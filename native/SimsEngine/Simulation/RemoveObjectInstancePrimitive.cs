using SimsEngine.Formats;

namespace SimsEngine.Simulation;

public static class RemoveObjectInstancePrimitive
{
    private const uint PendingRemovalFlag = 0x1000;

    public static PrimitiveResult Execute(in TreeContext context, ReadOnlySpan<byte> operand)
    {
        var selector = (short)(operand[0] | operand[1] << 8);
        var flags = operand[2];
        var id = selector switch
        {
            0 => context.Me.Id,
            1 => context.Frame.StackObject,
            2 => (short)0,
            _ => throw new SimulationException(SimulationError.IllegalOwnerFieldInDataReference),
        };
        var world = context.World;
        var runningObjectId = context.Me.Id;
        var item = world.ObjectById(id);
        if (world.CaptureExecutionTrace && item is not null)
            world.ObjectRemovalTrace.Add(new ObjectRemovalDiagnostic(context.Me.Id, id, item.Id, world.CurrentExecutionLocation));
        if (item is null) return PrimitiveResult.False;
        var selected = item;

        if (item.Definition[(int)ObjdField.MasterId] != 0 && !SimulationWorld.HasFunction(item, 8))
        {
            if (item.MultiTileMasterId != 0 && world.ObjectById(item.MultiTileMasterId) is { } master)
                item = master;
        }

        var groupAlreadyPending = world.RemovalGroupParents(item).Any(member => world.PendingRemovals.Contains(member.Id));
        if (!groupAlreadyPending && !world.PendingRemovals.Contains(item.Id))
        {
            if (ReferenceEquals(item, selected) && SimulationWorld.HasFunction(selected, 8))
                world.BeginObjectRemoval(item, 1);
            else
                foreach (var member in world.MultiTileMembers(item))
                    world.BeginObjectRemoval(member, 1);
            item.Flags &= ~PendingRemovalFlag;
            if ((flags & 2) != 0) item.Flags |= PendingRemovalFlag;
            world.PendingRemovals.Add(item.Id);
        }
        if (selected is XPerson person) world.SavePersonRecord(person);
        return Result();

        PrimitiveResult Result() => id == runningObjectId && world.SelfRemovalEndsRun && (flags & 1) == 0
            ? PrimitiveResult.Stop
            : PrimitiveResult.True;
    }
}
