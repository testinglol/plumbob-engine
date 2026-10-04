using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;

internal static class NativeWaterSurface
{
    public record Topology(int Adjacency, ushort Sprite, ushort[] Corners);
    public record Pixels(byte[] Data, int Width, int Height, Topology Topology);
    private static readonly (int X, int Y)[] Directions = [(0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1)];

    public static Pixels Read(ushort pattern, int x, int y, int width, int height, int cameraOrientation, Func<int, int, ushort> floorAt)
    {
        if (pattern is not (65534 or 65535)) throw new ArgumentException("Expected pool or pond pattern");
        var adjacency = 0;
        for (var index = 0; index < Directions.Length; index++)
        {
            var nx = x + Directions[index].X;
            var ny = y + Directions[index].Y;
            if (nx <= 0 || ny <= 0 || nx >= width - 1 || ny >= height - 1 || floorAt(nx, ny) == pattern) adjacency |= 1 << index;
        }
        adjacency = RotateAdjacency(adjacency, cameraOrientation);
        var variant = ((adjacency & 1) != 0 ? 1 : 0) | ((adjacency & 64) != 0 ? 2 : 0) | ((adjacency & 16) != 0 ? 4 : 0) | ((adjacency & 4) != 0 ? 8 : 0);
        var spriteID = (ushort)((pattern == 65535 ? 0x410 : 0x800) + variant);
        var frame = Frame(spriteID, pattern == 65535 ? 0 : 1);
        var pixels = new byte[frame.Width * frame.Height * 4];
        for (var index = 0; index < frame.PixelData.Length; index++)
        {
            var color = frame.PixelData[index];
            pixels[index * 4] = color.R;
            pixels[index * 4 + 1] = color.G;
            pixels[index * 4 + 2] = color.B;
            pixels[index * 4 + 3] = color.A;
        }
        var corners = new List<ushort>();
        if (pattern == 65535)
        {
            var pairs = new[] { 64 | 1, 64 | 16, 16 | 4, 1 | 4 };
            var diagonal = new[] { 128, 32, 8, 2 };
            for (var index = 0; index < pairs.Length; index++)
            {
                if ((adjacency & pairs[index]) != pairs[index] || (adjacency & diagonal[index]) != 0) continue;
                var cornerID = (ushort)(0x434 + index);
                var corner = Frame(cornerID, 0);
                var px = index is 0 or 2 ? frame.Width / 2 - corner.Width / 2 : index == 1 ? 0 : frame.Width - corner.Width;
                var py = index == 0 ? 0 : index == 2 ? frame.Height - corner.Height : frame.Height / 2 + 1 - corner.Height / 2;
                Composite(pixels, frame.Width, frame.Height, corner, px, py);
                corners.Add(cornerID);
            }
        }
        return new Pixels(pixels, frame.Width, frame.Height, new Topology(adjacency, spriteID, corners.ToArray()));
    }

    private static int RotateAdjacency(int adjacency, int orientation)
    {
        var result = 0;
        for (var index = 0; index < Directions.Length; index++)
        {
            if ((adjacency & (1 << index)) == 0) continue;
            var (x, y) = Directions[index];
            var rotated = (((orientation % 4) + 4) % 4) switch
            {
                0 => (x, y),
                1 => (-y, x),
                2 => (-x, -y),
                _ => (y, -x)
            };
            var target = Array.IndexOf(Directions, rotated);
            if (target >= 0) result |= 1 << target;
        }
        return result;
    }

    private static SPR2Frame Frame(ushort id, int index)
    {
        var sprite = Content.Get().WorldFloors.GetGlobalSPR(id);
        if (sprite == null || index >= sprite.Frames.Length) throw new InvalidDataException($"Missing original water sprite {id}:{index}");
        var frame = sprite.Frames[index];
        frame.DecodeIfRequired(false);
        if (frame.PixelData == null || frame.PixelData.Length != frame.Width * frame.Height) throw new InvalidDataException("Invalid water sprite pixels");
        return frame;
    }

    private static void Composite(byte[] pixels, int width, int height, SPR2Frame frame, int x, int y)
    {
        for (var sy = 0; sy < frame.Height; sy++)
        for (var sx = 0; sx < frame.Width; sx++)
        {
            var dx = x + sx;
            var dy = y + sy;
            if (dx < 0 || dy < 0 || dx >= width || dy >= height) continue;
            var color = frame.PixelData[sy * frame.Width + sx];
            if (color.A == 0) continue;
            var index = (dy * width + dx) * 4;
            var alpha = color.A * 255 + pixels[index + 3] * (255 - color.A);
            var components = new[] { color.R, color.G, color.B };
            for (var channel = 0; channel < 3; channel++) pixels[index + channel] = (byte)((components[channel] * color.A * 255 + pixels[index + channel] * pixels[index + 3] * (255 - color.A) + alpha / 2) / alpha);
            pixels[index + 3] = (byte)((alpha + 127) / 255);
        }
    }
}
