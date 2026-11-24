using System.Buffers.Binary;
using System.Diagnostics;
using System.Security.Cryptography;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsSimulation;

internal sealed partial class SimulationServer
{
    internal sealed record SavedDialogSnapshot(string Token, short OwnerId, short? IconId, byte Kind, string Title,
        string Message, string? Yes, string? No, string? Cancel, bool Blocking, bool AwaitsResponse, int State,
        bool Visible, ushort ImageBitmapId, byte? BookMode = null);

    internal sealed record SaveRuntimeMetadata(int Version, int Speed, PersonAnimationRuntimeSnapshot[]? PersonAnimations = null,
        string? LotSha256 = null, SavedDialogSnapshot[]? Dialogs = null, int? Budget = null,
        IReadOnlyList<int>? RestrictedActivePersonKeys = null, SavedSuspendedHomeLot? SuspendedHome = null,
        int? ClockTicks = null, int? ClockDay = null);

    internal sealed record SavedSuspendedHomeLot(short HomeHouse, ushort? HomeFamilyChunkId, string LotState,
        SaveRuntimeMetadata Runtime, int Speed);

    internal sealed record SaveEnvelope(int SchemaVersion, string Engine, string PackFingerprint, short House, long Updates,
        string State, SaveCompatibility.PackRecord[]? Packs = null,
        Dictionary<string, PluginHost.PluginSaveRecord>? Plugins = null, int Neighborhood = 1,
        SaveRuntimeMetadata? Runtime = null, string? NeighborhoodState = null,
        SavedSuspendedHomeLot? SuspendedHome = null,
        IReadOnlyList<int>? RestrictedActivePersonKeys = null,
        [property: JsonIgnore(Condition = JsonIgnoreCondition.WhenWritingNull)]
        string? CorePackFingerprint = null);

    private static readonly JsonSerializerOptions Json = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        NumberHandling = JsonNumberHandling.AllowNamedFloatingPointLiterals,
    };
    private static double TickIntervalSeconds(int speed) => speed switch
    {
        3 => (172.0 - 171.0 * 924.0 / 1000.0) / 1000.0,
        10 => (172.0 - 171.0 * 994.0 / 1000.0) / 1000.0,
        _ => (172.0 - 171.0 * 760.0 / 1000.0) / 1000.0,
    };
    private readonly TextWriter output;
    private readonly string session;
    private readonly string profile;
    private readonly string dataRoot;
    private readonly string game;
    private short house;
    private readonly byte language;
    private SimulationWorld? world;
    public SimulationWorld? World => world;
    private FameTuning? fameTuning;
    private IReadOnlyList<string>? fameTitles;
    private IffFile? lot;
    private ObjectRegistry? registry;
    private SuspendedHomeLot? suspendedHomeLot;
    private (ushort FamilyChunkId, int VacationHouse)? committedVacationState;
    private int? lastTravelNeighborhoodMode;
    private readonly Dictionary<uint, IffFile> refreshedPersonFiles = new();

    private sealed record SuspendedHomeLot(short HomeHouse, ushort? HomeFamilyChunkId, byte[] LotBytes,
        SaveRuntimeMetadata Runtime, int Speed);
    private PanelImages? images;
    private IffFile? global;
    private string? neighborhoodPath;
    private IffFile? neighborhood;
    private ushort? activeFamilyChunkId;
    private readonly string? loadError;
    private long updates;
    private long revision;
    private long previewRevision;
    private bool running = true;
    private bool streaming;
    private bool simulatorBlocked;
    private readonly SceneExporter.AnimationState animationState = new();
    private long animationSequence;
    private int speed;
    private int lastRunningSpeed = 1;
    private int autoSpeedSaved = -1;
    private Dictionary<ushort, char>? floorSoundCodes;
    private string wallMode = "down";
    private bool editingView;
    private bool doorWindowBuildToolActive;
    private bool wallpaperBuildToolActive;
    private bool roofsVisible;
    private (int X, int Y)? cutawayTile;
    private readonly List<ushort> cutawayRooms = [];
    private long exportedCutawaySimKey = -1;
    private int exportedFoliageStage;
    private int cutawayZoom = 2;
    private int cameraOrientation;
    private readonly TutorialEvents tutorialEvents = new();
    private short viewerMode;
    private short viewerScale;
    private int? lastButtonImage;
    private short lastButtonPerson;
    private bool saveDirty;
    private int dialogResumeSpeed;
    private string? simulationError;
    private int loggedThreadErrors;
    private int loggedInteractionGuardErrors;
    private int loggedQueuedInteractionStarts;
    private int loggedPrimitiveResults;
    private int loggedExecutionTraces;
    private int loggedRinkInitTraces;
    private int loggedNativeRoutes;
    private int loggedRouteSearches;
    private int loggedRouteCandidates;
    private bool loggedSimRoster;
    private short selectedSim;
    private bool familyMembershipChangedDuringTick;
    private readonly bool profile_ = Environment.GetEnvironmentVariable("SIMS_PROFILE") is not null;
    private TimeSpan tickTime;
    private TimeSpan animationTime;
    private double maxTickMs;
    private long profileWindowStart;
    private int animationsTimed;
    private double nextAnimation;
    private float lastSubTickAlpha;
    private int ticksTimed;
    private (short Sim, long Tick, List<AvatarSceneGeometry.PosedHeadMesh> Meshes)? pieHead;
    private int viewLevel = 1;
    private readonly bool traceActions = Environment.GetEnvironmentVariable("SIMS_NATIVE_TRACE_ACTIONS") == "1";
    private readonly bool testFixtureEnabled = Environment.GetEnvironmentVariable("SIMS_NATIVE_TEST_FIXTURE") == "1";
    private bool testFixtureStartPositionUsed;
    private PluginHost? plugins;
    private PluginWorld? pluginWorld;
    private readonly string packFingerprint;
    private readonly string? corePackFingerprint;
    private readonly string? explicitInstallRoot;
    private HitAudioRuntime? audio;
    private SimOutfits? engineOutfits;
    private SimAppearanceTransitionService? appearanceTransitions;
    private string? lastCheatCommand;

    private void ResetAppearanceTransitions() => appearanceTransitions?.Reset(world);
    private (int FurnishingsObjects, int ArchitectureObjects) initialObjectValuation;
    private IffFile? initialValuationLot;
    private bool lotValuationEdited;
    internal Action<SceneExporter.DirectAnimationFrame>? DirectAnimationSink { get; set; }
    private static bool IsExplicitNativeEnv =>
        string.Equals(Environment.GetEnvironmentVariable("SIMS_ENGINE")?.Trim(), "native", StringComparison.OrdinalIgnoreCase);

    private string SceneDirectory => IsExplicitNativeEnv ? session : Path.Combine(session, "scene");

    private readonly DirectPackOverlay? packOverlay;

    private SimulationServer(TextWriter output, string session, string profile, string game, short house, SimulationWorld? world, IffFile? lot,
        ObjectRegistry? registry, IffFile? global, string? loadError, byte language = 1,
        string? neighborhoodPath = null, IffFile? neighborhood = null, ushort? activeFamilyChunkId = null,
        string? installRoot = null, DirectPackOverlay? packOverlay = null)
    {
        this.output = output;
        this.session = session;
        this.profile = profile;
        this.game = game;
        this.explicitInstallRoot = installRoot;
        this.packOverlay = packOverlay;
        this.house = house;
        this.world = world;
        this.lot = lot;
        this.registry = registry;
        Directory.CreateDirectory(session);
        Directory.CreateDirectory(SceneDirectory);
        images = registry is null ? null : new PanelImages(SceneDirectory, registry);
        this.global = global;
        this.neighborhoodPath = neighborhoodPath;
        this.neighborhood = neighborhood;
        this.activeFamilyChunkId = activeFamilyChunkId;
        this.loadError = loadError;
        this.language = language;
        var metadata = Path.Combine(game, ".pack-stack.json");
        var metadataJson = packOverlay?.PackStackJson ?? (File.Exists(metadata) ? File.ReadAllText(metadata) : null);
        if (metadataJson != null)
        {
            using var metadataDoc = JsonDocument.Parse(metadataJson);
            packFingerprint = metadataDoc.RootElement.GetProperty("fingerprint").GetString() ?? "unmounted-base-1.90";
            corePackFingerprint = metadataDoc.RootElement.TryGetProperty("coreFingerprint", out var coreProp) &&
                                  coreProp.ValueKind == JsonValueKind.String
                ? coreProp.GetString()
                : null;
        }
        else
        {
            packFingerprint = "unmounted-base-1.90";
            corePackFingerprint = null;
        }
        audio = new HitAudioRuntime(Path.Combine(session, "audio"), profile, Write, game)
        {
            SuppressActiveDuplicates = true
        };
        this.dataRoot = Path.GetFullPath(Path.Combine(profile, "..", "..", ".."));
        this.pluginWorld = new SimsSimulation.PluginWorld(
            () => this.world,
            () => this.house,
            () => this.activeFamilyChunkId,
            () => this.registry,
            () => this.speed == 0,
            () => this.lot,
            () => LotWidth,
            person => appearanceTransitions?.HasOverride(person) ?? false,
            (person, prefix, bodySlot) => EnsureAppearanceTransitions()?.ResolveCategorySuit(person, prefix, bodySlot),
            (simId, suitSpec, animate) => EnsureAppearanceTransitions()?.SetAppearanceOverride(simId, suitSpec, animate),
            () => this.IsVisitingAwayLot,
            () => this.FamilyFriends());
        plugins = PluginHost.Create(game, dataRoot, Write, () => this.house,
            host => this.pluginWorld, userData: Neighborhoods.UserData(profile), world: this.pluginWorld,
            playSoundResource: (path, owner, cue, loop) => audio.PlayResource(path, owner, cue, loop),
            stopSoundResource: (owner, cue) => audio.StopResource(owner, cue),
            packOverlay: packOverlay);
        this.pluginWorld.SetInteractionFilter(plugins.AllowInteraction);
        if (world is not null)
        {
            if (registry is not null)
            {
                world.UiTextFile ??= registry.UiText;
                var avatarGeometry = AvatarSceneGeometry.For(game, registry);
            }
            AttachTutorialFlash(world);
        }
        if (traceActions && world is not null) world.CaptureExecutionTrace = true;
        selectedSim = DefaultSelectedSimId();
        if (world is not null) SyncSelectedSimFlags(world, selectedSim);
        InitializeViewLevelFromSelectedSim();
        Directory.CreateDirectory(session);
        if (world is not null) AttachNoticeListener(world);
        ResetLotValuationBaseline();
    }

    private void AttachTutorialFlash(SimulationWorld targetWorld)
    {
        targetWorld.TutorialFlash = (kind, value, on) =>
        {
            if (!ReferenceEquals(world, targetWorld)) return;
            switch (kind)
            {
                case TutorialFlashKind.ImageButton:
                    Write(new { type = "tutorialFlash", target = "image", value = (int)value, on });
                    break;
                case TutorialFlashKind.PersonButton:
                    if (targetWorld.Neighbors.ContainsKey(value)
                        && targetWorld.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person[PersonData.NeighborId] == value) is { } sim)
                        Write(new { type = "tutorialFlash", target = "person", value = (int)sim.Id, on });
                    break;
                case TutorialFlashKind.RelationshipButton:
                    if (targetWorld.Neighbors.ContainsKey(value)) Write(new { type = "tutorialFlash", target = "relationship", value = (int)value, on });
                    break;
            }
        };
    }

    private ObjectRegistry EnsureRegistry()
    {
        if (registry is null)
        {
            var charsDir = Path.Combine(Neighborhoods.UserData(profile), "Characters");
            registry = ObjectRegistry.Scan(game, charsDir);
        }
        images ??= new PanelImages(SceneDirectory, registry);
        global ??= WorldBootstrap.GetOrLoadGlobalLibrary(game).Global;
        return registry;
    }

    private SimAppearanceTransitionService? EnsureAppearanceTransitions()
    {
        if (appearanceTransitions is not null) return appearanceTransitions;
        if (registry is null) return null;
        appearanceTransitions = new SimAppearanceTransitionService(game, registry);
        return appearanceTransitions;
    }

    private SimsNative.Plugins.PluginGroundPoint GroundPoint(SimulationWorld currentWorld, ObjectPosition position)
    {
        var tx = position.X >> 4;
        var ty = position.Y >> 4;
        var level = position.Height;
        ushort floorPattern = 0;
        if (lot is { } currentLot && tx is >= 0 and < LotFloors.Size && ty is >= 0 and < LotFloors.Size)
        {
            try { floorPattern = LotFloors.Read(currentLot, level)[tx, ty]; }
            catch (InvalidDataException) { }
        }
        var bare = floorPattern == 0 && !currentWorld.WalkOrder.Any(item =>
            item is not XPerson && item.Position.Height == level &&
            (item.Position.X >> 4) == tx && (item.Position.Y >> 4) == ty &&
            item.TypeRecord?.Key != 0x7c4);
        var outside = currentWorld.RoomIsOutside(currentWorld.RoomAtTile(tx, ty, level));
        var sheltered = SceneExporter.IsShelteredAt(lot, currentWorld, LotWidth, position);
        return new SimsNative.Plugins.PluginGroundPoint(tx, ty, level, bare, outside, sheltered);
    }

    private string ResolveInstallRoot()
    {
        if (!string.IsNullOrEmpty(explicitInstallRoot) && Directory.Exists(Path.Combine(explicitInstallRoot, "UserData")))
            return Path.GetFullPath(explicitInstallRoot);
        if (Directory.Exists(Path.Combine(game, "UserData"))) return game;
        var gameDataPath = Path.Combine(game, "GameData");
        if (Directory.Exists(gameDataPath) &&
            new DirectoryInfo(gameDataPath).ResolveLinkTarget(true)?.FullName is { } resolvedGameData &&
            Path.GetDirectoryName(resolvedGameData) is { } parent &&
            Directory.Exists(Path.Combine(parent, "UserData")))
            return parent;
        if (TryReadSavedInstallRoot(dataRoot) is { } savedInstall && Directory.Exists(Path.Combine(savedInstall, "UserData")))
            return Path.GetFullPath(savedInstall);
        if (Environment.GetEnvironmentVariable("SIMS_GAME_DIR") is { Length: > 0 } envGame &&
            Directory.Exists(Path.Combine(envGame, "UserData")))
            return Path.GetFullPath(envGame);
        foreach (var candidate in new[] { Path.Combine(dataRoot, "runtime", "game"), Path.Combine(dataRoot, "The Sims 1") })
            if (Directory.Exists(Path.Combine(candidate, "UserData")))
                return Path.GetFullPath(candidate);
        return game;
    }

    internal static string? TryReadSavedInstallRoot(string root)
    {
        try
        {
            var settingsFile = Path.Combine(root, "Settings", "install.json");
            if (!File.Exists(settingsFile)) return null;
            using var doc = JsonDocument.Parse(File.ReadAllBytes(settingsFile));
            if (doc.RootElement.TryGetProperty("gamePath", out var prop) &&
                prop.ValueKind == JsonValueKind.String &&
                prop.GetString() is { Length: > 0 } path)
                return path;
        }
        catch
        {
        }
        return null;
    }

    private readonly System.Runtime.CompilerServices.ConditionalWeakTable<SimulationWorld, Action<short, AvatarInventory>> neighborInventoryHandlers = new();
    private readonly System.Runtime.CompilerServices.ConditionalWeakTable<SimulationWorld, object> attachedNoticeWorlds = new();

    private void AttachNoticeListener(SimulationWorld target)
    {
        target.GlobalSubroutineInterceptor = (subroutineId, caller, stackObjectId, _) =>
        {
            if (!ReferenceEquals(world, target) || plugins is null || pluginWorld is null || !plugins.HasGlobalCallInterceptors)
                return null;
            return plugins.InterceptGlobalCall(subroutineId, pluginWorld.Describe(caller), stackObjectId);
        };
        target.PlaySoundEvent = (name, owner, pan, zoom) =>
        {
            if (!ReferenceEquals(world, target) || audio is null) return false;
            char? voiceCode = null;
            int? pianoSkill = null;
            if (target.ObjectById(owner) is XPerson person)
            {
                if ((person[PersonData.RenderDisplayFlags] & 0x0C) != 0 &&
                    audio.IsDemographicVoxEvent(name))
                {
                    return false;
                }
                var age = person[PersonData.PersonAge];
                var gender = person[PersonData.Gender];
                voiceCode = PersonAgeCategory.IsChild(age)
                    ? 'k'
                    : gender == 0
                        ? 'm'
                        : gender == 1
                            ? 'f'
                            : gender == 2
                                ? 'k'
                                : null;
                pianoSkill = person[PersonData.CreativitySkill] / 100;
            }

            var played = audio.PlayForSimulationObject(name, owner, pan, zoom, voiceCode, pianoSkill);
            if (played) target.PositionalSoundOwners.Add(owner);
            return played;
        };
        target.StopOwnerSounds = owner =>
        {
            if (ReferenceEquals(world, target)) audio?.RemoveOwner(owner);
            target.PositionalSoundOwners.Remove(owner);
        };
        target.AnimationSound = (ownerId, cue) =>
        {
            if (ReferenceEquals(world, target)) HandleAnimationSound(ownerId, cue);
        };
        target.PictureInPicture ??= pictureInPicture;
        target.PersistNeighborhoodStateImmediately = () =>
        {
            if (ReferenceEquals(world, target)) PersistNeighborhoodStateImmediately();
        };
        target.PersistLotSimulationStateImmediately = () =>
        {
            if (!ReferenceEquals(world, target) || lot is null) return;
            var updatedLot = target.WriteSavedSimulationStateTo(lot);
            lot = updatedLot;
            if (house > 0)
            {
                var lotPath = Path.Combine(Neighborhoods.UserData(profile), "Houses", $"House{house:D2}.iff");
                if (File.Exists(lotPath))
                    WriteReplace(lotPath, updatedLot.Bytes);
            }
        };
        target.LiveLotValuationProvider = () => target.SavedSimulationState is { } s
            ? (ReferenceEquals(world, target) ? CurrentLotValuation(s) : (s.Field0xA0, s.Field0xA4))
            : (0, 0);
        WorldBootstrap.WireNeighborhoodDelegates(target, () => ReferenceEquals(world, target) ? neighborhood : null);
        WorldBootstrap.SyncFamilyBridgeState(
            target,
            (target.FamilyBudget as FamilyBudget)?.ActiveFamily,
            (target.FamilyBudget as FamilyBudget)?.FamilyChunkId);
        target.ReleaseGenericSimsCall03PrimaryHandle = _ =>
        {
            target.DismissVisibleDialogRecords();
            if (ReferenceEquals(world, target) && !HasBlockingDialog(target) && dialogResumeSpeed > 0)
            {
                SetSimulationSpeed(dialogResumeSpeed);
                dialogResumeSpeed = 0;
            }
        };
        target.ReleaseGenericSimsCall03SecondaryHandle = _ =>
        {
            target.DismissVisibleDialogRecords();
        };
        if (neighborInventoryHandlers.TryGetValue(target, out var prevInventoryHandler))
            target.NeighborInventoryChanged -= prevInventoryHandler;
        Action<short, AvatarInventory> inventoryHandler = (_, _) =>
        {
            if (ReferenceEquals(world, target))
            {
                PersistNeighborhoodStateImmediately();
            }
        };
        neighborInventoryHandlers.AddOrUpdate(target, inventoryHandler);
        target.NeighborInventoryChanged += inventoryHandler;
        if (attachedNoticeWorlds.TryGetValue(target, out _))
            return;
        attachedNoticeWorlds.Add(target, new object());
        target.AddNoticeListener(new SimulationNoticeListener((message, value) =>
        {
            if (!ReferenceEquals(world, target))
                return false;
            if (message is 0x88 or 0xda or 0xdb or 0xe4 or 0xe8 or 0xee) saveDirty = true;
            if (message == 0x20000000)
            {
                if (RefreshPendingPersonPortraits())
                {
                    saveDirty = true;
                    Write(new { type = "state", state = State() });
                }
                return true;
            }
            if (message == 0xe4)
            {
                var selected = value == 0
                    ? null
                    : target.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person.RequestKey == value || person.Id == value);
                if (value == 0 || (selected is not null && IsHouseholdPerson(selected)))
                {
                    selectedSim = selected?.Id ?? (short)0;
                    SyncSelectedSimFlags(target, selectedSim);
                }
            }
            if (message == 0xe8)
            {
                familyMembershipChangedDuringTick = true;
                ReconcileSelectedSim(target);
            }
            if (message == 0x88 && selectedSim != 0 && value == selectedSim)
            {
                ReconcileSelectedSim(target);
            }
            if (message == 0x108)
            {
                if (IsEmergencyBuyBuildLocked)
                {
                    editingView = false;
                    doorWindowBuildToolActive = false;
                    wallpaperBuildToolActive = false;
                    if (viewerMode is 1 or 2)
                        viewerMode = 0;
                    if (world is not null)
                        world[SimulationGlobal.Mode] = viewerMode;
                }
                if (streaming)
                    Write(new { type = "state", state = State(includeArchitectureGrids: false) });
                return true;
            }
            if (message == 0xda)
            {
                Write(new { type = "state", state = State() });
                return true;
            }
            return false;
        }));
    }

    private static Family UpdateFamilyFields(Family family, ushort chunkId, int? field0x120 = null, uint? flags = null, int? value = null) =>
        family.WithFields(
            familyNumber: chunkId == 0 ? 0 : family.FamilyNumber != 0 ? family.FamilyNumber : chunkId,
            value: value,
            field0x120: field0x120,
            flags: flags);

    private int RecountFamilyFriends(SimulationWorld currentWorld, Family family, short familyNumber)
    {
        var neighbors = currentWorld.NeighborWalkOrder.Count > 0
            ? currentWorld.NeighborWalkOrder.OfType<NeighborState>().ToArray()
            : currentWorld.Neighbors.Values.ToArray();
        var threshold = currentWorld.FriendshipThreshold > 0 ? currentWorld.FriendshipThreshold : (short)50;
        var memberNeighbors = neighbors
            .Where(n => family.Members.Contains(unchecked((uint)n.TypeRecordKey)) ||
                        (familyNumber != 0 && n.PersonData[(int)PersonData.FamilyNumber] == familyNumber))
            .ToArray();
        if (memberNeighbors.Length == 0) return 0;
        var count = 0;
        foreach (var candidate in neighbors)
        {
            if (family.Members.Contains(unchecked((uint)candidate.TypeRecordKey)) ||
                (familyNumber != 0 && candidate.PersonData[(int)PersonData.FamilyNumber] == familyNumber) ||
                candidate.PersonData[(int)PersonData.FamilyNumber] == 0 ||
                candidate.PersonData[(int)PersonData.Gender] >= 2)
                continue;

            foreach (var memberNeighbor in memberNeighbors)
            {
                if (candidate.Relationships.Count(memberNeighbor.Id) <= 0 ||
                    memberNeighbor.Relationships.Count(candidate.Id) <= 0)
                    continue;
                if (candidate.Relationships.Get(memberNeighbor.Id, 0) < threshold ||
                    memberNeighbor.Relationships.Get(candidate.Id, 0) < threshold)
                    continue;
                count++;
                break;
            }
        }
        return count;
    }

    private void PersistNeighborhoodStateImmediately() =>
        PersistNeighborhoodStateImmediatelyCore(commitVacationField: false);

    private void PersistNeighborhoodStateImmediatelyCore(bool commitVacationField)
    {
        if (world is null || neighborhood is null || neighborhoodPath is null) return;

        RefreshPendingPersonPortraits();
        world.SaveAllPersistentPersonData();
        var updated = world.WriteSavedNeighborRelationshipsTo(neighborhood);
        var famiType = ResourceType.Parse("FAMI");

        if (world.DirtyRelationshipFamilies.Count > 0)
        {
            var dirtyIds = world.DirtyRelationshipFamilies.ToArray();
            world.DirtyRelationshipFamilies.Clear();
            foreach (var dirtyFamilyId in dirtyIds)
            {
                if (dirtyFamilyId == 0) continue;
                ushort? targetChunkId = null;
                Family? targetFamily = null;
                if (activeFamilyChunkId is { } activeId &&
                    world.FamilyBudget is FamilyBudget activeBudget &&
                    activeBudget.ActiveFamily is { } activeFam &&
                    (activeId == unchecked((ushort)dirtyFamilyId) || activeFam.FamilyNumber == dirtyFamilyId))
                {
                    targetChunkId = activeId;
                    targetFamily = activeFam;
                }
                else
                {
                    foreach (var chunk in updated.OfType(famiType))
                    {
                        if (chunk.Id == 0) continue;
                        var candidateFamily = Family.Read(updated, chunk);
                        if (chunk.Id == unchecked((ushort)dirtyFamilyId) || candidateFamily.FamilyNumber == dirtyFamilyId)
                        {
                            targetChunkId = chunk.Id;
                            targetFamily = candidateFamily;
                            break;
                        }
                    }
                }
                if (targetChunkId is { } foundChunkId && targetFamily is not null)
                {
                    var friendCount = RecountFamilyFriends(world, targetFamily, dirtyFamilyId);
                    var updatedFamily = UpdateFamilyFields(targetFamily, foundChunkId, field0x120: friendCount);
                    if (activeFamilyChunkId == foundChunkId && world.FamilyBudget is FamilyBudget budget)
                        budget.ActiveFamily = updatedFamily;
                    updated = updated.WithAddedOrReplacedChunk(famiType, foundChunkId, updatedFamily.Write(foundChunkId));
                }
            }
        }

        if (activeFamilyChunkId is { } familyChunkId &&
            world.FamilyBudget is FamilyBudget familyBudget && familyBudget.ActiveFamily is { } family)
        {
            if (suspendedHomeLot is null && !IsAwayLot(Path.GetDirectoryName(neighborhoodPath) ?? "", house) &&
                world.SavedSimulationState is { } valueState)
            {
                var (furnishingsValue, architectureValue) = CurrentLotValuation(valueState);
                family = family.WithValue(valueState.Field0x9C + furnishingsValue + (int)(architectureValue * (world.ArchitectureValueMultiplier ?? 0.7f)));
                familyBudget.ActiveFamily = family;
            }
            var diskFamily = family;
            if (!commitVacationField &&
                committedVacationState is { } committed &&
                committed.FamilyChunkId == familyChunkId &&
                diskFamily.Field0x13C != committed.VacationHouse)
            {
                diskFamily = diskFamily.WithFields(field0x13C: committed.VacationHouse);
            }
            updated = updated.WithAddedOrReplacedChunk(famiType, familyChunkId,
                diskFamily.Write(familyChunkId));
        }
        if (world.NeighborhoodFamilies is NeighborhoodFamilies families)
            foreach (var (chunkId, changedFamily) in families.Changed)
                updated = updated.WithAddedOrReplacedChunk(famiType, chunkId, changedFamily.Write(chunkId));

        if (world[SimulationGlobal.IsTutorialHouseNoYes] != 0)
            world.NeighborhoodData[0] = house;
        var ngbhType = ResourceType.Parse("NGBH");
        var existingNgbhChunk = updated.Find(ngbhType, 1);
        var existingNgbh = existingNgbhChunk is not null ? NeighborhoodData.Read(updated, existingNgbhChunk) : null;
        var inventories = new Dictionary<short, IReadOnlyList<NeighborhoodData.InventoryItem>>();
        var neighborIds = new SortedSet<short>();
        if (existingNgbh is not null)
        {
            foreach (var id in existingNgbh.Inventories.Keys)
                if (world.Neighbors.Count == 0 || world.Neighbors.ContainsKey(id))
                    neighborIds.Add(id);
        }
        foreach (var id in world.Neighbors.Keys)
            neighborIds.Add(id);
        foreach (var id in neighborIds)
        {
            var entries = world.NeighborInventory(id).Entries;
            if (entries.Count > 0 || (existingNgbh is not null && existingNgbh.Inventories.ContainsKey(id)))
            {
                inventories[id] = entries
                    .Select(entry => new NeighborhoodData.InventoryItem(entry.Key1, unchecked((uint)entry.Key2), unchecked((ushort)entry.Count)))
                    .ToArray();
            }
        }
        var ngbhSwap = existingNgbhChunk is not null && existingNgbhChunk.Data.Span.Length > 0 && existingNgbhChunk.Data.Span[0] != 0;
        var ngbhBytes = existingNgbh is not null && (existingNgbh.Version >= 0x40 || inventories.Count == 0)
            ? existingNgbh.WithData(world.NeighborhoodData).WithInventories(inventories).Write(ngbhSwap)
            : NeighborhoodData.Write(world.NeighborhoodData, inventories, 0x49, ngbhSwap);
        updated = updated.WithAddedOrReplacedChunk(ngbhType, 1, ngbhBytes);
        if (updated.Find(ngbhType, 1) is { } refreshedNgbhChunk)
            world.LoadNeighborhoodData(NeighborhoodData.Read(updated, refreshedNgbhChunk));

        var tattType = ResourceType.Parse("TATT");
        var existingTattChunk = updated.Find(tattType, 1);
        var existingTatt = existingTattChunk is not null ? TypeAttributes.Read(updated, existingTattChunk) : null;
        var tattMap = existingTatt is not null
            ? new Dictionary<uint, short[]>(existingTatt.AttributesByGuid)
            : new Dictionary<uint, short[]>();
        foreach (var obj in world.Objects.Values)
        {
            var guid = unchecked((uint)(obj.TypeRecord?.Key ?? 0));
            if (guid != 0 && obj.TypeAttributes is { Length: > 0 })
                tattMap[guid] = obj.TypeAttributes.ToArray();
        }
        if (existingTattChunk is not null || tattMap.Count > 0)
        {
            var tattVersion = existingTatt?.Version ?? 0x49;
            var tattSwap = existingTattChunk is not null && existingTattChunk.Data.Span.Length > 0 && existingTattChunk.Data.Span[0] != 0;
            var tattCoded = existingTattChunk is null || existingTattChunk.Data.Span.Length <= 12 || existingTattChunk.Data.Span[12] != 0;
            updated = updated.WithAddedOrReplacedChunk(tattType, 1, TypeAttributes.Write(tattMap, tattVersion, tattCoded, tattSwap));
        }

        var userData = Path.GetDirectoryName(neighborhoodPath);
        if (!string.IsNullOrEmpty(userData))
        {
            Directory.CreateDirectory(userData);
            if (registry is not null && registry.DirtyPeopleGuids.Count > 0)
            {
                var charactersDir = Path.Combine(userData, "Characters");
                Directory.CreateDirectory(charactersDir);
                foreach (var dirtyGuid in registry.DirtyPeopleGuids.ToArray())
                {
                    if (registry.Find(dirtyGuid) is { Scan: ObjectScan.People } dirtyEntry)
                    {
                        var fileName = Path.GetFileName(dirtyEntry.Source);
                        if (!string.IsNullOrEmpty(fileName))
                            WriteReplace(Path.Combine(charactersDir, fileName), dirtyEntry.File.Bytes);
                    }
                }
                registry.DirtyPeopleGuids.Clear();
            }
        }

        WriteReplace(neighborhoodPath, updated.Bytes);
        neighborhood = updated;
    }

    private static (short House, ushort? ActiveFamilyChunkId) ResolveVacationRedirect(string userData, short requestedHouse)
    {
        var nghPath = Path.Combine(userData, "Neighborhood.iff");
        if (!File.Exists(nghPath)) return (requestedHouse, null);
        try
        {
            var ngh = IffFile.Open(nghPath);
            foreach (var chunk in ngh.OfType(ResourceType.Parse("FAMI")))
            {
                if (chunk.Id == 0) continue;
                var family = Family.Read(ngh, chunk);
                if ((requestedHouse is (> 0 and < 20) or (>= 90 and <= 92)) &&
                    !Neighborhoods.IsCommunityLot(userData, requestedHouse) &&
                    family.HouseNumber == requestedHouse &&
                    family.Field0x13C > 0)
                {
                    var vacHouse = checked((short)family.Field0x13C);
                    var vacPath = Path.Combine(userData, "Houses", $"House{vacHouse:D2}.iff");
                    if (File.Exists(vacPath)) return (vacHouse, chunk.Id);
                }
                else if (requestedHouse is >= 40 and <= 49 && family.Field0x13C == requestedHouse)
                {
                    return (requestedHouse, chunk.Id);
                }
            }
        }
        catch
        {
        }
        return (requestedHouse, null);
    }

    private static void HydrateTypeAttributesFromNeighborhood(SimulationWorld targetWorld, IffFile? lotFile, IffFile? neighborhoodFile,
        bool overwriteExisting = false)
    {
        if (neighborhoodFile is null || (!overwriteExisting && lotFile?.Find(ResourceType.Parse("TATT"), 1) is not null)) return;
        if (neighborhoodFile.Find(ResourceType.Parse("TATT"), 1) is not { } tattChunk) return;
        var attributesByGuid = TypeAttributes.Read(neighborhoodFile, tattChunk).AttributesByGuid;
        foreach (var obj in targetWorld.Objects.Values)
        {
            var guid = unchecked((uint)(obj.TypeRecord?.Key ?? 0));
            if (guid == 0 || !attributesByGuid.TryGetValue(guid, out var savedAttrs) || savedAttrs.Length == 0) continue;
            if (obj.TypeAttributes.Length < savedAttrs.Length)
                obj.TypeAttributes = new short[savedAttrs.Length];
            Array.Copy(savedAttrs, obj.TypeAttributes, savedAttrs.Length);
        }
    }

    public static SimulationServer Load(string game, string session, string profile, short house, TextWriter output, byte language = 1, string? installRoot = null, DirectPackOverlay? packOverlay = null)
    {
        try
        {
            if (house == 0)
            {
                return new SimulationServer(output, session, profile, game, 0, null, null, null, null, loadError: null, language, installRoot: installRoot, packOverlay: packOverlay);
            }
            var userData = Neighborhoods.UserData(profile);
            var (effectiveHouse, redirectedFamilyChunkId) = ResolveVacationRedirect(userData, house);
            house = effectiveHouse;
            var path = Path.Combine(userData, "Houses", $"House{house:D2}.iff");
            if (!File.Exists(path)) return new SimulationServer(output, session, profile, game, house, null, null, null, null, $"Lot {house} not found.", language, installRoot: installRoot, packOverlay: packOverlay);
            var runtime = ReadSavedRuntimeMetadata(CanonicalRuntimePath(path), File.ReadAllBytes(path));
            var setup = WorldBootstrap.Load(game, path, language, () => false, house,
                userDataPath: userData, activeFamilyChunkId: redirectedFamilyChunkId);
            HydrateTypeAttributesFromNeighborhood(setup.World, setup.Lot, setup.Neighborhood);
            if (setup.ActiveFamilyChunkId is null && !WorldBootstrap.HasResidentHouseholdSim(setup.World))
            {
                setup.World[SimulationGlobal.SimlessBuildMode] = 1;
            }
            else if (setup.ActiveFamilyChunkId is not null)
            {
                setup.World[SimulationGlobal.SimlessBuildMode] = 0;
            }
            RestorePersonAnimationRuntime(setup.World, runtime.PersonAnimations);
            RestoreDialogRecords(setup.World, runtime.Dialogs);
            if (runtime.ClockTicks is { } clockTicks)
                setup.World.Clock.RestoreProgress(clockTicks, runtime.ClockDay ?? 0);
            var server = new SimulationServer(output, session, profile, game, house, setup.World, setup.Lot,
                setup.Registry, setup.Global, null, language, setup.NeighborhoodPath, setup.Neighborhood, setup.ActiveFamilyChunkId,
                installRoot: installRoot, packOverlay: packOverlay);
            server.RestoreTravelRuntimeState(setup.World, userData, house, setup.ActiveFamilyChunkId, setup.ActiveFamily, runtime);
            server.ClampAwayLotEditingState();
            if (setup.ActiveFamily is { Members.Count: > 0 } activeFamily)
            {
                var expectedKeys = (setup.World.FamilyBudget as FamilyBudget)?.RestrictedActivePersonKeys
                    ?? activeFamily.Members.Select(static m => unchecked((int)m)).ToArray();
                if (!setup.World.WalkOrder.OfType<XPerson>().Any(p => expectedKeys.Contains(p.TypeRecord?.Key ?? 0)))
                {
                    server.EnsureSelectedHouseholdMember(activeFamily, server.LotWidth / 2, server.LotHeight / 2);
                }
            }
            if (!server.IsValidSelectedSim(setup.World, server.selectedSim))
            {
                server.selectedSim = server.DefaultSelectedSimId();
                SyncSelectedSimFlags(setup.World, server.selectedSim);
            }
            server.SetSimulationSpeed(0);
            server.lastRunningSpeed = runtime.Speed;
            if (HasBlockingDialog(setup.World) && runtime.Speed > 0)
                server.dialogResumeSpeed = runtime.Speed;
            server.InitializeFameCallbackTarget(setup.World);
            if (setup.Global is { } global) setup.World.AutonomyHost = server.BuildAutonomyHost(setup.World, global, house);
            server.InitializeViewLevelFromSelectedSim();
            return server;
        }
        catch (Exception error) when (error is IOException or UnauthorizedAccessException or InvalidDataException or ResourceFormatException)
        {
            return new SimulationServer(output, session, profile, game, house, null, null, null, null, error.Message, language, installRoot: installRoot, packOverlay: packOverlay);
        }
    }

    private AutonomyHost BuildAutonomyHost(SimulationWorld targetWorld, IffFile targetGlobal, short targetHouse) =>
        new(targetWorld, targetGlobal, targetHouse, () => speed == 0,
            ScoreAutonomyChoice, DirectsAutonomyForPerson, SelectAutonomyChoice);

    private float ScoreAutonomyChoice(XPerson person, XObject target, short actionIndex, string actionName, float score) =>
        plugins is null
            ? score
            : plugins.ScoreAutonomy(new SimsNative.Plugins.PluginAutonomyChoice(person.Id, IsHouseholdPerson(person), target.Id,
                unchecked((uint)(target.TypeRecord?.Key ?? 0)), actionIndex, actionName), score);

    private bool DirectsAutonomyForPerson(XPerson person) =>
        plugins is not null && plugins.DirectsAutonomy(person.Id, IsHouseholdPerson(person));

    private int? SelectAutonomyChoice(AutonomySelectionContext selection, IReadOnlyList<AutonomyCandidateSnapshot> candidates)
    {
        if (plugins is null) return null;
        var activeWorld = world;
        var clockHour = activeWorld?.Clock.Hour ?? 0;
        var clockMinute = activeWorld?.Clock.Minute ?? 0;
        var ctx = new SimsNative.Plugins.PluginAutonomyContext(
            SimId: selection.Person.Id,
            Household: IsHouseholdPerson(selection.Person),
            House: house,
            AwayLot: IsVisitingAwayLot,
            Hours: clockHour,
            Minutes: clockMinute,
            BaselineScore: selection.BaselineScore,
            VanillaThreshold: selection.VanillaThreshold,
            RandomSeed: selection.RandomSeed);
        var mapped = new SimsNative.Plugins.PluginAutonomyCandidate[candidates.Count];
        for (var i = 0; i < candidates.Count; i++)
        {
            var c = candidates[i];
            var objName = c.Target is XPerson targetPerson
                ? (!string.IsNullOrWhiteSpace(targetPerson.Name) ? targetPerson.Name : targetPerson.TypeRecord?.CatalogName ?? targetPerson.TypeRecord?.Name ?? "")
                : c.Target.TypeRecord?.Name ?? "";
            var englishName = pluginWorld?.ResolveEnglishInteractionName(c.Target, c.ActionIndex) ?? c.InteractionName;
            mapped[i] = new SimsNative.Plugins.PluginAutonomyCandidate(
                ObjectId: c.Target.Id,
                ObjectGuid: unchecked((uint)(c.Target.TypeRecord?.Key ?? 0)),
                ObjectName: objName,
                ActionId: c.ActionIndex,
                InteractionName: c.InteractionName,
                EnglishName: englishName,
                Distance: c.Distance,
                VanillaScore: c.VanillaScore,
                AdjustedScore: c.AdjustedScore,
                AutoFirst: c.AutoFirst,
                JoinInteraction: c.JoinInteraction,
                BlockedByPlugin: c.BlockedByHost,
                MotiveDeltas: c.MotiveDeltas);
        }
        return plugins.SelectAutonomyCandidate(ctx, mapped);
    }

    public async Task Run(System.Threading.Channels.ChannelReader<string>? externalInput = null)
    {
        Write(new
        {
            type = "hello",
            protocolVersion = 1,
            architecture = RuntimeInformation.ProcessArchitecture.ToString(),
            engine = "native-simsengine-v0",
            packFingerprint,
            packWarnings = Array.Empty<object>(),
            languageCode = (byte)1,
            saveSchemaVersion = 2,
            plugins = plugins?.Statuses ?? [],
            pluginPanels = plugins?.Panels.Select(panel => new { panel.PackId, panel.Id, panel.Path }).ToArray() ?? [],
            nativeEngine = true,
            house,
            homeHouse = EffectiveHomeHouse,
            away = IsVisitingAwayLot,
            simless = world is not null && world[SimulationGlobal.SimlessBuildMode] != 0,
            loadError,
            commands = new[] { "state", "audio", "audioEvent", "audioStopOwner", "audioEnded", "audioVolume", "audioState", "modeMusic", "speed", "blockSimulator", "tutorialInfo", "uiButton", "relationshipPopup", "tutorialPanelCheck", "step", "scene", "stream", "sceneAck", "selectSim", "setMotive", "menu", "groundMenu", "groundInteract", "interact", "catalog", "catalogPage", "buyCatalogViews", "buildCatalogPage", "previewObject", "buildCursor", "pieHeadPreview", "buyObject", "sellObject", "moveObject", "architecture", "architectureBatch", "roof", "undo", "redo", "cancelAction", "dialogResponse", "genericSimsCallPersonPicker", "appearanceCatalog", "appearancePreview", "createHousehold", "moveInFamily", "neighborhood", "saveBackups", "restoreBackup", "outfitChoices", "outfitPreview", "freeWill", "cheat", "pictureInPicture", "walls", "cutaway", "roofs", "cameraOrientation", "level", "view", "viewScrolling", "cursorObjectCreated", "tutorialResetState", "save", "load", "travelFilter", "plugins", "pluginPanels", "pluginAction", "warmup", "openLot", "closeLot", "quit" }
                .Concat(testFixtureEnabled ? ["setTestPersonTile", "testTileContents"] : []).ToArray(),
        });
        if (world is not null)
        {
            var initialExport = Stopwatch.GetTimestamp();
            Export();
            Write(new { type = "state", state = State() });
            if (profile_) Console.Error.WriteLine($"Native load: first scene export {Stopwatch.GetElapsedTime(initialExport).TotalMilliseconds:F0} ms");
        }
        System.Threading.Channels.ChannelReader<string> reader;
        Task? read = null;
        if (externalInput is not null)
        {
            reader = externalInput;
        }
        else
        {
            var channel = System.Threading.Channels.Channel.CreateBounded<string>(new System.Threading.Channels.BoundedChannelOptions(128)
            { SingleReader = true, SingleWriter = true });
            read = Task.Run(async () =>
            {
                try
                {
                    while (await Console.In.ReadLineAsync() is { } line) await channel.Writer.WriteAsync(line);
                }
                finally { channel.Writer.TryComplete(); }
            });
            reader = channel.Reader;
        }
        var watch = Stopwatch.StartNew();
        var nextUpdate = watch.Elapsed.TotalSeconds;
        var nextAudioTick = nextUpdate;
        var scheduledSpeed = speed;
        var nextScene = nextUpdate + 1;
        string DialogTokens()
        {
            if (world is not { DialogRecords.Count: > 0 } current) return "";
            var hasVisible = false;
            for (var i = 0; i < current.DialogRecords.Count; i++)
            {
                if (current.DialogRecords[i].Visible) { hasVisible = true; break; }
            }
            if (!hasVisible) return "";
            return string.Join(",", current.DialogRecords.Where(r => r.Visible).OrderByDescending(r => r.Blocking).Select(r => r.Token));
        }
        var lastDialogToken = DialogTokens();
        var hadActivePluginEnvironment = false;
        PluginHost.EnvironmentState? lastPluginEnvironment = null;
        static bool EnvironmentStateEquals(PluginHost.EnvironmentState? a, PluginHost.EnvironmentState? b)
        {
            if (ReferenceEquals(a, b)) return true;
            if (a is null || b is null) return false;
            if (!string.Equals(a.PackId, b.PackId, StringComparison.Ordinal) ||
                !string.Equals(a.AssetRoot, b.AssetRoot, StringComparison.Ordinal) ||
                !string.Equals(a.Scope, b.Scope, StringComparison.Ordinal))
                return false;
            var ea = a.Effect;
            var eb = b.Effect;
            if (ReferenceEquals(ea, eb)) return true;
            if (ea.SurfaceMode != eb.SurfaceMode ||
                ea.SurfaceAmount != eb.SurfaceAmount ||
                ea.CloudCover != eb.CloudCover ||
                ea.Precipitation != eb.Precipitation ||
                ea.Wetness != eb.Wetness ||
                ea.AudioGain != eb.AudioGain ||
                ea.AudioCutoff != eb.AudioCutoff ||
                ea.Atmosphere != eb.Atmosphere ||
                ea.DisplacedSurface != eb.DisplacedSurface ||
                ea.TrailRecovery != eb.TrailRecovery)
                return false;
            if (ea.Footprints.Length != eb.Footprints.Length ||
                ea.AmbientSounds.Length != eb.AmbientSounds.Length ||
                ea.Shaders.Count != eb.Shaders.Count ||
                ea.Parameters.Count != eb.Parameters.Count)
                return false;
            for (int i = 0; i < ea.Footprints.Length; i++)
                if (ea.Footprints[i] != eb.Footprints[i]) return false;
            for (int i = 0; i < ea.AmbientSounds.Length; i++)
                if (ea.AmbientSounds[i] != eb.AmbientSounds[i]) return false;
            foreach (var (k, v) in ea.Shaders)
                if (!eb.Shaders.TryGetValue(k, out var bv) || !string.Equals(v, bv, StringComparison.Ordinal)) return false;
            foreach (var (k, v) in ea.Parameters)
                if (!eb.Parameters.TryGetValue(k, out var bv) || v != bv) return false;
            return true;
        }
        string? pending = null;
        while (running)
        {
            while (pending is not null || reader.TryRead(out pending))
            {
                if (!Handle(pending)) break;
                pending = null;
            }
            if (reader.Completion.IsCompleted && pending is null) break;
            var now = watch.Elapsed.TotalSeconds;
            if (speed != scheduledSpeed)
            {
                scheduledSpeed = speed;
                nextUpdate = now;
            }
            if (now >= nextUpdate)
            {
                if (!simulatorBlocked && speed > 0 && world is not null)
                {
                    var tickInterval = TickIntervalSeconds(speed);
                    var maxBatchTicks = speed >= 10 ? 48 : speed >= 3 ? 6 : 2;
                    var batchTicks = 0;
                    var batchStartHouse = house;
                    var batchDeadline = now + (streaming ? (speed >= 10 ? 0.011 : 0.005) : 0.014);
                    while (now >= nextUpdate && batchTicks < maxBatchTicks && !simulatorBlocked && speed > 0 && pending is null && (batchTicks == 0 || !reader.TryPeek(out _)))
                    {
                        var started = Stopwatch.GetTimestamp();
                        if (AdvanceOneTick()) { updates++; lastSubTickAlpha = 0f; plugins?.Tick(updates); }
                        if (profile_)
                        {
                            var elapsed = Stopwatch.GetElapsedTime(started);
                            tickTime += elapsed;
                            var ms = elapsed.TotalMilliseconds;
                            if (ms > maxTickMs) maxTickMs = ms;
                            ticksTimed++;
                        }
                        batchTicks++;
                        nextUpdate += tickInterval;
                        now = watch.Elapsed.TotalSeconds;
                        if (house != batchStartHouse || HasBlockingDialog(world) || now >= batchDeadline) break;
                    }
                    if (now - nextUpdate > 0.25) nextUpdate = now;
                }
                else
                {
                    if (!simulatorBlocked && speed == 0 && world is not null && (updates > 0 || world[SimulationGlobal.IsTutorialHouseNoYes] != 0)) AdvancePausedTick();
                    nextUpdate += TickIntervalSeconds(speed);
                    if (now - nextUpdate > 0.25) nextUpdate = now;
                }
                var currentDialogToken = DialogTokens();
                if (currentDialogToken != lastDialogToken)
                {
                    lastDialogToken = currentDialogToken;
                    if (streaming) Write(new { type = "state", state = State(includeArchitectureGrids: false) });
                }
            }
            if (now >= nextAudioTick)
            {
                if (audio is { } activeAudio && world is { } activeWorld) activeAudio.Tick(activeWorld);
                else audio?.Tick();
                nextAudioTick += 1.0 / 60;
                if (now - nextAudioTick > 0.25) nextAudioTick = now;
            }
            if (!simulatorBlocked && streaming && world is not null && lot is not null && registry is not null)
            {
                var currentCutawaySimKey = CutawaySimKey();
                if (currentCutawaySimKey != exportedCutawaySimKey)
                {
                    if (!SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                            cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: wallpaperBuildToolActive))
                        Export();
                    else
                        exportedCutawaySimKey = currentCutawaySimKey;
                }
            }
            if (!simulatorBlocked && streaming && speed > 0 && world is not null && lot is not null && registry is not null && now >= nextAnimation)
            {
                if (animationState.Kept is null || animationState.Revision != revision)
                    Export();
                var started = Stopwatch.GetTimestamp();
                var currentTickInterval = TickIntervalSeconds(speed);
                var subTickAlpha = currentTickInterval > 0
                    ? (float)Math.Clamp(1.0 - (nextUpdate - now) / currentTickInterval, 0.0, 0.999)
                    : 0f;
                lastSubTickAlpha = subTickAlpha;
                if (DirectAnimationSink is { } directSink)
                {
                    if (SceneExporter.AnimationDirect(lot, world, registry, game, SceneDirectory, house, revision, animationState, ++animationSequence, updates,
                            viewLevel, wallMode, cameraOrientation, cutawayTile, roofsVisible, cutawayRooms: cutawayRooms, cutawaySim: CutawaySimTile(), cutawayZoom: cutawayZoom, showLoweredPortals: doorWindowBuildToolActive, subTickAlpha: subTickAlpha, raiseHoveredWalls: wallpaperBuildToolActive) is { } directFrame)
                        directSink(directFrame);
                }
                else if (SceneExporter.Animation(lot, world, registry, game, SceneDirectory, house, revision, animationState, ++animationSequence, updates,
                        viewLevel, wallMode, cameraOrientation, cutawayTile, roofsVisible, cutawayRooms: cutawayRooms, cutawaySim: CutawaySimTile(), cutawayZoom: cutawayZoom, showLoweredPortals: doorWindowBuildToolActive, subTickAlpha: subTickAlpha, raiseHoveredWalls: wallpaperBuildToolActive) is { } frame)
                {
                    Write(new { type = "animation", frame });
                }
                if (plugins is not null)
                {
                    var currentEnv = plugins.Environment(house);
                    plugins.FlushClientStates();
                    if ((currentEnv is not null || hadActivePluginEnvironment) && !EnvironmentStateEquals(currentEnv, lastPluginEnvironment))
                    {
                        hadActivePluginEnvironment = currentEnv is not null;
                        lastPluginEnvironment = currentEnv;
                        Write(new { type = "environment", updates, environment = currentEnv });
                    }
                }
                if (profile_)
                {
                    if (profileWindowStart == 0) profileWindowStart = started;
                    animationTime += Stopwatch.GetElapsedTime(started);
                    if (++animationsTimed == 120)
                    {
                        var windowSec = Math.Max(Stopwatch.GetElapsedTime(profileWindowStart).TotalSeconds, 1e-6);
                        var avgTick = ticksTimed > 0 ? tickTime.TotalMilliseconds / ticksTimed : 0.0;
                        var ticksPerSec = ticksTimed / windowSec;
                        Console.Error.WriteLine(
                            $"Native profile (speed {speed}): animation {animationTime.TotalMilliseconds / animationsTimed:F2} ms/frame, ticks {ticksTimed} ({ticksPerSec:F0}/s, avg {avgTick:F2} ms, max {maxTickMs:F1} ms)");
                        animationTime = TimeSpan.Zero;
                        animationsTimed = 0;
                        tickTime = TimeSpan.Zero;
                        ticksTimed = 0;
                        maxTickMs = 0;
                        profileWindowStart = Stopwatch.GetTimestamp();
                    }
                }
                nextAnimation = now + (speed >= 10 ? 1.0 / 60 : 1.0 / 120);
            }
            if (now >= nextScene && streaming)
            {
                if (!simulatorBlocked && world is not null)
                {
                    if (CurrentFoliageStage() != exportedFoliageStage)
                    {
                        Export();
                    }
                    else if (speed > 0)
                    {
                        var currentObjectsSig = ComputeObjectsSignature();
                        var includeObjects = editingView || currentObjectsSig != lastStreamedObjectsSignature;
                        Write(new { type = "state", state = State(includeArchitectureGrids: false, includeObjects: includeObjects) });
                    }
                }
                nextScene = now + 0.25;
            }
            else if (now >= nextScene)
            {
                if (speed > 0 && !simulatorBlocked && world is not null)
                {
                    var started = Stopwatch.GetTimestamp();
                    Export();
                    if (profile_ && ticksTimed > 0)
                        Console.Error.WriteLine($"Native profile: {ticksTimed} ticks, {tickTime.TotalMilliseconds / ticksTimed:F2} ms/tick, scene export {Stopwatch.GetElapsedTime(started).TotalMilliseconds:F0} ms");
                    tickTime = TimeSpan.Zero;
                    ticksTimed = 0;
                }
                nextScene = now + 1;
            }
            var afterWork = watch.Elapsed.TotalSeconds;
            var nextDeadline = Math.Min(nextUpdate, nextAudioTick);
            if (streaming && speed > 0 && !simulatorBlocked && nextAnimation < nextDeadline)
                nextDeadline = nextAnimation;
            var sleepSeconds = nextDeadline - afterWork;
            if (sleepSeconds > 0.0015 && !reader.TryPeek(out _))
            {
                if (sleepSeconds < 0.004)
                {
                    Thread.Sleep(1);
                }
                else
                {
                    var sleepMs = Math.Clamp((int)(sleepSeconds * 1000.0), 1, 15);
                    var readTask = reader.WaitToReadAsync().AsTask();
                    if (!readTask.IsCompleted)
                    {
                        using var delayCts = new CancellationTokenSource();
                        var delayTask = Task.Delay(sleepMs, delayCts.Token);
                        var completed = await Task.WhenAny(readTask, delayTask);
                        if (completed == readTask) delayCts.Cancel();
                    }
                }
            }
            else
            {
                await Task.Yield();
            }
        }
        if (read is not null && reader.Completion.IsCompleted) await read;
        plugins?.Dispose();
        audio?.Dispose();
    }

    public int BatchRun(int requestedTicks)
    {
        if (world is null || requestedTicks <= 0) return 0;
        int completed = 0;
        for (int i = 0; i < requestedTicks; i++)
        {
            if (AdvanceOneTick()) completed++;
        }
        return completed;
    }

    internal bool Handle(string line)
    {
        var id = "";
        var op = "";
        try
        {
            using var document = JsonDocument.Parse(line);
            var root = document.RootElement;
            if (root.TryGetProperty("id", out var value) && value.ValueKind == JsonValueKind.String)
                id = value.GetString() ?? "";
            if (root.TryGetProperty("op", out var opValue) && opValue.ValueKind == JsonValueKind.String)
                op = opValue.GetString() ?? "";
            try { return HandleCore(root, id, op); }
            catch (SaveCompatibility.MissingPacksException error)
            {
                Write(new { type = "response", id, operation = op, ok = false, error = error.Message, missingPacks = error.Packs });
                return true;
            }
            catch (Exception error)
            {
                Write(new { type = "response", id, operation = op, ok = false, error = error.Message });
                return true;
            }
        }
        catch (JsonException)
        {
            Write(new { type = "response", id = "", operation = "", ok = false, error = "invalid json" });
            return true;
        }
    }


    private object SaveLotToSlot(string slot, bool isCanonical, bool saveLot)
    {
        if (world is null || lot is null) throw new InvalidOperationException("There is no native lot to save.");
        RefreshPendingPersonPortraits();
        UpdatePreSaveState(world, lot);
        if (world.SavedSimulationState is { } savedSimi)
        {
            var (furnishingsValue, architectureValue) = CurrentLotValuation(savedSimi);
            world.ReplaceSavedValuation(furnishingsValue, architectureValue);
        }
        var (withObjects, _) = world.WriteSavedLotObjectsTo(lot);
        var saved = world.WriteSavedSimulationStateTo(withObjects);
        Directory.CreateDirectory(Saves);
        var saveSpeed = speed > 0 ? speed : lastRunningSpeed;
        var savedSuspendedHome = suspendedHomeLot is { } suspendedHome
            ? new SavedSuspendedHomeLot(suspendedHome.HomeHouse, suspendedHome.HomeFamilyChunkId,
                Convert.ToBase64String(suspendedHome.LotBytes), suspendedHome.Runtime, suspendedHome.Speed)
            : null;
        var runtimeMetadata = CaptureRuntimeMetadata(world, saved.Bytes.Span, saveSpeed, savedSuspendedHome);
        var runtimeJson = JsonSerializer.SerializeToUtf8Bytes(runtimeMetadata, Json);
        WriteReplace(SavePath(slot), saved.Bytes);
        WriteReplace(SaveRuntimePath(slot), runtimeJson);
        var lotWritten = false;
        string? lotSkipped = null;
        if (saveLot)
        {
            var neighborhoodUserData = Neighborhoods.UserData(profile);
            var userData = neighborhoodUserData;
            var housePath = Path.Combine(userData, "Houses", $"House{house:D2}.iff");
            var ordinarySimulationMode = world[SimulationGlobal.SimlessBuildMode] == 0;
            var skipCanonicalLotWrite = ordinarySimulationMode &&
                (house is >= 20 and <= 30 or >= 81 and <= 89 or >= 93 and <= 98 ||
                 (house is >= 40 and <= 49
                     ? activeFamilyChunkId is null or 0
                     : Neighborhoods.IsCommunityLot(neighborhoodUserData, house)));
            if (!skipCanonicalLotWrite)
            {
                Directory.CreateDirectory(Path.GetDirectoryName(housePath)!);
                WriteReplace(housePath, saved.Bytes);
                WriteReplace(CanonicalRuntimePath(housePath), runtimeJson);
                DeleteUnhousedCharacters(userData);
                lotWritten = true;
            }
            else
            {
                lotSkipped = "away";
            }
        }
        if (lotWritten && activeFamilyChunkId is { } famId && world.FamilyBudget is FamilyBudget fb && fb.ActiveFamily is { } fam)
        {
            var committedVac = house is >= 40 and <= 49 ? house : 0;
            if (fam.Field0x13C != committedVac)
                fb.ActiveFamily = fam.WithFields(field0x13C: committedVac);
            committedVacationState = (famId, committedVac);
        }
        lot = saved;
        if (neighborhood is not null && neighborhoodPath is not null)
        {
            PersistNeighborhoodStateImmediatelyCore(commitVacationField: lotWritten);
        }
        else
        {
            plugins?.CommitNeighborhood();
        }
        if (!isCanonical && neighborhood is not null)
        {
            WriteReplace(SaveNeighborhoodPath(slot), neighborhood.Bytes);
        }
        var storageSlot = Neighborhoods.StorageSlot(slot, Neighborhoods.Current);
        var envelopePath = SaveEnvelopePath(slot);
        Directory.CreateDirectory(Path.GetDirectoryName(envelopePath)!);
        var backup = File.Exists(envelopePath) ? SaveCompatibility.Backup(profile, storageSlot, envelopePath) : null;
        var nghBytesForSave = !isCanonical && neighborhood is not null ? Convert.ToBase64String(neighborhood.Bytes.Span) : null;
        var envelope = new SaveEnvelope(2, "native-simsengine-v0", packFingerprint, house, updates,
            Convert.ToBase64String(saved.Bytes.Span),
            plugins?.MigratedPacks.Select(pack => new SaveCompatibility.PackRecord(pack.Id, pack.Version)).ToArray() ?? [],
            plugins?.Save() ?? [], Neighborhoods.Current, runtimeMetadata with { SuspendedHome = null },
            nghBytesForSave, savedSuspendedHome, runtimeMetadata.RestrictedActivePersonKeys,
            CorePackFingerprint: corePackFingerprint);
        WriteReplace(envelopePath, JsonSerializer.SerializeToUtf8Bytes(envelope, Json));
        ResetLotValuationBaseline();
        saveDirty = false;
        return new { slot, path = envelopePath, saved = true, bytes = saved.Bytes.Length, backup, updates, canonical = isCanonical, lot = lotWritten, lotSkipped };
    }

    private object CloseLotInternal(bool save = false)
    {
        var saved = false;
        if (save && world is not null && lot is not null)
        {
            SaveLotToSlot("manual", isCanonical: false, saveLot: true);
            saved = true;
        }
        else
        {
            ReconcileCommittedVacationFieldOnDisk();
        }
        RemoveTileCursor();
        ResetAppearanceTransitions();
        audio?.Reset();
        audio?.SetMusicModeActive(false);
        world = null;
        lot = null;
        house = 0;
        activeFamilyChunkId = null;
        neighborhood = null;
        neighborhoodPath = null;
        suspendedHomeLot = null;
        committedVacationState = null;
        refreshedPersonFiles.Clear();
        simulationError = null;
        saveDirty = false;
        simulatorBlocked = false;
        speed = 0;
        lastRunningSpeed = 1;
        autoSpeedSaved = -1;
        dialogResumeSpeed = 0;
        selectedSim = 0;
        pieHead = null;
        cutawayTile = null;
        cutawayRooms.Clear();
        exportedCutawaySimKey = -1;
        ClearBuildHistory();
        revision = 0;
        previewRevision = 0;
        animationSequence = 0;
        animationState.Revision = 0;
        animationState.Kept = null;
        lastStreamedObjectsSignature = null;
        buildableLot = null;
        buildableMask = null;
        buildableLevel2Mask = null;
        stateFloorsLot = null;
        stateFloorsCache = null;
        stateWallsLot = null;
        stateWallsCache = null;
        cachedRoofLot = null;
        initialObjectValuation = default;
        initialValuationLot = null;
        lotValuationEdited = false;
        viewLevel = 1;
        viewerMode = 0;
        editingView = false;
        doorWindowBuildToolActive = false;
        wallpaperBuildToolActive = false;
        roofsVisible = false;
        return new { closed = true, saved, house = 0 };
    }

    private object OpenLotInternal(short requestedHouse, ushort? moveInFamily = null,
        ushort? activeFamilyOverride = null, (int? X, int? Y)? spawnCenter = null) =>
        OpenLotInternal(requestedHouse, moveInFamily, activeFamilyOverride, spawnCenter, out _);

    private object OpenLotInternal(short requestedHouse, ushort? moveInFamily,
        ushort? activeFamilyOverride, (int? X, int? Y)? spawnCenter, out string? memberInstantiation)
    {
        memberInstantiation = null;
        CloseLotInternal(save: false);
        var userData = Neighborhoods.UserData(profile);
        var (effectiveHouse, redirectedFamilyChunkId) = ResolveVacationRedirect(userData, requestedHouse);
        var path = Path.Combine(userData, "Houses", $"House{effectiveHouse:D2}.iff");
        if (!File.Exists(path)) throw new FileNotFoundException($"Lot {effectiveHouse} not found.");
        var runtime = ReadSavedRuntimeMetadata(CanonicalRuntimePath(path), File.ReadAllBytes(path));
        registry = EnsureRegistry().WithRefreshedPeople(Path.Combine(userData, "Characters"));
        var setup = WorldBootstrap.Load(game, path, language, () => speed == 0, effectiveHouse,
            userDataPath: userData, activeFamilyChunkId: activeFamilyOverride ?? redirectedFamilyChunkId,
            scoreAutonomy: ScoreAutonomyChoice, existingRegistry: registry,
            directsAutonomy: DirectsAutonomyForPerson, selectAutonomy: SelectAutonomyChoice);
        house = effectiveHouse;
        lot = setup.Lot;
        world = setup.World;
        global ??= setup.Global;
        registry = setup.Registry;
        neighborhoodPath = setup.NeighborhoodPath;
        neighborhood = setup.Neighborhood;
        activeFamilyChunkId = setup.ActiveFamilyChunkId;
        HydrateTypeAttributesFromNeighborhood(world, lot, neighborhood);
        if (activeFamilyChunkId is null && moveInFamily is null && !WorldBootstrap.HasResidentHouseholdSim(world))
        {
            world[SimulationGlobal.SimlessBuildMode] = 1;
        }
        else if (activeFamilyChunkId is not null)
        {
            world[SimulationGlobal.SimlessBuildMode] = 0;
        }
        if (registry is not null)
            world.UiTextFile ??= registry.UiText;
        AttachTutorialFlash(world);
        if (traceActions) world.CaptureExecutionTrace = true;
        if (viewerScale != 0) world[SimulationGlobal.ZoomLevelSML] = viewerScale;
        world[SimulationGlobal.Mode] = viewerMode;
        ClampAwayLotEditingState();
        AttachNoticeListener(world);
        RestorePersonAnimationRuntime(world, runtime.PersonAnimations);
        RestoreDialogRecords(world, runtime.Dialogs);
        if (runtime.ClockTicks is { } openedClockTicks)
            world.Clock.RestoreProgress(openedClockTicks, runtime.ClockDay ?? 0);
        RestoreTravelRuntimeState(world, userData, house, activeFamilyChunkId, setup.ActiveFamily, runtime);
        ClampAwayLotEditingState();
        if (setup.ActiveFamily is { Members.Count: > 0 } activeFamily)
        {
            var expectedKeys = (world.FamilyBudget as FamilyBudget)?.RestrictedActivePersonKeys
                ?? activeFamily.Members.Select(static m => unchecked((int)m)).ToArray();
            if (!world.WalkOrder.OfType<XPerson>().Any(p => expectedKeys.Contains(p.TypeRecord?.Key ?? 0)))
            {
                memberInstantiation = EnsureSelectedHouseholdMember(activeFamily, spawnCenter?.X ?? LotWidth / 2, spawnCenter?.Y ?? LotHeight / 2);
            }
        }
        selectedSim = DefaultSelectedSimId();
        SyncSelectedSimFlags(world, selectedSim);
        SetSimulationSpeed(0);
        lastRunningSpeed = runtime.Speed;
        if (HasBlockingDialog(world) && runtime.Speed > 0)
            dialogResumeSpeed = runtime.Speed;
        InitializeFameCallbackTarget(world);
        if (global is not null)
            world.AutonomyHost = BuildAutonomyHost(world, global, house);
        ResetLotValuationBaseline();
        if (moveInFamily is { } famId)
        {
            var (_, _, _, _, moveInstantiation) = MoveInFamilyCore(famId, spawnCenter?.X ?? LotWidth / 2, spawnCenter?.Y ?? LotHeight / 2);
            memberInstantiation = moveInstantiation;
            if (world is not null) world[SimulationGlobal.SimlessBuildMode] = 0;
        }
        else
        {
            InitializeViewLevelFromSelectedSim();
            Export();
        }
        if (audio?.Enabled == true)
            audio.PlayLotAmbience(house);
        Write(new { type = "state", state = State() });
        return new
        {
            house,
            homeHouse = EffectiveHomeHouse,
            away = IsVisitingAwayLot,
            simless = world![SimulationGlobal.SimlessBuildMode] != 0
        };
    }

    private string Saves => Path.Combine(profile, "native-saves");

    private static bool HasBlockingDialog(SimulationWorld? world) =>
        world is not null && (world.HasVisibleBlockingDialog ||
            world.DialogRecords.Any(record => record.Visible && record.State < 2 &&
                (record.Blocking || (record.Kind is 12 or 15 && record.BookMode is not null))));

    private void SetSimulationSpeed(int value, bool blockingDialog = false)
    {
        speed = Math.Clamp(value, 0, 1000);
        audio?.SetSimulationSpeed(speed);
        audio?.SetSimulationPaused(speed == 0, blockingDialog);
        if (world is not { } current) return;
        if (speed > 0) current[SimulationGlobal.Speed] = speed switch { 3 => 924, 10 => 994, _ => 760 };
        current[SimulationGlobal.Paused] = (short)(speed == 0 ? 1 : 0);
    }

    private void MarkSaveDirtyIfChanged(object? result)
    {
        if (result is null) return;
        var type = result.GetType();
        if (type.GetProperty("bought")?.GetValue(result) is true ||
            type.GetProperty("sold")?.GetValue(result) is true ||
            type.GetProperty("moved")?.GetValue(result) is true ||
            type.GetProperty("applied")?.GetValue(result) is true && type.GetProperty("changed") is null)
        {
            saveDirty = true;
            return;
        }
        var changed = type.GetProperty("changed")?.GetValue(result);
        if (changed is true || changed is int count && count > 0) saveDirty = true;
    }

    private static void WriteReplace(string path, ReadOnlyMemory<byte> bytes)
    {
        var temporary = path + ".tmp";
        try
        {
            File.WriteAllBytes(temporary, bytes.ToArray());
            File.Move(temporary, path, true);
        }
        finally
        {
            if (File.Exists(temporary)) File.Delete(temporary);
        }
    }

    private static int CountVisibleDialogs(SimulationWorld targetWorld)
    {
        var count = 0;
        var records = targetWorld.DialogRecords;
        for (var i = 0; i < records.Count; i++)
            if (records[i].Visible) count++;
        return count;
    }

    private void AdvancePausedTick()
    {
        try
        {
            var visible = CountVisibleDialogs(world!);
            var total = world!.DialogRecords.Count;
            world.AdvanceSimulationTick(new SimulationClockControl(0, 0, 0), 0, world.Clock.Ticks);
            LogNewThreadErrors();
            if (!streaming && (CountVisibleDialogs(world) != visible || world.DialogRecords.Count != total)) Export();
        }
        catch (Exception error) when (error is not OperationCanceledException and not OutOfMemoryException)
        {
            Console.Error.WriteLine($"Native paused tick failed: {error.Message}");
        }
    }

    private bool AdvanceOneTick(bool allowAutoSpeed = true)
    {
        try
        {
            var hadBlockingDialog = HasBlockingDialog(world);
            var previousHour = world!.Clock.Hour;
            Dictionary<short, (string Name, float Frame)>? routeAnimBefore = null;
            if (!world.AvatarAnimationRootOnly)
            {
                foreach (var walkItem in world.WalkOrder)
                {
                    if (walkItem is not XPerson person) continue;
                    if (person.AnimationPlayback is { RouteDriven: true, PracticeWeight: > 0f, Clip.SoundEvents.Count: > 0 } pb)
                    {
                        routeAnimBefore ??= [];
                        routeAnimBefore[person.Id] = (pb.Clip.Name, pb.Frame);
                    }
                }
            }
            var previousSelectedSim = selectedSim;
            familyMembershipChangedDuringTick = false;
            var control = new SimulationClockControl(1, 1, 1);
            world.AdvanceSimulationTick(control, 0, world.Clock.Ticks);
            if (world.PendingLotSwitch is { } pendingLotSwitch)
            {
                world.PendingLotSwitch = null;
                if (TryApplyPendingLotSwitch(world, pendingLotSwitch)) return true;
            }
            if (RefreshPendingPersonPortraits())
            {
                saveDirty = true;
                Write(new { type = "state", state = State() });
            }
            ReconcileSelectedSim(world);
            if (selectedSim != previousSelectedSim || familyMembershipChangedDuringTick)
            {
                familyMembershipChangedDuringTick = false;
                Export();
                Write(new { type = "state", state = State() });
            }
            if (!world.AvatarAnimationRootOnly && routeAnimBefore is not null)
                DispatchRouteAnimationSounds(world, routeAnimBefore);
            if (!world.AvatarAnimationRootOnly && plugins is not null && EnsureAppearanceTransitions() is { } transitions)
                transitions.Tick(world);
            if (world.Clock.Hour != previousHour) world.DispatchNotice(0xdb, world.Clock.Hour);
            if (allowAutoSpeed) UpdateAutoSpeed(world);
            if (traceActions) LogActionState();
            LogNewThreadErrors();
            LogNewInteractionGuardErrors();
            if (!hadBlockingDialog && HasBlockingDialog(world))
            {
                dialogResumeSpeed = speed;
                SetSimulationSpeed(0, blockingDialog: true);
                Export();
            }
            return true;
        }
        catch (Exception error) when (error is not OperationCanceledException and not OutOfMemoryException)
        {
            simulationError = $"{error.GetType().Name}: {error.Message}";
            SetSimulationSpeed(0);
            Console.Error.WriteLine($"Native simulation paused: {simulationError}");
            Console.Error.WriteLine(error);
            if (error.Data["tickingObject"] is { } tickingObject)
                Console.Error.WriteLine($"Native simulation error object: {tickingObject}");
            if (error.Data["executionLocation"] is { } executionLocation)
                Console.Error.WriteLine($"Native simulation error location: {executionLocation}");
            Export();
            return false;
        }
    }

    private void LogActionState()
    {
        var person = world?.ObjectById(selectedSim) as XPerson;
        if (person is null) return;
        if (!loggedSimRoster)
        {
            loggedSimRoster = true;
            foreach (var sim in world!.WalkOrder.OfType<XPerson>())
                Console.Error.WriteLine($"Native Sim roster: id={sim.Id} family={sim[PersonData.FamilyNumber]} activeFamily={activeFamilyChunkId} " +
                    $"age={sim[PersonData.PersonAge]} type={sim[PersonData.PersonType]} selected={sim.Id == selectedSim} position=({sim.Position.X},{sim.Position.Y},{sim.Position.Height})");
        }
        while (loggedQueuedInteractionStarts < world!.QueuedInteractionStartTrace.Count)
        {
            var start = world.QueuedInteractionStartTrace[loggedQueuedInteractionStarts++];
            Console.Error.WriteLine($"Native queued interaction start: sim={start.PersonId} target={start.TargetId} tree={start.ActionTree} " +
                $"scope={start.TargetScopeFound} guard={start.InteractionPassed}:{start.GuardTree} pushed={start.ActionTreePushed} " +
                $"selection={start.PersonSelectionWord} age={start.PersonAge} gender={start.PersonGender} stateClass={start.StateClass} targetFlags={start.TargetFlags:X4}");
        }
        var primitiveResults = world.PrimitiveResultTrace.Skip(loggedPrimitiveResults)
            .Where(entry => entry.ObjectId == selectedSim).ToArray();
        loggedPrimitiveResults = world.PrimitiveResultTrace.Count;
        var executionTraces = world.ExecutionTrace.Skip(loggedExecutionTraces)
            .Where(entry => entry.ObjectId == selectedSim && entry.Opcode == 0x1b).ToArray();
        loggedExecutionTraces = world.ExecutionTrace.Count;
        foreach (var trace in executionTraces)
            Console.Error.WriteLine($"Native relative-route operand: sim={trace.ObjectId} tree={trace.Tree} instruction={trace.Instruction} " +
                $"operand={trace.Operand} stack={trace.StackObject} parameters=[{string.Join(',', trace.Parameters)}] locals=[{string.Join(',', trace.Locals)}]");
        var rink = world.Objects.Values.FirstOrDefault(item =>
            item.TypeRecord?.Interactions?.Interactions.Any(interaction => interaction.Name == "Skate") == true);
        if (rink is not null)
        {
            var rinkIds = world.Objects.Values.Where(item => item.Id == rink.Id || item.MultiTileMasterId == rink.Id)
                .Select(item => item.Id).ToHashSet();
            var initTraces = world.ExecutionTrace.Skip(loggedRinkInitTraces).Where(entry => rinkIds.Contains(entry.ObjectId) &&
                entry.Tree is 4119 or 4124 or 4125 or 4101 or 4105).ToArray();
            loggedRinkInitTraces = world.ExecutionTrace.Count;
            foreach (var trace in initTraces)
            {
                var type = world.ObjectById(trace.ObjectId)?.TypeRecord;
                Console.Error.WriteLine($"Native rink init trace: object={trace.ObjectId} subindex={type?.SubIndex} " +
                    $"tree={trace.Tree} instruction={trace.Instruction} opcode={trace.Opcode:X2} operand={trace.Operand} " +
                    $"parameters=[{string.Join(',', trace.Parameters)}] locals=[{string.Join(',', trace.Locals)}]");
            }
        }
        foreach (var result in primitiveResults)
            Console.Error.WriteLine($"Native primitive trace: sim={result.ObjectId} tree={result.Tree} instruction={result.Instruction} " +
                $"opcode={result.Opcode:X2} result={result.Result} parameters=[{string.Join(',', result.Parameters)}]");
        while (loggedNativeRoutes < world.NativeRouteTrace.Count)
        {
            var route = world.NativeRouteTrace[loggedNativeRoutes++];
            Console.Error.WriteLine($"Native route trace: actor={route.ActorId} anchor={route.AnchorId} destination={route.Destination} phase={route.Phase} failure={route.Failure}");
        }
        while (loggedRouteSearches < world.RouteSearchTrace.Count)
        {
            var route = world.RouteSearchTrace[loggedRouteSearches++];
            Console.Error.WriteLine($"Native route search: actor={route.ActorId} destination={route.Destination} start=({route.StartTile.X},{route.StartTile.Y}) " +
                $"end=({route.EndTile.X},{route.EndTile.Y}) rooms={route.StartRoom}->{route.EndRoom} visited={route.VisitedTiles} " +
                $"rejected={route.RejectedPlacements}/{route.RejectedEdges} visitedRooms={route.VisitedRooms}");
        }
        while (loggedRouteCandidates < world.RouteCandidateTrace.Count)
        {
            var candidate = world.RouteCandidateTrace[loggedRouteCandidates++];
            if (candidate.ActorId != selectedSim) continue;
            var blocker = candidate.BlockingObjectId is { } blockerId ? world.ObjectById(blockerId) : null;
            var blockerGuid = blocker is null ? 0u : (uint)(ushort)blocker.Definition[(int)ObjdField.Guid1] |
                ((uint)(ushort)blocker.Definition[(int)ObjdField.Guid2] << 16);
            var anchor = world.ObjectById(candidate.AnchorId);
            var anchorParts = anchor is null ? Array.Empty<XObject>() : world.Objects.Values
                .Where(item => item.Id == anchor.Id || item.MultiTileMasterId == anchor.Id).ToArray();
            Console.Error.WriteLine($"Native route candidate: actor={candidate.ActorId} anchor={candidate.AnchorId} position={candidate.Position} " +
                $"room={candidate.Room} direction={candidate.Direction} accepted={candidate.PlacementAccepted} " +
                $"failure={candidate.PlacementFailureCode} blocker={candidate.BlockingObjectId} " +
                $"blockerGuid=0x{blockerGuid:X8} blockerName={blocker?.TypeRecord?.Name ?? "<missing>"} " +
                $"blockerSubIndex={blocker?.TypeRecord?.SubIndex} blockerMaster={blocker?.MultiTileMasterId} " +
                $"blockerNext={blocker?.MultiTileNextId} blockerPosition={blocker?.Position} " +
                $"blockerDataFlags=0x{(ushort)(blocker?[ObjectData.Flags] ?? 0):X4} " +
                $"blockerAllowedHeight=0x{(ushort)(blocker?[ObjectData.AllowedHeightFlags] ?? 0):X4} " +
                $"blockerPlacementFlags=0x{(ushort)(blocker?[ObjectData.PlacementFlags] ?? 0):X4} " +
                $"blockerFunctions=[{string.Join(',', blocker?.TypeRecord?.FunctionTable?.Take(2) ?? [])}] " +
                $"anchorFlags=0x{(ushort)(anchor?[ObjectData.Flags] ?? 0):X4} " +
                $"anchorAllowedHeight=0x{(ushort)(anchor?[ObjectData.AllowedHeightFlags] ?? 0):X4} " +
                $"anchorPlacementFlags=0x{(ushort)(anchor?[ObjectData.PlacementFlags] ?? 0):X4} " +
                $"anchorPartCount={anchorParts.Length} reason={candidate.FailureReason}");
        }
        var queued = person.ActionQueueEnd - person.ActionQueueCurrent;
        var queue = queued is >= 0 and <= 8
            ? string.Join(",", Enumerable.Range(0, queued).Select(index =>
            {
                var action = person.ActionQueue[(person.ActionQueueCurrent + index) & 7];
                return $"{action.Owner?.Id ?? 0}:{action.ActionTree}:{action.Flags:X2}";
            }))
            : $"invalid({queued})";
        var stack = world!.SavedExecutionStacks.GetValueOrDefault(person.Id);
        var frames = stack is null ? "none" : string.Join("/", stack.Frames.TakeLast(5).Select(frame =>
            $"{frame.TreeId}:{frame.Instruction}:{frame.WaitState}:p[{string.Join(',', frame.Parameters)}]:l[{string.Join(',', frame.Locals)}]"));
        var active = person.CurrentActionRecord is { Owner: not null } current
            ? $"{current.Owner.Id}:{current.ActionTree}:{current.Flags:X2}" : "none";
        var target = world.ObjectById(110);
        var tracedRoute = person.NativeRoute;
        var playback = person.AnimationPlayback;
        Console.Error.WriteLine($"Native action trace: tick={updates} sim={person.Id} pos=({person.Position.X},{person.Position.Y},{person.Position.Height}) " +
            $"root=({person.AnimatorRootX:R},{person.AnimatorRootY:R}) direction={person.AnimatorRootDirection:R} " +
            $"control={person.AnimatorControlState} follow={tracedRoute?.AnimatorFollowState} skill={tracedRoute?.MotionAnimationIndex} " +
            $"routeFrame={tracedRoute?.MotionPracticeFrame:R} practice={playback?.Clip.Name} practiceFrame={playback?.Frame:R} " +
            $"weight={playback?.PracticeWeight:R} rootOnly={world.AvatarAnimationRootOnly} " +
            $"priority={person[PersonData.Priority]} nonInterruptible={person[PersonData.NonInterruptible]} stateClass={world.StateClass(person.StateValue)} inputFlags={person.InputFlags:X2} bladder={person[Motive.Bladder]:F2} active={active} queue=[{queue}] pending={person.PendingActionRequests.Count} toiletUseCount={(target is null ? "missing" : target[ObjectData.UseCount].ToString())} stack={frames}");
    }

    private void LogNewThreadErrors()
    {
        if (world is null) return;
        while (loggedThreadErrors < world.ThreadErrors.Count)
        {
            var error = world.ThreadErrors[loggedThreadErrors++];
            Console.Error.WriteLine($"Native SimAntics thread error: object {error.ObjectId} ({DescribeObject(error.ObjectId)}): {error.Message}");
            if (error.Frames is null) continue;
            foreach (var frame in error.Frames)
                Console.Error.WriteLine($"  BHAV {frame.Tree} instruction {frame.Instruction}, opcode {frame.Opcode?.ToString("X2") ?? "none"}, stack object {frame.StackObject} ({DescribeObject(frame.StackObject)}), code owner {frame.CodeOwner}, parameters [{string.Join(",", frame.Parameters)}], locals [{string.Join(",", frame.Locals)}]");
        }
    }

    private string DescribeObject(short id)
    {
        if (world?.ObjectById(id) is not { } item) return "none";
        var guid = unchecked((uint)(item.TypeRecord?.Key ?? 0));
        var name = registry?.Find(guid)?.CatalogString(0, language) ?? Path.GetFileName(registry?.Find(guid)?.Source ?? "");
        return $"GUID 0x{guid:X8} {name}";
    }

    private void LogNewInteractionGuardErrors()
    {
        if (world is null) return;
        while (loggedInteractionGuardErrors < world.InteractionGuardErrors.Count)
        {
            var error = world.InteractionGuardErrors[loggedInteractionGuardErrors++];
            Console.Error.WriteLine($"Native interaction check rejected: person {error.PersonId}, object {error.ObjectId}, " +
                $"TTAB entry {error.InteractionId}, BHAV {error.GuardTree}: error {(short)error.Error} " + error.Message);
        }
    }

    private CatalogLotType CurrentCatalogLotType()
    {
        if (world is null || world[SimulationGlobal.SimlessBuildMode] == 0)
            return CatalogLotType.Residential;
        var userData = Path.GetDirectoryName(neighborhoodPath) ?? Neighborhoods.UserData(profile);
        return house switch
        {
            >= 21 and <= 31 => CatalogLotType.Downtown,
            >= 40 and <= 49 => CatalogLotType.Vacation,
            >= 81 and <= 89 => CatalogLotType.StudioTown,
            >= 93 and <= 99 => CatalogLotType.MagicTown,
            _ when house > 0 && Neighborhoods.IsCommunityLot(userData, house) => CatalogLotType.Community,
            _ => CatalogLotType.Residential,
        };
    }

    private IReadOnlyList<PluginHost.BuyCatalogViewEntry> ResolveBuyCatalogViews()
    {
        if (plugins is null || registry is null)
            return [];
        var catalogObjects = ObjectCatalog.BuildPluginCatalogObjects(registry, language, CurrentCatalogLotType(), game);
        return plugins.BuyCatalogViews(catalogObjects);
    }

    private HashSet<uint>? ResolveHiddenCatalogGuids()
    {
        var views = ResolveBuyCatalogViews();
        if (views.Count == 0)
            return null;
        HashSet<uint>? hidden = null;
        foreach (var entry in views)
        {
            if (!entry.View.HideMatchedFromStandardCatalog)
                continue;
            hidden ??= [];
            foreach (var collection in entry.View.Collections)
            {
                foreach (var guid in collection.Guids)
                    hidden.Add(guid);
            }
        }
        return hidden;
    }
}
