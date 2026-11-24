namespace SimsEngine.Formats;

public sealed record BhavInstruction(ushort Opcode, byte TrueTarget, byte FalseTarget, byte[] Operand, bool Breakpoint)
{
    public const byte Error = 0xFD, ReturnTrue = 0xFE, ReturnFalse = 0xFF;
}

public sealed class Bhav
{
    public ushort Signature { get; }
    public byte Type { get; }
    public byte StoredArgumentCount { get; }
    public byte StoredLocalCount { get; }
    public uint TreeVersion { get; }
    public IReadOnlyList<BhavInstruction> Instructions { get; }

    public int TrailingBytes { get; }

    public byte ArgumentCount => Signature switch
    {
        < 0x8001 => 4,
        0x8001 => Math.Min(StoredArgumentCount, (byte)4),
        _ => StoredArgumentCount,
    };

    public byte LocalCount => Signature switch
    {
        < 0x8001 => 0,
        0x8001 => Math.Min(StoredLocalCount, (byte)4),
        _ => StoredLocalCount,
    };

    public bool StartsAtCallerInstruction => Type == 4;

    internal Bhav(ushort signature, byte type, byte arguments, byte locals, uint version, IReadOnlyList<BhavInstruction> instructions, int trailing)
    {
        Signature = signature;
        Type = type;
        StoredArgumentCount = arguments;
        StoredLocalCount = locals;
        TreeVersion = version;
        Instructions = instructions;
        TrailingBytes = trailing;
    }

    public static Bhav Read(IffFile file, IffChunk chunk)
    {
        var reader = file.Reader(chunk);
        var signature = reader.U16();
        byte type, arguments, locals;
        uint version;
        int count;
        if (signature == 0x8003)
        {
            type = reader.U8();
            arguments = reader.U8();
            locals = reader.U8();
            version = reader.U32();
            var stored = reader.U32();
            if (stored > short.MaxValue || (long)stored * 12 > reader.Remaining)
            {
                // TSO/Simitone 0x8003 BHAV variants store count big-endian or as a 16-byte header with LE count at offset 12.
                uint bigEndianCount = System.Buffers.Binary.BinaryPrimitives.ReverseEndianness(stored);
                if (bigEndianCount <= short.MaxValue && (long)bigEndianCount * 12 <= reader.Remaining)
                {
                    stored = bigEndianCount;
                }
                else if (chunk.Data.Length >= 16)
                {
                    uint countAt12 = System.Buffers.Binary.BinaryPrimitives.ReadUInt32LittleEndian(chunk.Data.Span.Slice(12, 4));
                    if (countAt12 <= short.MaxValue && 16L + (long)countAt12 * 12 <= chunk.Data.Length)
                    {
                        _ = reader.Bytes(3);
                        stored = countAt12;
                    }
                }
            }
            if (stored > short.MaxValue) throw reader.Error($"instruction count {stored} is above the 32767 the game indexes");
            count = (int)stored;
        }
        else if (signature is >= 0x8000 and <= 0x8002)
        {
            count = reader.S16();
            if (count < 0) throw reader.Error($"negative instruction count {count}");
            type = reader.U8();
            arguments = reader.U8();
            locals = reader.U8();
            reader.U8();
            version = reader.U32();
        }
        else throw reader.Error($"unknown BHAV signature 0x{signature:x4}");
        if ((long)count * 12 > reader.Remaining) throw reader.Error($"{count} instructions need {count * 12} bytes, {reader.Remaining} left");
        var instructions = new BhavInstruction[count];
        for (var index = 0; index < count; index++)
        {
            var opcode = reader.U16();
            var trueTarget = reader.U8();
            var falseTarget = reader.U8();
            instructions[index] = new BhavInstruction((ushort)(opcode & 0x7fff), trueTarget, falseTarget, reader.Bytes(8).ToArray(), (opcode & 0x8000) != 0);
        }
        return new Bhav(signature, type, arguments, locals, version, instructions, reader.Remaining);
    }
}

public sealed record Bcon(bool TuningOverride, IReadOnlyList<short> Constants)
{
    public static Bcon Read(IffFile file, IffChunk chunk)
    {
        var reader = file.Reader(chunk);
        var count = reader.U8();
        var flags = reader.U8();
        var values = new short[count];
        for (var index = 0; index < count; index++) values[index] = reader.S16();
        return new Bcon((flags & 0x80) != 0, values);
    }
}
