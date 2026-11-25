using System.Numerics;
using System.Buffers.Binary;
using System.Collections.Concurrent;
using System.Diagnostics;
using System.Globalization;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsSimulation;

internal static partial class SceneExporter
{

    private static int ResolveWallTexture(
        IffFile? wallArtwork,
        string gameRoot,
        Dictionary<ushort, string> lotWallMap,
        Dictionary<int, string> dynamicWallFiles,
        ushort pattern,
        WallStyleArt styleArt,
        int frame,
        bool down,
        int zoom,
        List<Texture> textures,
        Dictionary<string, byte[]> files,
        Dictionary<(ushort Pattern, IffFile? File, ushort SpriteBase, ushort BaseStyle, int Frame, bool Down, int Zoom), int> wallTextures,
        HashSet<string>? missingResources)
    {
        if (wallArtwork is null)
        {
            missingResources?.Add("GameData/walls.iff");
            return -1;
        }
        var key = (pattern, styleArt.File, styleArt.SpriteBase, styleArt.BaseStyle, frame, down, zoom);
        if (wallTextures.TryGetValue(key, out var cached)) return cached;
        IffFile patternFile;
        ushort patternSpriteId;
        if (pattern is >= 256 and < 65534)
        {
            IffFile? dynamicWallArt = null;
            if (lotWallMap.TryGetValue(pattern, out var lotWallFile) &&
                WallpaperCatalog.TryOpenWallpaperIffByName(gameRoot, lotWallFile, out var mappedWall))
            {
                dynamicWallArt = mappedWall;
            }
            else if (dynamicWallFiles.TryGetValue(pattern, out var dynamicWallPath))
            {
                dynamicWallArt = OpenArtwork(dynamicWallPath);
            }
            if (dynamicWallArt is null)
            {
                missingResources?.Add($"wall:{pattern}:resource");
                patternFile = wallArtwork;
                patternSpriteId = WallPatternId(0, zoom);
            }
            else
            {
                patternFile = dynamicWallArt;
                patternSpriteId = zoom switch { 0 => 1, 2 => 2049, _ => 1793 };
            }
        }
        else
        {
            patternFile = wallArtwork;
            patternSpriteId = WallPatternId(pattern, zoom);
        }
        var patternChunk = patternFile.Find(ResourceType.Spr1, patternSpriteId);
        if (patternChunk is null)
        {
            missingResources?.Add($"wall:{pattern}:zoom:{zoom}");
            if (!ReferenceEquals(patternFile, wallArtwork) || pattern != 0)
            {
                patternFile = wallArtwork;
                patternSpriteId = WallPatternId(0, zoom);
                patternChunk = wallArtwork.Find(ResourceType.Spr1, patternSpriteId);
            }
            if (patternChunk is null) return -1;
        }
        IffFile maskFile;
        IffChunk maskChunk;
        if (styleArt.File is { } objectFile)
        {
            // Object wall masks store 6 SPR# chunks: [up far/med/near, down far/med/near].
            var maskId = ResolveWallMaskId(styleArt, down, zoom);
            var candidateMask = objectFile.Find(ResourceType.Spr1, maskId);
            if (candidateMask is null)
            {
                missingResources?.Add($"wall:{pattern}:object-style:{styleArt.SpriteBase}:zoom:{zoom}:down:{down}");
                var fallbackMaskId = WallMaskId(1, down, zoom);
                var fallbackMaskChunk = wallArtwork.Find(ResourceType.Spr1, fallbackMaskId);
                if (fallbackMaskChunk is null) return -1;
                maskFile = wallArtwork;
                maskChunk = fallbackMaskChunk;
            }
            else
            {
                maskFile = objectFile;
                maskChunk = candidateMask;
            }
        }
        else
        {
            var maskId = ResolveWallMaskId(styleArt, down, zoom);
            var candidateMask = wallArtwork.Find(ResourceType.Spr1, maskId);
            if (candidateMask is null && down)
            {
                maskId = WallMaskId(styleArt.BaseStyle, false, zoom);
                candidateMask = wallArtwork.Find(ResourceType.Spr1, maskId);
            }
            if (candidateMask is null)
            {
                missingResources?.Add($"wall:{pattern}:style:{styleArt.BaseStyle}:zoom:{zoom}");
                return -1;
            }
            maskFile = wallArtwork;
            maskChunk = candidateMask;
        }
        var patternSprite = CachedSprite(patternFile, patternChunk);
        var maskSprite = CachedSprite(maskFile, maskChunk);
        if (frame >= patternSprite.Frames.Count || frame >= maskSprite.Frames.Count)
        {
            missingResources?.Add($"wall:{pattern}:style:{styleArt.BaseStyle}:zoom:{zoom}:frame:{frame}");
            return -1;
        }
        var art = patternSprite.Frames[frame];
        var colors = PaletteFor(patternFile, WallPaletteId(patternSprite.PaletteId));
        if (colors is null || colors.Length == 0)
        {
            missingResources?.Add($"wall-palette:{pattern}");
            return -1;
        }
        if (wallRgbaBytesCache.Count > 512) wallRgbaBytesCache.Clear();
        var rendered = wallRgbaBytesCache.GetOrAdd((patternFile, patternChunk.Id, maskFile, maskChunk.Id, frame), k =>
        {
            var mask = maskSprite.Frames[k.Frame];
            var buffer = new byte[art.Width * art.Height * 4];
            for (var py = 0; py < art.Height; py++)
            for (var px = 0; px < art.Width; px++)
            {
                var pixel = py * art.Width + px;
                if (!art.Opaque[pixel]) continue;
                var colorIndex = art.Indices[pixel];
                var color = colorIndex < colors.Length ? colors[colorIndex] : default;
                var maskX = px * mask.Width / art.Width;
                var maskY = py * mask.Height / art.Height;
                var visible = mask.Opaque[maskY * mask.Width + maskX];
                var at = pixel * 4;
                buffer[at] = color.Red;
                buffer[at + 1] = color.Green;
                buffer[at + 2] = color.Blue;
                buffer[at + 3] = visible ? (byte)255 : (byte)0;
            }
            return (art.Width, art.Height, buffer);
        });
        var styleName = styleArt.File is null ? styleArt.BaseStyle.ToString() : $"obj{styleArt.SpriteBase}";
        var name = $"wall-{pattern}-{styleName}-{frame}-{(down ? "down" : "up")}-{zoom}.rgba";
        files[name] = rendered.Bytes;
        var result = textures.Count;
        textures.Add(new Texture(name, rendered.Width, rendered.Height, "rgba"));
        wallTextures[key] = result;
        return result;
    }

    private static int SplitVerticalWallTexture(
        int leftTexture,
        int rightTexture,
        List<Texture> textures,
        Dictionary<string, byte[]> files,
        Dictionary<(int Left, int Right), int> splitTextures)
    {
        if (leftTexture < 0) return rightTexture;
        if (rightTexture < 0 || leftTexture == rightTexture) return leftTexture;
        var key = (leftTexture, rightTexture);
        if (splitTextures.TryGetValue(key, out var cached)) return cached;
        var left = textures[leftTexture];
        var right = textures[rightTexture];
        if (left.Width != right.Width || left.Height != right.Height || left.Encoding != "rgba" || right.Encoding != "rgba")
            return rightTexture;
        var width = left.Width;
        var height = left.Height;
        var half = width / 2;
        var leftBytes = files[left.File];
        var rightBytes = files[right.File];
        var combined = new byte[width * height * 4];
        var leftRowBytes = half * 4;
        var rightRowBytes = (width - half) * 4;
        var stride = width * 4;
        for (var row = 0; row < height; row++)
        {
            var rowOffset = row * stride;
            Array.Copy(leftBytes, rowOffset, combined, rowOffset, leftRowBytes);
            Array.Copy(rightBytes, rowOffset + leftRowBytes, combined, rowOffset + leftRowBytes, rightRowBytes);
        }
        var name = $"wall-split-{Path.GetFileNameWithoutExtension(left.File)}-{Path.GetFileNameWithoutExtension(right.File)}.rgba";
        files[name] = combined;
        var result = textures.Count;
        textures.Add(new Texture(name, width, height, "rgba"));
        splitTextures[key] = result;
        return result;
    }

    private static (DepthFrame? Frame, IndexedFrame? Legacy, int Width, int Height, int PaletteId) ReadDgrpPart(
        IffFile file,
        DrawGroupSprite part,
        short objectId,
        HashSet<string>? missingResources)
    {
        var sprChunk = file.Find(ResourceType.Spr2, (ushort)part.SpriteId);
        if (sprChunk is not null)
        {
            var art = CachedDepthSprite(file, sprChunk);
            if (part.Frame < 0 || part.Frame >= art.Frames.Count)
            {
                missingResources?.Add($"object:{objectId}:sprite:{part.SpriteId}:frame:{part.Frame}:frames:{art.Frames.Count}");
                return (null, null, 0, 0, -1);
            }
            var depthFrame = art.Frames[part.Frame];
            return (depthFrame, null, depthFrame.Width, depthFrame.Height, art.PaletteId);
        }
        var legacyChunk = file.Find(ResourceType.Spr1, (ushort)part.SpriteId);
        if (legacyChunk is null)
        {
            missingResources?.Add($"object:{objectId}:sprite:{part.SpriteId}:chunk-absent");
            return (null, null, 0, 0, -1);
        }
        var legacyArt = CachedSprite(file, legacyChunk);
        if (part.Frame < 0 || part.Frame >= legacyArt.Frames.Count)
        {
            missingResources?.Add($"object:{objectId}:sprite:{part.SpriteId}:frame:{part.Frame}:frames:{legacyArt.Frames.Count}");
            return (null, null, 0, 0, -1);
        }
        var legacyFrame = legacyArt.Frames[part.Frame];
        return (null, legacyFrame, legacyFrame.Width, legacyFrame.Height, legacyArt.PaletteId);
    }

    private static byte[]? GetPartRgbaBytes(
        IffFile file,
        DrawGroupSprite part,
        DepthFrame? frame,
        IndexedFrame? legacy,
        int width,
        int height,
        int paletteId)
    {
        var palette = PaletteFor(file, paletteId);
        if (palette is null) return null;
        var doubleAlpha = (part.Flags & 0x10) != 0;
        var spriteKey = part.SpriteId | (doubleAlpha ? 0x1000000 : 0);
        if (partRgbaBytesCache.Count > 1024) partRgbaBytesCache.Clear();
        var cacheKey = (file, paletteId, spriteKey | (frame is null ? 0x2000000 : 0), part.Frame);
        return partRgbaBytesCache.GetOrAdd(cacheKey, _ =>
        {
            var buffer = new byte[width * height * 4];
            for (var pixel = 0; pixel < width * height; pixel++)
            {
                // Sims.exe culls 5-bit SPR2 alpha values below 8 as transparent.
                var visible = frame is not null ? frame.Alpha[pixel] >= 8 : legacy!.Opaque[pixel];
                if (!visible) continue;
                var color = palette[frame is not null ? frame.Indices[pixel] : legacy!.Indices[pixel]];
                var at = pixel * 4;
                buffer[at] = color.Red;
                buffer[at + 1] = color.Green;
                buffer[at + 2] = color.Blue;
                var alpha = frame is null ? (byte)255 : (byte)Math.Clamp((frame.Alpha[pixel] * 255 + 15) / 31, 0, 255);
                if (doubleAlpha) alpha = alpha < 0x80 ? (byte)(alpha << 1) : (byte)0xff;
                buffer[at + 3] = alpha;
            }
            return buffer;
        });
    }

    private static byte[] GetPartDepthBytes(IffFile file, DrawGroupSprite part, DepthFrame frame)
    {
        if (partDepthBytesCache.Count > 1024) partDepthBytesCache.Clear();
        return partDepthBytesCache.GetOrAdd((file, part.SpriteId, part.Frame), _ =>
        {
            var srcDepth = frame.Depth;
            var srcAlpha = frame.Alpha;
            var buffer = new byte[srcDepth.Length];
            for (var pixel = 0; pixel < srcDepth.Length; pixel++)
                buffer[pixel] = srcAlpha[pixel] < 8 ? (byte)255 : srcDepth[pixel];
            return buffer;
        });
    }

    private static void WriteGhostAssetFiles(string directory, Kept kept, Dictionary<string, byte[]> files)
    {
        if (files.Count == 0) return;
        var inMemory = SimsSimulation.InMemorySessionAssets.IsInMemoryPath(directory);
        if (!inMemory) Directory.CreateDirectory(directory);
        foreach (var (name, bytes) in files)
        {
            var target = Path.Combine(directory, name);
            if (!kept.Written.Add(name) &&
                (inMemory ? SimsSimulation.InMemorySessionAssets.ContainsFile(target) : File.Exists(target)))
                continue;
            if (inMemory) SimsSimulation.InMemorySessionAssets.StoreFile(target, bytes);
            else File.WriteAllBytes(target, bytes);
        }
    }

    internal static bool TryBuildPlacementGhost(
        ObjectRegistry registry,
        SimulationWorld world,
        short house,
        AnimationState state,
        long revision,
        string directory,
        IReadOnlyList<XObject> entities,
        int viewLevel,
        int cameraOrientation,
        int lotSize,
        out object? ghost)
    {
        ghost = null;
        if (state.Revision != revision ||
            state.Kept is not Kept kept ||
            kept.CameraOrientation != cameraOrientation ||
            kept.ViewLevel != viewLevel ||
            kept.Heights.Length < Size * Size)
        {
            return false;
        }

        foreach (var entity in entities)
        {
            if (entity is XPerson) return false;
            foreach (var slot in entity.RuntimeSlots)
            {
                if (slot.ReadWord(0x10) != 0) return false;
            }
        }

        var activeLotSize = world.Globals.Length > 23 && world.Globals[23] is > 0 and <= Size ? world.Globals[23] : lotSize;
        var camera = new LotCamera(cameraOrientation, activeLotSize, activeLotSize);
        float[] slotHeightOffsets = [0f, 2.5f, 4f, 4.05f, 0f, 0f, 0f, 4f, 0f];
        var objectPositions = new Dictionary<XObject, Vector3>(ReferenceEqualityComparer.Instance);
        var resolvingContainment = new HashSet<XObject>(ReferenceEqualityComparer.Instance);

        Vector3 RootPosition(ObjectPosition tile) =>
            new(tile.X / 16f, tile.Y / 16f,
                (tile.Height - 1) * EntityTransform.StoryHeight +
                ElevationAt(kept.Heights, kept.BaseHeight, tile.X / 16f + 0.5f, tile.Y / 16f + 0.5f) / 40);

        bool TryResolveSlotPosition(XObject container, int index, out Vector3 position)
        {
            if (!TryResolveObjectPosition(container, out var origin))
            {
                position = default;
                return false;
            }
            if (index < 0)
            {
                position = origin;
                return true;
            }
            var defSlots = container.DefinitionSlots;
            var matchedSlotIndex = -1;
            var matchIndex = 0;
            for (var s = 0; s < defSlots.Count; s++)
            {
                if (defSlots[s].Type != 0) continue;
                if (matchIndex == index) { matchedSlotIndex = s; break; }
                matchIndex++;
            }
            if (matchedSlotIndex < 0)
            {
                position = origin;
                return true;
            }
            var slotDef = defSlots[matchedSlotIndex];
            float height;
            switch (slotDef.Height)
            {
                case 1 or 2 or 3 or 4 or 8:
                    height = slotHeightOffsets[slotDef.Height - 1];
                    break;
                case >= 0 and <= 9:
                    height = slotDef.Z;
                    break;
                default:
                    position = default;
                    return false;
            }
            var (rotatedX, rotatedY) = RotateCardinalOffset(container[ObjectData.Direction], slotDef.X / 16f, slotDef.Y / 16f);
            position = origin + new Vector3(rotatedX, rotatedY, height / 5);
            return true;
        }

        bool TryResolveObjectPosition(XObject entity, out Vector3 position)
        {
            if (objectPositions.TryGetValue(entity, out position)) return true;
            if (!resolvingContainment.Add(entity))
            {
                position = RootPosition(entity.Position);
                return true;
            }
            try
            {
                var container = ContainmentParent(world, entity) ??
                    (entity[ObjectData.ContainerId] != 0 ? world.ObjectById(entity[ObjectData.ContainerId]) : null);
                if (container is XPerson)
                {
                    position = default;
                    return false;
                }
                var hierarchySlot = entity[ObjectData.SlotHierNumber];
                if (hierarchySlot > 0 && container is not null)
                {
                    if (!TryResolveSlotPosition(container, hierarchySlot - 1, out position))
                        return false;
                }
                else
                {
                    position = RootPosition(entity.Position);
                }
                objectPositions.Add(entity, position);
                return true;
            }
            finally
            {
                resolvingContainment.Remove(entity);
            }
        }

        var textures = new List<Texture>();
        var files = new Dictionary<string, byte[]>(StringComparer.Ordinal);
        var spriteTextures = new Dictionary<(uint Guid, int SpriteId, int Frame), int>();
        var spriteDepthTextures = new Dictionary<(uint Guid, int SpriteId, int Frame), int>();
        var sprites = new List<SceneSprite>();

        foreach (var entity in entities)
        {
            if (entity.Position.Height < 1 || entity.Position.Height > viewLevel) continue;
            if (entity.Position.X < 0 || entity.Position.Y < 0) continue;
            if (entity[ObjectData.Hidden] != 0) continue;
            if (entity.Definition is { Length: > (int)ObjdField.MasterId } &&
                entity.Definition[(int)ObjdField.SubIndex] < 0 &&
                entity.Definition[(int)ObjdField.MasterId] != 0)
                continue;
            var guid = unchecked((uint)(entity.TypeRecord?.Key ?? 0));
            if (guid == 2179383033u) continue;
            var entry = registry.Find(guid);
            if (entry is null) continue;
            if (!TryResolveObjectPosition(entity, out var origin))
                return false;

            var entityLevel = entity.Position.Height;
            var subtileRoom = ResolveGhostSubtileRoom(world.LotRoomMaps.GetValueOrDefault(entityLevel), origin, entity);
            AppendDgrpGhostSprites(
                entry, guid, entity.Id, entity[ObjectData.Graphic], origin, entity[ObjectData.Direction],
                entityLevel, camera, house, subtileRoom, IsHierarchyContained(entity),
                entity[ObjectData.LightingContribution0100] != 0, entity.DynamicSpriteFlags,
                textures, files, spriteTextures, spriteDepthTextures, sprites);
        }

        if (sprites.Count == 0) return true;
        ghost = FinalizeGhostObject(directory, kept, cameraOrientation, textures, files, sprites);
        return true;
    }

    internal static bool TryBuildCursorGhost(
        ObjectRegistry registry,
        SimulationWorld world,
        short house,
        AnimationState state,
        long revision,
        string directory,
        uint guid,
        short objectId,
        short graphic,
        ObjectPosition position,
        int direction,
        int cameraOrientation,
        int lotSize,
        short[]? dynamicSpriteFlags,
        out object? ghost)
    {
        ghost = null;
        if (state.Revision != revision ||
            state.Kept is not Kept kept ||
            kept.CameraOrientation != cameraOrientation ||
            kept.ViewLevel != position.Height ||
            kept.Heights.Length < Size * Size)
        {
            return false;
        }
        if (position.Height < 1 || position.X < 0 || position.Y < 0 || guid == 2179383033u)
            return true;

        var entry = registry.Find(guid);
        if (entry is null) return false;
        if ((short)entry.Definition[ObjdField.SubIndex] < 0 && entry.Definition[ObjdField.MasterId] != 0)
            return true;

        var activeLotSize = world.Globals.Length > 23 && world.Globals[23] is > 0 and <= Size ? world.Globals[23] : lotSize;
        var camera = new LotCamera(cameraOrientation, activeLotSize, activeLotSize);
        var source = world.ObjectById(objectId);
        var origin = source is null
            ? new Vector3(
                position.X / 16f,
                position.Y / 16f,
                (position.Height - 1) * EntityTransform.StoryHeight + ElevationAt(kept.Heights, kept.BaseHeight, position.X / 16f + 0.5f, position.Y / 16f + 0.5f) / 40)
            : new Vector3(
                source.Position.X / 16f,
                source.Position.Y / 16f,
                (source.Position.Height - 1) * EntityTransform.StoryHeight + ElevationAt(kept.Heights, kept.BaseHeight, source.Position.X / 16f + 0.5f, source.Position.Y / 16f + 0.5f) / 40);
        var subtileRoom = ResolveGhostSubtileRoom(world.LotRoomMaps.GetValueOrDefault(position.Height), origin, source);

        var textures = new List<Texture>();
        var files = new Dictionary<string, byte[]>(StringComparer.Ordinal);
        var spriteTextures = new Dictionary<(uint Guid, int SpriteId, int Frame), int>();
        var spriteDepthTextures = new Dictionary<(uint Guid, int SpriteId, int Frame), int>();
        var sprites = new List<SceneSprite>();
        if (!AppendDgrpGhostSprites(
                entry, guid, objectId, graphic, origin, direction, position.Height, camera, house,
                subtileRoom, contained: false, litLightSource: false, dynamicSpriteFlags,
                textures, files, spriteTextures, spriteDepthTextures, sprites))
            return false;

        if (sprites.Count == 0) return true;
        ghost = FinalizeGhostObject(directory, kept, cameraOrientation, textures, files, sprites);
        return true;
    }

    private static int? ResolveGhostSubtileRoom(RoomMap? roomMap, Vector3 origin, XObject? source)
    {
        if (roomMap is null) return null;
        var r = roomMap.RoomAtPosition(
            Math.Clamp((int)(origin.X * 16f), 0, roomMap.Width * 16 - 1),
            Math.Clamp((int)(origin.Y * 16f), 0, roomMap.Height * 16 - 1));
        return r == RoomMap.NoRoom && source is not null && source.RoomWord84 >= 0 && source.RoomWord84 != RoomMap.NoRoom
            ? source.RoomWord84
            : r;
    }

    private static bool AppendDgrpGhostSprites(
        ObjectEntry entry,
        uint guid,
        short objectId,
        short graphic,
        Vector3 origin,
        int direction,
        int level,
        LotCamera camera,
        short house,
        int? subtileRoom,
        bool contained,
        bool litLightSource,
        short[]? dynamicSpriteFlags,
        List<Texture> textures,
        Dictionary<string, byte[]> files,
        Dictionary<(uint Guid, int SpriteId, int Frame), int> spriteTextures,
        Dictionary<(uint Guid, int SpriteId, int Frame), int> spriteDepthTextures,
        List<SceneSprite> sprites)
    {
        var baseGraphic = (ushort)entry.Definition[ObjdField.BaseGraphic];
        var selectedGraphic = SelectedGraphic(baseGraphic, graphic);
        var groupChunk = entry.File.Find(ResourceType.Dgrp, selectedGraphic);
        if (groupChunk is null) return false;

        DrawGroup group;
        try { group = CachedGroup(entry.File, groupChunk); }
        catch (ResourceFormatException) { return false; }

        var image = SelectedImage(group, direction, camera.Orientation);
        if (image is null) return false;
        var nearImage = SelectedImage(group, direction, camera.Orientation, 3);
        var farImage = SelectedImage(group, direction, camera.Orientation, 1);
        var mediumUnitHeight = (float)(Math.Sqrt(64 * 64 / 2.0) * Math.Cos(Math.PI / 6));

        int PartTexture(DrawGroupSprite part, DepthFrame? frame, IndexedFrame? legacy, int width, int height, int paletteId)
        {
            var doubleAlpha = (part.Flags & 0x10) != 0;
            var spriteKey = part.SpriteId | (doubleAlpha ? 0x1000000 : 0);
            var key = (guid, spriteKey, part.Frame);
            if (spriteTextures.TryGetValue(key, out var tex)) return tex;
            var bytes = GetPartRgbaBytes(entry.File, part, frame, legacy, width, height, paletteId);
            if (bytes is null) return -1;
            var baseName = $"sprite-{guid:x8}-{part.SpriteId}-{part.Frame}.rgba";
            var name = doubleAlpha && files.ContainsKey(baseName)
                ? $"sprite-{guid:x8}-{part.SpriteId}-{part.Frame}-a2.rgba"
                : baseName;
            files[name] = bytes;
            tex = textures.Count;
            textures.Add(new Texture(name, width, height, "rgba"));
            spriteTextures[key] = tex;
            return tex;
        }

        int? PartDepth(DrawGroupSprite part, DepthFrame? frame, int width, int height)
        {
            if (frame is null) return null;
            var key = (guid, part.SpriteId, part.Frame);
            if (spriteDepthTextures.TryGetValue(key, out var depthIndex)) return depthIndex;
            var depthBytes = GetPartDepthBytes(entry.File, part, frame);
            var depthName = $"sprite-depth-{guid:x8}-{part.SpriteId}-{part.Frame}.depth8";
            files[depthName] = depthBytes;
            depthIndex = textures.Count;
            textures.Add(new Texture(depthName, width, height, "depth8"));
            spriteDepthTextures[key] = depthIndex;
            return depthIndex;
        }

        for (var index = 0; index < image.Sprites.Count; index++)
        {
            var sprite = image.Sprites[index];
            if (!DynamicSpriteVisible(sprite.SpriteId, entry.Definition[ObjdField.DynamicSpritesBaseId],
                    entry.Definition[ObjdField.NumDynamicSprites], dynamicSpriteFlags))
                continue;
            var (frame, legacy, width, height, paletteId) = ReadDgrpPart(entry.File, sprite, objectId, null);
            if (frame is null && legacy is null) continue;
            if (!FrameHasPixels(width, height)) continue;
            var texture = PartTexture(sprite, frame, legacy, width, height, paletteId);
            if (texture < 0) continue;
            var depthTexture = PartDepth(sprite, frame, width, height);
            var (offsetX, offsetY) = RotateCardinalOffset(direction, sprite.Offset2, sprite.Offset3);
            var offset = new Vector3(offsetX, offsetY, sprite.Offset1);
            var point = camera.Project(origin.X + offset.X / 16, origin.Y + offset.Y / 16, origin.Z * 40);
            var spriteX = (int)(point.X + sprite.X);
            var spriteY = (int)(point.Y - offset.Z / 5 * mediumUnitHeight - height + sprite.Y);

            ZoomImage? Zoom(DrawGroupImage? zoomed, float scale)
            {
                if (zoomed is null || index >= zoomed.Sprites.Count) return null;
                if (zoomed.Sprites.Count != image.Sprites.Count && index != 0) return null;
                var other = zoomed.Sprites[index];
                if ((other.Flags & 1) != (sprite.Flags & 1)) return null;
                var (otherFrame, otherLegacy, otherWidth, otherHeight, otherPalette) = ReadDgrpPart(entry.File, other, objectId, null);
                if (otherFrame is null && otherLegacy is null) return null;
                if ((otherFrame is not null) != (frame is not null)) return null;
                if (!FrameHasPixels(otherWidth, otherHeight)) return null;
                var otherTexture = PartTexture(other, otherFrame, otherLegacy, otherWidth, otherHeight, otherPalette);
                if (otherTexture < 0) return null;
                var otherDepth = PartDepth(other, otherFrame, otherWidth, otherHeight);
                if (otherDepth.HasValue != depthTexture.HasValue) return null;
                var zoomedX = (int)(scale * point.X + other.X) / scale;
                var zoomedY = (int)(scale * (point.Y - offset.Z / 5 * mediumUnitHeight) - otherHeight + other.Y) / scale;
                return new ZoomImage(otherTexture, zoomedX - spriteX, zoomedY - spriteY, otherWidth / scale,
                    otherHeight / scale, otherDepth);
            }

            var depth = depthTexture.HasValue ? SpriteDepth(camera, origin, offset) : (Near: 0f, Far: 0f);
            var sortDepth = camera.DepthOrder(origin.X + offset.X / 16, origin.Y + offset.Y / 16) +
                0.001f * origin.Z + (contained ? 0.01f : 0f);
            var unlitSprite = (sprite.Flags & 4) != 0 || house == 99 ||
                (litLightSource && entry.Definition[ObjdField.Type] != 8);
            var room = unlitSprite ? null : entry.Definition[ObjdField.BuildModeType] == 7 ? 65534 : subtileRoom;
            sprites.Add(new SceneSprite(texture, spriteX, spriteY, width, height, (sprite.Flags & 1) != 0, objectId,
                sortDepth, 1,
                depthTexture, depthTexture.HasValue ? depth.Near : null, depthTexture.HasValue ? depth.Far : null,
                Level: level, Room: room, Near: Zoom(nearImage, 2f), Far: Zoom(farImage, 0.5f)));
        }

        return true;
    }

    private static JsonObject FinalizeGhostObject(
        string directory,
        Kept kept,
        int cameraOrientation,
        List<Texture> textures,
        Dictionary<string, byte[]> files,
        List<SceneSprite> sprites)
    {
        WriteGhostAssetFiles(directory, kept, files);
        var minX = sprites.Min(s => s.X);
        var minY = sprites.Min(s => s.Y);
        var maxX = sprites.Max(s => s.X + s.Width);
        var maxY = sprites.Max(s => s.Y + s.Height);
        var ghostSprites = sprites.OrderBy(s => s.Depth)
            .Select(s => s with { X = s.X - minX, Y = s.Y - minY })
            .ToArray();
        var ghostScene = new JsonObject
        {
            ["schemaVersion"] = 1,
            ["house"] = 0,
            ["width"] = maxX - minX,
            ["height"] = maxY - minY,
            ["cameraOrientation"] = cameraOrientation,
            ["textures"] = JsonSerializer.SerializeToNode(textures, Json),
            ["sprites"] = JsonSerializer.SerializeToNode(ghostSprites, Json),
            ["limitations"] = new JsonArray(),
        };
        return new JsonObject { ["x"] = minX + kept.ShiftX, ["y"] = minY + kept.ShiftY, ["scene"] = ghostScene };
    }

    internal static bool TryBuildWallPaintGhost(
        IffFile lot,
        SimulationWorld world,
        string gameRoot,
        string directory,
        AnimationState state,
        long revision,
        int wallLevel,
        string wallMode,
        LotWalls previewWalls,
        IReadOnlySet<(int X, int Y, int Level, int Direction)> changedWalls,
        int cameraOrientation,
        int lotSize,
        out object? wallPreview)
    {
        wallPreview = null;
        if (state.Revision != revision ||
            state.Kept is not Kept kept ||
            kept.CameraOrientation != cameraOrientation ||
            kept.ViewLevel != wallLevel ||
            !string.Equals(kept.WallMode, wallMode, StringComparison.Ordinal) ||
            kept.Heights.Length < Size * Size ||
            kept.ObjectStyles is null ||
            kept.WallObjectKinds is null)
        {
            return false;
        }
        if (changedWalls.Count == 0) return true;

        var wallArtwork = TryOpenOptionalArtwork(Path.Combine(gameRoot, "GameData", "walls.iff"));
        if (wallArtwork is null) return false;

        var activeLotSize = world.Globals.Length > 23 && world.Globals[23] is > 0 and <= Size ? world.Globals[23] : lotSize;
        var camera = new LotCamera(cameraOrientation, activeLotSize, activeLotSize);
        var uniqueTiles = new HashSet<(int X, int Y)>();
        var orderedTiles = new List<(int V, int U, int X, int Y)>();
        foreach (var changed in changedWalls)
        {
            if (changed.Level != wallLevel) continue;
            if ((uint)changed.X >= (uint)lotSize || (uint)changed.Y >= (uint)lotSize ||
                changed.X >= LotWalls.Size || changed.Y >= LotWalls.Size)
                continue;
            if (!uniqueTiles.Add((changed.X, changed.Y))) continue;
            var cp = camera.CameraPoint(changed.X + 0.5f, changed.Y + 0.5f);
            orderedTiles.Add(((int)MathF.Floor(cp.Y), (int)MathF.Floor(cp.X), changed.X, changed.Y));
        }
        if (orderedTiles.Count == 0) return true;
        orderedTiles.Sort(static (a, b) =>
        {
            var cmp = a.V.CompareTo(b.V);
            return cmp != 0 ? cmp : a.U.CompareTo(b.U);
        });

        var gameDataPath = Path.Combine(gameRoot, "GameData");
        var dynamicWallFiles = DynamicWallFiles(gameDataPath);
        var lotWallMap = ReadLotMaterialMap(lot, WalmType);
        var wallRooms = world.LotRoomMaps.TryGetValue(wallLevel, out var wallRoomMap) ? wallRoomMap : null;
        var cutawayMask = kept.CutawayMask;
        var objectStyles = kept.ObjectStyles;
        var wallObjectKinds = kept.WallObjectKinds;
        var hasLiveObjects = kept.HasLiveObjects;
        var levelForcedDown = wallMode == "down";
        var levelCutaway = wallMode == "cutaway";

        var textures = new List<Texture>();
        var files = new Dictionary<string, byte[]>(StringComparer.Ordinal);
        var wallTextures = new Dictionary<(ushort Pattern, IffFile? File, ushort SpriteBase, ushort BaseStyle, int Frame, bool Down, int Zoom), int>();
        var wallSplitTextures = new Dictionary<(int Left, int Right), int>();
        var wallDepthTextures = new Dictionary<(int Configuration, int Width, int Height), int>();
        var sprites = new List<SceneSprite>();

        float Elevation(float x, float y) => ElevationAt(kept.Heights, kept.BaseHeight, x, y);

        bool IsDoorEdge(int ownerX, int ownerY, int side, ushort storedStyle) =>
            wallObjectKinds.GetValueOrDefault((wallLevel, ownerX, ownerY, side)) == 1 ||
            (!hasLiveObjects && storedStyle is 3 or 5 or 6 or 15 or 23);

        bool IsWindowEdge(int ownerX, int ownerY, int side, ushort storedStyle) =>
            wallObjectKinds.GetValueOrDefault((wallLevel, ownerX, ownerY, side)) == 2 ||
            (!hasLiveObjects && storedStyle is 4 or 9 or 10 or 11 or (>= 16 and <= 22));

        int WallTexture(ushort pattern, WallStyleArt styleArt, int frame, bool isDown, int zoom) =>
            ResolveWallTexture(wallArtwork, gameRoot, lotWallMap, dynamicWallFiles, pattern, styleArt,
                frame, isDown, zoom, textures, files, wallTextures, null);

        int ArchitectureDepth(int configuration, int colorTexture)
        {
            var dimensions = textures[colorTexture];
            return ResolveArchitectureDepthTexture(configuration, dimensions.Width, dimensions.Height,
                textures, files, wallDepthTextures);
        }

        ZoomImage? Zoom(ushort pattern, WallStyleArt wallStyle, int zoom, float scale,
            (int X, int Y, int Width, int Height)[] rectangles, int configuration, int artFace, bool isDown)
        {
            var art = WallTexture(pattern, wallStyle, artFace, isDown, zoom);
            if (art < 0) return null;
            var medium = WallRectangles[artFace];
            var zoomed = rectangles[artFace];
            return new ZoomImage(art, zoomed.X / scale - medium.X, zoomed.Y / scale - medium.Y,
                zoomed.Width / scale, zoomed.Height / scale, ArchitectureDepth(configuration, art));
        }

        foreach (var (v, u, sourceX, sourceY) in orderedTiles)
        {
            bool Cutaway(int otherX, int otherY) =>
                levelCutaway && cutawayMask is not null && otherX >= 0 && otherY >= 0 && otherX < lotSize && otherY < lotSize &&
                cutawayMask[sourceY * lotSize + sourceX] && cutawayMask[otherY * lotSize + otherX];

            void AddFace(int face, int neighbourX, int neighbourY)
            {
                var (ownerX, ownerY, side) = EdgeOwner(sourceX, sourceY, neighbourX, neighbourY);
                if (ownerX < 0 || ownerY < 0 || ownerX >= lotSize || ownerY >= lotSize ||
                    ownerX >= LotWalls.Size || ownerY >= LotWalls.Size)
                    return;
                var owner = previewWalls[ownerX, ownerY];
                if ((owner[0] & (side == 0 ? 1 : 2)) == 0) return;
                var sourceDirection = camera.SourceWallDirection(face);
                var storedStyle = previewWalls.GetStyle(ownerX, ownerY, side);
                var style = NormalizedWallStyle(storedStyle);
                if (style != 1 || !changedWalls.Contains((sourceX, sourceY, wallLevel, sourceDirection))) return;
                var faceDown = levelForcedDown || Cutaway(neighbourX, neighbourY);
                if (faceDown && IsDoorEdge(ownerX, ownerY, side, storedStyle)) return;
                var patternSlot = neighbourX < sourceX ? 4 : neighbourX > sourceX ? 7 : neighbourY < sourceY ? 5 : 6;
                var pattern = previewWalls.GetPattern(sourceX, sourceY, patternSlot);
                var objectStyle = objectStyles.GetValueOrDefault((wallLevel, ownerX, ownerY, side));
                var wallStyle = faceDown && IsWindowEdge(ownerX, ownerY, side, storedStyle)
                    ? WallStyleArt.Base(1)
                    : ResolveWallStyle(style, objectStyle);
                var texture = WallTexture(pattern, wallStyle, face, faceDown, 1);
                if (texture < 0) return;
                var altitude = Elevation(sourceX, sourceY) / 40f + (wallLevel - 1) * EntityTransform.StoryHeight;
                var interval = camera.SpriteDepthCamera(u, v, altitude);
                var point = camera.ProjectCamera(u, v, altitude * 40);
                var rectangle = WallRectangles[face];
                var (faceSubX, faceSubY) = sourceDirection switch
                {
                    0 => (2, 8),
                    1 => (8, 2),
                    2 => (13, 8),
                    _ => (8, 13),
                };
                var faceRoom = wallRooms is not null && sourceX >= 0 && sourceY >= 0 && sourceX < wallRooms.Width && sourceY < wallRooms.Height
                    ? wallRooms.RoomAtPosition(sourceX * 16 + faceSubX, sourceY * 16 + faceSubY)
                    : wallRooms?.RoomAt(sourceX, sourceY);
                sprites.Add(new SceneSprite(texture, point.X - 34 + rectangle.X, point.Y - 158 + rectangle.Y,
                    rectangle.Width, rectangle.Height, false, 0, camera.DepthOrderCamera(u, v) - 0.5f, 1,
                    ArchitectureDepth(face + 4, texture), interval.Near, interval.Far,
                    Wall: new WallSide(sourceX, sourceY, wallLevel, sourceDirection),
                    Level: wallLevel, Room: faceRoom,
                    ArchitectureDepth: new WallDepth(sourceX, sourceY, wallLevel, face + 4),
                    Near: Zoom(pattern, wallStyle, 2, 2f, NearWallRectangles, face, face, faceDown),
                    Far: Zoom(pattern, wallStyle, 0, 0.5f, FarWallRectangles, face + 8, face, faceDown)));
            }

            void AddDiagonal()
            {
                var owner = previewWalls[sourceX, sourceY];
                var sourceDiag = owner[0] & 0x30;
                if (sourceDiag is not (0x10 or 0x20)) return;
                var cameraDiag = camera.Orientation % 2 == 0 ? sourceDiag : sourceDiag ^ 0x30;
                var face = cameraDiag == 0x10 ? 2 : 3;
                var sourceDirection = camera.SourceWallDirection(face);
                var storedStyle = previewWalls.GetStyle(sourceX, sourceY, 1);
                if (NormalizedWallStyle(storedStyle) != 1 || !changedWalls.Contains((sourceX, sourceY, wallLevel, sourceDirection)))
                    return;
                var style = storedStyle;
                var diagDown = levelForcedDown ||
                    (levelCutaway && style is not (2 or 12 or 13 or 14) && cutawayMask is not null && cutawayMask[sourceY * lotSize + sourceX]);
                if (diagDown && IsDoorEdge(sourceX, sourceY, 1, storedStyle)) return;
                var (primarySlot, facingSide) = DiagonalFacingSlotAndSide(sourceDiag, camera.Orientation);
                var secondarySlot = primarySlot == 6 ? 7 : 6;
                var primaryPattern = previewWalls.GetPattern(sourceX, sourceY, primarySlot);
                var secondaryPattern = previewWalls.GetPattern(sourceX, sourceY, secondarySlot);
                var pattern = primaryPattern != 0 ? primaryPattern : secondaryPattern;
                var leftPattern = secondaryPattern != 0 ? secondaryPattern : primaryPattern;
                var objectStyle = objectStyles.GetValueOrDefault((wallLevel, sourceX, sourceY, 1));
                var wallStyle = diagDown && IsWindowEdge(sourceX, sourceY, 1, storedStyle)
                    ? WallStyleArt.Base(1)
                    : ResolveWallStyle(style, objectStyle);
                int DiagTexture(int zoom) => face == 3 && leftPattern != pattern
                    ? SplitVerticalWallTexture(WallTexture(leftPattern, wallStyle, face, diagDown, zoom),
                        WallTexture(pattern, wallStyle, face, diagDown, zoom), textures, files, wallSplitTextures)
                    : WallTexture(pattern, wallStyle, face, diagDown, zoom);
                ZoomImage? DiagZoom(int zoom, float scale, (int X, int Y, int Width, int Height)[] rectangles, int configuration)
                {
                    var art = DiagTexture(zoom);
                    if (art < 0) return null;
                    var medium = WallRectangles[face];
                    var zoomed = rectangles[face];
                    return new ZoomImage(art, zoomed.X / scale - medium.X, zoomed.Y / scale - medium.Y,
                        zoomed.Width / scale, zoomed.Height / scale, ArchitectureDepth(configuration, art));
                }
                var texture = DiagTexture(1);
                if (texture < 0) return;
                var altitude = Elevation(sourceX, sourceY) / 40f + (wallLevel - 1) * EntityTransform.StoryHeight;
                var interval = camera.SpriteDepthCamera(u, v, altitude);
                var point = camera.ProjectCamera(u, v, altitude * 40);
                var rectangle = WallRectangles[face];
                var (diagSubX, diagSubY) = sourceDiag == 0x10
                    ? (primarySlot == 6 ? (4, 4) : (12, 12))
                    : (primarySlot == 6 ? (4, 12) : (12, 4));
                var diagRoom = wallRooms is not null && sourceX >= 0 && sourceY >= 0 && sourceX < wallRooms.Width && sourceY < wallRooms.Height
                    ? wallRooms.RoomAtPosition(sourceX * 16 + diagSubX, sourceY * 16 + diagSubY)
                    : wallRooms?.RoomAt(sourceX, sourceY);
                sprites.Add(new SceneSprite(texture, point.X - 34 + rectangle.X, point.Y - 158 + rectangle.Y,
                    rectangle.Width, rectangle.Height, false, 0, camera.DepthOrderCamera(u, v) - 0.5f, 1,
                    ArchitectureDepth(face + 4, texture), interval.Near, interval.Far,
                    Wall: new WallSide(sourceX, sourceY, wallLevel, sourceDirection, Edge: sourceDiag, Side: facingSide),
                    Level: wallLevel, Room: diagRoom,
                    ArchitectureDepth: new WallDepth(sourceX, sourceY, wallLevel, face + 4),
                    Near: DiagZoom(2, 2f, NearWallRectangles, face),
                    Far: DiagZoom(0, 0.5f, FarWallRectangles, face + 8)));
            }

            var (leftX, leftY) = camera.SourceTile(u - 1, v);
            var (upX, upY) = camera.SourceTile(u, v - 1);
            AddFace(0, leftX, leftY);
            AddFace(1, upX, upY);
            AddDiagonal();
        }

        if (sprites.Count == 0) return true;

        WriteGhostAssetFiles(directory, kept, files);
        var minX = sprites.Min(s => s.X);
        var minY = sprites.Min(s => s.Y);
        var maxX = sprites.Max(s => s.X + s.Width);
        var maxY = sprites.Max(s => s.Y + s.Height);
        var wallSprites = sprites.Select(s => s with { X = s.X - minX, Y = s.Y - minY }).ToArray();
        var ghostScene = new JsonObject
        {
            ["schemaVersion"] = 1,
            ["house"] = 0,
            ["width"] = maxX - minX,
            ["height"] = maxY - minY,
            ["lotWidth"] = lotSize,
            ["lotHeight"] = lotSize,
            ["viewLevel"] = wallLevel,
            ["stories"] = Stories(lot),
            ["cameraOrientation"] = cameraOrientation,
            ["textures"] = JsonSerializer.SerializeToNode(textures, Json),
            ["sprites"] = JsonSerializer.SerializeToNode(wallSprites, Json),
            ["limitations"] = new JsonArray(),
        };
        wallPreview = new JsonObject { ["x"] = minX + kept.ShiftX, ["y"] = minY + kept.ShiftY, ["scene"] = ghostScene };
        return true;
    }

    private static byte[] PackVertices(Vertex[] vertices, float shiftX, float shiftY)
    {
        var data = new byte[vertices.Length * 32];
        var span = data.AsSpan();
        var offset = 0;
        for (var i = 0; i < vertices.Length; i++)
        {
            ref readonly var vertex = ref vertices[i];
            BinaryPrimitives.WriteSingleLittleEndian(span.Slice(offset, 4), vertex.X + shiftX);
            BinaryPrimitives.WriteSingleLittleEndian(span.Slice(offset + 4, 4), vertex.Y + shiftY);
            BinaryPrimitives.WriteSingleLittleEndian(span.Slice(offset + 8, 4), vertex.Z);
            BinaryPrimitives.WriteSingleLittleEndian(span.Slice(offset + 12, 4), vertex.U);
            BinaryPrimitives.WriteSingleLittleEndian(span.Slice(offset + 16, 4), vertex.V);
            BinaryPrimitives.WriteSingleLittleEndian(span.Slice(offset + 20, 4), vertex.Nx);
            BinaryPrimitives.WriteSingleLittleEndian(span.Slice(offset + 24, 4), vertex.Ny);
            BinaryPrimitives.WriteSingleLittleEndian(span.Slice(offset + 28, 4), vertex.Nz);
            offset += 32;
        }
        return data;
    }

    private static readonly ConcurrentDictionary<string, IffFile> artworkFiles = new(StringComparer.Ordinal);
    private static readonly ConcurrentDictionary<string, IffFile?> optionalArtworkFiles = new(StringComparer.Ordinal);
    private static readonly ConcurrentDictionary<string, Dictionary<int, string>> dynamicFloors = new(StringComparer.Ordinal);
    private static readonly ConcurrentDictionary<string, Dictionary<int, string>> dynamicWalls = new(StringComparer.Ordinal);

    private static IffFile OpenArtwork(string path) =>
        artworkFiles.GetOrAdd(path, static p => IffFile.Open(p));

    private static IffFile? TryOpenOptionalArtwork(string path) =>
        optionalArtworkFiles.GetOrAdd(path, static p => File.Exists(p) ? OpenArtwork(p) : null);

    private static Dictionary<int, string> DynamicFloorFiles(string gameData) =>
        dynamicFloors.GetOrAdd(gameData, static gd => FloorCatalog.DynamicFiles(gd).ToDictionary());

    private static Dictionary<int, string> DynamicWallFiles(string gameData) =>
        dynamicWalls.GetOrAdd(gameData, static gd => WallpaperCatalog.DynamicFiles(gd).ToDictionary());

    // Parses house FLRm ("mRLF") / WALm ("mLAW") chunks mapping pattern IDs (>= 256) to .flr/.wll filenames.
    internal static Dictionary<ushort, string> ReadLotMaterialMap(IffFile lot, ResourceType chunkType)
    {
        var result = new Dictionary<ushort, string>();
        var chunk = lot.Find(chunkType, 1) ?? lot.Find(chunkType, 0);
        if (chunk is null)
            return result;

        try
        {
            var reader = new PersistReader(lot, chunk);
            var fileCount = reader.Int32();
            if (fileCount <= 0 || fileCount > 65536)
                return result;

            for (var i = 0; i < fileCount && reader.Remaining > 0; i++)
            {
                var name = reader.String();
                var entryCount = reader.Int32();
                if (entryCount < 0 || entryCount > 65536)
                    break;

                for (var j = 0; j < entryCount; j++)
                {
                    ushort patternId;
                    if (chunk.Id == 1)
                    {
                        patternId = unchecked((ushort)reader.Int16());
                        _ = reader.Int16();
                        _ = reader.Int32();
                    }
                    else
                    {
                        var b0 = reader.Byte();
                        var b1 = reader.Byte();
                        patternId = unchecked((ushort)(b0 | (b1 << 8)));
                        _ = reader.Int32();
                    }

                    if (patternId >= 256 && !string.IsNullOrWhiteSpace(name))
                        result.TryAdd(patternId, name);
                }
            }
        }
        catch (Exception ex) when (ex is ResourceFormatException or EndOfStreamException or InvalidDataException)
        {
        }

        return result;
    }

    private static float[] ReadHeights(IffFile lot)
    {
        var heights = new float[Size * Size];
        var array = ReadArray(lot, 0);
        if (array is null) return heights;
        for (var x = 0; x < Size; x++)
        for (var y = 0; y < Size; y++)
            heights[x * Size + y] = array.Element(x, y)[1] * 10;
        return heights;
    }

    private static short[] TerrainHeights(IffFile lot, int lotSize)
    {
        var result = new short[lotSize * lotSize];
        if (ReadArray(lot, 0) is not { } array) return result;
        for (var y = 0; y < lotSize; y++)
        for (var x = 0; x < lotSize; x++)
            result[y * lotSize + x] = array.Element(x, y)[1];
        return result;
    }

    private static byte[] ReadGrass(IffFile lot)
    {
        var grass = new byte[Size * Size];
        Array.Fill(grass, (byte)127);
        var array = ReadArray(lot, 6);
        if (array is null) return grass;
        for (var x = 0; x < Size; x++)
        for (var y = 0; y < Size; y++)
            // Arry 6 stores grass state as a signed delta subtracted from 127, where a raw byte of 255
            // represents grass state 128.
            grass[x * Size + y] = unchecked((byte)(127 - array.Element(x, y)[0]));
        return grass;
    }

    private static ushort[] ReadFloors(IffFile lot, int level)
    {
        var floors = new ushort[Size * Size];
        var advanced = ReadArray(lot, level == 1 ? 11 : 111);
        var standard = ReadArray(lot, level == 1 ? 1 : 101);
        if (advanced is not null && advanced.ElementSize >= 2)
        {
            for (var x = 0; x < Size; x++)
            for (var y = 0; y < Size; y++)
                floors[x * Size + y] = BitConverter.ToUInt16(advanced.Element(x, y)[..2]);
        }
        else if (standard is not null)
        {
            for (var x = 0; x < Size; x++)
            for (var y = 0; y < Size; y++)
                floors[x * Size + y] = standard.Element(x, y)[0];
        }
        if (level == 1)
        {
            var pool = ReadArray(lot, 9);
            var water = ReadArray(lot, 10);
            var waterSentinel = water is not null && water.Element(0, 0)[0] == 0xff ? (byte)0xff : (byte)0;
            for (var x = 0; x < Size; x++)
            for (var y = 0; y < Size; y++)
            {
                if (pool is not null && pool.Element(x, y)[0] < 0x10)
                    floors[x * Size + y] = 65535;
                else if (pool is not null && pool.Element(x, y)[0] == 0x10 && floors[x * Size + y] == 0)
                    floors[x * Size + y] = 12;
                else if (water is not null && water.Element(x, y)[0] != waterSentinel && floors[x * Size + y] == 0)
                    floors[x * Size + y] = 65534;
            }
        }
        return floors;
    }

    internal static XObject? ContainmentParent(SimulationWorld world, XObject entity)
    {
        var key = entity[ObjectData.ContainerId] > 0
            ? entity[ObjectData.ContainerId]
            : entity[ObjectData.SlotHierNumber] > 0 && entity[ObjectData.ParentId] > 0
                ? entity[ObjectData.ParentId]
                : (short)0;
        if (key <= 0) return null;
        // ContainerId/ParentId store object-table slot keys, not raw ObjectIds.
        return entity.ObjectTableEntry(key) ?? world.ObjectTableEntry(key);
    }

    // XPerson.Slots[2] holds logical slot 1 (head bone) because Slots[0] is a sentinel record.
    internal static bool HeadSlotTargets(SimulationWorld world, XPerson owner, XObject attached)
    {
        if (owner.Slots.Count <= 2) return false;
        var key = owner.Slots[2];
        return key != 0 && ReferenceEquals(owner.ObjectTableEntry(key) ?? world.ObjectTableEntry(key), attached);
    }

    internal static Vector3 ResolveObjectPosition(XObject entity, XObject? container,
        Func<ObjectPosition, Vector3> rootPosition,
        Func<XPerson, Vector3> headPosition,
        Func<XObject, int, Vector3> authoredSlotPosition,
        Func<XPerson, Vector3>? handPosition = null,
        Func<XPerson, Vector3>? pelvisPosition = null,
        Func<XPerson, Vector3>? headAttachmentPosition = null)
    {
        var hierarchySlot = entity[ObjectData.SlotHierNumber];
        if (hierarchySlot == 2 && container is XPerson person && entity is XPerson)
            return headPosition(person);
        if (hierarchySlot is 1 or 5 && container is XPerson handSim && entity is not XPerson && handPosition != null)
            return handPosition(handSim);
        if (hierarchySlot == 3 && container is XPerson pelvisSim && entity is not XPerson && pelvisPosition != null)
            return pelvisPosition(pelvisSim);
        if (hierarchySlot == 4 && container is XPerson headSim && entity is not XPerson && headAttachmentPosition != null)
            return headAttachmentPosition(headSim);
        if (hierarchySlot > 0 && container is not null)
            return authoredSlotPosition(container, hierarchySlot - 1);
        return rootPosition(entity.Position);
    }

    internal static bool IsHierarchyContained(XObject? entity) =>
        entity is not null && entity[ObjectData.SlotHierNumber] > 0 &&
        (entity[ObjectData.ContainerId] > 0 || entity[ObjectData.ParentId] > 0);

    private static (float X, float Y) RotateCardinalOffset(int direction, float dx, float dy) => (direction & 7) switch
    {
        0 => (dx, dy),
        2 => (-dy, dx),
        4 => (-dx, -dy),
        6 => (dy, -dx),
        _ => (0f, 0f),
    };

    private static (float Near, float Far) SpriteDepth(LotCamera camera, Vector3 centre,
        Vector3 offset)
    {
        const float HalfStep = 1f / 97.97959f; // 1 / (40 * sqrt(6))
        var anchor = camera.CameraPoint(centre.X + offset.X / 16f, centre.Y + offset.Y / 16f);
        var altitude = centre.Z + offset.Z / 5f;
        return (SceneDepth.Project(anchor.X + 200f * HalfStep, anchor.Y + 200f * HalfStep, altitude),
            SceneDepth.Project(anchor.X - 54f * HalfStep, anchor.Y - 54f * HalfStep, altitude));
    }

    private static readonly ConcurrentDictionary<(IffFile File, int PaletteId), PaletteColor[]?> objectPaletteCache = new();

    internal static PaletteColor[]? PaletteFor(IffFile file, int paletteId)
    {
        if (objectPaletteCache.Count > 512) objectPaletteCache.Clear();
        return objectPaletteCache.GetOrAdd((file, paletteId), static key =>
        {
            // SPR2/SPR# PaletteId is a PALT chunk ID (often >= 1000), not an index.
            var chunk = key.PaletteId is >= 0 and <= ushort.MaxValue
                ? key.File.Find(ResourceType.Palt, (ushort)key.PaletteId)
                : null;
            chunk ??= key.File.OfType(ResourceType.Palt).FirstOrDefault();
            return chunk is null ? null : Palette.Read(key.File, chunk).Colors.ToArray();
        });
    }

    private static LotArray? ReadWalls(IffFile lot, int level)
    {
        var advanced = ReadArray(lot, level == 1 ? 12 : 112);
        if (advanced is { ElementSize: >= 14 })
            return advanced;
        return ReadArray(lot, level == 1 ? 2 : 102);
    }

    private static ushort WallStyle0(ReadOnlySpan<byte> tile) =>
        tile.Length >= 14 ? BitConverter.ToUInt16(tile.Slice(2, 2)) : tile[2];

    private static ushort WallStyle1(ReadOnlySpan<byte> tile) =>
        tile.Length >= 14 ? BitConverter.ToUInt16(tile.Slice(4, 2)) : tile[3];

    private static ushort WallPattern(ReadOnlySpan<byte> tile, int slot) =>
        tile.Length >= 14 ? BitConverter.ToUInt16(tile.Slice(6 + (slot - 4) * 2, 2)) : tile[slot];

    private static LotArray? ReadArray(IffFile lot, int id)
    {
        var chunk = lot.Find(ResourceType.Parse("Arry"), (ushort)id);
        return chunk is null ? null : LotArray.Read(lot, chunk);
    }

    private sealed record SoundSourceJson(
        [property: JsonPropertyName("objectID")] short ObjectID,
        int Level,
        float X,
        float Y,
        float Z);

    private sealed record AnimatedJsonPayload(
        [property: JsonPropertyName("schemaVersion")] int SchemaVersion,
        [property: JsonPropertyName("baseRevision")] long BaseRevision,
        [property: JsonPropertyName("sequence")] long Sequence,
        [property: JsonPropertyName("updates")] long Updates,
        [property: JsonPropertyName("textureStart")] int TextureStart,
        [property: JsonPropertyName("lighting")] SceneLighting.State? Lighting,
        [property: JsonPropertyName("missingResources")] string[] MissingResources,
        [property: JsonPropertyName("textures")] Texture[] Textures,
        [property: JsonPropertyName("sprites")] SceneSprite[] Sprites,
        [property: JsonPropertyName("meshes")] object[] Meshes,
        [property: JsonPropertyName("censorRects")] CensorRect[] CensorRects,
        [property: JsonPropertyName("overheadFeedback"), JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] OverheadFeedbackRecord[]? OverheadFeedback,
        [property: JsonPropertyName("skillMeters"), JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] SkillMeterRecord[]? SkillMeters,
        [property: JsonPropertyName("voxelMap"), JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] OverheadMapRecord? VoxelMap = null,
        [property: JsonPropertyName("voxelMapCleared"), JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingDefault)] bool VoxelMapCleared = false);

    private sealed record FullJsonPayload(
        [property: JsonPropertyName("schemaVersion")] int SchemaVersion,
        [property: JsonPropertyName("house")] int House,
        [property: JsonPropertyName("width")] float Width,
        [property: JsonPropertyName("height")] float Height,
        [property: JsonPropertyName("lotWidth")] int LotWidth,
        [property: JsonPropertyName("lotHeight")] int LotHeight,
        [property: JsonPropertyName("floorDiagonals")] int[] FloorDiagonals,
        [property: JsonPropertyName("terrainHeights")] short[] TerrainHeights,
        [property: JsonPropertyName("cameraOrientation")] int CameraOrientation,
        [property: JsonPropertyName("originX")] float OriginX,
        [property: JsonPropertyName("originY")] float OriginY,
        [property: JsonPropertyName("wallMode")] string WallMode,
        [property: JsonPropertyName("wallsUp")] bool WallsUp,
        [property: JsonPropertyName("roofsVisible")] bool RoofsVisible,
        [property: JsonPropertyName("viewLevel")] int ViewLevel,
        [property: JsonPropertyName("stories")] int Stories,
        [property: JsonPropertyName("lighting")] SceneLighting.State? Lighting,
        [property: JsonPropertyName("textures")] Texture[] Textures,
        [property: JsonPropertyName("sprites")] SceneSprite[] Sprites,
        [property: JsonPropertyName("soundSources")] SoundSourceJson[] SoundSources,
        [property: JsonPropertyName("placementVertices")] TerrainVertex[] PlacementVertices,
        [property: JsonPropertyName("terrainVertices")] TerrainVertex[] TerrainVertices,
        [property: JsonPropertyName("meshes")] Mesh[] Meshes,
        [property: JsonPropertyName("censorRects")] CensorRect[] CensorRects,
        [property: JsonPropertyName("limitations")] string[] Limitations,
        [property: JsonPropertyName("missingResources")] string[] MissingResources,
        [property: JsonPropertyName("overheadMap")] OverheadMapRecord? OverheadMap,
        [property: JsonPropertyName("overheadFeedback"), JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] OverheadFeedbackRecord[]? OverheadFeedback,
        [property: JsonPropertyName("skillMeters"), JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] SkillMeterRecord[]? SkillMeters,
        [property: JsonPropertyName("voxelMap"), JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] OverheadMapRecord? VoxelMap = null);
}
