using FSO.Content;
using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.SimAntics.NetPlay.Model.Commands;
using FSO.SimAntics.Primitives;

internal static class NativeVisitorChecks
{
    private sealed record VisitorSnapshot(short NeighborId, string Name, short Schedule, short GreetStatus,
        short FamilyNumber, string FirstSeen, int Appearances);

    public static object Run(VM vm)
    {
        var family = vm.TS1State.CurrentFamily;
        var initialNeighborIds = vm.Entities.OfType<VMAvatar>()
            .Select(avatar => avatar.GetPersonData(VMPersonDataVariable.NeighborId))
            .ToHashSet();
        var dialogResponder = vm.Entities.OfType<VMAvatar>().FirstOrDefault(avatar =>
            family == null || avatar.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID);
        if (family != null && dialogResponder == null)
            throw new InvalidDataException("Visitor check household has no resident Sim");
        if (dialogResponder == null)
        {
            var neighbor = FSO.Content.Content.Get().Neighborhood.Neighbors.NeighbourByID.Values.FirstOrDefault(candidate =>
                candidate.PersonData != null && FSO.Content.Content.Get().WorldObjects.Get(candidate.GUID) != null)
                ?? throw new InvalidDataException("Visitor check community lot has no valid neighborhood Sim for dialog responses");
            dialogResponder = (VMAvatar)vm.Context.CreateObjectInstance(neighbor.GUID,
                FSO.LotView.Model.LotTilePos.OUT_OF_WORLD, FSO.LotView.Model.Direction.NORTH).Objects[0];
            initialNeighborIds.Add(dialogResponder.GetPersonData(VMPersonDataVariable.NeighborId));
        }
        vm.SetGlobalValue(3, family == null ? (short)0 : dialogResponder.ObjectID);
        var visitors = new Dictionary<short, (VMAvatar Avatar, string FirstSeen, int Appearances)>();
        var dialogTypes = new HashSet<VMDialogType>();
        var simulationErrors = new List<string>();
        var clock = vm.Context.Clock;
        clock.Hours = 6;
        clock.Minutes = 0;
        clock.MinuteFractions = 0;
        vm.SpeedMultiplier = 10;
        vm.LastSpeedMultiplier = 10;

        void CaptureDialog(VMDialogInfo? info)
        {
            if (info?.Title == "SimAntics Exception!") simulationErrors.Add(info.Message ?? "Unknown SimAntics exception");
        }

        vm.OnDialog += CaptureDialog;
        var updates = 0;
        try
        {
            while (clock.Hours * 60 + clock.Minutes < 21 * 60 && updates < 7000)
            {
                if (vm.GlobalBlockingDialog != null)
                {
                    var state = vm.GlobalBlockingDialog.Thread.BlockingState as VMDialogResult
                        ?? throw new InvalidDataException("Visitor check encountered a non-dialog blocking state");
                    if (state.Type == VMDialogType.Sims1Tutorial)
                        throw new InvalidDataException("Visitor check unexpectedly entered the Sims 1 tutorial");
                    dialogTypes.Add(state.Type);
                    var code = state.Type switch
                    {
                        VMDialogType.YesNo => (byte)1,
                        VMDialogType.YesNoCancel => (byte)2,
                        _ => (byte)0
                    };
                    if (dialogResponder == null)
                        throw new InvalidDataException("Visitor check encountered a blocking dialog before any Sim arrived on the community lot");
                    if (!new VMNetDialogResponseCmd { ResponseCode = code, ResponseText = string.Empty }.Execute(vm,
                        dialogResponder))
                        throw new InvalidDataException("Visitor check could not dismiss an original modal dialog");
                    continue;
                }

                vm.Update();
                updates++;
                foreach (var avatar in vm.Entities.OfType<VMAvatar>())
                {
                    var neighborId = avatar.GetPersonData(VMPersonDataVariable.NeighborId);
                    var familyNumber = avatar.GetPersonData(VMPersonDataVariable.TS1FamilyNumber);
                    if (initialNeighborIds.Contains(neighborId) ||
                        avatar.GetPersonData(VMPersonDataVariable.PersonType) != 1 ||
                        (family != null && familyNumber == family.ChunkID))
                        continue;

                    var time = $"{clock.Hours:D2}:{clock.Minutes:D2}";
                    if (visitors.TryGetValue(neighborId, out var current))
                        visitors[neighborId] = (avatar, current.FirstSeen, current.Appearances + 1);
                    else
                        visitors[neighborId] = (avatar, time, 1);
                }
            }
        }
        finally
        {
            vm.OnDialog -= CaptureDialog;
        }

        var reachedEvening = clock.Hours * 60 + clock.Minutes >= 21 * 60;
        // Departure phase: keep the original lot scripts running for four more simulated hours, across midnight,
        // and record visitors whose avatars the scripts remove from the lot.
        var departures = new Dictionary<short, string>();
        var departureUpdates = 0;
        vm.OnDialog += CaptureDialog;
        try
        {
            var elapsed = 0;
            var lastMinute = clock.Hours * 60 + clock.Minutes;
            while (reachedEvening && elapsed < 4 * 60 && departureUpdates < 4000)
            {
                if (vm.GlobalBlockingDialog != null)
                {
                    var state = vm.GlobalBlockingDialog.Thread.BlockingState as VMDialogResult
                        ?? throw new InvalidDataException("Visitor departure check encountered a non-dialog blocking state");
                    dialogTypes.Add(state.Type);
                    var code = state.Type switch
                    {
                        VMDialogType.YesNo => (byte)1,
                        VMDialogType.YesNoCancel => (byte)2,
                        _ => (byte)0
                    };
                    if (dialogResponder == null || !new VMNetDialogResponseCmd { ResponseCode = code, ResponseText = string.Empty }.Execute(vm, dialogResponder))
                        throw new InvalidDataException("Visitor departure check could not dismiss an original modal dialog");
                    continue;
                }

                vm.Update();
                departureUpdates++;
                var minute = clock.Hours * 60 + clock.Minutes;
                elapsed += (minute - lastMinute + 24 * 60) % (24 * 60);
                lastMinute = minute;
                foreach (var (neighborId, visitor) in visitors)
                {
                    if (departures.ContainsKey(neighborId) || vm.Entities.Contains(visitor.Avatar)) continue;
                    departures[neighborId] = $"{clock.Hours:D2}:{clock.Minutes:D2}";
                }
            }
        }
        finally
        {
            vm.OnDialog -= CaptureDialog;
            vm.SpeedMultiplier = 0;
        }

        if (!reachedEvening)
            throw new TimeoutException($"Original visitor scenario did not advance through the day; stopped at {clock.Hours:D2}:{clock.Minutes:D2} after {updates} updates");
        if (simulationErrors.Count > 0)
            throw new InvalidDataException("Original visitor behavior raised a SimAntics exception: " + simulationErrors[0]);
        if (visitors.Count == 0)
        {
            var neighbors = FSO.Content.Content.Get().Neighborhood.Neighbors.NeighbourByID.Values
                .Where(neighbor => neighbor.PersonData != null &&
                    (family == null || neighbor.PersonData[(int)VMPersonDataVariable.TS1FamilyNumber] != family.ChunkID))
                .Select(neighbor => new
                {
                    neighbor.NeighbourID,
                    neighbor.Name,
                    personType = neighbor.PersonData![(int)VMPersonDataVariable.PersonType],
                    visitorSchedule = neighbor.PersonData![(int)VMPersonDataVariable.VisitorSchedule]
                })
                .Take(12)
                .ToArray();
            throw new InvalidDataException($"Original lot behavior did not produce a visitor from 06:00 to 21:00; lot={vm.GetGlobalValue(10)}, family={family?.ChunkID}, outsideNeighbors={neighbors.Length}, examples={System.Text.Json.JsonSerializer.Serialize(neighbors)}");
        }

        if (simulationErrors.Count > 0)
            throw new InvalidDataException("Original visitor departure behavior raised a SimAntics exception: " + simulationErrors[0]);
        if (departures.Count == 0)
            throw new InvalidDataException($"No visitor left the lot within four simulated hours after 21:00; visitors={visitors.Count}, stoppedAt={clock.Hours:D2}:{clock.Minutes:D2}");

        return new
        {
            lot = vm.GetGlobalValue(10),
            household = family?.ChunkID,
            simulatedFrom = "06:00",
            simulatedThrough = $"{clock.Hours:D2}:{clock.Minutes:D2}",
            visitors = visitors.Select(pair => new VisitorSnapshot(
                pair.Key,
                pair.Value.Avatar.Name,
                pair.Value.Avatar.GetPersonData(VMPersonDataVariable.VisitorSchedule),
                pair.Value.Avatar.GetPersonData(VMPersonDataVariable.GreetStatus),
                pair.Value.Avatar.GetPersonData(VMPersonDataVariable.TS1FamilyNumber),
                pair.Value.FirstSeen,
                pair.Value.Appearances)).OrderBy(visitor => visitor.NeighborId).ToArray(),
            dialogTypes = dialogTypes.Select(type => type.ToString()).Order().ToArray(),
            vmUpdates = updates,
            departures = departures.OrderBy(pair => pair.Key).Select(pair => new { neighborId = pair.Key, time = pair.Value }).ToArray(),
            departureUpdates,
            visitorDepartureObserved = true,
            originalVisitorBehaviorObserved = true
        };
    }
}
