using System.Text.Json;

namespace SimsSimulation;

internal static class ServingEntry
{
    public static async Task<int> Run(string[] args)
    {
        if (args.Length > 0 && args[0] == "--compile-animation")
        {
            if (args.Length is not (3 or 4))
            {
                Console.Error.WriteLine("Usage: SimsSimulation --compile-animation INPUT_JSON NEW_PACK_DIRECTORY [GAME_DIRECTORY]");
                return 1;
            }
            try
            {
                Console.WriteLine(JsonSerializer.Serialize(
                    AnimationAuthor.Compile(args[1], args[2], args.Length == 4 ? args[3] : null),
                    new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
                return 0;
            }
            catch (Exception error) when (error is IOException or JsonException or ArgumentException or InvalidDataException)
            {
                Console.Error.WriteLine(error.Message);
                return 1;
            }
        }

        if (args.Length > 0 && args[0] == "--tso-inventory")
        {
            if (args.Length != 3)
            {
                Console.Error.WriteLine("Usage: SimsSimulation --tso-inventory OBJIFF_FAR OUTPUT_TSV");
                return 1;
            }
            return TsoInventory.Run(args[1], args[2]);
        }

        if (args.Length > 0 && args[0] == "--tso-merge")
        {
            if (args.Length != 4)
            {
                Console.Error.WriteLine("Usage: SimsSimulation --tso-merge TSO_OBJECTS_DIRECTORY NAME OUTPUT_IFF");
                return 1;
            }
            return TsoInventory.Merge(args[1], args[2], args[3]);
        }

        if (args.Length > 0 && args[0] == "--compile-object")
        {
            if (args.Length != 4)
            {
                Console.Error.WriteLine("Usage: SimsSimulation --compile-object INPUT_JSON GAME_DIRECTORY NEW_PACK_DIRECTORY");
                return 1;
            }
            try
            {
                Console.WriteLine(JsonSerializer.Serialize(
                    ObjectAuthor.Compile(args[1], args[2], args[3]),
                    new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
                return 0;
            }
            catch (Exception error) when (error is IOException or InvalidDataException or JsonException or ArgumentException)
            {
                Console.Error.WriteLine(error.Message);
                return 1;
            }
        }

        if (args.Length > 0 && args[0] is "--compile-outfit" or "--export-outfit-textures" or "--export-outfit-mesh")
        {
            if (args.Length != 4)
            {
                Console.Error.WriteLine(args[0] == "--compile-outfit"
                    ? "Usage: SimsSimulation --compile-outfit INPUT_JSON GAME_DIRECTORY NEW_PACK_DIRECTORY"
                    : $"Usage: SimsSimulation {args[0]} TEMPLATE_OUTFIT GAME_DIRECTORY OUTPUT_DIRECTORY");
                return 1;
            }
            try
            {
                var outfitResult = args[0] switch
                {
                    "--compile-outfit" => OutfitAuthor.Compile(args[1], args[2], args[3]),
                    "--export-outfit-mesh" => OutfitAuthor.ExportMeshes(args[1], args[2], args[3]),
                    _ => OutfitAuthor.ExportTextures(args[1], args[2], args[3])
                };
                Console.WriteLine(JsonSerializer.Serialize(outfitResult, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
                return 0;
            }
            catch (Exception error) when (error is IOException or InvalidDataException or JsonException or ArgumentException)
            {
                Console.Error.WriteLine(error.Message);
                return 1;
            }
        }

        if (args.Length > 0 && args[0] == "--export-object-sprites")
        {
            if (args.Length != 4)
            {
                Console.Error.WriteLine("Usage: SimsSimulation --export-object-sprites TEMPLATE_IFF GAME_DIRECTORY OUTPUT_DIRECTORY");
                return 1;
            }
            try
            {
                Console.WriteLine(JsonSerializer.Serialize(
                    ObjectAuthor.ExportSprites(args[1], args[2], args[3]),
                    new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
                return 0;
            }
            catch (Exception error) when (error is IOException or InvalidDataException or JsonException or ArgumentException)
            {
                Console.Error.WriteLine(error.Message);
                return 1;
            }
        }

        if (args.Length > 0 && args[0] == "--import-original-user-data")
        {
            if (args.Length != 5 && (args.Length != 7 || args[5] != "--data-root"))
            {
                Console.Error.WriteLine("Usage: SimsSimulation --import-original-user-data GAME WORKSPACE SOURCE_DIRECTORY PROFILE_ID [--data-root DIRECTORY]");
                return 1;
            }
            try
            {
                var importDataRoot = args.Length == 7 ? Path.GetFullPath(args[6]) : Path.GetFullPath(args[2]);
                var imported = ProfileBootstrap.ImportOriginalUserData(args[1], importDataRoot, args[3], args[4]);
                Console.WriteLine(JsonSerializer.Serialize(imported, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
                return 0;
            }
            catch (Exception error) when (error is IOException or UnauthorizedAccessException or InvalidDataException or ArgumentException)
            {
                Console.Error.WriteLine(error.Message);
                return 1;
            }
        }

        if (args.Length is 1 or 2 && args[0] == "--check-plugins")
        {
            try
            {
                var pluginFolder = args.Length == 2 ? args[1] : Path.Combine("examples", "plugin-pack", "plugin");
                Console.WriteLine(JsonSerializer.Serialize(
                    PluginChecks.Run(pluginFolder),
                    new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
                return 0;
            }
            catch (Exception error) when (error is InvalidDataException or IOException)
            {
                Console.Error.WriteLine(error.Message);
                return 1;
            }
        }

        if (args.Length is 2 or 3 && args[0] == "--check-native-floor-art")
        {
            try
            {
                Console.WriteLine(JsonSerializer.Serialize(
                    FloorArtworkChecks.Run(args[1], args.Length == 3 ? args[2] : null),
                    new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
                return 0;
            }
            catch (Exception error) when (error is IOException or UnauthorizedAccessException or InvalidDataException or SimsEngine.Formats.ResourceFormatException)
            {
                Console.Error.WriteLine(error.Message);
                return 1;
            }
        }

        if (args.Length == 1 && args[0] == "--check-profile-bootstrap")
        {
            try
            {
                Console.WriteLine(JsonSerializer.Serialize(ProfileBootstrap.Check()));
                return 0;
            }
            catch (Exception error) when (error is IOException or UnauthorizedAccessException or InvalidDataException)
            {
                Console.Error.WriteLine(error.Message);
                return 1;
            }
        }

        if (args.Length >= 2 && args[0] == "--audit-bytecode")
        {
            string? outputDir = null;
            for (var i = 2; i < args.Length; i++)
            {
                if (args[i] == "--out" && i + 1 < args.Length) outputDir = args[++i];
                else
                {
                    Console.Error.WriteLine($"Unknown option for --audit-bytecode: {args[i]}");
                    return 1;
                }
            }
            var report = InteractionCensus.Run(args[1], outputDir);
            Console.WriteLine(InteractionCensus.FormatSummary(report));
            return 0;
        }

        if (args.Length >= 3 && args[0] == "--audit-interactions")
        {
            string? outputDir = null;
            string? packFilter = null;
            var ticks = 450;
            int? limit = null;
            short houseNumber = 5;
            var subhoods = false;
            var includeTravel = false;
            var shippedLots = false;
            var socials = false;
            var chained = false;
            var states = false;
            var actorMode = "adult";
            uint? guidFilter = null;
            byte lang = 1;
            for (var i = 3; i < args.Length; i++)
            {
                switch (args[i])
                {
                    case "--out" when i + 1 < args.Length: outputDir = args[++i]; break;
                    case "--pack" when i + 1 < args.Length: packFilter = args[++i]; break;
                    case "--ticks" when i + 1 < args.Length && int.TryParse(args[i + 1], out var parsedTicks) && parsedTicks > 0:
                        ticks = parsedTicks; i++; break;
                    case "--limit" when i + 1 < args.Length && int.TryParse(args[i + 1], out var parsedLimit) && parsedLimit > 0:
                        limit = parsedLimit; i++; break;
                    case "--house" when i + 1 < args.Length && short.TryParse(args[i + 1], out var parsedHouse) && parsedHouse > 0:
                        houseNumber = parsedHouse; i++; break;
                    case "--language" when i + 1 < args.Length && byte.TryParse(args[i + 1], out var parsedLang) && parsedLang is >= 1 and <= 20:
                        lang = parsedLang; i++; break;
                    case "--guid" when i + 1 < args.Length && TryParseGuid(args[i + 1], out var parsedGuid):
                        guidFilter = parsedGuid; i++; break;
                    case "--actor-mode" when i + 1 < args.Length && args[i + 1] is "adult" or "child" or "dog" or "cat":
                        actorMode = args[++i]; break;
                    case "--subhoods": subhoods = true; break;
                    case "--shipped-lots": shippedLots = true; break;
                    case "--socials": socials = true; break;
                    case "--chained": chained = true; break;
                    case "--states": states = true; break;
                    case "--include-travel": includeTravel = true; break;
                    default:
                        Console.Error.WriteLine($"Unknown or invalid option for --audit-interactions: {args[i]}");
                        return 1;
                }
            }
            var sweepOptions = new SweepOptions(args[1], args[2], outputDir, packFilter, ticks, limit, houseNumber, subhoods, includeTravel, lang, guidFilter, shippedLots, actorMode, socials, chained, states);
            var sweepReport = InteractionOutcomeSweeper.Run(sweepOptions);
            Console.WriteLine(InteractionOutcomeSweeper.FormatClustersMarkdown(sweepReport, sweepOptions));
            return 0;
        }

        HashSet<string> knownFlags =
        [
            "--serve", "--export-neighborhood", "--serve-audio", "--appearance-catalog", "--appearance-preview",
            "--batch-run", "--install-root", "--data-root", "--profile-id", "--language", "--neighborhood",
            "--edit", "--web-scenes"
        ];
        foreach (var arg in args)
        {
            if (arg.StartsWith("--", StringComparison.Ordinal) && !knownFlags.Contains(arg))
            {
                Console.Error.WriteLine($"Unknown option: {arg}");
                return 1;
            }
        }

        var batchRunOption = Array.IndexOf(args, "--batch-run");
        int batchTicks = 0;
        if (batchRunOption >= 0)
        {
            if (batchRunOption + 1 >= args.Length || !int.TryParse(args[batchRunOption + 1], out batchTicks) || batchTicks <= 0)
            {
                Console.Error.WriteLine("--batch-run requires a positive integer tick count");
                return 1;
            }
        }

        if (batchTicks == 0)
        {
            var hasValidSubcommand = args.Length >= 3 && args[2] is "--serve" or "--export-neighborhood"
                or "--serve-audio" or "--appearance-catalog" or "--appearance-preview";
            if (!hasValidSubcommand || (args[2] == "--serve" && (args.Length < 4 || args[3].StartsWith("--", StringComparison.Ordinal) || int.TryParse(args[3], out _))))
            {
                Console.Error.WriteLine("Usage: SimsSimulation GAME WORKSPACE --serve SESSION_DIRECTORY [HOUSE]");
                return 1;
            }
        }

        var installRootOption = Array.IndexOf(args, "--install-root");
        if (installRootOption >= 0 && (installRootOption + 1 >= args.Length || args[installRootOption + 1].StartsWith("--", StringComparison.Ordinal)))
        {
            Console.Error.WriteLine("--install-root requires an installed game directory");
            return 1;
        }

        string game;
        string workspace;
        if (args.Length >= 2 && !args[0].StartsWith("--", StringComparison.Ordinal) && !args[1].StartsWith("--", StringComparison.Ordinal))
        {
            game = Path.GetFullPath(args[0]);
            workspace = Path.GetFullPath(args[1]);
        }
        else
        {
            var defaultGame = Path.GetFullPath(Directory.Exists("The Sims 1") ? "The Sims 1" : (Directory.Exists("runtime/game") ? "runtime/game" : "."));
            game = installRootOption >= 0 ? Path.GetFullPath(args[installRootOption + 1]) : defaultGame;
            workspace = Directory.Exists("runtime/game") ? Path.GetFullPath("runtime/game") : Path.GetFullPath(".");
        }

        var session = batchTicks > 0
            ? Path.Combine(Path.GetTempPath(), "sims-batch-" + Guid.NewGuid().ToString("N"))
            : (args.Length > 3 && !args[3].StartsWith("--", StringComparison.Ordinal)
                ? Path.GetFullPath(args[3])
                : Path.Combine(workspace, "batch-session"));
        var house = args.Length > 4 && short.TryParse(args[4], out var h) && h >= 0 ? h : (short)5;
        var dataRootOption = Array.IndexOf(args, "--data-root");
        if (dataRootOption >= 0 && (dataRootOption + 1 >= args.Length || args[dataRootOption + 1].StartsWith("--", StringComparison.Ordinal)))
        {
            Console.Error.WriteLine("--data-root requires a directory path");
            return 1;
        }
        var dataRoot = dataRootOption >= 0 && dataRootOption + 1 < args.Length
            ? Path.GetFullPath(args[dataRootOption + 1])
            : workspace;
        var installRoot = installRootOption >= 0
            ? Path.GetFullPath(args[installRootOption + 1])
            : ResolveInstallRoot(game, workspace);
        var profileOption = Array.IndexOf(args, "--profile-id");
        var profileId = profileOption >= 0 && profileOption + 1 < args.Length ? args[profileOption + 1] : "player";
        try { ProfileBootstrap.ValidateProfileId(profileId); }
        catch (ArgumentException error) { Console.Error.WriteLine(error.Message); return 1; }

        var languageCode = (byte)1;
        var languageOption = Array.IndexOf(args, "--language");
        if (languageOption >= 0 && (languageOption + 1 >= args.Length ||
            !byte.TryParse(args[languageOption + 1], out languageCode) || languageCode is < 1 or > 20))
        {
            Console.Error.WriteLine("--language must be a Sims language code from 1 through 20");
            return 1;
        }

        var neighborhoodOption = Array.IndexOf(args, "--neighborhood");
        if (neighborhoodOption >= 0)
        {
            if (neighborhoodOption + 1 >= args.Length || !int.TryParse(args[neighborhoodOption + 1], out var neighborhood) ||
                neighborhood is < 1 or > Neighborhoods.Maximum)
            {
                Console.Error.WriteLine("--neighborhood must be a neighborhood number from 1 through 99");
                return 1;
            }
            Neighborhoods.Current = neighborhood;
        }

        var profile = Path.Combine(dataRoot, "runtime", "profiles", profileId);
        try
        {
            ProfileBootstrap.EnsureNeighborhoodImported(installRoot, profile, Neighborhoods.Current);
        }
        catch (Exception error) when (error is IOException or UnauthorizedAccessException or InvalidDataException or ArgumentException)
        {
            Console.Error.WriteLine(error.Message);
            return 1;
        }
        var userData = Neighborhoods.UserData(profile);
        if (!File.Exists(Path.Combine(userData, "Neighborhood.iff")))
        {
            Console.Error.WriteLine($"Neighborhood {Neighborhoods.Current} is not installed in this profile");
            return 1;
        }

        if (args.Length > 2 && args[2] == "--export-neighborhood")
        {
            var exportSession = Path.GetFullPath(args[3]);
            var mode = args.Length > 4 && !args[4].StartsWith("--", StringComparison.Ordinal)
                ? short.Parse(args[4])
                : (short)1;
            var editOption = Array.IndexOf(args, "--edit");
            if (editOption >= 0 && editOption + 1 < args.Length)
            {
                NeighborhoodEdits.Apply(args[editOption + 1], installRoot, profile, languageCode, mode);
            }
            var includeWebScenes = Array.IndexOf(args, "--web-scenes") >= 0;
            NeighborhoodExport.Export(exportSession, mode, profile, languageCode, dataRoot, game, includeRenderScenes: includeWebScenes);
            return 0;
        }

        if (args.Length > 2 && args[2] == "--serve-audio")
        {
            var audioSession = Path.GetFullPath(args[3]);
            var audioProtocol = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = true };
            Console.SetOut(Console.Error);
            await new FrontendAudioServer(audioProtocol, audioSession, profile, installRoot, languageCode).Run();
            return 0;
        }

        if (args.Length > 2 && args[2] == "--appearance-catalog")
        {
            if (args.Length < 6)
            {
                Console.Error.WriteLine("Usage: SimsSimulation GAME WORKSPACE --appearance-catalog GENDER AGE SKIN");
                return 1;
            }
            var registry = SimsEngine.Content.ObjectRegistry.Scan(installRoot, Path.Combine(userData, "Characters"));
            var catalog = HouseholdAppearance.Catalog(installRoot, registry, args[3], args[4], args[5]);
            Console.WriteLine(JsonSerializer.Serialize(catalog));
            return 0;
        }

        if (args.Length > 2 && args[2] == "--appearance-preview")
        {
            if (args.Length < 9)
            {
                Console.Error.WriteLine("Usage: SimsSimulation GAME WORKSPACE --appearance-preview SESSION GENDER AGE SKIN HEAD BODY");
                return 1;
            }
            var registry = SimsEngine.Content.ObjectRegistry.Scan(installRoot, Path.Combine(userData, "Characters"));
            var previewSession = Path.GetFullPath(args[3]);
            var preview = HouseholdAppearancePreview.Export(
                previewSession, installRoot, registry, args[4], args[5], args[6], args[7], args[8]);
            Console.WriteLine(JsonSerializer.Serialize(preview));
            return 0;
        }

        if (batchTicks > 0)
        {
            try
            {
                var batchServer = SimsSimulation.SimulationServer.Load(installRoot, session, profile, house, StreamWriter.Null, languageCode);
                var completed = batchServer.BatchRun(batchTicks);
                Console.Error.WriteLine($"Headless batch run completed {completed}/{batchTicks} ticks.");
                return 0;
            }
            finally
            {
                if (Directory.Exists(session))
                {
                    try { Directory.Delete(session, true); } catch { }
                }
            }
        }

        var protocol = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = true };
        Console.SetOut(Console.Error);
        var server = SimsSimulation.SimulationServer.Load(game, session, profile, house, protocol, languageCode);
        await server.Run();
        return 0;
    }

    private static bool TryParseGuid(string text, out uint guid)
    {
        if (text.StartsWith("0x", StringComparison.OrdinalIgnoreCase))
            return uint.TryParse(text.AsSpan(2), System.Globalization.NumberStyles.HexNumber, System.Globalization.CultureInfo.InvariantCulture, out guid);
        return uint.TryParse(text, System.Globalization.NumberStyles.Integer, System.Globalization.CultureInfo.InvariantCulture, out guid);
    }

    private static string ResolveInstallRoot(string game, string workspace)
    {
        if (Directory.Exists(Path.Combine(game, "UserData"))) return game;
        var gameDataPath = Path.Combine(game, "GameData");
        if (Directory.Exists(gameDataPath) &&
            new DirectoryInfo(gameDataPath).ResolveLinkTarget(true)?.FullName is { } resolvedGameData &&
            Path.GetDirectoryName(resolvedGameData) is { } parent &&
            Directory.Exists(Path.Combine(parent, "UserData")))
            return parent;
        if (SimsSimulation.SimulationServer.TryReadSavedInstallRoot(workspace) is { } savedInstall &&
            Directory.Exists(Path.Combine(savedInstall, "UserData")))
            return Path.GetFullPath(savedInstall);
        if (Environment.GetEnvironmentVariable("SIMS_GAME_DIR") is { Length: > 0 } envGame &&
            Directory.Exists(Path.Combine(envGame, "UserData")))
            return Path.GetFullPath(envGame);
        foreach (var candidate in new[] { Path.Combine(workspace, "runtime", "game"), Path.Combine(workspace, "The Sims 1") })
            if (Directory.Exists(Path.Combine(candidate, "UserData")))
                return Path.GetFullPath(candidate);
        return game;
    }
}
