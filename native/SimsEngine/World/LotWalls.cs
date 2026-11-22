using System.Buffers.Binary;
using SimsEngine.Formats;

namespace SimsEngine.World;

// Arry 2/102 8-byte record: [0] segment mask (0x01 -x, 0x02 -y, 0x04 +x, 0x08 +y, 0x10/0x20 diag), [2..3] styles, [4..7] patterns.
// Arry 12/112 14-byte record: [0] segment mask, [1] flags, [2..3] style0 (uint16), [4..5] style1 (uint16), [6..13] patterns (4x uint16).
public sealed class LotWalls
{
    public const int Size = 64;
    public const int RecordSize = 8;
    public const int AdvancedRecordSize = 14;
    private readonly byte[] records = new byte[Size * Size * RecordSize];
    private readonly byte[] initialRecords = new byte[Size * Size * RecordSize];
    private readonly byte[] advancedFlags = new byte[Size * Size];
    private readonly ushort[] styles0 = new ushort[Size * Size];
    private readonly ushort[] styles1 = new ushort[Size * Size];
    private readonly ushort[] patterns = new ushort[Size * Size * 4];
    private readonly ushort chunkId;
    private readonly ushort advancedChunkId;
    private readonly bool hasAdvanced;
    private readonly LotArray shape;
    private readonly LotArray? advancedShape;

    private LotWalls(ushort chunkId, LotArray shape, ushort advancedChunkId, LotArray? advancedShape)
    {
        this.chunkId = chunkId;
        this.shape = shape;
        this.advancedChunkId = advancedChunkId;
        this.advancedShape = advancedShape;
        hasAdvanced = advancedShape is not null;
    }

    public int Level { get; private init; }

    public static LotWalls Read(IffFile lot, int level)
    {
        var type = ResourceType.Parse("Arry");
        var id = (ushort)(level == 1 ? 2 : 102);
        var advancedId = (ushort)(level == 1 ? 12 : 112);

        LotArray? array = null;
        if (lot.Find(type, id) is { } chunk)
        {
            array = LotArray.Read(lot, chunk);
            if (array.Rows != Size || array.Width != Size || array.ElementSize != RecordSize)
                throw new InvalidDataException($"Wall array {id} is {array.Rows}x{array.Width} of {array.ElementSize}-byte records");
        }

        LotArray? advancedArray = null;
        if (lot.Find(type, advancedId) is { } advancedChunk)
        {
            var candidate = LotArray.Read(lot, advancedChunk);
            if (candidate.Rows == Size && candidate.Width == Size && candidate.ElementSize == AdvancedRecordSize)
                advancedArray = candidate;
        }

        if (array is null && advancedArray is null)
            throw new InvalidDataException($"The lot has no wall array for level {level}");

        var walls = new LotWalls(id, array ?? advancedArray!, advancedId, advancedArray) { Level = level };
        for (var x = 0; x < Size; x++)
        for (var y = 0; y < Size; y++)
        {
            var cellIdx = x * Size + y;
            var recOffset = cellIdx * RecordSize;
            if (array is not null)
                array.Element(x, y).CopyTo(walls.records.AsSpan(recOffset, RecordSize));

            if (advancedArray is not null)
            {
                var adv = advancedArray.Element(x, y);
                walls.advancedFlags[cellIdx] = adv[1];
                walls.styles0[cellIdx] = BinaryPrimitives.ReadUInt16LittleEndian(adv.Slice(2, 2));
                walls.styles1[cellIdx] = BinaryPrimitives.ReadUInt16LittleEndian(adv.Slice(4, 2));
                for (var p = 0; p < 4; p++)
                    walls.patterns[cellIdx * 4 + p] = BinaryPrimitives.ReadUInt16LittleEndian(adv.Slice(6 + p * 2, 2));
                if (array is null)
                {
                    walls.records[recOffset] = adv[0];
                    walls.records[recOffset + 1] = adv[1];
                    walls.records[recOffset + 2] = unchecked((byte)walls.styles0[cellIdx]);
                    walls.records[recOffset + 3] = unchecked((byte)walls.styles1[cellIdx]);
                    for (var p = 0; p < 4; p++)
                        walls.records[recOffset + 4 + p] = unchecked((byte)walls.patterns[cellIdx * 4 + p]);
                }
            }
            else
            {
                walls.styles0[cellIdx] = walls.records[recOffset + 2];
                walls.styles1[cellIdx] = walls.records[recOffset + 3];
                for (var p = 0; p < 4; p++)
                    walls.patterns[cellIdx * 4 + p] = walls.records[recOffset + 4 + p];
            }
        }
        walls.records.AsSpan().CopyTo(walls.initialRecords);
        return walls;
    }

    public Span<byte> this[int x, int y] => records.AsSpan((x * Size + y) * RecordSize, RecordSize);

    public ushort GetStyle(int x, int y, int side)
    {
        if (side is not (0 or 1)) throw new ArgumentOutOfRangeException(nameof(side));
        var cellIdx = x * Size + y;
        var recOffset = cellIdx * RecordSize;
        var byteIdx = recOffset + (side == 0 ? 2 : 3);
        var styleArray = side == 0 ? styles0 : styles1;
        if (records[byteIdx] != initialRecords[byteIdx])
        {
            styleArray[cellIdx] = records[byteIdx];
            initialRecords[byteIdx] = records[byteIdx];
        }
        return styleArray[cellIdx];
    }

    public void SetStyle(int x, int y, int side, ushort value)
    {
        if (side is not (0 or 1)) throw new ArgumentOutOfRangeException(nameof(side));
        var cellIdx = x * Size + y;
        var byteIdx = cellIdx * RecordSize + (side == 0 ? 2 : 3);
        (side == 0 ? styles0 : styles1)[cellIdx] = value;
        var low = unchecked((byte)value);
        records[byteIdx] = low;
        initialRecords[byteIdx] = low;
    }

    public ushort GetPattern(int x, int y, int slot)
    {
        if (slot is < 4 or > 7) throw new ArgumentOutOfRangeException(nameof(slot));
        var cellIdx = x * Size + y;
        var byteIdx = cellIdx * RecordSize + slot;
        var patIdx = cellIdx * 4 + (slot - 4);
        if (records[byteIdx] != initialRecords[byteIdx])
        {
            patterns[patIdx] = records[byteIdx];
            initialRecords[byteIdx] = records[byteIdx];
        }
        return patterns[patIdx];
    }

    public void SetPattern(int x, int y, int slot, ushort value)
    {
        if (slot is < 4 or > 7) throw new ArgumentOutOfRangeException(nameof(slot));
        var cellIdx = x * Size + y;
        var byteIdx = cellIdx * RecordSize + slot;
        patterns[cellIdx * 4 + (slot - 4)] = value;
        var low = unchecked((byte)value);
        records[byteIdx] = low;
        initialRecords[byteIdx] = low;
    }

    private void SyncFromRawRecords()
    {
        for (var cellIdx = 0; cellIdx < Size * Size; cellIdx++)
        {
            var recOffset = cellIdx * RecordSize;
            var curSeg = records[recOffset];
            var initSeg = initialRecords[recOffset];
            if ((curSeg & 4) == 0 && (initSeg & 4) != 0 && records[recOffset + 7] == 0)
                patterns[cellIdx * 4 + 3] = 0;
            if ((curSeg & 8) == 0 && (initSeg & 8) != 0 && records[recOffset + 6] == 0)
                patterns[cellIdx * 4 + 2] = 0;

            if (curSeg == 0 && initSeg != 0 && records.AsSpan(recOffset, RecordSize).IndexOfAnyExcept((byte)0) < 0)
            {
                advancedFlags[cellIdx] = 0;
                styles0[cellIdx] = 0;
                styles1[cellIdx] = 0;
                for (var p = 0; p < 4; p++)
                    patterns[cellIdx * 4 + p] = 0;
                continue;
            }

            if (records[recOffset + 2] != initialRecords[recOffset + 2])
                styles0[cellIdx] = records[recOffset + 2];
            if (records[recOffset + 3] != initialRecords[recOffset + 3])
                styles1[cellIdx] = records[recOffset + 3];
            for (var p = 0; p < 4; p++)
            {
                if (records[recOffset + 4 + p] != initialRecords[recOffset + 4 + p])
                    patterns[cellIdx * 4 + p] = records[recOffset + 4 + p];
            }
        }
    }

    public IffFile WriteTo(IffFile lot)
    {
        SyncFromRawRecords();
        var type = ResourceType.Parse("Arry");
        var baseBody = shape.ToChunkData(records, RecordSize);
        var updated = lot.Find(type, chunkId) is not null
            ? lot.WithChunkDataResized(type, chunkId, baseBody)
            : lot.WithAddedChunk(type, chunkId, baseBody);

        var writeAdvanced = hasAdvanced ||
            styles0.Any(static value => value > byte.MaxValue) ||
            styles1.Any(static value => value > byte.MaxValue) ||
            patterns.Any(static value => value > byte.MaxValue);
        if (writeAdvanced)
        {
            var advData = new byte[Size * Size * AdvancedRecordSize];
            for (var cellIdx = 0; cellIdx < Size * Size; cellIdx++)
            {
                var recOffset = cellIdx * RecordSize;
                var advOffset = cellIdx * AdvancedRecordSize;
                advData[advOffset] = records[recOffset];
                advData[advOffset + 1] = hasAdvanced ? advancedFlags[cellIdx] : records[recOffset + 1];
                BinaryPrimitives.WriteUInt16LittleEndian(advData.AsSpan(advOffset + 2, 2), styles0[cellIdx]);
                BinaryPrimitives.WriteUInt16LittleEndian(advData.AsSpan(advOffset + 4, 2), styles1[cellIdx]);
                for (var p = 0; p < 4; p++)
                    BinaryPrimitives.WriteUInt16LittleEndian(advData.AsSpan(advOffset + 6 + p * 2, 2), patterns[cellIdx * 4 + p]);
            }
            var advBody = (advancedShape ?? shape).ToChunkData(advData, AdvancedRecordSize);
            updated = updated.Find(type, advancedChunkId) is not null
                ? updated.WithChunkDataResized(type, advancedChunkId, advBody)
                : updated.WithAddedChunk(type, advancedChunkId, advBody);
        }

        records.AsSpan().CopyTo(initialRecords);
        return updated;
    }
}
