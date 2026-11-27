using System.Runtime.CompilerServices;
using SimsEngine.Formats;

namespace SimsEngine.Content;

public sealed record CharacterFile(string Name, string Folder, string Source, Func<ReadOnlyMemory<byte>> Read)
{
    public string Extension => Path.GetExtension(Name);
}

public sealed class CharacterSearchPath
{
    private static readonly EnumerationOptions CaseInsensitiveTopLevel = new() { MatchCasing = MatchCasing.CaseInsensitive };

    private readonly Dictionary<string, CharacterFile> _byName = new(StringComparer.OrdinalIgnoreCase);

    public IReadOnlyList<(string Folder, IReadOnlyList<string> Sources)> Folders { get; }
    public IReadOnlyList<CharacterFile> Files { get; }
    public IReadOnlyList<CharacterFile> Shadowed { get; }

    private CharacterSearchPath(List<(string, IReadOnlyList<string>)> folders, List<CharacterFile> files)
    {
        Folders = folders;
        Files = files;
        var shadowed = new List<CharacterFile>();
        foreach (var file in files)
            if (!_byName.TryAdd(file.Name, file)) shadowed.Add(file);
        Shadowed = shadowed;
    }

    public CharacterFile? Find(string name) => _byName.GetValueOrDefault(name);

    public IEnumerable<CharacterFile> OfExtension(string extension) =>
        _byName.Values.Where(file => string.Equals(file.Extension, extension, StringComparison.OrdinalIgnoreCase));

    private static readonly (int Bit, string[] Roots)[] Packs =
    [
        (0x80, ["ExpansionPack7"]),
        (0x40, ["ExpansionPack6"]),
        (0x20, ["ExpansionPack5"]),
        (0x10, ["Deluxe", "ExpansionPackGOLD"]),
        (0x08, ["ExpansionPack4"]),
        (0x04, ["ExpansionPack3"]),
        (0x02, ["ExpansionPack2"]),
    ];

    private static readonly string[] LivinLarge = ["ExpansionPack", "ExpansionPack1"];

    public static CharacterSearchPath Skins(string game, ObjectRegistry? registry = null)
    {
        var folders = new List<string> { @"GameData\Skins" };
        folders.Add(@"GameData\cmx");
        for (var index = 2; index < 11; index++) folders.Add($@"GameData\cmx{index}");
        folders.Add(@"GameData\cmxpreview");
        folders.AddRange([@"GameData\People1", @"GameData\People2", @"GameData\Accessories1", @"GameData\Accessories2"]);
        var gameEditionMask = registry?.GameEditionMask ?? DetectGameEditionMask(game);
        if (gameEditionMask > 3)
            folders.AddRange([@"ExpansionShared\Skins", @"ExpansionShared\SkinsBuy", @"ExpansionShared\Animations",
                @"ExpansionShared\Skeletons", "TemplateNPCs", @"ExpansionShared\Accessories"]);
        foreach (var (bit, roots) in Packs)
            if ((gameEditionMask & bit) != 0 && Root(game, roots) is { } root)
                folders.AddRange([$@"{root}\Skins", $@"{root}\Animations", $@"{root}\Accessories"]);
        if ((gameEditionMask & 0x01) != 0 && Root(game, LivinLarge) is { } livinLarge) folders.Add($@"{livinLarge}\ExpansionPackAssets");
        return Build(game, folders, registry, lastRegisteredFirst: true);
    }

    public static CharacterSearchPath Textures(string game, ObjectRegistry? registry = null)
    {
        var gameEditionMask = registry?.GameEditionMask ?? DetectGameEditionMask(game);
        var folders = new List<string>();
        if (gameEditionMask > 3)
            folders.AddRange([@"ExpansionShared\Accessories", @"ExpansionShared\Skins", @"ExpansionShared\SkinsBuy", "TemplateNPCs"]);
        foreach (var (bit, roots) in Packs)
            if ((gameEditionMask & bit) != 0 && Root(game, roots) is { } root)
                folders.AddRange([$@"{root}\Accessories", $@"{root}\Skins"]);
        if ((gameEditionMask & 0x01) != 0 && Root(game, LivinLarge) is { } livinLarge) folders.Add($@"{livinLarge}\ExpansionPackAssets");
        folders.AddRange([@"GameData\Skins", @"GameData\Textures2", @"GameData\Textures"]);
        return Build(game, folders, registry, lastRegisteredFirst: false);
    }

    public static CharacterSearchPath Animation(string game, ObjectRegistry? registry = null) =>
        Build(game, [@"GameData\Animation"], registry, lastRegisteredFirst: true);

    private static string? Root(string game, string[] names) =>
        names.FirstOrDefault(name => ObjectRegistry.Resolve(game, name) is not null);

    public static byte DetectEditionMask(string game) => DetectGameEditionMask(game);

    private static byte DetectGameEditionMask(string game)
    {
        bool HasFile(string windowsPath)
        {
            var parts = windowsPath.Split('\\', StringSplitOptions.RemoveEmptyEntries);
            if (parts.Length == 0) return false;
            var folder = parts.Length == 1 ? game : ObjectRegistry.Resolve(game, string.Join('\\', parts[..^1]));
            return folder is not null && Directory.Exists(folder) && Directory.EnumerateFiles(folder)
                .Any(path => string.Equals(Path.GetFileName(path), parts[^1], StringComparison.OrdinalIgnoreCase));
        }

        bool HasPackage(string[] dirNames, string[] rootArchives)
        {
            foreach (var dirName in dirNames)
            {
                if (ObjectRegistry.Resolve(game, dirName) is { } folder &&
                    Directory.Exists(folder) &&
                    Directory.EnumerateFileSystemEntries(folder).Any())
                {
                    return true;
                }
            }
            if (!Directory.Exists(game)) return false;
            foreach (var entry in Directory.EnumerateFiles(game))
            {
                var fileName = Path.GetFileName(entry);
                if (rootArchives.Any(archive => string.Equals(fileName, archive, StringComparison.OrdinalIgnoreCase)))
                    return true;
            }
            return false;
        }

        byte mask = 0x80;
        if (HasFile(@"GameData\Ranger.iff") || HasFile("Ranger.iff") || HasPackage(LivinLarge, ["ExpansionPack.far", "ExpansionPack1.far"])) mask |= 0x01;
        if (HasFile(@"GameData\Ranger2.iff") || HasFile("Ranger2.iff") || HasPackage(["ExpansionPack2"], ["ExpansionPack2.far"])) mask |= 0x02;
        if (HasFile(@"GameData\Ranger3.iff") || HasFile("Ranger3.iff") || HasPackage(["ExpansionPack3"], ["ExpansionPack3.far"])) mask |= 0x04;
        if (HasFile(@"GameData\Ranger4.iff") || HasFile("Ranger4.iff") || HasPackage(["ExpansionPack4"], ["ExpansionPack4.far"])) mask |= 0x08;
        if (HasFile(@"GameData\RangerD.iff") || HasFile("RangerD.iff") || HasPackage(["Deluxe", "ExpansionPackGOLD"], ["Deluxe.far", "ExpansionPackGOLD.far"])) mask |= 0x10;
        if (HasFile(@"GameData\Ranger5.iff") || HasFile("Ranger5.iff") || HasPackage(["ExpansionPack5"], ["ExpansionPack5.far"])) mask |= 0x20;
        if (HasFile(@"GameData\Ranger6.iff") || HasFile("Ranger6.iff") || HasPackage(["ExpansionPack6"], ["ExpansionPack6.far"])) mask |= 0x40;
        return mask;
    }

    private static readonly ConditionalWeakTable<FarArchive, Dictionary<string, List<(string FileName, FarArchive.Entry Entry)>>> ArchiveDirectoryCache = new();

    private static Dictionary<string, List<(string FileName, FarArchive.Entry Entry)>> DirectoryIndex(FarArchive archive) =>
        ArchiveDirectoryCache.GetValue(archive, static far =>
        {
            var index = new Dictionary<string, List<(string FileName, FarArchive.Entry Entry)>>(StringComparer.OrdinalIgnoreCase);
            foreach (var entry in far.Entries)
            {
                var raw = entry.Name;
                var slash = raw.LastIndexOf('/');
                var backslash = raw.LastIndexOf('\\');
                var sep = Math.Max(slash, backslash);
                var folder = sep < 0 ? "" : raw[..sep].Replace('\\', '/');
                var fileName = sep < 0 ? raw : raw[(sep + 1)..];
                if (!index.TryGetValue(folder, out var bucket))
                {
                    bucket = [];
                    index[folder] = bucket;
                }
                bucket.Add((fileName, entry));
            }
            return index;
        });

    private static CharacterSearchPath Build(string game, List<string> windowsFolders, ObjectRegistry? registry, bool lastRegisteredFirst)
    {
        var archives = new Dictionary<string, FarArchive>(StringComparer.Ordinal);
        FarArchive Archive(string path) => archives.TryGetValue(path, out var archive) ? archive : archives[path] = FarArchive.Open(path);
        var folders = new List<(string, IReadOnlyList<string>)>();
        var files = new List<CharacterFile>();

        void Add(string windowsFolder, string? folder)
        {
            var sources = new List<string>();
            var found = new List<CharacterFile>();
            if (folder is not null)
            {
                sources.Add(folder);
                foreach (var path in Directory.EnumerateFiles(folder).Order(StringComparer.OrdinalIgnoreCase))
                    if (!path.EndsWith(".far", StringComparison.OrdinalIgnoreCase))
                        found.Add(new CharacterFile(Path.GetFileName(path), windowsFolder, path, () => File.ReadAllBytes(path)));
            }
            var parts = windowsFolder.Split('\\');
            var parent = parts.Length > 1 ? ObjectRegistry.Resolve(game, string.Join('\\', parts[..^1])) : null;
            foreach (var (directory, prefix) in new[] { (folder, ""), (parent, parts[^1]) })
            {
                if (directory is null) continue;
                foreach (var path in Directory.EnumerateFiles(directory, "*.far", CaseInsensitiveTopLevel).Order(StringComparer.OrdinalIgnoreCase))
                {
                    var archive = Archive(path);
                    var dirIndex = DirectoryIndex(archive);
                    if (!dirIndex.TryGetValue(prefix, out var bucket)) continue;
                    sources.Add(prefix.Length == 0 ? path : path + "::" + prefix + "/");
                    foreach (var (fileName, entry) in bucket)
                    {
                        var captured = entry;
                        found.Add(new CharacterFile(fileName, windowsFolder, path + "::" + captured.Name, () => archive.Read(captured)));
                    }
                }
            }
            if (folder is not null &&
                parts[^1] is { } leaf &&
                (leaf.Equals("Skins", StringComparison.OrdinalIgnoreCase) ||
                 leaf.Equals("SkinsBuy", StringComparison.OrdinalIgnoreCase) ||
                 leaf.Equals("Accessories", StringComparison.OrdinalIgnoreCase) ||
                 leaf.Equals("Textures", StringComparison.OrdinalIgnoreCase)))
            {
                void WalkSubdirs(string subRoot)
                {
                    foreach (var subDir in Directory.EnumerateDirectories(subRoot).Order(StringComparer.OrdinalIgnoreCase))
                    {
                        var subFiles = new List<CharacterFile>();
                        foreach (var path in Directory.EnumerateFiles(subDir).Order(StringComparer.OrdinalIgnoreCase))
                        {
                            if (!path.EndsWith(".far", StringComparison.OrdinalIgnoreCase))
                                subFiles.Add(new CharacterFile(Path.GetFileName(path), windowsFolder, path, () => File.ReadAllBytes(path)));
                        }
                        if (subFiles.Count > 0)
                        {
                            sources.Add(subDir);
                            found.AddRange(subFiles);
                        }
                        foreach (var farPath in Directory.EnumerateFiles(subDir, "*.far", CaseInsensitiveTopLevel).Order(StringComparer.OrdinalIgnoreCase))
                        {
                            var archive = Archive(farPath);
                            var dirIndex = DirectoryIndex(archive);
                            foreach (var (subPrefix, bucket) in dirIndex.OrderBy(static kv => kv.Key, StringComparer.OrdinalIgnoreCase))
                            {
                                if (bucket.Count == 0) continue;
                                sources.Add(subPrefix.Length == 0 ? farPath : farPath + "::" + subPrefix + "/");
                                foreach (var (fileName, entry) in bucket)
                                {
                                    var captured = entry;
                                    found.Add(new CharacterFile(fileName, windowsFolder, farPath + "::" + captured.Name, () => archive.Read(captured)));
                                }
                            }
                        }
                        WalkSubdirs(subDir);
                    }
                }
                WalkSubdirs(folder);
            }
            if (sources.Count == 0) return;
            folders.Add((windowsFolder, sources));
            files.AddRange(found);
        }

        var seenDownloadDirs = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        var seenArchivePrefixes = new HashSet<string>(StringComparer.OrdinalIgnoreCase);

        foreach (var windowsFolder in windowsFolders)
            Add(windowsFolder, ObjectRegistry.Resolve(game, windowsFolder));
        if (registry is not null)
            foreach (var folder in DownloadFolders(registry, lastRegisteredFirst))
            {
                if (folder.ArchivePrefix is null)
                {
                    var fullDir = Path.GetFullPath(folder.Path);
                    seenDownloadDirs.Add(fullDir);
                    if (Directory.Exists(fullDir))
                    {
                        foreach (var farPath in Directory.EnumerateFiles(fullDir, "*.far", CaseInsensitiveTopLevel).Order(StringComparer.OrdinalIgnoreCase))
                            seenArchivePrefixes.Add(Path.GetFullPath(farPath) + "\0");
                    }
                    Add(Path.GetRelativePath(game, folder.Path).Replace('/', '\\'), folder.Path);
                    continue;
                }

                var archive = Archive(folder.Path);
                var logicalFolder = Path.GetRelativePath(game, folder.Path).Replace('/', '\\') + "\\" + folder.ArchivePrefix.Replace('/', '\\');
                var dirIndex = DirectoryIndex(archive);
                var normalizedPrefix = folder.ArchivePrefix.Replace('\\', '/');
                seenArchivePrefixes.Add(Path.GetFullPath(folder.Path) + "\0" + normalizedPrefix);
                if (dirIndex.TryGetValue(normalizedPrefix, out var bucket) && bucket.Count > 0)
                {
                    var found = new List<CharacterFile>(bucket.Count);
                    foreach (var (fileName, entry) in bucket)
                    {
                        var captured = entry;
                        found.Add(new CharacterFile(fileName, logicalFolder, folder.Path + "::" + captured.Name, () => archive.Read(captured)));
                    }
                    folders.Add((logicalFolder, [folder.Path + "::" + folder.ArchivePrefix + "/"]));
                    files.AddRange(found);
                }
            }

        var disabledDownloads = LoadDisabledDownloads(game);
        if (ObjectRegistry.Resolve(game, "Downloads") is { } downloadRoot)
        {
            void WalkDownloads(string dir)
            {
                var fullDir = Path.GetFullPath(dir);
                var logicalFolder = Path.GetRelativePath(game, dir).Replace('/', '\\');
                if (seenDownloadDirs.Add(fullDir))
                {
                    var looseFound = new List<CharacterFile>();
                    foreach (var path in Directory.EnumerateFiles(dir).Order(StringComparer.OrdinalIgnoreCase))
                    {
                        if (!path.EndsWith(".far", StringComparison.OrdinalIgnoreCase))
                            looseFound.Add(new CharacterFile(Path.GetFileName(path), logicalFolder, path, () => File.ReadAllBytes(path)));
                    }
                    if (looseFound.Count > 0)
                    {
                        folders.Add((logicalFolder, [dir]));
                        files.AddRange(looseFound);
                    }
                }

                foreach (var farPath in Directory.EnumerateFiles(dir, "*.far", CaseInsensitiveTopLevel).Order(StringComparer.OrdinalIgnoreCase))
                {
                    var archive = Archive(farPath);
                    var dirIndex = DirectoryIndex(archive);
                    var fullFar = Path.GetFullPath(farPath);
                    foreach (var (prefix, bucket) in dirIndex.OrderBy(static kv => kv.Key, StringComparer.OrdinalIgnoreCase))
                    {
                        if (bucket.Count == 0 || !seenArchivePrefixes.Add(fullFar + "\0" + prefix)) continue;
                        var archiveLogical = prefix.Length == 0
                            ? logicalFolder
                            : logicalFolder + "\\" + prefix.Replace('/', '\\');
                        var sourceLabel = prefix.Length == 0 ? farPath : farPath + "::" + prefix + "/";
                        var found = new List<CharacterFile>(bucket.Count);
                        foreach (var (fileName, entry) in bucket)
                        {
                            var captured = entry;
                            found.Add(new CharacterFile(fileName, archiveLogical, farPath + "::" + captured.Name, () => archive.Read(captured)));
                        }
                        folders.Add((archiveLogical, [sourceLabel]));
                        files.AddRange(found);
                    }
                }

                var isTopLevel = string.Equals(fullDir, Path.GetFullPath(downloadRoot), StringComparison.OrdinalIgnoreCase);
                foreach (var subDir in Directory.EnumerateDirectories(dir).Order(StringComparer.OrdinalIgnoreCase))
                {
                    if (isTopLevel && disabledDownloads is not null && disabledDownloads.Contains(Path.GetFileName(subDir)))
                        continue;
                    WalkDownloads(subDir);
                }
            }

            WalkDownloads(downloadRoot);
        }
        else if (Directory.Exists(game) &&
                 Directory.EnumerateFiles(game, "Downloads.far", CaseInsensitiveTopLevel)
                     .Order(StringComparer.OrdinalIgnoreCase)
                     .FirstOrDefault() is { } farPath)
        {
            var fullFar = Path.GetFullPath(farPath);
            var archive = Archive(farPath);
            var dirIndex = DirectoryIndex(archive);
            foreach (var (prefix, bucket) in dirIndex.OrderBy(static kv => kv.Key, StringComparer.OrdinalIgnoreCase))
            {
                if (bucket.Count == 0 || !seenArchivePrefixes.Add(fullFar + "\0" + prefix)) continue;
                var logicalFolder = prefix.Length == 0
                    ? "Downloads"
                    : @"Downloads\" + prefix.Replace('/', '\\');
                var sourceLabel = prefix.Length == 0 ? farPath : farPath + "::" + prefix + "/";
                var found = new List<CharacterFile>(bucket.Count);
                foreach (var (fileName, entry) in bucket)
                {
                    var captured = entry;
                    found.Add(new CharacterFile(fileName, logicalFolder, farPath + "::" + captured.Name, () => archive.Read(captured)));
                }
                folders.Add((logicalFolder, [sourceLabel]));
                files.AddRange(found);
            }
        }
        return new CharacterSearchPath(folders, files);
    }

    private static HashSet<string>? LoadDisabledDownloads(string game)
    {
        HashSet<string>? disabledDownloads = null;
        var disabledMarkerPath = Path.Combine(game, ".disabled-downloads.txt");
        if (File.Exists(disabledMarkerPath))
        {
            try
            {
                disabledDownloads = new HashSet<string>(
                    File.ReadAllLines(disabledMarkerPath)
                        .Select(static s => s.Trim())
                        .Where(static s => s.Length > 0),
                    StringComparer.OrdinalIgnoreCase);
            }
            catch
            {
            }
        }
        if (Environment.GetEnvironmentVariable("SIMS_DISABLED_DOWNLOADS") is { Length: > 0 } envDisabled)
        {
            disabledDownloads ??= new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var token in envDisabled.Split([';', '\n', '\r'], StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries))
                disabledDownloads.Add(token);
        }
        return disabledDownloads;
    }

    private static IEnumerable<(string Path, string? ArchivePrefix)> DownloadFolders(ObjectRegistry registry, bool lastRegisteredFirst)
    {
        var seen = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        var entries = lastRegisteredFirst ? registry.Entries.Reverse() : registry.Entries;
        foreach (var entry in entries)
        {
            if (entry.Scan != ObjectScan.Downloads) continue;
            var separator = entry.Source.IndexOf("::", StringComparison.Ordinal);
            if (separator >= 0)
            {
                var archive = entry.Source[..separator];
                var item = entry.Source[(separator + 2)..].Replace('\\', '/');
                var slash = item.LastIndexOf('/');
                var prefix = slash < 0 ? "" : item[..slash];
                if (seen.Add(archive + "\0" + prefix)) yield return (archive, prefix);
            }
            else if (Path.GetDirectoryName(entry.Source) is { } folder && seen.Add(folder)) yield return (folder, null);
        }
    }
}
