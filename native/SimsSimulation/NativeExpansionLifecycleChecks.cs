using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;
using FSO.SimAntics.Utils;
using FSO.LotView.Model;

internal static class NativeExpansionLifecycleChecks
{
    internal static object Run(VM vm)
    {
        var avatar = vm.Entities.OfType<VMAvatar>().First();
        var thread = avatar.Thread ?? throw new InvalidDataException("Lifecycle check avatar has no VM thread");
        var neighborId = avatar.GetPersonData(VMPersonDataVariable.NeighborId);
        var neighborhood = Content.Get().Neighborhood;
        var inventoryById = neighborhood.Neighborhood.InventoryByID;
        var neighbor = neighborhood.GetNeighborByID(neighborId) ?? throw new InvalidDataException("Lifecycle check avatar has no neighborhood record");
        var originalNeighborPersonData = neighbor.PersonData?.ToArray() ?? throw new InvalidDataException("Lifecycle check neighbor has no person data");
        var originalAvatarPersonData = avatar.GetPersonDataClone();
        var originalFootprintBounds = avatar.Footprint == null ? null : new[]
        {
            avatar.Footprint.x1, avatar.Footprint.y1, avatar.Footprint.x2, avatar.Footprint.y2
        };
        var hadInventory = inventoryById.TryGetValue(neighborId, out var previousInventory);
        var originalTemps = (short[])thread.TempRegisters.Clone();
        var checks = 0;
        void Require(bool condition, string message)
        {
            if (!condition) throw new InvalidDataException(message);
            checks++;
        }

        try
        {
            inventoryById[neighborId] = new List<InventoryItem>
            {
                new() { Type = 2, GUID = 7, Count = 14 },
                new() { Type = 2, GUID = 8, Count = 37 },
                new() { Type = 1, GUID = 7, Count = 99 },
                new() { Type = 2, GUID = 6, Count = 88 }
            };
            for (var index = 0; index < thread.TempRegisters.Length; index++) thread.TempRegisters[index] = (short)(100 + index);
            var frame = new VMStackFrame { Thread = thread, Caller = avatar, Callee = avatar, StackObject = avatar };
            var result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.GetDowntownTimeFromSOInventory });
            Require(result == VMPrimitiveExitCode.GOTO_TRUE, "Downtown time inventory call did not return true");
            Require(thread.TempRegisters[0] == 14 && thread.TempRegisters[1] == 37,
                "Downtown time inventory call did not read type-2 hour and minute records");
            Require(thread.TempRegisters.Skip(2).SequenceEqual(Enumerable.Range(2, thread.TempRegisters.Length - 2).Select(index => (short)(100 + index))),
                "Downtown time inventory call changed temps outside Temp0 and Temp1");

            inventoryById[neighborId] = new List<InventoryItem>();
            thread.TempRegisters[0] = 77;
            thread.TempRegisters[1] = 78;
            result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.GetDowntownTimeFromSOInventory });
            Require(result == VMPrimitiveExitCode.GOTO_TRUE, "Missing downtown time records changed the primitive result");
            Require(thread.TempRegisters[0] == 77 && thread.TempRegisters[1] == 78,
                "Missing downtown time records overwrote the existing temp values");

            avatar.SetPersonData(VMPersonDataVariable.NicePersonality, 321);
            avatar.SetPersonData(VMPersonDataVariable.ActivePersonality, 654);
            foreach (var length in new[] { 80, 256 })
            {
                neighbor.PersonData = new short[length];
                neighbor.PersonData[40] = -1234;
                result = new VMGenericTS1Call().Execute(frame,
                    new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.SaveSimPersistentData });
                Require(result == VMPrimitiveExitCode.GOTO_TRUE, $"Persistent person-data call failed for {length} fields");
                Require(neighbor.PersonData[2] == 321 && neighbor.PersonData[3] == 654,
                    $"Persistent person-data call did not copy original fields for {length} fields");
                Require(neighbor.PersonData[40] == -1234, "Persistent person-data call changed a non-persistent field");
            }

            var missingNeighborId = short.MaxValue;
            while (neighborhood.GetNeighborByID(missingNeighborId) != null) missingNeighborId--;
            avatar.SetPersonData(VMPersonDataVariable.NeighborId, missingNeighborId);
            result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.SaveSimPersistentData });
            Require(result == VMPrimitiveExitCode.GOTO_TRUE, "Missing-neighbor persistent save did not preserve success behavior");
            avatar.SetPersonData(VMPersonDataVariable.NeighborId, originalAvatarPersonData[31]);

            var occupiedVacationLots = neighborhood.FamilyForHouse.Keys.Count(houseNumber => houseNumber is >= 40 and <= 48);
            for (var index = 0; index < thread.TempRegisters.Length; index++) thread.TempRegisters[index] = (short)(200 + index);
            result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.ReturnNumberOfAvaiableVacationLotsInTemp0 });
            Require(result == VMPrimitiveExitCode.GOTO_TRUE && thread.TempRegisters[0] == 9 - occupiedVacationLots,
                "Vacation-lot availability did not account for occupied lots 40 through 48");
            Require(thread.TempRegisters.Skip(1).SequenceEqual(Enumerable.Range(1, thread.TempRegisters.Length - 1).Select(index => (short)(200 + index))),
                "Vacation-lot availability changed temps outside Temp0");
            checks += CheckRoutingFootprint(vm, avatar, thread);
            checks += CheckNormalOutfit(avatar, thread);
            checks += CheckAddToFamilyInTemp0(vm, avatar, thread);

        }
        finally
        {
            Array.Copy(originalTemps, thread.TempRegisters, originalTemps.Length);
            avatar.SetPersonData(VMPersonDataVariable.NicePersonality, originalAvatarPersonData[2]);
            avatar.SetPersonData(VMPersonDataVariable.ActivePersonality, originalAvatarPersonData[3]);
            avatar.SetPersonData(VMPersonDataVariable.NeighborId, originalAvatarPersonData[31]);
            avatar.SetPersonData(VMPersonDataVariable.RouteFootprintMask, originalAvatarPersonData[(int)VMPersonDataVariable.RouteFootprintMask]);
            avatar.SetPersonData(VMPersonDataVariable.FootprintExtension, originalAvatarPersonData[(int)VMPersonDataVariable.FootprintExtension]);
            avatar.UpdateFootprint();
            if (originalFootprintBounds != null && avatar.Footprint != null)
            {
                avatar.Footprint.x1 = originalFootprintBounds[0];
                avatar.Footprint.y1 = originalFootprintBounds[1];
                avatar.Footprint.x2 = originalFootprintBounds[2];
                avatar.Footprint.y2 = originalFootprintBounds[3];
            }
            neighbor.PersonData = originalNeighborPersonData;
            if (hadInventory) inventoryById[neighborId] = previousInventory!;
            else inventoryById.Remove(neighborId);
        }

        return new { checks, mode = (byte)VMGenericTS1CallMode.GetDowntownTimeFromSOInventory, originalHandler = true };
    }

    private static int CheckAddToFamilyInTemp0(VM vm, VMAvatar caller, VMThread thread)
    {
        var neighborhood = Content.Get().Neighborhood;
        var runtimeNeighborIds = vm.Context.ObjectQueries.Avatars.OfType<VMAvatar>()
            .Select(avatar => avatar.GetPersonData(VMPersonDataVariable.NeighborId)).ToHashSet();
        var families = neighborhood.MainResource.List<FAMI>() ?? new List<FAMI>();
        var fixture = neighborhood.Neighbors.Entries
            .Where(person => person.PersonData != null && person.PersonData.Length > (int)VMPersonDataVariable.TS1FamilyNumber &&
                !runtimeNeighborIds.Contains(person.NeighbourID))
            .Select(person => new
            {
                Person = person,
                Source = neighborhood.GetFamily((ushort)person.PersonData![(int)VMPersonDataVariable.TS1FamilyNumber])
            })
            .Where(item => item.Source != null && item.Source.FamilyGUIDs.Contains(item.Person.GUID))
            .SelectMany(item => families.Where(target => target != item.Source && target != vm.TS1State.CurrentFamily &&
                    target.FamilyGUIDs.Length < 8 && !target.FamilyGUIDs.Contains(item.Person.GUID))
                .Select(target => new { item.Person, item.Source, Target = target }))
            .FirstOrDefault();
        if (fixture == null) throw new InvalidDataException("Family lifecycle checks require a non-runtime neighbor and non-current family fixture");

        var originalPersonData = fixture.Person.PersonData!.ToArray();
        var originalTargetMembers = (uint[])fixture.Target.FamilyGUIDs.Clone();
        var originalTargetRuntime = (uint[])fixture.Target.RuntimeSubset.Clone();
        var sourceFamilyId = ushort.MaxValue;
        while (neighborhood.MainResource.Get<FAMI>(sourceFamilyId) != null) sourceFamilyId--;
        var sourceFamily = new FAMI
        {
            ChunkID = sourceFamilyId,
            AddedByPatch = true,
            ChunkProcessed = true,
            FamilyGUIDs = new[] { fixture.Person.GUID }
        };
        neighborhood.MainResource.AddChunk(sourceFamily);
        fixture.Person.PersonData[(int)VMPersonDataVariable.TS1FamilyNumber] = (short)sourceFamilyId;
        var originalTemp0 = thread.TempRegisters[0];
        var frame = new VMStackFrame
        {
            Thread = thread,
            Caller = caller,
            Callee = caller,
            StackObjectID = fixture.Person.NeighbourID
        };
        var checks = 0;
        void Require(bool condition, string message)
        {
            if (!condition) throw new InvalidDataException(message);
            checks++;
        }

        try
        {
            var missingId = ushort.MaxValue;
            while (neighborhood.GetFamily(missingId) != null) missingId--;
            thread.TempRegisters[0] = (short)missingId;
            var result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AddToFamilyInTemp0 });
            Require(result == VMPrimitiveExitCode.GOTO_FALSE && sourceFamily.FamilyGUIDs.SequenceEqual(new[] { fixture.Person.GUID }) &&
                fixture.Target.FamilyGUIDs.SequenceEqual(originalTargetMembers), "Missing target family changed family membership");

            fixture.Target.FamilyGUIDs = Enumerable.Range(0, 8).Select(index => 0xF0000000u + (uint)index).ToArray();
            thread.TempRegisters[0] = (short)fixture.Target.ChunkID;
            result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AddToFamilyInTemp0 });
            Require(result == VMPrimitiveExitCode.GOTO_FALSE && fixture.Person.PersonData![(int)VMPersonDataVariable.TS1FamilyNumber] ==
                (short)sourceFamilyId, "Full target family changed the neighbor assignment");

            fixture.Target.FamilyGUIDs = new[] { fixture.Person.GUID, fixture.Person.GUID };
            thread.TempRegisters[0] = (short)fixture.Target.ChunkID;
            result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AddToFamilyInTemp0 });
            Require(result == VMPrimitiveExitCode.GOTO_TRUE, "Target-family add did not return true");
            Require(fixture.Target.FamilyGUIDs.Count(guid => guid == fixture.Person.GUID) == 1 &&
                neighborhood.GetFamily(sourceFamilyId) == null,
                "Target-family add did not deduplicate membership and delete the emptied old family");
            Require(fixture.Person.PersonData[(int)VMPersonDataVariable.TS1FamilyNumber] == (short)fixture.Target.ChunkID,
                "Target-family add did not update the neighbor's family number");
            Require(fixture.Target != vm.TS1State.CurrentFamily, "Family lifecycle fixture unexpectedly targeted the current family");

            result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AddToFamilyInTemp0 });
            Require(result == VMPrimitiveExitCode.GOTO_TRUE && neighborhood.GetFamily(fixture.Target.ChunkID) == fixture.Target &&
                fixture.Target.FamilyGUIDs.Count(guid => guid == fixture.Person.GUID) == 1,
                "Repeated same-family add deleted the family or duplicated its member");

            var currentFamily = vm.TS1State.CurrentFamily;
            var runtimeSource = neighborhood.GetFamily((ushort)caller.GetPersonData(VMPersonDataVariable.TS1FamilyNumber));
            var runtimeTarget = families.FirstOrDefault(target => target != currentFamily && target != runtimeSource &&
                target.FamilyGUIDs.Length < 8 && !target.FamilyGUIDs.Contains(caller.Object.OBJ.GUID));
            if (runtimeSource != null && runtimeTarget != null && runtimeSource.FamilyGUIDs.Contains(caller.Object.OBJ.GUID))
            {
                var oldAvatarFamily = caller.GetPersonData(VMPersonDataVariable.TS1FamilyNumber);
                var oldSourceMembers = (uint[])runtimeSource.FamilyGUIDs.Clone();
                var oldSourceRuntime = (uint[])runtimeSource.RuntimeSubset.Clone();
                var oldTargetMembers = (uint[])runtimeTarget.FamilyGUIDs.Clone();
                var oldTargetRuntime = (uint[])runtimeTarget.RuntimeSubset.Clone();
                try
                {
                    if (runtimeSource.FamilyGUIDs.Length == 1)
                        runtimeSource.FamilyGUIDs = runtimeSource.FamilyGUIDs.Concat(new[] { 0xEFFFFFFEu }).ToArray();
                    frame.StackObjectID = caller.GetPersonData(VMPersonDataVariable.NeighborId);
                    thread.TempRegisters[0] = (short)runtimeTarget.ChunkID;
                    result = new VMGenericTS1Call().Execute(frame,
                        new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AddToFamilyInTemp0 });
                    Require(result == VMPrimitiveExitCode.GOTO_TRUE &&
                        caller.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == (short)runtimeTarget.ChunkID,
                        "Runtime-avatar family move did not update its TS1 family number");
                    Require(!runtimeSource.RuntimeSubset.Contains(caller.Object.OBJ.GUID) &&
                        runtimeTarget.FamilyGUIDs.Count(guid => guid == caller.Object.OBJ.GUID) == 1,
                        "Runtime-avatar family move did not update active membership");
                }
                finally
                {
                    caller.SetPersonData(VMPersonDataVariable.TS1FamilyNumber, oldAvatarFamily);
                    runtimeSource.FamilyGUIDs = oldSourceMembers;
                    runtimeSource.RuntimeSubset = oldSourceRuntime;
                    runtimeTarget.FamilyGUIDs = oldTargetMembers;
                    runtimeTarget.RuntimeSubset = oldTargetRuntime;
                }
            }
            else
            {
                throw new InvalidDataException("Family lifecycle checks require an active avatar in a current family and another open family");
            }
        }
        finally
        {
            fixture.Person.PersonData = originalPersonData;
            if (!neighborhood.MainResource.SilentListAll().Contains(sourceFamily)) neighborhood.MainResource.AddChunk(sourceFamily);
            sourceFamily.FamilyGUIDs = new[] { fixture.Person.GUID };
            fixture.Target.FamilyGUIDs = originalTargetMembers;
            fixture.Target.RuntimeSubset = originalTargetRuntime;
            thread.TempRegisters[0] = originalTemp0;
        }

        return checks;
    }

    private static int CheckRoutingFootprint(VM vm, VMAvatar avatar, VMThread thread)
    {
        var center = new FSO.LotView.Model.LotTilePos(100, 200, 0);
        var north = VMAvatar.GetRoutingFootprintBounds(center, Direction.NORTH, 0x1234, 0x0102);
        var east = VMAvatar.GetRoutingFootprintBounds(center, Direction.EAST, 0x1234, 0x0102);
        if (!north.SequenceEqual(new[] { 99, 198, 102, 200 }))
            throw new InvalidDataException("North-facing asymmetric routing footprint did not preserve native nibble offsets");
        if (!east.SequenceEqual(new[] { 98, 198, 100, 201 }))
            throw new InvalidDataException("East-facing routing footprint did not rotate the asymmetric mask and extension");
        if (!VMAvatar.GetRoutingFootprintBounds(center, Direction.NORTH, 0, 0, true).SequenceEqual(new[] { 100, 200, 100, 200 }))
            throw new InvalidDataException("Original zero-radius state did not collapse the routing bounds to the person position");

        var originalRouteMask = avatar.GetPersonData(VMPersonDataVariable.RouteFootprintMask);
        var originalExtension = avatar.GetPersonData(VMPersonDataVariable.FootprintExtension);
        var originalGhost = avatar.GetPersonData(VMPersonDataVariable.IsGhost);
        var originalSkillLockCreativity = avatar.GetPersonData(VMPersonDataVariable.SkillLockCreativity);
        var originalTemps = (short[])thread.TempRegisters.Clone();
        var frame = new VMStackFrame { Thread = thread, Caller = avatar, Callee = avatar, StackObject = avatar };
        var oldBounds = avatar.Footprint == null ? null : new[]
        {
            avatar.Footprint.x1, avatar.Footprint.y1, avatar.Footprint.x2, avatar.Footprint.y2
        };
        try
        {
            avatar.SetPersonData(VMPersonDataVariable.RouteFootprintMask, 0x4567);
            avatar.SetPersonData(VMPersonDataVariable.FootprintExtension, 0x1234);
            thread.TempRegisters[0] = 0;
            var result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.MyRoutingFootprintEqualsTemp0 });
            if (result != VMPrimitiveExitCode.GOTO_TRUE ||
                avatar.GetPersonData(VMPersonDataVariable.RouteFootprintMask) != 0 ||
                avatar.GetPersonData(VMPersonDataVariable.FootprintExtension) != 0)
                throw new InvalidDataException("Mode 15 did not reset route mask and extension when Temp0 is zero");

            var expected = VMAvatar.GetRoutingFootprintBounds(avatar.Position, avatar.Direction, avatar.Object?.OBJ?.FootprintMask ?? 0, 0);
            if (avatar.Footprint == null || avatar.Footprint.x1 != expected[0] || avatar.Footprint.y1 != expected[1] ||
                avatar.Footprint.x2 != expected[2] || avatar.Footprint.y2 != expected[3])
                throw new InvalidDataException("Mode 15 zero-mask reset did not refresh the avatar routing obstacle");

            var actualFootprintMask = avatar.Object?.OBJ?.FootprintMask ?? 0;
            var zeroRadiusExpected = VMAvatar.GetRoutingFootprintBounds(avatar.Position, avatar.Direction,
                actualFootprintMask, 0, true);
            avatar.SetPersonData(VMPersonDataVariable.IsGhost, 1);
            var ghostObstacle = avatar.GetObstacle(avatar.Position, avatar.Direction, true);
            if (ghostObstacle == null || ghostObstacle.x1 != zeroRadiusExpected[0] || ghostObstacle.y1 != zeroRadiusExpected[1] ||
                ghostObstacle.x2 != zeroRadiusExpected[2] || ghostObstacle.y2 != zeroRadiusExpected[3])
                throw new InvalidDataException("Person-data field 68 did not trigger the original zero-radius footprint path");
            avatar.SetPersonData(VMPersonDataVariable.IsGhost, 0);
            avatar.SetPersonData(VMPersonDataVariable.SkillLockCreativity, 1);
            var lockedSkillObstacle = avatar.GetObstacle(avatar.Position, avatar.Direction, true);
            if (lockedSkillObstacle == null || lockedSkillObstacle.x1 != zeroRadiusExpected[0] ||
                lockedSkillObstacle.y1 != zeroRadiusExpected[1] || lockedSkillObstacle.x2 != zeroRadiusExpected[2] ||
                lockedSkillObstacle.y2 != zeroRadiusExpected[3])
                throw new InvalidDataException("Person-data field 84 did not trigger the original zero-radius footprint path");
            avatar.SetPersonData(VMPersonDataVariable.SkillLockCreativity, 0);
            var normalObstacle = avatar.GetObstacle(avatar.Position, avatar.Direction, true);
            var normalExpected = VMAvatar.GetRoutingFootprintBounds(avatar.Position, avatar.Direction, actualFootprintMask, 0);
            if (normalObstacle == null || normalObstacle.x1 != normalExpected[0] || normalObstacle.y1 != normalExpected[1] ||
                normalObstacle.x2 != normalExpected[2] || normalObstacle.y2 != normalExpected[3])
                throw new InvalidDataException("Clearing person-data fields 68 and 84 did not restore the default avatar radius");
            if (!thread.TempRegisters.Skip(1).SequenceEqual(originalTemps.Skip(1)))
                throw new InvalidDataException("Mode 15 changed temps outside Temp0");
            avatar.Footprint.x1 = 333;
            avatar.Footprint.y1 = 334;
            avatar.Footprint.x2 = 335;
            avatar.Footprint.y2 = 336;
            thread.TempRegisters[0] = 0x4567;
            result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.MyRoutingFootprintEqualsTemp0 });
            if (result != VMPrimitiveExitCode.GOTO_TRUE ||
                avatar.GetPersonData(VMPersonDataVariable.RouteFootprintMask) != 0x4567 ||
                avatar.GetPersonData(VMPersonDataVariable.FootprintExtension) != 0)
                throw new InvalidDataException("Mode 15 did not store the nonzero route mask or clear the extension");
            if (avatar.Footprint == null || avatar.Footprint.x1 != 333 || avatar.Footprint.y1 != 334 ||
                avatar.Footprint.x2 != 335 || avatar.Footprint.y2 != 336)
                throw new InvalidDataException("Mode 15 rebuilt the obstacle on the original nonzero-mask path");
            return 6;
        }
        finally
        {
            avatar.SetPersonData(VMPersonDataVariable.RouteFootprintMask, originalRouteMask);
            avatar.SetPersonData(VMPersonDataVariable.FootprintExtension, originalExtension);
            avatar.SetPersonData(VMPersonDataVariable.IsGhost, originalGhost);
            avatar.SetPersonData(VMPersonDataVariable.SkillLockCreativity, originalSkillLockCreativity);
            Array.Copy(originalTemps, thread.TempRegisters, originalTemps.Length);
            avatar.UpdateFootprint();
            if (oldBounds != null && avatar.Footprint != null)
            {
                avatar.Footprint.x1 = oldBounds[0];
                avatar.Footprint.y1 = oldBounds[1];
                avatar.Footprint.x2 = oldBounds[2];
                avatar.Footprint.y2 = oldBounds[3];
            }
        }
    }

    private static int CheckNormalOutfit(VMAvatar avatar, VMThread thread)
    {
        var strings = avatar.Object.Resource.Get<STR>(avatar.Object.OBJ.BodyStringID);
        var stringIndexes = new[] { 1, 17, 18, 19, 20, 21, 22 };
        var originalStrings = stringIndexes.Select(index => strings.GetString(index)).ToArray();
        var originalBody = avatar.BodyOutfit;
        var originalDaywear = avatar.DefaultSuits.Daywear;
        var originalCurrentOutfit = avatar.GetPersonData(VMPersonDataVariable.CurrentOutfit);
        var originalTemps = (short[])thread.TempRegisters.Clone();
        try
        {
            var validOutfits = VMGenericTS1Call.GetNormalOutfits(avatar);
            var frame = new VMStackFrame { Thread = thread, Caller = avatar, Callee = avatar, StackObject = avatar };
            if (validOutfits.Length == 0)
            {
                var unchangedBody = avatar.BodyOutfit;
                var emptyResult = new VMGenericTS1Call().Execute(frame,
                    new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.ChangeNormalOutfit });
                if (emptyResult != VMPrimitiveExitCode.GOTO_TRUE || !ReferenceEquals(avatar.BodyOutfit, unchangedBody))
                    throw new InvalidDataException("Empty normal-outfit list was not a successful no-op");
                return 2;
            }

            VMOutfitReference Candidate(int index) => new VMOutfitReference(validOutfits[index].Item1, false);
            bool Matches(VMOutfitReference left, VMOutfitReference right) =>
                left.OftData?.TS1AppearanceID == right.OftData?.TS1AppearanceID &&
                left.OftData?.TS1TextureID == right.OftData?.TS1TextureID;

            var duplicateFixture = validOutfits.Length > 1
                ? validOutfits.ToArray()
                : new[] { validOutfits[0], validOutfits[0] };
            duplicateFixture[1] = duplicateFixture[0];
            if (VMGenericTS1Call.FindNormalOutfitIndex(duplicateFixture, Candidate(0).OftData) != 0)
                throw new InvalidDataException("Duplicate normal-outfit candidates did not resolve to the first matching index");

            avatar.BodyOutfit = new VMOutfitReference("missingnormaloutfit,BODY=missingnormaltexture", false);
            var result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.ChangeNormalOutfit });
            if (result != VMPrimitiveExitCode.GOTO_TRUE || !Matches(avatar.BodyOutfit, Candidate(0)))
                throw new InvalidDataException("Missing current outfit did not wrap to the first valid outfit");

            for (var index = 1; index <= validOutfits.Length; index++)
            {
                result = new VMGenericTS1Call().Execute(frame,
                    new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.ChangeNormalOutfit });
                if (result != VMPrimitiveExitCode.GOTO_TRUE || !Matches(avatar.BodyOutfit, Candidate(index % validOutfits.Length)))
                    throw new InvalidDataException("Normal-outfit cycle did not advance and wrap through the complete catalog");
                var expectedHandgroup = originalDaywear?.OftData?.LiteralHandgroup ?? originalBody?.OftData?.LiteralHandgroup;
                if (expectedHandgroup != null && !ReferenceEquals(avatar.BodyOutfit.OftData?.LiteralHandgroup, expectedHandgroup))
                    throw new InvalidDataException("Normal-outfit cycle did not preserve the avatar's existing handgroup");
            }
            if (!ReferenceEquals(avatar.DefaultSuits.Daywear, originalDaywear) ||
                avatar.GetPersonData(VMPersonDataVariable.CurrentOutfit) != originalCurrentOutfit)
                throw new InvalidDataException("Normal-outfit cycle changed persistent daywear or CurrentOutfit data");
            if (stringIndexes.Where((index, offset) => strings.GetString(index) != originalStrings[offset]).Any())
                throw new InvalidDataException("Normal-outfit cycle persisted changes into person body strings");
            if (!thread.TempRegisters.SequenceEqual(originalTemps))
                throw new InvalidDataException("Normal-outfit cycle changed temp registers");
            return 6;
        }
        finally
        {
            for (var i = 0; i < stringIndexes.Length; i++)
                strings.SetString(stringIndexes[i], originalStrings[i], STRLangCode.EnglishUS);
            avatar.DefaultSuits.Daywear = originalDaywear;
            if (originalBody != null) avatar.BodyOutfit = originalBody;
            Array.Copy(originalTemps, thread.TempRegisters, originalTemps.Length);
        }
    }
}
