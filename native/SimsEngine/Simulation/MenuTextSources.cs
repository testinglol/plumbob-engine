namespace SimsEngine.Simulation;

public interface ISimulationMenuTextSources
{
    string? FamilyName(int familyNumber);

    int? FamilyAssets(int familyNumber);

    string? FameTitle(int level);
}
