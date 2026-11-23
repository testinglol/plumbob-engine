using SimsEngine.Simulation;

namespace SimsEngine.World;

public sealed class FloorTool(SimulationWorld world, LotFloors floors, FloorCatalog catalog, IFamilyBudget budget, LotTerrain? terrain = null, LotPool? pool = null, LotTiles? tiles = null, LotWalls? walls = null, LotWater? water = null)
{
    public const int ExpenseCategory = 7;
    private const double RefundFactor = 0.800000011920929;

    public int Pending { get; private set; }

    public bool InsufficientFunds { get; private set; }

    public int Rectangle(int fromX, int fromY, int toX, int toY, int pattern, int half = 0)
    {
        var changed = 0;
        for (var x = Math.Min(fromX, toX); x <= Math.Max(fromX, toX); x++)
        for (var y = Math.Min(fromY, toY); y <= Math.Max(fromY, toY); y++)
        {
            var singleTile = fromX == toX && fromY == toY;
            if (Tile(x, y, pattern, out var tileChanged, singleTile ? half : 0, !singleTile) && tileChanged) changed++;
        }
        return changed;
    }

    public int Fill(RoomMap rooms, int x, int y, int pattern, int half = 0)
    {
        if ((uint)x >= LotFloors.Size || (uint)y >= LotFloors.Size) return 0;
        if (half is < 0 or > 4) throw new ArgumentOutOfRangeException(nameof(half));
        var (sampleX, sampleY) = half switch
        {
            1 => (12, 4),
            2 => (4, 12),
            3 => (4, 4),
            4 => (12, 12),
            _ => (8, 8),
        };
        var room = rooms.RoomAtPosition(x * 16 + sampleX, y * 16 + sampleY);
        if (room == RoomMap.NoRoom || (room & 0x3ff) == 0) return 0;
        var initialPending = Pending;
        var snapshot = new List<(int X, int Y, ushort Floor, ushort Wall2, ushort Wall4, bool HadWall)>();
        var changed = 0;

        bool TryTile(int tileX, int tileY, int tileHalf = 0)
        {
            var prevFloor = floors[tileX, tileY];
            ushort wall2 = 0, wall4 = 0;
            var hadWall = walls is not null;
            if (walls is not null)
            {
                wall2 = walls.GetStyle(tileX, tileY, 0);
                wall4 = walls.GetPattern(tileX, tileY, 4);
            }
            if (!Tile(tileX, tileY, pattern, out var tileChanged, tileHalf))
            {
                if (InsufficientFunds)
                {
                    for (var i = snapshot.Count - 1; i >= 0; i--)
                    {
                        var item = snapshot[i];
                        floors[item.X, item.Y] = item.Floor;
                        if (item.HadWall && walls is not null)
                        {
                            walls.SetStyle(item.X, item.Y, 0, item.Wall2);
                            walls.SetPattern(item.X, item.Y, 4, item.Wall4);
                        }
                    }
                    Pending = initialPending;
                    InsufficientFunds = true;
                    return false;
                }
                return true;
            }
            if (tileChanged)
            {
                snapshot.Add((tileX, tileY, prevFloor, wall2, wall4, hadWall));
                changed++;
            }
            return true;
        }

        foreach (var (tileX, tileY) in rooms.TilesInRoom(room).ToArray())
            if (!TryTile(tileX, tileY)) return 0;
        if (walls is not null)
        {
            for (var tileY = 1; tileY < LotFloors.Size - 1; tileY++)
            for (var tileX = 1; tileX < LotFloors.Size - 1; tileX++)
            {
                var diagonal = walls[tileX, tileY][0] & 0x30;
                if (diagonal == 0) continue;
                var candidates = diagonal == 0x20 ? new[] { (Half: 1, X: 12, Y: 4), (Half: 2, X: 4, Y: 12) }
                    : new[] { (Half: 3, X: 4, Y: 4), (Half: 4, X: 12, Y: 12) };
                var matching = candidates.Where(candidate => rooms.RoomAtPosition(tileX * 16 + candidate.X, tileY * 16 + candidate.Y) == room).ToArray();
                foreach (var candidate in matching)
                    if (!TryTile(tileX, tileY, candidate.Half)) return 0;
            }
        }
        return changed;
    }

    public bool Tile(int x, int y, int pattern, out bool changed, int half = 0, bool bothDiagonalSides = false)
    {
        changed = false;
        if (x < 1 || y < 1 || x > LotFloors.Size - 2 || y > LotFloors.Size - 2) return false;
        if (tiles is not null && !tiles.InsideLot(x, y)) return false;
        if (walls is not null)
        {
            var wall = walls[x, y];
            if ((wall[0] & 0x30) != 0)
                return DiagonalTile(x, y, pattern, half, bothDiagonalSides, wall, out changed);
        }
        var existing = floors[x, y];
        var isDeck = floors.Level == 1 && pool?.IsDeck(x, y, 1) == true;
        if (existing == pattern && !(pattern == 0 && isDeck)) return true;
        var objects = world.ObjectsAtTile(x, y, floors.Level).ToArray();
        int cost;
        if (pattern == 0)
        {
            cost = unchecked((int)(-0.5 - catalog.Price(existing) * RefundFactor));
            if (!Affordable(cost)) return Refuse();
            InsufficientFunds = false;
            var level = floors.Level > 1;
            if (objects.Any(item => (unchecked((ushort)item[ObjectData.PlacementFlags]) & 2) == 0 ||
                    (level && (unchecked((ushort)item[ObjectData.PlacementFlags]) & 0x200) == 0))) return true;
        }
        else
        {
            cost = catalog.Price(pattern);
            if (!Affordable(cost)) return Refuse();
            InsufficientFunds = false;
            if (!FlatTile(x, y) || tiles?.Buildable(x, y, floors.Level) == false || pool?.IsPool(x, y, floors.Level) == true || water?.IsWater(x, y, floors.Level) == true || objects.Any(item => (unchecked((ushort)item[ObjectData.PlacementFlags]) & 1) == 0)) return true;
        }
        floors[x, y] = checked((ushort)pattern);
        if (isDeck) pool!.ClearDeck(x, y);
        Pending += cost;
        changed = true;
        return true;
    }

    // Diagonal tiles store the two half-tile floor patterns in wall bytes 2 and 4 with floors[x, y] = 0xFF.
    private bool DiagonalTile(int x, int y, int pattern, int half, bool bothSides, Span<byte> wall, out bool changed)
    {
        changed = false;
        if (half is < 0 or > 4) throw new ArgumentOutOfRangeException(nameof(half));
        var diagonal = wall[0] & 0x30;
        var targetByte = diagonal == 0x20
            ? half == 1 ? 4 : half == 2 ? 2 : 2
            : half == 3 ? 2 : half == 4 ? 4 : 2;
        var otherByte = targetByte == 2 ? 4 : 2;
        ushort GetSlot(int slotByte) => slotByte == 2 ? walls!.GetStyle(x, y, 0) : walls!.GetPattern(x, y, 4);
        void SetSlot(int slotByte, ushort value)
        {
            if (slotByte == 2) walls!.SetStyle(x, y, 0, value);
            else walls!.SetPattern(x, y, 4, value);
        }

        var existing = GetSlot(targetByte);
        if (existing == pattern) return true;

        var cost = catalog.Price(pattern);
        if (!bothSides) cost = unchecked((cost + (cost < 0 ? 1 : 0)) >> 1);
        if (!Affordable(cost)) return Refuse();
        InsufficientFunds = false;
        var objects = world.ObjectsAtTile(x, y, floors.Level).ToArray();
        if (pattern == 0)
        {
            var level = floors.Level > 1;
            if (objects.Any(item => (unchecked((ushort)item[ObjectData.PlacementFlags]) & 2) == 0 ||
                    (level && (unchecked((ushort)item[ObjectData.PlacementFlags]) & 0x200) == 0))) return true;
        }
        else if (!FlatTile(x, y) || tiles?.Buildable(x, y, floors.Level) == false || pool?.IsPool(x, y, floors.Level) == true || water?.IsWater(x, y, floors.Level) == true ||
                 objects.Any(item => (unchecked((ushort)item[ObjectData.PlacementFlags]) & 1) == 0)) return true;

        var previousFloor = floors[x, y];
        var nextValue = checked((ushort)pattern);
        SetSlot(targetByte, nextValue);
        if (bothSides)
        {
            if (GetSlot(otherByte) != nextValue) SetSlot(otherByte, nextValue);
        }
        else if (previousFloor != byte.MaxValue)
        {
            SetSlot(otherByte, previousFloor);
        }
        floors[x, y] = (ushort)(pattern == 0 && GetSlot(otherByte) == 0 ? 0 : byte.MaxValue);
        Pending += cost;
        changed = true;
        return true;
    }

    private bool FlatTile(int x, int y)
    {
        if (terrain is null) return true;
        var corners = terrain.Corners(x, y);
        return corners[0] == corners[1] && corners[0] == corners[2] && corners[0] == corners[3];
    }

    public int Commit()
    {
        var amount = Pending;
        budget.AlterFamilyBudget(ExpenseCategory, amount);
        Pending = 0;
        return amount;
    }

    private bool Affordable(int cost) => cost < 1 || Pending + cost <= budget.ReadFamilyBudget();

    private bool Refuse()
    {
        InsufficientFunds = true;
        return false;
    }
}
