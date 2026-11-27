using System.Numerics;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsNative.Plugins;

namespace SimsSimulation;

internal static partial class SceneExporter
{
    private static readonly HashSet<uint> DisallowedWildSceneryGuids =
    [
        0xBB83A08Au, 0xD68E73D8u, 0xF2999F51u,
        0xE4FB60EBu, 0xE48328E1u, 0xE482787Cu, 0xE48D0746u, 0xE48C2A23u,
        0xAC66D6CAu, 0x1671A218u, 0x00DD7908u,
        0x34431396u, 0xB1153E7Du,
        0x54C3E0CFu, 0xFA733902u, 0x17332210u,
        0x5D723615u, 0x5D767E1Fu, 0x5D7B6688u,
        0x65274A4Fu, 0xA2DAA08Cu, 0xC02B406Au, 0x96E3398Du,
    ];

    private static readonly HashSet<uint> SnowMountainSceneryGuids =
    [
        0x3026A0F4u, 0xAA86AD2Au, 0x3007996Eu, 0xAED3C88Au, 0x72BDBB7Du,
    ];

    private static readonly HashSet<uint> BeachSandSceneryGuids =
    [
        0xDE802250u, 0xA02C8857u, 0xD9BD21CDu, 0xDC0BEF65u, 0x52ED4B7Cu, 0x11EC66D9u, 0x99400B4Au,
    ];

    private static uint[] BiomeFallbackFloraGuids(short house, int terrainType)
    {
        if (terrainType == 7 || house == 99)
            return [];
        if (terrainType == 3)
            return [0x3026A0F4u, 0xAA86AD2Au, 0x3007996Eu, 0xAED3C88Au, 0x72BDBB7Du];
        if (terrainType == 1)
            return [0xDE802250u, 0xA02C8857u, 0xD9BD21CDu, 0xDC0BEF65u, 0x52ED4B7Cu, 0x11EC66D9u];
        if (terrainType == 5 || house is >= 90 and <= 94)
            return [0xF9E11D1Cu, 0xB9020120u, 0x110CF4B1u, 0x39319021u, 0x1468C3A7u, 0x7C24A376u, 0xE9693F98u, 0x10444309u, 0x2ABC6E73u];
        if (terrainType == 6 || house is >= 95 and <= 98)
            return [0x110CF4B1u, 0xB9020120u, 0x39319021u, 0x09D8DCECu, 0x1468C3A7u, 0x7C24A376u, 0xE9693F98u, 0x10444309u, 0x2ABC6E73u];
        if (house is >= 81 and <= 89)
            return [0xA02C8857u, 0xDE802250u, 0x9DA7B210u, 0x678F09FFu, 0x3484C1F7u, 0x154522AFu, 0x15460FCAu, 0x2C555EA3u];
        if (house is >= 43 and <= 45)
            return [0x3026A0F4u, 0xAA86AD2Au, 0x3007996Eu, 0x39319021u, 0x1468C3A7u, 0x15460FCAu, 0x154522AFu];
        if (house is >= 20 and <= 39)
            return [0x5F421524u, 0x8BA56284u, 0x51474702u, 0x3484C1F7u, 0x9DA7B210u, 0xC99AC74Eu, 0x154522AFu, 0x2C555EA3u, 0x15460FCAu];
        if (house is >= 50 and <= 80)
            return [0x6854DA61u, 0xCEB2F9B8u, 0x39319021u, 0x1468C3A7u, 0x09D8DCECu, 0x5C198CBEu, 0x2C555EA3u, 0x15460FCAu, 0xD5CA5425u];
        return [0x39319021u, 0x1468C3A7u, 0x09D8DCECu, 0x2B83B971u, 0x5C198CBEu, 0x2C555EA3u, 0x154522AFu, 0xD5CA5425u];
    }

    private static bool IsEligibleWildScenery(ObjectRegistry registry, ObjectEntry lead, int terrainType)
    {
        uint guid = lead.Guid;
        if (DisallowedWildSceneryGuids.Contains(guid))
            return false;
        if (lead.Definition[ObjdField.Type] == 8 || lead.Definition[ObjdField.BuildModeType] != 4)
            return false;
        if (terrainType == 3)
            return SnowMountainSceneryGuids.Contains(guid);
        if (terrainType == 1)
            return BeachSandSceneryGuids.Contains(guid);
        if (SnowMountainSceneryGuids.Contains(guid) && (guid == 0xAED3C88Au || guid == 0x72BDBB7Du))
            return false;

        string label = lead.Chunk.Label ?? string.Empty;
        if (label.Contains("Hedge", StringComparison.OrdinalIgnoreCase) ||
            label.Contains("Topiar", StringComparison.OrdinalIgnoreCase) ||
            label.Contains("Curb", StringComparison.OrdinalIgnoreCase) ||
            label.Contains("Plot", StringComparison.OrdinalIgnoreCase) ||
            label.Contains("Lamp", StringComparison.OrdinalIgnoreCase) ||
            label.Contains("Lily", StringComparison.OrdinalIgnoreCase) ||
            label.Contains("Cat Tail", StringComparison.OrdinalIgnoreCase) ||
            label.Contains("Coped", StringComparison.OrdinalIgnoreCase))
        {
            return false;
        }

        return true;
    }

    private static (SceneSprite[][]? Prototypes, SceneryType[]? Types) BuildSceneryPrototypes(
        SimulationWorld world,
        ObjectRegistry registry,
        LotCamera camera,
        short house,
        int terrainType,
        int outsideLightByte,
        IReadOnlyDictionary<(IffFile File, ushort MasterId, ushort SubIndex), ObjectEntry> shadowParts,
        IPluginObjectSpriteModifier? spriteModifier,
        int spriteVariant,
        List<Texture> textures,
        Dictionary<string, byte[]> files,
        Dictionary<(uint Guid, int SpriteId, int Frame), int> spriteTextures,
        Dictionary<(uint Guid, int SpriteId, int Frame), int> spriteDepthTextures,
        Func<int?, int, int, int, float, float, float, ZoomImage?> floorShadowAt)
    {
        if (terrainType == 7 || house == 99)
            return (null, null);

        var lotCounts = new Dictionary<uint, int>();
        foreach (var obj in world.WalkOrder)
        {
            if (obj is XPerson || obj.Position.X < 0 || obj.Position.Y < 0 || obj[ObjectData.Hidden] != 0)
                continue;
            uint rawGuid = unchecked((uint)(obj.TypeRecord?.Key ?? 0));
            if (rawGuid == 0 || registry.Find(rawGuid) is not { } rawEntry)
                continue;
            ObjectEntry lead = rawEntry.Definition[ObjdField.MasterId] != 0
                ? (registry.FindAlternativeType(rawEntry) ?? rawEntry)
                : rawEntry;
            if (!IsEligibleWildScenery(registry, lead, terrainType))
                continue;
            lotCounts[lead.Guid] = lotCounts.GetValueOrDefault(lead.Guid) + 1;
        }

        var chosenGuids = new List<uint>(12);
        foreach (var kv in lotCounts.OrderByDescending(static kv => kv.Value).ThenBy(static kv => kv.Key))
        {
            if (chosenGuids.Count >= 7)
                break;
            chosenGuids.Add(kv.Key);
        }

        foreach (uint fallbackGuid in BiomeFallbackFloraGuids(house, terrainType))
        {
            if (chosenGuids.Count >= 11)
                break;
            if (chosenGuids.Contains(fallbackGuid))
                continue;
            if (registry.Find(fallbackGuid) is { } fbEntry && IsEligibleWildScenery(registry, fbEntry, terrainType))
                chosenGuids.Add(fallbackGuid);
        }

        if (chosenGuids.Count == 0)
            return (null, null);

        const float mediumUnitHeight = 152f / 7f;
        Vector2 refPoint = camera.Project(0f, 0f, 0f);
        Vector2 refCam = camera.CameraPoint(0f, 0f);
        float refSortDepth = refCam.X + refCam.Y;
        float refDepth = 0.62f - 0.003f * refSortDepth;

        int PartTexture(ObjectEntry partEntry, uint partGuid, DrawGroupSprite part, DepthFrame? frame, IndexedFrame? legacy, int width, int height, int paletteId, byte[]? overrideRgba, int stageTag)
        {
            bool doubleAlpha = (part.Flags & 0x10) != 0;
            int spriteKey = part.SpriteId | (doubleAlpha ? 0x1000000 : 0) | (stageTag << 25);
            var key = (partGuid, spriteKey, part.Frame);
            if (spriteTextures.TryGetValue(key, out int cached))
                return cached;
            byte[]? bytes = overrideRgba ?? GetPartRgbaBytes(partEntry.File, part, frame, legacy, width, height, paletteId);
            if (bytes is null)
                return -1;
            string stageSuffix = stageTag > 0 ? $"-f{stageTag}" : "";
            string baseName = $"sprite-{partGuid:x8}-{part.SpriteId}-{part.Frame}{stageSuffix}.rgba";
            string name = doubleAlpha && files.ContainsKey(baseName)
                ? $"sprite-{partGuid:x8}-{part.SpriteId}-{part.Frame}{stageSuffix}-a2.rgba"
                : baseName;
            files[name] = bytes;
            int idx = textures.Count;
            textures.Add(new Texture(name, width, height, "rgba"));
            spriteTextures[key] = idx;
            return idx;
        }

        int? PartDepth(ObjectEntry partEntry, uint partGuid, DrawGroupSprite part, DepthFrame? frame, int width, int height, byte[]? overrideDepth, int stageTag)
        {
            if (frame is null)
                return null;
            var key = (partGuid, part.SpriteId | (stageTag << 25), part.Frame);
            if (spriteDepthTextures.TryGetValue(key, out int cached))
                return cached;
            byte[] depthBytes = overrideDepth ?? GetPartDepthBytes(partEntry.File, part, frame);
            string stageSuffix = stageTag > 0 ? $"-f{stageTag}" : "";
            string depthName = $"sprite-depth-{partGuid:x8}-{part.SpriteId}-{part.Frame}{stageSuffix}.depth8";
            files[depthName] = depthBytes;
            int idx = textures.Count;
            textures.Add(new Texture(depthName, width, height, "depth8"));
            spriteDepthTextures[key] = idx;
            return idx;
        }

        var groups = new List<SceneSprite[]>(chosenGuids.Count);
        var types = new List<SceneryType>(chosenGuids.Count);
        for (int pIdx = 0; pIdx < chosenGuids.Count; pIdx++)
        {
            if (registry.Find(chosenGuids[pIdx]) is not { } lead)
                continue;

            ushort master = lead.Definition[ObjdField.MasterId];
            List<(ObjectEntry Entry, float Rx, float Ry)> subTiles = [];
            if (master != 0)
            {
                foreach (var candidate in registry.Entries)
                {
                    if (!ReferenceEquals(candidate.File, lead.File) || candidate.Definition[ObjdField.MasterId] != master)
                        continue;
                    ushort rawSub = candidate.Definition[ObjdField.SubIndex];
                    if (rawSub == ushort.MaxValue)
                        continue;
                    int sx = unchecked((short)rawSub) >> 8;
                    int sy = rawSub & 0xff;
                    subTiles.Add((candidate, sx, sy));
                }
            }
            if (subTiles.Count == 0)
                subTiles.Add((lead, 0f, 0f));

            float avgX = subTiles.Average(static t => t.Rx);
            float avgY = subTiles.Average(static t => t.Ry);
            for (int i = 0; i < subTiles.Count; i++)
                subTiles[i] = (subTiles[i].Entry, subTiles[i].Rx - avgX, subTiles[i].Ry - avgY);
            subTiles.Sort((a, b) => camera.DepthOrder(a.Rx, a.Ry).CompareTo(camera.DepthOrder(b.Rx, b.Ry)));

            short forcedGraphic = terrainType == 3 && SnowMountainSceneryGuids.Contains(lead.Guid) ? (short)1 : (short)0;
            Dictionary<(short ObjectId, int SpriteIndex), PluginObjectSpriteOverride>? protoOverrides = null;
            short baseFakeId = (short)(-1000 - pIdx * 32);

            if (spriteModifier is not null && spriteVariant != 0 && terrainType != 3)
            {
                var capturedMembers = new List<CapturedGroupObject>(subTiles.Count);
                for (int si = 0; si < subTiles.Count; si++)
                {
                    var st = subTiles[si];
                    short fakeObjId = (short)(baseFakeId - si);
                    string objName = st.Entry.Chunk.Label ?? st.Entry.CatalogString(0, 1) ?? string.Empty;
                    var member = new PluginObjectSpriteMember(
                        fakeObjId,
                        baseFakeId,
                        st.Entry.Guid,
                        objName,
                        true,
                        true,
                        false,
                        new Vector3(st.Rx, st.Ry, 0f),
                        0,
                        forcedGraphic);
                    if (spriteModifier.SelectsObject(member))
                        capturedMembers.Add(new CapturedGroupObject(member, st.Entry, null));
                }

                if (capturedMembers.Count > 0)
                {
                    capturedMembers.Sort(static (a, b) => a.Member.Guid != b.Member.Guid
                        ? a.Member.Guid.CompareTo(b.Member.Guid)
                        : a.Member.ObjectId.CompareTo(b.Member.ObjectId));
                    var captures = CaptureGroupParts(capturedMembers, camera, mediumUnitHeight);
                    if (captures.Count > 0)
                    {
                        var descriptors = capturedMembers.Select(static m => m.Member).ToArray();
                        if (spriteModifier.TransformObjectGroup(camera.Orientation, descriptors, captures) is { } transformed)
                        {
                            protoOverrides = new Dictionary<(short ObjectId, int SpriteIndex), PluginObjectSpriteOverride>();
                            for (int ci = 0; ci < captures.Count && ci < transformed.Count; ci++)
                            {
                                if (transformed[ci] is { } ov)
                                    protoOverrides[(capturedMembers[captures[ci].MemberIndex].Member.ObjectId, captures[ci].SpriteIndex)] = ov;
                            }
                        }
                    }
                }
            }

            var protoSprites = new List<SceneSprite>();
            for (int si = 0; si < subTiles.Count; si++)
            {
                var (partEntry, rx, ry) = subTiles[si];
                short fakeObjId = (short)(baseFakeId - si);
                ushort baseGraphic = (ushort)partEntry.Definition[ObjdField.BaseGraphic];
                if (baseGraphic == 0)
                    continue;
                int numGrp = partEntry.Definition[ObjdField.NumGraphics];
                ushort selGraphic = forcedGraphic > 0 && forcedGraphic < numGrp
                    ? (ushort)(baseGraphic + forcedGraphic)
                    : baseGraphic;
                if (partEntry.File.Find(ResourceType.Dgrp, selGraphic) is not { } groupChunk)
                    continue;

                DrawGroup group;
                try { group = CachedGroup(partEntry.File, groupChunk); }
                catch (ResourceFormatException) { continue; }

                if (SelectedImage(group, 0, camera.Orientation) is not { } image)
                    continue;
                var nearImage = SelectedImage(group, 0, camera.Orientation, 3);
                var farImage = SelectedImage(group, 0, camera.Orientation, 1);
                var origin = new Vector3(rx, ry, 0f);
                bool emittedShadowForSubTile = false;

                for (int spIdx = 0; spIdx < image.Sprites.Count; spIdx++)
                {
                    var sp = image.Sprites[spIdx];
                    if (!DynamicSpriteVisible(sp.SpriteId, partEntry.Definition[ObjdField.DynamicSpritesBaseId],
                            partEntry.Definition[ObjdField.NumDynamicSprites], null))
                        continue;

                    var (frame, legacy, width, height, paletteId) = ReadDgrpPart(partEntry.File, sp, 0, null);
                    if ((frame is null && legacy is null) || !FrameHasPixels(width, height))
                        continue;

                    PluginObjectSpriteOverride? ov = protoOverrides is not null && protoOverrides.TryGetValue((fakeObjId, spIdx), out var foundOv)
                        ? foundOv
                        : null;
                    int stageTag = ov is not null ? spriteVariant : 0;
                    int tex = PartTexture(partEntry, partEntry.Guid, sp, frame, legacy, width, height, paletteId, ov?.MediumRgba, stageTag);
                    if (tex < 0)
                        continue;
                    int? depthTex = PartDepth(partEntry, partEntry.Guid, sp, frame, width, height, ov?.MediumDepth, stageTag);
                    var (offsetX, offsetY) = RotateCardinalOffset(0, sp.Offset2, sp.Offset3);
                    var offset = new Vector3(offsetX, offsetY, sp.Offset1);
                    Vector2 point = camera.Project(origin.X + offset.X / 16f, origin.Y + offset.Y / 16f, 0f);
                    int spriteX = (int)(point.X + sp.X);
                    int spriteY = (int)(point.Y - offset.Z / 5f * mediumUnitHeight - height + sp.Y);

                    ZoomImage? BuildZoom(DrawGroupImage? zoomed, float zScale, byte[]? zRgba, byte[]? zDepth)
                    {
                        if (zoomed is null || spIdx >= zoomed.Sprites.Count)
                            return null;
                        if (zoomed.Sprites.Count != image.Sprites.Count && spIdx != 0)
                            return null;
                        var other = zoomed.Sprites[spIdx];
                        if ((other.Flags & 1) != (sp.Flags & 1))
                            return null;
                        var (oFrame, oLegacy, oW, oH, oPal) = ReadDgrpPart(partEntry.File, other, 0, null);
                        if ((oFrame is null && oLegacy is null) || (oFrame is not null) != (frame is not null) || !FrameHasPixels(oW, oH))
                            return null;
                        int zStage = zRgba is not null ? stageTag : 0;
                        int oTex = PartTexture(partEntry, partEntry.Guid, other, oFrame, oLegacy, oW, oH, oPal, zRgba, zStage);
                        if (oTex < 0)
                            return null;
                        int? oDepth = PartDepth(partEntry, partEntry.Guid, other, oFrame, oW, oH, zDepth, zStage);
                        if (oDepth.HasValue != depthTex.HasValue)
                            return null;
                        float zoomedX = (int)(zScale * point.X + other.X) / zScale;
                        float zoomedY = (int)(zScale * (point.Y - offset.Z / 5f * mediumUnitHeight) - oH + other.Y) / zScale;
                        return new ZoomImage(oTex, zoomedX - spriteX, zoomedY - spriteY, oW / zScale, oH / zScale, oDepth);
                    }

                    var rawDepth = depthTex.HasValue ? SpriteDepth(camera, origin, offset) : (Near: 0f, Far: 0f);
                    float relSort = camera.DepthOrder(origin.X + offset.X / 16f, origin.Y + offset.Y / 16f) - refSortDepth;

                    int? shadowId = ShadowId(partEntry, shadowParts);
                    if (shadowId is int rawMask)
                        shadowId = RotateShadowId(rawMask, camera.Orientation & 3);
                    short shadowBrightness = (short)partEntry.Definition[ObjdField.ShadowBrightness];

                    ZoomImage? fsMed = null;
                    ZoomImage? fsNear = null;
                    ZoomImage? fsFar = null;
                    if (!emittedShadowForSubTile && shadowId is not null)
                    {
                        emittedShadowForSubTile = true;
                        ZoomImage? RelShadow(int zoom)
                        {
                            var abs = floorShadowAt(shadowId, shadowBrightness, outsideLightByte, zoom, origin.X, origin.Y, 0f);
                            return abs is null ? null : abs with { X = abs.X - spriteX, Y = abs.Y - spriteY };
                        }
                        fsMed = RelShadow(2);
                        fsNear = RelShadow(3);
                        fsFar = RelShadow(1);
                    }

                    protoSprites.Add(new SceneSprite(
                        tex,
                        spriteX - refPoint.X,
                        spriteY - refPoint.Y,
                        width,
                        height,
                        (sp.Flags & 1) != 0,
                        0,
                        relSort,
                        1,
                        depthTex,
                        depthTex.HasValue ? rawDepth.Near - refDepth : null,
                        depthTex.HasValue ? rawDepth.Far - refDepth : null,
                        Level: 1,
                        Room: (sp.Flags & 4) != 0 ? null : 255,
                        Near: BuildZoom(nearImage, 2f, ov?.NearRgba, ov?.NearDepth),
                        Far: BuildZoom(farImage, 0.5f, ov?.FarRgba, ov?.FarDepth),
                        Shadow: shadowId,
                        ShadowBrightness: shadowBrightness,
                        FloorShadow: fsMed,
                        FloorShadowNear: fsNear,
                        FloorShadowFar: fsFar));
                }
            }

            if (protoSprites.Count > 0 && protoSprites.Count <= 64)
            {
                groups.Add([.. protoSprites]);
                string leadName = lead.Chunk.Label ?? lead.CatalogString(0, 1) ?? string.Empty;
                types.Add(new SceneryType(lead.Guid, leadName));
            }
        }

        return groups.Count > 0 ? ([.. groups], [.. types]) : (null, null);
    }
}
