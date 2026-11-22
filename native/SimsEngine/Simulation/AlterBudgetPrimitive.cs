namespace SimsEngine.Simulation;

public static class AlterBudgetPrimitive
{
    private const byte JustTest = 1;
    private const byte Negate = 2;
    private const byte MaximumExpenseType = 8;

    public static PrimitiveResult Execute(in TreeContext context, ReadOnlySpan<byte> operand)
    {
        var owner = Owner(operand[0], operand[1]);
        var data = (short)(operand[2] | operand[3] << 8);
        var flags = operand[4];
        var expenseType = operand[6];
        if (expenseType > MaximumExpenseType) throw new SimulationException(SimulationError.BadExpenseTypeSpecified);
        var value = Variables.Get(context, owner, data);
        var amount = (flags & Negate) != 0 ? -(int)value : value;
        var budget = context.World.RequireFamilyBudget();
        var funds = budget.ReadFamilyBudget();
        if (amount >= 0 && funds < amount) return PrimitiveResult.False;
        if ((flags & JustTest) == 0) budget.AlterFamilyBudget(expenseType, amount);
        return PrimitiveResult.True;
    }

    private static DataOwner Owner(byte scope, byte owner) => scope switch
    {
        0 => DataOwner.Literal,
        1 => DataOwner.Parameter,
        2 => DataOwner.Local,
        _ => (DataOwner)owner,
    };
}
