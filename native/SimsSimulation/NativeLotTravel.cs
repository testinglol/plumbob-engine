using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.NetPlay.Model.Commands;

internal sealed class NativeLotTravel
{
    internal record Item(int Type, uint GUID, ushort Count);
    internal record Inventory(short Neighbor, Item[] Items);
    internal record Family(ushort ID, string State);
    internal record Snapshot(short HomeHouse, string? HomeState, uint SimGUID, short TransitInfo, uint[] Members, Inventory[] Inventories, Family? ActiveFamily = null, string? Neighbors = null, short[]? NeighborhoodData = null, NativeNeighborhoodState.TypeAttribute[]? TypeAttributes = null);
    private readonly short homeHouse;
    private readonly string userData;
    private VMMarshal? homeState;
    private short? pending;
    internal short House { get; private set; }
    internal bool Away => homeState != null;
    internal bool Pending => pending != null;

    internal NativeLotTravel(string userData, short house) { this.userData = userData; homeHouse = House = house; }

    internal void Request(VM vm, uint destination)
    {
        var target = unchecked((short)destination);
        if (target == -1) target = homeHouse;
        if (target == House) return;
        if (target < 1 || target > 99 || !File.Exists(Path.Combine(userData, "Houses", $"House{target:D2}.iff")))
            throw new InvalidDataException("Requested travel lot is unavailable");
        if (target != homeHouse && target < 21) throw new InvalidDataException("Travel cannot activate another residential household");
        if (target != homeHouse && target is >= 50 and <= 80 &&
            Content.Get().Neighborhood.ZoningDictionary.GetValueOrDefault(target) != 1)
            throw new InvalidDataException("Travel requires a community-zoned Old Town lot");
        if (pending != null) throw new InvalidOperationException("A lot transition is already pending");
        pending = target;
        vm.SpeedMultiplier = 0;
    }

    internal VM Apply(VM current)
    {
        if (pending is not short target) return current;
        var family = current.TS1State.CurrentFamily ?? Content.Get().Neighborhood.GameState.ActiveFamily
            ?? throw new InvalidOperationException("Travel requires an active family");
        VM candidate;
        if (target == homeHouse)
        {
            if (homeState == null) throw new InvalidOperationException("No suspended home lot exists");
            candidate = SimulationServer.CreateVM();
            candidate.TS1State.CurrentFamily = family;
            candidate.Load(homeState);
            family.SelectWholeFamily();
            candidate.TS1State.ActivateFamily(candidate, family);
        }
        else
        {
            candidate = SimulationServer.LoadHouse(userData, target, false);
            var neighborhood = Content.Get().Neighborhood;
            var neighbor = neighborhood.GetNeighborIDForGUID(neighborhood.GameState.DowntownSimGUID);
            var inventory = neighbor.HasValue ? neighborhood.GetInventoryByNID(neighbor.Value) : null;
            var hour = inventory?.FirstOrDefault(item => item.Type == 2 && item.GUID == 7)?.Count ?? 0;
            var minute = inventory?.FirstOrDefault(item => item.Type == 2 && item.GUID == 8)?.Count ?? 0;
            new VMNetSetTimeCmd { Hours = hour % 24, Minutes = minute % 60 }.Execute(candidate);
        }
        if (!Away && target != homeHouse) homeState = Decode(Encode(current.Save()));
        if (target == homeHouse) homeState = null;
        pending = null;
        House = target;
        candidate.SpeedMultiplier = 1;
        return candidate;
    }

    internal Snapshot Save(VM vm)
    {
        var neighborhood = Content.Get().Neighborhood;
        var family = vm.TS1State.CurrentFamily ?? neighborhood.GameState.ActiveFamily;
        using var familyData = new MemoryStream();
        family?.Write(null, familyData);
        return new Snapshot(homeHouse, homeState == null ? null : Encode(homeState), neighborhood.GameState.DowntownSimGUID,
            neighborhood.GameState.LotTransitInfo, family?.RuntimeSubset?.ToArray() ?? [],
            neighborhood.Neighborhood.InventoryByID.OrderBy(pair => pair.Key).Select(pair => new Inventory(pair.Key,
                pair.Value.Select(item => new Item(item.Type, item.GUID, item.Count)).ToArray())).ToArray(),
            family == null ? null : new Family(family.ChunkID, Convert.ToBase64String(familyData.ToArray())), NativeNeighborhoodState.Save(),
            neighborhood.Neighborhood.NeighborhoodData.ToArray(), NativeNeighborhoodState.SaveTypeAttributes());
    }

    internal void Validate(Snapshot? snapshot, short house)
    {
        NativeNeighborhoodState.ValidateTypeAttributes(snapshot?.TypeAttributes);
        if (snapshot == null)
        {
            if (house != homeHouse) throw new InvalidDataException("Legacy save belongs to another home lot");
            return;
        }
        if (snapshot.HomeHouse != homeHouse || (snapshot.HomeState != null) != (house != homeHouse) || house is < 1 or > 99 ||
            snapshot.Members == null || snapshot.Members.Length > 8 || snapshot.Inventories == null || snapshot.Inventories.Length > 32768 ||
            snapshot.Inventories.Any(entry => entry.Items == null || entry.Items.Length > 10000) ||
            snapshot.Inventories.Select(entry => entry.Neighbor).Distinct().Count() != snapshot.Inventories.Length)
            throw new InvalidDataException("Invalid travel save state");
        if (snapshot.HomeState != null) _ = Decode(snapshot.HomeState);
        if (snapshot.ActiveFamily != null) _ = DecodeFamily(snapshot.ActiveFamily);
        if (snapshot.Neighbors != null) _ = NativeNeighborhoodState.Decode(snapshot.Neighbors);
        if (snapshot.NeighborhoodData != null && snapshot.NeighborhoodData.Length != 16)
            throw new InvalidDataException("Invalid neighborhood variable snapshot");
    }

    internal void Restore(Snapshot? snapshot, short house, VM vm)
    {
        Validate(snapshot, house);
        pending = null;
        House = house;
        homeState = snapshot?.HomeState == null ? null : Decode(snapshot.HomeState);
        var neighborhood = Content.Get().Neighborhood;
        neighborhood.GameState.ActiveFamily = vm.TS1State.CurrentFamily ?? (snapshot?.ActiveFamily == null ? null : DecodeFamily(snapshot.ActiveFamily));
        neighborhood.GameState.DowntownSimGUID = snapshot?.SimGUID ?? 0;
        neighborhood.GameState.LotTransitInfo = snapshot?.TransitInfo ?? 0;
        if (snapshot == null) return;
        if (snapshot.Neighbors != null) NativeNeighborhoodState.Restore(snapshot.Neighbors);
        if (snapshot.NeighborhoodData != null) neighborhood.Neighborhood.NeighborhoodData = snapshot.NeighborhoodData.ToArray();
        NativeNeighborhoodState.RestoreTypeAttributes(snapshot.TypeAttributes);
        if (neighborhood.GameState.ActiveFamily != null) neighborhood.GameState.ActiveFamily.RuntimeSubset = snapshot.Members.ToArray();
        neighborhood.Neighborhood.InventoryByID = snapshot.Inventories.ToDictionary(entry => entry.Neighbor,
            entry => entry.Items.Select(item => new InventoryItem { Type = item.Type, GUID = item.GUID, Count = item.Count }).ToList());
    }

    internal static string Encode(VMMarshal marshal)
    {
        using var data = new MemoryStream();
        using (var writer = new BinaryWriter(data, System.Text.Encoding.UTF8, true)) marshal.SerializeInto(writer);
        return Convert.ToBase64String(data.ToArray());
    }

    private static FAMI DecodeFamily(Family family)
    {
        using var data = new MemoryStream(Convert.FromBase64String(family.State));
        var result = new FAMI { ChunkID = family.ID, ChunkType = "FAMI", ChunkLabel = "" };
        result.Read(null, data);
        if (result.FamilyGUIDs.Length > 8) throw new InvalidDataException("Travel save exceeds household size");
        return result;
    }

    internal static VMMarshal Decode(string state)
    {
        using var data = new MemoryStream(Convert.FromBase64String(state));
        using var reader = new BinaryReader(data);
        if (data.Length < 9 || new string(reader.ReadChars(4)) != "FSOv") throw new InvalidDataException("Invalid simulation snapshot");
        data.Position = 0;
        var marshal = new VMMarshal();
        marshal.Deserialize(reader);
        return marshal;
    }
}
