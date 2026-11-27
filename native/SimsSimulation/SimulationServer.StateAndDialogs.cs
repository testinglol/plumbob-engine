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

    private void DispatchRouteAnimationSounds(SimulationWorld current, Dictionary<short, (string Name, float Frame)> before)
    {
        foreach (var (personId, prev) in before)
        {
            if (current.ObjectById(personId) is not XPerson person ||
                person.AnimationPlayback is not { RouteDriven: true, PracticeWeight: > 0f, Clip: { FrameCount: > 0, SoundEvents.Count: > 0 } clip } pb ||
                !string.Equals(clip.Name, prev.Name, StringComparison.OrdinalIgnoreCase))
                continue;
            var duration = clip.DurationMilliseconds > 0f ? clip.DurationMilliseconds : clip.FrameCount * (1000f / 30f);
            var prevTime = prev.Frame * (duration / clip.FrameCount);
            var currTime = pb.Frame * (duration / clip.FrameCount);
            if (MathF.Abs(currTime - prevTime) < 0.01f) continue;
            var backwards = pb.PracticeScale < 0f;
            if (!backwards)
            {
                if (currTime >= prevTime)
                {
                    foreach (var sound in clip.SoundEvents!)
                        if (sound.TimeMilliseconds > prevTime && sound.TimeMilliseconds <= currTime)
                            HandleAnimationSound(person.Id, sound);
                }
                else
                {
                    var dispatchedWrap = false;
                    foreach (var sound in clip.SoundEvents!)
                    {
                        if (sound.TimeMilliseconds > prevTime && sound.TimeMilliseconds <= duration)
                        {
                            HandleAnimationSound(person.Id, sound);
                            dispatchedWrap = true;
                        }
                    }
                    if (!dispatchedWrap)
                    {
                        foreach (var sound in clip.SoundEvents!)
                        {
                            if (sound.TimeMilliseconds >= 0 && sound.TimeMilliseconds <= currTime)
                                HandleAnimationSound(person.Id, sound);
                        }
                    }
                }
            }
            else
            {
                if (currTime <= prevTime)
                {
                    for (var i = clip.SoundEvents!.Count - 1; i >= 0; i--)
                    {
                        var sound = clip.SoundEvents[i];
                        if (sound.TimeMilliseconds < prevTime && sound.TimeMilliseconds >= currTime)
                            HandleAnimationSound(person.Id, sound);
                    }
                }
                else
                {
                    var dispatchedWrap = false;
                    for (var i = clip.SoundEvents!.Count - 1; i >= 0; i--)
                    {
                        var sound = clip.SoundEvents[i];
                        if (sound.TimeMilliseconds < prevTime && sound.TimeMilliseconds >= 0)
                        {
                            HandleAnimationSound(person.Id, sound);
                            dispatchedWrap = true;
                        }
                    }
                    if (!dispatchedWrap)
                    {
                        for (var i = clip.SoundEvents.Count - 1; i >= 0; i--)
                        {
                            var sound = clip.SoundEvents[i];
                            if (sound.TimeMilliseconds <= duration && sound.TimeMilliseconds >= currTime)
                                HandleAnimationSound(person.Id, sound);
                        }
                    }
                }
            }
        }
    }

    private void HandleAnimationSound(short ownerId, AvatarAnimationSoundEvent cue)
    {
        if (!string.IsNullOrEmpty(cue.PackId))
        {
            plugins?.PlayAnimationSound(cue.PackId, cue.Resource, ownerId, cue.Cue, cue.Loop, cue.Stop);
            return;
        }
        var current = world;
        if (current?.ObjectById(ownerId) is not XPerson person || string.IsNullOrWhiteSpace(cue.Cue)) return;

        switch (cue.Resource)
        {
            case "sound":
            {
                var inWorld = person[ObjectData.Hidden] == 0 && person.Position.X >= 0 && person.Position.Y >= 0;
                if (!inWorld)
                {
                    if (person[PersonData.Gender] >= 2)
                        audio?.Play(cue.Cue, -4);
                }
                else
                {
                    current.PlaySoundEvent?.Invoke(cue.Cue, person.Id, true, true);
                }
                break;
            }
            case "selectedsound":
                if (person.Id == selectedSim)
                    current.PlaySoundEvent?.Invoke(cue.Cue, person.Id, true, true);
                break;
            case "deselectedsound":
                if (person.Id != selectedSim)
                    current.PlaySoundEvent?.Invoke(cue.Cue, person.Id, true, true);
                break;
            case "footstep":
            {
                if ((person[PersonData.IsLivingGhost] & 1) != 0 ||
                    (person[PersonData.IsGhost] & 1) != 0 ||
                    (person[PersonData.RenderDisplayFlags] & 8) != 0)
                    return;
                if (int.TryParse(cue.Cue, System.Globalization.NumberStyles.Integer, System.Globalization.CultureInfo.InvariantCulture, out var stepValue))
                {
                    var backward = (person.AnimationPlayback?.PracticeScale ?? 1f) < 0f;
                    if (!backward && stepValue is not (1 or 2)) return;
                    if (backward && stepValue is not (-1 or -2)) return;
                }
                if (person[ObjectData.Hidden] != 0 || person.Position.X < 0 || person.Position.Y < 0)
                    return;
                var footstepCue = ResolveFootstepCue(person);
                current.PlaySoundEvent?.Invoke(footstepCue, person.Id, true, true);
                break;
            }
        }
    }

    private string ResolveFootstepCue(XPerson person)
    {
        // Outfit values 1, 2, 5, and 14 represent barefoot attire for footsteps.
        var barefoot = person[PersonData.CurrentOutfit] is 1 or 2 or 5 or 14;
        var tx = person.Position.X >> 4;
        var ty = person.Position.Y >> 4;
        var level = Math.Max(1, (int)person.Position.Height);

        if (person[PersonData.IsSwimming] != 0 ||
            (level == 1 && lot is not null && LotPool.Read(lot).IsPool(tx, ty, 1)))
            return "footstep_pool_swim_stroke";

        if (level == 1 && lot is not null && LotWater.Read(lot).IsWater(tx, ty, 1))
            return "footstep_puddle";

        if (ResolveObjectSurfaceFootstepCue(world, tx, ty, level) is { } objectCue)
            return objectCue;

        ushort floorPattern = 0;
        if (lot is not null && tx is >= 0 and < LotFloors.Size && ty is >= 0 and < LotFloors.Size)
        {
            try { floorPattern = LotFloors.Read(lot, level)[tx, ty]; } catch { }
        }

        if (floorPattern == 0)
        {
            if (GroundSnow())
                return "footstep_snow";
            if (house == 99)
                return barefoot ? "footstep_soft_noshoe" : "footstep_soft";
            return barefoot ? "footstep_terrain_noshoe" : "footstep_terrain";
        }

        if (floorPattern == 0xff)
            return barefoot ? "footstep_hard_noshoe" : "footstep_hard";

        return GetFloorSoundCode(floorPattern) switch
        {
            'H' => barefoot ? "footstep_medium_noshoe" : "footstep_medium",
            'S' => barefoot ? "footstep_soft_noshoe" : "footstep_soft",
            _ => barefoot ? "footstep_hard_noshoe" : "footstep_hard",
        };
    }

    private static string? ResolveObjectSurfaceFootstepCue(SimulationWorld? currentWorld, int tx, int ty, int level)
    {
        if (currentWorld is null) return null;

        var bestPriority = 0;
        void CheckObject(XObject item)
        {
            if (item is XPerson || item[ObjectData.ContainerId] != 0) return;
            var guid = item.TypeRecord is { } tr
                ? unchecked((uint)tr.Key)
                : (uint)(ushort)item.Definition[(int)ObjdField.Guid1] | ((uint)(ushort)item.Definition[(int)ObjdField.Guid2] << 16);
            var priority = guid switch
            {
                0x3E7470F6u or 0x5C67FC8Fu or 0x9BE030B9u => 10,
                99999999u => 9,
                0x63416BA1u => 8,
                0x7F907075u or 0xBF62F653u => 7,
                0x96E3398Du or 0xA2DAA08Cu or 0xC02B406Au or 0x65274A4Fu => 6,
                _ => 0,
            };
            if (priority > bestPriority) bestPriority = priority;
        }

        foreach (var item in currentWorld.ObjectsAtTile(tx, ty, level))
            CheckObject(item);

        foreach (var item in currentWorld.WalkOrder)
        {
            if ((item.Position.X >> 4) == tx &&
                (item.Position.Y >> 4) == ty &&
                Math.Max(1, (int)item.Position.Height) == level)
                CheckObject(item);
        }

        return bestPriority switch
        {
            10 => "footstep_puddle",
            9 => "footstep_roach",
            8 => "footstep_ash",
            7 => "footstep_trash",
            6 => "footstep_plant",
            _ => null,
        };
    }

    private char GetFloorSoundCode(ushort pattern)
    {
        if (floorSoundCodes is null)
        {
            floorSoundCodes = [];
            try
            {
                var gameData = Path.Combine(game, "GameData");
                if (!Directory.Exists(gameData)) gameData = game;
                if (Directory.Exists(gameData))
                {
                    var floorPath = Directory.EnumerateFiles(gameData).FirstOrDefault(path =>
                        Path.GetFileName(path).Equals("floors.iff", StringComparison.OrdinalIgnoreCase));
                    if (floorPath is not null)
                    {
                        var globals = IffFile.Open(floorPath);
                        for (ushort id = 1; id <= 29; id++)
                        {
                            if (ReadNonEmptyFloorSoundCode(globals, id, (ushort)(id + 256)) is { } code)
                                floorSoundCodes[id] = code;
                        }
                    }
                    foreach (var entry in FloorCatalog.DynamicEntries(game))
                    {
                        try
                        {
                            var iff = entry.Open();
                            if (ReadNonEmptyFloorSoundCode(iff, 1, 257) is { } code)
                                floorSoundCodes[(ushort)entry.PatternId] = code;
                        }
                        catch { }
                    }
                }
            }
            catch { }
        }
        return floorSoundCodes.GetValueOrDefault(pattern, 'M');
    }

    private static char? ReadNonEmptyFloorSoundCode(IffFile iff, params ushort[] ids)
    {
        var spr2 = ResourceType.Parse("SPR2");
        foreach (var id in ids)
        {
            var chunk = iff.Find(spr2, id);
            if (chunk?.Label is { Length: > 0 } name)
                return char.ToUpperInvariant(name[0]);
        }
        return null;
    }

    private object PhoneBook(SimulationDialogRecord record)
    {
        var current = world;
        if (current is null || record.Owner is not XPerson owner ||
            !current.Neighbors.TryGetValue(owner[PersonData.NeighborId], out var caller))
            return Array.Empty<object>();

        var familyStrings = neighborhood is null ? null : neighborhood.OfType(ResourceType.Parse("FAMs"))
            .ToDictionary(chunk => chunk.Id, chunk => StringTable.Read(neighborhood, chunk).ForLanguage(language).FirstOrDefault() ?? "");

        if (neighborhood is not null)
        {
            var neighborsByGuid = current.Neighbors.Values
                .Where(neighbor => neighbor.TypeRecordKey != 0)
                .GroupBy(neighbor => unchecked((uint)neighbor.TypeRecordKey))
                .ToDictionary(group => group.Key, group => group.First());
            var callerFamilyId = caller.PersonData[(int)PersonData.FamilyNumber];
            var result = new List<object>();

            foreach (var chunk in neighborhood.OfType(ResourceType.Parse("FAMI")))
            {
                var familyId = (int)chunk.Id;
                var family = Family.Read(neighborhood, chunk);
                if (familyId == callerFamilyId || familyId == activeFamilyChunkId ||
                    !(familyId > 1999 || (familyId != 0 && family.HouseNumber > 0)))
                    continue;

                var familyContacts = new List<object>();
                foreach (var guid in family.Members)
                {
                    if (!neighborsByGuid.TryGetValue(guid, out var contact) ||
                        contact.Id == caller.Id ||
                        contact.PersonData[(int)PersonData.Gender] >= 2 ||
                        caller.Relationships.Count(contact.Id) < 1)
                        continue;

                    var catalogName = registry?.Find(guid)?.CatalogString(0, language);
                    var livePerson = current.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person[PersonData.NeighborId] == contact.Id);
                    var contactName = !string.IsNullOrWhiteSpace(livePerson?.Name) ? livePerson.Name
                        : !IsInternalUserLabel(contact.Name) ? contact.Name!
                        : !string.IsNullOrWhiteSpace(catalogName) ? catalogName
                        : livePerson?.TypeRecord?.CatalogName is { Length: > 0 } liveCatalog ? liveCatalog
                        : contact.Name ?? livePerson?.TypeRecord?.Name ?? "";
                    familyContacts.Add(new { neighborId = (int)contact.Id, name = contactName, portrait = images?.Portrait(guid) });
                }

                if (familyContacts.Count > 0)
                {
                    result.Add(new
                    {
                        familyId,
                        name = familyStrings?.GetValueOrDefault(chunk.Id) is { Length: > 0 } label ? label : familyId.ToString(),
                        contacts = familyContacts.ToArray(),
                    });
                }
            }
            return result.ToArray();
        }

        var contacts = new List<(short Family, short Neighbor, string Name, object? Portrait)>();
        foreach (var relation in caller.Relationships.Snapshot().Keys)
        {
            if (relation is <= 0 or > short.MaxValue || relation == caller.Id || caller.Relationships.Count((short)relation) < 1 ||
                !current.Neighbors.TryGetValue((short)relation, out var contact)) continue;
            var family = contact.PersonData[(int)PersonData.FamilyNumber];
            if (family <= 0 || family == caller.PersonData[(int)PersonData.FamilyNumber] ||
                contact.PersonData[(int)PersonData.Gender] > 1) continue;
            var guid = unchecked((uint)contact.TypeRecordKey);
            var catalogName = registry?.Find(guid)?.CatalogString(0, language);
            var livePerson = current.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person[PersonData.NeighborId] == relation);
            var name = !string.IsNullOrWhiteSpace(livePerson?.Name) ? livePerson.Name
                : !IsInternalUserLabel(contact.Name) ? contact.Name!
                : !string.IsNullOrWhiteSpace(catalogName) ? catalogName
                : livePerson?.TypeRecord?.CatalogName is { Length: > 0 } liveCatalog ? liveCatalog
                : contact.Name ?? livePerson?.TypeRecord?.Name ?? "";
            contacts.Add((family, (short)relation, name, images?.Portrait(guid)));
        }

        return contacts.GroupBy(contact => contact.Family).Select(group => (object)new
        {
            familyId = (int)group.Key,
            name = familyStrings?.GetValueOrDefault(unchecked((ushort)group.Key)) is { Length: > 0 } label ? label : group.Key.ToString(),
            contacts = group.Select(contact => new { neighborId = (int)contact.Neighbor, name = contact.Name, portrait = contact.Portrait }).ToArray(),
        }).ToArray();
    }

    private static bool IsInternalUserLabel(string? value) =>
        string.IsNullOrWhiteSpace(value) ||
        (value.Length >= 5 && value.StartsWith("user", StringComparison.OrdinalIgnoreCase) && value.AsSpan(4).ToArray().All(char.IsAsciiDigit));

    private Family? ActiveFamily() => (world?.FamilyBudget as FamilyBudget)?.ActiveFamily;

    private uint PersonGuid(XPerson person) => unchecked((uint)(person.TypeRecord?.Key ??
        (world?.Neighbors.TryGetValue(person[PersonData.NeighborId], out var neighbor) == true ? neighbor.TypeRecordKey : 0)));

    private bool IsHouseholdPerson(XPerson person) =>
        (person[PersonData.IsGhost] & 1) == 0 &&
        ActiveFamily()?.Members.Contains(PersonGuid(person)) == true;

    private bool IsValidSelectedSim(SimulationWorld? target, short simId) =>
        simId > 0 && target?.ObjectById(simId) is XPerson p && IsHouseholdPerson(p);

    private bool ReconcileSelectedSim(SimulationWorld target)
    {
        if (IsValidSelectedSim(target, selectedSim))
            return false;
        var nextSelected = DefaultSelectedSimId();
        if (nextSelected == selectedSim)
            return false;
        selectedSim = nextSelected;
        SyncSelectedSimFlags(target, selectedSim);
        return true;
    }

    private static bool IsControllableHuman(XPerson person) =>
        person[PersonData.Gender] < 2 && (person.AnimatorBodyStringMode & 6) == 0;

    private short DefaultSelectedSimId()
    {
        var people = PanelPeople();
        return people.FirstOrDefault(p => IsHouseholdPerson(p) && IsControllableHuman(p) && PersonAgeCategory.IsAdult(p[PersonData.PersonAge]))?.Id
            ?? people.FirstOrDefault(p => IsHouseholdPerson(p) && IsControllableHuman(p))?.Id
            ?? people.FirstOrDefault(IsHouseholdPerson)?.Id
            ?? (short)0;
    }

    private XPerson[] PanelPeople()
    {
        if (world is null) return [];
        var people = world.WalkOrder.OfType<XPerson>().ToArray();
        var roster = ActiveFamily()?.Members ?? [];
        var order = roster.Select((guid, index) => (guid, index)).ToDictionary(item => item.guid, item => item.index);
        return people.OrderBy(person => order.GetValueOrDefault(PersonGuid(person), int.MaxValue))
            .ThenBy(person => person.Id).ToArray();
    }

    private static object Skills(XPerson person) => new Dictionary<string, short>
    {
        ["Cooking"] = person[PersonData.CookingHouseBrokenSkill],
        ["Mechanical"] = person[PersonData.MechanicalTricksSkill],
        ["Charisma"] = person[PersonData.CharismaObedienceSkill],
        ["Body"] = person[PersonData.BodyFurnitureSkill],
        ["Logic"] = person[PersonData.LogicSkill],
        ["Creativity"] = person[PersonData.CreativitySkill],
    };

    private static object PetSkills(XPerson person) => new Dictionary<string, short>
    {
        ["HouseBroken"] = person[PersonData.CookingHouseBrokenSkill],
        ["Obedience"] = person[PersonData.CharismaObedienceSkill],
        ["Tricks"] = person[PersonData.MechanicalTricksSkill],
    };

    private int FamilyFriends()
    {
        var current = world;
        var family = ActiveFamily();
        if (current is null || family is null) return 0;
        var members = family.Members.Select(guid => current.Neighbors.Values.FirstOrDefault(neighbor =>
            unchecked((uint)neighbor.TypeRecordKey) == guid)).Where(neighbor => neighbor is not null &&
                neighbor.PersonData[(int)PersonData.PersonType] <= 1 &&
                neighbor.PersonData[(int)PersonData.Gender] < 2).Cast<NeighborState>().ToArray();
        var memberGuids = family.Members.ToHashSet();
        var friends = new HashSet<short>();
        foreach (var member in members)
        foreach (var relation in member.Relationships.Snapshot())
        {
            if (relation.Key is <= 0 or > short.MaxValue || current.Neighbors.GetValueOrDefault((short)relation.Key) is not { } target ||
                memberGuids.Contains(unchecked((uint)target.TypeRecordKey)) ||
                target.PersonData[(int)PersonData.PersonType] > 1 ||
                target.PersonData[(int)PersonData.Gender] >= 2 ||
                relation.Value.Count == 0 || target.Relationships.Count(member.Id) == 0) continue;
            if (relation.Value[0] >= current.FriendshipThreshold && target.Relationships.Get(member.Id, 0) >= current.FriendshipThreshold)
                friends.Add((short)relation.Key);
        }
        return friends.Count;
    }

    private object[] Relationships(XPerson person)
    {
        var current = world;
        if (current is null || !current.Neighbors.TryGetValue(person[PersonData.NeighborId], out var owner)) return [];
        var familyGuids = ActiveFamily()?.Members.ToHashSet() ?? [];
        return owner.Relationships.Snapshot().OrderBy(pair => pair.Key).Select(pair =>
        {
            if (pair.Key is <= 0 or > short.MaxValue || current.Neighbors.GetValueOrDefault((short)pair.Key) is not { } target || target.Id == owner.Id)
                return null;
            var guid = unchecked((uint)target.TypeRecordKey);
            var reverseDaily = target.Relationships.Count(owner.Id) > 0 ? target.Relationships.Get(owner.Id, 0) : 0;
            var daily = pair.Value.Count > 0 ? pair.Value[0] : 0;
            var catalogName = registry?.Find(guid)?.CatalogString(0, language);
            var livePerson = current.WalkOrder.OfType<XPerson>().FirstOrDefault(sim => sim[PersonData.NeighborId] == target.Id);
            var targetData = livePerson?.PersonData ?? target.PersonData;
            return (object)new
            {
                neighborID = (int)target.Id,
                guid,
                name = !string.IsNullOrWhiteSpace(livePerson?.Name) ? livePerson.Name
                    : !IsInternalUserLabel(target.Name) ? target.Name!
                    : !string.IsNullOrWhiteSpace(catalogName) ? catalogName
                    : livePerson?.TypeRecord?.CatalogName is { Length: > 0 } liveCatalog ? liveCatalog
                    : target.Name ?? livePerson?.TypeRecord?.Name ?? "",
                description = registry?.Find(guid)?.CatalogString(1, language) ?? "",
                zodiac = (int)targetData[(int)PersonData.Zodiac],
                personality = new Dictionary<string, short>
                {
                    ["Neat"] = targetData[(int)PersonData.NeatQuietPersonality],
                    ["Outgoing"] = targetData[(int)PersonData.OutgoingFriendlyPersonality],
                    ["Active"] = targetData[(int)PersonData.ActivePlayfulPersonality],
                    ["Playful"] = targetData[(int)PersonData.PlayfulSmartPersonality],
                    ["Nice"] = targetData[(int)PersonData.NiceLoyalPersonality],
                },
                values = pair.Value,
                household = familyGuids.Contains(guid),
                portrait = images?.NeighborPortrait(guid),
                reverseDaily,
                famous = targetData.ElementAtOrDefault(81) != 0,
                mutualFriend = daily >= current.FriendshipThreshold && reverseDaily >= current.FriendshipThreshold,
                livePosition = livePerson is null ? null : new { x = livePerson.Position.X / 16f, y = livePerson.Position.Y / 16f, level = (int)livePerson.Position.Height },
            };
        }).Where(item => item is not null).Cast<object>().ToArray();
    }

    private object? CareerPanel(XPerson person, int? cachedFamilyFriends = null)
    {
        if (person[PersonData.PersonType] is < 0 or > 1 || person[PersonData.Gender] >= 2) return null;
        if (IsFamePanelEligible(person)) return null;
        var career = world?.CareerHost as CareerCatalog;
        var type = person[PersonData.JobType];
        var level = person[PersonData.JobPromotionLevel];
        var age = person[PersonData.PersonAge];
        var female = (person[PersonData.Gender] & 1) != 0;
        var school = PersonAgeCategory.IsChild(age);
        int[]? Requirements(int levelIndex)
        {
            if (career?.CareerExists(type) != true || career.JobData(type, (short)levelIndex, 0) is null) return null;
            var values = new int[10];
            for (var i = 0; i < 10; i++)
            {
                if (career.JobData(type, (short)levelIndex, (short)(i + 2)) is not { } value) return null;
                values[i] = value;
            }
            return values;
        }
        var performance = person[PersonData.JobPerformance];
        var ratingIndex = school ? Math.Clamp(performance + 1, 0, 15) : performance < -60 ? 0 : performance < -30 ? 1 : performance < 30 ? 2 : performance < 60 ? 3 : 4;
        return new
        {
            type = (int)type,
            level = (int)level,
            performance = (int)performance,
            age = (int)age,
            atWorkSchool = (int)person[PersonData.JobData],
            school,
            track = career?.TrackName(type),
            title = career?.JobText(type, level, JobTextKind.Title, female, language),
            jobDescription = career?.JobText(type, level, JobTextKind.Description, female, language),
            salary = career?.JobData(type, level, 1),
            startHour = career?.JobData(type, level, 12),
            endHour = career?.JobData(type, level, 13),
            currentLevelRequirements = Requirements(level),
            nextLevelRequirements = Requirements(level + 1),
            performanceLabel = career?.GradeString(ratingIndex, language),
            // School grades index work.iff STR# 0x1001 at performance + 1.
            reportCardGrade = school ? career?.GradeString(performance + 1, language) : null,
            familyFriends = cachedFamilyFriends ?? FamilyFriends(),
        };
    }

    private object? FamePanel(XPerson person)
    {
        if (!IsFamePanelEligible(person)) return null;
        var (tuning, titles) = FameResources();
        var level = Math.Clamp((int)person[PersonData.FameStarPower09], 0, 10);
        var title = level < titles.Count ? titles[level] : "?";
        var skillData = new[]
        {
            person[PersonData.CookingHouseBrokenSkill], person[PersonData.MechanicalTricksSkill],
            person[PersonData.CharismaObedienceSkill], person[PersonData.BodyFurnitureSkill],
            person[PersonData.LogicSkill], person[PersonData.CreativitySkill],
        };
        var skillRequirements = Enumerable.Range(0, 6).Select(index =>
            level < 10 && skillData[index] < tuning.FameSkillThresholds[index][level] * 100
                ? tuning.FameSkillThresholds[index][level] : 0).ToArray();
        var starPower = world?.FameFriendStarPower(world.PersonRecordIndex(person)) ?? 0;
        return new
        {
            score = (int)person[PersonData.FameScore],
            level,
            title,
            skills = skillData.Select(value => Math.Clamp((int)value, 0, 1000)).ToArray(),
            skillRequirements,
            friendStarPower = starPower,
            friendsNeeded = level < tuning.FameFriendThresholds.Count ? tuning.FameFriendThresholds[level] : 0,
            nextScore = level < tuning.FameStarThresholds.Count - 1 ? tuning.FameStarThresholds[level + 1] : 1000,
        };
    }

    private bool IsFamePanelEligible(XPerson person)
    {
        if (person[PersonData.PersonType] is < 0 or > 1 || person[PersonData.FameScore] <= 0 || !HasSuperstarPack()) return false;
        var career = world?.CareerHost as CareerCatalog;
        var jobType = person[PersonData.JobType];
        return jobType == 0 || career?.JobData(jobType, person[PersonData.JobPromotionLevel], 0) is null;
    }

    private (FameTuning Tuning, IReadOnlyList<string> Titles) FameResources()
    {
        if (fameTuning is not null && fameTitles is not null) return (fameTuning, fameTitles);
        var famePath = Path.Combine(game, "GameData", "fame.iff");
        var file = new IffFile(File.ReadAllBytes(famePath), famePath);
        var titleChunk = file.Find(ResourceType.Str, 1)
            ?? throw new InvalidDataException("fame.iff is missing STR# 1 fame titles");
        fameTuning = FameTuning.Read(file);
        fameTitles = StringTable.Read(file, titleChunk).ForLanguage(language);
        return (fameTuning, fameTitles);
    }

    private void InitializeFameCallbackTarget(SimulationWorld targetWorld)
    {
        targetWorld.GenericSimsCallRecordCallbackTarget = HasSuperstarPack()
            ? GenericSimsCallRecordTarget.FromFameTuning(FameResources().Tuning)
            : new GenericSimsCallRecordTarget();
    }

    private bool HasSuperstarPack()
    {
        var folder = Path.Combine(game, "ExpansionPack6");
        return Directory.Exists(folder) || File.Exists(folder + ".far");
    }

    private readonly PictureInPictureOptions pictureInPicture = new();

    private object[] PictureInPictureEvents(SimulationWorld lotWorld)
    {
        lotWorld.PictureInPicture ??= pictureInPicture;
        return lotWorld.PictureInPictureEvents.Select(item =>
        {
            var target = item.ObjectId != 0 ? lotWorld.ObjectById((short)item.ObjectId) : null;
            var insideLotEdge = target is null || SimulationWorld.IsInsideLotEdge(target);
            return (object)new
            {
                sequence = item.Sequence,
                objectId = item.ObjectId,
                open = item.Open,
                force = item.Force,
                snapshot = item.SnapshotRequested,
                durationMs = item.DurationMilliseconds,
                flags = (int)item.Flags,
                checkOffScreen = (item.Flags & 4) == 0,
                insideLotEdge,
                size = (int)item.Byte2,
                zoom = (int)item.Byte3,
                byte2 = (int)item.Byte2,
                byte3 = (int)item.Byte3,
                text = item.Text,
            };
        }).ToArray();
    }

    private ulong? lastStreamedObjectsSignature;

    private ulong ComputeObjectsSignature()
    {
        if (world is null) return 0;
        var hash = 14695981039346656037UL;
        void Mix(long v)
        {
            hash ^= unchecked((ulong)v);
            hash *= 1099511628211UL;
        }
        Mix(world.WalkOrder.Count);
        foreach (var item in world.WalkOrder)
        {
            Mix(item.Id);
            Mix(item.TypeRecord?.Key ?? 0);
            if (item is XPerson) continue;
            Mix(item.MultiTileMasterId);
            Mix(item.MultiTileNextId);
            Mix(item.Position.X);
            Mix(item.Position.Y);
            Mix(item.Position.Height);
            Mix(item[ObjectData.Direction]);
            Mix(item[ObjectData.UseCount]);
            Mix(item[ObjectData.Flags]);
            Mix(world.InteractionLifecycle.LeaseCount(item));
            Mix(world.InteractionLifecycle.WaiterCount(item));
        }
        return hash;
    }

    private object State(bool includeArchitectureGrids = true, bool includeObjects = true)
    {
        if (registry is not null) images?.SetRegistry(registry);
        if (includeObjects) lastStreamedObjectsSignature = ComputeObjectsSignature();
        var computedFamilyFriends = world is null ? (int?)null : FamilyFriends();
        var sharedValuation = world?.SavedSimulationState is { Version: >= 0x25 } savedValuation
            ? CurrentLotValuation(savedValuation)
            : ((int FurnishingsValue, int ArchitectureValue)?)null;
        var roof = lot is null ? ((string Style, float Pitch, int StyleIndex)?)null : RoofInfo(lot);
        var vanillaPayload = new
        {
        house,
        homeHouse = EffectiveHomeHouse,
        away = IsVisitingAwayLot,
        emergencyBuyBuildLocked = IsEmergencyBuyBuildLocked,
        houseStateClass = world?.StateClass(house) ?? 0,
        lotTransitInfo = world?[SimulationGlobal.LotTransitInfo] ?? 0,
        family = activeFamilyChunkId,
        tutorialResetRequiresSave = saveDirty && house != 0,
        tutorialIcon = world is { TutorialOwner: not null } activeWorld
            ? images?.TutorialIcon(activeWorld) ?? new { fallback = true }
            : null,
        updates,
        speed,
        simulationError,
        selectedSim = IsValidSelectedSim(world, selectedSim) ? selectedSim : DefaultSelectedSimId(),
        housePanel = HousePanel(sharedValuation),
        freeWill = world?.AutonomyForced,
        budget = world?.FamilyBudget?.ReadFamilyBudget(),
        familyFriends = computedFamilyFriends,
        budgetReport = BudgetReport(sharedValuation),
        hours = world?.Clock.Hour ?? 0,
        minutes = world?.Clock.Minute ?? 0,
        seconds = world?.Clock.Second ?? 0,
        wallsUp = wallMode == "up",
        wallMode,
        editingView,
        cameraOrientation,
        roofsVisible,
        roofStyle = roof?.Style,
        roofStyleIndex = roof?.StyleIndex,
        roofPitch = roof?.Pitch,
        simlessBuildMode = world is not null && world[SimulationGlobal.SimlessBuildMode] != 0,
        canUndo = undoStack.Count > 0,
        canRedo = redoStack.Count > 0,
        viewLevel,
        stories = Stories,
        dialogs = world is null ? Array.Empty<object>() : world.DialogRecords.Where(record => record.Visible).OrderByDescending(record => record.Blocking).Select(record => (object)new
        {
            token = record.Token,
            blocking = record.Blocking,
            caller = (int)record.Owner.Id,
            tutorial = world.TutorialOwner is { } tutorialOwner && ReferenceEquals(record.Owner, tutorialOwner),
            icon = (int)(record.Icon?.Id ?? 0),
            kind = record.Kind,
            title = record.Kind == 10 && string.IsNullOrEmpty(record.Title) && record.Owner is XPerson callerOwner
                ? (!string.IsNullOrWhiteSpace(callerOwner.Name) ? callerOwner.Name
                    : world.Neighbors.TryGetValue(callerOwner[PersonData.NeighborId], out var callerNeighbor) && !IsInternalUserLabel(callerNeighbor.Name) ? callerNeighbor.Name!
                    : callerOwner.TypeRecord?.CatalogName is { Length: > 0 } cat ? cat
                    : registry?.Find(PersonGuid(callerOwner))?.CatalogString(0, language) ?? "")
                : record.Title,
            message = record.Message,
            yes = record.Yes,
            no = record.No,
            cancel = record.Cancel,
            image = record.Kind == 10 && record.Owner is XPerson phoneCaller
                ? images?.Portrait(world, phoneCaller)
                : images?.DialogImage(record),
            phoneBook = record.Kind == 10 ? PhoneBook(record) : null,
            bookMode = record.BookMode,
            hideBookItem9 = record.HideBookItem9,
            hideBookItem4 = record.HideBookItem4,
            bookAvailability = record.BookAvailability?.Select(item => new
            {
                contextItemId = (int)item.ContextItemId,
                itemId = (int)item.ItemId,
                made = item.Made,
            }).ToArray(),
        }).ToArray(),
        pictureInPicture = world is null ? Array.Empty<object>() : PictureInPictureEvents(world),
        uiMessages = world is null ? Array.Empty<object>() : world.UiMessages.TakeLast(16).Select(message => (object)new
        {
            sequence = message.Sequence,
            message = message.Message,
            text = message.Text,
        }).ToArray(),
        width = LotWidth,
        height = LotHeight,
        buildable = includeArchitectureGrids ? Buildable() : null,
        buildableLevel2 = includeArchitectureGrids ? BuildableLevel2() : null,
        floors = includeArchitectureGrids ? StateFloors() : null,
        walls = includeArchitectureGrids ? StateWalls() : null,
        objects = !includeObjects ? null : world is null ? Array.Empty<object>() : world.WalkOrder.Select(item =>
        {
            var isPerson = item is XPerson;
            var buildType = !isPerson ? ObjectBuildModeType(item) : 0;
            var canSell = !isPerson && world.CanSellObject(item);
            var resaleValue = !isPerson ? SimulationWorld.HandResaleValue(world.ObjectSaleValue(item), buildType) : 0;
            return new
            {
                id = (int)item.Id,
                name = item.TypeRecord?.Name ?? "",
                guid = (uint)(item.TypeRecord?.Key ?? 0),
                multiTileMasterID = (int)item.MultiTileMasterId,
                multiTileNextID = (int)item.MultiTileNextId,
                x = item.Position.X / 16f,
                y = item.Position.Y / 16f,
                level = item.Position.Height,
                direction = (byte)(1 << (item[ObjectData.Direction] & 7)),
                useCount = (short)item[ObjectData.UseCount],
                interactionLeaseCount = world.InteractionLifecycle.LeaseCount(item),
                interactionWaiterCount = world.InteractionLifecycle.WaiterCount(item),
                avatar = isPerson,
                movable = !isPerson && world.CanPickUpObject(item),
                sellable = canSell,
                buildModeType = buildType,
                resaleValue,
                catalogName = !isPerson ? ObjectCatalogName(world, item) : "",
                catalogCategory = buildType is >= 1 and <= 7 ? (int?)(buildType + 7) : null,
            };
        }).ToArray(),
        sims = PanelPeople().Select(person => new
        {
            id = (int)person.Id,
            guid = (uint)(person.TypeRecord?.Key ?? 0),
            hideHover = (person.Definition[91] & 4) != 0,
            name = !string.IsNullOrWhiteSpace(person.Name) && !IsInternalUserLabel(person.Name)
                ? person.Name
                : world!.Neighbors.TryGetValue(person[PersonData.NeighborId], out var neighbor) && !IsInternalUserLabel(neighbor.Name)
                ? neighbor.Name!
                : person.TypeRecord?.CatalogName is { } catalogName && !string.IsNullOrWhiteSpace(catalogName)
                ? catalogName
                : world.Neighbors.TryGetValue(person[PersonData.NeighborId], out var fallbackNeighbor) && !string.IsNullOrWhiteSpace(fallbackNeighbor.Name)
                    ? fallbackNeighbor.Name
                    : person.TypeRecord?.Name ?? "",
            internalName = world!.Neighbors.TryGetValue(person[PersonData.NeighborId], out var neighborForId) && !string.IsNullOrWhiteSpace(neighborForId.Name)
                ? neighborForId.Name
                : null,
            tooltipName = !string.IsNullOrWhiteSpace(person.Name) && !IsInternalUserLabel(person.Name)
                ? person.Name
                : world!.Neighbors.TryGetValue(person[PersonData.NeighborId], out var tooltipNeighbor) && !IsInternalUserLabel(tooltipNeighbor.Name)
                    ? tooltipNeighbor.Name!
                    : person.TypeRecord?.CatalogName ?? person.TypeRecord?.Name ?? "",
            neighborID = (int)person[PersonData.NeighborId],
            household = IsHouseholdPerson(person),
            child = PersonAgeCategory.IsChild(person[PersonData.PersonAge]),
            mood = (short)person[Motive.Mood],
            personType = (int)person[PersonData.PersonType],
            gender = (int)person[PersonData.Gender],
            zodiac = (int)person[PersonData.Zodiac],
            fameScore = (int)person[PersonData.FameScore],
            jobType = (int)person[PersonData.JobType],
            personality = new Dictionary<string, short>
            {
                ["Neat"] = (short)person[PersonData.NeatQuietPersonality],
                ["Outgoing"] = (short)person[PersonData.OutgoingFriendlyPersonality],
                ["Active"] = (short)person[PersonData.ActivePlayfulPersonality],
                ["Playful"] = (short)person[PersonData.PlayfulSmartPersonality],
                ["Nice"] = (short)person[PersonData.NiceLoyalPersonality],
            },
            // PersonData 46-49 repeat at indices 8-11 because Sims.exe reuses those slots for child-specific interests.
            interests = new[] { 46, 47, 48, 49, 50, 51, 52, 53, 46, 47, 48, 49, 13, 14, 16, 20, 26, 54, 55 }
                .Select(field => (short)person.PersonData[field]).ToArray(),
            x = person.Position.X / 16f,
            y = person.Position.Y / 16f,
            level = person.Position.Height,
            animation = person.AnimationPlayback?.Clip.Name,
            interactionAttachments = person.InteractionAttachments.OrderBy(value => value, StringComparer.Ordinal).ToArray(),
            appearanceOverride = appearanceTransitions?.HasOverride(person) ?? false,
            outfitChanging = person.NativeOutfitTransitionActive,
            motives = new Dictionary<string, short>
            {
                ["Hunger"] = (short)person[Motive.Hunger], ["Comfort"] = (short)person[Motive.Comfort],
                ["Hygiene"] = (short)person[Motive.Hygiene], ["Bladder"] = (short)person[Motive.Bladder],
                ["Energy"] = (short)person[Motive.Energy], ["Fun"] = (short)person[Motive.Fun],
                ["Social"] = (short)person[Motive.Social], ["Room"] = (short)person[Motive.Room],
            },
            skills = Skills(person),
            petSkills = PetSkills(person),
            career = CareerPanel(person, computedFamilyFriends),
            fame = FamePanel(person),
            relationships = Relationships(person),
            portrait = world is null ? null : images?.Portrait(world, person),
            inventory = (world is null ? Array.Empty<AvatarInventory.Entry>() : world.NeighborInventory((short)person[PersonData.NeighborId]).Entries)
                .Where(item => item.Key1 is not (1 or 2 or 3))
                .Select(item => new { type = item.Key1, guid = unchecked((uint)item.Key2), count = (int)item.Count,
                    name = images?.ItemName(unchecked((uint)item.Key2), language) ?? $"Unknown Item ({item.Key2})",
                    description = images?.ItemDescription(unchecked((uint)item.Key2), language) ?? "", icon = images?.ItemIcon(unchecked((uint)item.Key2)) }).ToArray(),
            actions = Actions(person),
        }).ToArray(),
        nativeEngine = true,
        };
        return vanillaPayload;
    }

    private object? BudgetReport((int FurnishingsValue, int ArchitectureValue)? precomputedValuation = null)
    {
        if (world?.SavedSimulationState is not { Version: >= 0x26, BudgetDays.Count: 6 } saved) return null;
        var days = saved.BudgetDays;
        var today = days[0].Values.Take(8).Concat(Enumerable.Repeat(0, 8)).Take(8).ToArray();
        var threeDay = Enumerable.Range(0, 8).Select(index =>
            today[index] + (days[1].Values.Count > index ? days[1].Values[index] : 0)
                       + (days[2].Values.Count > index ? days[2].Values[index] : 0)).ToArray();
        var daysSinceMoveIn = (int)(world[SimulationGlobal.DaysRunning]);
        var funds = world.FamilyBudget?.ReadFamilyBudget() ?? saved.Field0x90;
        var (furnishingsValue, rawArchitectureValue) = precomputedValuation ?? CurrentLotValuation(saved);
        var architectureValue = (int)(rawArchitectureValue * (world.ArchitectureValueMultiplier ?? 0.7f));
        var lotValue = saved.Field0x9C;
        var propertyValue = lotValue + furnishingsValue + architectureValue;
        var netWorth = funds + propertyValue;
        return new
        {
            today,
            threeDay,
            daysSinceMoveIn,
            objects = furnishingsValue,
            architecture = architectureValue,
            lotValue,
            propertyValue,
            netWorth,
        };
    }

    private void ResetLotValuationBaseline()
    {
        initialObjectValuation = SumPlacedObjectValues(world);
        initialValuationLot = lot;
        lotValuationEdited = false;
    }

    private (int FurnishingsValue, int ArchitectureValue) CurrentLotValuation(SimulationState saved) =>
        ComputeLotValuation(world, lot, initialObjectValuation, initialValuationLot, lotValuationEdited, saved);

    private (int FurnishingsValue, int ArchitectureValue) ComputeLotValuation(
        SimulationWorld? targetWorld,
        IffFile? targetLot,
        (int FurnishingsObjects, int ArchitectureObjects) baselineObjects,
        IffFile? baselineLot,
        bool edited,
        SimulationState saved)
    {
        var currentObjects = SumPlacedObjectValues(targetWorld);
        var furnishingsDelta = currentObjects.FurnishingsObjects - baselineObjects.FurnishingsObjects;
        var archObjectsDelta = currentObjects.ArchitectureObjects - baselineObjects.ArchitectureObjects;
        var archLayerDelta = (edited || (targetLot is not null && baselineLot is not null && !ReferenceEquals(targetLot, baselineLot)))
            && targetLot is not null && baselineLot is not null && !ReferenceEquals(targetLot, baselineLot)
            ? SumArchitectureLayerValue(targetLot) - SumArchitectureLayerValue(baselineLot)
            : 0;
        return (Math.Max(0, saved.Field0xA0 + furnishingsDelta),
                Math.Max(0, saved.Field0xA4 + archObjectsDelta + archLayerDelta));
    }

    private (int FurnishingsObjects, int ArchitectureObjects) SumPlacedObjectValues(SimulationWorld? target)
    {
        if (target is null) return (0, 0);
        var furnishings = 0;
        var architecture = 0;
        foreach (var item in target.Objects.Values)
        {
            if (item is XPerson || (item.Definition is { Length: > (int)ObjdField.Type } && item.Definition[(int)ObjdField.Type] == 7)) continue;
            if (item.MultiTileMasterId != 0 && item.MultiTileMasterId != item.Id) continue;
            if (item.Position.X < 0 || item.Position.Y < 0) continue;
            var buildMode = ObjectBuildModeType(item);
            if (buildMode == 0)
            {
                var movementFlags = unchecked((ushort)item[ObjectData.MovementFlags]);
                if ((movementFlags & 0x10) == 0 && (movementFlags & 0x08) != 0)
                    furnishings += target.ObjectSaleValue(item);
            }
            else if (buildMode != 4)
            {
                architecture += target.ObjectSaleValue(item);
            }
        }
        return (furnishings, architecture);
    }

    private static readonly System.Runtime.CompilerServices.ConditionalWeakTable<IffFile, System.Runtime.CompilerServices.StrongBox<int>> architectureLayerValueCache = new();

    private int SumArchitectureLayerValue(IffFile targetLot) =>
        architectureLayerValueCache.GetValue(targetLot, ComputeArchitectureLayerValue).Value;

    private System.Runtime.CompilerServices.StrongBox<int> ComputeArchitectureLayerValue(IffFile targetLot)
    {
        var floorsCatalog = floorCatalog ??= FloorCatalog.Open(game, language);
        var wallsCatalog = wallCatalogCache ??= WallCatalog.Open(game, language);
        var wallpaperCatalog = wallpaperCatalogCache ??= WallpaperCatalog.Open(game, language);
        var lotTiles = LotTiles.Read(targetLot);
        var pool = LotPool.Read(targetLot);
        var poolPrice = floorsCatalog.Contains(65535) ? floorsCatalog.Price(65535) : 0;
        var wallTotal = 0;
        var otherTotal = 0;
        var builtStoriesCount = LotTiles.BuiltStories(targetLot, world?.WalkOrder);
        for (var level = 1; level <= builtStoriesCount; level++)
        {
            var walls = LotWalls.Read(targetLot, level);
            var floors = LotFloors.Read(targetLot, level);
            for (var x = 0; x < LotWalls.Size; x++)
            for (var y = 0; y < LotWalls.Size; y++)
            {
                if (!lotTiles.InsideLot(x, y)) continue;
                var cell = walls[x, y];
                int StylePrice(int style) => style > 0 && wallsCatalog.Contains(style) ? wallsCatalog.Price(style) : 0;
                int PaperPrice(int style, int pattern) =>
                    style is 1 or 7 or 8 or 9 && pattern is > 0 and < 255 && wallpaperCatalog.Contains(pattern)
                        ? wallpaperCatalog.Price(pattern)
                        : 0;
                int SplitFloorHalfPrice(int pattern) =>
                    pattern is > 0 and < 255 && floorsCatalog.Contains(pattern) ? floorsCatalog.Price(pattern) / 2 : 0;

                var segments = cell[0];
                var style1 = (int)cell[2];
                var style2 = (int)cell[3];
                var style4 = x + 1 < LotWalls.Size ? (int)walls[x + 1, y][2] : 0;
                var style8 = y + 1 < LotWalls.Size ? (int)walls[x, y + 1][3] : 0;
                var styleDiag = (int)cell[3];
                var pattern1 = (int)cell[4];
                var pattern2 = (int)cell[5];
                var pattern8 = (int)cell[6];
                var pattern4 = (int)cell[7];

                if ((segments & 1) != 0) wallTotal += StylePrice(style1);
                if ((segments & 2) != 0) wallTotal += StylePrice(style2);
                if ((segments & 4) != 0) wallTotal += StylePrice(style4);
                if ((segments & 8) != 0) wallTotal += StylePrice(style8);
                if ((segments & 16) != 0) wallTotal += 2 * StylePrice(styleDiag);
                if ((segments & 32) != 0) wallTotal += 2 * StylePrice(styleDiag);

                if ((segments & 1) != 0) otherTotal += PaperPrice(style1, pattern1);
                if ((segments & 2) != 0) otherTotal += PaperPrice(style2, pattern2);
                if ((segments & 4) != 0) otherTotal += PaperPrice(style4, pattern4);
                if ((segments & 8) != 0) otherTotal += PaperPrice(style8, pattern8);
                if ((segments & 48) != 0)
                {
                    if (styleDiag == 255)
                    {
                        otherTotal += SplitFloorHalfPrice(cell[2]) + SplitFloorHalfPrice(cell[4]);
                    }
                    else
                    {
                        otherTotal += PaperPrice(styleDiag, pattern8) + PaperPrice(styleDiag, pattern4);
                    }
                }

                var floorPattern = floors[x, y];
                if (floorPattern is > 0 and < 65534 && floorsCatalog.Contains(floorPattern))
                    otherTotal += floorsCatalog.Price(floorPattern);
                if (level == 1 && pool.IsPool(x, y, 1))
                    otherTotal += poolPrice;
            }
        }
        return new System.Runtime.CompilerServices.StrongBox<int>(wallTotal / 2 + otherTotal);
    }

    private IReadOnlyList<string>? cachedRoofStyles;
    private IffFile? cachedRoofLot;
    private (string Style, float Pitch, int StyleIndex) cachedRoofInfo;

    private (string Style, float Pitch, int StyleIndex) RoofInfo(IffFile currentLot)
    {
        if (ReferenceEquals(cachedRoofLot, currentLot)) return cachedRoofInfo;
        var settings = LotRoof.Read(currentLot);
        var styles = cachedRoofStyles ??= LotRoof.Styles(game);
        var styleIndex = 0;
        for (var i = 0; i < styles.Count; i++)
        {
            if (string.Equals(styles[i], settings.Style, StringComparison.OrdinalIgnoreCase))
            {
                styleIndex = i;
                break;
            }
        }
        cachedRoofLot = currentLot;
        return cachedRoofInfo = (settings.Style, settings.Pitch, styleIndex);
    }

    private bool furnishingsCurveLoaded;
    private (float X, float Y)[]? cachedFurnishingsCurve;

    private (float X, float Y)[]? FurnishingsCurvePoints()
    {
        if (furnishingsCurveLoaded) return cachedFurnishingsCurve;
        furnishingsCurveLoaded = true;
        if (global?.Find(ResourceType.Str, 505) is not { } chunk) return null;
        var curves = StringTable.Read(global, chunk).ForLanguage(language);
        if (curves.Count < 2) return null;
        var points = new List<(float X, float Y)>();
        foreach (var token in curves[1].Split(' ', StringSplitOptions.RemoveEmptyEntries))
        {
            var pair = token.Trim('(', ')').Split(';');
            if (pair.Length != 2 || !float.TryParse(pair[0], System.Globalization.NumberStyles.Float,
                    System.Globalization.CultureInfo.InvariantCulture, out var x) ||
                !float.TryParse(pair[1], System.Globalization.NumberStyles.Float,
                    System.Globalization.CultureInfo.InvariantCulture, out var y)) return null;
            points.Add((x, y));
        }
        points.Sort((left, right) => left.X.CompareTo(right.X));
        return cachedFurnishingsCurve = points.Count == 0 ? null : points.ToArray();
    }

    private object[] Actions(XPerson person)
    {
        var queued = new List<object>();
        if (person.CurrentActionRecord is { Owner: not null, Secondary: not null } current)
            queued.Add(DescribeAction(current, person, true));
        var count = person.ActionQueueEnd - person.ActionQueueCurrent;
        if (count is >= 0 and <= 8)
        {
            for (var index = 0; index < count; index++)
            {
                var action = person.ActionQueue[(person.ActionQueueCurrent + index) & 7];
                if (action.Owner is not null && action.Secondary is not null) queued.Add(DescribeAction(action, person, false));
            }
        }
        return queued.ToArray();
    }

    private object DescribeAction(ActionQueueSlot action, XPerson person, bool active) => new
    {
        name = action.ActionText ?? action.Owner?.TypeRecord?.Interactions?.Interactions.FirstOrDefault(entry => entry.TtaIndex == action.RawDword10)?.Name ?? "",
        callee = action.Owner?.Id,
        token = $"native-{person.Id}-{action.Sequence}",
        active = active && person[PersonData.RoutingComplete] != 0,
        visible = true,
        cancellable = person[PersonData.Gender] < 2,
        cancelRequested = (action.Flags & 0x100) != 0 ||
            world!.InteractionLifecycle.InterruptRequested(person, action.Sequence) ||
            (active && person.ActiveActionCancelRequested),
        icon = images?.Icon(world!, action.Secondary) ?? images?.Icon(world!, action.Owner) ?? images?.Portrait(world!, person),
    };

    private int BuiltStories => lot is null ? 1 : LotTiles.BuiltStories(lot, world?.WalkOrder);

    private int BuildableStories
    {
        get
        {
            if (lot is not { } currentLot) return 1;
            var built = BuiltStories;
            if (built >= LotGeometry.MaxSupportedStories) return built;
            var tiles = EffectiveLotTiles(currentLot, world);
            return tiles.HasAnyBuildableTile(built + 1) ? built + 1 : built;
        }
    }

    private int Stories => viewerMode == 1 || (editingView && viewerMode == 0) ? BuildableStories : BuiltStories;

    private object HousePanel((int FurnishingsValue, int ArchitectureValue)? precomputedValuation = null)
    {
        var squareFeet = HouseSquareFeet();
        var roomCounts = HouseRoomCounts();
        var householdSize = 0;
        if (world is not null)
        {
            foreach (var item in world.WalkOrder)
                if (item is XPerson) householdSize++;
        }
        return new
        {
            squareFeet,
            bedrooms = roomCounts?.Bedrooms,
            bathrooms = roomCounts?.Bathrooms,
            lotSize = HouseLotSizeIndex(),
            sizeScore = squareFeet is null ? (int?)null : HouseSizeScore(squareFeet.Value, householdSize),
            furnishingsScore = HouseFurnishingsScore(precomputedValuation),
            yardScore = HouseYardScore(),
            upkeepScore = HouseUpkeepScore(),
            layoutScore = HouseLayoutScore(),
        };
    }

    private int? HouseFurnishingsScore((int FurnishingsValue, int ArchitectureValue)? precomputedValuation = null)
    {
        if (world?.SavedSimulationState is not { Version: >= 0x25 } saved || FurnishingsCurvePoints() is not { } points)
            return null;

        var (savedObjectsValue, savedArchitectureValue) = precomputedValuation ?? CurrentLotValuation(saved);
        var input = savedObjectsValue == 0 ? 100f : (float)savedArchitectureValue / savedObjectsValue;
        var curve = input < points[0].X
            ? points[0].Y
            : input >= points[^1].X
                ? points[^1].Y
                : Interpolate(points, input);
        return (int)Math.Round(Math.Clamp(curve, 0f, 100f), MidpointRounding.ToEven);

        static float Interpolate((float X, float Y)[] points, float value)
        {
            for (var index = points.Length - 2; index >= 0; index--)
            {
                var start = points[index];
                var end = points[index + 1];
                if (value < start.X) continue;
                var fraction = (value - start.X) / (end.X - start.X);
                return (1 - fraction) * start.Y + fraction * end.Y;
            }
            return points[0].Y;
        }
    }

    private int HouseLotSizeIndex() => house > 0x31 ? 2 : house > 0x27 ? 1 : 0;

    private (int Bedrooms, int Bathrooms)? HouseRoomCounts()
    {
        if (world is null || !world.RoomManagerRecordsLoaded || world.LotRoomMaps.Count == 0 ||
            world.LotRoomMaps.Values.Any(map => !map.HasAuthoritativeOutsideRooms) ||
            world.PersonRoomMotiveEntries.Values.Any(room => room.NeedsRefresh)) return null;

        var indoorRooms = world.PersonRoomMotiveEntries.Values.Where(room => !room.IsOutside);
        return (
            indoorRooms.Count(room => room.HouseCategory4ObjectCount58 > 0),
            indoorRooms.Count(room => room.HouseCategory5To7ObjectCount5c > 0));
    }

    private int? HouseSquareFeet()
    {
        if (world is null || world.LotRoomMaps.Count == 0 || world.LotRoomMaps.Values.Any(map => !map.HasAuthoritativeOutsideRooms)) return null;
        var tiles = 0;
        foreach (var map in world.LotRoomMaps.Values)
        foreach (var room in map.RoomIds)
            if (!map.IsOutside(room)) tiles += map.TilesInRoom(room).Count();
        return checked(tiles * 9);
    }

    private int? HouseYardScore()
    {
        if (world is null || !world.RoomManagerRecordsLoaded || !float.IsFinite(world.HouseYardScoreMultiplier) || world.LotRoomMaps.Count == 0 ||
            world.LotRoomMaps.Values.Any(map => !map.HasAuthoritativeOutsideRooms) ||
            world.PersonRoomMotiveEntries.Values.Any(room => room.NeedsRefresh)) return null;
        var score = world.PersonRoomMotiveEntries.Values.Where(room => room.IsOutside).Sum(room => room.InteriorValue) * world.HouseYardScoreMultiplier;
        return float.IsFinite(score) ? (int)Math.Round(Math.Clamp(score, 0f, 100f), MidpointRounding.ToEven) : null;
    }

    private int? HouseUpkeepScore()
    {
        if (world is null) return null;
        var count = 0;
        var penalty = 0;
        foreach (var item in world.WalkOrder)
        {
            if (item.Definition[(int)ObjdField.RoomSort] == 0 &&
                item.Definition[(int)ObjdField.FunctionSort] == 0 &&
                item.Definition[(int)ObjdField.BuildModeType] == 0) continue;

            count++;
            if (item[ObjectData.RepairState] != 0)
                penalty += world.HouseUpkeepPenaltyPerBrokenObject;
            else if (item[ObjectData.DirtyLevel] > 0)
                penalty += world.HouseUpkeepPenaltyPerDirtyObject;
        }
        if (count == 0) return 0;
        var ratio = Math.Clamp((count - penalty) / (float)count, 0f, 1f);
        return (int)Math.Round(ratio * 100f, MidpointRounding.ToEven);
    }

    private int? HouseLayoutScore()
    {
        if (world is null || lot is null) return null;
        return HouseLayoutHistory.Read(lot, world.HouseLayoutHistoryFillValue)?.Score;
    }

    private static int HouseSizeScore(int squareFeet, int householdSize)
    {
        if (householdSize == 0) return 0;
        var areaPerMember = (double)squareFeet / householdSize;
        if (areaPerMember <= 0) return 0;
        if (areaPerMember >= 1200) return 100;
        var (start, end) = areaPerMember switch
        {
            < 150 => (0d, 150d),
            < 300 => (150d, 300d),
            < 600 => (300d, 600d),
            _ => (600d, 1200d),
        };
        var score = areaPerMember switch
        {
            < 150 => 0d,
            < 300 => 25d,
            < 600 => 50d,
            _ => 75d,
        };
        return (int)Math.Round(score + (areaPerMember - start) / (end - start) * 25d, MidpointRounding.ToEven);
    }

    private int LotWidth => world is null ? 64 : LotGeometry.LotDimension;
    private int LotHeight => world is null ? 64 : LotGeometry.LotDimension;

    private IffFile? buildableLot;
    private int buildableUpperLevel;
    private LotTiles? cachedEffectiveTiles;
    private bool[]? buildableMask;
    private bool[]? buildableLevel2Mask;

    private LotTiles EffectiveLotTiles(IffFile currentLot, SimulationWorld? activeWorld)
    {
        if (ReferenceEquals(buildableLot, currentLot) && cachedEffectiveTiles is not null)
            return cachedEffectiveTiles;
        var refreshed = LotTiles.RefreshStructuralFlags(currentLot, activeWorld?.WalkOrder);
        var tiles = LotTiles.Read(refreshed);
        buildableLot = currentLot;
        cachedEffectiveTiles = tiles;
        buildableMask = null;
        buildableLevel2Mask = null;
        return tiles;
    }

    private bool[] Buildable()
    {
        if (lot is not { } currentLot) return Enumerable.Repeat(true, LotWidth * LotHeight).ToArray();
        var tiles = EffectiveLotTiles(currentLot, world);
        if (buildableMask is not null) return buildableMask;
        var mask = new bool[LotWidth * LotHeight];
        for (var y = 0; y < LotHeight; y++)
            for (var x = 0; x < LotWidth; x++)
                mask[y * LotWidth + x] = tiles.InsideLot(x, y) && tiles.Buildable(x, y, 1);
        return buildableMask = mask;
    }

    private bool[] BuildableLevel2()
    {
        if (lot is not { } currentLot) return new bool[LotWidth * LotHeight];
        var targetLevel = Math.Clamp(Math.Max(2, viewLevel), 2, LotGeometry.MaxSupportedStories);
        var tiles = EffectiveLotTiles(currentLot, world);
        if (buildableLevel2Mask is not null && buildableUpperLevel == targetLevel)
            return buildableLevel2Mask;
        var mask = new bool[LotWidth * LotHeight];
        for (var y = 0; y < LotHeight; y++)
            for (var x = 0; x < LotWidth; x++)
                mask[y * LotWidth + x] = tiles.InsideLot(x, y) && tiles.Buildable(x, y, targetLevel);
        buildableUpperLevel = targetLevel;
        return buildableLevel2Mask = mask;
    }

    private IffFile? stateFloorsLot;
    private int stateFloorsLevel;
    private int[]? stateFloorsCache;

    private int[] StateFloors()
    {
        if (lot is not { } currentLot) return new int[LotWidth * LotHeight];
        var level = Math.Clamp(viewLevel, 1, LotGeometry.MaxSupportedStories);
        if (ReferenceEquals(stateFloorsLot, currentLot) && stateFloorsLevel == level && stateFloorsCache is not null)
            return stateFloorsCache;
        var result = new int[LotWidth * LotHeight];
        try
        {
            var floors = LotFloors.Read(currentLot, level);
            var pool = level == 1 ? LotPool.Read(currentLot) : null;
            var water = level == 1 ? LotWater.Read(currentLot) : null;
            for (var y = 0; y < LotHeight; y++)
            for (var x = 0; x < LotWidth; x++)
            {
                if (x >= LotFloors.Size || y >= LotFloors.Size) continue;
                int pattern = floors[x, y];
                if (pattern == byte.MaxValue) pattern = 0;
                if (pool is not null && pool.IsPool(x, y, 1)) pattern = 65535;
                else if (water is not null && water.IsWater(x, y, 1)) pattern = 65534;
                result[y * LotWidth + x] = pattern;
            }
        }
        catch { }
        stateFloorsLot = currentLot;
        stateFloorsLevel = level;
        return stateFloorsCache = result;
    }

    private IffFile? stateWallsLot;
    private int stateWallsLevel;
    private object[]? stateWallsCache;

    private object[] StateWalls()
    {
        if (lot is not { } currentLot)
            return Enumerable.Repeat((object)new { segments = (byte)0, topLeftStyle = 0, topRightStyle = 0, topLeftPattern = 0, topRightPattern = 0, bottomLeftPattern = 0, bottomRightPattern = 0 }, LotWidth * LotHeight).ToArray();
        var level = Math.Clamp(viewLevel, 1, LotGeometry.MaxSupportedStories);
        if (ReferenceEquals(stateWallsLot, currentLot) && stateWallsLevel == level && stateWallsCache is not null)
            return stateWallsCache;
        var result = new object[LotWidth * LotHeight];
        try
        {
            var walls = LotWalls.Read(currentLot, level);
            for (var y = 0; y < LotHeight; y++)
            for (var x = 0; x < LotWidth; x++)
            {
                if (x >= LotWalls.Size || y >= LotWalls.Size)
                {
                    result[y * LotWidth + x] = new { segments = (byte)0, topLeftStyle = 0, topRightStyle = 0, topLeftPattern = 0, topRightPattern = 0, bottomLeftPattern = 0, bottomRightPattern = 0 };
                    continue;
                }
                var cell = walls[x, y];
                result[y * LotWidth + x] = new
                {
                    segments = cell[0],
                    topLeftStyle = (int)cell[2],
                    topRightStyle = (int)cell[3],
                    topLeftPattern = (int)cell[4],
                    topRightPattern = (int)cell[5],
                    bottomLeftPattern = (int)cell[6],
                    bottomRightPattern = (int)cell[7],
                };
            }
        }
        catch
        {
            for (var i = 0; i < result.Length; i++)
                result[i] ??= new { segments = (byte)0, topLeftStyle = 0, topRightStyle = 0, topLeftPattern = 0, topRightPattern = 0, bottomLeftPattern = 0, bottomRightPattern = 0 };
        }
        stateWallsLot = currentLot;
        stateWallsLevel = level;
        return stateWallsCache = result;
    }

    private string Export()
    {
        if (world is not null && !ReferenceEquals(notifiedPluginWorld, world))
        {
            notifiedPluginWorld = world;
            plugins?.NotifyWorldLoaded();
        }
        revision++;
        animationSequence = 0;
        exportedCutawaySimKey = CutawaySimKey();
        var spriteModifier = plugins?.ActiveSpriteModifier;
        exportedSpriteVariant = spriteModifier?.SpriteVariant ?? 0;
        var sceneDirectory = SceneDirectory;
        var scenePath = world is not null && lot is not null && registry is not null
            ? SceneExporter.Export(lot, world, registry, game, sceneDirectory, house, revision, viewLevel, wallMode, cameraOrientation, cutawayTile, roofsVisible, animationState, cutawayRooms, cutawaySim: CutawaySimTile(), cutawayZoom: cutawayZoom, showLoweredPortals: doorWindowBuildToolActive, raiseHoveredWalls: wallpaperBuildToolActive, updates: updates, spriteModifier: spriteModifier, storiesOverride: Stories)
            : PlaceholderScene();
        Write(new { type = "frame", revision, scene = scenePath, state = State() });
        return scenePath;
    }

    private void RefreshDynamicOrExport()
    {
        if (streaming && world is not null && lot is not null && registry is not null &&
            animationState.Kept is not null && animationState.Revision == revision &&
            SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: wallpaperBuildToolActive))
        {
            exportedCutawaySimKey = CutawaySimKey();
            var refreshAlpha = speed > 0 ? lastSubTickAlpha : 0f;
            if (DirectAnimationSink is { } directSink)
            {
                if (SceneExporter.AnimationDirect(lot, world, registry, game, SceneDirectory, house, revision, animationState,
                        ++animationSequence, updates, viewLevel, wallMode, cameraOrientation, cutawayTile, roofsVisible,
                        cutawayRooms: cutawayRooms, cutawaySim: CutawaySimTile(), cutawayZoom: cutawayZoom,
                        showLoweredPortals: doorWindowBuildToolActive, subTickAlpha: refreshAlpha, raiseHoveredWalls: wallpaperBuildToolActive) is { } directFrame)
                    directSink(directFrame);
            }
            else if (SceneExporter.Animation(lot, world, registry, game, SceneDirectory, house, revision, animationState,
                    ++animationSequence, updates, viewLevel, wallMode, cameraOrientation, cutawayTile, roofsVisible,
                    cutawayRooms: cutawayRooms, cutawaySim: CutawaySimTile(), cutawayZoom: cutawayZoom,
                    showLoweredPortals: doorWindowBuildToolActive, subTickAlpha: refreshAlpha, raiseHoveredWalls: wallpaperBuildToolActive) is { } frame)
            {
                Write(new { type = "animation", frame });
            }
            return;
        }
        Export();
    }

    private (int X, int Y)? CutawaySimTile()
    {
        if (wallMode != "cutaway" || editingView || world?.ObjectById(selectedSim) is not XPerson person) return null;
        if (person.Position.Height != viewLevel || person.Position.X < 0 || person.Position.Y < 0) return null;
        return (person.Position.X >> 4, person.Position.Y >> 4);
    }

    private long CutawaySimKey()
    {
        if (CutawaySimTile() is not { } tile || world is null || !world.LotRoomMaps.TryGetValue(viewLevel, out var map) ||
            tile.X >= map.Width || tile.Y >= map.Height) return -1;
        var room = map.RoomAt(tile.X, tile.Y);
        return map.IsOutside(room) ? ((long)tile.X << 40) | ((long)tile.Y << 20) | room : room;
    }

    private void InitializeViewLevelFromSelectedSim()
    {
        if (world is null)
        {
            viewLevel = 1;
            return;
        }

        var level = (world.ObjectById(selectedSim) as XPerson)?.Position.Height ?? 1;
        viewLevel = Math.Clamp(level, 1, Math.Max(1, Stories));
    }

    private void ApplyCutawayTarget(JsonElement request)
    {
        if (request.TryGetProperty("zoom", out var zoomValue) && zoomValue.ValueKind == JsonValueKind.Number && zoomValue.TryGetInt32(out var requestedZoom))
        {
            cutawayZoom = Math.Clamp(requestedZoom, 1, 3);
        }
        if (request.TryGetProperty("wallpaperTool", out var wtValue) && wtValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
        {
            wallpaperBuildToolActive = editingView && wtValue.GetBoolean();
        }
        var cutawayX = TileCoordinate(request, "x");
        var cutawayY = TileCoordinate(request, "y");
        if (cutawayX < 0 || cutawayY < 0) ClearCutaway();
        else if (cutawayX >= LotWidth || cutawayY >= LotHeight) throw new ArgumentException("Cutaway tile is outside the lot.");
        else
        {
            cutawayTile = (cutawayX, cutawayY);
            if (world is not null && world.LotRoomMaps.TryGetValue(viewLevel, out var roomMap) &&
                cutawayX < roomMap.Width && cutawayY < roomMap.Height)
            {
                var cutawayCamera = new LotCamera(cameraOrientation, LotWidth, LotHeight);
                var hoveredRoom = roomMap.RoomAt(cutawayX, cutawayY);
                if (hoveredRoom != RoomMap.NoRoom &&
                    (!wallpaperBuildToolActive || !roomMap.IsOutside(hoveredRoom)) &&
                    !cutawayRooms.Contains(hoveredRoom))
                {
                    cutawayRooms.Add(hoveredRoom);
                    if (cutawayRooms.Count > 3) cutawayRooms.RemoveAt(0);
                }
                if (!wallpaperBuildToolActive)
                {
                    var probeRoom = SceneExporter.CutawayProbeRoom(roomMap, cutawayCamera, LotWidth, cutawayX, cutawayY, cutawayZoom);
                    if (probeRoom != RoomMap.NoRoom && !cutawayRooms.Contains(probeRoom))
                    {
                        cutawayRooms.Add(probeRoom);
                        if (cutawayRooms.Count > 3) cutawayRooms.RemoveAt(0);
                    }
                }
            }
        }
    }

    private void ClearCutaway()
    {
        cutawayTile = null;
        cutawayRooms.Clear();
    }

    private string PlaceholderScene()
    {
        var sceneDir = SceneDirectory;
        Directory.CreateDirectory(sceneDir);
        var scenePath = Path.Combine(sceneDir, $"scene-{revision}.json");
        var scene = new
        {
            schemaVersion = 1,
            house,
            width = LotWidth * 16f,
            height = LotHeight * 16f,
            cameraOrientation,
            wallMode,
            wallsUp = wallMode == "up",
            viewLevel = 1,
            stories = 1,
            textures = Array.Empty<object>(),
            sprites = Array.Empty<object>(),
            meshes = Array.Empty<object>(),
            limitations = new[] { "native engine placeholder scene" },
        };
        File.WriteAllText(scenePath, JsonSerializer.Serialize(scene, Json));
        return scenePath;
    }

    private void Write(object message)
    {
        if (output is StreamWriter streamWriter && streamWriter.Encoding.CodePage == 65001)
        {
            streamWriter.Flush();
            JsonSerializer.Serialize(streamWriter.BaseStream, message, Json);
            streamWriter.BaseStream.WriteByte((byte)'\n');
            streamWriter.BaseStream.Flush();
            return;
        }
        output.WriteLine(JsonSerializer.Serialize(message, Json));
        output.Flush();
    }
}
