using System.Text.Json;
using SimsNative.Plugins;

namespace Local.SmartFreeWill;

internal enum DramaEventKind
{
    BladderAccident,
    SlapOrRejection,
    ElectricalZap,
    FireOutbreak,
}

internal sealed record DramaEvent(
    int Id,
    DramaEventKind Kind,
    short SubjectSimId,
    short? SecondarySimId,
    short? RelatedObjectId,
    int X,
    int Y,
    int Level,
    int ExpiresAtMinute);

internal sealed class HouseholdBlackboard
{
    private sealed record TransientClaim(short SimId, SmartActionKind Kind, int ExpiresAtMinute);
    private sealed record RecentActivity(uint ObjectGuid, short LeadObjectId, SmartActionKind Kind, int Minute);
    private sealed record ActiveWatch(short LeadObjectId, int ActionId, SmartActionKind Kind, int StartedMinute, short InitialMotiveSum);
    private sealed record MotiveSnapshot(short Bladder, short Energy, short Comfort, short Hygiene, SmartObjectKind ActiveObjectKind);

    private short trackedHouse = -1;
    private int lastClockMinuteOfDay = -1;
    private int monotonicMinutes;
    private int nextDramaEventId = 1;

    private readonly Dictionary<short, TransientClaim> objectClaims = [];
    private readonly Dictionary<short, short> bedOwners = [];
    private readonly Dictionary<short, List<RecentActivity>> recentBySim = [];
    private readonly Dictionary<(short SimId, short LeadObjectId), (int UntilMinute, int Strikes)> routeBackoffs = [];
    private readonly Dictionary<(short SimId, short LeadObjectId, int ActionId), int> playerVetoes = [];
    private readonly Dictionary<short, ActiveWatch> activeAutonomousWatch = [];
    private readonly Dictionary<short, MotiveSnapshot> prevSimSnapshots = [];
    private readonly Dictionary<(short SimId, short TargetNeighborId), int> prevDailyRel = [];
    private readonly HashSet<short> knownPuddleIds = [];
    private readonly HashSet<short> knownFireIds = [];
    private readonly List<DramaEvent> dramaEvents = [];
    private readonly HashSet<(short WitnessSimId, int EventId)> reactedWitnesses = [];
    private bool objectBaselineSeeded;
    private (short SimId, int ExpiresAtMinute)? activeGroupChef;

    public int NowMinutes => monotonicMinutes;

    public void Reset()
    {
        trackedHouse = -1;
        lastClockMinuteOfDay = -1;
        monotonicMinutes = 0;
        objectClaims.Clear();
        bedOwners.Clear();
        recentBySim.Clear();
        routeBackoffs.Clear();
        playerVetoes.Clear();
        activeAutonomousWatch.Clear();
        prevSimSnapshots.Clear();
        prevDailyRel.Clear();
        knownPuddleIds.Clear();
        knownFireIds.Clear();
        dramaEvents.Clear();
        reactedWitnesses.Clear();
        objectBaselineSeeded = false;
        activeGroupChef = null;
    }

    public byte[] SerializeState()
    {
        var dto = new SavedBlackboardState(
            trackedHouse,
            lastClockMinuteOfDay,
            monotonicMinutes,
            bedOwners.ToDictionary(k => k.Key, v => v.Value));
        return JsonSerializer.SerializeToUtf8Bytes(dto);
    }

    public void RestoreState(ReadOnlySpan<byte> data)
    {
        Reset();
        if (data.IsEmpty) return;
        try
        {
            var dto = JsonSerializer.Deserialize<SavedBlackboardState>(data);
            if (dto is null) return;
            trackedHouse = dto.House;
            lastClockMinuteOfDay = dto.LastClockMinute;
            monotonicMinutes = Math.Max(0, dto.MonotonicMinutes);
            if (dto.BedOwners is not null)
            {
                foreach (var (simId, bedId) in dto.BedOwners)
                    bedOwners[simId] = bedId;
            }
        }
        catch (JsonException)
        {
            Reset();
        }
    }

    private sealed record SavedBlackboardState(
        short House,
        int LastClockMinute,
        int MonotonicMinutes,
        Dictionary<short, short>? BedOwners);

    public void SyncWorld(
        short house,
        int hours,
        int minutes,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyDictionary<short, PluginObject> objectsById,
        IPluginSimulation? lotForRelationships = null)
    {
        var clockMinute = Math.Clamp(hours * 60 + minutes, 0, 1439);
        if (house != trackedHouse)
        {
            Reset();
            trackedHouse = house;
            lastClockMinuteOfDay = clockMinute;
            monotonicMinutes = clockMinute;
        }
        else if (lastClockMinuteOfDay < 0)
        {
            lastClockMinuteOfDay = clockMinute;
            monotonicMinutes = Math.Max(monotonicMinutes, clockMinute);
        }
        else
        {
            var delta = clockMinute - lastClockMinuteOfDay;
            if (delta < -720)
                delta += 1440;
            if (delta > 0 && delta <= 360)
                monotonicMinutes += delta;
            lastClockMinuteOfDay = clockMinute;
        }

        PruneExpired(objectsById, allSims);
        ObserveSimProgressAndDrama(allSims, objectsById, lotForRelationships);
    }

    private void PruneExpired(
        IReadOnlyDictionary<short, PluginObject> objectsById,
        IReadOnlyList<PluginSimProfile> allSims)
    {
        var validSimIds = allSims.Select(s => s.ObjectId).ToHashSet();

        foreach (var (objId, claim) in objectClaims.ToArray())
        {
            if (claim.ExpiresAtMinute <= monotonicMinutes || !objectsById.ContainsKey(objId) || !validSimIds.Contains(claim.SimId))
                objectClaims.Remove(objId);
        }

        if (activeGroupChef is { } chef && (chef.ExpiresAtMinute <= monotonicMinutes || !validSimIds.Contains(chef.SimId)))
            activeGroupChef = null;

        foreach (var (key, entry) in routeBackoffs.ToArray())
        {
            if (entry.UntilMinute <= monotonicMinutes || !validSimIds.Contains(key.SimId))
                routeBackoffs.Remove(key);
        }

        foreach (var (key, until) in playerVetoes.ToArray())
        {
            if (until <= monotonicMinutes || !validSimIds.Contains(key.SimId))
                playerVetoes.Remove(key);
        }

        foreach (var (simId, list) in recentBySim.ToArray())
        {
            if (!validSimIds.Contains(simId))
            {
                recentBySim.Remove(simId);
                continue;
            }
            list.RemoveAll(item => monotonicMinutes - item.Minute > 240);
        }

        foreach (var (simId, bedId) in bedOwners.ToArray())
        {
            if (!objectsById.ContainsKey(bedId))
                bedOwners.Remove(simId);
        }

        dramaEvents.RemoveAll(ev => ev.ExpiresAtMinute <= monotonicMinutes || (ev.SubjectSimId != 0 && !validSimIds.Contains(ev.SubjectSimId)));
        if (dramaEvents.Count == 0)
            reactedWitnesses.Clear();
    }

    private void ObserveSimProgressAndDrama(
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyDictionary<short, PluginObject> objectsById,
        IPluginSimulation? lot)
    {
        var currentPuddles = new List<PluginObject>();
        var currentFires = new List<PluginObject>();
        foreach (var obj in objectsById.Values)
        {
            if (obj.ObjectId != obj.LeadObjectId)
                continue;
            var kind = InteractionClassifier.ClassifyObject(obj, isSim: false);
            if (kind == SmartObjectKind.FloodOrPuddle)
                currentPuddles.Add(obj);
            else if (kind == SmartObjectKind.Fire)
                currentFires.Add(obj);
        }

        if (!objectBaselineSeeded)
        {
            foreach (var p in currentPuddles) knownPuddleIds.Add(p.ObjectId);
            foreach (var f in currentFires) knownFireIds.Add(f.ObjectId);
            objectBaselineSeeded = true;
        }
        else
        {
            knownPuddleIds.RemoveWhere(id => !objectsById.ContainsKey(id));
            knownFireIds.RemoveWhere(id => !objectsById.ContainsKey(id));

            foreach (var fire in currentFires)
            {
                if (knownFireIds.Add(fire.ObjectId))
                {
                    var nearestSim = allSims
                        .Where(s => !s.AtWorkOrSchool && !s.Dog && !s.Cat && s.Level == fire.Level)
                        .OrderBy(s => Math.Abs(s.X - fire.X) + Math.Abs(s.Y - fire.Y))
                        .FirstOrDefault();
                    PushDramaEvent(DramaEventKind.FireOutbreak, nearestSim?.ObjectId ?? 0, null, fire.ObjectId, fire.X, fire.Y, fire.Level, 18);
                }
            }

            foreach (var puddle in currentPuddles)
            {
                if (knownPuddleIds.Add(puddle.ObjectId))
                {
                    var culprit = allSims
                        .Where(s => !s.AtWorkOrSchool && !s.Dog && !s.Cat && s.Level == puddle.Level &&
                                    Math.Abs(s.X - puddle.X) <= 3 && Math.Abs(s.Y - puddle.Y) <= 3 &&
                                    prevSimSnapshots.TryGetValue(s.ObjectId, out var snap) && snap.Bladder <= -75)
                        .FirstOrDefault();
                    if (culprit is not null)
                        PushDramaEvent(DramaEventKind.BladderAccident, culprit.ObjectId, null, puddle.ObjectId, puddle.X, puddle.Y, puddle.Level, 24);
                }
            }
        }

        foreach (var sim in allSims)
        {
            if (sim.Dog || sim.Cat)
                continue;

            var activeObjKind = SmartObjectKind.General;
            if (sim.CurrentAction is { } curAct && objectsById.TryGetValue(curAct.TargetObjectId, out var curTarget))
            {
                var curLead = objectsById.GetValueOrDefault(curTarget.LeadObjectId, curTarget);
                activeObjKind = InteractionClassifier.ClassifyObject(curLead, allSims.Any(s => s.ObjectId == curLead.ObjectId));
            }

            var bladder = sim.Motives[InteractionClassifier.MotiveBladder];
            var energy = sim.Motives[InteractionClassifier.MotiveEnergy];
            var comfort = sim.Motives[InteractionClassifier.MotiveComfort];
            var hygiene = sim.Motives[InteractionClassifier.MotiveHygiene];

            if (!sim.AtWorkOrSchool && prevSimSnapshots.TryGetValue(sim.ObjectId, out var prev))
            {
                if (prev.Bladder <= -92 && bladder >= 40 && prev.ActiveObjectKind != SmartObjectKind.Toilet && activeObjKind != SmartObjectKind.Toilet)
                {
                    var nearPuddle = currentPuddles.FirstOrDefault(p => p.Level == sim.Level && Math.Abs(p.X - sim.X) <= 3 && Math.Abs(p.Y - sim.Y) <= 3);
                    PushDramaEvent(DramaEventKind.BladderAccident, sim.ObjectId, null, nearPuddle?.ObjectId, sim.X, sim.Y, sim.Level, 24);
                }

                var crashDelta = (prev.Energy - energy) + (prev.Comfort - comfort) + (prev.Hygiene - hygiene);
                if (crashDelta >= 65 && energy <= -60)
                {
                    var brokenNear = objectsById.Values.FirstOrDefault(o =>
                        o.ObjectId == o.LeadObjectId && o.RepairState != 0 && o.Level == sim.Level &&
                        Math.Abs(o.X - sim.X) <= 3 && Math.Abs(o.Y - sim.Y) <= 3);
                    if (brokenNear is not null)
                        PushDramaEvent(DramaEventKind.ElectricalZap, sim.ObjectId, null, brokenNear.ObjectId, sim.X, sim.Y, sim.Level, 22);
                }
            }

            prevSimSnapshots[sim.ObjectId] = new MotiveSnapshot(bladder, energy, comfort, hygiene, activeObjKind);

            if (lot is not null && sim.Household && !sim.AtWorkOrSchool)
            {
                try
                {
                    foreach (var rel in lot.GetRelationships(sim.ObjectId))
                    {
                        if (rel.TargetObjectId is not { } otherObjId)
                            continue;
                        var key = (sim.ObjectId, rel.TargetNeighborId);
                        if (prevDailyRel.TryGetValue(key, out var prevDaily) && prevDaily - rel.Daily >= 8)
                        {
                            PushDramaEvent(DramaEventKind.SlapOrRejection, sim.ObjectId, otherObjId, otherObjId, sim.X, sim.Y, sim.Level, 20);
                        }
                        prevDailyRel[key] = rel.Daily;
                    }
                }
                catch
                {
                }
            }

            if (!sim.Household)
                continue;

            if (sim.AtWorkOrSchool)
            {
                activeAutonomousWatch.Remove(sim.ObjectId);
                continue;
            }

            if (HasPlayerCommand(sim))
            {
                ReleaseClaimsForSim(sim.ObjectId);
                activeAutonomousWatch.Remove(sim.ObjectId);
                continue;
            }

            var motiveSum = MotiveHealthSum(sim);
            if (activeAutonomousWatch.TryGetValue(sim.ObjectId, out var watch))
            {
                var stillRunningSame = sim.CurrentAction is { } running &&
                    LeadId(running.TargetObjectId, objectsById) == watch.LeadObjectId &&
                    running.InteractionId == watch.ActionId;

                if (!stillRunningSame)
                {
                    var elapsed = monotonicMinutes - watch.StartedMinute;
                    if (elapsed <= 3 && motiveSum <= watch.InitialMotiveSum + 2 && sim.RouteResult < 0)
                    {
                        RecordRouteFailure(sim.ObjectId, watch.LeadObjectId);
                    }
                    else if (elapsed >= 4 && objectsById.TryGetValue(watch.LeadObjectId, out var usedObj))
                    {
                        RecordRecentActivity(sim.ObjectId, usedObj.Guid, watch.LeadObjectId, watch.Kind);
                        if (watch.Kind == SmartActionKind.SleepInBed)
                            bedOwners[sim.ObjectId] = watch.LeadObjectId;
                    }
                    activeAutonomousWatch.Remove(sim.ObjectId);
                }
            }

            if (sim.CurrentAction is { Autonomous: true } autoCur &&
                objectsById.TryGetValue(autoCur.TargetObjectId, out var targetObj))
            {
                var leadId = targetObj.LeadObjectId;
                var leadObj = objectsById.GetValueOrDefault(leadId, targetObj);
                var classified = InteractionClassifier.Classify(
                    leadObj,
                    allSims.Any(s => s.ObjectId == leadId),
                    autoCur.Name,
                    autoCur.EnglishName,
                    false,
                    []);

                if (!activeAutonomousWatch.ContainsKey(sim.ObjectId))
                {
                    activeAutonomousWatch[sim.ObjectId] = new ActiveWatch(
                        leadId,
                        autoCur.InteractionId,
                        classified.ActionKind,
                        monotonicMinutes,
                        motiveSum);
                }

                if (classified.ActionKind == SmartActionKind.SleepInBed)
                    bedOwners[sim.ObjectId] = leadId;
                if (classified.ActionKind == SmartActionKind.PrepareGroupMeal)
                    activeGroupChef = (sim.ObjectId, monotonicMinutes + 30);
            }
        }
    }

    public void PushDramaEvent(
        DramaEventKind kind,
        short subjectSimId,
        short? secondarySimId,
        short? relatedObjectId,
        int x,
        int y,
        int level,
        int durationMinutes = 20)
    {
        if (dramaEvents.Any(e =>
                e.Kind == kind &&
                e.SubjectSimId == subjectSimId &&
                e.ExpiresAtMinute > monotonicMinutes))
        {
            return;
        }

        dramaEvents.Add(new DramaEvent(
            nextDramaEventId++,
            kind,
            subjectSimId,
            secondarySimId,
            relatedObjectId,
            x,
            y,
            level,
            monotonicMinutes + durationMinutes));
        if (dramaEvents.Count > 12)
            dramaEvents.RemoveAt(0);
    }

    public DramaEvent? TryClaimNextWitnessEvent(PluginSimProfile witness, float maxTileDistance = 18f)
    {
        for (var i = dramaEvents.Count - 1; i >= 0; i--)
        {
            var ev = dramaEvents[i];
            if (ev.ExpiresAtMinute <= monotonicMinutes)
                continue;
            if (ev.SubjectSimId == witness.ObjectId || ev.SecondarySimId == witness.ObjectId)
                continue;
            if (reactedWitnesses.Contains((witness.ObjectId, ev.Id)))
                continue;

            var dx = witness.X - ev.X;
            var dy = witness.Y - ev.Y;
            var dist = MathF.Sqrt(dx * dx + dy * dy) + Math.Abs(witness.Level - ev.Level) * 8f;
            if (dist > maxTileDistance)
                continue;

            reactedWitnesses.Add((witness.ObjectId, ev.Id));
            return ev;
        }
        return null;
    }

    public static bool IsStereoPlaying(
        PluginObject stereo,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        if (stereo.RepairState != 0)
            return false;
        if (stereo.PrimaryAttribute != 0 || stereo.UseCount > 0)
            return true;
        foreach (var s in allSims)
        {
            if (s.CurrentAction is { } cur && LeadId(cur.TargetObjectId, objectsById) == stereo.ObjectId)
                return true;
        }
        return false;
    }

    public static PluginSimProfile? FindActiveTvWatcher(
        PluginObject tv,
        short excludeSimId,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        foreach (var other in allSims)
        {
            if (other.ObjectId == excludeSimId || other.AtWorkOrSchool || other.Dog || other.Cat)
                continue;
            if (other.CurrentAction is not { } cur)
                continue;
            if (LeadId(cur.TargetObjectId, objectsById) == tv.ObjectId &&
                InteractionClassifier.ContainsAny(cur.EnglishName ?? cur.Name, "watch"))
            {
                return other;
            }
        }
        return null;
    }

    public static bool HasPlayerCommand(PluginSimProfile sim) =>
        (sim.CurrentAction is { Autonomous: false } && sim.Priority < 95) ||
        sim.ActionQueue.Any(q => !q.Autonomous);

    private static short MotiveHealthSum(PluginSimProfile sim)
    {
        int sum = 0;
        foreach (var m in new[] { 5, 6, 7, 8, 9, 14, 15 })
            if (m < sim.Motives.Length) sum += sim.Motives[m];
        return (short)Math.Clamp(sum, short.MinValue, short.MaxValue);
    }

    private static short LeadId(short objectId, IReadOnlyDictionary<short, PluginObject> objectsById) =>
        objectsById.TryGetValue(objectId, out var obj) ? obj.LeadObjectId : objectId;

    public void RecordClaim(short simId, short leadObjectId, SmartActionKind kind, int durationMinutes = 14)
    {
        ReleaseClaimsForSim(simId);
        objectClaims[leadObjectId] = new TransientClaim(simId, kind, monotonicMinutes + Math.Max(3, durationMinutes));
        if (kind == SmartActionKind.PrepareGroupMeal)
            activeGroupChef = (simId, monotonicMinutes + 30);
    }

    public void ReleaseClaimsForSim(short simId)
    {
        foreach (var (objId, claim) in objectClaims.ToArray())
            if (claim.SimId == simId)
                objectClaims.Remove(objId);
        if (activeGroupChef is { SimId: var chefId } && chefId == simId)
            activeGroupChef = null;
    }

    public void RecordRecentActivity(short simId, uint guid, short leadObjectId, SmartActionKind kind)
    {
        if (!recentBySim.TryGetValue(simId, out var list))
            recentBySim[simId] = list = [];
        if (list.Count > 0 && list[^1].LeadObjectId == leadObjectId && monotonicMinutes - list[^1].Minute < 5)
            return;
        list.Add(new RecentActivity(guid, leadObjectId, kind, monotonicMinutes));
        if (list.Count > 24)
            list.RemoveAt(0);
    }

    public void RecordRouteFailure(short simId, short leadObjectId)
    {
        var key = (simId, leadObjectId);
        var prevStrikes = routeBackoffs.TryGetValue(key, out var prev) ? prev.Strikes : 0;
        var nextStrikes = Math.Min(4, prevStrikes + 1);
        var penaltyMinutes = 15 * nextStrikes;
        routeBackoffs[key] = (monotonicMinutes + penaltyMinutes, nextStrikes);
    }

    public void RecordPlayerCancellation(short simId, short leadObjectId, int actionId)
    {
        playerVetoes[(simId, leadObjectId, actionId)] = monotonicMinutes + 90;
        ReleaseClaimsForSim(simId);
    }

    public bool IsPlayerVetoed(short simId, short leadObjectId, int actionId) =>
        playerVetoes.TryGetValue((simId, leadObjectId, actionId), out var until) && until > monotonicMinutes;

    public bool IsBackedOff(short simId, short leadObjectId) =>
        routeBackoffs.TryGetValue((simId, leadObjectId), out var entry) && entry.UntilMinute > monotonicMinutes;

    public float NoveltyFactor(short simId, uint objectGuid, short leadObjectId, SmartActionKind kind)
    {
        if (!recentBySim.TryGetValue(simId, out var list) || list.Count == 0)
            return 1f;
        var repeats = 0;
        foreach (var item in list)
        {
            var age = monotonicMinutes - item.Minute;
            if (age > 180) continue;
            if (item.LeadObjectId == leadObjectId || (objectGuid != 0 && item.ObjectGuid == objectGuid && item.Kind == kind))
                repeats++;
        }
        return repeats switch
        {
            0 => 1f,
            1 => 0.58f,
            2 => 0.30f,
            _ => 0.14f,
        };
    }

    public bool IsClaimedByAnotherSim(
        short simId,
        PluginObject leadObj,
        SmartObjectKind objectKind,
        bool joinInteraction,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        if (joinInteraction || objectKind is SmartObjectKind.HotTub or SmartObjectKind.GroupMeal or SmartObjectKind.Carpool or SmartObjectKind.SchoolBus or SmartObjectKind.Television or SmartObjectKind.Stereo)
            return false;

        var capacity = objectKind == SmartObjectKind.DoubleBed ? 2 : 1;
        var users = (int)leadObj.UseCount;

        if (objectClaims.TryGetValue(leadObj.ObjectId, out var claim) && claim.SimId != simId && claim.ExpiresAtMinute > monotonicMinutes)
            users++;

        foreach (var other in allSims)
        {
            if (other.ObjectId == simId || other.AtWorkOrSchool) continue;
            if (other.CurrentAction is { } cur && LeadId(cur.TargetObjectId, objectsById) == leadObj.ObjectId && leadObj.UseCount == 0)
                users++;
            else if (other.ActionQueue.Any(q => LeadId(q.TargetObjectId, objectsById) == leadObj.ObjectId))
                users++;
        }

        return users >= capacity;
    }

    public short? FindToiletOccupantSimId(
        short askingSimId,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginObject> allObjects,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        var toilets = allObjects
            .Where(o => o.ObjectId == o.LeadObjectId && InteractionClassifier.ClassifyObject(o, false) == SmartObjectKind.Toilet)
            .Select(o => o.ObjectId)
            .ToHashSet();
        if (toilets.Count == 0)
            return null;

        foreach (var other in allSims)
        {
            if (other.ObjectId == askingSimId || other.AtWorkOrSchool || other.Dog || other.Cat)
                continue;
            if (other.CurrentAction is { } cur)
            {
                var leadId = LeadId(cur.TargetObjectId, objectsById);
                if (toilets.Contains(leadId))
                    return other.ObjectId;
                if (objectsById.TryGetValue(leadId, out var inRoom) &&
                    InteractionClassifier.ClassifyObject(inRoom, false) is SmartObjectKind.Shower or SmartObjectKind.Tub &&
                    allObjects.Any(t => toilets.Contains(t.ObjectId) && t.RoomId == inRoom.RoomId && t.Level == inRoom.Level))
                {
                    return other.ObjectId;
                }
            }
        }
        return null;
    }

    public bool ViolatesBathroomPrivacy(
        PluginSimProfile sim,
        PluginObject targetObj,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginSimRelationship> relationships,
        IReadOnlyDictionary<short, PluginObject> objectsById)
    {
        if (targetObj.Outside || targetObj.RoomId < 0)
            return false;

        var romanticPartnerIds = relationships
            .Where(r => r.Love || r.Crush || r.Lifetime >= 70)
            .Select(r => r.TargetObjectId)
            .Where(id => id.HasValue)
            .Select(id => id!.Value)
            .ToHashSet();

        foreach (var other in allSims)
        {
            if (other.ObjectId == sim.ObjectId || other.AtWorkOrSchool || other.Dog || other.Cat)
                continue;
            if (other.RoomId != targetObj.RoomId || other.Level != targetObj.Level)
                continue;

            if (other.CurrentAction is not { } cur || !objectsById.TryGetValue(cur.TargetObjectId, out var otherTarget))
                continue;
            var lead = objectsById.GetValueOrDefault(otherTarget.LeadObjectId, otherTarget);
            var otherObjKind = InteractionClassifier.ClassifyObject(lead, isSim: false);
            if (otherObjKind == SmartObjectKind.Toilet)
                return true;
            if (otherObjKind is SmartObjectKind.Shower or SmartObjectKind.Tub)
            {
                if (sim.Child || other.Child || !romanticPartnerIds.Contains(other.ObjectId))
                    return true;
            }
        }
        return false;
    }

    public float BedAffinityMultiplier(
        PluginSimProfile sim,
        PluginObject bedLead,
        SmartObjectKind bedKind,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginSimRelationship> relationships)
    {
        var romanticPartners = relationships
            .Where(r => r.Household && (r.Love || r.Crush || (r.Daily >= 70 && r.Lifetime >= 60)))
            .Select(r => r.TargetObjectId)
            .Where(id => id.HasValue)
            .Select(id => id!.Value)
            .ToHashSet();

        if (bedOwners.TryGetValue(sim.ObjectId, out var myBedId) && myBedId == bedLead.ObjectId)
            return 1.38f;

        var ownersOfThisBed = bedOwners
            .Where(kv => kv.Value == bedLead.ObjectId && kv.Key != sim.ObjectId && allSims.Any(s => s.ObjectId == kv.Key))
            .Select(kv => kv.Key)
            .ToArray();

        if (bedKind == SmartObjectKind.Bed)
        {
            if (ownersOfThisBed.Length > 0)
                return 0.32f;
            if (!sim.Child && romanticPartners.Count > 0)
                return 0.78f;
            return 1.05f;
        }

        if (bedKind == SmartObjectKind.DoubleBed)
        {
            if (sim.Child && allSims.Any(s => s.Household && !s.Child))
                return 0.55f;
            if (ownersOfThisBed.Any(owner => romanticPartners.Contains(owner)))
                return 1.42f;
            if (ownersOfThisBed.Length > 0 && !ownersOfThisBed.Any(owner => romanticPartners.Contains(owner)))
                return 0.38f;
            return romanticPartners.Count > 0 ? 1.25f : 1.08f;
        }

        return 1f;
    }

    public bool IsMealBeingPreparedOrReady(
        short askingSimId,
        IReadOnlyList<PluginSimProfile> allSims,
        IReadOnlyList<PluginObject> allObjects,
        IReadOnlyDictionary<short, PluginObject> objectsById,
        out bool readyFoodOnLot,
        out bool someoneElseCooking)
    {
        readyFoodOnLot = allObjects.Any(obj =>
            obj.ObjectId == obj.LeadObjectId &&
            obj.DirtyLevel == 0 &&
            InteractionClassifier.ClassifyObject(obj, isSim: false) is SmartObjectKind.GroupMeal or SmartObjectKind.PreparedFood);

        someoneElseCooking = false;
        if (activeGroupChef is { } chef && chef.SimId != askingSimId && chef.ExpiresAtMinute > monotonicMinutes)
        {
            someoneElseCooking = true;
            return true;
        }

        foreach (var other in allSims)
        {
            if (other.ObjectId == askingSimId || other.AtWorkOrSchool) continue;
            var actions = new List<PluginQueuedAction>(other.ActionQueue.Count + 1);
            if (other.CurrentAction is { } cur) actions.Add(cur);
            actions.AddRange(other.ActionQueue);
            foreach (var act in actions)
            {
                if (!objectsById.TryGetValue(act.TargetObjectId, out var target)) continue;
                var lead = objectsById.GetValueOrDefault(target.LeadObjectId, target);
                var classified = InteractionClassifier.Classify(lead, false, act.Name, act.EnglishName, false, []);
                if (classified.ActionKind is SmartActionKind.PrepareGroupMeal or SmartActionKind.PrepareSingleMeal)
                {
                    someoneElseCooking = true;
                    return true;
                }
            }
        }

        return readyFoodOnLot;
    }

    public bool IsBestAvailableHouseholdChef(PluginSimProfile sim, IReadOnlyList<PluginSimProfile> allSims)
    {
        if (!sim.Household || sim.Child || sim.Dog || sim.Cat || sim.AtWorkOrSchool || sim.Asleep)
            return false;

        var candidates = allSims.Where(s =>
            s.Household && !s.Child && !s.Dog && !s.Cat && !s.AtWorkOrSchool && !s.Asleep &&
            !HasPlayerCommand(s) && s.Motives[InteractionClassifier.MotiveEnergy] > -55).ToArray();

        if (candidates.Length == 0)
            return true;

        var best = candidates
            .OrderByDescending(s => s.Cooking)
            .ThenByDescending(s => s.Neat)
            .ThenBy(s => s.Motives[InteractionClassifier.MotiveHunger])
            .First();

        return best.ObjectId == sim.ObjectId || sim.Cooking >= best.Cooking - 50;
    }
}
