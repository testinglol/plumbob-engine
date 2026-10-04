using FSO.SimAntics.Engine;

namespace FSO.SimAntics.Primitives
{
    public class VMTS1Tutorial : VMPrimitiveHandler
    {
        public override VMPrimitiveExitCode Execute(VMStackFrame context, VMPrimitiveOperand args)
        {
            var operand = (VMTS1TutorialOperand)args;
            bool result = operand.Mode switch
            {
                0 => context.Thread.Context.TryClaimTutorialOwner(context.Caller),
                1 => context.Thread.Context.TryReleaseTutorialOwner(context.Caller),
                _ => throw new VMSimanticsException("Invalid TS1 tutorial mode.", context)
            };
            return result.AsGotoExitCode();
        }
    }

    public class VMTS1TutorialOperand : VMPrimitiveOperand
    {
        public byte Mode { get; set; }

        public void Read(byte[] bytes)
        {
            Mode = bytes[0];
        }

        public void Write(byte[] bytes)
        {
            bytes[0] = Mode;
        }
    }
}
