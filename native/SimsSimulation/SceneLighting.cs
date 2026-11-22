using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsSimulation;

internal static class SceneLighting
{
    internal record RGB(byte R, byte G, byte B);
    internal record Room(int Id, bool Outside, int Ambient, int Daylight, byte R, byte G, byte B);
    internal record State(RGB Outside, Room[] Rooms, RGB Backdrop, int Minutes, int Phase, Light[]? Lights = null,
        Window[]? Windows = null);
    internal record Light(float X, float Y, float Toward, int Strength, int Level, bool Fire = false);
    internal record Window(int X, int Y, int Level);

    internal enum FireLightKind
    {
        None = 0,
        Flame,
        Fireplace,
        Campfire,
        Torch,
        Candle,
    }

    private const uint CampfireGuid = 0xF0D9AE7Fu;

    private static readonly HashSet<uint> FireplaceGuids =
    [
        0x497A0C3Eu, 0x9D1A7773u, 0xD0814063u, // Fireplace - Cheap (+ Left, Right)
        0x8EAA68ADu, 0xD2C4735Cu, 0x34794586u, // Fireplace - Moderate (+ Left, Right)
        0x5D6B538Au, 0x72E724C8u, 0xAB2B356Cu, // Fireplace - Expensive (+ Left, Right)
        0xB5215809u, 0xB50A1003u, 0xB50B409Eu, // Fireplace - Very Expensive (+ Left, Right)
        0x3DEF46A0u, 0x14F36BBDu, 0x70C0617Cu, // Fireplace - Souvenir (+ Left, Right)
        0x3DEA8B15u, 0x3D9989D7u, 0xED2597B5u, 0x3D99C1DDu, // Fireplace - Lodge (+ Left, Middle, Right)
    ];

    private static readonly HashSet<uint> TorchGuids =
    [
        0xDA746262u, // Lamp - Floor - Animated - Tiki Torch
        0xA4E75CFFu, // Lamp - Floor - Animated - Torch
        0x00E22E1Eu, // Lamp - Sconce - Torch (Castle 1)
    ];

    private static readonly HashSet<uint> CandleGuids =
    [
        0xDA6132FFu, // Lamp - Floor - Animated - Candelabra
        0x19057C09u, // Lamp - Floor - Candle
        0xE1577BE5u, // Lamp - Wall - Candle
        0x98A0A6D6u, // Lamp - Table - Candle Dive Bar
        0xEA50C82Fu, // Lamp - Unleashed - Candle - Large
        0x4E665BF5u, // Lamp - Unleashed - Candle - Skull
        0xE53B581Au, // Lamp - Unleashed - Candle - Gold
        0x0C0D4574u, // Lamp - Unleashed - Candle - Black
        0xEE3F527Du, // Lamp - Table - Candle AOL
        0x3DBFC043u, // Menorah
        0xF9CA6B20u, // Jack-O-Lantern
    ];

    public static uint ObjectGuid(XObject item)
    {
        if (item.TypeRecord is { Key: not 0 } typeRecord)
            return unchecked((uint)typeRecord.Key);
        if (item.Definition.Length > (int)ObjdField.Guid2)
            return (uint)unchecked((ushort)item.Definition[(int)ObjdField.Guid1]) |
                   ((uint)unchecked((ushort)item.Definition[(int)ObjdField.Guid2]) << 16);
        return 0u;
    }

    public static FireLightKind FireKind(XObject item)
    {
        var guid = ObjectGuid(item);
        if (guid == unchecked((uint)BurnPrimitive.FireType))
            return FireLightKind.Flame;
        if ((item.Definition.Length > (int)ObjdField.BuildModeType &&
             item.Definition[(int)ObjdField.BuildModeType] == 5) ||
            item.TypeRecord?.AutonomyAlternativeTypeFlag == 5 ||
            FireplaceGuids.Contains(guid))
        {
            return FireLightKind.Fireplace;
        }
        if (guid == CampfireGuid)
            return FireLightKind.Campfire;
        if (TorchGuids.Contains(guid))
            return FireLightKind.Torch;
        if (CandleGuids.Contains(guid))
            return FireLightKind.Candle;
        return FireLightKind.None;
    }

    public static bool IsLightSource(XObject item)
    {
        if (item is XPerson || item[ObjectData.Hidden] != 0 || item.RoomWord84 < 0 || !InsideLot(item))
            return false;
        var kind = FireKind(item);
        if (kind == FireLightKind.Flame)
            return true;
        if (kind == FireLightKind.Campfire && item.Attributes.Length >= 2 &&
            (item.Attributes[0] != 1 || item.Attributes[1] <= 0 || item.Attributes[1] >= 6))
        {
            return false;
        }
        return (item[ObjectData.FlagField2] & 0x400) != 0 &&
               item[ObjectData.LightingContribution0100] != 0 &&
               item[ObjectData.LightSource] == 1;
    }

    public static int LightStrength(XObject item, FireLightKind kind)
    {
        var raw = (int)item[ObjectData.LightingContribution0100];
        return kind switch
        {
            FireLightKind.Flame => Math.Max(raw, 95),
            FireLightKind.Campfire => Math.Max(raw, 95),
            FireLightKind.Fireplace => Math.Max(raw, 85),
            FireLightKind.Torch => Math.Max(raw, 52),
            FireLightKind.Candle => Math.Clamp(Math.Max(raw, 28), 28, 44),
            _ => raw,
        };
    }

    public static float LightLiftFor(FireLightKind kind) => kind switch
    {
        FireLightKind.Flame => 0.85f,
        FireLightKind.Fireplace => 0.68f,
        FireLightKind.Campfire => 0.62f,
        FireLightKind.Torch => 1.45f,
        FireLightKind.Candle => 0.95f,
        _ => LightLift,
    };

    public static bool IsWindow(XObject item) =>
        item is not XPerson && (item[ObjectData.FlagField2] & 0x4000) != 0 && item.Position.X >= 0 && item.Position.Y >= 0;

    // 5 Sims 3D units above floor at 3 units per tile.
    public const float LightLift = 5f / 3f;

    private static bool InsideLot(XObject item)
    {
        var x = item.Position.X >> 4;
        var y = item.Position.Y >> 4;
        return x > 0 && y > 0 && x < LotGeometry.LotDimension - 1 && y < LotGeometry.LotDimension - 1;
    }

    public static State? Build(SimulationWorld world, RoomMap? roomMap, short house)
    {
        var allRoomIds = new SortedSet<ushort>();
        if (roomMap is not null)
        {
            foreach (var id in roomMap.RoomIds) allRoomIds.Add(id);
        }
        foreach (var map in world.LotRoomMaps.Values)
        {
            foreach (var id in map.RoomIds) allRoomIds.Add(id);
        }
        if (allRoomIds.Count == 0) return null;
        var phase = world.Clock.TimeOfDay;
        var outside = Level(ClampSpriteLight(OutsideLight(phase), phase));
        var maxRoomId = Math.Max((int)allRoomIds.Max, RoomMap.NoRoom);
        var rooms = Enumerable.Range(0, maxRoomId + 1)
            .Select(id => new Room(id, true, 0, 100, outside, outside, outside)).ToArray();
        foreach (var roomId in allRoomIds)
        {
            var id = (int)roomId;
            if (world.RoomIsOutside(checked((short)roomId)))
            {
                rooms[id] = new Room(id, true, 0, 100, outside, outside, outside);
                continue;
            }
            if (!world.PersonRoomMotiveEntries.TryGetValue(roomId, out var entry))
                throw new InvalidDataException($"Room {id} has no native room-motive record");
            var light = ClampSpriteLight(SimulationWorld.DisplayedRoomLight(entry), phase);
            var level = Level(light);
            rooms[id] = new Room(id, false, Math.Min(100, entry.LightingObjectCount140), 0, level, level, level);
        }
        return new State(new RGB(outside, outside, outside), rooms, Backdrop(phase, house),
            world.Clock.Hour * 60 + world.Clock.Minute, phase);
    }

    private static float OutsideLight(int phase) => phase switch { 0 => 1f, 1 or 3 => 0.5f, _ => 0f };

    private static float ClampSpriteLight(float room, int phase) =>
        Math.Clamp(room, 0.5f, phase == 0 ? 1f : 0.8f);

    private static RGB Backdrop(int phase, short house) => house == 99 ? new RGB(0x14, 0x14, 0x8c) : phase switch
    {
        0 => new RGB(0x73, 0x73, 0x73),
        1 or 3 => new RGB(0x40, 0x40, 0x40),
        _ => new RGB(0x1a, 0x1a, 0x1a),
    };

    private static byte Level(float light) => (byte)Math.Clamp((int)Math.Round(light * 255), 0, 255);
}
