using System.Text;
using System.Text.Json;
using SimsEngine.Formats;
using SimsEngine.World;
using SimsSimulation;
using Xunit;

namespace SimsEngine.Tests;

public class CutawayVisibilityTests
{
    private static IffFile CreateLotWithIndoorAndOutdoorRooms(int lotSize = 64)
    {
        byte[] Layer(int size, Func<int, int, byte[]> value)
        {
            var body = new ChunkBuilder().S16(0).S16(0).S32(lotSize).S32(lotSize).S32(size).U32(0);
            for (var x = 0; x < lotSize; x++)
            for (var y = 0; y < lotSize; y++) body.Raw(value(x, y));
            return body.ToArray();
        }

        byte[] Walls(int x, int y)
        {
            byte bits = 0;
            if (y >= 10 && y <= 15)
            {
                if (x == 10 || x == 16) bits |= 1;
                if (x == 9 || x == 15) bits |= 4;
            }
            if (x >= 10 && x <= 15)
            {
                if (y == 10 || y == 16) bits |= 2;
                if (y == 9 || y == 15) bits |= 8;
            }
            return [bits, 0x0f, 1, 1, 0, 0, 0, 0];
        }

        return new IffFile(ChunkBuilder.File(
            ("Arry", 0, Layer(4, (_, _) => [0, 0, 0, 0])),
            ("Arry", 1, Layer(1, (_, _) => [0])),
            ("Arry", 2, Layer(8, Walls)),
            ("Arry", 8, Layer(1, (x, y) => [x >= 10 && x <= 15 && y >= 10 && y <= 15 ? (byte)0x10 : (byte)0x14]))), "cutaway_lot.iff");
    }

    private static IffFile CreateLotWithWallStyle(byte wallStyle, int width = 4, int height = 2)
    {
        var wallBody = new ChunkBuilder().S16(0).S16(0).S32(width).S32(height).S32(8).U32(0);
        for (var x = 0; x < width; x++)
        for (var y = 0; y < height; y++)
        {
            byte segments = x switch
            {
                1 => 4,
                2 => 1,
                _ => 0
            };
            wallBody.Raw([segments, 0x0f, wallStyle, 0, 0, 0, 0, 0]);
        }
        return new IffFile(ChunkBuilder.File(("Arry", 2, wallBody.ToArray())), "style_lot.iff");
    }

    [Fact]
    public void CutawayRoomMaskComputesBitmaskForSelectedIndoorRooms()
    {
        var lot = CreateLotWithIndoorAndOutdoorRooms();
        var map = RoomMap.Build(lot, 1, 64, 64);
        var camera = new LotCamera(0, 64, 64);

        var indoorRoom = map.RoomAt(12, 12);
        Assert.False(map.IsOutside(indoorRoom));

        var outdoorRoom = map.RoomAt(0, 0);
        Assert.True(map.IsOutside(outdoorRoom));

        var mask = SceneExporter.CutawayMatrix(map, camera, 64, [indoorRoom], []);
        Assert.True(mask[12 * 64 + 12]);
        Assert.False(mask[0 * 64 + 0]);

        var outdoorMask = SceneExporter.CutawayMatrix(map, camera, 64, [outdoorRoom], []);
        Assert.False(outdoorMask[0 * 64 + 0]);

        var extraMask = SceneExporter.CutawayMatrix(map, camera, 64, [], [(5, 5)]);
        Assert.True(extraMask[5 * 64 + 5]);
    }

    [Fact]
    public void WallCutawayMaskTransitionsAndMaskId()
    {
        Assert.Equal(2, SceneExporter.WallMaskId(1, down: false, zoom: 0));
        Assert.Equal(3, SceneExporter.WallMaskId(1, down: true, zoom: 0));
        Assert.Equal(4, SceneExporter.WallMaskId(2, down: false, zoom: 0));

        Assert.Equal(514, SceneExporter.WallMaskId(1, down: false, zoom: 1));
        Assert.Equal(515, SceneExporter.WallMaskId(1, down: true, zoom: 1));
        Assert.Equal(516, SceneExporter.WallMaskId(2, down: false, zoom: 1));
        Assert.Equal(517, SceneExporter.WallMaskId(2, down: true, zoom: 1));
        Assert.Equal(536, SceneExporter.WallMaskId(12, down: false, zoom: 1));
        Assert.Equal(538, SceneExporter.WallMaskId(13, down: false, zoom: 1));
        Assert.Equal(540, SceneExporter.WallMaskId(14, down: false, zoom: 1));

        Assert.Equal(1026, SceneExporter.WallMaskId(1, down: false, zoom: 2));
        Assert.Equal(1027, SceneExporter.WallMaskId(1, down: true, zoom: 2));

        Assert.Equal(58, SceneExporter.CutawayStoryPixels(1));
        Assert.Equal(116, SceneExporter.CutawayStoryPixels(2));
        Assert.Equal(232, SceneExporter.CutawayStoryPixels(3));
    }

    [Fact]
    public void OutdoorCutawayGeneratesFiveByFiveBlockAroundSim()
    {
        var camera = new LotCamera(0, 64, 64);
        var simX = 20;
        var simY = 25;
        var lotSize = 64;

        var tiles = SceneExporter.CutawayRectangle(camera, simX, simY, lotSize).ToList();

        Assert.Equal(25, tiles.Count);

        foreach (var (x, y) in tiles)
        {
            Assert.InRange(x, 0, lotSize - 1);
            Assert.InRange(y, 0, lotSize - 1);
        }

        var lot = CreateLotWithIndoorAndOutdoorRooms();
        var map = RoomMap.Build(lot, 1, 64, 64);
        var mask = SceneExporter.CutawayMatrix(map, camera, lotSize, [], tiles);
        foreach (var (x, y) in tiles)
        {
            Assert.True(mask[y * lotSize + x]);
        }

        var edgeTiles = SceneExporter.CutawayRectangle(camera, 62, 62, lotSize).ToList();
        Assert.NotEmpty(edgeTiles);
        foreach (var (x, y) in edgeTiles)
        {
            Assert.InRange(x, 0, lotSize - 1);
            Assert.InRange(y, 0, lotSize - 1);
        }

        var rotatedCamera = new LotCamera(1, 64, 64);
        var rotatedTiles = SceneExporter.CutawayRectangle(rotatedCamera, simX, simY, lotSize).ToList();
        Assert.Equal(25, rotatedTiles.Count);
        foreach (var (x, y) in rotatedTiles)
        {
            Assert.InRange(x, 0, lotSize - 1);
            Assert.InRange(y, 0, lotSize - 1);
        }
    }

    [Theory]
    [InlineData(2, true)]
    [InlineData(14, true)]
    [InlineData(12, true)]
    [InlineData(13, true)]
    [InlineData(1, false)]
    [InlineData(5, false)]
    [InlineData(20, false)]
    public void WallPatternAndStyleCutawayExemptions(byte style, bool isExempt)
    {
        var normalized = SceneExporter.NormalizedWallStyle(style);
        if (isExempt)
        {
            Assert.Equal(style, normalized);
        }
        else
        {
            Assert.Equal(1, normalized);
        }

        var lot = CreateLotWithWallStyle(style);
        var map = RoomMap.Build(lot, 1, 4, 2);
        if (isExempt)
        {
            Assert.Equal(1, map.RoomCount);
        }
        else
        {
            Assert.Equal(2, map.RoomCount);
        }
    }

    [Fact]
    public void CutawayWallAdjacentTilesCondition()
    {
        var lot = CreateLotWithIndoorAndOutdoorRooms();
        var map = RoomMap.Build(lot, 1, 64, 64);
        var camera = new LotCamera(0, 64, 64);

        var indoorRoom = map.RoomAt(12, 12);
        var mask = SceneExporter.CutawayMatrix(map, camera, 64, [indoorRoom], []);

        int inX1 = 12, inY1 = 12;
        int inX2 = 13, inY2 = 12;
        Assert.True(mask[inY1 * 64 + inX1] && mask[inY2 * 64 + inX2]);

        int boundInX = 10, boundInY = 12;
        int boundOutX = 9, boundOutY = 12;
        Assert.True(mask[boundInY * 64 + boundInX]);
        Assert.False(mask[boundOutY * 64 + boundOutX]);
        Assert.False(mask[boundInY * 64 + boundInX] && mask[boundOutY * 64 + boundOutX]);

        int outX1 = 5, outY1 = 5;
        int outX2 = 6, outY2 = 5;
        Assert.False(mask[outY1 * 64 + outX1] && mask[outY2 * 64 + outX2]);
    }

    [Fact]
    public void CutawayProbeRoomFindsAdjacentRoom()
    {
        var lot = CreateLotWithIndoorAndOutdoorRooms();
        var map = RoomMap.Build(lot, 1, 64, 64);
        var camera = new LotCamera(0, 64, 64);

        var indoorRoom = map.RoomAt(12, 12);
        var outdoorRoom = map.RoomAt(0, 0);

        var probed = SceneExporter.CutawayProbeRoom(map, camera, 64, 15, 12, zoom: 2);
        Assert.True(probed == indoorRoom || probed == outdoorRoom);
    }

    [Fact]
    public void ComputeCutawayMask_RaiseHoveredWalls_RaisesContiguousExteriorAndInteriorWalls()
    {
        const int lotSize = 64;
        byte[] Layer(int size, Func<int, int, byte[]> value)
        {
            var body = new ChunkBuilder().S16(0).S16(0).S32(lotSize).S32(lotSize).S32(size).U32(0);
            for (var x = 0; x < lotSize; x++)
            for (var y = 0; y < lotSize; y++) body.Raw(value(x, y));
            return body.ToArray();
        }

        byte[] Walls(int x, int y)
        {
            byte bits = 0;
            if (y >= 10 && y <= 19)
            {
                if (x is 10 or 15 or 20) bits |= 1;
                if (x is 9 or 14 or 19) bits |= 4;
            }
            if (x >= 10 && x <= 19)
            {
                if (y is 10 or 20) bits |= 2;
                if (y is 9 or 19) bits |= 8;
            }
            if ((x, y) is (25, 25) or (26, 26) or (27, 27))
                bits |= 0x20;
            if ((x, y) is (35, 37) or (36, 36) or (37, 35))
                bits |= 0x10;
            return [bits, 0x0f, 1, 1, 0, 0, 0, 0];
        }

        var lot = new IffFile(ChunkBuilder.File(
            ("Arry", 0, Layer(4, (_, _) => [0, 0, 0, 0])),
            ("Arry", 1, Layer(1, (_, _) => [0])),
            ("Arry", 2, Layer(8, Walls)),
            ("Arry", 8, Layer(1, (x, y) => [x >= 10 && x <= 19 && y >= 10 && y <= 19 ? (byte)0x10 : (byte)0x14]))),
            "wallpaper_cutaway_lot.iff");

        var rooms = RoomMap.Build(lot, 1, lotSize, lotSize);
        var wallsArray = LotArray.Read(lot, lot.Find(ResourceType.Parse("Arry"), 2)!);
        var heights = new float[lotSize * lotSize];

        var leftRoom = rooms.RoomAt(12, 14);
        var rightRoom = rooms.RoomAt(17, 14);
        Assert.NotEqual(leftRoom, rightRoom);
        Assert.False(rooms.IsOutside(leftRoom));
        Assert.False(rooms.IsOutside(rightRoom));

        static bool IsCutawayPair(bool[] mask, int x1, int y1, int x2, int y2) =>
            mask[y1 * lotSize + x1] && mask[y2 * lotSize + x2];

        for (var orientation = 0; orientation < 4; orientation++)
        {
            var camera = new LotCamera(orientation, lotSize, lotSize);
            var baseline = SceneExporter.ComputeCutawayMask(
                rooms, camera, lotSize, "cutaway",
                cutawayTile: (12, 14),
                cutawayRooms: [leftRoom, rightRoom],
                cutawaySim: null, cutawayZoom: 2,
                heights: heights, baseHeight: 0f,
                raiseHoveredWalls: false, viewLevelWalls: wallsArray);
            Assert.NotNull(baseline);

            // Find contiguous cutaway exterior wall edges (x=20 for orientation 0, x=9 for orientation 2, etc.)
            var frontExteriorTiles = new List<(int FrontX, int FrontY, int BackX, int BackY)>();
            for (var v = 1; v < lotSize; v++)
            for (var u = 1; u < lotSize; u++)
            {
                var (sx, sy) = camera.SourceTile(u, v);
                foreach (var (nx, ny) in new[] { camera.SourceTile(u - 1, v), camera.SourceTile(u, v - 1) })
                {
                    if ((uint)sx >= lotSize || (uint)sy >= lotSize || (uint)nx >= lotSize || (uint)ny >= lotSize)
                        continue;
                    var (ox, oy, side) = SceneExporter.EdgeOwner(sx, sy, nx, ny);
                    if ((wallsArray.Element(ox, oy)[0] & (side == 0 ? 1 : 2)) == 0)
                        continue;
                    if (rooms.IsOutside(rooms.RoomAt(sx, sy)) && !rooms.IsOutside(rooms.RoomAt(nx, ny)) &&
                        IsCutawayPair(baseline!, sx, sy, nx, ny))
                    {
                        frontExteriorTiles.Add((sx, sy, nx, ny));
                    }
                }
            }
            Assert.True(frontExteriorTiles.Count >= 4);

            // Group by constant X or Y run to pick a long straight exterior wall run.
            var xRun = frontExteriorTiles.GroupBy(e => (IsVertical: true, Coord: e.FrontX, BackCoord: e.BackX))
                .OrderByDescending(g => g.Count()).First();
            var yRun = frontExteriorTiles.GroupBy(e => (IsVertical: false, Coord: e.FrontY, BackCoord: e.BackY))
                .OrderByDescending(g => g.Count()).First();
            var selectedRun = (xRun.Count() >= yRun.Count() ? xRun.ToList() : yRun.ToList());
            Assert.True(selectedRun.Count >= 4);

            var hoverExt = selectedRun[selectedRun.Count / 2];
            var raisedExtMask = SceneExporter.ComputeCutawayMask(
                rooms, camera, lotSize, "cutaway",
                cutawayTile: (hoverExt.FrontX, hoverExt.FrontY),
                cutawayRooms: [leftRoom, rightRoom],
                cutawaySim: null, cutawayZoom: 2,
                heights: heights, baseHeight: 0f,
                raiseHoveredWalls: true, viewLevelWalls: wallsArray);
            Assert.NotNull(raisedExtMask);
            foreach (var seg in selectedRun)
                Assert.False(IsCutawayPair(raisedExtMask!, seg.FrontX, seg.FrontY, seg.BackX, seg.BackY));

            // Hovering open indoor floor leaves front exterior walls cut down.
            var floorHoverMask = SceneExporter.ComputeCutawayMask(
                rooms, camera, lotSize, "cutaway",
                cutawayTile: (12, 14),
                cutawayRooms: [leftRoom, rightRoom],
                cutawaySim: null, cutawayZoom: 2,
                heights: heights, baseHeight: 0f,
                raiseHoveredWalls: true, viewLevelWalls: wallsArray);
            Assert.NotNull(floorHoverMask);
            Assert.True(IsCutawayPair(floorHoverMask!, hoverExt.FrontX, hoverExt.FrontY, hoverExt.BackX, hoverExt.BackY));

            // Hovering interior partition wall raises the partition while keeping closer front exterior walls cut down.
            var partU = camera.CameraPoint(15.5f, 14.5f);
            var partV = camera.CameraPoint(14.5f, 14.5f);
            var (partFrontX, partFrontY, partBackX, partBackY) =
                partU.X + partU.Y > partV.X + partV.Y ? (15, 14, 14, 14) : (14, 14, 15, 14);
            Assert.True(IsCutawayPair(baseline!, partFrontX, partFrontY, partBackX, partBackY));

            var raisedPartMask = SceneExporter.ComputeCutawayMask(
                rooms, camera, lotSize, "cutaway",
                cutawayTile: (partFrontX, partFrontY),
                cutawayRooms: [leftRoom, rightRoom],
                cutawaySim: null, cutawayZoom: 2,
                heights: heights, baseHeight: 0f,
                raiseHoveredWalls: true, viewLevelWalls: wallsArray);
            Assert.NotNull(raisedPartMask);
            Assert.False(IsCutawayPair(raisedPartMask!, partFrontX, partFrontY, partBackX, partBackY));
            Assert.False(IsCutawayPair(raisedPartMask!, partFrontX, 12, partBackX, 12));
            Assert.True(IsCutawayPair(raisedPartMask!, hoverExt.FrontX, hoverExt.FrontY, hoverExt.BackX, hoverExt.BackY));

            // Diagonal wall run inside outdoor cutaway box stands up when hovered with raiseHoveredWalls: true.
            var outsideRoom = rooms.RoomAt(0, 0);
            Assert.True(rooms.IsOutside(outsideRoom));
            (int X, int Y)[] diagRun = orientation % 2 == 0
                ? [(25, 25), (26, 26), (27, 27)]
                : [(35, 37), (36, 36), (37, 35)];
            var diagHover = orientation switch
            {
                0 => (25, 25),
                1 => (35, 37),
                2 => (27, 27),
                _ => (37, 35),
            };
            var diagBaseline = SceneExporter.ComputeCutawayMask(
                rooms, camera, lotSize, "cutaway",
                cutawayTile: diagHover,
                cutawayRooms: [outsideRoom],
                cutawaySim: null, cutawayZoom: 2,
                heights: heights, baseHeight: 0f,
                raiseHoveredWalls: false, viewLevelWalls: wallsArray);
            Assert.NotNull(diagBaseline);
            foreach (var dt in diagRun)
                Assert.True(diagBaseline![dt.Y * lotSize + dt.X]);

            var diagRaised = SceneExporter.ComputeCutawayMask(
                rooms, camera, lotSize, "cutaway",
                cutawayTile: diagHover,
                cutawayRooms: [outsideRoom],
                cutawaySim: null, cutawayZoom: 2,
                heights: heights, baseHeight: 0f,
                raiseHoveredWalls: true, viewLevelWalls: wallsArray);
            Assert.NotNull(diagRaised);
            foreach (var dt in diagRun)
                Assert.False(diagRaised![dt.Y * lotSize + dt.X]);
        }
    }
}

[Collection("Neighborhoods")]
public sealed class CutawayVisibilityServerTests
{
    private static JsonElement[] DrainEvents(MemoryStream outputStream, StreamWriter writer)
    {
        writer.Flush();
        var text = Encoding.UTF8.GetString(outputStream.GetBuffer(), 0, (int)outputStream.Length);
        outputStream.SetLength(0);
        outputStream.Position = 0;
        return text
            .Split('\n', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries)
            .Select(line => JsonDocument.Parse(line).RootElement.Clone())
            .ToArray();
    }

    private static JsonElement ResponseFor(JsonElement[] events, string id) =>
        events.Single(e => e.TryGetProperty("id", out var idEl) && idEl.GetString() == id);

    private static (string TempRoot, string Profile, string Session) CreateIsolatedProfile(string gameDir, short house)
    {
        var tempRoot = Path.Combine(Path.GetTempPath(), "sims-cutaway-" + Guid.NewGuid().ToString("N"));
        var profile = Path.Combine(tempRoot, "runtime", "profiles", "test");
        var userData = Path.Combine(profile, "UserData");
        Directory.CreateDirectory(Path.Combine(userData, "Houses"));
        var charsDir = Path.Combine(userData, "Characters");
        Directory.CreateDirectory(charsDir);
        foreach (var charFile in Directory.EnumerateFiles(Path.Combine(gameDir, "UserData", "Characters")))
            File.Copy(charFile, Path.Combine(charsDir, Path.GetFileName(charFile)));
        File.Copy(Path.Combine(gameDir, "UserData", "Neighborhood.iff"), Path.Combine(userData, "Neighborhood.iff"));
        var src = Path.Combine(gameDir, "UserData", "Houses", $"House{house:D2}.iff");
        File.Copy(src, Path.Combine(userData, "Houses", $"House{house:D2}.iff"));
        var session = Path.Combine(tempRoot, "session");
        Directory.CreateDirectory(session);
        return (tempRoot, profile, session);
    }

    [Fact]
    public void SimulationServer_CutawayWallpaperTool_SkipsProbeRoomAndAvoidsReexportAlongRaisedWall()
    {
        var gameDir = TestGameLocator.Locate();
        var house05 = gameDir is null ? null : Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        if (gameDir is null || !File.Exists(house05) || !File.Exists(Path.Combine(gameDir, "UserData", "Neighborhood.iff")))
            return;

        var previousNeighborhood = Neighborhoods.Current;
        var (tempRoot, profile, session) = CreateIsolatedProfile(gameDir, 5);
        try
        {
            Neighborhoods.Current = 1;
            using var outputStream = new MemoryStream();
            using var writer = new StreamWriter(outputStream, new UTF8Encoding(false)) { AutoFlush = true };
            var server = SimulationServer.Load(gameDir, session, profile, 5, writer);
            DrainEvents(outputStream, writer);

            var lot = new IffFile(File.ReadAllBytes(house05!), "House05.iff");
            var walls = LotWalls.Read(lot, 1);
            var map = RoomMap.Build(lot, 1, 64, 64);
            var camera = new LotCamera(0, 64, 64);

            // Find an outdoor tile on a front exterior wall where CutawayProbeRoom returns an indoor room,
            // plus an adjacent tile on the same contiguous exterior wall run.
            (int X1, int Y1, int X2, int Y2, int IndoorX, int IndoorY)? pair = null;
            for (var x = 8; x < 55 && pair is null; x++)
            for (var y = 8; y < 55 && pair is null; y++)
            {
                var room1 = map.RoomAt(x, y);
                if (!map.IsOutside(room1)) continue;
                var probed = SceneExporter.CutawayProbeRoom(map, camera, 64, x, y, zoom: 2);
                if (probed == RoomMap.NoRoom || map.IsOutside(probed)) continue;

                // Front-left exterior wall (side 1 on (x, y) separating (x, y) outside from (x, y-1) indoor)
                if ((walls[x, y][0] & 2) != 0 && walls.GetStyle(x, y, 1) == 1 && !map.IsOutside(map.RoomAt(x, y - 1)) &&
                    map.IsOutside(map.RoomAt(x + 1, y)) && (walls[x + 1, y][0] & 2) != 0 && walls.GetStyle(x + 1, y, 1) == 1 &&
                    !map.IsOutside(map.RoomAt(x + 1, y - 1)))
                {
                    pair = (x, y, x + 1, y, x, y - 1);
                }
                // Front-right exterior wall (side 0 on (x, y) separating (x, y) outside from (x-1, y) indoor)
                else if ((walls[x, y][0] & 1) != 0 && walls.GetStyle(x, y, 0) == 1 && !map.IsOutside(map.RoomAt(x - 1, y)) &&
                    map.IsOutside(map.RoomAt(x, y + 1)) && (walls[x, y + 1][0] & 1) != 0 && walls.GetStyle(x, y + 1, 0) == 1 &&
                    !map.IsOutside(map.RoomAt(x - 1, y + 1)))
                {
                    pair = (x, y, x, y + 1, x - 1, y);
                }
            }
            Assert.NotNull(pair);

            Assert.True(server.Handle("""{"id":"wallsCut","op":"walls","mode":"cutaway"}"""));
            DrainEvents(outputStream, writer);
            Assert.True(server.Handle("""{"id":"viewEdit","op":"view","editing":true}"""));
            DrainEvents(outputStream, writer);
            Assert.True(server.Handle("""{"id":"wallCat","op":"buildCatalogPage","kind":"wall","offset":0,"count":8}"""));
            DrainEvents(outputStream, writer);

            // First hover the indoor room so the room cuts down, including the front exterior wall.
            Assert.True(server.Handle(JsonSerializer.Serialize(new
            {
                id = "cutIn",
                op = "cutaway",
                x = pair!.Value.IndoorX,
                y = pair.Value.IndoorY,
                zoom = 2,
                wallpaperTool = true,
            })));
            var eventsIn = DrainEvents(outputStream, writer);
            Assert.True(ResponseFor(eventsIn, "cutIn").GetProperty("ok").GetBoolean());

            // Now hover the front exterior wall tile with wallpaperTool: true -> raises wall run (emits frame).
            Assert.True(server.Handle(JsonSerializer.Serialize(new
            {
                id = "cut1",
                op = "cutaway",
                x = pair.Value.X1,
                y = pair.Value.Y1,
                zoom = 2,
                wallpaperTool = true,
            })));
            var events1 = DrainEvents(outputStream, writer);
            Assert.True(ResponseFor(events1, "cut1").GetProperty("ok").GetBoolean());
            var frame1 = events1.Single(e => e.TryGetProperty("type", out var t) && t.GetString() == "frame");
            var rev1 = frame1.GetProperty("revision").GetInt64();

            // Sliding along the same raised exterior wall run should match the cutaway mask and NOT re-export.
            Assert.True(server.Handle(JsonSerializer.Serialize(new
            {
                id = "cut2",
                op = "cutaway",
                x = pair.Value.X2,
                y = pair.Value.Y2,
                zoom = 2,
                wallpaperTool = true,
            })));
            var events2 = DrainEvents(outputStream, writer);
            Assert.True(ResponseFor(events2, "cut2").GetProperty("ok").GetBoolean());
            Assert.DoesNotContain(events2, e => e.TryGetProperty("type", out var t) && t.GetString() == "frame");

            // Disabling wallpaperTool at the same tile drops the hovered wall (triggers re-export).
            Assert.True(server.Handle(JsonSerializer.Serialize(new
            {
                id = "cutOff",
                op = "cutaway",
                x = pair.Value.X1,
                y = pair.Value.Y1,
                zoom = 2,
                wallpaperTool = false,
            })));
            var events3 = DrainEvents(outputStream, writer);
            Assert.True(ResponseFor(events3, "cutOff").GetProperty("ok").GetBoolean());
            var frame3 = events3.Single(e => e.TryGetProperty("type", out var t) && t.GetString() == "frame");
            Assert.True(frame3.GetProperty("revision").GetInt64() > rev1);
        }
        finally
        {
            Neighborhoods.Current = previousNeighborhood;
            if (Directory.Exists(tempRoot))
                Directory.Delete(tempRoot, recursive: true);
        }
    }
}
