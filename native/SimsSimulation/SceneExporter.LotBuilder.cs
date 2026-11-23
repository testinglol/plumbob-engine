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

    private static object Build(IffFile lot, SimulationWorld world, ObjectRegistry registry, string gameRoot, string directory, short house, long revision, int viewLevel, string wallMode, int cameraOrientation, (int X, int Y)? cutawayTile, bool roofsVisible, AnimationState? retain, bool animating, long sequence, long updates, IReadOnlyList<ushort>? cutawayRooms, (int X, int Y)? cutawaySim, int cutawayZoom, bool showLoweredPortals = false, float subTickAlpha = 0f, bool directAnimation = false, bool hideInteriorPeople = false, bool allowPlumbbob = true, short? authoritativeSelectedPersonId = null, bool raiseHoveredWalls = false)
    {
        var shadowParts = GetShadowParts(registry);
        // SIMI global 23 defines the active lot size, while saved ARRY layers retain a fixed 64-cell
        // storage stride.
        var lotSize = world.Globals.Length > 23 && world.Globals[23] is > 0 and <= Size ? world.Globals[23] : Size;
        var lapWatch = ProfileEnabled ? Stopwatch.StartNew() : null;
        var lapText = ProfileEnabled ? new StringBuilder() : null;
        void Lap(string name)
        {
            if (lapWatch is null || lapText is null) return;
            lapText.Append($" {name}={lapWatch.ElapsedMilliseconds}");
            lapWatch.Restart();
        }
        var kept = animating ? (Kept)retain!.Kept! : new Kept();
        var heights = animating ? kept.Heights : ReadHeights(lot);
        var baseHeight = animating ? kept.BaseHeight : heights[0];
        var rooms = world.LotRoomMaps.TryGetValue(viewLevel, out var roomMap) ? roomMap : null;
        var camera = new LotCamera(cameraOrientation, lotSize, lotSize);
        var stamp = LightingStamp(world);
        SceneLighting.State? baseLighting;
        if (animating &&
            kept.CachedLightingHouse == house &&
            kept.CachedLightingXor == stamp.Xor &&
            kept.CachedLightingSum == stamp.Sum &&
            kept.CachedLightingRoomCount == stamp.RoomCount &&
            kept.CachedLightingMapRooms == stamp.MapRooms &&
            kept.CachedLightingMinute == stamp.Minute &&
            kept.CachedLightingPhase == stamp.Phase)
        {
            baseLighting = kept.CachedLighting;
        }
        else
        {
            baseLighting = SceneLighting.Build(world, rooms, house);
            kept.CachedLighting = baseLighting;
            kept.CachedLightingHouse = house;
            kept.CachedLightingXor = stamp.Xor;
            kept.CachedLightingSum = stamp.Sum;
            kept.CachedLightingRoomCount = stamp.RoomCount;
            kept.CachedLightingMapRooms = stamp.MapRooms;
            kept.CachedLightingMinute = stamp.Minute;
            kept.CachedLightingPhase = stamp.Phase;
        }

        int TileSpriteLightByte(int? subtileRoom)
        {
            if (house == 99 || baseLighting is null) return 255;
            if (subtileRoom is { } roomId && roomId >= 0 && roomId < baseLighting.Rooms.Length)
                return baseLighting.Rooms[roomId].R;
            return baseLighting.Outside.R;
        }

        float HeightAt(int x, int y) => HeightAtArray(heights, x, y);
        float Elevation(float x, float y) => ElevationAt(heights, baseHeight, x, y);

        var terrain = animating ? null! : new List<TerrainVertex>();
        var meshVertices = animating ? null! : new List<(Vertex Vertex, int TileX, int TileY)>();
        var textures = animating ? kept.Textures : new List<Texture>();
        var animationStart = animating ? textures.Count : 0;
        var files = new Dictionary<string, byte[]>();
        var meshes = new List<Mesh>();
        var sprites = new List<SceneSprite>();
        var missingResources = new HashSet<string>(StringComparer.Ordinal);
        IffFile? floorArtwork;
        if (animating && kept.HasFloorArtwork)
        {
            floorArtwork = kept.FloorArtwork;
        }
        else
        {
            floorArtwork = TryOpenOptionalArtwork(Path.Combine(gameRoot, "GameData", "floors.iff"));
            kept.FloorArtwork = floorArtwork;
            kept.HasFloorArtwork = true;
        }
        var floorShadowTextures = animating
            ? kept.FloorShadowTextures
            : new Dictionary<(int Shadow, int Attenuation, int Zoom), int?>();
        var spriteTextures = animating ? kept.SpriteTextures : new Dictionary<(uint Guid, int SpriteId, int Frame), int>();
        var speechImageTextures = animating ? kept.SpeechImageTextures : new Dictionary<(uint Guid, int BitmapId), (int Texture, int Width, int Height)>();
        var spriteDepthTextures = animating ? kept.SpriteDepthTextures : new Dictionary<(uint Guid, int SpriteId, int Frame), int>();

        int? FloorShadowTexture(int shadowId, int attenuation, int zoom)
        {
            // floors.iff stores pre-authored shadow SPR2s at 0x300..0x350 for IDs 0/16; other IDs modulate base diamond (z-1)*0x100.
            if (floorArtwork is null || shadowId is < 0 or > 255 || attenuation >= 0xf8 || zoom is < 1 or > 3) return null;
            var key = (shadowId, attenuation, zoom);
            if (floorShadowTextures.TryGetValue(key, out var cached)) return cached;
            if (floorShadowBytesCache.Count > 256) floorShadowBytesCache.Clear();
            var cachedPixels = floorShadowBytesCache.GetOrAdd((floorArtwork, shadowId, attenuation, zoom), static k =>
            {
                var (artwork, sId, atten, z) = k;
                var spriteId = sId is 0 or 16
                    ? (ushort)(0x300 + (z - 1) * 0x20 + (sId == 16 ? 0x10 : 0))
                    : (ushort)((z - 1) * 0x100);
                var chunk = artwork.Find(ResourceType.Spr2, spriteId);
                if (chunk is null) return default;
                var art = CachedDepthSprite(artwork, chunk);
                if (art.Frames.Count == 0) return default;
                var frame = art.Frames[0];
                var generated = sId is not (0 or 16);
                var lookupTypes = generated ? ShadowLookupValues(sId) : [];
                if (generated && lookupTypes.Any(type => type is 2 or 4 or 6)) return default;
                var buffer = new byte[frame.Width * frame.Height * 4];
                var generatedWidth = frame.Width + (frame.Width & 1);
                var scale = generatedWidth > 0 ? 2f / generatedWidth : 0f;
                var anyVisible = false;
                for (var pixel = 0; pixel < frame.Width * frame.Height; pixel++)
                {
                    if (frame.Alpha[pixel] == 0) continue;
                    int shadeByte;
                    if (generated)
                    {
                        var row = pixel / frame.Width;
                        var column = pixel - row * frame.Width;
                        var halfX = (column - generatedWidth * 0.5f) * 0.5f;
                        var halfY = row - frame.Height * 0.5f;
                        var u = Math.Clamp(0.5f + scale * (halfY + halfX), 0f, 1f);
                        var v = Math.Clamp(0.5f + scale * (halfY - halfX), 0f, 1f);
                        var shade = EvaluateFloorShadowShade(lookupTypes, u, v);
                        shadeByte = Math.Clamp((int)(Math.Clamp(1f - shade, 0f, 1f) * 255f + 0.5f), 0, 255);
                    }
                    else
                    {
                        shadeByte = frame.Indices[pixel];
                    }
                    var adjusted = shadeByte + atten;
                    if (adjusted >= 0xf8) continue;
                    var opacity = (byte)(Math.Clamp(255 - adjusted, 0, 255) * frame.Alpha[pixel] / 31);
                    if (opacity == 0) continue;
                    buffer[pixel * 4 + 3] = opacity;
                    anyVisible = true;
                }
                return anyVisible ? (frame.Width, frame.Height, buffer) : default;
            });
            if (cachedPixels.Bytes is not { } bytes)
            {
                floorShadowTextures[key] = null;
                return null;
            }
            var attenuationTag = attenuation < 0 ? $"m{-attenuation}" : $"{attenuation}";
            var name = $"floor-shadow-{shadowId}-{attenuationTag}-{zoom}.rgba";
            files[name] = bytes;
            var texture = textures.Count;
            textures.Add(new Texture(name, cachedPixels.Width, cachedPixels.Height, "rgba"));
            floorShadowTextures[key] = texture;
            return texture;
        }
        ZoomImage? FloorShadowAt(int? shadowId, int shadowBrightness, int roomLightByte, int zoom, float x, float y, float altitude = 0)
        {
            if (shadowId is null or < 0 or > 255) return null;
            var attenuation = Math.Clamp(shadowBrightness - roomLightByte + 0xff, -255, 0xf8);
            var textureIndex = FloorShadowTexture(shadowId.Value, attenuation, zoom);
            if (textureIndex is null) return null;
            var point = camera.Project(x, y, altitude * 40f);
            var dimensions = textures[textureIndex.Value];
            var factor = zoom switch { 1 => 0.5f, 3 => 2f, _ => 1f };
            var shadowWidth = dimensions.Width / factor;
            var shadowHeight = dimensions.Height / factor;
            return new ZoomImage(textureIndex.Value, point.X - shadowWidth / 2, point.Y - shadowHeight / 2,
                shadowWidth, shadowHeight);
        }
        var viewWallsForMask = animating ? kept.ViewLevelWalls : ReadWalls(lot, viewLevel);
        var cutawayMask = animating &&
            kept.ViewLevel == viewLevel &&
            kept.WallMode == wallMode &&
            kept.CameraOrientation == cameraOrientation &&
            kept.CutawayTile == cutawayTile &&
            kept.CutawaySim == cutawaySim &&
            kept.CutawayZoom == cutawayZoom &&
            kept.CutawayRaiseHoveredWalls == raiseHoveredWalls &&
            CutawayRoomsSequenceEqual(kept.CutawayRooms, cutawayRooms)
            ? kept.CutawayMask
            : ComputeCutawayMask(rooms, camera, lotSize, wallMode, cutawayTile, cutawayRooms, cutawaySim, cutawayZoom, heights, baseHeight, raiseHoveredWalls, viewWallsForMask);

        bool IsCutawayPair(int x1, int y1, int x2, int y2) =>
            cutawayMask is not null &&
            x1 >= 0 && y1 >= 0 && x1 < lotSize && y1 < lotSize &&
            x2 >= 0 && y2 >= 0 && x2 < lotSize && y2 < lotSize &&
            cutawayMask[y1 * lotSize + x1] && cutawayMask[y2 * lotSize + x2];

        bool IsWallObjectLowered(int level, int tileX, int tileY, int flags1, int flags2, int wallPlacement, int direction,
            bool unresetPortalFallback = false)
        {
            if (roofsVisible || level != viewLevel || showLoweredPortals) return false;
            // Flags bit 0x400 marks cutaway-hidden wall objects (paintings/lamps/phones omit it to stay visible).
            var hideForCutaway = (flags1 & 0x400) != 0 || (unresetPortalFallback && (flags2 & 0xc000) != 0);
            if (!hideForCutaway) return false;
            if (wallMode == "down") return true;
            if (wallMode != "cutaway" || cutawayMask is null) return false;
            if (tileX < 0 || tileY < 0 || tileX >= lotSize || tileY >= lotSize) return false;
            if (!cutawayMask[tileY * lotSize + tileX]) return false;
            var maskedPlacement = wallPlacement & 5;
            if (maskedPlacement is not (1 or 4)) return true;
            var dir = (direction & 7) >> 1;
            var side = (dir + (maskedPlacement == 1 ? 0 : 2)) & 3;
            var (nx, ny) = side switch
            {
                0 => (tileX, tileY - 1),
                1 => (tileX + 1, tileY),
                2 => (tileX, tileY + 1),
                _ => (tileX - 1, tileY)
            };
            return IsCutawayPair(tileX, tileY, nx, ny);
        }

        var hasLiveObjects = false;
        foreach (var walkItem in world.WalkOrder)
        {
            if (walkItem is not XPerson) { hasLiveObjects = true; break; }
        }
        var wallObjectIds = animating ? kept.WallObjectIds : new HashSet<short>();
        var savedDoors = animating ? kept.SavedDoors : Array.Empty<SavedDoor>();
        var wallAdjacentTiles = animating ? kept.WallAdjacentTiles : new bool[lotSize * lotSize];
        var viewLevelWalls = animating ? kept.ViewLevelWalls : viewWallsForMask;
        var cutawayWallPairs = animating ? kept.CutawayWallPairs : new List<(int X1, int Y1, int X2, int Y2)>();
        var cutawayDiagonalTiles = animating ? kept.CutawayDiagonalTiles : new List<(int X, int Y)>();
        var objectStyles = animating ? kept.ObjectStyles : new Dictionary<(int Level, int X, int Y, int Side), WallStyleArt>();
        var wallObjectKinds = animating ? kept.WallObjectKinds : new Dictionary<(int Level, int X, int Y, int Side), int>();

        void MarkCutawaySensitiveNeighborhood(int centerX, int centerY)
        {
            if (wallAdjacentTiles is null) return;
            for (var dy = -1; dy <= 1; dy++)
            for (var dx = -1; dx <= 1; dx++)
            {
                var nx = centerX + dx;
                var ny = centerY + dy;
                if ((uint)nx < (uint)lotSize && (uint)ny < (uint)lotSize)
                    wallAdjacentTiles[ny * lotSize + nx] = true;
            }
        }

        if (!animating)
        {
        var grass = ReadGrass(lot);
        var wallArtwork = TryOpenOptionalArtwork(Path.Combine(gameRoot, "GameData", "walls.iff"));
        var gameDataPath = Path.Combine(gameRoot, "GameData");
        var dynamicFloorFiles = DynamicFloorFiles(gameDataPath);
        var dynamicWallFiles = DynamicWallFiles(gameDataPath);
        var lotFloorMap = ReadLotMaterialMap(lot, FlrmType);
        var lotWallMap = ReadLotMaterialMap(lot, WalmType);
        var floorTextures = new Dictionary<(ushort Pattern, int Zoom), int>();
        var waterTextures = new Dictionary<(ushort Sprite, int CornerMask, int Zoom), int>();
        var wallSprites = new Dictionary<ushort, Sprite>();
        var wallPalettes = new Dictionary<(IffFile File, int Id), PaletteColor[]>();
        var wallTextures = new Dictionary<(ushort Pattern, IffFile? File, ushort SpriteBase, ushort BaseStyle, int Frame, bool Down, int Zoom), int>();
        var wallJunctionTextures = new Dictionary<(int Zoom, int Frame, bool LoweredSheet), int>();
        var wallJunctionDepthTextures = new Dictionary<(int Zoom, int Frame, bool LoweredSheet), int>();
        var wallDepthTextures = new Dictionary<(int Configuration, int Width, int Height), int>();
        var wallStripTextures = new Dictionary<(int Texture, int Width, bool Right), int>();
        var wallSplitTextures = new Dictionary<(int Left, int Right), int>();

        int WallStrip(int texture, int width, bool right)
        {
            var key = (texture, width, right);
            if (wallStripTextures.TryGetValue(key, out var cached)) return cached;
            var source = textures[texture];
            width = Math.Min(width, source.Width);
            var channels = source.Encoding == "depth8" ? 1 : 4;
            var bytes = new byte[width * source.Height * channels];
            var sourceBytes = files[source.File];
            var sourceX = right ? source.Width - width : 0;
            for (var row = 0; row < source.Height; row++)
                Array.Copy(sourceBytes, (row * source.Width + sourceX) * channels, bytes,
                    row * width * channels, width * channels);
            var name = $"cap-{Path.GetFileNameWithoutExtension(source.File)}-{(right ? "right" : "left")}-{width}.{source.Encoding}";
            files[name] = bytes;
            var result = textures.Count;
            textures.Add(new Texture(name, width, source.Height, source.Encoding));
            wallStripTextures[key] = result;
            return result;
        }

        int ArchitectureDepth(int configuration, int colorTexture)
        {
            var dimensions = textures[colorTexture];
            return ResolveArchitectureDepthTexture(configuration, dimensions.Width, dimensions.Height,
                textures, files, wallDepthTextures);
        }
        PaletteColor[] Colors(IffFile sourceFile, Sprite sprite)
        {
            var paletteId = WallPaletteId(sprite.PaletteId);
            if (wallPalettes.TryGetValue((sourceFile, paletteId), out var colors)) return colors;
            var palette = sourceFile.Find(ResourceType.Palt, (ushort)paletteId)
                ?? sourceFile.OfType(ResourceType.Palt).FirstOrDefault();
            if (palette is null) return wallPalettes[(sourceFile, paletteId)] = [];
            return wallPalettes[(sourceFile, paletteId)] = Palette.Read(sourceFile, palette).Colors.ToArray();
        }
        int JunctionTexture(int zoom, int frame, bool loweredSheet = false)
        {
            if (wallArtwork is null) { missingResources.Add("GameData/walls.iff"); return -1; }
            var key = (zoom, frame, loweredSheet);
            if (wallJunctionTextures.TryGetValue(key, out var cached)) return cached;
            var upperId = (ushort)(zoom switch { 0 => 4096, 2 => 4098, _ => 4097 });
            var loweredId = (ushort)(zoom switch { 0 => 5120, 2 => 5122, _ => 5121 });
            var chunk = loweredSheet ? wallArtwork.Find(ResourceType.Spr1, loweredId) : null;
            var artworkId = chunk is not null ? loweredId : upperId;
            chunk ??= wallArtwork.Find(ResourceType.Spr1, upperId);
            if (chunk is null) { missingResources.Add($"wall-junction:{artworkId}"); return -1; }
            if (!wallSprites.TryGetValue(chunk.Id, out var sprite))
                wallSprites[chunk.Id] = sprite = Sprite.Read(wallArtwork, chunk);
            if (frame < 0 || frame >= sprite.Frames.Count)
            {
                missingResources.Add($"wall-junction:{artworkId}:frame:{frame}");
                return -1;
            }
            var art = sprite.Frames[frame];
            var colors = Colors(wallArtwork, sprite);
            if (colors.Length == 0) { missingResources.Add($"wall-junction-palette:{artworkId}"); return -1; }
            var bytes = new byte[art.Width * art.Height * 4];
            for (var pixel = 0; pixel < art.Indices.Length; pixel++)
            {
                if (!art.Opaque[pixel]) continue;
                var color = colors[art.Indices[pixel]];
                var at = pixel * 4;
                bytes[at] = color.Red;
                bytes[at + 1] = color.Green;
                bytes[at + 2] = color.Blue;
                bytes[at + 3] = 255;
            }
            var name = $"wall-junction-{(loweredSheet ? "down-" : "")}{zoom}-{frame}.rgba";
            files[name] = bytes;
            var result = textures.Count;
            textures.Add(new Texture(name, art.Width, art.Height, "rgba"));
            wallJunctionTextures[key] = result;
            return result;
        }
        int LoweredJunctionDepth(int zoom, int frame, bool loweredSheet, int fallbackConfiguration, int colorTexture)
        {
            if (wallArtwork is null) return ArchitectureDepth(fallbackConfiguration, colorTexture);
            var key = (zoom, frame, loweredSheet);
            if (wallJunctionDepthTextures.TryGetValue(key, out var cached)) return cached;
            var maskId = (ushort)(zoom switch { 0 => 6144, 2 => 6146, _ => 6145 });
            var maskChunk = wallArtwork.Find(ResourceType.Spr1, maskId);
            if (maskChunk is null) return ArchitectureDepth(fallbackConfiguration, colorTexture);
            if (!wallSprites.TryGetValue(maskChunk.Id, out var maskSprite))
                wallSprites[maskChunk.Id] = maskSprite = Sprite.Read(wallArtwork, maskChunk);
            if (frame < 0 || frame >= maskSprite.Frames.Count)
                return ArchitectureDepth(fallbackConfiguration, colorTexture);
            var upperId = (ushort)(zoom switch { 0 => 4096, 2 => 4098, _ => 4097 });
            var loweredId = (ushort)(zoom switch { 0 => 5120, 2 => 5122, _ => 5121 });
            var artChunk = (loweredSheet ? wallArtwork.Find(ResourceType.Spr1, loweredId) : null)
                ?? wallArtwork.Find(ResourceType.Spr1, upperId);
            if (artChunk is null) return ArchitectureDepth(fallbackConfiguration, colorTexture);
            if (!wallSprites.TryGetValue(artChunk.Id, out var artSprite))
                wallSprites[artChunk.Id] = artSprite = Sprite.Read(wallArtwork, artChunk);
            var colorDimensions = textures[colorTexture];
            var maskFrame = maskSprite.Frames[frame];
            if (frame >= artSprite.Frames.Count ||
                maskFrame.Width != colorDimensions.Width ||
                maskFrame.Height != colorDimensions.Height)
            {
                return ArchitectureDepth(fallbackConfiguration, colorTexture);
            }
            var depths = ResolveLoweredJunctionDepthBytes(wallArtwork, zoom, frame, loweredSheet,
                artSprite.Frames[frame], maskFrame);
            var name = $"wall-junction-depth-{(loweredSheet ? "down-" : "")}{zoom}-{frame}.depth8";
            files[name] = depths;
            var result = textures.Count;
            textures.Add(new Texture(name, colorDimensions.Width, colorDimensions.Height, "depth8"));
            wallJunctionDepthTextures[key] = result;
            return result;
        }
        var terrainType = TerrainType(house);
        const float sunLatitude = 0.31415927f;
        var sunLongitude = (camera.Orientation & 3) switch
        {
            0 => MathF.PI * 0.25f,
            2 => MathF.PI * 0.75f,
            _ => MathF.PI * 1.25f,
        };
        var sunZ = MathF.Cos(sunLatitude);
        var sunX = MathF.Sin(sunLongitude) * MathF.Sin(sunLatitude);
        var sunY = -MathF.Cos(sunLongitude) * MathF.Sin(sunLatitude);
        float SlopeDotSq(int dx, int dy)
        {
            dx = Math.Clamp(dx, -5, 5);
            dy = Math.Clamp(dy, -5, 5);
            var dot = (2.82842712f * sunZ + dx * sunX + dy * sunY) / MathF.Sqrt(8f + dx * dx + dy * dy);
            return dot * dot;
        }
        int RawHeightStep(int tx, int ty) => (int)MathF.Round(HeightAt(tx, ty) / 10f);
        float TileTri0(int tx, int ty)
        {
            var h00 = RawHeightStep(tx, ty);
            var h01 = RawHeightStep(tx, ty + 1);
            var h10 = RawHeightStep(tx + 1, ty);
            return SlopeDotSq(h00 - h10, h01 - h00);
        }
        float TileTri1(int tx, int ty)
        {
            var h01 = RawHeightStep(tx, ty + 1);
            var h11 = RawHeightStep(tx + 1, ty + 1);
            var h10 = RawHeightStep(tx + 1, ty);
            return SlopeDotSq(h01 - h11, h10 - h11);
        }
        int GrassCell(int tx, int ty) =>
            grass[Math.Clamp(tx, 1, lotSize - 1) * Size + Math.Clamp(ty, 1, lotSize - 1)];
        var terrainPoint = new Func<float, float, TerrainVertex>((x, y) =>
        {
            var cellX = Math.Clamp((int)x, 1, lotSize - 1);
            var cellY = Math.Clamp((int)y, 1, lotSize - 1);
            // Cloud lots (terrainType 7) force the outer 2-tile border to sky blue.
            var grassState = terrainType == 7 && (x <= 2 || y <= 2 || x >= lotSize - 2 || y >= lotSize - 2)
                ? (byte)255
                : (byte)((GrassCell(cellX, cellY) + GrassCell(cellX - 1, cellY)
                    + GrassCell(cellX - 1, cellY - 1) + GrassCell(cellX, cellY - 1)) / 4);
            var blend = grassState / 255f;
            var light = TerrainColors.LightGreen[terrainType];
            var lightBrown = TerrainColors.LightBrown[terrainType];
            var lightColor = TerrainColor.Lerp(light, lightBrown, blend);
            var darkGreen = TerrainColors.DarkGreen[terrainType];
            var darkBrown = TerrainColors.DarkBrown[terrainType];
            var darkColor = TerrainColor.Lerp(darkGreen, darkBrown, blend);
            var avgDotSq = (TileTri0(cellX - 1, cellY - 1) + TileTri1(cellX - 1, cellY - 1)
                + TileTri0(cellX, cellY - 1) + TileTri1(cellX - 1, cellY)
                + TileTri0(cellX, cellY) + TileTri1(cellX, cellY)) / 6f;
            var hash = unchecked((uint)(cellX * 0x40de9 + cellY * 0x10dcd) ^ 0x40de9u);
            hash ^= hash >> 16;
            hash *= 0x7feb352du;
            hash ^= hash >> 15;
            var jitter = (int)Math.Min(hash % 3u, (hash >> 8) % 3u);
            if ((hash & 0x10000u) != 0) jitter = -jitter;
            var vertexShade = Math.Clamp((int)((1f - avgDotSq) * 127f) + jitter, 0, 127);
            lightColor = TerrainColor.Lerp(lightColor, darkColor, vertexShade / 128f);
            var point = camera.Project(x, y, Elevation(x, y));
            return new TerrainVertex(point.X, point.Y, lightColor.R, lightColor.G, lightColor.B,
                darkColor.R, darkColor.G, darkColor.B, grassState);
        });
        Lap("terrain");
        for (var y = 0; y < lotSize; y++)
        for (var x = 0; x < lotSize; x++)
        {
            var top = terrainPoint(x, y);
            var right = terrainPoint(x + 1, y);
            var bottom = terrainPoint(x + 1, y + 1);
            var left = terrainPoint(x, y + 1);
            terrain.AddRange([top, right, bottom, bottom, left, top]);
        }

        // Keep lower-story floors visible through upper-story cutouts and for object depth.
        Lap("preFloors");
        for (var floorLevel = 1; floorLevel <= viewLevel; floorLevel++)
        {
            var floors = ReadFloors(lot, floorLevel);
            var floorWalls = ReadWalls(lot, floorLevel);
            var floorRooms = world.LotRoomMaps.TryGetValue(floorLevel, out var floorRoomMap) ? floorRoomMap : null;
            var levelOffset = (floorLevel - 1) * EntityTransform.StoryHeight * 40;
            Vertex Corner(float cornerX, float cornerY, float u, float v, ushort pattern)
            {
                var elevation = Elevation(cornerX, cornerY) + levelOffset;
                var point = camera.Project(cornerX, cornerY, elevation);
                var depth = floorLevel == 1 && pattern < 65534 ? 1 : camera.Depth(cornerX, cornerY, elevation / 40);
                var rotatedUv = camera.TexturePoint(u, v);
                if (pattern is >= 9 and <= 11)
                    rotatedUv = camera.Orientation % 2 == 0 ? new(u, v) : new(1 - v, 1 - u);
                else if (pattern >= 65534)
                    rotatedUv = camera.Orientation switch
                    {
                        0 => new(u, v),
                        1 => new(1 - v, u),
                        2 => new(1 - u, 1 - v),
                        _ => new(v, 1 - u)
                    };
                return new Vertex(point.X, point.Y, depth, rotatedUv.X, rotatedUv.Y, 0, 1, 0);
            }
            void EmitFloor(int tileX, int tileY, ushort pattern, int half, (int Dx, int Dy, float U, float V)[] corners, int? room)
            {
                if (!HasFloorArtwork(pattern)) return;
                int texture;
                int nearTexture;
                int farTexture;
                WaterSurface? water = null;
                if (pattern is 65534 or 65535)
                {
                    ReadOnlySpan<(int Dx, int Dy)> neighbourOffsets =
                        [(0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1)];
                    var adjacency = 0;
                    for (var i = 0; i < neighbourOffsets.Length; i++)
                    {
                        var offset = camera.SourceVector(neighbourOffsets[i].Dx, neighbourOffsets[i].Dy);
                        var nx = tileX + (int)MathF.Round(offset.X);
                        var ny = tileY + (int)MathF.Round(offset.Y);
                        if (nx >= 0 && nx < Size && ny >= 0 && ny < Size && floors[nx * Size + ny] == pattern)
                            adjacency |= 1 << i;
                    }
                    var variant = ((adjacency & 1) != 0 ? 1 : 0) |
                                  ((adjacency & 64) != 0 ? 2 : 0) |
                                  ((adjacency & 16) != 0 ? 4 : 0) |
                                  ((adjacency & 4) != 0 ? 8 : 0);
                    var sprite = (ushort)((pattern == 65535 ? 0x410 : 0x800) + variant);
                    ushort[] cornerSprites = [];
                    var cornerMask = 0;
                    if (pattern == 65535)
                    {
                        ReadOnlySpan<int> pairs = [65, 80, 20, 5];
                        ReadOnlySpan<int> diagonals = [128, 32, 8, 2];
                        var list = new List<ushort>(4);
                        for (var i = 0; i < 4; i++)
                        {
                            if ((adjacency & pairs[i]) == pairs[i] && (adjacency & diagonals[i]) == 0)
                            {
                                list.Add((ushort)(0x434 + i));
                                cornerMask |= 1 << i;
                            }
                        }
                        cornerSprites = [.. list];
                    }
                    water = new WaterSurface(adjacency, sprite, cornerSprites);
                    texture = WaterTexture(pattern, variant, cornerMask, 1);
                    if (texture < 0) return;
                    nearTexture = WaterTexture(pattern, variant, cornerMask, 2);
                    farTexture = WaterTexture(pattern, variant, cornerMask, 0);
                }
                else
                {
                    texture = FloorTexture(pattern, 1);
                    if (texture < 0) return;
                    nearTexture = FloorTexture(pattern, 2);
                    farTexture = FloorTexture(pattern, 0);
                }
                var vertices = corners.Select(c => Corner(tileX + c.Dx, tileY + c.Dy, c.U, c.V, pattern)).ToArray();
                var depth = camera.DepthOrder(tileX + 0.5f, tileY + 0.5f);
                meshes.Add(new Mesh(texture, 0, depth, vertices, floorLevel, room, Unlit: true,
                    Floor: new FloorSurface(tileX, tileY, pattern, half, floorLevel, water),
                    NearTexture: nearTexture >= 0 ? nearTexture : null,
                    FarTexture: farTexture >= 0 ? farTexture : null,
                    Layer: 0));
                foreach (var vertex in vertices) meshVertices.Add((vertex, tileX, tileY));
            }
            for (var y = 0; y < lotSize; y++)
            for (var x = 0; x < lotSize; x++)
            {
                var c0 = (Dx: 0, Dy: 0, U: 0.5f, V: 0f);
                var c1 = (Dx: 1, Dy: 0, U: 1f, V: 0.5f);
                var c2 = (Dx: 1, Dy: 1, U: 0.5f, V: 1f);
                var c3 = (Dx: 0, Dy: 1, U: 0f, V: 0.5f);
                var wallDiag = floorWalls is not null && x < floorWalls.Rows && y < floorWalls.Width
                    ? floorWalls.Element(x, y)[0] & 0x30
                    : 0;
                if (wallDiag == 0x20)
                {
                    var wallTile = floorWalls!.Element(x, y);
                    var basePattern = floors[x * Size + y] == byte.MaxValue ? (ushort)0 : floors[x * Size + y];
                    var diagA = WallStyle0(wallTile);
                    var diagB = WallPattern(wallTile, 4);
                    var pat1 = diagA == 0 && diagB == 0 ? basePattern : diagB;
                    var pat2 = diagA == 0 && diagB == 0 ? basePattern : diagA;
                    EmitFloor(x, y, pat1, 1, [c0, c1, c2], floorRooms?.RoomAtPosition(x * 16 + 12, y * 16 + 4));
                    EmitFloor(x, y, pat2, 2, [c2, c3, c0], floorRooms?.RoomAtPosition(x * 16 + 4, y * 16 + 12));
                }
                else if (wallDiag == 0x10)
                {
                    var wallTile = floorWalls!.Element(x, y);
                    var basePattern = floors[x * Size + y] == byte.MaxValue ? (ushort)0 : floors[x * Size + y];
                    var diagA = WallStyle0(wallTile);
                    var diagB = WallPattern(wallTile, 4);
                    var pat3 = diagA == 0 && diagB == 0 ? basePattern : diagA;
                    var pat4 = diagA == 0 && diagB == 0 ? basePattern : diagB;
                    EmitFloor(x, y, pat3, 3, [c0, c1, c3], floorRooms?.RoomAtPosition(x * 16 + 4, y * 16 + 4));
                    EmitFloor(x, y, pat4, 4, [c1, c2, c3], floorRooms?.RoomAtPosition(x * 16 + 12, y * 16 + 12));
                }
                else
                {
                    var pattern = floors[x * Size + y];
                    EmitFloor(x, y, pattern, 0, [c0, c1, c2, c2, c3, c0], floorRooms?.RoomAt(x, y));
                }
            }
        }

        int FloorTexture(ushort pattern, int zoom = 1)
        {
            var key = (pattern, zoom);
            if (floorTextures.TryGetValue(key, out var cached)) return cached;
            var art = floorArtwork;
            var spriteId = unchecked((ushort)(pattern + zoom * 256));
            if (pattern >= 256)
            {
                IffFile? dynamicFloorArt = null;
                if (lotFloorMap.TryGetValue(pattern, out var lotFloorFile) &&
                    FloorCatalog.TryOpenFloorIffByName(gameRoot, lotFloorFile, out var mappedFloor))
                {
                    dynamicFloorArt = mappedFloor;
                }
                else if (dynamicFloorFiles.TryGetValue(pattern, out var path))
                {
                    dynamicFloorArt = OpenArtwork(path);
                }

                if (dynamicFloorArt is null)
                {
                    if (zoom == 1) missingResources.Add($"floor:{pattern}:resource");
                    return -1;
                }
                art = dynamicFloorArt;
                spriteId = (ushort)(1 + zoom * 256);
            }
            if (art is null) { if (zoom == 1) missingResources.Add("GameData/floors.iff"); return -1; }
            var chunk = art.Find(ResourceType.Spr2, spriteId);
            if (chunk is null)
            {
                if (zoom == 1) missingResources.Add($"floor:{pattern}");
                return -1;
            }
            var sprite = DepthSprite.Read(art, chunk);
            if (sprite.Frames.Count == 0)
            {
                if (zoom == 1) missingResources.Add($"floor:{pattern}:frame:0");
                return -1;
            }
            var frame = sprite.Frames[0];
            if (frame.Width <= 0 || frame.Height <= 0 || frame.Indices.Length != frame.Width * frame.Height ||
                frame.Alpha.Length != frame.Indices.Length)
            {
                if (zoom == 1) missingResources.Add($"floor:{pattern}:frame:0");
                return -1;
            }
            var paletteId = sprite.PaletteId;
            var colors = PaletteFor(art, paletteId);
            if (colors is null)
            {
                if (zoom == 1) missingResources.Add($"floor-palette:{pattern}");
                return -1;
            }
            var bytes = new byte[frame.Width * frame.Height * 4];
            for (var pixel = 0; pixel < frame.Indices.Length; pixel++)
            {
                if (frame.Alpha[pixel] == 0) continue;
                if (frame.Indices[pixel] >= colors.Length)
                {
                    if (zoom == 1) missingResources.Add($"floor-palette:{pattern}");
                    return -1;
                }
                var color = colors[frame.Indices[pixel]];
                var at = pixel * 4;
                bytes[at] = color.Red;
                bytes[at + 1] = color.Green;
                bytes[at + 2] = color.Blue;
                bytes[at + 3] = (byte)Math.Clamp((frame.Alpha[pixel] * 255 + 15) / 31, 0, 255);
                // Sims.exe tints bright white line pixels yellow on road floor patterns 10 and 11.
                if (pattern is 10 or 11 && Math.Min(color.Red, Math.Min(color.Green, color.Blue)) > 64)
                {
                    bytes[at + 1] = (byte)(color.Green * 0.8f);
                    bytes[at + 2] = (byte)(color.Blue * 0.12f);
                }
            }
            // Bleed edge texels into transparent diamond border pixels to prevent bilinear seams.
            var firstOpaqueRow = -1;
            var lastOpaqueRow = -1;
            for (var py = 0; py < frame.Height; py++)
            {
                var rowStart = py * frame.Width;
                var firstX = -1;
                var lastX = -1;
                for (var px = 0; px < frame.Width; px++)
                {
                    if (bytes[(rowStart + px) * 4 + 3] == 0) continue;
                    if (firstX < 0) firstX = px;
                    lastX = px;
                }
                if (firstX < 0) continue;
                if (firstOpaqueRow < 0) firstOpaqueRow = py;
                lastOpaqueRow = py;
                var leftAt = (rowStart + firstX) * 4;
                for (var px = 0; px < firstX; px++)
                {
                    var dst = (rowStart + px) * 4;
                    bytes[dst] = bytes[leftAt];
                    bytes[dst + 1] = bytes[leftAt + 1];
                    bytes[dst + 2] = bytes[leftAt + 2];
                    bytes[dst + 3] = 255;
                }
                var rightAt = (rowStart + lastX) * 4;
                for (var px = lastX + 1; px < frame.Width; px++)
                {
                    var dst = (rowStart + px) * 4;
                    bytes[dst] = bytes[rightAt];
                    bytes[dst + 1] = bytes[rightAt + 1];
                    bytes[dst + 2] = bytes[rightAt + 2];
                    bytes[dst + 3] = 255;
                }
            }
            if (firstOpaqueRow > 0)
            {
                for (var py = 0; py < firstOpaqueRow; py++)
                    Array.Copy(bytes, firstOpaqueRow * frame.Width * 4, bytes, py * frame.Width * 4, frame.Width * 4);
            }
            if (lastOpaqueRow >= 0 && lastOpaqueRow < frame.Height - 1)
            {
                for (var py = lastOpaqueRow + 1; py < frame.Height; py++)
                    Array.Copy(bytes, lastOpaqueRow * frame.Width * 4, bytes, py * frame.Width * 4, frame.Width * 4);
            }
            var name = zoom == 1 ? $"floor-{pattern}.rgba" : $"floor-{pattern}-z{zoom}.rgba";
            files[name] = bytes;
            var result = textures.Count;
            textures.Add(new Texture(name, frame.Width, frame.Height, "rgba"));
            floorTextures.Add(key, result);
            return result;
        }

        int WaterTexture(ushort pattern, int variant, int cornerMask, int zoom = 1)
        {
            var mediumSprite = (ushort)((pattern == 65535 ? 0x410 : 0x800) + variant);
            var key = (mediumSprite, cornerMask, zoom);
            if (waterTextures.TryGetValue(key, out var cached)) return cached;
            var art = floorArtwork;
            if (art is null) { if (zoom == 1) missingResources.Add("GameData/floors.iff"); return -1; }
            var spriteId = pattern == 65535
                ? (ushort)(0x400 + zoom * 0x10 + variant)
                : (ushort)(0x800 + variant);
            var frameIndex = pattern == 65535 ? 0 : 2 - zoom;

            (int Width, int Height, int OffsetX, int OffsetY, byte[] Rgba)? ReadWaterSprite(ushort id, int frameIdx)
            {
                var spr2Chunk = art.Find(ResourceType.Spr2, id);
                if (spr2Chunk is not null)
                {
                    var spr2 = DepthSprite.Read(art, spr2Chunk);
                    if (frameIdx < 0 || frameIdx >= spr2.Frames.Count) return null;
                    var f = spr2.Frames[frameIdx];
                    if (f.Width <= 0 || f.Height <= 0 || f.Indices.Length != f.Width * f.Height || f.Alpha.Length != f.Indices.Length)
                        return null;
                    var colors = PaletteFor(art, spr2.PaletteId);
                    if (colors is null) return null;
                    var rgba = new byte[f.Width * f.Height * 4];
                    for (var p = 0; p < f.Indices.Length; p++)
                    {
                        if (f.Alpha[p] == 0 || f.Indices[p] == f.TransparentIndex || f.Indices[p] >= colors.Length) continue;
                        var c = colors[f.Indices[p]];
                        var at = p * 4;
                        rgba[at] = c.Red;
                        rgba[at + 1] = c.Green;
                        rgba[at + 2] = c.Blue;
                        rgba[at + 3] = (byte)Math.Clamp((f.Alpha[p] * 255 + 15) / 31, 0, 255);
                    }
                    return (f.Width, f.Height, f.X, f.Y, rgba);
                }
                var spr1Chunk = art.Find(ResourceType.Spr1, id);
                if (spr1Chunk is not null)
                {
                    var spr1 = Sprite.Read(art, spr1Chunk);
                    if (frameIdx < 0 || frameIdx >= spr1.Frames.Count) return null;
                    var f = spr1.Frames[frameIdx];
                    if (f.Width <= 0 || f.Height <= 0 || f.Indices.Length != f.Width * f.Height || f.Opaque.Length != f.Indices.Length)
                        return null;
                    var colors = PaletteFor(art, spr1.PaletteId);
                    if (colors is null) return null;
                    var rgba = new byte[f.Width * f.Height * 4];
                    for (var p = 0; p < f.Indices.Length; p++)
                    {
                        if (!f.Opaque[p] || f.Indices[p] >= colors.Length) continue;
                        var c = colors[f.Indices[p]];
                        var at = p * 4;
                        rgba[at] = c.Red;
                        rgba[at + 1] = c.Green;
                        rgba[at + 2] = c.Blue;
                        rgba[at + 3] = 255;
                    }
                    return (f.Width, f.Height, f.BoundsLeft, f.BoundsTop, rgba);
                }
                return null;
            }

            var baseArt = ReadWaterSprite(spriteId, frameIndex);
            if (baseArt is not { } loaded)
            {
                if (zoom == 1) missingResources.Add($"water:{spriteId}:frame:{frameIndex}");
                return -1;
            }
            var bytes = loaded.Rgba;
            if (pattern == 65535 && cornerMask != 0)
            {
                for (var cornerIndex = 0; cornerIndex < 4; cornerIndex++)
                {
                    if ((cornerMask & (1 << cornerIndex)) == 0) continue;
                    var cornerSpriteId = (ushort)(0x430 + zoom * 4 + cornerIndex);
                    if (ReadWaterSprite(cornerSpriteId, 0) is not { } cornerArt) continue;
                    var dx = cornerArt.OffsetX - loaded.OffsetX;
                    var dy = cornerArt.OffsetY - loaded.OffsetY;
                    for (var cy = 0; cy < cornerArt.Height; cy++)
                    for (var cx = 0; cx < cornerArt.Width; cx++)
                    {
                        var srcAt = (cy * cornerArt.Width + cx) * 4;
                        var alpha = cornerArt.Rgba[srcAt + 3];
                        if (alpha == 0) continue;
                        var bx = cx + dx;
                        var by = cy + dy;
                        if (bx < 0 || bx >= loaded.Width || by < 0 || by >= loaded.Height) continue;
                        var dstAt = (by * loaded.Width + bx) * 4;
                        bytes[dstAt] = (byte)((cornerArt.Rgba[srcAt] * alpha + bytes[dstAt] * (255 - alpha) + 127) / 255);
                        bytes[dstAt + 1] = (byte)((cornerArt.Rgba[srcAt + 1] * alpha + bytes[dstAt + 1] * (255 - alpha) + 127) / 255);
                        bytes[dstAt + 2] = (byte)((cornerArt.Rgba[srcAt + 2] * alpha + bytes[dstAt + 2] * (255 - alpha) + 127) / 255);
                        bytes[dstAt + 3] = (byte)Math.Max(bytes[dstAt + 3], alpha);
                    }
                }
            }
            bool IsOutsideDiamond(int px, int py)
            {
                var hw = loaded.Width * 0.5;
                var hh = loaded.Height * 0.5;
                return Math.Abs(px + 0.5 - hw) / hw + Math.Abs(py + 0.5 - hh) / hh > 1.0;
            }
            bool IsAtDiamondBoundary(int px, int py)
            {
                var hw = loaded.Width * 0.5;
                var hh = loaded.Height * 0.5;
                return Math.Abs(px + 0.5 - hw) / hw + Math.Abs(py + 0.5 - hh) / hh > 0.94;
            }
            var firstOpaqueRow = -1;
            var lastOpaqueRow = -1;
            for (var py = 0; py < loaded.Height; py++)
            {
                var rowStart = py * loaded.Width;
                var firstX = -1;
                var lastX = -1;
                for (var px = 0; px < loaded.Width; px++)
                {
                    if (bytes[(rowStart + px) * 4 + 3] == 0) continue;
                    if (firstX < 0) firstX = px;
                    lastX = px;
                }
                if (firstX < 0) continue;
                if (firstOpaqueRow < 0) firstOpaqueRow = py;
                lastOpaqueRow = py;
                if (IsAtDiamondBoundary(firstX - 1, py))
                {
                    var leftAt = (rowStart + firstX) * 4;
                    for (var px = 0; px < firstX; px++)
                    {
                        if (!IsOutsideDiamond(px, py)) continue;
                        var dst = (rowStart + px) * 4;
                        bytes[dst] = bytes[leftAt];
                        bytes[dst + 1] = bytes[leftAt + 1];
                        bytes[dst + 2] = bytes[leftAt + 2];
                        bytes[dst + 3] = 255;
                    }
                }
                if (IsAtDiamondBoundary(lastX + 1, py))
                {
                    var rightAt = (rowStart + lastX) * 4;
                    for (var px = lastX + 1; px < loaded.Width; px++)
                    {
                        if (!IsOutsideDiamond(px, py)) continue;
                        var dst = (rowStart + px) * 4;
                        bytes[dst] = bytes[rightAt];
                        bytes[dst + 1] = bytes[rightAt + 1];
                        bytes[dst + 2] = bytes[rightAt + 2];
                        bytes[dst + 3] = 255;
                    }
                }
            }
            if (firstOpaqueRow > 0)
            {
                for (var py = 0; py < firstOpaqueRow; py++)
                for (var px = 0; px < loaded.Width; px++)
                {
                    if (!IsOutsideDiamond(px, py)) continue;
                    var src = (firstOpaqueRow * loaded.Width + px) * 4;
                    if (bytes[src + 3] == 0) continue;
                    var dst = (py * loaded.Width + px) * 4;
                    bytes[dst] = bytes[src];
                    bytes[dst + 1] = bytes[src + 1];
                    bytes[dst + 2] = bytes[src + 2];
                    bytes[dst + 3] = bytes[src + 3];
                }
            }
            if (lastOpaqueRow >= 0 && lastOpaqueRow < loaded.Height - 1)
            {
                for (var py = lastOpaqueRow + 1; py < loaded.Height; py++)
                for (var px = 0; px < loaded.Width; px++)
                {
                    if (!IsOutsideDiamond(px, py)) continue;
                    var src = (lastOpaqueRow * loaded.Width + px) * 4;
                    if (bytes[src + 3] == 0) continue;
                    var dst = (py * loaded.Width + px) * 4;
                    bytes[dst] = bytes[src];
                    bytes[dst + 1] = bytes[src + 1];
                    bytes[dst + 2] = bytes[src + 2];
                    bytes[dst + 3] = bytes[src + 3];
                }
            }
            var suffix = cornerMask == 0 ? "" : $"-c{cornerMask:x}";
            var waterName = zoom == 1
                ? $"water-{mediumSprite:x4}{suffix}.rgba"
                : $"water-{mediumSprite:x4}{suffix}-z{zoom}.rgba";
            files[waterName] = bytes;
            var waterResult = textures.Count;
            textures.Add(new Texture(waterName, loaded.Width, loaded.Height, "rgba"));
            waterTextures.Add(key, waterResult);
            return waterResult;
        }

        var typeTable = ObjectTypeTable.Read(lot, lot.OfType(ResourceType.Parse("objt")).First());
        var savedDoorsList = new List<SavedDoor>();
        Lap("floors");
        if (!hasLiveObjects && world.SavedLotObjects is { } savedObjects)
        foreach (var saved in savedObjects.Objects)
        {
            if (saved.Decoded is not { } state) continue;
            var type = typeTable.Entries.FirstOrDefault(entry => entry.TypeIndex == saved.TypeIndex);
            if (type is null) continue;
            var entry = registry.Find(type.Guid);
            if (entry is null) continue;
            if (entry.Definition[ObjdField.Type] is not (8 or 9)) continue;
            if ((state.Value0x110 & 0xff) < 1 || (state.Value0x110 & 0xff) > viewLevel) continue;
            var tileX = state.Values0x108[4] / 16f;
            var tileY = state.Values0x108[5] / 16f;
            if (world.ObjectById(saved.ObjectId) is not null) continue;
            savedDoorsList.Add(new SavedDoor(entry, type.Guid, saved.ObjectId, tileX, tileY, state.Values0x108[4] >> 4, state.Values0x108[5] >> 4,
                state.Value0x110 & 0xff, state.Data[(int)ObjectData.Direction],
                unchecked((ushort)state.Data[(int)ObjectData.Flags]), unchecked((ushort)state.Data[(int)ObjectData.FlagField2]),
                state.Data[(int)ObjectData.WallPlacementFlags], state.Data[(int)ObjectData.Graphic], state.Values0x34));
        }
        savedDoors = savedDoorsList.Count == 0 ? Array.Empty<SavedDoor>() : savedDoorsList.ToArray();
        objectStyles = new Dictionary<(int Level, int X, int Y, int Side), WallStyleArt>();
        wallObjectKinds = new Dictionary<(int Level, int X, int Y, int Side), int>();
        void AddObjectStyle(int level, int tileX, int tileY, int flags2, int wallPlacement, int direction, int wallStyle, IffFile file, Objd definition)
        {
            if ((flags2 & 0xc000) == 0 || wallStyle == 0) return;
            var kind = (flags2 & 0x8000) != 0 ? 1 : (flags2 & 0x4000) != 0 ? 2 : 0;
            WallStyleArt art;
            if (wallStyle is > 21 and < 256)
            {
                // OBJD field 81 holds the base SPR# ID for custom door/window wall mask cutouts (up/down x 3 zooms).
                if (definition.Fields.Count <= 81) return;
                var spriteBase = definition.Fields[81];
                if (spriteBase == 0) return;
                art = new WallStyleArt(file, spriteBase, 0);
            }
            else art = WallStyleArt.Base((ushort)wallStyle);
            var dir = (direction & 7) >> 1;
            void Apply(int side)
            {
                switch (side & 3)
                {
                    case 0:
                        objectStyles[(level, tileX, tileY, 1)] = art;
                        if (kind != 0) wallObjectKinds[(level, tileX, tileY, 1)] = kind;
                        break;
                    case 1 when tileX + 1 < Size:
                        objectStyles.TryAdd((level, tileX + 1, tileY, 0), art);
                        if (kind != 0) wallObjectKinds.TryAdd((level, tileX + 1, tileY, 0), kind);
                        break;
                    case 2 when tileY + 1 < Size:
                        objectStyles.TryAdd((level, tileX, tileY + 1, 1), art);
                        if (kind != 0) wallObjectKinds.TryAdd((level, tileX, tileY + 1, 1), kind);
                        break;
                    case 3:
                        objectStyles[(level, tileX, tileY, 0)] = art;
                        if (kind != 0) wallObjectKinds[(level, tileX, tileY, 0)] = kind;
                        break;
                }
            }
            if ((wallPlacement & 1) != 0) Apply(dir);
            if ((wallPlacement & 2) != 0) Apply(dir + 1);
            if ((wallPlacement & 4) != 0) Apply(dir + 2);
            if ((wallPlacement & 8) != 0) Apply(dir + 3);
        }
        Lap("savedObjects");
        foreach (var item in world.WalkOrder)
        {
            if (item is XPerson || item.Position.Height < 1 || item.Position.Height > viewLevel) continue;
            var itemFlags1 = unchecked((ushort)item[ObjectData.Flags]);
            var itemFlags = unchecked((ushort)item[ObjectData.FlagField2]);
            var itemStyle = item.Definition[(int)ObjdField.WallStyle];
            var itemGuid = (uint)(item.TypeRecord?.Key ?? 0);
            var itemEntry = registry.Find(itemGuid);
            var itemTileX = item.Position.X >> 4;
            var itemTileY = item.Position.Y >> 4;
            var itemWallPlacement = item[ObjectData.WallPlacementFlags];
            var itemDirection = item[ObjectData.Direction];
            if (itemEntry is not null)
                AddObjectStyle(item.Position.Height, itemTileX, itemTileY, itemFlags,
                    itemWallPlacement, itemDirection, itemStyle,
                    itemEntry.File, itemEntry.Definition);
            if (IsWallObjectLowered(item.Position.Height, itemTileX, itemTileY, itemFlags1, itemFlags, itemWallPlacement, itemDirection,
                unresetPortalFallback: world.ChangedCodeTypeGuids.Contains(itemGuid)))
                wallObjectIds.Add(item.Id);
        }
        if (!hasLiveObjects && world.SavedLotObjects is { } doorStates)
            foreach (var saved in doorStates.Objects)
            {
                if (saved.Decoded is not { } state || (state.Value0x110 & 0xff) < 1 || (state.Value0x110 & 0xff) > viewLevel) continue;
                if (world.ObjectById(saved.ObjectId) is not null) continue;
                var type = typeTable.Entries.FirstOrDefault(candidate => candidate.TypeIndex == saved.TypeIndex);
                var entry = type is null ? null : registry.Find(type.Guid);
                if (entry is null) continue;
                var savedLevel = state.Value0x110 & 0xff;
                var savedTileX = state.Values0x108[4] >> 4;
                var savedTileY = state.Values0x108[5] >> 4;
                if (savedLevel == viewLevel &&
                    ((state.Data[(int)ObjectData.Flags] & 0x400) != 0 || (state.Data[(int)ObjectData.FlagField2] & 0xc000) != 0))
                {
                    MarkCutawaySensitiveNeighborhood(savedTileX, savedTileY);
                }
                AddObjectStyle(savedLevel, savedTileX, savedTileY, state.Data[(int)ObjectData.FlagField2],
                    state.Data[(int)ObjectData.WallPlacementFlags], state.Data[(int)ObjectData.Direction],
                    entry.Definition[ObjdField.WallStyle], entry.File, entry.Definition);
            }
        Lap("walkorder");
        for (var wallLevel = 1; wallLevel <= viewLevel; wallLevel++)
        {
        var walls = wallLevel == viewLevel ? viewLevelWalls : ReadWalls(lot, wallLevel);
        var wallRooms = world.LotRoomMaps.TryGetValue(wallLevel, out var wallRoomMap) ? wallRoomMap : null;
        var upJunctions = new int[Size * Size];
        var downJunctions = new int[Size * Size];
        var levelForcedDown = wallMode == "down" && wallLevel == viewLevel;
        var levelCutaway = wallMode == "cutaway" && wallLevel == viewLevel;
        bool IsDoorEdge(int ownerX, int ownerY, int side, ushort storedStyle) =>
            wallObjectKinds.GetValueOrDefault((wallLevel, ownerX, ownerY, side)) == 1 ||
            (!hasLiveObjects && storedStyle is 3 or 5 or 6 or 15 or 23);
        if (walls is not null)
        Lap("wallsLevel");
        for (var y = 0; y < lotSize; y++)
        for (var x = 0; x < lotSize; x++)
        {
            if (walls is null || x >= walls.Rows || y >= walls.Width) continue;
            var tile = walls.Element(x, y);
            var segments = tile[0];
            if (wallLevel == viewLevel && segments != 0)
                MarkCutawaySensitiveNeighborhood(x, y);
            if (segments == 0) continue;

            var style0 = WallStyle0(tile);
            var style1 = WallStyle1(tile);
            if ((segments & 1) != 0 && NormalizedWallStyle(style0) == 1)
            {
                if (wallLevel == viewLevel && x > 0)
                    cutawayWallPairs!.Add((x, y, x - 1, y));
                var segDown = levelForcedDown || (levelCutaway && IsCutawayPair(x, y, x - 1, y));
                if (!segDown || !IsDoorEdge(x, y, 0, style0))
                {
                    var targetJunctions = segDown ? downJunctions : upJunctions;
                    targetJunctions[y * Size + x] |= 4;
                    if (y + 1 < lotSize) targetJunctions[(y + 1) * Size + x] |= 1;
                }
            }
            if ((segments & 2) != 0 && NormalizedWallStyle(style1) == 1)
            {
                if (wallLevel == viewLevel && y > 0)
                    cutawayWallPairs!.Add((x, y, x, y - 1));
                var segDown = levelForcedDown || (levelCutaway && IsCutawayPair(x, y, x, y - 1));
                if (!segDown || !IsDoorEdge(x, y, 1, style1))
                {
                    var targetJunctions = segDown ? downJunctions : upJunctions;
                    targetJunctions[y * Size + x] |= 8;
                    if (x + 1 < lotSize) targetJunctions[y * Size + x + 1] |= 2;
                }
            }

            var diag = segments & 0x30;
            if (diag is 0x20 or 0x10 && style1 is not (2 or 12 or 13 or 14))
            {
                if (wallLevel == viewLevel)
                    cutawayDiagonalTiles!.Add((x, y));
                var diagDown = levelForcedDown || (levelCutaway && cutawayMask is not null && cutawayMask[y * lotSize + x]);
                if (!diagDown || !IsDoorEdge(x, y, 1, style1))
                {
                    var targetJunctions = diagDown ? downJunctions : upJunctions;
                    if (diag == 0x20)
                    {
                        targetJunctions[y * Size + x] |= 64;
                        if (x + 1 < lotSize && y + 1 < lotSize) targetJunctions[(y + 1) * Size + x + 1] |= 16;
                    }
                    else
                    {
                        if (x + 1 < lotSize) targetJunctions[y * Size + x + 1] |= 32;
                        if (y + 1 < lotSize) targetJunctions[(y + 1) * Size + x] |= 128;
                    }
                }
            }
        }
        if (walls is not null)
        Lap("wallTiles");
        for (var v = 0; v < lotSize; v++)
        for (var u = 0; u < lotSize; u++)
        {
            var (sourceX, sourceY) = camera.SourceTile(u, v);
            if (sourceX < 0 || sourceY < 0 || sourceX >= lotSize || sourceY >= lotSize) continue;
            bool Cutaway(int otherX, int otherY) =>
                wallLevel == viewLevel && cutawayMask is not null && otherX >= 0 && otherY >= 0 && otherX < lotSize && otherY < lotSize &&
                cutawayMask[sourceY * lotSize + sourceX] && cutawayMask[otherY * lotSize + otherX];
            var down = wallMode == "down" && wallLevel == viewLevel;
            bool IsWindowEdge(int ownerX, int ownerY, int side, ushort storedStyle) =>
                wallObjectKinds.GetValueOrDefault((wallLevel, ownerX, ownerY, side)) == 2 ||
                (!hasLiveObjects && storedStyle is 4 or 9 or 10 or 11 or (>= 16 and <= 22));
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
            void AddFace(int face, int neighbourX, int neighbourY)
            {
                // ARRY wall tiles store structural styles on the edge-owning tile, while each side's wallpaper lives on the facing tile.
                var (ownerX, ownerY, side) = EdgeOwner(sourceX, sourceY, neighbourX, neighbourY);
                if (ownerX < 0 || ownerY < 0 || ownerX >= lotSize || ownerY >= lotSize) return;
                var owner = walls!.Element(ownerX, ownerY);
                // ARRY wall cell bytes: [0]=segment flags, [2..3]=wall styles, [4..7]=wallpaper patterns per face.
                if ((owner[0] & (side == 0 ? 1 : 2)) == 0) return;
                var sourceTile = walls.Element(sourceX, sourceY);
                var patternSlot = neighbourX < sourceX ? 4 : neighbourX > sourceX ? 7 : neighbourY < sourceY ? 5 : 6;
                var pattern = WallPattern(sourceTile, patternSlot);
                var storedStyle = side == 0 ? WallStyle0(owner) : WallStyle1(owner);
                var style = NormalizedWallStyle(storedStyle);
                var faceDown = down || (style == 1 && Cutaway(neighbourX, neighbourY));
                if (faceDown && IsDoorEdge(ownerX, ownerY, side, storedStyle)) return;
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
                var sourceDirection = camera.SourceWallDirection(face);
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
                    Wall: style == 1 ? new WallSide(sourceX, sourceY, wallLevel, sourceDirection) : null,
                    Level: wallLevel, Room: faceRoom,
                    ArchitectureDepth: new WallDepth(sourceX, sourceY, wallLevel, face + 4),
                    Near: Zoom(pattern, wallStyle, 2, 2f, NearWallRectangles, face, face, faceDown),
                    Far: Zoom(pattern, wallStyle, 0, 0.5f, FarWallRectangles, face + 8, face, faceDown)));
            }
            // ARRY segment bits 0x10 (horizontal) and 0x20 (vertical) encode diagonal walls.
            void AddDiagonal()
            {
                var owner = walls!.Element(sourceX, sourceY);
                var sourceDiag = owner[0] & 0x30;
                if (sourceDiag is not (0x10 or 0x20)) return;
                var cameraDiag = camera.Orientation % 2 == 0 ? sourceDiag : sourceDiag ^ 0x30;
                var face = cameraDiag == 0x10 ? 2 : 3;
                var (primarySlot, facingSide) = DiagonalFacingSlotAndSide(sourceDiag, camera.Orientation);
                var secondarySlot = primarySlot == 6 ? 7 : 6;
                var primaryPattern = WallPattern(owner, primarySlot);
                var secondaryPattern = WallPattern(owner, secondarySlot);
                var pattern = primaryPattern != 0 ? primaryPattern : secondaryPattern;
                var leftPattern = secondaryPattern != 0 ? secondaryPattern : primaryPattern;
                var storedStyle = WallStyle1(owner);
                var style = storedStyle;
                var diagDown = down || (wallLevel == viewLevel && style is not (2 or 12 or 13 or 14) && cutawayMask is not null && cutawayMask[sourceY * lotSize + sourceX]);
                if (diagDown && IsDoorEdge(sourceX, sourceY, 1, storedStyle)) return;
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
                // Diagonal tiles report RoomMap.NoRoom, so sample the camera-facing sub-tile half for lighting.
                var (diagSubX, diagSubY) = sourceDiag == 0x10
                    ? (primarySlot == 6 ? (4, 4) : (12, 12))
                    : (primarySlot == 6 ? (4, 12) : (12, 4));
                var diagRoom = wallRooms is not null && sourceX >= 0 && sourceY >= 0 && sourceX < wallRooms.Width && sourceY < wallRooms.Height
                    ? wallRooms.RoomAtPosition(sourceX * 16 + diagSubX, sourceY * 16 + diagSubY)
                    : wallRooms?.RoomAt(sourceX, sourceY);
                sprites.Add(new SceneSprite(texture, point.X - 34 + rectangle.X, point.Y - 158 + rectangle.Y,
                    rectangle.Width, rectangle.Height, false, 0, camera.DepthOrderCamera(u, v) - 0.5f, 1,
                    ArchitectureDepth(face + 4, texture), interval.Near, interval.Far,
                    Wall: NormalizedWallStyle(storedStyle) == 1
                        ? new WallSide(sourceX, sourceY, wallLevel, camera.SourceWallDirection(face), Edge: sourceDiag,
                            Side: facingSide)
                        : null,
                    Level: wallLevel, Room: diagRoom,
                    ArchitectureDepth: new WallDepth(sourceX, sourceY, wallLevel, face + 4),
                    Near: DiagZoom(2, 2f, NearWallRectangles, face),
                    Far: DiagZoom(0, 0.5f, FarWallRectangles, face + 8)));
            }
            void AddVertexCap(int flags, bool isDown, bool mixedDown, int requiredArmMask)
            {
                if (walls is null || flags == 0) return;
                var corner = camera.CameraPoint(sourceX, sourceY);
                var vx = (int)MathF.Round(corner.X);
                var vy = (int)MathF.Round(corner.Y);
                (int ArmBit, int EndU, int EndV, int ArtFace, bool Right, int FarW, int MedW, int NearW, int PatKind, int PatU, int PatV) spec = (flags & 0xff) switch
                {
                    0x01 => (0x01, vx - 1, vy, 1, true, 2, 5, 11, 0, vx, vy - 1),
                    0x02 => (0x02, vx, vy - 1, 0, false, 2, 6, 12, 1, vx - 1, vy),
                    0x04 or 0x06 => (0x04, vx, vy - 1, 0, false, 3, 6, 12, 0, vx, vy),
                    0x08 or 0x09 => (0x08, vx - 1, vy, 1, true, 2, 5, 11, 1, vx, vy),
                    0x14 => (0x04, vx, vy - 1, 0, false, 2, 4, 8, 0, vx, vy),
                    0x18 => (0x08, vx - 1, vy, 1, true, 2, 4, 8, 1, vx, vy),
                    0x30 => (0x20, vx, vy - 1, 2, false, 2, 4, 8, 2, vx - 1, vy),
                    0x90 => (0x80, vx - 1, vy, 2, true, 2, 4, 8, 2, vx, vy - 1),
                    _ => default,
                };
                if (spec.ArmBit == 0 || (requiredArmMask & spec.ArmBit) == 0) return;
                var (patTileX, patTileY) = camera.SourceTile(spec.PatU, spec.PatV);
                if (patTileX < 0 || patTileY < 0 || patTileX >= lotSize || patTileY >= lotSize ||
                    patTileX >= walls.Rows || patTileY >= walls.Width)
                    return;
                ushort pattern;
                int? capRoom;
                if (spec.PatKind == 2)
                {
                    var diagOwner = walls.Element(patTileX, patTileY);
                    var sourceDiag = diagOwner[0] & 0x30;
                    if (sourceDiag is not (0x10 or 0x20)) return;
                    var (primarySlot, _) = DiagonalFacingSlotAndSide(sourceDiag, camera.Orientation);
                    var secondarySlot = primarySlot == 6 ? 7 : 6;
                    var primaryPattern = WallPattern(diagOwner, primarySlot);
                    var secondaryPattern = WallPattern(diagOwner, secondarySlot);
                    pattern = primaryPattern != 0 ? primaryPattern : secondaryPattern;
                    var (diagSubX, diagSubY) = sourceDiag == 0x10
                        ? (primarySlot == 6 ? (4, 4) : (12, 12))
                        : (primarySlot == 6 ? (4, 12) : (12, 4));
                    capRoom = wallRooms is not null && patTileX < wallRooms.Width && patTileY < wallRooms.Height
                        ? wallRooms.RoomAtPosition(patTileX * 16 + diagSubX, patTileY * 16 + diagSubY)
                        : wallRooms?.RoomAt(patTileX, patTileY);
                }
                else
                {
                    var (neighX, neighY) = spec.PatKind == 0
                        ? camera.SourceTile(spec.PatU - 1, spec.PatV)
                        : camera.SourceTile(spec.PatU, spec.PatV - 1);
                    var (ownerX, ownerY, side) = EdgeOwner(patTileX, patTileY, neighX, neighY);
                    if (ownerX < 0 || ownerY < 0 || ownerX >= lotSize || ownerY >= lotSize ||
                        ownerX >= walls.Rows || ownerY >= walls.Width)
                        return;
                    var edgeOwner = walls.Element(ownerX, ownerY);
                    if ((edgeOwner[0] & (side == 0 ? 1 : 2)) == 0) return;
                    var patTile = walls.Element(patTileX, patTileY);
                    var patternSlot = neighX < patTileX ? 4 : neighX > patTileX ? 7 : neighY < patTileY ? 5 : 6;
                    pattern = WallPattern(patTile, patternSlot);
                    var sourceDirection = camera.SourceWallDirection(spec.PatKind);
                    var (faceSubX, faceSubY) = sourceDirection switch
                    {
                        0 => (2, 8),
                        1 => (8, 2),
                        2 => (13, 8),
                        _ => (8, 13),
                    };
                    capRoom = wallRooms is not null && patTileX < wallRooms.Width && patTileY < wallRooms.Height
                        ? wallRooms.RoomAtPosition(patTileX * 16 + faceSubX, patTileY * 16 + faceSubY)
                        : wallRooms?.RoomAt(patTileX, patTileY);
                }
                var capStyle = WallStyleArt.Base(1);
                var fullTexture = WallTexture(pattern, capStyle, spec.ArtFace, isDown, 1);
                if (fullTexture < 0) return;
                var endTexture = WallStrip(fullTexture, spec.MedW, spec.Right);
                var depthTexture = WallStrip(ArchitectureDepth(spec.ArtFace + 4, fullTexture), spec.MedW, spec.Right);
                var endAltitude = Elevation(sourceX, sourceY) / 40f + (wallLevel - 1) * EntityTransform.StoryHeight;
                var endPoint = camera.ProjectCamera(spec.EndU, spec.EndV, endAltitude * 40);
                var rect = WallRectangles[spec.ArtFace];
                var stripX = spec.Right ? rect.Width - spec.MedW : 0;
                var spriteX = endPoint.X - 34 + rect.X + stripX;
                var spriteY = endPoint.Y - 158 + rect.Y;
                var depthBias = 0.01f + ((flags & 0xa0) != 0 ? 0.02f : 0f) + (mixedDown ? 0.02f : 0f);
                var interval = camera.SpriteDepthCamera(spec.EndU + depthBias, spec.EndV + depthBias, endAltitude);
                ZoomImage? CapZoom(int zoom, float scale, int widthPx, (int X, int Y, int Width, int Height)[] rects, int config)
                {
                    var full = WallTexture(pattern, capStyle, spec.ArtFace, isDown, zoom);
                    if (full < 0) return null;
                    var r = rects[spec.ArtFace];
                    var x = endPoint.X - 34 + (r.X + (spec.Right ? r.Width - widthPx : 0)) / scale;
                    var y = endPoint.Y - 158 + r.Y / scale;
                    return new ZoomImage(WallStrip(full, widthPx, spec.Right), x - spriteX, y - spriteY,
                        widthPx / scale, r.Height / scale, WallStrip(ArchitectureDepth(config, full), widthPx, spec.Right));
                }
                sprites.Add(new SceneSprite(endTexture, spriteX, spriteY, spec.MedW, rect.Height, false, 0,
                    camera.DepthOrderCamera(spec.EndU + depthBias, spec.EndV + depthBias) - 0.5f, 1, depthTexture,
                    interval.Near, interval.Far,
                    Level: wallLevel, Room: capRoom,
                    ArchitectureDepth: new WallDepth(patTileX, patTileY, wallLevel, spec.ArtFace + 4),
                    Near: CapZoom(2, 2f, spec.NearW, NearWallRectangles, spec.ArtFace),
                    Far: CapZoom(0, 0.5f, spec.FarW, FarWallRectangles, spec.ArtFace + 8)));
            }
            void AddJunction(int sourceFlags, bool isDown)
            {
                if (sourceFlags == 0) return;
                var flags = camera.CameraJunction(sourceFlags);
                var rawFrame = JunctionFrames[flags & 0xff];
                var frameIndex = rawFrame is 0 or byte.MaxValue ? -1 : rawFrame - 1;
                if (frameIndex < 0) return;
                var useDownSheet = isDown && (flags & 0x50) == 0;
                var texture = JunctionTexture(1, frameIndex, useDownSheet);
                if (texture < 0) return;
                var floorAltitude = Elevation(sourceX, sourceY) / 40f + (wallLevel - 1) * EntityTransform.StoryHeight;
                var altitude = floorAltitude + (isDown ? 0.3f : EntityTransform.StoryHeight);
                var corner = camera.CameraPoint(sourceX, sourceY);
                var hasQuadrantMask = isDown && wallArtwork?.Find(ResourceType.Spr1, 6145) is not null;
                var depthBias = !hasQuadrantMask && (flags & 0x40) != 0 ? 0.5f : -0.5f;
                var interval = camera.SpriteDepthCamera(corner.X + depthBias, corner.Y + depthBias, altitude);
                var point = camera.ProjectCamera(corner.X, corner.Y, altitude * 40);
                int JunctionDepth(int zoom, int configuration, int art) =>
                    isDown ? LoweredJunctionDepth(zoom, frameIndex, useDownSheet, configuration, art) : ArchitectureDepth(configuration, art);
                ZoomImage? JunctionZoom(int zoom, float scale, (int X, int Y) destination, int configuration)
                {
                    var art = JunctionTexture(zoom, frameIndex, useDownSheet);
                    if (art < 0) return null;
                    return new ZoomImage(art, destination.X / scale - JunctionOrigin.X,
                        destination.Y / scale - JunctionOrigin.Y, 64, 32, JunctionDepth(zoom, configuration, art));
                }
                var junctionRoom = wallRooms is not null && sourceX >= 0 && sourceY >= 0 && sourceX < wallRooms.Width && sourceY < wallRooms.Height
                    ? (int?)wallRooms.RoomAt(sourceX, sourceY)
                    : (wallRooms is not null ? RoomMap.NoRoom : 1);
                sprites.Add(new SceneSprite(texture, point.X - 32, point.Y - (isDown ? 15 : 13), 64, 32, false, 0,
                    camera.DepthOrderCamera(corner.X, corner.Y) - 0.5f, 1, JunctionDepth(1, 19, texture),
                    interval.Near, interval.Far, Level: wallLevel, Room: junctionRoom,
                    Junction: new WallJunction(sourceX, sourceY, wallLevel, sourceFlags, frameIndex, isDown),
                    Near: JunctionZoom(2, 2f, (4, isDown ? 318 : 317), 18), Far: JunctionZoom(0, 0.5f, (1, 80), 20)));
            }
            var (leftX, leftY) = camera.SourceTile(u - 1, v);
            var (upX, upY) = camera.SourceTile(u, v - 1);
            AddFace(0, leftX, leftY);
            AddFace(1, upX, upY);
            AddDiagonal();
            var rawDownJunction = downJunctions[sourceY * Size + sourceX];
            var rawUpJunction = upJunctions[sourceY * Size + sourceX];
            var downJunctionFlags = rawDownJunction != 0 ? camera.CameraJunction(rawDownJunction) : 0;
            var upJunctionFlags = rawUpJunction != 0 ? camera.CameraJunction(rawUpJunction) : 0;
            AddVertexCap(upJunctionFlags, isDown: false, mixedDown: false, requiredArmMask: upJunctionFlags);
            if (downJunctionFlags != 0)
                AddVertexCap(downJunctionFlags | upJunctionFlags, isDown: true, mixedDown: upJunctionFlags != 0, requiredArmMask: downJunctionFlags);
            AddJunction(rawDownJunction, isDown: true);
            AddJunction(rawUpJunction, isDown: false);

            int WallTexture(ushort pattern, WallStyleArt styleArt, int frame, bool down, int zoom) =>
                ResolveWallTexture(wallArtwork, gameRoot, lotWallMap, dynamicWallFiles, pattern, styleArt,
                    frame, down, zoom, textures, files, wallTextures, missingResources);
        }

        }

        }

        var mediumUnitHeight = (float)(Math.Sqrt(64 * 64 / 2.0) * Math.Cos(Math.PI / 6));
        // Sims.exe SLOT height-code table (1-based).
        float[] slotHeightOffsets = [0f, 2.5f, 4f, 4.05f, 0f, 0f, 0f, 4f, 0f];
        var avatarGeometry = AvatarSceneGeometry.For(gameRoot, registry);
        var avatarParts = new Dictionary<short, IReadOnlyList<AvatarSceneGeometry.Part>>();
        var buildingAvatars = new HashSet<short>();
        XPerson? selectedPerson = null;
        if (allowPlumbbob && world[SimulationGlobal.SimlessBuildMode] == 0)
        {
            var effectiveSelectedId = authoritativeSelectedPersonId ?? world[SimulationGlobal.SelectedPersonID];
            if (effectiveSelectedId is > 0 && world.ObjectById(effectiveSelectedId) is XPerson byId)
            {
                selectedPerson = byId;
            }
            else if (authoritativeSelectedPersonId is null)
            {
                foreach (var candidate in world.WalkOrder)
                {
                    if (candidate is XPerson flagged && (flagged.Flags & 2u) != 0)
                    {
                        selectedPerson = flagged;
                        break;
                    }
                }
            }
        }
        Dictionary<short, List<uint>>? heldPropGuidsByPerson = null;
        foreach (var walkItem in world.WalkOrder)
        {
            if (walkItem is XPerson || walkItem[ObjectData.Hidden] != 0) continue;
            if (walkItem[ObjectData.ContainerId] == 0 && walkItem[ObjectData.ParentId] == 0) continue;
            var walkGuid = (uint)(walkItem.TypeRecord?.Key ?? 0);
            if (walkGuid != 0 &&
                avatarGeometry.HasHandPropMesh(walkGuid) &&
                (ContainmentParent(world, walkItem) ??
                 (walkItem[ObjectData.ContainerId] != 0 ? world.ObjectById(walkItem[ObjectData.ContainerId]) : null)) is XPerson holder)
            {
                if (!(heldPropGuidsByPerson ??= []).TryGetValue(holder.Id, out var list))
                    heldPropGuidsByPerson[holder.Id] = list = [];
                list.Add(walkGuid);
            }
        }
        foreach (var walkEntry in world.WalkOrder)
        {
            if (walkEntry is not XPerson person) continue;
            var visibleOnStairs = person.Position.Height == viewLevel + 1 && person[PersonData.WalkingUpStairs] != 0;
            if (person.Position.X < 0 || person.Position.Y < 0 || person.Position.Height < 1 ||
                (person.Position.Height > viewLevel && !visibleOnStairs) || person[ObjectData.Hidden] != 0) continue;
            if (hideInteriorPeople && IsPersonHiddenBehindClosedRoof(world, person)) continue;
            BuildAvatar(person);
        }

        void BuildAvatar(XPerson person, bool refreshPose = false)
        {
            if (!refreshPose && avatarParts.ContainsKey(person.Id)) return;
            var hadPreviousParts = avatarParts.TryGetValue(person.Id, out var previousParts);
            if (refreshPose) avatarParts.Remove(person.Id);
            if (!buildingAvatars.Add(person.Id))
            {
                if (refreshPose && hadPreviousParts) avatarParts[person.Id] = previousParts!;
                if (!refreshPose) avatarParts[person.Id] = Array.Empty<AvatarSceneGeometry.Part>();
                return;
            }
            try
            {
                System.Numerics.Vector3? attachmentRoot = null;
                float? inheritedRootDirection = null;
                var parent = ContainmentParent(world, person);
                // SlotHierNumber is 1-based; 2 maps to logical HEAD slot 1 (XPerson.Slots[2]).
                if (person[ObjectData.SlotHierNumber] == 2 && parent is XPerson parentPerson &&
                    HeadSlotTargets(world, parentPerson, person) &&
                    parentPerson.Position.Height >= 1 &&
                    (parentPerson.Position.Height <= viewLevel ||
                     (parentPerson.Position.Height == viewLevel + 1 && parentPerson[PersonData.WalkingUpStairs] != 0)))
                {
                    BuildAvatar(parentPerson, refreshPose);
                    if (avatarGeometry.HeadPosition(parentPerson) is { } headPosition)
                    {
                        attachmentRoot = headPosition;
                        inheritedRootDirection = avatarGeometry.RootDirection(parentPerson);
                    }
                }

                // headIndicatorKind: 1=selected plumbbob, 2=date plumbbob, 3=fame star.
                var headSlotOccupied = false;
                if (person.Slots.Count > 2 && person.Slots[2] != 0)
                {
                    foreach (var item in world.WalkOrder)
                    {
                        if (!ReferenceEquals(item, person) &&
                            item[ObjectData.SlotHierNumber] == 2 &&
                            ReferenceEquals(ContainmentParent(world, item), person) &&
                            HeadSlotTargets(world, person, item))
                        {
                            headSlotOccupied = true;
                            break;
                        }
                    }
                }
                var headIndicatorKind = headSlotOccupied || !allowPlumbbob
                    ? 0
                    : selectedPerson is not null && person.Id == selectedPerson.Id
                        ? 1
                        : selectedPerson is not null && selectedPerson[PersonData.AutoFollowHotDate] > 0 &&
                          selectedPerson[PersonData.AutoFollowHotDate] == person.Id
                            ? 2
                            : person[PersonData.FameStarPower09] >= 10
                                ? 3
                                : 0;

                avatarParts[person.Id] = avatarGeometry.Build(person, person.Position.Height, cameraOrientation, Elevation,
                    camera, attachmentRoot: attachmentRoot, inheritedRootDirection: inheritedRootDirection,
                    headIndicatorKind: headIndicatorKind, subTickAlpha: animating ? subTickAlpha : 0f, updates: updates,
                    careerHost: world.CareerHost, heldPropGuids: heldPropGuidsByPerson?.GetValueOrDefault(person.Id));
            }
            catch
            {
                if (refreshPose && hadPreviousParts) avatarParts[person.Id] = previousParts!;
                throw;
            }
            finally { buildingAvatars.Remove(person.Id); }
        }
        var objectPositions = new Dictionary<XObject, Vector3>();
        var resolvingContainment = new HashSet<XObject>();
        var shadowedObjectTiles = new HashSet<(int Level, int TileX, int TileY)>();
        var traceSpriteGuid = uint.TryParse(Environment.GetEnvironmentVariable("SIMS_NATIVE_TRACE_SPRITE_GUID"),
            NumberStyles.HexNumber, CultureInfo.InvariantCulture, out var parsedTraceSpriteGuid) ? parsedTraceSpriteGuid : 0;
        var tracedSpriteResources = new HashSet<(short Id, ushort Graphic, int Direction)>();
        Vector3 ObjectPosition(XObject entity)
        {
            if (objectPositions.TryGetValue(entity, out var cached)) return cached;
            if (!resolvingContainment.Add(entity)) return RootPosition(entity.Position);
            try
            {
                var container = ContainmentParent(world, entity) ??
                    (entity[ObjectData.ContainerId] != 0 ? world.ObjectById(entity[ObjectData.ContainerId]) : null);
                var position = ResolveObjectPosition(entity, container,
                    RootPosition,
                    (person) => avatarParts.ContainsKey(person.Id)
                        ? avatarGeometry.HeadPosition(person) ?? SlotPosition(person, 1)
                        : SlotPosition(person, 1),
                    (parent, slotIndex) => SlotPosition(parent, slotIndex),
                    (person) => avatarParts.ContainsKey(person.Id)
                        ? avatarGeometry.HandPosition(person) ?? SlotPosition(person, 0)
                        : SlotPosition(person, 0),
                    (person) => avatarParts.ContainsKey(person.Id)
                        ? avatarGeometry.PelvisPosition(person) ?? SlotPosition(person, 2)
                        : SlotPosition(person, 2),
                    (person) => avatarParts.ContainsKey(person.Id)
                        ? avatarGeometry.HeadAttachmentPosition(person) ?? SlotPosition(person, 3)
                        : SlotPosition(person, 3));
                objectPositions.Add(entity, position);
                return position;
            }
            finally { resolvingContainment.Remove(entity); }
        }
        Vector3 RootPosition(ObjectPosition tile) =>
            new(tile.X / 16f, tile.Y / 16f,
                (tile.Height - 1) * EntityTransform.StoryHeight + Elevation(tile.X / 16f + 0.5f, tile.Y / 16f + 0.5f) / 40);
        Vector3 SlotPosition(XObject container, int index)
        {
            var origin = ObjectPosition(container);
            if (index < 0) return origin;
            var defSlots = container.DefinitionSlots;
            var matchedSlotIndex = -1;
            var matchIndex = 0;
            for (var s = 0; s < defSlots.Count; s++)
            {
                if (defSlots[s].Type != 0) continue;
                if (matchIndex == index) { matchedSlotIndex = s; break; }
                matchIndex++;
            }
            if (matchedSlotIndex < 0) return origin;
            var item = defSlots[matchedSlotIndex];
            var height = item.Height switch
            {
                1 or 2 or 3 or 4 or 8 => slotHeightOffsets[item.Height - 1],
                >= 0 and <= 9 => item.Z,
                _ => throw new InvalidDataException("Invalid object containment slot height"),
            };
            var (rotatedX, rotatedY) = RotateCardinalOffset(container[ObjectData.Direction], item.X / 16f, item.Y / 16f);
            return origin + new Vector3(rotatedX, rotatedY,
                container is XPerson ? 0 : height / 5);
        }
        world.HeadSeekGeometryResolver = (actor, target) =>
        {
            if (actor.AnimatorHeadSeekRegistrationsAvailable == false) return null;
            try { BuildAvatar(actor, refreshPose: true); }
            catch (Exception error) when (error is InvalidDataException or ResourceFormatException or ArgumentException)
            {
                avatarGeometry.ClearHeadSeekRegistrations(actor);
                missingResources.Add($"sim:{actor.Id}:head-seek-pose");
                return null;
            }
            if (actor.AnimatorHeadSeekRegistrationsAvailable == false ||
                avatarGeometry.HeadSeekRegistration(actor) is not { } actorRegistration ||
                avatarGeometry.HeadFakeRegistration(actor) is not { } headFakeRegistration)
                return null;

            System.Numerics.Vector2 targetPoint;
            if (target is XPerson targetPerson)
            {
                if (!ReferenceEquals(actor, targetPerson))
                {
                    try { BuildAvatar(targetPerson, refreshPose: true); }
                    catch (Exception error) when (error is InvalidDataException or ResourceFormatException or ArgumentException)
                    {
                        avatarGeometry.ClearHeadSeekRegistrations(targetPerson);
                        missingResources.Add($"sim:{targetPerson.Id}:head-seek-pose");
                        return null;
                    }
                }
                if (avatarGeometry.HeadSeekRegistration(targetPerson) is not { } targetRegistration) return null;
                targetPoint = new System.Numerics.Vector2(targetRegistration.X, targetRegistration.Z);
            }
            else
            {
                // HeadSeekGeometry uses avatar (X, Z) = lot (Y, X).
                objectPositions.Clear();
                resolvingContainment.Clear();
                var targetPosition = ObjectPosition(target);
                targetPoint = new System.Numerics.Vector2(targetPosition.Y, targetPosition.X);
            }

            return new HeadSeekGeometry(
                new System.Numerics.Vector2(actorRegistration.X, actorRegistration.Z),
                new System.Numerics.Vector2(headFakeRegistration.X, headFakeRegistration.Z), targetPoint);
        };
        var voxelStamps = !animating ? new List<VoxelStamp>(64) : null;
        void EmitObject(ObjectEntry entry, uint guid, short id, float tileX, float tileY, int level, int direction,
            short graphic = 0, short[]? dynamicSpriteFlags = null, XObject? source = null)
        {
            var origin = source is null
                ? new Vector3(tileX, tileY,
                    (level - 1) * EntityTransform.StoryHeight + Elevation(tileX + 0.5f, tileY + 0.5f) / 40)
                : ObjectPosition(source);
            var contained = IsHierarchyContained(source);
            var objectRooms = world.LotRoomMaps.GetValueOrDefault(level);
            var subtileRoom = ResolveSubtileRoom(objectRooms, origin.X, origin.Y, source);
            var shadowLightByte = TileSpriteLightByte(subtileRoom);
            var shadowHidden = source is not null && (source[ObjectData.Flags] & 4) != 0;
            if (voxelStamps is not null && !shadowHidden &&
                entry.Definition[ObjdField.Type] != 2 &&
                entry.Definition[ObjdField.BuildModeType] is not (1 or 2 or 7))
            {
                var selGraphic = SelectedGraphic((ushort)entry.Definition[ObjdField.BaseGraphic], graphic);
                var isBuildFoliage = entry.Definition[ObjdField.BuildModeType] == 4 ||
                    (entry.Definition[ObjdField.MasterId] != 0 &&
                     registry.FindAlternativeType(entry)?.Definition[ObjdField.BuildModeType] == 4);
                var isBuyPlant = !isBuildFoliage &&
                    entry.Definition[ObjdField.RoomSort] != 0 &&
                    (entry.Definition[ObjdField.FunctionFlags] & 0x20) != 0 &&
                    (entry.Definition[ObjdField.FunctionSubsort] & 0x04) != 0;
                var groundAoScale = isBuildFoliage ? 0.34f : isBuyPlant ? 0.52f : 1f;
                voxelStamps.Add(new VoxelStamp(entry.File, selGraphic, entry.Definition, direction, dynamicSpriteFlags, origin.X, origin.Y, origin.Z, level, groundAoScale));
            }
            var litLightSource = source is not null && source[ObjectData.LightingContribution0100] != 0;
            ObjectSpriteCacheKey cacheKey = default;
            var canCacheObject = source is not null && traceSpriteGuid == 0 && (animating || retain is not null);
            if (canCacheObject)
            {
                cacheKey = new ObjectSpriteCacheKey(guid, origin.X, origin.Y, origin.Z, level, direction, graphic,
                    contained, shadowHidden, litLightSource, subtileRoom ?? -1, shadowLightByte, camera.Orientation);
                if (animating && kept.ObjectSprites.TryGetValue(id, out var cachedObj) &&
                    cachedObj.Key == cacheKey &&
                    DynamicFlagsSequenceEqual(cachedObj.DynamicFlags, dynamicSpriteFlags))
                {
                    var cachedSprites = cachedObj.Sprites;
                    var hasCachedShadow = false;
                    for (var c = 0; c < cachedSprites.Length; c++)
                    {
                        if (cachedSprites[c].FloorShadow is not null) { hasCachedShadow = true; break; }
                    }
                    if (!hasCachedShadow || shadowedObjectTiles.Add((level, (int)MathF.Floor(origin.X), (int)MathF.Floor(origin.Y))))
                    {
                        sprites.AddRange(cachedSprites);
                    }
                    else
                    {
                        for (var c = 0; c < cachedSprites.Length; c++)
                        {
                            var cs = cachedSprites[c];
                            sprites.Add(cs.FloorShadow is not null
                                ? cs with { FloorShadow = null, FloorShadowNear = null, FloorShadowFar = null }
                                : cs);
                        }
                    }
                    return;
                }
            }
            var emitStart = sprites.Count;
            var baseGraphic = (ushort)entry.Definition[ObjdField.BaseGraphic];
            var selectedGraphic = SelectedGraphic(baseGraphic, graphic);
            var groupChunk = entry.File.Find(ResourceType.Dgrp, selectedGraphic);
            if (groupChunk is null)
            {
                missingResources.Add($"object:{id}:guid:{guid:x8}:dgrp:{selectedGraphic}");
                return;
            }
            DrawGroup group;
            try { group = CachedGroup(entry.File, groupChunk); }
            catch (ResourceFormatException)
            {
                missingResources.Add($"object:{id}:guid:{guid:x8}:dgrp-read:{selectedGraphic}");
                return;
            }
            var image = SelectedImage(group, direction, camera.Orientation);
            if (image is null)
            {
                missingResources.Add($"object:{id}:guid:{guid:x8}:image:{selectedGraphic}:direction:{direction}:rotation:{camera.Orientation}");
                return;
            }
            var nearImage = SelectedImage(group, direction, camera.Orientation, 3);
            var farImage = SelectedImage(group, direction, camera.Orientation, 1);
            (DepthFrame? Frame, IndexedFrame? Legacy, int Width, int Height, int PaletteId) ReadPart(
                DrawGroupSprite part, bool report) =>
                ReadDgrpPart(entry.File, part, id, report ? missingResources : null);
            int PartTexture(DrawGroupSprite part, DepthFrame? frame, IndexedFrame? legacy, int width, int height, int paletteId)
            {
                var doubleAlpha = (part.Flags & 0x10) != 0;
                var spriteKey = part.SpriteId | (doubleAlpha ? 0x1000000 : 0);
                var key = (guid, spriteKey, part.Frame);
                if (spriteTextures.TryGetValue(key, out var texture)) return texture;
                var bytes = GetPartRgbaBytes(entry.File, part, frame, legacy, width, height, paletteId);
                if (bytes is null) return -1;
                var baseName = $"sprite-{guid:x8}-{part.SpriteId}-{part.Frame}.rgba";
                var name = doubleAlpha && files.ContainsKey(baseName)
                    ? $"sprite-{guid:x8}-{part.SpriteId}-{part.Frame}-a2.rgba"
                    : baseName;
                files[name] = bytes;
                texture = textures.Count;
                textures.Add(new Texture(name, width, height, "rgba"));
                spriteTextures[key] = texture;
                return texture;
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
            var emittedAnySprite = false;
            var objectEmittedShadow = false;
            for (var index = 0; index < image.Sprites.Count; index++)
            {
                var sprite = image.Sprites[index];
                if (!DynamicSpriteVisible(sprite.SpriteId, entry.Definition[ObjdField.DynamicSpritesBaseId],
                        entry.Definition[ObjdField.NumDynamicSprites], dynamicSpriteFlags))
                    continue;
                var (frame, legacy, width, height, paletteId) = ReadPart(sprite, report: true);
                if (frame is null && legacy is null) continue;
                if (!FrameHasPixels(width, height)) continue;
                var texture = PartTexture(sprite, frame, legacy, width, height, paletteId);
                if (texture < 0) continue;
                var depthTexture = PartDepth(sprite, frame, width, height);
                var (offsetX, offsetY) = RotateCardinalOffset(direction, sprite.Offset2, sprite.Offset3);
                var offset = new Vector3(offsetX, offsetY, sprite.Offset1);
                var point = camera.Project(origin.X + offset.X / 16, origin.Y + offset.Y / 16, origin.Z * 40);
                // Omit SPR2 frame origin offsets here; DGRP sprite.X/Y already include the part pivot.
                var spriteX = (int)(point.X + sprite.X);
                var spriteY = (int)(point.Y - offset.Z / 5 * mediumUnitHeight - height + sprite.Y);
                // DGRP zoom part offsets (other.X/Y) are already in zoom-native pixels.
                ZoomImage? Zoom(DrawGroupImage? zoomed, float scale)
                {
                    if (zoomed is null || index >= zoomed.Sprites.Count) return null;
                    if (zoomed.Sprites.Count != image.Sprites.Count && index != 0) return null;
                    var other = zoomed.Sprites[index];
                    if ((other.Flags & 1) != (sprite.Flags & 1)) return null;
                    var (otherFrame, otherLegacy, otherWidth, otherHeight, otherPalette) = ReadPart(other, report: false);
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
                var sortDepth = camera.DepthOrder(origin.X + offset.X / 16,
                    origin.Y + offset.Y / 16) + 0.001f * origin.Z + (contained ? 0.01f : 0f);
                if (traceSpriteGuid != 0 && guid == traceSpriteGuid &&
                    tracedSpriteResources.Add((id, selectedGraphic, direction)))
                {
                    var sourcePosition = source?.Position;
                    var containerId = source is null ? 0 : source[ObjectData.ContainerId];
                    var slot = source is null ? -1 : source[ObjectData.SlotHierNumber];
                    var sourceParentKey = source is null ? (short)0 : source[ObjectData.ParentId];
                    var managerContainer = source is not null && containerId is > 0 and <= short.MaxValue
                        ? source.ObjectTableEntry((short)containerId)
                        : null;
                    var managerParent = source is not null && sourceParentKey > 0
                        ? source.ObjectTableEntry(sourceParentKey)
                        : null;
                    var idContainer = containerId is > 0 and <= short.MaxValue ? world.ObjectById((short)containerId) : null;
                    var resourceHash = Convert.ToHexString(SHA256.HashData(entry.File.Bytes.Span)).ToLowerInvariant();
                    Console.Error.WriteLine(string.Create(CultureInfo.InvariantCulture,
                        $"SPRITE_TRACE guid={guid:x8} id={id} graphic={selectedGraphic} dgrp={groupChunk.Id} resourceSha256={resourceHash} " +
                        $"sourceTile={(sourcePosition is null ? "none" : $"{sourcePosition.Value.X},{sourcePosition.Value.Y},{sourcePosition.Value.Height}")} " +
                        $"container={containerId} slot={slot} contained={contained} direction={direction} camera={camera.Orientation} " +
                        $"parentKey={sourceParentKey} managerContainer={(managerContainer is null ? "none" : $"{managerContainer.Id}/{managerContainer.ClockManagerIndex}/{managerContainer.TypeRecord?.Key:x8}")} " +
                        $"managerParent={(managerParent is null ? "none" : $"{managerParent.Id}/{managerParent.ClockManagerIndex}/{managerParent.TypeRecord?.Key:x8}")} " +
                        $"managerContainerClass={managerContainer?.GetType().Name ?? "none"} " +
                        $"managerContainerPos={(managerContainer is null ? "none" : $"{managerContainer.Position.X},{managerContainer.Position.Y},{managerContainer.Position.Height}")} " +
                        $"managerContainerSlot0={(managerContainer is null || managerContainer.Slots.Count == 0 ? "none" : managerContainer.Slots[0].ToString(CultureInfo.InvariantCulture))} " +
                        $"idContainer={(idContainer is null ? "none" : $"{idContainer.Id}/{idContainer.ClockManagerIndex}/{idContainer.TypeRecord?.Key:x8}")} " +
                        $"origin={origin.X:R},{origin.Y:R},{origin.Z:R} rawDgrpOffset={sprite.Offset2:R},{sprite.Offset3:R},{sprite.Offset1:R} " +
                        $"rotatedOffset={offset.X:R},{offset.Y:R},{offset.Z:R} sortDepth={sortDepth:R} " +
                        $"near={depth.Near:R} far={depth.Far:R}"));
                }
                // DGRP flag 0x4 = unlit; BuildModeType 7 = pool attachment (room 65534); house 99 = cloud lot.
                var unlitSprite = (sprite.Flags & 4) != 0 || house == 99 ||
                    (litLightSource && entry.Definition[ObjdField.Type] != 8);
                var room = unlitSprite ? null : entry.Definition[ObjdField.BuildModeType] == 7 ? 65534 : subtileRoom;
                var shadowId = ShadowId(entry, shadowParts);
                if (shadowId is { } rawMask)
                {
                    var turns = (((direction & 7) / 2) + camera.Orientation) & 3;
                    shadowId = RotateShadowId(rawMask, turns);
                }
                var shadowBrightness = (short)entry.Definition[ObjdField.ShadowBrightness];
                var attachShadow = !emittedAnySprite;
                emittedAnySprite = true;
                ZoomImage? FloorShadow(int zoom)
                {
                    if (!attachShadow || shadowId is null || contained ||
                        shadowHidden ||
                        entry.Definition[ObjdField.Type] is 2 or 9)
                        return null;
                    var altitude = (level - 1) * EntityTransform.StoryHeight +
                                   Elevation(origin.X + 0.5f, origin.Y + 0.5f) / 40f;
                    var absolute = FloorShadowAt(shadowId, shadowBrightness, shadowLightByte, zoom,
                        origin.X, origin.Y, altitude);
                    return absolute is null ? null : absolute with { X = absolute.X - spriteX, Y = absolute.Y - spriteY };
                }
                var fsMed = FloorShadow(2);
                var fsNear = FloorShadow(3);
                var fsFar = FloorShadow(1);
                if (fsMed is not null) objectEmittedShadow = true;
                sprites.Add(new SceneSprite(texture, spriteX, spriteY, width, height, (sprite.Flags & 1) != 0, id,
                    sortDepth, 1,
                    depthTexture, depthTexture.HasValue ? depth.Near : null, depthTexture.HasValue ? depth.Far : null,
                    Level: level, Room: room, Near: Zoom(nearImage, 2f), Far: Zoom(farImage, 0.5f),
                    Shadow: shadowId,
                    ShadowBrightness: shadowBrightness,
                    FloorShadow: fsMed, FloorShadowNear: fsNear, FloorShadowFar: fsFar));
            }
            if (canCacheObject)
            {
                var emittedCount = sprites.Count - emitStart;
                var emitted = emittedCount == 0 ? Array.Empty<SceneSprite>() : sprites.GetRange(emitStart, emittedCount).ToArray();
                var flagsCopy = dynamicSpriteFlags is null or { Length: 0 } ? null : (short[])dynamicSpriteFlags.Clone();
                kept.ObjectSprites[id] = new CachedObjectSprites(cacheKey, flagsCopy, emitted);
            }
            if (objectEmittedShadow &&
                !shadowedObjectTiles.Add((level, (int)MathF.Floor(origin.X), (int)MathF.Floor(origin.Y))))
            {
                for (var k = emitStart; k < sprites.Count; k++)
                {
                    if (sprites[k].FloorShadow is not null)
                        sprites[k] = sprites[k] with { FloorShadow = null, FloorShadowNear = null, FloorShadowFar = null };
                }
            }
        }

        static int? ResolveSubtileRoom(RoomMap? map, float tileX, float tileY, XObject? entity = null)
        {
            if (map is null) return null;
            var room = map.RoomAtPosition(
                Math.Clamp((int)(tileX * 16f), 0, map.Width * 16 - 1),
                Math.Clamp((int)(tileY * 16f), 0, map.Height * 16 - 1));
            if (room == RoomMap.NoRoom && entity is not null && entity.RoomWord84 >= 0 && entity.RoomWord84 != RoomMap.NoRoom)
                return entity.RoomWord84;
            return room;
        }

        void EmitRuntimeSlotSprites(XObject owner, System.Numerics.Vector3? attachmentAnchor = null)
        {
            var source = world.GlobalSprites;
            if (source is null || owner.RuntimeSlots.Count == 0) return;
            var guid = unchecked((uint)(owner.TypeRecord?.Key ?? 0));
            var tileX = attachmentAnchor?.X ?? owner.Position.X / 16f;
            var tileY = attachmentAnchor?.Y ?? owner.Position.Y / 16f;
            var altitude = attachmentAnchor?.Z ?? ((owner.Position.Height - 1) * EntityTransform.StoryHeight +
                           Elevation(tileX + 0.5f, tileY + 0.5f) / 40);
            var point = camera.Project(tileX, tileY, altitude * 40);
            var roomMap = world.LotRoomMaps.GetValueOrDefault(owner.Position.Height);
            var room = house == 99 ? null : ResolveSubtileRoom(roomMap, tileX, tileY, owner);
            for (var slotIndex = 0; slotIndex < owner.RuntimeSlots.Count; slotIndex++)
            {
                var slot = owner.RuntimeSlots[slotIndex];
                if (slot.ReadWord(0x10) == 0) continue;
                if (owner is XPerson person)
                {
                    var isSelectedPerson = (person.Flags & 2u) != 0 || world[SimulationGlobal.SelectedPersonID] == person.Id;
                    if (slot.ReadWord(0x38) == 0 && !isSelectedPerson)
                        continue;
                }
                var spriteId = slot.ReadWord(0x14);
                var rawSlotZ = BitConverter.Int32BitsToSingle(slot.ReadWord(0x08));
                var slotZ = float.IsFinite(rawSlotZ) ? rawSlotZ : 0f;

                bool EmitSprite(int resourceId, int frameIndex, string kind, float depthLayer = 0f,
                    int? nearFrameIndex = null)
                {
                    if (resourceId <= 0 || resourceId > ushort.MaxValue) return false;
                    var chunk = source.Find(ResourceType.Spr1, (ushort)resourceId);
                    if (chunk is null)
                    {
                        missingResources.Add($"runtime-slot:{owner.Id}:{kind}:{resourceId}:chunk-absent");
                        return false;
                    }
                    Sprite art;
                    try { art = CachedSprite(source, chunk); }
                    catch (ResourceFormatException)
                    {
                        missingResources.Add($"runtime-slot:{owner.Id}:{kind}:{resourceId}:read");
                        return false;
                    }
                    if (frameIndex < 0 || frameIndex >= art.Frames.Count)
                    {
                        missingResources.Add($"runtime-slot:{owner.Id}:{kind}:{resourceId}:frame:{frameIndex}:frames:{art.Frames.Count}");
                        return false;
                    }
                    var frame = art.Frames[frameIndex];
                    if (!FrameHasPixels(frame.Width, frame.Height)) return false;
                    int UploadRuntimeSlotFrame(IndexedFrame targetFrame, int targetFrameIndex)
                    {
                        var key = (guid, resourceId, targetFrameIndex);
                        if (spriteTextures.TryGetValue(key, out var cachedTexture)) return cachedTexture;
                        var palette = PaletteFor(source, art.PaletteId);
                        if (palette is null)
                        {
                            missingResources.Add($"runtime-slot:{owner.Id}:{kind}:{resourceId}:palette:{art.PaletteId}");
                            return -1;
                        }
                        var rgba = new byte[targetFrame.Width * targetFrame.Height * 4];
                        for (var pixel = 0; pixel < targetFrame.Width * targetFrame.Height; pixel++)
                        {
                            if (!targetFrame.Opaque[pixel]) continue;
                            var color = palette[targetFrame.Indices[pixel]];
                            var at = pixel * 4;
                            rgba[at] = color.Red;
                            rgba[at + 1] = color.Green;
                            rgba[at + 2] = color.Blue;
                            rgba[at + 3] = 255;
                        }
                        var name = $"runtime-slot-{guid:x8}-{resourceId}-{targetFrameIndex}.rgba";
                        files[name] = rgba;
                        var uploaded = textures.Count;
                        textures.Add(new Texture(name, targetFrame.Width, targetFrame.Height, "rgba"));
                        spriteTextures[key] = uploaded;
                        return uploaded;
                    }
                    var texture = UploadRuntimeSlotFrame(frame, frameIndex);
                    if (texture < 0) return false;
                    var (x, y) = RuntimeSlotSpritePosition(point.X, point.Y, slotZ, frame.Height, frame.BoundsLeft, frame.BoundsTop);
                    ZoomImage? ZoomRuntimeSlotImage(int? zoomFrameIndex, int zoomScale, float zoomFactor)
                    {
                        if (zoomFrameIndex is not { } idx || idx < 0 || idx >= art.Frames.Count) return null;
                        var zoomFrame = art.Frames[idx];
                        if (!FrameHasPixels(zoomFrame.Width, zoomFrame.Height)) return null;
                        var zoomTexture = UploadRuntimeSlotFrame(zoomFrame, idx);
                        if (zoomTexture < 0) return null;
                        var (zx, zy) = RuntimeSlotSpritePosition(point.X * zoomFactor, point.Y * zoomFactor, slotZ,
                            zoomFrame.Height, zoomFrame.BoundsLeft, zoomFrame.BoundsTop, scale: zoomScale);
                        return new ZoomImage(zoomTexture, zx / zoomFactor - x, zy / zoomFactor - y,
                            zoomFrame.Width / zoomFactor, zoomFrame.Height / zoomFactor, null);
                    }
                    var nearImage = ZoomRuntimeSlotImage(nearFrameIndex, zoomScale: 3, zoomFactor: 2f);
                    var objectDepth = camera.DepthOrder(tileX, tileY);
                    sprites.Add(new SceneSprite(texture, x, y, frame.Width, frame.Height, false, owner.Id,
                        objectDepth + 1.5f + slotIndex * 0.0001f + depthLayer, 1, Level: Math.Min(owner.Position.Height, viewLevel),
                        Room: null, Near: nearImage, Far: null, HideAtFarZoom: true));
                    return true;
                }

                bool? productSpeechBuffersAvailable = null;
                (int Texture, int Width, int Height)? LoadSelectorSpeechImage(uint selectorGuid, ObjectEntry selector, bool isPerson, int scale, bool recordMissing)
                {
                    var bitmapId = isPerson
                        ? (scale == 2 ? 2005 : 2006)
                        : selector.Definition[ObjdField.CatalogStringsId] + (scale == 2 ? 2000 : 4000);
                    if (bitmapId is <= 0 or > ushort.MaxValue) return null;
                    var textureKey = (selectorGuid, bitmapId);
                    if (speechImageTextures.TryGetValue(textureKey, out var cachedImage))
                        return cachedImage;

                    var bitmap = selector.File.Find(ResourceType.Parse("BMP_"), (ushort)bitmapId);
                    int width;
                    int height;
                    byte[] rgba;
                    var generated = false;
                    var iconSize = scale == 2 ? 16 : 32;
                    if (bitmap is null && !isPerson &&
                        (productSpeechBuffersAvailable ??= HasProductSpeechBuffers(gameRoot)) &&
                        ObjectCatalog.GenerateProductSpeechIcon(selector, iconSize) is { } generatedIcon)
                    {
                        (width, height, rgba) = generatedIcon;
                        generated = true;
                    }
                    else if (bitmap is null && isPerson &&
                        world.WalkOrder.OfType<XPerson>().FirstOrDefault(p => unchecked((uint)(p.TypeRecord?.Key ?? 0)) == selectorGuid) is { } speechPerson &&
                        avatarGeometry.BuildHeadMeshes(speechPerson, speechPerson.Position.Height, camera.Orientation, Elevation, camera) is { Count: > 0 } headMeshes)
                    {
                        (width, height, rgba) = SimPortrait.SpeechIcon(headMeshes, iconSize);
                        KeySpeechBitmapTransparency(width, height, rgba, isPerson: true);
                        generated = true;
                    }
                    else if (bitmap is not null)
                    {
                        try { (width, height, rgba) = BitmapCodec.Read(bitmap.Data.ToArray()); }
                        catch (InvalidDataException)
                        {
                            if (recordMissing)
                                missingResources.Add($"runtime-slot:{owner.Id}:speech-image:{selectorGuid:x8}:bmp:{bitmapId}:read");
                            return null;
                        }
                        KeySpeechBitmapTransparency(width, height, rgba, isPerson: isPerson);
                    }
                    else
                    {
                        if (recordMissing)
                            missingResources.Add($"runtime-slot:{owner.Id}:speech-image:{selectorGuid:x8}:bmp:{bitmapId}:chunk-absent");
                        return null;
                    }

                    if (!FrameHasPixels(width, height)) return null;
                    var name = $"runtime-slot-speech-{selectorGuid:x8}-{bitmapId}{(generated ? "-generated" : "")}.rgba";
                    files[name] = rgba;
                    var texture = textures.Count;
                    textures.Add(new Texture(name, width, height, "rgba"));
                    var image = (texture, width, height);
                    speechImageTextures[textureKey] = image;
                    return image;
                }

                void EmitSelectorSpeechImage(ObjectRuntimeSlot runtimeSlot, int depthSlotIndex)
                {
                    if (runtimeSlot.SelectorTypeKey is not { } selectorKey) return;
                    var selectorGuid = unchecked((uint)selectorKey);
                    var selector = registry.Find(selectorGuid);
                    if (selector is null) return;

                    var isPerson = selector.Definition[ObjdField.Type] == 2;
                    if (LoadSelectorSpeechImage(selectorGuid, selector, isPerson, scale: 2, recordMissing: true) is not { } image)
                        return;

                    var (x, y) = RuntimeSlotSpeechImagePosition(point.X, point.Y, slotZ, image.Width, image.Height);
                    ZoomImage? nearImage = null;
                    if (LoadSelectorSpeechImage(selectorGuid, selector, isPerson, scale: 3, recordMissing: false) is { } nearSpeech)
                    {
                        var (nearX, nearY) = RuntimeSlotSpeechImagePosition(point.X * 2f, point.Y * 2f, slotZ,
                            nearSpeech.Width, nearSpeech.Height, scale: 3);
                        nearImage = new ZoomImage(nearSpeech.Texture, nearX / 2f - x, nearY / 2f - y,
                            nearSpeech.Width / 2f, nearSpeech.Height / 2f, null);
                    }
                    var objectDepth = camera.DepthOrder(tileX, tileY);
                    sprites.Add(new SceneSprite(image.Texture, x, y, image.Width, image.Height, false, owner.Id,
                        objectDepth + 1.5f + depthSlotIndex * 0.0001f + 0.00002f, 1, Level: Math.Min(owner.Position.Height, viewLevel),
                        Room: null, Near: nearImage, HideAtFarZoom: true));
                }

                EmitSprite(slot.ReadWord(0x2c), RuntimeSlotOverlayFrame(scale: 2), "balloon",
                    depthLayer: 0f, nearFrameIndex: RuntimeSlotOverlayFrame(scale: 3));

                if (spriteId >= 0)
                    EmitSprite(spriteId, RuntimeSlotSpriteFrame(scale: 2, slot.ReadWord(0x20)), "sprite",
                        depthLayer: 0.00002f, nearFrameIndex: RuntimeSlotSpriteFrame(scale: 3, slot.ReadWord(0x20)));
                else
                    EmitSelectorSpeechImage(slot, slotIndex);

                EmitSprite(slot.ReadWord(0x30), RuntimeSlotOverlayFrame(scale: 2), "label",
                    depthLayer: 0.00004f, nearFrameIndex: RuntimeSlotOverlayFrame(scale: 3));
            }
        }

        Lap("meshes");
        void EmitDynamicWorldObject(XObject item, XPerson? carrier)
        {
            if (carrier is not null)
            {
                if (!avatarParts.ContainsKey(carrier.Id)) return;
                // SlotHierNumber 2 is reserved for 3D head attachments/plumbbobs; 2D props use 1/5 (hand), 3 (pelvis), 4 (head).
                var slotHier = item[ObjectData.SlotHierNumber];
                var hasRegistration = slotHier switch
                {
                    1 or 5 => avatarGeometry.HandPosition(carrier).HasValue,
                    3 => avatarGeometry.PelvisPosition(carrier).HasValue,
                    4 => avatarGeometry.HeadAttachmentPosition(carrier).HasValue,
                    _ => false,
                };
                if (!hasRegistration) return;
            }
            else
            {
                if (item.Position.Height < 1 || item.Position.Height > viewLevel) return;
                if (item.Position.X < 0 || item.Position.Y < 0) return;
            }
            if (item[ObjectData.Hidden] != 0) return;
            if (item.Definition[(int)ObjdField.SubIndex] < 0 && item.Definition[(int)ObjdField.MasterId] != 0) return;
            var guid = (uint)(item.TypeRecord?.Key ?? 0);
            if (wallMode == "down" || wallMode == "cutaway")
            {
                var lowered = animating
                    ? item.Position.Height >= 1 && item.Position.Height <= viewLevel &&
                      IsWallObjectLowered(item.Position.Height, item.Position.X >> 4, item.Position.Y >> 4,
                          unchecked((ushort)item[ObjectData.Flags]), unchecked((ushort)item[ObjectData.FlagField2]),
                          item[ObjectData.WallPlacementFlags], item[ObjectData.Direction],
                          unresetPortalFallback: world.ChangedCodeTypeGuids.Contains(guid))
                    : wallObjectIds.Contains(item.Id);
                if (lowered) return;
            }
            if (guid == 2179383033u) return; // Pedestrian portal (no visible artwork).
            var entry = registry.Find(guid);
            if (entry is null) return;
            var itemLevel = item.Position.Height >= 1 ? item.Position.Height : (carrier?.Position.Height ?? 1);
            EmitObject(entry, guid, item.Id, item.Position.X / 16f, item.Position.Y / 16f, itemLevel,
                item[ObjectData.Direction], item[ObjectData.Graphic], item.DynamicSpriteFlags, item);
            EmitRuntimeSlotSprites(item);
        }

        var useSubTickCache = animating && directAnimation && subTickAlpha > 0f &&
            updates == kept.LastAnimatedUpdates &&
            kept.CachedNonCarriedObjectSprites is not null &&
            kept.CachedSubTickLights is not null &&
            kept.CachedSubTickWindows is not null;

        if (useSubTickCache)
        {
            sprites.AddRange(kept.CachedNonCarriedObjectSprites!);
            foreach (var item in world.WalkOrder)
            {
                if (item is XPerson) continue;
                if (item[ObjectData.ContainerId] == 0 && item[ObjectData.ParentId] == 0) continue;
                var carrier = (ContainmentParent(world, item) ?? (item[ObjectData.ContainerId] != 0 ? world.ObjectById(item[ObjectData.ContainerId]) : null)) as XPerson;
                var itemGuid = (uint)(item.TypeRecord?.Key ?? 0);
                if (carrier is not null && (itemGuid == 0 || !avatarGeometry.HasHandPropMesh(itemGuid)))
                    EmitDynamicWorldObject(item, carrier);
            }
        }
        else
        {
            List<(XObject Item, XPerson Carrier)>? carriedObjects = null;
            foreach (var item in world.WalkOrder)
            {
                if (item is XPerson) continue;
                var carrier = (ContainmentParent(world, item) ?? (item[ObjectData.ContainerId] != 0 ? world.ObjectById(item[ObjectData.ContainerId]) : null)) as XPerson;
                if (carrier is not null)
                {
                    var itemGuid = (uint)(item.TypeRecord?.Key ?? 0);
                    if (itemGuid == 0 || !avatarGeometry.HasHandPropMesh(itemGuid))
                        (carriedObjects ??= []).Add((item, carrier));
                    continue;
                }
                EmitDynamicWorldObject(item, null);
            }
            if (!hasLiveObjects)
            {
                foreach (var door in savedDoors)
                {
                    if (animating && world.ObjectById(door.Id) is not null) continue;
                    if ((wallMode == "down" || wallMode == "cutaway") &&
                        IsWallObjectLowered(door.Level, door.TileX, door.TileY, door.Flags1,
                            door.Flags2 != 0 ? door.Flags2 : 0xc000, door.WallPlacement, door.Direction, unresetPortalFallback: true))
                        continue;
                    EmitObject(door.Entry, door.Guid, door.Id, door.X, door.Y, door.Level, door.Direction,
                        door.Graphic, door.DynamicSpriteFlags);
                }
            }
            if (animating && directAnimation)
            {
                kept.CachedNonCarriedObjectSprites = sprites.Count == 0 ? Array.Empty<SceneSprite>() : sprites.ToArray();
            }
            if (carriedObjects is not null)
            {
                foreach (var (item, carrier) in carriedObjects)
                    EmitDynamicWorldObject(item, carrier);
            }
        }
        Lap("items");
        var censorRects = new List<CensorRect>();
        var skillMeters = new List<SkillMeterRecord>();
        var personBasePoints = new Dictionary<short, (float X, float Y, int Level)>();
        foreach (var walkEntry in world.WalkOrder)
        {
            if (walkEntry is not XPerson person) continue;
            var visibleOnStairs = person.Position.Height == viewLevel + 1 && person[PersonData.WalkingUpStairs] != 0;
            if (person.Position.X < 0 || person.Position.Y < 0 || person.Position.Height < 1 ||
                (person.Position.Height > viewLevel && !visibleOnStairs) || person[ObjectData.Hidden] != 0) continue;
            if (hideInteriorPeople && IsPersonHiddenBehindClosedRoof(world, person)) continue;
            var personLevel = person.Position.Height;
            var avatarRoot = avatarGeometry.RootPosition(person);
            var avatarAnchor = avatarGeometry.PelvisPosition(person) ?? avatarRoot;
            var tileX = avatarAnchor.X;
            var tileY = avatarAnchor.Y;
            var rootTileX = person.Position.X / 16f;
            var rootTileY = person.Position.Y / 16f;
            var rootAlt = (personLevel - 1) * EntityTransform.StoryHeight + Elevation(rootTileX + 0.5f, rootTileY + 0.5f) / 40f;
            var basePt = camera.Project(rootTileX, rootTileY, rootAlt * 40f);
            personBasePoints[person.Id] = (basePt.X, basePt.Y, Math.Min(personLevel, viewLevel));
            if (person.RuntimeSlots.Count > 0 &&
                person.RuntimeSlots[0].ReadWord(0x10) != 0 &&
                person.RuntimeSlots[0].ReadWord(0x14) is >= 800 and <= 829 and var meterSpriteId)
            {
                var headAnchor = avatarGeometry.HeadAttachmentPosition(person) ?? avatarRoot;
                var headPt = camera.Project(headAnchor.X, headAnchor.Y, headAnchor.Z * 40f);
                skillMeters.Add(new SkillMeterRecord(
                    person.Id,
                    meterSpriteId,
                    (meterSpriteId - 800) % 10,
                    headPt.X,
                    headPt.Y,
                    Math.Min(personLevel, viewLevel)));
            }
            var personRooms = world.LotRoomMaps.GetValueOrDefault(personLevel);
            var parts = avatarParts.GetValueOrDefault(person.Id) ?? [];
            var isGhostOrLivingGhost = (person[PersonData.IsGhost] & 1) != 0 || (person[PersonData.IsLivingGhost] & 1) != 0;
            var displayFlags = person[PersonData.RenderDisplayFlags];
            float[]? avatarTint = isGhostOrLivingGhost
                ? [17f / 255f, 1f, 241f / 255f, 128f / 255f]
                : (displayFlags & 2) != 0
                    ? [17f / 255f, 1f, 128f / 255f, 128f / 255f]
                    : (displayFlags & 1) != 0
                        ? [248f / 255f, 248f / 255f, 1f, 128f / 255f]
                        : null;
            ZoomImage? avatarShadow = null;
            ZoomImage? avatarShadowNear = null;
            ZoomImage? avatarShadowFar = null;
            if (house != 99 && parts.Count > 0 && person[PersonData.Sitting] == 0 && !person.AnimatorPoolTile &&
                (person[ObjectData.Flags] & 4) == 0 && !isGhostOrLivingGhost)
            {
                var groundAltitude = (personLevel - 1) * EntityTransform.StoryHeight + Elevation(tileX, tileY) / 40f;
                var personShadowLight = TileSpriteLightByte(ResolveSubtileRoom(personRooms, tileX, tileY, person));
                var shadowScale = person[PersonData.Gender] >= 2 || PersonAgeCategory.IsChild(person[PersonData.PersonAge])
                    ? 0.78f
                    : 1f;
                ZoomImage? ScaleAvatarShadow(ZoomImage? z) => z is null || shadowScale == 1f
                    ? z
                    : z with
                    {
                        X = z.X + z.Width * (1f - shadowScale) * 0.5f,
                        Y = z.Y + z.Height * (1f - shadowScale) * 0.5f,
                        Width = z.Width * shadowScale,
                        Height = z.Height * shadowScale,
                    };
                avatarShadow = ScaleAvatarShadow(FloorShadowAt(0, 75, personShadowLight, 2, tileX, tileY, groundAltitude));
                avatarShadowNear = ScaleAvatarShadow(FloorShadowAt(0, 75, personShadowLight, 3, tileX, tileY, groundAltitude));
                avatarShadowFar = ScaleAvatarShadow(FloorShadowAt(0, 75, personShadowLight, 1, tileX, tileY, groundAltitude));
            }
            var partIndex = 0;
            foreach (var part in parts)
            {
                var name = $"avatar-{person.Id}-{partIndex}-{part.TextureHash}.{part.Encoding}";
                if (!kept.AvatarTextures.TryGetValue(name, out var texture))
                {
                    files[name] = part.Texture;
                    texture = textures.Count;
                    textures.Add(new Texture(name, part.Width, part.Height, part.Encoding));
                    kept.AvatarTextures[name] = texture;
                }
                var sourceVertices = part.Vertices;
                var vertices = new Vertex[sourceVertices.Length];
                for (var vIdx = 0; vIdx < sourceVertices.Length; vIdx++)
                {
                    ref readonly var vertex = ref sourceVertices[vIdx];
                    vertices[vIdx] = new Vertex(vertex.X, vertex.Y, vertex.Z, vertex.U, vertex.V,
                        vertex.Nx, vertex.Ny, vertex.Nz);
                }
                var applyTint = avatarTint is not null && !part.IgnoreRoomLighting;
                var room = part.IgnoreRoomLighting || house == 99 || applyTint
                    ? null
                    : ResolveSubtileRoom(personRooms, tileX, tileY, person);
                meshes.Add(new Mesh(texture, person.Id, camera.DepthOrder(tileX, tileY), vertices,
                    Math.Min(personLevel, viewLevel), room,
                    FloorShadow: partIndex == 0 ? avatarShadow : null,
                    FloorShadowNear: partIndex == 0 ? avatarShadowNear : null,
                    FloorShadowFar: partIndex == 0 ? avatarShadowFar : null,
                    Tint: applyTint ? avatarTint : null,
                    Indicator: part.IgnoreRoomLighting ? true : null));
                partIndex++;
            }
            if (avatarGeometry.Censor(person) is { } censor)
                censorRects.Add(new CensorRect(censor.X, censor.Y, censor.Width, censor.Height, censor.Depth));
            EmitRuntimeSlotSprites(person, avatarGeometry.HeadAttachmentPosition(person) ?? avatarRoot);
        }

        if (!animating && roofsVisible)
        {
            var settings = LotRoof.Read(lot);
            var styles = LotRoof.Styles(gameRoot);
            var styleIndex = styles.ToList().FindIndex(style => string.Equals(style, settings.Style, StringComparison.OrdinalIgnoreCase));
            if (styleIndex < 0 && styles.Count > 0) styleIndex = 0;
            var selectedStyle = styleIndex >= 0 && styleIndex < styles.Count ? styles[styleIndex] : settings.Style;
            var roofPath = LotRoof.MaterialPath(gameRoot, selectedStyle);
            if (styleIndex < 0 || roofPath is null) missingResources.Add($"roof-material:{settings.Style}");
            else
            {
                var bytes = File.ReadAllBytes(roofPath);
                if (bytes.Length < 54 || bytes[0] != 'B' || bytes[1] != 'M')
                    throw new InvalidDataException("Roof material is not a BMP");
                var width = System.Buffers.Binary.BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(18));
                var height = Math.Abs((long)System.Buffers.Binary.BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(22)));
                if (width < 1 || width > 4096 || height < 1 || height > 4096)
                    throw new InvalidDataException("Invalid roof texture dimensions");
                var texture = textures.Count;
                var textureFile = $"roof-{styleIndex}.bmp";
                files[textureFile] = bytes;
                textures.Add(new Texture(textureFile, width, (int)height, "bmp"));
                var material = new RoofSurface("surface", (uint)styleIndex, settings.Pitch, Path.GetFileName(roofPath));
                var totalStories = Stories(lot);
                var roofGrids = new Dictionary<int, RoofGrid>();
                RoofGrid? upperRoof = null;
                for (var buildLevel = totalStories; buildLevel >= 1; buildLevel--)
                {
                    var builtGrid = LotRoofGrid.Build(lot, buildLevel, world.WalkOrder, upperRoof);
                    roofGrids[buildLevel] = builtGrid;
                    upperRoof = builtGrid;
                }
                for (var level = 1; level <= Math.Min(viewLevel, totalStories); level++)
                {
                    var grid = roofGrids[level];
                    var vertices = new List<Vertex>();
                    for (var row = 1; row < Math.Min(grid.Size - 1, lotSize * 2); row++)
                    for (var column = 1; column < Math.Min(grid.Size - 1, lotSize * 2); column++)
                    {
                        if (!grid.Has(row, column)) continue;
                        // Sample base tile elevation so overhanging eaves do not warp with neighbor terrain.
                        var altitude = level * EntityTransform.StoryHeight + Elevation(column / 2, row / 2) / 40;
                        var placed = RoofCellMesh.Build(grid, row, column, settings.Pitch).Select(vertex =>
                            (Position: new Vector3(vertex.X, altitude + vertex.Height, vertex.Y),
                                vertex.U, vertex.V)).ToArray();
                        for (var index = 0; index < placed.Length; index += 3)
                        {
                            var normal = Vector3.Cross(placed[index + 1].Position - placed[index].Position,
                                placed[index + 2].Position - placed[index].Position);
                            if (normal.LengthSquared() > 0) normal = Vector3.Normalize(normal);
                            else normal = Vector3.UnitY;
                            normal = camera.CameraNormal(normal);
                            for (var corner = 0; corner < 3; corner++)
                            {
                                var vertex = placed[index + corner];
                                var point = camera.Project(vertex.Position.X, vertex.Position.Z, vertex.Position.Y * 40);
                                // Depth-bias roofs toward camera so wall-top sprites under eaves do not poke through.
                                var roofDepthBias = level == totalStories ? 0.0045f : 0.0018f;
                                var roofDepth = MathF.Max(0.001f, camera.Depth(vertex.Position.X, vertex.Position.Z, vertex.Position.Y) - roofDepthBias);
                                var output = new Vertex(point.X, point.Y, roofDepth,
                                    vertex.U, vertex.V, normal.X, normal.Y, normal.Z);
                                vertices.Add(output);
                                meshVertices.Add((output, column / 2, row / 2));
                            }
                        }
                    }
                    if (vertices.Count > 0) meshes.Add(new Mesh(texture, 0, 0, vertices.ToArray(), level,
                        Room: 0, Unlit: false, Layer: 2, Roof: material));
                }
            }
        }

        var lights = new List<SceneLighting.Light>();
        var windows = new List<SceneLighting.Window>();
        SceneLighting.Light[]? cachedLights = null;
        SceneLighting.Window[]? cachedWindows = null;
        Lap("avatars");
        if (useSubTickCache)
        {
            cachedLights = kept.CachedSubTickLights!;
            cachedWindows = kept.CachedSubTickWindows!;
        }
        else
        {
            HashSet<short>? emittedFireplaces = null;
            foreach (var item in world.WalkOrder)
            {
                if (SceneLighting.IsWindow(item))
                    windows.Add(new SceneLighting.Window(item.Position.X >> 4, item.Position.Y >> 4, item.Position.Height));
                if (!SceneLighting.IsLightSource(item) || item.Position.Height > viewLevel) continue;
                var fireKind = SceneLighting.FireKind(item);
                var lightX = item.Position.X / 16f;
                var lightY = item.Position.Y / 16f;
                var strength = SceneLighting.LightStrength(item, fireKind);
                if (fireKind == SceneLighting.FireLightKind.Fireplace)
                {
                    if (emittedFireplaces is not null && emittedFireplaces.Contains(item.Id)) continue;
                    emittedFireplaces ??= new HashSet<short>();
                    var sumX = 0f;
                    var sumY = 0f;
                    var count = 0;
                    var maxStrength = 0;
                    foreach (var member in world.MultiTileMembers(item))
                    {
                        emittedFireplaces.Add(member.Id);
                        if (!SceneLighting.IsLightSource(member) || member.Position.Height > viewLevel) continue;
                        sumX += member.Position.X / 16f;
                        sumY += member.Position.Y / 16f;
                        count++;
                        maxStrength = Math.Max(maxStrength, SceneLighting.LightStrength(member, fireKind));
                    }
                    if (count > 0)
                    {
                        lightX = sumX / count;
                        lightY = sumY / count;
                        strength = maxStrength;
                    }
                    var (fx, fy) = LotGeometry.FootprintOffset(item[ObjectData.Direction]);
                    lightX += (fx / 16f) * 0.38f;
                    lightY += (fy / 16f) * 0.38f;
                }
                var altitude = (item.Position.Height - 1) * EntityTransform.StoryHeight + Elevation(lightX, lightY) / 40 +
                    SceneLighting.LightLiftFor(fireKind);
                var point = camera.Project(lightX, lightY, altitude * 40);
                var toward = camera.CameraPoint(lightX, lightY);
                lights.Add(new SceneLighting.Light(point.X, point.Y, toward.X + toward.Y + 0.8f * altitude,
                    strength, item.Position.Height, fireKind != SceneLighting.FireLightKind.None));
            }
            if (animating && directAnimation)
            {
                kept.CachedSubTickLights = lights.Count == 0 ? Array.Empty<SceneLighting.Light>() : lights.ToArray();
                kept.CachedSubTickWindows = windows.Count == 0 ? Array.Empty<SceneLighting.Window>() : windows.ToArray();
                kept.LastAnimatedUpdates = updates;
            }
        }

        var activeOverhead = world.ActiveOverheadFeedback();
        var overheadFeedback = new List<OverheadFeedbackRecord>(activeOverhead.Count);
        foreach (var evt in activeOverhead)
        {
            if (personBasePoints.TryGetValue(evt.PersonId, out var pt))
            {
                var kind = evt.Kind switch
                {
                    OverheadFeedbackKind.Currency => "currency",
                    OverheadFeedbackKind.SkillUp => "skillUp",
                    OverheadFeedbackKind.Magenta => "magenta",
                    _ => "currency",
                };
                var remaining = Math.Max(0, evt.ExpiresAtTick - world.Clock.Ticks);
                overheadFeedback.Add(new OverheadFeedbackRecord(
                    evt.PersonId, kind, evt.Text, evt.BackgroundRgb, evt.ForegroundRgb,
                    evt.Delta, pt.X, pt.Y, pt.Level, evt.StackIndex, remaining));
            }
        }

        if (animating)
        {
            Lap("animation");
            if (ProfileEnabled && sequence % 60 == 0) Console.Error.WriteLine("Animation phases (ms):" + lapText);
            var animatingInMemory = SimsSimulation.InMemorySessionAssets.IsInMemoryPath(directory);
            foreach (var (name, bytes) in files)
            {
                var target = Path.Combine(directory, name);
                if (!kept.Written.Add(name) &&
                    (!animatingInMemory || SimsSimulation.InMemorySessionAssets.ContainsFile(target)))
                    continue;
                if (animatingInMemory) SimsSimulation.InMemorySessionAssets.StoreFile(target, bytes);
                else File.WriteAllBytes(target, bytes);
            }
            var dx = kept.ShiftX;
            var dy = kept.ShiftY;
            var lightCount = cachedLights is not null ? cachedLights.Length : lights.Count;
            SceneLighting.Light[] shiftedLights;
            if (lightCount == 0)
            {
                shiftedLights = Array.Empty<SceneLighting.Light>();
            }
            else
            {
                shiftedLights = new SceneLighting.Light[lightCount];
                for (var i = 0; i < lightCount; i++)
                {
                    var light = cachedLights is not null ? cachedLights[i] : lights[i];
                    shiftedLights[i] = light with { X = light.X + dx, Y = light.Y + dy };
                }
            }
            var animatedLighting = baseLighting is { } animatedBuilt
                ? animatedBuilt with
                {
                    Lights = shiftedLights,
                    Windows = cachedWindows is not null
                        ? cachedWindows
                        : windows.Count == 0 ? Array.Empty<SceneLighting.Window>() : windows.ToArray(),
                }
                : null;
            var baseTextureCount = kept.BaseTextureCount;
            var newTextureCount = textures.Count - baseTextureCount;
            Texture[] animatedTextures;
            if (newTextureCount <= 0)
            {
                animatedTextures = Array.Empty<Texture>();
            }
            else
            {
                animatedTextures = new Texture[newTextureCount];
                textures.CopyTo(baseTextureCount, animatedTextures, 0, newTextureCount);
            }

            SceneSprite[] animatedSprites;
            if (sprites.Count == 0)
            {
                animatedSprites = Array.Empty<SceneSprite>();
            }
            else
            {
                var order = new (float Depth, int Index)[sprites.Count];
                var count = 0;
                for (var i = 0; i < sprites.Count; i++)
                {
                    var candidate = sprites[i];
                    if (candidate.ObjectID <= 0) continue;
                    order[count++] = (candidate.Depth, i);
                }
                Array.Sort(order, 0, count);
                animatedSprites = new SceneSprite[count];
                for (var i = 0; i < count; i++)
                {
                    var sprite = sprites[order[i].Index];
                    animatedSprites[i] = sprite with { X = sprite.X + dx, Y = sprite.Y + dy };
                }
            }

            var dynamicMeshCount = 0;
            for (var i = 0; i < meshes.Count; i++)
                if (meshes[i].ObjectID > 0) dynamicMeshCount++;
            if (directAnimation)
            {
                var directMeshes = dynamicMeshCount == 0
                    ? Array.Empty<DirectAnimationMesh>()
                    : new DirectAnimationMesh[dynamicMeshCount];
                var directOut = 0;
                for (var i = 0; i < meshes.Count; i++)
                {
                    var mesh = meshes[i];
                    if (mesh.ObjectID <= 0) continue;
                    directMeshes[directOut++] = new DirectAnimationMesh(
                        mesh.Texture, mesh.ObjectID, mesh.Depth, mesh.Level, mesh.Room,
                        ShiftAnimationShadow(mesh.FloorShadow),
                        ShiftAnimationShadow(mesh.FloorShadowNear),
                        ShiftAnimationShadow(mesh.FloorShadowFar),
                        mesh.Vertices, dx, dy, mesh.Tint, mesh.Indicator);
                }

                CensorRect[] directCensors;
                if (censorRects.Count == 0)
                {
                    directCensors = Array.Empty<CensorRect>();
                }
                else
                {
                    directCensors = new CensorRect[censorRects.Count];
                    for (var i = 0; i < censorRects.Count; i++)
                    {
                        var rect = censorRects[i];
                        directCensors[i] = rect with { X = rect.X + dx, Y = rect.Y + dy };
                    }
                }

                OverheadFeedbackRecord[]? ShiftOverhead(float sx, float sy)
                {
                    if (overheadFeedback.Count == 0) return null;
                    var arr = new OverheadFeedbackRecord[overheadFeedback.Count];
                    for (var i = 0; i < overheadFeedback.Count; i++)
                    {
                        var o = overheadFeedback[i];
                        arr[i] = o with { X = o.X + sx, Y = o.Y + sy };
                    }
                    return arr;
                }
                SkillMeterRecord[]? ShiftSkillMeters(float sx, float sy)
                {
                    if (skillMeters.Count == 0) return null;
                    var arr = new SkillMeterRecord[skillMeters.Count];
                    for (var i = 0; i < skillMeters.Count; i++)
                    {
                        var m = skillMeters[i];
                        arr[i] = m with { X = m.X + sx, Y = m.Y + sy };
                    }
                    return arr;
                }
                return new DirectAnimationFrame(
                    revision, sequence, updates, baseTextureCount, animatedLighting,
                    animatedTextures, animatedSprites, directMeshes, directCensors,
                    ShiftOverhead(dx, dy), ShiftSkillMeters(dx, dy));
            }

            var animatedMeshes = new object[dynamicMeshCount];
            var meshOut = 0;
            for (var i = 0; i < meshes.Count; i++)
            {
                var mesh = meshes[i];
                if (mesh.ObjectID <= 0) continue;
                animatedMeshes[meshOut++] = new
                {
                    mesh.Texture, mesh.ObjectID, mesh.Depth, mesh.Level, mesh.Room,
                    FloorShadow = ShiftAnimationShadow(mesh.FloorShadow),
                    FloorShadowNear = ShiftAnimationShadow(mesh.FloorShadowNear),
                    FloorShadowFar = ShiftAnimationShadow(mesh.FloorShadowFar),
                    tint = mesh.Tint,
                    indicator = mesh.Indicator,
                    vertices = PackVertices(mesh.Vertices, dx, dy),
                };
            }

            CensorRect[] animatedCensorRects;
            if (censorRects.Count == 0)
            {
                animatedCensorRects = Array.Empty<CensorRect>();
            }
            else
            {
                animatedCensorRects = new CensorRect[censorRects.Count];
                for (var i = 0; i < censorRects.Count; i++)
                {
                    var rect = censorRects[i];
                    animatedCensorRects[i] = rect with { X = rect.X + dx, Y = rect.Y + dy };
                }
            }

            return new AnimatedJsonPayload(
                1,
                revision,
                sequence,
                updates,
                baseTextureCount,
                animatedLighting,
                missingResources.Count == 0 ? Array.Empty<string>() : missingResources.Order().ToArray(),
                animatedTextures,
                animatedSprites,
                animatedMeshes,
                animatedCensorRects,
                overheadFeedback.Count == 0 ? null : overheadFeedback.Select(o => o with { X = o.X + dx, Y = o.Y + dy }).ToArray(),
                skillMeters.Count == 0 ? null : skillMeters.Select(m => m with { X = m.X + dx, Y = m.Y + dy }).ToArray());

            ZoomImage? ShiftAnimationShadow(ZoomImage? shadow) => shadow is null
                ? null
                : shadow with { X = shadow.X + dx, Y = shadow.Y + dy };
        }

        var placementLift = (viewLevel - 1) * EntityTransform.StoryHeight * 40;
        var meshShadows = meshes.SelectMany(mesh => new[] { mesh.FloorShadow, mesh.FloorShadowNear, mesh.FloorShadowFar })
            .OfType<ZoomImage>()
            .ToArray();
        var allX = terrain.Select(vertex => vertex.X)
            .Concat(meshVertices.Select(item => item.Vertex.X))
            .Concat(sprites.Select(sprite => sprite.X))
            .Concat(sprites.Select(sprite => sprite.X + sprite.Width))
            .ToArray();
        var allY = terrain.Select(vertex => vertex.Y)
            .Concat(terrain.Select(vertex => vertex.Y - placementLift))
            .Concat(meshVertices.Select(item => item.Vertex.Y))
            .Concat(sprites.Select(sprite => sprite.Y))
            .Concat(sprites.Select(sprite => sprite.Y + sprite.Height))
            .ToArray();
        var minX = allX.Min();
        var minY = allY.Min();
        var shiftX = 2 - minX;
        var shiftY = 2 - minY;
        var maxX = allX.Concat(meshes.SelectMany(mesh => mesh.Vertices).Select(vertex => vertex.X))
            .Concat(meshShadows.Select(shadow => shadow.X + shadow.Width))
            .Max();
        var maxY = allY.Concat(meshes.SelectMany(mesh => mesh.Vertices).Select(vertex => vertex.Y))
            .Concat(meshShadows.Select(shadow => shadow.Y + shadow.Height))
            .Max();
        var sceneWidth = maxX - minX + 4;
        var sceneHeight = maxY - minY + 4;
        terrain = terrain.Select(vertex => vertex with { X = vertex.X + shiftX, Y = vertex.Y + shiftY }).ToList();
        var viewWalls = viewLevelWalls;
        var floorDiagonals = new int[lotSize * lotSize];
        if (viewWalls is not null)
        {
            for (var y = 0; y < lotSize; y++)
            for (var x = 0; x < lotSize; x++)
            {
                if (x < viewWalls.Rows && y < viewWalls.Width)
                    floorDiagonals[y * lotSize + x] = viewWalls.Element(x, y)[0] & 0x30;
            }
        }
        ZoomImage? ShiftShadow(ZoomImage? shadow) => shadow is null
            ? null
            : shadow with { X = shadow.X + shiftX, Y = shadow.Y + shiftY };
        meshes = meshes.Select(mesh => mesh with
        {
            Vertices = mesh.Vertices.Select(vertex => vertex with { X = vertex.X + shiftX, Y = vertex.Y + shiftY }).ToArray(),
            FloorShadow = ShiftShadow(mesh.FloorShadow),
            FloorShadowNear = ShiftShadow(mesh.FloorShadowNear),
            FloorShadowFar = ShiftShadow(mesh.FloorShadowFar),
        }).ToList();
        sprites = sprites.Select(sprite => sprite with { X = sprite.X + shiftX, Y = sprite.Y + shiftY }).ToList();
        censorRects = censorRects.Select(rect => rect with { X = rect.X + shiftX, Y = rect.Y + shiftY }).ToList();
        var shiftedOverhead = overheadFeedback.Count == 0
            ? null
            : overheadFeedback.Select(o => o with { X = o.X + shiftX, Y = o.Y + shiftY }).ToArray();
        var shiftedSkillMeters = skillMeters.Count == 0
            ? null
            : skillMeters.Select(m => m with { X = m.X + shiftX, Y = m.Y + shiftY }).ToArray();
        Lap("sprites");
        var lighting = baseLighting is { } built
            ? built with
            {
                Lights = lights.Select(light => light with { X = light.X + shiftX, Y = light.Y + shiftY }).ToArray(),
                Windows = windows.ToArray(),
            }
            : null;

        var inMemory = SimsSimulation.InMemorySessionAssets.IsInMemoryPath(directory);
        if (!inMemory) Directory.CreateDirectory(directory);
        Lap("lighting");
        var previousWritten = retain?.Kept is Kept prevKept ? prevKept.Written : null;
        var prunedOldRevisionFiles = false;
        if (inMemory)
        {
            if (previousWritten is not null && SimsSimulation.InMemorySessionAssets.TotalDirectBytesIn(directory) > 192L * 1024 * 1024)
            {
                foreach (var stale in previousWritten)
                {
                    if (!files.ContainsKey(stale))
                    {
                        SimsSimulation.InMemorySessionAssets.DeleteFile(Path.Combine(directory, stale));
                    }
                }
                prunedOldRevisionFiles = true;
            }
            foreach (var pair in files)
            {
                var target = Path.Combine(directory, pair.Key);
                if (previousWritten is not null && previousWritten.Contains(pair.Key) &&
                    SimsSimulation.InMemorySessionAssets.ContainsFile(target))
                    continue;
                SimsSimulation.InMemorySessionAssets.StoreFile(target, pair.Value);
            }
        }
        else
        {
            Parallel.ForEach(files, pair =>
            {
                if (previousWritten is not null && previousWritten.Contains(pair.Key)) return;
                var target = Path.Combine(directory, pair.Key);
                if (new FileInfo(target) is { Exists: true } existing && existing.Length == pair.Value.Length) return;
                File.WriteAllBytes(target, pair.Value);
            });
        }
        var path = Path.Combine(directory, $"scene-{revision}.json");
        var soundSources = world.PositionalSoundOwners
            .Select(id => world.ObjectById(id))
            .Where(item => item is not null && item.Position.Height >= 1)
            .Select(item =>
            {
                var source = item!;
                var tileX = source.Position.X / 16f + 0.5f;
                var tileY = source.Position.Y / 16f + 0.5f;
                var altitude = (source.Position.Height - 1) * EntityTransform.StoryHeight + Elevation(tileX, tileY) / 40f;
                return new SoundSourceRecord(source.Id, source.Position.Height, tileX, tileY, altitude * 40f);
            }).ToArray();
        OverheadMapRecord? overheadMap = null;
        if (!animating)
        {
            const int samples = 8;
            var shelterCache = GetShelterCache(lot, world);
            if (shelterCache.CachedOverheadMap is { } cachedOverhead &&
                shelterCache.CachedOverheadLotSize == lotSize &&
                shelterCache.CachedOverheadBaseHeight == baseHeight)
            {
                overheadMap = cachedOverhead;
            }
            else
            {
                var mapWidth = lotSize * samples;
                var mapHeight = lotSize * samples;
                var mapPixels = new byte[mapWidth * mapHeight * 4];
                var totalStories = Math.Min(Stories(lot), 5);
                var roofPitch = LotRoof.Read(lot).Pitch;
                var roofTop = new float[mapWidth * mapHeight];
                Array.Fill(roofTop, float.NegativeInfinity);
                var maxRoofLevel = Math.Min(totalStories, 2);
                for (var rLevel = 1; rLevel <= maxRoofLevel; rLevel++)
                {
                    if (shelterCache.Roofs[rLevel] is not { } roofGrid) continue;
                    var rowLimit = Math.Min(roofGrid.Size - 1, lotSize * 2);
                    var colLimit = Math.Min(roofGrid.Size - 1, lotSize * 2);
                    for (var row = 1; row < rowLimit; row++)
                    for (var column = 1; column < colLimit; column++)
                    {
                        if (!roofGrid.Has(row, column)) continue;
                        var tris = RoofCellMesh.Build(roofGrid, row, column, roofPitch);
                        if (tris.Count == 0) continue;
                        var cellBaseAlt = rLevel * EntityTransform.StoryHeight + Elevation(column / 2, row / 2) / 40f;
                        var fallbackHeight = roofGrid.Height(row, column) * roofPitch * 0.5f;
                        for (var sy = 0; sy < 4; sy++)
                        {
                            var qy = row * 4 + sy;
                            var py = (qy + 0.5f) / samples;
                            var qRow = qy * mapWidth;
                            for (var sx = 0; sx < 4; sx++)
                            {
                                var qx = column * 4 + sx;
                                var px = (qx + 0.5f) / samples;
                                var sampledHeight = fallbackHeight;
                                for (var tri = 0; tri + 2 < tris.Count; tri += 3)
                                {
                                    var a = tris[tri];
                                    var b = tris[tri + 1];
                                    var c = tris[tri + 2];
                                    var v0x = c.X - a.X;
                                    var v0y = c.Y - a.Y;
                                    var v1x = b.X - a.X;
                                    var v1y = b.Y - a.Y;
                                    var denom = v0x * v1y - v1x * v0y;
                                    if (MathF.Abs(denom) < 1e-8f) continue;
                                    var v2x = px - a.X;
                                    var v2y = py - a.Y;
                                    var inv = 1f / denom;
                                    var u = (v2x * v1y - v1x * v2y) * inv;
                                    var v = (v0x * v2y - v2x * v0y) * inv;
                                    var w = 1f - u - v;
                                    if (u >= -1e-4f && v >= -1e-4f && w >= -1e-4f)
                                    {
                                        sampledHeight = w * a.Height + u * c.Height + v * b.Height;
                                        break;
                                    }
                                }
                                var top = cellBaseAlt + sampledHeight;
                                var idx = qRow + qx;
                                if (top > roofTop[idx]) roofTop[idx] = top;
                            }
                        }
                    }
                }
                Parallel.For(0, mapHeight, qy =>
                {
                    var ty = qy / samples;
                    var fy = (qy % samples + 0.5f) / samples;
                    var wy16 = Math.Clamp((int)MathF.Floor((ty + fy) * 16f), 0, Size * 16 - 1);
                    var rowBase = qy * mapWidth * 4;
                    var gridRow = qy * mapWidth;
                    for (var qx = 0; qx < mapWidth; qx++)
                    {
                        var tx = qx / samples;
                        var fx = (qx % samples + 0.5f) / samples;
                        var wx16 = Math.Clamp((int)MathF.Floor((tx + fx) * 16f), 0, Size * 16 - 1);
                        var offset = rowBase + qx * 4;
                        byte mask = 0;
                        for (var level = 1; level <= totalStories; level++)
                        {
                            if (IsCoveredSubtile(shelterCache, level, tx, ty, fx, fy))
                                mask |= (byte)(1 << (level - 1));
                        }
                        var worldX = tx + fx;
                        var worldY = ty + fy;
                        var hasUpper2Floor = totalStories >= 2 &&
                            HasUpperFloorAt(shelterCache.Floors[2], shelterCache.Walls[2], tx, ty, fx, fy);
                        var directRoof1 = IsDirectRoofedAt(shelterCache, 1, worldX, worldY);
                        var directRoof2 = IsDirectRoofedAt(shelterCache, 2, worldX, worldY);
                        var hasCeil1 = hasUpper2Floor || directRoof1 || directRoof2;
                        if (hasCeil1) mask |= 0x20;
                        var hasStory2Room = totalStories >= 2 && shelterCache.Rooms[2] is { } rooms2 &&
                            rooms2.RoomAtPosition(wx16, wy16) is var room2 && room2 != RoomMap.NoRoom && !rooms2.IsOutside(room2);
                        var hasStory2 = directRoof2 || hasStory2Room;
                        if (hasStory2) mask |= 0x40;
                        mapPixels[offset] = mask;
                        var altitude = ElevationAt(heights, baseHeight, worldX, worldY) / 40f;
                        var code = Math.Clamp((int)MathF.Round(altitude * 256f) + 32768, 0, 65535);
                        mapPixels[offset + 1] = (byte)(code >> 8);
                        mapPixels[offset + 2] = (byte)code;
                        var roofVal = roofTop[gridRow + qx];
                        var topAboveBase = float.IsFinite(roofVal) ? roofVal - altitude : -1f;
                        for (var upper = 2; upper <= totalStories; upper++)
                        {
                            if (HasUpperFloorAt(shelterCache.Floors[upper], shelterCache.Walls[upper], tx, ty, fx, fy))
                                topAboveBase = MathF.Max(topAboveBase, (upper - 1) * EntityTransform.StoryHeight);
                        }
                        if (hasStory2)
                            topAboveBase = MathF.Max(topAboveBase, 2f * EntityTransform.StoryHeight);
                        mapPixels[offset + 3] = topAboveBase >= 0f
                            ? (byte)Math.Clamp(2 + (int)MathF.Round(topAboveBase * 16f), 2, 254)
                            : (byte)1;
                    }
                });
                overheadMap = new OverheadMapRecord(mapWidth, mapHeight, samples, mapPixels);
                shelterCache.CachedOverheadLotSize = lotSize;
                shelterCache.CachedOverheadBaseHeight = baseHeight;
                shelterCache.CachedOverheadMap = overheadMap;
            }
        }
        var voxelMap = voxelStamps is { Count: > 0 } ? BuildOrthoDepthMap(lotSize, camera.Orientation, voxelStamps, Elevation) : null;

        var exported = new ExportedLotScene(
            house,
            sceneWidth,
            sceneHeight,
            lotSize,
            floorDiagonals,
            TerrainHeights(lot, lotSize),
            camera.Orientation,
            -shiftX,
            -shiftY,
            wallMode,
            roofsVisible,
            viewLevel,
            Stories(lot),
            lighting,
            textures.ToArray(),
            sprites.ToArray(),
            soundSources,
            terrain.ToArray(),
            placementLift,
            meshes.ToArray(),
            censorRects.ToArray(),
            ["native engine scene"],
            missingResources.Order().ToArray(),
            overheadMap,
            shiftedOverhead,
            shiftedSkillMeters,
            voxelMap);
        static FullJsonPayload BuildJsonScene(ExportedLotScene payload) => new(
            1,
            payload.House,
            payload.Width,
            payload.Height,
            payload.LotSize,
            payload.LotSize,
            payload.FloorDiagonals,
            payload.TerrainHeights,
            payload.CameraOrientation,
            payload.OriginX,
            payload.OriginY,
            payload.WallMode,
            payload.WallMode == "up",
            payload.RoofsVisible,
            payload.ViewLevel,
            payload.Stories,
            payload.Lighting,
            payload.Textures,
            payload.Sprites,
            payload.SoundSources.Select(s => new SoundSourceJson(s.ObjectID, s.Level, s.X, s.Y, s.Z)).ToArray(),
            payload.Terrain.Select(vertex => new TerrainVertex(
                vertex.X, vertex.Y - payload.PlacementLift, vertex.R, vertex.G, vertex.B,
                vertex.Dr, vertex.Dg, vertex.Db, vertex.Grass)).ToArray(),
            payload.Terrain.Select((vertex, index) =>
            {
                var tileIndex = index / 6;
                var tx = tileIndex % payload.LotSize;
                var ty = tileIndex / payload.LotSize;
                var v = (tx == 0 || tx == payload.LotSize - 1 || ty == 0 || ty == payload.LotSize - 1) ? payload.Terrain[tileIndex * 6] : vertex;
                return new TerrainVertex(
                    v.X, v.Y, v.R, v.G, v.B,
                    v.Dr, v.Dg, v.Db, v.Grass);
            }).ToArray(),
            payload.Meshes,
            payload.CensorRects,
            payload.Limitations,
            payload.MissingResources,
            payload.OverheadMap is { } om
                ? new OverheadMapRecord(om.Width, om.Height, om.SamplesPerTile, om.Pixels)
                : null,
            payload.OverheadFeedback,
            payload.SkillMeters,
            payload.VoxelMap is { } vm
                ? new OverheadMapRecord(vm.Width, vm.Height, vm.SamplesPerTile, vm.Pixels)
                : null);
        Lap("write");
        if (retain is not null)
        {
            kept.Textures = textures;
            kept.BaseTextureCount = textures.Count;
            kept.SpriteTextures = spriteTextures;
            kept.SpeechImageTextures = speechImageTextures;
            kept.SpriteDepthTextures = spriteDepthTextures;
            kept.FloorShadowTextures = floorShadowTextures;
            var mergedWritten = previousWritten is not null && !prunedOldRevisionFiles
                ? new HashSet<string>(previousWritten, StringComparer.Ordinal)
                : new HashSet<string>(files.Count, StringComparer.Ordinal);
            foreach (var key in files.Keys) mergedWritten.Add(key);
            kept.Written = mergedWritten;
            kept.Heights = heights;
            kept.BaseHeight = baseHeight;
            kept.CutawayMask = cutawayMask;
            kept.WallAdjacentTiles = wallAdjacentTiles;
            kept.ViewLevel = viewLevel;
            kept.WallMode = wallMode;
            kept.CameraOrientation = cameraOrientation;
            kept.CutawayTile = cutawayTile;
            kept.CutawayRooms = cutawayRooms is null or { Count: 0 } ? [] : [.. cutawayRooms];
            kept.CutawaySim = cutawaySim;
            kept.CutawayZoom = cutawayZoom;
            kept.CutawayRaiseHoveredWalls = raiseHoveredWalls;
            kept.ViewLevelWalls = viewLevelWalls;
            kept.CutawayWallPairs = cutawayWallPairs;
            kept.CutawayDiagonalTiles = cutawayDiagonalTiles;
            kept.ObjectStyles = objectStyles;
            kept.WallObjectKinds = wallObjectKinds;
            kept.HasLiveObjects = hasLiveObjects;
            kept.WallObjectIds = wallObjectIds;
            kept.SavedDoors = savedDoors;
            kept.ShiftX = shiftX;
            kept.ShiftY = shiftY;
            retain.Revision = revision;
            retain.Kept = kept;
        }
        if (inMemory)
        {
            SimsSimulation.InMemorySessionAssets.StoreScene(path, exported,
                () => JsonSerializer.SerializeToUtf8Bytes(BuildJsonScene(exported), Json));
            SimsSimulation.InMemorySessionAssets.PruneOldScenes(directory, revision - 3);
        }
        else
        {
            using (var stream = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.Read, 65536))
            {
                JsonSerializer.Serialize(stream, BuildJsonScene(exported), Json);
            }
        }
        Lap("json");
        if (ProfileEnabled) Console.Error.WriteLine("Export phases (ms):" + lapText);
        return path;
    }

    private static readonly ConcurrentDictionary<(IffFile File, ushort Id), DrawGroup> groupCache = new();
    private static readonly ConcurrentDictionary<(IffFile File, ushort Id), DepthSprite> depthSpriteCache = new();
    private static readonly ConcurrentDictionary<(IffFile File, ushort Id), Sprite> spriteCache = new();
    private static readonly ConcurrentDictionary<(IffFile File, int PaletteId, int SpriteKey, int Frame), byte[]> partRgbaBytesCache = new();
    private static readonly ConcurrentDictionary<(IffFile File, int SpriteId, int Frame), byte[]> partDepthBytesCache = new();
    private static readonly ConcurrentDictionary<(IffFile File, int Shadow, int Attenuation, int Zoom), (int Width, int Height, byte[]? Bytes)> floorShadowBytesCache = new();
    private static readonly ConcurrentDictionary<(int Configuration, int Width, int Height), byte[]> archDepthBytesCache = new();
    private static readonly ConcurrentDictionary<(IffFile File, int Zoom, int Frame, bool LoweredSheet), byte[]> loweredJunctionDepthBytesCache = new();
    private static readonly ConcurrentDictionary<(IffFile PatternFile, ushort PatternChunkId, IffFile MaskFile, ushort MaskChunkId, int Frame), (int Width, int Height, byte[] Bytes)> wallRgbaBytesCache = new();

    private static T Cached<T>(ConcurrentDictionary<(IffFile File, ushort Id), T> cache, IffFile file, IffChunk chunk, int maxEntries, Func<T> read)
    {
        if (cache.Count > maxEntries) cache.Clear();
        return cache.GetOrAdd((file, chunk.Id), _ => read());
    }

    private static DrawGroup CachedGroup(IffFile file, IffChunk chunk) => Cached(groupCache, file, chunk, 1536, () => DrawGroup.Read(file, chunk));
    private static DepthSprite CachedDepthSprite(IffFile file, IffChunk chunk) => Cached(depthSpriteCache, file, chunk, 1024, () => DepthSprite.Read(file, chunk));
    private static Sprite CachedSprite(IffFile file, IffChunk chunk) => Cached(spriteCache, file, chunk, 1536, () => Sprite.Read(file, chunk));

    internal static void TrimTransientCaches()
    {
        if (partRgbaBytesCache.Count > 512) partRgbaBytesCache.Clear();
        if (partDepthBytesCache.Count > 512) partDepthBytesCache.Clear();
        if (wallRgbaBytesCache.Count > 256) wallRgbaBytesCache.Clear();
        if (floorShadowBytesCache.Count > 128) floorShadowBytesCache.Clear();
        if (archDepthBytesCache.Count > 64) archDepthBytesCache.Clear();
        if (loweredJunctionDepthBytesCache.Count > 192) loweredJunctionDepthBytesCache.Clear();
        if (depthSpriteCache.Count > 512) depthSpriteCache.Clear();
        if (spriteCache.Count > 768) spriteCache.Clear();
        if (groupCache.Count > 1024) groupCache.Clear();
        if (objectPaletteCache.Count > 256) objectPaletteCache.Clear();
    }

    private static byte[] ResolveLoweredJunctionDepthBytes(
        IffFile wallArtwork,
        int zoom,
        int frame,
        bool loweredSheet,
        IndexedFrame artFrame,
        IndexedFrame maskFrame)
    {
        if (loweredJunctionDepthBytesCache.Count > 384) loweredJunctionDepthBytesCache.Clear();
        return loweredJunctionDepthBytesCache.GetOrAdd((wallArtwork, zoom, frame, loweredSheet), _ =>
        {
            var width = artFrame.Width;
            var height = artFrame.Height;
            var half = 16 << zoom;
            var center = half - 0.5f;
            var dx = 4f / (1 << zoom);
            var dy = 2f / (1 << zoom);
            var bias = zoom == 0 ? 1f : zoom == 2 ? 0.5f : 0f;
            var buffer = new byte[width * height];
            Array.Fill(buffer, byte.MaxValue);
            for (var row = 0; row < height; row++)
            for (var column = 0; column < width; column++)
            {
                var at = row * width + column;
                if (!artFrame.Opaque[at]) continue;
                byte raw;
                if (maskFrame.Opaque[at])
                {
                    raw = maskFrame.Indices[at];
                }
                else
                {
                    raw = 0;
                    for (var sr = Math.Max(0, row - 2); sr <= Math.Min(height - 1, row + 2) && raw == 0; sr++)
                    for (var sc = Math.Max(0, column - 2); sc <= Math.Min(width - 1, column + 2); sc++)
                    {
                        var sat = sr * width + sc;
                        if (maskFrame.Opaque[sat]) { raw = maskFrame.Indices[sat]; break; }
                    }
                    if (raw == 0) raw = row < height / 2 ? (byte)128 : (byte)77;
                }

                var depth = raw switch
                {
                    179 => 191.51f + dx * (column - center) + dy * row + bias,
                    153 => 191.51f - dx * (column - center) + dy * row + bias,
                    230 => 194f + dx * Math.Abs(column - half) + dy * row + bias,
                    204 => 193f + dx * Math.Abs(column - (half - 1)) + dy * row + bias,
                    51 or 102 => 193.5f + dy * row + bias,
                    128 => 195.99f + dy * row + bias,
                    77 => 66.01f + dy * row + bias,
                    _ => 191.51f + dy * row + bias,
                };
                buffer[at] = (byte)Math.Clamp((int)MathF.Round(depth), 0, 254);
            }
            return buffer;
        });
    }

    private static int ResolveArchitectureDepthTexture(
        int configuration,
        int width,
        int height,
        List<Texture> textures,
        Dictionary<string, byte[]> files,
        Dictionary<(int Configuration, int Width, int Height), int> wallDepthTextures)
    {
        var key = (configuration, width, height);
        if (wallDepthTextures.TryGetValue(key, out var cached)) return cached;
        if (archDepthBytesCache.Count > 128) archDepthBytesCache.Clear();
        var depths = archDepthBytesCache.GetOrAdd(key, static k =>
        {
            var (cfg, w, h) = k;
            var config = WallDepthConfig[cfg];
            var buffer = new byte[w * h];
            for (var row = 0; row < h; row++)
            for (var column = 0; column < w; column++)
            {
                var sourceX = Math.Min((int)config[0] - 1, column * (int)config[0] / w);
                var sourceY = Math.Min((int)config[1] - 1, row * (int)config[1] / h);
                buffer[row * w + column] =
                    (byte)Math.Clamp(Math.Round(config[2] + config[3] * sourceX + config[4] * sourceY, MidpointRounding.AwayFromZero), 0, 254);
            }
            return buffer;
        });
        var name = $"wall-depth-{configuration}-{width}x{height}.depth8";
        files[name] = depths;
        var result = textures.Count;
        textures.Add(new Texture(name, width, height, "depth8"));
        wallDepthTextures[key] = result;
        return result;
    }
}
