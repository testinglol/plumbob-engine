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

    internal static bool[] CutawayMatrix(RoomMap rooms, LotCamera camera, int lotSize, IEnumerable<ushort> selectedRooms,
        IEnumerable<(int X, int Y)> extraTiles, int zoom = 2, Func<int, int, float>? altitudePixels = null)
    {
        zoom = Math.Clamp(zoom, 1, 3);
        var mask = new bool[lotSize * lotSize];
        var selected = new HashSet<ushort>(selectedRooms);
        foreach (var (x, y) in extraTiles) if (x >= 0 && y >= 0 && x < lotSize && y < lotSize) mask[y * lotSize + x] = true;
        if (selected.Count == 0) return mask;
        int unit = 8 << zoom, half = unit / 2, story = CutawayStoryPixels(zoom), boxX = unit - 2;
        var altitudeScale = MathF.Pow(2, zoom - 2);
        float Altitude(int sx, int sy) => altitudePixels is null ? 0 : altitudePixels(sx, sy) * altitudeScale;
        bool InLot(int cameraX, int cameraY) => cameraX >= 1 && cameraY >= 1 && cameraX <= lotSize - 2 && cameraY <= lotSize - 2;
        for (var y = 0; y < lotSize && y < rooms.Height; y++)
        for (var x = 0; x < lotSize && x < rooms.Width; x++)
        {
            var room = rooms.RoomAt(x, y);
            if (selected.Contains(room) && !rooms.IsOutside(room)) Walk(x, y, 0, 0);
            else if (room == RoomMap.NoRoom && rooms.AdjacentRoomsAtTile(x, y) is { } pair)
            {
                var diagonal = rooms.HasRoomDividingDiagonal(x, y);
                if (!diagonal) continue;
                var vertical = (rooms.DiagonalKind(x, y) & 0x20) != 0;
                var points = vertical ? new[] { (14, 1), (1, 14) } : new[] { (1, 1), (14, 14) };
                var rooms2 = new[] { pair.First, pair.Second };
                var centre = camera.CameraPoint(x + 0.5f, y + 0.5f);
                for (var i = 0; i < 2; i++)
                {
                    if (!selected.Contains(rooms2[i]) || rooms.IsOutside(rooms2[i])) continue;
                    var p = camera.CameraPoint(x + points[i].Item1 / 16f, y + points[i].Item2 / 16f);
                    var left = (p.X - p.Y) < (centre.X - centre.Y);
                    Walk(x, y, left ? 0 : 1, left ? 1 : 0);
                }
            }
        }

        void Walk(int x, int y, int raiseMin, int cutMax)
        {
            mask[y * lotSize + x] = true;
            var origin = camera.CameraPoint(x + 0.5f, y + 0.5f);
            int originX = (int)MathF.Floor(origin.X), originY = (int)MathF.Floor(origin.Y);
            var originAltitude = Altitude(x, y);
            int minDelta = 3 - 2 * unit + raiseMin * unit, maxDelta = 2 * unit - 2 - cutMax * unit;
            int walkX = originX, walkY = originY + 1;
            for (var guard = 0; guard < 4 * lotSize; guard++)
            {
                var outside = 0;
                for (var check = 0; check < 3; check++)
                {
                    if (!InLot(walkX, walkY)) outside++;
                    else
                    {
                        var (sx, sy) = camera.SourceTile(walkX, walkY);
                        if (sx >= 0 && sy >= 0 && sx < lotSize && sy < lotSize && !mask[sy * lotSize + sx])
                        {
                            int dx = walkX - originX, dy = walkY - originY;
                            var screenX = unit * (dx - dy);
                            var screenY = half * (dx + dy) - (Altitude(sx, sy) - originAltitude);
                            if (screenX <= maxDelta && screenX >= minDelta && screenY <= story + boxX - 1 && screenY >= 2 - unit)
                                mask[sy * lotSize + sx] = true;
                        }
                    }
                    if (check == 0) { walkX++; walkY--; }
                    else if (check == 1) walkY++;
                }
                if (outside >= 3) break;
                walkY++;
            }
        }
        return mask;
    }

    internal static ushort CutawayProbeRoom(RoomMap rooms, LotCamera camera, int lotSize, int tileX, int tileY, int zoom = 2)
    {
        zoom = Math.Clamp(zoom, 1, 3);
        var first = rooms.RoomAt(tileX, tileY);
        var probe = first;
        int unit = 8 << zoom, half = unit / 2;
        var origin = camera.CameraPoint(tileX + 0.5f, tileY + 0.5f);
        var screenX = unit * (origin.X - origin.Y);
        var screenY = half * (origin.X + origin.Y);
        for (var step = unit / 2; step < CutawayStoryPixels(zoom) / 2; step += unit / 2)
        {
            var x = (screenX + step) / unit;
            var y = screenY / half;
            int cameraX = (int)MathF.Floor((y + x) / 2), cameraY = (int)MathF.Floor((y - x) / 2);
            if (cameraX >= 1 && cameraY >= 1 && cameraX <= lotSize - 2 && cameraY <= lotSize - 2)
            {
                var (sx, sy) = camera.SourceTile(cameraX, cameraY);
                if (sx >= 0 && sy >= 0 && sx < rooms.Width && sy < rooms.Height) probe = rooms.RoomAt(sx, sy);
            }
            if (probe != first) break;
        }
        return probe;
    }

    internal static (int X, int Y, int Side) EdgeOwner(int x, int y, int neighbourX, int neighbourY)
    {
        var dx = neighbourX - x;
        var dy = neighbourY - y;
        if (dx < 0) return (x, y, 0);
        if (dx > 0) return (neighbourX, neighbourY, 0);
        if (dy < 0) return (x, y, 1);
        if (dy > 0) return (neighbourX, neighbourY, 1);
        return (-1, -1, 0);
    }

    internal static bool DynamicSpriteVisible(int spriteId, int dynamicBase, int dynamicCount, short[]? flags)
    {
        var index = spriteId - dynamicBase;
        if (index < 0 || index >= dynamicCount) return true;
        return flags is not null && index < flags.Length && flags[index] != 0;
    }

    public static int Stories(IffFile lot) => lot.Find(ResourceType.Parse("Arry"), 101) is not null ? 2 : 1;

    private static int TerrainType(short house) => house switch
    {
        28 or 29 or 46 or 47 or 48 => 1,
        40 or 41 or 42 => 3,
        >= 90 and <= 94 => 5,
        95 or 96 => 6,
        99 => 7,
        _ => 0,
    };

    private static readonly ConditionalWeakTable<ObjectRegistry, IReadOnlyDictionary<(IffFile File, ushort MasterId, ushort SubIndex), ObjectEntry>> shadowPartsCache = new();

    private static IReadOnlyDictionary<(IffFile File, ushort MasterId, ushort SubIndex), ObjectEntry> GetShadowParts(ObjectRegistry registry) =>
        shadowPartsCache.GetValue(registry, static reg =>
        {
            var parts = new Dictionary<(IffFile File, ushort MasterId, ushort SubIndex), ObjectEntry>();
            foreach (var part in reg.Entries)
            {
                if (part.Definition[ObjdField.MasterId] is not 0 && (short)part.Definition[ObjdField.LevelOffset] == 0)
                    parts.TryAdd((part.File, part.Definition[ObjdField.MasterId], part.Definition[ObjdField.SubIndex]), part);
            }
            return parts;
        });

    private readonly record struct SavedDoor(
        ObjectEntry Entry,
        uint Guid,
        short Id,
        float X,
        float Y,
        int TileX,
        int TileY,
        int Level,
        int Direction,
        ushort Flags1,
        ushort Flags2,
        short WallPlacement,
        short Graphic,
        short[] DynamicSpriteFlags);

    public sealed class AnimationState
    {
        internal long Revision;
        internal object? Kept;
    }

    private readonly record struct ObjectSpriteCacheKey(
        uint Guid,
        float OriginX,
        float OriginY,
        float OriginZ,
        int Level,
        int Direction,
        short Graphic,
        bool Contained,
        bool ShadowHidden,
        bool Lit,
        int SubtileRoom,
        int RoomLightByte,
        int CameraOrientation);

    private sealed record CachedObjectSprites(ObjectSpriteCacheKey Key, short[]? DynamicFlags, SceneSprite[] Sprites);

    private static bool DynamicFlagsSequenceEqual(short[]? left, short[]? right)
    {
        var leftEmpty = left is null || left.Length == 0;
        var rightEmpty = right is null || right.Length == 0;
        if (leftEmpty && rightEmpty) return true;
        if (leftEmpty || rightEmpty) return false;
        return left.AsSpan().SequenceEqual(right);
    }

    private sealed class Kept
    {
        public List<Texture> Textures = [];
        public int BaseTextureCount;
        public Dictionary<(uint Guid, int SpriteId, int Frame), int> SpriteTextures = [];
        public Dictionary<(uint Guid, int BitmapId), (int Texture, int Width, int Height)> SpeechImageTextures = [];
        public Dictionary<(uint Guid, int SpriteId, int Frame), int> SpriteDepthTextures = [];
        public Dictionary<(int Shadow, int Attenuation, int Zoom), int?> FloorShadowTextures = [];
        public Dictionary<string, int> AvatarTextures = new(StringComparer.Ordinal);
        public Dictionary<short, CachedObjectSprites> ObjectSprites = [];
        public HashSet<string> Written = new(StringComparer.Ordinal);
        public float[] Heights = [];
        public float BaseHeight;
        public bool[]? CutawayMask;
        public bool[]? WallAdjacentTiles;
        public int ViewLevel;
        public string WallMode = "down";
        public int CameraOrientation;
        public (int X, int Y)? CutawayTile;
        public ushort[] CutawayRooms = [];
        public (int X, int Y)? CutawaySim;
        public int CutawayZoom = 2;
        public HashSet<short> WallObjectIds = [];
        public SavedDoor[] SavedDoors = [];
        public float ShiftX, ShiftY;
        public SceneLighting.State? CachedLighting;
        public ulong CachedLightingXor;
        public ulong CachedLightingSum;
        public int CachedLightingRoomCount = -1;
        public int CachedLightingMapRooms = -1;
        public int CachedLightingMinute = -1;
        public int CachedLightingPhase = -1;
        public short CachedLightingHouse = -1;
        public long LastAnimatedUpdates = -1;
        public SceneSprite[]? CachedNonCarriedObjectSprites;
        public SceneLighting.Light[]? CachedSubTickLights;
        public IffFile? FloorArtwork;
        public bool HasFloorArtwork;
        public SceneLighting.Window[]? CachedSubTickWindows;
        public bool CutawayRaiseHoveredWalls;
        public LotArray? ViewLevelWalls;
        public List<(int X1, int Y1, int X2, int Y2)>? CutawayWallPairs;
        public List<(int X, int Y)>? CutawayDiagonalTiles;
        public Dictionary<(int Level, int X, int Y, int Side), WallStyleArt> ObjectStyles = [];
        public Dictionary<(int Level, int X, int Y, int Side), int> WallObjectKinds = [];
        public bool HasLiveObjects;
    }

    private static float HeightAtArray(float[] heights, int x, int y)
    {
        x = Math.Clamp(x, 0, Size - 1);
        y = Math.Clamp(y, 0, Size - 1);
        return heights[x * Size + y];
    }

    private static float ElevationAt(float[] heights, float baseHeight, float x, float y)
    {
        var left = Math.Clamp((int)x, 0, Size - 1);
        var top = Math.Clamp((int)y, 0, Size - 1);
        var right = Math.Min(left + 1, Size - 1);
        var bottom = Math.Min(top + 1, Size - 1);
        var fx = Math.Clamp(x - left, 0, 1);
        var fy = Math.Clamp(y - top, 0, 1);
        var upper = HeightAtArray(heights, left, top) * (1 - fx) + HeightAtArray(heights, right, top) * fx;
        var lower = HeightAtArray(heights, left, bottom) * (1 - fx) + HeightAtArray(heights, right, bottom) * fx;
        return (upper * (1 - fy) + lower * fy - baseHeight) * 0.75f;
    }

    private static bool CutawayRoomsSequenceEqual(ushort[] left, IReadOnlyList<ushort>? right)
    {
        var rightCount = right?.Count ?? 0;
        if (left.Length != rightCount) return false;
        for (var i = 0; i < left.Length; i++)
            if (left[i] != right![i]) return false;
        return true;
    }

    internal static bool[]? ComputeCutawayMask(
        RoomMap? rooms,
        LotCamera camera,
        int lotSize,
        string wallMode,
        (int X, int Y)? cutawayTile,
        IReadOnlyList<ushort>? cutawayRooms,
        (int X, int Y)? cutawaySim,
        int cutawayZoom,
        float[] heights,
        float baseHeight,
        bool raiseHoveredWalls = false,
        LotArray? viewLevelWalls = null)
    {
        if (wallMode != "cutaway" || rooms is null) return null;
        var selectedCutawayRooms = new HashSet<ushort>();
        var cutawayRectangleTiles = new HashSet<(int X, int Y)>();
        var touchedRooms = new HashSet<ushort>(cutawayRooms ?? Array.Empty<ushort>());
        if (cutawayTile is { } hovered && hovered.X >= 0 && hovered.Y >= 0 && hovered.X < rooms.Width && hovered.Y < rooms.Height &&
            rooms.RoomAt(hovered.X, hovered.Y) is var hoveredRoom && hoveredRoom != RoomMap.NoRoom)
            touchedRooms.Add(hoveredRoom);
        var simOutside = false;
        if (cutawaySim is { } sim && sim.X >= 0 && sim.Y >= 0 && sim.X < rooms.Width && sim.Y < rooms.Height &&
            rooms.RoomAt(sim.X, sim.Y) is var simRoom && simRoom != RoomMap.NoRoom)
        {
            touchedRooms.Add(simRoom);
            if (rooms.IsOutside(simRoom))
            {
                simOutside = true;
                foreach (var tile in CutawayRectangle(camera, sim.X, sim.Y, lotSize)) cutawayRectangleTiles.Add(tile);
            }
        }
        var anyOutside = simOutside;
        foreach (var room in touchedRooms)
        {
            if (rooms.IsOutside(room)) anyOutside = true;
            else selectedCutawayRooms.Add(room);
        }
        if (anyOutside && cutawayTile is { } cursor &&
            cursor.X >= 0 && cursor.Y >= 0 && cursor.X < lotSize && cursor.Y < lotSize)
        {
            foreach (var tile in CutawayRectangle(camera, cursor.X, cursor.Y, lotSize)) cutawayRectangleTiles.Add(tile);
        }
        var mask = CutawayMatrix(rooms, camera, lotSize, selectedCutawayRooms, cutawayRectangleTiles, cutawayZoom,
            (x, y) => ElevationAt(heights, baseHeight, x + 0.5f, y + 0.5f));
        if (raiseHoveredWalls && cutawayTile is { } wt && viewLevelWalls is not null)
        {
            ApplyWallpaperCutawayRaise(mask, viewLevelWalls, rooms, camera, lotSize, wt.X, wt.Y);
        }
        return mask;
    }

    internal static void ApplyWallpaperCutawayRaise(
        bool[] mask,
        LotArray viewLevelWalls,
        RoomMap rooms,
        LotCamera camera,
        int lotSize,
        int wtX,
        int wtY)
    {
        if ((uint)wtX >= (uint)lotSize || (uint)wtY >= (uint)lotSize || mask.Length < lotSize * lotSize)
            return;

        var cp = camera.CameraPoint(wtX + 0.5f, wtY + 0.5f);
        var u = (int)MathF.Floor(cp.X);
        var v = (int)MathF.Floor(cp.Y);

        bool HasCardinalFace(int cu, int cv, int face, out int sx, out int sy, out int nx, out int ny)
        {
            (sx, sy) = camera.SourceTile(cu, cv);
            (nx, ny) = face == 0 ? camera.SourceTile(cu - 1, cv) : camera.SourceTile(cu, cv - 1);
            if ((uint)sx >= (uint)lotSize || (uint)sy >= (uint)lotSize ||
                (uint)nx >= (uint)lotSize || (uint)ny >= (uint)lotSize)
                return false;
            var (ownerX, ownerY, side) = EdgeOwner(sx, sy, nx, ny);
            if ((uint)ownerX >= (uint)viewLevelWalls.Rows || (uint)ownerY >= (uint)viewLevelWalls.Width)
                return false;
            var owner = viewLevelWalls.Element(ownerX, ownerY);
            if ((owner[0] & (side == 0 ? 1 : 2)) == 0)
                return false;
            var storedStyle = side == 0 ? WallStyle0(owner) : WallStyle1(owner);
            return NormalizedWallStyle(storedStyle) == 1;
        }

        void RaiseCardinalRun(int face)
        {
            if (!HasCardinalFace(u, v, face, out var baseX, out var baseY, out _, out _))
                return;
            var facingRoom = baseX < rooms.Width && baseY < rooms.Height ? rooms.RoomAt(baseX, baseY) : RoomMap.NoRoom;
            var du = face == 1 ? 1 : 0;
            var dv = face == 0 ? 1 : 0;
            for (var dir = -1; dir <= 1; dir += 2)
            {
                var startStep = dir < 0 ? 0 : 1;
                for (var step = startStep; step < lotSize; step++)
                {
                    var cu = u + du * dir * step;
                    var cv = v + dv * dir * step;
                    if (!HasCardinalFace(cu, cv, face, out var sx, out var sy, out var nx, out var ny))
                        break;
                    if (step > 0 && facingRoom != RoomMap.NoRoom &&
                        (sx >= rooms.Width || sy >= rooms.Height || rooms.RoomAt(sx, sy) != facingRoom))
                        break;
                    mask[ny * lotSize + nx] = false;
                }
            }
        }

        RaiseCardinalRun(0);
        RaiseCardinalRun(1);

        if (wtX < viewLevelWalls.Rows && wtY < viewLevelWalls.Width)
        {
            var diagCell = viewLevelWalls.Element(wtX, wtY);
            var sourceDiag = diagCell[0] & 0x30;
            if (sourceDiag is 0x10 or 0x20 && NormalizedWallStyle(WallStyle1(diagCell)) == 1)
            {
                var cameraDiag = camera.Orientation % 2 == 0 ? sourceDiag : sourceDiag ^ 0x30;
                const int du = 1;
                var dv = cameraDiag == 0x10 ? -1 : 1;
                for (var dir = -1; dir <= 1; dir += 2)
                {
                    var startStep = dir < 0 ? 0 : 1;
                    for (var step = startStep; step < lotSize; step++)
                    {
                        var cu = u + du * dir * step;
                        var cv = v + dv * dir * step;
                        var (sx, sy) = camera.SourceTile(cu, cv);
                        if ((uint)sx >= (uint)lotSize || (uint)sy >= (uint)lotSize ||
                            sx >= viewLevelWalls.Rows || sy >= viewLevelWalls.Width)
                            break;
                        var cell = viewLevelWalls.Element(sx, sy);
                        if ((cell[0] & 0x30) != sourceDiag || NormalizedWallStyle(WallStyle1(cell)) != 1)
                            break;
                        mask[sy * lotSize + sx] = false;
                    }
                }
            }
        }
    }

    internal static bool CutawayMaskMatches(
        SimulationWorld world,
        AnimationState state,
        long revision,
        int viewLevel,
        string wallMode,
        int cameraOrientation,
        (int X, int Y)? cutawayTile,
        IReadOnlyList<ushort>? cutawayRooms,
        (int X, int Y)? cutawaySim,
        int cutawayZoom,
        bool raiseHoveredWalls = false)
    {
        if (state.Revision != revision || state.Kept is not Kept kept || kept.Heights.Length < Size * Size) return false;
        if (kept.ViewLevel != viewLevel || kept.WallMode != wallMode || kept.CameraOrientation != cameraOrientation)
            return false;
        if (kept.CutawayTile == cutawayTile &&
            kept.CutawaySim == cutawaySim &&
            kept.CutawayZoom == cutawayZoom &&
            kept.CutawayRaiseHoveredWalls == raiseHoveredWalls &&
            CutawayRoomsSequenceEqual(kept.CutawayRooms, cutawayRooms))
            return true;

        var lotSize = world.Globals.Length > 23 && world.Globals[23] is > 0 and <= Size ? world.Globals[23] : Size;
        var rooms = world.LotRoomMaps.TryGetValue(viewLevel, out var roomMap) ? roomMap : null;
        var camera = new LotCamera(cameraOrientation, lotSize, lotSize);
        var nextMask = ComputeCutawayMask(rooms, camera, lotSize, wallMode, cutawayTile, cutawayRooms, cutawaySim, cutawayZoom, kept.Heights, kept.BaseHeight, raiseHoveredWalls, kept.ViewLevelWalls);
        var matches = ReferenceEquals(nextMask, kept.CutawayMask) ||
                      (nextMask is not null && kept.CutawayMask is not null &&
                       (nextMask.AsSpan().SequenceEqual(kept.CutawayMask) ||
                        CutawayChangesIgnoreWallsAndPortals(world, viewLevel, lotSize, kept.CutawayMask, nextMask, kept)));
        if (matches)
        {
            kept.CutawayMask = nextMask;
            kept.CutawayTile = cutawayTile;
            kept.CutawaySim = cutawaySim;
            kept.CutawayZoom = cutawayZoom;
            kept.CutawayRaiseHoveredWalls = raiseHoveredWalls;
            kept.CutawayRooms = cutawayRooms is null or { Count: 0 } ? [] : [.. cutawayRooms];
        }
        return matches;
    }

    private static bool CutawayChangesIgnoreWallsAndPortals(
        SimulationWorld world,
        int viewLevel,
        int lotSize,
        bool[] previousMask,
        bool[] nextMask,
        Kept kept)
    {
        if (previousMask.Length != nextMask.Length)
            return false;

        bool PairCutaway(bool[] mask, int x1, int y1, int x2, int y2) =>
            (uint)x1 < (uint)lotSize && (uint)y1 < (uint)lotSize &&
            (uint)x2 < (uint)lotSize && (uint)y2 < (uint)lotSize &&
            mask[y1 * lotSize + x1] && mask[y2 * lotSize + x2];

        bool IsObjectLoweredForMask(bool[] mask, int tileX, int tileY, ushort flags1, ushort flags2, int wallPlacement, int direction, bool unresetPortalFallback)
        {
            if ((uint)tileX >= (uint)lotSize || (uint)tileY >= (uint)lotSize) return false;
            var hideForCutaway = (flags1 & 0x400) != 0 || (unresetPortalFallback && (flags2 & 0xc000) != 0);
            if (!hideForCutaway) return false;
            if (!mask[tileY * lotSize + tileX]) return false;
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
            return PairCutaway(mask, tileX, tileY, nx, ny);
        }

        if (kept.CutawayWallPairs is { } wallPairs && kept.CutawayDiagonalTiles is { } diagTiles)
        {
            for (var i = 0; i < wallPairs.Count; i++)
            {
                var (x1, y1, x2, y2) = wallPairs[i];
                if (PairCutaway(previousMask, x1, y1, x2, y2) != PairCutaway(nextMask, x1, y1, x2, y2))
                    return false;
            }

            for (var i = 0; i < diagTiles.Count; i++)
            {
                var (x, y) = diagTiles[i];
                if ((uint)x < (uint)lotSize && (uint)y < (uint)lotSize &&
                    previousMask[y * lotSize + x] != nextMask[y * lotSize + x])
                    return false;
            }

            foreach (var obj in world.WalkOrder)
            {
                if (obj is XPerson || obj.Position.Height != viewLevel) continue;
                var guid = (uint)(obj.TypeRecord?.Key ?? 0);
                var unresetPortalFallback = world.ChangedCodeTypeGuids.Contains(guid);
                var flags1 = unchecked((ushort)obj[ObjectData.Flags]);
                var flags2 = unchecked((ushort)obj[ObjectData.FlagField2]);
                var wallPlacement = obj[ObjectData.WallPlacementFlags];
                var direction = obj[ObjectData.Direction];
                var tileX = obj.Position.X >> 4;
                var tileY = obj.Position.Y >> 4;
                if (IsObjectLoweredForMask(previousMask, tileX, tileY, flags1, flags2, wallPlacement, direction, unresetPortalFallback) !=
                    IsObjectLoweredForMask(nextMask, tileX, tileY, flags1, flags2, wallPlacement, direction, unresetPortalFallback))
                    return false;
            }

            if (!kept.HasLiveObjects)
            {
                for (var i = 0; i < kept.SavedDoors.Length; i++)
                {
                    var door = kept.SavedDoors[i];
                    if (door.Level != viewLevel) continue;
                    var unresetPortalFallback = world.ChangedCodeTypeGuids.Contains(door.Guid);
                    if (IsObjectLoweredForMask(previousMask, door.TileX, door.TileY, door.Flags1, door.Flags2, door.WallPlacement, door.Direction, unresetPortalFallback) !=
                        IsObjectLoweredForMask(nextMask, door.TileX, door.TileY, door.Flags1, door.Flags2, door.WallPlacement, door.Direction, unresetPortalFallback))
                        return false;
                }
            }

            return true;
        }

        var wallAdjacentTiles = kept.WallAdjacentTiles;
        if (wallAdjacentTiles is null || wallAdjacentTiles.Length != nextMask.Length)
            return false;

        for (var i = 0; i < nextMask.Length; i++)
        {
            if (previousMask[i] == nextMask[i]) continue;
            if (wallAdjacentTiles[i]) return false;
        }

        foreach (var obj in world.WalkOrder)
        {
            if (obj.Position.Height != viewLevel || (obj[ObjectData.Flags] & 0x400) == 0) continue;
            var tx = obj.Position.X >> 4;
            var ty = obj.Position.Y >> 4;
            for (var dy = -1; dy <= 1; dy++)
            for (var dx = -1; dx <= 1; dx++)
            {
                var nx = tx + dx;
                var ny = ty + dy;
                if ((uint)nx >= (uint)lotSize || (uint)ny >= (uint)lotSize) continue;
                var idx = ny * lotSize + nx;
                if (previousMask[idx] != nextMask[idx]) return false;
            }
        }
        return true;
    }

    public static string Export(IffFile lot, SimulationWorld world, ObjectRegistry registry, string gameRoot, string directory, short house, long revision, int viewLevel = 1, string wallMode = "down", int cameraOrientation = 0, (int X, int Y)? cutawayTile = null, bool roofsVisible = false, AnimationState? state = null, IReadOnlyList<ushort>? cutawayRooms = null, (int X, int Y)? cutawaySim = null, int cutawayZoom = 2, bool showLoweredPortals = false, bool hideInteriorPeople = false, bool allowPlumbbob = true, short? authoritativeSelectedPersonId = null, bool raiseHoveredWalls = false) =>
        (string)Build(lot, world, registry, gameRoot, directory, house, revision, viewLevel, wallMode, cameraOrientation, cutawayTile, roofsVisible, state, false, 0, 0, cutawayRooms, cutawaySim, cutawayZoom, showLoweredPortals, 0f, hideInteriorPeople: hideInteriorPeople, allowPlumbbob: allowPlumbbob, authoritativeSelectedPersonId: authoritativeSelectedPersonId, raiseHoveredWalls: raiseHoveredWalls);

    public static object? Animation(IffFile lot, SimulationWorld world, ObjectRegistry registry, string gameRoot, string directory, short house, long revision, AnimationState state, long sequence, long updates, int viewLevel = 1, string wallMode = "down", int cameraOrientation = 0, (int X, int Y)? cutawayTile = null, bool roofsVisible = false, IReadOnlyList<ushort>? cutawayRooms = null, (int X, int Y)? cutawaySim = null, int cutawayZoom = 2, bool showLoweredPortals = false, float subTickAlpha = 0f, bool hideInteriorPeople = false, bool allowPlumbbob = true, short? authoritativeSelectedPersonId = null, bool raiseHoveredWalls = false) =>
        state.Kept is Kept && state.Revision == revision
            ? Build(lot, world, registry, gameRoot, directory, house, revision, viewLevel, wallMode, cameraOrientation, cutawayTile, roofsVisible, state, true, sequence, updates, cutawayRooms, cutawaySim, cutawayZoom, showLoweredPortals, subTickAlpha, directAnimation: false, hideInteriorPeople: hideInteriorPeople, allowPlumbbob: allowPlumbbob, authoritativeSelectedPersonId: authoritativeSelectedPersonId, raiseHoveredWalls: raiseHoveredWalls)
            : null;

    internal static DirectAnimationFrame? AnimationDirect(IffFile lot, SimulationWorld world, ObjectRegistry registry, string gameRoot, string directory, short house, long revision, AnimationState state, long sequence, long updates, int viewLevel = 1, string wallMode = "down", int cameraOrientation = 0, (int X, int Y)? cutawayTile = null, bool roofsVisible = false, IReadOnlyList<ushort>? cutawayRooms = null, (int X, int Y)? cutawaySim = null, int cutawayZoom = 2, bool showLoweredPortals = false, float subTickAlpha = 0f, bool hideInteriorPeople = false, bool allowPlumbbob = true, short? authoritativeSelectedPersonId = null, bool raiseHoveredWalls = false) =>
        state.Kept is Kept && state.Revision == revision
            ? (DirectAnimationFrame)Build(lot, world, registry, gameRoot, directory, house, revision, viewLevel, wallMode, cameraOrientation, cutawayTile, roofsVisible, state, true, sequence, updates, cutawayRooms, cutawaySim, cutawayZoom, showLoweredPortals, subTickAlpha, directAnimation: true, hideInteriorPeople: hideInteriorPeople, allowPlumbbob: allowPlumbbob, authoritativeSelectedPersonId: authoritativeSelectedPersonId, raiseHoveredWalls: raiseHoveredWalls)
            : null;

    private static ulong MixLightingTerm(ulong value)
    {
        value += 0x9e3779b97f4a7c15UL;
        value = (value ^ (value >> 30)) * 0xbf58476d1ce4e5b9UL;
        value = (value ^ (value >> 27)) * 0x94d049bb133111ebUL;
        return value ^ (value >> 31);
    }

    private static (ulong Xor, ulong Sum, int RoomCount, int MapRooms, int Minute, int Phase) LightingStamp(
        SimulationWorld world)
    {
        ulong xor = 0;
        ulong sum = 0;
        foreach (var pair in world.PersonRoomMotiveEntries)
        {
            var term = MixLightingTerm(
                ((ulong)pair.Key << 48)
                ^ ((ulong)(pair.Value.IsOutside ? 1 : 0) << 40)
                ^ ((ulong)pair.Value.LightsEnabledFlag73 << 41)
                ^ ((ulong)pair.Value.LightOverrideFlag75 << 42)
                ^ ((ulong)(uint)BitConverter.SingleToInt32Bits(pair.Value.LightLevel6c) << 8)
                ^ ((ulong)(ushort)pair.Value.LightingObjectCount140 << 24)
                ^ (ushort)pair.Value.PersonObjectCount142);
            xor ^= term;
            sum = unchecked(sum + term);
        }

        var mapRooms = 0;
        foreach (var map in world.LotRoomMaps.Values)
            mapRooms += map.RoomIds.Count;

        return (xor, sum, world.PersonRoomMotiveEntries.Count, mapRooms,
            world.Clock.Hour * 60 + world.Clock.Minute, world.Clock.TimeOfDay);
    }

    private static bool IsPersonHiddenBehindClosedRoof(SimulationWorld world, XPerson person)
    {
        int tx = person.Position.X >> 4;
        int ty = person.Position.Y >> 4;
        if (!world.LotRoomMaps.TryGetValue(person.Position.Height, out var pRooms))
            return false;
        if (tx < 0 || ty < 0 || tx >= pRooms.Width || ty >= pRooms.Height)
            return false;
        var room = pRooms.RoomAt(tx, ty);
        return room != RoomMap.NoRoom && !pRooms.IsOutside(room);
    }
}
