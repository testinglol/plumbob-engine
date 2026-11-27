using System.Numerics;
using SimsNative.Plugins;

namespace SimsSDL;

public sealed partial class LotRenderer
{
    private byte[]? _boundsVoxelPixels;
    private Vector4 _cachedVoxelBounds = new(1e6f, 1e6f, -1e6f, -1e6f);
    private Vector2 _cachedVoxelZBounds = new(1e6f, -1e6f);
    private byte[]? _boundsOverheadPixels;
    private Vector4 _cachedRoofSrcBounds = new(1e6f, 1e6f, -1e6f, -1e6f);
    private Vector2 _cachedRoofZBounds = new(1e6f, -1e6f);

    public void InvalidateShaderCaches()
    {
        _worldShadowKey = string.Empty;
        _worldShadowStaticKey = string.Empty;
        _groundDepthCacheKey = default;
        ClearPluginGpuResources();
    }

    private GPUTexture HeightTexture(int width, int height, bool feet = false)
    {
        GPUTexture? cached = feet ? _footMapTexture : _heightMapTexture;
        if (cached is not null && cached.Width == width && cached.Height == height)
        {
            return cached;
        }

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.DepthFormat,
            SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(cached);
        if (feet)
        {
            _footMapTexture = texture;
        }
        else
        {
            _heightMapTexture = texture;
        }

        return texture;
    }

    private static ulong ComputeFastByteHash(ReadOnlySpan<byte> bytes)
    {
        ulong hash = 14695981039346656037UL ^ (uint)bytes.Length;
        int i = 0;
        ReadOnlySpan<ulong> words = System.Runtime.InteropServices.MemoryMarshal.Cast<byte, ulong>(bytes);
        for (int w = 0; w < words.Length; w++)
        {
            hash = (hash ^ words[w]) * 1099511628211UL;
        }
        for (i = words.Length * 8; i < bytes.Length; i++)
        {
            hash = (hash ^ bytes[i]) * 1099511628211UL;
        }
        return hash == 0 ? 1UL : hash;
    }

    private void UpdateSceneEnvironmentMaps(LotScene scene)
    {
        if (BuildIndoorMaskBytes(scene) is var (imCols, imRows, imBytes))
        {
            ulong imHash = ComputeFastByteHash(imBytes);
            if (_indoorMask is null || _uploadedIndoorWidth != imCols || _uploadedIndoorHeight != imRows || _uploadedIndoorHash != imHash)
            {
                Retire(_indoorMask);
                IReadOnlyList<GPUTexture> uploaded = GPU.UploadTextures([(imCols, imRows, true, imBytes)]);
                _indoorMask = uploaded.Count > 0 ? uploaded[0] : null;
                _uploadedIndoorWidth = imCols;
                _uploadedIndoorHeight = imRows;
                _uploadedIndoorHash = imHash;
            }
        }
        else if (_indoorMask is not null)
        {
            Retire(_indoorMask);
            _indoorMask = null;
            _uploadedIndoorWidth = 0;
            _uploadedIndoorHeight = 0;
            _uploadedIndoorHash = 0;
        }

        if (scene.OverheadMap is { } ohMap)
        {
            ulong ohHash = ComputeFastByteHash(ohMap.Pixels);
            if (_overheadMap is null || _uploadedOverheadWidth != ohMap.Width || _uploadedOverheadHeight != ohMap.Height || _uploadedOverheadHash != ohHash)
            {
                Retire(_overheadMap);
                _overheadMap = GPU.UploadDataTexture(ohMap.Width, ohMap.Height, ohMap.Pixels);
                _uploadedOverheadWidth = ohMap.Width;
                _uploadedOverheadHeight = ohMap.Height;
                _uploadedOverheadHash = ohHash;
            }
        }
        else if (_overheadMap is not null)
        {
            Retire(_overheadMap);
            _overheadMap = null;
            _uploadedOverheadWidth = 0;
            _uploadedOverheadHeight = 0;
            _uploadedOverheadHash = 0;
        }

        if (scene.VoxelMap is { } vxMap)
        {
            bool sameRef = ReferenceEquals(_uploadedVoxelPixels, vxMap.Pixels)
                && _voxelMap is not null
                && _uploadedVoxelWidth == vxMap.Width
                && _uploadedVoxelHeight == vxMap.Height;
            if (!sameRef)
            {
                ulong vxHash = ComputeFastByteHash(vxMap.Pixels);
                if (_voxelMap is null || _uploadedVoxelWidth != vxMap.Width || _uploadedVoxelHeight != vxMap.Height || _uploadedVoxelHash != vxHash)
                {
                    Retire(_voxelMap);
                    _voxelMap = GPU.UploadDataTexture(vxMap.Width, vxMap.Height, vxMap.Pixels);
                    _uploadedVoxelWidth = vxMap.Width;
                    _uploadedVoxelHeight = vxMap.Height;
                    _uploadedVoxelHash = vxHash;
                }
            }
        }
        else if (_voxelMap is not null)
        {
            Retire(_voxelMap);
            _voxelMap = null;
            _uploadedVoxelWidth = 0;
            _uploadedVoxelHeight = 0;
            _uploadedVoxelHash = 0;
        }
    }

    private GPUTexture? MakeOverheadMap(LotScene scene) =>
        scene.OverheadMap is { } map ? GPU.UploadDataTexture(map.Width, map.Height, map.Pixels) : null;

    private GPUTexture? MakeIndoorMask(LotScene scene)
    {
        if (BuildIndoorMaskBytes(scene) is not var (cols, rows, bytes))
            return null;
        IReadOnlyList<GPUTexture> uploaded = GPU.UploadTextures([(cols, rows, true, bytes)]);
        return uploaded.Count > 0 ? uploaded[0] : null;
    }

    private GPUTexture? MakeVoxelMap(LotScene scene) =>
        scene.VoxelMap is { } map ? GPU.UploadDataTexture(map.Width, map.Height, map.Pixels) : null;

    private GPUTexture EmptyOverheadMap()
    {
        if (_emptyOverhead is not null)
            return _emptyOverhead;
        _emptyOverhead = GPU.UploadDataTexture(1, 1, [0, 128, 0, 0]);
        return _emptyOverhead;
    }

    private GPUTexture EmptyTransparent()
    {
        if (_emptyTransparent is not null)
            return _emptyTransparent;
        _emptyTransparent = GPU.UploadDataTexture(1, 1, [0, 0, 0, 0]);
        return _emptyTransparent;
    }

    private GPUTexture EmptyIndoorMask()
    {
        if (_emptyMask is not null)
            return _emptyMask;
        _emptyMask = GPU.UploadTextures([(1, 10, true, new byte[10])])[0];
        return _emptyMask;
    }

    private GPUTexture EmptyLift()
    {
        if (_emptyLiftTexture is not null)
            return _emptyLiftTexture;
        _emptyLiftTexture = GPU.MakeTexture(
            1,
            1,
            GPUContext.LiftFormat,
            SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        return _emptyLiftTexture;
    }

    // Packs 5 * stories bands into R8 indoorMap: rooms/windows, floor altitudes,
    // half-tile/road/cement, solid wall edges, and fence/railing edges.
    private (int Columns, int Rows, byte[] Bytes)? BuildIndoorMaskBytes(LotScene scene)
    {
        if (scene.LotWidth is not int width || scene.LotHeight is not int height ||
            scene.Lighting is not { } lighting || LotFrame(scene) is not { } frame)
        {
            return null;
        }

        int orientation = ((scene.CameraOrientation ?? 0) % 4 + 4) % 4;
        int margin = (int)_heightMargin;
        int columns = (orientation % 2 == 0 ? width : height) + 2 * margin;
        int rows = (orientation % 2 == 0 ? height : width) + 2 * margin;
        int stories = Math.Clamp(Math.Max(2, scene.Stories ?? 2), 2, LotScene.MaxSupportedStories);
        int bandStride = rows * columns;
        int catAltitudes = stories * bandStride;
        int catHalves = 2 * stories * bandStride;
        int catWalls = 3 * stories * bandStride;
        int catFences = 4 * stories * bandStride;
        var mask = new byte[columns * rows * 5 * stories];

        (int X, int Y, int Index)? TryCell(int x, int y, int level)
        {
            if (x < 0 || x >= width || y < 0 || y >= height || level < 1 || level > stories)
                return null;

            (int cx, int cy) = orientation switch
            {
                0 => (x, y),
                1 => (height - 1 - y, x),
                2 => (width - 1 - x, height - 1 - y),
                _ => (y, width - 1 - x),
            };
            return (cx, cy, ((level - 1) * rows + cy + margin) * columns + cx + margin);
        }

        List<(int Index, float Altitude)> altitudes = [];
        HashSet<int> seenAltitudes = [];
        float?[] baseAltitudes = new float?[bandStride];
        Dictionary<int, byte> halves = new();
        HashSet<int> whole = [];
        Dictionary<int, byte> outdoorHalves = new();
        HashSet<int> outdoorWhole = [];

        foreach (LotScene.Mesh mesh in scene.Meshes ?? [])
        {
            if (mesh.Floor is not { } floor)
                continue;
            int floorLevel = Math.Clamp(floor.Level ?? 1, 1, stories);
            if (TryCell(floor.X, floor.Y, floorLevel) is not { } at)
                continue;

            if (mesh.Vertices.Count > 0)
            {
                LotScene.MeshVertex v0 = mesh.Vertices[0];
                float rawAltitude = (frame.Y + 16f * (at.X + at.Y) + 32f * v0.V - v0.Y) / 40f;
                float groundAltitude = rawAltitude - (floorLevel - 1) * 2.95f;
                if (seenAltitudes.Add(at.Index + catAltitudes))
                    altitudes.Add((at.Index + catAltitudes, groundAltitude));
                if (TryCell(floor.X, floor.Y, 1) is { } atBase)
                {
                    baseAltitudes[atBase.Index] ??= groundAltitude;
                    if (floorLevel > 1 && seenAltitudes.Add(atBase.Index + catAltitudes))
                        altitudes.Add((atBase.Index + catAltitudes, groundAltitude));
                }
            }

            if (mesh.Room is not int room || room < 0 || room >= lighting.Rooms.Count || lighting.Rooms[room].Outside)
            {
                if (floor.Pattern == 12)
                    mask[at.Index + catHalves] |= 0x80;
                if (floor.Pattern is >= 9 and <= 11)
                    mask[at.Index + catHalves] |= 0x40;
                if (floor.Pattern >= 65534)
                    mask[at.Index + catHalves] |= 0x20;

                if (floor.Pattern != 12 && floor.Pattern is not (>= 9 and <= 11) && floor.Pattern < 65534)
                {
                    if (floor.Half == 0 || outdoorHalves.ContainsKey(at.Index))
                        outdoorWhole.Add(at.Index);
                    else if (floor.Half is >= 1 and <= 4)
                        outdoorHalves[at.Index] = (byte)floor.Half;
                }
                continue;
            }

            mask[at.Index] = (byte)(((room % 127 + 1) * 2) | (mask[at.Index] & 1));
            if (floor.Half == 0 || halves.ContainsKey(at.Index))
                whole.Add(at.Index);
            else
                halves[at.Index] = (byte)floor.Half;
        }

        foreach (var (index, half) in halves)
        {
            if (!whole.Contains(index))
                mask[index + catHalves] |= (byte)(half & 7);
        }

        foreach (var (index, half) in outdoorHalves)
        {
            if (mask[index] < 2 && !outdoorWhole.Contains(index))
                mask[index + catHalves] |= (byte)(half & 7);
        }

        foreach (LotScene.Sprite sprite in scene.Sprites ?? [])
        {
            if (sprite.ArchitectureDepth is not { } arch || sprite.Width <= 8f)
                continue;
            if (TryCell(arch.X, arch.Y, arch.Level) is not { } at)
                continue;

            int bandOffset = sprite.Wall is not null ? catWalls : catFences;
            int idx = at.Index + bandOffset;
            switch (arch.Configuration)
            {
                case 4:
                    mask[idx] |= 0x01;
                    if (at.X + margin > 0)
                        mask[idx - 1] |= 0x02;
                    break;
                case 5:
                    mask[idx] |= 0x04;
                    if (at.Y + margin > 0)
                        mask[idx - columns] |= 0x08;
                    break;
                case 6:
                    mask[idx] |= 0x20;
                    break;
                case 7:
                    mask[idx] |= 0x10;
                    break;
            }
        }

        bool anyIndoor = false;
        for (int i = 0; i < mask.Length; i++)
        {
            if (mask[i] != 0)
            {
                anyIndoor = true;
                break;
            }
        }

        if (!anyIndoor)
            return null;

        if (lighting.Windows is not null)
        {
            foreach (SimsSDL.Core.SceneLighting.Window window in lighting.Windows)
            {
                if (TryCell(window.X, window.Y, window.Level) is { } at)
                    mask[at.Index] |= 1;
                if (TryCell(window.X, window.Y, 1) is { } atBase && seenAltitudes.Add(atBase.Index + catAltitudes))
                {
                    float? neighborAlt = baseAltitudes[atBase.Index]
                        ?? (atBase.X + margin > 0 ? baseAltitudes[atBase.Index - 1] : null)
                        ?? (atBase.X + margin + 1 < columns ? baseAltitudes[atBase.Index + 1] : null)
                        ?? (atBase.Y + margin > 0 ? baseAltitudes[atBase.Index - columns] : null)
                        ?? (atBase.Y + margin + 1 < rows ? baseAltitudes[atBase.Index + columns] : null);
                    if (neighborAlt is float resolvedAlt)
                        altitudes.Add((atBase.Index + catAltitudes, resolvedAlt));
                }
            }
        }

        _indoorBase = altitudes.Count > 0 ? altitudes.Min(a => a.Altitude) : 0f;
        foreach (var (index, altitude) in altitudes)
        {
            mask[index] = (byte)MathF.Max(1f, MathF.Min(255f, MathF.Round((altitude - _indoorBase) * 8f, MidpointRounding.AwayFromZero) + 1f));
        }

        return (columns, rows * 5 * stories, mask);
    }

    private static Vector2? LotFrame(LotScene scene)
    {
        if (scene.OriginX is float x && scene.OriginY is float y)
            return new Vector2(34f - x, 158f - y);

        if (scene.LotWidth is not int width || scene.LotHeight is not int height ||
            scene.TerrainVertices is not { Count: > 0 } vertices)
        {
            return null;
        }

        LotScene.TerrainVertex first = vertices[0];
        Vector2 corner = (((scene.CameraOrientation ?? 0) % 4 + 4) % 4) switch
        {
            0 => new Vector2(0f, 0f),
            1 => new Vector2(height, 0f),
            2 => new Vector2(width, height),
            _ => new Vector2(0f, width),
        };
        return new Vector2(first.X - 32f * (corner.X - corner.Y), first.Y - 16f * (corner.X + corner.Y));
    }

    private static ulong ComputeDynamicSpriteHash(IReadOnlyList<LotScene.Sprite> sprites)
    {
        ulong hash = 14695981039346656037UL;
        const ulong prime = 1099511628211UL;
        for (int i = 0; i < sprites.Count; i++)
        {
            LotScene.Sprite s = sprites[i];
            if (s.DepthTexture is null || s.DynamicShadow == true)
                continue;
            hash = (hash ^ (ulong)(uint)s.Texture) * prime;
            hash = (hash ^ (ulong)(uint)s.DepthTexture.Value) * prime;
            hash = (hash ^ (ulong)(uint)BitConverter.SingleToInt32Bits(s.X)) * prime;
            hash = (hash ^ (ulong)(uint)BitConverter.SingleToInt32Bits(s.Y)) * prime;
            hash = (hash ^ (ulong)(uint)BitConverter.SingleToInt32Bits(s.Width)) * prime;
            hash = (hash ^ (ulong)(uint)BitConverter.SingleToInt32Bits(s.Height)) * prime;
            hash = (hash ^ (s.Flip ? 1UL : 0UL)) * prime;
        }
        return hash;
    }

    private (SimsSDL.Core.SceneViewport Viewport, Vector2 Canvas, LotZoom Zoom)? ComputeWorldShadowProjection(LotScene scene)
    {
        if (LotFrame(scene) is not { } frame ||
            scene.LotWidth is not int width || scene.LotHeight is not int height)
        {
            return null;
        }

        const int maxShadowW = 3456;
        const int maxShadowH = 2160;
        bool swapped = (scene.CameraOrientation ?? 0) % 2 != 0;
        float w = swapped ? height : width;
        float h = swapped ? width : height;
        int stories = Math.Max(2, scene.Stories ?? 2);
        float topHeadroom = 400f + (stories - 2) * PlacementPreview.StoryLiftPerLevel;
        float minX = frame.X - 32f * h - 128f;
        float spanX = 32f * (w + h) + 256f;
        float minY = frame.Y - topHeadroom;
        float spanY = 16f * (w + h) + topHeadroom + 128f;
        float shadowScale = MathF.Min(0.80f, MathF.Min(maxShadowW / spanX, maxShadowH / spanY));
        LotZoom shadowZoom = shadowScale >= MediumToNearZoomMidpoint ? LotZoom.Near : LotZoom.Medium;
        int shadowW = Math.Clamp((int)MathF.Ceiling(spanX * shadowScale), 512, maxShadowW);
        int shadowH = Math.Clamp((int)MathF.Ceiling(spanY * shadowScale), 512, maxShadowH);
        var shadowCanvas = new Vector2(shadowW, shadowH);
        var shadowViewport = new SimsSDL.Core.SceneViewport(shadowCanvas, shadowScale, new Vector2(-minX * shadowScale, -minY * shadowScale));
        return (shadowViewport, shadowCanvas, shadowZoom);
    }

    private unsafe ((GPUTexture Texture, Vector4? Frame) HeightMap, (GPUTexture Texture, Vector4? Frame) FootMap, GPUTexture WorldDepth, GPUTexture WorldBackDepth, SimsSDL.Core.SceneViewport? WorldViewport) EnsureWorldShadowMaps(
        nint command,
        GPUTexture screenDepth,
        SimsSDL.Core.SceneViewport screenViewport,
        Vector2 screenCanvas)
    {
        if (Scene is not { } scene || ComputeWorldShadowProjection(scene) is not var (shadowViewport, shadowCanvas, shadowZoom))
        {
            var hm = EncodeHeightMap(command, screenDepth, screenViewport, screenCanvas);
            var fm = EncodeHeightMap(command, screenDepth, screenViewport, screenCanvas, feet: true);
            return (hm, fm, screenDepth, screenDepth, null);
        }

        int shadowW = (int)shadowCanvas.X;
        int shadowH = (int)shadowCanvas.Y;
        string staticKey = $"{scene.House}:{_sceneRevision}:{scene.CameraOrientation}:{ViewLevel}:{RoofsVisible}:{_worldShadowSpriteSeq}:{HeightTexelsPerTile:0.##}:{shadowW}x{shadowH}";
        string key = $"{staticKey}:{_worldShadowAnimSeq}";
        if (_worldShadowDepth is not null
            && _worldShadowBackDepth is not null
            && _heightMapTexture is not null
            && _footMapTexture is not null
            && ReferenceEquals(_worldShadowScene, scene)
            && string.Equals(_worldShadowKey, key, StringComparison.Ordinal))
        {
            return ((_heightMapTexture, _worldHeightFrame), (_footMapTexture, _worldFootFrame), _worldShadowDepth, _worldShadowBackDepth, _worldShadowViewport);
        }

        if (_worldShadowColor is null || _worldShadowColor.Width != shadowW || _worldShadowColor.Height != shadowH)
        {
            Retire(_worldShadowColor);
            _worldShadowColor = GPU.MakeTexture(shadowW, shadowH, GPUContext.ColorFormat, SDL_GPU_TEXTUREUSAGE_COLOR_TARGET);
        }
        if (_worldShadowDepth is null || _worldShadowDepth.Width != shadowW || _worldShadowDepth.Height != shadowH)
        {
            Retire(_worldShadowDepth);
            _worldShadowDepth = GPU.MakeTexture(shadowW, shadowH, GPUContext.DepthFormat, SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        }
        if (_worldShadowBackDepth is null || _worldShadowBackDepth.Width != shadowW || _worldShadowBackDepth.Height != shadowH)
        {
            Retire(_worldShadowBackDepth);
            _worldShadowBackDepth = GPU.MakeTexture(shadowW, shadowH, GPUContext.DepthFormat, SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        }
        if (_worldShadowStaticDepth is null || _worldShadowStaticDepth.Width != shadowW || _worldShadowStaticDepth.Height != shadowH)
        {
            Retire(_worldShadowStaticDepth);
            _worldShadowStaticDepth = GPU.MakeTexture(shadowW, shadowH, GPUContext.DepthFormat, SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
            _worldShadowStaticKey = string.Empty;
        }
        if (_worldShadowStaticBackDepth is null || _worldShadowStaticBackDepth.Width != shadowW || _worldShadowStaticBackDepth.Height != shadowH)
        {
            Retire(_worldShadowStaticBackDepth);
            _worldShadowStaticBackDepth = GPU.MakeTexture(shadowW, shadowH, GPUContext.DepthFormat, SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
            _worldShadowStaticKey = string.Empty;
        }

        var colorTarget = new SDL_GPUColorTargetInfo
        {
            texture = _worldShadowColor.Handle,
            load_op = SDL_GPU_LOADOP_DONT_CARE,
            store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        bool staticNeedsRebuild = _heightMapTexture is null
            || _footMapTexture is null
            || !string.Equals(_worldShadowStaticKey, staticKey, StringComparison.Ordinal);

        if (staticNeedsRebuild)
        {
            var staticDepthTarget = new SDL_GPUDepthStencilTargetInfo
            {
                texture = _worldShadowStaticDepth.Handle,
                clear_depth = 1f,
                load_op = SDL_GPU_LOADOP_CLEAR,
                store_op = SDL_GPU_STOREOP_STORE,
                stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
                stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
            };
            nint staticPass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &staticDepthTarget);
            if (staticPass == 0)
                throw new SDLError("SDL_BeginGPURenderPass");
            try
            {
                EncodeLot(
                    staticPass,
                    command,
                    shadowCanvas,
                    SDL_GPU_SAMPLECOUNT_1,
                    deferTranslucentAvatars: true,
                    zoomOverride: shadowZoom,
                    skipTerrainAndRoads: true,
                    viewportOverride: shadowViewport,
                    shadowDepthOnly: true,
                    shadowBackLayer: false,
                    shadowFilter: ShadowItemFilter.StaticOnly);
            }
            finally
            {
                SDL_EndGPURenderPass(staticPass);
            }

            var staticBackDepthTarget = new SDL_GPUDepthStencilTargetInfo
            {
                texture = _worldShadowStaticBackDepth.Handle,
                clear_depth = 0f,
                load_op = SDL_GPU_LOADOP_CLEAR,
                store_op = SDL_GPU_STOREOP_STORE,
                stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
                stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
            };
            nint staticBackPass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &staticBackDepthTarget);
            if (staticBackPass == 0)
                throw new SDLError("SDL_BeginGPURenderPass");
            try
            {
                EncodeLot(
                    staticBackPass,
                    command,
                    shadowCanvas,
                    SDL_GPU_SAMPLECOUNT_1,
                    deferTranslucentAvatars: true,
                    zoomOverride: shadowZoom,
                    skipTerrainAndRoads: true,
                    viewportOverride: shadowViewport,
                    shadowDepthOnly: true,
                    shadowBackLayer: true,
                    shadowFilter: ShadowItemFilter.StaticOnly);
            }
            finally
            {
                SDL_EndGPURenderPass(staticBackPass);
            }

            var hmWorld = EncodeHeightMap(command, _worldShadowStaticDepth, shadowViewport, shadowCanvas);
            var fmWorld = EncodeHeightMap(command, _worldShadowStaticDepth, shadowViewport, shadowCanvas, feet: true);
            _worldHeightFrame = hmWorld.Frame;
            _worldFootFrame = fmWorld.Frame;
            _worldShadowStaticKey = staticKey;
        }

        bool dynamicOnlyWorld = _voxelMap is not null;
        if (!dynamicOnlyWorld)
        {
            nint copyPass = SDL_BeginGPUCopyPass(command);
            if (copyPass == 0)
                throw new SDLError("SDL_BeginGPUCopyPass");
            try
            {
                var srcFront = new SDL_GPUTextureLocation { texture = _worldShadowStaticDepth.Handle };
                var dstFront = new SDL_GPUTextureLocation { texture = _worldShadowDepth.Handle };
                SDL_CopyGPUTextureToTexture(copyPass, in srcFront, in dstFront, (uint)shadowW, (uint)shadowH, 1, false);
                var srcBack = new SDL_GPUTextureLocation { texture = _worldShadowStaticBackDepth.Handle };
                var dstBack = new SDL_GPUTextureLocation { texture = _worldShadowBackDepth.Handle };
                SDL_CopyGPUTextureToTexture(copyPass, in srcBack, in dstBack, (uint)shadowW, (uint)shadowH, 1, false);
            }
            finally
            {
                SDL_EndGPUCopyPass(copyPass);
            }
        }

        bool hasDynamicItems = (scene.Meshes is not null && scene.Meshes.Count > _staticMeshes.Count) || _hasDynamicShadowSprites;
        if (dynamicOnlyWorld || hasDynamicItems)
        {
            var depthTarget = new SDL_GPUDepthStencilTargetInfo
            {
                texture = _worldShadowDepth.Handle,
                clear_depth = 1f,
                load_op = dynamicOnlyWorld ? SDL_GPU_LOADOP_CLEAR : SDL_GPU_LOADOP_LOAD,
                store_op = SDL_GPU_STOREOP_STORE,
                stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
                stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
            };
            nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget);
            if (pass == 0)
                throw new SDLError("SDL_BeginGPURenderPass");
            try
            {
                if (hasDynamicItems)
                {
                    EncodeLot(
                        pass,
                        command,
                        shadowCanvas,
                        SDL_GPU_SAMPLECOUNT_1,
                        deferTranslucentAvatars: true,
                        zoomOverride: shadowZoom,
                        skipTerrainAndRoads: true,
                        viewportOverride: shadowViewport,
                        shadowDepthOnly: true,
                        shadowBackLayer: false,
                        shadowFilter: ShadowItemFilter.DynamicOnly);
                }
            }
            finally
            {
                SDL_EndGPURenderPass(pass);
            }

            var backDepthTarget = new SDL_GPUDepthStencilTargetInfo
            {
                texture = _worldShadowBackDepth.Handle,
                clear_depth = 0f,
                load_op = dynamicOnlyWorld ? SDL_GPU_LOADOP_CLEAR : SDL_GPU_LOADOP_LOAD,
                store_op = SDL_GPU_STOREOP_STORE,
                stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
                stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
            };
            nint backPass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &backDepthTarget);
            if (backPass == 0)
                throw new SDLError("SDL_BeginGPURenderPass");
            try
            {
                if (hasDynamicItems)
                {
                    EncodeLot(
                        backPass,
                        command,
                        shadowCanvas,
                        SDL_GPU_SAMPLECOUNT_1,
                        deferTranslucentAvatars: true,
                        zoomOverride: shadowZoom,
                        skipTerrainAndRoads: true,
                        viewportOverride: shadowViewport,
                        shadowDepthOnly: true,
                        shadowBackLayer: true,
                        shadowFilter: ShadowItemFilter.DynamicOnly);
                }
            }
            finally
            {
                SDL_EndGPURenderPass(backPass);
            }
        }

        _worldShadowScene = scene;
        _worldShadowKey = key;
        _worldShadowViewport = shadowViewport;
        return ((_heightMapTexture!, _worldHeightFrame), (_footMapTexture!, _worldFootFrame), _worldShadowDepth, _worldShadowBackDepth, shadowViewport);
    }

    private unsafe (GPUTexture Texture, Vector4? Frame) EncodeHeightMap(
        nint command,
        GPUTexture depth,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas,
        bool feet = false)
    {
        if (Scene is null || LotFrame(Scene) is not { } frame ||
            Scene.LotWidth is not int width || Scene.LotHeight is not int height)
        {
            return (HeightTexture(1, 1, feet), null);
        }

        bool swapped = (Scene.CameraOrientation ?? 0) % 2 != 0;
        float texels = HeightTexelsPerTile;
        float margin = _heightMargin;
        Vector2 grid = new Vector2(swapped ? height : width, swapped ? width : height) + new Vector2(2f * margin);
        GPUTexture texture = HeightTexture((int)(grid.X * texels), (int)(grid.Y * texels), feet);

        var depthTarget = new SDL_GPUDepthStencilTargetInfo
        {
            texture = texture.Handle,
            clear_depth = 1f,
            load_op = SDL_GPU_LOADOP_CLEAR,
            store_op = SDL_GPU_STOREOP_STORE,
            stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
            stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        nint pass = SDL_BeginGPURenderPass(command, null, 0, &depthTarget);
        if (pass == 0)
            throw new SDLError("SDL_BeginGPURenderPass");

        try
        {
            SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(GPUContext.Program.HeightScatter, GPUContext.DepthMode.Flat));
            var binding = new SDL_GPUTextureSamplerBinding { texture = depth.Handle, sampler = GPU.PixelSampler };
            SDL_BindGPUVertexSamplers(pass, 0, &binding, 1);

            float stride = MathF.Max(1f, MathF.Floor(0.5f * viewport.Scale));
            float columns = MathF.Ceiling(canvas.X / stride);
            float rows = MathF.Ceiling(canvas.Y / stride);

            Vector4* uniforms = stackalloc Vector4[4];
            uniforms[0] = new Vector4(viewport.Origin.X, viewport.Origin.Y, viewport.Scale, stride);
            uniforms[1] = new Vector4(canvas.X, canvas.Y, columns, feet ? 1f : 0f);
            uniforms[2] = new Vector4(frame.X, frame.Y, texels, margin);
            uniforms[3] = new Vector4(texture.Width, texture.Height, 0f, 0f);
            SDL_PushGPUVertexUniformData(command, 0, (nint)uniforms, (uint)(4 * sizeof(Vector4)));
            SDL_DrawGPUPrimitives(pass, (uint)(columns * rows), 1, 0, 0);
        }
        finally
        {
            SDL_EndGPURenderPass(pass);
        }

        return (texture, new Vector4(frame.X, frame.Y, texels, margin));
    }

    private GPUTexture GroundTexture(int width, int height)
    {
        if (_groundDepthTexture is not null && _groundDepthTexture.Width == width && _groundDepthTexture.Height == height)
            return _groundDepthTexture;

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.DepthFormat,
            SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_groundDepthTexture);
        _groundDepthTexture = texture;
        return texture;
    }

    private GPUTexture DepthSpritePrepassDepthTexture(int width, int height)
    {
        if (_depthSpritePrepassDepth is not null && _depthSpritePrepassDepth.Width == width && _depthSpritePrepassDepth.Height == height)
            return _depthSpritePrepassDepth;

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.DepthFormat,
            SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_depthSpritePrepassDepth);
        _depthSpritePrepassDepth = texture;
        return texture;
    }

    private GPUTexture DepthSpriteColorTexture(int width, int height)
    {
        if (_depthSpriteColorTexture is not null && _depthSpriteColorTexture.Width == width && _depthSpriteColorTexture.Height == height)
            return _depthSpriteColorTexture;

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.ColorFormat,
            SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_depthSpriteColorTexture);
        _depthSpriteColorTexture = texture;
        return texture;
    }

    private unsafe GPUTexture EncodeSimMask(nint command, GPUTexture depth, SimsSDL.Core.SceneViewport viewport, Vector2 canvas)
    {
        uint usage = SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER;
        List<int> sims = [];
        if (Scene?.Meshes is { } meshes)
        {
            for (int i = 0; i < meshes.Count && i < _meshSlices.Count; i++)
            {
                if (meshes[i].Unlit != true && meshes[i].Roof is null && !IsTranslucentAvatarMesh(meshes[i]) && _meshSlices[i] is not null)
                    sims.Add(i);
            }
        }

        if (Scene is null || sims.Count == 0)
        {
            if (_emptySimMaskTexture is not null)
                return _emptySimMaskTexture;
            _emptySimMaskTexture = GPU.MakeTexture(1, 1, GPUContext.MaskFormat, usage);
            return _emptySimMaskTexture;
        }

        GPUTexture mask;
        if (_simMaskTexture is not null && _simMaskTexture.Width == depth.Width && _simMaskTexture.Height == depth.Height)
        {
            mask = _simMaskTexture;
        }
        else
        {
            Retire(_simMaskTexture);
            mask = GPU.MakeTexture(depth.Width, depth.Height, GPUContext.MaskFormat, usage);
            _simMaskTexture = mask;
        }

        var colorTarget = new SDL_GPUColorTargetInfo
        {
            texture = mask.Handle,
            load_op = SDL_GPU_LOADOP_CLEAR,
            store_op = SDL_GPU_STOREOP_STORE,
        };
        var depthTarget = new SDL_GPUDepthStencilTargetInfo
        {
            texture = depth.Handle,
            load_op = SDL_GPU_LOADOP_LOAD,
            store_op = SDL_GPU_STOREOP_STORE,
            stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
            stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget);
        if (pass == 0)
            throw new SDLError("SDL_BeginGPURenderPass");

        try
        {
            var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
            SDL_SetGPUScissor(pass, in scissor);
            SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(GPUContext.Program.AvatarMask, GPUContext.DepthMode.Mesh));

            nint boundBufferHandle = 0;
            foreach (int index in sims)
            {
                LotScene.Mesh mesh = Scene.Meshes![index];
                if (_meshSlices[index] is not { } slice || slice.Buffer.Handle == nint.Zero)
                    continue;

                var binding = new SDL_GPUTextureSamplerBinding
                {
                    texture = _sceneTextures[mesh.TextureFor(EffectiveVisualZoom)].Handle,
                    sampler = GPU.Sampler,
                };
                SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1);

                if (boundBufferHandle != slice.Buffer.Handle)
                {
                    boundBufferHandle = slice.Buffer.Handle;
                    nint handle = slice.Buffer.Handle;
                    SDL_BindGPUVertexStorageBuffers(pass, 0, &handle, 1);
                }

                var transform = new Quad(new Vector4(viewport.Origin.X, viewport.Origin.Y, viewport.Scale, viewport.Scale), canvas)
                {
                    DepthInterval = new Vector4(BitConverter.UInt32BitsToSingle(slice.FirstVertex), 0f, 0f, 0f),
                };
                if (CharacterDetail == 0)
                    transform.UvRect = new Vector4(1f, transform.UvRect.Y, transform.UvRect.Z, transform.UvRect.W);

                SDL_PushGPUVertexUniformData(command, 0, (nint)(&transform), (uint)sizeof(Quad));
                SDL_DrawGPUPrimitives(pass, slice.VertexCount, 1, 0, 0);
            }
        }
        finally
        {
            SDL_EndGPURenderPass(pass);
        }

        return mask;
    }

    private GPUTexture SurfaceTexture(int width, int height)
    {
        if (_surfaceSourceTexture is not null && _surfaceSourceTexture.Width == width && _surfaceSourceTexture.Height == height)
            return _surfaceSourceTexture;

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.ColorFormat,
            SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_surfaceSourceTexture);
        _surfaceSourceTexture = texture;
        return texture;
    }

    private unsafe void EncodeGroundDepth(nint command, GPUTexture depth, SimsSDL.Core.SceneViewport viewport, Vector2 canvas)
    {
        GPUBuffer? groundBuf = _terrainBuffer;
        if (groundBuf is null || groundBuf.Handle == nint.Zero)
            return;

        GPUBuffer? surBuf = _surroundingsTerrain;
        nint surHandleKey = surBuf is { Handle: not 0 } ? surBuf.Handle : nint.Zero;
        int surCountKey = surHandleKey != nint.Zero ? surBuf!.Count : 0;
        var key = (groundBuf.Handle, groundBuf.Count, surHandleKey, surCountKey, depth.Handle, _sceneRevision, viewport.Origin.X, viewport.Origin.Y, viewport.Scale, canvas.X, canvas.Y);
        if (_groundDepthCacheKey == key)
            return;

        var depthTarget = new SDL_GPUDepthStencilTargetInfo
        {
            texture = depth.Handle,
            clear_depth = 1f,
            load_op = SDL_GPU_LOADOP_CLEAR,
            store_op = SDL_GPU_STOREOP_STORE,
            stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
            stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        nint pass = SDL_BeginGPURenderPass(command, null, 0, &depthTarget);
        if (pass == 0)
            throw new SDLError("SDL_BeginGPURenderPass");

        try
        {
            var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
            SDL_SetGPUScissor(pass, in scissor);
            SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(GPUContext.Program.GroundDepth, GPUContext.DepthMode.Flat));
            var transform = new Quad(new Vector4(viewport.Origin.X, viewport.Origin.Y, viewport.Scale, viewport.Scale), canvas);
            SDL_PushGPUVertexUniformData(command, 0, (nint)(&transform), (uint)sizeof(Quad));
            if (surHandleKey != nint.Zero)
            {
                nint surHandle = surHandleKey;
                SDL_BindGPUVertexStorageBuffers(pass, 0, &surHandle, 1);
                SDL_DrawGPUPrimitives(pass, (uint)surCountKey, 1, 0, 0);
            }
            nint handle = groundBuf.Handle;
            SDL_BindGPUVertexStorageBuffers(pass, 0, &handle, 1);
            SDL_DrawGPUPrimitives(pass, (uint)groundBuf.Count, 1, 0, 0);
        }
        finally
        {
            SDL_EndGPURenderPass(pass);
        }
        _groundDepthCacheKey = key;
    }

    private unsafe GPUTexture EncodeDepthSpriteColor(
        nint command,
        GPUTexture sceneDepth,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas)
    {
        GPUTexture depthCopy = DepthSpritePrepassDepthTexture(sceneDepth.Width, sceneDepth.Height);
        nint copy = SDL_BeginGPUCopyPass(command);
        if (copy == 0)
            throw new SDLError("SDL_BeginGPUCopyPass");
        try
        {
            var src = new SDL_GPUTextureLocation { texture = sceneDepth.Handle };
            var dst = new SDL_GPUTextureLocation { texture = depthCopy.Handle };
            SDL_CopyGPUTextureToTexture(copy, in src, in dst, (uint)sceneDepth.Width, (uint)sceneDepth.Height, 1, false);
        }
        finally
        {
            SDL_EndGPUCopyPass(copy);
        }

        GPUTexture spriteLayer = DepthSpriteColorTexture(sceneDepth.Width, sceneDepth.Height);
        var colorTarget = new SDL_GPUColorTargetInfo
        {
            texture = spriteLayer.Handle,
            clear_color = new SDL_FColor { r = 0f, g = 0f, b = 0f, a = 0f },
            load_op = SDL_GPU_LOADOP_CLEAR,
            store_op = SDL_GPU_STOREOP_STORE,
        };
        var depthTarget = new SDL_GPUDepthStencilTargetInfo
        {
            texture = depthCopy.Handle,
            load_op = SDL_GPU_LOADOP_LOAD,
            store_op = SDL_GPU_STOREOP_STORE,
            stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
            stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget);
        if (pass == 0)
            throw new SDLError("SDL_BeginGPURenderPass");

        try
        {
            if (Scene is not { } scene || (_drawItems.Count == 0 && _surroundingsDecorations.Count == 0))
                return spriteLayer;

            var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
            SDL_SetGPUScissor(pass, in scissor);

            float scale = viewport.Scale;
            Vector2 origin = viewport.Origin;
            LotZoom zoom = AssetZoomForScale(scale, EffectiveVisualZoom);
            float artTexelScale = scale / zoom.Factor();
            bool settledIntegerUi = MathF.Abs(artTexelScale - MathF.Round(artTexelScale, MidpointRounding.AwayFromZero)) <= 1e-4f
                && !IsZoomInterpolating;
            nint artSampler = settledIntegerUi ? GPU.PixelSampler : GPU.Sampler;
            nint spriteSampler = AntiAliasedSprites ? GPU.Sampler : artSampler;
            bool spriteMinified = artTexelScale < 0.99f;
            nint colorSpriteSampler = AntiAliasedSprites && spriteMinified ? GPU.AnisoSampler : spriteSampler;
            SimsSDL.Core.SceneLighting? lighting = ActiveLighting(scene);
            float coreAlphaCutoff = scale < 0.14f ? 0.45f : 0.985f;
            nint currentPipeline = 0;
            (nint T0, nint T1)? lastBound = null;
            SDL_GPUTextureSamplerBinding* bindings = stackalloc SDL_GPUTextureSamplerBinding[2];

            (int Level, int Layer) ItemGroup(SceneDrawItem item) => item.Kind switch
            {
                SceneDrawItem.ItemKind.Sprite => (uint)item.Index < (uint)scene.Sprites.Count
                    ? (scene.Sprites[item.Index].Level ?? 1, scene.Sprites[item.Index].Layer ?? 0)
                    : (1, 0),
                _ => scene.Meshes is { } itemMeshes && (uint)item.Index < (uint)itemMeshes.Count
                    ? (itemMeshes[item.Index].Level ?? 1, itemMeshes[item.Index].Layer ?? 1)
                    : (1, 1),
            };

            void DrawSingleDepthSprite(LotScene.Sprite sprite, nint pipeline, SpritePassMode passMode)
            {
                if (sprite.Wall is not null || (zoom == LotZoom.Far && sprite.HideAtFarZoom == true))
                    return;

                int texture = sprite.Texture;
                int? depthTexture = sprite.DepthTexture;
                var rect = new Vector4(sprite.X, sprite.Y, sprite.Width, sprite.Height);
                if (sprite.Image(zoom) is { } image)
                {
                    texture = image.Texture;
                    depthTexture = image.DepthTexture;
                    rect = new Vector4(sprite.X + image.X, sprite.Y + image.Y, image.Width, image.Height);
                }

                if (depthTexture is not int dt || (uint)texture >= (uint)_sceneTextures.Count || (uint)dt >= (uint)_sceneTextures.Count)
                    return;

                if (origin.X + (rect.X + rect.Z) * scale < 0f ||
                    origin.Y + (rect.Y + rect.W) * scale < 0f ||
                    origin.X + rect.X * scale >= canvas.X ||
                    origin.Y + rect.Y * scale >= canvas.Y)
                {
                    return;
                }

                if (currentPipeline != pipeline)
                {
                    SDL_BindGPUGraphicsPipeline(pass, pipeline);
                    currentPipeline = pipeline;
                    lastBound = null;
                }

                nint t0 = _sceneTextures[texture].Handle;
                nint t1 = _sceneTextures[dt].Handle;
                if (t0 == 0 || t1 == 0)
                    return;
                if (lastBound != (t0, t1))
                {
                    bindings[0] = new SDL_GPUTextureSamplerBinding { texture = t0, sampler = colorSpriteSampler };
                    bindings[1] = new SDL_GPUTextureSamplerBinding { texture = t1, sampler = GPU.PixelSampler };
                    SDL_BindGPUFragmentSamplers(pass, 0, bindings, 2);
                    lastBound = (t0, t1);
                }

                float depthNear = sprite.DepthNear ?? 0f;
                float depthFar = sprite.DepthFar ?? 0f;
                var quad = new Quad(
                    new Vector4(origin.X + rect.X * scale, origin.Y + rect.Y * scale, rect.Z * scale, rect.W * scale),
                    canvas,
                    sprite.Flip)
                {
                    DepthInterval = passMode == SpritePassMode.EdgeFringe
                        ? new Vector4(depthNear, depthFar, 0.985f, AntiAliasedSprites ? 2f : -1f)
                        : new Vector4(depthNear, depthFar, coreAlphaCutoff, AntiAliasedSprites ? 1f : 0f),
                    Tint = EffectiveRoomTint(lighting, sprite.Room),
                };
                SDL_PushGPUVertexUniformData(command, 0, (nint)(&quad), (uint)sizeof(Quad));
                SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
            }

            void DrawDepthSpritePass(int sliceStart, int sliceEnd, SpritePassMode passMode, bool interleaveSurroundings)
            {
                nint pipeline = passMode == SpritePassMode.EdgeFringe ? GPU.SpriteDepthEdgePipeline : GPU.SpriteDepthPipeline;
                int surCursor = 0;
                for (int i = sliceStart; i < sliceEnd; i++)
                {
                    SceneDrawItem item = _drawItems[i];
                    if (interleaveSurroundings)
                    {
                        float curDepth = item.Kind == SceneDrawItem.ItemKind.Sprite && (uint)item.Index < (uint)scene.Sprites.Count
                            ? (scene.Sprites[item.Index].Depth ?? item.Index)
                            : (scene.Meshes is { } itemMeshes && (uint)item.Index < (uint)itemMeshes.Count ? itemMeshes[item.Index].Depth : 0f);
                        while (surCursor < _surroundingsDecorations.Count && (_surroundingsDecorations[surCursor].Depth ?? 0f) <= curDepth)
                            DrawSingleDepthSprite(_surroundingsDecorations[surCursor++], pipeline, passMode);
                    }
                    if (item.Kind != SceneDrawItem.ItemKind.Sprite || (uint)item.Index >= (uint)scene.Sprites.Count)
                        continue;

                    DrawSingleDepthSprite(scene.Sprites[item.Index], pipeline, passMode);
                }
                if (interleaveSurroundings)
                {
                    while (surCursor < _surroundingsDecorations.Count)
                        DrawSingleDepthSprite(_surroundingsDecorations[surCursor++], pipeline, passMode);
                }
            }

            bool drewSurroundings = _surroundingsDecorations.Count == 0;
            int sliceStart = 0;
            while (sliceStart < _drawItems.Count)
            {
                (int itemLevel, int itemLayer) = ItemGroup(_drawItems[sliceStart]);
                int sliceEnd = sliceStart + 1;
                while (sliceEnd < _drawItems.Count)
                {
                    (int nextLevel, int nextLayer) = ItemGroup(_drawItems[sliceEnd]);
                    if (nextLevel != itemLevel || nextLayer != itemLayer)
                        break;
                    sliceEnd += 1;
                }

                bool interleaveHere = !drewSurroundings && itemLevel == 1 && itemLayer == 1;
                if (interleaveHere)
                    drewSurroundings = true;

                DrawDepthSpritePass(sliceStart, sliceEnd, SpritePassMode.OpaqueCore, interleaveHere);
                if (scale >= 0.14f)
                    DrawDepthSpritePass(sliceStart, sliceEnd, SpritePassMode.EdgeFringe, interleaveHere);
                sliceStart = sliceEnd;
            }
            if (!drewSurroundings)
            {
                for (int d = 0; d < _surroundingsDecorations.Count; d++)
                    DrawSingleDepthSprite(_surroundingsDecorations[d], GPU.SpriteDepthPipeline, SpritePassMode.OpaqueCore);
                if (scale >= 0.14f)
                {
                    for (int d = 0; d < _surroundingsDecorations.Count; d++)
                        DrawSingleDepthSprite(_surroundingsDecorations[d], GPU.SpriteDepthEdgePipeline, SpritePassMode.EdgeFringe);
                }
            }
        }
        finally
        {
            SDL_EndGPURenderPass(pass);
        }

        return spriteLayer;
    }

    private unsafe void EncodeDepthSpriteStamp(
        nint command,
        GPUTexture colorTargetTex,
        GPUTexture targetDepth,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas,
        float alphaCutoff)
    {
        if (Scene is not { } scene || (_drawItems.Count == 0 && _surroundingsDecorations.Count == 0))
            return;

        var colorTarget = new SDL_GPUColorTargetInfo
        {
            texture = colorTargetTex.Handle,
            load_op = SDL_GPU_LOADOP_LOAD,
            store_op = SDL_GPU_STOREOP_STORE,
        };
        var depthTarget = new SDL_GPUDepthStencilTargetInfo
        {
            texture = targetDepth.Handle,
            load_op = SDL_GPU_LOADOP_LOAD,
            store_op = SDL_GPU_STOREOP_STORE,
            stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
            stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget);
        if (pass == 0)
            throw new SDLError("SDL_BeginGPURenderPass");

        try
        {
            var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
            SDL_SetGPUScissor(pass, in scissor);
            SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(GPUContext.Program.SpriteDepth, GPUContext.DepthMode.MeshDepthPrepass));

            float scale = viewport.Scale;
            Vector2 origin = viewport.Origin;
            LotZoom zoom = AssetZoomForScale(scale, EffectiveVisualZoom);
            float artTexelScale = scale / zoom.Factor();
            bool settledIntegerUi = MathF.Abs(artTexelScale - MathF.Round(artTexelScale, MidpointRounding.AwayFromZero)) <= 1e-4f
                && !IsZoomInterpolating;
            nint artSampler = settledIntegerUi ? GPU.PixelSampler : GPU.Sampler;
            nint spriteSampler = AntiAliasedSprites ? GPU.Sampler : artSampler;
            bool spriteMinified = artTexelScale < 0.99f;
            nint colorSpriteSampler = AntiAliasedSprites && spriteMinified ? GPU.AnisoSampler : spriteSampler;
            float modeFlag = AntiAliasedSprites ? 1f : 0f;
            (nint T0, nint T1)? lastBound = null;
            SDL_GPUTextureSamplerBinding* bindings = stackalloc SDL_GPUTextureSamplerBinding[2];

            void StampSingleDepthSprite(LotScene.Sprite sprite)
            {
                if (sprite.Wall is not null || sprite.HideAtFarZoom == true)
                    return;

                int texture = sprite.Texture;
                int? depthTexture = sprite.DepthTexture;
                var rect = new Vector4(sprite.X, sprite.Y, sprite.Width, sprite.Height);
                if (sprite.Image(zoom) is { } image)
                {
                    texture = image.Texture;
                    depthTexture = image.DepthTexture;
                    rect = new Vector4(sprite.X + image.X, sprite.Y + image.Y, image.Width, image.Height);
                }

                if (depthTexture is not int dt || (uint)texture >= (uint)_sceneTextures.Count || (uint)dt >= (uint)_sceneTextures.Count)
                    return;

                if (origin.X + (rect.X + rect.Z) * scale < 0f ||
                    origin.Y + (rect.Y + rect.W) * scale < 0f ||
                    origin.X + rect.X * scale >= canvas.X ||
                    origin.Y + rect.Y * scale >= canvas.Y)
                {
                    return;
                }

                nint t0 = _sceneTextures[texture].Handle;
                nint t1 = _sceneTextures[dt].Handle;
                if (t0 == 0 || t1 == 0)
                    return;
                if (lastBound != (t0, t1))
                {
                    bindings[0] = new SDL_GPUTextureSamplerBinding { texture = t0, sampler = colorSpriteSampler };
                    bindings[1] = new SDL_GPUTextureSamplerBinding { texture = t1, sampler = GPU.PixelSampler };
                    SDL_BindGPUFragmentSamplers(pass, 0, bindings, 2);
                    lastBound = (t0, t1);
                }

                var quad = new Quad(
                    new Vector4(origin.X + rect.X * scale, origin.Y + rect.Y * scale, rect.Z * scale, rect.W * scale),
                    canvas,
                    sprite.Flip)
                {
                    DepthInterval = new Vector4(sprite.DepthNear ?? 0f, sprite.DepthFar ?? 0f, alphaCutoff, modeFlag),
                    Tint = Vector4.One,
                };
                SDL_PushGPUVertexUniformData(command, 0, (nint)(&quad), (uint)sizeof(Quad));
                SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
            }

            for (int i = 0; i < _drawItems.Count; i++)
            {
                SceneDrawItem item = _drawItems[i];
                if (item.Kind == SceneDrawItem.ItemKind.Sprite && (uint)item.Index < (uint)scene.Sprites.Count)
                    StampSingleDepthSprite(scene.Sprites[item.Index]);
            }

            for (int d = 0; d < _surroundingsDecorations.Count; d++)
                StampSingleDepthSprite(_surroundingsDecorations[d]);
        }
        finally
        {
            SDL_EndGPURenderPass(pass);
        }
    }

    private sealed class PluginRenderFrame(
        LotRenderer renderer,
        nint command,
        GPUTexture sceneColor,
        GPUTexture sceneDepth,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas,
        PluginLotRenderState sceneState) : IPluginRenderContext
    {
        private readonly List<GPUTexture> _handles = [];
        private readonly Dictionary<GPUTexture, PluginTextureHandle> _handleByTex = new(ReferenceEqualityComparer.Instance);
        private readonly Dictionary<string, PluginTextureHandle> _shared = new(StringComparer.Ordinal);
        private GPUTexture? _groundDepth;
        private bool _worldShadowsBuilt;
        private GPUTexture? _heightMap;
        private GPUTexture? _footMap;
        private GPUTexture? _worldDepth;
        private GPUTexture? _worldBackDepth;
        private GPUTexture? _simMask;
        private GPUTexture? _depthSpriteColor;

        public string ActivePackId { get; set; } = string.Empty;
        public PluginRenderStage Stage { get; set; }
        public PluginLotRenderState Scene => sceneState;

        private PluginTextureHandle Register(GPUTexture tex)
        {
            if (_handleByTex.TryGetValue(tex, out var existing))
                return existing;
            int id = _handles.Count + 1;
            _handles.Add(tex);
            var handle = new PluginTextureHandle(id, tex.Width, tex.Height);
            _handleByTex[tex] = handle;
            return handle;
        }

        private GPUTexture Resolve(PluginTextureHandle handle)
        {
            int idx = handle.Id - 1;
            if ((uint)idx >= (uint)_handles.Count)
                throw new ArgumentException("Invalid plugin texture handle", nameof(handle));
            return _handles[idx];
        }

        private void EnsureWorldShadows()
        {
            if (_worldShadowsBuilt)
                return;
            _worldShadowsBuilt = true;
            var (hm, fm, wd, wbd, _) = renderer.EnsureWorldShadowMaps(command, sceneDepth, viewport, canvas);
            _heightMap = hm.Texture;
            _footMap = fm.Texture;
            _worldDepth = wd;
            _worldBackDepth = wbd;
        }

        public PluginTextureHandle AcquireSceneBuffer(SceneBufferKind kind)
        {
            GPUTexture tex = kind switch
            {
                SceneBufferKind.SceneColor => sceneColor,
                SceneBufferKind.SceneDepth => sceneDepth,
                SceneBufferKind.GroundDepth => _groundDepth ??= BuildGroundDepth(),
                SceneBufferKind.LotHeightMap => BuildWorldShadowBuffer(0),
                SceneBufferKind.LotFootHeightMap => BuildWorldShadowBuffer(1),
                SceneBufferKind.WorldShadowDepth => BuildWorldShadowBuffer(2),
                SceneBufferKind.WorldShadowBackDepth => BuildWorldShadowBuffer(3),
                SceneBufferKind.IndoorArchitectureMask => renderer._indoorMask ?? renderer.EmptyIndoorMask(),
                SceneBufferKind.OverheadMap => renderer._overheadMap ?? renderer.EmptyOverheadMap(),
                SceneBufferKind.VoxelMap => renderer._voxelMap ?? renderer.EmptyTransparent(),
                SceneBufferKind.AvatarMask => _simMask ??= renderer.EncodeSimMask(command, sceneDepth, viewport, canvas),
                SceneBufferKind.DepthSpriteColor => _depthSpriteColor ??= renderer.EncodeDepthSpriteColor(command, sceneDepth, viewport, canvas),
                SceneBufferKind.EmptyTransparent => renderer.EmptyTransparent(),
                SceneBufferKind.EmptyFloat16 => renderer.EmptyLift(),
                SceneBufferKind.EmptyIndoorMask => renderer.EmptyIndoorMask(),
                _ => throw new ArgumentOutOfRangeException(nameof(kind)),
            };
            return Register(tex);
        }

        private GPUTexture BuildGroundDepth()
        {
            GPUTexture gd = renderer.GroundTexture(sceneColor.Width, sceneColor.Height);
            renderer.EncodeGroundDepth(command, gd, viewport, canvas);
            return gd;
        }

        private GPUTexture BuildWorldShadowBuffer(int slot)
        {
            EnsureWorldShadows();
            return slot switch
            {
                0 => _heightMap!,
                1 => _footMap!,
                2 => _worldDepth!,
                _ => _worldBackDepth!,
            };
        }

        public PluginTextureHandle GetOrCreateTarget(string key, int width, int height, PluginTextureFormat format, out bool wasCreated)
        {
            if (string.IsNullOrEmpty(key) || key.Length > 64)
                throw new ArgumentException("Invalid target key", nameof(key));
            if (width is <= 0 or > 8192 || height is <= 0 or > 8192)
                throw new ArgumentOutOfRangeException(nameof(width));

            uint gpuFormat = GPUContext.ResolveTextureFormat(format);
            uint usage = format == PluginTextureFormat.Depth32Float
                ? SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER
                : SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER;

            var dictKey = (ActivePackId, key);
            if (renderer._pluginRenderTargets.TryGetValue(dictKey, out GPUTexture? existing)
                && existing.Width == width
                && existing.Height == height
                && existing.Format == gpuFormat)
            {
                wasCreated = false;
                return Register(existing);
            }

            renderer.Retire(existing);
            GPUTexture created = renderer.GPU.MakeTexture(width, height, gpuFormat, usage);
            renderer._pluginRenderTargets[dictKey] = created;
            wasCreated = true;
            return Register(created);
        }

        public PluginTextureHandle UploadTexture(string key, int width, int height, ReadOnlySpan<byte> rgba)
        {
            if (string.IsNullOrEmpty(key) || key.Length > 64)
                throw new ArgumentException("Invalid texture key", nameof(key));
            if (width is <= 0 or > 4096 || height is <= 0 or > 4096 || rgba.Length != checked(width * height * 4))
                throw new ArgumentException("Invalid RGBA upload dimensions");

            ulong hash = 14695981039346656037UL ^ (uint)rgba.Length;
            for (int i = 0; i < rgba.Length; i++)
                hash = (hash ^ rgba[i]) * 1099511628211UL;

            var dictKey = (ActivePackId, key);
            if (renderer._pluginUploadedTextures.TryGetValue(dictKey, out var cached)
                && cached.Width == width
                && cached.Height == height
                && cached.Hash == hash)
            {
                return Register(cached.Texture);
            }

            renderer.Retire(cached.Texture);
            GPUTexture uploaded = renderer.GPU.UploadDataTexture(width, height, rgba.ToArray());
            renderer._pluginUploadedTextures[dictKey] = (width, height, hash, uploaded);
            return Register(uploaded);
        }

        public void ShareTexture(string globalKey, PluginTextureHandle texture)
        {
            if (string.IsNullOrEmpty(globalKey) || globalKey.Length > 64)
                throw new ArgumentException("Invalid shared texture key", nameof(globalKey));
            _ = Resolve(texture);
            _shared[globalKey] = texture;
        }

        public bool TryGetSharedTexture(string globalKey, out PluginTextureHandle texture) =>
            _shared.TryGetValue(globalKey, out texture);

        public void CopyTexture(PluginTextureHandle source, PluginTextureHandle destination)
        {
            GPUTexture src = Resolve(source);
            GPUTexture dst = Resolve(destination);
            if (src.Width != dst.Width || src.Height != dst.Height || src.Format != dst.Format)
                throw new ArgumentException("CopyTexture requires matching dimensions and texture format");

            nint copy = SDL_BeginGPUCopyPass(command);
            if (copy == 0)
                throw new SDLError("SDL_BeginGPUCopyPass");
            try
            {
                var from = new SDL_GPUTextureLocation { texture = src.Handle };
                var to = new SDL_GPUTextureLocation { texture = dst.Handle };
                SDL_CopyGPUTextureToTexture(copy, in from, in to, (uint)src.Width, (uint)src.Height, 1, false);
            }
            finally
            {
                SDL_EndGPUCopyPass(copy);
            }
        }

        public void StampDepthSprites(PluginTextureHandle depthTarget, float alphaCutoff)
        {
            GPUTexture depth = Resolve(depthTarget);
            if (depth.Format != GPUContext.DepthFormat)
                throw new ArgumentException("StampDepthSprites requires a Depth32Float target", nameof(depthTarget));
            renderer.EncodeDepthSpriteStamp(command, sceneColor, depth, viewport, canvas, alphaCutoff);
        }

        public unsafe void DrawFullscreenPass(
            string fragmentShaderResource,
            PluginTextureHandle target,
            PluginBlendMode blendMode,
            bool loadTarget,
            ReadOnlySpan<PluginTextureHandle> sampledTextures,
            ReadOnlySpan<byte> uniformBytes,
            PluginTextureHandle? secondaryTarget = null,
            uint linearSamplerMask = 0)
        {
            if (renderer.ClientPlugins?.ResolveShaderBasePath(ActivePackId, fragmentShaderResource) is not { } shaderBase
                || !renderer.GPU.SupportsShaderAsset(shaderBase))
            {
                return;
            }

            GPUTexture targetTex = Resolve(target);
            GPUTexture? secondTex = secondaryTarget is { } secHandle ? Resolve(secHandle) : null;
            if (sampledTextures.Length > 16)
                throw new ArgumentException("At most 16 sampled textures are supported per pass", nameof(sampledTextures));

            nint pipeline = renderer.GPU.FullscreenPluginPipeline(
                shaderBase,
                targetTex.Format,
                blendMode,
                secondTex?.Format ?? 0);

            var passScissor = new SDL_Rect { x = 0, y = 0, w = targetTex.Width, h = targetTex.Height };
            SDL_GPUColorTargetInfo* colorTargets = stackalloc SDL_GPUColorTargetInfo[secondTex is not null ? 2 : 1];
            colorTargets[0] = new SDL_GPUColorTargetInfo
            {
                texture = targetTex.Handle,
                load_op = loadTarget ? SDL_GPU_LOADOP_LOAD : SDL_GPU_LOADOP_DONT_CARE,
                store_op = SDL_GPU_STOREOP_STORE,
            };
            uint numTargets = 1;
            if (secondTex is not null)
            {
                colorTargets[1] = new SDL_GPUColorTargetInfo
                {
                    texture = secondTex.Handle,
                    load_op = SDL_GPU_LOADOP_CLEAR,
                    store_op = SDL_GPU_STOREOP_STORE,
                };
                numTargets = 2;
            }

            nint pass = SDL_BeginGPURenderPass(command, colorTargets, numTargets, null);
            if (pass == 0)
                throw new SDLError("SDL_BeginGPURenderPass");

            try
            {
                SDL_SetGPUScissor(pass, in passScissor);
                SDL_BindGPUGraphicsPipeline(pass, pipeline);

                if (sampledTextures.Length > 0)
                {
                    SDL_GPUTextureSamplerBinding* bindings = stackalloc SDL_GPUTextureSamplerBinding[sampledTextures.Length];
                    for (int i = 0; i < sampledTextures.Length; i++)
                    {
                        GPUTexture boundTex = Resolve(sampledTextures[i]);
                        nint samp = (linearSamplerMask & (1u << i)) != 0 ? renderer.GPU.Sampler : renderer.GPU.PixelSampler;
                        bindings[i] = new SDL_GPUTextureSamplerBinding { texture = boundTex.Handle, sampler = samp };
                    }
                    SDL_BindGPUFragmentSamplers(pass, 0, bindings, (uint)sampledTextures.Length);
                }

                if (!uniformBytes.IsEmpty)
                {
                    fixed (byte* uPtr = uniformBytes)
                    {
                        SDL_PushGPUFragmentUniformData(command, 0, (nint)uPtr, (uint)uniformBytes.Length);
                    }
                }

                SDL_DrawGPUPrimitives(pass, 3, 1, 0, 0);
            }
            finally
            {
                SDL_EndGPURenderPass(pass);
            }
        }
    }

    private void EncodePluginRenderStages(
        nint command,
        GPUTexture color,
        GPUTexture depth,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas)
    {
        if (ClientPlugins is not { HasActiveRenderPasses: true } clientPlugins || Scene is not { } scene)
            return;

        ulong nowTicks = SDL_GetTicks();
        double dt = _renderDeltaTicks is ulong prevTicks && nowTicks >= prevTicks
            ? Math.Min((nowTicks - prevTicks) / 1000.0, 0.25)
            : 0.0;
        _renderDeltaTicks = nowTicks;
        double effectiveDelta = AmbientPaused || Speed <= 0 ? 0.0 : dt * Math.Min(Speed, 10);

        Vector4? lotHeightFrame = LotFrame(scene) is { } lf && scene.LotWidth is not null && scene.LotHeight is not null
            ? new Vector4(lf.X, lf.Y, HeightTexelsPerTile, _heightMargin)
            : null;
        Vector4? worldShadowView = null;
        Vector4? worldDynamicBounds = null;
        if (ComputeWorldShadowProjection(scene) is var (wsv, _, shadowZoom))
        {
            worldShadowView = new Vector4(wsv.Origin.X, wsv.Origin.Y, wsv.Scale, 1f);
            if (_voxelMap is not null)
            {
                float dMinX = float.MaxValue;
                float dMinY = float.MaxValue;
                float dMaxX = -float.MaxValue;
                float dMaxY = -float.MaxValue;
                if (scene.Meshes is { } dynMeshes)
                {
                    int n = Math.Min(dynMeshes.Count, _meshBounds.Length);
                    for (int i = 0; i < n; i++)
                    {
                        var m = dynMeshes[i];
                        if (m.Floor is not null || m.Roof is not null || m.Indicator == true)
                            continue;
                        Vector4 b = _meshBounds[i];
                        if (b.X > b.Z)
                            continue;
                        if (b.X < dMinX) dMinX = b.X;
                        if (b.Y < dMinY) dMinY = b.Y;
                        if (b.Z > dMaxX) dMaxX = b.Z;
                        if (b.W > dMaxY) dMaxY = b.W;
                    }
                }
                if (_hasDynamicShadowSprites && scene.Sprites is { } dynSprites)
                {
                    for (int i = 0; i < dynSprites.Count; i++)
                    {
                        var s = dynSprites[i];
                        if (s.DynamicShadow != true || s.DepthTexture is null)
                            continue;
                        float sx = s.X, sy = s.Y, sw = s.Width, sh = s.Height;
                        if (s.Image(shadowZoom) is { } img)
                        {
                            sx = s.X + img.X;
                            sy = s.Y + img.Y;
                            sw = img.Width;
                            sh = img.Height;
                        }
                        if (sx < dMinX) dMinX = sx;
                        if (sy < dMinY) dMinY = sy;
                        if (sx + sw > dMaxX) dMaxX = sx + sw;
                        if (sy + sh > dMaxY) dMaxY = sy + sh;
                    }
                }
                worldDynamicBounds = dMinX <= dMaxX
                    ? new Vector4(
                        wsv.Origin.X + dMinX * wsv.Scale - 10f,
                        wsv.Origin.Y + dMinY * wsv.Scale - 10f,
                        wsv.Origin.X + dMaxX * wsv.Scale + 10f,
                        wsv.Origin.Y + dMaxY * wsv.Scale + 10f)
                    : new Vector4(1e6f, 1e6f, -1e6f, -1e6f);
            }
        }

        List<PluginPointLight> lights = [];
        if (ActiveLighting(scene)?.Lights is { } sceneLights)
        {
            int level = scene.ViewLevel ?? 1;
            const float cullReachPx = 360f;
            float reachOnScreen = cullReachPx * viewport.Scale;
            var fireCandidates = new List<SimsSDL.Core.SceneLighting.Light>();
            var lampCandidates = new List<SimsSDL.Core.SceneLighting.Light>();
            foreach (var light in sceneLights)
            {
                if (light.Level > level)
                    continue;
                float r = reachOnScreen * (light.Fire ? 1.25f : 1f);
                Vector2 screen = viewport.Origin + new Vector2(light.X, light.Y) * viewport.Scale;
                if (screen.X <= -r || screen.Y <= -r || screen.X >= canvas.X + r || screen.Y >= canvas.Y + r)
                    continue;
                if (light.Fire)
                    fireCandidates.Add(light);
                else
                    lampCandidates.Add(light);
            }
            int Priority(SimsSDL.Core.SceneLighting.Light l) => l.Strength + (l.Level == level ? 25 : 0);
            fireCandidates.Sort((a, b) =>
            {
                int cmp = Priority(b).CompareTo(Priority(a));
                if (cmp != 0) return cmp;
                cmp = a.X.CompareTo(b.X);
                return cmp != 0 ? cmp : a.Y.CompareTo(b.Y);
            });
            var fireClusters = new List<(int Level, float X, float Y, float Toward, float Weight, float Intensity)>();
            const float fireMergeDistSq = 36f * 36f;
            foreach (var fire in fireCandidates)
            {
                float baseIntensity = MathF.Min(1.5f, MathF.Max(0.4f, fire.Strength / 40f));
                int mergedIndex = -1;
                float bestDistSq = fireMergeDistSq;
                for (int c = 0; c < fireClusters.Count; c++)
                {
                    var cluster = fireClusters[c];
                    if (cluster.Level != fire.Level)
                        continue;
                    float dx = fire.X - cluster.X;
                    float dy = fire.Y - cluster.Y;
                    float distSq = dx * dx + dy * dy;
                    if (distSq <= bestDistSq)
                    {
                        bestDistSq = distSq;
                        mergedIndex = c;
                    }
                }
                if (mergedIndex >= 0)
                {
                    var cluster = fireClusters[mergedIndex];
                    float newWeight = cluster.Weight + baseIntensity;
                    float t = baseIntensity / newWeight;
                    fireClusters[mergedIndex] = (
                        cluster.Level,
                        cluster.X + (fire.X - cluster.X) * t,
                        cluster.Y + (fire.Y - cluster.Y) * t,
                        cluster.Toward + (fire.Toward - cluster.Toward) * t,
                        newWeight,
                        MathF.Min(1.75f, cluster.Intensity + 0.55f * baseIntensity));
                }
                else
                {
                    fireClusters.Add((fire.Level, fire.X, fire.Y, fire.Toward, baseIntensity, baseIntensity));
                }
            }
            fireClusters.Sort((a, b) => b.Intensity.CompareTo(a.Intensity));
            int fireTake = Math.Min(10, fireClusters.Count);
            for (int i = 0; i < fireTake; i++)
            {
                var fc = fireClusters[i];
                lights.Add(new PluginPointLight(fc.X, fc.Y, fc.Toward, -fc.Intensity));
            }
            lampCandidates.Sort((a, b) => Priority(b).CompareTo(Priority(a)));
            int lampTake = Math.Min(MaxLamps - lights.Count, lampCandidates.Count);
            for (int i = 0; i < lampTake; i++)
            {
                var lamp = lampCandidates[i];
                float intensity = MathF.Min(1.5f, MathF.Max(0.4f, lamp.Strength / 40f));
                lights.Add(new PluginPointLight(lamp.X, lamp.Y, lamp.Toward, intensity));
            }
        }

        int camOrient = ((scene.CameraOrientation ?? 0) % 4 + 4) % 4;
        if (scene.VoxelMap is { } vxBoundsMap)
        {
            if (!ReferenceEquals(_boundsVoxelPixels, vxBoundsMap.Pixels))
            {
                _boundsVoxelPixels = vxBoundsMap.Pixels;
                int aoSize = vxBoundsMap.Width / 4;
                int aoRows = aoSize > 0 ? Math.Max(1, (vxBoundsMap.Height - vxBoundsMap.Width - 256) / (512 + aoSize)) : 1;
                int halfH = vxBoundsMap.Width / 2 + 128 + 256 * aoRows;
                int aoBase = halfH * 2 * vxBoundsMap.Width * 4;
                byte[] px = vxBoundsMap.Pixels;
                int minGx = int.MaxValue, minGy = int.MaxValue, maxGx = -1, maxGy = -1;
                int minZb = 256, maxZb = 0;
                if (aoSize > 0 && aoBase + aoSize * vxBoundsMap.Width * 4 <= px.Length)
                {
                    for (int gy = 0; gy < aoSize; gy++)
                    {
                        int r0 = aoBase + gy * vxBoundsMap.Width * 4;
                        int r1 = r0 + aoSize * 4;
                        for (int gx = 0; gx < aoSize; gx++)
                        {
                            byte mx = px[r0 + gx * 4 + 3];
                            if (mx == 0) continue;
                            if (gx < minGx) minGx = gx;
                            if (gy < minGy) minGy = gy;
                            if (gx > maxGx) maxGx = gx;
                            if (gy > maxGy) maxGy = gy;
                            if (mx > maxZb) maxZb = mx;
                            byte mn = px[r1 + gx * 4 + 3];
                            if (mn > 0 && mn < minZb) minZb = mn;
                        }
                    }
                }
                if (maxGx >= 0)
                {
                    _cachedVoxelBounds = new Vector4(minGx / 8f - 0.50f, minGy / 8f - 0.50f, (maxGx + 1) / 8f + 0.50f, (maxGy + 1) / 8f + 0.50f);
                    float loZ = minZb <= 255 ? (minZb - 1) * 0.125f - 4.60f : -4.60f;
                    float hiZ = (maxZb - 1) * 0.125f - 3.40f;
                    _cachedVoxelZBounds = new Vector2(loZ, hiZ);
                }
                else
                {
                    _cachedVoxelBounds = new Vector4(1e6f, 1e6f, -1e6f, -1e6f);
                    _cachedVoxelZBounds = new Vector2(1e6f, -1e6f);
                }
            }
        }
        else
        {
            _boundsVoxelPixels = null;
            _cachedVoxelBounds = new Vector4(1e6f, 1e6f, -1e6f, -1e6f);
            _cachedVoxelZBounds = new Vector2(1e6f, -1e6f);
        }

        if (scene.OverheadMap is { } ohBoundsMap)
        {
            if (!ReferenceEquals(_boundsOverheadPixels, ohBoundsMap.Pixels))
            {
                _boundsOverheadPixels = ohBoundsMap.Pixels;
                int ohW = ohBoundsMap.Width;
                bool hasBand1 = ohBoundsMap.Height >= ohW * 2 && ohW > 1;
                int baseH = hasBand1 ? ohW : ohBoundsMap.Height;
                float topScale = hasBand1 ? 4f : 8f;
                float invSamplesX = ohW > 0 && (scene.LotWidth ?? 0) > 0 ? (float)scene.LotWidth!.Value / ohW : 0.125f;
                float invSamplesY = baseH > 0 && (scene.LotHeight ?? 0) > 0 ? (float)scene.LotHeight!.Value / baseH : 0.125f;
                byte[] opx = ohBoundsMap.Pixels;
                int band1ByteBase = baseH * ohW * 4;
                int minQx = int.MaxValue, minQy = int.MaxValue, maxQx = -1, maxQy = -1;
                float rMinZ = float.MaxValue, rMaxZ = -float.MaxValue;
                if (ohW > 1 && baseH * ohW * 4 <= opx.Length)
                {
                    for (int qy = 0; qy < baseH; qy++)
                    {
                        int rowOff = qy * ohW * 4;
                        for (int qx = 0; qx < ohW; qx++)
                        {
                            int off = rowOff + qx * 4;
                            byte a = opx[off + 3];
                            if (a == 0 || a == 255) continue;
                            byte r = opx[off];
                            if ((r & 96) == 0 && a < 2) continue;
                            if (qx < minQx) minQx = qx;
                            if (qy < minQy) minQy = qy;
                            if (qx > maxQx) maxQx = qx;
                            if (qy > maxQy) maxQy = qy;
                            float qBase = (((opx[off + 1] << 8) | opx[off + 2]) - 32768) / 256f;
                            float loZ = qBase + 2.95f - 0.60f;
                            if (loZ < rMinZ) rMinZ = loZ;
                            float canopyTop = a >= 2 ? (a - 2) / topScale : 0f;
                            int topStory = 1;
                            if (hasBand1 && (r & 64) != 0 && band1ByteBase + off + 3 < opx.Length)
                            {
                                int slab16 = opx[band1ByteBase + off + 2] | (opx[band1ByteBase + off + 3] << 8);
                                if (slab16 != 0)
                                    topStory = 32 - BitOperations.LeadingZeroCount((uint)slab16);
                            }
                            else if (!hasBand1 && (r & 64) != 0)
                            {
                                topStory = 2;
                                for (int k = 3; k <= 5; k++)
                                {
                                    if ((r & (1 << (k - 1))) != 0) topStory = k;
                                }
                            }
                            float hiZ = qBase + MathF.Max(canopyTop, topStory * 2.95f) + 1.25f;
                            if (hiZ > rMaxZ) rMaxZ = hiZ;
                        }
                    }
                }
                if (maxQx >= 0)
                {
                    _cachedRoofSrcBounds = new Vector4(
                        minQx * invSamplesX - 0.55f,
                        minQy * invSamplesY - 0.55f,
                        (maxQx + 1) * invSamplesX + 0.55f,
                        (maxQy + 1) * invSamplesY + 0.55f);
                    _cachedRoofZBounds = new Vector2(rMinZ, rMaxZ);
                }
                else
                {
                    _cachedRoofSrcBounds = new Vector4(1e6f, 1e6f, -1e6f, -1e6f);
                    _cachedRoofZBounds = new Vector2(1e6f, -1e6f);
                }
            }
        }
        else
        {
            _boundsOverheadPixels = null;
            _cachedRoofSrcBounds = new Vector4(1e6f, 1e6f, -1e6f, -1e6f);
            _cachedRoofZBounds = new Vector2(1e6f, -1e6f);
        }

        float srcLotW = scene.LotWidth ?? 0;
        float srcLotH = scene.LotHeight ?? 0;
        Vector4 srb = _cachedRoofSrcBounds;
        Vector4 worldRoofBounds = srb.X > srb.Z
            ? srb
            : camOrient switch
            {
                1 => new Vector4(srcLotH - srb.W, srb.X, srcLotH - srb.Y, srb.Z),
                2 => new Vector4(srcLotW - srb.Z, srcLotH - srb.W, srcLotW - srb.X, srcLotH - srb.Y),
                3 => new Vector4(srb.Y, srcLotW - srb.Z, srb.W, srcLotW - srb.X),
                _ => srb,
            };
        Vector4 worldCasterZBounds = new(_cachedVoxelZBounds.X, _cachedVoxelZBounds.Y, _cachedRoofZBounds.X, _cachedRoofZBounds.Y);

        var state = new PluginLotRenderState(
            House: scene.House,
            SceneRevision: _sceneRevision,
            CameraOrientation: camOrient,
            ViewLevel: scene.ViewLevel ?? 1,
            RoofsVisible: RoofsVisible,
            LotWidth: scene.LotWidth ?? 0,
            LotHeight: scene.LotHeight ?? 0,
            ViewportOrigin: viewport.Origin,
            ViewportScale: viewport.Scale,
            CanvasSize: canvas,
            LotHeightFrame: lotHeightFrame,
            IndoorBaseAltitude: _indoorBase,
            WorldShadowViewport: worldShadowView,
            Speed: AmbientPaused ? 0 : Speed,
            DeltaSeconds: effectiveDelta,
            DebugViewMode: AmbientDebug,
            ShadowsEnabled: ShadowsEnabled,
            SunDirectionOverride: SunOverride,
            TimeOverrideSeconds: TimeOverrideSeconds,
            Lights: lights)
        {
            SurroundingsMargin = _surroundingsMargin,
            Scenery = _surroundingsScenery,
            WorldDynamicShadowBounds = worldDynamicBounds,
            WorldVoxelShadowBounds = _cachedVoxelBounds,
            WorldRoofShadowBounds = worldRoofBounds,
            WorldCasterZBounds = worldCasterZBounds,
        };

        var frame = new PluginRenderFrame(this, command, color, depth, viewport, canvas, state);
        ReadOnlySpan<PluginRenderStage> stages =
        [
            PluginRenderStage.PreLighting,
            PluginRenderStage.Lighting,
            PluginRenderStage.Atmosphere,
            PluginRenderStage.PostProcess,
        ];
        foreach (PluginRenderStage stage in stages)
        {
            if (AmbientDebug != 0 && stage > PluginRenderStage.Lighting)
                break;
            if (!LightingEnabled && stage == PluginRenderStage.Lighting)
                continue;
            frame.Stage = stage;
            EventProfiler.Measure($"plugin:{stage}", () =>
            {
                clientPlugins.RenderStage(stage, packId =>
                {
                    frame.ActivePackId = packId;
                    return frame;
                });
            });
        }
    }
}
