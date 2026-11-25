using System.Numerics;
using SimsNative.Plugins;

namespace SimsSDL;

public sealed partial class LotRenderer
{
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

    private GPUTexture? MakeOverheadMap(LotScene scene) =>
        scene.OverheadMap is { } map ? GPU.UploadDataTexture(map.Width, map.Height, map.Pixels) : null;

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

    // Packs 10 bands across 2 floors into R8 indoorMap: rooms/windows (0-1), altitudes (2-3),
    // half-tile/road/cement (4-5), solid wall edges (6-7), and fence/railing edges (8-9).
    private GPUTexture? MakeIndoorMask(LotScene scene)
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
        var mask = new byte[columns * rows * 10];

        (int X, int Y, int Index)? TryCell(int x, int y, int level)
        {
            if (x < 0 || x >= width || y < 0 || y >= height || (level != 1 && level != 2))
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
        Dictionary<int, byte> halves = new();
        HashSet<int> whole = [];
        Dictionary<int, byte> outdoorHalves = new();
        HashSet<int> outdoorWhole = [];

        foreach (LotScene.Mesh mesh in scene.Meshes ?? [])
        {
            if (mesh.Floor is not { } floor || TryCell(floor.X, floor.Y, floor.Level ?? 1) is not { } at)
                continue;

            if (mesh.Vertices.Count > 0 && seenAltitudes.Add(at.Index + 2 * rows * columns))
            {
                LotScene.MeshVertex v0 = mesh.Vertices[0];
                altitudes.Add((at.Index + 2 * rows * columns, (frame.Y + 16f * (at.X + at.Y) + 32f * v0.V - v0.Y) / 40f));
            }

            if (mesh.Room is not int room || room < 0 || room >= lighting.Rooms.Count || lighting.Rooms[room].Outside)
            {
                if (floor.Pattern == 12)
                    mask[at.Index + 4 * rows * columns] |= 0x80;
                if (floor.Pattern is >= 9 and <= 11)
                    mask[at.Index + 4 * rows * columns] |= 0x40;

                if (floor.Pattern != 12 && floor.Pattern is not (>= 9 and <= 11))
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
                mask[index + 4 * rows * columns] |= (byte)(half & 7);
        }

        foreach (var (index, half) in outdoorHalves)
        {
            if (mask[index] < 2 && !outdoorWhole.Contains(index))
                mask[index + 4 * rows * columns] |= (byte)(half & 7);
        }

        int bandStride = rows * columns;
        foreach (LotScene.Sprite sprite in scene.Sprites ?? [])
        {
            if (sprite.ArchitectureDepth is not { } arch || sprite.Width <= 8f)
                continue;
            if (TryCell(arch.X, arch.Y, arch.Level) is not { } at)
                continue;

            int bandOffset = (sprite.Wall is not null ? 6 : 8) * bandStride;
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
            }
        }

        _indoorBase = altitudes.Count > 0 ? altitudes.Min(a => a.Altitude) : 0f;
        foreach (var (index, altitude) in altitudes)
        {
            mask[index] = (byte)MathF.Max(1f, MathF.Min(255f, MathF.Round((altitude - _indoorBase) * 8f, MidpointRounding.AwayFromZero) + 1f));
        }

        IReadOnlyList<GPUTexture> uploaded = GPU.UploadTextures([(columns, rows * 10, true, mask)]);
        return uploaded.Count > 0 ? uploaded[0] : null;
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
        float minX = frame.X - 32f * h - 128f;
        float spanX = 32f * (w + h) + 256f;
        float minY = frame.Y - 400f;
        float spanY = 16f * (w + h) + 528f;
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

        var key = (groundBuf.Handle, groundBuf.Count, depth.Handle, _sceneRevision, viewport.Origin.X, viewport.Origin.Y, viewport.Scale, canvas.X, canvas.Y);
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
            if (Scene is not { } scene || _drawItems.Count == 0)
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

            void DrawDepthSpritePass(int sliceStart, int sliceEnd, SpritePassMode passMode)
            {
                nint pipeline = passMode == SpritePassMode.EdgeFringe ? GPU.SpriteDepthEdgePipeline : GPU.SpriteDepthPipeline;
                for (int i = sliceStart; i < sliceEnd; i++)
                {
                    SceneDrawItem item = _drawItems[i];
                    if (item.Kind != SceneDrawItem.ItemKind.Sprite || (uint)item.Index >= (uint)scene.Sprites.Count)
                        continue;

                    LotScene.Sprite sprite = scene.Sprites[item.Index];
                    if (sprite.Wall is not null || (zoom == LotZoom.Far && sprite.HideAtFarZoom == true))
                        continue;

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
                        continue;

                    if (origin.X + (rect.X + rect.Z) * scale < 0f ||
                        origin.Y + (rect.Y + rect.W) * scale < 0f ||
                        origin.X + rect.X * scale >= canvas.X ||
                        origin.Y + rect.Y * scale >= canvas.Y)
                    {
                        continue;
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
                        continue;
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
            }

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

                DrawDepthSpritePass(sliceStart, sliceEnd, SpritePassMode.OpaqueCore);
                if (scale >= 0.14f)
                    DrawDepthSpritePass(sliceStart, sliceEnd, SpritePassMode.EdgeFringe);
                sliceStart = sliceEnd;
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
        if (Scene is not { } scene || _drawItems.Count == 0)
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

            for (int i = 0; i < _drawItems.Count; i++)
            {
                SceneDrawItem item = _drawItems[i];
                if (item.Kind != SceneDrawItem.ItemKind.Sprite)
                    continue;

                LotScene.Sprite sprite = scene.Sprites[item.Index];
                if (sprite.Wall is not null || (zoom == LotZoom.Far && sprite.HideAtFarZoom == true))
                    continue;

                int texture = sprite.Texture;
                int? depthTexture = sprite.DepthTexture;
                var rect = new Vector4(sprite.X, sprite.Y, sprite.Width, sprite.Height);
                if (sprite.Image(zoom) is { } image)
                {
                    texture = image.Texture;
                    depthTexture = image.DepthTexture;
                    rect = new Vector4(sprite.X + image.X, sprite.Y + image.Y, image.Width, image.Height);
                }

                if (depthTexture is not int dt)
                    continue;

                if (origin.X + (rect.X + rect.Z) * scale < 0f ||
                    origin.Y + (rect.Y + rect.W) * scale < 0f ||
                    origin.X + rect.X * scale >= canvas.X ||
                    origin.Y + rect.Y * scale >= canvas.Y)
                {
                    continue;
                }

                nint t0 = _sceneTextures[texture].Handle;
                nint t1 = _sceneTextures[dt].Handle;
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
        Vector4? worldShadowView = ComputeWorldShadowProjection(scene) is var (wsv, _, _)
            ? new Vector4(wsv.Origin.X, wsv.Origin.Y, wsv.Scale, 1f)
            : null;

        List<PluginPointLight> lights = [];
        if (scene.Lighting?.Lights is { } sceneLights)
        {
            int level = scene.ViewLevel ?? 1;
            const float cullReachPx = 360f;
            float reachOnScreen = cullReachPx * viewport.Scale;
            var candidates = new List<SimsSDL.Core.SceneLighting.Light>();
            foreach (var light in sceneLights)
            {
                if (light.Level != level)
                    continue;
                float r = reachOnScreen * (light.Fire ? 1.25f : 1f);
                Vector2 screen = viewport.Origin + new Vector2(light.X, light.Y) * viewport.Scale;
                if (screen.X > -r && screen.Y > -r && screen.X < canvas.X + r && screen.Y < canvas.Y + r)
                    candidates.Add(light);
            }
            static int Priority(SimsSDL.Core.SceneLighting.Light l) => l.Strength + (l.Fire ? 50 : 0);
            candidates.Sort((a, b) => Priority(b).CompareTo(Priority(a)));
            int take = Math.Min(MaxLamps, candidates.Count);
            for (int i = 0; i < take; i++)
            {
                var lamp = candidates[i];
                float intensity = MathF.Min(1.5f, MathF.Max(0.4f, lamp.Strength / 40f));
                lights.Add(new PluginPointLight(lamp.X, lamp.Y, lamp.Toward, lamp.Fire ? -intensity : intensity));
            }
        }

        var state = new PluginLotRenderState(
            House: scene.House,
            SceneRevision: _sceneRevision,
            CameraOrientation: ((scene.CameraOrientation ?? 0) % 4 + 4) % 4,
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
            Lights: lights);

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
            frame.Stage = stage;
            clientPlugins.RenderStage(stage, packId =>
            {
                frame.ActivePackId = packId;
                return frame;
            });
        }
    }
}
