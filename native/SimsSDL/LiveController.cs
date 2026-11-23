using System.Collections.Concurrent;
using System.Diagnostics;

namespace SimsSDL;

internal sealed partial class LiveController
{
    public SimulationBridge? Bridge { get; private set; }
    public GameContent Content { get; private set; }
    public string Workspace { get; }
    public LotRenderer Renderer { get; }
    public LiveUI Ui { get; private set; }
    internal Options Options { get; }
    private string? _safeModeBootError;
    private OriginalUIStrings Strings => Ui.Strings;
    public bool HasBlockingDialog => Ui.GameDialog?.Dialog.Blocking == true && Ui.GameDialog?.Submitting == false;
    private bool _tutorialLiveModeClicked;

    private sealed class MenuRequest
    {
        public required string Id { get; init; }
        public required int Object { get; init; }
        public required int Caller { get; init; }
        public required CGPoint Anchor { get; init; }
        public (GroundTile Tile, int Level)? Ground { get; set; }
    }

    private (GroundTile Tile, int Level)? _pieGround;

    private readonly record struct PlacementKey(
        BuySelection.SelectionTarget Target,
        GroundTile Tile,
        int Direction,
        long Revision,
        int Level,
        SimsSDL.Core.LotCamera Orientation,
        int? WallDirection = null);

    private readonly record struct WallStrokeMode(bool Rectangle, bool Deleting);

    private readonly record struct WallStrokeSegment(WallBrushSelection Selection, ushort Style, ushort Pattern);

    private sealed class WallStroke
    {
        public required LotVertex Start { get; set; }
        public required ushort Style { get; init; }
        public required ushort Pattern { get; init; }
        public required WallStrokeMode Mode { get; set; }
        public List<WallStrokeSegment> Completed { get; } = [];
    }

    private sealed class LotSimInfo
    {
        public required string TooltipName { get; init; }
        public required int Gender { get; init; }
        public required uint Guid { get; init; }
        public required bool HideHover { get; init; }
        public int FameScore { get; set; }
        public int JobType { get; set; }
        public float X { get; set; }
        public float Y { get; set; }
        public int Level { get; set; } = 1;
        public bool WinterClothes { get; set; }
        public bool OutfitChanging { get; set; }
    }

    private readonly record struct PlacedObjectMeta(
        float X,
        float Y,
        int Level,
        int BuildModeType,
        int ResaleValue,
        string CatalogName);

    private int _selectedSim;
    private bool _windowActive = true;
    private List<int> _simIDs = [];
    private Dictionary<int, LotSimInfo> _lotSims = new();
    private List<string> _simAnimations = [];
    public bool ScriptSimIdle { get; private set; }
    public bool? ScriptSimWinterClothes => _lotSims.TryGetValue(_selectedSim, out var sim) && !sim.OutfitChanging ? sim.WinterClothes : null;
    public List<string> ScriptSimActions { get; private set; } = [];
    private Dictionary<string, JsonElement>? _stateAwaitingScene;
    private bool _centresOnSelectedSim;
    private int? _edgeScrollRegionKey;
    private CGPoint? _rightOrigin;
    private CGPoint? _rightCurrent;
    private bool _rightScrolling;
    private double _edgeScrollStart;
    private double _edgeScrollClock;
    private MenuRequest? _pendingMenu;
    private CGPoint? _pendingPieMenuWarp;

    private readonly record struct PieHeadKey(OriginalPieOverlay Menu, int Sim, float Yaw, float Pitch);

    private PieHeadKey? _desiredPieHead;
    private PieHeadKey? _checkedPieHead;
    private (string Id, PieHeadKey Key)? _pendingPieHead;
    private string? _pendingGenericSimsCallPoll;
    private string? _pendingGenericSimsCallChoice;
    private double _lastGenericSimsCallPoll;
    private long? _activeGenericSimsCallRequest;
    private string? _pendingCatalog;
    private string? _pendingBuyCatalogViews;
    private string? _pendingBuildCatalog;
    private string? _pendingWallMode;
    private bool? _pendingRoofsVisible;
    private int? _pendingViewLevel;
    private int? _pendingCameraOrientation;
    private string? _pendingViewRequestID;
    private long? _pendingViewSceneRevision;
    private long _latestQueuedSceneRevision;
    private string EffectiveWallMode => _pendingWallMode ?? Ui.WallMode;
    private bool EffectiveRoofsVisible => _pendingRoofsVisible ?? Renderer.RoofsVisible;
    private int EffectiveViewLevel => _pendingViewLevel ?? Renderer.ViewLevel;

    private void ClearPendingViewState()
    {
        _pendingWallMode = null;
        _pendingRoofsVisible = null;
        _pendingViewLevel = null;
        _pendingCameraOrientation = null;
        _pendingViewRequestID = null;
        _pendingViewSceneRevision = null;
    }

    private (string Id, PlacementKey Key)? _pendingPlacement;
    private PlacementKey? _desiredPlacement;
    private PlacementKey? _checkedPlacement;
    private (PlacementKey Key, int Direction)? _snappedPlacementDirection;
    private string? _pendingMoveRequest;
    private long? _pendingMoveClearRevision;
    private List<EditableLotObject> _editableObjects = [];
    private Dictionary<int, PlacedObjectMeta> _placedObjectMeta = new();
    private HashSet<string> _pendingSaleRequests = new(StringComparer.Ordinal);
    private (string Id, int ObjectID)? _pendingDisposePreviewRequest;
    public CGPoint? ScriptSimPosition { get; private set; }
    private int? _scriptSimLevel;
    public List<(int Id, string Name)> ScriptObjects { get; private set; } = [];
    public bool? ScriptFreeWill { get; private set; }

    private record struct BuildCursorKey
    {
        public required uint Guid { get; init; }
        public required int Graphic { get; init; }
        public required LotVertex Vertex { get; init; }
        public required int Level { get; init; }
        public int Direction { get; set; } = 1;
        public required SimsSDL.Core.LotCamera Orientation { get; init; }
        public bool Centered { get; set; }
        public ushort? Pattern { get; set; }
        public int WallDirection { get; set; }
        public int? WallEdge { get; set; }
        public int? WallSide { get; set; }
        public bool Fill { get; set; }
        public required long Revision { get; init; }

        public BuildCursorKey() { }
    }

    private BuildCursorKey? _desiredBuildCursor;
    private BuildableArea? _buildable;
    private BuildableArea? _buildableLevel2;
    private ulong _lastBuildRefusal;
    private BuildCursorKey? _checkedBuildCursor;
    private (string Id, BuildCursorKey Key)? _pendingBuildCursor;
    private Dictionary<string, (string Success, string? Failure)> _pendingResponseSounds = new(StringComparer.Ordinal);
    private HashSet<string> _pendingSaveRequests = new(StringComparer.Ordinal);
    private Dictionary<string, Action<bool>> _pendingSaveCompletions = new(StringComparer.Ordinal);
    private HashSet<string> _pendingLoadRequests = new(StringComparer.Ordinal);
    private HashSet<string> _pendingScriptTileTraversals = new(StringComparer.Ordinal);
    private Dictionary<string, (List<int>? ObjectIDs, string? Error)> _scriptTileTraversalResults = new(StringComparer.Ordinal);
    private string? _pendingAudioState;
    private string? _pendingResetTutorialState;
    private Dictionary<string, OriginalSoundOptionsOverlay.VolumeChange> _pendingAudioVolumes = new(StringComparer.Ordinal);
    private Dictionary<string, string> _latestAudioVolumeRequest = new(StringComparer.Ordinal);
    private bool _soundGesture;
    private (CGPoint Point, GroundTile Tile)? _placementAnchor;
    private int? _lastPieHighlight;
    private string? _lastCutawayTile;
    private (string Key, int X, int Y, int Zoom, bool WallpaperTool, double Time)? _desiredCutaway;
    public CGRect? PendingPhoto { get; private set; }
    private string? _pendingPhotoCaption;
    private bool _pendingPhotoIsAutomatic;

    private sealed class PictureInPictureWindow
    {
        public required int ObjectID { get; init; }
        public DateTime? Expires { get; set; }
        public int SizeIndex { get; set; }
        public int Zoom { get; set; }
        public string? Text { get; set; }
        public bool SnapshotPending { get; set; }
        public bool Built { get; set; }
    }

    private PictureInPictureWindow? _pictureInPicture;
    private bool _pipNeedsCapture;
    private RenderTargets? _pipRenderTargets;
    private int _pipPanAssignmentsBias;
    private bool _pipCloseTracking;
    private bool _dialogButtonTracking;
    private bool _chooserOKTracking;
    private bool _modsOverlayGesture;
    private int? _pendingPipCenterObjectID;
    private bool _pendingPipCenterChangesLevel;
    private long? _lastPictureInPictureSequence;
    private int _lastRunningSpeed = 1;
    private bool _liveModePaused;
    private string? _localDialogToken;
    private Action<byte>? _localDialogResponse;
    private HashSet<string> _answeredDialogs = new(StringComparer.Ordinal);
    public CGPoint? Pointer { get; private set; }
    private CGSize _canvas = new(1, 1);
    public double ScriptPixelDensity { get; set; } = 1;
    public Action<CGPoint>? WarpPointer { get; set; }
    private WallStroke? _wallStroke;
    private WallBrushSelection? _wallBrush;
    private (GroundTile Start, ushort Pattern, ushort? Selection, bool Deleting)? _floorStroke;
    private FloorBrushSelection? _floorBrush;
    private bool _floorBrushDeleting;
    private string? _floorBrushTexture;
    private (bool Deleting, ushort Pattern, HashSet<LotScene.WallSide> Visited)? _wallpaperStroke;
    private int? _lastWallpaperCursorDirection;
    private ushort _lastBuildModifiers;
    private TerrainBrushMode? _terrainStrokeMode;
    private CGPoint? _terrainStrokeStartPoint;
    private string? _terrainStrokeID;
    private byte? _terrainStrokeBaseHeight;
    private short? _lastStreamedTerrainDelta;
    private bool _terrainStrokePlayedSound;
    private TerrainBrushGesture _terrainGesture = new();
    public bool PrimaryGesture { get; private set; }
    public bool QuitRequested { get; set; }

    private bool _lotSaveDisabled;
    private bool LotSaveDisabled
    {
        get => _lotSaveDisabled;
        set
        {
            _lotSaveDisabled = value;
            Ui.OptionsPanel.LotSaveDisabled = value;
        }
    }

    public int? HomeLotHouse { get; private set; }

    private bool _awayBuyBuildLocked;
    public bool AwayBuyBuildLocked
    {
        get => _awayBuyBuildLocked;
        private set
        {
            _awayBuyBuildLocked = value;
            Ui.AwayBuyBuildLocked = value;
        }
    }

    private bool _emergencyBuyBuildLocked;
    public bool EmergencyBuyBuildLocked
    {
        get => _emergencyBuyBuildLocked;
        private set
        {
            _emergencyBuyBuildLocked = value;
            Ui.EmergencyBuyBuildLocked = value;
        }
    }

    public bool BuyBuildLocked => AwayBuyBuildLocked || EmergencyBuyBuildLocked;

    private bool _simlessBuildMode;
    public bool SimlessBuildMode
    {
        get => _simlessBuildMode;
        private set
        {
            _simlessBuildMode = value;
            Ui.LiveModeLocked = value;
            if (!value)
            {
                _simlessResumeBuildMode = false;
            }
        }
    }
    private bool _simlessResumeBuildMode;
    private SDLAudioPlayer? _audio;
    private Vector2 _lastAudioPan = Vector2.Zero;
    private LotZoom _lastAudioZoom = LotZoom.Medium;
    private long _lastAudioSceneRevision = -1;
    private long _lastAudioAnimationSequence = -1;

    private int _currentNeighborhood;
    private int? _currentHouse;
    private int? _lastNeighborhoodMode;
    private Action<int>? _neighborhoodHouseSelected;
    private bool _rezoneMode;
    private bool _evictMode;
    private OriginalNeighborhoodOverlay? _neighborhoodBeforeHouseholdCreation;
    private int? _pendingHouseholdCreation;
    private string? _pendingHouseholdCreationRequest;
    private string? _pendingHouseholdAppearanceRequest;
    private (string Gender, string Age, string Skin)? _deferredAppearanceCatalogRequest;
    private (string Gender, string Age, string Skin)? _queuedAppearanceCatalogRequest;
    private string? _pendingAppearanceCatalogKey;
    private bool _prewarmingAppearanceCatalog;
    private Dictionary<string, SimsSDL.Core.HouseholdAppearanceCatalog> _cachedAppearanceCatalogs = new(StringComparer.Ordinal);
    private bool _bridgeConnected;
    private bool _daemonMode;
    private bool _daemonWarmedUp;

    private readonly record struct DaemonOpenLotResult(bool Simless, bool Away, int? HomeHouse);

    private List<TaskCompletionSource> _pendingHelloContinuations = [];
    private Dictionary<string, (string Session, TaskCompletionSource<(string Session, string Manifest)> Continuation)> _pendingDaemonNeighborhoodRequests = new(StringComparer.Ordinal);
    private Dictionary<string, TaskCompletionSource<DaemonOpenLotResult>> _pendingDaemonOpenLotRequests = new(StringComparer.Ordinal);

    private bool HasActiveLot =>
        Bridge is not null && (_currentHouse ?? 0) > 0 && Ui.Neighborhood is null && Ui.HouseholdCreation is null;

    private bool IsLivePanelMinimized =>
        Ui.PanelMinimized && IsInLiveMode;

    private string? _pendingHouseholdPreviewRequest;
    private (string Gender, string Age, string Skin, string Head, string Body)? _queuedAppearancePreviewRequest;
    private int _pendingHouseholdPreviewKey;
    private string _pendingHouseholdPreviewSignature = string.Empty;
    private Dictionary<int, string> _familyPortraits = new();
    private (int House, int Family, string? Request)? _pendingFamilyMoveIn;

    private OriginalFamilyPickerOverlay.Family? _familyPlacement;
    private OriginalFamilyPickerOverlay.Family? FamilyPlacement
    {
        get => _familyPlacement;
        set
        {
            _familyPlacement = value;
            Ui.Neighborhood?.SetMovingInFamily(value);
        }
    }

    private bool _householdCreationUnhoused;
    private bool _returnToFamilyPickerAfterHouseholdCreation;

    private readonly record struct NeighborhoodRequest(string Id, GameDialog Dialog, int Mode);

    private NeighborhoodRequest? _pendingNeighborhood;
    private string? _pendingNeighborhoodResponse;
    private GameDialog? _activeNeighborhoodDialog;
    private HashSet<string> _failedNeighborhoodTokens = new(StringComparer.Ordinal);
    private (string Id, GameDialog Dialog)? _pendingOutfitChoices;
    private string? _pendingOutfitPreview;
    private bool _loadingNeighborhood;
    private bool _editingNeighborhood;
    private bool _exportingWebPages;
    private bool _openingNeighborhoodLot;
    private bool _switchingLot;
    private bool _awaitingLotSwitchChange;
    private bool _hasCompletedInitialLoad;
    private long _highestReceivedSceneRevision;
    private long _minimumSceneRevisionToFinishLoading = 1;
    private int? _lastHouseStateClass;
    private int _lastLotTransitInfo;
    private (int Destination, OriginalTravelLoadScreen? Screen)? _pendingTravelSelection;
    private ulong _neighborhoodLoadGeneration;
    private int? _pendingNeighborhoodTarget;
    public bool IsLoadingNeighborhood => _loadingNeighborhood;
    private List<string> _splashProgressQueue = [];
    private double _lastSplashProgressStep;
    private SDLAudioPlayer? _startupLoadAudio;
    private SimulationBridge? _frontendAudio;
    private SDLAudioPlayer? _frontendAudioPlayer;
    private bool _frontendAudioReady;
    private List<(string Operation, Dictionary<string, object?> Parameters)> _pendingFrontendAudio = [];
    public bool ScriptAnswersDialogs { get; set; }
    public string? ScriptDialogStop { get; set; }
    public bool SuppressEdgeScrollForScript { get; set; }
    private string? _frontendMusic;
    private bool UsesNativeEngine => SimulationEngineSelection.UsesNativeEngine();
    private Dictionary<string, Dictionary<string, Dictionary<string, string>>> _pluginPanelValues = new(StringComparer.Ordinal);

    private bool _catalogPopupWasVisible;
    public string HoverCursor { get; private set; } = "Arrow";
    public bool DeleteModifier { get; set; }
    public bool ScriptDeleteModifier { get; set; }
    public bool ScriptCtrlModifier { get; set; }
    public bool ScriptShiftModifier { get; set; }
    private double _lastTutorialPanelCheck;
    private LotZoom? _simulatorZoom;
    private string? _simulatorMode;
    private bool? _simulatorViewScrolling;
    private Vector2? _lastSimulatorPan;
    private bool _rightSelectedSim;
    private bool _rightConsumed;
    private GameplayPanelState.Relationship.LivePosition? _relationshipCenter;
    private bool _relationshipCenterChangesLevel;

    internal static void Log(string message) => Console.Error.WriteLine($"SimsSDL: {message}");

    private static double CurrentUptime() =>
        System.Diagnostics.Stopwatch.GetTimestamp() / (double)System.Diagnostics.Stopwatch.Frequency;

    private static void RunOnMainThread(Action action)
    {
        if (MainThreadDispatcher.IsMainThread)
        {
            action();
        }
        else
        {
            MainThreadDispatcher.Post(action);
        }
    }

    private static Task<T> RunOnMainThreadAsync<T>(Func<T> func)
    {
        if (MainThreadDispatcher.IsMainThread)
        {
            return Task.FromResult(func());
        }

        var tcs = new TaskCompletionSource<T>(TaskCreationOptions.RunContinuationsAsynchronously);
        MainThreadDispatcher.Post(() =>
        {
            try
            {
                tcs.TrySetResult(func());
            }
            catch (Exception ex)
            {
                tcs.TrySetException(ex);
            }
        });
        return tcs.Task;
    }

    internal LiveController(Options options, int? house, LotRenderer renderer)
    {
        string workspace = options.Workspace ?? InstallLocator.DefaultWorkspace();
        string dataRoot = options.DataRoot ?? InstallLocator.DefaultDataRoot(workspace);
        var resolvedOptions = options;
        resolvedOptions.Workspace = workspace;
        resolvedOptions.DataRoot = dataRoot;
        string game = resolvedOptions.Game
            ?? InstallLocator.ResolveGameDirectory(explicitPath: null, workspace: workspace, dataRoot: dataRoot)
            ?? Path.Combine(workspace, "runtime", "game");
        resolvedOptions.Game = game;
        Content = ModManager.LoadStartupContentWithSafeMode(game, workspace, dataRoot, resolvedOptions.Packs, out _safeModeBootError);
        AppLog.Info(FormattableString.Invariant(
            $"GameContent loaded (language={Content.Language.Code}, activePacks={Content.Packs.Ordered.Count}, disabledDownloads={Content.DisabledDownloadFolders.Count}, safeMode={_safeModeBootError is not null})."));
        if (_safeModeBootError is not null)
        {
            AppLog.Warn($"Mod Safe Mode triggered on startup: {_safeModeBootError}");
        }
        Workspace = workspace;
        Options = resolvedOptions;
        Renderer = renderer;
        _currentNeighborhood = resolvedOptions.Neighborhood;
        Ui = new LiveUI(Content);
        AppLog.Info("LiveUI initialized.");
        ResolvePluginTrust(dataRoot, allowInteractivePrompt: !options.AnswerDialogs);

        if (house is int activeHouse)
        {
            if (UsesNativeEngine)
            {
                _daemonMode = true;
            }
            StartSimulation(activeHouse);
        }
        else if (UsesNativeEngine)
        {
            _daemonMode = true;
            StartWarmDaemon();
        }
        else
        {
            LoadBaseNeighborhood();
        }
    }

    private float LoadLoopVolume() => LoadPersistedAudioGroupVolume(1, "MUSIC");

    private float LoadAmbientVolume() => LoadPersistedAudioGroupVolume(3, "AMBIENCE");

    private float LoadPersistedAudioGroupVolume(int groupIndex, string groupName)
    {
        string profile = Path.Combine(Options.DataRoot ?? Workspace, "runtime", "profiles", Options.Profile, "Settings", "audio.json");
        try
        {
            if (!File.Exists(profile))
            {
                return 1f;
            }

            byte[] data = File.ReadAllBytes(profile);
            using var doc = JsonDocument.Parse(data);
            if (doc.RootElement.ValueKind != JsonValueKind.Object)
            {
                return 1f;
            }

            if (doc.RootElement.TryGetProperty("schemaVersion", out var schema) &&
                schema.ValueKind == JsonValueKind.Number &&
                schema.TryGetInt32(out int schemaVersion) &&
                schemaVersion == 1 &&
                doc.RootElement.TryGetProperty("volumes", out var volumes) &&
                volumes.ValueKind == JsonValueKind.Array &&
                volumes.GetArrayLength() == 4)
            {
                var entry = volumes[groupIndex];
                if (entry.ValueKind == JsonValueKind.Number && entry.TryGetSingle(out float v) && float.IsFinite(v))
                {
                    return Math.Clamp(v, 0f, 1f);
                }

                return 1f;
            }

            if (doc.RootElement.TryGetProperty(groupName, out var flat) &&
                flat.ValueKind == JsonValueKind.Number &&
                flat.TryGetSingle(out float flatValue) &&
                float.IsFinite(flatValue))
            {
                return Math.Clamp(flatValue, 0f, 1f);
            }

            return 1f;
        }
        catch
        {
            return 1f;
        }
    }

    private static string? LoadLoopURL(GameContent content)
    {
        string path = content.Root;
        string[] parts = ["Music", "Modes", "Load", "loadloop.wav"];
        foreach (string part in parts)
        {
            try
            {
                string? next = null;
                foreach (string entry in Directory.EnumerateFileSystemEntries(path))
                {
                    if (string.Equals(Path.GetFileName(entry), part, StringComparison.OrdinalIgnoreCase))
                    {
                        next = entry;
                        break;
                    }
                }

                if (next is null)
                {
                    return null;
                }

                path = next;
            }
            catch
            {
                return null;
            }
        }

        return path;
    }

    private void StartWarmDaemon()
    {
        _currentHouse = 0;
        HomeLotHouse = null;
        AwayBuyBuildLocked = false;
        EmergencyBuyBuildLocked = false;
        SimlessBuildMode = false;
        Ui.PanelMinimized = false;
        StopFrontendAudio();
        var bridge = new SimulationBridge(Workspace, Options.DataRoot, Options.Profile, _currentNeighborhood);
        bridge.DiscardsContentOnExit = true;
        Bridge = bridge;
        _bridgeConnected = false;
        _daemonWarmedUp = false;
        Renderer.LiveMode = false;
        Renderer.DrawsLot = false;
        Renderer.ApplyEnvironment(null);
        BeginStartupSplash(startingAt: 3);
        AttachBridgeCallbacks(bridge);
        _audio?.Close();
        _audio = null;
        _lastAudioSceneRevision = -1;
        _lastAudioAnimationSequence = -1;
        if (Options.Audio)
        {
            try
            {
                var audio = new SDLAudioPlayer(bridge.Session);
                audio.Ended = voice => RunOnMainThread(() =>
                {
                    if (ReferenceEquals(_audio, audio))
                    {
                        _ = Send("audioEnded", new Dictionary<string, object?> { ["voice"] = voice });
                    }
                });
                audio.Spatial = (owner, panned, zoom) => SpatialMix(owner, panned, zoom);
                audio.SetAmbientMasterVolume(LoadAmbientVolume());
                _audio = audio;
                if (LoadLoopURL(Content) is { } loop)
                {
                    audio.PlayLoadLoop(loop, LoadLoopVolume());
                }
            }
            catch (Exception error)
            {
                Log($"audio disabled: {error}");
            }
        }

        _ = StartWarmDaemonCoreAsync(bridge);
    }

    private async Task StartWarmDaemonCoreAsync(SimulationBridge bridge)
    {
        var weakSelf = new WeakReference<LiveController>(this);
        var weakBridge = new WeakReference<SimulationBridge>(bridge);
        try
        {
            AppLog.SetStage("Daemon: starting warm simulation server");
            await bridge.StartDaemonAsync(Content, nativeEngine: true).ConfigureAwait(false);
            bool active = await RunOnMainThreadAsync(() =>
            {
                if (!weakSelf.TryGetTarget(out var self) || !weakBridge.TryGetTarget(out var target))
                {
                    return false;
                }

                if (!ReferenceEquals(self.Bridge, target))
                {
                    target.Stop(save: false);
                    _ = target.WaitForExit(10);
                    return false;
                }

                Log($"daemon session {target.Session}");
                return true;
            }).ConfigureAwait(false);
            if (!active)
            {
                return;
            }

            AppLog.SetStage("Daemon: waiting for simulation server hello");
            await WaitForBridgeConnected().ConfigureAwait(false);
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self) || !weakBridge.TryGetTarget(out var target))
                {
                    return;
                }

                if (!ReferenceEquals(self.Bridge, target))
                {
                    return;
                }

                self.LoadBaseNeighborhood(mode: 1);
            });
        }
        catch (Exception error)
        {
            AppLog.Error($"Warm simulation daemon startup failed: {error}");
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self) || !weakBridge.TryGetTarget(out var target))
                {
                    return;
                }

                if (!ReferenceEquals(self.Bridge, target))
                {
                    return;
                }

                Log($"Simulation daemon: {error}");
                self._audio?.StopLoadLoop();
                self._loadingNeighborhood = false;
                self.HandleInitialOrNeighborhoodError(error);
            });
        }
    }

    private void AttachBridgeCallbacks(SimulationBridge bridge)
    {
        var weakSelf = new WeakReference<LiveController>(this);
        var weakBridge = new WeakReference<SimulationBridge>(bridge);
        bridge.Event = evt => RunOnMainThread(() =>
        {
            if (!weakSelf.TryGetTarget(out var self) || !weakBridge.TryGetTarget(out var target))
            {
                return;
            }

            if (!ReferenceEquals(self.Bridge, target))
            {
                return;
            }

            EventProfiler.Measure(evt.JsonString("type") ?? "response", () => self.SimulationEvent(evt));
        });
        bridge.Animation = frame => MainThreadDispatcher.Post(() =>
        {
            if (!weakSelf.TryGetTarget(out var self) || !weakBridge.TryGetTarget(out var target))
            {
                return;
            }

            if (!ReferenceEquals(self.Bridge, target))
            {
                return;
            }

            self.Renderer.QueueAnimation(frame);
        });
        bridge.Failed = error => RunOnMainThread(() =>
        {
            var targetForLog = weakBridge.TryGetTarget(out var resolvedBridge) ? resolvedBridge : null;
            string logHint = AppLog.CurrentLogPath is { Length: > 0 } currentLog
                ? $" (log: {currentLog})"
                : string.Empty;
            Log($"{error}{logHint}");
            if (!weakSelf.TryGetTarget(out var self) || targetForLog is null)
            {
                return;
            }

            if (!ReferenceEquals(self.Bridge, targetForLog))
            {
                return;
            }

            self.CancelPendingDaemonContinuations(new ContentError(error));
        });
    }

    private Task WaitForBridgeConnected()
    {
        if (MainThreadDispatcher.IsMainThread)
        {
            if (_bridgeConnected)
            {
                return Task.CompletedTask;
            }

            var tcs = new TaskCompletionSource(TaskCreationOptions.RunContinuationsAsynchronously);
            _pendingHelloContinuations.Add(tcs);
            return tcs.Task;
        }

        var waiter = new TaskCompletionSource(TaskCreationOptions.RunContinuationsAsynchronously);
        MainThreadDispatcher.Post(() =>
        {
            if (_bridgeConnected)
            {
                waiter.TrySetResult();
            }
            else
            {
                _pendingHelloContinuations.Add(waiter);
            }
        });
        return waiter.Task;
    }

    private void CancelPendingDaemonContinuations(Exception error)
    {
        var hellos = _pendingHelloContinuations;
        _pendingHelloContinuations = [];
        foreach (var continuation in hellos)
        {
            continuation.TrySetException(error);
        }

        var neighborhoods = _pendingDaemonNeighborhoodRequests;
        _pendingDaemonNeighborhoodRequests = new Dictionary<string, (string Session, TaskCompletionSource<(string Session, string Manifest)> Continuation)>(StringComparer.Ordinal);
        foreach (var entry in neighborhoods.Values)
        {
            entry.Continuation.TrySetException(error);
        }

        var openLots = _pendingDaemonOpenLotRequests;
        _pendingDaemonOpenLotRequests = new Dictionary<string, TaskCompletionSource<DaemonOpenLotResult>>(StringComparer.Ordinal);
        foreach (var continuation in openLots.Values)
        {
            continuation.TrySetException(error);
        }
    }

    private void StartSimulation(int house)
    {
        _currentHouse = house;
        HomeLotHouse = _pendingHouseholdCreation is null ? house : null;
        AwayBuyBuildLocked = false;
        EmergencyBuyBuildLocked = false;
        SimlessBuildMode = false;
        Ui.PanelMinimized = false;
        if (_daemonMode)
        {
            _daemonWarmedUp = true;
        }
        StopFrontendAudio();
        var bridge = new SimulationBridge(Workspace, Options.DataRoot, Options.Profile, _currentNeighborhood);
        bridge.DiscardsContentOnExit = true;
        Bridge = bridge;
        _bridgeConnected = false;
        _deferredAppearanceCatalogRequest = null;
        _queuedAppearanceCatalogRequest = null;
        _pendingAppearanceCatalogKey = null;
        _prewarmingAppearanceCatalog = false;
        _cachedAppearanceCatalogs.Clear();
        _queuedAppearancePreviewRequest = null;
        _simulatorZoom = null;
        _simulatorMode = null;
        _simulatorViewScrolling = null;
        _lastSimulatorPan = Renderer.Pan;
        _tutorialLiveModeClicked = false;
        _lastRunningSpeed = Math.Max(1, Options.Speed ?? 1);
        _liveModePaused = Options.Speed == 0;
        _highestReceivedSceneRevision = 0;
        _minimumSceneRevisionToFinishLoading = 1;
        Renderer.ResetSceneRevisionTracking();
        _awaitingLotSwitchChange = false;
        _switchingLot = false;
        _pendingTravelSelection = null;
        _lastHouseStateClass = null;
        _lastLotTransitInfo = 0;
        Renderer.LiveMode = true;
        Renderer.DrawsLot = Ui.ShowsLot;
        Renderer.ApplyEnvironment(null);
        AttachBridgeCallbacks(bridge);
        _audio?.Close();
        _audio = null;
        _lastAudioSceneRevision = -1;
        _lastAudioAnimationSequence = -1;
        if (Options.Audio)
        {
            try
            {
                var audio = new SDLAudioPlayer(bridge.Session);
                audio.Ended = voice => RunOnMainThread(() =>
                {
                    if (ReferenceEquals(_audio, audio))
                    {
                        _ = Send("audioEnded", new Dictionary<string, object?> { ["voice"] = voice });
                    }
                });
                audio.Spatial = (owner, panned, zoom) => SpatialMix(owner, panned, zoom);
                audio.SetAmbientMasterVolume(LoadAmbientVolume());
                _audio = audio;
            }
            catch (Exception error)
            {
                Log($"audio disabled: {error}");
            }
        }

        if (_pendingHouseholdCreation is int lot)
        {
            Ui.Loading = false;
            _openingNeighborhoodLot = false;
            _hasCompletedInitialLoad = true;
            try
            {
                OpenHouseholdCreationOverlay(lot);
            }
            catch
            {
            }
        }
        else if (!_hasCompletedInitialLoad)
        {
            _openingNeighborhoodLot = false;
            BeginStartupSplash(startingAt: 5);
            if (_audio is { } activeAudio && LoadLoopURL(Content) is { } loop)
            {
                activeAudio.PlayLoadLoop(loop, LoadLoopVolume());
            }
        }
        else
        {
            Ui.Loading = false;
            _openingNeighborhoodLot = true;
        }

        _centresOnSelectedSim = Ui.OptionsPanel.PlayOptions.AutoCenter;
        _pendingPieHead = null;
        _desiredPieHead = null;
        _checkedPieHead = null;
        _ = StartSimulationCoreAsync(bridge, house);
    }

    private async Task StartSimulationCoreAsync(SimulationBridge bridge, int house)
    {
        var weakSelf = new WeakReference<LiveController>(this);
        var weakBridge = new WeakReference<SimulationBridge>(bridge);
        try
        {
            await bridge.StartAsync(Content, house, UsesNativeEngine).ConfigureAwait(false);
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self) || !weakBridge.TryGetTarget(out var target))
                {
                    return;
                }

                if (!ReferenceEquals(self.Bridge, target))
                {
                    target.Stop(save: false);
                    _ = target.WaitForExit(10);
                    return;
                }

                Log($"live session {target.Session}");
            });
        }
        catch (Exception error)
        {
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self) || !weakBridge.TryGetTarget(out var target))
                {
                    return;
                }

                if (!ReferenceEquals(self.Bridge, target))
                {
                    return;
                }

                Log($"Open lot {house}: {error}");
                self.Bridge = null;
                self._audio?.Close();
                self._audio = null;
                self.Ui.Loading = false;
                self._openingNeighborhoodLot = false;
                self._switchingLot = false;
                self._awaitingLotSwitchChange = false;
                self._hasCompletedInitialLoad = true;
                self._pendingFamilyMoveIn = null;
                self.RestoreNeighborhoodAfterHouseholdCreation();
                self.ShowNeighborhoodError(error);
            });
        }
    }

    private void RequestPieHeadPreview()
    {
        if (Ui.PieMenu is not { } menu)
        {
            _desiredPieHead = null;
            return;
        }

        _desiredPieHead = new PieHeadKey(
            menu,
            menu.SelectedSim,
            MathF.Round(menu.HeadOrientation.X * 2f, MidpointRounding.AwayFromZero) / 2f,
            MathF.Round(menu.HeadOrientation.Y * 2f, MidpointRounding.AwayFromZero) / 2f);
        if (_pendingPieHead is not null || _desiredPieHead is not { } key || key == _checkedPieHead)
        {
            return;
        }

        string? id = Send("pieHeadPreview", new Dictionary<string, object?> { ["yaw"] = key.Yaw, ["pitch"] = key.Pitch });
        if (id is null)
        {
            return;
        }

        _pendingPieHead = (id, key);
    }

    private string? Send(string operation, IReadOnlyDictionary<string, object?>? parameters = null)
    {
        if (Bridge is not { } bridge)
        {
            return null;
        }

        try
        {
            return bridge.Send(operation, parameters);
        }
        catch (Exception error)
        {
            Log($"{operation}: {error}");
            return null;
        }
    }

    public List<string>? ScriptUISounds { get; set; }

    public void PlayUISound(string name)
    {
        ScriptUISounds?.Add(name);
        if (Bridge is null)
        {
            SendFrontendAudio("audioEvent", new Dictionary<string, object?> { ["name"] = name });
            return;
        }

        if (_audio is not null)
        {
            _ = Send("audioEvent", new Dictionary<string, object?> { ["name"] = name });
        }
    }

    private void PlayModeMusic(string mode)
    {
        if (Bridge is not null && _audio is not null)
        {
            _ = Send("modeMusic", new Dictionary<string, object?> { ["mode"] = mode });
        }
    }

    private (float Pan, float Gain) SpatialMix(int owner, bool panned, bool zoom)
    {
        if (Renderer.Scene is not { } scene || Renderer.SceneViewport(SimdCanvas) is not { } viewport)
        {
            return (0f, 1f);
        }

        (int Level, Vector2 Point)? placed = null;
        if (scene.Sprites.FirstOrDefault(s => s.ObjectID == owner) is { } sprite)
        {
            placed = (sprite.Level ?? 1, new Vector2(sprite.X + sprite.Width / 2f, sprite.Y + sprite.Height / 2f));
        }
        else if (scene.Meshes is { } meshes
                 && meshes.FirstOrDefault(m => m.ObjectID == owner) is { } mesh
                 && mesh.Vertices.Count > 0)
        {
            var vertex = mesh.Vertices[0];
            placed = (mesh.Level ?? 1, new Vector2(vertex.X, vertex.Y));
        }
        else if (scene.SoundSources is { } sources
                 && sources.FirstOrDefault(s => s.ObjectID == owner) is { } source
                 && PositionalSound.ScenePoint(source, scene) is { } sourcePoint)
        {
            placed = (source.Level, sourcePoint);
        }

        if (placed is not { } target)
        {
            return (0f, zoom ? Renderer.Zoom.SoundGain() : 1f);
        }

        var mix = PositionalSound.Mix(target.Point * viewport.Scale + viewport.Origin, viewport.Size, panned);
        float floor = PositionalSound.FloorGain(target.Level, Renderer.ViewLevel);
        return (mix.Pan, mix.Gain * floor * (zoom ? Renderer.Zoom.SoundGain() : 1f));
    }

    public void UpdateAudio()
    {
        _frontendAudioPlayer?.Poll();
        if (_audio is not { } audio)
        {
            return;
        }

        audio.Poll();
        audio.SetEnvironmentAudio(
            Renderer.Environment?.Effect.AudioGain ?? 1f,
            Renderer.Environment?.Effect.AudioCutoff ?? 0f);
        audio.UpdateAmbientBeds(
            Renderer.LiveMode && Ui.ShowsLot ? Renderer.Environment : null,
            paused: _liveModePaused || HasBlockingDialog || !Renderer.LiveMode || !Ui.ShowsLot);
        if (Renderer.Pan != _lastAudioPan
            || Renderer.Zoom != _lastAudioZoom
            || Renderer.SceneRevisionNumber != _lastAudioSceneRevision
            || Renderer.AnimationSequenceNumber != _lastAudioAnimationSequence)
        {
            _lastAudioPan = Renderer.Pan;
            _lastAudioZoom = Renderer.Zoom;
            _lastAudioSceneRevision = Renderer.SceneRevisionNumber;
            _lastAudioAnimationSequence = Renderer.AnimationSequenceNumber;
            audio.UpdateSpatial();
        }
    }

    public void Stop()
    {
        CancelPendingDaemonContinuations(new OperationCanceledException());
        _audio?.Close();
        _audio = null;
        _lastAudioSceneRevision = -1;
        _lastAudioAnimationSequence = -1;
        var hosts = new List<SimulationBridge>(2);
        if (Bridge is not null)
        {
            hosts.Add(Bridge);
        }

        if (_frontendAudio is not null)
        {
            hosts.Add(_frontendAudio);
        }

        Bridge?.Stop();
        StopFrontendAudio();
        foreach (var host in hosts)
        {
            if (!host.WaitForExit(10))
            {
                Log("the simulation host did not exit in time");
            }
        }
    }

    private void PlayUISoundOnResponse(string? id, string success, string? failure = "ui_error")
    {
        if (id is null)
        {
            return;
        }

        _pendingResponseSounds[id] = (success, failure);
    }

    private string? SendWithBuildSound(string operation, IReadOnlyDictionary<string, object?> parameters, string successSound = "ui_bld_dragtool_place")
    {
        string? id = Send(operation, parameters);
        PlayUISoundOnResponse(id, successSound);
        return id;
    }

    private bool IsInLiveMode => !Ui.BuyMode && !Ui.BuildMode && !Ui.OptionsMode && !Ui.Camera.Visible;

    public void SendSpeed(int value)
    {
        if (SimlessBuildMode)
        {
            return;
        }

        if (value > 0)
        {
            _lastRunningSpeed = value;
            _liveModePaused = false;
            if (!IsInLiveMode)
            {
                if (!Ui.BuyMode && !Ui.BuildMode && SpeedTransitionSound(0, value) is { } pendingSound)
                {
                    PlayUISound(pendingSound);
                }

                return;
            }
        }
        else
        {
            _liveModePaused = true;
            if (!IsInLiveMode)
            {
                return;
            }
        }

        if (Send("speed", new Dictionary<string, object?> { ["value"] = value }) is null)
        {
            return;
        }

        int previousSpeed = Renderer.Speed;
        Renderer.Speed = value;
        if (SpeedTransitionSound(previousSpeed, value) is { } sound)
        {
            PlayUISound(sound);
        }
    }

    private void PauseForNonLiveMode()
    {
        if (Renderer.Speed > 0)
        {
            _lastRunningSpeed = Renderer.Speed;
        }

        if (Send("speed", new Dictionary<string, object?> { ["value"] = 0 }) is null)
        {
            return;
        }

        int previousSpeed = Renderer.Speed;
        Renderer.Speed = 0;
        if (SpeedTransitionSound(previousSpeed, 0) is { } sound)
        {
            PlayUISound(sound);
        }
    }

    private void ResumeLiveMode()
    {
        if (SimlessBuildMode)
        {
            RestoreSimlessEditingMode();
            return;
        }

        if (!IsInLiveMode)
        {
            return;
        }

        PlayModeMusic("live");
        int target = _liveModePaused ? 0 : _lastRunningSpeed;
        if (target <= 0)
        {
            return;
        }

        SendSpeed(target);
    }

    public static string? SpeedTransitionSound(int current, int requested)
    {
        static string? Code(int speed) => speed switch
        {
            0 => "p",
            1 => "1",
            3 => "2",
            10 => "3",
            _ => null,
        };

        if (current == requested || Code(current) is not { } from || Code(requested) is not { } to)
        {
            return null;
        }

        return $"ui_speed_{from}to{to}";
    }

    private double Scale => Renderer.UIScale;
    private CGSize LogicalCanvas => new(_canvas.Width / Scale, _canvas.Height / Scale);
    private CGPoint Local(CGPoint point) => new(point.X / Scale, point.Y / Scale);
    private double OverlayScale => Ui.ShowsLot ? Scale : LiveUI.FullscreenOverlayScale(_canvas, Renderer.UIScale);
    private CGSize OverlayLogicalCanvas => new(_canvas.Width / OverlayScale, _canvas.Height / OverlayScale);
    private CGPoint OverlayLocal(CGPoint point) => new(point.X / OverlayScale, point.Y / OverlayScale);

    private CGRect OverlayScriptScreenRect(CGRect rect) =>
        new(rect.MinX * OverlayScale, rect.MinY * OverlayScale, rect.Width * OverlayScale, rect.Height * OverlayScale);

    private static Vector2 Simd(CGPoint point) => new((float)point.X, (float)point.Y);
    private Vector2 SimdCanvas => new((float)_canvas.Width, (float)_canvas.Height);

    public void DismissTransientMenu()
    {
        _placementAnchor = null;
        _wallStroke = null;
        _wallBrush = null;
        _floorStroke = null;
        _floorBrush = null;
        _floorBrushDeleting = false;
        _floorBrushTexture = null;
        _wallpaperStroke = null;
        _lastWallpaperCursorDirection = null;
        try { Renderer.UpdateWallBrush(null); } catch { }
        try { Renderer.UpdateFloorBrush(null); } catch { }
        _terrainStrokeMode = null;
        _terrainStrokeStartPoint = null;
        _terrainStrokeID = null;
        _terrainStrokeBaseHeight = null;
        _lastStreamedTerrainDelta = null;
        _terrainStrokePlayedSound = false;
        _terrainGesture = new TerrainBrushGesture();
        _pendingMenu = null;
        _pendingPieMenuWarp = null;
        _pieGround = null;
        Ui.PieMenu = null;
        _desiredPieHead = null;
        _checkedPieHead = null;
    }

    public void DismissMenu()
    {
        bool hadPlacementAnchor = _placementAnchor is not null;
        DismissTransientMenu();
        if (hadPlacementAnchor)
        {
            PrimaryGesture = false;
        }

        _pendingMoveClearRevision = null;
        Ui.Buy.CancelSelection();
        Ui.Build.CancelSelection();
        SyncDisposePanel();
        Ui.CatalogPopup.ShowPlacementError(null);
        _desiredPlacement = null;
        _checkedPlacement = null;
        _snappedPlacementDirection = null;
        try { Renderer.UpdatePlacement(null); } catch { }
        ClearBuildCursor();
        if (Pointer is { } pointer)
        {
            HoverCursor = CursorStem(pointer);
        }
    }

    private void ActivateBuyMode(bool allowDuringDialog = false)
    {
        if ((!allowDuringDialog && HasBlockingDialog) || BuyBuildLocked)
        {
            return;
        }

        DismissMenu();
        CloseCameraOverlay();
        CloseOptionsOverlay();
        Ui.BuildMode = false;
        _pendingBuildCatalog = null;
        Ui.BuyMode = true;
        EditingViewChanged();
        _pendingCatalog = null;
        _pendingBuyCatalogViews = null;
        Ui.PanelMinimized = false;
        PlayModeMusic("buy");
        PauseForNonLiveMode();
        Ui.Buy.ExitPluginView();
        Ui.Buy.ClearCategory(0);
        RequestBuyCatalogViews();
        RequestCatalog(category: 0, offset: 0);
    }

    private void ActivateBuildMode(bool allowDuringDialog = false)
    {
        if ((!allowDuringDialog && HasBlockingDialog) || BuyBuildLocked)
        {
            return;
        }

        DismissMenu();
        CloseCameraOverlay();
        CloseOptionsOverlay();
        Ui.BuyMode = false;
        _pendingCatalog = null;
        Ui.BuildMode = true;
        EditingViewChanged();
        _pendingBuildCatalog = null;
        Ui.PanelMinimized = false;
        PlayModeMusic("build");
        PauseForNonLiveMode();
        Ui.Build.ChangeKind(BuildCatalogPage.CatalogKind.Floor);
        RequestBuildCatalog(offset: 0);
    }

    private void EnsureSimlessEditingMode()
    {
        if (!SimlessBuildMode
            || Bridge is null
            || (_currentHouse ?? 0) <= 0
            || _pendingHouseholdCreation is not null
            || (Renderer.SceneRoot ?? Bridge.Session) is null
            || _canvas.Width <= 1
            || _canvas.Height <= 1
            || !IsInLiveMode)
        {
            return;
        }

        ActivateBuyMode(allowDuringDialog: true);
    }

    private void RestoreSimlessEditingMode()
    {
        if (_simlessResumeBuildMode)
        {
            ActivateBuildMode(allowDuringDialog: true);
        }
        else
        {
            ActivateBuyMode(allowDuringDialog: true);
        }
    }

    public void BrowseBuyCatalog()
    {
        if (HasBlockingDialog)
        {
            return;
        }

        if (BuyBuildLocked)
        {
            PlayUISound("ui_error");
            return;
        }

        if (SimlessBuildMode && Ui.BuyMode)
        {
            return;
        }

        if (!Ui.BuyMode)
        {
            ActivateBuyMode();
            return;
        }

        DismissMenu();
        CloseCameraOverlay();
        CloseOptionsOverlay();
        Ui.BuildMode = false;
        _pendingBuildCatalog = null;
        Ui.BuyMode = false;
        EditingViewChanged();
        _pendingCatalog = null;
        _pendingBuyCatalogViews = null;
        Ui.PanelMinimized = false;
        ResumeLiveMode();
    }

    public void BrowseBuildCatalog()
    {
        if (HasBlockingDialog)
        {
            return;
        }

        if (BuyBuildLocked)
        {
            PlayUISound("ui_error");
            return;
        }

        if (SimlessBuildMode && Ui.BuildMode)
        {
            return;
        }

        if (!Ui.BuildMode)
        {
            ActivateBuildMode();
            return;
        }

        DismissMenu();
        CloseCameraOverlay();
        CloseOptionsOverlay();
        Ui.BuyMode = false;
        _pendingCatalog = null;
        Ui.BuildMode = false;
        EditingViewChanged();
        _pendingBuildCatalog = null;
        Ui.PanelMinimized = false;
        ResumeLiveMode();
    }

    private void EditingViewChanged() =>
        _ = Send("view", new Dictionary<string, object?> { ["editing"] = Ui.BuyMode || Ui.BuildMode });

    private static string BuildCatalogKindRawValue(BuildCatalogPage.CatalogKind kind) => kind switch
    {
        BuildCatalogPage.CatalogKind.Floor => "floor",
        BuildCatalogPage.CatalogKind.Wall => "wall",
        BuildCatalogPage.CatalogKind.WallStyle => "wallStyle",
        BuildCatalogPage.CatalogKind.Water => "water",
        BuildCatalogPage.CatalogKind.Roof => "roof",
        _ => throw new ArgumentOutOfRangeException(nameof(kind), kind, null),
    };

    private void RequestBuildCatalog(int offset)
    {
        int count = Ui.Build.ObjectTool is null && Ui.Build.Kind == BuildCatalogPage.CatalogKind.Roof
            ? OriginalBuildOverlay.RoofCapacity(LogicalCanvas)
            : OriginalBuildLayout.Capacity(LogicalCanvas);
        if (Ui.Build.ObjectTool is { } objectTool && objectTool.Category() is int category)
        {
            _pendingBuildCatalog = Send("catalogPage", new Dictionary<string, object?>
            {
                ["category"] = category,
                ["offset"] = offset,
                ["count"] = count,
            });
        }
        else
        {
            _pendingBuildCatalog = Send("buildCatalogPage", new Dictionary<string, object?>
            {
                ["kind"] = BuildCatalogKindRawValue(Ui.Build.Kind),
                ["offset"] = offset,
                ["count"] = count,
            });
        }
    }

    private void RequestCatalog(int category, int? room = null, int? subsort = null, int offset = 0)
    {
        var request = new Dictionary<string, object?>
        {
            ["category"] = category,
            ["offset"] = offset,
            ["count"] = OriginalBuyLayout.Capacity(LogicalCanvas, Ui.Buy.PluginViews.Count),
        };
        if (room is int roomVal)
        {
            request["room"] = roomVal;
        }

        if (subsort is int subsortVal)
        {
            request["subsort"] = subsortVal;
        }

        _pendingCatalog = Send("catalogPage", request);
    }

    private void RequestBuyCatalogViews()
    {
        _pendingBuyCatalogViews = Send("buyCatalogViews", new Dictionary<string, object?>());
    }

    private void RequestPluginCatalog(string packId, string tabId, string collectionId, int offset = 0)
    {
        _pendingCatalog = Send("catalogPage", new Dictionary<string, object?>
        {
            ["pluginPackId"] = packId,
            ["pluginTabId"] = tabId,
            ["pluginCollectionId"] = collectionId,
            ["offset"] = offset,
            ["count"] = OriginalBuyLayout.Capacity(LogicalCanvas, Ui.Buy.PluginViews.Count),
        });
    }

    public void SelectStory(int level, bool? doorWindowTool = null)
    {
        if (HasBlockingDialog)
        {
            return;
        }

        if (level < 1 || level > Renderer.StoryCount || (level == EffectiveViewLevel && !EffectiveRoofsVisible && doorWindowTool is null))
        {
            PlayUISound("ui_error");
            return;
        }

        DismissMenu();
        Ui.Buy.Selection.Cancel();
        try { Renderer.UpdateFloorBrush(null); } catch { }
        _pendingViewLevel = level;
        _pendingRoofsVisible = false;
        _pendingViewSceneRevision = null;
        var payload = new Dictionary<string, object?>
        {
            ["value"] = level,
            ["roofs"] = false,
            ["wallpaperTool"] = WallpaperToolActive,
        };
        if (doorWindowTool is bool isDoorWindow)
        {
            payload["doorWindowTool"] = isDoorWindow;
        }

        _pendingViewRequestID = Send("level", payload);
    }

    public void NextSim()
    {
        DismissMenu();
        if (_simIDs.Count == 0)
        {
            return;
        }

        int current = _simIDs.IndexOf(_selectedSim);
        int next = _simIDs[(current + 1) % _simIDs.Count];
        _selectedSim = next;
        RequestAutoCenterOnSelection();
        _ = Send("selectSim", new Dictionary<string, object?> { ["objectID"] = next });
    }

    private void RequestAutoCenterOnSelection(bool playErrorSound = true)
    {
        if (!Ui.OptionsPanel.PlayOptions.AutoCenter)
        {
            if (playErrorSound)
            {
                PlayUISound("ui_error");
            }
            return;
        }

        _centresOnSelectedSim = true;
    }

    private void RecordButton(int? image = null, int? person = null)
    {
        if (!UsesNativeEngine || !HasActiveLot)
        {
            return;
        }

        var payload = new Dictionary<string, object?>();
        if (image is int imageID)
        {
            payload["image"] = imageID;
        }

        if (person is int personID)
        {
            payload["objectID"] = personID;
        }

        _ = Send("uiButton", payload);
    }

    public void ToggleWalls()
    {
        DismissTransientMenu();
        _lastCutawayTile = null;
        _desiredCutaway = null;
        string mode = EffectiveWallMode == "up" ? "down" : "up";
        _pendingWallMode = mode;
        _pendingRoofsVisible = false;
        _pendingViewSceneRevision = null;
        _pendingViewRequestID = Send("walls", new Dictionary<string, object?> { ["mode"] = mode });
    }

    public void RotateCamera(int delta)
    {
        int current = _pendingCameraOrientation ?? (int)Renderer.CameraOrientation;
        int next = ((current + delta) % 4 + 4) % 4;
        _pendingCameraOrientation = next;
        _pendingViewSceneRevision = null;
        _pendingViewRequestID = Send("cameraOrientation", new Dictionary<string, object?> { ["value"] = next });
    }

    public void UniversalControl(OriginalUniversalControl.Action action)
    {
        if (action == OriginalUniversalControl.Action.Help)
        {
            SetHelpVisible(true);
            return;
        }

        switch (action)
        {
            case OriginalUniversalControl.Action.Live:
                if (SimlessBuildMode)
                {
                    PlayUISound("ui_error");
                    return;
                }

                _tutorialLiveModeClicked = true;
                bool wasNonLive = !IsInLiveMode;
                CloseCameraOverlay();
                CloseOptionsOverlay();
                if (wasNonLive)
                {
                    Ui.PanelMinimized = false;
                }

                if (Ui.BuyMode)
                {
                    BrowseBuyCatalog();
                }
                else if (Ui.BuildMode)
                {
                    BrowseBuildCatalog();
                }
                else if (wasNonLive)
                {
                    ResumeLiveMode();
                }
                else
                {
                    Ui.PanelMinimized = !Ui.PanelMinimized;
                    Ui.Gameplay.ClearHoverPopups();
                }
                break;

            case OriginalUniversalControl.Action.Buy:
                if (BuyBuildLocked)
                {
                    PlayUISound("ui_error");
                    return;
                }

                Ui.PanelMinimized = false;
                CloseCameraOverlay();
                CloseOptionsOverlay();
                if (!Ui.BuyMode)
                {
                    BrowseBuyCatalog();
                }
                else
                {
                    Ui.Buy.ToggleMode();
                    _pendingCatalog = null;
                    if (Ui.Buy.RoomMode)
                    {
                        RequestCatalog(category: -1, room: Ui.Buy.Room, offset: 0);
                    }
                    else
                    {
                        RequestCatalog(category: Ui.Buy.Category, offset: 0);
                    }
                }
                break;

            case OriginalUniversalControl.Action.Build:
                if (BuyBuildLocked)
                {
                    PlayUISound("ui_error");
                    return;
                }

                Ui.PanelMinimized = false;
                CloseCameraOverlay();
                CloseOptionsOverlay();
                if (!Ui.BuildMode)
                {
                    BrowseBuildCatalog();
                }
                break;

            case OriginalUniversalControl.Action.ZoomIn:
            case OriginalUniversalControl.Action.ZoomOut:
                DismissTransientMenu();
                Renderer.SetZoom(Renderer.Zoom.Stepped(
                    action == OriginalUniversalControl.Action.ZoomIn ? 1 : -1));
                break;

            case OriginalUniversalControl.Action.WallsUp:
            case OriginalUniversalControl.Action.WallsDown:
            case OriginalUniversalControl.Action.WallsCutaway:
                DismissTransientMenu();
                _desiredCutaway = null;
                string mode = action == OriginalUniversalControl.Action.WallsUp
                    ? "up"
                    : action == OriginalUniversalControl.Action.WallsCutaway
                        ? "cutaway"
                        : "down";
                _pendingWallMode = mode;
                _pendingRoofsVisible = false;
                _pendingViewSceneRevision = null;
                bool wallpaperTool = WallpaperToolActive;
                var wallsPayload = new Dictionary<string, object?>
                {
                    ["mode"] = mode,
                    ["wallpaperTool"] = wallpaperTool,
                };
                if (mode == "cutaway" && Pointer is { } cutawayPointer && ResolveCutawayTile(cutawayPointer) is { } cwTile)
                {
                    int cutawayZoom = (int)Renderer.Zoom.AssetZoom();
                    wallsPayload["x"] = cwTile.X;
                    wallsPayload["y"] = cwTile.Y;
                    wallsPayload["zoom"] = cutawayZoom;
                    _lastCutawayTile = CutawayKey(cwTile, wallpaperTool, EffectiveViewLevel, cutawayZoom);
                }
                else
                {
                    _lastCutawayTile = null;
                }
                _pendingViewRequestID = Send("walls", wallsPayload);
                break;

            case OriginalUniversalControl.Action.Roofs:
                DismissTransientMenu();
                bool visible = !EffectiveRoofsVisible;
                _pendingRoofsVisible = visible;
                var payload = new Dictionary<string, object?> { ["visible"] = visible };
                if (visible)
                {
                    _pendingWallMode = "up";
                    if (Renderer.StoryCount > 1)
                    {
                        _pendingViewLevel = Renderer.StoryCount;
                        payload["level"] = Renderer.StoryCount;
                    }
                }

                _pendingViewSceneRevision = null;
                _pendingViewRequestID = Send("roofs", payload);
                break;

            case OriginalUniversalControl.Action.Story1:
                SelectStory(1);
                break;

            case OriginalUniversalControl.Action.Story2:
                SelectStory(2);
                break;

            case OriginalUniversalControl.Action.CameraLeft:
                RotateCamera(-1);
                break;

            case OriginalUniversalControl.Action.CameraRight:
                RotateCamera(1);
                break;

            case OriginalUniversalControl.Action.Options:
                if (Ui.OptionsMode)
                {
                    LeaveOptionsMode();
                }
                else
                {
                    EnterOptionsMode();
                }
                break;

            case OriginalUniversalControl.Action.Help:
                break;
        }
    }

    private void SetHelpVisible(bool visible)
    {
        if (Ui.HelpVisible == visible)
        {
            return;
        }

        Ui.HelpVisible = visible;
        SyncSimulatorBlock();
    }

    public void SetWindowActive(bool active)
    {
        if (_windowActive == active)
        {
            return;
        }

        _windowActive = active;
        SyncSimulatorBlock();
    }

    private void SyncSimulatorBlock()
    {
        bool blocked = Ui.HelpVisible || (!_windowActive && !Ui.OptionsPanel.PlayOptions.SimInBackground);
        _ = Send("blockSimulator", new Dictionary<string, object?> { ["blocked"] = blocked });
    }

    private void StepWallView(int delta)
    {
        OriginalUniversalControl.Action[] views =
        [
            OriginalUniversalControl.Action.WallsDown,
            OriginalUniversalControl.Action.WallsCutaway,
            OriginalUniversalControl.Action.WallsUp,
            OriginalUniversalControl.Action.Roofs,
        ];
        int current = EffectiveRoofsVisible ? 3 : EffectiveWallMode == "down" ? 0 : EffectiveWallMode == "cutaway" ? 1 : 2;
        int next = Math.Clamp(current + delta, 0, views.Length - 1);
        if (next == current)
        {
            PlayUISound("ui_error");
            return;
        }

        UniversalControl(views[next]);
    }

    private void CloseCameraOverlay()
    {
        if (!Ui.Camera.Visible)
        {
            return;
        }

        Ui.Album.Close();
        Ui.Camera.Visible = false;
        PendingPhoto = null;
        _pendingPhotoIsAutomatic = false;
    }

    private void EnterCameraMode()
    {
        if (HasBlockingDialog || Ui.Album.Visible || !Ui.ShowsLot)
        {
            return;
        }

        if (Ui.Camera.Visible)
        {
            LeaveCameraMode();
            return;
        }

        Ui.PanelMinimized = false;
        DismissMenu();
        CloseOptionsOverlay();
        if (Ui.BuyMode || Ui.BuildMode)
        {
            _simlessResumeBuildMode = Ui.BuildMode;
            Ui.BuyMode = false;
            _pendingCatalog = null;
            Ui.BuildMode = false;
            _pendingBuildCatalog = null;
            EditingViewChanged();
        }

        PauseForNonLiveMode();
        Ui.Camera.Visible = true;
        PlayModeMusic("camera");
    }

    private void LeaveCameraMode()
    {
        if (!Ui.Camera.Visible)
        {
            return;
        }

        CloseCameraOverlay();
        if (SimlessBuildMode)
        {
            RestoreSimlessEditingMode();
        }
        else
        {
            ResumeLiveMode();
        }
    }

    public bool PrepareFrameCapture()
    {
        UpdatePictureInPictureCaptureState();
        return PendingPhoto is not null || _pipNeedsCapture;
    }

    private static (byte[] Pixels, int Width, int Height) Crop(byte[] pixels, int width, int height, CGRect rect)
    {
        int x = Math.Max(0, (int)rect.MinX);
        int y = Math.Max(0, (int)rect.MinY);
        int w = Math.Min((int)rect.Width, width - x);
        int h = Math.Min((int)rect.Height, height - y);
        if (w <= 0 || h <= 0 || pixels.Length != width * height * 4)
        {
            throw new ContentError("Invalid camera frame");
        }

        byte[] cropped = new byte[w * h * 4];
        int rowBytes = w * 4;
        for (int row = 0; row < h; row++)
        {
            Buffer.BlockCopy(pixels, ((y + row) * width + x) * 4, cropped, row * rowBytes, rowBytes);
        }

        return (cropped, w, h);
    }

    private static byte[] ScaleRGBA(byte[] pixels, int srcW, int srcH, int dstW, int dstH)
    {
        if (dstW <= 0 || dstH <= 0 || srcW <= 0 || srcH <= 0 || pixels.Length != srcW * srcH * 4)
        {
            return pixels;
        }

        if (srcW == dstW && srcH == dstH)
        {
            return pixels;
        }

        byte[] scaled = new byte[dstW * dstH * 4];
        for (int y = 0; y < dstH; y++)
        {
            int sy = Math.Min(srcH - 1, y * srcH / dstH);
            for (int x = 0; x < dstW; x++)
            {
                int sx = Math.Min(srcW - 1, x * srcW / dstW);
                int sIdx = (sy * srcW + sx) * 4;
                int dIdx = (y * dstW + x) * 4;
                scaled[dIdx] = pixels[sIdx];
                scaled[dIdx + 1] = pixels[sIdx + 1];
                scaled[dIdx + 2] = pixels[sIdx + 2];
                scaled[dIdx + 3] = pixels[sIdx + 3];
            }
        }

        return scaled;
    }

    public void CapturePhoto(byte[] pixels, int width, int height)
    {
        if (_pipNeedsCapture)
        {
            _pipNeedsCapture = false;
            CapturePictureInPictureFrame();
        }

        if (PendingPhoto is not { } rect)
        {
            return;
        }

        bool automatic = _pendingPhotoIsAutomatic;
        string? caption = _pendingPhotoCaption;
        PendingPhoto = null;
        _pendingPhotoIsAutomatic = false;
        _pendingPhotoCaption = null;
        try
        {
            var frame = Crop(pixels, width, height, rect);
            int targetW = Math.Max(1, (int)Math.Round(rect.Width / Scale, MidpointRounding.AwayFromZero));
            int targetH = Math.Max(1, (int)Math.Round(rect.Height / Scale, MidpointRounding.AwayFromZero));
            byte[] finalPixels = ScaleRGBA(frame.Pixels, frame.Width, frame.Height, targetW, targetH);
            var album = new PhotoAlbum(Path.Combine(NeighborhoodUserData, "PhotoAlbum"));
            float[] qualities = [0.2f, 0.5f, 0.9f];
            float quality = qualities[Math.Clamp(Ui.Camera.Quality, 0, qualities.Length - 1)];
            _ = album.Capture(finalPixels, targetW, targetH, quality, caption ?? Strings.AlbumDescription());
            if (!automatic)
            {
                PlayUISound("ui_camera_photo");
            }
        }
        catch (Exception error)
        {
            if (!automatic)
            {
                PresentLocalFeedback("Photo Album", "Could not save this photo.");
            }

            Log($"Camera: {error}");
        }
    }

    private void AlbumAction(OriginalPhotoAlbumOverlay.Action action)
    {
        if (action == OriginalPhotoAlbumOverlay.Action.Delete)
        {
            PresentLocalConfirmation(
                Strings.Album(20, "Delete Photo?"),
                Strings.Album(21, "Are you sure you want to delete this photo?"),
                Strings.YesButton(),
                Strings.NoButton(),
                response: code =>
                {
                    if (code != 0)
                    {
                        return;
                    }

                    try
                    {
                        Ui.Album.Perform(OriginalPhotoAlbumOverlay.Action.Delete);
                        PlayUISound("ui_click");
                    }
                    catch
                    {
                        PresentLocalFeedback("Photo Album", "Could not delete this photo.");
                    }
                });
        }
        else
        {
            try
            {
                Ui.Album.Perform(action);
                PlayUISound("ui_click");
            }
            catch
            {
                PresentLocalFeedback("Photo Album", "Could not open this photo.");
            }
        }
    }

    private void CloseOptionsOverlay()
    {
        if (!Ui.OptionsMode)
        {
            return;
        }

        Ui.OptionsMode = false;
        Ui.OptionsPanel.Select(OriginalOptionsPanelOverlay.Page.None);
        if (Ui.SoundOptions.IsEmbedded)
        {
            Ui.SoundOptions.Dismiss();
        }
    }

    public void EnterOptionsMode()
    {
        if (HasBlockingDialog)
        {
            return;
        }

        Ui.PanelMinimized = false;
        DismissMenu();
        CloseCameraOverlay();
        if (Ui.BuyMode || Ui.BuildMode)
        {
            _simlessResumeBuildMode = Ui.BuildMode;
            Ui.BuyMode = false;
            _pendingCatalog = null;
            Ui.BuildMode = false;
            _pendingBuildCatalog = null;
            EditingViewChanged();
        }

        Ui.OptionsPanel.Select(OriginalOptionsPanelOverlay.Page.None);
        Ui.OptionsMode = true;
        PlayUISound("ui_click");
        PauseForNonLiveMode();
        PlayModeMusic("options");
    }

    public void LeaveOptionsMode()
    {
        if (!Ui.OptionsMode)
        {
            return;
        }

        CloseOptionsOverlay();
        if (SimlessBuildMode)
        {
            RestoreSimlessEditingMode();
        }
        else
        {
            ResumeLiveMode();
        }
    }

    private void SendAudioVolume(OriginalSoundOptionsOverlay.VolumeChange change)
    {
        string? id = Send("audioVolume", new Dictionary<string, object?>
        {
            ["group"] = change.Group,
            ["volume"] = change.Volume,
        });
        if (id is null)
        {
            Ui.SoundOptions.Restore(change);
            return;
        }

        _pendingAudioVolumes[id] = change;
        _latestAudioVolumeRequest[change.Group] = id;
        if (string.Equals(change.Group, "AMBIENCE", StringComparison.OrdinalIgnoreCase))
        {
            _audio?.SetAmbientMasterVolume(change.Volume);
        }
    }

    private void ChooseOption(OriginalOptionsPanelOverlay.Button button)
    {
        PlayUISound("ui_click");
        switch (button)
        {
            case OriginalOptionsPanelOverlay.Button.Save:
                SaveGame();
                break;

            case OriginalOptionsPanelOverlay.Button.Sound:
                if (Ui.OptionsPanel.CurrentPage == OriginalOptionsPanelOverlay.Page.Sound)
                {
                    Ui.SoundOptions.HideEmbedded();
                    Ui.OptionsPanel.Select(OriginalOptionsPanelOverlay.Page.None);
                }
                else
                {
                    bool hadActivePage = Ui.OptionsPanel.CurrentPage != OriginalOptionsPanelOverlay.Page.None;
                    Ui.SoundOptions.ShowEmbedded(OriginalOptionsPanelOverlay.SoundRows(Strings), afterFadeOut: hadActivePage);
                    Ui.OptionsPanel.Select(OriginalOptionsPanelOverlay.Page.Sound);
                    _pendingAudioState = Send("audioState");
                }
                break;

            case OriginalOptionsPanelOverlay.Button.Neighborhood:
                if (LotSaveDisabled)
                {
                    if (!_simlessBuildMode)
                    {
                        var (title, message) = Strings.AwayLeaveWithoutSavingConfirmation(
                            _currentHouse ?? Options.House ?? 0,
                            _lastLotTransitInfo);
                        PresentLocalConfirmation(
                            title,
                            message,
                            Strings.YesButton(),
                            Strings.NoButton(),
                            response: code =>
                            {
                                if (code != 0)
                                {
                                    return;
                                }

                                ReturnToNeighborhood(saving: false);
                            });
                        break;
                    }

                    ReturnToNeighborhood(saving: false);
                    break;
                }

                PresentLocalConfirmation(
                    Strings.SaveMenuTitle(),
                    Strings.SaveConfirmationMessage(),
                    Strings.YesButton(),
                    Strings.NoButton(),
                    Strings.CancelButton(),
                    code =>
                    {
                        if (code > 1)
                        {
                            return;
                        }

                        ReturnToNeighborhood(saving: code == 0);
                    });
                break;

            case OriginalOptionsPanelOverlay.Button.Quit:
                ConfirmQuit();
                break;

            case OriginalOptionsPanelOverlay.Button.ResetTutorial:
                PresentLocalConfirmation(
                    Strings.ResetTutorialTitle(),
                    Strings.ResetTutorialMessage(),
                    Strings.YesButton(),
                    Strings.NoButton(),
                    response: code =>
                    {
                        if (code != 0)
                        {
                            return;
                        }

                        _pendingResetTutorialState = Send("tutorialResetState");
                    });
                break;

            case OriginalOptionsPanelOverlay.Button.Play:
            case OriginalOptionsPanelOverlay.Button.Graphics:
                var target = button == OriginalOptionsPanelOverlay.Button.Play
                    ? OriginalOptionsPanelOverlay.Page.Play
                    : OriginalOptionsPanelOverlay.Page.Graphics;
                if (Ui.SoundOptions.IsEmbedded)
                {
                    Ui.SoundOptions.HideEmbedded();
                }

                if (target == OriginalOptionsPanelOverlay.Page.Graphics)
                {
                    Ui.OptionsPanel.HasLightingSettings = PluginPanels.Any(p =>
                        string.Equals(p.Description.Id, "lighting-settings", StringComparison.Ordinal));
                    if (Ui.OptionsPanel.HasLightingSettings)
                    {
                        _ = Send("pluginPanels");
                    }
                }

                Ui.OptionsPanel.Select(Ui.OptionsPanel.CurrentPage != target ? target : OriginalOptionsPanelOverlay.Page.None);
                break;
        }
    }

    private string NeighborhoodUserData =>
        Path.Combine(
            Options.DataRoot ?? Workspace,
            "runtime",
            "profiles",
            Options.Profile,
            $"UserData{(_currentNeighborhood == 1 ? string.Empty : _currentNeighborhood.ToString(CultureInfo.InvariantCulture))}");

    private void CopyTutorialToImport()
    {
        string imports = Path.Combine(NeighborhoodUserData, "Import");
        Directory.CreateDirectory(imports);
        string @base = Path.Combine(Options.DataRoot ?? Workspace, "runtime", "profiles", Options.Profile, "UserData", "Tutorial.FAM");
        string source = File.Exists(@base) ? @base : Path.Combine(Content.Root, "UserData", "Tutorial.FAM");
        TutorialReset.Copy(source, imports);
    }

    private void FinishResetTutorial()
    {
        try
        {
            CopyTutorialToImport();
            ReturnToNeighborhood(saving: false, mode: 1);
        }
        catch (Exception error)
        {
            Log($"Reset Tutorial: {error}");
            PresentLocalFeedback(Strings.ResetTutorialTitle(), Strings.ResetTutorialFailedMessage());
        }
    }

    private void OfferResetTutorialSave()
    {
        PresentLocalConfirmation(
            Strings.SaveMenuTitle(),
            Strings.SaveConfirmationMessage(),
            Strings.YesButton(),
            Strings.NoButton(),
            Strings.CancelButton(),
            save =>
            {
                if (save > 1)
                {
                    return;
                }

                if (save == 0)
                {
                    if (LotSaveDisabled)
                    {
                        FinishResetTutorial();
                        return;
                    }

                    SendSaveRequest(succeeded =>
                    {
                        if (!succeeded)
                        {
                            return;
                        }

                        FinishResetTutorial();
                    });
                }
                else
                {
                    FinishResetTutorial();
                }
            });
    }

    private string PlayOptionsURL =>
        Path.Combine(
            Options.DataRoot ?? Path.Combine(Options.Workspace ?? InstallLocator.DefaultWorkspace(), "runtime", "data"),
            "Settings",
            "options.json");

    public void LoadPlayOptions()
    {
        var loadedOptions = Ui.OptionsPanel.PlayOptions;
        try
        {
            if (File.Exists(PlayOptionsURL))
            {
                byte[] data = File.ReadAllBytes(PlayOptionsURL);
                if (JsonSerializer.Deserialize<OriginalOptionsPanelOverlay.PlayOptionsState?>(data) is { } parsed)
                {
                    loadedOptions = parsed;
                }
            }
        }
        catch
        {
        }

        if (Options.EdgeScroll is bool cliEdgeScroll)
        {
            loadedOptions.EdgeScrolling = cliEdgeScroll;
        }

        if (Options.AutoCenter is bool cliAutoCenter)
        {
            loadedOptions.AutoCenter = cliAutoCenter;
        }

        Ui.OptionsPanel.PlayOptions = loadedOptions;
        Ui.ApplySharpText(loadedOptions.SharpText);
        Ui.SoundOptions.InterfaceEffectsEnabled = loadedOptions.InterfaceEffects;
        _centresOnSelectedSim = loadedOptions.AutoCenter;
        Renderer.LightingEnabled = loadedOptions.Lighting && Options.Lighting;
        Renderer.AntiAliasedSprites = loadedOptions.AntiAlias;
        Renderer.ShadowsEnabled = loadedOptions.Shadows;
        Renderer.TerrainDetail = loadedOptions.Detail(OriginalOptionsPanelOverlay.DetailSetting.Terrain);
        Renderer.CharacterDetail = loadedOptions.Detail(OriginalOptionsPanelOverlay.DetailSetting.Character);
    }

    private void TogglePlayOption(OriginalOptionsPanelOverlay.PlayOption option)
    {
        var updated = option.Toggled(Ui.OptionsPanel.PlayOptions);
        if (option == OriginalOptionsPanelOverlay.PlayOption.AutoCenter && !updated.AutoCenter)
        {
            _centresOnSelectedSim = false;
        }

        SavePlayOptions(updated);
    }

    private void SetDetail(OriginalOptionsPanelOverlay.DetailSetting setting, int level)
    {
        var updated = Ui.OptionsPanel.PlayOptions;
        switch (setting)
        {
            case OriginalOptionsPanelOverlay.DetailSetting.Terrain:
                updated.TerrainDetail = level;
                break;

            case OriginalOptionsPanelOverlay.DetailSetting.Character:
                updated.CharacterDetail = level;
                break;
        }

        SavePlayOptions(updated);
    }

    private void SavePlayOptions(OriginalOptionsPanelOverlay.PlayOptionsState updated)
    {
        Ui.OptionsPanel.PlayOptions = updated;
        Ui.ApplySharpText(updated.SharpText);
        _neighborhoodBeforeHouseholdCreation?.ClearTextCaches();
        Ui.SoundOptions.InterfaceEffectsEnabled = updated.InterfaceEffects;
        try
        {
            string directory = Path.GetDirectoryName(PlayOptionsURL)!;
            Directory.CreateDirectory(directory);
            byte[] encoded = JsonSerializer.SerializeToUtf8Bytes(updated);
            string temp = Path.Combine(directory, $".options.{Guid.NewGuid():N}.tmp");
            try
            {
                File.WriteAllBytes(temp, encoded);
                File.Move(temp, PlayOptionsURL, overwrite: true);
            }
            finally
            {
                if (File.Exists(temp))
                {
                    try { File.Delete(temp); } catch { }
                }
            }
        }
        catch (Exception error)
        {
            Log($"Play options: {error}");
        }

        PlayUISound("ui_click");
        ApplyPlayOptions();
        Renderer.LightingEnabled = updated.Lighting && Options.Lighting;
        Renderer.AntiAliasedSprites = updated.AntiAlias;
        Renderer.ShadowsEnabled = updated.Shadows;
        Renderer.TerrainDetail = updated.Detail(OriginalOptionsPanelOverlay.DetailSetting.Terrain);
        Renderer.CharacterDetail = updated.Detail(OriginalOptionsPanelOverlay.DetailSetting.Character);
        SyncSimulatorBlock();
    }

    public void ApplyPlayOptions()
    {
        _ = Send("freeWill", new Dictionary<string, object?> { ["enabled"] = Ui.OptionsPanel.PlayOptions.FreeWill });
        _ = Send("pictureInPicture", new Dictionary<string, object?> { ["live"] = Ui.OptionsPanel.PlayOptions.LivePIP });
    }

    public void SaveGame()
    {
        if (Ui.GameDialog is not null || LotSaveDisabled)
        {
            return;
        }

        DismissMenu();
        PresentLocalConfirmation(
            Strings.SaveHouseTitle(),
            Strings.SaveConfirmationMessage(),
            Strings.YesButton(),
            Strings.NoButton(),
            response: code =>
            {
                if (code != 0)
                {
                    return;
                }

                SendSaveRequest();
            });
    }

    private void SendSaveRequest(Action<bool>? completion = null)
    {
        string? id = Send("save", new Dictionary<string, object?> { ["slot"] = "manual", ["lot"] = true });
        if (id is null)
        {
            PresentLocalFeedback(Strings.SaveHouseTitle(), Strings.SaveFailedMessage());
            completion?.Invoke(false);
            return;
        }

        _pendingSaveRequests.Add(id);
        if (completion is not null)
        {
            _pendingSaveCompletions[id] = completion;
        }
    }

    public void LoadGame()
    {
        if (Ui.GameDialog is not null)
        {
            return;
        }

        DismissMenu();
        PresentLocalConfirmation(
            Strings.LoadHouseTitle(),
            Strings.LoadConfirmationMessage(),
            Strings.YesButton(),
            Strings.NoButton(),
            response: code =>
            {
                if (code != 0)
                {
                    return;
                }

                SendLoad(removingPacks: false);
            });
    }

    private void SendLoad(bool removingPacks)
    {
        var parameters = new Dictionary<string, object?> { ["slot"] = "manual" };
        if (removingPacks)
        {
            parameters["removePacks"] = true;
        }

        string? id = Send("load", parameters);
        if (id is null)
        {
            PresentLocalFeedback(Strings.LoadHouseTitle(), Strings.LoadFailedMessage());
            return;
        }

        _pendingLoadRequests.Add(id);
    }

    private void ConfirmPackRemoval(IReadOnlyList<string> packs)
    {
        string names = string.Join(
            ", ",
            packs.Select(p => p.Split('@', StringSplitOptions.RemoveEmptyEntries).FirstOrDefault() ?? p));
        PresentLocalConfirmation(
            Strings.LoadHouseTitle(),
            $"This house uses custom content that is not installed: {names}. Load it anyway? "
            + "Objects from that content will be removed and refunded. A backup of the save is kept.",
            Strings.YesButton(),
            Strings.NoButton(),
            response: code =>
            {
                if (code != 0)
                {
                    return;
                }

                SendLoad(removingPacks: true);
            });
    }

    private void PresentLocalFeedback(string title, string message)
    {
        if (Ui.GameDialog is not null)
        {
            return;
        }

        string token = "native-storage-" + Guid.NewGuid().ToString("D").ToUpperInvariant();
        try
        {
            Ui.GameDialog = new OriginalDialogOverlay(
                GameDialog.LocalFeedback(token, title, message, Strings.OkButton()),
                Ui.Font,
                Ui.Device,
                Ui.Content);
            _localDialogToken = token;
            _localDialogResponse = null;
        }
        catch (Exception error)
        {
            Log($"Dialog: {error}");
        }
    }

    private void PresentLocalConfirmation(
        string title,
        string message,
        string yes,
        string no,
        string? cancel = null,
        Action<byte>? response = null)
    {
        if (Ui.GameDialog is not null)
        {
            return;
        }

        string token = "native-storage-" + Guid.NewGuid().ToString("D").ToUpperInvariant();
        try
        {
            var dialog = GameDialog.LocalPrompt(
                token,
                title,
                message,
                kind: (byte)(cancel is null ? 1 : 2),
                yes,
                no,
                cancel);
            Ui.GameDialog = new OriginalDialogOverlay(dialog, Ui.Font, Ui.Device, Ui.Content);
            _localDialogToken = token;
            _localDialogResponse = response;
        }
        catch (Exception error)
        {
            Log($"Dialog: {error}");
        }
    }
}
