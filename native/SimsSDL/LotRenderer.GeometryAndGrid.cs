using System.Numerics;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using SimsSDL.UI;

namespace SimsSDL;

public sealed partial class LotRenderer
{

    private void MakeCombinedDynamicMeshes(IReadOnlyList<LotScene.Mesh> meshes, List<MeshSlice?> slices)
    {
        if (meshes.Count == 0)
        {
            return;
        }

        int totalVertices = 0;
        for (int i = 0; i < meshes.Count; i++)
        {
            totalVertices += meshes[i].Vertices.Count;
        }

        if (totalVertices == 0)
        {
            for (int i = 0; i < meshes.Count; i++)
            {
                slices.Add(null);
            }
            return;
        }

        if (_dynamicVertexScratch.Length < totalVertices)
        {
            _dynamicVertexScratch = new AvatarVertex[Math.Max(totalVertices * 2, 4096)];
        }

        if (slices.Capacity < meshes.Count)
        {
            slices.Capacity = meshes.Count;
        }

        int writePos = 0;
        int slot = _dynamicMeshRingSlot;
        _dynamicMeshRingSlot = (_dynamicMeshRingSlot + 1) % _dynamicMeshRing.Length;

        long neededBytes = (long)totalVertices * Marshal.SizeOf<AvatarVertex>();
        GPUBuffer? ring = _dynamicMeshRing[slot];
        if (ring is null || ring.ByteSize < neededBytes)
        {
            Retire(ring);
            ring = GPU.MakeStorageBufferCapacity<AvatarVertex>(Math.Max(totalVertices * 2, 4096));
            _dynamicMeshRing[slot] = ring;
        }

        for (int i = 0; i < meshes.Count; i++)
        {
            IReadOnlyList<LotScene.MeshVertex> verts = meshes[i].Vertices;
            if (verts.Count == 0)
            {
                slices.Add(null);
                continue;
            }

            uint first = (uint)writePos;
            for (int vi = 0; vi < verts.Count; vi++)
            {
                LotScene.MeshVertex v = verts[vi];
                _dynamicVertexScratch[writePos++] = new AvatarVertex
                {
                    Position = new Vector4(v.X, v.Y, v.Z, 1f),
                    Uv = new Vector2(v.U, v.V),
                    Normal = new Vector4(v.NX, v.NY, v.NZ, 0f),
                };
            }

            slices.Add(new MeshSlice(ring, first, (uint)verts.Count));
        }

        GPU.UploadIntoBuffer<AvatarVertex>(ring, _dynamicVertexScratch.AsSpan(0, totalVertices));
    }

    private List<MeshSlice?> MakeCombinedMeshes(IReadOnlyList<LotScene.Mesh> meshes, IReadOnlyList<int>? order = null)
    {
        if (meshes.Count == 0)
        {
            return [];
        }

        int indexCount = order?.Count ?? meshes.Count;
        int totalVertices = 0;
        for (int i = 0; i < indexCount; i++)
        {
            int idx = order is not null ? order[i] : i;
            totalVertices += meshes[idx].Vertices.Count;
        }

        if (totalVertices == 0)
        {
            return Enumerable.Repeat<MeshSlice?>(null, meshes.Count).ToList();
        }

        var combined = new AvatarVertex[totalVertices];
        var ranges = new (uint First, uint Count)?[meshes.Count];
        int writePos = 0;
        for (int i = 0; i < indexCount; i++)
        {
            int idx = order is not null ? order[i] : i;
            IReadOnlyList<LotScene.MeshVertex> verts = meshes[idx].Vertices;
            if (verts.Count == 0)
            {
                continue;
            }

            uint first = (uint)writePos;
            for (int vi = 0; vi < verts.Count; vi++)
            {
                LotScene.MeshVertex v = verts[vi];
                combined[writePos++] = new AvatarVertex
                {
                    Position = new Vector4(v.X, v.Y, v.Z, 1f),
                    Uv = new Vector2(v.U, v.V),
                    Normal = new Vector4(v.NX, v.NY, v.NZ, 0f),
                };
            }

            ranges[idx] = (first, (uint)verts.Count);
        }

        GPUBuffer? buffer = GPU.MakeStorageBuffer(combined);
        if (buffer is null)
        {
            return Enumerable.Repeat<MeshSlice?>(null, meshes.Count).ToList();
        }

        List<MeshSlice?> slices = new(meshes.Count);
        foreach (var range in ranges)
        {
            slices.Add(range is { } r ? new MeshSlice(buffer, r.First, r.Count) : null);
        }

        return slices;
    }

    private GPUBuffer? MakeTerrain(LotScene scene, IReadOnlyList<LotScene.TerrainVertex>? vertices = null, float[]? depths = null)
    {
        // Terrain shade ramps are blended in sRGB before converting to linear color.
        static float Unit(byte component) => component / 255f;

        IReadOnlyList<LotScene.TerrainVertex> source = vertices ?? scene.TerrainVertices ?? [];
        if (source.Count == 0)
        {
            return null;
        }

        float[]? groundDepth = depths ?? (vertices is null ? TerrainDepth(scene) : null);
        var buffer = new TerrainVertex[source.Count];
        for (int index = 0; index < source.Count; index++)
        {
            LotScene.TerrainVertex vertex = source[index];
            var light = new Vector4(Unit(vertex.R), Unit(vertex.G), Unit(vertex.B), 1f);
            Vector4 dark = vertex.DR is byte dr
                ? new Vector4(Unit(dr), Unit(vertex.DG ?? 0), Unit(vertex.DB ?? 0), 1f)
                : light * new Vector4(0.2f, 0.45f, 0.15f, 1f);
            float depth = groundDepth is not null && index < groundDepth.Length ? groundDepth[index] : 1f;
            buffer[index] = new TerrainVertex
            {
                Position = new Vector2(vertex.X, vertex.Y),
                Grass = new Vector2(Unit(vertex.Grass ?? 0), depth),
                Color = light,
                Dark = dark,
            };
        }

        return GPU.MakeStorageBuffer(buffer);
    }

    // Ground depth 0.9 - 0.003*(x+y) matches standing sprite bases and shader depth reconstruction.
    private static float[]? TerrainDepth(LotScene scene)
    {
        if (scene.LotWidth is not int width || scene.LotHeight is not int height ||
            scene.TerrainVertices is not { } vertices || vertices.Count != width * height * 6)
        {
            return null;
        }

        int orientation = ((scene.CameraOrientation ?? 0) % 4 + 4) % 4;
        float CameraSum(int x, int y) => orientation switch
        {
            0 => x + y,
            1 => height - y + x,
            2 => width - x + height - y,
            _ => y + width - x,
        };

        Span<(int DX, int DY)> corners = [(0, 0), (1, 0), (1, 1), (1, 1), (0, 1), (0, 0)];
        var depths = new float[vertices.Count];
        for (int index = 0; index < vertices.Count; index++)
        {
            int tile = index / 6;
            (int dx, int dy) = corners[index % 6];
            float sum = CameraSum(tile % width + dx, tile / width + dy);
            depths[index] = MathF.Min(0.999f, MathF.Max(0.001f, 0.9f - 0.003f * sum));
        }

        return depths;
    }

    public void SetZoom(LotZoom level, bool instant = false)
    {
        if (level == _zoom && (!instant || !IsZoomInterpolating))
        {
            return;
        }

        if (instant)
        {
            Vector2 rescaled = SimsSDL.Core.SceneViewport.RescaledPan(_pan, _visualZoomFactor, level.Factor());
            _zoom = level;
            _visualZoomFactor = level.Factor();
            Pan = rescaled;
            return;
        }

        _zoom = level;
    }

    public void StepSmoothZoom(double dtSeconds, bool instant = false)
    {
        float target = TargetZoomFactor;
        if (MathF.Abs(target - _visualZoomFactor) <= 1e-5f)
        {
            return;
        }

        float prev = _visualZoomFactor;
        float next = instant
            ? target
            : prev + (target - prev) * (1f - MathF.Exp(-18f * (float)Math.Clamp(dtSeconds, 0.0, 0.1)));
        if (MathF.Abs(target - next) < 0.001f)
        {
            next = target;
        }

        _visualZoomFactor = next;
        Vector2 rescaled = SimsSDL.Core.SceneViewport.RescaledPan(_pan, prev, next);
        _pan = Scene is not null
            ? SimsSDL.Core.SceneViewport.ClampedPan(rescaled, Scene, MathF.Max(UIScale, 0.01f) * next)
            : rescaled;
    }

    private void UpdateAmbientMaps(Vector2 canvas, nint command)
    {
        if (Scene is null || !DrawsLot || !AmbientEnabled || Environment is null)
        {
            return;
        }

        float scale = MathF.Max(0.01f, UIScale * Zoom.Factor());
        float coverage = MathF.Min(12f, MathF.Ceiling(canvas.X / (128f * scale) + canvas.Y / (64f * scale)) + 8f);
        if (coverage > _heightMargin)
        {
            _heightMargin = coverage;
            GPU.BatchingUploads(command, () =>
            {
                Retire(_indoorMask);
                _indoorMask = MakeIndoorMask(Scene);
                Retire(_overheadMap);
                _overheadMap = MakeOverheadMap(Scene);
                Retire(_voxelMap);
                _voxelMap = MakeVoxelMap(Scene);
            });
        }
    }

    private SimsSDL.Core.SceneViewport? Viewport(Vector2 canvas)
    {
        if (Scene is null)
        {
            return null;
        }

        return new SimsSDL.Core.SceneViewport(
            Scene,
            canvas,
            LiveMode && !SuppressControlPanelInset ? 100f * UIScale : 0f,
            _visualZoomFactor,
            UIScale,
            _pan,
            snapOriginToPixel: !IsZoomInterpolating);
    }

    public bool ContainsObject(int id) =>
        Scene is not null &&
        (Scene.Sprites.Any(s => s.ObjectID == id) || (Scene.Meshes?.Any(m => m.ObjectID == id) ?? false));

    public CGRect? ScreenBounds(int id, Vector2 canvas)
    {
        if (Scene is null || Viewport(canvas) is not { } viewport)
        {
            return null;
        }

        var low = new Vector2(float.PositiveInfinity);
        var high = new Vector2(float.NegativeInfinity);

        foreach (LotScene.Sprite sprite in Scene.Sprites)
        {
            if (sprite.ObjectID != id)
            {
                continue;
            }

            low = Vector2.Min(low, new Vector2(sprite.X, sprite.Y));
            high = Vector2.Max(high, new Vector2(sprite.X + sprite.Width, sprite.Y + sprite.Height));
        }

        if (Scene.Meshes is not null)
        {
            foreach (LotScene.Mesh mesh in Scene.Meshes)
            {
                if (mesh.ObjectID != id)
                {
                    continue;
                }

                foreach (LotScene.MeshVertex vertex in mesh.Vertices)
                {
                    var p = new Vector2(vertex.X, vertex.Y);
                    low = Vector2.Min(low, p);
                    high = Vector2.Max(high, p);
                }
            }
        }

        if (!(low.X <= high.X))
        {
            return null;
        }

        Vector2 origin = viewport.Origin + low * viewport.Scale;
        Vector2 size = (high - low) * viewport.Scale;
        return new CGRect(origin.X, origin.Y, size.X, size.Y);
    }

    public FloorTileHit? FloorHitAt(Vector2 point, Vector2 canvas)
    {
        if (PickScenePoint(point, canvas) is not { } location)
        {
            return null;
        }

        return _groundPicker?.Hit(location);
    }

    public SimsSDL.Core.GroundTile? GroundTileAt(Vector2 point, Vector2 canvas) => FloorHitAt(point, canvas)?.Tile;

    public Vector2? ScreenPoint(int x, int y, Vector2 canvas)
    {
        if (Scene is { LotWidth: int width, LotHeight: int height, ConstructionVertices: { } vertices } &&
            x >= 0 && x < width && y >= 0 && y < height &&
            vertices.Count == width * height * 6 &&
            Viewport(canvas) is { } viewport)
        {
            int start = (y * width + x) * 6;
            LotScene.TerrainVertex a = vertices[start];
            LotScene.TerrainVertex c = vertices[start + 2];
            Vector2 center = new((a.X + c.X) * 0.5f, (a.Y + c.Y) * 0.5f);
            if (float.IsFinite(center.X) && float.IsFinite(center.Y))
            {
                return viewport.Origin + center * viewport.Scale;
            }
        }

        return ScreenPoint(x + 0.5f, y + 0.5f, canvas);
    }

    public Vector2? ScreenPoint(float x, float y, Vector2 canvas)
    {
        if (Scene is null || Scene.LotWidth is not int width || Scene.LotHeight is not int height ||
            Viewport(canvas) is not { } viewport || !float.IsFinite(x) || !float.IsFinite(y))
        {
            return null;
        }

        var lotSize = new Vector2(width, height);
        Vector2 origin;
        if (Scene.OriginX is float originX && Scene.OriginY is float originY)
        {
            origin = new Vector2(originX, originY);
        }
        else if (Scene.TerrainVertices is { Count: > 0 } vertices)
        {
            LotScene.TerrainVertex first = vertices[0];
            Vector2 corner = Scene.Camera switch
            {
                SimsSDL.Core.LotCamera.TopLeft => Vector2.Zero,
                SimsSDL.Core.LotCamera.TopRight => new Vector2(height, 0f),
                SimsSDL.Core.LotCamera.BottomRight => new Vector2(width, height),
                _ => new Vector2(0f, width),
            };
            origin = Scene.Camera.ProjectedPoint(corner, lotSize) - new Vector2(first.X, first.Y);
        }
        else
        {
            return null;
        }

        Vector2 projected = Scene.Camera.ProjectedPoint(new Vector2(x, y), lotSize);
        return viewport.Origin + (projected - origin) * viewport.Scale;
    }

    public Vector2? CentreGroundTile(int x, int y, Vector2 canvas)
    {
        if (ScreenPoint(x, y, canvas) is not { } point || Viewport(canvas) is not { } viewport)
        {
            return null;
        }

        Pan += viewport.Size / 2f - point;
        return ScreenPoint(x, y, canvas);
    }

    public string GroundProjectionInfo(Vector2 canvas)
    {
        if (Scene is null || Viewport(canvas) is not { } viewport)
        {
            return "scene or viewport missing";
        }

        string originX = Scene.OriginX?.ToString() ?? "nil";
        string originY = Scene.OriginY?.ToString() ?? "nil";
        return $"lot {Scene.LotWidth ?? -1}x{Scene.LotHeight ?? -1}, camera {(int)Scene.Camera}, origin {originX},{originY}, viewport {viewport.Size.X}x{viewport.Size.Y}";
    }

    public SimsSDL.Core.LotVertex? LotVertexAt(Vector2 point, Vector2 canvas)
    {
        if (Scene is null || LotVertexPicker.Create(Scene) is not { } picker ||
            PickScenePoint(point, canvas) is not { } location)
        {
            return null;
        }

        return picker.Vertex(location);
    }

    public SimsSDL.Core.SceneViewport? SceneViewport(Vector2 canvas) => Viewport(canvas);

    public void SetBuildableAreas(BuildableArea? level1, BuildableArea? level2)
    {
        if (Equals(_buildableLevel1, level1) && Equals(_buildableLevel2, level2))
        {
            return;
        }

        _buildableLevel1 = level1;
        _buildableLevel2 = level2;
        _buildGridDirty = true;
    }

    private void RebuildBuildGridBuffers()
    {
        Retire(_buildGridLevel1Buffer);
        _buildGridLevel1Buffer = null;
        Retire(_buildGridLevel2Buffer);
        _buildGridLevel2Buffer = null;

        if (Scene is not { } scene ||
            scene.LotWidth is not int width || scene.LotHeight is not int height ||
            scene.TerrainVertices is not { } terrain || terrain.Count != width * height * 6)
        {
            return;
        }

        IReadOnlyList<short>? heights = scene.TerrainHeights;
        int heightStride = width + 1;
        bool hasHeights = heights is not null && heights.Count == heightStride * (height + 1);

        var level1 = new List<TerrainVertex>(width * height * 12);
        var flatGridColor = new Vector4(0f, 0f, 0f, 0.38f);
        var slopedGridColor = new Vector4(0f, 0f, 0f, 0.20f);
        const float gridHalfWidth = 0.45f;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (_buildableLevel1 is not null && !_buildableLevel1.Contains(x, y))
                {
                    continue;
                }

                int start = (y * width + x) * 6;
                var top = new Vector2(terrain[start + 0].X, terrain[start + 0].Y);
                var right = new Vector2(terrain[start + 1].X, terrain[start + 1].Y);
                var bottom = new Vector2(terrain[start + 2].X, terrain[start + 2].Y);
                var left = new Vector2(terrain[start + 4].X, terrain[start + 4].Y);
                if (Vector2.DistanceSquared(top, bottom) <= 1f)
                {
                    continue;
                }

                bool flat = true;
                if (hasHeights)
                {
                    int h00 = heights![y * heightStride + x];
                    flat = heights[y * heightStride + x + 1] == h00 &&
                           heights[(y + 1) * heightStride + x] == h00 &&
                           heights[(y + 1) * heightStride + x + 1] == h00;
                }

                Vector4 lineColor = flat ? flatGridColor : slopedGridColor;
                AppendEdgeQuad(level1, top, left, gridHalfWidth, lineColor);
                AppendEdgeQuad(level1, top, right, gridHalfWidth, lineColor);

                bool closeRight = _buildableLevel1 is not null ? !_buildableLevel1.Contains(x + 1, y) : x == width - 1;
                bool closeBottom = _buildableLevel1 is not null ? !_buildableLevel1.Contains(x, y + 1) : y == height - 1;
                if (closeRight)
                {
                    AppendEdgeQuad(level1, right, bottom, gridHalfWidth, lineColor);
                }

                if (closeBottom)
                {
                    AppendEdgeQuad(level1, left, bottom, gridHalfWidth, lineColor);
                }
            }
        }

        if (level1.Count > 0)
        {
            _buildGridLevel1Buffer = GPU.MakeStorageBuffer(level1.ToArray());
        }

        if (scene.SelectedLevel >= 2 && _buildableLevel2 is not null)
        {
            var hasFloor2 = new bool[width * height];
            if (scene.Meshes is not null)
            {
                foreach (LotScene.Mesh mesh in scene.Meshes)
                {
                    if (mesh.Floor is { } floor && (floor.Level ?? 1) == 2 &&
                        floor.X >= 0 && floor.X < width && floor.Y >= 0 && floor.Y < height)
                    {
                        hasFloor2[floor.Y * width + floor.X] = true;
                    }
                }
            }

            var level2 = new List<TerrainVertex>();
            var checkerDark = new Vector4(0f, 0f, 0f, 0.16f);
            var checkerLight = new Vector4(0.06f, 0.06f, 0.06f, 0.10f);
            var bevelWhite = new Vector4(0.85f, 0.85f, 0.85f, 0.85f);
            var bevelBlack = new Vector4(0f, 0f, 0f, 0.75f);
            float lift = PlacementPreview.StoryLiftPerLevel;

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    if (!_buildableLevel2.Contains(x, y) || hasFloor2[y * width + x])
                    {
                        continue;
                    }

                    int start = (y * width + x) * 6;
                    var top = new Vector2(terrain[start + 0].X, terrain[start + 0].Y - lift);
                    var right = new Vector2(terrain[start + 1].X, terrain[start + 1].Y - lift);
                    var bottom = new Vector2(terrain[start + 2].X, terrain[start + 2].Y - lift);
                    var left = new Vector2(terrain[start + 4].X, terrain[start + 4].Y - lift);
                    if (Vector2.DistanceSquared(top, bottom) <= 1f)
                    {
                        continue;
                    }

                    Vector4 fill = ((x + y) & 1) == 0 ? checkerDark : checkerLight;
                    level2.Add(new TerrainVertex { Position = top, Color = fill });
                    level2.Add(new TerrainVertex { Position = right, Color = fill });
                    level2.Add(new TerrainVertex { Position = bottom, Color = fill });
                    level2.Add(new TerrainVertex { Position = bottom, Color = fill });
                    level2.Add(new TerrainVertex { Position = left, Color = fill });
                    level2.Add(new TerrainVertex { Position = top, Color = fill });

                    AppendEdgeQuad(level2, top, left, gridHalfWidth, bevelWhite);
                    AppendEdgeQuad(level2, top, right, gridHalfWidth, bevelWhite);
                    AppendEdgeQuad(level2, right, bottom, gridHalfWidth, bevelBlack);
                    AppendEdgeQuad(level2, left, bottom, gridHalfWidth, bevelBlack);
                }
            }

            if (level2.Count > 0)
            {
                _buildGridLevel2Buffer = GPU.MakeStorageBuffer(level2.ToArray());
            }
        }
    }

    private static void AppendEdgeQuad(List<TerrainVertex> vertices, Vector2 a, Vector2 b, float halfWidth, Vector4 color)
    {
        Vector2 delta = b - a;
        float lenSq = delta.LengthSquared();
        if (lenSq < 1e-4f)
        {
            return;
        }

        float invLen = halfWidth / MathF.Sqrt(lenSq);
        var n = new Vector2(-delta.Y * invLen, delta.X * invLen);
        Vector2 a0 = a - n;
        Vector2 a1 = a + n;
        Vector2 b0 = b - n;
        Vector2 b1 = b + n;

        vertices.Add(new TerrainVertex { Position = a0, Color = color });
        vertices.Add(new TerrainVertex { Position = b0, Color = color });
        vertices.Add(new TerrainVertex { Position = b1, Color = color });
        vertices.Add(new TerrainVertex { Position = b1, Color = color });
        vertices.Add(new TerrainVertex { Position = a1, Color = color });
        vertices.Add(new TerrainVertex { Position = a0, Color = color });
    }

    private static void AppendDiamondOutline(
        List<TerrainVertex> vertices,
        Vector2 top,
        Vector2 right,
        Vector2 bottom,
        Vector2 left,
        float insetRatio,
        Vector4 color)
    {
        Vector2 center = (top + right + bottom + left) * 0.25f;
        Vector2 iTop = Vector2.Lerp(top, center, insetRatio);
        Vector2 iRight = Vector2.Lerp(right, center, insetRatio);
        Vector2 iBottom = Vector2.Lerp(bottom, center, insetRatio);
        Vector2 iLeft = Vector2.Lerp(left, center, insetRatio);

        static void AppendQuad(List<TerrainVertex> dst, Vector2 o0, Vector2 o1, Vector2 i1, Vector2 i0, Vector4 col)
        {
            dst.Add(new TerrainVertex { Position = o0, Color = col });
            dst.Add(new TerrainVertex { Position = o1, Color = col });
            dst.Add(new TerrainVertex { Position = i1, Color = col });
            dst.Add(new TerrainVertex { Position = i1, Color = col });
            dst.Add(new TerrainVertex { Position = i0, Color = col });
            dst.Add(new TerrainVertex { Position = o0, Color = col });
        }

        AppendQuad(vertices, top, right, iRight, iTop, color);
        AppendQuad(vertices, right, bottom, iBottom, iRight, color);
        AppendQuad(vertices, bottom, left, iLeft, iBottom, color);
        AppendQuad(vertices, left, top, iTop, iLeft, color);
    }

    private static void AppendUnplaceableSymbol(
        List<TerrainVertex> vertices,
        Vector2 top,
        Vector2 right,
        Vector2 bottom,
        Vector2 left,
        Vector4 color)
    {
        Vector2 center = (top + right + bottom + left) * 0.25f;
        const int segments = 16;
        const float outerRadius = 12.5f;
        const float innerRadius = 9.5f;

        for (int i = 0; i < segments; i++)
        {
            float a0 = i * (MathF.PI * 2f / segments);
            float a1 = (i + 1) * (MathF.PI * 2f / segments);
            var d0 = new Vector2(MathF.Cos(a0), MathF.Sin(a0));
            var d1 = new Vector2(MathF.Cos(a1), MathF.Sin(a1));

            Vector2 o0 = center + d0 * outerRadius;
            Vector2 o1 = center + d1 * outerRadius;
            Vector2 i0 = center + d0 * innerRadius;
            Vector2 i1 = center + d1 * innerRadius;

            vertices.Add(new TerrainVertex { Position = o0, Color = color });
            vertices.Add(new TerrainVertex { Position = o1, Color = color });
            vertices.Add(new TerrainVertex { Position = i1, Color = color });
            vertices.Add(new TerrainVertex { Position = i1, Color = color });
            vertices.Add(new TerrainVertex { Position = i0, Color = color });
            vertices.Add(new TerrainVertex { Position = o0, Color = color });
        }

        float slash = innerRadius * 0.78f;
        AppendEdgeQuad(
            vertices,
            center + new Vector2(-slash, -slash),
            center + new Vector2(slash, slash),
            1.6f,
            color);
    }

    private void SetPlacement(
        TerrainVertex[] vertices,
        PlacementPreview.GhostData? ghost = null,
        (int Width, int Height, bool Depth8, byte[] Pixels)[]? pixels = null,
        TerrainVertex[]? upperVertices = null,
        bool reuseGhostTextures = false)
    {
        _placementVertices = vertices;
        _upperPlacementVertices = upperVertices ?? [];
        _placementGhost = ghost;
        if (ghost is null)
        {
            _ghostPixels = null;
            RetireDistinctTextures(_ghostTextures);
            _ghostTextures = [];
            _ghostTextureKeys = [];
        }
        else if (!reuseGhostTextures)
        {
            _ghostPixels = pixels ?? [];
            RetireDistinctTextures(_ghostTextures);
            _ghostTextures = [];
            _ghostTextureKeys = ExtractTextureKeys(ghost.Scene.Textures);
        }
        Retire(_placementBuffer);
        _placementBuffer = null;
        Retire(_upperPlacementBuffer);
        _upperPlacementBuffer = null;
        _placementDirty = true;
        if (_floorBrushVertices.Length > 0 || _floorBrushBuffer is not null)
        {
            _floorBrushVertices = [];
            Retire(_floorBrushBuffer);
            _floorBrushBuffer = null;
            _floorBrushDirty = true;
        }
    }

    private static byte[] BleedFloorBitmap(SimsBitmap bitmap)
    {
        var bytes = (byte[])bitmap.Rgba.Clone();
        int width = bitmap.Width;
        int height = bitmap.Height;

        for (int i = 0; i + 3 < bytes.Length; i += 4)
        {
            if (bytes[i] == 255 && bytes[i + 1] == 0 && bytes[i + 2] == 255)
            {
                bytes[i + 3] = 0;
            }
        }

        int firstOpaqueRow = -1;
        int lastOpaqueRow = -1;
        for (int py = 0; py < height; py++)
        {
            int rowStart = py * width;
            int firstX = -1;
            int lastX = -1;
            for (int px = 0; px < width; px++)
            {
                if (bytes[(rowStart + px) * 4 + 3] == 0)
                {
                    continue;
                }

                if (firstX < 0)
                {
                    firstX = px;
                }

                lastX = px;
            }

            if (firstX < 0)
            {
                continue;
            }

            if (firstOpaqueRow < 0)
            {
                firstOpaqueRow = py;
            }

            lastOpaqueRow = py;

            int leftAt = (rowStart + firstX) * 4;
            for (int px = 0; px < firstX; px++)
            {
                int dst = (rowStart + px) * 4;
                bytes[dst] = bytes[leftAt];
                bytes[dst + 1] = bytes[leftAt + 1];
                bytes[dst + 2] = bytes[leftAt + 2];
                bytes[dst + 3] = 255;
            }

            int rightAt = (rowStart + lastX) * 4;
            for (int px = lastX + 1; px < width; px++)
            {
                int dst = (rowStart + px) * 4;
                bytes[dst] = bytes[rightAt];
                bytes[dst + 1] = bytes[rightAt + 1];
                bytes[dst + 2] = bytes[rightAt + 2];
                bytes[dst + 3] = 255;
            }
        }

        if (firstOpaqueRow > 0)
        {
            int srcStart = firstOpaqueRow * width * 4;
            int rowBytes = width * 4;
            for (int py = 0; py < firstOpaqueRow; py++)
            {
                Buffer.BlockCopy(bytes, srcStart, bytes, py * rowBytes, rowBytes);
            }
        }

        if (lastOpaqueRow >= 0 && lastOpaqueRow < height - 1)
        {
            int srcStart = lastOpaqueRow * width * 4;
            int rowBytes = width * 4;
            for (int py = lastOpaqueRow + 1; py < height; py++)
            {
                Buffer.BlockCopy(bytes, srcStart, bytes, py * rowBytes, rowBytes);
            }
        }

        return SpritePixels.PremultipliedSRGB(bytes);
    }

    public void UpdateWallBrush(WallBrushSelection? line)
    {
        if (line is null || Scene is null)
        {
            SetPlacement([]);
            return;
        }

        Vector4 color = line.Deleting ? new Vector4(0.35f, 0.12f, 0.02f, 0.4f) : new Vector4(0.06f, 0.12f, 0.32f, 0.4f);
        List<LotScene.TerrainVertex> geometry = line.Geometry(Scene);
        var vertices = new TerrainVertex[geometry.Count];
        for (int i = 0; i < geometry.Count; i++)
        {
            vertices[i] = new TerrainVertex
            {
                Position = new Vector2(geometry[i].X, geometry[i].Y),
                Color = color,
            };
        }

        SetPlacement(vertices);
    }

    public void UpdateFloorBrush(FloorBrushSelection? rectangle, bool deleting = false, string? textureFile = null)
    {
        if (rectangle is null || Scene is null)
        {
            SetPlacement([]);
            return;
        }

        if (!deleting && !rectangle.Water && textureFile is not null && SceneRoot is not null)
        {
            string root = ResolveRealPath(SceneRoot);
            string file = ResolveRealPath(Path.Combine(
                root,
                textureFile.Replace('\\', Path.DirectorySeparatorChar).Replace('/', Path.DirectorySeparatorChar)));
            string? fileDir = Path.GetDirectoryName(file);
            StringComparison cmp = OperatingSystem.IsWindows() ? StringComparison.OrdinalIgnoreCase : StringComparison.Ordinal;
            if (fileDir is not null && string.Equals(Path.TrimEndingDirectorySeparator(fileDir), root, cmp) && File.Exists(file))
            {
                List<(LotScene.TerrainVertex Vertex, Vector2 UV)> textured = rectangle.TexturedGeometry(Scene);
                SetPlacement([]);
                if (textured.Count == 0)
                {
                    return;
                }

                var brushVerts = new AvatarVertex[textured.Count];
                for (int i = 0; i < textured.Count; i++)
                {
                    var item = textured[i];
                    brushVerts[i] = new AvatarVertex
                    {
                        Position = new Vector4(item.Vertex.X, item.Vertex.Y, 1f, 1f),
                        Uv = item.UV,
                        Normal = new Vector4(0f, 1f, 0f, 0f),
                    };
                }

                _floorBrushVertices = brushVerts;
                if (!string.Equals(_floorBrushTextureKey, file, cmp) || (_floorBrushTexture is null && _floorBrushPixels is null))
                {
                    var bitmap = new SimsBitmap(File.ReadAllBytes(file));
                    _floorBrushPixels = (bitmap.Width, bitmap.Height, false, BleedFloorBitmap(bitmap));
                    _floorBrushTextureKey = file;
                }

                _floorBrushDirty = true;
                return;
            }
        }

        Vector4 color = deleting ? new Vector4(0.35f, 0.12f, 0.02f, 0.4f) : new Vector4(0.06f, 0.12f, 0.32f, 0.4f);
        List<LotScene.TerrainVertex> geometry = rectangle.Geometry(Scene);
        var vertices = new TerrainVertex[geometry.Count];
        for (int i = 0; i < geometry.Count; i++)
        {
            vertices[i] = new TerrainVertex
            {
                Position = new Vector2(geometry[i].X, geometry[i].Y),
                Color = color,
            };
        }

        SetPlacement(vertices);
    }

    public void UpdatePlacement(PlacementPreview? preview)
    {
        if (preview is null || Scene is null || SceneRoot is null)
        {
            PlacementIsValid = null;
            SetPlacement([]);
            return;
        }

        PlacementIsValid = preview.Valid;
        List<PlacementPreview.TileDiamond> diamonds = preview.TileDiamonds(Scene);
        var lower = new List<TerrainVertex>(diamonds.Count * 24);
        var upper = new List<TerrainVertex>();
        var yellow = new Vector4(1f, 1f, 0f, 1f);
        var red = new Vector4(1f, 0f, 0f, 1f);
        int selectedLevel = Scene.SelectedLevel;

        foreach (PlacementPreview.TileDiamond diamond in diamonds)
        {
            List<TerrainVertex> target = diamond.Level > selectedLevel ? upper : lower;
            AppendDiamondOutline(target, diamond.Top, diamond.Right, diamond.Bottom, diamond.Left, 0.14f, yellow);
            if (!preview.Valid)
            {
                AppendUnplaceableSymbol(target, diamond.Top, diamond.Right, diamond.Bottom, diamond.Left, red);
            }
        }

        TerrainVertex[] lowerVertices = lower.ToArray();
        TerrainVertex[]? upperVertices = upper.Count > 0 ? upper.ToArray() : null;

        if (preview.Ghost is not { } ghost)
        {
            SetPlacement(lowerVertices, upperVertices: upperVertices);
            return;
        }

        if (TextureKeysEqual(_ghostTextureKeys, ghost.Scene.Textures)
            && (_ghostPixels is not null || _ghostTextures.Count == ghost.Scene.Textures.Count))
        {
            SetPlacement(lowerVertices, ghost, upperVertices: upperVertices, reuseGhostTextures: true);
            return;
        }

        List<byte[]> data = LotScene.ReadPixels(ghost.Scene.Textures, ResolveRealPath(SceneRoot));
        var prepared = new (int Width, int Height, bool Depth8, byte[] Pixels)[ghost.Scene.Textures.Count];
        for (int i = 0; i < ghost.Scene.Textures.Count; i++)
        {
            prepared[i] = PrepareUpload(ghost.Scene.Textures[i], data[i]);
        }

        SetPlacement(lowerVertices, ghost, prepared, upperVertices);
    }

    private static bool TextureKeysEqual(string[] currentKeys, IReadOnlyList<LotScene.Texture> textures)
    {
        if (currentKeys.Length != textures.Count) return false;
        for (int i = 0; i < currentKeys.Length; i++)
        {
            if (!string.Equals(currentKeys[i], textures[i].File, StringComparison.Ordinal))
                return false;
        }
        return true;
    }

    private static string[] ExtractTextureKeys(IReadOnlyList<LotScene.Texture> textures)
    {
        var keys = new string[textures.Count];
        for (int i = 0; i < textures.Count; i++)
        {
            keys[i] = textures[i].File;
        }
        return keys;
    }

    private void RebuildWallPaintLookup(PlacementPreview.GhostData ghost)
    {
        _wallPaintByWall.Clear();
        foreach (LotScene.Sprite candidate in ghost.Scene.Sprites)
        {
            if (candidate.Wall is { } wall)
            {
                _wallPaintByWall.TryAdd(wall, candidate);
            }
        }
    }

    public void UpdateBuildCursor(PlacementPreview.GhostData? ghost)
    {
        if (ghost is null || SceneRoot is null)
        {
            BuildCursor = null;
            _buildCursorPixels = null;
            RetireDistinctTextures(_buildCursorTextures);
            _buildCursorTextures = [];
            _buildCursorTextureKeys = [];
            return;
        }

        ghost.Validate();
        if (_buildCursorPixels is null
            && _buildCursorTextures.Count == ghost.Scene.Textures.Count
            && TextureKeysEqual(_buildCursorTextureKeys, ghost.Scene.Textures))
        {
            BuildCursor = ghost;
            return;
        }

        List<byte[]> data = LotScene.ReadPixels(ghost.Scene.Textures, ResolveRealPath(SceneRoot));
        var prepared = new (int Width, int Height, bool Depth8, byte[] Pixels)[ghost.Scene.Textures.Count];
        for (int i = 0; i < ghost.Scene.Textures.Count; i++)
        {
            prepared[i] = PrepareUpload(ghost.Scene.Textures[i], data[i]);
        }

        _buildCursorPixels = prepared;
        RetireDistinctTextures(_buildCursorTextures);
        _buildCursorTextures = [];
        _buildCursorTextureKeys = ExtractTextureKeys(ghost.Scene.Textures);
        BuildCursor = ghost;
    }

    public void UpdateWallPaintPreview(PlacementPreview.GhostData? ghost)
    {
        if (ghost is null || SceneRoot is null)
        {
            WallPaintPreview = null;
            _wallPaintPixels = null;
            RetireDistinctTextures(_wallPaintTextures);
            _wallPaintTextures = [];
            _wallPaintTextureKeys = [];
            _wallPaintByWall.Clear();
            return;
        }

        ghost.Validate(wallSurface: true);
        if (_wallPaintPixels is null
            && _wallPaintTextures.Count == ghost.Scene.Textures.Count
            && TextureKeysEqual(_wallPaintTextureKeys, ghost.Scene.Textures))
        {
            WallPaintPreview = ghost;
            RebuildWallPaintLookup(ghost);
            return;
        }

        List<byte[]> data = LotScene.ReadPixels(ghost.Scene.Textures, ResolveRealPath(SceneRoot));
        var prepared = new (int Width, int Height, bool Depth8, byte[] Pixels)[ghost.Scene.Textures.Count];
        for (int i = 0; i < ghost.Scene.Textures.Count; i++)
        {
            prepared[i] = PrepareUpload(ghost.Scene.Textures[i], data[i]);
        }

        _wallPaintPixels = prepared;
        RetireDistinctTextures(_wallPaintTextures);
        _wallPaintTextures = [];
        _wallPaintTextureKeys = ExtractTextureKeys(ghost.Scene.Textures);
        WallPaintPreview = ghost;
        RebuildWallPaintLookup(ghost);
    }

    public int? ObjectAt(Vector2 point, Vector2 canvas)
    {
        LotZoom zoom = EffectiveVisualZoom;
        if (_cachedObjectHit is { } cached &&
            cached.Point == point &&
            cached.Canvas == canvas &&
            cached.Zoom == zoom &&
            cached.VisualZoomFactor == _visualZoomFactor &&
            cached.Pan == _pan &&
            cached.Revision == _sceneRevision &&
            cached.Sequence == _animationSequence)
        {
            return cached.Result;
        }

        if (PickScenePoint(point, canvas) is not { } location)
        {
            return null;
        }

        int? hit = EnsurePicker()?.ObjectAt(location, zoom);
        _cachedObjectHit = new CachedObjectHit(point, canvas, zoom, _visualZoomFactor, _pan, _sceneRevision, _animationSequence, hit);
        return hit;
    }

    public LotScene.WallSide? WallAt(Vector2 point, Vector2 canvas)
    {
        LotZoom zoom = EffectiveVisualZoom;
        if (_cachedWallHit is { } cached &&
            cached.Point == point &&
            cached.Canvas == canvas &&
            cached.Zoom == zoom &&
            cached.VisualZoomFactor == _visualZoomFactor &&
            cached.Pan == _pan &&
            cached.Revision == _sceneRevision &&
            cached.Sequence == _animationSequence)
        {
            return cached.Result;
        }

        if (PickScenePoint(point, canvas) is not { } location)
        {
            return null;
        }

        LotScene.WallSide? hit = EnsurePicker()?.WallAt(location, zoom);
        _cachedWallHit = new CachedWallHit(point, canvas, zoom, _visualZoomFactor, _pan, _sceneRevision, _animationSequence, hit);
        return hit;
    }

    public void UpdateAppearancePreview(SimsSDL.Core.HouseholdAppearancePreview preview, IReadOnlyList<byte[]> pixels, int key = 0)
    {
        preview.Validate();
        if (pixels.Count != preview.Textures.Count)
        {
            throw new ContentError("Household preview texture data does not match its manifest");
        }

        var uploadBatch = new (int Width, int Height, bool Depth8, byte[] Pixels)[preview.Textures.Count];
        var mips = new bool[preview.Textures.Count];
        for (int i = 0; i < preview.Textures.Count; i++)
        {
            LotScene.Texture metadata = preview.Textures[i];
            uploadBatch[i] = (metadata.Width, metadata.Height, false, SpritePixels.PremultipliedSRGB(pixels[i]));
            mips[i] = true;
        }

        IReadOnlyList<GPUTexture> uploaded = GPU.UploadTextures(uploadBatch, mips);
        float minX = float.PositiveInfinity;
        float maxX = float.NegativeInfinity;
        float minY = float.PositiveInfinity;
        float maxY = float.NegativeInfinity;
        bool hasVertex = false;

        List<GPUTexture> meshTextures = new(preview.Meshes.Count);
        List<int> vertexCounts = new(preview.Meshes.Count);
        foreach (LotScene.Mesh mesh in preview.Meshes)
        {
            meshTextures.Add(uploaded[mesh.Texture]);
            vertexCounts.Add(mesh.Vertices.Count);
            foreach (LotScene.MeshVertex v in mesh.Vertices)
            {
                hasVertex = true;
                if (v.X < minX) minX = v.X;
                if (v.X > maxX) maxX = v.X;
                if (v.Y < minY) minY = v.Y;
                if (v.Y > maxY) maxY = v.Y;
            }
        }

        var bounds = hasVertex
            ? new CGRect(minX, minY, maxX - minX, maxY - minY)
            : new CGRect(0, 0, 1, 1);

        if (_previews.TryGetValue(key, out PreviewMeshes? existingPreview))
        {
            RetirePreview(existingPreview);
        }

        _previews[key] = new PreviewMeshes
        {
            Textures = meshTextures,
            Buffers = MakeMeshes(preview.Meshes),
            VertexCounts = vertexCounts,
            Bounds = bounds,
        };
    }

    public void ClearAppearancePreview(int? key = null)
    {
        if (key is int k)
        {
            if (_previews.Remove(k, out PreviewMeshes? removed))
            {
                RetirePreview(removed);
            }
        }
        else
        {
            foreach (PreviewMeshes preview in _previews.Values)
            {
                RetirePreview(preview);
            }

            _previews.Clear();
        }
    }

    public void Encode(
        nint command,
        GPUTexture color,
        GPUTexture depth,
        GPUTexture? msaaColor = null,
        GPUTexture? msaaDepth = null)
    {
        var canvas = new Vector2(color.Width, color.Height);
        UpdateAmbientMaps(canvas, command);

        bool previewing = PreviewPlacement is { } pp && pp.Rects.Keys.Any(k => _previews.ContainsKey(k));
        int split = previewing ? Math.Min(Overlay.Count, Math.Max(0, PreviewPlacement!.Value.Index + 1)) : Overlay.Count;
        bool needsAmbient = DrawsLot && AmbientEnabled && Environment is not null && GPU.EffectShaders.ContainsKey("groundDepth.vert") && Viewport(canvas) is not null;
        bool needsCensor = DrawsLot && Scene?.CensorRects is { Count: > 0 } && Viewport(canvas) is not null;
        bool useMsaa = msaaColor is not null
            && msaaDepth is not null
            && msaaColor.Width == color.Width
            && msaaColor.Height == color.Height
            && msaaDepth.Width == depth.Width
            && msaaDepth.Height == depth.Height
            && msaaColor.SampleCount > SDL_GPU_SAMPLECOUNT_1
            && msaaColor.SampleCount == msaaDepth.SampleCount
            && !needsAmbient;
        int passSamples = useMsaa ? msaaColor!.SampleCount : SDL_GPU_SAMPLECOUNT_1;
        int activePassSamples = passSamples;
        GPUTexture targetColor = useMsaa ? msaaColor! : color;
        GPUTexture targetDepth = useMsaa ? msaaDepth! : depth;
        bool resolveLotPassImmediately = useMsaa && (!previewing || needsCensor);
        GPUTexture? initialResolve = resolveLotPassImmediately ? color : null;

        nint pass = BeginPass(
            command,
            targetColor,
            targetDepth,
            clearColor: true,
            resolveColor: initialResolve,
            discardDepth: resolveLotPassImmediately);
        try
        {
            if (DrawsLot)
            {
                EncodeLot(pass, command, canvas, passSamples, deferTranslucentAvatars: needsAmbient);
            }

            if (needsAmbient && Viewport(canvas) is { } viewport)
            {
                SDL_EndGPURenderPass(pass);
                pass = 0;

                GPUTexture ground = GroundTexture(color.Width, color.Height);
                EncodeGroundDepth(command, ground, viewport, canvas);
                var (heightMap, footMap, worldDepth, worldBackDepth, worldShadowViewport) = EnsureWorldShadowMaps(command, depth, viewport, canvas);
                EncodeAmbient(command, color, depth, ground, heightMap, footMap.Texture, worldDepth, worldBackDepth, worldShadowViewport, viewport, canvas);
                if (HasTranslucentAvatars())
                {
                    pass = BeginPass(command, color, depth, clearColor: false, clearDepth: false);
                    EncodeTranslucentAvatars(pass, command, canvas, SDL_GPU_SAMPLECOUNT_1);
                    if (Scene?.CensorRects is { Count: > 0 })
                    {
                        SDL_EndGPURenderPass(pass);
                        pass = 0;
                    }
                    else
                    {
                        activePassSamples = SDL_GPU_SAMPLECOUNT_1;
                    }
                }

                if (Scene?.CensorRects is { Count: > 0 } censors)
                {
                    EncodeCensorRects(censors, command, color, depth, viewport, canvas);
                }

                if (pass == 0)
                {
                    pass = BeginPass(command, color, depth, clearColor: false, clearDepth: false);
                    activePassSamples = SDL_GPU_SAMPLECOUNT_1;
                }
                EncodePostAmbientOverlaySprites(pass, command, viewport, canvas, activePassSamples);
            }
            else if (needsCensor && Scene?.CensorRects is { Count: > 0 } censors && Viewport(canvas) is { } censorViewport)
            {
                SDL_EndGPURenderPass(pass);
                pass = 0;

                if (useMsaa && ComputeCensorScissor(censors, censorViewport, color.Width, color.Height) is { } censorScissor)
                {
                    nint censorDepthPass = BeginPass(command, SurfaceTexture(color.Width, color.Height), depth, clearColor: true);
                    try
                    {
                        EncodeLot(censorDepthPass, command, canvas, SDL_GPU_SAMPLECOUNT_1, censorScissor);
                    }
                    finally
                    {
                        SDL_EndGPURenderPass(censorDepthPass);
                    }
                }

                EncodeCensorRects(censors, command, color, depth, censorViewport, canvas);
                pass = BeginPass(command, color, depth, clearColor: false);
                activePassSamples = SDL_GPU_SAMPLECOUNT_1;
            }

            EncodeOverlay(CollectionsMarshal.AsSpan(Overlay).Slice(0, split), pass, command, canvas, activePassSamples);
            if (previewing && PreviewPlacement is { } placement)
            {
                SDL_EndGPURenderPass(pass);
                pass = 0;

                bool previewMsaa = useMsaa && !needsCensor;
                int previewSamples = previewMsaa ? passSamples : SDL_GPU_SAMPLECOUNT_1;
                pass = BeginPass(
                    command,
                    previewMsaa ? targetColor : color,
                    previewMsaa ? targetDepth : depth,
                    clearColor: false,
                    resolveColor: previewMsaa ? color : null,
                    discardDepth: previewMsaa);
                foreach (var (key, rect) in placement.Rects.OrderBy(kv => kv.Key))
                {
                    if (_previews.TryGetValue(key, out PreviewMeshes? preview))
                    {
                        EncodePreview(preview, rect, pass, command, canvas, previewSamples);
                    }
                }

                EncodeOverlay(CollectionsMarshal.AsSpan(Overlay).Slice(split), pass, command, canvas, previewSamples);
            }
        }
        finally
        {
            if (pass != 0)
            {
                SDL_EndGPURenderPass(pass);
            }
        }
    }

    private unsafe nint BeginPass(
        nint command,
        GPUTexture color,
        GPUTexture depth,
        bool clearColor,
        GPUTexture? resolveColor = null,
        bool discardDepth = false,
        bool clearDepth = true)
    {
        var clear = new SDL_FColor { r = 0f, g = 0f, b = OriginalUIBlue, a = 1f };
        if (DrawsLot && Scene?.Lighting?.Backdrop is { } backdrop)
        {
            static float Linear(byte value) => (float)Math.Pow((value / 255.0 + 0.055) / 1.055, 2.4);
            clear = new SDL_FColor { r = Linear(backdrop.R), g = Linear(backdrop.G), b = Linear(backdrop.B), a = 1f };
        }

        var colorTarget = new SDL_GPUColorTargetInfo
        {
            texture = color.Handle,
            clear_color = clear,
            load_op = clearColor ? SDL_GPU_LOADOP_CLEAR : SDL_GPU_LOADOP_LOAD,
            store_op = resolveColor is not null ? SDL_GPU_STOREOP_RESOLVE : SDL_GPU_STOREOP_STORE,
            resolve_texture = resolveColor?.Handle ?? nint.Zero,
        };

        var depthTarget = new SDL_GPUDepthStencilTargetInfo
        {
            texture = depth.Handle,
            clear_depth = 1f,
            load_op = clearDepth ? SDL_GPU_LOADOP_CLEAR : SDL_GPU_LOADOP_LOAD,
            store_op = discardDepth ? SDL_GPU_STOREOP_DONT_CARE : SDL_GPU_STOREOP_STORE,
            stencil_load_op = SDL_GPU_LOADOP_DONT_CARE,
            stencil_store_op = SDL_GPU_STOREOP_DONT_CARE,
        };

        nint pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget);
        if (pass == 0)
        {
            throw new SDLError("SDL_BeginGPURenderPass");
        }

        return pass;
    }
}
