using System.Numerics;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using SimsSDL.UI;

namespace SimsSDL;

public sealed partial class LotRenderer
{

    private unsafe void EncodeCensorRects(
        IReadOnlyList<LotScene.CensorRect> censors,
        nint command,
        GPUTexture color,
        GPUTexture depth,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas)
    {
        GPUTexture source = SurfaceTexture(color.Width, color.Height);
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
        }
        finally
        {
            SDL_EndGPUCopyPass(copy);
        }

        var colorTarget = new SDL_GPUColorTargetInfo
        {
            texture = color.Handle,
            load_op = SDL_GPU_LOADOP_LOAD,
            store_op = SDL_GPU_STOREOP_STORE,
        };

        nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, null);
        if (pass == 0)
        {
            throw new SDLError("SDL_BeginGPURenderPass");
        }

        try
        {
            var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
            SDL_SetGPUScissor(pass, in scissor);
            SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(GPUContext.Program.Censor, GPUContext.DepthMode.Flat));

            SDL_GPUTextureSamplerBinding* bindings = stackalloc SDL_GPUTextureSamplerBinding[2];
            bindings[0] = new SDL_GPUTextureSamplerBinding { texture = source.Handle, sampler = GPU.PixelSampler };
            bindings[1] = new SDL_GPUTextureSamplerBinding { texture = depth.Handle, sampler = GPU.PixelSampler };
            SDL_BindGPUFragmentSamplers(pass, 0, bindings, 2);

            float blockSize = MathF.Max(2f, MathF.Round(4f * viewport.Scale, MidpointRounding.AwayFromZero));
            foreach (LotScene.CensorRect censor in censors)
            {
                float rx = viewport.Origin.X + censor.X * viewport.Scale;
                float ry = viewport.Origin.Y + censor.Y * viewport.Scale;
                float rw = censor.Width * viewport.Scale;
                float rh = censor.Height * viewport.Scale;
                if (rx + rw < 0f || ry + rh < 0f || rx >= canvas.X || ry >= canvas.Y)
                {
                    continue;
                }

                var quad = new Quad(new Vector4(rx, ry, rw, rh), canvas)
                {
                    DepthInterval = new Vector4(censor.Depth, blockSize, 0f, 0f),
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

    private unsafe void EncodePreview(PreviewMeshes preview, int key, Vector4 rect, nint pass, nint command, Vector2 canvas, int sampleCount = SDL_GPU_SAMPLECOUNT_1)
    {
        if (rect.Z <= 0f || rect.W <= 0f)
        {
            return;
        }

        var scissor = new SDL_Rect
        {
            x = (int)MathF.Max(0f, rect.X),
            y = (int)MathF.Max(0f, rect.Y),
            w = (int)rect.Z,
            h = (int)rect.W,
        };
        SDL_SetGPUScissor(pass, in scissor);
        SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(GPUContext.Program.Avatar, GPUContext.DepthMode.Mesh, sampleCount));

        Vector4 drawRect;
        float turntableYaw = 0f;
        if (preview.Buffers.Count > 1)
        {
            float widthSpan = key == 0 && _previewTurntableActive && preview.MaxTurntableSpan > 0f
                ? preview.MaxTurntableSpan
                : (float)preview.Bounds.Width;
            float scale = MathF.Min(rect.Z / MathF.Max(widthSpan, 0.001f), rect.W);
            drawRect = new Vector4(rect.X + rect.Z * 0.5f - scale * 0.5f, rect.Y + rect.W - scale, scale, scale);
            if (key == 0 && _previewTurntableActive)
            {
                turntableYaw = PreviewTurntableYaw;
            }
        }
        else
        {
            drawRect = rect;
        }

        for (int index = 0; index < preview.Buffers.Count; index++)
        {
            if (preview.Buffers[index] is not { } buffer || buffer.Handle == nint.Zero || preview.Textures[index].Handle == nint.Zero)
            {
                continue;
            }

            var binding = new SDL_GPUTextureSamplerBinding
            {
                texture = preview.Textures[index].Handle,
                sampler = GPU.AnisoSampler,
            };
            SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1);
            nint handle = buffer.Handle;
            SDL_BindGPUVertexStorageBuffers(pass, 0, &handle, 1);

            var transform = new Quad(drawRect, canvas)
            {
                DepthInterval = new Vector4(0f, turntableYaw, 0f, 0f),
            };
            SDL_PushGPUVertexUniformData(command, 0, (nint)(&transform), (uint)sizeof(Quad));
            SDL_DrawGPUPrimitives(pass, (uint)preview.VertexCounts[index], 1, 0, 0);
        }
    }

    private unsafe void EncodeOverlay(ReadOnlySpan<UIDraw> items, nint pass, nint command, Vector2 canvas, int sampleCount = SDL_GPU_SAMPLECOUNT_1)
    {
        if (items.IsEmpty)
        {
            return;
        }

        var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
        SDL_SetGPUScissor(pass, in scissor);
        SDL_BindGPUGraphicsPipeline(pass, GPU.Pipeline(GPUContext.Program.Sprite, GPUContext.DepthMode.Flat, sampleCount));
        nint overlaySampler = GPU.AnisoSampler;

        for (int i = 0; i < items.Length; i++)
        {
            UIDraw item = items[i];
            if (!_uiTextures.TryGetValue(item.Texture, out var entry))
            {
                continue;
            }

            var binding = new SDL_GPUTextureSamplerBinding { texture = entry.Texture.Handle, sampler = overlaySampler };
            SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1);

            var quad = new Quad(item.Rect, canvas, false, item.Opacity)
            {
                UvRect = item.UV,
                Tint = new Vector4(item.Opacity),
                DepthInterval = new Vector4(0f, 0f, 1f, 1f),
            };
            SDL_PushGPUVertexUniformData(command, 0, (nint)(&quad), (uint)sizeof(Quad));
            SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
        }
    }

    private static SDL_Rect? ComputeCensorScissor(
        IReadOnlyList<LotScene.CensorRect> censors,
        SimsSDL.Core.SceneViewport viewport,
        int maxWidth,
        int maxHeight)
    {
        float blockSize = MathF.Max(2f, MathF.Round(4f * viewport.Scale, MidpointRounding.AwayFromZero));
        int pad = (int)MathF.Ceiling(blockSize) + 2;
        int minX = maxWidth;
        int minY = maxHeight;
        int maxX = 0;
        int maxY = 0;
        foreach (LotScene.CensorRect censor in censors)
        {
            int x0 = (int)MathF.Floor(viewport.Origin.X + censor.X * viewport.Scale) - pad;
            int y0 = (int)MathF.Floor(viewport.Origin.Y + censor.Y * viewport.Scale) - pad;
            int x1 = (int)MathF.Ceiling(viewport.Origin.X + (censor.X + censor.Width) * viewport.Scale) + pad;
            int y1 = (int)MathF.Ceiling(viewport.Origin.Y + (censor.Y + censor.Height) * viewport.Scale) + pad;
            if (x1 <= 0 || y1 <= 0 || x0 >= maxWidth || y0 >= maxHeight) continue;
            minX = Math.Min(minX, Math.Max(0, x0));
            minY = Math.Min(minY, Math.Max(0, y0));
            maxX = Math.Max(maxX, Math.Min(maxWidth, x1));
            maxY = Math.Max(maxY, Math.Min(maxHeight, y1));
        }

        return maxX > minX && maxY > minY
            ? new SDL_Rect { x = minX, y = minY, w = maxX - minX, h = maxY - minY }
            : null;
    }

    private static bool IsTranslucentAvatarMesh(LotScene.Mesh mesh) =>
        mesh.ObjectID > 0 && mesh.Unlit != true && mesh.Roof is null &&
        mesh.Tint is { Count: 4 } tint && tint[3] < 0.999f;

    private static float SrgbChannelToLinear(float c)
    {
        c = Math.Clamp(c, 0f, 1f);
        return c <= 0.04045f ? c / 12.92f : MathF.Pow((c + 0.055f) / 1.055f, 2.4f);
    }

    private bool HasTranslucentAvatars()
    {
        if (Scene?.Meshes is not { Count: > 0 } meshes)
        {
            return false;
        }

        for (int i = 0; i < meshes.Count; i++)
        {
            if (IsTranslucentAvatarMesh(meshes[i]))
            {
                return true;
            }
        }

        return false;
    }

    private unsafe void EncodeTranslucentAvatars(nint pass, nint command, Vector2 canvas, int sampleCount = SDL_GPU_SAMPLECOUNT_1, SDL_Rect? clipScissor = null)
    {
        if (Scene is not { Meshes.Count: > 0 } scene || Viewport(canvas) is not { } viewport || !HasTranslucentAvatars())
        {
            return;
        }

        float scale = viewport.Scale;
        Vector2 origin = viewport.Origin;
        LotZoom zoom = EffectiveVisualZoom;

        var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
        if (clipScissor is { } clip)
        {
            int left = Math.Max(scissor.x, clip.x);
            int top = Math.Max(scissor.y, clip.y);
            int right = Math.Min(scissor.x + scissor.w, clip.x + clip.w);
            int bottom = Math.Min(scissor.y + scissor.h, clip.y + clip.h);
            scissor = new SDL_Rect { x = left, y = top, w = Math.Max(0, right - left), h = Math.Max(0, bottom - top) };
            if (scissor.w == 0 || scissor.h == 0)
            {
                return;
            }
        }

        float clipLeft = scissor.x;
        float clipTop = scissor.y;
        float clipRight = scissor.x + scissor.w;
        float clipBottom = scissor.y + scissor.h;
        SDL_SetGPUScissor(pass, in scissor);

        var groups = new List<(int ObjectId, List<int> MeshIndices)>();
        var groupIndexByObject = new Dictionary<int, int>();
        for (int i = 0; i < _drawItems.Count; i++)
        {
            SceneDrawItem item = _drawItems[i];
            if (item.IsSprite)
            {
                continue;
            }

            int index = item.Index;
            if (index >= scene.Meshes.Count || index >= _meshSlices.Count || _meshSlices[index] is null)
            {
                continue;
            }

            LotScene.Mesh mesh = scene.Meshes[index];
            if (!IsTranslucentAvatarMesh(mesh))
            {
                continue;
            }

            if (index < _meshBounds.Length)
            {
                Vector4 b = _meshBounds[index];
                if (origin.X + b.Z * scale < clipLeft ||
                    origin.Y + b.W * scale < clipTop ||
                    origin.X + b.X * scale >= clipRight ||
                    origin.Y + b.Y * scale >= clipBottom)
                {
                    continue;
                }
            }

            if (!groupIndexByObject.TryGetValue(mesh.ObjectID, out int groupIdx))
            {
                groupIdx = groups.Count;
                groupIndexByObject[mesh.ObjectID] = groupIdx;
                groups.Add((mesh.ObjectID, []));
            }

            groups[groupIdx].MeshIndices.Add(index);
        }

        if (groups.Count == 0)
        {
            return;
        }

        nint prepassPipeline = GPU.Pipeline(GPUContext.Program.Avatar, GPUContext.DepthMode.MeshDepthPrepass, sampleCount);
        nint colorPipeline = GPU.Pipeline(GPUContext.Program.Avatar, GPUContext.DepthMode.MeshEqual, sampleCount);

        void DrawGhostSlices(List<int> meshIndices, bool colorSubpass)
        {
            nint currentVertexBuffer = 0;
            nint currentTexHandle = 0;
            for (int k = 0; k < meshIndices.Count; k++)
            {
                int index = meshIndices[k];
                LotScene.Mesh mesh = scene.Meshes[index];
                MeshSlice slice = _meshSlices[index]!.Value;
                if (slice.Buffer.Handle == nint.Zero)
                {
                    continue;
                }
                int meshTexIdx = mesh.TextureFor(zoom);
                if ((uint)meshTexIdx >= (uint)_sceneTextures.Count)
                {
                    continue;
                }
                GPUTexture tex = _sceneTextures[meshTexIdx];
                if (tex.Handle == nint.Zero)
                {
                    continue;
                }
                if (tex.Handle != currentTexHandle)
                {
                    currentTexHandle = tex.Handle;
                    var binding = new SDL_GPUTextureSamplerBinding { texture = tex.Handle, sampler = GPU.AnisoSampler };
                    SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1);
                }

                if (slice.Buffer.Handle != currentVertexBuffer)
                {
                    currentVertexBuffer = slice.Buffer.Handle;
                    nint handle = slice.Buffer.Handle;
                    SDL_BindGPUVertexStorageBuffers(pass, 0, &handle, 1);
                }

                Vector4 tint = Vector4.One;
                if (colorSubpass && mesh.Tint is { Count: 4 } meshTint)
                {
                    float alpha = MathF.Pow(Math.Clamp(meshTint[3], 0f, 1f), 1.6f);
                    tint = new Vector4(
                        SrgbChannelToLinear(MathF.Min(1f, meshTint[0] * 1.5f)),
                        SrgbChannelToLinear(meshTint[1]),
                        SrgbChannelToLinear(MathF.Min(1f, meshTint[2] * 1.06f)),
                        alpha);
                }

                var quad = new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas)
                {
                    Tint = tint,
                    UvRect = new Vector4(1f, 0f, 1f, 1f),
                    DepthInterval = new Vector4(BitConverter.UInt32BitsToSingle(slice.FirstVertex), 0f, 0f, 0f),
                };
                SDL_PushGPUVertexUniformData(command, 0, (nint)(&quad), (uint)sizeof(Quad));
                SDL_DrawGPUPrimitives(pass, slice.VertexCount, 1, 0, 0);
            }
        }

        // Render each translucent ghost with a frontmost-surface depth prepass followed by an
        // EQUAL color pass so interior limbs never double-blend or punch holes in the torso.
        for (int g = 0; g < groups.Count; g++)
        {
            List<int> meshIndices = groups[g].MeshIndices;
            SDL_BindGPUGraphicsPipeline(pass, prepassPipeline);
            DrawGhostSlices(meshIndices, colorSubpass: false);
            SDL_BindGPUGraphicsPipeline(pass, colorPipeline);
            DrawGhostSlices(meshIndices, colorSubpass: true);
        }
    }

    private unsafe void EncodeLot(
        nint pass,
        nint command,
        Vector2 canvas,
        int sampleCount = SDL_GPU_SAMPLECOUNT_1,
        SDL_Rect? clipScissor = null,
        bool deferTranslucentAvatars = false,
        Vector2? originOverride = null,
        float? scaleOverride = null,
        LotZoom? zoomOverride = null,
        bool skipTerrainAndRoads = false,
        SimsSDL.Core.SceneViewport? viewportOverride = null,
        bool shadowDepthOnly = false,
        bool shadowBackLayer = false,
        ShadowItemFilter shadowFilter = ShadowItemFilter.All)
    {
        if (Scene is not { } scene || (viewportOverride ?? Viewport(canvas)) is not { } viewport)
        {
            return;
        }

        float scale = scaleOverride ?? viewport.Scale;
        Vector2 origin = originOverride ?? viewport.Origin;

        LotZoom zoom = zoomOverride ?? EffectiveVisualZoom;
        LotZoom assetZoom = zoomOverride ?? AssetZoomForScale(scale, zoom);
        float artTexelScale = scale / assetZoom.Factor();
        bool settledIntegerUi = MathF.Abs(artTexelScale - MathF.Round(artTexelScale, MidpointRounding.AwayFromZero)) <= 1e-4f
            && (scaleOverride is not null || !IsZoomInterpolating);
        nint artSampler = settledIntegerUi ? GPU.PixelSampler : GPU.Sampler;
        nint spriteSampler = AntiAliasedSprites ? GPU.Sampler : artSampler;
        bool spriteMinified = artTexelScale < 0.99f;
        nint colorSpriteSampler = AntiAliasedSprites && spriteMinified ? GPU.AnisoSampler : spriteSampler;
        SimsSDL.Core.SceneLighting? lighting = ActiveLighting(scene);
        IReadOnlyDictionary<string, float>? blackboard = AmbientEnabled ? ClientPlugins?.Blackboard : null;
        float Bb(string key, float fallback = 0f) =>
            blackboard is not null && blackboard.TryGetValue(key, out float v) ? v : fallback;
        bool enhancedShadowsActive = AmbientEnabled && LightingEnabled && ShadowsEnabled && Bb("lighting.shadows") > 0.01f;
        string? terrainOverride = AmbientEnabled ? ClientPlugins?.ActiveTerrainShaderPath : null;
        bool IsOutsideRoom(int? room) =>
            room is not int r || lighting is null || r < 0 || r >= lighting.Rooms.Count || lighting.Rooms[r].Outside;

        var scissor = new SDL_Rect { x = 0, y = 0, w = (int)canvas.X, h = (int)canvas.Y };
        if (clipScissor is { } clip)
        {
            int left = Math.Max(scissor.x, clip.x);
            int top = Math.Max(scissor.y, clip.y);
            int right = Math.Min(scissor.x + scissor.w, clip.x + clip.w);
            int bottom = Math.Min(scissor.y + scissor.h, clip.y + clip.h);
            scissor = new SDL_Rect { x = left, y = top, w = Math.Max(0, right - left), h = Math.Max(0, bottom - top) };
            if (scissor.w == 0 || scissor.h == 0)
            {
                return;
            }
        }
        float clipLeft = scissor.x;
        float clipTop = scissor.y;
        float clipRight = scissor.x + scissor.w;
        float clipBottom = scissor.y + scissor.h;
        SDL_SetGPUScissor(pass, in scissor);

        (GPUContext.Program Program, GPUContext.DepthMode Depth)? currentPipeline = null;
        (nint Tex, nint Sampler)? currentSingleSampler = null;
        (nint T0, nint S0, nint T1, nint S1)? currentDualSamplers = null;
        nint currentVertexBuffer = 0;

        void Bind(GPUContext.Program program, GPUContext.DepthMode depth)
        {
            if (currentPipeline is { } current && current.Program == program && current.Depth == depth)
            {
                return;
            }

            string? fragOverride = program == GPUContext.Program.Terrain ? terrainOverride : null;
            nint resolved = sampleCount == SDL_GPU_SAMPLECOUNT_1 && fragOverride is null
                ? (program, depth) switch
                {
                    (GPUContext.Program.SpriteDepth, GPUContext.DepthMode.Mesh) => GPU.SpriteDepthPipeline,
                    (GPUContext.Program.SpriteDepth, GPUContext.DepthMode.MeshEdge) => GPU.SpriteDepthEdgePipeline,
                    _ => GPU.Pipeline(program, depth, sampleCount),
                }
                : GPU.Pipeline(program, depth, sampleCount, fragOverride);
            SDL_BindGPUGraphicsPipeline(pass, resolved);
            currentPipeline = (program, depth);
            currentSingleSampler = null;
            currentDualSamplers = null;
        }

        bool BindTexture(GPUTexture texture, nint sampler)
        {
            nint th = texture.Handle;
            if (th == nint.Zero)
            {
                return false;
            }

            if (currentSingleSampler is { } cur && cur.Tex == th && cur.Sampler == sampler)
            {
                return true;
            }

            var binding = new SDL_GPUTextureSamplerBinding { texture = th, sampler = sampler };
            SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1);
            currentSingleSampler = (th, sampler);
            currentDualSamplers = null;
            return true;
        }

        bool BindTextures(GPUTexture first, nint firstSampler, GPUTexture second, nint secondSampler)
        {
            nint t0 = first.Handle;
            nint t1 = second.Handle;
            if (t0 == nint.Zero || t1 == nint.Zero)
            {
                return false;
            }

            if (currentDualSamplers is { } cur && cur.T0 == t0 && cur.S0 == firstSampler && cur.T1 == t1 && cur.S1 == secondSampler)
            {
                return true;
            }

            SDL_GPUTextureSamplerBinding* bindings = stackalloc SDL_GPUTextureSamplerBinding[2];
            bindings[0] = new SDL_GPUTextureSamplerBinding { texture = t0, sampler = firstSampler };
            bindings[1] = new SDL_GPUTextureSamplerBinding { texture = t1, sampler = secondSampler };
            SDL_BindGPUFragmentSamplers(pass, 0, bindings, 2);
            currentDualSamplers = (t0, firstSampler, t1, secondSampler);
            currentSingleSampler = null;
            return true;
        }

        bool BindVertices(GPUBuffer buffer)
        {
            nint handle = buffer.Handle;
            if (handle == nint.Zero)
            {
                return false;
            }

            if (currentVertexBuffer == handle)
            {
                return true;
            }

            currentVertexBuffer = handle;
            SDL_BindGPUVertexStorageBuffers(pass, 0, &handle, 1);
            return true;
        }

        void Push(in Quad quad)
        {
            Quad copy = quad;
            SDL_PushGPUVertexUniformData(command, 0, (nint)(&copy), (uint)sizeof(Quad));
        }

        if (!shadowDepthOnly && !skipTerrainAndRoads)
        {
            Vector4 outsideTint = EffectiveOutsideTint(lighting);
            ReadOnlySpan<GPUBuffer?> terrainBuffers = [_surroundingsTerrain, _terrainBuffer];
            for (int t = 0; t < terrainBuffers.Length; t++)
            {
                if (terrainBuffers[t] is not { } tBuf)
                {
                    continue;
                }

                Bind(GPUContext.Program.Terrain, GPUContext.DepthMode.Flat);
                if (BindVertices(tBuf))
                {
                    var transform = new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas)
                    {
                        Tint = outsideTint,
                        UvRect = new Vector4(TerrainDetail, (float)zoom, 0f, 0f),
                    };
                    Push(in transform);
                    SDL_DrawGPUPrimitives(pass, (uint)tBuf.Count, 1, 0, 0);
                }
            }

            if (_surroundingsRoads.Count > 0)
            {
                nint roadSampler = settledIntegerUi ? artSampler : GPU.AnisoSampler;
                Bind(GPUContext.Program.Surface, GPUContext.DepthMode.Flat);
                for (int r = 0; r < _surroundingsRoads.Count; r++)
                {
                    (LotScene.Mesh roadMesh, MeshSlice roadSlice) = _surroundingsRoads[r];
                    int roadTexIdx = roadMesh.TextureFor(assetZoom);
                    if ((uint)roadTexIdx >= (uint)_sceneTextures.Count)
                    {
                        continue;
                    }

                    GPUTexture roadTex = _sceneTextures[roadTexIdx];
                    if (roadTex.Format == SDL_GPU_TEXTUREFORMAT_R8_UNORM ||
                        !BindTexture(roadTex, roadSampler) ||
                        !BindVertices(roadSlice.Buffer))
                    {
                        continue;
                    }

                    var transform = new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas)
                    {
                        Tint = outsideTint,
                        DepthInterval = new Vector4(BitConverter.UInt32BitsToSingle(roadSlice.FirstVertex), 0f, 0f, 0f),
                    };
                    Push(in transform);
                    SDL_DrawGPUPrimitives(pass, roadSlice.VertexCount, 1, 0, 0);
                }
            }
        }

        if (!shadowDepthOnly && ShowsPlacement && _buildGridLevel1Buffer is not null)
        {
            Bind(GPUContext.Program.Placement, GPUContext.DepthMode.Flat);
            if (BindVertices(_buildGridLevel1Buffer))
            {
                Push(new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas));
                SDL_DrawGPUPrimitives(pass, (uint)_buildGridLevel1Buffer.Count, 1, 0, 0);
            }
        }

        void DrawFloorShadow(LotScene.Sprite sprite, bool forceShadow = false, float opacity = 1f)
        {
            if (shadowDepthOnly || !ShadowsEnabled || !LiveMode || scale < 0.22f || sprite.Wall is not null ||
                (enhancedShadowsActive && !forceShadow) ||
                sprite.FloorShadowImage(zoom) is not { } shadow)
            {
                return;
            }

            var shadowRect = new Vector4(sprite.X + shadow.X, sprite.Y + shadow.Y, shadow.Width, shadow.Height);
            if (origin.X + (shadowRect.X + shadowRect.Z) * scale < clipLeft ||
                origin.Y + (shadowRect.Y + shadowRect.W) * scale < clipTop ||
                origin.X + shadowRect.X * scale >= clipRight ||
                origin.Y + shadowRect.Y * scale >= clipBottom)
            {
                return;
            }

            if ((uint)shadow.Texture >= (uint)_sceneTextures.Count)
            {
                return;
            }
            Bind(GPUContext.Program.Sprite, GPUContext.DepthMode.Flat);
            if (!BindTexture(_sceneTextures[shadow.Texture], colorSpriteSampler))
            {
                return;
            }
            var shadowQuad = new Quad(
                new Vector4(origin.X + shadowRect.X * scale, origin.Y + shadowRect.Y * scale, shadowRect.Z * scale, shadowRect.W * scale),
                canvas,
                opacity: opacity)
            {
                DepthInterval = new Vector4(0f, 0f, 0f, 1f),
                Tint = new Vector4(opacity),
            };
            Push(in shadowQuad);
            SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
        }

        void DrawSprite(LotScene.Sprite sourceSprite, SpritePassMode passMode)
        {
            if (zoom == LotZoom.Far && sourceSprite.HideAtFarZoom == true)
            {
                return;
            }

            if (shadowDepthOnly &&
                (passMode == SpritePassMode.EdgeFringe ||
                 sourceSprite.HideAtFarZoom == true ||
                 (sourceSprite.DepthTexture is null &&
                  !(ShowsPlacement && sourceSprite.Wall is not null && WallPaintPreview is not null))))
            {
                return;
            }

            if (passMode == SpritePassMode.EdgeFringe &&
                sourceSprite.DepthTexture is null &&
                !(ShowsPlacement && sourceSprite.Wall is not null && WallPaintPreview is not null))
            {
                return;
            }

            bool useWallPaint = false;
            Vector2 offset = Vector2.Zero;
            LotScene.Sprite sprite = sourceSprite;
            if (ShowsPlacement &&
                sourceSprite.Wall is { } wall &&
                WallPaintPreview is { } preview &&
                _wallPaintTextures.Count == preview.Scene.Textures.Count &&
                _wallPaintByWall.TryGetValue(wall, out LotScene.Sprite? candidate))
            {
                sprite = candidate;
                useWallPaint = true;
                offset = new Vector2(preview.X, preview.Y);
            }

            if (HasActiveRenderPasses && IsPostAmbientOverlaySprite(sprite))
            {
                return;
            }

            int texture = sprite.Texture;
            int? depthTexture = sprite.DepthTexture;
            var rect = new Vector4(sprite.X + offset.X, sprite.Y + offset.Y, sprite.Width, sprite.Height);
            if (sprite.Image(assetZoom) is { } image)
            {
                texture = image.Texture;
                depthTexture = image.DepthTexture;
                rect = new Vector4(sprite.X + offset.X + image.X, sprite.Y + offset.Y + image.Y, image.Width, image.Height);
            }

            if ((passMode == SpritePassMode.EdgeFringe || shadowDepthOnly) && depthTexture is null)
            {
                return;
            }

            if (origin.X + (rect.X + rect.Z) * scale < clipLeft ||
                origin.Y + (rect.Y + rect.W) * scale < clipTop ||
                origin.X + rect.X * scale >= clipRight ||
                origin.Y + rect.Y * scale >= clipBottom)
            {
                return;
            }

            if (scale < 0.22f &&
                sprite.Wall is null &&
                sprite.ArchitectureDepth is null &&
                sprite.Junction is null &&
                MathF.Max(rect.Z, rect.W) * scale < (scale < 0.14f ? 3.5f : 2.2f))
            {
                return;
            }

            IReadOnlyList<GPUTexture> colorList = useWallPaint ? _wallPaintTextures : _sceneTextures;
            if ((uint)texture >= (uint)colorList.Count)
            {
                return;
            }
            GPUTexture colorTex = colorList[texture];
            if (colorTex.Format == SDL_GPU_TEXTUREFORMAT_R8_UNORM)
            {
                return;
            }
            var quad = new Quad(
                new Vector4(origin.X + rect.X * scale, origin.Y + rect.Y * scale, rect.Z * scale, rect.W * scale),
                canvas,
                sprite.Flip);

            if (depthTexture is int dt)
            {
                if ((uint)dt >= (uint)colorList.Count)
                {
                    return;
                }
                GPUContext.DepthMode depthMode = shadowDepthOnly
                    ? (shadowBackLayer ? GPUContext.DepthMode.MeshDepthBack : GPUContext.DepthMode.MeshDepthPrepass)
                    : (passMode == SpritePassMode.EdgeFringe ? GPUContext.DepthMode.MeshEdge : GPUContext.DepthMode.Mesh);
                Bind(GPUContext.Program.SpriteDepth, depthMode);
                GPUTexture depthTex = colorList[dt];
                if (!BindTextures(colorTex, colorSpriteSampler, depthTex, GPU.PixelSampler))
                {
                    return;
                }
                float depthNear = sprite.DepthNear ?? 0f;
                float depthFar = sprite.DepthFar ?? 0f;
                if (shadowDepthOnly && shadowBackLayer)
                {
                    const float spriteBackShellDepth = 0.00135f;
                    depthNear = MathF.Min(0.999f, depthNear + spriteBackShellDepth);
                    depthFar = MathF.Min(0.999f, depthFar + spriteBackShellDepth);
                }
                float coreAlphaCutoff = shadowDepthOnly ? 0.15f : (scale < 0.14f ? 0.45f : 0.985f);
                quad.DepthInterval = passMode switch
                {
                    SpritePassMode.Single => new Vector4(depthNear, depthFar, coreAlphaCutoff, 0f),
                    SpritePassMode.OpaqueCore => (AntiAliasedSprites || shadowDepthOnly)
                        ? new Vector4(depthNear, depthFar, coreAlphaCutoff, 1f)
                        : new Vector4(depthNear, depthFar, coreAlphaCutoff, 0f),
                    SpritePassMode.EdgeFringe => AntiAliasedSprites
                        ? new Vector4(depthNear, depthFar, 0.985f, 2f)
                        : new Vector4(depthNear, depthFar, 0.985f, -1f),
                    _ => default,
                };
            }
            else
            {
                Bind(GPUContext.Program.Sprite, GPUContext.DepthMode.Flat);
                if (!BindTexture(colorTex, colorSpriteSampler))
                {
                    return;
                }
                quad.DepthInterval = new Vector4(0f, 0f, 8.0f / 31.0f, AntiAliasedSprites ? 1f : 0f);
            }

            quad.Tint = EffectiveRoomTint(lighting, sprite.Room);
            Push(in quad);
            SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
        }

        SpritePassMode primaryPass = SpritePassMode.OpaqueCore;
        bool drewSurroundingsShadows = shadowDepthOnly || skipTerrainAndRoads || _surroundingsDecorations.Count == 0;
        bool drewSurroundingsSprites = drewSurroundingsShadows;
        float surroundingsShadowOpacity = enhancedShadowsActive
            ? 0.50f * (1f - Math.Clamp(Bb("lighting.nightGlow"), 0f, 1f) * 0.80f)
            : Math.Clamp(((lighting?.Outside.Multiplier.X ?? 1f) - 0.35f) / 0.65f, 0.20f, 1f);
        int lastShadowLevel = 0;
        bool drewFloorBrush = false;
        bool drewLevel2BuildGrid = false;

        void DrawLevel2BuildGridIfNeeded()
        {
            if (shadowDepthOnly || !ShowsPlacement || drewLevel2BuildGrid || scene.SelectedLevel < 2 || _buildGridLevel2Buffer is null)
            {
                return;
            }

            drewLevel2BuildGrid = true;
            Bind(GPUContext.Program.Placement, GPUContext.DepthMode.Flat);
            if (BindVertices(_buildGridLevel2Buffer))
            {
                Push(new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas));
                SDL_DrawGPUPrimitives(pass, (uint)_buildGridLevel2Buffer.Count, 1, 0, 0);
            }
        }

        void DrawFloorBrushIfNeeded()
        {
            if (shadowDepthOnly || !ShowsPlacement || drewFloorBrush || _floorBrushBuffer is null || _floorBrushTexture is null)
            {
                return;
            }

            drewFloorBrush = true;
            Bind(GPUContext.Program.Surface, GPUContext.DepthMode.Flat);
            if (!BindTexture(_floorBrushTexture, artSampler) || !BindVertices(_floorBrushBuffer))
            {
                return;
            }
            var transform = new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas)
            {
                Tint = Vector4.One,
            };
            Push(in transform);
            SDL_DrawGPUPrimitives(pass, (uint)_floorBrushBuffer.Count, 1, 0, 0);
        }

        (int Level, int Layer) ItemGroup(SceneDrawItem item) => item.Kind switch
        {
            SceneDrawItem.ItemKind.Sprite => (uint)item.Index < (uint)scene.Sprites.Count
                ? (scene.Sprites[item.Index].Level ?? 1, scene.Sprites[item.Index].Layer ?? 0)
                : (1, 0),
            _ => scene.Meshes is { } itemMeshes && (uint)item.Index < (uint)itemMeshes.Count
                ? (itemMeshes[item.Index].Level ?? 1, itemMeshes[item.Index].Layer ?? 1)
                : (1, 1),
        };

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

            if (itemLevel >= scene.SelectedLevel)
            {
                DrawLevel2BuildGridIfNeeded();
            }

            if (itemLevel > scene.SelectedLevel || (itemLevel == scene.SelectedLevel && itemLayer >= 1))
            {
                DrawFloorBrushIfNeeded();
            }

            if (!shadowDepthOnly && itemLayer >= 1 && lastShadowLevel < itemLevel)
            {
                lastShadowLevel = itemLevel;
                if (!drewSurroundingsShadows && itemLevel >= 1)
                {
                    drewSurroundingsShadows = true;
                    for (int s = 0; s < _surroundingsDecorations.Count; s++)
                    {
                        DrawFloorShadow(_surroundingsDecorations[s], forceShadow: true, opacity: surroundingsShadowOpacity);
                    }
                }
                for (int s = 0; s < _activeShadowSpriteIndices.Count; s++)
                {
                    int shadowSpriteIdx = _activeShadowSpriteIndices[s];
                    if ((uint)shadowSpriteIdx >= (uint)scene.Sprites.Count)
                    {
                        continue;
                    }
                    LotScene.Sprite sprite = scene.Sprites[shadowSpriteIdx];
                    if ((sprite.Level ?? 1) == itemLevel)
                    {
                        DrawFloorShadow(sprite);
                    }
                }

                if (!enhancedShadowsActive && scene.Meshes is not null)
                {
                    foreach (LotScene.Mesh mesh in scene.Meshes)
                    {
                        if ((mesh.Level ?? 1) != itemLevel ||
                            !ShadowsEnabled || !LiveMode || scale < 0.22f ||
                            mesh.FloorShadowImage(zoom) is not { } shadow ||
                            (uint)shadow.Texture >= (uint)_sceneTextures.Count)
                        {
                            continue;
                        }

                        var shadowRect = new Vector4(shadow.X, shadow.Y, shadow.Width, shadow.Height);
                        if (origin.X + (shadowRect.X + shadowRect.Z) * scale < clipLeft ||
                            origin.Y + (shadowRect.Y + shadowRect.W) * scale < clipTop ||
                            origin.X + shadowRect.X * scale >= clipRight ||
                            origin.Y + shadowRect.Y * scale >= clipBottom)
                        {
                            continue;
                        }

                        Bind(GPUContext.Program.Sprite, GPUContext.DepthMode.Flat);
                        if (!BindTexture(_sceneTextures[shadow.Texture], colorSpriteSampler))
                        {
                            continue;
                        }
                        var shadowQuad = new Quad(
                            new Vector4(origin.X + shadowRect.X * scale, origin.Y + shadowRect.Y * scale, shadowRect.Z * scale, shadowRect.W * scale),
                            canvas)
                        {
                            DepthInterval = new Vector4(0f, 0f, 0f, 1f),
                            Tint = Vector4.One,
                        };
                        Push(in shadowQuad);
                        SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
                    }
                }
            }

            PendingMeshBatch? pendingMesh = null;
            void FlushPendingMesh()
            {
                if (pendingMesh is not { } batch)
                {
                    return;
                }

                pendingMesh = null;
                Bind(batch.Program, batch.Depth);
                if (!BindTexture(batch.Texture, batch.Sampler) || !BindVertices(batch.Buffer))
                {
                    return;
                }
                var transform = new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas)
                {
                    Tint = batch.Tint,
                    DepthInterval = new Vector4(BitConverter.UInt32BitsToSingle(batch.FirstVertex), 0f, 0f, 0f),
                };
                transform.UvRect = new Vector4(batch.UVRectX, batch.SunDir.X, batch.SunDir.Y, batch.SunDir.Z);
                Push(in transform);
                SDL_DrawGPUPrimitives(pass, batch.VertexCount, 1, 0, 0);
            }

            float nightGlow = Bb("lighting.nightGlow");
            Vector3 currentSun = SunOverride ?? new Vector3(Bb("lighting.sunUp", 1f), Bb("lighting.sunToward"), Bb("lighting.sunRight"));
            Vector3 roofSunDir = ResolveRoofSunDirection(SuppressVanillaLightingActive, currentSun, nightGlow);

            float ItemSortDepth(SceneDrawItem item) => item.Kind switch
            {
                SceneDrawItem.ItemKind.Sprite => (uint)item.Index < (uint)scene.Sprites.Count
                    ? (scene.Sprites[item.Index].Depth ?? item.Index)
                    : 0f,
                _ => scene.Meshes is { } itemMeshes && (uint)item.Index < (uint)itemMeshes.Count
                    ? itemMeshes[item.Index].Depth
                    : 0f,
            };

            bool interleaveSurroundingsHere = !drewSurroundingsSprites && itemLevel == 1 && itemLayer == 1;
            if (!drewSurroundingsSprites && (itemLevel > 1 || (itemLevel == 1 && itemLayer > 1)))
            {
                drewSurroundingsSprites = true;
                bool anyDepth = false;
                for (int d = 0; d < _surroundingsDecorations.Count; d++)
                {
                    if (_surroundingsDecorations[d].DepthTexture is not null) anyDepth = true;
                    DrawSprite(_surroundingsDecorations[d], primaryPass);
                }
                if (anyDepth && scale >= 0.14f)
                {
                    for (int d = 0; d < _surroundingsDecorations.Count; d++)
                        DrawSprite(_surroundingsDecorations[d], SpritePassMode.EdgeFringe);
                }
            }

            int surCursor = 0;
            bool hasDepthSprites = false;
            for (int i = sliceStart; i < sliceEnd; i++)
            {
                SceneDrawItem item = _drawItems[i];
                if (interleaveSurroundingsHere)
                {
                    float curDepth = ItemSortDepth(item);
                    while (surCursor < _surroundingsDecorations.Count && (_surroundingsDecorations[surCursor].Depth ?? 0f) <= curDepth)
                    {
                        if (pendingMesh is not null)
                            FlushPendingMesh();
                        LotScene.Sprite surSprite = _surroundingsDecorations[surCursor++];
                        if (surSprite.DepthTexture is not null)
                            hasDepthSprites = true;
                        DrawSprite(surSprite, primaryPass);
                    }
                }
                if (shadowFilter != ShadowItemFilter.All)
                {
                    bool isDynamicCaster = (!item.IsSprite
                            && scene.Meshes is not null
                            && (uint)item.Index < (uint)scene.Meshes.Count
                            && scene.Meshes[item.Index].Floor is null
                            && scene.Meshes[item.Index].Roof is null
                            && scene.Meshes[item.Index].Indicator != true)
                        || (item.IsSprite
                            && (uint)item.Index < (uint)scene.Sprites.Count
                            && scene.Sprites[item.Index].DynamicShadow == true);
                    bool isStatic = !isDynamicCaster;
                    if ((shadowFilter == ShadowItemFilter.StaticOnly) != isStatic)
                    {
                        continue;
                    }
                }
                if (item.IsSprite)
                {
                    if (pendingMesh is not null)
                    {
                        FlushPendingMesh();
                    }

                    if ((uint)item.Index >= (uint)scene.Sprites.Count)
                    {
                        continue;
                    }
                    LotScene.Sprite sprite = scene.Sprites[item.Index];
                    if (sprite.DepthTexture is not null)
                    {
                        hasDepthSprites = true;
                    }

                    DrawSprite(sprite, primaryPass);
                }
                else
                {
                    int index = item.Index;
                    if (index < _meshBounds.Length)
                    {
                        Vector4 b = _meshBounds[index];
                        if (origin.X + b.Z * scale < clipLeft ||
                            origin.Y + b.W * scale < clipTop ||
                            origin.X + b.X * scale >= clipRight ||
                            origin.Y + b.Y * scale >= clipBottom)
                        {
                            continue;
                        }
                    }

                    if (scene.Meshes is null || index >= scene.Meshes.Count || index >= _meshSlices.Count || _meshSlices[index] is not { } slice)
                    {
                        continue;
                    }

                    LotScene.Mesh mesh = scene.Meshes[index];
                    if (skipTerrainAndRoads && mesh.Floor is { } floor && (mesh.Level ?? 1) == 1 && floor.Pattern is 9 or 10 or 11 or 65534)
                    {
                        continue;
                    }
                    if (IsTranslucentAvatarMesh(mesh) || (deferTranslucentAvatars && mesh.Indicator == true))
                    {
                        continue;
                    }

                    bool unlit = mesh.Unlit == true;
                    GPUContext.Program prog = unlit ? GPUContext.Program.Surface : GPUContext.Program.Avatar;
                    GPUContext.DepthMode depthMode = unlit && mesh.Floor?.Pattern != 65535 && (mesh.Level ?? 1) == 1
                        ? GPUContext.DepthMode.Flat
                        : GPUContext.DepthMode.Mesh;
                    if (shadowDepthOnly)
                    {
                        if (depthMode == GPUContext.DepthMode.Flat || mesh.Roof is not null || mesh.Indicator == true)
                        {
                            continue;
                        }

                        depthMode = shadowBackLayer ? GPUContext.DepthMode.MeshDepthBack : GPUContext.DepthMode.MeshDepthPrepass;
                    }
                    int meshTexIdx = mesh.TextureFor(assetZoom);
                    if ((uint)meshTexIdx >= (uint)_sceneTextures.Count)
                    {
                        continue;
                    }
                    GPUTexture tex = _sceneTextures[meshTexIdx];
                    if (tex.Format == SDL_GPU_TEXTUREFORMAT_R8_UNORM)
                    {
                        continue;
                    }
                    nint samp = mesh.Roof is not null
                        ? GPU.RoofSampler
                        : mesh.Floor is not null
                            ? (settledIntegerUi ? artSampler : GPU.AnisoSampler)
                            : GPU.AnisoSampler;
                    Vector4 tint = EffectiveRoomTint(lighting, mesh.Room);
                    if (mesh.Tint is { Count: 4 } meshTint)
                    {
                        tint *= new Vector4(meshTint[0], meshTint[1], meshTint[2], meshTint[3]);
                    }
                    float uvX = !unlit && mesh.Roof is not null
                        ? 2f
                        : (!unlit && mesh.Roof is null && CharacterDetail == 0) ? 1f : 0f;
                    Vector3 sunDir = !unlit
                        ? (mesh.Roof is not null
                            ? roofSunDir
                            : (SuppressVanillaLightingActive ? (IsOutsideRoom(mesh.Room) ? roofSunDir : Vector3.UnitY) : Vector3.Zero))
                        : Vector3.Zero;

                    if (pendingMesh is { } existing &&
                        existing.Program == prog &&
                        existing.Depth == depthMode &&
                        existing.Texture.Handle == tex.Handle &&
                        existing.Sampler == samp &&
                        existing.Buffer.Handle == slice.Buffer.Handle &&
                        existing.Tint == tint &&
                        existing.UVRectX == uvX &&
                        existing.SunDir == sunDir &&
                        existing.FirstVertex + existing.VertexCount == slice.FirstVertex)
                    {
                        existing.VertexCount += slice.VertexCount;
                        pendingMesh = existing;
                    }
                    else
                    {
                        if (pendingMesh is not null)
                        {
                            FlushPendingMesh();
                        }

                        pendingMesh = new PendingMeshBatch
                        {
                            Program = prog,
                            Depth = depthMode,
                            Texture = tex,
                            Sampler = samp,
                            Buffer = slice.Buffer,
                            Tint = tint,
                            UVRectX = uvX,
                            SunDir = sunDir,
                            FirstVertex = slice.FirstVertex,
                            VertexCount = slice.VertexCount,
                        };
                    }
                }
            }

            if (pendingMesh is not null)
            {
                FlushPendingMesh();
            }

            if (interleaveSurroundingsHere)
            {
                while (surCursor < _surroundingsDecorations.Count)
                {
                    LotScene.Sprite surSprite = _surroundingsDecorations[surCursor++];
                    if (surSprite.DepthTexture is not null)
                        hasDepthSprites = true;
                    DrawSprite(surSprite, primaryPass);
                }
                drewSurroundingsSprites = true;
            }

            if (!shadowDepthOnly && hasDepthSprites && scale >= 0.14f)
            {
                int edgeSurCursor = 0;
                for (int i = sliceStart; i < sliceEnd; i++)
                {
                    SceneDrawItem item = _drawItems[i];
                    if (interleaveSurroundingsHere)
                    {
                        float curDepth = ItemSortDepth(item);
                        while (edgeSurCursor < _surroundingsDecorations.Count && (_surroundingsDecorations[edgeSurCursor].Depth ?? 0f) <= curDepth)
                        {
                            DrawSprite(_surroundingsDecorations[edgeSurCursor++], SpritePassMode.EdgeFringe);
                        }
                    }
                    if (item.IsSprite && (uint)item.Index < (uint)scene.Sprites.Count)
                    {
                        DrawSprite(scene.Sprites[item.Index], SpritePassMode.EdgeFringe);
                    }
                }
                if (interleaveSurroundingsHere)
                {
                    while (edgeSurCursor < _surroundingsDecorations.Count)
                    {
                        DrawSprite(_surroundingsDecorations[edgeSurCursor++], SpritePassMode.EdgeFringe);
                    }
                }
            }

            sliceStart = sliceEnd;
        }

        if (!drewSurroundingsShadows)
        {
            for (int s = 0; s < _surroundingsDecorations.Count; s++)
            {
                DrawFloorShadow(_surroundingsDecorations[s], forceShadow: true, opacity: surroundingsShadowOpacity);
            }
        }
        if (!drewSurroundingsSprites)
        {
            bool anyDepth = false;
            for (int d = 0; d < _surroundingsDecorations.Count; d++)
            {
                if (_surroundingsDecorations[d].DepthTexture is not null) anyDepth = true;
                DrawSprite(_surroundingsDecorations[d], primaryPass);
            }
            if (anyDepth && scale >= 0.14f)
            {
                for (int d = 0; d < _surroundingsDecorations.Count; d++)
                    DrawSprite(_surroundingsDecorations[d], SpritePassMode.EdgeFringe);
            }
        }

        if (shadowDepthOnly)
        {
            return;
        }

        DrawLevel2BuildGridIfNeeded();
        DrawFloorBrushIfNeeded();

        if (!deferTranslucentAvatars)
        {
            EncodeTranslucentAvatars(pass, command, canvas, sampleCount, clipScissor);
            currentPipeline = null;
            currentSingleSampler = null;
            currentDualSamplers = null;
            currentVertexBuffer = 0;
        }

        if (ShowsPlacement && _placementBuffer is not null)
        {
            Bind(GPUContext.Program.Placement, GPUContext.DepthMode.Flat);
            if (BindVertices(_placementBuffer))
            {
                Push(new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas));
                SDL_DrawGPUPrimitives(pass, (uint)_placementBuffer.Count, 1, 0, 0);
            }
        }

        void DrawGhost(PlacementPreview.GhostData ghost, IReadOnlyList<GPUTexture> textures, float opacity)
        {
            foreach (LotScene.Sprite sprite in ghost.Scene.Sprites)
            {
                int texture = sprite.Texture;
                var rect = new Vector4(sprite.X, sprite.Y, sprite.Width, sprite.Height);
                if (sprite.Image(zoom) is { } image)
                {
                    texture = image.Texture;
                    rect = new Vector4(sprite.X + image.X, sprite.Y + image.Y, image.Width, image.Height);
                }

                if ((uint)texture >= (uint)textures.Count || !BindTexture(textures[texture], artSampler))
                {
                    continue;
                }
                var quad = new Quad(
                    new Vector4(origin.X + (ghost.X + rect.X) * scale, origin.Y + (ghost.Y + rect.Y) * scale, rect.Z * scale, rect.W * scale),
                    canvas,
                    sprite.Flip,
                    opacity)
                {
                    DepthInterval = new Vector4(0f, 0f, 0f, AntiAliasedSprites ? 1f : 0f),
                };
                Push(in quad);
                SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
            }
        }

        if (ShowsGhost && _placementGhost is { } placementGhost && _ghostTextures.Count == placementGhost.Scene.Textures.Count)
        {
            Bind(GPUContext.Program.Ghost, GPUContext.DepthMode.Flat);
            DrawGhost(placementGhost, _ghostTextures, 0.6f);
        }

        if (ShowsPlacement && _upperPlacementBuffer is not null)
        {
            Bind(GPUContext.Program.Placement, GPUContext.DepthMode.Flat);
            if (BindVertices(_upperPlacementBuffer))
            {
                Push(new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas));
                SDL_DrawGPUPrimitives(pass, (uint)_upperPlacementBuffer.Count, 1, 0, 0);
            }
        }

        if (ShowsBuildCursor && BuildCursor is { } cursorGhost && _buildCursorTextures.Count == cursorGhost.Scene.Textures.Count)
        {
            Bind(GPUContext.Program.Ghost, GPUContext.DepthMode.Flat);
            DrawGhost(cursorGhost, _buildCursorTextures, 1f);
        }
    }

    private static bool IsPostAmbientOverlaySprite(LotScene.Sprite sprite) =>
        sprite.HideAtFarZoom == true && sprite.Room is null && sprite.DepthTexture is null;

    private unsafe void EncodePostAmbientOverlaySprites(
        nint pass,
        nint command,
        SimsSDL.Core.SceneViewport viewport,
        Vector2 canvas,
        int sampleCount)
    {
        if (Scene is not { } scene || _drawItems.Count == 0)
        {
            return;
        }

        Vector2 origin = viewport.Origin;
        float scale = viewport.Scale;
        LotZoom zoom = Zoom;

        if (scene.Meshes is { Count: > 0 } meshes)
        {
            nint meshPipeline = 0;
            nint meshTex = 0;
            nint meshBuf = 0;
            for (int i = 0; i < _drawItems.Count; i++)
            {
                SceneDrawItem item = _drawItems[i];
                if (item.IsSprite || (uint)item.Index >= (uint)meshes.Count || (uint)item.Index >= (uint)_meshSlices.Count)
                {
                    continue;
                }

                LotScene.Mesh mesh = meshes[item.Index];
                if (mesh.Indicator != true || IsTranslucentAvatarMesh(mesh) || _meshSlices[item.Index] is not { } slice)
                {
                    continue;
                }

                int meshTexIdx = mesh.TextureFor(zoom);
                if ((uint)meshTexIdx >= (uint)_sceneTextures.Count)
                {
                    continue;
                }

                GPUTexture tex = _sceneTextures[meshTexIdx];
                if (tex.Format == SDL_GPU_TEXTUREFORMAT_R8_UNORM || tex.Handle == nint.Zero || slice.Buffer.Handle == nint.Zero)
                {
                    continue;
                }

                GPUContext.Program prog = mesh.Unlit == true ? GPUContext.Program.Surface : GPUContext.Program.Avatar;
                nint nextPipeline = GPU.Pipeline(prog, GPUContext.DepthMode.Mesh, sampleCount);
                if (nextPipeline == 0)
                {
                    continue;
                }
                if (nextPipeline != meshPipeline)
                {
                    SDL_BindGPUGraphicsPipeline(pass, nextPipeline);
                    meshPipeline = nextPipeline;
                }

                if (tex.Handle != meshTex)
                {
                    var binding = new SDL_GPUTextureSamplerBinding
                    {
                        texture = tex.Handle,
                        sampler = GPU.AnisoSampler,
                    };
                    SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1);
                    meshTex = tex.Handle;
                }

                nint bufHandle = slice.Buffer.Handle;
                if (bufHandle != meshBuf)
                {
                    SDL_BindGPUVertexStorageBuffers(pass, 0, &bufHandle, 1);
                    meshBuf = bufHandle;
                }

                Vector4 tint = Vector4.One;
                if (mesh.Tint is { Count: 4 } meshTint)
                {
                    tint *= new Vector4(meshTint[0], meshTint[1], meshTint[2], meshTint[3]);
                }

                var transform = new Quad(new Vector4(origin.X, origin.Y, scale, scale), canvas)
                {
                    Tint = tint,
                    DepthInterval = new Vector4(BitConverter.UInt32BitsToSingle(slice.FirstVertex), 0f, 0f, 0f),
                    UvRect = new Vector4(! (mesh.Unlit == true) && CharacterDetail == 0 ? 1f : 0f, 0f, 0f, 0f),
                };
                SDL_PushGPUVertexUniformData(command, 0, (nint)(&transform), (uint)sizeof(Quad));
                SDL_DrawGPUPrimitives(pass, slice.VertexCount, 1, 0, 0);
            }
        }

        if (zoom == LotZoom.Far)
        {
            return;
        }

        nint pipeline = 0;
        nint lastTex = 0;
        nint sampler = AntiAliasedSprites ? GPU.Sampler : GPU.PixelSampler;
        for (int i = 0; i < _drawItems.Count; i++)
        {
            SceneDrawItem item = _drawItems[i];
            if (!item.IsSprite || (uint)item.Index >= (uint)scene.Sprites.Count)
            {
                continue;
            }

            LotScene.Sprite sprite = scene.Sprites[item.Index];
            if (!IsPostAmbientOverlaySprite(sprite))
            {
                continue;
            }

            int texture = sprite.Texture;
            var rect = new Vector4(sprite.X, sprite.Y, sprite.Width, sprite.Height);
            if (sprite.Image(zoom) is { } image)
            {
                texture = image.Texture;
                rect = new Vector4(sprite.X + image.X, sprite.Y + image.Y, image.Width, image.Height);
            }

            if ((uint)texture >= (uint)_sceneTextures.Count)
            {
                continue;
            }

            GPUTexture colorTex = _sceneTextures[texture];
            if (colorTex.Format == SDL_GPU_TEXTUREFORMAT_R8_UNORM)
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

            if (pipeline == 0)
            {
                pipeline = GPU.Pipeline(GPUContext.Program.Sprite, GPUContext.DepthMode.Flat, sampleCount);
                if (pipeline == 0)
                {
                    return;
                }
                SDL_BindGPUGraphicsPipeline(pass, pipeline);
            }

            if (colorTex.Handle != lastTex)
            {
                var binding = new SDL_GPUTextureSamplerBinding
                {
                    texture = colorTex.Handle,
                    sampler = sampler,
                };
                SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1);
                lastTex = colorTex.Handle;
            }

            var quad = new Quad(
                new Vector4(origin.X + rect.X * scale, origin.Y + rect.Y * scale, rect.Z * scale, rect.W * scale),
                canvas,
                sprite.Flip)
            {
                DepthInterval = new Vector4(0f, 0f, 8.0f / 31.0f, AntiAliasedSprites ? 1f : 0f),
                Tint = Vector4.One,
            };
            SDL_PushGPUVertexUniformData(command, 0, (nint)(&quad), (uint)sizeof(Quad));
            SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0);
        }
    }
}
