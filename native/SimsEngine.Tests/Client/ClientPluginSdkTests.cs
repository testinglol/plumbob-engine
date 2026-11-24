using System.Text.Json;
using SimsNative.Plugins;
using SimsSDL;
using SimsSDL.Client;
using SimsSDL.Core;
using SimsSDL.UI;
using Xunit;

namespace SimsEngine.Tests.Client;

public sealed class ClientPluginSdkTests
{
    private static string RepoRoot =>
        Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "..", "..", "..", "..", ".."));

    private static string CreateMinimalGameRoot(string parentDir)
    {
        string gameRoot = Path.Combine(parentDir, "game");
        Directory.CreateDirectory(Path.Combine(gameRoot, "UIGraphics"));
        File.WriteAllBytes(
            Path.Combine(gameRoot, "UIGraphics", "UIGraphics.far"),
            [.. System.Text.Encoding.ASCII.GetBytes("FAR!byAZ"), 1, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0]);
        return gameRoot;
    }

    [Fact]
    public void LightingPackDeclaresOptionsPagesWithoutHostHardcoding()
    {
        string temp = Path.Combine(Path.GetTempPath(), "plumbob-options-pages-" + Guid.NewGuid().ToString("N"));
        try
        {
            string gameRoot = CreateMinimalGameRoot(temp);
            string lightingPack = Path.Combine(RepoRoot, "packs", "lighting");
            var content = new GameContent(gameRoot, [lightingPack]);

            var pack = Assert.Single(content.Packs.Ordered);
            Assert.NotNull(pack.Manifest.OptionsPages);
            var page = Assert.Single(pack.Manifest.OptionsPages!);
            Assert.Equal("graphics", page.Category);
            Assert.Equal("lighting-settings", page.PanelId);
            Assert.Equal(4, page.Items.Count);
            Assert.Equal("enabled", page.Items[0].Key);
            Assert.Null(page.Items[0].EnabledWhen);
            Assert.Equal("enabled", page.Items[1].EnabledWhen);
        }
        finally
        {
            if (Directory.Exists(temp))
                Directory.Delete(temp, recursive: true);
        }
    }

    [Fact]
    public void SeasonsClientPluginRendersHudWidgetToastAndDispatchesForecastClick()
    {
        string temp = Path.Combine(Path.GetTempPath(), "plumbob-client-plugin-" + Guid.NewGuid().ToString("N"));
        try
        {
            string gameRoot = CreateMinimalGameRoot(temp);
            string dataRoot = Path.Combine(temp, "data");
            Directory.CreateDirectory(dataRoot);

            string seasonsPack = Path.Combine(RepoRoot, "packs", "seasons");
            var content = new GameContent(gameRoot, [seasonsPack]);
            ModManager.TrustAllPlugins(content, dataRoot);

            var sentCommands = new List<(string PackId, string Command, string? Payload)>();
            using var host = new ClientPluginHost(
                content,
                dataRoot,
                (packId, cmd, payload) => sentCommands.Add((packId, cmd, payload)));
            Assert.True(host.HasClientPlugins);

            var uiDevice = new UIDevice();
            byte[] summerState = JsonSerializer.SerializeToUtf8Bytes(new
            {
                active = true,
                house = 1,
                season = 1,
                cycleTooltip = "Summer — day 1 of 7",
                weatherTooltip = "Sunny, 78°F",
            });
            using (var doc = JsonDocument.Parse(JsonSerializer.SerializeToUtf8Bytes(new
            {
                states = new[] { new { packId = "local.seasons", data = Convert.ToBase64String(summerState) } },
                blackboard = new Dictionary<string, float> { ["sky.cloudCover"] = 0.25f },
            })))
            {
                host.ApplyServerStates(doc.RootElement);
            }

            var firstHud = host.BuildHud(uiDevice, inLiveMode: true, controlPanelMinimized: false);
            Assert.Null(firstHud.PendingToast);
            var widget = Assert.Single(firstHud.Widgets);
            Assert.Equal("local.seasons", widget.PackId);
            Assert.Equal("season-indicator", widget.WidgetId);
            Assert.Equal(PluginHudAnchor.ControlPanel, widget.Anchor);
            Assert.Equal(149, widget.Rect.MinX);
            Assert.Equal(88, widget.Rect.MinY);
            Assert.Equal(10, widget.Rect.Width);
            Assert.Equal(10, widget.Rect.Height);
            Assert.Equal("Summer — day 1 of 7 · Sunny, 78°F", widget.Tooltip);

            byte[] autumnState = JsonSerializer.SerializeToUtf8Bytes(new
            {
                active = true,
                house = 1,
                season = 2,
                cycleTooltip = "Autumn — day 1 of 7",
                weatherTooltip = "Partly cloudy, 58°F",
            });
            using (var doc = JsonDocument.Parse(JsonSerializer.SerializeToUtf8Bytes(new
            {
                states = new[] { new { packId = "local.seasons", data = Convert.ToBase64String(autumnState) } },
                blackboard = new Dictionary<string, float>(),
            })))
            {
                host.ApplyServerStates(doc.RootElement);
            }

            var secondHud = host.BuildHud(uiDevice, inLiveMode: true, controlPanelMinimized: false);
            Assert.NotNull(secondHud.PendingToast);
            Assert.Equal("Autumn has arrived", secondHud.PendingToast!.Value.Text);

            Assert.True(host.DispatchHudClick("local.seasons", "season-indicator"));
            var sent = Assert.Single(sentCommands);
            Assert.Equal("local.seasons", sent.PackId);
            Assert.Equal("show-forecast", sent.Command);
        }
        finally
        {
            if (Directory.Exists(temp))
                Directory.Delete(temp, recursive: true);
        }
    }

    [Fact]
    public void LightingAndSeasonsClientPluginsComposeStagesTerrainAndRoomLighting()
    {
        string temp = Path.Combine(Path.GetTempPath(), "plumbob-render-sdk-" + Guid.NewGuid().ToString("N"));
        try
        {
            string gameRoot = CreateMinimalGameRoot(temp);
            string dataRoot = Path.Combine(temp, "data");
            Directory.CreateDirectory(dataRoot);

            string lightingPack = Path.Combine(RepoRoot, "packs", "lighting");
            string seasonsPack = Path.Combine(RepoRoot, "packs", "seasons");
            var content = new GameContent(gameRoot, [lightingPack, seasonsPack]);
            ModManager.TrustAllPlugins(content, dataRoot);

            using var host = new ClientPluginHost(content, dataRoot);
            Assert.True(host.SuppressVanillaRoomLighting);
            Assert.True(host.HasActiveRenderPasses);
            Assert.Null(host.ActiveTerrainShaderPath);

            byte[] disabledLighting = JsonSerializer.SerializeToUtf8Bytes(new { enabled = false });
            byte[] winterSeasons = JsonSerializer.SerializeToUtf8Bytes(new
            {
                active = true,
                house = 2,
                season = 3,
                surfaceMode = 2,
                surfaceAmount = 0.85f,
                atmosphere = true,
                seasonalTerrain = true,
                cloudCover = 0.7f,
                audioGain = 0.72f,
                audioCutoff = 0.35f,
            });
            using (var doc = JsonDocument.Parse(JsonSerializer.SerializeToUtf8Bytes(new
            {
                states = new[]
                {
                    new { packId = "local.lighting", data = Convert.ToBase64String(disabledLighting) },
                    new { packId = "local.seasons", data = Convert.ToBase64String(winterSeasons) },
                },
                blackboard = new Dictionary<string, float> { ["sky.cloudCover"] = 0.7f },
            })))
            {
                host.ApplyServerStates(doc.RootElement);
            }

            Assert.False(host.SuppressVanillaRoomLighting);
            Assert.True(host.HasActiveRenderPasses);
            Assert.NotNull(host.ActiveTerrainShaderPath);
            Assert.Contains("local.seasons", host.ActiveTerrainShaderPath, StringComparison.OrdinalIgnoreCase);
            Assert.EndsWith("terrain.frag", host.ActiveTerrainShaderPath, StringComparison.OrdinalIgnoreCase);

            var seasonsManifest = content.Packs.Ordered.Single(p => p.Manifest.Id == "local.seasons").Manifest;
            Assert.NotNull(seasonsManifest.Cheats);
            Assert.Equal(2, seasonsManifest.Cheats!.Count);
            Assert.Contains(seasonsManifest.Cheats, c => c.Usage.StartsWith("weather ", StringComparison.Ordinal));
            Assert.Contains(seasonsManifest.Cheats, c => c.Usage.StartsWith("season ", StringComparison.Ordinal));
        }
        finally
        {
            if (Directory.Exists(temp))
                Directory.Delete(temp, recursive: true);
        }
    }
}
