using System.Diagnostics;
using System.Globalization;
using System.IO.Compression;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace SimsSDL.Client;

public enum UpdateInstallKind
{
    None = 0,
    MacAppBundle = 1,
    PortableDirectory = 2,
}

public sealed record UpdateReleaseInfo(
    string TagName,
    string VersionText,
    Version ParsedVersion,
    string HtmlUrl,
    string? AssetName,
    string? AssetUrl,
    long AssetSize,
    string? AssetSha256);

public sealed record UpdateInstallTarget(
    UpdateInstallKind Kind,
    string TargetRoot,
    string RelaunchPath,
    string? DisableReason)
{
    public bool CanSelfUpdate => Kind != UpdateInstallKind.None && string.IsNullOrEmpty(DisableReason);
}

public readonly record struct UpdateStageProgress(float Fraction, string StatusLine);

public sealed record StagedUpdatePlan(
    UpdateInstallTarget Target,
    string StagingDirectory,
    string StagedPayloadPath,
    IReadOnlyList<string> RelaunchArgs);

public static class ClientUpdater
{
    public const string DefaultFeedUrl = "https://api.github.com/repos/testinglol/plumbob-engine/releases/latest";
    public const string DefaultReleasesPageUrl = "https://github.com/testinglol/plumbob-engine/releases/latest";
    public const string FeedUrlEnvVar = "PLUMBOB_UPDATE_FEED_URL";
    public const string VersionOverrideEnvVar = "PLUMBOB_CLIENT_VERSION_OVERRIDE";
    public const string SkipSwapRelaunchEnvVar = "PLUMBOB_UPDATE_SKIP_SWAP_RELAUNCH";

    private const long MaxDownloadBytes = 1024L * 1024 * 1024;
    private const long MaxExtractedBytes = 2048L * 1024 * 1024;
    private static readonly TimeSpan CheckCooldown = TimeSpan.FromMinutes(15);
    private static readonly TimeSpan CheckRequestTimeout = TimeSpan.FromSeconds(5);
    private static readonly TimeSpan StreamReadTimeout = TimeSpan.FromSeconds(30);

    private static readonly JsonSerializerOptions CacheJsonOptions = new()
    {
        WriteIndented = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
    };

    private sealed class UpdateCheckCacheFile
    {
        [JsonPropertyName("schemaVersion")]
        public int SchemaVersion { get; init; } = 1;

        [JsonPropertyName("feedUrl")]
        public string FeedUrl { get; init; } = "";

        [JsonPropertyName("etag")]
        public string? ETag { get; init; }

        [JsonPropertyName("checkedAtUtc")]
        public DateTimeOffset CheckedAtUtc { get; init; }

        [JsonPropertyName("release")]
        public CachedReleaseDto? Release { get; init; }
    }

    internal sealed class CachedReleaseDto
    {
        [JsonPropertyName("tagName")]
        public string TagName { get; init; } = "";

        [JsonPropertyName("htmlUrl")]
        public string HtmlUrl { get; init; } = "";

        [JsonPropertyName("assetName")]
        public string? AssetName { get; init; }

        [JsonPropertyName("assetUrl")]
        public string? AssetUrl { get; init; }

        [JsonPropertyName("assetSize")]
        public long AssetSize { get; init; }

        [JsonPropertyName("assetSha256")]
        public string? AssetSha256 { get; init; }
    }

    public static (Version Parsed, string Display) GetCurrentVersion(string? explicitOverride = null)
    {
        string? raw = explicitOverride;
        if (string.IsNullOrWhiteSpace(raw) &&
            !string.IsNullOrWhiteSpace(Environment.GetEnvironmentVariable(FeedUrlEnvVar)))
        {
            raw = Environment.GetEnvironmentVariable(VersionOverrideEnvVar);
        }

        if (string.IsNullOrWhiteSpace(raw))
        {
            Assembly asm = typeof(ClientUpdater).Assembly;
            raw = asm.GetCustomAttribute<AssemblyInformationalVersionAttribute>()?.InformationalVersion
                  ?? asm.GetName().Version?.ToString(3);
        }

        if (TryParseReleaseVersion(raw, out Version parsed, out string display))
        {
            return (parsed, display);
        }

        return (new Version(0, 9, 0, 0), "0.9.0");
    }

    public static bool TryParseReleaseVersion(string? raw, out Version version, out string displayText)
    {
        version = new Version(0, 0, 0, 0);
        displayText = "";
        if (string.IsNullOrWhiteSpace(raw))
        {
            return false;
        }

        ReadOnlySpan<char> span = raw.AsSpan().Trim();
        if (span.Length > 0 && (span[0] == 'v' || span[0] == 'V'))
        {
            span = span[1..].Trim();
        }

        int plusIdx = span.IndexOf('+');
        if (plusIdx >= 0)
        {
            span = span[..plusIdx];
        }

        if (span.Length == 0 || span.IndexOf('-') >= 0)
        {
            return false;
        }

        string cleaned = span.ToString();
        string[] parts = cleaned.Split('.');
        if (parts.Length is < 2 or > 4)
        {
            return false;
        }

        int[] nums = new int[4];
        for (int i = 0; i < parts.Length; i++)
        {
            if (!int.TryParse(parts[i], NumberStyles.None, CultureInfo.InvariantCulture, out int value) || value < 0)
            {
                return false;
            }

            nums[i] = value;
        }

        version = new Version(nums[0], nums[1], nums[2], nums[3]);
        displayText = nums[3] > 0
            ? string.Create(CultureInfo.InvariantCulture, $"{nums[0]}.{nums[1]}.{nums[2]}.{nums[3]}")
            : string.Create(CultureInfo.InvariantCulture, $"{nums[0]}.{nums[1]}.{nums[2]}");
        return true;
    }

    public static string? ExpectedAssetName(OSPlatform? platform = null, Architecture? architecture = null)
    {
        Architecture arch = architecture ?? RuntimeInformation.ProcessArchitecture;
        bool isMac = platform.HasValue ? platform.Value == OSPlatform.OSX : OperatingSystem.IsMacOS();
        if (isMac)
        {
            return arch == Architecture.Arm64 ? "Plumbob-Engine-macOS-arm64.zip" : null;
        }

        bool isWin = platform.HasValue ? platform.Value == OSPlatform.Windows : OperatingSystem.IsWindows();
        if (isWin)
        {
            return arch == Architecture.X64 ? "Plumbob-Engine-Windows-x64.zip" : null;
        }

        bool isLinux = platform.HasValue ? platform.Value == OSPlatform.Linux : OperatingSystem.IsLinux();
        if (isLinux)
        {
            return arch == Architecture.X64 ? "Plumbob-Engine-Linux-x64.zip" : null;
        }

        return null;
    }

    public static bool IsAllowedFeedUri(Uri uri) =>
        uri.IsAbsoluteUri &&
        (string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase)
         || (uri.IsLoopback && string.Equals(uri.Scheme, Uri.UriSchemeHttp, StringComparison.OrdinalIgnoreCase)));

    public static bool IsAllowedAssetUri(Uri uri, bool allowLoopback)
    {
        if (!uri.IsAbsoluteUri)
        {
            return false;
        }

        if (allowLoopback && uri.IsLoopback &&
            (string.Equals(uri.Scheme, Uri.UriSchemeHttp, StringComparison.OrdinalIgnoreCase) ||
             string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase)))
        {
            return true;
        }

        if (!string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase))
        {
            return false;
        }

        string host = uri.Host;
        return string.Equals(host, "github.com", StringComparison.OrdinalIgnoreCase)
               || host.EndsWith(".github.com", StringComparison.OrdinalIgnoreCase)
               || host.EndsWith(".githubusercontent.com", StringComparison.OrdinalIgnoreCase);
    }

    public static bool IsAllowedBrowserUri(Uri uri, bool allowLoopback)
    {
        if (!uri.IsAbsoluteUri)
        {
            return false;
        }

        if (allowLoopback && uri.IsLoopback &&
            (string.Equals(uri.Scheme, Uri.UriSchemeHttp, StringComparison.OrdinalIgnoreCase) ||
             string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase)))
        {
            return true;
        }

        if (!string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase))
        {
            return false;
        }

        string host = uri.Host;
        return string.Equals(host, "github.com", StringComparison.OrdinalIgnoreCase)
               || host.EndsWith(".github.com", StringComparison.OrdinalIgnoreCase);
    }

    public static async Task<UpdateReleaseInfo?> CheckForUpdateAsync(
        string dataRoot,
        Version? currentVersionOverride = null,
        string? feedUrlOverride = null,
        HttpMessageHandler? customHandler = null,
        DateTimeOffset? nowUtcOverride = null,
        string? expectedAssetOverride = null,
        CancellationToken cancellationToken = default)
    {
        try
        {
            var (currentVersion, currentDisplay) = currentVersionOverride is not null
                ? (NormalizeVersion(currentVersionOverride), FormatVersion(currentVersionOverride))
                : GetCurrentVersion();

            string? envFeed = Environment.GetEnvironmentVariable(FeedUrlEnvVar);
            string effectiveFeed = !string.IsNullOrWhiteSpace(feedUrlOverride)
                ? feedUrlOverride.Trim()
                : !string.IsNullOrWhiteSpace(envFeed)
                    ? envFeed.Trim()
                    : DefaultFeedUrl;

            if (!Uri.TryCreate(effectiveFeed, UriKind.Absolute, out Uri? feedUri) || !IsAllowedFeedUri(feedUri))
            {
                AppLog.Warn($"Update check skipped: invalid feed URL '{effectiveFeed}'.");
                return null;
            }

            bool isCustomFeed = !string.Equals(effectiveFeed, DefaultFeedUrl, StringComparison.OrdinalIgnoreCase);
            bool allowLoopback = feedUri.IsLoopback;
            string? expectedAsset = expectedAssetOverride ?? ExpectedAssetName();
            DateTimeOffset nowUtc = nowUtcOverride ?? DateTimeOffset.UtcNow;
            string cachePath = Path.Combine(dataRoot, "Settings", "update-check.json");
            UpdateCheckCacheFile? cached = TryReadCache(cachePath);

            if (!isCustomFeed &&
                cached is not null &&
                string.Equals(cached.FeedUrl, effectiveFeed, StringComparison.Ordinal) &&
                cached.Release is not null &&
                nowUtc >= cached.CheckedAtUtc &&
                nowUtc - cached.CheckedAtUtc < CheckCooldown)
            {
                return BuildIfNewer(cached.Release, currentVersion, allowLoopback);
            }

            using var cts = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
            cts.CancelAfter(CheckRequestTimeout);

            using var client = customHandler is not null
                ? new HttpClient(customHandler, disposeHandler: false)
                : new HttpClient();

            using var request = new HttpRequestMessage(HttpMethod.Get, feedUri);
            request.Headers.UserAgent.Add(new ProductInfoHeaderValue("PlumbobEngine", currentDisplay));
            request.Headers.Accept.Add(new MediaTypeWithQualityHeaderValue("application/vnd.github+json"));
            request.Headers.TryAddWithoutValidation("X-GitHub-Api-Version", "2022-11-28");

            if (cached is not null &&
                string.Equals(cached.FeedUrl, effectiveFeed, StringComparison.Ordinal) &&
                !string.IsNullOrWhiteSpace(cached.ETag) &&
                cached.Release is not null)
            {
                request.Headers.TryAddWithoutValidation("If-None-Match", cached.ETag);
            }

            using HttpResponseMessage response = await client.SendAsync(
                request,
                HttpCompletionOption.ResponseContentRead,
                cts.Token).ConfigureAwait(false);

            if (response.StatusCode == HttpStatusCode.NotModified && cached?.Release is not null)
            {
                TryWriteCache(cachePath, new UpdateCheckCacheFile
                {
                    SchemaVersion = 1,
                    FeedUrl = effectiveFeed,
                    ETag = response.Headers.ETag?.ToString() ?? cached.ETag,
                    CheckedAtUtc = nowUtc,
                    Release = cached.Release,
                });
                return BuildIfNewer(cached.Release, currentVersion, allowLoopback);
            }

            if (!response.IsSuccessStatusCode)
            {
                AppLog.Info(FormattableString.Invariant($"Update check returned HTTP {(int)response.StatusCode}."));
                return null;
            }

            string json = await response.Content.ReadAsStringAsync(cts.Token).ConfigureAwait(false);
            CachedReleaseDto? parsedDto = ParseGitHubReleaseJson(json, expectedAsset, allowLoopback);
            if (parsedDto is null)
            {
                return null;
            }

            TryWriteCache(cachePath, new UpdateCheckCacheFile
            {
                SchemaVersion = 1,
                FeedUrl = effectiveFeed,
                ETag = response.Headers.ETag?.ToString(),
                CheckedAtUtc = nowUtc,
                Release = parsedDto,
            });

            UpdateReleaseInfo? candidate = BuildIfNewer(parsedDto, currentVersion, allowLoopback);
            AppLog.Info(candidate is not null
                ? $"Update check: newer release {candidate.TagName} available (current v{currentDisplay}, asset={candidate.AssetName ?? "none"})."
                : $"Update check: client v{currentDisplay} is up to date (latest {parsedDto.TagName}).");
            return candidate;
        }
        catch (Exception ex) when (ex is not OutOfMemoryException)
        {
            AppLog.Info($"Update check skipped ({ex.GetType().Name}: {ex.Message}).");
            return null;
        }
    }

    internal static CachedReleaseDto? ParseGitHubReleaseJson(string json, string? expectedAssetName, bool allowLoopback)
    {
        using var doc = JsonDocument.Parse(json);
        JsonElement root = doc.RootElement;
        if (root.ValueKind != JsonValueKind.Object)
        {
            return null;
        }

        if (root.TryGetProperty("draft", out JsonElement draftProp) && draftProp.ValueKind == JsonValueKind.True)
        {
            return null;
        }

        if (root.TryGetProperty("prerelease", out JsonElement preProp) && preProp.ValueKind == JsonValueKind.True)
        {
            return null;
        }

        if (!root.TryGetProperty("tag_name", out JsonElement tagProp) || tagProp.ValueKind != JsonValueKind.String)
        {
            return null;
        }

        string? tagName = tagProp.GetString()?.Trim();
        if (string.IsNullOrEmpty(tagName) || !TryParseReleaseVersion(tagName, out _, out _))
        {
            return null;
        }

        string htmlUrl = DefaultReleasesPageUrl;
        if (root.TryGetProperty("html_url", out JsonElement htmlProp) &&
            htmlProp.ValueKind == JsonValueKind.String &&
            Uri.TryCreate(htmlProp.GetString(), UriKind.Absolute, out Uri? candidateHtml) &&
            IsAllowedBrowserUri(candidateHtml, allowLoopback))
        {
            htmlUrl = candidateHtml.AbsoluteUri;
        }

        string? matchedName = null;
        string? matchedUrl = null;
        long matchedSize = 0;
        string? matchedSha256 = null;

        if (!string.IsNullOrEmpty(expectedAssetName) &&
            root.TryGetProperty("assets", out JsonElement assetsProp) &&
            assetsProp.ValueKind == JsonValueKind.Array)
        {
            foreach (JsonElement asset in assetsProp.EnumerateArray())
            {
                if (asset.ValueKind != JsonValueKind.Object ||
                    !asset.TryGetProperty("name", out JsonElement nameProp) ||
                    nameProp.ValueKind != JsonValueKind.String)
                {
                    continue;
                }

                string? name = nameProp.GetString();
                if (!string.Equals(name, expectedAssetName, StringComparison.OrdinalIgnoreCase))
                {
                    continue;
                }

                if (!asset.TryGetProperty("browser_download_url", out JsonElement urlProp) ||
                    urlProp.ValueKind != JsonValueKind.String ||
                    !Uri.TryCreate(urlProp.GetString(), UriKind.Absolute, out Uri? downloadUri) ||
                    !IsAllowedAssetUri(downloadUri, allowLoopback))
                {
                    continue;
                }

                matchedName = name;
                matchedUrl = downloadUri.AbsoluteUri;
                if (asset.TryGetProperty("size", out JsonElement sizeProp) &&
                    sizeProp.ValueKind == JsonValueKind.Number &&
                    sizeProp.TryGetInt64(out long parsedSize) &&
                    parsedSize > 0)
                {
                    matchedSize = parsedSize;
                }

                if (asset.TryGetProperty("digest", out JsonElement digestProp) &&
                    digestProp.ValueKind == JsonValueKind.String)
                {
                    matchedSha256 = NormalizeSha256Digest(digestProp.GetString());
                }

                break;
            }
        }

        return new CachedReleaseDto
        {
            TagName = tagName,
            HtmlUrl = htmlUrl,
            AssetName = matchedName,
            AssetUrl = matchedUrl,
            AssetSize = matchedSize,
            AssetSha256 = matchedSha256,
        };
    }

    private static UpdateReleaseInfo? BuildIfNewer(CachedReleaseDto dto, Version currentVersion, bool allowLoopback)
    {
        if (!TryParseReleaseVersion(dto.TagName, out Version remoteVersion, out string displayText))
        {
            return null;
        }

        if (remoteVersion <= currentVersion)
        {
            return null;
        }

        string htmlUrl = DefaultReleasesPageUrl;
        if (Uri.TryCreate(dto.HtmlUrl, UriKind.Absolute, out Uri? parsedHtml) &&
            IsAllowedBrowserUri(parsedHtml, allowLoopback))
        {
            htmlUrl = parsedHtml.AbsoluteUri;
        }

        string? validAssetUrl = null;
        if (!string.IsNullOrEmpty(dto.AssetUrl) &&
            Uri.TryCreate(dto.AssetUrl, UriKind.Absolute, out Uri? parsedAsset) &&
            IsAllowedAssetUri(parsedAsset, allowLoopback))
        {
            validAssetUrl = parsedAsset.AbsoluteUri;
        }

        return new UpdateReleaseInfo(
            dto.TagName,
            displayText,
            remoteVersion,
            htmlUrl,
            validAssetUrl is not null ? dto.AssetName : null,
            validAssetUrl,
            validAssetUrl is not null ? dto.AssetSize : 0,
            validAssetUrl is not null ? NormalizeSha256Digest(dto.AssetSha256) : null);
    }

    internal static string? NormalizeSha256Digest(string? raw)
    {
        if (string.IsNullOrWhiteSpace(raw))
        {
            return null;
        }

        ReadOnlySpan<char> span = raw.AsSpan().Trim();
        if (span.StartsWith("sha256:", StringComparison.OrdinalIgnoreCase))
        {
            span = span["sha256:".Length..].Trim();
        }

        if (span.Length != 64)
        {
            return null;
        }

        for (int i = 0; i < span.Length; i++)
        {
            if (!Uri.IsHexDigit(span[i]))
            {
                return null;
            }
        }

        return span.ToString().ToLowerInvariant();
    }

    public static UpdateInstallTarget ResolveInstallTarget(
        string? baseDirectory = null,
        OSPlatform? platformOverride = null,
        bool? allowWorkspaceBundleOverride = null)
    {
        string rawBase = baseDirectory ?? AppContext.BaseDirectory;
        if (string.IsNullOrWhiteSpace(rawBase))
        {
            return new UpdateInstallTarget(UpdateInstallKind.None, "", "", "missing base directory");
        }

        string normalizedBase = Path.TrimEndingDirectorySeparator(Path.GetFullPath(rawBase));
        bool allowWorkspace = allowWorkspaceBundleOverride
                              ?? !string.IsNullOrWhiteSpace(Environment.GetEnvironmentVariable(FeedUrlEnvVar));

        bool isMac = platformOverride.HasValue ? platformOverride.Value == OSPlatform.OSX : OperatingSystem.IsMacOS();
        if (isMac)
        {
            string? contentsDir = Path.GetDirectoryName(normalizedBase);
            string? bundleDir = contentsDir is not null ? Path.GetDirectoryName(contentsDir) : null;
            if (string.Equals(Path.GetFileName(normalizedBase), "MacOS", StringComparison.OrdinalIgnoreCase) &&
                contentsDir is not null &&
                string.Equals(Path.GetFileName(contentsDir), "Contents", StringComparison.OrdinalIgnoreCase) &&
                bundleDir is not null &&
                bundleDir.EndsWith(".app", StringComparison.OrdinalIgnoreCase) &&
                File.Exists(Path.Combine(contentsDir, "Info.plist")))
            {
                string? bundleParent = Path.GetDirectoryName(bundleDir);
                if (string.IsNullOrEmpty(bundleParent))
                {
                    return new UpdateInstallTarget(UpdateInstallKind.MacAppBundle, bundleDir, bundleDir, "invalid app parent");
                }

                if (!allowWorkspace && File.Exists(Path.Combine(bundleParent, "PlumbobEngine.sln")))
                {
                    return new UpdateInstallTarget(UpdateInstallKind.MacAppBundle, bundleDir, bundleDir, "workspace development bundle");
                }

                if (!CanWriteDirectory(bundleParent) || !CanWriteDirectory(contentsDir))
                {
                    return new UpdateInstallTarget(UpdateInstallKind.MacAppBundle, bundleDir, bundleDir, "install folder is read-only");
                }

                return new UpdateInstallTarget(UpdateInstallKind.MacAppBundle, bundleDir, bundleDir, null);
            }

            return new UpdateInstallTarget(UpdateInstallKind.None, normalizedBase, "", "not running from a macOS .app bundle");
        }

        bool isWin = platformOverride.HasValue ? platformOverride.Value == OSPlatform.Windows : OperatingSystem.IsWindows();
        string exeName = isWin ? "SimsSDL.exe" : "SimsSDL";
        string sdlLibName = isWin ? "SDL3.dll" : "libSDL3.so.0";
        string exePath = Path.Combine(normalizedBase, exeName);
        if (!File.Exists(exePath) ||
            !File.Exists(Path.Combine(normalizedBase, sdlLibName)) ||
            !Directory.Exists(Path.Combine(normalizedBase, "Shaders")) ||
            !Directory.Exists(Path.Combine(normalizedBase, "Packs")))
        {
            return new UpdateInstallTarget(UpdateInstallKind.None, normalizedBase, exePath, "not a standalone release folder");
        }

        if (!allowWorkspace && HasSourceCheckoutAncestor(normalizedBase))
        {
            return new UpdateInstallTarget(UpdateInstallKind.PortableDirectory, normalizedBase, exePath, "workspace build output");
        }

        if (!CanWriteDirectory(normalizedBase))
        {
            return new UpdateInstallTarget(UpdateInstallKind.PortableDirectory, normalizedBase, exePath, "install folder is read-only");
        }

        return new UpdateInstallTarget(UpdateInstallKind.PortableDirectory, normalizedBase, exePath, null);
    }

    public static async Task<StagedUpdatePlan> DownloadAndStageAsync(
        UpdateReleaseInfo release,
        UpdateInstallTarget target,
        string dataRoot,
        IReadOnlyList<string>? relaunchArgs = null,
        Action<UpdateStageProgress>? onProgress = null,
        HttpMessageHandler? customHandler = null,
        bool? useMacDittoOverride = null,
        CancellationToken cancellationToken = default)
    {
        ArgumentNullException.ThrowIfNull(release);
        ArgumentNullException.ThrowIfNull(target);
        if (!target.CanSelfUpdate)
        {
            throw new InvalidOperationException(target.DisableReason ?? "Self-update is unavailable for this installation.");
        }

        if (string.IsNullOrWhiteSpace(release.AssetUrl) ||
            !Uri.TryCreate(release.AssetUrl, UriKind.Absolute, out Uri? assetUri))
        {
            throw new InvalidOperationException("No downloadable release archive is available for this platform.");
        }

        bool allowLoopback = assetUri.IsLoopback &&
                             !string.IsNullOrWhiteSpace(Environment.GetEnvironmentVariable(FeedUrlEnvVar));
        if (customHandler is not null && assetUri.IsLoopback)
        {
            allowLoopback = true;
        }

        if (!IsAllowedAssetUri(assetUri, allowLoopback))
        {
            throw new InvalidOperationException("Blocked untrusted update archive URL.");
        }

        string updatesRoot = Path.Combine(dataRoot, "runtime", "updates");
        Directory.CreateDirectory(updatesRoot);
        string stageDir = Path.Combine(updatesRoot, $"stage-{Guid.NewGuid():N}");
        Directory.CreateDirectory(stageDir);
        string? sameVolumeAppStage = null;

        try
        {
            string headerLine = $"Downloading version {release.VersionText}...";
            onProgress?.Invoke(new UpdateStageProgress(0.02f, $"{headerLine}\nConnecting to GitHub..."));

            string zipPath = Path.Combine(stageDir, release.AssetName ?? "plumbob-update.zip");
            await DownloadArchiveWithHashAsync(
                assetUri,
                zipPath,
                release,
                headerLine,
                onProgress,
                customHandler,
                cancellationToken).ConfigureAwait(false);

            onProgress?.Invoke(new UpdateStageProgress(0.84f, $"{headerLine}\nVerifying archive..."));
            int entryCount = ValidateZipArchiveSafety(zipPath);

            string extractDir = Path.Combine(stageDir, "extracted");
            Directory.CreateDirectory(extractDir);

            bool useDitto = useMacDittoOverride ?? (OperatingSystem.IsMacOS() &&
                                                    target.Kind == UpdateInstallKind.MacAppBundle &&
                                                    File.Exists("/usr/bin/ditto"));
            if (useDitto)
            {
                onProgress?.Invoke(new UpdateStageProgress(0.88f, $"{headerLine}\nUnpacking application bundle..."));
                await ExtractWithMacDittoAsync(zipPath, extractDir, cancellationToken).ConfigureAwait(false);
            }
            else
            {
                ExtractZipManaged(zipPath, extractDir, entryCount, headerLine, onProgress, cancellationToken);
            }

            TryDeleteFile(zipPath);
            onProgress?.Invoke(new UpdateStageProgress(0.96f, $"{headerLine}\nValidating installation files..."));

            string validatedPayload = ValidateExtractedPayload(extractDir, target.Kind);
            if (target.Kind == UpdateInstallKind.MacAppBundle)
            {
                string bundleParent = Path.GetDirectoryName(target.TargetRoot)
                    ?? throw new InvalidOperationException("Missing macOS app bundle parent directory.");
                sameVolumeAppStage = Path.Combine(
                    bundleParent,
                    $".{Path.GetFileName(target.TargetRoot)}.staged-{Guid.NewGuid():N}");
                MoveDirectoryAcrossOrSameVolume(validatedPayload, sameVolumeAppStage);
                validatedPayload = sameVolumeAppStage;
            }

            onProgress?.Invoke(new UpdateStageProgress(1.0f, $"{headerLine}\nRestarting Plumbob Engine..."));
            return new StagedUpdatePlan(
                target,
                stageDir,
                validatedPayload,
                relaunchArgs ?? GetFilteredRelaunchArgs());
        }
        catch
        {
            if (!string.IsNullOrEmpty(sameVolumeAppStage))
            {
                TryDeleteDirectory(sameVolumeAppStage);
            }

            TryDeleteDirectory(stageDir);
            throw;
        }
    }

    public static Process LaunchDetachedSwapAndRelaunch(
        StagedUpdatePlan plan,
        int waitForPid,
        bool relaunch = true)
    {
        ArgumentNullException.ThrowIfNull(plan);
        Directory.CreateDirectory(plan.StagingDirectory);

        if (OperatingSystem.IsWindows())
        {
            return LaunchWindowsSwapScript(plan, waitForPid, relaunch);
        }

        return LaunchPosixSwapScript(plan, waitForPid, relaunch);
    }

    public static void SweepStaleStaging(string dataRoot)
    {
        try
        {
            string updatesRoot = Path.Combine(dataRoot, "runtime", "updates");
            if (!Directory.Exists(updatesRoot))
            {
                return;
            }

            DateTime cutoffUtc = DateTime.UtcNow.AddHours(-1);
            foreach (string dir in Directory.EnumerateDirectories(updatesRoot, "stage-*"))
            {
                try
                {
                    if (Directory.GetCreationTimeUtc(dir) < cutoffUtc)
                    {
                        Directory.Delete(dir, recursive: true);
                    }
                }
                catch
                {
                }
            }
        }
        catch
        {
        }
    }

    private static async Task DownloadArchiveWithHashAsync(
        Uri assetUri,
        string destinationZipPath,
        UpdateReleaseInfo release,
        string headerLine,
        Action<UpdateStageProgress>? onProgress,
        HttpMessageHandler? customHandler,
        CancellationToken cancellationToken)
    {
        using var client = customHandler is not null
            ? new HttpClient(customHandler, disposeHandler: false) { Timeout = Timeout.InfiniteTimeSpan }
            : new HttpClient { Timeout = Timeout.InfiniteTimeSpan };

        var (_, currentDisplay) = GetCurrentVersion();
        using var request = new HttpRequestMessage(HttpMethod.Get, assetUri);
        request.Headers.UserAgent.Add(new ProductInfoHeaderValue("PlumbobEngine", currentDisplay));

        using var connectCts = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
        connectCts.CancelAfter(StreamReadTimeout);
        using HttpResponseMessage response = await client.SendAsync(
            request,
            HttpCompletionOption.ResponseHeadersRead,
            connectCts.Token).ConfigureAwait(false);
        response.EnsureSuccessStatusCode();

        long totalBytes = response.Content.Headers.ContentLength ?? release.AssetSize;
        if (totalBytes > MaxDownloadBytes)
        {
            throw new InvalidDataException("Update archive exceeds maximum permitted download size.");
        }

        using Stream network = await response.Content.ReadAsStreamAsync(cancellationToken).ConfigureAwait(false);
        using var file = new FileStream(destinationZipPath, FileMode.Create, FileAccess.Write, FileShare.None, 65536, useAsync: true);
        using var sha256 = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);

        byte[] buffer = new byte[65536];
        long downloaded = 0;
        long lastReportTick = 0;

        while (true)
        {
            using var readCts = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
            readCts.CancelAfter(StreamReadTimeout);
            int read = await network.ReadAsync(buffer, readCts.Token).ConfigureAwait(false);
            if (read <= 0)
            {
                break;
            }

            downloaded += read;
            if (downloaded > MaxDownloadBytes)
            {
                throw new InvalidDataException("Update archive exceeded maximum permitted download size.");
            }

            sha256.AppendData(buffer, 0, read);
            await file.WriteAsync(buffer.AsMemory(0, read), cancellationToken).ConfigureAwait(false);

            long nowTick = Stopwatch.GetTimestamp();
            if (nowTick - lastReportTick >= Stopwatch.Frequency / 20)
            {
                lastReportTick = nowTick;
                ReportDownloadProgress(downloaded, totalBytes, headerLine, onProgress);
            }
        }

        await file.FlushAsync(cancellationToken).ConfigureAwait(false);
        ReportDownloadProgress(downloaded, totalBytes > 0 ? totalBytes : downloaded, headerLine, onProgress);

        if (release.AssetSize > 0 && downloaded != release.AssetSize)
        {
            throw new InvalidDataException(
                string.Create(CultureInfo.InvariantCulture, $"Incomplete download ({downloaded} of {release.AssetSize} bytes)."));
        }

        if (!string.IsNullOrEmpty(release.AssetSha256))
        {
            string actualHex = Convert.ToHexStringLower(sha256.GetHashAndReset());
            if (!CryptographicOperations.FixedTimeEquals(
                    Encoding.ASCII.GetBytes(actualHex),
                    Encoding.ASCII.GetBytes(release.AssetSha256)))
            {
                throw new InvalidDataException("Downloaded archive failed SHA-256 integrity verification.");
            }
        }
    }

    private static void ReportDownloadProgress(
        long downloaded,
        long totalBytes,
        string headerLine,
        Action<UpdateStageProgress>? onProgress)
    {
        if (onProgress is null)
        {
            return;
        }

        double mbDone = downloaded / (1024.0 * 1024.0);
        float fraction;
        string status;
        if (totalBytes > 0)
        {
            double mbTotal = totalBytes / (1024.0 * 1024.0);
            double raw = Math.Clamp((double)downloaded / totalBytes, 0.0, 1.0);
            fraction = 0.02f + (float)(raw * 0.80);
            status = string.Create(CultureInfo.InvariantCulture, $"{headerLine}\n{mbDone:F1} MB of {mbTotal:F1} MB");
        }
        else
        {
            double raw = 1.0 - 1.0 / (1.0 + mbDone / 25.0);
            fraction = 0.02f + (float)(raw * 0.78);
            status = string.Create(CultureInfo.InvariantCulture, $"{headerLine}\n{mbDone:F1} MB downloaded");
        }

        onProgress(new UpdateStageProgress(fraction, status));
    }

    internal static int ValidateZipArchiveSafety(string zipPath)
    {
        using ZipArchive archive = ZipFile.OpenRead(zipPath);
        if (archive.Entries.Count == 0)
        {
            throw new InvalidDataException("Update archive is empty.");
        }

        string dummyRoot = Path.GetFullPath(Path.Combine(Path.GetTempPath(), "plumbob-zip-check"));
        if (!dummyRoot.EndsWith(Path.DirectorySeparatorChar))
        {
            dummyRoot += Path.DirectorySeparatorChar;
        }

        StringComparison cmp = OperatingSystem.IsWindows() ? StringComparison.OrdinalIgnoreCase : StringComparison.Ordinal;
        long totalUncompressed = 0;
        int fileEntries = 0;

        foreach (ZipArchiveEntry entry in archive.Entries)
        {
            string normalizedName = entry.FullName.Replace('\\', '/');
            if (string.IsNullOrEmpty(normalizedName) ||
                normalizedName.StartsWith("/", StringComparison.Ordinal) ||
                Path.IsPathRooted(entry.FullName))
            {
                throw new InvalidDataException($"Archive contains invalid rooted path: {entry.FullName}");
            }

            string candidate = Path.GetFullPath(Path.Combine(dummyRoot, normalizedName));
            if (!candidate.StartsWith(dummyRoot, cmp))
            {
                throw new InvalidDataException($"Archive entry escapes destination directory: {entry.FullName}");
            }

            if (!normalizedName.EndsWith('/'))
            {
                fileEntries++;
                totalUncompressed = checked(totalUncompressed + Math.Max(0, entry.Length));
                if (totalUncompressed > MaxExtractedBytes)
                {
                    throw new InvalidDataException("Archive exceeds maximum permitted uncompressed size.");
                }
            }
        }

        if (fileEntries == 0)
        {
            throw new InvalidDataException("Update archive contains no files.");
        }

        return fileEntries;
    }

    private static async Task ExtractWithMacDittoAsync(string zipPath, string extractDir, CancellationToken cancellationToken)
    {
        var psi = new ProcessStartInfo("/usr/bin/ditto")
        {
            UseShellExecute = false,
            CreateNoWindow = true,
            RedirectStandardError = true,
        };
        psi.ArgumentList.Add("-x");
        psi.ArgumentList.Add("-k");
        psi.ArgumentList.Add(zipPath);
        psi.ArgumentList.Add(extractDir);

        using Process proc = Process.Start(psi) ?? throw new InvalidOperationException("Failed to start /usr/bin/ditto.");
        string stderr = await proc.StandardError.ReadToEndAsync(cancellationToken).ConfigureAwait(false);
        await proc.WaitForExitAsync(cancellationToken).ConfigureAwait(false);
        if (proc.ExitCode != 0)
        {
            throw new InvalidDataException($"Archive extraction failed (ditto exit {proc.ExitCode}): {stderr.Trim()}");
        }
    }

    private static void ExtractZipManaged(
        string zipPath,
        string extractDir,
        int totalFiles,
        string headerLine,
        Action<UpdateStageProgress>? onProgress,
        CancellationToken cancellationToken)
    {
        string fullRoot = Path.GetFullPath(extractDir);
        if (!fullRoot.EndsWith(Path.DirectorySeparatorChar))
        {
            fullRoot += Path.DirectorySeparatorChar;
        }

        StringComparison cmp = OperatingSystem.IsWindows() ? StringComparison.OrdinalIgnoreCase : StringComparison.Ordinal;
        using ZipArchive archive = ZipFile.OpenRead(zipPath);
        int extractedFiles = 0;

        foreach (ZipArchiveEntry entry in archive.Entries)
        {
            cancellationToken.ThrowIfCancellationRequested();
            string normalized = entry.FullName.Replace('\\', '/');
            if (normalized.StartsWith("__MACOSX/", StringComparison.OrdinalIgnoreCase))
            {
                continue;
            }

            string destPath = Path.GetFullPath(Path.Combine(extractDir, normalized));
            if (!destPath.StartsWith(fullRoot, cmp))
            {
                throw new InvalidDataException($"Archive entry escapes destination directory: {entry.FullName}");
            }

            if (normalized.EndsWith('/'))
            {
                Directory.CreateDirectory(destPath);
                continue;
            }

            string? parentDir = Path.GetDirectoryName(destPath);
            if (!string.IsNullOrEmpty(parentDir))
            {
                Directory.CreateDirectory(parentDir);
            }

            entry.ExtractToFile(destPath, overwrite: true);
            if (!OperatingSystem.IsWindows())
            {
                ApplyUnixEntryPermissions(destPath, entry);
            }

            extractedFiles++;
            if (onProgress is not null && (extractedFiles % 8 == 0 || extractedFiles == totalFiles))
            {
                float frac = 0.84f + 0.11f * Math.Clamp((float)extractedFiles / Math.Max(1, totalFiles), 0f, 1f);
                onProgress(new UpdateStageProgress(frac, $"{headerLine}\nUnpacking files..."));
            }
        }
    }

    private static void ApplyUnixEntryPermissions(string filePath, ZipArchiveEntry entry)
    {
        if (OperatingSystem.IsWindows())
        {
            return;
        }

        int mode = (entry.ExternalAttributes >> 16) & 0x1FF;
        string name = Path.GetFileName(filePath);
        bool mustExecute = string.Equals(name, "SimsSDL", StringComparison.Ordinal) ||
                           name.EndsWith(".dylib", StringComparison.OrdinalIgnoreCase) ||
                           name.Contains(".so", StringComparison.Ordinal);
        if (mustExecute)
        {
            mode |= 0b111_101_101;
        }

        if (mode != 0)
        {
            try
            {
                File.SetUnixFileMode(filePath, (UnixFileMode)mode);
            }
            catch
            {
            }
        }
    }

    internal static string ValidateExtractedPayload(string extractDir, UpdateInstallKind kind)
    {
        if (kind == UpdateInstallKind.MacAppBundle)
        {
            string? appBundle = Directory.EnumerateDirectories(extractDir)
                .Where(static d => !string.Equals(Path.GetFileName(d), "__MACOSX", StringComparison.OrdinalIgnoreCase))
                .FirstOrDefault(static d => d.EndsWith(".app", StringComparison.OrdinalIgnoreCase));
            if (appBundle is null ||
                !File.Exists(Path.Combine(appBundle, "Contents", "Info.plist")) ||
                !File.Exists(Path.Combine(appBundle, "Contents", "MacOS", "SimsSDL")) ||
                !File.Exists(Path.Combine(appBundle, "Contents", "Frameworks", "libSDL3.0.dylib")) ||
                !Directory.Exists(Path.Combine(appBundle, "Contents", "Resources", "Shaders")) ||
                !Directory.Exists(Path.Combine(appBundle, "Contents", "Resources", "Packs")))
            {
                throw new InvalidDataException("Downloaded macOS bundle is missing required Plumbob Engine files.");
            }

            if (!OperatingSystem.IsWindows())
            {
                try
                {
                    File.SetUnixFileMode(
                        Path.Combine(appBundle, "Contents", "MacOS", "SimsSDL"),
                        UnixFileMode.UserRead | UnixFileMode.UserWrite | UnixFileMode.UserExecute |
                        UnixFileMode.GroupRead | UnixFileMode.GroupExecute |
                        UnixFileMode.OtherRead | UnixFileMode.OtherExecute);
                }
                catch
                {
                }
            }

            return appBundle;
        }

        string candidateRoot = extractDir;
        string[] topDirs = Directory.GetDirectories(extractDir)
            .Where(static d => !string.Equals(Path.GetFileName(d), "__MACOSX", StringComparison.OrdinalIgnoreCase))
            .ToArray();
        string[] topFiles = Directory.GetFiles(extractDir);
        if (topFiles.Length == 0 && topDirs.Length == 1)
        {
            candidateRoot = topDirs[0];
        }

        bool hasWin = File.Exists(Path.Combine(candidateRoot, "SimsSDL.exe")) &&
                      File.Exists(Path.Combine(candidateRoot, "SDL3.dll"));
        bool hasLinux = File.Exists(Path.Combine(candidateRoot, "SimsSDL")) &&
                        File.Exists(Path.Combine(candidateRoot, "libSDL3.so.0"));
        if ((!hasWin && !hasLinux) ||
            !Directory.Exists(Path.Combine(candidateRoot, "Shaders")) ||
            !Directory.Exists(Path.Combine(candidateRoot, "Packs")))
        {
            throw new InvalidDataException("Downloaded archive is missing required Plumbob Engine files.");
        }

        return candidateRoot;
    }

    private static Process LaunchPosixSwapScript(StagedUpdatePlan plan, int waitForPid, bool relaunch)
    {
        string scriptPath = Path.Combine(plan.StagingDirectory, "apply-update.sh");
        string scriptBody = plan.Target.Kind == UpdateInstallKind.MacAppBundle
            ? """
              #!/bin/sh
              trap '' HUP
              WAIT_PID="$1"
              TARGET_APP="$2"
              STAGED_APP="$3"
              BACKUP_APP="$4"
              STAGE_DIR="$5"
              RELAUNCH="$6"
              shift 6

              i=0
              while [ "$i" -lt 120 ] && kill -0 "$WAIT_PID" 2>/dev/null; do
                sleep 0.25
                i=$((i + 1))
              done

              rm -rf "$BACKUP_APP" 2>/dev/null || true
              if [ -e "$TARGET_APP" ]; then
                if ! mv "$TARGET_APP" "$BACKUP_APP"; then
                  rm -rf "$STAGED_APP" "$STAGE_DIR" 2>/dev/null || true
                  exit 1
                fi
              fi

              if mv "$STAGED_APP" "$TARGET_APP"; then
                rm -rf "$BACKUP_APP" "$STAGE_DIR" 2>/dev/null || true
                if [ "$RELAUNCH" = "1" ]; then
                  if [ "$#" -gt 0 ]; then
                    open -n "$TARGET_APP" --args "$@" >/dev/null 2>&1 &
                  else
                    open -n "$TARGET_APP" >/dev/null 2>&1 &
                  fi
                fi
                exit 0
              else
                if [ -e "$BACKUP_APP" ]; then
                  mv "$BACKUP_APP" "$TARGET_APP" 2>/dev/null || true
                fi
                rm -rf "$STAGED_APP" "$STAGE_DIR" 2>/dev/null || true
                exit 1
              fi
              """
            : """
              #!/bin/sh
              trap '' HUP
              WAIT_PID="$1"
              TARGET_DIR="$2"
              PAYLOAD_DIR="$3"
              RELAUNCH_EXE="$4"
              STAGE_DIR="$5"
              RELAUNCH="$6"
              shift 6

              i=0
              while [ "$i" -lt 120 ] && kill -0 "$WAIT_PID" 2>/dev/null; do
                sleep 0.25
                i=$((i + 1))
              done

              rm -rf "$TARGET_DIR/Shaders" "$TARGET_DIR/Packs" 2>/dev/null || true
              cp -Rf "$PAYLOAD_DIR"/. "$TARGET_DIR"/
              chmod 755 "$TARGET_DIR/SimsSDL" "$TARGET_DIR/libSDL3.so.0" 2>/dev/null || true
              rm -rf "$STAGE_DIR" 2>/dev/null || true

              if [ "$RELAUNCH" = "1" ]; then
                "$RELAUNCH_EXE" "$@" >/dev/null 2>&1 &
              fi
              exit 0
              """;

        File.WriteAllText(scriptPath, scriptBody.Replace("\r\n", "\n", StringComparison.Ordinal) + "\n", new UTF8Encoding(false));
        if (!OperatingSystem.IsWindows())
        {
            File.SetUnixFileMode(scriptPath, UnixFileMode.UserRead | UnixFileMode.UserWrite | UnixFileMode.UserExecute);
        }

        var psi = new ProcessStartInfo("/bin/sh")
        {
            UseShellExecute = false,
            CreateNoWindow = true,
            WorkingDirectory = Path.GetTempPath(),
        };
        psi.ArgumentList.Add(scriptPath);
        psi.ArgumentList.Add(waitForPid.ToString(CultureInfo.InvariantCulture));
        psi.ArgumentList.Add(plan.Target.TargetRoot);
        psi.ArgumentList.Add(plan.StagedPayloadPath);
        if (plan.Target.Kind == UpdateInstallKind.MacAppBundle)
        {
            string bundleParent = Path.GetDirectoryName(plan.Target.TargetRoot) ?? Path.GetTempPath();
            string backupApp = Path.Combine(bundleParent, $".{Path.GetFileName(plan.Target.TargetRoot)}.backup");
            psi.ArgumentList.Add(backupApp);
        }
        else
        {
            psi.ArgumentList.Add(plan.Target.RelaunchPath);
        }

        psi.ArgumentList.Add(plan.StagingDirectory);
        psi.ArgumentList.Add(relaunch ? "1" : "0");
        foreach (string arg in plan.RelaunchArgs)
        {
            psi.ArgumentList.Add(arg);
        }

        return Process.Start(psi) ?? throw new InvalidOperationException("Could not start update installer helper.");
    }

    private static Process LaunchWindowsSwapScript(StagedUpdatePlan plan, int waitForPid, bool relaunch)
    {
        string scriptPath = Path.Combine(plan.StagingDirectory, "apply-update.ps1");
        const string psBody = """
            param(
                [int]$WaitPid,
                [string]$TargetDir,
                [string]$PayloadDir,
                [string]$RelaunchExe,
                [string]$StageDir,
                [string]$Relaunch,
                [Parameter(ValueFromRemainingArguments = $true)]
                [string[]]$PassArgs
            )
            $ErrorActionPreference = 'Stop'
            if ($WaitPid -gt 0) {
                Wait-Process -Id $WaitPid -Timeout 30 -ErrorAction SilentlyContinue
            }
            $applied = $false
            for ($attempt = 0; $attempt -lt 25; $attempt++) {
                try {
                    $shaders = Join-Path $TargetDir 'Shaders'
                    $packs = Join-Path $TargetDir 'Packs'
                    if (Test-Path $shaders) { Remove-Item -LiteralPath $shaders -Recurse -Force }
                    if (Test-Path $packs) { Remove-Item -LiteralPath $packs -Recurse -Force }
                    Get-ChildItem -LiteralPath $PayloadDir -Force | ForEach-Object {
                        Copy-Item -LiteralPath $_.FullName -Destination $TargetDir -Recurse -Force
                    }
                    $applied = $true
                    break
                } catch {
                    Start-Sleep -Milliseconds 250
                }
            }
            if ($applied -and $Relaunch -eq '1' -and (Test-Path -LiteralPath $RelaunchExe)) {
                if ($PassArgs -and $PassArgs.Count -gt 0) {
                    Start-Process -FilePath $RelaunchExe -WorkingDirectory $TargetDir -ArgumentList $PassArgs
                } else {
                    Start-Process -FilePath $RelaunchExe -WorkingDirectory $TargetDir
                }
            }
            Remove-Item -LiteralPath $StageDir -Recurse -Force -ErrorAction SilentlyContinue
            """;

        File.WriteAllText(scriptPath, psBody, new UTF8Encoding(false));
        var psi = new ProcessStartInfo("powershell.exe")
        {
            UseShellExecute = false,
            CreateNoWindow = true,
            WorkingDirectory = Path.GetTempPath(),
        };
        psi.ArgumentList.Add("-NoProfile");
        psi.ArgumentList.Add("-NonInteractive");
        psi.ArgumentList.Add("-ExecutionPolicy");
        psi.ArgumentList.Add("Bypass");
        psi.ArgumentList.Add("-WindowStyle");
        psi.ArgumentList.Add("Hidden");
        psi.ArgumentList.Add("-File");
        psi.ArgumentList.Add(scriptPath);
        psi.ArgumentList.Add(waitForPid.ToString(CultureInfo.InvariantCulture));
        psi.ArgumentList.Add(plan.Target.TargetRoot);
        psi.ArgumentList.Add(plan.StagedPayloadPath);
        psi.ArgumentList.Add(plan.Target.RelaunchPath);
        psi.ArgumentList.Add(plan.StagingDirectory);
        psi.ArgumentList.Add(relaunch ? "1" : "0");
        foreach (string arg in plan.RelaunchArgs)
        {
            psi.ArgumentList.Add(arg);
        }

        return Process.Start(psi) ?? throw new InvalidOperationException("Could not start Windows update helper.");
    }

    private static IReadOnlyList<string> GetFilteredRelaunchArgs()
    {
        string[] raw = Environment.GetCommandLineArgs();
        if (raw.Length <= 1)
        {
            return [];
        }

        var result = new List<string>(raw.Length - 1);
        for (int i = 1; i < raw.Length; i++)
        {
            result.Add(raw[i]);
        }

        return result;
    }

    private static void MoveDirectoryAcrossOrSameVolume(string sourceDir, string destDir)
    {
        TryDeleteDirectory(destDir);
        try
        {
            Directory.Move(sourceDir, destDir);
            return;
        }
        catch (IOException)
        {
        }

        CopyDirectoryRecursive(sourceDir, destDir);
        TryDeleteDirectory(sourceDir);
    }

    private static void CopyDirectoryRecursive(string sourceDir, string destDir)
    {
        Directory.CreateDirectory(destDir);
        foreach (string file in Directory.GetFiles(sourceDir))
        {
            string targetFile = Path.Combine(destDir, Path.GetFileName(file));
            File.Copy(file, targetFile, overwrite: true);
            if (!OperatingSystem.IsWindows())
            {
                try
                {
                    File.SetUnixFileMode(targetFile, File.GetUnixFileMode(file));
                }
                catch
                {
                }
            }
        }

        foreach (string subDir in Directory.GetDirectories(sourceDir))
        {
            CopyDirectoryRecursive(subDir, Path.Combine(destDir, Path.GetFileName(subDir)));
        }
    }

    private static bool HasSourceCheckoutAncestor(string startDir)
    {
        string? current = Path.TrimEndingDirectorySeparator(Path.GetFullPath(startDir));
        while (!string.IsNullOrEmpty(current))
        {
            if (File.Exists(Path.Combine(current, "PlumbobEngine.sln")) ||
                File.Exists(Path.Combine(current, "native", "SimsSDL", "SimsSDL.csproj")))
            {
                return true;
            }

            string? parent = Path.GetDirectoryName(current);
            if (string.IsNullOrEmpty(parent) || string.Equals(parent, current, StringComparison.Ordinal))
            {
                break;
            }

            current = parent;
        }

        return false;
    }

    private static bool CanWriteDirectory(string directoryPath)
    {
        try
        {
            if (!Directory.Exists(directoryPath))
            {
                return false;
            }

            string probe = Path.Combine(directoryPath, $".plumbob-write-probe-{Guid.NewGuid():N}");
            using (new FileStream(probe, FileMode.CreateNew, FileAccess.Write, FileShare.None, 1, FileOptions.DeleteOnClose))
            {
            }

            return true;
        }
        catch
        {
            return false;
        }
    }

    private static Version NormalizeVersion(Version v) =>
        new(Math.Max(0, v.Major), Math.Max(0, v.Minor), Math.Max(0, v.Build), Math.Max(0, v.Revision));

    private static string FormatVersion(Version v)
    {
        int patch = Math.Max(0, v.Build);
        int rev = Math.Max(0, v.Revision);
        return rev > 0
            ? string.Create(CultureInfo.InvariantCulture, $"{v.Major}.{v.Minor}.{patch}.{rev}")
            : string.Create(CultureInfo.InvariantCulture, $"{v.Major}.{v.Minor}.{patch}");
    }

    private static UpdateCheckCacheFile? TryReadCache(string path)
    {
        try
        {
            if (!File.Exists(path))
            {
                return null;
            }

            UpdateCheckCacheFile? parsed = JsonSerializer.Deserialize<UpdateCheckCacheFile>(File.ReadAllBytes(path), CacheJsonOptions);
            return parsed?.SchemaVersion == 1 ? parsed : null;
        }
        catch
        {
            return null;
        }
    }

    private static void TryWriteCache(string path, UpdateCheckCacheFile data)
    {
        try
        {
            string? dir = Path.GetDirectoryName(path);
            if (!string.IsNullOrEmpty(dir))
            {
                Directory.CreateDirectory(dir);
            }

            string tmp = path + ".tmp-" + Guid.NewGuid().ToString("N");
            File.WriteAllBytes(tmp, JsonSerializer.SerializeToUtf8Bytes(data, CacheJsonOptions));
            File.Move(tmp, path, overwrite: true);
        }
        catch
        {
        }
    }

    private static void TryDeleteFile(string path)
    {
        try
        {
            if (File.Exists(path))
            {
                File.Delete(path);
            }
        }
        catch
        {
        }
    }

    private static void TryDeleteDirectory(string path)
    {
        try
        {
            if (Directory.Exists(path))
            {
                Directory.Delete(path, recursive: true);
            }
        }
        catch
        {
        }
    }
}
