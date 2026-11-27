using System.Numerics;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using SimsSDL.Client;
using SimsSDL.UI;

namespace SimsSDL;

public sealed partial class LotRenderer : IDisposable
{
    public static readonly float OriginalUIBlue = (float)Math.Pow((82.0 / 255.0 + 0.055) / 1.055, 2.4);

    private const int MaxLamps = 16;

    private const int MaxCachedDynamicTextures = 256;

    private readonly record struct OrderedDrawEntry(
        int Level,
        int Layer,
        float Depth,
        bool IsMesh,
        int Index,
        SceneDrawItem Item)
    {
        public static int Compare(in OrderedDrawEntry a, in OrderedDrawEntry b, int spriteCount)
        {
            int cmp = a.Level.CompareTo(b.Level);
            if (cmp != 0)
            {
                return cmp;
            }

            cmp = a.Layer.CompareTo(b.Layer);
            if (cmp != 0)
            {
                return cmp;
            }

            cmp = a.Depth.CompareTo(b.Depth);
            if (cmp != 0)
            {
                return cmp;
            }

            int lhsOrdinal = a.IsMesh ? spriteCount + a.Index : a.Index;
            int rhsOrdinal = b.IsMesh ? spriteCount + b.Index : b.Index;
            return lhsOrdinal.CompareTo(rhsOrdinal);
        }
    }

    private readonly struct OrderedDrawEntryComparer(int spriteCount) : IComparer<OrderedDrawEntry>
    {
        public int Compare(OrderedDrawEntry x, OrderedDrawEntry y) => OrderedDrawEntry.Compare(in x, in y, spriteCount);
    }

    private readonly record struct MeshSlice(GPUBuffer Buffer, uint FirstVertex, uint VertexCount);

    private sealed class PreparedScene
    {
        public required LotScene Scene { get; init; }
        public required PickerAlphaMask[] Masks { get; init; }
        public required Dictionary<int, (int Width, int Height, bool Depth8, byte[] Pixels)> PreparedUploads { get; init; }
        public required Dictionary<int, GPUContext.SharedTextureKey> UploadKeys { get; init; }
        public required bool DeferredMasks { get; init; }
        public required List<SceneDrawItem> DrawItems { get; init; }
        public required Vector4[] AllMeshBounds { get; init; }
        public required Vector4[] StaticMeshBounds { get; init; }
        public GroundTilePicker? GroundPicker { get; init; }
    }

    private sealed class PreviewMeshes
    {
        public required List<GPUTexture> Textures { get; init; }
        public required List<GPUBuffer?> Buffers { get; init; }
        public required List<int> VertexCounts { get; init; }
        public required CGRect Bounds { get; init; }
        public float MaxTurntableSpan { get; init; }
    }

    private sealed record CachedObjectHit(
        Vector2 Point,
        Vector2 Canvas,
        LotZoom Zoom,
        float VisualZoomFactor,
        Vector2 Pan,
        long Revision,
        long Sequence,
        int? Result);

    private sealed record CachedWallHit(
        Vector2 Point,
        Vector2 Canvas,
        LotZoom Zoom,
        float VisualZoomFactor,
        Vector2 Pan,
        long Revision,
        long Sequence,
        LotScene.WallSide? Result);

    private struct PendingMeshBatch
    {
        public GPUContext.Program Program;
        public GPUContext.DepthMode Depth;
        public GPUTexture Texture;
        public nint Sampler;
        public GPUBuffer Buffer;
        public Vector4 Tint;
        public float UVRectX;
        public Vector3 SunDir;
        public uint FirstVertex;
        public uint VertexCount;
    }

    internal static Vector3 ResolveRoofSunDirection(bool ambientActive, Vector3 ambientSun, float nightFactor = 0f)
    {
        if (ambientActive)
        {
            var horiz = new Vector2(ambientSun.Y, ambientSun.Z);
            float hLen = horiz.Length();
            if (hLen > 0.05f)
            {
                const float invSqrt2 = 0.70710678f;
                float up = Math.Clamp(ambientSun.X, 0.25f, 0.78f);
                float targetHoriz = MathF.Sqrt(MathF.Max(0f, 1f - up * up));
                horiz *= targetHoriz / hLen;
                var sunDir = Vector3.Normalize(new Vector3(
                    (horiz.X + horiz.Y) * invSqrt2,
                    up,
                    (horiz.X - horiz.Y) * invSqrt2));
                if (nightFactor > 0.01f)
                {
                    return Vector3.Normalize(Vector3.Lerp(sunDir, Vector3.UnitY, Math.Clamp(nightFactor, 0f, 1f) * 0.78f));
                }

                return sunDir;
            }
        }

        return Vector3.Normalize(new Vector3(0.75f, 0.55f, -0.35f));
    }

    private enum SpritePassMode
    {
        Single,
        OpaqueCore,
        EdgeFringe,
    }

    public GPUContext GPU { get; }
    public LotScene? Scene { get; private set; }
    private List<PickerAlphaMask> _sceneMasks = [];
    private List<LotScene.Texture> _deferredPixelTextures = [];
    public string? SceneRoot { get; private set; }
    private long _sceneRevision;
    private long _animationSequence;
    private List<GPUTexture> _sceneTextures = [];
    public int BaseTextureCount { get; private set; }
    private Dictionary<string, int> _textureIndexByFile = new();
    private Dictionary<string, GPUTexture> _cachedTextures = new();
    private Dictionary<string, PickerAlphaMask> _cachedMasks = new();
    private readonly Dictionary<string, GPUTexture> _dynamicTextureCache = new();
    private readonly Dictionary<string, PickerAlphaMask> _dynamicMaskCache = new();
    private readonly List<string> _dynamicTextureOrder = [];
    private GPUBuffer? _terrainBuffer;
    private GPUBuffer? _surroundingsTerrain;
    private GPUBuffer? _surroundingsRoadBuffer;
    private List<(LotScene.Mesh Mesh, MeshSlice Slice)> _surroundingsRoads = [];
    private IReadOnlyList<LotScene.Sprite> _surroundingsDecorations = [];
    private IReadOnlyList<SimsNative.Plugins.PluginSceneryInstance> _surroundingsScenery = [];
    private int _surroundingsMargin;
    private List<MeshSlice?> _meshSlices = [];
    private readonly GPUBuffer?[] _dynamicMeshRing = new GPUBuffer?[3];
    private int _dynamicMeshRingSlot;
    private AvatarVertex[] _dynamicVertexScratch = [];
    private Vector4[] _meshBounds = [];
    private List<LotScene.Sprite> _staticSprites = [];
    private List<LotScene.Mesh> _staticMeshes = [];
    private int _staticSpriteCount;
    private int _staticMeshCount;
    private List<MeshSlice?> _staticMeshSlices = [];
    private Vector4[] _staticMeshBounds = [];
    private List<OrderedDrawEntry> _staticDrawEntries = [];
    private int[] _staticShadowSpriteIndices = [];
    private List<int> _activeShadowSpriteIndices = [];
    private List<int> _activeShadowSpriteIndicesScratch = [];
    private List<SceneDrawItem> _drawItems = [];
    private List<SceneDrawItem> _drawItemsScratch = [];
    private readonly List<LotScene.Mesh> _dynamicMeshesScratch = [];
    private readonly List<OrderedDrawEntry> _dynamicEntriesScratch = [];
    private readonly List<MeshSlice?> _dynamicSlicesScratch = [];

    private static bool HasFloorShadow(LotScene.Sprite sprite) =>
        sprite.Wall is null && (sprite.FloorShadow is not null || sprite.FloorShadowNear is not null || sprite.FloorShadowFar is not null);
    private ScenePicker? _picker;
    private bool _pickerDirty;
    private CachedObjectHit? _cachedObjectHit;
    private CachedWallHit? _cachedWallHit;
    private GroundTilePicker? _groundPicker;

    private TerrainVertex[] _placementVertices = [];
    private GPUBuffer? _placementBuffer;
    private TerrainVertex[] _upperPlacementVertices = [];
    private GPUBuffer? _upperPlacementBuffer;
    private bool _placementDirty;
    private BuildableArea? _buildableLevel1;
    private BuildableArea? _buildableLevel2;
    private GPUBuffer? _buildGridLevel1Buffer;
    private GPUBuffer? _buildGridLevel2Buffer;
    private bool _buildGridDirty;
    private AvatarVertex[] _floorBrushVertices = [];
    private GPUBuffer? _floorBrushBuffer;
    private bool _floorBrushDirty;
    private string? _floorBrushTextureKey;
    private (int Width, int Height, bool Depth8, byte[] Pixels)? _floorBrushPixels;
    private GPUTexture? _floorBrushTexture;
    private PlacementPreview.GhostData? _placementGhost;
    public bool? PlacementIsValid { get; private set; }
    private (int Width, int Height, bool Depth8, byte[] Pixels)[]? _ghostPixels;
    private IReadOnlyList<GPUTexture> _ghostTextures = [];
    private string[] _ghostTextureKeys = [];

    public PlacementPreview.GhostData? BuildCursor { get; private set; }
    private (int Width, int Height, bool Depth8, byte[] Pixels)[]? _buildCursorPixels;
    private IReadOnlyList<GPUTexture> _buildCursorTextures = [];
    private string[] _buildCursorTextureKeys = [];
    public PlacementPreview.GhostData? WallPaintPreview { get; private set; }
    private (int Width, int Height, bool Depth8, byte[] Pixels)[]? _wallPaintPixels;
    private IReadOnlyList<GPUTexture> _wallPaintTextures = [];
    private string[] _wallPaintTextureKeys = [];
    private readonly Dictionary<LotScene.WallSide, LotScene.Sprite> _wallPaintByWall = new();

    public bool ShowsPlacement { get; set; }
    public bool ShowsGhost { get; set; }
    public bool ShowsBuildCursor { get; set; }
    public bool LiveMode { get; set; }
    public bool SuppressControlPanelInset { get; set; }

    public int Speed { get; set; }
    public bool AmbientPaused { get; set; }
    public float UIScale { get; set; } = 2f;

    private LotZoom _zoom = LotZoom.Near;
    private float _visualZoomFactor = LotZoom.Near.Factor();

    private float TargetZoomFactor => _zoom.Factor();

    public LotZoom Zoom
    {
        get => _zoom;
        set
        {
            _zoom = value;
            _visualZoomFactor = value.Factor();
        }
    }

    public float VisualZoomFactor => _visualZoomFactor;
    public bool IsZoomInterpolating => MathF.Abs(_visualZoomFactor - TargetZoomFactor) > 1e-4f;

    private const float FarToMediumZoomMidpoint = 0.70710678f;
    private const float MediumToNearZoomMidpoint = 1.41421356f;

    public LotZoom EffectiveVisualZoom => !DrawsLot
        ? Zoom.AssetZoom()
        : _visualZoomFactor < FarToMediumZoomMidpoint
            ? LotZoom.Far
            : _visualZoomFactor < MediumToNearZoomMidpoint
                ? LotZoom.Medium
                : LotZoom.Near;

    internal LotZoom AssetZoomForScale(float scale, LotZoom fallback) => !DrawsLot
        ? fallback.AssetZoom()
        : AntiAliasedSprites
            ? (scale >= 0.55f ? LotZoom.Near : LotZoom.Medium)
            : (scale >= MediumToNearZoomMidpoint
                ? LotZoom.Near
                : scale >= FarToMediumZoomMidpoint
                    ? LotZoom.Medium
                    : LotZoom.Far);

    public void SnapVisualZoom(LotZoom zoom) => Zoom = zoom;

    internal (LotZoom Zoom, float VisualFactor) SaveVisualZoom() => (_zoom, _visualZoomFactor);

    internal void RestoreVisualZoom((LotZoom Zoom, float VisualFactor) saved)
    {
        _zoom = saved.Zoom;
        _visualZoomFactor = saved.VisualFactor;
    }

    public int TerrainDetail { get; set; } = 2;

    public int CharacterDetail { get; set; } = 2;

    public int PanAssignments { get; private set; }

    private Vector2 _pan = Vector2.Zero;
    public Vector2 Pan
    {
        get => _pan;
        set
        {
            PanAssignments = unchecked(PanAssignments + 1);
            _pan = Scene is not null
                ? SimsSDL.Core.SceneViewport.ClampedPan(value, Scene, MathF.Max(UIScale, 0.01f) * _visualZoomFactor)
                : value;
        }
    }

    public bool LightingEnabled { get; set; } = true;
    public bool AntiAliasedSprites { get; set; } = true;

    public List<UIDraw> Overlay { get; set; } = [];

    public bool DrawsLot { get; set; } = true;

    public (int Index, Dictionary<int, Vector4> Rects)? PreviewPlacement { get; set; }

    private const float PreviewTurntableAmplitudeRadians = MathF.PI * 0.25f;
    private const float PreviewTurntablePeriodSeconds = 10f;
    private bool _previewTurntableActive;
    private float _previewTurntableSeconds;

    public float PreviewTurntableYaw => _previewTurntableActive
        ? PreviewTurntableAmplitudeRadians * MathF.Sin(MathF.Tau * _previewTurntableSeconds / PreviewTurntablePeriodSeconds)
        : 0f;

    public void AdvancePreviewTurntable(float dtSeconds, bool active)
    {
        if (!active)
        {
            _previewTurntableActive = false;
            _previewTurntableSeconds = 0f;
            return;
        }

        if (!_previewTurntableActive)
        {
            _previewTurntableActive = true;
            _previewTurntableSeconds = 0f;
            return;
        }

        if (float.IsFinite(dtSeconds) && dtSeconds > 0f)
        {
            _previewTurntableSeconds = (_previewTurntableSeconds + dtSeconds) % PreviewTurntablePeriodSeconds;
        }
    }

    private readonly Dictionary<int, PreviewMeshes> _previews = new();
    private Dictionary<UITexture, (UITexture Source, int Version, GPUTexture Texture)> _uiTextures =
        new(ReferenceEqualityComparer.Instance);
    private Dictionary<UITexture, (UITexture Source, int Version, GPUTexture Texture)> _uiTexturesAlt =
        new(ReferenceEqualityComparer.Instance);
    private readonly List<UITexture> _uiUploadsScratch = [];
    private readonly HashSet<UITexture> _uiUploadSeenScratch = new(ReferenceEqualityComparer.Instance);
    private readonly HashSet<GPUTexture> _retainedUiScratch = new(ReferenceEqualityComparer.Instance);

    private int _sceneLoadsInFlight;
    private long _newestRequestedRevision;
    private long _sceneLoadEpoch;

    private List<SceneAnimation> _pendingFrames = [];

    public ClientPluginHost? ClientPlugins { get; private set; }
    public bool AmbientEnabled { get; set; } = true;
    public bool ShadowsEnabled { get; set; } = true;
    public int AmbientDebug { get; set; }
    public Vector3? SunOverride { get; set; }
    public float? TimeOverrideSeconds { get; set; }

    private const float HeightTexelsPerTile = 16f;
    private GPUTexture? _heightMapTexture;
    private float _heightMargin = 4f;
    private GPUTexture? _footMapTexture;
    private GPUTexture? _worldShadowColor;
    private GPUTexture? _worldShadowDepth;
    private GPUTexture? _worldShadowBackDepth;
    private GPUTexture? _worldShadowStaticDepth;
    private GPUTexture? _worldShadowStaticBackDepth;
    private LotScene? _worldShadowScene;
    private string _worldShadowStaticKey = string.Empty;
    private string _worldShadowKey = string.Empty;
    private long _worldShadowSpriteSeq;
    private ulong _lastDynamicSpriteHash;
    private long _worldShadowAnimSeq;
    private Vector4? _worldHeightFrame;
    private Vector4? _worldFootFrame;
    private SimsSDL.Core.SceneViewport? _worldShadowViewport;
    private enum ShadowItemFilter { All, StaticOnly, DynamicOnly }
    private GPUTexture? _overheadMap;
    private int _uploadedOverheadWidth;
    private int _uploadedOverheadHeight;
    private ulong _uploadedOverheadHash;
    private GPUTexture? _emptyOverhead;
    private GPUTexture? _voxelMap;
    private byte[]? _uploadedVoxelPixels;
    private int _uploadedVoxelWidth;
    private int _uploadedVoxelHeight;
    private ulong _uploadedVoxelHash;
    private bool _hasDynamicShadowSprites;
    private GPUTexture? _indoorMask;
    private int _uploadedIndoorWidth;
    private int _uploadedIndoorHeight;
    private ulong _uploadedIndoorHash;
    private float _indoorBase;
    private GPUTexture? _emptyMask;
    private GPUTexture? _groundDepthTexture;
    private (nint Buf, int Count, nint SurBuf, int SurCount, nint Tex, long Rev, float Ox, float Oy, float Scale, float W, float H) _groundDepthCacheKey;
    private ulong? _renderDeltaTicks;
    private GPUTexture? _emptyLiftTexture;
    private GPUTexture? _simMaskTexture;
    private GPUTexture? _emptySimMaskTexture;
    private GPUTexture? _surfaceSourceTexture;
    private GPUTexture? _depthSpritePrepassDepth;
    private GPUTexture? _depthSpriteColorTexture;
    private GPUTexture? _emptyTransparent;
    private readonly Dictionary<(string PackId, string Key), GPUTexture> _pluginRenderTargets = new();
    private readonly Dictionary<(string PackId, string Key), (int Width, int Height, ulong Hash, GPUTexture Texture)> _pluginUploadedTextures = new();

    public void SetClientPlugins(ClientPluginHost? clientPlugins)
    {
        if (ReferenceEquals(ClientPlugins, clientPlugins))
            return;
        ClientPlugins = clientPlugins;
        ClearPluginGpuResources();
    }

    private void ClearPluginGpuResources()
    {
        foreach (GPUTexture tex in _pluginRenderTargets.Values)
            Retire(tex);
        _pluginRenderTargets.Clear();
        foreach (var entry in _pluginUploadedTextures.Values)
            Retire(entry.Texture);
        _pluginUploadedTextures.Clear();
    }

    private readonly Queue<(ulong Frame, IDisposable Resource)> _retiredGpu = new();
    private ulong _frameCounter;
    private bool _disposed;

    public LotRenderer(GPUContext gpu)
    {
        GPU = gpu ?? throw new ArgumentNullException(nameof(gpu));
    }

    public void BeginFrame()
    {
        _frameCounter++;
        DrainRetired(minAge: 3);
    }

    private void Retire(IDisposable? resource)
    {
        if (resource is null)
        {
            return;
        }

        if (_disposed)
        {
            resource.Dispose();
            return;
        }

        _retiredGpu.Enqueue((_frameCounter, resource));
    }

    private void DrainRetired(ulong minAge)
    {
        while (_retiredGpu.TryPeek(out var entry) && _frameCounter - entry.Frame >= minAge)
        {
            _retiredGpu.Dequeue();
            entry.Resource.Dispose();
        }
    }

    private void RetireDistinctBuffers(
        IReadOnlyList<MeshSlice?> slices,
        int startIndex = 0,
        IReadOnlyList<MeshSlice?>? excludeSlices = null)
    {
        if (startIndex >= slices.Count)
        {
            return;
        }

        HashSet<GPUBuffer>? excluded = null;
        if (excludeSlices is { Count: > 0 })
        {
            excluded = new HashSet<GPUBuffer>(ReferenceEqualityComparer.Instance);
            for (int i = 0; i < excludeSlices.Count; i++)
            {
                if (excludeSlices[i] is { Buffer: { } excludedBuffer })
                {
                    excluded.Add(excludedBuffer);
                }
            }
        }

        HashSet<GPUBuffer>? seen = null;
        for (int i = startIndex; i < slices.Count; i++)
        {
            if (slices[i] is not { Buffer: { } buffer })
            {
                continue;
            }

            if (_dynamicMeshRing.Contains(buffer, ReferenceEqualityComparer.Instance) ||
                (excluded is not null && excluded.Contains(buffer)))
            {
                continue;
            }

            seen ??= new HashSet<GPUBuffer>(ReferenceEqualityComparer.Instance);
            if (seen.Add(buffer))
            {
                Retire(buffer);
            }
        }
    }

    private void RetireDistinctTextures(IEnumerable<GPUTexture> textures)
    {
        HashSet<GPUTexture>? seen = null;
        foreach (GPUTexture texture in textures)
        {
            seen ??= new HashSet<GPUTexture>(ReferenceEqualityComparer.Instance);
            if (seen.Add(texture))
            {
                Retire(texture);
            }
        }
    }

    private void RetirePreview(PreviewMeshes preview)
    {
        var seen = new HashSet<IDisposable>(ReferenceEqualityComparer.Instance);
        foreach (GPUBuffer? buffer in preview.Buffers)
        {
            if (buffer is not null && seen.Add(buffer))
            {
                Retire(buffer);
            }
        }

        foreach (GPUTexture texture in preview.Textures)
        {
            if (seen.Add(texture))
            {
                Retire(texture);
            }
        }
    }

    public void Dispose()
    {
        if (_disposed)
        {
            return;
        }

        _disposed = true;
        var all = new HashSet<IDisposable>(ReferenceEqualityComparer.Instance);
        while (_retiredGpu.TryDequeue(out var entry))
        {
            all.Add(entry.Resource);
        }

        static void Collect(HashSet<IDisposable> set, IDisposable? resource)
        {
            if (resource is not null)
            {
                set.Add(resource);
            }
        }

        Collect(all, _terrainBuffer);
        Collect(all, _surroundingsTerrain);
        Collect(all, _surroundingsRoadBuffer);
        Collect(all, _placementBuffer);
        Collect(all, _upperPlacementBuffer);
        Collect(all, _buildGridLevel1Buffer);
        Collect(all, _buildGridLevel2Buffer);
        Collect(all, _floorBrushBuffer);
        Collect(all, _floorBrushTexture);
        Collect(all, _heightMapTexture);
        Collect(all, _footMapTexture);
        Collect(all, _worldShadowColor);
        Collect(all, _worldShadowDepth);
        Collect(all, _worldShadowBackDepth);
        Collect(all, _worldShadowStaticDepth);
        Collect(all, _worldShadowStaticBackDepth);
        Collect(all, _overheadMap);
        Collect(all, _emptyOverhead);
        Collect(all, _voxelMap);
        Collect(all, _indoorMask);
        Collect(all, _emptyMask);
        Collect(all, _groundDepthTexture);
        Collect(all, _emptyLiftTexture);
        Collect(all, _simMaskTexture);
        Collect(all, _emptySimMaskTexture);
        Collect(all, _surfaceSourceTexture);
        Collect(all, _depthSpritePrepassDepth);
        Collect(all, _depthSpriteColorTexture);
        Collect(all, _emptyTransparent);

        foreach (MeshSlice? slice in _meshSlices) Collect(all, slice?.Buffer);
        foreach (MeshSlice? slice in _staticMeshSlices) Collect(all, slice?.Buffer);
        foreach (GPUBuffer? ring in _dynamicMeshRing) Collect(all, ring);
        foreach (GPUTexture tex in _sceneTextures) all.Add(tex);
        foreach (GPUTexture tex in _cachedTextures.Values) all.Add(tex);
        foreach (GPUTexture tex in _dynamicTextureCache.Values) all.Add(tex);
        foreach (GPUTexture tex in _pluginRenderTargets.Values) all.Add(tex);
        foreach (var entry in _pluginUploadedTextures.Values) all.Add(entry.Texture);
        foreach (GPUTexture tex in _ghostTextures) all.Add(tex);
        foreach (GPUTexture tex in _buildCursorTextures) all.Add(tex);
        foreach (GPUTexture tex in _wallPaintTextures) all.Add(tex);
        foreach (var entry in _uiTextures.Values) all.Add(entry.Texture);
        foreach (PreviewMeshes preview in _previews.Values)
        {
            foreach (GPUBuffer? b in preview.Buffers) Collect(all, b);
            foreach (GPUTexture t in preview.Textures) all.Add(t);
        }

        _sceneTextures = [];
        _cachedTextures = [];
        _dynamicTextureCache.Clear();
        _pluginRenderTargets.Clear();
        _pluginUploadedTextures.Clear();
        _uiTextures.Clear();
        _uiTexturesAlt.Clear();
        _previews.Clear();
        _ghostPixels = null;
        _ghostTextures = [];
        _ghostTextureKeys = [];
        _buildCursorTextures = [];
        _buildCursorTextureKeys = [];
        _wallPaintTextures = [];
        _wallPaintTextureKeys = [];
        _wallPaintByWall.Clear();
        _cachedObjectHit = null;
        _cachedWallHit = null;
        _uploadedVoxelPixels = null;
        _uploadedVoxelWidth = 0;
        _uploadedVoxelHeight = 0;
        _uploadedVoxelHash = 0;
        _uploadedOverheadWidth = 0;
        _uploadedOverheadHeight = 0;
        _uploadedOverheadHash = 0;
        _uploadedIndoorWidth = 0;
        _uploadedIndoorHeight = 0;
        _uploadedIndoorHash = 0;
        _hasDynamicShadowSprites = false;
        _surroundingsRoads = [];
        _surroundingsDecorations = [];
        _surroundingsScenery = [];
        _surroundingsMargin = 0;
        _meshSlices = [];
        _staticMeshSlices = [];

        foreach (IDisposable resource in all)
        {
            resource.Dispose();
        }
    }

    public bool IsLoadingScene => _sceneLoadsInFlight > 0;
    public long SceneRevisionNumber => _sceneRevision;
    public long AnimationSequenceNumber => _animationSequence;
    public int ViewLevel => Scene?.SelectedLevel ?? 1;
    public bool RoofsVisible => Scene?.RoofsVisible ?? false;
    public int StoryCount => Scene?.Stories ?? 2;
    public SimsSDL.Core.LotCamera CameraOrientation => Scene?.Camera ?? SimsSDL.Core.LotCamera.TopLeft;

    public void UploadOverlay()
    {
        if (_placementDirty)
        {
            _placementDirty = false;
            Retire(_placementBuffer);
            _placementBuffer = GPU.MakeStorageBuffer(_placementVertices);
            Retire(_upperPlacementBuffer);
            _upperPlacementBuffer = _upperPlacementVertices.Length > 0
                ? GPU.MakeStorageBuffer(_upperPlacementVertices)
                : null;
        }

        if (_ghostPixels is { } ghostPixels)
        {
            _ghostPixels = null;
            RetireDistinctTextures(_ghostTextures);
            _ghostTextures = GPU.UploadTextures(ghostPixels);
        }

        if (_buildGridDirty)
        {
            _buildGridDirty = false;
            RebuildBuildGridBuffers();
        }

        if (_floorBrushDirty)
        {
            _floorBrushDirty = false;
            Retire(_floorBrushBuffer);
            _floorBrushBuffer = GPU.MakeStorageBuffer(_floorBrushVertices);
            if (_floorBrushPixels is { } pixels)
            {
                _floorBrushPixels = null;
                Retire(_floorBrushTexture);
                ReadOnlySpan<bool> floorBrushMip = [true];
                var uploaded = GPU.UploadTextures([(pixels.Width, pixels.Height, pixels.Depth8, pixels.Pixels)], floorBrushMip);
                _floorBrushTexture = uploaded.Count > 0 ? uploaded[0] : null;
            }
            else if (_floorBrushTextureKey is null)
            {
                Retire(_floorBrushTexture);
                _floorBrushTexture = null;
            }
        }

        if (_buildCursorPixels is { } cursorPixels)
        {
            _buildCursorPixels = null;
            RetireDistinctTextures(_buildCursorTextures);
            _buildCursorTextures = GPU.UploadTextures(cursorPixels);
        }

        if (_wallPaintPixels is { } wallPixels)
        {
            _wallPaintPixels = null;
            RetireDistinctTextures(_wallPaintTextures);
            _wallPaintTextures = GPU.UploadTextures(wallPixels);
        }

        var next = _uiTexturesAlt;
        next.Clear();
        List<UITexture> uploads = _uiUploadsScratch;
        uploads.Clear();
        _uiUploadSeenScratch.Clear();

        for (int i = 0; i < Overlay.Count; i++)
        {
            UITexture texture = Overlay[i].Texture;
            if (next.ContainsKey(texture))
            {
                continue;
            }

            if (_uiTextures.TryGetValue(texture, out var cached) && cached.Version == texture.Version)
            {
                next[texture] = cached;
            }
            else if (_uiUploadSeenScratch.Add(texture))
            {
                uploads.Add(texture);
            }
        }

        if (uploads.Count > 0)
        {
            var imageBatch = new (int Width, int Height, bool Depth8, byte[] Pixels)[uploads.Count];
            var mipFlags = new bool[uploads.Count];
            for (int i = 0; i < uploads.Count; i++)
            {
                UITexture u = uploads[i];
                imageBatch[i] = (u.Width, u.Height, false, u.Pixels);
                mipFlags[i] = u.Width > 1 && u.Height > 1;
            }

            IReadOnlyList<GPUTexture> uploadedTextures = GPU.UploadTextures(imageBatch, mipFlags);
            for (int i = 0; i < uploads.Count; i++)
            {
                UITexture source = uploads[i];
                next[source] = (source, source.Version, uploadedTextures[i]);
            }
        }

        if (_uiTextures.Count > 0 && (uploads.Count > 0 || next.Count != _uiTextures.Count))
        {
            HashSet<GPUTexture> retainedUi = _retainedUiScratch;
            retainedUi.Clear();
            foreach (var entry in next.Values)
            {
                retainedUi.Add(entry.Texture);
            }

            foreach (var entry in _uiTextures.Values)
            {
                if (retainedUi.Add(entry.Texture))
                {
                    Retire(entry.Texture);
                }
            }
        }

        _uiTexturesAlt = _uiTextures;
        _uiTexturesAlt.Clear();
        _uiTextures = next;
    }

    private SimsSDL.Core.SceneLighting? ActiveLighting(LotScene scene) => LightingEnabled ? scene.Lighting : null;

    internal bool SuppressVanillaLightingActive => LightingEnabled && AmbientEnabled && ClientPlugins?.SuppressVanillaRoomLighting == true;

    internal bool HasActiveRenderPasses => DrawsLot && AmbientEnabled && ClientPlugins?.HasActiveRenderPasses == true;

    private static Vector4 SrgbTintToLinear(Vector4 srgb) =>
        new(SrgbChannelToLinear(srgb.X), SrgbChannelToLinear(srgb.Y), SrgbChannelToLinear(srgb.Z), srgb.W);

    internal Vector4 EffectiveOutsideTint(SimsSDL.Core.SceneLighting? lighting) =>
        SuppressVanillaLightingActive ? Vector4.One : SrgbTintToLinear(lighting?.Outside.Multiplier ?? Vector4.One);

    internal Vector4 EffectiveRoomTint(SimsSDL.Core.SceneLighting? lighting, int? room) =>
        SuppressVanillaLightingActive ? Vector4.One : SrgbTintToLinear(lighting?.Multiplier(room) ?? Vector4.One);

    private static (int Width, int Height, bool Depth8, byte[] Pixels) PrepareUpload(LotScene.Texture image, byte[] data)
    {
        bool depth8 = string.Equals(image.Encoding, "depth8", StringComparison.Ordinal);
        return (
            image.Width,
            image.Height,
            depth8,
            depth8 ? data : SpritePixels.PremultipliedSRGB(data, decontaminateEdges: true, width: image.Width, height: image.Height));
    }

    private static string CacheTexturePath(string rootDir, string file) =>
        Path.GetFullPath(Path.Combine(rootDir, file.Replace('\\', Path.DirectorySeparatorChar).Replace('/', Path.DirectorySeparatorChar)));

    private static string ResolveRealPath(string path) => LotScene.ResolveRealPath(path);

    private static readonly SemaphoreSlim s_bgLoadGate = new(4, 4);

    public void LoadScene(string path, long revision = 0)
    {
        (LotScene Scene, List<byte[]> Pixels) loaded = LotScene.Load(path);
        PreparedScene prepared = PrepareScene(loaded, path, SnapshotCachedTextureSpecs(), deferMasks: false, gpu: GPU);
        GPU.BatchingUploads(() => Install(prepared, path, revision));
    }

    private Dictionary<string, (int Width, int Height, bool Depth8, PickerAlphaMask? Mask)> SnapshotCachedTextureSpecs()
    {
        var specs = new Dictionary<string, (int Width, int Height, bool Depth8, PickerAlphaMask? Mask)>(_cachedTextures.Count + _dynamicTextureCache.Count);
        foreach (var (key, tex) in _dynamicTextureCache)
        {
            PickerAlphaMask? mask = _dynamicMaskCache.TryGetValue(key, out var dynMask) ? dynMask : null;
            if (mask.HasValue)
            {
                specs[key] = (tex.Width, tex.Height, tex.Format == SDL_GPU_TEXTUREFORMAT_R8_UNORM, mask);
            }
        }

        foreach (var (key, tex) in _cachedTextures)
        {
            PickerAlphaMask? mask = _cachedMasks.TryGetValue(key, out var cachedMask) ? cachedMask : null;
            if (mask.HasValue)
            {
                specs[key] = (tex.Width, tex.Height, tex.Format == SDL_GPU_TEXTUREFORMAT_R8_UNORM, mask);
            }
        }

        return specs;
    }

    private static PreparedScene PrepareScene(
        (LotScene Scene, List<byte[]> Pixels) loaded,
        string path,
        Dictionary<string, (int Width, int Height, bool Depth8, PickerAlphaMask? Mask)> cachedSpecs,
        bool deferMasks = false,
        GPUContext? gpu = null)
    {
        string rootDir = Path.GetDirectoryName(Path.GetFullPath(path)) ?? ".";
        var masks = deferMasks ? [] : new PickerAlphaMask[loaded.Scene.Textures.Count];
        List<int> workIndices = [];
        for (int index = 0; index < loaded.Scene.Textures.Count; index++)
        {
            LotScene.Texture image = loaded.Scene.Textures[index];
            string key = CacheTexturePath(rootDir, image.File);
            bool isDepth = string.Equals(image.Encoding, "depth8", StringComparison.Ordinal);
            if (cachedSpecs.TryGetValue(key, out var spec) &&
                spec.Width == image.Width &&
                spec.Height == image.Height &&
                spec.Depth8 == isDepth &&
                (deferMasks || spec.Mask.HasValue))
            {
                if (!deferMasks)
                    masks[index] = spec.Mask!.Value;
                continue;
            }

            workIndices.Add(index);
        }

        var preparedUploads = new Dictionary<int, (int Width, int Height, bool Depth8, byte[] Pixels)>(workIndices.Count);
        var uploadKeys = new Dictionary<int, GPUContext.SharedTextureKey>(workIndices.Count);
        if (workIndices.Count > 0)
        {
            if (workIndices.Count >= 8)
            {
                var slots = new (int Width, int Height, bool Depth8, byte[] Pixels)[workIndices.Count];
                var keys = new GPUContext.SharedTextureKey[workIndices.Count];
                Exception? firstError = null;
                Parallel.For(0, workIndices.Count, i =>
                {
                    int texIndex = workIndices[i];
                    try
                    {
                        var info = loaded.Scene.Textures[texIndex];
                        var raw = loaded.Pixels[texIndex];
                        if (!deferMasks)
                            masks[texIndex] = PickerAlphaMask.FromTexture(info, raw);
                        var prep = PrepareUpload(info, raw);
                        bool wantsMip = !prep.Depth8 && (prep.Width > 1 || prep.Height > 1);
                        var k = GPUContext.ComputeContentKey(prep.Width, prep.Height, prep.Depth8, wantsMip, prep.Pixels);
                        keys[i] = k;
                        if (gpu is null || !gpu.ContainsSharedTexture(k))
                            slots[i] = prep;
                    }
                    catch (Exception ex)
                    {
                        Interlocked.CompareExchange(ref firstError, ex, null);
                    }
                });

                if (firstError is not null)
                {
                    ExceptionDispatchInfo.Capture(firstError).Throw();
                }

                for (int i = 0; i < workIndices.Count; i++)
                {
                    int texIdx = workIndices[i];
                    if (slots[i].Pixels is not null)
                        preparedUploads[texIdx] = slots[i];
                    uploadKeys[texIdx] = keys[i];
                }
            }
            else
            {
                foreach (int texIndex in workIndices)
                {
                    var info = loaded.Scene.Textures[texIndex];
                    var raw = loaded.Pixels[texIndex];
                    if (!deferMasks)
                        masks[texIndex] = PickerAlphaMask.FromTexture(info, raw);
                    var prep = PrepareUpload(info, raw);
                    bool wantsMip = !prep.Depth8 && (prep.Width > 1 || prep.Height > 1);
                    var k = GPUContext.ComputeContentKey(prep.Width, prep.Height, prep.Depth8, wantsMip, prep.Pixels);
                    uploadKeys[texIndex] = k;
                    if (gpu is null || !gpu.ContainsSharedTexture(k))
                        preparedUploads[texIndex] = prep;
                }
            }
        }

        List<SceneDrawItem> drawItems = SceneDrawItem.Ordered(loaded.Scene);
        IReadOnlyList<LotScene.Mesh> allMeshes = loaded.Scene.Meshes ?? [];
        Vector4[] allMeshBounds = ScenePicker.ComputeMeshBounds(allMeshes);
        List<LotScene.Mesh> staticMeshes = allMeshes.Where(m => m.ObjectID == 0).ToList();
        Vector4[] staticMeshBounds = ScenePicker.ComputeMeshBounds(staticMeshes);
        GroundTilePicker? groundPicker = deferMasks ? null : GroundTilePicker.Create(loaded.Scene);

        return new PreparedScene
        {
            Scene = loaded.Scene,
            Masks = masks,
            PreparedUploads = preparedUploads,
            UploadKeys = uploadKeys,
            DeferredMasks = deferMasks,
            DrawItems = drawItems,
            AllMeshBounds = allMeshBounds,
            StaticMeshBounds = staticMeshBounds,
            GroundPicker = groundPicker,
        };
    }

    public void ResetSceneRevisionTracking()
    {
        _sceneLoadEpoch++;
        _newestRequestedRevision = 0;
        _pendingFrames.Clear();
    }

    public void LoadSceneInBackground(string path, long revision, Action<Exception?> loaded)
    {
        long epoch = _sceneLoadEpoch;
        _newestRequestedRevision = Math.Max(_newestRequestedRevision, revision);
        _sceneLoadsInFlight += 1;
        var cachedSpecs = SnapshotCachedTextureSpecs();
        const bool deferMasks = false;
        GPUContext gpu = GPU;
        _ = Task.Run(async () =>
        {
            PreparedScene? prepared = null;
            Exception? decodeError = null;
            await s_bgLoadGate.WaitAsync().ConfigureAwait(false);
            try
            {
                if (epoch == _sceneLoadEpoch && revision >= _newestRequestedRevision)
                {
                    var decoded = LotScene.Load(path);
                    prepared = PrepareScene(decoded, path, cachedSpecs, deferMasks, gpu);
                }
            }
            catch (Exception error)
            {
                decodeError = error;
            }
            finally
            {
                s_bgLoadGate.Release();
            }

            MainThreadDispatcher.Post(() =>
            {
                _sceneLoadsInFlight -= 1;
                if (epoch != _sceneLoadEpoch || revision < _newestRequestedRevision || (decodeError is null && prepared is null))
                {
                    return;
                }

                try
                {
                    if (decodeError is not null)
                    {
                        loaded(decodeError);
                        return;
                    }

                    GPU.BatchingUploads(() => Install(prepared!, path, revision));
                    loaded(null);
                }
                catch (Exception error)
                {
                    loaded(error);
                }
            });
        });
    }

    private void CacheDynamicTexture(GPUTexture texture, PickerAlphaMask mask, string key)
    {
        if (!_dynamicTextureCache.ContainsKey(key))
        {
            _dynamicTextureOrder.Add(key);
            if (_dynamicTextureOrder.Count > MaxCachedDynamicTextures)
            {
                int overflow = _dynamicTextureOrder.Count - MaxCachedDynamicTextures;
                for (int i = 0; i < overflow; i++)
                {
                    string evicted = _dynamicTextureOrder[i];
                    if (_dynamicTextureCache.Remove(evicted, out var evictedTex) &&
                        !IsTextureReferencedOutsideDynamicCache(evictedTex))
                    {
                        Retire(evictedTex);
                    }
                    _dynamicMaskCache.Remove(evicted);
                }

                _dynamicTextureOrder.RemoveRange(0, overflow);
            }
        }

        _dynamicTextureCache[key] = texture;
        _dynamicMaskCache[key] = mask;
    }

    private bool IsTextureReferencedOutsideDynamicCache(GPUTexture target)
    {
        foreach (GPUTexture tex in _sceneTextures)
        {
            if (ReferenceEquals(tex, target)) return true;
        }

        foreach (GPUTexture tex in _cachedTextures.Values)
        {
            if (ReferenceEquals(tex, target)) return true;
        }

        return false;
    }

    private void Install(PreparedScene loaded, string path, long revision)
    {
        int textureCount = loaded.Scene.Textures.Count;
        var textures = new GPUTexture?[textureCount];
        var uploads = new List<(int Index, (int Width, int Height, bool Depth8, byte[] Pixels) Image, bool Mipmapped, GPUContext.SharedTextureKey Key)>();
        List<string> keys = new(textureCount);
        string rootDir = Path.GetDirectoryName(Path.GetFullPath(path)) ?? ".";

        var previousTextures = new HashSet<GPUTexture>(ReferenceEqualityComparer.Instance);
        foreach (GPUTexture oldTex in _sceneTextures) previousTextures.Add(oldTex);
        foreach (GPUTexture oldTex in _cachedTextures.Values) previousTextures.Add(oldTex);

        var batchDedup = new Dictionary<GPUContext.SharedTextureKey, GPUTexture>();

        for (int index = 0; index < textureCount; index++)
        {
            LotScene.Texture image = loaded.Scene.Textures[index];
            string key = CacheTexturePath(rootDir, image.File);
            keys.Add(key);
            var format = string.Equals(image.Encoding, "depth8", StringComparison.Ordinal)
                ? SDL_GPU_TEXTUREFORMAT_R8_UNORM
                : GPUContext.ColorFormat;
            bool wantsMip = !string.Equals(image.Encoding, "depth8", StringComparison.Ordinal)
                && (image.Width > 1 || image.Height > 1);
            GPUTexture? cached = _cachedTextures.GetValueOrDefault(key) ?? _dynamicTextureCache.GetValueOrDefault(key);
            if (cached is not null && cached.Handle != nint.Zero && cached.Width == image.Width && cached.Height == image.Height && cached.Format == format
                && (!wantsMip || cached.NumLevels > 1))
            {
                textures[index] = cached;
            }
            else
            {
                GPUContext.SharedTextureKey uploadKey;
                (int Width, int Height, bool Depth8, byte[] Pixels) preparedImage = default;
                bool hasPrepared = loaded.PreparedUploads.TryGetValue(index, out preparedImage);
                if (loaded.UploadKeys.TryGetValue(index, out var preKey))
                {
                    uploadKey = preKey;
                }
                else
                {
                    if (!hasPrepared)
                    {
                        byte[] raw = LotScene.ReadPixels([image], ResolveRealPath(rootDir))[0];
                        if (!loaded.DeferredMasks && index < loaded.Masks.Length)
                            loaded.Masks[index] = PickerAlphaMask.FromTexture(image, raw);
                        preparedImage = PrepareUpload(image, raw);
                        hasPrepared = true;
                    }
                    uploadKey = GPUContext.ComputeContentKey(preparedImage.Width, preparedImage.Height, preparedImage.Depth8, wantsMip, preparedImage.Pixels);
                }

                if (batchDedup.TryGetValue(uploadKey, out var sameLotTex))
                {
                    textures[index] = sameLotTex;
                }
                else if (GPU.TryAcquireSharedTexture(uploadKey) is { } sharedTex)
                {
                    if (previousTextures.Contains(sharedTex))
                        sharedTex.Dispose();
                    batchDedup[uploadKey] = sharedTex;
                    textures[index] = sharedTex;
                }
                else
                {
                    if (!hasPrepared)
                    {
                        byte[] raw = LotScene.ReadPixels([image], ResolveRealPath(rootDir))[0];
                        if (!loaded.DeferredMasks && index < loaded.Masks.Length)
                            loaded.Masks[index] = PickerAlphaMask.FromTexture(image, raw);
                        preparedImage = PrepareUpload(image, raw);
                    }
                    uploads.Add((index, preparedImage, wantsMip, uploadKey));
                }
            }
        }

        if (uploads.Count > 0)
        {
            var uniqueUploads = new List<(int FirstIndex, (int Width, int Height, bool Depth8, byte[] Pixels) Image, bool Mipmapped, GPUContext.SharedTextureKey Key, List<int> Indices)>(uploads.Count);
            var pendingByKey = new Dictionary<GPUContext.SharedTextureKey, int>(uploads.Count);
            for (int i = 0; i < uploads.Count; i++)
            {
                var u = uploads[i];
                if (pendingByKey.TryGetValue(u.Key, out int slotIdx))
                {
                    uniqueUploads[slotIdx].Indices.Add(u.Index);
                }
                else
                {
                    pendingByKey[u.Key] = uniqueUploads.Count;
                    uniqueUploads.Add((u.Index, u.Image, u.Mipmapped, u.Key, [u.Index]));
                }
            }

            var batch = new (int Width, int Height, bool Depth8, byte[] Pixels)[uniqueUploads.Count];
            var batchMips = new bool[uniqueUploads.Count];
            for (int i = 0; i < uniqueUploads.Count; i++)
            {
                batch[i] = uniqueUploads[i].Image;
                batchMips[i] = uniqueUploads[i].Mipmapped;
            }

            IReadOnlyList<GPUTexture> uploaded = GPU.UploadTextures(batch, batchMips);
            for (int i = 0; i < uploaded.Count; i++)
            {
                GPUTexture tex = uploaded[i];
                GPU.RegisterSharedTexture(uniqueUploads[i].Key, tex);
                foreach (int dstIdx in uniqueUploads[i].Indices)
                    textures[dstIdx] = tex;
            }
        }

        List<GPUTexture> resolved = new(textureCount);
        for (int i = 0; i < textureCount; i++)
        {
            resolved.Add(textures[i]!);
        }

        if (Scene is null || loaded.Scene.Camera != Scene.Camera || loaded.Scene.SelectedLevel != Scene.SelectedLevel)
        {
            WallPaintPreview = null;
            _wallPaintPixels = null;
            RetireDistinctTextures(_wallPaintTextures);
            _wallPaintTextures = [];
            _wallPaintTextureKeys = [];
            _wallPaintByWall.Clear();
        }

        LotScene? previousScene = Scene;
        Scene = loaded.Scene;
        if (previousScene is not null &&
                 previousScene.House == loaded.Scene.House &&
                 previousScene.Camera != loaded.Scene.Camera &&
                 previousScene.LotWidth is int prevW && previousScene.LotHeight is int prevH &&
                 previousScene.OriginX is float prevOx && previousScene.OriginY is float prevOy &&
                 loaded.Scene.LotWidth is int nextW && loaded.Scene.LotHeight is int nextH &&
                 loaded.Scene.OriginX is float nextOx && loaded.Scene.OriginY is float nextOy)
        {
            float scale = MathF.Max(UIScale, 0.01f) * _visualZoomFactor;
            if (scale > 0f)
            {
                Vector2 prevSize = new(prevW, prevH);
                Vector2 nextSize = new(nextW, nextH);
                Vector2 prevCentre = new Vector2(previousScene.Width, previousScene.Height) * 0.5f;
                Vector2 prevProjected = prevCentre - _pan / scale + new Vector2(prevOx, prevOy) - new Vector2(34f, 158f);
                Vector2 prevCamPt = new(prevProjected.Y / 32f + prevProjected.X / 64f, prevProjected.Y / 32f - prevProjected.X / 64f);
                Vector2 lotPt = previousScene.Camera.LotPoint(prevCamPt, prevSize);
                Vector2 nextCentre = new Vector2(loaded.Scene.Width, loaded.Scene.Height) * 0.5f;
                Vector2 newPan = (nextCentre - (loaded.Scene.Camera.ProjectedPoint(lotPt, nextSize) - new Vector2(nextOx, nextOy))) * scale;
                _pan = SimsSDL.Core.SceneViewport.ClampedPan(newPan, loaded.Scene, scale);
            }
        }
        _sceneMasks = loaded.DeferredMasks ? [] : [.. loaded.Masks];
        _deferredPixelTextures = loaded.DeferredMasks ? [.. loaded.Scene.Textures] : [];
        SceneRoot = rootDir;
        _sceneRevision = revision;
        _animationSequence = 0;
        Retire(_terrainBuffer);
        _terrainBuffer = MakeTerrain(loaded.Scene);
        Retire(_surroundingsTerrain);
        _surroundingsTerrain = null;
        Retire(_surroundingsRoadBuffer);
        _surroundingsRoadBuffer = null;
        _surroundingsRoads = [];
        _surroundingsDecorations = [];
        _surroundingsScenery = [];
        _surroundingsMargin = 0;
        _buildGridDirty = true;

        IReadOnlyList<LotScene.Mesh> allMeshes = loaded.Scene.Meshes ?? [];
        List<LotScene.Sprite> keptSprites = new(loaded.Scene.Sprites.Count);
        foreach (LotScene.Sprite sprite in loaded.Scene.Sprites)
        {
            if ((sprite.ObjectID ?? 0) == 0)
            {
                keptSprites.Add(sprite);
            }
        }

        List<LotScene.Mesh> keptMeshes = new(allMeshes.Count);
        List<int> staticAllIndices = new(allMeshes.Count);
        List<LotScene.Mesh> dynamicMeshesInitial = [];
        List<int> dynamicAllIndices = [];
        for (int allIdx = 0; allIdx < allMeshes.Count; allIdx++)
        {
            LotScene.Mesh mesh = allMeshes[allIdx];
            if (mesh.ObjectID == 0)
            {
                keptMeshes.Add(mesh);
                staticAllIndices.Add(allIdx);
            }
            else
            {
                dynamicMeshesInitial.Add(mesh);
                dynamicAllIndices.Add(allIdx);
            }
        }

        _staticSprites = keptSprites;
        _staticMeshes = keptMeshes;
        _staticSpriteCount = keptSprites.Count;
        _staticMeshCount = keptMeshes.Count;
        _staticMeshBounds = loaded.StaticMeshBounds;

        bool hasElevatedOrBuilding = false;
        foreach (LotScene.Mesh mesh in allMeshes)
        {
            if (mesh.Roof is not null || mesh.Floor is null)
            {
                hasElevatedOrBuilding = true;
                break;
            }
        }
        if (!hasElevatedOrBuilding)
        {
            foreach (LotScene.Sprite sprite in loaded.Scene.Sprites)
            {
                if (sprite.Wall is not null || sprite.Junction is not null || sprite.ArchitectureDepth is not null ||
                    ((sprite.ObjectID ?? 0) != 0 && MathF.Max(sprite.Width, sprite.Height) >= 44f))
                {
                    hasElevatedOrBuilding = true;
                    break;
                }
            }
        }
        HasElevatedOrBuildingContent = hasElevatedOrBuilding;
        bool hasStaticRenderableMesh = false;
        foreach (LotScene.Mesh mesh in keptMeshes)
        {
            if (!(mesh.Floor is { } floor && (mesh.Level ?? 1) == 1 && floor.Pattern is 9 or 10 or 11 or 65534))
            {
                hasStaticRenderableMesh = true;
                break;
            }
        }
        _hasStaticRenderableMesh = hasStaticRenderableMesh;
        HasRenderableOverlayContent = hasStaticRenderableMesh ||
                                      keptSprites.Count > 0 ||
                                      dynamicMeshesInitial.Count > 0 ||
                                      loaded.Scene.Sprites.Count > keptSprites.Count;

        List<int> staticShadowIndices = [];
        for (int index = 0; index < keptSprites.Count; index++)
        {
            if (HasFloorShadow(keptSprites[index]))
            {
                staticShadowIndices.Add(index);
            }
        }
        _staticShadowSpriteIndices = [.. staticShadowIndices];

        _activeShadowSpriteIndices.Clear();
        for (int index = 0; index < loaded.Scene.Sprites.Count; index++)
        {
            if (HasFloorShadow(loaded.Scene.Sprites[index]))
            {
                _activeShadowSpriteIndices.Add(index);
            }
        }

        List<OrderedDrawEntry> cachedStaticEntries = new(keptSprites.Count + keptMeshes.Count);
        for (int index = 0; index < keptSprites.Count; index++)
        {
            LotScene.Sprite sprite = keptSprites[index];
            cachedStaticEntries.Add(new OrderedDrawEntry(
                sprite.Level ?? 1,
                sprite.Layer ?? 0,
                sprite.Depth ?? index,
                false,
                index,
                SceneDrawItem.Sprite(index)));
        }

        for (int index = 0; index < keptMeshes.Count; index++)
        {
            LotScene.Mesh mesh = keptMeshes[index];
            cachedStaticEntries.Add(new OrderedDrawEntry(
                mesh.Level ?? 1,
                mesh.Layer ?? 1,
                mesh.Depth,
                true,
                index,
                SceneDrawItem.Mesh(index)));
        }

        int staticTotalSprites = keptSprites.Count;
        cachedStaticEntries.Sort((a, b) => OrderedDrawEntry.Compare(in a, in b, staticTotalSprites));
        _staticDrawEntries = cachedStaticEntries;

        List<int> staticMeshOrder = [];
        foreach (OrderedDrawEntry entry in cachedStaticEntries)
        {
            if (entry.IsMesh)
            {
                staticMeshOrder.Add(entry.Index);
            }
        }

        RetireDistinctBuffers(_meshSlices);
        List<MeshSlice?> builtStaticSlices = MakeCombinedMeshes(keptMeshes, staticMeshOrder);
        List<MeshSlice?> builtDynamicSlices = dynamicMeshesInitial.Count == 0 ? [] : MakeCombinedMeshes(dynamicMeshesInitial);
        _staticMeshSlices = builtStaticSlices;

        List<MeshSlice?> initialSlices = Enumerable.Repeat<MeshSlice?>(null, allMeshes.Count).ToList();
        for (int staticIdx = 0; staticIdx < staticAllIndices.Count; staticIdx++)
        {
            initialSlices[staticAllIndices[staticIdx]] = builtStaticSlices[staticIdx];
        }

        for (int dynIdx = 0; dynIdx < dynamicAllIndices.Count; dynIdx++)
        {
            initialSlices[dynamicAllIndices[dynIdx]] = builtDynamicSlices[dynIdx];
        }

        _meshSlices = initialSlices;
        _meshBounds = loaded.AllMeshBounds;

        _drawItems = loaded.DrawItems;
        _picker = null;
        _pickerDirty = true;
        _cachedObjectHit = null;
        _cachedWallHit = null;
        _groundPicker = loaded.GroundPicker;
        _sceneTextures = resolved;
        BaseTextureCount = resolved.Count;

        var fileMap = new Dictionary<string, int>(textureCount);
        for (int index = 0; index < textureCount; index++)
        {
            fileMap[loaded.Scene.Textures[index].File] = index;
        }

        _textureIndexByFile = fileMap;
        UpdateSceneEnvironmentMaps(loaded.Scene);
        _uploadedVoxelPixels = loaded.Scene.VoxelMap?.Pixels;
        bool initialDynShadowSprites = false;
        foreach (LotScene.Sprite sprite in loaded.Scene.Sprites)
        {
            if (sprite.DynamicShadow == true && sprite.DepthTexture is not null)
            {
                initialDynShadowSprites = true;
                break;
            }
        }
        _hasDynamicShadowSprites = initialDynShadowSprites;

        var nextCachedTextures = new Dictionary<string, GPUTexture>(keys.Count);
        var nextCachedMasks = new Dictionary<string, PickerAlphaMask>(loaded.DeferredMasks ? 0 : keys.Count);
        for (int i = 0; i < keys.Count; i++)
        {
            nextCachedTextures[keys[i]] = resolved[i];
            if (!loaded.DeferredMasks)
                nextCachedMasks[keys[i]] = loaded.Masks[i];
        }

        _cachedTextures = nextCachedTextures;
        _cachedMasks = nextCachedMasks;

        if (previousTextures.Count > 0)
        {
            foreach (GPUTexture keep in resolved) previousTextures.Remove(keep);
            foreach (GPUTexture keep in nextCachedTextures.Values) previousTextures.Remove(keep);
            foreach (GPUTexture keep in _dynamicTextureCache.Values) previousTextures.Remove(keep);
            foreach (GPUTexture dead in previousTextures) Retire(dead);
        }

        if (_pendingFrames.Count > 0)
        {
            ApplyPendingAnimation();
        }
    }

    internal bool HasPendingFrames => _pendingFrames.Count > 0;
    internal bool HasElevatedOrBuildingContent { get; private set; }
    internal bool HasRenderableOverlayContent { get; private set; }
    private bool _hasStaticRenderableMesh;

    public void QueueAnimation(SceneAnimation frame) => _pendingFrames.Add(frame);

    public void ApplyPendingAnimation(nint command = 0)
    {
        if (_pendingFrames.Count == 0)
        {
            return;
        }

        List<SceneAnimation> future = [];
        List<SceneAnimation> matching = [];
        foreach (SceneAnimation frame in _pendingFrames)
        {
            if (frame.BaseRevision == _sceneRevision)
            {
                matching.Add(frame);
            }
            else if (frame.BaseRevision > _sceneRevision)
            {
                future.Add(frame);
            }
        }

        _pendingFrames = future;
        if (matching.Count == 0)
        {
            return;
        }
        _worldShadowAnimSeq++;

        int last = matching.Count - 1;
        SceneAnimation targetFrame = matching[last];
        if (!targetFrame.HasDirectVoxelMapState && targetFrame.VoxelMap is null && !targetFrame.VoxelMapCleared)
        {
            for (int i = last - 1; i >= 0; i--)
            {
                if (matching[i].VoxelMap is not null || matching[i].VoxelMapCleared)
                {
                    targetFrame = targetFrame with
                    {
                        VoxelMap = matching[i].VoxelMap,
                        VoxelMapCleared = matching[i].VoxelMapCleared,
                    };
                    break;
                }
            }
        }
        GPU.BatchingUploads(command, () =>
        {
            ApplyAnimation(targetFrame);
        });
    }

    public void ApplyAnimation(SceneAnimation frame)
    {
        if (Scene is null || SceneRoot is null)
        {
            throw new ContentError("Animation requires a scene snapshot");
        }

        LotScene previousScene = Scene;
        int keepCount = frame.TextureStart;
        if (keepCount < 0 || keepCount > _sceneTextures.Count || (BaseTextureCount > 0 && keepCount != BaseTextureCount))
        {
            throw new ContentError($"Animation TextureStart ({keepCount}) is out of range for scene texture count ({_sceneTextures.Count}) / base ({BaseTextureCount})");
        }

        LotScene updated = frame.Applying(previousScene, _staticSprites, _staticMeshes, _sceneRevision, _animationSequence);
        ulong dynamicSpriteHash = ComputeDynamicSpriteHash(frame.Sprites);
        if (dynamicSpriteHash != _lastDynamicSpriteHash)
        {
            _lastDynamicSpriteHash = dynamicSpriteHash;
            _worldShadowSpriteSeq++;
        }

        var resolvedNew = frame.Textures.Count > 0 ? new GPUTexture?[frame.Textures.Count] : [];
        var resolvedMasks = frame.Textures.Count > 0 ? new PickerAlphaMask[frame.Textures.Count] : [];

        if (frame.Textures.Count > 0)
        {
            int count = frame.Textures.Count;
            List<int> missingIndices = [];
            List<LotScene.Texture> missingTextures = [];
            List<string> missingKeys = [];
            List<bool> missingMips = [];
            const bool deferMasks = false;

            for (int offset = 0; offset < count; offset++)
            {
                LotScene.Texture image = frame.Textures[offset];
                var format = string.Equals(image.Encoding, "depth8", StringComparison.Ordinal)
                    ? SDL_GPU_TEXTUREFORMAT_R8_UNORM
                    : GPUContext.ColorFormat;
                bool wantsMip = !string.Equals(image.Encoding, "depth8", StringComparison.Ordinal)
                    && (image.Width > 1 || image.Height > 1);

                if (_textureIndexByFile.TryGetValue(image.File, out int existingIndex)
                    && (uint)existingIndex < (uint)_sceneTextures.Count
                    && (uint)existingIndex < (uint)previousScene.Textures.Count
                    && string.Equals(previousScene.Textures[existingIndex].File, image.File, StringComparison.Ordinal))
                {
                    GPUTexture existing = _sceneTextures[existingIndex];
                    if (existing.Handle != nint.Zero && existing.Width == image.Width && existing.Height == image.Height && existing.Format == format
                        && (!wantsMip || existing.NumLevels > 1))
                    {
                        resolvedNew[offset] = existing;
                        if (!deferMasks && (uint)existingIndex < (uint)_sceneMasks.Count)
                        {
                            resolvedMasks[offset] = _sceneMasks[existingIndex];
                        }

                        continue;
                    }
                }

                string key = CacheTexturePath(SceneRoot, image.File);
                GPUTexture? cached = _cachedTextures.GetValueOrDefault(key) ?? _dynamicTextureCache.GetValueOrDefault(key);
                PickerAlphaMask? mask = deferMasks
                    ? default
                    : _cachedMasks.TryGetValue(key, out var cachedMask)
                        ? cachedMask
                        : _dynamicMaskCache.TryGetValue(key, out var dynMask)
                            ? dynMask
                            : null;
                if (cached is not null && cached.Handle != nint.Zero && cached.Width == image.Width && cached.Height == image.Height && cached.Format == format
                    && (deferMasks || mask is { }) && (!wantsMip || cached.NumLevels > 1))
                {
                    resolvedNew[offset] = cached;
                    if (!deferMasks)
                        resolvedMasks[offset] = mask!.Value;
                }
                else
                {
                    missingIndices.Add(offset);
                    missingTextures.Add(image);
                    missingKeys.Add(key);
                    missingMips.Add(wantsMip);
                }
            }

            if (missingTextures.Count > 0)
            {
                string standardizedRoot = ResolveRealPath(SceneRoot);
                List<byte[]> rawData = LotScene.ReadPixels(missingTextures, standardizedRoot);
                var uploadBatch = new List<(int Width, int Height, bool Depth8, byte[] Pixels)>(missingTextures.Count);
                var uploadBatchMips = new List<bool>(missingTextures.Count);
                var uploadBatchKeys = new List<GPUContext.SharedTextureKey>(missingTextures.Count);
                var uploadTargets = new List<List<int>>(missingTextures.Count);
                var pendingKeySlot = new Dictionary<GPUContext.SharedTextureKey, int>(missingTextures.Count);
                var localOwned = new HashSet<GPUTexture>(ReferenceEqualityComparer.Instance);
                foreach (GPUTexture t in _sceneTextures) localOwned.Add(t);
                foreach (GPUTexture t in _cachedTextures.Values) localOwned.Add(t);
                foreach (GPUTexture t in _dynamicTextureCache.Values) localOwned.Add(t);

                for (int i = 0; i < missingTextures.Count; i++)
                {
                    int targetOffset = missingIndices[i];
                    if (!deferMasks)
                        resolvedMasks[targetOffset] = PickerAlphaMask.FromTexture(missingTextures[i], rawData[i]);
                    var prep = PrepareUpload(missingTextures[i], rawData[i]);
                    bool wantsMip = missingMips[i];
                    var contentKey = GPUContext.ComputeContentKey(prep.Width, prep.Height, prep.Depth8, wantsMip, prep.Pixels);
                    if (pendingKeySlot.TryGetValue(contentKey, out int slot))
                    {
                        uploadTargets[slot].Add(targetOffset);
                    }
                    else if (GPU.TryAcquireSharedTexture(contentKey) is { } sharedTex)
                    {
                        if (localOwned.Contains(sharedTex))
                            sharedTex.Dispose();
                        else
                            localOwned.Add(sharedTex);
                        resolvedNew[targetOffset] = sharedTex;
                    }
                    else
                    {
                        pendingKeySlot[contentKey] = uploadBatch.Count;
                        uploadBatch.Add(prep);
                        uploadBatchMips.Add(wantsMip);
                        uploadBatchKeys.Add(contentKey);
                        uploadTargets.Add([targetOffset]);
                    }
                }

                if (uploadBatch.Count > 0)
                {
                    IReadOnlyList<GPUTexture> uploaded = GPU.UploadTextures(uploadBatch, CollectionsMarshal.AsSpan(uploadBatchMips));
                    for (int i = 0; i < uploaded.Count; i++)
                    {
                        GPUTexture tex = uploaded[i];
                        GPU.RegisterSharedTexture(uploadBatchKeys[i], tex);
                        foreach (int dstOffset in uploadTargets[i])
                            resolvedNew[dstOffset] = tex;
                    }
                }
            }
        }

        IReadOnlyList<LotScene.Mesh> allUpdatedMeshes = updated.Meshes ?? [];
        List<LotScene.Mesh> dynamicMeshes = _dynamicMeshesScratch;
        dynamicMeshes.Clear();
        if (allUpdatedMeshes.Count > _staticMeshCount)
        {
            int dynCount = allUpdatedMeshes.Count - _staticMeshCount;
            if (dynamicMeshes.Capacity < dynCount)
                dynamicMeshes.Capacity = dynCount;
            for (int m = _staticMeshCount; m < allUpdatedMeshes.Count; m++)
            {
                dynamicMeshes.Add(allUpdatedMeshes[m]);
            }
        }

        List<MeshSlice?> dynamicSlices = _dynamicSlicesScratch;
        dynamicSlices.Clear();
        if (dynamicMeshes.Count > 0)
        {
            MakeCombinedDynamicMeshes(dynamicMeshes, dynamicSlices);
        }

        Vector4[] nextBounds;
        if (dynamicMeshes.Count == 0)
        {
            nextBounds = _staticMeshBounds;
        }
        else
        {
            int totalMeshCount = _staticMeshBounds.Length + dynamicMeshes.Count;
            nextBounds = new Vector4[totalMeshCount];
            Array.Copy(_staticMeshBounds, nextBounds, _staticMeshBounds.Length);
            Vector4[] dynBounds = ScenePicker.ComputeMeshBounds(dynamicMeshes);
            Array.Copy(dynBounds, 0, nextBounds, _staticMeshBounds.Length, dynBounds.Length);
        }

        List<int> nextShadows = _activeShadowSpriteIndicesScratch;
        nextShadows.Clear();
        for (int i = 0; i < _staticShadowSpriteIndices.Length; i++)
        {
            nextShadows.Add(_staticShadowSpriteIndices[i]);
        }

        int totalSprites = _staticSpriteCount + frame.Sprites.Count;
        List<OrderedDrawEntry> dynamicEntries = _dynamicEntriesScratch;
        dynamicEntries.Clear();
        int neededEntries = frame.Sprites.Count + dynamicMeshes.Count;
        if (dynamicEntries.Capacity < neededEntries)
        {
            dynamicEntries.Capacity = neededEntries;
        }

        bool hasDynShadowSprites = false;
        for (int offset = 0; offset < frame.Sprites.Count; offset++)
        {
            LotScene.Sprite sprite = frame.Sprites[offset];
            if (sprite.DynamicShadow == true && sprite.DepthTexture is not null)
            {
                hasDynShadowSprites = true;
            }
            int spriteIndex = _staticSpriteCount + offset;
            if (HasFloorShadow(sprite))
            {
                nextShadows.Add(spriteIndex);
            }
            dynamicEntries.Add(new OrderedDrawEntry(
                sprite.Level ?? 1,
                sprite.Layer ?? 0,
                sprite.Depth ?? spriteIndex,
                false,
                spriteIndex,
                SceneDrawItem.Sprite(spriteIndex)));
        }

        for (int offset = 0; offset < dynamicMeshes.Count; offset++)
        {
            LotScene.Mesh mesh = dynamicMeshes[offset];
            int meshIndex = _staticMeshCount + offset;
            dynamicEntries.Add(new OrderedDrawEntry(
                mesh.Level ?? 1,
                mesh.Layer ?? 1,
                mesh.Depth,
                true,
                meshIndex,
                SceneDrawItem.Mesh(meshIndex)));
        }

        CollectionsMarshal.AsSpan(dynamicEntries).Sort(new OrderedDrawEntryComparer(totalSprites));

        List<SceneDrawItem> nextMerged = _drawItemsScratch;
        nextMerged.Clear();
        int mergedCount = _staticDrawEntries.Count + dynamicEntries.Count;
        if (nextMerged.Capacity < mergedCount)
        {
            nextMerged.Capacity = mergedCount;
        }

        int s = 0;
        int d = 0;
        while (s < _staticDrawEntries.Count && d < dynamicEntries.Count)
        {
            OrderedDrawEntry staticEntry = _staticDrawEntries[s];
            OrderedDrawEntry dynEntry = dynamicEntries[d];
            if (OrderedDrawEntry.Compare(in staticEntry, in dynEntry, totalSprites) < 0)
            {
                nextMerged.Add(staticEntry.Item);
                s += 1;
            }
            else
            {
                nextMerged.Add(dynEntry.Item);
                d += 1;
            }
        }

        while (s < _staticDrawEntries.Count)
        {
            nextMerged.Add(_staticDrawEntries[s].Item);
            s += 1;
        }

        while (d < dynamicEntries.Count)
        {
            nextMerged.Add(dynamicEntries[d].Item);
            d += 1;
        }

        // All fallible uploads & mesh builds succeeded; commit state atomically together.
        if (_sceneTextures.Count > keepCount)
        {
            _sceneTextures.RemoveRange(keepCount, _sceneTextures.Count - keepCount);
        }

        if (_sceneMasks.Count > keepCount)
        {
            _sceneMasks.RemoveRange(keepCount, _sceneMasks.Count - keepCount);
        }

        _deferredPixelTextures.Clear();

        if (frame.Textures.Count > 0)
        {
            bool anyMissingMask = false;
            for (int offset = 0; offset < frame.Textures.Count; offset++)
            {
                LotScene.Texture image = frame.Textures[offset];
                int index = _sceneTextures.Count;
                GPUTexture texture = resolvedNew[offset]!;
                _sceneTextures.Add(texture);
                _textureIndexByFile[image.File] = index;
                if (!anyMissingMask && _sceneMasks.Count == index)
                {
                    _sceneMasks.Add(resolvedMasks[offset]);
                }
                else
                {
                    anyMissingMask = true;
                }
            }

            for (int offset = 0; offset < frame.Textures.Count; offset++)
            {
                LotScene.Texture image = frame.Textures[offset];
                string key = CacheTexturePath(SceneRoot, image.File);
                if (!_cachedTextures.ContainsKey(key))
                {
                    CacheDynamicTexture(resolvedNew[offset]!, resolvedMasks[offset], key);
                }
            }

            if (anyMissingMask)
            {
                _deferredPixelTextures = [.. updated.Textures];
            }
        }

        RetireDistinctBuffers(_meshSlices, startIndex: 0, excludeSlices: _staticMeshSlices);
        _meshSlices.Clear();
        _meshSlices.AddRange(_staticMeshSlices);
        for (int i = 0; i < dynamicSlices.Count; i++)
        {
            _meshSlices.Add(dynamicSlices[i]);
        }

        _meshBounds = nextBounds;
        (_activeShadowSpriteIndices, _activeShadowSpriteIndicesScratch) = (_activeShadowSpriteIndicesScratch, _activeShadowSpriteIndices);
        (_drawItems, _drawItemsScratch) = (_drawItemsScratch, _drawItems);

        if (!ReferenceEquals(updated.VoxelMap?.Pixels, _uploadedVoxelPixels))
        {
            Retire(_voxelMap);
            _voxelMap = MakeVoxelMap(updated);
            _uploadedVoxelPixels = updated.VoxelMap?.Pixels;
        }

        _hasDynamicShadowSprites = hasDynShadowSprites;
        Scene = updated;
        HasRenderableOverlayContent = _hasStaticRenderableMesh ||
                                      updated.Sprites.Count > 0 ||
                                      dynamicMeshes.Count > 0;
        _picker = null;
        _pickerDirty = true;
        _cachedObjectHit = null;
        _cachedWallHit = null;
        _animationSequence = frame.Sequence;
    }

    private ScenePicker? EnsurePicker()
    {
        if (!_pickerDirty && _picker is not null)
        {
            return _picker;
        }

        if (Scene is null)
        {
            return null;
        }

        if (_deferredPixelTextures.Count > 0 && SceneRoot is not null)
        {
            string standardizedRoot = ResolveRealPath(SceneRoot);
            Dictionary<string, int> existingByFile = new(_sceneMasks.Count);
            int limit = Math.Min(_sceneMasks.Count, Scene.Textures.Count);
            for (int i = 0; i < limit; i++)
            {
                existingByFile.TryAdd(Scene.Textures[i].File, i);
            }

            List<LotScene.Texture> unread = [];
            Dictionary<string, PickerAlphaMask> unreadMap = new();
            foreach (LotScene.Texture image in _deferredPixelTextures)
            {
                if (!existingByFile.ContainsKey(image.File) && unreadMap.TryAdd(image.File, default))
                {
                    unread.Add(image);
                }
            }

            if (unread.Count > 0)
            {
                List<byte[]> loaded;
                try
                {
                    loaded = LotScene.ReadPixels(unread, standardizedRoot);
                }
                catch
                {
                    return null;
                }

                for (int i = 0; i < unread.Count; i++)
                {
                    unreadMap[unread[i].File] = PickerAlphaMask.FromTexture(unread[i], loaded[i]);
                }
            }

            foreach (LotScene.Texture image in _deferredPixelTextures)
            {
                if (existingByFile.TryGetValue(image.File, out int existingIndex))
                {
                    _sceneMasks.Add(_sceneMasks[existingIndex]);
                }
                else if (unreadMap.TryGetValue(image.File, out PickerAlphaMask mask))
                {
                    int newIndex = _sceneMasks.Count;
                    _sceneMasks.Add(mask);
                    existingByFile[image.File] = newIndex;
                }
                else
                {
                    return null;
                }
            }

            _deferredPixelTextures.Clear();
        }

        if (_sceneMasks.Count != Scene.Textures.Count)
        {
            return null;
        }

        IReadOnlyList<LotScene.Mesh> allMeshes = Scene.Meshes ?? [];
        Vector4[]? precomputedBounds = _meshBounds.Length == allMeshes.Count
            ? _meshBounds
            : null;

        var built = new ScenePicker(Scene, _sceneMasks, _drawItems, precomputedBounds);
        _picker = built;
        _pickerDirty = false;
        return built;
    }

    private Vector2? PickScenePoint(Vector2 point, Vector2 canvas)
    {
        if (point.X < 0f || point.Y < 0f || point.X >= canvas.X || point.Y >= canvas.Y ||
            Viewport(canvas) is not { } viewport)
        {
            return null;
        }

        return (point - viewport.Origin) / viewport.Scale;
    }

    private List<GPUBuffer?> MakeMeshes(
        IReadOnlyList<LotScene.Mesh> meshes,
        float previewScale,
        float maxProjectedY,
        float centerV,
        out float maxTurntableSpan)
    {
        bool hasTurntableBasis = previewScale > 0f && float.IsFinite(previewScale) && float.IsFinite(maxProjectedY) && float.IsFinite(centerV);
        float maxRadius = 0f;
        List<GPUBuffer?> result = new(meshes.Count);
        foreach (LotScene.Mesh mesh in meshes)
        {
            var vertices = new AvatarVertex[mesh.Vertices.Count];
            for (int i = 0; i < mesh.Vertices.Count; i++)
            {
                LotScene.MeshVertex v = mesh.Vertices[i];
                Vector2 padding = Vector2.Zero;
                if (hasTurntableBasis)
                {
                    float pointY = maxProjectedY - (0.97f - v.Y) / previewScale;
                    float vCoord = (((0.62f - v.Z) / 0.003f) + 0.0204124145f * (pointY - 158f)) / 1.32659863f;
                    float sv = 32f * previewScale * (vCoord - centerV);
                    float su = v.X - 0.5f;
                    float radius = MathF.Sqrt(su * su + sv * sv);
                    if (radius > maxRadius) maxRadius = radius;
                    padding = new Vector2(sv, previewScale);
                }

                vertices[i] = new AvatarVertex
                {
                    Position = new Vector4(v.X, v.Y, v.Z, 1f),
                    Uv = new Vector2(v.U, v.V),
                    Padding = padding,
                    Normal = new Vector4(v.NX, v.NY, v.NZ, 0f),
                };
            }

            result.Add(GPU.MakeStorageBuffer(vertices));
        }

        maxTurntableSpan = maxRadius * 2f;
        return result;
    }
}

public struct UIDraw
{
    public UITexture Texture { get; set; }
    public Vector4 Rect { get; set; }
    public Vector4 UV { get; set; }
    public float Opacity { get; set; }

    public UIDraw()
    {
        Texture = default!;
        Rect = Vector4.Zero;
        UV = new Vector4(0f, 0f, 1f, 1f);
        Opacity = 1f;
    }

    public UIDraw(UITexture texture, Vector4 rect, Vector4? uv = null, float opacity = 1f)
    {
        Texture = texture;
        Rect = rect;
        UV = uv ?? new Vector4(0f, 0f, 1f, 1f);
        Opacity = opacity;
    }
}
