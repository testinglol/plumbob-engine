using System.Buffers.Binary;
using FSO.Content;
using FSO.Content.Model;
using FSO.Files.HIT;
using FSO.Files.XA;
using FSO.HIT;

internal static class NativeAudioChecks
{
    public static object Run()
    {
        HITVM.Init();
        var source = Content.Get().Audio.Events["vox_laugh_giggle"].ResGroup;
        var targets = source.hot.TrackData.Where(entry => (entry.Key & 255) <= 15).ToArray();
        int checks = 0;
        HITThread Thread(byte[] operand)
        {
            var bytes = new byte[16 + operand.Length];
            "HIT!"u8.CopyTo(bytes);
            operand.CopyTo(bytes, 16);
            return new HITThread(new HITResourceGroup { hot = source.hot, hsm = source.hsm, hit = new HITFile(bytes) }, HITVM.Get()) { PC = 16 };
        }
        foreach (var target in targets)
        {
            var operand = new byte[4];
            BinaryPrimitives.WriteUInt32LittleEndian(operand, target.Key);
            var thread = Thread(operand);
            thread.WriteVar((int)(target.Key & 255), -1);
            HITInterpreter.Jump(thread);
            if (thread.PC != target.Value) throw new InvalidDataException("HIT literal target was mistaken for a register");
            checks++;
        }
        var destination = targets.First(entry => entry.Value != 0);
        for (int register = 0; register < 16; register++)
        {
            var thread = Thread([(byte)register, 255, 255, 255]);
            thread.WriteVar(register, (int)destination.Key);
            HITInterpreter.Jump(thread);
            if (thread.PC != destination.Value) throw new InvalidDataException("HIT register target was mistaken for a literal");
            checks++;
        }
        var xa = new byte[39];
        "XAI\0"u8.CopyTo(xa);
        BinaryPrimitives.WriteUInt32LittleEndian(xa.AsSpan(4), 9000);
        BinaryPrimitives.WriteUInt16LittleEndian(xa.AsSpan(8), 1);
        BinaryPrimitives.WriteUInt16LittleEndian(xa.AsSpan(10), 1);
        BinaryPrimitives.WriteUInt32LittleEndian(xa.AsSpan(12), 22050);
        BinaryPrimitives.WriteUInt32LittleEndian(xa.AsSpan(16), 44100);
        BinaryPrimitives.WriteUInt16LittleEndian(xa.AsSpan(20), 2);
        BinaryPrimitives.WriteUInt16LittleEndian(xa.AsSpan(22), 16);
        var wav = new XAFile(xa).DecompressedData;
        if (wav.Length != 100 || BinaryPrimitives.ReadUInt32LittleEndian(wav.AsSpan(4)) != wav.Length - 8 ||
            BinaryPrimitives.ReadUInt32LittleEndian(wav.AsSpan(40)) != 56 || Math.Abs(NativeAudio.WaveDuration(wav) - 56f / 44100) > 0.000001)
            throw new InvalidDataException("XA WAV header does not describe actual decoded samples");
        return new { jumpChecks = checks, xaHeader = true, originalTrackData = true };
    }
}
