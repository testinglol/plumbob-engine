using FSO.LotView.Components;
using FSO.LotView;
using FSO.LotView.Model;
using FSO.SimAntics;
using FSO.SimAntics.Model;
using FSO.SimAntics.Utils;
using Microsoft.Xna.Framework;

internal sealed class NativeCutaway
{
    private readonly List<uint> rooms = [];
    private Point? hover;
    private sbyte level;

    internal void Reset() { rooms.Clear(); hover = null; }

    internal void Hover(VM vm, sbyte story, int x, int y)
    {
        if (level != story) { Reset(); level = story; }
        hover = new Point(x, y);
        var room = vm.Context.GetRoomAt(LotTilePos.FromBigTile((short)x, (short)y, story));
        if (!vm.Context.RoomInfo[room].Room.IsOutside && !rooms.Contains(room)) rooms.Add(room);
        if (rooms.Count > 3) rooms.RemoveAt(0);
    }

    internal bool[] Mask(VM vm, sbyte story, string mode, WorldRotation rotation = WorldRotation.TopLeft)
    {
        var architecture = vm.Context.Architecture;
        if (mode == "down") return Enumerable.Repeat(true, architecture.Width * architecture.Height).ToArray();
        if (mode != "cutaway") return new bool[architecture.Width * architecture.Height];
        var result = VMArchitectureTools.GenerateRoomCut(architecture, story, rotation, new HashSet<uint>(rooms));
        if (hover is Point point) VMArchitectureTools.ApplyCutRectangle(architecture, story, result, new Rectangle(point.X, point.Y, 5, 5));
        return result;
    }

    internal static WallComponent.WallGeometry Walls(VM vm, sbyte story, bool[] mask, bool enabled, WorldRotation rotation)
    {
        var architecture = vm.Context.Architecture;
        var blueprint = new Blueprint(architecture.Width, architecture.Height) { Cutaway = mask };
        blueprint.Walls[story - 1] = architecture.Walls[story - 1];
        var geometry = WallComponent.GenerateGeometry(blueprint, architecture.Walls[story - 1], enabled);
        return WallComponent.RotateForCamera(blueprint, story, geometry, rotation);
    }

    internal static bool Hidden(VM vm, VMGameObject entity, bool[] mask)
    {
        if (((VMEntityFlags)entity.GetValue(VMStackObjectVariable.Flags) & VMEntityFlags.HideForCutaway) == 0) return false;
        var architecture = vm.Context.Architecture;
        var x = (int)Math.Round(entity.Position.x / 16f);
        var y = (int)Math.Round(entity.Position.y / 16f);
        if (x < 0 || y < 0 || x >= architecture.Width || y >= architecture.Height) return false;
        var wall = architecture.Walls[entity.Position.Level - 1][y * architecture.Width + x];
        if (!ObjectComponent.CutawayTests.TryGetValue(entity.GetAdjacentWallSegments() & wall.Segments, out var offset))
            ObjectComponent.CutawayTests.TryGetValue(wall.OccupiedWalls & wall.Segments, out offset);
        var nextX = x + offset.X;
        var nextY = y + offset.Y;
        return mask[y * architecture.Width + x] && nextX >= 0 && nextY >= 0 && nextX < architecture.Width && nextY < architecture.Height && mask[nextY * architecture.Width + nextX];
    }
}
