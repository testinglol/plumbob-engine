using FSO.Files.Formats.IFF.Chunks;
using FSO.LotView.Model;
using FSO.SimAntics;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.Model;
using System;
using System.Collections.Generic;
using System.Linq;

internal sealed class NativeArchitectureHistory
{
    private sealed record ArchitectureState(object Architecture, short[] Heights, byte[] Grass, FSO.Content.Model.TerrainType LightType,
        FSO.Content.Model.TerrainType DarkType, FloorTile[][] Floors, WallTile[][] Walls, uint RoofStyle, float RoofPitch, FAMI? ActiveFamily, int? FamilyID, int Budget);
    private sealed record Entry(ArchitectureState Before, ArchitectureState After);

    private readonly Stack<Entry> undo = new();
    private readonly Stack<Entry> redo = new();
    private ArchitectureState? pending;
    private FAMI? pendingFamily;

    internal void Invalidate()
    {
        pending = null;
        pendingFamily = null;
        undo.Clear();
        redo.Clear();
    }

    internal void Begin(VM vm)
    {
        if (!vm.TS1) throw new InvalidOperationException("Construction history is available only in TS1");
        if (pending != null) throw new InvalidOperationException("A construction edit is already pending");
        pendingFamily = vm.TS1State.CurrentFamily;
        pending = Capture(vm, pendingFamily);
    }

    internal bool Commit(VM vm)
    {
        if (pending == null) throw new InvalidOperationException("No construction edit is pending");
        var before = pending;
        var family = pendingFamily;
        pending = null;
        pendingFamily = null;
        if (!ReferenceEquals(vm.TS1State.CurrentFamily, family)) return false;
        var after = Capture(vm, family);
        if (SameArchitecture(before, after) && before.Budget == after.Budget) return false;
        undo.Push(new Entry(before, after));
        redo.Clear();
        return true;
    }

    internal bool Undo(VM vm)
    {
        if (!CanUndo(vm)) return false;
        var entry = undo.Peek();
        Apply(vm, entry.Before, entry.After);
        undo.Pop();
        redo.Push(entry);
        return true;
    }

    internal bool Redo(VM vm)
    {
        if (!CanRedo(vm)) return false;
        var entry = redo.Peek();
        Apply(vm, entry.After, entry.Before);
        redo.Pop();
        undo.Push(entry);
        return true;
    }

    internal bool CanUndo(VM vm) => pending == null && undo.Count > 0 &&
        Matches(vm, undo.Peek().After) && CanApplyBudget(vm, undo.Peek().After, undo.Peek().Before);

    internal bool CanRedo(VM vm) => pending == null && redo.Count > 0 &&
        Matches(vm, redo.Peek().Before) && CanApplyBudget(vm, redo.Peek().Before, redo.Peek().After);

    private static ArchitectureState Capture(VM vm, FAMI? family)
    {
        var architecture = vm.Context.Architecture;
        var terrain = architecture.Terrain;
        return new ArchitectureState(architecture, terrain.Heights.ToArray(), terrain.GrassState.ToArray(), terrain.LightType, terrain.DarkType,
            architecture.Floors.Select(level => level.ToArray()).ToArray(), architecture.Walls.Select(level => level.ToArray()).ToArray(),
            architecture.RoofStyle, architecture.RoofPitch, family, family?.ChunkID, family?.Budget ?? 0);
    }

    private static bool SameArchitecture(ArchitectureState left, ArchitectureState right) =>
        left.LightType == right.LightType && left.DarkType == right.DarkType && left.RoofStyle == right.RoofStyle && left.RoofPitch == right.RoofPitch &&
        left.Heights.AsSpan().SequenceEqual(right.Heights) && left.Grass.AsSpan().SequenceEqual(right.Grass) &&
        SameLayers(left.Floors, right.Floors) && SameLayers(left.Walls, right.Walls);

    private static bool SameLayers<T>(T[][] left, T[][] right) where T : struct
    {
        if (left.Length != right.Length) return false;
        var comparer = EqualityComparer<T>.Default;
        for (var level = 0; level < left.Length; level++)
        {
            if (left[level].Length != right[level].Length) return false;
            for (var index = 0; index < left[level].Length; index++)
                if (!comparer.Equals(left[level][index], right[level][index])) return false;
        }
        return true;
    }

    private static bool Matches(VM vm, ArchitectureState state)
    {
        if (!ReferenceEquals(vm.Context.Architecture, state.Architecture)) return false;
        var family = vm.TS1State.CurrentFamily;
        if (!ReferenceEquals(family, state.ActiveFamily) || family?.ChunkID != state.FamilyID) return false;
        var current = Capture(vm, family);
        return SameArchitecture(current, state);
    }

    private static bool CanApplyBudget(VM vm, ArchitectureState from, ArchitectureState to)
    {
        var family = vm.TS1State.CurrentFamily;
        if (family == null) return from.ActiveFamily == null && to.ActiveFamily == null && from.FamilyID == null && to.FamilyID == null;
        if (!ReferenceEquals(family, from.ActiveFamily) || !ReferenceEquals(family, to.ActiveFamily) || from.FamilyID != family.ChunkID || to.FamilyID != family.ChunkID) return false;
        return family.Budget + (to.Budget - from.Budget) >= 0;
    }

    private static void Apply(VM vm, ArchitectureState target, ArchitectureState source)
    {
        try
        {
            ApplyCore(vm, target, source);
        }
        catch
        {
            try { ApplyCore(vm, source, target); }
            catch { }
            throw;
        }
        var family = vm.TS1State.CurrentFamily;
        if (family != null) family.Budget += target.Budget - source.Budget;
    }

    private static void ApplyCore(VM vm, ArchitectureState target, ArchitectureState source)
    {
        var architecture = vm.Context.Architecture;
        if (!ReferenceEquals(architecture, target.Architecture)) throw new InvalidOperationException("Lot architecture changed since the edit");
        var terrain = new VMArchitectureTerrain(architecture.Width, architecture.Height)
        {
            Heights = target.Heights.ToArray(),
            GrassState = target.Grass.ToArray(),
            LightType = target.LightType,
            DarkType = target.DarkType
        };
        terrain.RegenerateCenters();
        architecture.Load(new VMArchitectureMarshal
        {
            Width = architecture.Width,
            Height = architecture.Height,
            Stories = architecture.Stories,
            Terrain = terrain,
            Floors = target.Floors.Select(level => level.ToArray()).ToArray(),
            Walls = target.Walls.Select(level => level.ToArray()).ToArray(),
            FineBuildableArea = architecture.FineBuildableArea,
            RoofStyle = target.RoofStyle,
            RoofPitch = target.RoofPitch,
            BuildBuyEnabled = architecture.BuildBuyEnabled
        });
        architecture.SignalAllDirty();
        architecture.SignalTerrainRedraw();
        architecture.Tick();
    }
}
