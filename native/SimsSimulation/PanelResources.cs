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
    public Image? CatalogIcon(GameObject item) => StoreIcon(item.Resource.Get<BMP>(item.OBJ.CatalogStringsID));

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
