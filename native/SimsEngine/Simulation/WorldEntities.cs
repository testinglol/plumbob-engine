using SimsEngine.Formats;
using SimsEngine.Content;
using SimsEngine.Character;
using System.Numerics;

namespace SimsEngine.Simulation;

public readonly record struct ObjectPosition(int X, int Y, int Height);
public readonly record struct EditorPlacementTile(int X, int Y, int Level);
public sealed record EditorPlacementResult(bool Valid, string Status, IReadOnlyList<EditorPlacementTile> Tiles, XObject? ReferenceObject = null, int ReferenceSlot = -1);

public sealed class MultiTilePlacementCursorGroup
{
    internal sealed record CursorMember(XObject Source, short MasterId, XObject? AssociatedObject, bool Error15Gate);

    private readonly Dictionary<short, CursorMember> _members;
    internal short LeadSourceId { get; }

    private MultiTilePlacementCursorGroup(short leadSourceId, IEnumerable<CursorMember> members)
    {
        LeadSourceId = leadSourceId;
        _members = members.ToDictionary(member => member.Source.Id);
    }

    internal bool HasError15Gate(XObject member) => _members.TryGetValue(member.Id, out var cursor) && cursor.Error15Gate;
    internal XObject? AssociatedObjectFor(XObject member) =>
        _members.TryGetValue(member.Id, out var cursor) ? cursor.AssociatedObject : null;

    internal static MultiTilePlacementCursorGroup Create(XObject requested, IReadOnlyList<XObject> sourceMembers)
    {
        var lead = requested.MultiTileMasterId == 0
            ? requested
            : sourceMembers.FirstOrDefault(member => member.Id == requested.MultiTileMasterId) ?? requested;
        return new MultiTilePlacementCursorGroup(lead.Id, sourceMembers.Select(member => new CursorMember(
            member,
            member.MultiTileMasterId,
            member.MultiTileMoveAssociatedObject,
            member.RuntimeClass == Formats.ObjectClass.MultiTileObject)));
    }
}

public readonly record struct PortalWallRefreshCoordinate(byte First, byte Second, byte Level);

// Dialog primitive state: 0 = waiting, 2..4 = completion response, 5 = dismissal.
public sealed class SimulationDialogRecord(string token, XObject owner, XObject? icon, byte kind, string title, string message,
    string? yes, string? no, string? cancel, bool blocking = true, bool awaitsResponse = true)
{
    public string Token { get; } = token;
    public XObject Owner { get; } = owner;
    public XObject? Icon { get; } = icon;
    public byte Kind { get; } = kind;
    public string Title { get; } = title;
    public string Message { get; } = message;
    public string? Yes { get; } = yes;
    public string? No { get; } = no;
    public string? Cancel { get; } = cancel;
    public string? ResponseText { get; internal set; }
    public bool Blocking { get; } = blocking;
    public bool AwaitsResponse { get; } = awaitsResponse;
    public int State { get; set; }
    public bool Visible { get; set; } = true;
    public IReadOnlyList<SimulationBookAvailability>? BookAvailability { get; internal set; }
    // 0 = child spellbook, 1 = adult spellbook, 2 = cookbook.
    public byte? BookMode { get; set; }
    public bool? HideBookItem9 { get; internal set; }
    public bool? HideBookItem4 { get; internal set; }
    public Formats.IffFile? ImageFile { get; set; }
    public ushort ImageBitmapId { get; set; }
}

public readonly record struct SimulationBookAvailability(short ContextItemId, short ItemId, bool Made);

public sealed class AssociatedPlacementHelper
{
    public XObject? Owner { get; internal set; }
    public float Value80 { get; private set; }
    public float Value84 { get; private set; }
    public float Value88 { get; private set; }
    public bool FlagD9 { get; private set; }

    internal void Initialize(XObject owner) => Owner = owner;

    internal void RefreshAfterMove()
    {
        Value80 = 0;
        Value84 = 0;
        Value88 = 0;
        FlagD9 = true;
    }
}

public sealed class GenericSimsCallRecordTarget
{
    public IReadOnlyList<int> FameStarThresholds { get; init; } = [];
    // Ordered by skill: cooking, mechanical, charisma, body, logic, creativity.
    public IReadOnlyList<IReadOnlyList<int>> FameSkillThresholds { get; init; } = [];
    public IReadOnlyList<int> FameFriendThresholds { get; init; } = [];

    public static GenericSimsCallRecordTarget FromFameTuning(FameTuning tuning)
    {
        ArgumentNullException.ThrowIfNull(tuning);
        return new GenericSimsCallRecordTarget
        {
            FameStarThresholds = tuning.FameStarThresholds,
            FameSkillThresholds = tuning.FameSkillThresholds,
            FameFriendThresholds = tuning.FameFriendThresholds,
        };
    }
}

public sealed record FamePromotionCandidate(short[] PersonData, short CurrentStarPower, int FriendPowerThreshold);

public sealed record ObjectCreationDiagnostic(short SourceObjectId, short CreatedObjectId, int GuidKey, byte Mode, byte Flags, string? Location,
    ObjectPosition? RequestedPosition = null, short RelativeObjectId = 0, bool? PlacementAccepted = null);
public sealed record ObjectRemovalDiagnostic(short SourceObjectId, short SelectedObjectId, short EffectiveTargetId, string? Location);

public readonly record struct FootprintBounds(int MaxX, int MaxY, int MinX, int MinY);

public readonly record struct LotCoordinateBounds(int MinX, int MaxX, int MinY, int MaxY);

public sealed class ObjectFootprintSlot
{
    public float X { get; init; }
    public float Y { get; init; }
    public float Height { get; init; }
    public short OccupantObjectId { get; set; }
    public int HeightCode { get; init; }
    public int Standing { get; init; }
    public int Sitting { get; init; }

    public static ObjectFootprintSlot FromDefinition(Formats.Slot slot)
    {
        ArgumentNullException.ThrowIfNull(slot);
        if (slot.Type != 0) throw new ArgumentException("Only type-0 SLOT entries build cXObject footprint slots.", nameof(slot));
        var height = slot.Z;
        var heightCode = slot.Height != 0 ? slot.Height : slot.Ground;
        switch (heightCode)
        {
            case 0:
                heightCode = height == 0f ? 1 : 5;
                break;
            case 1:
                height = 0f;
                break;
            case 2:
                height = 2.5f;
                break;
            case 3:
            case 8:
                height = 4f;
                break;
            case 4:
                height = 4.05f;
                break;
        }

        return new ObjectFootprintSlot
        {
            X = slot.X,
            Y = slot.Y,
            Height = height,
            HeightCode = heightCode,
            Standing = slot.MaxSize != 0 ? slot.MaxSize : slot.Standing,
            Sitting = slot.Reserved14 != 0 ? slot.Reserved14 : slot.Sitting,
        };
    }
}

public class XObject(short id, short[] definition, int attributes = 0)
{
    public const int DataCount = 0x48;
    public const int DefinitionCount = 0x6c;

    public short Id { get; } = id;
    public Formats.ObjectClass? RuntimeClass { get; set; }
    public short ClockManagerIndex { get; internal set; }
    public short[] Definition { get; } = definition.Length == DefinitionCount ? definition : throw new ArgumentException($"A definition has {DefinitionCount} fields.", nameof(definition));
    public short[] Attributes { get; set; } = new short[attributes];
    public short[] Temporaries { get; } = new short[8];
    public short[] Data { get; } = CreateData();
    public string? Name { get; set; }
    public List<short> MyList { get; } = [];
    public bool PositionRefreshPending { get; internal set; }
    public const float UnallocatedPortalRouteCost = 0f;

    public const float UninitializedPortalRouteCost = 10001f;
    public Dictionary<short, float> PortalRouteCosts { get; } = [];

    public float PortalRouteCostAt(short routeId) =>
        routeId > 0 && PortalRouteCosts.TryGetValue(routeId, out var cost) ? cost : UnallocatedPortalRouteCost;

    public void SetPortalRouteCost(short routeId, float cost)
    {
        if (routeId <= 0) throw new ArgumentOutOfRangeException(nameof(routeId));
        for (short index = 1; index <= routeId; index++)
            if (!PortalRouteCosts.ContainsKey(index)) PortalRouteCosts[index] = UninitializedPortalRouteCost;
        PortalRouteCosts[routeId] = cost;
    }

    internal void ResetAllocatedPortalRouteCosts()
    {
        foreach (var routeId in PortalRouteCosts.Keys.ToArray())
            PortalRouteCosts[routeId] = UninitializedPortalRouteCost;
    }

    private static short[] CreateData()
    {
        var data = new short[DataCount];
        data[(int)ObjectData.Room] = -5;
        data[(int)ObjectData.RotationNotches] = 2;
        return data;
    }

    public short SleepGateWord7C
    {
        get => Data[(int)ObjectData.LockoutCount];
        set => Data[(int)ObjectData.LockoutCount] = value;
    }
    public short StateValue { get; set; }
    public virtual short SelectionWord5CC { get; set; }
    public virtual short SelectionWord606 { get; set; }
    public int TableWord10C { get; set; }
    public bool LotUpkeepGateByte14C { get; set; }
    public bool LotUpkeepPointer128Present { get; set; }
    public short[] LotUpkeepMinimumResources { get; } = new short[6];
    public int GenericSimsCall1BRawWord13C { get; set; }
    public XPerson? StoredPersonPointer10C { get; set; }
    public short RoomWord84 { get => Data[(int)ObjectData.Room]; set => Data[(int)ObjectData.Room] = value; }
    public short RoomChangeNoticeGateWord58 { get; set; }
    public short RemovalCallbackWord14 { get; set; }
    public int ObjectValueWord118 { get; set; }
    public int ObjectValueWord11C { get; set; }
    public int NeighborTableWord08 { get; set; }
    public short NeighborInteractionTargetWordEE { get; set; }
    public short NeighborInteractionWordF6 { get; set; }
    public int NeighborInteractionCountWord120 { get; set; }
    public short NeighborInteractionWordFA { get; set; }
    public short NeighborInteractionWord612 { get; set; }
    public uint NeighborInteractionFlagsWord138 { get; set; }
    public byte NeighborInteractionStateByte124 { get; set; }
    private readonly List<XObject> _neighborSubobjectReferences = [];
    public IReadOnlyList<XObject> NeighborSubobjectReferences => _neighborSubobjectReferences;

    public bool HasNeighborSubobjectReference(XObject neighbor) =>
        _neighborSubobjectReferences.Any(candidate => ReferenceEquals(candidate, neighbor));

    public bool AddNeighborSubobjectReference(XObject neighbor)
    {
        if (HasNeighborSubobjectReference(neighbor)) return false;
        _neighborSubobjectReferences.Add(neighbor);
        return true;
    }

    public bool RemoveNeighborSubobjectReference(XObject neighbor)
    {
        var index = _neighborSubobjectReferences.FindIndex(candidate => ReferenceEquals(candidate, neighbor));
        if (index < 0) return false;
        _neighborSubobjectReferences.RemoveAt(index);
        return true;
    }
    private List<XObject?> _objectTableEntries = [];
    public List<XObject?> ObjectTableEntries => _objectTableEntries;
    public Dictionary<short, short> ObjectTableEffectWords { get; } = [];
    public FootprintBounds FootprintBounds { get; set; }
    public short? FootprintBoundsDirection { get; internal set; }
    public List<XObject> LotListEntries { get; } = [];
    public uint Flags { get; set; }
    public bool PrepareClockSpecialUpdate()
    {
        if ((Flags & 0x00010000u) == 0) return false;
        Flags &= ~0x00000100u;
        return true;
    }
    public List<ObjectStackFrame> SavedStack { get; } = [];
    public int SavedStackSize { get; set; }
    public MultiTileState? SavedMultiTileState { get; set; }
    public ObjectPosition? MultiTileMovePositionState { get; internal set; }
    public short MultiTileMoveFlag1B0 { get; internal set; }
    public short MultiTileMoveValue1C4 { get; internal set; }
    public short MultiTileMoveValue1C6 { get; internal set; }
    public AssociatedPlacementHelper? AssociatedPlacementHelper { get; internal set; }
    public bool AssociatedPlacementExtensionFlag180 { get; internal set; }
    public XObject? MultiTileMoveAssociatedObject { get; set; }
    public float MultiTileMoveValue1C0 { get; internal set; }
    public short MultiTileMasterId { get; set; }
    public short InteractionScopeKey5CA { get; set; }
    public short MultiTileNextId { get; set; }
    private short _requestKey;
    public short RequestKey
    {
        get => _requestKey;
        set
        {
            _requestKey = value;
            HasRequestKey = true;
        }
    }
    public bool HasRequestKey { get; private set; }
    public short StackObjectKey => HasRequestKey ? RequestKey : Id;
    public XObject? ObjectTableEntry(short index) =>
        index > 0 && index <= ObjectTableEntries.Count ? ObjectTableEntries[index - 1] : null;

    public void SetObjectTableEntry(short index, XObject? item)
    {
        if (index < 1) throw new ArgumentOutOfRangeException(nameof(index));
        while (ObjectTableEntries.Count < index) ObjectTableEntries.Add(null);
        ObjectTableEntries[index - 1] = item;
    }

    internal void AttachObjectTable(List<XObject?> table) => _objectTableEntries = table;

    public void SetObjectTableEffectWord(short index, short value) => ObjectTableEffectWords[index] = value;

    public void SetInteractionExecutorFloat(int selector, float value)
    {
        InteractionExecutorFloats[selector] = value;
        if (this is XPerson person && (uint)selector < (uint)person.Motives.Length)
            person.Motives[selector] = value;
    }

    public void SetInteractionExecutorWord(int offset, short value)
    {
        if (offset == 0x59c) InteractionBehaviorSavedWord = value;
        else InteractionExecutorWords[offset] = value;
        if (this is XPerson person)
        {
            switch (offset)
            {
                case 0x62c: person.PersonData[80] = value; break;
                case 0x62e: person.PersonData[81] = value; break;
                case 0x630: person.PersonData[82] = value; break;
            }
        }
    }

    // Entry 0 is the tile-overlap chain; container attachment slots start at index 1.
    public List<short> Slots { get; } = [];
    public List<Formats.Slot> DefinitionSlots { get; } = [];
    public List<ObjectFootprintSlot> FootprintSlots { get; } = [];
    public List<RoutingSlotRequest> RoutingSlots { get; } = [];
    public List<ObjectRuntimeSlot> RuntimeSlots { get; } = [];
    public short[] DynamicSpriteFlags { get; set; } = [];
    public short[] TypeAttributes { get; set; } = [];
    public short InteractionBehaviorSavedWord { get; set; }
    public Dictionary<int, float> InteractionExecutorFloats { get; } = [];
    public Dictionary<int, short> InteractionExecutorWords { get; } = [];
    public TypeRecord? TypeRecord { get; set; }
    public ObjectPosition Position { get; set; }
    public RelationshipTable Relationships { get; } = new();

    public short this[ObjectData field]
    {
        get => Data[(int)field];
        set => Data[(int)field] = value;
    }
}

public sealed class TypeRecord(int key)
{
    public int Key { get; } = key;
    public byte ExtensionFlagsCC { get; init; }
    public short? AlternativeObjectPrice { get; init; }
    public bool RuntimeExtension88Initialized { get; internal set; }
    public short ObjectType { get; init; } = -1;
    public short SubIndex { get; init; }
    public short ObjectVersion { get; init; }
    public short? AnimatorBodyStringMode { get; init; }
    public IReadOnlyList<ushort>? FunctionTable { get; init; }
    public IReadOnlyList<ushort>? FunctionCheckTable { get; init; }
    public int? AlternativeTypeKey { get; init; }
    public ushort FootprintMask { get; init; }
    public int AnimationKey { get; init; }
    public string? Name { get; init; }
    public string? CatalogName { get; init; }
    public string? CatalogDescription { get; init; }
    public ITreeTable? BehaviorScope { get; init; }
    public InteractionTable? Interactions { get; init; }
    public short AutonomyAlternativeTypeFlag { get; init; }
}

public readonly record struct GatedObjectCallbackRequest(int First, int Second, int Third, int Fourth);

public readonly record struct AvatarAnimationEvent(int TimeMilliseconds, short Value)
{
    public static int MotionFrameToMilliseconds(int frame, int motionFrameCount, float durationMilliseconds) =>
        motionFrameCount > 0 && durationMilliseconds > 0f
            ? (int)(frame * (durationMilliseconds / motionFrameCount))
            : frame;

    public static AvatarAnimationEvent FromMotionFrame(int frame, short value, int motionFrameCount,
        float durationMilliseconds) => new(MotionFrameToMilliseconds(frame, motionFrameCount, durationMilliseconds), value);
}

public readonly record struct AvatarAnimationSoundEvent(int TimeMilliseconds, string PackId, string Resource, string Cue, bool Loop, bool Stop, string BoneName = "");

public readonly record struct AvatarAnimationMarker(float NormalizedTime, string Bone);

public readonly record struct HeadSeekGeometry(Vector2 Actor, Vector2 HeadFake, Vector2 Target);

public sealed record AvatarAnimationClip
{
    private readonly Lazy<(System.Numerics.Vector3 Offset, IReadOnlyList<System.Numerics.Vector3>? Samples)>? _lazyRootMotion;
    private readonly System.Numerics.Vector3 _standardOffset;
    private readonly IReadOnlyList<System.Numerics.Vector3>? _standardRootMotionSamples;

    public string Name { get; init; }
    public int FrameCount { get; init; }
    public IReadOnlyList<AvatarAnimationEvent> Events { get; init; }
    public IReadOnlyList<AvatarAnimationSoundEvent>? SoundEvents { get; init; }
    public float StandardDistance { get; init; }
    public System.Numerics.Vector3 StandardOffset
    {
        get => _lazyRootMotion is { } lazy ? lazy.Value.Offset : _standardOffset;
        init => _standardOffset = value;
    }
    public IReadOnlyList<System.Numerics.Vector3>? StandardRootMotionSamples
    {
        get => _lazyRootMotion is { } lazy ? lazy.Value.Samples : _standardRootMotionSamples;
        init => _standardRootMotionSamples = value;
    }
    public float DurationMilliseconds { get; init; }
    public AvatarAnimationMarker? LocomotionMarkerOne { get; init; }
    public AvatarAnimationMarker? LocomotionMarkerTwo { get; init; }

    public AvatarAnimationClip(string Name, int FrameCount, IReadOnlyList<AvatarAnimationEvent> Events,
        IReadOnlyList<AvatarAnimationSoundEvent>? SoundEvents = null, float StandardDistance = 0f,
        System.Numerics.Vector3 StandardOffset = default,
        IReadOnlyList<System.Numerics.Vector3>? StandardRootMotionSamples = null,
        float DurationMilliseconds = 0f,
        AvatarAnimationMarker? LocomotionMarkerOne = null,
        AvatarAnimationMarker? LocomotionMarkerTwo = null,
        Lazy<(System.Numerics.Vector3 Offset, IReadOnlyList<System.Numerics.Vector3>? Samples)>? LazyRootMotion = null)
    {
        this.Name = Name;
        this.FrameCount = FrameCount;
        this.Events = Events;
        this.SoundEvents = SoundEvents;
        this.StandardDistance = StandardDistance;
        _standardOffset = StandardOffset;
        _standardRootMotionSamples = StandardRootMotionSamples;
        this.DurationMilliseconds = DurationMilliseconds;
        this.LocomotionMarkerOne = LocomotionMarkerOne;
        this.LocomotionMarkerTwo = LocomotionMarkerTwo;
        _lazyRootMotion = LazyRootMotion;
    }
}

// Stores vector components as primitive arrays for save compatibility.
public sealed record AvatarAnimationPlaybackState(string Name, int FrameCount, AvatarAnimationEvent[] Events,
    AvatarAnimationSoundEvent[]? SoundEvents, float StandardDistance, float[] StandardOffset,
    float[][]? StandardRootMotionSamples, float DurationMilliseconds, bool Backwards, bool Loop, float Frame,
    bool EndReached, bool RouteDriven, byte EventsRun, int NextEventIndex, int NextSoundEventIndex,
    short[] EventQueue, AvatarAnimationSoundEvent[] SoundEventQueue)
{
    public bool InterpolatePose { get; init; } = true;
    public bool Interruptible { get; init; }
    public bool PoolSwimExit { get; init; }
    public long PracticeStartOrder { get; init; }
    public float PracticeWeight { get; init; } = 1f;
    public bool PracticeWeightFadeActive { get; init; }
    public int? PracticeWeightFadeStartMils { get; init; }
    public int? PracticeWeightFadeEndMils { get; init; }
    public float? PracticeWeightFadeStart { get; init; }
    public float? PracticeWeightFadeTarget { get; init; }
    public AvatarAnimationMarker? LocomotionMarkerOne { get; init; }
    public AvatarAnimationMarker? LocomotionMarkerTwo { get; init; }
    public int? LastPracticeApplyMils { get; init; }
    public float? PracticeScale { get; init; }
    public int PracticePriority { get; init; }
    public bool AllowUnblendedOverride { get; init; } = true;
    public string? AnchorBone { get; init; }
}

public sealed class AvatarAnimationPlayback(AvatarAnimationClip clip, bool backwards, bool loop, int? startedAtMils = null)
{
    private static long nextPracticeStartOrder;
    private int nextEventIndex = backwards ? clip.Events.Count - 1 : 0;
    private int nextSoundEventIndex = backwards ? (clip.SoundEvents?.Count ?? 0) - 1 : 0;
    public long PracticeStartOrder { get; private set; } = Interlocked.Increment(ref nextPracticeStartOrder);
    public AvatarAnimationClip Clip { get; } = clip;
    public bool Backwards { get; } = backwards;
    public bool Loop { get; } = loop;
    public int? LastPracticeApplyMils { get; private set; } = startedAtMils;
    public float PracticeScale { get; private set; } = backwards ? -1f : 1f;
    public float Frame { get; private set; } = backwards ? clip.FrameCount : 0;
    public bool EndReached { get; private set; } = !loop && clip.FrameCount <= 0;
    public bool InterpolatePose { get; private set; } = true;
    public bool RouteDriven { get; set; }
    public bool Interruptible { get; set; }
    public bool PoolSwimExit { get; init; }
    public float PracticeWeight { get; set; } = 1f;
    public int PracticePriority { get; set; }
    public bool AllowUnblendedOverride { get; set; } = true;
    public string? AnchorBone { get; set; }
    private bool practiceWeightFadeActive;
    private int practiceWeightFadeStartMils;
    private int practiceWeightFadeEndMils;
    private float practiceWeightFadeStart;
    private float practiceWeightFadeTarget;
    public bool IsPracticeWeightFadeActive => practiceWeightFadeActive;

    public void FadePracticeWeight(int startMils, int endMils, float startWeight, float targetWeight)
    {
        practiceWeightFadeActive = true;
        practiceWeightFadeStartMils = startMils;
        practiceWeightFadeEndMils = endMils;
        practiceWeightFadeStart = startWeight;
        practiceWeightFadeTarget = targetWeight;
    }

    public float EvaluatePracticeWeight(int animatorMils, float subTickAlpha = 0f)
    {
        if (!practiceWeightFadeActive || subTickAlpha <= 0f)
            return PracticeWeight;
        var duration = unchecked(practiceWeightFadeEndMils - practiceWeightFadeStartMils);
        if (duration <= 0)
            return practiceWeightFadeTarget;
        var elapsed = unchecked(animatorMils - practiceWeightFadeStartMils) + subTickAlpha * 42f;
        var amount = Math.Clamp(elapsed / duration, 0f, 1f);
        return practiceWeightFadeStart + amount * (practiceWeightFadeTarget - practiceWeightFadeStart);
    }

    private void ApplyPracticeWeightFade(int animatorMils)
    {
        if (!practiceWeightFadeActive) return;
        var elapsed = unchecked(animatorMils - practiceWeightFadeStartMils);
        var duration = unchecked(practiceWeightFadeEndMils - practiceWeightFadeStartMils);
        if (duration <= 0 || elapsed > duration)
        {
            practiceWeightFadeActive = false;
            PracticeWeight = practiceWeightFadeTarget;
            return;
        }
        var amount = (float)elapsed / duration;
        amount = Math.Clamp(amount, 0f, 1f);
        PracticeWeight = practiceWeightFadeStart + amount * (practiceWeightFadeTarget - practiceWeightFadeStart);
    }
    public void SetFrame(float frame) => Frame = frame;

    public void AdvanceRouteFrame(float targetFrame, bool queueSoundEvents)
    {
        var previousFrame = Frame;
        Frame = targetFrame;
        if (!queueSoundEvents || PracticeWeight <= 0f || Clip.FrameCount <= 0 || Clip.DurationMilliseconds <= 0f ||
            Clip.SoundEvents is not { Count: > 0 } sounds || Backwards)
            return;

        var msPerFrame = Clip.DurationMilliseconds / Clip.FrameCount;
        if (Loop && targetFrame + 1e-4f < previousFrame)
        {
            QueueRouteSoundEvents(sounds, Clip.DurationMilliseconds);
            nextSoundEventIndex = 0;
            QueueRouteSoundEvents(sounds, targetFrame * msPerFrame);
        }
        else
        {
            QueueRouteSoundEvents(sounds, targetFrame * msPerFrame);
        }

        void QueueRouteSoundEvents(IReadOnlyList<AvatarAnimationSoundEvent> list, float throughTime)
        {
            while (nextSoundEventIndex < list.Count)
            {
                var item = list[nextSoundEventIndex];
                if (item.TimeMilliseconds > throughTime) break;
                nextSoundEventIndex++;
                if (!string.IsNullOrEmpty(item.PackId) ||
                    item.Resource is "footstep" or "sound")
                {
                    SoundEventQueue.Add(item);
                }
            }
        }
    }

    public void SetPracticeScale(float scale) => PracticeScale = scale;
    public byte EventsRun { get; private set; }
    public List<short> EventQueue { get; } = [];
    public List<AvatarAnimationSoundEvent> SoundEventQueue { get; } = [];

    public AvatarAnimationPlaybackState SaveState() => new(Clip.Name, Clip.FrameCount, Clip.Events.ToArray(),
        Clip.SoundEvents?.ToArray(), Clip.StandardDistance, [Clip.StandardOffset.X, Clip.StandardOffset.Y, Clip.StandardOffset.Z],
        Clip.StandardRootMotionSamples?.Select(sample => new[] { sample.X, sample.Y, sample.Z }).ToArray(),
        Clip.DurationMilliseconds, Backwards, Loop, Frame, EndReached, RouteDriven, EventsRun, nextEventIndex,
        nextSoundEventIndex, EventQueue.ToArray(), SoundEventQueue.ToArray())
    {
        Interruptible = Interruptible,
        PoolSwimExit = PoolSwimExit,
        PracticeStartOrder = PracticeStartOrder,
        PracticeWeight = PracticeWeight,
        PracticeWeightFadeActive = practiceWeightFadeActive,
        PracticeWeightFadeStartMils = practiceWeightFadeActive ? practiceWeightFadeStartMils : null,
        PracticeWeightFadeEndMils = practiceWeightFadeActive ? practiceWeightFadeEndMils : null,
        PracticeWeightFadeStart = practiceWeightFadeActive ? practiceWeightFadeStart : null,
        PracticeWeightFadeTarget = practiceWeightFadeActive ? practiceWeightFadeTarget : null,
        LocomotionMarkerOne = Clip.LocomotionMarkerOne,
        LocomotionMarkerTwo = Clip.LocomotionMarkerTwo,
        LastPracticeApplyMils = LastPracticeApplyMils,
        PracticeScale = PracticeScale,
        InterpolatePose = InterpolatePose,
        PracticePriority = PracticePriority,
        AllowUnblendedOverride = AllowUnblendedOverride,
        AnchorBone = AnchorBone,
    };

    public static AvatarAnimationPlayback RestoreState(AvatarAnimationPlaybackState state)
    {
        ArgumentNullException.ThrowIfNull(state);
        if (state.FrameCount < 0 || state.Events is null || state.EventQueue is null || state.SoundEventQueue is null ||
            state.StandardOffset is not { Length: 3 } || state.StandardRootMotionSamples?.Any(sample => sample is not { Length: 3 }) == true ||
            state.NextEventIndex < -1 || state.NextEventIndex > state.Events.Length ||
            state.NextSoundEventIndex < -1 || state.NextSoundEventIndex > (state.SoundEvents?.Length ?? 0) ||
            state.PracticeScale is { } savedScale && !float.IsFinite(savedScale) ||
            (state.PracticeWeightFadeActive && (state.PracticeWeightFadeStartMils is null ||
                state.PracticeWeightFadeEndMils is null || state.PracticeWeightFadeStart is null ||
                state.PracticeWeightFadeTarget is null)))
            throw new InvalidDataException("Invalid saved avatar animation state.");
        var clip = new AvatarAnimationClip(state.Name, state.FrameCount, state.Events, state.SoundEvents,
            state.StandardDistance, new System.Numerics.Vector3(state.StandardOffset[0], state.StandardOffset[1], state.StandardOffset[2]),
            state.StandardRootMotionSamples?.Select(sample => new System.Numerics.Vector3(sample[0], sample[1], sample[2])).ToArray(),
            state.DurationMilliseconds, state.LocomotionMarkerOne, state.LocomotionMarkerTwo);
        var result = new AvatarAnimationPlayback(clip, state.Backwards, state.Loop, state.LastPracticeApplyMils)
        {
            Frame = state.Frame,
            InterpolatePose = state.InterpolatePose,
            PracticeScale = state.PracticeScale ?? (state.Backwards ? -1f : 1f),
            EndReached = state.EndReached || (!state.Loop && state.FrameCount <= 0),
            RouteDriven = state.RouteDriven,
            Interruptible = state.Interruptible,
            PoolSwimExit = state.PoolSwimExit,
            PracticeWeight = state.PracticeWeight,
            practiceWeightFadeActive = state.PracticeWeightFadeActive,
            practiceWeightFadeStartMils = state.PracticeWeightFadeStartMils ?? 0,
            practiceWeightFadeEndMils = state.PracticeWeightFadeEndMils ?? 0,
            practiceWeightFadeStart = state.PracticeWeightFadeStart ?? state.PracticeWeight,
            practiceWeightFadeTarget = state.PracticeWeightFadeTarget ?? state.PracticeWeight,
            PracticePriority = state.PracticePriority,
            AllowUnblendedOverride = state.AllowUnblendedOverride,
            AnchorBone = state.AnchorBone,
            EventsRun = state.EventsRun,
            nextEventIndex = state.NextEventIndex,
            nextSoundEventIndex = state.NextSoundEventIndex,
        };
        if (state.PracticeStartOrder > 0)
        {
            result.PracticeStartOrder = state.PracticeStartOrder;
            AdvancePracticeOrder(state.PracticeStartOrder);
        }
        result.EventQueue.AddRange(state.EventQueue);
        result.SoundEventQueue.AddRange(state.SoundEventQueue);
        return result;
    }

    private static void AdvancePracticeOrder(long value)
    {
        var current = Volatile.Read(ref nextPracticeStartOrder);
        while (current < value)
        {
            var observed = Interlocked.CompareExchange(ref nextPracticeStartOrder, value, current);
            if (observed == current) return;
            current = observed;
        }
    }

    public void Tick(bool deliverAnimationEvents = true, int? animatorMils = null)
    {
        if (animatorMils is { } now) ApplyPracticeWeightFade(now);
        var elapsedMils = animatorMils is { } currentMils && LastPracticeApplyMils is { } previousMils
            ? unchecked(currentMils - previousMils)
            : 42;
        if (Clip.FrameCount > 0)
        {
            var poseDuration = Clip.DurationMilliseconds > 0f
                ? Clip.DurationMilliseconds
                : Clip.FrameCount * (1000f / 30f);
            var scale = MathF.Abs(PracticeScale);
            var frameInterval = scale > 0f ? poseDuration / (Clip.FrameCount * scale) : float.PositiveInfinity;
            InterpolatePose = frameInterval + frameInterval > elapsedMils;
        }
        else InterpolatePose = false;
        if (animatorMils is { } appliedMils) LastPracticeApplyMils = appliedMils;
        if (Clip.FrameCount <= 0)
        {
            if (!Loop) EndReached = true;
            return;
        }
        if (RouteDriven || EndReached) return;
        var duration = Clip.DurationMilliseconds;
        var backwards = PracticeScale < 0f;
        var practiceScale = MathF.Abs(PracticeScale);
        var frameStep = duration > 0f
            ? Clip.FrameCount * (elapsedMils / duration) * practiceScale
            : 1.2f * (elapsedMils / 42f) * practiceScale;
        var previousFrame = Frame;
        Frame += backwards ? -frameStep : frameStep;
        if (!Loop)
        {
            Frame = Math.Clamp(Frame, 0f, Clip.FrameCount);
            EndReached = backwards ? Frame <= 0f : Frame >= Clip.FrameCount;
        }
        var time = duration > 0f ? Frame * (duration / Clip.FrameCount) : Frame * (1000f / 30f);
        var processedLoopBoundary = false;
        if (PracticeWeight > 0f && Loop && duration > 0f && frameStep > 0f &&
            (backwards ? Frame < 0f : Frame > Clip.FrameCount))
        {
            var remainingMilliseconds = frameStep * (duration / Clip.FrameCount);
            var currentTime = previousFrame * (duration / Clip.FrameCount);
            if (!backwards)
            {
                while (remainingMilliseconds > 0f)
                {
                    var endTime = Math.Min(duration, currentTime + remainingMilliseconds);
                    QueueForwardEventsThrough(endTime);
                    remainingMilliseconds -= endTime - currentTime;
                    if (endTime < duration || remainingMilliseconds <= 0f) break;
                    nextEventIndex = 0;
                    nextSoundEventIndex = 0;
                    currentTime = 0f;
                }
            }
            else
            {
                while (remainingMilliseconds > 0f)
                {
                    var startTime = Math.Max(0f, currentTime - remainingMilliseconds);
                    QueueBackwardEventsThrough(startTime);
                    remainingMilliseconds -= currentTime - startTime;
                    if (startTime > 0f || remainingMilliseconds <= 0f) break;
                    nextEventIndex = Clip.Events.Count - 1;
                    nextSoundEventIndex = (Clip.SoundEvents?.Count ?? 0) - 1;
                    currentTime = duration;
                }
            }
            processedLoopBoundary = true;
        }
        else if (PracticeWeight > 0f && backwards)
        {
            QueueBackwardEventsThrough(time);
        }
        else if (PracticeWeight > 0f)
        {
            QueueForwardEventsThrough(time);
        }

        if (Frame > Clip.FrameCount || Frame < 0)
        {
            if (Loop)
            {
                Frame %= Clip.FrameCount;
                if (Frame < 0) Frame += Clip.FrameCount;
                if (!processedLoopBoundary)
                {
                    nextEventIndex = backwards ? Clip.Events.Count - 1 : 0;
                    nextSoundEventIndex = backwards ? (Clip.SoundEvents?.Count ?? 0) - 1 : 0;
                }
            }
            else EndReached = true;
        }

        void QueueForwardEventsThrough(float throughTime)
        {
            var sounds = Clip.SoundEvents ?? [];
            while (nextSoundEventIndex < sounds.Count)
            {
                var item = sounds[nextSoundEventIndex];
                if (item.TimeMilliseconds > throughTime) break;
                nextSoundEventIndex++;
                SoundEventQueue.Add(item);
            }
            while (nextEventIndex < Clip.Events.Count)
            {
                var item = Clip.Events[nextEventIndex];
                if (item.TimeMilliseconds > throughTime) break;
                nextEventIndex++;
                if (deliverAnimationEvents) EventQueue.Add(item.Value);
            }
        }

        void QueueBackwardEventsThrough(float throughTime)
        {
            var sounds = Clip.SoundEvents ?? [];
            while (nextSoundEventIndex >= 0)
            {
                var item = sounds[nextSoundEventIndex];
                if (item.TimeMilliseconds < throughTime) break;
                nextSoundEventIndex--;
                SoundEventQueue.Add(item);
            }
            while (nextEventIndex >= 0)
            {
                var item = Clip.Events[nextEventIndex];
                if (item.TimeMilliseconds < throughTime) break;
                nextEventIndex--;
                if (deliverAnimationEvents) EventQueue.Add(item.Value);
            }
        }
    }

    public short? TakeMissingExpectedEvent(sbyte expectedCount, bool? backwardsOverride = null)
    {
        if (EventsRun >= expectedCount) return null;
        var backwards = backwardsOverride ?? Backwards;
        var expected = backwards ? expectedCount - EventsRun - 1 : EventsRun;
        EventsRun++;
        return (short)expected;
    }

    public bool TryConsumeExpectedEvent(short value, sbyte expectedCount, out short expectedValue, bool? backwardsOverride = null)
    {
        const short substituteEventThreshold = 100;
        expectedValue = value;
        if (value >= substituteEventThreshold) return true;
        var backwards = backwardsOverride ?? Backwards;
        var expected = backwards ? expectedCount - EventsRun - 1 : EventsRun;
        if (expected < 0 || expected >= expectedCount || value != expected) return false;
        expectedValue = (short)expected;
        EventsRun++;
        return true;
    }
}

public readonly record struct GenericSimsCallRequestResult(short Temporary0, short Temporary1, int Status);

public readonly record struct GenericSimsCallRequestCompletion(
    short Temporary0,
    short Temporary1,
    bool Succeeded,
    int? TargetTypeRecordKey = null);

public sealed class XPerson(short id, short[] definition, int attributes = 0) : XObject(id, definition, attributes)
{
    public const short PersonType = 2;

    public List<GenericSimsCallPersonTypeRecord> GenericSimsCallPersonTypeRecords { get; } = [];

    public short GenericSimsCallPersonTypeRecordIndex { get; set; }

    public override short SelectionWord5CC
    {
        get => PersonData[(int)global::SimsEngine.Simulation.PersonData.PersonType];
        set => PersonData[(int)global::SimsEngine.Simulation.PersonData.PersonType] = value;
    }

    public override short SelectionWord606
    {
        get => PersonData[(int)global::SimsEngine.Simulation.PersonData.FamilyNumber];
        set => PersonData[(int)global::SimsEngine.Simulation.PersonData.FamilyNumber] = value;
    }

    public bool TryBeginObjectReferenceNotification()
    {
        if ((Flags & 0x00000800u) != 0) return false;
        Flags |= 0x00000800u;
        return true;
    }

    public void EndObjectReferenceNotification() => Flags &= ~0x00000800u;

    public void ClearPreviousActionRecord() => PreviousActionRecord = ActionQueueSlot.EmptyRecord();

    public void InvalidateRuntimeObjectReferences(XObject subject)
    {
        ArgumentNullException.ThrowIfNull(subject);
        if (subject.Definition[(int)ObjdField.Type] != PersonType) return;
        foreach (var entry in RuntimeObjectReferences)
        {
            if (!ReferenceEquals(entry.Target, subject)) continue;
            entry.State84 = 1;
            entry.Target = null;
            entry.RawWord90 = 0;
        }
    }

    public short InteractionActionWord72
    {
        get => this[ObjectData.TreeTableEntry];
        set => this[ObjectData.TreeTableEntry] = value;
    }
    public ObjectPosition? LastLookTowardsPoint { get; set; }

    public short FootprintFlags614 { get => this[global::SimsEngine.Simulation.PersonData.IsGhost]; set => this[global::SimsEngine.Simulation.PersonData.IsGhost] = value; }
    public short FootprintFlags634 { get => this[global::SimsEngine.Simulation.PersonData.IsLivingGhost]; set => this[global::SimsEngine.Simulation.PersonData.IsLivingGhost] = value; }

    public short[] PersonData { get; } = new short[256];
    public float[] Motives { get; } = new float[16];
    public AvatarAnimationPlayback? AnimationPlayback { get; set; }
    public List<short> PendingAnimationEvents { get; } = [];
    public float AnimatorWalkingScale { get; set; } = 1f;
    public bool? AnimatorHeadSeekRegistrationsAvailable { get; set; }
    public float AnimatorHeadAdjustment { get; set; }
    public float AnimatorHeadBaselineDirection { get; set; }
    public float AnimatorHeadTargetDirection { get; set; }
    public Vector2 AnimatorHeadTargetPoint { get; set; }
    public float AnimatorBodyScale { get; set; } = 1f;
    public bool AnimatorScaleUpdateSuppressed { get; set; }
    public float? AnimatorRootX { get; set; }
    public float? AnimatorRootY { get; set; }
    public float? AnimatorRootDirection { get; set; }
    public float AnimatorDisplacementX { get; private set; }
    public float AnimatorDisplacementY { get; private set; }
    public float AnimatorDisplacementDirection { get; private set; }
    public float AnimatorProjectedRootStepX { get; set; }
    public float AnimatorProjectedRootStepY { get; set; }
    public void SetAnimatorDisplacements(float x, float y, float direction)
    {
        AnimatorDisplacementX = x;
        AnimatorDisplacementY = y;
        AnimatorDisplacementDirection = direction;
    }
    public int AnimatorControlState { get; set; } = 3;
    public bool AnimatorPracticeScaleEnabled { get; set; }
    public int AnimatorCurrentSkill { get; set; } = -1;
    public int AnimatorMilliseconds { get; set; }
    public int AnimatorLocomotionFadeGate { get; set; }
    public int AnimatorPoolTransitionState { get; set; }
    public int AnimatorRouteTransitionState { get; set; }
    public int AnimatorStateTailField198 { get; set; }
    public bool AnimatorPoolTile { get; set; }
    public int AnimatorGaitEntryState { get; set; }
    public short AnimatorBodyStringMode { get; set; }
    public AvatarAnimationPlayback? BackgroundAnimationPlayback { get; set; }
    public short BackgroundPracticePersonState { get; set; } = -1;
    public bool BackgroundPracticePoolTile { get; set; }
    public AvatarAnimationPlayback? LastAnimationPlayback { get; set; }
    public bool AnimatorDiscontinuityPending { get; set; }
    public string? AnimatorAnchorBone { get; set; }
    public bool AnimatorAnchorInitialized { get; set; }
    public Vector3 AnimatorAnchorWorldPosition { get; set; }
    public bool PrimaryAnimationWaiting { get; set; }
    public byte PrimaryAnimationEventsRun { get; set; }
    public bool PrimaryAnimationBackwards { get; set; }
    public AvatarAnimationPlayback? CarryAnimationPlayback { get; set; }
    public int CarryPracticeMode { get; set; }
    public IReadOnlyList<AvatarAnimationPlayback> GetAnimationPracticeApplicationOrder()
    {
        var result = new List<(AvatarAnimationPlayback Playback, int Priority, long StartOrder)>(4);
        if (BackgroundAnimationPlayback is { } background) result.Add((background, -10, background.PracticeStartOrder));
        if (AnimationPlayback is { } primary) result.Add((primary, primary.PracticePriority, primary.PracticeStartOrder));
        if (LastAnimationPlayback is { } last) result.Add((last, last.PracticePriority, last.PracticeStartOrder));
        if (CarryAnimationPlayback is { } carry)
            result.Add((carry, 10, carry.PracticeStartOrder));
        result.Sort(static (left, right) =>
        {
            var priority = left.Priority.CompareTo(right.Priority);
            return priority != 0 ? priority : left.StartOrder.CompareTo(right.StartOrder);
        });
        return result.ConvertAll(static entry => entry.Playback);
    }

    public bool TryDequeueAnimationEvent(out short value)
    {
        if (PendingAnimationEvents.Count > 0)
        {
            value = PendingAnimationEvents[0];
            PendingAnimationEvents.RemoveAt(0);
            return true;
        }
        if (AnimationPlayback is { EventQueue.Count: > 0 } playback)
        {
            value = playback.EventQueue[0];
            playback.EventQueue.RemoveAt(0);
            return true;
        }
        value = default;
        return false;
    }
    public int CarryPracticeCachedState { get; set; } = -1;
    public bool ReachAnimationActive { get; set; }
    public RouteState? NativeRoute { get; set; }
    public List<RouteState> NativeRouteParents { get; } = [];
    public void ApplyMotiveChanges()
    {
        foreach (var change in MotiveChanges)
        {
            var index = (int)change.Motive;
            if ((uint)index >= (uint)Motives.Length) continue;
            var current = Motives[index];
            if (change.Rate >= 0f)
            {
                if (current < change.Target)
                {
                    current += change.Rate;
                    if (change.Target < current) current = change.Target;
                }
            }
            else if (change.Target < current)
            {
                current += change.Rate;
                if (current < change.Target) current = change.Target;
            }
            Motives[index] = current;
        }
    }
    public float[] SavedPersonValues7CC { get; } = new float[16];
    public int MotiveDecayLastTickCounter { get; set; }
    public short PersonTickGateWord8E { get; set; }
    public ushort LastObservedRoomIdAFC { get; set; }
    public PersonCharacter? SavedCharacter { get; set; }
    public PersonCharacter? PresentationCharacter { get; set; }
    public List<(string Appearance, string Texture)> TransientExtraParts { get; } = [];

    public void DressAccessory(string appearance, string texture = "")
    {
        var suit = appearance.Trim();
        var suitTexture = texture.Trim();
        if (suit.Length == 0 || suit.Equals("NONE", StringComparison.OrdinalIgnoreCase)) return;
        UndressAccessory(suit);
        TransientExtraParts.Add((suit, suitTexture));
        if (SavedCharacter is { } character)
        {
            var appearances = character.ExtraParts.ToList();
            appearances.Add((suit, suitTexture));
            SavedCharacter = character with { ExtraParts = appearances };
        }
        if (PresentationCharacter is { } presentation)
        {
            var appearances = presentation.ExtraParts.ToList();
            appearances.Add((suit, suitTexture));
            PresentationCharacter = presentation with { ExtraParts = appearances };
        }
    }

    public void UndressAccessory(string appearance)
    {
        var key = NormalizeAccessorySuitName(appearance);
        if (key.Length == 0) return;
        TransientExtraParts.RemoveAll(part =>
            NormalizeAccessorySuitName(part.Appearance).Equals(key, StringComparison.OrdinalIgnoreCase));
        if (SavedCharacter is { } character)
        {
            var appearances = character.ExtraParts
                .Where(part => !NormalizeAccessorySuitName(part.Item1).Equals(key, StringComparison.OrdinalIgnoreCase))
                .ToList();
            if (appearances.Count != character.ExtraParts.Count)
                SavedCharacter = character with { ExtraParts = appearances };
        }
        if (PresentationCharacter is { } presentation)
        {
            var appearances = presentation.ExtraParts
                .Where(part => !NormalizeAccessorySuitName(part.Item1).Equals(key, StringComparison.OrdinalIgnoreCase))
                .ToList();
            if (appearances.Count != presentation.ExtraParts.Count)
                PresentationCharacter = presentation with { ExtraParts = appearances };
        }
    }

    public void ClearExtraParts()
    {
        TransientExtraParts.Clear();
        if (SavedCharacter is { ExtraParts.Count: > 0 } character)
            SavedCharacter = character with { ExtraParts = [] };
        if (PresentationCharacter is { ExtraParts.Count: > 0 } presentation)
            PresentationCharacter = presentation with { ExtraParts = [] };
    }

    private static string NormalizeAccessorySuitName(string name)
    {
        var trimmed = name.Trim();
        foreach (var suffix in new[] { ".cmx.bcf", ".apr", ".bcf", ".cmx" })
        {
            if (trimmed.EndsWith(suffix, StringComparison.OrdinalIgnoreCase))
            {
                trimmed = trimmed[..^suffix.Length];
                break;
            }
        }
        return trimmed;
    }
    public bool NativeOutfitTransitionActive { get; set; }
    public int SavedPersonActionStorageCount { get; set; }
    public List<PersonRuntimeObjectReference> RuntimeObjectReferences { get; } = [];
    public List<PersonRuntimeStateRecord> RuntimeStateRecords { get; } = [];
    public List<PersonActionRequest> PendingActionRequests { get; } = [];
    public PersonAction? SavedCurrentAction { get; set; }
    public PersonAction? SavedQueuedAction { get; set; }
    public List<PersonAction> SavedActions { get; } = [];
    public List<PersonObjectReference> SavedPersonObjectReferences { get; } = [];
    public IReadOnlyList<PersonValueEntry> SavedPersonValues => WriteMotiveChanges();

    public void RestoreMotiveChanges(IReadOnlyList<PersonValueEntry> entries)
    {
        MotiveChanges.Clear();
        foreach (var entry in entries)
            MotiveChanges.Add(new MotiveChange((Motive)entry.Value, entry.First, entry.Second));
    }

    public PersonValueEntry[] WriteMotiveChanges() =>
        MotiveChanges.Select(change => new PersonValueEntry((int)change.Motive, change.Rate, change.Target)).ToArray();
    public short ActivePriority
    {
        get => PersonData[(int)global::SimsEngine.Simulation.PersonData.Priority];
        set => PersonData[(int)global::SimsEngine.Simulation.PersonData.Priority] = value;
    }
    public int GenericSimsCall02GateWordA84
    {
        get => CurrentActionRecord?.Sequence ?? 0;
        set
        {
            if (CurrentActionRecord is { } record) record.Sequence = value;
            else CurrentActionRecord = new ActionQueueSlot { Sequence = value };
        }
    }
    public bool ActiveActionCancelRequested { get; set; }
    public HashSet<string> InteractionAttachments { get; } = new(StringComparer.Ordinal);
    public XObject? GenericSimsCall02ObjectA54 { get; set; }
    public ActionQueueSlot? CurrentActionRecord { get; set; }
    public ActionQueueSlot? PreviousActionRecord { get; private set; }
    public void RestoreActionState(PersonState state, SimulationWorld world)
    {
        CurrentActionRecord = ActionQueueSlot.FromSaved(state.First, world);
        PreviousActionRecord = ActionQueueSlot.FromSaved(state.Second, world);
        world.RestoreActionSequence(state.First.Id);
        world.RestoreActionSequence(state.Second.Id);
        ActionQueueCurrent = ActionQueueEnd = 0;
        foreach (var action in state.Actions)
        {
            world.RestoreActionSequence(action.Id);
            if (ActionQueueEnd < ActionQueue.Length)
                ActionQueue[ActionQueueEnd++] = ActionQueueSlot.FromSaved(action, world);
        }
        GenericSimsCall02ObjectA54 = CurrentActionRecord.Secondary;
        GenericSimsCall02GateWordA84 = CurrentActionRecord.Sequence;
    }

    public IReadOnlyList<PersonAction> WriteActionQueue()
    {
        var count = unchecked(ActionQueueEnd - ActionQueueCurrent);
        if (count is < 0 or > 8) throw new InvalidDataException($"Person {Id}: invalid action queue count {count}.");
        return Enumerable.Range(0, count).Select(index => ActionQueue[(ActionQueueCurrent + index) & 7].ToSaved()).ToArray();
    }

    public byte ActionFlagByte20 { get; set; }
    public short CurrentActionWord5D8
    {
        get => PersonData[(int)global::SimsEngine.Simulation.PersonData.MultipleRoutes];
        set => PersonData[(int)global::SimsEngine.Simulation.PersonData.MultipleRoutes] = value;
    }
    public short CurrentActionWord5DA
    {
        get => PersonData[(int)global::SimsEngine.Simulation.PersonData.RoutingComplete];
        set => PersonData[(int)global::SimsEngine.Simulation.PersonData.RoutingComplete] = value;
    }

    public short this[PersonData field] { get => PersonData[(int)field]; set => PersonData[(int)field] = value; }
    public float this[Motive motive] { get => Motives[(int)motive]; set => Motives[(int)motive] = value; }

    public void RefreshFootprintBounds()
    {
        FootprintBounds = FootprintBoundsAt(Position);
        FootprintBoundsDirection = this[ObjectData.Direction];
    }

    public FootprintBounds FootprintBoundsAt(ObjectPosition position)
    {
        var span = (FootprintFlags614 & 1) != 0 || (FootprintFlags634 & 1) != 0 ? 0 : 6;
        var half = span / 2;
        var mask = TypeRecord?.FootprintMask
            ?? unchecked((ushort)Definition[(int)ObjdField.FootprintMask]);
        static int Extent(ushort value, int index) => (value >> (index * 4)) & 0xf;
        var extents = Enumerable.Range(0, 4).Select(index => Extent(mask, index)).ToArray();
        var extension = this[global::SimsEngine.Simulation.PersonData.FootprintExtension];
        if (extension != 0 && (this[ObjectData.Direction] & 1) == 0)
            for (var index = 0; index < extents.Length; index++)
                extents[index] -= Extent(unchecked((ushort)extension), index);
        var rotation = (8 - this[ObjectData.Direction]) / 2;
        return new FootprintBounds(
            position.X + half - extents[(rotation + 1) % 4],
            position.Y + half - extents[(rotation + 2) % 4],
            position.X - half + extents[(rotation + 3) % 4],
            position.Y - half + extents[rotation % 4]);
    }

    public void ApplyStartedActionState(ActionQueueSlot action, int? replacementSequence = null)
    {
        if (CurrentActionRecord?.Owner is not null)
        {
            PreviousActionRecord = CurrentActionRecord.Copy();
            PreviousActionRecord.Flags = (PreviousActionRecord.Flags & ~0x20) | (ActionFlagByte20 != 0 ? 0x20 : 0);
        }
        CurrentActionRecord = action.Copy();
        if (CurrentActionRecord.Owner is not null)
        {
            CurrentActionWord5D8 = 0;
            CurrentActionWord5DA = 0;
            if (GenericSimsCall02GateWordA84 == 0 && replacementSequence is { } sequence)
                CurrentActionRecord.Sequence = sequence;
        }
        GenericSimsCall02ObjectA54 = CurrentActionRecord.Secondary;
        ActivePriority = unchecked((short)action.Threshold);
        MotiveChanges.Clear();
        if (this[global::SimsEngine.Simulation.PersonData.FootprintExtension] != 0)
        {
            this[global::SimsEngine.Simulation.PersonData.FootprintExtension] = 0;
            RefreshFootprintBounds();
        }
        this[global::SimsEngine.Simulation.PersonData.RouteFootprintMask] = 0;
        this[global::SimsEngine.Simulation.PersonData.NonInterruptible] = 0;
    }

    public void SetCurrentActionSecondaryReference(XObject? value)
    {
        GenericSimsCall02ObjectA54 = value;
        if (CurrentActionRecord is { } current) current.Secondary = value;
    }

    public List<MotiveChange> MotiveChanges { get; } = [];
    public List<XObject> InteractingObjects { get; } = [];

    public byte InputFlags
    {
        get => unchecked((byte)Data[(int)ObjectData.Flags]);
        set => Data[(int)ObjectData.Flags] = unchecked((short)(((ushort)Data[(int)ObjectData.Flags] & 0xff00) | value));
    }
    public const byte IdleForInputFlag = 0x40;
    public int ActionQueueCurrent { get; set; }
    public int ActionQueueEnd { get; set; }
    public ActionQueueSlot[] ActionQueue { get; } = [new(), new(), new(), new(), new(), new(), new(), new()];
    public float IdleFloat7A0 { get => Motives[5]; set => Motives[5] = value; }
    public float IdleFloat7A8 { get => Motives[7]; set => Motives[7] = value; }
    public float IdleFloat7B0 { get => Motives[9]; set => Motives[9] = value; }
}

public sealed record PersonActionRequest(XObject Target, int Priority, bool Flag);

public sealed record FoundActionPushFailure(short PersonId, short TargetId, short Key, short ActionTree, string Reason);

public sealed class PersonRuntimeObjectReference(XObject? target, byte state84 = 0, int rawWord90 = 0, int rawWord28 = 0)
{
    public XObject? Target { get; set; } = target;
    public byte State84 { get; set; } = state84;
    public int RawWord90 { get; set; } = rawWord90;
    public int RawWord28 { get; set; } = rawWord28;
}

public sealed class PersonRuntimeStateRecord(XObject? target = null, int rawWord28 = 0)
{
    public XObject? Target { get; set; } = target;
    public int RawWord28 { get; set; } = rawWord28;
}

public sealed record PersonObjectReference(short SavedObjectKey, XObject? Target, int Value, bool Flag);

public sealed class ActionQueueSlot
{
    public int RawDword10 { get; set; }
    public int Threshold { get; set; }
    public int Flags { get; set; }
    public XPerson? Person { get; init; }
    public XObject? Owner { get; init; }
    public XObject? Secondary { get; set; }
    public int RecordKind { get; init; }
    public short[] Parameters { get; init; } = new short[4];
    public byte InteractionId { get => unchecked((byte)RawDword10); init => RawDword10 = value; }
    public ushort ActionTree { get; init; }
    public float Attenuation { get; init; }
    public int Sequence { get; set; }
    public string? ActionText { get; set; }
    public MotiveAdvertisement[]? EvaluatedAdvertisements { get; set; }

    public static ActionQueueSlot FromSaved(PersonAction action, SimulationWorld world) => new()
    {
        RecordKind = action.Value0x00,
        Sequence = action.Id,
        Person = world.ObjectById(action.Person) as XPerson,
        Owner = world.ObjectById(action.Object0x08),
        Secondary = world.ObjectById(action.Object0x0C),
        RawDword10 = action.Value0x10,
        Parameters = action.Values0x14.ToArray(),
        Threshold = action.Value0x1C,
        ActionTree = unchecked((ushort)action.Value0x20),
        Attenuation = action.Value0x24,
        Flags = action.Flags,
    };

    public PersonAction ToSaved() => new(RecordKind, Sequence, Person?.RequestKey ?? 0,
        Owner?.RequestKey ?? 0, Secondary?.RequestKey ?? 0, RawDword10, Parameters.ToArray(), Threshold,
        unchecked((short)ActionTree), Attenuation, Flags);

    public static ActionQueueSlot EmptyRecord() => new() { RawDword10 = -1 };

    public ActionQueueSlot Copy() => new()
    {
        RawDword10 = RawDword10,
        RecordKind = RecordKind,
        Parameters = Parameters.ToArray(),
        Threshold = Threshold,
        Flags = Flags,
        Person = Person,
        Owner = Owner,
        Secondary = Secondary,
        ActionTree = ActionTree,
        Attenuation = Attenuation,
        Sequence = Sequence,
        ActionText = ActionText,
        EvaluatedAdvertisements = EvaluatedAdvertisements?.ToArray(),
    };
}

public sealed record ActionQueueRemovalNotice(short PersonKey, int QueuePosition);
public sealed record QueuedInteractionStartTrace(short PersonId, short? TargetId, short ActionTree,
    bool TargetScopeFound, bool InteractionPassed, bool ActionTreePushed, ushort GuardTree,
    short PersonSelectionWord, short PersonAge, short PersonGender, int StateClass, short TargetFlags);
public sealed class GenericSimsCallPersonTypeRecord(
    int registryIndex, short index, int typeRecordKey, short objectType, string? catalogName, string typeName)
{
    public int RegistryIndex { get; } = registryIndex;
    public short Index { get; } = index;
    public int TypeRecordKey { get; } = typeRecordKey;
    public short ObjectType { get; } = objectType;
    public string? CatalogName { get; } = catalogName;
    public string TypeName { get; } = typeName;
    public short[] Payload { get; } = new short[256];
}
public sealed record GenericSimsCallChooserCandidate(
    int RegistryIndex,
    short PersonTypeRecordIndex,
    int TypeRecordKey,
    int PersonRecordIndex,
    short? LivePersonId,
    string? NeighborName,
    short[]? PersonData,
    string? CatalogName,
    string TypeName);

public sealed class NeighborState(short id, short[] definition)
{
    public short Id { get; } = id;
    public string? Name { get; set; }
    public int TypeRecordKey { get; set; }
    public uint? FriendEligibilityObjectFlagsB4 { get; set; }
    public int PersonRecordVersion { get; set; }
    public short[] PersonData { get; } = new short[256];
    public short[] Definition { get; } = definition;
    public RelationshipTable Relationships { get; } = new();
    public bool RelationshipsChangedFlag24 { get; set; }
    public int FriendCountWord20 { get; set; }
}

public sealed class StackFrame(short stackObject, short[] parameters, short[] locals)
{
    internal short[] StackObjectCell { get; } = [stackObject];
    public short StackObject { get => StackObjectCell[0]; set => StackObjectCell[0] = value; }
    public short[] Parameters { get; } = parameters;
    public short[] Locals { get; } = locals;
    public object? Tree { get; init; }
    public short TreeId { get; init; } = -1;
    public bool TreeBreakpoint { get; set; }
    public int Instruction { get; set; }
    public int WaitState { get; set; }
    public bool Waiting { get => WaitState != 0; set => WaitState = value ? 1 : 0; }
    public short CodeOwner { get; init; }
    public ITreeTable? Table { get; init; }
}

public sealed class RoutingSlotRequest
{
    public float X { get; set; }
    public float Y { get; set; }
    public float Z { get; set; }
    public int Standing { get; set; }
    public int Sitting { get; set; }
    public int Ground { get; set; }
    public uint Flags { get; set; }
    public bool CheckCandidateFootprintAgainstWall { get; set; }
    public int SnapTargetSlot { get; set; } = -1;
    public int MinProximity { get; set; } = 16;
    public int MaxProximity { get; set; } = 16;
    public int OptimalProximity { get; set; } = 16;
    public float Gradient { get; set; } = 0.1875f;
    // SLOT facing: -1 opposite anchor, -2 toward anchor, -3 keep current, 0..7 relative to anchor.
    public int Facing { get; set; } = -2;
    public int Resolution { get; set; } = 16;

    public static RoutingSlotRequest FromDefinition(Formats.Slot slot)
    {
        ArgumentNullException.ThrowIfNull(slot);
        if (slot.Type != 3) throw new ArgumentException("Only type-3 SLOT entries build routing slots.", nameof(slot));
        return new RoutingSlotRequest
        {
            X = slot.X, Y = slot.Y, Z = slot.Z,
            Standing = slot.Standing, Sitting = slot.Sitting, Ground = slot.Ground,
            Flags = slot.Flags, SnapTargetSlot = slot.SnapTargetSlot,
            MinProximity = slot.MinProximity, MaxProximity = slot.MaxProximity,
            OptimalProximity = slot.OptimalProximity, Gradient = slot.Gradient,
            Facing = slot.Facing, Resolution = slot.Resolution,
        };
    }
}

public sealed class ObjectRuntimeSlot
{
    private readonly int[] _words = new int[15];

    public int? SelectorTypeKey { get; private set; }

    public int ReadWord(int byteOffset) => _words[WordIndex(byteOffset)];
    public void WriteWord(int byteOffset, int value) => _words[WordIndex(byteOffset)] = value;

    public void SetRendererSprite(short spriteId, int frameCount, bool backwards, short balloonSpriteId,
        short labelSpriteId, bool flag)
    {
        SelectorTypeKey = null;
        WriteWord(0x14, spriteId);
        WriteWord(0x18, 0);
        WriteWord(0x1c, frameCount);
        WriteWord(0x20, backwards ? frameCount - 1 : 0);
        WriteWord(0x24, backwards ? -1 : 1);
        WriteWord(0x2c, balloonSpriteId);
        WriteWord(0x30, labelSpriteId);
        WriteWord(0x38, flag ? 1 : 0);
    }

    public void SetSelectorSprite(int typeKey)
    {
        SelectorTypeKey = typeKey;
        WriteWord(0x14, -1);
        WriteWord(0x18, 0);
        WriteWord(0x1c, 1);
        WriteWord(0x20, 0);
        WriteWord(0x24, 1);
    }

    public void ActivateForTicks(int ticks)
    {
        WriteWord(0x28, 0);
        WriteWord(0x10, ticks);
    }

    public void ActivateForLoops(int loops)
    {
        WriteWord(0x28, 0);
        WriteWord(0x10, unchecked(loops * ReadWord(0x1c) * 12));
    }

    public static ObjectRuntimeSlot FromObjectSlot(Formats.Slot slot, int slotTableIndex)
    {
        ArgumentNullException.ThrowIfNull(slot);
        if (slot.Type != 1) throw new ArgumentException("Only type-1 SLOT entries initialize this runtime vector.", nameof(slot));
        if (slotTableIndex < 0) throw new ArgumentOutOfRangeException(nameof(slotTableIndex));
        var runtime = new ObjectRuntimeSlot();
        runtime.WriteWord(0x00, BitConverter.SingleToInt32Bits(slot.X));
        runtime.WriteWord(0x04, BitConverter.SingleToInt32Bits(slot.Y));
        runtime.WriteWord(0x08, BitConverter.SingleToInt32Bits(slot.Z));
        runtime.WriteWord(0x0c, slotTableIndex + 1);
        return runtime;
    }

    public bool Tick()
    {
        if (ReadWord(0x10) > 0) WriteWord(0x10, ReadWord(0x10) - 1);
        if (ReadWord(0x10) == 0) return false;

        var phase = ReadWord(0x28) + 1;
        WriteWord(0x28, phase);
        if (phase != 12) return false;

        var interval = ReadWord(0x1c);
        var progress = ReadWord(0x20) + ReadWord(0x24);
        while (progress < 0) progress += interval;
        WriteWord(0x20, progress % interval);
        WriteWord(0x28, 0);
        return true;
    }

    private static int WordIndex(int byteOffset)
    {
        if ((byteOffset & 3) != 0 || (uint)byteOffset >= 0x3c)
            throw new ArgumentOutOfRangeException(nameof(byteOffset), "Runtime-slot offsets must be aligned dwords within 0x00..0x38.");
        return byteOffset / 4;
    }
}
public readonly record struct SpecialEffectRequest(int DurationMs, byte Byte2, byte Byte3, byte Byte4, byte Byte5);

public readonly record struct AutonomySelectionContext(
    XPerson Person,
    float BaselineScore,
    float VanillaThreshold,
    uint RandomSeed);

public sealed record AutonomyCandidateSnapshot(
    XObject Target,
    short ActionIndex,
    string InteractionName,
    float Distance,
    float VanillaScore,
    float AdjustedScore,
    bool AutoFirst,
    bool JoinInteraction,
    bool BlockedByHost,
    float[] MotiveDeltas);

public interface ISimulationAutonomyHost
{
    AutonomyLot AutonomyLotState();
    float ScoreAutonomy(XPerson person, XObject target, short actionIndex, string actionName, float score) => score;
    bool DirectsAutonomy(XPerson person) => false;
    int? SelectAutonomyCandidate(AutonomySelectionContext context, IReadOnlyList<AutonomyCandidateSnapshot> candidates) => null;
}

public interface ISimulationCareerHost
{
    IReadOnlyList<int> CareerTable();
    bool CareerExists(short career);
    short? JobData(short career, short level, short field);
    bool TryGetCareerUniform(short career, short level, bool female, out string meshTemplate, out string skinTemplate)
    {
        meshTemplate = string.Empty;
        skinTemplate = string.Empty;
        return false;
    }
}

public interface ISimulationHost : ISimulationAutonomyHost, ISimulationCareerHost
{
    IReadOnlyList<short>? Constants(StackFrame frame, ushort id);
    TypeRecord? AlternativeObjectType(TypeRecord entry);
    short? Room(short room, short field);
    string? StringTableEntry(short table, int index);
    void BroadcastString(int message, string text);
    bool PlaySoundEvent(int bank, short eventId);
    bool PlayPositionalSound(short ownerId);

    void RefreshDisplay();
    void RefreshRoom(ushort room);

    bool BurnEnabled();
    TypeRecord? FindObjectType(int key);
    bool BurnFootprintClear(int tileX, int tileY, int height, short direction);
    bool BurnSpread(XObject me, ObjectPosition position, TypeRecord? fire, bool strictFlags);

    void SetObjectUiEffect(short id, bool flag);
    void ShowObjectUiEffect(short id, bool flag);
    void ShowEntryUiEffect(short id, bool flag);

    bool HasBalloonEntries(XObject owner);
    bool ClaimBalloon(XObject owner, int priority);
    void SetBalloonState(XObject owner, int value);
    void SetBalloonStateTimed(XObject owner, int count);
    void NotifyPersonObjectReference(XPerson recipient, XObject subject);
    void ShowBalloonForType(XObject owner, TypeRecord? alternative);
    int ListEntryValue(short index);
    void ShowBalloonForValue(XObject owner, int value);
    bool ShowBalloonText(byte table, int textId, int flags);
    short BalloonString(byte table, short index);
    int BalloonDuration(byte kind);
    void SetBalloonFields(XObject owner, int duration, int label, bool flag);
    void NotifyObjectTable(XObject owner);

    bool CanGrab(XObject item, ObjectPosition at, XObject? who, int flag);
    void Grab(XObject item, ObjectPosition at, XObject? who, int flag);
    bool CanDrop(XObject item, ObjectPosition at, XObject? who, int flag);
    void Drop(XObject item, ObjectPosition at, XObject? who, int flag);
    bool CanDropOnto(XObject target, ObjectPosition at, XObject? who, int flag);
    void DropOnto(XObject target, ObjectPosition at, XObject? who, int flag);

    int? DialogRecordState(XObject owner);
    void DismissDialogRecord(XObject owner);
    void DismissDialogRecords(XObject owner);
    void ShowDialog(XPerson owner, byte style);
    byte DialogGlobalFlagF8();
    SimulationDialogRecord? DialogRecordFor(SimulationWorld world, XObject owner) => world.DialogRecord(owner);
    SimulationDialogRecord? CreateDialogRecord(SimulationWorld world, XObject owner, XObject? icon, string title, string message,
        string? yes, string? no, string? cancel, byte kind, bool blocking, bool awaitsResponse)
        => world.CreateMessageDialog(owner, icon, title, message, yes, no, cancel, kind, blocking, awaitsResponse);
    void CompleteDialogRecord(SimulationWorld world, SimulationDialogRecord record) => world.CompleteDialogRecord(record);
    bool HasVisibleDialog(SimulationWorld world) => world.HasVisibleDialog;
    void SetLookTarget(XObject me, short target);
    void TurnTowards(XObject me, ObjectPosition? point);
    int TurnStatus(XObject me);
    bool TryStartTurn(XObject me);

    bool RoutingEnabled();
    int RoutingSlotCount(XObject stackObject);
    RoutingSlotRequest RoutingSlotAt(XObject stackObject, int index);
    int LotRoutingSlotCount(XObject me);
    RoutingSlotRequest LotRoutingSlotAt(XObject me, int index);
    PrimitiveResult Route(XObject me, StackFrame frame, RoutingSlotRequest? target);

    PrimitiveResult AnimateAvatar(XPerson me, StackFrame frame, ReadOnlySpan<byte> operand);
    void StopOwnerSounds(short ownerId);

    void ChangeActionString(XObject me, short stackObject, string? text);

    PrimitiveResult RunSnapshot(XObject me, XObject? target, ObjectPosition position, int snapTargetSlot, bool snapTargetFlag,
        int directionMask, bool slotFlag, (int Dy, int Dx, int Ddir)? relative);

    void SetEffectWord(short index, short value);
    bool PlaySpecialEffect(XObject me, XObject stackObject, SpecialEffectRequest request);
    bool PushInteraction(XPerson person, XObject owner, byte interactionId, int priority, XObject? secondary, int flags);

    XObject? CreateCharacter(int mode);

    int ActivePersonIndex(int position);
    short? ActivePersonRecordId(int index);
    short? StoredSlotPersonId();
    InteractionBehaviorRuntimeContext? BeginInteractionBehaviorScope(InteractionBehaviorScope scope);
    InteractionBehaviorActionList? InteractionBehaviorActions(InteractionBehaviorScope scope, int listIndex);
    void EndInteractionBehaviorScope(InteractionBehaviorScope scope, bool commit);
    void FinalizeInteractionBehaviorTypeRecord(TypeRecord? typeRecord);
    void RefreshInteractionBehaviorTypeRecord(TypeRecord? typeRecord);
    void NotifyInteractionBehaviorGlobal(uint mask);
    XPerson? GenericSimsCall20FallbackPerson(int position);
    void GenericSimsCall20FinalizePerson(XPerson person);
    void RunGenericSimsCall01InteractionPhase(XObject runner, XObject stackObject, XObject runnerContainer, XObject? stackContainer);
    void RunGenericSimsCall01RoutePhase(XObject runner, XObject stackObject, XObject runnerContainer, XObject? stackContainer);
    void GenericSimsCall22Finalize(XObject resolved);
    short? ScopedNeighborPersonRecordId(int personRecordKey);
    void PersistNeighborhoodState();
    XObject? GenericSimsCall11CallbackTarget();
    bool PassesAutonomyCallbackGate(XObject target);
    void InvokeGatedObjectCallback(XObject target, GatedObjectCallbackRequest request);
    XObject? GenericSimsCall06CallbackTarget();
    void RunGenericSimsCall11Finalize(XObject resolved, short temporary0, short temporary1, short temporary2, short temporary3);
    bool GenericSimsCallRequestManagerAvailable();
    GenericSimsCallRequestCompletion ProcessGenericSimsCallRequest(GenericSimsCallPendingRequest request, XObject target);
    void ReleaseGenericSimsCall03PrimaryHandle(int handle);
    void ReleaseGenericSimsCall03SecondaryHandle(int handle);
    void RunGenericSimsCallInitialization(int mode);
    byte[]? GenericSimsCall26StringBytes(StackFrame frame, short selector, short oneBasedIndex);
    void SelectedPersonChanged(XObject person);
    sbyte TileTransformByte(int index);
    IReadOnlyList<int> GlobalIdTable();
    XObject? CreateObjectInstance(int guidKey);
    bool TileHasObject(int tileX, int tileY, int level, int? guidKey);
    short RoomAtTile(int tileX, int tileY, int level);
    bool FacingClear(int tileX, int tileY, int level, int facing);
    bool CanPlaceCreated(XObject created, ObjectPosition at, XObject? relativeTo, int method);
    void PlaceCreated(XObject created, ObjectPosition at, XObject? relativeTo, int method);
    void DiscardObject(XObject created);
    void RotateCreatedObject(XObject created);
    void InitCreatedPerson(XPerson created);
    void ArriveCreatedPerson(XPerson created);

    bool FindLocation(XObject stackObject, FindLocationParams parameters, out ObjectPosition found);
    bool CanPlaceAt(XObject stackObject, ObjectPosition at);
    void PlaceAt(XObject stackObject, ObjectPosition at);
    void AlignMultitileParts(XObject stackObject);
    void RotateForPlacement(XObject stackObject, int steps);
    void FinishLocationSearch(XObject stackObject);
    void FinalizePlacement(XObject stackObject);
    XObject? StartQueuedAction(XPerson me, ActionQueueSlot action);

    (XObject? Holder, int Value) GrabHolder(XObject target);
    float SlotPosition(int slot);
    bool NextAvatarEvent(XPerson me, out int code);
    bool ReachAnimationDone(XPerson me);
    void FinishReach(XPerson me);
    bool StartReachAnimation(XPerson me, float position);
    bool CanPlace(XObject target, ObjectPosition at, XObject who, int flag);
    void Place(XObject target, ObjectPosition at, XObject who, int flag);
}

public readonly record struct FoundAction(int Key, short Action)
{
    public static FoundAction FromTtab(Interaction interaction)
    {
        ArgumentNullException.ThrowIfNull(interaction);
        return new FoundAction(interaction.TtaIndex, unchecked((short)interaction.ActionTree));
    }
}

public readonly record struct StateClassEntry(int State, int Class);

public record struct PersonRoomMotiveEntry(float InteriorValue, bool IsOutside)
{
    public bool NeedsRefresh { get; set; }
    public float LightLevel6c { get; set; }
    public byte LightsEnabledFlag73 { get; set; }
    public byte LightOverrideFlag75 { get; set; }
    public int LightingObjectCount140 { get; set; }
    public int PersonObjectCount142 { get; set; }
    // House panel bedroom count input (category 4 objects).
    public int HouseCategory4ObjectCount58 { get; set; }
    // House panel bathroom count input (category 5..7 objects).
    public int HouseCategory5To7ObjectCount5c { get; set; }
}

public enum RoomRefreshResult
{
    ManagerUnavailable,
    RoomNotFound,
    Refreshed,
}

public sealed class GlobalPersonState
{
    public byte ByteE0 { get; set; }
    public byte ByteE1 { get; set; }
    public short LotUpkeepMatchWord22 { get; set; }
}

public sealed class GenericSimsCall03ManagerState
{
    public int PrimaryHandle { get; set; }
    public int SecondaryHandle { get; set; }
    public int? LinkedGlobalWord60 { get; set; }
}

public readonly record struct PersonRecordSelection(XObject? Person);

public sealed class SimulationNoticeListener(Func<int, int, bool> callback)
{
    public Func<int, int, bool> Callback { get; } = callback ?? throw new ArgumentNullException(nameof(callback));
    public SimulationNoticeListener? Next { get; set; }
}

public sealed record SimulationUiMessage(long Sequence, int Message, string Text);


public readonly record struct ThreadFrameError(short Tree, int Instruction, ushort? Opcode, short StackObject,
    short[] Parameters, short[] Locals, short CodeOwner, string? TreeLabel = null, int? TableObjectKey = null,
    string? ResourceScope = null, byte? TrueTarget = null, byte? FalseTarget = null, string? Operand = null,
    short? ResolvedStackObjectId = null, int? ResolvedStackObjectTypeKey = null, bool? ResolvedStackObjectIsPerson = null);

public readonly record struct AutonomyAttemptDiagnostic(short PersonId, bool Forced, bool GatePassed,
    int CandidatesVisited, int InteractionRecords, int PassedRecords, int ZeroAdvertisementRecords,
    int BelowThresholdRecords, int ScoredRecords, float? MaximumScore, float? MaximumScoreBaseline,
    float? MaximumScoreAdvertisement, short? MaximumScoreObjectId, short? MaximumScoreAction,
    MotiveAdvertisement[]? MaximumScoreMotives, float? MaximumAbsoluteMotiveDelta, short? MaximumDeltaObjectId,
    short? MaximumDeltaAction, MotiveAdvertisement[]? MaximumDeltaMotives, int? MaximumRawAdvertisement,
    short? MaximumRawAdvertisementObjectId, short? MaximumRawAdvertisementAction, short? ChosenObjectId, short? Action);

public readonly record struct SimulationTraceEntry(short ObjectId, short Tree, int Instruction, ushort Opcode,
    string Operand, short StackObject, short[] ActorTemporaries, short[] Parameters, short[] Locals);

public readonly record struct SimulationPrimitiveResultTrace(short ObjectId, short Tree, int Instruction, ushort Opcode,
    PrimitiveResult Result, short[] Parameters, short CodeOwner = 0);

public readonly record struct SimulationRouteCandidateTrace(short ActorId, short AnchorId, ObjectPosition Position,
    ushort Room, int Direction, bool PlacementAccepted, int PlacementFailureCode, short BlockingObjectId, bool Selected,
    string FailureReason);

public readonly record struct SimulationNativeRouteTrace(short ActorId, short AnchorId, ObjectPosition Destination,
    string Phase, string? Failure);

public readonly record struct SimulationRouteSearchTrace(short ActorId, ObjectPosition Destination,
    (int X, int Y) StartTile, (int X, int Y) EndTile, ushort StartRoom, ushort EndRoom, int VisitedTiles,
    int RejectedPlacements, int RejectedEdges, string VisitedRooms);

public readonly record struct SimulationTreeCallTrace(short ObjectId, short CallerTree, int Instruction, short CalleeTree,
    short[]? Parameters);

public readonly record struct SimulationNamedTreeLookupTrace(short ObjectId, short StackObjectId, short CallerTree,
    int Instruction, short StringTable, byte StringNumber, string? Name, int? ScopeKey, short ResolvedTree);

public readonly record struct SimulationInteractionTestTrace(short PersonId, short Tree, int Instruction, byte Mode,
    short StackObjectKey, short[] InteractingObjectIds, short[] InteractingStackKeys, bool Result);

public readonly record struct SimulationMissingAnimationTrace(short PersonId, short Tree, int Instruction, byte Source,
    short AnimationId, byte Mode, int? TargetGuid, ushort? TableId);

public readonly record struct ThreadError(short ObjectId, string Message, short[]? ActorTemporaries = null,
    ThreadFrameError[]? Frames = null);

public readonly record struct InteractionGuardError(short PersonId, short ObjectId, int InteractionId,
    int GuardTree, SimulationError Error, string Message);
