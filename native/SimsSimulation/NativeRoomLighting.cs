using FSO.Common.Rendering;
using FSO.LotView.Model;
using FSO.SimAntics;
using Microsoft.Xna.Framework;

internal static class NativeRoomLighting
{
    internal record RGB(byte R, byte G, byte B);
    internal record Room(int ID, bool Outside, ushort Ambient, ushort Daylight, byte R, byte G, byte B);
    internal record State(RGB Outside, Room[] Rooms);

    internal static State Read(VM vm)
    {
        vm.Context.ProcessLightingChanges();
        var clock = vm.Context.Clock;
        var time = (clock.Hours * 3600.0 + clock.Minutes * 60.0 + clock.Seconds) / 86400.0;
        var outside = TimeOfDayConfig.ColorFromTime(time % 1);
        var multiplier = vm.Tuning?.GetTuning("special", 0, 2) ?? 175 / 400f;
        var factor = 1f - ((outside.R + outside.G + outside.B) - 115) / 1024f;
        var minimum = new Color(outside.ToVector4() * multiplier * factor * new Vector4(0.8f, 0.8f, 1f, 0.87f));
        minimum.R = Math.Max((byte)1, minimum.R);
        minimum.G = Math.Max((byte)1, minimum.G);
        minimum.B = Math.Max((byte)1, minimum.B);
        var infos = vm.Context.RoomInfo;
        var rooms = Enumerable.Range(0, infos.Length).Select(index => {
            var info = infos[index];
            var light = infos[info.Room.LightBaseRoom].Light ?? new RoomLighting();
            var color = Blueprint.RoomColor(light, outside, minimum);
            return new Room(index, info.Room.IsOutside, light.AmbientLight, light.OutsideLight, color.R, color.G, color.B);
        }).ToArray();
        return new State(new RGB(outside.R, outside.G, outside.B), rooms);
    }
}
