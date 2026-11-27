using Microsoft.Win32.SafeHandles;

namespace SimsSDL.Core;

public sealed class FARArchive
{
    public readonly record struct Entry(string Name, int Offset, int Size);

    private readonly byte[]? _data;
    private readonly string? _filePath;

    public IReadOnlyDictionary<string, Entry> Entries { get; }

    public FARArchive(string filePath)
    {
        ArgumentException.ThrowIfNullOrEmpty(filePath);
        string fullPath = Path.GetFullPath(filePath);
        using SafeFileHandle handle = File.OpenHandle(
            fullPath,
            FileMode.Open,
            FileAccess.Read,
            FileShare.ReadWrite | FileShare.Delete);

        long fileLength = RandomAccess.GetLength(handle);
        if (fileLength < 16)
            throw new ContentError("Unexpected end of resource");

        Span<byte> header = stackalloc byte[16];
        ReadExact(handle, 0, header);
        if (!header[..8].SequenceEqual("FAR!byAZ"u8) || BinaryPrimitives.ReadUInt32LittleEndian(header.Slice(8, 4)) != 1)
            throw new ContentError("Expected a Sims FAR version 1 archive");

        uint manifestU32 = BinaryPrimitives.ReadUInt32LittleEndian(header.Slice(12, 4));
        if (manifestU32 < 16 || manifestU32 > fileLength - 4)
            throw new ContentError("FAR manifest is outside the file");

        long manifestSizeLong = fileLength - manifestU32;
        if (manifestSizeLong > int.MaxValue)
            throw new ContentError("FAR manifest is outside the file");

        var manifestBytes = new byte[(int)manifestSizeLong];
        ReadExact(handle, manifestU32, manifestBytes);
        Entries = ParseManifest(new SimsBinaryReader(manifestBytes), (int)manifestU32);
        _filePath = fullPath;
    }

    public FARArchive(byte[] data)
    {
        ArgumentNullException.ThrowIfNull(data);

        var reader = new SimsBinaryReader(data);
        if (!reader.Bytes(8).AsSpan().SequenceEqual("FAR!byAZ"u8) || reader.UInt32() != 1)
            throw new ContentError("Expected a Sims FAR version 1 archive");

        uint manifestU32 = reader.UInt32();
        if (manifestU32 < 16 || manifestU32 > (uint)(data.Length - 4))
            throw new ContentError("FAR manifest is outside the file");

        int manifest = (int)manifestU32;
        reader.Offset = manifest;

        _data = data;
        Entries = ParseManifest(reader, manifest);
    }

    private static Dictionary<string, Entry> ParseManifest(SimsBinaryReader reader, int manifest)
    {
        uint countU32 = reader.UInt32();
        if (countU32 > (uint)((reader.Data.Length - reader.Offset) / 17))
            throw new ContentError("FAR entry count exceeds the manifest size");

        int count = (int)countU32;
        var result = new Dictionary<string, Entry>(count, StringComparer.Ordinal);
        for (int i = 0; i < count; i++)
        {
            uint sizeU32 = reader.UInt32();
            uint storedSizeU32 = reader.UInt32();
            uint offsetU32 = reader.UInt32();
            uint lengthU32 = reader.UInt32();
            if (lengthU32 == 0 || lengthU32 > 4096)
                throw new ContentError("Invalid FAR filename length");

            byte[] nameBytes = reader.Bytes((int)lengthU32);
            if (!IsAscii(nameBytes) ||
                sizeU32 != storedSizeU32 ||
                offsetU32 < 16 ||
                offsetU32 > (uint)manifest ||
                sizeU32 > (uint)(manifest - (int)offsetU32))
            {
                throw new ContentError("Unsupported or corrupt FAR entry");
            }

            string name = Encoding.ASCII.GetString(nameBytes);
            string key = ResourceKey(name);
            if (result.ContainsKey(key))
                throw new ContentError($"Duplicate FAR entry: {name}");

            result[key] = new Entry(name, (int)offsetU32, (int)sizeU32);
        }

        return result;
    }

    public byte[] Read(string path)
    {
        string key = ResourceKey(path);
        if (!Entries.TryGetValue(key, out Entry entry))
            throw new ContentError($"Missing archive resource: {path}");

        var output = new byte[entry.Size];
        if (entry.Size == 0)
            return output;

        if (_data is not null)
        {
            Buffer.BlockCopy(_data, entry.Offset, output, 0, entry.Size);
            return output;
        }

        using SafeFileHandle handle = File.OpenHandle(
            _filePath!,
            FileMode.Open,
            FileAccess.Read,
            FileShare.ReadWrite | FileShare.Delete);
        ReadExact(handle, entry.Offset, output);
        return output;
    }

    private static void ReadExact(SafeFileHandle handle, long offset, Span<byte> destination)
    {
        int totalRead = 0;
        while (totalRead < destination.Length)
        {
            int read = RandomAccess.Read(handle, destination[totalRead..], offset + totalRead);
            if (read == 0)
                throw new ContentError("Unexpected end of resource");
            totalRead += read;
        }
    }

    public static string ResourceKey(string path)
    {
        ArgumentNullException.ThrowIfNull(path);

        string normalized = path.Replace('\\', '/');
        string[] parts = normalized.Split('/', StringSplitOptions.None);
        if (parts.Length == 0)
            throw new ContentError($"Unsafe resource path: {path}");

        foreach (string part in parts)
        {
            if (part.Length == 0 || part == "." || part == ".." || part.Contains(':') || part.Contains('\0'))
                throw new ContentError($"Unsafe resource path: {path}");
        }

        return string.Join('/', parts).ToLowerInvariant();
    }

    private static bool IsAscii(byte[] bytes)
    {
        foreach (byte b in bytes)
        {
            if (b > 0x7F)
                return false;
        }
        return true;
    }
}

public sealed class SimsBinaryReader
{
    public byte[] Data { get; }
    public int Offset { get; set; }

    public SimsBinaryReader(byte[] data)
    {
        ArgumentNullException.ThrowIfNull(data);
        Data = data;
    }

    public byte[] Bytes(int count)
    {
        if (count < 0 || Offset < 0 || Offset > Data.Length || count > Data.Length - Offset)
            throw new ContentError("Unexpected end of resource");

        var result = new byte[count];
        Buffer.BlockCopy(Data, Offset, result, 0, count);
        Offset += count;
        return result;
    }

    public uint UInt32()
    {
        if (Offset < 0 || Offset > Data.Length || 4 > Data.Length - Offset)
            throw new ContentError("Unexpected end of resource");

        uint value = BinaryPrimitives.ReadUInt32LittleEndian(Data.AsSpan(Offset, 4));
        Offset += 4;
        return value;
    }
}
