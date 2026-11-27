using SimsEngine.Formats;
using SimsEngine.Simulation;

namespace SimsEngine.World;

public sealed class LotTiles
{
    private readonly LotArray?[] grids;

    private LotTiles(LotArray?[] grids) => this.grids = grids;

    public static ushort FlagsChunkId(int level) => checked((ushort)((level - 1) * 100 + 8));

    public static LotTiles Read(IffFile lot)
    {
        var arryType = ResourceType.Parse("Arry");
        LotArray? Grid(ushort id)
        {
            if (lot.Find(arryType, id) is not { } chunk) return null;
            var array = LotArray.Read(lot, chunk);
            return array.Rows == LotWalls.Size && array.Width == LotWalls.Size && array.ElementSize == 1 ? array : null;
        }

        var list = new LotArray?[LotGeometry.MaxSupportedStories];
        for (var level = 1; level <= LotGeometry.MaxSupportedStories; level++)
            list[level - 1] = Grid(FlagsChunkId(level));
        return new LotTiles(list);
    }

    public bool InsideLot(int x, int y) => grids[0] is not { } ground || (ground.Element(x, y)[0] & 0x20) == 0;

    public bool Buildable(int x, int y, int level) =>
        level < 1 || level > grids.Length || grids[level - 1] is not { } grid || (grid.Element(x, y)[0] & 1) != 0;

    public bool HasAnyBuildableTile(int level)
    {
        if (level < 1 || level > grids.Length) return false;
        if (grids[level - 1] is not { } grid) return level == 1;
        for (var x = 0; x < LotWalls.Size; x++)
        for (var y = 0; y < LotWalls.Size; y++)
            if (InsideLot(x, y) && (grid.Element(x, y)[0] & 1) != 0)
                return true;
        return false;
    }

    public static int BuiltStories(IffFile lot, IEnumerable<XObject>? objects = null)
    {
        var arryType = ResourceType.Parse("Arry");
        var stories = lot.Find(arryType, 101) is not null ||
                      lot.Find(arryType, 102) is not null ||
                      lot.Find(arryType, 108) is not null ||
                      lot.Find(arryType, 111) is not null ||
                      lot.Find(arryType, 112) is not null
            ? 2
            : 1;

        for (var level = 3; level <= LotGeometry.MaxSupportedStories; level++)
        {
            if (LotFloors.HasNonEmptyFloor(lot, level) || LotWalls.HasNonEmptyWalls(lot, level))
                stories = level;
        }

        if (objects is not null)
        {
            foreach (var item in objects)
            {
                var level = item.Position.Height;
                if (level <= stories || level > LotGeometry.MaxSupportedStories) continue;
                if (item.Position.X < 0 || item.Position.Y < 0) continue;
                if ((item.SavedMultiTileState?.Value0x1A8 ?? 0) > 0) continue;
                stories = level;
            }
        }

        return stories;
    }

    public static IffFile RefreshStructuralFlags(IffFile lot, IEnumerable<XObject>? objects = null)
    {
        var arryType = ResourceType.Parse("Arry");
        if (lot.Find(arryType, 2) is null && lot.Find(arryType, 12) is null)
            return lot;

        var itemList = objects?.ToArray() ?? [];
        var builtStories = BuiltStories(lot, itemList);
        var maxEvalLevel = Math.Min(LotGeometry.MaxSupportedStories, builtStories + 1);

        var templateChunk = lot.Find(arryType, 8) ?? lot.Find(arryType, 2);
        var templateShape = templateChunk is not null
            ? LotArray.Read(lot, templateChunk)
            : LotArray.CreateEmpty(LotWalls.Size, LotWalls.Size, 1);
        if (templateShape.OldLayout || templateShape.Rows != LotWalls.Size || templateShape.Width != LotWalls.Size)
            templateShape = LotArray.CreateEmpty(LotWalls.Size, LotWalls.Size, 1);

        var existingFlag1 = lot.Find(arryType, 8) is { } chunk8 &&
                            LotArray.Read(lot, chunk8) is { Rows: LotWalls.Size, Width: LotWalls.Size, ElementSize: 1 } arr8
            ? arr8
            : null;

        bool InactiveVoid(int x, int y) => existingFlag1 is not null && (existingFlag1.Element(x, y)[0] & ~0x20) == 0;
        bool OffLot(int x, int y) => existingFlag1 is not null && (existingFlag1.Element(x, y)[0] & 0x20) != 0;
        bool GroundBuildable(int x, int y) => existingFlag1 is null || (existingFlag1.Element(x, y)[0] & 0x01) != 0;

        var wallsByLevel = new LotWalls[maxEvalLevel + 1];
        var floorsByLevel = new LotFloors[maxEvalLevel + 1];
        var outsideByLevel = new bool[maxEvalLevel + 1][];
        var columnsByLevel = new HashSet<(int X, int Y)>[maxEvalLevel + 1];

        for (var level = 1; level <= maxEvalLevel; level++)
        {
            wallsByLevel[level] = LotWalls.Read(lot, level);
            floorsByLevel[level] = LotFloors.Read(lot, level);
            outsideByLevel[level] = RoomMap.ComputeWallOutsideMask(wallsByLevel[level]);
            columnsByLevel[level] = [];
        }

        foreach (var item in itemList)
        {
            var level = item.Position.Height;
            if (level < 1 || level > maxEvalLevel) continue;
            var tx = item.Position.X >> 4;
            var ty = item.Position.Y >> 4;
            if (tx <= 0 || ty <= 0 || tx >= LotWalls.Size - 1 || ty >= LotWalls.Size - 1) continue;
            var isColumn = (item.Definition is { Length: > (int)ObjdField.BuildModeType } &&
                            item.Definition[(int)ObjdField.BuildModeType] == 6) ||
                           item.TypeRecord?.AutonomyAlternativeTypeFlag == 6;
            if (isColumn)
                columnsByLevel[level].Add((tx, ty));
        }

        var updated = lot;
        var highestMaterialized = builtStories;

        for (var level = 1; level <= maxEvalLevel; level++)
        {
            var data = new byte[LotWalls.Size * LotWalls.Size];
            var anyBuildable = false;

            for (var x = 0; x < LotWalls.Size; x++)
            for (var y = 0; y < LotWalls.Size; y++)
            {
                var cellIdx = x * LotWalls.Size + y;
                if (InactiveVoid(x, y))
                {
                    data[cellIdx] = level == 1 ? existingFlag1!.Element(x, y)[0] : (byte)0;
                    continue;
                }

                var offLot = OffLot(x, y);
                var outside = outsideByLevel[level][y * LotWalls.Size + x];
                var hasCol = !offLot && columnsByLevel[level].Contains((x, y));

                if (level == 1)
                {
                    byte flags = existingFlag1 is not null
                        ? (byte)(existingFlag1.Element(x, y)[0] & ~(0x02 | 0x04 | 0x08))
                        : (byte)(GroundBuildable(x, y) ? 0x01 : 0x00);
                    if (offLot) flags |= 0x20;
                    if (outside) flags |= 0x06;
                    if (hasCol) flags |= 0x08;
                    data[cellIdx] = flags;
                    if (!offLot && (flags & 0x01) != 0) anyBuildable = true;
                }
                else
                {
                    var supported = false;
                    if (!offLot)
                    {
                        if (!outsideByLevel[level - 1][y * LotWalls.Size + x])
                        {
                            supported = true;
                        }
                        else if (floorsByLevel[level][x, y] != 0 || wallsByLevel[level][x, y][0] != 0)
                        {
                            supported = true;
                        }
                        else
                        {
                            for (var dx = -1; dx <= 1 && !supported; dx++)
                            for (var dy = -1; dy <= 1 && !supported; dy++)
                                if (columnsByLevel[level - 1].Contains((x + dx, y + dy)))
                                    supported = true;
                        }
                    }

                    byte flags = 0;
                    if (outside) flags |= 0x06;
                    if (supported)
                    {
                        flags |= 0x01;
                        anyBuildable = true;
                    }
                    if (hasCol) flags |= 0x08;
                    data[cellIdx] = flags;
                }
            }

            if (level > builtStories && !anyBuildable)
                break;

            highestMaterialized = Math.Max(highestMaterialized, level);
            var chunkId = FlagsChunkId(level);
            var body = templateShape.ToChunkData(data, 1);
            if (updated.Find(arryType, chunkId) is { } prevChunk && prevChunk.Data.Span.SequenceEqual(body))
                continue;
            updated = updated.WithAddedOrReplacedChunk(arryType, chunkId, body, label: $"flags{level}");
        }

        for (var level = Math.Max(3, builtStories + 1); level <= LotGeometry.MaxSupportedStories; level++)
        {
            if (level > highestMaterialized)
            {
                var flagsId = FlagsChunkId(level);
                if (updated.Find(arryType, flagsId) is not null)
                    updated = updated.WithoutChunk(arryType, flagsId);
            }
            if (!LotFloors.HasNonEmptyFloor(updated, level))
            {
                foreach (var fid in new[] { LotFloors.LegacyChunkId(level), LotFloors.AdvancedChunkId(level) })
                    if (updated.Find(arryType, fid) is not null)
                        updated = updated.WithoutChunk(arryType, fid);
            }
            if (!LotWalls.HasNonEmptyWalls(updated, level))
            {
                foreach (var wid in new[] { LotWalls.LegacyChunkId(level), LotWalls.AdvancedChunkId(level) })
                    if (updated.Find(arryType, wid) is not null)
                        updated = updated.WithoutChunk(arryType, wid);
            }
        }

        return updated;
    }
}
