using System.Text.Json;
using System.Security.Cryptography;
using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.LotView.Model;
using FSO.LotView.Components;

internal sealed class LotSceneExporter
{
    private record Texture(string File, int Width, int Height, string Encoding = "rgba");
    private record FloorSurface(int X, int Y, ushort Pattern, int Half, NativeWaterSurface.Topology? Water = null, int Level = 1);
    private record RoofSurface(uint Style, float Pitch, string File, string Part = "surface");
    private record Mesh(int Texture, short ObjectID, float Depth, AvatarGeometry.Vertex[] Vertices, int Layer = 1, bool Unlit = false, FloorSurface? Floor = null, int Level = 1, RoofSurface? Roof = null, int? Room = null);
    private record WallSide(int X, int Y, int Level, int Direction, int Cut = 0);
    private record WallDepth(int X, int Y, int Level, int Configuration);
    private record WallJunction(int X, int Y, int Level, int Flags, int Frame, bool Down);
    private record Sprite(int Texture, float X, float Y, float Width, float Height, bool Flip, int Layer, float Depth, short ObjectID,
        int? DepthTexture = null, float? DepthNear = null, float? DepthFar = null, WallSide? Wall = null, int Level = 1, int? Room = null, WallJunction? Junction = null, WallDepth? ArchitectureDepth = null);
    private record TerrainVertex(float X, float Y, byte R, byte G, byte B);
    private static readonly (int X, int Y, int Width, int Height)[] WallRectangles = [(2, 39, 32, 136), (34, 39, 32, 136), (2, 55, 64, 120), (30, 73, 8, 116)];

    private sbyte visibleLevel = 1;
    private readonly VM vm;
    private readonly string directory;
    private readonly List<Texture> textures = [];
    private readonly Dictionary<string, int> textureFiles = [];
    private readonly Dictionary<SPR2Frame, int> textureIds = [];
    private readonly Dictionary<SPR2Frame, int?> depthTextureIds = [];
    private readonly Dictionary<SPRFrame, int> legacyTextureIds = [];
    private readonly Dictionary<(SPRFrame, SPRFrame), int> wallTextureIds = [];
    private readonly Dictionary<(int, int, int), int> proceduralDepthIds = [];
    private readonly Dictionary<byte[], int> avatarTextureIds = new(ReferenceEqualityComparer.Instance);
    private readonly List<Sprite> sprites = [];
    private readonly List<Mesh> meshes = [];
    private readonly HashSet<string> missing = [];
    private float originX, originY;
    private bool[]? cutawayMask;
    private bool editingView;
    private NativeLotCamera camera;

    private ushort RoomAt(int level, float x, float y) => vm.Context.GetRoomAt(new LotTilePos((short)(x * 16), (short)(y * 16), (sbyte)level));

    public LotSceneExporter(VM vm, string directory)
    {
        this.vm = vm;
        this.directory = directory;
        var architecture = vm.Context.Architecture;
        camera = new NativeLotCamera(0, architecture.Width, architecture.Height);
        Directory.CreateDirectory(directory);
    }

    public static void Export(VM vm, string directory, short house, int ticks, bool wallsUp = false, int cameraOrientation = 0) =>
        new LotSceneExporter(vm, directory).Snapshot(house, ticks, wallsUp, cameraOrientation: cameraOrientation);

    private int StorePixels(byte[] bytes, int width, int height, string encoding = "rgba")
    {
        var filename = $"{width}x{height}-{Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant()}.{encoding}";
        if (textureFiles.TryGetValue(filename, out var existing)) return existing;
        if (textureFiles.Count >= 10000) throw new InvalidDataException("Scene texture limit exceeded");
        var path = Path.Combine(directory, filename);
        if (!File.Exists(path)) File.WriteAllBytes(path, bytes);
        var id = textures.Count;
        textures.Add(new Texture(filename, width, height, encoding));
        textureFiles.Add(filename, id);
        return id;
    }

    private int Store(SPR2Frame frame)
    {
        if (textureIds.TryGetValue(frame, out var existing)) return existing;
        frame.DecodeIfRequired(false);
        if (frame.PixelData == null || frame.PixelData.Length != frame.Width * frame.Height)
            throw new InvalidDataException("Sprite pixel count differs from its dimensions");
        var bytes = new byte[frame.PixelData.Length * 4];
        for (var index = 0; index < frame.PixelData.Length; index++)
        {
            var pixel = frame.PixelData[index];
            bytes[index * 4] = pixel.R;
            bytes[index * 4 + 1] = pixel.G;
            bytes[index * 4 + 2] = pixel.B;
            bytes[index * 4 + 3] = pixel.A;
        }
        var id = StorePixels(bytes, frame.Width, frame.Height);
        textureIds.Add(frame, id);
        return id;
    }

    private int Store(SPRFrame frame)
    {
        if (legacyTextureIds.TryGetValue(frame, out var existing)) return existing;
        frame.DecodeIfRequired();
        var bytes = new byte[frame.Width * frame.Height * 4];
        for (var y = 0; y < frame.Height; y++)
        for (var x = 0; x < frame.Width; x++)
        {
            var pixel = frame.GetPixel(x, y);
            var index = (y * frame.Width + x) * 4;
            bytes[index] = pixel.R;
            bytes[index + 1] = pixel.G;
            bytes[index + 2] = pixel.B;
            bytes[index + 3] = pixel.A;
        }
        var id = StorePixels(bytes, frame.Width, frame.Height);
        legacyTextureIds.Add(frame, id);
        return id;
    }

    private int? StoreDepth(SPR2Frame frame)
    {
        if (depthTextureIds.TryGetValue(frame, out var existing)) return existing;
        frame.DecodeIfRequired(true);
        int? id = null;
        if (frame.ZBufferData != null)
        {
            if (frame.ZBufferData.Length != frame.Width * frame.Height)
                throw new InvalidDataException("Sprite depth count differs from its dimensions");
            id = StorePixels(frame.ZBufferData, frame.Width, frame.Height, "depth8");
        }
        depthTextureIds.Add(frame, id);
        return id;
    }

    private int StoreWall(SPRFrame pattern, SPRFrame mask)
    {
        if (wallTextureIds.TryGetValue((pattern, mask), out var existing)) return existing;
        pattern.DecodeIfRequired();
        mask.DecodeIfRequired();
        if (pattern.Width <= 0 || pattern.Height <= 0 || mask.Width <= 0 || mask.Height <= 0)
            throw new InvalidDataException("Wall texture has invalid dimensions");
        var bytes = new byte[pattern.Width * pattern.Height * 4];
        for (var y = 0; y < pattern.Height; y++)
        for (var x = 0; x < pattern.Width; x++)
        {
            var pixel = pattern.GetPixel(x, y);
            var alpha = mask.GetPixel(x * mask.Width / pattern.Width, y * mask.Height / pattern.Height).A;
            var index = (y * pattern.Width + x) * 4;
            bytes[index] = pixel.R;
            bytes[index + 1] = pixel.G;
            bytes[index + 2] = pixel.B;
            bytes[index + 3] = (byte)(alpha * pixel.A / 255);
        }
        var id = StorePixels(bytes, pattern.Width, pattern.Height);
        wallTextureIds.Add((pattern, mask), id);
        return id;
    }

    private int StoreArchitectureDepth(int configurationID, int colorTexture)
    {
        var dimensions = textures[colorTexture];
        var key = (configurationID, dimensions.Width, dimensions.Height);
        if (proceduralDepthIds.TryGetValue(key, out var existing)) return existing;
        var configuration = FSO.Common.Utils.TextureGenerator.WallZBufferConfig[configurationID];
        var depths = new byte[dimensions.Width * dimensions.Height];
        for (var row = 0; row < dimensions.Height; row++)
        for (var column = 0; column < dimensions.Width; column++)
        {
            var sourceX = Math.Min((int)configuration[0] - 1, column * (int)configuration[0] / dimensions.Width);
            var sourceY = Math.Min((int)configuration[1] - 1, row * (int)configuration[1] / dimensions.Height);
            depths[row * dimensions.Width + column] = (byte)Math.Clamp(Math.Round(configuration[2] + configuration[3] * sourceX + configuration[4] * sourceY), 0, 254);
        }
        var id = StorePixels(depths, dimensions.Width, dimensions.Height, "depth8");
        proceduralDepthIds.Add(key, id);
        return id;
    }

    private void AddJunction(sbyte level, int x, int y, int sourceX, int sourceY, JunctionFlags sourceUp, JunctionFlags sourceDown, JunctionFlags up, JunctionFlags down)
    {
        var lowered = up == 0;
        var flags = lowered ? down : up;
        var sourceFlags = lowered ? sourceDown : sourceUp;
        var frameIndex = WallComponent.JunctionFrame(flags);
        if (frameIndex < 0) return;
        var resource = Content.Get().WorldWalls.Junctions.Medium;
        if (resource == null || frameIndex >= resource.Frames.Count)
        {
            missing.Add($"wall-junction:{frameIndex}");
            return;
        }
        var frame = resource.Frames[frameIndex];
        var color = StoreWall(frame, frame);
        var depthTexture = StoreArchitectureDepth(19, color);
        var altitude = Elevation(sourceX, sourceY) / 40 + (lowered ? 0.3f + (level - 1) * NativeEntityTransform.StoryHeight : level * NativeEntityTransform.StoryHeight);
        var interval = camera.SpriteDepthCamera(x - 0.5f, y - 0.5f, altitude);
        var projected = camera.ProjectCamera(x, y, altitude * 40);
        sprites.Add(new Sprite(color, projected.X - 32, projected.Y - 15,
            64, 32, false, 1, camera.DepthOrderCamera(x, y) - 0.5f, 0, depthTexture, interval.Near, interval.Far,
            Level: level, Room: 1, Junction: new WallJunction(sourceX, sourceY, level, (int)sourceFlags, frameIndex, lowered)));
    }

    private void AddWall(sbyte level, int x, int y, int sourceX, int sourceY, int sourceDirection, ushort patternID, ushort styleID, ushort objectStyleID, bool door, int rotation, WallCut cut)
    {
        if (cut != WallCut.Up && door) return;
        var pattern = Content.Get().WorldWalls.Get(patternID)?.Medium;
        var down = cut == WallCut.Down;
        var effectiveStyle = cut == WallCut.DownLeftUpRight ? (ushort)7 : cut == WallCut.DownRightUpLeft ? (ushort)8 :
            !down && styleID == 1 && objectStyleID != 0 ? objectStyleID : styleID;
        var style = Content.Get().WorldWalls.GetWallStyle(effectiveStyle);
        var mask = down ? style?.WallsDownMedium : style?.WallsUpMedium;
        var cameraRotation = rotation;
        if (pattern == null || cameraRotation >= pattern.Frames.Count || mask == null || cameraRotation >= mask.Frames.Count)
        {
            missing.Add($"wall:{patternID}:style:{effectiveStyle}:rotation:{cameraRotation}");
            return;
        }
        var rect = WallRectangles[cameraRotation];
        var color = StoreWall(pattern.Frames[cameraRotation], mask.Frames[cameraRotation]);
        var altitude = Elevation(sourceX, sourceY) / 40 + (level - 1) * NativeEntityTransform.StoryHeight;
        var interval = camera.SpriteDepthCamera(x, y, altitude);
        var projected = camera.ProjectCamera(x, y, altitude * 40);
        var sprite = new Sprite(color,
            projected.X - 34 + rect.X, projected.Y - 158 + rect.Y, rect.Width, rect.Height, false, 1, camera.DepthOrderCamera(x, y) - 0.5f, 0, DepthTexture: StoreArchitectureDepth(cameraRotation + 4, color), DepthNear: interval.Near, DepthFar: interval.Far, ArchitectureDepth: new WallDepth(sourceX, sourceY, level, cameraRotation + 4), Wall: styleID == 1 ? new WallSide(sourceX, sourceY, level, sourceDirection, (int)cut) : null, Level: level, Room: RoomAt(level, sourceX + 0.5f, sourceY + 0.5f));
        sprites.Add(sprite);
        var overlayID = cut == WallCut.DownLeftUpRight ? 252 : cut == WallCut.DownRightUpLeft ? 253 : 0;
        if (overlayID != 0 && Content.Get().WorldWalls.Get((ushort)overlayID)?.Medium is SPR overlay && cameraRotation < overlay.Frames.Count)
        {
            var overlayTexture = StoreWall(overlay.Frames[cameraRotation], mask.Frames[cameraRotation]);
            sprites.Add(sprite with { Texture = overlayTexture, DepthTexture = StoreArchitectureDepth(cameraRotation + 4, overlayTexture), Wall = null });
        }
    }

    public string Snapshot(short house, int ticks, bool wallsUp = false, long revision = 0, sbyte viewLevel = 1, bool roofsVisible = false, string? wallMode = null, bool[]? cuts = null, bool editingView = false, int cameraOrientation = 0)
    {
        if (viewLevel < 1 || viewLevel > vm.Context.Architecture.Stories) throw new ArgumentOutOfRangeException(nameof(viewLevel));
        camera = new NativeLotCamera(cameraOrientation, vm.Context.Architecture.Width, vm.Context.Architecture.Height);
        visibleLevel = viewLevel;
        this.editingView = editingView;
        wallMode ??= wallsUp ? "up" : "down";
        cutawayMask = cuts ?? Enumerable.Repeat(!wallsUp, vm.Context.Architecture.Width * vm.Context.Architecture.Height).ToArray();
        sprites.Clear();
        meshes.Clear();
        missing.Clear();
        var terrainVertices = new List<TerrainVertex>();
        var architecture = vm.Context.Architecture;
        var terrain = architecture.Terrain;
        TerrainVertex TerrainPoint(int x, int y)
        {
            var index = Math.Min(y, architecture.Height - 1) * architecture.Width + Math.Min(x, architecture.Width - 1);
            var light = LotTypeGrassInfo.LightGreen[(int)terrain.LightType];
            var brown = terrain.LightType == terrain.DarkType ? LotTypeGrassInfo.LightBrown[(int)terrain.LightType] : LotTypeGrassInfo.LightGreen[(int)terrain.DarkType];
            var color = Microsoft.Xna.Framework.Color.Lerp(light, brown, terrain.GrassState[index] / 255f);
            var point = camera.Project(x, y, Elevation(x, y));
            return new TerrainVertex(point.X, point.Y, color.R, color.G, color.B);
        }
        for (var y = 0; y < architecture.Height; y++)
        for (var x = 0; x < architecture.Width; x++)
        {
            var top = TerrainPoint(x, y);
            var right = TerrainPoint(x + 1, y);
            var bottom = TerrainPoint(x + 1, y + 1);
            var left = TerrainPoint(x, y + 1);
            terrainVertices.AddRange([top, right, bottom, bottom, left, top]);
        }
        void AddFloor(sbyte level, ushort pattern, int x, int y, (int X, int Y, float U, float V)[] corners, int half = 0, bool cameraLocal = false, int? sourceTileX = null, int? sourceTileY = null)
        {
            if (pattern == 0) return;
            var tileX = sourceTileX ?? x;
            var tileY = sourceTileY ?? y;
            NativeWaterSurface.Pixels? water = null;
            int texture;
            if (pattern >= 65534)
            {
                water = NativeWaterSurface.Read(pattern, tileX, tileY, architecture.Width, architecture.Height, camera.Orientation,
                    (nx, ny) => architecture.Floors[level - 1][ny * architecture.Width + nx].Pattern);
                texture = StorePixels(water.Data, water.Width, water.Height);
            }
            else
            {
                var floor = Content.Get().WorldFloors.Get(pattern);
                if (floor?.Medium?.Frames.Length > 0) texture = Store(floor.Medium.Frames[0]);
                else { missing.Add($"floor:{pattern}"); return; }
            }
            var vertices = corners.Select(corner => {
                var pointX = x + corner.X;
                var pointY = y + corner.Y;
                var sourcePoint = cameraLocal ? camera.SourcePoint(pointX, pointY) : new Microsoft.Xna.Framework.Vector2(pointX, pointY);
                var elevation = Elevation(sourcePoint.X, sourcePoint.Y) + (level - 1) * NativeEntityTransform.StoryHeight * 40;
                var projected = cameraLocal ? camera.ProjectCamera(pointX, pointY, elevation) : camera.Project(pointX, pointY, elevation);
                var uv = water == null ? camera.TexturePoint(corner.U, corner.V) : new Microsoft.Xna.Framework.Vector2(corner.U, corner.V);
                return new AvatarGeometry.Vertex(projected.X, projected.Y, water == null && level == 1 ? 1 : cameraLocal ? camera.DepthCamera(pointX, pointY, elevation / 40 + (level - 1) * NativeEntityTransform.StoryHeight) : camera.Depth(pointX, pointY, elevation / 40 + (level - 1) * NativeEntityTransform.StoryHeight), uv.X, uv.Y, 0, 1, 0);
            }).ToArray();
            var depth = cameraLocal ? camera.DepthOrderCamera(x + 0.5f, y + 0.5f) : camera.DepthOrder(x + 0.5f, y + 0.5f);
            meshes.Add(new Mesh(texture, 0, depth, vertices, 0, true, new FloorSurface(tileX, tileY, pattern, half, water?.Topology, level), level,
                Room: RoomAt(level, tileX + (float)corners.Average(corner => corner.X), tileY + (float)corners.Average(corner => corner.Y))));
        }
        for (sbyte level = 1; level <= viewLevel; level++)
        {
        for (var y = 0; y < architecture.Height; y++)
        for (var x = 0; x < architecture.Width; x++)
        {
            var wall = architecture.Walls[level - 1][y * architecture.Width + x];
            if ((wall.Segments & WallSegments.AnyDiag) == 0) AddFloor(level, architecture.Floors[level - 1][y * architecture.Width + x].Pattern, x, y,
                [(0, 0, 0.5f, 0), (1, 0, 1, 0.5f), (1, 1, 0.5f, 1), (1, 1, 0.5f, 1), (0, 1, 0, 0.5f), (0, 0, 0.5f, 0)]);
        }

        var geometry = NativeCutaway.Walls(vm, level, cutawayMask, level == viewLevel, (FSO.LotView.WorldRotation)camera.Orientation);
        var wallCuts = geometry.Cuts;
        for (var y = 0; y < geometry.Height; y++)
        for (var x = 0; x < geometry.Width; x++)
        {
            var index = y * geometry.Width + x;
            var source = camera.SourceTile(x, y);
            var sourceX = source.X;
            var sourceY = source.Y;
            var wall = geometry.Walls[index];
            if (wall.Segments == WallSegments.VerticalDiag)
            {
                AddFloor(level, wall.TopLeftPattern, x, y, [(0, 0, 0.5f, 0), (1, 0, 1, 0.5f), (1, 1, 0.5f, 1)], 1, true, sourceX, sourceY);
                AddFloor(level, wall.TopLeftStyle, x, y, [(1, 1, 0.5f, 1), (0, 1, 0, 0.5f), (0, 0, 0.5f, 0)], 2, true, sourceX, sourceY);
            }
            else if (wall.Segments == WallSegments.HorizontalDiag)
            {
                AddFloor(level, wall.TopLeftStyle, x, y, [(0, 0, 0.5f, 0), (1, 0, 1, 0.5f), (0, 1, 0, 0.5f)], 3, true, sourceX, sourceY);
                AddFloor(level, wall.TopLeftPattern, x, y, [(1, 0, 1, 0.5f), (1, 1, 0.5f, 1), (0, 1, 0, 0.5f)], 4, true, sourceX, sourceY);
            }
            if ((wall.Segments & WallSegments.TopLeft) != 0)
                AddWall(level, x, y, sourceX, sourceY, camera.SourceWallDirection(0), wall.TopLeftPattern, wall.TopLeftStyle, wall.ObjSetTLStyle, wall.TopLeftDoor, 0, wallCuts[index].TLCut);
            if ((wall.Segments & WallSegments.TopRight) != 0)
                AddWall(level, x, y, sourceX, sourceY, camera.SourceWallDirection(1), wall.TopRightPattern, wall.TopRightStyle, wall.ObjSetTRStyle, wall.TopRightDoor, 1, wallCuts[index].TRCut);
            if (wall.Segments == WallSegments.HorizontalDiag)
                AddWall(level, x, y, sourceX, sourceY, camera.SourceWallDirection(2), wall.BottomRightPattern, wall.TopRightStyle, wall.ObjSetTRStyle, wall.TopRightDoor, 2, wallCuts[index].TRCut);
            if (wall.Segments == WallSegments.VerticalDiag)
                AddWall(level, x, y, sourceX, sourceY, camera.SourceWallDirection(3), wall.BottomRightPattern, wall.TopRightStyle, wall.ObjSetTRStyle, wall.TopRightDoor, 3, wallCuts[index].TRCut);
            AddJunction(level, x, y, sourceX, sourceY, (JunctionFlags)camera.UnrotateJunction((int)geometry.UpJunctions[index]), (JunctionFlags)camera.UnrotateJunction((int)geometry.DownJunctions[index]), geometry.UpJunctions[index], geometry.DownJunctions[index]);
        }

        }

        BuildDynamic();
        if (roofsVisible)
        {
            var material = NativeRoofGeometry.ReadMaterial(architecture.RoofStyle);
            var texture = StorePixels(material.Bytes, material.Width, material.Height, "bmp");
            var edge = NativeRoofGeometry.ReadEdges(architecture.RoofStyle);
            var edgeTexture = StorePixels(edge.Bytes, edge.Width, edge.Height, "png");
            foreach (var roof in NativeRoofGeometry.Build(vm, camera))
                if (roof.Level <= viewLevel) meshes.Add(new Mesh(roof.Edge ? edgeTexture : texture, 0, 0, roof.Vertices, 2, false, Level: roof.Level,
                    Roof: new RoofSurface(material.Style, architecture.RoofPitch, material.File, roof.Edge ? "edge" : "surface"), Room: 1));
        }
        var constructionVertices = terrainVertices.Select(vertex => vertex with { Y = vertex.Y - (viewLevel - 1) * NativeEntityTransform.StoryHeight * 40 }).ToArray();
        var meshVertices = meshes.SelectMany(mesh => mesh.Vertices).ToArray();
        var minX = Math.Min(sprites.Select(sprite => sprite.X).DefaultIfEmpty(float.PositiveInfinity).Min(), terrainVertices.Select(vertex => vertex.X).Concat(meshVertices.Select(vertex => vertex.X)).Min());
        var minY = Math.Min(sprites.Select(sprite => sprite.Y).DefaultIfEmpty(float.PositiveInfinity).Min(), terrainVertices.Select(vertex => vertex.Y).Concat(constructionVertices.Select(vertex => vertex.Y)).Concat(meshVertices.Select(vertex => vertex.Y)).Min());
        var maxX = Math.Max(sprites.Select(sprite => sprite.X + sprite.Width).DefaultIfEmpty(float.NegativeInfinity).Max(), terrainVertices.Select(vertex => vertex.X).Concat(meshVertices.Select(vertex => vertex.X)).Max());
        var maxY = Math.Max(sprites.Select(sprite => sprite.Y + sprite.Height).DefaultIfEmpty(float.NegativeInfinity).Max(), terrainVertices.Select(vertex => vertex.Y).Concat(constructionVertices.Select(vertex => vertex.Y)).Concat(meshVertices.Select(vertex => vertex.Y)).Max());
        originX = minX;
        originY = minY;
        var ordered = sprites.OrderBy(sprite => sprite.Layer).ThenBy(sprite => sprite.Depth)
            .Select(sprite => sprite with { X = sprite.X - minX, Y = sprite.Y - minY }).ToArray();
        var scene = new { schemaVersion = 1, house, ticks, wallsUp, wallMode, roofsVisible, cameraOrientation = camera.Orientation, viewLevel, stories = architecture.Stories, wallSprites = sprites.Count(sprite => sprite.Layer == 1 && sprite.ObjectID == 0), width = maxX - minX, height = maxY - minY,
            lotWidth = architecture.Width, lotHeight = architecture.Height,
            floorDiagonals = architecture.Walls[viewLevel - 1].Select(wall => (int)(wall.Segments & (WallSegments.HorizontalDiag | WallSegments.VerticalDiag))).ToArray(),
            placementVertices = constructionVertices.Select(vertex => vertex with { X = vertex.X - minX, Y = vertex.Y - minY }).ToArray(),
            lighting = NativeRoomLighting.Read(vm), textures, sprites = ordered, meshes = meshes.Select(mesh => mesh with { Vertices = mesh.Vertices.Select(vertex => vertex with { X = vertex.X - minX, Y = vertex.Y - minY }).ToArray() }).ToArray(),
            terrainVertices = terrainVertices.Select(vertex => vertex with { X = vertex.X - minX, Y = vertex.Y - minY }).ToArray(), terrainHeights = terrain.Heights, missingResources = missing.Order().ToArray(),
            limitations = new[] { "Localized light maps and shadows are not rendered", "Sprites without depth maps still use draw ordering; exact original depth parity remains incomplete", "Exact cutaway parity remains incomplete", "Terrain uses procedural detail with simulation heights and grass state", "Avatar poses support a 30 Hz live stream; slot transition interpolation and sub-tick interpolation remain incomplete" } };
        var scenePath = Path.Combine(directory, revision == 0 ? "scene.json" : $"scene-{revision}.json");
        File.WriteAllText(scenePath + ".tmp", JsonSerializer.Serialize(scene,
            new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase, WriteIndented = true }));
        File.Move(scenePath + ".tmp", scenePath, true);
        Console.Error.WriteLine($"Exported {sprites.Count} sprites, {meshes.Count} mesh parts and {textures.Count} textures; {missing.Count} unavailable resources");
        return scenePath;
    }

    private int StoreAvatarTexture(AvatarGeometry.Part part)
    {
        if (avatarTextureIds.TryGetValue(part.Texture, out var existing)) return existing;
        var index = StorePixels(part.Texture, part.Width, part.Height, part.Encoding);
        avatarTextureIds.Add(part.Texture, index);
        return index;
    }

    private void BuildDynamic(IEnumerable<VMGameObject>? objects = null, bool includeAvatars = true, Func<VMGameObject, LotTilePos>? positionFor = null, Direction? directionOverride = null)
    {
        var transforms = new NativeEntityTransform(Elevation);
        foreach (var entity in objects ?? vm.Entities.OfType<VMGameObject>())
        {
            var position = positionFor?.Invoke(entity) ?? entity.Position;
            var direction = directionOverride ?? entity.Direction;
            if (position.Level < 1 || position.Level > visibleLevel || position.x < 0 || position.y < 0) continue;
            if (entity.GetValue(VMStackObjectVariable.Hidden) != 0 ||
                !editingView && positionFor == null && position.Level == visibleLevel && cutawayMask != null && NativeCutaway.Hidden(vm, entity, cutawayMask)) continue;
            var requestedGraphic = (ushort)(entity.Object.OBJ.BaseGraphicID + entity.GetValue(VMStackObjectVariable.Graphic));
            var group = (entity.WorldUI as ObjectComponent)?.DGRP ?? entity.Object.Resource.Get<DGRP>(requestedGraphic);
            if (group == null && requestedGraphic != entity.Object.OBJ.BaseGraphicID)
                group = entity.Object.Resource.Get<DGRP>(entity.Object.OBJ.BaseGraphicID);
            var image = group?.GetImage((uint)direction, 2, (uint)camera.Orientation);
            if (image == null)
            {
                var resource = entity.Object.Resource;
                var mainGroups = string.Join(",", resource.Iff == null ? Enumerable.Empty<ushort>() : resource.Iff.ListAll().Where(chunk => chunk.ChunkType == "DGRP").Select(chunk => chunk.ChunkID).Order());
                var spriteGroups = string.Join(",", resource.Sprites == null ? Enumerable.Empty<ushort>() : resource.Sprites.ListAll().Where(chunk => chunk.ChunkType == "DGRP").Select(chunk => chunk.ChunkID).Order());
                var reason = group == null ? "group-absent" : "image-absent";
                missing.Add($"object:{entity.ObjectID}:guid:{entity.Object.OBJ.GUID}:baseGraphic:{entity.Object.OBJ.BaseGraphicID}:graphicOffset:{entity.GetValue(VMStackObjectVariable.Graphic)}:requestedGraphic:{requestedGraphic}:renderedGraphic:{group?.ChunkID}:name:{entity.Name}:resource:{resource.Name}:main:{resource.Iff?.Filename}:sprites:{resource.Sprites?.Filename}:{reason}:direction:{(byte)direction}:zoom:2:rotation:{camera.Orientation}:mainGroups:{mainGroups}:spriteGroups:{spriteGroups}");
                continue;
            }
            foreach (var sprite in image.Sprites)
            {
                var definition = entity.Object.OBJ;
                if (sprite.SpriteID >= definition.DynamicSpriteBaseId && sprite.SpriteID < definition.DynamicSpriteBaseId + definition.NumDynamicSprites)
                {
                    var bit = (int)(sprite.SpriteID - definition.DynamicSpriteBaseId);
                    var flags = bit < 64 ? entity.DynamicSpriteFlags : entity.DynamicSpriteFlags2;
                    if ((flags & (1UL << (bit % 64))) == 0) continue;
                }
                var chunk = entity.Object.Resource.Get<SPR2>((ushort)sprite.SpriteID);
                SPR2Frame? frame = null;
                SPRFrame? legacyFrame = null;
                if (chunk != null)
                {
                    if (sprite.SpriteFrameIndex < chunk.Frames.Length) frame = chunk.Frames[sprite.SpriteFrameIndex];
                }
                else
                {
                    var legacyChunk = entity.Object.Resource.Get<SPR>((ushort)sprite.SpriteID);
                    if (legacyChunk != null && sprite.SpriteFrameIndex < legacyChunk.Frames.Count) legacyFrame = legacyChunk.Frames[(int)sprite.SpriteFrameIndex];
                }
                if (frame == null && legacyFrame == null)
                {
                    var legacyChunk = entity.Object.Resource.Get<SPR>((ushort)sprite.SpriteID);
                    if (sprite.SpriteID == 0 && chunk == null && legacyChunk == null) continue;
                    var frameCount = chunk?.Frames.Length ?? legacyChunk?.Frames.Count ?? 0;
                    var sourceType = chunk != null || legacyChunk != null ? "frame-out-of-range" : "chunk-absent";
                    missing.Add($"sprite:{entity.ObjectID}:{sprite.SpriteID}:{sprite.SpriteFrameIndex}:resource:{entity.Object.Resource.Name}:main:{entity.Object.Resource.Iff?.Filename}:sprites:{entity.Object.Resource.Sprites?.Filename}:{sourceType}:frameCount:{frameCount}");
                    continue;
                }
                var frameWidth = frame?.Width ?? legacyFrame!.Width;
                var frameHeight = frame?.Height ?? legacyFrame!.Height;
                if (frameWidth == 0 || frameHeight == 0) continue;
                var origin = positionFor == null ? transforms.Position(entity) : transforms.Position(position);
                var x = origin.X;
                var y = origin.Y;
                var offset = Microsoft.Xna.Framework.Vector3.Transform(sprite.ObjectOffset, Microsoft.Xna.Framework.Matrix.CreateRotationZ(directionOverride.HasValue ? (float)(Math.Log2((byte)direction) * Math.PI / 4) : entity.RadianDirection));
                var colorTexture = frame != null ? Store(frame) : Store(legacyFrame!);
                var depthTexture = frame == null ? null : StoreDepth(frame);
                var depthInterval = camera.SpriteDepth(x + offset.X / 16, y + offset.Y / 16,
                    origin.Z + offset.Z / 5);
                var offsetPoint = camera.Project(x + offset.X / 16, y + offset.Y / 16, origin.Z * 40);
                var spriteX = (int)(offsetPoint.X + sprite.SpriteOffset.X);
                var spriteY = (int)(offsetPoint.Y + 16 - frameHeight + sprite.SpriteOffset.Y - offset.Z * 118 / 15f);
                sprites.Add(new Sprite(colorTexture, spriteX, spriteY,
                    frameWidth, frameHeight, sprite.Flip, 1, camera.DepthOrder(x + offset.X / 16, y + offset.Y / 16), entity.ObjectID,
                    depthTexture, depthTexture.HasValue ? depthInterval.Near : null, depthTexture.HasValue ? depthInterval.Far : null, Level: position.Level, Room: RoomAt(position.Level, x, y)));
            }
        }
        if (!includeAvatars) return;
        foreach (var avatar in vm.Entities.OfType<VMAvatar>())
        {
            if (avatar.Position.Level < 1 || avatar.Position.Level > visibleLevel || avatar.Position.x < 0 || avatar.Position.y < 0 || avatar.GetValue(VMStackObjectVariable.Hidden) != 0) continue;
            try
            {
                foreach (var part in AvatarGeometry.Build(avatar, transforms, camera))
                    if (part.Vertices.Length > 0)
                        meshes.Add(new Mesh(StoreAvatarTexture(part), avatar.ObjectID,
                            camera.DepthOrder(avatar.Position.x / 16f, avatar.Position.y / 16f), part.Vertices, Level: avatar.Position.Level, Room: vm.Context.GetObjectRoom(avatar)));
                foreach (var failure in AvatarGeometry.AppearanceFailures(avatar)) missing.Add($"avatar-appearance:{avatar.ObjectID}:{failure}");
            }
            catch (Exception error)
            {
                missing.Add($"avatar:{avatar.ObjectID}:{error.Message}");
                Console.Error.WriteLine(error);
            }
        }
    }

    public object? PlacementGhost(VM preview, IEnumerable<VMGameObject> objects, Dictionary<short, LotTilePos> positions, Direction direction)
    {
        var ghost = new LotSceneExporter(preview, directory);
        ghost.camera = new NativeLotCamera(camera.Orientation, preview.Context.Architecture.Width, preview.Context.Architecture.Height);
        ghost.visibleLevel = positions.Values.Max(position => position.Level);
        ghost.BuildDynamic(objects, false, entity => positions[entity.ObjectID], direction);
        if (ghost.sprites.Count == 0) return null;
        var minX = ghost.sprites.Select(sprite => sprite.X).DefaultIfEmpty(float.PositiveInfinity).Min();
        var minY = ghost.sprites.Select(sprite => sprite.Y).DefaultIfEmpty(float.PositiveInfinity).Min();
        var maxX = ghost.sprites.Select(sprite => sprite.X + sprite.Width).DefaultIfEmpty(float.NegativeInfinity).Max();
        var maxY = ghost.sprites.Select(sprite => sprite.Y + sprite.Height).DefaultIfEmpty(float.NegativeInfinity).Max();
        return new { x = minX - originX, y = minY - originY,
            scene = new { schemaVersion = 1, house = 0, cameraOrientation = ghost.camera.Orientation, width = maxX - minX, height = maxY - minY, textures = ghost.textures,
                sprites = ghost.sprites.OrderBy(sprite => sprite.Depth).Select(sprite => sprite with { X = sprite.X - minX, Y = sprite.Y - minY }).ToArray(),
                limitations = new[] { "Object placement ghost; contained-object visuals and slot heights remain incomplete" } } };
    }

    public object Animation(long baseRevision, long sequence, long updates)
    {
        var textureStart = textures.Count;
        sprites.Clear();
        meshes.Clear();
        missing.Clear();
        BuildDynamic();
        return new { schemaVersion = 1, baseRevision, sequence, updates, textureStart, lighting = NativeRoomLighting.Read(vm), missingResources = missing.Order().ToArray(),
            textures = textures.Skip(textureStart).ToArray(),
            sprites = sprites.OrderBy(sprite => sprite.Depth).Select(sprite => sprite with { X = sprite.X - originX, Y = sprite.Y - originY }).ToArray(),
            meshes = meshes.Select(mesh => new { mesh.Texture, mesh.ObjectID, mesh.Depth, mesh.Level, mesh.Room, vertices = PackVertices(mesh.Vertices) }).ToArray() };
    }

    private byte[] PackVertices(AvatarGeometry.Vertex[] vertices)
    {
        using var data = new MemoryStream(vertices.Length * 32);
        using var writer = new BinaryWriter(data);
        foreach (var vertex in vertices)
        {
            writer.Write(vertex.X - originX);
            writer.Write(vertex.Y - originY);
            writer.Write(vertex.Z);
            writer.Write(vertex.U);
            writer.Write(vertex.V);
            writer.Write(vertex.Nx);
            writer.Write(vertex.Ny);
            writer.Write(vertex.Nz);
        }
        return data.ToArray();
    }

    private float Elevation(float x, float y)
    {
        var architecture = vm.Context.Architecture;
        var terrain = architecture.Terrain;
        var baseHeight = terrain.Heights[0];
        var left = Math.Clamp((int)x, 0, architecture.Width - 1);
        var top = Math.Clamp((int)y, 0, architecture.Height - 1);
        var right = Math.Min(left + 1, architecture.Width - 1);
        var bottom = Math.Min(top + 1, architecture.Height - 1);
        var fractionX = Math.Clamp(x - left, 0, 1);
        var fractionY = Math.Clamp(y - top, 0, 1);
        var upper = terrain.Heights[top * architecture.Width + left] * (1 - fractionX) + terrain.Heights[top * architecture.Width + right] * fractionX;
        var lower = terrain.Heights[bottom * architecture.Width + left] * (1 - fractionX) + terrain.Heights[bottom * architecture.Width + right] * fractionX;
        return (upper * (1 - fractionY) + lower * fractionY - baseHeight) * (3f / 160) * 40;
    }

}
