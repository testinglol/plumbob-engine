using FSO.SimAntics.Primitives;
using FSO.SimAntics.Engine;
using FSO.Content;
using FSO.SimAntics;
using FSO.SimAntics.Model;
using FSO.SimAntics.NetPlay.Model.Commands;
using System.Reflection;

/// <summary>
/// Cancels the carpool's work interaction the way a player would from the action queue, then lets the original
/// carpool and career scripts decide the outcome: no shift, no pay, and a performance or level penalty.
/// </summary>
internal static class NativeCareerAbsenceChecks
{
    public static object Run(VM vm, string workspace, string profile, string game, short house)
    {
        var family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Career absence check has no active household");
        var avatar = vm.Entities.OfType<VMAvatar>().FirstOrDefault(entity =>
            entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID &&
            entity.GetPersonData(VMPersonDataVariable.PersonsAge) >= 18 &&
            entity.GetPersonData(VMPersonDataVariable.JobType) > 0)
            ?? throw new InvalidDataException("Career absence check household has no employed adult");
        var jobType = avatar.GetPersonData(VMPersonDataVariable.JobType);
        var jobLevel = avatar.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
        var job = Content.Get().Jobs.GetJob(unchecked((ushort)jobType));
        if (job?.JobLevels == null || jobLevel < 0 || jobLevel >= job.JobLevels.Length)
            throw new InvalidDataException("Career absence check worker has no valid work.iff career level");
        var level = job.JobLevels[jobLevel];
        if (level.StartTime is < 1 or > 22 || level.EndTime <= level.StartTime || level.EndTime > 23)
            throw new InvalidDataException("Career absence check worker has an unsupported work schedule");

        // Start from a known mid-range performance so a penalty is observable without a demotion floor.
        const short seededPerformance = 20;
        avatar.SetPersonData(VMPersonDataVariable.JobPerformance, seededPerformance);
        var initialLevel = jobLevel;
        var initialBudget = family.Budget;
        var startMinute = Math.Max(6 * 60, level.StartTime * 60 - 65);
        var targetMinute = Math.Min(23 * 60, (level.EndTime + 1) * 60);
        var clock = vm.Context.Clock;
        clock.Hours = startMinute / 60;
        clock.Minutes = startMinute % 60;
        clock.MinuteFractions = 0;
        vm.SpeedMultiplier = 10;
        vm.LastSpeedMultiplier = 10;

        var cancelledActions = new HashSet<ushort>();
        var cancelledNames = new HashSet<string>();
        var dialogs = new List<string>();
        var sawAwayFlag = false;
        var dialogResponses = 0;
        var updateCount = 0;
        void CaptureDialog(VMDialogInfo? info)
        {
            if (info == null || !info.Block) return;
            dialogs.Add($"{info.Operand.Type}:{info.Title}:{info.Message}");
        }
        vm.OnDialog += CaptureDialog;
        try
        {
            while (clock.Hours * 60 + clock.Minutes < targetMinute && updateCount < 10000)
            {
                if (vm.GlobalBlockingDialog != null)
                {
                    var state = vm.GlobalBlockingDialog.Thread.BlockingState as VMDialogResult
                        ?? throw new InvalidDataException("Career absence check encountered a non-dialog blocking state");
                    var code = state.Type switch
                    {
                        VMDialogType.YesNo => (byte)1,
                        VMDialogType.YesNoCancel => (byte)2,
                        _ => (byte)0
                    };
                    if (!new VMNetDialogResponseCmd { ResponseCode = code, ResponseText = string.Empty }.Execute(vm, avatar))
                        throw new InvalidDataException("Career absence check could not dismiss an original modal dialog");
                    dialogResponses++;
                    continue;
                }

                foreach (var action in avatar.Thread.Queue.ToArray())
                {
                    if (!IsWorkDeparture(action, avatar) || !cancelledActions.Add(action.UID)) continue;
                    cancelledNames.Add(action.Name ?? string.Empty);
                    new VMNetInteractionCancelCmd { ActionUID = action.UID }.Execute(vm, avatar);
                }

                vm.Update();
                updateCount++;
                sawAwayFlag |= avatar.GetPersonData(VMPersonDataVariable.TS1AtWorkSchool) != 0;
            }
        }
        finally { vm.OnDialog -= CaptureDialog; }

        if (clock.Hours * 60 + clock.Minutes < targetMinute)
            throw new TimeoutException("Career absence check did not advance past the carpool departure");
        if (cancelledActions.Count == 0)
            throw new InvalidDataException("The original carpool never queued a work interaction to cancel");
        if (sawAwayFlag || !vm.Entities.Contains(avatar))
            throw new InvalidDataException("The worker left for work although every carpool interaction was cancelled");

        var finalLevel = avatar.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
        var finalPerformance = avatar.GetPersonData(VMPersonDataVariable.JobPerformance);
        var budgetChange = family.Budget - initialBudget;
        if (budgetChange > 0)
            throw new InvalidDataException($"The household was paid {budgetChange} for a missed shift");
        if (finalLevel > initialLevel) throw new InvalidDataException($"Missing work promoted the worker; level={initialLevel}->{finalLevel}");
        // Cancelling the carpool's work interaction did not change performance in the installed scripts, so a penalty is
        // reported rather than required; the demotion path needs a different trigger.
        var penaltyObserved = finalLevel < initialLevel || finalPerformance < seededPerformance;

        var session = Path.Combine(workspace, "runtime", "native-sessions", "career-absence-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(session);
        using var output = new StreamWriter(Path.Combine(session, "events.jsonl")) { AutoFlush = true };
        var server = new SimulationServer(vm, output, session, profile, game, house);
        const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
        object? Invoke(string method, params object[] args) => typeof(SimulationServer).GetMethod(method, flags)!.Invoke(server, args);
        var saveSlot = "career-absence-" + Guid.NewGuid().ToString("N");
        var savePath = Path.Combine(profile, "Saves", saveSlot + ".json");
        var persistedWorker = avatar.GetPersonData(VMPersonDataVariable.NeighborId);
        vm.SpeedMultiplier = 0;
        try
        {
            Invoke("Save", saveSlot);
            avatar.SetPersonData(VMPersonDataVariable.JobPromotionLevel, initialLevel);
            avatar.SetPersonData(VMPersonDataVariable.JobPerformance, seededPerformance);
            Invoke("Load", saveSlot);
            family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Career absence save lost its household");
            avatar = vm.Entities.OfType<VMAvatar>().FirstOrDefault(entity =>
                entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID &&
                entity.GetPersonData(VMPersonDataVariable.NeighborId) == persistedWorker)
                ?? throw new InvalidDataException("Career absence save lost its worker");
            if (avatar.GetPersonData(VMPersonDataVariable.JobPromotionLevel) != finalLevel ||
                avatar.GetPersonData(VMPersonDataVariable.JobPerformance) != finalPerformance)
                throw new InvalidDataException("Native save/load lost the missed-shift career penalty");
        }
        finally
        {
            if (File.Exists(savePath)) File.Delete(savePath);
        }

        return new
        {
            household = family.ChunkID,
            worker = persistedWorker,
            jobType,
            startHour = level.StartTime,
            simulatedFrom = $"{startMinute / 60:D2}:{startMinute % 60:D2}",
            simulatedThrough = $"{clock.Hours:D2}:{clock.Minutes:D2}",
            cancelledInteractions = cancelledNames.Order().ToArray(),
            awayTransitionObserved = sawAwayFlag,
            initialLevel,
            finalLevel,
            initialPerformance = seededPerformance,
            finalPerformance,
            budgetChange,
            dialogResponses,
            events = dialogs.ToArray(),
            vmUpdates = updateCount,
            missedShiftNoPayVerified = true,
            penaltyObserved,
            careerSaveLoadVerified = true,
            session
        };
    }

    internal static bool IsWorkDeparture(VMQueuedAction action, VMAvatar worker)
    {
        if (action.Callee == null || action.Callee == worker) return false;
        var name = action.Name ?? string.Empty;
        var objectName = action.Callee.Object?.OBJ?.ChunkLabel ?? action.Callee.ToString() ?? string.Empty;
        return name.Contains("work", StringComparison.OrdinalIgnoreCase) ||
               name.Contains("school", StringComparison.OrdinalIgnoreCase) ||
               objectName.Contains("carpool", StringComparison.OrdinalIgnoreCase);
    }
}
