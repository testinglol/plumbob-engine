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
    internal const int Size = 64;

    private static readonly ConcurrentDictionary<string, bool> speechBuffersCache = new(StringComparer.Ordinal);

    private static bool HasProductSpeechBuffers(string gameRoot) =>
        speechBuffersCache.GetOrAdd(gameRoot, LoadProductSpeechBuffers);

    private static bool LoadProductSpeechBuffers(string gameRoot)
    {
        var path = Path.Combine(gameRoot, "UIGraphics", "UIGraphics.far");
        if (!File.Exists(path)) return false;
        try
        {
            var archive = FarArchive.Open(path);
            var medium = archive.Find("Other/SpeechMedium.bmp");
            var large = archive.Find("Other/SpeechLarge.bmp");
            if (medium is null || large is null) return false;
            _ = BitmapCodec.Read(archive.Read(medium).ToArray());
            _ = BitmapCodec.Read(archive.Read(large).ToArray());
            return true;
        }
        catch (IOException)
        {
            return false;
        }
        catch (InvalidDataException)
        {
            return false;
        }
    }

    internal static object? PlacementGhost(string scenePath, short objectId, string? referenceScenePath = null)
        => PlacementGhost(scenePath, new HashSet<short> { objectId }, referenceScenePath);

    internal static object? PlacementGhost(string scenePath, IReadOnlySet<short> objectIds, string? referenceScenePath = null)
    {
        using var document = JsonDocument.Parse(SimsSimulation.InMemorySessionAssets.ReadAllBytes(scenePath));
        var source = document.RootElement;
        var sourceSprites = source.GetProperty("sprites").EnumerateArray()
            .Where(sprite => sprite.TryGetProperty("objectID", out var id) && objectIds.Contains(checked((short)id.GetInt32())))
            .OrderBy(sprite => sprite.TryGetProperty("depth", out var depth) ? depth.GetSingle() : 0)
            .ToArray();
        if (sourceSprites.Length == 0) return null;

        var requiredTextures = new SortedSet<int>();
        foreach (var sprite in sourceSprites)
        {
            AddTexture(sprite, "texture");
            AddTexture(sprite, "depthTexture");
            AddZoom(sprite, "near");
            AddZoom(sprite, "far");
        }
        var textureMap = requiredTextures.Select((texture, index) => (texture, index))
            .ToDictionary(pair => pair.texture, pair => pair.index);
        var sourceTextures = source.GetProperty("textures").EnumerateArray().ToArray();
        var textures = new JsonArray(requiredTextures.Select(index => JsonNode.Parse(sourceTextures[index].GetRawText())!).ToArray());
        var minX = sourceSprites.Min(sprite => sprite.GetProperty("x").GetSingle());
        var minY = sourceSprites.Min(sprite => sprite.GetProperty("y").GetSingle());
        var maxX = sourceSprites.Max(sprite => sprite.GetProperty("x").GetSingle() + sprite.GetProperty("width").GetSingle());
        var maxY = sourceSprites.Max(sprite => sprite.GetProperty("y").GetSingle() + sprite.GetProperty("height").GetSingle());
        var alignX = 0f;
        var alignY = 0f;
        if (referenceScenePath is not null && SimsSimulation.InMemorySessionAssets.FileExists(referenceScenePath))
        {
            using var reference = JsonDocument.Parse(SimsSimulation.InMemorySessionAssets.ReadAllBytes(referenceScenePath));
            if (source.GetProperty("terrainVertices").GetArrayLength() > 0 &&
                reference.RootElement.GetProperty("terrainVertices").GetArrayLength() > 0)
            {
                var currentOrigin = source.GetProperty("terrainVertices")[0];
                var referenceOrigin = reference.RootElement.GetProperty("terrainVertices")[0];
                alignX = referenceOrigin.GetProperty("x").GetSingle() - currentOrigin.GetProperty("x").GetSingle();
                alignY = referenceOrigin.GetProperty("y").GetSingle() - currentOrigin.GetProperty("y").GetSingle();
            }
        }
        var sprites = new JsonArray();
        foreach (var sourceSprite in sourceSprites)
        {
            var sprite = JsonNode.Parse(sourceSprite.GetRawText())!.AsObject();
            RemapTexture(sprite, "texture");
            RemapTexture(sprite, "depthTexture");
            RemapZoom(sprite, "near");
            RemapZoom(sprite, "far");
            sprite["x"] = sourceSprite.GetProperty("x").GetSingle() - minX;
            sprite["y"] = sourceSprite.GetProperty("y").GetSingle() - minY;
            sprites.Add(sprite);
        }
        var ghostScene = new JsonObject
        {
            ["schemaVersion"] = 1,
            ["house"] = 0,
            ["width"] = maxX - minX,
            ["height"] = maxY - minY,
            ["cameraOrientation"] = source.TryGetProperty("cameraOrientation", out var orientation) ? orientation.GetInt32() : 0,
            ["textures"] = textures,
            ["sprites"] = sprites,
            ["limitations"] = new JsonArray(),
        };
        return new JsonObject { ["x"] = minX + alignX, ["y"] = minY + alignY, ["scene"] = ghostScene };

        void AddTexture(JsonElement sprite, string field)
        {
            if (sprite.TryGetProperty(field, out var value) && value.ValueKind == JsonValueKind.Number)
                requiredTextures.Add(value.GetInt32());
        }
        void AddZoom(JsonElement sprite, string field)
        {
            if (!sprite.TryGetProperty(field, out var zoom) || zoom.ValueKind != JsonValueKind.Object) return;
            AddTexture(zoom, "texture");
            AddTexture(zoom, "depthTexture");
        }
        void RemapTexture(JsonObject sprite, string field)
        {
            if (sprite[field] is JsonValue value && value.TryGetValue<int>(out var index)) sprite[field] = textureMap[index];
        }
        void RemapZoom(JsonObject sprite, string field)
        {
            if (sprite[field] is not JsonObject zoom) return;
            RemapTexture(zoom, "texture");
            RemapTexture(zoom, "depthTexture");
        }
    }

    internal static object? WallPaintGhost(
        string scenePath,
        IReadOnlySet<(int X, int Y, int Level, int Direction)> changedWalls,
        string? referenceScenePath = null)
    {
        if (changedWalls.Count == 0) return null;
        using var document = JsonDocument.Parse(SimsSimulation.InMemorySessionAssets.ReadAllBytes(scenePath));
        var source = document.RootElement;
        var sourceSprites = source.GetProperty("sprites").EnumerateArray()
            .Where(sprite =>
                sprite.TryGetProperty("wall", out var wall) &&
                wall.ValueKind == JsonValueKind.Object &&
                changedWalls.Contains((
                    wall.GetProperty("x").GetInt32(),
                    wall.GetProperty("y").GetInt32(),
                    wall.GetProperty("level").GetInt32(),
                    wall.GetProperty("direction").GetInt32())))
            .ToArray();
        if (sourceSprites.Length == 0) return null;

        var requiredTextures = new SortedSet<int>();
        foreach (var sprite in sourceSprites)
        {
            AddTexture(sprite, "texture");
            AddTexture(sprite, "depthTexture");
            AddZoom(sprite, "near");
            AddZoom(sprite, "far");
        }
        var textureMap = requiredTextures.Select((texture, index) => (texture, index))
            .ToDictionary(pair => pair.texture, pair => pair.index);
        var sourceTextures = source.GetProperty("textures").EnumerateArray().ToArray();
        var textures = new JsonArray(requiredTextures.Select(index => JsonNode.Parse(sourceTextures[index].GetRawText())!).ToArray());
        var minX = sourceSprites.Min(sprite => sprite.GetProperty("x").GetSingle());
        var minY = sourceSprites.Min(sprite => sprite.GetProperty("y").GetSingle());
        var maxX = sourceSprites.Max(sprite => sprite.GetProperty("x").GetSingle() + sprite.GetProperty("width").GetSingle());
        var maxY = sourceSprites.Max(sprite => sprite.GetProperty("y").GetSingle() + sprite.GetProperty("height").GetSingle());
        var alignX = 0f;
        var alignY = 0f;
        if (referenceScenePath is not null && SimsSimulation.InMemorySessionAssets.FileExists(referenceScenePath))
        {
            using var reference = JsonDocument.Parse(SimsSimulation.InMemorySessionAssets.ReadAllBytes(referenceScenePath));
            if (source.GetProperty("terrainVertices").GetArrayLength() > 0 &&
                reference.RootElement.GetProperty("terrainVertices").GetArrayLength() > 0)
            {
                var currentOrigin = source.GetProperty("terrainVertices")[0];
                var referenceOrigin = reference.RootElement.GetProperty("terrainVertices")[0];
                alignX = referenceOrigin.GetProperty("x").GetSingle() - currentOrigin.GetProperty("x").GetSingle();
                alignY = referenceOrigin.GetProperty("y").GetSingle() - currentOrigin.GetProperty("y").GetSingle();
            }
        }
        var sprites = new JsonArray();
        foreach (var sourceSprite in sourceSprites)
        {
            var sprite = JsonNode.Parse(sourceSprite.GetRawText())!.AsObject();
            RemapTexture(sprite, "texture");
            RemapTexture(sprite, "depthTexture");
            RemapZoom(sprite, "near");
            RemapZoom(sprite, "far");
            sprite["x"] = sourceSprite.GetProperty("x").GetSingle() - minX;
            sprite["y"] = sourceSprite.GetProperty("y").GetSingle() - minY;
            sprites.Add(sprite);
        }
        var ghostScene = new JsonObject
        {
            ["schemaVersion"] = 1,
            ["house"] = 0,
            ["width"] = maxX - minX,
            ["height"] = maxY - minY,
            ["lotWidth"] = source.TryGetProperty("lotWidth", out var lw) ? lw.GetInt32() : Size,
            ["lotHeight"] = source.TryGetProperty("lotHeight", out var lh) ? lh.GetInt32() : Size,
            ["viewLevel"] = source.TryGetProperty("viewLevel", out var vl) ? vl.GetInt32() : 1,
            ["stories"] = source.TryGetProperty("stories", out var st) ? st.GetInt32() : 2,
            ["cameraOrientation"] = source.TryGetProperty("cameraOrientation", out var orientation) ? orientation.GetInt32() : 0,
            ["textures"] = textures,
            ["sprites"] = sprites,
            ["limitations"] = new JsonArray(),
        };
        return new JsonObject { ["x"] = minX + alignX, ["y"] = minY + alignY, ["scene"] = ghostScene };

        void AddTexture(JsonElement sprite, string field)
        {
            if (sprite.TryGetProperty(field, out var value) && value.ValueKind == JsonValueKind.Number)
                requiredTextures.Add(value.GetInt32());
        }
        void AddZoom(JsonElement sprite, string field)
        {
            if (!sprite.TryGetProperty(field, out var zoom) || zoom.ValueKind != JsonValueKind.Object) return;
            AddTexture(zoom, "texture");
            AddTexture(zoom, "depthTexture");
        }
        void RemapTexture(JsonObject sprite, string field)
        {
            if (sprite[field] is JsonValue value && value.TryGetValue<int>(out var index)) sprite[field] = textureMap[index];
        }
        void RemapZoom(JsonObject sprite, string field)
        {
            if (sprite[field] is not JsonObject zoom) return;
            RemapTexture(zoom, "texture");
            RemapTexture(zoom, "depthTexture");
        }
    }

    private static readonly JsonSerializerOptions Json = new() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };

    internal readonly record struct Vertex(float X, float Y, float Z, float U, float V, float Nx, float Ny, float Nz);
    internal sealed record Texture(string File, int Width, int Height, string Encoding);
    internal sealed record WallSide(int X, int Y, int Level, int Direction, int Cut = 0, int? Edge = null, int? Side = null);
    internal sealed record WallDepth(int X, int Y, int Level, int Configuration);
    internal sealed record WallJunction(int X, int Y, int Level, int Flags, int Frame, bool Down);
    internal sealed record WaterSurface(int Adjacency, ushort Sprite, ushort[] Corners);
    internal sealed record FloorSurface(int X, int Y, ushort Pattern, int Half, int Level = 1, WaterSurface? Water = null);
    internal sealed record ZoomImage(int Texture, float X, float Y, float Width, float Height,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? DepthTexture = null);
    internal sealed record RoofSurface(string Part, uint Style, float Pitch, string File);
    internal sealed record Mesh(int Texture, int ObjectID, float Depth, Vertex[] Vertices, int Level,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? Room = null,
        bool Unlit = false,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] FloorSurface? Floor = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? NearTexture = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? FarTexture = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? Layer = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] RoofSurface? Roof = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? Shadow = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? ShadowBrightness = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] ZoomImage? FloorShadow = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] ZoomImage? FloorShadowNear = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] ZoomImage? FloorShadowFar = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] float[]? Tint = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] bool? Indicator = null);
    internal readonly record struct TerrainVertex(float X, float Y, int R, int G, int B, int Dr, int Dg, int Db, int Grass);
    internal sealed record WallStyleArt(IffFile? File, ushort SpriteBase, ushort BaseStyle)
    {
        public static WallStyleArt Base(ushort style) => new(null, 0, style);
    }

    internal sealed record CensorRect(float X, float Y, float Width, float Height, float Depth);
    internal sealed record SceneSprite(int Texture, float X, float Y, int Width, int Height, bool Flip, short ObjectID, float Depth, int Layer,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? DepthTexture = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] float? DepthNear = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] float? DepthFar = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] WallSide? Wall = null,
        int Level = 1,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? Room = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] WallJunction? Junction = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] WallDepth? ArchitectureDepth = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] ZoomImage? Near = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] ZoomImage? Far = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? Shadow = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] int? ShadowBrightness = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] ZoomImage? FloorShadow = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] ZoomImage? FloorShadowNear = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] ZoomImage? FloorShadowFar = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)] bool? HideAtFarZoom = null);

    internal sealed record SoundSourceRecord(short ObjectID, int Level, float X, float Y, float Z);

    internal sealed record OverheadMapRecord(int Width, int Height, int SamplesPerTile, byte[] Pixels);

    internal sealed record OverheadFeedbackRecord(
        [property: JsonPropertyName("objectID")] short ObjectID,
        string Kind,
        string Text,
        uint BackgroundRgb,
        uint ForegroundRgb,
        int Delta,
        float X,
        float Y,
        int Level,
        int StackIndex,
        int RemainingTicks);

    internal sealed record SkillMeterRecord(
        [property: JsonPropertyName("objectID")] short ObjectID,
        int SpriteId,
        int ProgressTenths,
        float X,
        float Y,
        int Level);

    internal sealed record ShelterCacheEntry(
        IffFile Lot,
        ulong Fingerprint,
        int StoriesCount,
        ushort[][] Floors,
        LotArray?[] Walls,
        RoofGrid?[] Roofs,
        RoomMap?[] Rooms,
        HashSet<ushort>?[] RoofableRooms)
    {
        public OverheadMapRecord? CachedOverheadMap;
        public int CachedOverheadLotSize;
        public float CachedOverheadBaseHeight;
    }

    private static readonly bool ProfileEnabled = Environment.GetEnvironmentVariable("SIMS_PROFILE") is not null;

    private static readonly ConditionalWeakTable<IffFile, ShelterCacheEntry> cachedShelters = new();
    private static readonly ushort[] ShelterArrayIds = [0, 1, 2, 11, 12, 101, 102, 111, 112];
    private static readonly ResourceType ArryType = ResourceType.Parse("Arry");
    private static readonly ResourceType RoofType = ResourceType.Parse("ROOF");
    private static readonly ResourceType FlrmType = ResourceType.Parse("FLRm");
    private static readonly ResourceType WalmType = ResourceType.Parse("WALm");
    private static readonly (float Dx, float Dy)[] EaveOffsets =
    [
        (0.45f, 0f), (-0.45f, 0f), (0f, 0.45f), (0f, -0.45f),
        (0.32f, 0.32f), (-0.32f, 0.32f), (0.32f, -0.32f), (-0.32f, -0.32f),
    ];

    private static ulong ArchitectureFingerprint(IffFile lot, SimulationWorld world)
    {
        var hash = 14695981039346656037UL;
        void Mix(ulong value)
        {
            hash ^= value;
            hash *= 1099511628211UL;
        }
        void MixSpan(ReadOnlySpan<byte> span)
        {
            Mix((ulong)span.Length);
            var i = 0;
            for (; i + 8 <= span.Length; i += 8) Mix(BitConverter.ToUInt64(span.Slice(i, 8)));
            for (; i < span.Length; i++) Mix(span[i]);
        }

        foreach (var id in ShelterArrayIds)
        {
            Mix(id);
            if (lot.Find(ArryType, id) is { } chunk) MixSpan(chunk.Data.Span);
            else Mix(0);
        }
        foreach (var chunk in lot.Chunks)
        {
            if (chunk.Type != RoofType) continue;
            Mix(chunk.Id);
            MixSpan(chunk.Data.Span);
        }
        Mix(BitConverter.SingleToUInt32Bits(LotRoof.Read(lot).Pitch));
        List<(int X, int Y)>? stairTiles = null;
        foreach (var item in world.WalkOrder)
        {
            var height = item.Position.Height;
            if (height is not (1 or 2)) continue;
            var tx = item.Position.X >> 4;
            var ty = item.Position.Y >> 4;
            if (tx < 0 || ty < 0) continue;
            if (item.Data[(int)ObjectData.Hidden] == 0 &&
                item.RoomWord84 >= 0 &&
                item.Data[(int)ObjectData.Category] == 8)
            {
                Mix(1);
                Mix((ulong)(uint)height);
                Mix((ulong)(uint)tx);
                Mix((ulong)(uint)ty);
            }
            if (height == 1 && item.TypeRecord?.AutonomyAlternativeTypeFlag == 3)
            {
                stairTiles ??= [];
                stairTiles.Add((tx, ty));
                Mix(2);
                Mix((ulong)(uint)tx);
                Mix((ulong)(uint)ty);
            }
        }
        if (stairTiles is not null)
        {
            foreach (var (sx, sy) in stairTiles)
            {
                var upperBlocked = false;
                foreach (var item in world.WalkOrder)
                {
                    if (item is XPerson || item.Position.Height != 2) continue;
                    if ((item.Position.X >> 4) == sx && (item.Position.Y >> 4) == sy)
                    {
                        upperBlocked = true;
                        break;
                    }
                }
                Mix(upperBlocked ? 3UL : 4UL);
            }
        }
        return hash;
    }

    private static ShelterCacheEntry GetShelterCache(IffFile lot, SimulationWorld world)
    {
        var fingerprint = ArchitectureFingerprint(lot, world);
        if (cachedShelters.TryGetValue(lot, out var entry) && entry.Fingerprint == fingerprint)
            return entry;
        lock (lot)
        {
            if (cachedShelters.TryGetValue(lot, out entry) && entry.Fingerprint == fingerprint)
                return entry;

            var stories = Stories(lot);
            var floors = new ushort[stories + 1][];
            var walls = new LotArray?[stories + 1];
            for (var level = 1; level <= stories; level++)
            {
                floors[level] = ReadFloors(lot, level);
                walls[level] = ReadWalls(lot, level);
            }
            var maxRoofLevel = Math.Min(stories, 2);
            var roofs = new RoofGrid?[maxRoofLevel + 1];
            var rooms = new RoomMap?[maxRoofLevel + 1];
            var roofableRooms = new HashSet<ushort>?[maxRoofLevel + 1];
            var terrain = ReadArray(lot, 0) is { Rows: Size, Width: Size, ElementSize: 4 }
                ? LotTerrain.Read(lot)
                : null;
            if (terrain is not null)
            {
                var items = world.WalkOrder.ToArray();
                RoofGrid? upper = null;
                for (var buildLevel = maxRoofLevel; buildLevel >= 1; buildLevel--)
                {
                    var grid = LotRoofGrid.Build(lot, buildLevel, items, upper);
                    roofs[buildLevel] = grid;
                    upper = grid;

                    var levelRooms = RoomMap.Build(lot, buildLevel, Size, Size);
                    rooms[buildLevel] = levelRooms;
                    var localObjects = items.Where(item => item.Position.Height == buildLevel)
                        .ToLookup(item => (X: item.Position.X >> 4, Y: item.Position.Y >> 4));
                    var roofable = new HashSet<ushort>();
                    foreach (var roomId in levelRooms.RoomIds)
                    {
                        var tiles = levelRooms.TilesInRoom(roomId).ToArray();
                        var flat = tiles.All(tile => terrain.IsFlatAt(tile.X, tile.Y, terrain.ReferenceHeight(tile.X, tile.Y)));
                        var roomOverride = (roomId & 0x3ff) != 0 && tiles.Any(tile => localObjects[tile].Any(item =>
                            item.Data[(int)ObjectData.Hidden] == 0 && item.RoomWord84 >= 0 &&
                            item.Data[(int)ObjectData.Category] == 8));
                        if (flat && (roomOverride || !levelRooms.IsOutside(roomId)))
                            roofable.Add(roomId);
                    }
                    roofableRooms[buildLevel] = roofable;
                }
            }
            entry = new ShelterCacheEntry(lot, fingerprint, stories, floors, walls, roofs, rooms, roofableRooms);
            cachedShelters.AddOrUpdate(lot, entry);
            return entry;
        }
    }

    internal readonly struct ShelterQuery
    {
        private readonly ShelterCacheEntry? cache;
        private readonly int lotSize;

        internal ShelterQuery(ShelterCacheEntry? cache, int lotSize)
        {
            this.cache = cache;
            this.lotSize = lotSize;
        }

        public bool IsSheltered(ObjectPosition position)
        {
            if (cache is null || position.Height < 1 || position.X < 0 || position.Y < 0) return false;
            var tileX = position.X >> 4;
            var tileY = position.Y >> 4;
            if (tileX < 0 || tileY < 0 || tileX >= lotSize || tileY >= lotSize) return false;
            return IsCoveredSubtile(cache, position.Height, tileX, tileY, (position.X & 15) / 16f, (position.Y & 15) / 16f);
        }
    }

    internal static ShelterQuery CaptureShelterQuery(IffFile? lot, SimulationWorld world, int lotSize) =>
        lot is null ? default : new ShelterQuery(GetShelterCache(lot, world), lotSize);

    internal static bool IsShelteredAt(IffFile? lot, SimulationWorld world, int lotSize, ObjectPosition position)
    {
        if (lot is null || position.Height < 1 || position.X < 0 || position.Y < 0) return false;
        var tileX = position.X >> 4;
        var tileY = position.Y >> 4;
        if (tileX < 0 || tileY < 0 || tileX >= lotSize || tileY >= lotSize) return false;
        var cache = GetShelterCache(lot, world);
        var fx = (position.X & 15) / 16f;
        var fy = (position.Y & 15) / 16f;
        return IsCoveredSubtile(cache, position.Height, tileX, tileY, fx, fy);
    }

    private static bool IsDirectRoofedAt(ShelterCacheEntry cache, int rLevel, float worldTileX, float worldTileY)
    {
        if (rLevel < 1 || rLevel >= cache.Roofs.Length) return false;
        if (worldTileX < 0f || worldTileY < 0f || worldTileX >= Size || worldTileY >= Size) return false;
        if (cache.Roofs[rLevel] is not { } grid || cache.Rooms[rLevel] is not { } rooms || cache.RoofableRooms[rLevel] is not { } roofable)
            return false;
        var wx = Math.Clamp((int)MathF.Floor(worldTileX * 16f), 0, Size * 16 - 1);
        var wy = Math.Clamp((int)MathF.Floor(worldTileY * 16f), 0, Size * 16 - 1);
        var room = rooms.RoomAtPosition(wx, wy);
        if (room == RoomMap.NoRoom || !roofable.Contains(room)) return false;
        var row = Math.Clamp((int)MathF.Floor(worldTileY * 2f), 0, grid.Size - 1);
        var col = Math.Clamp((int)MathF.Floor(worldTileX * 2f), 0, grid.Size - 1);
        return grid.Has(row, col);
    }

    private static bool IsCoveredSubtile(ShelterCacheEntry cache, int level, int tx, int ty, float fx, float fy)
    {
        for (var upper = level + 1; upper <= cache.StoriesCount; upper++)
        {
            if (HasUpperFloorAt(cache.Floors[upper], cache.Walls[upper], tx, ty, fx, fy)) return true;
        }
        var maxRoofLevel = Math.Min(cache.StoriesCount, 2);
        var worldX = tx + fx;
        var worldY = ty + fy;
        for (var rLevel = Math.Max(level, 1); rLevel <= maxRoofLevel; rLevel++)
        {
            if (IsDirectRoofedAt(cache, rLevel, worldX, worldY)) return true;
        }
        if (level >= 1 && level <= cache.StoriesCount &&
            HasPavedNonRoadFloorAt(cache.Floors[level], cache.Walls[level], tx, ty, fx, fy))
        {
            for (var rLevel = level; rLevel <= maxRoofLevel; rLevel++)
            {
                foreach (var (dx, dy) in EaveOffsets)
                {
                    if (IsDirectRoofedAt(cache, rLevel, worldX + dx, worldY + dy)) return true;
                }
            }
        }
        return false;
    }

    private static ushort FloorPatternAt(ushort[] floors, LotArray? walls, int tx, int ty, float fx, float fy)
    {
        if (floors.Length == 0 || tx < 0 || ty < 0 || tx >= Size || ty >= Size) return 0;
        var diag = walls is not null && tx < walls.Rows && ty < walls.Width ? walls.Element(tx, ty)[0] & 0x30 : 0;
        if (diag == 0x20)
        {
            var tile = walls!.Element(tx, ty);
            var basePattern = floors[tx * Size + ty] == byte.MaxValue ? (ushort)0 : floors[tx * Size + ty];
            var diagA = WallStyle0(tile);
            var diagB = WallPattern(tile, 4);
            return diagA == 0 && diagB == 0 ? basePattern : (fx > fy ? diagB : diagA);
        }
        if (diag == 0x10)
        {
            var tile = walls!.Element(tx, ty);
            var basePattern = floors[tx * Size + ty] == byte.MaxValue ? (ushort)0 : floors[tx * Size + ty];
            var diagA = WallStyle0(tile);
            var diagB = WallPattern(tile, 4);
            return diagA == 0 && diagB == 0 ? basePattern : (fx + fy < 1f ? diagA : diagB);
        }
        return floors[tx * Size + ty];
    }

    private static bool HasUpperFloorAt(ushort[] floors, LotArray? walls, int tx, int ty, float fx, float fy)
    {
        var pattern = FloorPatternAt(floors, walls, tx, ty, fx, fy);
        return pattern is > 0 and < 65534 && pattern != byte.MaxValue;
    }

    private static bool HasPavedNonRoadFloorAt(ushort[] floors, LotArray? walls, int tx, int ty, float fx, float fy)
    {
        var pattern = FloorPatternAt(floors, walls, tx, ty, fx, fy);
        return pattern is > 0 and < 65534 && pattern != byte.MaxValue && pattern is < 9 or > 11;
    }

    internal sealed record ExportedLotScene(
        short House,
        float Width,
        float Height,
        int LotSize,
        int[] FloorDiagonals,
        short[] TerrainHeights,
        int CameraOrientation,
        float OriginX,
        float OriginY,
        string WallMode,
        bool RoofsVisible,
        int ViewLevel,
        int Stories,
        SceneLighting.State? Lighting,
        Texture[] Textures,
        SceneSprite[] Sprites,
        SoundSourceRecord[] SoundSources,
        TerrainVertex[] Terrain,
        float PlacementLift,
        Mesh[] Meshes,
        CensorRect[] CensorRects,
        string[] Limitations,
        string[] MissingResources,
        OverheadMapRecord? OverheadMap = null,
        OverheadFeedbackRecord[]? OverheadFeedback = null,
        SkillMeterRecord[]? SkillMeters = null,
        OverheadMapRecord? VoxelMap = null);

    internal sealed record DirectAnimationMesh(
        int Texture,
        int ObjectID,
        float Depth,
        int Level,
        int? Room,
        ZoomImage? FloorShadow,
        ZoomImage? FloorShadowNear,
        ZoomImage? FloorShadowFar,
        Vertex[] Vertices,
        float ShiftX,
        float ShiftY,
        float[]? Tint = null,
        bool? Indicator = null);

    internal sealed record DirectAnimationFrame(
        long BaseRevision,
        long Sequence,
        long Updates,
        int TextureStart,
        SceneLighting.State? Lighting,
        Texture[] Textures,
        SceneSprite[] Sprites,
        DirectAnimationMesh[] Meshes,
        CensorRect[] CensorRects,
        OverheadFeedbackRecord[]? OverheadFeedback = null,
        SkillMeterRecord[]? SkillMeters = null);
    private static readonly (int X, int Y, int Width, int Height)[] WallRectangles = [(2, 39, 32, 136), (34, 39, 32, 136), (2, 55, 64, 120), (30, 73, 8, 116)];
    private static readonly (int X, int Y, int Width, int Height)[] NearWallRectangles = [(4, 77, 64, 271), (68, 77, 64, 271), (4, 109, 128, 240), (60, 145, 16, 232)];
    private static readonly (int X, int Y, int Width, int Height)[] FarWallRectangles = [(1, 20, 16, 68), (17, 20, 16, 68), (1, 28, 32, 60), (15, 37, 4, 58)];
    private static readonly (int X, int Y) JunctionOrigin = (2, 159);
    private const float FlatDepthIncrement = 1.525f;
    // Depth ramp table [width, height, baseDepth, dx, dy] for wall/floor/junction z-buffers across zoom levels.
    private static readonly float[][] WallDepthConfig =
    [
        [64, 271, 74, 1, 0.5f], [64, 271, 136, -1, 0.5f], [128, 240, 89.5f, 0, 0.5f], [16, 232, 50, 0, 0.5f],
        [32, 135, 74, 2, 1f], [32, 135, 135, -2, 1f], [64, 120, 89.5f, 0, 1f], [8, 116, 50, 0, 1f],
        [16, 67, 74, 4, 2f], [16, 67, 135, -4, 2f], [32, 60, 89.5f, 0, 2f], [4, 58, 50, 0, 2f],
        [128, 64, 255, 0, -FlatDepthIncrement], [64, 32, 255, 0, -FlatDepthIncrement * 2], [32, 16, 255, 0, -FlatDepthIncrement * 4],
        [128, 64, 153, 0, FlatDepthIncrement], [64, 32, 153, 0, FlatDepthIncrement * 2], [32, 16, 153, 0, FlatDepthIncrement * 4],
        [128, 64, 235, 0, -FlatDepthIncrement], [64, 32, 235, 0, -FlatDepthIncrement * 2], [32, 16, 235, 0, -FlatDepthIncrement * 4],
    ];

    // Maps an 8-bit camera-rotated wall junction mask to a 1-based SPR# frame index, where 0 or 255
    // indicates no junction.
    internal static ReadOnlySpan<byte> JunctionFrames =>
    [
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        16, 255, 255, 255, 17, 255, 255, 255, 18, 255, 255, 255, 19, 255, 255, 255,
        20, 21, 255, 255, 255, 255, 255, 255, 22, 23, 255, 255, 255, 255, 255, 255,
        24, 255, 255, 255, 255, 255, 255, 255, 25, 255, 255, 255, 255, 255, 255, 255,
        26, 27, 28, 29, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        30, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        31, 32, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        33, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        34, 255, 35, 255, 36, 255, 37, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        38, 255, 255, 255, 39, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        40, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        41, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        42, 255, 43, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        44, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        45, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
        46, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255
    ];

    internal static ushort SelectedGraphic(ushort baseGraphic, short graphicOffset) =>
        unchecked((ushort)(baseGraphic + graphicOffset));

    internal static int FacingFlag(int direction) => 1 << (direction & 7);

    internal static DrawGroupImage? SelectedImage(DrawGroup group, int direction, int cameraOrientation, int zoom = 2)
    {
        var rotatedDirection = (uint)FacingFlag(direction) << (cameraOrientation * 2);
        var wanted = (rotatedDirection & 0xff) | (rotatedDirection >> 8);
        var images = group.Images;
        for (var i = 0; i < images.Count; i++)
        {
            var image = images[i];
            if (image.Direction == wanted && image.Zoom == zoom) return image;
        }
        return null;
    }

    internal static bool FrameHasPixels(int width, int height) => width > 0 && height > 0;

    internal static bool HasFloorArtwork(ushort pattern) =>
        pattern is not (0 or 0xff);

    internal static ushort WallMaskId(ushort wallStyle, bool down, int zoom = 1)
    {
        var style = wallStyle is >= 1 and <= 21 ? wallStyle : (ushort)1;
        var origin = zoom switch { 0 => 2, 2 => 1026, _ => 514 };
        return (ushort)(origin + (style - 1) * 2 + (down ? 1 : 0));
    }

    // Styles 2, 12, 13, and 14 are walls.iff opening cutouts; all other stored styles fall back to 1.
    internal static ushort NormalizedWallStyle(ushort style) => style is 1 or 2 or 12 or 13 or 14 ? style : (ushort)1;

    internal static (int Slot, int Side) DiagonalFacingSlotAndSide(int sourceDiag, int cameraOrientation)
    {
        var orientation = ((cameraOrientation % 4) + 4) % 4;
        var useSlot6 = sourceDiag == 0x10
            ? orientation is 1 or 2
            : orientation is 2 or 3;
        return (useSlot6 ? 6 : 7, useSlot6 ? (sourceDiag == 0x10 ? 2 : 1) : (sourceDiag == 0x10 ? 4 : 3));
    }

    internal static bool ShouldEmitWallJunction(int wallLevel, int viewLevel, string wallMode) =>
        wallLevel < viewLevel || wallMode == "up";

    internal static WallStyleArt ResolveWallStyle(ushort style, WallStyleArt? objectStyle) =>
        style == 1 && objectStyle is not null ? objectStyle : WallStyleArt.Base(style);

    internal static ushort ResolveWallMaskId(WallStyleArt styleArt, bool down, int zoom = 1) =>
        styleArt.File is not null
            ? (ushort)(styleArt.SpriteBase + (down ? 3 : 0) + (zoom switch { 0 => 0, 2 => 2, _ => 1 }))
            : WallMaskId(styleArt.BaseStyle, down, zoom);

    internal static void PopulateTileJunctionFlags(
        int[] junctions,
        int lotSize,
        int x,
        int y,
        byte segments,
        byte styleSide0,
        byte styleSide1,
        byte? diagonalStyle = null,
        int stride = Size,
        bool[]? cutawayMask = null)
    {
        if (segments == 0) return;
        var diagStyle = diagonalStyle ?? styleSide1;
        var s = stride > 0 ? stride : (junctions.Length >= lotSize * lotSize ? lotSize : Size);

        bool CutawayEdge(int otherX, int otherY) =>
            cutawayMask is not null &&
            x >= 0 && y >= 0 && x < lotSize && y < lotSize &&
            otherX >= 0 && otherY >= 0 && otherX < lotSize && otherY < lotSize &&
            cutawayMask[y * lotSize + x] && cutawayMask[otherY * lotSize + otherX];

        bool Thick(int bit, byte rawStyle, int otherX, int otherY)
        {
            if ((segments & bit) == 0) return false;
            if (CutawayEdge(otherX, otherY)) return false;
            var style = rawStyle is 2 or 12 or 13 or 14 ? rawStyle : (byte)1;
            return style == 1;
        }

        if (Thick(1, styleSide0, x - 1, y))
        {
            junctions[y * s + x] |= 4;
            if (y + 1 < lotSize) junctions[(y + 1) * s + x] |= 1;
        }
        if (Thick(2, styleSide1, x, y - 1))
        {
            junctions[y * s + x] |= 8;
            if (x + 1 < lotSize) junctions[y * s + x + 1] |= 2;
        }
        var diagThick = diagStyle is not (2 or 12 or 13 or 14) &&
                        (cutawayMask is null || !cutawayMask[y * lotSize + x]);
        if ((segments & 0x30) == 0x20 && diagThick)
        {
            // walls.iff junction masks map bits 0x10..0x80 to diagonal arms (0x40 downward, 0x10 upward).
            junctions[y * s + x] |= 64;
            if (x + 1 < lotSize && y + 1 < lotSize) junctions[(y + 1) * s + x + 1] |= 16;
        }
        else if ((segments & 0x30) == 0x10 && diagThick)
        {
            if (x + 1 < lotSize) junctions[y * s + x + 1] |= 32;
            if (y + 1 < lotSize) junctions[(y + 1) * s + x] |= 128;
        }
    }

    internal static ushort WallPatternId(ushort pattern, int zoom) =>
        (ushort)((zoom switch { 0 => 1536, 2 => 2048, _ => 1792 }) + pattern);

    internal static int WallPaletteId(int paletteId) =>
        paletteId is >= 0 and <= ushort.MaxValue ? paletteId : 0;

    internal static int RuntimeSlotSpriteFrame(int scale, int animationFrame) => 3 - scale + animationFrame * 3;

    internal static int RuntimeSlotOverlayFrame(int scale) => 3 - scale;

    internal static (int X, int Y) RuntimeSlotSpeechImagePosition(float renderX, float renderY, float slotZ,
        int width, int height, int scale = 2)
    {
        var slotX = renderX - (8 << scale) / 2f;
        var slotY = renderY + (4 << scale) - slotZ * (1 << (scale + 1));
        var imageOffsetX = scale == 2 ? 0x20 / 2 : 0x20;
        var imageOffsetY = scale == 2 ? -36 / 2 : -36;
        return ((int)(slotX + imageOffsetX - width / 2f), (int)(slotY + imageOffsetY - height / 2f));
    }

    internal static (int X, int Y) RuntimeSlotSpritePosition(float renderX, float renderY, float slotZ,
        int height, short boundsLeft = 0, short boundsTop = 0, int scale = 2) =>
        ((int)(renderX - (8 << scale) / 2f + boundsLeft),
            (int)(renderY + (4 << scale) - slotZ * (1 << (scale + 1)) - height + boundsTop));

    // Sims 1 keys speech BMPs in RGB565 from top-left pixel; person portraits restrict corner-keying to magenta or white.
    internal static void KeySpeechBitmapTransparency(int width, int height, byte[] rgba, bool isPerson = false)
    {
        if (width <= 0 || height <= 0 || rgba.Length < 4) return;
        var keyR = rgba[0] >> 3;
        var keyG = rgba[1] >> 2;
        var keyB = rgba[2] >> 3;
        var useCornerKey = !isPerson || (keyR == 31 && keyB == 31 && (keyG == 0 || keyG == 63));
        for (var at = 0; at + 3 < rgba.Length; at += 4)
        {
            var r5 = rgba[at] >> 3;
            var g6 = rgba[at + 1] >> 2;
            var b5 = rgba[at + 2] >> 3;
            var isKey = (useCornerKey && r5 == keyR && g6 == keyG && b5 == keyB)
                || (r5 == 31 && g6 == 0 && b5 == 31)
                || (isPerson && r5 == 31 && g6 == 63 && b5 == 31);
            if (isKey)
            {
                rgba[at] = 0;
                rgba[at + 1] = 0;
                rgba[at + 2] = 0;
                rgba[at + 3] = 0;
            }
        }
    }

    internal static int? ShadowId(ObjectEntry entry, IReadOnlyDictionary<(IffFile File, ushort MasterId, ushort SubIndex), ObjectEntry> parts)
    {
        var definition = entry.Definition;
        var shadow = definition[ObjdField.Shadow];
        if (shadow == ushort.MaxValue) return null;
        var masterId = definition[ObjdField.MasterId];
        if (masterId == 0) return shadow;

        // SubIndex packs the signed tile X offset in the high byte and unsigned Y offset in the low byte.
        var subIndex = definition[ObjdField.SubIndex];
        var originX = unchecked((sbyte)(subIndex >> 8));
        var originY = (byte)subIndex;
        ReadOnlySpan<(sbyte X, sbyte Y)> neighbours =
        [
            (0, -1), (-1, 0), (0, 1), (1, 0),
            (-1, -1), (-1, 1), (1, 1), (1, -1),
        ];
        var mask = 0;
        for (var bit = 0; bit < neighbours.Length; bit++)
        {
            var x = unchecked((byte)(originX + neighbours[bit].X));
            var y = unchecked((byte)(originY + neighbours[bit].Y));
            var target = (ushort)((x << 8) | y);
            parts.TryGetValue((entry.File, masterId, target), out var part);
            if (part is not null && part.Definition[ObjdField.Shadow] != ushort.MaxValue)
                mask |= 1 << bit;
        }

        return ShadowMaskIsValid(mask) ? mask : 0;
    }

    private static readonly bool[] validShadowMasks = BuildValidShadowMasks();

    private static bool[] BuildValidShadowMasks()
    {
        var valid = new bool[256];
        for (var mask = 0; mask < valid.Length; mask++)
        {
            var corners = ShadowLookupValues(mask);
            valid[mask] = corners[0] is not (2 or 4 or 6) &&
                          corners[1] is not (2 or 4 or 6) &&
                          corners[2] is not (2 or 4 or 6) &&
                          corners[3] is not (2 or 4 or 6);
        }
        return valid;
    }

    internal static bool ShadowMaskIsValid(int mask)
    {
        if ((uint)mask < (uint)validShadowMasks.Length) return validShadowMasks[mask];
        var corners = ShadowLookupValues(mask);
        return !corners.Any(corner => corner is 2 or 4 or 6);
    }

    // Packs cardinal bit + flanking diagonal bits (weights 1, 2, 4) into 0..7 floor-shadow edge curve indices.
    internal static int[] ShadowLookupValues(int mask) =>
    [
        (mask & 1) + 2 * ((mask >> 7) & 1) + 4 * ((mask >> 4) & 1),
        ((mask >> 1) & 1) + 2 * ((mask >> 5) & 1) + 4 * ((mask >> 4) & 1),
        ((mask >> 2) & 1) + 2 * ((mask >> 6) & 1) + 4 * ((mask >> 5) & 1),
        ((mask >> 3) & 1) + 2 * ((mask >> 6) & 1) + 4 * ((mask >> 7) & 1),
    ];

    // Shadow ID 16 is Sims 1's unrotated single-tile shadow; multi-tile masks rotate cardinal and diagonal nibbles.
    internal static int RotateShadowId(int shadowId, int quarterTurns)
    {
        var turns = ((quarterTurns % 4) + 4) % 4;
        if (turns == 0 || shadowId == 16) return shadowId & 0xff;
        var cardinal = shadowId & 0x0f;
        var diagonal = (shadowId >> 4) & 0x0f;
        for (var step = 0; step < turns; step++)
        {
            cardinal = ((cardinal >> 1) | ((cardinal & 1) << 3)) & 0x0f;
            diagonal = ((diagonal >> 1) | ((diagonal & 1) << 3)) & 0x0f;
        }
        return cardinal | (diagonal << 4);
    }

    internal static float ShadowLookup(int type, float value) => type switch
    {
        0 => 0f,
        1 => MathF.Pow(MathF.Max(0f, MathF.Sin(value * MathF.PI)), 0.6f),
        3 => MathF.Pow(MathF.Max(0f, MathF.Sin(value * MathF.PI * 0.5f)), 0.6f),
        5 => MathF.Pow(MathF.Max(0f, MathF.Sin((1f - value) * MathF.PI * 0.5f)), 0.6f),
        7 => 1f,
        _ => 0f,
    };

    internal static float EvaluateFloorShadowShade(ReadOnlySpan<int> lookupTypes, float u, float v) =>
        0.5f * ((1f - v) * ShadowLookup(lookupTypes[0], u)
            + (1f - u) * ShadowLookup(lookupTypes[1], v)
            + v * ShadowLookup(lookupTypes[2], u)
            + u * ShadowLookup(lookupTypes[3], v));

    internal static IEnumerable<(int X, int Y)> CutawayRectangle(LotCamera camera, int sourceX, int sourceY, int lotSize)
    {
        var origin = camera.CameraPoint(sourceX + 0.5f, sourceY + 0.5f);
        var cameraX = (int)MathF.Floor(origin.X);
        var cameraY = (int)MathF.Floor(origin.Y);
        var extent = 4;
        while (extent > 0 && (cameraX + extent >= lotSize || cameraY + extent >= lotSize)) extent--;
        for (var y = 0; y <= extent; y++)
        for (var x = 0; x <= extent; x++)
        {
            var tile = camera.SourceTile(cameraX + x, cameraY + y);
            if (tile.X >= 0 && tile.Y >= 0 && tile.X < lotSize && tile.Y < lotSize) yield return tile;
        }
    }

    internal static int CutawayStoryPixels(int zoom) => 58 << (Math.Clamp(zoom, 1, 3) - 1);
}
