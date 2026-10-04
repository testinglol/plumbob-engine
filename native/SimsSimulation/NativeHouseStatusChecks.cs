using FSO.Content;
using FSO.LotView.Model;
using FSO.SimAntics;
using FSO.SimAntics.Utils;

internal static class NativeHouseStatusChecks
{
    internal static object Run(VM vm)
    {
        var architecture = vm.Context.Architecture;
        short tileX = -1;
        short tileY = -1;
        sbyte level = 1;
        FloorTile original = default;
        for (sbyte story = 1; story <= architecture.Stories && tileX < 0; story++)
        for (short y = 0; y < architecture.Height && tileX < 0; y++)
        for (short x = 0; x < architecture.Width; x++)
        {
            if (architecture.OutsideClip(x, y, story)) continue;
            tileX = x;
            tileY = y;
            level = story;
            original = architecture.GetFloor(x, y, story);
            break;
        }
        if (tileX < 0) throw new Exception("No buildable tile is available for house valuation check");
        var pattern = Content.Get().WorldFloors.Entries.Values.FirstOrDefault(floor => floor.ID > 1 && floor.Price > 0 && floor.ID != original.Pattern);
        if (pattern == null) throw new Exception("No alternate priced floor pattern is available for house valuation check");

        try
        {
            var before = (NativeHouseStatus.Snapshot)NativeHouseStatus.Read(vm);
            var expectedArea = vm.Context.RoomInfo.Where(info => !info.Room.IsOutside && info.Room.Area > 0).Sum(info => info.Room.Area) * 9;
            var expectedMembers = vm.TS1State.CurrentFamily?.FamilyGUIDs.Length;
            var expectedSize = expectedMembers.GetValueOrDefault() > 0
                ? (int)Content.Get().WorldObjectGlobals.HouseScore[0].GetPoint(expectedArea / (float)expectedMembers.Value)
                : 0;
            if (before.IndoorAreaSquareFeet != expectedArea || before.HouseholdMembers != expectedMembers || before.SizeRating != expectedSize)
                throw new Exception("House size status did not match the canonical room and household data");
            if (!architecture.SetFloor(tileX, tileY, level, new FloorTile { Pattern = (ushort)pattern.ID }, true))
                throw new Exception("Could not apply temporary floor for house valuation check");
            var after = (NativeHouseStatus.Snapshot)NativeHouseStatus.Read(vm);
            var delta = pattern.Price - (original.Pattern == 1 ? 0 : Content.Get().WorldFloors.Entries.GetValueOrDefault(original.Pattern)?.Price ?? 0);
            if (after.ArchitectureValue - before.ArchitectureValue != delta || after.TotalValue - before.TotalValue != delta)
                throw new Exception("House valuation did not track the engine floor pattern price");
            return new { before, after, expectedDelta = delta };
        }
        finally
        {
            architecture.SetFloor(tileX, tileY, level, original, true);
        }
    }
}
