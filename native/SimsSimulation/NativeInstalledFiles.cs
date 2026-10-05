using FSO.Files.FAR1;

/// <summary>The files of an installed game folder, loose or inside its FAR archives, for the offline pack compilers.</summary>
internal static class NativeInstalledFiles
{
    internal sealed record Entry(string Path, Func<byte[]> Read)
    {
        /// <summary>The file name without folders, for archive entries too.</summary>
        public string Name => System.IO.Path.GetFileName(Path[(Path.LastIndexOf("::", StringComparison.Ordinal) + 1)..].Replace('\\', '/').TrimStart(':'));
    }

    /// <summary>Visits every file whose name <paramref name="wanted"/> accepts. Archive entries are named
    /// <c>archive.far::entry</c>; their contents are read only when the visitor asks for them.</summary>
    internal static void Visit(string game, Func<string, bool> wanted, Action<Entry> visit)
    {
        if (!Directory.Exists(game)) throw new InvalidDataException($"No installed game at {game}");
        foreach (var path in Directory.EnumerateFiles(game, "*", SearchOption.AllDirectories))
        {
            if (path.EndsWith(".far", StringComparison.OrdinalIgnoreCase))
            {
                FAR1Archive archive;
                try { archive = new FAR1Archive(path, false); _ = archive.GetAllFarEntries(); }
                catch (Exception) { archive = new FAR1Archive(path, true); }
                try
                {
                    foreach (var entry in archive.GetAllFarEntries())
                        if (wanted(System.IO.Path.GetFileName(entry.Filename.Replace('\\', '/'))))
                            visit(new Entry(path + "::" + entry.Filename, () => archive.GetEntry(entry)));
                }
                finally { archive.Close(); }
            }
            else if (wanted(System.IO.Path.GetFileName(path)) && new FileInfo(path).Length < 64 * 1024 * 1024)
                visit(new Entry(path, () => File.ReadAllBytes(path)));
        }
    }
}
