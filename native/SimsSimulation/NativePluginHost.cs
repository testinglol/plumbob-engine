using System.Reflection;
using System.Runtime.Loader;
using System.Security.Cryptography;
using System.Text.Json;
using FSO.SimAntics;
using FSO.SimAntics.Model;
using FSO.SimAntics.NetPlay.Model.Commands;
using SimsNative.Plugins;

/// <summary>
/// Loads code-bearing gameplay packs described by the content mount's <c>.native-pack-stack.json</c>.
/// A plugin runs only when the data root's trust store names its pack ID, version and assembly SHA-256,
/// and only when the mounted copy still has that hash. Each plugin gets its own collectible load context
/// that shares the contract assembly with the host. A plugin that throws is disabled for the session.
/// </summary>
internal sealed class NativePluginHost : IDisposable
{
    internal sealed record PluginDescriptor(string PackId, string Version, string Assembly, string Sha256, string EntryType, int ApiVersion, int StateVersion);
    internal sealed record PanelDescriptor(string PackId, string Id, string Path, string Sha256);
    internal sealed record PackDescriptor(string Id, string Version, string[] MigratesFrom);
    internal sealed record PluginSaveRecord(string PackVersion, int StateVersion, string? Data, Dictionary<string, string> Values);
    internal sealed record PluginStatus(string PackId, string Version, string State, string? Reason);
    private sealed record TrustEntry(string PackId, string Version, string Sha256);
    private sealed record TrustFile(int SchemaVersion, TrustEntry[] Plugins);

    private sealed class LoadedPlugin(PluginDescriptor descriptor, ISimsPlugin instance, PluginContext context, PluginLoadContext loadContext)
    {
        public PluginDescriptor Descriptor { get; } = descriptor;
        public ISimsPlugin Instance { get; } = instance;
        public PluginContext Context { get; } = context;
        public PluginLoadContext LoadContext { get; } = loadContext;
        public bool Failed { get; set; }
    }

    private const int MaxValues = 256;
    private const int MaxKeyLength = 64;
    private const int MaxValueLength = 4096;
    private const int MaxStateBytes = 1 << 20;
    private static readonly JsonSerializerOptions Json = new() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
    private readonly List<LoadedPlugin> loaded = [];
    private readonly List<PluginStatus> statuses = [];
    private readonly Action<object> write;
    private readonly Func<VM> currentVM;
    private readonly Func<short> currentHouse;
    private readonly Func<NativePluginHost, IPluginSimulation> simulation;
    private readonly Dictionary<(string Pack, string Panel), Dictionary<string, string>> panelValues = [];
    private readonly HashSet<(string Pack, string Panel)> declaredPanels = [];
    private bool panelValuesChanged;

    public IReadOnlyList<PackDescriptor> Packs { get; }
    public IReadOnlyList<PanelDescriptor> Panels { get; }
    public IReadOnlyList<PluginStatus> Statuses => statuses;

    private NativePluginHost(Action<object> write, Func<VM> currentVM, Func<short> currentHouse,
        Func<NativePluginHost, IPluginSimulation>? simulation, PackDescriptor[] packs, PanelDescriptor[] panels)
    {
        this.write = write;
        this.currentVM = currentVM;
        this.currentHouse = currentHouse;
        this.simulation = simulation ?? (host => new PluginSimulation(host));
        Packs = packs;
        Panels = panels;
        foreach (var panel in panels) declaredPanels.Add((panel.PackId, panel.Id));
    }

    public static string TrustStorePath(string dataRoot) => System.IO.Path.Combine(dataRoot, "Settings", "plugin-trust.json");

    /// <summary>
    /// Reads the mount metadata and loads every trusted, hash-verified plugin. <paramref name="simulation"/> replaces the
    /// VM-backed simulation view; only the game-free plugin check uses it.
    /// </summary>
    public static NativePluginHost Create(string mount, string dataRoot, Action<object> write, Func<VM> currentVM, Func<short> currentHouse,
        Func<NativePluginHost, IPluginSimulation>? simulation = null)
    {
        var metadataPath = System.IO.Path.Combine(mount, ".native-pack-stack.json");
        PluginDescriptor[] plugins = [];
        PanelDescriptor[] panels = [];
        PackDescriptor[] packs = [];
        if (File.Exists(metadataPath))
        {
            using var document = JsonDocument.Parse(File.ReadAllText(metadataPath));
            var root = document.RootElement;
            if (root.TryGetProperty("plugins", out var pluginElement))
                plugins = pluginElement.Deserialize<PluginDescriptor[]>(Json) ?? [];
            if (root.TryGetProperty("panels", out var panelElement))
                panels = panelElement.Deserialize<PanelDescriptor[]>(Json) ?? [];
            if (root.TryGetProperty("packDetails", out var packElement))
                packs = packElement.Deserialize<PackDescriptor[]>(Json) ?? [];
            else if (root.TryGetProperty("packs", out var legacyPacks))
                packs = legacyPacks.EnumerateArray().Select(value => value.GetString() ?? "").Select(ParsePackLabel).ToArray();
        }
        var host = new NativePluginHost(write, currentVM, currentHouse, simulation, packs, panels);
        var trusted = ReadTrust(TrustStorePath(dataRoot));
        foreach (var plugin in plugins) host.TryLoad(mount, plugin, trusted);
        return host;
    }

    private static PackDescriptor ParsePackLabel(string label)
    {
        var separator = label.LastIndexOf('@');
        return separator <= 0 ? new PackDescriptor(label, "", []) : new PackDescriptor(label[..separator], label[(separator + 1)..], []);
    }

    private static HashSet<(string, string, string)> ReadTrust(string path)
    {
        if (!File.Exists(path)) return [];
        try
        {
            var file = JsonSerializer.Deserialize<TrustFile>(File.ReadAllText(path), Json);
            if (file == null || file.SchemaVersion != 1) return [];
            return file.Plugins.Select(entry => (entry.PackId, entry.Version, entry.Sha256.ToLowerInvariant())).ToHashSet();
        }
        catch (JsonException) { return []; }
    }

    private void TryLoad(string mount, PluginDescriptor descriptor, HashSet<(string, string, string)> trusted)
    {
        void Block(string state, string reason)
        {
            statuses.Add(new PluginStatus(descriptor.PackId, descriptor.Version, state, reason));
            write(new { type = "plugin", packId = descriptor.PackId, version = descriptor.Version, state, reason });
        }

        if (!PluginApi.SupportedVersions.Contains(descriptor.ApiVersion))
        {
            Block("rejected", $"Plugin API version {descriptor.ApiVersion} is not supported");
            return;
        }
        if (descriptor.StateVersion < 1)
        {
            Block("rejected", "Plugin state version must be at least 1");
            return;
        }
        var pluginRoot = System.IO.Path.GetFullPath(System.IO.Path.Combine(mount, ".native-plugins")) + System.IO.Path.DirectorySeparatorChar;
        var assemblyPath = System.IO.Path.GetFullPath(System.IO.Path.Combine(mount, descriptor.Assembly));
        if (!assemblyPath.StartsWith(pluginRoot, StringComparison.Ordinal) || !File.Exists(assemblyPath))
        {
            Block("rejected", "Plugin assembly is missing from the content mount");
            return;
        }
        var actualHash = Digest(System.IO.Path.GetDirectoryName(assemblyPath)!);
        if (actualHash != descriptor.Sha256.ToLowerInvariant())
        {
            Block("rejected", "Plugin files changed after the content mount was validated");
            return;
        }
        if (!trusted.Contains((descriptor.PackId, descriptor.Version, actualHash)))
        {
            Block("untrusted", "This plugin has not been trusted on this Mac");
            return;
        }

        var loadContext = new PluginLoadContext(assemblyPath);
        try
        {
            var assembly = loadContext.LoadFromAssemblyPath(assemblyPath);
            var type = assembly.GetType(descriptor.EntryType, throwOnError: false)
                ?? throw new InvalidDataException($"Entry type {descriptor.EntryType} was not found");
            if (!typeof(ISimsPlugin).IsAssignableFrom(type) || type.IsAbstract || type.GetConstructor(Type.EmptyTypes) == null)
                throw new InvalidDataException($"Entry type {descriptor.EntryType} must be a concrete ISimsPlugin with a public parameterless constructor");
            var instance = (ISimsPlugin)Activator.CreateInstance(type)!;
            var context = new PluginContext(this, descriptor);
            var plugin = new LoadedPlugin(descriptor, instance, context, loadContext);
            instance.Initialize(context);
            loaded.Add(plugin);
            if (descriptor.ApiVersion >= 2 && ImplementsScoreAutonomy(instance)) scorers = [.. scorers, plugin];
            statuses.Add(new PluginStatus(descriptor.PackId, descriptor.Version, "loaded", null));
            write(new { type = "plugin", packId = descriptor.PackId, version = descriptor.Version, state = "loaded" });
        }
        catch (Exception error) when (error is not OutOfMemoryException)
        {
            loadContext.Unload();
            Block("failed", Unwrap(error).Message);
        }
    }

    /// <summary>Matches Swift's <c>pluginDigest</c>: SHA-256 over "name:sha256\n" lines for each .dll/.json file, by lowercase name.</summary>
    internal static string Digest(string folder)
    {
        var lines = new System.Text.StringBuilder();
        foreach (var file in Directory.EnumerateFiles(folder)
            .Where(path => path.EndsWith(".dll", StringComparison.OrdinalIgnoreCase) || path.EndsWith(".json", StringComparison.OrdinalIgnoreCase))
            .Where(path => !new FileInfo(path).Attributes.HasFlag(FileAttributes.ReparsePoint))
            .Select(path => (Path: path, Name: System.IO.Path.GetFileName(path).ToLowerInvariant()))
            .OrderBy(entry => entry.Name, StringComparer.Ordinal))
            lines.Append(file.Name).Append(':').Append(Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(file.Path))).ToLowerInvariant()).Append('\n');
        return Convert.ToHexString(SHA256.HashData(System.Text.Encoding.UTF8.GetBytes(lines.ToString()))).ToLowerInvariant();
    }

    private static Exception Unwrap(Exception error) => error is TargetInvocationException { InnerException: { } inner } ? inner : error;

    private void Guard(LoadedPlugin plugin, string phase, Action action)
    {
        if (plugin.Failed) return;
        try { action(); }
        catch (Exception error) when (error is not OutOfMemoryException)
        {
            plugin.Failed = true;
            var reason = $"{phase}: {Unwrap(error).Message}";
            var index = statuses.FindIndex(status => status.PackId == plugin.Descriptor.PackId);
            var status = new PluginStatus(plugin.Descriptor.PackId, plugin.Descriptor.Version, "failed", reason);
            if (index >= 0) statuses[index] = status; else statuses.Add(status);
            write(new { type = "plugin", packId = plugin.Descriptor.PackId, version = plugin.Descriptor.Version, state = "failed", reason });
        }
    }

    private LoadedPlugin[] scorers = [];

    /// <summary>The VM's autonomy hook while a loaded version 2 plugin implements <see cref="ISimsPlugin.ScoreAutonomy"/>, else null.</summary>
    public Func<VMAvatar, VMPieMenuInteraction, float, float>? AutonomyScore =>
        scorers.Any(plugin => !plugin.Failed) ? ScoreAutonomy : null;

    private static bool ImplementsScoreAutonomy(ISimsPlugin instance)
    {
        var map = instance.GetType().GetInterfaceMap(typeof(ISimsPlugin));
        var index = Array.FindIndex(map.InterfaceMethods, method => method.Name == nameof(ISimsPlugin.ScoreAutonomy));
        return index >= 0 && map.TargetMethods[index].DeclaringType != typeof(ISimsPlugin);
    }

    private float ScoreAutonomy(VMAvatar sim, VMPieMenuInteraction candidate, float score)
    {
        var family = sim.Thread.Context.VM.TS1State.CurrentFamily;
        var choice = new PluginAutonomyChoice(sim.ObjectID, family != null && sim.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID,
            candidate.Callee.ObjectID, candidate.Callee.Object.OBJ.GUID, candidate.ID, candidate.Name ?? "");
        foreach (var plugin in scorers)
            Guard(plugin, "ScoreAutonomy", () =>
            {
                var next = plugin.Instance.ScoreAutonomy(choice, score);
                if (!float.IsFinite(next)) throw new InvalidDataException("ScoreAutonomy returned a score that is not a finite number");
                score = Math.Clamp(next, 0f, 1e6f);
            });
        return score;
    }

    public void Tick(long update)
    {
        foreach (var plugin in loaded) Guard(plugin, "OnTick", () => plugin.Instance.OnTick(update));
        FlushPanels();
    }

    public void FlushPanels()
    {
        if (!panelValuesChanged) return;
        panelValuesChanged = false;
        write(new { type = "pluginPanels", panels = PanelState() });
    }

    public object[] PanelState() => panelValues
        .OrderBy(pair => pair.Key.Pack, StringComparer.Ordinal).ThenBy(pair => pair.Key.Panel, StringComparer.Ordinal)
        .Select(pair => (object)new { packId = pair.Key.Pack, panelId = pair.Key.Panel, values = pair.Value })
        .ToArray();

    public object PanelAction(string packId, string panelId, string action)
    {
        if (!declaredPanels.Contains((packId, panelId))) throw new ArgumentException("Unknown plugin panel");
        if (string.IsNullOrEmpty(action) || action.Length > MaxKeyLength) throw new ArgumentException("Invalid plugin panel action");
        var plugin = loaded.FirstOrDefault(candidate => candidate.Descriptor.PackId == packId && !candidate.Failed)
            ?? throw new InvalidOperationException("The panel's plugin is not running");
        Guard(plugin, "OnPanelAction", () => plugin.Instance.OnPanelAction(panelId, action));
        FlushPanels();
        return new { accepted = !plugin.Failed };
    }

    /// <summary>Collects namespaced state from every running plugin for a native save.</summary>
    public Dictionary<string, PluginSaveRecord> Save()
    {
        var records = new Dictionary<string, PluginSaveRecord>(StringComparer.Ordinal);
        foreach (var plugin in loaded)
        {
            byte[]? data = null;
            Guard(plugin, "SaveState", () => data = plugin.Instance.SaveState());
            if (plugin.Failed) throw new InvalidOperationException($"Plugin {plugin.Descriptor.PackId} failed and its state cannot be saved");
            if (data is { Length: > MaxStateBytes }) throw new InvalidOperationException($"Plugin {plugin.Descriptor.PackId} returned more than 1 MiB of state");
            records[plugin.Descriptor.PackId] = new PluginSaveRecord(plugin.Descriptor.Version, plugin.Descriptor.StateVersion,
                data == null ? null : Convert.ToBase64String(data), new Dictionary<string, string>(plugin.Context.ValueStore, StringComparer.Ordinal));
        }
        return records;
    }

    /// <summary>
    /// Rejects saved plugin state that the running plugins cannot accept. Runs before the VM is replaced,
    /// so a rejected save leaves the session untouched.
    /// </summary>
    public void ValidateSaved(IReadOnlyDictionary<string, PluginSaveRecord>? records)
    {
        foreach (var (packId, record) in records ?? new Dictionary<string, PluginSaveRecord>())
        {
            var plugin = loaded.FirstOrDefault(candidate => candidate.Descriptor.PackId == packId);
            if (plugin == null)
            {
                var status = statuses.FirstOrDefault(candidate => candidate.PackId == packId);
                throw new InvalidDataException(status == null
                    ? $"This save contains state for the missing plugin {packId}"
                    : $"This save requires plugin {packId}, which is {status.State}: {status.Reason}");
            }
            if (plugin.Failed) throw new InvalidDataException($"This save requires plugin {packId}, which failed in this session");
            if (record.StateVersion > plugin.Descriptor.StateVersion)
                throw new InvalidDataException($"This save was written by a newer state version ({record.StateVersion}) of plugin {packId}; restore a backup or update the pack");
            if (record.StateVersion < 1) throw new InvalidDataException($"Invalid saved state version for plugin {packId}");
            if (record.Values.Count > MaxValues || record.Values.Any(pair => pair.Key.Length is 0 or > MaxKeyLength || pair.Value.Length > MaxValueLength))
                throw new InvalidDataException($"Saved values for plugin {packId} exceed the namespace limits");
            if (record.Data != null && (record.Data.Length > MaxStateBytes * 4 / 3 + 4 || !IsBase64(record.Data)))
                throw new InvalidDataException($"Saved state for plugin {packId} is not valid");
        }
    }

    private static bool IsBase64(string value)
    {
        var buffer = new byte[value.Length];
        return Convert.TryFromBase64String(value, buffer, out _);
    }

    /// <summary>Restores validated state. Plugins with no saved record start fresh; a plugin that throws is disabled.</summary>
    public void Restore(IReadOnlyDictionary<string, PluginSaveRecord>? records)
    {
        foreach (var plugin in loaded)
        {
            plugin.Context.ValueStore.Clear();
            if (records == null || !records.TryGetValue(plugin.Descriptor.PackId, out var record)) continue;
            foreach (var (key, value) in record.Values) plugin.Context.ValueStore[key] = value;
            var data = record.Data == null ? [] : Convert.FromBase64String(record.Data);
            Guard(plugin, "LoadState", () => plugin.Instance.LoadState(record.StateVersion, data));
        }
        FlushPanels();
    }

    public void Dispose()
    {
        foreach (var plugin in loaded) plugin.LoadContext.Unload();
        loaded.Clear();
    }

    private sealed class PluginLoadContext(string assemblyPath) : AssemblyLoadContext("plugin:" + System.IO.Path.GetFileName(assemblyPath), isCollectible: true)
    {
        private readonly AssemblyDependencyResolver resolver = new(assemblyPath);

        protected override Assembly? Load(AssemblyName name)
        {
            // The contract assembly must be the host's copy so ISimsPlugin has one identity.
            if (name.Name == typeof(ISimsPlugin).Assembly.GetName().Name) return null;
            var path = resolver.ResolveAssemblyToPath(name);
            return path == null ? null : LoadFromAssemblyPath(path);
        }
    }

    private sealed class PluginContext(NativePluginHost host, PluginDescriptor descriptor) : IPluginContext
    {
        public readonly BoundedValues ValueStore = new();
        public int ApiVersion => descriptor.ApiVersion;
        public string PackId => descriptor.PackId;
        public string PackVersion => descriptor.Version;
        public int StateVersion => descriptor.StateVersion;
        public IPluginSimulation Simulation { get; } = descriptor.ApiVersion >= 2 ? host.simulation(host) : new VersionOneSimulation(host.simulation(host));
        public IDictionary<string, string> Values => ValueStore;

        public void SetPanelValue(string panelId, string binding, string value)
        {
            if (!host.declaredPanels.Contains((descriptor.PackId, panelId))) throw new ArgumentException($"Panel {panelId} is not declared by pack {descriptor.PackId}");
            if (string.IsNullOrEmpty(binding) || binding.Length > MaxKeyLength) throw new ArgumentException("Invalid panel binding");
            if (value.Length > MaxValueLength) throw new ArgumentException("Panel values are limited to 4096 characters");
            var key = (descriptor.PackId, panelId);
            if (!host.panelValues.TryGetValue(key, out var values)) host.panelValues[key] = values = new Dictionary<string, string>(StringComparer.Ordinal);
            if (values.TryGetValue(binding, out var current) && current == value) return;
            if (!values.ContainsKey(binding) && values.Count >= MaxValues) throw new ArgumentException("Too many panel bindings");
            values[binding] = value;
            host.panelValuesChanged = true;
        }

        public void Log(string message) => Console.Error.WriteLine($"[plugin {descriptor.PackId}] {(message.Length > 1024 ? message[..1024] : message)}");
    }

    internal sealed class BoundedValues : Dictionary<string, string>, IDictionary<string, string>
    {
        public BoundedValues() : base(StringComparer.Ordinal) { }

        private void Check(string key, string value)
        {
            if (key.Length is 0 or > MaxKeyLength) throw new ArgumentException("Plugin value keys must be 1 to 64 characters");
            if (value.Length > MaxValueLength) throw new ArgumentException("Plugin values are limited to 4096 characters");
            if (!ContainsKey(key) && Count >= MaxValues) throw new ArgumentException("Plugins can store at most 256 values");
        }

        string IDictionary<string, string>.this[string key]
        {
            get => this[key];
            set { Check(key, value); this[key] = value; }
        }

        void IDictionary<string, string>.Add(string key, string value) { Check(key, value); Add(key, value); }
        void ICollection<KeyValuePair<string, string>>.Add(KeyValuePair<string, string> item) { Check(item.Key, item.Value); Add(item.Key, item.Value); }
    }

    /// <summary>What a plugin built for API version 1 sees: the version 2 members keep their throwing defaults.</summary>
    private sealed class VersionOneSimulation(IPluginSimulation inner) : IPluginSimulation
    {
        public short House => inner.House;
        public int Hours => inner.Hours;
        public int Minutes => inner.Minutes;
        public bool Paused => inner.Paused;
        public int HouseholdFunds => inner.HouseholdFunds;
        public IReadOnlyList<PluginSim> HouseholdSims => inner.HouseholdSims;
        public short GetMotive(short objectId, int motive) => inner.GetMotive(objectId, motive);
        public bool TryCharge(int amount) => inner.TryCharge(amount);
        public bool TryPay(int amount) => inner.TryPay(amount);
    }

    private static readonly HashSet<int> ChangeableMotives = [(int)VMMotive.Energy, (int)VMMotive.Comfort, (int)VMMotive.Hunger,
        (int)VMMotive.Hygiene, (int)VMMotive.Bladder, (int)VMMotive.Social, (int)VMMotive.Fun];

    private sealed class PluginSimulation(NativePluginHost host) : IPluginSimulation
    {
        private VM VM => host.currentVM();
        public short House => host.currentHouse();
        public int Hours => VM.Context.Clock.Hours;
        public int Minutes => VM.Context.Clock.Minutes;
        public bool Paused => VM.SpeedMultiplier <= 0 || VM.GlobalBlockingDialog != null;
        public int HouseholdFunds => VM.TS1State.CurrentFamily?.Budget ?? 0;

        private IEnumerable<VMAvatar> Household()
        {
            var family = VM.TS1State.CurrentFamily;
            if (family == null) return [];
            return VM.Entities.OfType<VMAvatar>().Where(avatar => !avatar.Dead &&
                avatar.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID);
        }

        public IReadOnlyList<PluginSim> HouseholdSims => Household()
            .Select(avatar => new PluginSim(avatar.ObjectID, avatar.GetPersonData(VMPersonDataVariable.NeighborId), avatar.Name,
                avatar.GetPersonData(VMPersonDataVariable.PersonsAge) < 18))
            .ToArray();

        public short GetMotive(short objectId, int motive)
        {
            if (motive is < 0 or > 15) throw new ArgumentOutOfRangeException(nameof(motive));
            var avatar = Household().FirstOrDefault(candidate => candidate.ObjectID == objectId)
                ?? throw new ArgumentException("Motives are readable only for household Sims on this lot");
            return avatar.GetMotiveData((VMMotive)motive);
        }

        private VMAvatar HouseholdSim(short objectId) => Household().FirstOrDefault(candidate => candidate.ObjectID == objectId)
            ?? throw new ArgumentException("Only household Sims on this lot can be directed");

        private VMEntity Entity(short objectId) => VM.GetObjectById(objectId) ?? throw new ArgumentException($"No object {objectId} on this lot");

        public IReadOnlyList<PluginObject> Objects => VM.Entities
            .Select(entity => new PluginObject(entity.ObjectID, entity.Object.OBJ.GUID, entity.ToString() ?? "", entity.Position.TileX, entity.Position.TileY,
                entity.Position.Level, entity.MultitileGroup?.BaseObject?.ObjectID ?? entity.ObjectID))
            .ToArray();

        public IReadOnlyList<PluginInteraction> GetInteractions(short simId, short objectId) => Entity(objectId)
            .GetPieMenu(VM, HouseholdSim(simId), false, true)
            .Select(entry => new PluginInteraction(entry.ID, entry.Name ?? "", entry.Param0, entry.Global))
            .ToArray();

        public bool TryQueueInteraction(short simId, short objectId, int interactionId, short param0 = 0, bool global = false)
        {
            if (VM.GlobalBlockingDialog != null) return false;
            var sim = HouseholdSim(simId);
            var callee = Entity(objectId);
            if (!callee.GetPieMenu(VM, sim, false, true).Any(entry => entry.ID == interactionId && entry.Param0 == param0 && entry.Global == global)) return false;
            VM.SendCommand(new VMNetInteractionCmd { CallerID = sim.ObjectID, CalleeID = callee.ObjectID, Interaction = (ushort)interactionId, Param0 = param0, Global = global });
            return true;
        }

        public IReadOnlyList<string> GetQueuedActions(short simId) => HouseholdSim(simId).Thread.Queue.Select(action => action.Name ?? "").ToArray();

        public short ChangeMotive(short simId, int motive, int delta)
        {
            if (!ChangeableMotives.Contains(motive)) throw new ArgumentOutOfRangeException(nameof(motive), "Only the needs can be changed");
            if (delta is < -100 or > 100) throw new ArgumentOutOfRangeException(nameof(delta));
            var sim = HouseholdSim(simId);
            var value = (short)Math.Clamp(sim.GetMotiveData((VMMotive)motive) + delta, -100, 100);
            sim.SetMotiveData((VMMotive)motive, value);
            return value;
        }

        public bool TryCharge(int amount)
        {
            var family = VM.TS1State.CurrentFamily;
            if (family == null || amount <= 0 || amount > family.Budget) return false;
            family.Budget -= amount;
            return true;
        }

        public bool TryPay(int amount)
        {
            var family = VM.TS1State.CurrentFamily;
            if (family == null || amount <= 0 || amount > 100_000 || family.Budget > int.MaxValue - amount) return false;
            family.Budget += amount;
            return true;
        }
    }
}
