using System.Numerics;

namespace SimsSDL.Core;

public sealed class LotSurroundings
{
    private static readonly (byte R, byte G, byte B)[] LightGreen =
    [
        (0x50, 0x74, 0x3b), (0x50, 0x74, 0x3b), (0x50, 0x74, 0x3b), (0xe6, 0xf0, 0xff),
        (0x50, 0x74, 0x3b), (0x50, 0x5c, 0x48), (0x90, 0x7a, 0x38), (0xe6, 0xf0, 0xff),
    ];

    private static readonly (byte R, byte G, byte B)[] LightBrown =
    [
        (0x9d, 0x75, 0x41), (0xdc, 0xd2, 0xaa), (0x9d, 0x75, 0x41), (0x9d, 0x75, 0x41),
        (0x9d, 0x75, 0x41), (0x5a, 0x48, 0x2b), (0x75, 0x4b, 0x28), (0x14, 0x14, 0x8c),
    ];

    private static readonly (byte R, byte G, byte B)[] DarkGreen =
    [
        (0x0e, 0x35, 0x08), (0x0e, 0x35, 0x08), (0x0e, 0x35, 0x08), (0xa1, 0xb4, 0xd2),
        (0x0e, 0x35, 0x08), (0x0e, 0x18, 0x0a), (0x68, 0x3c, 0x20), (0xa1, 0xb4, 0xd2),
    ];

    private static readonly (byte R, byte G, byte B)[] DarkBrown =
    [
        (0x51, 0x3c, 0x12), (0xbd, 0xb3, 0x8b), (0x51, 0x3c, 0x12), (0x51, 0x3c, 0x12),
        (0x51, 0x3c, 0x12), (0x47, 0x46, 0x0f), (0x3a, 0x26, 0x0e), (0x14, 0x14, 0x8c),
    ];

    public IReadOnlyList<LotScene.TerrainVertex> Terrain { get; }
    public float[] Depths { get; }
    public IReadOnlyList<LotScene.Mesh> Roads { get; }
    public IReadOnlyList<LotScene.Sprite> Decorations { get; }
    public IReadOnlyList<SimsNative.Plugins.PluginSceneryInstance> SceneryInstances { get; }

    private static int ResolveTerrainType(int house) => house switch
    {
        28 or 29 or 46 or 47 or 48 => 1,
        40 or 41 or 42 => 3,
        >= 90 and <= 94 => 5,
        95 or 96 => 6,
        99 => 7,
        _ => 0,
    };

    private static float SmoothStep(float edge0, float edge1, float x)
    {
        if (edge1 <= edge0)
            return x >= edge1 ? 1f : 0f;
        float t = Math.Clamp((x - edge0) / (edge1 - edge0), 0f, 1f);
        return t * t * (3f - 2f * t);
    }

    private static (byte R, byte G, byte B) LerpColor((byte R, byte G, byte B) a, (byte R, byte G, byte B) b, float t)
    {
        t = Math.Clamp(t, 0f, 1f);
        return (
            (byte)Math.Clamp((int)MathF.Round(a.R + (b.R - a.R) * t), 0, 255),
            (byte)Math.Clamp((int)MathF.Round(a.G + (b.G - a.G) * t), 0, 255),
            (byte)Math.Clamp((int)MathF.Round(a.B + (b.B - a.B) * t), 0, 255));
    }

    public LotSurroundings(LotScene scene, int margin)
    {
        if (scene.LotWidth is not int width ||
            scene.LotHeight is not int height ||
            width <= 2 ||
            height <= 2 ||
            scene.TerrainVertices is not { } vertices ||
            vertices.Count != width * height * 6 ||
            scene.OriginX is not float originX ||
            scene.OriginY is not float originY)
        {
            Terrain = [];
            Depths = [];
            Roads = [];
            Decorations = [];
            SceneryInstances = [];
            return;
        }

        Vector2 size = new(width, height);
        int clampedMargin = Math.Max(4, margin);
        int terrainType = ResolveTerrainType(scene.House);
        bool hasRealHeights = scene.TerrainHeights is not null && scene.TerrainHeights.Count == width * height;

        LotScene.TerrainVertex LotVertexAt(int ix, int iy)
        {
            ix = Math.Clamp(ix, 1, width - 1);
            iy = Math.Clamp(iy, 1, height - 1);
            int tx = Math.Min(width - 2, ix);
            int ty = Math.Min(height - 2, iy);
            int corner = iy > ty ? (ix > tx ? 2 : 4) : (ix > tx ? 1 : 0);
            return vertices[(ty * width + tx) * 6 + corner];
        }

        float LotElevAt(int ix, int iy)
        {
            ix = Math.Clamp(ix, 1, width - 1);
            iy = Math.Clamp(iy, 1, height - 1);
            LotScene.TerrainVertex lv = LotVertexAt(ix, iy);
            Vector2 lp = scene.Camera.ProjectedPoint(new Vector2(ix, iy), size);
            return lp.Y - originY - lv.Y;
        }

        float[] topElev = new float[width];
        float[] bottomElev = new float[width];
        float[] leftElev = new float[height];
        float[] rightElev = new float[height];
        float[] topSlope = new float[width];
        float[] bottomSlope = new float[width];
        float[] leftSlope = new float[height];
        float[] rightSlope = new float[height];
        float[] topGrass = new float[width];
        float[] bottomGrass = new float[width];
        float[] leftGrass = new float[height];
        float[] rightGrass = new float[height];
        var perimeterElevSample = new List<float>((width + height) * 2);
        double grassAccum = 0.0;
        int grassCount = 0;

        int innerStepY = Math.Min(height - 1, 2);
        int innerStepBackY = Math.Max(1, height - 2);
        int innerStepX = Math.Min(width - 1, 2);
        int innerStepBackX = Math.Max(1, width - 2);

        for (int x = 1; x <= width - 1; x++)
        {
            topElev[x] = LotElevAt(x, 1);
            bottomElev[x] = LotElevAt(x, height - 1);
            topSlope[x] = Math.Clamp(topElev[x] - LotElevAt(x, innerStepY), -7.5f, 7.5f);
            bottomSlope[x] = Math.Clamp(bottomElev[x] - LotElevAt(x, innerStepBackY), -7.5f, 7.5f);
            topGrass[x] = LotVertexAt(x, 1).Grass ?? 127;
            bottomGrass[x] = LotVertexAt(x, height - 1).Grass ?? 127;
            perimeterElevSample.Add(topElev[x]);
            perimeterElevSample.Add(bottomElev[x]);
            grassAccum += topGrass[x] + bottomGrass[x];
            grassCount += 2;
        }

        for (int y = 1; y <= height - 1; y++)
        {
            leftElev[y] = LotElevAt(1, y);
            rightElev[y] = LotElevAt(width - 1, y);
            leftSlope[y] = Math.Clamp(leftElev[y] - LotElevAt(innerStepX, y), -7.5f, 7.5f);
            rightSlope[y] = Math.Clamp(rightElev[y] - LotElevAt(innerStepBackX, y), -7.5f, 7.5f);
            leftGrass[y] = LotVertexAt(1, y).Grass ?? 127;
            rightGrass[y] = LotVertexAt(width - 1, y).Grass ?? 127;
            perimeterElevSample.Add(leftElev[y]);
            perimeterElevSample.Add(rightElev[y]);
            grassAccum += leftGrass[y] + rightGrass[y];
            grassCount += 2;
        }

        perimeterElevSample.Sort();
        float medianPerimeterElev = perimeterElevSample.Count > 0 ? perimeterElevSample[perimeterElevSample.Count / 2] : 0f;
        float meanPerimeterGrass = grassCount > 0 ? (float)(grassAccum / grassCount) : 115f;

        List<LotScene.Mesh> paving = [];
        Dictionary<(int X, int Y), LotScene.Mesh> tiles = new();
        Dictionary<(int X, int Y), LotScene.Mesh> customFloors = new();
        List<LotScene.Mesh> oceanTiles = [];
        Dictionary<(int X, int Y), LotScene.Mesh> oceanMap = new();
        bool hasStandardAsphalt = false;
        if (scene.Meshes is { } sceneMeshes)
        {
            foreach (LotScene.Mesh mesh in sceneMeshes)
            {
                if ((mesh.Level ?? 1) == 1 && mesh.Floor is { Half: 0 } floor)
                {
                    if (floor.Pattern is >= 9 and <= 12)
                    {
                        paving.Add(mesh);
                        tiles[(floor.X, floor.Y)] = mesh;
                        if (floor.Pattern < 12)
                            hasStandardAsphalt = true;
                    }
                    else if (floor.Pattern == 65534)
                    {
                        oceanTiles.Add(mesh);
                        oceanMap[(floor.X, floor.Y)] = mesh;
                    }
                    else if (floor.Pattern is >= 256 and < 65534)
                    {
                        customFloors[(floor.X, floor.Y)] = mesh;
                    }
                }
            }
        }

        ushort? customRoadPattern = null;
        if (!hasStandardAsphalt && customFloors.Count > 0)
        {
            for (int e = 0; e < 4 && customRoadPattern is null; e++)
            {
                int borderLen = (e < 2 ? height : width) - 2;
                if (borderLen < 12)
                    continue;
                Dictionary<ushort, int> counts = new();
                for (int i = 1; i <= borderLen; i++)
                {
                    (int bx, int by) = e switch
                    {
                        0 => (1, i),
                        1 => (width - 2, i),
                        2 => (i, 1),
                        _ => (i, height - 2),
                    };
                    if (customFloors.TryGetValue((bx, by), out var m))
                    {
                        ushort pat = m.Floor!.Pattern;
                        counts[pat] = counts.GetValueOrDefault(pat) + 1;
                    }
                }
                foreach (var (pat, cnt) in counts)
                {
                    if (cnt >= borderLen - 2)
                    {
                        int mid = borderLen / 2;
                        int depth = 0;
                        while (depth < 10)
                        {
                            (int tx, int ty) = e switch
                            {
                                0 => (1 + depth, mid),
                                1 => (width - 2 - depth, mid),
                                2 => (mid, 1 + depth),
                                _ => (mid, height - 2 - depth),
                            };
                            if (customFloors.TryGetValue((tx, ty), out var dm) && dm.Floor!.Pattern == pat)
                                depth++;
                            else
                                break;
                        }
                        if (depth is >= 4 and <= 8)
                        {
                            customRoadPattern = pat;
                            break;
                        }
                    }
                }
            }

            if (customRoadPattern is ushort roadPat)
            {
                foreach (var (coord, mesh) in customFloors)
                {
                    if (mesh.Floor!.Pattern == roadPat)
                    {
                        paving.Add(mesh);
                        tiles[coord] = mesh;
                    }
                }
            }
        }

        bool IsRoadSurface(ushort pat) => pat < 12 || (customRoadPattern is ushort rp && pat == rp);

        Dictionary<(int Medium, int? Near, int? Far), List<LotScene.MeshVertex>> batches = new();
        List<(int Edge, int Along, int? Width, float Elev)> streets = [];
        List<(int Edge, int Low, int High, float Elev)> oceanEdges = [];
        Vector2 projOrigin = scene.Camera.ProjectedPoint(Vector2.Zero, size);
        Vector2 axisX = scene.Camera.ProjectedPoint(new Vector2(1f, 0f), size) - projOrigin;
        Vector2 axisY = scene.Camera.ProjectedPoint(new Vector2(0f, 1f), size) - projOrigin;
        float determinant = axisX.X * axisY.Y - axisX.Y * axisY.X;

        for (int edge = 0; edge < 4; edge++)
        {
            (int X, int Y) Tile(int along, int inward) => edge switch
            {
                0 => (1 + inward, along),
                1 => (width - 2 - inward, along),
                2 => (along, 1 + inward),
                _ => (along, height - 2 - inward),
            };

            List<LotScene.Mesh> border = [];
            bool hasAsphalt = false;
            foreach (LotScene.Mesh m in paving)
            {
                var fl = m.Floor!;
                int coord = edge < 2 ? fl.Y : fl.X;
                if (Tile(coord, 0) == (fl.X, fl.Y))
                {
                    border.Add(m);
                    if (IsRoadSurface(fl.Pattern))
                        hasAsphalt = true;
                }
            }

            if (!hasAsphalt)
                continue;

            (int Total, int Asphalt) StreetDepth(int along)
            {
                int count = 0;
                int asphaltCount = 0;
                bool seenAsphalt = false;
                int trailingSidewalk = 0;
                while (tiles.TryGetValue(Tile(along, count), out LotScene.Mesh? m))
                {
                    ushort pat = m.Floor!.Pattern;
                    if (IsRoadSurface(pat))
                    {
                        seenAsphalt = true;
                        asphaltCount += 1;
                        trailingSidewalk = 0;
                    }
                    else if (seenAsphalt)
                    {
                        trailingSidewalk += 1;
                        if (trailingSidewalk > 1)
                            break;
                    }
                    count += 1;
                }
                return (count, asphaltCount);
            }

            int Run(int along)
            {
                int low = along;
                int high = along;
                while (tiles.ContainsKey(Tile(low - 1, 0)))
                    low -= 1;
                while (tiles.ContainsKey(Tile(high + 1, 0)))
                    high += 1;
                return high - low + 1;
            }

            Dictionary<int, (int Total, int Asphalt)?> lengthwise = new();
            List<int> lengthwiseTotals = [];
            List<int> lengthwiseAsphalts = [];
            List<int> exitAlongs = [];
            foreach (LotScene.Mesh m in border)
            {
                int along = edge < 2 ? m.Floor!.Y : m.Floor!.X;
                if (lengthwise.ContainsKey(along))
                    continue;
                int length = Run(along);
                var (across, asphaltAcross) = StreetDepth(along);
                (int Total, int Asphalt)? w = length >= 8 && across * 2 < length ? (across, asphaltAcross) : null;
                lengthwise[along] = w;
                if (w is { } wVal)
                {
                    lengthwiseTotals.Add(wVal.Total);
                    lengthwiseAsphalts.Add(wVal.Asphalt);
                }
                else
                {
                    exitAlongs.Add(along);
                }
            }

            lengthwiseTotals.Sort();
            lengthwiseAsphalts.Sort();
            int uniformBand = lengthwiseTotals.Count > 0 ? lengthwiseTotals[lengthwiseTotals.Count / 2] : 0;
            int medianAsphalt = lengthwiseAsphalts.Count > 0 ? lengthwiseAsphalts[lengthwiseAsphalts.Count / 2] : 0;
            bool mirrorHalfStreet = uniformBand > 0 && medianAsphalt <= 3;

            void Place(LotScene.Mesh source, (int X, int Y) from, int along, int step, bool mirrored)
            {
                (int X, int Y) target = Tile(along, -step);
                Vector2 delta = scene.Camera.ProjectedPoint(new Vector2(target.X, target.Y), size)
                              - scene.Camera.ProjectedPoint(new Vector2(from.X, from.Y), size);
                Vector2 centre = Vector2.Zero;
                for (int i = 0; i < source.Vertices.Count; i++)
                    centre += new Vector2(source.Vertices[i].X, source.Vertices[i].Y);
                centre /= Math.Max(1, source.Vertices.Count);

                var key = (source.Texture, source.NearTexture, source.FarTexture);
                if (!batches.TryGetValue(key, out List<LotScene.MeshVertex>? list))
                {
                    list = [];
                    batches[key] = list;
                }

                for (int i = 0; i < source.Vertices.Count; i++)
                {
                    LotScene.MeshVertex v = source.Vertices[i];
                    Vector2 p = new(v.X, v.Y);
                    if (mirrored && determinant != 0f)
                    {
                        Vector2 d = p - centre;
                        if (edge < 2)
                            p -= 2f * (d.X * axisY.Y - d.Y * axisY.X) / determinant * axisX;
                        else
                            p -= 2f * (axisX.X * d.Y - axisX.Y * d.X) / determinant * axisY;
                    }

                    list.Add(new LotScene.MeshVertex(p.X + delta.X, p.Y + delta.Y, 1f, v.U, v.V, v.NX, v.NY, v.NZ));
                }
            }

            int maxLotInward = (edge < 2 ? width : height) - 3;
            int dashCycleStart = uniformBand > 0 && uniformBand + 11 <= maxLotInward ? uniformBand + 6 : uniformBand;

            float EdgeElev(int along) => edge switch
            {
                0 => leftElev[Math.Clamp(along, 1, height - 1)],
                1 => rightElev[Math.Clamp(along, 1, height - 1)],
                2 => topElev[Math.Clamp(along, 1, width - 1)],
                _ => bottomElev[Math.Clamp(along, 1, width - 1)],
            };

            foreach (LotScene.Mesh boundary in border)
            {
                int along = edge < 2 ? boundary.Floor!.Y : boundary.Floor!.X;
                float sElev = EdgeElev(along);

                if (lengthwise.TryGetValue(along, out var acrossOpt) && acrossOpt is { } raw)
                {
                    if (mirrorHalfStreet)
                    {
                        int across = Math.Min(raw.Total, uniformBand);
                        streets.Add((edge, along, across, sElev));
                        for (int step = 1; step <= across; step++)
                        {
                            (int X, int Y) from = Tile(along, step - 1);
                            Place(tiles[from], from, along, step, mirrored: true);
                        }
                    }
                    else
                    {
                        streets.Add((edge, along, 0, sElev));
                    }
                    continue;
                }

                streets.Add((edge, along, null, sElev));
                int mirrorPrefix = mirrorHalfStreet ? uniformBand : (uniformBand > 0 ? 1 : 0);
                for (int step = 1; step <= clampedMargin; step++)
                {
                    if (step <= mirrorPrefix)
                    {
                        int prefixInward = mirrorHalfStreet ? step - 1 : uniformBand;
                        if (tiles.TryGetValue(Tile(along, prefixInward), out LotScene.Mesh? bandSource))
                        {
                            Place(bandSource, Tile(along, prefixInward), along, step, mirrored: true);
                            continue;
                        }
                    }

                    int phase = (step - mirrorPrefix - 1) % 6;
                    (int X, int Y) from = Tile(along, dashCycleStart + 5 - phase);
                    if (tiles.TryGetValue(from, out LotScene.Mesh? source) &&
                        IsRoadSurface(source.Floor!.Pattern) == IsRoadSurface(boundary.Floor!.Pattern))
                    {
                        Place(source, from, along, step, mirrored: false);
                    }
                    else if (!IsRoadSurface(boundary.Floor!.Pattern) && customFloors.TryGetValue(from, out LotScene.Mesh? customSw))
                    {
                        Place(customSw, from, along, step, mirrored: false);
                    }
                    else
                    {
                        (int X, int Y) fallbackFrom = Tile(along, uniformBand + 5 - phase);
                        if (tiles.TryGetValue(fallbackFrom, out LotScene.Mesh? fbSource) &&
                            IsRoadSurface(fbSource.Floor!.Pattern) == IsRoadSurface(boundary.Floor!.Pattern))
                        {
                            Place(fbSource, fallbackFrom, along, step, mirrored: false);
                        }
                        else
                        {
                            Place(boundary, Tile(along, 0), along, step, mirrored: false);
                        }
                    }
                }
            }

            if (customRoadPattern is null && exitAlongs.Count > 0 && customFloors.Count > 0)
            {
                exitAlongs.Sort();
                int minExit = exitAlongs[0];
                int maxExit = exitAlongs[^1];
                int maxAlong = (edge < 2 ? height : width) - 2;
                int minCheck = Math.Max(1, minExit - 3);
                int maxCheck = Math.Min(maxAlong, maxExit + 3);

                LotScene.Mesh? SidewalkAt((int X, int Y) coord)
                {
                    if (customFloors.TryGetValue(coord, out var cm))
                        return cm;
                    if (tiles.TryGetValue(coord, out var tm) && tm.Floor!.Pattern == 12)
                        return tm;
                    return null;
                }

                for (int cand = minCheck; cand <= maxCheck; cand++)
                {
                    if (cand >= minExit && cand <= maxExit)
                        continue;
                    if (tiles.ContainsKey(Tile(cand, 0)) && lengthwise.TryGetValue(cand, out var lw) && lw is not null)
                        continue;
                    if (tiles.ContainsKey(Tile(cand, 0)))
                        continue;

                    int runInward = 0;
                    bool hasCustom = false;
                    while (runInward <= maxLotInward && SidewalkAt(Tile(cand, runInward)) is { } sw)
                    {
                        if (sw.Floor!.Pattern >= 256)
                            hasCustom = true;
                        runInward++;
                    }
                    if (!hasCustom || runInward < Math.Min(16, maxLotInward))
                        continue;

                    float sElev = EdgeElev(cand);
                    streets.Add((edge, cand, null, sElev));
                    int mirrorPrefix = mirrorHalfStreet ? uniformBand : (uniformBand > 0 ? 1 : 0);
                    LotScene.Mesh boundarySw = SidewalkAt(Tile(cand, 0))!;
                    for (int step = 1; step <= clampedMargin; step++)
                    {
                        int phase = step <= mirrorPrefix ? 0 : (step - mirrorPrefix - 1) % 6;
                        (int X, int Y) from = Tile(cand, dashCycleStart + 5 - phase);
                        if (SidewalkAt(from) is { } srcSw)
                            Place(srcSw, from, cand, step, mirrored: false);
                        else
                            Place(boundarySw, Tile(cand, 0), cand, step, mirrored: false);
                    }
                }
            }
        }

        if (oceanTiles.Count >= 8)
        {
            LotScene.Mesh? openWaterSource = null;
            foreach (LotScene.Mesh m in oceanTiles)
            {
                if (m.Floor?.Water is { Adjacency: 255 })
                {
                    openWaterSource = m;
                    break;
                }
            }

            bool[] edgeHasOcean = new bool[4];
            (int Low, int High, float Elev)[] edgeSpan = new (int, int, float)[4];
            for (int edge = 0; edge < 4; edge++)
            {
                (int X, int Y) OTile(int along, int inward) => edge switch
                {
                    0 => (1 + inward, along),
                    1 => (width - 2 - inward, along),
                    2 => (along, 1 + inward),
                    _ => (along, height - 2 - inward),
                };

                List<int> borderAlongs = [];
                foreach (LotScene.Mesh m in oceanTiles)
                {
                    var fl = m.Floor!;
                    int coord = edge < 2 ? fl.Y : fl.X;
                    if (OTile(coord, 0) == (fl.X, fl.Y))
                        borderAlongs.Add(coord);
                }

                if (borderAlongs.Count < 8)
                    continue;
                borderAlongs.Sort();
                int minA = borderAlongs[0];
                int maxA = borderAlongs[^1];
                float oElev = edge switch
                {
                    0 => leftElev[Math.Clamp((minA + maxA) / 2, 1, height - 1)],
                    1 => rightElev[Math.Clamp((minA + maxA) / 2, 1, height - 1)],
                    2 => topElev[Math.Clamp((minA + maxA) / 2, 1, width - 1)],
                    _ => bottomElev[Math.Clamp((minA + maxA) / 2, 1, width - 1)],
                };
                edgeHasOcean[edge] = true;
                edgeSpan[edge] = (minA, maxA, oElev);
                oceanEdges.Add((edge, minA, maxA, oElev));

                void PlaceOceanTile(LotScene.Mesh src, (int X, int Y) srcCoord, (int X, int Y) dstCoord)
                {
                    Vector2 delta = scene.Camera.ProjectedPoint(new Vector2(dstCoord.X, dstCoord.Y), size)
                                  - scene.Camera.ProjectedPoint(new Vector2(srcCoord.X, srcCoord.Y), size);
                    var key = (src.Texture, src.NearTexture, src.FarTexture);
                    if (!batches.TryGetValue(key, out List<LotScene.MeshVertex>? list))
                    {
                        list = [];
                        batches[key] = list;
                    }
                    for (int i = 0; i < src.Vertices.Count; i++)
                    {
                        var v = src.Vertices[i];
                        list.Add(new LotScene.MeshVertex(v.X + delta.X, v.Y + delta.Y, 1f, v.U, v.V, v.NX, v.NY, v.NZ));
                    }
                }

                foreach (int along in borderAlongs)
                {
                    (int X, int Y) borderCoord = OTile(along, 0);
                    LotScene.Mesh borderMesh = oceanMap[borderCoord];
                    for (int step = 1; step <= clampedMargin; step++)
                    {
                        PlaceOceanTile(borderMesh, borderCoord, OTile(along, -step));
                    }
                }
            }

            if (openWaterSource is not null)
            {
                (int X, int Y) deepCoord = (openWaterSource.Floor!.X, openWaterSource.Floor!.Y);
                void FillCornerQuadrant(int x0, int y0, int x1, int y1)
                {
                    var key = (openWaterSource.Texture, openWaterSource.NearTexture, openWaterSource.FarTexture);
                    if (!batches.TryGetValue(key, out List<LotScene.MeshVertex>? list))
                    {
                        list = [];
                        batches[key] = list;
                    }
                    Vector2 srcP = scene.Camera.ProjectedPoint(new Vector2(deepCoord.X, deepCoord.Y), size);
                    for (int ty = y0; ty < y1; ty++)
                    {
                        for (int tx = x0; tx < x1; tx++)
                        {
                            Vector2 delta = scene.Camera.ProjectedPoint(new Vector2(tx, ty), size) - srcP;
                            for (int i = 0; i < openWaterSource.Vertices.Count; i++)
                            {
                                var v = openWaterSource.Vertices[i];
                                list.Add(new LotScene.MeshVertex(v.X + delta.X, v.Y + delta.Y, 1f, v.U, v.V, v.NX, v.NY, v.NZ));
                            }
                        }
                    }
                }

                if (edgeHasOcean[0] && edgeHasOcean[2] && edgeSpan[0].Low <= 3 && edgeSpan[2].Low <= 3)
                    FillCornerQuadrant(1 - clampedMargin, 1 - clampedMargin, 1, 1);
                if (edgeHasOcean[1] && edgeHasOcean[2] && edgeSpan[1].Low <= 3 && edgeSpan[2].High >= width - 4)
                    FillCornerQuadrant(width - 1, 1 - clampedMargin, width - 1 + clampedMargin, 1);
                if (edgeHasOcean[0] && edgeHasOcean[3] && edgeSpan[0].High >= height - 4 && edgeSpan[3].Low <= 3)
                    FillCornerQuadrant(1 - clampedMargin, height - 1, 1, height - 1 + clampedMargin);
                if (edgeHasOcean[1] && edgeHasOcean[3] && edgeSpan[1].High >= height - 4 && edgeSpan[3].High >= width - 4)
                    FillCornerQuadrant(width - 1, height - 1, width - 1 + clampedMargin, height - 1 + clampedMargin);
            }
        }

        Roads = batches
            .OrderBy(static kv => kv.Key.Medium)
            .Select(static kv => new LotScene.Mesh(
                texture: kv.Key.Medium,
                objectID: 0,
                depth: 0f,
                vertices: kv.Value,
                unlit: true,
                nearTexture: kv.Key.Near,
                farTexture: kv.Key.Far))
            .ToList();

        bool NearOrInOcean(float x, float y, float pad, out float oceanElev)
        {
            oceanElev = medianPerimeterElev;
            for (int i = 0; i < oceanEdges.Count; i++)
            {
                var oe = oceanEdges[i];
                (float outward, float along) = oe.Edge switch
                {
                    0 => (1f - x, y),
                    1 => (x - (width - 2f), y),
                    2 => (1f - y, x),
                    _ => (y - (height - 2f), x),
                };
                if (outward >= -pad && along >= oe.Low - pad && along <= oe.High + pad)
                {
                    oceanElev = oe.Elev;
                    return true;
                }
            }
            if (oceanEdges.Count >= 2)
            {
                for (int i = 0; i < oceanEdges.Count; i++)
                {
                    for (int j = i + 1; j < oceanEdges.Count; j++)
                    {
                        int e0 = oceanEdges[i].Edge;
                        int e1 = oceanEdges[j].Edge;
                        if ((e0 < 2) == (e1 < 2))
                            continue;
                        int xEdge = e0 < 2 ? e0 : e1;
                        int yEdge = e0 < 2 ? e1 : e0;
                        bool outX = xEdge == 0 ? x <= 1f + pad : x >= width - 2f - pad;
                        bool outY = yEdge == 2 ? y <= 1f + pad : y >= height - 2f - pad;
                        if (outX && outY)
                        {
                            oceanElev = oceanEdges[i].Elev;
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        (float Dist, float Elev) NearestStreetInfo(float x, float y)
        {
            if (streets.Count == 0)
                return (999f, medianPerimeterElev);

            float bestDist = 999f;
            float bestElev = medianPerimeterElev;
            for (int i = 0; i < streets.Count; i++)
            {
                var st = streets[i];
                (float outward, float along) = st.Edge switch
                {
                    0 => (1f - x, y),
                    1 => (x - (width - 1f), y),
                    2 => (1f - y, x),
                    _ => (y - (height - 1f), x),
                };
                if (outward < -1f)
                    continue;
                float maxOut = st.Width is int w ? w : clampedMargin + 16f;
                float dOut = outward > maxOut ? outward - maxOut : (outward < 0f ? -outward : 0f);
                float dAlong = MathF.Max(0f, MathF.Abs(along - st.Along) - 0.5f);
                float d = MathF.Sqrt(dOut * dOut + dAlong * dAlong);
                if (d < bestDist)
                {
                    bestDist = d;
                    bestElev = st.Elev;
                }
            }
            return (bestDist, bestElev);
        }

        static float SampleArraySmooth(float[] arr, int minIdx, int maxIdx, int center, float radius)
        {
            if (radius <= 0.001f)
                return arr[Math.Clamp(center, minIdx, maxIdx)];
            int span = (int)MathF.Ceiling(radius);
            float sum = 0f;
            float weightSum = 0f;
            for (int k = -span; k <= span; k++)
            {
                float w = MathF.Max(0f, radius + 1f - Math.Abs(k));
                sum += arr[Math.Clamp(center + k, minIdx, maxIdx)] * w;
                weightSum += w;
            }
            return sum / weightSum;
        }

        uint houseSeed = unchecked((uint)(scene.House * 2654435761u));
        float phaseA = (houseSeed & 0xFFu) * 0.02454369f;
        float phaseB = ((houseSeed >> 8) & 0xFFu) * 0.02454369f;
        float phaseC = ((houseSeed >> 16) & 0xFFu) * 0.02454369f;

        (float Elev, float Grass) SurroundSample(int x, int y)
        {
            if (x >= 1 && x <= width - 1 && y >= 1 && y <= height - 1)
                return (LotElevAt(x, y), LotVertexAt(x, y).Grass ?? 127f);

            int bx = Math.Clamp(x, 1, width - 1);
            int by = Math.Clamp(y, 1, height - 1);
            int dxOut = x < 1 ? 1 - x : (x > width - 1 ? x - (width - 1) : 0);
            int dyOut = y < 1 ? 1 - y : (y > height - 1 ? y - (height - 1) : 0);

            float dist = MathF.Sqrt(dxOut * dxOut + dyOut * dyOut);
            float nearRadius = MathF.Min(18f, dist * 0.85f);
            const float regionalRadius = 24f;

            float smoothEdgeElev;
            float regionalElev;
            float smoothOutSlope;
            float smoothEdgeGrass;

            if (dyOut == 0)
            {
                float[] eArr = x < 1 ? leftElev : rightElev;
                float[] sArr = x < 1 ? leftSlope : rightSlope;
                float[] gArr = x < 1 ? leftGrass : rightGrass;
                smoothEdgeElev = SampleArraySmooth(eArr, 1, height - 1, by, nearRadius);
                regionalElev = SampleArraySmooth(eArr, 1, height - 1, by, regionalRadius);
                smoothOutSlope = SampleArraySmooth(sArr, 1, height - 1, by, MathF.Max(2f, nearRadius));
                smoothEdgeGrass = SampleArraySmooth(gArr, 1, height - 1, by, nearRadius);
            }
            else if (dxOut == 0)
            {
                float[] eArr = y < 1 ? topElev : bottomElev;
                float[] sArr = y < 1 ? topSlope : bottomSlope;
                float[] gArr = y < 1 ? topGrass : bottomGrass;
                smoothEdgeElev = SampleArraySmooth(eArr, 1, width - 1, bx, nearRadius);
                regionalElev = SampleArraySmooth(eArr, 1, width - 1, bx, regionalRadius);
                smoothOutSlope = SampleArraySmooth(sArr, 1, width - 1, bx, MathF.Max(2f, nearRadius));
                smoothEdgeGrass = SampleArraySmooth(gArr, 1, width - 1, bx, nearRadius);
            }
            else
            {
                float[] xEArr = x < 1 ? leftElev : rightElev;
                float[] xSArr = x < 1 ? leftSlope : rightSlope;
                float[] xGArr = x < 1 ? leftGrass : rightGrass;
                float[] yEArr = y < 1 ? topElev : bottomElev;
                float[] ySArr = y < 1 ? topSlope : bottomSlope;
                float[] yGArr = y < 1 ? topGrass : bottomGrass;
                int shiftY = y < 1 ? Math.Min(height - 1, 1 + dyOut / 2) : Math.Max(1, height - 1 - dyOut / 2);
                int shiftX = x < 1 ? Math.Min(width - 1, 1 + dxOut / 2) : Math.Max(1, width - 1 - dxOut / 2);
                float eX = SampleArraySmooth(xEArr, 1, height - 1, shiftY, nearRadius + 2f);
                float eY = SampleArraySmooth(yEArr, 1, width - 1, shiftX, nearRadius + 2f);
                float rX = SampleArraySmooth(xEArr, 1, height - 1, shiftY, regionalRadius);
                float rY = SampleArraySmooth(yEArr, 1, width - 1, shiftX, regionalRadius);
                float sX = SampleArraySmooth(xSArr, 1, height - 1, shiftY, nearRadius + 3f);
                float sY = SampleArraySmooth(ySArr, 1, width - 1, shiftX, nearRadius + 3f);
                float gX = SampleArraySmooth(xGArr, 1, height - 1, shiftY, nearRadius + 2f);
                float gY = SampleArraySmooth(yGArr, 1, width - 1, shiftX, nearRadius + 2f);
                float sumD = dxOut + dyOut;
                smoothEdgeElev = (dxOut * eX + dyOut * eY) / sumD;
                regionalElev = (dxOut * rX + dyOut * rY) / sumD;
                smoothOutSlope = (dxOut * sX + dyOut * sY) / sumD;
                smoothEdgeGrass = (dxOut * gX + dyOut * gY) / sumD;
            }

            float slopeCarry = smoothOutSlope * 4.5f * (1f - MathF.Exp(-dist / 4.5f));
            float farTarget = regionalElev * 0.80f + medianPerimeterElev * 0.20f;
            float settleT = 1f - MathF.Exp(-dist * dist / (42f * 42f));
            float elev = (smoothEdgeElev + slopeCarry) * (1f - settleT) + farTarget * settleT;

            var (streetDist, streetElev) = NearestStreetInfo(x, y);
            if (hasRealHeights && terrainType != 7)
            {
                float streetClear = SmoothStep(1.5f, 9f, streetDist);
                float hillRamp = SmoothStep(1.5f, 12f, dist) * streetClear;
                float hillAmp = terrainType == 1 ? 5f : 11f;
                float roll = hillAmp * (
                    0.65f * MathF.Sin(x * 0.115f + phaseA) * MathF.Cos(y * 0.105f + phaseB) +
                    0.35f * MathF.Sin((x * 0.68f - y * 0.82f) * 0.175f + phaseC));
                elev += roll * hillRamp;
            }

            if (NearOrInOcean(x, y, 4f, out float ocElev))
            {
                elev = ocElev;
            }
            else if (streetDist < 8f)
            {
                float lockT = SmoothStep(0f, 8f, streetDist);
                elev = streetElev + (elev - streetElev) * lockT;
            }

            float targetGrass = terrainType is 1 or 7
                ? 255f
                : Math.Clamp(meanPerimeterGrass + 14f * MathF.Sin(x * 0.19f + phaseB) * MathF.Cos(y * 0.17f + phaseA), 18f, 248f);
            float grassRamp = terrainType == 1 ? SmoothStep(0f, 2.5f, dist) : SmoothStep(0f, 12f, dist);
            float grass = smoothEdgeGrass + (targetGrass - smoothEdgeGrass) * grassRamp;
            return (elev, grass);
        }

        int camOrient = ((scene.CameraOrientation ?? 0) % 4 + 4) % 4;
        const float sunLatitude = 0.31415927f;
        float sunLongitude = camOrient switch
        {
            0 => MathF.PI * 0.25f,
            2 => MathF.PI * 0.75f,
            _ => MathF.PI * 1.25f,
        };
        float sunZ = MathF.Cos(sunLatitude);
        float sunX = MathF.Sin(sunLongitude) * MathF.Sin(sunLatitude);
        float sunY = -MathF.Cos(sunLongitude) * MathF.Sin(sunLatitude);

        float SlopeDotSqContinuous(float dx, float dy)
        {
            dx = Math.Clamp(dx, -5f, 5f);
            dy = Math.Clamp(dy, -5f, 5f);
            float dot = (2.82842712f * sunZ + dx * sunX + dy * sunY) / MathF.Sqrt(8f + dx * dx + dy * dy);
            return dot * dot;
        }

        Dictionary<(int X, int Y), (LotScene.TerrainVertex Vertex, float Depth)> pointCache = new();
        (LotScene.TerrainVertex Vertex, float Depth) Point(int x, int y)
        {
            if (pointCache.TryGetValue((x, y), out var cached))
                return cached;

            int bx = Math.Clamp(x, 1, width - 1);
            int by = Math.Clamp(y, 1, height - 1);
            int dxOut = x < 1 ? 1 - x : (x > width - 1 ? x - (width - 1) : 0);
            int dyOut = y < 1 ? 1 - y : (y > height - 1 ? y - (height - 1) : 0);
            Vector2 cam = scene.Camera.CameraPoint(new Vector2(x, y), size);
            float depth = Math.Clamp(0.62f - 0.003f * (cam.X + cam.Y), 0.001f, 0.999f);

            LotScene.TerrainVertex edge = LotVertexAt(bx, by);
            if (dxOut == 0 && dyOut == 0)
            {
                var exact = (edge, depth);
                pointCache[(x, y)] = exact;
                return exact;
            }

            var (elev, grassVal) = SurroundSample(x, y);
            Vector2 projected = scene.Camera.ProjectedPoint(new Vector2(x, y), size);
            float vx = projected.X - originX;
            float vy = projected.Y - originY - elev;

            byte outR, outG, outB;
            byte? outDR, outDG, outDB, outGrass;
            float dist = MathF.Sqrt(dxOut * dxOut + dyOut * dyOut);

            if (hasRealHeights)
            {
                float hL = SurroundSample(x - 1, y).Elev / 7.5f;
                float hR = SurroundSample(x + 1, y).Elev / 7.5f;
                float hU = SurroundSample(x, y - 1).Elev / 7.5f;
                float hD = SurroundSample(x, y + 1).Elev / 7.5f;
                float dhx = (hL - hR) * 0.28f;
                float dhy = (hD - hU) * 0.28f;
                float dotSq = SlopeDotSqContinuous(dhx, dhy);

                uint hash = unchecked((uint)(x * 0x40de9 + y * 0x10dcd) ^ 0x40de9u);
                hash ^= hash >> 16;
                hash *= 0x7feb352du;
                hash ^= hash >> 15;
                int jitter = (int)Math.Min(hash % 3u, (hash >> 8) % 3u);
                if ((hash & 0x10000u) != 0)
                    jitter = -jitter;

                byte grassByte = (byte)Math.Clamp((int)MathF.Round(grassVal), 0, 255);
                float blend = grassByte / 255f;
                var lightBase = LerpColor(LightGreen[terrainType], LightBrown[terrainType], blend);
                var darkBase = LerpColor(DarkGreen[terrainType], DarkBrown[terrainType], blend);
                int vertexShade = Math.Clamp((int)((1f - dotSq) * 127f) + jitter, 0, 127);
                var shadedLight = LerpColor(lightBase, darkBase, vertexShade / 128f);

                float shadeBlend = SmoothStep(0f, 3f, dist);
                var finalLight = LerpColor((edge.R, edge.G, edge.B), shadedLight, shadeBlend);
                var edgeDark = (edge.DR ?? darkBase.R, edge.DG ?? darkBase.G, edge.DB ?? darkBase.B);
                var finalDark = LerpColor(edgeDark, darkBase, shadeBlend);
                byte finalGrass = (byte)Math.Clamp((int)MathF.Round((edge.Grass ?? grassByte) + (grassByte - (edge.Grass ?? grassByte)) * shadeBlend), 0, 255);

                outR = finalLight.R;
                outG = finalLight.G;
                outB = finalLight.B;
                outDR = finalDark.R;
                outDG = finalDark.G;
                outDB = finalDark.B;
                outGrass = finalGrass;
            }
            else
            {
                outR = edge.R;
                outG = edge.G;
                outB = edge.B;
                outDR = edge.DR;
                outDG = edge.DG;
                outDB = edge.DB;
                outGrass = edge.Grass;
            }

            var result = (new LotScene.TerrainVertex(vx, vy, outR, outG, outB, outDR, outDG, outDB, outGrass), depth);
            pointCache[(x, y)] = result;
            return result;
        }

        List<LotScene.TerrainVertex> terrain = [];
        List<float> depths = [];

        void EmitTri(int x0, int y0, int x1, int y1, int x2, int y2)
        {
            var p0 = Point(x0, y0);
            var p1 = Point(x1, y1);
            var p2 = Point(x2, y2);
            terrain.Add(p0.Vertex); depths.Add(p0.Depth);
            terrain.Add(p1.Vertex); depths.Add(p1.Depth);
            terrain.Add(p2.Vertex); depths.Add(p2.Depth);
        }

        void EmitCellQuad(int x0, int y0, int x1, int y1)
        {
            EmitTri(x0, y0, x1, y0, x1, y1);
            EmitTri(x1, y1, x0, y1, x0, y0);
        }

        int innerLo = -6;
        int innerHiX = (width + 7) & ~1;
        int innerHiY = (height + 7) & ~1;
        int outerLo = Math.Min(innerLo - 2, -((clampedMargin + 7) & ~1));
        int outerHiX = Math.Max(innerHiX + 2, (width + clampedMargin + 7) & ~1);
        int outerHiY = Math.Max(innerHiY + 2, (height + clampedMargin + 7) & ~1);

        for (int y = innerLo + 1; y < innerHiY - 1; y++)
        {
            for (int x = innerLo + 1; x < innerHiX - 1; x++)
            {
                if (x >= 1 && x < width - 1 && y >= 1 && y < height - 1)
                    continue;
                EmitCellQuad(x, y, x + 1, y + 1);
            }
        }

        for (int x = innerLo + 2; x <= innerHiX - 4; x += 2)
        {
            EmitTri(x, innerLo + 1, x, innerLo, x + 1, innerLo + 1);
            EmitTri(x + 1, innerLo + 1, x, innerLo, x + 2, innerLo);
            EmitTri(x + 1, innerLo + 1, x + 2, innerLo, x + 2, innerLo + 1);

            EmitTri(x, innerHiY - 1, x + 1, innerHiY - 1, x, innerHiY);
            EmitTri(x + 1, innerHiY - 1, x + 2, innerHiY, x, innerHiY);
            EmitTri(x + 1, innerHiY - 1, x + 2, innerHiY - 1, x + 2, innerHiY);
        }

        for (int y = innerLo + 2; y <= innerHiY - 4; y += 2)
        {
            EmitTri(innerLo + 1, y, innerLo + 1, y + 1, innerLo, y);
            EmitTri(innerLo + 1, y + 1, innerLo, y + 2, innerLo, y);
            EmitTri(innerLo + 1, y + 1, innerLo + 1, y + 2, innerLo, y + 2);

            EmitTri(innerHiX - 1, y, innerHiX, y, innerHiX - 1, y + 1);
            EmitTri(innerHiX - 1, y + 1, innerHiX, y, innerHiX, y + 2);
            EmitTri(innerHiX - 1, y + 1, innerHiX, y + 2, innerHiX - 1, y + 2);
        }

        EmitTri(innerLo, innerLo, innerLo + 2, innerLo, innerLo + 2, innerLo + 1);
        EmitTri(innerLo, innerLo, innerLo + 2, innerLo + 1, innerLo + 1, innerLo + 1);
        EmitTri(innerLo, innerLo, innerLo + 1, innerLo + 1, innerLo + 1, innerLo + 2);
        EmitTri(innerLo, innerLo, innerLo + 1, innerLo + 2, innerLo, innerLo + 2);

        EmitTri(innerHiX, innerLo, innerHiX, innerLo + 2, innerHiX - 1, innerLo + 2);
        EmitTri(innerHiX, innerLo, innerHiX - 1, innerLo + 2, innerHiX - 1, innerLo + 1);
        EmitTri(innerHiX, innerLo, innerHiX - 1, innerLo + 1, innerHiX - 2, innerLo + 1);
        EmitTri(innerHiX, innerLo, innerHiX - 2, innerLo + 1, innerHiX - 2, innerLo);

        EmitTri(innerLo, innerHiY, innerLo, innerHiY - 2, innerLo + 1, innerHiY - 2);
        EmitTri(innerLo, innerHiY, innerLo + 1, innerHiY - 2, innerLo + 1, innerHiY - 1);
        EmitTri(innerLo, innerHiY, innerLo + 1, innerHiY - 1, innerLo + 2, innerHiY - 1);
        EmitTri(innerLo, innerHiY, innerLo + 2, innerHiY - 1, innerLo + 2, innerHiY);

        EmitTri(innerHiX, innerHiY, innerHiX - 2, innerHiY, innerHiX - 2, innerHiY - 1);
        EmitTri(innerHiX, innerHiY, innerHiX - 2, innerHiY - 1, innerHiX - 1, innerHiY - 1);
        EmitTri(innerHiX, innerHiY, innerHiX - 1, innerHiY - 1, innerHiX - 1, innerHiY - 2);
        EmitTri(innerHiX, innerHiY, innerHiX - 1, innerHiY - 2, innerHiX, innerHiY - 2);

        for (int y = outerLo; y < outerHiY; y += 2)
        {
            for (int x = outerLo; x < outerHiX; x += 2)
            {
                if (x >= innerLo && x < innerHiX && y >= innerLo && y < innerHiY)
                    continue;
                EmitCellQuad(x, y, x + 2, y + 2);
            }
        }

        Terrain = terrain;
        Depths = [.. depths];

        if (scene.Scenery is not { Count: > 0 } prototypes || terrainType == 7)
        {
            Decorations = [];
            SceneryInstances = [];
            return;
        }

        IReadOnlyList<LotScene.SceneryType>? prototypeTypes = scene.SceneryTypes;
        List<(IReadOnlyList<LotScene.Sprite> Sprites, uint Guid, string Name)> treeProtos = [];
        List<(IReadOnlyList<LotScene.Sprite> Sprites, uint Guid, string Name)> shrubProtos = [];
        for (int i = 0; i < prototypes.Count; i++)
        {
            var group = prototypes[i];
            if (group.Count == 0)
                continue;
            uint protoGuid = prototypeTypes is not null && i < prototypeTypes.Count ? prototypeTypes[i].Guid : 0u;
            string protoName = prototypeTypes is not null && i < prototypeTypes.Count ? prototypeTypes[i].Name : string.Empty;
            float minY = float.MaxValue;
            float maxY = float.MinValue;
            for (int s = 0; s < group.Count; s++)
            {
                if (group[s].Y < minY) minY = group[s].Y;
                if (group[s].Y + group[s].Height > maxY) maxY = group[s].Y + group[s].Height;
            }
            if (maxY - minY >= 80f)
                treeProtos.Add((group, protoGuid, protoName));
            else
                shrubProtos.Add((group, protoGuid, protoName));
        }

        if (treeProtos.Count == 0)
            treeProtos.AddRange(shrubProtos);

        static int FloorDiv(int a, int b) => (int)Math.Floor((double)a / b);

        float LotBoundaryDist(float x, float y)
        {
            float dx = x < 1f ? 1f - x : (x > width - 1f ? x - (width - 1f) : 0f);
            float dy = y < 1f ? 1f - y : (y > height - 1f ? y - (height - 1f) : 0f);
            return MathF.Sqrt(dx * dx + dy * dy);
        }

        List<LotScene.Sprite> decorations = [];
        List<SimsNative.Plugins.PluginSceneryInstance> sceneryInstances = [];
        List<(int X, int Y)> placedPositions = [];

        bool NearExistingFlora(int x, int y, int minDistSq)
        {
            for (int i = 0; i < placedPositions.Count; i++)
            {
                int dx = x - placedPositions[i].X;
                int dy = y - placedPositions[i].Y;
                if (dx * dx + dy * dy < minDistSq)
                    return true;
            }
            return false;
        }

        void PlacePrototype((IReadOnlyList<LotScene.Sprite> Sprites, uint Guid, string Name) proto, int x, int y)
        {
            var group = proto.Sprites;
            placedPositions.Add((x, y));
            if (proto.Guid != 0u || proto.Name.Length > 0)
                sceneryInstances.Add(new SimsNative.Plugins.PluginSceneryInstance(proto.Guid, proto.Name, x, y));
            (LotScene.TerrainVertex ground, _) = Point(x, y);
            Vector2 cam = scene.Camera.CameraPoint(new Vector2(x, y), size);
            Vector2 flat = scene.Camera.ProjectedPoint(new Vector2(x, y), size);
            float altitude = (flat.Y - originY - ground.Y) / 40f;
            float baseDepth = 0.62f - 0.003f * (cam.X + cam.Y + altitude * 0.8f);
            for (int s = 0; s < group.Count; s++)
            {
                LotScene.Sprite sprite = group[s];
                float? depthNear = sprite.DepthNear is float dn ? Math.Clamp(dn + baseDepth, 0.001f, 0.999f) : null;
                float? depthFar = sprite.DepthFar is float df ? Math.Clamp(df + baseDepth, 0.001f, 0.999f) : null;
                decorations.Add(new LotScene.Sprite
                {
                    Texture = sprite.Texture,
                    X = ground.X + sprite.X,
                    Y = ground.Y + sprite.Y,
                    Width = sprite.Width,
                    Height = sprite.Height,
                    Flip = sprite.Flip,
                    ObjectID = 0,
                    Layer = 1,
                    Level = 1,
                    Room = sprite.Room ?? 255,
                    Depth = cam.X + cam.Y + (sprite.Depth ?? 0f),
                    DepthTexture = sprite.DepthTexture,
                    DepthNear = depthNear,
                    DepthFar = depthFar,
                    Near = sprite.Near,
                    Far = sprite.Far,
                    Shadow = sprite.Shadow,
                    ShadowBrightness = sprite.ShadowBrightness,
                    FloorShadow = sprite.FloorShadow,
                    FloorShadowNear = sprite.FloorShadowNear,
                    FloorShadowFar = sprite.FloorShadowFar,
                });
            }
        }

        int treeDensityPct = terrainType == 1
            ? 42
            : (scene.House is (>= 20 and <= 27) or 30 ? 46 : (scene.House is >= 81 and <= 89 ? 58 : 64));

        const int treeCell = 6;
        int gridStartX = FloorDiv(outerLo, treeCell) * treeCell;
        int gridStartY = FloorDiv(outerLo, treeCell) * treeCell;
        for (int cy = gridStartY; cy <= outerHiY; cy += treeCell)
        {
            for (int cx = gridStartX; cx <= outerHiX; cx += treeCell)
            {
                int patchX = FloorDiv(cx, 18);
                int patchY = FloorDiv(cy, 18);
                uint patch = unchecked((uint)(patchX * 19349663 ^ patchY * 83492791 ^ scene.House * 73856093));
                uint seed = unchecked((uint)(cx * 73856093 ^ cy * 19349663 ^ scene.House * 83492791));
                seed ^= seed >> 13;
                seed *= 0x5bd1e995u;
                seed ^= seed >> 15;

                int groveBoost = (patch % 100 < 72) ? 12 : -14;
                if ((int)(seed % 100u) >= treeDensityPct + groveBoost)
                    continue;

                int x = cx + (int)((seed >> 4) % 5u);
                int y = cy + (int)((seed >> 9) % 5u);
                float lotDist = LotBoundaryDist(x, y);
                if (lotDist < 3.6f)
                    continue;
                if (NearestStreetInfo(x, y).Dist < 4.2f || NearOrInOcean(x, y, 2.5f, out _))
                    continue;

                var chosenTree = treeProtos[(int)((seed >> 16) % (uint)treeProtos.Count)];
                PlacePrototype(chosenTree, x, y);

                if (shrubProtos.Count > 0 && ((seed >> 22) % 100u) < 55u)
                {
                    int angleIdx = (int)((seed >> 26) & 3u);
                    (int ox, int oy) = angleIdx switch
                    {
                        0 => (2, 1),
                        1 => (-2, 1),
                        2 => (1, -2),
                        _ => (-1, 2),
                    };
                    int sx = x + ox;
                    int sy = y + oy;
                    if (!NearExistingFlora(sx, sy, 4) && LotBoundaryDist(sx, sy) >= 2.0f && NearestStreetInfo(sx, sy).Dist >= 3.0f && !NearOrInOcean(sx, sy, 2.0f, out _))
                    {
                        var companion = shrubProtos[(int)((seed >> 19) % (uint)shrubProtos.Count)];
                        PlacePrototype(companion, sx, sy);
                    }
                }
            }
        }

        if (shrubProtos.Count > 0)
        {
            const int shrubCell = 5;
            int sStartX = FloorDiv(outerLo, shrubCell) * shrubCell;
            int sStartY = FloorDiv(outerLo, shrubCell) * shrubCell;
            for (int cy = sStartY; cy <= outerHiY; cy += shrubCell)
            {
                for (int cx = sStartX; cx <= outerHiX; cx += shrubCell)
                {
                    uint seed = unchecked((uint)((cx + 37) * 83492791 ^ (cy - 19) * 73856093 ^ scene.House * 19349663));
                    seed ^= seed >> 15;
                    seed *= 0x27d4eb2du;
                    seed ^= seed >> 15;

                    int x = cx + (int)(seed % 4u);
                    int y = cy + (int)((seed >> 6) % 4u);
                    float lotDist = LotBoundaryDist(x, y);
                    if (lotDist < 2.0f)
                        continue;
                    int chance = lotDist < 5.5f ? 38 : 22;
                    if ((int)((seed >> 12) % 100u) >= chance)
                        continue;
                    if (NearExistingFlora(x, y, 4) || NearestStreetInfo(x, y).Dist < 3.0f || NearOrInOcean(x, y, 2.0f, out _))
                        continue;

                    var shrub = shrubProtos[(int)((seed >> 20) % (uint)shrubProtos.Count)];
                    PlacePrototype(shrub, x, y);
                }
            }
        }

        decorations.Sort(static (a, b) => (a.Depth ?? 0f).CompareTo(b.Depth ?? 0f));
        Decorations = decorations;
        SceneryInstances = sceneryInstances;
    }
}
