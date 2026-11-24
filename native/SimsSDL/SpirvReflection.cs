using System.Runtime.InteropServices;

namespace SimsSDL;

internal static class SpirvReflection
{
    private const uint MagicNumber = 0x07230203;
    private const ushort OpEntryPoint = 15;
    private const ushort OpTypeSampledImage = 27;
    private const ushort OpTypeArray = 28;
    private const ushort OpTypeRuntimeArray = 29;
    private const ushort OpTypePointer = 32;
    private const ushort OpFunction = 54;
    private const ushort OpFunctionEnd = 56;
    private const ushort OpVariable = 59;
    private const ushort OpDecorate = 71;

    private const uint ExecutionModelFragment = 4;
    private const uint StorageClassUniformConstant = 0;
    private const uint StorageClassUniform = 2;
    private const uint StorageClassStorageBuffer = 12;

    private const uint DecorationBlock = 2;
    private const uint DecorationBufferBlock = 3;
    private const uint DecorationBinding = 33;

    internal readonly record struct ShaderResources(int Stage, uint Samplers, uint StorageBuffers, uint UniformBuffers);

    internal static ShaderResources? TryReflectFile(string spvPath)
    {
        if (!File.Exists(spvPath))
            return null;
        return Reflect(File.ReadAllBytes(spvPath));
    }

    internal static ShaderResources Reflect(ReadOnlySpan<byte> bytecode)
    {
        if (bytecode.Length < 20 || (bytecode.Length & 3) != 0)
            throw new InvalidDataException("Invalid SPIR-V bytecode length.");

        ReadOnlySpan<uint> words = MemoryMarshal.Cast<byte, uint>(bytecode);
        if (words[0] != MagicNumber)
            throw new InvalidDataException($"Unexpected SPIR-V magic 0x{words[0]:X8}.");

        int stage = SDL_GPU_SHADERSTAGE_VERTEX;
        var blocks = new HashSet<uint>();
        var bufferBlocks = new HashSet<uint>();
        var bindings = new Dictionary<uint, uint>();
        var sampledImages = new HashSet<uint>();
        var arrayElements = new Dictionary<uint, uint>();
        var pointerPointees = new Dictionary<uint, uint>();
        var variables = new List<(uint ResultTypeId, uint ResultId, uint StorageClass)>();
        var referencedIds = new HashSet<uint>();
        bool insideFunction = false;

        int pos = 5;
        while (pos < words.Length)
        {
            uint header = words[pos];
            int wordCount = (int)(header >> 16);
            ushort opcode = (ushort)(header & 0xFFFF);
            if (wordCount <= 0 || pos + wordCount > words.Length)
                throw new InvalidDataException($"Malformed SPIR-V instruction at word {pos}.");

            if (opcode == OpFunction)
            {
                insideFunction = true;
            }
            else if (opcode == OpFunctionEnd)
            {
                insideFunction = false;
            }
            else if (insideFunction)
            {
                for (int i = 1; i < wordCount; i++)
                    referencedIds.Add(words[pos + i]);
            }

            switch (opcode)
            {
                case OpEntryPoint when wordCount >= 3:
                    stage = words[pos + 1] == ExecutionModelFragment
                        ? SDL_GPU_SHADERSTAGE_FRAGMENT
                        : SDL_GPU_SHADERSTAGE_VERTEX;
                    break;

                case OpDecorate when wordCount >= 3:
                {
                    uint targetId = words[pos + 1];
                    uint decoration = words[pos + 2];
                    if (decoration == DecorationBlock)
                        blocks.Add(targetId);
                    else if (decoration == DecorationBufferBlock)
                        bufferBlocks.Add(targetId);
                    else if (decoration == DecorationBinding && wordCount >= 4)
                        bindings[targetId] = words[pos + 3];
                    break;
                }

                case OpTypeSampledImage when wordCount >= 2:
                    sampledImages.Add(words[pos + 1]);
                    break;

                case OpTypeArray or OpTypeRuntimeArray when wordCount >= 3:
                    arrayElements[words[pos + 1]] = words[pos + 2];
                    break;

                case OpTypePointer when wordCount >= 4:
                    pointerPointees[words[pos + 1]] = words[pos + 3];
                    break;

                case OpVariable when !insideFunction && wordCount >= 4:
                    variables.Add((words[pos + 1], words[pos + 2], words[pos + 3]));
                    break;
            }

            pos += wordCount;
        }

        uint samplers = 0;
        uint storageBuffers = 0;
        uint uniformBuffers = 0;

        foreach (var (resultTypeId, resultId, storageClass) in variables)
        {
            if (!bindings.TryGetValue(resultId, out uint binding) || !referencedIds.Contains(resultId))
                continue;
            if (!pointerPointees.TryGetValue(resultTypeId, out uint pointee))
                continue;

            while (arrayElements.TryGetValue(pointee, out uint inner))
                pointee = inner;

            uint requiredSlots = binding + 1;
            if (storageClass == StorageClassUniformConstant && sampledImages.Contains(pointee))
            {
                if (requiredSlots > samplers)
                    samplers = requiredSlots;
            }
            else if (storageClass == StorageClassStorageBuffer ||
                     (storageClass == StorageClassUniform && bufferBlocks.Contains(pointee)))
            {
                if (requiredSlots > storageBuffers)
                    storageBuffers = requiredSlots;
            }
            else if (storageClass == StorageClassUniform && blocks.Contains(pointee))
            {
                if (requiredSlots > uniformBuffers)
                    uniformBuffers = requiredSlots;
            }
        }

        return new ShaderResources(stage, samplers, storageBuffers, uniformBuffers);
    }
}
