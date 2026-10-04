using FSO.Content;
using FSO.SimAntics;
using FSO.SimAntics.Model;

/// <summary>
/// Runs two complete shifts through the original carpool and career scripts with the same mood and performance. The
/// first leaves the worker below the next level's work.iff skill requirements and must not promote; the second meets
/// them and must promote, showing the skills alone decided the outcome.
/// </summary>
internal static class NativeCareerRequirementChecks
{
    // work.iff requirement slots 1–6, in the order the original career panel lists them; slot 0 is family friends.
    private static readonly VMPersonDataVariable[] RequirementSkills =
    [
        VMPersonDataVariable.CookingSkill, VMPersonDataVariable.MechanicalSkill, VMPersonDataVariable.CharismaSkill,
        VMPersonDataVariable.BodySkill, VMPersonDataVariable.LogicSkill, VMPersonDataVariable.CreativitySkill
    ];

    private const short SeededPerformance = 90;

    private sealed record ShiftResult(short LevelBefore, short LevelAfter, short PerformanceAfter, int Pay, bool Away,
        int Updates, string[] Dialogs);

    public static object Run(VM vm)
    {
        var family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Career requirement check has no active household");
        var worker = vm.Entities.OfType<VMAvatar>().FirstOrDefault(entity =>
            entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID &&
            entity.GetPersonData(VMPersonDataVariable.PersonsAge) >= 18 &&
            entity.GetPersonData(VMPersonDataVariable.JobType) > 0)
            ?? throw new InvalidDataException("Career requirement check household has no employed adult");
        vm.SetGlobalValue(3, worker.ObjectID);
        var jobType = worker.GetPersonData(VMPersonDataVariable.JobType);
        var job = Content.Get().Jobs.GetJob(unchecked((ushort)jobType));
        if (job?.JobLevels == null || job.JobLevels.Length < 2)
            throw new InvalidDataException("Career requirement check worker has no valid work.iff career track");

        // Use the worker's own level when its next level needs a skill; otherwise the lowest such level on the track.
        bool NeedsSkill(int level) => level + 1 < job.JobLevels.Length &&
            job.JobLevels[level + 1].MinRequired.Skip(1).Take(RequirementSkills.Length).Any(value => value > 0);
        var originalLevel = worker.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
        var testLevel = (short)Enumerable.Range(0, job.JobLevels.Length - 1)
            .OrderBy(level => level < originalLevel ? 1 : 0).ThenBy(level => level)
            .FirstOrDefault(NeedsSkill, -1);
        if (testLevel < 0) throw new InvalidDataException($"Career {job.Name} has no level whose promotion requires a skill");
        var schedule = job.JobLevels[testLevel];
        if (schedule.StartTime is < 1 or > 22 || schedule.EndTime <= schedule.StartTime || schedule.EndTime > 23)
            throw new InvalidDataException($"Career {job.Name} level {testLevel} has an unsupported work schedule");
        var next = job.JobLevels[testLevel + 1];
        var required = next.MinRequired.Skip(1).Take(RequirementSkills.Length).ToArray();
        worker.SetPersonData(VMPersonDataVariable.JobPromotionLevel, testLevel);

        // Friends are not under test: meet that requirement in both shifts so only the skills differ.
        var originalFriends = family.FamilyFriends;
        family.FamilyFriends = Math.Max(originalFriends, next.MinRequired[0]);

        var startMinute = Math.Max(6 * 60, schedule.StartTime * 60 - 65);
        var targetMinute = Math.Min(23 * 60, (schedule.EndTime + 1) * 60);
        var clock = vm.Context.Clock;

        ShiftResult Shift(Func<int, short> skill)
        {
            for (var index = 0; index < RequirementSkills.Length; index++)
                worker.SetPersonData(RequirementSkills[index], skill(index));
            foreach (var motive in new[] { VMMotive.Hunger, VMMotive.Comfort, VMMotive.Energy, VMMotive.Hygiene,
                         VMMotive.Bladder, VMMotive.Fun, VMMotive.Social, VMMotive.Room })
                worker.SetMotiveData(motive, 90);
            worker.SetPersonData(VMPersonDataVariable.JobPerformance, SeededPerformance);
            clock.Hours = startMinute / 60;
            clock.Minutes = startMinute % 60;
            clock.MinuteFractions = 0;
            var levelBefore = worker.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
            var budget = family.Budget;
            var away = false;
            var dialogs = new List<string>();
            void Capture(VMDialogInfo? info)
            {
                if (info != null && info.Block) dialogs.Add($"{info.Operand.Type}:{info.Title}:{info.Message}");
            }
            vm.OnDialog += Capture;
            NativeDailyLifeChecks.AdvanceResult outcome;
            try
            {
                outcome = NativeDailyLifeChecks.Advance(vm, worker, 12000, () => false, () =>
                {
                    away |= worker.GetPersonData(VMPersonDataVariable.TS1AtWorkSchool) != 0 || !vm.Entities.Contains(worker);
                    return clock.Hours * 60 + clock.Minutes >= targetMinute;
                });
            }
            finally { vm.OnDialog -= Capture; }
            if (clock.Hours * 60 + clock.Minutes < targetMinute)
                throw new TimeoutException($"Career requirement shift stopped at {clock.Hours:D2}:{clock.Minutes:D2} after {outcome.Updates} updates");
            if (outcome.Errors.Length > 0)
                throw new InvalidDataException("A career requirement shift raised a SimAntics exception: " + outcome.Errors[0]);
            if (!vm.Entities.Contains(worker))
                throw new InvalidDataException($"The worker had not returned from the shift by {clock.Hours:D2}:{clock.Minutes:D2}");
            return new ShiftResult(levelBefore, worker.GetPersonData(VMPersonDataVariable.JobPromotionLevel),
                worker.GetPersonData(VMPersonDataVariable.JobPerformance), family.Budget - budget, away, outcome.Updates,
                dialogs.ToArray());
        }

        ShiftResult unqualified, qualified;
        try
        {
            unqualified = Shift(_ => 0);
            if (!unqualified.Away || unqualified.Pay <= 0)
                throw new InvalidDataException($"The unqualified worker did not complete a paid shift; away={unqualified.Away}, pay={unqualified.Pay}");
            if (unqualified.LevelAfter > unqualified.LevelBefore)
                throw new InvalidDataException($"The original career scripts promoted a worker without the required skills; level={unqualified.LevelBefore}->{unqualified.LevelAfter}, required={string.Join(",", required)}");

            // Control shift on the following day: the same mood and performance, now with every required skill.
            clock.DayOfMonth = clock.DayOfMonth % 28 + 1;
            worker.SetPersonData(VMPersonDataVariable.JobPromotionLevel, testLevel);
            qualified = Shift(index => (short)Math.Clamp(required[index], 0, 1000));
            if (!qualified.Away || qualified.Pay <= 0)
                throw new InvalidDataException($"The qualified worker did not complete a paid shift; away={qualified.Away}, pay={qualified.Pay}");
            if (qualified.LevelAfter <= qualified.LevelBefore)
                throw new InvalidDataException($"The original career scripts did not promote a worker who met the requirements; level={qualified.LevelBefore}->{qualified.LevelAfter}, performance={SeededPerformance}->{qualified.PerformanceAfter}, required={string.Join(",", required)}, events={string.Join("|", qualified.Dialogs)}");
        }
        finally
        {
            vm.SpeedMultiplier = 0;
            family.FamilyFriends = originalFriends;
        }

        object Report(ShiftResult shift) => new
        {
            levelBefore = shift.LevelBefore,
            levelAfter = shift.LevelAfter,
            performanceBefore = SeededPerformance,
            performanceAfter = shift.PerformanceAfter,
            pay = shift.Pay,
            awayTransitionObserved = shift.Away,
            vmUpdates = shift.Updates,
            events = shift.Dialogs
        };

        return new
        {
            household = family.ChunkID,
            worker = worker.GetPersonData(VMPersonDataVariable.NeighborId),
            jobType,
            track = job.Name,
            originalLevel,
            testLevel,
            nextTitle = next.JobName,
            schedule = $"{schedule.StartTime}-{schedule.EndTime}",
            requiredFriends = next.MinRequired[0],
            requiredSkills = RequirementSkills.Select((skill, index) => new { skill = skill.ToString(), points = required[index] })
                .Where(item => item.points > 0).ToArray(),
            unqualified = Report(unqualified),
            qualified = Report(qualified),
            promotionBlockedWithoutSkills = true,
            promotionGrantedWithSkills = true
        };
    }
}
