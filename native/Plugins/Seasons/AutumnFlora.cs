using System;
using System.Collections.Generic;
using System.Numerics;
using SimsNative.Plugins;

namespace Local.Seasons;

public sealed partial class SeasonsPlugin
{
    private enum FloraKind
    {
        None = 0,
        DeciduousShrub = 1,
        DeciduousTree = 2,
        EvergreenShrub = 3,
        EvergreenHedge = 4,
        EvergreenTree = 5,
    }

    private sealed class FloraGroup
    {
        public FloraKind Kind;
        public uint Guid;
        public float Param;
        public float Hue;
        public float LumRef;
        public readonly HashSet<(int X, int Y)> Tiles = [];
    }

    private sealed record FloraStamp(int Priority, float X, float Y, float Param, float Foot);

    private int autumnFloraHouse;
    private int autumnFloraMinute = -1;
    private int lastAutumnEnvMode = -1;
    private ulong autumnFloraHash;
    private readonly List<SeasonTrailMark> autumnPrints = [];

    private void ResetAutumnFlora()
    {
        autumnFloraHouse = 0;
        autumnFloraMinute = -1;
        lastAutumnEnvMode = -1;
        autumnFloraHash = 0;
        autumnPrints.Clear();
    }

    private void TryRefreshAutumnFlora(int house)
    {
        try
        {
            var lot = context.Simulation;
            if (lot.House != house) return;
            var paused = lot.Paused;
            var minute = lot.Hours * 60 + lot.Minutes;
            if (autumnFloraHouse != house || paused || autumnFloraMinute != minute)
            {
                RefreshAutumnFlora(lot);
                autumnFloraMinute = paused ? -1 : minute;
            }
        }
        catch (InvalidOperationException)
        {
        }
        catch (NotSupportedException)
        {
        }
    }

    private void RefreshAutumnFlora(IPluginSimulation lot)
    {
        var grouped = new Dictionary<short, FloraGroup>();
        var hedgeTiles = new HashSet<(int X, int Y)>();

        foreach (var obj in lot.Objects)
        {
            if (!obj.Outside || obj.Level != 1)
                continue;

            var kind = ClassifyFlora(obj.Guid, obj.Name, out var param, out var hue, out var lumRef);
            if (kind == FloraKind.None)
                continue;

            bool isEvergreen = kind is FloraKind.EvergreenTree or FloraKind.EvergreenShrub or FloraKind.EvergreenHedge;
            if (obj.Sheltered && !isEvergreen)
                continue;

            if (kind == FloraKind.EvergreenHedge)
            {
                hedgeTiles.Add((obj.X, obj.Y));
                continue;
            }

            var leadId = obj.LeadObjectId != 0 ? obj.LeadObjectId : obj.ObjectId;
            if (!grouped.TryGetValue(leadId, out var group))
            {
                group = new FloraGroup { Kind = kind, Guid = obj.Guid, Param = param, Hue = hue, LumRef = lumRef };
                grouped[leadId] = group;
            }
            else if ((int)kind > (int)group.Kind)
            {
                group.Kind = kind;
                group.Guid = obj.Guid;
                group.Param = param;
                group.Hue = hue;
                group.LumRef = lumRef;
            }
            else if (kind == group.Kind && param > group.Param)
            {
                group.Param = param;
            }

            group.Tiles.Add((obj.X, obj.Y));
        }

        var stamps = new List<FloraStamp>(grouped.Count + hedgeTiles.Count);

        foreach (var (leadId, group) in grouped)
        {
            if (group.Tiles.Count == 0)
                continue;

            var sumX = 0f;
            var sumY = 0f;
            foreach (var (tx, ty) in group.Tiles)
            {
                sumX += tx + 0.5f;
                sumY += ty + 0.5f;
            }

            var invCount = 1f / group.Tiles.Count;
            var cx = sumX * invCount;
            var cy = sumY * invCount;

            switch (group.Kind)
            {
                case FloraKind.EvergreenTree:
                    stamps.Add(new FloraStamp(0, cx, cy, group.Param, -1.0f));
                    break;

                case FloraKind.EvergreenShrub:
                    stamps.Add(new FloraStamp(2, cx, cy, group.Param, -1.5f));
                    break;

                case FloraKind.DeciduousTree:
                {
                    uint seed = unchecked((uint)leadId ^ ((uint)lot.House * 0x85EBCA6Bu));
                    var hue = SelectTreeAutumnHue(group.Guid, group.Hue, seed);
                    stamps.Add(new FloraStamp(3, cx, cy, EncodeFloraHeading(group.Param, group.LumRef), 1.0f + hue));
                    break;
                }

                case FloraKind.DeciduousShrub:
                {
                    uint seed = unchecked((uint)leadId ^ ((uint)lot.House * 0x85EBCA6Bu));
                    var hue = SelectShrubAutumnHue(group.Guid, group.Hue, seed);
                    stamps.Add(new FloraStamp(4, cx, cy, EncodeFloraHeading(group.Param, group.LumRef), 2.1f + hue));
                    break;
                }
            }
        }

        EmitMergedHedgeStamps(hedgeTiles, stamps);

        stamps.Sort(static (a, b) =>
        {
            var cmp = a.Priority.CompareTo(b.Priority);
            if (cmp != 0) return cmp;
            cmp = a.X.CompareTo(b.X);
            if (cmp != 0) return cmp;
            cmp = a.Y.CompareTo(b.Y);
            if (cmp != 0) return cmp;
            cmp = a.Param.CompareTo(b.Param);
            return cmp != 0 ? cmp : a.Foot.CompareTo(b.Foot);
        });

        var count = Math.Min(stamps.Count, 127);
        var hash = 14695981039346656037UL;
        hash = FnvMix(hash, (uint)lot.House);
        hash = FnvMix(hash, (uint)count);
        for (var i = 0; i < count; i++)
        {
            var s = stamps[i];
            hash = FnvMix(hash, (uint)MathF.Round(s.X * 16f));
            hash = FnvMix(hash, (uint)MathF.Round(s.Y * 16f));
            hash = FnvMix(hash, (uint)MathF.Round(s.Param * 100f));
            hash = FnvMix(hash, (uint)MathF.Round(s.Foot * 1000f));
        }

        if (autumnFloraHouse == lot.House && autumnFloraHash == hash)
            return;

        autumnFloraHouse = lot.House;
        autumnFloraHash = hash;
        autumnPrints.Clear();
        autumnPrints.Add(new SeasonTrailMark(++sequence, -100f, -100f, 0f, 3.9f));

        for (var i = 0; i < count; i++)
        {
            var s = stamps[i];
            autumnPrints.Add(new SeasonTrailMark(++sequence, s.X, s.Y, s.Param, s.Foot));
        }
    }

    private static void EmitMergedHedgeStamps(HashSet<(int X, int Y)> remaining, List<FloraStamp> stamps)
    {
        if (remaining.Count == 0)
            return;

        var horizontalOrder = new List<(int X, int Y)>(remaining);
        horizontalOrder.Sort(static (a, b) =>
        {
            var cmp = a.Y.CompareTo(b.Y);
            return cmp != 0 ? cmp : a.X.CompareTo(b.X);
        });

        var index = 0;
        while (index < horizontalOrder.Count)
        {
            var (x0, y) = horizontalOrder[index];
            var x1 = x0;
            index++;
            while (index < horizontalOrder.Count && horizontalOrder[index].Y == y && horizontalOrder[index].X == x1 + 1)
            {
                x1++;
                index++;
            }

            if (x1 > x0)
            {
                for (var x = x0; x <= x1; x++)
                    remaining.Remove((x, y));

                stamps.Add(new FloraStamp(1, (x0 + x1) * 0.5f + 0.5f, y + 0.5f, (x1 - x0) * 0.5f + 0.52f, -2.0f));
            }
        }

        if (remaining.Count == 0)
            return;

        var verticalOrder = new List<(int X, int Y)>(remaining);
        verticalOrder.Sort(static (a, b) =>
        {
            var cmp = a.X.CompareTo(b.X);
            return cmp != 0 ? cmp : a.Y.CompareTo(b.Y);
        });

        index = 0;
        while (index < verticalOrder.Count)
        {
            var (x, y0) = verticalOrder[index];
            var y1 = y0;
            index++;
            while (index < verticalOrder.Count && verticalOrder[index].X == x && verticalOrder[index].Y == y1 + 1)
            {
                y1++;
                index++;
            }

            if (y1 > y0)
            {
                for (var y = y0; y <= y1; y++)
                    remaining.Remove((x, y));

                stamps.Add(new FloraStamp(1, x + 0.5f, (y0 + y1) * 0.5f + 0.5f, (y1 - y0) * 0.5f + 0.52f, -2.5f));
            }
        }

        foreach (var (x, y) in remaining)
            stamps.Add(new FloraStamp(1, x + 0.5f, y + 0.5f, 0.52f, -2.0f));
    }

    private static float SelectTreeAutumnHue(uint guid, float baseHue, uint seed)
    {
        float r0 = TreeHueJitter(seed);
        float r1 = TreeHueJitter(seed ^ 0xA5A5F00Du);
        return guid switch
        {
            0x1468C3A7u or 0x8F89C3DDu or 0xC0C3E3ABu or 0x1182FF7Cu or 0x7B56A4E8u or 0xC99AC74Eu =>
                r1 < 0.72f ? 0.08f + 0.16f * r0 : 0.30f + 0.14f * r0,
            0x5C198CBEu or 0x93DDE1F7u or 0x82998688u or 0xF200F110u or 0xE184A4DBu
                or 0xCEB2F9B8u or 0xBDECFE70u or 0x4498AD77u or 0x1C57A3B7u or 0xC4D089B2u
                or 0x6382888Du or 0x9CC2AA86u or 0x1AA2F18Cu or 0xFE21991Au or 0x05FF8522u =>
                0.10f + 0.22f * r0,
            0x440087F3u or 0xAF169672u or 0x81BCC800u or 0xEB10D3E6u or 0xDD96E529u or 0x00DD7908u =>
                0.80f + 0.14f * r0,
            _ => Math.Clamp(baseHue + (r0 - 0.5f) * 0.24f, 0.08f, 0.94f),
        };
    }

    private static float SelectShrubAutumnHue(uint guid, float baseHue, uint seed)
    {
        float r0 = TreeHueJitter(seed);
        float r1 = TreeHueJitter(seed ^ 0x5BD1E995u);
        return guid switch
        {
            0xD5CA5425u => r1 < 0.72f ? 0.82f + 0.12f * r0 : 0.58f + 0.16f * r0,
            0xB1153E7Du => 0.16f + 0.18f * r0,
            _ => r1 < 0.44f
                ? 0.12f + 0.20f * r0
                : r1 < 0.74f
                    ? 0.36f + 0.26f * r0
                    : 0.81f + 0.13f * r0,
        };
    }

    private static float TreeHueJitter(uint seed)
    {
        unchecked
        {
            var h = seed * 0x9E3779B1u;
            h ^= h >> 16;
            h *= 0x85EBCA6Bu;
            h ^= h >> 13;
            h *= 0xC2B2AE35u;
            h ^= h >> 16;
            return h / 4294967295f;
        }
    }

    internal static List<Vector4> BuildSurroundingsFloraStamps(
        IReadOnlyList<PluginSceneryInstance> scenery,
        int house,
        IReadOnlyList<Vector4> lotStamps)
    {
        var stamps = new List<FloraStamp>(scenery.Count + lotStamps.Count);
        for (int i = 0; i < scenery.Count; i++)
        {
            var item = scenery[i];
            var kind = ClassifyFlora(item.Guid, item.Name ?? string.Empty, out var param, out var hue, out var lumRef);
            if (kind == FloraKind.None)
                continue;

            uint seed = unchecked((uint)((int)MathF.Round(item.X * 4f) * 73856093 ^ (int)MathF.Round(item.Y * 4f) * 19349663 ^ house * 83492791));
            switch (kind)
            {
                case FloraKind.EvergreenTree:
                    stamps.Add(new FloraStamp(0, item.X, item.Y, param, -1.0f));
                    break;

                case FloraKind.EvergreenHedge:
                case FloraKind.EvergreenShrub:
                    stamps.Add(new FloraStamp(2, item.X, item.Y, param, -1.5f));
                    break;

                case FloraKind.DeciduousTree:
                {
                    var jittered = SelectTreeAutumnHue(item.Guid, hue, seed);
                    stamps.Add(new FloraStamp(3, item.X, item.Y, EncodeFloraHeading(param, lumRef), 1.0f + jittered));
                    break;
                }

                case FloraKind.DeciduousShrub:
                {
                    var jittered = SelectShrubAutumnHue(item.Guid, hue, seed);
                    stamps.Add(new FloraStamp(4, item.X, item.Y, EncodeFloraHeading(param, lumRef), 2.1f + jittered));
                    break;
                }
            }
        }

        for (int i = 0; i < lotStamps.Count; i++)
        {
            var ls = lotStamps[i];
            int priority = ls.W < -1.75f ? 1
                : ls.W <= -1.25f ? 2
                : ls.W < -0.75f ? 0
                : ls.W >= 2.08f ? 4
                : 3;
            stamps.Add(new FloraStamp(priority, ls.X, ls.Y, ls.Z, ls.W));
        }

        stamps.Sort(static (a, b) =>
        {
            var cmp = a.Priority.CompareTo(b.Priority);
            if (cmp != 0) return cmp;
            cmp = a.X.CompareTo(b.X);
            if (cmp != 0) return cmp;
            cmp = a.Y.CompareTo(b.Y);
            if (cmp != 0) return cmp;
            cmp = a.Param.CompareTo(b.Param);
            return cmp != 0 ? cmp : a.Foot.CompareTo(b.Foot);
        });

        var output = new List<Vector4>(stamps.Count);
        for (int i = 0; i < stamps.Count; i++)
        {
            var s = stamps[i];
            output.Add(new Vector4(s.X, s.Y, s.Param, s.Foot));
        }
        return output;
    }

    private static ulong FnvMix(ulong hash, uint value)
    {
        unchecked
        {
            hash ^= value;
            hash *= 1099511628211UL;
            return hash;
        }
    }

    private static readonly string[] NonFloraKeywords =
    [
        "Chair", "Table", "Desk", "Bed", "Bench", "Cabinet", "Counter", "Door",
        "Window", "Fence", "Lamp", "Clock", "Bookcase", "Dresser", "Sofa",
        "Couch", "Stump", "Tub", "Barrel", "Planter", "Pot", "Swing",
        "Stair", "Fireplace"
    ];

    private static readonly string[] EvergreenKeywords =
    [
        "Pine", "Fir", "Spruce", "Cypress", "Cedar", "Juniper", "Redwood",
        "Sequoia", "Hemlock", "Yew", "Holly", "Boxwood", "Privet", "Laurel",
        "Topiary", "Palm", "Cactus", "Agave", "Succulent", "Aloe", "Bamboo",
        "Fern", "Ivy", "Citrus", "Orange", "Lemon", "Lime", "Olive",
        "Magnolia", "Rhododendron", "Camellia", "Azalea", "Hibiscus", "Rose",
        "Flower", "Blossom", "Oleander", "Hydrangea", "Gardenia", "Bougainvillea",
        "Tulip", "Daffodil", "Daisy", "Pansy", "Geranium", "Sunflower", "Lily",
        "Orchid", "Violets", "Nasturtium", "Marigold", "Lavender", "Petunia",
        "Evergreen", "Christmas", "Spellbound", "Autumn", "Dead", "Spooky"
    ];

    private static readonly string[] TallEvergreenKeywords =
    [
        "Pine", "Fir", "Spruce", "Cypress", "Cedar", "Redwood", "Sequoia",
        "Hemlock", "Palm", "Cactus", "Citrus", "Orange", "Lemon", "Lime",
        "Olive", "Magnolia", "Christmas", "Spellbound", "Autumn", "Dead",
        "Spooky", "Tree"
    ];

    // Packs integer lumRef bin into Heading (Param) while keeping |Foot| <= 3.9f for PluginHost validation.
    private static float EncodeFloraHeading(float radius, float lumRef)
    {
        var lumBin = Math.Clamp((int)MathF.Round((lumRef - 0.020f) / 0.120f * 60f), 0, 60);
        return lumBin * 10.0f + Math.Clamp(radius, 0.30f, 5.00f);
    }

    private static FloraKind ClassifyFlora(uint guid, string name, out float param, out float hue, out float lumRef)
    {
        lumRef = 0f;

        switch (guid)
        {
            case 0x1468C3A7u:
            case 0x8F89C3DDu:
            case 0xC0C3E3ABu:
            case 0x1182FF7Cu:
            case 0x7B56A4E8u:
                param = 1.65f;
                hue = 0.14f;
                lumRef = 0.022f;
                return FloraKind.DeciduousTree;

            case 0x5C198CBEu:
            case 0x93DDE1F7u:
            case 0x82998688u:
            case 0xF200F110u:
            case 0xE184A4DBu:
                param = 1.75f;
                hue = 0.22f;
                lumRef = 0.056f;
                return FloraKind.DeciduousTree;

            case 0x2B839414u:
            case 0x2B83B971u:
            case 0x2B85F3B9u:
            case 0x2B82BBB3u:
            case 0x2B82EB2Eu:
                param = 1.65f;
                hue = 0.42f;
                lumRef = 0.022f;
                return FloraKind.DeciduousTree;

            case 0x09D8DCECu:
            case 0x5CDAF13Au:
            case 0x4C9BFBFDu:
            case 0xA5379F60u:
            case 0x9610DC23u:
                param = 1.65f;
                hue = 0.66f;
                lumRef = 0.060f;
                return FloraKind.DeciduousTree;

            case 0xC99AC74Eu:
                param = 1.20f;
                hue = 0.12f;
                lumRef = 0.135f;
                return FloraKind.DeciduousTree;

            case 0x440087F3u:
            case 0xAF169672u:
            case 0x81BCC800u:
            case 0xEB10D3E6u:
            case 0xDD96E529u:
                param = 1.65f;
                hue = 0.78f;
                lumRef = 0.055f;
                return FloraKind.DeciduousTree;

            case 0x3484C1F7u:
            case 0x0857B671u:
            case 0x5764E8AFu:
            case 0xA17EB26Au:
            case 0xFC528B7Du:
                param = 1.75f;
                hue = 0.86f;
                lumRef = 0.038f;
                return FloraKind.DeciduousTree;

            case 0x1671A218u:
            case 0x00DD7908u:
                param = 1.25f;
                hue = 0.72f;
                lumRef = 0.028f;
                return FloraKind.DeciduousTree;

            case 0xAC66D6CAu:
            case 0x15A2A7B0u:
            case 0xB612B0D6u:
            case 0xFAA5BC18u:
            case 0x39B3CEF6u:
            case 0x2FA784C3u:
            case 0x18F3A440u:
            case 0x0E52DC52u:
            case 0x77D0B84Bu:
            case 0x5FDB844Fu:
                param = 2.05f;
                hue = 0.36f;
                lumRef = 0.027f;
                return FloraKind.DeciduousTree;

            case 0x6A6D90A8u:
            case 0x6854DA61u:
            case 0x68F0926Bu:
            case 0x6B62C2F6u:
            case 0x6BFFBDCCu:
            case 0x6A8AE725u:
            case 0x6526F69Fu:
            case 0x6549A8E7u:
            case 0x65ECB31Bu:
            case 0x640985D9u:
                param = 2.15f;
                hue = 0.54f;
                lumRef = 0.058f;
                return FloraKind.DeciduousTree;

            case 0xCEB2F9B8u:
            case 0xBDECFE70u:
            case 0x4498AD77u:
            case 0x1C57A3B7u:
            case 0xC4D089B2u:
            case 0x6382888Du:
            case 0x9CC2AA86u:
            case 0x1AA2F18Cu:
            case 0xFE21991Au:
            case 0x05FF8522u:
                param = 2.15f;
                hue = 0.20f;
                lumRef = 0.065f;
                return FloraKind.DeciduousTree;

            case 0x2C555EA3u:
                param = 0.62f;
                hue = 0.30f;
                lumRef = 0.084f;
                return FloraKind.DeciduousShrub;
            case 0xD5CA5425u:
                param = 0.62f;
                hue = 0.86f;
                lumRef = 0.074f;
                return FloraKind.DeciduousShrub;
            case 0xB1153E7Du:
                param = 0.58f;
                hue = 0.22f;
                lumRef = 0.075f;
                return FloraKind.DeciduousShrub;

            case 0x39319021u:
            case 0x07CFB214u:
            case 0x58EBC469u:
            case 0x9B2BD5C3u:
            case 0xECD28B8Eu:
            case 0x5F421524u:
            case 0xBD9E1D34u:
            case 0x9F9D7688u:
            case 0xFCDE3114u:
            case 0xDB4B0721u:
            case 0x8BA56284u:
            case 0xF7194FE6u:
            case 0xD1743863u:
            case 0x358D29CEu:
            case 0x1748778Eu:
            case 0x51474702u:
            case 0xB7AF202Bu:
            case 0x90CB0721u:
            case 0xFE560D63u:
            case 0xD987287Eu:
                param = 1.55f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x3026A0F4u:
            case 0x3026B863u:
            case 0x3026C759u:
            case 0x3026E8FEu:
            case 0x3026EA3Cu:
            case 0xAA86AD2Au:
            case 0xF140D974u:
            case 0xC15387ADu:
            case 0x23F3DD6Cu:
            case 0x03CDE481u:
            case 0x30078DCFu:
            case 0x3007996Eu:
            case 0x3007A790u:
            case 0x3007C49Eu:
            case 0x3007ED15u:
            case 0xDE802250u:
            case 0xFD085D5Du:
            case 0xDE3668E1u:
            case 0xC5CE7914u:
            case 0x10B32EB3u:
                param = 1.75f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x9DA7B210u:
            case 0x99400B4Au:
                param = 1.15f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x6A6DBADCu:
            case 0x6A55E034u:
            case 0x6A79CD51u:
            case 0x6A67AB66u:
            case 0x6A8BF51Eu:
            case 0xA02C8857u:
                param = 1.40f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0xD9BD21CDu:
            case 0xC3D369C9u:
            case 0x373C3951u:
            case 0x26A24677u:
            case 0x01656B1Au:
                param = 1.55f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x678F09FFu:
            case 0x67FB41F5u:
            case 0x64671168u:
            case 0x64D26E52u:
            case 0x653F4337u:
            case 0x65AA34BAu:
            case 0x62162500u:
            case 0x62827B78u:
            case 0x62F16084u:
            case 0x63615647u:
                param = 2.05f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x110CF4B1u:
            case 0x0EDEB33Au:
            case 0x0E908508u:
            case 0x0E628AAFu:
            case 0x0E348B13u:
            case 0xD17F1085u:
            case 0xFB0E28E7u:
            case 0x127428BCu:
            case 0x4676293Fu:
            case 0x5EDC56E1u:
            case 0xB9020120u:
            case 0xE049759Au:
            case 0xF89E2350u:
            case 0x16AE22EEu:
            case 0x335E4B40u:
            case 0xF9E11D1Cu:
            case 0x9249249Fu:
            case 0x7E213927u:
            case 0x92473548u:
            case 0xAB0422E6u:
            case 0xBEB34678u:
            case 0xD27A1F32u:
            case 0xE55470A2u:
            case 0xFA5637A8u:
            case 0x82960603u:
            case 0x89BC1085u:
            case 0xA8D128E7u:
            case 0xC60128BCu:
                param = 1.75f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x10444309u:
            case 0x2ABC6E73u:
            case 0xBB83A08Au:
            case 0xD68E73D8u:
            case 0xF2999F51u:
            case 0x5359BFC1u:
            case 0x3C52B66Du:
            case 0xC3EFD759u:
            case 0x1181CCB1u:
                param = 0.52f;
                hue = 0f;
                return FloraKind.EvergreenHedge;

            case 0x4B4D30A9u:
                param = 0.54f;
                hue = 0f;
                return FloraKind.EvergreenShrub;

            case 0xDC0BEF65u:
            case 0xA9648B31u:
            case 0x6961DA94u:
            case 0x5A3A9DB8u:
            case 0x4B60CC69u:
                param = 0.72f;
                hue = 0f;
                return FloraKind.EvergreenShrub;

            case 0x154522AFu:
            case 0x15460FCAu:
            case 0x0EB692FBu:
            case 0xAED3C88Au:
            case 0x72BDBB7Du:
            case 0x11EC66D9u:
            case 0x52ED4B7Cu:
            case 0x34431396u:
            case 0xE4FB60EBu:
            case 0xE48328E1u:
            case 0xE482787Cu:
            case 0xE48D0746u:
            case 0xE48C2A23u:
            case 0xD6272E40u:
            case 0x302E3939u:
            case 0x7C24A376u:
            case 0xE9693F98u:
            case 0x17332210u:
            case 0x15316867u:
            case 0x15445522u:
            case 0xAD12E0D0u:
            case 0x9AE018BBu:
            case 0xAF4A1300u:
            case 0xE5293E72u:
            case 0x78EDCD25u:
            case 0xFF97BA8Fu:
            case 0x952BCAC7u:
            case 0xF3CCCCBEu:
            case 0xF3CA84B4u:
            case 0x984671A9u:
            case 0x70FC19C3u:
            case 0xFEE30120u:
            case 0x8EB8E1A6u:
            case 0xBC661500u:
            case 0x54C3E0CFu:
            case 0xFA733902u:
                param = 0.48f;
                hue = 0f;
                return FloraKind.EvergreenShrub;
        }

        if (string.IsNullOrWhiteSpace(name) || MatchesNonFlora(name))
        {
            param = 0f;
            hue = 0f;
            return FloraKind.None;
        }

        if (NameMatches(name, "Hedge", "Flower", "Nasturtium", "Marigold", "Petunia", "Tulip", "Daffodil", "Daisy", "Pansy", "Geranium", "Violets", "Lavender"))
        {
            param = 0.52f;
            hue = 0f;
            return FloraKind.EvergreenHedge;
        }

        if (NameMatches(name, EvergreenKeywords))
        {
            if (NameMatches(name, TallEvergreenKeywords))
            {
                param = 1.40f;
                hue = 0f;
                return FloraKind.EvergreenTree;
            }

            param = 0.60f;
            hue = 0f;
            return FloraKind.EvergreenShrub;
        }

        if (NameMatches(name, "Sycamore"))
        {
            param = 2.05f;
            hue = 0.54f;
            lumRef = 0.058f;
            return FloraKind.DeciduousTree;
        }

        if (NameMatches(name, "Willow"))
        {
            param = name.Contains("Weeping", StringComparison.OrdinalIgnoreCase) ? 2.05f : 1.75f;
            hue = 0.21f;
            lumRef = 0.058f;
            return FloraKind.DeciduousTree;
        }

        if (NameMatches(name, "Birch", "Poplar", "Aspen", "Ginkgo"))
        {
            param = 1.55f;
            hue = 0.14f;
            lumRef = 0.045f;
            return FloraKind.DeciduousTree;
        }

        if (NameMatches(name, "Apple", "Elm", "Beech", "Linden", "Alder", "Walnut", "Hickory"))
        {
            param = 1.65f;
            hue = 0.45f;
            lumRef = 0.040f;
            return FloraKind.DeciduousTree;
        }

        if (NameMatches(name, "Maple", "Oak", "Mulberry", "Prune", "Plum", "Cherry", "Crape Myrtle", "Chestnut", "Ash", "Sweetgum", "Dogwood", "Tree"))
        {
            param = 1.60f;
            hue = 0.68f;
            lumRef = 0.048f;
            return FloraKind.DeciduousTree;
        }

        if (NameMatches(name, "Shrub", "Bush"))
        {
            param = 0.62f;
            hue = 0.34f;
            lumRef = 0.078f;
            return FloraKind.DeciduousShrub;
        }

        param = 0f;
        hue = 0f;
        return FloraKind.None;
    }

    private static bool MatchesNonFlora(string name)
    {
        for (var i = 0; i < NonFloraKeywords.Length; i++)
        {
            var token = NonFloraKeywords[i];
            var idx = 0;
            while ((idx = name.IndexOf(token, idx, StringComparison.OrdinalIgnoreCase)) >= 0)
            {
                if (idx == 0 || !char.IsLetter(name[idx - 1]))
                    return true;
                idx += token.Length;
            }
        }
        return false;
    }
}
