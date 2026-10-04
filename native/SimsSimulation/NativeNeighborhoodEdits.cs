using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics.Model;

/// <summary>
/// Neighborhood-screen edits applied by the one-shot export process: evict an occupied family back to the
/// Select a Family list, or delete an unhoused family. Both save Neighborhood.iff in the active profile only.
/// </summary>
internal static class NativeNeighborhoodEdits
{
    public static object Apply(string edit, string game)
    {
        var parts = edit.Split(':');
        if (parts.Length < 2 || !int.TryParse(parts[1], out var value))
            throw new ArgumentException("Neighborhood edits look like evict:HOUSE, delete:FAMILY, bulldoze:HOUSE or rezone:HOUSE:TYPE");
        return parts[0] switch
        {
            "rezone" when parts.Length == 3 && int.TryParse(parts[2], out var zoningType) => Rezone(value, zoningType, game),
            "evict" => Evict(value),
            "delete" => Delete(value),
            "bulldoze" => Bulldoze(value, game),
            _ => throw new ArgumentException("Unknown neighborhood edit")
        };
    }

    /// Evicts an occupied residential family, checks it reaches the picker list, then deletes it; the installed source is unchanged.
    public static object Check(string game)
    {
        var sourceUserData = Path.Combine(game, "UserData");
        var sourceHash = NativeHouseholdCreation.HashDirectory(sourceUserData);
        var neighborhood = Content.Get().Neighborhood;
        var house = neighborhood.ZoningDictionary
            .Where(pair => pair.Key > 0 && pair.Value == 0 && neighborhood.GetFamilyForHouse(pair.Key) != null)
            .Select(pair => (int)pair.Key).OrderBy(value => value).FirstOrDefault();
        if (house == 0) throw new InvalidOperationException("The installed neighborhood has no occupied residential lot to evict");
        var family = neighborhood.GetFamilyForHouse((short)house)!;
        var familyId = family.ChunkID;
        var members = family.FamilyGUIDs.ToArray();
        var vacantBefore = neighborhood.ZoningDictionary.Count(pair => pair.Value == 0 && neighborhood.GetFamilyForHouse(pair.Key) == null);
        Evict(house);
        var stillHoused = neighborhood.ZoningDictionary
            .Where(pair => pair.Key > 0 && pair.Value == 0 && pair.Key != house && neighborhood.GetFamilyForHouse(pair.Key) != null)
            .Select(pair => (int)pair.Key).OrderBy(value => value).FirstOrDefault();
        bool? housedBulldozeRejected = null;
        if (stillHoused != 0)
        {
            housedBulldozeRejected = false;
            try { Bulldoze(stillHoused, game); }
            catch (InvalidOperationException) { housedBulldozeRejected = true; }
            if (housedBulldozeRejected != true) throw new InvalidDataException("A housed lot was bulldozed");
        }
        if (neighborhood.GetFamilyForHouse((short)house) != null || family.HouseNumber != 0)
            throw new InvalidDataException("Eviction left the family on its lot");
        if (!NativeNeighborhoodExport.UnhousedFamilies().Any(choice => choice.Id == familyId))
            throw new InvalidDataException("An evicted family is missing from the Select a Family list");
        var rejectedOccupiedDelete = false;
        var other = neighborhood.FamilyForHouse.Values.FirstOrDefault(candidate => candidate.HouseNumber != 0);
        if (other != null)
        {
            try { Delete(other.ChunkID); }
            catch (InvalidOperationException) { rejectedOccupiedDelete = true; }
            if (!rejectedOccupiedDelete) throw new InvalidDataException("A housed family was deleted without being evicted");
        }
        Delete(familyId);
        if (neighborhood.GetFamily((ushort)familyId) != null || NativeNeighborhoodExport.UnhousedFamilies().Any(choice => choice.Id == familyId))
            throw new InvalidDataException("Deleting a family left its record behind");
        foreach (var guid in members)
        {
            var id = neighborhood.GetNeighborIDForGUID(guid);
            var person = id.HasValue ? neighborhood.GetNeighborByID(id.Value)?.PersonData : null;
            if (person != null && person[(int)VMPersonDataVariable.TS1FamilyNumber] != 0)
                throw new InvalidDataException("A deleted family's Sim still points at it");
        }
        Bulldoze(house, game);
        var profileHouse = Path.Combine(neighborhood.UserPath, "Houses", $"House{house:D2}.iff");
        if (!File.ReadAllBytes(profileHouse).SequenceEqual(File.ReadAllBytes(Path.Combine(game, "TemplateUserData", "Houses", "House00.iff"))))
            throw new InvalidDataException("Bulldozing did not reset the lot to the empty-lot template");
        // Rezoning needs an evicted, bulldozed lot and persists in the profile's zoning table.
        var originalZoning = neighborhood.ZoningDictionary[(short)house];
        Rezone(house, 1, game);
        var zoningLine = new FSO.Files.Formats.IFF.IffFile(Path.Combine(neighborhood.UserPath, "LotZoning.iff")).Get<STR>(1)!;
        if (neighborhood.ZoningDictionary[(short)house] != 1 || !Enumerable.Range(0, zoningLine.Length).Any(i => zoningLine.GetString(i).Replace(" ", "") == $"{house},community"))
            throw new InvalidDataException("Rezoning to community did not persist");
        Rezone(house, originalZoning, game);
        bool? housedRezoneRejected = null;
        if (stillHoused != 0)
        {
            housedRezoneRejected = false;
            try { Rezone(stillHoused, 1, game); }
            catch (InvalidOperationException) { housedRezoneRejected = true; }
            if (housedRezoneRejected != true) throw new InvalidDataException("A housed lot was rezoned");
        }
        var vacantAfter = neighborhood.ZoningDictionary.Count(pair => pair.Value == 0 && neighborhood.GetFamilyForHouse(pair.Key) == null);
        if (vacantAfter != vacantBefore + 1) throw new InvalidDataException("The evicted lot did not become vacant");
        if (!NativeHouseholdCreation.HashDirectory(sourceUserData).SequenceEqual(sourceHash))
            throw new InvalidDataException("Neighborhood edits modified the installed UserData");
        return new { result = "passed", house, evicted = familyId, deleted = true, housedDeleteRejected = other == null ? (bool?)null : rejectedOccupiedDelete, housedBulldozeRejected, bulldozedToEmptyLot = true, rezonedAndRestored = true, housedRezoneRejected, sourceUserDataUnchanged = true };
    }

    /// <summary>
    /// Resets a vacant residential lot's house file to the installed empty-lot template (TemplateUserData/Houses/House00.iff).
    /// The original game's bulldoze source is inferred: House00 has no floors or walls. The source install is only read.
    /// </summary>
    private static object Bulldoze(int house, string game)
    {
        var neighborhood = Content.Get().Neighborhood;
        if (!neighborhood.ZoningDictionary.ContainsKey((short)house)) throw new InvalidOperationException("The lot has no zoning record");
        if (neighborhood.GetFamilyForHouse((short)house) != null) throw new InvalidOperationException("Evict the family before bulldozing its house");
        var template = Path.Combine(game, "TemplateUserData", "Houses", "House00.iff");
        if (!File.Exists(template)) throw new FileNotFoundException("The installed game has no empty-lot template");
        var target = Path.Combine(neighborhood.UserPath, "Houses", $"House{house:D2}.iff");
        var temporary = target + ".tmp";
        try
        {
            File.Copy(template, temporary, true);
            File.Move(temporary, target, true);
        }
        finally { if (File.Exists(temporary)) File.Delete(temporary); }
        return new { bulldozed = house };
    }

    /// <summary>True when a lot's house file in the active profile is the empty-lot template.</summary>
    internal static bool IsBulldozed(string userPath, int house, string game)
    {
        var target = Path.Combine(userPath, "Houses", $"House{house:D2}.iff");
        var template = Path.Combine(game, "TemplateUserData", "Houses", "House00.iff");
        return File.Exists(target) && File.Exists(template) && new FileInfo(target).Length == new FileInfo(template).Length &&
               File.ReadAllBytes(target).SequenceEqual(File.ReadAllBytes(template));
    }

    /// <summary>
    /// Rewrites a lot's zoning (0 residential, 1 community) in the profile's LotZoning.iff. As in the original game the lot must
    /// have no family and must already be bulldozed (STR# 131 entries 7 and 9).
    /// </summary>
    private static object Rezone(int house, int type, string game)
    {
        if (type is not (0 or 1)) throw new ArgumentException("Zoning type must be 0 (residential) or 1 (community)");
        var neighborhood = Content.Get().Neighborhood;
        if (!neighborhood.ZoningDictionary.ContainsKey((short)house)) throw new InvalidOperationException("The lot has no zoning record");
        if (neighborhood.GetFamilyForHouse((short)house) != null) throw new InvalidOperationException("Evict the family before rezoning its lot");
        if (!IsBulldozed(neighborhood.UserPath, house, game)) throw new InvalidOperationException("Bulldoze the lot before rezoning it");
        var path = Path.Combine(neighborhood.UserPath, "LotZoning.iff");
        var file = new FSO.Files.Formats.IFF.IffFile(path);
        var zones = file.Get<STR>(1) ?? throw new InvalidDataException("LotZoning.iff has no zoning table");
        var index = Enumerable.Range(0, zones.Length).FirstOrDefault(i => zones.GetString(i).Split(',')[0].Trim() == house.ToString(), -1);
        if (index < 0) throw new InvalidOperationException("The lot is missing from the zoning table");
        zones.SetString(index, $"{house}, {(type == 1 ? "community" : "residential")}");
        var temporary = path + ".tmp";
        try
        {
            using (var stream = new FileStream(temporary, FileMode.Create, FileAccess.Write, FileShare.None)) file.Write(stream);
            File.Move(temporary, path, true);
        }
        finally { if (File.Exists(temporary)) File.Delete(temporary); }
        neighborhood.ZoningDictionary[(short)house] = (short)type;
        return new { rezoned = house, type };
    }

    internal static object Evict(int house)
    {
        var neighborhood = Content.Get().Neighborhood;
        if (!neighborhood.ZoningDictionary.TryGetValue((short)house, out var zoning) || zoning != 0)
            throw new InvalidOperationException("Only a residential lot can be evicted");
        var family = neighborhood.GetFamilyForHouse((short)house) ?? throw new InvalidOperationException("Nobody lives on this lot");
        neighborhood.MoveOut((short)house);
        neighborhood.SaveNeighbourhood(false);
        return new { evicted = family.ChunkID, house };
    }

    private static object Delete(int familyId)
    {
        var neighborhood = Content.Get().Neighborhood;
        var family = neighborhood.GetFamily((ushort)familyId) ?? throw new ArgumentException("The family does not exist");
        if (family.HouseNumber != 0) throw new InvalidOperationException("Evict a family before deleting it");
        foreach (var guid in family.FamilyGUIDs)
        {
            var id = neighborhood.GetNeighborIDForGUID(guid);
            var person = id.HasValue ? neighborhood.GetNeighborByID(id.Value)?.PersonData : null;
            if (person != null) person[(int)VMPersonDataVariable.TS1FamilyNumber] = 0;
        }
        foreach (var name in family.ChunkParent.List<FAMs>().Where(chunk => chunk.ChunkID == family.ChunkID).ToArray())
            family.ChunkParent.FullRemoveChunk(name);
        family.ChunkParent.FullRemoveChunk(family);
        neighborhood.SaveNeighbourhood(false);
        return new { deleted = familyId };
    }
}
