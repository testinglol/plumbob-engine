using SimsEngine.Formats;
using SimsEngine.Content;
using SimsEngine.Character;
using System.Numerics;

namespace SimsEngine.Simulation;

public sealed partial class SimulationWorld
{

    public void RunGenericSimsCall11Native(XObject me, short temporary0, short temporary1, short temporary2, short temporary3)
    {
        ArgumentNullException.ThrowIfNull(me);
        if (me.TypeRecord is null) return;

        InteractionScopeTable? timeScope = null;
        XObject? companion = null;
        var wroteState = false;
        if (temporary3 == 1)
        {
            for (var index = 0; index < ActivePersonCount; index++)
            {
                if (ActivePersonAt(index) is not { } person) continue;
                SavePersonRecord(person);
                var scope = InteractionExecutorScope(person);
                StoreGenericSimsCall11State(scope, person);
                timeScope ??= scope;
                wroteState = true;
            }
            if (!wroteState && ActivePersonCount == 0)
            {
                timeScope = InteractionExecutorScope(me);
                StoreGenericSimsCall11State(timeScope, me);
                wroteState = true;
            }
        }
        else if (temporary3 == 0)
        {
            var sourceScope = InteractionExecutorScope(me);
            var selector = temporary0 == -1 ? 3 : 1;
            short cursor = -1;
            if (sourceScope.TryFindNext(selector, ref cursor, 0, out _) && sourceScope.TryGet(cursor, out var entry))
            {
                var selected = entry.Mode == 0 || !PersonRecordKeys.Contains(entry.Mode)
                    ? null
                    : WalkOrder.FirstOrDefault(item => item.TypeRecord?.Key == entry.Mode);
                if (selected is not null)
                {
                    companion = selected;
                    var selectedScope = InteractionExecutorScope(selected);
                    if (!ReferenceEquals(selectedScope, sourceScope))
                        StoreGenericSimsCall11State(selectedScope, selected);
                }
            }
            StoreGenericSimsCall11State(sourceScope, me);
            timeScope = sourceScope;
        }
        else
        {
            timeScope = InteractionExecutorScope(me);
            StoreGenericSimsCall11State(timeScope, me);
        }

        if (timeScope is not null)
        {
            int hour;
            int minute;
            if (StateClass(unchecked((short)ActiveLotNumber)) == 1 && temporary0 is >= 0x28 and < 0x32)
            {
                hour = temporary1;
                minute = temporary2;
            }
            else
            {
                hour = Clock.Hour + temporary1;
                minute = Clock.Minute + temporary2;
                if (minute > 59) { hour++; minute %= 60; }
                if (hour > 23) hour %= 24;
            }
            timeScope.AddOrIncrement(2, 7, hour);
            timeScope.AddOrIncrement(2, 8, minute);
        }

        PersistNeighborhoodState();
        if (temporary3 is 0 or 1)
        {
            var selfFamily = (me as XPerson)?[PersonData.FamilyNumber] ?? (short)0;
            var firstActive = ActivePersonCount > 0 ? ActivePersonAt(0) as XPerson : null;
            var familyNumber = temporary3 == 1
                ? firstActive?[PersonData.FamilyNumber] ?? selfFamily
                : selfFamily;
            var personGuid = temporary3 == 1 ? 0 : me.TypeRecord?.Key ?? 0;
            var companionGuid = temporary3 == 0 && companion is not null && !ReferenceEquals(companion, me)
                ? companion.TypeRecord?.Key ?? 0
                : 0;
            PendingLotSwitch = new LotSwitchRequest(temporary0, personGuid, familyNumber, companionGuid);
        }
    }

    private static void StoreGenericSimsCall11State(InteractionScopeTable scope, XObject source)
    {
        scope.RemoveEntriesWithKey(2);
        ReadOnlySpan<(int Selector, int Mode)> floatFields = [(9, 0), (6, 1), (5, 2), (15, 3), (7, 4), (8, 5), (14, 6)];
        var person = source as XPerson;
        foreach (var (selector, mode) in floatFields)
        {
            var value = person is not null && (uint)selector < (uint)person.Motives.Length
                ? person.Motives[selector]
                : source.InteractionExecutorFloats.GetValueOrDefault(selector);
            scope.AddOrIncrement(2, mode, unchecked((int)MathF.Truncate(value)));
        }
        scope.AddOrIncrement(2, 9, source.InteractionBehaviorSavedWord);
        scope.AddOrIncrement(2, 10, person is not null
            ? person.PersonData[80]
            : source.InteractionExecutorWords.GetValueOrDefault(0x62c));
        scope.AddOrIncrement(2, 11, person is not null
            ? person.PersonData[82]
            : source.InteractionExecutorWords.GetValueOrDefault(0x630));
        scope.AddOrIncrement(2, 12, person is not null
            ? person.PersonData[81]
            : source.InteractionExecutorWords.GetValueOrDefault(0x62e));
    }

    internal bool HasVisitorInventoryEntry(XPerson person)
    {
        var scope = InteractionExecutorScope(person);
        if (_visitorAvatarAnimationKey == 0)
            foreach (var avatar in scope.AvatarObjects)
                if (avatar.ObjectType == 13) _visitorAvatarAnimationKey = avatar.AnimationKey;
        return scope.HasVisitorInventoryEntry(_visitorAvatarAnimationKey);
    }

    public void InitializePersonTypeRecord(XPerson person)
    {
        ArgumentNullException.ThrowIfNull(person);
        if (person.TypeRecord is not { } typeRecord) return;
        if (!PersonTypeRecordSlots.TryGetValue(typeRecord.Key, out var slot))
        {
            short candidate = 1;
            while (PersonTypeRecordSlots.ContainsValue(candidate))
            {
                if (candidate == short.MaxValue)
                    throw new InvalidOperationException("The person type-record manager exhausted its one-based short slots.");
                candidate++;
            }
            slot = candidate;
            PersonTypeRecordSlots.Add(typeRecord.Key, slot);
        }
        person.InteractionScopeKey5CA = slot;
    }

    public short? ActivePersonRecordId(int index)
    {
        if (index < 0 || index >= PersonRecordKeys.Count) return null;
        var key = PersonRecordKeys[index];
        if (key == 0) return null;
        foreach (var item in WalkOrder.OfType<XPerson>())
            if (item.TypeRecord?.Key == key) return item.Id;
        return null;
    }

    public IReadOnlyList<GenericSimsCallChooserCandidate> GenericSimsCallChooserCandidates(
        XPerson requestOwner, int? viewerCenterX = null, int? viewerCenterY = null)
    {
        ArgumentNullException.ThrowIfNull(requestOwner);
        if (viewerCenterX.HasValue != viewerCenterY.HasValue)
            throw new ArgumentException("GenericSimsCall chooser viewer center requires both coordinates.");
        var candidates = new List<GenericSimsCallChooserCandidate>();
        foreach (var typeRecord in requestOwner.GenericSimsCallPersonTypeRecords)
        {
            if (typeRecord.ObjectType != XPerson.PersonType) continue;
            var rowIndex = PersonRecordKeys.IndexOf(typeRecord.TypeRecordKey);
            if (rowIndex < 0) continue;

            var livePersonId = ActivePersonRecordId(rowIndex);
            if (livePersonId is null && viewerCenterX is { } centerX && viewerCenterY is { } centerY)
                livePersonId = TryMaterializeGenericSimsCallPerson(typeRecord.TypeRecordKey, centerX, centerY);
            var neighbor = PersonRecordNeighbor(rowIndex);
            var personData = PersonRecordData(rowIndex)?.ToArray();
            candidates.Add(new GenericSimsCallChooserCandidate(
                typeRecord.RegistryIndex,
                typeRecord.Index,
                typeRecord.TypeRecordKey,
                rowIndex,
                livePersonId,
                neighbor?.Name,
                personData,
                typeRecord.CatalogName,
                typeRecord.TypeName));
        }

        return candidates;
    }

    private short? TryMaterializeGenericSimsCallPerson(int typeRecordKey, int centerX, int centerY)
    {
        if (!PersonRecordKeys.Contains(typeRecordKey) || ScopedNeighborPersonRecordId(typeRecordKey) is null)
            return null;
        var person = WalkOrder.OfType<XPerson>().FirstOrDefault(candidate => candidate.TypeRecord?.Key == typeRecordKey);
        if (person is null) return null;

        var parameters = new FindLocationParams
        {
            UseCenter = false,
            CenterX = centerX,
            CenterY = centerY,
            Height = 1,
            Direction = -1,
            ContinueFlag = 1,
            FlagB = 1,
        };
        var checkStack = TreeRunner.CreateTransientStack(this, person);
        if (!FindLocation(person, parameters, out var found, checkStack: checkStack))
        {
            KillObject(person.Id);
            return null;
        }

        PlaceObject(person, found, checkStack: checkStack);
        RefreshPersonPlacementCallbacksAfterMovement(person);
        return person.Id;
    }

    public bool TryChooseGenericSimsCallPerson(long requestId, int personRecordIndex)
    {
        var requests = GenericSimsCallRequests.Snapshot();
        var request = requests.FirstOrDefault(candidate => candidate.Id == requestId);
        if (request.Id != requestId || request.Status != 0 || request.Kind != GenericSimsCallRequestKind.Second)
            return false;
        if (requests.FirstOrDefault(candidate => candidate.PersonKey == request.PersonKey).Id != requestId)
            return false;

        var owner = WalkOrder.OfType<XPerson>().FirstOrDefault(person => person.StackObjectKey == request.Temporary0);
        if (owner is null) return false;
        var candidate = GenericSimsCallChooserCandidates(owner)
            .FirstOrDefault(row => row.PersonRecordIndex == personRecordIndex && row.LivePersonId is not null);
        if (candidate?.LivePersonId is not { } livePersonId) return false;
        if (ObjectById(livePersonId) is not XPerson selected || selected.TypeRecord?.Key != candidate.TypeRecordKey)
            return false;

        if (!GenericSimsCallRequests.TryComplete(
                requestId, 0, selected.StackObjectKey, GenericSimsCallRequestStatus.Succeeded))
            return false;
        GlobalPerson.ByteE0 = 1;
        return true;
    }

    public short? ScopedNeighborPersonRecordId(int personRecordKey)
    {
        if (personRecordKey == 0 || !PersonRecordKeys.Contains(personRecordKey)) return null;

        foreach (var item in WalkOrder)
            if (item.TypeRecord?.Key == personRecordKey)
                return item.ClockManagerIndex;

        if (ObjectGroupFactory?.Invoke(personRecordKey) is { } group)
            return group.Count == 0 ? null : group[0].ClockManagerIndex;

        if (ObjectFactory?.Invoke(personRecordKey) is not { } created) return null;
        Add(created);
        if (created is XPerson person) InitializeCreatedPerson(person);
        InitializeCreatedObject(created);
        if (created is XPerson postInitPerson) InitializeCreatedPerson(postInitPerson);
        return created.ClockManagerIndex;
    }

    public int PersonRecordIndex(XObject item)
    {
        var key = item.TypeRecord?.Key
            ?? throw new InvalidOperationException($"Object {item.Id} has no type record for person-record lookup.");
        return PersonRecordKeys.IndexOf(key);
    }

    public short[]? PersonRecordData(int personRecordIndex)
    {
        if (personRecordIndex < 0 || personRecordIndex >= PersonRecordKeys.Count) return null;
        var key = PersonRecordKeys[personRecordIndex];
        short[]? personData = key == 0 ? null : WalkOrder.OfType<XPerson>()
            .FirstOrDefault(item => item.TypeRecord?.Key == key) is XPerson person ? person.PersonData : null;
        if (personData is null) personData = PersonRecordNeighbor(personRecordIndex)?.PersonData;
        return personData;
    }

    public void ApplySimulatorConstants(SimulatorConstants constants)
    {
        SimulatorTuning = FindBestInteractionTuning.FromSimulatorConstants(constants);
        RoomScoreTuning = SimsEngine.World.RoomScoreTuning.FromSimulatorConstants(constants);
        HouseYardScoreMultiplier = constants.Get("yard score multiplier", 0.33f);
        HouseUpkeepPenaltyPerDirtyObject = (int)Math.Round(constants.Get("upkeep penalty per dirty object", 6f), MidpointRounding.ToEven);
        HouseUpkeepPenaltyPerBrokenObject = (int)Math.Round(constants.Get("upkeep penalty per broken object", 15f), MidpointRounding.ToEven);
        HouseLayoutHistoryFillValue = (int)Math.Round(constants.Get("fill value for layout history", 200f), MidpointRounding.ToEven);
        FriendshipThreshold = SimulatorTuning.FriendshipThreshold;
        ArchitectureValueMultiplier = constants.Get("architecture value multiplier", 0.7f);
    }

    public bool InitializeAutonomyCandidate(XObject item, XObject root, InteractionTable? interactions)
    {
        ArgumentNullException.ThrowIfNull(item);
        if (!ReferenceEquals(item, ObjectById(item.Id)))
            throw new InvalidOperationException($"Object {item.Id} is not registered in this simulation world.");
        var eligible = AutonomyCandidateEligibility.IsEligible(item, root, interactions);
        ClockManager.SetFlag(item.ClockManagerIndex, 3, eligible);
        return eligible;
    }

    private NeighborState? PersonRecordNeighbor(int personRecordIndex)
    {
        if (personRecordIndex < 0 || personRecordIndex >= PersonRecordKeys.Count) return null;
        while (PersonRecordNeighborIds.Count <= personRecordIndex) PersonRecordNeighborIds.Add(null);
        if (PersonRecordNeighborIds[personRecordIndex] is { } neighborId)
            return Neighbors.GetValueOrDefault(neighborId);

        var key = PersonRecordKeys[personRecordIndex];
        foreach (var neighbor in NeighborWalkOrder)
        {
            if (neighbor?.TypeRecordKey != key) continue;
            PersonRecordNeighborIds[personRecordIndex] = neighbor.Id;
            return neighbor;
        }
        PersonRecordNeighborIds[personRecordIndex] = 0;
        return null;
    }

    public int FameFriendStarPower(int personRecordIndex)
    {
        var subject = PersonRecordNeighbor(personRecordIndex);
        if (subject is null) return 0;

        var total = 0;
        foreach (var candidate in NeighborWalkOrder)
        {
            if (candidate is null || ReferenceEquals(candidate, subject)) continue;
            if (candidate.FriendEligibilityObjectFlagsB4 is not { } flags || (flags & 0xC) != 4) continue;
            var candidateFamily = candidate.PersonData[61];
            var subjectFamily = subject.PersonData[61];
            if (candidateFamily == 0 || candidateFamily == subjectFamily) continue;

            var candidateToSubject = candidate.Relationships;
            var subjectToCandidate = subject.Relationships;
            if (candidateToSubject.Count(subject.Id) == 0 || subjectToCandidate.Count(candidate.Id) == 0) continue;
            if (candidateToSubject.Get(subject.Id, 0) < FriendshipThreshold ||
                subjectToCandidate.Get(candidate.Id, 0) < FriendshipThreshold) continue;
            total = unchecked(total + candidate.PersonData[81]);
        }
        return total;
    }

    public bool MeetsFameFriendPowerGate(int personRecordIndex, int requiredFriendPower) =>
        requiredFriendPower <= FameFriendStarPower(personRecordIndex) * 0.5f;

    public FamePromotionCandidate? EvaluateFamePromotion(int personRecordIndex, GenericSimsCallRecordTarget target)
    {
        var data = PersonRecordData(personRecordIndex);
        if (data is null) return null;
        var stars = data[(int)PersonData.FameStarPower09];
        if (stars < 0 || stars >= 10 || stars >= target.FameStarThresholds.Count || stars >= target.FameFriendThresholds.Count)
            return null;
        if (data[(int)PersonData.FameScore] < target.FameStarThresholds[stars]) return null;

        ReadOnlySpan<int> skillFields = [10, 12, 11, 17, 18, 15];
        if (target.FameSkillThresholds.Count < skillFields.Length) return null;
        for (var skill = 0; skill < skillFields.Length; skill++)
        {
            var rows = target.FameSkillThresholds[skill];
            if (stars >= rows.Count) return null;
            var threshold = rows[stars];
            var raw = data[skillFields[skill]];
            var required = unchecked(threshold * 100) <= raw ? 0 : threshold;
            var level = Math.Clamp(raw / 100, 0, 10);
            if (level < required) return null;
        }
        return new FamePromotionCandidate(data, stars, target.FameFriendThresholds[stars]);
    }

    public static void ApplyFamePromotion(FamePromotionCandidate candidate)
    {
        var promoted = (short)(candidate.CurrentStarPower + 1);
        candidate.PersonData[(int)PersonData.FameStarPower09] = promoted;
        if (candidate.PersonData[(int)PersonData.FameStarHighWatermark] < promoted)
            candidate.PersonData[(int)PersonData.FameStarHighWatermark] = promoted;
    }

    public bool TryDecrementFameStarPower(int personRecordIndex, IReadOnlyList<int> fameStarThresholds)
    {
        var personData = PersonRecordData(personRecordIndex);
        if (personData is null) return false;

        var starPower = personData[(int)PersonData.FameStarPower09];
        if (starPower <= 0 || starPower > fameStarThresholds.Count) return false;
        if (personData[(int)PersonData.FameScore] >= fameStarThresholds[starPower - 1]) return false;
        personData[(int)PersonData.FameStarPower09] = (short)(starPower - 1);
        return true;
    }

    public PersonRecordSelection? EvaluatePersonRecordSelection(int index)
    {
        if (!PersonRecordManagerPresent) return null;
        var key = index >= 0 && index < PersonRecordKeys.Count ? PersonRecordKeys[index] : 0;
        var person = key == 0 ? null : ObjectByTypeRecordKey(key);
        if (person is null) return new PersonRecordSelection(null);

        var state = EffectiveStateValue(person);
        var stateClass = StateClass(state);
        if (stateClass == 1)
            return new PersonRecordSelection(PersonSelectionOverride || person.SelectionWord5CC == 0 ? person : null);

        if (stateClass != 2 && !(state > 0x14 && state < 0x1f) && !(state > 0x27 && state < 0x32))
            return null;

        if (PersonSelectionOverride) return new PersonRecordSelection(person);
        if (state <= 0x14 || state >= 0x1f)
        {
            if (StoredSlotPersonId is { } stored && person.SelectionWord606 == stored)
                return new PersonRecordSelection(person);
        }

        return new PersonRecordSelection(person.SelectionWord5CC != 2 ? person : null);
    }

    public void ApplyPersonRecordSelection(XObject? selected, ISimulationHost? host = null)
    {
        var previous = WalkOrder.FirstOrDefault(item => (item.Flags & 2) != 0);
        if (ReferenceEquals(previous, selected)) return;

        if (previous is not null)
        {
            SetPersonSelectionFlags(previous, (byte)(previous.Flags & 0x1d), host);
            host?.RefreshDisplay();
            host?.SelectedPersonChanged(previous);
        }

        if (selected is null)
        {
            DispatchNotice(0xe4, 0);
            return;
        }

        SetPersonSelectionFlags(selected, (byte)((selected.Flags & 0x1f) | 2), host);
        host?.RefreshDisplay();
        host?.SelectedPersonChanged(selected);
        DispatchNotice(0xe4, selected.RequestKey);
    }

    private void SetPersonSelectionFlags(XObject person, byte lowFiveBits, ISimulationHost? host)
    {
        lowFiveBits &= 0x1f;
        if (person.Definition[(int)ObjdField.MasterId] != 0)
        {
            if (HasFunction(person, 8))
            {
                if ((person.Flags & 0x1f) != lowFiveBits)
                {
                    person.Flags = person.Flags & ~0x1fu | lowFiveBits;
                    host?.RefreshDisplay();
                }
                return;
            }

            SetMultiTilePersonSelectionFlags(person, lowFiveBits, host);
            return;
        }

        if ((person.Flags & 0x1f) == lowFiveBits) return;
        person.Flags = person.Flags & ~0x1fu | lowFiveBits;
        host?.RefreshDisplay();
    }

    private void SetMultiTilePersonSelectionFlags(XObject person, byte lowFiveBits, ISimulationHost? host)
    {
        var current = person.MultiTileMasterId == 0
            ? person
            : ObjectById(person.MultiTileMasterId)
                ?? throw new InvalidOperationException($"Multi-tile object {person.Id} names missing master {person.MultiTileMasterId}.");
        var visited = new HashSet<short>();
        while (true)
        {
            if (!visited.Add(current.Id))
                throw new InvalidOperationException($"Multi-tile selection chain loops at object {current.Id}.");

            if ((current.Flags & 0x1f) != lowFiveBits)
            {
                current.Flags = current.Flags & ~0x1fu | lowFiveBits;
                host?.RefreshDisplay();
            }

            if (current.MultiTileNextId == 0) return;
            current = ObjectById(current.MultiTileNextId)
                ?? throw new InvalidOperationException($"Multi-tile object {current.Id} names missing next object {current.MultiTileNextId}.");
        }
    }

    public short EffectiveStateValue(XObject item) =>
        item.StateValue != 0 ? item.StateValue : NeighborInteractionGlobalStateValue;

    public int StateClass(short state)
    {
        if (state == 0) return 1;
        foreach (var entry in StateClasses)
            if (entry.State == state) return entry.Class;
        return 0;
    }

    public void RunLotUpkeep(XObject runningObject)
    {
        ArgumentNullException.ThrowIfNull(runningObject);
        if (!LotUpkeepManagerPresent) return;

        IReadOnlyList<short> minResources;
        if (runningObject.LotUpkeepGateByte14C)
        {
            if (runningObject.TableWord10C == 0 || runningObject.TableWord10C != GlobalPerson.LotUpkeepMatchWord22 ||
                StateClass(EffectiveStateValue(runningObject)) != 1 || !runningObject.LotUpkeepPointer128Present)
                return;
            minResources = runningObject.LotUpkeepMinimumResources;
        }
        else if (TryLookupActiveFamilyUpkeep is { } lookup &&
                 lookup(out var familyNumber, out var hasMembers, out var familyResources) &&
                 familyNumber != 0 &&
                 familyNumber == GlobalPerson.LotUpkeepMatchWord22 &&
                 StateClass(unchecked((short)ActiveLotNumber)) == 1 &&
                 hasMembers &&
                 familyResources.Count >= 6)
        {
            minResources = familyResources;
        }
        else
        {
            return;
        }

        var resources = ObjectByTypeRecordKey(unchecked((int)0xB6C90029))?.Attributes;
        if (resources is null) return;
        if (resources.Length < 6)
            throw new InvalidOperationException("Sims.exe FUN_00410b89 requires six Magic Master Spells resource attributes.");
        for (var i = 0; i < 6; i++)
            if (resources[i] < minResources[i])
                resources[i] = minResources[i];
    }

    public void UpdatePersonRoomMotive(XPerson person)
    {
        ArgumentNullException.ThrowIfNull(person);
        var currentRoom = unchecked((ushort)person.RoomWord84);
        var previousRoom = person.LastObservedRoomIdAFC;
        person.LastObservedRoomIdAFC = currentRoom;
        if (previousRoom != currentRoom && person[PersonData.Gender] < 2)
        {
            if (PersonRoomMotiveEntries.ContainsKey(previousRoom) &&
                !Objects.Values.OfType<XPerson>().Any(other => !ReferenceEquals(other, person) &&
                    (other.FootprintFlags614 & 1) == 0 && (other.FootprintFlags634 & 1) == 0 &&
                    other.LastObservedRoomIdAFC == previousRoom))
                SetRoomLightsEnabled(previousRoom, enabled: false);
            if (PersonRoomMotiveEntries.ContainsKey(currentRoom))
                SetRoomLightsEnabled(currentRoom, enabled: true);
        }
        if (previousRoom != currentRoom &&
            ((person.Flags & 2) != 0 || this[SimulationGlobal.SelectedPersonID] == person.Id))
            DispatchNotice(0xf7, 0);
        if (currentRoom == 0xfffb) return; // Room ID 0xfffb (-5) represents the off-lot sentinel value.

        var motive = 0f;
        if (PersonRoomMotiveEntries.TryGetValue(currentRoom, out var room))
            motive = room.IsOutside ? OutsidePersonRoomMotiveValue : room.InteriorValue;
        var stateValue = EffectiveStateValue(person);
        if (currentRoom == 0 && StateClass(stateValue) != 1 && motive < 0f)
            motive = 0f;
        person[Motive.Room] = motive;
    }

    internal void RefreshPersonRoomStateAfterMovement(XPerson person)
    {
        ArgumentNullException.ThrowIfNull(person);
        if (person.LastObservedRoomIdAFC == unchecked((ushort)person.RoomWord84)) return;
        UpdatePersonRoomMotive(person);
    }

    internal void RefreshPersonPlacementCallbacksAfterMovement(XPerson person)
    {
        ArgumentNullException.ThrowIfNull(person);
        RefreshPersonRoomStateAfterMovement(person);
        InvalidateAnimatorRootGrid(person);
        person.AnimatorPoolTile = IsPoolTile(person.Position);
    }

    private static void InvalidateAnimatorRootGrid(XPerson person)
    {
        person.AnimatorRootX = null;
        person.AnimatorRootY = null;
        person.AnimatorRootDirection = null;
    }

    private void SetRoomLightsEnabled(ushort roomId, bool enabled)
    {
        if (!PersonRoomMotiveEntries.TryGetValue(roomId, out var room) || room.IsOutside ||
            room.LightsEnabledFlag73 == (enabled ? 1 : 0) || room.LightOverrideFlag75 != 0)
            return;

        room.LightsEnabledFlag73 = enabled ? (byte)1 : (byte)0;
        PersonRoomMotiveEntries[roomId] = room;
        if (room.LightingObjectCount140 != 0 || room.LightLevel6c >= SimsEngine.World.RoomScoreTuning.DaylightCeiling)
            return;

        DispatchNotice(0xf1, roomId);
        var light = enabled ? SimsEngine.World.RoomScoreTuning.DaylightCeiling : room.LightLevel6c;
        foreach (var (level, roomMap) in LotRoomMaps)
        {
            if (!LotRoomLightMaps.TryGetValue(level, out var grid) || !roomMap.RoomIds.Contains(roomId)) continue;
            WriteRoomLightMap(roomMap, roomId, light);
            break;
        }
    }

    public bool SleepWritesWaitCell(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        if (item.Definition[(int)ObjdField.Type] == 2) return false;
        if (item.RuntimeSlots.Count > 0 && item.RuntimeSlots[0].ReadWord(0x10) != 0) return false;
        return item.SleepGateWord7C == 0;
    }

    public void RefreshNeighborInteractionManager()
    {
        var managerAllowsSelection = StateClass(NeighborInteractionGlobalStateValue) == 1;
        foreach (var item in WalkOrder.OfType<XPerson>())
        {
            var selection = item.SelectionWord5CC == 0 ? (short)1 : item.SelectionWord5CC;
            var typeRecord = item.TypeRecord
                ?? throw new InvalidOperationException($"Sims.exe FUN_0045741b would dereference a missing type record on object {item.Id}.");
            if (NeighborInteractionManagerTypeKeys.Contains(typeRecord.Key)) selection = 0;
            if (!managerAllowsSelection && selection == 0) selection = 1;
            item.SelectionWord5CC = selection;
        }
    }

    public XObject? ObjectById(short id) => Objects.GetValueOrDefault(id);

    public void MaintainLotList(XObject owner)
    {
        var wasEmpty = WorldLotListEntries.Count == 0 && owner.LotListEntries.Count == 0;
        owner.LotListEntries.Add(owner);
        WorldLotListEntries.Add(owner);
        if (wasEmpty) DispatchNotice(0x108, 0);
    }

    public void RemoveFromLotList(XObject owner)
    {
        var wasEmpty = WorldLotListEntries.Count == 0 && owner.LotListEntries.Count == 0;
        var index = owner.LotListEntries.FindIndex(item => ReferenceEquals(item, owner));
        if (index >= 0) owner.LotListEntries.RemoveAt(index);
        var worldIndex = WorldLotListEntries.FindIndex(item => ReferenceEquals(item, owner));
        if (worldIndex >= 0) WorldLotListEntries.RemoveAt(worldIndex);
        var isEmpty = WorldLotListEntries.Count == 0 && owner.LotListEntries.Count == 0;
        if (wasEmpty != isEmpty) DispatchNotice(0x108, 0);
    }

    public XObject? FindInteractionObjectByTableWord(short id)
    {
        foreach (var item in InteractionLookupOrder)
            if (item.TableWord10C == id) return item;
        return null;
    }

    public XObject? NeighborTableEntry(short index) =>
        index > 0 && index <= NeighborTableEntries.Count ? NeighborTableEntries[index - 1] : null;

    public void SetNeighborTableEntry(short index, XObject? item)
    {
        if (index < 1) throw new ArgumentOutOfRangeException(nameof(index));
        while (NeighborTableEntries.Count < index) NeighborTableEntries.Add(null);
        NeighborTableEntries[index - 1] = item;
    }

    public int StackObjectCreateKey(short index) => NeighborManagerEntry(index) is { FriendEligibilityObjectFlagsB4: not null } neighbor
        ? neighbor.TypeRecordKey : 0;

    public int GenericSimsCall05Amount(XObject item)
    {
        var managerWord = GenericSimsCall05ManagerWord164;
        if (managerWord is null || managerWord == 0 || item.Position.Height != managerWord.Value)
            return unchecked(item.ObjectValueWord118 + item.ObjectValueWord11C);

        var mode = ObjectValueGlobalWord50 ?? throw MissingObjectValueState(nameof(ObjectValueGlobalWord50));
        var funds = ObjectValueGlobalWord90 ?? throw MissingObjectValueState(nameof(ObjectValueGlobalWord90));
        var word9C = ObjectValueGlobalWord9C ?? throw MissingObjectValueState(nameof(ObjectValueGlobalWord9C));
        var wordA0 = ObjectValueGlobalWordA0 ?? throw MissingObjectValueState(nameof(ObjectValueGlobalWordA0));
        var wordA4 = ObjectValueGlobalWordA4 ?? throw MissingObjectValueState(nameof(ObjectValueGlobalWordA4));
        var multiplier = ArchitectureValueMultiplier ?? throw MissingObjectValueState(nameof(ArchitectureValueMultiplier));
        var scaled = MultiplyAndTruncateX87(wordA4, multiplier);
        var availableFunds = mode == 1 ? 999_999 : funds;
        return unchecked(availableFunds + wordA0 + word9C + scaled);

        static InvalidOperationException MissingObjectValueState(string name) =>
            new($"GenericSimsCall 0x05 special value path needs {name} from the game state.");
    }

    public bool TryGetGenericSimsCall05FamilyAmount(short familyNumber, out int amount)
    {
        amount = 0;
        if (TryLookupFamilyValuation is not { } lookup ||
            !lookup(familyNumber, out var houseNumber, out var budget, out var value))
            return false;

        if (ActiveLotNumber != 0 && houseNumber == ActiveLotNumber)
        {
            var availableFunds = this[SimulationGlobal.SimlessBuildMode] == 1
                ? 999_999
                : (FamilyBudget?.ReadFamilyBudget() ?? budget);
            var simi = SavedSimulationState;
            var lotValue = simi?.Field0x9C ?? 0;
            var (furnishings, arch) = LiveLotValuationProvider?.Invoke()
                ?? (simi?.Field0xA0 ?? 0, simi?.Field0xA4 ?? 0);
            var scaled = MultiplyAndTruncateX87(arch, ArchitectureValueMultiplier ?? 0.7f);
            amount = unchecked(availableFunds + lotValue + furnishings + scaled);
        }
        else
        {
            amount = unchecked(budget + value);
        }
        return true;
    }

    private static int MultiplyAndTruncateX87(int value, float factor)
    {
        var bits = BitConverter.SingleToInt32Bits(factor);
        var exponentBits = (bits >> 23) & 0xff;
        if (exponentBits == 0xff) return 0;
        var significand = bits & 0x7fffff;
        var exponent = exponentBits == 0 ? -149 : exponentBits - 127 - 23;
        if (exponentBits != 0) significand |= 1 << 23;

        var product = new BigInteger(value) * significand;
        if ((bits & int.MinValue) != 0) product = -product;
        var negative = product.Sign < 0;
        var magnitude = BigInteger.Abs(product);
        magnitude = exponent >= 0 ? magnitude << exponent : magnitude >> -exponent;
        var truncated = negative ? -magnitude : magnitude;
        if (truncated < long.MinValue || truncated > long.MaxValue) return 0;
        return unchecked((int)(long)truncated);
    }

    public XObject? ObjectByStackObject(XObject me, short key)
    {
        if (me.ObjectTableEntries.Count > 0) return me.ObjectTableEntry(key);
        return me.HasRequestKey ? null : ObjectById(key);
    }

    public void SavePersonRecord(XPerson person)
    {
        var neighborId = person[PersonData.NeighborId];
        if (neighborId < 1 || !Neighbors.TryGetValue(neighborId, out var neighbor)) return;
        var changed = neighbor.PersonRecordVersion != 10;
        neighbor.PersonRecordVersion = 10;
        if (SavedNeighbors?.Entries.FirstOrDefault(saved => saved.NeighborId == neighborId) is { } savedNeighbor &&
            !string.Equals(savedNeighbor.Name, neighbor.Name, StringComparison.Ordinal))
            changed = true;
        if (person.Name is { } personName && !string.Equals(neighbor.Name, personName, StringComparison.Ordinal))
        {
            neighbor.Name = personName;
            changed = true;
        }
        foreach (var field in PersonRecordFieldsVersion10)
        {
            if (field >= neighbor.PersonData.Length || field >= person.PersonData.Length) continue;
            if (neighbor.PersonData[field] == person.PersonData[field]) continue;
            neighbor.PersonData[field] = person.PersonData[field];
            changed = true;
        }
        PersistentPersonDataDirty |= changed;
        if (changed) DirtyPersistentPersonNeighborIds.Add(neighborId);
    }

    public void SaveAllPersistentPersonData()
    {
        foreach (var person in WalkOrder.OfType<XPerson>()) SavePersonRecord(person);
    }

    public XObject? ObjectByTypeRecordKey(int key)
    {
        foreach (var item in WalkOrder)
        {
            var record = item.TypeRecord
                ?? throw new InvalidOperationException($"Sims.exe FUN_0045741B would dereference a missing type record on object {item.Id}.");
            if (record.Key == key) return item;
        }

        return null;
    }

    public void UpdateGenericSimsCallRequests()
    {
        var host = Host;
        foreach (var request in GenericSimsCallRequests.Snapshot())
        {
            if (request.Status != 0) continue;

            if (host is not null && !host.GenericSimsCallRequestManagerAvailable()) continue;

            var target = WalkOrder.OfType<XPerson>().FirstOrDefault(person => person.StackObjectKey == request.Temporary0);
            if (target is null)
            {
                GenericSimsCallRequests.TryComplete(
                    request.Id,
                    request.Temporary0,
                    request.Temporary1,
                    GenericSimsCallRequestStatus.Failed);
                continue;
            }

            if (host is null && !AutoProcessGenericSimsCallRequests) continue;

            GenericSimsCallRequestCompletion result;
            if (host is not null)
            {
                result = host.ProcessGenericSimsCallRequest(request, target);
            }
            else
            {
                if (request.Kind == GenericSimsCallRequestKind.Second)
                {
                    result = target.TypeRecord is not null
                        ? new GenericSimsCallRequestCompletion(0, target.StackObjectKey, Succeeded: true, TargetTypeRecordKey: target.TypeRecord.Key)
                        : new GenericSimsCallRequestCompletion(request.Temporary0, 0, Succeeded: false);
                }
                else
                {
                    result = new GenericSimsCallRequestCompletion(request.Temporary0, request.Temporary1, Succeeded: true);
                }
            }

            if (request.Kind == GenericSimsCallRequestKind.Second)
            {
                if (target is not null && !result.Succeeded)
                {
                    result = result with { Temporary0 = request.Temporary0, Temporary1 = 0 };
                }
                else if (result.Succeeded)
                {
                    var key = result.TargetTypeRecordKey
                        ?? throw new InvalidOperationException("GenericSimsCall request kind 1 succeeded without a type-record key.");
                    var resultPerson = ObjectByTypeRecordKey(key)
                        ?? throw new InvalidOperationException($"GenericSimsCall request kind 1 could not resolve type-record key {key}.");
                    result = result with { Temporary0 = 0, Temporary1 = resultPerson.StackObjectKey };
                }
            }

            if (result.Succeeded) GlobalPerson.ByteE0 = 1;
            GenericSimsCallRequests.TryComplete(
                request.Id,
                result.Temporary0,
                result.Temporary1,
                result.Succeeded ? GenericSimsCallRequestStatus.Succeeded : GenericSimsCallRequestStatus.Failed);
        }

        GenericSimsCallRequests.AdvanceTick();
    }

    public int TickSavedExecutionStacks(int? tickCounter = null)
    {
        var currentTick = tickCounter ?? Clock.Ticks;
        var scheduled = 0;
        foreach (var owner in WalkOrder.ToArray())
        {
            if (!Objects.TryGetValue(owner.Id, out var current) || !ReferenceEquals(current, owner) ||
                !SavedExecutionStacks.ContainsKey(owner.Id))
                continue;

            bool completed;
            try
            {
                completed = TreeRunner.RunRestoredObjectStack(this, owner);
            }
            catch (Exception error) when (error is SimulationException or InvalidOperationException or TreeRunException)
            {
                throw new InvalidOperationException($"Saved object {owner.Id}: {error.Message} ({CurrentExecutionLocation ?? "no current instruction"})", error);
            }
            if (owner is XPerson scalingPerson) UpdateAnimatorBodyScale(scalingPerson, currentTick);
            if (completed) FinishObjectSimulation(owner);
            if (completed && owner is XPerson animatingPerson)
            {
                TickAvatarAnimations(animatingPerson);
            }
            if (completed && owner is XPerson person) ApplyPersonPostUpdate(person, currentTick);
            scheduled++;
        }
        CommitPendingObjectRemovals();
        return scheduled;
    }

    internal static void UpdateAnimatorBodyScale(XPerson person, int simulationTick)
    {
        if (person.PersonTickGateWord8E != 0 || person.AnimatorScaleUpdateSuppressed || simulationTick % 10 != 0) return;
        var scale = person[PersonData.ScalingSim] / 100f;
        if (scale > 0.4f && scale < 10f) person.AnimatorBodyScale = scale;
    }

    private void FinishObjectSimulation(XObject item)
    {
        if (item[ObjectData.LockoutCount] != 0)
            item[ObjectData.LockoutCount]--;
        foreach (var slot in item.RuntimeSlots)
            if (slot.Tick()) DisplayRefreshRequested = true;
    }

    private void ApplyPersonPostUpdate(XPerson person, int tickCounter)
    {
        if (unchecked(person.MotiveDecayLastTickCounter + 60) <= tickCounter)
        {
            person.MotiveDecayLastTickCounter = tickCounter;
            if (person[PersonData.MotivesStatic] == 0 && person.PersonTickGateWord8E == 0)
                PersonMotiveDecayTuning?.Apply(person, Clock.Hour);
        }
        UpdatePersonRoomMotive(person);
        person[PersonData.TickCounter] = unchecked((short)(person[PersonData.TickCounter] + 1));
        person.ApplyMotiveChanges();
        ProcessPersonMoneyOverhead(person);
    }

    public int AdvanceSimulationTick(bool advanceGameTime = false)
    {
        AdvanceClock(advanceGameTime, simulationTickCompleted: advanceGameTime);
        var scheduled = TickSavedExecutionStacks(Clock.Ticks);
        UpdateGenericSimsCallRequests();
        RefreshPendingRoomGroups();
        return scheduled;
    }

    public int AdvanceSimulationTick(
        SimulationClockControl control,
        short clockState28,
        int clockTickCounter,
        Func<XObject, int, bool> tickClockObject)
    {
        var ambientRandomState = RandomState;
        RandomState = ObjectManagerRandomState;
        SimulationClockManagerResult result;
        try
        {
            result = ClockManager.Evaluate(control, clockState28, clockTickCounter, tickClockObject);
        }
        finally
        {
            ObjectManagerRandomState = RandomState;
            RandomState = ambientRandomState;
        }
        CommitPendingObjectRemovals();
        var advanceGameTime = result == SimulationClockManagerResult.PassComplete && !control.GlobalTimeHold;
        AdvanceClock(advanceGameTime, simulationTickCompleted: result == SimulationClockManagerResult.PassComplete);
        UpdateGenericSimsCallRequests();
        RefreshPendingRoomGroups();
        return ClockManager.ObjectCallbacksLastEvaluation;
    }

    internal void AdvanceClock(bool advanceGameTime = true, bool simulationTickCompleted = true)
    {
        var result = Clock.Tick(advanceGameTime, simulationTickCompleted);
        if (!simulationTickCompleted) return;

        if (advanceGameTime)
        {
            this[SimulationGlobal.Hour] = checked((short)Clock.Hour);
            this[SimulationGlobal.Minute] = checked((short)Clock.Minute);
            this[SimulationGlobal.Second] = checked((short)Clock.Second);
            this[SimulationGlobal.TimeOfDay] = checked((short)Clock.TimeOfDay);
        }

        if (!result.DayChanged) return;

        var date = CurrentDate ?? SimulationDate.Initial;
        var day = date.Day + 1;
        var month = date.Month;
        var year = date.Year;
        if (day > 30)
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        var nextDate = new SimulationDate(checked((short)year), checked((short)month), checked((short)day));
        CurrentDate = nextDate;
        this[SimulationGlobal.DaysRunning] = unchecked((short)(this[SimulationGlobal.DaysRunning] + 1));
        if (nextDate.Month != date.Month) this[SimulationGlobal.MaximumDayNumber] = 30;
        this[SimulationGlobal.DayOfMonth] = nextDate.Day;
        this[SimulationGlobal.Month] = nextDate.Month;
        this[SimulationGlobal.Year] = nextDate.Year;
        foreach (var item in (WalkOrder.Count > 0 ? (IEnumerable<XObject>)WalkOrder : Objects.Values).ToArray())
        {
            RecomputeObjectAge(item, nextDate);
            DepreciateObjectForDay(item);
        }
        FamilyBudget?.AdvanceBudgetDay();
    }

    private void RefreshPendingRoomGroups()
    {
        if ((RoomManagerRefreshFlags & 1) != 0) RefreshDirtyRoomRecords(1);
        if ((RoomManagerRefreshFlags & 2) != 0) RefreshDirtyRoomRecords(2);
    }

    private void CommitPendingObjectRemovals()
    {
        if (PendingRemovals.Count == 0) return;
        var removals = PendingRemovals.Distinct().ToArray();
        PendingRemovals.Clear();
        foreach (var id in removals)
        {
            KillObject(id);
        }
    }
}
