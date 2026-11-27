using System.Numerics;
using SimsSDL.Core;
using LotCamera = SimsSDL.Core.LotCamera;

namespace SimsEngine.Tests.Client;

public sealed class LotSurroundingsTests
{
    private static LotScene BuildTestScene(
        int width,
        int height,
        int cameraOrientation = 0,
        List<LotScene.Mesh>? meshes = null,
        IReadOnlyList<IReadOnlyList<LotScene.Sprite>>? scenery = null)
    {
        var camera = (LotCamera)(((cameraOrientation % 4) + 4) % 4);
        var size = new Vector2(width, height);
        var vertices = new LotScene.TerrainVertex[width * height * 6];
        ReadOnlySpan<(int Dx, int Dy)> corners = [(0, 0), (1, 0), (1, 1), (1, 1), (0, 1), (0, 0)];
        for (int ty = 0; ty < height; ty++)
        {
            for (int tx = 0; tx < width; tx++)
            {
                bool padding = tx == 0 || ty == 0 || tx == width - 1 || ty == height - 1;
                for (int c = 0; c < 6; c++)
                {
                    int vx = tx + corners[c].Dx;
                    int vy = ty + corners[c].Dy;
                    Vector2 p = camera.ProjectedPoint(new Vector2(vx, vy), size);
                    byte r = padding ? (byte)10 : (byte)(50 + vx);
                    byte g = padding ? (byte)20 : (byte)(120 + vy);
                    byte b = padding ? (byte)30 : (byte)40;
                    vertices[(ty * width + tx) * 6 + c] = new LotScene.TerrainVertex(p.X, p.Y, r, g, b, 15, 60, 20, 80);
                }
            }
        }

        return new LotScene
        {
            SchemaVersion = 1,
            House = 5,
            Width = 2048f,
            Height = 1024f,
            LotWidth = width,
            LotHeight = height,
            CameraOrientation = cameraOrientation,
            OriginX = 0f,
            OriginY = 0f,
            Textures = [new LotScene.Texture("road0.bmp", 64, 32), new LotScene.Texture("road1.bmp", 64, 32), new LotScene.Texture("sidewalk.bmp", 64, 32)],
            Sprites = [],
            Limitations = [],
            TerrainVertices = vertices,
            Meshes = meshes ?? [],
            Scenery = scenery,
        };
    }

    private static LotScene.Mesh RoadTileMesh(LotCamera camera, Vector2 lotSize, int x, int y, ushort pattern, int texture)
    {
        ReadOnlySpan<(int Dx, int Dy, float U, float V)> quad =
        [
            (0, 0, 0.5f, 0f),
            (1, 0, 1f, 0.5f),
            (1, 1, 0.5f, 1f),
            (1, 1, 0.5f, 1f),
            (0, 1, 0f, 0.5f),
            (0, 0, 0.5f, 0f),
        ];
        var verts = new LotScene.MeshVertex[6];
        for (int i = 0; i < 6; i++)
        {
            Vector2 p = camera.ProjectedPoint(new Vector2(x + quad[i].Dx, y + quad[i].Dy), lotSize);
            verts[i] = new LotScene.MeshVertex(p.X, p.Y, 1f, quad[i].U, quad[i].V, 0f, 1f, 0f);
        }

        return new LotScene.Mesh(
            texture: texture,
            objectID: 0,
            depth: 0f,
            vertices: verts,
            level: 1,
            unlit: true,
            floor: new LotScene.FloorSurface(x, y, pattern, 0, level: 1));
    }

    [Fact]
    public void TerrainExtension_UsesInteriorBoundaryAndIgnoresPaddingRing()
    {
        var scene = BuildTestScene(16, 16);
        var surroundings = new LotSurroundings(scene, margin: 12);

        Assert.NotEmpty(surroundings.Terrain);
        Assert.Equal(surroundings.Terrain.Count, surroundings.Depths.Length);
        Assert.Equal(0, surroundings.Terrain.Count % 6);
        Assert.All(surroundings.Terrain, v =>
        {
            Assert.NotEqual((byte)10, v.R);
            Assert.InRange(v.R, (byte)51, (byte)65);
            Assert.InRange(v.G, (byte)121, (byte)135);
        });
        Assert.All(surroundings.Depths, d => Assert.InRange(d, 0.001f, 0.999f));
    }

    [Fact]
    public void Roads_MirrorLengthwiseEdgeAndContinuePerpendicularExitWithSixTileCycle()
    {
        const int size = 20;
        var lotSize = new Vector2(size, size);
        var camera = LotCamera.TopLeft;
        var meshes = new List<LotScene.Mesh>();

        for (int x = 1; x <= size - 2; x++)
        {
            int phase = (x - 1) % 6;
            int roadTex = phase < 3 ? 0 : 1;
            meshes.Add(RoadTileMesh(camera, lotSize, x, size - 2, 10, roadTex));
            meshes.Add(RoadTileMesh(camera, lotSize, x, size - 3, 11, roadTex));
            meshes.Add(RoadTileMesh(camera, lotSize, x, size - 4, 12, 2));
        }

        var scene = BuildTestScene(size, size, cameraOrientation: 0, meshes: meshes);
        var surroundings = new LotSurroundings(scene, margin: 24);

        Assert.NotEmpty(surroundings.Roads);
        int totalVertices = surroundings.Roads.Sum(m => m.Vertices.Count);
        int mirroredAlongBottom = (size - 2) * 3 * 6;
        int continuedLeftAndRight = 2 * 3 * 24 * 6;
        Assert.Equal(mirroredAlongBottom + continuedLeftAndRight, totalVertices);

        int tex0Verts = surroundings.Roads.Where(m => m.Texture == 0).Sum(m => m.Vertices.Count);
        int tex1Verts = surroundings.Roads.Where(m => m.Texture == 1).Sum(m => m.Vertices.Count);
        Assert.True(tex0Verts > 0);
        Assert.True(tex1Verts > 0);
    }

    [Fact]
    public void SceneryDecorations_StayOutsideBufferAndClearOfStreets()
    {
        const int size = 16;
        var lotSize = new Vector2(size, size);
        var meshes = new List<LotScene.Mesh>();
        for (int x = 1; x <= size - 2; x++)
        {
            meshes.Add(RoadTileMesh(LotCamera.TopLeft, lotSize, x, size - 2, 10, 0));
            meshes.Add(RoadTileMesh(LotCamera.TopLeft, lotSize, x, size - 3, 12, 2));
        }

        var prototypes = new IReadOnlyList<LotScene.Sprite>[]
        {
            [
                new LotScene.Sprite
                {
                    Texture = 0,
                    X = -16f,
                    Y = -48f,
                    Width = 32f,
                    Height = 64f,
                    Flip = false,
                    DepthTexture = 0,
                    DepthNear = -0.002f,
                    DepthFar = 0.002f,
                }
            ]
        };

        var scene = BuildTestScene(size, size, meshes: meshes, scenery: prototypes) with
        {
            SceneryTypes = [new LotScene.SceneryType(0x1468C3A7u, "Trees - Birch")],
        };
        var first = new LotSurroundings(scene, margin: 40);
        var second = new LotSurroundings(scene, margin: 40);
        var rotated = new LotSurroundings(scene with { CameraOrientation = 1 }, margin: 40);

        Assert.NotEmpty(first.Decorations);
        Assert.Equal(first.Decorations.Count, second.Decorations.Count);
        Assert.Equal(first.Decorations.Count, first.SceneryInstances.Count);
        Assert.Equal(first.SceneryInstances, rotated.SceneryInstances);
        Assert.All(first.SceneryInstances, inst =>
        {
            Assert.Equal(0x1468C3A7u, inst.Guid);
            Assert.Equal("Trees - Birch", inst.Name);
            Assert.True(inst.X < 0f || inst.X > size || inst.Y < 0f || inst.Y > size);
            Vector2 expectedAnchor = LotCamera.TopLeft.ProjectedPoint(new Vector2(inst.X, inst.Y), lotSize);
            Assert.Contains(first.Decorations, d => MathF.Abs(d.X - (expectedAnchor.X - 16f)) < 0.01f);
        });
        for (int i = 0; i < first.Decorations.Count; i++)
        {
            Assert.Equal(first.Decorations[i].X, second.Decorations[i].X);
            Assert.Equal(first.Decorations[i].Y, second.Decorations[i].Y);
            Assert.Equal(255, first.Decorations[i].Room);
            if (i > 0)
            {
                Assert.True((first.Decorations[i].Depth ?? 0f) >= (first.Decorations[i - 1].Depth ?? 0f));
            }
        }
    }

    [Fact]
    public void HillBoundary_EasesSmoothlyTowardBaselineWithoutSeam()
    {
        const int size = 20;
        var lotSize = new Vector2(size, size);
        var camera = LotCamera.TopLeft;
        var heights = new short[size * size];
        for (int x = 1; x < size - 1; x++)
        {
            heights[1 * size + x] = 8;
        }

        var vertices = new LotScene.TerrainVertex[size * size * 6];
        ReadOnlySpan<(int Dx, int Dy)> corners = [(0, 0), (1, 0), (1, 1), (1, 1), (0, 1), (0, 0)];
        for (int ty = 0; ty < size; ty++)
        {
            for (int tx = 0; tx < size; tx++)
            {
                for (int c = 0; c < 6; c++)
                {
                    int vx = tx + corners[c].Dx;
                    int vy = ty + corners[c].Dy;
                    float elev = vy <= 2 ? 60f : 0f;
                    Vector2 p = camera.ProjectedPoint(new Vector2(vx, vy), lotSize, elev);
                    vertices[(ty * size + tx) * 6 + c] = new LotScene.TerrainVertex(p.X, p.Y, 60, 100, 50, 15, 50, 10, 90);
                }
            }
        }

        var scene = new LotScene
        {
            SchemaVersion = 1,
            House = 5,
            Width = 2048f,
            Height = 1024f,
            LotWidth = size,
            LotHeight = size,
            CameraOrientation = 0,
            OriginX = 0f,
            OriginY = 0f,
            TerrainHeights = heights,
            Textures = [new LotScene.Texture("road0.bmp", 64, 32)],
            Sprites = [],
            Limitations = [],
            TerrainVertices = vertices,
            Meshes = [],
        };

        var surroundings = new LotSurroundings(scene, margin: 28);
        Assert.NotEmpty(surroundings.Terrain);

        Vector2 seamExpected = camera.ProjectedPoint(new Vector2(10, 1), lotSize, 60f);
        Assert.Contains(surroundings.Terrain, v => MathF.Abs(v.X - seamExpected.X) < 0.01f && MathF.Abs(v.Y - seamExpected.Y) < 0.01f);

        Vector2 farFlat = camera.ProjectedPoint(new Vector2(10, -20), lotSize, 0f);
        var farMatches = surroundings.Terrain.Where(v => MathF.Abs(v.X - farFlat.X) < 0.5f && MathF.Abs(v.Y - farFlat.Y) < 80f).ToList();
        Assert.NotEmpty(farMatches);
        float farElev = farFlat.Y - farMatches[0].Y;
        Assert.InRange(farElev, 5f, 65f);

        var edgeCounts = new Dictionary<((int X, int Y) A, (int X, int Y) B), int>();
        static (int X, int Y) Quantize(LotScene.TerrainVertex v) =>
            ((int)MathF.Round(v.X * 16f), (int)MathF.Round(v.Y * 16f));

        for (int t = 0; t < surroundings.Terrain.Count; t += 3)
        {
            var p0 = Quantize(surroundings.Terrain[t]);
            var p1 = Quantize(surroundings.Terrain[t + 1]);
            var p2 = Quantize(surroundings.Terrain[t + 2]);
            ReadOnlySpan<((int X, int Y) U, (int X, int Y) V)> triEdges = [(p0, p1), (p1, p2), (p2, p0)];
            foreach (var (u, v) in triEdges)
            {
                var rev = (v, u);
                if (edgeCounts.TryGetValue(rev, out int revCnt) && revCnt > 0)
                {
                    if (revCnt == 1) edgeCounts.Remove(rev);
                    else edgeCounts[rev] = revCnt - 1;
                }
                else
                {
                    edgeCounts[(u, v)] = edgeCounts.GetValueOrDefault((u, v)) + 1;
                }
            }
        }

        int innerLo = -6;
        int innerHi = (size + 7) & ~1;
        int outerLo = Math.Min(innerLo - 2, -((28 + 7) & ~1));
        int outerHi = Math.Max(innerHi + 2, (size + 28 + 7) & ~1);
        int expectedInnerBoundaryEdges = (size - 2) * 4;
        int expectedOuterBoundaryEdges = ((outerHi - outerLo) / 2) * 4;
        Assert.Equal(expectedInnerBoundaryEdges + expectedOuterBoundaryEdges, edgeCounts.Count);
        Assert.All(edgeCounts.Values, c => Assert.Equal(1, c));
    }
}
