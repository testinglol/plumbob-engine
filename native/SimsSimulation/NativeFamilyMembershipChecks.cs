using System.Reflection;
using System.Security.Cryptography;
using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.LotView.Model;
using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;

internal static class NativeFamilyMembershipChecks
{
    public static object Run(VM vm, string workspace, string profile, string game, short house)
    {
        var family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Family membership check has no active family");
        if (family.FamilyGUIDs.Length >= 8) throw new InvalidDataException("Family membership check requires a household with a free member slot");
        var resident = vm.Entities.OfType<VMAvatar>().FirstOrDefault(avatar =>
            avatar.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID)
            ?? throw new InvalidDataException("Family membership check has no resident Sim");
        var neighborhood = Content.Get().Neighborhood;
        var originalNeighborhoodPath = Path.Combine(game, "UserData", "Neighborhood.iff");
        var originalHousePath = Path.Combine(game, "UserData", "Houses", $"House{house:D2}.iff");
        var originalNeighborhoodHash = SHA256.HashData(File.ReadAllBytes(originalNeighborhoodPath));
        var originalHouseHash = SHA256.HashData(File.ReadAllBytes(originalHousePath));
        var candidate = neighborhood.Neighbors.NeighbourByID.Values.FirstOrDefault(neighbor =>
            neighbor.PersonData != null &&
            neighbor.PersonData[(int)VMPersonDataVariable.TS1FamilyNumber] == 0 &&
            !family.FamilyGUIDs.Contains(neighbor.GUID) &&
            Content.Get().WorldObjects.Get(neighbor.GUID)?.OBJ.ObjectType == OBJDType.Person)
            ?? throw new InvalidDataException("Family membership check has no unassigned neighborhood Sim");
        var member = vm.Context.CreateObjectInstance(candidate.GUID, LotTilePos.OUT_OF_WORLD, Direction.NORTH).BaseObject as VMAvatar
            ?? throw new InvalidDataException("Family membership check could not instantiate its neighborhood Sim");
        var memberID = member.GetPersonData(VMPersonDataVariable.NeighborId);
        if (memberID != candidate.NeighbourID)
            throw new InvalidDataException("Newly instantiated Sim did not inherit its neighborhood identity");

        var session = Path.Combine(workspace, "runtime", "native-sessions", "family-membership-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(session);
        using var output = new StreamWriter(Path.Combine(session, "events.jsonl")) { AutoFlush = true };
        var server = new SimulationServer(vm, output, session, profile, game, house);
        const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
        object? Invoke(string method, params object[] args) => NativeServerReflection.Invoke(server, method, args);

        ExecuteMembershipCall(vm, resident, memberID, VMGenericTS1CallMode.AddToFamily);
        Require(family.FamilyGUIDs.Count(guid => guid == candidate.GUID) == 1,
            "Add-to-family did not add exactly one family roster entry");
        Require(family.RuntimeSubset.Count(guid => guid == candidate.GUID) == 1,
            "Add-to-family did not add exactly one active runtime member");
        Require(candidate.PersonData[(int)VMPersonDataVariable.TS1FamilyNumber] == family.ChunkID &&
            member.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID,
            "Add-to-family did not update canonical and runtime family identifiers");

        var neighborhoodBeforeSave = NativeNeighborhoodState.Save();
        var saveSlot = "family-membership-" + Guid.NewGuid().ToString("N");
        var savePath = Path.Combine(profile, "Saves", saveSlot + ".json");
        try
        {
            Invoke("Save", saveSlot);
            family.FamilyGUIDs = family.FamilyGUIDs.Where(guid => guid != candidate.GUID).ToArray();
            family.RuntimeSubset = family.RuntimeSubset.Where(guid => guid != candidate.GUID).ToArray();
            candidate.PersonData[(int)VMPersonDataVariable.TS1FamilyNumber] = 0;
            member.SetPersonData(VMPersonDataVariable.TS1FamilyNumber, 0);
            Invoke("Load", saveSlot);

            family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Native reload lost the active household");
            candidate = neighborhood.GetNeighborByID(memberID) ?? throw new InvalidDataException("Native reload lost the neighborhood Sim");
            member = vm.Entities.OfType<VMAvatar>().FirstOrDefault(avatar =>
                avatar.GetPersonData(VMPersonDataVariable.NeighborId) == memberID)
                ?? throw new InvalidDataException("Native reload lost the newly added household Sim");
            Require(family.FamilyGUIDs.Count(guid => guid == candidate.GUID) == 1 &&
                family.RuntimeSubset.Count(guid => guid == candidate.GUID) == 1,
                "Native save/load did not preserve the family roster and active runtime member");
            Require(candidate.PersonData?[(int)VMPersonDataVariable.TS1FamilyNumber] == family.ChunkID &&
                member.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID,
                "Native save/load did not preserve the member's canonical and runtime family identifiers");
            Require(NativeNeighborhoodState.Save() == neighborhoodBeforeSave,
                "Native save/load did not restore the neighborhood member record");

            ExecuteMembershipCall(vm, member, memberID, VMGenericTS1CallMode.RemoveFromFamily);
            Require(!family.FamilyGUIDs.Contains(candidate.GUID),
                "Remove-from-family left the Sim on the family roster");
            Require(!family.RuntimeSubset.Contains(candidate.GUID),
                "Remove-from-family left the Sim in the active runtime household");
            Require(candidate.PersonData?[(int)VMPersonDataVariable.TS1FamilyNumber] == 0 &&
                member.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == 0,
                "Remove-from-family did not clear canonical and runtime family identifiers");
        }
        finally
        {
            if (File.Exists(savePath)) File.Delete(savePath);
        }
        if (!originalNeighborhoodHash.SequenceEqual(SHA256.HashData(File.ReadAllBytes(originalNeighborhoodPath))) ||
            !originalHouseHash.SequenceEqual(SHA256.HashData(File.ReadAllBytes(originalHousePath))))
            throw new InvalidDataException("Family membership check modified the original neighborhood or household file");

        return new
        {
            family = family.ChunkID,
            member = candidate.Name,
            memberNeighborId = memberID,
            addedToRoster = true,
            saveLoadPreservedMembership = true,
            removedFromRoster = true,
            removedFromRuntimeSubset = true,
            originalDataModified = false,
            session
        };
    }

    private static void ExecuteMembershipCall(VM vm, VMAvatar caller, short neighborId, VMGenericTS1CallMode call)
    {
        var frame = new VMStackFrame
        {
            Caller = caller,
            Callee = caller,
            CodeOwner = caller.Object,
            Thread = caller.Thread,
            StackObjectID = neighborId
        };
        if (new VMGenericTS1Call().Execute(frame, new VMGenericTS1CallOperand { Call = call }) != VMPrimitiveExitCode.GOTO_TRUE)
            throw new InvalidDataException($"Original {call} primitive did not report success");
    }

    private static void Require(bool condition, string message)
    {
        if (!condition) throw new InvalidDataException(message);
    }
}
