using System.Text;
using System.Text.Json;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;
using SimsSDL;
using SimsSDL.Core;
using SimsSimulation;

namespace SimsEngine.Tests;

public sealed class WallpaperToolTests
{
    private sealed class Budget(int funds) : IFamilyBudget
    {
        public int Funds { get; private set; } = funds;
        public int ReadFamilyBudget() => Funds;
        public void AlterFamilyBudget(int expenseType, int amount) => Funds -= amount;
    }

    private static (IffFile Lot, WallpaperCatalog Catalog) Setup(byte diagonalStyle)
    {
        var walls = new ChunkBuilder().S16(0).S16(0).S32(64).S32(64).S32(8).U32(0);
        for (var x = 0; x < 64; x++)
        for (var y = 0; y < 64; y++)
            walls.Raw(x == 10 && y == 10 ? [0x10, 0, 0, diagonalStyle, 0, 0, 0, 0] : new byte[8]);
        var lot = new IffFile(ChunkBuilder.File(("Arry", 2, walls.ToArray())), "lot.iff");
        var strings = new ChunkBuilder().S16(-1).S16(3).CString("10").CString("one").CString("one pattern");
        var build = new IffFile(ChunkBuilder.File(("STR#", (ushort)0x83, strings.ToArray())), "Build.iff");
        return (lot, WallpaperCatalog.Read(build));
    }

    [Fact]
    public void FillStopsWithFenceErrorAtADiagonalInTheRoom()
    {
        var (lot, catalog) = Setup(2);
        var tool = new WallpaperTool(LotWalls.Read(lot, 1), catalog, new Budget(1000));
        var changed = tool.Fill(RoomMap.Build(lot, 1, 64, 64), 5, 5, 1, erase: false);
        Assert.Equal(0, changed);
        Assert.Equal(WallpaperTool.FenceError, tool.Error);
    }

    [Fact]
    public void FillWithoutADiagonalHasNoError()
    {
        var (lot, catalog) = Setup(2);
        var walls = LotWalls.Read(lot, 1);
        walls[10, 10][0] = 0;
        var tool = new WallpaperTool(walls, catalog, new Budget(1000));
        tool.Fill(RoomMap.Build(lot, 1, 64, 64), 5, 5, 1, erase: false);
        Assert.Equal(0, tool.Error);
    }

    [Theory]
    [InlineData(1, true)]
    [InlineData(3, true)]
    [InlineData(5, true)]
    [InlineData(6, true)]
    [InlineData(15, true)]
    [InlineData(22, true)]
    [InlineData(23, true)]
    [InlineData(24, true)]
    [InlineData(0, false)]
    [InlineData(2, false)]
    [InlineData(12, false)]
    [InlineData(13, false)]
    [InlineData(14, false)]
    public void CanChangeStyleAllowsOpeningStylesAndRejectsFences(byte style, bool expected)
    {
        Assert.Equal(expected, WallpaperTool.CanChangeStyle(style));
    }

    [Theory]
    [InlineData(3)]
    [InlineData(5)]
    [InlineData(6)]
    public void DotAndFillPaintAndEraseWallWithDoorOrWindowCutoutStyle(byte openingStyle)
    {
        var (lot, catalog) = Setup(1);
        var walls = LotWalls.Read(lot, 1);
        walls[10, 10][0] = 1;
        walls[10, 10][2] = openingStyle;
        walls[9, 10][0] = 4;
        var budget = new Budget(1000);
        var tool = new WallpaperTool(walls, catalog, budget);

        Assert.True(tool.Dot(10, 10, 1, 0, 1, erase: false));
        Assert.Equal(0, tool.Error);
        Assert.Equal(1, walls[10, 10][4]);
        Assert.Equal(10, tool.Commit());

        Assert.True(tool.Dot(10, 10, 1, 0, 0, erase: true));
        Assert.Equal(0, walls[10, 10][4]);
        Assert.Equal(-8, tool.Commit());

        var updatedLot = walls.WriteTo(lot);
        var filled = tool.Fill(RoomMap.Build(updatedLot, 1, 64, 64), 5, 5, 1, erase: false);
        Assert.Equal(2, filled);
        Assert.Equal(1, walls[10, 10][4]);
        Assert.Equal(1, walls[9, 10][7]);
    }

    [Theory]
    [InlineData(0x10, 0, 7, 4)]
    [InlineData(0x10, 1, 6, 2)]
    [InlineData(0x10, 2, 6, 2)]
    [InlineData(0x10, 3, 7, 4)]
    [InlineData(0x20, 0, 7, 3)]
    [InlineData(0x20, 1, 7, 3)]
    [InlineData(0x20, 2, 6, 1)]
    [InlineData(0x20, 3, 6, 1)]
    public void DiagonalFacingSlotAndSideMatchesCameraFacingHalfAndWallpaperToolSlot(
        int sourceDiag, int orientation, int expectedSlot, int expectedSide)
    {
        var (slot, side) = SceneExporter.DiagonalFacingSlotAndSide(sourceDiag, orientation);
        Assert.Equal(expectedSlot, slot);
        Assert.Equal(expectedSide, side);

        var (lot, catalog) = Setup(1);
        var walls = LotWalls.Read(lot, 1);
        walls[10, 10][0] = (byte)sourceDiag;
        var tool = new WallpaperTool(walls, catalog, new Budget(1000));
        Assert.True(tool.Dot(10, 10, sourceDiag, side, 1, erase: false));
        Assert.Equal(1, walls[10, 10][slot]);
        Assert.Equal(0, walls[10, 10][slot == 6 ? 7 : 6]);

        const int broadsideDiagonal = 0x10;
        var cameraDiag = orientation % 2 == 0 ? sourceDiag : sourceDiag ^ 0x30;
        if (cameraDiag == broadsideDiagonal)
        {
            var camera = new SimsSimulation.LotCamera(orientation, LotWalls.Size, LotWalls.Size);
            var (slot6X, slot6Y, slot7X, slot7Y) = sourceDiag == 0x10
                ? (10.25f, 10.25f, 10.75f, 10.75f)
                : (10.25f, 10.75f, 10.75f, 10.25f);
            var depth6 = camera.DepthOrder(slot6X, slot6Y);
            var depth7 = camera.DepthOrder(slot7X, slot7Y);
            Assert.Equal(depth6 > depth7 ? 6 : 7, slot);
        }
    }

    [Fact]
    public void WallpaperCursorDirection_SelectsExpectedFlipAcrossAllOrientations()
    {
        for (var orientation = 0; orientation < 4; orientation++)
        foreach (var face in new[] { 0, 1 })
        {
            var sourceDirection = (face - orientation + 4) % 4;
            var directionFlag = LotCameraExtensions.WallpaperCursorDirection(sourceDirection);
            var direction = directionFlag switch
            {
                1 => 0,
                4 => 2,
                16 => 4,
                64 => 6,
                _ => throw new InvalidOperationException($"Unexpected cursor direction flag {directionFlag}"),
            };
            var rotatedDirection = (uint)SceneExporter.FacingFlag(direction) << (orientation * 2);
            var wanted = (rotatedDirection & 0xff) | (rotatedDirection >> 8);
            Assert.Equal(face == 0 ? 64u : 1u, wanted);
        }

        var gameDir = TestGameLocator.Locate();
        var objectsFar = gameDir is null ? null : Path.Combine(gameDir, "GameData", "Objects", "Objects.far");
        if (gameDir is null || !File.Exists(objectsFar))
            return;

        var far = FarArchive.Open(objectsFar!);
        var entry = far.Find("Cursors.iff")
            ?? far.Entries.FirstOrDefault(e => e.Name.EndsWith("Cursors.iff", StringComparison.OrdinalIgnoreCase));
        Assert.NotNull(entry);

        var cursorsIff = new IffFile(far.Read(entry!).ToArray(), entry.Name);
        var dgrpChunk = cursorsIff.Find(ResourceType.Dgrp, 258);
        Assert.NotNull(dgrpChunk);
        var dgrp = DrawGroup.Read(cursorsIff, dgrpChunk!);

        for (var orientation = 0; orientation < 4; orientation++)
        foreach (var face in new[] { 0, 1 })
        {
            var sourceDirection = (face - orientation + 4) % 4;
            var flag = LotCameraExtensions.WallpaperCursorDirection(sourceDirection);
            var dir = flag switch { 1 => 0, 4 => 2, 16 => 4, _ => 6 };
            var img = SceneExporter.SelectedImage(dgrp, dir, orientation, zoom: 2);
            Assert.NotNull(img);
            Assert.NotEmpty(img!.Sprites);
            Assert.Equal(face == 0, (img.Sprites[0].Flags & 1) != 0);
        }
    }
}

[Collection("Neighborhoods")]
public sealed class WallpaperToolServerTests
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
        var tempRoot = Path.Combine(Path.GetTempPath(), "sims-walltool-" + Guid.NewGuid().ToString("N"));
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
    public void SimulationServer_BuildCursor_FastPath_MatchesFullExportAndRotatesCursor()
    {
        var gameDir = TestGameLocator.Locate();
        var house05 = gameDir is null ? null : Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        if (gameDir is null || !File.Exists(house05) || !File.Exists(Path.Combine(gameDir, "UserData", "Neighborhood.iff")))
            return;

        var previousNeighborhood = Neighborhoods.Current;
        var (tempRoot, profile, session) = CreateIsolatedProfile(gameDir, 5);
        var refTempDir = Path.Combine(tempRoot, "ref-export");
        Directory.CreateDirectory(refTempDir);
        try
        {
            Neighborhoods.Current = 1;
            using var outputStream = new MemoryStream();
            using var writer = new StreamWriter(outputStream, new UTF8Encoding(false)) { AutoFlush = true };
            var server = SimulationServer.Load(gameDir, session, profile, 5, writer);
            DrainEvents(outputStream, writer);

            Assert.True(server.Handle("""{"id":"wallsCut","op":"walls","mode":"cutaway"}"""));
            DrainEvents(outputStream, writer);
            Assert.True(server.Handle("""{"id":"viewEdit","op":"view","editing":true,"wallpaperTool":true}"""));
            DrainEvents(outputStream, writer);
            Assert.True(server.Handle("""{"id":"wallCat","op":"buildCatalogPage","kind":"wall","offset":0,"count":16}"""));
            var wallCatResp = ResponseFor(DrainEvents(outputStream, writer), "wallCat");
            var pattern = wallCatResp.GetProperty("result").GetProperty("items")[0].GetProperty("id").GetUInt16();

            var lot = new IffFile(File.ReadAllBytes(house05!), "House05.iff");
            var walls = LotWalls.Read(lot, 1);

            (int X, int Y)? face0Tile = null;
            (int X, int Y)? face1Tile = null;
            for (var y = 8; y < 56; y++)
            for (var x = 8; x < 56; x++)
            {
                var cell = walls[x, y];
                if (face0Tile is null && (cell[0] & 1) != 0 && walls.GetStyle(x, y, 0) == 1 && walls.GetPattern(x, y, 4) != pattern)
                    face0Tile = (x, y);
                if (face1Tile is null && (cell[0] & 2) != 0 && walls.GetStyle(x, y, 1) == 1 && walls.GetPattern(x, y, 5) != pattern)
                    face1Tile = (x, y);
                if (face0Tile is not null && face1Tile is not null) break;
            }
            Assert.NotNull(face0Tile);
            Assert.NotNull(face1Tile);

            PlacementPreview.GhostData DeserializeGhost(JsonElement el) =>
                JsonSerializer.Deserialize<PlacementPreview.GhostData>(el.GetRawText(), PackContentPaths.JsonReadOptions)!;

            var cursor0Cmd = JsonSerializer.Serialize(new
            {
                id = "cur0",
                op = "buildCursor",
                guid = 0x439u,
                graphic = 2,
                centered = true,
                x = face0Tile!.Value.X,
                y = face0Tile!.Value.Y,
                level = 1,
                direction = LotCameraExtensions.WallpaperCursorDirection(0),
                pattern,
                wallDirection = 0,
                fill = false,
            });
            Assert.True(server.Handle(cursor0Cmd));
            var resp0 = ResponseFor(DrainEvents(outputStream, writer), "cur0").GetProperty("result");
            var ghost0 = DeserializeGhost(resp0.GetProperty("ghost"));
            ghost0.Validate();
            Assert.True(ghost0.Scene.Sprites[0].Flip);
            var wallPrev0 = DeserializeGhost(resp0.GetProperty("wallPreview"));
            wallPrev0.Validate(wallSurface: true);

            var cursor1Cmd = JsonSerializer.Serialize(new
            {
                id = "cur1",
                op = "buildCursor",
                guid = 0x439u,
                graphic = 2,
                centered = true,
                x = face1Tile!.Value.X,
                y = face1Tile!.Value.Y,
                level = 1,
                direction = LotCameraExtensions.WallpaperCursorDirection(1),
                pattern,
                wallDirection = 1,
                fill = false,
            });
            Assert.True(server.Handle(cursor1Cmd));
            var resp1 = ResponseFor(DrainEvents(outputStream, writer), "cur1").GetProperty("result");
            var ghost1 = DeserializeGhost(resp1.GetProperty("ghost"));
            ghost1.Validate();
            Assert.False(ghost1.Scene.Sprites[0].Flip);
            var wallPrev1 = DeserializeGhost(resp1.GetProperty("wallPreview"));
            wallPrev1.Validate(wallSurface: true);

            // Verify zero temporary preview scene files were written and fast path matches full export.
            var sceneDir = Path.Combine(session, "scene");
            if (Directory.Exists(sceneDir))
                Assert.Empty(Directory.GetFiles(sceneDir, "scene-1000*.json"));

            var setup = WorldBootstrap.Load(gameDir, house05!, 1, () => true, 5);
            var catalog = WallpaperCatalog.Open(gameDir, 1);
            var animState = new SceneExporter.AnimationState();
            var fastDir = Path.Combine(refTempDir, "fast");
            var fullDir = Path.Combine(refTempDir, "full");
            Directory.CreateDirectory(fastDir);
            Directory.CreateDirectory(fullDir);

            var fastBaseScene = SceneExporter.Export(
                setup.Lot, setup.World, setup.Registry!, gameDir, fastDir, house: 5, revision: 1,
                viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0, cutawayTile: face1Tile,
                roofsVisible: false, state: animState, showLoweredPortals: true, raiseHoveredWalls: true);

            var fullRefScene = SceneExporter.Export(
                setup.Lot, setup.World, setup.Registry!, gameDir, fullDir, house: 5, revision: 1,
                viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0, cutawayTile: face1Tile,
                roofsVisible: false, state: null, showLoweredPortals: true, raiseHoveredWalls: true);

            var previewWalls = LotWalls.Read(setup.Lot, 1);
            var previewTool = new WallpaperTool(previewWalls, catalog, setup.World.FamilyBudget!, LotTiles.Read(setup.Lot));
            Assert.True(previewTool.Dot(face1Tile.Value.X, face1Tile.Value.Y, 2, 0, pattern, erase: false));
            var changedWalls = new HashSet<(int X, int Y, int Level, int Direction)>
            {
                (face1Tile.Value.X, face1Tile.Value.Y, 1, 1),
            };

            Assert.NotNull(setup.Registry);
            Assert.NotNull(setup.World.BuildCursorFactory);
            var cursorItem = setup.World.BuildCursorFactory!(unchecked((int)0x439u));
            Assert.NotNull(cursorItem);
            var pos1 = new ObjectPosition(face1Tile.Value.X * 16 + 8, face1Tile.Value.Y * 16 + 8, 1);
            cursorItem!.Position = new ObjectPosition(-16, -16, 1);
            setup.World.Add(cursorItem);
            setup.World.InitializeCreatedObject(cursorItem);
            cursorItem[ObjectData.Graphic] = 2;
            setup.World.FaceCreatedObject(cursorItem, [cursorItem], 0);
            setup.World.SetObjectPosition(cursorItem, pos1);

            Assert.True(SceneExporter.TryBuildCursorGhost(
                setup.Registry!, setup.World, house: 5, animState, revision: 1, fastDir,
                0x439u, cursorItem.Id, 2, pos1, direction: 0, cameraOrientation: 0, lotSize: 64,
                cursorItem.DynamicSpriteFlags, out var fastCursorObj));
            Assert.NotNull(fastCursorObj);

            Assert.True(SceneExporter.TryBuildWallPaintGhost(
                setup.Lot, setup.World, gameDir, fastDir, animState, revision: 1, wallLevel: 1, wallMode: "cutaway",
                previewWalls, changedWalls, cameraOrientation: 0, lotSize: 64, out var fastWallObj));
            Assert.NotNull(fastWallObj);

            Assert.Empty(Directory.GetFiles(fastDir, "scene-1000*.json"));
            Assert.Single(Directory.GetFiles(fastDir, "scene-*.json"));

            var fullModifiedLot = previewWalls.WriteTo(setup.Lot);
            var fullScene = SceneExporter.Export(
                fullModifiedLot, setup.World, setup.Registry!, gameDir, fullDir, house: 5, revision: 2,
                viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0, cutawayTile: face1Tile,
                roofsVisible: false, state: null, showLoweredPortals: true, raiseHoveredWalls: true);
            var fullCursorObj = SceneExporter.PlacementGhost(fullScene, cursorItem.Id, fullRefScene);
            var fullWallObj = SceneExporter.WallPaintGhost(fullScene, changedWalls, fullRefScene);
            Assert.NotNull(fullCursorObj);
            Assert.NotNull(fullWallObj);

            var fastCursor = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
                JsonSerializer.Serialize(fastCursorObj), PackContentPaths.JsonReadOptions)!;
            var expectedCursor = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
                JsonSerializer.Serialize(fullCursorObj), PackContentPaths.JsonReadOptions)!;
            fastCursor.Validate();
            Assert.Equal(expectedCursor.X, fastCursor.X, 2);
            Assert.Equal(expectedCursor.Y, fastCursor.Y, 2);
            Assert.Equal(expectedCursor.Scene.Width, fastCursor.Scene.Width, 2);
            Assert.Equal(expectedCursor.Scene.Height, fastCursor.Scene.Height, 2);
            Assert.Equal(expectedCursor.Scene.Sprites.Count, fastCursor.Scene.Sprites.Count);
            Assert.Equal(expectedCursor.Scene.Sprites[0].Flip, fastCursor.Scene.Sprites[0].Flip);
            Assert.Equal(expectedCursor.Scene.Textures.Select(t => t.File), fastCursor.Scene.Textures.Select(t => t.File));

            var fastWall = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
                JsonSerializer.Serialize(fastWallObj), PackContentPaths.JsonReadOptions)!;
            var expectedWall = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
                JsonSerializer.Serialize(fullWallObj), PackContentPaths.JsonReadOptions)!;
            fastWall.Validate(wallSurface: true);
            Assert.Equal(expectedWall.X, fastWall.X, 2);
            Assert.Equal(expectedWall.Y, fastWall.Y, 2);
            Assert.Equal(expectedWall.Scene.Width, fastWall.Scene.Width, 2);
            Assert.Equal(expectedWall.Scene.Height, fastWall.Scene.Height, 2);
            Assert.Equal(expectedWall.Scene.Sprites.Count, fastWall.Scene.Sprites.Count);
            Assert.Equal(expectedWall.Scene.Sprites[0].Room, fastWall.Scene.Sprites[0].Room);
            Assert.Equal(expectedWall.Scene.Sprites[0].Wall, fastWall.Scene.Sprites[0].Wall);
            Assert.Equal(
                expectedWall.Scene.Textures.Select(t => t.File).OrderBy(f => f, StringComparer.Ordinal),
                fastWall.Scene.Textures.Select(t => t.File).OrderBy(f => f, StringComparer.Ordinal));
            Assert.Equal(
                expectedWall.Scene.Textures[expectedWall.Scene.Sprites[0].Texture].File,
                fastWall.Scene.Textures[fastWall.Scene.Sprites[0].Texture].File);
            Assert.Equal(
                expectedWall.Scene.Textures[expectedWall.Scene.Sprites[0].DepthTexture!.Value].File,
                fastWall.Scene.Textures[fastWall.Scene.Sprites[0].DepthTexture!.Value].File);
            Assert.NotNull(fastBaseScene);
            Assert.NotNull(fullRefScene);
        }
        finally
        {
            Neighborhoods.Current = previousNeighborhood;
            if (Directory.Exists(tempRoot))
                Directory.Delete(tempRoot, recursive: true);
        }
    }
}
