using System.Buffers.Binary;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Engine;
using FSO.Content;

internal sealed class PanelResources(string directory)
{
    public record Image(string File, int Columns, int Rows);
    private readonly ConditionalWeakTable<BMP, Image> images = new();
    private readonly ConditionalWeakTable<VMQueuedAction, ActionIdentity> actions = new();
    private sealed record ActionIdentity(string Token);
    private long sequence;

    public string Token(VMQueuedAction action) => actions.GetValue(action, _ => new ActionIdentity((++sequence).ToString())).Token;

    public Image? Portrait(VMAvatar avatar) => Store(avatar.Object.Resource.Get<BMP>(2002), 3, 1);
    public Image? NeighborPortrait(uint guid) => Store(Content.Get().WorldObjects.Get(guid)?.Resource.Get<BMP>(2003), 5, 1);
    public Image? CatalogIcon(GameObject item) => StoreIcon(item.Resource.Get<BMP>(item.OBJ.CatalogStringsID)) ?? RenderedIcon(item);

    private readonly Dictionary<uint, Image?> renderedIcons = new();
    private const int RenderedIconSize = 43;
    private static readonly float MediumUnitHeight = (float)(Math.Sqrt(64 * 64 / 2.0) * Math.Cos(Math.PI / 6));

    /// <summary>
    /// The thumbnail the original catalog shows for an object without a catalog bitmap: its medium-zoom sprites facing
    /// south, every tile of a multi-tile object at its place, scaled down to fit the catalog button.
    /// </summary>
    private Image? RenderedIcon(GameObject item)
    {
        if (renderedIcons.TryGetValue(item.OBJ.GUID, out var cached)) return cached;
        var parts = new List<(GameObject Part, int X, int Y)>();
        if (item.OBJ.MasterID != 0 && item.OBJ.SubIndex == -1)
        {
            foreach (var definition in item.Resource.List<OBJD>() ?? new List<OBJD>())
                if (definition.MasterID == item.OBJ.MasterID && definition.SubIndex != -1 && Content.Get().WorldObjects.Get(definition.GUID) is { } part)
                    parts.Add((part, (sbyte)((ushort)definition.SubIndex >> 8), (sbyte)((ushort)definition.SubIndex & 0xFF)));
        }
        else parts.Add((item, 0, 0));
        const uint south = 0x10;
        var rotation = Microsoft.Xna.Framework.Matrix.CreateRotationZ((float)(Math.Log2(south) * Math.PI / 4));
        var layers = new List<(float Order, int Index, int X, int Y, int Width, int Height, bool Flip, Func<int, int, Microsoft.Xna.Framework.Color> Pixel)>();
        foreach (var (part, tileX, tileY) in parts.OrderBy(part => part.X + part.Y))
        {
            var image = part.Resource.Get<DGRP>(part.OBJ.BaseGraphicID)?.GetImage(south, 2, 0);
            if (image == null) continue;
            for (var index = 0; index < image.Sprites.Length; index++)
            {
                var sprite = image.Sprites[index];
                if (sprite.SpriteID >= part.OBJ.DynamicSpriteBaseId && sprite.SpriteID < part.OBJ.DynamicSpriteBaseId + part.OBJ.NumDynamicSprites) continue;
                int width, height;
                Func<int, int, Microsoft.Xna.Framework.Color> pixel;
                if (part.Resource.Get<SPR2>((ushort)sprite.SpriteID) is { } chunk)
                {
                    if (sprite.SpriteFrameIndex >= chunk.Frames.Length) continue;
                    var frame = chunk.Frames[sprite.SpriteFrameIndex];
                    frame.DecodeIfRequired(false);
                    if (frame.PixelData == null || frame.PixelData.Length != frame.Width * frame.Height) continue;
                    (width, height) = (frame.Width, frame.Height);
                    pixel = (x, y) => frame.PixelData[y * frame.Width + x];
                }
                else if (part.Resource.Get<SPR>((ushort)sprite.SpriteID) is { } legacy && sprite.SpriteFrameIndex < legacy.Frames.Count)
                {
                    var frame = legacy.Frames[(int)sprite.SpriteFrameIndex];
                    frame.DecodeIfRequired();
                    (width, height) = (frame.Width, frame.Height);
                    pixel = frame.GetPixel;
                }
                else continue;
                if (width == 0 || height == 0) continue;
                var offset = Microsoft.Xna.Framework.Vector3.Transform(sprite.ObjectOffset, rotation);
                var x = tileX + offset.X / 16;
                var y = tileY + offset.Y / 16;
                var left = (int)((x - y) * 32 + sprite.SpriteOffset.X);
                var top = (int)((x + y) * 16 - offset.Z / 5 * MediumUnitHeight - height + sprite.SpriteOffset.Y);
                layers.Add((x + y, layers.Count, left, top, width, height, sprite.Flip, pixel));
            }
        }
        Image? result = null;
        if (layers.Count > 0)
        {
            var minX = layers.Min(layer => layer.X);
            var minY = layers.Min(layer => layer.Y);
            var width = layers.Max(layer => layer.X + layer.Width) - minX;
            var height = layers.Max(layer => layer.Y + layer.Height) - minY;
            if (width is > 0 and <= 2048 && height is > 0 and <= 2048)
            {
                var canvas = new Microsoft.Xna.Framework.Color[width * height];
                foreach (var layer in layers.OrderBy(layer => layer.Order).ThenBy(layer => layer.Index))
                    for (var sy = 0; sy < layer.Height; sy++)
                    for (var sx = 0; sx < layer.Width; sx++)
                    {
                        var color = layer.Pixel(layer.Flip ? layer.Width - 1 - sx : sx, sy);
                        if (color.A == 0) continue;
                        var target = (layer.Y - minY + sy) * width + layer.X - minX + sx;
                        canvas[target] = color.A == 255 ? color : Microsoft.Xna.Framework.Color.Lerp(canvas[target], color, color.A / 255f);
                    }
                var scale = Math.Min(1f, RenderedIconSize / (float)Math.Max(width, height));
                var outWidth = Math.Max(1, (int)Math.Round(width * scale));
                var outHeight = Math.Max(1, (int)Math.Round(height * scale));
                result = PatternBitmap(outWidth, outHeight, (ox, oy) => Downsample(canvas, width, height, ox / (float)outWidth, oy / (float)outHeight, 1f / outWidth, 1f / outHeight));
            }
        }
        renderedIcons[item.OBJ.GUID] = result;
        return result;
    }

    /// <summary>The covered pixels of one output pixel averaged; mostly transparent areas stay transparent.</summary>
    private static Microsoft.Xna.Framework.Color Downsample(Microsoft.Xna.Framework.Color[] canvas, int width, int height, float u, float v, float du, float dv)
    {
        int x0 = (int)(u * width), y0 = (int)(v * height);
        int x1 = Math.Max(x0 + 1, (int)((u + du) * width)), y1 = Math.Max(y0 + 1, (int)((v + dv) * height));
        int r = 0, g = 0, b = 0, opaque = 0, total = 0;
        for (var y = y0; y < Math.Min(y1, height); y++)
        for (var x = x0; x < Math.Min(x1, width); x++)
        {
            total++;
            var color = canvas[y * width + x];
            if (color.A == 0) continue;
            r += color.R; g += color.G; b += color.B; opaque++;
        }
        return opaque * 2 < total ? Microsoft.Xna.Framework.Color.Transparent : new Microsoft.Xna.Framework.Color(r / opaque, g / opaque, b / opaque, 255);
    }

    public Image? Icon(VMEntity? entity) => entity switch
    {
        VMAvatar avatar => Portrait(avatar),
        VMGameObject item => StoreIcon(item.Object.Resource.Get<BMP>((item.MasterDefinition ?? item.Object.OBJ).CatalogStringsID)),
        _ => null
    };

    public Image? RoofPattern(uint id) => Store(new BMP { data = NativeRoofGeometry.ReadMaterial(id).Bytes }, 1, 1);

    public Image? FloorPattern(ushort id)
    {
        var frame = id >= 65534 ? Content.Get().WorldFloors.GetGlobalSPR(id == 65535 ? (ushort)0x420 : (ushort)0x800)?.Frames.FirstOrDefault() : Content.Get().WorldFloors.Get(id)?.Near?.Frames.FirstOrDefault();
        if (frame == null) return null;
        frame.DecodeIfRequired(false);
        if (frame.PixelData == null || frame.PixelData.Length != frame.Width * frame.Height) return null;
        return PatternBitmap(frame.Width, frame.Height, (x, y) => frame.PixelData[y * frame.Width + x]);
    }
    public Image? WallStyle(ushort id)
    {
        var bitmap = Content.Get().WorldWalls.GetWallStyleIcon(id);
        return bitmap == null ? null : Store(bitmap, 2, 1);
    }
    public Image? WallPattern(ushort id)
    {
        var frame = Content.Get().WorldWalls.Get(id)?.Medium?.Frames.ElementAtOrDefault(2);
        if (frame == null) return null;
        frame.DecodeIfRequired();
        return PatternBitmap(frame.Width, frame.Height, frame.GetPixel);
    }
    private Image? PatternBitmap(int width, int height, Func<int, int, Microsoft.Xna.Framework.Color> pixelAt)
    {
        if (width is < 1 or > 512 || height is < 1 or > 512) return null;
        using var data = new MemoryStream();
        using var writer = new BinaryWriter(data);
        writer.Write((ushort)0x4d42);
        writer.Write(54 + width * height * 4);
        writer.Write(0);
        writer.Write(54);
        writer.Write(40);
        writer.Write(width);
        writer.Write(-height);
        writer.Write((ushort)1);
        writer.Write((ushort)32);
        writer.Write(0);
        writer.Write(width * height * 4);
        writer.Write(0);
        writer.Write(0);
        writer.Write(0);
        writer.Write(0);
        for (var y = 0; y < height; y++)
        for (var x = 0; x < width; x++)
        {
            var pixel = pixelAt(x, y);
            writer.Write(pixel.A == 0 ? (byte)255 : pixel.B);
            writer.Write(pixel.A == 0 ? (byte)0 : pixel.G);
            writer.Write(pixel.A == 0 ? (byte)255 : pixel.R);
            writer.Write(pixel.A == 0 ? (byte)255 : pixel.A);
        }
        writer.Flush();
        return Store(new BMP { data = data.ToArray() }, 1, 1);
    }

    private Image? StoreIcon(BMP? bitmap)
    {
        var data = bitmap?.data;
        if (data == null || data.Length < 54) return null;
        var width = BinaryPrimitives.ReadInt32LittleEndian(data.AsSpan(18));
        var height = BinaryPrimitives.ReadInt32LittleEndian(data.AsSpan(22));
        return Store(bitmap, width > 0 && height is > -512 and < 512 && width == Math.Abs(height) * 2 ? 2 : 1, 1);
    }

    private Image? Store(BMP? bitmap, int columns, int rows)
    {
        if (bitmap == null) return null;
        if (images.TryGetValue(bitmap, out var existing)) return existing;
        var data = bitmap.data;
        if (data == null || data.Length < 54 || data.Length > 4 * 1024 * 1024 || data[0] != 'B' || data[1] != 'M') return null;
        var width = BinaryPrimitives.ReadInt32LittleEndian(data.AsSpan(18));
        var height = BinaryPrimitives.ReadInt32LittleEndian(data.AsSpan(22));
        if (width < columns || width > 512 || height == 0 || height < -512 || height > 512 || width % columns != 0 || Math.Abs(height) % rows != 0) return null;
        var file = "ui-" + Convert.ToHexString(SHA256.HashData(data)).ToLowerInvariant() + ".bmp";
        Directory.CreateDirectory(directory);
        var path = Path.Combine(directory, file);
        if (!File.Exists(path)) File.WriteAllBytes(path, data);
        var image = new Image(file, columns, rows);
        images.Add(bitmap, image);
        return image;
    }
}
