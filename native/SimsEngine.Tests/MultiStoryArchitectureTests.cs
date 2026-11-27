using System.Numerics;
using System.Text;
using System.Text.Json;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;
using SimsSDL;
using SimsSDL.Core;
using SimsSimulation;
using Xunit;

namespace SimsEngine.Tests;

[Collection("Neighborhoods")]
public sealed class MultiStoryArchitectureTests
{
    private static string? LocateGameDirectory() => TestGameLocator.Locate();

    private static (string TempRoot, string Profile, string UserData, string Session) CreateIsolatedHouse05Profile(string gameDir)
    {
        var tempRoot = Path.Combine(Path.GetTempPath(), "sims-multistory-" + Guid.NewGuid().ToString("N"));
        var profile = Path.Combine(tempRoot, "runtime", "profiles", "test");
        var userData = Path.Combine(profile, "UserData");
        Directory.CreateDirectory(Path.Combine(userData, "Houses"));
        var charsDir = Path.Combine(userData, "Characters");
        Directory.CreateDirectory(charsDir);
        foreach (var charFile in Directory.EnumerateFiles(Path.Combine(gameDir, "UserData", "Characters")))
            File.Copy(charFile, Path.Combine(charsDir, Path.GetFileName(charFile)));

        File.Copy(Path.Combine(gameDir, "UserData", "Neighborhood.iff"), Path.Combine(userData, "Neighborhood.iff"));
        foreach (var extra in new[] { "LotZoning.iff", "LotLocations.iff", "StreetNames.iff" })
        {
            var extraPath = Path.Combine(gameDir, "UserData", extra);
            if (File.Exists(extraPath))
                File.Copy(extraPath, Path.Combine(userData, extra));
        }

        File.Copy(
            Path.Combine(gameDir, "UserData", "Houses", "House05.iff"),
            Path.Combine(userData, "Houses", "House05.iff"));

        var session = Path.Combine(tempRoot, "session");
        Directory.CreateDirectory(session);
        return (tempRoot, profile, userData, session);
    }

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

    private static void DismissBlockingDialogs(SimulationServer server, MemoryStream outputStream, StreamWriter writer)
    {
        var world = server.World;
        if (world is null) return;
        for (int guard = 0; guard < 16 && world.HasVisibleBlockingDialog; guard++)
        {
            var blocking = world.DialogRecords.FirstOrDefault(d => d.Visible && d.Blocking && d.State < 2);
            if (blocking is null) break;
            var reqId = $"dlg_{guard}_{blocking.Token}";
            Assert.True(server.Handle($$"""{"id":"{{reqId}}","op":"dialogResponse","token":"{{blocking.Token}}","code":0}"""));
            var resp = ResponseFor(DrainEvents(outputStream, writer), reqId);
            Assert.True(resp.GetProperty("ok").GetBoolean(), resp.GetRawText());
        }
    }

    private static int QueryFirstFloorPattern(SimulationServer server, MemoryStream outputStream, StreamWriter writer)
    {
        Assert.True(server.Handle("""{"id":"qFloor","op":"buildCatalogPage","kind":"floor","offset":0,"count":10}"""));
        var resp = ResponseFor(DrainEvents(outputStream, writer), "qFloor");
        Assert.True(resp.GetProperty("ok").GetBoolean(), resp.GetRawText());
        return resp.GetProperty("result").GetProperty("items")[0].GetProperty("id").GetInt32();
    }

    private static uint QueryFirstChairGuid(SimulationServer server, MemoryStream outputStream, StreamWriter writer)
    {
        Assert.True(server.Handle("""{"id":"qChair","op":"catalogPage","category":0,"offset":0,"count":20}"""));
        var resp = ResponseFor(DrainEvents(outputStream, writer), "qChair");
        Assert.True(resp.GetProperty("ok").GetBoolean(), resp.GetRawText());
        return resp.GetProperty("result").GetProperty("items")[0].GetProperty("guid").GetUInt32();
    }

    private static uint[] QueryStairGuids(SimulationServer server, MemoryStream outputStream, StreamWriter writer)
    {
        var guids = new List<uint>();
        Assert.True(server.Handle("""{"id":"qStairs","op":"catalogPage","category":10,"offset":0,"count":50}"""));
        var resp = ResponseFor(DrainEvents(outputStream, writer), "qStairs");
        Assert.True(resp.GetProperty("ok").GetBoolean(), resp.GetRawText());
        foreach (var item in resp.GetProperty("result").GetProperty("items").EnumerateArray())
        {
            var g = item.GetProperty("guid").GetUInt32();
            var name = item.TryGetProperty("name", out var nEl) ? (nEl.GetString() ?? "") : "";
            if (name.Contains("Teleport", StringComparison.OrdinalIgnoreCase))
                continue;
            if (g is 0x948AED3Cu or 0xBDCF6469u)
                guids.Insert(0, g);
            else
                guids.Add(g);
        }

        return guids.Distinct().ToArray();
    }

    [Fact]
    public void ClientSceneAndHud_SupportUpTo16StoriesAndPreserveClassic2StoryUi()
    {
        var terrainVerts = new LotScene.TerrainVertex[4 * 4 * 6];
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                int baseIdx = (y * 4 + x) * 6;
                float cx = 160f + (x - y) * 32f;
                float cy = 200f + (x + y) * 16f;
                terrainVerts[baseIdx + 0] = new LotScene.TerrainVertex(cx, cy, 0, 0, 0, 0, 0, 0, 0);
                terrainVerts[baseIdx + 1] = new LotScene.TerrainVertex(cx + 32f, cy + 16f, 0, 0, 0, 0, 0, 0, 0);
                terrainVerts[baseIdx + 2] = new LotScene.TerrainVertex(cx, cy + 32f, 0, 0, 0, 0, 0, 0, 0);
                terrainVerts[baseIdx + 3] = new LotScene.TerrainVertex(cx, cy + 32f, 0, 0, 0, 0, 0, 0, 0);
                terrainVerts[baseIdx + 4] = new LotScene.TerrainVertex(cx - 32f, cy + 16f, 0, 0, 0, 0, 0, 0, 0);
                terrainVerts[baseIdx + 5] = new LotScene.TerrainVertex(cx, cy, 0, 0, 0, 0, 0, 0, 0);
            }
        }

        var valid6 = JsonSerializer.Deserialize<LotScene>("""
        {
          "schemaVersion": 1,
          "house": 5,
          "width": 800,
          "height": 600,
          "viewLevel": 6,
          "stories": 6,
          "textures": [],
          "sprites": [],
          "limitations": []
        }
        """);
        Assert.NotNull(valid6);
        Assert.Equal(6, valid6!.ViewLevel);
        Assert.Equal(6, valid6.Stories);
        valid6.Validate();

        var valid16TwoBand = new LotScene
        {
            SchemaVersion = 1,
            House = 5,
            Width = 800,
            Height = 600,
            LotWidth = 4,
            LotHeight = 4,
            ViewLevel = 16,
            Stories = 16,
            Textures = [],
            Sprites = [],
            TerrainVertices = terrainVerts,
            Limitations = [],
            OverheadMap = new LotScene.OverheadMapData(32, 64, 8, new byte[32 * 64 * 4]),
        };
        valid16TwoBand.Validate();

        var invalid17 = JsonSerializer.Deserialize<LotScene>("""
        {
          "schemaVersion": 1,
          "house": 5,
          "width": 800,
          "height": 600,
          "viewLevel": 17,
          "stories": 17,
          "textures": [],
          "sprites": [],
          "limitations": []
        }
        """)!;
        Assert.Throws<ContentError>(() => invalid17.Validate());

        var preview = new PlacementPreview
        {
            SchemaVersion = 1,
            Valid = true,
            Status = "Success",
            Tiles = [new PlacementPreview.Tile(1, 1, 4), new PlacementPreview.Tile(1, 1, 6)],
        };
        var diamonds = preview.TileDiamonds(new LotScene
        {
            SchemaVersion = 1,
            House = 5,
            Width = 800,
            Height = 600,
            LotWidth = 4,
            LotHeight = 4,
            ViewLevel = 1,
            Stories = 6,
            Textures = [],
            Sprites = [],
            TerrainVertices = terrainVerts,
            Limitations = [],
        });
        Assert.Equal(2, diamonds.Count);
        Assert.Equal(232f - 3f * PlacementPreview.StoryLiftPerLevel, diamonds[0].Top.Y, 2);
        Assert.Equal(232f - 5f * PlacementPreview.StoryLiftPerLevel, diamonds[1].Top.Y, 2);

        var gameDir = LocateGameDirectory();
        if (gameDir is not null)
        {
            var ui = new LiveUI(new GameContent(gameDir));
            var logical = new CGSize(800, 600);
            ui.StoryCount = 2;
            Assert.Empty(ui.StoryStackSlices(logical));

            ui.StoryCount = 6;
            ui.ViewLevel = 3;
            ui.RoofsVisible = false;
            ui.SnapStoryStackExpansion(expanded: false);
            var restingSlices = ui.StoryStackSlices(logical);
            Assert.Equal(3, restingSlices.Count);
            var restingBounds = Assert.NotNull(ui.StoryStackBounds(logical, expanded: false));
            Assert.True(restingBounds.Height <= 28.0);
            var restDraws = ui.Draws(new Vector2(800, 600), 1f, speed: 0);
            var restMid = restingSlices[1];
            Assert.Contains(restDraws, d =>
                MathF.Abs(d.Rect.X - (float)restMid.Rect.MinX) < 0.01f &&
                MathF.Abs(d.Rect.Y - (float)restMid.Rect.MinY) < 0.01f &&
                MathF.Abs(d.UV.X - 0.25f) < 0.01f);

            ui.StoryStackExpanded = true;
            ui.AdvanceStoryStackAnimation(0.0);
            ui.AdvanceStoryStackAnimation(0.08);
            Assert.InRange(ui.StoryStackExpansion, 0.1f, 0.9f);
            var midAnimSlices = ui.StoryStackSlices(logical);
            Assert.Equal(6, midAnimSlices.Count);

            ui.SnapStoryStackExpansion(expanded: true);
            var expandedSlices = ui.StoryStackSlices(logical);
            Assert.Equal(6, expandedSlices.Count);
            Assert.Equal(6, expandedSlices[0].Level);
            Assert.Equal(1, expandedSlices[^1].Level);
            var expandedBounds = Assert.NotNull(ui.StoryStackBounds(logical, expanded: true));
            Assert.Equal(restingBounds.MaxY, expandedBounds.MaxY, 2);
            Assert.True(expandedBounds.MinY < restingBounds.MinY);
            var expDraws = ui.Draws(new Vector2(800, 600), 1f, speed: 0);
            var slice3 = expandedSlices.Single(s => s.Level == 3);
            Assert.Contains(expDraws, d =>
                MathF.Abs(d.Rect.X - (float)slice3.Rect.MinX) < 0.01f &&
                MathF.Abs(d.Rect.Y - (float)slice3.Rect.MinY) < 0.01f &&
                MathF.Abs(d.UV.X - 0.25f) < 0.01f);

            ui.StoryCount = 11;
            ui.SnapStoryStackExpansion(expanded: true);
            var slices11 = ui.StoryStackSlices(logical);
            Assert.Equal(11, slices11.Count);
            var slice11 = slices11[0];
            var slice11Mid = new CGPoint(slice11.Rect.MidX, slice11.Rect.MidY);
            Assert.Equal(11, slice11.Level);
            Assert.True(slice11Mid.Y < logical.Height - 150.0);
            Assert.True(ui.BlocksStoryStackEdgeScroll(slice11Mid, logical));
            Assert.True(ui.BlocksStoryStackEdgeScroll(new CGPoint(2.0, slice11Mid.Y), logical));
            Assert.False(ui.BlocksStoryStackEdgeScroll(new CGPoint(2.0, 40.0), logical));

            ui.SnapStoryStackExpansion(expanded: false);
            Assert.False(ui.BlocksStoryStackEdgeScroll(new CGPoint(2.0, slice11Mid.Y), logical));
        }
    }

    [Fact]
    public void SimulationServer_Progressive6StoryUnlock_2BandOverheadAndVoxelExport_AndDemolishCollapse()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null ||
            !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")) ||
            !File.Exists(Path.Combine(gameDir, "UserData", "Neighborhood.iff")))
            return;

        var previousNeighborhood = Neighborhoods.Current;
        var (tempRoot, profile, _, session) = CreateIsolatedHouse05Profile(gameDir);
        try
        {
            Neighborhoods.Current = 1;
            using var outputStream = new MemoryStream();
            using var writer = new StreamWriter(outputStream, new UTF8Encoding(false)) { AutoFlush = true };
            var server = SimulationServer.Load(gameDir, session, profile, 5, writer);
            DrainEvents(outputStream, writer);

            DismissBlockingDialogs(server, outputStream, writer);
            server.World!.FamilyBudget!.AlterFamilyBudget(0, -500000);

            Assert.True(server.Handle("""{"id":"s0","op":"state"}"""));
            var s0 = ResponseFor(DrainEvents(outputStream, writer), "s0").GetProperty("result");
            Assert.Equal(2, s0.GetProperty("stories").GetInt32());

            Assert.True(server.Handle("""{"id":"mBuild","op":"mode","mode":"build"}"""));
            DrainEvents(outputStream, writer);
            Assert.True(server.Handle("""{"id":"sBuild","op":"state"}"""));
            var sBuild = ResponseFor(DrainEvents(outputStream, writer), "sBuild").GetProperty("result");
            Assert.Equal(3, sBuild.GetProperty("stories").GetInt32());

            var l2Rooms = server.World.LotRoomMaps[2];
            int boxX = -1, boxY = -1;
            for (int x = 8; x < 54 && boxX < 0; x++)
            {
                for (int y = 8; y < 54 && boxX < 0; y++)
                {
                    var ok = true;
                    for (int dx = 0; dx < 4 && ok; dx++)
                    for (int dy = 0; dy < 4 && ok; dy++)
                    {
                        var rm = l2Rooms.RoomAt(x + dx, y + dy);
                        if (rm == RoomMap.NoRoom || l2Rooms.IsOutside(rm))
                            ok = false;
                    }
                    if (ok)
                    {
                        boxX = x;
                        boxY = y;
                    }
                }
            }
            Assert.True(boxX >= 0, "Expected at least one 4x4 indoor area on House05 floor 2.");

            var floorPattern = QueryFirstFloorPattern(server, outputStream, writer);
            var propGuid = QueryFirstChairGuid(server, outputStream, writer);

            for (int lvl = 3; lvl <= 6; lvl++)
            {
                Assert.True(server.Handle($$"""{"id":"lv{{lvl}}","op":"level","value":{{lvl}},"roofs":false}"""));
                DrainEvents(outputStream, writer);

                Assert.True(server.Handle($$"""{"id":"fl{{lvl}}","op":"architecture","command":"FLOOR_RECT","level":{{lvl}},"x":{{boxX}},"y":{{boxY}},"x2":3,"y2":3,"pattern":{{floorPattern}}}"""));
                var flResp = ResponseFor(DrainEvents(outputStream, writer), $"fl{lvl}");
                Assert.True(flResp.GetProperty("ok").GetBoolean(), flResp.GetRawText());
                Assert.True(flResp.GetProperty("result").GetProperty("changed").GetInt32() > 0);

                Assert.True(server.Handle($$"""{"id":"wl{{lvl}}","op":"architecture","command":"WALL_RECT","level":{{lvl}},"x":{{boxX}},"y":{{boxY}},"x2":4,"y2":4,"style":1,"pattern":0}"""));
                var wlResp = ResponseFor(DrainEvents(outputStream, writer), $"wl{lvl}");
                Assert.True(wlResp.GetProperty("ok").GetBoolean(), wlResp.GetRawText());
                Assert.True(wlResp.GetProperty("result").GetProperty("changed").GetInt32() > 0);

                Assert.True(server.Handle($$"""{"id":"st{{lvl}}","op":"state"}"""));
                var st = ResponseFor(DrainEvents(outputStream, writer), $"st{lvl}").GetProperty("result");
                Assert.Equal(lvl + 1, st.GetProperty("stories").GetInt32());

                var rm = server.World.LotRoomMaps[lvl].RoomAt(boxX + 1, boxY + 1);
                Assert.NotEqual(RoomMap.NoRoom, rm);
                Assert.False(server.World.LotRoomMaps[lvl].IsOutside(rm));
                Assert.Equal((lvl - 1) * 0x0400, rm & 0x7c00);

                var outRm = server.World.LotRoomMaps[lvl].RoomAt(1, 1);
                Assert.NotEqual(RoomMap.NoRoom, outRm);
                Assert.True(server.World.LotRoomMaps[lvl].IsOutside(outRm));
            }

            Assert.True(server.Handle($$"""{"id":"buy6","op":"buyObject","guid":{{propGuid}},"x":{{(boxX + 1) * 16 + 8}},"y":{{(boxY + 1) * 16 + 8}},"level":6,"direction":1}"""));
            var buy6Resp = ResponseFor(DrainEvents(outputStream, writer), "buy6");
            Assert.True(buy6Resp.GetProperty("ok").GetBoolean(), buy6Resp.GetRawText());
            var prop6Id = (short)buy6Resp.GetProperty("result").GetProperty("objectID").GetInt32();

            Assert.True(server.Handle("""{"id":"mLive","op":"mode","mode":"live"}"""));
            DrainEvents(outputStream, writer);
            Assert.True(server.Handle("""{"id":"rfOn","op":"roofs","visible":true}"""));
            var rfEvents = DrainEvents(outputStream, writer);
            var rfState = ResponseFor(rfEvents, "rfOn").GetProperty("result");
            Assert.Equal(6, rfState.GetProperty("stories").GetInt32());

            Assert.True(server.Handle("""{"id":"sc6","op":"scene"}"""));
            var scEvents = DrainEvents(outputStream, writer);
            var scResp = ResponseFor(scEvents, "sc6");
            Assert.True(scResp.GetProperty("ok").GetBoolean(), scResp.GetRawText());
            var scenePath = scEvents
                .Last(e => e.TryGetProperty("type", out var t) && t.GetString() == "frame")
                .GetProperty("scene").GetString()!;
            var (scene6, _) = LotScene.Load(scenePath);
            Assert.Equal(6, scene6.Stories);
            Assert.NotNull(scene6.OverheadMap);
            Assert.Equal(scene6.OverheadMap!.Width * 2, scene6.OverheadMap.Height);
            int yardSampleOffset = ((2 * 8 + 4) * scene6.OverheadMap.Width + (2 * 8 + 4)) * 4;
            Assert.Equal(0, scene6.OverheadMap.Pixels![yardSampleOffset] & 0x60);
            Assert.Equal(1, scene6.OverheadMap.Pixels[yardSampleOffset + 3]);
            Assert.NotNull(scene6.VoxelMap);
            int aoSize = scene6.VoxelMap!.Width / 4;
            int aoRows = (scene6.VoxelMap.Height - scene6.VoxelMap.Width - 256) / (512 + aoSize);
            Assert.Equal(2, aoRows);
            Assert.NotNull(scene6.Lighting?.Windows);
            var exportedWindows = scene6.Lighting!.Windows!
                .Select(w => (w.X, w.Y, w.Level))
                .ToHashSet();
            var orthWindows = server.World.WalkOrder
                .Where(o => o is not XPerson &&
                            (o[ObjectData.FlagField2] & 0x4000) != 0 &&
                            (o[ObjectData.Direction] & 1) == 0 &&
                            (o[ObjectData.WallPlacementFlags] & 0x0f) != 0)
                .ToArray();
            Assert.NotEmpty(orthWindows);
            foreach (var winObj in orthWindows)
            {
                int wx = winObj.Position.X >> 4;
                int wy = winObj.Position.Y >> 4;
                int wl = winObj.Position.Height;
                Assert.Contains((wx, wy, wl), exportedWindows);
                int wDir = (winObj[ObjectData.Direction] & 7) >> 1;
                int wp = winObj[ObjectData.WallPlacementFlags];
                for (int bit = 0; bit < 4; bit++)
                {
                    if ((wp & (1 << bit)) == 0) continue;
                    var (nx, ny) = ((wDir + bit) & 3) switch
                    {
                        0 => (wx, wy - 1),
                        1 => (wx + 1, wy),
                        2 => (wx, wy + 1),
                        _ => (wx - 1, wy),
                    };
                    Assert.Contains((nx, ny, wl), exportedWindows);
                }
            }

            DismissBlockingDialogs(server, outputStream, writer);
            Assert.True(server.Handle($$"""{"id":"sell6","op":"sellObject","objectID":{{prop6Id}}}"""));
            var sell6Resp = ResponseFor(DrainEvents(outputStream, writer), "sell6");
            Assert.True(sell6Resp.GetProperty("ok").GetBoolean(), sell6Resp.GetRawText());
            DismissBlockingDialogs(server, outputStream, writer);
            Assert.True(server.Handle("""{"id":"rfOff","op":"roofs","visible":false}"""));
            DrainEvents(outputStream, writer);
            DismissBlockingDialogs(server, outputStream, writer);
            Assert.True(server.Handle("""{"id":"mBuild2","op":"mode","mode":"build"}"""));
            DrainEvents(outputStream, writer);
            DismissBlockingDialogs(server, outputStream, writer);
            Assert.True(server.Handle($$"""{"id":"wErase6","op":"architecture","command":"WALL_STROKE","level":6,"segments":[{"command":"WALL_ERASE","x":{{boxX}},"y":{{boxY}},"x2":{{boxX + 4}},"y2":{{boxY}},"style":1,"pattern":0},{"command":"WALL_ERASE","x":{{boxX + 4}},"y":{{boxY}},"x2":{{boxX + 4}},"y2":{{boxY + 4}},"style":1,"pattern":0},{"command":"WALL_ERASE","x":{{boxX + 4}},"y":{{boxY + 4}},"x2":{{boxX}},"y2":{{boxY + 4}},"style":1,"pattern":0},{"command":"WALL_ERASE","x":{{boxX}},"y":{{boxY + 4}},"x2":{{boxX}},"y2":{{boxY}},"style":1,"pattern":0}]}"""));
            var wErase6Resp = ResponseFor(DrainEvents(outputStream, writer), "wErase6");
            Assert.True(wErase6Resp.GetProperty("ok").GetBoolean(), wErase6Resp.GetRawText());
            DismissBlockingDialogs(server, outputStream, writer);
            Assert.True(server.Handle($$"""{"id":"fErase6","op":"architecture","command":"FLOOR_RECT","level":6,"x":{{boxX}},"y":{{boxY}},"x2":3,"y2":3,"pattern":0}"""));
            var fErase6Resp = ResponseFor(DrainEvents(outputStream, writer), "fErase6");
            Assert.True(fErase6Resp.GetProperty("ok").GetBoolean(), fErase6Resp.GetRawText());

            var remOn6 = server.World.WalkOrder.Where(o => o.Position.Height == 6).Select(o => $"{o.Id}:{o.TypeRecord?.Name}@{o.Position}").ToArray();
            Assert.True(remOn6.Length == 0, $"Remaining objects on level 6: [{string.Join(", ", remOn6)}]");

            Assert.True(server.Handle("""{"id":"mLive2","op":"mode","mode":"live"}"""));
            DrainEvents(outputStream, writer);
            Assert.True(server.Handle("""{"id":"sCollapse","op":"state"}"""));
            var sCollapse = ResponseFor(DrainEvents(outputStream, writer), "sCollapse").GetProperty("result");
            Assert.Equal(5, sCollapse.GetProperty("stories").GetInt32());
        }
        finally
        {
            Neighborhoods.Current = previousNeighborhood;
            if (Directory.Exists(tempRoot))
                Directory.Delete(tempRoot, recursive: true);
        }
    }

    [Fact]
    public void FourStoryTower_SaveReload_SimRoutesFloor1To4_AndDirectClickOnUpperStaircaseWorks()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null ||
            !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")) ||
            !File.Exists(Path.Combine(gameDir, "UserData", "Neighborhood.iff")))
            return;

        var previousNeighborhood = Neighborhoods.Current;
        var (tempRoot, profile, userData, session) = CreateIsolatedHouse05Profile(gameDir);
        try
        {
            Neighborhoods.Current = 1;
            using var outputStream = new MemoryStream();
            using var writer = new StreamWriter(outputStream, new UTF8Encoding(false)) { AutoFlush = true };
            var server = SimulationServer.Load(gameDir, session, profile, 5, writer);
            DrainEvents(outputStream, writer);

            var world = server.World!;
            DismissBlockingDialogs(server, outputStream, writer);
            world.FamilyBudget!.AlterFamilyBudget(0, -500000);

            var floorPattern = QueryFirstFloorPattern(server, outputStream, writer);
            var propGuid = QueryFirstChairGuid(server, outputStream, writer);
            var stairGuids = QueryStairGuids(server, outputStream, writer);
            Assert.NotEmpty(stairGuids);
            uint? doorGuid = null;
            Assert.True(server.Handle("""{"id":"qDoor","op":"catalogPage","category":8,"offset":0,"count":20}"""));
            var doorResp = ResponseFor(DrainEvents(outputStream, writer), "qDoor");
            if (doorResp.GetProperty("ok").GetBoolean())
            {
                foreach (var dItem in doorResp.GetProperty("result").GetProperty("items").EnumerateArray())
                {
                    doorGuid = dItem.GetProperty("guid").GetUInt32();
                    break;
                }
            }
            Assert.NotNull(doorGuid);

            var terrain = LotTerrain.Read(IffFile.Open(Path.Combine(userData, "Houses", "House05.iff")));
            var lotTiles = LotTiles.Read(IffFile.Open(Path.Combine(userData, "Houses", "House05.iff")));
            int towerX = -1, towerY = -1;
            for (int x = 6; x < 50 && towerX < 0; x++)
            {
                for (int y = 6; y < 50 && towerX < 0; y++)
                {
                    var refH = terrain.ReferenceHeight(x, y);
                    var ok = true;
                    for (int dx = -1; dx <= 8 && ok; dx++)
                    {
                        for (int dy = -1; dy <= 8 && ok; dy++)
                        {
                            if (!lotTiles.InsideLot(x + dx, y + dy) ||
                                !lotTiles.Buildable(x + dx, y + dy, 1) ||
                                !terrain.IsFlatAt(x + dx, y + dy, refH) ||
                                world.LotRoomMaps[1].RoomAt(x + dx, y + dy) == RoomMap.NoRoom ||
                                !world.LotRoomMaps[1].IsOutside(world.LotRoomMaps[1].RoomAt(x + dx, y + dy)) ||
                                world.ObjectsAtTile(x + dx, y + dy, 1).Any() ||
                                world.ObjectsAtTile(x + dx, y + dy, 2).Any())
                            {
                                ok = false;
                            }
                        }
                    }
                    if (ok)
                    {
                        towerX = x;
                        towerY = y;
                    }
                }
            }
            Assert.True(towerX >= 0, "Expected an open 8x8 flat yard area on House05.");

            Assert.True(server.Handle("""{"id":"m1","op":"mode","mode":"build"}"""));
            DrainEvents(outputStream, writer);

            for (int lvl = 1; lvl <= 4; lvl++)
            {
                Assert.True(server.Handle($$"""{"id":"f{{lvl}}","op":"architecture","command":"FLOOR_RECT","level":{{lvl}},"x":{{towerX}},"y":{{towerY}},"x2":7,"y2":7,"pattern":{{floorPattern}}}"""));
                var fResp = ResponseFor(DrainEvents(outputStream, writer), $"f{lvl}");
                Assert.True(fResp.GetProperty("ok").GetBoolean(), fResp.GetRawText());

                Assert.True(server.Handle($$"""{"id":"w{{lvl}}","op":"architecture","command":"WALL_RECT","level":{{lvl}},"x":{{towerX}},"y":{{towerY}},"x2":8,"y2":8,"style":1,"pattern":0}"""));
                var wResp = ResponseFor(DrainEvents(outputStream, writer), $"w{lvl}");
                Assert.True(wResp.GetProperty("ok").GetBoolean(), wResp.GetRawText());
            }

            var placedDoor = false;
            foreach (var dir in new byte[] { 1, 4, 16, 64 })
            {
                for (int off = 2; off <= 5 && !placedDoor; off++)
                {
                    foreach (var (dx, dy) in new[] { (towerX, towerY + off), (towerX + off, towerY), (towerX + 7, towerY + off), (towerX + off, towerY + 7) })
                    {
                        var dReq = $"door_{dir}_{dx}_{dy}";
                        server.Handle($$"""{"id":"{{dReq}}","op":"buyObject","guid":{{doorGuid!.Value}},"x":{{dx * 16 + 8}},"y":{{dy * 16 + 8}},"level":1,"direction":{{dir}}}""");
                        var dResp = ResponseFor(DrainEvents(outputStream, writer), dReq);
                        if (dResp.GetProperty("ok").GetBoolean())
                        {
                            placedDoor = true;
                            break;
                        }
                    }
                }
            }
            Assert.True(placedDoor, "Expected front door to place on ground floor of 4-story tower.");

            short PlaceStairOnLevel(int baseLevel, int preferredOffsetX, int preferredOffsetY)
            {
                DismissBlockingDialogs(server, outputStream, writer);
                string lastErr = "";
                foreach (var stairGuid in stairGuids)
                {
                    for (int ox = 1; ox <= 6; ox++)
                    {
                        for (int oy = 1; oy <= 6; oy++)
                        {
                            int sx = towerX + ((ox + preferredOffsetX - 1) % 6) + 1;
                            int sy = towerY + ((oy + preferredOffsetY - 1) % 6) + 1;
                            foreach (var dir in new byte[] { 1, 4, 16, 64 })
                            {
                                DismissBlockingDialogs(server, outputStream, writer);
                                var reqId = $"st_{stairGuid}_{baseLevel}_{sx}_{sy}_{dir}";
                                server.Handle($$"""{"id":"{{reqId}}","op":"buyObject","guid":{{stairGuid}},"x":{{sx * 16 + 8}},"y":{{sy * 16 + 8}},"level":{{baseLevel}},"direction":{{dir}}}""");
                                var resp = ResponseFor(DrainEvents(outputStream, writer), reqId);
                                if (resp.GetProperty("ok").GetBoolean())
                                    return (short)resp.GetProperty("result").GetProperty("objectID").GetInt32();
                                lastErr = $"{resp.GetRawText()} (failCode=0x{world.LastPlacementFailureCode:X2}, portalFail=0x{world.LastPortalPlacementFailureCode:X2})";
                            }
                        }
                    }
                }
                throw new InvalidOperationException($"Failed to place staircase on level {baseLevel} inside tower ({towerX},{towerY}); last={lastErr}");
            }

            _ = PlaceStairOnLevel(1, 0, 0);
            var stair23Id = PlaceStairOnLevel(2, 2, 0);
            _ = PlaceStairOnLevel(3, 4, 3);

            short placedProp4Id = 0;
            for (int dx = 0; dx <= 7 && placedProp4Id == 0; dx++)
            {
                for (int dy = 0; dy <= 7 && placedProp4Id == 0; dy++)
                {
                    DismissBlockingDialogs(server, outputStream, writer);
                    var reqId = $"prop4_{dx}_{dy}";
                    server.Handle($$"""{"id":"{{reqId}}","op":"buyObject","guid":{{propGuid}},"x":{{(towerX + dx) * 16 + 8}},"y":{{(towerY + dy) * 16 + 8}},"level":4,"direction":1}""");
                    var resp = ResponseFor(DrainEvents(outputStream, writer), reqId);
                    if (resp.GetProperty("ok").GetBoolean())
                        placedProp4Id = (short)resp.GetProperty("result").GetProperty("objectID").GetInt32();
                }
            }
            Assert.NotEqual(0, placedProp4Id);

            DismissBlockingDialogs(server, outputStream, writer);
            Assert.True(server.Handle("""{"id":"closeSave","op":"closeLot","save":true}"""));
            var closeResp = ResponseFor(DrainEvents(outputStream, writer), "closeSave");
            Assert.True(closeResp.GetProperty("ok").GetBoolean(), closeResp.GetRawText());

            var house05Path = Path.Combine(userData, "Houses", "House05.iff");
            var savedLot = IffFile.Open(house05Path);
            Assert.True(LotFloors.HasNonEmptyFloor(savedLot, 3));
            Assert.True(LotFloors.HasNonEmptyFloor(savedLot, 4));
            Assert.True(LotWalls.HasNonEmptyWalls(savedLot, 3));
            Assert.True(LotWalls.HasNonEmptyWalls(savedLot, 4));
            Assert.NotNull(savedLot.Find(ResourceType.Parse("Arry"), 208));
            Assert.NotNull(savedLot.Find(ResourceType.Parse("Arry"), 308));
            Assert.NotNull(savedLot.Find(ResourceType.Parse("Arry"), 408));

            var reloaded = WorldBootstrap.Load(gameDir, house05Path, userDataPath: userData);
            var rWorld = reloaded.World;
            rWorld.AutonomyForced = false;
            rWorld.AutonomyHost = null;
            Assert.InRange(rWorld.MaxIndexedLevel, 4, 5);
            Assert.NotNull(rWorld.ObjectById(placedProp4Id));
            Assert.Equal(4, rWorld.ObjectById(placedProp4Id)!.Position.Height);

            var bella = Assert.IsType<XPerson>(rWorld.ObjectById(18));
            Assert.Equal(1, bella.Position.Height);

            (int X, int Y)? goal4 = null;
            for (int dx = 1; dx <= 6 && goal4 is null; dx++)
            {
                for (int dy = 1; dy <= 6 && goal4 is null; dy++)
                {
                    int gx = towerX + dx;
                    int gy = towerY + dy;
                    if (rWorld.ObjectsAtTile(gx, gy, 4).Any())
                        continue;
                    if (rWorld.CanPlaceObject(bella, new ObjectPosition(gx * 16 + 8, gy * 16 + 8, 4), null))
                        goal4 = (gx, gy);
                }
            }
            Assert.NotNull(goal4);

            var goHereTarget = rWorld.ObjectFactory!(0x7c4)!;
            rWorld.Add(goHereTarget);
            rWorld.InitializeCreatedObject(goHereTarget);
            rWorld.SetObjectPosition(goHereTarget, new ObjectPosition(goal4!.Value.X * 16 + 8, goal4.Value.Y * 16 + 8, 4));
            var goChoice = InteractionMenus.Read(rWorld, bella, goHereTarget).First(c => c.ActionText is not null);
            Assert.True(rWorld.EnqueueInteractionAction(bella, goChoice));

            var controls = new SimulationClockControl(1, 1, 1);
            var visitedLevels = new HashSet<int> { bella.Position.Height };
            var reachedFloor4 = false;
            for (int tick = 0; tick < 2800; tick++)
            {
                rWorld.AdvanceSimulationTick(controls, 0, rWorld.Clock.Ticks);
                visitedLevels.Add(bella.Position.Height);
                if (bella.Position.Height == 4 &&
                    (bella.Position.X >> 4) == goal4.Value.X &&
                    (bella.Position.Y >> 4) == goal4.Value.Y &&
                    bella.NativeRoute is null)
                {
                    reachedFloor4 = true;
                    break;
                }
            }

            Assert.True(reachedFloor4, $"Expected Bella to climb Floor 1 -> 2 -> 3 -> 4 to {goal4}, stopped at {bella.Position} (visited=[{string.Join(",", visitedLevels.Order())}])");
            Assert.Equal([1, 2, 3, 4], visitedLevels.Order().ToArray());

            var stair23Members = rWorld.Objects.Values
                .Where(o => o.Id == stair23Id || o.MultiTileMasterId == stair23Id)
                .ToArray();
            var clickableStair23 = stair23Members
                .Select(m => (Member: m, Choices: InteractionMenus.Read(rWorld, bella, m)))
                .FirstOrDefault(x => x.Choices.Count > 0);
            Assert.NotNull(clickableStair23.Member);
            var downChoice = clickableStair23.Choices.First(c => c.ActionText is not null);
            Assert.True(rWorld.EnqueueInteractionAction(bella, downChoice));

            var reachedFloor2ViaDirectClick = false;
            for (int tick = 0; tick < 2000; tick++)
            {
                rWorld.AdvanceSimulationTick(controls, 0, rWorld.Clock.Ticks);
                if (bella.Position.Height == 2 && bella.NativeRoute is null && bella.CurrentActionRecord?.Owner is null)
                {
                    reachedFloor2ViaDirectClick = true;
                    break;
                }
            }
            Assert.True(reachedFloor2ViaDirectClick, $"Expected direct click on L2<->L3 staircase from L4 to descend to L2, stopped at {bella.Position}");

            var upChoicesFromL2 = InteractionMenus.Read(rWorld, bella, clickableStair23.Member);
            Assert.NotEmpty(upChoicesFromL2);
            Assert.True(rWorld.EnqueueInteractionAction(bella, upChoicesFromL2.First(c => c.ActionText is not null)));

            var reachedFloor3ViaDirectClick = false;
            for (int tick = 0; tick < 1500; tick++)
            {
                rWorld.AdvanceSimulationTick(controls, 0, rWorld.Clock.Ticks);
                if (bella.Position.Height == 3 && bella.NativeRoute is null && bella.CurrentActionRecord?.Owner is null)
                {
                    reachedFloor3ViaDirectClick = true;
                    break;
                }
            }
            Assert.True(reachedFloor3ViaDirectClick, $"Expected direct click on L2<->L3 staircase from L2 to climb to L3, stopped at {bella.Position}");
        }
        finally
        {
            Neighborhoods.Current = previousNeighborhood;
            if (Directory.Exists(tempRoot))
                Directory.Delete(tempRoot, recursive: true);
        }
    }
}
