using FSO.Content;
using FSO.SimAntics;
using FSO.SimAntics.Model;
using FSO.SimAntics.NetPlay.Model.Commands;
using FSO.SimAntics.Primitives;
using System.Reflection;

internal static class NativeCareerChecks
{
    public static object Run(VM vm, string workspace, string profile, string game, short house)
    {
        var family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Career check has no active household");
        var avatar = vm.Entities.OfType<VMAvatar>().FirstOrDefault(entity =>
            entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID &&
            entity.GetPersonData(VMPersonDataVariable.PersonsAge) >= 18 &&
            entity.GetPersonData(VMPersonDataVariable.JobType) > 0)
            ?? throw new InvalidDataException("Career check household has no employed adult");
        var jobType = avatar.GetPersonData(VMPersonDataVariable.JobType);
        var jobLevel = avatar.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
        var job = Content.Get().Jobs.GetJob(unchecked((ushort)jobType));
        if (job?.JobLevels == null || jobLevel < 0 || jobLevel >= job.JobLevels.Length)
            throw new InvalidDataException("Career check worker has no valid work.iff career level");
        var level = job.JobLevels[jobLevel];
        if (level.StartTime is < 1 or > 22 || level.EndTime <= level.StartTime || level.EndTime > 23)
            throw new InvalidDataException("Career check worker has an unsupported work schedule");

        var initialPerformance = avatar.GetPersonData(VMPersonDataVariable.JobPerformance);
        var initialLevel = jobLevel;
        var initialBudget = family.Budget;
        var startMinute = Math.Max(6 * 60, level.StartTime * 60 - 65);
        var targetMinute = (level.EndTime + 1) * 60;
        var clock = vm.Context.Clock;
        clock.Hours = startMinute / 60;
        clock.Minutes = startMinute % 60;
        clock.MinuteFractions = 0;
        vm.SpeedMultiplier = 10;
        vm.LastSpeedMultiplier = 10;

        var dialogResponses = 0;
        var dialogTypes = new HashSet<VMDialogType>();
        var dialogs = new List<string>();
        var sawAwayFlag = false;
        var sawWorkerAbsent = false;
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
                        ?? throw new InvalidDataException("Career check encountered a non-dialog blocking state");
                    dialogTypes.Add(state.Type);
                    var code = state.Type switch
                    {
                        VMDialogType.YesNo => (byte)1,
                        VMDialogType.YesNoCancel => (byte)2,
                        _ => (byte)0
                    };
                    if (!new VMNetDialogResponseCmd { ResponseCode = code, ResponseText = string.Empty }.Execute(vm, avatar))
                        throw new InvalidDataException("Career check could not dismiss an original modal dialog");
                    dialogResponses++;
                    continue;
                }

                vm.Update();
                updateCount++;
                sawAwayFlag |= avatar.GetPersonData(VMPersonDataVariable.TS1AtWorkSchool) != 0;
                sawWorkerAbsent |= !vm.Entities.Contains(avatar);
            }
        }
        finally { vm.OnDialog -= CaptureDialog; }

        if (clock.Hours * 60 + clock.Minutes < targetMinute)
            throw new TimeoutException("Career check did not advance through the scheduled work period");

        var finalLevel = avatar.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
        var finalPerformance = avatar.GetPersonData(VMPersonDataVariable.JobPerformance);
        var householdPay = family.Budget - initialBudget;
        if (!sawAwayFlag)
            throw new InvalidDataException("Original career scripts did not mark the household worker away during the shift");
        if (finalLevel <= initialLevel || finalPerformance <= initialPerformance)
            throw new InvalidDataException($"Original career scripts did not advance the worker after a complete shift; level={initialLevel}->{finalLevel}, performance={initialPerformance}->{finalPerformance}, householdPay={householdPay}, workEvents={string.Join("|", dialogs.Where(message => message.Contains("work", StringComparison.OrdinalIgnoreCase) || message.Contains("salary", StringComparison.OrdinalIgnoreCase) || message.Contains("promot", StringComparison.OrdinalIgnoreCase)))}");
        if (householdPay <= 0)
            throw new InvalidDataException("Original career scripts did not pay the household for its completed shift");

        var session = Path.Combine(workspace, "runtime", "native-sessions", "career-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(session);
        using var output = new StreamWriter(Path.Combine(session, "events.jsonl")) { AutoFlush = true };
        var server = new SimulationServer(vm, output, session, profile, game, house);
        const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
        object? Invoke(string method, params object[] args) => NativeServerReflection.Invoke(server, method, args);
        var saveSlot = "career-" + Guid.NewGuid().ToString("N");
        var savePath = Path.Combine(profile, "Saves", saveSlot + ".json");
        var persistedWorker = avatar.GetPersonData(VMPersonDataVariable.NeighborId);
        vm.SpeedMultiplier = 0;
        try
        {
            Invoke("Save", saveSlot);
            avatar.SetPersonData(VMPersonDataVariable.JobPromotionLevel, initialLevel);
            avatar.SetPersonData(VMPersonDataVariable.JobPerformance, initialPerformance);
            family.Budget = initialBudget;
            Invoke("Load", saveSlot);
            family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Career save lost its household");
            avatar = vm.Entities.OfType<VMAvatar>().FirstOrDefault(entity =>
                entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID &&
                entity.GetPersonData(VMPersonDataVariable.NeighborId) == persistedWorker)
                ?? throw new InvalidDataException("Career save lost its worker");
            if (family.Budget - initialBudget != householdPay ||
                avatar.GetPersonData(VMPersonDataVariable.JobPromotionLevel) != finalLevel ||
                avatar.GetPersonData(VMPersonDataVariable.JobPerformance) != finalPerformance)
                throw new InvalidDataException("Native save/load lost career promotion, performance, or household pay");
        }
        finally
        {
            if (File.Exists(savePath)) File.Delete(savePath);
        }

        return new
        {
            household = family.ChunkID,
            worker = avatar.GetPersonData(VMPersonDataVariable.NeighborId),
            jobType,
            startHour = level.StartTime,
            endHour = level.EndTime,
            simulatedFrom = $"{startMinute / 60:D2}:{startMinute % 60:D2}",
            simulatedThrough = $"{clock.Hours:D2}:{clock.Minutes:D2}",
            workPeriodAdvanced = true,
            awayTransitionObserved = sawAwayFlag,
            sawWorkerAbsent,
            initialLevel,
            finalLevel,
            initialPerformance,
            finalPerformance,
            householdPay,
            dialogResponses,
            workEvents = dialogs.Where(message => message.Contains("work", StringComparison.OrdinalIgnoreCase) ||
                message.Contains("salary", StringComparison.OrdinalIgnoreCase) || message.Contains("promot", StringComparison.OrdinalIgnoreCase)).ToArray(),
            dialogTypes = dialogTypes.Select(type => type.ToString()).Order().ToArray(),
            vmUpdates = updateCount,
            progressionVerified = true,
            careerSaveLoadVerified = true,
            session
        };
    }
}
