namespace SimsEngine.Simulation;

public interface INeighborhoodFamilies
{
    bool HasMember(short familyNumber, int guid);

    short ActiveFamilyNumber { get; }

    bool Exists(short familyNumber);

    void AddMember(short familyNumber, int guid);

    void RemoveMember(short familyNumber, int guid);

    short HouseNumberForMember(int guid) => 0;

    int HouseNumber(short familyNumber) => 0;

    uint Flags(short familyNumber) => 0;

    IReadOnlyList<int> MemberGuids(short familyNumber) => [];
}
