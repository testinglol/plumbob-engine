using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using FSO.Content;
using FSO.Content.TS1;
using FSO.Files.Formats.IFF;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics.Utils;

internal sealed record NativeHouseholdMember(string Name, string Bio, string Code, string Skin, short[] Personality, string? HeadChoice = null, string? BodyChoice = null);

internal static class NativeHouseholdCreation
{
    internal static FAMI Create(short house, string familyName, IReadOnlyList<NativeHouseholdMember> members)
    {
        if (house is < 1 or > 99) throw new ArgumentOutOfRangeException(nameof(house));
        ValidateText(familyName, 32, nameof(familyName));
        if (members.Count is < 1 or > 8) throw new ArgumentException("A household must contain one to eight Sims", nameof(members));
        foreach (var member in members) ValidateMember(member);
        if (!members.Any(member => member.Code[1] == 'a')) throw new ArgumentException("A household must contain at least one adult Sim", nameof(members));

        var neighborhood = Content.Get().Neighborhood;
        if (neighborhood.GetFamilyForHouse(house) != null) throw new InvalidOperationException("The selected lot already has a household");
        if (!neighborhood.ZoningDictionary.TryGetValue(house, out var zoning) || zoning != 0)
            throw new InvalidOperationException("The selected lot is not a residential lot");

        var lot = neighborhood.GetHouse(house) ?? throw new FileNotFoundException("The selected lot has no installed house data");
        var price = lot.Get<SIMI>(1)?.PurchaseValue ?? 0;
        if (price < 0 || price > 20_000) throw new InvalidOperationException("The selected lot costs more than a new household can afford");

        var infos = members.Select(member =>
        {
            var info = new SimTemplateCreateInfo(member.Code, member.Skin)
            {
                Name = member.Name,
                Bio = member.Bio,
                PersonalityPoints = member.Personality.ToArray()
            };
            NativeHouseholdAppearance.Apply(info, member);
            return info;
        }).ToArray();

        var family = SimitoneNeighbourGenerator.CreateFamily(familyName, infos.Length, infos);
        // The template character carries the template's portraits; the original renders each new Sim's own.
        var objects = (TS1ObjectProvider)Content.Get().WorldObjects;
        for (var i = 0; i < family.FamilyGUIDs.Length && i < members.Count; i++)
        {
            try
            {
                if (!objects.Entries.TryGetValue(family.FamilyGUIDs[i], out var entry)) continue;
                NativeSimPortrait.Write(entry.FileName, NativeHouseholdAppearancePreview.Avatar(infos[i], members[i].Code[1] == 'c', members[i].Skin));
            }
            catch (Exception error)
            {
                Console.Error.WriteLine($"SimsSimulation: portrait for {members[i].Name} failed: {error.Message}");
            }
        }
        neighborhood.SetFamilyForHouse(house, family, true);
        neighborhood.SaveNeighbourhood(true);
        return family;
    }

    /// Moves an existing unhoused family onto a vacant residential lot and charges the lot price, matching the
    /// original Select a Family → Move In → Purchase House? flow (UIText STR# 132 entries 0–3).
    internal static FAMI MoveIn(short house, ushort familyId)
    {
        if (house is < 1 or > 99) throw new ArgumentOutOfRangeException(nameof(house));
        var neighborhood = Content.Get().Neighborhood;
        if (neighborhood.GetFamilyForHouse(house) != null) throw new InvalidOperationException("The selected lot already has a household");
        if (!neighborhood.ZoningDictionary.TryGetValue(house, out var zoning) || zoning != 0)
            throw new InvalidOperationException("The selected lot is not a residential lot");
        var family = neighborhood.GetFamily(familyId) ?? throw new ArgumentException("The selected family does not exist");
        if (family.HouseNumber != 0 || family.FamilyGUIDs.Length == 0 || family.Unknown == 0)
            throw new InvalidOperationException("The selected family cannot move in");
        var price = neighborhood.GetHouse(house)?.Get<SIMI>(1)?.PurchaseValue ?? throw new FileNotFoundException("The selected lot has no installed house data");
        if (price < 0 || price > family.Budget) throw new InvalidOperationException("The selected family cannot afford this lot");
        neighborhood.SetFamilyForHouse(house, family, true);
        neighborhood.SaveNeighbourhood(true);
        return family;
    }

    internal static object CheckMoveIn(string game, string profile)
    {
        var sourceUserData = Path.Combine(game, "UserData");
        var sourceHash = HashDirectory(sourceUserData);
        var neighborhood = Content.Get().Neighborhood;
        var families = NativeNeighborhoodExport.UnhousedFamilies();
        // The installed neighborhood starts with every family housed; evict one to get a family for the picker.
        var evictedFirst = false;
        if (families.Length == 0)
        {
            var occupied = neighborhood.ZoningDictionary
                .Where(pair => pair.Key > 0 && pair.Value == 0 && neighborhood.GetFamilyForHouse(pair.Key) != null)
                .Select(pair => (int)pair.Key).OrderBy(value => value).FirstOrDefault();
            if (occupied != 0)
            {
                NativeNeighborhoodEdits.Evict(occupied);
                evictedFirst = true;
                families = NativeNeighborhoodExport.UnhousedFamilies();
            }
        }
        var lots = neighborhood.ZoningDictionary
            .Where(pair => pair.Key > 0 && pair.Value == 0 && neighborhood.GetFamilyForHouse(pair.Key) == null)
            .Select(pair => new { House = pair.Key, Price = neighborhood.GetHouse(pair.Key)?.Get<SIMI>(1)?.PurchaseValue ?? -1 })
            .Where(lot => lot.Price >= 0)
            .OrderBy(lot => lot.Price)
            .ToArray();
        var choice = (from family in families from lot in lots where family.Budget >= lot.Price select new { family, lot }).FirstOrDefault();
        var fundedForCheck = false;
        if (choice == null && families.Length > 0 && lots.Length > 0)
        {
            // The installed families cannot afford any vacant lot, so give one family enough funds to exercise a successful move-in.
            var richest = families.OrderByDescending(candidate => candidate.Budget).First();
            var cheapest = lots[0];
            neighborhood.GetFamily((ushort)richest.Id)!.Budget = cheapest.Price + 500;
            families = NativeNeighborhoodExport.UnhousedFamilies();
            choice = (from family in families from lot in lots where family.Budget >= lot.Price select new { family, lot }).FirstOrDefault();
            fundedForCheck = choice != null;
        }
        if (choice == null)
            throw new InvalidOperationException($"No unhoused family can afford a vacant residential lot; families={families.Length}, vacantLots={lots.Length}");

        var poorest = families.OrderBy(family => family.Budget).First();
        var unaffordable = lots.FirstOrDefault(lot => lot.Price > poorest.Budget);
        var rejectedUnaffordable = false;
        if (unaffordable != null)
        {
            try { MoveIn(unaffordable.House, (ushort)poorest.Id); }
            catch (InvalidOperationException) { rejectedUnaffordable = true; }
            if (!rejectedUnaffordable) throw new InvalidDataException("A family moved into a lot it could not afford");
        }

        var movedIn = MoveIn(choice.lot.House, (ushort)choice.family.Id);
        if (movedIn.HouseNumber != choice.lot.House || movedIn.Budget != choice.family.Budget - choice.lot.Price)
            throw new InvalidDataException("Moving in did not assign the lot or charge its price");
        var rejectedOccupied = false;
        try { MoveIn(choice.lot.House, (ushort)choice.family.Id); }
        catch (InvalidOperationException) { rejectedOccupied = true; }
        if (!rejectedOccupied) throw new InvalidDataException("A second move-in onto an occupied lot was accepted");

        var activatedLot = SimulationServer.LoadHouse(Path.Combine(profile, "UserData"), choice.lot.House, true);
        if (activatedLot.TS1State.CurrentFamily?.ChunkID != movedIn.ChunkID)
            throw new InvalidDataException("The moved-in family did not activate on its new lot");
        if (!HashDirectory(sourceUserData).SequenceEqual(sourceHash))
            throw new InvalidDataException("Moving in modified the installed UserData");
        return new
        {
            result = "passed",
            family = movedIn.ChunkID,
            house = choice.lot.House,
            price = choice.lot.Price,
            budgetBefore = choice.family.Budget,
            budgetAfter = movedIn.Budget,
            unaffordableRejected = unaffordable == null ? (bool?)null : rejectedUnaffordable,
            occupiedRejected = rejectedOccupied,
            householdActivated = true,
            evictedFirst,
            fundedForCheck,
            sourceUserDataUnchanged = true
        };
    }

    internal static object Check(string game, string profile, string? sourceUserDataOverride = null)
    {
        var sourceUserData = sourceUserDataOverride ?? Path.Combine(game, "UserData");
        var sourceHash = HashDirectory(sourceUserData);
        var neighborhood = Content.Get().Neighborhood;
        var importedHome = neighborhood.ZoningDictionary
            .Where(pair => pair.Key > 0 && pair.Value == 0 && neighborhood.GetFamilyForHouse(pair.Key) != null)
            .OrderBy(pair => pair.Key)
            .Select(pair => (short?)pair.Key)
            .FirstOrDefault();
        if (importedHome == null) throw new InvalidOperationException("The installed neighborhood has no occupied residential household to import");
        var importedFamily = neighborhood.GetFamilyForHouse(importedHome.Value) ?? throw new InvalidDataException("The installed household record is missing");
        var importedLot = SimulationServer.LoadHouse(Path.Combine(profile, "UserData"), importedHome.Value, true);
        if (importedLot.TS1State.CurrentFamily?.ChunkID != importedFamily.ChunkID || importedFamily.FamilyGUIDs.Length == 0)
            throw new InvalidDataException("An installed household did not activate from the isolated native profile");

        var house = neighborhood.ZoningDictionary
            .Where(pair => pair.Key > 0 && pair.Value == 0 && neighborhood.GetFamilyForHouse(pair.Key) == null)
            .Select(pair => new { House = pair.Key, Price = neighborhood.GetHouse(pair.Key)?.Get<SIMI>(1)?.PurchaseValue ?? 0 })
            .Where(lot => lot.Price is >= 0 and <= 20_000)
            .OrderBy(lot => lot.House)
            .Select(lot => (short?)lot.House)
            .FirstOrDefault();
        if (house == null) throw new InvalidOperationException("No vacant residential lot is available for the household check");

        var checkSession = Path.Combine(profile, "HouseholdCreationCheck");
        VerifyLotAvailability(checkSession, house.Value, false);
        var emptyLot = SimulationServer.LoadHouse(Path.Combine(profile, "UserData"), house.Value, true);
        if (emptyLot.TS1State.CurrentFamily != null)
            throw new InvalidDataException("A vacant residential lot activated a household before creation");

        var appearanceCatalogs = (from gender in new[] { "m", "f" }
                                  from age in new[] { "adult", "child" }
                                  from skin in new[] { "lgt", "med", "drk" }
                                  select ((gender, age, skin), Catalog: NativeHouseholdAppearance.Catalog(gender, age, skin)))
            .ToDictionary(item => item.Item1, item => item.Catalog);
        var adultAppearance = appearanceCatalogs[("m", "adult", "lgt")];
        var childAppearance = appearanceCatalogs[("m", "child", "med")];
        var chosenHeadReplacements = new[] { adultAppearance.Heads[0].Replacement, childAppearance.Heads[0].Replacement };
        var chosenBodyReplacements = new[] { adultAppearance.Bodies[0].Replacement, childAppearance.Bodies[0].Replacement };
        object CheckMember(string name, string age, string skin, NativeAppearanceCatalog catalog)
        {
            var body = catalog.Bodies[0];
            return new
            {
                name,
                bio = "",
                code = "m" + (age == "child" ? "c" : "a") + body.BodyType,
                skin,
                personality = new[] { 500, 500, 500, 500, 500 },
                headChoice = catalog.Heads[0].Id,
                bodyChoice = body.Id
            };
        }
        var createRequest = JsonSerializer.Serialize(new
        {
            id = "native-household-check",
            op = "createHousehold",
            familyName = "Native Check",
            members = new[]
            {
                CheckMember("Alex", "adult", "lgt", adultAppearance),
                CheckMember("Casey", "child", "med", childAppearance)
            }
        });
        var appearanceRequest = JsonSerializer.Serialize(new { id = "native-household-appearance", op = "appearanceCatalog", gender = "m", age = "adult", skin = "lgt" });
        var previewRequest = JsonSerializer.Serialize(new
        {
            id = "native-household-preview", op = "appearancePreview", gender = "m", age = "adult", skin = "lgt",
            headChoice = adultAppearance.Heads[0].Id, bodyChoice = adultAppearance.Bodies[0].Id
        });
        var saveRequest = JsonSerializer.Serialize(new { id = "native-household-save", op = "save", slot = "native-household-check" });
        var loadRequest = JsonSerializer.Serialize(new { id = "native-household-load", op = "load", slot = "native-household-check" });
        var stateRequest = JsonSerializer.Serialize(new { id = "native-household-state", op = "state" });
        var previousInput = Console.In;
        var outputBuffer = new MemoryStream();
        FAMI? family = null;
        var profileSaveReload = false;
        var appearancePreviewExported = false;
        try
        {
            Console.SetIn(new StringReader(string.Join('\n', appearanceRequest, previewRequest, createRequest, saveRequest, loadRequest, stateRequest, "{\"id\":\"native-household-check-exit\",\"op\":\"quit\"}") + "\n"));
            using var writer = new StreamWriter(outputBuffer, new UTF8Encoding(false), 1024, true);
            var server = new SimulationServer(emptyLot, writer, checkSession, profile, game, house.Value);
            server.Run().GetAwaiter().GetResult();
            writer.Flush();
            foreach (var line in Encoding.UTF8.GetString(outputBuffer.ToArray()).Split('\n', StringSplitOptions.RemoveEmptyEntries))
            {
                using var message = JsonDocument.Parse(line);
                var root = message.RootElement;
                if (!root.TryGetProperty("type", out var type) || type.GetString() != "response" || !root.TryGetProperty("id", out var id)) continue;
                var requestID = id.GetString();
                if (requestID is not ("native-household-appearance" or "native-household-preview" or "native-household-check" or "native-household-save" or "native-household-load" or "native-household-state")) continue;
                if (!root.GetProperty("ok").GetBoolean())
                    throw new InvalidOperationException(root.GetProperty("error").GetString() ?? $"The {requestID} protocol request failed");
                var result = root.GetProperty("result");
                if (requestID == "native-household-appearance")
                {
                    if (result.GetProperty("heads").GetArrayLength() == 0 || result.GetProperty("bodies").GetArrayLength() == 0)
                        throw new InvalidDataException("The appearance catalog returned no installed head or clothing choices");
                }
                else if (requestID == "native-household-preview")
                {
                    var relativePath = result.GetProperty("file").GetString();
                    if (result.GetProperty("schemaVersion").GetInt32() != 1 || relativePath != "cas-preview/preview.json")
                        throw new InvalidDataException("The appearance preview returned an unsupported manifest");
                    var previewDirectory = Path.Combine(checkSession, "cas-preview");
                    var manifestPath = Path.Combine(checkSession, relativePath);
                    using var manifest = JsonDocument.Parse(File.ReadAllBytes(manifestPath));
                    var textures = manifest.RootElement.GetProperty("textures").EnumerateArray().ToArray();
                    var meshes = manifest.RootElement.GetProperty("meshes").EnumerateArray().ToArray();
                    if (manifest.RootElement.GetProperty("schemaVersion").GetInt32() != 1 || meshes.Length == 0 || textures.Length == 0 ||
                        result.GetProperty("meshes").GetInt32() != meshes.Length || result.GetProperty("textures").GetInt32() != textures.Length)
                        throw new InvalidDataException("The appearance preview manifest has no renderable avatar geometry");
                    foreach (var texture in textures)
                    {
                        var texturePath = Path.GetFullPath(Path.Combine(previewDirectory, texture.GetProperty("file").GetString() ?? ""));
                        if (!texturePath.StartsWith(previewDirectory + Path.DirectorySeparatorChar, StringComparison.Ordinal) || !File.Exists(texturePath))
                            throw new InvalidDataException("An appearance preview texture is missing or escapes its session directory");
                    }
                    appearancePreviewExported = true;
                }
                else if (requestID == "native-household-check")
                {
                    var familyID = checked((ushort)result.GetProperty("family").GetInt32());
                    family = Content.Get().Neighborhood.GetFamily(familyID);
                }
                else if (requestID is "native-household-load" or "native-household-state")
                {
                    var householdSims = result.GetProperty("sims").EnumerateArray().Count(sim => sim.GetProperty("household").GetBoolean());
                    if (result.GetProperty("house").GetInt32() != house.Value || family == null || result.GetProperty("family").GetInt32() != family.ChunkID || householdSims != 2)
                        throw new InvalidDataException("The saved household did not survive the runtime save/load protocol");
                    if (requestID == "native-household-state") profileSaveReload = true;
                }
            }
        }
        finally
        {
            Console.SetIn(previousInput);
            outputBuffer.Dispose();
        }
        if (!appearancePreviewExported) throw new InvalidDataException("The simulation server did not export a usable Create-a-Sim preview");
        if (family == null) throw new InvalidDataException("The simulation server did not acknowledge household creation");
        if (!profileSaveReload || !File.Exists(Path.Combine(profile, "Saves", "native-household-check.json")))
            throw new InvalidDataException("The native profile did not save and reload the created household through the runtime protocol");
        VerifyLotAvailability(checkSession, house.Value, true);
        var saved = new IffFile(Path.Combine(profile, "UserData", "Neighborhood.iff"));
        var persistedFamily = saved.Get<FAMI>((ushort)family.ChunkID);
        if (persistedFamily == null || persistedFamily.HouseNumber != house.Value || persistedFamily.FamilyGUIDs.Length != 2)
            throw new InvalidDataException("Created household was not persisted to the profile neighborhood");

        foreach (var guid in family.FamilyGUIDs)
        {
            var neighborID = neighborhood.GetNeighborIDForGUID(guid) ?? throw new InvalidDataException("Created Sim has no neighborhood record");
            var neighbor = neighborhood.GetNeighborByID(neighborID) ?? throw new InvalidDataException("Created Sim record is missing");
            if (neighbor.PersonMode != 9 || neighbor.PersonData.Length < 88 || neighbor.PersonData[61] != family.ChunkID)
                throw new InvalidDataException("Created Sim has invalid person data or household membership");
        }

        var characterFiles = Directory.GetFiles(Path.Combine(profile, "UserData", "Characters"), "User*.iff");
        foreach (var index in family.FamilyGUIDs.Select((guid, index) => (guid, index)))
        {
            var character = characterFiles.Select(path => new IffFile(path))
                .FirstOrDefault(file => file.List<OBJD>()?.Any(obj => obj.GUID == index.guid) == true);
            var bodyStrings = character?.Get<STR>(200);
            if (bodyStrings == null || bodyStrings.GetString(1) != chosenBodyReplacements[index.index] ||
                bodyStrings.GetString(2) != chosenHeadReplacements[index.index])
                throw new InvalidDataException("A selected head or outfit was not persisted in the created character resource");
        }

        var loaded = SimulationServer.LoadHouse(Path.Combine(profile, "UserData"), house.Value, true);
        var loadedFamily = loaded.TS1State.CurrentFamily;
        if (loadedFamily == null || loadedFamily.ChunkID != family.ChunkID || loadedFamily.FamilyGUIDs.Length != family.FamilyGUIDs.Length)
            throw new InvalidDataException("The created household did not activate when its lot was reloaded");

        var afterHash = HashDirectory(sourceUserData);
        if (!CryptographicOperations.FixedTimeEquals(sourceHash, afterHash))
            throw new InvalidDataException("Household creation modified installed game user data");

        return new { result = "passed", house = house.Value, vacantLotLoaded = true, lotAvailability = true, originalHouseholdImport = true, importedHouse = importedHome.Value,
            importedMembers = importedFamily.FamilyGUIDs.Length, protocolCreation = true, members = family.FamilyGUIDs.Length, householdReload = true, profileSaveReload,
            budget = family.Budget, sourceNeighborhoodUnchanged = true, sourceUserDataUnchanged = true,
            installedAppearanceCatalog = true, appearanceCatalogVariants = appearanceCatalogs.Count, appearancePreviewExported, selectedAppearancesPersisted = true,
            profileCharacters = Directory.GetFiles(Path.Combine(profile, "UserData", "Characters"), "User*.iff").Length };
    }

    internal static byte[] HashDirectory(string directory)
    {
        using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
        foreach (var file in Directory.EnumerateFiles(directory, "*", SearchOption.AllDirectories)
                     .OrderBy(path => Path.GetRelativePath(directory, path), StringComparer.Ordinal))
        {
            var relativePath = Encoding.UTF8.GetBytes(Path.GetRelativePath(directory, file).Replace(Path.DirectorySeparatorChar, '/'));
            hash.AppendData(BitConverter.GetBytes(relativePath.Length));
            hash.AppendData(relativePath);
            hash.AppendData(SHA256.HashData(File.ReadAllBytes(file)));
        }
        return hash.GetHashAndReset();
    }

    private static void VerifyLotAvailability(string session, short house, bool expectedOccupied)
    {
        NativeNeighborhoodExport.Export(session, 1);
        using var manifest = JsonDocument.Parse(File.ReadAllText(Path.Combine(session, "neighborhood.json")));
        var entry = manifest.RootElement.GetProperty("entries").EnumerateArray()
            .Single(item => item.GetProperty("house").GetInt32() == house);
        if (entry.GetProperty("occupied").GetBoolean() != expectedOccupied ||
            !entry.GetProperty("residential").GetBoolean() ||
            entry.GetProperty("availableForCreation").GetBoolean() == expectedOccupied)
            throw new InvalidDataException("Neighborhood lot availability does not match the household state");
    }

    private static void ValidateMember(NativeHouseholdMember member)
    {
        ValidateText(member.Name, 32, "member name");
        if (member.Bio.Length > 512 || member.Bio.Any(char.IsControl)) throw new ArgumentException("Sim bio is invalid or too long");
        if (member.Code.Length != 5 || member.Code[0] is not ('m' or 'f') || member.Code[1] is not ('a' or 'c') || !member.Code.Skip(2).All(character => character is >= 'a' and <= 'z'))
            throw new ArgumentException("Sim appearance code must contain gender, age and a three-letter body type");
        if (member.Skin is not ("lgt" or "med" or "drk")) throw new ArgumentException("Skin tone must be lgt, med or drk");
        if (member.Personality.Length != 5 || member.Personality.Any(value => value is < 0 or > 1000 || value % 100 != 0) || member.Personality.Sum(value => value) != 2500)
            throw new ArgumentException("Personality must distribute exactly 25 points in five one-point steps");
    }

    private static void ValidateText(string value, int maximum, string field)
    {
        if (string.IsNullOrWhiteSpace(value) || value.Length > maximum || value.Any(char.IsControl))
            throw new ArgumentException($"{field} is empty or invalid");
    }
}
