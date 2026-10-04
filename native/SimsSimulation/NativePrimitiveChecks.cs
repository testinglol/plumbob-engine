using System.Buffers.Binary;
using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Engine.Scopes;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;

internal static class NativePrimitiveChecks
{
    internal static object Run(VM vm)
    {
        var checks = 0;
        void Require(bool condition, string message)
        {
            if (!condition) throw new InvalidDataException(message);
            checks++;
        }

        var tutorialBytes = new byte[8];
        tutorialBytes[0] = 1;
        var tutorial = new VMTS1TutorialOperand();
        tutorial.Read(tutorialBytes);
        Require(tutorial.Mode == 1, "TS1 tutorial mode did not decode from operand byte 0");

        var motivesBytes = new byte[8];
        BinaryPrimitives.WriteUInt16LittleEndian(motivesBytes.AsSpan(4, 2), 1);
        BinaryPrimitives.WriteUInt16LittleEndian(motivesBytes.AsSpan(6, 2), 2);
        var motives = new VMFindWorstMotivesOperand();
        motives.Read(motivesBytes);
        Require(motives.Target == 1 && motives.MotiveType == 2, "Worst-motive target or type operand fields were decoded incorrectly");

        var ranked = VMFindWorstMotives.RankValues([45, 30, 25, 20, 15, 10, 5, 0]);
        Require(ranked.SequenceEqual(new short[] { 15, 14, 13, 9, 8 }), "Worst motives were not stored from lowest value to highest");

        var effectBytes = new byte[8];
        effectBytes[0] = 2;
        effectBytes[1] = (byte)VMVariableScope.Temps;
        BinaryPrimitives.WriteInt16LittleEndian(effectBytes.AsSpan(2, 2), -7);
        effectBytes[4] = 0xff;
        var effect = new VMUIEffectOperand();
        effect.Read(effectBytes);
        Require(effect.Mode == 2 && effect.Scope == VMVariableScope.Temps && effect.Data == -7 && effect.Flags == 0xff,
            "UI effect mode, scope, data, or flags were decoded incorrectly");

        var primary = VMUIEffect.BuildRequests(0, 42, 1);
        Require(primary.Select(request => request.Method).SequenceEqual(new[] { VMUIEffectMethod.BitmapButton, VMUIEffectMethod.PortraitButton }) &&
            primary.All(request => request.Value == 42 && request.Flags == 1), "UI effect mode 0 did not dispatch both original calls");
        Require(VMUIEffect.BuildRequests(1, 42, 0).Select(request => request.Method).SequenceEqual(new[] { VMUIEffectMethod.PortraitButton }),
            "UI effect mode 1 did not dispatch only the portrait call");
        Require(VMUIEffect.BuildRequests(2, 42, 0).Select(request => request.Method).SequenceEqual(new[] { VMUIEffectMethod.RelationshipWidget }),
            "UI effect mode 2 did not dispatch only the relationship call");
        Require(VMUIEffect.BuildRequests(3, 42, 0).Length == 0, "Unknown UI effect mode was not a no-op");
        var unhandled = new List<VMUIEffectRequest>();
        VMUIEffect.DispatchRequests(primary, _ => VMUIEffectDispatchResult.Applied, unhandled.Add);
        Require(unhandled.Count == 0, "Handled UI requests were reported as unhandled");
        VMUIEffect.DispatchRequests(primary, _ => VMUIEffectDispatchResult.Unhandled, unhandled.Add);
        Require(unhandled.Count == 2, "Unimplemented UI requests were not surfaced to the diagnostic callback");
        VMUIEffect.DispatchRequests(primary, _ => VMUIEffectDispatchResult.TargetMissing, unhandled.Add);
        Require(unhandled.Count == 2, "Missing original UI targets were reported as unimplemented requests");

        var avatars = vm.Entities.OfType<VMAvatar>().Take(2).ToArray();
        if (avatars.Length != 2) throw new InvalidDataException("Primitive checks require two resident avatars");
        var caller = avatars[0];
        var stackAvatar = avatars[1];
        var thread = caller.Thread ?? throw new InvalidDataException("Primitive check caller has no VM thread");
        var autonomyOptions = new[]
        {
            new VMPieMenuInteraction { Param0 = 12 },
            new VMPieMenuInteraction { Param0 = 27 }
        };
        var motiveAdChanges = new Dictionary<int, short> { [(1 << 16) | (int)VMMotive.Energy] = -10 };
        VMThread.AttachMotiveAdChanges(autonomyOptions, motiveAdChanges);
        var autonomyCandidates = new List<VMPieMenuInteraction>();
        VMFindBestAction.AddScoredAlternative(autonomyCandidates, autonomyOptions[0], stackAvatar, 0.25f);
        VMFindBestAction.AddScoredAlternative(autonomyCandidates, autonomyOptions[1], stackAvatar, 0.5f);
        Require(autonomyCandidates.Count == 2 && autonomyCandidates.Select(item => item.Param0).SequenceEqual(new short[] { 12, 27 }) &&
            autonomyCandidates.Select(item => item.Score).SequenceEqual(new[] { 0.25f, 0.5f }) &&
            autonomyCandidates.All(item => ReferenceEquals(item.Callee, stackAvatar) &&
                ReferenceEquals(item.MotiveAdChanges, motiveAdChanges)),
            "Autonomous scoring discarded action-string alternatives or their motive-ad changes");
        var frame = new VMStackFrame { Thread = thread, Caller = caller, Callee = caller, StackObject = stackAvatar };
        var candidates = new[] { VMMotive.Energy, VMMotive.Comfort, VMMotive.Hunger, VMMotive.Hygiene,
            VMMotive.Bladder, VMMotive.Room, VMMotive.Social, VMMotive.Fun };
        var callerMotives = candidates.Select(caller.GetMotiveData).ToArray();
        var stackMotives = candidates.Select(stackAvatar.GetMotiveData).ToArray();
        var originalTemps = (short[])thread.TempRegisters.Clone();
        var simulationContext = vm.Context;
        var originalTutorialOwner = simulationContext.TutorialOwner;
        var originalEffectHandler = simulationContext.UIEffectHandler;
        var originalUnhandledHandler = simulationContext.UIEffectUnhandled;
        try
        {
            var callerValues = new short[] { 45, 30, 25, 20, 15, 10, 5, 0 };
            var stackValues = new short[] { 0, 5, 10, 15, 20, 25, 30, 35 };
            for (var i = 0; i < candidates.Length; i++)
            {
                caller.SetMotiveData(candidates[i], callerValues[i]);
                stackAvatar.SetMotiveData(candidates[i], stackValues[i]);
            }
            for (var i = 0; i < thread.TempRegisters.Length; i++) thread.TempRegisters[i] = (short)(1000 + i);

            var worst = new VMFindWorstMotives();
            Require(worst.Execute(frame, new VMFindWorstMotivesOperand { Target = 3, MotiveType = 0 }) == VMPrimitiveExitCode.GOTO_TRUE &&
                thread.TempRegisters.Take(5).SequenceEqual(new short[] { 15, 14, 13, 9, 8 }),
                "Worst-motive primitive did not rank caller motives or preserve original unknown-target fallback");
            Require(thread.TempRegisters.Skip(5).SequenceEqual(Enumerable.Range(5, thread.TempRegisters.Length - 5).Select(index => (short)(1000 + index))),
                "Worst-motive primitive changed temps outside Temp0 through Temp4");

            Require(worst.Execute(frame, new VMFindWorstMotivesOperand { Target = 1, MotiveType = 2 }) == VMPrimitiveExitCode.GOTO_TRUE &&
                thread.TempRegisters.Take(5).SequenceEqual(new short[] { 5, 6, 7, 8, 9 }),
                "Worst-motive primitive did not rank the stack avatar's motives");
            RequireThrows(() => worst.Execute(frame, new VMFindWorstMotivesOperand { Target = 2, MotiveType = 0 }), "Target selector 2 did not fail");
            RequireThrows(() => worst.Execute(frame, new VMFindWorstMotivesOperand { Target = 0, MotiveType = 3 }), "Motive type 3 did not fail");
            var nonPerson = vm.Entities.FirstOrDefault(entity => entity is not VMAvatar);
            if (nonPerson == null) throw new InvalidDataException("Primitive checks require a non-person entity");
            frame.StackObject = nonPerson;
            RequireThrows(() => worst.Execute(frame, new VMFindWorstMotivesOperand { Target = 1, MotiveType = 0 }), "Non-person target did not fail");
            frame.StackObject = stackAvatar;

            var tutorialPrimitive = new VMTS1Tutorial();
            if (originalTutorialOwner != null)
            {
                var releaseFrame = new VMStackFrame { Thread = thread, Caller = originalTutorialOwner, Callee = originalTutorialOwner };
                Require(tutorialPrimitive.Execute(releaseFrame, new VMTS1TutorialOperand { Mode = 1 }) == VMPrimitiveExitCode.GOTO_TRUE,
                    "Could not temporarily release the existing tutorial owner");
            }
            Require(tutorialPrimitive.Execute(frame, new VMTS1TutorialOperand { Mode = 0 }) == VMPrimitiveExitCode.GOTO_TRUE &&
                ReferenceEquals(simulationContext.TutorialOwner, caller), "Tutorial primitive did not claim an empty owner slot");
            var otherFrame = new VMStackFrame { Thread = thread, Caller = stackAvatar, Callee = stackAvatar, StackObject = caller };
            Require(tutorialPrimitive.Execute(otherFrame, new VMTS1TutorialOperand { Mode = 0 }) == VMPrimitiveExitCode.GOTO_FALSE &&
                tutorialPrimitive.Execute(otherFrame, new VMTS1TutorialOperand { Mode = 1 }) == VMPrimitiveExitCode.GOTO_FALSE,
                "Tutorial primitive did not reject a second owner and its release");
            Require(tutorialPrimitive.Execute(frame, new VMTS1TutorialOperand { Mode = 1 }) == VMPrimitiveExitCode.GOTO_TRUE &&
                simulationContext.TutorialOwner == null, "Tutorial primitive did not release its owner");

            var uiCalls = new List<VMUIEffectRequest>();
            simulationContext.UIEffectHandler = request => { uiCalls.Add(request); return VMUIEffectDispatchResult.Applied; };
            thread.TempRegisters[4] = -7;
            var effectFrame = new VMStackFrame { Thread = thread, Caller = caller, Callee = caller, StackObject = stackAvatar };
            var effectResult = new VMUIEffect().Execute(effectFrame, new VMUIEffectOperand
            {
                Mode = 2, Scope = VMVariableScope.Temps, Data = 4, Flags = 0xff
            });
            Require(effectResult == VMPrimitiveExitCode.GOTO_TRUE && uiCalls.Count == 1 &&
                uiCalls[0] == new VMUIEffectRequest(VMUIEffectMethod.RelationshipWidget, -7, 1),
                "UI-effect primitive did not resolve its Temp scope, mask flags, and capture its typed request");
        }
        finally
        {
            for (var i = 0; i < candidates.Length; i++)
            {
                caller.SetMotiveData(candidates[i], callerMotives[i]);
                stackAvatar.SetMotiveData(candidates[i], stackMotives[i]);
            }
            Array.Copy(originalTemps, thread.TempRegisters, originalTemps.Length);
            simulationContext.UIEffectHandler = originalEffectHandler;
            simulationContext.UIEffectUnhandled = originalUnhandledHandler;
            if (simulationContext.TutorialOwner != null)
                new VMTS1Tutorial().Execute(new VMStackFrame { Thread = thread, Caller = simulationContext.TutorialOwner, Callee = simulationContext.TutorialOwner },
                    new VMTS1TutorialOperand { Mode = 1 });
            if (originalTutorialOwner != null)
                new VMTS1Tutorial().Execute(new VMStackFrame { Thread = thread, Caller = originalTutorialOwner, Callee = originalTutorialOwner },
                    new VMTS1TutorialOperand { Mode = 0 });
        }
        Require(candidates.Select(caller.GetMotiveData).SequenceEqual(callerMotives) &&
            candidates.Select(stackAvatar.GetMotiveData).SequenceEqual(stackMotives) &&
            thread.TempRegisters.SequenceEqual(originalTemps), "Primitive execution did not restore motives and temp registers");
        Require(ReferenceEquals(simulationContext.TutorialOwner, originalTutorialOwner) &&
            ReferenceEquals(simulationContext.UIEffectHandler, originalEffectHandler) &&
            ReferenceEquals(simulationContext.UIEffectUnhandled, originalUnhandledHandler),
            "Primitive execution did not restore context callbacks and tutorial ownership");

        return new { checks, worstMotiveIDs = ranked, uiEffectMode0Calls = primary.Length, unknownUiModeIsNoOp = true,
            unhandledUiCallsReported = unhandled.Count, primitiveExecution = true, autonomyVariantCount = autonomyCandidates.Count,
            motiveAdChangesPreserved = autonomyCandidates.All(item => ReferenceEquals(item.MotiveAdChanges, motiveAdChanges)),
            motiveValuesRestored = true,
            frontendPresentationVerified = false };
    }

    private static void RequireThrows(Action action, string message)
    {
        try { action(); }
        catch (VMSimanticsException) { return; }
        throw new InvalidDataException(message);
    }
}
