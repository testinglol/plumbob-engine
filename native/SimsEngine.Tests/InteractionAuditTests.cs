using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsSimulation;
using Xunit;

namespace SimsEngine.Tests;

public sealed class InteractionAuditTests
{
    [Fact]
    public void BytecodeCensus_AggregatesOpcodesSubModesAndFlagsUnknownAndInvalidCalls()
    {
        var bhavBytes = BuildBhav(
            (0x01, [0x01, 0x00, 0, 0, 0, 0, 0, 0]),
            (0x01, [0x07, 0x00, 0, 0, 0, 0, 0, 0]),
            (0x1f, [0, 0, 0, 0, 0x87, 0x09, 0, 0]),
            (0x2c, [0x05, 0x00, 0, 0, 0x00, 0x20, 0, 0]),
            (0x26, [0, 0, 0, 0, 0, 0, 0, 0]),
            (0x0101, [0, 0, 0, 0, 0, 0, 0, 0]));

        var iff = new IffFile(ChunkBuilder.File(("BHAV", 0x1000, bhavBytes)), "synthetic.iff");
        var globalIff = new IffFile(ChunkBuilder.File(("BHAV", 0x0100, BuildBhav((0x00, [1, 0, 0, 0, 0, 0, 0, 0])))), "global.iff");

        var report = InteractionCensus.Analyze(
            [new CensusFileInput("Objects", "synthetic.iff", iff)],
            globalIff);

        Assert.Equal(1, report.FilesScanned);
        Assert.Equal(1, report.BhavTreesScanned);
        Assert.Equal(6, report.InstructionsScanned);
        Assert.Equal(5, report.PrimitiveInstructions);
        Assert.Equal(1, report.TreeCallInstructions);

        var unknown = Assert.Single(report.UnknownOpcodes);
        Assert.Equal((ushort)0x26, unknown.Opcode);

        var invalidCall = Assert.Single(report.InvalidGenericCalls);
        Assert.Equal((ushort)0x07, invalidCall.TargetId);

        var missingRef = Assert.Single(report.MissingTreeReferences);
        Assert.Equal((ushort)0x0101, missingRef.TargetId);

        var setToNext = Assert.Single(report.Opcodes, o => o.Opcode == 0x1f);
        var mode = Assert.Single(setToNext.SubModes);
        Assert.Equal("mode=7 var=1", mode.Key);

        var animate = Assert.Single(report.Opcodes, o => o.Opcode == 0x2c);
        var animMode = Assert.Single(animate.SubModes);
        Assert.Equal("src=0 flags=0x20", animMode.Key);
    }

    [Fact]
    public void MissingAnimationTrace_RecordedOnlyWhenExecutionTraceEnabled()
    {
        var world = new SimulationWorld();
        var definition = new short[108];
        definition[9] = XPerson.PersonType;
        var person = new XPerson(1, definition) { AnimatorControlState = 3, TypeRecord = new TypeRecord(0x1234) };
        world.Add(person);

        var frame = new StackFrame(person.Id, [0], [0]) { TreeId = 0x1000, Instruction = 3 };
        var context = new TreeContext(world, person, frame);
        byte[] operand = [0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00];

        world.CaptureExecutionTrace = false;
        _ = AnimateSimPrimitive.Execute(context, operand);
        Assert.Empty(world.MissingAnimationTrace);

        person.PrimaryAnimationWaiting = false;
        world.CaptureExecutionTrace = true;
        _ = AnimateSimPrimitive.Execute(context, operand);
        var recorded = Assert.Single(world.MissingAnimationTrace);
        Assert.Equal(person.Id, recorded.PersonId);
        Assert.Equal((short)0x1000, recorded.Tree);
        Assert.Equal(3, recorded.Instruction);
        Assert.Equal((short)0x2a, recorded.AnimationId);
        Assert.Equal((ushort)129, recorded.TableId);

        world.ClearExecutionTraces();
        Assert.Empty(world.MissingAnimationTrace);
    }

    [Fact]
    public void FailureClusterer_GroupsDistinctObjectsByRootSignatureAndExcludesSucceeded()
    {
        var trials = new List<InteractionTrialRecord>
        {
            new("Base", "Residential", 5, 0x1001, "Stove A", "floor-indoor", 1, "Cook", 0x1000, 0x1001,
                InteractionOutcomeKind.EarlyBailout, 5, "EarlyBailout:0x0200:4:FindLocationFor:mode=0 flags=0x04",
                "bailout detail", 0f, 0, 0, 0, 0, 0, 0),
            new("LivinLarge", "Residential", 5, 0x1002, "Stove B", "floor-indoor", 2, "Serve", 0x1002, 0x1003,
                InteractionOutcomeKind.EarlyBailout, 7, "EarlyBailout:0x0200:4:FindLocationFor:mode=0 flags=0x04",
                "bailout detail", 0f, 0, 0, 0, 0, 0, 0),
            new("HouseParty", "Residential", 5, 0x2001, "Lamp", "surface-h3", 0, "Turn On", 0x1005, 0x1006,
                InteractionOutcomeKind.Succeeded, 12, "OK", "ok", 0f, 0, 1, 0, 0, 0, 0),
            new("HotDate", "Downtown", 21, 0x3001, "Podium", "floor-indoor", 0, "Seat", 0x1010, 0x1011,
                InteractionOutcomeKind.ThreadError, 2, "ThreadError:StackNumberOutOfRange:SemiGlobal:0x2010:3:Expression",
                "stack error", 0f, 0, 0, 0, 0, 1, 0),
        };

        var clusters = InteractionOutcomeSweeper.ClusterFailures(trials);

        Assert.Equal(2, clusters.Count);
        Assert.Equal(InteractionOutcomeKind.EarlyBailout, clusters[0].OutcomeKind);
        Assert.Equal(2, clusters[0].Count);
        Assert.Equal(2, clusters[0].DistinctObjects);
        Assert.Equal(["Base", "LivinLarge"], clusters[0].Packs);

        Assert.Equal(InteractionOutcomeKind.ThreadError, clusters[1].OutcomeKind);
        Assert.Equal(1, clusters[1].Count);
    }

    [Fact]
    public void Remove_ScrubsSavedPersonObjectReferencesAndResetSkipsRemovedObjects()
    {
        var world = new SimulationWorld();
        var personDef = new short[108];
        personDef[9] = XPerson.PersonType;
        var person = world.Add(new XPerson(1, personDef) { TypeRecord = new TypeRecord(0x1111) });

        var objDef = new short[108];
        var obj = world.Add(new XObject(2, objDef) { TypeRecord = new TypeRecord(0x2222) });
        person.SavedPersonObjectReferences.Add(new PersonObjectReference(obj.StackObjectKey, obj, 1, false));
        person.SetCurrentActionSecondaryReference(obj);

        Assert.True(world.Remove(obj.Id));
        Assert.Empty(person.SavedPersonObjectReferences);
        Assert.Null(person.GenericSimsCall02ObjectA54);

        world.ResetObjectForChangedCode(obj);
        Assert.Empty(world.ThreadErrors);
    }

    [Fact]
    public void SleepPrimitive_UnregisteredObject_CountsDownWithoutThrowingArgumentOutOfRange()
    {
        var world = new SimulationWorld();
        var def = new short[108];
        var detached = new XObject(42, def);
        var frame = new StackFrame(0, [2], []);
        var context = new TreeContext(world, detached, frame);
        byte[] operand = [0, 0, 0, 0, 0, 0, 0, 0];

        Assert.Equal(PrimitiveResult.Stop, SleepPrimitive.Execute(context, operand));
        Assert.Equal((short)1, frame.Parameters[0]);
        Assert.Equal(PrimitiveResult.Stop, SleepPrimitive.Execute(context, operand));
        Assert.Equal((short)0, frame.Parameters[0]);
        Assert.Equal(PrimitiveResult.True, SleepPrimitive.Execute(context, operand));
    }

    [Fact]
    public void TestObjectTypePrimitive_ResolvesStackObjectKeyWhenDifferentFromObjectId()
    {
        var world = new SimulationWorld();
        var me = world.Add(new XObject(1, new short[108]));
        var target = world.Add(new XObject(2, new short[108]) { TypeRecord = new TypeRecord(0x55AA) });
        me.SetObjectTableEntry(7, target);
        var frame = new StackFrame(7, [], []);
        var context = new TreeContext(world, me, frame);
        byte[] operand = [0xAA, 0x55, 0x00, 0x00, 0x00, 0x00, (byte)DataOwner.StackObjectId, 0x00];

        Assert.Equal(PrimitiveResult.True, TestObjectTypePrimitive.Execute(context, operand));
    }

    [Fact]
    public void BeginObjectRemoval_PromotesOverlappingTileRootChildToTileGrid()
    {
        var world = new SimulationWorld();
        var under = world.Add(new XObject(2, new short[108]) { Position = new ObjectPosition(10 * 16 + 8, 12 * 16 + 8, 1) });
        var root = world.Add(new XObject(1, new short[108]) { Position = new ObjectPosition(10 * 16 + 8, 12 * 16 + 8, 1) });
        root.Slots.Add(under.ClockManagerIndex);
        under[ObjectData.ParentId] = root.ClockManagerIndex;
        under[ObjectData.SlotHierNumber] = 0;

        world.BeginObjectRemoval(root, 1);

        Assert.Equal(under.ClockManagerIndex, world.TileValueAt(10, 12, 1));
    }

    [Fact]
    public void GetDirectionToPrimitive_ResolvesStackObjectKeyWhenDifferentFromObjectId()
    {
        var world = new SimulationWorld();
        var me = world.Add(new XObject(1, new short[108]) { Position = new ObjectPosition(10 * 16 + 8, 10 * 16 + 8, 1) });
        var target = world.Add(new XObject(2, new short[108]) { Position = new ObjectPosition(12 * 16 + 8, 10 * 16 + 8, 1) });
        me.SetObjectTableEntry(7, me);
        me.SetObjectTableEntry(8, target);
        me.Temporaries[1] = 7;
        var frame = new StackFrame(8, [], [0, 0]);
        var context = new TreeContext(world, me, frame);
        byte[] operand = [0x00, 0x00, (byte)DataOwner.Local, 0x00, 0x01, (byte)DataOwner.Temporary, 0x01, 0x00];

        Assert.Equal(PrimitiveResult.True, GetDirectionToPrimitive.Execute(context, operand));
        Assert.Equal((short)2, frame.Locals[0]);
    }

    [Fact]
    public void InitializeCreatedObject_ClearsPreInitTileRootSoWalkNearTileDoesNotLoop()
    {
        var world = new SimulationWorld();
        var anchor = world.Add(new XObject(1, new short[108])
        {
            Position = new ObjectPosition(25 * 16 + 8, 24 * 16 + 8, 1),
            RoomWord84 = 0,
        });
        var created = new XObject(2, new short[108])
        {
            Position = new ObjectPosition(24 * 16 + 8, 24 * 16 + 8, 1),
            RoomWord84 = 0,
        };
        world.Add(created);
        Assert.Equal(created.ClockManagerIndex, world.TileValueAt(24, 24, 1));

        world.InitializeCreatedObject(created);
        Assert.Equal(0, world.TileValueAt(24, 24, 1));

        world.PlaceObject(created, new ObjectPosition(25 * 16 + 8, 26 * 16 + 8, 1));
        Assert.Equal(0, world.TileValueAt(24, 24, 1));
        Assert.Equal(created.ClockManagerIndex, world.TileValueAt(25, 26, 1));

        var frame = new StackFrame(0, [], [anchor.StackObjectKey]);
        var context = new TreeContext(world, anchor, frame);
        byte[] operand = [0, 0, 0, 0, 0x89, (byte)DataOwner.StackObjectId, 0, 0];

        Assert.Equal(PrimitiveResult.False, SetToNextPrimitive.Execute(context, operand));
    }

    [Fact]
    public void RouteExecutor_ReinitializesMotionAnimationIndexWhenPendingTargetExists()
    {
        var world = new SimulationWorld();
        const int size = 16;
        var walls = new ChunkBuilder().S16(0).S16(0).S32(size).S32(size).S32(8).U32(0);
        var terrain = new ChunkBuilder().S16(0).S16(0).S32(size).S32(size).S32(1).U32(0);
        for (var tile = 0; tile < size * size; tile++)
        {
            walls.Raw(new byte[8]);
            terrain.U8(0x10);
        }
        var lot = new IffFile(ChunkBuilder.File(("Arry", 2, walls.ToArray()), ("Arry", 9, terrain.ToArray())), "route-test.iff");
        world.LoadRoomMaps(new Dictionary<int, SimsEngine.World.RoomMap> { [1] = SimsEngine.World.RoomMap.Build(lot, 1, size, size) });
        var personDef = new short[108];
        personDef[9] = XPerson.PersonType;
        var person = world.Add(new XPerson(1, personDef)
        {
            Position = new ObjectPosition(6 * 16 + 8, 6 * 16 + 8, 1),
            TypeRecord = new TypeRecord(0x1111) { ObjectType = XPerson.PersonType },
            AnimatorControlState = 3,
        });
        person[ObjectData.AllowedHeightFlags] = 0x41;
        var anchor = world.Add(new XObject(2, new short[108])
        {
            Position = new ObjectPosition(8 * 16 + 8, 6 * 16 + 8, 1),
            TypeRecord = new TypeRecord(0x2222),
        });
        var clip = new AvatarAnimationClip("a2o-walk-test", 4, [], DurationMilliseconds: 400f,
            StandardRootMotionSamples: [new(0f, 0f, 0f), new(4f, 0f, 0f), new(8f, 0f, 0f), new(16f, 0f, 0f)]);
        for (short skill = 11; skill <= 22; skill++)
            world.StandardWalkFallbackAnimationTable[(150, skill)] = clip;

        var startPos = person.Position;
        var nextPos = new ObjectPosition(7 * 16 + 8, 6 * 16 + 8, 1);
        var path = new[]
        {
            new RouteExecutor.RouteWaypoint(startPos.X >> 4, startPos.Y >> 4, startPos.X, startPos.Y, startPos.X, startPos.Y, false),
            new RouteExecutor.RouteWaypoint(nextPos.X >> 4, nextPos.Y >> 4, nextPos.X, nextPos.Y, nextPos.X, nextPos.Y, true),
        };
        var slot = new RoutingSlotRequest { MinProximity = 16, MaxProximity = 16, OptimalProximity = 16, Standing = 1, Facing = -3 };
        person.NativeRoute = new RouteState(anchor.Id, nextPos, slot, MotionAnimationIndex: -1, MotionDirection: 2, StandChecked: true, AnimatorFollowState: 2)
        {
            MotionPath = path,
            MotionTargetPathIndex = 1,
            MotionTargetTileX = nextPos.X >> 4,
            MotionTargetTileY = nextPos.Y >> 4,
            MotionTargetX = nextPos.X,
            MotionTargetY = nextPos.Y,
            MotionTargetIsDestination = true,
            MotionX = startPos.X,
            MotionY = startPos.Y,
            FollowPath = path,
            FollowWaypointIndex = 1,
        };
        world.CaptureExecutionTrace = true;
        var frame = new StackFrame(anchor.Id, [], []);
        var result = RouteExecutor.Continue(world, person, frame, null);

        Assert.DoesNotContain(world.NativeRouteTrace, t => t.Phase == "walk-skill-missing");
        Assert.NotEqual(PrimitiveResult.False, result);
    }

    [Theory]
    [InlineData(21, false, "Downtown")]
    [InlineData(40, true, "Vacation")]
    [InlineData(50, true, "Community")]
    [InlineData(81, false, "StudioTown")]
    [InlineData(90, true, "MagicTown")]
    [InlineData(99, false, "GiantsCloud")]
    public void SimulationServer_RoundTripTravel_AllSubhoodsAndGiantsCloud(short destinationHouse, bool wholeFamily, string label)
    {
        var gameDir = Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "../../../../../runtime/game"));
        var homePath = Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        var destPath = Path.Combine(gameDir, "UserData", "Houses", $"House{destinationHouse:D2}.iff");
        var nghPath = Path.Combine(gameDir, "UserData", "Neighborhood.iff");
        if (!Directory.Exists(gameDir) || !File.Exists(homePath) || !File.Exists(destPath) || !File.Exists(nghPath))
            return;

        var tempRoot = Path.Combine(Path.GetTempPath(), $"sims-travel-rt-{destinationHouse}-{Guid.NewGuid():N}");
        try
        {
            var profile = Path.Combine(tempRoot, "profile");
            var userData = Path.Combine(profile, "UserData");
            Directory.CreateDirectory(Path.Combine(userData, "Houses"));
            var charsDir = Path.Combine(userData, "Characters");
            Directory.CreateDirectory(charsDir);
            foreach (var charFile in Directory.EnumerateFiles(Path.Combine(gameDir, "UserData", "Characters")))
                File.Copy(charFile, Path.Combine(charsDir, Path.GetFileName(charFile)));
            File.Copy(nghPath, Path.Combine(userData, "Neighborhood.iff"));
            var zoningPath = Path.Combine(gameDir, "UserData", "LotZoning.iff");
            if (File.Exists(zoningPath))
                File.Copy(zoningPath, Path.Combine(userData, "LotZoning.iff"));
            File.Copy(homePath, Path.Combine(userData, "Houses", "House05.iff"));
            File.Copy(destPath, Path.Combine(userData, "Houses", $"House{destinationHouse:D2}.iff"));

            var session = Path.Combine(tempRoot, "session");
            Directory.CreateDirectory(session);
            using var outputStream = new MemoryStream();
            using var writer = new StreamWriter(outputStream, new System.Text.UTF8Encoding(false)) { AutoFlush = true };
            var server = SimulationServer.Load(gameDir, session, profile, 5, writer);
            Assert.NotNull(server.World);

            var homeWorld = server.World!;
            var traveller = homeWorld.WalkOrder.OfType<XPerson>()
                .First(p => p[PersonData.FamilyNumber] > 0 && !PersonAgeCategory.IsChild(p[PersonData.PersonAge]) && (p.TypeRecord?.Key ?? 0) != 0);
            var travellerGuid = traveller.TypeRecord!.Key;
            var familyNumber = traveller[PersonData.FamilyNumber];
            var homeFamilyCount = homeWorld.WalkOrder.OfType<XPerson>().Count(p => p[PersonData.FamilyNumber] == familyNumber);

            homeWorld.PendingLotSwitch = wholeFamily
                ? new SimulationWorld.LotSwitchRequest(destinationHouse, 0, familyNumber)
                : new SimulationWorld.LotSwitchRequest(destinationHouse, travellerGuid, familyNumber);

            server.BatchRun(1);
            var awayWorld = server.World!;
            Assert.NotSame(homeWorld, awayWorld);

            var arrived = awayWorld.WalkOrder.OfType<XPerson>()
                .FirstOrDefault(p => p.TypeRecord?.Key == travellerGuid);
            Assert.True(arrived is not null, $"{label} (House{destinationHouse:D2}): traveller did not arrive on away lot.");

            var awayTicks = server.BatchRun(240);
            Assert.Equal(240, awayTicks);
            Assert.True(awayWorld.ThreadErrors.Count == 0,
                $"{label} (House{destinationHouse:D2}) had {awayWorld.ThreadErrors.Count} thread error(s): {string.Join(" | ", awayWorld.ThreadErrors.Take(3).Select(e => $"obj={e.ObjectId} {e.Message}"))}");

            var arrivedFamilyCount = awayWorld.WalkOrder.OfType<XPerson>().Count(p => p[PersonData.FamilyNumber] == familyNumber);
            if (wholeFamily)
                Assert.True(arrivedFamilyCount >= homeFamilyCount, $"{label}: expected all {homeFamilyCount} family members, got {arrivedFamilyCount}");

            arrived![PersonData.FameScore] = 250;
            arrived[PersonData.CookingHouseBrokenSkill] = 600;
            var arrivedNid = arrived[PersonData.NeighborId];
            if (arrivedNid > 0)
            {
                var inv = awayWorld.NeighborInventory(arrivedNid);
                inv.Add(7, unchecked((int)0x99E81BECu), 75);
                inv.MarkChanged();
            }

            awayWorld.PendingLotSwitch = new SimulationWorld.LotSwitchRequest(-1, 0, familyNumber);
            server.BatchRun(1);
            var returnedWorld = server.World!;
            Assert.NotSame(awayWorld, returnedWorld);

            var returned = returnedWorld.WalkOrder.OfType<XPerson>()
                .FirstOrDefault(p => p.TypeRecord?.Key == travellerGuid);
            Assert.NotNull(returned);
            Assert.Equal((short)250, returned![PersonData.FameScore]);
            Assert.Equal((short)600, returned[PersonData.CookingHouseBrokenSkill]);
            if (returned[PersonData.NeighborId] > 0)
            {
                var returnedInv = returnedWorld.NeighborInventory(returned[PersonData.NeighborId]);
                Assert.True(returnedInv.FindIndex(7, unchecked((int)0x99E81BECu), out _) >= 75,
                    $"{label}: expected MagiCoins inventory delta to persist after returning home.");
            }
            var returnedFamilyCount = returnedWorld.WalkOrder.OfType<XPerson>().Count(p => p[PersonData.FamilyNumber] == familyNumber);
            Assert.Equal(homeFamilyCount, returnedFamilyCount);

            var homeReturnTicks = server.BatchRun(60);
            Assert.Equal(60, homeReturnTicks);
            Assert.True(returnedWorld.ThreadErrors.Count == 0,
                $"{label} return to House05 had {returnedWorld.ThreadErrors.Count} thread error(s): {string.Join(" | ", returnedWorld.ThreadErrors.Take(3).Select(e => $"obj={e.ObjectId} {e.Message}"))}");
        }
        finally
        {
            try { if (Directory.Exists(tempRoot)) Directory.Delete(tempRoot, recursive: true); } catch { }
        }
    }

    [Theory]
    [InlineData("b603maskn_gunther.apr", "BODY=b603masknlgt_gunther;b803maskn_gunther,BODY=b803masknlgt_gunther", "c803ma_gunter.apr", "HEAD-HEAD=c803malgt_gunter2")]
    [InlineData("b601mafit_elden.apr", "BODY=b601mafitlgt_elden;b801mafit_elden,BODY=b801mafitlgt_elden", "c801ma_elden.apr", "HEAD-HEAD=c801malgt_elden2")]
    public void AvatarSceneGeometry_SemicolonAlternateBodyString_RendersPortraitWithoutError(
        string bodyMesh, string bodyTexWithAlternate, string headMesh, string headTex)
    {
        var gameDir = Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "../../../../../runtime/game"));
        var ep5 = Path.Combine(gameDir, "ExpansionPack5", "ExpansionPack5.far");
        if (!File.Exists(ep5))
            return;

        var registry = SimsEngine.Content.ObjectRegistry.Scan(gameDir);
        var parts = new (string, string)[]
        {
            (bodyMesh, bodyTexWithAlternate),
            (string.Empty, string.Empty),
            ("hmlo.apr", "huaolgt"),
            ("hmro.apr", "huaolgt"),
            (headMesh, headTex),
        };
        var person = new XPerson(1, new short[XObject.DefinitionCount])
        {
            SavedCharacter = new PersonCharacter(0, 0, parts, [], [string.Empty, string.Empty, string.Empty], 3, new float[9]),
            Position = new ObjectPosition(64 * 16, 64 * 16, 1),
        };
        person[PersonData.PersonAge] = 27;
        person[ObjectData.Direction] = 3;

        var headMeshes = AvatarSceneGeometry.For(gameDir, registry)
            .BuildHeadMeshes(person, 1, 0, (_, _) => 0, new LotCamera(0, 128, 128));
        Assert.NotEmpty(headMeshes);
    }

    [Fact]
    public void Level2BedSleeping_SimRemainsOccludedUnderBlanketDepthBuffer()
    {
        var gameDir = Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "../../../../../runtime/game"));
        var homePath = Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        var nghPath = Path.Combine(gameDir, "UserData", "Neighborhood.iff");
        if (!File.Exists(homePath) || !File.Exists(nghPath))
            return;

        var tempRoot = Path.Combine(Path.GetTempPath(), $"sims-bed-l2-{Guid.NewGuid():N}");
        try
        {
            var profile = Path.Combine(tempRoot, "profile");
            var userData = Path.Combine(profile, "UserData");
            Directory.CreateDirectory(Path.Combine(userData, "Houses"));
            var charsDir = Path.Combine(userData, "Characters");
            Directory.CreateDirectory(charsDir);
            foreach (var charFile in Directory.EnumerateFiles(Path.Combine(gameDir, "UserData", "Characters")))
                File.Copy(charFile, Path.Combine(charsDir, Path.GetFileName(charFile)));
            File.Copy(nghPath, Path.Combine(userData, "Neighborhood.iff"));
            var zoning = Path.Combine(gameDir, "UserData", "LotZoning.iff");
            if (File.Exists(zoning)) File.Copy(zoning, Path.Combine(userData, "LotZoning.iff"));
            File.Copy(homePath, Path.Combine(userData, "Houses", "House05.iff"));

            var session = Path.Combine(tempRoot, "session");
            Directory.CreateDirectory(session);
            using var stream = new MemoryStream();
            using var writer = new StreamWriter(stream, new System.Text.UTF8Encoding(false)) { AutoFlush = true };
            var server = SimulationServer.Load(gameDir, session, profile, 5, writer);
            var seq = 0;
            System.Text.Json.JsonElement Call(string opWithArgs)
            {
                seq++;
                var id = seq.ToString();
                var start = stream.Length;
                server.Handle($"{{\"id\":\"{id}\",{opWithArgs}}}");
                var text = System.Text.Encoding.UTF8.GetString(stream.GetBuffer(), (int)start, (int)(stream.Length - start));
                foreach (var line in text.Split('\n', StringSplitOptions.RemoveEmptyEntries))
                {
                    using var doc = System.Text.Json.JsonDocument.Parse(line);
                    if (doc.RootElement.TryGetProperty("type", out var t) && t.GetString() == "response" &&
                        doc.RootElement.TryGetProperty("id", out var rid) && rid.GetString() == id)
                        return doc.RootElement.GetProperty("result").Clone();
                }
                throw new InvalidOperationException($"No response for {opWithArgs}");
            }

            server.BatchRun(5);
            var world = server.World!;
            var state = Call("\"op\":\"state\"");
            var bellaId = (short)state.GetProperty("sims").EnumerateArray().First(s => s.GetProperty("name").GetString() == "Bella").GetProperty("id").GetInt32();
            var bella = (XPerson)world.ObjectById(bellaId)!;
            bella[Motive.Energy] = -80;
            Call($"\"op\":\"selectSim\",\"objectID\":{bellaId}");

            var middleBed = state.GetProperty("objects").EnumerateArray()
                .First(o => (o.GetProperty("name").GetString() ?? "").Contains("Bed - Single - Cheap - middle", StringComparison.OrdinalIgnoreCase));
            var middleBedId = middleBed.GetProperty("id").GetInt32();
            var sleepOpt = Call($"\"op\":\"menu\",\"objectID\":{middleBedId}").EnumerateArray()
                .First(o => (o.GetProperty("name").GetString() ?? "").Contains("Sleep", StringComparison.OrdinalIgnoreCase));
            Call($"\"op\":\"interact\",\"objectID\":{middleBedId},\"interaction\":{sleepOpt.GetProperty("interaction").GetInt32()},\"param0\":{sleepOpt.GetProperty("param0").GetInt32()},\"global\":{(sleepOpt.GetProperty("global").GetBoolean() ? "true" : "false")}");

            for (var i = 0; i < 80; i++)
            {
                server.BatchRun(15);
                if (bella[Motive.SleepState] < 0 && i >= 55) break;
            }
            Assert.True(bella[Motive.SleepState] < 0, "Expected Bella to be asleep in the Level-2 single bed.");

            var lot = IffFile.Open(Path.Combine(userData, "Houses", "House05.iff"));
            var sceneDir = Path.Combine(tempRoot, "scene");
            Directory.CreateDirectory(sceneDir);
            var scenePath = SceneExporter.Export(lot, world, world.ObjectRegistry!, gameDir, sceneDir, house: 5, revision: 1, viewLevel: 2, wallMode: "cutaway", cameraOrientation: 0);
            using var doc = System.Text.Json.JsonDocument.Parse(File.ReadAllText(scenePath));
            var root = doc.RootElement;
            var textures = root.GetProperty("textures").EnumerateArray().ToList();
            var simVerts = new List<(float X, float Y, float Z)>();
            foreach (var mesh in root.GetProperty("meshes").EnumerateArray())
            {
                if (mesh.GetProperty("objectID").GetInt32() != bellaId) continue;
                if (mesh.TryGetProperty("indicator", out var ind) && ind.ValueKind == System.Text.Json.JsonValueKind.True) continue;
                foreach (var v in mesh.GetProperty("vertices").EnumerateArray())
                    simVerts.Add((v.GetProperty("x").GetSingle(), v.GetProperty("y").GetSingle(), v.GetProperty("z").GetSingle()));
            }
            Assert.NotEmpty(simVerts);

            var middleSprite = root.GetProperty("sprites").EnumerateArray().First(sp => sp.GetProperty("objectID").GetInt32() == middleBedId);
            var sx = middleSprite.GetProperty("x").GetSingle();
            var sy = middleSprite.GetProperty("y").GetSingle();
            var dnear = middleSprite.GetProperty("depthNear").GetSingle();
            var dfar = middleSprite.GetProperty("depthFar").GetSingle();
            var dtex = textures[middleSprite.GetProperty("depthTexture").GetInt32()];
            var tw = dtex.GetProperty("width").GetInt32();
            var th = dtex.GetProperty("height").GetInt32();
            var raw = File.ReadAllBytes(Path.Combine(sceneDir, dtex.GetProperty("file").GetString()!));
            var flip = middleSprite.TryGetProperty("flip", out var fl) && fl.GetBoolean();
            var simFront = 0;
            var bedFront = 0;
            foreach (var v in simVerts)
            {
                var px = (int)(v.X - sx);
                var py = (int)(v.Y - sy);
                if (px < 0 || px >= tw || py < 0 || py >= th) continue;
                var d8 = raw[py * tw + (flip ? (tw - 1 - px) : px)];
                if (d8 >= 255) continue;
                var bedZ = dnear + (dfar - dnear) * (d8 / 254f);
                if (v.Z < bedZ) simFront++; else bedFront++;
            }
            Assert.True(bedFront > 100, $"Expected blanket to overlap sleeping Sim (bedFront={bedFront}).");
            Assert.Equal(0, simFront);
        }
        finally
        {
            try { if (Directory.Exists(tempRoot)) Directory.Delete(tempRoot, recursive: true); } catch { }
        }
    }

    [Fact]
    public void PoolSwimming_AdultUsesAdultSwimAnimations_SwimsMultipleLapsAndExitsLadder()
    {
        var gameDir = Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "../../../../../runtime/game"));
        var homePath = Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        var nghPath = Path.Combine(gameDir, "UserData", "Neighborhood.iff");
        if (!File.Exists(homePath) || !File.Exists(nghPath))
            return;

        var tempRoot = Path.Combine(Path.GetTempPath(), $"sims-pool-swim-{Guid.NewGuid():N}");
        try
        {
            var profile = Path.Combine(tempRoot, "profile");
            var userData = Path.Combine(profile, "UserData");
            Directory.CreateDirectory(Path.Combine(userData, "Houses"));
            var charsDir = Path.Combine(userData, "Characters");
            Directory.CreateDirectory(charsDir);
            foreach (var charFile in Directory.EnumerateFiles(Path.Combine(gameDir, "UserData", "Characters")))
                File.Copy(charFile, Path.Combine(charsDir, Path.GetFileName(charFile)));
            File.Copy(nghPath, Path.Combine(userData, "Neighborhood.iff"));
            var zoning = Path.Combine(gameDir, "UserData", "LotZoning.iff");
            if (File.Exists(zoning)) File.Copy(zoning, Path.Combine(userData, "LotZoning.iff"));
            File.Copy(homePath, Path.Combine(userData, "Houses", "House05.iff"));

            var session = Path.Combine(tempRoot, "session");
            Directory.CreateDirectory(session);
            using var stream = new MemoryStream();
            using var writer = new StreamWriter(stream, new System.Text.UTF8Encoding(false)) { AutoFlush = true };
            var server = SimulationServer.Load(gameDir, session, profile, 5, writer);
            var seq = 0;
            System.Text.Json.JsonElement Call(string opWithArgs)
            {
                seq++;
                var id = seq.ToString();
                var start = stream.Length;
                server.Handle($"{{\"id\":\"{id}\",{opWithArgs}}}");
                var text = System.Text.Encoding.UTF8.GetString(stream.GetBuffer(), (int)start, (int)(stream.Length - start));
                foreach (var line in text.Split('\n', StringSplitOptions.RemoveEmptyEntries))
                {
                    using var doc = System.Text.Json.JsonDocument.Parse(line);
                    if (doc.RootElement.TryGetProperty("type", out var t) && t.GetString() == "response" &&
                        doc.RootElement.TryGetProperty("id", out var rid) && rid.GetString() == id)
                        return doc.RootElement.GetProperty("result").Clone();
                }
                throw new InvalidOperationException($"No response for {opWithArgs}");
            }

            server.BatchRun(5);
            for (var d = 0; d < 10; d++)
            {
                var dlgs = Call("\"op\":\"state\"").GetProperty("dialogs").EnumerateArray().ToList();
                if (dlgs.Count == 0) break;
                foreach (var dlg in dlgs)
                    Call($"\"op\":\"dialogResponse\",\"token\":\"{dlg.GetProperty("token").GetString()}\",\"code\":{(dlg.GetProperty("kind").GetInt32() == 1 ? 1 : 0)}");
                server.BatchRun(1);
            }
            Call("\"op\":\"cheat\",\"command\":\"rosebud\"");
            Call("\"op\":\"cheat\",\"command\":\"rosebud\"");
            Call("\"op\":\"cheat\",\"command\":\"rosebud\"");
            Call("\"op\":\"view\",\"editing\":true");
            var poolRes = Call("\"op\":\"architecture\",\"command\":\"POOL_RECT\",\"x\":22,\"y\":35,\"level\":1,\"x2\":4,\"y2\":4,\"pattern\":65535,\"style\":0");
            Assert.True(poolRes.GetProperty("applied").GetBoolean());

            var registry = server.World!.ObjectRegistry!;
            var divingGuid = registry.Entries.First(e => e.Source.Contains("PoolDivBrd", StringComparison.OrdinalIgnoreCase) && e.Definition[ObjdField.Price] > 0).Guid;
            var ladderGuid = registry.Entries.First(e => e.Source.Contains("PoolLadder", StringComparison.OrdinalIgnoreCase) && e.Definition[ObjdField.Price] > 0).Guid;

            List<int> Place(uint guid, int skipDir = -1)
            {
                var before = Call("\"op\":\"state\"").GetProperty("objects").EnumerateArray().Select(o => o.GetProperty("id").GetInt32()).ToHashSet();
                foreach (var dir in new[] { 1, 4, 16, 64 })
                {
                    if (dir == skipDir) continue;
                    for (var ty = 33; ty <= 41; ty++)
                    for (var tx = 20; tx <= 28; tx++)
                    {
                        var prev = Call($"\"op\":\"previewObject\",\"guid\":{guid},\"x\":{tx * 16 + 8},\"y\":{ty * 16 + 8},\"level\":1,\"direction\":{dir}");
                        if (prev.GetProperty("valid").GetBoolean())
                        {
                            Call($"\"op\":\"buyObject\",\"guid\":{guid},\"x\":{tx * 16 + 8},\"y\":{ty * 16 + 8},\"level\":1,\"direction\":{dir}");
                            return Call("\"op\":\"state\"").GetProperty("objects").EnumerateArray()
                                .Where(o => !before.Contains(o.GetProperty("id").GetInt32()))
                                .Select(o => o.GetProperty("id").GetInt32()).ToList();
                        }
                    }
                }
                return [];
            }

            var boardIds = Place(divingGuid);
            var ladderIds = Place(ladderGuid, skipDir: 1);
            Assert.NotEmpty(boardIds);
            Assert.NotEmpty(ladderIds);
            Call("\"op\":\"view\",\"editing\":false");

            var world = server.World!;
            var mortimerId = (short)Call("\"op\":\"state\"").GetProperty("sims").EnumerateArray().First(s => s.GetProperty("name").GetString() == "Mortimer").GetProperty("id").GetInt32();
            var mortimer = (XPerson)world.ObjectById(mortimerId)!;
            Call($"\"op\":\"selectSim\",\"objectID\":{mortimerId}");

            var diveEntry = boardIds
                .SelectMany(id => Call($"\"op\":\"menu\",\"objectID\":{id}").EnumerateArray().Select(opt => (Id: id, Opt: opt.Clone())))
                .First(x => (x.Opt.GetProperty("name").GetString() ?? "").Contains("Dive", StringComparison.OrdinalIgnoreCase));
            Call($"\"op\":\"interact\",\"objectID\":{diveEntry.Id},\"interaction\":{diveEntry.Opt.GetProperty("interaction").GetInt32()},\"param0\":{diveEntry.Opt.GetProperty("param0").GetInt32()},\"global\":{(diveEntry.Opt.GetProperty("global").GetBoolean() ? "true" : "false")}");

            var distinctPoolPositions = new HashSet<(int X, int Y)>();
            var sawAdultSwimLoop = false;
            var sawChildSwimClip = false;
            var sawPoolStandingBg = false;
            for (var step = 0; step < 140; step++)
            {
                server.BatchRun(20);
                var clip = mortimer.AnimationPlayback?.Clip.Name ?? "";
                if (clip.StartsWith("c2o-pool-", StringComparison.OrdinalIgnoreCase)) sawChildSwimClip = true;
                if (clip.Equals("a2o-pool-swim-loop", StringComparison.OrdinalIgnoreCase)) sawAdultSwimLoop = true;
                if ((mortimer.BackgroundAnimationPlayback?.Clip.Name ?? "").Equals("a2o-pool-standing-loop", StringComparison.OrdinalIgnoreCase))
                    sawPoolStandingBg = true;
                if (world.IsPoolTile(mortimer.Position))
                    distinctPoolPositions.Add((mortimer.Position.X >> 4, mortimer.Position.Y >> 4));
                if (sawAdultSwimLoop && sawPoolStandingBg && distinctPoolPositions.Count >= 3)
                    break;
            }
            Assert.False(sawChildSwimClip, "Adult Sim should never play child c2o-pool-* swim animations.");
            Assert.True(sawAdultSwimLoop, "Expected adult Sim to play a2o-pool-swim-loop.");
            Assert.True(sawPoolStandingBg, "Expected swimming adult Sim to switch background idle to a2o-pool-standing-loop.");
            Assert.True(distinctPoolPositions.Count >= 3, $"Expected Sim to swim across multiple pool tiles, only visited {distinctPoolPositions.Count}.");

            var exitEntry = ladderIds
                .SelectMany(id => Call($"\"op\":\"menu\",\"objectID\":{id}").EnumerateArray().Select(opt => (Id: id, Opt: opt.Clone())))
                .First(x => (x.Opt.GetProperty("name").GetString() ?? "").Contains("Get Out", StringComparison.OrdinalIgnoreCase));
            Call($"\"op\":\"interact\",\"objectID\":{exitEntry.Id},\"interaction\":{exitEntry.Opt.GetProperty("interaction").GetInt32()},\"param0\":{exitEntry.Opt.GetProperty("param0").GetInt32()},\"global\":{(exitEntry.Opt.GetProperty("global").GetBoolean() ? "true" : "false")}");

            var exitedPool = false;
            for (var step = 0; step < 40; step++)
            {
                server.BatchRun(20);
                if (!world.IsPoolTile(mortimer.Position) && !mortimer.AnimatorPoolTile)
                {
                    exitedPool = true;
                    break;
                }
            }
            Assert.True(exitedPool, $"Expected Mortimer to exit pool via ladder (pos={mortimer.Position}, animPool={mortimer.AnimatorPoolTile}).");
            Assert.Equal("a2o-standing-loop", mortimer.BackgroundAnimationPlayback?.Clip.Name);
        }
        finally
        {
            try { if (Directory.Exists(tempRoot)) Directory.Delete(tempRoot, recursive: true); } catch { }
        }
    }

    private static byte[] BuildBhav(params (ushort Opcode, byte[] Operand)[] instructions)
    {
        var b = new ChunkBuilder();
        b.U16(0x8002);
        b.S16((short)instructions.Length);
        b.U8(0).U8(0).U8(0).U8(0);
        b.U32(0);
        foreach (var (opcode, operand) in instructions)
        {
            b.U16(opcode);
            b.U8(BhavInstruction.ReturnTrue);
            b.U8(BhavInstruction.ReturnFalse);
            b.Raw(operand);
        }
        return b.ToArray();
    }
}
