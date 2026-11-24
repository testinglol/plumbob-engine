using System.Collections.Concurrent;
using System.Numerics;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsSimulation;

internal static partial class SceneExporter
{
    internal const int MaxFoliageStage = 9;

    internal enum DeciduousHabit : byte
    {
        None = 0,
        Spreading = 1,
        Weeping = 2,
        Slender = 3,
        Shrub = 4,
    }

    internal sealed record WitheredPartOverride(
        byte[] MediumRgba,
        byte[]? MediumDepth,
        byte[]? NearRgba,
        byte[]? NearDepth,
        byte[]? FarRgba,
        byte[]? FarDepth);

    private readonly record struct TreeSynthesisCacheKey(
        string Signature,
        int CameraOrientation,
        int Stage);

    private static readonly ConcurrentDictionary<TreeSynthesisCacheKey, WitheredPartOverride?[]> witheredTreeCache = new();

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
        0x3931u, 0x07CFu, 0x58EBu, 0x9B2Bu, 0xECD2u, 0x5F42u, 0xBD9Eu, 0x9F9Du, 0xFCDEu, 0xDB4Bu,
        0x8BA5u, 0xF719u, 0xD174u, 0x358Du, 0x1748u, 0x5147u, 0xB7AFu, 0x90CBu, 0xFE56u, 0xD987u,
        0x3026u, 0xAA86u, 0xF140u, 0xC153u, 0x23F3u, 0x03CDu, 0x3007u, 0xDE80u, 0xFD08u, 0xDE36u,
        0xC5CEu, 0x10B3u, 0x9DA7u, 0x9940u, 0x6A55u, 0x6A79u, 0x6A67u, 0x6A8Bu, 0xA02Cu, 0xD9BDu,
        0xC3D3u, 0x373Cu, 0x26A2u, 0x0165u, 0x678Fu, 0x67FBu, 0x6467u, 0x64D2u, 0x653Fu, 0x65AAu,
        0x6216u, 0x6282u, 0x62F1u, 0x6361u, 0x110Cu, 0x0EDEu, 0x0E90u, 0x0E62u, 0x0E34u, 0xD17Fu,
        0xFB0Eu, 0x1274u, 0x4676u, 0x5EDCu, 0xB902u, 0xE049u, 0xF89Eu, 0x16AEu, 0x335Eu, 0xF9E1u,
        0x9249u, 0x7E21u, 0x9247u, 0xAB04u, 0xBEB3u, 0xD27Au, 0xE554u, 0xFA56u, 0x8296u, 0x89BCu,
        0xA8D1u, 0xC601u, 0xBB83u, 0xD68Eu, 0xF299u, 0x5359u, 0x3C52u, 0xC3EFu, 0x1181u, 0x4B4Du,
        0xDC0Bu, 0xA964u, 0x6961u, 0x5A3Au, 0x4B60u, 0x1545u, 0x1546u, 0x0EB6u, 0xAED3u, 0x72BDu,
        0x11ECu, 0x52EDu, 0x3443u, 0xE4FBu, 0xE483u, 0xE482u, 0xE48Du, 0xE48Cu, 0xD627u, 0x302Eu,
        0x7C24u, 0xE969u, 0x1733u, 0x1531u, 0x1544u, 0xAD12u, 0x9AE0u, 0xAF4Au, 0xE529u, 0x78EDu,
        0xFF97u, 0x952Bu, 0xF3CCu, 0xF3CAu, 0x9846u, 0x70FCu, 0xFEE3u, 0x8EB8u, 0xBC66u, 0x54C3u,
        0xFA73u
    ];

    internal static DeciduousHabit ClassifyDeciduousFlora(ObjectRegistry registry, ObjectEntry entry, uint guid, string name)
    {
        if (EvergreenExcludeGuids.Contains(guid)) return DeciduousHabit.None;

        if (guid == 0x6A6Du)
            return name.Contains("Christmas", StringComparison.OrdinalIgnoreCase) ? DeciduousHabit.None : DeciduousHabit.Spreading;

        switch (guid)
        {
            case 0x5C19u or 0x93DDu or 0x8299u or 0xF200u or 0xE184u:
                return DeciduousHabit.Weeping;
            case 0x1468u or 0x8F89u or 0xC0C3u or 0x1182u or 0x7B56u or 0xC99Au:
                return DeciduousHabit.Slender;
            case 0x2C55u or 0xD5CAu or 0xB115u:
                return DeciduousHabit.Shrub;
            case 0x2B83u or 0x2B85u or 0x2B82u
                or 0x09D8u or 0x5CDAu or 0x4C9Bu or 0xA537u or 0x9610u
                or 0x4400u or 0xAF16u or 0x81BCu or 0xEB10u or 0xDD96u
                or 0x3484u or 0x0857u or 0x5764u or 0xA17Eu or 0xFC52u
                or 0x1671u or 0x00DDu
                or 0xAC66u or 0x15A2u or 0xB612u or 0xFAA5u or 0x39B3u or 0x2FA7u or 0x18F3u or 0x0E52u or 0x77D0u or 0x5FDBu
                or 0x6854u or 0x68F0u or 0x6B62u or 0x6BFFu or 0x6A8Au or 0x6526u or 0x6549u or 0x65ECu or 0x6409u
                or 0xCEB2u or 0xBDECu or 0x4498u or 0x1C57u or 0xC4D0u or 0x6382u or 0x9CC2u or 0x1AA2u or 0xFE21u or 0x05FFu:
                return DeciduousHabit.Spreading;
        }

        bool isBuildFoliage = entry.Definition[ObjdField.BuildModeType] == 4 ||
            (entry.Definition[ObjdField.MasterId] != 0 &&
             registry.FindAlternativeType(entry)?.Definition[ObjdField.BuildModeType] == 4);
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

    private sealed record FloraMemberSpec(
        short ObjectId,
        uint Guid,
        ObjectEntry Entry,
        Vector3 Origin,
        int Direction,
        short Graphic,
        short[]? DynamicFlags,
        DeciduousHabit Habit,
        bool Sheltered);

    private sealed record PartCapture(
        int MemberIndex,
        int SpriteIndex,
        int NearX,
        int NearY,
        int NearW,
        int NearH,
        bool Flip,
        float DepthNear,
        float DepthFar,
        byte[] NearRgba,
        byte[]? NearDepth,
        int MedW,
        int MedH,
        int FarW,
        int FarH,
        bool HasNear,
        bool HasFar);

    internal static Dictionary<(short ObjectId, int SpriteIndex), WitheredPartOverride>? BuildLotWitheredOverrides(
        IffFile lot,
        SimulationWorld world,
        ObjectRegistry registry,
        LotCamera camera,
        int lotSize,
        int foliageStage,
        Func<XObject, Vector3> objectPosition,
        Func<XObject?, bool> isContained)
    {
        if (foliageStage <= 0) return null;

        var level1Rooms = world.LotRoomMaps.GetValueOrDefault(1);
        var groups = new Dictionary<short, List<FloraMemberSpec>>();

        foreach (var obj in world.WalkOrder)
        {
            if (obj is XPerson || obj.Position.Height != 1 || obj.Position.X < 0 || obj.Position.Y < 0 || obj[ObjectData.Hidden] != 0)
                continue;
            if (obj[ObjectData.ContainerId] != 0 || obj[ObjectData.ParentId] != 0 || isContained(obj))
                continue;

            var guid = unchecked((uint)(obj.TypeRecord?.Key ?? 0));
            if (guid == 0 || guid == 2179383033u) continue;
            var entry = registry.Find(guid);
            if (entry is null) continue;

            var name = obj.TypeRecord?.Name ?? entry.Chunk.Label ?? entry.CatalogString(0, 1) ?? "";
            var habit = ClassifyDeciduousFlora(registry, entry, guid, name);
            if (habit == DeciduousHabit.None) continue;

            int tx = obj.Position.X >> 4;
            int ty = obj.Position.Y >> 4;
            bool outside = level1Rooms is null ||
                ((uint)tx < (uint)level1Rooms.Width && (uint)ty < (uint)level1Rooms.Height &&
                 level1Rooms.RoomAt(tx, ty) is var room && room != RoomMap.NoRoom && level1Rooms.IsOutside(room));
            if (!outside) continue;

            bool sheltered = IsShelteredAt(lot, world, lotSize, obj.Position);
            short leadId = obj.MultiTileMasterId != 0 ? obj.MultiTileMasterId : obj.Id;
            if (!groups.TryGetValue(leadId, out var list))
            {
                list = new List<FloraMemberSpec>(4);
                groups[leadId] = list;
            }
            list.Add(new FloraMemberSpec(
                obj.Id,
                guid,
                entry,
                objectPosition(obj),
                obj[ObjectData.Direction],
                obj[ObjectData.Graphic],
                obj.DynamicSpriteFlags,
                habit,
                sheltered));
        }

        if (groups.Count == 0) return null;

        var result = new Dictionary<(short ObjectId, int SpriteIndex), WitheredPartOverride>();
        const float mediumUnitHeight = 152f / 7f;

        foreach (var (_, members) in groups)
        {
            bool allSheltered = true;
            DeciduousHabit groupHabit = DeciduousHabit.Spreading;
            for (int i = 0; i < members.Count; i++)
            {
                if (!members[i].Sheltered) allSheltered = false;
                if (members[i].Habit is DeciduousHabit.Weeping or DeciduousHabit.Slender or DeciduousHabit.Shrub)
                    groupHabit = members[i].Habit;
            }
            if (allSheltered) continue;

            members.Sort(static (a, b) => a.Guid != b.Guid ? a.Guid.CompareTo(b.Guid) : a.ObjectId.CompareTo(b.ObjectId));

            var baseOrigin = members[0].Origin;
            var sigParts = new string[members.Count];
            for (int i = 0; i < members.Count; i++)
            {
                var m = members[i];
                int dx16 = (int)MathF.Round((m.Origin.X - baseOrigin.X) * 16f);
                int dy16 = (int)MathF.Round((m.Origin.Y - baseOrigin.Y) * 16f);
                sigParts[i] = $"{m.Guid:x8}:{dx16},{dy16}:{m.Direction}:{m.Graphic}";
            }
            var cacheKey = new TreeSynthesisCacheKey(string.Join('|', sigParts), camera.Orientation, foliageStage);

            if (witheredTreeCache.Count > 512)
                witheredTreeCache.Clear();

            var captures = CaptureGroupParts(members, camera, mediumUnitHeight);
            if (captures.Count == 0) continue;

            var synthesized = witheredTreeCache.GetOrAdd(cacheKey, _ => SynthesizeGroup(captures, groupHabit, foliageStage, members[0].Guid));
            for (int ci = 0; ci < captures.Count && ci < synthesized.Length; ci++)
            {
                if (synthesized[ci] is { } ov)
                    result[(members[captures[ci].MemberIndex].ObjectId, captures[ci].SpriteIndex)] = ov;
            }
        }

        return result.Count > 0 ? result : null;
    }

    private static List<PartCapture> CaptureGroupParts(List<FloraMemberSpec> members, LotCamera camera, float mediumUnitHeight)
    {
        var captures = new List<PartCapture>(members.Count);
        for (int mi = 0; mi < members.Count; mi++)
        {
            var m = members[mi];
            var baseGraphic = (ushort)m.Entry.Definition[ObjdField.BaseGraphic];
            var selectedGraphic = SelectedGraphic(baseGraphic, m.Graphic);
            var groupChunk = m.Entry.File.Find(ResourceType.Dgrp, selectedGraphic);
            if (groupChunk is null) continue;
            DrawGroup group;
            try { group = CachedGroup(m.Entry.File, groupChunk); }
            catch (ResourceFormatException) { continue; }

            var image = SelectedImage(group, m.Direction, camera.Orientation);
            if (image is null) continue;
            var nearImage = SelectedImage(group, m.Direction, camera.Orientation, 3);
            var farImage = SelectedImage(group, m.Direction, camera.Orientation, 1);

            for (int si = 0; si < image.Sprites.Count; si++)
            {
                var sp = image.Sprites[si];
                if (!DynamicSpriteVisible(sp.SpriteId, m.Entry.Definition[ObjdField.DynamicSpritesBaseId],
                        m.Entry.Definition[ObjdField.NumDynamicSprites], m.DynamicFlags))
                    continue;
                var (medFrame, medLegacy, medW, medH, medPal) = ReadDgrpPart(m.Entry.File, sp, m.ObjectId, null);
                if ((medFrame is null && medLegacy is null) || !FrameHasPixels(medW, medH))
                    continue;
                var medRgba = GetPartRgbaBytes(m.Entry.File, sp, medFrame, medLegacy, medW, medH, medPal);
                if (medRgba is null) continue;
                var medDepth = medFrame is not null ? GetPartDepthBytes(m.Entry.File, sp, medFrame) : null;

                var (offX, offY) = RotateCardinalOffset(m.Direction, sp.Offset2, sp.Offset3);
                var offset = new Vector3(offX, offY, sp.Offset1);
                var point = camera.Project(m.Origin.X + offset.X / 16f, m.Origin.Y + offset.Y / 16f, m.Origin.Z * 40f);
                int medScreenX = (int)(point.X + sp.X);
                int medScreenY = (int)(point.Y - offset.Z / 5f * mediumUnitHeight - medH + sp.Y);
                bool flip = (sp.Flags & 1) != 0;
                var depthRange = medDepth is not null ? SpriteDepth(camera, m.Origin, offset) : (Near: 0.5f, Far: 0.52f);

                bool hasNear = false;
                int nearScreenX = medScreenX * 2;
                int nearScreenY = medScreenY * 2;
                int nearW = medW * 2;
                int nearH = medH * 2;
                byte[] nearRgba;
                byte[]? nearDepth;

                if (nearImage is not null && si < nearImage.Sprites.Count &&
                    (nearImage.Sprites.Count == image.Sprites.Count || si == 0) &&
                    (nearImage.Sprites[si].Flags & 1) == (sp.Flags & 1))
                {
                    var nsp = nearImage.Sprites[si];
                    var (nf, nl, nw, nh, npal) = ReadDgrpPart(m.Entry.File, nsp, m.ObjectId, null);
                    if ((nf is not null || nl is not null) && (nf is not null) == (medFrame is not null) && FrameHasPixels(nw, nh) &&
                        GetPartRgbaBytes(m.Entry.File, nsp, nf, nl, nw, nh, npal) is { } nBytes)
                    {
                        hasNear = true;
                        nearW = nw;
                        nearH = nh;
                        nearScreenX = (int)(2f * point.X + nsp.X);
                        nearScreenY = (int)(2f * (point.Y - offset.Z / 5f * mediumUnitHeight) - nh + nsp.Y);
                        nearRgba = nBytes;
                        nearDepth = nf is not null ? GetPartDepthBytes(m.Entry.File, nsp, nf) : null;
                    }
                    else
                    {
                        nearRgba = Upscale2xRgba(medRgba, medW, medH);
                        nearDepth = medDepth is not null ? Upscale2xDepth(medDepth, medW, medH) : null;
                    }
                }
                else
                {
                    nearRgba = Upscale2xRgba(medRgba, medW, medH);
                    nearDepth = medDepth is not null ? Upscale2xDepth(medDepth, medW, medH) : null;
                }

                bool hasFar = false;
                int farW = Math.Max(1, medW / 2);
                int farH = Math.Max(1, medH / 2);
                if (farImage is not null && si < farImage.Sprites.Count &&
                    (farImage.Sprites.Count == image.Sprites.Count || si == 0) &&
                    (farImage.Sprites[si].Flags & 1) == (sp.Flags & 1))
                {
                    var fsp = farImage.Sprites[si];
                    var (ff, fl, fw, fh, _) = ReadDgrpPart(m.Entry.File, fsp, m.ObjectId, null);
                    if ((ff is not null || fl is not null) && (ff is not null) == (medFrame is not null) && FrameHasPixels(fw, fh))
                    {
                        hasFar = true;
                        farW = fw;
                        farH = fh;
                    }
                }

                captures.Add(new PartCapture(
                    mi, si, nearScreenX, nearScreenY, nearW, nearH, flip,
                    depthRange.Near, depthRange.Far,
                    nearRgba, nearDepth, medW, medH, farW, farH, hasNear, hasFar));
            }
        }
        return captures;
    }

    private static WitheredPartOverride?[] SynthesizeGroup(List<PartCapture> parts, DeciduousHabit habit, int stage, uint seedGuid)
    {
        var outputs = new WitheredPartOverride?[parts.Count];
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

                    const float aaHalfWidth = 0.62f;
                    if (dist >= rad + aaHalfWidth) continue;

                    float solidCore = MathF.Max(0.38f, rad - 0.36f);
                    byte aNew;
                    if (dist <= solidCore)
                    {
                        aNew = 255;
                    }
                    else
                    {
                        float uEdge = Math.Clamp((rad + aaHalfWidth - dist) / (rad + aaHalfWidth - solidCore), 0f, 1f);
                        float smoothCov = uEdge * uEdge * (3f - 2f * uEdge);
                        if (rad < 0.72f)
                            smoothCov *= 0.72f + 0.28f * (rad / 0.72f);
                        int mapped = (int)MathF.Round(smoothCov * 255f);
                        if (mapped < 68) continue;
                        aNew = (byte)Math.Min(251, mapped);
                    }

                    float crossT = Math.Clamp(((px - cx) * perpX + (py - cy) * perpY) / MathF.Max(0.46f, rad), -1f, 1f);
                    var (cr, cg, cb) = BarkColor(crossT, ux, uy, px, py, rad);
                    float pz = z0 + (z1 - z0) * t - 0.0002f * MathF.Sqrt(MathF.Max(0f, 1f - crossT * crossT));

                    byte oldA = skelRgba[di * 4 + 3];
                    if (oldA == 0 || (aNew == 255 && (oldA < 255 || pz <= skelZ[di] + 0.0004f)) || (oldA < 255 && aNew > oldA))
                    {
                        if (oldA > 0 && aNew < 255 && oldA < 255)
                        {
                            float w = aNew / (float)(oldA + aNew);
                            cr = (byte)MathF.Round(skelRgba[di * 4] * (1f - w) + cr * w);
                            cg = (byte)MathF.Round(skelRgba[di * 4 + 1] * (1f - w) + cg * w);
                            cb = (byte)MathF.Round(skelRgba[di * 4 + 2] * (1f - w) + cb * w);
                        }
                        skelRgba[di * 4] = cr;
                        skelRgba[di * 4 + 1] = cg;
                        skelRgba[di * 4 + 2] = cb;
                        skelRgba[di * 4 + 3] = Math.Max(oldA, aNew);
                        skelZ[di] = MathF.Min(skelZ[di], pz);
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
                    if (oa < 68 || !barkMask[di]) continue;
                    byte r = origRgba[di * 4], g = origRgba[di * 4 + 1], b = origRgba[di * 4 + 2];
                    byte sa = skelRgba[di * 4 + 3];
                    if (sa == 0 || wReal >= 0.99f)
                    {
                        skelRgba[di * 4] = r;
                        skelRgba[di * 4 + 1] = g;
                        skelRgba[di * 4 + 2] = b;
                        skelRgba[di * 4 + 3] = oa;
                        skelZ[di] = origZ[di];
                    }
                    else
                    {
                        skelRgba[di * 4] = (byte)MathF.Round(skelRgba[di * 4] * (1f - wReal) + r * wReal);
                        skelRgba[di * 4 + 1] = (byte)MathF.Round(skelRgba[di * 4 + 1] * (1f - wReal) + g * wReal);
                        skelRgba[di * 4 + 2] = (byte)MathF.Round(skelRgba[di * 4 + 2] * (1f - wReal) + b * wReal);
                        skelRgba[di * 4 + 3] = Math.Max(sa, oa);
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

            float invScale = 1f / MathF.Max(0.6f, sizeScale);
            float tetherNorm = MathF.Max(6f, 8f * sizeScale);
            float freeRadius = 4f * sizeScale;
            for (int y = 0; y < H; y++)
            {
                for (int x = 0; x < W; x++)
                {
                    int di = y * W + x;
                    byte oa = origRgba[di * 4 + 3];
                    if (oa < 68 || barkMask[di]) continue;
                    float n = 0.62f * ValueNoise2D(x * 0.13f * invScale, y * 0.10f * invScale, seedGuid) +
                              0.38f * ValueNoise2D(x * 0.26f * invScale + 13.1f, y * 0.20f * invScale + 7.7f, seedGuid ^ 0x55AAu);
                    float crownBias = 0.08f * (1f - (y - silTop) / (float)silH) + 0.05f * (MathF.Abs(x - rootX) / MathF.Max(8f, silW * 0.5f));
                    float tetherPenalty = branchDist is not null
                        ? tetherWeight * MathF.Max(0f, (branchDist[di] / 3f - freeRadius) / tetherNorm)
                        : 0f;
                    float margin = (n - crownBias - tetherPenalty) - thresh;
                    if (margin <= 0f) continue;

                    float clusterAlpha = Math.Clamp(margin / 0.09f, 0f, 1f) * (oa / 255f);
                    int leafA = (int)MathF.Round(clusterAlpha * 255f);
                    if (leafA < 68) continue;

                    byte lr = origRgba[di * 4], lg = origRgba[di * 4 + 1], lb = origRgba[di * 4 + 2];
                    byte sa = compRgba[di * 4 + 3];
                    if (sa == 0 || leafA >= 252)
                    {
                        compRgba[di * 4] = lr;
                        compRgba[di * 4 + 1] = lg;
                        compRgba[di * 4 + 2] = lb;
                        compRgba[di * 4 + 3] = (byte)Math.Max(sa, Math.Min(255, leafA));
                        compZ[di] = MathF.Min(compZ[di], origZ[di]);
                    }
                    else
                    {
                        float af = leafA / 255f;
                        compRgba[di * 4] = (byte)MathF.Round(compRgba[di * 4] * (1f - af) + lr * af);
                        compRgba[di * 4 + 1] = (byte)MathF.Round(compRgba[di * 4 + 1] * (1f - af) + lg * af);
                        compRgba[di * 4 + 2] = (byte)MathF.Round(compRgba[di * 4 + 2] * (1f - af) + lb * af);
                        compRgba[di * 4 + 3] = (byte)Math.Max(sa, leafA);
                        compZ[di] = MathF.Min(compZ[di], origZ[di]);
                    }
                }
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
                    int di = dy * W + (p.NearX - minX + x);
                    if (owner[di] != pi || compRgba[di * 4 + 3] < 68) continue;
                    int dstX = p.Flip ? (p.NearW - 1 - x) : x;
                    int qi = y * p.NearW + dstX;
                    Buffer.BlockCopy(compRgba, di * 4, nearOutRgba, qi * 4, 4);
                    if (nearOutDepth is not null)
                    {
                        float zv = compZ[di] < 1e8f ? compZ[di] : centerZ;
                        nearOutDepth[qi] = (byte)Math.Clamp((int)MathF.Round((zv - p.DepthNear) / dSpan * 255f), 0, 254);
                    }
                }
            }

            var (medOutRgba, medOutDepth) = DownsampleSmooth(nearOutRgba, nearOutDepth, p.NearW, p.NearH, p.MedW, p.MedH, 2);
            byte[]? farOutRgba = null;
            byte[]? farOutDepth = null;
            if (p.HasFar)
                (farOutRgba, farOutDepth) = DownsampleSmooth(nearOutRgba, nearOutDepth, p.NearW, p.NearH, p.FarW, p.FarH, 4);

            outputs[pi] = new WitheredPartOverride(
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
                int blendedA = (int)MathF.Round(0.52f * avgA + 0.48f * aMax);
                if (blendedA < 68) continue;
                if (blendedA >= 242) blendedA = 255;

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
