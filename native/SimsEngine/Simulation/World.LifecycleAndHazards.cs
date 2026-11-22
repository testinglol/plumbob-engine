using SimsEngine.Formats;
using SimsEngine.Content;
using SimsEngine.Character;
using System.Numerics;

namespace SimsEngine.Simulation;

public sealed partial class SimulationWorld
{

    public int ComputeSaveHouseInfo(out bool lotHasHouse, out int lotSize, out int transitFilterFlags, out int familyFlagsMask)
    {
        lotSize = this[SimulationGlobal.LotSize] is > 3 and <= LotGeometry.LotDimension
            ? this[SimulationGlobal.LotSize]
            : LotRoomMaps.Values.FirstOrDefault()?.Width is { } width && width > 0
                ? width
                : LotGeometry.LotDimension;
        this[SimulationGlobal.LotSize] = unchecked((short)lotSize);

        lotHasHouse = ComputeLotHasHouse(lotSize);
        this[SimulationGlobal.LotHasHouse] = lotHasHouse ? (short)1 : (short)0;

        familyFlagsMask = 0;
        transitFilterFlags = 0;
        var hasCashRegister = false;
        var hasCategoryBVar6 = false;
        var hasCategoryBVar3 = false;
        var hasCategoryBVar5 = false;
        var hasCategoryBVar7 = false;

        foreach (var item in WalkOrder)
        {
            var category = item[ObjectData.Category];
            if (category == 0 && item.TypeRecord?.Name is { Length: > 0 } typeName)
            {
                if (typeName.Equals("Baby", StringComparison.OrdinalIgnoreCase)) category = 1;
                else if (typeName.Contains("Phone", StringComparison.OrdinalIgnoreCase)) category = 9;
            }

            switch (category)
            {
                case 1:
                    if (item.Position.X != -16 || item.Position.Y != -16)
                        familyFlagsMask |= 0x1;
                    break;
                case 4:
                case 0x2e:
                case 0x2f:
                case 0x30:
                case 0x47:
                    transitFilterFlags |= 0x0001;
                    break;
                case 9:
                    familyFlagsMask |= 0x2;
                    break;
                case 10:
                    hasCashRegister = true;
                    break;
                case 0x11:
                case 0x15:
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x1e:
                case 0x27:
                case 0x28:
                case 0x3a:
                case 0x3b:
                case 0x4a:
                    hasCategoryBVar6 = true;
                    break;
                case 0x19:
                case 0x1a:
                case 0x32:
                case 0x48:
                    transitFilterFlags |= 0x0002;
                    break;
                case 0x2b:
                case 0x31:
                case 0x33:
                case 0x4d:
                    transitFilterFlags |= 0x0040;
                    break;
                case 0x49:
                    transitFilterFlags |= 0x0004;
                    break;
                case 0x4b:
                    hasCategoryBVar3 = true;
                    break;
                case 0x4c:
                    hasCategoryBVar5 = true;
                    break;
                case 0x50:
                    transitFilterFlags |= 0x0080;
                    break;
                case 0x53:
                    transitFilterFlags |= 0x0400;
                    break;
                case 0x54:
                    transitFilterFlags |= 0x0100;
                    break;
                case 0x55:
                    transitFilterFlags |= 0x0200;
                    break;
                case 0x5d:
                case 0x5e:
                    transitFilterFlags |= 0x1000;
                    break;
                case 0x5f:
                    transitFilterFlags |= 0x0800;
                    break;
                case 0x61:
                    hasCategoryBVar7 = true;
                    break;
            }
        }

        if (hasCategoryBVar6 && hasCashRegister) transitFilterFlags |= 0x0008;
        if (hasCategoryBVar3 && hasCashRegister) transitFilterFlags |= 0x0010;
        if ((hasCategoryBVar5 && hasCashRegister) || hasCategoryBVar7) transitFilterFlags |= 0x0020;

        this[SimulationGlobal.FilterFlagsForTransitScreen] = unchecked((short)transitFilterFlags);
        return familyFlagsMask;
    }

    public int ComputeSaveHouseInfo() => ComputeSaveHouseInfo(out _, out _, out _, out _);

    private bool ComputeLotHasHouse(int lotSize)
    {
        var anyObjectHasCatalogSort = WalkOrder.Any(item =>
            item.Definition[(int)ObjdField.RoomSort] != 0 ||
            item.Definition[(int)ObjdField.FunctionSort] != 0 ||
            item.Definition[(int)ObjdField.BuildModeType] != 0);

        foreach (var item in WalkOrder)
        {
            if (item.MultiTileMasterId != 0 && item.MultiTileMasterId != item.Id) continue;
            var objectType = item.TypeRecord?.ObjectType ?? item.Definition[(int)ObjdField.Type];
            if (objectType == 7) continue;
            var x = item.Position.X >> 4;
            var y = item.Position.Y >> 4;
            if (x <= 0 || y <= 0 || x >= lotSize - 1 || y >= lotSize - 1) continue;
            if (LotTileFlags is not null && !LotTileFlags.InsideLot(x, y)) continue;

            if (item.Definition[(int)ObjdField.RoomSort] != 0 ||
                item.Definition[(int)ObjdField.FunctionSort] != 0 ||
                item.Definition[(int)ObjdField.BuildModeType] != 0)
            {
                return true;
            }

            if (!anyObjectHasCatalogSort && SavedLotObjects is null && item is not XPerson &&
                objectType is not (2 or 7 or 8 or 9 or 11))
            {
                return true;
            }
        }

        foreach (var (level, roomMap) in LotRoomMaps.OrderBy(pair => pair.Key))
        {
            var maxX = Math.Min(lotSize - 1, roomMap.Width - 1);
            var maxY = Math.Min(lotSize - 1, roomMap.Height - 1);
            for (var x = 1; x < maxX; x++)
            for (var y = 1; y < maxY; y++)
            {
                if (LotTileFlags is not null && !LotTileFlags.InsideLot(x, y)) continue;
                if (roomMap.StatisticsInputAt(x, y) is { } stats)
                {
                    if (stats.Walls.UInt32At(0) != 0) return true;
                    if (stats.FloorGridWord is { } floor && floor != 0) return true;
                    if (level == 1 && stats.RawGroundWaterGridByte is { } pool && pool != 0 && pool != 0xff)
                        return true;
                }
                else if (roomMap.RuntimeWallAt(x, y) is { Segments: not 0 })
                {
                    return true;
                }
            }
        }

        return false;
    }

    private int CountNeighborInteractions(XObject interactionObject)
    {
        var count = 0;
        foreach (var candidate in NeighborTableEntries)
        {
            if (candidate is null || interactionObject.HasNeighborSubobjectReference(candidate) ||
                candidate.NeighborInteractionTargetWordEE == 0) continue;

            for (var position = 0; position < ActivePersonCount; position++)
            {
                var personRecordPosition = ActivePersonIndex(position);
                if (personRecordPosition < 0 || personRecordPosition >= PersonRecordKeys.Count) continue;
                var personRecordKey = PersonRecordKeys[personRecordPosition];
                var activeNeighbor = NeighborTableEntries.FirstOrDefault(item => item?.TypeRecord?.Key == personRecordKey);
                if (activeNeighbor is null) continue;

                if (candidate.Relationships.Count(activeNeighbor.Id) == 0 ||
                    activeNeighbor.Relationships.Count(candidate.Id) == 0) continue;
                if (candidate.Relationships.Get(activeNeighbor.Id, 0) < FriendshipThreshold ||
                    activeNeighbor.Relationships.Get(candidate.Id, 0) < FriendshipThreshold ||
                    candidate.NeighborInteractionWordF6 >= 2) continue;

                count++;
                break;
            }
        }
        return count;
    }

    public int FriendshipThreshold { get; set; } = 25;
    public float HouseYardScoreMultiplier { get; private set; } = 0.33f;
    public int HouseUpkeepPenaltyPerDirtyObject { get; private set; } = 6;
    public int HouseUpkeepPenaltyPerBrokenObject { get; private set; } = 15;
    public int HouseLayoutHistoryFillValue { get; private set; } = 200;
    public FindBestInteractionTuning SimulatorTuning { get; set; } = new();
    public SimsEngine.World.RoomScoreTuning RoomScoreTuning { get; set; } = new();
    private bool? _autonomyForced;
    public bool? AutonomyForced
    {
        get => _autonomyForced;
        set
        {
            _autonomyForced = value;
            if (value is { } enabled)
            {
                var sourceValue = (short)(enabled ? 1 : 0);
                GlobalObjectTableEffectWords[0x1e] = sourceValue;
                this[SimulationGlobal.FreeWill] = sourceValue;
            }
        }
    }
    public Dictionary<short, short> GlobalObjectTableEffectWords { get; } = [];
    // Populated from lot SLOT resource 100.
    public List<RoutingSlotRequest> LotRoutingSlots { get; } = [];
    public bool RoutingEnabled { get; set; } = true;
    public GlobalPersonState GlobalPerson { get; } = new();
    public bool LotUpkeepManagerPresent { get; set; }
    public XObject? NeighborInteractionSubject { get; set; }
    public List<int> NeighborInteractionManagerTypeKeys { get; } = [];
    public short NeighborInteractionGlobalStateValue { get; set; }
    public GenericSimsCall03ManagerState GenericSimsCall03State { get; } = new();
    public XObject? GenericSimsCall23PersonSlotBase { get; set; }
    public List<XObject?> NeighborTableEntries { get; } = [];
    public List<int> ActivePersonRecordKeys { get; } = [];
    public List<int> PersonRecordKeys { get; } = [];
    public List<short?> PersonRecordNeighborIds { get; } = [];
    public bool ActivePersonManagerPresent { get; set; }
    public short? StoredSlotPersonId { get; set; }
    public bool PersonRecordManagerPresent { get; set; }
    public GenericSimsCallRecordTarget? GenericSimsCallRecordCallbackTarget { get; set; }
    public bool PersonSelectionOverride { get; set; }
    public short[] Globals { get; } = new short[GlobalCount];
    public short[] NeighborhoodData { get; } = new short[16];
    public int? GenericSimsCall05ManagerWord164 { get; set; }
    public float? ArchitectureValueMultiplier { get; set; }
    public int? ObjectValueGlobalWord50 { get; set; }
    public int? ObjectValueGlobalWord90 { get; set; }
    public int? ObjectValueGlobalWord9C { get; set; }
    public int? ObjectValueGlobalWordA0 { get; set; }
    public int? ObjectValueGlobalWordA4 { get; set; }
    public short[] CheckTreeAds { get; set; } = [];
    public List<StateClassEntry> StateClasses { get; } = [];
    public Dictionary<(byte Source, bool Child, int Index), AvatarAnimationClip> AvatarAnimationTable { get; } = [];
    public Dictionary<(uint ObjectGuid, int Index), AvatarAnimationClip> CustomWalkAvatarAnimationTable { get; } = [];
    public Dictionary<(ushort TableId, int Index), AvatarAnimationClip> StandardWalkFallbackAnimationTable { get; } = [];
    public Dictionary<(int ObjectKey, ushort TableId, int Index), AvatarAnimationClip> ObjectAvatarAnimationTable { get; } = [];
    public Action<short, AvatarAnimationSoundEvent>? AnimationSound { get; set; }
    public bool AvatarAnimationRootOnly { get; set; }
    public Dictionary<short, InteractionScopeTable> InteractionScopes { get; } = [];
    public Dictionary<int, short> PersonTypeRecordSlots { get; } = [];
    public ISimulationHost? Host { get; set; }
    public Func<string, short, bool, bool, bool>? PlaySoundEvent { get; set; }
    public Action<short>? StopOwnerSounds { get; set; }
    public event Action<short>? ObjectSoundsStopped;
    public Action<TutorialFlashKind, short, bool>? TutorialFlash { get; set; }
    public HashSet<short> PositionalSoundOwners { get; } = [];

    public void StopObjectSounds(short id)
    {
        PositionalSoundOwners.Remove(id);
        StopOwnerSounds?.Invoke(id);
        ObjectSoundsStopped?.Invoke(id);
    }
    public ISimulationCareerHost? CareerHost { get; set; }
    public ISimulationAutonomyHost? AutonomyHost { get; set; }
    internal readonly record struct ExecutionLocationSnapshot(
        XObject Me,
        short TreeId,
        int Instruction,
        ushort Opcode,
        byte[] Operand,
        short StackObjectKey,
        XObject? StackObject);

    private ExecutionLocationSnapshot? _executionLocationSnapshot;
    private string? _executionLocationOverride;

    internal void SetExecutionLocation(
        XObject me,
        short treeId,
        int instruction,
        ushort opcode,
        byte[] operand,
        short stackObjectKey,
        XObject? stackObject)
    {
        _executionLocationOverride = null;
        _executionLocationSnapshot = new ExecutionLocationSnapshot(
            me, treeId, instruction, opcode, operand, stackObjectKey, stackObject);
    }

    internal (ExecutionLocationSnapshot? Snapshot, string? Override) CaptureExecutionLocation() =>
        (_executionLocationSnapshot, _executionLocationOverride);

    internal void RestoreExecutionLocation((ExecutionLocationSnapshot? Snapshot, string? Override) state)
    {
        _executionLocationSnapshot = state.Snapshot;
        _executionLocationOverride = state.Override;
    }

    internal string? CurrentExecutionLocation
    {
        get
        {
            if (_executionLocationOverride is { } cached)
                return cached;
            if (_executionLocationSnapshot is not { } snap)
                return null;
            var objectType = snap.Me.Definition[(int)ObjdField.Type];
            int? objectGuid = snap.Me.TypeRecord is { Key: not 0 } typeRecord ? typeRecord.Key : null;
            var tileX = snap.Me.Position.X >> 4;
            var tileY = snap.Me.Position.Y >> 4;
            var tileValue = TileValueAt(tileX, tileY, snap.Me.Position.Height);
            var stackObject = snap.StackObject;
            var stackType = stackObject?.TypeRecord is { } stackRecord ? $", GUID 0x{stackRecord.Key:X8}" : string.Empty;
            var formatted = $"object {snap.Me.Id} (OBJD type {objectType}, GUID {(objectGuid is { } guid ? $"0x{guid:X8}" : "unknown")}), BHAV {snap.TreeId}, instruction {snap.Instruction}, opcode 0x{snap.Opcode:X}, operand {Convert.ToHexString(snap.Operand)}, stack key {snap.StackObjectKey}, stack object {(stackObject is null ? "none" : $"{stackObject.Id} (OBJD type {stackObject.Definition[(int)ObjdField.Type]}{stackType})")}, position {snap.Me.Position}, tile key {tileValue}";
            _executionLocationOverride = formatted;
            return formatted;
        }
        set
        {
            _executionLocationOverride = value;
            _executionLocationSnapshot = null;
        }
    }
    public bool DisplayRefreshRequested { get; set; }
    public IFamilyBudget? FamilyBudget { get; set; }
    public INeighborhoodFamilies? NeighborhoodFamilies { get; set; }
    public sealed record LotSwitchRequest(short RawTargetHouse, int PersonGuid, short FamilyNumber, int CompanionGuid = 0);

    public LotSwitchRequest? PendingLotSwitch { get; set; }

    public Action? PersistNeighborhoodStateImmediately { get; set; }
    public Action? PersistLotSimulationStateImmediately { get; set; }
    public Action<int>? ReleaseGenericSimsCall03PrimaryHandle { get; set; }
    public Action<int>? ReleaseGenericSimsCall03SecondaryHandle { get; set; }

    public delegate bool FamilyValuationLookup(short familyNumber, out int houseNumber, out int budget, out int value);
    public FamilyValuationLookup? TryLookupFamilyValuation { get; set; }
    public Func<(int Furnishings, int Architecture)>? LiveLotValuationProvider { get; set; }
    public Func<IReadOnlyList<int>>? OccupiedVacationHousesProvider { get; set; }

    public delegate bool ActiveFamilyUpkeepLookup(out short familyNumber, out bool hasMembers, out IReadOnlyList<short> minResources);
    public ActiveFamilyUpkeepLookup? TryLookupActiveFamilyUpkeep { get; set; }

    public List<XObject> WorldLotListEntries { get; } = [];

    // Handles GenericSimsCall 0x00, 0x08, and 0x09.
    public void RunGenericSimsCallInitialization(int mode)
    {
        if (mode == 0)
        {
            this[SimulationGlobal.IsTutorialHouseNoYes] = 0;
            PersistLotSimulationStateImmediately?.Invoke();
        }
        NeighborhoodData[1] = checked((short)(mode + 1));
        NeighborhoodData[2] = 0;
        PersistNeighborhoodState();
    }

    public void PersistNeighborhoodState()
    {
        if (Host is { } host) host.PersistNeighborhoodState();
        else PersistNeighborhoodStateImmediately?.Invoke();
    }
    public ISimulationMenuTextSources? MenuTextSources { get; set; }
    public List<short> PendingRemovals { get; } = [];
    public GenericSimsCallRequestQueue GenericSimsCallRequests { get; } = new();
    public bool AutoProcessGenericSimsCallRequests { get; set; }
    public bool SelfRemovalEndsRun { get; set; } = true;

    public short this[SimulationGlobal global] { get => Globals[(int)global]; set => Globals[(int)global] = value; }

    public IReadOnlyList<XObject?> ObjectTableEntries => _objectTableEntries;
    private readonly Dictionary<(int X, int Y, int Level), short> _tileRoots = [];

    public int TileValueAt(int tileX, int tileY, int level)
    {
        if (tileX is < 0 or >= 64 || tileY is < 0 or >= 64 || level is < 1 or > 2) return 0;
        return _tileRoots.GetValueOrDefault((tileX, tileY, level));
    }

    public byte BuildModeType6PlacementFlagsAt(int tileX, int tileY, int level)
    {
        if (tileX is < 0 or >= 64 || tileY is < 0 or >= 64 || level is < 1 or > 3) return 0;
        return BuildModeType6PlacementGrids.TryGetValue(level, out var grid) ? grid[tileX * 64 + tileY] : (byte)0;
    }

    public bool HasPlacementEligibilityAt(int tileX, int tileY, int level)
    {
        if (level != 1 || tileX is < 0 or >= 64 || tileY is < 0 or >= 64) return false;
        return PlacementEligibilityGrids.TryGetValue(1, out var grid) && grid[tileX * 64 + tileY] != 0xff;
    }

    public void SetPlacementEligibilityAt(int tileX, int tileY, byte value)
    {
        if (tileX is < 0 or >= 64 || tileY is < 0 or >= 64)
            throw new ArgumentOutOfRangeException(nameof(tileX), "Placement eligibility cells must be inside the lot grid.");
        if (!PlacementEligibilityGrids.TryGetValue(1, out var grid))
        {
            grid = new byte[64 * 64];
            Array.Fill(grid, (byte)0xff);
            PlacementEligibilityGrids.Add(1, grid);
        }
        grid[tileX * 64 + tileY] = value;
    }

    internal bool BlocksRouteDirectionAt(SimsEngine.World.RoomMap map, int tileX, int tileY, int direction)
    {
        if (tileX <= 0 || tileY <= 0 || tileX >= LotGeometry.LotDimension - 1 ||
            tileY >= LotGeometry.LotDimension - 1) return false;
        var mask = map.RouteBlockingMaskAt(tileX, tileY);
        foreach (var item in ObjectsAtTile(tileX, tileY, map.Level))
        {
            var wallBlockFlags = item[ObjectData.WallBlockFlags];
            if (wallBlockFlags == 0) continue;
            var shift = unchecked((byte)item[ObjectData.Direction]) & 0x1f;
            var objectMask = unchecked((uint)((int)wallBlockFlags << shift));
            objectMask = (objectMask & 0xff) | ((objectMask >> 8) & 0xff);
            mask |= objectMask;
        }
        return SimsEngine.World.RoomMap.BlocksRouteDirection(mask, direction);
    }

    private static (int X, int Y, int Level)? TileCell(ObjectPosition position)
    {
        var x = position.X >> 4;
        var y = position.Y >> 4;
        return x is >= 0 and < 64 && y is >= 0 and < 64 && position.Height is >= 1 and <= 2
            ? (x, y, position.Height)
            : null;
    }

    private bool IsInSlotSubtree(XObject target, XObject root)
    {
        var visited = new HashSet<XObject>(ReferenceEqualityComparer.Instance);
        var stack = new Stack<XObject>();
        stack.Push(root);
        while (stack.Count > 0)
        {
            var current = stack.Pop();
            if (!visited.Add(current)) continue;
            if (ReferenceEquals(current, target)) return true;
            for (var i = 0; i < current.Slots.Count; i++)
            {
                var key = current.Slots[i];
                if (key <= 0) continue;
                var child = current.ObjectTableEntry(key) ?? ObjectTableEntry(key);
                if (child is not null) stack.Push(child);
            }
        }
        return false;
    }

    private void InsertTileRoot(XObject item, ObjectPosition? at = null)
    {
        if (item[ObjectData.ParentId] != 0 || item.ClockManagerIndex <= 0 || TileCell(at ?? item.Position) is not { } cell) return;
        _tileRoots[cell] = item.ClockManagerIndex;
    }

    private void RemoveTileRoot(XObject item, ObjectPosition? at = null)
    {
        if (item[ObjectData.ParentId] == 0)
            UnplaceObjectFromGridOrSlot(item, at);
    }

    private void DetachDirectPlacementLink(XObject item, ObjectPosition? at = null)
    {
        if (TileCell(at ?? item.Position) is { } cell &&
            _tileRoots.TryGetValue(cell, out var rootKey) && rootKey == item.ClockManagerIndex)
        {
            _tileRoots.Remove(cell);
        }

        var parentIndex = item[ObjectData.ParentId] > 0 ? item[ObjectData.ParentId] : item[ObjectData.ContainerId];
        var slotIndex = item[ObjectData.SlotHierNumber];
        if (slotIndex < 0 && item[ObjectData.ContainerId] > 0 && item[ObjectData.SlotNumber] > 0)
            slotIndex = item[ObjectData.SlotNumber];
        if (parentIndex > 0 && (item.ObjectTableEntry(parentIndex) ?? ObjectTableEntry(parentIndex) ?? ObjectById(parentIndex)) is { } parent)
        {
            if (slotIndex >= 0)
            {
                if (slotIndex < parent.Slots.Count && parent.Slots[slotIndex] == item.ClockManagerIndex)
                    parent.Slots[slotIndex] = 0;
                if (slotIndex > 0 && slotIndex - 1 < parent.FootprintSlots.Count &&
                    parent.FootprintSlots[slotIndex - 1].OccupantObjectId == item.ClockManagerIndex)
                {
                    parent.FootprintSlots[slotIndex - 1].OccupantObjectId = 0;
                }
            }
            else
            {
                for (var i = 1; i < parent.Slots.Count; i++)
                {
                    if (parent.Slots[i] == item.ClockManagerIndex) parent.Slots[i] = 0;
                }
                for (var i = 0; i < parent.FootprintSlots.Count; i++)
                {
                    if (parent.FootprintSlots[i].OccupantObjectId == item.ClockManagerIndex)
                        parent.FootprintSlots[i].OccupantObjectId = 0;
                }
            }
        }
        item[ObjectData.ParentId] = 0;
        item[ObjectData.SlotHierNumber] = -1;
    }

    private void UnplaceObjectFromGridOrSlot(XObject item, ObjectPosition? at = null)
    {
        var pos = at ?? item.Position;
        var oldCell = TileCell(pos);
        var oldHeight = pos.Height;
        var oldParentKey = item[ObjectData.ParentId];
        var oldSlotIndex = item[ObjectData.SlotHierNumber];
        var oldParent = oldParentKey > 0
            ? item.ObjectTableEntry(oldParentKey) ?? ObjectTableEntry(oldParentKey) ?? ObjectById(oldParentKey)
            : null;
        var wasTileRoot = oldParentKey == 0 && oldCell is { } c &&
                          _tileRoots.TryGetValue(c, out var currentKey) && currentKey == item.ClockManagerIndex;
        var wasParentSlotOccupant = oldParent is not null && oldSlotIndex >= 0 &&
                                    ((oldSlotIndex < oldParent.Slots.Count && oldParent.Slots[oldSlotIndex] == item.ClockManagerIndex) ||
                                     (oldSlotIndex > 0 && oldSlotIndex - 1 < oldParent.FootprintSlots.Count &&
                                      oldParent.FootprintSlots[oldSlotIndex - 1].OccupantObjectId == item.ClockManagerIndex));

        DetachDirectPlacementLink(item, pos);

        if (item.Slots.Count > 0 && item.Slots[0] > 0)
        {
            var displacedKey = item.Slots[0];
            item.Slots[0] = 0;
            var displaced = item.ObjectTableEntry(displacedKey) ?? ObjectTableEntry(displacedKey);
            if (displaced is not null && !ReferenceEquals(displaced, item))
            {
                DetachDirectPlacementLink(displaced);
                if (wasParentSlotOccupant && oldParent is not null && !ReferenceEquals(oldParent, displaced) &&
                    !IsInSlotSubtree(oldParent, displaced) && !IsInSlotSubtree(displaced, oldParent))
                {
                    if (oldSlotIndex < oldParent.Slots.Count)
                        oldParent.Slots[oldSlotIndex] = displaced.ClockManagerIndex;
                    if (oldSlotIndex > 0 && oldSlotIndex - 1 < oldParent.FootprintSlots.Count)
                        oldParent.FootprintSlots[oldSlotIndex - 1].OccupantObjectId = displaced.ClockManagerIndex;
                    displaced[ObjectData.ParentId] = oldParent.ClockManagerIndex;
                    displaced[ObjectData.SlotHierNumber] = oldSlotIndex;
                    if (oldSlotIndex > 0)
                    {
                        displaced[ObjectData.ContainerId] = oldParent.ClockManagerIndex;
                        displaced[ObjectData.SlotNumber] = oldSlotIndex;
                    }
                    SetObjectPosition(displaced, displaced.Position with { Height = oldParent.Position.Height });
                }
                else if (wasTileRoot && oldCell is { } rootCell && displaced.ClockManagerIndex > 0)
                {
                    _tileRoots[rootCell] = displaced.ClockManagerIndex;
                    SetObjectPosition(displaced, displaced.Position with { Height = oldHeight });
                }
            }
        }
    }

    private void DetachFromFootprintSlot(XObject item)
    {
        if (item[ObjectData.ParentId] > 0 || item[ObjectData.ContainerId] > 0)
            UnplaceObjectFromGridOrSlot(item);
        else
            DetachDirectPlacementLink(item);
    }

    private void MoveTileRoot(XObject item, ObjectPosition destination, XObject? placementContainer = null,
        short placementSlotNumber = 0, Action<XObject>? onPriorContainerDetached = null)
    {
        var previous = item.Position;
        var previousDirection = item.FootprintBoundsDirection ?? item[ObjectData.Direction];
        var isChair = HasFunction(item, 0x1a);
        var oldContainer = ResolveParentContainer(item);
        var wasFloorPlaced = oldContainer is null && TileCell(previous) is not null;
        if (oldContainer is not null && !ReferenceEquals(oldContainer, placementContainer))
            onPriorContainerDetached?.Invoke(oldContainer);

        SetBuildModeType6PlacementFlag(item, previous, false);
        UnplaceObjectFromGridOrSlot(item, previous);
        if (wasFloorPlaced && isChair && (TileCell(previous) != TileCell(destination) || placementContainer is not null))
        {
            var oldOffset = LotGeometry.FootprintOffset(previousDirection);
            UpdateAdjacentChairFlag((previous.X >> 4) + (oldOffset.X >> 4),
                (previous.Y >> 4) + (oldOffset.Y >> 4), previous.Height);
        }

        short destinationOccupantKey = 0;
        if (placementContainer is not null)
        {
            if (placementSlotNumber > 0 && placementSlotNumber - 1 < placementContainer.FootprintSlots.Count)
                destinationOccupantKey = placementContainer.FootprintSlots[placementSlotNumber - 1].OccupantObjectId;
            else if (placementSlotNumber >= 0 && placementSlotNumber < placementContainer.Slots.Count)
                destinationOccupantKey = placementContainer.Slots[placementSlotNumber];
        }
        else if (TileCell(destination) is { } targetCell)
        {
            destinationOccupantKey = checked((short)TileValueAt(targetCell.X, targetCell.Y, targetCell.Level));
        }

        var displacedObject = destinationOccupantKey > 0
            ? item.ObjectTableEntry(destinationOccupantKey) ?? ObjectTableEntry(destinationOccupantKey)
            : null;
        if (displacedObject is not null &&
            (ReferenceEquals(displacedObject, item) ||
             IsInSlotSubtree(item, displacedObject) ||
             IsInSlotSubtree(displacedObject, item)))
        {
            displacedObject = null;
        }
        if (displacedObject is not null)
            DetachDirectPlacementLink(displacedObject);

        item[ObjectData.ContainerId] = placementContainer?.ClockManagerIndex ?? 0;
        item[ObjectData.SlotNumber] = placementContainer is null ? (short)0 : placementSlotNumber;
        item[ObjectData.ParentId] = placementContainer?.ClockManagerIndex ?? 0;
        item[ObjectData.SlotHierNumber] = placementContainer is null ? (short)-1 : placementSlotNumber;
        if (placementContainer is not null)
        {
            if (placementSlotNumber >= 0 && placementSlotNumber < placementContainer.Slots.Count)
                placementContainer.Slots[placementSlotNumber] = item.ClockManagerIndex;
            if (placementSlotNumber > 0 && placementSlotNumber - 1 < placementContainer.FootprintSlots.Count)
                placementContainer.FootprintSlots[placementSlotNumber - 1].OccupantObjectId = item.ClockManagerIndex;
        }
        else if (item.ClockManagerIndex > 0 && TileCell(destination) is { } destinationCell)
        {
            _tileRoots[destinationCell] = item.ClockManagerIndex;
        }

        var currentDirection = item[ObjectData.Direction];
        SetObjectPosition(item, destination);
        if (displacedObject is not null && item.ClockManagerIndex > 0)
        {
            if (item.Slots.Count == 0) item.Slots.Add(0);
            item.Slots[0] = displacedObject.ClockManagerIndex;
            displacedObject[ObjectData.ParentId] = item.ClockManagerIndex;
            displacedObject[ObjectData.SlotHierNumber] = 0;
            SetObjectPosition(displacedObject, displacedObject.Position with { Height = destination.Height });
        }

        SetBuildModeType6PlacementFlag(item, destination, true);
        UpdateAdjacentChairFlag(destination.X >> 4, destination.Y >> 4, destination.Height);
        if (isChair)
        {
            if (TileCell(previous) == TileCell(destination) && placementContainer is null && wasFloorPlaced &&
                previousDirection != currentDirection)
            {
                var oldOffset = LotGeometry.FootprintOffset(previousDirection);
                UpdateAdjacentChairFlag((previous.X >> 4) + (oldOffset.X >> 4),
                    (previous.Y >> 4) + (oldOffset.Y >> 4), previous.Height);
            }
            if (placementContainer is null)
            {
                var newOffset = LotGeometry.FootprintOffset(currentDirection);
                UpdateAdjacentChairFlag((destination.X >> 4) + (newOffset.X >> 4),
                    (destination.Y >> 4) + (newOffset.Y >> 4), destination.Height);
            }
        }
        if ((unchecked((ushort)item[ObjectData.FlagField2]) & 0x0400) != 0)
            DispatchNotice(0xf2, item.ClockManagerIndex);
    }

    internal void UpdateAdjacentChairFlag(int tileX, int tileY, int level)
    {
        var size = LotGeometry.LotDimension;
        if (tileX <= 0 || tileY <= 0 || tileX >= size - 1 || tileY >= size - 1) return;
        var tileObjects = ObjectsAtTile(tileX, tileY, level).ToList();
        if (tileObjects.Count == 0) return;

        var hasAdjacentChair = false;
        for (short dir = 0; dir < 8; dir += 2)
        {
            var offset = LotGeometry.FootprintOffset(dir);
            var nx = tileX + (offset.X >> 4);
            var ny = tileY + (offset.Y >> 4);
            if (nx <= 0 || ny <= 0 || nx >= size - 1 || ny >= size - 1) continue;
            var neighbor = ObjectsAtTile(nx, ny, level).FirstOrDefault(candidate =>
                candidate is not XPerson &&
                (candidate[ObjectData.ParentId] == 0 || candidate[ObjectData.SlotHierNumber] == 0) &&
                (unchecked((ushort)candidate[ObjectData.Flags]) & 4) == 0);
            if (neighbor is not null && HasFunction(neighbor, 0x1a) &&
                (neighbor[ObjectData.Direction] & 7) == ((dir + 4) & 7))
            {
                hasAdjacentChair = true;
                break;
            }
        }

        foreach (var obj in tileObjects)
        {
            var oldFlags = unchecked((ushort)obj[ObjectData.Flags]);
            var newFlags = hasAdjacentChair ? (ushort)(oldFlags | 0x0100) : (ushort)(oldFlags & ~0x0100);
            obj[ObjectData.Flags] = unchecked((short)newFlags);
            if (((oldFlags ^ newFlags) & 0x0100) != 0 && HasFunction(obj, 0x19))
                RunFunctionToCompletion(obj, 9);
        }
    }

    private void SetBuildModeType6PlacementFlag(XObject item, ObjectPosition position, bool present)
    {
        if (item.Definition[(int)ObjdField.BuildModeType] != 6) return;
        var x = position.X >> 4;
        var y = position.Y >> 4;
        var size = LotGeometry.LotDimension;
        if (x <= 0 || y <= 0 || x >= size - 1 || y >= size - 1 || position.Height is < 1 or > 3) return;
        if (!BuildModeType6PlacementGrids.TryGetValue(position.Height, out var grid))
        {
            if (!present) return;
            grid = new byte[size * size];
            BuildModeType6PlacementGrids.Add(position.Height, grid);
        }
        var index = x * size + y;
        grid[index] = present ? (byte)(grid[index] | 0x08) : (byte)(grid[index] & ~0x08);
    }

    public IEnumerable<XObject> ObjectsAtTile(int tileX, int tileY, int level)
    {
        var rootKey = TileValueAt(tileX, tileY, level);
        if (rootKey <= 0 || rootKey > short.MaxValue || ObjectTableEntry((short)rootKey) is not { } root) yield break;

        var activePath = new HashSet<short>();
        foreach (var item in EnumerateSlotSubtree(root, activePath))
            yield return item;
    }

    private IEnumerable<XObject> EnumerateSlotSubtree(XObject root, HashSet<short> activePath)
    {
        if (!activePath.Add(root.Id)) yield break;
        var visited = new HashSet<short> { root.Id };
        var stack = new Stack<(XObject Node, int NextSlot)>();
        stack.Push((root, 0));
        try
        {
            yield return root;
            while (stack.Count > 0)
            {
                var (node, nextSlot) = stack.Pop();
                var descended = false;
                while (nextSlot < node.Slots.Count)
                {
                    var child = ObjectTableEntry(node.Slots[nextSlot++]);
                    if (child is null) continue;
                    if (!visited.Add(child.Id) || !activePath.Add(child.Id)) continue;
                    stack.Push((node, nextSlot));
                    stack.Push((child, 0));
                    descended = true;
                    yield return child;
                    break;
                }
                if (!descended)
                    activePath.Remove(node.Id);
            }
        }
        finally
        {
            while (stack.Count > 0)
                activePath.Remove(stack.Pop().Node.Id);
            activePath.Remove(root.Id);
        }
    }

    internal static bool BurnSourceOnLot(XObject source)
    {
        ArgumentNullException.ThrowIfNull(source);
        var tileX = (sbyte)(source.Position.X >> 4);
        var tileY = (sbyte)(source.Position.Y >> 4);
        return tileX > 0 && tileY > 0 && tileX < LotGeometry.LotDimension - 1 && tileY < LotGeometry.LotDimension - 1;
    }

    internal bool TryBurnTile(int tileX, int tileY, short height, bool strictFlags, TreeStack? checkStack = null) =>
        TryBurnTile(new ObjectPosition(tileX * 16 + 8, tileY * 16 + 8, height), strictFlags, checkStack);

    internal bool TryBurnTile(ObjectPosition position, bool strictFlags, TreeStack? checkStack = null)
    {
        var tileX = (sbyte)(position.X >> 4);
        var tileY = (sbyte)(position.Y >> 4);
        if (tileX <= 0 || tileY <= 0 || tileX >= LotGeometry.LotDimension - 1 ||
            tileY >= LotGeometry.LotDimension - 1 || position.Height is < 1 or > 2) return false;

        XObject? seed = null;
        foreach (var item in ObjectsAtTile(tileX, tileY, position.Height))
        {
            if ((unchecked((ushort)item[ObjectData.FlagField2]) & 0x0020) != 0)
                seed = item;
            if ((unchecked((ushort)item[ObjectData.Flags]) & 0x0800) != 0 ||
                item.TypeRecord?.Key == BurnPrimitive.FireType) return false;
        }
        if (seed is null) return TryCreateBurnFire(position, checkStack);

        var burnable = new List<XObject> { seed };
        var burnableIds = new HashSet<short> { seed.Id };

        ReadOnlySpan<(int X, int Y)> neighbors = [
            (-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)];
        for (var cursor = 0; cursor < burnable.Count; cursor++)
        {
            var candidate = burnable[cursor];
            if ((candidate.RuntimeClass is SimsEngine.Formats.ObjectClass.MultiTileObject or SimsEngine.Formats.ObjectClass.Portal ||
                 candidate.MultiTileMasterId != 0 || candidate.MultiTileNextId != 0) &&
                (unchecked((ushort)candidate[ObjectData.FlagField2]) & 0x0020) != 0 &&
                !HasFunction(candidate, 8))
            {
                foreach (var member in MultiTileMembers(candidate))
                    AddUnique(member);
            }

            var candidateX = (sbyte)(candidate.Position.X >> 4);
            var candidateY = (sbyte)(candidate.Position.Y >> 4);
            foreach (var sameTile in ObjectsAtTile(candidateX, candidateY, candidate.Position.Height))
            {
                if ((unchecked((ushort)sameTile[ObjectData.FlagField2]) & 0x0020) != 0)
                    AddUnique(sameTile);
            }

            foreach (var (dx, dy) in neighbors)
            {
                var nx = candidateX + dx;
                var ny = candidateY + dy;
                foreach (var adjacent in ObjectsAtTile(nx, ny, candidate.Position.Height))
                {
                    var adjacentBounds = adjacent.FootprintBoundsDirection == adjacent[ObjectData.Direction]
                        ? adjacent.FootprintBounds
                        : PlacementFootprintBounds(adjacent, adjacent.Position);
                    if (FootprintsOverlapCell(adjacent, adjacentBounds, candidateX, candidateY))
                        AddUnique(adjacent);
                }
            }

            void AddUnique(XObject item)
            {
                if (burnableIds.Add(item.Id))
                    burnable.Add(item);
            }
        }

        foreach (var item in burnable)
        {
            var flags = unchecked((ushort)item[ObjectData.Flags]);
            if ((flags & 0x0800) != 0 || (strictFlags && ((flags & 0x0020) != 0 || item.Data[62] > 0))) return false;
        }

        foreach (var item in burnable)
        {
            if (item is not XPerson person) continue;
            var pos = person.Position;
            ResetPersonForChangedCode(person);
            var snappedPosition = new ObjectPosition((pos.X & ~0x7) | 8, (pos.Y & ~0xf) | 8, pos.Height);
            PlaceObject(person, snappedPosition, checkStack ?? TreeRunner.CreateTransientStack(this, person));
            RefreshPersonPlacementCallbacksAfterMovement(person);
        }

        var placed = false;
        foreach (var item in burnable)
        {
            var objectTileX = (sbyte)(item.Position.X >> 4);
            var objectTileY = (sbyte)(item.Position.Y >> 4);
            if (ObjectsAtTile(objectTileX, objectTileY, item.Position.Height)
                .Any(occupant => occupant.TypeRecord?.Key == BurnPrimitive.FireType)) continue;
            var firePosition = new ObjectPosition((item.Position.X & ~0x7) | 8, (item.Position.Y & ~0xf) | 8, item.Position.Height);
            placed |= TryCreateBurnFire(firePosition, checkStack);
        }
        return placed;

        static bool FootprintsOverlapCell(XObject item, FootprintBounds bounds, int tileX, int tileY)
        {
            var expansion = item is XPerson ? 2 : 0;
            var minX = bounds.MinX - expansion;
            var maxX = bounds.MaxX + expansion;
            var minY = bounds.MinY - expansion;
            var maxY = bounds.MaxY + expansion;
            var cellMinX = tileX * 16;
            var cellMaxX = cellMinX + 16;
            var cellMinY = tileY * 16;
            var cellMaxY = cellMinY + 16;
            return minX < cellMaxX && cellMinX < maxX && minY < cellMaxY && cellMinY < maxY;
        }
    }

    private bool TryCreateBurnFire(ObjectPosition position, TreeStack? checkStack = null)
    {
        if (ObjectFactory?.Invoke(BurnPrimitive.FireType) is not { } fire) return false;
        Add(fire);
        InitializeCreatedObject(fire);
        var effectiveStack = checkStack ?? TreeRunner.CreateTransientStack(this, fire);
        if (!CanPlaceCreatedObject(fire, position, checkStack: effectiveStack))
        {
            Remove(fire.Id);
            return false;
        }
        PlaceObject(fire, position, effectiveStack);
        return true;
    }

    public void BeginObjectRemoval(XObject item, int argument)
    {
        ArgumentNullException.ThrowIfNull(item);
        if (argument is not (0 or 1)) throw new ArgumentOutOfRangeException(nameof(argument), "The source +0x50 callback paths use arguments 0 or 1.");

        if (item.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal)
        {
            foreach (var member in MultiTileMembers(item)) RefreshPortalWallStyleOverlay(member, resetToDefault: true);
            foreach (var routeOwner in WalkOrder) routeOwner.ResetAllocatedPortalRouteCosts();
        }

        if (item.Definition is { Length: > (int)ObjdField.MasterId } &&
            item.Definition[(int)ObjdField.MasterId] == 0)
        {
            RunFunctionToCompletion(item, 10);
        }

        if ((unchecked((ushort)item[ObjectData.FlagField2]) & 0x0400) != 0)
            DispatchNotice(0xf2, item.ClockManagerIndex);
        SetBuildModeType6PlacementFlag(item, item.Position, false);
        var oldPosition = item.Position;
        var oldDirection = item[ObjectData.Direction];
        var oldContainer = ResolveParentContainer(item);
        DetachFromFootprintSlot(item);
        RemoveTileRoot(item);
        SetObjectPosition(item, new ObjectPosition(-16, -16, 1));
        if (HasFunction(item, 0x1a))
        {
            var oldOffset = LotGeometry.FootprintOffset(oldDirection);
            UpdateAdjacentChairFlag((oldPosition.X >> 4) + (oldOffset.X >> 4),
                (oldPosition.Y >> 4) + (oldOffset.Y >> 4), oldPosition.Height);
        }
        item.RemovalCallbackWord14 = -1;
        item.Data[2] = 0;
        item.Data[8] = (short)(item.Data[8] & 0xfeff);
        if (oldContainer is not null)
            RunFunctionToCompletion(oldContainer, 9);
        DisplayRefreshRequested = true;
        if (argument != 0) RefreshInteractionAfterObjectRemoval(item);
    }

    private void RefreshInteractionAfterObjectRemoval(XObject removed)
    {
        if (!InteractionRefreshManagerEnabled) return;
        if (ReferenceEquals(ActiveInteractionRefreshTarget, removed)) InteractionContextsInvalidated = true;

        XObject? target = removed;
        if (removed.TypeRecord?.ObjectType == XPerson.PersonType)
        {
            var occupantKey = removed.FootprintSlots.Count >= 2 ? removed.FootprintSlots[1].OccupantObjectId : (short)0;
            target = occupantKey > 0 ? ObjectTableEntry(occupantKey) ?? ObjectById(occupantKey) : null;
        }
        if (target is null) return;

        if (InteractionRefreshTypeKey == unchecked((int)0xe9337020u))
        {
            var index = InteractionRefreshPendingObjects.FindIndex(candidate => ReferenceEquals(candidate, target));
            if (index >= 0)
            {
                InteractionRefreshDeferredObjects.Add(InteractionRefreshPendingObjects[index]);
                InteractionRefreshPendingObjects.RemoveAt(index);
            }
        }
        else if (InteractionRefreshTypeKey is not (0x0baa71c5 or 0x2f726fff))
            return;

        BeginObjectRemoval(target, 0);
    }

    internal void DetachMultiTilePart(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        var firstPart = item.MultiTileNextId == 0 ? null : ObjectById(item.MultiTileNextId);
        if (item.MultiTileMasterId == 0)
        {
            var current = item;
            var visited = new HashSet<short>();
            while (current is not null && visited.Add(current.Id))
            {
                var nextId = current.MultiTileNextId;
                current.MultiTileMasterId = firstPart?.Id ?? (short)0;
                current = nextId == 0 ? null : ObjectById(nextId);
            }
            if (firstPart is not null) firstPart.MultiTileMasterId = 0;
        }
        else
        {
            var previous = ObjectById(item.MultiTileMasterId);
            var visited = new HashSet<short>();
            while (previous is not null && visited.Add(previous.Id))
            {
                var next = previous.MultiTileNextId == 0 ? null : ObjectById(previous.MultiTileNextId);
                if (ReferenceEquals(next, item))
                {
                    previous.MultiTileNextId = item.MultiTileNextId;
                    break;
                }
                previous = next;
            }
        }

        item.MultiTileMasterId = 0;
        item.MultiTileNextId = 0;
    }

    private sealed record ResetObjectSnapshot(
        XObject Item,
        ObjectPosition PreviousPosition,
        Dictionary<ObjectData, short> PreservedData,
        XObject? Parent,
        short ParentSlot,
        bool RestoreParentSlot,
        bool ValidPriorTile,
        XObject? DirectParent,
        short DirectSlot);

    private ResetObjectSnapshot CaptureResetObjectSnapshot(XObject item)
    {
        var previousPosition = item.Position;
        var preservedData = PreservedInitializerData(item);
        var anchor = item;
        for (var visited = 0; visited < 64 && anchor[ObjectData.SlotHierNumber] == 0 &&
                              ObjectTableEntry(anchor[ObjectData.ParentId]) is { } above && !ReferenceEquals(above, anchor); visited++)
            anchor = above;
        var parentKey = anchor[ObjectData.ParentId];
        var parentSlot = anchor[ObjectData.SlotHierNumber];
        var parent = ObjectTableEntry(parentKey);
        var validPriorTile = previousPosition.Height is >= 1 and <= 3 &&
            previousPosition.X >> 4 is > 0 and < LotGeometry.LotDimension - 1 &&
            previousPosition.Y >> 4 is > 0 and < LotGeometry.LotDimension - 1;
        var directParent = ObjectTableEntry(item[ObjectData.ParentId]);
        var directSlot = item[ObjectData.SlotHierNumber];
        var restoreParentSlot = parent is not null && parentSlot >= 0 && parentSlot < parent.Slots.Count;
        return new ResetObjectSnapshot(item, previousPosition, preservedData, parent, parentSlot,
            restoreParentSlot, validPriorTile, directParent, directSlot);
    }

    private void DetachAndInitializeResetObject(ResetObjectSnapshot snapshot)
    {
        var item = snapshot.Item;
        BeginObjectRemoval(item, 1);

        if (snapshot.DirectParent is not null && snapshot.DirectSlot >= 0 && snapshot.DirectSlot < snapshot.DirectParent.Slots.Count)
        {
            if (snapshot.DirectParent.Slots[snapshot.DirectSlot] == item.ClockManagerIndex) snapshot.DirectParent.Slots[snapshot.DirectSlot] = 0;
            if (snapshot.DirectSlot > 0 && snapshot.DirectSlot - 1 < snapshot.DirectParent.FootprintSlots.Count &&
                snapshot.DirectParent.FootprintSlots[snapshot.DirectSlot - 1].OccupantObjectId == item.ClockManagerIndex)
                snapshot.DirectParent.FootprintSlots[snapshot.DirectSlot - 1].OccupantObjectId = 0;
        }

        InitializeObjectData(item, snapshot.PreservedData);

        if (snapshot.RestoreParentSlot && snapshot.Parent is not null)
        {
            var parent = snapshot.Parent;
            var parentSlot = snapshot.ParentSlot;
            var existingSlotKey = parentSlot > 0 && parentSlot - 1 < parent.FootprintSlots.Count
                ? parent.FootprintSlots[parentSlot - 1].OccupantObjectId
                : parent.Slots[parentSlot];
            var displacedPeer = existingSlotKey > 0 && existingSlotKey != item.ClockManagerIndex
                ? ObjectTableEntry(existingSlotKey)
                : null;
            if (displacedPeer is not null &&
                (ReferenceEquals(displacedPeer, item) ||
                 IsInSlotSubtree(item, displacedPeer) ||
                 IsInSlotSubtree(displacedPeer, item)))
            {
                displacedPeer = null;
            }
            if (displacedPeer is not null) DetachDirectPlacementLink(displacedPeer);
            parent.Slots[parentSlot] = item.ClockManagerIndex;
            if (parentSlot > 0 && parentSlot - 1 < parent.FootprintSlots.Count)
                parent.FootprintSlots[parentSlot - 1].OccupantObjectId = item.ClockManagerIndex;
            item[ObjectData.ParentId] = parent.ClockManagerIndex;
            item[ObjectData.ContainerId] = parent.ClockManagerIndex;
            item[ObjectData.SlotNumber] = parentSlot;
            item[ObjectData.SlotHierNumber] = parentSlot;
            if (displacedPeer is not null && item.ClockManagerIndex > 0)
            {
                if (item.Slots.Count == 0) item.Slots.Add(0);
                item.Slots[0] = displacedPeer.ClockManagerIndex;
                displacedPeer[ObjectData.ParentId] = item.ClockManagerIndex;
                displacedPeer[ObjectData.SlotHierNumber] = 0;
            }
        }
    }

    private void ResetObjectAfterScriptError(XObject item, TreeStack? activeStack)
    {
        if (item.MultiTileMasterId != 0 || item.MultiTileNextId != 0)
        {
            var lead = item.MultiTileMasterId != 0 ? ObjectById(item.MultiTileMasterId) ?? item : item;
            var group = MultiTileMembers(lead);
            if (group.Count > 1)
            {
                // Matches Sims.exe cXMTObject::Reset (004231a8.c): unplace/initialize all parts,
                // run init (function 0) on every part, and re-place the group so cross-part
                // placement callbacks (e.g. stair BHAV 4122) see initialized sibling Attributes.
                var snapshots = new List<ResetObjectSnapshot>(group.Count);
                foreach (var member in group)
                {
                    if (member is XPerson resettingMember)
                    {
                        InteractionLifecycle.FinalizeActor(resettingMember);
                        ResetPersonAnimatorForChangedCode(resettingMember);
                    }
                    else InteractionLifecycle.FinalizeRink(member);
                    snapshots.Add(CaptureResetObjectSnapshot(member));
                }
                foreach (var snapshot in snapshots)
                {
                    SavedExecutionStacks.Remove(snapshot.Item.Id);
                    DetachAndInitializeResetObject(snapshot);
                }
                foreach (var snapshot in snapshots)
                    FinishObjectInitializer(snapshot.Item, runTick: true, finishMultiTileMember: true);

                var leadSnapshot = snapshots[0];
                if (lead.RuntimeClass is SimsEngine.Formats.ObjectClass.MultiTileObject or SimsEngine.Formats.ObjectClass.Portal)
                {
                    if (leadSnapshot.RestoreParentSlot || leadSnapshot.ValidPriorTile)
                        PlaceObject(lead, leadSnapshot.PreviousPosition, activeStack ?? TreeRunner.CreateTransientStack(this, lead),
                            leadSnapshot.RestoreParentSlot ? leadSnapshot.Parent : null,
                            leadSnapshot.RestoreParentSlot ? checked((short)leadSnapshot.ParentSlot) : (short)0);
                }
                else
                {
                    foreach (var snapshot in snapshots)
                    {
                        if (snapshot.RestoreParentSlot || snapshot.ValidPriorTile)
                            PlaceObject(snapshot.Item, snapshot.PreviousPosition, activeStack ?? TreeRunner.CreateTransientStack(this, snapshot.Item),
                                snapshot.RestoreParentSlot ? snapshot.Parent : null,
                                snapshot.RestoreParentSlot ? checked((short)snapshot.ParentSlot) : (short)0);
                    }
                }
                foreach (var member in group) StopObjectSounds(member.Id);
                return;
            }
        }

        if (item is XPerson resettingPerson)
        {
            InteractionLifecycle.FinalizeActor(resettingPerson);
            ResetPersonAnimatorForChangedCode(resettingPerson);
        }
        else InteractionLifecycle.FinalizeRink(item);
        var singleSnapshot = CaptureResetObjectSnapshot(item);
        DetachAndInitializeResetObject(singleSnapshot);
        // Runs init (function 0) and the initial tick only for lead/single objects (cXObject::Reset 00431c90.c:70).
        FinishObjectInitializer(item, runTick: true, finishMultiTileMember: false);

        if (singleSnapshot.RestoreParentSlot || singleSnapshot.ValidPriorTile)
            PlaceObject(item, singleSnapshot.PreviousPosition, activeStack,
                singleSnapshot.RestoreParentSlot ? singleSnapshot.Parent : null,
                singleSnapshot.RestoreParentSlot ? checked((short)singleSnapshot.ParentSlot) : (short)0);
        StopObjectSounds(item.Id);
    }

    private static Dictionary<ObjectData, short> PreservedInitializerData(XObject item) => new()
    {
        [ObjectData.Direction] = item[ObjectData.Direction],
        [ObjectData.BirthMinute] = item[ObjectData.BirthMinute],
        [ObjectData.BirthHour] = item[ObjectData.BirthHour],
        [ObjectData.Room] = item[ObjectData.Room],
        [ObjectData.CurrentValue] = item[ObjectData.CurrentValue],
        [ObjectData.BirthYear] = item[ObjectData.BirthYear],
        [ObjectData.BirthMonth] = item[ObjectData.BirthMonth],
        [ObjectData.BirthDay] = item[ObjectData.BirthDay],
        [ObjectData.SlotCount] = item[ObjectData.SlotCount],
    };

    private void InitializeObjectData(XObject item, Dictionary<ObjectData, short> preservedData)
    {
        Array.Clear(item.Data);
        item[ObjectData.ObjectId] = item.ClockManagerIndex;
        item[ObjectData.ObjectVersion] = item.TypeRecord?.ObjectVersion ?? 0;
        foreach (var (field, value) in preservedData)
            item[field] = field == ObjectData.Direction ? (short)(value & 7) : value;
        if (CurrentDate is { } currentDate)
            RecomputeObjectAge(item, currentDate);
        item[ObjectData.SlotHierNumber] = -1;
        Array.Clear(item.Attributes);
        Array.Clear(item.Temporaries);
        item.SavedStack.Clear();
        item.SavedStackSize = 0;

        RunObjectResetInitializer(item);
    }

    private void FinishObjectInitializer(XObject item, bool runTick, bool finishMultiTileMember = false,
        XObject? autonomyRoot = null)
    {
        if (item.ClockManagerIndex > 0) ClockManager.SetWaitTicksAt(item.ClockManagerIndex, -1);
        if (item.Definition is not { Length: > (int)ObjdField.MasterId } definition ||
            (definition[(int)ObjdField.MasterId] != 0 && !finishMultiTileMember)) return;
        var callerLocation = CaptureExecutionLocation();
        try
        {
            if (FunctionTreeId(item, 0) is var initTree && initTree != 0 && item.TypeRecord?.BehaviorScope is { } scope)
                TreeRunner.RunWithParameters(this, item, scope, initTree, 0, []);
            if (runTick && SavedExecutionStacks.ContainsKey(item.Id))
                TreeRunner.RunRestoredObjectStack(this, item);
        }
        finally
        {
            RestoreExecutionLocation(callerLocation);
        }
        if (item.ClockManagerIndex <= 0 || !ReferenceEquals(item, ObjectById(item.Id))) return;
        ClockManager.SetFlag(item.ClockManagerIndex, 1, item[ObjectData.SimulateOnPause] != 0);
        var root = autonomyRoot ?? InteractionMenus.Target(this, item);
        InitializeAutonomyCandidate(item, root, root.TypeRecord?.Interactions);
    }

    public void InitializeCreatedObject(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        if (!ReferenceEquals(item, ObjectById(item.Id)))
            throw new InvalidOperationException($"Object {item.Id} is not registered in this simulation world.");
        PrepareCreatedObject(item);
        InitializeObjectData(item, PreservedInitializerData(item));
        FinishObjectInitializer(item, runTick: true);
        if (item.Definition is { Length: > (int)ObjdField.Price } definition)
            item[ObjectData.CurrentValue] = definition[(int)ObjdField.Price];
        item.Flags |= 0x80u;
        ClockManager.SetTickEnabled(item, true);
        DispatchNotice(0xe2, item.ClockManagerIndex);
    }

    public NeighborState? BindPersonToNeighborRecord(XPerson person)
    {
        ArgumentNullException.ThrowIfNull(person);
        if (!ReferenceEquals(person, ObjectById(person.Id)))
            throw new InvalidOperationException($"Person {person.Id} is not registered in this simulation world.");
        var typeKey = person.TypeRecord?.Key;
        var neighbor = typeKey is null ? null : Neighbors.Values.FirstOrDefault(item => item.TypeRecordKey == typeKey.Value);
        if (neighbor is null && typeKey is not null)
        {
            neighbor = AddCreatedPersonNeighbor(person, typeKey.Value);
            person[PersonData.NeighborId] = neighbor.Id;
            SyncPersonScopeWithNeighborInventory(person, neighbor.Id);
            return neighbor;
        }
        if (neighbor is not null)
        {
            person[PersonData.NeighborId] = neighbor.Id;
            SyncPersonScopeWithNeighborInventory(person, neighbor.Id);
            var version = neighbor.PersonRecordVersion;
            if (version > 0)
            {
                ReadOnlySpan<(int Field, int MinVersion)> versionedFields =
                [
                    (2, 1), (3, 1), (4, 1), (5, 1), (6, 1), (7, 1), (9, 1), (10, 1), (0x0b, 1), (0x0c, 1),
                    (0x10, 1), (0x14, 1), (0x0f, 1), (0x1a, 1), (0x11, 1), (0x12, 1),
                    (0x2e, 1), (0x2f, 1), (0x30, 1), (0x31, 1), (0x32, 1), (0x33, 1), (0x34, 1), (0x35, 1),
                    (0x0d, 1), (0x0e, 1), (0x3a, 1), (0x3c, 1), (0x3d, 1),
                    (0x38, 2), (0x39, 2), (0x3f, 2),
                    (0x41, 3),
                    (0x43, 4), (0x44, 4),
                    (0x45, 5), (0x46, 1),
                    (0x4a, 6),
                    (0x36, 7), (0x37, 7), (0x4b, 7), (0x4c, 7),
                    (0x50, 8), (0x51, 8),
                    (0x52, 9),
                    (0x53, 10), (0x54, 10), (0x55, 10), (0x56, 10),
                ];
                foreach (var (field, minVersion) in versionedFields)
                {
                    if (version >= minVersion && field != (int)PersonData.FamilyNumber)
                        person.PersonData[field] = neighbor.PersonData[field];
                }
            }
            // Preserves the saved family number on unpersisted catalog or tutorial Sims.
            if (version > 0 || neighbor.PersonData[(int)PersonData.FamilyNumber] != 0)
                person[PersonData.FamilyNumber] = neighbor.PersonData[(int)PersonData.FamilyNumber];
        }
        return neighbor;
    }

    private void SyncPersonScopeWithNeighborInventory(XPerson person, short neighborId)
    {
        if (neighborId <= 0) return;
        var inventory = NeighborInventory(neighborId);
        if (InteractionScopes.TryGetValue(person.InteractionScopeKey5CA, out var existing))
        {
            if (existing.IsBackedBy(inventory)) return;
            for (short i = 0; i < existing.Count; i++)
            {
                if (existing.TryGet(i, out var entry))
                    inventory.Add(entry.Value, entry.Mode, unchecked((short)entry.Result));
            }
            if (existing.Count > 0) inventory.MarkChanged();
            if (!existing.TryBindResolver(() => NeighborInventory(neighborId)))
            {
                var backed = new InteractionScopeTable(() => NeighborInventory(neighborId));
                backed.AvatarObjects.AddRange(existing.AvatarObjects);
                InteractionScopes[person.InteractionScopeKey5CA] = backed;
            }
        }
        else
        {
            InteractionScopes[person.InteractionScopeKey5CA] = new InteractionScopeTable(() => NeighborInventory(neighborId));
        }
    }

    public void InitializeCreatedPerson(XPerson person)
    {
        var neighbor = BindPersonToNeighborRecord(person);
        if (neighbor is not null)
        {
            foreach (var (otherId, values) in neighbor.Relationships.Snapshot())
            {
                var targetId = checked((short)otherId);
                person.Relationships.Resize(targetId, values.Count);
                for (var index = 0; index < values.Count; index++)
                    person.Relationships.Set(targetId, index, values[index]);
            }
        }

        if (Enumerable.Range(0x2e, 8).All(field => person.PersonData[field] <= 10))
            RandomizeCreatedPersonInterests(person);
    }

    internal void ArriveCreatedPerson(XPerson person)
    {
        ArgumentNullException.ThrowIfNull(person);
        if (!ReferenceEquals(person, ObjectById(person.Id)) || person[PersonData.PersonType] == 0 ||
            person.TypeRecord?.BehaviorScope is not Content.BehaviorScope scope) return;
        var tree = scope.FindNamedTree("init visitor");
        if (tree == 0) return;
        TreeRunner.RunWithParameters(this, person, scope, tree, person.ClockManagerIndex, []);
    }

    private NeighborState AddCreatedPersonNeighbor(XPerson person, int typeKey)
    {
        var slot = NeighborWalkOrder.FindIndex(neighbor => neighbor is null);
        if (!NeighborRosterComplete && (slot < 0 || slot >= CompleteNeighborSlotPrefix))
            throw new InvalidOperationException("Cannot allocate a neighbor id because the loaded neighborhood roster has an unknown tail.");
        if (slot < 0)
        {
            slot = NeighborWalkOrder.Count;
            NeighborWalkOrder.Add(null);
        }
        var id = checked((short)(slot + 1));
        while (Neighbors.ContainsKey(id))
        {
            if (!NeighborRosterComplete)
                throw new InvalidOperationException("Cannot allocate a neighbor id because the loaded neighborhood roster has an unknown tail.");
            slot = NeighborWalkOrder.Count;
            NeighborWalkOrder.Add(null);
            id = checked((short)(slot + 1));
        }
        var neighbor = new NeighborState(id, person.Definition.ToArray())
        {
            TypeRecordKey = typeKey,
            FriendEligibilityObjectFlagsB4 = 4u,
        };
        ClearRemovedNeighbor(id);
        Neighbors.Add(id, neighbor);
        NeighborWalkOrder[slot] = neighbor;
        return neighbor;
    }

    private void RandomizeCreatedPersonInterests(XPerson person)
    {
        Randomize([0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37], [4, 3, 3]);
        Randomize([0x0d, 0x0e, 0x10, 0x14, 0x1a], [1, 2, 2]);

        void Randomize(ReadOnlySpan<int> fields, int[] remaining)
        {
            foreach (var field in fields)
            {
                int category;
                do category = (int)(NextRandom() % 3); while (remaining[category] == 0);
                remaining[category]--;
                var value = category switch
                {
                    0 => (int)(NextRandom() & 3),
                    1 => (int)(NextRandom() % 3) + 4,
                    _ => (int)(NextRandom() & 3) + 7,
                };
                person.PersonData[field] = unchecked((short)(value * 100));
            }
        }
    }

    public void InitializeCreatedObjectGroup(IReadOnlyList<XObject> group)
    {
        ArgumentNullException.ThrowIfNull(group);
        if (group.Count < 1) throw new ArgumentException("A created multi-tile group must include at least one member.", nameof(group));
        var root = group[0];
        for (var index = 0; index < group.Count; index++)
        {
            var member = group[index];
            if (!ReferenceEquals(member, ObjectById(member.Id)))
                throw new InvalidOperationException($"Object {member.Id} is not registered in this simulation world.");
            if (index == 0)
            {
                if (member.MultiTileMasterId != 0)
                    throw new InvalidOperationException("A created multi-tile group root cannot name another master.");
            }
            else if (member.MultiTileMasterId != root.Id)
            {
                throw new InvalidOperationException($"Multi-tile member {member.Id} does not name root {root.Id}.");
            }
            var expectedNext = index + 1 < group.Count ? group[index + 1].Id : (short)0;
            if (member.MultiTileNextId != expectedNext)
                throw new InvalidOperationException($"Multi-tile member {member.Id} has an incomplete group link.");
        }

        foreach (var member in group)
        {
            PrepareCreatedObject(member);
            if (member[ObjectData.CurrentValue] == 0 && member.Definition is { Length: > (int)ObjdField.Price } definition)
                member[ObjectData.CurrentValue] = definition[(int)ObjdField.Price];
        }
        foreach (var member in group) InitializeObjectData(member, PreservedInitializerData(member));

        foreach (var member in group) FinishObjectInitializer(member, runTick: true);
        RefreshMultiTileOffsetsAfterRotation(root);

        foreach (var member in group)
        {
            FinishObjectInitializer(member, runTick: true, finishMultiTileMember: true);
            member.Flags |= 0x80u;
            ClockManager.SetTickEnabled(member, true);
        }
        DispatchNotice(0xe2, root.ClockManagerIndex);
    }

    private void PrepareCreatedObject(XObject item)
    {
        SetObjectPosition(item, new ObjectPosition(-16, -16, item.Position.Height));
        item[ObjectData.SlotNumber] = -1;
        item[ObjectData.SlotHierNumber] = -1;
        item[ObjectData.SlotCount] = checked((short)(item.FootprintSlots.Count == 0 &&
            item.Definition is { Length: > (int)ObjdField.SlotsId } slots && slots[(int)ObjdField.SlotsId] == 0
                ? -1 : item.FootprintSlots.Count));
        Array.Clear(item.Attributes);
        if (CurrentDate is { } date)
        {
            item[ObjectData.BirthYear] = date.Year;
            item[ObjectData.BirthMonth] = date.Month;
            item[ObjectData.BirthDay] = date.Day;
        }
        item[ObjectData.BirthHour] = checked((short)Clock.Hour);
        item[ObjectData.BirthMinute] = checked((short)Clock.Minute);
    }

    public bool CanPickUpObject(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        LastPlacementFailureCode = 0;
        LastPlacementBlockingObjectId = 0;
        if (MoveObjects) return true;
        var visited = new HashSet<short>();
        bool CanPickUpTree(XObject root)
        {
            var members = MultiTileMembers(root);
            var lead = members[0];
            foreach (var member in members)
            {
                if (!visited.Add(member.Id)) continue;
                var isPerson = member is XPerson ||
                               member.TypeRecord?.ObjectType == XPerson.PersonType ||
                               (member.Definition is { Length: > (int)ObjdField.Type } &&
                                member.Definition[(int)ObjdField.Type] == XPerson.PersonType);
                if (isPerson || !ReferenceEquals(member, ObjectById(member.Id))) return false;
                if ((member[ObjectData.MovementFlags] & 2) == 0)
                {
                    LastPlacementFailureCode = 0x25;
                    return false;
                }
                if (member[ObjectData.UseCount] >= 1 || (member[ObjectData.Flags] & 0x20) != 0)
                {
                    LastPlacementFailureCode = 0x26;
                    return false;
                }
                if (ReferenceEquals(member, lead))
                {
                    var tileX = member.Position.X >> 4;
                    var tileY = member.Position.Y >> 4;
                    if (tileX >= 0 && tileY >= 0 && tileX < LotGeometry.LotDimension && tileY < LotGeometry.LotDimension &&
                        (LotTileFlags?.InsideLot(tileX, tileY) == false ||
                         (BuildModeType6PlacementFlagsAt(tileX, tileY, 1) & 0x20) != 0))
                    {
                        LastPlacementFailureCode = 0x27;
                        return false;
                    }
                }
                foreach (var child in EnumerateContainedSlotChildren(member))
                    if (!CanPickUpTree(child)) return false;
            }
            return true;
        }
        return CanPickUpTree(item);
    }

    public bool MoveObject(XObject item, ObjectPosition destination, short direction)
    {
        if (!CanPickUpObject(item)) throw new InvalidOperationException("Object cannot be moved");
        var members = MultiTileMembers(item);
        if (members.Count > 1)
        {
            var original = members.ToDictionary(member => member,
                member => (member[ObjectData.Direction], member.SavedMultiTileState));
            var directionFlag = direction switch
            {
                0 => (byte)1,
                2 => (byte)4,
                4 => (byte)16,
                6 => (byte)64,
                _ => throw new ArgumentOutOfRangeException(nameof(direction), "Direction must be 0, 2, 4 or 6."),
            };
            var placed = false;
            try
            {
                var checkStack = TreeRunner.CreateTransientStack(this, item);
                ApplyEditorFacing(item, members, directionFlag);
                if (!CanPlaceObject(item, destination, checkStack: checkStack)) return false;
                foreach (var member in members)
                    RunFunctionToCompletion(member, 10);
                PlaceObject(item, destination, checkStack: checkStack, cursorGroup: MultiTilePlacementCursorGroup.Create(item, members));
                RunEditorUserPlacementCallbacks(members);
                WakeSimulateOnPauseObjects();
                placed = true;
                return true;
            }
            finally
            {
                if (!placed) RestoreEditorFacing(original);
            }
        }
        var origin = item.Position;
        var originalDirection = item[ObjectData.Direction];
        var singleDelta = (direction - originalDirection + 8) & 7;
        BeginObjectRemoval(item, 1);
        item[ObjectData.Direction] = direction;
        RotateContainedSlotChildren(item, singleDelta);
        if (CanPlaceObject(item, destination))
        {
            PlaceObject(item, destination);
            RunEditorUserPlacementCallbacks(members);
            WakeSimulateOnPauseObjects();
            return true;
        }
        item[ObjectData.Direction] = originalDirection;
        if (singleDelta != 0) RotateContainedSlotChildren(item, (8 - singleDelta) & 7);
        PlaceObject(item, origin);
        return false;
    }

    public bool CanSellObject(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        if (MoveObjects) return true;
        if (!CanPickUpObject(item)) return false;
        foreach (var member in MultiTileMembers(item))
        {
            if ((member[ObjectData.MovementFlags] & 8) == 0) return false;
            if (EnumerateContainedSlotChildren(member).Any()) return false;
        }
        return true;
    }

    public short ObjectSaleValue(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        var members = MultiTileMembers(item);
        var master = members.FirstOrDefault() ?? item;
        var broken = members.Any(member => member[ObjectData.RepairState] != 0) || item[ObjectData.RepairState] != 0;
        var value = master[ObjectData.CurrentValue];
        return broken ? (short)(value / 2) : value;
    }

    public int SellObject(XObject item)
    {
        if (!CanSellObject(item)) throw new InvalidOperationException("Object cannot be sold");
        var refund = ObjectSaleValue(item);
        DemolishObject(item, runCleanup: true);
        return refund;
    }

    // BuildModeType: 4 = plants (0%), 1/2/3/5/6 = doors/windows/stairs/fireplaces/columns (80%), others = 100%.
    public static int HandResaleValue(int baseSaleValue, int buildModeType) => buildModeType switch
    {
        4 => 0,
        1 or 2 or 3 or 5 or 6 => (int)(baseSaleValue * 0.8f + 0.5f),
        _ => baseSaleValue,
    };

    public static bool IsInsideLotEdge(XObject target)
    {
        ArgumentNullException.ThrowIfNull(target);
        return TileInsideLotEdge(target);
    }

    public void DemolishObject(XObject item, bool runCleanup = false)
    {
        var doomed = new List<XObject>();
        void Collect(XObject root)
        {
            foreach (var member in MultiTileMembers(root))
            {
                if (doomed.Contains(member)) continue;
                doomed.Add(member);
                foreach (var occupant in EnumerateContainedSlotChildren(member))
                {
                    var isPerson = occupant is XPerson ||
                                   occupant.TypeRecord?.ObjectType == XPerson.PersonType ||
                                   (occupant.Definition is { Length: > (int)ObjdField.Type } &&
                                    occupant.Definition[(int)ObjdField.Type] == XPerson.PersonType);
                    if (!isPerson) Collect(occupant);
                }
            }
        }
        Collect(item);
        var callerLocation = CaptureExecutionLocation();
        if (runCleanup)
        foreach (var member in doomed)
            if (FunctionTreeId(member, 12) is var tree && tree != 0 && member.TypeRecord?.BehaviorScope is { } scope)
                TreeRunner.RunWithParameters(this, member, scope, tree, 0, []);
        RestoreExecutionLocation(callerLocation);
        foreach (var member in doomed) BeginObjectRemoval(member, 1);
        foreach (var member in doomed) KillObject(member.Id);
        WakeSimulateOnPauseObjects();
    }

    private static void RecomputeObjectAge(XObject item, SimulationDate currentDate)
    {
        var years = unchecked((short)(currentDate.Year - item[ObjectData.BirthYear]));
        var months = unchecked((short)(currentDate.Month - item[ObjectData.BirthMonth]));
        if (currentDate.Day < item[ObjectData.BirthDay]) months = unchecked((short)(months - 1));
        if (months < 0)
        {
            months = unchecked((short)(months + 12));
            years = unchecked((short)(years - 1));
        }
        item[ObjectData.SimAge] = years;
        item[ObjectData.AgeInMonths] = unchecked((short)(months + years * 12));
    }

    private void DepreciateObjectForDay(XObject item)
    {
        if (item is XPerson || item.Definition is not { Length: > (int)ObjdField.SelfDepreciating }) return;
        if (item.Definition[(int)ObjdField.Type] == XPerson.PersonType) return;

        short selfDepreciating;
        short price;
        short initial;
        short daily;
        short limit;

        if (item.Definition[(int)ObjdField.MasterId] != 0)
        {
            if (item.RuntimeClass is not null and not SimsEngine.Formats.ObjectClass.MultiTileObject) return;
            var lead = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId) ?? item;
            if (!ReferenceEquals(item, lead)) return;

            var masterEntry = item.TypeRecord?.AlternativeTypeKey is { } altKey
                ? ObjectRegistry?.Find(unchecked((uint)altKey))
                : item.TypeRecord is { Key: var key } && ObjectRegistry?.Find(unchecked((uint)key)) is { } memberEntry
                    ? ObjectRegistry.FindAlternativeType(memberEntry)
                    : null;
            if (masterEntry is not null)
            {
                selfDepreciating = unchecked((short)masterEntry.Definition[ObjdField.SelfDepreciating]);
                price = unchecked((short)masterEntry.Definition[ObjdField.Price]);
                initial = unchecked((short)masterEntry.Definition[ObjdField.InitialDepreciation]);
                daily = unchecked((short)masterEntry.Definition[ObjdField.DailyDepreciation]);
                limit = unchecked((short)masterEntry.Definition[ObjdField.DepreciationLimit]);
            }
            else if (ObjectRegistry is not null)
            {
                return;
            }
            else
            {
                selfDepreciating = item.Definition[(int)ObjdField.SelfDepreciating];
                price = item.TypeRecord?.AlternativeObjectPrice ?? item.Definition[(int)ObjdField.Price];
                initial = item.Definition[(int)ObjdField.InitialDepreciation];
                daily = item.Definition[(int)ObjdField.DailyDepreciation];
                limit = item.Definition[(int)ObjdField.DepreciationLimit];
            }
        }
        else
        {
            selfDepreciating = item.Definition[(int)ObjdField.SelfDepreciating];
            price = item.Definition[(int)ObjdField.Price];
            initial = item.Definition[(int)ObjdField.InitialDepreciation];
            daily = item.Definition[(int)ObjdField.DailyDepreciation];
            limit = item.Definition[(int)ObjdField.DepreciationLimit];
        }

        if (selfDepreciating != 0) return;
        if (price <= 0 && initial == 0 && daily == 0 && limit == 0) return;

        var current = item[ObjectData.CurrentValue];
        var delta = current == price && initial != 0 ? initial : daily;
        current = unchecked((short)(current - delta));
        if (current < limit) current = limit;
        item[ObjectData.CurrentValue] = current;
    }

    public HashSet<uint> ChangedCodeTypeGuids { get; } = [];
    internal Dictionary<short, ObjectTypeEntry> CurrentObjectTypes { get; } = [];

    public void ResetObjectsWithChangedCode()
    {
        var resetIds = new HashSet<short>();
        foreach (var item in WalkOrder.ToArray())
        {
            if (!ReferenceEquals(item, ObjectById(item.Id)) || resetIds.Contains(item.Id)) continue;
            if (item is not XPerson && (item.MultiTileMasterId != 0 || item.MultiTileNextId != 0))
            {
                var lead = item.MultiTileMasterId != 0 ? ObjectById(item.MultiTileMasterId) ?? item : item;
                var group = MultiTileMembers(lead);
                if (group.Count > 1 && group.Any(m => FunctionTreeId(m, 3) == 0))
                {
                    var anyResetTarget = false;
                    foreach (var member in group)
                    {
                        var memberGuid = unchecked((uint)(member.TypeRecord?.Key ?? 0));
                        if (ChangedCodeTypeGuids.Contains(memberGuid) || memberGuid == 0x3C08965F)
                        {
                            anyResetTarget = true;
                            break;
                        }
                    }
                    if (!anyResetTarget) continue;
                    foreach (var member in group)
                    {
                        NotifyPersonObjectReferenceRecipients(member);
                        SavedExecutionStacks.Remove(member.Id);
                    }
                    if (!group.Any(m => (m.Flags & DyingObjectFlag) != 0))
                        ResetObjectAfterScriptError(lead, TreeRunner.CreateTransientStack(this, lead));
                    else
                    {
                        foreach (var member in group)
                        {
                            BeginObjectRemoval(member, 1);
                            member.SavedStack.Clear();
                            member.SavedStackSize = 0;
                            StopObjectSounds(member.Id);
                        }
                    }
                    foreach (var member in group)
                    {
                        resetIds.Add(member.Id);
                        if (member.ClockManagerIndex > 0) ClockManager.SetWaitTicksAt(member.ClockManagerIndex, -1);
                    }
                    continue;
                }
            }

            var guid = unchecked((uint)(item.TypeRecord?.Key ?? 0));
            var changed = ChangedCodeTypeGuids.Contains(guid);
            if (!changed && guid != 0x3C08965F) continue;
            NotifyPersonObjectReferenceRecipients(item);
            SavedExecutionStacks.Remove(item.Id);
            if (item is XPerson person) ResetPersonForChangedCode(person);
            else ResetObjectForChangedCode(item);
            resetIds.Add(item.Id);
            if (item.ClockManagerIndex > 0) ClockManager.SetWaitTicksAt(item.ClockManagerIndex, -1);
            if (changed && (item is XPerson || FunctionTreeId(item, 3) != 0)) RunFunctionToCompletion(item, 0);
        }
        foreach (var (typeIndex, updatedType) in CurrentObjectTypes)
            SavedObjectTypes[typeIndex] = updatedType;
        CurrentObjectTypes.Clear();
        ChangedCodeTypeGuids.Clear();
        RefreshSavedPortalWallStyles();
    }

    public (IReadOnlyList<(string Guid, short ObjectId, string Name, int Refund)> RemovedObjects,
            IReadOnlyList<(string From, string To, short ObjectId)> MigratedObjects,
            int Refund,
            IReadOnlySet<short> ResetEntityIds) ApplyPackObjectMigration(
        Content.ObjectRegistry registry,
        IReadOnlyDictionary<short, (uint From, uint To)> remappedByTypeIndex,
        bool stripMissingObjects)
    {
        var removedObjects = new List<(string Guid, short ObjectId, string Name, int Refund)>();
        var migratedObjects = new List<(string From, string To, short ObjectId)>();
        var resetEntityIds = new HashSet<short>();
        var totalRefund = 0;

        var typeIndexByObjectId = SavedLotObjects?.Objects.ToDictionary(o => o.ObjectId, o => o.TypeIndex) ?? [];

        bool FrameReferencesSubject(short stackObject, short codeOwner, XObject subject)
        {
            if (stackObject == subject.Id || (subject.ClockManagerIndex > 0 && stackObject == subject.ClockManagerIndex))
                return true;
            return typeIndexByObjectId.TryGetValue(subject.Id, out var subjTi) && subjTi != 0 && codeOwner == subjTi;
        }

        bool PersonReferencesObject(XPerson person, XObject subject)
        {
            if (person.SavedPersonObjectReferences.Any(r => ReferenceEquals(r.Target, subject)) ||
                ReferenceEquals(person.GenericSimsCall02ObjectA54, subject) ||
                ReferenceEquals(person.CurrentActionRecord?.Owner, subject) ||
                ReferenceEquals(person.CurrentActionRecord?.Secondary, subject) ||
                person.NativeRoute?.AnchorObjectId == subject.Id ||
                person.NativeRouteParents.Any(r => r.AnchorObjectId == subject.Id) ||
                person.SavedStack.Any(f => FrameReferencesSubject(f.StackObject, f.CodeOwner, subject)))
                return true;
            var count = unchecked(person.ActionQueueEnd - person.ActionQueueCurrent);
            if (count is > 0 and <= 8)
            {
                for (var i = 0; i < count; i++)
                {
                    var slot = person.ActionQueue[(person.ActionQueueCurrent + i) & 7];
                    if (ReferenceEquals(slot.Owner, subject) || ReferenceEquals(slot.Secondary, subject))
                        return true;
                }
            }
            return SavedExecutionStacks.TryGetValue(person.Id, out var stack) &&
                   stack.Frames.Any(f => FrameReferencesSubject(f.StackObject, f.CodeOwner, subject));
        }

        void ResetReferencingEntities(XObject subject, HashSet<short>? excludedIds = null)
        {
            foreach (var other in WalkOrder.ToArray())
            {
                if (ReferenceEquals(other, subject) || (excludedIds is not null && excludedIds.Contains(other.Id))) continue;
                if (other is XPerson person)
                {
                    if (person[ObjectData.ParentId] == subject.Id ||
                        (subject.ClockManagerIndex > 0 && person[ObjectData.ParentId] == subject.ClockManagerIndex))
                    {
                        person[ObjectData.ParentId] = 0;
                        person[ObjectData.SlotHierNumber] = -1;
                        resetEntityIds.Add(person.Id);
                    }
                    if (PersonReferencesObject(person, subject))
                    {
                        ResetPersonForChangedCode(person);
                        RemoveQueuedActionsReferencing(person, subject);
                        person.CurrentActionRecord = ActionQueueSlot.EmptyRecord();
                        person.ActionQueueCurrent = 0;
                        person.ActionQueueEnd = 0;
                        Array.Clear(person.ActionQueue);
                        if (person.ClockManagerIndex > 0) ClockManager.SetWaitTicksAt(person.ClockManagerIndex, -1);
                        resetEntityIds.Add(person.Id);
                    }
                }
                else if (other[ObjectData.ParentId] == subject.Id ||
                         (subject.ClockManagerIndex > 0 && other[ObjectData.ParentId] == subject.ClockManagerIndex) ||
                         other.SavedStack.Any(f => FrameReferencesSubject(f.StackObject, f.CodeOwner, subject)) ||
                         (SavedExecutionStacks.TryGetValue(other.Id, out var oStack) &&
                          oStack.Frames.Any(f => FrameReferencesSubject(f.StackObject, f.CodeOwner, subject))))
                {
                    ResetObjectForChangedCode(other);
                    if (other.ClockManagerIndex > 0) ClockManager.SetWaitTicksAt(other.ClockManagerIndex, -1);
                    resetEntityIds.Add(other.Id);
                }
            }
        }

        if (remappedByTypeIndex.Count > 0)
        {
            foreach (var item in WalkOrder.ToArray())
            {
                if (!typeIndexByObjectId.TryGetValue(item.Id, out var typeIndex) ||
                    !remappedByTypeIndex.TryGetValue(typeIndex, out var remap)) continue;
                ChangedCodeTypeGuids.Add(remap.To);
                if (item.MultiTileMasterId == 0)
                    migratedObjects.Add(($"0x{remap.From:X8}", $"0x{remap.To:X8}", item.Id));
                resetEntityIds.Add(item.Id);
                ResetReferencingEntities(item);
            }
        }

        if (stripMissingObjects)
        {
            var handledIds = new HashSet<short>();
            foreach (var item in WalkOrder.ToArray())
            {
                if (item is XPerson || handledIds.Contains(item.Id)) continue;
                var guid = unchecked((uint)(item.TypeRecord?.Key ?? 0));
                if (guid == 0 || registry.Find(guid) is not null) continue;
                var lead = item.MultiTileMasterId != 0 && ObjectById(item.MultiTileMasterId) is { } master ? master : item;
                if (handledIds.Contains(lead.Id)) continue;
                var group = WalkOrder
                    .Where(o => o is not XPerson && (o.Id == lead.Id || o.MultiTileMasterId == lead.Id))
                    .ToList();
                var groupIds = group.Select(o => o.Id).ToHashSet();
                var addedChild = true;
                while (addedChild)
                {
                    addedChild = false;
                    foreach (var o in WalkOrder)
                    {
                        if (o is not XPerson && !groupIds.Contains(o.Id) && groupIds.Contains(o[ObjectData.ParentId]))
                        {
                            group.Add(o);
                            groupIds.Add(o.Id);
                            addedChild = true;
                        }
                    }
                }
                foreach (var id in groupIds) handledIds.Add(id);
                var refund = group.Sum(part => Math.Max(0, (int)part[ObjectData.CurrentValue]));
                var leadGuid = unchecked((uint)(lead.TypeRecord?.Key ?? 0));
                var leadName = typeIndexByObjectId.TryGetValue(lead.Id, out var ti) &&
                               SavedObjectTypes.TryGetValue(ti, out var savedType) &&
                               !string.IsNullOrWhiteSpace(savedType.Name)
                    ? savedType.Name
                    : lead.TypeRecord?.Name ?? $"0x{leadGuid:X8}";
                removedObjects.Add(($"0x{leadGuid:X8}", lead.Id, leadName, refund));
                totalRefund += refund;

                foreach (var part in group)
                    ResetReferencingEntities(part, groupIds);
                foreach (var part in group)
                {
                    NotifyPersonObjectReferenceRecipients(part);
                    HierSever(part);
                    Remove(part.Id);
                }
            }

            foreach (var pair in SavedObjectTypes.ToArray())
            {
                var ti = pair.Key;
                var savedType = pair.Value;
                if (registry.Find(savedType.Guid) is null &&
                    !WalkOrder.Any(o => unchecked((uint)(o.TypeRecord?.Key ?? 0)) == savedType.Guid))
                {
                    SavedObjectTypes.Remove(ti);
                    CurrentObjectTypes.Remove(ti);
                    CodeOwnerTypeGuids.Remove(ti);
                    CodeOwnerScopes.Remove(ti);
                }
            }
        }

        return (removedObjects, migratedObjects, totalRefund, resetEntityIds);
    }

    public void NotifyPersonObjectReferenceRecipients(XObject subject)
    {
        ArgumentNullException.ThrowIfNull(subject);
        for (var index = 0; index < WalkOrder.Count; index++)
        {
            if (WalkOrder[index] is not XPerson person || ReferenceEquals(person, subject)) continue;
            if (!person.TryBeginObjectReferenceNotification()) continue;
            var prefix = index > 0 ? WalkOrder.Take(index).ToArray() : [];
            try
            {
                if (person.SavedPersonObjectReferences.Any(reference => ReferenceEquals(reference.Target, subject)) ||
                    ReferenceEquals(person.GenericSimsCall02ObjectA54, subject))
                {
                    ResetPersonForChangedCode(person, notificationGuardHeld: true, subject: subject);
                }
                RemoveQueuedActionsReferencing(person, subject);
                ApplyPersonObjectReferenceActionChanges(person, subject);
                person.InvalidateRuntimeObjectReferences(subject);
                Host?.NotifyPersonObjectReference(person, subject);
            }
            finally
            {
                person.EndObjectReferenceNotification();
                if (index >= WalkOrder.Count || !ReferenceEquals(WalkOrder[index], person))
                {
                    var moved = -1;
                    for (var probe = Math.Min(index, WalkOrder.Count - 1); probe >= 0; probe--)
                    {
                        if (ReferenceEquals(WalkOrder[probe], person))
                        {
                            moved = probe;
                            break;
                        }
                    }
                    index = moved >= 0 ? moved : prefix.Count(item => WalkOrder.Contains(item)) - 1;
                }
            }
        }
    }

    public void HierSever(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        var directParent = ObjectTableEntry(item[ObjectData.ParentId]) ?? ObjectById(item[ObjectData.ParentId]);
        var directSlot = item[ObjectData.SlotHierNumber];
        if (directParent is not null)
        {
            if (directSlot >= 0 && directSlot < directParent.Slots.Count)
            {
                if (directParent.Slots[directSlot] == item.ClockManagerIndex || directParent.Slots[directSlot] == item.Id)
                    directParent.Slots[directSlot] = 0;
                if (directSlot > 0 && directSlot - 1 < directParent.FootprintSlots.Count &&
                    (directParent.FootprintSlots[directSlot - 1].OccupantObjectId == item.ClockManagerIndex ||
                     directParent.FootprintSlots[directSlot - 1].OccupantObjectId == item.Id))
                    directParent.FootprintSlots[directSlot - 1].OccupantObjectId = 0;
            }
            for (var i = 0; i < directParent.Slots.Count; i++)
            {
                if (directParent.Slots[i] == item.ClockManagerIndex || directParent.Slots[i] == item.Id)
                    directParent.Slots[i] = 0;
            }
        }
        item[ObjectData.ParentId] = 0;
        item[ObjectData.ContainerId] = 0;
        item[ObjectData.SlotNumber] = 0;
        item[ObjectData.SlotHierNumber] = -1;

        foreach (var child in WalkOrder)
        {
            if (child[ObjectData.ParentId] == item.Id || child[ObjectData.ParentId] == item.ClockManagerIndex)
            {
                child[ObjectData.ParentId] = 0;
                child[ObjectData.ContainerId] = 0;
                child[ObjectData.SlotNumber] = 0;
                child[ObjectData.SlotHierNumber] = -1;
            }
        }
        for (var i = 0; i < item.Slots.Count; i++) item.Slots[i] = 0;
        for (var i = 0; i < item.FootprintSlots.Count; i++) item.FootprintSlots[i].OccupantObjectId = 0;
    }

    public void ResetObjectForChangedCode(XObject item)
    {
        if (item is XPerson person)
        {
            ResetPersonForChangedCode(person);
            return;
        }
        SavedExecutionStacks.Remove(item.Id);
        if (FunctionTreeId(item, 3) == 0)
        {
            if ((item.Flags & DyingObjectFlag) != 0)
            {
                BeginObjectRemoval(item, 1);
                item.SavedStack.Clear();
                item.SavedStackSize = 0;
                StopObjectSounds(item.Id);
                return;
            }
            ResetObjectAfterScriptError(item, TreeRunner.CreateTransientStack(this, item));
            StopObjectSounds(item.Id);
            return;
        }
        RunFunctionToCompletion(item, 3);
        item[ObjectData.Flags] = unchecked((short)(item[ObjectData.Flags] & ~0x20));
        item[ObjectData.UseCount] = 0;
        item.SavedStack.Clear();
        item.SavedStackSize = 0;
        RunObjectResetInitializer(item);
        StopObjectSounds(item.Id);
    }

    private void ResetPersonForChangedCode(XPerson person, bool notificationGuardHeld = false, XObject? subject = null)
    {
        if (!notificationGuardHeld && !person.TryBeginObjectReferenceNotification()) return;
        try
        {
            SavedExecutionStacks.Remove(person.Id);
            InteractionLifecycle.FinalizeActor(person);
            var flagSource = subject ?? person;
            while (person.SavedPersonObjectReferences.Count > 0)
            {
                var lastReference = person.SavedPersonObjectReferences[^1];
                PersonInteractionStack.Release(person, lastReference.Value - 1);
                if ((flagSource.Flags & 0x00001000u) != 0 || lastReference.Target is not { } target) continue;

                NotifyPersonObjectReferenceRecipients(target);
                if (target is XPerson targetPerson) ResetPersonForChangedCode(targetPerson);
                else ResetObjectForChangedCode(target);
            }
            person[global::SimsEngine.Simulation.PersonData.CensorshipFlags] = 0;
            ResetPersonAnimatorForChangedCode(person);
            StopObjectSounds(person.Id);
            person.RuntimeObjectReferences.Clear();
            foreach (var reference in person.RuntimeStateRecords)
            {
                reference.Target = null;
                reference.RawWord28 = 0;
            }
            ResetPersonPlacementAfterChangedCode(person);
            person.SavedStack.Clear();
            person.SavedStackSize = 0;
            RunObjectResetInitializer(person);
            RunFunctionToCompletion(person, 3);
            person[global::SimsEngine.Simulation.PersonData.Sitting] = 0;
            person[global::SimsEngine.Simulation.PersonData.WalkingUpStairs] = 0;
            person[global::SimsEngine.Simulation.PersonData.ObjectSocialObjectID] = 0;
            person[ObjectData.Hidden] = 0;
            person[ObjectData.RoutePreference] = 0;
            ApplyStartedInteractionAction(person, ActionQueueSlot.EmptyRecord());
            if (!notificationGuardHeld) person.ActionQueueCurrent = person.ActionQueueEnd = 0;
        }
        finally
        {
            if (!notificationGuardHeld) person.EndObjectReferenceNotification();
        }
    }

    private void ResetPersonPlacementAfterChangedCode(XPerson person)
    {
        var (holder, _) = PlacementSpec(person);
        var stack = TreeRunner.CreateTransientStack(this, person);
        if (holder is not null)
        {
            BeginObjectRemoval(person, 1);
            var detachedPosition = person.Position;
            var holderCandidate = detachedPosition;
            if (!CanPlaceObject(person, detachedPosition, stack))
            {
                var holderParams = new FindLocationParams
                {
                    UseCenter = true,
                    CenterX = detachedPosition.X,
                    CenterY = detachedPosition.Y,
                    Height = detachedPosition.Height,
                    Direction = -1,
                    ContinueFlag = 1,
                    FlagB = 1,
                };
                if (FindLocation(person, holderParams, out var found, stack))
                {
                    holderCandidate = new ObjectPosition(found.X, found.Y, detachedPosition.Height);
                }
                else
                {
                    holderParams.ContinueFlag = 0;
                    if (FindLocation(person, holderParams, out found, stack))
                        holderCandidate = new ObjectPosition(found.X, found.Y, detachedPosition.Height);
                }

            }

            PlaceObject(person, holderCandidate, stack);
            RefreshPersonPlacementCallbacksAfterMovement(person);
        }

        var position = person.Position;
        var size = LotGeometry.LotDimension;
        var tileX = position.X >> 4;
        var tileY = position.Y >> 4;
        var positionInsideLot = tileX > 0 && tileY > 0 && tileX < size - 1 && tileY < size - 1;
        if ((person.Flags & DyingObjectFlag) != 0 || positionInsideLot) return;

        BeginObjectRemoval(person, 1);
        var center = size / 2 * 16 + 8;
        var candidate = new ObjectPosition(center, center, person.Position.Height);
        if (!CanPlaceObject(person, candidate, stack))
        {
            var parameters = new FindLocationParams
            {
                UseCenter = true,
                CenterX = candidate.X,
                CenterY = candidate.Y,
                Height = person.Position.Height,
                Direction = -1,
                ContinueFlag = 1,
                FlagB = 1,
            };
            for (var attempt = 0; attempt < 2; attempt++)
            {
                if (FindLocation(person, parameters, out var found, stack))
                {
                    candidate = new ObjectPosition(found.X, found.Y, person.Position.Height);
                    break;
                }
                parameters.ContinueFlag = 0;
            }
        }

        PlaceObject(person, candidate, stack);
        RefreshPersonPlacementCallbacksAfterMovement(person);
    }

    private void ResetPersonAnimatorForChangedCode(XPerson person)
    {
        StopObjectSounds(person.Id);
        person.NativeRoute = null;
        person.NativeRouteParents.Clear();
        InvalidateAnimatorRootGrid(person);
        person.SetAnimatorDisplacements(0f, 0f, 0f);
        person.AnimationPlayback = null;
        person.LastAnimationPlayback = null;
        person.AnimatorDiscontinuityPending = true;
        person.AnimatorAnchorBone = null;
        person.AnimatorAnchorInitialized = false;
        person.AnimatorAnchorWorldPosition = Vector3.Zero;
        person.PrimaryAnimationWaiting = false;
        person.PrimaryAnimationEventsRun = 0;
        person.PrimaryAnimationBackwards = false;
        person.BackgroundAnimationPlayback = null;
        person.CarryAnimationPlayback = null;
        person.PendingAnimationEvents.Clear();
        person.BackgroundPracticePersonState = -1;
        person.CarryPracticeMode = 0;
        person.CarryPracticeCachedState = -1;
        person.AnimatorControlState = 3;
        person.AnimatorRouteTransitionState = 0;
        person.AnimatorPoolTransitionState = 0;
        person.AnimatorGaitEntryState = 0;
        person.AnimatorLocomotionFadeGate = 0;
        person.AnimatorStateTailField198 = 1;
        person.PresentationCharacter = null;
        person.ClearExtraParts();
        person[global::SimsEngine.Simulation.PersonData.HandGestureLeft] = 0;
        person[global::SimsEngine.Simulation.PersonData.HandGestureRight] = 0;
        person.NativeOutfitTransitionActive = false;
        if (person.TypeRecord?.AnimatorBodyStringMode is { } bodyStringMode)
            person.AnimatorBodyStringMode = bodyStringMode;
    }

    public void RunFunctionToCompletion(XObject item, short function, short stackObject = 0)
    {
        if (FunctionTreeId(item, function) is not (var tree and not 0) || item.TypeRecord?.BehaviorScope is not { } scope)
            return;
        var callerLocation = CaptureExecutionLocation();
        TreeRunner.RunWithParameters(this, item, scope, tree, stackObject, []);
        RestoreExecutionLocation(callerLocation);
    }

    private void RunObjectResetInitializer(XObject item)
    {
        var type = item.TypeRecord;
        if (type?.FunctionTable is not { Count: > 1 } functions || type.BehaviorScope is not { } scope) return;
        var tree = functions[1];
        if (tree == 0) return;

        var codeOwner = CodeOwnerTypeGuids.FirstOrDefault(entry => entry.Value == unchecked((uint)type.Key));
        if (!CodeOwnerTypeGuids.ContainsKey(codeOwner.Key) || codeOwner.Value != unchecked((uint)type.Key)) return;
        var stack = TreeRunner.StartObjectTree(this, item, scope, unchecked((short)tree), 0, codeOwner.Key,
            [0, 0, 0, 0]);
        if (stack is null) return;
        SavedExecutionStacks[item.Id] = stack;
        TreeRunner.SaveFrames(item, stack);
    }

    public short ResolveCodeOwner(XObject? codeOwnerObject, ITreeTable? scope = null)
    {
        if (codeOwnerObject?.TypeRecord is { Key: var key })
        {
            var expectedGuid = unchecked((uint)key);
            foreach (var entry in CodeOwnerTypeGuids)
                if (entry.Value == expectedGuid)
                    return entry.Key;
        }

        if (scope is not null)
        {
            foreach (var entry in CodeOwnerScopes)
                if (ReferenceEquals(entry.Value, scope))
                    return entry.Key;
        }

        return 0;
    }

    public void RequestDisplayRefresh()
    {
        DisplayRefreshRequested = true;
        Host?.RefreshDisplay();
    }

    public XObject? ObjectTableEntry(short index) =>
        index > 0 && index <= _objectTableEntries.Count ? _objectTableEntries[index - 1] : null;

    public (XObject? Holder, int Value) PlacementSpec(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        var visited = new HashSet<short> { item.Id };
        while (item[ObjectData.SlotHierNumber] == 0)
        {
            var parent = ObjectTableEntry(item[ObjectData.ParentId]);
            if (parent is null || !visited.Add(parent.Id)) break;
            item = parent;
        }
        var holder = ObjectTableEntry(item[ObjectData.ParentId]);
        int value = item[ObjectData.SlotHierNumber];
        if (value != -1)
        {
            value--;
            if (value == -1) item[ObjectData.SlotHierNumber] = -1;
        }
        return (holder, value);
    }

    public float SlotHeight(XObject holder, int slot)
    {
        ArgumentNullException.ThrowIfNull(holder);
        if (slot < 0 || slot >= holder.FootprintSlots.Count) return 0f;
        var total = 0f;
        XObject? current = holder;
        var visited = new HashSet<short>();
        while (current is not null && visited.Add(current.Id))
        {
            if (slot >= 0 && slot < current.FootprintSlots.Count) total += current.FootprintSlots[slot].Height;
            var (next, nextSlot) = PlacementSpec(current);
            current = next;
            slot = (short)nextSlot;
        }
        return total;
    }

    public Dictionary<(bool Child, int Index), AvatarAnimationClip> ReachAvatarAnimationTable { get; } = [];

    public IReadOnlyList<XObject> RemovalGroupParents(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        var parents = new List<XObject>();
        var current = item;
        var visited = new HashSet<short> { item.Id };
        while (current[ObjectData.SlotHierNumber] == 0)
        {
            var parent = ObjectTableEntry(current[ObjectData.ParentId]);
            if (parent is null || !visited.Add(parent.Id)) break;
            parents.Add(parent);
            current = parent;
        }
        return parents;
    }

    public int ActivePersonIndex(int position)
    {
        if (!ActivePersonManagerPresent || position < 0 || position >= ActivePersonRecordKeys.Count) return -1;
        var key = ActivePersonRecordKeys[position];
        return PersonRecordKeys.IndexOf(key);
    }

    public static short FunctionTreeId(XObject item, short function)
    {
        ArgumentNullException.ThrowIfNull(item);
        var functions = item.TypeRecord?.FunctionTable;
        if (function < 0 || functions is null || function >= functions.Count) return 0;
        return unchecked((short)functions[function]);
    }

    public static (short Tree, short Check) FunctionEntry(XObject item, short function)
    {
        ArgumentNullException.ThrowIfNull(item);
        var tree = FunctionTreeId(item, function);
        var checks = item.TypeRecord?.FunctionCheckTable;
        var check = function >= 0 && checks is not null && function < checks.Count
            ? unchecked((short)checks[function])
            : (short)0;
        return (tree, check);
    }

    public static bool HasFunction(XObject item, short function) => FunctionTreeId(item, function) != 0;

    public int ActivePersonCount => ActivePersonManagerPresent ? ActivePersonRecordKeys.Count : 0;

    public XPerson? ActivePersonAt(int position)
    {
        var index = ActivePersonIndex(position);
        if (index < 0 || index >= PersonRecordKeys.Count) return null;
        var key = PersonRecordKeys[index];
        if (key == 0) return null;
        return WalkOrder.FirstOrDefault(item => item.TypeRecord?.Key == key) as XPerson;
    }

    public XPerson? ResolveOrCreateActivePerson(int position)
    {
        if (!ActivePersonManagerPresent || position < 0 || position >= ActivePersonRecordKeys.Count) return null;
        if (ActivePersonAt(position) is { } existing) return existing;
        var key = ActivePersonRecordKeys[position];
        if (key == 0 || ActivePersonIndex(position) < 0 || ScopedNeighborPersonRecordId(key) is null) return null;
        return WalkOrder.OfType<XPerson>().FirstOrDefault(person => person.TypeRecord?.Key == key);
    }

    public InteractionScopeTable InteractionExecutorScope(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        if (InteractionScopes.TryGetValue(item.InteractionScopeKey5CA, out var scope))
            return scope;
        scope = item is XPerson person && person[PersonData.NeighborId] is > 0 and var neighborId
            ? new InteractionScopeTable(() => NeighborInventory(neighborId))
            : new InteractionScopeTable([]);
        InteractionScopes[item.InteractionScopeKey5CA] = scope;
        return scope;
    }
}
