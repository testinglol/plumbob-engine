using FSO.Content;
using FSO.LotView.Model;
using FSO.SimAntics;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.Model;
using System;
using System.Linq;

internal static class NativeArchitectureHistoryChecks
{
    internal static object Run(VM vm)
    {
        if (!vm.TS1) throw new InvalidOperationException("Construction history checks require a TS1 VM");
        var architecture = vm.Context.Architecture;
        var terrain = architecture.Terrain;
        var originalHeights = terrain.Heights.ToArray();
        var originalGrass = terrain.GrassState.ToArray();
        var originalLight = terrain.LightType;
        var originalDark = terrain.DarkType;
        var originalFloors = architecture.Floors.Select(level => level.ToArray()).ToArray();
        var originalWalls = architecture.Walls.Select(level => level.ToArray()).ToArray();
        var originalRoomMaps = architecture.Rooms.Select(room => room.Map.ToArray()).ToArray();
        var originalRoofStyle = architecture.RoofStyle;
        var originalRoofPitch = architecture.RoofPitch;
        var family = vm.TS1State.CurrentFamily;
        var originalBudget = family?.Budget ?? 0;
        var originalTS1 = vm.TS1;
        var tsoHistoryRejected = false;
        try
        {
            vm.TS1 = false;
            new NativeArchitectureHistory().Begin(vm);
        }
        catch (InvalidOperationException)
        {
            tsoHistoryRejected = true;
        }
        finally
        {
            vm.TS1 = originalTS1;
        }
        if (!tsoHistoryRejected) throw new InvalidOperationException("Construction history accepted a TSO VM");
        var floor = Content.Get().WorldFloors.Entries.Values.FirstOrDefault(item => item.ID > 1 && item.ID <= ushort.MaxValue);
        var index = Enumerable.Range(0, originalFloors[0].Length).FirstOrDefault(candidate => floor != null && originalFloors[0][candidate].Pattern != floor.ID, -1);
        if (floor == null || index < 0) throw new InvalidOperationException("No alternate floor pattern is available for construction history check");
        var x = (short)(index % architecture.Width);
        var y = (short)(index / architecture.Width);
        var heightIndex = Math.Min(originalHeights.Length - 1, index);
        var nextHeight = (short)(originalHeights[heightIndex] == short.MaxValue ? short.MaxValue - 1 : originalHeights[heightIndex] + 1);
        var budgetDelta = family != null && family.Budget > 0 ? -1 : 0;
        var history = new NativeArchitectureHistory();
        try
        {
            history.Begin(vm);
            architecture.SetTerrainHeight(x, y, nextHeight);
            var tile = architecture.GetFloor(x, y, 1);
            tile.Pattern = (ushort)floor.ID;
            architecture.SetFloor(x, y, 1, tile, true);
            if (family != null) family.Budget += budgetDelta;
            if (!history.Commit(vm)) throw new InvalidOperationException("Construction history did not record an edit");
            if (!history.Undo(vm)) throw new InvalidOperationException("Construction history could not undo the edit");
            var undoHeight = architecture.Terrain.Heights[heightIndex];
            var undoFloor = architecture.Floors[0][index].Pattern;
            var undoBudget = family?.Budget ?? 0;
            if (!architecture.Terrain.Heights.SequenceEqual(originalHeights) || !architecture.Floors[0].SequenceEqual(originalFloors[0]) ||
                (family != null && family.Budget != originalBudget))
                throw new InvalidOperationException($"Construction undo mismatch: height {undoHeight} (expected {originalHeights[heightIndex]}), floor {undoFloor} (expected {originalFloors[0][index].Pattern}), budget {undoBudget} (expected {originalBudget})");
            if (!architecture.Rooms.Select((room, level) => room.Map.SequenceEqual(originalRoomMaps[level])).All(matches => matches) ||
                vm.Context.RoomInfo.Length != architecture.RoomData.Count)
                throw new InvalidOperationException("Construction undo did not synchronously restore room maps and room-info count");
            if (!history.Redo(vm)) throw new InvalidOperationException("Construction history could not redo the edit");
            if (architecture.Terrain.Heights[heightIndex] != nextHeight || architecture.Floors[0][index].Pattern != floor.ID ||
                (family != null && family.Budget != originalBudget + budgetDelta))
                throw new InvalidOperationException("Construction redo did not reapply terrain, floors, and transaction funds");
            architecture.SetRoof(architecture.RoofPitch == 1f ? 0.99f : 1f, architecture.RoofStyle);
            if (history.Undo(vm)) throw new InvalidOperationException("Construction history overwrote a later architecture edit");
            return new { tile = new { x, y }, beforeFloor = originalFloors[0][index].Pattern, afterFloor = floor.ID, budgetDelta };
        }
        finally
        {
            var restoredTerrain = new VMArchitectureTerrain(architecture.Width, architecture.Height)
            {
                Heights = originalHeights,
                GrassState = originalGrass,
                LightType = originalLight,
                DarkType = originalDark
            };
            architecture.Load(new VMArchitectureMarshal
            {
                Width = architecture.Width,
                Height = architecture.Height,
                Stories = architecture.Stories,
                Terrain = restoredTerrain,
                Floors = originalFloors,
                Walls = originalWalls,
                FineBuildableArea = architecture.FineBuildableArea,
                RoofStyle = originalRoofStyle,
                RoofPitch = originalRoofPitch,
                BuildBuyEnabled = architecture.BuildBuyEnabled
            });
            architecture.SignalAllDirty();
            architecture.SignalTerrainRedraw();
            architecture.Tick();
            if (family != null) family.Budget = originalBudget;
        }
    }
}
