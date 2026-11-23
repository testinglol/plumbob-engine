using System.Buffers.Binary;
using System.Text;
using System.Text.Json;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;

namespace SimsSimulation;

internal sealed record CensusFileInput(string ScopeKind, string Source, IffFile File, string? SemiGlobal = null);

internal sealed record CensusSample(string Source, short TreeId, string TreeLabel, int Instruction, string OperandHex);

internal sealed record CensusSubModeCount(string Key, int Count, IReadOnlyList<CensusSample> Samples);

internal sealed record CensusOpcodeSummary(ushort Opcode, string Name, int Count, bool Known,
    IReadOnlyList<CensusSubModeCount> SubModes);

internal sealed record CensusReferenceIssue(string Kind, string Source, short OwnerId, string OwnerLabel,
    int Instruction, ushort TargetId, string Detail);

internal sealed record CensusReport(
    int FilesScanned,
    int GlobalFilesScanned,
    int SemiGlobalFilesScanned,
    int PrivateFilesScanned,
    int BhavTreesScanned,
    int InstructionsScanned,
    int PrimitiveInstructions,
    int TreeCallInstructions,
    int ObjectsAudited,
    int InteractionsAudited,
    IReadOnlyList<CensusOpcodeSummary> Opcodes,
    IReadOnlyList<CensusOpcodeSummary> UnknownOpcodes,
    IReadOnlyList<CensusReferenceIssue> InvalidGenericCalls,
    IReadOnlyList<CensusReferenceIssue> MissingTreeReferences,
    IReadOnlyList<CensusReferenceIssue> MalformedChunks);

internal static class InteractionCensus
{
    private const int MaxSamplesPerKey = 3;

    private static readonly HashSet<ushort> KnownPrimitiveOpcodes =
    [
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33,
    ];

    private static readonly Dictionary<ushort, string> PrimitiveNames = new()
    {
        [0x00] = "Sleep",
        [0x01] = "GenericSimsCall",
        [0x02] = "Expression",
        [0x03] = "FindBestInteraction",
        [0x04] = "Grab",
        [0x05] = "Drop",
        [0x06] = "ChangeSuitAccessory",
        [0x07] = "Refresh",
        [0x08] = "RandomNumber",
        [0x09] = "Burn",
        [0x0a] = "Tutorial",
        [0x0b] = "GetDistanceTo",
        [0x0c] = "GetDirectionTo",
        [0x0d] = "PushInteraction",
        [0x0e] = "FindBestObjectForFunction",
        [0x0f] = "Breakpoint",
        [0x10] = "FindLocationFor",
        [0x11] = "IdleForInput",
        [0x12] = "RemoveObjectInstance",
        [0x13] = "MakeNewCharacter",
        [0x14] = "RunFunctionalTree",
        [0x15] = "ShowString",
        [0x16] = "LookTowards",
        [0x17] = "PlaySoundEvent",
        [0x18] = "OldRelationship",
        [0x19] = "AlterBudget",
        [0x1a] = "Relationship",
        [0x1b] = "GoToRelativePosition",
        [0x1c] = "RunTreeByName",
        [0x1d] = "SetMotiveChange",
        [0x1e] = "GosubFoundAction",
        [0x1f] = "SetToNext",
        [0x20] = "TestObjectType",
        [0x21] = "Find5WorstMotives",
        [0x22] = "UiEffect",
        [0x23] = "SpecialEffect",
        [0x24] = "Dialog",
        [0x25] = "TestSimInteractingWith",
        [0x29] = "SetBalloonHeadline",
        [0x2a] = "CreateObjectInstance",
        [0x2b] = "DropOnto",
        [0x2c] = "AnimateSim",
        [0x2d] = "GoToRoutingSlot",
        [0x2e] = "Snapshot",
        [0x2f] = "ReachPut",
        [0x30] = "StopAllSounds",
        [0x31] = "NotifyStackObjectOutOfRoom",
        [0x32] = "ChangeActionString",
        [0x33] = "ManageInventory",
    };

    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        WriteIndented = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
    };

    public static string PrimitiveName(ushort opcode) =>
        PrimitiveNames.TryGetValue(opcode, out var name) ? name : $"Unknown_0x{opcode:X2}";

    public static string DescribeSubMode(ushort opcode, ReadOnlySpan<byte> operand)
    {
        if (operand.Length < 8) return "short-operand";
        return opcode switch
        {
            0x01 => $"call=0x{BinaryPrimitives.ReadInt16LittleEndian(operand):X2}",
            0x02 => $"op={operand[5]} lhs={(sbyte)operand[6]} rhs={(sbyte)operand[7]}",
            0x06 => $"mode={operand[4]} flags=0x{operand[5]:X2}",
            0x0d => $"flags=0x{operand[4]:X2} prio={operand[2]}",
            0x10 => $"mode={operand[0]} flags=0x{operand[2]:X2}",
            0x14 => $"fn={BinaryPrimitives.ReadInt16LittleEndian(operand)} flags=0x{operand[2]:X2}",
            0x18 or 0x1a => $"op={operand[0]} flags=0x{operand[2]:X2}",
            0x1b => $"dir={(sbyte)operand[2]} face={(sbyte)operand[3]} flags=0x{operand[6]:X2}",
            0x1f => $"mode={operand[4] & 0x7f} var={((operand[4] & 0x80) != 0 ? 1 : 0)}",
            0x22 => $"kind={operand[0]} flag={operand[4] & 1}",
            0x23 => $"flags=0x{operand[4]:X2}",
            0x24 => $"type=0x{operand[5] & 0x7f:X2} nonblock={((operand[7] & 0x80) != 0 ? 1 : 0)}",
            0x29 => $"flags=0x{operand[4]:X2} mode={operand[5]}",
            0x2a => $"mode={operand[4]} flags=0x{operand[5]:X2}",
            0x2c => $"src={operand[4]} flags=0x{operand[5]:X2}",
            0x2d => $"mode={BinaryPrimitives.ReadInt16LittleEndian(operand.Slice(2, 2))} flags=0x{operand[4]:X2}",
            0x2f => $"mode={operand[0]} flags=0x{operand[2]:X2}",
            0x33 => $"op={operand[0]} flags=0x{BinaryPrimitives.ReadUInt16LittleEndian(operand.Slice(2, 2)):X4}",
            _ => "default",
        };
    }

    public static CensusReport Run(string gameRoot, string? outputDir = null)
    {
        var fullGame = Path.GetFullPath(gameRoot);
        var registry = ObjectRegistry.Scan(fullGame);
        var library = WorldBootstrap.GetOrLoadGlobalLibrary(fullGame);

        var inputs = new List<CensusFileInput>();
        var seenFiles = new HashSet<IffFile>(ReferenceEqualityComparer.Instance);

        if (library.Global is { } globalFile && seenFiles.Add(globalFile))
            inputs.Add(new CensusFileInput("Global", globalFile.Source, globalFile));

        if (library.Folder is { } folder && Directory.Exists(folder))
        {
            foreach (var path in Directory.EnumerateFiles(folder).Order(StringComparer.OrdinalIgnoreCase))
            {
                if (path.EndsWith(".far", StringComparison.OrdinalIgnoreCase))
                {
                    var archive = FarArchive.Open(path);
                    foreach (var entry in archive.Entries)
                    {
                        var name = Path.GetFileName(entry.Name.Replace('\\', '/'));
                        if (!name.EndsWith(".iff", StringComparison.OrdinalIgnoreCase)) continue;
                        if (library.Load(name) is { } semi && seenFiles.Add(semi))
                            inputs.Add(new CensusFileInput("SemiGlobal", semi.Source, semi));
                    }
                }
                else if (path.EndsWith(".iff", StringComparison.OrdinalIgnoreCase))
                {
                    if (library.Load(Path.GetFileName(path)) is { } semi && seenFiles.Add(semi))
                        inputs.Add(new CensusFileInput("SemiGlobal", semi.Source, semi));
                }
            }
        }

        foreach (var entry in registry.Entries)
        {
            if (seenFiles.Add(entry.File))
                inputs.Add(new CensusFileInput(entry.Scan.ToString(), entry.Source, entry.File, entry.SemiGlobal));
        }

        var report = Analyze(inputs, library.Global, name => library.Load(name), registry.Entries);

        if (!string.IsNullOrWhiteSpace(outputDir))
        {
            var fullOut = Path.GetFullPath(outputDir);
            Directory.CreateDirectory(fullOut);
            File.WriteAllText(Path.Combine(fullOut, "census.json"), JsonSerializer.Serialize(report, JsonOptions));
            File.WriteAllText(Path.Combine(fullOut, "census_summary.txt"), FormatSummary(report));
        }

        return report;
    }

    internal static CensusReport Analyze(
        IEnumerable<CensusFileInput> files,
        IffFile? globalFile,
        Func<string, IffFile?>? resolveSemiGlobal = null,
        IReadOnlyList<ObjectEntry>? objectEntries = null)
    {
        var opcodeCounts = new Dictionary<ushort, int>();
        var subModeCounts = new Dictionary<ushort, Dictionary<string, (int Count, List<CensusSample> Samples)>>();
        var invalidGenericCalls = new List<CensusReferenceIssue>();
        var missingTreeRefs = new List<CensusReferenceIssue>();
        var malformedChunks = new List<CensusReferenceIssue>();

        var filesScanned = 0;
        var globalFiles = 0;
        var semiGlobalFiles = 0;
        var privateFiles = 0;
        var treesScanned = 0;
        var instructionsScanned = 0;
        var primitiveInstructions = 0;
        var treeCallInstructions = 0;

        var globalBhavIds = CollectBhavIds(globalFile);
        var semiBhavIdCache = new Dictionary<IffFile, HashSet<ushort>>(ReferenceEqualityComparer.Instance);
        HashSet<ushort> BhavIdsFor(IffFile? file)
        {
            if (file is null) return [];
            if (!semiBhavIdCache.TryGetValue(file, out var set))
                semiBhavIdCache[file] = set = CollectBhavIds(file);
            return set;
        }

        foreach (var input in files)
        {
            filesScanned++;
            if (input.ScopeKind == "Global") globalFiles++;
            else if (input.ScopeKind == "SemiGlobal") semiGlobalFiles++;
            else privateFiles++;

            var privateBhavIds = BhavIdsFor(input.File);
            var semiFile = input.SemiGlobal is { Length: > 0 } sg ? resolveSemiGlobal?.Invoke(sg) : null;
            var semiBhavIds = BhavIdsFor(semiFile);

            foreach (var chunk in input.File.OfType(ResourceType.Bhav))
            {
                Bhav bhav;
                try { bhav = Bhav.Read(input.File, chunk); }
                catch (ResourceFormatException error)
                {
                    malformedChunks.Add(new CensusReferenceIssue("MalformedBhav", input.Source, unchecked((short)chunk.Id),
                        chunk.Label, -1, chunk.Id, error.Message));
                    continue;
                }

                treesScanned++;
                var treeId = unchecked((short)chunk.Id);
                for (var index = 0; index < bhav.Instructions.Count; index++)
                {
                    var inst = bhav.Instructions[index];
                    instructionsScanned++;

                    if (inst.Opcode < 0x100)
                    {
                        primitiveInstructions++;
                        opcodeCounts[inst.Opcode] = opcodeCounts.GetValueOrDefault(inst.Opcode) + 1;
                        var subKey = DescribeSubMode(inst.Opcode, inst.Operand);
                        if (!subModeCounts.TryGetValue(inst.Opcode, out var map))
                            subModeCounts[inst.Opcode] = map = new Dictionary<string, (int, List<CensusSample>)>(StringComparer.Ordinal);
                        if (!map.TryGetValue(subKey, out var entry))
                            entry = (0, new List<CensusSample>(MaxSamplesPerKey));
                        entry.Count++;
                        if (entry.Samples.Count < MaxSamplesPerKey)
                            entry.Samples.Add(new CensusSample(input.Source, treeId, chunk.Label, index, Convert.ToHexString(inst.Operand)));
                        map[subKey] = entry;

                        if (inst.Opcode == 0x01 && inst.Operand.Length >= 2)
                        {
                            var call = BinaryPrimitives.ReadInt16LittleEndian(inst.Operand);
                            var invalid = call < 0 || call >= GenericSimsCallPrimitive.CaseAddresses.Count ||
                                GenericSimsCallPrimitive.CaseAddresses[call] == 0x45145f;
                            if (invalid)
                            {
                                invalidGenericCalls.Add(new CensusReferenceIssue("InvalidGenericSimsCall", input.Source,
                                    treeId, chunk.Label, index, unchecked((ushort)call),
                                    $"GenericSimsCall 0x{call:X2} is outside valid dispatch table"));
                            }
                        }
                    }
                    else
                    {
                        treeCallInstructions++;
                        if (globalFile is not null)
                        {
                            var targetScope = BehaviorScope.ScopeOf(unchecked((short)inst.Opcode));
                            var exists = targetScope switch
                            {
                                TreeScope.Global => globalBhavIds.Contains(inst.Opcode),
                                TreeScope.Private => privateBhavIds.Contains(inst.Opcode),
                                TreeScope.SemiGlobal => input.ScopeKind == "SemiGlobal"
                                    ? privateBhavIds.Contains(inst.Opcode)
                                    : semiBhavIds.Contains(inst.Opcode),
                                _ => true,
                            };
                            if (!exists && !(targetScope == TreeScope.SemiGlobal && input.ScopeKind == "Global") &&
                                !(targetScope == TreeScope.Private && input.ScopeKind is "Global" or "SemiGlobal"))
                            {
                                missingTreeRefs.Add(new CensusReferenceIssue("MissingBhavCall", input.Source, treeId,
                                    chunk.Label, index, inst.Opcode,
                                    $"Calls missing {targetScope} BHAV 0x{inst.Opcode:X4}"));
                            }
                        }
                    }
                }
            }
        }

        var objectsAudited = 0;
        var interactionsAudited = 0;
        if (objectEntries is not null && globalFile is not null)
        {
            foreach (var obj in objectEntries)
            {
                objectsAudited++;
                var semiFile = obj.SemiGlobal is { Length: > 0 } sg ? resolveSemiGlobal?.Invoke(sg) : null;
                var scope = new BehaviorScope(globalFile, obj.File, semiFile);
                InteractionTable? ttab;
                try { ttab = obj.FindInteractionTable(scope); }
                catch (ResourceFormatException error)
                {
                    malformedChunks.Add(new CensusReferenceIssue("MalformedTtab", obj.Source,
                        unchecked((short)obj.Definition[ObjdField.TreeTableId]), obj.Chunk.Label, -1,
                        obj.Definition[ObjdField.TreeTableId], error.Message));
                    continue;
                }
                if (ttab is null) continue;
                foreach (var interaction in ttab.Interactions)
                {
                    interactionsAudited++;
                    if (interaction.ActionTree != 0 && scope.Find(unchecked((short)interaction.ActionTree)) is null)
                    {
                        missingTreeRefs.Add(new CensusReferenceIssue("MissingTtabActionTree", obj.Source,
                            unchecked((short)interaction.TtaIndex), $"{obj.Chunk.Label} -> {interaction.Name}", -1,
                            interaction.ActionTree, $"TTAB entry {interaction.TtaIndex} references missing ActionTree 0x{interaction.ActionTree:X4}"));
                    }
                    if (interaction.GuardTree != 0 && scope.Find(unchecked((short)interaction.GuardTree)) is null)
                    {
                        missingTreeRefs.Add(new CensusReferenceIssue("MissingTtabGuardTree", obj.Source,
                            unchecked((short)interaction.TtaIndex), $"{obj.Chunk.Label} -> {interaction.Name}", -1,
                            interaction.GuardTree, $"TTAB entry {interaction.TtaIndex} references missing GuardTree 0x{interaction.GuardTree:X4}"));
                    }
                }
            }
        }

        var opcodes = opcodeCounts
            .OrderBy(pair => pair.Key)
            .Select(pair =>
            {
                var modes = subModeCounts.TryGetValue(pair.Key, out var map)
                    ? map.OrderByDescending(m => m.Value.Count).ThenBy(m => m.Key, StringComparer.Ordinal)
                        .Select(m => new CensusSubModeCount(m.Key, m.Value.Count, m.Value.Samples)).ToArray()
                    : [];
                return new CensusOpcodeSummary(pair.Key, PrimitiveName(pair.Key), pair.Value,
                    KnownPrimitiveOpcodes.Contains(pair.Key), modes);
            })
            .ToArray();

        var unknownOpcodes = opcodes.Where(item => !item.Known).ToArray();

        return new CensusReport(
            filesScanned,
            globalFiles,
            semiGlobalFiles,
            privateFiles,
            treesScanned,
            instructionsScanned,
            primitiveInstructions,
            treeCallInstructions,
            objectsAudited,
            interactionsAudited,
            opcodes,
            unknownOpcodes,
            invalidGenericCalls,
            missingTreeRefs,
            malformedChunks);
    }

    public static string FormatSummary(CensusReport report)
    {
        var sb = new StringBuilder();
        sb.AppendLine("=== SimAntics Static Bytecode Census ===");
        sb.AppendLine($"Files scanned:        {report.FilesScanned} (Global={report.GlobalFilesScanned}, SemiGlobal={report.SemiGlobalFilesScanned}, Private={report.PrivateFilesScanned})");
        sb.AppendLine($"BHAV trees scanned:   {report.BhavTreesScanned}");
        sb.AppendLine($"Instructions scanned: {report.InstructionsScanned} (Primitives={report.PrimitiveInstructions}, TreeCalls={report.TreeCallInstructions})");
        sb.AppendLine($"Objects / TTABs:      {report.ObjectsAudited} objects, {report.InteractionsAudited} TTAB entries");
        sb.AppendLine($"Unknown opcodes:      {report.UnknownOpcodes.Count}");
        sb.AppendLine($"Invalid GenericCalls: {report.InvalidGenericCalls.Count}");
        sb.AppendLine($"Missing tree refs:    {report.MissingTreeReferences.Count}");
        sb.AppendLine($"Malformed chunks:     {report.MalformedChunks.Count}");
        sb.AppendLine();

        if (report.UnknownOpcodes.Count > 0)
        {
            sb.AppendLine("--- Unknown Opcodes ---");
            foreach (var item in report.UnknownOpcodes)
                sb.AppendLine($"  0x{item.Opcode:X2} ({item.Count} uses)");
            sb.AppendLine();
        }

        if (report.InvalidGenericCalls.Count > 0)
        {
            sb.AppendLine("--- Invalid GenericSimsCall Uses (top 20) ---");
            foreach (var issue in report.InvalidGenericCalls.Take(20))
                sb.AppendLine($"  {issue.Source} tree=0x{unchecked((ushort)issue.OwnerId):X4} ({issue.OwnerLabel}) inst={issue.Instruction}: {issue.Detail}");
            sb.AppendLine();
        }

        sb.AppendLine("--- Primitive Opcode Usage & Top Sub-Modes ---");
        foreach (var op in report.Opcodes.OrderByDescending(o => o.Count))
        {
            var topModes = string.Join(", ", op.SubModes.Take(6).Select(m => $"{m.Key} ({m.Count})"));
            sb.AppendLine($"  0x{op.Opcode:X2} {op.Name,-26} total={op.Count,7}  distinctModes={op.SubModes.Count,4}  top=[{topModes}]");
        }

        var missingByKind = report.MissingTreeReferences.GroupBy(i => i.Kind).OrderByDescending(g => g.Count());
        if (report.MissingTreeReferences.Count > 0)
        {
            sb.AppendLine();
            sb.AppendLine("--- Missing Tree References Summary ---");
            foreach (var group in missingByKind)
            {
                sb.AppendLine($"  {group.Key}: {group.Count()}");
                foreach (var sample in group.Take(8))
                    sb.AppendLine($"    {sample.Source} owner=0x{unchecked((ushort)sample.OwnerId):X4} ({sample.OwnerLabel}): {sample.Detail}");
            }
        }

        return sb.ToString();
    }

    private static HashSet<ushort> CollectBhavIds(IffFile? file)
    {
        var ids = new HashSet<ushort>();
        if (file is null) return ids;
        foreach (var chunk in file.OfType(ResourceType.Bhav))
            ids.Add(chunk.Id);
        return ids;
    }
}
