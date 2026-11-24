using System.Numerics;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;
using SimsNative.Plugins;

namespace SimsSimulation;

internal static partial class SceneExporter
{
    private sealed record CapturedGroupObject(
        PluginObjectSpriteMember Member,
        ObjectEntry Entry,
        short[]? DynamicFlags);

    internal static Dictionary<(short ObjectId, int SpriteIndex), PluginObjectSpriteOverride>? BuildPluginSpriteOverrides(
        IffFile lot,
        SimulationWorld world,
        ObjectRegistry registry,
        LotCamera camera,
        int lotSize,
        IPluginObjectSpriteModifier? modifier,
        Func<XObject, Vector3> objectPosition,
        Func<XObject?, bool> isContained)
    {
        if (modifier is null || modifier.SpriteVariant == 0)
            return null;

        var level1Rooms = world.LotRoomMaps.GetValueOrDefault(1);
        var groups = new Dictionary<short, List<CapturedGroupObject>>();

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

            var name = obj.TypeRecord?.Name ?? entry.Chunk.Label ?? entry.CatalogString(0, 1) ?? string.Empty;
            bool isBuildFoliage = entry.Definition[ObjdField.BuildModeType] == 4 ||
                (entry.Definition[ObjdField.MasterId] != 0 &&
                 registry.FindAlternativeType(entry)?.Definition[ObjdField.BuildModeType] == 4);

            int tx = obj.Position.X >> 4;
            int ty = obj.Position.Y >> 4;
            bool outside = level1Rooms is null ||
                ((uint)tx < (uint)level1Rooms.Width && (uint)ty < (uint)level1Rooms.Height &&
                 level1Rooms.RoomAt(tx, ty) is var room && room != RoomMap.NoRoom && level1Rooms.IsOutside(room));
            bool sheltered = IsShelteredAt(lot, world, lotSize, obj.Position);
            short leadId = obj.MultiTileMasterId != 0 ? obj.MultiTileMasterId : obj.Id;

            var candidate = new PluginObjectSpriteMember(
                obj.Id,
                leadId,
                guid,
                name,
                isBuildFoliage,
                outside,
                sheltered,
                objectPosition(obj),
                obj[ObjectData.Direction],
                obj[ObjectData.Graphic]);

            if (!modifier.SelectsObject(candidate))
                continue;

            if (!groups.TryGetValue(leadId, out var list))
            {
                list = new List<CapturedGroupObject>(4);
                groups[leadId] = list;
            }
            list.Add(new CapturedGroupObject(candidate, entry, obj.DynamicSpriteFlags));
        }

        if (groups.Count == 0)
            return null;

        var result = new Dictionary<(short ObjectId, int SpriteIndex), PluginObjectSpriteOverride>();
        const float mediumUnitHeight = 152f / 7f;

        foreach (var (_, members) in groups)
        {
            members.Sort(static (a, b) => a.Member.Guid != b.Member.Guid
                ? a.Member.Guid.CompareTo(b.Member.Guid)
                : a.Member.ObjectId.CompareTo(b.Member.ObjectId));

            var captures = CaptureGroupParts(members, camera, mediumUnitHeight);
            if (captures.Count == 0)
                continue;

            var memberDescriptors = members.Select(static m => m.Member).ToArray();
            var transformed = modifier.TransformObjectGroup(camera.Orientation, memberDescriptors, captures);
            if (transformed is null)
                continue;

            for (int ci = 0; ci < captures.Count && ci < transformed.Count; ci++)
            {
                if (transformed[ci] is { } ov)
                    result[(members[captures[ci].MemberIndex].Member.ObjectId, captures[ci].SpriteIndex)] = ov;
            }
        }

        return result.Count > 0 ? result : null;
    }

    private static List<PluginObjectSpritePart> CaptureGroupParts(
        List<CapturedGroupObject> members,
        LotCamera camera,
        float mediumUnitHeight)
    {
        var captures = new List<PluginObjectSpritePart>(members.Count);
        for (int mi = 0; mi < members.Count; mi++)
        {
            var m = members[mi];
            var baseGraphic = (ushort)m.Entry.Definition[ObjdField.BaseGraphic];
            var selectedGraphic = SelectedGraphic(baseGraphic, m.Member.Graphic);
            var groupChunk = m.Entry.File.Find(ResourceType.Dgrp, selectedGraphic);
            if (groupChunk is null) continue;
            DrawGroup group;
            try { group = CachedGroup(m.Entry.File, groupChunk); }
            catch (ResourceFormatException) { continue; }

            var image = SelectedImage(group, m.Member.Direction, camera.Orientation);
            if (image is null) continue;
            var nearImage = SelectedImage(group, m.Member.Direction, camera.Orientation, 3);
            var farImage = SelectedImage(group, m.Member.Direction, camera.Orientation, 1);

            for (int si = 0; si < image.Sprites.Count; si++)
            {
                var sp = image.Sprites[si];
                if (!DynamicSpriteVisible(sp.SpriteId, m.Entry.Definition[ObjdField.DynamicSpritesBaseId],
                        m.Entry.Definition[ObjdField.NumDynamicSprites], m.DynamicFlags))
                    continue;
                var (medFrame, medLegacy, medW, medH, medPal) = ReadDgrpPart(m.Entry.File, sp, m.Member.ObjectId, null);
                if ((medFrame is null && medLegacy is null) || !FrameHasPixels(medW, medH))
                    continue;
                var medRgba = GetPartRgbaBytes(m.Entry.File, sp, medFrame, medLegacy, medW, medH, medPal);
                if (medRgba is null) continue;
                var medDepth = medFrame is not null ? GetPartDepthBytes(m.Entry.File, sp, medFrame) : null;

                var (offX, offY) = RotateCardinalOffset(m.Member.Direction, sp.Offset2, sp.Offset3);
                var offset = new Vector3(offX, offY, sp.Offset1);
                var point = camera.Project(m.Member.Origin.X + offset.X / 16f, m.Member.Origin.Y + offset.Y / 16f, m.Member.Origin.Z * 40f);
                int medScreenX = (int)(point.X + sp.X);
                int medScreenY = (int)(point.Y - offset.Z / 5f * mediumUnitHeight - medH + sp.Y);
                bool flip = (sp.Flags & 1) != 0;
                var depthRange = medDepth is not null ? SpriteDepth(camera, m.Member.Origin, offset) : (Near: 0.5f, Far: 0.52f);

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
                    var (nf, nl, nw, nh, npal) = ReadDgrpPart(m.Entry.File, nsp, m.Member.ObjectId, null);
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
                    var (ff, fl, fw, fh, _) = ReadDgrpPart(m.Entry.File, fsp, m.Member.ObjectId, null);
                    if ((ff is not null || fl is not null) && (ff is not null) == (medFrame is not null) && FrameHasPixels(fw, fh))
                    {
                        hasFar = true;
                        farW = fw;
                        farH = fh;
                    }
                }

                captures.Add(new PluginObjectSpritePart(
                    mi, si, nearScreenX, nearScreenY, nearW, nearH, flip,
                    depthRange.Near, depthRange.Far,
                    nearRgba, nearDepth, medW, medH, farW, farH, hasNear, hasFar));
            }
        }
        return captures;
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
}
