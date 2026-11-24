using SimsEngine.Content;
using SimsEngine.Formats;
using System.Text;
using Xunit;

namespace SimsEngine.Tests;

public sealed class GlobalLibraryTests
{
    private static byte[] Tree(ushort opcode) =>
        new ChunkBuilder().U16(0x8002).S16(1).U8(0).U8(0).U8(0).U8(0).U32(0)
            .U16(opcode).U8(BhavInstruction.ReturnTrue).U8(BhavInstruction.ReturnFalse).Raw(new byte[8]).ToArray();

    private static IffFile NamedFile(string name, ushort id)
    {
        var bytes = ChunkBuilder.File(("BHAV", id, Tree(1)));
        Encoding.Latin1.GetBytes(name).CopyTo(bytes, IffFile.HeaderSize + 12);
        return new IffFile(bytes, name + ".iff");
    }

    [Theory]
    [InlineData(0, TreeScope.Primitive)]
    [InlineData(255, TreeScope.Primitive)]
    [InlineData(256, TreeScope.Global)]
    [InlineData(4095, TreeScope.Global)]
    [InlineData(4096, TreeScope.Private)]
    [InlineData(8191, TreeScope.Private)]
    [InlineData(8192, TreeScope.SemiGlobal)]
    [InlineData(9000, TreeScope.SemiGlobal)]
    [InlineData(9001, TreeScope.Primitive)]
    [InlineData(-1, TreeScope.Primitive)]
    public void TreeIdsSplitAsSimsExeSplitsThem(short id, TreeScope scope) => Assert.Equal(scope, BehaviorScope.ScopeOf(id));

    [Fact]
    public void AnObjectReachesGlobalPrivateAndSemiGlobalTrees()
    {
        var game = Directory.CreateTempSubdirectory("globals").FullName;
        try
        {
            var globalFolder = Path.Combine(game, "GameData", "Global");
            var objects = Path.Combine(game, "GameData", "Objects");
            Directory.CreateDirectory(globalFolder);
            Directory.CreateDirectory(objects);
            File.WriteAllBytes(Path.Combine(globalFolder, "Global.iff"), ChunkBuilder.File(("BHAV", 256, Tree(1))));
            File.WriteAllBytes(Path.Combine(globalFolder, "ChairGlobals.iff"), ChunkBuilder.File(("BHAV", 8192, Tree(3))));
            var definition = new ChunkBuilder();
            for (var field = 0; field < 20; field++) definition.U16(field == 14 ? (ushort)0x1234 : (ushort)0);
            var glob = new ChunkBuilder().U8(12).Raw("chairglobals"u8).ToArray();
            File.WriteAllBytes(Path.Combine(objects, "Chair.iff"),
                ChunkBuilder.File(("OBJD", 128, definition.ToArray()), ("GLOB", 128, glob), ("BHAV", 4096, Tree(2))));

            var entry = ObjectRegistry.Scan(game).Find(0x1234)!;
            Assert.Equal("chairglobals", entry.SemiGlobal);
            var scope = GlobalLibrary.Open(game).ScopeOf(entry)!;
            Assert.Equal(1, scope.Find(256)!.Instructions[0].Opcode);
            Assert.Equal(2, scope.Find(4096)!.Instructions[0].Opcode);
            Assert.Equal(3, scope.Find(8192)!.Instructions[0].Opcode);
            Assert.Null(scope.Find(8193));
            Assert.Null(scope.Find(12));
        }
        finally { Directory.Delete(game, true); }
    }

    [Fact]
    public void FlatInstallLoadsGlobalIffFromTheRootGlobalDirectory()
    {
        var game = Directory.CreateTempSubdirectory("flat-globals").FullName;
        try
        {
            var globalFolder = Path.Combine(game, "Global");
            Directory.CreateDirectory(globalFolder);
            File.WriteAllBytes(Path.Combine(globalFolder, "Global.iff"), ChunkBuilder.File(("BHAV", 256, Tree(7))));

            var global = GlobalLibrary.Open(game).Global;
            var chunk = Assert.Single(global!.OfType(ResourceType.Bhav));
            Assert.Equal(7, Bhav.Read(global, chunk).Instructions[0].Opcode);
        }
        finally { Directory.Delete(game, true); }
    }

    [Fact]
    public void NamedTreeLookupUsesCaseInsensitiveLabelsInPrivateThenSemiGlobalThenGlobalOrder()
    {
        var scope = new BehaviorScope(
            NamedFile("Hello", 257),
            NamedFile("hello", 4097),
            NamedFile("Hello", 8193));

        Assert.Equal(4097, scope.FindNamedTree("Hello"));
        Assert.Equal(4097, scope.FindNamedTree("HELLO"));
    }

    [Fact]
    public void NamedTreeLookupReturnsZeroWhenNoBhavLabelMatches()
    {
        var scope = new BehaviorScope(NamedFile("Global", 257), NamedFile("Private", 4097), null);
        Assert.Equal(0, scope.FindNamedTree("Missing"));
    }

    [Fact]
    public void VanillaRoachesStompTreesUpgradeToKillAndAllowPlayerPieMenu()
    {
        var objd = new ChunkBuilder();
        for (var field = 0; field < 20; field++)
        {
            objd.U16(field switch
            {
                14 => 0xA98E,
                15 => 0x4415,
                _ => 0,
            });
        }

        var stomp = new ChunkBuilder().U16(0x8002).S16(18).U8(0).U8(0).U8(3).U8(0).U32(9);
        for (var i = 0; i < 18; i++)
        {
            var opcode = i switch { 0 => (ushort)27, 8 => (ushort)2, 9 => (ushort)281, 10 => (ushort)44, _ => (ushort)0 };
            var t = i == 10 ? BhavInstruction.ReturnTrue : (byte)1;
            var f = i == 10 ? (byte)10 : BhavInstruction.ReturnFalse;
            stomp.U16(opcode).U8(t).U8(f).Raw(new byte[8]);
        }

        var stompTest = new ChunkBuilder().U16(0x8002).S16(1).U8(0).U8(1).U8(0).U8(0).U32(0)
            .U16(2).U8(BhavInstruction.ReturnTrue).U8(BhavInstruction.ReturnFalse)
            .Raw([0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 0x09, 0x07]);

        var roachesFile = new IffFile(ChunkBuilder.File(
            ("OBJD", 16807, objd.ToArray()),
            ("BHAV", 4097, stomp.ToArray()),
            ("BHAV", 4098, stompTest.ToArray())), "Roaches.iff");

        var scope = new BehaviorScope(NamedFile("Global", 256), roachesFile, null);
        var upgradedStomp = scope.Find(4097)!;
        var upgradedTest = scope.Find(4098)!;

        Assert.Equal(38, upgradedStomp.Instructions.Count);
        Assert.Equal(23, upgradedStomp.Instructions[8].FalseTarget);
        Assert.Equal(25, upgradedStomp.Instructions[9].TrueTarget);
        Assert.Equal(24, upgradedStomp.Instructions[10].TrueTarget);
        Assert.Equal(3, upgradedTest.Instructions.Count);
        Assert.Equal(321, upgradedTest.Instructions[2].Opcode);
    }
}
