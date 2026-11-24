using SimsEngine.Character;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsNative.Plugins;

namespace SimsSimulation;

internal sealed class PluginWorld(
    Func<SimulationWorld?> world,
    Func<short> house,
    Func<ushort?> family,
    Func<ObjectRegistry?> registry,
    Func<bool> paused,
    Func<IffFile?>? lot = null,
    Func<int>? lotSize = null,
    Func<XPerson, bool>? wearingOutdoorSuit = null,
    Func<XPerson, char, int, string?>? resolveSimSuit = null,
    Action<short, string?, bool>? setSimAppearanceOverride = null,
    Func<bool>? awayLot = null,
    Func<int>? familyFriends = null) : IPluginSimulation, PluginHost.IPluginWorld
{
    private const int AutonomousPriority = 2;
    private static readonly HashSet<int> ChangeableMotives = [5, 6, 7, 8, 9, 14, 15];
    private Func<short, PluginObject, PluginInteraction, bool> interactionAllowed = (_, _, _) => true;
    private readonly Dictionary<uint, Dictionary<int, string>> englishInteractionCache = [];
    private ObjectRegistry? cachedEnglishRegistry;

    private SimulationWorld World => world() ?? throw new InvalidOperationException("No native lot is loaded");

    public short House => house();
    public int Hours => World.Clock.Hour;
    public int Minutes => World.Clock.Minute;
    public bool Paused => paused();
    public int HouseholdFunds => world()?.FamilyBudget?.ReadFamilyBudget() ?? 0;
    public bool FreeWill => World.AutonomyForced ?? (World[SimulationGlobal.FreeWill] != 0);
    public bool AwayLot => awayLot?.Invoke() ?? (House is >= 21 and <= 99);

    private IEnumerable<XPerson> Persons() => World.Objects.Values.OfType<XPerson>();

    private IEnumerable<XPerson> Household() => family() is { } chunk
        ? Persons().Where(person => person[PersonData.IsGhost] == 0 && (ushort)person[PersonData.FamilyNumber] == chunk)
        : [];

    private XPerson HouseholdSim(short objectId) => Household().FirstOrDefault(person => person.Id == objectId)
        ?? throw new ArgumentException("Only household Sims on this lot can be read or changed");

    internal void SetInteractionFilter(Func<short, PluginObject, PluginInteraction, bool> filter) => interactionAllowed = filter;

    private string Name(XPerson person) =>
        !string.IsNullOrWhiteSpace(person.Name) ? person.Name
        : person.TypeRecord?.CatalogName is { } catalogName && !string.IsNullOrWhiteSpace(catalogName) ? catalogName
        : World.Neighbors.TryGetValue(person[PersonData.NeighborId], out var neighbor) && !string.IsNullOrWhiteSpace(neighbor.Name) ? neighbor.Name!
        : person.TypeRecord?.Name ?? "";

    public IReadOnlyList<PluginSim> HouseholdSims => Household()
        .Select(person => new PluginSim(person.Id, person[PersonData.NeighborId], Name(person), PersonAgeCategory.IsChild(person[PersonData.PersonAge]))
        {
            Animation = person.AnimationPlayback?.Clip.Name,
            WearingOutdoorSuit = wearingOutdoorSuit?.Invoke(person) ?? false,
        })
        .ToArray();

    public IReadOnlyList<string> GetQueuedActions(short simId)
    {
        var person = HouseholdSim(simId);
        var actions = new List<ActionQueueSlot>();
        if (person.CurrentActionRecord is { } current) actions.Add(current);
        actions.AddRange(person.ActionQueue.Where(action => action.Owner is not null));
        return actions.Select(action => action.ActionText ?? action.Owner?.TypeRecord?.Interactions?.Interactions
                .FirstOrDefault(entry => entry.TtaIndex == action.RawDword10)?.Name ?? "")
            .Where(name => !string.IsNullOrWhiteSpace(name)).ToArray();
    }

    public short GetMotive(short objectId, int motive)
    {
        if (motive is < 0 or > 15) throw new ArgumentOutOfRangeException(nameof(motive));
        return (short)HouseholdSim(objectId).Motives[motive];
    }

    public short ChangeMotive(short simId, int motive, int delta)
    {
        if (!ChangeableMotives.Contains(motive)) throw new ArgumentOutOfRangeException(nameof(motive), "Only the needs can be changed");
        if (delta is < -100 or > 100) throw new ArgumentOutOfRangeException(nameof(delta));
        var sim = HouseholdSim(simId);
        var value = (short)Math.Clamp((short)sim.Motives[motive] + delta, -100, 100);
        sim.Motives[motive] = value;
        return value;
    }

    private bool Outside(XObject item) => World.RoomIsOutside(World.RoomAtTile(item.Position.X >> 4, item.Position.Y >> 4, item.Position.Height));

    private bool Sheltered(XObject item) =>
        lot?.Invoke() is { } currentLot && world() is { } currentWorld &&
        SceneExporter.IsShelteredAt(currentLot, currentWorld, lotSize?.Invoke() ?? 64, item.Position);

    internal string? ResolveEnglishInteractionName(XObject target, int ttaIndex)
    {
        var guid = unchecked((uint)(target.TypeRecord?.Key ?? 0));
        if (guid == 0) return null;
        var activeRegistry = registry();
        if (!ReferenceEquals(activeRegistry, cachedEnglishRegistry))
        {
            englishInteractionCache.Clear();
            cachedEnglishRegistry = activeRegistry;
        }
        if (activeRegistry is null) return null;
        if (!englishInteractionCache.TryGetValue(guid, out var map))
        {
            map = [];
            try
            {
                if (activeRegistry.Find(guid) is { } entry &&
                    entry.FindInteractionTable(
                        target.TypeRecord?.BehaviorScope as BehaviorScope,
                        language: 1,
                        activeRegistry.FindAlternativeType(entry)) is { } table)
                {
                    foreach (var item in table.Interactions)
                        if (!string.IsNullOrWhiteSpace(item.Name))
                            map[item.TtaIndex] = item.Name!;
                }
            }
            catch (Exception ex) when (ex is ResourceFormatException or NotSupportedException or InvalidDataException) { }
            englishInteractionCache[guid] = map;
        }
        return map.GetValueOrDefault(ttaIndex);
    }

    private static short DefWord(XObject item, int index) =>
        index >= 0 && index < item.Definition.Length ? item.Definition[index] : (short)0;

    internal PluginObject Describe(XObject item) => Describe(item, null);

    private PluginObject Describe(XObject item, SceneExporter.ShelterQuery? shelter)
    {
        var currentWorld = World;
        var root = item.MultiTileMasterId != 0 ? (currentWorld.ObjectById(item.MultiTileMasterId) ?? item) : item;
        var useCount = Math.Max(item[ObjectData.UseCount], root[ObjectData.UseCount]);
        var dirtyLevel = Math.Max(item[ObjectData.DirtyLevel], root[ObjectData.DirtyLevel]);
        var repairState = item[ObjectData.RepairState] != 0 ? item[ObjectData.RepairState] : root[ObjectData.RepairState];
        if (ReferenceEquals(item, root) && item.MultiTileNextId != 0)
        {
            var seen = new HashSet<short> { item.Id };
            for (var nextId = item.MultiTileNextId; nextId != 0 && seen.Add(nextId); )
            {
                if (currentWorld.ObjectById(nextId) is not { } part) break;
                useCount = Math.Max(useCount, part[ObjectData.UseCount]);
                dirtyLevel = Math.Max(dirtyLevel, part[ObjectData.DirtyLevel]);
                if (repairState == 0 && part[ObjectData.RepairState] != 0)
                    repairState = part[ObjectData.RepairState];
                nextId = part.MultiTileNextId;
            }
        }
        var roomId = item.Position.X >= 0 && item.Position.Y >= 0
            ? currentWorld.RoomAtTile(item.Position.X >> 4, item.Position.Y >> 4, item.Position.Height)
            : item[ObjectData.Room];

        return new(item.Id,
            unchecked((uint)(item.TypeRecord?.Key ?? 0)), item is XPerson person ? Name(person) : item.TypeRecord?.Name ?? "",
            item.Position.X >> 4, item.Position.Y >> 4, item.Position.Height, root.Id)
        {
            Outside = currentWorld.RoomIsOutside(roomId),
            Sheltered = shelter is { } s ? s.IsSheltered(item.Position) : Sheltered(item),
            RoomId = roomId,
            UseCount = useCount,
            DirtyLevel = dirtyLevel,
            RepairState = repairState,
            Category = item[ObjectData.Category] != 0 ? item[ObjectData.Category] : root[ObjectData.Category],
            Price = unchecked((ushort)DefWord(root, (int)ObjdField.Price)),
            FunctionFlags = DefWord(root, (int)ObjdField.FunctionFlags) & 0xff,
            FunctionSubsort = unchecked((ushort)DefWord(root, (int)ObjdField.FunctionSubsort)),
            RoomSort = unchecked((ushort)DefWord(root, (int)ObjdField.RoomSort)),
            SkillFlags = DefWord(root, 0x59) & 0xff,
            RatingHunger = DefWord(root, 0x52),
            RatingComfort = DefWord(root, 0x53),
            RatingHygiene = DefWord(root, 0x54),
            RatingBladder = DefWord(root, 0x55),
            RatingEnergy = DefWord(root, 0x56),
            RatingFun = DefWord(root, 0x57),
            RatingRoom = DefWord(root, 0x58),
            PrepValue = Math.Max(item[ObjectData.PrepValue], root[ObjectData.PrepValue]),
            CookValue = Math.Max(item[ObjectData.CookValue], root[ObjectData.CookValue]),
            SurfaceValue = Math.Max(item[ObjectData.SurfaceValue], root[ObjectData.SurfaceValue]),
            DisposeValue = Math.Max(item[ObjectData.DisposeValue], root[ObjectData.DisposeValue]),
            WashDishValue = Math.Max(item[ObjectData.WashDishValue], root[ObjectData.WashDishValue]),
            EatingSurfaceValue = Math.Max(item[ObjectData.EatingSurfaceValue], root[ObjectData.EatingSurfaceValue]),
            ServingSurfaceValue = Math.Max(item[ObjectData.ServingSurfaceValue], root[ObjectData.ServingSurfaceValue]),
            GardeningValue = Math.Max(item[ObjectData.GardeningValue], root[ObjectData.GardeningValue]),
            WashHandsValue = Math.Max(item[ObjectData.WashHandsValue], root[ObjectData.WashHandsValue]),
            PrimaryAttribute = root.Attributes.Length > 0 ? root.Attributes[0] : (item.Attributes.Length > 0 ? item.Attributes[0] : (short)0),
            AttributeCount = item.Attributes.Length,
            IsPerson = item is XPerson,
        };
    }

    public IReadOnlyList<PluginObject> Objects
    {
        get
        {
            var currentWorld = World;
            var shelter = SceneExporter.CaptureShelterQuery(lot?.Invoke(), currentWorld, lotSize?.Invoke() ?? 64);
            var values = currentWorld.Objects.Values;
            var result = new PluginObject[values.Count];
            var index = 0;
            foreach (var item in values)
                result[index++] = Describe(item, shelter);
            return result;
        }
    }

    private PluginInteraction DescribeInteraction(XPerson sim, XObject target, ActionQueueSlot action)
    {
        var tableEntry = World.EffectiveInteractions(target)?.Interactions
            .FirstOrDefault(entry => entry.TtaIndex == action.RawDword10);
        float[] deltas;
        if (action.EvaluatedAdvertisements is { } evaluated)
        {
            deltas = FindBestInteractionPrimitive.EvaluateMotiveDeltas(sim, evaluated);
        }
        else if (tableEntry is not null)
        {
            var record = InteractionRecord.FromTtab(tableEntry, passed: true);
            deltas = FindBestInteractionPrimitive.EvaluateMotiveDeltas(sim, record.Advertisement);
        }
        else
        {
            deltas = new float[16];
        }
        return new PluginInteraction(action.RawDword10, action.ActionText ?? tableEntry?.Name ?? "", action.Parameters[0], false)
        {
            EnglishName = ResolveEnglishInteractionName(target, action.RawDword10) ?? tableEntry?.Name ?? action.ActionText,
            AutonomyThreshold = tableEntry is null ? 100 : (int)tableEntry.AutonomyThreshold,
            AutoFirst = tableEntry is not null && (tableEntry.Flags & 0x100) != 0,
            Joinable = tableEntry is not null && (tableEntry.Flags & 2) != 0,
            MotiveDeltas = deltas,
        };
    }

    public IReadOnlyList<PluginInteraction> GetInteractions(short simId, short objectId)
    {
        var sim = HouseholdSim(simId);
        var clicked = World.ObjectById(objectId) ?? throw new ArgumentException($"No object {objectId} on this lot");
        var target = InteractionMenus.Target(World, clicked);
        if (target.Position.X < 0 || target.Position.Y < 0) return [];
        var described = Describe(target);
        return InteractionMenus.Read(World, sim, target)
            .Select(action => DescribeInteraction(sim, target, action))
            .Where(entry => interactionAllowed(simId, described, entry)).ToArray();
    }

    public IReadOnlyList<string> GetDefinedInteractions(short objectId)
    {
        var item = World.ObjectById(objectId) ?? throw new ArgumentException($"No object {objectId} on this lot");
        var interactions = item.TypeRecord?.Interactions?.Interactions;
        if (interactions is null || interactions.Count == 0)
            return [];
        return interactions
            .Select(static entry => entry.Name)
            .Where(static name => !string.IsNullOrWhiteSpace(name))
            .Select(static name => name!)
            .ToArray();
    }

    public bool TryQueueInteraction(short simId, short objectId, int interactionId, short param0 = 0, bool global = false)
    {
        if (global || interactionId is < 0 or > byte.MaxValue || World.HasVisibleBlockingDialog) return false;
        var sim = HouseholdSim(simId);
        var clicked = World.ObjectById(objectId);
        if (clicked is null) return false;
        var target = InteractionMenus.Target(World, clicked);
        var described = Describe(target);
        var choice = InteractionMenus.Read(World, sim, target).FirstOrDefault(action =>
            action.RawDword10 == interactionId && action.Parameters[0] == param0);
        if (choice is null) return false;
        var offered = DescribeInteraction(sim, target, choice);
        return interactionAllowed(simId, described, offered) && World.EnqueueInteractionAction(sim, choice);
    }

    private static bool HasPlayerOrderedWork(XPerson sim)
    {
        if (sim.CurrentActionRecord is { Owner: not null } active &&
            (active.Threshold > AutonomousPriority || sim.ActivePriority > AutonomousPriority))
            return true;
        var current = sim.ActionQueueCurrent;
        var end = sim.ActionQueueEnd;
        for (var idx = current; unchecked((uint)(idx - current)) < unchecked((uint)(end - current)) && idx - current < 8; idx++)
        {
            var slot = sim.ActionQueue[idx & 7];
            if (slot.Owner is not null && slot.Threshold > AutonomousPriority)
                return true;
        }
        return false;
    }

    public bool TryQueueAutonomousInteraction(short simId, short objectId, int interactionId, short param0 = 0)
    {
        if (!FreeWill || interactionId is < 0 or > byte.MaxValue || World.HasVisibleBlockingDialog) return false;
        var sim = HouseholdSim(simId);
        if (sim[PersonData.IsPersonAtWorkSchool] != 0 || sim[PersonData.JobData] != 0) return false;
        if (HasPlayerOrderedWork(sim)) return false;
        var clicked = World.ObjectById(objectId);
        if (clicked is null) return false;
        var target = InteractionMenus.Target(World, clicked);
        if (target.Position.X < 0 || target.Position.Y < 0 || target[ObjectData.LockoutCount] >= 1) return false;
        var described = Describe(target);
        var choice = InteractionMenus.Read(World, sim, target).FirstOrDefault(action =>
            action.RawDword10 == interactionId && action.Parameters[0] == param0);
        if (choice is null) return false;
        var offered = DescribeInteraction(sim, target, choice);
        if (!interactionAllowed(simId, described, offered)) return false;
        choice.Threshold = AutonomousPriority;
        return World.EnqueueInteractionAction(sim, choice);
    }

    public bool TryCancelAutonomousAction(short simId)
    {
        if (!FreeWill || World.HasVisibleBlockingDialog) return false;
        var sim = HouseholdSim(simId);
        if (sim[PersonData.NonInterruptible] != 0 || HasPlayerOrderedWork(sim)) return false;
        if (sim.CurrentActionRecord is not { Owner: not null } current) return false;
        if (current.Threshold > AutonomousPriority || sim.ActivePriority > AutonomousPriority) return false;
        return World.CancelInteractionAction(sim, current.Sequence);
    }

    public bool TryShowSimBalloon(
        short simId,
        PluginBalloonStyle style,
        short? targetObjectId = null,
        int? spriteId = null,
        bool crossedOut = false,
        int durationTicks = 90)
    {
        if (world() is not { } currentWorld) return false;
        var person = Persons().FirstOrDefault(p => p.Id == simId && p[PersonData.IsGhost] == 0);
        if (person is null || person.RuntimeSlots.Count == 0) return false;
        if (person[PersonData.IsPersonAtWorkSchool] != 0 || person[PersonData.JobData] != 0) return false;

        var slot = person.RuntimeSlots[0];
        if (slot.ReadWord(0x10) != 0 && (slot.ReadWord(0x34) >= 2 || slot.ReadWord(0x14) is >= 800 and <= 829))
            return false;

        short balloonSpriteId = style switch
        {
            PluginBalloonStyle.Thought => 100,
            PluginBalloonStyle.Scream => 101,
            PluginBalloonStyle.Speech => 102,
            _ => 0,
        };
        short labelSpriteId = crossedOut ? (short)103 : (short)0;
        var ticks = Math.Clamp(durationTicks, 15, 240);

        if (targetObjectId is { } objId)
        {
            var clicked = currentWorld.ObjectById(objId);
            if (clicked is null) return false;
            var root = clicked.MultiTileMasterId != 0
                ? (currentWorld.ObjectById(clicked.MultiTileMasterId) ?? clicked)
                : clicked;
            if (root.TypeRecord is not { } type) return false;
            var typeKey = type.AlternativeTypeKey ?? ResolveBalloonMasterTypeKey(currentWorld, type.Key);
            if (typeKey == 0) return false;

            slot.WriteWord(0x34, 1);
            slot.SetSelectorSprite(typeKey);
            slot.WriteWord(0x2c, balloonSpriteId);
            slot.WriteWord(0x30, labelSpriteId);
            slot.WriteWord(0x38, 1);
            slot.ActivateForTicks(ticks);
            currentWorld.DisplayRefreshRequested = true;
            return true;
        }

        if (spriteId is { } sprId and > 0 and <= ushort.MaxValue)
        {
            var spritesFile = currentWorld.GlobalSprites;
            var chunk = spritesFile?.Find(ResourceType.Spr1, (ushort)sprId);
            if (chunk is null) return false;
            var frameCount = Sprite.Read(spritesFile!, chunk).Frames.Count / 3;
            if (frameCount <= 0) return false;

            slot.WriteWord(0x34, 1);
            slot.SetRendererSprite((short)sprId, frameCount, backwards: false, balloonSpriteId, labelSpriteId, flag: true);
            slot.ActivateForTicks(ticks);
            currentWorld.DisplayRefreshRequested = true;
            return true;
        }

        return false;
    }

    private int ResolveBalloonMasterTypeKey(SimulationWorld currentWorld, int typeKey)
    {
        var loadedType = currentWorld.WalkOrder.Select(item => item.TypeRecord).FirstOrDefault(type => type?.Key == typeKey);
        if (loadedType?.AlternativeTypeKey is { } loadedAlternative) return loadedAlternative;
        var objectReg = registry();
        var entry = objectReg?.Find(unchecked((uint)typeKey));
        var alternative = entry is null ? null : objectReg?.FindAlternativeType(entry);
        return alternative is null ? typeKey : unchecked((int)alternative.Guid);
    }

    private PluginQueuedAction DescribeQueuedAction(ActionQueueSlot slot, short fallbackPriority)
    {
        var target = slot.Owner is null ? null : InteractionMenus.Target(World, slot.Owner);
        var tableEntry = target is null
            ? null
            : World.EffectiveInteractions(target)?.Interactions.FirstOrDefault(entry => entry.TtaIndex == slot.RawDword10);
        var name = slot.ActionText ?? tableEntry?.Name ?? "";
        var english = target is null ? name : (ResolveEnglishInteractionName(target, slot.RawDword10) ?? tableEntry?.Name ?? name);
        var priority = (short)Math.Max(slot.Threshold, fallbackPriority);
        return new PluginQueuedAction(
            slot.Sequence,
            target?.Id ?? slot.Owner?.Id ?? 0,
            unchecked((uint)(target?.TypeRecord?.Key ?? slot.Owner?.TypeRecord?.Key ?? 0)),
            slot.RawDword10,
            slot.Parameters.Length > 0 ? slot.Parameters[0] : (short)0,
            name,
            english,
            priority,
            priority <= AutonomousPriority);
    }

    private PluginSimCareer? DescribeCareer(XPerson person, int cachedFamilyFriends)
    {
        if (person[PersonData.PersonType] is < 0 or > 1 || person[PersonData.Gender] >= 2) return null;
        var isSchool = PersonAgeCategory.IsChild(person[PersonData.PersonAge]);
        var jobType = person[PersonData.JobType];
        var level = person[PersonData.JobPromotionLevel];
        var performance = person[PersonData.JobPerformance];
        var career = World.CareerHost;
        if (isSchool)
        {
            return new PluginSimCareer(
                JobType: jobType,
                JobLevel: level,
                JobPerformance: performance,
                IsSchool: true,
                StartHour: 8,
                EndHour: 15,
                Salary: 0,
                FriendsRequired: 0,
                FamilyFriends: cachedFamilyFriends,
                SkillRequirements: new short[6]);
        }
        if (jobType == 0 || career?.CareerExists(jobType) != true)
        {
            return new PluginSimCareer(
                JobType: 0,
                JobLevel: 0,
                JobPerformance: performance,
                IsSchool: false,
                StartHour: null,
                EndHour: null,
                Salary: 0,
                FriendsRequired: 0,
                FamilyFriends: cachedFamilyFriends,
                SkillRequirements: new short[6]);
        }
        var salary = (int?)(career.JobData(jobType, level, 1));
        var startHour = (int?)(career.JobData(jobType, level, 12));
        var endHour = (int?)(career.JobData(jobType, level, 13));
        var nextLevel = (short)(level + 1);
        var hasNext = career.JobData(jobType, nextLevel, 0) is not null &&
                      career.JobData(jobType, nextLevel, 2) is not null;
        var friendsReq = hasNext ? (int)(career.JobData(jobType, nextLevel, 2) ?? 0) : 0;
        var skillReq = new short[6];
        if (hasNext)
        {
            for (var i = 0; i < 6; i++)
                skillReq[i] = career.JobData(jobType, nextLevel, (short)(i + 3)) ?? 0;
        }
        return new PluginSimCareer(
            JobType: jobType,
            JobLevel: level,
            JobPerformance: performance,
            IsSchool: false,
            StartHour: startHour,
            EndHour: endHour,
            Salary: salary,
            FriendsRequired: friendsReq,
            FamilyFriends: cachedFamilyFriends,
            SkillRequirements: skillReq);
    }

    public IReadOnlyList<PluginSimProfile> AllSims
    {
        get
        {
            var currentWorld = World;
            var familyChunk = family();
            var friendsCount = familyFriends?.Invoke() ?? 0;
            var result = new List<PluginSimProfile>();
            foreach (var person in Persons())
            {
                if (person[PersonData.IsGhost] != 0) continue;
                var gender = person[PersonData.Gender];
                var isDog = (gender & 2) != 0;
                var isCat = (gender & 4) != 0;
                var isChild = !isDog && !isCat && PersonAgeCategory.IsChild(person[PersonData.PersonAge]);
                var personType = person[PersonData.PersonType];
                var isHousehold = familyChunk is { } chunk && (ushort)person[PersonData.FamilyNumber] == chunk;
                var isNpc = !isHousehold && personType >= 2;
                var isVisitor = !isHousehold && !isNpc;
                var motives = new short[16];
                for (var m = 0; m < 16; m++)
                    motives[m] = (short)Math.Clamp((int)MathF.Round(person.Motives[m]), -100, 100);
                var active = person.CurrentActionRecord is { Owner: not null } cur
                    ? DescribeQueuedAction(cur, person.ActivePriority)
                    : null;
                var queue = new List<PluginQueuedAction>();
                var qCur = person.ActionQueueCurrent;
                var qEnd = person.ActionQueueEnd;
                for (var idx = qCur; unchecked((uint)(idx - qCur)) < unchecked((uint)(qEnd - qCur)) && idx - qCur < 8; idx++)
                {
                    var slot = person.ActionQueue[idx & 7];
                    if (slot.Owner is not null)
                        queue.Add(DescribeQueuedAction(slot, 0));
                }
                var roomId = person.Position.X >= 0 && person.Position.Y >= 0
                    ? currentWorld.RoomAtTile(person.Position.X >> 4, person.Position.Y >> 4, person.Position.Height)
                    : person[ObjectData.Room];

                result.Add(new PluginSimProfile(
                    ObjectId: person.Id,
                    NeighborId: person[PersonData.NeighborId],
                    Guid: unchecked((uint)(person.TypeRecord?.Key ?? 0)),
                    Name: Name(person),
                    Household: isHousehold,
                    Visitor: isVisitor,
                    Npc: isNpc,
                    Child: isChild,
                    Dog: isDog,
                    Cat: isCat,
                    Greeted: isHousehold || person[PersonData.GreetStatus] != 0,
                    X: person.Position.X >> 4,
                    Y: person.Position.Y >> 4,
                    Level: person.Position.Height,
                    RoomId: roomId,
                    Outside: Outside(person),
                    Sheltered: Sheltered(person),
                    Sitting: person[PersonData.Sitting] != 0,
                    Asleep: person.Motives[(int)Motive.SleepState] < 0,
                    AtWorkOrSchool: person[PersonData.IsPersonAtWorkSchool] != 0 || person[PersonData.JobData] != 0,
                    Priority: Math.Max(person[PersonData.Priority], person.ActivePriority),
                    NonInterruptible: person[PersonData.NonInterruptible] != 0,
                    RouteResult: person[PersonData.RouteResult],
                    Neat: person[PersonData.NeatQuietPersonality],
                    Outgoing: person[PersonData.OutgoingFriendlyPersonality],
                    Active: person[PersonData.ActivePlayfulPersonality],
                    Playful: person[PersonData.PlayfulSmartPersonality],
                    Nice: person[PersonData.NiceLoyalPersonality],
                    Cooking: person[PersonData.CookingHouseBrokenSkill],
                    Mechanical: person[PersonData.MechanicalTricksSkill],
                    Charisma: person[PersonData.CharismaObedienceSkill],
                    Body: person[PersonData.BodyFurnitureSkill],
                    Logic: person[PersonData.LogicSkill],
                    Creativity: person[PersonData.CreativitySkill],
                    Cleaning: person[PersonData.CleaningSkill],
                    Motives: motives,
                    Career: isHousehold ? DescribeCareer(person, friendsCount) : null,
                    CurrentAction: active,
                    ActionQueue: queue)
                {
                    Gender = (short)(gender & 1),
                    FemalePreference = person[PersonData.FemalePreferenceHotDate],
                    MalePreference = person[PersonData.MalePreferenceHotDate],
                    RomanceInterest = person[PersonData.IRomanceHotDate],
                    PartyInterest = person[PersonData.IPartiesHotDate],
                    MusicInterest = person[PersonData.IMusic],
                    TechInterest = person[PersonData.ITechnologyHotDate],
                });
            }
            return result;
        }
    }

    public IReadOnlyList<PluginSimRelationship> GetRelationships(short simId)
    {
        var currentWorld = World;
        var person = Persons().FirstOrDefault(candidate => candidate.Id == simId && candidate[PersonData.IsGhost] == 0)
            ?? throw new ArgumentException($"Sim {simId} is not on this lot");
        if (!currentWorld.Neighbors.TryGetValue(person[PersonData.NeighborId], out var owner))
            return [];
        var familyChunk = family();
        var liveByNeighbor = Persons()
            .Where(p => p[PersonData.IsGhost] == 0 && p[PersonData.NeighborId] > 0)
            .GroupBy(p => p[PersonData.NeighborId])
            .ToDictionary(g => g.Key, g => g.First());
        var list = new List<PluginSimRelationship>();
        foreach (var pair in owner.Relationships.Snapshot())
        {
            if (pair.Key is <= 0 or > short.MaxValue) continue;
            var targetId = (short)pair.Key;
            if (targetId == owner.Id || !currentWorld.Neighbors.TryGetValue(targetId, out var target)) continue;
            var daily = pair.Value.Count > 0 ? pair.Value[0] : 0;
            var crush = pair.Value.Count > 1 && pair.Value[1] != 0;
            var lifetime = pair.Value.Count > 2 ? pair.Value[2] : 0;
            var love = pair.Value.Count > 3 && pair.Value[3] != 0;
            var reverseDaily = target.Relationships.Count(owner.Id) > 0 ? target.Relationships.Get(owner.Id, 0) : 0;
            var live = liveByNeighbor.GetValueOrDefault(targetId);
            var isHousehold = live is not null
                ? familyChunk is { } chunk && (ushort)live[PersonData.FamilyNumber] == chunk
                : familyChunk is { } fChunk && (ushort)target.PersonData.ElementAtOrDefault((int)PersonData.FamilyNumber) == fChunk;
            var targetName = live is not null ? Name(live) : (target.Name ?? "");
            var mutual = daily >= currentWorld.FriendshipThreshold && reverseDaily >= currentWorld.FriendshipThreshold;
            list.Add(new PluginSimRelationship(
                TargetNeighborId: targetId,
                TargetObjectId: live?.Id,
                TargetName: targetName,
                Household: isHousehold,
                Daily: daily,
                ReverseDaily: reverseDaily,
                Lifetime: lifetime,
                MutualFriend: mutual,
                Crush: crush,
                Love: love));
        }
        return list;
    }

    public bool TryCharge(int amount)
    {
        if (world()?.FamilyBudget is not { } budget || amount <= 0 || amount > budget.ReadFamilyBudget()) return false;
        budget.AlterFamilyBudget(0, amount);
        return true;
    }

    public bool TryPay(int amount)
    {
        if (world()?.FamilyBudget is not { } budget || amount <= 0 || amount > 100_000 || budget.ReadFamilyBudget() > int.MaxValue - amount) return false;
        budget.AlterFamilyBudget(0, -amount);
        return true;
    }

    public PluginEnvironmentClock Clock(int house, int mapMode)
    {
        if (world() is not { } currentWorld) return new PluginEnvironmentClock(house, mapMode, 0, 0, 720, []);
        var currentLot = lot?.Invoke();
        var size = lotSize?.Invoke() ?? 64;
        var shelter = SceneExporter.CaptureShelterQuery(currentLot, currentWorld, size);
        var actors = Persons().Select(person => new PluginActor(person.Id, person.Position.X / 16f, person.Position.Y / 16f,
            person.Position.Height, false, PersonAgeCategory.IsChild(person[PersonData.PersonAge]), false)
        {
            Outside = Outside(person),
            Sheltered = shelter.IsSheltered(person.Position),
            WearingOutdoorSuit = wearingOutdoorSuit?.Invoke(person) ?? false,
        }).ToArray();
        return new PluginEnvironmentClock(house, mapMode, currentWorld.CurrentDate?.Month ?? 0, currentWorld.CurrentDate?.Day ?? 0,
            currentWorld.Clock.Hour * 60 + currentWorld.Clock.Minute, actors);
    }

    private XObject LotObject(short objectId, int? index)
    {
        var item = World.ObjectById(objectId) ?? throw new ArgumentException("Object no longer exists");
        if (index is { } attribute && (attribute < 0 || attribute >= item.Attributes.Length))
            throw new ArgumentOutOfRangeException(nameof(index));
        return item;
    }

    private readonly Dictionary<short, string> placedObjectOwners = new();

    private static bool IsPackOrBaseGameObject(string? source, string packId)
    {
        if (source is null) return false;
        var normalized = source.Replace('\\', '/');
        if (normalized.Contains("/Downloads/" + packId + "/", StringComparison.OrdinalIgnoreCase))
            return true;
        return !normalized.Contains("/Downloads/", StringComparison.OrdinalIgnoreCase);
    }

    public short? TryPlaceOwnedObject(string packId, uint guid, int tileX, int tileY, int level, short direction, short? clearForSimId)
    {
        if (world() is not { } currentWorld || level < 1) return null;
        var source = registry()?.Find(guid)?.Source;
        if (!IsPackOrBaseGameObject(source, packId))
            throw new ArgumentException("Only this pack's own or base game objects may be placed");
        using var savedTypes = currentWorld.BeginSavedObjectTypeRegistrationScope();
        var group = currentWorld.ObjectGroupFactory?.Invoke(unchecked((int)guid));
        if (group is { Count: 0 }) return null;
        XObject root;
        if (group is { Count: > 0 })
        {
            root = group[0];
        }
        else
        {
            if (currentWorld.ObjectFactory?.Invoke(unchecked((int)guid)) is not { } single) return null;
            currentWorld.Add(single);
            currentWorld.InitializeCreatedObject(single);
            group = [single];
            root = single;
        }
        var actor = clearForSimId is { } simId ? currentWorld.ObjectById(simId) as XPerson : null;
        var maxCoord = (lotSize?.Invoke() ?? 64) - 2;
        var placed = false;
        try
        {
            var baseFacing = (short)(direction & 6);
            var facings = actor is not null
                ? new short[] { 0, 2, 4, 6 }.OrderBy(d =>
                {
                    var spotPxX = tileX * 16 + 8;
                    var spotPxY = tileY * 16 + 8;
                    var (fx, fy) = d switch { 0 => (0, -1), 2 => (1, 0), 4 => (0, 1), _ => (-1, 0) };
                    return -((fx * (actor.Position.X - spotPxX)) + (fy * (actor.Position.Y - spotPxY)));
                }).ToArray()
                : [baseFacing, (short)((baseFacing + 2) & 6), (short)((baseFacing + 4) & 6), (short)((baseFacing + 6) & 6)];

            for (var radius = 0; radius <= 3 && !placed; radius++)
            for (var dy = -radius; dy <= radius && !placed; dy++)
            for (var dx = -radius; dx <= radius && !placed; dx++)
            {
                if (Math.Max(Math.Abs(dx), Math.Abs(dy)) != radius) continue;
                var cx = tileX + dx;
                var cy = tileY + dy;
                if (cx < 1 || cy < 1 || cx > maxCoord || cy > maxCoord) continue;
                var spot = new ObjectPosition((short)(cx * 16 + 8), (short)(cy * 16 + 8), (sbyte)level);
                if (!currentWorld.RoomIsOutside(currentWorld.RoomAtTile(cx, cy, level)) && level == 1)
                {
                }
                foreach (var facing in facings)
                {
                    currentWorld.FaceCreatedObject(root, group, facing);
                    if (!currentWorld.CanPlaceCreatedObject(root, spot, actor)) continue;
                    currentWorld.PlaceCreatedObject(root, spot);
                    placed = true;
                    break;
                }
            }
            if (placed) placedObjectOwners[root.Id] = packId;
            return placed ? root.Id : null;
        }
        finally
        {
            if (!placed) currentWorld.RemoveCreatedObjectGroup(root);
        }
    }

    public bool TryRemoveOwnedObject(string packId, short objectId)
    {
        if (world() is not { } currentWorld) return false;
        if (currentWorld.ObjectById(objectId) is not { } existing) return false;
        var source = existing.TypeRecord is { } type ? registry()?.Find(unchecked((uint)type.Key))?.Source : null;
        var root = existing.MultiTileMasterId != 0 ? (currentWorld.ObjectById(existing.MultiTileMasterId) ?? existing) : existing;
        var ownsPlaced = placedObjectOwners.TryGetValue(root.Id, out var ownerPack) && string.Equals(ownerPack, packId, StringComparison.Ordinal);
        if (!ownsPlaced && (source is null || !source.Replace('\\', '/').Contains("/Downloads/" + packId + "/", StringComparison.OrdinalIgnoreCase)))
            throw new ArgumentException("Only this pack's own objects may be removed");
        if (existing[ObjectData.UseCount] > 0) return false;
        if (root[ObjectData.UseCount] > 0) return false;
        var seen = new HashSet<short> { root.Id };
        for (var nextId = root.MultiTileNextId; nextId != 0 && seen.Add(nextId); )
        {
            if (currentWorld.ObjectById(nextId) is not { } part) break;
            if (part[ObjectData.UseCount] > 0) return false;
            nextId = part.MultiTileNextId;
        }
        placedObjectOwners.Remove(root.Id);
        currentWorld.RemoveCreatedObjectGroup(root);
        return true;
    }

    public string? ResolveSimSuit(short simId, char categoryPrefix, int bodyStringIndex)
    {
        if (world()?.ObjectById(simId) is not XPerson person)
            return null;
        return resolveSimSuit?.Invoke(person, categoryPrefix, bodyStringIndex);
    }

    public void SetSimAppearanceOverride(short simId, string? bodySuitSpec, bool animateSpin = true) =>
        setSimAppearanceOverride?.Invoke(simId, bodySuitSpec, animateSpin);

    public short GetObjectAttribute(short objectId, int index) => LotObject(objectId, index).Attributes[index];
    public void SetObjectAttribute(short objectId, int index, short value)
    {
        var item = LotObject(objectId, index);
        item.Attributes[index] = value;
        if (item.MultiTileMasterId == 0 && item.MultiTileNextId != 0 &&
            unchecked((ushort)item.Definition[(int)SimsEngine.Formats.ObjdField.SubIndex]) == ushort.MaxValue)
        {
            var seen = new HashSet<short> { item.Id };
            for (var nextId = item.MultiTileNextId; nextId != 0 && seen.Add(nextId); )
            {
                if (World.ObjectById(nextId) is not { } part) break;
                if (index >= 0 && index < part.Attributes.Length)
                    part.Attributes[index] = value;
                nextId = part.MultiTileNextId;
            }
        }
    }
    public void SetObjectGraphic(short objectId, short graphic)
    {
        var item = LotObject(objectId, null);
        var leadNumGraphics = item.Definition[(int)SimsEngine.Formats.ObjdField.NumGraphics];
        var isCatalogLead = item.MultiTileMasterId == 0 && item.MultiTileNextId != 0 &&
            unchecked((ushort)item.Definition[(int)SimsEngine.Formats.ObjdField.SubIndex]) == ushort.MaxValue;
        if (graphic < 0 || (!isCatalogLead && graphic >= leadNumGraphics))
            throw new ArgumentOutOfRangeException(nameof(graphic));
        if (graphic < leadNumGraphics || leadNumGraphics == 0)
            item[ObjectData.Graphic] = graphic;
        if (isCatalogLead)
        {
            var seen = new HashSet<short> { item.Id };
            for (var nextId = item.MultiTileNextId; nextId != 0 && seen.Add(nextId); )
            {
                if (World.ObjectById(nextId) is not { } part) break;
                if (graphic < part.Definition[(int)SimsEngine.Formats.ObjdField.NumGraphics])
                    part[ObjectData.Graphic] = graphic;
                nextId = part.MultiTileNextId;
            }
        }
    }
}
