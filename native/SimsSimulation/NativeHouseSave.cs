using System.Buffers.Binary;
using FSO.Content;
using FSO.Files.Formats.IFF;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.Model.TS1Platform;

/// <summary>
/// Saves a played lot back into its UserData/Houses/HouseNN.iff, the way Simitone does: the whole simulation goes into an
/// FSOV chunk and the SIMI chunk is refreshed. Every other chunk of the house file (the original lot data, thumbnails
/// and offsets) is kept byte for byte, so the neighborhood view and older readers still find what they expect. A house
/// file with an FSOV chunk is restored from it instead of being rebuilt from its original object map.
/// </summary>
internal static class NativeHouseSave
{
    private const string Label = "Native Lot Data";

    internal static string HousePath(string userData, short house) => Path.Combine(userData, "Houses", $"House{house:D2}.iff");

    internal static int Write(string userData, short house, VM vm)
    {
        var path = HousePath(userData, house);
        var chunks = NativeObjectAuthor.ReadIff(File.ReadAllBytes(path));
        vm.TS1State.UpdateSIMI(vm);
        using var state = new MemoryStream();
        using (var writer = new BinaryWriter(state, System.Text.Encoding.UTF8, true)) vm.Save().SerializeInto(writer);
        var fsov = new byte[8 + state.Length];
        BinaryPrimitives.WriteInt32LittleEndian(fsov, FSOV.CURRENT_VERSION);
        BinaryPrimitives.WriteInt32LittleEndian(fsov.AsSpan(4), (int)state.Length);
        state.ToArray().CopyTo(fsov, 8);
        chunks.RemoveAll(chunk => chunk.Type == "FSOV");
        chunks.Add(new NativeObjectAuthor.Chunk { Type = "FSOV", Id = 1, Flags = 0x10, Label = Label, Data = fsov });
        if (vm.TS1State.SimulationInfo is { } simi)
        {
            using var data = new MemoryStream();
            simi.Write(null, data);
            var index = chunks.FindIndex(chunk => chunk.Type == "SIMI" && chunk.Id == 1);
            var chunk = new NativeObjectAuthor.Chunk { Type = "SIMI", Id = 1, Flags = 0x10, Label = index >= 0 ? chunks[index].Label : "", Data = data.ToArray() };
            if (index >= 0) chunks[index] = chunk;
            else chunks.Add(chunk);
        }
        Replace(path, chunks);
        return fsov.Length;
    }

    /// <summary>
    /// Drops the saved simulation of a house file, so the lot starts again from its original object map. Used when its
    /// family moves out: their Sims and saved state must not come back with the next family, or with them.
    /// </summary>
    internal static bool Discard(string userData, short house)
    {
        var path = HousePath(userData, house);
        if (!File.Exists(path)) return false;
        var chunks = NativeObjectAuthor.ReadIff(File.ReadAllBytes(path));
        if (chunks.RemoveAll(chunk => chunk.Type == "FSOV") == 0) return false;
        Replace(path, chunks);
        return true;
    }

    /// <summary>
    /// Restores the saved simulation of a house file into a fresh VM. Returns false when the file has none or it belongs
    /// to a family that no longer lives there (the lot then starts from its original object map, as after a move).
    /// Objects of packs that are no longer installed are removed and refunded to the family, as when loading a save.
    /// </summary>
    internal static bool Restore(VM vm, IffFile iff, FAMI? family, bool activateFamily)
    {
        var fsov = iff.List<FSOV>()?.FirstOrDefault();
        if (fsov?.Data == null) return false;
        var marshal = new VMMarshal();
        using (var reader = new BinaryReader(new MemoryStream(fsov.Data))) marshal.Deserialize(reader);
        var savedFamily = (marshal.PlatformState as VMTS1LotState)?.CurrentFamily;
        if ((savedFamily?.ChunkID ?? -1) != (family?.ChunkID ?? -1)) return false;
        var removal = NativePackRemoval.Strip(marshal, guid => Content.Get().WorldObjects.Get(guid) != null);
        vm.Load(marshal);
        // The neighborhood's family record is the live one: budget and members are shared with the neighborhood file.
        vm.TS1State.CurrentFamily = null;
        if (activateFamily && family != null)
        {
            family.SelectWholeFamily();
            vm.TS1State.ActivateFamily(vm, family);
            if (removal.Refund > 0) family.Budget = (int)Math.Min(int.MaxValue, (long)family.Budget + removal.Refund);
        }
        foreach (var id in removal.ResetEntities) vm.GetObjectById(id)?.Reset(vm.Context);
        vm.TS1State.VerifyFamily(vm);
        return true;
    }

    private static void Replace(string path, List<NativeObjectAuthor.Chunk> chunks)
    {
        var temporary = path + ".tmp";
        try
        {
            File.WriteAllBytes(temporary, NativeObjectAuthor.WriteIff(chunks));
            File.Move(temporary, path, true);
        }
        finally
        {
            if (File.Exists(temporary)) File.Delete(temporary);
        }
    }
}
