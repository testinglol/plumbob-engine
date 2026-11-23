namespace SimsEngine.Simulation;

public static class GetDirectionToPrimitive
{
    private const short ObjectIdData = (short)ObjectData.ObjectId;

    public static PrimitiveResult Execute(in TreeContext context, ReadOnlySpan<byte> operand)
    {
        var output = Variables.Reference(context, (DataOwner)(short)(operand[2] | operand[3] << 8), (short)(operand[0] | operand[1] << 8));
        var byVariable = (operand[4] & 1) != 0;
        var targetId = byVariable
            ? Variables.Get(context, (DataOwner)operand[5], (short)(operand[6] | operand[7] << 8))
            : Variables.Get(context, DataOwner.My, ObjectIdData);
        var self = (context.World.ObjectTableEntry(targetId) ?? context.World.ObjectByStackObject(context.Me, targetId) ?? context.World.ObjectById(targetId))
            ?? throw new SimulationException(SimulationError.CouldNotFindObjectReference);
        var stackObject = context.World.ObjectByStackObject(context.Me, context.Frame.StackObject)
            ?? throw new SimulationException(SimulationError.NoStackObjectPresentWhenRequired);
        var direction = DirectionBetween(self.Position, stackObject.Position);
        var stored = unchecked((short)(direction + 8));
        if (!output.IsShort) throw new SimulationException(SimulationError.ExpressionAttemptingToWriteInAReadOnlyArea);
        output.Short = (short)(stored % 8);
        return PrimitiveResult.True;
    }

    // Returns 0=-Y, 2=+X, 4=+Y, 6=-X; identical positions yield 3 per Sims.exe.
    public static short DirectionBetween(ObjectPosition self, ObjectPosition other)
    {
        var dx = unchecked(other.X - self.X);
        var dy = unchecked(other.Y - self.Y);
        var absoluteX = unchecked(dx < 0 ? -dx : dx);
        var absoluteY = unchecked(dy < 0 ? -dy : dy);
        int result;
        if (unchecked(absoluteX * 2) < absoluteY) result = 4;
        else result = absoluteX <= unchecked(absoluteY * 2) ? 3 : 2;
        if (dx < 0) result = result switch { 2 => 6, 3 => 5, _ => result };
        if (dy < 0) result = result switch { 3 => 1, 4 => 0, 5 => 7, _ => result };
        return (short)result;
    }
}
