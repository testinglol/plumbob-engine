using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsEngine.Tests;

public sealed class FloorToolTests
{
    private sealed class Budget(int funds) : IFamilyBudget
    {
        public int Funds { get; private set; } = funds;
        public int ReadFamilyBudget() => Funds;
        public void AlterFamilyBudget(int expenseType, int amount) => Funds -= amount;
    }

    private static (IffFile Lot, FloorCatalog Catalog) CreateSetup()
    {
        byte[] BuildArry(int elementSize, byte[] rawData) => new ChunkBuilder()
            .S16(0).S16(0).S32(64).S32(64).S32(elementSize).S32(0).Raw(rawData).ToArray();

        var terrainData = new byte[64 * 64 * 4];
        var wallData = new byte[64 * 64 * 8];
        var floorData = new byte[64 * 64 * 2];
        var tileFlags = Enumerable.Repeat((byte)1, 64 * 64).ToArray();

        var lot = new IffFile(ChunkBuilder.File(
            ("Arry", 0, BuildArry(4, terrainData)),
            ("Arry", 2, BuildArry(8, wallData)),
            ("Arry", 8, BuildArry(1, tileFlags)),
            ("Arry", 11, BuildArry(2, floorData))
        ), "lot.iff");

        var strings = new ChunkBuilder().S16(-3).S16(6)
            .U8(1).CString("10").CString("")
            .U8(1).CString("Tile One").CString("")
            .U8(1).CString("First floor").CString("")
            .U8(1).CString("20").CString("")
            .U8(1).CString("Tile Two").CString("")
            .U8(1).CString("Second floor").CString("");
        var build = new IffFile(ChunkBuilder.File(("STR#", 0x82, strings.ToArray())), "Build.iff");
        return (lot, FloorCatalog.Read(build));
    }

    [Fact]
    public void PaintingReplacingAndErasingFlatTilesChargesAndRefundsCorrectly()
    {
        var (lot, catalog) = CreateSetup();
        var floors = LotFloors.Read(lot, 1);
        var budget = new Budget(1000);
        var tool = new FloorTool(new SimulationWorld(), floors, catalog, budget,
            LotTerrain.Read(lot), LotPool.Read(lot), LotTiles.Read(lot), LotWalls.Read(lot, 1), LotWater.Read(lot));

        Assert.Equal(4, tool.Rectangle(10, 10, 11, 11, pattern: 1));
        Assert.Equal(40, tool.Commit());
        Assert.Equal(960, budget.Funds);

        Assert.Equal(0, tool.Rectangle(10, 10, 11, 11, pattern: 1));
        Assert.Equal(0, tool.Commit());

        Assert.Equal(4, tool.Rectangle(10, 10, 11, 11, pattern: 2));
        Assert.Equal(80, tool.Commit());
        Assert.Equal(880, budget.Funds);

        Assert.Equal(4, tool.Rectangle(10, 10, 11, 11, pattern: 0));
        Assert.Equal(-64, tool.Commit());
        Assert.Equal(944, budget.Funds);
    }

    [Fact]
    public void DiagonalSingleHalfPreservesOtherHalfAndSentinelUntilBothSidesErased()
    {
        var (lot, catalog) = CreateSetup();
        var floors = LotFloors.Read(lot, 1);
        var walls = LotWalls.Read(lot, 1);
        walls[10, 10][0] = 0x10;
        walls[10, 10][3] = 1;
        floors[10, 10] = 1;

        var budget = new Budget(1000);
        var tool = new FloorTool(new SimulationWorld(), floors, catalog, budget,
            LotTerrain.Read(lot), LotPool.Read(lot), LotTiles.Read(lot), walls, LotWater.Read(lot));

        Assert.True(tool.Tile(10, 10, 2, out var changed, half: 4, bothDiagonalSides: false));
        Assert.True(changed);
        Assert.Equal(byte.MaxValue, floors[10, 10]);
        Assert.Equal(2, walls[10, 10][4]);
        Assert.Equal(1, walls[10, 10][2]);

        Assert.True(tool.Tile(10, 10, 0, out changed, half: 4, bothDiagonalSides: false));
        Assert.True(changed);
        Assert.Equal(byte.MaxValue, floors[10, 10]);
        Assert.Equal(0, walls[10, 10][4]);
        Assert.Equal(1, walls[10, 10][2]);

        Assert.True(tool.Tile(10, 10, 0, out changed, half: 3, bothDiagonalSides: false));
        Assert.True(changed);
        Assert.Equal(0, floors[10, 10]);
    }

    [Fact]
    public void FillRefusesExteriorRoomZeroAndFillsEnclosedRoomOnly()
    {
        var (lot, catalog) = CreateSetup();
        var walls = LotWalls.Read(lot, 1);
        for (var i = 10; i <= 11; i++)
        {
            walls[9, i][0] |= 4;
            walls[10, i][0] |= 1;
            walls.SetStyle(10, i, 0, 1);

            walls[11, i][0] |= 4;
            walls[12, i][0] |= 1;
            walls.SetStyle(12, i, 0, 1);

            walls[i, 9][0] |= 8;
            walls[i, 10][0] |= 2;
            walls.SetStyle(i, 10, 1, 1);

            walls[i, 11][0] |= 8;
            walls[i, 12][0] |= 2;
            walls.SetStyle(i, 12, 1, 1);
        }
        lot = walls.WriteTo(lot);

        var floors = LotFloors.Read(lot, 1);
        var rooms = RoomMap.Build(lot, 1, 64, 64);
        Assert.Equal(0, rooms.RoomAt(5, 5) & 0x3ff);
        Assert.NotEqual(0, rooms.RoomAt(10, 10) & 0x3ff);

        var budget = new Budget(1000);
        var tool = new FloorTool(new SimulationWorld(), floors, catalog, budget,
            LotTerrain.Read(lot), LotPool.Read(lot), LotTiles.Read(lot), walls, LotWater.Read(lot));

        Assert.Equal(0, tool.Fill(rooms, 5, 5, pattern: 1));
        Assert.Equal(0, tool.Commit());
        Assert.Equal(1000, budget.Funds);
        Assert.Equal(0, floors[5, 5]);
        Assert.Equal(0, floors[10, 10]);

        Assert.Equal(4, tool.Fill(rooms, 10, 10, pattern: 1));
        Assert.Equal(40, tool.Commit());
        Assert.Equal(960, budget.Funds);
        Assert.Equal(1, floors[10, 10]);
        Assert.Equal(1, floors[10, 11]);
        Assert.Equal(1, floors[11, 10]);
        Assert.Equal(1, floors[11, 11]);
        Assert.Equal(0, floors[5, 5]);
    }
}
