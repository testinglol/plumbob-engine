using System.Buffers.Binary;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Engine.Scopes;
using FSO.SimAntics.Engine.Utils;

namespace FSO.SimAntics.Primitives
{
    public enum VMUIEffectMethod : byte
    {
        BitmapButton,
        PortraitButton,
        RelationshipWidget
    }

    public enum VMUIEffectDispatchResult : byte
    {
        Applied,
        TargetMissing,
        Unhandled
    }

    public sealed record VMUIEffectRequest(VMUIEffectMethod Method, short Value, byte Flags);

    public class VMUIEffect : VMPrimitiveHandler
    {
        public override VMPrimitiveExitCode Execute(VMStackFrame context, VMPrimitiveOperand args)
        {
            var operand = (VMUIEffectOperand)args;
            if (operand.Mode > 2) return VMPrimitiveExitCode.GOTO_TRUE;
            var value = VMMemory.GetVariable(context, operand.Scope, operand.Data);
            var flags = (byte)(operand.Flags & 1);
            var requests = BuildRequests(operand.Mode, value, flags);
            DispatchRequests(requests, context.Thread.Context.UIEffectHandler, context.Thread.Context.UIEffectUnhandled);
            return VMPrimitiveExitCode.GOTO_TRUE;
        }

        public static void DispatchRequests(VMUIEffectRequest[] requests, Func<VMUIEffectRequest, VMUIEffectDispatchResult> handler,
            Action<VMUIEffectRequest> unhandled)
        {
            foreach (var request in requests)
            {
                var result = handler?.Invoke(request) ?? VMUIEffectDispatchResult.Unhandled;
                if (result == VMUIEffectDispatchResult.Unhandled) unhandled?.Invoke(request);
            }
        }

        public static VMUIEffectRequest[] BuildRequests(byte mode, short value, byte flags) => mode switch
        {
            0 => new[]
            {
                new VMUIEffectRequest(VMUIEffectMethod.BitmapButton, value, flags),
                new VMUIEffectRequest(VMUIEffectMethod.PortraitButton, value, flags)
            },
            1 => new[] { new VMUIEffectRequest(VMUIEffectMethod.PortraitButton, value, flags) },
            2 => new[] { new VMUIEffectRequest(VMUIEffectMethod.RelationshipWidget, value, flags) },
            _ => Array.Empty<VMUIEffectRequest>()
        };
    }

    public class VMUIEffectOperand : VMPrimitiveOperand
    {
        public byte Mode { get; set; }
        public VMVariableScope Scope { get; set; }
        public short Data { get; set; }
        public byte Flags { get; set; }

        public void Read(byte[] bytes)
        {
            Mode = bytes[0];
            Scope = (VMVariableScope)bytes[1];
            Data = BinaryPrimitives.ReadInt16LittleEndian(bytes.AsSpan(2, 2));
            Flags = bytes[4];
        }

        public void Write(byte[] bytes)
        {
            bytes[0] = Mode;
            bytes[1] = (byte)Scope;
            BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(2, 2), Data);
            bytes[4] = Flags;
        }
    }
}
