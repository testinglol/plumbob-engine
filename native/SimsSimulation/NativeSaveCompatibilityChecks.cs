using System.Text.Json;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.Marshals.Threads;
using FSO.SimAntics.Model.TS1Platform;

/// <summary>Exercises pack-version save migration rules, pack removal and save-backup rotation without loading the game.</summary>
internal static class NativeSaveCompatibilityChecks
{
    private static NativePluginHost.PackDescriptor Pack(string id, string version, params string[] migratesFrom) => new(id, version, migratesFrom);
    private static NativeSaveCompatibility.PackRecord Saved(string id, string version) => new(id, version);

    public static object Run()
    {
        var checks = 0;
        void Require(bool condition, string message) { if (!condition) throw new InvalidDataException(message); checks++; }
        void Rejects(Action action, string expected, string message)
        {
            try { action(); }
            catch (InvalidDataException error) when (error.Message.Contains(expected, StringComparison.OrdinalIgnoreCase)) { checks++; return; }
            throw new InvalidDataException(message);
        }

        var current = new[] { Pack("local.a", "2.0.0", "1.0.0", "1.5.0"), Pack("local.b", "1.0.0") };
        Require(!NativeSaveCompatibility.Check("same", null, "same", current).Migrated, "An identical fingerprint must load without migration");
        var upgraded = NativeSaveCompatibility.Check("old", [Saved("local.a", "1.5.0"), Saved("local.b", "1.0.0")], "new", current);
        Require(upgraded.Migrated && upgraded.Upgraded.SequenceEqual(["local.a@1.5.0->2.0.0"]) && upgraded.Added.Length == 0, "A declared version migration must be accepted and reported");
        var added = NativeSaveCompatibility.Check("old", [Saved("local.a", "2.0.0")], "new", current);
        Require(added.Migrated && added.Added.SequenceEqual(["local.b@1.0.0"]), "A newly enabled pack must be allowed and reported");
        Rejects(() => NativeSaveCompatibility.Check("old", [Saved("local.a", "0.9.0"), Saved("local.b", "1.0.0")], "new", current), "does not declare a save migration",
            "An undeclared version jump must be rejected");
        try { NativeSaveCompatibility.Check("old", [Saved("local.gone", "1.0.0"), Saved("local.a", "2.0.0"), Saved("local.lost", "3.0.0")], "new", current); throw new InvalidDataException("Missing packs were accepted"); }
        catch (NativeSaveCompatibility.MissingPacksException error) { Require(error.Packs.SequenceEqual(["local.gone@1.0.0", "local.lost@3.0.0"]), "A removed pack must reject the save, naming every missing pack"); }
        var removed = NativeSaveCompatibility.Check("old", [Saved("local.a", "2.0.0"), Saved("local.b", "1.0.0"), Saved("local.gone", "1.0.0")], "new", current, removeMissing: true);
        Require(removed.Migrated && removed.Removed.SequenceEqual(["local.gone@1.0.0"]) && removed.Upgraded.Length == 0, "A removed pack must be reported when its removal is allowed");
        Rejects(() => NativeSaveCompatibility.Check("old", [Saved("local.a", "0.9.0"), Saved("local.gone", "1.0.0")], "new", current, removeMissing: true), "does not declare a save migration",
            "Allowing removal must not relax version migration");
        var mapped = new[] { Pack("local.a", "2.0.0", "1.5.0") with { Objects = [new(0xF1A00071, 0xF1A00072)] }, Pack("local.b", "1.0.0") };
        var replaced = NativeSaveCompatibility.Check("old", [Saved("local.a", "1.5.0"), Saved("local.b", "1.0.0")], "new", mapped);
        Require(replaced.Objects.Count == 1 && replaced.Objects[0xF1A00071] == 0xF1A00072, "An upgraded pack's object map must apply");
        var unchanged = NativeSaveCompatibility.Check("old", [Saved("local.a", "2.0.0")], "new", mapped);
        Require(unchanged.Objects.Count == 0, "An object map must not apply to a save from the current pack version");
        checks += PackRemoval();
        Rejects(() => NativeSaveCompatibility.Check("old", [Saved("local.a", "2.0.0"), Saved("local.b", "1.0.0")], "new", current), "without a version change",
            "Changed content without a version change must be rejected");
        Rejects(() => NativeSaveCompatibility.Check("old", null, "new", current), "same engine and content pack stack", "A save without pack records must need an identical fingerprint");

        var profile = Path.Combine(Path.GetTempPath(), "sims-save-compat-" + Guid.NewGuid().ToString("N"));
        try
        {
            var saves = Path.Combine(profile, "Saves");
            Directory.CreateDirectory(saves);
            var slotPath = Path.Combine(saves, "manual.json");
            Require(NativeSaveCompatibility.Backup(profile, "manual", slotPath) == null, "A missing slot has nothing to back up");
            for (var version = 1; version <= NativeSaveCompatibility.MaxBackupsPerSlot + 3; version++)
            {
                File.WriteAllText(slotPath, JsonSerializer.Serialize(new { version }));
                NativeSaveCompatibility.Backup(profile, "manual", slotPath);
            }
            var listed = NativeSaveCompatibility.List(profile, "manual");
            Require(listed.Length == NativeSaveCompatibility.MaxBackupsPerSlot, "Backups must be pruned to the newest five");
            Require(listed.SequenceEqual(listed.OrderByDescending(name => name, StringComparer.Ordinal)), "Backups must list newest first");
            Require(NativeSaveCompatibility.List(profile, "other").Length == 0, "Backups are separate per slot");
            File.WriteAllText(Path.Combine(NativeSaveCompatibility.BackupDirectory(profile), "manual2-20200101T000000000.json"), "{}");
            Require(NativeSaveCompatibility.List(profile, "manual").Length == listed.Length, "A slot whose name extends another must not share its backups");
            var oldest = listed[^1];
            var oldestContents = File.ReadAllText(Path.Combine(NativeSaveCompatibility.BackupDirectory(profile), oldest));
            NativeSaveCompatibility.Restore(profile, "manual", slotPath, oldest);
            Require(File.ReadAllText(slotPath) == oldestContents, "Restore must replace the slot with the chosen backup even when it is the oldest");
            var restored = NativeSaveCompatibility.List(profile, "manual");
            Require(restored.Length == NativeSaveCompatibility.MaxBackupsPerSlot, "Restoring must keep the backup count at the limit");
            try { NativeSaveCompatibility.Restore(profile, "manual", slotPath, "../outside.json"); throw new InvalidDataException("A path-like backup name was accepted"); }
            catch (ArgumentException) { checks++; }
        }
        finally
        {
            if (Directory.Exists(profile)) Directory.Delete(profile, true);
        }
        return new { result = "passed", checks, migrationRules = true, packRemoval = true, backupRotation = true };
    }

    /// <summary>A lot with a removed two-tile custom table holding a plate and a carried Sim, a Sim queued on the table and an untouched chair.</summary>
    private static int PackRemoval()
    {
        const uint person = 0x7FD96B54, table = 0xF1A00001, tableTile = 0xF1A00002, plate = 0x0B1E0001, chair = 0x0C4A0001;
        var definedGuids = new HashSet<uint> { person, tableTile, plate, chair };
        VMEntityMarshal Entity(VMEntityMarshal entity, short id, uint guid, short[]? contained = null, short container = 0, ushort wear = 80)
        {
            entity.ObjectID = id; entity.GUID = guid; entity.Contained = contained ?? []; entity.Container = container;
            entity.ContainerSlot = (short)(container == 0 ? -1 : 0);
            entity.PlatformState = new VMTS1ObjectState { Wear = wear };
            return entity;
        }
        VMThreadMarshal Thread(params VMQueuedActionMarshal[] queue) => new() { Stack = [], Queue = queue, ActiveQueueBlock = (sbyte)(queue.Length > 0 ? 0 : -1) };
        VMMultitileGroupMarshal Group(string name, int price, params short[] objects) => new() { Name = name, Price = price, Objects = objects, Offsets = objects.Select(_ => new FSO.LotView.Model.LotTilePos()).ToArray() };

        var marshal = new VMMarshal
        {
            Entities =
            [
                Entity(new VMAvatarMarshal(), 1, person),
                Entity(new VMAvatarMarshal(), 2, person),
                Entity(new VMGameObjectMarshal(), 10, table, contained: [12, 13], wear: 200),
                Entity(new VMGameObjectMarshal(), 11, tableTile),
                Entity(new VMGameObjectMarshal(), 12, plate, container: 10),
                Entity(new VMAvatarMarshal(), 13, person, container: 10),
                Entity(new VMGameObjectMarshal(), 20, chair),
            ],
            Threads =
            [
                Thread(new VMQueuedActionMarshal { Callee = 10, StackObject = 10, IconOwner = 10, CodeOwnerGUID = table, Name = "Eat" }),
                Thread(new VMQueuedActionMarshal { Callee = 20, StackObject = 20, IconOwner = 20, CodeOwnerGUID = chair, Name = "Sit" }),
                Thread(), Thread(), Thread(), Thread(), Thread(),
            ],
            MultitileGroups = [Group("Custom table", 400, 10, 11), Group("Plate", 10, 12), Group("Chair", 100, 20)],
        };
        var report = NativePackRemoval.Strip(marshal, definedGuids.Contains);
        var checks = 0;
        void Require(bool condition, string message) { if (!condition) throw new InvalidDataException(message); checks++; }
        Require(report.Objects.Select(item => item.ObjectId).SequenceEqual(new short[] { 10, 11, 12 }), "The removed object, its other tiles and what it held must be removed");
        Require(report.Refund == 200 + 8 && report.Objects.Single(item => item.ObjectId == 10).Refund == 200, "Each removed group must be refunded once at its worn value");
        Require(marshal.Entities.Select(entity => entity.ObjectID).SequenceEqual(new short[] { 1, 2, 13, 20 }) && marshal.Threads.Length == 4, "Sims and unrelated objects must be kept with their threads");
        Require(marshal.Entities.Single(entity => entity.ObjectID == 13).Container == 0, "A Sim held by a removed object must be detached");
        Require(marshal.MultitileGroups.Select(group => group.Name).SequenceEqual(["Chair"]), "Removed groups must be dropped");
        Require(report.ResetEntities.SequenceEqual(new short[] { 1 }) && marshal.Threads[0].Queue.Length == 0 && marshal.Threads[1].Queue.Length == 1,
            "Only threads that reference removed objects or definitions must be cleared");
        var untouched = NativePackRemoval.Strip(marshal, definedGuids.Contains);
        Require(!untouched.Changed, "A snapshot without missing definitions must be left as it is");
        const uint newChair = 0xF1A0FFFF;
        var remapped = NativePackRemoval.Remap(marshal, new Dictionary<uint, uint> { [chair] = newChair, [person] = newChair });
        Require(remapped.SequenceEqual([(chair, newChair, (short)20)]) && marshal.Entities.Single(entity => entity.ObjectID == 20).GUID == newChair
            && marshal.Entities.Where(entity => entity is VMAvatarMarshal).All(entity => entity.GUID == person), "A replaced object must take its new GUID, and Sims are never replaced");
        var migrated = NativePackRemoval.Strip(marshal, guid => guid != chair && (guid == newChair || definedGuids.Contains(guid)));
        Require(migrated.Objects.Length == 0 && migrated.ResetEntities.SequenceEqual(new short[] { 2 }) && marshal.Entities.Length == 4,
            "A replaced object must be kept while threads running its old code are reset");
        return checks;
    }
}
