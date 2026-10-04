using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;

internal static class NativeGenericMode13Checks
{
    internal static object Run(VM vm)
    {
        var caller = vm.Entities.OfType<VMAvatar>().FirstOrDefault(avatar => avatar.Thread != null &&
            Array.Exists(avatar.Contained, entity => entity == null));
        if (caller == null) throw new InvalidDataException("Mode 13 check requires a runtime avatar with a VM thread");

        var emptySlot = Array.FindIndex(caller.Contained, entity => entity == null);
        var target = vm.Entities.FirstOrDefault(entity => entity != caller && entity.Container == null && entity is VMGameObject);
        if (target == null) throw new InvalidDataException("Mode 13 check could not find an uncontained object fixture");
        var originalTargetContainer = target.Container;
        var originalTargetContainerSlot = target.ContainerSlot;
        caller.Contained[emptySlot] = target;
        target.Container = caller;
        target.ContainerSlot = (short)emptySlot;

        var targetSlot = Array.IndexOf(caller.Contained, target);
        var emptyTestSlot = Enumerable.Range(0, caller.Contained.Length)
            .FirstOrDefault(index => index != targetSlot && caller.Contained[index] == null, -1);
        var thread = caller.Thread;
        var originalQueue = thread.Queue.ToArray();
        var originalQueueDirty = thread.QueueDirty;
        var originalTemp0 = thread.TempRegisters[0];
        var originalCanceled = caller.GetFlag(VMEntityFlags.InteractionCanceled);
        var originalPriority = caller.GetPersonData(VMPersonDataVariable.Priority);
        var originalNotifyIdle = originalQueue.ToDictionary(action => action, action => action.NotifyIdle);
        var originalActionPriority = originalQueue.ToDictionary(action => action, action => action.Priority);
        var other = vm.Entities.FirstOrDefault(entity => entity != caller && entity != target);
        var frame = new VMStackFrame { Thread = thread, Caller = caller, Callee = caller, StackObject = other };
        var checks = 0;
        void Require(bool condition, string message)
        {
            if (!condition) throw new InvalidDataException(message);
            checks++;
        }

        try
        {
            var usedIds = new HashSet<ushort>(thread.Queue.Select(action => action.UID));
            var nextUid = ushort.MaxValue;
            ushort NextUid()
            {
                while (usedIds.Contains(nextUid)) nextUid--;
                var result = nextUid--;
                usedIds.Add(result);
                return result;
            }
            var targetByCallee = new VMQueuedAction
            {
                UID = NextUid(),
                Mode = VMQueueMode.ParentExit,
                Callee = target,
                StackObject = other
            };
            var targetByStackObject = new VMQueuedAction
            {
                UID = NextUid(),
                Mode = VMQueueMode.ParentExit,
                Callee = other,
                StackObject = target
            };
            var targetByIconOwner = new VMQueuedAction
            {
                UID = NextUid(),
                Mode = VMQueueMode.ParentExit,
                Callee = other,
                StackObject = other,
                IconOwner = target
            };
            var unrelated = new VMQueuedAction
            {
                UID = NextUid(),
                Mode = VMQueueMode.ParentExit,
                Callee = other,
                StackObject = other
            };
            thread.Queue.AddRange(new[] { targetByCallee, targetByStackObject, targetByIconOwner, unrelated });
            thread.TempRegisters[0] = (short)(targetSlot + 1);

            var result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AbortInteractions });
            Require(result == VMPrimitiveExitCode.GOTO_TRUE, "Mode 13 did not return true for a valid inventory index");
            Require(targetByCallee.NotifyIdle && targetByStackObject.NotifyIdle && targetByIconOwner.NotifyIdle,
                "Mode 13 did not mark target-associated interactions for cancellation");
            Require(!unrelated.NotifyIdle, "Mode 13 canceled an unrelated interaction");

            thread.Queue.Clear();
            thread.Queue.Add(unrelated);
            thread.TempRegisters[0] = (short)(targetSlot + 1);
            result = new VMGenericTS1Call().Execute(frame,
                new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AbortInteractions });
            Require(result == VMPrimitiveExitCode.GOTO_TRUE && !unrelated.NotifyIdle,
                "Mode 13 did not preserve the no-matching-interactions path");

            foreach (var invalidIndex in new short[] { -1, 0, (short)(caller.TotalSlots() + 1) })
            {
                thread.TempRegisters[0] = invalidIndex;
                var threw = false;
                try
                {
                    new VMGenericTS1Call().Execute(frame,
                        new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AbortInteractions });
                }
                catch (VMSimanticsException)
                {
                    threw = true;
                }
                Require(threw, "Mode 13 did not reject an out-of-range inventory index");
            }

            if (emptyTestSlot >= 0)
            {
                thread.TempRegisters[0] = (short)(emptyTestSlot + 1);
                var threw = false;
                try
                {
                    new VMGenericTS1Call().Execute(frame,
                        new VMGenericTS1CallOperand { Call = VMGenericTS1CallMode.AbortInteractions });
                }
                catch (VMSimanticsException)
                {
                    threw = true;
                }
                Require(threw, "Mode 13 did not reject an empty inventory slot");
            }
        }
        finally
        {
            thread.Queue.Clear();
            thread.Queue.AddRange(originalQueue);
            foreach (var action in originalQueue)
            {
                action.NotifyIdle = originalNotifyIdle[action];
                action.Priority = originalActionPriority[action];
            }
            thread.QueueDirty = originalQueueDirty;
            thread.TempRegisters[0] = originalTemp0;
            caller.SetFlag(VMEntityFlags.InteractionCanceled, originalCanceled);
            caller.SetPersonData(VMPersonDataVariable.Priority, originalPriority);
            caller.Contained[emptySlot] = null;
            target.Container = originalTargetContainer;
            target.ContainerSlot = originalTargetContainerSlot;
        }

        return new { checks, mode = (byte)VMGenericTS1CallMode.AbortInteractions, originalHandler = true };
    }
}
