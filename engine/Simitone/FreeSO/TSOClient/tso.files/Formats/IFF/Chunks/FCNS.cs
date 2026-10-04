using FSO.Files.Utils;
using System.Collections.Generic;
using System.IO;

namespace FSO.Files.Formats.IFF.Chunks
{
    /// <summary>
    /// Duplicate of STR chunk, instead used for simulator constants.
    /// </summary>
    public class FCNS : STR
    {
        /// <summary>The constants by name, as the original's tuning reader looks them up (0x004132b3).</summary>
        public Dictionary<string, float> Values = new Dictionary<string, float>();

        public float Get(string name, float defaultValue)
        {
            return Values.TryGetValue(name, out var value) ? value : defaultValue;
        }

        public override void Read(IffFile iff, Stream stream)
        {
            using (var io = IoBuffer.FromStream(stream, ByteOrder.LITTLE_ENDIAN))
            {
                var zero = io.ReadInt32();
                var version = io.ReadInt32(); //2 in tso
                string magic = io.ReadCString(4); //NSCF
                var count = io.ReadInt32();

                LanguageSets[0].Strings = new STRItem[count];
                for (int i=0; i<count; i++)
                {
                    string name, desc;
                    float value;
                    if (version == 2)
                    {
                        name = io.ReadVariableLengthPascalString();
                        value = io.ReadFloat();
                        desc = io.ReadVariableLengthPascalString();
                    }
                    else
                    {
                        name = io.ReadNullTerminatedString();
                        if (name.Length % 2 == 0) io.ReadByte(); //padding to 2 byte align
                        value = io.ReadFloat();
                        desc = io.ReadNullTerminatedString();
                        if (desc.Length % 2 == 0) io.ReadByte(); //padding to 2 byte align
                    }

                    Values[name] = value;
                    LanguageSets[0].Strings[i] = new STRItem()
                    {
                        Value = name + ": " + value,
                        Comment = desc
                    };
                }
            }
        }

        public override bool Write(IffFile iff, Stream stream)
        {
            return false;
        }
    }
}
