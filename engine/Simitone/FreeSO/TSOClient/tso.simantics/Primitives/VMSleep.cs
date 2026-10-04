using FSO.SimAntics.Engine;
using FSO.Files.Utils;
using System.IO;

namespace FSO.SimAntics.Primitives
{
    public class VMSleep : VMPrimitiveHandler
    {
        public override VMPrimitiveExitCode Execute(VMStackFrame context, VMPrimitiveOperand args)
        {
            var operand = (VMSleepOperand)args;
            var idleStart = context.Thread.ScheduleIdleStart;
            var elapsed = (idleStart != 0 && idleStart < context.VM.Scheduler.CurrentTickID) ? context.VM.Scheduler.CurrentTickID - idleStart : 1u;
            var remaining = (ushort)context.Args[operand.StackVarToDec];
            var completed = context.VM.TS1 && elapsed > remaining;
            context.Args[operand.StackVarToDec] = context.VM.TS1
                ? (completed ? (short)-1 : (short)(remaining - elapsed))
                : (short)(context.Args[operand.StackVarToDec] - (short)elapsed);

            if (context.Thread.Interrupt)
            {
                context.Thread.ScheduleIdleStart = 0;
                context.Thread.Interrupt = false;
                return VMPrimitiveExitCode.GOTO_TRUE;
            }

            if (context.VM.TS1 ? completed : context.Args[operand.StackVarToDec] <= -1) {
                context.Thread.ScheduleIdleStart = 0;
                context.VM.Context.NextRandom(1); //rng cycle - for desync detect
                return (context.Caller.Dead)?VMPrimitiveExitCode.GOTO_TRUE_NEXT_TICK:VMPrimitiveExitCode.GOTO_TRUE;
            }
            else
            {
                context.Thread.ScheduleIdleStart = context.VM.Scheduler.CurrentTickID;
                context.VM.Scheduler.ScheduleTickIn(context.Caller, (context.VM.TS1 ? (uint)(ushort)context.Args[operand.StackVarToDec] : (uint)context.Args[operand.StackVarToDec]) + 1);
                return VMPrimitiveExitCode.CONTINUE_FUTURE_TICK;
            }
        }
    }

    public class VMSleepOperand : VMPrimitiveOperand
    {
        public short StackVarToDec { get; set; }

        #region VMPrimitiveOperand Members
        public void Read(byte[] bytes){
            using (var io = IoBuffer.FromBytes(bytes, ByteOrder.LITTLE_ENDIAN)){
                StackVarToDec = io.ReadInt16();
            }
        }

        public void Write(byte[] bytes) {
            using (var io = new BinaryWriter(new MemoryStream(bytes)))
            {
                io.Write(StackVarToDec);
            }
        }
        #endregion
    }
}
