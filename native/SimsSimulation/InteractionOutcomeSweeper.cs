using System.Buffers.Binary;
using System.Globalization;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsSimulation;

[JsonConverter(typeof(JsonStringEnumConverter))]
internal enum InteractionOutcomeKind
{
    Succeeded,
    ThreadError,
    GuardError,
    NeverOffered,
    RouteFailed,
    MissingAnimation,
    EarlyBailout,
    Stalled,
}

internal sealed record SweepOptions(
    string GameRoot,
    string WorkspaceRoot,
    string? OutputDir = null,
    string? PackFilter = null,
    int Ticks = 450,
    int? Limit = null,
    short House = 5,
    bool Subhoods = false,
    bool IncludeTravel = false,
    byte Language = 1,
    uint? GuidFilter = null,
    bool ShippedLots = false,
    string ActorMode = "adult",
    bool Socials = false,
    bool Chained = false,
    bool States = false);

internal sealed record InteractionTrialRecord(
    string Pack,
    string LotType,
    short House,
    uint ObjectGuid,
    string ObjectName,
    string PlacementAnchorKind,
    int TtaIndex,
    string InteractionName,
    ushort ActionTree,
    ushort GuardTree,
    InteractionOutcomeKind Outcome,
    int TicksRun,
    string RootSignature,
    string Detail,
    float MotiveDeltaAbs,
    int DialogsTriggered,
    int AnimationsPlayed,
    int MissingAnimations,
    int RouteFailures,
    int ThreadErrorCount,
    int GuardErrorCount);

internal sealed record ObjectSweepRecord(
    string Pack,
    string LotType,
    short House,
    uint Guid,
    string Name,
    bool Placed,
    string PlacementAnchorKind,
    int PlacementFailureCode,
    int TtabCount,
    int OfferedCount,
    int GuardErrorCount,
    int NeverOfferedCount,
    IReadOnlyList<InteractionTrialRecord> Trials);

internal sealed record FailureCluster(
    InteractionOutcomeKind OutcomeKind,
    string Signature,
    int Count,
    int DistinctObjects,
    IReadOnlyList<string> Packs,
    IReadOnlyList<string> Samples,
    string Detail);

internal sealed record PlacementFailureCluster(
    int FailureCode,
    string Hint,
    int Count,
    IReadOnlyList<string> Samples);

internal sealed record SweepReport(
    int ObjectsTested,
    int ObjectsPlaced,
    int ObjectsPlacementFailed,
    int TotalTtabEntries,
    int TotalTrials,
    Dictionary<string, int> OutcomeCounts,
    IReadOnlyList<FailureCluster> Clusters,
    IReadOnlyList<PlacementFailureCluster> PlacementFailures,
    IReadOnlyList<ObjectSweepRecord> Objects);

internal static class InteractionOutcomeSweeper
{
    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        WriteIndented = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
    };

    private static void SweepShippedLots(
        string gameRoot,
        string userData,
        ObjectRegistry registry,
        IffFile? baselineNeighborhood,
        SweepOptions options,
        List<ObjectSweepRecord> results)
    {
        var housesDir = Path.Combine(userData, "Houses");
        if (!Directory.Exists(housesDir)) return;
        var lotFiles = Directory.EnumerateFiles(housesDir, "House*.iff")
            .Select(path => (Path: path, Name: Path.GetFileNameWithoutExtension(path)))
            .Where(item => short.TryParse(item.Name.AsSpan(5), NumberStyles.None, CultureInfo.InvariantCulture, out var num) && num > 0)
            .Select(item => (item.Path, House: short.Parse(item.Name.AsSpan(5), CultureInfo.InvariantCulture)))
            .OrderBy(item => item.House)
            .ToList();
        if (options.Limit is { } lim && lotFiles.Count > lim)
            lotFiles = lotFiles.Take(lim).ToList();

        foreach (var (lotPath, house) in lotFiles)
        {
            var lotType = house switch
            {
                >= 21 and <= 31 => CatalogLotType.Downtown,
                >= 40 and <= 49 => CatalogLotType.Vacation,
                >= 50 and <= 80 => CatalogLotType.Community,
                >= 81 and <= 89 => CatalogLotType.StudioTown,
                >= 90 and <= 99 => CatalogLotType.MagicTown,
                _ => CatalogLotType.Residential,
            };
            Console.Error.WriteLine($"[audit] Sweeping shipped lot House{house:D2} ({lotType})...");
            try
            {
                var harness = InitializeLotHarness(gameRoot, lotPath, userData, house, lotType, registry, baselineNeighborhood, options.Language);
                var world = harness.Bootstrap.World;
                var actor = harness.Actor;
                var prevThreadErrors = world.ThreadErrors.Count;
                var prevGuardErrors = world.InteractionGuardErrors.Count;

                // First run live lot soak ticks to catch any passive lot-object or NPC controller thread errors.
                var soakTicks = Math.Min(options.Ticks, 180);
                var soakTrials = new List<InteractionTrialRecord>();
                for (var t = 0; t < soakTicks; t++)
                {
                    world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
                    DismissAllDialogs(world);
                }
                for (var i = prevThreadErrors; i < world.ThreadErrors.Count; i++)
                {
                    var err = world.ThreadErrors[i];
                    var owner = world.ObjectById(err.ObjectId);
                    var top = err.Frames is { Length: > 0 } ? err.Frames[^1] : (ThreadFrameError?)null;
                    var errPrefix = err.Message.Split('(')[0].Trim();
                    var sig = top is { } f
                        ? $"LotSoakThreadError({owner?.TypeRecord?.Name ?? $"id{err.ObjectId}"}):{errPrefix}:{f.ResourceScope ?? "?"}:0x{unchecked((ushort)f.Tree):X4}:{f.Instruction}:{(f.Opcode is { } op ? InteractionCensus.PrimitiveName(op) : "?")}:{f.Operand}"
                        : $"LotSoakThreadError({owner?.TypeRecord?.Name ?? $"id{err.ObjectId}"}):{errPrefix}";
                    soakTrials.Add(new InteractionTrialRecord(
                        lotType.ToString(), lotType.ToString(), house,
                        unchecked((uint)(owner?.TypeRecord?.Key ?? 0)), owner?.TypeRecord?.Name ?? $"House{house:D2}",
                        "shipped-lot", 0, "LotSoak", 0, 0,
                        InteractionOutcomeKind.ThreadError, soakTicks, sig,
                        $"[House{house:D2} obj={err.ObjectId}] {err.Message}",
                        0f, 0, 0, 0, 0, 1, 0));
                }
                if (soakTrials.Count == 0)
                {
                    soakTrials.Add(new InteractionTrialRecord(
                        lotType.ToString(), lotType.ToString(), house, 0, $"House{house:D2}",
                        "shipped-lot", 0, "LotSoak", 0, 0,
                        InteractionOutcomeKind.Succeeded, soakTicks, "OK", $"Clean {soakTicks}-tick lot soak",
                        0f, 0, 0, 0, 0, 0, 0));
                }
                results.Add(new ObjectSweepRecord(
                    lotType.ToString(), lotType.ToString(), house, (uint)house, $"House{house:D2} Soak",
                    Placed: true, "shipped-lot", 0, 1, 1, world.InteractionGuardErrors.Count - prevGuardErrors, 0, soakTrials));

                // Then sample up to 12 distinct interactive pre-placed objects on the lot.
                var sampledGuids = new HashSet<uint>();
                var lotObjects = world.WalkOrder
                    .Where(o => o is not XPerson && o.Position.Height == 1 && o.MultiTileMasterId == 0 &&
                        o.Position.X >= 0 && o.Position.Y >= 0 && o.RoomWord84 >= 0 &&
                        o[ObjectData.Hidden] == 0 && (o[ObjectData.Flags] & 0x200) == 0 &&
                        o.Definition[(int)ObjdField.NumGraphics] > 0 &&
                        world.EffectiveInteractions(o)?.Interactions.Count > 0)
                    .ToList();
                var testedOnLot = 0;
                foreach (var obj in lotObjects)
                {
                    if (testedOnLot >= 12 || !world.Objects.ContainsKey(actor.Id)) break;
                    var guid = unchecked((uint)(obj.TypeRecord?.Key ?? 0));
                    if (guid == 0 || !sampledGuids.Add(guid)) continue;
                    var regEntry = registry.Find(guid);
                    var catEntry = new ObjectCatalogEntry(
                        regEntry ?? registry.Entries[0], guid, 0, 0,
                        obj.TypeRecord?.CatalogName ?? obj.TypeRecord?.Name ?? $"0x{guid:X8}", "");

                    PrepareActorForProbe(world, actor, obj.Position, drained: true);
                    var choices = ReadInteractionChoices(world, actor, obj)
                        .Where(c => !IsTravelOrDestructiveLabel(c.ActionText ?? ""))
                        .GroupBy(c => c.RawDword10)
                        .Select(g => g.First())
                        .Take(2)
                        .ToList();
                    if (choices.Count == 0) continue;

                    var trials = new List<InteractionTrialRecord>();
                    var ttab = world.EffectiveInteractions(obj)?.Interactions ?? [];
                    foreach (var choice in choices)
                    {
                        if (!world.Objects.ContainsKey(obj.Id) || !world.Objects.ContainsKey(actor.Id)) break;
                        var decl = ttab.FirstOrDefault(d => d.TtaIndex == choice.RawDword10);
                        trials.Add(ExecuteInteractionTrial(world, harness, catEntry, obj, "shipped-lot", choice, decl, Math.Min(options.Ticks, 240)));
                    }
                    results.Add(new ObjectSweepRecord(
                        regEntry?.Scan.ToString() ?? lotType.ToString(), lotType.ToString(), house, guid, catEntry.Name,
                        Placed: true, "shipped-lot", 0, ttab.Count, choices.Count, 0, 0, trials));
                    testedOnLot++;
                }
            }
            catch (Exception ex) when (ex is not OutOfMemoryException)
            {
                var sig = $"LotLoadError:House{house:D2}:{ex.GetType().Name}:{ex.Message.Split('(')[0].Trim()}";
                results.Add(new ObjectSweepRecord(
                    lotType.ToString(), lotType.ToString(), house, (uint)house, $"House{house:D2}",
                    Placed: false, "shipped-lot", 0, 0, 0, 0, 0,
                    [new InteractionTrialRecord(lotType.ToString(), lotType.ToString(), house, (uint)house, $"House{house:D2}",
                        "shipped-lot", 0, "LotLoad", 0, 0, InteractionOutcomeKind.ThreadError, 0, sig, ex.ToString(),
                        0f, 0, 0, 0, 0, 1, 0)]));
            }
        }
    }

    private static readonly string[] SkipTravelKeywords =
    [
        "call cab", "go downtown", "go to vacation", "go to old town", "go to studio town",
        "go to magic town", "return home", "move out", "evict", "check out",
        "invite to old town", "invite downtown", "invite to studio town", "invite to magic town",
    ];

    private sealed record StagingAnchor(string Kind, ObjectPosition Position, byte Direction, int HeightCode);

    private sealed class LotHarness
    {
        public required WorldBootstrap Bootstrap { get; set; }
        public required string LotPath { get; init; }
        public required string UserData { get; init; }
        public required short House { get; init; }
        public required CatalogLotType LotType { get; init; }
        public required string ActorMode { get; init; }
        public required IffFile BaselineLot { get; init; }
        public required IffFile? BaselineNeighborhood { get; init; }
        public required ObjectRegistry Registry { get; init; }
        public required XPerson Actor { get; set; }
        public XPerson? Partner { get; set; }
        public required ObjectPosition ActorHomePosition { get; set; }
        public required List<StagingAnchor> Anchors { get; set; }
        public required HashSet<short> BaselineObjectIds { get; set; }
        public bool NeedsReload { get; set; }
    }

    public static SweepReport Run(SweepOptions options)
    {
        var gameRoot = Path.GetFullPath(options.GameRoot);
        var workspaceRoot = Path.GetFullPath(options.WorkspaceRoot);
        Directory.CreateDirectory(workspaceRoot);

        var profileId = "audit-" + Guid.NewGuid().ToString("N")[..8];
        var profile = Path.Combine(workspaceRoot, "runtime", "profiles", profileId);
        try
        {
            ProfileBootstrap.EnsureNeighborhoodImported(gameRoot, profile, 1);
            var userData = Neighborhoods.UserData(profile);
            var registry = ObjectRegistry.Scan(gameRoot, Path.Combine(userData, "Characters"));
            var neighborhoodPath = Path.Combine(userData, "Neighborhood.iff");
            var baselineNeighborhood = File.Exists(neighborhoodPath) ? IffFile.Open(neighborhoodPath) : null;

            var lotPlan = new List<(CatalogLotType LotType, short House)>();
            if (options.Subhoods)
            {
                // Run EP-native subhood lots before Residential so community/fame/magic objects run in their native lot context.
                lotPlan.Add((CatalogLotType.StudioTown, 81));
                lotPlan.Add((CatalogLotType.MagicTown, 90));
                lotPlan.Add((CatalogLotType.Vacation, 40));
                lotPlan.Add((CatalogLotType.Community, 50));
                lotPlan.Add((CatalogLotType.Downtown, 21));
            }
            lotPlan.Add((CatalogLotType.Residential, options.House));

            var allObjectRecords = new List<ObjectSweepRecord>();
            var testedGuids = new HashSet<uint>();
            var remainingLimit = options.Limit;

            if (options.ShippedLots)
            {
                SweepShippedLots(gameRoot, userData, registry, baselineNeighborhood, options, allObjectRecords);
            }
            else if (options.Socials)
            {
                SweepSocials(gameRoot, userData, registry, baselineNeighborhood, options, lotPlan, allObjectRecords);
            }
            else
            {
                foreach (var (lotType, house) in lotPlan)
                {
                    if (remainingLimit is <= 0) break;
                    var lotPath = Path.Combine(userData, "Houses", $"House{house:D2}.iff");
                    if (!File.Exists(lotPath)) continue;

                    var catalogEntries = CollectCatalogEntries(registry, options.Language, lotType, options.PackFilter, options.GuidFilter, testedGuids);
                    if (catalogEntries.Count == 0) continue;
                    if (remainingLimit is { } rem && catalogEntries.Count > rem)
                        catalogEntries = catalogEntries.Take(rem).ToList();

                    Console.Error.WriteLine($"[audit] Sweeping {catalogEntries.Count} {lotType} objects on House{house:D2} (actor={options.ActorMode}{(options.Chained ? ", chained" : "")})...");
                    var harness = InitializeLotHarness(gameRoot, lotPath, userData, house, lotType, registry, baselineNeighborhood, options.Language, options.ActorMode);

                    var processedInLot = 0;
                    foreach (var entry in catalogEntries)
                    {
                        testedGuids.Add(entry.Guid);
                        var record = SweepSingleObject(harness, entry, options);
                        allObjectRecords.Add(record);
                        processedInLot++;
                        if (remainingLimit is not null) remainingLimit--;

                        if (processedInLot % 25 == 0 || processedInLot == catalogEntries.Count)
                        {
                            var errCount = allObjectRecords.Sum(o => o.Trials.Count(t => t.Outcome is not (InteractionOutcomeKind.Succeeded or InteractionOutcomeKind.NeverOffered)));
                            Console.Error.WriteLine($"[audit] {lotType} House{house:D2}: {processedInLot}/{catalogEntries.Count} objects (actionable failures so far: {errCount})");
                        }

                        if (harness.NeedsReload || processedInLot % 60 == 0 || !harness.Bootstrap.World.Objects.ContainsKey(harness.Actor.Id))
                        {
                            harness.NeedsReload = false;
                            ReloadLotHarness(harness, gameRoot, options.Language);
                        }
                    }
                }
            }

            var report = BuildReport(allObjectRecords);
            if (!string.IsNullOrWhiteSpace(options.OutputDir))
            {
                var fullOut = Path.GetFullPath(options.OutputDir);
                Directory.CreateDirectory(fullOut);
                File.WriteAllText(Path.Combine(fullOut, "sweep_report.json"), JsonSerializer.Serialize(report, JsonOptions));
                File.WriteAllText(Path.Combine(fullOut, "clusters.md"), FormatClustersMarkdown(report, options));
            }
            return report;
        }
        finally
        {
            try { if (Directory.Exists(profile)) Directory.Delete(profile, recursive: true); } catch { }
        }
    }

    internal static SweepReport BuildReport(IReadOnlyList<ObjectSweepRecord> objects)
    {
        var allTrials = objects.SelectMany(o => o.Trials).ToList();
        var outcomeCounts = Enum.GetValues<InteractionOutcomeKind>()
            .ToDictionary(kind => kind.ToString(), kind => allTrials.Count(t => t.Outcome == kind));
        var clusters = ClusterFailures(allTrials);
        var placementFailures = ClusterPlacementFailures(objects);

        return new SweepReport(
            ObjectsTested: objects.Count,
            ObjectsPlaced: objects.Count(o => o.Placed),
            ObjectsPlacementFailed: objects.Count(o => !o.Placed),
            TotalTtabEntries: objects.Sum(o => o.TtabCount),
            TotalTrials: allTrials.Count,
            OutcomeCounts: outcomeCounts,
            Clusters: clusters,
            PlacementFailures: placementFailures,
            Objects: objects);
    }

    internal static IReadOnlyList<FailureCluster> ClusterFailures(IReadOnlyList<InteractionTrialRecord> trials)
    {
        return trials
            .Where(t => t.Outcome != InteractionOutcomeKind.Succeeded)
            .GroupBy(t => (t.Outcome, t.RootSignature))
            .Select(group =>
            {
                var items = group.ToList();
                var packs = items.Select(i => i.Pack).Distinct(StringComparer.OrdinalIgnoreCase).Order(StringComparer.OrdinalIgnoreCase).ToArray();
                var samples = items
                    .GroupBy(i => (i.ObjectGuid, i.InteractionName))
                    .Take(8)
                    .Select(g =>
                    {
                        var first = g.First();
                        return $"0x{first.ObjectGuid:X8} {first.ObjectName} -> \"{first.InteractionName}\" (tree=0x{first.ActionTree:X4}, ticks={first.TicksRun})";
                    })
                    .ToArray();
                return new FailureCluster(
                    group.Key.Outcome,
                    group.Key.RootSignature,
                    items.Count,
                    items.Select(i => i.ObjectGuid).Distinct().Count(),
                    packs,
                    samples,
                    items[0].Detail);
            })
            .OrderByDescending(c => c.Count)
            .ThenBy(c => c.OutcomeKind)
            .ThenBy(c => c.Signature, StringComparer.Ordinal)
            .ToArray();
    }

    private static IReadOnlyList<PlacementFailureCluster> ClusterPlacementFailures(IReadOnlyList<ObjectSweepRecord> objects)
    {
        return objects
            .Where(o => !o.Placed)
            .GroupBy(o => o.PlacementFailureCode)
            .Select(group => new PlacementFailureCluster(
                group.Key,
                DescribePlacementFailureCode(group.Key),
                group.Count(),
                group.Take(10).Select(o => $"0x{o.Guid:X8} {o.Name} ({o.Pack})").ToArray()))
            .OrderByDescending(c => c.Count)
            .ToArray();
    }

    private static List<ObjectCatalogEntry> CollectCatalogEntries(
        ObjectRegistry registry,
        byte language,
        CatalogLotType lotType,
        string? packFilter,
        uint? guidFilter,
        HashSet<uint> alreadyTested)
    {
        var entries = new List<ObjectCatalogEntry>();
        foreach (var source in registry.ByGuid.Values)
        {
            if (alreadyTested.Contains(source.Guid)) continue;
            if (guidFilter is { } targetGuid && source.Guid != targetGuid) continue;
            if (!string.IsNullOrWhiteSpace(packFilter) && !MatchesPack(source.Scan, packFilter)) continue;
            if (!ObjectCatalog.TryGetEntry(source, language, lotType, out var item) || item is null) continue;
            if (source.Definition[ObjdField.RoomSort] == 0 && source.Definition[ObjdField.BuildModeType] is >= 1 and <= 7)
                continue;
            // On subhood lots, prefer objects that are community/EP-exclusive (not residential-buyable)
            // so standard chairs/lamps still get tested on the residential lot.
            if (lotType != CatalogLotType.Residential && guidFilter is null &&
                ObjectCatalog.TryGetEntry(source, language, CatalogLotType.Residential, out _))
                continue;
            entries.Add(item);
        }
        entries.Sort((a, b) => a.Guid.CompareTo(b.Guid));
        return entries;
    }

    private static bool MatchesPack(ObjectScan scan, string filter)
    {
        var normalized = filter.Replace("'", "", StringComparison.Ordinal).Replace(" ", "", StringComparison.Ordinal);
        return scan switch
        {
            ObjectScan.Objects or ObjectScan.Deluxe or ObjectScan.ExpansionShared =>
                normalized.Equals("Base", StringComparison.OrdinalIgnoreCase) || scan.ToString().Equals(normalized, StringComparison.OrdinalIgnoreCase),
            ObjectScan.Spellbound =>
                normalized.Equals("MakinMagic", StringComparison.OrdinalIgnoreCase) || normalized.Equals("Spellbound", StringComparison.OrdinalIgnoreCase),
            _ => scan.ToString().Equals(normalized, StringComparison.OrdinalIgnoreCase),
        };
    }

    private static void SweepSocials(
        string gameRoot,
        string userData,
        ObjectRegistry registry,
        IffFile? baselineNeighborhood,
        SweepOptions options,
        List<(CatalogLotType LotType, short House)> lotPlan,
        List<ObjectSweepRecord> results)
    {
        var globalSeenLabels = new HashSet<(string PairKind, string Label)>(new PairLabelComparer());

        foreach (var (lotType, house) in lotPlan)
        {
            var lotPath = Path.Combine(userData, "Houses", $"House{house:D2}.iff");
            if (!File.Exists(lotPath)) continue;

            Console.Error.WriteLine($"[audit] Sweeping social interactions on House{house:D2} ({lotType})...");
            var harness = InitializeLotHarness(gameRoot, lotPath, userData, house, lotType, registry, baselineNeighborhood, options.Language, "adult");
            var world = harness.Bootstrap.World;
            var familyNum = harness.Actor[PersonData.FamilyNumber];

            var adultA = harness.Actor;
            var adultB = harness.Partner ?? SpawnPersonByMode(world, registry, harness.Bootstrap.ActiveFamily, "adult", familyNum, excludeKey: adultA.TypeRecord?.Key ?? 0);
            var child = world.WalkOrder.OfType<XPerson>().FirstOrDefault(p => p[PersonData.PersonType] == 0 && PersonAgeCategory.IsChild(p[PersonData.PersonAge]) && (p[PersonData.Gender] & 6) == 0)
                ?? SpawnPersonByMode(world, registry, harness.Bootstrap.ActiveFamily, "child", familyNum, excludeKey: 0);
            var dog = world.WalkOrder.OfType<XPerson>().FirstOrDefault(p => (p[PersonData.Gender] & 2) != 0)
                ?? SpawnPersonByMode(world, registry, harness.Bootstrap.ActiveFamily, "dog", familyNum, excludeKey: 0);
            var cat = world.WalkOrder.OfType<XPerson>().FirstOrDefault(p => (p[PersonData.Gender] & 4) != 0)
                ?? SpawnPersonByMode(world, registry, harness.Bootstrap.ActiveFamily, "cat", familyNum, excludeKey: 0);

            var pairs = new List<(string Kind, XPerson Source, XPerson Target)>();
            if (adultB is not null) pairs.Add(("Adult->Adult", adultA, adultB));
            if (child is not null)
            {
                pairs.Add(("Adult->Child", adultA, child));
                pairs.Add(("Child->Adult", child, adultA));
            }
            if (dog is not null)
            {
                pairs.Add(("Adult->Dog", adultA, dog));
                pairs.Add(("Dog->Adult", dog, adultA));
            }
            if (cat is not null)
            {
                pairs.Add(("Adult->Cat", adultA, cat));
                pairs.Add(("Cat->Adult", cat, adultA));
            }
            if (dog is not null && cat is not null)
                pairs.Add(("Dog->Cat", dog, cat));

            var tiers = new (string Name, short Daily, short Lifetime, short Flags)[]
            {
                ("Stranger", 0, 0, 0),
                ("Friend", 65, 65, 1),
                ("Romantic", 100, 100, 7),
            };

            var openPos = harness.ActorHomePosition;
            foreach (var (pairKind, source, target) in pairs)
            {
                var pairTrials = new List<InteractionTrialRecord>();
                var offeredCount = 0;
                var guardErrors = 0;
                var targetGuid = unchecked((uint)(target.TypeRecord?.Key ?? 0));
                var catEntry = new ObjectCatalogEntry(
                    registry.Find(targetGuid) ?? registry.Entries[0],
                    targetGuid, 0, 0, $"{pairKind} ({target.TypeRecord?.Name ?? $"id{target.Id}"})", "");

                foreach (var (tierName, daily, lifetime, relFlags) in tiers)
                {
                    if (!world.Objects.ContainsKey(source.Id) || !world.Objects.ContainsKey(target.Id)) break;
                    SetSymmetricRelationship(world, source, target, daily, lifetime, relFlags);
                    ResetActorState(world, target, openPos);
                    var nearPos = FindNearbyStandingTile(world, source, target.Position);
                    ResetActorState(world, source, nearPos);
                    for (var m = 0; m < source.Motives.Length; m++) source.Motives[m] = 65f;
                    for (var m = 0; m < target.Motives.Length; m++) target.Motives[m] = 65f;

                    var prevGuardErrors = world.InteractionGuardErrors.Count;
                    var choices = ReadInteractionChoices(world, source, target);
                    guardErrors += world.InteractionGuardErrors.Count - prevGuardErrors;

                    var batch = new List<ActionQueueSlot>();
                    foreach (var choice in choices)
                    {
                        var label = choice.ActionText ?? $"#{choice.RawDword10}";
                        if (IsTravelOrDestructiveLabel(label)) continue;
                        if (label.Contains("Move In", StringComparison.OrdinalIgnoreCase) ||
                            label.Contains("Propose", StringComparison.OrdinalIgnoreCase) ||
                            label.Contains("Ask to Leave", StringComparison.OrdinalIgnoreCase) ||
                            label.Contains("Say Goodbye", StringComparison.OrdinalIgnoreCase))
                            continue;
                        if (!globalSeenLabels.Add((pairKind, label))) continue;
                        batch.Add(choice);
                    }

                    foreach (var choice in batch)
                    {
                        if (!world.Objects.ContainsKey(source.Id) || !world.Objects.ContainsKey(target.Id)) break;
                        SetSymmetricRelationship(world, source, target, daily, lifetime, relFlags);
                        ResetActorState(world, target, openPos);
                        harness.Actor = source;
                        world[SimulationGlobal.SelectedPersonID] = source.Id;
                        offeredCount++;
                        var trial = ExecuteInteractionTrial(world, harness, catEntry, target, $"social-{tierName.ToLowerInvariant()}", choice, null, Math.Min(options.Ticks, 240));
                        pairTrials.Add(trial);
                        if (options.Limit is { } lim && results.Sum(r => r.Trials.Count) + pairTrials.Count >= lim) break;
                    }
                    if (options.Limit is { } lim2 && results.Sum(r => r.Trials.Count) + pairTrials.Count >= lim2) break;
                }

                results.Add(new ObjectSweepRecord(
                    "Socials", lotType.ToString(), house, targetGuid, catEntry.Name,
                    Placed: true, "social", 0, pairTrials.Count, offeredCount, guardErrors, 0, pairTrials));
            }
        }
    }

    private sealed class PairLabelComparer : IEqualityComparer<(string PairKind, string Label)>
    {
        public bool Equals((string PairKind, string Label) x, (string PairKind, string Label) y) =>
            string.Equals(x.PairKind, y.PairKind, StringComparison.OrdinalIgnoreCase) &&
            string.Equals(x.Label, y.Label, StringComparison.OrdinalIgnoreCase);

        public int GetHashCode((string PairKind, string Label) obj) =>
            HashCode.Combine(
                StringComparer.OrdinalIgnoreCase.GetHashCode(obj.PairKind),
                StringComparer.OrdinalIgnoreCase.GetHashCode(obj.Label));
    }

    private static List<ActionQueueSlot> ReadInteractionChoices(SimulationWorld world, XPerson actor, XObject target)
    {
        if ((actor[PersonData.Gender] & 6) == 0)
            return InteractionMenus.Read(world, actor, target).ToList();

        var root = InteractionMenus.Target(world, target);
        var entries = world.EffectiveInteractions(root)?.Interactions;
        if (entries is null || entries.Count == 0) return [];
        var candidates = entries.Select(entry => new ActionQueueSlot
        {
            Person = actor,
            Owner = root,
            Secondary = root,
            RawDword10 = entry.TtaIndex,
            Threshold = 50,
            ActionTree = entry.ActionTree,
            ActionText = entry.Name,
            Flags = (entry.Flags & 0x100) != 0 ? 1 : 0,
        }).ToArray();
        InteractionTestEvaluator.Evaluate(world, actor, candidates, autonomy: true);
        var passed = candidates.Where(c => (c.Flags & InteractionTestEvaluator.Passed) != 0).ToList();
        var remaining = candidates.Where(c => (c.Flags & InteractionTestEvaluator.Passed) == 0).ToArray();
        if (remaining.Length > 0)
        {
            InteractionTestEvaluator.Evaluate(world, actor, remaining, autonomy: false);
            passed.AddRange(remaining.Where(c => (c.Flags & InteractionTestEvaluator.Passed) != 0));
        }
        return passed;
    }

    private static void SetSymmetricRelationship(SimulationWorld world, XPerson a, XPerson b, short daily, short lifetime, short flags)
    {
        var nidA = a[PersonData.NeighborId];
        var nidB = b[PersonData.NeighborId];
        if (nidA > 0 && nidB > 0)
        {
            ApplyRel(world.Neighbors.GetValueOrDefault(nidA)?.Relationships, nidB, daily, lifetime, flags);
            ApplyRel(world.Neighbors.GetValueOrDefault(nidB)?.Relationships, nidA, daily, lifetime, flags);
        }
        ApplyRel(a.Relationships, b.Id, daily, lifetime, flags);
        ApplyRel(b.Relationships, a.Id, daily, lifetime, flags);
    }

    private static void ApplyRel(RelationshipTable? table, short targetId, short daily, short lifetime, short flags)
    {
        if (table is null || targetId <= 0) return;
        table.Resize(targetId, 4);
        table.Set(targetId, 0, daily);
        table.Set(targetId, 1, flags);
        table.Set(targetId, 2, lifetime);
    }

    private static LotHarness InitializeLotHarness(
        string gameRoot,
        string lotPath,
        string userData,
        short house,
        CatalogLotType lotType,
        ObjectRegistry registry,
        IffFile? baselineNeighborhood,
        byte language,
        string actorMode = "adult")
    {
        var baselineLot = IffFile.Open(lotPath);
        var harness = new LotHarness
        {
            Bootstrap = null!,
            LotPath = lotPath,
            UserData = userData,
            House = house,
            LotType = lotType,
            ActorMode = actorMode,
            BaselineLot = baselineLot,
            BaselineNeighborhood = baselineNeighborhood,
            Registry = registry,
            Actor = null!,
            ActorHomePosition = new ObjectPosition(16 * 16 + 8, 16 * 16 + 8, 1),
            Anchors = [],
            BaselineObjectIds = [],
        };
        ReloadLotHarness(harness, gameRoot, language);
        return harness;
    }

    private static ushort? ResolveTravelingFamilyChunkId(IffFile? neighborhood)
    {
        if (neighborhood is null) return null;
        ushort? fallback = null;
        foreach (var chunk in neighborhood.OfType(ResourceType.Parse("FAMI")))
        {
            var family = Family.Read(neighborhood, chunk);
            if (family.Members.Count == 0) continue;
            if (family.HouseNumber == 5) return chunk.Id;
            if (fallback is null && family.HouseNumber is > 0 and <= 10) fallback = chunk.Id;
        }
        return fallback;
    }

    private static void ReloadLotHarness(LotHarness harness, string gameRoot, byte language)
    {
        XPerson? trackedActor = null;
        var travelingFamilyChunkId = harness.LotType != CatalogLotType.Residential
            ? ResolveTravelingFamilyChunkId(harness.BaselineNeighborhood)
            : null;
        var bootstrap = WorldBootstrap.Load(
            gameRoot,
            harness.LotPath,
            language: language,
            isPaused: () => false,
            lotKey: harness.House,
            autonomyForced: false,
            activeFamilyChunkId: travelingFamilyChunkId,
            userDataPath: harness.UserData,
            preloadedLot: harness.BaselineLot,
            scoreAutonomy: (person, _, _, _, score) => ReferenceEquals(person, trackedActor) ? float.NegativeInfinity : score,
            existingRegistry: harness.Registry,
            preloadedNeighborhood: harness.BaselineNeighborhood);

        var world = bootstrap.World;
        world.AutonomyForced = false;
        if (world.ActivePersonManagerPresent)
        {
            foreach (var key in world.ActivePersonRecordKeys)
            {
                if (key != 0) world.ScopedNeighborPersonRecordId(key);
            }
        }
        if (world.FamilyBudget is FamilyBudget budget)
            budget.AlterFamilyBudget(0, -500000);

        var adults = world.WalkOrder.OfType<XPerson>()
            .Where(p => p[PersonData.PersonType] == 0 && !PersonAgeCategory.IsChild(p[PersonData.PersonAge]) && (p[PersonData.Gender] & 6) == 0)
            .ToList();
        var existingFamilyNum = adults.FirstOrDefault()?[PersonData.FamilyNumber]
            ?? (bootstrap.ActiveFamily is { } af ? unchecked((short)af.FamilyNumber) : (short)0);

        XPerson actor;
        XPerson? partner = null;
        if (harness.ActorMode == "child")
        {
            var children = world.WalkOrder.OfType<XPerson>()
                .Where(p => p[PersonData.PersonType] == 0 && PersonAgeCategory.IsChild(p[PersonData.PersonAge]) && (p[PersonData.Gender] & 6) == 0)
                .ToList();
            actor = children.FirstOrDefault()
                ?? SpawnPersonByMode(world, harness.Registry, bootstrap.ActiveFamily, "child", existingFamilyNum, 0)
                ?? throw new InvalidOperationException($"House{harness.House:D2} child actor spawn failed.");
            partner = adults.FirstOrDefault();
        }
        else if (harness.ActorMode is "dog" or "cat")
        {
            var bit = harness.ActorMode == "dog" ? 2 : 4;
            var pets = world.WalkOrder.OfType<XPerson>().Where(p => (p[PersonData.Gender] & bit) != 0).ToList();
            actor = pets.FirstOrDefault()
                ?? SpawnPersonByMode(world, harness.Registry, bootstrap.ActiveFamily, harness.ActorMode, existingFamilyNum, 0)
                ?? throw new InvalidOperationException($"House{harness.House:D2} {harness.ActorMode} actor spawn failed.");
            if (existingFamilyNum != 0) actor[PersonData.FamilyNumber] = existingFamilyNum;
            partner = adults.FirstOrDefault();
        }
        else if (adults.Count > 0)
        {
            actor = adults[0];
            partner = adults.Count > 1 ? adults[1] : null;
        }
        else
        {
            actor = SpawnPersonByMode(world, harness.Registry, bootstrap.ActiveFamily, "adult", existingFamilyNum, 0)
                ?? world.WalkOrder.OfType<XPerson>().FirstOrDefault()
                ?? throw new InvalidOperationException($"House{harness.House:D2} has no Sim and fallback spawn failed.");
        }
        trackedActor = actor;
        world[SimulationGlobal.SelectedPersonID] = actor.Id;
        if (harness.House == 99)
        {
            world.StoredSlotPersonId = null;
        }
        else if (actor[PersonData.FamilyNumber] != 0)
        {
            world[SimulationGlobal.CurrentFamily] = actor[PersonData.FamilyNumber];
            world.StoredSlotPersonId ??= actor[PersonData.FamilyNumber];
        }
        if (actor.TypeRecord is { Key: not 0 } actorType)
        {
            world.ActivePersonManagerPresent = true;
            if (!world.ActivePersonRecordKeys.Contains(actorType.Key))
                world.ActivePersonRecordKeys.Insert(0, actorType.Key);
            world.ScopedNeighborPersonRecordId(actorType.Key);
        }

        for (var i = 0; i < 15; i++)
        {
            world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
            DismissAllDialogs(world);
        }

        var anchors = DiscoverAndStageAnchors(world, harness.BaselineLot, harness.Registry, language);
        var openFloor = anchors.FirstOrDefault(a => a.Kind == "floor-indoor")
            ?? anchors.FirstOrDefault(a => a.Kind == "floor-outdoor-paved")
            ?? anchors.FirstOrDefault(a => a.Kind == "floor-outdoor-terrain");

        harness.Bootstrap = bootstrap;
        harness.Actor = actor;
        harness.Partner = partner;
        harness.ActorHomePosition = openFloor?.Position ?? actor.Position;
        harness.Anchors = anchors;
        harness.BaselineObjectIds = world.Objects.Keys.ToHashSet();
        world.ClearExecutionTraces();
        world.ThreadErrors.Clear();
        world.InteractionGuardErrors.Clear();
    }

    private static XPerson? SpawnPersonByMode(
        SimulationWorld world,
        ObjectRegistry registry,
        Family? activeFamily,
        string mode,
        short familyNumber,
        int excludeKey)
    {
        if (world.ObjectFactory is null) return null;

        bool MatchesNeighbor(NeighborState candidate)
        {
            if (candidate.TypeRecordKey == 0 || candidate.TypeRecordKey == excludeKey) return false;
            var age = candidate.PersonData[(int)PersonData.PersonAge];
            var gender = candidate.PersonData[(int)PersonData.Gender];
            return mode switch
            {
                "child" => PersonAgeCategory.IsChild(age) && (gender & 6) == 0,
                "dog" => (gender & 2) != 0,
                "cat" => (gender & 4) != 0,
                _ => !PersonAgeCategory.IsChild(age) && (gender & 6) == 0,
            };
        }

        NeighborState? chosenNeighbor = null;
        ObjectEntry? personEntry = null;
        if (activeFamily is not null)
        {
            foreach (var memberGuid in activeFamily.Members)
            {
                var key = unchecked((int)memberGuid);
                var candidate = world.NeighborWalkOrder.FirstOrDefault(n => n is not null && n.TypeRecordKey == key);
                if (candidate is null || !MatchesNeighbor(candidate)) continue;
                var entry = registry.Find(memberGuid);
                if (entry is null) continue;
                chosenNeighbor = candidate;
                personEntry = entry;
                break;
            }
        }
        if (personEntry is null)
        {
            for (var slot = 1; slot <= world.NeighborWalkOrder.Count; slot++)
            {
                var candidate = world.NeighborWalkOrder[slot - 1];
                if (candidate is null || !MatchesNeighbor(candidate)) continue;
                var entry = registry.Find(unchecked((uint)candidate.TypeRecordKey));
                if (entry is null) continue;
                chosenNeighbor = candidate;
                personEntry = entry;
                break;
            }
        }

        if (personEntry is null && mode == "dog")
            personEntry = registry.Find(0x4A70DF92u) ?? registry.Find(0x05DAC986u);
        if (personEntry is null && mode == "cat")
            personEntry = registry.Find(0x7BEA0977u) ?? registry.Find(0x7318C9DFu);
        if (personEntry is null && mode is "dog" or "cat")
        {
            var token = mode == "dog" ? "dog" : "cat";
            personEntry = registry.Entries.FirstOrDefault(e =>
                e.Scan == ObjectScan.People &&
                (e.Chunk.Label.Contains(token, StringComparison.OrdinalIgnoreCase) ||
                 e.File.Source.Contains(token, StringComparison.OrdinalIgnoreCase)));
        }
        personEntry ??= registry.Entries.FirstOrDefault(e => e.Scan == ObjectScan.People && unchecked((int)e.Guid) != excludeKey);
        if (personEntry is null) return null;

        var created = world.ObjectFactory(unchecked((int)personEntry.Guid));
        if (created is not XPerson person) return null;
        person.Position = new ObjectPosition(-16, -16, 1);
        world.Add(person);
        world.InitializeCreatedObject(person);
        if (chosenNeighbor is not null)
        {
            person[PersonData.NeighborId] = chosenNeighbor.Id;
            var fam = familyNumber != 0 ? familyNumber : chosenNeighbor.PersonData[(int)PersonData.FamilyNumber];
            person[PersonData.FamilyNumber] = fam;
            person[PersonData.PersonType] = 0;
            person[PersonData.PersonAge] = mode == "child" ? (short)9 : (chosenNeighbor.PersonData[(int)PersonData.PersonAge] is > 0 and var a ? a : (short)27);
            person[PersonData.Gender] = chosenNeighbor.PersonData[(int)PersonData.Gender];
            if (fam != 0)
            {
                world[SimulationGlobal.CurrentFamily] = fam;
                world.StoredSlotPersonId ??= fam;
            }
        }
        else
        {
            person[PersonData.FamilyNumber] = familyNumber;
            person[PersonData.PersonType] = 0;
            person[PersonData.PersonAge] = mode == "child" ? (short)9 : (short)27;
            person[PersonData.Gender] = mode switch { "dog" => (short)2, "cat" => (short)4, _ => (short)0 };
            var bound = world.BindPersonToNeighborRecord(person);
            if (bound is not null)
            {
                bound.PersonData[(int)PersonData.FamilyNumber] = familyNumber;
                bound.PersonData[(int)PersonData.PersonAge] = person[PersonData.PersonAge];
                bound.PersonData[(int)PersonData.Gender] = person[PersonData.Gender];
            }
        }
        person.SelectionWord5CC = 0;
        person[PersonData.GreetStatus] = 1;
        world[SimulationGlobal.SimlessBuildMode] = 0;
        for (var tx = 14; tx <= 46; tx += 2)
        for (var ty = 14; ty <= 46; ty += 2)
        {
            var pos = new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1);
            if (world.CanPlaceObjectFromEditor(person, pos, out var refObj, out var refSlot))
            {
                world.PlaceCreatedObjectFromEditor(person, pos, refObj, refSlot);
                return person;
            }
        }
        return person;
    }

    private static List<StagingAnchor> DiscoverAndStageAnchors(
        SimulationWorld world,
        IffFile lot,
        ObjectRegistry registry,
        byte language)
    {
        var anchors = new List<StagingAnchor>();
        var walls = LotWalls.Read(lot, 1);
        var roomMap = world.LotRoomMaps.GetValueOrDefault(1);

        var occupiedTiles = new HashSet<(int X, int Y)>();
        foreach (var obj in world.WalkOrder)
        {
            if (obj.Position.Height != 1) continue;
            occupiedTiles.Add((obj.Position.X >> 4, obj.Position.Y >> 4));
        }

        var existingSurfaces = new Dictionary<int, List<ObjectPosition>>();
        foreach (var obj in world.WalkOrder)
        {
            if (obj is XPerson || obj.Position.Height != 1 || obj.FootprintSlots.Count == 0) continue;
            for (var slotIndex = 0; slotIndex < obj.FootprintSlots.Count; slotIndex++)
            {
                if (obj.FootprintSlots[slotIndex].OccupantObjectId != 0) continue;
                var hc = obj.FootprintSlots[slotIndex].HeightCode;
                if (hc <= 1) continue;
                if (!existingSurfaces.TryGetValue(hc, out var list))
                    existingSurfaces[hc] = list = [];
                if (list.Count < 4) list.Add(obj.Position);
            }
        }

        var terrain = world.LotTerrain;
        bool IsFlatTile(int x, int y)
        {
            if (terrain is null) return true;
            var c = terrain.Corners(x, y);
            return c[0] == c[1] && c[0] == c[2] && c[0] == c[3];
        }

        bool IsFlatArea(int x, int y)
        {
            for (var dx = -1; dx <= 1; dx++)
            for (var dy = -1; dy <= 1; dy++)
                if (!IsFlatTile(x + dx, y + dy)) return false;
            return true;
        }

        var outdoorTerrain = new List<(int X, int Y)>();
        var outdoorPaved = new List<(int X, int Y)>();
        var indoorFloors = new List<(int X, int Y)>();
        var wallIndoor = new List<(int X, int Y, byte Dir)>();
        var wallOutdoor = new List<(int X, int Y, byte Dir)>();
        var poolTiles = new List<(int X, int Y)>();

        for (var tx = 6; tx < LotWalls.Size - 6; tx++)
        for (var ty = 6; ty < LotWalls.Size - 6; ty++)
        {
            var pos = new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1);
            if (world.IsPoolTile(pos))
            {
                if (poolTiles.Count < 16) poolTiles.Add((tx, ty));
                continue;
            }
            if (occupiedTiles.Contains((tx, ty))) continue;
            if (!IsFlatTile(tx, ty)) continue;

            var room = roomMap is not null && tx < roomMap.Width && ty < roomMap.Height ? roomMap.RoomAt(tx, ty) : (ushort)0;
            ushort floorWord = 0;
            if (roomMap is not null && roomMap.TryGetFloorGridWord(tx, ty, out var rawFloor) && rawFloor < 65534)
                floorWord = rawFloor;

            var tileWalls = walls[tx, ty];
            var targetWalls = room > 0 ? wallIndoor : wallOutdoor;
            if (tileWalls[0] != 0) targetWalls.Add((tx, ty, 64));
            if (tileWalls[1] != 0) targetWalls.Add((tx, ty, 1));
            if (tx + 1 < LotWalls.Size && walls[tx + 1, ty][0] != 0) targetWalls.Add((tx, ty, 4));
            if (ty + 1 < LotWalls.Size && walls[tx, ty + 1][1] != 0) targetWalls.Add((tx, ty, 16));

            if (tileWalls[0] != 0 || tileWalls[1] != 0) continue;

            var clearRadius = true;
            for (var dx = -1; dx <= 1 && clearRadius; dx++)
            for (var dy = -1; dy <= 1 && clearRadius; dy++)
                if (occupiedTiles.Contains((tx + dx, ty + dy))) clearRadius = false;
            if (!clearRadius || !IsFlatArea(tx, ty)) continue;

            if (room > 0) indoorFloors.Add((tx, ty));
            else if (floorWord != 0) outdoorPaved.Add((tx, ty));
            else outdoorTerrain.Add((tx, ty));
        }

        // Stage dedicated open-floor counter (h4), table+chair (h3), and end table (h2) with 3x3 clearance first.
        var stagedSurfaces = new Dictionary<int, List<ObjectPosition>>();
        var stagingCandidates = indoorFloors.Concat(outdoorPaved).Concat(outdoorTerrain).ToList();
        EnsureSurfaceAnchor(world, registry, language, stagedSurfaces, heightCode: 4, stagingCandidates, occupiedTiles, addChairInFront: false);
        EnsureSurfaceAnchor(world, registry, language, stagedSurfaces, heightCode: 3, stagingCandidates, occupiedTiles, addChairInFront: true);
        EnsureSurfaceAnchor(world, registry, language, stagedSurfaces, heightCode: 2, stagingCandidates, occupiedTiles, addChairInFront: false);

        foreach (var (hc, positions) in stagedSurfaces.OrderBy(p => p.Key))
        {
            foreach (var pos in positions)
                anchors.Add(new StagingAnchor($"surface-h{hc}", pos, hc == 3 ? (byte)16 : (byte)1, hc));
        }
        foreach (var (hc, positions) in existingSurfaces.OrderBy(p => p.Key))
        {
            foreach (var pos in positions)
                anchors.Add(new StagingAnchor($"surface-h{hc}", pos, 1, hc));
        }

        static IEnumerable<T> SpreadSample<T>(List<T> list, int maxCount)
        {
            if (list.Count <= maxCount) return list;
            var step = Math.Max(1, list.Count / maxCount);
            return list.Where((_, i) => i % step == 0).Take(maxCount);
        }

        bool HasClearWallFront(int tx, int ty, byte dirFlag)
        {
            var dir = dirFlag switch { 1 => (short)0, 4 => (short)2, 16 => (short)4, _ => (short)6 };
            var off = LotGeometry.FootprintOffset(dir);
            var fx = tx + (off.X >> 4);
            var fy = ty + (off.Y >> 4);
            if (fx is < 2 or >= LotWalls.Size - 2 || fy is < 2 or >= LotWalls.Size - 2) return false;
            if (occupiedTiles.Contains((fx, fy))) return false;
            if (roomMap is not null && tx < roomMap.Width && ty < roomMap.Height && fx < roomMap.Width && fy < roomMap.Height)
            {
                if (roomMap.RoomAt(tx, ty) != roomMap.RoomAt(fx, fy)) return false;
            }
            return true;
        }

        var clearWallIndoor = wallIndoor.Where(w => HasClearWallFront(w.X, w.Y, w.Dir)).ToList();
        foreach (var (tx, ty, dir) in SpreadSample(clearWallIndoor, 20).Concat(SpreadSample(wallIndoor, 12)))
            anchors.Add(new StagingAnchor("wall-indoor", new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1), dir, 1));
        var clearWallOutdoor = wallOutdoor.Where(w => HasClearWallFront(w.X, w.Y, w.Dir)).ToList();
        foreach (var (tx, ty, dir) in SpreadSample(clearWallOutdoor, 10).Concat(SpreadSample(wallOutdoor, 8)))
            anchors.Add(new StagingAnchor("wall-outdoor", new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1), dir, 1));

        foreach (var (tx, ty) in poolTiles)
        {
            anchors.Add(new StagingAnchor("pool", new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1), 1, 1));
            anchors.Add(new StagingAnchor("pool-edge", new ObjectPosition((tx - 1) * 16 + 8, ty * 16 + 8, 1), 4, 1));
        }

        foreach (var (tx, ty) in SpreadSample(indoorFloors, 20))
            anchors.Add(new StagingAnchor("floor-indoor", new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1), 1, 1));

        foreach (var (tx, ty) in SpreadSample(outdoorPaved, 12))
            anchors.Add(new StagingAnchor("floor-outdoor-paved", new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1), 1, 1));

        foreach (var (tx, ty) in SpreadSample(outdoorTerrain, 20))
            anchors.Add(new StagingAnchor("floor-outdoor-terrain", new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1), 1, 1));

        return anchors;
    }

    private static void EnsureSurfaceAnchor(
        SimulationWorld world,
        ObjectRegistry registry,
        byte language,
        Dictionary<int, List<ObjectPosition>> existingSurfaces,
        int heightCode,
        List<(int X, int Y)> openTiles,
        HashSet<(int X, int Y)> occupiedTiles,
        bool addChairInFront)
    {
        if (existingSurfaces.TryGetValue(heightCode, out var existing) && existing.Count > 0) return;
        if (openTiles.Count == 0) return;

        foreach (var source in registry.ByGuid.Values)
        {
            if (source.Definition[ObjdField.MasterId] != 0) continue;
            if (!ObjectCatalog.TryGetEntry(source, language, CatalogLotType.Residential, out var cat) || cat is null) continue;
            if ((cat.Categories & 0x04) == 0) continue;

            var probe = world.ObjectFactory?.Invoke(unchecked((int)source.Guid));
            if (probe is null) continue;
            probe.Position = new ObjectPosition(-16, -16, 1);
            world.Add(probe);
            world.InitializeCreatedObject(probe);
            var hasHeight = probe.FootprintSlots.Any(s => s.HeightCode == heightCode);
            if (!hasHeight)
            {
                world.Remove(probe.Id);
                continue;
            }

            foreach (var (tx, ty) in openTiles)
            {
                if (occupiedTiles.Contains((tx, ty))) continue;
                var pos = new ObjectPosition(tx * 16 + 8, ty * 16 + 8, 1);
                if (world.CanPlaceObjectFromEditor(probe, pos, out var refObj, out var refSlot))
                {
                    world.PlaceCreatedObjectFromEditor(probe, pos, refObj, refSlot);
                    occupiedTiles.Add((tx, ty));
                    existingSurfaces[heightCode] = [pos];
                    if (addChairInFront)
                    {
                        var chairPos = new ObjectPosition(tx * 16 + 8, (ty + 1) * 16 + 8, 1);
                        TryStageDiningChair(world, registry, language, chairPos, facingDir: 0, occupiedTiles);
                    }
                    return;
                }
            }
            world.Remove(probe.Id);
        }
    }

    private static void TryStageDiningChair(
        SimulationWorld world,
        ObjectRegistry registry,
        byte language,
        ObjectPosition pos,
        short facingDir,
        HashSet<(int X, int Y)> occupiedTiles)
    {
        foreach (var source in registry.ByGuid.Values)
        {
            if (source.Definition[ObjdField.MasterId] != 0) continue;
            if (!ObjectCatalog.TryGetEntry(source, language, CatalogLotType.Residential, out var cat) || cat is null) continue;
            if ((cat.Categories & 0x01) == 0) continue;

            var chair = world.ObjectFactory?.Invoke(unchecked((int)source.Guid));
            if (chair is null) continue;
            chair.Position = new ObjectPosition(-16, -16, 1);
            world.Add(chair);
            world.InitializeCreatedObject(chair);
            if (!SimulationWorld.HasFunction(chair, 0x1a))
            {
                world.Remove(chair.Id);
                continue;
            }
            world.FaceCreatedObject(chair, [chair], facingDir);
            if (world.CanPlaceObjectFromEditor(chair, pos, out var refObj, out var refSlot))
            {
                world.PlaceCreatedObjectFromEditor(chair, pos, refObj, refSlot);
                occupiedTiles.Add((pos.X >> 4, pos.Y >> 4));
                return;
            }
            world.Remove(chair.Id);
        }
    }

    private static ObjectSweepRecord SweepSingleObject(LotHarness harness, ObjectCatalogEntry entry, SweepOptions options)
    {
        var world = harness.Bootstrap.World;
        var packName = entry.Source.Scan.ToString();
        var lotTypeName = harness.LotType.ToString();
        var preTrialIds = world.Objects.Keys.ToHashSet();

        var placed = TryPlaceCatalogObject(world, harness.Anchors, entry, out var item, out var members, out var anchorKind, out var failureCode);
        if (!placed || item is null)
        {
            return new ObjectSweepRecord(
                packName, lotTypeName, harness.House, entry.Guid, entry.Name,
                Placed: false, anchorKind, failureCode,
                TtabCount: 0, OfferedCount: 0, GuardErrorCount: 0, NeverOfferedCount: 0, Trials: []);
        }

        if (SimulationWorld.HasFunction(item, 1))
        {
            for (var w = 0; w < 6; w++)
            {
                world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
                DismissAllDialogs(world);
            }
            if (!world.Objects.ContainsKey(item.Id))
            {
                CleanupTrialObjects(world, harness, item, members, preTrialIds);
                return new ObjectSweepRecord(
                    packName, lotTypeName, harness.House, entry.Guid, entry.Name,
                    Placed: true, anchorKind, 0,
                    TtabCount: 0, OfferedCount: 0, GuardErrorCount: 0, NeverOfferedCount: 0, Trials: []);
            }
        }

        var trials = new List<InteractionTrialRecord>();
        var ttab = world.EffectiveInteractions(item);
        var declaredEntries = ttab?.Interactions ?? [];
        var guardErrorCount = 0;
        var neverOfferedCount = 0;

        try
        {
            var actor = harness.Actor;
            if (options.States)
            {
                SeedProgressionAndInventoryForObject(world, actor, item);
                if (harness.Partner is null && world.Objects.ContainsKey(actor.Id))
                    harness.Partner = SpawnPersonByMode(world, harness.Registry, harness.Bootstrap.ActiveFamily, "adult", actor[PersonData.FamilyNumber], actor.TypeRecord?.Key ?? 0);
                if (harness.Partner is not null && world.Objects.ContainsKey(harness.Partner.Id))
                    SetSymmetricRelationship(world, actor, harness.Partner, 100, 100, 7);
            }
            PositionPartnerNearby(world, harness.Partner, item.Position);

            var offeredByKey = new Dictionary<(int TtaIndex, short Param0), ActionQueueSlot>();
            var guardErrorsByTta = new Dictionary<int, InteractionGuardError>();
            var guardLastFalseByTta = new Dictionary<int, (short TreeId, int Instruction, ushort Opcode, string Operand)>();

            foreach (var drained in new[] { false, true })
            {
                PrepareActorForProbe(world, actor, item.Position, drained);
                world.ClearExecutionTraces();
                var prevGuardErrors = world.InteractionGuardErrors.Count;
                world.CaptureExecutionTrace = true;
                var choices = ReadInteractionChoices(world, actor, item);
                world.CaptureExecutionTrace = false;

                for (var e = prevGuardErrors; e < world.InteractionGuardErrors.Count; e++)
                {
                    var err = world.InteractionGuardErrors[e];
                    guardErrorsByTta.TryAdd(err.InteractionId, err);
                }

                foreach (var choice in choices)
                {
                    var key = (choice.RawDword10, choice.Parameters.Length > 0 ? choice.Parameters[0] : (short)0);
                    offeredByKey.TryAdd(key, choice);
                }

                if (drained)
                {
                    var lastFalse = FindLastFalsePrimitive(world, actor.Id);
                    if (lastFalse is not null)
                    {
                        foreach (var decl in declaredEntries)
                        {
                            if (!offeredByKey.Keys.Any(k => k.TtaIndex == decl.TtaIndex))
                                guardLastFalseByTta.TryAdd(decl.TtaIndex, lastFalse.Value);
                        }
                    }
                }
            }

            foreach (var decl in declaredEntries)
            {
                var declName = decl.Name ?? $"#{decl.TtaIndex}";
                if (guardErrorsByTta.TryGetValue(decl.TtaIndex, out var guardErr))
                {
                    guardErrorCount++;
                    trials.Add(new InteractionTrialRecord(
                        packName, lotTypeName, harness.House, entry.Guid, entry.Name, anchorKind,
                        decl.TtaIndex, declName, decl.ActionTree, decl.GuardTree,
                        InteractionOutcomeKind.GuardError, 0,
                        $"GuardError:{guardErr.Error}:tree=0x{unchecked((ushort)guardErr.GuardTree):X4}",
                        guardErr.Message,
                        0f, 0, 0, 0, 0, 0, 1));
                }
                else if (options.ActorMode == "adult" && !offeredByKey.Keys.Any(k => k.TtaIndex == decl.TtaIndex))
                {
                    var isDebugOrNonAdult = (decl.Flags & 0x80) != 0 || (decl.Flags & 0x40) != 0 ||
                        declName.StartsWith("Debug", StringComparison.OrdinalIgnoreCase);
                    if (isDebugOrNonAdult) continue;
                    neverOfferedCount++;
                    var sig = guardLastFalseByTta.TryGetValue(decl.TtaIndex, out var lf)
                        ? $"NeverOffered:guard=0x{decl.GuardTree:X4}:lastFalse=0x{unchecked((ushort)lf.TreeId):X4}:{lf.Instruction}:{InteractionCensus.PrimitiveName(lf.Opcode)}"
                        : $"NeverOffered:guard=0x{decl.GuardTree:X4}:flags=0x{decl.Flags:X4}";
                    trials.Add(new InteractionTrialRecord(
                        packName, lotTypeName, harness.House, entry.Guid, entry.Name, anchorKind,
                        decl.TtaIndex, declName, decl.ActionTree, decl.GuardTree,
                        InteractionOutcomeKind.NeverOffered, 0, sig,
                        $"TTAB entry {decl.TtaIndex} (\"{declName}\", flags=0x{decl.Flags:X4}) never passed guard under baseline or drained profiles",
                        0f, 0, 0, 0, 0, 0, 0));
                }
            }

            var offeredChoices = offeredByKey.Values
                .GroupBy(c => c.RawDword10)
                .Select(g => g.First())
                .ToList();
            var executedTtaIndices = new HashSet<int>();
            var chainedExecuted = 0;

            foreach (var choice in offeredChoices)
            {
                if (item is null || !world.Objects.ContainsKey(actor.Id)) { harness.NeedsReload = true; break; }
                var label = choice.ActionText ?? $"#{choice.RawDword10}";
                if (!options.IncludeTravel && IsTravelOrDestructiveLabel(label)) continue;
                var decl = declaredEntries.FirstOrDefault(d => d.TtaIndex == choice.RawDword10);
                executedTtaIndices.Add(choice.RawDword10);
                var trial = ExecuteInteractionTrial(world, harness, entry, item, anchorKind, choice, decl, options.Ticks);
                trials.Add(trial);

                if (options.Chained && chainedExecuted < 4 && item is not null &&
                    world.Objects.ContainsKey(item.Id) && world.Objects.ContainsKey(actor.Id))
                {
                    var postChoices = ReadInteractionChoices(world, actor, item)
                        .GroupBy(c => c.RawDword10)
                        .Select(g => g.First())
                        .Where(c => !executedTtaIndices.Contains(c.RawDword10) &&
                            (options.IncludeTravel || !IsTravelOrDestructiveLabel(c.ActionText ?? "")))
                        .ToList();
                    foreach (var followChoice in postChoices)
                    {
                        if (chainedExecuted >= 4 || !world.Objects.ContainsKey(item.Id) || !world.Objects.ContainsKey(actor.Id)) break;
                        executedTtaIndices.Add(followChoice.RawDword10);
                        chainedExecuted++;
                        var followDecl = declaredEntries.FirstOrDefault(d => d.TtaIndex == followChoice.RawDword10);
                        trials.Add(ExecuteInteractionTrial(world, harness, entry, item, $"{anchorKind}:chained", followChoice, followDecl, Math.Min(options.Ticks, 240)));
                    }
                }

                if (harness.NeedsReload || !world.Objects.ContainsKey(actor.Id)) { harness.NeedsReload = true; break; }
                if (item is null || !world.Objects.ContainsKey(item.Id))
                {
                    if (!TryPlaceCatalogObject(world, harness.Anchors, entry, out item, out members, out anchorKind, out _))
                        break;
                }
            }

            if (options.States && item is not null && world.Objects.ContainsKey(item.Id) && world.Objects.ContainsKey(actor.Id) && !harness.NeedsReload)
            {
                RunMaintenanceAndCoopStateProbes(world, harness, entry, item, members, anchorKind, declaredEntries, executedTtaIndices, trials, options);
            }
        }
        finally
        {
            CleanupTrialObjects(world, harness, item, members, preTrialIds);
        }

        return new ObjectSweepRecord(
            packName, lotTypeName, harness.House, entry.Guid, entry.Name,
            Placed: true, anchorKind, 0,
            TtabCount: declaredEntries.Count,
            OfferedCount: trials.Count(t => t.Outcome is not (InteractionOutcomeKind.GuardError or InteractionOutcomeKind.NeverOffered)),
            GuardErrorCount: guardErrorCount,
            NeverOfferedCount: neverOfferedCount,
            Trials: trials);
    }

    private static void SeedProgressionAndInventoryForObject(SimulationWorld world, XPerson actor, XObject item)
    {
        actor[PersonData.CleaningSkill] = 1000;
        actor[PersonData.CookingHouseBrokenSkill] = 1000;
        actor[PersonData.CharismaObedienceSkill] = 1000;
        actor[PersonData.MechanicalTricksSkill] = 1000;
        actor[PersonData.CreativitySkill] = 1000;
        actor[PersonData.BodyFurnitureSkill] = 1000;
        actor[PersonData.LogicSkill] = 1000;
        actor[PersonData.FameScore] = 500;
        actor[PersonData.FameStarPower09] = 10;
        actor[PersonData.FameStarHighWatermark] = 10;

        var nid = actor[PersonData.NeighborId];
        if (nid <= 0) return;
        var inv = world.NeighborInventory(nid);
        void EnsureInv(int invType, int guid, short targetCount)
        {
            var cur = inv.FindIndex(invType, guid, out _);
            if (cur < targetCount)
                inv.Add(invType, guid, checked((short)(targetCount - cur)));
        }
        EnsureInv(7, unchecked((int)0x99E81BECu), 5000);
        EnsureInv(0, unchecked((int)0x378EE399u), 1);
        EnsureInv(0, unchecked((int)0xD9B4146Fu), 1);

        if (item.TypeRecord?.BehaviorScope is BehaviorScope scope)
        {
            var bhavType = ResourceType.Parse("BHAV");
            foreach (var file in new[] { scope.Private, scope.SemiGlobal })
            {
                if (file is null) continue;
                foreach (var chunk in file.OfType(bhavType))
                {
                    Bhav bhav;
                    try { bhav = Bhav.Read(file, chunk); }
                    catch { continue; }
                    foreach (var inst in bhav.Instructions)
                    {
                        if (inst.Opcode != 0x33 || inst.Operand.Length < 8) continue;
                        var op = inst.Operand[0];
                        if (op is not (1 or 3)) continue;
                        var invType = inst.Operand[1];
                        var guid = BinaryPrimitives.ReadInt32LittleEndian(inst.Operand.AsSpan(4, 4));
                        if (guid != 0) EnsureInv(invType, guid, 5);
                    }
                }
            }
        }
        inv.MarkChanged();
    }

    private static void RunMaintenanceAndCoopStateProbes(
        SimulationWorld world,
        LotHarness harness,
        ObjectCatalogEntry entry,
        XObject item,
        IReadOnlyList<XObject>? members,
        string anchorKind,
        IReadOnlyList<Interaction> declaredEntries,
        HashSet<int> executedTtaIndices,
        List<InteractionTrialRecord> trials,
        SweepOptions options)
    {
        var actor = harness.Actor;
        var allParts = members is { Count: > 0 } ? members : [item];
        var unexecutedNames = declaredEntries
            .Where(d => !executedTtaIndices.Contains(d.TtaIndex))
            .Select(d => d.Name ?? "")
            .ToList();

        // Pass B: maintenance states (broken, dirty, clogged, un-flushed, wilted/dead plant).
        var wantsMaintenance = unexecutedNames.Any(n =>
            n.Contains("Repair", StringComparison.OrdinalIgnoreCase) ||
            n.Contains("Clean", StringComparison.OrdinalIgnoreCase) ||
            n.Contains("Flush", StringComparison.OrdinalIgnoreCase) ||
            n.Contains("Unclog", StringComparison.OrdinalIgnoreCase) ||
            n.Contains("Water", StringComparison.OrdinalIgnoreCase) ||
            n.Contains("Throw Away", StringComparison.OrdinalIgnoreCase) ||
            n.Contains("Empty", StringComparison.OrdinalIgnoreCase));

        if (wantsMaintenance)
        {
            foreach (var part in allParts)
            {
                part[ObjectData.RepairState] = 1;
                part[ObjectData.DirtyLevel] = 900;
            }
            if (unexecutedNames.Any(n => n.Contains("Flush", StringComparison.OrdinalIgnoreCase)) && item.Attributes.Length > 1)
                item.Attributes[1] = 1;
            if (unexecutedNames.Any(n => n.Contains("Unclog", StringComparison.OrdinalIgnoreCase)) && item.Attributes.Length > 2)
                item.Attributes[2] = 1;
            if (unexecutedNames.Any(n => n.Contains("Water", StringComparison.OrdinalIgnoreCase)) && item.Attributes.Length > 1)
                item.Attributes[1] = 10;

            PrepareActorForProbe(world, actor, item.Position, drained: false);
            var maintChoices = ReadInteractionChoices(world, actor, item)
                .GroupBy(c => c.RawDword10)
                .Select(g => g.First())
                .Where(c => !executedTtaIndices.Contains(c.RawDword10) &&
                    (options.IncludeTravel || !IsTravelOrDestructiveLabel(c.ActionText ?? "")))
                .Take(4)
                .ToList();
            foreach (var choice in maintChoices)
            {
                if (!world.Objects.ContainsKey(item.Id) || !world.Objects.ContainsKey(actor.Id)) break;
                executedTtaIndices.Add(choice.RawDword10);
                var decl = declaredEntries.FirstOrDefault(d => d.TtaIndex == choice.RawDword10);
                trials.Add(ExecuteInteractionTrial(world, harness, entry, item, $"{anchorKind}:maint", choice, decl, Math.Min(options.Ticks, 240)));
            }

            if (unexecutedNames.Any(n => n.Contains("Throw Away", StringComparison.OrdinalIgnoreCase)) &&
                world.Objects.ContainsKey(item.Id) && world.Objects.ContainsKey(actor.Id) && item.Attributes.Length > 0)
            {
                item.Attributes[0] = 2;
                PrepareActorForProbe(world, actor, item.Position, drained: false);
                var throwChoices = ReadInteractionChoices(world, actor, item)
                    .GroupBy(c => c.RawDword10)
                    .Select(g => g.First())
                    .Where(c => !executedTtaIndices.Contains(c.RawDword10))
                    .Take(2)
                    .ToList();
                foreach (var choice in throwChoices)
                {
                    if (!world.Objects.ContainsKey(item.Id) || !world.Objects.ContainsKey(actor.Id)) break;
                    executedTtaIndices.Add(choice.RawDword10);
                    var decl = declaredEntries.FirstOrDefault(d => d.TtaIndex == choice.RawDword10);
                    trials.Add(ExecuteInteractionTrial(world, harness, entry, item, $"{anchorKind}:maint", choice, decl, Math.Min(options.Ticks, 240)));
                }
            }
        }

        // Pass C: 2-Sim co-op states (Cuddle / Join / Play With / Vibrate).
        var partner = harness.Partner;
        var wantsCoop = partner is not null && world.Objects.ContainsKey(partner.Id) &&
            world.Objects.ContainsKey(item.Id) && world.Objects.ContainsKey(actor.Id) &&
            unexecutedNames.Any(n =>
                n.Contains("Cuddle", StringComparison.OrdinalIgnoreCase) ||
                n.Contains("Join", StringComparison.OrdinalIgnoreCase) ||
                n.Contains("Play With", StringComparison.OrdinalIgnoreCase) ||
                n.Contains("Vibrate", StringComparison.OrdinalIgnoreCase) ||
                n.Contains("Watch", StringComparison.OrdinalIgnoreCase));

        if (wantsCoop && partner is not null)
        {
            foreach (var part in allParts)
            {
                part[ObjectData.RepairState] = 0;
                part[ObjectData.DirtyLevel] = 0;
            }
            PrepareActorForProbe(world, partner, item.Position, drained: false);
            var partnerChoices = ReadInteractionChoices(world, partner, item);
            var seatOrStart = partnerChoices.FirstOrDefault(c =>
                (c.ActionText ?? "").Contains("Sit", StringComparison.OrdinalIgnoreCase) ||
                (c.ActionText ?? "").Contains("Play", StringComparison.OrdinalIgnoreCase) ||
                (c.ActionText ?? "").Contains("Get In", StringComparison.OrdinalIgnoreCase) ||
                (c.ActionText ?? "").Contains("Relax", StringComparison.OrdinalIgnoreCase) ||
                (c.ActionText ?? "").Contains("Use", StringComparison.OrdinalIgnoreCase))
                ?? partnerChoices.FirstOrDefault(c => !IsTravelOrDestructiveLabel(c.ActionText ?? ""));

            if (seatOrStart is not null && world.EnqueueInteractionAction(partner, seatOrStart))
            {
                for (var t = 0; t < 90; t++)
                {
                    world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
                    DismissAllDialogs(world);
                    if (partner[PersonData.Sitting] != 0) break;
                }
                if (world.Objects.ContainsKey(item.Id) && world.Objects.ContainsKey(actor.Id))
                {
                    // For Cuddle, seat actor on the same sofa first if Sit is available.
                    var needsActorSeated = unexecutedNames.Any(n => n.Contains("Cuddle", StringComparison.OrdinalIgnoreCase));
                    if (needsActorSeated)
                    {
                        PrepareActorForProbe(world, actor, item.Position, drained: false);
                        var actorSit = ReadInteractionChoices(world, actor, item)
                            .FirstOrDefault(c => (c.ActionText ?? "").Equals("Sit", StringComparison.OrdinalIgnoreCase));
                        if (actorSit is not null && world.EnqueueInteractionAction(actor, actorSit))
                        {
                            for (var t = 0; t < 90; t++)
                            {
                                world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
                                DismissAllDialogs(world);
                                if (actor[PersonData.Sitting] != 0) break;
                            }
                        }
                    }

                    if (world.Objects.ContainsKey(item.Id) && world.Objects.ContainsKey(actor.Id))
                    {
                        var coopChoices = ReadInteractionChoices(world, actor, item)
                            .GroupBy(c => c.RawDword10)
                            .Select(g => g.First())
                            .Where(c => !executedTtaIndices.Contains(c.RawDword10) &&
                                (options.IncludeTravel || !IsTravelOrDestructiveLabel(c.ActionText ?? "")))
                            .Take(2)
                            .ToList();
                        foreach (var choice in coopChoices)
                        {
                            if (!world.Objects.ContainsKey(item.Id) || !world.Objects.ContainsKey(actor.Id)) break;
                            executedTtaIndices.Add(choice.RawDword10);
                            var decl = declaredEntries.FirstOrDefault(d => d.TtaIndex == choice.RawDword10);
                            // Do not reset actor off the sofa when Cuddle requires actor already seated.
                            trials.Add(ExecuteInteractionTrial(world, harness, entry, item, $"{anchorKind}:coop", choice, decl, Math.Min(options.Ticks, 240), preserveActorPosition: needsActorSeated && actor[PersonData.Sitting] != 0));
                        }
                    }
                }
            }
        }
    }

    private static InteractionTrialRecord ExecuteInteractionTrial(
        SimulationWorld world,
        LotHarness harness,
        ObjectCatalogEntry entry,
        XObject target,
        string anchorKind,
        ActionQueueSlot choice,
        Interaction? decl,
        int maxTicks,
        bool preserveActorPosition = false)
    {
        var actor = harness.Actor;
        var label = choice.ActionText ?? decl?.Name ?? $"#{choice.RawDword10}";
        var actionTree = decl?.ActionTree ?? choice.ActionTree;
        var guardTree = decl?.GuardTree ?? 0;

        if (!preserveActorPosition)
            ResetActorState(world, actor, FindNearbyStandingTile(world, actor, target.Position));
        DismissAllDialogs(world);
        world.ClearExecutionTraces();

        var motivesBefore = actor.Motives.ToArray();
        var attrsBefore = target.Attributes.ToArray();
        var objectsBefore = world.Objects.Count;
        var prevThreadErrors = world.ThreadErrors.Count;
        var prevGuardErrors = world.InteractionGuardErrors.Count;

        world.CaptureExecutionTrace = true;
        var dialogsTriggered = 0;
        var animationsPlayed = 0;
        var ticksRun = 0;
        var actionEverStarted = false;
        var lastStackKey = (TreeId: (short)0, Inst: -1);
        var sameStackStreak = 0;
        string? lastAnimationName = null;

        Exception? uncaughtException = null;
        try
        {
            var freshChoice = ReadInteractionChoices(world, actor, target)
                .FirstOrDefault(c => c.RawDword10 == choice.RawDword10 &&
                    (c.Parameters.Length == 0 || choice.Parameters.Length == 0 || c.Parameters[0] == choice.Parameters[0]))
                ?? choice.Copy();

            if (world.IsImmediateMenuInteraction(freshChoice))
            {
                world.RunImmediateMenuInteraction(actor, freshChoice);
                actionEverStarted = true;
                ticksRun = 1;
                dialogsTriggered += DismissAllDialogs(world);
            }
            else if (world.EnqueueInteractionAction(actor, freshChoice))
            {
                for (var tick = 1; tick <= maxTicks; tick++)
                {
                    ticksRun = tick;
                    world.AdvanceSimulationTick(new SimulationClockControl(1, 1, 1), 0, world.Clock.Ticks);
                    dialogsTriggered += DismissAllDialogs(world);

                    if (actor.CurrentActionRecord?.Owner is not null)
                        actionEverStarted = true;

                    if (actor.AnimationPlayback is { Clip.Name: { } clipName, RouteDriven: false } &&
                        clipName != lastAnimationName &&
                        !IsRouteFailOrIdleClip(clipName))
                    {
                        lastAnimationName = clipName;
                        animationsPlayed++;
                    }

                    if (HasActorOrTargetThreadError(world, prevThreadErrors, actor.Id, target.Id))
                        break;

                    if (world.SavedExecutionStacks.TryGetValue(actor.Id, out var stack) && stack.Top is { } top)
                    {
                        var key = (top.TreeId, top.Instruction);
                        if (key == lastStackKey && actor.NativeRoute is null) sameStackStreak++;
                        else { lastStackKey = key; sameStackStreak = 0; }
                    }
                    else
                    {
                        sameStackStreak = 0;
                    }

                    var queueEmpty = actor.ActionQueueCurrent >= actor.ActionQueueEnd;
                    if (actionEverStarted && actor.CurrentActionRecord?.Owner is null && queueEmpty && tick >= 10)
                        break;
                    if (!actionEverStarted && queueEmpty && tick >= 30)
                        break;
                }
            }
        }
        catch (Exception ex) when (ex is not OutOfMemoryException)
        {
            uncaughtException = ex;
            harness.NeedsReload = true;
        }
        finally
        {
            world.CaptureExecutionTrace = false;
        }

        if (uncaughtException is not null)
        {
            var topMethod = uncaughtException.TargetSite is { DeclaringType: { } dt } ? $"{dt.Name}.{uncaughtException.TargetSite.Name}" : uncaughtException.GetType().Name;
            var loc = uncaughtException.Data["executionLocation"]?.ToString() ?? "";
            var sig = $"UncaughtException:{uncaughtException.GetType().Name}:{topMethod}:{uncaughtException.Message.Split('(')[0].Trim()}";
            return new InteractionTrialRecord(
                entry.Source.Scan.ToString(), harness.LotType.ToString(), harness.House,
                entry.Guid, entry.Name, anchorKind,
                choice.RawDword10, label, actionTree, guardTree,
                InteractionOutcomeKind.ThreadError, ticksRun, sig,
                $"{uncaughtException.GetType().Name}: {uncaughtException.Message} | {loc}",
                0f, dialogsTriggered, animationsPlayed, world.MissingAnimationTrace.Count, 0, 1, 0);
        }

        // Exclude Room (13) and Mood/overall slots from motive delta so room-score snap does not mask bailouts.
        var motiveDeltaAbs = 0f;
        for (var i = 0; i < Math.Min(motivesBefore.Length, actor.Motives.Length); i++)
        {
            if (i is 0 or 1 or 2 or 3 or 4 or 10 or 11 or 12 or 13) continue;
            motiveDeltaAbs += Math.Abs(actor.Motives[i] - motivesBefore[i]);
        }

        var attrsChanged = false;
        for (var i = 0; i < Math.Min(attrsBefore.Length, target.Attributes.Length); i++)
            if (attrsBefore[i] != target.Attributes[i]) { attrsChanged = true; break; }

        var newThreadErrors = world.ThreadErrors.Count - prevThreadErrors;
        var newGuardErrors = world.InteractionGuardErrors.Count - prevGuardErrors;
        var missingAnims = world.MissingAnimationTrace.Count;
        var routeFailures = world.PrimitiveResultTrace.Count(r =>
            r.ObjectId == actor.Id && r.Opcode is 0x1b or 0x2d && r.Result == PrimitiveResult.False);
        var routeSuccesses = world.PrimitiveResultTrace.Count(r =>
            r.ObjectId == actor.Id && r.Opcode is 0x1b or 0x2d && r.Result == PrimitiveResult.True);

        var (outcome, signature, detail) = ClassifyOutcome(
            world, actor.Id, target.Id, actionTree, anchorKind, ticksRun, maxTicks, sameStackStreak,
            motiveDeltaAbs, attrsChanged, world.Objects.Count != objectsBefore,
            dialogsTriggered, animationsPlayed, missingAnims, routeFailures, routeSuccesses,
            newThreadErrors, prevThreadErrors, newGuardErrors, prevGuardErrors);

        return new InteractionTrialRecord(
            entry.Source.Scan.ToString(), harness.LotType.ToString(), harness.House,
            entry.Guid, entry.Name, anchorKind,
            choice.RawDword10, label, actionTree, guardTree,
            outcome, ticksRun, signature, detail,
            motiveDeltaAbs, dialogsTriggered, animationsPlayed, missingAnims, routeFailures,
            newThreadErrors, newGuardErrors);
    }

    private static bool IsRouteFailOrIdleClip(string clipName) =>
        clipName.Contains("route", StringComparison.OrdinalIgnoreCase) ||
        clipName.Contains("cantgo", StringComparison.OrdinalIgnoreCase) ||
        clipName.Contains("shrug", StringComparison.OrdinalIgnoreCase) ||
        clipName.Contains("wave", StringComparison.OrdinalIgnoreCase) ||
        clipName.Contains("walk", StringComparison.OrdinalIgnoreCase) ||
        clipName.Contains("stand", StringComparison.OrdinalIgnoreCase);

    private static bool HasActorOrTargetThreadError(SimulationWorld world, int prevCount, short actorId, short targetId)
    {
        for (var i = prevCount; i < world.ThreadErrors.Count; i++)
            if (world.ThreadErrors[i].ObjectId == actorId || world.ThreadErrors[i].ObjectId == targetId)
                return true;
        return false;
    }

    private static (InteractionOutcomeKind Outcome, string Signature, string Detail) ClassifyOutcome(
        SimulationWorld world,
        short actorId,
        short targetId,
        ushort actionTree,
        string anchorKind,
        int ticksRun,
        int maxTicks,
        int sameStackStreak,
        float motiveDeltaAbs,
        bool attrsChanged,
        bool objectCountChanged,
        int dialogsTriggered,
        int animationsPlayed,
        int missingAnims,
        int routeFailures,
        int routeSuccesses,
        int newThreadErrors,
        int prevThreadErrors,
        int newGuardErrors,
        int prevGuardErrors)
    {
        if (newThreadErrors > 0)
        {
            ThreadError? directErr = null;
            for (var i = prevThreadErrors; i < world.ThreadErrors.Count; i++)
            {
                if (world.ThreadErrors[i].ObjectId == actorId || world.ThreadErrors[i].ObjectId == targetId)
                {
                    directErr = world.ThreadErrors[i];
                    break;
                }
            }
            var err = directErr ?? world.ThreadErrors[prevThreadErrors];
            var isDirect = directErr is not null;
            var errOwner = world.ObjectById(err.ObjectId);
            var ownerTag = isDirect
                ? "Direct"
                : $"BgObj:{errOwner?.TypeRecord?.Name ?? $"id{err.ObjectId}"}";
            var top = err.Frames is { Length: > 0 } ? err.Frames[^1] : (ThreadFrameError?)null;
            var errPrefix = err.Message.Split('(')[0].Trim();
            var sig = top is { } f
                ? $"ThreadError({ownerTag}):{errPrefix}:{f.ResourceScope ?? "?"}:0x{unchecked((ushort)f.Tree):X4}:{f.Instruction}:{(f.Opcode is { } op ? InteractionCensus.PrimitiveName(op) : "?")}:{f.Operand}"
                : $"ThreadError({ownerTag}):{errPrefix}";
            return (InteractionOutcomeKind.ThreadError, sig, $"[obj={err.ObjectId} ({errOwner?.TypeRecord?.Name ?? "?"})] {err.Message}");
        }

        if (newGuardErrors > 0)
        {
            var err = world.InteractionGuardErrors[prevGuardErrors];
            return (InteractionOutcomeKind.GuardError, $"GuardError:{err.Error}:0x{unchecked((ushort)err.GuardTree):X4}", err.Message);
        }

        if (missingAnims > 0)
        {
            var first = world.MissingAnimationTrace[0];
            var sig = $"MissingAnim:src={first.Source}:tbl={first.TableId ?? 0}:id={first.AnimationId}:guid=0x{unchecked((uint)(first.TargetGuid ?? 0)):X8}";
            return (InteractionOutcomeKind.MissingAnimation, sig,
                $"Missing animation clip (source={first.Source}, table={first.TableId}, id={first.AnimationId}, mode={first.Mode}, tree=0x{unchecked((ushort)first.Tree):X4}:{first.Instruction})");
        }

        var hadMeaningfulSideEffect = motiveDeltaAbs >= 2.0f || attrsChanged || objectCountChanged ||
            dialogsTriggered > 0 || animationsPlayed > 0;

        if (routeFailures > 0 && routeSuccesses == 0 && !attrsChanged && !objectCountChanged && animationsPlayed == 0)
        {
            var lastRoute = world.PrimitiveResultTrace.Last(r => r.ObjectId == actorId && r.Opcode is 0x1b or 0x2d && r.Result == PrimitiveResult.False);
            var reason = string.IsNullOrEmpty(world.LastRouteCandidateFailureReason)
                ? (world.NativeRouteTrace.LastOrDefault(t => t.ActorId == actorId && t.Failure is not null).Failure ?? "route-false")
                : world.LastRouteCandidateFailureReason;
            var shortReason = reason.Length > 80 ? reason[..80] : reason;
            var sig = $"RouteFailed:{anchorKind}:{InteractionCensus.PrimitiveName(lastRoute.Opcode)}:0x{unchecked((ushort)lastRoute.Tree):X4}:{lastRoute.Instruction}:{shortReason}";
            return (InteractionOutcomeKind.RouteFailed, sig, reason);
        }

        if (ticksRun < 30 && !hadMeaningfulSideEffect)
        {
            var lastFalse = FindLastFalsePrimitive(world, actorId);
            if (lastFalse is { } lf)
            {
                var subMode = TryDescribeOperandHex(lf.Opcode, lf.Operand);
                var sig = $"EarlyBailout:0x{unchecked((ushort)lf.TreeId):X4}:{lf.Instruction}:{InteractionCensus.PrimitiveName(lf.Opcode)}:{subMode}";
                return (InteractionOutcomeKind.EarlyBailout, sig,
                    $"Exited in {ticksRun} ticks with no side effects after {InteractionCensus.PrimitiveName(lf.Opcode)} ({subMode}) returned False in tree 0x{unchecked((ushort)lf.TreeId):X4}:{lf.Instruction}");
            }
        }

        if (ticksRun >= maxTicks && sameStackStreak >= 200 && !hadMeaningfulSideEffect)
        {
            var top = world.SavedExecutionStacks.TryGetValue(actorId, out var stack) ? stack.Top : null;
            var sig = top is not null
                ? $"Stalled:0x{unchecked((ushort)top.TreeId):X4}:{top.Instruction}"
                : $"Stalled:action=0x{actionTree:X4}";
            return (InteractionOutcomeKind.Stalled, sig,
                $"Pinned at same instruction for {sameStackStreak} ticks with no motive/state/animation progress");
        }

        return (InteractionOutcomeKind.Succeeded, "OK", $"ticks={ticksRun}, anims={animationsPlayed}, motiveDelta={motiveDeltaAbs:F1}, dialogs={dialogsTriggered}");
    }

    private static (short TreeId, int Instruction, ushort Opcode, string Operand)? FindLastFalsePrimitive(SimulationWorld world, short actorId)
    {
        for (var i = world.PrimitiveResultTrace.Count - 1; i >= 0; i--)
        {
            var r = world.PrimitiveResultTrace[i];
            if (r.ObjectId != actorId || r.Result != PrimitiveResult.False) continue;
            var operand = string.Empty;
            for (var j = world.ExecutionTrace.Count - 1; j >= 0; j--)
            {
                var e = world.ExecutionTrace[j];
                if (e.ObjectId == actorId && e.Tree == r.Tree && e.Instruction == r.Instruction && e.Opcode == r.Opcode)
                {
                    operand = e.Operand;
                    break;
                }
            }
            return (r.Tree, r.Instruction, r.Opcode, operand);
        }
        return null;
    }

    private static string TryDescribeOperandHex(ushort opcode, string operandHex)
    {
        if (string.IsNullOrEmpty(operandHex)) return "none";
        try
        {
            var bytes = Convert.FromHexString(operandHex);
            return InteractionCensus.DescribeSubMode(opcode, bytes);
        }
        catch (FormatException)
        {
            return operandHex;
        }
    }

    private static bool TryPlaceCatalogObject(
        SimulationWorld world,
        List<StagingAnchor> anchors,
        ObjectCatalogEntry entry,
        out XObject? item,
        out IReadOnlyList<XObject>? members,
        out string anchorKind,
        out int failureCode)
    {
        item = null;
        members = null;
        anchorKind = "none";
        failureCode = 0;

        using var savedTypes = world.BeginSavedObjectTypeRegistrationScope();
        try
        {
            var group = world.ObjectGroupFactory?.Invoke(unchecked((int)entry.Guid));
            if (group is { Count: > 0 })
            {
                item = group[0];
                members = group;
            }
            else if (entry.Source.Definition[ObjdField.MasterId] == 0 && world.ObjectFactory is not null)
            {
                item = world.ObjectFactory(unchecked((int)entry.Guid));
                if (item is null) return false;
                item.Position = new ObjectPosition(-16, -16, 1);
                world.Add(item);
                world.InitializeCreatedObject(item);
                members = [item];
            }
            else
            {
                return false;
            }

            var allowedHeights = unchecked((ushort)item[ObjectData.AllowedHeightFlags]);
            var wallFlags = unchecked((ushort)item[ObjectData.WallPlacementFlags]);
            var orderedAnchors = PrioritizeAnchors(anchors, allowedHeights, wallFlags).ToList();
            byte[] allDirections = [1, 4, 16, 64];
            var roomMap = world.LotRoomMaps.GetValueOrDefault(1);

            bool HasGoodTileApproach(int tx, int ty, short dir, StagingAnchor anchor, HashSet<short> memberIds)
            {
                var off = LotGeometry.FootprintOffset(dir);
                var fx = tx + (off.X >> 4);
                var fy = ty + (off.Y >> 4);
                if (fx is < 2 or >= LotWalls.Size - 2 || fy is < 2 or >= LotWalls.Size - 2) return false;
                if (roomMap is not null && tx < roomMap.Width && ty < roomMap.Height && fx < roomMap.Width && fy < roomMap.Height)
                {
                    if (roomMap.RoomAt(tx, ty) != roomMap.RoomAt(fx, fy)) return false;
                }
                var tv = world.TileValueAt(fx, fy, 1);
                if (tv <= 0) return true;
                var occupant = world.ObjectTableEntry(unchecked((short)tv));
                if (occupant is null || occupant is XPerson || memberIds.Contains(occupant.Id)) return true;
                return anchor.HeightCode == 3 && SimulationWorld.HasFunction(occupant, 0x1a);
            }

            var memberIdSet = members.Select(m => m.Id).ToHashSet();

            foreach (var requireApproach in new[] { true, false })
            {
                foreach (var anchor in orderedAnchors)
                {
                    var dirs = allDirections.OrderBy(d => d == anchor.Direction ? 0 : 1);
                    foreach (var dirFlag in dirs)
                    {
                        var dir = dirFlag switch { 1 => (short)0, 4 => (short)2, 16 => (short)4, _ => (short)6 };
                        if (requireApproach && !anchor.Kind.StartsWith("pool", StringComparison.Ordinal) &&
                            !HasGoodTileApproach(anchor.Position.X >> 4, anchor.Position.Y >> 4, dir, anchor, memberIdSet))
                            continue;
                        world.FaceCreatedObject(item, members, dir);
                        if (world.CanPlaceObjectFromEditor(item, anchor.Position, out var refObj, out var refSlot))
                        {
                            world.PlaceCreatedObjectFromEditor(item, anchor.Position, refObj, refSlot);
                            if (requireApproach && !anchor.Kind.StartsWith("pool", StringComparison.Ordinal) && members.Count > 1)
                            {
                                var allClear = true;
                                foreach (var m in members)
                                {
                                    if (!HasGoodTileApproach(m.Position.X >> 4, m.Position.Y >> 4, dir, anchor, memberIdSet))
                                    {
                                        allClear = false;
                                        break;
                                    }
                                }
                                if (!allClear)
                                {
                                    foreach (var m in members) world.BeginObjectRemoval(m, 1);
                                    continue;
                                }
                            }
                            savedTypes.Commit();
                            anchorKind = anchor.Kind;
                            return true;
                        }
                        failureCode = world.LastPlacementFailureCode;
                    }
                }
            }

            world.RemoveCreatedObjectGroup(item);
            item = null;
            members = null;
            return false;
        }
        catch
        {
            if (item is not null)
            {
                try { world.RemoveCreatedObjectGroup(item); } catch { }
            }
            item = null;
            members = null;
            return false;
        }
    }

    private static IEnumerable<StagingAnchor> PrioritizeAnchors(List<StagingAnchor> anchors, ushort allowedHeights, ushort wallFlags)
    {
        var needsSurface = (allowedHeights & 1) == 0 && (allowedHeights & 0xfe) != 0;
        var wallRequired = (wallFlags & 0x0f) != 0;

        int Rank(StagingAnchor a)
        {
            if (needsSurface)
            {
                if (a.HeightCode > 1 && (allowedHeights & (1 << ((a.HeightCode - 1) & 0x1f))) != 0) return 0;
                if (a.Kind.StartsWith("surface", StringComparison.Ordinal)) return 1;
                if (a.Kind.StartsWith("wall", StringComparison.Ordinal)) return 2;
                return 3;
            }
            if (wallRequired)
            {
                if (a.Kind == "wall-indoor") return 0;
                if (a.Kind == "wall-outdoor") return 1;
                if (a.Kind.StartsWith("floor", StringComparison.Ordinal)) return 2;
                return 4;
            }
            if (a.Kind == "floor-indoor") return 0;
            if (a.Kind == "floor-outdoor-paved") return 1;
            if (a.Kind == "floor-outdoor-terrain") return 2;
            if (a.Kind == "wall-indoor") return 3;
            if (a.Kind == "wall-outdoor") return 4;
            if (a.Kind.StartsWith("pool", StringComparison.Ordinal)) return 5;
            return 6;
        }

        return anchors.OrderBy(Rank);
    }

    private static void PrepareActorForProbe(SimulationWorld world, XPerson actor, ObjectPosition targetPos, bool drained)
    {
        ResetActorState(world, actor, FindNearbyStandingTile(world, actor, targetPos));
        actor.SelectionWord5CC = 0;
        actor[PersonData.GreetStatus] = 1;
        var level = drained ? -35f : 50f;
        for (var i = 0; i < actor.Motives.Length; i++)
            actor.Motives[i] = level;
    }

    private static void ResetActorState(SimulationWorld world, XPerson actor, ObjectPosition position)
    {
        world.CancelDirectPositionRoutes(actor);
        actor.ActionQueueCurrent = 0;
        actor.ActionQueueEnd = 0;
        for (var i = 0; i < actor.ActionQueue.Length; i++)
            actor.ActionQueue[i] = ActionQueueSlot.EmptyRecord();
        actor.PendingActionRequests.Clear();
        world.ApplyStartedInteractionAction(actor, ActionQueueSlot.EmptyRecord());
        actor.InteractingObjects.Clear();
        actor.SavedPersonObjectReferences.Clear();
        world.ResetPersonState(actor);
        if (actor.Position != position && world.CanPlaceObjectFromEditor(actor, position, out var refObj, out var refSlot))
        {
            world.BeginObjectRemoval(actor, 1);
            world.PlaceCreatedObjectFromEditor(actor, position, refObj, refSlot);
        }
    }

    private static ObjectPosition FindNearbyStandingTile(SimulationWorld world, XPerson actor, ObjectPosition targetPos)
    {
        var baseX = targetPos.X >> 4;
        var baseY = targetPos.Y >> 4;
        for (var r = 1; r <= 4; r++)
        for (var dx = -r; dx <= r; dx++)
        for (var dy = -r; dy <= r; dy++)
        {
            if (Math.Abs(dx) != r && Math.Abs(dy) != r) continue;
            var tx = baseX + dx;
            var ty = baseY + dy;
            if (tx is < 2 or >= LotWalls.Size - 2 || ty is < 2 or >= LotWalls.Size - 2) continue;
            var pos = new ObjectPosition(tx * 16 + 8, ty * 16 + 8, targetPos.Height);
            if (!world.IsPoolTile(pos) && world.CanPlaceObjectFromEditor(actor, pos, out _, out _))
                return pos;
        }
        return actor.Position;
    }

    private static void PositionPartnerNearby(SimulationWorld world, XPerson? partner, ObjectPosition targetPos)
    {
        if (partner is null || !world.Objects.ContainsKey(partner.Id)) return;
        ResetActorState(world, partner, FindNearbyStandingTile(world, partner, targetPos));
    }

    private static void CleanupTrialObjects(SimulationWorld world, LotHarness harness, XObject? item, IReadOnlyList<XObject>? members, HashSet<short> preTrialIds)
    {
        DismissAllDialogs(world);
        if (world.Objects.ContainsKey(harness.Actor.Id))
        {
            try { ResetActorState(world, harness.Actor, harness.ActorHomePosition); }
            catch { harness.NeedsReload = true; }
        }

        var itemIds = new HashSet<short>();
        if (item is not null) itemIds.Add(item.Id);
        if (members is not null)
        {
            foreach (var m in members) itemIds.Add(m.Id);
        }

        if (item is not null && world.Objects.ContainsKey(item.Id))
        {
            try { world.RemoveCreatedObjectGroup(item); } catch { }
        }
        if (members is not null)
        {
            foreach (var m in members)
                if (world.Objects.ContainsKey(m.Id))
                    try { world.Remove(m.Id); } catch { }
        }

        foreach (var id in world.Objects.Keys.ToArray())
        {
            if (preTrialIds.Contains(id) || harness.BaselineObjectIds.Contains(id)) continue;
            var obj = world.ObjectById(id);
            if (obj is null || obj is XPerson) continue;
            var parentKey = obj[ObjectData.ParentId] > 0 ? obj[ObjectData.ParentId] : obj[ObjectData.ContainerId];
            if (parentKey > 0)
            {
                var parent = obj.ObjectTableEntry(parentKey) ?? world.ObjectTableEntry(parentKey) ?? world.ObjectById(parentKey);
                if (parent is XPerson otherPerson && otherPerson.Id != harness.Actor.Id) continue;
            }
            if (obj.Position.X < 0 || obj.Position.Y < 0) continue;
            try
            {
                if (!world.KillObject(id)) world.Remove(id);
            }
            catch { }
        }
    }

    private static int DismissAllDialogs(SimulationWorld world)
    {
        var count = 0;
        for (var guard = 0; guard < 16; guard++)
        {
            var visible = world.DialogRecords.FirstOrDefault(r => r.Visible && r.State < 2);
            if (visible is null) break;
            count++;
            try
            {
                world.RespondMessageDialog(visible.Token, 0);
            }
            catch
            {
                visible.State = 5;
                visible.Visible = false;
            }
        }
        return count;
    }

    private static bool IsTravelOrDestructiveLabel(string label)
    {
        foreach (var kw in SkipTravelKeywords)
            if (label.Contains(kw, StringComparison.OrdinalIgnoreCase)) return true;
        return false;
    }

    private static string DescribePlacementFailureCode(int code) => code switch
    {
        0x00 => "None/Unknown",
        0x01 => "WallRequirementNotMet",
        0x0b => "Overlap/Occupied",
        0x0c => "OutOfBounds/NoFloor",
        0x0e => "InsufficientSupportStrength",
        0x10 => "WallRequirementNotMet",
        0x11 => "SlopedTerrain",
        0x13 => "RejectsFloorTile",
        0x14 => "NeedsFloorTile",
        0x18 => "AllowedHeightMismatch",
        0x19 => "PortalOrWallIntersection",
        0x1d => "RejectsPoolWater",
        0x1e => "RequiresPoolWater",
        _ => $"Code_0x{code:X2}",
    };

    public static string FormatClustersMarkdown(SweepReport report, SweepOptions options)
    {
        var sb = new StringBuilder();
        sb.AppendLine("# Interaction Outcome Sweep & Root-Cause Clusters");
        sb.AppendLine();
        sb.AppendLine($"- **Objects tested:** {report.ObjectsTested} (placed: {report.ObjectsPlaced}, unplaced: {report.ObjectsPlacementFailed})");
        sb.AppendLine($"- **TTAB entries audited:** {report.TotalTtabEntries}");
        sb.AppendLine($"- **Total interaction trials:** {report.TotalTrials} (ticks/trial: {options.Ticks})");
        sb.AppendLine();
        sb.AppendLine("## Outcome Breakdown");
        sb.AppendLine();
        sb.AppendLine("| Outcome | Count |");
        sb.AppendLine("|---|---:|");
        foreach (var (kind, count) in report.OutcomeCounts.OrderByDescending(kv => kv.Value))
            sb.AppendLine($"| `{kind}` | {count} |");
        sb.AppendLine();

        var actionableClusters = report.Clusters.Where(c => c.OutcomeKind != InteractionOutcomeKind.NeverOffered).ToList();
        var guardClusters = report.Clusters.Where(c => c.OutcomeKind == InteractionOutcomeKind.NeverOffered).ToList();

        sb.AppendLine("## Actionable Execution Failure Clusters");
        sb.AppendLine();
        if (actionableClusters.Count == 0)
        {
            sb.AppendLine("No execution failures (ThreadError, GuardError, RouteFailed, MissingAnimation, EarlyBailout, Stalled) found.");
            sb.AppendLine();
        }
        else
        {
            var rank = 0;
            foreach (var cluster in actionableClusters.Take(50))
            {
                rank++;
                sb.AppendLine($"### {rank}. `{cluster.OutcomeKind}` — {cluster.Count} trials ({cluster.DistinctObjects} objects)");
                sb.AppendLine($"- **Signature:** `{cluster.Signature}`");
                sb.AppendLine($"- **Packs:** {string.Join(", ", cluster.Packs)}");
                sb.AppendLine($"- **Detail:** {cluster.Detail}");
                sb.AppendLine("- **Samples:**");
                foreach (var sample in cluster.Samples.Take(5))
                    sb.AppendLine($"  - {sample}");
                sb.AppendLine();
            }
        }

        if (guardClusters.Count > 0)
        {
            sb.AppendLine($"## State-Gated / Never-Offered Adult TTAB Guards (top 20 of {guardClusters.Count})");
            sb.AppendLine();
            var rank = 0;
            foreach (var cluster in guardClusters.Take(20))
            {
                rank++;
                sb.AppendLine($"{rank}. **`{cluster.Signature}`** — {cluster.Count} entries ({cluster.DistinctObjects} objects, packs: {string.Join(", ", cluster.Packs)}): {string.Join("; ", cluster.Samples.Take(3))}");
            }
            sb.AppendLine();
        }

        if (report.PlacementFailures.Count > 0)
        {
            sb.AppendLine("## Unplaced Objects by Placement Failure Code");
            sb.AppendLine();
            foreach (var pf in report.PlacementFailures)
            {
                sb.AppendLine($"- **`0x{pf.FailureCode:X2}` ({pf.Hint})** — {pf.Count} objects: {string.Join("; ", pf.Samples.Take(5))}");
            }
            sb.AppendLine();
        }

        return sb.ToString();
    }
}
