using System.Text;
using System.Text.Json;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;
using SimsSDL.Core;
using SimsSimulation;

namespace SimsEngine.Tests;

[Collection("Neighborhoods")]
public sealed class PlacementGhostTests
{
    private static void AssertGhostParity(object? fastObj, object? expectedObj)
    {
        Assert.NotNull(expectedObj);
        Assert.NotNull(fastObj);

        var fast = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
            JsonSerializer.Serialize(fastObj), PackContentPaths.JsonReadOptions)!;
        var expected = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
            JsonSerializer.Serialize(expectedObj), PackContentPaths.JsonReadOptions)!;

        fast.Validate();
        expected.Validate();

        Assert.Equal(expected.X, fast.X, 2);
        Assert.Equal(expected.Y, fast.Y, 2);
        Assert.Equal(expected.Scene.Width, fast.Scene.Width, 2);
        Assert.Equal(expected.Scene.Height, fast.Scene.Height, 2);
        Assert.Equal(expected.Scene.Sprites.Count, fast.Scene.Sprites.Count);

        for (var i = 0; i < expected.Scene.Sprites.Count; i++)
        {
            var es = expected.Scene.Sprites[i];
            var fs = fast.Scene.Sprites[i];
            Assert.Equal(es.X, fs.X, 2);
            Assert.Equal(es.Y, fs.Y, 2);
            Assert.Equal(es.Width, fs.Width, 2);
            Assert.Equal(es.Height, fs.Height, 2);
            Assert.Equal(es.Flip, fs.Flip);
            Assert.Equal(expected.Scene.Textures[es.Texture].File, fast.Scene.Textures[fs.Texture].File);
        }
    }

    private static string? LocateGameDirectory() => TestGameLocator.Locate();

    private static void DeleteTempTree(string path)
    {
        if (!Directory.Exists(path) && !File.Exists(path))
            return;

        try
        {
            Directory.Delete(path, recursive: true);
        }
        catch (IOException)
        {
        }
        catch (UnauthorizedAccessException)
        {
        }
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

    private static (string TempRoot, string Profile, string Session) CreateIsolatedProfile(
        string gameDir, params short[] houses)
    {
        var tempRoot = Path.Combine(Path.GetTempPath(), "sims-ghost-" + Guid.NewGuid().ToString("N"));
        var profile = Path.Combine(tempRoot, "runtime", "profiles", "test");
        var userData = Path.Combine(profile, "UserData");
        Directory.CreateDirectory(Path.Combine(userData, "Houses"));
        var charsDir = Path.Combine(userData, "Characters");
        Directory.CreateDirectory(charsDir);
        foreach (var charFile in Directory.EnumerateFiles(Path.Combine(gameDir, "UserData", "Characters")))
        {
            File.Copy(charFile, Path.Combine(charsDir, Path.GetFileName(charFile)));
        }

        File.Copy(Path.Combine(gameDir, "UserData", "Neighborhood.iff"), Path.Combine(userData, "Neighborhood.iff"));
        foreach (var extra in new[] { "LotZoning.iff", "LotLocations.iff", "StreetNames.iff" })
        {
            var extraPath = Path.Combine(gameDir, "UserData", extra);
            if (File.Exists(extraPath))
                File.Copy(extraPath, Path.Combine(userData, extra));
        }

        foreach (var house in houses)
        {
            var src = Path.Combine(gameDir, "UserData", "Houses", $"House{house:D2}.iff");
            if (File.Exists(src))
                File.Copy(src, Path.Combine(userData, "Houses", $"House{house:D2}.iff"));
        }

        var session = Path.Combine(tempRoot, "session");
        Directory.CreateDirectory(session);
        return (tempRoot, profile, session);
    }

    private static void PositionPreviewMembers(
        SimulationWorld world,
        XObject root,
        IReadOnlyList<XObject> members,
        ObjectPosition destination,
        XObject? referenceObject = null,
        int referenceSlot = -1)
    {
        if (referenceObject is not null && referenceSlot >= 0 && members.Count == 1)
        {
            var slotNumber = checked((short)(referenceSlot + 1));
            root[ObjectData.ContainerId] = referenceObject.ClockManagerIndex;
            root[ObjectData.SlotNumber] = slotNumber;
            root[ObjectData.ParentId] = referenceObject.ClockManagerIndex;
            root[ObjectData.SlotHierNumber] = slotNumber;
            world.SetObjectPosition(root, referenceObject.Position);
            return;
        }

        var rootState = root.SavedMultiTileState;
        var rootOffsetX = (rootState?.Value0x1A0 ?? 0) << 4;
        var rootOffsetY = (rootState?.Value0x1A4 ?? 0) << 4;
        var rootOffsetLevel = rootState?.Value0x1A8 ?? 0;
        foreach (var member in members)
        {
            var state = member.SavedMultiTileState;
            world.SetObjectPosition(member, new ObjectPosition(
                destination.X - rootOffsetX + ((state?.Value0x1A0 ?? 0) << 4),
                destination.Y - rootOffsetY + ((state?.Value0x1A4 ?? 0) << 4),
                destination.Height - rootOffsetLevel + (state?.Value0x1A8 ?? 0)));
        }
    }

    [Fact]
    public void TryBuildPlacementGhost_MatchesFullPlacementGhost_AcrossObjectClasses()
    {
        var gameDir = LocateGameDirectory();
        var house05 = gameDir is null ? null : Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        if (gameDir is null || !File.Exists(house05))
            return;

        var tempDir = Path.Combine(Path.GetTempPath(), "sims-placement-ghost-" + Guid.NewGuid().ToString("N"));
        try
        {
            var fastDir = Path.Combine(tempDir, "fast");
            var fullDir = Path.Combine(tempDir, "full");
            Directory.CreateDirectory(fastDir);
            Directory.CreateDirectory(fullDir);

            var setup = WorldBootstrap.Load(gameDir, house05!, 1, () => true, 5);
            var world = setup.World;
            var registry = setup.Registry!;
            var animState = new SceneExporter.AnimationState();

            var fastRefScene = SceneExporter.Export(
                setup.Lot, world, registry, gameDir, fastDir, house: 5, revision: 1,
                viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0, cutawayTile: null,
                roofsVisible: false, state: animState, showLoweredPortals: true, raiseHoveredWalls: false);
            Assert.False(string.IsNullOrEmpty(fastRefScene));

            var fullRefScene = SceneExporter.Export(
                setup.Lot, world, registry, gameDir, fullDir, house: 5, revision: 1,
                viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0, cutawayTile: null,
                roofsVisible: false, state: null, showLoweredPortals: true, raiseHoveredWalls: false);

            var exportRevision = 100L;

            void VerifyParity(IReadOnlyList<XObject> entities)
            {
                Assert.True(SceneExporter.TryBuildPlacementGhost(
                    registry, world, house: 5, animState, revision: 1, fastDir,
                    entities, viewLevel: 1, cameraOrientation: 0, lotSize: 64, out var fastGhost));

                var fullScene = SceneExporter.Export(
                    setup.Lot, world, registry, gameDir, fullDir, house: 5, revision: ++exportRevision,
                    viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0, cutawayTile: null,
                    roofsVisible: false, state: null, showLoweredPortals: true, raiseHoveredWalls: false);
                var ids = entities.Select(e => e.Id).ToHashSet();
                var expectedGhost = SceneExporter.PlacementGhost(fullScene, ids, fullRefScene);

                AssertGhostParity(fastGhost, expectedGhost);
                Assert.Empty(Directory.GetFiles(fastDir, "scene-1000*.json"));
                Assert.Single(Directory.GetFiles(fastDir, "scene-*.json"));
            }

            (int X, int Y) FindFreeGroundTile(XObject item, IReadOnlyList<XObject> members)
            {
                for (var y = 16; y < 48; y++)
                for (var x = 16; x < 48; x++)
                {
                    var pos = new ObjectPosition(x * 16 + 8, y * 16 + 8, 1);
                    if (world.CanPlaceObjectFromEditor(item, pos, out var refObj, out _) && refObj is null)
                    {
                        PositionPreviewMembers(world, item, members, pos);
                        return (x, y);
                    }
                }
                throw new InvalidOperationException("No free placement tile found");
            }

            var singleEntry = registry.Entries.FirstOrDefault(e =>
                e.Definition[ObjdField.MasterId] == 0 &&
                e.Definition[ObjdField.BuildModeType] == 0 &&
                ObjectCatalog.TryGetEntry(e, 1, CatalogLotType.Residential, out var cat) &&
                cat is not null && (cat.Categories & (1 << 0)) != 0);
            Assert.NotNull(singleEntry);
            var singleObj = world.PlacementPreviewFactory!.Invoke(unchecked((int)singleEntry!.Guid))!;
            singleObj.Position = new ObjectPosition(-16, -16, 1);
            world.Add(singleObj);
            world.InitializeCreatedObject(singleObj);
            try
            {
                world.FaceCreatedObject(singleObj, [singleObj], 2);
                FindFreeGroundTile(singleObj, [singleObj]);
                VerifyParity([singleObj]);
            }
            finally
            {
                world.Remove(singleObj.Id);
            }

            var multiEntry = registry.Entries.FirstOrDefault(e =>
                e.Definition[ObjdField.MasterId] != 0 &&
                e.Definition[ObjdField.SubIndex] == ushort.MaxValue &&
                e.Definition[ObjdField.BuildModeType] == 0 &&
                ObjectCatalog.TryGetEntry(e, 1, CatalogLotType.Residential, out var cat) &&
                cat is not null && (cat.Categories & ((1 << 0) | (1 << 3))) != 0);
            Assert.NotNull(multiEntry);
            var multiMembers = world.PlacementPreviewGroupFactory!.Invoke(unchecked((int)multiEntry!.Guid))!;
            Assert.True(multiMembers.Count > 1);
            try
            {
                world.FaceCreatedObject(multiMembers[0], multiMembers, 0);
                FindFreeGroundTile(multiMembers[0], multiMembers);
                VerifyParity(multiMembers);
            }
            finally
            {
                world.RemoveCreatedObjectGroup(multiMembers[0]);
            }

            var doorEntry = registry.Entries.FirstOrDefault(e =>
                (e.Definition[ObjdField.MasterId] == 0 || e.Definition[ObjdField.SubIndex] == ushort.MaxValue) &&
                e.Definition[ObjdField.BuildModeType] is 1 or 2 &&
                ObjectCatalog.TryGetEntry(e, 1, CatalogLotType.Residential, out var cat) &&
                cat is not null && (cat.Categories & ((1 << 8) | (1 << 9))) != 0);
            Assert.NotNull(doorEntry);
            IReadOnlyList<XObject> doorMembers;
            bool doorIsGroup = doorEntry!.Definition[ObjdField.MasterId] != 0;
            if (doorIsGroup)
            {
                doorMembers = world.PlacementPreviewGroupFactory!.Invoke(unchecked((int)doorEntry.Guid))!;
            }
            else
            {
                var dObj = world.PlacementPreviewFactory!.Invoke(unchecked((int)doorEntry.Guid))!;
                dObj.Position = new ObjectPosition(-16, -16, 1);
                world.Add(dObj);
                world.InitializeCreatedObject(dObj);
                doorMembers = [dObj];
            }
            try
            {
                var walls = LotWalls.Read(setup.Lot, 1);
                var placedDoor = false;
                for (var y = 8; y < 56 && !placedDoor; y++)
                for (var x = 8; x < 56 && !placedDoor; x++)
                {
                    var cell = walls[x, y];
                    foreach (var dir in new[] { (short)0, (short)2, (short)4, (short)6 })
                    {
                        if ((cell[0] & 3) == 0) continue;
                        world.FaceCreatedObject(doorMembers[0], doorMembers, dir);
                        var pos = new ObjectPosition(x * 16 + 8, y * 16 + 8, 1);
                        if (world.CanPlaceObjectFromEditor(doorMembers[0], pos, out _, out _))
                        {
                            PositionPreviewMembers(world, doorMembers[0], doorMembers, pos);
                            placedDoor = true;
                            break;
                        }
                    }
                }
                Assert.True(placedDoor);
                VerifyParity(doorMembers);
            }
            finally
            {
                if (doorIsGroup)
                    world.RemoveCreatedObjectGroup(doorMembers[0]);
                else
                    world.Remove(doorMembers[0].Id);
            }

            var surfaceCandidates = registry.Entries.Where(e =>
                e.Definition[ObjdField.MasterId] == 0 &&
                e.Definition[ObjdField.BuildModeType] == 0 &&
                ObjectCatalog.TryGetEntry(e, 1, CatalogLotType.Residential, out var cat) &&
                cat is not null && (cat.Categories & ((1 << 5) | (1 << 6))) != 0);
            var placedOnSurface = false;
            foreach (var lampEntry in surfaceCandidates)
            {
                var lampObj = world.PlacementPreviewFactory!.Invoke(unchecked((int)lampEntry.Guid));
                if (lampObj is null) continue;
                lampObj.Position = new ObjectPosition(-16, -16, 1);
                world.Add(lampObj);
                world.InitializeCreatedObject(lampObj);
                try
                {
                    foreach (var candidateSurface in world.WalkOrder.Where(o =>
                        o is not XPerson && o.Position.Height == 1 && o.Position.X > 0 && o.DefinitionSlots.Any(s => s.Type == 0)))
                    {
                        world.FaceCreatedObject(lampObj, [lampObj], 0);
                        if (world.CanPlaceObjectFromEditor(lampObj, candidateSurface.Position, out var refObj, out var refSlot)
                            && refObj is not null && refSlot >= 0)
                        {
                            PositionPreviewMembers(world, lampObj, [lampObj], candidateSurface.Position, refObj, refSlot);
                            VerifyParity([lampObj]);
                            placedOnSurface = true;
                            break;
                        }
                    }
                    if (placedOnSurface) break;
                }
                finally
                {
                    world.Remove(lampObj.Id);
                }
            }
            Assert.True(placedOnSurface);

            var hostWithChild = world.WalkOrder.FirstOrDefault(o =>
                o is not XPerson &&
                o.Position.Height == 1 &&
                o.Position.X > 0 &&
                o.Definition[(int)ObjdField.MasterId] == 0 &&
                world.EnumerateContainedSlotChildren(o).Any(c => c is not XPerson && c[ObjectData.SlotHierNumber] > 0));
            if (hostWithChild is not null)
            {
                var hostGuid = unchecked((uint)(hostWithChild.TypeRecord?.Key ?? 0));
                var previewHost = world.PlacementPreviewFactory!.Invoke(unchecked((int)hostGuid))!;
                previewHost.Position = new ObjectPosition(-16, -16, 1);
                world.Add(previewHost);
                world.InitializeCreatedObject(previewHost);
                var savedChildren = new List<(XObject Child, ObjectPosition Position, short Direction, short ContainerId, short ParentId)>();
                try
                {
                    world.FaceCreatedObject(previewHost, [previewHost], (short)((hostWithChild[ObjectData.Direction] + 2) & 7));
                    FindFreeGroundTile(previewHost, [previewHost]);
                    var entities = new List<XObject> { previewHost };
                    foreach (var child in world.EnumerateContainedSlotChildren(hostWithChild))
                    {
                        if (child is XPerson) continue;
                        savedChildren.Add((child, child.Position, child[ObjectData.Direction], child[ObjectData.ContainerId], child[ObjectData.ParentId]));
                        child.Position = previewHost.Position;
                        child[ObjectData.Direction] = (short)((child[ObjectData.Direction] + 2) & 7);
                        if (child[ObjectData.ContainerId] == hostWithChild.ClockManagerIndex && previewHost.ClockManagerIndex > 0)
                            child[ObjectData.ContainerId] = previewHost.ClockManagerIndex;
                        if (child[ObjectData.ParentId] == hostWithChild.ClockManagerIndex && previewHost.ClockManagerIndex > 0)
                            child[ObjectData.ParentId] = previewHost.ClockManagerIndex;
                        entities.Add(child);
                    }
                    VerifyParity(entities);
                }
                finally
                {
                    foreach (var saved in savedChildren)
                    {
                        saved.Child.Position = saved.Position;
                        saved.Child[ObjectData.Direction] = saved.Direction;
                        saved.Child[ObjectData.ContainerId] = saved.ContainerId;
                        saved.Child[ObjectData.ParentId] = saved.ParentId;
                    }
                    world.Remove(previewHost.Id);
                }
            }
        }
        finally
        {
            DeleteTempTree(tempDir);
        }
    }

    [Fact]
    public void SimulationServer_PreviewObject_UsesFastGhostPathAndWritesZeroTempScenes()
    {
        var gameDir = LocateGameDirectory();
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

            Assert.True(server.Handle("""{"id":"viewEdit","op":"view","editing":true}"""));
            DrainEvents(outputStream, writer);

            Assert.True(server.Handle("""{"id":"catChair","op":"catalogPage","category":0,"offset":0,"count":8}"""));
            var chairCat = ResponseFor(DrainEvents(outputStream, writer), "catChair");
            var chairGuid = chairCat.GetProperty("result").GetProperty("items")[0].GetProperty("guid").GetUInt32();

            for (var step = 0; step < 5; step++)
            {
                var cmd = JsonSerializer.Serialize(new
                {
                    id = $"prev-{step}",
                    op = "previewObject",
                    guid = chairGuid,
                    x = (24 + step) * 16 + 8,
                    y = 24 * 16 + 8,
                    level = 1,
                    direction = 1,
                });
                Assert.True(server.Handle(cmd));
                var resp = ResponseFor(DrainEvents(outputStream, writer), $"prev-{step}");
                Assert.True(resp.GetProperty("ok").GetBoolean());
                var ghostEl = resp.GetProperty("result").GetProperty("ghost");
                var ghost = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
                    ghostEl.GetRawText(), PackContentPaths.JsonReadOptions)!;
                ghost.Validate();
                Assert.True(ghost.Scene.Sprites.Count > 0);
            }

            var sceneDir = Path.Combine(session, "scene");
            if (Directory.Exists(sceneDir))
                Assert.Empty(Directory.GetFiles(sceneDir, "scene-1000*.json"));
        }
        finally
        {
            Neighborhoods.Current = previousNeighborhood;
            DeleteTempTree(tempRoot);
        }
    }
}
