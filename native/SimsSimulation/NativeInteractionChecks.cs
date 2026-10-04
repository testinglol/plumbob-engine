using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.SimAntics.NetPlay.Model.Commands;
using FSO.SimAntics.Primitives;

internal static class NativeInteractionChecks
{
    private sealed record NeedOutcome(string Interaction, string ObjectName, short InitialNeed, short FinalNeed,
        bool Moved, bool SawActionQueued, bool Completed, int Updates, string[] DialogTypes);
    private sealed record SkillOutcome(string Interaction, string ObjectName, short InitialSkill, short FinalSkill,
        bool Moved, bool SawActionQueued, bool Completed, int Updates, string[] DialogTypes);

    public static object Run(VM vm)
    {
        var family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Interaction check has no active household");
        var avatar = vm.Entities.OfType<VMAvatar>().FirstOrDefault(entity =>
            entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID &&
            entity.GetPersonData(VMPersonDataVariable.PersonsAge) >= 18)
            ?? throw new InvalidDataException("Interaction check has no adult household Sim");
        var originalBladder = avatar.GetMotiveData(VMMotive.Bladder);
        var originalHunger = avatar.GetMotiveData(VMMotive.Hunger);
        var originalCooking = avatar.GetPersonData(VMPersonDataVariable.CookingSkill);
        vm.SetGlobalValue(3, avatar.ObjectID);
        try
        {
            var toilet = vm.Entities.OfType<VMGameObject>().FirstOrDefault(entity =>
                entity.Name.Contains("toilet", StringComparison.OrdinalIgnoreCase))
                ?? throw new InvalidDataException("Interaction check lot has no toilet");
            var fridge = vm.Entities.OfType<VMGameObject>().FirstOrDefault(entity =>
                entity.Name.Contains("refrigerator", StringComparison.OrdinalIgnoreCase))
                ?? throw new InvalidDataException("Interaction check lot has no refrigerator");
            var toiletUse = RunNeedAction(vm, avatar, toilet, "Use", VMMotive.Bladder, -80, -50, true);
            var snack = RunNeedAction(vm, avatar, fridge, "Have A Snack", VMMotive.Hunger, -80, -70, false);
            var bookcase = vm.Entities.OfType<VMGameObject>().FirstOrDefault(entity =>
                entity.Name.Contains("bookcase", StringComparison.OrdinalIgnoreCase))
                ?? throw new InvalidDataException("Interaction check lot has no bookcase");
            var cookingStudy = RunSkillAction(vm, avatar, bookcase, "Study Cooking", VMPersonDataVariable.CookingSkill);
            return new
            {
                worker = avatar.GetPersonData(VMPersonDataVariable.NeighborId),
                needInteractions = new[] { toiletUse, snack },
                skillInteraction = cookingStudy,
                originalInteractionsCompleted = true
            };
        }
        finally
        {
            vm.SpeedMultiplier = 0;
            avatar.SetMotiveData(VMMotive.Bladder, originalBladder);
            avatar.SetMotiveData(VMMotive.Hunger, originalHunger);
            avatar.SetPersonData(VMPersonDataVariable.CookingSkill, originalCooking);
        }
    }

    private static NeedOutcome RunNeedAction(VM vm, VMAvatar avatar, VMGameObject target, string interactionName,
        VMMotive motive, short startingNeed, short targetNeed, bool requireStanding)
    {
        var startPosition = avatar.Position;
        avatar.SetMotiveData(motive, startingNeed);
        var interaction = target.GetPieMenu(vm, avatar, false, true).FirstOrDefault(entry => entry.Name == interactionName)
            ?? throw new InvalidDataException($"Original {target.Name} pie menu does not offer {interactionName}");
        if (!new VMNetInteractionCmd
        {
            CallerID = avatar.ObjectID,
            CalleeID = target.ObjectID,
            Interaction = checked((ushort)interaction.ID),
            Param0 = interaction.Param0,
            Global = interaction.Global
        }.Execute(vm, avatar))
            throw new InvalidDataException($"Original {target.Name} interaction {interactionName} could not be queued");

        var sawActionQueued = false;
        var actionStillQueued = false;
        var completed = false;
        var bestNeed = avatar.GetMotiveData(motive);
        var dialogTypes = new HashSet<VMDialogType>();
        var simulationErrors = new List<string>();
        var updates = 0;
        vm.SpeedMultiplier = 10;
        vm.LastSpeedMultiplier = 10;
        void CaptureDialog(VMDialogInfo? info)
        {
            if (info?.Title == "SimAntics Exception!") simulationErrors.Add(info.Message ?? "Unknown SimAntics exception");
        }
        vm.OnDialog += CaptureDialog;
        try
        {
            while (updates < 10000 && !completed)
            {
                if (vm.GlobalBlockingDialog != null)
                {
                    var state = vm.GlobalBlockingDialog.Thread.BlockingState as VMDialogResult
                        ?? throw new InvalidDataException("Interaction check encountered a non-dialog blocking state");
                    if (state.Type == VMDialogType.Sims1Tutorial)
                        throw new InvalidDataException("Interaction check reached an unexpected tutorial flow");
                    dialogTypes.Add(state.Type);
                    var code = state.Type switch
                    {
                        VMDialogType.YesNo => (byte)1,
                        VMDialogType.YesNoCancel => (byte)2,
                        _ => (byte)0
                    };
                    if (!new VMNetDialogResponseCmd { ResponseCode = code, ResponseText = string.Empty }.Execute(vm, avatar))
                        throw new InvalidDataException("Interaction check could not dismiss an original modal dialog");
                    continue;
                }

                vm.Update();
                updates++;
                bestNeed = Math.Max(bestNeed, avatar.GetMotiveData(motive));
                actionStillQueued = avatar.Thread.Queue.Any(action => action.Name == interactionName && action.Callee == target);
                sawActionQueued |= actionStillQueued;
                completed = sawActionQueued && bestNeed >= targetNeed && !actionStillQueued &&
                    (!requireStanding || avatar.GetPersonData(VMPersonDataVariable.Posture) == 0);
            }

            if (bestNeed < targetNeed)
                throw new TimeoutException($"Original {interactionName} interaction did not improve {motive}; best={bestNeed}, queued={sawActionQueued}, stillQueued={actionStillQueued}, actions={string.Join("|", avatar.Thread.Queue.Select(action => action.Name + "@" + action.Callee?.Name))}, dialogs={string.Join("|", dialogTypes)}");
            if (!sawActionQueued)
                throw new InvalidDataException($"Original {interactionName} interaction never appeared in the Sim's action queue");
            if (!completed)
                throw new TimeoutException($"Original {interactionName} interaction did not finish and clear from the action queue");
            if (simulationErrors.Count > 0)
                throw new InvalidDataException("Original interaction raised a SimAntics exception: " + simulationErrors[0]);
            return new NeedOutcome(interaction.Name, target.Name, startingNeed, avatar.GetMotiveData(motive),
                avatar.Position != startPosition, sawActionQueued, completed, updates,
                dialogTypes.Select(type => type.ToString()).Order().ToArray());
        }
        finally
        {
            vm.OnDialog -= CaptureDialog;
            vm.SpeedMultiplier = 0;
        }
    }

    private static SkillOutcome RunSkillAction(VM vm, VMAvatar avatar, VMGameObject target, string interactionName,
        VMPersonDataVariable skill)
    {
        var startPosition = avatar.Position;
        var initialSkill = avatar.GetPersonData(skill);
        avatar.SetPersonData(skill, 0);
        var interaction = target.GetPieMenu(vm, avatar, false, true).FirstOrDefault(entry => entry.Name == interactionName)
            ?? throw new InvalidDataException($"Original {target.Name} pie menu does not offer {interactionName}");
        if (!new VMNetInteractionCmd
        {
            CallerID = avatar.ObjectID,
            CalleeID = target.ObjectID,
            Interaction = checked((ushort)interaction.ID),
            Param0 = interaction.Param0,
            Global = interaction.Global
        }.Execute(vm, avatar))
            throw new InvalidDataException($"Original {target.Name} interaction {interactionName} could not be queued");

        var sawActionQueued = false;
        var actionStillQueued = false;
        var completed = false;
        var finalSkill = avatar.GetPersonData(skill);
        var dialogTypes = new HashSet<VMDialogType>();
        var simulationErrors = new List<string>();
        var updates = 0;
        vm.SpeedMultiplier = 10;
        vm.LastSpeedMultiplier = 10;
        void CaptureDialog(VMDialogInfo? info)
        {
            if (info?.Title == "SimAntics Exception!") simulationErrors.Add(info.Message ?? "Unknown SimAntics exception");
        }
        vm.OnDialog += CaptureDialog;
        try
        {
            while (updates < 20000 && !completed)
            {
                if (vm.GlobalBlockingDialog != null)
                {
                    var state = vm.GlobalBlockingDialog.Thread.BlockingState as VMDialogResult
                        ?? throw new InvalidDataException("Skill check encountered a non-dialog blocking state");
                    if (state.Type == VMDialogType.Sims1Tutorial)
                        throw new InvalidDataException("Skill check reached an unexpected tutorial flow");
                    dialogTypes.Add(state.Type);
                    var code = state.Type switch
                    {
                        VMDialogType.YesNo => (byte)1,
                        VMDialogType.YesNoCancel => (byte)2,
                        _ => (byte)0
                    };
                    if (!new VMNetDialogResponseCmd { ResponseCode = code, ResponseText = string.Empty }.Execute(vm, avatar))
                        throw new InvalidDataException("Skill check could not dismiss an original modal dialog");
                    continue;
                }

                vm.Update();
                updates++;
                finalSkill = avatar.GetPersonData(skill);
                actionStillQueued = avatar.Thread.Queue.Any(action => action.Name == interactionName && action.Callee == target);
                sawActionQueued |= actionStillQueued;
                completed = sawActionQueued && finalSkill > 0 && !actionStillQueued;
            }

            if (!sawActionQueued)
                throw new InvalidDataException($"Original {interactionName} interaction never appeared in the Sim's action queue");
            if (!completed)
                throw new TimeoutException($"Original {interactionName} interaction did not gain skill and clear from the action queue");
            if (simulationErrors.Count > 0)
                throw new InvalidDataException("Original skill interaction raised a SimAntics exception: " + simulationErrors[0]);
            return new SkillOutcome(interaction.Name, target.Name, initialSkill, finalSkill,
                avatar.Position != startPosition, sawActionQueued, completed, updates,
                dialogTypes.Select(type => type.ToString()).Order().ToArray());
        }
        finally { vm.SpeedMultiplier = 0; }
    }
}
