using SimsEngine.Formats;
using SimsEngine.Content;
using SimsEngine.Character;
using System.Numerics;

namespace SimsEngine.Simulation;

public sealed partial class SimulationWorld
{

    public bool CancelInteractionAction(XPerson person, int sequence)
    {
        ArgumentNullException.ThrowIfNull(person);
        if (sequence == person.GenericSimsCall02GateWordA84)
        {
            if (person.CurrentActionRecord?.Owner is null) return false;
            if (InteractionLifecycle.TryRequestGracefulExit(person, sequence)) return true;
            person.ActivePriority = 0;
            person.ActiveActionCancelRequested = true;
            if (!IdleForInputPrimitive.ShouldInterrupt(this, person) &&
                person.TypeRecord?.Interactions?.Interactions.FirstOrDefault(entry => entry.TtaIndex == 0x21) is { } cancelEntry)
            {
                if ((cancelEntry.Flags & 4) == 0)
                {
                    EnqueueInteractionAction(person, person, cancelEntry, 0x21, 50, null, secondarySpecified: true, recordFlags: 0);
                }
                else if (!ImmediateInteractionRunning && person.TypeRecord.BehaviorScope is { } scope)
                {
                    var immediate = new ActionQueueSlot
                    {
                        Person = person,
                        Owner = person,
                        Secondary = null,
                        RawDword10 = 0x21,
                        ActionTree = cancelEntry.ActionTree,
                        Threshold = 50,
                        Flags = (cancelEntry.Flags & 0x100) != 0 ? 1 : 0,
                    };
                    InteractionTestEvaluator.Evaluate(this, person, [immediate], autonomy: false);
                    if ((immediate.Flags & InteractionTestEvaluator.Passed) != 0)
                    {
                        var previousPriority = person.ActivePriority;
                        var previousImmediate = ActiveImmediateAction;
                        var previousImmediatePerson = ActiveImmediatePerson;
                        ImmediateInteractionRunning = true;
                        ActiveImmediateAction = immediate;
                        ActiveImmediatePerson = person;
                        person.ActivePriority = 50;
                        try
                        {
                            TreeRunner.RunWithParameters(this, person, scope, unchecked((short)cancelEntry.ActionTree),
                                person.StackObjectKey, immediate.Parameters);
                        }
                        finally
                        {
                            person.ActivePriority = previousPriority;
                            ImmediateInteractionRunning = false;
                            ActiveImmediateAction = previousImmediate;
                            ActiveImmediatePerson = previousImmediatePerson;
                        }
                    }
                }
            }
            return true;
        }

        var count = unchecked(person.ActionQueueEnd - person.ActionQueueCurrent);
        if (count is < 0 or > 8) return false;

        var survivors = new List<ActionQueueSlot>(count);
        var removed = false;
        for (var index = 0; index < count; index++)
        {
            var action = person.ActionQueue[(person.ActionQueueCurrent + index) & 7];
            if (action.Sequence == sequence)
            {
                removed = true;
                if (action.Owner is not null)
                    ActionQueueRemovalNotices.Add(new ActionQueueRemovalNotice(person.RequestKey, 0));
            }
            else survivors.Add(action.Copy());
        }

        if (!removed) return false;
        for (var index = 0; index < person.ActionQueue.Length; index++)
            person.ActionQueue[index] = ActionQueueSlot.EmptyRecord();
        for (var index = 0; index < survivors.Count; index++)
            person.ActionQueue[index] = survivors[index];
        person.ActionQueueCurrent = 0;
        person.ActionQueueEnd = survivors.Count;
        return true;
    }

    public void ApplyStartedInteractionAction(XPerson person, ActionQueueSlot action)
    {
        if (person.CurrentActionRecord is { Owner: not null } current)
            InteractionLifecycle.FinalizeAction(person, current.Sequence);
        var sequence = action.Owner is not null && action.Sequence == 0
            ? unchecked(++_actionQueueSequence)
            : (int?)null;
        person.ApplyStartedActionState(action, sequence);
        person.ActiveActionCancelRequested = false;
    }

    public bool RequestInteractionExit(XPerson person, int actionSequence)
    {
        if (person.CurrentActionRecord is not { Owner: not null } current || current.Sequence != actionSequence) return false;
        return InteractionLifecycle.TryRequestGracefulExit(person, actionSequence);
    }

    public void ApplyPersonObjectReferenceActionChanges(XPerson person, XObject subject)
    {
        if (person.PreviousActionRecord is { } previous)
        {
            if (ReferenceEquals(previous.Owner, subject)) person.ClearPreviousActionRecord();
            else if (ReferenceEquals(previous.Secondary, subject)) previous.Secondary = null;
        }

        if (person.CurrentActionRecord is { } current)
        {
            if (ReferenceEquals(current.Owner, subject))
                ApplyStartedInteractionAction(person, ActionQueueSlot.EmptyRecord());
            else if (ReferenceEquals(current.Secondary, subject))
                current.Secondary = null;
        }

        if (ReferenceEquals(person.GenericSimsCall02ObjectA54, subject))
            person.SetCurrentActionSecondaryReference(null);
    }

    public static bool TryDequeueInteractionAction(XPerson person, out ActionQueueSlot? action)
    {
        var current = person.ActionQueueCurrent;
        if (unchecked((uint)current) >= unchecked((uint)person.ActionQueueEnd))
        {
            action = null;
            return false;
        }

        action = person.ActionQueue[current & 7].Copy();
        person.ActionQueueCurrent = unchecked(current + 1);
        return true;
    }

    internal float InteractionAttenuation(XPerson person, Interaction interaction)
    {
        var tuning = SimulatorTuning;
        var visitor = person.SelectionWord5CC != 0;
        return interaction.AttenuationCode switch
        {
            0 => interaction.AttenuationValue,
            1 => 0f,
            2 => visitor ? tuning.VisitorLowAttenuation : tuning.FamilyLowAttenuation,
            3 => visitor ? tuning.VisitorModerateAttenuation : tuning.FamilyModerateAttenuation,
            4 => visitor ? tuning.VisitorHighAttenuation : tuning.FamilyHighAttenuation,
            _ => tuning.FallbackAttenuation,
        };
    }

    public T Add<T>(T item) where T : XObject
    {
        var initialTable = item.ObjectTableEntries;
        if (Objects.TryGetValue(item.Id, out var previous))
        {
            if (!ReferenceEquals(previous, item))
                UnplaceObjectFromGridOrSlot(previous);
            WalkOrder[WalkOrder.IndexOf(previous)] = item;
            if (!ReferenceEquals(previous, item))
            {
                ClockManager.Remove(previous);
                SavedExecutionStacks.Remove(item.Id);
            }
        }
        else WalkOrder.Add(item);
        Objects[item.Id] = item;
        var itemGuid = TypeAttributesGuid(item);
        if (itemGuid != 0)
        {
            var numTypeAttributes = unchecked((short)item.Definition[(int)ObjdField.NumTypeAttributes]);
            var definitionAttributeCount = numTypeAttributes is > 0 and <= 31999
                ? numTypeAttributes
                : (int)(ushort)item.Definition[(int)ObjdField.NumAttributes];
            if (SharedTypeAttributes.TryGetValue(itemGuid, out var shared))
            {
                if (!ReferenceEquals(shared, item.TypeAttributes))
                {
                    var minLength = Math.Max(definitionAttributeCount, item.TypeAttributes.Length);
                    if (shared.Length < minLength)
                        shared = GetOrCreateTypeAttributes(itemGuid, minLength);
                    if (item.TypeAttributes.Any(value => value != 0) && shared.All(value => value == 0))
                        item.TypeAttributes.CopyTo(shared, 0);
                    item.TypeAttributes = shared;
                }
            }
            else if (item.TypeAttributes.Length > 0)
            {
                SharedTypeAttributes[itemGuid] = item.TypeAttributes;
            }
            else
            {
                item.TypeAttributes = GetOrCreateTypeAttributes(itemGuid, definitionAttributeCount > 0 ? definitionAttributeCount : 8);
            }
        }
        if (item.AssociatedPlacementHelper is null && (item.TypeRecord?.ExtensionFlagsCC & 1) != 0)
        {
            if (item.TypeRecord is { ObjectType: not XPerson.PersonType } typeRecord)
                typeRecord.RuntimeExtension88Initialized = true;
            item.AssociatedPlacementHelper = new AssociatedPlacementHelper();
            item.AssociatedPlacementHelper.Initialize(item);
            item.AssociatedPlacementExtensionFlag180 = true;
        }
        if (item is XPerson person) InitializePersonTypeRecord(person);
        if (!ReferenceEquals(previous, item))
        {
            var slot = ClockManager.Register(item);
            while (_objectTableEntries.Count < slot) _objectTableEntries.Add(null);
            _objectTableEntries[slot - 1] = item;
            foreach (var existing in WalkOrder) existing.AttachObjectTable(_objectTableEntries);
            InsertTileRoot(item);
            for (var index = 0; index < initialTable.Count; index++)
                if (initialTable[index] is { } entry && (index >= _objectTableEntries.Count || _objectTableEntries[index] is null))
                {
                    while (_objectTableEntries.Count <= index) _objectTableEntries.Add(null);
                    _objectTableEntries[index] = entry;
                }
            foreach (var existing in WalkOrder) existing.AttachObjectTable(_objectTableEntries);
        }
        return item;
    }

    public bool Remove(short id)
    {
        if (!Objects.Remove(id, out var item)) return false;
        if (item is XPerson person) InteractionLifecycle.FinalizeActor(person);
        else InteractionLifecycle.FinalizeRink(item);
        StopObjectSounds(id);
        UnplaceObjectFromGridOrSlot(item);
        var tableSlot = item.ClockManagerIndex;
        if (tableSlot > 0)
        {
            for (var i = 1; i < item.Slots.Count; i++)
            {
                var childKey = item.Slots[i];
                if (childKey <= 0 || (item.ObjectTableEntry(childKey) ?? ObjectTableEntry(childKey)) is not { } child)
                    continue;
                if (child[ObjectData.ParentId] == tableSlot)
                {
                    child[ObjectData.ParentId] = 0;
                    child[ObjectData.SlotHierNumber] = -1;
                }
            }
        }
        WalkOrder.Remove(item);
        var hadLotListEntries = WorldLotListEntries.Count > 0;
        item.LotListEntries.Clear();
        WorldLotListEntries.RemoveAll(entry => ReferenceEquals(entry, item));
        ClockManager.Remove(item);
        if (tableSlot > 0 && tableSlot <= _objectTableEntries.Count && ReferenceEquals(_objectTableEntries[tableSlot - 1], item))
            _objectTableEntries[tableSlot - 1] = null;
        SavedExecutionStacks.Remove(id);
        foreach (var existing in WalkOrder)
        {
            if (existing is not XPerson existingPerson) continue;
            existingPerson.SavedPersonObjectReferences.RemoveAll(reference => ReferenceEquals(reference.Target, item));
            if (ReferenceEquals(existingPerson.GenericSimsCall02ObjectA54, item))
                existingPerson.SetCurrentActionSecondaryReference(null);
            existingPerson.InvalidateRuntimeObjectReferences(item);
        }
        if (hadLotListEntries && WorldLotListEntries.Count == 0)
            DispatchNotice(0x108, 0);
        return true;
    }

    public bool KillObject(short id)
    {
        if (ObjectById(id) is not { } target) return false;
        if ((target.MultiTileMasterId != 0 || target.MultiTileNextId != 0) && !HasFunction(target, 8))
        {
            var members = MultiTileMembers(target).ToArray();
            foreach (var member in members)
                member.Flags = (member.Flags & ~DyingObjectFlag) | DyingObjectFlag;
            var removedAny = false;
            foreach (var member in members)
            {
                DispatchNotice(0x87, member.Id);
                NotifyPersonObjectReferenceRecipients(member);
                if (member is XPerson killedMemberPerson) ResetPersonForChangedCode(killedMemberPerson);
                DetachFromFootprintSlot(member);
                if (!Remove(member.Id)) continue;
                DispatchNotice(0x88, member.Id);
                removedAny = true;
            }
            return removedAny;
        }
        DispatchNotice(0x87, id);
        if (target is XPerson && ((target.Flags & 2u) != 0 || this[SimulationGlobal.SelectedPersonID] == id))
        {
            this[SimulationGlobal.SelectedPersonID] = 0;
            if ((target.Flags & 2u) != 0)
                ApplyPersonRecordSelection(null, Host);
            else
                DispatchNotice(0xe4, 0);
        }
        target.Flags = (target.Flags & ~DyingObjectFlag) | DyingObjectFlag;
        NotifyPersonObjectReferenceRecipients(target);
        if (target is XPerson killedPerson) ResetPersonForChangedCode(killedPerson);
        DetachFromFootprintSlot(target);
        StopObjectSounds(id);
        if (!Remove(id)) return false;
        DispatchNotice(0x88, id);
        return true;
    }

    public int RoomArea(short roomId)
    {
        var uRoom = unchecked((ushort)roomId);
        var outside = RoomIsOutside(roomId);
        foreach (var map in LotRoomMaps.Values)
        {
            var area = map.RoomHalfArea(uRoom, outside);
            if (area > 0) return area;
        }
        return 0;
    }

    public bool FacingClear(int tileX, int tileY, int level, int facing) =>
        !LotRoomMaps.TryGetValue(level, out var roomMap) ||
        !BlocksRouteDirectionAt(roomMap, tileX, tileY, facing);

    public InteractionBehaviorActionList? GetInteractionBehaviorActions(XObject me, int listIndex) =>
        me is XPerson person ? WardrobeSuitService.GetActionList(this, person, null, listIndex) : null;

    internal ISimulationHost RequireHost() => Host ?? throw new InvalidOperationException(
        CurrentExecutionLocation is { } location
            ? $"This variable needs a simulation host ({location})."
            : "This variable needs a simulation host.");

    internal ISimulationHost RequireHost(string operation) => Host ?? throw new InvalidOperationException(
        CurrentExecutionLocation is { } location
            ? $"This operation needs a simulation host for {operation} ({location})."
            : $"This operation needs a simulation host for {operation}.");

    internal ISimulationCareerHost RequireCareerHost(string operation) =>
        CareerHost ?? (ISimulationCareerHost?)Host ?? throw new InvalidOperationException(
            CurrentExecutionLocation is { } location
                ? $"This operation needs career data for {operation} ({location})."
                : $"This operation needs career data for {operation}.");

    internal ISimulationAutonomyHost RequireAutonomyHost() => AutonomyHost ?? Host ?? throw new InvalidOperationException(
        CurrentExecutionLocation is { } location
            ? $"This autonomy service needs a simulation host ({location})."
            : "This autonomy service needs a simulation host.");

    internal IFamilyBudget RequireFamilyBudget() => FamilyBudget ?? throw new InvalidOperationException("This primitive needs the family budget.");

    public SimsEngine.Formats.IffFile? UiTextFile { get; set; }

    public string? UiTextString(ushort tableId, int index)
    {
        if (UiTextFile?.Find(SimsEngine.Formats.ResourceType.Str, tableId) is { } chunk)
        {
            var strings = SimsEngine.Formats.StringTable.Read(UiTextFile, chunk).ForLanguage(Language);
            if (index >= 0 && index < strings.Count && strings[index].Length > 0) return strings[index];
        }
        return ObjectRegistry?.UiTextString(tableId, index, Language);
    }

    public DialogWords Dialog { get; } = new();

    public List<SimulationDialogRecord> DialogRecords { get; } = [];
    private long _dialogSequence;
    private int? _dialogOwnedGenericSimsCall03PrimaryHandle;

    public void SyncGenericSimsCall03DialogHandle()
    {
        if (Host is not null) return;
        if (HasVisibleDialog)
        {
            if (GenericSimsCall03State.PrimaryHandle == 0)
            {
                var handle = unchecked((int)Math.Max(1L, _dialogSequence));
                GenericSimsCall03State.PrimaryHandle = handle;
                if (GenericSimsCall03State.LinkedGlobalWord60 is null or 0)
                    GenericSimsCall03State.LinkedGlobalWord60 = 0xf;
                _dialogOwnedGenericSimsCall03PrimaryHandle = handle;
            }
            return;
        }
        if (_dialogOwnedGenericSimsCall03PrimaryHandle is { } owned &&
            GenericSimsCall03State.PrimaryHandle == owned)
        {
            GenericSimsCall03State.PrimaryHandle = 0;
            if (GenericSimsCall03State.LinkedGlobalWord60 == 0xf)
                GenericSimsCall03State.LinkedGlobalWord60 = 0;
            _dialogOwnedGenericSimsCall03PrimaryHandle = null;
        }
    }

    public void DismissVisibleDialogRecords()
    {
        for (var i = DialogRecords.Count - 1; i >= 0; i--)
        {
            var record = DialogRecords[i];
            if (!record.Visible) continue;
            record.State = record.AwaitsResponse ? 2 : 5;
            record.Visible = false;
            if (!record.AwaitsResponse)
                DialogRecords.RemoveAt(i);
        }
        if (_dialogOwnedGenericSimsCall03PrimaryHandle is { } owned &&
            GenericSimsCall03State.PrimaryHandle == owned)
        {
            GenericSimsCall03State.PrimaryHandle = 0;
            if (GenericSimsCall03State.LinkedGlobalWord60 == 0xf)
                GenericSimsCall03State.LinkedGlobalWord60 = 0;
        }
        _dialogOwnedGenericSimsCall03PrimaryHandle = null;
        ShowNextDialogRecord();
        SyncGenericSimsCall03DialogHandle();
    }

    public SimulationDialogRecord? DialogRecord(XObject owner) =>
        DialogRecords.FirstOrDefault(record => ReferenceEquals(record.Owner, owner));

    public int? DialogRecordState(XObject owner) => DialogRecord(owner)?.State;

    public bool HasVisibleBlockingDialog => DialogRecords.Any(record => record.Visible && record.Blocking && record.State < 2);
    public bool HasVisibleDialog => DialogRecords.Any(record => record.Visible);

    public SimulationDialogRecord? CreateMessageDialog(XObject owner, XObject? icon, string title, string message,
        string? yes, string? no, string? cancel, byte kind = 0, bool blocking = true, bool awaitsResponse = true)
    {
        var record = new SimulationDialogRecord($"native-dialog-{++_dialogSequence}", owner, icon, kind, title, message,
            yes, no, cancel, blocking, awaitsResponse)
        {
            Visible = blocking ? !HasVisibleBlockingDialog : !HasVisibleDialog,
            State = !awaitsResponse && !blocking ? 1 : 0,
        };
        DialogRecords.Add(record);
        SyncGenericSimsCall03DialogHandle();
        return record;
    }

    // style: 0 = Spellbook, 1 = Cookbook.
    public SimulationDialogRecord? CreateBookDialog(XPerson owner, byte style)
    {
        if (style > 1) throw new ArgumentOutOfRangeException(nameof(style));
        if (HasVisibleDialog) return null;
        var familyNumber = owner[PersonData.FamilyNumber];
        if (familyNumber == 0 && Neighbors.TryGetValue(owner[PersonData.NeighborId], out var neighbor))
            familyNumber = neighbor.PersonData[(int)PersonData.FamilyNumber];
        var familyName = familyNumber != 0 ? MenuTextSources?.FamilyName(familyNumber) : null;
        if (string.IsNullOrWhiteSpace(familyName))
            familyName = !string.IsNullOrWhiteSpace(owner.Name) ? owner.Name : owner.TypeRecord?.CatalogName ?? owner.TypeRecord?.Name;
        var record = new SimulationDialogRecord(
            $"native-dialog-{++_dialogSequence}", owner, null, style == 0 ? (byte)12 : (byte)15,
            string.IsNullOrWhiteSpace(familyName) ? "Family" : familyName, "", UiTextString(142, 0) ?? "OK", null, null, awaitsResponse: false);
        if (style == 0)
        {
            var age = owner[PersonData.PersonAge];
            record.BookMode = (byte)(age == 0 || age > 17 ? 1 : 0);
            record.BookAvailability = QuerySpellBookAvailability(owner, record.BookMode.Value);
        }
        else
        {
            record.BookMode = 2;
            if (owner.TypeRecord?.BehaviorScope is Content.BehaviorScope scope)
            {
                record.HideBookItem9 = !RunMagicMadeQuery(owner, scope, 3, 5);
                record.HideBookItem4 = !RunMagicMadeQuery(owner, scope, 4, 4);
            }
        }
        DialogRecords.Add(record);
        SyncGenericSimsCall03DialogHandle();
        return record;
    }

    private IReadOnlyList<SimulationBookAvailability> QuerySpellBookAvailability(XPerson owner, byte mode)
    {
        if (owner.TypeRecord?.BehaviorScope is not Content.BehaviorScope scope) return [];
        var savedTemporaries = owner.Temporaries.ToArray();
        try
        {
            var itemIds = MagicMasterSpellItemIds;
            short[] contexts = mode == 1 ? [0] : [0, .. itemIds];
            var result = new SimulationBookAvailability[contexts.Length * itemIds.Count];
            var index = 0;
            foreach (var contextItemId in contexts)
            foreach (var itemId in itemIds)
            {
                var made = TreeRunner.RunWithParameters(this, owner, scope, 496, owner.StackObjectKey,
                    [contextItemId, itemId]);
                result[index++] = new SimulationBookAvailability(contextItemId, itemId, made);
            }
            return result;
        }
        finally
        {
            savedTemporaries.CopyTo(owner.Temporaries, 0);
        }
    }

    private bool RunMagicMadeQuery(XPerson owner, Content.BehaviorScope scope, short contextItemId, short itemId)
    {
        var savedTemporaries = owner.Temporaries.ToArray();
        try
        {
            return TreeRunner.RunWithParameters(this, owner, scope, 496, owner.StackObjectKey,
                [contextItemId, itemId]);
        }
        finally
        {
            savedTemporaries.CopyTo(owner.Temporaries, 0);
        }
    }

    public void DismissDialogRecord(XObject owner)
    {
        var record = DialogRecord(owner);
        if (record is null) return;
        record.State = 5;
        record.Visible = false;
        ShowNextDialogRecord();
        SyncGenericSimsCall03DialogHandle();
    }

    public void RespondMessageDialog(string token, byte code, string? responseText = null)
    {
        var record = DialogRecords.FirstOrDefault(item => item.Token == token && item.Visible)
            ?? throw new ArgumentException("Dialog is no longer active.");
        if (record.Kind is 12 or 15 && record.BookMode is not null)
        {
            if (code != 0) throw new ArgumentException("Book dialog response code must be 0.");
            record.State = 2;
            record.Visible = false;
            if (!record.AwaitsResponse) DialogRecords.Remove(record);
            ShowNextDialogRecord();
            SyncGenericSimsCall03DialogHandle();
            return;
        }
        if (record.Kind == 2 || record.Kind == 14)
        {
            var max = record.Kind == 2 ? 2 : 1;
            if (code > max) throw new ArgumentException("Invalid native dialog response.");
            record.State = code switch { 0 => 2, 1 => 3, _ => 4 };
        }
        else if (record.Kind == 1)
        {
            if (code > 1) throw new ArgumentException("Invalid native dialog response.");
            record.State = code == 0 ? 2 : 3;
        }
        else if (record.Kind is 6 or 9)
        {
            if (code > 1) throw new ArgumentException("Invalid native selection response.");
            short selection = -1;
            if (code == 1 && (responseText is null || !short.TryParse(responseText.AsSpan(), System.Globalization.NumberStyles.None,
                    System.Globalization.CultureInfo.InvariantCulture, out selection) || selection < 0))
                throw new ArgumentException("A selected wardrobe or pet choice requires a nonnegative index.");
            if (record.Kind == 6)
            {
                Dialog[0xf4] = code == 1 ? (short)-2 : (short)0;
                Dialog[0xf6] = (short)selection;
            }
            else
            {
                Dialog[0x100] = (short)selection;
                Dialog[0x108] = code == 1 ? (short)-2 : (short)0;
            }
            record.State = code == 1 ? 2 : 4;
        }
        else if (record.Kind == 10)
        {
            if (code > 1 || record.Owner is not XPerson caller ||
                !short.TryParse(responseText.AsSpan(), System.Globalization.NumberStyles.AllowLeadingSign,
                    System.Globalization.CultureInfo.InvariantCulture, out var neighborId))
                throw new ArgumentException("Invalid native phone-book response.");
            if (code == 1)
            {
                if (neighborId <= 0 || !Neighbors.TryGetValue(neighborId, out var neighbor) ||
                    !Neighbors.TryGetValue(caller[PersonData.NeighborId], out var callerNeighbor) ||
                    callerNeighbor.Relationships.Count(neighborId) == 0)
                    throw new ArgumentException("The selected phone-book contact is no longer available.");
                Dialog[0xe8] = neighborId;
            }
            else
            {
                if (neighborId != -1) throw new ArgumentException("Phone-book cancellation must use -1.");
                Dialog[0xe8] = -9999;
            }
            record.State = code == 1 ? 2 : 3;
        }
        else if (record.Kind is 5 or 7 or 8 or 11 or 13)
        {
            if (code > 1 || !short.TryParse(responseText.AsSpan(), System.Globalization.NumberStyles.AllowLeadingSign,
                    System.Globalization.CultureInfo.InvariantCulture, out var destination) ||
                (code == 0 && destination != -1) || (code == 1 && destination is < 1 or > 100))
                throw new ArgumentException("Invalid native travel destination response.");
            // Maps destination dialog kinds to lot variable words for vacation, downtown, studio town,
            // community, and magic town destinations.
            var offset = record.Kind switch { 5 => 0xea, 7 => 0xec, 8 => 0xf2, 11 => 0xee, _ => 0xf0 };
            Dialog[offset] = destination;
            record.State = code == 1 ? 2 : 3;
        }
        else
        {
            if ((record.Kind is 0 or 3 or 4 or 12 or 15) && code != 0)
                throw new ArgumentException("This native Dialog type accepts only its first button.");
            if (record.Kind == 3 && responseText is { Length: > 64 })
                throw new ArgumentException("Text-entry response exceeds 64 characters.");
            if (record.Kind == 3 && responseText is not null && responseText.Any(character => character == '\0' || character is '\r' or '\n'))
                throw new ArgumentException("Text-entry response contains an unsupported character.");
            record.State = code == 0 ? 2 : code == 1 ? 3 : 4;
        }
        record.ResponseText = responseText;
        record.Visible = false;
        if (!record.AwaitsResponse || record.Kind is 5 or 6 or 7 or 8 or 9 or 10 or 11 or 13)
            DialogRecords.Remove(record);
        ShowNextDialogRecord();
        SyncGenericSimsCall03DialogHandle();
    }

    public void CompleteDialogRecord(SimulationDialogRecord record)
    {
        DialogRecords.Remove(record);
        ShowNextDialogRecord();
        SyncGenericSimsCall03DialogHandle();
    }

    private void ShowNextDialogRecord()
    {
        if (!HasVisibleBlockingDialog)
        {
            var nextBlocking = DialogRecords.FirstOrDefault(record => !record.Visible && record.Blocking && record.State < 2);
            if (nextBlocking is not null)
            {
                nextBlocking.Visible = true;
                return;
            }
        }
        if (HasVisibleDialog) return;
        var next = DialogRecords.FirstOrDefault(record => !record.Visible && record.State < 2);
        if (next is not null) next.Visible = true;
    }

    public XObject? TutorialOwner { get; set; }

    public Dictionary<StackFrame, int> PrimitiveTicks { get; } = [];
}
