using FSO.Files.Formats.IFF.Chunks;

internal static class NativePersonDataChecks
{
    internal static object Run()
    {
        int checks = 0;
        void Require(bool condition, string message)
        {
            if (!condition) throw new InvalidDataException(message);
            checks++;
        }

        NBRS RoundTrip(Neighbour neighbor)
        {
            var source = new NBRS();
            source.AddNeighbor(neighbor);
            using var stream = new MemoryStream();
            source.Write(null!, stream);
            stream.Position = 0;
            var decoded = new NBRS();
            decoded.Read(null!, stream);
            return decoded;
        }

        var modernData = Enumerable.Range(0, 256).Select(index => (short)(index - 128)).ToArray();
        modernData[0] = short.MinValue;
        modernData[1] = short.MaxValue;
        modernData[2] = -1;
        modernData[3] = 0;
        modernData[4] = 1;
        var modern = RoundTrip(new Neighbour
        {
            Version = 0xA,
            PersonMode = 5,
            Name = "Modern",
            PersonData = modernData,
            NeighbourID = 1,
            Relationships = new Dictionary<int, List<short>>()
        }).NeighbourByID[1];
        Require(modern.PersonData is { Length: 256 } && modern.PersonData.SequenceEqual(modernData),
            "Modern person data did not preserve all 256 signed values");

        var legacyData = Enumerable.Range(0, 80).Select(index => (short)(index * 17 - 600)).ToArray();
        var legacy = RoundTrip(new Neighbour
        {
            Version = 0x4,
            PersonMode = 5,
            Name = "Legacy",
            PersonData = legacyData,
            NeighbourID = 2,
            Relationships = new Dictionary<int, List<short>>()
        }).NeighbourByID[2];
        Require(legacy.PersonData is { Length: 88 } && legacy.PersonData.Take(80).SequenceEqual(legacyData) && legacy.PersonData.Skip(80).All(value => value == 0),
            "Legacy person data did not retain its 80 values and 88-slot compatibility padding");

        var shortData = new short[] { short.MinValue, short.MaxValue, -1 };
        var padded = RoundTrip(new Neighbour
        {
            Version = 0xA,
            PersonMode = 9,
            Name = "Short",
            PersonData = shortData,
            NeighbourID = 3,
            Relationships = new Dictionary<int, List<short>>()
        }).NeighbourByID[3];
        Require(padded.PersonData is { Length: 256 } && padded.PersonData.Take(3).SequenceEqual(shortData) && padded.PersonData.Skip(3).All(value => value == 0),
            "Short generated person data was not zero-padded on write");

        var nullData = RoundTrip(new Neighbour
        {
            Version = 0xA,
            PersonMode = 5,
            Name = "NullData",
            PersonData = null,
            NeighbourID = 4,
            Relationships = new Dictionary<int, List<short>>()
        }).NeighbourByID[4];
        Require(nullData.PersonData is { Length: 256 } && nullData.PersonData.All(value => value == 0),
            "Null positive-mode person data was not written as zeros");

        var noPersonData = RoundTrip(new Neighbour
        {
            Version = 0xA,
            PersonMode = 0,
            Name = "NoPersonData",
            PersonData = null,
            NeighbourID = 5,
            Relationships = new Dictionary<int, List<short>>()
        }).NeighbourByID[5];
        Require(noPersonData.PersonMode == 0 && noPersonData.PersonData == null,
            "A no-person-data mode unexpectedly consumed or created person data");

        return new { checks, modernValues = 256, legacyValues = 80, compatibilityLength = 88, generatedShortArrayPadding = true,
            nullPersonModes = true };
    }
}
