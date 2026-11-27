using System.Reflection;
using System.Text.Json;
using SimsNative.Plugins;
using SimsSDL.Core;
using Xunit;

namespace SimsEngine.Tests.Client;

[Collection("Neighborhoods")]
public sealed class BuyCatalogPluginTests
{
    [Fact]
    public void PluginApiVersion5_SupportsBuyCatalogProvider()
    {
        Assert.True(PluginApi.Version >= 5);
        Assert.Contains(5, PluginApi.SupportedVersions);
    }

    [Fact]
    public void BuyCatalogPage_Validate_AllowsPluginCollectionPages()
    {
        var page = new BuyCatalogPage
        {
            SchemaVersion = 1,
            Category = -1,
            Room = null,
            Offset = 0,
            Total = 0,
            Items = [],
        };

        Assert.Throws<ContentError>(() => page.Validate(buildObjects: false, pluginCollection: false));
        page.Validate(buildObjects: false, pluginCollection: true);
    }

    [Fact]
    public void CcBrowserPlugin_GroupsCustomContentBySubfolder_AndIgnoresMaxisItems()
    {
        var repoRoot = FindRepoRoot();
        var dllPath = Path.Combine(repoRoot, "packs", "cc-browser", "plugin", "LocalCcBrowser.dll");
        Assert.True(File.Exists(dllPath), $"Expected built CC browser plugin at {dllPath}");

        var asm = Assembly.LoadFrom(dllPath);
        var type = asm.GetType("Local.CcBrowser.CcBrowserPlugin", throwOnError: true)!;
        var instance = (ISimsPlugin)Activator.CreateInstance(type)!;
        var provider = Assert.IsAssignableFrom<IPluginBuyCatalogProvider>(instance);

        var objects = new PluginCatalogObject[]
        {
            new(0x1001, "Maxis Chair", "GameData/Objects/Objects.far#chair.iff", 100, 1, 1, IsCustomContent: false),
            new(0x2001, "Retro Stove", "Downloads/KitchenSet/stove.iff", 500, 8, 1, IsCustomContent: true),
            new(0x2002, "Retro Fridge", "Downloads/KitchenSet/fridge.iff", 650, 8, 1, IsCustomContent: true),
            new(0x2003, "Fern", "Downloads/Plants/fern.iff", 45, 4, 1, IsCustomContent: true),
            new(0x2004, "Loose Lamp", "Downloads/lamp.iff", 80, 16, 1, IsCustomContent: true),
            new(0x2005, "Custom Rug", "GameData/UserObjects/rug.iff", 120, 4, 1, IsCustomContent: true),
        };

        var view = provider.GetBuyCatalogView(objects);
        Assert.NotNull(view);
        Assert.Equal("cc-folders", view!.TabId);
        Assert.Equal("Folders", view.TabLabel);
        Assert.Equal("f", view.Hotkey);
        Assert.True(view.HideMatchedFromStandardCatalog);

        Assert.Equal(4, view.Collections.Length);
        Assert.Equal(["Downloads", "KitchenSet", "Plants", "UserObjects"], view.Collections.Select(c => c.Label).ToArray());

        var kitchen = view.Collections.Single(c => c.Label == "KitchenSet");
        Assert.Equal([0x2001u, 0x2002u], kitchen.Guids);
        Assert.DoesNotContain(0x1001u, view.Collections.SelectMany(c => c.Guids));
    }

    [Fact]
    public void OriginalBuyLayout_ShiftsRightSectionAndCentersCatalogStrip()
    {
        var canvas = new CGSize(1280, 720);
        var arrowSize = new CGSize(9, 49);

        Assert.Equal(57.0, OriginalBuyLayout.Positions[3].Y);
        Assert.Equal(0, OriginalBuyLayout.ExtraPluginColumns(0));
        Assert.Equal(1, OriginalBuyLayout.ExtraPluginColumns(1));
        Assert.Equal(1, OriginalBuyLayout.ExtraPluginColumns(2));
        Assert.Equal(2, OriginalBuyLayout.ExtraPluginColumns(3));

        double baseThumbX = OriginalBuyLayout.Thumbnail(0, canvas, 0).X;
        var basePrev = OriginalBuyLayout.Arrow(false, arrowSize, canvas, 0);
        var baseNext = OriginalBuyLayout.Arrow(true, arrowSize, canvas, 0);
        int baseCols = OriginalBuyLayout.Columns(canvas, 0);
        double baseLastThumbMaxX = OriginalBuyLayout.Thumbnail(baseCols - 1, canvas, 0).MaxX;

        Assert.Equal(baseThumbX - basePrev.MaxX, baseNext.X - baseLastThumbMaxX, 6);
        Assert.InRange((basePrev.X - 395.0) - (canvas.Width - baseNext.MaxX), -1.0, 1.0);

        double shiftedThumbX = OriginalBuyLayout.Thumbnail(0, canvas, 1).X;
        var shiftedPrev = OriginalBuyLayout.Arrow(false, arrowSize, canvas, 1);
        var shiftedNext = OriginalBuyLayout.Arrow(true, arrowSize, canvas, 1);
        int shiftedCols = OriginalBuyLayout.Columns(canvas, 1);
        double shiftedLastThumbMaxX = OriginalBuyLayout.Thumbnail(shiftedCols - 1, canvas, 1).MaxX;

        Assert.True(shiftedThumbX >= baseThumbX + OriginalBuyLayout.PluginCategoryColumnWidth);
        Assert.True(shiftedPrev.X >= basePrev.X + OriginalBuyLayout.PluginCategoryColumnWidth);
        Assert.True(shiftedCols <= baseCols);
        Assert.Equal(shiftedThumbX - shiftedPrev.MaxX, shiftedNext.X - shiftedLastThumbMaxX, 6);
        Assert.InRange(
            (shiftedPrev.X - (395.0 + OriginalBuyLayout.PluginCategoryColumnWidth)) - (canvas.Width - shiftedNext.MaxX),
            -1.0,
            1.0);

        var pos0 = OriginalBuyLayout.PluginCategoryPosition(0);
        var pos1 = OriginalBuyLayout.PluginCategoryPosition(1);
        var pos2 = OriginalBuyLayout.PluginCategoryPosition(2);
        Assert.Equal(pos0.X, pos1.X);
        Assert.True(pos1.Y > pos0.Y);
        Assert.Equal(pos0.X + OriginalBuyLayout.PluginCategoryColumnWidth, pos2.X);
        Assert.True(pos0.X + OriginalBuyLayout.PluginCategoryIconWidth <= shiftedPrev.X);

        int buildCols = OriginalBuildLayout.Columns(canvas);
        var buildPrev = OriginalBuildLayout.Arrow(false, arrowSize, canvas);
        var buildNext = OriginalBuildLayout.Arrow(true, arrowSize, canvas);
        double buildFirstX = OriginalBuildLayout.Thumbnail(0, canvas).X;
        double buildLastMaxX = OriginalBuildLayout.Thumbnail(buildCols - 1, canvas).MaxX;
        Assert.Equal(buildFirstX - buildPrev.MaxX, buildNext.X - buildLastMaxX, 6);
        Assert.InRange((buildPrev.X - 532.0) - (canvas.Width - buildNext.MaxX), -1.0, 1.0);
    }

    [Fact]
    public void CcBrowserPack_IsDisabledByDefault_EvenWhenBundled()
    {
        var repoRoot = FindRepoRoot();
        var ccBrowserDir = Path.Combine(repoRoot, "packs", "cc-browser");
        var pack = new ContentPack(ccBrowserDir);
        Assert.Equal("local.cc-browser", pack.Manifest.Id);
        Assert.False(pack.Manifest.DefaultEnabled);

        string tempRoot = Path.Combine(Path.GetTempPath(), "sims-cc-default-" + Guid.NewGuid().ToString("N"));
        string gameRoot = Path.Combine(tempRoot, "game");
        string dataRoot = Path.Combine(tempRoot, "data");
        string bundledRoot = Path.Combine(tempRoot, "bundled");
        Directory.CreateDirectory(gameRoot);
        Directory.CreateDirectory(dataRoot);
        CopyDirectory(ccBrowserDir, Path.Combine(bundledRoot, "cc-browser"));

        string? prevOverride = SimsSDL.ModManager.BundledPacksDirectoryOverride;
        try
        {
            SimsSDL.ModManager.BundledPacksDirectoryOverride = bundledRoot;
            var discovered = SimsSDL.ModManager.DiscoverAll(gameRoot, workspace: "", dataRoot, cliPacks: null);
            var ccMod = Assert.Single(discovered, m => m.LoadedPack?.Manifest.Id == "local.cc-browser");
            Assert.False(ccMod.DefaultEnabled);

            var (_, enabledKeys) = SimsSDL.ModManager.BuildInitialState(discovered, new SimsSDL.ModManager.ModSettingsFile());
            Assert.DoesNotContain(ccMod.Key, enabledKeys);

            var explicitSettings = new SimsSDL.ModManager.ModSettingsFile { EnabledPacks = ["local.cc-browser"] };
            var (_, enabledWhenOptedIn) = SimsSDL.ModManager.BuildInitialState(discovered, explicitSettings);
            Assert.Contains(ccMod.Key, enabledWhenOptedIn);
        }
        finally
        {
            SimsSDL.ModManager.BundledPacksDirectoryOverride = prevOverride;
            if (Directory.Exists(tempRoot))
                Directory.Delete(tempRoot, recursive: true);
        }
    }

    private static void CopyDirectory(string source, string destination)
    {
        Directory.CreateDirectory(destination);
        foreach (string file in Directory.EnumerateFiles(source))
            File.Copy(file, Path.Combine(destination, Path.GetFileName(file)), overwrite: true);
        foreach (string dir in Directory.EnumerateDirectories(source))
            CopyDirectory(dir, Path.Combine(destination, Path.GetFileName(dir)));
    }

    private static string FindRepoRoot()
    {
        var dir = new DirectoryInfo(AppContext.BaseDirectory);
        while (dir is not null)
        {
            if (Directory.Exists(Path.Combine(dir.FullName, "packs")) && Directory.Exists(Path.Combine(dir.FullName, "native")))
                return dir.FullName;
            dir = dir.Parent;
        }
        throw new DirectoryNotFoundException("Could not locate repository root");
    }
}
