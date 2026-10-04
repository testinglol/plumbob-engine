using FSO.Content;
using FSO.Content.Model;
using FSO.LotView.Components;
using FSO.LotView.Model;
using FSO.LotView.Utils;
using FSO.SimAntics;
using Microsoft.Xna.Framework;

internal static class NativeRoofGeometry
{
    public record Surface(int Level, AvatarGeometry.Vertex[] Vertices, bool Edge = false);
    public record Material(uint Style, string File, byte[] Bytes, int Width, int Height);
    public static Material ReadMaterial(uint style)
    {
        var provider = Content.Get().WorldRoofs;
        if (style >= provider.Count) throw new InvalidDataException("Unknown roof style");
        var file = provider.IDToName((int)style);
        var texture = provider.Get(file) as AbstractTextureRef ?? throw new InvalidDataException("Roof has no readable texture");
        var bytes = texture.ReadSourceData();
        if (bytes.Length < 54 || bytes[0] != 'B' || bytes[1] != 'M') throw new InvalidDataException("Roof material is not a BMP");
        var width = System.Buffers.Binary.BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(18));
        var height = Math.Abs((long)System.Buffers.Binary.BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(22)));
        if (width < 1 || width > 4096 || height < 1 || height > 4096) throw new InvalidDataException("Invalid roof texture dimensions");
        return new Material(style, file, bytes, width, (int)height);
    }

    public static Material ReadEdges(uint style)
    {
        var file = Path.Combine(FSO.Common.FSOEnvironment.ContentDir, "Textures", "roof", "default_edge.png");
        var bytes = File.ReadAllBytes(file);
        if (bytes.Length < 33 || !bytes.AsSpan(0, 8).SequenceEqual(new byte[] { 137, 80, 78, 71, 13, 10, 26, 10 })) throw new InvalidDataException("Invalid roof edge PNG");
        var width = System.Buffers.Binary.BinaryPrimitives.ReadInt32BigEndian(bytes.AsSpan(16));
        var height = System.Buffers.Binary.BinaryPrimitives.ReadInt32BigEndian(bytes.AsSpan(20));
        if (width < 1 || width > 4096 || height < 1 || height > 4096) throw new InvalidDataException("Invalid roof edge dimensions");
        return new Material(style, "default_edge.png", bytes, width, height);
    }

    public static Surface[] Build(VM vm, NativeLotCamera camera)
    {
        var architecture = vm.Context.Architecture;
        var terrain = architecture.Terrain;
        var blueprint = new Blueprint(architecture.Width, architecture.Height)
        {
            Stories = (sbyte)architecture.Stories, Floors = architecture.Floors, Walls = architecture.Walls,
            RoomMap = architecture.Rooms.Select(room => room.Map).ToArray(),
            Rooms = architecture.RoomData.Select(room => new Room { IsOutside = room.IsOutside }).ToList(),
            Altitude = terrain.Heights, AltitudeCenters = terrain.Centers, BaseAlt = terrain.Heights[0]
        };
        var component = new RoofComponent(blueprint) { RoofPitch = architecture.RoofPitch, RoofStyle = architecture.RoofStyle, TexRescale = 1, RoofAvgColor = Color.White };
        var result = new List<Surface>();
        var data = component.BuildGeometry();
        for (int story = 0; story < data.Length; story++)
        {
            var roof = data[story];
            if (roof.Indices.Length == 0) continue;
            AvatarGeometry.Vertex Vertex(TerrainParallaxVertex vertex)
            {
                var point = vertex.Position / 3;
                var projected = camera.Project(point.X, point.Z, point.Y * 40);
                var uv = camera.TexturePoint(vertex.GrassInfo.Y, vertex.GrassInfo.Z);
                var normal = camera.CameraNormal(vertex.Normal);
                return new AvatarGeometry.Vertex(projected.X, projected.Y,
                    camera.Depth(point.X, point.Z, point.Y), uv.X, uv.Y,
                    normal.X, normal.Y, normal.Z);
            }
            var vertices = roof.Indices.Select(index => Vertex(roof.Vertices[index])).ToArray();
            result.Add(new Surface(story + 1, vertices));
            if (roof.AdvIndices.Length > 0)
                result.Add(new Surface(story + 1, roof.AdvIndices.Select(index => Vertex(roof.AdvVertices[index])).ToArray(), true));
        }
        return result.ToArray();
    }
}
