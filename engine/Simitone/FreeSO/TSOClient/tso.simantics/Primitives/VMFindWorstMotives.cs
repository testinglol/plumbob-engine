using System.Buffers.Binary;
using System.Linq;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;

namespace FSO.SimAntics.Primitives
{
    public class VMFindWorstMotives : VMPrimitiveHandler
    {
        private static readonly VMMotive[] Candidates =
        {
            VMMotive.Energy, VMMotive.Comfort, VMMotive.Hunger, VMMotive.Hygiene,
            VMMotive.Bladder, VMMotive.Room, VMMotive.Social, VMMotive.Fun
        };

        public override VMPrimitiveExitCode Execute(VMStackFrame context, VMPrimitiveOperand args)
        {
            var operand = (VMFindWorstMotivesOperand)args;
            if (operand.MotiveType > 2) throw new VMSimanticsException("Invalid motive type.", context);
            var target = operand.Target switch
            {
                1 => context.StackObject,
                2 => throw new VMSimanticsException("Invalid motive target.", context),
                _ => context.Caller
            };
            if (target is not VMAvatar avatar) throw new VMSimanticsException("Motive target is not a person.", context);

            var values = Candidates.Select(avatar.GetMotiveData).ToArray();
            var ranked = RankValues(values);
            Array.Copy(ranked, context.Thread.TempRegisters, ranked.Length);
            return VMPrimitiveExitCode.GOTO_TRUE;
        }

        public static short[] RankValues(short[] values) => Candidates
            .Select((motive, index) => (Motive: (short)motive, Value: values[index]))
            .OrderBy(entry => entry.Value)
            .Take(5)
            .Select(entry => entry.Motive)
            .ToArray();
    }

    public class VMFindWorstMotivesOperand : VMPrimitiveOperand
    {
        public ushort Target { get; set; }
        public ushort MotiveType { get; set; }

        public void Read(byte[] bytes)
        {
            Target = BinaryPrimitives.ReadUInt16LittleEndian(bytes.AsSpan(4, 2));
            MotiveType = BinaryPrimitives.ReadUInt16LittleEndian(bytes.AsSpan(6, 2));
        }

        public void Write(byte[] bytes)
        {
            BinaryPrimitives.WriteUInt16LittleEndian(bytes.AsSpan(4, 2), Target);
            BinaryPrimitives.WriteUInt16LittleEndian(bytes.AsSpan(6, 2), MotiveType);
        }
    }
}
