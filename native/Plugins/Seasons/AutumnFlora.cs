using System;
using System.Collections.Generic;
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
    private readonly List<PluginFootprint> autumnPrints = [];

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
                group = new FloraGroup { Kind = kind, Param = param, Hue = hue, LumRef = lumRef };
                grouped[leadId] = group;
            }
            else if ((int)kind > (int)group.Kind)
            {
                group.Kind = kind;
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
                    var hue = ApplyHueJitter(group.Hue, leadId, 0.14f);
                    stamps.Add(new FloraStamp(3, cx, cy, EncodeFloraHeading(group.Param, group.LumRef), 1.0f + hue));
                    break;
                }

                case FloraKind.DeciduousShrub:
                {
                    var hue = ApplyHueJitter(group.Hue, leadId, 0.12f);
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

        var count = Math.Min(stamps.Count, 63);
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
        // Foot > 3.5 clears the previous autumn flora buffer in trail.frag before stamping active entries.
        autumnPrints.Add(new PluginFootprint(++sequence, -100f, -100f, 0f, 3.9f));

        for (var i = 0; i < count; i++)
        {
            var s = stamps[i];
            autumnPrints.Add(new PluginFootprint(++sequence, s.X, s.Y, s.Param, s.Foot));
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

    private static float ApplyHueJitter(float baseHue, short seedId, float span) =>
        Math.Clamp(baseHue + (TreeHueJitter(seedId) - 0.5f) * span, 0.08f, 0.94f);

    private static float TreeHueJitter(short leadId)
    {
        unchecked
        {
            var h = (uint)leadId * 0x9E3779B1u;
            h ^= h >> 16;
            h *= 0x85EBCA6Bu;
            h ^= h >> 13;
            h *= 0xC2B2AE35u;
            h ^= h >> 16;
            return h / 4294967295f;
        }
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

        // 0x6A6D is shared between Christmas Tree - Front and Unleashed Sycamore - 4.
        if (guid == 0x6A6Du)
        {
            if (name.Contains("Christmas", StringComparison.OrdinalIgnoreCase))
            {
                param = 1.40f;
                hue = 0f;
                return FloraKind.EvergreenTree;
            }

            param = 2.15f;
            hue = 0.54f;
            lumRef = 0.058f;
            return FloraKind.DeciduousTree;
        }

        switch (guid)
        {
            case 0x1468u:
            case 0x8F89u:
            case 0xC0C3u:
            case 0x1182u:
            case 0x7B56u:
                param = 1.65f;
                hue = 0.14f;
                lumRef = 0.022f;
                return FloraKind.DeciduousTree;

            case 0x5C19u:
            case 0x93DDu:
            case 0x8299u:
            case 0xF200u:
            case 0xE184u:
                param = 1.75f;
                hue = 0.22f;
                lumRef = 0.056f;
                return FloraKind.DeciduousTree;

            case 0x2B83u:
            case 0x2B85u:
            case 0x2B82u:
                param = 1.65f;
                hue = 0.42f;
                lumRef = 0.022f;
                return FloraKind.DeciduousTree;

            case 0x09D8u:
            case 0x5CDAu:
            case 0x4C9Bu:
            case 0xA537u:
            case 0x9610u:
                param = 1.65f;
                hue = 0.66f;
                lumRef = 0.060f;
                return FloraKind.DeciduousTree;

            case 0xC99Au:
                param = 1.20f;
                hue = 0.12f;
                lumRef = 0.135f;
                return FloraKind.DeciduousTree;

            case 0x4400u:
            case 0xAF16u:
            case 0x81BCu:
            case 0xEB10u:
            case 0xDD96u:
                param = 1.65f;
                hue = 0.78f;
                lumRef = 0.055f;
                return FloraKind.DeciduousTree;

            case 0x3484u:
            case 0x0857u:
            case 0x5764u:
            case 0xA17Eu:
            case 0xFC52u:
                param = 1.75f;
                hue = 0.86f;
                lumRef = 0.038f;
                return FloraKind.DeciduousTree;

            case 0x1671u:
            case 0x00DDu:
                param = 1.25f;
                hue = 0.72f;
                lumRef = 0.028f;
                return FloraKind.DeciduousTree;

            case 0xAC66u:
            case 0x15A2u:
            case 0xB612u:
            case 0xFAA5u:
            case 0x39B3u:
            case 0x2FA7u:
            case 0x18F3u:
            case 0x0E52u:
            case 0x77D0u:
            case 0x5FDBu:
                param = 2.05f;
                hue = 0.36f;
                lumRef = 0.027f;
                return FloraKind.DeciduousTree;

            case 0x6854u:
            case 0x68F0u:
            case 0x6B62u:
            case 0x6BFFu:
            case 0x6A8Au:
            case 0x6526u:
            case 0x6549u:
            case 0x65ECu:
            case 0x6409u:
                param = 2.15f;
                hue = 0.54f;
                lumRef = 0.058f;
                return FloraKind.DeciduousTree;

            case 0xCEB2u:
            case 0xBDECu:
            case 0x4498u:
            case 0x1C57u:
            case 0xC4D0u:
            case 0x6382u:
            case 0x9CC2u:
            case 0x1AA2u:
            case 0xFE21u:
            case 0x05FFu:
                param = 2.15f;
                hue = 0.20f;
                lumRef = 0.065f;
                return FloraKind.DeciduousTree;

            case 0x2C55u:
                param = 0.75f;
                hue = 0.30f;
                lumRef = 0.084f;
                return FloraKind.DeciduousShrub;
            case 0xD5CAu:
                param = 0.72f;
                hue = 0.18f;
                lumRef = 0.074f;
                return FloraKind.DeciduousShrub;
            case 0xB115u:
                param = 0.65f;
                hue = 0.14f;
                lumRef = 0.075f;
                return FloraKind.DeciduousShrub;

            // Tall evergreen & pre-themed trees (stay untouched at all heights)
            case 0x3931u:
            case 0x07CFu:
            case 0x58EBu:
            case 0x9B2Bu:
            case 0xECD2u:
            case 0x5F42u:
            case 0xBD9Eu:
            case 0x9F9Du:
            case 0xFCDEu:
            case 0xDB4Bu:
            case 0x8BA5u:
            case 0xF719u:
            case 0xD174u:
            case 0x358Du:
            case 0x1748u:
            case 0x5147u:
            case 0xB7AFu:
            case 0x90CBu:
            case 0xFE56u:
            case 0xD987u:
                param = 1.55f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x3026u:
            case 0xAA86u:
            case 0xF140u:
            case 0xC153u:
            case 0x23F3u:
            case 0x03CDu:
            case 0x3007u:
            case 0xDE80u:
            case 0xFD08u:
            case 0xDE36u:
            case 0xC5CEu:
            case 0x10B3u:
                param = 1.75f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x9DA7u:
            case 0x9940u:
                param = 1.15f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x6A55u:
            case 0x6A79u:
            case 0x6A67u:
            case 0x6A8Bu:
            case 0xA02Cu:
                param = 1.40f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0xD9BDu:
            case 0xC3D3u:
            case 0x373Cu:
            case 0x26A2u:
            case 0x0165u:
                param = 1.55f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x678Fu:
            case 0x67FBu:
            case 0x6467u:
            case 0x64D2u:
            case 0x653Fu:
            case 0x65AAu:
            case 0x6216u:
            case 0x6282u:
            case 0x62F1u:
            case 0x6361u:
                param = 2.05f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            case 0x110Cu:
            case 0x0EDEu:
            case 0x0E90u:
            case 0x0E62u:
            case 0x0E34u:
            case 0xD17Fu:
            case 0xFB0Eu:
            case 0x1274u:
            case 0x4676u:
            case 0x5EDCu:
            case 0xB902u:
            case 0xE049u:
            case 0xF89Eu:
            case 0x16AEu:
            case 0x335Eu:
            case 0xF9E1u:
            case 0x9249u:
            case 0x7E21u:
            case 0x9247u:
            case 0xAB04u:
            case 0xBEB3u:
            case 0xD27Au:
            case 0xE554u:
            case 0xFA56u:
            case 0x8296u:
            case 0x89BCu:
            case 0xA8D1u:
            case 0xC601u:
                param = 1.75f;
                hue = 0f;
                return FloraKind.EvergreenTree;

            // Evergreen hedges & planted border boxes
            case 0xBB83u:
            case 0xD68Eu:
            case 0xF299u:
            case 0x5359u:
            case 0x3C52u:
            case 0xC3EFu:
            case 0x1181u:
                param = 0.52f;
                hue = 0f;
                return FloraKind.EvergreenHedge;

            // Low/medium evergreen shrubs, topiaries, tropicals, potted plants & garden plots
            case 0x4B4Du: // Tall Privet Shrub
                param = 0.62f;
                hue = 0f;
                return FloraKind.EvergreenShrub;

            case 0xDC0Bu:
            case 0xA964u:
            case 0x6961u:
            case 0x5A3Au:
            case 0x4B60u: // Century Plant (2x2)
                param = 0.90f;
                hue = 0f;
                return FloraKind.EvergreenShrub;

            case 0x1545u:
            case 0x1546u:
            case 0x0EB6u:
            case 0xAED3u:
            case 0x72BDu:
            case 0x11ECu:
            case 0x52EDu:
            case 0x3443u:
            case 0xE4FBu:
            case 0xE483u:
            case 0xE482u:
            case 0xE48Du:
            case 0xE48Cu:
            case 0xD627u:
            case 0x302Eu:
            case 0x7C24u:
            case 0xE969u:
            case 0x1733u:
            case 0x1531u:
            case 0x1544u:
            case 0xAD12u:
            case 0x9AE0u:
            case 0xAF4Au:
            case 0xE529u:
            case 0x78EDu:
            case 0xFF97u:
            case 0x952Bu:
            case 0xF3CCu:
            case 0xF3CAu:
            case 0x9846u:
            case 0x70FCu:
            case 0xFEE3u:
            case 0x8EB8u:
            case 0xBC66u:
            case 0x54C3u:
            case 0xFA73u:
                param = 0.58f;
                hue = 0f;
                return FloraKind.EvergreenShrub;
        }

        if (string.IsNullOrWhiteSpace(name) || NameMatches(name, NonFloraKeywords))
        {
            param = 0f;
            hue = 0f;
            return FloraKind.None;
        }

        if (NameMatches(name, "Hedge"))
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
            param = 0.70f;
            hue = 0.24f;
            lumRef = 0.078f;
            return FloraKind.DeciduousShrub;
        }

        param = 0f;
        hue = 0f;
        return FloraKind.None;
    }
}
