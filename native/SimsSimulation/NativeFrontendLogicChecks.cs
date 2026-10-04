using FSO.Content.TS1;
using FSO.Files.Formats.IFF.Chunks;

/// <summary>
/// Checks that need no game data: the original family-friend recount rules (0x00427c21) on synthetic neighbors and
/// the numbered-neighborhood folder rules (0x0042a53a).
/// </summary>
internal static class NativeFrontendLogicChecks
{
    public static object Run()
    {
        var checks = new List<string>();
        void Require(bool condition, string name)
        {
            if (!condition) throw new InvalidDataException("Frontend logic check failed: " + name);
            checks.Add(name);
        }

        static Neighbour Sim(short id, uint guid, short family, short gender = 0)
        {
            var data = new short[88];
            data[61] = family;
            data[65] = gender;
            return new Neighbour { NeighbourID = id, GUID = guid, PersonData = data, Relationships = new Dictionary<int, List<short>>() };
        }
        static void Relate(Neighbour from, Neighbour to, short daily) => from.Relationships[to.NeighbourID] = [daily, 0];

        var mom = Sim(1, 100, 7);
        var kid = Sim(2, 101, 7);
        var mutual = Sim(3, 200, 8);
        var oneSided = Sim(4, 201, 8);
        var belowThreshold = Sim(5, 202, 8);
        var noFamily = Sim(6, 203, 0);
        var pet = Sim(7, 204, 8, gender: 2);
        var friendOfBoth = Sim(8, 205, 9);
        var noData = new Neighbour { NeighbourID = 9, GUID = 206, Relationships = new Dictionary<int, List<short>>() };
        Relate(mom, mutual, 30); Relate(mutual, mom, 25);
        Relate(mom, oneSided, 90);
        Relate(kid, belowThreshold, 40); Relate(belowThreshold, kid, 24);
        Relate(mom, noFamily, 90); Relate(noFamily, mom, 90);
        Relate(kid, pet, 90); Relate(pet, kid, 90);
        Relate(mom, friendOfBoth, 50); Relate(friendOfBoth, mom, 50);
        Relate(kid, friendOfBoth, 50); Relate(friendOfBoth, kid, 50);
        Relate(mom, kid, 100); Relate(kid, mom, 100);
        var everyone = new[] { mom, kid, mutual, oneSided, belowThreshold, noFamily, pet, friendOfBoth, noData };
        uint[] family = [100, 101];

        Require(TS1NeighborhoodProvider.CountFamilyFriends(everyone, family) == 2, "mutual friends at threshold 25 count once each");
        Require(TS1NeighborhoodProvider.CountFamilyFriends(everyone, family, 26) == 1, "threshold is inclusive and both directions must reach it");
        Require(TS1NeighborhoodProvider.CountFamilyFriends(everyone, family, 51) == 0, "no friends above every daily value");
        Require(TS1NeighborhoodProvider.CountFamilyFriends(everyone, [], 25) == 0, "an empty family has no friends");
        Require(TS1NeighborhoodProvider.CountFamilyFriends(everyone, [100]) == 3, "one member's friendships are enough, and a relative outside the family counts");
        Require(TS1NeighborhoodProvider.CountFamilyFriends(everyone, [101]) == 2, "the other member counts only its own mutual friends; pets and one-sided ties do not count");

        Require(NativeNeighborhoods.Number("UserData") == 1, "UserData is neighborhood 1");
        Require(NativeNeighborhoods.Number("userdata7") == 7, "folder names are case-insensitive");
        Require(NativeNeighborhoods.Number("UserData1") == null && NativeNeighborhoods.Number("UserData100") == null &&
                NativeNeighborhoods.Number("UserData2b") == null && NativeNeighborhoods.Number("UserData Import") == null,
            "only UserData and UserData2–99 are neighborhoods");
        Require(NativeNeighborhoods.DirectoryName(1) == "UserData" && NativeNeighborhoods.DirectoryName(12) == "UserData12", "folder names round-trip");

        var profile = Path.Combine(Path.GetTempPath(), "sims-native-neighborhoods-" + Guid.NewGuid().ToString("N"));
        try
        {
            foreach (var folder in new[] { "UserData", "UserData3", "UserData10", "UserData2" })
            {
                Directory.CreateDirectory(Path.Combine(profile, folder));
                if (folder != "UserData2") File.WriteAllBytes(Path.Combine(profile, folder, "Neighborhood.iff"), []);
            }
            Directory.CreateDirectory(Path.Combine(profile, "Saves"));
            Require(NativeNeighborhoods.Installed(profile).SequenceEqual([1, 3, 10]),
                "installed neighborhoods are numeric-sorted and need Neighborhood.iff");
        }
        finally
        {
            if (Directory.Exists(profile)) Directory.Delete(profile, true);
        }

        return new { result = "passed", checks };
    }
}
