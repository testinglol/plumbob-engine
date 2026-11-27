using System.IO.Compression;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using SimsSDL.Client;
using SimsSDL.Core;

namespace SimsEngine.Tests.Client;

public sealed class ClientUpdaterTests
{
    private sealed class MockHttpHandler(Func<HttpRequestMessage, HttpResponseMessage> responder) : HttpMessageHandler
    {
        protected override Task<HttpResponseMessage> SendAsync(HttpRequestMessage request, CancellationToken cancellationToken) =>
            Task.FromResult(responder(request));
    }

    [Fact]
    public void TryParseReleaseVersion_NormalizesStableTagsAndRejectsPrereleases()
    {
        Assert.True(ClientUpdater.TryParseReleaseVersion("v0.8.7", out Version v1, out string d1));
        Assert.Equal(new Version(0, 8, 7, 0), v1);
        Assert.Equal("0.8.7", d1);

        Assert.True(ClientUpdater.TryParseReleaseVersion("0.8.7+git1234", out Version v2, out string d2));
        Assert.Equal(v1, v2);
        Assert.Equal("0.8.7", d2);

        Assert.True(ClientUpdater.TryParseReleaseVersion("V1.2.3.4", out Version v3, out string d3));
        Assert.Equal(new Version(1, 2, 3, 4), v3);
        Assert.Equal("1.2.3.4", d3);

        Assert.False(ClientUpdater.TryParseReleaseVersion("v0.9.0-rc1", out _, out _));
        Assert.False(ClientUpdater.TryParseReleaseVersion("", out _, out _));
        Assert.False(ClientUpdater.TryParseReleaseVersion("invalid", out _, out _));
    }

    [Fact]
    public async Task CheckForUpdateAsync_ParsesReleaseCachesETagAndSkipsEqualOrOlderVersions()
    {
        string temp = Path.Combine(Path.GetTempPath(), "sims-updater-check-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);
        try
        {
            const string releaseJson = """
                {
                  "tag_name": "v0.9.2",
                  "draft": false,
                  "prerelease": false,
                  "html_url": "https://github.com/testinglol/plumbob-engine/releases/tag/v0.9.2",
                  "assets": [
                    {
                      "name": "Plumbob-Engine-macOS-arm64.zip",
                      "size": 4096,
                      "digest": "sha256:0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef",
                      "browser_download_url": "https://github.com/testinglol/plumbob-engine/releases/download/v0.9.2/Plumbob-Engine-macOS-arm64.zip"
                    }
                  ]
                }
                """;

            int networkCalls = 0;
            string? sawIfNoneMatch = null;
            var handler = new MockHttpHandler(req =>
            {
                networkCalls++;
                Assert.Contains("PlumbobEngine/", req.Headers.UserAgent.ToString(), StringComparison.Ordinal);
                if (req.Headers.TryGetValues("If-None-Match", out var etags))
                {
                    sawIfNoneMatch = string.Join(",", etags);
                    return new HttpResponseMessage(HttpStatusCode.NotModified);
                }

                var resp = new HttpResponseMessage(HttpStatusCode.OK)
                {
                    Content = new StringContent(releaseJson, Encoding.UTF8, "application/json")
                };
                resp.Headers.ETag = new EntityTagHeaderValue("\"release-092\"");
                return resp;
            });

            DateTimeOffset t0 = new(2026, 11, 26, 12, 0, 0, TimeSpan.Zero);
            UpdateReleaseInfo? newer = await ClientUpdater.CheckForUpdateAsync(
                temp,
                currentVersionOverride: new Version(0, 8, 7),
                customHandler: handler,
                nowUtcOverride: t0,
                expectedAssetOverride: "Plumbob-Engine-macOS-arm64.zip");

            Assert.NotNull(newer);
            Assert.Equal("0.9.2", newer.VersionText);
            Assert.Equal("https://github.com/testinglol/plumbob-engine/releases/tag/v0.9.2", newer.HtmlUrl);
            Assert.Equal("Plumbob-Engine-macOS-arm64.zip", newer.AssetName);
            Assert.Equal(4096, newer.AssetSize);
            Assert.Equal("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef", newer.AssetSha256);
            Assert.Equal(1, networkCalls);

            UpdateReleaseInfo? cooldownHit = await ClientUpdater.CheckForUpdateAsync(
                temp,
                currentVersionOverride: new Version(0, 8, 7),
                customHandler: handler,
                nowUtcOverride: t0.AddMinutes(5),
                expectedAssetOverride: "Plumbob-Engine-macOS-arm64.zip");
            Assert.NotNull(cooldownHit);
            Assert.Equal(1, networkCalls);

            UpdateReleaseInfo? etagHit = await ClientUpdater.CheckForUpdateAsync(
                temp,
                currentVersionOverride: new Version(0, 8, 7),
                customHandler: handler,
                nowUtcOverride: t0.AddMinutes(30),
                expectedAssetOverride: "Plumbob-Engine-macOS-arm64.zip");
            Assert.NotNull(etagHit);
            Assert.Equal(2, networkCalls);
            Assert.Equal("\"release-092\"", sawIfNoneMatch);

            UpdateReleaseInfo? upToDate = await ClientUpdater.CheckForUpdateAsync(
                temp,
                currentVersionOverride: new Version(0, 9, 2),
                customHandler: handler,
                nowUtcOverride: t0.AddMinutes(31),
                expectedAssetOverride: "Plumbob-Engine-macOS-arm64.zip");
            Assert.Null(upToDate);
        }
        finally
        {
            if (Directory.Exists(temp))
            {
                Directory.Delete(temp, recursive: true);
            }
        }
    }

    [Fact]
    public void ResolveInstallTarget_DistinguishesStandaloneAndWorkspaceLayouts()
    {
        string temp = Path.Combine(Path.GetTempPath(), "sims-updater-target-" + Guid.NewGuid().ToString("N"));
        try
        {
            string standaloneMacos = Path.Combine(temp, "apps", "Plumbob Engine.app", "Contents", "MacOS");
            Directory.CreateDirectory(standaloneMacos);
            File.WriteAllText(Path.Combine(temp, "apps", "Plumbob Engine.app", "Contents", "Info.plist"), "<plist/>");
            var macTarget = ClientUpdater.ResolveInstallTarget(
                standaloneMacos,
                platformOverride: OSPlatform.OSX,
                allowWorkspaceBundleOverride: false);
            Assert.True(macTarget.CanSelfUpdate);
            Assert.Equal(UpdateInstallKind.MacAppBundle, macTarget.Kind);

            string repoDir = Path.Combine(temp, "repo");
            string repoMacos = Path.Combine(repoDir, "Plumbob Engine.app", "Contents", "MacOS");
            Directory.CreateDirectory(repoMacos);
            File.WriteAllText(Path.Combine(repoDir, "PlumbobEngine.sln"), "");
            File.WriteAllText(Path.Combine(repoDir, "Plumbob Engine.app", "Contents", "Info.plist"), "<plist/>");
            var repoTarget = ClientUpdater.ResolveInstallTarget(
                repoMacos,
                platformOverride: OSPlatform.OSX,
                allowWorkspaceBundleOverride: false);
            Assert.False(repoTarget.CanSelfUpdate);

            string winDir = Path.Combine(temp, "win-standalone");
            Directory.CreateDirectory(Path.Combine(winDir, "Shaders"));
            Directory.CreateDirectory(Path.Combine(winDir, "Packs"));
            File.WriteAllText(Path.Combine(winDir, "SimsSDL.exe"), "stub");
            File.WriteAllText(Path.Combine(winDir, "SDL3.dll"), "stub");
            var winTarget = ClientUpdater.ResolveInstallTarget(
                winDir,
                platformOverride: OSPlatform.Windows,
                allowWorkspaceBundleOverride: false);
            Assert.True(winTarget.CanSelfUpdate);
            Assert.Equal(UpdateInstallKind.PortableDirectory, winTarget.Kind);
        }
        finally
        {
            if (Directory.Exists(temp))
            {
                Directory.Delete(temp, recursive: true);
            }
        }
    }

    [Fact]
    public async Task DownloadAndStageAsync_RejectsHashMismatchAndZipSlipAndAppliesValidBundleSwap()
    {
        string temp = Path.Combine(Path.GetTempPath(), "sims-updater-stage-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);
        try
        {
            string evilZip = Path.Combine(temp, "evil.zip");
            using (var zf = ZipFile.Open(evilZip, ZipArchiveMode.Create))
            {
                var entry = zf.CreateEntry("../escaped.txt");
                using var w = new StreamWriter(entry.Open());
                w.Write("bad");
            }
            Assert.Throws<InvalidDataException>(() => ClientUpdater.ValidateZipArchiveSafety(evilZip));

            string appsDir = Path.Combine(temp, "Applications");
            string installedApp = Path.Combine(appsDir, "Plumbob Engine.app");
            Directory.CreateDirectory(Path.Combine(installedApp, "Contents", "MacOS"));
            Directory.CreateDirectory(Path.Combine(installedApp, "Contents", "Frameworks"));
            Directory.CreateDirectory(Path.Combine(installedApp, "Contents", "Resources", "Shaders"));
            Directory.CreateDirectory(Path.Combine(installedApp, "Contents", "Resources", "Packs"));
            File.WriteAllText(Path.Combine(installedApp, "Contents", "Info.plist"), "0.8.7");
            File.WriteAllText(Path.Combine(installedApp, "Contents", "MacOS", "SimsSDL"), "old-bin");
            File.WriteAllText(Path.Combine(installedApp, "Contents", "Frameworks", "libSDL3.0.dylib"), "sdl");

            string buildNewParent = Path.Combine(temp, "new-build");
            string buildNewApp = Path.Combine(buildNewParent, "Plumbob Engine.app");
            Directory.CreateDirectory(Path.Combine(buildNewApp, "Contents", "MacOS"));
            Directory.CreateDirectory(Path.Combine(buildNewApp, "Contents", "Frameworks"));
            Directory.CreateDirectory(Path.Combine(buildNewApp, "Contents", "Resources", "Shaders"));
            Directory.CreateDirectory(Path.Combine(buildNewApp, "Contents", "Resources", "Packs"));
            File.WriteAllText(Path.Combine(buildNewApp, "Contents", "Info.plist"), "0.9.0");
            File.WriteAllText(Path.Combine(buildNewApp, "Contents", "MacOS", "SimsSDL"), "new-bin-090");
            File.WriteAllText(Path.Combine(buildNewApp, "Contents", "Frameworks", "libSDL3.0.dylib"), "sdl-090");

            string validZipPath = Path.Combine(temp, "Plumbob-Engine-macOS-arm64.zip");
            ZipFile.CreateFromDirectory(buildNewParent, validZipPath, CompressionLevel.Fastest, includeBaseDirectory: false);
            byte[] zipBytes = File.ReadAllBytes(validZipPath);
            string shaHex = Convert.ToHexStringLower(SHA256.HashData(zipBytes));

            var handler = new MockHttpHandler(_ =>
            {
                var resp = new HttpResponseMessage(HttpStatusCode.OK)
                {
                    Content = new ByteArrayContent(zipBytes)
                };
                resp.Content.Headers.ContentLength = zipBytes.Length;
                return resp;
            });

            var macTarget = ClientUpdater.ResolveInstallTarget(
                Path.Combine(installedApp, "Contents", "MacOS"),
                platformOverride: OSPlatform.OSX,
                allowWorkspaceBundleOverride: false);
            Assert.True(macTarget.CanSelfUpdate);

            var badHashRelease = new UpdateReleaseInfo(
                "v0.9.0",
                "0.9.0",
                new Version(0, 9, 0, 0),
                "https://github.com/testinglol/plumbob-engine/releases/tag/v0.9.0",
                "Plumbob-Engine-macOS-arm64.zip",
                "http://127.0.0.1:18080/Plumbob-Engine-macOS-arm64.zip",
                zipBytes.Length,
                new string('f', 64));

            await Assert.ThrowsAsync<InvalidDataException>(() =>
                ClientUpdater.DownloadAndStageAsync(
                    badHashRelease,
                    macTarget,
                    Path.Combine(temp, "data"),
                    customHandler: handler,
                    useMacDittoOverride: false));

            var validRelease = badHashRelease with { AssetSha256 = shaHex };
            var seenFractions = new List<float>();
            StagedUpdatePlan plan = await ClientUpdater.DownloadAndStageAsync(
                validRelease,
                macTarget,
                Path.Combine(temp, "data"),
                relaunchArgs: [],
                onProgress: p => seenFractions.Add(p.Fraction),
                customHandler: handler,
                useMacDittoOverride: false);

            Assert.NotEmpty(seenFractions);
            Assert.Equal(1.0f, seenFractions[^1]);
            Assert.True(Directory.Exists(plan.StagedPayloadPath));

            if (!OperatingSystem.IsWindows())
            {
                using var swapProc = ClientUpdater.LaunchDetachedSwapAndRelaunch(plan, waitForPid: 999999, relaunch: false);
                await swapProc.WaitForExitAsync();
                Assert.Equal(0, swapProc.ExitCode);
                Assert.Equal("0.9.0", File.ReadAllText(Path.Combine(installedApp, "Contents", "Info.plist")));
                Assert.Equal("new-bin-090", File.ReadAllText(Path.Combine(installedApp, "Contents", "MacOS", "SimsSDL")));
                Assert.False(Directory.Exists(plan.StagingDirectory));
                Assert.False(Directory.Exists(plan.StagedPayloadPath));
            }
        }
        finally
        {
            if (Directory.Exists(temp))
            {
                Directory.Delete(temp, recursive: true);
            }
        }
    }

    [Fact]
    public void LocalProgressDialog_ReservesProgressBarBandWithoutButtons()
    {
        var dialog = GameDialog.LocalProgress(
            "progress-1",
            "Updating Plumbob Engine",
            "Downloading Plumbob Engine v0.9.0...\n12.4 MB of 48.0 MB",
            "UIGraphics/Community/ngh.bmp");
        dialog.Validate();
        Assert.True(dialog.Blocking);
        Assert.True(dialog.HasProgressBar);
        Assert.Empty(dialog.Buttons);
    }
}
