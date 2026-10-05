using FSO.Content.Model;
using FSO.Files.Formats.IFF;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.Vitaboy;
using Microsoft.Xna.Framework;

/// <summary>
/// The portraits the original Create a Family writes into a new Sim's character file: BMP_ 2002 "faces" (three 35×41
/// frames on navy), 2003 "rel. images" (five 40×40 frames on the relationship colours), 2004 "thumbnail" (25×25 on black
/// with a blue edge), 2005 "speech_med" (16×16) and 2006 "speech_large" (32×32), all 24-bit. They are drawn here with a
/// small software rasterizer from the Sim's posed head, lit softly from the front; without them the panel would show the
/// template person's bitmap.
/// </summary>
internal static class NativeSimPortrait
{
    private sealed record Triangle(Vector3 A, Vector3 B, Vector3 C, Vector2 Ta, Vector2 Tb, Vector2 Tc, Vector3 Na, Vector3 Nb, Vector3 Nc, Texture Image);
    private sealed record Texture(int Width, int Height, byte[] Rgba);

    private static readonly (int R, int G, int B)[] RelationshipColours = [(208, 0, 0), (136, 44, 40), (64, 92, 88), (32, 144, 72), (0, 200, 56)];
    private static readonly (int R, int G, int B) Navy = (0, 0, 80), Speech = (248, 252, 248), Black = (0, 0, 0), Edge = (0, 0, 248);

    /// <summary>Adds (or replaces) the portrait chunks in the character file at <paramref name="path"/>.</summary>
    internal static void Write(string path, VMAvatar avatar)
    {
        var posed = AvatarGeometry.Pose(avatar);
        var front = Render(posed, 0);
        var turned = Render(posed, MathHelper.ToRadians(-30));
        var chunks = new List<(ushort Id, string Label, byte[] Data)>
        {
            (2002, "faces", Strip(front, 35, 41, 3, _ => Navy)),
            (2003, "rel. images", Strip(front, 40, 40, 5, frame => RelationshipColours[frame])),
            (2004, "thumbnail", Bordered(front, 25)),
            (2005, "speech_med", Strip(turned, 16, 16, 1, _ => Speech)),
            (2006, "speech_large", Strip(turned, 32, 32, 1, _ => Speech)),
        };
        var iff = new IffFile(path, true);
        foreach (var (id, label, data) in chunks)
        {
            if (iff.Get<BMP>(id) is { } existing) iff.RemoveChunk(existing);
            iff.AddChunk(new BMP { ChunkID = id, ChunkLabel = label, ChunkType = "BMP_", ChunkProcessed = true, AddedByPatch = true, data = data });
        }
        var temporary = path + ".tmp";
        try
        {
            using (var stream = new FileStream(temporary, FileMode.Create)) iff.Write(stream);
            File.Move(temporary, path, true);
        }
        finally
        {
            if (File.Exists(temporary)) File.Delete(temporary);
        }
    }

    /// <summary>A head shot: draws into a square of the requested size, framing the head from crown to chin.</summary>
    private delegate (int R, int G, int B, int A)[] Shot(int width, int height);

    private static Shot Render(SimAvatar avatar, float yaw)
    {
        var head = Array.FindIndex(avatar.Skeleton.Bones, bone => string.Equals(bone.Name, "HEAD", StringComparison.OrdinalIgnoreCase));
        if (head < 0) throw new InvalidDataException("The Sim skeleton has no head bone");
        // Faces look down +Z in the bind pose; the camera sits in front, a little above eye level.
        var view = Matrix.CreateRotationY(yaw) * Matrix.CreateRotationX(MathHelper.ToRadians(8));
        var triangles = new List<Triangle>();
        var headPoints = new List<Vector3>();
        var textures = new Dictionary<ITextureRef, Texture>();
        foreach (var binding in avatar.Bindings)
        {
            if (binding.Mesh is not { } mesh || binding.Texture is not AbstractTextureRef reference) continue;
            if (!textures.TryGetValue(reference, out var texture)) textures[reference] = texture = Decode(reference.ReadSourceData());
            var points = new Vector3[mesh.VertexBuffer.Length];
            var normals = new Vector3[mesh.VertexBuffer.Length];
            for (var index = 0; index < points.Length; index++)
            {
                var source = mesh.VertexBuffer[index];
                var bone = avatar.Skeleton.Bones[(int)source.Parameters.X].AbsoluteMatrix;
                var position = Vector3.Transform(source.Position, bone);
                var normal = Vector3.TransformNormal(source.Normal, bone);
                if (source.Parameters.Z > 0)
                {
                    var blend = avatar.Skeleton.Bones[(int)source.Parameters.Y].AbsoluteMatrix;
                    position = Vector3.Lerp(position, Vector3.Transform(source.BvPosition, blend), source.Parameters.Z);
                    normal = Vector3.Lerp(normal, Vector3.TransformNormal(source.BvNormal, blend), source.Parameters.Z);
                }
                points[index] = Vector3.Transform(position, view);
                normals[index] = Vector3.Normalize(Vector3.TransformNormal(normal, view));
                if ((int)source.Parameters.X == head) headPoints.Add(points[index]);
            }
            for (var index = 0; index + 2 < mesh.IndexBuffer.Length; index += 3)
            {
                int a = mesh.IndexBuffer[index], b = mesh.IndexBuffer[index + 1], c = mesh.IndexBuffer[index + 2];
                triangles.Add(new Triangle(points[a], points[b], points[c],
                    mesh.VertexBuffer[a].TextureCoordinate, mesh.VertexBuffer[b].TextureCoordinate, mesh.VertexBuffer[c].TextureCoordinate,
                    normals[a], normals[b], normals[c], texture));
            }
        }
        if (headPoints.Count == 0) throw new InvalidDataException("The Sim has no head geometry");
        float left = headPoints.Min(p => p.X), right = headPoints.Max(p => p.X);
        float top = headPoints.Max(p => p.Y), chin = headPoints.Min(p => p.Y);
        var light = Vector3.Normalize(new Vector3(-0.35f, 0.45f, 1));

        return (width, height) =>
        {
            const int Samples = 4;
            int w = width * Samples, h = height * Samples;
            // Crown to chin fills the frame height; the head is centred across it.
            var scale = h / ((top - chin) * 1.04f);
            var centreX = (left + right) / 2;
            var colour = new Vector4[w * h];
            var depth = new float[w * h];
            Array.Fill(depth, float.NegativeInfinity);
            Vector3 Screen(Vector3 p) => new(w / 2f + (p.X - centreX) * scale, (top - p.Y) * scale + h * 0.01f, p.Z);
            foreach (var triangle in triangles)
            {
                Vector3 a = Screen(triangle.A), b = Screen(triangle.B), c = Screen(triangle.C);
                var area = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
                if (MathF.Abs(area) < 1e-6f) continue;
                int minX = Math.Max(0, (int)MathF.Floor(MathF.Min(a.X, MathF.Min(b.X, c.X)))), maxX = Math.Min(w - 1, (int)MathF.Ceiling(MathF.Max(a.X, MathF.Max(b.X, c.X))));
                int minY = Math.Max(0, (int)MathF.Floor(MathF.Min(a.Y, MathF.Min(b.Y, c.Y)))), maxY = Math.Min(h - 1, (int)MathF.Ceiling(MathF.Max(a.Y, MathF.Max(b.Y, c.Y))));
                for (var y = minY; y <= maxY; y++)
                for (var x = minX; x <= maxX; x++)
                {
                    float px = x + 0.5f, py = y + 0.5f;
                    var wa = ((b.X - px) * (c.Y - py) - (b.Y - py) * (c.X - px)) / area;
                    var wb = ((c.X - px) * (a.Y - py) - (c.Y - py) * (a.X - px)) / area;
                    var wc = 1 - wa - wb;
                    if (wa < 0 || wb < 0 || wc < 0) continue;
                    var z = wa * a.Z + wb * b.Z + wc * c.Z;
                    var at = y * w + x;
                    if (z <= depth[at]) continue;
                    var uv = triangle.Ta * wa + triangle.Tb * wb + triangle.Tc * wc;
                    var image = triangle.Image;
                    int tx = Math.Clamp((int)(uv.X * image.Width), 0, image.Width - 1), ty = Math.Clamp((int)(uv.Y * image.Height), 0, image.Height - 1);
                    var texel = (ty * image.Width + tx) * 4;
                    var normal = Vector3.Normalize(triangle.Na * wa + triangle.Nb * wb + triangle.Nc * wc);
                    var shade = Math.Min(1.1f, 0.7f + 0.45f * Math.Max(0, Vector3.Dot(normal, light)));
                    depth[at] = z;
                    colour[at] = new Vector4(image.Rgba[texel] * shade, image.Rgba[texel + 1] * shade, image.Rgba[texel + 2] * shade, 1);
                }
            }
            var result = new (int, int, int, int)[width * height];
            for (var y = 0; y < height; y++)
            for (var x = 0; x < width; x++)
            {
                var sum = Vector4.Zero;
                for (var sy = 0; sy < Samples; sy++)
                for (var sx = 0; sx < Samples; sx++)
                {
                    var sample = colour[(y * Samples + sy) * w + x * Samples + sx];
                    sum += new Vector4(sample.X * sample.W, sample.Y * sample.W, sample.Z * sample.W, sample.W);
                }
                var coverage = sum.W / (Samples * Samples);
                result[y * width + x] = sum.W > 0
                    ? ((int)Math.Min(255, sum.X / sum.W), (int)Math.Min(255, sum.Y / sum.W), (int)Math.Min(255, sum.Z / sum.W), (int)(coverage * 255))
                    : (0, 0, 0, 0);
            }
            return result;
        };
    }

    private static byte[] Strip(Shot shot, int width, int height, int frames, Func<int, (int R, int G, int B)> background)
    {
        var pixels = shot(width, height);
        var rgba = new byte[width * frames * height * 4];
        for (var frame = 0; frame < frames; frame++)
        {
            var back = background(frame);
            for (var y = 0; y < height; y++)
            for (var x = 0; x < width; x++)
                Put(rgba, width * frames, frame * width + x, y, pixels[y * width + x], back);
        }
        return NativeOutfitAuthor.WriteBitmap(width * frames, height, rgba);
    }

    private static byte[] Bordered(Shot shot, int size)
    {
        var pixels = shot(size - 2, size - 2);
        var rgba = new byte[size * size * 4];
        for (var y = 0; y < size; y++)
        for (var x = 0; x < size; x++)
        {
            var edge = x == 0 || y == 0 || x == size - 1 || y == size - 1;
            Put(rgba, size, x, y, edge ? (0, 0, 0, 0) : pixels[(y - 1) * (size - 2) + x - 1], edge ? Edge : Black);
        }
        return NativeOutfitAuthor.WriteBitmap(size, size, rgba);
    }

    private static void Put(byte[] rgba, int width, int x, int y, (int R, int G, int B, int A) pixel, (int R, int G, int B) back)
    {
        var offset = (y * width + x) * 4;
        rgba[offset] = (byte)((pixel.R * pixel.A + back.R * (255 - pixel.A)) / 255);
        rgba[offset + 1] = (byte)((pixel.G * pixel.A + back.G * (255 - pixel.A)) / 255);
        rgba[offset + 2] = (byte)((pixel.B * pixel.A + back.B * (255 - pixel.A)) / 255);
        rgba[offset + 3] = 255;
    }

    /// <summary>Avatar textures are BMPs or uncompressed/RLE truecolour TGAs.</summary>
    private static Texture Decode(byte[] data)
    {
        if (data.Length >= 2 && data[0] == 'B' && data[1] == 'M')
        {
            var (width, height, rgba) = NativeOutfitAuthor.ReadBitmap(data);
            return new Texture(width, height, rgba);
        }
        if (data.Length < 18 || data[2] is not (2 or 10) || data[16] is not (24 or 32)) return new Texture(1, 1, [160, 160, 160, 255]);
        int w = BitConverter.ToUInt16(data, 12), h = BitConverter.ToUInt16(data, 14), bytes = data[16] / 8;
        var topDown = (data[17] & 0x20) != 0;
        var output = new byte[w * h * 4];
        var position = 18 + data[0];
        var pixel = 0;
        void Emit(int at)
        {
            if (pixel >= w * h || at + bytes > data.Length) { pixel++; return; }
            int x = pixel % w, y = pixel / w, row = topDown ? y : h - 1 - y, target = (row * w + x) * 4;
            (output[target], output[target + 1], output[target + 2], output[target + 3]) = (data[at + 2], data[at + 1], data[at], 255);
            pixel++;
        }
        while (pixel < w * h && position < data.Length)
        {
            if (data[2] == 2) { Emit(position); position += bytes; continue; }
            var header = data[position++];
            var count = (header & 0x7F) + 1;
            if ((header & 0x80) != 0) { for (var i = 0; i < count; i++) Emit(position); position += bytes; }
            else for (var i = 0; i < count; i++) { Emit(position); position += bytes; }
        }
        return new Texture(w, h, output);
    }
}
