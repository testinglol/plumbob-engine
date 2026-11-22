namespace SimsEngine.Simulation;

public static class BreakpointPrimitive
{
    public static PrimitiveResult Execute(in TreeContext context, ReadOnlySpan<byte> operand)
    {
        var data = (short)(operand[0] | operand[1] << 8);
        var owner = (DataOwner)(short)(operand[2] | operand[3] << 8);
        if (Variables.Get(context, owner, data) != 0) throw new SimulationException(SimulationError.TreeBreakEncountered);
        return PrimitiveResult.True;
    }
}
