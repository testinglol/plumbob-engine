using System.Buffers.Binary;
using SimsEngine.Formats;

namespace SimsEngine.Tests;

public class AnimationCurveTests
{
    private static byte[] Float(float value)
    {
        var bytes = new byte[4];
        BinaryPrimitives.WriteSingleLittleEndian(bytes, value);
        return bytes;
    }

    private static byte[] Stream(params byte[][] parts) => [.. parts.SelectMany(part => part)];

    private static void AssertClose(float[] expected, float[] actual)
    {
        Assert.Equal(expected.Length, actual.Length);
        for (var index = 0; index < expected.Length; index++) Assert.True(MathF.Abs(expected[index] - actual[index]) < 1e-5f, $"index {index}: {actual[index]} != {expected[index]}");
    }

    [Fact]
    public void AbsoluteFloatsAndDeltaCodesAccumulate()
    {
        // CFP opcodes: 0xFF = f32 literal, 0xFC = +0.1 delta, 0x7E = 0 delta.
        var data = Stream([0xFF], Float(1f), [0xFC], [0x7E]);
        var curves = AnimationCurveFile.Read(data, "absolute.cfp", 1, 0);
        AssertClose([1f, 1.1f, 1.1f], curves.Translations);
        Assert.Empty(curves.Rotations);
    }

    [Fact]
    public void RepeatCodeHoldsTheValueWithoutReadingMoreCodes()
    {
        // CFP opcode 0xFE followed by u16 N repeats the current value across the current frame plus N subsequent frames.
        var data = Stream([0xFE, 0x01, 0x00], [0xFF], Float(3f), [0x00], [0xFF], Float(5f), [0xFE, 0x00, 0x00]);
        var curves = AnimationCurveFile.Read(data, "repeat.cfp", 2, 0);
        AssertClose([0f, 3f, 5f, 0f, 2.9f, 5f], curves.Translations);
    }

    [Fact]
    public void EachRunStartsFromZeroAndChannelsShareTheValue()
    {
        // CFP shares one accumulator across translation channels, then resets to 0 for rotation channels.
        var data = Stream([0xFF], Float(2f), [0x00], [0x00], [0xFC], [0xFE, 0x00, 0x00], [0xFE, 0x00, 0x00], [0xFE, 0x00, 0x00]);
        var curves = AnimationCurveFile.Read(data, "restart.cfp", 1, 1);
        AssertClose([2f, 1.9f, 1.8f], curves.Translations);
        AssertClose([0.1f, 0.1f, 0.1f, 0.1f], curves.Rotations);
    }

    [Fact]
    public void LeftoverBytesAreRejected()
    {
        var data = Stream([0xFF], Float(1f), [0x00], [0x00], [0x00]);
        var error = Assert.Throws<ResourceFormatException>(() => AnimationCurveFile.Read(data, "extra.cfp", 1, 0));
        Assert.Equal("extra.cfp", error.File);
        Assert.Equal(7, error.Offset);
    }

    [Fact]
    public void TruncatedAbsoluteFloatIsRejectedWithItsOffset()
    {
        var data = Stream([0xFF], [0x00, 0x00]);
        var error = Assert.Throws<ResourceFormatException>(() => AnimationCurveFile.Read(data, "short.cfp", 1, 0));
        Assert.Equal("short.cfp", error.File);
        Assert.Equal(1, error.Offset);
    }

    [Fact]
    public void FrameCountsAboveTheLimitAreRejected()
    {
        Assert.Throws<ResourceFormatException>(() => AnimationCurveFile.Read(new byte[] { 0 }, "big.cfp", AnimationCurveFile.MaximumFrames + 1, 0));
    }
}
