using System.Numerics;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;
using SimsSimulation;
using Xunit;

namespace SimsEngine.Tests;

public class House05ChairSittingTests
{
    private static string? LocateGameDirectory() => TestGameLocator.Locate();

    [Fact]
    public void House05_BellaCanRouteAroundPorchFenceAndSitInTableTuckedPatioChair224()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null || !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")))
            return;

        var lotPath = Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        var bootstrap = WorldBootstrap.Load(gameDir, lotPath);
        var world = bootstrap.World;
        world.AutonomyForced = false;
        world.AutonomyHost = null;

        var bella = Assert.IsType<XPerson>(world.ObjectById(18));
        var chair224 = Assert.IsAssignableFrom<XObject>(world.ObjectById(224));
        var target = InteractionMenus.Target(world, chair224);
        var sit = InteractionMenus.Read(world, bella, target)
            .FirstOrDefault(c => string.Equals(c.ActionText, "Sit", StringComparison.OrdinalIgnoreCase));
        Assert.NotNull(sit);
        Assert.True(world.EnqueueInteractionAction(bella, sit!));

        var controls = new SimulationClockControl(1, 1, 1);
        var seated = false;
        for (var tick = 0; tick < 450; tick++)
        {
            world.AdvanceSimulationTick(controls, 0, world.Clock.Ticks);
            if (bella[PersonData.Sitting] != 0 && bella[ObjectData.ParentId] == chair224.Id)
            {
                seated = true;
                break;
            }
        }

        Assert.True(seated, $"Bella failed to sit in chair 224 (pos={bella.Position}, routeResult={bella[PersonData.RouteResult]})");
        Assert.Equal(0, bella[PersonData.RouteResult]);
    }

    [Fact]
    public void PieHeadPreview_UsesUnclipped128x128CanvasFixedSkullPivotAndZeroRoll()
    {
        Assert.Equal(128, SimPortrait.PieHeadWidth);
        Assert.Equal(128, SimPortrait.PieHeadHeight);

        var lotOffset = new Vector3(45f, 0.55f, 35f);
        var positions = new[]
        {
            lotOffset + new Vector3(-0.08f, -0.10f,  0.08f),
            lotOffset + new Vector3( 0.08f, -0.10f,  0.08f),
            lotOffset + new Vector3( 0.00f,  0.10f,  0.08f),
            lotOffset + new Vector3(-0.08f, -0.10f, -0.08f),
            lotOffset + new Vector3( 0.08f, -0.10f, -0.08f),
            lotOffset + new Vector3( 0.00f,  0.10f, -0.08f),
            lotOffset + new Vector3(-0.10f, -0.14f, -0.13f),
            lotOffset + new Vector3( 0.10f, -0.14f, -0.13f),
            lotOffset + new Vector3( 0.00f,  0.11f, -0.13f),
        };
        var normals = Enumerable.Repeat(Vector3.UnitZ, positions.Length).ToArray();
        var uvs = Enumerable.Repeat(new Vector2(0.5f, 0.5f), positions.Length).ToArray();
        var onHead = new[] { true, true, true, true, true, true, false, false, false };
        var faces = new[] { (0, 1, 2), (3, 4, 5), (6, 7, 8) };
        var texture = BitmapCodec.Write(2, 2,
        [
            200, 120, 100, 255,  200, 120, 100, 255,
            200, 120, 100, 255,  200, 120, 100, 255,
        ]);
        var mesh = new AvatarSceneGeometry.PosedHeadMesh(positions, normals, uvs, onHead, faces, texture);

        const int size = SimPortrait.PieHeadWidth;
        var turned = SimPortrait.PieHeadPreview([mesh], -45f, 30f);
        Assert.Equal(size * size * 4, turned.Length);

        for (var i = 0; i < size; i++)
        {
            Assert.Equal(0, turned[(0 * size + i) * 4 + 3]);
            Assert.Equal(0, turned[((size - 1) * size + i) * 4 + 3]);
            Assert.Equal(0, turned[(i * size + 0) * 4 + 3]);
            Assert.Equal(0, turned[(i * size + (size - 1)) * 4 + 3]);
        }

        var gameDir = LocateGameDirectory();
        if (gameDir is null || !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")))
            return;

        var bootstrap = WorldBootstrap.Load(gameDir, Path.Combine(gameDir, "UserData", "Houses", "House05.iff"));
        var bella = Assert.IsType<XPerson>(bootstrap.World.ObjectById(18));
        var bellaHeadMeshes = AvatarSceneGeometry.For(gameDir, bootstrap.Registry)
            .BuildHeadMeshes(bella, 1, 0, (_, _) => 0f, new LotCamera(0, 64, 64));
        Assert.NotEmpty(bellaHeadMeshes);
        Assert.NotNull(bellaHeadMeshes[0].HeadPivot);
        Assert.True(bellaHeadMeshes[0].HeadHeight > 0f);

        foreach (var (yaw, pitch) in new[] { (0f, 8f), (-45f, 35f), (45f, -30f) })
        {
            var bellaTurned = SimPortrait.PieHeadPreview(bellaHeadMeshes, yaw, pitch);
            for (var i = 0; i < size; i++)
            {
                Assert.Equal(0, bellaTurned[(0 * size + i) * 4 + 3]);
                Assert.Equal(0, bellaTurned[((size - 1) * size + i) * 4 + 3]);
                Assert.Equal(0, bellaTurned[(i * size + 0) * 4 + 3]);
                Assert.Equal(0, bellaTurned[(i * size + (size - 1)) * 4 + 3]);
            }
        }

        var cassandra = Assert.IsType<XPerson>(bootstrap.World.ObjectById(16));
        var cassandraHeadMeshes = AvatarSceneGeometry.For(gameDir, bootstrap.Registry)
            .BuildHeadMeshes(cassandra, 1, 0, (_, _) => 0f, new LotCamera(0, 64, 64));
        if (cassandraHeadMeshes.Count >= 2)
        {
            var distinctTextures = cassandraHeadMeshes.Select(m => Convert.ToBase64String(m.Texture)).Distinct().Count();
            Assert.True(distinctTextures >= 2, "Companion head accessory mesh (glasses) must keep its own authored texture instead of inheriting HEAD-HEAD skin texture.");
        }
    }

    [Theory]
    [InlineData(21)]
    [InlineData(16)]
    public void House05_SimsCanTakeBathViaTubSecondarySubPart113(short simId)
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null || !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")))
            return;

        var bootstrap = WorldBootstrap.Load(gameDir, Path.Combine(gameDir, "UserData", "Houses", "House05.iff"));
        var world = bootstrap.World;
        world.AutonomyForced = false;
        world.AutonomyHost = null;

        var sim = Assert.IsType<XPerson>(world.ObjectById(simId));
        sim[Motive.Hygiene] = -50f;
        var tubSubPart113 = Assert.IsAssignableFrom<XObject>(world.ObjectById(113));
        var target = InteractionMenus.Target(world, tubSubPart113);
        var bath = InteractionMenus.Read(world, sim, target)
            .FirstOrDefault(c => string.Equals(c.ActionText, "Take a Bath", StringComparison.OrdinalIgnoreCase));
        Assert.NotNull(bath);
        Assert.True(world.EnqueueInteractionAction(sim, bath!));

        var controls = new SimulationClockControl(1, 1, 1);
        var startedBath = false;
        var censoredDuringBath = false;
        var playedAnims = new List<string>();
        for (var tick = 0; tick < 1200; tick++)
        {
            world.AdvanceSimulationTick(controls, 0, world.Clock.Ticks);
            var anim = sim.AnimationPlayback?.Clip.Name;
            if (!string.IsNullOrEmpty(anim) && !playedAnims.Contains(anim))
                playedAnims.Add(anim);
            if (anim is not null && anim.Contains("tub", StringComparison.OrdinalIgnoreCase))
                startedBath = true;
            if (startedBath && sim[PersonData.CensorshipFlags] != 0)
            {
                censoredDuringBath = true;
                break;
            }
        }

        Assert.True(startedBath, $"Sim {simId} failed to start bath via TubM 113 (pos={sim.Position}, routeResult={sim[PersonData.RouteResult]}, anims=[{string.Join(", ", playedAnims)}])");
        Assert.True(censoredDuringBath, $"Sim {simId} started bath via TubM 113 without setting CensorshipFlags (anims=[{string.Join(", ", playedAnims)}])");

        var geometry = AvatarSceneGeometry.For(gameDir, bootstrap.Registry);
        geometry.Build(sim, 1, 0, (_, _) => 0f, new LotCamera(0, 64, 64));
        var censor = geometry.Censor(sim);
        Assert.NotNull(censor);
        Assert.True(censor!.Width > 8f && censor.Height > 8f,
            $"Expected non-empty <skeleton>-needs censor bounds for bathing Sim {simId}, got {censor.Width}x{censor.Height}");
    }

    [Theory]
    [InlineData(191)]
    [InlineData(192)]
    public void House05_MortimerSeatedOnSofaCanStandAndExitThroughFrontDoorToPorchMagicKit(short sofaId)
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null || !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")))
            return;

        var lotPath = Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        var bootstrap = WorldBootstrap.Load(gameDir, lotPath);
        var world = bootstrap.World;
        world.AutonomyForced = false;
        world.AutonomyHost = null;
        world.CaptureExecutionTrace = true;

        var mortimer = Assert.IsType<XPerson>(world.ObjectById(21));
        var sofa = Assert.IsAssignableFrom<XObject>(world.ObjectById(sofaId));
        var sit = InteractionMenus.Read(world, mortimer, InteractionMenus.Target(world, sofa))
            .FirstOrDefault(c => string.Equals(c.ActionText, "Sit", StringComparison.OrdinalIgnoreCase));
        Assert.NotNull(sit);
        Assert.True(world.EnqueueInteractionAction(mortimer, sit!));

        var controls = new SimulationClockControl(1, 1, 1);
        var seated = false;
        for (var tick = 0; tick < 450; tick++)
        {
            world.AdvanceSimulationTick(controls, 0, world.Clock.Ticks);
            if (mortimer[PersonData.Sitting] != 0 && mortimer[ObjectData.ParentId] == sofaId)
            {
                seated = true;
                break;
            }
        }
        Assert.True(seated, $"Mortimer failed to sit on sofa {sofaId} (pos={mortimer.Position}, routeResult={mortimer[PersonData.RouteResult]})");

        const int magicStarterKitGuid = 427612988; // 0x197C64FC: Magic - Starter Kit
        var kit = world.ObjectFactory?.Invoke(magicStarterKitGuid);
        if (kit is null)
            return;
        kit.Position = new ObjectPosition(-16, -16, 1);
        world.Add(kit);
        world.InitializeCreatedObject(kit);
        var kitPos = new ObjectPosition(30 * 16 + 8, 27 * 16 + 8, 1);
        Assert.True(world.CanPlaceObject(kit, kitPos),
            $"Failed to place Magic - Starter Kit on front porch (error=0x{world.LastPlacementFailureCode:X2})");
        world.PlaceObject(kit, kitPos);

        // Simulate persisted high RouteIds on Kitchen door (94/95) and Bathroom door (56/57)
        // with unpopulated PortalRouteCosts, matching a reloaded save.
        Assert.IsAssignableFrom<XObject>(world.ObjectById(94))[ObjectData.RouteId] = 24;
        Assert.IsAssignableFrom<XObject>(world.ObjectById(95))[ObjectData.RouteId] = 25;
        Assert.IsAssignableFrom<XObject>(world.ObjectById(56))[ObjectData.RouteId] = 26;
        Assert.IsAssignableFrom<XObject>(world.ObjectById(57))[ObjectData.RouteId] = 27;

        world.NativeRouteTrace.Clear();
        var kitMenu = InteractionMenus.Read(world, mortimer, InteractionMenus.Target(world, kit));
        var kitAction = kitMenu.FirstOrDefault(c => string.Equals(c.ActionText, "Open", StringComparison.OrdinalIgnoreCase))
            ?? kitMenu.FirstOrDefault();
        Assert.NotNull(kitAction);
        Assert.True(world.EnqueueInteractionAction(mortimer, kitAction!));

        var stoodUp = false;
        var startedKitRoute = false;
        var completedKitAction = false;
        var reachedFrontPorch = false;
        for (var tick = 0; tick < 900; tick++)
        {
            world.AdvanceSimulationTick(controls, 0, world.Clock.Ticks);
            if (world.DialogRecords.Count > 0)
            {
                foreach (var dialog in world.DialogRecords.Where(d => d.Visible).ToArray())
                    world.RespondMessageDialog(dialog.Token, 0);
            }
            if (mortimer[PersonData.Sitting] == 0)
                stoodUp = true;
            if (ReferenceEquals(mortimer.CurrentActionRecord?.Owner, kit))
                startedKitRoute = true;
            if (mortimer.Position.X >= 26 * 16 && mortimer.Position.Y >= 25 * 16)
                reachedFrontPorch = true;
            if (startedKitRoute && mortimer.CurrentActionRecord?.Owner is null &&
                mortimer.ActionQueueCurrent == mortimer.ActionQueueEnd)
            {
                completedKitAction = true;
                break;
            }
        }

        Assert.True(stoodUp, $"Mortimer stayed seated on sofa {sofaId}");
        Assert.True(startedKitRoute, "Mortimer never started the Magic - Starter Kit interaction");
        Assert.True(reachedFrontPorch, $"Mortimer failed to reach the front porch (pos={mortimer.Position}, routeResult={mortimer[PersonData.RouteResult]})");
        Assert.True(completedKitAction, $"Mortimer did not finish opening Magic - Starter Kit (pos={mortimer.Position}, routeResult={mortimer[PersonData.RouteResult]}, current={mortimer.CurrentActionRecord?.ActionText})");
        Assert.Equal(0, mortimer[PersonData.RouteResult]);

        var portalRankings = world.NativeRouteTrace
            .Where(t => t.ActorId == mortimer.Id && t.Phase == "portal-ranking")
            .Select(t => t.Failure ?? "")
            .ToArray();
        Assert.Contains(portalRankings, r => r.Contains("selected=52", StringComparison.Ordinal) || r.Contains("selected=51", StringComparison.Ordinal));
        Assert.DoesNotContain(portalRankings, r => r.Contains("selected=94", StringComparison.Ordinal) || r.Contains("selected=56", StringComparison.Ordinal));
    }

    [Fact]
    public void House05_MortimerSeatedOnSofaCanStandAndRouteToBookshelf132()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null || !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")))
            return;

        var lotPath = Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        var bootstrap = WorldBootstrap.Load(gameDir, lotPath);
        var world = bootstrap.World;
        world.AutonomyForced = false;
        world.AutonomyHost = null;

        var mortimer = Assert.IsType<XPerson>(world.ObjectById(21));
        var sofa191 = Assert.IsAssignableFrom<XObject>(world.ObjectById(191));
        var sit = InteractionMenus.Read(world, mortimer, InteractionMenus.Target(world, sofa191))
            .FirstOrDefault(c => string.Equals(c.ActionText, "Sit", StringComparison.OrdinalIgnoreCase));
        Assert.NotNull(sit);
        Assert.True(world.EnqueueInteractionAction(mortimer, sit!));

        var controls = new SimulationClockControl(1, 1, 1);
        var seated = false;
        for (var tick = 0; tick < 450; tick++)
        {
            world.AdvanceSimulationTick(controls, 0, world.Clock.Ticks);
            if (mortimer[PersonData.Sitting] != 0 && mortimer[ObjectData.ParentId] == sofa191.Id)
            {
                seated = true;
                break;
            }
        }
        Assert.True(seated, $"Mortimer failed to sit on sofa 191 (pos={mortimer.Position})");

        var bookshelf = Assert.IsAssignableFrom<XObject>(world.ObjectById(132));
        var readBook = InteractionMenus.Read(world, mortimer, InteractionMenus.Target(world, bookshelf))
            .FirstOrDefault(c => string.Equals(c.ActionText, "Read a Book", StringComparison.OrdinalIgnoreCase))
            ?? InteractionMenus.Read(world, mortimer, InteractionMenus.Target(world, bookshelf)).FirstOrDefault();
        Assert.NotNull(readBook);
        Assert.True(world.EnqueueInteractionAction(mortimer, readBook!));

        var reachedBookshelf = false;
        for (var tick = 0; tick < 450; tick++)
        {
            world.AdvanceSimulationTick(controls, 0, world.Clock.Ticks);
            if (mortimer[PersonData.Sitting] == 0 &&
                Math.Abs((mortimer.Position.X >> 4) - 25) <= 1 &&
                Math.Abs((mortimer.Position.Y >> 4) - 24) <= 1 &&
                mortimer[PersonData.RoutingComplete] != 0)
            {
                reachedBookshelf = true;
                break;
            }
        }

        Assert.True(reachedBookshelf, $"Seated Mortimer failed to route to Bookshelf 132 (pos={mortimer.Position}, sitting={mortimer[PersonData.Sitting]}, routeResult={mortimer[PersonData.RouteResult]})");
        Assert.Equal(0, mortimer[PersonData.RouteResult]);
    }

    [Theory]
    [InlineData(330, 392, 2)]
    [InlineData(328, 394, 4)]
    [InlineData(326, 393, 6)]
    public void House05_CassandraRoutesShortStepToToilet110WithoutTurnAdjustLoop(
        int startX, int startY, short startDir)
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null || !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")))
            return;

        var lotPath = Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        var bootstrap = WorldBootstrap.Load(gameDir, lotPath);
        var world = bootstrap.World;
        world.AutonomyForced = false;
        world.AutonomyHost = null;

        var controls = new SimulationClockControl(1, 1, 1);
        for (var warmup = 0; warmup < 120; warmup++)
            world.AdvanceSimulationTick(controls, 0, world.Clock.Ticks);

        var cassandra = Assert.IsType<XPerson>(world.ObjectById(16));
        var toilet = Assert.IsAssignableFrom<XObject>(world.ObjectById(110));
        world.SetObjectPosition(cassandra, new ObjectPosition(startX, startY, 1));
        world.RefreshPersonRoomStateAfterMovement(cassandra);
        cassandra[ObjectData.Direction] = startDir;
        cassandra.AnimatorRootX = startX;
        cassandra.AnimatorRootY = startY;
        cassandra.AnimatorRootDirection = startDir;
        cassandra[Motive.Bladder] = -80;

        var use = InteractionMenus.Read(world, cassandra, InteractionMenus.Target(world, toilet))
            .FirstOrDefault(c => string.Equals(c.ActionText, "Use", StringComparison.OrdinalIgnoreCase));
        Assert.NotNull(use);
        Assert.True(world.EnqueueInteractionAction(cassandra, use!));

        var snappedToToilet = false;
        var stateFiveEntries = 0;
        var previousControl = cassandra.AnimatorControlState;
        for (var tick = 0; tick < 180; tick++)
        {
            world.AdvanceSimulationTick(controls, 0, world.Clock.Ticks);
            if (cassandra.AnimatorControlState == 5 && previousControl != 5)
                stateFiveEntries++;
            previousControl = cassandra.AnimatorControlState;

            if (cassandra.Position.X == toilet.Position.X && cassandra.Position.Y == toilet.Position.Y)
            {
                snappedToToilet = true;
                break;
            }
        }

        Assert.True(snappedToToilet,
            $"Cassandra failed to reach Toilet 110 from ({startX},{startY}) dir={startDir}: pos={cassandra.Position}, root=({cassandra.AnimatorRootX},{cassandra.AnimatorRootY}), ctrl={cassandra.AnimatorControlState}, state5Entries={stateFiveEntries}");
        Assert.InRange(stateFiveEntries, 1, 2);
        Assert.Equal(0, cassandra[PersonData.RouteResult]);
    }
}
