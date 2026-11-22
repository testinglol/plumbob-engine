using System.Buffers.Binary;
using System.Globalization;
using System.Text;

namespace SimsEngine.Tests;

internal sealed class CharacterWriter(bool text)
{
    private readonly List<byte> _bytes = [];
    private readonly StringBuilder _text = new();

    public CharacterWriter CmxHeader()
    {
        if (text) _text.Append("// Character File. Copyright 1997, Maxis Inc.\r\nversion 300\r\n");
        return this;
    }

    public CharacterWriter Int(int value)
    {
        if (text) _text.Append(value.ToString(CultureInfo.InvariantCulture)).Append("\r\n");
        else _bytes.AddRange(BitConverter.GetBytes(value));
        return this;
    }

    public CharacterWriter Ints(params int[] values)
    {
        if (text) _text.Append(string.Join(' ', values.Select(value => value.ToString(CultureInfo.InvariantCulture)))).Append("\r\n");
        else foreach (var value in values) _bytes.AddRange(BitConverter.GetBytes(value));
        return this;
    }

    public CharacterWriter Float(float value)
    {
        if (text) _text.Append(value.ToString("R", CultureInfo.InvariantCulture)).Append("\r\n");
        else _bytes.AddRange(BitConverter.GetBytes(value));
        return this;
    }

    public CharacterWriter Floats(params float[] values)
    {
        if (text) _text.Append(string.Join(' ', values.Select(value => value.ToString("R", CultureInfo.InvariantCulture)))).Append("\r\n");
        else foreach (var value in values) _bytes.AddRange(BitConverter.GetBytes(value));
        return this;
    }

    public CharacterWriter Str(string value)
    {
        if (text)
        {
            _text.Append(value).Append("\r\n");
            return this;
        }
        var bytes = Encoding.Latin1.GetBytes(value);
        if (bytes.Length < 0xFF) _bytes.Add((byte)bytes.Length);
        else
        {
            _bytes.Add(0xFF);
            _bytes.AddRange(BitConverter.GetBytes(bytes.Length));
        }
        _bytes.AddRange(bytes);
        return this;
    }

    public CharacterWriter Raw(params byte[] bytes)
    {
        if (text) _text.Append(Encoding.Latin1.GetString(bytes));
        else _bytes.AddRange(bytes);
        return this;
    }

    public byte[] ToArray() => text ? Encoding.Latin1.GetBytes(_text.ToString()) : [.. _bytes];

    public static byte[] U32(uint value)
    {
        var bytes = new byte[4];
        BinaryPrimitives.WriteUInt32LittleEndian(bytes, value);
        return bytes;
    }
}
