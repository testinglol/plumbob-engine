using SimsNative.Plugins;

namespace Local.SmartFreeWill;

internal enum SmartStyle
{
    Classic = 0,
    Drama = 1,
    Mastermind = 2,
}

internal sealed record SmartSettings(
    SmartStyle Style = SmartStyle.Drama,
    bool ThoughtBubbles = true,
    bool SparksAndTurfWars = true)
{
    public bool Enabled => Style != SmartStyle.Classic;
    public bool IsDrama => Style == SmartStyle.Drama;
    public bool IsMastermind => Style == SmartStyle.Mastermind;
}

internal sealed class SimMindPlanner(HouseholdBlackboard blackboard, BalloonDirector balloons)
{
    private enum BalloonCue
    {
        None,
        TargetObject,
        HoldItThenTarget,
        PanicToilet,
        CrushShot,
        TurfWar,
        HostileSpark,
        HubrisIdea,
        RefuseTvThenTarget,
        NeatRageClean,
        MusicParty,
        CareerScheme,
        SleepBed,
    }

    private sealed record CandidateEval(
        float Score,
        bool Urgent,
        BalloonCue Cue = BalloonCue.TargetObject,
        short? SecondaryId = null);

    private readonly Dictionary<short, int> lastInterruptMinute = [];
    private readonly Dictionary<short, int> lastProactiveQueueMinute = [];
    private long currentTick;

    public void UpdateTick(long tick) => currentTick = tick;

    public int? SelectBestCandidate(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginAutonomyContext context,
        IReadOnlyList<PluginAutonomyCandidate> candidates)
    {
        if (!settings.Enabled || !context.Household || candidates.Count == 0)
            return null;

        var allSims = lot.AllSims;
        var sim = allSims.FirstOrDefault(s => s.ObjectId == context.SimId);
        if (sim is null || sim.Npc || HouseholdBlackboard.HasPlayerCommand(sim))
            return null;

        var allObjects = lot.Objects;
        var objectsById = allObjects.ToDictionary(o => o.ObjectId);
        blackboard.SyncWorld(context.House, context.Hours, context.Minutes, allSims, objectsById, lot);

        if (sim.Dog || sim.Cat)
            return SelectPetCandidate(sim, context, candidates, objectsById);

        var relationships = SafeRelationships(lot, sim.ObjectId);
        var relByObjectId = relationships
            .Where(r => r.TargetObjectId.HasValue)
            .GroupBy(r => r.TargetObjectId!.Value)
            .ToDictionary(g => g.Key, g => g.First());

        var fireOnLot = allObjects.Any(o => o.ObjectId == o.LeadObjectId &&
            InteractionClassifier.ClassifyObject(o, isSim: false) == SmartObjectKind.Fire);

        blackboard.IsMealBeingPreparedOrReady(
            sim.ObjectId, allSims, allObjects, objectsById,
            out var readyFoodOnLot, out var someoneElseCooking);

        var hungryHouseholdCount = allSims.Count(s =>
            s.Household && !s.Dog && !s.Cat && !s.AtWorkOrSchool &&
            s.Motives[InteractionClassifier.MotiveHunger] < 25);

        var activeStereoOnFloor = allObjects.FirstOrDefault(o =>
            o.ObjectId == o.LeadObjectId &&
            o.Level == sim.Level &&
            InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.Stereo &&
            HouseholdBlackboard.IsStereoPlaying(o, allSims, objectsById));

        var tvInRoom = allObjects.FirstOrDefault(o =>
            o.ObjectId == o.LeadObjectId &&
            o.Level == sim.Level &&
            o.RoomId == sim.RoomId &&
            o.RepairState == 0 &&
            InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.Television);

        var nearestToilet = allObjects
            .Where(o => o.ObjectId == o.LeadObjectId && InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.Toilet)
            .OrderBy(o => TileDist(sim, o))
            .FirstOrDefault();

        var transitCancelledToday = candidates.Any(c => c.BlockedByPlugin &&
            InteractionClassifier.ContainsAny(c.ObjectName, "schoolbus", "school bus", "carpool", "car -"));
        var minutesToShift = transitCancelledToday
            ? null
            : MinutesUntilWorkOrSchool(sim, context.Hours, context.Minutes, context.AwayLot);
        var isNightSleepWindow = IsSleepHoursForSim(sim, context.Hours, minutesToShift, context.AwayLot);

        var ranked = new List<(int Index, float Score, bool Urgent, SmartActionKind Kind, short LeadId, uint Guid, BalloonCue Cue, short? SecondaryId)>(candidates.Count);
        var anyUsableToiletCandidate = false;

        for (var i = 0; i < candidates.Count; i++)
        {
            var cand = candidates[i];
            if (cand.BlockedByPlugin)
                continue;

            var targetObj = objectsById.GetValueOrDefault(cand.ObjectId)
                ?? new PluginObject(cand.ObjectId, cand.ObjectGuid, cand.ObjectName, sim.X, sim.Y, sim.Level, cand.ObjectId);
            var leadObj = objectsById.GetValueOrDefault(targetObj.LeadObjectId, targetObj);
            var targetSim = allSims.FirstOrDefault(s => s.ObjectId == leadObj.ObjectId);

            if (blackboard.IsPlayerVetoed(sim.ObjectId, leadObj.ObjectId, cand.ActionId))
                continue;
            if (blackboard.IsBackedOff(sim.ObjectId, leadObj.ObjectId))
                continue;

            var classified = InteractionClassifier.Classify(
                leadObj,
                targetSim is not null,
                cand.InteractionName,
                cand.EnglishName,
                cand.JoinInteraction,
                cand.MotiveDeltas);

            if (fireOnLot && classified.ActionKind is not (SmartActionKind.ExtinguishOrPanicFire or SmartActionKind.PhoneCallFriend))
                continue;

            if (blackboard.IsClaimedByAnotherSim(sim.ObjectId, leadObj, classified.ObjectKind, cand.JoinInteraction, allSims, objectsById) &&
                classified.ActionKind is not (SmartActionKind.BoardCarpool or SmartActionKind.BoardSchoolBus or SmartActionKind.EatPreparedMeal or SmartActionKind.SwitchChannelOrStation or SmartActionKind.TurnOffMedia or SmartActionKind.DanceToMusic or SmartActionKind.WatchTv))
            {
                continue;
            }

            if (classified.IsBathroomPrivacySensitive &&
                blackboard.ViolatesBathroomPrivacy(sim, leadObj, allSims, relationships, objectsById))
            {
                continue;
            }

            if (classified.ActionKind == SmartActionKind.UseToilet)
                anyUsableToiletCandidate = true;

            var eval = settings.IsDrama
                ? ScoreDramaCandidate(
                    lot, settings, sim, cand, leadObj, targetSim, classified,
                    allSims, allObjects, objectsById, relationships, relByObjectId,
                    activeStereoOnFloor, tvInRoom, nearestToilet,
                    context.Hours, context.AwayLot, minutesToShift, isNightSleepWindow,
                    readyFoodOnLot, someoneElseCooking, hungryHouseholdCount)
                : ScoreMastermindCandidate(
                    lot, settings, sim, cand, leadObj, targetSim, classified,
                    allSims, relationships, relByObjectId,
                    context.Hours, context.AwayLot, minutesToShift, isNightSleepWindow,
                    readyFoodOnLot, someoneElseCooking, hungryHouseholdCount);

            if (eval.Score <= 0.01f)
                continue;

            var weatherFactor = WeatherAppealFactor(cand);
            var finalScore = eval.Score * weatherFactor;
            if (finalScore <= 0.01f)
                continue;

            ranked.Add((i, finalScore, eval.Urgent, classified.ActionKind, leadObj.ObjectId, leadObj.Guid, eval.Cue, eval.SecondaryId));
        }

        if (!anyUsableToiletCandidate && sim.Motives[InteractionClassifier.MotiveBladder] <= -75)
        {
            var hogger = blackboard.FindToiletOccupantSimId(sim.ObjectId, allSims, allObjects, objectsById);
            if (hogger.HasValue)
            {
                balloons.EmitSingle(
                    lot,
                    settings.ThoughtBubbles,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Scream, TargetObjectId: hogger.Value, CrossedOut: true, DurationTicks: 84),
                    currentTick,
                    minGapTicks: 45);
            }
            else if (nearestToilet is not null)
            {
                balloons.EmitSingle(
                    lot,
                    settings.ThoughtBubbles,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Scream, TargetObjectId: nearestToilet.ObjectId, CrossedOut: true, DurationTicks: 84),
                    currentTick,
                    minGapTicks: 45);
            }
        }

        if (ranked.Count == 0)
            return -1;

        ranked.Sort(static (a, b) => b.Score.CompareTo(a.Score));
        var best = ranked[0];

        int chosenRankIndex = 0;
        if (!best.Urgent && ranked.Count > 1)
        {
            var spread = settings.IsDrama ? 0.76f : 0.84f;
            var topPool = ranked.Take(3).Where(r => r.Score >= best.Score * spread).ToArray();
            if (topPool.Length > 1)
            {
                var totalWeight = topPool.Sum(r => r.Score);
                var roll = (context.RandomSeed % 10000u) / 10000f * totalWeight;
                var accum = 0f;
                for (var k = 0; k < topPool.Length; k++)
                {
                    accum += topPool[k].Score;
                    if (roll <= accum)
                    {
                        chosenRankIndex = k;
                        break;
                    }
                }
            }
        }

        var chosen = ranked[chosenRankIndex];
        blackboard.RecordClaim(sim.ObjectId, chosen.LeadId, chosen.Kind, ClaimDurationFor(chosen.Kind));
        EmitSelectionBalloon(lot, settings, sim, chosen.LeadId, chosen.Kind, chosen.Cue, chosen.SecondaryId, nearestToilet?.ObjectId);
        return chosen.Index;
    }

    private CandidateEval ScoreDramaCandidate(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile sim,
        PluginAutonomyCandidate cand,
        PluginObject leadObj,
        PluginSimProfile? targetSim,
        ClassifiedAction classified,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginObject> allObjects,
        IReadOnlyDictionary<short, PluginObject> objectsById,
        IReadOnlyList<PluginSimRelationship> relationships,
        IReadOnlyDictionary<short, PluginSimRelationship> relByObjectId,
        PluginObject? activeStereoOnFloor,
        PluginObject? tvInRoom,
        PluginObject? nearestToilet,
        int hour,
        bool awayLot,
        int? minutesToShift,
        bool isNightSleepWindow,
        bool readyFoodOnLot,
        bool someoneElseCooking,
        int hungryHouseholdCount)
    {
        var energy = sim.Motives[InteractionClassifier.MotiveEnergy];
        var comfort = sim.Motives[InteractionClassifier.MotiveComfort];
        var hunger = sim.Motives[InteractionClassifier.MotiveHunger];
        var hygiene = sim.Motives[InteractionClassifier.MotiveHygiene];
        var bladder = sim.Motives[InteractionClassifier.MotiveBladder];
        var room = sim.Motives[InteractionClassifier.MotiveRoom];
        var social = sim.Motives[InteractionClassifier.MotiveSocial];
        var fun = sim.Motives[InteractionClassifier.MotiveFun];

        var distPenalty = 1f / (1f + 0.024f * MathF.Max(0f, cand.Distance));
        var sameLevelBonus = leadObj.Level == sim.Level ? 1.05f : 0.95f;

        var isLazy = sim.Active <= 300;
        var isEnergetic = sim.Active >= 700;
        var isSlob = sim.Neat <= 250;
        var isNeatFreak = sim.Neat >= 750;
        var isPlayful = sim.Playful >= 650;
        var isSerious = sim.Playful <= 300;
        var isOutgoing = sim.Outgoing >= 650;
        var isShy = sim.Outgoing <= 350;
        var isGrouchy = sim.Nice <= 350;

        if (classified.ActionKind == SmartActionKind.BoardCarpool && !sim.Child && !awayLot)
        {
            if (isLazy && energy < -65 && fun < -40)
                return new(45f * distPenalty, false, BalloonCue.TargetObject);
            return new(2400f * distPenalty, true, BalloonCue.TargetObject);
        }

        if (classified.ActionKind == SmartActionKind.BoardSchoolBus && sim.Child && !awayLot)
            return new(2400f * distPenalty, true, BalloonCue.TargetObject);

        if (classified.ActionKind == SmartActionKind.ExtinguishOrPanicFire)
            return new(3200f * distPenalty, true, BalloonCue.TargetObject);

        if (classified.ActionKind == SmartActionKind.CareForBaby && !sim.Child)
            return new(1550f * distPenalty, true, BalloonCue.TargetObject);

        if (classified.ActionKind == SmartActionKind.UseToilet)
        {
            var preWorkTopOff = minutesToShift is <= 60 ? -8 : -32;
            if (bladder >= preWorkTopOff)
                return new(0f, false);

            if (bladder <= -83)
            {
                var panicScore = (920f + (-83 - bladder) * 35f) * distPenalty;
                return new(panicScore, true, BalloonCue.PanicToilet);
            }

            var disciplined = (sim.Neat >= 650 && !isPlayful) ? 1.35f : 0.82f;
            var moderate = NeedUrgency(bladder, criticalBelow: -80, moderateBelow: -55, topOffBelow: preWorkTopOff);
            var quality = 1f + 0.04f * Math.Clamp((int)leadObj.RatingBladder, 0, 10);
            return new(moderate * 155f * disciplined * quality * distPenalty * sameLevelBonus, false, BalloonCue.TargetObject);
        }

        if (classified.ActionKind == SmartActionKind.SleepInBed)
        {
            if (awayLot && !InteractionClassifier.ContainsAny(leadObj.Name, "tent", "igloo", "bed"))
                return new(0f, false);

            var bedCutoff = isLazy ? (isNightSleepWindow ? 48 : -18) : (isNightSleepWindow ? 20 : -58);
            if (energy >= bedCutoff)
                return new(0f, false);

            if (energy <= -84)
            {
                var ownershipPanic = awayLot ? 1f : blackboard.BedAffinityMultiplier(sim, leadObj, classified.ObjectKind, allSims, relationships);
                return new(880f * ownershipPanic * distPenalty, true, BalloonCue.SleepBed);
            }

            var urgency = NeedUrgency(energy, criticalBelow: -78, moderateBelow: isNightSleepWindow ? -15 : -55, topOffBelow: bedCutoff);
            var bedQuality = 1f + 0.07f * Math.Clamp((int)leadObj.RatingEnergy, 1, 10);
            var ownership = awayLot ? 1f : blackboard.BedAffinityMultiplier(sim, leadObj, classified.ObjectKind, allSims, relationships);
            var lazyPull = isLazy ? 1.45f : (isPlayful && !isNightSleepWindow ? 0.65f : 1.0f);
            var gentleDist = 1f / (1f + 0.012f * MathF.Max(0f, cand.Distance));
            return new(urgency * 320f * bedQuality * ownership * lazyPull * gentleDist, energy <= -76, BalloonCue.SleepBed);
        }

        if (classified.ActionKind == SmartActionKind.Nap)
        {
            if (energy > (isLazy ? 15 : -38))
                return new(0f, false);
            var lazyNapBoost = isLazy ? 3.1f : (isEnergetic ? 0.25f : 0.9f);
            var score = (65f + NeedUrgency(energy, -70, -25, 15) * 145f) * lazyNapBoost * distPenalty;
            return new(score, false, BalloonCue.TargetObject);
        }

        if (classified.ActionKind == SmartActionKind.DrinkCaffeine)
        {
            if (sim.Child || bladder <= -78)
                return new(0f, false);
            if (energy > 30 && !(hour >= 21 && (isPlayful || isSerious)))
                return new(0f, false);
            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.DrinkCaffeine);
            if (novelty < 0.45f)
                return new(0f, false);
            var lateNightBinge = hour >= 20 && (isPlayful || isSerious) ? 1.75f : 1.0f;
            var score = (85f + NeedUrgency(energy, -70, -20, 30) * 155f) * lateNightBinge * novelty * distPenalty;
            return new(score, false, BalloonCue.HubrisIdea);
        }

        if (classified.ActionKind == SmartActionKind.RepairObject)
        {
            if (sim.Child || awayLot)
                return new(0f, false);

            if (classified.IsElectricalRepairRisk)
            {
                if (!settings.SparksAndTurfWars && sim.Mechanical < 350)
                    return new(0f, false);
                var stubbornHubris = isGrouchy || isEnergetic || isPlayful || sim.Mechanical >= 300;
                if (!stubbornHubris)
                    return new(0f, false);
                var favoriteBroken =
                    (classified.ObjectKind == SmartObjectKind.Television && isLazy) ||
                    (classified.ObjectKind == SmartObjectKind.ComputerOrArcade && isPlayful) ||
                    (classified.ObjectKind == SmartObjectKind.Stereo && isOutgoing);
                var hubrisBoost = sim.Mechanical < 250
                    ? (favoriteBroken ? 265f : 195f)
                    : 185f;
                return new(hubrisBoost * distPenalty, false, BalloonCue.HubrisIdea);
            }

            var plumbingScore = (classified.ObjectKind == SmartObjectKind.Toilet ? 240f : 155f) * (isSlob ? 0.35f : 1.15f) * distPenalty;
            return new(plumbingScore, classified.ObjectKind == SmartObjectKind.Toilet, BalloonCue.HubrisIdea);
        }

        if (classified.ActionKind is SmartActionKind.EatPreparedMeal or SmartActionKind.PrepareGroupMeal or
            SmartActionKind.PrepareSingleMeal or SmartActionKind.HaveSnack)
        {
            return ScoreDramaFood(
                settings, sim, leadObj, classified, allSims,
                hunger, bladder, hour, awayLot, minutesToShift,
                readyFoodOnLot, someoneElseCooking, hungryHouseholdCount,
                isLazy, isSlob, distPenalty, nearestToilet);
        }

        if (classified.ActionKind is SmartActionKind.TakeShower or SmartActionKind.TakeBath or SmartActionKind.WashHandsOrBrush)
        {
            if (isSlob && hygiene > -78)
                return new(0f, false);
            if (classified.ActionKind == SmartActionKind.WashHandsOrBrush)
            {
                if (!isNeatFreak || hygiene >= 35 || hygiene < -30)
                    return new(0f, false);
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.WashHandsOrBrush);
                return new(65f * novelty * distPenalty, false, BalloonCue.TargetObject);
            }

            var topOff = isNeatFreak ? 25 : -18;
            if (hygiene >= topOff)
                return new(0f, false);
            var urgency = NeedUrgency(hygiene, criticalBelow: -80, moderateBelow: -45, topOffBelow: topOff);
            var luxBath = classified.ActionKind == SmartActionKind.TakeBath && isLazy ? 1.45f : 1.0f;
            return new(urgency * 240f * luxBath * distPenalty, hygiene <= -78, BalloonCue.TargetObject);
        }

        if (classified.ActionKind is SmartActionKind.CleanOrDispose or SmartActionKind.MakeBed or SmartActionKind.WaterPlant)
        {
            if (awayLot || bladder <= -80 || energy <= -80)
                return new(0f, false);
            if (isSlob || (isLazy && sim.Neat < 600))
                return new(0f, false);
            if (sim.Neat < 450 && classified.ObjectKind != SmartObjectKind.FloodOrPuddle)
                return new(0f, false);

            var neatObsession = isNeatFreak ? 2.75f : (0.55f + sim.Neat * 0.0012f);
            var baseChore = classified.ObjectKind switch
            {
                SmartObjectKind.FloodOrPuddle => 210f,
                SmartObjectKind.DirtyDish => 165f,
                SmartObjectKind.TrashOrAsh => 160f,
                _ => classified.ActionKind == SmartActionKind.MakeBed ? 125f : 110f,
            };
            var cue = isNeatFreak && classified.ObjectKind is SmartObjectKind.FloodOrPuddle or SmartObjectKind.DirtyDish or SmartObjectKind.TrashOrAsh
                ? BalloonCue.NeatRageClean
                : BalloonCue.TargetObject;
            return new(baseChore * neatObsession * distPenalty, false, cue);
        }

        if (classified.ActionKind == SmartActionKind.PayBills)
        {
            if (sim.Child || awayLot || lot.HouseholdFunds < 150 || isSlob || isLazy)
                return new(0f, false);
            return new(210f * distPenalty, false, BalloonCue.TargetObject);
        }

        if (classified.ActionKind == SmartActionKind.GetMail)
        {
            if (awayLot || hour is < 7 or > 20 || isLazy)
                return new(0f, false);
            return new(125f * distPenalty, false, BalloonCue.TargetObject);
        }

        if (classified.ActionKind == SmartActionKind.CareForPet && !awayLot)
            return new(220f * distPenalty, false, BalloonCue.TargetObject);

        if (classified.ActionKind == SmartActionKind.SwitchChannelOrStation)
        {
            if (!settings.SparksAndTurfWars)
                return new(0f, false);

            if (classified.ObjectKind == SmartObjectKind.Television)
            {
                var watcher = HouseholdBlackboard.FindActiveTvWatcher(leadObj, sim.ObjectId, allSims, objectsById);
                if (watcher is null)
                    return new(0f, false);
                relByObjectId.TryGetValue(watcher.ObjectId, out var wRel);
                var clash = Math.Abs(sim.Playful - watcher.Playful) >= 350 ||
                            Math.Abs(sim.Active - watcher.Active) >= 350 ||
                            isGrouchy ||
                            (wRel?.Daily ?? 0) < 15;
                if (!clash)
                    return new(0f, false);
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.SwitchChannelOrStation);
                return new(255f * novelty * distPenalty, false, BalloonCue.TurfWar, watcher.ObjectId);
            }

            if (classified.ObjectKind == SmartObjectKind.Stereo && HouseholdBlackboard.IsStereoPlaying(leadObj, allSims, objectsById))
            {
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.SwitchChannelOrStation);
                if (novelty < 0.5f || (!isOutgoing && !isGrouchy))
                    return new(0f, false);
                return new(145f * novelty * distPenalty, false, BalloonCue.MusicParty);
            }
            return new(0f, false);
        }

        if (classified.ActionKind == SmartActionKind.TurnOffMedia)
        {
            if (!settings.SparksAndTurfWars)
                return new(0f, false);

            if (classified.ObjectKind == SmartObjectKind.Stereo && HouseholdBlackboard.IsStereoPlaying(leadObj, allSims, objectsById))
            {
                var hatesNoise = (isSerious || isNeatFreak || isGrouchy) && (hour >= 22 || hour < 7 || energy < -25);
                if (!hatesNoise)
                    return new(0f, false);
                var dancer = allSims.FirstOrDefault(s =>
                    s.ObjectId != sim.ObjectId &&
                    s.CurrentAction is { } cur &&
                    (objectsById.GetValueOrDefault(cur.TargetObjectId)?.LeadObjectId ?? cur.TargetObjectId) == leadObj.ObjectId);
                return new(245f * distPenalty, false, BalloonCue.TurfWar, dancer?.ObjectId ?? leadObj.ObjectId);
            }
            return new(0f, false);
        }

        if (classified.ActionKind == SmartActionKind.TurnOnMedia && classified.ObjectKind == SmartObjectKind.Stereo)
        {
            if (HouseholdBlackboard.IsStereoPlaying(leadObj, allSims, objectsById))
                return new(0f, false);
            var sleepingHousemate = allSims.FirstOrDefault(s => s.ObjectId != sim.ObjectId && s.Asleep && s.Level == leadObj.Level);
            if (sleepingHousemate is not null && !isGrouchy && !(isOutgoing && isPlayful && settings.SparksAndTurfWars))
                return new(0f, false);
            if (!isOutgoing && !isPlayful && sim.MusicInterest < 60 && sim.PartyInterest < 60)
                return new(25f * distPenalty, false, BalloonCue.MusicParty);

            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.TurnOnMedia);
            var wakePrank = sleepingHousemate is not null && settings.SparksAndTurfWars;
            return new(235f * novelty * distPenalty, false,
                wakePrank ? BalloonCue.TurfWar : BalloonCue.MusicParty,
                wakePrank ? sleepingHousemate!.ObjectId : null);
        }

        if (classified.ActionKind == SmartActionKind.DanceToMusic)
        {
            var stereoLive = HouseholdBlackboard.IsStereoPlaying(leadObj, allSims, objectsById);
            var partyFit = (isOutgoing ? 1.55f : 0.85f) * (isPlayful ? 1.45f : 0.85f) * (isEnergetic ? 1.25f : 1.0f);
            var contagion = stereoLive ? 210f : 95f;
            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.DanceToMusic);
            var cue = bladder <= -50 && nearestToilet is not null ? BalloonCue.HoldItThenTarget : BalloonCue.MusicParty;
            return new(contagion * partyFit * novelty * distPenalty, false, cue);
        }

        if (classified.ActionKind == SmartActionKind.WatchTv)
        {
            var watcher = HouseholdBlackboard.FindActiveTvWatcher(leadObj, sim.ObjectId, allSims, objectsById);
            var watcherRel = watcher is not null && relByObjectId.TryGetValue(watcher.ObjectId, out var r) ? r : null;
            var joiningCrush = watcherRel is not null && (watcherRel.Crush || watcherRel.Love || watcherRel.Daily >= 55);

            if (isEnergetic && !joiningCrush)
                return new(0f, false);

            var lazyMagnet = isLazy ? 3.25f : 1.05f;
            var funDrive = 65f + NeedUrgency(fun, -65, 15, 85) * 155f + (joiningCrush ? 95f : 0f);
            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.WatchTv);
            var cue = bladder <= -50 && nearestToilet is not null ? BalloonCue.HoldItThenTarget : BalloonCue.TargetObject;
            return new(funDrive * lazyMagnet * novelty * distPenalty, false, cue);
        }

        if (classified.ActionKind == SmartActionKind.PlayComputerOrArcade)
        {
            var gamerMagnet = isPlayful && isShy
                ? 3.4f
                : isPlayful
                    ? 2.35f
                    : sim.TechInterest >= 65
                        ? 1.95f
                        : 0.95f;
            var funDrive = 75f + NeedUrgency(fun, -65, 20, 90) * 165f;
            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.PlayComputerOrArcade);
            var cue = bladder <= -48 && nearestToilet is not null
                ? BalloonCue.HoldItThenTarget
                : (isEnergetic && tvInRoom is not null ? BalloonCue.RefuseTvThenTarget : BalloonCue.TargetObject);
            return new(funDrive * gamerMagnet * novelty * distPenalty, false, cue, tvInRoom?.ObjectId);
        }

        if (classified.ActionKind == SmartActionKind.PlayInstrument)
        {
            var audienceCount = allSims.Count(s => s.ObjectId != sim.ObjectId && !s.AtWorkOrSchool && !s.Asleep && s.Level == leadObj.Level);
            var showOffHubris = sim.Creativity < 250 && (isOutgoing || isPlayful) && audienceCount > 0 && settings.SparksAndTurfWars
                ? 2.25f
                : (0.85f + sim.Playful * 0.0005f + sim.Creativity * 0.0004f);
            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.PlayInstrument);
            var cue = sim.Creativity < 250 && audienceCount > 0 ? BalloonCue.HubrisIdea : BalloonCue.TargetObject;
            return new((85f + NeedUrgency(fun, -60, 15, 85) * 135f) * showOffHubris * novelty * distPenalty, false, cue);
        }

        if (targetSim is not null || classified.ActionKind == SmartActionKind.PhoneCallFriend)
        {
            return ScoreDramaSocial(
                settings, sim, leadObj, targetSim, classified,
                allSims, relationships, relByObjectId, activeStereoOnFloor,
                social, fun, energy, hunger, bladder, hour, awayLot, distPenalty);
        }

        if (classified.ActionKind == SmartActionKind.StudySchool && sim.Child)
        {
            if (isPlayful && fun < 10)
                return new(18f * distPenalty, false);
            var perf = sim.Career?.JobPerformance ?? 50;
            if (perf < 70 && hour is >= 7 and <= 21 && energy > -55 && bladder > -65)
            {
                var seriousChild = isSerious || isNeatFreak ? 2.1f : 0.95f;
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.StudySchool);
                return new(155f * seriousChild * novelty * distPenalty, false, BalloonCue.CareerScheme);
            }
        }

        if (classified.ActionKind == SmartActionKind.TrainSkill && !awayLot && energy > -65 && bladder > -72)
        {
            var (skillBonus, _) = EvaluateSkillDrive(sim, classified.TrainedSkills);
            var obsessionFit = DramaSkillObsessionFit(sim, classified.TrainedSkills, isSerious, isEnergetic, isOutgoing);
            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.TrainSkill);
            var cue = isEnergetic && tvInRoom is not null && (classified.TrainedSkills & SkillMask.Body) != 0
                ? BalloonCue.RefuseTvThenTarget
                : (skillBonus >= 120f ? BalloonCue.CareerScheme : BalloonCue.TargetObject);
            return new((75f + skillBonus * 0.75f) * obsessionFit * novelty * distPenalty, false, cue, tvInRoom?.ObjectId);
        }

        var dFun = Math.Max(0f, InteractionClassifier.Delta(cand.MotiveDeltas, InteractionClassifier.MotiveFun));
        var dComfort = Math.Max(0f, InteractionClassifier.Delta(cand.MotiveDeltas, InteractionClassifier.MotiveComfort));
        var funUrgency = NeedUrgency(fun, criticalBelow: -60, moderateBelow: 15, topOffBelow: 85);
        var comfortUrgency = NeedUrgency(comfort, criticalBelow: -55, moderateBelow: 5, topOffBelow: 65);

        var leisureScore = funUrgency * (55f + dFun * 1.5f + leadObj.RatingFun * 7f)
            + comfortUrgency * (22f + dComfort * 1.1f + leadObj.RatingComfort * 5f);

        if (classified.ActionKind is SmartActionKind.JoinGroupActivity or SmartActionKind.UseHotTub)
        {
            var othersIn = leadObj.UseCount > 0 || cand.JoinInteraction;
            var partyBoost = activeStereoOnFloor is not null ? 1.45f : 1.0f;
            if (othersIn)
                leisureScore += (85f + NeedUrgency(social, -55, 20, 80) * 125f) * (0.8f + sim.Outgoing * 0.0008f) * partyBoost;
            else if (classified.ActionKind == SmartActionKind.UseHotTub && (isOutgoing || isLazy || isPlayful))
                leisureScore += 95f * partyBoost;
        }

        leisureScore *= DramaLeisurePersonalityFit(sim, leadObj, classified, isLazy, isEnergetic, isPlayful, isSerious);
        leisureScore *= blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, classified.ActionKind);

        if (awayLot)
            leisureScore *= 1.3f;

        if (leisureScore <= 4f)
            leisureScore = Math.Max(0f, cand.AdjustedScore * 10f) * blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, classified.ActionKind);

        var leisureCue = bladder <= -50 && nearestToilet is not null && dFun >= 12f
            ? BalloonCue.HoldItThenTarget
            : (isEnergetic && tvInRoom is not null && InteractionClassifier.ContainsAny(leadObj.Name, "pool", "basket", "dive", "slide")
                ? BalloonCue.RefuseTvThenTarget
                : BalloonCue.TargetObject);

        return new(leisureScore * distPenalty * sameLevelBonus, false, leisureCue, tvInRoom?.ObjectId);
    }

    private CandidateEval ScoreDramaFood(
        SmartSettings settings,
        PluginSimProfile sim,
        PluginObject leadObj,
        ClassifiedAction classified,
        IReadOnlyList<PluginSimProfile> allSims,
        short hunger,
        short bladder,
        int hour,
        bool awayLot,
        int? minutesToShift,
        bool readyFoodOnLot,
        bool someoneElseCooking,
        int hungryHouseholdCount,
        bool isLazy,
        bool isSlob,
        float distPenalty,
        PluginObject? nearestToilet)
    {
        var topOff = isLazy || isSlob ? 25 : 5;
        if (hunger >= topOff)
            return new(0f, false);

        if (classified.ActionKind == SmartActionKind.EatPreparedMeal)
        {
            var urgency = NeedUrgency(hunger, -80, -20, topOff);
            var urgent = hunger <= -78;
            return new(urgency * 480f * distPenalty, urgent, BalloonCue.TargetObject);
        }

        if (readyFoodOnLot && hunger > -82)
            return new(0f, false);

        var foodUrgency = NeedUrgency(hunger, -82, -25, topOff);
        var desperate = hunger <= -82;

        if (classified.ActionKind == SmartActionKind.HaveSnack)
        {
            var snackHabit = (isLazy || isSlob || sim.Child || hour >= 22) ? 2.15f : 0.85f;
            return new(foodUrgency * 215f * snackHabit * distPenalty, desperate, BalloonCue.TargetObject);
        }

        if (someoneElseCooking && hunger > -78 && !(isGrouchyOrImpatient(sim)))
            return new(0f, false);

        var foodQuality = 1f + 0.05f * Math.Clamp((int)leadObj.RatingHunger, 0, 10);
        var zeroCookHubris = classified.IsStoveFireRisk && sim.Cooking < 150 && settings.SparksAndTurfWars;
        var cue = zeroCookHubris
            ? BalloonCue.HubrisIdea
            : (bladder <= -55 && nearestToilet is not null ? BalloonCue.HoldItThenTarget : BalloonCue.TargetObject);

        if (classified.ActionKind == SmartActionKind.PrepareGroupMeal)
        {
            if (sim.Child)
                return new(0f, false);
            var hostBoost = hungryHouseholdCount >= 2 && sim.Nice >= 500 ? 1.45f : 0.95f;
            return new(foodUrgency * 330f * foodQuality * hostBoost * distPenalty, desperate, cue);
        }

        return new(foodUrgency * 310f * foodQuality * distPenalty, desperate, cue);
    }

    private static bool isGrouchyOrImpatient(PluginSimProfile sim) => sim.Nice <= 350 || sim.Active >= 700;

    private CandidateEval ScoreDramaSocial(
        SmartSettings settings,
        PluginSimProfile sim,
        PluginObject leadObj,
        PluginSimProfile? targetSim,
        ClassifiedAction classified,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginSimRelationship> relationships,
        IReadOnlyDictionary<short, PluginSimRelationship> relByObjectId,
        PluginObject? activeStereoOnFloor,
        short social,
        short fun,
        short energy,
        short hunger,
        short bladder,
        int hour,
        bool awayLot,
        float distPenalty)
    {
        if (energy <= -84 || hunger <= -84 || bladder <= -84)
            return new(0f, false);

        if (classified.ActionKind == SmartActionKind.PhoneCallFriend)
        {
            if (awayLot || (hour < 7 && sim.Nice > 300))
                return new(0f, false);
            var socialNeed = NeedUrgency(social, -65, -5, 35);
            if (socialNeed <= 0.05f)
                return new(0f, false);
            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.PhoneCallFriend);
            return new((70f + socialNeed * 175f) * novelty * distPenalty, false, BalloonCue.TargetObject);
        }

        if (targetSim is null || targetSim.Asleep || targetSim.AtWorkOrSchool || targetSim.Dog || targetSim.Cat)
            return new(0f, false);

        if (targetSim.CurrentAction is { } targetAct &&
            InteractionClassifier.ContainsAny(targetAct.EnglishName ?? targetAct.Name, "toilet", "shower", "bath", "sleep"))
        {
            return new(0f, false);
        }

        relByObjectId.TryGetValue(targetSim.ObjectId, out var rel);
        var daily = rel?.Daily ?? 0;
        var reverseDaily = rel?.ReverseDaily ?? 0;
        var lifetime = rel?.Lifetime ?? 0;
        var partyContagion = activeStereoOnFloor is not null ? 1.42f : 1.0f;

        if (classified.ActionKind == SmartActionKind.GreetVisitor)
        {
            if (!targetSim.Greeted && targetSim.Visitor && hour is >= 6 and <= 23)
                return new(410f * (0.75f + sim.Outgoing * 0.0006f) * distPenalty, false, BalloonCue.TargetObject, targetSim.ObjectId);
        }

        if (classified.ActionKind == SmartActionKind.SocialRomantic)
        {
            if (sim.Child || targetSim.Child || !AllowsRomanticTarget(sim, targetSim))
                return new(0f, false);

            var mutualRomance = rel is { Love: true } or { Crush: true } || (daily >= 65 && reverseDaily >= 55);
            var crushThreshold = (sim.Outgoing >= 650 || sim.RomanceInterest >= 60) ? 20 : (sim.Outgoing <= 300 ? 35 : 28);
            var oneWayCrush = settings.SparksAndTurfWars && daily >= crushThreshold;

            if (!mutualRomance && !oneWayCrush)
                return new(0f, false);

            var jealousyOnLot = allSims.Any(other =>
                other.ObjectId != sim.ObjectId &&
                other.ObjectId != targetSim.ObjectId &&
                !other.AtWorkOrSchool && !other.Asleep &&
                relationships.Any(r => r.TargetObjectId == other.ObjectId && (r.Love || r.Crush)));

            if (jealousyOnLot && !settings.SparksAndTurfWars)
                return new(0f, false);

            var dramaRiskMultiplier = 1f;
            if (daily - reverseDaily >= 18)
                dramaRiskMultiplier *= 1.38f;
            if (jealousyOnLot)
                dramaRiskMultiplier *= (sim.Nice <= 450 || sim.Outgoing >= 650 || sim.Playful >= 650) ? 1.35f : 0.45f;

            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.SocialRomantic);
            var romanceDrive = (165f + NeedUrgency(social, -60, 25, 90) * 165f) * dramaRiskMultiplier * partyContagion * novelty * distPenalty;
            return new(romanceDrive, false, BalloonCue.CrushShot, targetSim.ObjectId);
        }

        if (classified.ActionKind == SmartActionKind.SocialHostile)
        {
            if (!settings.SparksAndTurfWars)
                return new(0f, false);

            var hasGrudge = daily <= -8 || reverseDaily <= -15;
            var crankyBully = sim.Nice <= 350 && (daily < 25 || fun < 0 || hunger < -25);
            if (!hasGrudge && !crankyBully)
                return new(0f, false);

            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.SocialHostile);
            var feudIntensity = (hasGrudge ? 185f : 135f) * (1.25f - sim.Nice * 0.0008f) * partyContagion * novelty * distPenalty;
            return new(feudIntensity, false, BalloonCue.HostileSpark, targetSim.ObjectId);
        }

        var socialUrgency = NeedUrgency(social, criticalBelow: -60, moderateBelow: 15, topOffBelow: 78);
        var outgoingBoost = 0.72f + sim.Outgoing * 0.00075f;
        var kindFit = classified.ActionKind == SmartActionKind.SocialPlayful
            ? 0.75f + sim.Playful * 0.00075f
            : 0.82f + sim.Nice * 0.00045f;
        var socNovelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, classified.ActionKind);
        var baseSocial = (70f + socialUrgency * 195f + (targetSim.Visitor ? 45f : 0f)) * partyContagion;

        return new(baseSocial * outgoingBoost * kindFit * socNovelty * distPenalty, social <= -75, BalloonCue.TargetObject, targetSim.ObjectId);
    }

    private CandidateEval ScoreMastermindCandidate(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile sim,
        PluginAutonomyCandidate cand,
        PluginObject leadObj,
        PluginSimProfile? targetSim,
        ClassifiedAction classified,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginSimRelationship> relationships,
        IReadOnlyDictionary<short, PluginSimRelationship> relByObjectId,
        int hour,
        bool awayLot,
        int? minutesToShift,
        bool isNightSleepWindow,
        bool readyFoodOnLot,
        bool someoneElseCooking,
        int hungryHouseholdCount)
    {
        var energy = sim.Motives[InteractionClassifier.MotiveEnergy];
        var comfort = sim.Motives[InteractionClassifier.MotiveComfort];
        var hunger = sim.Motives[InteractionClassifier.MotiveHunger];
        var hygiene = sim.Motives[InteractionClassifier.MotiveHygiene];
        var bladder = sim.Motives[InteractionClassifier.MotiveBladder];
        var room = sim.Motives[InteractionClassifier.MotiveRoom];
        var social = sim.Motives[InteractionClassifier.MotiveSocial];
        var fun = sim.Motives[InteractionClassifier.MotiveFun];

        var distPenalty = 1f / (1f + 0.032f * MathF.Max(0f, cand.Distance));
        var sameLevelBonus = leadObj.Level == sim.Level ? 1.06f : 0.94f;

        if (classified.ActionKind == SmartActionKind.BoardCarpool && !sim.Child && !awayLot)
            return new(2500f * distPenalty, true);

        if (classified.ActionKind == SmartActionKind.BoardSchoolBus && sim.Child && !awayLot)
            return new(2500f * distPenalty, true);

        if (classified.ActionKind == SmartActionKind.ExtinguishOrPanicFire)
            return new(3000f * distPenalty, true);

        if (classified.ActionKind == SmartActionKind.CareForBaby && !sim.Child)
            return new(1600f * distPenalty, true);

        if (classified.ActionKind is SmartActionKind.LightFire or SmartActionKind.SwitchChannelOrStation or SmartActionKind.TurnOffMedia)
            return new(0f, false);

        if (classified.ActionKind == SmartActionKind.RepairObject)
        {
            if (sim.Child || awayLot)
                return new(0f, false);
            if (classified.IsElectricalRepairRisk && (sim.Mechanical < 350 || energy < -25 || hunger < -35))
                return new(0f, false);
            if (minutesToShift is <= 60)
                return new(0f, false);
            var repairScore = (classified.ObjectKind == SmartObjectKind.Toilet ? 220f : 145f) * distPenalty;
            return new(repairScore, classified.ObjectKind == SmartObjectKind.Toilet);
        }

        if (minutesToShift is <= 35 &&
            classified.ActionKind is SmartActionKind.SleepInBed or SmartActionKind.Nap or SmartActionKind.TakeBath or
                SmartActionKind.PrepareGroupMeal or SmartActionKind.UseHotTub or SmartActionKind.TrainSkill or SmartActionKind.StudySchool)
        {
            return new(0f, false);
        }

        if (classified.ActionKind == SmartActionKind.UseToilet)
        {
            if (bladder >= 65)
                return new(0f, false);
            var urgency = NeedUrgency(bladder, criticalBelow: -50, moderateBelow: 5, topOffBelow: minutesToShift is <= 120 ? 45 : 20);
            if (urgency <= 0.02f)
                return new(0f, false);
            var quality = 1f + 0.04f * Math.Clamp((int)leadObj.RatingBladder, 0, 10) + 0.03f * Math.Clamp((int)leadObj.RatingComfort, 0, 10);
            var dirtyPenalty = leadObj.DirtyLevel > 30 ? 0.82f : 1f;
            var urgent = bladder < -45 || (minutesToShift is <= 90 && bladder < 10);
            return new(urgency * 420f * quality * dirtyPenalty * distPenalty * sameLevelBonus, urgent,
                bladder <= -65 ? BalloonCue.PanicToilet : BalloonCue.TargetObject);
        }

        if (classified.ActionKind == SmartActionKind.SleepInBed)
        {
            if (awayLot && !InteractionClassifier.ContainsAny(leadObj.Name, "tent", "igloo", "bed"))
                return new(0f, false);
            if (minutesToShift is <= 95 && energy > -80)
                return new(0f, false);
            if (!isNightSleepWindow && energy > -42)
                return new(0f, false);
            if (isNightSleepWindow && energy > 38)
                return new(0f, false);

            var sleepThreshold = isNightSleepWindow ? 32 : -40;
            var urgency = NeedUrgency(energy, criticalBelow: -65, moderateBelow: isNightSleepWindow ? 0 : -45, topOffBelow: sleepThreshold);
            var bedQuality = 1f + 0.075f * Math.Clamp((int)leadObj.RatingEnergy, 1, 10) + 0.03f * Math.Clamp((int)leadObj.RatingComfort, 0, 10);
            var ownership = awayLot ? 1f : blackboard.BedAffinityMultiplier(sim, leadObj, classified.ObjectKind, allSims, relationships);
            var nightBoost = isNightSleepWindow ? 1.45f : 1f;
            var gentleDist = 1f / (1f + 0.012f * MathF.Max(0f, cand.Distance));
            var urgent = energy < -60 || (isNightSleepWindow && energy < -15);
            return new(urgency * 440f * bedQuality * ownership * nightBoost * gentleDist, urgent, BalloonCue.SleepBed);
        }

        if (classified.ActionKind == SmartActionKind.Nap)
        {
            if (isNightSleepWindow || energy > -20 || minutesToShift is <= 65)
                return new(0f, false);
            var anyFreeBed = !awayLot && lot.Objects.Any(o =>
                o.ObjectId == o.LeadObjectId && o.UseCount == 0 &&
                InteractionClassifier.ClassifyObject(o, false) is SmartObjectKind.Bed or SmartObjectKind.DoubleBed);
            if (anyFreeBed && energy < -55)
                return new(8f * distPenalty, false);
            var lazyFactor = 0.7f + (1000 - sim.Active) * 0.0006f;
            return new(NeedUrgency(energy, -55, -35, -20) * 95f * lazyFactor * distPenalty, false);
        }

        if (classified.ActionKind == SmartActionKind.DrinkCaffeine)
        {
            if (sim.Child || bladder < -15 || hour >= 19 || (isNightSleepWindow && minutesToShift is null or > 180))
                return new(0f, false);
            if (energy > 25 && !(minutesToShift is <= 120 && energy < 45))
                return new(0f, false);
            var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.DrinkCaffeine);
            if (novelty < 0.5f)
                return new(0f, false);
            var prepBoost = minutesToShift is <= 120 && energy < 35 ? 1.5f : 0.85f;
            return new(NeedUrgency(energy, -55, -15, 25) * 115f * prepBoost * novelty * distPenalty, false, BalloonCue.CareerScheme);
        }

        if (classified.ActionKind is SmartActionKind.EatPreparedMeal or SmartActionKind.PrepareGroupMeal or
            SmartActionKind.PrepareSingleMeal or SmartActionKind.HaveSnack)
        {
            var topOff = minutesToShift is <= 140 ? 40 : 12;
            var isGroupChefCandidate = settings.SparksAndTurfWars && !awayLot &&
                classified.ActionKind == SmartActionKind.PrepareGroupMeal &&
                hungryHouseholdCount >= 2 && hunger < 45 &&
                !readyFoodOnLot && !someoneElseCooking &&
                blackboard.IsBestAvailableHouseholdChef(sim, allSims);

            if (hunger >= topOff && !isGroupChefCandidate)
                return new(0f, false);

            var urgency = isGroupChefCandidate
                ? Math.Max(0.65f, NeedUrgency(hunger, -60, -5, 45))
                : NeedUrgency(hunger, criticalBelow: -55, moderateBelow: -10, topOffBelow: topOff);
            var urgent = hunger < -50 || (minutesToShift is <= 95 && hunger < 0);

            if (classified.ActionKind == SmartActionKind.EatPreparedMeal)
            {
                var groupBonus = classified.ObjectKind == SmartObjectKind.GroupMeal ? 1.35f : 1.22f;
                return new(urgency * 460f * groupBonus * distPenalty, urgent);
            }

            if ((readyFoodOnLot && hunger > -75) || (someoneElseCooking && hunger > -65))
                return new(0f, false);

            if (classified.IsStoveFireRisk && sim.Cooking < 150 && !awayLot &&
                allSims.Any(s => s.Household && !s.Child && !s.AtWorkOrSchool && s.Cooking >= 200) && hunger > -65)
            {
                return new(0f, false);
            }

            var foodQuality = 1f + 0.05f * Math.Clamp((int)leadObj.RatingHunger, 0, 10) + 0.02f * Math.Clamp(sim.Cooking / 100, 0, 10);
            var mealTime = hour is >= 6 and <= 9 or >= 11 and <= 14 or >= 17 and <= 21;

            if (classified.ActionKind == SmartActionKind.PrepareGroupMeal)
            {
                if (minutesToShift is <= 40 || sim.Child)
                    return new(0f, false);
                var mult = isGroupChefCandidate || (hungryHouseholdCount >= 2 && mealTime) ? 415f : 250f;
                return new(urgency * mult * foodQuality * distPenalty, urgent);
            }

            if (classified.ActionKind == SmartActionKind.HaveSnack)
            {
                var mult = minutesToShift is <= 35 && hunger < 20 ? 350f : (hunger < -25 && !sim.Child ? 130f : 210f);
                return new(urgency * mult * distPenalty, urgent);
            }

            return new(urgency * 345f * foodQuality * distPenalty, urgent);
        }

        if (classified.ActionKind is SmartActionKind.TakeShower or SmartActionKind.TakeBath or SmartActionKind.WashHandsOrBrush)
        {
            if (classified.ActionKind == SmartActionKind.WashHandsOrBrush)
            {
                if (hygiene >= 45 || hygiene < -25)
                    return new(0f, false);
                var neatBoost = 0.6f + sim.Neat * 0.0008f;
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.WashHandsOrBrush);
                return new(NeedUrgency(hygiene, -20, 10, 40) * 55f * neatBoost * novelty * distPenalty, false);
            }

            var topOff = minutesToShift is <= 140 ? 35 : 5;
            if (hygiene >= topOff)
                return new(0f, false);
            var urgency = NeedUrgency(hygiene, criticalBelow: -65, moderateBelow: -15, topOffBelow: topOff);
            var quality = 1f + 0.05f * Math.Clamp((int)leadObj.RatingHygiene, 1, 10);
            var speedFit = classified.ActionKind == SmartActionKind.TakeShower
                ? (minutesToShift is <= 120 ? 1.45f : 1.12f)
                : (minutesToShift is <= 90 ? 0.35f : (comfort < 0 ? 1.28f : 1.0f));
            var urgent = hygiene < -55 || (minutesToShift is <= 110 && hygiene < -10);
            return new(urgency * 340f * quality * speedFit * distPenalty, urgent);
        }

        if (classified.ActionKind == SmartActionKind.PayBills)
        {
            if (sim.Child || awayLot || lot.HouseholdFunds < 150)
                return new(0f, false);
            return new(260f * distPenalty, false);
        }

        if (classified.ActionKind == SmartActionKind.GetMail)
        {
            if (awayLot || hour is < 7 or > 20)
                return new(0f, false);
            return new(140f * distPenalty, false);
        }

        if (classified.ActionKind is SmartActionKind.CleanOrDispose or SmartActionKind.MakeBed or SmartActionKind.WaterPlant)
        {
            if (awayLot || energy < -45 || hunger < -45 || bladder < -40 || minutesToShift is <= 45)
                return new(0f, false);
            var neatFactor = 0.45f + sim.Neat * 0.0011f;
            if (sim.Neat < 250 && room > -15 && classified.ObjectKind != SmartObjectKind.FloodOrPuddle)
                return new(0f, false);
            var baseChore = classified.ObjectKind switch
            {
                SmartObjectKind.FloodOrPuddle => 195f,
                SmartObjectKind.DirtyDish => 155f,
                SmartObjectKind.TrashOrAsh => 150f,
                SmartObjectKind.PlantOrGarden => 120f,
                _ => classified.ActionKind == SmartActionKind.MakeBed ? 95f : 115f,
            };
            return new(baseChore * neatFactor * (room < 0 ? 1.35f : 1f) * distPenalty, false);
        }

        if (classified.ActionKind == SmartActionKind.CareForPet && !awayLot)
            return new(230f * distPenalty, false);

        var survivalHealthy = energy > -25 && hunger > -25 && bladder > -25 && hygiene > -35;

        if (classified.ActionKind == SmartActionKind.StudySchool && sim.Child && settings.SparksAndTurfWars && survivalHealthy)
        {
            var perf = sim.Career?.JobPerformance ?? 0;
            if (perf < 65 && hour is >= 7 and <= 21 && minutesToShift is null or > 45)
            {
                var gradeNeed = Math.Clamp((75 - perf) / 50f, 0.4f, 1.8f);
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.StudySchool);
                return new(185f * gradeNeed * novelty * distPenalty, false, BalloonCue.CareerScheme);
            }
        }

        if (classified.ActionKind is SmartActionKind.TrainSkill or SmartActionKind.PlayInstrument && settings.SparksAndTurfWars && survivalHealthy && !awayLot)
        {
            var (skillBonus, _) = EvaluateSkillDrive(sim, classified.TrainedSkills);
            if (skillBonus > 0f && fun > -35)
            {
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.TrainSkill);
                var traitFit = SkillPersonalityFit(sim, classified.TrainedSkills);
                return new((110f + skillBonus) * traitFit * novelty * distPenalty, false, BalloonCue.CareerScheme);
            }
        }

        if (targetSim is not null || classified.ActionKind == SmartActionKind.PhoneCallFriend)
        {
            if (energy < -55 || hunger < -55 || bladder < -50)
                return new(0f, false);

            var friendsGap = settings.SparksAndTurfWars && sim.Career is { } car
                ? Math.Max(0, car.FriendsRequired - car.FamilyFriends)
                : 0;

            if (classified.ActionKind == SmartActionKind.PhoneCallFriend)
            {
                if (awayLot || hour is < 8 or >= 22)
                    return new(0f, false);
                var socialNeed = NeedUrgency(social, -55, 0, friendsGap > 0 ? 55 : 20);
                if (socialNeed <= 0.05f && friendsGap == 0)
                    return new(0f, false);
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.PhoneCallFriend);
                return new((75f + socialNeed * 165f) * (friendsGap > 0 ? 1.55f : 1f) * novelty * distPenalty, false);
            }

            if (targetSim is null || targetSim.Asleep || targetSim.AtWorkOrSchool)
                return new(0f, false);
            if (targetSim.CurrentAction is { } targetAct &&
                InteractionClassifier.ContainsAny(targetAct.EnglishName ?? targetAct.Name, "toilet", "shower", "bath", "sleep"))
            {
                return new(0f, false);
            }

            relByObjectId.TryGetValue(targetSim.ObjectId, out var rel);
            var daily = rel?.Daily ?? 0;
            var lifetime = rel?.Lifetime ?? 0;
            var isRomantic = rel is { Love: true } or { Crush: true } || (daily >= 70 && lifetime >= 50 && !sim.Child && !targetSim.Child);

            if (classified.ActionKind == SmartActionKind.GreetVisitor && !targetSim.Greeted && targetSim.Visitor && hour is >= 7 and <= 22)
                return new(380f * (0.8f + sim.Outgoing * 0.0005f) * distPenalty, false, BalloonCue.TargetObject, targetSim.ObjectId);

            if (classified.ActionKind == SmartActionKind.SocialRomantic)
            {
                if (sim.Child || targetSim.Child || !isRomantic || daily < 55)
                    return new(0f, false);
                var novelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, SmartActionKind.SocialRomantic);
                return new((135f + NeedUrgency(social, -50, 20, 80) * 140f) * novelty * distPenalty, false, BalloonCue.CrushShot, targetSim.ObjectId);
            }

            if (classified.ActionKind == SmartActionKind.SocialHostile)
                return new(0f, false);

            var socialUrgency = NeedUrgency(social, -55, 10, 70);
            var friendBoost = friendsGap > 0 && !targetSim.Household && !targetSim.Npc && !targetSim.Dog && !targetSim.Cat && daily is >= 15 and < 55 ? 1.65f : 1f;
            var socNovelty = blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, classified.ActionKind);
            return new((65f + socialUrgency * 195f) * (0.72f + sim.Outgoing * 0.00065f) * friendBoost * socNovelty * distPenalty, social < -60, BalloonCue.TargetObject, targetSim.ObjectId);
        }

        var dFun2 = Math.Max(0f, InteractionClassifier.Delta(cand.MotiveDeltas, InteractionClassifier.MotiveFun));
        var dComfort2 = Math.Max(0f, InteractionClassifier.Delta(cand.MotiveDeltas, InteractionClassifier.MotiveComfort));
        var leisureVal = NeedUrgency(fun, -50, 10, 75) * (45f + dFun2 * 1.4f + leadObj.RatingFun * 6f)
            + NeedUrgency(comfort, -45, 5, 60) * (25f + dComfort2 * 1.1f + leadObj.RatingComfort * 5f);
        leisureVal *= blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, classified.ActionKind);
        if (leisureVal <= 5f)
            leisureVal = Math.Max(0f, cand.AdjustedScore * 12f) * blackboard.NoveltyFactor(sim.ObjectId, leadObj.Guid, leadObj.ObjectId, classified.ActionKind);
        return new(leisureVal * distPenalty * sameLevelBonus, false);
    }

    public void AdvanceProactiveDirector(IPluginSimulation lot, SmartSettings settings, long update)
    {
        currentTick = update;
        balloons.AdvanceTicks(lot, settings.Enabled && settings.ThoughtBubbles, update);

        if (!settings.Enabled || lot.Paused || !lot.FreeWill || update % 12 != 0)
            return;

        var allSims = lot.AllSims;
        if (allSims.Count == 0)
            return;

        var allObjects = lot.Objects;
        var objectsById = allObjects.ToDictionary(o => o.ObjectId);
        blackboard.SyncWorld(lot.House, lot.Hours, lot.Minutes, allSims, objectsById, lot);

        var fireOnLot = allObjects.Any(o => o.ObjectId == o.LeadObjectId &&
            InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.Fire);

        foreach (var sim in allSims)
        {
            if (!sim.Household || sim.Npc || sim.Dog || sim.Cat || sim.AtWorkOrSchool)
                continue;
            if (HouseholdBlackboard.HasPlayerCommand(sim))
                continue;

            if (sim.CurrentAction is { Autonomous: true })
            {
                TryPreemptOrTelegraphAutonomousLoop(lot, settings, sim, allSims, allObjects, objectsById, fireOnLot);
                continue;
            }

            if (sim.CurrentAction is not null || sim.ActionQueue.Count > 0 || sim.Asleep)
                continue;

            var minGap = settings.IsDrama ? 1 : 2;
            if (lastProactiveQueueMinute.TryGetValue(sim.ObjectId, out var lastMin) && blackboard.NowMinutes - lastMin < minGap)
                continue;

            if (TryDispatchProactiveGoal(lot, settings, sim, allSims, allObjects, objectsById, fireOnLot))
                lastProactiveQueueMinute[sim.ObjectId] = blackboard.NowMinutes;
        }
    }

    private void TryPreemptOrTelegraphAutonomousLoop(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile sim,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginObject> allObjects,
        IReadOnlyDictionary<short, PluginObject> objectsById,
        bool fireOnLot)
    {
        if (sim.NonInterruptible || sim.Asleep || sim.CurrentAction is not { Autonomous: true } cur)
            return;

        if (!objectsById.TryGetValue(cur.TargetObjectId, out var targetObj))
            return;
        var leadObj = objectsById.GetValueOrDefault(targetObj.LeadObjectId, targetObj);
        var targetIsSim = allSims.Any(s => s.ObjectId == leadObj.ObjectId);
        var currentClass = InteractionClassifier.Classify(leadObj, targetIsSim, cur.Name, cur.EnglishName, false, []);

        var engrossingLoop = currentClass.ActionKind is SmartActionKind.Leisure or SmartActionKind.PlayComputerOrArcade or
            SmartActionKind.WatchTv or SmartActionKind.DanceToMusic or SmartActionKind.PlayInstrument or
            SmartActionKind.JoinGroupActivity or SmartActionKind.UseHotTub or SmartActionKind.TrainSkill or
            SmartActionKind.StudySchool or SmartActionKind.SitOrRelax or SmartActionKind.Nap or
            SmartActionKind.SocialFriendly or SmartActionKind.SocialPlayful or SmartActionKind.SocialRomantic;

        if (!engrossingLoop)
            return;

        var bladder = sim.Motives[InteractionClassifier.MotiveBladder];
        var hunger = sim.Motives[InteractionClassifier.MotiveHunger];
        var energy = sim.Motives[InteractionClassifier.MotiveEnergy];

        var nearestToilet = allObjects
            .Where(o => o.ObjectId == o.LeadObjectId && InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.Toilet)
            .OrderBy(o => TileDist(sim, o))
            .FirstOrDefault();

        if (settings.IsDrama && bladder is <= -65 and > -89)
        {
            balloons.TryEmitHoldItHubris(lot, settings.ThoughtBubbles, sim.ObjectId, nearestToilet?.ObjectId, blackboard.NowMinutes, currentTick);
        }

        if (lastInterruptMinute.TryGetValue(sim.ObjectId, out var lastInt) && blackboard.NowMinutes - lastInt < 12)
            return;

        var vehicleWaiting = !lot.AwayLot &&
            !(settings.IsDrama && sim.Active <= 250 && energy < -65) &&
            allObjects.Any(o =>
                o.ObjectId == o.LeadObjectId &&
                InteractionClassifier.ClassifyObject(o, false) == (sim.Child ? SmartObjectKind.SchoolBus : SmartObjectKind.Carpool) &&
                SafeInteractions(lot, sim.ObjectId, o.ObjectId).Count > 0);

        var criticalBladder = settings.IsDrama ? bladder <= -89 : bladder < -58;
        var criticalHunger = settings.IsDrama ? hunger <= -86 : hunger < -65;
        var criticalEnergy = (settings.IsDrama ? energy <= -88 : energy < -75) && currentClass.ActionKind != SmartActionKind.Nap;

        if (fireOnLot || vehicleWaiting || criticalBladder || criticalHunger || criticalEnergy)
        {
            if (lot.TryCancelAutonomousAction(sim.ObjectId))
            {
                lastInterruptMinute[sim.ObjectId] = blackboard.NowMinutes;
                blackboard.ReleaseClaimsForSim(sim.ObjectId);
                if (criticalBladder)
                {
                    var hogger = blackboard.FindToiletOccupantSimId(sim.ObjectId, allSims, allObjects, objectsById);
                    var panicBeat = hogger.HasValue
                        ? new BalloonBeat(PluginBalloonStyle.Scream, TargetObjectId: hogger.Value, CrossedOut: true, DurationTicks: 84)
                        : nearestToilet is not null
                            ? new BalloonBeat(PluginBalloonStyle.Scream, TargetObjectId: nearestToilet.ObjectId, DurationTicks: 84)
                            : new BalloonBeat(PluginBalloonStyle.Scream, SpriteId: BalloonDirector.SpriteBladder, DurationTicks: 84);
                    balloons.EmitSingle(lot, settings.ThoughtBubbles, sim.ObjectId, panicBeat, currentTick, minGapTicks: 20);
                }
            }
        }
    }

    private bool TryDispatchProactiveGoal(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile sim,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginObject> allObjects,
        IReadOnlyDictionary<short, PluginObject> objectsById,
        bool fireOnLot)
    {
        if (fireOnLot)
            return false;

        var leadObjects = allObjects.Where(o => o.ObjectId == o.LeadObjectId).ToArray();
        var awayLot = lot.AwayLot;

        if (!awayLot && !(settings.IsDrama && sim.Active <= 250 && sim.Motives[InteractionClassifier.MotiveEnergy] < -65))
        {
            var desiredVehicle = sim.Child ? SmartObjectKind.SchoolBus : SmartObjectKind.Carpool;
            foreach (var vehicle in leadObjects.Where(o => InteractionClassifier.ClassifyObject(o, false) == desiredVehicle))
            {
                if (TryQueueMatching(lot, settings, sim, vehicle, static (_, kind) => kind is SmartActionKind.BoardCarpool or SmartActionKind.BoardSchoolBus,
                        BalloonCue.TargetObject))
                    return true;
            }
        }

        if (!awayLot && !sim.Child)
        {
            foreach (var crib in leadObjects.Where(o => InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.BabyCrib))
            {
                if (blackboard.IsClaimedByAnotherSim(sim.ObjectId, crib, SmartObjectKind.BabyCrib, false, allSims, objectsById))
                    continue;
                if (TryQueueMatching(lot, settings, sim, crib, static (_, kind) => kind == SmartActionKind.CareForBaby, BalloonCue.TargetObject))
                    return true;
            }
        }

        if (settings.IsDrama && settings.SparksAndTurfWars && TryDispatchWitnessReaction(lot, settings, sim, allSims, objectsById))
            return true;

        var panicThreshold = settings.IsDrama ? -82 : -48;
        if (sim.Motives[InteractionClassifier.MotiveBladder] <= panicThreshold ||
            sim.Motives[InteractionClassifier.MotiveHunger] <= panicThreshold ||
            sim.Motives[InteractionClassifier.MotiveEnergy] <= panicThreshold)
        {
            return false;
        }

        if (!awayLot && lot.Hours is >= 7 and <= 22)
        {
            var ungreetedVisitor = allSims.FirstOrDefault(v =>
                v.Visitor && !v.Greeted && !v.Dog && !v.Cat &&
                !blackboard.IsBackedOff(sim.ObjectId, v.ObjectId));
            if (ungreetedVisitor is not null && objectsById.TryGetValue(ungreetedVisitor.ObjectId, out var visitorObj) &&
                !blackboard.IsClaimedByAnotherSim(sim.ObjectId, visitorObj, SmartObjectKind.Person, false, allSims, objectsById))
            {
                if (TryQueueMatching(lot, settings, sim, visitorObj,
                        static (entry, kind) => kind == SmartActionKind.GreetVisitor ||
                            InteractionClassifier.ContainsAny(entry.EnglishName ?? entry.Name, "greet"),
                        BalloonCue.TargetObject, ungreetedVisitor.ObjectId))
                {
                    return true;
                }
            }
        }

        if (settings.IsDrama)
            return TryDispatchDramaBeat(lot, settings, sim, allSims, leadObjects, objectsById);

        return TryDispatchMastermindBeat(lot, settings, sim, allSims, allObjects, leadObjects, objectsById);
    }

    private bool TryDispatchWitnessReaction(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile witness,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        if (blackboard.TryClaimNextWitnessEvent(witness) is not { } drama)
            return false;

        if (drama.Kind == DramaEventKind.BladderAccident && witness.Neat >= 700 &&
            drama.RelatedObjectId is { } puddleId && objectsById.TryGetValue(puddleId, out var puddleObj))
        {
            if (TryQueueMatching(lot, settings, witness, puddleObj, static (_, kind) => kind == SmartActionKind.CleanOrDispose,
                    BalloonCue.None))
            {
                balloons.EmitSequence(
                    lot,
                    settings.ThoughtBubbles,
                    witness.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Scream, TargetObjectId: drama.SubjectSimId != 0 ? drama.SubjectSimId : puddleId, CrossedOut: true, DurationTicks: 54),
                    new BalloonBeat(PluginBalloonStyle.Thought, SpriteId: BalloonDirector.SpriteSmell, DurationTicks: 64),
                    currentTick,
                    minGapTicks: 20);
                return true;
            }
        }

        if (drama.SubjectSimId == 0 || !objectsById.TryGetValue(drama.SubjectSimId, out var subjectObj))
            return false;

        var isSweet = witness.Nice >= 600;
        var queued = TryQueueMatching(
            lot,
            settings,
            witness,
            subjectObj,
            (entry, kind) =>
            {
                var label = entry.EnglishName ?? entry.Name;
                if (isSweet)
                    return InteractionClassifier.ContainsAny(label, "cheer", "compliment", "hug", "talk") || kind == SmartActionKind.SocialFriendly;
                return InteractionClassifier.ContainsAny(label, "tease", "brag", "joke", "entertain", "laugh", "insult") ||
                       kind is SmartActionKind.SocialPlayful or SmartActionKind.SocialHostile;
            },
            BalloonCue.None);

        if (queued)
        {
            var secondBeat = isSweet
                ? new BalloonBeat(PluginBalloonStyle.Thought, SpriteId: BalloonDirector.SpriteCheerUp, DurationTicks: 68)
                : new BalloonBeat(PluginBalloonStyle.Speech, TargetObjectId: drama.SubjectSimId, DurationTicks: 72);
            balloons.EmitSequence(
                lot,
                settings.ThoughtBubbles,
                witness.ObjectId,
                new BalloonBeat(PluginBalloonStyle.Scream, SpriteId: BalloonDirector.SpriteSurprise, DurationTicks: 46),
                secondBeat,
                currentTick,
                minGapTicks: 20);
            return true;
        }

        return false;
    }

    private bool TryDispatchDramaBeat(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile sim,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginObject> leadObjects,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        if (settings.SparksAndTurfWars && !sim.Child)
        {
            var rels = SafeRelationships(lot, sim.ObjectId);
            foreach (var rel in rels.OrderByDescending(r => (r.Crush || r.Love ? 50 : 0) + r.Daily - r.ReverseDaily))
            {
                if (rel.TargetObjectId is not { } targetId)
                    continue;
                var targetSim = allSims.FirstOrDefault(s => s.ObjectId == targetId && !s.Asleep && !s.AtWorkOrSchool && !s.Child);
                if (targetSim is null || !AllowsRomanticTarget(sim, targetSim))
                    continue;
                var crushThreshold = (sim.Outgoing >= 650 || sim.RomanceInterest >= 60) ? 24 : 36;
                if (!rel.Crush && !rel.Love && rel.Daily < crushThreshold)
                    continue;
                if (!objectsById.TryGetValue(targetId, out var targetObj) ||
                    blackboard.NoveltyFactor(sim.ObjectId, targetObj.Guid, targetObj.ObjectId, SmartActionKind.SocialRomantic) < 0.5f)
                    continue;

                if (TryQueueMatching(lot, settings, sim, targetObj, static (_, kind) => kind == SmartActionKind.SocialRomantic,
                        BalloonCue.CrushShot, targetId))
                    return true;
            }
        }

        if ((sim.Outgoing >= 650 || sim.Playful >= 650) && lot.Hours is >= 8 and <= 23)
        {
            foreach (var stereo in leadObjects.Where(o => InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.Stereo && o.RepairState == 0))
            {
                if (HouseholdBlackboard.IsStereoPlaying(stereo, allSims, objectsById))
                {
                    if (blackboard.NoveltyFactor(sim.ObjectId, stereo.Guid, stereo.ObjectId, SmartActionKind.DanceToMusic) >= 0.5f &&
                        TryQueueMatching(lot, settings, sim, stereo, static (_, kind) => kind == SmartActionKind.DanceToMusic, BalloonCue.MusicParty))
                        return true;
                }
                else if (blackboard.NoveltyFactor(sim.ObjectId, stereo.Guid, stereo.ObjectId, SmartActionKind.TurnOnMedia) >= 0.5f &&
                         TryQueueMatching(lot, settings, sim, stereo, static (_, kind) => kind == SmartActionKind.TurnOnMedia, BalloonCue.MusicParty))
                {
                    return true;
                }
            }
        }

        if (sim.Neat >= 700 && !lot.AwayLot)
        {
            foreach (var mess in leadObjects
                .Where(o => InteractionClassifier.ClassifyObject(o, false) is SmartObjectKind.FloodOrPuddle or SmartObjectKind.DirtyDish or SmartObjectKind.TrashOrAsh)
                .OrderBy(o => TileDist(sim, o)))
            {
                if (blackboard.IsClaimedByAnotherSim(sim.ObjectId, mess, SmartObjectKind.General, false, allSims, objectsById))
                    continue;
                if (TryQueueMatching(lot, settings, sim, mess, static (_, kind) => kind == SmartActionKind.CleanOrDispose, BalloonCue.NeatRageClean))
                    return true;
            }
        }

        var preferredObjects = leadObjects
            .Where(o => o.RepairState == 0 && !blackboard.IsBackedOff(sim.ObjectId, o.ObjectId))
            .Select(o => (Obj: o, Kind: InteractionClassifier.ClassifyObject(o, false)))
            .Where(x =>
                (sim.Playful >= 650 && x.Kind == SmartObjectKind.ComputerOrArcade) ||
                (sim.Active <= 300 && x.Kind == SmartObjectKind.Television) ||
                (sim.Active >= 700 && ((x.Obj.SkillFlags & (int)SkillMask.Body) != 0 || InteractionClassifier.ContainsAny(x.Obj.Name, "pool", "basket"))) ||
                (sim.Playful <= 300 && ((x.Obj.SkillFlags & (int)(SkillMask.Logic | SkillMask.Creativity)) != 0)))
            .OrderBy(x => TileDist(sim, x.Obj));

        foreach (var (obsObj, obsKind) in preferredObjects)
        {
            if (blackboard.IsClaimedByAnotherSim(sim.ObjectId, obsObj, obsKind, false, allSims, objectsById))
                continue;
            if (blackboard.NoveltyFactor(sim.ObjectId, obsObj.Guid, obsObj.ObjectId, SmartActionKind.Leisure) < 0.5f)
                continue;
            if (TryQueueMatching(
                    lot,
                    settings,
                    sim,
                    obsObj,
                    static (_, kind) => kind is SmartActionKind.PlayComputerOrArcade or SmartActionKind.WatchTv or
                        SmartActionKind.TrainSkill or SmartActionKind.PlayInstrument or SmartActionKind.Leisure,
                    BalloonCue.TargetObject))
            {
                return true;
            }
        }

        return false;
    }

    private bool TryDispatchMastermindBeat(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile sim,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginObject> allObjects,
        IReadOnlyList<PluginObject> leadObjects,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        var awayLot = lot.AwayLot;
        var minutesToShift = MinutesUntilWorkOrSchool(sim, lot.Hours, lot.Minutes, awayLot);

        if (settings.SparksAndTurfWars && !awayLot && !sim.Child && minutesToShift is null or > 50)
        {
            blackboard.IsMealBeingPreparedOrReady(sim.ObjectId, allSims, allObjects, objectsById,
                out var readyFood, out var someoneCooking);
            var hungryFamily = allSims.Count(s => s.Household && !s.Dog && !s.Cat && !s.AtWorkOrSchool &&
                s.Motives[InteractionClassifier.MotiveHunger] < 20);
            var mealWindow = lot.Hours is >= 6 and <= 9 or >= 11 and <= 14 or >= 17 and <= 21;

            if (!readyFood && !someoneCooking && hungryFamily >= 2 &&
                (mealWindow || allSims.Any(s => s.Household && s.Motives[InteractionClassifier.MotiveHunger] < -25)) &&
                blackboard.IsBestAvailableHouseholdChef(sim, allSims))
            {
                foreach (var fridge in leadObjects
                    .Where(o => InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.Fridge)
                    .OrderByDescending(o => o.RatingHunger)
                    .ThenBy(o => TileDist(sim, o)))
                {
                    if (blackboard.IsClaimedByAnotherSim(sim.ObjectId, fridge, SmartObjectKind.Fridge, false, allSims, objectsById))
                        continue;
                    if (TryQueueMatching(lot, settings, sim, fridge,
                            static (entry, kind) => kind == SmartActionKind.PrepareGroupMeal ||
                                InteractionClassifier.ContainsAny(entry.EnglishName ?? entry.Name, "serve"),
                            BalloonCue.TargetObject))
                    {
                        return true;
                    }
                }
            }

            if (lot.HouseholdFunds >= 250 && lot.Hours is >= 8 and <= 20)
            {
                foreach (var billObj in leadObjects.Where(o => InteractionClassifier.ClassifyObject(o, false) is SmartObjectKind.Bills or SmartObjectKind.Mailbox))
                {
                    if (blackboard.IsClaimedByAnotherSim(sim.ObjectId, billObj, SmartObjectKind.Bills, false, allSims, objectsById))
                        continue;
                    if (TryQueueMatching(lot, settings, sim, billObj,
                            static (_, kind) => kind is SmartActionKind.PayBills or SmartActionKind.GetMail,
                            BalloonCue.TargetObject))
                    {
                        return true;
                    }
                }
            }
        }

        var greenForGrowth = sim.Motives[InteractionClassifier.MotiveEnergy] > -5 &&
                             sim.Motives[InteractionClassifier.MotiveHunger] > -10 &&
                             sim.Motives[InteractionClassifier.MotiveBladder] > -10 &&
                             sim.Motives[InteractionClassifier.MotiveHygiene] > -20 &&
                             sim.Motives[InteractionClassifier.MotiveFun] > -15 &&
                             minutesToShift is null or > 55;

        if (settings.SparksAndTurfWars && !awayLot && greenForGrowth && !sim.Child)
        {
            var (neededMask, _) = TopNeededSkill(sim);
            if (neededMask != SkillMask.None)
            {
                foreach (var skillObj in leadObjects
                    .Where(o => (o.SkillFlags & (int)neededMask) != 0 && o.RepairState == 0)
                    .OrderByDescending(o => SkillPersonalityFit(sim, neededMask))
                    .ThenBy(o => TileDist(sim, o)))
                {
                    if (blackboard.IsBackedOff(sim.ObjectId, skillObj.ObjectId) ||
                        blackboard.IsClaimedByAnotherSim(sim.ObjectId, skillObj, SmartObjectKind.SkillObject, false, allSims, objectsById))
                        continue;
                    if (blackboard.NoveltyFactor(sim.ObjectId, skillObj.Guid, skillObj.ObjectId, SmartActionKind.TrainSkill) < 0.35f)
                        continue;
                    if (TryQueueMatching(lot, settings, sim, skillObj,
                            (entry, _) => (InteractionClassifier.InferSkills(skillObj, entry.EnglishName ?? entry.Name) & neededMask) != 0,
                            BalloonCue.CareerScheme))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    private bool TryQueueMatching(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile sim,
        PluginObject targetObj,
        Func<PluginInteraction, SmartActionKind, bool> predicate,
        BalloonCue cue,
        short? secondaryId = null)
    {
        var interactions = SafeInteractions(lot, sim.ObjectId, targetObj.ObjectId);
        foreach (var entry in interactions)
        {
            if (blackboard.IsPlayerVetoed(sim.ObjectId, targetObj.LeadObjectId, entry.Id))
                continue;
            var classified = InteractionClassifier.Classify(
                targetObj,
                secondaryId == targetObj.LeadObjectId,
                entry.Name,
                entry.EnglishName,
                entry.Joinable,
                entry.MotiveDeltas);
            if (!predicate(entry, classified.ActionKind))
                continue;
            if (lot.TryQueueAutonomousInteraction(sim.ObjectId, targetObj.ObjectId, entry.Id, entry.Param0))
            {
                blackboard.RecordClaim(sim.ObjectId, targetObj.LeadObjectId, classified.ActionKind, ClaimDurationFor(classified.ActionKind));
                EmitSelectionBalloon(lot, settings, sim, targetObj.LeadObjectId, classified.ActionKind, cue, secondaryId, null);
                return true;
            }
        }
        return false;
    }

    private void EmitSelectionBalloon(
        IPluginSimulation lot,
        SmartSettings settings,
        PluginSimProfile sim,
        short targetLeadId,
        SmartActionKind kind,
        BalloonCue cue,
        short? secondaryId,
        short? nearestToiletId)
    {
        if (!settings.ThoughtBubbles || cue == BalloonCue.None)
            return;

        switch (cue)
        {
            case BalloonCue.PanicToilet:
                balloons.EmitSingle(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Scream, TargetObjectId: targetLeadId, DurationTicks: 84),
                    currentTick,
                    minGapTicks: 25);
                break;

            case BalloonCue.HoldItThenTarget:
            {
                var first = nearestToiletId.HasValue
                    ? new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: nearestToiletId.Value, CrossedOut: true, DurationTicks: 52)
                    : new BalloonBeat(PluginBalloonStyle.Thought, SpriteId: BalloonDirector.SpriteBladder, CrossedOut: true, DurationTicks: 52);
                balloons.EmitSequence(
                    lot,
                    true,
                    sim.ObjectId,
                    first,
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 68),
                    currentTick,
                    minGapTicks: 55);
                break;
            }

            case BalloonCue.CrushShot:
                balloons.EmitSequence(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Thought, SpriteId: BalloonDirector.SpriteCrush, DurationTicks: 48),
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: secondaryId ?? targetLeadId, DurationTicks: 72),
                    currentTick,
                    minGapTicks: 50);
                break;

            case BalloonCue.TurfWar:
                balloons.EmitSequence(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: secondaryId ?? targetLeadId, CrossedOut: true, DurationTicks: 52),
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 66),
                    currentTick,
                    minGapTicks: 50);
                break;

            case BalloonCue.HostileSpark:
                balloons.EmitSequence(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: secondaryId ?? targetLeadId, CrossedOut: true, DurationTicks: 48),
                    new BalloonBeat(PluginBalloonStyle.Scream, SpriteId: BalloonDirector.SpriteSlap, DurationTicks: 64),
                    currentTick,
                    minGapTicks: 50);
                break;

            case BalloonCue.HubrisIdea:
                balloons.EmitSequence(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Thought, SpriteId: BalloonDirector.SpriteIdea, DurationTicks: 46),
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 68),
                    currentTick,
                    minGapTicks: 55);
                break;

            case BalloonCue.RefuseTvThenTarget:
                if (secondaryId.HasValue)
                {
                    balloons.EmitSequence(
                        lot,
                        true,
                        sim.ObjectId,
                        new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: secondaryId.Value, CrossedOut: true, DurationTicks: 46),
                        new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 68),
                        currentTick,
                        minGapTicks: 65);
                }
                else
                {
                    balloons.EmitSingle(lot, true, sim.ObjectId, new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 68), currentTick);
                }
                break;

            case BalloonCue.NeatRageClean:
                balloons.EmitSequence(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Scream, SpriteId: BalloonDirector.SpriteSmell, DurationTicks: 48),
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 64),
                    currentTick,
                    minGapTicks: 55);
                break;

            case BalloonCue.MusicParty:
                balloons.EmitSequence(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Thought, SpriteId: BalloonDirector.SpriteMusic, DurationTicks: 44),
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 64),
                    currentTick,
                    minGapTicks: 60);
                break;

            case BalloonCue.CareerScheme:
            {
                var badge = sim.Career is { IsSchool: false, JobType: > 0 } car
                    ? BalloonDirector.CareerSpriteForJobType(car.JobType)
                    : BalloonDirector.SpriteIdea;
                balloons.EmitSequence(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Thought, SpriteId: badge, DurationTicks: 48),
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 66),
                    currentTick,
                    minGapTicks: 65);
                break;
            }

            case BalloonCue.SleepBed:
                balloons.EmitSingle(
                    lot,
                    true,
                    sim.ObjectId,
                    new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: targetLeadId, DurationTicks: 70),
                    currentTick,
                    minGapTicks: 75);
                break;

            default:
                if (kind is not (SmartActionKind.SitOrRelax or SmartActionKind.WashHandsOrBrush))
                {
                    balloons.EmitSingle(
                        lot,
                        true,
                        sim.ObjectId,
                        new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: secondaryId ?? targetLeadId, DurationTicks: 66),
                        currentTick,
                        minGapTicks: 75);
                }
                break;
        }
    }

    private int? SelectPetCandidate(
        PluginSimProfile pet,
        PluginAutonomyContext context,
        IReadOnlyList<PluginAutonomyCandidate> candidates,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        var bestIdx = -1;
        var bestScore = 0f;
        for (var i = 0; i < candidates.Count; i++)
        {
            var cand = candidates[i];
            if (cand.BlockedByPlugin) continue;
            var leadId = objectsById.TryGetValue(cand.ObjectId, out var o) ? o.LeadObjectId : cand.ObjectId;
            if (blackboard.IsBackedOff(pet.ObjectId, leadId)) continue;
            var score = Math.Max(0.05f, cand.AdjustedScore) * blackboard.NoveltyFactor(pet.ObjectId, cand.ObjectGuid, leadId, SmartActionKind.General);
            if (pet.Motives[InteractionClassifier.MotiveHunger] < -40 && InteractionClassifier.Delta(cand.MotiveDeltas, InteractionClassifier.MotiveHunger) > 15f)
                score += 120f;
            if (pet.Motives[InteractionClassifier.MotiveBladder] < -40 && InteractionClassifier.Delta(cand.MotiveDeltas, InteractionClassifier.MotiveBladder) > 15f)
                score += 120f;
            if (pet.Motives[InteractionClassifier.MotiveEnergy] < -50 && InteractionClassifier.Delta(cand.MotiveDeltas, InteractionClassifier.MotiveEnergy) > 15f)
                score += 100f;
            if (score > bestScore)
            {
                bestScore = score;
                bestIdx = i;
            }
        }
        if (bestIdx < 0)
            return context.RandomSeed == 0 ? -1 : null;
        return bestIdx;
    }

    private static bool AllowsRomanticTarget(PluginSimProfile sim, PluginSimProfile target)
    {
        if (sim.FemalePreference == 0 && sim.MalePreference == 0)
            return true;
        return target.Gender != 0
            ? sim.FemalePreference >= 0 && (sim.FemalePreference > 0 || sim.MalePreference <= 0)
            : sim.MalePreference >= 0 && (sim.MalePreference > 0 || sim.FemalePreference <= 0);
    }

    private static IReadOnlyList<PluginInteraction> SafeInteractions(IPluginSimulation lot, short simId, short objectId)
    {
        try { return lot.GetInteractions(simId, objectId); }
        catch { return []; }
    }

    private static IReadOnlyList<PluginSimRelationship> SafeRelationships(IPluginSimulation lot, short simId)
    {
        try { return lot.GetRelationships(simId); }
        catch { return []; }
    }

    public static int? MinutesUntilWorkOrSchool(PluginSimProfile sim, int hour, int minute, bool awayLot)
    {
        if (awayLot || sim.AtWorkOrSchool || sim.Career is not { StartHour: { } startHour })
            return null;
        if (!sim.Child && sim.Career.JobType == 0)
            return null;
        var nowMins = hour * 60 + minute;
        var startMins = startHour * 60;
        var diff = startMins - nowMins;
        if (diff < 0)
            diff += 1440;
        return diff is >= 0 and <= 240 ? diff : null;
    }

    public static bool IsSleepHoursForSim(PluginSimProfile sim, int hour, int? minutesToShift, bool awayLot)
    {
        if (awayLot)
            return false;
        if (minutesToShift is <= 90)
            return false;
        if (sim.Career is { IsSchool: false, StartHour: { } startHour } && sim.Career.JobType != 0)
        {
            var preShiftBedStart = (startHour - 9 + 24) % 24;
            var preShiftWake = (startHour - 2 + 24) % 24;
            if (InHourWindow(hour, preShiftBedStart, preShiftWake))
                return true;
        }
        return sim.Child
            ? (hour >= 21 || hour < 6)
            : (hour >= 22 || hour < 6);
    }

    private static bool InHourWindow(int hour, int start, int end) =>
        start <= end ? (hour >= start && hour < end) : (hour >= start || hour < end);

    private static float NeedUrgency(short value, int criticalBelow, int moderateBelow, int topOffBelow)
    {
        if (value >= topOffBelow)
            return 0f;
        if (value <= criticalBelow)
            return 2.2f + (criticalBelow - value) * 0.03f;
        if (value <= moderateBelow)
        {
            var t = (float)(moderateBelow - value) / Math.Max(1, moderateBelow - criticalBelow);
            return 0.75f + t * 1.45f;
        }
        var mild = (float)(topOffBelow - value) / Math.Max(1, topOffBelow - moderateBelow);
        return 0.12f + mild * 0.63f;
    }

    private static (float Bonus, string Label) EvaluateSkillDrive(PluginSimProfile sim, SkillMask trained)
    {
        var mask = trained & ~SkillMask.Study;
        if (mask == SkillMask.None)
            return (0f, "a hobby");

        var current = new[] { sim.Cooking, sim.Mechanical, sim.Charisma, sim.Body, sim.Logic, sim.Creativity };
        var masks = new[] { SkillMask.Cooking, SkillMask.Mechanical, SkillMask.Charisma, SkillMask.Body, SkillMask.Logic, SkillMask.Creativity };
        var names = new[] { "Cooking", "Mechanical", "Charisma", "Body", "Logic", "Creativity" };
        var reqs = sim.Career?.SkillRequirements;

        float bestBonus = 0f;
        string bestName = "a skill";

        for (var i = 0; i < 6; i++)
        {
            if ((mask & masks[i]) == 0 || current[i] >= 1000)
                continue;

            var req = reqs is not null && i < reqs.Length ? reqs[i] : (short)0;
            var deficit = req - current[i];
            float score;
            if (deficit > 0)
                score = 135f + Math.Min(120f, deficit * 0.35f);
            else if (i == 0 && current[0] < 200)
                score = 75f;
            else if (i == 1 && current[1] < 350)
                score = 60f;
            else
                score = 22f * (1f - current[i] / 1000f);

            if (score > bestBonus)
            {
                bestBonus = score;
                bestName = names[i];
            }
        }

        return (bestBonus, bestName);
    }

    private static (SkillMask Mask, string Label) TopNeededSkill(PluginSimProfile sim)
    {
        var current = new[] { sim.Cooking, sim.Mechanical, sim.Charisma, sim.Body, sim.Logic, sim.Creativity };
        var masks = new[] { SkillMask.Cooking, SkillMask.Mechanical, SkillMask.Charisma, SkillMask.Body, SkillMask.Logic, SkillMask.Creativity };
        var names = new[] { "Cooking", "Mechanical", "Charisma", "Body", "Logic", "Creativity" };
        var reqs = sim.Career?.SkillRequirements;

        if (reqs is { Length: >= 6 })
        {
            var bestIdx = -1;
            var bestDeficit = 0;
            for (var i = 0; i < 6; i++)
            {
                var deficit = reqs[i] - current[i];
                if (deficit > bestDeficit)
                {
                    bestDeficit = deficit;
                    bestIdx = i;
                }
            }
            if (bestIdx >= 0)
                return (masks[bestIdx], names[bestIdx]);
        }

        if (sim.Cooking < 200)
            return (SkillMask.Cooking, "Cooking");
        if (sim.Mechanical < 350 && sim.Neat >= 400)
            return (SkillMask.Mechanical, "Mechanical");

        return (SkillMask.None, "");
    }

    private static float SkillPersonalityFit(PluginSimProfile sim, SkillMask mask)
    {
        float fit = 1f;
        if ((mask & SkillMask.Body) != 0)
            fit *= 0.72f + sim.Active * 0.00065f;
        if ((mask & SkillMask.Charisma) != 0)
            fit *= 0.75f + sim.Outgoing * 0.00055f;
        if ((mask & SkillMask.Logic) != 0)
            fit *= 0.80f + (1000 - sim.Playful) * 0.00045f;
        if ((mask & SkillMask.Creativity) != 0)
            fit *= 0.82f + sim.Playful * 0.00040f;
        if ((mask & (SkillMask.Cooking | SkillMask.Mechanical)) != 0)
            fit *= 0.82f + sim.Neat * 0.00040f;
        return fit;
    }

    private static float DramaSkillObsessionFit(PluginSimProfile sim, SkillMask mask, bool isSerious, bool isEnergetic, bool isOutgoing)
    {
        float fit = 1f;
        if ((mask & SkillMask.Body) != 0)
            fit *= isEnergetic ? 2.85f : (sim.Active <= 300 ? 0.22f : 1.0f);
        if ((mask & SkillMask.Logic) != 0)
            fit *= isSerious ? 2.65f : 0.9f;
        if ((mask & SkillMask.Charisma) != 0)
            fit *= isOutgoing ? 2.35f : 0.8f;
        if ((mask & SkillMask.Creativity) != 0)
            fit *= isSerious || sim.Playful >= 650 ? 1.85f : 1.0f;
        return fit;
    }

    private static float DramaLeisurePersonalityFit(
        PluginSimProfile sim,
        PluginObject obj,
        ClassifiedAction classified,
        bool isLazy,
        bool isEnergetic,
        bool isPlayful,
        bool isSerious)
    {
        var fit = 1f;
        var name = obj.Name ?? "";
        if (InteractionClassifier.ContainsAny(name, "pool", "dive", "slide", "dance", "basket", "exercise", "workout"))
            fit *= isEnergetic ? 2.85f : (isLazy ? 0.25f : 1.05f);
        else if (classified.ObjectKind is SmartObjectKind.CouchOrRecliner or SmartObjectKind.Chair)
            fit *= isLazy ? 2.55f : (isEnergetic ? 0.45f : 1.0f);

        if (InteractionClassifier.ContainsAny(name, "pinball", "arcade", "toy", "vr", "game", "jukebox"))
            fit *= isPlayful ? 2.65f : (isSerious ? 0.40f : 1.05f);
        else if (InteractionClassifier.ContainsAny(name, "book", "chess", "telescope", "easel"))
            fit *= isSerious ? 2.55f : (isPlayful ? 0.55f : 1.05f);

        return fit;
    }

    private static float WeatherAppealFactor(PluginAutonomyCandidate cand)
    {
        if (cand.BlockedByPlugin)
            return 0f;
        if (cand.VanillaScore > 0.0001f)
            return Math.Clamp(cand.AdjustedScore / cand.VanillaScore, 0.05f, 3.0f);
        if (cand.AdjustedScore > 0.0001f)
            return Math.Clamp(cand.AdjustedScore, 0.2f, 2.5f);
        return 1f;
    }

    private static int ClaimDurationFor(SmartActionKind kind) => kind switch
    {
        SmartActionKind.PrepareGroupMeal => 28,
        SmartActionKind.PrepareSingleMeal => 18,
        SmartActionKind.SleepInBed => 60,
        SmartActionKind.TakeBath => 24,
        SmartActionKind.TakeShower => 16,
        SmartActionKind.UseToilet => 12,
        _ => 14,
    };

    private static float TileDist(PluginSimProfile sim, PluginObject obj) =>
        MathF.Sqrt((sim.X - obj.X) * (sim.X - obj.X) + (sim.Y - obj.Y) * (sim.Y - obj.Y)) + Math.Abs(sim.Level - obj.Level) * 8f;
}
