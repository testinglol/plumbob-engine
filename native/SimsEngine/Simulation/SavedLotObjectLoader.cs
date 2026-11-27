using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.World;

namespace SimsEngine.Simulation;

public static class SavedLotObjectLoader
{
    private static readonly ResourceType ObjectTypesType = ResourceType.Parse("objt");
    private static readonly ResourceType LotObjectsType = ResourceType.Parse("ObjM");
    private static readonly ResourceType TypeAttributesType = ResourceType.Parse("TATT");
    private static readonly ResourceType SlotsType = ResourceType.Parse("SLOT");
    private static readonly HashSet<short> GenericSimsCallPersonRecordTypes = [2, 0x200, 0x400, 0x800, 0x1000];

    public static SimulationWorld Load(IffFile lot, ObjectRegistry registry, GlobalLibrary library, byte language = 1,
        IffFile? neighborhood = null)
    {
        var typesChunk = lot.OfType(ObjectTypesType).FirstOrDefault()
            ?? throw MissingChunk(lot, ObjectTypesType);
        var objectsChunk = lot.OfType(LotObjectsType).FirstOrDefault()
            ?? throw MissingChunk(lot, LotObjectsType);
        var types = ObjectTypeTable.Read(lot, typesChunk);
        var rawEntriesByGuid = new Dictionary<uint, ObjectEntry?>();
        var entriesByGuid = new Dictionary<uint, ObjectEntry?>();
        foreach (var type in types.Entries)
        {
            var entry = registry.Find(type.Guid);
            rawEntriesByGuid[type.Guid] = entry;
            if (entry is null && PlaceholderGuid(type) is { } placeholderGuid)
                entry = registry.Find(placeholderGuid);
            entriesByGuid[type.Guid] = entry;
        }
        var rawDefinition = new Func<uint, Objd?>(guid => rawEntriesByGuid.GetValueOrDefault(guid)?.Definition);
        var objects = LotObjects.Read(lot, objectsChunk, types, rawDefinition, decodeUnknownAsObject: true);
        var attributes = ReadMergedTypeAttributes(lot, neighborhood);
        var neighbors = ReadAdjacentNeighbors(lot, neighborhood);
        var familyNumbers = ReadAdjacentFamilyNumbers(lot, neighborhood);
        var simulationState = lot.OfType(ResourceType.Parse("SIMI")).FirstOrDefault() is { } simulationStateChunk
            ? Formats.SimulationState.Read(lot, simulationStateChunk)
            : null;
        var decodedByType = new Dictionary<short, ObjectState>();
        foreach (var savedObj in objects.Objects)
            if (savedObj.Decoded is { } dec) decodedByType.TryAdd(savedObj.TypeIndex, dec);
        var objectClasses = new Dictionary<short, (ObjectClass Class, bool Placeholder)>();
        foreach (var type in types.Entries)
        {
            if (rawEntriesByGuid.GetValueOrDefault(type.Guid)?.Definition is { } rawObjd && LotObjects.ClassOf(rawObjd) is { } rawClass)
            {
                if (decodedByType.TryGetValue(type.TypeIndex, out var decState))
                {
                    var inferredClass = decState.Person is not null ? ObjectClass.Person
                        : decState.MultiTile is { PortalValues: not null } ? ObjectClass.Portal
                        : decState.MultiTile is not null ? ObjectClass.MultiTileObject
                        : rawClass;
                    var inferredPlaceholder = LotObjects.IsPlaceholder(type.Guid) || (objects.Version > 0x35 && decState.ManagerFlags is null);
                    objectClasses[type.TypeIndex] = (inferredClass, inferredPlaceholder);
                }
                else
                {
                    objectClasses[type.TypeIndex] = (rawClass, LotObjects.IsPlaceholder(type.Guid));
                }
            }
            else if (decodedByType.TryGetValue(type.TypeIndex, out var missingDec))
            {
                var inferredClass = missingDec.Person is not null ? ObjectClass.Person
                    : missingDec.MultiTile is { PortalValues: not null } ? ObjectClass.Portal
                    : missingDec.MultiTile is not null ? ObjectClass.MultiTileObject
                    : ObjectClass.Object;
                var inferredPlaceholder = LotObjects.IsPlaceholder(type.Guid) || (objects.Version > 0x35 && missingDec.ManagerFlags is null);
                objectClasses[type.TypeIndex] = (inferredClass, inferredPlaceholder);
            }
            else if (entriesByGuid.GetValueOrDefault(type.Guid)?.Definition is { } fallbackObjd && LotObjects.ClassOf(fallbackObjd) is { } fallbackClass)
            {
                objectClasses[type.TypeIndex] = (fallbackClass, LotObjects.IsPlaceholder(type.Guid));
            }
        }
        var world = Restore(objects.Objects, types.Entries, guid => rawEntriesByGuid.GetValueOrDefault(guid) ?? registry.Find(guid), library.ScopeOf,
            attributes, objects.Version, registry, neighbors, simulationState, language, familyNumbers);
        world.ObjectRegistry = registry;
        world.SavedLotObjects = objects;
        world.SavedObjectClasses = objectClasses;
        if (library.Global?.Find(ResourceType.Slot, 100) is { } lotRoutingChunk)
            world.LotRoutingSlots.AddRange(SlotTable.Read(library.Global, lotRoutingChunk).Slots
                .Where(slot => slot.Type == 3).Select(RoutingSlotRequest.FromDefinition));
        world.PersonMotiveDecayTuning = library.Global is { } global
            ? PersonMotiveDecayTuning.Read(global)
            : null;
        var constants = library.Global?.Find(ResourceType.Fcns, 2) is { } constantsChunk
            ? SimulatorConstants.Read(library.Global, constantsChunk)
            : SimulatorConstants.Empty;
        world.ApplySimulatorConstants(constants);
        // Applies global constants prior to room map initialization so score and lighting calculations
        // receive valid configuration values.
        world.LotTileFlags = SimsEngine.World.LotTiles.Read(lot);
        world.LotTerrain = lot.Find(ResourceType.Parse("Arry"), 0) is not null
            ? SimsEngine.World.LotTerrain.Read(lot)
            : null;
        world.LoadRoomMaps(ReadRoomMaps(lot, simulationState?.Version ?? 0));
        world.RefreshSavedPortalWallStyles();
        world.PlacementEligibilityGrids[1] = ReadPlacementEligibilityGrid(lot, simulationState?.Version ?? 0);
        world.ObjectFactory = guid => CreateInstance(world, unchecked((uint)guid), registry, library, language, registerSavedType: true);
        world.ObjectGroupFactory = guid => CreateObjectGroup(world, unchecked((uint)guid), registry, library, language, registerSavedType: true);
        world.PlacementPreviewFactory = guid => CreateInstance(world, unchecked((uint)guid), registry, library, language, registerSavedType: false);
        world.BuildCursorFactory = guid => CreateInstance(world, unchecked((uint)guid), registry, library, language, registerSavedType: false, toolObject: true);
        world.PlacementPreviewGroupFactory = guid => CreateObjectGroup(world, unchecked((uint)guid), registry, library, language, registerSavedType: false);
        world.OffLotTransit.CaptureBaseline(world);
        return world;
    }

    private static IReadOnlyList<XObject>? CreateObjectGroup(SimulationWorld world, uint guid,
        ObjectRegistry registry, GlobalLibrary library, byte language, bool registerSavedType)
    {
        var masterEntry = registry.Find(guid);
        if (masterEntry is null || masterEntry.Definition[ObjdField.MasterId] == 0) return null;
        if (masterEntry.Definition[ObjdField.SubIndex] != ushort.MaxValue) return [];

        var masterId = masterEntry.Definition[ObjdField.MasterId];
        // OBJD SubIndex -1 (0xFFFF) is a catalog master placeholder; parts share its MasterId within the same IFF.
        var allParts = registry.Entries.Where(entry => ReferenceEquals(entry.File, masterEntry.File) &&
            entry.Definition[ObjdField.MasterId] == masterId &&
            entry.Definition[ObjdField.SubIndex] != ushort.MaxValue).ToArray();
        if (allParts.Length == 0) return [];
        var leadEntry = allParts.FirstOrDefault(entry => entry.Definition[ObjdField.MtLeadObject] != 0)
            ?? allParts.FirstOrDefault(entry => entry.Definition[ObjdField.SubIndex] == 0 && entry.Definition[ObjdField.LevelOffset] == 0)
            ?? allParts[0];
        var orderedParts = new List<ObjectEntry>(allParts.Length) { leadEntry };
        foreach (var entry in allParts)
            if (!ReferenceEquals(entry, leadEntry)) orderedParts.Add(entry);

        var created = new List<XObject>(orderedParts.Count);
        using var savedTypes = world.BeginSavedObjectTypeRegistrationScope();
        try
        {
            XObject? root = null;
            foreach (var entry in orderedParts)
            {
                var part = CreateInstance(world, entry.Guid, registry, library, language, registerSavedType);
                if (part is null) throw new InvalidDataException($"Multi-tile definition {entry.Guid:X8} could not be instantiated.");
                var subIndex = unchecked((ushort)entry.Definition[ObjdField.SubIndex]);
                var offsetX = unchecked((sbyte)(subIndex >> 8));
                var offsetY = (byte)(subIndex & 0xff);
                var levelOffset = unchecked((short)entry.Definition[ObjdField.LevelOffset]);
                if (root is null)
                {
                    root = part;
                    root.SavedMultiTileState = new MultiTileState(offsetX, offsetY, levelOffset,
                        offsetX, offsetY, levelOffset, 0, root.RuntimeClass == ObjectClass.Portal ? [] : null);
                }
                else
                {
                    part.MultiTileMasterId = root.Id;
                    part.SavedMultiTileState = new MultiTileState(offsetX, offsetY, levelOffset,
                        offsetX, offsetY, levelOffset, root.Id, part.RuntimeClass == ObjectClass.Portal ? [] : null);
                    created[^1].MultiTileNextId = part.Id;
                }
                world.Add(part);
                created.Add(part);
            }
            if (root is not null)
                root[ObjectData.CurrentValue] = unchecked((short)masterEntry.Definition[ObjdField.Price]);
            world.InitializeCreatedObjectGroup(created);
            if (registerSavedType) savedTypes.Commit();
            return created;
        }
        catch
        {
            foreach (var instance in created.AsEnumerable().Reverse()) world.Remove(instance.Id);
            return [];
        }
    }

    private static int InstanceAttributeCount(ObjectEntry entry) => Math.Max((int)entry.Definition[ObjdField.NumAttributes], 8);

    internal static XObject? CreateInstance(SimulationWorld world, uint guid, ObjectRegistry registry, GlobalLibrary library, byte language,
        bool registerSavedType, bool toolObject = false)
    {
        var entry = registry.Find(guid);
        if (entry is null) return null;
        if (!toolObject && entry.Definition[ObjdField.MasterId] != 0 && entry.Definition[ObjdField.SubIndex] == ushort.MaxValue)
            return null;
        var objectClass = LotObjects.ClassOf(entry.Definition) ?? (toolObject ? ObjectClass.Object : null);
        if (objectClass is null) return null;
        var definition = new short[XObject.DefinitionCount];
        for (var field = 0; field < Math.Min(definition.Length, entry.Definition.Fields.Count); field++)
            definition[field] = unchecked((short)entry.Definition.Fields[field]);
        var id = world.NextObjectId();
        XObject instance = objectClass == ObjectClass.Person
            ? new XPerson(id, definition, InstanceAttributeCount(entry))
            : new XObject(id, definition, InstanceAttributeCount(entry));
        instance.RuntimeClass = objectClass.Value;
        instance.RequestKey = id;
        instance.Flags = 0x80;
        instance.DynamicSpriteFlags = new short[entry.Definition[ObjdField.NumDynamicSprites]];
        var runtimeTypeAttrGuid = entry.Definition.TypeAttributesGuid;
        var runtimeTypeAttrCount = TypeAttributeCount(entry, runtimeTypeAttrGuid, registry);
        instance.TypeAttributes = world.GetOrCreateTypeAttributes(runtimeTypeAttrGuid, runtimeTypeAttrCount);
        RestoreSlotDefinitions(instance, entry);
        PadSlotVector(instance);
        var scope = library.ScopeOf(entry);
        var actionFunctions = SafeActionFunctions(entry);
        if (registerSavedType)
            world.RegisterSavedObjectType(new ObjectTypeEntry(guid,
                SavedTreeFingerprint(scope, actionFunctions.ElementAtOrDefault(0)),
                SavedTreeFingerprint(scope, actionFunctions.ElementAtOrDefault(1)), 0,
                unchecked((short)entry.Definition[ObjdField.Type]),
                entry.Definition[ObjdField.MasterId] == 0 || entry.Definition[ObjdField.SubIndex] == ushort.MaxValue ? entry.Chunk.Label : string.Empty,
                unchecked((int)((uint)entry.Definition.Fields.ElementAtOrDefault(70) | ((uint)entry.Definition.Fields.ElementAtOrDefault(71) << 16)))),
                objectClass.Value, scope);
        var alternativeType = registry.FindAlternativeType(entry);
        var functionEntries = SafeFunctionEntries(entry);
        instance.TypeRecord = new TypeRecord(unchecked((int)guid))
        {
            ObjectType = unchecked((short)entry.Definition[ObjdField.Type]),
            SubIndex = unchecked((short)entry.Definition[ObjdField.SubIndex]),
            ObjectVersion = unchecked((short)entry.Definition[ObjdField.ObjectVersion]),
            AnimatorBodyStringMode = AnimatorBodyStringMode(entry, language),
            FootprintMask = entry.Definition[ObjdField.FootprintMask],
            Name = entry.Chunk.Label,
            CatalogName = SafeCatalogString(entry, 0, language),
            CatalogDescription = SafeCatalogString(entry, 1, language),
            FunctionTable = functionEntries.Select(function => function.Action).ToArray(),
            FunctionCheckTable = functionEntries.Select(function => function.Guard).ToArray(),
            BehaviorScope = scope,
            Interactions = entry.HasNoMasterInteractionTable ? null :
                SafeFindInteractionTable(entry, scope, language, alternativeType),
            AlternativeTypeKey = alternativeType is null ? null : unchecked((int)alternativeType.Guid),
            AlternativeObjectPrice = alternativeType is null ? null : unchecked((short)alternativeType.Definition[ObjdField.Price]),
            AutonomyAlternativeTypeFlag = alternativeType is null ? (short)0 :
                unchecked((short)alternativeType.Definition[ObjdField.BuildModeType]),
        };
        InitializeGenericSimsCallPersonTypeRecords(instance, registry, language);
        if (instance is XPerson person)
        {
            person.SavedCharacter = DefaultPersonCharacter(entry, language);
            person.AnimatorBodyStringMode = instance.TypeRecord.AnimatorBodyStringMode ?? 0;
        }
        return instance;
    }

    private static IReadOnlyList<ushort> SafeActionFunctions(ObjectEntry entry)
    {
        try { return entry.ActionFunctions; }
        catch (ResourceFormatException) { return []; }
    }

    private static IReadOnlyList<(ushort Guard, ushort Action)> SafeFunctionEntries(ObjectEntry entry)
    {
        try { return entry.FunctionEntries; }
        catch (ResourceFormatException) { return []; }
    }

    private static string? SafeCatalogString(ObjectEntry entry, int index, byte language)
    {
        try { return entry.CatalogString(index, language); }
        catch (ResourceFormatException) { return null; }
    }

    private static InteractionTable? SafeFindInteractionTable(ObjectEntry entry, BehaviorScope? scope, byte language, ObjectEntry? masterFallback)
    {
        try { return entry.FindInteractionTable(scope, language, masterFallback); }
        catch (Exception ex) when (ex is ResourceFormatException or NotSupportedException) { return null; }
    }

    internal static short? AnimatorBodyStringMode(ObjectEntry entry, byte language)
    {
        var id = entry.Definition[ObjdField.BodyStringsId];
        if (id == 0 || entry.File.Find(ResourceType.Str, id) is not { } chunk) return null;
        try
        {
            var strings = StringTable.Read(entry.File, chunk).ForLanguage(language);
            return (strings.Count > 12 ? MapAnimatorBodyString13(strings[12]) : null)
                ?? (strings.Count > 13 ? MapAnimatorBodyString13(strings[13]) : null);
        }
        catch (ResourceFormatException)
        {
            return null;
        }
    }

    internal static short? MapAnimatorBodyString13(string value) => value.Trim().ToLowerInvariant() switch
        {
            "male" => 0,
            "female" => 1,
            "dogmale" => 2,
            "dogfemale" => 3,
            "catmale" => 4,
            "catfemale" => 5,
            _ => null,
        };

    private static PersonCharacter? DefaultPersonCharacter(ObjectEntry entry, byte language)
    {
        var id = entry.Definition[ObjdField.BodyStringsId];
        if (id == 0 || entry.File.Find(ResourceType.Str, id) is not { } chunk) return null;
        IReadOnlyList<string> strings;
        try { strings = StringTable.Read(entry.File, chunk).ForLanguage(language); }
        catch (ResourceFormatException) { return null; }
        if (strings.Count < 3) return null;

        static (string, string) Pair(string value)
        {
            var semicolon = value.IndexOf(';');
            var trimmed = (semicolon >= 0 ? value[..semicolon] : value).Trim();
            var separator = trimmed.IndexOf(',');
            return separator < 0 ? (trimmed, string.Empty) : (trimmed[..separator].Trim(), trimmed[(separator + 1)..].Trim());
        }

        var parts = Enumerable.Repeat((string.Empty, string.Empty), 5).ToArray();
        parts[0] = Pair(strings[1]);
        parts[4] = Pair(strings[2]);
        return new PersonCharacter(0, 0, parts, [], [string.Empty, string.Empty, string.Empty], 3, new float[9]);
    }

    public static uint SavedTreeFingerprint(ITreeTable? scope, ushort root)
    {
        if (scope is null) return 0;
        var pending = new Stack<ushort>();
        var seen = new HashSet<ushort>();
        pending.Push(root);
        var rootTree = scope.Find(unchecked((short)root));
        var result = unchecked((rootTree?.TreeVersion ?? 0) << 16);
        while (pending.TryPop(out var id))
        {
            if (!seen.Add(id)) continue;
            var tree = scope.Find(unchecked((short)id));
            if (tree is null) continue;
            result = unchecked(result + tree.TreeVersion);
            foreach (var instruction in tree.Instructions)
            {
                var call = (ushort)(instruction.Opcode & 0x7fff);
                if (call > 255) pending.Push(call);
            }
        }
        return result;
    }

    public static IReadOnlyDictionary<int, RoomMap> ReadRoomMaps(IffFile lot, int simulationVersion, int minLevels = 2)
    {
        ArgumentNullException.ThrowIfNull(lot);
        var result = new Dictionary<int, RoomMap>();
        var maxLevel = Math.Clamp(Math.Max(minLevels, SimsEngine.World.LotTiles.BuiltStories(lot)), 1, LotGeometry.MaxSupportedStories);
        for (var level = 1; level <= LotGeometry.MaxSupportedStories; level++)
        {
            if (level <= maxLevel ? (level == 1 ? RoomMap.HasLevel(lot, 1) : RoomMap.HasLevel(lot, 1) || RoomMap.HasLevel(lot, level)) : RoomMap.HasLevel(lot, level))
            {
                result.Add(level, RoomMap.Build(lot, level, LotGeometry.LotDimension, LotGeometry.LotDimension,
                    importRuntimeWallGrid: level == 1 || simulationVersion > 0x16));
            }
        }
        return result;
    }

    public static byte[] ReadPlacementEligibilityGrid(IffFile lot, int simulationVersion)
    {
        ArgumentNullException.ThrowIfNull(lot);
        var result = new byte[LotGeometry.LotDimension * LotGeometry.LotDimension];
        Array.Fill(result, (byte)0xff);
        if (simulationVersion < 0x35 || lot.Find(ResourceType.Parse("Arry"), 10) is not { } chunk)
            return result;

        var array = LotArray.Read(lot, chunk);
        if (array.Rows < LotGeometry.LotDimension || array.Width < LotGeometry.LotDimension || array.ElementSize != 1)
            throw new InvalidDataException("Arry 10 eligibility grid must contain a 64 by 64 byte plane.");
        for (var x = 0; x < LotGeometry.LotDimension; x++)
        for (var y = 0; y < LotGeometry.LotDimension; y++)
            result[x * LotGeometry.LotDimension + y] = array.Element(x, y)[0];
        return result;
    }

    public static SimulationWorld Restore(
        IReadOnlyList<LotObject> savedObjects,
        IEnumerable<ObjectTypeEntry> savedTypes,
        Func<uint, ObjectEntry?> findDefinition,
        Func<ObjectEntry, ITreeTable?> findBehaviorScope,
        IReadOnlyDictionary<uint, short[]>? attributesByGuid = null,
        int objectManagerVersion = 0x39,
        ObjectRegistry? typeRegistry = null,
        Neighbors? savedNeighbors = null,
        SimulationState? savedSimulationState = null,
        byte language = 1,
        IReadOnlyDictionary<uint, int>? familyNumbersByGuid = null)
    {
        ArgumentNullException.ThrowIfNull(savedObjects);
        ArgumentNullException.ThrowIfNull(savedTypes);
        ArgumentNullException.ThrowIfNull(findDefinition);
        ArgumentNullException.ThrowIfNull(findBehaviorScope);

        var typesByIndex = new Dictionary<short, ObjectTypeEntry>();
        foreach (var type in savedTypes)
            if (!typesByIndex.TryAdd(type.TypeIndex, type))
                throw new InvalidDataException($"Lot object type index {type.TypeIndex} appears more than once.");

        var world = new SimulationWorld();
        var maxSavedHeight = 2;
        foreach (var savedObj in savedObjects)
        {
            if (savedObj.Decoded is not { } decoded) continue;
            var h = decoded.Value0x110 & 0xff;
            if (h > maxSavedHeight && h <= LotGeometry.MaxSupportedStories)
                maxSavedHeight = h;
        }
        world.MaxIndexedLevel = maxSavedHeight;
        world.SavedSimulationState = savedSimulationState;
        world.SavedObjectManagerVersion = objectManagerVersion;
        if (typeRegistry is not null)
        {
            foreach (var entry in typeRegistry.Entries)
            {
                if (entry.Definition[ObjdField.Type] != XPerson.PersonType) continue;
                var key = unchecked((int)entry.Guid);
                world.PersonRecordKeys.Add(key);
            }
            world.PersonRecordManagerPresent = true;
        }
        if (savedSimulationState is { } loadedSimulationState)
        {
            for (var global = 0; global < Math.Min(loadedSimulationState.Globals.Count, world.Globals.Length); global++)
                world.Globals[global] = loadedSimulationState.Globals[global];
            world.UseSimulationGlobalsForCurrentDate();
            world.Clock.Restore(world[SimulationGlobal.Hour], world[SimulationGlobal.Minute], world[SimulationGlobal.Second]);
            if (loadedSimulationState.Version > 0x0d)
                world.ObjectManagerRandomState = unchecked((uint)loadedSimulationState.Field0xAC);
        }
        else
        {
            world.CurrentDate = SimulationDate.Initial;
        }
        world[SimulationGlobal.GameEdition] = typeRegistry?.GameEditionMask ?? 0xff;
        if (savedNeighbors is not null)
        {
            world.SavedNeighbors = savedNeighbors;
            RestoreNeighbors(world, savedNeighbors, typeRegistry, familyNumbersByGuid);
        }
        else if (typeRegistry is not null)
        {
            RestoreCatalogNeighbors(world, typeRegistry, familyNumbersByGuid);
        }
        Dictionary<int, PersonState>? personStateByTypeIndex = null;
        foreach (var savedObj in savedObjects)
        {
            if (savedObj.Decoded?.Person is { } ps)
            {
                personStateByTypeIndex ??= [];
                personStateByTypeIndex.TryAdd(savedObj.TypeIndex, ps);
            }
        }
        foreach (var type in typesByIndex.Values)
        {
            world.SavedObjectTypes.Add(type.TypeIndex, type);
            world.CodeOwnerTypeGuids.Add(type.TypeIndex, type.Guid);
            var typeEntry = findDefinition(type.Guid);
            if (typeEntry is null && PlaceholderGuid(type, personStateByTypeIndex?.GetValueOrDefault(type.TypeIndex)) is { } placeholderGuid)
                typeEntry = findDefinition(placeholderGuid);
            var typeScope = typeEntry is null ? null : findBehaviorScope(typeEntry);
            world.CodeOwnerScopes.Add(type.TypeIndex, typeScope);
            if (typeEntry is not null)
            {
                var actionFuncs = SafeActionFunctions(typeEntry);
                var tree0 = SavedTreeFingerprint(typeScope, actionFuncs.ElementAtOrDefault(0));
                var tree1 = SavedTreeFingerprint(typeScope, actionFuncs.ElementAtOrDefault(1));
                if (tree0 != type.TreeValue0 || tree1 != type.TreeValue1)
                {
                    world.ChangedCodeTypeGuids.Add(type.Guid);
                    world.CurrentObjectTypes[type.TypeIndex] = type with { TreeValue0 = tree0, TreeValue1 = tree1 };
                }
            }
        }
        if (typeRegistry is not null)
        {
            foreach (var registered in typeRegistry.Entries)
            {
                var count = unchecked((short)registered.Definition[ObjdField.NumTypeAttributes]);
                if (count is > 0 and <= 31999)
                    world.GetOrCreateTypeAttributes(registered.Definition.Guid, count);
            }
        }
        if (attributesByGuid is not null)
        {
            foreach (var (guid, attributes) in attributesByGuid)
            {
                var target = world.GetOrCreateTypeAttributes(guid, attributes.Length);
                attributes.CopyTo(target, 0);
            }
        }
        var seenIds = new HashSet<short>();
        var pendingPersonStates = new List<(XPerson Person, PersonState State)>();
        foreach (var saved in savedObjects)
        {
            if (!seenIds.Add(saved.ObjectId))
                throw new InvalidDataException($"Lot object id {saved.ObjectId} appears more than once.");
            if (!typesByIndex.TryGetValue(saved.TypeIndex, out var savedType))
                throw new InvalidDataException($"Lot object {saved.ObjectId} refers to missing object type index {saved.TypeIndex}.");

            var entry = findDefinition(savedType.Guid);
            if (entry is null && PlaceholderGuid(savedType, saved.Decoded?.Person) is { } placeholderGuid)
                entry = findDefinition(placeholderGuid);
            if (entry is null)
                throw new InvalidDataException($"Lot object {saved.ObjectId} needs missing definition {savedType.Guid:X8} and its placeholder.");
            var objectClass = LotObjects.ClassOf(entry.Definition);
            if (objectClass is null) continue;

            var state = saved.Decoded
                ?? throw new InvalidDataException($"Lot object {saved.ObjectId} ({savedType.Guid:X8}) has no decoded {objectClass} state.");
            if (state.Values0x108.Count != 6)
                throw new InvalidDataException($"Lot object {saved.ObjectId} has {state.Values0x108.Count} common position/bounds fields; expected 6.");
            if (objectClass == ObjectClass.Person && state.Person is null)
                throw new InvalidDataException($"Lot person {saved.ObjectId} has no person-state block.");

            var definition = new short[XObject.DefinitionCount];
            for (var i = 0; i < Math.Min(definition.Length, entry.Definition.Fields.Count); i++)
                definition[i] = unchecked((short)entry.Definition.Fields[i]);

            XObject instance = objectClass == ObjectClass.Person
                ? new XPerson(saved.ObjectId, definition, state.Attributes.Length)
                : new XObject(saved.ObjectId, definition, state.Attributes.Length);
            instance.RuntimeClass = objectClass;
            instance.RequestKey = saved.ObjectId;
            var instanceAttributeCount = InstanceAttributeCount(entry);
            instance.Attributes = new short[Math.Max(instanceAttributeCount, state.Attributes.Length)];
            state.Attributes.CopyTo(instance.Attributes, 0);
            RestoreSlotDefinitions(instance, entry);
            state.Temps.CopyTo(instance.Temporaries, 0);
            state.Data.CopyTo(instance.Data, 0);
            var dynamicSpriteCount = (int)entry.Definition[ObjdField.NumDynamicSprites];
            instance.DynamicSpriteFlags = new short[Math.Max(dynamicSpriteCount, state.Values0x34.Length)];
            state.Values0x34.CopyTo(instance.DynamicSpriteFlags, 0);
            instance.Slots.AddRange(state.Slots);
            PadSlotVector(instance);
            // Serialized Slots[0] is a sentinel; FootprintSlots map to Slots[1..].
            for (var footprintIndex = 0; footprintIndex < instance.FootprintSlots.Count; footprintIndex++)
            {
                var relationIndex = footprintIndex + 1;
                if (relationIndex >= instance.Slots.Count) break;
                instance.FootprintSlots[footprintIndex].OccupantObjectId = instance.Slots[relationIndex];
            }
            instance.Position = new ObjectPosition(state.Values0x108[4], state.Values0x108[5], state.Value0x110);
            instance.FootprintBounds = new FootprintBounds(
                state.Values0x108[3], state.Values0x108[2], state.Values0x108[1], state.Values0x108[0]);
            instance.FootprintBoundsDirection = instance[ObjectData.Direction];
            instance.Flags = unchecked((uint)(state.Value0x114 ?? 0x80));
            instance.SavedStack.AddRange(state.Stack);
            instance.SavedStackSize = state.StackSize;
            instance.SavedMultiTileState = state.MultiTile;
            if (state.MultiTile is { } multiTile)
                instance.MultiTileMasterId = multiTile.LeadObject == saved.ObjectId ? (short)0 : multiTile.LeadObject;

            foreach (var relationship in state.Relationships)
            {
                if (relationship is null) continue;
                var target = checked((short)relationship.Value0x0C);
                instance.Relationships.Resize(target, relationship.Values.Length);
                for (var index = 0; index < relationship.Values.Length; index++)
                    instance.Relationships.Set(target, index, relationship.Values[index]);
            }

            var typeAttributeGuid = entry.Definition.TypeAttributesGuid != 0 ? entry.Definition.TypeAttributesGuid : savedType.Guid;
            var typeAttributeCount = TypeAttributeCount(entry, typeAttributeGuid, typeRegistry);
            instance.TypeAttributes = world.GetOrCreateTypeAttributes(typeAttributeGuid, typeAttributeCount);

            var behaviorScope = findBehaviorScope(entry);
            var resourceScope = behaviorScope as BehaviorScope;
            var treeTableId = entry.Definition[ObjdField.TreeTableId];
            var alternativeType = typeRegistry?.FindAlternativeType(entry);
            InteractionTable? interactionTable = null;
            if (treeTableId != 0 && !entry.HasNoMasterInteractionTable)
                interactionTable = SafeFindInteractionTable(entry, resourceScope, language, alternativeType);
            var functionEntries = SafeFunctionEntries(entry);
            instance.TypeRecord = new TypeRecord(unchecked((int)savedType.Guid))
            {
                ObjectType = unchecked((short)entry.Definition[ObjdField.Type]),
                SubIndex = unchecked((short)entry.Definition[ObjdField.SubIndex]),
                ObjectVersion = unchecked((short)entry.Definition[ObjdField.ObjectVersion]),
                AnimatorBodyStringMode = AnimatorBodyStringMode(entry, language),
                FootprintMask = entry.Definition[ObjdField.FootprintMask],
                Name = entry.Chunk.Label,
                CatalogName = SafeCatalogString(entry, 0, language),
                CatalogDescription = SafeCatalogString(entry, 1, language),
                FunctionTable = functionEntries.Select(function => function.Action).ToArray(),
                FunctionCheckTable = functionEntries.Select(function => function.Guard).ToArray(),
                BehaviorScope = behaviorScope,
                Interactions = interactionTable,
                AlternativeTypeKey = alternativeType is null ? null : unchecked((int)alternativeType.Guid),
                AlternativeObjectPrice = alternativeType is null ? null : unchecked((short)alternativeType.Definition[ObjdField.Price]),
                AutonomyAlternativeTypeFlag = alternativeType is null ? (short)0 :
                    unchecked((short)alternativeType.Definition[ObjdField.BuildModeType]),
            };

            InitializeGenericSimsCallPersonTypeRecords(instance, typeRegistry, language);

            if (instance is XPerson person)
            {
                var personState = state.Person!;
                personState.PersonData.CopyTo(person.PersonData, 0);
                if (personState.Values0x78C.Length != person.Motives.Length)
                    throw new InvalidDataException($"Lot person {saved.ObjectId} has {personState.Values0x78C.Length} motive values; expected {person.Motives.Length}.");
                personState.Values0x78C.CopyTo(person.Motives, 0);
                if (personState.Values0x7CC.Length == person.SavedPersonValues7CC.Length)
                    personState.Values0x7CC.CopyTo(person.SavedPersonValues7CC, 0);
                person.SavedCharacter = personState.Character;
                var genderFlags = person[PersonData.Gender];
                person.AnimatorBodyStringMode = instance.TypeRecord.AnimatorBodyStringMode
                    ?? ((genderFlags & 2) != 0 ? (short)(2 + (genderFlags & 1))
                        : (genderFlags & 4) != 0 ? (short)(4 + (genderFlags & 1))
                        : (short)(genderFlags & 1));
                if ((genderFlags & 2) != 0 && person.AnimatorBodyStringMode is < 2 or > 3)
                    person.AnimatorBodyStringMode = (short)(2 + (genderFlags & 1));
                else if ((genderFlags & 4) != 0 && person.AnimatorBodyStringMode is < 4 or > 5)
                    person.AnimatorBodyStringMode = (short)(4 + (genderFlags & 1));
                person.SavedPersonActionStorageCount = personState.Count0xAF0;
                person.SavedCurrentAction = personState.First;
                person.SavedQueuedAction = personState.Second;
                person.SavedActions.AddRange(personState.Actions);
                person.RestoreMotiveChanges(personState.Values);
                pendingPersonStates.Add((person, personState));
            }

            world.Add(instance);
            world.LoadedObjectInstances[saved.ObjectId] = instance;
            ApplyLoadedClockEligibility(world, instance, entry.Definition.Guid, objectManagerVersion, state.ManagerFlags);
        }

        // ObjM saves only MultiTileMasterId, so rebuild MultiTileNextId links in walk order.
        foreach (var part in world.WalkOrder)
        {
            if (part.MultiTileMasterId == 0 || part.MultiTileMasterId == part.Id) continue;
            var master = world.ObjectById(part.MultiTileMasterId);
            if (master is null) continue;
            var tail = master;
            var visited = new HashSet<short> { master.Id };
            while (tail.MultiTileNextId != 0)
            {
                var next = world.ObjectById(tail.MultiTileNextId);
                if (next is null || !visited.Add(next.Id))
                {
                    tail = null;
                    break;
                }
                tail = next;
            }
            if (tail is not null) tail.MultiTileNextId = part.Id;
        }

        foreach (var instance in world.WalkOrder)
        {
            var root = InteractionMenus.Target(world, instance);
            world.InitializeAutonomyCandidate(instance, root, root.TypeRecord?.Interactions);
        }

        foreach (var (person, state) in pendingPersonStates)
        {
            if ((savedNeighbors is not null || typeRegistry is not null) && !LotObjects.IsPlaceholder(unchecked((uint)(person.TypeRecord?.Key ?? 0))))
                world.BindPersonToNeighborRecord(person);
            person.RestoreActionState(state, world);
        }

        foreach (var (person, state) in pendingPersonStates)
        foreach (var savedReference in state.Objects)
        {
            var target = savedReference.Object == 0 ? null : world.ObjectById(savedReference.Object);
            person.SavedPersonObjectReferences.Add(new PersonObjectReference(
                savedReference.Object, target, savedReference.Value, savedReference.Flag));
            if (target is not null) person.InteractingObjects.Add(target);
        }

        // Restore stack frames after all objects and type scopes are registered so cross-object references resolve.
        foreach (var owner in world.WalkOrder.Where(item => item.SavedStack.Count != 0))
        {
            RepairLegacyZeroCodeOwners(world, owner);
            world.SavedExecutionStacks.Add(owner.Id, TreeRunner.RestoreSavedStack(world, owner,
                codeOwner => world.CodeOwnerScopes.GetValueOrDefault(codeOwner)));
        }

        RestorePendingActionRequests(world);
        RepairLegacyMissingMotiveChanges(world);
        world.OffLotTransit.CaptureBaseline(world);
        return world;
    }

    private static void RestorePendingActionRequests(SimulationWorld world)
    {
        foreach (var person in world.WalkOrder.OfType<XPerson>())
        {
            if (person.PendingActionRequests.Count != 0 ||
                person.CurrentActionRecord?.Owner is not { } activeOwner ||
                !world.SavedExecutionStacks.TryGetValue(person.Id, out var stack))
            {
                continue;
            }

            var frameCount = stack.Frames.Count;
            PersonObjectReference? matchedRef = null;
            foreach (var objRef in person.SavedPersonObjectReferences)
            {
                if (objRef.Target is null || objRef.Value <= 0 || objRef.Value > frameCount)
                    continue;
                if (ReferenceEquals(objRef.Target, activeOwner) ||
                    ReferenceEquals(objRef.Target, person.CurrentActionRecord.Secondary))
                {
                    matchedRef = objRef;
                    break;
                }
            }

            if (matchedRef is { Target: not null })
            {
                person.PendingActionRequests.Add(new PersonActionRequest(matchedRef.Target, matchedRef.Value, matchedRef.Flag));
                continue;
            }

            var resolvedDepth = 0;
            for (var i = 0; i < frameCount - 1; i++)
            {
                var frame = stack.Frames[i];
                if (frame.TreeId == 0x0119 && frame.WaitState == 1)
                {
                    resolvedDepth = i + 2;
                    break;
                }
            }

            if (resolvedDepth == 0)
            {
                var expectedTree = unchecked((short)person.CurrentActionRecord.ActionTree);
                var expectedOwner = world.ResolveCodeOwner(activeOwner);
                for (var i = 0; i < frameCount; i++)
                {
                    var frame = stack.Frames[i];
                    if (frame.TreeId <= 0) continue;
                    if ((expectedTree != 0 && frame.TreeId == expectedTree) ||
                        (expectedOwner != 0 && frame.CodeOwner == expectedOwner))
                    {
                        resolvedDepth = i + 1;
                        break;
                    }
                }
            }

            if (resolvedDepth > 0)
                person.PendingActionRequests.Add(new PersonActionRequest(activeOwner, resolvedDepth, false));
        }
    }

    public static void RepairLegacyMissingMotiveChanges(SimulationWorld world)
    {
        ArgumentNullException.ThrowIfNull(world);
        foreach (var person in world.WalkOrder.OfType<XPerson>())
        {
            if (person.MotiveChanges.Count != 0 || person[PersonData.Gender] >= 2 ||
                !world.SavedExecutionStacks.ContainsKey(person.Id))
            {
                continue;
            }

            if (person[Motive.SleepState] < 0)
            {
                var sleepTarget = person.CurrentActionRecord?.Secondary
                    ?? person.CurrentActionRecord?.Owner
                    ?? person.InteractingObjects.LastOrDefault();
                if (sleepTarget?.TypeRecord?.BehaviorScope is BehaviorScope sleepScope)
                {
                    var treeId = sleepScope.FindNamedTree("set motive deltas for sleep");
                    if (treeId == 0) treeId = sleepScope.FindNamedTree("CT - nap motive deltas");
                    if (treeId == 0) treeId = sleepScope.FindNamedTree("set nap motive deltas");
                    if (treeId != 0)
                        TryRunLegacyMotiveDeltaSetup(world, person, sleepScope, treeId, sleepTarget.StackObjectKey);
                }
            }
            else if (person[PersonData.IsPersonAtWorkSchool] != 0 && world.CareerHost is not null)
            {
                var portalTarget = person.CurrentActionRecord?.Owner ?? person.InteractingObjects.LastOrDefault();
                if (portalTarget?.TypeRecord?.BehaviorScope is BehaviorScope workScope)
                {
                    var treeName = PersonAgeCategory.IsChild(person[PersonData.PersonAge])
                        ? "start motive deltas for school"
                        : "start motives delta";
                    var treeId = workScope.FindNamedTree(treeName);
                    if (treeId != 0)
                        TryRunLegacyMotiveDeltaSetup(world, person, workScope, treeId, portalTarget.StackObjectKey);
                }
            }
        }
    }

    private static void TryRunLegacyMotiveDeltaSetup(
        SimulationWorld world, XPerson person, BehaviorScope scope, short treeId, short stackObject)
    {
        var savedTemps = (short[])person.Temporaries.Clone();
        try
        {
            TreeRunner.RunWithParameters(world, person, scope, treeId, stackObject, []);
        }
        catch (SimulationException)
        {
        }
        finally
        {
            Array.Copy(savedTemps, person.Temporaries, savedTemps.Length);
        }
    }

    private static void RepairLegacyZeroCodeOwners(SimulationWorld world, XObject owner)
    {
        if (world.CodeOwnerScopes.ContainsKey(0)) return;
        var hasZeroFrame = false;
        foreach (var frame in owner.SavedStack)
        {
            if (frame.Tree != ushort.MaxValue && frame.CodeOwner == 0)
            {
                hasZeroFrame = true;
                break;
            }
        }
        if (!hasZeroFrame) return;

        short currentCodeOwner = 0;
        for (var i = 0; i < owner.SavedStack.Count; i++)
        {
            var saved = owner.SavedStack[i];
            if (saved.Tree == ushort.MaxValue)
            {
                currentCodeOwner = 0;
                continue;
            }

            if (saved.CodeOwner != 0)
            {
                currentCodeOwner = saved.CodeOwner;
                continue;
            }

            var treeId = (short)(saved.Tree & 0x7fff);
            var depth = i + 1;
            short resolved = 0;

            if (owner is XPerson person)
            {
                for (var r = person.SavedPersonObjectReferences.Count - 1; r >= 0; r--)
                {
                    var objRef = person.SavedPersonObjectReferences[r];
                    if (objRef.Value != depth || objRef.Target is not { } refTarget) continue;
                    var refOwner = world.ResolveCodeOwner(refTarget);
                    if (refOwner != 0 && world.CodeOwnerScopes.GetValueOrDefault(refOwner)?.Find(treeId) is not null)
                    {
                        resolved = refOwner;
                        break;
                    }
                }
            }

            if (resolved == 0 && currentCodeOwner != 0 &&
                world.CodeOwnerScopes.GetValueOrDefault(currentCodeOwner)?.Find(treeId) is not null)
            {
                resolved = currentCodeOwner;
            }

            if (resolved == 0 && saved.StackObject != 0 &&
                world.ObjectById(saved.StackObject) is { } stackObj)
            {
                var stackOwner = world.ResolveCodeOwner(stackObj);
                if (stackOwner != 0 && world.CodeOwnerScopes.GetValueOrDefault(stackOwner)?.Find(treeId) is not null)
                    resolved = stackOwner;
            }

            if (resolved != 0)
            {
                owner.SavedStack[i] = saved with { CodeOwner = resolved };
                currentCodeOwner = resolved;
            }
        }
    }

    private static void InitializeGenericSimsCallPersonTypeRecords(XObject instance, ObjectRegistry? typeRegistry, byte language)
    {
        if (instance is not XPerson person) return;
        person.GenericSimsCallPersonTypeRecords.Clear();
        if (typeRegistry is not null)
        {
            foreach (var entry in typeRegistry.Entries)
            {
                var objectType = unchecked((short)entry.Definition[ObjdField.Type]);
                if (!GenericSimsCallPersonRecordTypes.Contains(objectType)) continue;
                person.GenericSimsCallPersonTypeRecords.Add(new GenericSimsCallPersonTypeRecord(
                    entry.Index,
                    checked((short)(person.GenericSimsCallPersonTypeRecords.Count + 1)),
                    unchecked((int)entry.Guid),
                    objectType,
                    entry.CatalogString(0, language),
                    entry.Chunk.Label));
            }
        }

        person.GenericSimsCallPersonTypeRecordIndex = person.GenericSimsCallPersonTypeRecords
            .FirstOrDefault(record => record.TypeRecordKey == instance.TypeRecord?.Key) is { Index: > 0 } current
            ? current.Index
            : (short)0;
    }

    private static IffFile? OpenAdjacentNeighborhoodFile(IffFile lot)
    {
        if (string.IsNullOrWhiteSpace(lot.Source)) return null;
        var houses = Path.GetDirectoryName(Path.GetFullPath(lot.Source));
        var neighborhood = houses is null ? null : Directory.GetParent(houses)?.FullName;
        var path = neighborhood is null ? null : Path.Combine(neighborhood, "Neighborhood.iff");
        if (path is not null && !File.Exists(path)) path = Path.Combine(neighborhood!, "UserData", "Neighborhood.iff");
        if ((path is null || !File.Exists(path)) && houses is not null) path = Path.Combine(houses, "Neighborhood.iff");
        return path is not null && File.Exists(path) ? IffFile.Open(path) : null;
    }

    private static int TypeAttributeCount(ObjectEntry entry, uint typeAttributeGuid, ObjectRegistry? registry)
    {
        var count = unchecked((short)entry.Definition[ObjdField.NumTypeAttributes]);
        if (count is < 0 or > 31999) count = 0;
        if (registry is not null && typeAttributeGuid != 0 && typeAttributeGuid != entry.Definition.Guid &&
            registry.Find(typeAttributeGuid) is { } proxyEntry)
        {
            var proxyCount = unchecked((short)proxyEntry.Definition[ObjdField.NumTypeAttributes]);
            if (proxyCount is > 0 and <= 31999 && proxyCount > count)
                count = proxyCount;
        }
        return count > 0 ? count : entry.Definition[ObjdField.NumAttributes];
    }

    private static IReadOnlyDictionary<uint, short[]>? ReadMergedTypeAttributes(IffFile lot, IffFile? neighborhood = null)
    {
        Dictionary<uint, short[]>? merged = null;
        var neighborhoodFile = neighborhood ?? OpenAdjacentNeighborhoodFile(lot);
        if ((neighborhoodFile?.Find(TypeAttributesType, 1) ?? neighborhoodFile?.OfType(TypeAttributesType).FirstOrDefault()) is { } neighborhoodChunk)
        {
            merged = new Dictionary<uint, short[]>();
            foreach (var (guid, values) in TypeAttributes.Read(neighborhoodFile!, neighborhoodChunk).AttributesByGuid)
                merged[guid] = values.ToArray();
        }

        if ((lot.Find(TypeAttributesType, 1) ?? lot.OfType(TypeAttributesType).FirstOrDefault()) is { } lotChunk)
        {
            merged ??= new Dictionary<uint, short[]>();
            foreach (var (guid, values) in TypeAttributes.Read(lot, lotChunk).AttributesByGuid)
                merged[guid] = values.ToArray();
        }

        return merged;
    }

    private static Neighbors? ReadAdjacentNeighbors(IffFile lot, IffFile? neighborhood = null)
    {
        var file = neighborhood ?? OpenAdjacentNeighborhoodFile(lot);
        if (file is null) return null;
        var chunk = file.OfType(ResourceType.Parse("NBRS")).FirstOrDefault();
        if (chunk is null) return null;
        var neighbors = Neighbors.ReadRecoveringSupportedPrefix(file, chunk);
        if (!neighbors.IsComplete)
        {
            Console.Error.WriteLine($"Native load: recovered {neighbors.CompleteSlotPrefix} complete slots from malformed neighbor roster in {file.Source}; remaining slots are unknown and the roster will not be saved.");
        }
        return neighbors;
    }

    private static IReadOnlyDictionary<uint, int>? ReadAdjacentFamilyNumbers(IffFile lot, IffFile? neighborhood = null)
    {
        var file = neighborhood ?? OpenAdjacentNeighborhoodFile(lot);
        if (file is null) return null;

        var result = new Dictionary<uint, int>();
        foreach (var chunk in file.OfType(ResourceType.Parse("FAMI")))
        {
            if (chunk.Id == 0) continue;
            var family = Family.Read(file, chunk);
            foreach (var member in family.Members) result[member] = chunk.Id;
        }
        return result;
    }

    private static void RestoreNeighbors(SimulationWorld world, Neighbors savedNeighbors, ObjectRegistry? registry,
        IReadOnlyDictionary<uint, int>? familyNumbersByGuid)
    {
        world.NeighborRosterComplete = savedNeighbors.IsComplete;
        world.CompleteNeighborSlotPrefix = savedNeighbors.CompleteSlotPrefix;
        var bySlot = savedNeighbors.Entries.ToDictionary(neighbor => neighbor.Slot);
        for (var slot = 0; slot < savedNeighbors.SlotCount; slot++)
        {
            if (!bySlot.TryGetValue(slot, out var saved))
            {
                world.NeighborWalkOrder.Add(null);
                continue;
            }

            var entry = registry?.Find(saved.Guid);
            if (registry is not null && entry is null)
            {
                world.NeighborWalkOrder.Add(null);
                continue;
            }
            var definition = entry?.Definition.Fields.Select(value => unchecked((short)value)).ToArray() ?? [];
            var neighbor = new NeighborState(saved.NeighborId, definition)
            {
                Name = saved.Name,
                TypeRecordKey = unchecked((int)saved.Guid),
                PersonRecordVersion = saved.PersonData is null ? 0 : saved.RecordVersion,
                FriendEligibilityObjectFlagsB4 = entry is null ? null : entry.Scan == ObjectScan.People ? 4u : 0u,
                RelationshipsChangedFlag24 = true,
            };
            if (saved.PersonData is { } personData)
                personData.Take(neighbor.PersonData.Length).ToArray().CopyTo(neighbor.PersonData, 0);
            // FAMI membership is authoritative over saved NBRS PersonData.FamilyNumber, which can be stale.
            if (familyNumbersByGuid is not null)
                neighbor.PersonData[(int)PersonData.FamilyNumber] = familyNumbersByGuid.TryGetValue(saved.Guid, out var familyNumber)
                    ? unchecked((short)familyNumber)
                    : (short)0;
            foreach (var (otherId, values) in saved.Relationships)
            {
                var targetId = checked((short)otherId);
                neighbor.Relationships.Resize(targetId, values.Count);
                for (var index = 0; index < values.Count; index++)
                    neighbor.Relationships.Set(targetId, index, values[index]);
            }
            world.Neighbors[saved.NeighborId] = neighbor;
            world.NeighborWalkOrder.Add(neighbor);
        }

        if (registry is not null && world.NeighborRosterComplete)
            RestoreCatalogNeighbors(world, registry, familyNumbersByGuid);
    }

    private static void RestoreCatalogNeighbors(SimulationWorld world, ObjectRegistry registry,
        IReadOnlyDictionary<uint, int>? familyNumbersByGuid)
    {
        foreach (var entry in registry.Entries)
        {
            var objectType = unchecked((short)entry.Definition[ObjdField.Type]);
            if (!GenericSimsCallPersonRecordTypes.Contains(objectType)) continue;
            if (entry.Definition[ObjdField.MasterId] != 0 && entry.Definition[ObjdField.SubIndex] != ushort.MaxValue) continue;
            if (entry.Definition[ObjdField.Disabled] != 0) continue;

            var key = unchecked((int)entry.Guid);
            if (world.NeighborWalkOrder.Any(existing => existing is not null && existing.TypeRecordKey == key)) continue;

            var slot = -1;
            for (var i = 0; i < world.NeighborWalkOrder.Count; i++)
            {
                if (world.NeighborWalkOrder[i] is null && !world.Neighbors.ContainsKey(checked((short)(i + 1))))
                    slot = i;
            }
            if (slot < 0)
            {
                slot = world.NeighborWalkOrder.Count;
                world.NeighborWalkOrder.Add(null);
            }
            while (world.Neighbors.ContainsKey(checked((short)(slot + 1))))
            {
                slot = world.NeighborWalkOrder.Count;
                world.NeighborWalkOrder.Add(null);
            }

            var neighborId = checked((short)(slot + 1));
            var definition = entry.Definition.Fields.Select(value => unchecked((short)value)).ToArray();
            var neighbor = new NeighborState(neighborId, definition)
            {
                TypeRecordKey = key,
                FriendEligibilityObjectFlagsB4 = entry.Scan == ObjectScan.People ? 4u : 0u,
                RelationshipsChangedFlag24 = true,
            };
            if (familyNumbersByGuid is not null && familyNumbersByGuid.TryGetValue(entry.Guid, out var familyNumber))
                neighbor.PersonData[(int)PersonData.FamilyNumber] = unchecked((short)familyNumber);
            world.Neighbors[neighborId] = neighbor;
            world.NeighborWalkOrder[slot] = neighbor;
        }
    }

    private static void ApplyLoadedClockEligibility(
        SimulationWorld world, XObject instance, uint effectiveGuid, int version, int? savedFlags)
    {
        if (version <= 0x35) return;

        var entry = world.ClockManager.Entries[instance.ClockManagerIndex - 1];
        var flags = LotObjects.IsPlaceholder(effectiveGuid)
            ? entry.Flags | 0x00010000u
            : unchecked((uint)(savedFlags ?? unchecked((int)entry.Flags)));

        if (version < 0x39)
        {
            flags &= 0x0000ffff;
            flags |= 0x00010000;
        }

        entry.Flags = flags;
    }

    private static ResourceFormatException MissingChunk(IffFile lot, ResourceType type) =>
        new(lot.Source, type.ToString(), 0, "required saved-lot chunk is missing");

    private static void PadSlotVector(XObject instance)
    {
        var length = 1 + instance.FootprintSlots.Count;
        while (instance.Slots.Count < length) instance.Slots.Add(0);
    }

    private static void RestoreSlotDefinitions(XObject instance, ObjectEntry entry)
    {
        RestoreObjectSlotDefinitions(instance, entry);
        if (instance is not XPerson) return;
        foreach (var heightCode in new[] { 6, 0, 1, 1, 1 })
            instance.FootprintSlots.Add(new ObjectFootprintSlot { HeightCode = heightCode });
        if (instance.RuntimeSlots.Count == 0)
        {
            var slot = new ObjectRuntimeSlot();
            slot.WriteWord(0x08, BitConverter.SingleToInt32Bits(2.0f));
            slot.WriteWord(0x0c, -1);
            slot.WriteWord(0x14, -1);
            instance.RuntimeSlots.Add(slot);
        }
    }

    private static void RestoreObjectSlotDefinitions(XObject instance, ObjectEntry entry)
    {
        var slotsId = entry.Definition[ObjdField.SlotsId];
        if (slotsId == 0) return;
        var chunk = entry.File.OfType(SlotsType).FirstOrDefault(candidate => candidate.Id == slotsId);
        if (chunk is null) return;
        SlotTable table;
        try { table = SlotTable.Read(entry.File, chunk); }
        catch (ResourceFormatException) { return; }
        var slots = table.Slots;
        for (var slotIndex = 0; slotIndex < slots.Count; slotIndex++)
        {
            var slot = slots[slotIndex];
            instance.DefinitionSlots.Add(slot);
            switch (slot.Type)
            {
                case 0:
                    instance.FootprintSlots.Add(ObjectFootprintSlot.FromDefinition(slot));
                    break;
                case 1:
                    instance.RuntimeSlots.Add(ObjectRuntimeSlot.FromObjectSlot(slot, slotIndex));
                    break;
                case 3:
                    instance.RoutingSlots.Add(RoutingSlotRequest.FromDefinition(slot));
                    break;
            }
        }
    }

    internal static uint? PlaceholderGuid(ObjectTypeEntry type, PersonState? person = null)
    {
        if (type.ObjectType != 2) return 0x3C08965F;
        if (type.Guid == 0x4A70DF92 || unchecked((uint)type.Field0x8C) == 0x4A70DF92) return 0x4A70DF92;
        if (type.Guid == 0x7BEA0977 || unchecked((uint)type.Field0x8C) == 0x7BEA0977) return 0x7BEA0977;
        if (person is not null && person.PersonData.Length > (int)PersonData.Gender)
        {
            var gender = person.PersonData[(int)PersonData.Gender];
            if ((gender & 2) != 0) return 0x4A70DF92;
            if ((gender & 4) != 0) return 0x7BEA0977;
        }
        return 0x7FD96B54;
    }
}
