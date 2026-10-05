using System.Runtime.InteropServices;
using System.Text.Json;
using FSO.Common;
using FSO.Content;
using FSO.Files.Formats.IFF;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Model;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Engine.TSOTransaction;
using FSO.SimAntics.NetPlay.Drivers;
using FSO.SimAntics.NetPlay.Model;
using FSO.SimAntics.Utils;

if (args.Length > 0 && args[0] == "--compile-animation")
{
    if (args.Length is not (3 or 4)) { Console.Error.WriteLine("Usage: SimsSimulation --compile-animation INPUT_JSON NEW_PACK_DIRECTORY [GAME_DIRECTORY]"); return 1; }
    try
    {
        Console.WriteLine(JsonSerializer.Serialize(NativeAnimationAuthor.Compile(args[1], args[2], args.Length == 4 ? args[3] : null), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
        return 0;
    }
    catch (Exception error) when (error is IOException or JsonException or ArgumentException or InvalidDataException)
    {
        Console.Error.WriteLine(error.Message);
        return 1;
    }
}

if (args.Length > 0 && args[0] == "--compile-object")
{
    if (args.Length != 4) { Console.Error.WriteLine("Usage: SimsSimulation --compile-object INPUT_JSON GAME_DIRECTORY NEW_PACK_DIRECTORY"); return 1; }
    try
    {
        Console.WriteLine(JsonSerializer.Serialize(NativeObjectAuthor.Compile(args[1], args[2], args[3]), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
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
        Console.Error.WriteLine(args[0] == "--compile-outfit" ? "Usage: SimsSimulation --compile-outfit INPUT_JSON GAME_DIRECTORY NEW_PACK_DIRECTORY"
            : $"Usage: SimsSimulation {args[0]} TEMPLATE_OUTFIT GAME_DIRECTORY OUTPUT_DIRECTORY");
        return 1;
    }
    try
    {
        var outfitResult = args[0] switch
        {
            "--compile-outfit" => NativeOutfitAuthor.Compile(args[1], args[2], args[3]),
            "--export-outfit-mesh" => NativeOutfitAuthor.ExportMeshes(args[1], args[2], args[3]),
            _ => NativeOutfitAuthor.ExportTextures(args[1], args[2], args[3])
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
    if (args.Length != 4) { Console.Error.WriteLine("Usage: SimsSimulation --export-object-sprites TEMPLATE_IFF GAME_DIRECTORY OUTPUT_DIRECTORY"); return 1; }
    try
    {
        Console.WriteLine(JsonSerializer.Serialize(NativeObjectAuthor.ExportSprites(args[1], args[2], args[3]), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
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
        var import = NativeProfileBootstrap.ImportOriginalUserData(args[1], importDataRoot, args[3], args[4]);
        Console.WriteLine(JsonSerializer.Serialize(import, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
        return 0;
    }
    catch (Exception error) when (error is IOException or UnauthorizedAccessException or InvalidDataException or ArgumentException)
    {
        Console.Error.WriteLine(error.Message);
        return 1;
    }
}

if (args.Length == 1 && args[0] == "--check-frontend-logic")
{
    Console.WriteLine(JsonSerializer.Serialize(NativeFrontendLogicChecks.Run(), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Length is 1 or 2 && args[0] == "--check-plugins")
{
    try
    {
        var pluginFolder = args.Length == 2 ? args[1] : Path.Combine("examples", "plugin-pack", "plugin");
        Console.WriteLine(JsonSerializer.Serialize(NativePluginChecks.Run(pluginFolder), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
        return 0;
    }
    catch (Exception error) when (error is InvalidDataException or IOException)
    {
        Console.Error.WriteLine(error.Message);
        return 1;
    }
}
if (args.Length == 1 && args[0] == "--check-save-compat")
{
    try
    {
        Console.WriteLine(JsonSerializer.Serialize(NativeSaveCompatibilityChecks.Run(), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
        return 0;
    }
    catch (Exception error) when (error is InvalidDataException or IOException)
    {
        Console.Error.WriteLine(error.Message);
        return 1;
    }
}

if (args.Length == 1 && args[0] == "--check-profile-bootstrap")
{
    try
    {
        Console.WriteLine(JsonSerializer.Serialize(NativeProfileBootstrap.Check()));
        return 0;
    }
    catch (Exception error) when (error is IOException or UnauthorizedAccessException or InvalidDataException)
    {
        Console.Error.WriteLine(error.Message);
        return 1;
    }
}

if (args.Length < 2)
{
    Console.Error.WriteLine("Usage: SimsSimulation GAME WORKSPACE [HOUSE] [TICKS] [SCENE] | GAME WORKSPACE --serve SESSION_DIRECTORY [HOUSE] | GAME WORKSPACE --export-neighborhood SESSION_DIRECTORY [MODE] | GAME WORKSPACE --serve-audio SESSION_DIRECTORY");
    return 1;
}

var game = Path.GetFullPath(args[0]);
var workspace = Path.GetFullPath(args[1]);
var dataRootOption = Array.IndexOf(args, "--data-root");
if (dataRootOption >= 0 && (dataRootOption + 1 >= args.Length || args[dataRootOption + 1].StartsWith("--", StringComparison.Ordinal)))
{
    Console.Error.WriteLine("--data-root requires a directory path");
    return 1;
}
var dataRoot = dataRootOption >= 0 && dataRootOption + 1 < args.Length
    ? Path.GetFullPath(args[dataRootOption + 1])
    : workspace;
var profileOption = Array.IndexOf(args, "--profile-id");
var profileId = profileOption >= 0 && profileOption + 1 < args.Length ? args[profileOption + 1] : "player";
var importedHouseholdCheck = args.Length > 2 && args[2] == "--check-imported-household-creation";
if (importedHouseholdCheck && args.Length != 4)
{
    Console.Error.WriteLine("Usage: SimsSimulation GAME WORKSPACE --check-imported-household-creation SOURCE_DIRECTORY");
    return 1;
}
if (importedHouseholdCheck) profileId = "household-import-check-" + Guid.NewGuid().ToString("N");
try { NativeProfileBootstrap.ValidateProfileId(profileId); }
catch (ArgumentException error) { Console.Error.WriteLine(error.Message); return 1; }
var languageOption = Array.IndexOf(args, "--language");
byte languageCode = 1;
if (languageOption >= 0)
{
    if (languageOption + 1 >= args.Length || !byte.TryParse(args[languageOption + 1], out languageCode) || languageCode is < 1 or > 20)
    {
        Console.Error.WriteLine("--language must be a Sims language code from 1 through 20");
        return 1;
    }
}
STR.DefaultLangCode = (STRLangCode)languageCode;
var neighborhoodOption = Array.IndexOf(args, "--neighborhood");
if (neighborhoodOption >= 0)
{
    if (neighborhoodOption + 1 >= args.Length || !int.TryParse(args[neighborhoodOption + 1], out var neighborhoodNumber) ||
        neighborhoodNumber is < 1 or > NativeNeighborhoods.Maximum)
    {
        Console.Error.WriteLine("--neighborhood must be a neighborhood number from 1 through 99");
        return 1;
    }
    NativeNeighborhoods.Current = neighborhoodNumber;
}
var serving = args.Length > 2 && args[2] == "--serve";
var servingAudio = args.Length > 3 && args[2] == "--serve-audio";
var exportingNeighborhood = args.Length > 2 && args[2] == "--export-neighborhood";
var appearanceCatalogRequest = args.Length > 2 && args[2] == "--appearance-catalog";
var appearancePreviewRequest = args.Length > 2 && args[2] == "--appearance-preview";
var moveInCheck = args.Contains("--check-family-move-in");
var editsCheck = args.Contains("--check-neighborhood-edits");
var householdCheck = args.Contains("--check-household-creation") || moveInCheck || editsCheck;
var protocol = serving || servingAudio ? new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = true } : null;
var neighborhoodOutput = exportingNeighborhood ? new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = true } : null;
if (serving || servingAudio || exportingNeighborhood) Console.SetOut(Console.Error);
if (exportingNeighborhood && args.Length < 4)
{
    Console.Error.WriteLine("Usage: SimsSimulation GAME WORKSPACE --export-neighborhood SESSION_DIRECTORY [MODE]");
    return 1;
}
var session = serving || servingAudio || exportingNeighborhood ? Path.GetFullPath(args[3]) : null;
var houseNumber = householdCheck || importedHouseholdCheck || appearanceCatalogRequest || appearancePreviewRequest || servingAudio ? (short)1 : (serving || exportingNeighborhood
    ? (args.Length > 4 && serving ? short.Parse(args[4]) : (short)5)
    : (args.Length > 2 ? short.Parse(args[2]) : (short)1));
var ticks = !serving && !servingAudio && !exportingNeighborhood && !appearanceCatalogRequest && !appearancePreviewRequest && !importedHouseholdCheck && args.Length > 3 ? int.Parse(args[3]) : 0;
if (ticks < 0 || ticks > 10000) throw new ArgumentOutOfRangeException(nameof(ticks));
var profile = householdCheck
    ? Path.Combine(dataRoot, "runtime", "native-checks", "household-" + Guid.NewGuid().ToString("N"))
    : importedHouseholdCheck
    ? Path.Combine(dataRoot, "runtime", "native-profiles", profileId)
    : Path.Combine(dataRoot, "runtime", "native-profiles", serving || servingAudio || exportingNeighborhood ? profileId : "probe");
if (importedHouseholdCheck)
{
    try
    {
        NativeProfileBootstrap.ImportOriginalUserData(game, dataRoot, args[3], profileId);
    }
    catch (Exception error) when (error is IOException or UnauthorizedAccessException or InvalidDataException or ArgumentException)
    {
        Console.Error.WriteLine(error.Message);
        return 1;
    }
}
NativeProfileBootstrap.EnsureImported(game, profile);
var userData = NativeNeighborhoods.UserData(profile);
if (!File.Exists(Path.Combine(userData, "Neighborhood.iff")))
{
    Console.Error.WriteLine($"Neighborhood {NativeNeighborhoods.Current} is not installed in this profile");
    return 1;
}

Directory.SetCurrentDirectory(Path.Combine(workspace, "engine", "Simitone", "FreeSO", "TSOClient", "tso.content"));
FSOEnvironment.ContentDir = Path.Combine(workspace, "engine", "Simitone", "FreeSO", "TSOClient", "tso.content", "Content") + Path.DirectorySeparatorChar;
FSOEnvironment.UserDir = profile + Path.DirectorySeparatorChar;
FSOEnvironment.NoSound = true;
FSOEnvironment.RefreshRate = 60;
FSOEnvironment.Enable3D = false;
Content.Target = FSOEngineMode.TS1;
Content.TS1HybridBasePath = game + Path.DirectorySeparatorChar;
VMContext.BindAssembler();
VMContext.InitVMConfig(true);
Content.Init(game + Path.DirectorySeparatorChar, ContentMode.SERVER);
// The content manager opens neighborhood 1; switch to the selected UserData folder in this profile.
if (NativeNeighborhoods.Current != 1) Content.Get().Neighborhood.InitSpecific(NativeNeighborhoods.Current - 1);
VM.UseWorld = false;
if (servingAudio)
{
    await new NativeFrontendAudioServer(protocol!, session!, profile).Run();
    return 0;
}
if (args.Length == 6 && args[2] == "--appearance-catalog")
{
    var catalog = NativeHouseholdAppearance.Catalog(args[3], args[4], args[5]);
    Console.WriteLine(JsonSerializer.Serialize(catalog, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Length == 9 && args[2] == "--appearance-preview")
{
    Console.WriteLine(JsonSerializer.Serialize(NativeHouseholdAppearancePreview.Export(args[3], args[4], args[5], args[6], args[7], args[8]), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (householdCheck)
{
    try
    {
        var householdResult = editsCheck ? NativeNeighborhoodEdits.Check(game) : moveInCheck ? NativeHouseholdCreation.CheckMoveIn(game, profile) : NativeHouseholdCreation.Check(game, profile);
        Console.WriteLine(JsonSerializer.Serialize(householdResult, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    }
    finally
    {
        if (Directory.Exists(profile)) Directory.Delete(profile, true);
    }
    return 0;
}
if (importedHouseholdCheck)
{
    try
    {
        var selectedSource = Path.GetFullPath(args[3]);
        var nestedUserData = Path.Combine(selectedSource, "UserData");
        var sourceUserData = Directory.Exists(nestedUserData) ? nestedUserData : selectedSource;
        var household = NativeHouseholdCreation.Check(game, profile, sourceUserData);
        Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", originalSaveImported = true, importedProfileIsolated = true, household },
            new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    }
    finally
    {
        if (Directory.Exists(profile)) Directory.Delete(profile, true);
    }
    return 0;
}
if (exportingNeighborhood)
{
    NativeNeighborhoodExport.GameRoot = game;
    var mode = args.Length > 4 && !args[4].StartsWith("--", StringComparison.Ordinal) ? int.Parse(args[4]) : 1;
    var editOption = Array.IndexOf(args, "--edit");
    if (editOption >= 0)
    {
        if (editOption + 1 >= args.Length) { Console.Error.WriteLine("--edit requires evict:HOUSE or delete:FAMILY"); return 1; }
        try { Console.Error.WriteLine(JsonSerializer.Serialize(NativeNeighborhoodEdits.Apply(args[editOption + 1], game))); }
        catch (Exception error) when (error is ArgumentException or InvalidOperationException or IOException)
        {
            Console.Error.WriteLine("Neighborhood edit rejected: " + error.Message);
            return 1;
        }
    }
    var model = NativeNeighborhoodExport.Export(session!, mode);
    neighborhoodOutput!.WriteLine(JsonSerializer.Serialize(model, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--audit-expansions"))
{
    try
    {
        Console.WriteLine(JsonSerializer.Serialize(NativeExpansionAudit.Run(game), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
        return 0;
    }
    catch (InvalidDataException error)
    {
        Console.Error.WriteLine(error.Message);
        return 1;
    }
}
var dumpOption = Array.IndexOf(args, "--dump-behavior");
if (dumpOption >= 0 && dumpOption + 1 < args.Length)
{
    Console.WriteLine(JsonSerializer.Serialize(NativeBehaviorDump.Run(args[dumpOption + 1]), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--audit-animation-tables"))
{
    var missingClips = NativeAnimationTables.Missing();
    var missingReferences = NativeAnimationTables.MissingReferences(Content.Get().WorldObjects.Entries.Keys.Select(key => (uint)key));
    Console.WriteLine(JsonSerializer.Serialize(new { missing = missingClips.Count, clips = missingClips, missingReferences = missingReferences.Count, references = missingReferences },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--audit-behaviors"))
{
    Console.WriteLine(JsonSerializer.Serialize(NativeBehaviorAudit.Run(), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
var vm = SimulationServer.LoadHouse(userData, houseNumber, serving || args.Contains("--check-sleep") || args.Contains("--check-autonomy") || args.Contains("--check-attachments") || args.Contains("--check-lighting") || args.Contains("--check-appearances") || args.Contains("--check-animations") || args.Contains("--check-travel") || args.Contains("--check-relationships") || args.Contains("--check-fundamentals") || args.Contains("--check-expansion-lifecycle") || args.Contains("--check-generic-mode13") || args.Contains("--check-camera-geometry") || args.Contains("--check-object-placement") || args.Contains("--check-sprite-resources") || args.Contains("--check-architecture-history") || args.Contains("--check-career") || args.Contains("--check-career-absence") || args.Contains("--check-outfit-picker") || args.Contains("--check-career-tracks") || args.Contains("--check-career-requirements") || args.Contains("--check-social") || args.Contains("--check-services") || args.Contains("--check-school") || args.Contains("--check-interaction") || args.Contains("--check-visitors") || args.Contains("--check-family-membership"));
if (args.Contains("--check-fundamentals"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", personData = NativePersonDataChecks.Run(),
        neighborhoodVariables = NativeNeighborhoodVariableChecks.Run(vm), primitives = NativePrimitiveChecks.Run(vm),
        houseStatus = NativeHouseStatusChecks.Run(vm) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-clock"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", clock = NativeClockChecks.Run(vm) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-career"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", career = NativeCareerChecks.Run(vm, workspace, profile, game, houseNumber) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-career-tracks"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", audit = NativeCareerTrackChecks.Audit(), missedShifts = NativeCareerTrackChecks.RunMissedShifts(vm) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-career-requirements"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", careerRequirements = NativeCareerRequirementChecks.Run(vm) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-career-absence"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", careerAbsence = NativeCareerAbsenceChecks.Run(vm, workspace, profile, game, houseNumber) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-outfit-picker"))
{
    var pickerOutput = Path.Combine(workspace, "runtime", "native-checks", "outfit-picker");
    if (Directory.Exists(pickerOutput)) Directory.Delete(pickerOutput, true);
    Console.WriteLine(JsonSerializer.Serialize(NativeOutfitPicker.Check(vm, pickerOutput), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-social"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", social = NativeDailyLifeChecks.RunSocial(vm, workspace) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-services"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", services = NativeDailyLifeChecks.RunServices(vm) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-school"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", school = NativeDailyLifeChecks.RunSchool(vm) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-interaction"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", interaction = NativeInteractionChecks.Run(vm) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-visitors"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", visitors = NativeVisitorChecks.Run(vm) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-family-membership"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", membership = NativeFamilyMembershipChecks.Run(vm, workspace, profile, game, houseNumber) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-autonomy"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", autonomy = NativeAutonomyChecks.Run(vm) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-relationships"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", relationships = NativeRelationshipChecks.Run(vm, workspace, profile, game, houseNumber) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-person-data"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", personData = NativePersonDataChecks.Run() }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-expansion-lifecycle"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", expansionLifecycle = NativeExpansionLifecycleChecks.Run(vm) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-generic-mode13"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", genericMode13 = NativeGenericMode13Checks.Run(vm) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-camera-geometry"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", cameraGeometry = NativeCameraGeometryChecks.Run(vm) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-object-placement"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", objectPlacement = NativeObjectPlacementChecks.Run(vm) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-sprite-resources"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", spriteResources = NativeSpriteResourceChecks.Run(vm) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-architecture-history"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", architectureHistory = NativeArchitectureHistoryChecks.Run(vm) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-travel"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", travel = NativeLotTravelChecks.Run(vm, workspace, profile, game, houseNumber) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-animations"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", animations = NativeAnimationChecks.Run(vm, workspace, houseNumber) }, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-appearances"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", appearances = NativeAppearanceChecks.Run(vm, workspace, houseNumber) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-lighting"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", lighting = NativeLightingChecks.Run(vm, workspace, houseNumber) },
        new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
    return 0;
}
if (args.Contains("--check-audio"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", audio = NativeAudioChecks.Run() }));
    return 0;
}
if (args.Contains("--check-attachments"))
{
    Console.WriteLine(JsonSerializer.Serialize(new { result = "passed", slotTransforms = NativeAttachmentChecks.Run(vm), originalWorldParity = true }));
    return 0;
}
if (args.Contains("--check-sleep"))
{
    NativeSleepChecks.Run(vm);
    Console.WriteLine("{\"result\":\"passed\",\"sleepDurations\":[0,1,32767,32768,36000,65535],\"earlyWake\":true,\"interrupt\":true,\"sleepEnergyFractionCarry\":true,\"motiveStateSaveReload\":true}");
    return 0;
}
if (serving)
{
    await new SimulationServer(vm, protocol!, session!, profile, game, houseNumber).Run();
    return 0;
}
for (var index = 0; index < ticks; index++) vm.Update();
if (args.Length > 4) LotSceneExporter.Export(vm, Path.GetFullPath(args[4]), houseNumber, ticks);
Console.WriteLine(JsonSerializer.Serialize(new
{
    architecture = RuntimeInformation.ProcessArchitecture.ToString(),
    backend = "headless TS1 SimAntics",
    house = houseNumber,
    ticks,
    objects = vm.Entities.Count,
    width = vm.Context.Architecture.Width,
    height = vm.Context.Architecture.Height,
    hours = vm.Context.Clock.Hours,
    minutes = vm.Context.Clock.Minutes,
    originalDataModified = false
}));
return 0;
