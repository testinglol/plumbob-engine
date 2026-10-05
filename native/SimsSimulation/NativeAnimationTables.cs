using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics.Engine.Primitives;
using FSO.SimAntics.Engine.Scopes;

/// <summary>
/// Checks that the clips named in objects' animation tables exist. The engine resolves an Object-scope animate by the
/// object's AnimationTableID (or 129) for adults and the next table for children; a missing clip only surfaces when a
/// Sim reaches that instruction, so packs are checked when their mount is loaded instead.
/// </summary>
internal static class NativeAnimationTables
{
    internal sealed record MissingClip(string Guid, string Object, ushort Table, int Index, string Clip);

    internal static List<MissingClip> Missing(IEnumerable<uint>? guids = null)
    {
        var content = Content.Get();
        var clips = content.BCFGlobal.AnimHostBCF;
        var missing = new List<MissingClip>();
        var seen = new HashSet<(string, ushort)>();
        var ids = guids?.Select(guid => (ulong)guid) ?? content.WorldObjects.Entries.Keys;
        foreach (var guid in ids.Distinct().OrderBy(id => id))
        {
            var item = content.WorldObjects.Get(guid);
            if (item?.OBJ == null) continue;
            var adult = item.OBJ.AnimationTableID == 0 ? (ushort)129 : item.OBJ.AnimationTableID;
            foreach (var (table, fallback) in new[] { (adult, (ushort)129), ((ushort)(adult + 1), (ushort)130) })
            {
                var strings = item.Resource.Get<STR>(table) ?? item.Resource.Get<STR>(fallback);
                var tableID = item.Resource.Get<STR>(table) != null ? table : fallback;
                if (strings == null || !seen.Add((item.Resource.MainIff.Filename ?? item.OBJ.GUID.ToString(), tableID))) continue;
                for (var index = 1; index < strings.Length; index++)
                {
                    var clip = strings.GetString(index)?.Trim();
                    if (string.IsNullOrEmpty(clip) || clip == "0" || clips.ContainsKey(clip.ToLowerInvariant())) continue;
                    missing.Add(new MissingClip($"0x{item.OBJ.GUID:X8}", item.OBJ.ChunkLabel, tableID, index, clip));
                }
            }
        }
        return missing;
    }

    internal sealed record MissingReference(string Guid, string Object, ushort Routine, string Label, int Instruction, ushort Table, int Index, string? Clip)
    {
        public override string ToString() =>
            $"{Object} ({Guid}) routine {Routine} '{Label}' instruction {Instruction} animates entry {Index} of table {Table}, " +
            (Clip == null ? "which does not exist" : $"clip {Clip}, which is not installed");
    }

    /// <summary>
    /// Checks the Object-scope animate instructions in the given objects' own routines: each literal entry must exist in the
    /// adult and child tables and name an installed clip. Unlike <see cref="Missing"/>, unused leftovers in a table are ignored,
    /// which the base game has plenty of.
    /// </summary>
    internal static List<MissingReference> MissingReferences(IEnumerable<uint> guids)
    {
        var content = Content.Get();
        var clips = content.BCFGlobal.AnimHostBCF;
        var missing = new List<MissingReference>();
        var seen = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        foreach (var guid in guids.Distinct().Order())
        {
            var item = content.WorldObjects.Get(guid);
            if (item?.OBJ == null || !seen.Add(item.Resource.MainIff.Filename ?? guid.ToString())) continue;
            var adult = item.OBJ.AnimationTableID == 0 ? (ushort)129 : item.OBJ.AnimationTableID;
            var tables = new[] { (adult, (ushort)129), ((ushort)(adult + 1), (ushort)130) }
                .Select(pair => item.Resource.Get<STR>(pair.Item1) is { } table ? (pair.Item1, table) : (pair.Item2, item.Resource.Get<STR>(pair.Item2)))
                .ToArray();
            foreach (var behavior in item.Resource.MainIff.List<BHAV>() ?? [])
            {
                for (var index = 0; index < behavior.Instructions.Length; index++)
                {
                    var instruction = behavior.Instructions[index];
                    if (instruction.Opcode != 44) continue;
                    var operand = new VMAnimateSimOperand();
                    operand.Read(instruction.Operand);
                    if (operand.IDFromParam || operand.Source != VMAnimationScope.Object || operand.AnimationID == 0) continue;
                    foreach (var (tableID, table) in tables)
                    {
                        var clip = table?.GetString(operand.AnimationID);
                        if (table != null && operand.AnimationID < table.Length && !string.IsNullOrWhiteSpace(clip) && clips.ContainsKey(clip.Trim().ToLowerInvariant())) continue;
                        missing.Add(new MissingReference($"0x{item.OBJ.GUID:X8}", item.OBJ.ChunkLabel, behavior.ChunkID, behavior.ChunkLabel, index, tableID, operand.AnimationID,
                            table == null || operand.AnimationID >= table.Length ? null : clip));
                    }
                }
            }
        }
        return missing;
    }
}
