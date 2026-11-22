using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsSimulation;

namespace SimsEngine.Tests;

public sealed class WorldBootstrapFamilySelectionTests
{
    private const uint OwnerGuid = 0x11110001u;
    private const uint VisitorGuid = 0x22220002u;
    private const uint StrayGuid = 0x33330003u;

    [Fact]
    public void ResidentialLot_WithVisitorEarlierInWalkOrder_SelectsHomeownerFamilyNotVisitor()
    {
        using var env = SyntheticNeighborhoodScope.Create();
        var path = env.WriteHouse(69, createPeopleInOrder: [VisitorGuid, OwnerGuid]);

        var boot = WorldBootstrap.Load(env.GameDir, path, lotKey: 69, userDataPath: env.UserData);

        Assert.Equal((short)6, boot.World.WalkOrder.OfType<XPerson>().First()[PersonData.FamilyNumber]);
        Assert.Equal((ushort)13, boot.ActiveFamilyChunkId);
        Assert.NotNull(boot.ActiveFamily);
        Assert.Equal(1373, boot.ActiveFamily!.Budget);
        Assert.Equal((short)13, boot.World[SimulationGlobal.CurrentFamily]);
    }

    [Fact]
    public void ResidentialLot_WithOnlyVisitorOnLot_StillSelectsHomeownerFamily()
    {
        using var env = SyntheticNeighborhoodScope.Create();
        var path = env.WriteHouse(69, createPeopleInOrder: [VisitorGuid]);

        var boot = WorldBootstrap.Load(env.GameDir, path, lotKey: 69, userDataPath: env.UserData);

        Assert.Equal((short)6, boot.World.WalkOrder.OfType<XPerson>().First()[PersonData.FamilyNumber]);
        Assert.Equal((ushort)13, boot.ActiveFamilyChunkId);
        Assert.NotNull(boot.ActiveFamily);
        Assert.Equal(1373, boot.ActiveFamily!.Budget);
        Assert.Equal((short)13, boot.World[SimulationGlobal.CurrentFamily]);
    }

    [Fact]
    public void ResidentialLot_WithExplicitActiveFamilyOverride_UsesOverrideForVisitingFamily()
    {
        using var env = SyntheticNeighborhoodScope.Create();
        var path = env.WriteHouse(69, createPeopleInOrder: [VisitorGuid, OwnerGuid]);

        var boot = WorldBootstrap.Load(env.GameDir, path, lotKey: 69, activeFamilyChunkId: 6, userDataPath: env.UserData);

        Assert.Equal((ushort)6, boot.ActiveFamilyChunkId);
        Assert.NotNull(boot.ActiveFamily);
        Assert.Equal(1529, boot.ActiveFamily!.Budget);
        Assert.Equal((short)6, boot.World[SimulationGlobal.CurrentFamily]);
    }

    [Fact]
    public void CommunityLot_WithStrayInWalkOrderAndNoActiveFamilyOverride_StaysSimless()
    {
        using var env = SyntheticNeighborhoodScope.Create();
        var path = env.WriteHouse(73, createPeopleInOrder: [StrayGuid]);

        var boot = WorldBootstrap.Load(env.GameDir, path, lotKey: 73, userDataPath: env.UserData);

        Assert.Equal((short)NeighborhoodEdits.StrayFamilyId, boot.World.WalkOrder.OfType<XPerson>().First()[PersonData.FamilyNumber]);
        Assert.Null(boot.ActiveFamilyChunkId);
        Assert.Null(boot.ActiveFamily);
        Assert.Equal((short)1, boot.World[SimulationGlobal.SimlessBuildMode]);
        Assert.Equal((short)0, boot.World[SimulationGlobal.CurrentFamily]);
    }

    private sealed class SyntheticNeighborhoodScope : IDisposable
    {
        public string GameDir { get; }
        public string UserData { get; }

        private SyntheticNeighborhoodScope(string gameDir, string userData)
        {
            GameDir = gameDir;
            UserData = userData;
        }

        public static SyntheticNeighborhoodScope Create()
        {
            var gameDir = Path.Combine(Path.GetTempPath(), "sims-wb-family-" + Guid.NewGuid().ToString("N"));
            var globalDir = Path.Combine(gameDir, "GameData", "Global");
            var userData = Path.Combine(gameDir, "UserData");
            var charsDir = Path.Combine(userData, "Characters");
            var housesDir = Path.Combine(userData, "Houses");
            Directory.CreateDirectory(globalDir);
            Directory.CreateDirectory(charsDir);
            Directory.CreateDirectory(housesDir);

            var bhav = new ChunkBuilder()
                .U16(0x8002).U16(0).U8(0).U8(0).U8(0).U8(0).S32(0)
                .U16(0).U8(254).U8(255).Raw(new byte[8])
                .ToArray();
            var decayFcns = BuildMotiveDecayConstants();
            var moodCurves = BuildSevenCurveStrings();
            File.WriteAllBytes(
                Path.Combine(globalDir, "Global.iff"),
                ChunkBuilder.File(
                    ("BHAV", 256, bhav),
                    ("FCNS", 1, decayFcns),
                    ("FCNS", 5, decayFcns),
                    ("FCNS", 6, decayFcns),
                    ("STR#", 0x1f5, moodCurves),
                    ("STR#", 0x1f6, moodCurves),
                    ("STR#", 0x1f7, moodCurves),
                    ("STR#", 0x1f8, moodCurves)));

            WritePersonFile(Path.Combine(charsDir, "User00001.iff"), OwnerGuid, "Claire");
            WritePersonFile(Path.Combine(charsDir, "User00002.iff"), VisitorGuid, "Ginia");
            WritePersonFile(Path.Combine(charsDir, "User00003.iff"), StrayGuid, "Stray");

            var sentinel = Family.CreateNew(0, 0, []);
            var ownerFamily = Family.CreateNew(11, 69, [OwnerGuid], budget: 1373, value: 18393, flags: 1);
            var visitorFamily = Family.CreateNew(6, 56, [VisitorGuid], budget: 1529, value: 27499, flags: 1);
            var strayFamily = Family.CreateNew(4000, 0, [StrayGuid], budget: 0, value: 0, flags: 0);

            var visitorData = new short[256];
            visitorData[(int)PersonData.FamilyNumber] = 6;
            visitorData[(int)PersonData.PersonAge] = 27;
            var ownerData = new short[256];
            ownerData[(int)PersonData.FamilyNumber] = 13;
            ownerData[(int)PersonData.PersonAge] = 27;
            var strayData = new short[256];
            strayData[(int)PersonData.FamilyNumber] = (short)NeighborhoodEdits.StrayFamilyId;
            strayData[(int)PersonData.Gender] = 2;

            var nbrs = new Neighbors(
                version: 0x49,
                slotCount: 3,
                entries:
                [
                    new Neighbor(0, 10, "Ginia", 0, visitorData, 1, VisitorGuid, new Dictionary<int, IReadOnlyList<int>>(), 10, 0),
                    new Neighbor(1, 10, "Claire", 0, ownerData, 2, OwnerGuid, new Dictionary<int, IReadOnlyList<int>>(), 10, 0),
                    new Neighbor(2, 10, "Stray", 0, strayData, 3, StrayGuid, new Dictionary<int, IReadOnlyList<int>>(), 10, 0),
                ]);

            var ngbh = PersistWriter.Start(false, 0x3e, "HBGN");
            for (var i = 0; i < 16; i++) ngbh.Int16(0);

            File.WriteAllBytes(
                Path.Combine(userData, "Neighborhood.iff"),
                ChunkBuilder.File(
                    ("NGBH", 1, ngbh.ToArray()),
                    ("FAMI", 0, sentinel.Write(0)),
                    ("FAMI", 6, visitorFamily.Write(6)),
                    ("FAMI", 13, ownerFamily.Write(13)),
                    ("FAMI", NeighborhoodEdits.StrayFamilyId, strayFamily.Write(NeighborhoodEdits.StrayFamilyId)),
                    ("NBRS", 1, nbrs.WriteChunkData(swap: false))));

            var zoningStrings = new ChunkBuilder()
                .S16(-3).S16(3)
                .U8(1).CString("56, residential").CString("")
                .U8(1).CString("69, residential").CString("")
                .U8(1).CString("73, community").CString("")
                .ToArray();
            File.WriteAllBytes(
                Path.Combine(userData, "LotZoning.iff"),
                ChunkBuilder.File(("STR#", 1, zoningStrings)));

            return new SyntheticNeighborhoodScope(gameDir, userData);
        }

        public string WriteHouse(int houseNumber, uint[] createPeopleInOrder)
        {
            var registry = ObjectRegistry.Scan(GameDir, Path.Combine(UserData, "Characters"));
            var library = GlobalLibrary.Open(GameDir);

            var objm = PersistWriter.Start(false, 0x45, "MjbO");
            objm.WriteCodingFlag(false);
            objm.Int16(0);
            objm.BeginBlock();
            objm.Int16(0);
            objm.Int32(0);
            objm.String("");
            var objt = PersistWriter.Start(false, 3, "tjbo");
            objt.Int32(0);

            var lotPath = Path.Combine(UserData, "Houses", $"House{houseNumber:D2}.iff");
            var emptyLot = new IffFile(
                ChunkBuilder.File(("ObjM", 1, objm.ToArray()), ("objt", 0, objt.ToArray())),
                lotPath);
            var world = SavedLotObjectLoader.Load(emptyLot, registry, library);

            for (var i = 0; i < createPeopleInOrder.Length; i++)
            {
                var guid = createPeopleInOrder[i];
                var person = (XPerson)world.ObjectFactory!(unchecked((int)guid))!;
                if (guid == OwnerGuid)
                {
                    person[PersonData.FamilyNumber] = 13;
                    person[PersonData.NeighborId] = 2;
                    person[PersonData.PersonAge] = 27;
                }
                else if (guid == VisitorGuid)
                {
                    person[PersonData.FamilyNumber] = 6;
                    person[PersonData.NeighborId] = 1;
                    person[PersonData.PersonAge] = 27;
                }
                else if (guid == StrayGuid)
                {
                    person[PersonData.FamilyNumber] = (short)NeighborhoodEdits.StrayFamilyId;
                    person[PersonData.NeighborId] = 3;
                    person[PersonData.Gender] = 2;
                }
                person.Position = new ObjectPosition((short)(32 + i * 16), 32, 1);
                world.Add(person);
            }

            var (savedLot, _) = world.WriteSavedLotObjectsTo(emptyLot);
            File.WriteAllBytes(lotPath, savedLot.Bytes.ToArray());
            return lotPath;
        }

        private static void WritePersonFile(string path, uint guid, string name)
        {
            var builder = new ChunkBuilder();
            for (var field = 0; field < 80; field++)
            {
                ushort value = field switch
                {
                    (int)ObjdField.Version1 => 138,
                    (int)ObjdField.Type => 2,
                    (int)ObjdField.Guid1 => unchecked((ushort)(guid & 0xFFFF)),
                    (int)ObjdField.Guid2 => unchecked((ushort)(guid >> 16)),
                    (int)ObjdField.BodyStringsId => 200,
                    (int)ObjdField.NumAttributes => 8,
                    _ => 0,
                };
                builder.U16(value);
            }

            var ctss = new ChunkBuilder().S16(-3).S16(1).U8(1).CString(name).CString("").ToArray();
            var body = new ChunkBuilder().S16(-3).S16(3)
                .U8(1).CString("adult").CString("")
                .U8(1).CString("b001fa_lgt,lgt").CString("")
                .U8(1).CString("c001fa_lgt,lgt").CString("")
                .ToArray();
            File.WriteAllBytes(path, ChunkBuilder.File(("OBJD", 128, builder.ToArray()), ("STR#", 200, body), ("CTSS", 2000, ctss)));
        }

        private static byte[] BuildMotiveDecayConstants()
        {
            string[] names =
            [
                "energy span", "wake hours", "wake hour", "energy drift",
                "hunger to bladder multiplier", "comfort decrement active", "comfort decrement lazy",
                "hunger decrement ratio", "social decrement base", "social decrement multiplier",
                "ent decrement, awake", "ent multiplier, asleep",
                "hyg decrement, awake", "hyg decrement, asleep",
                "bladder decrement, awake", "bladder decrement, asleep",
            ];
            var chunk = new ChunkBuilder().U32(0).S32(1).Raw("SNCF"u8).S32(names.Length);
            foreach (var name in names)
                chunk.EvenString(name).F32(1f).EvenString("");
            return chunk.ToArray();
        }

        private static byte[] BuildSevenCurveStrings()
        {
            var chunk = new ChunkBuilder().S16(-3).S16(7);
            for (var i = 0; i < 7; i++)
                chunk.U8(1).CString("(0;1)").CString("");
            return chunk.ToArray();
        }

        public void Dispose()
        {
            try
            {
                if (Directory.Exists(GameDir))
                    Directory.Delete(GameDir, recursive: true);
            }
            catch
            {
            }
        }
    }
}
