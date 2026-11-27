using SimsEngine.Formats;
using SimsEngine.Simulation;

namespace SimsEngine.World;

public static class LotRoofGrid
{
    private const int StairsBuildModeType = 3;

    public static RoofGrid Build(IffFile lot, int level, IEnumerable<XObject> objects, bool grow = false)
    {
        var grid = Seed(lot, level, objects);
        grid.Plan(grow);
        return grid;
    }

    public static RoofGrid Build(IffFile lot, int level, IEnumerable<XObject> objects, RoofGrid? upperRoof)
    {
        var grid = Seed(lot, level, objects);
        grid.Plan(upperRoof);
        return grid;
    }

    public static RoofGrid Seed(IffFile lot, int level, IEnumerable<XObject> objects)
    {
        if (level is < 1 or > LotGeometry.MaxSupportedStories) throw new ArgumentOutOfRangeException(nameof(level));
        var rooms = RoomMap.Build(lot, level, LotWalls.Size, LotWalls.Size);
        var terrain = LotTerrain.Read(lot);
        var upperLevel = level + 1;
        var upperFloors = upperLevel <= LotGeometry.MaxSupportedStories && LotFloors.HasStoredArray(lot, upperLevel)
            ? LotFloors.Read(lot, upperLevel)
            : null;
        var items = objects.ToArray();
        var localObjects = items.Where(item => item.Position.Height == level)
            .ToLookup(item => (X: item.Position.X >> 4, Y: item.Position.Y >> 4));
        var upperObjects = items.Where(item => item.Position.Height == upperLevel)
            .Select(item => (X: item.Position.X >> 4, Y: item.Position.Y >> 4)).ToHashSet();
        var roofable = new Dictionary<ushort, bool>();
        foreach (var room in rooms.RoomIds)
        {
            var tiles = rooms.TilesInRoom(room).ToArray();
            var flat = tiles.All(tile => terrain.IsFlatAt(tile.X, tile.Y, terrain.ReferenceHeight(tile.X, tile.Y)));
            var roomOverride = (room & 0x3ff) != 0 && tiles.Any(tile => localObjects[tile].Any(item =>
                item.Data[(int)ObjectData.Hidden] == 0 && item.RoomWord84 >= 0 &&
                item.Data[(int)ObjectData.Category] == 8));
            roofable[room] = flat && (roomOverride || !rooms.IsOutside(room));
        }
        bool Roofable(ushort room) => roofable.GetValueOrDefault(room);
        var grid = new RoofGrid(LotWalls.Size * 2);
        for (var x = 0; x < LotWalls.Size; x++)
        for (var y = 0; y < LotWalls.Size; y++)
        {
            var room = rooms.RoomAt(x, y);
            var has = room != RoomMap.NoRoom ? Roofable(room)
                : rooms.AdjacentRoomsAtTile(x, y) is { } pair && (Roofable(pair.First) || Roofable(pair.Second));
            var blocked = upperLevel <= LotGeometry.MaxSupportedStories &&
                ((upperFloors?[x, y] ?? 0) != 0 || (upperObjects.Contains((x, y)) &&
                localObjects[(x, y)].Any(item => item.TypeRecord?.AutonomyAlternativeTypeFlag == StairsBuildModeType)));
            for (var dy = 0; dy < 2; dy++)
            for (var dx = 0; dx < 2; dx++) grid.Seed(y * 2 + dy, x * 2 + dx, has && !blocked, blocked);
        }
        return grid;
    }
}
