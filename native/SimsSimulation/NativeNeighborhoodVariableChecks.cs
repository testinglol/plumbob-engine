using System.Security.Cryptography;
using FSO.Content;
using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Engine.Scopes;
using FSO.SimAntics.Engine.Utils;
using FSO.SimAntics.Model;

internal static class NativeNeighborhoodVariableChecks
{
    internal static object Run(VM vm)
    {
        var neighborhood = Content.Get().Neighborhood;
        var nhoodValues = neighborhood.Neighborhood.NeighborhoodData;
        var nhoodBefore = (short[])nhoodValues.Clone();
        var nhoodFile = Path.Combine(neighborhood.UserPath, "Neighborhood.iff");
        var originalHash = SHA256.HashData(File.ReadAllBytes(nhoodFile));
        var avatar = vm.Entities.OfType<VMAvatar>().First(entity => entity.Thread != null);
        var neighbor = neighborhood.Neighbors.NeighbourByID.Values.FirstOrDefault(item => item.PersonData?.Length > 0);
        var personBefore = neighbor?.PersonData == null ? null : (short[])neighbor.PersonData.Clone();
        var frame = new VMStackFrame { Caller = avatar, Callee = avatar, CodeOwner = avatar.Object, Thread = avatar.Thread,
            StackObjectID = neighbor?.NeighbourID ?? 0 };
        var wasTs1 = vm.TS1;
        var checks = 0;
        void Require(bool condition, string message)
        {
            if (!condition) throw new InvalidDataException(message);
            checks++;
        }
        bool ThrowsForScope(VMVariableScope scope, short index)
        {
            try { VMMemory.GetVariable(frame, scope, index); }
            catch (VMSimanticsException) { return true; }
            return false;
        }

        try
        {
            Require(nhoodValues.Length == 16, "NGBH neighborhood data does not have 16 records");
            for (short index = 1; index < nhoodValues.Length; index++)
                Require(VMMemory.GetVariable(frame, VMVariableScope.NeighborhoodData, index) == nhoodBefore[index], "Neighborhood data getter differs from NGBH");
            Require(!VMMemory.SetVariable(frame, VMVariableScope.NeighborhoodData, 1, 173), "Neighborhood data scope unexpectedly allowed a write");
            Require(nhoodValues.SequenceEqual(nhoodBefore), "Neighborhood data scope changed NGBH");
            Require(ThrowsForScope(VMVariableScope.NeighborhoodData, 0) && ThrowsForScope(VMVariableScope.NeighborhoodData, 16), "Neighborhood data accepted an invalid index");
            foreach (var readOnlyScope in new[] { VMVariableScope.StackObjectSlot, VMVariableScope.MySlot, VMVariableScope.RoomByTemp0,
                VMVariableScope.NeighborInStackObject, VMVariableScope.JobData })
                Require(!VMMemory.SetVariable(frame, readOnlyScope, 0, 173), $"Read-only scope {readOnlyScope} unexpectedly allowed a write");

            Require(neighbor?.PersonData != null, "Neighborhood fixture contains no neighbor person data");
            var personIndex = (short)(neighbor!.PersonData!.Length - 1);
            Require(VMMemory.GetVariable(frame, VMVariableScope.NeighborPersonData, personIndex) == personBefore![personIndex], "Neighbor person data getter differs from NBRS");
            neighbor.PersonData = null;
            Require(VMMemory.GetVariable(frame, VMVariableScope.NeighborPersonData, 0) == 0, "Neighbor without serialized person data did not read as zero");
            neighbor.PersonData = personBefore;
            var originalNeighborId = frame.StackObjectID;
            frame.StackObjectID = short.MaxValue;
            Require(ThrowsForScope(VMVariableScope.NeighborPersonData, 0), "Missing neighborhood record did not fail its person-data lookup");
            frame.StackObjectID = originalNeighborId;
            Require(!VMMemory.SetVariable(frame, VMVariableScope.NeighborPersonData, personIndex, -173), "Neighbor person data scope unexpectedly allowed a write");
            Require(neighbor.PersonData.SequenceEqual(personBefore), "Neighbor person data scope changed NBRS");
            Require(ThrowsForScope(VMVariableScope.NeighborPersonData, -1), "Neighbor person data accepted a negative index");
            Require(ThrowsForScope(VMVariableScope.NeighborPersonData, short.MaxValue), "Neighbor person data accepted an out-of-range index");

            vm.TS1 = false;
            Require(ThrowsForScope(VMVariableScope.NeighborhoodData, 0) && ThrowsForScope(VMVariableScope.NeighborPersonData, 0), "TSO accepted a TS1 neighborhood data scope");
            Require(!VMMemory.SetVariable(frame, VMVariableScope.NeighborhoodData, 1, 1), "Neighborhood data scope wrote in TSO mode");
        }
        finally
        {
            vm.TS1 = wasTs1;
            Array.Copy(nhoodBefore, nhoodValues, nhoodBefore.Length);
            if (neighbor != null) neighbor.PersonData = personBefore;
        }

        Require(originalHash.SequenceEqual(SHA256.HashData(File.ReadAllBytes(nhoodFile))), "Checks modified the original neighborhood file");
        return new { checks, neighborhoodRecords = nhoodValues.Length, personDataRecords = personBefore?.Length ?? 0,
            originalDataModified = false, livePresentationVerified = false };
    }
}
