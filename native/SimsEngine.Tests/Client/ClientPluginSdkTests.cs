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
            Assert.Equal("lighting", page.Items[0].HostEnabledWhen);
            Assert.Equal("enabled", page.Items[1].EnabledWhen);
            Assert.Equal("shadows", page.Items[1].HostEnabledWhen);
        }
        finally
        {
            if (Directory.Exists(temp))
                Directory.Delete(temp, recursive: true);
        }
    }

    [Fact]
    public void AllPackAndBuiltinOptionsSubpagesFitCleanlyWithoutOverlapAndDispatchSteppers()
    {
        string temp = Path.Combine(Path.GetTempPath(), "plumbob-all-options-pages-" + Guid.NewGuid().ToString("N"));
        try
        {
            string gameRoot = CreateMinimalGameRoot(temp);
            string[] packs =
            [
                Path.Combine(RepoRoot, "packs", "lighting"),
                Path.Combine(RepoRoot, "packs", "seasons"),
                Path.Combine(RepoRoot, "packs", "smart-free-will"),
            ];
            var content = new GameContent(gameRoot, packs);
            Assert.Equal(3, content.Packs.Ordered.Count);

            var seasonsPage = Assert.Single(content.Packs.Ordered.Single(p => p.Manifest.Id == "local.seasons").Manifest.OptionsPages!);
            Assert.Equal("play", seasonsPage.Category);
            Assert.Equal(2, seasonsPage.Items.Count);
            Assert.All(seasonsPage.Items, it => Assert.Equal("stepper", it.Kind));

            var sfwPage = Assert.Single(content.Packs.Ordered.Single(p => p.Manifest.Id == "local.smart-free-will").Manifest.OptionsPages!);
            Assert.Equal("play", sfwPage.Category);
            Assert.Equal(3, sfwPage.Items.Count);

            string realGame = Path.Combine(RepoRoot, "runtime", "game");
            if (!Directory.Exists(Path.Combine(realGame, "UIGraphics")))
                return;

            var fullContent = new GameContent(realGame, packs);
            var font = new SimsBitmapFont(fullContent.Read("UIGraphics/Fonts/variablesans_10.ffn"));
            var strings = new OriginalUIStrings(fullContent);
            var panel = new OriginalOptionsPanelOverlay(fullContent, new UIDevice(), strings, font);
            var canvas = new CGSize(800, 600);

            Assert.Equal(3, panel.TotalSubpages(OriginalOptionsPanelOverlay.Page.Graphics));
            Assert.Equal(3, panel.TotalSubpages(OriginalOptionsPanelOverlay.Page.Play));

            static bool Intersects(CGRect a, CGRect b) =>
                a.MinX < b.MaxX && b.MinX < a.MaxX && a.MinY < b.MaxY && b.MinY < a.MaxY;

            foreach (var category in new[] { OriginalOptionsPanelOverlay.Page.Graphics, OriginalOptionsPanelOverlay.Page.Play })
            {
                int count = panel.TotalSubpages(category);
                for (int sp = 0; sp < count; sp++)
                {
                    panel.SelectSubpage(category, sp);
                    Assert.Equal(sp, panel.ActiveSubpage);
                    Assert.False(string.IsNullOrWhiteSpace(panel.CurrentSubpageTitle));

                    var controls = panel.Controls(canvas);
                    Assert.NotEmpty(controls);
                    for (int i = 0; i < controls.Count; i++)
                    {
                        var r = controls[i].Rect;
                        Assert.True(r.MinX >= 220 && r.MaxX <= 800, $"{category}[{sp}] '{controls[i].Label}' X out of bounds: {r}");
                        Assert.True(r.MinY >= 500 && r.MaxY <= 600, $"{category}[{sp}] '{controls[i].Label}' Y out of bounds: {r}");
                        for (int j = i + 1; j < controls.Count; j++)
                        {
                            Assert.False(
                                Intersects(r, controls[j].Rect),
                                $"{category}[{sp}] '{controls[i].Label}' ({r}) overlapped '{controls[j].Label}' ({controls[j].Rect})");
                        }
                    }
                }
            }

            panel.SelectSubpage(OriginalOptionsPanelOverlay.Page.Play, 1);
            Assert.Equal("Seasons", panel.CurrentSubpageTitle);
            var nextSeasonLen = Assert.Single(panel.Controls(canvas), c => c.Label == "Next Season Length");
            var hit = panel.PluginOptionAt(new CGPoint(nextSeasonLen.Rect.MidX, nextSeasonLen.Rect.MidY), canvas);
            Assert.NotNull(hit);
            Assert.Equal("local.seasons", hit!.PackId);
            Assert.Equal("long", hit.Action);
            Assert.False(string.IsNullOrWhiteSpace(panel.AboutText(new CGPoint(nextSeasonLen.Rect.MidX, nextSeasonLen.Rect.MidY), canvas)));

            panel.PlayOptions = panel.PlayOptions with { Lighting = false, FreeWill = false };
            panel.SelectSubpage(OriginalOptionsPanelOverlay.Page.Graphics, 2);
            Assert.DoesNotContain(panel.Controls(canvas), c => c.Label.StartsWith("Enhanced Lighting", StringComparison.Ordinal));
            panel.SelectSubpage(OriginalOptionsPanelOverlay.Page.Play, 2);
            Assert.DoesNotContain(panel.Controls(canvas), c => c.Label.StartsWith("Autonomy Style", StringComparison.Ordinal));
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

    private sealed class SimlessTestSimulation : IPluginSimulation
    {
        public short House { get; set; } = 1;
        public int Hours { get; set; } = 12;
        public int Minutes { get; set; } = 0;
        public bool Paused { get; set; }
        public bool SimlessBuildMode { get; set; }
        public bool FreeWill => true;
        public bool AwayLot => false;
        public int HouseholdFunds => 2000;
        public IReadOnlyList<PluginSim> HouseholdSims { get; set; } = [];
        public IReadOnlyList<PluginSimProfile> AllSims => [];
        public IReadOnlyList<PluginObject> Objects => [];
        public short GetMotive(short objectId, int motive) => 0;
        public bool TryCharge(int amount) => false;
        public bool TryPay(int amount) => false;
    }

    [Fact]
    public void SeasonsResetsToNormalSeasonWithoutWeatherWhenEditingLotOutsideHousehold()
    {
        string temp = Path.Combine(Path.GetTempPath(), "plumbob-seasons-simless-" + Guid.NewGuid().ToString("N"));
        try
        {
            string gameRoot = CreateMinimalGameRoot(temp);
            string dataRoot = Path.Combine(temp, "data");
            string userData = Path.Combine(temp, "UserData");
            Directory.CreateDirectory(dataRoot);
            Directory.CreateDirectory(userData);

            string seasonsPack = Path.Combine(RepoRoot, "packs", "seasons");
            var content = new GameContent(gameRoot, [seasonsPack]);
            ModManager.TrustAllPlugins(content, dataRoot);

            var sim = new SimlessTestSimulation { House = 1, SimlessBuildMode = false };
            var json = new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
            using var clientHost = new ClientPluginHost(content, dataRoot);
            var uiDevice = new UIDevice();

            void SyncClient(PluginHost server)
            {
                using var doc = JsonDocument.Parse(JsonSerializer.SerializeToUtf8Bytes(server.ClientStateSnapshot(), json));
                clientHost.ApplyServerStates(doc.RootElement);
            }

            using var serverHost = PluginHost.Create(
                gameRoot,
                dataRoot,
                _ => { },
                () => sim.House,
                _ => sim,
                userData: userData,
                packOverlay: content.BuildDirectPackOverlay());

            Assert.Equal("loaded", Assert.Single(serverHost.Statuses).State);

            Assert.True(serverHost.TryHandleCheat("season", ["autumn", "4"], out _));
            Assert.True(serverHost.TryHandleCheat("weather", ["rain"], out _));
            SyncClient(serverHost);
            Assert.NotNull(clientHost.ActiveTerrainShaderPath);
            Assert.True(clientHost.HasActiveRenderPasses);
            Assert.True(serverHost.CurrentSpriteVariant > 0);
            Assert.Single(clientHost.BuildHud(uiDevice, inLiveMode: true, controlPanelMinimized: false).Widgets);

            serverHost.CommitNeighborhood();

            sim.House = 0;
            sim.SimlessBuildMode = false;
            serverHost.NotifyWorldLoaded();
            SyncClient(serverHost);
            Assert.Null(clientHost.ActiveTerrainShaderPath);
            Assert.False(clientHost.HasActiveRenderPasses);

            sim.House = 2;
            sim.SimlessBuildMode = true;
            serverHost.NotifyWorldLoaded();
            SyncClient(serverHost);

            Assert.Null(clientHost.ActiveTerrainShaderPath);
            Assert.False(clientHost.HasActiveRenderPasses);
            Assert.Equal(0, serverHost.CurrentSpriteVariant);
            Assert.Empty(clientHost.BuildHud(uiDevice, inLiveMode: false, controlPanelMinimized: false).Widgets);
            Assert.Equal(0f, clientHost.Blackboard["sky.cloudCover"]);
            Assert.Equal(0f, clientHost.Blackboard["sky.precipitation"]);
            Assert.Equal(0f, clientHost.Blackboard["sky.wetness"]);
            Assert.Equal(0f, clientHost.Blackboard["sky.snowPack"]);
            Assert.Equal(0f, clientHost.Blackboard["sky.snowfall"]);
            Assert.Equal(0f, clientHost.Blackboard["sky.thunder"]);
            Assert.Equal(1f, clientHost.Blackboard["sky.tintScale"]);

            sim.House = 40;
            sim.SimlessBuildMode = true;
            serverHost.NotifyWorldLoaded();
            SyncClient(serverHost);
            Assert.Null(clientHost.ActiveTerrainShaderPath);
            Assert.False(clientHost.HasActiveRenderPasses);
            Assert.Equal(0, serverHost.CurrentSpriteVariant);
            Assert.Equal(0f, clientHost.Blackboard["sky.precipitation"]);
            Assert.Equal(0f, clientHost.Blackboard["sky.snowPack"]);

            sim.House = 3;
            sim.SimlessBuildMode = false;
            serverHost.NotifyWorldLoaded();
            SyncClient(serverHost);
            Assert.NotNull(clientHost.ActiveTerrainShaderPath);
            Assert.True(serverHost.CurrentSpriteVariant > 0);
            var householdHud = clientHost.BuildHud(uiDevice, inLiveMode: true, controlPanelMinimized: false);
            Assert.Null(householdHud.PendingToast);
            var widget = Assert.Single(householdHud.Widgets);
            Assert.StartsWith("Autumn —", widget.Tooltip, StringComparison.Ordinal);

            Assert.True(serverHost.TryHandleCheat("season", ["winter", "2"], out _));
            SyncClient(serverHost);
            Assert.StartsWith("Winter —", Assert.Single(clientHost.BuildHud(uiDevice, inLiveMode: true, controlPanelMinimized: false).Widgets).Tooltip, StringComparison.Ordinal);

            sim.House = 0;
            serverHost.ReloadNeighborhood(userData);
            serverHost.NotifyWorldLoaded();

            sim.House = 3;
            sim.SimlessBuildMode = false;
            serverHost.NotifyWorldLoaded();
            SyncClient(serverHost);
            Assert.StartsWith("Autumn —", Assert.Single(clientHost.BuildHud(uiDevice, inLiveMode: true, controlPanelMinimized: false).Widgets).Tooltip, StringComparison.Ordinal);
        }
        finally
        {
            if (Directory.Exists(temp))
                Directory.Delete(temp, recursive: true);
        }
    }
}
