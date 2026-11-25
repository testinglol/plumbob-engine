using System.Reflection;
using System.Runtime.Loader;
using SimsNative.Plugins;
using SimsSDL.Core;
using SimsSDL.UI;

namespace SimsSDL.Client;

public sealed class ClientPluginHost : IDisposable
{
    public sealed record HudWidget(
        string PackId,
        string WidgetId,
        OriginalGameplayOverlay.Image Image,
        PluginHudAnchor Anchor,
        CGRect Rect,
        string? Tooltip,
        float Opacity);

    private sealed class ClientPluginLoadContext(string assemblyPath) : AssemblyLoadContext(isCollectible: true)
    {
        private readonly AssemblyDependencyResolver _resolver = new(assemblyPath);

        protected override Assembly? Load(AssemblyName assemblyName)
        {
            if (string.Equals(assemblyName.Name, typeof(ISimsClientPlugin).Assembly.GetName().Name, StringComparison.Ordinal))
                return null;
            string? resolved = _resolver.ResolveAssemblyToPath(assemblyName);
            return resolved is null ? null : LoadFromAssemblyPath(resolved);
        }
    }

    private sealed class LoadedClientPlugin(
        ContentPack pack,
        ISimsClientPlugin instance,
        ClientContext context,
        ClientPluginLoadContext loadContext)
    {
        public ContentPack Pack { get; } = pack;
        public string PackId => Pack.Manifest.Id;
        public ISimsClientPlugin Instance { get; } = instance;
        public ClientContext Context { get; } = context;
        public ClientPluginLoadContext LoadContext { get; } = loadContext;
        public bool Failed { get; set; }
    }

    private sealed class ClientContext(ClientPluginHost host, ContentPack pack) : IClientPluginContext
    {
        public string PackId => pack.Manifest.Id;
        public string PackVersion => pack.Manifest.Version;
        public IReadOnlyDictionary<string, float> Blackboard => host._mergedBlackboard;

        public byte[] ReadPluginData(string filename)
        {
            if (string.IsNullOrWhiteSpace(filename) || filename.IndexOfAny(['/', '\\', ':']) >= 0 || filename.Contains("..", StringComparison.Ordinal))
                throw new ArgumentException("Invalid plugin data filename", nameof(filename));
            string pluginFolder = pack.PluginAssembly is { } asm ? Path.GetDirectoryName(asm)! : Path.Combine(pack.Directory, "plugin");
            string fullPath = Path.Combine(pluginFolder, filename);
            if (!File.Exists(fullPath))
                throw new FileNotFoundException($"Plugin data file {filename} was not found in {PackId}");
            return File.ReadAllBytes(fullPath);
        }

        public byte[] ReadResourceBytes(string resource)
        {
            string key = PackContentPaths.ResourceKey(resource);
            if (!pack.Assets.TryGetValue(key, out string? fullPath) || !File.Exists(fullPath))
                throw new FileNotFoundException($"Pack resource {resource} was not found in {PackId}");
            return File.ReadAllBytes(fullPath);
        }

        public void SetBlackboardValue(string key, float value)
        {
            if (string.IsNullOrEmpty(key) || key.Length > 64 || !float.IsFinite(value))
                throw new ArgumentException("Invalid blackboard entry");
            host._clientBlackboard[key] = value;
            host.RebuildBlackboard();
        }

        public void SendServerCommand(string command, string? payload = null)
        {
            if (string.IsNullOrEmpty(command) || command.Length > 64)
                throw new ArgumentException("Invalid server command", nameof(command));
            host._sendServerCommand?.Invoke(PackId, command, payload);
        }

        public void Log(string message) => AppLog.Info($"[ClientPlugin:{PackId}] {message}");
    }

    private sealed class UiFrameContext(ClientPluginHost host, UIDevice device) : IPluginUiContext
    {
        public string ActivePackId { get; set; } = string.Empty;
        public bool InLiveMode { get; set; }
        public bool ControlPanelMinimized { get; set; }
        public List<HudWidget> Widgets { get; } = [];

        public void RegisterImage(string imageKey, int pixelWidth, int pixelHeight, ReadOnlySpan<byte> rgba, double logicalWidth = 0, double logicalHeight = 0)
        {
            if (string.IsNullOrEmpty(imageKey) || imageKey.Length > 64)
                throw new ArgumentException("Invalid image key", nameof(imageKey));
            if (pixelWidth is <= 0 or > 2048 || pixelHeight is <= 0 or > 2048 || rgba.Length != checked(pixelWidth * pixelHeight * 4))
                throw new ArgumentException("Invalid RGBA image dimensions");

            var cacheKey = (ActivePackId, imageKey);
            ulong hash = ComputeHash(rgba);
            var logical = new CGSize(logicalWidth > 0 ? logicalWidth : pixelWidth, logicalHeight > 0 ? logicalHeight : pixelHeight);
            if (host._registeredImages.TryGetValue(cacheKey, out var cached)
                && cached.Width == pixelWidth
                && cached.Height == pixelHeight
                && cached.Hash == hash
                && cached.Image.Size == logical)
            {
                return;
            }

            var created = OriginalGameplayOverlay.CreateImage(device, pixelWidth, pixelHeight, rgba.ToArray(), logical);
            host._registeredImages[cacheKey] = (pixelWidth, pixelHeight, hash, created);
        }

        public void DrawWidget(string widgetId, string imageKey, PluginHudAnchor anchor, PluginUiRect rect, string? tooltip = null, float opacity = 1f)
        {
            if (string.IsNullOrEmpty(widgetId) || widgetId.Length > 64)
                throw new ArgumentException("Invalid widget ID", nameof(widgetId));
            if (!host._registeredImages.TryGetValue((ActivePackId, imageKey), out var entry))
                return;
            Widgets.Add(new HudWidget(
                ActivePackId,
                widgetId,
                entry.Image,
                anchor,
                new CGRect(rect.X, rect.Y, rect.Width, rect.Height),
                tooltip,
                Math.Clamp(opacity, 0f, 1f)));
        }

        public void ShowToastBanner(string text, double durationSeconds = 4.5)
        {
            if (string.IsNullOrWhiteSpace(text) || text.Length > 256)
                return;
            double duration = Math.Clamp(durationSeconds, 0.5, 15.0);
            host._pendingToast = (text.Trim(), duration);
        }

        private static ulong ComputeHash(ReadOnlySpan<byte> bytes)
        {
            ulong h = 14695981039346656037UL ^ (uint)bytes.Length;
            for (int i = 0; i < bytes.Length; i++)
                h = (h ^ bytes[i]) * 1099511628211UL;
            return h;
        }
    }

    private sealed class AudioFrameContext(ClientPluginHost host) : IPluginAudioContext
    {
        public string ActivePackId { get; set; } = string.Empty;
        public bool Paused { get; set; }
        public float CombinedGain { get; set; } = 1f;
        public float CombinedCutoff { get; set; }
        public Dictionary<string, (string Path, float Gain)> DesiredLoops { get; } = new(StringComparer.Ordinal);

        public void SetEnvironmentMuffle(float gain, float cutoffHz)
        {
            if (float.IsFinite(gain))
                CombinedGain = Math.Clamp(CombinedGain * Math.Clamp(gain, 0f, 1f), 0f, 1f);
            if (float.IsFinite(cutoffHz) && cutoffHz > 0f)
                CombinedCutoff = CombinedCutoff > 0f ? Math.Min(CombinedCutoff, cutoffHz) : cutoffHz;
        }

        public void SetAmbientLoop(string cue, string packResource, float gain)
        {
            if (Paused || !float.IsFinite(gain) || gain <= 0.002f || string.IsNullOrWhiteSpace(cue) || cue.Length > 64)
                return;
            if (host.ResolveResourcePath(ActivePackId, packResource) is not { } fullPath)
                return;
            DesiredLoops[$"{ActivePackId}:{cue}"] = (fullPath, Math.Clamp(gain, 0f, 1f));
        }
    }

    private readonly List<LoadedClientPlugin> _plugins = [];
    private readonly Action<string, string, string?>? _sendServerCommand;
    private readonly Dictionary<string, float> _serverBlackboard = new(StringComparer.Ordinal);
    private readonly Dictionary<string, float> _clientBlackboard = new(StringComparer.Ordinal);
    private readonly Dictionary<string, float> _mergedBlackboard = new(StringComparer.Ordinal);
    private readonly Dictionary<(string PackId, string Key), (int Width, int Height, ulong Hash, OriginalGameplayOverlay.Image Image)> _registeredImages = new();
    private (string Text, double Duration)? _pendingToast;
    private UiFrameContext? _uiFrame;
    private AudioFrameContext? _audioFrame;
    private bool _disposed;

    public bool HasClientPlugins => _plugins.Any(static p => !p.Failed);
    public IReadOnlyDictionary<string, float> Blackboard => _mergedBlackboard;

    public bool SuppressVanillaRoomLighting
    {
        get
        {
            foreach (var plugin in _plugins)
            {
                if (plugin.Failed) continue;
                bool suppress = false;
                Guard(plugin, "SuppressVanillaRoomLighting", () => suppress = plugin.Instance.SuppressVanillaRoomLighting);
                if (suppress) return true;
            }
            return false;
        }
    }

    public string? ActiveTerrainShaderPath
    {
        get
        {
            string? resolved = null;
            foreach (var plugin in _plugins)
            {
                if (plugin.Failed) continue;
                string? resource = null;
                Guard(plugin, "TerrainFragmentShader", () => resource = plugin.Instance.TerrainFragmentShader);
                if (!string.IsNullOrEmpty(resource) && ResolveShaderBasePath(plugin.PackId, resource) is { } path)
                    resolved = path;
            }
            return resolved;
        }
    }

    public bool HasActiveRenderPasses
    {
        get
        {
            foreach (var plugin in _plugins)
            {
                if (plugin.Failed) continue;
                bool any = false;
                Guard(plugin, "RenderStages", () => any = plugin.Instance.RenderStages.Count > 0);
                if (any) return true;
            }
            return false;
        }
    }

    public ClientPluginHost(
        GameContent content,
        string dataRoot,
        Action<string, string, string?>? sendServerCommand = null)
    {
        ArgumentNullException.ThrowIfNull(content);
        ArgumentException.ThrowIfNullOrEmpty(dataRoot);
        _sendServerCommand = sendServerCommand;

        PluginTrustStore? trustStore = null;
        try { trustStore = new PluginTrustStore(dataRoot); }
        catch { trustStore = null; }
        if (trustStore is null)
            return;

        var reports = content.Packs.PluginReports().ToDictionary(static r => r.PackID, StringComparer.Ordinal);
        foreach (var pack in content.Packs.Ordered)
        {
            if (pack.Manifest.Plugin is not { ClientEntryType: { Length: > 0 } clientEntryType } ||
                pack.PluginAssembly is not { } assemblyPath ||
                !reports.TryGetValue(pack.Manifest.Id, out var report) ||
                !trustStore.IsTrusted(report))
            {
                continue;
            }

            ClientPluginLoadContext? loadContext = null;
            try
            {
                loadContext = new ClientPluginLoadContext(assemblyPath);
                var assembly = loadContext.LoadFromAssemblyPath(assemblyPath);
                var type = assembly.GetType(clientEntryType, throwOnError: false)
                    ?? throw new InvalidDataException($"Client entry type {clientEntryType} was not found");
                if (!typeof(ISimsClientPlugin).IsAssignableFrom(type) || type.IsAbstract || type.GetConstructor(Type.EmptyTypes) is null)
                    throw new InvalidDataException($"Client entry type {clientEntryType} must implement ISimsClientPlugin with a parameterless constructor");
                var instance = (ISimsClientPlugin)Activator.CreateInstance(type)!;
                var context = new ClientContext(this, pack);
                var loaded = new LoadedClientPlugin(pack, instance, context, loadContext);
                instance.Initialize(context);
                _plugins.Add(loaded);
            }
            catch (Exception ex) when (ex is not OutOfMemoryException)
            {
                AppLog.Warn($"Client plugin {pack.Manifest.Id} failed to initialize: {Unwrap(ex).Message}");
                loadContext?.Unload();
            }
        }
    }

    public void ApplyServerStates(JsonElement payload)
    {
        if (payload.TryGetProperty("blackboard", out var bbEl) && bbEl.ValueKind == JsonValueKind.Object)
        {
            _serverBlackboard.Clear();
            foreach (var prop in bbEl.EnumerateObject())
            {
                if (prop.Value.TryGetSingle(out float val) && float.IsFinite(val))
                    _serverBlackboard[prop.Name] = val;
            }
            RebuildBlackboard();
        }

        if (payload.TryGetProperty("states", out var statesEl) && statesEl.ValueKind == JsonValueKind.Array)
        {
            foreach (var item in statesEl.EnumerateArray())
            {
                string? packId = item.TryGetProperty("packId", out var pEl) ? pEl.GetString() : null;
                string? b64 = item.TryGetProperty("data", out var dEl) ? dEl.GetString() : null;
                if (string.IsNullOrEmpty(packId) || b64 is null)
                    continue;
                var target = _plugins.FirstOrDefault(p => !p.Failed && string.Equals(p.PackId, packId, StringComparison.Ordinal));
                if (target is null)
                    continue;
                byte[] raw;
                try { raw = Convert.FromBase64String(b64); }
                catch { continue; }
                Guard(target, "OnServerState", () => target.Instance.OnServerState(raw));
            }
        }
    }

    public void DeliverServerState(string packId, byte[] raw)
    {
        var target = _plugins.FirstOrDefault(p => !p.Failed && string.Equals(p.PackId, packId, StringComparison.Ordinal));
        if (target is not null)
        {
            Guard(target, "OnServerState", () => target.Instance.OnServerState(raw));
        }
    }

    public (IReadOnlyList<HudWidget> Widgets, (string Text, double Duration)? PendingToast) BuildHud(
        UIDevice device,
        bool inLiveMode,
        bool controlPanelMinimized)
    {
        if (_plugins.Count == 0)
            return ([], null);

        _uiFrame ??= new UiFrameContext(this, device);
        _uiFrame.Widgets.Clear();
        _uiFrame.InLiveMode = inLiveMode;
        _uiFrame.ControlPanelMinimized = controlPanelMinimized;
        _pendingToast = null;

        foreach (var plugin in _plugins)
        {
            if (plugin.Failed) continue;
            _uiFrame.ActivePackId = plugin.PackId;
            Guard(plugin, "BuildHud", () => plugin.Instance.BuildHud(_uiFrame));
        }

        return (_uiFrame.Widgets, _pendingToast);
    }

    public bool DispatchHudClick(string packId, string widgetId)
    {
        var plugin = _plugins.FirstOrDefault(p => !p.Failed && string.Equals(p.PackId, packId, StringComparison.Ordinal));
        if (plugin is null)
            return false;
        bool handled = false;
        Guard(plugin, "OnHudClick", () => handled = plugin.Instance.OnHudClick(widgetId));
        return handled;
    }

    public void TransformNeighborhoodTexture(PluginNeighborhoodTexture descriptor, Span<byte> rgba)
    {
        if (_plugins.Count == 0)
            return;
        byte[]? copy = null;
        foreach (var plugin in _plugins)
        {
            if (plugin.Failed) continue;
            copy ??= rgba.ToArray();
            try
            {
                plugin.Instance.TransformNeighborhoodTexture(descriptor, copy);
            }
            catch (Exception ex) when (ex is not OutOfMemoryException)
            {
                plugin.Failed = true;
                AppLog.Warn($"Client plugin {plugin.PackId} failed in TransformNeighborhoodTexture: {Unwrap(ex).Message}");
                copy = rgba.ToArray();
            }
        }
        if (copy is not null)
            copy.CopyTo(rgba);
    }

    public string? ResolveResourcePath(string packId, string resource)
    {
        var plugin = _plugins.FirstOrDefault(p => !p.Failed && string.Equals(p.PackId, packId, StringComparison.Ordinal));
        if (plugin is null || string.IsNullOrWhiteSpace(resource))
            return null;
        string key = PackContentPaths.ResourceKey(resource);
        return plugin.Pack.Assets.TryGetValue(key, out string? fullPath) && File.Exists(fullPath) ? fullPath : null;
    }

    public string? ResolveShaderBasePath(string packId, string shaderResource)
    {
        var plugin = _plugins.FirstOrDefault(p => !p.Failed && string.Equals(p.PackId, packId, StringComparison.Ordinal));
        if (plugin is null || string.IsNullOrWhiteSpace(shaderResource))
            return null;

        string spvKey = PackContentPaths.ResourceKey(shaderResource + ".spv");
        if (plugin.Pack.Assets.TryGetValue(spvKey, out string? spvPath) && spvPath.EndsWith(".spv", StringComparison.OrdinalIgnoreCase))
            return spvPath[..^4];

        string mslKey = PackContentPaths.ResourceKey(shaderResource + ".msl");
        if (plugin.Pack.Assets.TryGetValue(mslKey, out string? mslPath) && mslPath.EndsWith(".msl", StringComparison.OrdinalIgnoreCase))
            return mslPath[..^4];

        return null;
    }

    public void RenderStage(PluginRenderStage stage, Func<string, IPluginRenderContext> contextFactory)
    {
        foreach (var plugin in _plugins)
        {
            if (plugin.Failed) continue;
            bool participates = false;
            Guard(plugin, "RenderStages", () => participates = plugin.Instance.RenderStages.Contains(stage));
            if (!participates || plugin.Failed) continue;
            var ctx = contextFactory(plugin.PackId);
            Guard(plugin, $"Render({stage})", () => plugin.Instance.Render(ctx));
        }
    }

    public void UpdateAudio(SDLAudioPlayer? audioPlayer, bool paused)
    {
        if (audioPlayer is null)
            return;
        if (_plugins.Count == 0)
        {
            audioPlayer.SetEnvironmentAudio(1f, 0f);
            audioPlayer.UpdateAmbientBeds(null);
            return;
        }

        _audioFrame ??= new AudioFrameContext(this);
        _audioFrame.Paused = paused;
        _audioFrame.CombinedGain = 1f;
        _audioFrame.CombinedCutoff = 0f;
        _audioFrame.DesiredLoops.Clear();

        foreach (var plugin in _plugins)
        {
            if (plugin.Failed) continue;
            _audioFrame.ActivePackId = plugin.PackId;
            Guard(plugin, "UpdateAudio", () => plugin.Instance.UpdateAudio(_audioFrame));
        }

        audioPlayer.SetEnvironmentAudio(_audioFrame.CombinedGain, _audioFrame.CombinedCutoff);
        audioPlayer.UpdateAmbientBeds(_audioFrame.DesiredLoops);
    }

    private void RebuildBlackboard()
    {
        _mergedBlackboard.Clear();
        foreach (var (k, v) in _serverBlackboard)
            _mergedBlackboard[k] = v;
        foreach (var (k, v) in _clientBlackboard)
            _mergedBlackboard[k] = v;
    }

    private static void Guard(LoadedClientPlugin plugin, string op, Action action)
    {
        if (plugin.Failed) return;
        try { action(); }
        catch (Exception ex) when (ex is not OutOfMemoryException)
        {
            plugin.Failed = true;
            AppLog.Warn($"Client plugin {plugin.PackId} failed in {op}: {Unwrap(ex).Message}");
        }
    }

    private static Exception Unwrap(Exception error) =>
        error is TargetInvocationException { InnerException: { } inner } ? inner : error;

    public void Dispose()
    {
        if (_disposed) return;
        _disposed = true;
        foreach (var plugin in _plugins)
        {
            try { plugin.Instance.Dispose(); }
            catch { }
            try { plugin.LoadContext.Unload(); }
            catch { }
        }
        _plugins.Clear();
        _registeredImages.Clear();
    }
}
