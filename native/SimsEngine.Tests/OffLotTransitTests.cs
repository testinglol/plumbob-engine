using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.Tests.E2E;
using SimsEngine.World;
using SimsSimulation;

namespace SimsEngine.Tests;

[Collection("Neighborhoods")]
public sealed class OffLotTransitTests
{
    private static RoomMap FlatOutdoorMap()
    {
        var walls = new ChunkBuilder().S16(0).S16(0).S32(64).S32(64).S32(8).U32(0).Raw(new byte[64 * 64 * 8]);
        var lot = new IffFile(ChunkBuilder.File(("Arry", 2, walls.ToArray())), "flat.iff");
        return RoomMap.Build(lot, 1, 64, 64);
    }

    [Fact]
    public void PedestrianAndPetSpawnAndExit_WalkInFromOffScreenAndWalkOutPastScreenWhileBlockingOutsideInteraction()
    {
        var (context, _, _) = PrimitiveTestWorld.Create(stackObject: 1);
        var world = context.World;
        world[SimulationGlobal.LotSize] = 52;
        world.LotRoomMaps[1] = FlatOutdoorMap();

        var resident = world.Add(new XPerson(2, PrimitiveTestWorld.Definition(XPerson.PersonType)));
        resident.TypeRecord = new TypeRecord(2) { Name = "Resident" };
        resident[ObjectData.AllowedHeightFlags] = 1;
        world.SetObjectPosition(resident, new ObjectPosition(25 * 16 + 8, 25 * 16 + 8, 1));

        var portal = world.Add(new XObject(6, PrimitiveTestWorld.Definition()));
        portal.TypeRecord = new TypeRecord(unchecked((int)0x81E6BEF9)) { Name = "Portal - Pedestrian" };
        portal.RuntimeClass = ObjectClass.Portal;
        world.SetObjectPosition(portal, new ObjectPosition(41 * 16 + 8, 1 * 16 + 8, 1));

        world.StandardWalkFallbackAnimationTable[(152, 20)] = new AvatarAnimationClip("d2o-walk", 20, [], null, 0.5f, default, null, 667f);
        world.StandardWalkFallbackAnimationTable[(150, 20)] = new AvatarAnimationClip("d2o-walk", 20, [], null, 0.5f, default, null, 667f);
        world.CustomWalkAvatarAnimationTable[(0x4A70DF92u, 20)] = new AvatarAnimationClip("d2o-walk", 20, [], null, 0.5f, default, null, 667f);
        world.OffLotTransit.CaptureBaseline(world);

        var strayDog = world.Add(new XPerson(50, PrimitiveTestWorld.Definition(XPerson.PersonType)));
        var ttabBytes = new ChunkBuilder().S16(1).S16(8)
            .U16(0x1000).U16(0).S32(0).U32(0).S32(1).U32(0).F32(0).U32(0).S32(0)
            .ToArray();
        var bhavBytes = new ChunkBuilder()
            .U16(0x8002).S16(1).U8(0).U8(0).U8(0).U8(0).U32(0)
            .U16(0x0002).U8(0xfe).U8(0xff).Raw([0, 0, 0, 0, 0, 5, 0, 7])
            .ToArray();
        var strBytes = new ChunkBuilder()
            .S16(-3).U16(1).U8(1).Raw("Pet\0"u8.ToArray()).U8(0)
            .ToArray();
        var petIff = new IffFile(ChunkBuilder.File(("TTAB", 1, ttabBytes), ("BHAV", 0x1000, bhavBytes), ("TTAs", 1, strBytes)), "dog.iff");
        var scope = new SimsEngine.Content.BehaviorScope(petIff, petIff, null);
        strayDog.TypeRecord = new TypeRecord(50)
        {
            Name = "Stray Dog",
            BehaviorScope = scope,
            Interactions = InteractionTable.Read(petIff, petIff.Find(ResourceType.Ttab, 1)!).WithNames(_ => "Pet"),
        };
        strayDog[PersonData.Gender] = 2;
        strayDog[ObjectData.Direction] = 0;
        strayDog[ObjectData.AllowedHeightFlags] = 1;
        world.ClockManager.Register(strayDog);
        world.ClockManager.SetTickEnabled(strayDog, true);
        world.SetObjectPosition(strayDog, new ObjectPosition(41 * 16 + 8, 1 * 16 + 8, 1));

        world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);

        Assert.True(world.OffLotTransit.TryGetApproachingPersonVisual(strayDog.Id, 0f, out var startTile, out _));
        Assert.True(startTile.Y < -15f, $"Expected off-screen start Y < -15, got {startTile.Y}");
        Assert.Equal((short)4, strayDog[ObjectData.Direction]);
        Assert.True(world.OffLotTransit.IsEntityOutsideLotBounds(world, strayDog.Id));
        Assert.Empty(InteractionMenus.Read(world, resident, strayDog));
        Assert.NotNull(strayDog.AnimationPlayback);
        float initialFrame = strayDog.AnimationPlayback!.Frame;
        world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
        Assert.NotNull(strayDog.AnimationPlayback);
        Assert.True(strayDog.AnimationPlayback!.Frame > initialFrame);

        for (int i = 0; i < 600 && world.OffLotTransit.TryGetApproachingPersonVisual(strayDog.Id, 0f, out _, out _); i++)
        {
            world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
        }

        Assert.False(world.OffLotTransit.TryGetApproachingPersonVisual(strayDog.Id, 0f, out _, out _));
        Assert.False(world.OffLotTransit.IsEntityOutsideLotBounds(world, strayDog.Id));
        Assert.NotEmpty(InteractionMenus.Read(world, resident, strayDog));

        world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
        world.Remove(strayDog.Id);
        world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);

        Assert.Single(world.OffLotTransit.DepartingPeople);
        var dep = world.OffLotTransit.DepartingPeople[0];
        Assert.True(dep.SyntheticObjectId >= OffLotTransitManager.SyntheticIdBase);
        Assert.True(world.OffLotTransit.IsEntityOutsideLotBounds(world, dep.SyntheticObjectId));

        for (int i = 0; i < 700 && world.OffLotTransit.DepartingPeople.Count > 0; i++)
        {
            world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
        }

        Assert.Empty(world.OffLotTransit.DepartingPeople);
    }

    [Fact]
    public void SchoolBus_EntersFromOffScreenAndDrivesOutPastScreenOnHouse05()
    {
        if (!E2EHarness.TryLocateGameDir(out var gameDir) || !E2EHarness.HasHouses(gameDir, 5))
            return;

        using var profile = E2EHarness.CreateIsolatedProfile(gameDir, 5);
        using var server = E2EHarness.StartServer(profile, house: 5);
        var world = server.World!;
        server.HandleJson("freeWill", new { enabled = false });
        world.Clock.Restore(7, 59, 0);

        Assert.False(server.HandleJson("groundMenu", new { x = -32, y = 41 * 16 + 8, level = 1 }).GetProperty("ok").GetBoolean());
        Assert.False(server.HandleJson("groundMenu", new { x = 8, y = 41 * 16 + 8, level = 1 }).GetProperty("ok").GetBoolean());
        Assert.False(server.HandleJson("groundMenu", new { x = 41 * 16 + 8, y = 51 * 16 + 8, level = 1 }).GetProperty("ok").GetBoolean());
        Assert.False(server.HandleJson("groundMenu", new { x = 41 * 16 + 8, y = 58 * 16 + 8, level = 1 }).GetProperty("ok").GetBoolean());
        Assert.True(server.HandleJson("groundMenu", new { x = 41 * 16 + 8, y = 2 * 16 + 8, level = 1 }).GetProperty("ok").GetBoolean());

        bool sawOffScreenApproach = false;
        bool sawOnLotParked = false;
        bool sawOffScreenDeparture = false;

        for (int step = 0; step < 3000; step++)
        {
            while (world.HasVisibleBlockingDialog)
            {
                var b = world.DialogRecords.FirstOrDefault(d => d.Visible && d.Blocking && d.State < 2);
                if (b is null) break;
                server.HandleJson("dialogResponse", new { token = b.Token, code = (byte)0 });
            }
            server.BatchRun(1);

            if (world.OffLotTransit.ApproachingVehicles.Count > 0)
            {
                var app = world.OffLotTransit.ApproachingVehicles.First();
                if (app.CurrentLeadY < -10f)
                {
                    if (!sawOffScreenApproach)
                    {
                        var menuResp = server.HandleJson("menu", new { objectID = app.LeadId });
                        Assert.True(menuResp.GetProperty("ok").GetBoolean());
                        Assert.Equal(0, menuResp.GetProperty("result").GetArrayLength());
                        Assert.False(server.HandleJson("interact", new { objectID = app.LeadId, interaction = 0, param0 = 0 }).GetProperty("ok").GetBoolean());
                        Assert.True(server.HandleJson("scene").GetProperty("ok").GetBoolean());
                        using var sceneDoc = server.ReadLatestScene();
                        var nonInteractive = sceneDoc.RootElement.GetProperty("nonInteractiveObjectIds").EnumerateArray().Select(e => e.GetInt32()).ToHashSet();
                        Assert.Contains(app.LeadId, nonInteractive);
                    }
                    sawOffScreenApproach = true;
                    Assert.True(world.OffLotTransit.IsEntityOutsideLotBounds(world, app.LeadId));
                }
            }
            else if (sawOffScreenApproach && !sawOnLotParked)
            {
                var bus = world.WalkOrder.FirstOrDefault(o => o is not XPerson && o.MultiTileMasterId == 0 &&
                    (o.TypeRecord?.Name?.Contains("School Bus", StringComparison.OrdinalIgnoreCase) ?? false));
                if (bus is not null)
                {
                    sawOnLotParked = true;
                    Assert.False(world.OffLotTransit.IsEntityOutsideLotBounds(world, bus.Id));
                }
            }

            if (world.OffLotTransit.DepartingVehicles.Count > 0)
            {
                var dep = world.OffLotTransit.DepartingVehicles[0];
                if (dep.CurrentLeadY > 75f)
                {
                    sawOffScreenDeparture = true;
                    break;
                }
            }
        }

        Assert.True(sawOffScreenApproach, "Expected School Bus to approach from off-screen (Y < -10).");
        Assert.True(sawOnLotParked, "Expected School Bus to pull up and park on-lot.");
        Assert.True(sawOffScreenDeparture, "Expected School Bus to continue driving past Y > 75 off-screen.");
    }
}
