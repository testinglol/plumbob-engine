using SimsEngine.Formats;
using SimsEngine.Content;
using SimsEngine.Character;
using System.Numerics;

namespace SimsEngine.Simulation;

public sealed partial class SimulationWorld
{
    public Func<XPerson, string, (float MarkerOneStride, float MarkerTwoStride)?>? LocomotionStrideResolver { get; set; }
    public Func<XPerson, XObject, HeadSeekGeometry?>? HeadSeekGeometryResolver { get; set; }
    public Func<XPerson, string, Vector3?>? AnchorBoneWorldResolver { get; set; }
    public Func<ushort, XObject, short, short[]?, bool?>? GlobalSubroutineInterceptor { get; set; }
    private static long s_uiMessageSequence;
    private readonly Dictionary<short, (StackFrame Frame, TreeStack? Stack)> _directPositionRoutes = [];
    private int _visitorAvatarAnimationKey;

    public int ActiveLotNumber { get; set; }

    public HeadlessSpecialEffectService HeadlessSpecialEffects { get; } = new();

    public List<SimulationUiMessage> UiMessages { get; } = [];

    public void RecordUiMessage(int message, string text)
    {
        UiMessages.Add(new SimulationUiMessage(Interlocked.Increment(ref s_uiMessageSequence), message, text));
        if (UiMessages.Count > 16) UiMessages.RemoveAt(0);
    }

    public uint RandomState { get; set; } = 1;

    public uint ObjectManagerRandomState { get; set; } = 1;

    public SimulationState? SavedSimulationState { get; internal set; }

    public IffFile? GlobalSprites { get; set; }

    internal ObjectRegistry? ObjectRegistry { get; set; }

    public void ReplaceSavedBudgetDays(IReadOnlyList<BudgetDay> days)
    {
        if (SavedSimulationState is { } saved) SavedSimulationState = saved.WithBudgetDays(days);
    }

    // SIMI chunk fields: fieldA0 = furnishings, fieldA4 = architecture.
    public void ReplaceSavedValuation(int fieldA0, int fieldA4)
    {
        if (SavedSimulationState is { } saved) SavedSimulationState = saved.WithValuation(fieldA0, fieldA4);
    }

    public void LoadNeighborhoodData(NeighborhoodData data)
    {
        ArgumentNullException.ThrowIfNull(data);
        data.ToVariables().CopyTo(NeighborhoodData, 0);
        NeighborInventories = data.Inventories;
        foreach (var (neighborId, inventory) in _neighborInventories)
        {
            while (inventory.Entries.Count > 0) inventory.Adjust(0, -1);
            if (NeighborInventories.TryGetValue(neighborId, out var items))
                foreach (var item in items)
                    inventory.Add(item.Type, unchecked((int)item.GUID), unchecked((short)item.Count));
        }
    }

    private readonly Dictionary<short, AvatarInventory> _neighborInventories = [];

    public event Action<short, AvatarInventory>? NeighborInventoryChanged;

    internal void RaiseNeighborInventoryChanged(short neighborId, AvatarInventory inventory) =>
        NeighborInventoryChanged?.Invoke(neighborId, inventory);

    public AvatarInventory NeighborInventory(short neighborId)
    {
        if (_neighborInventories.TryGetValue(neighborId, out var inventory)) return inventory;
        inventory = new AvatarInventory();
        if (NeighborInventories.TryGetValue(neighborId, out var items))
            foreach (var item in items) inventory.Add(item.Type, unchecked((int)item.GUID), unchecked((short)item.Count));
        return _neighborInventories[neighborId] = inventory;
    }

    public IReadOnlyDictionary<short, IReadOnlyList<NeighborhoodData.InventoryItem>> NeighborInventories { get; private set; } =
        new Dictionary<short, IReadOnlyList<NeighborhoodData.InventoryItem>>();

    public Dictionary<uint, short[]> SharedTypeAttributes { get; } = [];

    public short[] GetOrCreateTypeAttributes(uint guid, int minimumLength = 8)
    {
        var requiredLength = Math.Max(0, minimumLength);
        if (SharedTypeAttributes.TryGetValue(guid, out var existing))
        {
            if (existing.Length >= requiredLength) return existing;
            var expanded = new short[requiredLength];
            existing.CopyTo(expanded, 0);
            SharedTypeAttributes[guid] = expanded;
            foreach (var obj in WalkOrder)
                if (TypeAttributesGuid(obj) == guid) obj.TypeAttributes = expanded;
            return expanded;
        }

        var created = new short[requiredLength];
        SharedTypeAttributes[guid] = created;
        return created;
    }

    private static uint ObjectGuid(XObject item) =>
        item.TypeRecord is { Key: not 0 } record
            ? unchecked((uint)record.Key)
            : unchecked((uint)(ushort)item.Definition[(int)ObjdField.Guid1] |
                        ((uint)(ushort)item.Definition[(int)ObjdField.Guid2] << 16));

    private static uint TypeAttributesGuid(XObject item)
    {
        var proxy = unchecked((uint)(ushort)item.Definition[(int)ObjdField.TypeAttributesGuid1] |
                              ((uint)(ushort)item.Definition[(int)ObjdField.TypeAttributesGuid2] << 16));
        return proxy != 0 ? proxy : ObjectGuid(item);
    }

    public LotObjects? SavedLotObjects { get; internal set; }

    public IReadOnlyDictionary<short, (ObjectClass Class, bool Placeholder)> SavedObjectClasses { get; internal set; } =
        new Dictionary<short, (ObjectClass, bool)>();

    public int SavedObjectManagerVersion { get; internal set; }

    // Must run before WriteSavedLotObjectsTo when saving so live state is preserved.
    public (IffFile Lot, IReadOnlyList<short> Written) WriteSavedObjectManagerStateTo(IffFile lot)
    {
        ArgumentNullException.ThrowIfNull(lot);
        var source = SavedLotObjects ?? throw new InvalidDataException($"{lot.Source}: the lot has no parsed ObjM state.");
        var chunk = lot.OfType(ResourceType.Parse("ObjM")).FirstOrDefault()
            ?? throw new InvalidDataException($"{lot.Source}: no ObjM chunk was found.");
        var body = chunk.Data.Span;
        var swap = body.Length > 0 && body[0] != 0;
        var tag = System.Text.Encoding.ASCII.GetString(body[8..12]);
        var overrides = new Dictionary<short, ObjectState>();
        var written = new List<short>();
        foreach (var saved in source.Objects)
        {
            if (saved.Decoded is not { ManagerFlags: not null } state) continue;
            var instance = ObjectById(saved.ObjectId);
            if (instance is null || instance.ClockManagerIndex < 1 || instance.ClockManagerIndex > ClockManager.Entries.Count) continue;
            var flags = ClockManager.Entries[instance.ClockManagerIndex - 1].Flags;
            if (flags == state.ManagerFlags) continue;
            overrides[saved.ObjectId] = state with { ManagerFlags = unchecked((int)flags) };
            written.Add(saved.ObjectId);
        }
        if (written.Count == 0) return (lot, written);
        var reencoded = LotObjects.Write(source, swap, tag, typeIndex => SavedObjectClasses[typeIndex], overrides);
        return (lot.WithChunkDataResized(chunk.Type, chunk.Id, reencoded), written);
    }

    public (IffFile Lot, int Objects) WriteSavedLotObjectsTo(IffFile lot)
    {
        ArgumentNullException.ThrowIfNull(lot);
        var source = SavedLotObjects ?? throw new InvalidDataException($"{lot.Source}: the lot has no parsed ObjM state.");
        var chunk = lot.OfType(ResourceType.Parse("ObjM")).FirstOrDefault()
            ?? throw new InvalidDataException($"{lot.Source}: no ObjM chunk was found.");
        var body = chunk.Data.Span;
        var swap = body.Length > 0 && body[0] != 0;
        var tag = System.Text.Encoding.ASCII.GetString(body[8..12]);
        var overrides = new Dictionary<short, ObjectState>();
        var records = BuildLiveSavedObjectList(source);
        foreach (var saved in records)
        {
            if (saved.Decoded is not { } state) continue;
            var live = ObjectById(saved.ObjectId);
            if (live is null) continue;
            var values = state.Values0x108.ToArray();
            var bounds = live.FootprintBounds;
            values[0] = bounds.MinY;
            values[1] = bounds.MinX;
            values[2] = bounds.MaxY;
            values[3] = bounds.MaxX;
            values[4] = live.Position.X;
            values[5] = live.Position.Y;
            var flags = state.ManagerFlags is null || live.ClockManagerIndex < 1 ||
                        live.ClockManagerIndex > ClockManager.Entries.Count
                ? state.ManagerFlags
                : unchecked((int)ClockManager.Entries[live.ClockManagerIndex - 1].Flags);
            var personState = state.Person;
            if (live is XPerson person && personState is not null)
            {
                var personDataLength = source.Version < 0x47 ? 0x50 : 0x100;
                personState = personState with
                {
                    Character = person.SavedCharacter ?? personState.Character,
                    Values0x78C = person.Motives.ToArray(),
                    Values0x7CC = person.SavedPersonValues7CC.ToArray(),
                    PersonData = person.PersonData.Take(personDataLength).ToArray(),
                    Count0xAF0 = person.SavedPersonActionStorageCount,
                    First = (person.CurrentActionRecord ?? ActionQueueSlot.EmptyRecord()).ToSaved(),
                    Second = (person.PreviousActionRecord ?? ActionQueueSlot.EmptyRecord()).ToSaved(),
                    Actions = person.WriteActionQueue(),
                    Values = person.WriteMotiveChanges(),
                };
            }
            var isPortal = SavedObjectClasses.TryGetValue(saved.TypeIndex, out var savedClass) &&
                           savedClass.Class == Formats.ObjectClass.Portal;
            overrides[saved.ObjectId] = state with
            {
                Person = personState,
                MultiTile = (live.SavedMultiTileState ?? state.MultiTile) is { } multiTile
                    ? multiTile with
                    {
                        LeadObject = live.MultiTileMasterId,
                        PortalValues = isPortal ? multiTile.PortalValues ?? [] : multiTile.PortalValues,
                    }
                    : null,
                Relationships = live.Relationships.WriteSavedEntries(state.Relationships),
                Values0x108 = values,
                Value0x110 = live.Position.Height,
                Attributes = live.Attributes.ToArray(),
                Temps = live.Temporaries.ToArray(),
                Data = live.Data.ToArray(),
                Values0x34 = live.DynamicSpriteFlags.ToArray(),
                Slots = live.Slots.ToArray(),
                Stack = live.SavedStack.ToArray(),
                StackSize = live.SavedStackSize,
                ManagerFlags = flags,
            };
        }
        var reencoded = LotObjects.Write(source, swap, tag, typeIndex => SavedObjectClasses[typeIndex], overrides, records);
        var updated = lot.WithChunkDataResized(chunk.Type, chunk.Id, reencoded);
        var typesChunk = updated.OfType(ResourceType.Parse("objt")).FirstOrDefault()
            ?? throw new InvalidDataException($"{lot.Source}: no objt chunk was found.");
        var types = ObjectTypeTable.Read(updated, typesChunk);
        if (!types.Entries.SequenceEqual(SavedObjectTypes.Values))
        {
            var typesBody = typesChunk.Data.Span;
            var bytes = types.Write(typesBody[0] != 0, System.Text.Encoding.ASCII.GetString(typesBody[8..12]), SavedObjectTypes.Values.ToArray());
            updated = updated.WithChunkDataResized(typesChunk.Type, typesChunk.Id, bytes);
        }
        return (updated, overrides.Count);
    }

    public byte[]? WriteSavedSimulationStateChunk() => SavedSimulationState?.WriteChunkData(ObjectManagerRandomState, Globals);

    public IffFile WriteSavedSimulationStateTo(IffFile lot)
    {
        ArgumentNullException.ThrowIfNull(lot);
        var chunk = lot.OfType(ResourceType.Parse("SIMI")).FirstOrDefault()
            ?? throw new InvalidDataException($"{lot.Source}: no SIMI chunk to save.");
        var data = WriteSavedSimulationStateChunk()
            ?? throw new InvalidOperationException("This simulation world has no retained SIMI state.");
        return data.Length == chunk.Data.Length
            ? lot.WithChunkData(chunk.Type, chunk.Id, data)
            : lot.WithChunkDataResized(chunk.Type, chunk.Id, data);
    }

    public byte[] WriteSavedTypeAttributesChunk(int version = 0x49, bool coded = true, bool swap = false) =>
        TypeAttributes.Write(SharedTypeAttributes, version, coded, swap);

    public IffFile WriteSavedTypeAttributesTo(IffFile file, int version = 0x49)
    {
        ArgumentNullException.ThrowIfNull(file);
        var type = ResourceType.Parse("TATT");
        var existing = file.Find(type, 1) ?? file.OfType(type).FirstOrDefault();
        var swap = existing is { Data.Length: > 0 } && existing.Data.Span[0] != 0;
        var coded = existing is not { Data.Length: > 12 } || existing.Data.Span[12] != 0;
        var payload = WriteSavedTypeAttributesChunk(version, coded, swap);
        return existing is not null
            ? file.WithChunkDataResized(existing.Type, existing.Id, payload)
            : file;
    }

    public byte[] WriteSavedNeighborhoodDataChunk(int version = 0x49, bool swap = false)
    {
        var mergedInventories = new Dictionary<short, IReadOnlyList<Formats.NeighborhoodData.InventoryItem>>();
        foreach (var (neighborId, items) in NeighborInventories)
            mergedInventories[neighborId] = items;
        foreach (var (neighborId, liveInventory) in _neighborInventories)
        {
            mergedInventories[neighborId] = liveInventory.Entries
                .Select(entry => new Formats.NeighborhoodData.InventoryItem(entry.Key1, unchecked((uint)entry.Key2), unchecked((ushort)entry.Count)))
                .ToArray();
        }
        return Formats.NeighborhoodData.Write(NeighborhoodData, mergedInventories, version, swap);
    }

    public uint NextRandom()
    {
        var previous = RandomState;
        RandomState = unchecked(previous * 0x41c64e6d + 0x3039);
        return (uint)(((ulong)previous * 0x41c64e6d + 0x3039) >> 16);
    }
    private readonly List<XObject?> _objectTableEntries = [];
    private readonly HashSet<short> _activeAssociatedPlacementCallbacks = [];
    private int _actionQueueSequence;

    public void RestoreActionSequence(int sequence) => _actionQueueSequence = Math.Max(_actionQueueSequence, sequence);
    private static readonly byte[] PersonRecordFieldsVersion10 =
    [
        2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 16, 20, 15, 26, 17, 18, 46, 47, 48, 49, 50, 51, 52, 53,
        13, 14, 58, 60, 61, 56, 57, 63, 65, 67, 68, 69, 74, 54, 55, 75, 76, 80, 81, 82, 83, 84, 85, 86,
    ];

    public const int GlobalCount = 0x40;

    public SimulationNoticeListener? NoticeListeners { get; private set; }

    public void AddNoticeListener(SimulationNoticeListener listener)
    {
        ArgumentNullException.ThrowIfNull(listener);
        if (NoticeListeners is null)
        {
            NoticeListeners = listener;
            return;
        }

        var tail = NoticeListeners;
        var visited = new HashSet<SimulationNoticeListener>();
        while (tail.Next is not null)
        {
            if (!visited.Add(tail)) throw new InvalidOperationException("The simulation notice-listener chain contains a cycle.");
            tail = tail.Next;
        }
        if (!visited.Add(tail)) throw new InvalidOperationException("The simulation notice-listener chain contains a cycle.");
        tail.Next = listener;
    }

    public bool DispatchNotice(int message, int value)
    {
        var handled = false;
        var listener = NoticeListeners;
        while (listener is not null)
        {
            var next = listener.Next;
            if (listener.Callback(message, value)) handled = true;
            listener = next;
        }
        // Room key 0xFFFB (-5) is the off-lot sentinel and has no room record.
        if (message == 0xf3 && value is not (-5 or 0xfffb))
            RefreshRoomRecord(unchecked((ushort)value));
        return handled;
    }

    public SimulationClock Clock { get; } = new();
    private SimulationDate? _explicitCurrentDate;
    private bool _currentDateUsesGlobals;
    public SimulationDate? CurrentDate
    {
        get => _currentDateUsesGlobals
            ? new SimulationDate(this[SimulationGlobal.Year], this[SimulationGlobal.Month], this[SimulationGlobal.DayOfMonth])
            : _explicitCurrentDate;
        set
        {
            _explicitCurrentDate = value;
            _currentDateUsesGlobals = false;
        }
    }

    internal void UseSimulationGlobalsForCurrentDate() => _currentDateUsesGlobals = true;
    public SimulationClockManager ClockManager { get; } = new();
    public int TreeStepLimit
    {
        get
        {
            var eligibleNeighbors = NeighborWalkOrder.Count(neighbor =>
                neighbor?.FriendEligibilityObjectFlagsB4 is { } flags && (flags & 0xC) == 4);
            return checked(10_000 + ClockManager.Entries.Count * 15 + eligibleNeighbors * eligibleNeighbors * 15);
        }
    }
    // Ordered item IDs from MagicMasterSpells.iff STR# 15 (excluding reserved first entry).
    public IReadOnlyList<short> MagicMasterSpellItemIds { get; set; } = [];
    public PersonMotiveDecayTuning? PersonMotiveDecayTuning { get; set; }
    public List<ActionQueueRemovalNotice> ActionQueueRemovalNotices { get; } = [];
    public List<QueuedInteractionStartTrace> QueuedInteractionStartTrace { get; } = [];
    public bool ActionStringDisplayActive { get; set; }
    public InteractionMenuContext? InteractionMenu { get; internal set; }
    internal bool ImmediateInteractionRunning { get; set; }
    internal ActionQueueSlot? ActiveImmediateAction { get; set; }
    internal XPerson? ActiveImmediatePerson { get; set; }
    public bool EvaluatingInteractionTest { get; set; }
    public bool ActionStringRecordWriteEnabled { get; set; } = true;

    public Dictionary<short, XObject> Objects { get; } = [];
    public Dictionary<ushort, PersonRoomMotiveEntry> PersonRoomMotiveEntries { get; } = [];
    public Dictionary<int, SimsEngine.World.RoomMap> LotRoomMaps { get; } = [];
    public SimsEngine.World.LotTiles? LotTileFlags { get; set; }
    public SimsEngine.World.LotTerrain? LotTerrain { get; set; }
    public Dictionary<int, byte[]> BuildModeType6PlacementGrids { get; } = [];
    public Dictionary<int, byte[]> PlacementEligibilityGrids { get; } = [];
    public Dictionary<int, byte[]> LotRoomLightMaps { get; } = [];
    public SimsEngine.World.RoomLightCoordinateGrid RoomLightCandidates { get; } = new();
    public bool FindLocationWaterOverride { get; set; }
    public bool MoveObjects
    {
        get => FindLocationWaterOverride;
        set => FindLocationWaterOverride = value;
    }
    public bool RoomManagerRecordsLoaded { get; set; }
    public float OutsidePersonRoomMotiveValue { get; set; }
    public float RoomLightRadiusScalar { get; set; } = SimsEngine.World.RoomLightCoordinateGrid.SimsExecutableInitialLightingScalar;
    public float RoomDaylightScalar { get; set; } = SimsEngine.World.RoomRuntimeScalarDefaults.SimsExecutableInitialDaylightScalar;
    public float RoomDaylightAtCurrentClockPhase =>
        SimsEngine.World.RoomRuntimeScalarDefaults.DaylightForTimePhase(Clock.TimeOfDay, RoomDaylightScalar);
    public uint RoomManagerRefreshFlags { get; private set; }
    private readonly HashSet<int> _portalWallRefreshRequestedLevels = [];
    private readonly HashSet<int> _portalGeometryRefreshRequestedLevels = [];
    public IReadOnlySet<int> PortalWallRefreshRequestedChannels => _portalWallRefreshRequestedLevels;
    public IReadOnlySet<int> PortalGeometryRefreshRequestedChannels => _portalGeometryRefreshRequestedLevels;

    public IReadOnlyList<int> ConsumePortalWallRefreshRequests()
    {
        if (_portalWallRefreshRequestedLevels.Count == 0) return Array.Empty<int>();
        var levels = _portalWallRefreshRequestedLevels.Order().ToArray();
        _portalWallRefreshRequestedLevels.Clear();
        return levels;
    }

    public IReadOnlyList<int> ConsumePortalGeometryRefreshRequests()
    {
        if (_portalGeometryRefreshRequestedLevels.Count == 0) return Array.Empty<int>();
        var levels = _portalGeometryRefreshRequestedLevels.Order().ToArray();
        _portalGeometryRefreshRequestedLevels.Clear();
        return levels;
    }

    public event Action<PortalWallRefreshCoordinate>? PortalWallRefreshRequested;

    private void MarkPortalGeometryRefreshRequested(int height)
    {
        if (height == 0)
        {
            _portalGeometryRefreshRequestedLevels.Add(1);
            _portalGeometryRefreshRequestedLevels.Add(2);
        }
        else _portalGeometryRefreshRequestedLevels.Add(height);
    }

    private void MarkPortalWallRefreshRequested(int height, int tileX, int tileY)
    {
        if (height == 0)
        {
            _portalWallRefreshRequestedLevels.Add(1);
            _portalWallRefreshRequestedLevels.Add(2);
        }
        else _portalWallRefreshRequestedLevels.Add(height);
        var coordinate = MapPortalWallRefreshCoordinate(tileX, tileY, height);
        PortalWallRefreshRequested?.Invoke(coordinate);
    }

    private static PortalWallRefreshCoordinate MapPortalWallRefreshCoordinate(int tileX, int tileY, int height)
    {
        var (first, second) = height switch
        {
            1 => (63 - tileX, tileY),
            2 => (63 - tileY, 63 - tileX),
            3 => (tileX, 63 - tileY),
            _ => (tileY, tileX),
        };
        return new PortalWallRefreshCoordinate(unchecked((byte)first), unchecked((byte)second), unchecked((byte)height));
    }

    public void LoadRoomMaps(IReadOnlyDictionary<int, SimsEngine.World.RoomMap> roomMaps)
    {
        ArgumentNullException.ThrowIfNull(roomMaps);
        LotRoomMaps.Clear();
        LotRoomLightMaps.Clear();
        PersonRoomMotiveEntries.Clear();

        foreach (var (level, roomMap) in roomMaps.OrderBy(pair => pair.Key))
        {
            LotRoomMaps.Add(level, roomMap);
            LotRoomLightMaps.Add(level, new byte[SimsEngine.World.RoomLightCoordinateGrid.GridSize * SimsEngine.World.RoomLightCoordinateGrid.GridSize]);
            foreach (var roomId in roomMap.RoomIds)
                PersonRoomMotiveEntries.Add(roomId,
                    new PersonRoomMotiveEntry(0f, IsOutside: roomMap.IsOutside(roomId))
                    {
                        NeedsRefresh = true,
                        LightOverrideFlag75 = roomMap.LightControlFlag75(roomId) ? (byte)1 : (byte)0,
                    });
        }

        RoomManagerRecordsLoaded = true;
        ReconcileObjectRoomsAfterMapLoad();
        RefreshDirtyRoomRecords();
    }

    public void ReloadRoomMaps(IReadOnlyDictionary<int, SimsEngine.World.RoomMap> roomMaps) =>
        LoadRoomMaps(roomMaps);

    private void ReconcileObjectRoomsAfterMapLoad()
    {
        foreach (var item in WalkOrder)
        {
            var position = item.Position;
            if (position.Height == 0 && (position.X > 0 || position.Y > 0))
            {
                position = position with { Height = 1 };
                item.Position = position;
            }

            short roomId = -5;
            var x = position.X >> 4;
            var y = position.Y >> 4;
            if (x > 0 && y > 0 && x < LotGeometry.LotDimension - 1 && y < LotGeometry.LotDimension - 1 &&
                LotRoomMaps.TryGetValue(position.Height, out var roomMap) && x < roomMap.Width && y < roomMap.Height)
            {
                var room = roomMap.RoomAtPosition(position.X, position.Y);
                if (room != SimsEngine.World.RoomMap.NoRoom) roomId = unchecked((short)room);
            }

            item.RoomWord84 = roomId;
            if (item is XPerson person)
                person.LastObservedRoomIdAFC = unchecked((ushort)roomId);
        }
    }

    public bool HasRoomRecord(short roomId) =>
        RoomManagerRecordsLoaded && PersonRoomMotiveEntries.ContainsKey(unchecked((ushort)roomId));

    public bool RoomIsOutside(short roomId) =>
        PersonRoomMotiveEntries.TryGetValue(unchecked((ushort)roomId), out var room) && room.IsOutside;

    public RoomRefreshResult RefreshRoomRecord(ushort roomId)
    {
        if (!RoomManagerRecordsLoaded) return RoomRefreshResult.ManagerUnavailable;
        if (!PersonRoomMotiveEntries.TryGetValue(roomId, out var room)) return RoomRefreshResult.RoomNotFound;
        room.NeedsRefresh = true;
        PersonRoomMotiveEntries[roomId] = room;
        // Room key bits 10–11 (mask 0x0C00) encode the room group.
        switch ((roomId & 0x0c00) >> 10)
        {
            case 0: RoomManagerRefreshFlags |= 1; break;
            case 1: RoomManagerRefreshFlags |= 2; break;
        }
        return RoomRefreshResult.Refreshed;
    }

    public int RefreshDirtyRoomRecords(int roomGroup = 0)
    {
        if (!RoomManagerRecordsLoaded) return 0;
        if (roomGroup is < 0 or > 4) throw new ArgumentOutOfRangeException(nameof(roomGroup));
        var refreshed = 0;
        foreach (var (level, roomMap) in LotRoomMaps.OrderBy(pair => pair.Key))
        foreach (var roomId in roomMap.RoomIds)
        {
            if (!PersonRoomMotiveEntries.TryGetValue(roomId, out var room) || !room.NeedsRefresh) continue;
            var roomKeyGroup = (roomId & 0x0c00) >> 10;
            if (roomGroup != 0 && roomKeyGroup + 1 != roomGroup) continue;

            var previousDisplayedLight = DisplayedRoomLight(room);
            var statistics = new SimsEngine.World.RoomRuntimeStatistics();
            var lightGridContext = new SimsEngine.World.RoomLightGridCallbackContext(
                RoomLightCandidates,
                RoomLightRadiusScalar,
                LevelAt: item => item[ObjectData.LightSource],
                RoomAt: (first, second, candidateLevel) =>
                    LotRoomMaps.TryGetValue(candidateLevel, out var candidateMap) &&
                    second >= 0 && first >= 0 && second < candidateMap.Width && first < candidateMap.Height &&
                    candidateMap.RoomAt(second, first) != SimsEngine.World.RoomMap.NoRoom
                        ? unchecked((short)candidateMap.RoomAt(second, first))
                        : (short)-5,
                AdjacentRooms: (first, second, candidateLevel) =>
                {
                    if (!LotRoomMaps.TryGetValue(candidateLevel, out var candidateMap)) return (null, null);
                    var adjacent = candidateMap.AdjacentRoomsAtTile(second, first);
                    return adjacent is { } rooms
                        ? (rooms.First == SimsEngine.World.RoomMap.NoRoom ? null : unchecked((short?)rooms.First),
                            rooms.Second == SimsEngine.World.RoomMap.NoRoom ? null : unchecked((short?)rooms.Second))
                        : (null, null);
                },
                BridgeUnassignedRoomCells: true);

            foreach (var (tileX, tileY) in roomMap.TilesInRoom(roomId))
            {
                var tileInput = roomMap.StatisticsInputAt(tileX, tileY);
                if (tileInput is { } input)
                    statistics.Add(SimsEngine.World.RoomTileStatistics.AccumulateKnown(input, room.IsOutside));
                statistics.Add(SimsEngine.World.RoomObjectStatistics.AccumulateTile(
                    this, tileX, tileY, level, roomId, room.IsOutside,
                    item => IsInsideLotForRoomLightCallback(item), lightGridContext));
            }

            room.LightingObjectCount140 = statistics.LightingObjects140;
            room.PersonObjectCount142 = statistics.PersonObjects142;
            room.HouseCategory4ObjectCount58 = statistics.Category4Objects2C;
            room.HouseCategory5To7ObjectCount5c = statistics.Category5To7Objects2E;
            var scoreInput = statistics.ToScoreInput(
                RoomDaylightAtCurrentClockPhase,
                room.IsOutside,
                room.LightOverrideFlag75,
                room.LightsEnabledFlag73,
                SimsEngine.World.RoomScoreTuning.DaylightCeiling);
            var result = RoomScoreTuning.Calculate(scoreInput);
            room.InteriorValue = result.RoomScore;
            room.LightLevel6c = result.Light;
            room.NeedsRefresh = false;
            PersonRoomMotiveEntries[roomId] = room;
            WriteRoomLightMap(roomMap, roomId, result.TileLight);
            if (previousDisplayedLight != DisplayedRoomLight(room)) DispatchNotice(0xf1, roomId);
            refreshed++;
        }

        var outsideScoreSum = PersonRoomMotiveEntries.Values
            .Where(room => room.IsOutside)
            .Sum(room => room.InteriorValue);
        var phase = Clock.TimeOfDay;
        var phaseBonus = phase switch
        {
            1 or 3 => RoomScoreTuning.OutdoorDawnDuskBonus,
            2 => RoomScoreTuning.OutdoorNighttimeBonus,
            _ => RoomScoreTuning.OutdoorDaylightBonus,
        };
        OutsidePersonRoomMotiveValue = Math.Clamp(
            outsideScoreSum / RoomScoreTuning.OutdoorObjectDivisor + phaseBonus, -100f, 100f);

        var totalIndoorTiles = 0;
        foreach (var (_, roomMap) in LotRoomMaps)
        foreach (var roomId in roomMap.RoomIds)
            if (PersonRoomMotiveEntries.TryGetValue(roomId, out var entry) && !entry.IsOutside)
                totalIndoorTiles += roomMap.RoomHalfArea(roomId, entry.IsOutside);
        var indoorTilesWord = unchecked((short)Math.Clamp(totalIndoorTiles, short.MinValue, short.MaxValue));
        this[SimulationGlobal.IndoorTiles] = indoorTilesWord;
        GlobalObjectTableEffectWords[0x1b] = indoorTilesWord;

        RoomManagerRefreshFlags = roomGroup switch
        {
            0 => 0,
            1 => RoomManagerRefreshFlags & ~1u,
            2 => RoomManagerRefreshFlags & ~2u,
            _ => RoomManagerRefreshFlags,
        };
        return refreshed;
    }

    public static float DisplayedRoomLight(PersonRoomMotiveEntry room)
    {
        var ceiling = SimsEngine.World.RoomScoreTuning.DaylightCeiling;
        return room.LightOverrideFlag75 == 0 &&
               (room.LightsEnabledFlag73 == 0 || room.LightingObjectCount140 != 0 ||
                room.PersonObjectCount142 < 1 || ceiling <= room.LightLevel6c)
            ? room.LightLevel6c
            : ceiling;
    }

    private static bool IsInsideLotForRoomLightCallback(XObject item)
    {
        var x = item.Position.X >> 4;
        var y = item.Position.Y >> 4;
        return x > 0 && y > 0 && x < LotGeometry.LotDimension - 1 && y < LotGeometry.LotDimension - 1;
    }

    private void WriteRoomLightMap(SimsEngine.World.RoomMap roomMap, ushort roomId, float light)
    {
        if (!LotRoomLightMaps.TryGetValue(roomMap.Level, out var grid)) return;
        var lightByte = unchecked((byte)MathF.Round(light, MidpointRounding.ToEven));
        foreach (var (x, y) in roomMap.TilesInRoom(roomId))
            grid[x * SimsEngine.World.RoomLightCoordinateGrid.GridSize + y] = lightByte;
    }

    public void SetObjectPosition(XObject item, ObjectPosition position)
        => SetObjectPosition(item, position, new HashSet<XObject>(ReferenceEqualityComparer.Instance));

    private void SetObjectPosition(XObject item, ObjectPosition position, HashSet<XObject> visited)
    {
        ArgumentNullException.ThrowIfNull(item);
        if (!visited.Add(item)) return;
        item.Position = position;
        if (item is XPerson movingPerson && movingPerson.NativeRoute is null)
        {
            movingPerson.AnimatorRootX = position.X;
            movingPerson.AnimatorRootY = position.Y;
            movingPerson.AnimatorRootDirection = movingPerson[ObjectData.Direction];
        }
        if (item is XPerson person && person.TypeRecord is not null)
            person.RefreshFootprintBounds();
        else if (item.TypeRecord is not null)
        {
            item.FootprintBounds = PlacementFootprintBounds(item, position);
            item.FootprintBoundsDirection = item[ObjectData.Direction];
        }
        var previousRoom = item.RoomWord84;
        short currentRoom = -5;
        var x = position.X >> 4;
        var y = position.Y >> 4;
        if (x > 0 && y > 0 && x < LotGeometry.LotDimension - 1 && y < LotGeometry.LotDimension - 1 &&
            LotRoomMaps.TryGetValue(position.Height, out var roomMap) && x < roomMap.Width && y < roomMap.Height)
        {
            var room = roomMap.RoomAtPosition(position.X, position.Y);
            if (room != SimsEngine.World.RoomMap.NoRoom) currentRoom = unchecked((short)room);
        }

        item.RoomWord84 = currentRoom;
        if (previousRoom != currentRoom && item.RoomChangeNoticeGateWord58 != 0)
        {
            DispatchNotice(0xf3, previousRoom);
            DispatchNotice(0xf3, currentRoom);
        }

        foreach (var related in EnumerateContainedSlotChildren(item))
            SetObjectPosition(related, position, visited);
    }
    public Dictionary<short, ITreeTable?> CodeOwnerScopes { get; } = [];
    public Dictionary<short, uint> CodeOwnerTypeGuids { get; } = [];
    public Dictionary<short, TreeStack> SavedExecutionStacks { get; } = [];
    public InteractionLifecycle InteractionLifecycle { get; } = new();
    public List<FoundActionPushFailure> FoundActionPushFailures { get; } = [];
    public List<ObjectCreationDiagnostic> ObjectCreationTrace { get; } = [];
    public List<ObjectRemovalDiagnostic> ObjectRemovalTrace { get; } = [];
    public List<XObject> WalkOrder { get; } = [];
    public IReadOnlyList<XObject> ObjectsOfType(int guidKey) =>
        WalkOrder.Where(item => item.TypeRecord?.Key == guidKey).ToArray();
    public List<XObject> InteractionLookupOrder { get; } = [];
    public bool InteractionRefreshManagerEnabled { get; set; } = true;
    public int InteractionRefreshTypeKey { get; set; }
    public XObject? ActiveInteractionRefreshTarget { get; set; }
    public bool InteractionContextsInvalidated { get; private set; }
    public List<XObject> InteractionRefreshPendingObjects { get; } = [];
    public List<XObject> InteractionRefreshDeferredObjects { get; } = [];
    public int LotTransformParameter { get; private set; }
    public LotCoordinateBounds LotBounds { get; private set; } = LotGeometry.TransformLotBounds(64, 0);
    public void SetLotOrientation(int orientation)
    {
        LotTransformParameter = LotGeometry.NormalizeOrientation(orientation);
        LotBounds = LotGeometry.TransformLotBounds(64, LotTransformParameter);
    }
    public Dictionary<short, NeighborState> Neighbors { get; } = [];
    internal Neighbors? SavedNeighbors { get; set; }
    internal bool NeighborRosterComplete { get; set; } = true;
    internal int CompleteNeighborSlotPrefix { get; set; }
    public bool RelationshipModuleDirtyFlag12 { get; private set; }
    public bool PersistentPersonDataDirty { get; private set; }

    public void SetPersistentNeighborPersonData(NeighborState neighbor, PersonData field, short value)
    {
        var index = (int)field;
        if (neighbor.PersonData[index] == value) return;
        neighbor.PersonData[index] = value;
        if (neighbor.PersonRecordVersion == 0) neighbor.PersonRecordVersion = 10;
        PersistentPersonDataDirty = true;
        DirtyPersistentPersonNeighborIds.Add(neighbor.Id);
    }

    public short InitializeRelationshipZodiac(NeighborState neighbor, bool hasName, Func<short[], short> compute)
    {
        var person = WalkOrder.OfType<XPerson>().FirstOrDefault(item => item[PersonData.NeighborId] == neighbor.Id);
        var data = person?.PersonData ?? neighbor.PersonData;
        var zodiac = data[(int)PersonData.Zodiac];
        if (hasName && zodiac == 0)
        {
            zodiac = compute(data);
            if (person is null) SetPersistentNeighborPersonData(neighbor, PersonData.Zodiac, zodiac);
            else data[(int)PersonData.Zodiac] = zodiac;
        }
        return zodiac;
    }
    public HashSet<short> DirtyRelationshipFamilies { get; } = [];
    public HashSet<short> DirtyRelationshipNeighbors { get; } = [];
    public HashSet<(short SourceNeighborId, short TargetNeighborId)> DirtyRelationshipPairs { get; } = [];
    public HashSet<short> DirtyPersistentPersonNeighborIds { get; } = [];
    public IReadOnlySet<short> RemovedNeighbors => _removedNeighbors;
    public IReadOnlyDictionary<short, uint> RemovedNeighborGuids => _removedNeighborGuids;
    public Func<XPerson, bool>? TryInterceptConnectedVisitorRemoval { get; set; }
    public Action<short>? NotifyRemovedNeighborCleared { get; set; }

    public void ClearRemovedNeighbor(short neighborId)
    {
        _removedNeighbors.Remove(neighborId);
        _removedNeighborGuids.Remove(neighborId);
        NotifyRemovedNeighborCleared?.Invoke(neighborId);
    }

    public void ClearAllRemovedNeighbors()
    {
        _removedNeighbors.Clear();
        _removedNeighborGuids.Clear();
    }

    private bool IsRemovedNeighborEntry(short neighborId, uint guid)
    {
        if (!_removedNeighbors.Contains(neighborId))
            return false;
        if (!_removedNeighborGuids.TryGetValue(neighborId, out var deletedGuid) || deletedGuid == 0 || guid == 0)
            return true;
        return guid == deletedGuid;
    }

    public void MarkRelationshipsChanged(NeighborState source, NeighborState target)
    {
        source.RelationshipsChangedFlag24 = true;
        target.RelationshipsChangedFlag24 = true;
        var sourceFamily = source.PersonData[(int)PersonData.FamilyNumber];
        var targetFamily = target.PersonData[(int)PersonData.FamilyNumber];
        if (sourceFamily != 0) DirtyRelationshipFamilies.Add(sourceFamily);
        if (targetFamily != 0) DirtyRelationshipFamilies.Add(targetFamily);
        DirtyRelationshipNeighbors.Add(source.Id);
        DirtyRelationshipPairs.Add((source.Id, target.Id));
        RelationshipModuleDirtyFlag12 = true;
    }

    public IffFile WriteSavedNeighborRelationshipsTo(IffFile neighborhood)
    {
        if ((!RelationshipModuleDirtyFlag12 && !PersistentPersonDataDirty) || SavedNeighbors is null || !SavedNeighbors.IsComplete)
            return neighborhood;
        var chunk = neighborhood.OfType(ResourceType.Parse("NBRS")).FirstOrDefault();
        if (chunk is null) return neighborhood;

        var entriesById = new Dictionary<short, Neighbor>();
        var entries = new List<Neighbor>(SavedNeighbors.Entries.Count);
        foreach (var saved in SavedNeighbors.Entries)
        {
            if (IsRemovedNeighborEntry(saved.NeighborId, saved.Guid)) continue;
            var updated = Neighbors.TryGetValue(saved.NeighborId, out var live)
                ? saved with
                {
                    Name = PersistentPersonDataDirty ? live.Name : saved.Name,
                    Relationships = RelationshipModuleDirtyFlag12 ? live.Relationships.Snapshot() : saved.Relationships,
                    RecordVersion = PersistentPersonDataDirty && live.PersonRecordVersion > 0
                        ? live.PersonRecordVersion
                        : saved.RecordVersion,
                    PersonData = PersistentPersonDataDirty && live.PersonRecordVersion > 0
                        ? live.PersonData.ToArray()
                        : saved.PersonData,
                }
                : saved;
            entries.Add(updated);
            entriesById[updated.NeighborId] = updated;
        }

        var updatedSlotCount = SavedNeighbors.SlotCount;
        var existingSlots = new HashSet<int>(entries.Select(e => e.Slot));
        for (var slotIndex = 0; slotIndex < NeighborWalkOrder.Count; slotIndex++)
        {
            var live = NeighborWalkOrder[slotIndex];
            if (live is null || IsRemovedNeighborEntry(live.Id, unchecked((uint)live.TypeRecordKey)) || entriesById.ContainsKey(live.Id))
                continue;
            if (live.PersonRecordVersion <= 0 && live.Relationships.Snapshot().Count == 0)
                continue;

            var targetSlot = slotIndex;
            while (existingSlots.Contains(targetSlot)) targetSlot++;
            existingSlots.Add(targetSlot);
            if (targetSlot + 1 > updatedSlotCount) updatedSlotCount = targetSlot + 1;

            var versioned = live.PersonRecordVersion > 0;
            var added = new Neighbor(
                Slot: targetSlot,
                RecordVersion: versioned ? live.PersonRecordVersion : (SavedNeighbors.Version > 0x48 ? 10 : 4),
                Name: live.Name,
                Field0x1C: 0,
                PersonData: versioned ? live.PersonData.ToArray() : null,
                NeighborId: live.Id,
                Guid: unchecked((uint)live.TypeRecordKey),
                Relationships: RelationshipModuleDirtyFlag12 ? live.Relationships.Snapshot() : new Dictionary<int, IReadOnlyList<int>>(),
                StoredFormat: SavedNeighbors.Version > 0x48 ? 10 : 0,
                PersonDataTrailingWord: 0);
            entries.Add(added);
            entriesById[added.NeighborId] = added;
        }

        var rewritten = new Neighbors(
            SavedNeighbors.Version,
            updatedSlotCount,
            entries,
            SavedNeighbors.IsComplete,
            SavedNeighbors.CompleteSlotPrefix);
        return neighborhood.WithChunkDataResized(chunk.Type, chunk.Id,
            rewritten.WriteChunkData(chunk.Data.Span[0] != 0));
    }
    private readonly HashSet<short> _removedNeighbors = [];
    private readonly Dictionary<short, uint> _removedNeighborGuids = [];

    public static bool IsCharacter(NeighborState neighbor) =>
        neighbor.FriendEligibilityObjectFlagsB4 is { } flags && (flags & 0xC) == 4;

    public IReadOnlyList<short> DeleteUnhousedCharacters(Func<int, bool> isFamilyMember)
    {
        var deleted = new List<short>();
        while (NeighborWalkOrder.FirstOrDefault(neighbor => neighbor is not null && IsCharacter(neighbor) &&
                   neighbor.PersonData[(int)PersonData.FamilyNumber] == 0 &&
                   neighbor.PersonData[(int)PersonData.LingeringHouseNumber] == 0) is { } found)
        {
            if (!DeleteCharacter(found, isFamilyMember)) break;
            deleted.Add(found.Id);
        }
        return deleted;
    }

    public bool DeleteCharacter(NeighborState neighbor, Func<int, bool> isFamilyMember)
    {
        ArgumentNullException.ThrowIfNull(neighbor);
        ArgumentNullException.ThrowIfNull(isFamilyMember);
        if (!IsCharacter(neighbor)) return false;
        while (WalkOrder.FirstOrDefault(item => item.TypeRecord?.Key == neighbor.TypeRecordKey) is { } item)
            KillObject(item.Id);
        if (isFamilyMember(neighbor.TypeRecordKey)) return false;

        DispatchNotice(0xfb, neighbor.Id);
        var inventory = NeighborInventory(neighbor.Id);
        for (var type = 0; type <= 9; type++) inventory.RemoveAllOfType(type);
        RaiseNeighborInventoryChanged(neighbor.Id, inventory);
        var slot = NeighborWalkOrder.IndexOf(neighbor);
        if (slot >= 0) NeighborWalkOrder[slot] = null;
        foreach (var other in NeighborWalkOrder)
            other?.Relationships.RemoveTarget(neighbor.Id);
        Neighbors.Remove(neighbor.Id);
        _removedNeighbors.Add(neighbor.Id);
        _removedNeighborGuids[neighbor.Id] = unchecked((uint)neighbor.TypeRecordKey);
        RelationshipModuleDirtyFlag12 = true;
        return true;
    }

    public List<NeighborState?> NeighborWalkOrder { get; } = [];
    // BHAV variable scopes 0x20 and 0x26 index this 1-based roster independently of NeighborId.
    public NeighborState? NeighborManagerEntry(short oneBasedIndex) =>
        oneBasedIndex >= 1 && oneBasedIndex <= NeighborWalkOrder.Count ? NeighborWalkOrder[oneBasedIndex - 1] : null;
    public short? WaitInstructionOpcode(XObject stackObject)
    {
        ArgumentNullException.ThrowIfNull(stackObject);
        if (!SavedExecutionStacks.TryGetValue(stackObject.Id, out var stack) || stack.Top is not { } frame) return null;
        if (frame.Tree is not Bhav tree) return null;
        if (frame.Instruction < 0 || frame.Instruction >= tree.Instructions.Count) return null;
        return (short)(tree.Instructions[frame.Instruction].Opcode & 0x7fff);
    }

    public void ClearWaitCounter(XObject stackObject)
    {
        ArgumentNullException.ThrowIfNull(stackObject);
        if (!SavedExecutionStacks.TryGetValue(stackObject.Id, out var stack) || stack.Top is not { } frame) return;
        if (frame.Tree is not Bhav tree) return;
        if (frame.Instruction < 0 || frame.Instruction >= tree.Instructions.Count) return;
        var operand = tree.Instructions[frame.Instruction].Operand;
        var index = (short)(operand[0] | operand[1] << 8);
        if (index >= 0 && index < frame.Parameters.Length) frame.Parameters[index] = 0;
    }

    public Func<int, XObject?>? ObjectFactory { get; set; }

    public Func<int, IReadOnlyList<XObject>?>? ObjectGroupFactory { get; set; }

    public Func<int, XObject?>? PlacementPreviewFactory { get; set; }
    public Func<int, XObject?>? BuildCursorFactory { get; set; }

    public Func<int, IReadOnlyList<XObject>?>? PlacementPreviewGroupFactory { get; set; }

    public void RemoveCreatedObjectGroup(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        var root = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId) ?? item;
        var members = new List<XObject>();
        var seen = new HashSet<short>();
        for (var member = root; member is not null && seen.Add(member.Id);)
        {
            members.Add(member);
            member = member.MultiTileNextId == 0 ? null : ObjectById(member.MultiTileNextId);
        }
        foreach (var member in members.AsEnumerable().Reverse()) Remove(member.Id);
    }

    public short NextObjectId()
    {
        for (short id = 1; id < short.MaxValue; id++)
            if (!Objects.ContainsKey(id)) return id;
        throw new InvalidOperationException("No free object id.");
    }

    public bool TileHasObject(int tileX, int tileY, int level, int? guidKey)
    {
        foreach (var item in WalkOrder)
        {
            if (item.Position.Height != level) continue;
            if ((item.Position.X >> 4) != tileX || (item.Position.Y >> 4) != tileY) continue;
            if (guidKey is null || item.TypeRecord?.Key == guidKey) return true;
        }
        return false;
    }

    public short RoomAtTile(int tileX, int tileY, int level)
    {
        return TryGetRoomAtTile(tileX, tileY, level, out var room) ? room : (short)0;
    }

    public bool TryGetRoomAtTile(int tileX, int tileY, int level, out short room)
    {
        room = 0;
        if (!LotRoomMaps.TryGetValue(level, out var map) || tileX < 0 || tileY < 0 || tileX >= map.Width || tileY >= map.Height)
            return false;
        var key = map.RoomAt(tileX, tileY);
        if (key == SimsEngine.World.RoomMap.NoRoom) return false;
        room = unchecked((short)key);
        return true;
    }

    public bool TileHasRoomDividingDiagonal(int tileX, int tileY, int level) =>
        LotRoomMaps.TryGetValue(level, out var map) && map.HasRoomDividingDiagonal(tileX, tileY);

    public bool TileHasDiagonalWall(int tileX, int tileY, int level) =>
        LotRoomMaps.TryGetValue(level, out var map) && map.HasDiagonalWall(tileX, tileY);

    public bool CanPlaceCreatedObject(XObject created, ObjectPosition at, XObject? relativeTo = null, TreeStack? checkStack = null)
    {
        ArgumentNullException.ThrowIfNull(created);
        return PassesCommonPlacementChecks(created, at, relativeTo is not null, checkStack,
            relativeTo?.ClockManagerIndex ?? 0) && PassesUpperFloorPlacementCheck(created, at);
    }
}
