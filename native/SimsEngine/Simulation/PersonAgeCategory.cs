namespace SimsEngine.Simulation;

public static class PersonAgeCategory
{
    public static bool IsChild(short age) => age != 0 && age < 18;
    public static bool IsAdult(short age) => age == 0 || age >= 18;
}
