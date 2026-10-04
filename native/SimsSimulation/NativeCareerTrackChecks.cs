using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Model;
using FSO.SimAntics.NetPlay.Model.Commands;

/// <summary>
/// Career coverage beyond one shift: a static audit of every work.iff track, and a run of consecutive missed shifts
/// through the original carpool and career scripts to observe demotion or firing.
/// </summary>
internal static class NativeCareerTrackChecks
{
    public static object Audit()
    {
        var jobs = Content.Get().Jobs.JobResource.List<CARR>().Where(job => job.ChunkID > 0).OrderBy(job => job.ChunkID).ToArray();
        if (jobs.Length == 0) throw new InvalidDataException("work.iff contains no career tracks");
        var tracks = new List<object>();
        foreach (var job in jobs)
        {
            if (string.IsNullOrWhiteSpace(job.Name)) throw new InvalidDataException($"Career {job.ChunkID} has no name");
            var levels = job.JobLevels ?? throw new InvalidDataException($"Career {job.Name} has no levels");
            if (levels.Length < 2) throw new InvalidDataException($"Career {job.Name} has fewer than two levels");
            var previousSalary = -1;
            var untitledLevels = 0;
            for (var index = 0; index < levels.Length; index++)
            {
                var level = levels[index];
                string where() => $"{job.Name} level {index}";
                if (level.Salary < previousSalary) throw new InvalidDataException($"{where()} pays less than the level below it");
                previousSalary = level.Salary;
                if (level.StartTime < 0 || level.StartTime > 24 || level.EndTime < 0 || level.EndTime > 24)
                    throw new InvalidDataException($"{where()} has an invalid schedule {level.StartTime}-{level.EndTime}");
                if (level.MinRequired.Any(value => value < 0)) throw new InvalidDataException($"{where()} has a negative requirement");
                if (string.IsNullOrWhiteSpace(level.JobName)) untitledLevels++;
            }
            tracks.Add(new { id = job.ChunkID, job.Name, levels = levels.Length, topSalary = levels[^1].Salary, untitledLevels,
                firstShift = $"{levels[0].StartTime}-{levels[0].EndTime}" });
        }
        return new { tracks = tracks.Count, details = tracks, careerTrackAuditPassed = true };
    }

    public static object RunMissedShifts(VM vm, int days = 8)
    {
        var family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Career check has no active household");
        var worker = vm.Entities.OfType<VMAvatar>().FirstOrDefault(entity =>
            entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID &&
            entity.GetPersonData(VMPersonDataVariable.PersonsAge) >= 18 && entity.GetPersonData(VMPersonDataVariable.JobType) > 0)
            ?? throw new InvalidDataException("Career check household has no employed adult");
        vm.SetGlobalValue(3, worker.ObjectID);
        var job = Content.Get().Jobs.GetJob(unchecked((ushort)worker.GetPersonData(VMPersonDataVariable.JobType)))!;
        var history = new List<object>();
        var initialLevel = worker.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
        var initialType = worker.GetPersonData(VMPersonDataVariable.JobType);
        worker.SetPersonData(VMPersonDataVariable.JobPerformance, 10);
        var clock = vm.Context.Clock;
        var lowestPerformance = worker.GetPersonData(VMPersonDataVariable.JobPerformance);
        var cancelled = new HashSet<ushort>();
        for (var day = 1; day <= days; day++)
        {
            var level = worker.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
            if (worker.GetPersonData(VMPersonDataVariable.JobType) == 0) break;
            var schedule = job.JobLevels[Math.Clamp((int)level, 0, job.JobLevels.Length - 1)];
            var start = Math.Max(6 * 60, schedule.StartTime * 60 - 65);
            var target = Math.Min(23 * 60, (schedule.EndTime + 1) * 60);
            clock.Hours = start / 60;
            clock.Minutes = start % 60;
            clock.MinuteFractions = 0;
            var outcome = NativeDailyLifeChecks.Advance(vm, worker, 12000, () =>
            {
                foreach (var action in worker.Thread.Queue.ToArray())
                    if (NativeCareerAbsenceChecks.IsWorkDeparture(action, worker) && cancelled.Add(action.UID))
                        new VMNetInteractionCancelCmd { ActionUID = action.UID }.Execute(vm, worker);
                return false;
            }, () => clock.Hours * 60 + clock.Minutes >= target);
            if (outcome.Errors.Length > 0) throw new InvalidDataException("A missed shift raised a SimAntics exception: " + outcome.Errors[0]);
            var performance = worker.GetPersonData(VMPersonDataVariable.JobPerformance);
            lowestPerformance = Math.Min(lowestPerformance, performance);
            history.Add(new { day, level = worker.GetPersonData(VMPersonDataVariable.JobPromotionLevel), performance, jobType = worker.GetPersonData(VMPersonDataVariable.JobType) });
        }
        var finalLevel = worker.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
        var finalType = worker.GetPersonData(VMPersonDataVariable.JobType);
        if (cancelled.Count == 0) throw new InvalidDataException("The original carpool never queued work to cancel");
        if (finalType == initialType && finalLevel > initialLevel) throw new InvalidDataException("Missing work promoted the worker");
        var penaltyObserved = finalType != initialType || finalLevel < initialLevel || worker.GetPersonData(VMPersonDataVariable.JobPerformance) < 10;
        return new
        {
            worker = worker.GetPersonData(VMPersonDataVariable.NeighborId),
            initialLevel, finalLevel, initialType, finalType,
            fired = finalType == 0,
            demoted = finalType == initialType && finalLevel < initialLevel,
            lowestPerformance, daysSimulated = history.Count, history,
            penaltyObserved,
            note = penaltyObserved ? "A missed-shift penalty occurred" : "Cancelling the carpool work interaction produced no penalty; the demotion path needs another trigger"
        };
    }
}
