using System.Buffers.Binary;
using System.Diagnostics;
using System.Security.Cryptography;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsSimulation;

internal sealed partial class SimulationServer
{

    private string ReloadAfterHouseholdCreation(ushort familyChunkId, int spawnCenterX, int spawnCenterY)
    {
        var previous = world;
        var autonomyForced = previous?.AutonomyForced ?? true;
        RemoveTileCursor();
        ResetAppearanceTransitions();
        audio?.Reset();

        var userData = Neighborhoods.UserData(profile);
        registry = registry?.WithRefreshedPeople(Path.Combine(userData, "Characters")) ?? registry;
        var lotPath = Path.Combine(userData, "Houses", $"House{house:D2}.iff");
        var setup = WorldBootstrap.Load(game, lotPath, language, () => true, house,
            autonomyForced: autonomyForced, activeFamilyChunkId: familyChunkId, existingRegistry: registry);
        lot = setup.Lot;
        ClearBuildHistory();
        world = setup.World;
        world[SimulationGlobal.SimlessBuildMode] = 0;
        ResetLotValuationBaseline();
        setup.World[SimulationGlobal.FreeWill] = (short)(autonomyForced ? 1 : 0);
        InitializeFameCallbackTarget(setup.World);
        neighborhoodPath = setup.NeighborhoodPath;
        neighborhood = setup.Neighborhood;
        activeFamilyChunkId = setup.ActiveFamilyChunkId;
        HydrateTypeAttributesFromNeighborhood(world, lot, neighborhood);
        simulationError = null;
        viewerMode = 0;
        viewLevel = 1;
        editingView = false;
        doorWindowBuildToolActive = false;
        wallpaperBuildToolActive = false;
        tileCursor = null;
        if (viewerScale != 0) world[SimulationGlobal.ZoomLevelSML] = viewerScale;
        world[SimulationGlobal.Mode] = viewerMode;
        ClampAwayLotEditingState();
        if (registry is not null) world.UiTextFile ??= registry.UiText;
        world.PlaySoundEvent = (name, owner, pan, zoom) =>
        {
            char? voiceCode = null;
            int? pianoSkill = null;
            if (world.ObjectById(owner) is XPerson person)
            {
                var age = person[PersonData.PersonAge];
                var gender = person[PersonData.Gender];
                voiceCode = PersonAgeCategory.IsChild(age) ? 'k' : ((gender & 1) != 0 ? 'f' : 'm');
                pianoSkill = person[PersonData.CreativitySkill] / 100;
            }

            var played = audio!.PlayForSimulationObject(name, owner, pan, zoom, voiceCode, pianoSkill);
            if (played) world.PositionalSoundOwners.Add(owner);
            return played;
        };
        world.StopOwnerSounds = owner =>
        {
            audio!.RemoveOwner(owner);
            world.PositionalSoundOwners.Remove(owner);
        };
        AttachTutorialFlash(world);
        if (traceActions) world.CaptureExecutionTrace = true;
        selectedSim = DefaultSelectedSimId();
        SyncSelectedSimFlags(world, selectedSim);
        var familyResource = setup.Neighborhood?.Find(ResourceType.Parse("FAMI"), familyChunkId);
        var memberInstantiation = EnsureSelectedHouseholdMember(familyResource is null || setup.Neighborhood is null
            ? null
            : Family.Read(setup.Neighborhood, familyResource), spawnCenterX, spawnCenterY);
        world.AutonomyHost = BuildAutonomyHost(world, setup.Global ?? global!, house);
        world.AnimationSound = HandleAnimationSound;
        autoSpeedSaved = -1;
        SetSimulationSpeed(0);
        lastRunningSpeed = 1;
        dialogResumeSpeed = HasBlockingDialog(world) ? 1 : 0;
        AttachNoticeListener(setup.World);
        if (audio?.Enabled == true)
            audio.PlayLotAmbience(house);
        InitializeViewLevelFromSelectedSim();
        Export();
        Write(new { type = "state", state = State() });
        return memberInstantiation;
    }

    private string EnsureSelectedHouseholdMember(Family? family, int centerX, int centerY)
    {
        if (world is null || family is null) return "no-active-family";
        if (family.Members.Count == 0) return "empty-family";
        var targetMemberGuids = (world.FamilyBudget as FamilyBudget)?.RestrictedActivePersonKeys is { Count: > 0 } restrictedKeys
            ? restrictedKeys.Select(static k => unchecked((uint)k)).ToArray()
            : family.Members.ToArray();
        short firstId = 0;
        string? status = null;
        foreach (var guid in targetMemberGuids)
        {
            if (guid == 0) continue;
            var existing = world.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person.TypeRecord?.Key == unchecked((int)guid));
            if (existing is not null)
            {
                if (firstId == 0) firstId = existing.Id;
                status ??= "already-present";
                continue;
            }

            if (world.ObjectFactory?.Invoke(unchecked((int)guid)) is not XPerson person)
            {
                status ??= "character-factory-failed";
                continue;
            }
            world.Add(person);
            world.InitializeCreatedObject(person);
            world.InitializeCreatedPerson(person);
            if (!world.FindGoodLocation(person, centerX, centerY, out var position))
            {
                world.Remove(person.Id);
                status ??= "location-search-failed";
                continue;
            }
            world.PlaceCreatedObject(person, position);
            if (firstId == 0)
            {
                firstId = person.Id;
                status = $"placed:{firstId}@{position.X},{position.Y},{position.Height}";
            }
        }
        world.RefreshNeighborInteractionManager();
        if (firstId != 0)
        {
            selectedSim = firstId;
            SyncSelectedSimFlags(world, selectedSim);
        }
        return status ?? "empty-family";
    }

    private static void SyncSelectedSimFlags(SimulationWorld target, short simId)
    {
        target[SimulationGlobal.SelectedPersonID] = simId;
        foreach (var candidate in target.WalkOrder.OfType<XPerson>())
            candidate.Flags = candidate.Id == simId ? (candidate.Flags | 2u) : (candidate.Flags & ~2u);
    }

    private void RemoveTileCursor()
    {
        if (tileCursor is not null && world?.ObjectById(tileCursor.Id) is not null) world.Remove(tileCursor.Id);
        tileCursor = null;
    }

    private static IReadOnlyList<object> PlacementTiles(XObject item, IReadOnlyList<XObject>? group, ObjectPosition destination)
    {
        var members = group ?? [item];
        var rootState = item.SavedMultiTileState;
        var rootOffsetX = (rootState?.Value0x1A0 ?? 0) << 4;
        var rootOffsetY = (rootState?.Value0x1A4 ?? 0) << 4;
        var rootOffsetLevel = rootState?.Value0x1A8 ?? 0;
        return members.Select(member =>
        {
            var state = member.SavedMultiTileState;
            var memberX = (destination.X - rootOffsetX + ((state?.Value0x1A0 ?? 0) << 4)) >> 4;
            var memberY = (destination.Y - rootOffsetY + ((state?.Value0x1A4 ?? 0) << 4)) >> 4;
            var memberLevel = destination.Height - rootOffsetLevel + (state?.Value0x1A8 ?? 0);
            return (object)new { x = memberX, y = memberY, level = memberLevel };
        }).ToArray();
    }

    private static void PositionPreviewMembers(SimulationWorld current, XObject root, IReadOnlyList<XObject> members,
        ObjectPosition destination, XObject? referenceObject = null, int referenceSlot = -1)
    {
        if (referenceObject is not null && referenceSlot >= 0 && members.Count == 1)
        {
            var slotNumber = checked((short)(referenceSlot + 1));
            root[ObjectData.ContainerId] = referenceObject.ClockManagerIndex;
            root[ObjectData.SlotNumber] = slotNumber;
            root[ObjectData.ParentId] = referenceObject.ClockManagerIndex;
            root[ObjectData.SlotHierNumber] = slotNumber;
            current.SetObjectPosition(root, referenceObject.Position);
            return;
        }
        var rootState = root.SavedMultiTileState;
        var rootOffsetX = (rootState?.Value0x1A0 ?? 0) << 4;
        var rootOffsetY = (rootState?.Value0x1A4 ?? 0) << 4;
        var rootOffsetLevel = rootState?.Value0x1A8 ?? 0;
        foreach (var member in members)
        {
            var state = member.SavedMultiTileState;
            current.SetObjectPosition(member, new ObjectPosition(
                destination.X - rootOffsetX + ((state?.Value0x1A0 ?? 0) << 4),
                destination.Y - rootOffsetY + ((state?.Value0x1A4 ?? 0) << 4),
                destination.Height - rootOffsetLevel + (state?.Value0x1A8 ?? 0)));
        }
    }

    private static int Coordinate(JsonElement request, string property) =>
        request.TryGetProperty(property, out var value) && value.TryGetInt32(out var coordinate)
            ? coordinate : throw new ArgumentException($"{property} must be an integer in sixteenths of a tile");

    private static int TileCoordinate(JsonElement request, string property) =>
        request.TryGetProperty(property, out var value) && value.TryGetInt32(out var coordinate)
            ? coordinate : throw new ArgumentException($"{property} must be an integer lot tile coordinate");

    private XPerson SelectedPerson() => world?.ObjectById(selectedSim) as XPerson
        ?? throw new InvalidOperationException("Select a Sim before requesting an interaction.");

    private static byte MenuIndex(ActionQueueSlot choice)
    {
        if (choice.RawDword10 is < byte.MinValue or > byte.MaxValue)
            throw new NotSupportedException($"Interaction index {choice.RawDword10} exceeds the runtime protocol's 8-bit interaction field.");
        return (byte)choice.RawDword10;
    }

    private XObject RequestObject(JsonElement request, string property)
    {
        if (world is null) throw new InvalidOperationException("There is no loaded native lot.");
        if (!request.TryGetProperty(property, out var value) || !value.TryGetInt16(out var id))
            throw new ArgumentException($"{property} must be an object ID.");
        return world.ObjectById(id) ?? throw new ArgumentException($"Object {id} is not in the active lot.");
    }

    // Houses 40-42 are Vacation Island winter lots.
    private bool GroundSnow() => house is 40 or 41 or 42;

    private (ObjectPosition Position, XObject Target) GroundPreview(JsonElement request, bool persistent = false)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        var x = Coordinate(request, "x");
        var y = Coordinate(request, "y");
        var level = request.TryGetProperty("level", out var levelValue) && levelValue.TryGetInt32(out var parsedLevel)
            ? parsedLevel : throw new ArgumentException("level must be an integer");
        if (x < 0 || y < 0 || x >= LotWidth * 16 || y >= LotHeight * 16 || level < 1 || level > Stories)
            throw new ArgumentException("Ground position is outside the lot.");
        var target = (persistent ? current.ObjectFactory : current.PlacementPreviewFactory)?.Invoke(0x7c4)
            ?? throw new InvalidOperationException("The installed Go Here object is unavailable.");
        var position = new ObjectPosition(x, y, level);
        try
        {
            current.Add(target);
            current.InitializeCreatedObject(target);
            current.SetObjectPosition(target, position);
            return (position, target);
        }
        catch
        {
            current.Remove(target.Id);
            throw;
        }
    }

    private static string Slot(JsonElement request) =>
        request.TryGetProperty("slot", out var value) && value.ValueKind == JsonValueKind.String && value.GetString() is { Length: > 0 and <= 64 } slot
            ? new string(slot.Where(character => char.IsAsciiLetterOrDigit(character) || character is '-' or '_').ToArray()) is { Length: > 0 } safe ? safe : "manual"
            : "manual";

    private string SaveEnvelopePath(string slot) => Path.Combine(profile, "Saves", Neighborhoods.StorageSlot(slot, Neighborhoods.Current) + ".json");

    private string SavePath(string slot) => Path.Combine(Saves, Neighborhoods.StorageSlot(slot, Neighborhoods.Current) + ".iff");

    private string SaveRuntimePath(string slot) => Path.Combine(Saves, Neighborhoods.StorageSlot(slot, Neighborhoods.Current) + ".runtime.json");

    private string SaveNeighborhoodPath(string slot) => Path.Combine(Saves, Neighborhoods.StorageSlot(slot, Neighborhoods.Current) + ".neighborhood.iff");

    private static string CanonicalRuntimePath(string housePath) => housePath + ".runtime.json";

    private void UpdatePreSaveState(SimulationWorld current, IffFile currentLot) =>
        UpdatePreSaveState(current, currentLot, activeFamilyChunkId);

    private void UpdatePreSaveState(SimulationWorld current, IffFile currentLot, ushort? targetFamilyChunkId)
    {
        if (current[SimulationGlobal.LotSize] <= 3)
            current[SimulationGlobal.LotSize] = LotGeometry.LotDimension;
        current[SimulationGlobal.Hour] = checked((short)current.Clock.Hour);
        current[SimulationGlobal.Minute] = checked((short)current.Clock.Minute);

        var lotTiles = LotTiles.Read(currentLot);
        var pool = LotPool.Read(currentLot);
        var hasArchitecture = false;
        for (var level = 1; level <= 2 && !hasArchitecture; level++)
        {
            var walls = LotWalls.Read(currentLot, level);
            var floors = LotFloors.Read(currentLot, level);
            for (var x = 0; x < LotWalls.Size && !hasArchitecture; x++)
            for (var y = 0; y < LotWalls.Size; y++)
            {
                if (!lotTiles.InsideLot(x, y)) continue;
                if ((walls[x, y][0] & 0x3f) != 0 || floors[x, y] != 0 || (level == 1 && pool.IsPool(x, y, 1)))
                {
                    hasArchitecture = true;
                    break;
                }
            }
        }

        var hasBaby = false;
        var hasPhone = false;
        var hasBuildableObject = false;
        var hasCashRegister = false;
        var hasCat4B = false;
        var hasCat4C = false;
        var hasShopDisplay = false;
        var hasCat61 = false;
        var filterFlags = 0u;

        foreach (var item in current.Objects.Values)
        {
            var category = item[ObjectData.Category];
            if (category > 0x3b)
            {
                if (category < 0x51)
                {
                    if (category == 0x50) filterFlags |= 0x80;
                    else if (category == 0x47) filterFlags |= 0x1;
                    else if (category == 0x48) filterFlags |= 0x2;
                    else if (category == 0x49) filterFlags |= 0x4;
                    else if (category == 0x4a) hasShopDisplay = true;
                    else if (category == 0x4b) hasCat4B = true;
                    else if (category == 0x4c) hasCat4C = true;
                    else if (category == 0x4d) filterFlags |= 0x40;
                }
                else if (category == 0x53) filterFlags |= 0x400;
                else if (category == 0x54) filterFlags |= 0x100;
                else if (category == 0x55) filterFlags |= 0x200;
                else if (category is 0x5d or 0x5e) filterFlags |= 0x1000;
                else if (category == 0x5f) filterFlags |= 0x800;
                else if (category == 0x61) hasCat61 = true;
            }
            else if (category is 0x3a or 0x3b)
            {
                hasShopDisplay = true;
            }
            else if (category < 0x1f)
            {
                if (category == 0x1e) hasShopDisplay = true;
                else if (category < 0xb)
                {
                    if (category == 10) hasCashRegister = true;
                    else if (category == 1 && item.Position.X >= 0 && item.Position.Y >= 0) hasBaby = true;
                    else if (category == 4) filterFlags |= 0x1;
                    else if (category == 9) hasPhone = true;
                }
                else if (category == 0x11 || category is >= 0x15 and <= 0x18) hasShopDisplay = true;
                else if (category is 0x19 or 0x1a) filterFlags |= 0x2;
            }
            else if (category < 0x32)
            {
                if (category is 0x31 or 0x2b) filterFlags |= 0x40;
                else if (category is 0x27 or 0x28) hasShopDisplay = true;
                else if (category is >= 0x2e and <= 0x30) filterFlags |= 0x1;
            }
            else if (category == 0x32) filterFlags |= 0x2;
            else if (category == 0x33) filterFlags |= 0x40;

            if (item is XPerson || (item.Definition is { Length: > (int)ObjdField.Type } && item.Definition[(int)ObjdField.Type] == 7))
                continue;
            if (item.MultiTileMasterId != 0 && item.MultiTileMasterId != item.Id)
                continue;
            if (item.Position.X >= 0 && item.Position.Y >= 0)
            {
                var roomSort = item.Definition is { Length: > (int)ObjdField.RoomSort } ? item.Definition[(int)ObjdField.RoomSort] : (short)0;
                var funcSort = item.Definition is { Length: > (int)ObjdField.FunctionSort } ? item.Definition[(int)ObjdField.FunctionSort] : (short)0;
                var buildMode = ObjectBuildModeType(item);
                if ((roomSort != 0 || funcSort != 0 || buildMode != 0) && lotTiles.InsideLot(item.Position.X >> 4, item.Position.Y >> 4))
                    hasBuildableObject = true;
            }
        }

        if (!hasCashRegister)
        {
            hasCat4B = false;
            hasCat4C = false;
            hasShopDisplay = false;
        }
        if (hasShopDisplay) filterFlags |= 0x8;
        if (hasCat4B) filterFlags |= 0x10;
        if (hasCat4C || hasCat61) filterFlags |= 0x20;

        current[SimulationGlobal.LotHasHouse] = (short)(hasArchitecture || hasBuildableObject ? 1 : 0);
        current[SimulationGlobal.FilterFlagsForTransitScreen] = unchecked((short)filterFlags);

        if (targetFamilyChunkId is { } familyChunkId &&
            current.FamilyBudget is FamilyBudget budget &&
            budget.ActiveFamily is { } activeFamily &&
            (budget.FamilyChunkId == familyChunkId || budget.FamilyChunkId is null))
        {
            var flags = activeFamily.Flags & ~0xbu;
            if (hasBaby) flags |= 1u;
            if (hasPhone) flags |= 2u;
            var updatedFamily = UpdateFamilyFields(activeFamily, familyChunkId, flags: flags);
            budget.ActiveFamily = updatedFamily;
            if (neighborhood is not null)
            {
                var famiType = ResourceType.Parse("FAMI");
                var existingChunk = neighborhood.Find(famiType, familyChunkId);
                neighborhood = neighborhood.WithAddedOrReplacedChunk(famiType, familyChunkId,
                    updatedFamily.Write(familyChunkId), existingChunk?.Flags ?? 0, existingChunk?.Label ?? "");
            }
        }
    }

    private void DeleteUnhousedCharacters(string userData)
    {
        if (world is null) return;
        var families = neighborhood?.OfType(ResourceType.Parse("FAMI"))
            .Select(chunk => SimsEngine.Formats.Family.Read(neighborhood, chunk)).ToArray() ?? [];
        var characters = Path.GetFullPath(Path.Combine(userData, "Characters")) + Path.DirectorySeparatorChar;
        var guids = world.Neighbors.ToDictionary(pair => pair.Key, pair => unchecked((uint)pair.Value.TypeRecordKey));
        foreach (var id in world.DeleteUnhousedCharacters(guid => families.Any(family => family.Members.Contains(unchecked((uint)guid)))))
        {
            if (registry?.Find(guids[id]) is not { Scan: ObjectScan.People } entry) continue;
            var file = Path.GetFullPath(entry.Source);
            if (file.StartsWith(characters, StringComparison.OrdinalIgnoreCase) && File.Exists(file)) File.Delete(file);
            registry?.Remove(guids[id]);
        }
    }

    private object CreateHousehold(JsonElement request)
    {
        if (speed != 0 || simulatorBlocked)
            throw new InvalidOperationException("Household creation requires a paused residential lot without a blocking dialog or active trip");

        if (!request.TryGetProperty("familyName", out var familyNameElement) ||
            familyNameElement.ValueKind != JsonValueKind.String ||
            familyNameElement.GetString() is not { Length: > 0 } familyName)
            throw new ArgumentException("Family name is required.", nameof(request));

        var filteredChars = new HashSet<char> {
            '\\', '/', '|', '*', '?', ':', '<', '>', '\"', '\'', '%', '(', ')', '&', ';', '@', '!', '#', ',', '.'
        };
        if (Encoding.UTF8.GetByteCount(familyName) > 24 ||
            familyName.Any(c => char.IsControl(c) || filteredChars.Contains(c)))
            throw new ArgumentException("Family name exceeds the original 24-byte field capacity or contains illegal characters.", nameof(request));

        if (!request.TryGetProperty("members", out var membersElement) ||
            membersElement.ValueKind != JsonValueKind.Array ||
            membersElement.GetArrayLength() is < 1 or > 8)
            throw new ArgumentException("A household must contain one to eight Sims.", nameof(request));

        var members = membersElement.EnumerateArray().Select(m =>
        {
            var name = m.TryGetProperty("name", out var n) ? n.GetString() ?? "" : "";
            if (string.IsNullOrWhiteSpace(name)) throw new ArgumentException("Member name cannot be empty.");
            var bio = m.TryGetProperty("bio", out var b) ? b.GetString() ?? "" : "";
            var code = m.TryGetProperty("code", out var c) ? c.GetString() ?? "" : "";
            var skin = m.TryGetProperty("skin", out var s) ? s.GetString() ?? "lgt" : "lgt";
            var headChoice = m.TryGetProperty("headChoice", out var hc) && hc.ValueKind == JsonValueKind.String
                ? hc.GetString()
                : m.TryGetProperty("head", out var hAlt) && hAlt.ValueKind == JsonValueKind.String ? hAlt.GetString() : null;
            var bodyChoice = m.TryGetProperty("bodyChoice", out var bc) && bc.ValueKind == JsonValueKind.String
                ? bc.GetString()
                : m.TryGetProperty("body", out var bAlt) && bAlt.ValueKind == JsonValueKind.String ? bAlt.GetString() : null;
            var zodiac = m.TryGetProperty("zodiac", out var zProp) && zProp.ValueKind == JsonValueKind.Number && zProp.TryGetInt16(out var zVal)
                ? (short?)zVal : null;
            var isChild = (m.TryGetProperty("child", out var chProp) && chProp.ValueKind == JsonValueKind.True) ||
                (code.Length >= 2 && char.ToLowerInvariant(code[1]) == 'c') ||
                code.StartsWith("child", StringComparison.OrdinalIgnoreCase) ||
                (m.TryGetProperty("age", out var ageProp) && ageProp.ValueKind == JsonValueKind.String && string.Equals(ageProp.GetString(), "child", StringComparison.OrdinalIgnoreCase));
            var isFemale = (code.Length >= 1 && char.ToLowerInvariant(code[0]) == 'f') ||
                (string.IsNullOrEmpty(code) && m.TryGetProperty("gender", out var gProp) && gProp.ValueKind == JsonValueKind.String &&
                 gProp.GetString() is { Length: > 0 } genderText && char.ToLowerInvariant(genderText[0]) == 'f');
            var personality = m.TryGetProperty("personality", out var p) && p.ValueKind == JsonValueKind.Array
                ? p.EnumerateArray().Select(v => checked((short)v.GetInt32())).ToArray()
                : [500, 500, 500, 500, 500];
            return (Name: name, Bio: bio, Code: code, Skin: skin, Child: isChild, Female: isFemale, HeadChoice: headChoice, BodyChoice: bodyChoice, Zodiac: zodiac, Personality: personality);
        }).ToArray();

        if (!members.Any(member => !member.Child))
            throw new ArgumentException("A household must contain at least one adult Sim.", nameof(request));

        var moveIn = !request.TryGetProperty("moveIn", out var moveInElement) ||
            (moveInElement.ValueKind == JsonValueKind.True ||
             (moveInElement.ValueKind == JsonValueKind.String && bool.TryParse(moveInElement.GetString(), out var mb) && mb));

        var userDataPath = Neighborhoods.UserData(profile);
        var charDir = Path.Combine(userDataPath, "Characters");
        Directory.CreateDirectory(charDir);
        registry = EnsureRegistry().WithRefreshedPeople(charDir);

        var installRoot = ResolveInstallRoot();
        var templatePath = Path.Combine(userDataPath, "Characters", "User00000.iff");
        if (!File.Exists(templatePath))
            templatePath = Path.Combine(installRoot, "UserData", "Characters", "User00000.iff");
        if (!File.Exists(templatePath))
            templatePath = Path.Combine(installRoot, "TemplateUserData", "Characters", "User00000.iff");
        if (!File.Exists(templatePath))
            templatePath = Path.Combine(installRoot, "TemplateUserData", "UserData", "Characters", "User00000.iff");
        if (!File.Exists(templatePath))
        {
            var candidates = Directory.GetFiles(charDir, "User*.iff");
            var fallback = candidates.FirstOrDefault(file =>
            {
                try
                {
                    var iff = IffFile.Open(file);
                    if (iff.OfType(ResourceType.Objd).FirstOrDefault() is not { } objdChunk) return false;
                    var bodyId = Objd.Read(iff, objdChunk)[ObjdField.BodyStringsId];
                    if (bodyId == 0 || iff.Find(ResourceType.Str, bodyId) is not { } strChunk) return true;
                    var strings = StringTable.Read(iff, strChunk).ForLanguage(1);
                    var mode = strings.Count > 12 ? strings[12].Trim().ToLowerInvariant() : "";
                    return !mode.StartsWith("dog", StringComparison.Ordinal) && !mode.StartsWith("cat", StringComparison.Ordinal);
                }
                catch
                {
                    return false;
                }
            }) ?? candidates.FirstOrDefault();
            if (fallback != null) templatePath = fallback;
        }
        if (!File.Exists(templatePath))
            throw new FileNotFoundException($"Cannot find character template to clone in {userDataPath} or {game}.");

        var templateIff = IffFile.Open(templatePath);
        var memberGuids = new List<uint>();
        var memberNeighborIds = new List<short>();

        if (world is null)
        {
            neighborhoodPath = Path.Combine(userDataPath, "Neighborhood.iff");
            neighborhood = File.Exists(neighborhoodPath) ? IffFile.Open(neighborhoodPath) : null;
        }
        else
        {
            neighborhoodPath ??= Path.Combine(userDataPath, "Neighborhood.iff");
            if (neighborhood is null && File.Exists(neighborhoodPath))
                neighborhood = IffFile.Open(neighborhoodPath);
        }

        var nbrsChunk = neighborhood?.OfType(ResourceType.Parse("NBRS")).FirstOrDefault();
        var existingNeighbors = nbrsChunk is not null ? Neighbors.Read(neighborhood!, nbrsChunk) : null;
        var neighborEntries = existingNeighbors?.Entries
            .Where(e => registry is null || registry.Find(e.Guid) is not null)
            .ToList() ?? new List<Neighbor>();
        var usedNeighborIds = new HashSet<short>(neighborEntries.Select(e => e.NeighborId));
        var usedSlots = new HashSet<int>(neighborEntries.Select(e => e.Slot));

        var existingFamilies = neighborhood?.OfType(ResourceType.Parse("FAMI"))
            .Select(c => Family.Read(neighborhood!, c)).ToList() ?? new List<Family>();
        var usedFamilyChunkIds = new HashSet<int>(neighborhood?.OfType(ResourceType.Parse("FAMI")).Select(c => (int)c.Id) ?? []);
        var familyChunkId = 1;
        while (usedFamilyChunkIds.Contains(familyChunkId)) familyChunkId++;
        var familyNumber = existingFamilies.Count == 0 ? 1 : existingFamilies.Max(f => f.FamilyNumber) + 1;

        var requestedHouse = request.TryGetProperty("house", out var houseProp) && houseProp.ValueKind != JsonValueKind.Null
            ? (houseProp.TryGetInt16(out var parsedHouse) ? parsedHouse : throw new ArgumentException("house must be a 16-bit integer"))
            : (short)0;
        var familyBudget = 20_000;
        var targetHouse = (short)0;
        var lotPrice = 0;
        if (moveIn)
        {
            targetHouse = requestedHouse > 0 ? requestedHouse : house;
            if (targetHouse <= 0)
                throw new InvalidOperationException("Moving in requires a target residential lot");
            if (world?.SavedSimulationState is { } simi && targetHouse == house)
            {
                var (furnishingsValue, architectureValue) = CurrentLotValuation(simi);
                lotPrice = Math.Max(0, simi.Field0x9C + furnishingsValue + (int)(architectureValue * (world.ArchitectureValueMultiplier ?? 0.7f)));
            }
            else
            {
                var targetHousePath = Path.Combine(userDataPath, "Houses", $"House{targetHouse:D2}.iff");
                if (!File.Exists(targetHousePath))
                    throw new FileNotFoundException($"House{targetHouse:D2}.iff not found in {userDataPath}");
                var targetHouseFile = IffFile.Open(targetHousePath);
                if (targetHouseFile.Find(ResourceType.Parse("SIMI"), 1) is { } targetSimiChunk)
                {
                    var targetSimi = SimulationState.Read(targetHouseFile, targetSimiChunk);
                    lotPrice = Math.Max(0, targetSimi.Field0x9C + targetSimi.Field0xA0 + (int)(targetSimi.Field0xA4 * 0.7f));
                }
            }
            if (lotPrice > 20_000)
                throw new InvalidOperationException("The selected lot costs more than a new household can afford");
            familyBudget = 20_000 - lotPrice;
        }

        var charNumber = 1;
        var existingGuids = new HashSet<uint>(neighborEntries.Select(e => e.Guid));
        if (world != null)
        {
            foreach (var g in world.Neighbors.Values.Select(n => unchecked((uint)n.TypeRecordKey))) existingGuids.Add(g);
        }

        foreach (var member in members)
        {
            while (File.Exists(Path.Combine(charDir, $"User{charNumber:D5}.iff")))
            {
                charNumber++;
                if (charNumber > 32000) charNumber = 1;
            }
            var charFileName = $"User{charNumber:D5}.iff";
            var charPath = Path.Combine(charDir, charFileName);
            charNumber++;

            uint newGuid;
            do
            {
                var timePart = (uint)Environment.TickCount;
                var randPart = (uint)(Random.Shared.Next() & 0xffff);
                newGuid = (timePart << 16) ^ randPart;
            } while (newGuid == 0 || !existingGuids.Add(newGuid));

            memberGuids.Add(newGuid);

            var objdChunk = templateIff.Find(ResourceType.Parse("OBJD"), 128)
                ?? throw new InvalidDataException("Template person has no OBJD #128 chunk.");
            var objdBytes = objdChunk.Data.ToArray();
            var templateGuid = BinaryPrimitives.ReadUInt32LittleEndian(objdBytes.AsSpan(0x1c, 4));
            BinaryPrimitives.WriteUInt32LittleEndian(objdBytes.AsSpan(0x8c, 4), templateGuid);
            BinaryPrimitives.WriteUInt32LittleEndian(objdBytes.AsSpan(0x1c, 4), newGuid);

            var ctssChunk = templateIff.Find(ResourceType.Parse("CTSS"), 2000);
            byte[] ctssBytes;
            if (ctssChunk is not null)
            {
                var ctssTable = StringTable.Read(templateIff, ctssChunk);
                ctssBytes = UpdateCtssStrings(ctssTable, member.Name, member.Bio);
            }
            else
            {
                var ctssEncoding = ResourceReader.EncodingForLanguage(1);
                using var ms = new MemoryStream();
                using var w = new BinaryWriter(ms);
                w.Write((short)-3);
                w.Write((short)2);
                w.Write((byte)1);
                w.Write(ctssEncoding.GetBytes(member.Name));
                w.Write((byte)0);
                w.Write((byte)0);
                w.Write((byte)1);
                w.Write(ctssEncoding.GetBytes(member.Bio));
                w.Write((byte)0);
                w.Write((byte)0);
                w.Flush();
                ctssBytes = ms.ToArray();
            }

            var isChild = member.Child;
            var isFemale = member.Female;
            var strChunk = templateIff.Find(ResourceType.Parse("STR#"), 200);
            var strTable = strChunk is not null ? StringTable.Read(templateIff, strChunk) : null;
            var strBytes = UpdateBodystrings(strTable, isChild, isFemale, member.BodyChoice, member.HeadChoice, member.Skin);

            var newCharIff = templateIff.WithChunkDataResized(ResourceType.Parse("OBJD"), 128, objdBytes);
            if (ctssChunk is not null)
                newCharIff = newCharIff.WithChunkDataResized(ctssChunk.Type, ctssChunk.Id, ctssBytes);
            newCharIff = strChunk is not null
                ? newCharIff.WithChunkDataResized(strChunk.Type, strChunk.Id, strBytes)
                : newCharIff.WithAddedOrReplacedChunk(ResourceType.Parse("STR#"), 200, strBytes);

            if (registry is not null)
            {
                try
                {
                    var genderCode = isFemale ? "f" : "m";
                    var ageCode = isChild ? "child" : "adult";
                    var catalog = HouseholdAppearance.Catalog(game, registry, genderCode, ageCode, member.Skin);
                    var headChoice = !string.IsNullOrWhiteSpace(member.HeadChoice) ? member.HeadChoice! : catalog.Heads[0].Id;
                    var bodyChoice = !string.IsNullOrWhiteSpace(member.BodyChoice) ? member.BodyChoice! : catalog.Bodies[0].Id;
                    var previewPerson = HouseholdAppearancePreview.CreatePreviewPerson(game, registry, genderCode, ageCode, member.Skin, headChoice, bodyChoice);
                    var headMeshes = AvatarSceneGeometry.For(game, registry).BuildHeadMeshes(previewPerson, 1, 0, (_, _) => 0, new LotCamera(0, 128, 128));
                    newCharIff = SimPortrait.WithPortraits(newCharIff, headMeshes);
                }
                catch (Exception error)
                {
                    Console.Error.WriteLine($"SimsSimulation: portrait for {member.Name} failed: {error.Message}");
                }
            }

            WriteReplace(charPath, newCharIff.Bytes);
            registry?.RegisterFile(newCharIff, charPath);

            var nextSlot = 0;
            while (usedSlots.Contains(nextSlot) || usedNeighborIds.Contains((short)(nextSlot + 1)))
                nextSlot++;
            var nextNeighborId = checked((short)(nextSlot + 1));
            usedSlots.Add(nextSlot);
            usedNeighborIds.Add(nextNeighborId);
            memberNeighborIds.Add(nextNeighborId);
            world?.ClearRemovedNeighbor(nextNeighborId);

            // NBRS record version 0x49 stores 88 16-bit integers of serialized person data.
            var personData = new short[88];
            if (member.Personality.Length >= 5)
            {
                personData[(int)PersonData.NeatQuietPersonality] = member.Personality[0];
                personData[(int)PersonData.OutgoingFriendlyPersonality] = member.Personality[1];
                personData[(int)PersonData.ActivePlayfulPersonality] = member.Personality[2];
                personData[(int)PersonData.PlayfulSmartPersonality] = member.Personality[3];
                personData[(int)PersonData.NiceLoyalPersonality] = member.Personality[4];
            }
            personData[(int)PersonData.PersonAge] = isChild ? (short)9 : (short)27;
            var skinColor = member.Skin.ToLowerInvariant() switch
            {
                "med" => (short)2,
                "drk" => (short)3,
                _ => (short)1,
            };
            personData[59] = skinColor;
            personData[(int)PersonData.SkinColor] = skinColor;
            personData[(int)PersonData.FamilyNumber] = (short)familyChunkId;
            personData[(int)PersonData.Gender] = isFemale ? (short)1 : (short)0;
            personData[(int)PersonData.LingeringHouseNumber] = 0;
            var zodiac = member.Zodiac is >= 1 and <= 12
                ? member.Zodiac.Value
                : (short)(Neighborhoods.ComputeExportZodiac(personData) ?? 1);
            personData[45] = zodiac;
            personData[(int)PersonData.Zodiac] = zodiac;

            var neighbor = new Neighbor(
                Slot: nextSlot,
                RecordVersion: 10,
                Name: member.Name,
                Field0x1C: 0,
                PersonData: personData,
                NeighborId: nextNeighborId,
                Guid: newGuid,
                Relationships: new Dictionary<int, IReadOnlyList<int>>(),
                StoredFormat: 10,
                PersonDataTrailingWord: 0);

            neighborEntries.Add(neighbor);
        }

        if (neighborhood is not null)
        {
            var newFamily = Family.CreateNew(checked((short)familyNumber), targetHouse, memberGuids, familyBudget)
                .WithValue(moveIn ? lotPrice : 0);
            var famiBytes = newFamily.Write((ushort)familyChunkId);
            neighborhood = neighborhood.WithAddedOrReplacedChunk(ResourceType.Parse("FAMI"), (ushort)familyChunkId, famiBytes, 0, familyName);

            var famsBytes = CreateFAMsChunk(familyName);
            neighborhood = neighborhood.WithAddedOrReplacedChunk(ResourceType.Parse("FAMs"), (ushort)familyChunkId, famsBytes, 0, familyName);

            var maxSlot = neighborEntries.Count == 0 ? 0 : neighborEntries.Max(e => e.Slot) + 1;
            var updatedSlotCount = Math.Max(existingNeighbors?.SlotCount ?? 0, maxSlot);
            var nbrsVersion = existingNeighbors?.Version ?? 73;
            var updatedNbrs = new Neighbors(nbrsVersion, updatedSlotCount, neighborEntries);
            var nbrsBytes = updatedNbrs.WriteChunkData(swap: false);
            neighborhood = neighborhood.WithAddedOrReplacedChunk(ResourceType.Parse("NBRS"), 1, nbrsBytes);

            if (neighborhoodPath is not null)
            {
                WriteReplace(neighborhoodPath, neighborhood.Bytes);
            }
        }

        if (moveIn)
        {
            int? centerX = request.TryGetProperty("centerX", out var cxProp) && cxProp.TryGetInt32(out var cxVal)
                ? cxVal : null;
            int? centerY = request.TryGetProperty("centerY", out var cyProp) && cyProp.TryGetInt32(out var cyVal)
                ? cyVal : null;
            string? memberInstantiation;
            if (world is not null && targetHouse == house)
            {
                memberInstantiation = ReloadAfterHouseholdCreation((ushort)familyChunkId, centerX ?? LotWidth / 2, centerY ?? LotHeight / 2);
            }
            else
            {
                OpenLotInternal(targetHouse, moveInFamily: null, activeFamilyOverride: (ushort)familyChunkId,
                    spawnCenter: (centerX, centerY), out memberInstantiation);
            }
            return new { family = familyChunkId, house = targetHouse, budget = familyBudget, members = members.Length, memberInstantiation };
        }

        return new { family = familyChunkId, house = targetHouse, budget = familyBudget, members = members.Length };
    }

    private object MoveInFamily(JsonElement request)
    {
        if (speed != 0 || simulatorBlocked || HasBlockingDialog(world))
            throw new InvalidOperationException("Moving in requires a paused residential lot without a blocking dialog or active trip");
        var requestedFamilyId = checked((ushort)request.GetProperty("family").GetInt32());
        var centerX = request.TryGetProperty("centerX", out var cxProp) && cxProp.TryGetInt32(out var cxVal)
            ? cxVal : LotWidth / 2;
        var centerY = request.TryGetProperty("centerY", out var cyProp) && cyProp.TryGetInt32(out var cyVal)
            ? cyVal : LotHeight / 2;
        var (familyId, targetHouse, budget, memberCount, memberInstantiation) = MoveInFamilyCore(requestedFamilyId, centerX, centerY);
        return new { family = (int)familyId, house = targetHouse, budget, members = memberCount, memberInstantiation };
    }

    private (ushort FamilyId, short House, int Budget, int Members, string MemberInstantiation) MoveInFamilyCore(
        ushort requestedFamilyId, int centerX, int centerY)
    {
        var userDataPath = Neighborhoods.UserData(profile);
        var nghPath = neighborhoodPath ?? Path.Combine(userDataPath, "Neighborhood.iff");
        if (!File.Exists(nghPath)) throw new FileNotFoundException($"Neighborhood.iff not found in {userDataPath}");
        neighborhood ??= IffFile.Open(nghPath);
        neighborhoodPath = nghPath;
        var famiChunk = neighborhood.Find(ResourceType.Parse("FAMI"), requestedFamilyId)
            ?? throw new ArgumentException("The selected family does not exist");
        var family = Family.Read(neighborhood, famiChunk);
        if (family.HouseNumber != 0)
            throw new InvalidOperationException("The selected family already lives on a lot");
        var lotPrice = 0;
        if (world?.SavedSimulationState is { } simi)
        {
            var (furnishingsValue, architectureValue) = CurrentLotValuation(simi);
            lotPrice = Math.Max(0, simi.Field0x9C + furnishingsValue + (int)(architectureValue * (world?.ArchitectureValueMultiplier ?? 0.7f)));
        }
        if (lotPrice > family.Budget)
            throw new InvalidOperationException("The selected family cannot afford this lot");
        var updatedFamily = family.WithHouseNumber(house).WithBudget(family.Budget - lotPrice).WithValue(lotPrice);
        neighborhood = neighborhood.WithAddedOrReplacedChunk(ResourceType.Parse("FAMI"), requestedFamilyId,
            updatedFamily.Write(requestedFamilyId), famiChunk.Flags, famiChunk.Label);
        WriteReplace(nghPath, neighborhood.Bytes);
        var memberInstantiation = ReloadAfterHouseholdCreation(requestedFamilyId, centerX, centerY);
        return (requestedFamilyId, house, updatedFamily.Budget, updatedFamily.Members.Count, memberInstantiation);
    }

    internal static void SetLanguageStringEntry(List<StringEntry> entries, int oneBasedIndex, string value)
    {
        var target = entries.Any(e => e.Language == 1) ? (byte)1 : (byte)0;
        var seen = 0;
        var at = entries.FindIndex(e => (e.Language == target || target == 0) && ++seen == oneBasedIndex);
        if (at >= 0)
        {
            entries[at] = entries[at] with { Value = value };
            return;
        }

        var insertLanguage = target == 0 ? (byte)1 : target;
        while (seen < oneBasedIndex - 1)
        {
            entries.Add(new StringEntry("", "", insertLanguage));
            seen++;
        }
        entries.Add(new StringEntry(value, "", insertLanguage));
    }

    internal static byte[] UpdateCtssStrings(StringTable table, string name, string bio)
    {
        var entries = table.Entries.ToList();
        SetLanguageStringEntry(entries, 1, name);
        SetLanguageStringEntry(entries, 2, bio);

        using var output = new MemoryStream();
        using var writer = new BinaryWriter(output);
        writer.Write((short)-3);
        writer.Write(checked((short)entries.Count));
        foreach (var entry in entries)
        {
            var encoding = ResourceReader.EncodingForLanguage(entry.Language);
            writer.Write(entry.Language);
            writer.Write(encoding.GetBytes(entry.Value));
            writer.Write((byte)0);
            writer.Write(encoding.GetBytes(entry.Comment));
            writer.Write((byte)0);
        }
        writer.Flush();
        return output.ToArray();
    }

    private byte[] UpdateBodystrings(StringTable? table, bool isChild, bool isFemale, string? bodyChoice, string? headChoice, string skin) =>
        HouseholdAppearance.BuildCharacterBodyStrings(table, game, registry, isChild, isFemale, bodyChoice, headChoice, skin);

    private static byte[] CreateFAMsChunk(string familyName)
    {
        var encoding = ResourceReader.EncodingForLanguage(1);
        using var stream = new MemoryStream();
        using var writer = new BinaryWriter(stream);
        writer.Write((short)-3);
        writer.Write((short)1);
        writer.Write((byte)1);
        writer.Write(encoding.GetBytes(familyName));
        writer.Write((byte)0);
        writer.Write((byte)0);
        writer.Flush();
        return stream.ToArray();
    }

    private bool IsAwayLot(string userData, short targetHouse) =>
        suspendedHomeLot is not null && suspendedHomeLot.HomeHouse != targetHouse ||
        targetHouse is (>= 21 and <= 30) or (>= 40 and <= 49) or (>= 81 and <= 89) or (>= 93 and <= 99) ||
        (!string.IsNullOrEmpty(userData) && Neighborhoods.IsCommunityLot(userData, targetHouse));

    private short EffectiveHomeHouse =>
        suspendedHomeLot?.HomeHouse ??
        (world is not null && house > 0 && world[SimulationGlobal.SimlessBuildMode] == 0 && !IsVisitingAwayLot ? house : (short)0);

    private bool IsVisitingAwayLot =>
        world is not null &&
        house != 0 &&
        ((suspendedHomeLot is not null && suspendedHomeLot.HomeHouse != house) ||
         (world[SimulationGlobal.SimlessBuildMode] == 0 &&
          IsAwayLot(Path.GetDirectoryName(neighborhoodPath) ?? Neighborhoods.UserData(profile), house)));

    private bool IsEmergencyBuyBuildLocked =>
        world is { WorldLotListEntries.Count: > 0 } active &&
        active.WorldLotListEntries.Any(item => ReferenceEquals(active.ObjectById(item.Id), item));

    private void EnsureLotEditingAllowed()
    {
        if (IsVisitingAwayLot)
            throw new InvalidOperationException("Buy and Build modes are disabled while visiting an away lot.");
        if (IsEmergencyBuyBuildLocked)
            throw new InvalidOperationException("Buy and Build modes are disabled during an active emergency.");
    }

    private void ClampAwayLotEditingState(bool forceAway = false)
    {
        if (!forceAway && !IsVisitingAwayLot) return;
        editingView = false;
        doorWindowBuildToolActive = false;
        wallpaperBuildToolActive = false;
        if (viewerMode is 1 or 2)
            viewerMode = 0;
        if (world is not null)
            world[SimulationGlobal.Mode] = viewerMode;
    }

    private static SaveRuntimeMetadata CaptureRuntimeMetadata(SimulationWorld currentWorld, ReadOnlySpan<byte> lotBytes, int saveSpeed,
        SavedSuspendedHomeLot? suspendedHome = null)
    {
        var animations = currentWorld.Objects.Values.OfType<XPerson>().OrderBy(person => person.Id).Select(person =>
        {
            var stack = currentWorld.SavedExecutionStacks.GetValueOrDefault(person.Id);
            return new PersonAnimationRuntimeSnapshot(person.Id, person.AnimationPlayback?.SaveState(),
                person.BackgroundAnimationPlayback?.SaveState(), person.CarryAnimationPlayback?.SaveState(),
                person.InteractionAttachments.Order(StringComparer.Ordinal).ToArray(),
                RoutePersistence.Capture(person, stack), person.BackgroundPracticePersonState,
                person.AnimatorWalkingScale, person.PendingAnimationEvents.ToArray(), person.AnimatorControlState,
                person.AnimatorRootX, person.AnimatorRootY, person.AnimatorPoolTransitionState,
                person.AnimatorGaitEntryState, person.AnimatorMilliseconds, person.AnimatorPoolTile,
                person.AnimatorRootDirection, person.AnimatorDisplacementX, person.AnimatorDisplacementY,
                person.AnimatorDisplacementDirection, person.AnimatorRouteTransitionState,
                person.AnimatorStateTailField198, person.AnimatorCurrentSkill,
                person.AnimatorPracticeScaleEnabled);
        }).ToArray();
        var savedDialogs = currentWorld.DialogRecords.Select(record => new SavedDialogSnapshot(
            record.Token, record.Owner.Id, record.Icon?.Id, record.Kind, record.Title, record.Message,
            record.Yes, record.No, record.Cancel, record.Blocking, record.AwaitsResponse, record.State,
            record.Visible, record.ImageBitmapId, record.BookMode)).ToArray();
        var restrictedKeys = (currentWorld.FamilyBudget as FamilyBudget)?.RestrictedActivePersonKeys?.ToArray();
        return new SaveRuntimeMetadata(14, saveSpeed, animations,
            Convert.ToHexString(SHA256.HashData(lotBytes)), savedDialogs,
            currentWorld.FamilyBudget?.ReadFamilyBudget(), restrictedKeys, suspendedHome,
            currentWorld.Clock.Ticks, currentWorld.Clock.Day);
    }

    private static int TravelFilterSlotForMode(int mode) => mode switch
    {
        2 => 1,
        3 => 2,
        4 => 3,
        5 => 4,
        7 => 5,
        _ => TravelFilter.Unleashed,
    };

    private static void SetInMemoryFamilyVacationField(SimulationWorld targetWorld, ushort familyChunkId, int vacationHouse)
    {
        if (targetWorld.FamilyBudget is FamilyBudget fb &&
            fb.FamilyChunkId == familyChunkId &&
            fb.ActiveFamily is { } fam &&
            fam.Field0x13C != vacationHouse)
        {
            fb.ActiveFamily = fam.WithFields(field0x13C: vacationHouse);
        }
    }

    private void ReconcileCommittedVacationFieldOnDisk()
    {
        if (committedVacationState is not { } committed ||
            neighborhoodPath is null ||
            !File.Exists(neighborhoodPath))
        {
            return;
        }
        try
        {
            var currentNgh = neighborhood ?? IffFile.Open(neighborhoodPath);
            var famiType = ResourceType.Parse("FAMI");
            if (currentNgh.Find(famiType, committed.FamilyChunkId) is not { } chunk) return;
            var currentFam = Family.Read(currentNgh, chunk);
            if (currentFam.Field0x13C == committed.VacationHouse) return;
            var updated = currentNgh.WithAddedOrReplacedChunk(famiType, committed.FamilyChunkId,
                currentFam.WithFields(field0x13C: committed.VacationHouse).Write(committed.FamilyChunkId));
            WriteReplace(neighborhoodPath, updated.Bytes);
            neighborhood = updated;
        }
        catch
        {
        }
    }

    private void RestoreTravelRuntimeState(SimulationWorld targetWorld, string userData, short loadedHouse,
        ushort? loadedFamilyChunkId, Family? loadedFamily, SaveRuntimeMetadata runtime, SaveEnvelope? envelope = null)
    {
        var savedHome = envelope?.SuspendedHome ?? runtime.SuspendedHome;
        if (savedHome is not null)
        {
            suspendedHomeLot = new SuspendedHomeLot(savedHome.HomeHouse, savedHome.HomeFamilyChunkId,
                Convert.FromBase64String(savedHome.LotState), savedHome.Runtime, savedHome.Speed);
        }
        else if (loadedFamily is { HouseNumber: > 0 } fam &&
                 loadedHouse != fam.HouseNumber &&
                 IsAwayLot(userData, loadedHouse))
        {
            var homePath = Path.Combine(userData, "Houses", $"House{(short)fam.HouseNumber:D2}.iff");
            if (File.Exists(homePath))
            {
                var homeBytes = File.ReadAllBytes(homePath);
                var homeRuntime = ReadSavedRuntimeMetadata(CanonicalRuntimePath(homePath), homeBytes);
                suspendedHomeLot = new SuspendedHomeLot((short)fam.HouseNumber, loadedFamilyChunkId,
                    homeBytes, homeRuntime, homeRuntime.Speed);
            }
            else
            {
                suspendedHomeLot = null;
            }
        }
        else
        {
            suspendedHomeLot = null;
        }

        if (targetWorld.FamilyBudget is FamilyBudget budget)
        {
            var restrictedKeys = envelope?.RestrictedActivePersonKeys ?? runtime.RestrictedActivePersonKeys;
            if (restrictedKeys is { Count: > 0 })
            {
                budget.RestrictActivePersonKeys(restrictedKeys);
                targetWorld.StoredSlotPersonId = null;
            }
            else if (runtime.Version < 14 &&
                     suspendedHomeLot is not null &&
                     loadedHouse is not (>= 40 and <= 49) &&
                     budget.ActiveFamily is { Members.Count: > 1 } legacyFamily)
            {
                var presentKeys = legacyFamily.Members
                    .Select(static m => unchecked((int)m))
                    .Where(k => targetWorld.WalkOrder.OfType<XPerson>().Any(p => p.TypeRecord?.Key == k))
                    .ToArray();
                if (presentKeys.Length > 0 && presentKeys.Length < legacyFamily.Members.Count)
                {
                    budget.RestrictActivePersonKeys(presentKeys);
                    targetWorld.StoredSlotPersonId = null;
                }
            }
        }

        var diskField0x13C = loadedFamily?.Field0x13C ?? 0;
        var diskNghPath = neighborhoodPath ?? Path.Combine(userData, "Neighborhood.iff");
        if (loadedFamilyChunkId is { } checkChunkId && File.Exists(diskNghPath))
        {
            try
            {
                var diskNgh = IffFile.Open(diskNghPath);
                if (diskNgh.Find(ResourceType.Parse("FAMI"), checkChunkId) is { } diskChunk)
                    diskField0x13C = Family.Read(diskNgh, diskChunk).Field0x13C;
            }
            catch
            {
            }
        }
        committedVacationState = loadedFamilyChunkId is { } committedChunkId ? (committedChunkId, diskField0x13C) : null;

        if (loadedHouse is >= 40 and <= 49 &&
            suspendedHomeLot is not null &&
            loadedFamilyChunkId is { } vacFamId &&
            loadedFamily is { Field0x13C: 0 })
        {
            SetInMemoryFamilyVacationField(targetWorld, vacFamId, loadedHouse);
        }
    }

    private bool RefreshPendingPersonPortraits()
    {
        if (registry is null || string.IsNullOrEmpty(game)) return false;
        HashSet<uint>? candidates = null;
        var drained = WardrobeSuitService.DrainPendingPortraitGuids(registry);
        if (drained.Length > 0)
            candidates = [.. drained];

        if (registry.DirtyPeopleGuids.Count > 0)
        {
            foreach (var dirtyGuid in registry.DirtyPeopleGuids)
            {
                if (registry.Find(dirtyGuid) is { Scan: ObjectScan.People } dirtyEntry &&
                    (!refreshedPersonFiles.TryGetValue(dirtyGuid, out var lastRefreshed) || !ReferenceEquals(lastRefreshed, dirtyEntry.File)))
                {
                    candidates ??= [];
                    candidates.Add(dirtyGuid);
                }
            }
        }
        if (candidates is null || candidates.Count == 0) return false;

        var refreshedAny = false;
        var geometry = AvatarSceneGeometry.For(game, registry);
        foreach (var guid in candidates)
        {
            if (registry.Find(guid) is not { Scan: ObjectScan.People } entry) continue;
            var livePerson = world?.WalkOrder.OfType<XPerson>().FirstOrDefault(p => unchecked((uint)(p.TypeRecord?.Key ?? 0)) == guid);
            var targetPerson = livePerson is { SavedCharacter: not null } ? livePerson : CreatePortraitPersonFromEntry(entry, language);
            if (targetPerson is null) continue;

            var savedPresentation = targetPerson.PresentationCharacter;
            var savedOutfit = targetPerson[PersonData.CurrentOutfit];
            try
            {
                targetPerson.PresentationCharacter = null;
                targetPerson[PersonData.CurrentOutfit] = 0;
                var headMeshes = geometry.BuildHeadMeshes(targetPerson, 1, 0, static (_, _) => 0, new LotCamera(0, 128, 128));
                if (headMeshes.Count == 0) continue;
                var updatedIff = SimPortrait.WithPortraits(entry.File, headMeshes);
                registry.ReplaceEntryFile(guid, updatedIff, markDirty: true);
                images?.SetRegistry(registry);
                refreshedPersonFiles[guid] = updatedIff;
                if (livePerson is not null && pieHead?.Sim == livePerson.Id)
                    pieHead = null;
                refreshedAny = true;
            }
            catch
            {
            }
            finally
            {
                targetPerson.PresentationCharacter = savedPresentation;
                targetPerson[PersonData.CurrentOutfit] = savedOutfit;
            }
        }
        return refreshedAny;
    }

    private static XPerson? CreatePortraitPersonFromEntry(ObjectEntry entry, byte language)
    {
        var stringsId = entry.Definition[ObjdField.BodyStringsId];
        var strChunk = stringsId == 0 ? null : entry.File.Find(ResourceType.Str, stringsId);
        if (strChunk is null) return null;
        var values = StringTable.Read(entry.File, strChunk).ForLanguage(language);
        static string StrAt(IReadOnlyList<string> list, int oneBased) =>
            oneBased >= 1 && oneBased <= list.Count ? list[oneBased - 1].Trim() : string.Empty;
        static (string, string) Pair(string spec)
        {
            var semicolon = spec.IndexOf(';');
            if (semicolon >= 0) spec = spec[..semicolon];
            spec = spec.Trim();
            if (string.IsNullOrWhiteSpace(spec) || spec.Equals("NONE", StringComparison.OrdinalIgnoreCase))
                return (string.Empty, string.Empty);
            var comma = spec.IndexOf(',');
            var mesh = (comma >= 0 ? spec[..comma] : spec).Trim();
            var tex = comma >= 0 ? spec[(comma + 1)..].Trim() : string.Empty;
            if (mesh.EndsWith(".apr", StringComparison.OrdinalIgnoreCase))
                mesh = mesh[..^4];
            return (mesh, tex);
        }

        var bodySpec = StrAt(values, 0x02);
        if (bodySpec.Length == 0) return null;
        var headSpec = StrAt(values, 0x03);
        var leftHandSpec = StrAt(values, 0x12);
        var rightHandSpec = StrAt(values, 0x13);
        var genderRaw = StrAt(values, 0x0d).ToLowerInvariant();
        var genderMode = genderRaw switch
        {
            "male" => 0,
            "female" => 1,
            "dogmale" or "dog_male" => 2,
            "dogfemale" or "dog_female" => 3,
            "catmale" or "cat_male" => 4,
            "catfemale" or "cat_female" => 5,
            _ => 0,
        };
        var isChild = StrAt(values, 0x01).Equals("child", StringComparison.OrdinalIgnoreCase);
        var parts = Enumerable.Repeat((string.Empty, string.Empty), 5).ToArray();
        parts[0] = Pair(bodySpec);
        if (genderMode is < 2 or > 5)
        {
            parts[2] = Pair(leftHandSpec);
            parts[3] = Pair(rightHandSpec);
            parts[4] = Pair(headSpec);
        }
        var character = new PersonCharacter(0, 0, parts, [], [string.Empty, string.Empty, string.Empty], 3, new float[9]);
        var person = new XPerson(1, new short[XObject.DefinitionCount])
        {
            TypeRecord = new TypeRecord(unchecked((int)entry.Guid)),
            SavedCharacter = character,
            Position = new ObjectPosition(64 * 16, 64 * 16, 1),
            AnimatorBodyStringMode = (short)genderMode,
        };
        person[PersonData.PersonAge] = (short)(isChild ? 9 : 27);
        person[ObjectData.Direction] = 3;
        return person;
    }

    private (ushort? ChunkId, Family? Family) ResolveTravellingFamily(SimulationWorld sourceWorld,
        SimulationWorld.LotSwitchRequest request)
    {
        if (activeFamilyChunkId is { } activeChunkId)
        {
            var liveFamily = (sourceWorld.FamilyBudget as FamilyBudget)?.ActiveFamily;
            if (liveFamily is not null) return (activeChunkId, liveFamily);
            if (neighborhood?.Find(ResourceType.Parse("FAMI"), activeChunkId) is { } activeChunk)
                return (activeChunkId, Family.Read(neighborhood, activeChunk));
        }

        if (neighborhood is not null)
        {
            foreach (var chunk in neighborhood.OfType(ResourceType.Parse("FAMI")))
            {
                var candidate = Family.Read(neighborhood, chunk);
                if (request.PersonGuid != 0 && candidate.Members.Contains(unchecked((uint)request.PersonGuid)))
                    return (chunk.Id, candidate);
                if (request.FamilyNumber != 0 && (candidate.FamilyNumber == request.FamilyNumber || chunk.Id == request.FamilyNumber))
                    return (chunk.Id, candidate);
            }
        }
        return (activeFamilyChunkId, null);
    }

    private void UpdateFamilyVacationField(ushort familyChunkId, int vacationHouse)
    {
        if (neighborhood is null || neighborhoodPath is null) return;
        var famiType = ResourceType.Parse("FAMI");
        if (neighborhood.Find(famiType, familyChunkId) is not { } chunk) return;
        var current = Family.Read(neighborhood, chunk);
        if (current.Field0x13C == vacationHouse) return;
        var updatedFamily = current.WithFields(field0x13C: vacationHouse);
        var updated = neighborhood.WithAddedOrReplacedChunk(famiType, familyChunkId, updatedFamily.Write(familyChunkId));
        WriteReplace(neighborhoodPath, updated.Bytes);
        neighborhood = updated;
    }

    private static (int? Hour, int? Minute) ConsumeArrivalClock(
        Dictionary<short, InteractionScopeTable> clonedScopes, short targetHouse)
    {
        int? hour = null;
        int? minute = null;
        foreach (var scope in clonedScopes.Values)
        {
            short hourCursor = -1;
            if (scope.TryFindNext(2, ref hourCursor, 7, out var hourWord))
            {
                hour ??= hourWord;
                scope.TryAdvance(hourCursor, -1);
            }

            short minuteCursor = -1;
            if (scope.TryFindNext(2, ref minuteCursor, 8, out var minuteWord))
            {
                minute ??= minuteWord;
                scope.TryAdvance(minuteCursor, -1);
            }
        }
        if (targetHouse == 99 && hour is null && minute is null)
            return (12, 0);
        if (hour is null && minute is not null) hour = 0;
        if (minute is null && hour is not null) minute = 0;
        return (hour, minute);
    }

    private static List<int> CollectTravelScopeKeys(
        Dictionary<int, short> sourceSlots, Dictionary<short, InteractionScopeTable> clonedScopes)
    {
        var keys = new List<int>();
        foreach (var (key, sourceSlot) in sourceSlots)
        {
            if (key == 0 || !clonedScopes.TryGetValue(sourceSlot, out var scope)) continue;
            short cursor = -1;
            while (scope.TryFindNext(2, ref cursor, 0, out _) && scope.TryGet(cursor, out var entry))
            {
                if (entry.Mode is (>= 0 and <= 6) or (>= 9 and <= 12))
                {
                    keys.Add(key);
                    break;
                }
            }
        }
        return keys;
    }

    private static void SyncPersonFromNeighborRecord(SimulationWorld targetWorld, XPerson person)
    {
        if (person.TypeRecord?.Key is not { } typeKey) return;
        var neighbor = targetWorld.Neighbors.Values.FirstOrDefault(n => n.TypeRecordKey == typeKey);
        if (neighbor is null) return;

        targetWorld.BindPersonToNeighborRecord(person);
        if (!string.IsNullOrWhiteSpace(neighbor.Name) &&
            !IsInternalUserLabel(neighbor.Name) &&
            !string.Equals(person.Name, neighbor.Name, StringComparison.Ordinal))
        {
            person.Name = neighbor.Name;
        }

        var neighborRelationships = neighbor.Relationships.Snapshot();
        foreach (var existingTarget in person.Relationships.Snapshot().Keys.ToArray())
        {
            if (!neighborRelationships.ContainsKey(existingTarget))
                person.Relationships.RemoveTarget(checked((short)existingTarget));
        }
        foreach (var (otherId, values) in neighborRelationships)
        {
            var targetId = checked((short)otherId);
            person.Relationships.Resize(targetId, values.Count);
            for (var index = 0; index < values.Count; index++)
                person.Relationships.Set(targetId, index, values[index]);
        }
    }

    private static bool ApplyTransferredScopeState(SimulationWorld targetWorld, XPerson person)
    {
        var scope = targetWorld.InteractionExecutorScope(person);
        var remaining = scope.CountValue(2);
        if (remaining <= 0) return false;

        var applied = false;
        short cursor = -1;
        while (remaining-- > 0 && scope.TryFindNext(2, ref cursor, 0, out _) && scope.TryGet(cursor, out var fetched))
        {
            var payload = unchecked((short)fetched.Result);
            var kind = fetched.Mode;
            var removeEntry = true;
            if ((uint)kind <= 6)
            {
                var selector = kind switch
                {
                    0 => 9,
                    1 => 6,
                    2 => 5,
                    3 => 15,
                    4 => 7,
                    5 => 8,
                    _ => 14,
                };
                person.SetInteractionExecutorFloat(selector, payload);
                if ((uint)selector < person.Motives.Length)
                    person.Motives[selector] = payload;
                applied = true;
            }
            else if (kind is >= 9 and <= 12)
            {
                var offset = kind switch
                {
                    9 => 0x59c,
                    10 => 0x62c,
                    11 => 0x630,
                    _ => 0x62e,
                };
                person.SetInteractionExecutorWord(offset, payload);
                applied = true;
            }
            else
            {
                removeEntry = false;
            }

            if (removeEntry)
            {
                var before = scope.CountValue(2);
                scope.TryAdvance(cursor, -1);
                if (scope.CountValue(2) < before) cursor--;
            }
        }
        return applied;
    }

    private void InstantiateMissingFamilyMembersOnReturnHome(SimulationWorld targetWorld, Family? activeFamily)
    {
        if (activeFamily is not { Members.Count: > 0 }) return;
        var addedAny = false;
        foreach (var guid in activeFamily.Members)
        {
            if (guid == 0) continue;
            var key = unchecked((int)guid);
            if (targetWorld.WalkOrder.OfType<XPerson>().Any(p => p.TypeRecord?.Key == key))
                continue;

            targetWorld.ScopedNeighborPersonRecordId(key);
            var created = targetWorld.WalkOrder.OfType<XPerson>().FirstOrDefault(p => p.TypeRecord?.Key == key);
            if (created is null && targetWorld.ObjectFactory?.Invoke(key) is XPerson fallbackPerson)
            {
                targetWorld.Add(fallbackPerson);
                targetWorld.InitializeCreatedPerson(fallbackPerson);
                targetWorld.InitializeCreatedObject(fallbackPerson);
                targetWorld.InitializeCreatedPerson(fallbackPerson);
                created = fallbackPerson;
            }

            if (created is not null)
            {
                addedAny = true;
                if (created.Position.X < 0 && created.Position.Y < 0 &&
                    targetWorld.FindGoodLocation(created, LotWidth / 2, LotHeight / 2, out var pos))
                {
                    targetWorld.PlaceCreatedObject(created, pos);
                }
            }
        }
        if (addedAny) targetWorld.RefreshNeighborInteractionManager();
    }

    private static void TransferScopes(SimulationWorld destWorld,
        Dictionary<int, short> sourceSlots, Dictionary<short, InteractionScopeTable> clonedScopes)
    {
        foreach (var (key, sourceSlot) in sourceSlots)
        {
            if (!clonedScopes.TryGetValue(sourceSlot, out var sourceScope)) continue;
            short targetSlot;
            if (destWorld.PersonTypeRecordSlots.TryGetValue(key, out var existingSlot))
            {
                targetSlot = existingSlot;
            }
            else if (!destWorld.PersonTypeRecordSlots.ContainsValue(sourceSlot) &&
                     !destWorld.InteractionScopes.ContainsKey(sourceSlot))
            {
                targetSlot = sourceSlot;
                destWorld.PersonTypeRecordSlots[key] = targetSlot;
            }
            else
            {
                short candidate = 1;
                while (destWorld.PersonTypeRecordSlots.ContainsValue(candidate) ||
                       destWorld.InteractionScopes.ContainsKey(candidate))
                    candidate++;
                targetSlot = candidate;
                destWorld.PersonTypeRecordSlots[key] = targetSlot;
            }

            XPerson? destBackedPerson = null;
            foreach (var obj in destWorld.WalkOrder)
            {
                if (obj.TypeRecord?.Key != key) continue;
                obj.InteractionScopeKey5CA = targetSlot;
                if (destBackedPerson is null && obj is XPerson p && p[PersonData.NeighborId] > 0)
                    destBackedPerson = p;
            }

            if (destBackedPerson is not null)
            {
                var destNeighborId = destBackedPerson[PersonData.NeighborId];
                var inventory = destWorld.NeighborInventory(destNeighborId);
                inventory.FilterOut(2);
                for (short i = 0; i < sourceScope.Count; i++)
                {
                    if (sourceScope.TryGet(i, out var entry) && entry.Value == 2)
                        inventory.Add(entry.Value, entry.Mode, unchecked((short)entry.Result));
                }
                var backed = new InteractionScopeTable(() => destWorld.NeighborInventory(destNeighborId));
                backed.AvatarObjects.AddRange(sourceScope.AvatarObjects);
                destWorld.InteractionScopes[targetSlot] = backed;
            }
            else
            {
                destWorld.InteractionScopes[targetSlot] = sourceScope;
            }
        }

        foreach (var (slot, scope) in clonedScopes)
        {
            if (!sourceSlots.ContainsValue(slot) && !destWorld.InteractionScopes.ContainsKey(slot))
                destWorld.InteractionScopes[slot] = scope;
        }
    }

    internal bool TryApplyPendingLotSwitch(SimulationWorld sourceWorld, SimulationWorld.LotSwitchRequest request)
    {
        var userData = Neighborhoods.UserData(profile);
        var (travellingFamilyChunkId, travellingFamily) = ResolveTravellingFamily(sourceWorld, request);
        var isReturnHome = request.RawTargetHouse == -1;
        var targetHouse = isReturnHome
            ? (suspendedHomeLot?.HomeHouse ?? checked((short)(travellingFamily?.HouseNumber ?? 0)))
            : request.RawTargetHouse;
        if (targetHouse <= 0) return false;

        var destPath = Path.Combine(userData, "Houses", $"House{targetHouse:D2}.iff");
        var returningHome = isReturnHome && suspendedHomeLot is { } suspended && suspended.HomeHouse == targetHouse
            ? suspended
            : null;
        if (returningHome is null && !File.Exists(destPath)) return false;

        var traveller = request.PersonGuid != 0
            ? sourceWorld.WalkOrder.OfType<XPerson>().FirstOrDefault(p => p.TypeRecord?.Key == request.PersonGuid)
            : selectedSim != 0 ? sourceWorld.WalkOrder.OfType<XPerson>().FirstOrDefault(p => p.Id == selectedSim) : null;
        var sourceStateClass = sourceWorld.StateClass(house);
        var destinationStateClass = sourceWorld.StateClass(targetHouse);
        var lotTransitInfo = sourceWorld[SimulationGlobal.LotTransitInfo];
        var fameScore = traveller is not null ? (int)traveller[PersonData.FameScore] : 0;
        var jobType = traveller is not null ? (int)traveller[PersonData.JobType] : 0;
        var willSuspendHome = !isReturnHome && suspendedHomeLot is null && lot is not null;
        var away = !isReturnHome && (willSuspendHome ||
                                     (suspendedHomeLot is not null && suspendedHomeLot.HomeHouse != targetHouse) ||
                                     targetHouse is (>= 21 and <= 30) or (>= 40 and <= 49) or (>= 50 and <= 89) or (>= 93 and <= 99) ||
                                     Neighborhoods.IsCommunityLot(userData, targetHouse));
        Write(new
        {
            type = "lotSwitching",
            fromHouse = house,
            house = targetHouse,
            away,
            returnHome = isReturnHome,
            sourceStateClass,
            destinationStateClass,
            lotTransitInfo,
            fameScore,
            jobType
        });

        foreach (var person in sourceWorld.WalkOrder.OfType<XPerson>())
        {
            if (person[PersonData.NeighborId] > 0) sourceWorld.SavePersonRecord(person);
        }
        PersistNeighborhoodStateImmediately();

        int? pendingVacationField = null;
        if (travellingFamilyChunkId is not null)
        {
            if (!isReturnHome && targetHouse is >= 40 and <= 49)
                pendingVacationField = targetHouse;
            else if (isReturnHome)
                pendingVacationField = 0;
        }

        var sourceSpeed = speed > 0 ? speed : lastRunningSpeed;
        if (!isReturnHome && suspendedHomeLot is null && lot is not null)
        {
            UpdatePreSaveState(sourceWorld, lot);
            var (withObjects, _) = sourceWorld.WriteSavedLotObjectsTo(lot);
            var savedHomeLot = sourceWorld.WriteSavedSimulationStateTo(withObjects);
            var homeRuntime = CaptureRuntimeMetadata(sourceWorld, savedHomeLot.Bytes.Span, sourceSpeed);
            suspendedHomeLot = new SuspendedHomeLot(house, activeFamilyChunkId, savedHomeLot.Bytes.ToArray(),
                homeRuntime, sourceSpeed);
            if (house is (> 0 and < 20) or (>= 90 and <= 92) && !Neighborhoods.IsCommunityLot(userData, house))
            {
                var homeHousePath = Path.Combine(userData, "Houses", $"House{house:D2}.iff");
                Directory.CreateDirectory(Path.GetDirectoryName(homeHousePath)!);
                WriteReplace(homeHousePath, savedHomeLot.Bytes);
                WriteReplace(CanonicalRuntimePath(homeHousePath), JsonSerializer.SerializeToUtf8Bytes(homeRuntime, Json));
            }
        }

        var sourceSlots = new Dictionary<int, short>(sourceWorld.PersonTypeRecordSlots);
        var clonedScopes = sourceWorld.InteractionScopes.ToDictionary(pair => pair.Key, pair => pair.Value.Clone());
        var (arrivalHour, arrivalMinute) = ConsumeArrivalClock(clonedScopes, targetHouse);
        var travelScopeKeys = CollectTravelScopeKeys(sourceSlots, clonedScopes);

        RemoveTileCursor();
        ResetAppearanceTransitions();
        audio?.Reset();
        refreshedPersonFiles.Clear();

        registry = registry?.WithRefreshedPeople(Path.Combine(userData, "Characters")) ?? registry;
        var preloadedLot = returningHome is null ? null : new IffFile(returningHome.LotBytes, destPath);
        var setup = WorldBootstrap.Load(game, destPath, language, () => speed == 0, targetHouse,
            autonomyForced: sourceWorld.AutonomyForced ?? false,
            activeFamilyChunkId: travellingFamilyChunkId,
            userDataPath: userData,
            preloadedLot: preloadedLot,
            scoreAutonomy: ScoreAutonomyChoice,
            existingRegistry: registry,
            directsAutonomy: DirectsAutonomyForPerson,
            selectAutonomy: SelectAutonomyChoice);

        house = targetHouse;
        lot = setup.Lot;
        world = setup.World;
        world[SimulationGlobal.SimlessBuildMode] = 0;
        world.AutonomyForced = sourceWorld.AutonomyForced;
        registry = setup.Registry ?? registry;
        neighborhoodPath = setup.NeighborhoodPath;
        neighborhood = setup.Neighborhood;
        activeFamilyChunkId = setup.ActiveFamilyChunkId;
        HydrateTypeAttributesFromNeighborhood(world, lot, neighborhood, overwriteExisting: returningHome is not null);
        if (travellingFamilyChunkId is { } resolvedFamilyChunkId && pendingVacationField is { } nextVacField)
        {
            SetInMemoryFamilyVacationField(world, resolvedFamilyChunkId, nextVacField);
        }
        if (!isReturnHome && targetHouse is >= 40 and <= 49)
        {
            var expectedFamilyNumber = (setup.ActiveFamily?.FamilyNumber is > 0 ? setup.ActiveFamily.FamilyNumber : 0);
            if (expectedFamilyNumber == 0 && travellingFamilyChunkId is { } chunkIdNum)
                expectedFamilyNumber = unchecked((short)chunkIdNum);
            var allowedKeys = new HashSet<int>(travelScopeKeys);
            if (setup.ActiveFamily is { Members.Count: > 0 } famMembers)
                foreach (var memberGuid in famMembers.Members) allowedKeys.Add(unchecked((int)memberGuid));
            if (request.PersonGuid != 0) allowedKeys.Add(request.PersonGuid);
            var removedStale = false;
            foreach (var loadedPerson in world.WalkOrder.OfType<XPerson>().ToArray())
            {
                var pFamily = loadedPerson[PersonData.FamilyNumber];
                var pGuid = loadedPerson.TypeRecord?.Key ?? 0;
                if (pFamily > 0 &&
                    expectedFamilyNumber > 0 &&
                    pFamily != expectedFamilyNumber &&
                    !allowedKeys.Contains(pGuid))
                {
                    world.Remove(loadedPerson.Id);
                    removedStale = true;
                }
            }
            if (removedStale) world.RefreshNeighborInteractionManager();
        }
        if (registry is not null)
            world.UiTextFile ??= registry.UiText;
        AttachTutorialFlash(world);
        ClampAwayLotEditingState(away);

        if (!isReturnHome && request.PersonGuid != 0)
        {
            if (world.FamilyBudget is FamilyBudget awayBudget)
            {
                var restrictedKeys = new List<int> { request.PersonGuid };
                var familyMembers = awayBudget.ActiveFamily?.Members;
                if (familyMembers is not null)
                {
                    foreach (var key in travelScopeKeys)
                    {
                        if (key != request.PersonGuid &&
                            familyMembers.Contains(unchecked((uint)key)) &&
                            !restrictedKeys.Contains(key))
                        {
                            restrictedKeys.Add(key);
                        }
                    }
                }
                awayBudget.RestrictActivePersonKeys(restrictedKeys);
            }
            world.StoredSlotPersonId = null;
        }

        if (!isReturnHome)
        {
            if (world.ActivePersonManagerPresent)
            {
                foreach (var key in world.ActivePersonRecordKeys)
                {
                    if (key != 0) world.ScopedNeighborPersonRecordId(key);
                }
            }
            foreach (var key in travelScopeKeys)
            {
                if (key != 0 && key != request.PersonGuid)
                    world.ScopedNeighborPersonRecordId(key);
            }
        }
        else if (returningHome is not null)
        {
            foreach (var person in world.WalkOrder.OfType<XPerson>())
                SyncPersonFromNeighborRecord(world, person);
            InstantiateMissingFamilyMembersOnReturnHome(world, setup.ActiveFamily);
        }

        TransferScopes(world, sourceSlots, clonedScopes);

        var updatedTravelerIds = new HashSet<short>();
        foreach (var person in world.WalkOrder.OfType<XPerson>())
        {
            if (ApplyTransferredScopeState(world, person))
                updatedTravelerIds.Add(person.Id);
        }

        if (returningHome is not null)
        {
            var travelerKeySet = new HashSet<int>(travelScopeKeys);
            if (request.PersonGuid != 0) travelerKeySet.Add(request.PersonGuid);
            var animationsToRestore = returningHome.Runtime.PersonAnimations?
                .Where(state => world.ObjectById(state.PersonId) is XPerson person &&
                                !updatedTravelerIds.Contains(person.Id) &&
                                !(person.TypeRecord?.Key is { } key && travelerKeySet.Contains(key)))
                .ToArray();
            RestorePersonAnimationRuntime(world, animationsToRestore);
            RestoreDialogRecords(world, returningHome.Runtime.Dialogs);
            suspendedHomeLot = null;
        }

        if (arrivalHour is { } h && arrivalMinute is { } m)
        {
            world.Clock.Restore(h, m, 0);
            world[SimulationGlobal.Hour] = checked((short)world.Clock.Hour);
            world[SimulationGlobal.Minute] = checked((short)world.Clock.Minute);
            world[SimulationGlobal.Second] = checked((short)world.Clock.Second);
        }

        ClearBuildHistory();
        ResetLotValuationBaseline();
        ClearCutaway();
        viewerMode = 0;
        viewLevel = 1;
        tileCursor = null;
        saveDirty = returningHome is not null && saveDirty;
        simulationError = null;
        if (viewerScale != 0) world[SimulationGlobal.ZoomLevelSML] = viewerScale;
        world[SimulationGlobal.Mode] = viewerMode;
        ClampAwayLotEditingState(away);
        InitializeFameCallbackTarget(world);
        AttachNoticeListener(world);
        world.AutonomyHost = BuildAutonomyHost(world, setup.Global ?? global!, house);
        selectedSim = request.PersonGuid != 0
            ? (PanelPeople().FirstOrDefault(p => p.TypeRecord?.Key == request.PersonGuid)?.Id ?? DefaultSelectedSimId())
            : DefaultSelectedSimId();
        SyncSelectedSimFlags(world, selectedSim);
        autoSpeedSaved = -1;

        var resumeSpeed = returningHome is { Speed: > 0 } ? returningHome.Speed : (sourceSpeed > 0 ? sourceSpeed : 1);
        lastRunningSpeed = resumeSpeed;
        SetSimulationSpeed(resumeSpeed);
        audio?.PlayLotAmbience(house);

        Write(new { type = "lotChanged", house, away, simless = world is not null && world[SimulationGlobal.SimlessBuildMode] != 0 });
        Write(new { type = "environment", environment = plugins?.Environment(house) });
        Export();
        Write(new { type = "state", state = State() });
        return true;
    }

    private static SaveRuntimeMetadata ReadSavedRuntimeMetadata(string path, ReadOnlyMemory<byte> lotBytes)
    {
        if (!File.Exists(path)) return new SaveRuntimeMetadata(1, 1);
        var metadata = JsonSerializer.Deserialize<SaveRuntimeMetadata>(File.ReadAllBytes(path), Json)
            ?? throw new InvalidDataException("Invalid native save runtime metadata.");
        if (metadata.Version is < 1 or > 14 || metadata.Speed is not (1 or 3 or 10) ||
            (metadata.Version == 1 && metadata.PersonAnimations is { Length: > 0 }))
            throw new InvalidDataException("Unsupported native save runtime metadata.");
        if (metadata.LotSha256 is { } expectedHash &&
            !string.Equals(expectedHash, Convert.ToHexString(SHA256.HashData(lotBytes.Span)), StringComparison.Ordinal))
            return new SaveRuntimeMetadata(1, 1);
        return metadata;
    }

    private static void RestorePersonAnimationRuntime(SimulationWorld world, PersonAnimationRuntimeSnapshot[]? states)
    {
        if (states is null) return;
        if (states.Select(state => state.PersonId).Distinct().Count() != states.Length)
            throw new InvalidDataException("Native save repeats a Sim animation state.");
        foreach (var state in states)
        {
            if (world.ObjectById(state.PersonId) is not XPerson person)
                throw new InvalidDataException($"Native save animation state references missing Sim {state.PersonId}.");
            person.AnimationPlayback = state.Primary is null ? null : AvatarAnimationPlayback.RestoreState(state.Primary);
            person.BackgroundAnimationPlayback = state.Background is null ? null : AvatarAnimationPlayback.RestoreState(state.Background);
            person.CarryAnimationPlayback = state.Carry is null ? null : AvatarAnimationPlayback.RestoreState(state.Carry);
            RoutePersistence.RestorePendingAnimationEvents(person, state.PendingAnimationEvents);
            person.BackgroundPracticePersonState = state.BackgroundPracticePersonState;
            person.AnimatorWalkingScale = RoutePersistence.RestoreAnimatorWalkingScale(
                state.AnimatorWalkingScale, state.Route);
            person.AnimatorControlState = state.AnimatorControlState ?? 3;
            person.AnimatorPoolTransitionState = state.AnimatorPoolTransitionState ?? 0;
            person.AnimatorRouteTransitionState = state.AnimatorRouteTransitionState ?? 0;
            person.AnimatorStateTailField198 = state.AnimatorStateTailField198 ?? 0;
            person.AnimatorCurrentSkill = state.AnimatorCurrentSkill ??
                (state.Primary is { RouteDriven: true } ? state.Route?.Current?.MotionAnimationIndex ?? -1 : -1);
            person.AnimatorPracticeScaleEnabled = state.AnimatorPracticeScaleEnabled ?? false;
            person.AnimatorGaitEntryState = state.AnimatorGaitEntryState ?? 0;
            person.AnimatorMilliseconds = state.AnimatorMilliseconds ?? 0;
            person.AnimatorPoolTile = state.AnimatorPoolTile ?? false;
            person.AnimatorRootX = state.AnimatorRootX ?? state.Route?.Current?.MotionX ?? state.Route?.Parents.LastOrDefault()?.MotionX;
            person.AnimatorRootY = state.AnimatorRootY ?? state.Route?.Current?.MotionY ?? state.Route?.Parents.LastOrDefault()?.MotionY;
            person.AnimatorRootDirection = state.AnimatorRootDirection ?? person[ObjectData.Direction];
            person.SetAnimatorDisplacements(state.AnimatorDisplacementX ?? 0f, state.AnimatorDisplacementY ?? 0f,
                state.AnimatorDisplacementDirection ?? 0f);
            person.InteractionAttachments.Clear();
            person.InteractionAttachments.UnionWith(state.InteractionAttachments ?? []);
            RoutePersistence.Restore(person, world.SavedExecutionStacks.GetValueOrDefault(person.Id), state.Route);
        }
    }

    private static void RestoreDialogRecords(SimulationWorld world, SavedDialogSnapshot[]? dialogs)
    {
        if (dialogs is not { Length: > 0 } || world.DialogRecords.Count > 0) return;
        foreach (var snapshot in dialogs)
        {
            if (world.ObjectById(snapshot.OwnerId) is not { } owner) continue;
            var icon = snapshot.IconId is { } iconId and not 0 ? world.ObjectById(iconId) : null;
            var record = new SimulationDialogRecord(snapshot.Token, owner, icon, snapshot.Kind, snapshot.Title,
                snapshot.Message, snapshot.Yes, snapshot.No, snapshot.Cancel, snapshot.Blocking, snapshot.AwaitsResponse)
            {
                State = snapshot.State,
                Visible = snapshot.Visible,
                ImageFile = snapshot.ImageBitmapId != 0 ? (owner.TypeRecord?.BehaviorScope as BehaviorScope)?.Private : null,
                ImageBitmapId = snapshot.ImageBitmapId,
                BookMode = snapshot.BookMode,
            };
            world.DialogRecords.Add(record);
        }
        world.SyncGenericSimsCall03DialogHandle();
    }

    // House ranges: 21-30 Downtown, 40-49 Vacation, 81-89 Superstar, 90-99 Magic Town, other community lots Unleashed.
    internal static string ModeMusic(string mode, short house, bool isCommunityLot = false)
    {
        switch (mode.ToLowerInvariant())
        {
            case "live":
                return "bkground_live";
            case "options":
                return "bkground_option";
            case "camera":
                return "bkground_camera";
            case "buy":
                if (house is >= 40 and <= 49) return "station_vacation";
                if (house is >= 81 and <= 89) return "station_superstar";
                if (house is >= 21 and <= 30) return "station_dtbuy";
                if (house is >= 93 and <= 99 || (house is >= 90 and <= 99 && isCommunityLot)) return "music_magictown";
                if (house is >= 90 and <= 92) return "music_magictown_buy";
                if (isCommunityLot) return "station_unleashed";
                return "bkground_buy1";
            case "build":
                if (house is >= 40 and <= 49 or >= 81 and <= 89 or >= 21 and <= 30 or >= 93 and <= 99 ||
                    (house is >= 90 and <= 99 && isCommunityLot))
                    return "";
                if (isCommunityLot) return "station_unleashed";
                if (house is >= 90 and <= 92) return "music_magictown_build";
                return "bkground_build";
            default:
                return "bkground_live";
        }
    }

    private string ModeMusic(string mode) =>
        ModeMusic(mode, house, Neighborhoods.IsCommunityLot(Neighborhoods.UserData(profile), house));

    private void UpdateAutoSpeed(SimulationWorld current)
    {
        if (testFixtureEnabled || house is 7 or >= 20 and <= 89 or >= 93 and <= 99 ||
            current[SimulationGlobal.SimlessBuildMode] != 0 ||
            current[SimulationGlobal.IsTutorialHouseNoYes] != 0 ||
            Neighborhoods.IsCommunityLot(Neighborhoods.UserData(profile), house))
            return;

        var humanResidents = current.WalkOrder.OfType<XPerson>()
            .Where(person => person[PersonData.PersonType] == 0 && person[PersonData.Gender] < 2)
            .ToArray();
        if (humanResidents.Length == 0) return;

        var anyAwakeOnLot = humanResidents.Any(person =>
            person[ObjectData.Hidden] == 0 &&
            person.Position.X >= 0 && person.Position.Y >= 0 &&
            person[PersonData.JobData] == 0 &&
            person[PersonData.IsPersonAtWorkSchool] == 0 &&
            person[Motive.SleepState] >= 0f);

        if (!anyAwakeOnLot)
        {
            if (autoSpeedSaved < 0 && speed > 0)
            {
                autoSpeedSaved = speed;
                SetSimulationSpeed(10);
                lastRunningSpeed = 10;
            }
        }
        else if (autoSpeedSaved > -1)
        {
            var restored = autoSpeedSaved > 0 ? autoSpeedSaved : 1;
            autoSpeedSaved = -1;
            if (speed > 0)
            {
                SetSimulationSpeed(restored);
                lastRunningSpeed = restored;
            }
        }
    }
}
