namespace SimsEngine.Simulation;

public interface IFamilyBudget
{
    int ReadFamilyBudget();

    void AlterFamilyBudget(int expenseType, int amount);

    void AdvanceBudgetDay() { }
}
