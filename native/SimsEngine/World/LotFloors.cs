using SimsEngine.Formats;
using SimsEngine.Simulation;

namespace SimsEngine.World;

public sealed class LotFloors
{
    public const int Size = 64;
    private readonly ushort[] patterns = new ushort[Size * Size];
    private readonly ushort chunkId;
    private readonly LotArray shape;

    private LotFloors(ushort chunkId, LotArray shape)
    {
        this.chunkId = chunkId;
        this.shape = shape;
    }

    public int Level { get; private init; }

    public bool HasAnyPattern => patterns.Any(static pattern => pattern != 0);

    public static ushort LegacyChunkId(int level) => checked((ushort)((level - 1) * 100 + 1));

    public static ushort AdvancedChunkId(int level) => checked((ushort)((level - 1) * 100 + 11));

    public static bool HasStoredArray(IffFile lot, int level) =>
        level is >= 1 and <= LotGeometry.MaxSupportedStories &&
        (lot.Find(ResourceType.Parse("Arry"), AdvancedChunkId(level)) is not null ||
         lot.Find(ResourceType.Parse("Arry"), LegacyChunkId(level)) is not null);

    public static bool HasNonEmptyFloor(IffFile lot, int level)
    {
        if (!HasStoredArray(lot, level)) return false;
        var type = ResourceType.Parse("Arry");
        foreach (var id in new[] { AdvancedChunkId(level), LegacyChunkId(level) })
        {
            if (lot.Find(type, id) is not { } chunk) continue;
            var array = LotArray.Read(lot, chunk);
            if (array.Rows != Size || array.Width != Size || array.ElementSize is not (1 or 2)) continue;
            return array.Data.AsSpan().IndexOfAnyExcept((byte)0) >= 0;
        }
        return false;
    }

    public static LotFloors Read(IffFile lot, int level)
    {
        if (level is < 1 or > LotGeometry.MaxSupportedStories)
            throw new ArgumentOutOfRangeException(nameof(level), $"Floor level must be between 1 and {LotGeometry.MaxSupportedStories}.");

        var arryType = ResourceType.Parse("Arry");
        var legacyId = LegacyChunkId(level);
        var advancedId = AdvancedChunkId(level);
        foreach (var id in new[] { advancedId, legacyId })
        {
            if (lot.Find(arryType, id) is not { } chunk) continue;
            var array = LotArray.Read(lot, chunk);
            if (array.Rows != Size || array.Width != Size || array.ElementSize is not (1 or 2)) continue;
            var floors = new LotFloors(id, array) { Level = level };
            for (var x = 0; x < Size; x++)
            for (var y = 0; y < Size; y++)
            {
                var element = array.Element(x, y);
                floors.patterns[x * Size + y] = array.ElementSize == 2 ? BitConverter.ToUInt16(element) : element[0];
            }
            return floors;
        }

        if (level >= 2)
        {
            var templateChunk = lot.Find(arryType, 1) ?? lot.Find(arryType, 11) ?? lot.Find(arryType, 2);
            var templateShape = templateChunk is not null
                ? LotArray.Read(lot, templateChunk)
                : LotArray.CreateEmpty(Size, Size, 1);
            if (templateShape.OldLayout || templateShape.Rows != Size || templateShape.Width != Size)
                templateShape = LotArray.CreateEmpty(Size, Size, 1);
            return new LotFloors(legacyId, templateShape) { Level = level };
        }

        throw new InvalidDataException($"The lot has no floor array for level {level}");
    }

    public ushort this[int x, int y]
    {
        get => patterns[x * Size + y];
        set => patterns[x * Size + y] = value;
    }

    public IffFile WriteTo(IffFile lot)
    {
        var elementSize = shape.ElementSize == 2 || patterns.Any(pattern => pattern > byte.MaxValue) ? 2 : 1;
        var targetId = elementSize == 2 ? AdvancedChunkId(Level) : chunkId;
        var data = new byte[Size * Size * elementSize];
        for (var index = 0; index < patterns.Length; index++)
        {
            if (elementSize == 2) BitConverter.TryWriteBytes(data.AsSpan(index * 2), patterns[index]);
            else data[index] = (byte)patterns[index];
        }
        var type = ResourceType.Parse("Arry");
        var body = shape.ToChunkData(data, elementSize);
        return lot.Find(type, targetId) is not null
            ? lot.WithChunkDataResized(type, targetId, body)
            : lot.WithAddedChunk(type, targetId, body);
    }
}
