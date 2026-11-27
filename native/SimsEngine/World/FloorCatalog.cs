using System.Collections.Concurrent;
using SimsEngine.Content;
using SimsEngine.Formats;

namespace SimsEngine.World;

public sealed record DynamicMaterialEntry(int PatternId, string FileName, string? LoosePath, Func<IffFile> Open);

public sealed class FloorCatalog
{
    private const int PoolPattern = 65535;
    private const int WaterPattern = 65534;
    private readonly Dictionary<int, int> prices = [];

    private int terrainPrice = 1;

    private FloorCatalog() { }

    public int TerrainPrice() => terrainPrice;

    public int WaterPrice() => prices.GetValueOrDefault(WaterPattern, 10);

    public void SetDynamicPrice(int pattern, int price)
    {
        if (pattern is >= 256 and < WaterPattern)
            prices[pattern] = price;
    }

    public static FloorCatalog Read(IffFile build, byte language = 1, IEnumerable<KeyValuePair<int, int>>? dynamicFloors = null)
    {
        var catalog = new FloorCatalog();
        var chunk = build.Find(ResourceType.Str, 0x82) ?? throw new InvalidDataException("Build.iff has no floor STR# 0x82");
        var table = StringTable.Read(build, chunk);
        var strings = table.ForLanguage(language);
        for (var pattern = 1; (pattern - 1) * 3 < strings.Count && pattern <= 29; pattern++)
        {
            var rawPrice = table.GetString((pattern - 1) * 3, language);
            catalog.prices[pattern] = int.TryParse(rawPrice.Trim(), out var price) ? price : 0;
        }
        if (build.Find(ResourceType.Str, 0x80) is { } terrainChunk
            && StringTable.Read(build, terrainChunk).GetString(0, language) is { Length: > 0 } terrainRaw
            && int.TryParse(terrainRaw.Trim(), out var unit))
            catalog.terrainPrice = unit;
        if (build.Find(ResourceType.Str, 0x85) is { } waterChunk)
        {
            var waterTable = StringTable.Read(build, waterChunk);
            var waterStrings = waterTable.ForLanguage(language);
            if (waterStrings.Count >= 1 && int.TryParse(waterTable.GetString(0, language).Trim(), out var poolPrice))
                catalog.prices[PoolPattern] = poolPrice;
            if (waterStrings.Count >= 4 && int.TryParse(waterTable.GetString(3, language).Trim(), out var pondPrice))
                catalog.prices[WaterPattern] = pondPrice;
            else if (waterStrings.Count >= 3 && int.TryParse(waterTable.GetString(2, language).Trim(), out var altPondPrice))
                catalog.prices[WaterPattern] = altPondPrice;
        }
        if (dynamicFloors is not null)
        foreach (var (pattern, price) in dynamicFloors)
            if (pattern is > 0 and < WaterPattern) catalog.prices[pattern] = price;
        return catalog;
    }

    public static FloorCatalog Open(string game, byte language = 1, IEnumerable<KeyValuePair<int, int>>? dynamicFloors = null)
    {
        var build = TryOpenCoreIff(game, "Build.iff")
            ?? throw new FileNotFoundException("Build.iff was not found", game);
        return Read(build, language, dynamicFloors ?? ReadDynamicFloors(game, language));
    }

    private static IEnumerable<KeyValuePair<int, int>> ReadDynamicFloors(string gameOrGameData, byte language)
    {
        foreach (var entry in DynamicEntries(gameOrGameData))
        {
            int price = 0;
            try
            {
                var iff = entry.Open();
                if (iff.Find(ResourceType.Str, 0) is { } chunk)
                {
                    var raw = StringTable.Read(iff, chunk).GetString(1, language);
                    if (int.TryParse(raw.Trim(), out var parsed))
                        price = Math.Max(0, parsed);
                }
            }
            catch (Exception ex) when (ex is IOException or InvalidDataException or ResourceFormatException or ArgumentException or OverflowException)
            {
                continue;
            }
            yield return KeyValuePair.Create(entry.PatternId, price);
        }
    }

    public static IEnumerable<KeyValuePair<int, string>> DynamicFiles(string gameData)
    {
        var root = ObjectRegistry.Resolve(gameData, "Floors");
        if (root is null) yield break;
        var pattern = 256;
        foreach (var path in Directory.EnumerateFiles(root, "*", SearchOption.AllDirectories)
            .Where(path => Path.GetExtension(path).Equals(".flr", StringComparison.OrdinalIgnoreCase))
            .OrderBy(path => Path.GetRelativePath(root, path), StringComparer.OrdinalIgnoreCase))
        {
            if (pattern >= WaterPattern) yield break;
            yield return KeyValuePair.Create(pattern++, path);
        }
    }

    private static readonly ConcurrentDictionary<string, IReadOnlyList<DynamicMaterialEntry>> DynamicFloorEntriesCache =
        new(OperatingSystem.IsWindows() ? StringComparer.OrdinalIgnoreCase : StringComparer.Ordinal);

    public static IReadOnlyList<DynamicMaterialEntry> DynamicEntries(string gameOrGameData) =>
        BuildDynamicMaterialEntries(gameOrGameData, "Floors", ".flr", WaterPattern, FloorArchiveCache, OpenedFloorCache, DynamicFloorEntriesCache);

    internal static string NormalizeGameRoot(string gameOrGameData)
    {
        if (string.IsNullOrWhiteSpace(gameOrGameData))
            return gameOrGameData;
        var full = Path.GetFullPath(gameOrGameData);
        if (string.Equals(Path.GetFileName(full.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar)), "GameData", StringComparison.OrdinalIgnoreCase) &&
            Path.GetDirectoryName(full.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar)) is { Length: > 0 } parent)
        {
            return parent;
        }
        return full;
    }

    public static IffFile? TryOpenCoreIff(string gameOrGameData, string fileName)
    {
        if (string.IsNullOrWhiteSpace(gameOrGameData))
            return null;
        var gameRoot = NormalizeGameRoot(gameOrGameData);
        foreach (var folder in new[] { ObjectRegistry.Resolve(gameRoot, "GameData"), gameRoot, gameOrGameData })
        {
            if (folder is null || !Directory.Exists(folder)) continue;
            var loose = Directory.EnumerateFiles(folder).FirstOrDefault(file =>
                string.Equals(Path.GetFileName(file), fileName, StringComparison.OrdinalIgnoreCase));
            if (loose is not null)
            {
                try { return IffFile.Open(loose); }
                catch { }
            }
        }

        var topEnum = new EnumerationOptions { IgnoreInaccessible = true, MatchCasing = MatchCasing.CaseInsensitive };
        foreach (var dir in new[]
        {
            ObjectRegistry.Resolve(gameRoot, "GameData"),
            ObjectRegistry.Resolve(gameRoot, @"GameData\Global"),
            ObjectRegistry.Resolve(gameRoot, @"GameData\Textures"),
            gameRoot,
        })
        {
            if (dir is null || !Directory.Exists(dir)) continue;
            foreach (var farPath in Directory.EnumerateFiles(dir, "*.far", topEnum).OrderBy(static p => p, StringComparer.OrdinalIgnoreCase))
            {
                try
                {
                    var archive = FarArchive.Open(farPath);
                    var hit = archive.Entries.FirstOrDefault(e =>
                        string.Equals(Path.GetFileName(e.Name.Replace('\\', '/')), fileName, StringComparison.OrdinalIgnoreCase));
                    if (hit is not null)
                        return archive.ReadIff(hit);
                }
                catch
                {
                }
            }
        }
        return null;
    }

    internal static IReadOnlyList<DynamicMaterialEntry> BuildDynamicMaterialEntries(
        string gameOrGameData,
        string subdir,
        string extension,
        int maxExclusivePattern,
        ConcurrentDictionary<string, IReadOnlyDictionary<string, Func<IffFile>>> archiveIndexCache,
        ConcurrentDictionary<(string Root, string Name), IffFile> openedCache,
        ConcurrentDictionary<string, IReadOnlyList<DynamicMaterialEntry>> entriesCache)
    {
        if (string.IsNullOrWhiteSpace(gameOrGameData))
            return [];
        var gameRoot = NormalizeGameRoot(gameOrGameData);
        if (!Directory.Exists(gameRoot))
            return [];

        return entriesCache.GetOrAdd(gameRoot, root =>
        {
            var list = new List<DynamicMaterialEntry>();
            var seenNames = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            var pattern = 256;

            var gameData = ObjectRegistry.Resolve(root, "GameData") ?? root;
            var looseRoot = ObjectRegistry.Resolve(gameData, subdir);
            if (looseRoot is not null && Directory.Exists(looseRoot))
            {
                foreach (var path in Directory.EnumerateFiles(looseRoot, "*", SearchOption.AllDirectories)
                             .Where(p => Path.GetExtension(p).Equals(extension, StringComparison.OrdinalIgnoreCase))
                             .OrderBy(p => Path.GetRelativePath(looseRoot, p), StringComparer.OrdinalIgnoreCase))
                {
                    if (pattern >= maxExclusivePattern)
                        return list;
                    var fileName = Path.GetFileName(path);
                    var key = fileName.ToLowerInvariant();
                    seenNames.Add(key);
                    var capturedPath = path;
                    list.Add(new DynamicMaterialEntry(
                        pattern++,
                        fileName,
                        capturedPath,
                        () => openedCache.GetOrAdd((root, key), _ => IffFile.Open(capturedPath))));
                }
            }

            var index = archiveIndexCache.GetOrAdd(root, r => BuildMaterialIndex(r, subdir, extension));
            foreach (var key in index.Keys.OrderBy(static k => k, StringComparer.OrdinalIgnoreCase))
            {
                if (pattern >= maxExclusivePattern)
                    break;
                if (!seenNames.Add(key))
                    continue;
                var loader = index[key];
                var capturedKey = key;
                list.Add(new DynamicMaterialEntry(
                    pattern++,
                    capturedKey,
                    null,
                    () => openedCache.GetOrAdd((root, capturedKey), _ => loader())));
            }

            return list;
        });
    }

    public bool Contains(int pattern) => prices.ContainsKey(pattern);

    public IReadOnlyCollection<int> Patterns => prices.Keys;

    public int Price(int pattern) => prices.GetValueOrDefault(pattern);

    private static readonly ConcurrentDictionary<string, IReadOnlyDictionary<string, Func<IffFile>>> FloorArchiveCache =
        new(OperatingSystem.IsWindows() ? StringComparer.OrdinalIgnoreCase : StringComparer.Ordinal);
    private static readonly ConcurrentDictionary<(string Root, string Name), IffFile> OpenedFloorCache = new();

    public static bool TryOpenFloorIffByName(string gameRoot, string fileName, out IffFile? iff) =>
        TryOpenMaterialByName(gameRoot, "Floors", ".flr", fileName, FloorArchiveCache, OpenedFloorCache, out iff);

    internal static bool TryOpenMaterialByName(
        string gameRoot,
        string gameDataSubdir,
        string extension,
        string fileName,
        ConcurrentDictionary<string, IReadOnlyDictionary<string, Func<IffFile>>> indexCache,
        ConcurrentDictionary<(string Root, string Name), IffFile> openedCache,
        out IffFile? iff)
    {
        iff = null;
        if (string.IsNullOrWhiteSpace(gameRoot) || string.IsNullOrWhiteSpace(fileName))
            return false;

        var normalizedBase = Path.GetFileName(fileName.Replace('\\', '/')).Trim().ToLowerInvariant();
        if (normalizedBase.Length == 0)
            return false;

        if (openedCache.TryGetValue((gameRoot, normalizedBase), out var cached))
        {
            iff = cached;
            return true;
        }

        var index = indexCache.GetOrAdd(gameRoot, root => BuildMaterialIndex(root, gameDataSubdir, extension));
        if (!index.TryGetValue(normalizedBase, out var loader))
            return false;

        try
        {
            var opened = loader();
            iff = openedCache.GetOrAdd((gameRoot, normalizedBase), opened);
            return true;
        }
        catch
        {
            return false;
        }
    }

    private static IReadOnlyDictionary<string, Func<IffFile>> BuildMaterialIndex(
        string gameRoot,
        string gameDataSubdir,
        string extension)
    {
        var map = new Dictionary<string, Func<IffFile>>(StringComparer.OrdinalIgnoreCase);
        if (!Directory.Exists(gameRoot))
            return map;

        var recursiveEnum = new EnumerationOptions
        {
            RecurseSubdirectories = true,
            IgnoreInaccessible = true,
            MatchCasing = MatchCasing.CaseInsensitive,
        };
        var topLevelEnum = new EnumerationOptions
        {
            RecurseSubdirectories = false,
            IgnoreInaccessible = true,
            MatchCasing = MatchCasing.CaseInsensitive,
        };

        void AddLooseDirectory(string? dir)
        {
            if (dir is null || !Directory.Exists(dir)) return;
            foreach (var path in Directory.EnumerateFiles(dir, "*", recursiveEnum)
                         .OrderBy(static p => p, StringComparer.OrdinalIgnoreCase))
            {
                if (!Path.GetExtension(path).Equals(extension, StringComparison.OrdinalIgnoreCase))
                    continue;
                var key = Path.GetFileName(path).ToLowerInvariant();
                map.TryAdd(key, () => IffFile.Open(path));
            }
        }

        void AddFarArchive(string farPath)
        {
            FarArchive archive;
            try { archive = FarArchive.Open(farPath); }
            catch { return; }

            foreach (var entry in archive.Entries)
            {
                var entryNorm = entry.Name.Replace('\\', '/');
                if (!entryNorm.EndsWith(extension, StringComparison.OrdinalIgnoreCase))
                    continue;
                var key = Path.GetFileName(entryNorm).ToLowerInvariant();
                var capturedArchive = archive;
                var capturedEntry = entry;
                map.TryAdd(key, () => capturedArchive.ReadIff(capturedEntry));
            }
        }

        var gameData = ObjectRegistry.Resolve(gameRoot, "GameData");
        var materialDir = gameData is not null ? ObjectRegistry.Resolve(gameData, gameDataSubdir) : null;
        var downloadsDir = ObjectRegistry.Resolve(gameRoot, "Downloads");

        AddLooseDirectory(materialDir);
        AddLooseDirectory(downloadsDir);

        foreach (var farPath in Directory.EnumerateFiles(gameRoot, "*.far", topLevelEnum)
                     .OrderBy(static p => p, StringComparer.OrdinalIgnoreCase))
        {
            var fileName = Path.GetFileName(farPath);
            if (fileName.StartsWith("Expansion", StringComparison.OrdinalIgnoreCase) ||
                fileName.StartsWith("Deluxe", StringComparison.OrdinalIgnoreCase) ||
                fileName.Equals("Downloads.far", StringComparison.OrdinalIgnoreCase))
            {
                AddFarArchive(farPath);
            }
        }

        foreach (var dir in Directory.EnumerateDirectories(gameRoot, "*", topLevelEnum)
                     .OrderBy(static p => p, StringComparer.OrdinalIgnoreCase))
        {
            var dirName = Path.GetFileName(dir);
            if (!dirName.StartsWith("Expansion", StringComparison.OrdinalIgnoreCase) &&
                !dirName.StartsWith("Deluxe", StringComparison.OrdinalIgnoreCase))
            {
                continue;
            }

            foreach (var farPath in Directory.EnumerateFiles(dir, "*.far", recursiveEnum)
                         .OrderBy(static p => p, StringComparer.OrdinalIgnoreCase))
            {
                AddFarArchive(farPath);
            }
        }

        foreach (var scopedDir in new[] { materialDir, downloadsDir })
        {
            if (scopedDir is null || !Directory.Exists(scopedDir)) continue;
            foreach (var farPath in Directory.EnumerateFiles(scopedDir, "*.far", recursiveEnum)
                         .OrderBy(static p => p, StringComparer.OrdinalIgnoreCase))
            {
                AddFarArchive(farPath);
            }
        }

        return map;
    }
}
