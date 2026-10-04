using FSO.SimAntics;
using FSO.SimAntics.Utils;
using FSO.Content;
using System;
using System.Linq;

internal static class NativeHouseStatus
{
    internal sealed record Snapshot(int ArchitectureValue, int FurnishingsValue, int BuildModeObjectValue, int TotalValue, int SizeRating, int? HouseholdMembers, int IndoorAreaSquareFeet);

    internal static object Read(VM vm)
    {
        var objectValues = VMArchitectureStats.GetObjectValue(vm);
        var architectureValue = VMArchitectureStats.GetArchValue(vm.Context.Architecture) + objectValues.Item2;
        var householdMembers = vm.TS1State.CurrentFamily?.FamilyGUIDs.Length;
        var indoorAreaSquareFeet = vm.Context.RoomInfo
            .Where(info => !info.Room.IsOutside && info.Room.Area > 0)
            .Sum(info => info.Room.Area) * 9;
        int sizeRating = 0;
        if (householdMembers.GetValueOrDefault() > 0)
        {
            var ratio = indoorAreaSquareFeet / (float)householdMembers.Value;
            sizeRating = (int)Content.Get().WorldObjectGlobals.HouseScore[0].GetPoint(ratio);
        }
        return new Snapshot(architectureValue, objectValues.Item1, objectValues.Item2,
            architectureValue + objectValues.Item1, sizeRating, householdMembers, indoorAreaSquareFeet);
    }
}
