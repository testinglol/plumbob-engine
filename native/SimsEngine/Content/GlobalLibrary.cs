using SimsEngine.Formats;
using System.Collections.Concurrent;
using System.Runtime.CompilerServices;

namespace SimsEngine.Content;

public enum TreeScope
{
    Primitive,
    Global,
    Private,
    SemiGlobal,
}

public sealed record BehaviorScope(IffFile Global, IffFile Private, IffFile? SemiGlobal) : Simulation.ITreeTable
{
    private static readonly ConditionalWeakTable<IffFile, Dictionary<ushort, short[]>> ConstantOverrides = new();
    private static readonly ConditionalWeakTable<IffFile, ConcurrentDictionary<ushort, Bhav?>> BhavCache = new();
    private static readonly ConditionalWeakTable<IffFile, ConcurrentDictionary<ushort, Bcon?>> BconCache = new();
    public int? ObjectKey { get; init; }
    public ushort AnimationTableId { get; init; }
    private static readonly StringComparison[] NamePasses =
    [
        StringComparison.OrdinalIgnoreCase,
        StringComparison.OrdinalIgnoreCase,
    ];
    public static TreeScope ScopeOf(short id) => id switch
    {
        >= 0x100 and < 0x1000 => TreeScope.Global,
        >= 0x1000 and < 0x2000 => TreeScope.Private,
        >= 0x2000 and < 0x2329 => TreeScope.SemiGlobal,
        _ => TreeScope.Primitive,
    };

    public IffFile? FileFor(short id) => ScopeOf(id) switch
    {
        TreeScope.Global => Global,
        TreeScope.Private => Private,
        TreeScope.SemiGlobal => SemiGlobal,
        _ => null,
    };

    private static readonly HashSet<string> LoggedMalformedChunks = new(StringComparer.OrdinalIgnoreCase);

    private static void LogMalformedChunkOnce(IffFile file, string kind, ushort id, Exception error)
    {
        string key = $"{file.Source}#{kind}:{id}";
        lock (LoggedMalformedChunks)
        {
            if (!LoggedMalformedChunks.Add(key))
                return;
        }
        Console.Error.WriteLine($"Native content: skipping malformed {kind} #{id} in {file.Source}: {error.Message}");
    }

    public byte[]? StringTableBytes(short treeId, ushort tableId, int oneBasedIndex, byte language)
    {
        var file = FileFor(treeId);
        if (oneBasedIndex <= 0 || file is null) return null;
        var chunk = file.Find(ResourceType.Str, tableId) ?? file.Find(ResourceType.Ctss, tableId);
        if (chunk is null) return null;

        try
        {
            var table = StringTable.Read(file, chunk);
            if (!table.ReadBySimsExe) return null;
            var strings = table.ForLanguage(language);
            return oneBasedIndex <= strings.Count
                ? ResourceReader.EncodingForLanguage(language == 0 ? (byte)1 : language).GetBytes(strings[oneBasedIndex - 1])
                : null;
        }
        catch (ResourceFormatException error)
        {
            LogMalformedChunkOnce(file, "STR#", tableId, error);
            return null;
        }
    }

    public Bhav? Find(short id)
    {
        var file = FileFor(id);
        if (file is null) return null;
        var uid = (ushort)id;
        var cache = BhavCache.GetOrCreateValue(file);
        if (cache.TryGetValue(uid, out var cached)) return cached;
        var chunk = file.Find(ResourceType.Bhav, uid);
        if (chunk is null)
        {
            cache.TryAdd(uid, null);
            return null;
        }
        try
        {
            var decoded = UpgradeVanillaBehavior(file, uid, Bhav.Read(file, chunk));
            cache.TryAdd(uid, decoded);
            return decoded;
        }
        catch (ResourceFormatException error)
        {
            LogMalformedChunkOnce(file, "BHAV", uid, error);
            cache.TryAdd(uid, null);
            return null;
        }
    }

    public IReadOnlyList<short>? Constants(ushort id, bool allowTuningOverride = false)
    {
        var file = id switch
        {
            >= 0x1000 and < 0x2000 => Private,
            >= 0x2000 and < 0x2329 => SemiGlobal,
            >= 0x100 and < 0x1000 => Global,
            _ => null,
        };
        if (file is null) return null;
        var cache = BconCache.GetOrCreateValue(file);
        if (!cache.TryGetValue(id, out var bcon))
        {
            var chunk = file.Find(ResourceType.Bcon, id);
            if (chunk is null)
            {
                cache.TryAdd(id, null);
                return null;
            }
            try
            {
                bcon = Bcon.Read(file, chunk);
                cache.TryAdd(id, bcon);
            }
            catch (ResourceFormatException error)
            {
                LogMalformedChunkOnce(file, "BCON", id, error);
                cache.TryAdd(id, null);
                return null;
            }
        }
        if (bcon is null) return null;
        if (allowTuningOverride && bcon.TuningOverride && ReferenceEquals(file, Private) &&
            ConstantOverrides.TryGetValue(Private, out var overrides))
        {
            lock (overrides)
                if (overrides.TryGetValue(id, out var values)) return values;
        }
        return bcon.Constants;
    }

    public void SetConstantOverride(ushort id, IReadOnlyList<short>? values)
        => SetConstantOverrideForFile(Private, id, values);

    internal static void SetConstantOverrideForFile(IffFile privateFile, ushort id, IReadOnlyList<short>? values)
    {
        var overrides = ConstantOverrides.GetOrCreateValue(privateFile);
        lock (overrides)
        {
            if (values is null) overrides.Remove(id);
            else overrides[id] = values.ToArray();
        }
    }

    public void ClearConstantOverrides()
        => ClearConstantOverridesForFile(Private);

    internal static void ClearConstantOverridesForFile(IffFile privateFile)
    {
        if (!ConstantOverrides.TryGetValue(privateFile, out var overrides)) return;
        lock (overrides) overrides.Clear();
    }

    public short FindNamedTree(string name)
    {
        if (string.IsNullOrEmpty(name)) return 0;
        var files = new[] { Private, SemiGlobal, Global };
        foreach (var comparison in NamePasses)
        foreach (var file in files)
        {
            if (file is null) continue;
            var chunk = file.OfType(ResourceType.Bhav)
                .FirstOrDefault(candidate => string.Equals(candidate.Label, name, comparison));
            if (chunk is not null) return (short)chunk.Id;
        }
        return 0;
    }

    private static bool IsVanillaRoachesFile(IffFile file) =>
        file.Find(ResourceType.Objd, 16807) is { Data.Length: >= 32 } objd &&
        System.Buffers.Binary.BinaryPrimitives.ReadUInt32LittleEndian(objd.Data.Span.Slice(28, 4)) == 0x4415A98Eu;

    private static Bhav UpgradeVanillaBehavior(IffFile file, ushort id, Bhav decoded)
    {
        if (id is not (4097 or 4098) || !IsVanillaRoachesFile(file)) return decoded;

        if (id == 4098 &&
            decoded.Instructions.Count == 1 &&
            decoded.Instructions[0].Opcode == 2 &&
            decoded.Instructions[0].TrueTarget == BhavInstruction.ReturnTrue &&
            decoded.Instructions[0].FalseTarget == BhavInstruction.ReturnFalse)
        {
            BhavInstruction[] checkInstructions =
            [
                new(2, BhavInstruction.ReturnFalse, 1, [0x02, 0x00, 0x01, 0x00, 0x00, 0x02, 0x01, 0x07], false),
                new(2, BhavInstruction.ReturnTrue, 2, [0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 0x09, 0x07], false),
                new(321, BhavInstruction.ReturnTrue, BhavInstruction.ReturnFalse, [0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff], false),
            ];
            return new Bhav(decoded.Signature, decoded.Type, decoded.StoredArgumentCount, decoded.StoredLocalCount,
                decoded.TreeVersion, checkInstructions, decoded.TrailingBytes);
        }

        if (id == 4097 &&
            decoded.Instructions.Count == 18 &&
            decoded.Instructions[0].Opcode == 27 &&
            decoded.Instructions[8].Opcode == 2 &&
            decoded.Instructions[9].Opcode == 281 &&
            decoded.Instructions[10].Opcode == 44 &&
            decoded.Instructions[10].TrueTarget == BhavInstruction.ReturnTrue)
        {
            var instructions = new BhavInstruction[38];
            for (var i = 0; i < 18; i++) instructions[i] = decoded.Instructions[i];
            instructions[0] = instructions[0] with { TrueTarget = 18, FalseTarget = 19 };
            instructions[3] = new(2, 1, BhavInstruction.Error, [0x00, 0x00, 0x5e, 0x01, 0x00, 0x07, 0x19, 0x07], false);
            instructions[8] = instructions[8] with { TrueTarget = 9, FalseTarget = 23 };
            instructions[9] = instructions[9] with { TrueTarget = 25, FalseTarget = 4 };
            instructions[10] = instructions[10] with { TrueTarget = 24, FalseTarget = 10 };
            instructions[18] = new(288, BhavInstruction.ReturnTrue, 21, [0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff], false);
            instructions[19] = new(45, 18, 20, [0x04, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00], false);
            instructions[20] = new(27, 18, BhavInstruction.ReturnFalse, [0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x04, 0x00], false);
            instructions[21] = new(2, BhavInstruction.ReturnTrue, 22, [0x02, 0x00, 0x01, 0x00, 0x00, 0x02, 0x01, 0x07], false);
            instructions[22] = new(272, 2, BhavInstruction.Error, [0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff], false);
            instructions[23] = new(2, 10, BhavInstruction.Error, [0x22, 0x00, 0x01, 0x00, 0x00, 0x05, 0x04, 0x07], false);
            instructions[24] = new(2, 26, BhavInstruction.Error, [0x02, 0x00, 0x01, 0x00, 0x00, 0x05, 0x01, 0x07], false);
            instructions[25] = new(2, 34, BhavInstruction.Error, [0x22, 0x00, 0x01, 0x00, 0x00, 0x05, 0x04, 0x07], false);
            instructions[26] = new(273, 27, BhavInstruction.Error, [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00], false);
            instructions[27] = new(2, 28, BhavInstruction.ReturnTrue, [0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x07], false);
            instructions[28] = new(2, 29, BhavInstruction.Error, [0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x0a, 0x07], false);
            instructions[29] = new(31, 30, BhavInstruction.ReturnTrue, [0x8e, 0xa9, 0x15, 0x44, 0x84, 0x0a, 0x00, 0x00], false);
            instructions[30] = new(2, 29, 35, [0x02, 0x00, 0x01, 0x00, 0x00, 0x02, 0x01, 0x07], false);
            instructions[31] = new(2, 32, BhavInstruction.Error, [0x02, 0x00, 0x00, 0x00, 0x00, 0x05, 0x19, 0x0a], false);
            instructions[32] = new(2, 33, BhavInstruction.Error, [0x00, 0x00, 0x0b, 0x00, 0x00, 0x05, 0x0a, 0x03], false);
            instructions[33] = new(13, BhavInstruction.ReturnTrue, BhavInstruction.ReturnTrue, [0x01, 0x02, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00], false);
            instructions[34] = new(44, 36, 34, [0x0d, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00], false);
            instructions[35] = new(288, 29, 31, [0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff], false);
            instructions[36] = new(2, 37, BhavInstruction.Error, [0x02, 0x00, 0x01, 0x00, 0x00, 0x05, 0x01, 0x07], false);
            instructions[37] = new(273, BhavInstruction.ReturnTrue, BhavInstruction.Error, [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00], false);
            return new Bhav(decoded.Signature, decoded.Type, decoded.StoredArgumentCount, decoded.StoredLocalCount,
                decoded.TreeVersion, instructions, decoded.TrailingBytes);
        }

        return decoded;
    }
}

public sealed class GlobalLibrary
{
    private readonly Dictionary<string, IffFile?> _files = new(StringComparer.OrdinalIgnoreCase);
    private readonly Dictionary<string, Func<ReadOnlyMemory<byte>>> _sources = new(StringComparer.OrdinalIgnoreCase);

    public string? Folder { get; }
    public IffFile? Global { get; }
    public List<(string Name, string Error)> Missing { get; } = new();

    private GlobalLibrary(string? folder)
    {
        Folder = folder;
        if (folder is null) return;
        foreach (var path in Directory.EnumerateFiles(folder).Order(StringComparer.OrdinalIgnoreCase))
        {
            if (path.EndsWith(".far", StringComparison.OrdinalIgnoreCase))
            {
                var archive = FarArchive.Open(path);
                foreach (var entry in archive.Entries)
                    _sources.TryAdd(Path.GetFileName(entry.Name.Replace('\\', '/')), () => archive.Read(entry));
            }
            else _sources[Path.GetFileName(path)] = () => File.ReadAllBytes(path);
        }
        Global = Load("Global");
    }

    public static GlobalLibrary Open(string game) => new(
        ObjectRegistry.Resolve(game, @"GameData\Global") ?? ObjectRegistry.Resolve(game, "Global"));

    public IffFile? Load(string name)
    {
        if (string.IsNullOrWhiteSpace(name)) return null;
        var key = Path.HasExtension(name) ? name : name + ".iff";
        if (_files.TryGetValue(key, out var file)) return file;
        if (!_sources.TryGetValue(key, out var source)) { Missing.Add((name, "not found")); return _files[key] = null; }
        try { file = new IffFile(source(), key); }
        catch (ResourceFormatException error) { Missing.Add((name, error.Message)); file = null; }
        return _files[key] = file;
    }

    public BehaviorScope? ScopeOf(ObjectEntry entry) =>
        Global is null ? null : new BehaviorScope(Global, entry.File, entry.SemiGlobal is { } name ? Load(name) : null)
        {
            ObjectKey = unchecked((int)entry.Guid),
            AnimationTableId = entry.Definition[ObjdField.AnimTableId],
        };
}
