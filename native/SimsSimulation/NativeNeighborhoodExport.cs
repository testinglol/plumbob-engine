using System.Globalization;
using System.Buffers.Binary;
using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;

internal static class NativeNeighborhoodExport
{
    private sealed record AnimationLayer(float PositionX, float PositionY, string[] FrameResources);
    private sealed record Mode(string BackgroundResource, float Scale, bool Pulsate, int FrameDuration,
        string? Music, string? AmbientSound, AnimationLayer[] AnimationLayers);
    private sealed record Entry(int Ordinal, int House, int X, int Y, string ClosedImagePath, string OpenImagePath,
        int ClosedImageWidth, int ClosedImageHeight, int OpenImageWidth, int OpenImageHeight,
        int ThumbWidth, int ThumbHeight, int XOff, int BaseYOff, int AddYOff, string ClosedImageSource,
        string OpenImageSource, string OffsetsSource, bool Occupied, bool Residential, bool AvailableForCreation,
        int Price, bool Community, string? HouseName, string? HouseDescription, int? Street,
        string? FamilyName, int? FamilyNetWorth, int? FamilyFriends, bool Bulldozed);

    /// <summary>The installed game folder, set by the host so lots can be compared with the empty-lot template.</summary>
    internal static string? GameRoot { get; set; }

    private static readonly IReadOnlyDictionary<int, Mode> Modes = new Dictionary<int, Mode>
    {
        [1] = new("UIGraphics/Nbhd/NScreen.BMP", 1f, true, 15, "bkground_nhood1", null,
            [Layer("Nbhd/DiffN1-N2_8.bmp", "Nbhd/DiffN1-N3_8.bmp", "Nbhd/DiffN1-N4_8.bmp")]),
        [2] = new("UIGraphics/Downtown/DScreen.bmp", 1f, true, 15, "station_dtnhood", null,
            [Layer("Downtown/dscreen00.bmp", "Downtown/dscreen01.bmp", "Downtown/dscreen02.bmp", "Downtown/dscreen03.bmp", "Downtown/dscreen04.bmp")]),
        [3] = new("UIGraphics/VIsland/visland.bmp", 1f, true, 15, "station_vacation", null,
            [Layer("VIsland/visland_waves001.bmp", "VIsland/visland_waves002.bmp", "VIsland/visland_waves003.bmp", "VIsland/visland_waves004.bmp", "VIsland/visland_waves005.bmp"),
             Layer("VIsland/visland_port.bmp"), Layer("VIsland/visland_trees.bmp")]),
        [4] = new("UIGraphics/Community/NScreen_unleashed.bmp", 2f, false, 15, "bkground_nhood1", "river_loop",
            [Layer("Community/NScreen_unleashed_waves001.bmp", "Community/NScreen_unleashed_waves002.bmp", "Community/NScreen_unleashed_waves003.bmp", "Community/NScreen_unleashed_waves004.bmp", "Community/NScreen_unleashed_waves005.bmp", "Community/NScreen_unleashed_waves006.bmp")]),
        [5] = new("UIGraphics/Studiotown/DScreen.bmp", 1f, true, 15, "station_superstar", null,
            [Layer("Studiotown/DScreen_top_layer.bmp")]),
        [7] = new("UIGraphics/Magicland/DScreen.bmp", 1f, false, 15, "music_magictown", "mt_river_loop",
            [LayerAt(0, 62, "Magicland/DScreen_waves1.bmp", "Magicland/DScreen_waves2.bmp", "Magicland/DScreen_waves3.bmp", "Magicland/DScreen_waves4.bmp", "Magicland/DScreen_waves5.bmp", "Magicland/DScreen_waves6.bmp")])
    };

    // With Unleashed installed, the original main neighborhood screen (0x00556bc9) always loads an Unleashed-style map
    // with six wave layers instead of Nbhd/NScreen.BMP, plays bkground_nhood1, and still reads its lots from STR# 1.
    // The phone-travel destination (mode 4) uses the same art in "Choose Destination" mode with station_unleashed.
    private static readonly Mode UnleashedMain = Modes[4] with { Music = "bkground_nhood1" };

    /// <summary>The map configuration for a mode, taking installed expansions into account.</summary>
    private static Mode Configure(int mode, out string variant)
    {
        if (!Modes.TryGetValue(mode, out var config)) throw new ArgumentOutOfRangeException(nameof(mode), "Unsupported neighborhood mode");
        variant = "base";
        if (mode == 1 && UnleashedInstalled)
        {
            variant = "unleashed";
            return UnleashedMain;
        }
        return config;
    }

    /// <summary>Whether the selected installation contains The Sims: Unleashed.</summary>
    internal static bool UnleashedInstalled => GameRoot != null && Directory.Exists(Path.Combine(GameRoot, "ExpansionPack5"));

    private static AnimationLayer Layer(params string[] frames) => LayerAt(0, 0, frames);
    private static AnimationLayer LayerAt(float x, float y, params string[] frames) =>
        new(x, y, frames.Select(frame => "UIGraphics/" + frame).ToArray());

    internal static object Export(string session, int mode)
    {
        var config = Configure(mode, out var variant);
        var neighborhood = Content.Get().Neighborhood;
        var locations = neighborhood.LotLocations.Get<STR>((ushort)mode) ?? throw new InvalidDataException($"LotLocations.iff has no STR chunk for mode {mode}");
        var outputDirectory = Path.Combine(Path.GetFullPath(session), "neighborhood");
        Directory.CreateDirectory(outputDirectory);
        var entries = new List<Entry>(locations.Length);

        for (var index = 0; index < locations.Length; index++)
        {
            var fields = locations.GetString(index).Split(',');
            if (fields.Length < 3 || !int.TryParse(fields[0].Trim(), NumberStyles.Integer, CultureInfo.InvariantCulture, out var house) ||
                !int.TryParse(fields[1].Trim(), NumberStyles.Integer, CultureInfo.InvariantCulture, out var x) ||
                !int.TryParse(fields[2].Trim(), NumberStyles.Integer, CultureInfo.InvariantCulture, out var y))
                throw new InvalidDataException($"Invalid LotLocations entry {index} for mode {mode}");

            var houseName = $"House{house:D2}.iff";
            var houseFile = neighborhood.GetHouse(house);
            var closed = houseFile.Get<BMP>(513) ?? throw new InvalidDataException($"{houseName} is missing BMP chunk 513");
            var open = houseFile.Get<BMP>(512) ?? throw new InvalidDataException($"{houseName} is missing BMP chunk 512");
            var offsets = houseFile.Get<THMB>(512) ?? throw new InvalidDataException($"{houseName} is missing THMB chunk 512");
            var family = neighborhood.GetFamilyForHouse((short)house);
            var occupied = family != null;
            var familyName = family == null ? null : neighborhood.GetFamilyString((ushort)family.ChunkID)?.GetString(0);
            var description = neighborhood.NeighbourhoodDesc?.Get<STR>((ushort)(2000 + house));
            var lotName = description != null && description.Length > 0 ? description.GetString(0).Trim() : null;
            var houseDescription = description != null && description.Length > 1 ? description.GetString(1).Trim() : null;
            var streets = neighborhood.StreetNames?.Get<STR>(2001);
            int? street = streets != null && house - 1 >= 0 && house - 1 < streets.Length &&
                int.TryParse(streets.GetString(house - 1).Trim(), NumberStyles.Integer, CultureInfo.InvariantCulture, out var streetValue) ? streetValue : null;
            var residential = neighborhood.ZoningDictionary.TryGetValue((short)house, out var zoning) && zoning == 0;
            var price = houseFile.Get<SIMI>(1)?.PurchaseValue ?? 0;
            var closedDimensions = ReadBitmapDimensions(closed.data, houseName, 513);
            var openDimensions = ReadBitmapDimensions(open.data, houseName, 512);
            var closedFilename = $"house{house:D2}-closed.bmp";
            var openFilename = $"house{house:D2}-open.bmp";
            var closedPath = Path.Combine(outputDirectory, closedFilename);
            var openPath = Path.Combine(outputDirectory, openFilename);
            File.WriteAllBytes(closedPath, closed.data);
            File.WriteAllBytes(openPath, open.data);
            var source = $"UserData/Houses/{houseName}";
            entries.Add(new Entry(index, house, x, y, Path.Combine("neighborhood", closedFilename), Path.Combine("neighborhood", openFilename),
                closedDimensions.Width, closedDimensions.Height, openDimensions.Width, openDimensions.Height,
                offsets.Width, offsets.Height, offsets.XOff, offsets.BaseYOff, offsets.AddYOff,
                $"{source}#BMP:513", $"{source}#BMP:512", $"{source}#THMB:512", occupied, residential,
                !occupied && residential && price is >= 0 and <= 20_000,
                price, neighborhood.ZoningDictionary.TryGetValue((short)house, out var zone) && zone == 1,
                string.IsNullOrEmpty(lotName) ? null : lotName, string.IsNullOrEmpty(houseDescription) ? null : houseDescription, street,
                familyName, family == null ? null : family.Budget + family.ValueInArch, family == null ? null : neighborhood.RecountFamilyFriends(family),
                GameRoot != null && NativeNeighborhoodEdits.IsBulldozed(neighborhood.UserPath, house, GameRoot)));
        }

        var manifest = new
        {
            schemaVersion = 2,
            mode,
            variant,
            neighborhood = NativeNeighborhoods.Current,
            neighborhoods = NativeNeighborhoods.Installed(Path.GetFullPath(Path.Combine(neighborhood.UserPath, ".."))),
            backgroundResource = config.BackgroundResource,
            backgroundSource = "UIGraphics/UIGraphics.far#" + config.BackgroundResource["UIGraphics/".Length..],
            canvasWidth = 800,
            canvasHeight = 600,
            scale = config.Scale,
            pulsate = config.Pulsate,
            frameDuration = config.FrameDuration,
            music = config.Music,
            ambientSound = config.AmbientSound,
            animationLayers = config.AnimationLayers,
            locationsSource = $"UserData/LotLocations.iff#STR:{mode}",
            entries,
            families = mode == 1 ? UnhousedFamilies() : []
        };
        File.WriteAllText(Path.Combine(Path.GetFullPath(session), "neighborhood.json"),
            System.Text.Json.JsonSerializer.Serialize(manifest, new System.Text.Json.JsonSerializerOptions { PropertyNamingPolicy = System.Text.Json.JsonNamingPolicy.CamelCase, WriteIndented = true }));
        return manifest;
    }

    internal sealed record FamilyChoice(int Id, string Name, int Budget, int NetWorth, int Friends, string[] Members);

    /// Households in Neighborhood.iff without a lot, as the original Select a Family screen lists them.
    /// Townie records (FAMI flags 0) and empty families are excluded.
    internal static FamilyChoice[] UnhousedFamilies()
    {
        var neighborhood = Content.Get().Neighborhood;
        var names = neighborhood.Neighbors?.NeighbourByID.Values
            .GroupBy(neighbor => neighbor.GUID).ToDictionary(group => group.Key, group => group.First().Name) ?? [];
        return neighborhood.MainResource.List<FAMI>()
            .Where(family => family.HouseNumber == 0 && family.FamilyGUIDs.Length > 0 && family.Unknown != 0)
            .OrderBy(family => family.ChunkID)
            .Select(family => new FamilyChoice(family.ChunkID,
                neighborhood.GetFamilyString(family.ChunkID)?.GetString(0) ?? "",
                family.Budget, family.Budget + family.ValueInArch, Content.Get().Neighborhood.RecountFamilyFriends(family),
                family.FamilyGUIDs.Select(guid => names.TryGetValue(guid, out var name) ? name : "").ToArray()))
            .ToArray();
    }

    private static (int Width, int Height) ReadBitmapDimensions(byte[] data, string filename, ushort chunkID)
    {
        if (data.Length < 26 || data[0] != (byte)'B' || data[1] != (byte)'M')
            throw new InvalidDataException($"{filename} BMP chunk {chunkID} has an invalid bitmap header");
        var headerSize = BinaryPrimitives.ReadUInt32LittleEndian(data.AsSpan(14, 4));
        int width;
        int height;
        if (headerSize == 12)
        {
            width = BinaryPrimitives.ReadUInt16LittleEndian(data.AsSpan(18, 2));
            height = BinaryPrimitives.ReadUInt16LittleEndian(data.AsSpan(20, 2));
        }
        else if (headerSize >= 40 && headerSize <= data.Length - 14)
        {
            width = BinaryPrimitives.ReadInt32LittleEndian(data.AsSpan(18, 4));
            var signedHeight = BinaryPrimitives.ReadInt32LittleEndian(data.AsSpan(22, 4));
            height = checked((int)Math.Abs((long)signedHeight));
        }
        else
        {
            throw new InvalidDataException($"{filename} BMP chunk {chunkID} has an unsupported bitmap header");
        }
        if (width <= 0 || height <= 0) throw new InvalidDataException($"{filename} BMP chunk {chunkID} has invalid dimensions");
        return (width, height);
    }
}
