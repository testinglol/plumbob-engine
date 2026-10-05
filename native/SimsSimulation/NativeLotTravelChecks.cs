using System.Reflection;
using System.Text.Json;
using FSO.Content;
using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;

internal static class NativeLotTravelChecks
{
    internal static object Run(VM original, string workspace, string profile, string game, short home)
    {
        var directory = Path.Combine(workspace, "runtime", "native-sessions", "travel-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(directory);
        using var output = new StreamWriter(Path.Combine(directory, "events.jsonl")) { AutoFlush = true };
        var server = new SimulationServer(original, output, directory, profile, game, home);
        const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
        var vmField = typeof(SimulationServer).GetField("vm", flags)!;
        VM Current() => (VM)vmField.GetValue(server)!;
        object? Invoke(string method, params object[] args) => NativeServerReflection.Invoke(server, method, args);
        int checks = 0;
        void Require(bool condition, string message) { if (!condition) throw new InvalidDataException(message); checks++; }
        void Change(short destination)
        {
            var vm = Current();
            var avatar = vm.Entities.OfType<VMAvatar>().First(entity => entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == vm.TS1State.CurrentFamily.ChunkID);
            avatar.Thread.TempRegisters[0] = destination;
            vm.SetGlobalValue(34, 1);
            var frame = new VMStackFrame { Caller = avatar, Callee = avatar, CodeOwner = avatar.Object, Thread = avatar.Thread };
            Require(new VMGenericTS1Call().Execute(frame, new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.ChangeToLotInTemp0 }) == VMPrimitiveExitCode.GOTO_TRUE_NEXT_TICK,
                "Original travel primitive did not request a switch");
            Invoke("ApplyLotSwitch");
        }
        var family = original.TS1State.CurrentFamily.ChunkID;
        var originalObjects = original.Entities.Count;
        var originalHour = original.Context.Clock.Hours;
        var destinations = new List<object>();
        var oldTown = Content.Get().Neighborhood.ZoningDictionary.Where(pair => pair.Key is >= 50 and <= 80 && pair.Value == 1).OrderBy(pair => pair.Key).First().Key;
        foreach (short destination in new short[] { 21, 40, oldTown, 81, 93 })
        {
            Change(destination);
            var vm = Current();
            Require(vm.GetGlobalValue(10) == destination && vm != original, "Destination VM did not activate the requested lot");
            var startupSlot = "travel-check-start-" + Guid.NewGuid().ToString("N");
            Invoke("Save", startupSlot);
            Content.Get().Neighborhood.GameState.ActiveFamily = null;
            Invoke("Load", startupSlot);
            vm = Current();
            Require(Content.Get().Neighborhood.GameState.ActiveFamily?.ChunkID == family, "Save before destination activation lost the travelling family");
            File.Delete(Path.Combine(profile, "Saves", startupSlot + ".json"));
            for (int tick = 0; tick < 1000 && vm.TS1State.CurrentFamily == null; tick++) { vm.SpeedMultiplier = 1; vm.Update(); }
            Require(vm.TS1State.CurrentFamily?.ChunkID == family, $"Destination {destination} scripts did not activate the travelling family");
            Require(vm.Entities.OfType<VMAvatar>().Any(entity => entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family), "Destination scripts did not spawn a traveller");
            var controlled = vm.GetGlobalValue(3);
            Invoke("ReconcileSelection");
            Require(vm.MyUID != 0 && (controlled == 0 || vm.GetGlobalValue(3) == controlled), "Native control did not follow the destination script's selected Sim");
            var inventory = Content.Get().Neighborhood.Neighborhood.InventoryByID;
            var before = JsonSerializer.Serialize(inventory.OrderBy(pair => pair.Key), new JsonSerializerOptions { IncludeFields = true });
            var budget = vm.TS1State.CurrentFamily!.Budget;
            var neighborhoodVariables = Content.Get().Neighborhood.Neighborhood.NeighborhoodData.ToArray();
            var slot = "travel-check-" + Guid.NewGuid().ToString("N");
            Invoke("Save", slot);
            vm.TS1State.CurrentFamily.Budget = 7;
            inventory.Clear();
            Array.Fill(Content.Get().Neighborhood.Neighborhood.NeighborhoodData, (short)1234);
            if (destination == 21) Change(40);
            Invoke("Load", slot);
            vm = Current();
            Require(vm.TS1State.CurrentFamily.Budget == budget, "Away save/load lost family funds");
            Require(Content.Get().Neighborhood.Neighborhood.NeighborhoodData.SequenceEqual(neighborhoodVariables), "Away save/load lost neighborhood script variables");
            Require(JsonSerializer.Serialize(Content.Get().Neighborhood.Neighborhood.InventoryByID.OrderBy(pair => pair.Key), new JsonSerializerOptions { IncludeFields = true }) == before,
                "Away save/load lost inventories");
            var members = vm.TS1State.CurrentFamily.RuntimeSubset.Length;
            Require(members > 0, "Away save/load lost active family members");
            Change(-1);
            vm = Current();
            Require(vm.GetGlobalValue(10) == home && vm.Entities.Count == originalObjects && vm.Context.Clock.Hours == originalHour, "Return home lost suspended lot state");
            Require(vm.TS1State.CurrentFamily.RuntimeSubset.Length == vm.TS1State.CurrentFamily.FamilyGUIDs.Length, "Return home did not restore the whole household");
            File.Delete(Path.Combine(profile, "Saves", slot + ".json"));
            destinations.Add(new { house = destination, activeMembers = members, saveLoad = true, returnedHome = true });
        }
        return new { checks, destinations, originalTravelPrimitive = true, session = directory, livePresentationVerified = false };
    }
}
