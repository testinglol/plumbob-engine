using System.Collections.Concurrent;
using SimsEngine.Content;
using SimsEngine.Formats;

namespace SimsEngine.World;

public sealed class WallpaperCatalog
{
    private readonly Dictionary<int, int> prices = [];

    private WallpaperCatalog() { }

    public void SetDynamicPrice(int pattern, int price)
    {
        if (pattern is >= 256 and < 65534)
            prices[pattern] = price;
    }

    public static WallpaperCatalog Read(IffFile build, byte language = 1, IEnumerable<KeyValuePair<int, int>>? dynamicWalls = null)
    {
        var catalog = new WallpaperCatalog();
        var chunk = build.Find(ResourceType.Str, 0x83) ?? throw new InvalidDataException("Build.iff has no wall pattern STR# 0x83");
        var table = StringTable.Read(build, chunk);
        var strings = table.ForLanguage(language);
        foreach (var id in Enumerable.Range(0, 31).Concat(Enumerable.Range(0xf8, 8)))
        {
            var index = 3 * (id - 1);
            var rawPrice = id > 0 && index < strings.Count ? table.GetString(index, language) : string.Empty;
            catalog.prices[id] = id > 0 && int.TryParse(rawPrice.Trim(), out var price) ? price : 0;
        }
        if (dynamicWalls is not null)
        foreach (var (pattern, price) in dynamicWalls)
            if (pattern is > 0 and < 65534) catalog.prices[pattern] = price;
        return catalog;
    }

    public static WallpaperCatalog Open(string game, byte language = 1, IEnumerable<KeyValuePair<int, int>>? dynamicWalls = null)
    {
        var build = FloorCatalog.TryOpenCoreIff(game, "Build.iff")
            ?? throw new FileNotFoundException("Build.iff was not found", game);
        return Read(build, language, dynamicWalls ?? ReadDynamicWalls(game, language));
    }

    private static IEnumerable<KeyValuePair<int, int>> ReadDynamicWalls(string gameOrGameData, byte language)
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
        var root = ObjectRegistry.Resolve(gameData, "Walls");
        if (root is null) yield break;
        var pattern = 256;
        foreach (var path in Directory.EnumerateFiles(root, "*", SearchOption.AllDirectories)
            .Where(path => Path.GetExtension(path).Equals(".wll", StringComparison.OrdinalIgnoreCase))
            .OrderBy(path => Path.GetRelativePath(root, path), StringComparer.OrdinalIgnoreCase))
        {
            if (pattern >= 65534) yield break;
            yield return KeyValuePair.Create(pattern++, path);
        }
    }

    public bool Contains(int pattern) => prices.ContainsKey(pattern);

    public int Price(int pattern) => prices.GetValueOrDefault(pattern);

    private static readonly ConcurrentDictionary<string, IReadOnlyDictionary<string, Func<IffFile>>> WallArchiveCache =
        new(OperatingSystem.IsWindows() ? StringComparer.OrdinalIgnoreCase : StringComparer.Ordinal);
    private static readonly ConcurrentDictionary<(string Root, string Name), IffFile> OpenedWallCache = new();
    private static readonly ConcurrentDictionary<string, IReadOnlyList<DynamicMaterialEntry>> DynamicWallEntriesCache =
        new(OperatingSystem.IsWindows() ? StringComparer.OrdinalIgnoreCase : StringComparer.Ordinal);

    public static IReadOnlyList<DynamicMaterialEntry> DynamicEntries(string gameOrGameData) =>
        FloorCatalog.BuildDynamicMaterialEntries(gameOrGameData, "Walls", ".wll", 65534, WallArchiveCache, OpenedWallCache, DynamicWallEntriesCache);

    public static bool TryOpenWallpaperIffByName(string gameRoot, string fileName, out IffFile? iff) =>
        FloorCatalog.TryOpenMaterialByName(gameRoot, "Walls", ".wll", fileName, WallArchiveCache, OpenedWallCache, out iff);
}
