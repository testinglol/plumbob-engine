using System.Reflection;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsNative.Plugins;
using SimsSDL.Core;
using SimsSimulation;
using Xunit;

namespace SimsEngine.Tests.Client;

public sealed class SmartFreeWillPluginTests
{
    [Fact]
    public void PluginApiVersion6_IsSupportedAndPackIsOptInByDefault()
    {
        Assert.Equal(6, PluginApi.Version);
        Assert.Contains(6, PluginApi.SupportedVersions);
        Assert.True(PluginDeclaration.IsSupportedAPIVersion(6));

        var repoRoot = FindRepoRoot();
        var packDir = Path.Combine(repoRoot, "packs", "smart-free-will");
        var pack = new ContentPack(packDir);
        Assert.Equal("local.smart-free-will", pack.Manifest.Id);
        Assert.False(pack.Manifest.DefaultEnabled);
        Assert.NotNull(pack.Manifest.Plugin);
        Assert.Equal(6, pack.Manifest.Plugin!.ApiVersion);
        Assert.NotNull(pack.Manifest.Panels);
        Assert.Single(pack.Manifest.Panels!);
        var panelJson = File.ReadAllText(Path.Combine(packDir, "panels", "smart-free-will.json"));
        Assert.DoesNotContain("\"list\"", panelJson);

        string tempRoot = Path.Combine(Path.GetTempPath(), "sims-smart-fw-" + Guid.NewGuid().ToString("N"));
        string gameRoot = Path.Combine(tempRoot, "game");
        string dataRoot = Path.Combine(tempRoot, "data");
        string bundledRoot = Path.Combine(tempRoot, "bundled");
        Directory.CreateDirectory(gameRoot);
        Directory.CreateDirectory(dataRoot);
        CopyDirectory(packDir, Path.Combine(bundledRoot, "smart-free-will"));

        string? prevOverride = SimsSDL.ModManager.BundledPacksDirectoryOverride;
        try
        {
            SimsSDL.ModManager.BundledPacksDirectoryOverride = bundledRoot;
            var discovered = SimsSDL.ModManager.DiscoverAll(gameRoot, workspace: "", dataRoot, cliPacks: null);
            var mod = Assert.Single(discovered, m => m.LoadedPack?.Manifest.Id == "local.smart-free-will");
            Assert.False(mod.DefaultEnabled);

            var (_, initialEnabled) = SimsSDL.ModManager.BuildInitialState(discovered, new SimsSDL.ModManager.ModSettingsFile());
            Assert.DoesNotContain(mod.Key, initialEnabled);

            var optedIn = new SimsSDL.ModManager.ModSettingsFile { EnabledPacks = ["local.smart-free-will"] };
            var (_, enabledAfterOptIn) = SimsSDL.ModManager.BuildInitialState(discovered, optedIn);
            Assert.Contains(mod.Key, enabledAfterOptIn);
        }
        finally
        {
            SimsSDL.ModManager.BundledPacksDirectoryOverride = prevOverride;
            if (Directory.Exists(tempRoot))
                Directory.Delete(tempRoot, recursive: true);
        }
    }

    [Fact]
    public void FindBestInteraction_BypassesDistanceBlindfoldOnlyWhenDirectorActive_AndKeepsVanillaIntactWhenInactive()
    {
        var (context, me, host) = PrimitiveTestWorld.Create();
        me[PersonData.AutonomyLevel] = 100;
        me.Position = new ObjectPosition(16, 16, 1);

        var farBedDef = PrimitiveTestWorld.Definition(0);
        farBedDef[7] = 1;
        var farBed = new XObject(20, farBedDef)
        {
            Position = new ObjectPosition(30 * 16, 30 * 16, 1),
        };
        var motives = new SimsEngine.Formats.MotiveAdvertisement[16];
        motives[5] = new SimsEngine.Formats.MotiveAdvertisement(400, 0, 0);
        farBed.TypeRecord = new TypeRecord(0xBEEF)
        {
            ObjectType = 4,
            Name = "Bed - Expensive",
            BehaviorScope = new TreeTable(_ => null),
            Interactions = BuildSingleInteractionTable(actionKey: 3, motives),
        };

        host.ObjectTable[1] = farBed;
        context.World.Add(farBed);
        context.World.ClockManager.SetFlag(farBed.ClockManagerIndex, 3, enabled: true);

        host.Lot = new AutonomyLot(Forced: true, Paused: false, FlagB: false, LotKey: 1, LotId: 1,
            Rotation: (1 - me.Id) & 3, ActivePerson: null);

        var vanillaResult = FindBestInteractionPrimitive.Execute(context, []);
        Assert.Equal(PrimitiveResult.False, vanillaResult);

        var directingHost = new DirectingAutonomyHostWrapper(host, directs: true, select: (_, cands) =>
        {
            Assert.Single(cands);
            Assert.Equal((short)20, cands[0].Target.Id);
            return 0;
        });
        context.World.AutonomyHost = directingHost;

        var smartResult = FindBestInteractionPrimitive.Execute(context, []);
        Assert.Equal(PrimitiveResult.True, smartResult);
        Assert.Equal((short)20, context.Frame.StackObject);
        Assert.Equal((short)3, me.InteractionActionWord72);
    }

    [Fact]
    public void SitcomDramaMode_HoldItBladderHubris_OneWayCrush_TurfWars_LowSkillZap_WitnessRipple_AndBalloons()
    {
        var (plugin, director, simHost) = CreateLoadedPlugin();

        var gamer = MakeSim(
            objectId: 10, name: "Mortimer",
            bladder: -66, fun: -35, energy: 30, hunger: 30,
            playful: 850, outgoing: 200, active: 400, nice: 300, mechanical: 50);
        var crushTarget = MakeSim(
            objectId: 11, name: "Bella",
            bladder: 50, fun: 20, energy: 50, hunger: 50,
            playful: 300, outgoing: 750, active: 820, nice: 700);
        simHost.Sims.AddRange([gamer, crushTarget]);

        var toilet = new PluginObject(101, 0x1001, "Toilet - Cheap", 8, 8, 1, 101)
        {
            FunctionFlags = 0x10, RoomSort = 0x04, RatingBladder = 5, RoomId = 2,
        };
        var computer = new PluginObject(102, 0x1002, "Computer - Expensive", 5, 6, 1, 102)
        {
            FunctionFlags = 0x08, RatingFun = 8, RoomId = 1,
        };
        var tv = new PluginObject(103, 0x1003, "TV - Color", 6, 6, 1, 103)
        {
            FunctionFlags = 0x08, RatingFun = 5, RoomId = 1,
        };
        var workoutBench = new PluginObject(104, 0x1004, "Exercise - Machine", 7, 6, 1, 104)
        {
            SkillFlags = 1 << 3, RatingFun = 2, RoomId = 1,
        };
        simHost.ObjectList.AddRange([toilet, computer, tv, workoutBench]);

        // 1) "Just One More Turn!" Hubris: Playful+Shy gamer at -66 Bladder picks Computer over Toilet
        //    and telegraphs [Thought: Toilet + CrossedOut] -> [Thought: Computer].
        plugin.OnTick(100);
        var gamerPick = director.SelectAutonomyCandidate(
            new PluginAutonomyContext(10, true, 1, false, 19, 0, 0f, 0.2f, 7u),
            [
                Candidate(toilet, 0, "Use", 4f, Motive(9, 85)),
                Candidate(computer, 0, "Play Games", 2f, Motive(15, 45)),
            ]);
        Assert.Equal(1, gamerPick);
        Assert.Contains(simHost.Balloons, b =>
            b.SimId == 10 && b.Style == PluginBalloonStyle.Thought && b.TargetObjectId == toilet.ObjectId && b.CrossedOut);
        plugin.OnTick(165);
        Assert.Contains(simHost.Balloons, b =>
            b.SimId == 10 && b.Style == PluginBalloonStyle.Thought && b.TargetObjectId == computer.ObjectId && !b.CrossedOut);

        // 2) While engrossed in Computer Games at -74 Bladder, Drama mode does NOT cancel the game early;
        //    only at -91 Bladder does panic break through with [Scream: Toilet]!
        simHost.CancelledSims.Clear();
        simHost.Sims[0] = gamer with
        {
            Motives = WithMotive(gamer.Motives, 9, -74),
            CurrentAction = new PluginQueuedAction(1, computer.ObjectId, computer.Guid, 0, 0, "Play Games", "Play Games", 2, Autonomous: true),
        };
        simHost.Minutes = 20;
        plugin.OnTick(240);
        Assert.Empty(simHost.CancelledSims);

        simHost.Sims[0] = simHost.Sims[0] with { Motives = WithMotive(gamer.Motives, 9, -91) };
        simHost.Minutes = 35;
        plugin.OnTick(360);
        Assert.Contains((short)10, simHost.CancelledSims);
        Assert.Contains(simHost.Balloons, b =>
            b.SimId == 10 && b.Style == PluginBalloonStyle.Scream && b.TargetObjectId == toilet.ObjectId);

        // 3) Energetic Sim (Active 820) refuses to turn on/watch TV and flashes [TV + CrossedOut] -> [Workout Bench].
        simHost.Balloons.Clear();
        plugin.OnTick(500);
        var activePick = director.SelectAutonomyCandidate(
            new PluginAutonomyContext(11, true, 1, false, 19, 40, 0f, 0.2f, 3u),
            [
                Candidate(tv, 0, "Watch TV", 2f, Motive(15, 35)),
                Candidate(workoutBench, 0, "Work Out", 3f, Motive(15, 10)),
            ]);
        Assert.Equal(1, activePick);
        Assert.Contains(simHost.Balloons, b =>
            b.SimId == 11 && b.TargetObjectId == tv.ObjectId && b.CrossedOut);

        // 4) Asymmetric One-Way Crush: Daily = 36, ReverseDaily = -5 still shoots a bold romantic shot
        //    with [Crush 633] -> [Target Sim Face].
        simHost.Balloons.Clear();
        simHost.Sims[0] = gamer with { Motives = WithMotive(gamer.Motives, 9, 50), CurrentAction = null };
        simHost.RelationshipsBySim[10] =
        [
            new PluginSimRelationship(11, 11, "Bella", true, Daily: 36, ReverseDaily: -5, Lifetime: 10, MutualFriend: false, Crush: false, Love: false),
        ];
        var bellaAsObj = new PluginObject(11, crushTarget.Guid, "Bella", 6, 5, 1, 11);
        plugin.OnTick(700);
        var crushPick = director.SelectAutonomyCandidate(
            new PluginAutonomyContext(10, true, 1, false, 20, 0, 0f, 0.2f, 1u),
            [
                Candidate(bellaAsObj, 0, "Flirt", 2f, Motive(14, 25)),
                Candidate(tv, 0, "Watch TV", 3f, Motive(15, 20)),
            ]);
        Assert.Equal(0, crushPick);
        Assert.Contains(simHost.Balloons, b => b.SimId == 10 && b.SpriteId == 633);
        plugin.OnTick(760);
        Assert.Contains(simHost.Balloons, b => b.SimId == 10 && b.TargetObjectId == 11 && !b.CrossedOut);

        // 5) Petty Channel Turf War: Bella is watching TV, Grouchy Mortimer hijacks channel with [Bella + CrossedOut] -> [TV].
        simHost.Balloons.Clear();
        simHost.Sims[1] = crushTarget with
        {
            CurrentAction = new PluginQueuedAction(2, tv.ObjectId, tv.Guid, 0, 0, "Watch TV", "Watch TV", 2, Autonomous: true),
        };
        simHost.RelationshipsBySim[10] =
        [
            new PluginSimRelationship(11, 11, "Bella", true, Daily: 5, ReverseDaily: 5, Lifetime: 0, MutualFriend: false, Crush: false, Love: false),
        ];
        plugin.OnTick(900);
        var channelPick = director.SelectAutonomyCandidate(
            new PluginAutonomyContext(10, true, 1, false, 20, 15, 0f, 0.2f, 1u),
            [
                Candidate(tv, 2, "Switch to Horror", 2f, Motive(15, 15)),
                Candidate(workoutBench, 0, "Work Out", 3f, []),
            ]);
        Assert.Equal(0, channelPick);
        Assert.Contains(simHost.Balloons, b => b.SimId == 10 && b.TargetObjectId == 11 && b.CrossedOut);

        // 6) Low-Skill Electrical Hubris: 50-Mechanical Grouchy Sim confidently attempts to repair a broken TV!
        var brokenTv = tv with { RepairState = 1 };
        simHost.ObjectList[2] = brokenTv;
        plugin.OnTick(1100);
        var hubrisRepairPick = director.SelectAutonomyCandidate(
            new PluginAutonomyContext(10, true, 1, false, 20, 30, 0f, 0.2f, 1u),
            [
                Candidate(brokenTv, 6, "Repair", 2f, []),
                Candidate(workoutBench, 0, "Work Out", 4f, []),
            ]);
        Assert.Equal(0, hubrisRepairPick);

        // 7) Witness Reaction Ripple: Bella wets the floor (-96 -> +90 + Puddle spawned) -> idle Mortimer witnesses,
        //    pops [Scream: Surprise 502] -> [Speech: Bella], and queues Tease!
        simHost.Balloons.Clear();
        simHost.QueuedAutonomous.Clear();
        simHost.Sims[1] = crushTarget with { Motives = WithMotive(crushTarget.Motives, 9, -96), CurrentAction = null };
        simHost.Sims[0] = gamer with { Motives = WithMotive(gamer.Motives, 9, 60), CurrentAction = null };
        simHost.Minutes = 40;
        plugin.OnTick(1200);

        var puddle = new PluginObject(301, 0x3001, "Flood - Puddle", 6, 5, 1, 301);
        simHost.ObjectList.Add(puddle);
        simHost.Sims[1] = crushTarget with { Motives = WithMotive(crushTarget.Motives, 9, 90), CurrentAction = null };
        simHost.Menus[(10, 11)] =
        [
            new PluginInteraction(4, "Tease", 0, false) { EnglishName = "Tease", MotiveDeltas = Motive(14, 15) },
        ];
        simHost.Minutes = 43;
        plugin.OnTick(1224);

        Assert.Contains(simHost.QueuedAutonomous, q => q.SimId == 10 && q.ObjId == 11 && q.ActionId == 4);
        Assert.Contains(simHost.Balloons, b => b.SimId == 10 && b.Style == PluginBalloonStyle.Scream && b.SpriteId == 502);
        plugin.OnTick(1284);
        Assert.Contains(simHost.Balloons, b => b.SimId == 10 && b.Style == PluginBalloonStyle.Speech && b.TargetObjectId == 11);
    }

    [Fact]
    public void MastermindMode_PrioritizesEmergencySurvival_ElectricalSafety_CareerPromotion_AndPlayerVetoes()
    {
        var (plugin, director, simHost) = CreateLoadedPlugin();
        var modeMsg = plugin.OnCheat("smart_freewill", ["mastermind"]);
        Assert.Contains("Mastermind", modeMsg);

        var careerNeedLogic = new PluginSimCareer(
            JobType: 8, JobLevel: 3, JobPerformance: 40, IsSchool: false,
            StartHour: 9, EndHour: 15, Salary: 450, FriendsRequired: 0, FamilyFriends: 2,
            SkillRequirements: [0, 0, 0, 0, 500, 0]);

        var bella = MakeSim(objectId: 1, name: "Bella", hunger: 40, energy: 50, bladder: 50, hygiene: 50,
            cooking: 600, mechanical: 100, logic: 100, career: careerNeedLogic);
        var mortimer = MakeSim(objectId: 2, name: "Mortimer", hunger: 20, energy: -68, bladder: -62, hygiene: 50,
            cooking: 100, mechanical: 100, logic: 400);
        simHost.Sims.AddRange([bella, mortimer]);

        var toilet1 = new PluginObject(50, 0x50, "Toilet - Master", 5, 5, 1, 50)
        {
            FunctionFlags = 0x10, RoomSort = 0x04, RatingBladder = 7, RoomId = 10, UseCount = 1,
        };
        var toilet2 = new PluginObject(51, 0x51, "Toilet - Hall", 10, 10, 1, 51)
        {
            FunctionFlags = 0x10, RoomSort = 0x04, RatingBladder = 6, RoomId = 11, UseCount = 0,
        };
        var espresso = new PluginObject(52, 0x52, "Espresso Machine", 4, 4, 1, 52) { FunctionFlags = 0x04, RoomId = 1 };
        var bed = new PluginObject(53, 0x53, "Bed - Double - Expensive", 12, 12, 2, 53)
        {
            FunctionFlags = 0x01, FunctionSubsort = 0x04, RatingEnergy = 9, RatingComfort = 8, Price = 1800, RoomId = 3,
        };
        var brokenTv = new PluginObject(60, 0x60, "TV - Expensive", 6, 6, 1, 60)
        {
            FunctionFlags = 0x08, RepairState = 1, RoomId = 1,
        };
        var cloggedToilet = new PluginObject(61, 0x61, "Toilet - Guest", 8, 8, 1, 61)
        {
            FunctionFlags = 0x10, RoomSort = 0x04, RepairState = 1, RoomId = 12,
        };
        var chessboard = new PluginObject(70, 0x70, "Chess - Table", 7, 7, 1, 70)
        {
            SkillFlags = 1 << 2, RatingFun = 4, RoomId = 1,
        };
        var mirror = new PluginObject(71, 0x71, "Mirror - Wall", 6, 7, 1, 71)
        {
            SkillFlags = 1 << 5, RoomId = 1,
        };
        simHost.ObjectList.AddRange([toilet1, toilet2, espresso, bed, brokenTv, cloggedToilet, chessboard, mirror]);

        var lateCtx = new PluginAutonomyContext(2, true, 1, false, 23, 30, 0f, 0.2f, 1u);
        var toiletPick = director.SelectAutonomyCandidate(lateCtx, [
            Candidate(toilet1, 0, "Use", 2f, Motive(9, 80)),
            Candidate(toilet2, 0, "Use", 8f, Motive(9, 80)),
        ]);
        Assert.Equal(1, toiletPick);

        simHost.Sims[1] = mortimer with { Motives = WithMotive(mortimer.Motives, 9, 60) };
        var bedPick = director.SelectAutonomyCandidate(lateCtx, [
            Candidate(espresso, 0, "Drink Espresso", 2f, Motive(5, 25)),
            Candidate(bed, 0, "Sleep", 16f, Motive(5, 90)),
        ]);
        Assert.Equal(1, bedPick);

        var bellaCtx = new PluginAutonomyContext(1, true, 1, false, 18, 0, 0f, 0.2f, 1u);
        var safetyPick = director.SelectAutonomyCandidate(bellaCtx, [
            Candidate(brokenTv, 0, "Repair", 2f, []),
            Candidate(cloggedToilet, 0, "Unclog", 5f, []),
        ]);
        Assert.Equal(1, safetyPick);

        var skillPick = director.SelectAutonomyCandidate(bellaCtx, [
            Candidate(mirror, 0, "Practice Speech", 2f, []),
            Candidate(chessboard, 0, "Play Chess", 4f, Motive(15, 15)),
        ]);
        Assert.Equal(1, skillPick);

        director.OnPlayerCancelledAction(simId: 1, targetObjectId: chessboard.ObjectId, interactionId: 0);
        var afterVetoPick = director.SelectAutonomyCandidate(bellaCtx, [
            Candidate(mirror, 0, "Practice Speech", 2f, []),
            Candidate(chessboard, 0, "Play Chess", 4f, Motive(15, 15)),
        ]);
        Assert.Equal(0, afterVetoPick);

        var schoolBus = new PluginObject(200, 0x2000, "Bus - SchoolBus", 2, 2, 1, 200);
        var studyBookcase = new PluginObject(201, 0x2001, "Bookcase - Wood", 5, 5, 1, 201) { SkillFlags = 1 << 6 };
        simHost.ObjectList.AddRange([schoolBus, studyBookcase]);
        simHost.Sims.Add(MakeSim(objectId: 11, name: "Cassandra", child: true));
        var childPick = director.SelectAutonomyCandidate(
            new PluginAutonomyContext(11, true, 1, false, 8, 5, 0f, 0.2f, 42u),
            [
                Candidate(schoolBus, 0, "Go to School", 3f, [], blocked: true),
                Candidate(studyBookcase, 1, "Study for School", 4f, Motive(15, -5)),
            ]);
        Assert.Equal(1, childPick);

        var classicMsg = plugin.OnCheat("smart_freewill", ["classic"]);
        Assert.Contains("Classic", classicMsg);
        Assert.False(director.DirectsAutonomy(1, household: true));
    }

    [Fact]
    public void PluginWorld_TryShowSimBalloon_WritesNativeRuntimeSlot_AndRespectsSkillMetersAndPriorityTwo()
    {
        var repoRoot = FindRepoRoot();
        var spritesPath = Path.Combine(repoRoot, "runtime", "game", "GameData", "Sprites.iff");
        if (!File.Exists(spritesPath))
            return;

        var (context, person, _) = PrimitiveTestWorld.Create();
        context.World.GlobalSprites = IffFile.Open(spritesPath);
        person.RuntimeSlots.Clear();
        person.RuntimeSlots.Add(new ObjectRuntimeSlot());
        person.TypeRecord = new TypeRecord(0x1111) { ObjectType = 2, Name = "Sim - Mortimer" };

        var targetDef = PrimitiveTestWorld.Definition(0);
        var pinball = new XObject(42, targetDef)
        {
            TypeRecord = new TypeRecord(0x2222) { ObjectType = 4, Name = "Pinball" },
        };
        context.World.Add(pinball);

        var pluginWorldType = typeof(SimulationServer).Assembly.GetType("SimsSimulation.PluginWorld", throwOnError: true)!;
        var pluginSim = (IPluginSimulation)Activator.CreateInstance(
            pluginWorldType,
            BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic,
            binder: null,
            args:
            [
                new Func<SimulationWorld?>(() => context.World),
                new Func<short>(() => 1),
                new Func<ushort?>(() => 1),
                new Func<ObjectRegistry?>(() => null),
                new Func<bool>(() => false),
                null, null, null, null, null, null,
            ],
            culture: null)!;

        // 1) Object selector balloon with crossed-out overlay writes balloon=100, label=103, alwaysVisible=1.
        Assert.True(pluginSim.TryShowSimBalloon(person.Id, PluginBalloonStyle.Thought, targetObjectId: 42, crossedOut: true, durationTicks: 75));
        var slot = person.RuntimeSlots[0];
        Assert.Equal(75, slot.ReadWord(0x10));
        Assert.Equal(-1, slot.ReadWord(0x14));
        Assert.Equal(0x2222, slot.SelectorTypeKey);
        Assert.Equal(100, slot.ReadWord(0x2c));
        Assert.Equal(103, slot.ReadWord(0x30));
        Assert.Equal(1, slot.ReadWord(0x38));

        // 2) Sprite balloon (Crush 633 in Scream 101) loads Sprites.iff frame count and clears SelectorTypeKey.
        Assert.True(pluginSim.TryShowSimBalloon(person.Id, PluginBalloonStyle.Scream, spriteId: 633, crossedOut: false, durationTicks: 60));
        Assert.Null(slot.SelectorTypeKey);
        Assert.Equal(633, slot.ReadWord(0x14));
        Assert.Equal(101, slot.ReadWord(0x2c));
        Assert.Equal(0, slot.ReadWord(0x30));

        // 3) Active skill meter (800..829) or priority-2 BHAV balloon is never overwritten.
        slot.SetRendererSprite(805, 1, false, 0, 0, true);
        slot.ActivateForTicks(50);
        Assert.False(pluginSim.TryShowSimBalloon(person.Id, PluginBalloonStyle.Thought, spriteId: 503));
        Assert.Equal(805, slot.ReadWord(0x14));

        slot.SetRendererSprite(300, 1, false, 102, 0, true);
        slot.WriteWord(0x34, 2);
        slot.ActivateForTicks(50);
        Assert.False(pluginSim.TryShowSimBalloon(person.Id, PluginBalloonStyle.Thought, spriteId: 503));
        Assert.Equal(300, slot.ReadWord(0x14));
    }

    private static (ISimsPlugin Plugin, IPluginAutonomyDirector Director, FakePluginSimulation Sim) CreateLoadedPlugin()
    {
        var repoRoot = FindRepoRoot();
        var dllPath = Path.Combine(repoRoot, "packs", "smart-free-will", "plugin", "LocalSmartFreeWill.dll");
        Assert.True(File.Exists(dllPath), $"Expected built Smart Free Will plugin at {dllPath}");

        var asm = Assembly.LoadFrom(dllPath);
        var type = asm.GetType("Local.SmartFreeWill.SmartFreeWillPlugin", throwOnError: true)!;
        var plugin = (ISimsPlugin)Activator.CreateInstance(type)!;
        var director = Assert.IsAssignableFrom<IPluginAutonomyDirector>(plugin);
        var sim = new FakePluginSimulation();
        var ctx = new FakePluginContext(sim);
        plugin.Initialize(ctx);
        return (plugin, director, sim);
    }

    private static PluginAutonomyCandidate Candidate(
        PluginObject obj,
        int actionId,
        string name,
        float distance,
        float[] deltas,
        bool blocked = false) =>
        new(
            ObjectId: obj.ObjectId,
            ObjectGuid: obj.Guid,
            ObjectName: obj.Name,
            ActionId: actionId,
            InteractionName: name,
            EnglishName: name,
            Distance: distance,
            VanillaScore: 1f,
            AdjustedScore: blocked ? 0f : 1f,
            AutoFirst: false,
            JoinInteraction: false,
            BlockedByPlugin: blocked,
            MotiveDeltas: deltas);

    private static float[] Motive(int index, float delta)
    {
        var arr = new float[16];
        arr[index] = delta;
        return arr;
    }

    private static short[] WithMotive(short[] source, int index, short value)
    {
        var copy = source.ToArray();
        copy[index] = value;
        return copy;
    }

    private static PluginSimProfile MakeSim(
        short objectId,
        string name,
        bool child = false,
        short energy = 40,
        short comfort = 40,
        short hunger = 40,
        short hygiene = 40,
        short bladder = 40,
        short room = 30,
        short social = 40,
        short fun = 40,
        short neat = 500,
        short outgoing = 500,
        short active = 500,
        short playful = 500,
        short nice = 500,
        short cooking = 300,
        short mechanical = 300,
        short logic = 300,
        PluginSimCareer? career = null)
    {
        var motives = new short[16];
        motives[3] = 40;
        motives[5] = energy;
        motives[6] = comfort;
        motives[7] = hunger;
        motives[8] = hygiene;
        motives[9] = bladder;
        motives[13] = room;
        motives[14] = social;
        motives[15] = fun;
        return new PluginSimProfile(
            ObjectId: objectId,
            NeighborId: objectId,
            Guid: (uint)(0x9000 + objectId),
            Name: name,
            Household: true,
            Visitor: false,
            Npc: false,
            Child: child,
            Dog: false,
            Cat: false,
            Greeted: true,
            X: 5,
            Y: 5,
            Level: 1,
            RoomId: 1,
            Outside: false,
            Sheltered: true,
            Sitting: false,
            Asleep: false,
            AtWorkOrSchool: false,
            Priority: 0,
            NonInterruptible: false,
            RouteResult: 0,
            Neat: neat,
            Outgoing: outgoing,
            Active: active,
            Playful: playful,
            Nice: nice,
            Cooking: cooking,
            Mechanical: mechanical,
            Charisma: 200,
            Body: 200,
            Logic: logic,
            Creativity: 200,
            Cleaning: 300,
            Motives: motives,
            Career: career ?? (child
                ? new PluginSimCareer(0, 0, 50, true, 8, 15, 0, 0, 0, new short[6])
                : new PluginSimCareer(0, 0, 0, false, null, null, 0, 0, 0, new short[6])),
            CurrentAction: null,
            ActionQueue: []);
    }

    private static InteractionTable BuildSingleInteractionTable(short actionKey, SimsEngine.Formats.MotiveAdvertisement[] motives)
    {
        var builder = new ChunkBuilder().S16(1).S16(6).U16(0x1000).U16(0).S32(16)
            .U32(0).S32(actionKey).S32(1).F32(0).S32(50).S32(0);
        for (var i = 0; i < 16; i++)
        {
            var m = i < motives.Length ? motives[i] : default;
            builder.S16(m.Minimum).S16(m.Delta).S16(m.Personality);
        }
        var (file, chunk) = builder.InFile("TTAB");
        return InteractionTable.Read(file, chunk);
    }

    private sealed class TreeTable(Func<short, Bhav?> find) : ITreeTable
    {
        public Bhav? Find(short id) => find(id);
    }

    private sealed class DirectingAutonomyHostWrapper(
        ISimulationAutonomyHost inner,
        bool directs,
        Func<AutonomySelectionContext, IReadOnlyList<AutonomyCandidateSnapshot>, int?> select) : ISimulationAutonomyHost
    {
        public AutonomyLot AutonomyLotState() => inner.AutonomyLotState();
        public float ScoreAutonomy(XPerson person, XObject target, short actionIndex, string actionName, float score) =>
            inner.ScoreAutonomy(person, target, actionIndex, actionName, score);
        public bool DirectsAutonomy(XPerson person) => directs;
        public int? SelectAutonomyCandidate(AutonomySelectionContext context, IReadOnlyList<AutonomyCandidateSnapshot> candidates) =>
            select(context, candidates);
    }

    private sealed class FakePluginContext(FakePluginSimulation sim) : IPluginContext
    {
        public int ApiVersion => 6;
        public string PackId => "local.smart-free-will";
        public string PackVersion => "1.0.0";
        public int StateVersion => 1;
        public IPluginSimulation Simulation => sim;
        public IDictionary<string, string> Values { get; } = new Dictionary<string, string>();
        public IDictionary<string, string> NeighborhoodValues { get; } = new Dictionary<string, string>();
        public int NeighborhoodStateVersion => 1;
        public Dictionary<string, string> PanelState { get; } = new();
        public byte[] ReadPluginData(string filename) => """{"style":"drama","thoughtBubbles":true,"sparksAndTurfWars":true}"""u8.ToArray();
        public void SetPanelValue(string panelId, string binding, string value) => PanelState[binding] = value;
        public void ShowPanel(string panelId) { }
        public void ShowPanel(string panelId, short anchorObjectId) { }
        public void Log(string message) { }
    }

    private sealed record RecordedBalloon(
        short SimId,
        PluginBalloonStyle Style,
        short? TargetObjectId,
        int? SpriteId,
        bool CrossedOut,
        int DurationTicks);

    private sealed class FakePluginSimulation : IPluginSimulation
    {
        public short House { get; set; } = 1;
        public int Hours { get; set; } = 12;
        public int Minutes { get; set; } = 0;
        public bool Paused { get; set; }
        public bool FreeWill { get; set; } = true;
        public bool AwayLot { get; set; }
        public int HouseholdFunds { get; set; } = 2000;
        public List<PluginSimProfile> Sims { get; } = [];
        public List<PluginObject> ObjectList { get; } = [];
        public Dictionary<(short SimId, short ObjId), List<PluginInteraction>> Menus { get; } = [];
        public Dictionary<short, List<PluginSimRelationship>> RelationshipsBySim { get; } = [];
        public List<(short SimId, short ObjId, int ActionId)> QueuedAutonomous { get; } = [];
        public List<short> CancelledSims { get; } = [];
        public List<RecordedBalloon> Balloons { get; } = [];

        public IReadOnlyList<PluginSim> HouseholdSims =>
            Sims.Where(s => s.Household).Select(s => new PluginSim(s.ObjectId, s.NeighborId, s.Name, s.Child)).ToArray();

        public IReadOnlyList<PluginSimProfile> AllSims => Sims;

        public IReadOnlyList<PluginObject> Objects =>
            Sims.Select(s => new PluginObject(s.ObjectId, s.Guid, s.Name, s.X, s.Y, s.Level, s.ObjectId))
                .Concat(ObjectList)
                .ToArray();

        public short GetMotive(short objectId, int motive) =>
            Sims.First(s => s.ObjectId == objectId).Motives[motive];

        public bool TryCharge(int amount) => false;
        public bool TryPay(int amount) => false;

        public IReadOnlyList<PluginInteraction> GetInteractions(short simId, short objectId) =>
            Menus.TryGetValue((simId, objectId), out var list) ? list : [];

        public IReadOnlyList<PluginSimRelationship> GetRelationships(short simId) =>
            RelationshipsBySim.TryGetValue(simId, out var rels) ? rels : [];

        public bool TryQueueAutonomousInteraction(short simId, short objectId, int interactionId, short param0 = 0)
        {
            if (!FreeWill) return false;
            QueuedAutonomous.Add((simId, objectId, interactionId));
            return true;
        }

        public bool TryCancelAutonomousAction(short simId)
        {
            if (!FreeWill) return false;
            CancelledSims.Add(simId);
            return true;
        }

        public bool TryShowSimBalloon(
            short simId,
            PluginBalloonStyle style,
            short? targetObjectId = null,
            int? spriteId = null,
            bool crossedOut = false,
            int durationTicks = 90)
        {
            Balloons.Add(new RecordedBalloon(simId, style, targetObjectId, spriteId, crossedOut, durationTicks));
            return true;
        }
    }

    private static void CopyDirectory(string source, string destination)
    {
        Directory.CreateDirectory(destination);
        foreach (string file in Directory.EnumerateFiles(source))
            File.Copy(file, Path.Combine(destination, Path.GetFileName(file)), overwrite: true);
        foreach (string dir in Directory.EnumerateDirectories(source))
            CopyDirectory(dir, Path.Combine(destination, Path.GetFileName(dir)));
    }

    private static string FindRepoRoot()
    {
        var dir = new DirectoryInfo(AppContext.BaseDirectory);
        while (dir is not null)
        {
            if (Directory.Exists(Path.Combine(dir.FullName, "packs")) && Directory.Exists(Path.Combine(dir.FullName, "native")))
                return dir.FullName;
            dir = dir.Parent;
        }
        throw new DirectoryNotFoundException("Could not locate repository root");
    }
}
