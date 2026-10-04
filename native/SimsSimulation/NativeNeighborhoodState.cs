using System.Buffers.Binary;
using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;

internal static class NativeNeighborhoodState
{
    internal sealed record TypeAttribute(uint GUID, short[] Values);

    internal static TypeAttribute[] SaveTypeAttributes() => Content.Get().Neighborhood.TypeAttributes.TypeAttributesByGUID
        .OrderBy(item => item.Key).Select(item => new TypeAttribute(item.Key, item.Value.ToArray())).ToArray();

    internal static void ValidateTypeAttributes(TypeAttribute[]? attributes)
    {
        if (attributes == null) return;
        if (attributes.Length > 32768 || attributes.Any(item => item == null || item.Values == null || item.Values.Length > 32768) ||
            attributes.Select(item => item.GUID).Distinct().Count() != attributes.Length ||
            attributes.Sum(item => (long)item.Values.Length) > 1024 * 1024)
            throw new InvalidDataException("Invalid neighborhood type-attribute snapshot");
    }

    internal static void RestoreTypeAttributes(TypeAttribute[]? attributes)
    {
        ValidateTypeAttributes(attributes);
        if (attributes == null) return;
        Content.Get().Neighborhood.TypeAttributes.TypeAttributesByGUID = attributes.ToDictionary(item => item.GUID, item => item.Values.ToArray());
    }

    internal static string Save()
    {
        using var data = new MemoryStream();
        Content.Get().Neighborhood.Neighbors.Write(null, data);
        return Convert.ToBase64String(data.ToArray());
    }

    internal static NBRS Decode(string state)
    {
        var bytes = Convert.FromBase64String(state);
        if (bytes.Length is < 16 or > 32 * 1024 * 1024 || !bytes.AsSpan(8, 4).SequenceEqual("SRBN"u8) ||
            BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(12, 4)) > 32768)
            throw new InvalidDataException("Invalid neighborhood save snapshot");
        using var data = new MemoryStream(bytes);
        var neighbors = new NBRS();
        neighbors.Read(null, data);
        if (data.Position != data.Length || neighbors.Entries.Count != BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(12, 4)) ||
            neighbors.Entries.Any(neighbor => neighbor.Unknown1 <= 0 ||
            neighbor.Relationships.Count > 32768 || neighbor.Relationships.Values.Any(values => values.Count > 1024)))
            throw new InvalidDataException("Invalid neighborhood relationship snapshot");
        return neighbors;
    }

    internal static void Restore(string state)
    {
        var saved = Decode(state);
        var current = Content.Get().Neighborhood.Neighbors;
        current.Entries = saved.Entries;
        current.NeighbourByID = saved.NeighbourByID;
        current.DefaultNeighbourByGUID = saved.DefaultNeighbourByGUID;
        current.Version = saved.Version;
    }
}
