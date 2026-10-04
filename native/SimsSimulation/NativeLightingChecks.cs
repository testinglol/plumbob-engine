using System.Text.Json;
using FSO.SimAntics;
using FSO.SimAntics.Model;

internal static class NativeLightingChecks
{
    internal static object Run(VM vm, string workspace, short house)
    {
        var directory = Path.Combine(workspace, "analysis", "lighting-check", Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(directory);
        var clock = vm.Context.Clock;
        var hours = clock.Hours;
        var minutes = clock.Minutes;
        var fractions = clock.MinuteFractions;
        var lamp = vm.Entities.OfType<VMGameObject>().First(entity => entity.Position.Level > 0 &&
            (entity.Object.OBJ.FunctionFlags & 16) != 0 && !vm.Context.RoomInfo[vm.Context.GetObjectRoom(entity)].Room.IsOutside);
        var contribution = lamp.GetValue(VMStackObjectVariable.LightingContribution);
        var room = vm.Context.GetObjectRoom(lamp);
        var snapshots = new List<object>();
        try
        {
            foreach (var hour in new[] { 12, 0 })
            foreach (var value in new short[] { 0, 100 })
            {
                clock.Hours = hour;
                clock.Minutes = 0;
                clock.MinuteFractions = 0;
                lamp.SetValue(VMStackObjectVariable.LightingContribution, value);
                vm.Context.RefreshAllLighting();
                var lighting = NativeRoomLighting.Read(vm);
                var exporter = new LotSceneExporter(vm, directory);
                var scene = exporter.Snapshot(house, 0, true, snapshots.Count + 1);
                var animation = Path.Combine(directory, $"animation-{hour}-{value}.json");
                File.WriteAllText(animation, JsonSerializer.Serialize(exporter.Animation(snapshots.Count + 1, 1, 0),
                    new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
                snapshots.Add(new { hour, contribution = value, scene, animation, lighting });
            }
            clock.Hours = 0;
            lamp.SetValue(VMStackObjectVariable.LightingContribution, 0);
            vm.Context.RefreshAllLighting();
            var off = NativeRoomLighting.Read(vm);
            lamp.SetValue(VMStackObjectVariable.LightingContribution, 100);
            vm.Context.RefreshAllLighting();
            var on = NativeRoomLighting.Read(vm);
            if (on.Rooms[room].Ambient <= off.Rooms[room].Ambient ||
                on.Rooms[room].R + on.Rooms[room].G + on.Rooms[room].B <= off.Rooms[room].R + off.Rooms[room].G + off.Rooms[room].B)
                throw new Exception("Original lamp contribution did not brighten its room");
            if (on.Outside != off.Outside || on.Rooms[1] != off.Rooms[1]) throw new Exception("Indoor lamp changed outside lighting");
            return new { lamp = lamp.ObjectID, room, snapshots, livePresentationVerified = false };
        }
        finally
        {
            clock.Hours = hours;
            clock.Minutes = minutes;
            clock.MinuteFractions = fractions;
            lamp.SetValue(VMStackObjectVariable.LightingContribution, contribution);
            vm.Context.RefreshAllLighting();
        }
    }
}
