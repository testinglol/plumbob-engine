using FSO.Files.Utils;
using Microsoft.Xna.Framework;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace FSO.Vitaboy
{
    public class CFP
    {
        public const int MaximumVectors = 1000000;
        public const float MaximumEncodingError = 0.0032126708614f / 2;
        public static float[] Delta = Enumerable.Range(0, 0xFD).Select(x => (float)(3.9676e-10 * (Math.Pow((double)x - 126, 3) * Math.Abs(x - 126)))).ToArray();
        public byte[] Data;

        public void Read(Stream stream)
        {
            using (var dest = new MemoryStream())
            {
                stream.CopyTo(dest);
                Data = dest.ToArray();
            }
        }

        public byte FindBestDelta(float diff)
        {
            if (float.IsNaN(diff) || float.IsInfinity(diff)) throw new ArgumentException("CFP delta must be finite");
            if (diff == 0) return 126;
            byte closestDelta = 0;
            float closestDeltaDiff = float.PositiveInfinity;
            for (int i = 0; i < Delta.Length; i++)
            {
                var difference = Math.Abs(Delta[i] - diff);
                if (difference < closestDeltaDiff) { closestDeltaDiff = difference; closestDelta = (byte)i; }
            }
            return closestDelta;
        }

        public void EnrichAnim(Animation anim)
        {
            if (anim.TranslationCount > MaximumVectors || anim.RotationCount > MaximumVectors)
                throw new InvalidDataException("CFP vector limit exceeded");
            var translations = new Vector3[anim.TranslationCount];
            var rotations = new Quaternion[anim.RotationCount];
            using (var stream = new MemoryStream(Data))
            using (var io = IoBuffer.FromStream(stream, ByteOrder.LITTLE_ENDIAN))
            {
                ReadNFloats(io, translations.Length, (i, x) => translations[i].X = -x);
                ReadNFloats(io, translations.Length, (i, y) => translations[i].Y = y);
                ReadNFloats(io, translations.Length, (i, z) => translations[i].Z = z);
                ReadNFloats(io, rotations.Length, (i, x) => rotations[i].X = x);
                ReadNFloats(io, rotations.Length, (i, y) => rotations[i].Y = -y);
                ReadNFloats(io, rotations.Length, (i, z) => rotations[i].Z = -z);
                ReadNFloats(io, rotations.Length, (i, w) => rotations[i].W = -w);
            }
            anim.Translations = translations;
            anim.Rotations = rotations;
        }

        public void CompressAnim(Animation anim)
        {
            if (anim.Translations == null || anim.Rotations == null || anim.Translations.Length != anim.TranslationCount || anim.Rotations.Length != anim.RotationCount ||
                anim.TranslationCount > MaximumVectors || anim.RotationCount > MaximumVectors)
                throw new InvalidDataException("CFP vector counts differ from animation data");
            using (var stream = new MemoryStream())
            {
                using (var io = IoWriter.FromStream(stream, ByteOrder.LITTLE_ENDIAN))
                {
                    WriteNFloats(io, anim.Translations.Select(value => -value.X));
                    WriteNFloats(io, anim.Translations.Select(value => value.Y));
                    WriteNFloats(io, anim.Translations.Select(value => value.Z));
                    WriteNFloats(io, anim.Rotations.Select(value => value.X));
                    WriteNFloats(io, anim.Rotations.Select(value => -value.Y));
                    WriteNFloats(io, anim.Rotations.Select(value => -value.Z));
                    WriteNFloats(io, anim.Rotations.Select(value => -value.W));
                }
                Data = stream.ToArray();
            }
        }

        private void WriteNFloats(IoWriter io, IEnumerable<float> values)
        {
            float lastValue = 0;
            int repeats = 0;
            Action flush = () =>
            {
                if (repeats == 1) io.WriteByte(126);
                else if (repeats > 1) { io.WriteByte(0xFE); io.WriteUInt16((ushort)(repeats - 1)); }
                repeats = 0;
            };
            foreach (var value in values)
            {
                if (float.IsNaN(value) || float.IsInfinity(value)) throw new InvalidDataException("CFP value must be finite");
                var difference = value - lastValue;
                var finite = !float.IsNaN(difference) && !float.IsInfinity(difference);
                var code = finite ? FindBestDelta(difference) : (byte)0xFF;
                if (code == 126)
                {
                    repeats++;
                    if (repeats == 65536) flush();
                    continue;
                }
                flush();
                if (!finite || Math.Abs(difference - Delta[code]) > MaximumEncodingError)
                {
                    io.WriteByte(0xFF);
                    io.WriteFloat(value);
                    lastValue = value;
                }
                else
                {
                    io.WriteByte(code);
                    lastValue += Delta[code];
                }
            }
            flush();
        }

        public static void ReadNFloats(IoBuffer io, int floats, Action<int, float> output)
        {
            if (floats < 0 || floats > MaximumVectors) throw new InvalidDataException("Invalid CFP channel length");
            float lastValue = 0;
            for (int i = 0; i < floats; i++)
            {
                var code = io.ReadByte();
                if (code == 0xFE)
                {
                    var run = (int)io.ReadUInt16() + 1;
                    if (run > floats - i) throw new InvalidDataException("CFP repeat exceeds channel length");
                    for (int j = 0; j < run; j++) output(i + j, lastValue);
                    i += run - 1;
                    continue;
                }
                if (code == 0xFF) lastValue = io.ReadFloat();
                else if (code < Delta.Length) lastValue += Delta[code];
                else throw new InvalidDataException("Reserved CFP delta code");
                if (float.IsNaN(lastValue) || float.IsInfinity(lastValue)) throw new InvalidDataException("CFP value must be finite");
                output(i, lastValue);
            }
        }
    }
}
