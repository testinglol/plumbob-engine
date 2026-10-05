using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;

internal static class NativeBehaviorAudit
{
    internal sealed record Site(string Resource, ushort Routine, string Label, int Instruction, ushort Opcode);
    internal sealed record LoadFailure(string Resource, string Error);
    internal sealed record InteractionSite(string Resource, ushort Table, int Index, string Problem, ushort Action, ushort Test);

    internal static object Run() => Run(null);

    /// <summary>Reads a resource's interaction tables; a malformed chunk is reported instead of aborting the audit.</summary>
    private static List<TTAB> ReadTables(string name, GameIffResource resource, List<LoadFailure> unreadable)
    {
        try { return resource.List<TTAB>() ?? new List<TTAB>(); }
        catch (Exception error) when (error is EndOfStreamException or InvalidDataException or IndexOutOfRangeException or ArgumentException)
        {
            unreadable.Add(new LoadFailure(name, "TTAB: " + error.Message));
            return new List<TTAB>();
        }
    }

    /// <summary>
    /// Audits all objects, or only object resources whose file names are in <paramref name="onlyFiles"/> (base names without
    /// extension, compared case-insensitively). A filtered run excludes the shared global resource from the counts but still
    /// uses it to resolve calls.
    /// </summary>
    internal static object Run(IReadOnlySet<string>? onlyFiles)
    {
        var content = Content.Get();
        var global = content.WorldObjectGlobals.Get("global").Resource;
        var resources = new Dictionary<string, GameIffResource>(StringComparer.OrdinalIgnoreCase)
        {
            ["global"] = global
        };
        var failures = new List<LoadFailure>();
        if (onlyFiles != null) resources.Clear();
        foreach (var entry in content.WorldObjects.Entries.Values.GroupBy(item => item.FileName, StringComparer.OrdinalIgnoreCase).OrderBy(group => group.Key))
        {
            if (onlyFiles != null && !onlyFiles.Contains(Path.GetFileNameWithoutExtension(entry.Key))) continue;
            try
            {
                var resource = content.WorldObjects.Get(entry.First().ID)?.Resource;
                if (resource == null) throw new InvalidDataException("Object resource is unavailable");
                resources[entry.Key] = resource;
                if (resource.SemiGlobal != null)
                {
                    var name = resource.MainIff.List<GLOB>()?.FirstOrDefault()?.Name;
                    resources["semiglobal/" + name] = resource.SemiGlobal;
                }
            }
            catch (Exception error)
            {
                failures.Add(new LoadFailure(entry.Key, error.Message));
            }
        }
        var interactionCount = 0;
        var autonomousInteractions = 0;
        var tablesWithoutNames = 0;
        var interactionProblems = new List<InteractionSite>();
        var unreadableTables = new List<LoadFailure>();
        bool Resolves(string name, GameIffResource resource, ushort routine)
        {
            if (routine < 256) return true; // primitive opcode used directly as a routine is not an interaction target
            var owner = routine >= 8192
                ? name.StartsWith("semiglobal/", StringComparison.Ordinal) ? resource : resource.SemiGlobal
                : routine >= 4096 ? resource : global;
            return owner?.Get<BHAV>(routine) != null;
        }
        var primitiveSites = new Dictionary<ushort, List<Site>>();
        var missingCalls = new List<Site>();
        var routines = 0;
        var instructions = 0;
        foreach (var (name, resource) in resources.OrderBy(item => item.Key))
        foreach (var table in ReadTables(name, resource, unreadableTables))
        {
            var names = resource.Get<TTAs>(table.ChunkID);
            if (names == null) tablesWithoutNames++;
            for (var index = 0; index < table.Interactions.Length; index++)
            {
                var interaction = table.Interactions[index];
                interactionCount++;
                if (interaction.AutonomyThreshold > 0 && interaction.MotiveEntries?.Any(entry => entry.EffectRangeDelta != 0 || entry.EffectRangeMinimum != 0) == true) autonomousInteractions++;
                if (!Resolves(name, resource, interaction.ActionFunction))
                    interactionProblems.Add(new InteractionSite(name, table.ChunkID, index, "action routine is missing", interaction.ActionFunction, interaction.TestFunction));
                else if (interaction.TestFunction != 0 && !Resolves(name, resource, interaction.TestFunction))
                    interactionProblems.Add(new InteractionSite(name, table.ChunkID, index, "check routine is missing", interaction.ActionFunction, interaction.TestFunction));
                else if (names != null && (index >= names.Length || string.IsNullOrWhiteSpace(names.GetString(index))))
                    interactionProblems.Add(new InteractionSite(name, table.ChunkID, index, "interaction has no name", interaction.ActionFunction, interaction.TestFunction));
            }
        }
        foreach (var (name, resource) in resources.OrderBy(item => item.Key))
        foreach (var behavior in resource.List<BHAV>() ?? new List<BHAV>())
        {
            routines++;
            for (var index = 0; index < behavior.Instructions.Length; index++)
            {
                instructions++;
                var opcode = behavior.Instructions[index].Opcode;
                var site = new Site(name, behavior.ChunkID, behavior.ChunkLabel, index, opcode);
                if (opcode < 256)
                {
                    if (!primitiveSites.TryGetValue(opcode, out var sites))
                        primitiveSites[opcode] = sites = new List<Site>();
                    sites.Add(site);
                }
                else
                {
                    var owner = opcode >= 8192
                        ? name.StartsWith("semiglobal/", StringComparison.Ordinal) ? resource : resource.SemiGlobal
                        : opcode >= 4096 ? resource : global;
                    if (owner?.Get<BHAV>(opcode) == null) missingCalls.Add(site);
                }
            }
        }
        return new
        {
            scope = "Static BHAV references in loaded object, global and referenced semiglobal resources",
            objects = content.WorldObjects.Entries.Count,
            resources = resources.Count,
            routines,
            instructions,
            primitives = primitiveSites.OrderBy(item => item.Key).Select(item => new
            {
                opcode = item.Key,
                name = VMContext.Primitives[item.Key]?.Name,
                registered = VMContext.Primitives[item.Key] != null,
                references = item.Value.Count,
                examples = item.Value.Take(8).ToArray()
            }).ToArray(),
            unregisteredPrimitiveReferences = primitiveSites.Where(item => VMContext.Primitives[item.Key] == null).Sum(item => item.Value.Count),
            unregisteredPrimitiveFallback = "The current VM takes the true branch without executing behavior",
            interactions = new
            {
                tables = interactionCount,
                autonomous = autonomousInteractions,
                tablesWithoutNames,
                unreadableTables = unreadableTables.Count,
                unreadableExamples = unreadableTables.Take(20).ToArray(),
                problems = interactionProblems.Count,
                examples = interactionProblems.Take(40).ToArray(),
                scope = "Every TTAB entry's action and check routine resolves, and has a TTAs name; reachability still needs execution"
            },
            missingRoutineReferences = missingCalls,
            missingRoutineInterpretation = "Static unresolved references may be unreachable or deliberately absent; execution is required to establish failures",
            loadFailures = failures,
            gameplayCompletenessVerified = false
        };
    }
}

/// <summary>Prints the control flow of every routine whose label contains a name, for tracing original scripts.</summary>
internal static class NativeBehaviorDump
{
    internal static object Run(string needle)
    {
        var content = Content.Get();
        var resources = new Dictionary<string, GameIffResource> { ["global"] = content.WorldObjectGlobals.Get("global").Resource };
        foreach (var group in content.WorldObjects.Entries.Values.GroupBy(item => item.FileName, StringComparer.OrdinalIgnoreCase))
        {
            var resource = content.WorldObjects.Get(group.First().ID)?.Resource;
            if (resource == null) continue;
            resources[group.Key] = resource;
            if (resource.SemiGlobal != null) resources["semiglobal/" + resource.MainIff.List<GLOB>()?.FirstOrDefault()?.Name] = resource.SemiGlobal;
        }
        var limit = int.TryParse(Environment.GetEnvironmentVariable("DUMP_LIMIT"), out var requested) ? requested : 12;
        // "guid:5EB641D1" lists one object's private routines, "guid:5EB641D1#4096" selects one of them;
        // "guid:VillageControl.iff" picks the file's first object.
        if (needle.StartsWith("guid:", StringComparison.OrdinalIgnoreCase))
        {
            var parts = needle[5..].Split('#', 2);
            var guid = parts[0].EndsWith(".iff", StringComparison.OrdinalIgnoreCase)
                ? content.WorldObjects.Entries.Values.FirstOrDefault(entry => string.Equals(Path.GetFileName(entry.FileName), parts[0], StringComparison.OrdinalIgnoreCase))?.ID
                    ?? throw new InvalidDataException("No object comes from " + parts[0])
                : Convert.ToUInt32(parts[0], 16);
            var resource = content.WorldObjects.Get(guid)?.Resource ?? throw new InvalidDataException("No object has GUID " + parts[0]);
            resources = new Dictionary<string, GameIffResource> { [content.WorldObjects.Entries[guid].FileName + "/" + guid.ToString("X8")] = resource };
            needle = parts.Length > 1 ? "#" + parts[1] : "";
            limit = 200;
        }
        var matches = new List<object>();
        foreach (var (name, resource) in resources.OrderBy(item => item.Key))
        foreach (var behavior in resource.List<BHAV>() ?? new List<BHAV>())
        {
            // "#280" selects routine id 280 in the global resource; anything else matches routine labels.
            if (needle.StartsWith('#') ? !((name == "global" || name.Contains('/')) && behavior.ChunkID.ToString() == needle[1..]) : !(behavior.ChunkLabel ?? "").Contains(needle, StringComparison.OrdinalIgnoreCase)) continue;
            matches.Add(new
            {
                resource = name,
                id = behavior.ChunkID,
                label = behavior.ChunkLabel,
                args = behavior.Args,
                locals = behavior.Locals,
                instructions = behavior.Instructions.Select((instruction, index) => new
                {
                    index,
                    op = instruction.Opcode < 256 ? (VMContext.Primitives[instruction.Opcode]?.Name ?? "primitive " + instruction.Opcode) : "call " + instruction.Opcode,
                    t = instruction.TruePointer,
                    f = instruction.FalsePointer,
                    operand = Convert.ToHexString(instruction.Operand ?? [])
                }).ToArray()
            });
            if (matches.Count >= limit) return new { needle, matches, truncated = true };
        }
        return new { needle, matches };
    }
}
