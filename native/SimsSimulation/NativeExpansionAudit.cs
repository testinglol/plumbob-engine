using System.Text.Json;
using FSO.Files;
using FSO.Files.FAR1;

/// <summary>
/// Per-expansion behavior audit. Each official pack's archive names its own object files; the shared behavior audit runs over
/// just those resources. Unregistered primitives fail the audit. Interactions whose action routine is absent from the pack's own file are reported as warnings, since they may be unreachable or defined elsewhere.
/// Static coverage only: it does not establish that a pack's gameplay works.
/// </summary>
internal static class NativeExpansionAudit
{
    private static readonly (string Name, string Folder)[] Packs =
    [
        ("Livin' Large", "ExpansionPack1"), ("House Party", "ExpansionPack2"), ("Hot Date", "ExpansionPack3"), ("Vacation", "ExpansionPack4"),
        ("Unleashed", "ExpansionPack5"), ("Superstar", "ExpansionPack6"), ("Makin' Magic", "ExpansionPack7")
    ];

    private static IReadOnlyList<string> ArchiveEntries(string path)
    {
        try { return Names(new FAR1Archive(path, false)); }
        catch (Exception) { return Names(new FAR1Archive(path, true)); }
    }

    private static IReadOnlyList<string> Names(FAR1Archive archive)
    {
        try { return archive.GetAllFarEntries().Select(entry => entry.Filename.Replace('\\', '/')).ToArray(); }
        finally { archive.Close(); }
    }

    public static object Run(string game)
    {
        var options = new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
        var results = new List<object>();
        var failures = new List<string>();
        foreach (var (name, folder) in Packs)
        {
            // The installed Complete Collection names Livin' Large's folder "ExpansionPack"; the dev fixture uses "ExpansionPack1".
            var directory = Path.Combine(game, folder);
            if (!Directory.Exists(directory) && folder == "ExpansionPack1") directory = Path.Combine(game, "ExpansionPack");
            var archives = Directory.Exists(directory) ? Directory.GetFiles(directory, "*.far") : [];
            var objectFiles = archives.SelectMany(ArchiveEntries)
                .Where(entry => entry.EndsWith(".iff", StringComparison.OrdinalIgnoreCase))
                .Select(entry => Path.GetFileNameWithoutExtension(entry)).ToHashSet(StringComparer.OrdinalIgnoreCase);
            if (objectFiles.Count == 0)
            {
                results.Add(new { pack = name, objectFiles = 0, note = "No object IFF files in this pack's own archives" });
                continue;
            }
            var audit = JsonSerializer.SerializeToElement(NativeBehaviorAudit.Run(objectFiles), options);
            var interactions = audit.GetProperty("interactions");
            var unregistered = audit.GetProperty("unregisteredPrimitiveReferences").GetInt32();
            var interactionProblems = interactions.GetProperty("problems").GetInt32();
            var actionProblems = interactions.GetProperty("examples").EnumerateArray()
                .Count(example => example.GetProperty("problem").GetString()!.Contains("action routine", StringComparison.Ordinal));
            if (unregistered > 0) failures.Add($"{name} references {unregistered} unregistered primitive operations");
            results.Add(new
            {
                pack = name,
                objectFiles = objectFiles.Count,
                resourcesAudited = audit.GetProperty("resources").GetInt32(),
                routines = audit.GetProperty("routines").GetInt32(),
                interactionTables = interactions.GetProperty("tables").GetInt32(),
                interactionProblems,
                unresolvedActionRoutines = actionProblems,
                unresolvedActionExamples = interactions.GetProperty("examples").EnumerateArray()
                    .Where(example => example.GetProperty("problem").GetString()!.Contains("action routine", StringComparison.Ordinal))
                    .Take(3).Select(example => example.GetRawText()).ToArray(),
                unreadableInteractionTables = interactions.GetProperty("unreadableTables").GetInt32(),
                unregisteredPrimitives = unregistered,
                unresolvedRoutineReferences = audit.GetProperty("missingRoutineReferences").GetArrayLength(),
                loadFailures = audit.GetProperty("loadFailures").GetArrayLength()
            });
        }
        if (failures.Count > 0) throw new InvalidDataException(string.Join("; ", failures));
        return new { result = "passed", packs = results, scope = "Static audit of each expansion's own object resources" };
    }
}
