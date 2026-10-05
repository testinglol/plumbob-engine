using FSO.SimAntics.Marshals;
using FSO.SimAntics.Marshals.Threads;
using FSO.SimAntics.Model.Platform;

/// <summary>
/// Removes the objects of uninstalled packs from a simulation snapshot before it loads. An object whose definition no
/// longer resolves is removed with the rest of its multi-tile group and everything it holds; each removed group is refunded
/// at its depreciated value, as if sold. Threads that ran code from a removed definition or referenced a removed object
/// are cleared so the engine never resolves a missing definition, and are reset once the snapshot has loaded.
/// Sims are never removed with their container; they are detached instead.
/// </summary>
internal static class NativePackRemoval
{
    internal sealed record RemovedObject(uint Guid, short ObjectId, string Name, int Refund);

    internal sealed record Report(RemovedObject[] Objects, short[] ResetEntities, int Refund)
    {
        public bool Changed => Objects.Length > 0 || ResetEntities.Length > 0;
    }

    /// <summary>
    /// Points saved instances of replaced objects at their new definitions, keeping their state and position. Their threads
    /// still name the old definition and are reset by <see cref="Strip"/>, which must run afterwards with the old GUIDs undefined.
    /// </summary>
    public static (uint From, uint To, short ObjectId)[] Remap(VMMarshal marshal, IReadOnlyDictionary<uint, uint> objects)
    {
        if (objects.Count == 0) return [];
        var remapped = new List<(uint, uint, short)>();
        foreach (var entity in marshal.Entities)
        {
            if (entity is VMAvatarMarshal) continue;
            if (objects.TryGetValue(entity.MasterGUID, out var master)) entity.MasterGUID = master;
            if (!objects.TryGetValue(entity.GUID, out var target)) continue;
            remapped.Add((entity.GUID, target, entity.ObjectID));
            entity.GUID = target;
        }
        return remapped.ToArray();
    }

    public static Report Strip(VMMarshal marshal, Func<uint, bool> defined)
    {
        if (marshal.Entities.Length != marshal.Threads.Length) throw new InvalidDataException("Simulation snapshot threads do not match its objects");
        var byId = new Dictionary<short, int>();
        for (var index = 0; index < marshal.Entities.Length; index++) byId[marshal.Entities[index].ObjectID] = index;
        var groupOf = new Dictionary<short, VMMultitileGroupMarshal>();
        foreach (var group in marshal.MultitileGroups)
            foreach (var id in group.Objects ?? []) groupOf.TryAdd(id, group);

        var removed = new HashSet<short>();
        var pending = new Stack<short>(marshal.Entities.Where(entity => !defined(entity.GUID)).Select(entity => entity.ObjectID));
        while (pending.Count > 0)
        {
            var id = pending.Pop();
            if (!byId.TryGetValue(id, out var index) || !removed.Add(id)) continue;
            var entity = marshal.Entities[index];
            if (groupOf.TryGetValue(id, out var group))
                foreach (var member in group.Objects) if (!removed.Contains(member)) pending.Push(member);
            foreach (var held in entity.Contained ?? [])
            {
                if (held == 0 || !byId.TryGetValue(held, out var heldIndex)) continue;
                if (marshal.Entities[heldIndex] is VMAvatarMarshal) marshal.Entities[heldIndex].Container = 0;
                else pending.Push(held);
            }
        }
        // A Sim is only removed when its own definition is missing; one swept up as a held object is detached above.
        removed.RemoveWhere(id => marshal.Entities[byId[id]] is VMAvatarMarshal && defined(marshal.Entities[byId[id]].GUID));
        if (removed.Count == 0 && !marshal.Threads.Any(thread => References(thread, removed, defined)))
            return new Report([], [], 0);

        var objects = new List<RemovedObject>();
        var keptGroups = new List<VMMultitileGroupMarshal>();
        foreach (var group in marshal.MultitileGroups)
        {
            var members = group.Objects ?? [];
            if (!members.Any(removed.Contains)) { keptGroups.Add(group); continue; }
            var refund = Value(group, members.Where(byId.ContainsKey).Select(id => marshal.Entities[byId[id]]).FirstOrDefault());
            var first = true;
            foreach (var id in members.Where(removed.Contains))
            {
                objects.Add(new RemovedObject(marshal.Entities[byId[id]].GUID, id, group.Name ?? "", first ? refund : 0));
                first = false;
            }
        }
        foreach (var id in removed.Where(id => !groupOf.ContainsKey(id)))
            objects.Add(new RemovedObject(marshal.Entities[byId[id]].GUID, id, "", 0));

        var entities = new List<VMEntityMarshal>();
        var threads = new List<VMThreadMarshal>();
        var reset = new List<short>();
        for (var index = 0; index < marshal.Entities.Length; index++)
        {
            var entity = marshal.Entities[index];
            if (removed.Contains(entity.ObjectID)) continue;
            if (entity.Contained != null)
                entity.Contained = entity.Contained.Select(held => removed.Contains(held) ? (short)0 : held).ToArray();
            if (removed.Contains(entity.Container)) { entity.Container = 0; entity.ContainerSlot = -1; }
            var thread = marshal.Threads[index];
            if (References(thread, removed, defined))
            {
                thread.Stack = [];
                thread.Queue = [];
                thread.ActiveQueueBlock = -1;
                thread.BlockingState = null;
                thread.EODConnection = null;
                thread.Interrupt = false;
                reset.Add(entity.ObjectID);
            }
            entities.Add(entity);
            threads.Add(thread);
        }
        marshal.Entities = entities.ToArray();
        marshal.Threads = threads.ToArray();
        marshal.MultitileGroups = keptGroups.ToArray();
        return new Report(objects.OrderBy(item => item.ObjectId).ToArray(), reset.ToArray(), objects.Sum(item => item.Refund));
    }

    /// <summary>The sale value the engine gives a group: its purchase price less wear, never more than it cost.</summary>
    private static int Value(VMMultitileGroupMarshal group, VMEntityMarshal? baseObject)
    {
        var wear = (baseObject?.PlatformState as VMIObjectState)?.Wear ?? 20 * 4;
        return Math.Max(0, Math.Min(group.Price, (int)((long)group.Price * (400 - wear) / 400)));
    }

    private static bool References(VMThreadMarshal thread, HashSet<short> removed, Func<uint, bool> defined)
    {
        foreach (var frame in thread.Stack ?? [])
            if (!defined(frame.CodeOwnerGUID) || removed.Contains(frame.Caller) || removed.Contains(frame.Callee) || removed.Contains(frame.StackObject)) return true;
        foreach (var action in thread.Queue ?? [])
            if (!defined(action.CodeOwnerGUID) || removed.Contains(action.Callee) || removed.Contains(action.StackObject) || removed.Contains(action.IconOwner)) return true;
        return false;
    }
}
