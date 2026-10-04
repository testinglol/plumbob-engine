using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Model;

internal static class NativeRelationships
{
    internal record Relationship(short NeighborID, uint GUID, string Name, short[] Values, bool Household, PanelResources.Image? Portrait, short ReverseDaily, bool Famous);

    internal static Relationship[] Read(VM vm, VMAvatar avatar, PanelResources images)
    {
        var neighborhood = Content.Get().Neighborhood;
        var neighbor = neighborhood.GetNeighborByID(avatar.GetPersonData(VMPersonDataVariable.NeighborId));
        if (neighbor == null) return [];
        return neighbor.Relationships.OrderBy(pair => pair.Key).Select(pair =>
        {
            var target = pair.Key is > 0 and <= short.MaxValue ? neighborhood.GetNeighborByID((short)pair.Key) : null;
            if (target == null || target.NeighbourID == neighbor.NeighbourID) return null;
            var definition = Content.Get().WorldObjects.Get(target.GUID);
            var name = definition?.Resource.Get<CTSS>(definition.OBJ.CatalogStringsID)?.GetString(0) ?? target.Name ?? "";
            return new Relationship(target.NeighbourID, target.GUID, name, pair.Value.ToArray(),
                vm.TS1State.CurrentFamily?.FamilyGUIDs.Contains(target.GUID) == true, images.NeighborPortrait(target.GUID),
                target.Relationships.GetValueOrDefault(neighbor.NeighbourID)?.FirstOrDefault() ?? 0,
                target.PersonData?.ElementAtOrDefault(81) != 0 && target.PersonData != null);
        }).Where(item => item != null).Cast<Relationship>().ToArray();
    }
}
