using System.Collections.Concurrent;
using System.Numerics;
using SimsNative.Plugins;

namespace Local.Seasons;

public sealed partial class SeasonsPlugin : IPluginObjectSpriteModifier
{
    private const int MaxFoliageStage = 9;

    private enum DeciduousHabit : byte
    {
        None = 0,
        Spreading = 1,
        Weeping = 2,
        Slender = 3,
        Shrub = 4,
    }

    private readonly record struct TreeSynthesisCacheKey(
        string Signature,
        int CameraOrientation,
        int Stage);

    private static readonly ConcurrentDictionary<TreeSynthesisCacheKey, PluginObjectSpriteOverride?[]> witheredTreeCache = new();

    private static readonly string[] EvergreenExcludeKeywords =
    [
        "Pine", "Fir", "Spruce", "Cypress", "Cedar", "Juniper", "Redwood",
        "Sequoia", "Hemlock", "Yew", "Holly", "Boxwood", "Privet", "Laurel",
        "Topiary", "Palm", "Cactus", "Agave", "Succulent", "Aloe", "Bamboo",
        "Fern", "Ivy", "Citrus", "Orange", "Lemon", "Lime", "Olive",
        "Magnolia", "Rhododendron", "Camellia", "Azalea", "Oleander", "Hydrangea",
        "Gardenia", "Marigold", "Lavender", "Petunia", "Blossom", "Evergreen", "Christmas",
        "Spellbound", "Autumn", "Dead", "Spooky", "Hedge", "Rose", "Flower",
        "Tulip", "Daffodil", "Nasturtium", "Daisy", "Pansy", "Geranium",
        "Sunflower", "Lily", "Orchid", "Hibiscus", "Bougainvillea", "Violets",
        "Berry Bush", "Garden", "Plot", "Crop", "Pot", "Planter", "Stump", "Log",
        "Water", "Reed", "Cattail", "Lilypad"
    ];

    private static readonly HashSet<uint> EvergreenExcludeGuids =
    [
        0x39319021u, 0x07CFB214u, 0x58EBC469u, 0x9B2BD5C3u, 0xECD28B8Eu, 0x5F421524u,
        0xBD9E1D34u, 0x9F9D7688u, 0xFCDE3114u, 0xDB4B0721u, 0x8BA56284u, 0xF7194FE6u,
        0xD1743863u, 0x358D29CEu, 0x1748778Eu, 0x51474702u, 0xB7AF202Bu, 0x90CB0721u,
        0xFE560D63u, 0xD987287Eu, 0x3026A0F4u, 0x3026B863u, 0x3026C759u, 0x3026E8FEu,
        0x3026EA3Cu, 0xAA86AD2Au, 0xF140D974u, 0xC15387ADu, 0x23F3DD6Cu, 0x03CDE481u,
        0x30078DCFu, 0x3007996Eu, 0x3007A790u, 0x3007C49Eu, 0x3007ED15u, 0xDE802250u,
        0xFD085D5Du, 0xDE3668E1u, 0xC5CE7914u, 0x10B32EB3u, 0x9DA7B210u, 0x99400B4Au,
        0x6A55E034u, 0x6A79CD51u, 0x6A67AB66u, 0x6A8BF51Eu, 0xA02C8857u, 0xD9BD21CDu,
        0xC3D369C9u, 0x373C3951u, 0x26A24677u, 0x01656B1Au, 0x678F09FFu, 0x67FB41F5u,
        0x64671168u, 0x64D26E52u, 0x653F4337u, 0x65AA34BAu, 0x62162500u, 0x62827B78u,
        0x62F16084u, 0x63615647u, 0x110CF4B1u, 0x0EDEB33Au, 0x0E908508u, 0x0E628AAFu,
        0x0E348B13u, 0xD17F1085u, 0xFB0E28E7u, 0x127428BCu, 0x4676293Fu, 0x5EDC56E1u,
        0xB9020120u, 0xE049759Au, 0xF89E2350u, 0x16AE22EEu, 0x335E4B40u, 0xF9E11D1Cu,
        0x9249249Fu, 0x7E213927u, 0x92473548u, 0xAB0422E6u, 0xBEB34678u, 0xD27A1F32u,
        0xE55470A2u, 0xFA5637A8u, 0x82960603u, 0x89BC1085u, 0xA8D128E7u, 0xC60128BCu,
        0xBB83A08Au, 0xD68E73D8u, 0xF2999F51u, 0x5359BFC1u, 0x3C52B66Du, 0xC3EFD759u,
        0x1181CCB1u, 0x4B4D30A9u, 0xDC0BEF65u, 0xA9648B31u, 0x6961DA94u, 0x5A3A9DB8u,
        0x4B60CC69u, 0x154522AFu, 0x15460FCAu, 0x0EB692FBu, 0xAED3C88Au, 0x72BDBB7Du,
        0x11EC66D9u, 0x52ED4B7Cu, 0x34431396u, 0xE4FB60EBu, 0xE48328E1u, 0xE482787Cu,
        0xE48D0746u, 0xE48C2A23u, 0xD6272E40u, 0x302E3939u, 0x7C24A376u, 0xE9693F98u,
        0x17332210u, 0x15316867u, 0x15445522u, 0xAD12E0D0u, 0x9AE018BBu, 0xAF4A1300u,
        0xE5293E72u, 0x78EDCD25u, 0xFF97BA8Fu, 0x952BCAC7u, 0xF3CCCCBEu, 0xF3CA84B4u,
        0x984671A9u, 0x70FC19C3u, 0xFEE30120u, 0x8EB8E1A6u, 0xBC661500u, 0x54C3E0CFu,
        0xFA733902u, 0x6A6DBADCu, 0x10444309u, 0x2ABC6E73u
    ];

    private static DeciduousHabit ClassifyDeciduousFlora(bool isBuildFoliage, uint guid, string name)
    {
        if (EvergreenExcludeGuids.Contains(guid)) return DeciduousHabit.None;

        switch (guid)
        {
            case 0x5C198CBEu or 0x93DDE1F7u or 0x82998688u or 0xF200F110u or 0xE184A4DBu:
                return DeciduousHabit.Weeping;
            case 0x1468C3A7u or 0x8F89C3DDu or 0xC0C3E3ABu or 0x1182FF7Cu or 0x7B56A4E8u or 0xC99AC74Eu:
                return DeciduousHabit.Slender;
            case 0x2C555EA3u or 0xD5CA5425u or 0xB1153E7Du:
                return DeciduousHabit.Shrub;
            case 0x2B839414u or 0x2B83B971u or 0x2B85F3B9u or 0x2B82BBB3u or 0x2B82EB2Eu or 0x09D8DCECu
                or 0x5CDAF13Au or 0x4C9BFBFDu or 0xA5379F60u or 0x9610DC23u or 0x440087F3u or 0xAF169672u
                or 0x81BCC800u or 0xEB10D3E6u or 0xDD96E529u or 0x3484C1F7u or 0x0857B671u or 0x5764E8AFu
                or 0xA17EB26Au or 0xFC528B7Du or 0x1671A218u or 0x00DD7908u or 0xAC66D6CAu or 0x15A2A7B0u
                or 0xB612B0D6u or 0xFAA5BC18u or 0x39B3CEF6u or 0x2FA784C3u or 0x18F3A440u or 0x0E52DC52u
                or 0x77D0B84Bu or 0x5FDB844Fu or 0x6854DA61u or 0x68F0926Bu or 0x6B62C2F6u or 0x6BFFBDCCu
                or 0x6A8AE725u or 0x6526F69Fu or 0x6549A8E7u or 0x65ECB31Bu or 0x640985D9u or 0xCEB2F9B8u
                or 0xBDECFE70u or 0x4498AD77u or 0x1C57A3B7u or 0xC4D089B2u or 0x6382888Du or 0x9CC2AA86u
                or 0x1AA2F18Cu or 0xFE21991Au or 0x05FF8522u or 0x6A6D90A8u:
                return DeciduousHabit.Spreading;
        }


        if (!isBuildFoliage || string.IsNullOrWhiteSpace(name))
            return DeciduousHabit.None;

        for (int i = 0; i < EvergreenExcludeKeywords.Length; i++)
        {
            if (name.Contains(EvergreenExcludeKeywords[i], StringComparison.OrdinalIgnoreCase))
                return DeciduousHabit.None;
        }

        if (name.Contains("Willow", StringComparison.OrdinalIgnoreCase))
            return DeciduousHabit.Weeping;
        if (name.Contains("Birch", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Poplar", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Aspen", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Ginkgo", StringComparison.OrdinalIgnoreCase))
            return DeciduousHabit.Slender;
        if (name.Contains("Shrub", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Bush", StringComparison.OrdinalIgnoreCase))
            return DeciduousHabit.Shrub;
        if (name.Contains("Tree", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Maple", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Oak", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Sycamore", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Elm", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Apple", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Cherry", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Plum", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Prune", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Mulberry", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Walnut", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Hickory", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Chestnut", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Ash", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Beech", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Linden", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Dogwood", StringComparison.OrdinalIgnoreCase) ||
            name.Contains("Sweetgum", StringComparison.OrdinalIgnoreCase))
            return DeciduousHabit.Spreading;

        return DeciduousHabit.None;
    }


    public int SpriteVariant => CurrentFoliageStage();

    public bool SelectsObject(PluginObjectSpriteMember candidate) =>
        candidate.Outside && ClassifyDeciduousFlora(candidate.IsBuildFoliage, candidate.Guid, candidate.Name) != DeciduousHabit.None;

    public IReadOnlyList<PluginObjectSpriteOverride?>? TransformObjectGroup(
        int cameraOrientation,
        IReadOnlyList<PluginObjectSpriteMember> members,
        IReadOnlyList<PluginObjectSpritePart> parts)
    {
        int foliageStage = CurrentFoliageStage();
        if (foliageStage <= 0 || members.Count == 0 || parts.Count == 0)
            return null;

        bool allSheltered = true;
        DeciduousHabit groupHabit = DeciduousHabit.Spreading;
        for (int i = 0; i < members.Count; i++)
        {
            if (!members[i].Sheltered) allSheltered = false;
            var habit = ClassifyDeciduousFlora(members[i].IsBuildFoliage, members[i].Guid, members[i].Name);
            if (habit is DeciduousHabit.Weeping or DeciduousHabit.Slender or DeciduousHabit.Shrub)
                groupHabit = habit;
        }
        if (allSheltered)
            return null;

        var baseOrigin = members[0].Origin;
        var sigParts = new string[members.Count];
        for (int i = 0; i < members.Count; i++)
        {
            var m = members[i];
            int dx16 = (int)MathF.Round((m.Origin.X - baseOrigin.X) * 16f);
            int dy16 = (int)MathF.Round((m.Origin.Y - baseOrigin.Y) * 16f);
            sigParts[i] = $"{m.Guid:x8}:{dx16},{dy16}:{m.Direction}:{m.Graphic}";
        }
        var cacheKey = new TreeSynthesisCacheKey(string.Join("|", sigParts), cameraOrientation, foliageStage);
        if (witheredTreeCache.Count > 512)
            witheredTreeCache.Clear();

        return witheredTreeCache.GetOrAdd(cacheKey, _ => SynthesizeGroup(parts, groupHabit, foliageStage, members[0].Guid));
    }

    private static PluginObjectSpriteOverride?[] SynthesizeGroup(IReadOnlyList<PluginObjectSpritePart> parts, DeciduousHabit habit, int stage, uint seedGuid)
    {
        var outputs = new PluginObjectSpriteOverride?[parts.Count];
        int minX = int.MaxValue, minY = int.MaxValue, maxX = int.MinValue, maxY = int.MinValue;
        for (int i = 0; i < parts.Count; i++)
        {
            var p = parts[i];
            if (p.NearX < minX) minX = p.NearX;
            if (p.NearY < minY) minY = p.NearY;
            if (p.NearX + p.NearW > maxX) maxX = p.NearX + p.NearW;
            if (p.NearY + p.NearH > maxY) maxY = p.NearY + p.NearH;
        }
        minX -= 8;
        minY -= 8;
        maxX += 8;
        maxY += 8;
        int W = maxX - minX;
        int H = maxY - minY;
        if (W < 12 || H < 14 || W > 1024 || H > 1024)
            return outputs;

        var origRgba = new byte[W * H * 4];
        var origZ = new float[W * H];
        Array.Fill(origZ, 1e9f);
        var canopyMask = new bool[W * H];
        var barkMask = new bool[W * H];

        int silLeft = W, silRight = 0, silTop = H, silBottom = 0;
        int greenPixelCount = 0;

        for (int pi = 0; pi < parts.Count; pi++)
        {
            var p = parts[pi];
            float dSpan = MathF.Max(1e-6f, p.DepthFar - p.DepthNear);
            for (int y = 0; y < p.NearH; y++)
            {
                int dy = p.NearY - minY + y;
                for (int x = 0; x < p.NearW; x++)
                {
                    int srcX = p.Flip ? (p.NearW - 1 - x) : x;
                    int si = (y * p.NearW + srcX) * 4;
                    byte a = p.NearRgba[si + 3];
                    if (a == 0) continue;
                    byte r = p.NearRgba[si];
                    byte g = p.NearRgba[si + 1];
                    byte b = p.NearRgba[si + 2];
                    float zNorm = p.NearDepth is not null ? p.NearDepth[y * p.NearW + srcX] / 255f : 0.5f;
                    float zWorld = p.DepthNear + zNorm * dSpan;

                    int dx = p.NearX - minX + x;
                    int di = dy * W + dx;
                    if (zWorld <= origZ[di] || origRgba[di * 4 + 3] < 64)
                    {
                        if (a >= 110) origZ[di] = zWorld;
                        origRgba[di * 4] = r;
                        origRgba[di * 4 + 1] = g;
                        origRgba[di * 4 + 2] = b;
                        origRgba[di * 4 + 3] = a;
                        if (a >= 72)
                        {
                            canopyMask[di] = true;
                            if (dx < silLeft) silLeft = dx;
                            if (dx > silRight) silRight = dx;
                            if (dy < silTop) silTop = dy;
                            if (dy > silBottom) silBottom = dy;
                            bool isBark = g <= r * 1.07f + 6f && r >= b && (r + g + b) > 68;
                            barkMask[di] = isBark;
                            if (!isBark && g > r + 6) greenPixelCount++;
                        }
                    }
                }
            }
        }

        int silW = silRight - silLeft + 1;
        int silH = silBottom - silTop + 1;
        if (silW < 10 || silH < 12 || greenPixelCount < 24)
            return outputs;

        var crownEnvelope = new bool[W * H];
        var rawLeft = new int[H];
        var rawRight = new int[H];
        Array.Fill(rawLeft, W);
        Array.Fill(rawRight, -1);
        for (int y = silTop; y <= silBottom; y++)
        {
            for (int x = silLeft; x <= silRight; x++)
            {
                if (!canopyMask[y * W + x]) continue;
                if (x < rawLeft[y]) rawLeft[y] = x;
                if (x > rawRight[y]) rawRight[y] = x;
            }
        }
        for (int y = silTop; y <= silBottom; y++)
        {
            int lo = W, hi = -1;
            int winMin = Math.Max(silTop, y - 5);
            int winMax = Math.Min(silBottom, y + 5);
            for (int wy = winMin; wy <= winMax; wy++)
            {
                if (rawRight[wy] < rawLeft[wy]) continue;
                if (rawLeft[wy] < lo) lo = rawLeft[wy];
                if (rawRight[wy] > hi) hi = rawRight[wy];
            }
            if (hi >= lo)
            {
                int inset = hi - lo > 8 ? 2 : 0;
                for (int x = lo + inset; x <= hi - inset; x++)
                    crownEnvelope[y * W + x] = true;
            }
        }

        int baseZoneTop = Math.Max(silTop + silH * 2 / 3, silBottom - Math.Max(14, silH / 4));
        var baseBark = new List<(int X, int Y, byte R, byte G, byte B, float Z)>();
        for (int y = baseZoneTop; y <= silBottom; y++)
        {
            for (int x = silLeft; x <= silRight; x++)
            {
                int di = y * W + x;
                if (barkMask[di] && origZ[di] < 1e8f)
                    baseBark.Add((x, y, origRgba[di * 4], origRgba[di * 4 + 1], origRgba[di * 4 + 2], origZ[di]));
            }
        }

        float rootX;
        int trunkCleanY;
        float centerZ;
        Vector3 shadowRgb = new(62f, 58f, 46f);
        Vector3 midRgb = new(98f, 92f, 74f);
        Vector3 litRgb = new(144f, 136f, 110f);
        float baseTrunkHalfW;

        if (habit != DeciduousHabit.Shrub && baseBark.Count >= 12)
        {
            int minBx = int.MaxValue, maxBx = int.MinValue;
            float sumX = 0f;
            for (int i = 0; i < baseBark.Count; i++)
            {
                sumX += baseBark[i].X;
                if (baseBark[i].X < minBx) minBx = baseBark[i].X;
                if (baseBark[i].X > maxBx) maxBx = baseBark[i].X;
            }
            rootX = sumX / baseBark.Count;

            trunkCleanY = baseZoneTop;
            for (int y = silBottom - 4; y >= silTop + silH / 3; y--)
            {
                int greenRow = 0;
                for (int x = silLeft; x <= silRight; x++)
                {
                    int di = y * W + x;
                    if (canopyMask[di] && !barkMask[di]) greenRow++;
                }
                if (greenRow > 2)
                {
                    trunkCleanY = Math.Min(silBottom - 4, y + 3);
                    break;
                }
            }

            var topRowXs = new List<int>();
            for (int i = 0; i < baseBark.Count; i++)
            {
                if (Math.Abs(baseBark[i].Y - trunkCleanY) <= 4)
                    topRowXs.Add(baseBark[i].X);
            }
            if (topRowXs.Count >= 2)
            {
                topRowXs.Sort();
                rootX = 0.5f * (topRowXs[topRowXs.Count / 6] + topRowXs[topRowXs.Count * 5 / 6]);
                baseTrunkHalfW = Math.Clamp((topRowXs[^1] - topRowXs[0]) * 0.46f, 2.2f, Math.Max(3.5f, silW * 0.055f));
            }
            else
            {
                baseTrunkHalfW = Math.Clamp(silW * 0.038f, 2.4f, 7.0f);
            }

            var zs = new float[baseBark.Count];
            for (int i = 0; i < baseBark.Count; i++) zs[i] = baseBark[i].Z;
            Array.Sort(zs);
            centerZ = zs[zs.Length / 2];

            baseBark.Sort(static (a, b) => (a.R + a.G + a.B).CompareTo(b.R + b.G + b.B));
            int n = baseBark.Count;
            shadowRgb = AverageSlice(baseBark, 0, Math.Max(1, n / 4));
            midRgb = AverageSlice(baseBark, n * 3 / 8, Math.Max(n * 3 / 8 + 1, n * 5 / 8));
            litRgb = AverageSlice(baseBark, n * 3 / 4, n);
            shadowRgb = Vector3.Clamp(shadowRgb, new Vector3(36f, 32f, 24f), new Vector3(135f, 130f, 120f));
            litRgb = Vector3.Max(litRgb, midRgb + new Vector3(22f, 20f, 16f));
            litRgb = Vector3.Clamp(litRgb, new Vector3(85f, 80f, 65f), new Vector3(215f, 210f, 198f));
        }
        else
        {
            rootX = (silLeft + silRight) * 0.5f;
            trunkCleanY = silBottom - 2;
            baseTrunkHalfW = habit == DeciduousHabit.Shrub
                ? Math.Clamp(silW * 0.028f, 1.1f, 2.2f)
                : Math.Clamp(silW * 0.036f, 2.2f, 6.2f);

            var allZs = new List<float>(256);
            for (int i = 0; i < origZ.Length; i++)
                if (origZ[i] < 1e8f) allZs.Add(origZ[i]);
            allZs.Sort();
            centerZ = allZs.Count > 0 ? allZs[allZs.Count / 2] : 0.5f;

            if (habit == DeciduousHabit.Slender)
            {
                shadowRgb = new Vector3(92f, 88f, 80f);
                midRgb = new Vector3(138f, 133f, 122f);
                litRgb = new Vector3(186f, 180f, 168f);
            }
        }

        var skelRgba = new byte[W * H * 4];
        var skelZ = new float[W * H];
        Array.Fill(skelZ, 1e9f);

        (byte R, byte G, byte B) BarkColor(float crossT, float tangX, float tangY, int gx, int gy, float rad)
        {
            float perpX = -tangY, perpY = tangX;
            if (perpX < 0f) { perpX = -perpX; perpY = -perpY; }
            float nz = MathF.Sqrt(MathF.Max(0.06f, 1f - crossT * crossT));
            float nx = perpX * crossT;
            float ny = perpY * crossT;
            float ndotl = nx * 0.76f - ny * 0.34f + nz * 0.55f;
            float grain = (MathF.Sin(gx * 2.1f + gy * 0.5f) + MathF.Sin(gx * 4.7f - gy * 0.9f)) * 0.045f;
            float twigWarm = Math.Clamp(0.84f + 0.16f * (rad / 2.2f), 0.84f, 1.0f);
            float lit = Math.Clamp(0.46f + 0.52f * ndotl + grain, 0f, 1f);
            Vector3 c = lit < 0.5f
                ? Vector3.Lerp(shadowRgb, midRgb, lit * 2f)
                : Vector3.Lerp(midRgb, litRgb, (lit - 0.5f) * 2f);
            c *= twigWarm;
            return (
                (byte)Math.Clamp((int)MathF.Round(c.X), 0, 255),
                (byte)Math.Clamp((int)MathF.Round(c.Y), 0, 255),
                (byte)Math.Clamp((int)MathF.Round(c.Z), 0, 255));
        }

        void DrawSegment(float x0, float y0, float z0, float r0, float x1, float y1, float z1, float r1, bool clipCanopy)
        {
            float dx = x1 - x0, dy = y1 - y0;
            float segLen = MathF.Sqrt(dx * dx + dy * dy);
            if (segLen < 1e-4f) return;
            int pad = (int)MathF.Ceiling(MathF.Max(r0, r1) + 1.4f);
            int bx0 = Math.Max(1, (int)MathF.Floor(MathF.Min(x0, x1)) - pad);
            int bx1 = Math.Min(W - 2, (int)MathF.Ceiling(MathF.Max(x0, x1)) + pad);
            int by0 = Math.Max(1, (int)MathF.Floor(MathF.Min(y0, y1)) - pad);
            int by1 = Math.Min(H - 2, (int)MathF.Ceiling(MathF.Max(y0, y1)) + pad);
            float invL2 = 1f / (segLen * segLen);
            float ux = dx / segLen, uy = dy / segLen;
            float perpX = -uy, perpY = ux;
            if (perpX < 0f) { perpX = -perpX; perpY = -perpY; }

            for (int py = by0; py <= by1; py++)
            {
                for (int px = bx0; px <= bx1; px++)
                {
                    int di = py * W + px;
                    if (clipCanopy && py < trunkCleanY - 10 && !crownEnvelope[di])
                        continue;

                    float t = Math.Clamp(((px - x0) * dx + (py - y0) * dy) * invL2, 0f, 1f);
                    float cx = x0 + dx * t;
                    float cy = y0 + dy * t;
                    float rad = MathF.Max(0.46f, r0 + (r1 - r0) * t);
                    float dist = MathF.Sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy));

                    const float aaHalfWidth = 0.85f;
                    if (dist >= rad + aaHalfWidth) continue;

                    float solidCore = MathF.Max(0f, rad - 0.55f);
                    byte aNew;
                    if (solidCore > 0f && dist <= solidCore)
                    {
                        aNew = 255;
                    }
                    else
                    {
                        float uEdge = Math.Clamp((rad + aaHalfWidth - dist) / MathF.Max(0.35f, rad + aaHalfWidth - solidCore), 0f, 1f);
                        float smoothCov = uEdge * uEdge * (3f - 2f * uEdge);
                        if (rad < 0.80f)
                            smoothCov *= 0.68f + 0.32f * (rad / 0.80f);
                        int mapped = (int)MathF.Round(smoothCov * 255f);
                        if (mapped < 4) continue;
                        aNew = (byte)Math.Min(solidCore > 0f ? 248 : 240, mapped);
                    }

                    float crossT = Math.Clamp(((px - cx) * perpX + (py - cy) * perpY) / MathF.Max(0.46f, rad), -1f, 1f);
                    var (cr, cg, cb) = BarkColor(crossT, ux, uy, px, py, rad);
                    float pz = z0 + (z1 - z0) * t - 0.0002f * MathF.Sqrt(MathF.Max(0f, 1f - crossT * crossT));

                    byte oldA = skelRgba[di * 4 + 3];
                    if (oldA == 0)
                    {
                        skelRgba[di * 4] = cr;
                        skelRgba[di * 4 + 1] = cg;
                        skelRgba[di * 4 + 2] = cb;
                        skelRgba[di * 4 + 3] = aNew;
                        skelZ[di] = pz;
                    }
                    else if (aNew == 255 && oldA == 255)
                    {
                        if (pz <= skelZ[di] + 0.0004f)
                        {
                            skelRgba[di * 4] = cr;
                            skelRgba[di * 4 + 1] = cg;
                            skelRgba[di * 4 + 2] = cb;
                            skelZ[di] = MathF.Min(skelZ[di], pz);
                        }
                    }
                    else
                    {
                        bool newInFront = pz <= skelZ[di] + 0.0004f;
                        float fA = (newInFront ? aNew : oldA) / 255f;
                        float bA = (newInFront ? oldA : aNew) / 255f;
                        float outA = fA + bA * (1f - fA);
                        if (outA > 1e-4f)
                        {
                            float wF = fA / outA;
                            float wB = (bA * (1f - fA)) / outA;
                            byte fR = newInFront ? cr : skelRgba[di * 4];
                            byte fG = newInFront ? cg : skelRgba[di * 4 + 1];
                            byte fB = newInFront ? cb : skelRgba[di * 4 + 2];
                            byte bR = newInFront ? skelRgba[di * 4] : cr;
                            byte bG = newInFront ? skelRgba[di * 4 + 1] : cg;
                            byte bB = newInFront ? skelRgba[di * 4 + 2] : cb;
                            skelRgba[di * 4] = (byte)Math.Clamp((int)MathF.Round(fR * wF + bR * wB), 0, 255);
                            skelRgba[di * 4 + 1] = (byte)Math.Clamp((int)MathF.Round(fG * wF + bG * wB), 0, 255);
                            skelRgba[di * 4 + 2] = (byte)Math.Clamp((int)MathF.Round(fB * wF + bB * wB), 0, 255);
                            skelRgba[di * 4 + 3] = (byte)Math.Clamp((int)MathF.Round(outA * 255f), 1, 255);
                            if (newInFront && aNew >= 80)
                                skelZ[di] = MathF.Min(skelZ[di], pz);
                        }
                    }
                }
            }
        }

        void DrawCurve(IReadOnlyList<(float X, float Y, float Z, float R)> pts, bool clip = true)
        {
            for (int i = 0; i < pts.Count - 1; i++)
                DrawSegment(pts[i].X, pts[i].Y, pts[i].Z, pts[i].R, pts[i + 1].X, pts[i + 1].Y, pts[i + 1].Z, pts[i + 1].R, clip);
        }

        var rng = new DeterministicRng(seedGuid ^ 0x9E3779B9u);
        var whipAnchors = new List<(float X, float Y, float Z, float Angle, float Rad)>();
        float canopyH = MathF.Max(14f, trunkCleanY - silTop);
        float sizeScale = canopyH / 165f;

        void GrowLimb(float x, float y, float z, float angle, float length, float rStart, float rEnd, int depth, float droopGain, int maxDepth)
        {
            float stepSize = Math.Clamp(2.4f * MathF.Max(0.55f, sizeScale), 1.3f, 3.0f);
            int steps = Math.Max(4, (int)MathF.Round(length / stepSize));
            float ds = length / steps;
            var pts = new List<(float X, float Y, float Z, float R)>(steps + 1) { (x, y, z, rStart) };
            float cx = x, cy = y, cz = z, curA = angle;
            float wobblePhase = rng.NextFloat() * 6.283185f;
            int forkEvery = Math.Max(2, steps / 3);

            for (int s = 1; s <= steps; s++)
            {
                float u = s / (float)steps;
                float horiz = MathF.Sin(curA);
                curA += horiz * droopGain * ds + MathF.Sin(u * 4.5f + wobblePhase) * 0.045f;
                float nx = cx + MathF.Sin(curA) * ds;
                float ny = cy - MathF.Cos(curA) * ds;
                float nz = cz + (rng.NextFloat() - 0.5f) * 0.0004f;
                int ix = (int)MathF.Round(nx), iy = (int)MathF.Round(ny);
                if (ix < 2 || ix >= W - 2 || iy < 2 || iy >= H - 2) break;
                if (iy < trunkCleanY - 10 && !crownEnvelope[iy * W + ix] && s > 2) break;

                float rad = rStart * MathF.Pow(rEnd / MathF.Max(0.15f, rStart), MathF.Pow(u, 0.85f));
                cx = nx; cy = ny; cz = nz;
                pts.Add((cx, cy, cz, rad));

                if (depth < maxDepth && u is >= 0.26f and <= 0.84f && s % forkEvery == 0)
                {
                    float side = ((s / forkEvery) & 1) == 0 ? 1f : -1f;
                    if (MathF.Abs(horiz) > 0.45f && rng.NextFloat() < 0.62f)
                        side = horiz > 0f ? 1f : -1f;
                    float spreadMin = habit == DeciduousHabit.Slender ? 0.24f : 0.34f;
                    float spreadMax = habit == DeciduousHabit.Slender ? 0.44f : 0.62f;
                    float forkA = curA + side * rng.Range(spreadMin, spreadMax);
                    float subR0 = rad * rng.Range(0.58f, 0.72f);
                    float subR1 = MathF.Max(0.46f, subR0 * 0.40f);
                    float subLen = length * (1f - u * 0.42f) * rng.Range(0.50f, 0.74f);
                    GrowLimb(cx, cy, cz + side * 0.0007f, forkA, subLen, subR0, subR1, depth + 1, droopGain * 1.35f, maxDepth);
                }

                if (habit == DeciduousHabit.Weeping && depth >= 1 && rad <= 1.55f && u >= 0.42f && rng.NextFloat() < 0.48f)
                    whipAnchors.Add((cx, cy, cz, curA, rad));
            }

            DrawCurve(pts);
            if (habit == DeciduousHabit.Weeping && pts.Count >= 2)
                whipAnchors.Add((cx, cy, cz, curA, pts[^1].R));

            if (depth < maxDepth && pts.Count >= steps)
            {
                float endR = pts[^1].R;
                for (int sideIdx = 0; sideIdx < 2; sideIdx++)
                {
                    float side = sideIdx == 0 ? -1f : 1f;
                    float fa = curA + side * rng.Range(0.26f, 0.48f);
                    GrowLimb(cx, cy, cz + side * 0.0005f, fa, length * rng.Range(0.42f, 0.58f),
                        endR * 0.74f, MathF.Max(0.46f, endR * 0.38f), depth + 1, droopGain * 1.4f, maxDepth);
                }
            }
        }

        if (habit == DeciduousHabit.Shrub)
        {
            float baseY = Math.Min(H - 3, silBottom - 2);
            float[] stemAngles = [-0.95f, -0.58f, -0.24f, 0.06f, 0.34f, 0.66f, 0.98f];
            for (int i = 0; i < stemAngles.Length; i++)
            {
                float sx = rootX + (i - 3) * MathF.Max(0.8f, silW * 0.04f);
                float a = stemAngles[i] + rng.Range(-0.08f, 0.08f);
                float len = MathF.Max(10f, silH * rng.Range(0.58f, 0.82f));
                GrowLimb(sx, baseY, centerZ + (i - 3) * 0.0004f, a, len, baseTrunkHalfW, 0.48f, 1, 0.010f, 3);
            }
        }
        else
        {
            float spineReach = habit == DeciduousHabit.Slender ? 0.76f : 0.58f;
            float spineTopY = trunkCleanY - canopyH * spineReach;
            var spine = new List<(float X, float Y, float Z, float R)>(7);
            for (int i = 0; i <= 6; i++)
            {
                float u = i / 6f;
                float sy = (trunkCleanY + 5f) + (spineTopY - (trunkCleanY + 5f)) * u;
                float wobbleX = MathF.Sin(u * 3.6f + (seedGuid & 7)) * MathF.Max(0.6f, 1.4f * sizeScale);
                float sr = baseTrunkHalfW * (1f - 0.62f * u);
                spine.Add((rootX + wobbleX, sy, centerZ - 0.0006f * u, MathF.Max(0.9f, sr)));
            }
            DrawCurve(spine, clip: false);

            float droop = habit switch
            {
                DeciduousHabit.Weeping => 0.020f / MathF.Max(0.55f, sizeScale),
                DeciduousHabit.Slender => 0.004f / MathF.Max(0.55f, sizeScale),
                _ => 0.009f / MathF.Max(0.55f, sizeScale),
            };

            ReadOnlySpan<(float FracH, float Angle, float LenFrac, float RadFrac)> template = habit == DeciduousHabit.Slender
                ? [
                    (0.14f, -0.52f, 0.42f, 0.44f),
                    (0.20f,  0.50f, 0.42f, 0.44f),
                    (0.34f, -0.44f, 0.48f, 0.46f),
                    (0.40f,  0.42f, 0.50f, 0.46f),
                    (0.54f, -0.34f, 0.46f, 0.40f),
                    (0.58f,  0.34f, 0.46f, 0.40f),
                    (0.74f, -0.18f, 0.38f, 0.34f),
                    (0.76f,  0.16f, 0.38f, 0.34f),
                  ]
                : [
                    (0.12f, -0.78f, 0.46f, 0.46f),
                    (0.17f,  0.74f, 0.44f, 0.44f),
                    (0.30f, -0.58f, 0.56f, 0.52f),
                    (0.35f,  0.56f, 0.58f, 0.54f),
                    (0.48f, -0.38f, 0.54f, 0.42f),
                    (0.52f,  0.38f, 0.54f, 0.42f),
                    (0.58f,  0.10f, 0.50f, 0.38f),
                    (0.57f, -0.20f, 0.46f, 0.34f),
                  ];

            float refSpan = MathF.Max(canopyH * 0.58f, silW * 0.52f);
            for (int i = 0; i < template.Length; i++)
            {
                var (fh, ang, lf, rf) = template[i];
                float sy = trunkCleanY - canopyH * fh;
                float sx = rootX + MathF.Sin(fh * 6f + (seedGuid & 7)) * 0.8f;
                float r0 = MathF.Max(0.85f, baseTrunkHalfW * rf);
                float r1 = MathF.Max(0.48f, r0 * 0.30f);
                float zOff = ((i & 1) == 0 ? 1f : -1f) * 0.0009f;
                GrowLimb(sx, sy, centerZ + zOff, ang + rng.Range(-0.05f, 0.05f), refSpan * lf, r0, r1, 1, droop, 3);
            }

            if (habit == DeciduousHabit.Weeping)
            {
                float stepD = Math.Clamp(2.0f * MathF.Max(0.6f, sizeScale), 1.2f, 2.2f);
                for (int i = 0; i < whipAnchors.Count; i++)
                {
                    if (rng.NextFloat() > 0.56f) continue;
                    var (wx, wy, wz, wang, wrad) = whipAnchors[i];
                    int whipSteps = rng.RangeInt(8, 17);
                    float w0 = Math.Clamp(wrad * 0.62f, 0.48f, 0.62f);
                    var pts = new List<(float X, float Y, float Z, float R)>(whipSteps + 1) { (wx, wy, wz + 0.0004f, w0) };
                    float cx = wx, cy = wy;
                    float vx = MathF.Sin(wang) * 1.15f + (wx >= rootX ? 0.25f : -0.25f);
                    float vy = -MathF.Cos(wang) * 0.75f;
                    float sway = rng.Range(-0.10f, 0.10f);
                    for (int s = 1; s <= whipSteps; s++)
                    {
                        vx = vx * 0.84f + sway * 0.15f;
                        vy = vy * 0.78f + 0.78f;
                        float vlen = MathF.Max(1e-4f, MathF.Sqrt(vx * vx + vy * vy));
                        cx += vx / vlen * stepD;
                        cy += vy / vlen * stepD;
                        int ix = (int)MathF.Round(cx), iy = (int)MathF.Round(cy);
                        if (ix < 3 || ix >= W - 3 || iy < 4 || iy >= Math.Max(8, trunkCleanY - 4) || !crownEnvelope[iy * W + ix])
                            break;
                        pts.Add((cx, cy, wz + 0.0004f, MathF.Max(0.46f, w0 * (1f - 0.22f * s / whipSteps))));
                    }
                    if (pts.Count >= 4)
                        DrawCurve(pts, clip: true);
                }
            }
        }

        if (habit != DeciduousHabit.Shrub)
        {
            int blendTop = Math.Max(0, trunkCleanY - 4);
            for (int y = blendTop; y < H; y++)
            {
                float wReal = Math.Clamp((y - blendTop) / 8f, 0f, 1f);
                for (int x = 0; x < W; x++)
                {
                    int di = y * W + x;
                    byte oa = origRgba[di * 4 + 3];
                    if (oa < 8) continue;
                    bool edgeBark = barkMask[di];
                    if (!edgeBark && oa < 220 && x > 0 && x < W - 1 && y > 0 && y < H - 1)
                    {
                        edgeBark = barkMask[di - 1] || barkMask[di + 1] || barkMask[di - W] || barkMask[di + W];
                    }
                    if (!edgeBark) continue;
                    byte r = origRgba[di * 4], g = origRgba[di * 4 + 1], b = origRgba[di * 4 + 2];
                    byte sa = skelRgba[di * 4 + 3];
                    if (sa == 0 || wReal >= 0.99f)
                    {
                        skelRgba[di * 4] = r;
                        skelRgba[di * 4 + 1] = g;
                        skelRgba[di * 4 + 2] = b;
                        skelRgba[di * 4 + 3] = oa;
                        if (origZ[di] < 1e8f)
                            skelZ[di] = origZ[di];
                    }
                    else
                    {
                        skelRgba[di * 4] = (byte)MathF.Round(skelRgba[di * 4] * (1f - wReal) + r * wReal);
                        skelRgba[di * 4 + 1] = (byte)MathF.Round(skelRgba[di * 4 + 1] * (1f - wReal) + g * wReal);
                        skelRgba[di * 4 + 2] = (byte)MathF.Round(skelRgba[di * 4 + 2] * (1f - wReal) + b * wReal);
                        skelRgba[di * 4 + 3] = (byte)MathF.Round(sa * (1f - wReal) + oa * wReal);
                    }
                }
            }
        }

        var compRgba = skelRgba;
        var compZ = skelZ;

        if (stage is >= 1 and < MaxFoliageStage)
        {
            compRgba = (byte[])skelRgba.Clone();
            compZ = (float[])skelZ.Clone();
            var (thresh, tetherWeight) = stage switch
            {
                1 => (0.217f, 0.000f),
                2 => (0.285f, 0.010f),
                3 => (0.337f, 0.025f),
                4 => (0.387f, 0.040f),
                5 => (0.431f, 0.060f),
                6 => (0.475f, 0.085f),
                7 => (0.533f, 0.115f),
                _ => (0.604f, 0.145f),
            };

            ushort[]? branchDist = null;
            if (tetherWeight > 0f)
            {
                branchDist = new ushort[W * H];
                for (int i = 0; i < branchDist.Length; i++)
                    branchDist[i] = skelRgba[i * 4 + 3] >= 68 ? (ushort)0 : (ushort)1000;
                for (int y = 1; y < H; y++)
                {
                    int row = y * W;
                    for (int x = 1; x < W - 1; x++)
                    {
                        int d = branchDist[row + x];
                        if (d == 0) continue;
                        int best = branchDist[row - W + x] + 3;
                        int dl = branchDist[row + x - 1] + 3;
                        if (dl < best) best = dl;
                        int dtl = branchDist[row - W + x - 1] + 4;
                        if (dtl < best) best = dtl;
                        int dtr = branchDist[row - W + x + 1] + 4;
                        if (dtr < best) best = dtr;
                        if (best < d) branchDist[row + x] = (ushort)best;
                    }
                }
                for (int y = H - 2; y >= 0; y--)
                {
                    int row = y * W;
                    for (int x = W - 2; x >= 1; x--)
                    {
                        int d = branchDist[row + x];
                        if (d == 0) continue;
                        int best = branchDist[row + W + x] + 3;
                        int dr = branchDist[row + x + 1] + 3;
                        if (dr < best) best = dr;
                        int dbl = branchDist[row + W + x - 1] + 4;
                        if (dbl < best) best = dbl;
                        int dbr = branchDist[row + W + x + 1] + 4;
                        if (dbr < best) best = dbr;
                        if (best < d) branchDist[row + x] = (ushort)best;
                    }
                }
            }

            static float SmoothStep01(float e0, float e1, float v)
            {
                float t = Math.Clamp((v - e0) / (e1 - e0), 0f, 1f);
                return t * t * (3f - 2f * t);
            }

            var rawGreen = new float[W * H];
            for (int i = 0; i < rawGreen.Length; i++)
            {
                byte oa = origRgba[i * 4 + 3];
                if (oa < 8 || barkMask[i]) continue;
                float r = origRgba[i * 4];
                float g = origRgba[i * 4 + 1];
                float b = origRgba[i * 4 + 2];
                float denom = MathF.Max(g, 10f);
                float blueAdv = (g - b) / denom;
                float redAdv = (g - r * 0.92f) / denom;
                rawGreen[i] = SmoothStep01(0.12f, 0.34f, blueAdv) * SmoothStep01(-0.10f, 0.12f, redAdv);
            }

            var rawLeafCov = new float[W * H];
            var cleanLeafRgb = new byte[W * H * 3];
            for (int y = 1; y < H - 1; y++)
            {
                int row = y * W;
                for (int x = 1; x < W - 1; x++)
                {
                    int di = row + x;
                    byte oa = origRgba[di * 4 + 3];
                    float r = origRgba[di * 4];
                    float g = origRgba[di * 4 + 1];
                    float b = origRgba[di * 4 + 2];

                    int strongGreenCount = 0;
                    float gSumR = 0f, gSumG = 0f, gSumB = 0f, gSumW = 0f;
                    int y0 = Math.Max(0, y - 2), y1 = Math.Min(H - 1, y + 2);
                    int x0 = Math.Max(0, x - 2), x1 = Math.Min(W - 1, x + 2);
                    for (int ny = y0; ny <= y1; ny++)
                    {
                        int dy = ny - y;
                        for (int nx = x0; nx <= x1; nx++)
                        {
                            int dx = nx - x;
                            int r2 = dx * dx + dy * dy;
                            if (r2 == 0 || r2 > 5) continue;
                            int ni = ny * W + nx;
                            byte na = origRgba[ni * 4 + 3];
                            float ng = rawGreen[ni];
                            if (na >= 150 && ng >= 0.55f)
                            {
                                if (r2 <= 2) strongGreenCount++;
                                float w = ng * (na / 255f) / r2;
                                gSumR += origRgba[ni * 4] * w;
                                gSumG += origRgba[ni * 4 + 1] * w;
                                gSumB += origRgba[ni * 4 + 2] * w;
                                gSumW += w;
                            }
                        }
                    }

                    if (oa < 8 || barkMask[di])
                    {
                        if (gSumW > 0f)
                        {
                            cleanLeafRgb[di * 3] = (byte)Math.Clamp((int)MathF.Round(gSumR / gSumW), 0, 255);
                            cleanLeafRgb[di * 3 + 1] = (byte)Math.Clamp((int)MathF.Round(gSumG / gSumW), 0, 255);
                            cleanLeafRgb[di * 3 + 2] = (byte)Math.Clamp((int)MathF.Round(gSumB / gSumW), 0, 255);
                        }
                        continue;
                    }

                    float rg = rawGreen[di];
                    if (rg >= 0.5f)
                    {
                        rawLeafCov[di] = (oa / 255f) * SmoothStep01(0.35f, 0.72f, rg);
                        if (oa < 236 && gSumW > 0f)
                        {
                            float nr = gSumR / gSumW;
                            float ng = gSumG / gSumW;
                            float nb = gSumB / gSumW;
                            float liftW = (1f - oa / 236f) * 0.85f;
                            if (nr + ng + nb > r + g + b)
                            {
                                r = r * (1f - liftW) + nr * liftW;
                                g = g * (1f - liftW) + ng * liftW;
                                b = b * (1f - liftW) + nb * liftW;
                            }
                        }
                    }
                    else if (strongGreenCount >= 4 && gSumW > 0f)
                    {
                        float bridge = Math.Clamp(rg + 0.80f * ((strongGreenCount - 3) / 5f), 0f, 1f);
                        rawLeafCov[di] = (oa / 255f) * bridge;
                        float nr = gSumR / gSumW;
                        float ng = gSumG / gSumW;
                        float nb = gSumB / gSumW;
                        float shadeScale = Math.Clamp((r + g + b) / MathF.Max(1f, nr + ng + nb), 0.42f, 0.86f);
                        float tintW = 1f - rg;
                        r = r * (1f - tintW) + nr * shadeScale * tintW;
                        g = g * (1f - tintW) + ng * shadeScale * tintW;
                        b = b * (1f - tintW) + nb * shadeScale * tintW;
                    }
                    else
                    {
                        rawLeafCov[di] = (oa / 255f) * rg * 0.65f;
                        if (rawLeafCov[di] > 0.02f && gSumW > 0f)
                        {
                            float nr = gSumR / gSumW;
                            float ng = gSumG / gSumW;
                            float nb = gSumB / gSumW;
                            float shadeScale = Math.Clamp((r + g + b) / MathF.Max(1f, nr + ng + nb), 0.48f, 0.95f);
                            float tintW = (1f - rg) * 0.85f;
                            r = r * (1f - tintW) + nr * shadeScale * tintW;
                            g = g * (1f - tintW) + ng * shadeScale * tintW;
                            b = b * (1f - tintW) + nb * shadeScale * tintW;
                        }
                    }

                    cleanLeafRgb[di * 3] = (byte)Math.Clamp((int)MathF.Round(r), 0, 255);
                    cleanLeafRgb[di * 3 + 1] = (byte)Math.Clamp((int)MathF.Round(g), 0, 255);
                    cleanLeafRgb[di * 3 + 2] = (byte)Math.Clamp((int)MathF.Round(b), 0, 255);
                }
            }

            var leafCov = new float[W * H];
            for (int y = 1; y < H - 1; y++)
            {
                int row = y * W;
                for (int x = 1; x < W - 1; x++)
                {
                    int di = row + x;
                    float c = rawLeafCov[di];
                    float card = rawLeafCov[di - 1] + rawLeafCov[di + 1] + rawLeafCov[di - W] + rawLeafCov[di + W];
                    if (c <= 0f && card <= 0.1f) continue;
                    float diag = rawLeafCov[di - W - 1] + rawLeafCov[di - W + 1] + rawLeafCov[di + W - 1] + rawLeafCov[di + W + 1];
                    float blur = c * 0.44f + card * 0.09f + diag * 0.05f;
                    if (c > 0f)
                    {
                        bool touchesInternalCut =
                            (rawLeafCov[di - 1] <= 0.02f && origRgba[(di - 1) * 4 + 3] >= 120) ||
                            (rawLeafCov[di + 1] <= 0.02f && origRgba[(di + 1) * 4 + 3] >= 120) ||
                            (rawLeafCov[di - W] <= 0.02f && origRgba[(di - W) * 4 + 3] >= 120) ||
                            (rawLeafCov[di + W] <= 0.02f && origRgba[(di + W) * 4 + 3] >= 120);
                        leafCov[di] = touchesInternalCut ? (0.50f * c + 0.50f * blur) : c;
                    }
                    else if (blur > 0.12f && origRgba[di * 4 + 3] >= 120 && cleanLeafRgb[di * 3 + 1] > 0)
                    {
                        leafCov[di] = blur * 0.60f;
                    }
                }
            }

            float invScale = 1f / MathF.Max(0.6f, sizeScale);
            float tetherNorm = MathF.Max(6f, 8f * sizeScale);
            float freeRadius = 4f * sizeScale;
            var noiseMargin = new float[W * H];
            for (int y = 0; y < H; y++)
            {
                int row = y * W;
                float yBias = 0.08f * (1f - (y - silTop) / (float)silH);
                for (int x = 0; x < W; x++)
                {
                    int di = row + x;
                    float n = 0.62f * ValueNoise2D(x * 0.13f * invScale, y * 0.10f * invScale, seedGuid) +
                              0.38f * ValueNoise2D(x * 0.26f * invScale + 13.1f, y * 0.20f * invScale + 7.7f, seedGuid ^ 0x55AAu);
                    float crownBias = yBias + 0.05f * (MathF.Abs(x - rootX) / MathF.Max(8f, silW * 0.5f));
                    float tetherPenalty = branchDist is not null
                        ? tetherWeight * MathF.Max(0f, (branchDist[di] / 3f - freeRadius) / tetherNorm)
                        : 0f;
                    noiseMargin[di] = (n - crownBias - tetherPenalty) - thresh;
                }
            }

            for (int y = 1; y < H - 1; y++)
            {
                int row = y * W;
                for (int x = 1; x < W - 1; x++)
                {
                    int di = row + x;
                    float baseCov = leafCov[di];
                    if (baseCov <= 0.01f) continue;

                    float gx = 0.5f * (noiseMargin[di + 1] - noiseMargin[di - 1]);
                    float gy = 0.5f * (noiseMargin[di + W] - noiseMargin[di - W]);
                    float grad = MathF.Max(0.032f, MathF.Sqrt(gx * gx + gy * gy));
                    float sdf = noiseMargin[di] / grad;
                    float clusterCov = SmoothStep01(-0.55f, 0.75f, sdf);
                    if (clusterCov <= 0.005f) continue;

                    float clusterAlpha = clusterCov * baseCov;
                    int leafA = (int)MathF.Round(clusterAlpha * 255f);
                    if (leafA < 4) continue;
                    if (clusterCov < 0.96f)
                        leafA = Math.Min(leafA, 240);

                    byte lr = cleanLeafRgb[di * 3];
                    byte lg = cleanLeafRgb[di * 3 + 1];
                    byte lb = cleanLeafRgb[di * 3 + 2];
                    float lz = origZ[di];
                    if (lz >= 1e8f)
                    {
                        for (int oy = -1; oy <= 1 && lz >= 1e8f; oy++)
                            for (int ox = -1; ox <= 1 && lz >= 1e8f; ox++)
                                if (origZ[(y + oy) * W + (x + ox)] < 1e8f)
                                    lz = origZ[(y + oy) * W + (x + ox)];
                        if (lz >= 1e8f) lz = centerZ;
                    }

                    byte sa = compRgba[di * 4 + 3];
                    if (sa == 0)
                    {
                        compRgba[di * 4] = lr;
                        compRgba[di * 4 + 1] = lg;
                        compRgba[di * 4 + 2] = lb;
                        compRgba[di * 4 + 3] = (byte)Math.Min(255, leafA);
                        compZ[di] = lz;
                    }
                    else
                    {
                        bool leafInFront = lz <= skelZ[di] + 0.0008f;
                        float fA = (leafInFront ? leafA : sa) / 255f;
                        float bA = (leafInFront ? sa : leafA) / 255f;
                        float outA = fA + bA * (1f - fA);
                        if (outA > 1e-4f)
                        {
                            float wF = fA / outA;
                            float wB = (bA * (1f - fA)) / outA;
                            byte sr = compRgba[di * 4], sg = compRgba[di * 4 + 1], sb = compRgba[di * 4 + 2];
                            byte fR = leafInFront ? lr : sr, fG = leafInFront ? lg : sg, fB = leafInFront ? lb : sb;
                            byte bR = leafInFront ? sr : lr, bG = leafInFront ? sg : lg, bB = leafInFront ? sb : lb;
                            compRgba[di * 4] = (byte)Math.Clamp((int)MathF.Round(fR * wF + bR * wB), 0, 255);
                            compRgba[di * 4 + 1] = (byte)Math.Clamp((int)MathF.Round(fG * wF + bG * wB), 0, 255);
                            compRgba[di * 4 + 2] = (byte)Math.Clamp((int)MathF.Round(fB * wF + bB * wB), 0, 255);
                            compRgba[di * 4 + 3] = (byte)Math.Clamp((int)MathF.Round(outA * 255f), 1, 255);
                            if (leafInFront && leafA >= 80)
                                compZ[di] = MathF.Min(compZ[di], lz);
                        }
                    }
                }
            }
        }

        var rimCappedAlpha = (byte[])null!;
        for (int y = 1; y < H - 1; y++)
        {
            int row = y * W;
            for (int x = 1; x < W - 1; x++)
            {
                int di = row + x;
                byte a = compRgba[di * 4 + 3];
                if (a <= 240) continue;
                if (compRgba[(di - 1) * 4 + 3] < 32 ||
                    compRgba[(di + 1) * 4 + 3] < 32 ||
                    compRgba[(di - W) * 4 + 3] < 32 ||
                    compRgba[(di + W) * 4 + 3] < 32)
                {
                    rimCappedAlpha ??= new byte[W * H];
                    rimCappedAlpha[di] = 240;
                }
            }
        }
        if (rimCappedAlpha is not null)
        {
            for (int i = 0; i < rimCappedAlpha.Length; i++)
            {
                if (rimCappedAlpha[i] != 0)
                    compRgba[i * 4 + 3] = rimCappedAlpha[i];
            }
        }

        var owner = new short[W * H];
        Array.Fill(owner, (short)-1);
        var partCenters = new (float X, float Y)[parts.Count];
        for (int pi = 0; pi < parts.Count; pi++)
        {
            var p = parts[pi];
            partCenters[pi] = (p.NearX - minX + p.NearW * 0.5f, p.NearY - minY + p.NearH * 0.6f);
            for (int y = 0; y < p.NearH; y++)
            {
                int dy = p.NearY - minY + y;
                for (int x = 0; x < p.NearW; x++)
                {
                    int srcX = p.Flip ? (p.NearW - 1 - x) : x;
                    if (p.NearRgba[(y * p.NearW + srcX) * 4 + 3] > 0)
                    {
                        int di = dy * W + (p.NearX - minX + x);
                        if (compRgba[di * 4 + 3] > 0)
                            owner[di] = (short)pi;
                    }
                }
            }
        }

        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                int di = y * W + x;
                if (compRgba[di * 4 + 3] == 0 || owner[di] >= 0) continue;
                short bestP = -1;
                float bestD = float.MaxValue;
                for (int pi = 0; pi < parts.Count; pi++)
                {
                    var p = parts[pi];
                    int ox = x - (p.NearX - minX);
                    int oy = y - (p.NearY - minY);
                    if ((uint)ox < (uint)p.NearW && (uint)oy < (uint)p.NearH)
                    {
                        float d = (x - partCenters[pi].X) * (x - partCenters[pi].X) + (y - partCenters[pi].Y) * (y - partCenters[pi].Y);
                        if (d < bestD) { bestD = d; bestP = (short)pi; }
                    }
                }
                owner[di] = bestP;
            }
        }

        for (int pi = 0; pi < parts.Count; pi++)
        {
            var p = parts[pi];
            float dSpan = MathF.Max(1e-6f, p.DepthFar - p.DepthNear);
            bool wantDepth = p.NearDepth is not null;

            var nearOutRgba = new byte[p.NearW * p.NearH * 4];
            var nearOutDepth = wantDepth ? new byte[p.NearW * p.NearH] : null;
            if (nearOutDepth is not null) Array.Fill(nearOutDepth, (byte)255);

            for (int y = 0; y < p.NearH; y++)
            {
                int dy = p.NearY - minY + y;
                for (int x = 0; x < p.NearW; x++)
                {
                    int gx = p.NearX - minX + x;
                    int di = dy * W + gx;
                    if (owner[di] != pi || compRgba[di * 4 + 3] < 4) continue;
                    int dstX = p.Flip ? (p.NearW - 1 - x) : x;
                    int qi = y * p.NearW + dstX;
                    Buffer.BlockCopy(compRgba, di * 4, nearOutRgba, qi * 4, 4);
                    if (nearOutDepth is not null)
                    {
                        float zv = compZ[di];
                        if (zv >= 1e8f)
                        {
                            for (int oy = -1; oy <= 1 && zv >= 1e8f; oy++)
                            {
                                int ny = Math.Clamp(dy + oy, 0, H - 1);
                                for (int ox = -1; ox <= 1 && zv >= 1e8f; ox++)
                                {
                                    int nx = Math.Clamp(gx + ox, 0, W - 1);
                                    if (compZ[ny * W + nx] < 1e8f)
                                        zv = compZ[ny * W + nx];
                                }
                            }
                            if (zv >= 1e8f) zv = centerZ;
                        }
                        nearOutDepth[qi] = (byte)Math.Clamp((int)MathF.Round((zv - p.DepthNear) / dSpan * 255f), 0, 254);
                    }
                }
            }

            var (medOutRgba, medOutDepth) = DownsampleSmooth(nearOutRgba, nearOutDepth, p.NearW, p.NearH, p.MedW, p.MedH, 2);
            byte[]? farOutRgba = null;
            byte[]? farOutDepth = null;
            if (p.HasFar)
                (farOutRgba, farOutDepth) = DownsampleSmooth(nearOutRgba, nearOutDepth, p.NearW, p.NearH, p.FarW, p.FarH, 4);

            outputs[pi] = new PluginObjectSpriteOverride(
                medOutRgba,
                medOutDepth,
                p.HasNear ? nearOutRgba : null,
                p.HasNear ? nearOutDepth : null,
                farOutRgba,
                farOutDepth);
        }

        return outputs;
    }

    private static (byte[] Rgba, byte[]? Depth) DownsampleSmooth(
        byte[] srcRgba,
        byte[]? srcDepth,
        int srcW,
        int srcH,
        int dstW,
        int dstH,
        int factor)
    {
        var outRgba = new byte[dstW * dstH * 4];
        var outDepth = srcDepth is not null ? new byte[dstW * dstH] : null;
        if (outDepth is not null) Array.Fill(outDepth, (byte)255);

        float scaleX = srcW / (float)Math.Max(1, dstW);
        float scaleY = srcH / (float)Math.Max(1, dstH);

        for (int dy = 0; dy < dstH; dy++)
        {
            int sy0 = (int)MathF.Floor(dy * scaleY);
            for (int dx = 0; dx < dstW; dx++)
            {
                int sx0 = (int)MathF.Floor(dx * scaleX);
                float rSum = 0f, gSum = 0f, bSum = 0f, aSum = 0f;
                int aMax = 0;
                byte dMin = 255;
                int taps = 0;

                for (int oy = 0; oy < factor; oy++)
                {
                    int sy = Math.Clamp(sy0 + oy, 0, srcH - 1);
                    for (int ox = 0; ox < factor; ox++)
                    {
                        int sx = Math.Clamp(sx0 + ox, 0, srcW - 1);
                        int si = sy * srcW + sx;
                        byte pa = srcRgba[si * 4 + 3];
                        taps++;
                        if (pa == 0) continue;
                        rSum += srcRgba[si * 4] * pa;
                        gSum += srcRgba[si * 4 + 1] * pa;
                        bSum += srcRgba[si * 4 + 2] * pa;
                        aSum += pa;
                        if (pa > aMax) aMax = pa;
                        if (srcDepth is not null && srcDepth[si] < dMin) dMin = srcDepth[si];
                    }
                }

                if (aSum <= 0f) continue;
                float avgA = aSum / Math.Max(1, taps);
                float effA = avgA < 96f && aMax >= 150 ? MathF.Min(aMax, avgA * 1.25f) : avgA;
                int blendedA = (int)MathF.Round(effA);
                if (blendedA < 4) continue;
                if (blendedA > 255) blendedA = 255;
                if (blendedA < 255 && aMax < 255 && blendedA > 240)
                    blendedA = 240;

                int di = dy * dstW + dx;
                outRgba[di * 4] = (byte)Math.Clamp((int)MathF.Round(rSum / aSum), 0, 255);
                outRgba[di * 4 + 1] = (byte)Math.Clamp((int)MathF.Round(gSum / aSum), 0, 255);
                outRgba[di * 4 + 2] = (byte)Math.Clamp((int)MathF.Round(bSum / aSum), 0, 255);
                outRgba[di * 4 + 3] = (byte)blendedA;
                if (outDepth is not null)
                    outDepth[di] = dMin < 255 ? dMin : (byte)128;
            }
        }

        return (outRgba, outDepth);
    }

    private static byte[] Upscale2xRgba(byte[] src, int w, int h)
    {
        int nw = w * 2, nh = h * 2;
        var dst = new byte[nw * nh * 4];
        for (int y = 0; y < nh; y++)
        {
            int sy = y >> 1;
            for (int x = 0; x < nw; x++)
            {
                int sx = x >> 1;
                Buffer.BlockCopy(src, (sy * w + sx) * 4, dst, (y * nw + x) * 4, 4);
            }
        }
        return dst;
    }

    private static byte[] Upscale2xDepth(byte[] src, int w, int h)
    {
        int nw = w * 2, nh = h * 2;
        var dst = new byte[nw * nh];
        for (int y = 0; y < nh; y++)
        {
            int sy = y >> 1;
            for (int x = 0; x < nw; x++)
                dst[y * nw + x] = src[sy * w + (x >> 1)];
        }
        return dst;
    }

    private static Vector3 AverageSlice(List<(int X, int Y, byte R, byte G, byte B, float Z)> list, int start, int end)
    {
        int count = Math.Max(1, end - start);
        float r = 0f, g = 0f, b = 0f;
        for (int i = start; i < end && i < list.Count; i++)
        {
            r += list[i].R;
            g += list[i].G;
            b += list[i].B;
        }
        return new Vector3(r / count, g / count, b / count);
    }

    private static float ValueNoise2D(float x, float y, uint seed)
    {
        int ix = (int)MathF.Floor(x);
        int iy = (int)MathF.Floor(y);
        float fx = x - ix;
        float fy = y - iy;
        fx = fx * fx * (3f - 2f * fx);
        fy = fy * fy * (3f - 2f * fy);

        static float Hash(int a, int b, uint s)
        {
            uint n = unchecked((uint)a * 374761393u + (uint)b * 668265263u + s * 2246822519u);
            n = (n ^ (n >> 13)) * 1274126177u;
            return ((n ^ (n >> 16)) & 0xFFFFu) / 65535f;
        }

        float v00 = Hash(ix, iy, seed);
        float v10 = Hash(ix + 1, iy, seed);
        float v01 = Hash(ix, iy + 1, seed);
        float v11 = Hash(ix + 1, iy + 1, seed);
        return (v00 * (1f - fx) + v10 * fx) * (1f - fy) + (v01 * (1f - fx) + v11 * fx) * fy;
    }

    private struct DeterministicRng(uint state)
    {
        private uint _s = state == 0 ? 0x6D2B79F5u : state;

        public float NextFloat()
        {
            _s ^= _s << 13;
            _s ^= _s >> 17;
            _s ^= _s << 5;
            return (_s & 0xFFFFFFu) / 16777216f;
        }

        public float Range(float lo, float hi) => lo + (hi - lo) * NextFloat();

        public int RangeInt(int lo, int hiInclusive) => lo + (int)(NextFloat() * (hiInclusive - lo + 0.999f));
    }
}
