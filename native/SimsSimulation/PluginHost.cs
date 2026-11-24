using System.Reflection;
using System.Runtime.Loader;
using System.Security.Cryptography;
using System.Text.Json;
using SimsNative.Plugins;

namespace SimsSimulation;

internal sealed class PluginHost : IDisposable
{
    internal sealed record PluginDescriptor(string PackId, string Version, string Assembly, string Sha256, string EntryType, int ApiVersion, int StateVersion);
    internal sealed record PanelDescriptor(string PackId, string Id, string Path, string Sha256 = "");
    internal sealed record ObjectMigration(uint From, uint To);
    internal sealed record PackDescriptor(string Id, string Version, string[] MigratesFrom, ObjectMigration[]? Objects = null);
    internal sealed record PluginSaveRecord(string PackVersion, int StateVersion, string? Data, Dictionary<string, string> Values, Dictionary<string, string>? NeighborhoodValues = null);
    internal sealed record PluginStatus(string PackId, string Version, string State, string? Reason);
    private sealed record TrustEntry(string PackId, string Version, string Sha256);
    private sealed record TrustFile(int SchemaVersion, TrustEntry[] Plugins);
    internal sealed record BuyCatalogViewEntry(string PackId, PluginBuyCatalogView View);
    private sealed record NeighborhoodRecord(string PackVersion, int StateVersion, Dictionary<string, string> Values);

    public interface IPluginWorld
    {
        short GetObjectAttribute(short objectId, int index);
        void SetObjectAttribute(short objectId, int index, short value);
        void SetObjectGraphic(short objectId, short graphic);
        short? TryPlaceOwnedObject(string packId, uint guid, int tileX, int tileY, int level, short direction, short? clearForSimId) => null;
        bool TryRemoveOwnedObject(string packId, short objectId) => false;
        string? ResolveSimSuit(short simId, char categoryPrefix, int bodyStringIndex) => null;
        void SetSimAppearanceOverride(short simId, string? bodySuitSpec, bool animateSpin = true) { }
    }

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
    private readonly Action<string, short, string, bool>? playSoundResource;
    private readonly Action<short, string>? stopSoundResource;
    private readonly Func<short> currentHouse;
    private readonly Func<PluginHost, IPluginSimulation> simulation;
    private IPluginWorld? world;
    private readonly Dictionary<(string Pack, string Panel), Dictionary<string, string>> panelValues = [];
    private readonly HashSet<(string Pack, string Panel)> declaredPanels = [];
    private bool panelValuesChanged;
    private readonly Dictionary<string, byte[]> clientStates = new(StringComparer.Ordinal);
    private readonly Dictionary<string, float> sharedBlackboard = new(StringComparer.Ordinal);
    private bool clientStatesChanged;
    private string mountRoot = "";
    private DirectPackOverlay? directOverlay;
    private string? neighborhoodRoot;
    private readonly Dictionary<string, string> resourceOwners = new(StringComparer.OrdinalIgnoreCase);
    private readonly Dictionary<uint, string> objectOwners = [];
    private readonly Dictionary<string, NeighborhoodRecord> neighborhoodRecords = [];
    private readonly Dictionary<string, Dictionary<string, string>> sealedResources = [];
    private readonly Dictionary<string, string> approvedResources = [];
    private LoadedPlugin[] scorers = [];
    private LoadedPlugin[] autonomyDirectors = [];
    private LoadedPlugin[] interactionFilters = [];
    private LoadedPlugin[] menuPlugins = [];
    private LoadedPlugin[] groundMenuPlugins = [];
    private LoadedPlugin[] globalCallPlugins = [];
    private LoadedPlugin[] spriteModifiers = [];
    private string? choosingPack;
    private string? shownPanel;
    private short? shownPanelAnchor;
    private const int MaxMenuEntries = 8;

    public static string TrustStorePath(string dataRoot) => Path.Combine(dataRoot, "Settings", "plugin-trust.json");

    public static PluginHost Create(string mount, string dataRoot, Action<object> write, Func<short> currentHouse,
        Func<PluginHost, IPluginSimulation>? simulation = null, string? userData = null,
        IPluginWorld? world = null, Action<string, short, string, bool>? playSoundResource = null,
        Action<short, string>? stopSoundResource = null, DirectPackOverlay? packOverlay = null)
    {
        var metadataPath = Path.Combine(mount, ".pack-stack.json");
        var metadataJson = packOverlay?.PackStackJson ?? (File.Exists(metadataPath) ? File.ReadAllText(metadataPath) : null);
        PluginDescriptor[] plugins = [];
        PanelDescriptor[] panels = [];
        PackDescriptor[] packs = [];
        if (metadataJson != null)
        {
            using var document = JsonDocument.Parse(metadataJson);
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
        var host = new PluginHost(write, currentHouse, playSoundResource, stopSoundResource, simulation, packs, panels);
        host.mountRoot = Path.GetFullPath(mount);
        host.directOverlay = packOverlay;
        host.neighborhoodRoot = userData;
        host.world = world;
        if (metadataJson != null)
        {
            using var document = JsonDocument.Parse(metadataJson);
            if (document.RootElement.TryGetProperty("resources", out var resources))
                foreach (var resource in resources.EnumerateArray())
                    host.resourceOwners[resource.GetProperty("path").GetString()!] = resource.GetProperty("owner").GetString()!;
            if (document.RootElement.TryGetProperty("objects", out var objects))
                foreach (var obj in objects.EnumerateArray())
                    if (obj.TryGetProperty("guid", out var guidEl) && guidEl.TryGetUInt32(out var guidVal) &&
                        obj.TryGetProperty("owner", out var ownerEl) && ownerEl.GetString() is { } ownerName)
                        host.objectOwners[guidVal] = ownerName;
        }
        var trusted = ReadTrust(TrustStorePath(dataRoot));
        foreach (var plugin in plugins) host.TryLoad(mount, plugin, trusted);
        return host;
    }

    private PluginHost(Action<object> write, Func<short> currentHouse,
        Action<string, short, string, bool>? playSoundResource, Action<short, string>? stopSoundResource,
        Func<PluginHost, IPluginSimulation>? simulation, PackDescriptor[] packs, PanelDescriptor[] panels)
    {
        this.write = write;
        this.currentHouse = currentHouse;
        this.playSoundResource = playSoundResource;
        this.stopSoundResource = stopSoundResource;
        this.simulation = simulation ?? (_ => throw new InvalidOperationException("No plugin simulation is available"));
        MigratedPacks = packs;
        Panels = panels;
        foreach (var panel in panels) declaredPanels.Add((panel.PackId, panel.Id));
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

    internal static string Digest(string folder) => PluginFolderDigest(folder);

    private static string PluginFolderDigest(string folder)
    {
        var files = new DirectoryInfo(folder).GetFiles()
            .Where(file => (file.Attributes & FileAttributes.ReparsePoint) == 0 &&
                (file.Extension.Equals(".dll", StringComparison.OrdinalIgnoreCase) ||
                 file.Extension.Equals(".json", StringComparison.OrdinalIgnoreCase)))
            .OrderBy(file => file.Name.ToLowerInvariant(), StringComparer.Ordinal);
        var lines = new System.Text.StringBuilder();
        foreach (var file in files)
        {
            var fileHash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(file.FullName))).ToLowerInvariant();
            lines.Append(file.Name.ToLowerInvariant()).Append(':').Append(fileHash).Append('\n');
        }
        return Convert.ToHexString(SHA256.HashData(System.Text.Encoding.UTF8.GetBytes(lines.ToString()))).ToLowerInvariant();
    }

    private static Exception Unwrap(Exception error) => error is TargetInvocationException { InnerException: { } inner } ? inner : error;

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
        if (descriptor.StateVersion < 1 ||
            string.IsNullOrWhiteSpace(descriptor.PackId) || string.IsNullOrWhiteSpace(descriptor.Version) ||
            string.IsNullOrWhiteSpace(descriptor.Assembly) || string.IsNullOrWhiteSpace(descriptor.Sha256))
        {
            Block("rejected", "Plugin state version must be at least 1");
            return;
        }

        string assemblyPath;
        if (directOverlay != null)
        {
            if (!directOverlay.PluginFolders.TryGetValue(descriptor.PackId, out var pluginFolder) || string.IsNullOrWhiteSpace(pluginFolder))
            {
                Block("rejected", "Plugin assembly is missing from the pack overlay");
                return;
            }
            var pluginFolderRoot = Path.GetFullPath(pluginFolder).TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar) + Path.DirectorySeparatorChar;
            var fileName = Path.GetFileName(descriptor.Assembly);
            assemblyPath = Path.GetFullPath(Path.Combine(pluginFolderRoot, fileName));
            if (!assemblyPath.StartsWith(pluginFolderRoot, OperatingSystem.IsWindows() ? StringComparison.OrdinalIgnoreCase : StringComparison.Ordinal) || !File.Exists(assemblyPath))
            {
                Block("rejected", "Plugin assembly is missing from the pack overlay");
                return;
            }
        }
        else
        {
            var pluginRoot = Path.GetFullPath(Path.Combine(mount, ".plugins")) + Path.DirectorySeparatorChar;
            assemblyPath = Path.GetFullPath(Path.Combine(mount, descriptor.Assembly));
            if (!assemblyPath.StartsWith(pluginRoot, StringComparison.Ordinal) || !File.Exists(assemblyPath))
            {
                Block("rejected", "Plugin assembly is missing from the content mount");
                return;
            }
        }

        var folder = Path.GetDirectoryName(assemblyPath)!;
        var actualHash = PluginFolderDigest(folder);
        var assemblyHash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(assemblyPath))).ToLowerInvariant();
        if (!string.Equals(actualHash, descriptor.Sha256, StringComparison.OrdinalIgnoreCase) &&
            !string.Equals(assemblyHash, descriptor.Sha256, StringComparison.OrdinalIgnoreCase))
        {
            Block("rejected", "Plugin files changed after the content mount was validated");
            return;
        }

        if (!trusted.Contains((descriptor.PackId, descriptor.Version, descriptor.Sha256.ToLowerInvariant())))
        {
            Block("untrusted", "This plugin has not been trusted on this Mac");
            return;
        }

        if (string.IsNullOrWhiteSpace(descriptor.EntryType))
        {
            statuses.Add(new PluginStatus(descriptor.PackId, descriptor.Version, "loaded", null));
            write(new { type = "plugin", packId = descriptor.PackId, version = descriptor.Version, state = "loaded" });
            return;
        }

        PluginLoadContext? loadContext = null;
        try
        {
            loadContext = new PluginLoadContext(assemblyPath);
            var assembly = loadContext.LoadFromAssemblyPath(assemblyPath);
            var type = assembly.GetType(descriptor.EntryType, throwOnError: false)
                ?? throw new InvalidDataException($"Entry type {descriptor.EntryType} was not found");
            if (!typeof(ISimsPlugin).IsAssignableFrom(type) || type.IsAbstract || type.GetConstructor(Type.EmptyTypes) == null)
                throw new InvalidDataException($"Entry type {descriptor.EntryType} must be a concrete ISimsPlugin with a public parameterless constructor");
            var instance = (ISimsPlugin)Activator.CreateInstance(type)!;
            var context = new PluginContext(this, descriptor);
            var loadedPlugin = new LoadedPlugin(descriptor, instance, context, loadContext);
            instance.Initialize(context);
            loaded.Add(loadedPlugin);
            statuses.Add(new PluginStatus(descriptor.PackId, descriptor.Version, "loaded", null));
            write(new { type = "plugin", packId = descriptor.PackId, version = descriptor.Version, state = "loaded" });
            RefreshHooks();
        }
        catch (Exception error) when (error is not OutOfMemoryException)
        {
            loadContext?.Unload();
            Block("failed", Unwrap(error).Message);
        }
    }

    public Func<PluginAutonomyChoice, float, float>? AutonomyScore =>
        scorers.Any(plugin => !plugin.Failed) ? ScoreAutonomy : null;

    public float ScoreAutonomy(PluginAutonomyChoice choice, float score)
    {
        foreach (var plugin in scorers)
            Guard(plugin, "ScoreAutonomy", () =>
            {
                var next = plugin.Instance.ScoreAutonomy(choice, score);
                if (!float.IsFinite(next)) throw new InvalidDataException("ScoreAutonomy returned a score that is not a finite number");
                score = Math.Clamp(next, 0f, 1e6f);
            });
        return score;
    }

    public bool DirectsAutonomy(short simId, bool household)
    {
        var directs = false;
        foreach (var plugin in autonomyDirectors)
            Guard(plugin, "DirectsAutonomy", () =>
            {
                if (((IPluginAutonomyDirector)plugin.Instance).DirectsAutonomy(simId, household))
                    directs = true;
            });
        return directs;
    }

    public int? SelectAutonomyCandidate(PluginAutonomyContext context, IReadOnlyList<PluginAutonomyCandidate> candidates)
    {
        int? chosen = null;
        foreach (var plugin in autonomyDirectors)
        {
            Guard(plugin, "SelectAutonomyCandidate", () =>
            {
                var director = (IPluginAutonomyDirector)plugin.Instance;
                if (!director.DirectsAutonomy(context.SimId, context.Household))
                    return;
                var next = director.SelectAutonomyCandidate(context, candidates);
                if (next is { } idx)
                {
                    if (idx < -1 || idx >= candidates.Count)
                        throw new InvalidDataException($"SelectAutonomyCandidate returned out-of-range index {idx}");
                    chosen = idx;
                }
            });
            if (chosen is not null)
                break;
        }
        FlushPanels();
        return chosen;
    }

    public void NotifyPlayerCancelledAction(short simId, short targetObjectId, int interactionId)
    {
        foreach (var plugin in autonomyDirectors)
            Guard(plugin, "OnPlayerCancelledAction", () =>
                ((IPluginAutonomyDirector)plugin.Instance).OnPlayerCancelledAction(simId, targetObjectId, interactionId));
        FlushPanels();
    }

    private void RefreshHooks()
    {
        scorers = loaded.Where(plugin => !plugin.Failed && plugin.Descriptor.ApiVersion >= 2 && Implements(plugin.Instance, nameof(ISimsPlugin.ScoreAutonomy))).ToArray();
        autonomyDirectors = loaded.Where(plugin => !plugin.Failed && plugin.Descriptor.ApiVersion >= 6 && plugin.Instance is IPluginAutonomyDirector).ToArray();
        interactionFilters = loaded.Where(plugin => !plugin.Failed && plugin.Descriptor.ApiVersion >= 2 && Implements(plugin.Instance, nameof(ISimsPlugin.AllowInteraction))).ToArray();
        menuPlugins = loaded.Where(plugin => !plugin.Failed && plugin.Descriptor.ApiVersion >= 2 && Implements(plugin.Instance, nameof(ISimsPlugin.GetMenuEntries))).ToArray();
        groundMenuPlugins = loaded.Where(plugin => !plugin.Failed && plugin.Descriptor.ApiVersion >= 4 && Implements(plugin.Instance, nameof(ISimsPlugin.GetGroundMenuEntries))).ToArray();
        globalCallPlugins = loaded.Where(plugin => !plugin.Failed && Implements(plugin.Instance, nameof(ISimsPlugin.OnSimAnticsGlobalCall))).ToArray();
        spriteModifiers = loaded.Where(plugin => !plugin.Failed && plugin.Instance is IPluginObjectSpriteModifier).ToArray();
    }

    public IPluginObjectSpriteModifier? ActiveSpriteModifier =>
        spriteModifiers.Select(p => (IPluginObjectSpriteModifier)p.Instance).FirstOrDefault(m => m.SpriteVariant != 0);

    public int CurrentSpriteVariant
    {
        get
        {
            foreach (var plugin in spriteModifiers)
            {
                int variant = 0;
                Guard(plugin, "SpriteVariant", () => variant = ((IPluginObjectSpriteModifier)plugin.Instance).SpriteVariant);
                if (variant != 0)
                    return variant;
            }
            return 0;
        }
    }

    public void NotifyWorldLoaded()
    {
        foreach (var plugin in loaded)
            Guard(plugin, "OnWorldLoaded", () => plugin.Instance.OnWorldLoaded());
        FlushPanels();
        FlushClientStates();
    }

    private static bool Implements(ISimsPlugin instance, string member)
    {
        var map = instance.GetType().GetInterfaceMap(typeof(ISimsPlugin));
        var index = Array.FindIndex(map.InterfaceMethods, method => method.Name == member);
        return index >= 0 && map.TargetMethods[index].DeclaringType != typeof(ISimsPlugin);
    }

    private void Guard(LoadedPlugin plugin, string operation, Action action)
    {
        if (plugin.Failed) return;
        try { action(); }
        catch (Exception error) when (error is not OutOfMemoryException)
        {
            plugin.Failed = true;
            var reason = $"{operation}: {Unwrap(error).Message}";
            var index = statuses.FindIndex(status => status.PackId == plugin.Descriptor.PackId);
            var status = new PluginStatus(plugin.Descriptor.PackId, plugin.Descriptor.Version, "failed", reason);
            if (index >= 0) statuses[index] = status; else statuses.Add(status);
            write(new
            {
                type = "plugin",
                packId = plugin.Descriptor.PackId,
                version = plugin.Descriptor.Version,
                state = "failed",
                reason
            });
            RefreshHooks();
        }
    }

    public IReadOnlyList<PluginStatus> Statuses => statuses;
    public IReadOnlyList<PanelDescriptor> Panels { get; }
    public IReadOnlyList<PackDescriptor> MigratedPacks { get; }

    public void Tick(long update)
    {
        foreach (var plugin in loaded) Guard(plugin, "OnTick", () => plugin.Instance.OnTick(update));
        FlushPanels();
        FlushClientStates();
    }

    public void FlushPanels()
    {
        if (!panelValuesChanged) return;
        panelValuesChanged = false;
        write(new { type = "pluginPanels", panels = PanelState() });
    }

    public void FlushClientStates(bool force = false)
    {
        if (!force && !clientStatesChanged) return;
        clientStatesChanged = false;
        if (!force && clientStates.Count == 0 && sharedBlackboard.Count == 0) return;
        write(new
        {
            type = "pluginClientStates",
            states = ClientStatePayload(),
            blackboard = new Dictionary<string, float>(sharedBlackboard, StringComparer.Ordinal),
        });
    }

    public object ClientStateSnapshot() => new
    {
        states = ClientStatePayload(),
        blackboard = new Dictionary<string, float>(sharedBlackboard, StringComparer.Ordinal),
    };

    private object[] ClientStatePayload() => clientStates
        .OrderBy(static kv => kv.Key, StringComparer.Ordinal)
        .Select(static kv => (object)new { packId = kv.Key, data = Convert.ToBase64String(kv.Value) })
        .ToArray();

    public object[] PanelState() => panelValues
        .OrderBy(pair => pair.Key.Pack, StringComparer.Ordinal).ThenBy(pair => pair.Key.Panel, StringComparer.Ordinal)
        .Select(pair => (object)new { packId = pair.Key.Pack, panelId = pair.Key.Panel, values = pair.Value })
        .ToArray();

    public bool AllowInteraction(short simId, PluginObject target, PluginInteraction interaction)
    {
        var allowed = true;
        foreach (var plugin in interactionFilters)
            Guard(plugin, "AllowInteraction", () =>
            {
                if (!plugin.Instance.AllowInteraction(simId, target, interaction)) allowed = false;
            });
        return allowed;
    }

    public bool HasGlobalCallInterceptors => globalCallPlugins.Length > 0;

    public bool? InterceptGlobalCall(ushort subroutineId, PluginObject caller, short stackObjectId)
    {
        bool? decision = null;
        foreach (var plugin in globalCallPlugins)
        {
            Guard(plugin, "OnSimAnticsGlobalCall", () =>
            {
                var next = plugin.Instance.OnSimAnticsGlobalCall(subroutineId, caller, stackObjectId);
                if (next is not null) decision = next;
            });
            if (decision is not null) break;
        }
        return decision;
    }

    public sealed record MenuEntry(string PackId, string Entry, string Name);

    public IReadOnlyList<MenuEntry> MenuEntries(short simId, PluginObject target)
    {
        var entries = new List<MenuEntry>();
        foreach (var plugin in menuPlugins)
            Guard(plugin, "GetMenuEntries", () =>
            {
                var offered = (plugin.Instance.GetMenuEntries(simId, target) ?? []).Take(MaxMenuEntries + 1).ToArray();
                if (offered.Length > MaxMenuEntries) throw new InvalidDataException($"GetMenuEntries returned more than {MaxMenuEntries} entries");
                var ids = new HashSet<string>(StringComparer.Ordinal);
                foreach (var entry in offered)
                {
                    if (entry == null || !ValidMenuId(entry.Id) || !ids.Add(entry.Id)) throw new InvalidDataException("GetMenuEntries returned a missing, malformed or repeated entry ID");
                    if (!ValidMenuName(entry.Name)) throw new InvalidDataException($"Menu entry {entry.Id} has a malformed name");
                }
                entries.AddRange(offered.Select(entry => new MenuEntry(plugin.Descriptor.PackId, entry.Id, entry.Name)));
            });
        return entries;
    }

    public object ChooseMenuEntry(short simId, PluginObject target, string packId, string entryId)
    {
        var plugin = menuPlugins.FirstOrDefault(candidate => candidate.Descriptor.PackId == packId && !candidate.Failed)
            ?? throw new InvalidOperationException("The menu entry's plugin is not running");
        if (!MenuEntries(simId, target).Any(entry => entry.PackId == packId && entry.Entry == entryId))
            throw new ArgumentException("The plugin no longer offers that menu entry");
        (choosingPack, shownPanel, shownPanelAnchor) = (packId, null, null);
        try { Guard(plugin, "OnMenuEntry", () => plugin.Instance.OnMenuEntry(simId, target, entryId)); }
        finally { choosingPack = null; }
        FlushPanels();
        FlushClientStates();
        var panel = plugin.Failed ? null : shownPanel;
        var anchorId = panel == null ? null : shownPanelAnchor;
        if (panel != null) write(new { type = "pluginPanelShow", packId, panelId = panel, anchorId });
        return new { accepted = !plugin.Failed, panel, anchorId };
    }

    public IReadOnlyList<MenuEntry> GroundMenuEntries(short simId, PluginGroundPoint point)
    {
        var entries = new List<MenuEntry>();
        foreach (var plugin in groundMenuPlugins)
            Guard(plugin, "GetGroundMenuEntries", () =>
            {
                var offered = (plugin.Instance.GetGroundMenuEntries(simId, point) ?? []).Take(MaxMenuEntries + 1).ToArray();
                if (offered.Length > MaxMenuEntries) throw new InvalidDataException($"GetGroundMenuEntries returned more than {MaxMenuEntries} entries");
                var ids = new HashSet<string>(StringComparer.Ordinal);
                foreach (var entry in offered)
                {
                    if (entry == null || !ValidMenuId(entry.Id) || !ids.Add(entry.Id)) throw new InvalidDataException("GetGroundMenuEntries returned a missing, malformed or repeated entry ID");
                    if (!ValidMenuName(entry.Name)) throw new InvalidDataException($"Ground menu entry {entry.Id} has a malformed name");
                }
                entries.AddRange(offered.Select(entry => new MenuEntry(plugin.Descriptor.PackId, entry.Id, entry.Name)));
            });
        return entries;
    }

    public object ChooseGroundMenuEntry(short simId, PluginGroundPoint point, string packId, string entryId)
    {
        var plugin = groundMenuPlugins.FirstOrDefault(candidate => candidate.Descriptor.PackId == packId && !candidate.Failed)
            ?? throw new InvalidOperationException("The ground menu entry's plugin is not running");
        if (!GroundMenuEntries(simId, point).Any(entry => entry.PackId == packId && entry.Entry == entryId))
            throw new ArgumentException("The plugin no longer offers that ground menu entry");
        (choosingPack, shownPanel, shownPanelAnchor) = (packId, null, null);
        try { Guard(plugin, "OnGroundMenuEntry", () => plugin.Instance.OnGroundMenuEntry(simId, point, entryId)); }
        finally { choosingPack = null; }
        FlushPanels();
        FlushClientStates();
        var panel = plugin.Failed ? null : shownPanel;
        var anchorId = panel == null ? null : shownPanelAnchor;
        if (panel != null) write(new { type = "pluginPanelShow", packId, panelId = panel, anchorId });
        return new { accepted = !plugin.Failed, panel, anchorId };
    }

    private static bool ValidMenuId(string? id) =>
        id is { Length: > 0 and <= MaxKeyLength } && id.All(c => char.IsAsciiLetterOrDigit(c) || c is '.' or '-' or '_');

    private static bool ValidMenuName(string? name) =>
        name is { Length: > 0 and <= MaxKeyLength } && !name.Any(char.IsControl) && name.Split('/').All(part => part.Length > 0);

    public object PanelAction(string packId, string panelId, string action)
    {
        if (!declaredPanels.Contains((packId, panelId))) throw new ArgumentException("Unknown plugin panel");
        if (string.IsNullOrEmpty(action) || action.Length > MaxKeyLength) throw new ArgumentException("Invalid plugin panel action");
        var plugin = loaded.FirstOrDefault(candidate => candidate.Descriptor.PackId == packId && !candidate.Failed)
            ?? throw new InvalidOperationException("The panel's plugin is not running");
        Guard(plugin, "OnPanelAction", () => plugin.Instance.OnPanelAction(panelId, action));
        FlushPanels();
        FlushClientStates();
        return new { accepted = !plugin.Failed };
    }

    public object ClientCommand(string packId, string command, string? payload)
    {
        if (string.IsNullOrEmpty(command) || command.Length > MaxKeyLength) throw new ArgumentException("Invalid plugin client command");
        if (payload is { Length: > MaxValueLength }) throw new ArgumentException("Plugin client command payload is too large");
        var plugin = loaded.FirstOrDefault(candidate => candidate.Descriptor.PackId == packId && !candidate.Failed)
            ?? throw new InvalidOperationException("The target plugin is not running");
        (choosingPack, shownPanel, shownPanelAnchor) = (packId, null, null);
        try { Guard(plugin, "OnClientCommand", () => plugin.Instance.OnClientCommand(command, payload)); }
        finally { choosingPack = null; }
        FlushPanels();
        FlushClientStates();
        var panel = plugin.Failed ? null : shownPanel;
        var anchorId = panel == null ? null : shownPanelAnchor;
        if (panel != null) write(new { type = "pluginPanelShow", packId, panelId = panel, anchorId });
        return new { accepted = !plugin.Failed, panel, anchorId };
    }

    public IReadOnlyList<string> CheatCommands
    {
        get
        {
            var names = new List<string>();
            foreach (var plugin in loaded)
            {
                if (plugin.Failed) continue;
                Guard(plugin, "CheatCommands", () =>
                {
                    foreach (var cmd in plugin.Instance.CheatCommands)
                    {
                        if (!string.IsNullOrWhiteSpace(cmd) && !names.Contains(cmd, StringComparer.OrdinalIgnoreCase))
                            names.Add(cmd);
                    }
                });
            }
            return names;
        }
    }

    public bool TryHandleCheat(string command, string[] args, out string? message)
    {
        foreach (var plugin in loaded)
        {
            if (plugin.Failed) continue;
            string? handled = null;
            ArgumentException? usageError = null;
            Guard(plugin, "OnCheat", () =>
            {
                try
                {
                    handled = plugin.Instance.OnCheat(command, args);
                }
                catch (ArgumentException ex)
                {
                    usageError = ex;
                }
            });
            if (usageError is not null) throw usageError;
            if (handled is not null)
            {
                FlushPanels();
                FlushClientStates();
                message = handled;
                return true;
            }
        }
        message = null;
        return false;
    }

    public void PlayAnimationSound(string packId, string resource, short ownerObjectId, string cue, bool loop, bool stop)
    {
        if (stop)
        {
            stopSoundResource?.Invoke(ownerObjectId, packId + ":" + cue);
        }
        else
        {
            var descriptor = loaded.FirstOrDefault(p => p.Descriptor.PackId == packId)?.Descriptor;
            if (descriptor is not null)
            {
                var path = ResourcePath(descriptor, resource);
                playSoundResource?.Invoke(path, ownerObjectId, packId + ":" + cue, loop);
            }
        }
    }

    public IReadOnlyList<BuyCatalogViewEntry> BuyCatalogViews(IReadOnlyList<PluginCatalogObject> objects)
    {
        var views = new List<BuyCatalogViewEntry>();
        foreach (var plugin in loaded.Where(plugin => !plugin.Failed && plugin.Descriptor.ApiVersion >= 5 && plugin.Instance is IPluginBuyCatalogProvider))
        {
            Guard(plugin, "GetBuyCatalogView", () =>
            {
                var view = ((IPluginBuyCatalogProvider)plugin.Instance).GetBuyCatalogView(objects);
                if (view is null) return;
                if (string.IsNullOrWhiteSpace(view.TabId) || string.IsNullOrWhiteSpace(view.TabLabel))
                    throw new InvalidDataException("Buy catalog view requires a non-empty tabId and tabLabel");
                var collections = (view.Collections ?? [])
                    .Where(c => c is not null && !string.IsNullOrWhiteSpace(c.Id) && !string.IsNullOrWhiteSpace(c.Label))
                    .Take(512)
                    .Select(c => c with { Guids = (c.Guids ?? []).Distinct().ToArray() })
                    .ToArray();
                views.Add(new BuyCatalogViewEntry(plugin.Descriptor.PackId, view with { Collections = collections }));
            });
        }
        return views;
    }

    public void CommitNeighborhood()
    {
        foreach (var plugin in loaded.Where(plugin => plugin.Descriptor.ApiVersion >= 3))
        {
            if (plugin.Failed) throw new InvalidOperationException($"Plugin {plugin.Descriptor.PackId} failed; neighborhood state cannot be saved");
            var path = NeighborhoodPath(plugin.Descriptor.PackId);
            if (path == null) continue;
            ValidateValues(plugin.Context.NeighborhoodStore);
            Directory.CreateDirectory(Path.GetDirectoryName(path)!);
            var record = new NeighborhoodRecord(plugin.Descriptor.Version, plugin.Descriptor.StateVersion, new(plugin.Context.NeighborhoodStore));
            var json = JsonSerializer.Serialize(record, Json);
            if (File.Exists(path) && File.ReadAllText(path) == json) continue;
            File.WriteAllText(path + ".tmp", json);
            File.Move(path + ".tmp", path, true);
        }
    }

    private static void ValidateValues(IReadOnlyDictionary<string, string> values)
    {
        if (values.Count > MaxValues || values.Any(pair => pair.Key.Length is 0 or > MaxKeyLength || pair.Value == null || pair.Value.Length > MaxValueLength))
            throw new InvalidDataException("Neighborhood plugin values exceed the namespace limits");
    }

    private string? NeighborhoodPath(string packId) => neighborhoodRoot == null ? null : Path.Combine(neighborhoodRoot, "PluginState", packId + ".json");

    private BoundedValues LoadNeighborhood(PluginDescriptor descriptor)
    {
        var values = new BoundedValues();
        if (descriptor.ApiVersion < 3) return values;
        var path = NeighborhoodPath(descriptor.PackId);
        if (path == null || !File.Exists(path)) return values;
        var record = JsonSerializer.Deserialize<NeighborhoodRecord>(File.ReadAllText(path), Json) ?? throw new InvalidDataException("Invalid neighborhood plugin state");
        if (record.StateVersion > descriptor.StateVersion || record.StateVersion < 1)
            throw new InvalidDataException($"Neighborhood state for {descriptor.PackId} needs a different state version");
        ValidateValues(record.Values);
        foreach (var pair in record.Values) values[pair.Key] = pair.Value;
        neighborhoodRecords[descriptor.PackId] = record;
        return values;
    }

    private int NeighborhoodVersion(PluginDescriptor descriptor) => descriptor.ApiVersion < 3
        ? throw new NotSupportedException("Neighborhood state needs API 3")
        : neighborhoodRecords.GetValueOrDefault(descriptor.PackId)?.StateVersion ?? descriptor.StateVersion;

    private static string PlainFilename(string filename)
    {
        if (filename.Length is 0 or > 128 || filename != Path.GetFileName(filename) || filename.Contains('\\') || filename is "." or "..")
            throw new ArgumentException("Expected a plain filename");
        return filename;
    }

    private byte[]? ReadLegacy(PluginDescriptor descriptor, string filename)
    {
        if (descriptor.ApiVersion < 3) throw new NotSupportedException("Legacy import needs API 3");
        var path = neighborhoodRoot == null ? null : Path.Combine(neighborhoodRoot, PlainFilename(filename));
        if (path == null || !File.Exists(path)) return null;
        if (new FileInfo(path).Length > MaxStateBytes) throw new InvalidDataException("Legacy plugin state is too large");
        return File.ReadAllBytes(path);
    }

    private byte[] ReadPluginData(PluginDescriptor descriptor, string filename)
    {
        if (descriptor.ApiVersion < 3) throw new NotSupportedException("Plugin data needs API 3");
        var folder = directOverlay != null && directOverlay.PluginFolders.TryGetValue(descriptor.PackId, out var directFolder)
            ? directFolder
            : Path.GetDirectoryName(Path.Combine(mountRoot, descriptor.Assembly))!;
        var path = Path.Combine(folder, PlainFilename(filename));
        if (!path.EndsWith(".json", StringComparison.OrdinalIgnoreCase) || new FileInfo(path).Length > MaxStateBytes)
            throw new InvalidDataException("Plugin data must be a bounded JSON file");
        return File.ReadAllBytes(path);
    }

    private string ResourcePath(PluginDescriptor descriptor, string resource)
    {
        var normalized = resource.Replace('\\', '/').ToLowerInvariant();
        if (descriptor.ApiVersion < 3 || !resourceOwners.TryGetValue(normalized, out var owner) || owner != descriptor.PackId)
            throw new InvalidDataException($"Resource {resource} is not owned by {descriptor.PackId}");
        var cacheKey = descriptor.PackId + "/" + normalized;
        if (approvedResources.TryGetValue(cacheKey, out var approved)) return approved;
        if (!sealedResources.TryGetValue(descriptor.PackId, out var seal))
        {
            seal = JsonSerializer.Deserialize<Dictionary<string, string>>(ReadPluginData(descriptor, "resources.json"))
                ?? throw new InvalidDataException("Missing signed resource list");
            sealedResources[descriptor.PackId] = seal;
        }
        string path;
        if (directOverlay != null)
        {
            if (!directOverlay.ResourcePaths.TryGetValue(normalized, out var directPath) || !File.Exists(directPath))
                throw new InvalidDataException("Plugin resource is missing");
            path = Path.GetFullPath(directPath);
        }
        else
        {
            path = mountRoot;
            foreach (var component in normalized.Split('/'))
            {
                if (component is "" or "." or "..") throw new InvalidDataException("Invalid resource path");
                path = Directory.EnumerateFileSystemEntries(path).FirstOrDefault(entry => Path.GetFileName(entry).Equals(component, StringComparison.OrdinalIgnoreCase))
                    ?? throw new InvalidDataException("Plugin resource is missing");
            }
            path = Path.GetFullPath(path);
            if (!path.StartsWith(mountRoot + Path.DirectorySeparatorChar, OperatingSystem.IsWindows() ? StringComparison.OrdinalIgnoreCase : StringComparison.Ordinal) || !File.Exists(path))
                throw new InvalidDataException("Plugin resource escapes the mount or is missing");
        }
        var hash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))).ToLowerInvariant();
        if (!seal.TryGetValue(normalized, out var expected) || hash != expected)
            throw new InvalidDataException("Plugin resource differs from its trusted digest");
        approvedResources[cacheKey] = path;
        return path;
    }

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
                data == null ? null : Convert.ToBase64String(data), new Dictionary<string, string>(plugin.Context.ValueStore, StringComparer.Ordinal),
                plugin.Descriptor.ApiVersion >= 3 ? new Dictionary<string, string>(plugin.Context.NeighborhoodStore) : null);
        }
        return records;
    }

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
            if (record.NeighborhoodValues != null) ValidateValues(record.NeighborhoodValues);
            if (record.Data != null && (record.Data.Length > MaxStateBytes * 4 / 3 + 4 || !IsBase64(record.Data)))
                throw new InvalidDataException($"Saved state for plugin {packId} is not valid");
        }
    }

    private static bool IsBase64(string value)
    {
        var buffer = new byte[value.Length];
        return Convert.TryFromBase64String(value, buffer, out _);
    }

    public void Restore(IReadOnlyDictionary<string, PluginSaveRecord>? records)
    {
        foreach (var plugin in loaded)
        {
            plugin.Context.ValueStore.Clear();
            if (records == null || !records.TryGetValue(plugin.Descriptor.PackId, out var record))
            {
                if (plugin.Descriptor.ApiVersion >= 3)
                {
                    plugin.Context.NeighborhoodStore.Clear();
                    Guard(plugin, "LoadState", () => plugin.Instance.LoadState(plugin.Descriptor.StateVersion, []));
                }
                continue;
            }
            if (record.NeighborhoodValues != null)
            {
                plugin.Context.NeighborhoodStore.Clear();
                foreach (var (key, value) in record.NeighborhoodValues) plugin.Context.NeighborhoodStore[key] = value;
            }
            else if (plugin.Descriptor.ApiVersion >= 3)
            {
                plugin.Context.NeighborhoodStore.Clear();
            }
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

    private sealed class PluginLoadContext(string assemblyPath) : AssemblyLoadContext("plugin:" + Path.GetFileName(assemblyPath), isCollectible: true)
    {
        private readonly AssemblyDependencyResolver resolver = new(assemblyPath);

        protected override Assembly? Load(AssemblyName name)
        {
            if (name.Name == typeof(ISimsPlugin).Assembly.GetName().Name) return null;
            var path = resolver.ResolveAssemblyToPath(name);
            return path == null ? null : LoadFromAssemblyPath(path);
        }
    }

    private sealed class PluginContext(PluginHost host, PluginDescriptor descriptor) : IPluginContext
    {
        public readonly BoundedValues ValueStore = new();
        public int ApiVersion => descriptor.ApiVersion;
        public string PackId => descriptor.PackId;
        public string PackVersion => descriptor.Version;
        public int StateVersion => descriptor.StateVersion;
        public IPluginSimulation Simulation { get; } = descriptor.ApiVersion switch
        {
            >= 6 => host.simulation(host),
            >= 4 => new VersionFourOrFiveSimulation(host.simulation(host)),
            3 => new VersionThreeSimulation(host.simulation(host)),
            2 => new VersionThreeSimulation(host.simulation(host)),
            _ => new VersionOneSimulation(host.simulation(host))
        };
        public IDictionary<string, string> Values => ValueStore;
        internal BoundedValues NeighborhoodStore { get; } = host.LoadNeighborhood(descriptor);
        public IDictionary<string, string> NeighborhoodValues => descriptor.ApiVersion >= 3 ? NeighborhoodStore : throw new NotSupportedException("Neighborhood values need API 3");
        public int NeighborhoodStateVersion => host.NeighborhoodVersion(descriptor);
        public byte[]? ReadLegacyNeighborhoodData(string filename) => host.ReadLegacy(descriptor, filename);
        public byte[] ReadPluginData(string filename) => host.ReadPluginData(descriptor, filename);
        public void Log(string message) => host.write(new { type = "pluginLog", packId = descriptor.PackId, message });
        public PluginImage ReadImageResource(string resource)
        {
            var bytes = File.ReadAllBytes(host.ResourcePath(descriptor, resource));
            var (width, height, rgba) = BitmapCodec.Read(bytes);
            return new PluginImage(width, height, rgba);
        }

        public void PlaySoundResource(string resource, short ownerObjectId, string cue, bool loop = false)
        {
            if (descriptor.ApiVersion < 3) throw new NotSupportedException("Pack sound resources need API3");
            if (cue.Length is 0 or > MaxKeyLength || cue.Any(ch => !char.IsAsciiLetterOrDigit(ch) && ch != '-' && ch != '_')) throw new ArgumentException("Invalid sound cue key");
            if (!host.simulation(host).Objects.Any(item => item.ObjectId == ownerObjectId)) throw new ArgumentException("Sound owner is not on the lot");
            host.playSoundResource?.Invoke(host.ResourcePath(descriptor, resource), ownerObjectId, descriptor.PackId + ":" + cue, loop);
        }

        public void StopSoundResource(short ownerObjectId, string cue)
        {
            if (descriptor.ApiVersion < 3) throw new NotSupportedException("Pack sound resources need API3");
            if (cue.Length is 0 or > MaxKeyLength || cue.Any(ch => !char.IsAsciiLetterOrDigit(ch) && ch != '-' && ch != '_')) throw new ArgumentException("Invalid sound cue key");
            host.stopSoundResource?.Invoke(ownerObjectId, descriptor.PackId + ":" + cue);
        }

        private void CheckAttribute(int index)
        {
            if (descriptor.ApiVersion < 3) throw new NotSupportedException("Object attributes need API3");
            if (index is < 0 or > 255) throw new ArgumentOutOfRangeException(nameof(index));
        }

        public short GetObjectAttribute(short objectId, int index)
        {
            CheckAttribute(index);
            if (host.world is not { } world) throw new InvalidOperationException("No plugin world is available");
            return world.GetObjectAttribute(objectId, index);
        }

        public void SetObjectAttribute(short objectId, int index, short value)
        {
            CheckAttribute(index);
            if (host.world is not { } world) throw new InvalidOperationException("No plugin world is available");
            world.SetObjectAttribute(objectId, index, value);
        }

        public void SetObjectGraphic(short objectId, short graphic)
        {
            if (descriptor.ApiVersion < 3) throw new NotSupportedException("Object graphics need API3");
            if (graphic < 0) throw new ArgumentOutOfRangeException(nameof(graphic));
            if (host.world is not { } world) throw new InvalidOperationException("No plugin world is available");
            world.SetObjectGraphic(objectId, graphic);
        }

        public short? TryPlaceOwnedObject(uint guid, int tileX, int tileY, int level = 1, short direction = 0, short? clearForSimId = null)
        {
            if (descriptor.ApiVersion < 4) throw new NotSupportedException("Pack object placement needs API4");
            if (host.world is not { } world) throw new InvalidOperationException("No plugin world is available");
            if (host.objectOwners.TryGetValue(guid, out var owner) && owner != descriptor.PackId)
                throw new ArgumentException("Only this pack's own objects may be placed");
            return world.TryPlaceOwnedObject(descriptor.PackId, guid, tileX, tileY, level, direction, clearForSimId);
        }

        public bool TryRemoveOwnedObject(short objectId)
        {
            if (descriptor.ApiVersion < 4) throw new NotSupportedException("Pack object removal needs API4");
            if (host.world is not { } world) throw new InvalidOperationException("No plugin world is available");
            return world.TryRemoveOwnedObject(descriptor.PackId, objectId);
        }

        public string? ResolveSimSuit(short simId, char categoryPrefix, int bodyStringIndex)
        {
            if (descriptor.ApiVersion < 4) throw new NotSupportedException("Sim suit resolution needs API4");
            if (bodyStringIndex is < 0 or > 128) throw new ArgumentOutOfRangeException(nameof(bodyStringIndex));
            if (host.world is not { } world) throw new InvalidOperationException("No plugin world is available");
            return world.ResolveSimSuit(simId, categoryPrefix, bodyStringIndex);
        }

        public void SetSimAppearanceOverride(short simId, string? bodySuitSpec, bool animateSpin = true)
        {
            if (descriptor.ApiVersion < 4) throw new NotSupportedException("Sim appearance overrides need API4");
            if (bodySuitSpec is { Length: > 256 }) throw new ArgumentOutOfRangeException(nameof(bodySuitSpec));
            if (host.world is not { } world) throw new InvalidOperationException("No plugin world is available");
            world.SetSimAppearanceOverride(simId, bodySuitSpec, animateSpin);
        }

        public void PublishClientState(byte[] data)
        {
            ArgumentNullException.ThrowIfNull(data);
            if (data.Length > MaxStateBytes)
                throw new ArgumentException("Client state snapshot exceeds 1 MiB");
            if (host.clientStates.TryGetValue(descriptor.PackId, out var existing) && existing.AsSpan().SequenceEqual(data))
                return;
            host.clientStates[descriptor.PackId] = data.ToArray();
            host.clientStatesChanged = true;
        }

        public IDictionary<string, float> SharedBlackboard => new ObservedBlackboard(host);

        public void SetPanelValue(string panelId, string binding, string value)
        {
            if (!host.declaredPanels.Contains((descriptor.PackId, panelId))) throw new ArgumentException($"Panel {panelId} is not declared by pack {descriptor.PackId}");
            if (string.IsNullOrEmpty(binding) || binding.Length > MaxKeyLength) throw new ArgumentException("Invalid panel binding");
            if (value.Length > MaxValueLength) throw new ArgumentException("Panel values are limited to 4096 characters");
            var key = (descriptor.PackId, panelId);
            if (!host.panelValues.TryGetValue(key, out var map)) host.panelValues[key] = map = new Dictionary<string, string>(StringComparer.Ordinal);
            if (map.TryGetValue(binding, out var existing) && existing == value) return;
            map[binding] = value;
            host.panelValuesChanged = true;
        }

        public void ShowPanel(string panelId) => ShowPanel(panelId, null);
        public void ShowPanel(string panelId, short anchorObjectId) => ShowPanel(panelId, (short?)anchorObjectId);

        public void ShowPanel(string panelId, short? anchorObjectId = null)
        {
            if (!host.declaredPanels.Contains((descriptor.PackId, panelId))) throw new ArgumentException($"Panel {panelId} is not declared by pack {descriptor.PackId}");
            if (host.choosingPack != descriptor.PackId) throw new InvalidOperationException("ShowPanel may only be called from OnMenuEntry");
            if (anchorObjectId is { } id &&
                !host.simulation(host).Objects.Any(item => item.ObjectId == id) &&
                !host.simulation(host).HouseholdSims.Any(sim => sim.ObjectId == id))
                throw new ArgumentException("Anchor object does not exist on this lot");
            (host.shownPanel, host.shownPanelAnchor) = (panelId, anchorObjectId);
        }
    }

    internal sealed class BoundedValues : Dictionary<string, string>, IDictionary<string, string>
    {
        public BoundedValues() : base(StringComparer.Ordinal) { }

        private void Check(string key, string value, bool allowReplace)
        {
            if (string.IsNullOrEmpty(key) || key.Length > MaxKeyLength) throw new ArgumentException("Invalid value key");
            if (value == null || value.Length > MaxValueLength) throw new ArgumentException("Invalid value payload");
            if ((!allowReplace || !ContainsKey(key)) && Count >= MaxValues)
                throw new ArgumentException("Too many plugin values");
        }

        public new string this[string key]
        {
            get => base[key];
            set { Check(key, value, allowReplace: true); base[key] = value; }
        }

        public new void Add(string key, string value) { Check(key, value, allowReplace: false); base.Add(key, value); }

        string IDictionary<string, string>.this[string key]
        {
            get => this[key];
            set => this[key] = value;
        }

        void IDictionary<string, string>.Add(string key, string value) => Add(key, value);
        void ICollection<KeyValuePair<string, string>>.Add(KeyValuePair<string, string> item) => Add(item.Key, item.Value);
    }

    private sealed class ObservedBlackboard(PluginHost host) : IDictionary<string, float>
    {
        private static void Check(string key, float value)
        {
            if (string.IsNullOrEmpty(key) || key.Length > MaxKeyLength) throw new ArgumentException("Invalid blackboard key");
            if (!float.IsFinite(value)) throw new ArgumentException("Blackboard value must be finite");
        }

        public float this[string key]
        {
            get => host.sharedBlackboard[key];
            set
            {
                Check(key, value);
                if (!host.sharedBlackboard.ContainsKey(key) && host.sharedBlackboard.Count >= MaxValues)
                    throw new ArgumentException("Too many blackboard entries");
                if (host.sharedBlackboard.TryGetValue(key, out var existing) && existing == value)
                    return;
                host.sharedBlackboard[key] = value;
                host.clientStatesChanged = true;
            }
        }

        public ICollection<string> Keys => host.sharedBlackboard.Keys;
        public ICollection<float> Values => host.sharedBlackboard.Values;
        public int Count => host.sharedBlackboard.Count;
        public bool IsReadOnly => false;
        public void Add(string key, float value) => this[key] = value;
        public void Add(KeyValuePair<string, float> item) => this[item.Key] = item.Value;
        public void Clear()
        {
            if (host.sharedBlackboard.Count == 0) return;
            host.sharedBlackboard.Clear();
            host.clientStatesChanged = true;
        }
        public bool Contains(KeyValuePair<string, float> item) => ((ICollection<KeyValuePair<string, float>>)host.sharedBlackboard).Contains(item);
        public bool ContainsKey(string key) => host.sharedBlackboard.ContainsKey(key);
        public void CopyTo(KeyValuePair<string, float>[] array, int arrayIndex) => ((ICollection<KeyValuePair<string, float>>)host.sharedBlackboard).CopyTo(array, arrayIndex);
        public IEnumerator<KeyValuePair<string, float>> GetEnumerator() => host.sharedBlackboard.GetEnumerator();
        public bool Remove(string key)
        {
            if (!host.sharedBlackboard.Remove(key)) return false;
            host.clientStatesChanged = true;
            return true;
        }
        public bool Remove(KeyValuePair<string, float> item) => Remove(item.Key);
        public bool TryGetValue(string key, out float value) => host.sharedBlackboard.TryGetValue(key, out value);
        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() => GetEnumerator();
    }

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

    private sealed class VersionThreeSimulation(IPluginSimulation inner) : IPluginSimulation
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
        public IReadOnlyList<PluginObject> Objects => inner.Objects;
        public IReadOnlyList<PluginInteraction> GetInteractions(short simId, short objectId) => inner.GetInteractions(simId, objectId);
        public IReadOnlyList<string> GetDefinedInteractions(short objectId) => inner.GetDefinedInteractions(objectId);
        public bool TryQueueInteraction(short simId, short objectId, int interactionId, short param0 = 0, bool global = false) =>
            inner.TryQueueInteraction(simId, objectId, interactionId, param0, global);
        public IReadOnlyList<string> GetQueuedActions(short simId) => inner.GetQueuedActions(simId);
        public short ChangeMotive(short simId, int motive, int delta) => inner.ChangeMotive(simId, motive, delta);
        public bool TryQueuePairedSocialAction(PluginPairedSocialRole first, PluginPairedSocialRole second, out long actionId)
        { actionId = 0; throw new NotSupportedException("Paired social actions need plugin API version 4"); }
        public PluginPairedSocialActionStatus? GetPairedSocialActionStatus(long actionId) =>
            throw new NotSupportedException("Paired social actions need plugin API version 4");
    }

    private sealed class VersionFourOrFiveSimulation(IPluginSimulation inner) : IPluginSimulation
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
        public IReadOnlyList<PluginObject> Objects => inner.Objects;
        public IReadOnlyList<PluginInteraction> GetInteractions(short simId, short objectId) => inner.GetInteractions(simId, objectId);
        public IReadOnlyList<string> GetDefinedInteractions(short objectId) => inner.GetDefinedInteractions(objectId);
        public bool TryQueueInteraction(short simId, short objectId, int interactionId, short param0 = 0, bool global = false) =>
            inner.TryQueueInteraction(simId, objectId, interactionId, param0, global);
        public IReadOnlyList<string> GetQueuedActions(short simId) => inner.GetQueuedActions(simId);
        public short ChangeMotive(short simId, int motive, int delta) => inner.ChangeMotive(simId, motive, delta);
        public bool TryQueuePairedSocialAction(PluginPairedSocialRole first, PluginPairedSocialRole second, out long actionId) =>
            inner.TryQueuePairedSocialAction(first, second, out actionId);
        public PluginPairedSocialActionStatus? GetPairedSocialActionStatus(long actionId) =>
            inner.GetPairedSocialActionStatus(actionId);
    }
}
