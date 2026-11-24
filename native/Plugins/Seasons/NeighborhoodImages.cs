using System.Numerics;
using SimsNative.Plugins;

namespace Local.Seasons;

public sealed partial class SeasonsPlugin
{
    private PluginImage? backdrop;
    private float? groundMedian;
    private static bool Key(byte[] pixels, int index) => pixels[index * 4] >= 248 && pixels[index * 4 + 1] <= 8 && pixels[index * 4 + 2] >= 248;
    private static Vector3 Color(byte[] pixels, int index) => new Vector3(pixels[index * 4], pixels[index * 4 + 1], pixels[index * 4 + 2]) / 255;
    private static float Luminance(Vector3 color) => Vector3.Dot(color, new(0.299f, 0.587f, 0.114f));
    private static bool Ground(Vector3 color) => (color.Y - color.Z) / Math.Max(color.Y, 0.04f) > 0.3f && color.X < color.Y * 1.25f;
    private static void Set(byte[] pixels, int index, Vector3 color)
    {
        color = Vector3.Clamp(color, Vector3.Zero, Vector3.One) * 255;
        pixels[index * 4] = (byte)MathF.Round(color.X);
        pixels[index * 4 + 1] = (byte)MathF.Round(color.Y);
        pixels[index * 4 + 2] = (byte)MathF.Round(color.Z);
    }
    private static float Median(PluginImage image)
    {
        var values = Enumerable.Range(0, image.Width * image.Height).Where(index => !Key(image.Rgba, index) && Ground(Color(image.Rgba, index)))
            .Select(index => Luminance(Color(image.Rgba, index))).Order().ToArray();
        return values.Length == 0 ? 0.3f : values[values.Length / 2];
    }
    private Vector3? Backdrop(PluginNeighborhoodImage source, int x, int y)
    {
        if (backdrop == null) return null;
        var px = source.X + (x + 0.5f) * source.Scale - 0.5f;
        var py = source.Y + (y + 0.5f) * source.Scale - 0.5f;
        var x0 = (int)MathF.Floor(px); var y0 = (int)MathF.Floor(py);
        if (x0 < 0 || y0 < 0 || x0 + 1 >= backdrop.Width || y0 + 1 >= backdrop.Height) return null;
        Vector3 At(int dx, int dy) => Color(backdrop.Rgba, (y0 + dy) * backdrop.Width + x0 + dx);
        return Vector3.Lerp(Vector3.Lerp(At(0, 0), At(1, 0), px - x0), Vector3.Lerp(At(0, 1), At(1, 1), px - x0), py - y0);
    }
    private static bool[]? Roofs(PluginImage closed, PluginImage? open)
    {
        if (open == null || closed.Width != open.Width || open.Height > closed.Height || closed.Height - open.Height > 16) return null;
        var width = closed.Width; var height = closed.Height; var count = width * height;
        bool Differs(int index, int shift)
        {
            var y = index / width - shift;
            if (y < 0 || y >= open.Height) return false;
            var other = (y * width + index % width) * 4;
            return Enumerable.Range(0, 3).Sum(channel => Math.Abs(closed.Rgba[index * 4 + channel] - open.Rgba[other + channel])) > 24;
        }
        var shift = Enumerable.Range(0, height - open.Height + 1).MinBy(candidate => Enumerable.Range(0, (count + 6) / 7)
            .Select(index => index * 7).Count(index => index < count && !Key(closed.Rgba, index) && Differs(index, candidate)));
        var roof = Enumerable.Range(0, count).Select(index => !Key(closed.Rgba, index) && Differs(index, shift)).ToArray();
        var filled = (bool[])roof.Clone();
        for (var y = 1; y < height - 1; y++) for (var x = 1; x < width - 1; x++)
        {
            var around = 0;
            for (var dy = -1; dy <= 1; dy++) for (var dx = -1; dx <= 1; dx++) if (roof[(y + dy) * width + x + dx]) around++;
            if (around >= 5) filled[y * width + x] = true;
        }
        return filled;
    }
    private enum Kind { Key, Ground, Tree, Water, Other }
    public PluginImage TransformNeighborhoodImage(PluginNeighborhoodImage source, PluginEnvironment environment)
    {
        return source.Image;
    }

    private PluginImage TransformNeighborhoodImageDisabled(PluginNeighborhoodImage source, PluginEnvironment environment)
    {
        var image = source.Image;
        var amount = Math.Min(1, environment.SurfaceAmount);
        var grass = environment.Parameters.TryGetValue("grassQuality", out var gq) ? gq : 0f;
        var bloom = environment.Parameters.TryGetValue("springBloom", out var sb) ? sb : 0f;
        if (environment.SurfaceMode == 0 && grass <= 0.01f && bloom <= 0.01f) return image;
        if (environment.SurfaceMode == 0)
            return SpringOrSummerMap(source, grass, bloom);
        if (amount <= 0) return image;
        if (source.Role == "background")
        {
            backdrop = null;
            groundMedian = Median(image);
            var name = Path.GetFileNameWithoutExtension(source.Resource.Replace('\\', '/'));
            var resource = Assets + "maps/" + name + (environment.SurfaceMode == 1 ? "-autumn.bmp" : "-winter.bmp");
            var resources = System.Text.Json.JsonSerializer.Deserialize<Dictionary<string, string>>(context.ReadPluginData("resources.json"))!;
            if (resources.ContainsKey(resource.ToLowerInvariant()))
            {
                var painted = context.ReadImageResource(resource);
                if (painted.Width != image.Width || painted.Height != image.Height) throw new InvalidDataException("Seasonal map dimensions differ");
                var output = (byte[])image.Rgba.Clone();
                for (var index = 0; index < image.Width * image.Height; index++) Set(output, index, Vector3.Lerp(Color(image.Rgba, index), Color(painted.Rgba, index), amount));
                backdrop = new(image.Width, image.Height, output);
                return backdrop;
            }
        }
        var width = image.Width; var height = image.Height; var count = width * height;
        var color = new Vector3[count]; var lum = new float[count]; var kind = new Kind[count];
        var median = Math.Max(0.001f, groundMedian ?? Median(image));
        for (var index = 0; index < count; index++)
        {
            color[index] = Color(image.Rgba, index); lum[index] = Luminance(color[index]);
            var c = color[index];
            kind[index] = Key(image.Rgba, index) ? Kind.Key : Ground(c) ? lum[index] < 0.78f * median ? Kind.Tree : Kind.Ground
                : c.Z > c.X + 0.08f && c.Z > c.Y ? Kind.Water : Kind.Other;
        }
        for (var pass = 0; pass < 2; pass++)
        {
            var grown = (Kind[])kind.Clone();
            for (var y = 1; y < height - 1; y++) for (var x = 1; x < width - 1; x++)
            {
                var index = y * width + x;
                if (kind[index] == Kind.Ground && lum[index] < 0.95f * median &&
                    (kind[index - 1] == Kind.Tree || kind[index + 1] == Kind.Tree || kind[index - width] == Kind.Tree || kind[index + width] == Kind.Tree)) grown[index] = Kind.Tree;
            }
            kind = grown;
        }
        if (environment.SurfaceMode == 1)
        {
            var autumn = Autumn(source, color, lum, kind, median, amount);
            if (source.Role == "background") backdrop = autumn;
            return autumn;
        }
        bool[] Tops(Kind wanted, float fraction, int least)
        {
            var marked = new bool[count];
            for (var x = 0; x < width; x++) for (var y = 0; y < height;)
            {
                if (kind[y * width + x] != wanted) { y++; continue; }
                var start = y; var last = y;
                while (y < height)
                {
                    if (kind[y * width + x] == wanted) { last = y; y++; }
                    else if (y - last <= 3) y++;
                    else break;
                }
                var run = last - start + 1;
                var marking = Math.Min(run, Math.Max(least, (int)MathF.Round(run * fraction)));
                for (var row = start; row < start + marking; row++) if (kind[row * width + x] == wanted) marked[row * width + x] = true;
                y = last + 1;
            }
            return marked;
        }
        var caps = Tops(Kind.Tree, 0.3f, 1);
        var roofMask = source.Role == "closedLot" ? Roofs(image, source.Alternate) : null;
        var upper = source.Role == "openLot" ? new bool[count] : roofMask ?? Tops(Kind.Other, source.Role == "background" ? 0 : 0.45f, source.Role == "background" ? 2 : 1);
        if (roofMask != null) for (var index = 0; index < count; index++) if (upper[index] && kind[index] != Kind.Key) kind[index] = Kind.Other;
        var bare = (Vector3[])color.Clone(); var snowed = (Vector3[])color.Clone(); var cover = new float[count];
        var snow = new Vector3(0.82f, 0.85f, 0.91f); var shade = new Vector3(0.70f, 0.76f, 0.88f);
        for (var index = 0; index < count; index++)
        {
            var c = color[index]; var l = lum[index];
            if (kind[index] is Kind.Ground or Kind.Tree) bare[index] = c * 0.85f + new Vector3(0.30f, 0.42f, 0.36f) * (0.4f * l);
            switch (kind[index])
            {
                case Kind.Ground:
                    var relief = Math.Clamp(0.8f * (l - median), -0.05f, 0.06f);
                    snowed[index] = snow * (0.88f + relief);
                    if (Backdrop(source, index % width, index / width) is { } painted)
                        snowed[index] = Vector3.Lerp(snowed[index], painted * (1 + 0.4f * relief), Math.Clamp((Luminance(painted) - 0.6f) / 0.15f, 0, 1));
                    cover[index] = 1; break;
                case Kind.Tree: snowed[index] = shade * (0.7f + 0.9f * l); cover[index] = caps[index] ? 0.85f : 0; break;
                case Kind.Other: snowed[index] = snow * (0.62f + l); cover[index] = upper[index] ? 1 : 0; break;
            }
        }
        int Group(int index) => kind[index] switch { Kind.Key or Kind.Water => 0, Kind.Tree => 1, Kind.Other when !upper[index] && lum[index] < 0.8f * median => 3, _ => 2 };
        for (var pass = 0; pass < 3; pass++)
        {
            var next = (float[])cover.Clone(); var nextSnowed = (Vector3[])snowed.Clone();
            for (var y = 0; y < height; y++) for (var x = 0; x < width; x++)
            {
                var index = y * width + x; var own = Group(index);
                if (own != 2 && !(own == 1 && pass == 0)) continue;
                var sum = 0f; var weight = 0f; var shading = Vector3.Zero;
                for (var dy = -1; dy <= 1; dy++) for (var dx = -1; dx <= 1; dx++)
                {
                    if (x + dx < 0 || x + dx >= width || y + dy < 0 || y + dy >= height) continue;
                    var other = index + dy * width + dx;
                    if (Group(other) != own) continue;
                    var w = dx == 0 && dy == 0 ? 4 : dx == 0 || dy == 0 ? 2 : 1;
                    sum += cover[other] * w; shading += snowed[other] * w; weight += w;
                }
                next[index] = sum / weight;
                if (own == 2) nextSnowed[index] = shading / weight;
            }
            cover = next; snowed = nextSnowed;
        }
        var pixels = (byte[])image.Rgba.Clone();
        for (var index = 0; index < count; index++)
        {
            if (Group(index) == 0) continue;
            if (kind[index] == Kind.Other && !upper[index]) cover[index] *= Math.Clamp((lum[index] / median - 0.7f) / 0.4f, 0, 1);
            var winter = Vector3.Clamp(Vector3.Lerp(bare[index], snowed[index], cover[index]), Vector3.Zero, Vector3.One);
            Set(pixels, index, kind[index] == Kind.Ground && Backdrop(source, index % width, index / width) is { } ground
                ? ground : Vector3.Lerp(color[index], winter, amount));
        }
        var result = new PluginImage(width, height, pixels);
        if (source.Role == "background") backdrop = result;
        return result;
    }
    private static float Noise(int x, int y, float size, uint seed)
    {
        float Hash(int i, int j)
        {
            unchecked { var h = (uint)(i * 73856093 ^ j * 19349663) ^ seed; h = (h ^ (h >> 13)) * 1274126177; return ((h ^ (h >> 16)) & 0xffff) / 65535f; }
        }
        var px = x / size; var py = y / size; var i = (int)MathF.Floor(px); var j = (int)MathF.Floor(py);
        var fx = px - i; var fy = py - j; fx = fx * fx * (3 - 2 * fx); fy = fy * fy * (3 - 2 * fy);
        var top = Hash(i, j) + (Hash(i + 1, j) - Hash(i, j)) * fx;
        var bottom = Hash(i, j + 1) + (Hash(i + 1, j + 1) - Hash(i, j + 1)) * fx;
        return top + (bottom - top) * fy;
    }
    private PluginImage Autumn(PluginNeighborhoodImage source, Vector3[] colors, float[] lum, Kind[] kind, float median, float amount)
    {
        var image = source.Image; var output = (byte[])image.Rgba.Clone();
        for (var index = 0; index < kind.Length; index++)
        {
            var x = index % image.Width; var y = index / image.Width; var l = lum[index]; Vector3 result;
            if (kind[index] == Kind.Ground)
            {
                var relief = Math.Clamp(0.8f * (l - median), -0.06f, 0.06f);
                var dry = Vector3.Lerp(new(0.70f, 0.56f, 0.30f), new(0.66f, 0.38f, 0.16f), Math.Max(0, Noise(x, y, 9, 0x9e37) * 1.6f - 0.8f));
                result = dry * (0.82f + relief * 2);
                if (Backdrop(source, x, y) is { } painted)
                {
                    var weight = Math.Clamp((Luminance(painted) - 0.25f) / 0.1f, 0, 1) * Math.Clamp((painted.X - painted.Z - 0.05f) / 0.1f, 0, 1);
                    result = Vector3.Lerp(result, painted * (1 + relief), weight);
                }
            }
            else if (kind[index] == Kind.Tree)
            {
                var shading = Math.Clamp(l / (0.6f * median), 0.52f, 1.45f);
                var n = Noise(x, y, 6, 0x51ed);
                var gold = new Vector3(0.74f, 0.59f, 0.20f);
                var amber = new Vector3(0.68f, 0.43f, 0.16f);
                var russet = new Vector3(0.50f, 0.30f, 0.15f);
                var tone = n < 0.58f
                    ? Vector3.Lerp(gold, amber, n / 0.58f)
                    : Vector3.Lerp(amber, russet, (n - 0.58f) / 0.42f);
                result = tone * 0.88f * shading;
            }
            else continue;
            Set(output, index, kind[index] == Kind.Ground && Backdrop(source, x, y) is { } ground
                ? ground : Vector3.Lerp(colors[index], Vector3.Clamp(result, Vector3.Zero, Vector3.One), amount));
        }
        return new(image.Width, image.Height, output);
    }

    private PluginImage SpringOrSummerMap(PluginNeighborhoodImage source, float grassQuality, float springBloom)
    {
        var image = source.Image;
        var width = image.Width;
        var height = image.Height;
        var count = width * height;
        var median = Math.Max(0.001f, groundMedian ?? Median(image));
        if (source.Role == "background") groundMedian = median;
        var output = (byte[])image.Rgba.Clone();
        for (var index = 0; index < count; index++)
        {
            if (Key(image.Rgba, index)) continue;
            var c = Color(image.Rgba, index);
            if (!Ground(c)) continue;
            var l = Luminance(c);
            if (grassQuality > 0.1f)
            {
                var lush = Vector3.Lerp(c, new Vector3(0.24f, 0.44f, 0.16f) * Math.Clamp(l / Math.Max(median, 0.2f), 0.78f, 1.24f), 0.35f * grassQuality);
                if (springBloom > 0.1f)
                    lush = Vector3.Lerp(lush, lush * new Vector3(0.96f, 1.05f, 0.92f), 0.5f * Math.Clamp(springBloom, 0f, 1f));
                Set(output, index, lush);
            }
        }
        return new(width, height, output);
    }
}
