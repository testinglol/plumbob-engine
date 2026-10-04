using System.Text.Json;

/// <summary>Exercises pack-version save migration rules and save-backup rotation without loading the game.</summary>
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
        Rejects(() => NativeSaveCompatibility.Check("old", [Saved("local.gone", "1.0.0")], "new", current), "not enabled", "A removed pack must reject the save");
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
        return new { result = "passed", checks, migrationRules = true, backupRotation = true };
    }
}
