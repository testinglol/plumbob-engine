using System.Collections.Concurrent;
using SimsEngine.Content;
using SimsEngine.Formats;

namespace SimsEngine.World;

public sealed class FloorCatalog
{
    private const int PoolPattern = 65535;
    private const int WaterPattern = 65534;
    private readonly Dictionary<int, int> prices = [];

    private int terrainPrice = 1;

    private FloorCatalog() { }

    public int TerrainPrice() => terrainPrice;

    public int WaterPrice() => prices.GetValueOrDefault(WaterPattern, 10);

    public static FloorCatalog Read(IffFile build, byte language = 1, IEnumerable<KeyValuePair<int, int>>? dynamicFloors = null)
    {
        var catalog = new FloorCatalog();
        var chunk = build.Find(ResourceType.Str, 0x82) ?? throw new InvalidDataException("Build.iff has no floor STR# 0x82");
        var strings = StringTable.Read(build, chunk).ForLanguage(language);
        for (var pattern = 1; (pattern - 1) * 3 < strings.Count && pattern <= 29; pattern++)
            catalog.prices[pattern] = int.TryParse(strings[(pattern - 1) * 3].Trim(), out var price) ? price : 0;
        if (build.Find(ResourceType.Str, 0x80) is { } terrainChunk
            && StringTable.Read(build, terrainChunk).ForLanguage(language) is { Count: > 0 } terrainStrings
            && int.TryParse(terrainStrings[0].Trim(), out var unit))
            catalog.terrainPrice = unit;
        if (build.Find(ResourceType.Str, 0x85) is { } waterChunk)
        {
            var waterStrings = StringTable.Read(build, waterChunk).ForLanguage(language);
            if (waterStrings.Count >= 1 && int.TryParse(waterStrings[0].Trim(), out var poolPrice))
                catalog.prices[PoolPattern] = poolPrice;
            if (waterStrings.Count >= 4 && int.TryParse(waterStrings[3].Trim(), out var pondPrice))
                catalog.prices[WaterPattern] = pondPrice;
            else if (waterStrings.Count >= 3 && int.TryParse(waterStrings[2].Trim(), out var altPondPrice))
                catalog.prices[WaterPattern] = altPondPrice;
        }
        if (dynamicFloors is not null)
        foreach (var (pattern, price) in dynamicFloors)
            if (pattern is > 0 and < WaterPattern) catalog.prices[pattern] = price;
        return catalog;
    }

    public static FloorCatalog Open(string game, byte language = 1, IEnumerable<KeyValuePair<int, int>>? dynamicFloors = null)
    {
        foreach (var folder in new[] { ObjectRegistry.Resolve(game, "GameData"), game })
        {
            if (folder is null || !Directory.Exists(folder)) continue;
            var path = Directory.EnumerateFiles(folder).FirstOrDefault(file =>
                string.Equals(Path.GetFileName(file), "Build.iff", StringComparison.OrdinalIgnoreCase));
            if (path is not null)
                return Read(IffFile.Open(path), language, dynamicFloors ?? ReadDynamicFloors(folder, language));
        }
        throw new FileNotFoundException("Build.iff was not found", game);
    }

    private static IEnumerable<KeyValuePair<int, int>> ReadDynamicFloors(string gameData, byte language)
    {
        foreach (var (pattern, path) in DynamicFiles(gameData))
        {
            var iff = IffFile.Open(path);
            var chunk = iff.Find(ResourceType.Str, 0);
            IReadOnlyList<string> strings = chunk is null ? Array.Empty<string>() : StringTable.Read(iff, chunk).ForLanguage(language);
            var price = strings.Count > 1 && int.TryParse(strings[1].Trim(), out var parsed) ? parsed : 0;
            yield return KeyValuePair.Create(pattern, price);
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
