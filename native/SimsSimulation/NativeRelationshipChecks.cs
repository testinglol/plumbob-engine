using System.Buffers.Binary;
using System.Reflection;
using System.Security.Cryptography;
using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Engine.Scopes;
using FSO.SimAntics.Engine.Utils;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;

internal static class NativeRelationshipChecks
{
    internal static object Run(VM vm, string workspace, string profile, string game, short home)
    {
        var directory = Path.Combine(workspace, "runtime", "native-sessions", "relationships-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(directory);
        using var output = new StreamWriter(Path.Combine(directory, "events.jsonl")) { AutoFlush = true };
        var server = new SimulationServer(vm, output, directory, profile, game, home);
        var neighborhood = Content.Get().Neighborhood;
        var originalFile = Path.Combine(game, "UserData", "Neighborhood.iff");
        var originalHash = SHA256.HashData(File.ReadAllBytes(originalFile));
        const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
        object? Invoke(string method, params object[] args) => typeof(SimulationServer).GetMethod(method, flags)!.Invoke(server, args);
        int checks = 0;
        void Require(bool condition, string message) { if (!condition) throw new InvalidDataException(message); checks++; }
        var avatar = vm.Entities.OfType<VMAvatar>().First(entity => entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == vm.TS1State.CurrentFamily.ChunkID);
        var caller = avatar.GetPersonData(VMPersonDataVariable.NeighborId);
        var residentIDs = vm.Entities.OfType<VMAvatar>().Select(entity => entity.GetPersonData(VMPersonDataVariable.NeighborId)).ToHashSet();
        var targets = neighborhood.Neighbors.NeighbourByID.Values.Where(neighbor => neighbor.NeighbourID > 0 && !residentIDs.Contains(neighbor.NeighbourID)).Take(32).ToArray();
        Require(targets.Length > 1, "Neighborhood fixture has no off-lot relationship targets");
        foreach (var target in targets)
        {
            var frame = new VMStackFrame { Caller = avatar, Callee = avatar, CodeOwner = avatar.Object, Thread = avatar.Thread, StackObjectID = target.NeighbourID };
            foreach (var value in new[] { (Index: (byte)0, Value: (short)37), (Index: (byte)2, Value: (short)-24), (Index: (byte)7, Value: (short)83) })
            {
                Require(new VMRelationship().Execute(frame, new VMRelationshipOperand { UseNeighbor = true, Mode = 0, RelVar = value.Index,
                    SetMode = 1, VarScope = VMVariableScope.Literal, VarData = value.Value }) == VMPrimitiveExitCode.GOTO_TRUE,
                    "Original relationship primitive failed with an off-lot target");
                Require(neighborhood.GetNeighborByID(caller).Relationships[target.NeighbourID][value.Index] == value.Value,
                    "Original primitive did not update the canonical neighborhood matrix");
            }
            Require(new VMRelationship().Execute(frame, new VMRelationshipOperand { UseNeighbor = true, Mode = 1, RelVar = 0,
                SetMode = 1, VarScope = VMVariableScope.Literal, VarData = -61 }) == VMPrimitiveExitCode.GOTO_TRUE,
                "Original reverse relationship primitive failed");
            Require(target.Relationships[caller][0] == -61 && neighborhood.GetNeighborByID(caller).Relationships[target.NeighbourID][0] == 37,
                "Relationship direction was lost");
        }
        var images = new PanelResources(directory);
        var exported = NativeRelationships.Read(vm, avatar, images);
        foreach (var target in targets)
        {
            var relationship = exported.Single(item => item.NeighborID == target.NeighbourID);
            Require(relationship.Values[0] == 37 && relationship.Values[2] == -24 && relationship.Values[7] == 83 && relationship.GUID == target.GUID && !relationship.Household && relationship.ReverseDaily == -61,
                "Native export changed raw relationship data or required a spawned target");
        }
        var extendedTargets = targets.Where(target => target.PersonData?.Length == 256).ToArray();
        var generatedModernRecord = extendedTargets.Length == 0;
        if (generatedModernRecord)
        {
            var modern = targets.First(target => target.PersonData != null);
            Array.Resize(ref modern.PersonData, 256);
            modern.Version = 0xA;
            extendedTargets = new[] { modern };
        }
        foreach (var target in extendedTargets)
        {
            target.PersonData[88] = short.MinValue;
            target.PersonData[255] = short.MaxValue;
            var frame = new VMStackFrame { Caller = avatar, Callee = avatar, CodeOwner = avatar.Object, Thread = avatar.Thread, StackObjectID = target.NeighbourID };
            Require(VMMemory.GetVariable(frame, VMVariableScope.NeighborPersonData, 88) == short.MinValue &&
                VMMemory.GetVariable(frame, VMVariableScope.NeighborPersonData, 255) == short.MaxValue,
                "Original neighbor variable scope lost extended person-data fields");
        }
        var before = NativeNeighborhoodState.Save();
        var activeCount = neighborhood.Neighbors.NeighbourByID.Count;
        neighborhood.Neighbors.Entries.Add(new Neighbour { Unknown1 = 0 });
        Require(NativeNeighborhoodState.Decode(NativeNeighborhoodState.Save()).Entries.Count == activeCount,
            "Unoccupied neighbor slots corrupted the serialized count");
        NativeNeighborhoodState.Restore(before);
        var typeGuid = (avatar.MasterDefinition ?? avatar.Object.OBJ).TypeAttrGUID;
        neighborhood.TypeAttributes.TypeAttributesByGUID[typeGuid] = new short[32];
        var typeFrame = new VMStackFrame { Caller = avatar, Callee = avatar, CodeOwner = avatar.Object, Thread = avatar.Thread, StackObjectID = avatar.ObjectID };
        Require(VMMemory.SetVariable(typeFrame, VMVariableScope.MyTypeAttr, 0, short.MinValue) &&
            VMMemory.SetVariable(typeFrame, VMVariableScope.StackObjectTypeAttr, 31, short.MaxValue),
            "Type-attribute scopes failed to write canonical neighborhood data");
        var typeAttributesBefore = NativeNeighborhoodState.SaveTypeAttributes();
        var duplicateAttributesRejected = false;
        try { NativeNeighborhoodState.ValidateTypeAttributes(new[] { typeAttributesBefore[0], typeAttributesBefore[0] }); }
        catch (InvalidDataException) { duplicateAttributesRejected = true; }
        Require(duplicateAttributesRejected, "Duplicate type-attribute identities were accepted");
        var slot = "relationships-" + Guid.NewGuid().ToString("N");
        var saveFile = Path.Combine(profile, "Saves", slot + ".json");
        try
        {
            Invoke("Save", slot);
            neighborhood.TypeAttributes.TypeAttributesByGUID.Clear();
            neighborhood.GetNeighborByID(caller).Relationships.Clear();
            foreach (var target in targets)
            {
                var changed = neighborhood.GetNeighborByID(target.NeighbourID);
                changed.Relationships.Clear();
                if (changed.PersonData != null) changed.PersonData[46] = 901;
                if (changed.PersonData?.Length == 256) { changed.PersonData[88] = 0; changed.PersonData[255] = 0; }
            }
            Invoke("Load", slot);
            Require(NativeNeighborhoodState.Save() == before, "Native save/load lost social or off-lot person data");
            Require(ReferenceEquals(neighborhood.Neighbors, neighborhood.MainResource.Get<NBRS>(1)), "Restore replaced the provider's canonical chunk identity");
            Require(VMMemory.GetVariable(typeFrame, VMVariableScope.MyTypeAttr, 0) == short.MinValue &&
                VMMemory.GetVariable(typeFrame, VMVariableScope.StackObjectTypeAttr, 31) == short.MaxValue,
                "Native save/load lost shared object type attributes");
            Require(ReferenceEquals(neighborhood.TypeAttributes, neighborhood.MainResource.List<TATT>().FirstOrDefault()), "Restore replaced the canonical type-attribute chunk");
            Require(NativeNeighborhoodState.SaveTypeAttributes().Zip(typeAttributesBefore).All(pair =>
                pair.First.GUID == pair.Second.GUID && pair.First.Values.SequenceEqual(pair.Second.Values)) &&
                neighborhood.TypeAttributes.TypeAttributesByGUID.Count == typeAttributesBefore.Length, "Native save/load changed type-attribute records");
        }
        finally { File.Delete(saveFile); }
        var truncated = Convert.FromBase64String(before);
        BinaryPrimitives.WriteUInt32LittleEndian(truncated.AsSpan(12, 4), (uint)activeCount + 1);
        bool rejected = false;
        try { NativeNeighborhoodState.Decode(Convert.ToBase64String(truncated)); } catch (InvalidDataException) { rejected = true; }
        Require(rejected, "Truncated neighborhood record count was accepted");
        Require(originalHash.SequenceEqual(SHA256.HashData(File.ReadAllBytes(originalFile))), "Checks modified original neighborhood data");
        return new { checks, offLotTargets = targets.Length, directionalRelationships = true, rawValuesPreserved = true,
            neighborhoodSaveLoad = true, typeAttributeSaveLoad = true, extendedPersonDataRecords = extendedTargets.Length, generatedModernRecord,
            originalDataModified = false, session = directory, livePresentationVerified = false };
    }
}
