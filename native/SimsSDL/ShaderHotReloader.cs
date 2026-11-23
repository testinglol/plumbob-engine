using System.Collections.Concurrent;
using System.Diagnostics;
using System.Globalization;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;

namespace SimsSDL;

internal sealed partial class ShaderHotReloader : IDisposable
{
    internal enum ShaderBucket
    {
        Core,
        Effect,
    }

    internal readonly record struct LiveCaptureRequest(string Id, string OutputPath, bool HideUi, CompiledSwapSummary? ReloadSummary);

    internal sealed record CompiledSwapSummary(
        long Revision,
        bool Ok,
        List<string> Reloaded,
        Dictionary<string, string> Errors,
        long ElapsedMs);

    private readonly record struct FileStamp(long LastWriteTicks, long Length);

    private sealed record ReloadJob(
        string? CommandId,
        bool ForceAll,
        string[]? RequestedShaders,
        string? ChainedShotPath,
        bool ChainedShotHideUi);

    private sealed record CompiledBatch(
        string? CommandId,
        Dictionary<string, string> CoreOutputs,
        Dictionary<string, string> EffectOutputs,
        List<string> ReloadedLabels,
        Dictionary<string, string> Errors,
        long ElapsedMs,
        string? ChainedShotPath,
        bool ChainedShotHideUi,
        bool NothingChanged);

    private sealed class LiveCommandPayload
    {
        [JsonPropertyName("id")]
        public string? Id { get; set; }

        [JsonPropertyName("action")]
        public string? Action { get; set; }

        [JsonPropertyName("path")]
        public string? Path { get; set; }

        [JsonPropertyName("hideUi")]
        public bool HideUi { get; set; }

        [JsonPropertyName("force")]
        public bool Force { get; set; }

        [JsonPropertyName("shaders")]
        public string[]? Shaders { get; set; }

        [JsonPropertyName("mode")]
        public int Mode { get; set; }

        [JsonPropertyName("azimuth")]
        public float? Azimuth { get; set; }

        [JsonPropertyName("elevation")]
        public float? Elevation { get; set; }

        [JsonPropertyName("clear")]
        public bool Clear { get; set; }

        [JsonPropertyName("targetPid")]
        public int? TargetPid { get; set; }
    }

    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        WriteIndented = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
    };

    private static readonly JsonSerializerOptions JsonReadOptions = new()
    {
        PropertyNameCaseInsensitive = true,
    };

    private readonly string _workspace;
    private readonly string _stagingRoot;
    private readonly string _coreStagingDir;
    private readonly string _effectStagingDir;
    private readonly string _liveDevDir;
    private readonly string _statusPath;
    private readonly string _commandPath;
    private readonly string _responsePath;
    private readonly string? _coreSourceDir;
    private readonly string? _effectSourceDir;
    private readonly LotRenderer _renderer;
    private readonly LiveController? _live;
    private readonly bool _usesMetal;
    private readonly string _augmentedPath;

    private readonly CancellationTokenSource _cts = new();
    private readonly ManualResetEventSlim _wake = new(false);
    private readonly ConcurrentQueue<ReloadJob> _jobs = new();
    private readonly ConcurrentQueue<CompiledBatch> _completed = new();
    private readonly Thread _worker;

    private readonly Dictionary<string, FileStamp> _coreCommitted = new(StringComparer.Ordinal);
    private readonly Dictionary<string, FileStamp> _effectCommitted = new(StringComparer.Ordinal);
    private readonly Dictionary<string, (FileStamp Stamp, long ObservedAtTicks)> _pendingDebounce = new(StringComparer.Ordinal);
    private readonly Dictionary<string, string> _activeCoreFiles = new(StringComparer.Ordinal);
    private readonly Dictionary<string, string> _activeEffectFiles = new(StringComparer.Ordinal);

    private long _generation;
    private long _revision;
    private long _lastCommandPollTicks;
    private (int? House, bool ShowsLot, int EffectCount, int AmbientDebug) _lastPublishedState;
    private DateTimeOffset? _lastReloadUtc;
    private List<string> _lastReloaded = [];
    private Dictionary<string, string> _lastErrors = new(StringComparer.Ordinal);
    private bool _lastOk = true;
    private LiveCaptureRequest? _activeCapture;
    private bool _disposed;

    public ShaderHotReloader(string workspace, string dataRoot, LotRenderer renderer, LiveController? live = null)
    {
        _workspace = workspace;
        _renderer = renderer;
        _live = live;
        _usesMetal = renderer.GPU.UsesMetalShaders;
        _augmentedPath = BuildAugmentedPath();

        string coreDir = Path.Combine(workspace, "native", "SimsSDL", "Shaders", "sdl");
        string effectDir = Path.Combine(workspace, "expansions", "seasons", "shaders");
        _coreSourceDir = Directory.Exists(coreDir) ? coreDir : null;
        _effectSourceDir = Directory.Exists(effectDir) ? effectDir : null;

        _stagingRoot = Path.Combine(dataRoot, "shader-hotreload", $"pid-{Environment.ProcessId}");
        _coreStagingDir = Path.Combine(_stagingRoot, "core");
        _effectStagingDir = Path.Combine(_stagingRoot, "effect");
        Directory.CreateDirectory(_coreStagingDir);
        Directory.CreateDirectory(_effectStagingDir);

        string? customLiveDevDir = Environment.GetEnvironmentVariable("SIMS_LIVE_DEV_DIR");
        _liveDevDir = !string.IsNullOrWhiteSpace(customLiveDevDir)
            ? Path.GetFullPath(customLiveDevDir)
            : Path.Combine(workspace, "logs", "live-dev");
        Directory.CreateDirectory(_liveDevDir);
        _statusPath = Path.Combine(_liveDevDir, "status.json");
        _commandPath = Path.Combine(_liveDevDir, "command.json");
        _responsePath = Path.Combine(_liveDevDir, "response.json");

        CaptureDirectoryStamps(_coreSourceDir, _coreCommitted);
        CaptureDirectoryStamps(_effectSourceDir, _effectCommitted);

        _lastPublishedState = CurrentPublishedState();
        WriteStatusFile(active: true);

        _worker = new Thread(WorkerLoop)
        {
            Name = "ShaderHotReloader",
            IsBackground = true,
            Priority = ThreadPriority.BelowNormal,
        };
        _worker.Start();

        AppLog.Info(FormattableString.Invariant(
            $"Shader hot-reload active (core={_coreSourceDir ?? "none"}, effect={_effectSourceDir ?? "none"}, liveDev={_liveDevDir})."));
    }

    public void TriggerManualReload(bool forceAll = false)
    {
        if (_disposed)
            return;
        _jobs.Enqueue(new ReloadJob(CommandId: null, ForceAll: forceAll, RequestedShaders: null, ChainedShotPath: null, ChainedShotHideUi: false));
        _wake.Set();
    }

    public void TickMainThread(Action waitForGpuIdle, bool swapchainActive, out LiveCaptureRequest? captureRequest)
    {
        captureRequest = null;
        if (_disposed)
            return;

        while (_completed.TryDequeue(out CompiledBatch? batch))
        {
            ApplyCompiledBatch(batch, waitForGpuIdle, swapchainActive, ref captureRequest);
        }

        long now = Stopwatch.GetTimestamp();
        if (Stopwatch.GetElapsedTime(_lastCommandPollTicks, now).TotalMilliseconds >= 40.0)
        {
            _lastCommandPollTicks = now;
            var state = CurrentPublishedState();
            if (state != _lastPublishedState)
            {
                _lastPublishedState = state;
                WriteStatusFile(active: true);
            }
            PollLiveCommand(waitForGpuIdle, swapchainActive, ref captureRequest);
        }

        if (_activeCapture is { } pending && captureRequest is null)
        {
            if (!swapchainActive)
            {
                _activeCapture = null;
                WriteCommandResponse(pending.Id, ok: false, error: "Window is minimized or swapchain inactive.");
            }
            else
            {
                captureRequest = pending;
            }
        }
    }

    public void CompletePendingCapture(GPUTexture target)
    {
        if (_activeCapture is not { } req)
            return;
        _activeCapture = null;

        try
        {
            string fullPath = Path.IsPathRooted(req.OutputPath)
                ? req.OutputPath
                : Path.GetFullPath(Path.Combine(_workspace, req.OutputPath));
            string? dir = Path.GetDirectoryName(fullPath);
            if (!string.IsNullOrEmpty(dir))
                Directory.CreateDirectory(dir);

            byte[] rgba = _renderer.GPU.ReadPixels(target);
            byte[] png = PNGEncoder.Encode(rgba, target.Width, target.Height);
            WriteBytesAtomic(fullPath, png);

            WriteCommandResponse(
                req.Id,
                ok: true,
                extra: new Dictionary<string, object?>
                {
                    ["path"] = fullPath,
                    ["width"] = target.Width,
                    ["height"] = target.Height,
                    ["hideUi"] = req.HideUi,
                    ["revision"] = _revision,
                    ["reloaded"] = req.ReloadSummary?.Reloaded ?? _lastReloaded,
                    ["elapsedMs"] = req.ReloadSummary?.ElapsedMs ?? 0L,
                });
        }
        catch (Exception ex)
        {
            AppLog.Warn($"Live capture failed ({req.OutputPath}): {ex.Message}");
            WriteCommandResponse(req.Id, ok: false, error: ex.Message);
        }
    }

    private void ApplyCompiledBatch(
        CompiledBatch batch,
        Action waitForGpuIdle,
        bool swapchainActive,
        ref LiveCaptureRequest? captureRequest)
    {
        if (batch.NothingChanged && batch.Errors.Count == 0)
        {
            if (batch.CommandId is { } cmdId)
            {
                if (batch.ChainedShotPath is { } shotPath)
                {
                    if (_lastErrors.Count > 0)
                    {
                        WriteCommandResponse(
                            cmdId,
                            ok: false,
                            error: "Last shader reload failed; fix shader errors before capturing.",
                            extra: new Dictionary<string, object?>
                            {
                                ["revision"] = _revision,
                                ["errors"] = _lastErrors,
                            });
                    }
                    else
                    {
                        QueueOrFailCapture(cmdId, shotPath, batch.ChainedShotHideUi, swapchainActive,
                            new CompiledSwapSummary(_revision, true, [], new Dictionary<string, string>(StringComparer.Ordinal), batch.ElapsedMs),
                            ref captureRequest);
                    }
                }
                else
                {
                    WriteCommandResponse(
                        cmdId,
                        ok: _lastErrors.Count == 0,
                        error: _lastErrors.Count > 0 ? "Previous shader errors remain." : null,
                        extra: new Dictionary<string, object?>
                        {
                            ["revision"] = _revision,
                            ["reloaded"] = Array.Empty<string>(),
                            ["errors"] = _lastErrors,
                            ["elapsedMs"] = batch.ElapsedMs,
                            ["unchanged"] = true,
                        });
                }
            }
            return;
        }

        var errors = new Dictionary<string, string>(batch.Errors, StringComparer.Ordinal);
        bool gpuSwapOk = true;
        List<string> staleFilesToDelete = [];

        if (batch.CoreOutputs.Count > 0 || batch.EffectOutputs.Count > 0)
        {
            if (_renderer.GPU.TryHotReloadShaders(batch.CoreOutputs, batch.EffectOutputs, waitForGpuIdle, out string? gpuError))
            {
                _renderer.InvalidateShaderCaches();
                foreach (var (name, newBase) in batch.CoreOutputs)
                {
                    if (_activeCoreFiles.TryGetValue(name, out string? oldBase) && !string.Equals(oldBase, newBase, StringComparison.Ordinal))
                        staleFilesToDelete.Add(oldBase);
                    _activeCoreFiles[name] = newBase;
                }
                foreach (var (name, newBase) in batch.EffectOutputs)
                {
                    if (_activeEffectFiles.TryGetValue(name, out string? oldBase) && !string.Equals(oldBase, newBase, StringComparison.Ordinal))
                        staleFilesToDelete.Add(oldBase);
                    _activeEffectFiles[name] = newBase;
                }
            }
            else
            {
                gpuSwapOk = false;
                errors["gpu"] = gpuError ?? "SDL GPU pipeline creation failed";
                foreach (string failedBase in batch.CoreOutputs.Values)
                    staleFilesToDelete.Add(failedBase);
                foreach (string failedBase in batch.EffectOutputs.Values)
                    staleFilesToDelete.Add(failedBase);
            }
        }

        foreach (string basePath in staleFilesToDelete)
            DeleteCompiledBaseFiles(basePath);

        _revision++;
        _lastReloadUtc = DateTimeOffset.UtcNow;
        _lastErrors = errors;
        _lastReloaded = gpuSwapOk ? batch.ReloadedLabels : [];
        _lastOk = gpuSwapOk && errors.Count == 0;

        if (_lastOk)
        {
            string summary = FormattableString.Invariant(
                $"Shader hot-reload #{_revision} OK ({batch.ElapsedMs}ms): {string.Join(", ", _lastReloaded)}");
            AppLog.Info(summary);
            Console.Error.WriteLine(summary);
        }
        else
        {
            string errDetail = string.Join(" | ", errors.Select(static kv => $"{kv.Key}: {kv.Value}"));
            string summary = FormattableString.Invariant(
                $"Shader hot-reload #{_revision} FAILED ({batch.ElapsedMs}ms): {errDetail}");
            AppLog.Warn(summary);
            Console.Error.WriteLine(summary);
        }

        WriteStatusFile(active: true);

        if (batch.CommandId is { } id)
        {
            var swapSummary = new CompiledSwapSummary(_revision, _lastOk, _lastReloaded, errors, batch.ElapsedMs);
            if (batch.ChainedShotPath is { } shotPath)
            {
                if (!_lastOk)
                {
                    WriteCommandResponse(
                        id,
                        ok: false,
                        error: "Shader reload failed.",
                        extra: new Dictionary<string, object?>
                        {
                            ["revision"] = _revision,
                            ["reloaded"] = _lastReloaded,
                            ["errors"] = errors,
                            ["elapsedMs"] = batch.ElapsedMs,
                        });
                }
                else
                {
                    QueueOrFailCapture(id, shotPath, batch.ChainedShotHideUi, swapchainActive, swapSummary, ref captureRequest);
                }
            }
            else
            {
                WriteCommandResponse(
                    id,
                    ok: _lastOk,
                    error: _lastOk ? null : "Shader reload failed.",
                    extra: new Dictionary<string, object?>
                    {
                        ["revision"] = _revision,
                        ["reloaded"] = _lastReloaded,
                        ["errors"] = errors,
                        ["elapsedMs"] = batch.ElapsedMs,
                    });
            }
        }
    }

    private void QueueOrFailCapture(
        string id,
        string shotPath,
        bool hideUi,
        bool swapchainActive,
        CompiledSwapSummary? summary,
        ref LiveCaptureRequest? captureRequest)
    {
        if (!swapchainActive)
        {
            WriteCommandResponse(id, ok: false, error: "Window is minimized or swapchain inactive.");
            return;
        }

        var req = new LiveCaptureRequest(id, shotPath, hideUi, summary);
        _activeCapture = req;
        captureRequest = req;
    }

    private void PollLiveCommand(Action waitForGpuIdle, bool swapchainActive, ref LiveCaptureRequest? captureRequest)
    {
        if (!File.Exists(_commandPath))
            return;

        string json;
        try
        {
            json = File.ReadAllText(_commandPath, Encoding.UTF8);
        }
        catch (IOException)
        {
            return;
        }
        catch (UnauthorizedAccessException)
        {
            return;
        }

        LiveCommandPayload? payload;
        try
        {
            payload = JsonSerializer.Deserialize<LiveCommandPayload>(json, JsonReadOptions);
        }
        catch (Exception ex)
        {
            TryDeleteFile(_commandPath);
            WriteCommandResponse("invalid", ok: false, error: $"Invalid command JSON: {ex.Message}");
            return;
        }

        if (payload?.TargetPid is int targetPid && targetPid != Environment.ProcessId)
            return;

        try
        {
            File.Delete(_commandPath);
        }
        catch (IOException)
        {
            return;
        }
        catch (UnauthorizedAccessException)
        {
            return;
        }

        if (payload is null || string.IsNullOrWhiteSpace(payload.Action))
        {
            WriteCommandResponse(payload?.Id ?? "invalid", ok: false, error: "Command missing 'action'.");
            return;
        }

        string id = string.IsNullOrWhiteSpace(payload.Id) ? Guid.NewGuid().ToString("N") : payload.Id;
        switch (payload.Action.ToLowerInvariant())
        {
            case "status":
                WriteStatusFile(active: true);
                WriteCommandResponse(id, ok: true, extra: BuildStatusObject(active: true));
                break;

            case "reload":
                _jobs.Enqueue(new ReloadJob(id, payload.Force, payload.Shaders, ChainedShotPath: null, ChainedShotHideUi: false));
                _wake.Set();
                break;

            case "shot":
                string shotPath = string.IsNullOrWhiteSpace(payload.Path)
                    ? Path.Combine(_liveDevDir, "shot.png")
                    : payload.Path;
                QueueOrFailCapture(id, shotPath, payload.HideUi, swapchainActive, summary: null, ref captureRequest);
                break;

            case "test_shader":
                string testShotPath = string.IsNullOrWhiteSpace(payload.Path)
                    ? Path.Combine(_liveDevDir, "shot.png")
                    : payload.Path;
                _jobs.Enqueue(new ReloadJob(id, payload.Force, payload.Shaders, testShotPath, payload.HideUi));
                _wake.Set();
                break;

            case "ambient_debug":
                _renderer.AmbientDebug = payload.Mode;
                _renderer.InvalidateShaderCaches();
                WriteStatusFile(active: true);
                WriteCommandResponse(id, ok: true, extra: new Dictionary<string, object?>
                {
                    ["ambientDebug"] = _renderer.AmbientDebug,
                });
                break;

            case "set_sun":
                if (payload.Clear)
                {
                    _renderer.SunOverride = null;
                }
                else
                {
                    float azRad = (payload.Azimuth ?? 45f) * (MathF.PI / 180f);
                    float elRad = Math.Clamp(payload.Elevation ?? 35f, 5f, 88f) * (MathF.PI / 180f);
                    float cosEl = MathF.Cos(elRad);
                    _renderer.SunOverride = new System.Numerics.Vector3(MathF.Sin(elRad), cosEl * MathF.Sin(azRad), cosEl * MathF.Cos(azRad));
                }
                _renderer.InvalidateShaderCaches();
                WriteCommandResponse(id, ok: true);
                break;

            case "reset":
                if (_renderer.GPU.ResetHotShaders(waitForGpuIdle, out string? resetError))
                {
                    _renderer.InvalidateShaderCaches();
                    foreach (string basePath in _activeCoreFiles.Values)
                        DeleteCompiledBaseFiles(basePath);
                    foreach (string basePath in _activeEffectFiles.Values)
                        DeleteCompiledBaseFiles(basePath);
                    _activeCoreFiles.Clear();
                    _activeEffectFiles.Clear();
                    _revision++;
                    _lastReloadUtc = DateTimeOffset.UtcNow;
                    _lastReloaded = [];
                    _lastErrors = new Dictionary<string, string>(StringComparer.Ordinal);
                    _lastOk = true;
                    WriteStatusFile(active: true);
                    WriteCommandResponse(id, ok: true, extra: new Dictionary<string, object?>
                    {
                        ["revision"] = _revision,
                    });
                }
                else
                {
                    WriteCommandResponse(id, ok: false, error: resetError ?? "Reset failed.");
                }
                break;

            default:
                WriteCommandResponse(id, ok: false, error: $"Unknown live-dev action '{payload.Action}'.");
                break;
        }
    }

    private void WorkerLoop()
    {
        CancellationToken ct = _cts.Token;
        while (!ct.IsCancellationRequested)
        {
            try
            {
                while (_jobs.TryDequeue(out ReloadJob? job))
                {
                    ProcessExplicitJob(job);
                }

                PollWatchedChanges();
            }
            catch (Exception ex) when (!ct.IsCancellationRequested)
            {
                AppLog.Warn($"ShaderHotReloader worker error: {ex.Message}");
            }

            _wake.Reset();
            try
            {
                _wake.Wait(200, ct);
            }
            catch (OperationCanceledException)
            {
                break;
            }
        }
    }

    private void ProcessExplicitJob(ReloadJob job)
    {
        var sw = Stopwatch.StartNew();
        var coreTargets = new HashSet<string>(StringComparer.Ordinal);
        var effectTargets = new HashSet<string>(StringComparer.Ordinal);

        if (job.RequestedShaders is { Length: > 0 } requested)
        {
            foreach (string raw in requested)
            {
                string trimmed = raw.Trim();
                if (string.IsNullOrEmpty(trimmed))
                    continue;
                if (trimmed.StartsWith("core:", StringComparison.OrdinalIgnoreCase))
                {
                    AddTargetsForEntry(_coreSourceDir, trimmed[5..], coreTargets);
                }
                else if (trimmed.StartsWith("effect:", StringComparison.OrdinalIgnoreCase))
                {
                    AddTargetsForEntry(_effectSourceDir, trimmed[7..], effectTargets);
                }
                else
                {
                    string fileName = Path.GetFileName(trimmed);
                    bool matched = false;
                    if (_coreSourceDir is not null && File.Exists(Path.Combine(_coreSourceDir, fileName)))
                    {
                        AddTargetsForEntry(_coreSourceDir, fileName, coreTargets);
                        matched = true;
                    }
                    if (_effectSourceDir is not null && File.Exists(Path.Combine(_effectSourceDir, fileName)))
                    {
                        AddTargetsForEntry(_effectSourceDir, fileName, effectTargets);
                        matched = true;
                    }
                    if (!matched)
                    {
                        coreTargets.Add(fileName);
                    }
                }
            }
        }
        else if (job.ForceAll)
        {
            CollectAllCompilableShaders(_coreSourceDir, coreTargets);
            CollectAllCompilableShaders(_effectSourceDir, effectTargets);
        }
        else
        {
            CollectDirtyShadersImmediate(_coreSourceDir, _coreCommitted, coreTargets);
            CollectDirtyShadersImmediate(_effectSourceDir, _effectCommitted, effectTargets);
        }

        if (coreTargets.Count == 0 && effectTargets.Count == 0)
        {
            sw.Stop();
            _completed.Enqueue(new CompiledBatch(
                job.CommandId,
                new Dictionary<string, string>(StringComparer.Ordinal),
                new Dictionary<string, string>(StringComparer.Ordinal),
                [],
                new Dictionary<string, string>(StringComparer.Ordinal),
                sw.ElapsedMilliseconds,
                job.ChainedShotPath,
                job.ChainedShotHideUi,
                NothingChanged: true));
            return;
        }

        CaptureDirectoryStamps(_coreSourceDir, _coreCommitted);
        CaptureDirectoryStamps(_effectSourceDir, _effectCommitted);
        _pendingDebounce.Clear();

        CompileAndEnqueue(job.CommandId, coreTargets, effectTargets, sw, job.ChainedShotPath, job.ChainedShotHideUi);
    }

    private void PollWatchedChanges()
    {
        long now = Stopwatch.GetTimestamp();
        var coreReady = CollectDebouncedChanges(_coreSourceDir, _coreCommitted, "core", now);
        var effectReady = CollectDebouncedChanges(_effectSourceDir, _effectCommitted, "effect", now);
        if (coreReady.Count == 0 && effectReady.Count == 0)
            return;

        var sw = Stopwatch.StartNew();
        var coreTargets = _coreSourceDir is not null && coreReady.Count > 0
            ? ResolveAffectedShaders(_coreSourceDir, coreReady)
            : [];
        var effectTargets = _effectSourceDir is not null && effectReady.Count > 0
            ? ResolveAffectedShaders(_effectSourceDir, effectReady)
            : [];

        if (coreTargets.Count == 0 && effectTargets.Count == 0)
            return;

        CompileAndEnqueue(
            commandId: null,
            new HashSet<string>(coreTargets, StringComparer.Ordinal),
            new HashSet<string>(effectTargets, StringComparer.Ordinal),
            sw,
            chainedShotPath: null,
            chainedShotHideUi: false);
    }

    private HashSet<string> CollectDebouncedChanges(
        string? dir,
        Dictionary<string, FileStamp> committed,
        string bucketPrefix,
        long nowTicks)
    {
        var ready = new HashSet<string>(StringComparer.Ordinal);
        if (dir is null || !Directory.Exists(dir))
            return ready;

        var current = new Dictionary<string, FileStamp>(StringComparer.Ordinal);
        CaptureDirectoryStamps(dir, current);

        foreach (var (name, stamp) in current)
        {
            string debounceKey = bucketPrefix + ":" + name;
            if (committed.TryGetValue(name, out FileStamp oldStamp) && oldStamp == stamp)
            {
                _pendingDebounce.Remove(debounceKey);
                continue;
            }

            if (_pendingDebounce.TryGetValue(debounceKey, out var pending))
            {
                if (pending.Stamp != stamp)
                {
                    _pendingDebounce[debounceKey] = (stamp, nowTicks);
                }
                else if (Stopwatch.GetElapsedTime(pending.ObservedAtTicks, nowTicks).TotalMilliseconds >= 80.0)
                {
                    ready.Add(name);
                    committed[name] = stamp;
                    _pendingDebounce.Remove(debounceKey);
                }
            }
            else
            {
                _pendingDebounce[debounceKey] = (stamp, nowTicks);
            }
        }

        return ready;
    }

    private void CompileAndEnqueue(
        string? commandId,
        HashSet<string> coreTargets,
        HashSet<string> effectTargets,
        Stopwatch sw,
        string? chainedShotPath,
        bool chainedShotHideUi)
    {
        var coreOutputs = new Dictionary<string, string>(StringComparer.Ordinal);
        var effectOutputs = new Dictionary<string, string>(StringComparer.Ordinal);
        var reloadedLabels = new List<string>();
        var errors = new Dictionary<string, string>(StringComparer.Ordinal);

        if (_coreSourceDir is not null)
        {
            foreach (string name in coreTargets.OrderBy(static s => s, StringComparer.Ordinal))
            {
                if (TryCompileShader(_coreSourceDir, _coreStagingDir, name, out string? basePath, out string? error))
                {
                    coreOutputs[name] = basePath!;
                    reloadedLabels.Add("core:" + name);
                }
                else
                {
                    errors["core:" + name] = error ?? "Shader compilation failed";
                }
            }
        }

        if (_effectSourceDir is not null)
        {
            foreach (string name in effectTargets.OrderBy(static s => s, StringComparer.Ordinal))
            {
                if (TryCompileShader(_effectSourceDir, _effectStagingDir, name, out string? basePath, out string? error))
                {
                    effectOutputs[name] = basePath!;
                    reloadedLabels.Add("effect:" + name);
                }
                else
                {
                    errors["effect:" + name] = error ?? "Shader compilation failed";
                }
            }
        }

        sw.Stop();
        _completed.Enqueue(new CompiledBatch(
            commandId,
            coreOutputs,
            effectOutputs,
            reloadedLabels,
            errors,
            sw.ElapsedMilliseconds,
            chainedShotPath,
            chainedShotHideUi,
            NothingChanged: false));
    }

    private bool TryCompileShader(
        string sourceDir,
        string outputDir,
        string shaderName,
        out string? compiledBasePath,
        out string? error)
    {
        compiledBasePath = null;
        string sourcePath = Path.Combine(sourceDir, shaderName);
        if (!File.Exists(sourcePath))
        {
            error = $"Shader source not found: {sourcePath}";
            return false;
        }

        long gen = Interlocked.Increment(ref _generation);
        string basePath = Path.Combine(outputDir, $"{shaderName}.r{gen}");
        string spvPath = basePath + ".spv";
        string mslPath = basePath + ".msl";

        try
        {
            (int glslExit, string glslOut, string glslErr) = RunTool(
                "glslangValidator",
                ["-V", "--quiet", $"-I{sourceDir}", "-o", spvPath, sourcePath]);
            if (glslExit != 0 || !File.Exists(spvPath))
            {
                error = CombineToolOutput(glslOut, glslErr, $"glslangValidator exited with code {glslExit}");
                DeleteCompiledBaseFiles(basePath);
                return false;
            }

            if (_usesMetal)
            {
                (int reflectExit, string reflectOut, string reflectErr) = RunTool(
                    "spirv-cross",
                    [spvPath, "--reflect"]);
                if (reflectExit != 0)
                {
                    error = CombineToolOutput(reflectOut, reflectErr, $"spirv-cross --reflect exited with code {reflectExit}");
                    DeleteCompiledBaseFiles(basePath);
                    return false;
                }

                ReflectionInfo reflection = ParseReflection(reflectOut);
                List<string> mslArgs = [spvPath, "--msl", "--msl-version", "20100"];
                if (!reflection.HasSsbos)
                    mslArgs.Add("--msl-decoration-binding");

                (int mslExit, string mslOut, string mslErr) = RunTool("spirv-cross", mslArgs);
                if (mslExit != 0)
                {
                    error = CombineToolOutput(mslOut, mslErr, $"spirv-cross --msl exited with code {mslExit}");
                    DeleteCompiledBaseFiles(basePath);
                    return false;
                }

                string normalizedMsl = NormalizeMslOutput(mslOut);
                List<string> problems = ValidateMetalBindings(shaderName, reflection, normalizedMsl);
                if (problems.Count > 0)
                {
                    error = string.Join("; ", problems);
                    DeleteCompiledBaseFiles(basePath);
                    return false;
                }

                WriteTextAtomic(mslPath, normalizedMsl);
            }

            compiledBasePath = basePath;
            error = null;
            return true;
        }
        catch (Exception ex)
        {
            DeleteCompiledBaseFiles(basePath);
            error = ex.Message;
            return false;
        }
    }

    internal readonly record struct TextureBinding(string Name, int Binding);

    internal sealed record ReflectionInfo(
        bool HasSsbos,
        bool HasQuadUbo,
        List<TextureBinding> Textures);

    internal static ReflectionInfo ParseReflection(string reflectionJson)
    {
        using var doc = JsonDocument.Parse(reflectionJson);
        JsonElement root = doc.RootElement;

        bool hasSsbos = root.TryGetProperty("ssbos", out JsonElement ssbos)
            && ssbos.ValueKind == JsonValueKind.Array
            && ssbos.GetArrayLength() > 0;

        bool hasQuadUbo = false;
        if (root.TryGetProperty("ubos", out JsonElement ubos) && ubos.ValueKind == JsonValueKind.Array)
        {
            foreach (JsonElement ubo in ubos.EnumerateArray())
            {
                if (ubo.TryGetProperty("name", out JsonElement nameEl)
                    && string.Equals(nameEl.GetString(), "Quad", StringComparison.Ordinal))
                {
                    hasQuadUbo = true;
                    break;
                }
            }
        }

        var textures = new List<TextureBinding>();
        if (root.TryGetProperty("textures", out JsonElement texArray) && texArray.ValueKind == JsonValueKind.Array)
        {
            foreach (JsonElement tex in texArray.EnumerateArray())
            {
                string? name = tex.TryGetProperty("name", out JsonElement n) ? n.GetString() : null;
                int binding = tex.TryGetProperty("binding", out JsonElement b) && b.TryGetInt32(out int idx) ? idx : -1;
                if (!string.IsNullOrEmpty(name) && binding >= 0)
                    textures.Add(new TextureBinding(name, binding));
            }
        }

        return new ReflectionInfo(hasSsbos, hasQuadUbo, textures);
    }

    internal static List<string> ValidateMetalBindings(string shaderName, ReflectionInfo reflection, string mslOutput)
    {
        var problems = new List<string>();
        foreach (TextureBinding tex in reflection.Textures)
        {
            CheckSlot(tex.Name, "texture", tex.Binding);
            CheckSlot(tex.Name + "Smplr", "sampler", tex.Binding);
        }

        if (shaderName.EndsWith(".vert", StringComparison.Ordinal) && reflection.HasQuadUbo)
        {
            if (!Regex.IsMatch(mslOutput, @"constant Quad& quad \[\[buffer\(0\)\]\]"))
                problems.Add($"{shaderName}: expected constant Quad& quad [[buffer(0)]]");
            if (reflection.HasSsbos && !Regex.IsMatch(mslOutput, @"const device Vertices& \w+ \[\[buffer\(1\)\]\]"))
                problems.Add($"{shaderName}: expected const device Vertices& <name> [[buffer(1)]]");
        }

        return problems;

        void CheckSlot(string variable, string kind, int expected)
        {
            Match match = Regex.Match(mslOutput, @"\b" + Regex.Escape(variable) + @"\s*\[\[" + kind + @"\((\d+)\)\]\]");
            int? actual = match.Success ? int.Parse(match.Groups[1].Value, CultureInfo.InvariantCulture) : null;
            if (actual != expected)
                problems.Add($"{shaderName}: {variable} {kind} slot {actual?.ToString(CultureInfo.InvariantCulture) ?? "missing"}, expected {expected}");
        }
    }

    internal static List<string> ResolveAffectedShaders(string sourceDir, IEnumerable<string> changedFileNames)
    {
        var changed = new HashSet<string>(changedFileNames, StringComparer.Ordinal);
        if (changed.Count == 0 || !Directory.Exists(sourceDir))
            return [];

        var allFiles = Directory.EnumerateFiles(sourceDir)
            .Select(Path.GetFileName)
            .Where(static n => !string.IsNullOrEmpty(n) && IsWatchedShaderFile(n!))
            .Select(static n => n!)
            .ToList();

        var includeDependents = new Dictionary<string, List<string>>(StringComparer.Ordinal);
        foreach (string file in allFiles)
        {
            string fullPath = Path.Combine(sourceDir, file);
            string text;
            try
            {
                text = File.ReadAllText(fullPath, Encoding.UTF8);
            }
            catch
            {
                continue;
            }

            foreach (Match m in IncludeDirectiveRegex().Matches(text))
            {
                string inc = Path.GetFileName(m.Groups[1].Value);
                if (!includeDependents.TryGetValue(inc, out List<string>? list))
                {
                    list = [];
                    includeDependents[inc] = list;
                }
                list.Add(file);
            }
        }

        var affectedFiles = new HashSet<string>(changed, StringComparer.Ordinal);
        var queue = new Queue<string>(changed);
        while (queue.Count > 0)
        {
            string current = queue.Dequeue();
            if (!includeDependents.TryGetValue(current, out List<string>? dependents))
                continue;
            foreach (string dep in dependents)
            {
                if (affectedFiles.Add(dep))
                    queue.Enqueue(dep);
            }
        }

        return affectedFiles
            .Where(IsCompilableShaderFile)
            .OrderBy(static s => s, StringComparer.Ordinal)
            .ToList();
    }

    private static void AddTargetsForEntry(string? sourceDir, string entry, HashSet<string> targets)
    {
        if (sourceDir is null)
            return;
        string fileName = Path.GetFileName(entry);
        if (IsCompilableShaderFile(fileName))
        {
            targets.Add(fileName);
        }
        else if (fileName.EndsWith(".glsl", StringComparison.OrdinalIgnoreCase))
        {
            foreach (string resolved in ResolveAffectedShaders(sourceDir, [fileName]))
                targets.Add(resolved);
        }
    }

    private static void CollectAllCompilableShaders(string? sourceDir, HashSet<string> targets)
    {
        if (sourceDir is null || !Directory.Exists(sourceDir))
            return;
        foreach (string path in Directory.EnumerateFiles(sourceDir))
        {
            string name = Path.GetFileName(path);
            if (IsCompilableShaderFile(name))
                targets.Add(name);
        }
    }

    private static void CollectDirtyShadersImmediate(
        string? sourceDir,
        Dictionary<string, FileStamp> committed,
        HashSet<string> targets)
    {
        if (sourceDir is null || !Directory.Exists(sourceDir))
            return;
        var current = new Dictionary<string, FileStamp>(StringComparer.Ordinal);
        CaptureDirectoryStamps(sourceDir, current);
        var changed = new List<string>();
        foreach (var (name, stamp) in current)
        {
            if (!committed.TryGetValue(name, out FileStamp oldStamp) || oldStamp != stamp)
                changed.Add(name);
        }
        foreach (string affected in ResolveAffectedShaders(sourceDir, changed))
            targets.Add(affected);
    }

    private static void CaptureDirectoryStamps(string? sourceDir, Dictionary<string, FileStamp> target)
    {
        target.Clear();
        if (sourceDir is null || !Directory.Exists(sourceDir))
            return;
        foreach (string path in Directory.EnumerateFiles(sourceDir))
        {
            string name = Path.GetFileName(path);
            if (!IsWatchedShaderFile(name))
                continue;
            try
            {
                var info = new FileInfo(path);
                target[name] = new FileStamp(info.LastWriteTimeUtc.Ticks, info.Length);
            }
            catch
            {
            }
        }
    }

    private static bool IsWatchedShaderFile(string name) =>
        name.EndsWith(".vert", StringComparison.OrdinalIgnoreCase)
        || name.EndsWith(".frag", StringComparison.OrdinalIgnoreCase)
        || name.EndsWith(".glsl", StringComparison.OrdinalIgnoreCase);

    private static bool IsCompilableShaderFile(string name) =>
        name.EndsWith(".vert", StringComparison.OrdinalIgnoreCase)
        || name.EndsWith(".frag", StringComparison.OrdinalIgnoreCase);

    private static string NormalizeMslOutput(string msl)
    {
        string[] lines = msl.Replace("\r\n", "\n", StringComparison.Ordinal).Split('\n');
        var sb = new StringBuilder(msl.Length);
        for (int i = 0; i < lines.Length; i++)
        {
            if (i > 0)
                sb.Append('\n');
            sb.Append(lines[i].TrimEnd());
        }
        return sb.ToString().TrimEnd() + "\n";
    }

    private (int ExitCode, string Stdout, string Stderr) RunTool(string fileName, IReadOnlyList<string> args)
    {
        var psi = new ProcessStartInfo
        {
            FileName = ResolveToolPath(fileName),
            UseShellExecute = false,
            RedirectStandardOutput = true,
            RedirectStandardError = true,
            CreateNoWindow = true,
        };
        psi.Environment["PATH"] = _augmentedPath;
        foreach (string arg in args)
            psi.ArgumentList.Add(arg);

        using Process process = Process.Start(psi)
            ?? throw new InvalidOperationException($"Failed to launch '{fileName}'");
        Task<string> stdoutTask = process.StandardOutput.ReadToEndAsync();
        Task<string> stderrTask = process.StandardError.ReadToEndAsync();
        if (!process.WaitForExit(30_000))
        {
            try
            {
                process.Kill(entireProcessTree: true);
            }
            catch
            {
            }
            throw new TimeoutException($"Timed out waiting for '{fileName}'");
        }

        return (process.ExitCode, stdoutTask.GetAwaiter().GetResult(), stderrTask.GetAwaiter().GetResult());
    }

    private string ResolveToolPath(string fileName)
    {
        foreach (string dir in _augmentedPath.Split(Path.PathSeparator, StringSplitOptions.RemoveEmptyEntries))
        {
            string candidate = Path.Combine(dir, fileName);
            if (File.Exists(candidate))
                return candidate;
            if (OperatingSystem.IsWindows())
            {
                string exeCandidate = candidate + ".exe";
                if (File.Exists(exeCandidate))
                    return exeCandidate;
            }
        }
        return fileName;
    }

    private static string BuildAugmentedPath()
    {
        string existing = Environment.GetEnvironmentVariable("PATH") ?? string.Empty;
        if (OperatingSystem.IsWindows())
            return existing;
        string[] extras = ["/opt/homebrew/bin", "/usr/local/bin"];
        var parts = new List<string>(extras.Length + 1);
        foreach (string extra in extras)
        {
            if (Directory.Exists(extra))
                parts.Add(extra);
        }
        if (!string.IsNullOrEmpty(existing))
            parts.Add(existing);
        return string.Join(Path.PathSeparator, parts);
    }

    private static string CombineToolOutput(string stdout, string stderr, string fallback)
    {
        string combined = string.Join("\n", new[] { stderr.Trim(), stdout.Trim() }.Where(static s => s.Length > 0));
        return string.IsNullOrEmpty(combined) ? fallback : combined;
    }

    private (int? House, bool ShowsLot, int EffectCount, int AmbientDebug) CurrentPublishedState() =>
        (_renderer.Scene?.House, _live is null || _live.Ui.ShowsLot, _renderer.GPU.EffectShaders.Count, _renderer.AmbientDebug);

    private Dictionary<string, object?> BuildStatusObject(bool active) => new()
    {
        ["pid"] = Environment.ProcessId,
        ["active"] = active,
        ["driver"] = _renderer.GPU.DriverName,
        ["revision"] = _revision,
        ["ok"] = _lastOk,
        ["lastReloadUtc"] = _lastReloadUtc?.ToString("O", CultureInfo.InvariantCulture),
        ["reloaded"] = _lastReloaded,
        ["errors"] = _lastErrors,
        ["coreSourceDir"] = _coreSourceDir,
        ["effectSourceDir"] = _effectSourceDir,
        ["coreOverrides"] = _renderer.GPU.HotCoreShaders.Keys.OrderBy(static k => k, StringComparer.Ordinal).ToArray(),
        ["effectOverrides"] = _renderer.GPU.HotEffectShaders.Keys.OrderBy(static k => k, StringComparer.Ordinal).ToArray(),
        ["activeEffectShaders"] = _renderer.GPU.EffectShaders.Keys.OrderBy(static k => k, StringComparer.Ordinal).ToArray(),
        ["ambientDebug"] = _renderer.AmbientDebug,
        ["house"] = _renderer.Scene?.House,
        ["zoom"] = _renderer.Zoom.ToString(),
        ["showsLot"] = _live is null || _live.Ui.ShowsLot,
    };

    private void WriteStatusFile(bool active)
    {
        try
        {
            string json = JsonSerializer.Serialize(BuildStatusObject(active), JsonOptions);
            WriteTextAtomic(_statusPath, json);
        }
        catch
        {
        }
    }

    private void WriteCommandResponse(
        string id,
        bool ok,
        string? error = null,
        Dictionary<string, object?>? extra = null)
    {
        try
        {
            var body = new Dictionary<string, object?>
            {
                ["id"] = id,
                ["ok"] = ok,
                ["pid"] = Environment.ProcessId,
                ["timestampUtc"] = DateTimeOffset.UtcNow.ToString("O", CultureInfo.InvariantCulture),
            };
            if (!string.IsNullOrEmpty(error))
                body["error"] = error;
            if (extra is not null)
            {
                foreach (var (k, v) in extra)
                    body[k] = v;
            }
            string json = JsonSerializer.Serialize(body, JsonOptions);
            WriteTextAtomic(_responsePath, json);
        }
        catch
        {
        }
    }

    private static void WriteTextAtomic(string path, string content) =>
        WriteBytesAtomic(path, Encoding.UTF8.GetBytes(content));

    private static void WriteBytesAtomic(string path, byte[] bytes)
    {
        string tmp = path + ".tmp." + Environment.ProcessId;
        File.WriteAllBytes(tmp, bytes);
        File.Move(tmp, path, overwrite: true);
    }

    private static void DeleteCompiledBaseFiles(string basePath)
    {
        TryDeleteFile(basePath + ".spv");
        TryDeleteFile(basePath + ".msl");
        TryDeleteFile(basePath + ".dxil");
    }

    private static void TryDeleteFile(string path)
    {
        try
        {
            if (File.Exists(path))
                File.Delete(path);
        }
        catch
        {
        }
    }

    [GeneratedRegex(@"^\s*#\s*include\s+""([^""]+)""", RegexOptions.Multiline)]
    private static partial Regex IncludeDirectiveRegex();

    public void Dispose()
    {
        if (_disposed)
            return;
        _disposed = true;
        _cts.Cancel();
        _wake.Set();
        try
        {
            _worker.Join(1500);
        }
        catch
        {
        }
        _cts.Dispose();
        _wake.Dispose();

        WriteStatusFile(active: false);
        try
        {
            if (Directory.Exists(_stagingRoot))
                Directory.Delete(_stagingRoot, recursive: true);
        }
        catch
        {
        }
    }
}
