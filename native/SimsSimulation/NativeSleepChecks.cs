using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;

internal static class NativeSleepChecks
{
    public static void Run(VM vm)
    {
        var entity = vm.Entities.OfType<VMGameObject>().First(item => item.Name.Contains("Insanity"));
        var originalThread = entity.Thread;
        var handler = new VMSleep();
        var operand = new VMSleepOperand { StackVarToDec = 0 };
        foreach (var duration in new[] { 0, 1, 32767, 32768, 36000, 65535 })
        {
            vm.Scheduler.Reset();
            vm.Scheduler.CurrentTickID = 100;
            entity.Thread = new VMThread(vm.Context, entity, 1);
            var frame = new VMStackFrame { Thread = entity.Thread, Caller = entity, Callee = entity, Args = [(short)duration] };
            var result = handler.Execute(frame, operand);
            if (duration == 0)
            {
                if (result != VMPrimitiveExitCode.GOTO_TRUE) throw new Exception("Zero sleep did not complete");
                continue;
            }
            if (result != VMPrimitiveExitCode.CONTINUE_FUTURE_TICK || entity.Thread.ScheduleIdleEnd != 100 + duration) throw new Exception($"Sleep {duration} did not schedule its deadline");
            if (duration > 50)
            {
                vm.Scheduler.CurrentTickID = 150;
                result = handler.Execute(frame, operand);
                if (result != VMPrimitiveExitCode.CONTINUE_FUTURE_TICK || entity.Thread.ScheduleIdleEnd != 100 + duration) throw new Exception($"Sleep {duration} changed deadline when woken early");
            }
            vm.Scheduler.CurrentTickID = (uint)(100 + duration);
            if (handler.Execute(frame, operand) != VMPrimitiveExitCode.GOTO_TRUE) throw new Exception($"Sleep {duration} did not complete at its deadline");
        }
        vm.Scheduler.Reset();
        vm.Scheduler.CurrentTickID = 100;
        entity.Thread = new VMThread(vm.Context, entity, 1) { Interrupt = true };
        var interrupted = new VMStackFrame { Thread = entity.Thread, Caller = entity, Callee = entity, Args = [unchecked((short)36000)] };
        if (handler.Execute(interrupted, operand) != VMPrimitiveExitCode.GOTO_TRUE || entity.Thread.Interrupt) throw new Exception("Sleep ignored an interrupt");
        entity.Thread = originalThread;

        var avatar = vm.Entities.OfType<VMAvatar>().First();
        var originalMotives = Enumerable.Range(0, 16).Select(index => avatar.GetMotiveData((VMMotive)index)).ToArray();
        var originalHours = vm.Context.Clock.Hours;
        var originalMinutes = vm.Context.Clock.Minutes;
        try
        {
            avatar.SetMotiveData(VMMotive.Energy, 50);
            avatar.SetMotiveData(VMMotive.SleepState, -1);
            vm.Context.Clock.Hours = 2;
            vm.Context.Clock.Minutes = 2;
            var decay = new VMTS1MotiveDecay();
            decay.Tick(avatar, vm.Context);
            vm.Context.Clock.Minutes = 4;
            decay.Tick(avatar, vm.Context);
            if (avatar.GetMotiveData(VMMotive.Energy) != 52 || decay.MotiveFractions[4] != -572)
                throw new Exception("Sleep energy recovery did not preserve the fractional motive remainder");

            using var savedDecay = new MemoryStream();
            using (var writer = new BinaryWriter(savedDecay, System.Text.Encoding.UTF8, true)) decay.SerializeInto(writer);
            savedDecay.Position = 0;
            var restoredDecay = new VMTS1MotiveDecay();
            using (var reader = new BinaryReader(savedDecay, System.Text.Encoding.UTF8, true)) restoredDecay.Deserialize(reader);
            vm.Context.Clock.Minutes = 6;
            restoredDecay.Tick(avatar, vm.Context);
            if (avatar.GetMotiveData(VMMotive.Energy) != 53 || restoredDecay.MotiveFractions[4] != -858)
                throw new Exception("Sleep energy recovery changed across motive state save and reload");
        }
        finally
        {
            avatar.ReplaceMotiveData(originalMotives);
            vm.Context.Clock.Hours = originalHours;
            vm.Context.Clock.Minutes = originalMinutes;
        }
    }
}
