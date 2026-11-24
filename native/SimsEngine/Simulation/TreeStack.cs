using SimsEngine.Formats;

namespace SimsEngine.Simulation;

public interface ITreeTable
{
    Bhav? Find(short id);

    IReadOnlyList<short>? Constants(ushort id, bool allowTuningOverride = false) => null;
}

public enum TreeRunError
{
    TreeNotEntered = 1000,
    ReturnFromLastFrame = 1001,
    BadTarget = 1100,
    StepLimit = 1101,
    TreeOrInstructionMissing = 1102,
    NestedRunSuspended = 1103,
}

public sealed class TreeRunException(TreeRunError error, string? detail = null)
    : Exception($"Tree run error {(int)error}: {error}{(detail is null ? string.Empty : $" ({detail})")}")
{
    public TreeRunError Error { get; } = error;
}

public enum PrimitiveResult
{
    Yield = -1,
    False = 0,
    True = 1,
    Stop = 2,
    Again = 3,
}

public enum StepResult
{
    Continue = 0,
    Stop = 1,
    Yield = 2,
}

public abstract class TreeStack
{
    public List<StackFrame> Frames { get; } = [];

    public int[] TempXL { get; } = new int[2];

    public int Steps { get; set; }

    public int StepLimit { get; set; } = 10000;

    public int LastTarget { get; private set; }

    public bool LastResult { get; private set; }

    public short[] DefaultParameters { get; set; } = new short[4];

    public StackFrame? Top => Frames.Count == 0 ? null : Frames[^1];

    // Matches Sims.exe TreeSim::PrimitiveFrame (TreeId == -1 marks nested-run sentinel frames).
    public StackFrame? PrimitiveFrame()
    {
        var start = 0;
        while (start < Frames.Count && Frames[start].TreeId == -1) start++;
        if (start >= Frames.Count) return null;
        for (var i = start; i < Frames.Count; i++)
            if (Frames[i].TreeId == -1) return Frames[i - 1];
        return Frames[^1];
    }

    public virtual int EffectiveDepth => Frames.Count;

    protected abstract PrimitiveResult RunPrimitive(StackFrame frame, BhavInstruction instruction);

    protected virtual void Called(StackFrame caller, short treeId, short[]? parameters) { }

    protected virtual bool TryInterceptSubroutine(StackFrame caller, short treeId, short[]? parameters, out bool result)
    {
        result = false;
        return false;
    }

    protected virtual void Popped(StackFrame frame) { }

    protected virtual object? BeginRunToReturn() => null;

    protected virtual void EndRunToReturn(object? state) { }

    // Matches retail Sims.exe TreeSim::Vfn03 (clears frame breakpoint flag and continues).
    protected virtual StepResult Breakpoint(StackFrame frame, BhavInstruction? instruction)
    {
        frame.TreeBreakpoint = false;
        return StepCore(checkBreakpoints: false);
    }

    public bool Push(ITreeTable? table, ReadOnlySpan<short> parameters, bool useDefault, short treeId, short codeOwner = 0)
    {
        var top = Top;
        var inheritedTable = table is null;
        table ??= top?.Table;
        if (table is null) return false;
        var tree = table.Find(treeId);
        if (tree is null) return false;
        var source = useDefault ? DefaultParameters : parameters;
        var count = tree.Instructions.Count;
        var start = 0;
        if (tree.StartsAtCallerInstruction)
        {
            start = source.Length > 0 ? source[0] : 0;
            if (start >= count) start = count - 1;
        }
        if (start < 0 || start >= count) return false;
        var arguments = new short[tree.ArgumentCount];
        for (var index = 0; index < arguments.Length && index < source.Length; index++) arguments[index] = source[index];
        Frames.Add(new StackFrame(top?.StackObject ?? 0, arguments, new short[tree.LocalCount])
        {
            Tree = tree,
            TreeId = treeId,
            Table = table,
            CodeOwner = inheritedTable ? (top?.CodeOwner ?? codeOwner) : codeOwner,
            Instruction = start,
        });
        return true;
    }

    public bool PushFor(ITreeTable table, short stackObject, short treeId, short codeOwner = 0)
    {
        if (!Push(table, [], true, treeId, codeOwner)) return false;
        Top!.StackObject = stackObject;
        return true;
    }

    public bool PushFor(ITreeTable table, short stackObject, short treeId, ReadOnlySpan<short> parameters, short codeOwner = 0)
    {
        if (!Push(table, parameters, false, treeId, codeOwner)) return false;
        Top!.StackObject = stackObject;
        return true;
    }

    internal void RestoreFrame(StackFrame frame) => Frames.Add(frame);

    public static short[]? GosubParameters(Bhav tree, int index)
    {
        var operand = tree.Instructions[index].Operand;
        if (operand.All(value => value == 0xFF)) return null;
        var bytes = new List<byte>(operand);
        for (var next = index + 1; next < tree.Instructions.Count; next++)
        {
            var instruction = tree.Instructions[next];
            var opcode = (ushort)(instruction.Opcode | (instruction.Breakpoint ? 0x8000 : 0));
            bytes.Add((byte)opcode);
            bytes.Add((byte)(opcode >> 8));
            bytes.Add(instruction.TrueTarget);
            bytes.Add(instruction.FalseTarget);
            bytes.AddRange(instruction.Operand);
        }
        var values = new short[bytes.Count / 2];
        for (var at = 0; at < values.Length; at++) values[at] = (short)(bytes[at * 2] | bytes[at * 2 + 1] << 8);
        return values;
    }

    public StepResult Step() => StepCore(checkBreakpoints: true);

    private StepResult StepCore(bool checkBreakpoints)
    {
        var frame = Top ?? throw new TreeRunException(TreeRunError.ReturnFromLastFrame);
        if (frame.Table is null)
        {
            Pop();
            return StepResult.Continue;
        }
        if (checkBreakpoints && frame.TreeBreakpoint) return Breakpoint(frame, null);
        var index = frame.Instruction;
        if (index is < 0 or > 0xFA)
        {
            if (index is not (BhavInstruction.ReturnTrue or BhavInstruction.ReturnFalse))
                throw new TreeRunException(TreeRunError.BadTarget);
            Return(index == BhavInstruction.ReturnTrue);
            return StepResult.Continue;
        }
        var tree = frame.Tree as Bhav;
        if (tree is null || index >= tree.Instructions.Count) throw new TreeRunException(TreeRunError.TreeOrInstructionMissing);
        var instruction = tree.Instructions[index];
        if (checkBreakpoints && instruction.Breakpoint) return Breakpoint(frame, instruction);
        if (++Steps >= StepLimit) throw new TreeRunException(TreeRunError.StepLimit, $"tree {frame.TreeId}, instruction {index}, stack {frame.StackObject}");
        if (instruction.Opcode < 0x100)
        {
            switch (RunPrimitive(frame, instruction))
            {
                case PrimitiveResult.False: Branch(frame, instruction.FalseTarget, false); break;
                case PrimitiveResult.True: Branch(frame, instruction.TrueTarget, true); break;
                case PrimitiveResult.Stop: return StepResult.Stop;
                case PrimitiveResult.Again: return StepResult.Continue;
                default: return StepResult.Yield;
            }
            return StepResult.Continue;
        }
        var parameters = GosubParameters(tree, index);
        var id = (short)instruction.Opcode;
        Called(frame, id, parameters);
        if (TryInterceptSubroutine(frame, id, parameters, out var intercepted))
        {
            Branch(frame, intercepted ? instruction.TrueTarget : instruction.FalseTarget, intercepted);
            return StepResult.Continue;
        }
        if (!Push(null, parameters, parameters is null, id))
            throw new TreeRunException(frame.Table.Find(id) is null ? TreeRunError.TreeOrInstructionMissing : TreeRunError.TreeNotEntered);
        return StepResult.Continue;
    }

    public bool Run()
    {
        Steps = 0;
        while (true)
        {
            if (Top is { TreeId: -1, Tree: null })
            {
                RemoveTop();
                return true;
            }
            var result = Step();
            if (result == StepResult.Stop) return true;
            if (result == StepResult.Yield) return false;
        }
    }

    public bool RunToReturn(ITreeTable? table, ReadOnlySpan<short> parameters, bool useDefault, short treeId, short stackObject)
    {
        var marker = new StackFrame(0, [], []) { TreeId = -1, Waiting = true };
        Frames.Add(marker);
        if (!Push(table, parameters, useDefault, treeId))
        {
            RemoveTop();
            return false;
        }
        Top!.StackObject = stackObject;
        var saved = Steps;
        Steps = 0;
        var runState = BeginRunToReturn();
        try
        {
            while (true)
            {
                if (Top!.TreeId == -1)
                {
                    RemoveTop();
                    return LastTarget == BhavInstruction.ReturnTrue;
                }
                var result = Step();
                if (result is StepResult.Stop or StepResult.Yield) throw new TreeRunException(TreeRunError.NestedRunSuspended);
            }
        }
        finally
        {
            EndRunToReturn(runState);
            Steps = saved;
        }
    }

    private void Pop()
    {
        if (Frames.Count < 2) throw new TreeRunException(TreeRunError.ReturnFromLastFrame);
        RemoveTop();
    }

    private void RemoveTop()
    {
        var frame = Frames[^1];
        Frames.RemoveAt(Frames.Count - 1);
        Popped(frame);
    }

    private void Return(bool result)
    {
        var returning = Top!;
        Pop();
        var caller = Frames[^1];
        LastResult = result;
        if (caller.Waiting) return;
        if (caller.Tree is not Bhav tree || caller.Instruction < 0 || caller.Instruction >= tree.Instructions.Count)
            throw new TreeRunException(TreeRunError.TreeOrInstructionMissing);
        var instruction = tree.Instructions[caller.Instruction];
        var target = result ? instruction.TrueTarget : instruction.FalseTarget;
        if (target == BhavInstruction.Error)
            throw new TreeRunException(TreeRunError.BadTarget,
                $"returning from tree {returning.TreeId} at return target {returning.Instruction} with result {(result ? "true" : "false")} " +
                $"into caller tree {caller.TreeId} instruction {caller.Instruction} selected the error target");
        caller.Instruction = target;
        LastTarget = target;
    }

    private void Branch(StackFrame frame, byte target, bool result)
    {
        if (target == BhavInstruction.Error)
            throw new TreeRunException(TreeRunError.BadTarget,
                $"tree {frame.TreeId} instruction {frame.Instruction} selected the error target for result {(result ? "true" : "false")}");
        frame.Instruction = target;
        LastTarget = target;
        LastResult = result;
        frame.Waiting = false;
    }
}
