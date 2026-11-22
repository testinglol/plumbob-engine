using System.Numerics;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using SimsSDL.UI;

namespace SimsSDL;

public sealed partial class LotRenderer
{

    public void ApplyEnvironment(PluginEnvironment? value)
    {
        if (!string.Equals(Environment?.Scope, value?.Scope, StringComparison.Ordinal) ||
            !string.Equals(Environment?.PackId, value?.PackId, StringComparison.Ordinal) ||
            !string.Equals(Environment?.AssetRoot, value?.AssetRoot, StringComparison.Ordinal))
        {
            _lastPrint = 0;
            _pendingPrints.Clear();
            _trailKey = string.Empty;
        }

        Environment = value;
        PluginEnvironment.EffectData? effect = value?.Effect;
        IReadOnlyDictionary<string, float>? parameters = effect?.Parameters;
        float Param(string key, float fallback = 0f) =>
            parameters is not null && parameters.TryGetValue(key, out float v) ? v : fallback;

        Ambient.Radius = Param("radius");
        Ambient.Occlusion = Param("occlusion");
        Ambient.Shadow = Param("shadow");
        Ambient.Thickness = Param("thickness");
        Ambient.Reach = Param("reach");
        Ambient.ContactRadius = Param("contactRadius");
        Ambient.Contact = Param("contact");
        Ambient.HeightTexels = Param("heightTexels", 16f);
        Ambient.GroundOffset = Param("groundOffset");
        Ambient.Sun = new Vector3(Param("sunUp", 1f), Param("sunToward"), Param("sunRight"));
        Ambient.LampReach = Param("lampReach");
        Ambient.LampGain = Param("lampGain");
        Ambient.WindowSun = Param("windowSun");
        Ambient.CloudShade = Param("cloudShade");
        Ambient.Wind = new Vector2(Param("windX"), Param("windY"));
        Ambient.CloudHeight = Param("cloudHeight");
        Ambient.Tint = Param("tint");
        Ambient.SurfaceMode = effect?.SurfaceMode ?? 0;
        Ambient.SurfaceAmount = effect?.SurfaceAmount ?? 0f;
        Ambient.CloudCover = effect?.CloudCover ?? 0f;
        Ambient.Rain = effect?.Precipitation ?? 0f;
        Ambient.Wetness = effect?.Wetness ?? 0f;
        Ambient.GrassQuality = Param("grassQuality", Param("grass"));
        Ambient.SpringBloom = Param("springBloom");
        Ambient.Snowfall = Param("snowfall");
        Ambient.Fireflies = Param("fireflies");
        Ambient.Hail = Param("hail");
        Ambient.Frost = Param("frost");
        Ambient.Thunder = Param("thunder");

        var nextShaders = new Dictionary<string, string>();
        if (value is not null && effect is not null)
        {
            foreach (var (key, shaderPath) in effect.Shaders)
            {
                string stage = key is "groundDepth" or "heightScatter" or "fullscreen" ? ".vert" : ".frag";
                string assetPath = value.Asset(shaderPath);
                if (!GPU.SupportsShaderAsset(assetPath))
                {
                    AppLog.Warn($"Skipping environment shader '{key + stage}' at '{assetPath}': no compiled bytecode matching active GPU backend ({GPU.DriverName}).");
                    nextShaders.Clear();
                    break;
                }
                nextShaders[key + stage] = assetPath;
            }
        }

        if (GPU.EffectShaders.Count != nextShaders.Count ||
            nextShaders.Any(kv => !GPU.EffectShaders.TryGetValue(kv.Key, out string? existing) || !string.Equals(existing, kv.Value, StringComparison.Ordinal)))
        {
            GPU.EffectShaders = nextShaders;
        }

        if (effect is not null)
        {
            foreach (PluginEnvironment.EffectData.Footprint mark in effect.Footprints)
            {
                if (mark.Sequence > _lastPrint)
                {
                    _pendingPrints.Add(new Vector4(mark.X, mark.Y, mark.Heading, mark.Foot));
                    _lastPrint = mark.Sequence;
                }
            }
        }

        if (_pendingPrints.Count > 128)
        {
            _pendingPrints.RemoveRange(0, _pendingPrints.Count - 128);
        }
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

    private GPUTexture? MakeOverheadMap(LotScene scene)
    {
        if (scene.OverheadMap is not { } map)
        {
            return null;
        }

        return GPU.UploadDataTexture(map.Width, map.Height, map.Pixels);
    }

    private GPUTexture EmptyOverheadMap()
    {
        if (_emptyOverhead is not null)
        {
            return _emptyOverhead;
        }

        GPUTexture texture = GPU.UploadDataTexture(1, 1, [0, 128, 0, 0]);
        _emptyOverhead = texture;
        return texture;
    }

    private GPUTexture EmptyTransparent()
    {
        if (_emptyTransparent is not null)
        {
            return _emptyTransparent;
        }

        GPUTexture texture = GPU.UploadDataTexture(1, 1, [0, 0, 0, 0]);
        _emptyTransparent = texture;
        return texture;
    }

    private GPUTexture EmptyIndoorMask()
    {
        if (_emptyMask is not null)
        {
            return _emptyMask;
        }

        GPUTexture texture = GPU.UploadTextures([(1, 6, true, new byte[] { 0, 0, 0, 0, 0, 0 })])[0];
        _emptyMask = texture;
        return texture;
    }

    // Packs 6 bands across 2 floors into R8 indoorMap: room/window (bit 0 = window), altitude (1/8 tile), half-tile mask.
    // Half-band bits 0x80 indicate cement and 0x40 indicate off-lot roads.
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
        var mask = new byte[columns * rows * 6];

        (int X, int Y, int Index)? TryCell(int x, int y, int level)
        {
            if (x < 0 || x >= width || y < 0 || y >= height || (level != 1 && level != 2))
            {
                return null;
            }

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
            {
                continue;
            }

            // Tile centers sit 16*(x+y+1) px below frame, minus 40 px per altitude tile.
            if (mesh.Vertices.Count > 0 && seenAltitudes.Add(at.Index + 2 * rows * columns))
            {
                LotScene.MeshVertex v0 = mesh.Vertices[0];
                altitudes.Add((at.Index + 2 * rows * columns, (frame.Y + 16f * (at.X + at.Y) + 32f * v0.V - v0.Y) / 40f));
            }

            if (mesh.Room is not int room || room < 0 || room >= lighting.Rooms.Count || lighting.Rooms[room].Outside)
            {
                if (floor.Pattern == 12)
                {
                    mask[at.Index + 4 * rows * columns] |= 0x80;
                }

                if (floor.Pattern is >= 9 and <= 11)
                {
                    mask[at.Index + 4 * rows * columns] |= 0x40;
                }

                if (floor.Pattern != 12 && floor.Pattern is not (>= 9 and <= 11))
                {
                    if (floor.Half == 0 || outdoorHalves.ContainsKey(at.Index))
                    {
                        outdoorWhole.Add(at.Index);
                    }
                    else if (floor.Half is >= 1 and <= 4)
                    {
                        outdoorHalves[at.Index] = (byte)floor.Half;
                    }
                }

                continue;
            }

            mask[at.Index] = (byte)(((room % 127 + 1) * 2) | (mask[at.Index] & 1));
            if (floor.Half == 0 || halves.ContainsKey(at.Index))
            {
                whole.Add(at.Index);
            }
            else
            {
                halves[at.Index] = (byte)floor.Half;
            }
        }

        foreach (var (index, half) in halves)
        {
            if (!whole.Contains(index))
            {
                mask[index + 4 * rows * columns] |= (byte)(half & 7);
            }
        }

        foreach (var (index, half) in outdoorHalves)
        {
            if (mask[index] < 2 && !outdoorWhole.Contains(index))
            {
                mask[index + 4 * rows * columns] |= (byte)(half & 7);
            }
        }

        bool anyIndoor = false;
        for (int i = 0; i < mask.Length; i++)
        {
            if (mask[i] >= 2)
            {
                anyIndoor = true;
                break;
            }
        }

        if (!anyIndoor)
        {
            return null;
        }

        if (lighting.Windows is not null)
        {
            foreach (SimsSDL.Core.SceneLighting.Window window in lighting.Windows)
            {
                if (TryCell(window.X, window.Y, window.Level) is { } at)
                {
                    mask[at.Index] |= 1;
                }
            }
        }

        _indoorBase = altitudes.Count > 0 ? altitudes.Min(a => a.Altitude) : 0f;
        foreach (var (index, altitude) in altitudes)
        {
            mask[index] = (byte)MathF.Max(1f, MathF.Min(255f, MathF.Round((altitude - _indoorBase) * 8f, MidpointRounding.AwayFromZero) + 1f));
        }

        IReadOnlyList<GPUTexture> uploaded = GPU.UploadTextures([(columns, rows * 6, true, mask)]);
        return uploaded.Count > 0 ? uploaded[0] : null;
    }

    private static Vector2? LotFrame(LotScene scene)
    {
        if (scene.OriginX is float x && scene.OriginY is float y)
        {
            return new Vector2(34f - x, 158f - y);
        }

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
        ulong hash = 14695981039346656037UL ^ (ulong)sprites.Count;
        const ulong prime = 1099511628211UL;
        for (int i = 0; i < sprites.Count; i++)
        {
            LotScene.Sprite s = sprites[i];
            if (s.DepthTexture is null)
            {
                continue;
            }
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

    private unsafe ((GPUTexture Texture, Vector4? Frame) HeightMap, (GPUTexture Texture, Vector4? Frame) FootMap, GPUTexture WorldDepth, GPUTexture WorldBackDepth, SimsSDL.Core.SceneViewport? WorldViewport) EnsureWorldShadowMaps(
        nint command,
        GPUTexture screenDepth,
        SimsSDL.Core.SceneViewport screenViewport,
        Vector2 screenCanvas)
    {
        if (Scene is not { } scene || LotFrame(scene) is not { } frame ||
            scene.LotWidth is not int width || scene.LotHeight is not int height)
        {
            var hm = EncodeHeightMap(command, screenDepth, screenViewport, screenCanvas);
            var fm = EncodeHeightMap(command, screenDepth, screenViewport, screenCanvas, feet: true);
            return (hm, fm, screenDepth, screenDepth, null);
        }

        const int maxShadowW = 2560;
        const int maxShadowH = 1600;
        bool swapped = (scene.CameraOrientation ?? 0) % 2 != 0;
        float w = swapped ? height : width;
        float h = swapped ? width : height;
        float minX = frame.X - 32f * h - 128f;
        float spanX = 32f * (w + h) + 256f;
        float minY = frame.Y - 400f;
        float spanY = 16f * (w + h) + 528f;
        float shadowScale = MathF.Min(0.625f, MathF.Min(maxShadowW / spanX, maxShadowH / spanY));
        LotZoom shadowZoom = shadowScale >= MediumToNearZoomMidpoint ? LotZoom.Near : LotZoom.Medium;
        int shadowW = Math.Clamp((int)MathF.Ceiling(spanX * shadowScale), 512, maxShadowW);
        int shadowH = Math.Clamp((int)MathF.Ceiling(spanY * shadowScale), 512, maxShadowH);
        var shadowCanvas = new Vector2(shadowW, shadowH);
        var shadowViewport = new SimsSDL.Core.SceneViewport(shadowCanvas, shadowScale, new Vector2(-minX * shadowScale, -minY * shadowScale));

        string staticKey = $"{scene.House}:{_sceneRevision}:{scene.CameraOrientation}:{ViewLevel}:{RoofsVisible}:{_worldShadowSpriteSeq}:{Ambient.HeightTexels:0.##}:{shadowW}x{shadowH}";
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
            {
                throw new SDLError("SDL_BeginGPURenderPass");
            }
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
            {
                throw new SDLError("SDL_BeginGPURenderPass");
            }
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

        nint copyPass = SDL_BeginGPUCopyPass(command);
        if (copyPass == 0)
        {
            throw new SDLError("SDL_BeginGPUCopyPass");
        }
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

        bool hasDynamicItems = scene.Meshes is not null && scene.Meshes.Count > _staticMeshes.Count;
        if (hasDynamicItems)
        {
            var depthTarget = new SDL_GPUDepthStencilTargetInfo
            {
                texture = _worldShadowDepth.Handle,
                load_op = SDL_GPU_LOADOP_LOAD,
                store_op = SDL_GPU_STOREOP_STORE,
                stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
                stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
            };
            nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget);
            if (pass == 0)
            {
                throw new SDLError("SDL_BeginGPURenderPass");
            }
            try
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
            finally
            {
                SDL_EndGPURenderPass(pass);
            }

            var backDepthTarget = new SDL_GPUDepthStencilTargetInfo
            {
                texture = _worldShadowBackDepth.Handle,
                load_op = SDL_GPU_LOADOP_LOAD,
                store_op = SDL_GPU_STOREOP_STORE,
                stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
                stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
            };
            nint backPass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &backDepthTarget);
            if (backPass == 0)
            {
                throw new SDLError("SDL_BeginGPURenderPass");
            }
            try
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
        float texels = Ambient.HeightTexels;
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
        {
            throw new SDLError("SDL_BeginGPURenderPass");
        }

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
        {
            return _groundDepthTexture;
        }

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.DepthFormat,
            SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_groundDepthTexture);
        _groundDepthTexture = texture;
        return texture;
    }

    private GPUTexture SeasonDepthTexture(int width, int height)
    {
        if (_seasonDepthTexture is not null && _seasonDepthTexture.Width == width && _seasonDepthTexture.Height == height)
        {
            return _seasonDepthTexture;
        }

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.DepthFormat,
            SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_seasonDepthTexture);
        _seasonDepthTexture = texture;
        return texture;
    }

    private GPUTexture SeasonSpriteTexture(int width, int height)
    {
        if (_seasonSpriteTexture is not null && _seasonSpriteTexture.Width == width && _seasonSpriteTexture.Height == height)
        {
            return _seasonSpriteTexture;
        }

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.ColorFormat,
            SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_seasonSpriteTexture);
        _seasonSpriteTexture = texture;
        return texture;
    }

    private GPUTexture AmbientTexture(int width, int height)
    {
        if (_ambientTermTexture is not null && _ambientTermTexture.Width == width && _ambientTermTexture.Height == height)
        {
            return _ambientTermTexture;
        }

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.ColorFormat,
            SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_ambientTermTexture);
        _ambientTermTexture = texture;
        return texture;
    }

    private GPUTexture LiftTexture(int width, int height)
    {
        if (_surfaceLiftTexture is not null && _surfaceLiftTexture.Width == width && _surfaceLiftTexture.Height == height)
        {
            return _surfaceLiftTexture;
        }

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.LiftFormat,
            SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_surfaceLiftTexture);
        _surfaceLiftTexture = texture;
        return texture;
    }

    private GPUTexture EmptyLift()
    {
        if (_emptyLiftTexture is not null)
        {
            return _emptyLiftTexture;
        }

        GPUTexture texture = GPU.MakeTexture(
            1,
            1,
            GPUContext.LiftFormat,
            SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        _emptyLiftTexture = texture;
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
                {
                    sims.Add(i);
                }
            }
        }

        if (Scene is null || sims.Count == 0)
        {
            if (_emptySimMaskTexture is not null)
            {
                return _emptySimMaskTexture;
            }

            GPUTexture empty = GPU.MakeTexture(1, 1, GPUContext.MaskFormat, usage);
            _emptySimMaskTexture = empty;
            return empty;
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
        {
            throw new SDLError("SDL_BeginGPURenderPass");
        }

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
                {
                    continue;
                }

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
                {
                    transform.UvRect = new Vector4(1f, transform.UvRect.Y, transform.UvRect.Z, transform.UvRect.W);
                }

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
        {
            return _surfaceSourceTexture;
        }

        GPUTexture texture = GPU.MakeTexture(
            width,
            height,
            GPUContext.ColorFormat,
            SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
        Retire(_surfaceSourceTexture);
        _surfaceSourceTexture = texture;
        return texture;
    }

    // Separate pass because primary Terrain/floor draws use DepthMode.Flat with depth writes disabled.
    private unsafe void EncodeGroundDepth(nint command, GPUTexture depth, SimsSDL.Core.SceneViewport viewport, Vector2 canvas)
    {
        GPUBuffer? groundBuf = _terrainBuffer;
        if (groundBuf is null || groundBuf.Handle == nint.Zero)
        {
            return;
        }

        var key = (groundBuf.Handle, groundBuf.Count, depth.Handle, _sceneRevision, viewport.Origin.X, viewport.Origin.Y, viewport.Scale, canvas.X, canvas.Y);
        if (_groundDepthCacheKey == key)
        {
            return;
        }

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
        {
            throw new SDLError("SDL_BeginGPURenderPass");
        }

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

    // Captures unblended premultiplied depth-sprite layers against lot depth so season.frag separates leaf edges from turf.
    private unsafe GPUTexture EncodeSeasonSprites(
        nint command,
        GPUTexture seasonDepth,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas)
    {
        GPUTexture spriteLayer = SeasonSpriteTexture(seasonDepth.Width, seasonDepth.Height);
        var colorTarget = new SDL_GPUColorTargetInfo
        {
            texture = spriteLayer.Handle,
            clear_color = new SDL_FColor { r = 0f, g = 0f, b = 0f, a = 0f },
            load_op = SDL_GPU_LOADOP_CLEAR,
            store_op = SDL_GPU_STOREOP_STORE,
        };
        var depthTarget = new SDL_GPUDepthStencilTargetInfo
        {
            texture = seasonDepth.Handle,
            load_op = SDL_GPU_LOADOP_LOAD,
            store_op = SDL_GPU_STOREOP_STORE,
            stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
            stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget);
        if (pass == 0)
        {
            throw new SDLError("SDL_BeginGPURenderPass");
        }

        try
        {
            if (Scene is not { } scene || _drawItems.Count == 0)
            {
                return spriteLayer;
            }

            var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
            SDL_SetGPUScissor(pass, in scissor);

            float scale = viewport.Scale;
            Vector2 origin = viewport.Origin;
            LotZoom zoom = EffectiveVisualZoom;
            float artTexelScale = scale / zoom.Factor();
            bool settledIntegerUi = MathF.Abs(artTexelScale - MathF.Round(artTexelScale, MidpointRounding.AwayFromZero)) <= 1e-4f
                && !IsZoomInterpolating;
            nint artSampler = settledIntegerUi ? GPU.PixelSampler : GPU.Sampler;
            nint spriteSampler = AntiAliasedSprites ? GPU.Sampler : artSampler;
            bool spriteMinified = scale < zoom.Factor() * MathF.Max(UIScale, 0.01f) - 0.001f;
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
                    {
                        continue;
                    }

                    LotScene.Sprite sprite = scene.Sprites[item.Index];
                    if (sprite.Wall is not null || (zoom == LotZoom.Far && sprite.HideAtFarZoom == true))
                    {
                        continue;
                    }

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
                    {
                        continue;
                    }

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
                    {
                        continue;
                    }
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
                    {
                        break;
                    }

                    sliceEnd += 1;
                }

                DrawDepthSpritePass(sliceStart, sliceEnd, SpritePassMode.OpaqueCore);
                if (scale >= 0.14f)
                {
                    DrawDepthSpritePass(sliceStart, sliceEnd, SpritePassMode.EdgeFringe);
                }

                sliceStart = sliceEnd;
            }
        }
        finally
        {
            SDL_EndGPURenderPass(pass);
        }

        return spriteLayer;
    }

    private unsafe void EncodeSeasonDepth(
        nint command,
        GPUTexture color,
        GPUTexture seasonDepth,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas,
        bool displaced)
    {
        if (Scene is not { } scene || _drawItems.Count == 0)
        {
            return;
        }

        var colorTarget = new SDL_GPUColorTargetInfo
        {
            texture = color.Handle,
            load_op = SDL_GPU_LOADOP_LOAD,
            store_op = SDL_GPU_STOREOP_STORE,
        };
        var depthTarget = new SDL_GPUDepthStencilTargetInfo
        {
            texture = seasonDepth.Handle,
            load_op = SDL_GPU_LOADOP_LOAD,
            store_op = SDL_GPU_STOREOP_STORE,
            stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
            stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget);
        if (pass == 0)
        {
            throw new SDLError("SDL_BeginGPURenderPass");
        }

        try
        {
            var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
            SDL_SetGPUScissor(pass, in scissor);
            SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(GPUContext.Program.SpriteDepth, GPUContext.DepthMode.MeshDepthPrepass));

            float scale = viewport.Scale;
            Vector2 origin = viewport.Origin;
            LotZoom zoom = EffectiveVisualZoom;
            float artTexelScale = scale / zoom.Factor();
            bool settledIntegerUi = MathF.Abs(artTexelScale - MathF.Round(artTexelScale, MidpointRounding.AwayFromZero)) <= 1e-4f
                && !IsZoomInterpolating;
            nint artSampler = settledIntegerUi ? GPU.PixelSampler : GPU.Sampler;
            nint spriteSampler = AntiAliasedSprites ? GPU.Sampler : artSampler;
            bool spriteMinified = scale < zoom.Factor() * MathF.Max(UIScale, 0.01f) - 0.001f;
            nint colorSpriteSampler = AntiAliasedSprites && spriteMinified ? GPU.AnisoSampler : spriteSampler;
            float alphaCutoff = Ambient.SurfaceMode == 1
                ? (1f / 255f)
                : (Ambient.SurfaceMode == 2 && displaced ? 0.68f : 0.18f);
            float modeFlag = AntiAliasedSprites ? 1f : 0f;
            (nint T0, nint T1)? lastBound = null;
            SDL_GPUTextureSamplerBinding* bindings = stackalloc SDL_GPUTextureSamplerBinding[2];

            for (int i = 0; i < _drawItems.Count; i++)
            {
                SceneDrawItem item = _drawItems[i];
                if (item.Kind != SceneDrawItem.ItemKind.Sprite)
                {
                    continue;
                }

                LotScene.Sprite sprite = scene.Sprites[item.Index];
                if (sprite.Wall is not null || (zoom == LotZoom.Far && sprite.HideAtFarZoom == true))
                {
                    continue;
                }

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
                {
                    continue;
                }

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

    private unsafe void EncodeAmbient(
        nint command,
        GPUTexture color,
        GPUTexture depth,
        GPUTexture ground,
        (GPUTexture Texture, Vector4? Frame) heightMap,
        GPUTexture footMap,
        GPUTexture worldDepth,
        GPUTexture worldBackDepth,
        SimsSDL.Core.SceneViewport? worldShadowViewport,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas)
    {
        // View-space basis vectors for the isometric camera in scene pixels.
        var up = new Vector3(0f, -0.8660254f, 0.5f);
        var toward = new Vector3(0f, 0.5f, 0.8660254f);
        var right = new Vector3(1f, 0f, 0f);
        SimsSDL.Core.SceneLighting? lighting = Scene?.Lighting;
        Vector3 sunInLot = Ambient.Sun;
        float shadowStrength = ShadowsEnabled ? Ambient.Shadow : 0f;
        float reach = Ambient.Reach;
        float windowSun = Ambient.WindowSun;

        Vector3 sun = up * sunInLot.X + toward * sunInLot.Y + right * sunInLot.Z;
        sun /= MathF.Max(1e-6f, sun.Length());

        float invSqrt2 = 1f / MathF.Sqrt(2f);
        var sunTiles = new Vector3((sunInLot.Y + sunInLot.Z) * invSqrt2, (sunInLot.Y - sunInLot.Z) * invSqrt2, sunInLot.X);
        sunTiles /= MathF.Max(1e-6f, sunTiles.Length());

        var parameters = Environment?.Effect.Parameters;
        float baseLight = parameters is not null && parameters.TryGetValue("base", out float baseVal) ? baseVal : 1f;
        float glow = parameters is not null && parameters.TryGetValue("glow", out float glowVal) ? glowVal : 0f;
        int level = Scene?.ViewLevel ?? 1;
        float reachOnScreen = Ambient.LampReach * viewport.Scale;

        List<SimsSDL.Core.SceneLighting.Light> lamps = [];
        if (lighting?.Lights is not null)
        {
            foreach (SimsSDL.Core.SceneLighting.Light light in lighting.Lights)
            {
                if (light.Level != level)
                {
                    continue;
                }

                float lightReachOnScreen = reachOnScreen * (light.Fire ? 1.25f : 1f);
                Vector2 screen = viewport.Origin + new Vector2(light.X, light.Y) * viewport.Scale;
                if (screen.X > -lightReachOnScreen && screen.Y > -lightReachOnScreen &&
                    screen.X < canvas.X + lightReachOnScreen && screen.Y < canvas.Y + lightReachOnScreen)
                {
                    lamps.Add(light);
                }
            }

            static int LampPriority(SimsSDL.Core.SceneLighting.Light l) => l.Strength + (l.Fire ? 50 : 0);
            lamps.Sort((a, b) => LampPriority(b).CompareTo(LampPriority(a)));
            if (lamps.Count > MaxLamps)
            {
                lamps.RemoveRange(MaxLamps, lamps.Count - MaxLamps);
            }
        }

        ulong nowTicks = SDL_GetTicks();
        double dt = _ambientTimeTicks is ulong prevTicks && nowTicks >= prevTicks
            ? Math.Min((nowTicks - prevTicks) / 1000.0, 0.25)
            : 0.0;
        _ambientTimeTicks = nowTicks;
        double speedScale = AmbientPaused || Speed <= 0 ? 0.0 : Math.Min(Speed, 10);
        double simElapsed = Ambient.CloudTime is null ? dt * speedScale : 0.0;
        if (Ambient.CloudTime is null)
        {
            _ambientTimeSeconds = (_ambientTimeSeconds + simElapsed) % 3600.0;
        }
        float seconds = Ambient.CloudTime ?? (float)_ambientTimeSeconds;
        Vector2 drift = Ambient.Wind * seconds;
        float orientation = ((Scene?.CameraOrientation ?? 0) % 4 + 4) % 4;
        var lotSize = new Vector2(Scene?.LotWidth ?? 0, Scene?.LotHeight ?? 0);

        Vector2 wind = orientation switch
        {
            1f => new Vector2(-Ambient.Wind.Y, Ambient.Wind.X),
            2f => -Ambient.Wind,
            3f => new Vector2(Ambient.Wind.Y, -Ambient.Wind.X),
            _ => Ambient.Wind,
        };
        float slant = MathF.Min(0.6f, MathF.Max(-0.6f, (wind.X - wind.Y) * 32f * 3f / 900f));
        float windStrength = MathF.Min(1f, Ambient.Wind.Length() / 1.5f);
        bool displaced = Environment?.Effect.DisplacedSurface == true && heightMap.Frame is not null && AmbientDebug == 0;
        float trailState = 0f;
        List<Vector4> prints = [];
        if (displaced)
        {
            _trailFill += (Environment?.Effect.TrailRecovery ?? 0f) * MathF.Min((float)simElapsed, 1f);
            string key = $"{Scene?.House ?? 0}-{lotSize.X}x{lotSize.Y}";
            if (!string.Equals(_trailKey, key, StringComparison.Ordinal))
            {
                RetireDistinctTextures(_trailTextures);
                Vector2 size = (lotSize + new Vector2(2f * TrailMargin)) * TrailTexels;
                _trailTextures =
                [
                    GPU.MakeTexture((int)size.X, (int)size.Y, GPUContext.ColorFormat, SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER),
                    GPU.MakeTexture((int)size.X, (int)size.Y, GPUContext.ColorFormat, SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER),
                ];
                _trailKey = key;
                trailState = -1f;
            }

            int takeCount = Math.Min(MaxPrints, _pendingPrints.Count);
            if (takeCount > 0)
            {
                prints = _pendingPrints.GetRange(0, takeCount);
                _pendingPrints.RemoveRange(0, takeCount);
            }
        }

        float fill = _trailFill >= 0.02f ? _trailFill : 0f;
        if (fill > 0f)
        {
            _trailFill = 0f;
        }

        bool halfResAmbient = AmbientDebug == 0 && (color.Width > 1280 || color.Height > 900);
        float ambScale = halfResAmbient ? 2f : 1f;
        const int uniformCount = 16 + MaxLamps + MaxPrints;
        Vector4* uniforms = stackalloc Vector4[uniformCount];
        uniforms[0] = new Vector4(viewport.Origin.X, viewport.Origin.Y, viewport.Scale, Ambient.GroundOffset);
        uniforms[1] = new Vector4(Ambient.Radius, Ambient.Occlusion, shadowStrength, Ambient.Thickness);
        uniforms[2] = new Vector4(sun, reach);
        uniforms[3] = new Vector4(canvas.X, canvas.Y, AmbientDebug, ambScale);
        uniforms[4] = new Vector4(lamps.Count, Ambient.LampReach, Ambient.LampGain, baseLight);
        uniforms[5] = new Vector4(Ambient.ContactRadius, ShadowsEnabled ? Ambient.Contact : 0f, heightMap.Frame is null ? 0f : windowSun, _indoorBase);
        uniforms[6] = heightMap.Frame ?? new Vector4(0f, 0f, 1f, 0f);
        uniforms[7] = new Vector4(sunTiles, heightMap.Frame is null ? 0f : reach);
        uniforms[8] = new Vector4(Ambient.CloudCover, Ambient.CloudShade, orientation, Ambient.CloudHeight);
        uniforms[9] = new Vector4(drift.X, drift.Y, lotSize.X, lotSize.Y);
        uniforms[10] = new Vector4(Ambient.Rain, Ambient.Wetness, seconds, heightMap.Frame is null ? 0f : glow);
        uniforms[11] = new Vector4(Ambient.Tint, slant, windStrength, 0f);
        uniforms[12] = new Vector4(Ambient.SurfaceMode, Ambient.SurfaceAmount, fill, trailState);

        int offset = 13;
        for (int i = 0; i < lamps.Count; i++)
        {
            SimsSDL.Core.SceneLighting.Light lamp = lamps[i];
            float intensity = MathF.Min(1.5f, MathF.Max(0.4f, lamp.Strength / 40f));
            uniforms[offset + i] = new Vector4(lamp.X, lamp.Y, lamp.Toward, lamp.Fire ? -intensity : intensity);
        }
        offset += MaxLamps;
        for (int i = 0; i < prints.Count; i++)
        {
            uniforms[offset + i] = prints[i];
        }
        offset += MaxPrints;
        uniforms[offset] = new Vector4(Ambient.GrassQuality, Ambient.SpringBloom, Ambient.Snowfall, Ambient.Fireflies);
        uniforms[offset + 1] = new Vector4(Ambient.Hail, Ambient.Frost, Ambient.Thunder, 0f);
        uniforms[offset + 2] = worldShadowViewport is { } wsv
            ? new Vector4(wsv.Origin.X, wsv.Origin.Y, wsv.Scale, 1f)
            : Vector4.Zero;

        var defaultScissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
        int termW = halfResAmbient ? (color.Width + 1) / 2 : color.Width;
        int termH = halfResAmbient ? (color.Height + 1) / 2 : color.Height;
        GPUTexture term = AmbientDebug > 0 ? color : AmbientTexture(termW, termH);

        GPUTexture lift = EmptyLift();
        if ((Ambient.SurfaceMode != 0 || Ambient.SpringBloom > 0.01f) && AmbientDebug == 0)
        {
            GPUTexture source = SurfaceTexture(color.Width, color.Height);
            GPUTexture seasonDepth = SeasonDepthTexture(depth.Width, depth.Height);
            nint copy = SDL_BeginGPUCopyPass(command);
            if (copy == 0)
            {
                throw new SDLError("SDL_BeginGPUCopyPass");
            }

            try
            {
                var from = new SDL_GPUTextureLocation { texture = color.Handle };
                var to = new SDL_GPUTextureLocation { texture = source.Handle };
                SDL_CopyGPUTextureToTexture(copy, in from, in to, (uint)color.Width, (uint)color.Height, 1, false);
                var fromDepth = new SDL_GPUTextureLocation { texture = depth.Handle };
                var toDepth = new SDL_GPUTextureLocation { texture = seasonDepth.Handle };
                SDL_CopyGPUTextureToTexture(copy, in fromDepth, in toDepth, (uint)depth.Width, (uint)depth.Height, 1, false);
            }
            finally
            {
                SDL_EndGPUCopyPass(copy);
            }

            GPUTexture spriteLayer = Ambient.SurfaceMode == 1
                ? EncodeSeasonSprites(command, seasonDepth, viewport, canvas)
                : EmptyTransparent();
            EncodeSeasonDepth(command, color, seasonDepth, viewport, canvas, displaced);

            GPUTexture trail = EmptyIndoorMask();
            if (displaced && _trailTextures.Count == 2)
            {
                GPUTexture previous = _trailTextures[_trailIndex];
                _trailIndex = 1 - _trailIndex;
                trail = _trailTextures[_trailIndex];
                RunAmbientPass(command, in defaultScissor, uniforms, uniformCount, GPUContext.Program.Trail, trail, false, [previous]);
            }

            GPUTexture seasonLift = LiftTexture(color.Width, color.Height);
            if (displaced)
            {
                lift = seasonLift;
            }

            GPUTexture sims = EncodeSimMask(command, depth, viewport, canvas);
            RunAmbientPass(
                command,
                in defaultScissor,
                uniforms,
                uniformCount,
                GPUContext.Program.Season,
                color,
                true,
                [seasonDepth, ground, heightMap.Texture, _indoorMask ?? EmptyIndoorMask(), source, trail, _overheadMap ?? EmptyOverheadMap(), sims, spriteLayer],
                seasonLift);
        }

        RunAmbientPass(
            command,
            in defaultScissor,
            uniforms,
            uniformCount,
            GPUContext.Program.Ambient,
            term,
            AmbientDebug > 0,
            [depth, ground, heightMap.Texture, _indoorMask ?? EmptyIndoorMask(), footMap, lift, _overheadMap ?? EmptyOverheadMap(), worldDepth, worldBackDepth]);

        if (AmbientDebug != 0)
        {
            return;
        }

        RunAmbientPass(command, in defaultScissor, uniforms, uniformCount, GPUContext.Program.AmbientBlur, color, true, [term, depth, ground, lift]);
        if (Environment?.Effect.Atmosphere == true)
        {
            RunAmbientPass(command, in defaultScissor, uniforms, uniformCount, GPUContext.Program.Atmosphere, color, true, [term, depth, ground, _overheadMap ?? EmptyOverheadMap()]);
        }
    }

    private unsafe void RunAmbientPass(
        nint command,
        in SDL_Rect defaultScissor,
        Vector4* uniforms,
        int uniformCount,
        GPUContext.Program program,
        GPUTexture target,
        bool load,
        ReadOnlySpan<GPUTexture> textures,
        GPUTexture? second = null)
    {
        SDL_Rect passScissor = program is GPUContext.Program.Trail or GPUContext.Program.Ambient
            ? new SDL_Rect { x = 0, y = 0, w = target.Width, h = target.Height }
            : defaultScissor;

        SDL_GPUColorTargetInfo* colorTargets = stackalloc SDL_GPUColorTargetInfo[second is not null ? 2 : 1];
        colorTargets[0] = new SDL_GPUColorTargetInfo
        {
            texture = target.Handle,
            load_op = load ? SDL_GPU_LOADOP_LOAD : SDL_GPU_LOADOP_DONT_CARE,
            store_op = SDL_GPU_STOREOP_STORE,
        };
        uint numColorTargets = 1;
        if (second is not null)
        {
            colorTargets[1] = new SDL_GPUColorTargetInfo
            {
                texture = second.Handle,
                load_op = SDL_GPU_LOADOP_CLEAR,
                store_op = SDL_GPU_STOREOP_STORE,
            };
            numColorTargets = 2;
        }

        nint pass = SDL_BeginGPURenderPass(command, colorTargets, numColorTargets, null);
        if (pass == 0)
        {
            throw new SDLError("SDL_BeginGPURenderPass");
        }

        try
        {
            SDL_SetGPUScissor(pass, in passScissor);
            SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(program, GPUContext.DepthMode.Flat));

            SDL_GPUTextureSamplerBinding* bindings = stackalloc SDL_GPUTextureSamplerBinding[textures.Length];
            for (int i = 0; i < textures.Length; i++)
            {
                bindings[i] = new SDL_GPUTextureSamplerBinding { texture = textures[i].Handle, sampler = GPU.PixelSampler };
            }

            SDL_BindGPUFragmentSamplers(pass, 0, bindings, (uint)textures.Length);
            SDL_PushGPUFragmentUniformData(command, 0, (nint)uniforms, (uint)(uniformCount * sizeof(Vector4)));
            SDL_DrawGPUPrimitives(pass, 3, 1, 0, 0);
        }
        finally
        {
            SDL_EndGPURenderPass(pass);
        }
    }
}
