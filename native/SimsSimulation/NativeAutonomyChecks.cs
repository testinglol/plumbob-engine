using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;

internal static class NativeAutonomyChecks
{
    public static object Run(VM vm)
    {
        var avatar = vm.Entities.OfType<VMAvatar>().FirstOrDefault(item =>
            vm.TS1State.CurrentFamily != null && item.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == vm.TS1State.CurrentFamily.ChunkID)
            ?? throw new InvalidDataException("Autonomy checks require an active household Sim");
        var originalThread = avatar.Thread;
        var originalMotives = Enumerable.Range(0, 16).Select(index => avatar.GetMotiveData((VMMotive)index)).ToArray();
        var originalHideInteraction = avatar.ObjectData[(int)VMStackObjectVariable.HideInteraction];
        var thread = new VMThread(vm.Context, avatar, 1);
        try
        {
            avatar.Thread = thread;
            foreach (var motive in new[] { VMMotive.Hunger, VMMotive.Comfort, VMMotive.Hygiene, VMMotive.Bladder,
                VMMotive.Energy, VMMotive.Fun, VMMotive.Social, VMMotive.Mood })
                avatar.SetMotiveData(motive, -100);

            var frame = new VMStackFrame { Thread = thread, Caller = avatar, Callee = avatar, StackObject = avatar };
            var result = new VMFindBestAction().Execute(frame, new VMFindBestActionOperand());
            var selected = thread.Queue.FirstOrDefault(action => action.Priority == (short)VMQueuePriority.Autonomous);
            if (result != VMPrimitiveExitCode.GOTO_TRUE || selected == null)
                throw new InvalidDataException("A household Sim with depleted needs did not queue an autonomous interaction");
            return new
            {
                accessibleObjects = vm.Context.ObjectQueries.WithAutonomy.Count(),
                selected.Name,
                selected.InteractionNumber,
                parameter = selected.Args?.FirstOrDefault() ?? 0,
                autonomousActionQueued = true
            };
        }
        finally
        {
            avatar.ReplaceMotiveData(originalMotives);
            avatar.ObjectData[(int)VMStackObjectVariable.HideInteraction] = originalHideInteraction;
            avatar.Thread = originalThread;
        }
    }
}
