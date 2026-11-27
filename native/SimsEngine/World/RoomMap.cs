using SimsEngine.Formats;
using System.Buffers.Binary;

namespace SimsEngine.World;

public readonly record struct RoomWallTile(byte Segments, byte Byte1, byte Side1Style, byte Side2Style, byte Byte4, byte Byte5, byte Byte6, byte Byte7);

public readonly record struct RoomRuntimeWallCell(
    byte Segments, byte Byte1, ushort Word2, ushort Word4, ushort Word6, ushort Word8, ushort Word10, ushort Word12)
{
    public static RoomRuntimeWallCell FromSavedRecord(RoomWallTile tile) => new(
        tile.Segments, tile.Byte1, tile.Side1Style, tile.Side2Style, tile.Byte4, tile.Byte5, tile.Byte6, tile.Byte7);
}

public readonly record struct RoomExpandedWallRecord(byte[] Bytes)
{
    public byte[] ToArray() => (byte[])Bytes.Clone();
    public uint UInt32At(int offset) => BinaryPrimitives.ReadUInt32LittleEndian(Bytes.AsSpan(offset, 4));
    public ushort UInt16At(int offset) => BinaryPrimitives.ReadUInt16LittleEndian(Bytes.AsSpan(offset, 2));

    public RoomExpandedWallRecord WithWallStyleOverlay(ushort wallStyle, uint selectedSegments)
    {
        var bytes = ToArray();
        for (var index = 0; index < 6; index++)
        {
            if ((selectedSegments & (1u << index)) == 0) continue;
            BinaryPrimitives.WriteUInt16LittleEndian(bytes.AsSpan(8 + index * 2, 2), wallStyle);
        }
        var flags = BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(0x28, 4));
        BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(0x28, 4), flags | 0x10);
        return new RoomExpandedWallRecord(bytes);
    }

    public byte WallSideOrientation(uint wallBit)
    {
        var index = CategoryIndex(wallBit);
        return index < 4 ? (byte)((UInt32At(4) >> (index * 2)) & 3) : (byte)3;
    }

    public RoomExpandedWallRecord WithWallSideOrientation(uint wallBit, byte orientation)
    {
        var index = CategoryIndex(wallBit);
        if (index >= 4) return this;
        var bytes = ToArray();
        var shift = index * 2;
        var directions = BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(4, 4));
        directions = (directions & ~(3u << shift)) | ((uint)(orientation & 3) << shift);
        BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(4, 4), directions);
        return new RoomExpandedWallRecord(bytes);
    }

    public RoomExpandedWallRecord WithRotatedSides(int quarterTurns)
    {
        var turns = quarterTurns & 3;
        var bytes = ToArray();
        var sourceSegments = UInt32At(0);
        var rotatedSegments = sourceSegments & ~0x3fu;
        var sourceDirections = UInt32At(4);
        uint rotatedDirections = sourceDirections & ~0xffu;
        var sourceCategories = new ushort[6];
        var sourceAdjacent = new ushort[4];
        var sourceDiagonalAdjacent = new ushort[4];
        for (var index = 0; index < sourceCategories.Length; index++)
            sourceCategories[index] = UInt16At(8 + index * 2);
        for (var index = 0; index < sourceAdjacent.Length; index++)
            sourceAdjacent[index] = UInt16At(20 + index * 2);
        for (var index = 0; index < sourceDiagonalAdjacent.Length; index++)
            sourceDiagonalAdjacent[index] = UInt16At(28 + index * 2);
        Array.Clear(bytes, 28, 8);

        for (var sourceIndex = 0; sourceIndex < 6; sourceIndex++)
        {
            var destinationIndex = sourceIndex < 4
                ? (sourceIndex + turns) & 3
                : 4 + ((sourceIndex - 4) ^ (turns & 1));
            var sourceBit = 1u << sourceIndex;
            var destinationBit = 1u << destinationIndex;
            if ((sourceSegments & sourceBit) != 0) rotatedSegments |= destinationBit;
            BinaryPrimitives.WriteUInt16LittleEndian(bytes.AsSpan(8 + destinationIndex * 2, 2), sourceCategories[sourceIndex]);
            if (sourceIndex < 4)
            {
                var orientation = (sourceDirections >> (sourceIndex * 2)) & 3;
                rotatedDirections |= orientation << (destinationIndex * 2);
                BinaryPrimitives.WriteUInt16LittleEndian(bytes.AsSpan(20 + destinationIndex * 2, 2), sourceAdjacent[sourceIndex]);
            }
        }
        for (var sourceIndex = 0; sourceIndex < sourceDiagonalAdjacent.Length; sourceIndex++)
        {
            var destinationIndex = DiagonalAdjacentRotation[turns, sourceIndex];
            BinaryPrimitives.WriteUInt16LittleEndian(bytes.AsSpan(28 + destinationIndex * 2, 2),
                sourceDiagonalAdjacent[sourceIndex]);
        }

        BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(0, 4), rotatedSegments);
        BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(4, 4), rotatedDirections);
        var flags = BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(0x28, 4));
        BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(0x28, 4), flags | 0x10);
        return new RoomExpandedWallRecord(bytes);
    }

    private static readonly int[,] DiagonalAdjacentRotation =
    {
        { 0, 1, 2, 3 },
        { 3, 2, 0, 1 },
        { 1, 0, 3, 2 },
        { 2, 3, 1, 0 },
    };

    public static int CategoryIndex(uint wallBit)
    {
        if (wallBit == 0 || (wallBit & (wallBit - 1)) != 0)
            throw new ArgumentOutOfRangeException(nameof(wallBit), "Expected one set wall bit.");
        return System.Numerics.BitOperations.TrailingZeroCount(wallBit);
    }

    public ushort WallCategory(uint wallBit) => UInt16At(8 + CategoryIndex(wallBit) * 2);

    public ushort AdjacentWallCategory(uint wallBit, int sideSelector = 0)
    {
        var index = CategoryIndex(wallBit);
        var adjusted = sideSelector switch { 1 or 4 => index + 1, 3 => index + 2, _ => index };
        return UInt16At(20 + adjusted * 2);
    }

    public static bool IsRoomWallCategory(ushort category) => category is 1 or 3 or 5 or 6 or 7 or 8 or 9 or 15 or 22 or 23;
}

public readonly record struct RoomTileStatisticsInput(byte? RawGroundWaterGridByte, ushort? FloorGridWord, RoomExpandedWallRecord Walls);

public readonly record struct RoomTileStatisticsContribution(int Counter38, int Counter3C, int Counter54, int Counter60, int Counter64);

public readonly record struct RoomLightCoordinateCell(sbyte FirstX, sbyte FirstY, sbyte SecondX, sbyte SecondY)
{
    public const sbyte EmptyCoordinate = 0x7f;
    public static RoomLightCoordinateCell Empty => new(EmptyCoordinate, EmptyCoordinate, EmptyCoordinate, EmptyCoordinate);

    public int Count => (FirstX != EmptyCoordinate ? 1 : 0) + (SecondX != EmptyCoordinate ? 1 : 0);

    public RoomLightCoordinateCell AddCandidate(sbyte x, sbyte y)
    {
        var count = Count;
        if (count == 0) return this with { FirstX = x, FirstY = y };
        if (count == 1) return this with { SecondX = x, SecondY = y };

        var distance = x * x + y * y;
        if (distance < FirstX * FirstX + FirstY * FirstY)
            return this with { FirstX = x, FirstY = y };
        if (SecondX * SecondX + SecondY * SecondY <= distance) return this;
        return this with { SecondX = x, SecondY = y };
    }

    public RoomLightCoordinateCell RemoveCandidate(sbyte x, sbyte y)
    {
        if (Count == 1)
            return FirstX == x && FirstY == y ? Empty : this;
        if (Count != 2) return this;
        if (FirstX == x && FirstY == y)
            return this with { FirstX = SecondX, FirstY = SecondY, SecondX = EmptyCoordinate, SecondY = EmptyCoordinate };
        return SecondX == x && SecondY == y
            ? this with { SecondX = EmptyCoordinate, SecondY = EmptyCoordinate }
            : this;
    }
}

public readonly record struct RoomObjectStatisticsContribution(int EligibleObjects, int Category4Objects,
    int Category5To7Objects, bool? Category8Flag, int PersonObjects, int RoomImpactSum26,
    int RoomImpactSum28, int NonnegativeImpactCount2A, int LightingObjects140,
    int Type8LightContribution22, int OtherLightContribution24, int ZeroContributionLightCallbacks);

public sealed record RoomScoreTuning
{
    public const float DaylightCeiling = 0.8f;
    public float ObjectLightContributionFactor { get; init; } = 30f;
    public float AreaClipToScore { get; init; } = 60f;
    public float AreaScoreForZeroTiles { get; init; } = -30f;
    public float AreaScoreForClipTile { get; init; } = 30f;
    public float LightScoreForZero { get; init; } = -20f;
    public float LightScoreForOne { get; init; } = 20f;
    public float RoomImpactEffectiveAreaMin { get; init; } = 10f;
    public float RoomImpactEffectiveAreaMax { get; init; } = 45f;
    public float RoomImpactMultiplier { get; init; } = 10f;
    public float OutdoorRoomImpactFactor { get; init; } = 2f;
    public float OutdoorGoodObjectCountFactor { get; init; } = 1f;
    public float OutdoorObjectDivisor { get; init; } = 3f;
    public float OutdoorDaylightBonus { get; init; }
    public float OutdoorDawnDuskBonus { get; init; } = -20f;
    public float OutdoorNighttimeBonus { get; init; } = -50f;
    public float FloorScoreForZero { get; init; } = -40f;
    public float FloorScoreFor100 { get; init; }
    public float WallScoreForZero { get; init; } = -40f;
    public float WallScoreFor100 { get; init; }

    public RoomScoreResult Calculate(in RoomScoreInput input)
    {
        var tileArea = input.Field38 / 2;
        float light;
        float score;
        if (input.Outdoor)
        {
            light = input.Daylight;
            score = input.Field50 * OutdoorRoomImpactFactor + input.Field54 * OutdoorGoodObjectCountFactor;
        }
        else
        {
            var windowLight = tileArea == 0
                ? float.NaN
                : (input.Field44 * 0.01f / tileArea) * ObjectLightContributionFactor;
            var lampLight = tileArea == 0
                ? float.NaN
                : (input.Field48 * 0.01f / tileArea) * ObjectLightContributionFactor;
            var daylightContribution = MathF.Min(windowLight * input.Daylight, input.Daylight);
            var combinedLight = daylightContribution + lampLight;
            light = combinedLight < 0.01f ? 0f : combinedLight > 0.99f ? 1f : combinedLight;

            var effectiveImpactArea = Math.Clamp(tileArea, RoomImpactEffectiveAreaMin, RoomImpactEffectiveAreaMax);
            var clippedArea = MathF.Min(tileArea, AreaClipToScore);
            var floorRange = FloorScoreFor100 - FloorScoreForZero;
            var wallRange = WallScoreFor100 - WallScoreForZero;
            score = (effectiveImpactArea == 0 ? float.NaN : input.Field50 * RoomImpactMultiplier / effectiveImpactArea)
                + (input.Field3C / (float)input.Field38) * floorRange + FloorScoreForZero
                + (input.Field64 / (float)input.Field60) * wallRange + WallScoreForZero
                + light * (LightScoreForOne - LightScoreForZero) + LightScoreForZero
                + (clippedArea / AreaClipToScore) * (AreaScoreForClipTile - AreaScoreForZeroTiles)
                + AreaScoreForZeroTiles;
            if (score >= -100f)
            {
                if (score > 100f) score = 100f;
            }
            else score = -100f;
        }

        var keepRoomLight = input.Outdoor ||
            (input.LightOverrideFlag75 == 0 &&
             (input.LightsEnabledFlag73 == 0 || input.LightingObjectCount140 != 0 ||
              input.PersonObjectCount142 == 0 || input.DaylightCeiling <= light));
        var tileLight = keepRoomLight ? light : input.DaylightCeiling;

        return new RoomScoreResult(score, light, tileLight);
    }

    public static RoomScoreTuning FromSimulatorConstants(SimsEngine.Formats.SimulatorConstants constants)
    {
        ArgumentNullException.ThrowIfNull(constants);
        return new RoomScoreTuning
        {
            ObjectLightContributionFactor = constants.Get("object light contribution factor", 30f),
            AreaClipToScore = constants.Get("area clip to score", 60f),
            AreaScoreForZeroTiles = constants.Get("area score for zero tiles", -30f),
            AreaScoreForClipTile = constants.Get("area score for clip tile", 30f),
            LightScoreForZero = constants.Get("light score for 0.0", -20f),
            LightScoreForOne = constants.Get("light score for 1.0", 20f),
            RoomImpactEffectiveAreaMin = constants.Get("room impact effective area min", 10f),
            RoomImpactEffectiveAreaMax = constants.Get("room impact effective area max", 45f),
            RoomImpactMultiplier = constants.Get("room impact multiplier", 10f),
            OutdoorRoomImpactFactor = constants.Get("outdoor room impact factor", 2f),
            OutdoorGoodObjectCountFactor = constants.Get("outdoor good object count factor", 1f),
            OutdoorObjectDivisor = constants.Get("outdoor object divisor", 3f),
            OutdoorDaylightBonus = constants.Get("outdoor daylight bonus", 0f),
            OutdoorDawnDuskBonus = constants.Get("outdoor dawn/dusk bonus", -20f),
            OutdoorNighttimeBonus = constants.Get("outdoor nighttime bonus", -50f),
            FloorScoreForZero = constants.Get("floor score for 0%", -40f),
            FloorScoreFor100 = constants.Get("floor score for 100%", 0f),
            WallScoreForZero = constants.Get("wall score for 0%", -40f),
            WallScoreFor100 = constants.Get("wall score for 100%", 0f),
        };
    }
}

public readonly record struct RoomScoreInput(
    int Field38, int Field3C, int Field44, int Field48, int Field50, int Field54,
    int Field60, int Field64,
    float Daylight, bool Outdoor,
    byte LightOverrideFlag75 = 0, byte LightsEnabledFlag73 = 0,
    int LightingObjectCount140 = 0, int PersonObjectCount142 = 0,
    float DaylightCeiling = RoomScoreTuning.DaylightCeiling);

public static class RoomRuntimeScalarDefaults
{
    public const float SimsExecutableInitialDaylightScalar = 0f;
    public static float DaylightForTimePhase(int phase, float daylightScalar) =>
        daylightScalar * (phase switch { 1 or 3 => 0.5f, 2 => 0f, _ => 1f });
}

public readonly record struct RoomScoreResult(float RoomScore, float Light, float TileLight = 0f);

public sealed class RoomLightCoordinateGrid
{
    public const int GridSize = 64;
    public const float SimsExecutableInitialLightingScalar = 0f;
    private const short UnassignedDividerRoom = -5;
    private readonly RoomLightCoordinateCell[] _cells =
        Enumerable.Repeat(RoomLightCoordinateCell.Empty, GridSize * GridSize * SimsEngine.Simulation.LotGeometry.MaxSupportedStories).ToArray();

    public static int RadiusFromLightingScalar(float lightingScalar) =>
        checked((int)MathF.Truncate(lightingScalar / 3f));

    public RoomLightCoordinateCell At(int firstCoordinate, int secondCoordinate, int level) =>
        IsCellInBounds(firstCoordinate, secondCoordinate, level)
            ? _cells[Index(firstCoordinate, secondCoordinate, level)]
            : RoomLightCoordinateCell.Empty;

    public int RemoveSource(int centerFirstCoordinate, int centerSecondCoordinate, int level, float lightingScalar,
        int mapDimension = GridSize)
    {
        if (!IsInterior(centerFirstCoordinate, centerSecondCoordinate, level, mapDimension)) return 0;
        var radius = RadiusFromLightingScalar(lightingScalar);
        var updated = 0;
        for (var yOffset = -radius; yOffset <= radius; yOffset++)
        for (var xOffset = -radius; xOffset <= radius; xOffset++)
        {
            var first = centerFirstCoordinate + xOffset;
            var second = centerSecondCoordinate + yOffset;
            if (!IsInterior(first, second, level, mapDimension)) continue;
            var index = Index(first, second, level);
            var next = _cells[index].RemoveCandidate(unchecked((sbyte)xOffset), unchecked((sbyte)yOffset));
            if (next == _cells[index]) continue;
            _cells[index] = next;
            updated++;
        }
        return updated;
    }

    public int AddSource(int centerFirstCoordinate, int centerSecondCoordinate, int level, float lightingScalar,
        Func<int, int, int, short> roomAt,
        Func<int, int, int, (short? First, short? Second)>? adjacentRooms = null,
        bool bridgeUnassignedRoomCells = false, int mapDimension = GridSize)
    {
        ArgumentNullException.ThrowIfNull(roomAt);
        if (!IsInterior(centerFirstCoordinate, centerSecondCoordinate, level, mapDimension)) return 0;
        var sourceRoom = roomAt(centerFirstCoordinate, centerSecondCoordinate, level);
        var radius = RadiusFromLightingScalar(lightingScalar);
        var updated = 0;
        for (var yOffset = -radius; yOffset <= radius; yOffset++)
        for (var xOffset = -radius; xOffset <= radius; xOffset++)
        {
            var first = centerFirstCoordinate + xOffset;
            var second = centerSecondCoordinate + yOffset;
            if (!IsInterior(first, second, level, mapDimension)) continue;
            var candidateRoom = roomAt(first, second, level);
            var include = candidateRoom == sourceRoom;
            if (!include && candidateRoom == UnassignedDividerRoom && bridgeUnassignedRoomCells && adjacentRooms is not null)
            {
                var (adjacentFirstRoom, adjacentSecondRoom) = adjacentRooms(first, second, level);
                include = adjacentFirstRoom == sourceRoom || adjacentSecondRoom == sourceRoom;
            }
            if (!include) continue;
            var index = Index(first, second, level);
            var next = _cells[index].AddCandidate(unchecked((sbyte)xOffset), unchecked((sbyte)yOffset));
            if (next == _cells[index]) continue;
            _cells[index] = next;
            updated++;
        }
        return updated;
    }

    private static bool IsInterior(int x, int y, int level, int mapDimension) =>
        level is >= 1 and <= SimsEngine.Simulation.LotGeometry.MaxSupportedStories &&
        mapDimension is > 2 and <= GridSize && x > 0 && y > 0 &&
        x < mapDimension - 1 && y < mapDimension - 1;

    private static bool IsCellInBounds(int x, int y, int level) =>
        x is >= 0 and < GridSize && y is >= 0 and < GridSize &&
        level is >= 1 and <= SimsEngine.Simulation.LotGeometry.MaxSupportedStories;

    private static int Index(int firstCoordinate, int secondCoordinate, int level) =>
        (level - 1) * GridSize * GridSize + secondCoordinate * GridSize + firstCoordinate;
}

public sealed record RoomLightGridCallbackContext(
    RoomLightCoordinateGrid Grid,
    float LightingScalar,
    Func<SimsEngine.Simulation.XObject, int> LevelAt,
    Func<int, int, int, short> RoomAt,
    Func<int, int, int, (short? First, short? Second)>? AdjacentRooms = null,
    bool BridgeUnassignedRoomCells = false,
    int MapDimension = RoomLightCoordinateGrid.GridSize)
{
    public void RefreshObject(SimsEngine.Simulation.XObject item, bool hasNonzeroContribution)
    {
        ArgumentNullException.ThrowIfNull(item);
        ArgumentNullException.ThrowIfNull(Grid);
        ArgumentNullException.ThrowIfNull(LevelAt);
        ArgumentNullException.ThrowIfNull(RoomAt);
        var firstCoordinate = item.Position.Y >> 4;
        var secondCoordinate = item.Position.X >> 4;
        var level = LevelAt(item);
        Grid.RemoveSource(firstCoordinate, secondCoordinate, level, LightingScalar, MapDimension);
        if (hasNonzeroContribution)
            Grid.AddSource(firstCoordinate, secondCoordinate, level, LightingScalar, RoomAt, AdjacentRooms,
                BridgeUnassignedRoomCells, MapDimension);
    }
}

public sealed class RoomRuntimeStatistics
{
    public int EligibleObjects20 { get; private set; }
    public int Type8LightContribution22 { get; private set; }
    public int OtherLightContribution24 { get; private set; }
    public int RoomImpactSum26 { get; private set; }
    public int RoomImpactSum28 { get; private set; }
    public int NonnegativeImpactCount2A { get; private set; }
    public int Category4Objects2C { get; private set; }
    public int Category5To7Objects2E { get; private set; }
    public int Counter38 { get; private set; }
    public bool Category8Flag3A { get; private set; }
    public int Counter3C { get; private set; }
    public int LightingObjects140 { get; private set; }
    public int PersonObjects142 { get; private set; }
    public int ZeroContributionLightCallbacks { get; private set; }
    public int Counter54 { get; private set; }
    public int Counter60 { get; private set; }
    public int Counter64 { get; private set; }

    public RoomScoreInput ToScoreInput(float daylight, bool outdoor, byte lightOverrideFlag75 = 0,
        byte lightsEnabledFlag73 = 0, float daylightCeiling = RoomScoreTuning.DaylightCeiling) => new(
        Field38: Counter38,
        Field3C: Counter3C,
        Field44: Type8LightContribution22,
        Field48: OtherLightContribution24,
        Field50: RoomImpactSum28,
        Field54: Counter54 + NonnegativeImpactCount2A,
        Field60: Counter60,
        Field64: Counter64,
        Daylight: daylight,
        Outdoor: outdoor,
        LightOverrideFlag75: lightOverrideFlag75,
        LightsEnabledFlag73: lightsEnabledFlag73,
        LightingObjectCount140: LightingObjects140,
        PersonObjectCount142: PersonObjects142,
        DaylightCeiling: daylightCeiling);

    public void Add(in RoomTileStatisticsContribution contribution)
    {
        Counter38 += contribution.Counter38;
        Counter3C += contribution.Counter3C;
        Counter54 += contribution.Counter54;
        Counter60 += contribution.Counter60;
        Counter64 += contribution.Counter64;
    }

    public void Add(in RoomObjectStatisticsContribution contribution)
    {
        EligibleObjects20 += contribution.EligibleObjects;
        Type8LightContribution22 += contribution.Type8LightContribution22;
        OtherLightContribution24 += contribution.OtherLightContribution24;
        RoomImpactSum26 += contribution.RoomImpactSum26;
        RoomImpactSum28 += contribution.RoomImpactSum28;
        NonnegativeImpactCount2A += contribution.NonnegativeImpactCount2A;
        Category4Objects2C += contribution.Category4Objects;
        Category5To7Objects2E += contribution.Category5To7Objects;
        if (contribution.Category8Flag is { } category8) Category8Flag3A = category8;
        LightingObjects140 += contribution.LightingObjects140;
        PersonObjects142 += contribution.PersonObjects;
        ZeroContributionLightCallbacks += contribution.ZeroContributionLightCallbacks;
    }
}

public static class RoomObjectStatistics
{
    public static RoomObjectStatisticsContribution AccumulateTile(SimsEngine.Simulation.SimulationWorld world,
        int tileX, int tileY, int level, ushort statisticsWord0, bool roomBranchFlag,
        Func<SimsEngine.Simulation.XObject, bool> lightingGate, RoomLightGridCallbackContext? lightGrid = null)
    {
        ArgumentNullException.ThrowIfNull(world);
        return AccumulateKnown(world.ObjectsAtTile(tileX, tileY, level), statisticsWord0, roomBranchFlag, lightingGate,
            lightGrid);
    }

    public static RoomObjectStatisticsContribution AccumulateKnown(IEnumerable<SimsEngine.Simulation.XObject> objects,
        ushort statisticsWord0, bool roomBranchFlag, Func<SimsEngine.Simulation.XObject, bool> lightingGate,
        RoomLightGridCallbackContext? lightGrid = null)
    {
        ArgumentNullException.ThrowIfNull(objects);
        ArgumentNullException.ThrowIfNull(lightingGate);
        var eligible = 0;
        var category4 = 0;
        var category5To7 = 0;
        var persons = 0;
        var impactSum26 = 0;
        var impactSum28 = 0;
        var nonnegativeImpactCount2A = 0;
        var lightingObjects140 = 0;
        var type8LightContribution22 = 0;
        var otherLightContribution24 = 0;
        var zeroContributionLightCallbacks = 0;
        bool? category8Flag = null;
        foreach (var item in objects)
        {
            if (item[SimsEngine.Simulation.ObjectData.Hidden] != 0 || item.RoomWord84 < 0) continue;
            eligible++;
            var category = item[SimsEngine.Simulation.ObjectData.Category];
            if (category == 4) category4++;
            else if (category is >= 5 and < 8) category5To7++;
            else if (category == 8) category8Flag = (statisticsWord0 & 0x3ff) != 0;
            var definitionType = item.Definition[(int)SimsEngine.Formats.ObjdField.Type];
            if (definitionType == SimsEngine.Simulation.XPerson.PersonType) persons++;
            var roomImpact = item[SimsEngine.Simulation.ObjectData.RoomImpact];
            impactSum26 += roomImpact;
            if (!roomBranchFlag || roomImpact < 0) impactSum28 += roomImpact;
            if (roomImpact >= 0) nonnegativeImpactCount2A++;

            if ((item[SimsEngine.Simulation.ObjectData.FlagField2] & 0x400) != 0 && lightingGate(item))
            {
                if (definitionType != 8) lightingObjects140++;
                var contribution = item[SimsEngine.Simulation.ObjectData.LightingContribution0100];
                if (contribution == 0)
                {
                    zeroContributionLightCallbacks++;
                    lightGrid?.RefreshObject(item, hasNonzeroContribution: false);
                }
                else
                {
                    if (definitionType == 8) type8LightContribution22 += contribution;
                    else otherLightContribution24 += contribution;
                    lightGrid?.RefreshObject(item, hasNonzeroContribution: true);
                }
            }
        }
        return new RoomObjectStatisticsContribution(eligible, category4, category5To7, category8Flag, persons,
            impactSum26, impactSum28, nonnegativeImpactCount2A, lightingObjects140, type8LightContribution22,
            otherLightContribution24, zeroContributionLightCallbacks);
    }
}

public static class RoomTileStatistics
{
    public static RoomTileStatisticsContribution AccumulateKnown(in RoomTileStatisticsInput input, bool roomBranchFlag)
    {
        var groundByte = input.RawGroundWaterGridByte
            ?? throw new InvalidOperationException("FUN_00467c93 requires the ground grid byte.");
        var counter54 = groundByte < 0x10 ? 1 : 0;
        if (roomBranchFlag) return new RoomTileStatisticsContribution(2, 0, counter54, 0, 0);

        var flags = input.Walls.UInt32At(0);
        var diagonals = flags & 0x30;
        if (diagonals != 0)
        {
            var diagonal = (diagonals & 0x10) != 0;
            var bit = diagonal ? 0x10u : 0x20u;
            var firstSelector = diagonal ? 2 : 1;
            var secondSelector = diagonal ? 4 : 3;
            var baseIndex = RoomExpandedWallRecord.CategoryIndex(bit);
            var baseCategory = input.Walls.WallCategory(bit);
            var selectedCategory = firstSelector == 1 ? input.Walls.UInt16At(8) : input.Walls.UInt16At(20);
            var adjacentPresent = input.Walls.UInt16At(20 + AdjustedIndex(baseIndex, firstSelector) * 2) != 0 ||
                                  input.Walls.UInt16At(20 + AdjustedIndex(baseIndex, secondSelector) * 2) != 0;
            return new RoomTileStatisticsContribution(
                Counter38: 1,
                Counter3C: selectedCategory != 0 ? 1 : 0,
                Counter54: counter54,
                Counter60: RoomExpandedWallRecord.IsRoomWallCategory(baseCategory) ? 1 : 0,
                Counter64: RoomExpandedWallRecord.IsRoomWallCategory(baseCategory) && adjacentPresent ? 1 : 0);
        }

        var floorWord = input.FloorGridWord
            ?? throw new InvalidOperationException("FUN_00467c93 requires the per-level floor grid word.");
        var counter38 = 2;
        var counter3C = floorWord != 0 ? 2 : 0;
        var counter60 = 0;
        var counter64 = 0;
        for (uint bit = 1; bit < 0x20; bit <<= 1)
        {
            if ((flags & bit) == 0) continue;
            if (!RoomExpandedWallRecord.IsRoomWallCategory(input.Walls.WallCategory(bit))) continue;
            counter60++;
            if (input.Walls.AdjacentWallCategory(bit) != 0) counter64++;
        }
        return new RoomTileStatisticsContribution(counter38, counter3C, counter54, counter60, counter64);
    }

    private static int AdjustedIndex(int index, int selector) => selector switch
    {
        1 or 4 => index + 1,
        3 => index + 2,
        _ => index,
    };
}

public sealed class RoomMap
{
    public const ushort NoRoom = 0xFF;

    // Fence and railing wall styles do not divide rooms.
    private static bool Open(int style) => style is 2 or 0xc or 0xd or 0xe;

    private readonly ushort[] _rooms;
    private readonly RoomWallTile[] _wallTiles;
    private readonly RoomRuntimeWallCell[] _runtimeWallTiles;
    private readonly byte[] _roomKeyWallAdjacency;
    private readonly Dictionary<(int X, int Y), Dictionary<int, ushort>> _wallStyleOverlays = [];
    private readonly byte[] _diagonalDividers;
    private readonly byte[] _diagonalWalls;
    private readonly byte[]? _waterGrid;
    private readonly ushort[]? _floorGrid;
    private readonly HashSet<ushort> _outsideRooms = [];
    private readonly IReadOnlyDictionary<ushort, (int X, int Y)[]> _roomTileOrder;

    public int Width { get; }
    public int Height { get; }
    public int Level { get; }
    public int RoomCount { get; }
    public IReadOnlyList<ushort> RoomIds { get; }
    public bool HasAuthoritativeOutsideRooms { get; }
    public bool HasWaterGrid => _waterGrid is not null;

    public bool TryGetWaterGridByte(int x, int y, out byte value)
    {
        if (Level == 1 && _waterGrid is not null && x >= 0 && y >= 0 && x < Width && y < Height)
        {
            value = _waterGrid[y * Width + x];
            return true;
        }
        value = 0;
        return false;
    }

    public byte WaterGridByteAt(int x, int y)
    {
        if (Level != 1 || (uint)x >= Width || (uint)y >= Height) return 0;
        return _waterGrid is null ? (byte)0xff : _waterGrid[y * Width + x];
    }

    public bool TryGetFloorGridWord(int x, int y, out ushort value)
    {
        if (_floorGrid is not null && x >= 0 && y >= 0 && x < Width && y < Height)
        {
            value = _floorGrid[y * Width + x];
            return true;
        }
        value = 0;
        return false;
    }

    public ushort FloorGridWordOrZeroAt(int x, int y)
    {
        if ((uint)x >= Width || (uint)y >= Height) return 0;
        return _floorGrid is null ? (ushort)0 : _floorGrid[y * Width + x];
    }

    public bool HasRoomDividingDiagonal(int x, int y)
    {
        if (x < 0 || y < 0 || x >= Width || y >= Height) return false;
        return _diagonalDividers[y * Width + x] != 0;
    }

    public bool HasDiagonalWall(int x, int y)
    {
        if (x < 0 || y < 0 || x >= Width || y >= Height) return false;
        return _diagonalWalls[y * Width + x] != 0;
    }

    public uint RouteBlockingMaskAt(int x, int y)
    {
        if ((uint)x >= Width || (uint)y >= Height) return 0;
        var segments = _runtimeWallTiles[y * Width + x].Segments;
        uint mask = 0;
        if ((segments & 0x01) != 0) mask |= 0x40;
        if ((segments & 0x02) != 0) mask |= 0x01;
        if ((segments & 0x04) != 0) mask |= 0x04;
        if ((segments & 0x08) != 0) mask |= 0x10;
        return mask;
    }

    public static bool BlocksRouteDirection(uint mask, int direction)
    {
        direction &= 7;
        if (direction != 0)
        {
            mask <<= (8 - direction) & 31;
            mask = (mask & 0xff) | ((mask >> 8) & 0xff);
        }
        return (mask & 1) != 0;
    }

    public bool BlocksRouteDirectionAt(int x, int y, int direction) =>
        BlocksRouteDirection(RouteBlockingMaskAt(x, y), direction);

    private RoomMap(int width, int height, int level, ushort[] rooms, RoomWallTile[] wallTiles,
        RoomRuntimeWallCell[] runtimeWallTiles, byte[] diagonalDividers, byte[] diagonalWalls, byte[]? waterGrid,
        ushort[]? floorGrid, Dictionary<ushort, (int X, int Y)[]> roomTileOrder, int roomCount, byte[]? tileFlags = null,
        bool[]? wallOutsideMask = null)
    {
        Width = width;
        Height = height;
        Level = level;
        _rooms = rooms;
        _wallTiles = wallTiles;
        _runtimeWallTiles = runtimeWallTiles;
        _roomKeyWallAdjacency = new byte[width * height];
        for (var x = 0; x < width; x++)
        for (var y = 0; y < height; y++)
            _roomKeyWallAdjacency[y * width + x] = ComputeRoomKeyWallAdjacency(x, y);
        _diagonalDividers = diagonalDividers;
        _diagonalWalls = diagonalWalls;
        _waterGrid = waterGrid;
        _floorGrid = floorGrid;
        _roomTileOrder = roomTileOrder;
        RoomCount = roomCount;
        RoomIds = rooms.Where(room => room != NoRoom).Distinct().Order().ToArray();
        HasAuthoritativeOutsideRooms = tileFlags is not null || level >= 2;
        foreach (var (room, tiles) in roomTileOrder)
        {
            if (tiles.Length == 0) continue;
            var firstIdx = tiles[0].Y * width + tiles[0].X;
            if (tileFlags is not null)
            {
                if ((tileFlags[firstIdx] & 4) != 0) _outsideRooms.Add(room);
            }
            else if (wallOutsideMask is not null)
            {
                if (wallOutsideMask[firstIdx]) _outsideRooms.Add(room);
            }
            else if (tiles.Any(t => t.X == 0 || t.Y == 0 || t.X == width - 1 || t.Y == height - 1))
            {
                _outsideRooms.Add(room);
            }
        }
    }

    public bool IsOutside(ushort room) => _outsideRooms.Contains(room);

    public bool LightControlFlag75(ushort room)
    {
        if (Level != 1 || _waterGrid is null || !_roomTileOrder.TryGetValue(room, out var tiles) || tiles.Length == 0)
            return false;
        var (x, y) = tiles[0];
        return _waterGrid[y * Width + x] < 0x10;
    }

    public IEnumerable<(int X, int Y)> TilesInRoom(ushort room)
    {
        if (_roomTileOrder.TryGetValue(room, out var tiles))
            foreach (var tile in tiles) yield return tile;
    }

    public int RoomHalfArea(ushort room, bool roomBranchFlag)
    {
        var counter38 = 0;
        foreach (var (x, y) in TilesInRoom(room))
        {
            var input = StatisticsInputAt(x, y)
                ?? throw new InvalidDataException($"Room {room} contains a tile without wall statistics at ({x}, {y}).");
            counter38 += RoomTileStatistics.AccumulateKnown(input, roomBranchFlag).Counter38;
        }
        return counter38 / 2;
    }

    public RoomWallTile? WallAt(int x, int y) =>
        x >= 0 && y >= 0 && x < Width && y < Height ? _wallTiles[y * Width + x] : null;

    public RoomRuntimeWallCell? RuntimeWallAt(int x, int y) =>
        x >= 0 && y >= 0 && x < Width && y < Height ? _runtimeWallTiles[y * Width + x] : null;

    public byte RoomKeyWallAdjacencyAt(int x, int y)
    {
        if ((uint)x >= Width || (uint)y >= Height) return 0;
        return ComputeRoomKeyWallAdjacency(x, y);
    }

    public byte RoomKeyWallAdjacencyGridByteAt(int x, int y) =>
        (uint)x < Width && (uint)y < Height ? _roomKeyWallAdjacency[y * Width + x] : (byte)0;

    private byte ComputeRoomKeyWallAdjacency(int x, int y)
    {
        byte Segments(int cellX, int cellY)
        {
            if (cellX < 1 || cellY < 1 || cellX >= Width - 1 || cellY >= Height - 1) return 0;
            return _runtimeWallTiles[cellY * Width + cellX].Segments;
        }

        var northwest = Segments(x - 1, y - 1);
        var northeast = Segments(x, y - 1);
        var southwest = Segments(x - 1, y);
        var southeast = Segments(x, y);
        byte result = 0;
        if ((northwest & 0x08) != 0) result |= 0x02;
        if ((northwest & 0x20) != 0) result |= 0x10;
        if ((northeast & 0x01) != 0) result |= 0x01;
        if ((northeast & 0x10) != 0) result |= 0x80;
        if ((southwest & 0x04) != 0) result |= 0x04;
        if ((southwest & 0x10) != 0) result |= 0x20;
        if ((southeast & 0x02) != 0) result |= 0x08;
        if ((southeast & 0x20) != 0) result |= 0x40;
        return result;
    }

    private void RefreshRoomKeyWallAdjacencyWindow(int x, int y)
    {
        foreach (var (cellX, cellY) in new[] { (x, y), (x + 1, y), (x, y + 1), (x + 1, y + 1) })
            if ((uint)cellX < Width && (uint)cellY < Height)
                _roomKeyWallAdjacency[cellY * Width + cellX] = ComputeRoomKeyWallAdjacency(cellX, cellY);
    }

    public RoomExpandedWallRecord? ExpandedWallAt(int x, int y)
    {
        if (x < 0 || y < 0 || x >= Width || y >= Height) return null;
        var cell = _runtimeWallTiles[y * Width + x];
        bool HasDiagonal(int nx, int ny) => nx >= 0 && ny >= 0 && nx < Width && ny < Height &&
                                            (_runtimeWallTiles[ny * Width + nx].Segments & 0x30) != 0;
        var bytes = new byte[44];
        BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(0, 4), cell.Segments);
        BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(4, 4), cell.Byte1);
        Write16(8, cell.Word2);
        Write16(10, cell.Word4);
        Write16(16, cell.Word4);
        Write16(18, cell.Word4);
        Write16(20, cell.Word6);
        Write16(22, cell.Word8);
        Write16(24, cell.Word12);
        Write16(26, cell.Word10);
        Write16(28, (cell.Segments & 0x10) != 0 ? cell.Word10 : (ushort)0);
        Write16(30, (cell.Segments & 0x10) != 0 ? cell.Word12 : (ushort)0);
        Write16(32, (cell.Segments & 0x20) != 0 ? cell.Word10 : (ushort)0);
        Write16(34, (cell.Segments & 0x20) != 0 ? cell.Word12 : (ushort)0);
        var neighbors = (HasDiagonal(x - 1, y) ? 4 : 0) |
                        (HasDiagonal(x, y - 1) ? 8 : 0) |
                        (HasDiagonal(x, y + 1) ? 1 : 0) |
                        (HasDiagonal(x + 1, y) ? 2 : 0);
        BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(40, 4), (uint)(0x10 | neighbors));

        if (y + 1 < Height && (_runtimeWallTiles[(y + 1) * Width + x].Segments & 2) != 0)
        {
            Write16(14, _runtimeWallTiles[(y + 1) * Width + x].Word4);
            OverlayDirection((byte)((_runtimeWallTiles[(y + 1) * Width + x].Byte1 & 0x0c) >> 2), 8);
        }
        if (x + 1 < Width && (_runtimeWallTiles[y * Width + x + 1].Segments & 1) != 0)
        {
            Write16(12, _runtimeWallTiles[y * Width + x + 1].Word2);
            OverlayDirection((byte)(_runtimeWallTiles[y * Width + x + 1].Byte1 & 3), 4);
        }
        if (_wallStyleOverlays.TryGetValue((x, y), out var overlays))
        {
            foreach (var (index, style) in overlays)
                Write16(8 + index * 2, style);
            var flags = BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(40, 4));
            BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(40, 4), flags | 0x10);
        }
        return new RoomExpandedWallRecord(bytes);

        void Write16(int offset, ushort value) => BinaryPrimitives.WriteUInt16LittleEndian(bytes.AsSpan(offset, 2), value);
        void OverlayDirection(byte value, uint mask)
        {
            var index = System.Numerics.BitOperations.TrailingZeroCount(mask);
            var shift = index * 2;
            var flags = BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(4, 4));
            flags = (flags & ~(3u << shift)) | ((uint)value << shift);
            BinaryPrimitives.WriteUInt32LittleEndian(bytes.AsSpan(4, 4), flags);
        }
    }

    public bool ApplyWallStyleOverlay(int x, int y, ushort wallStyle, uint selectedSegments,
        RoomExpandedWallRecord refreshedWall)
    {
        if (ExpandedWallAt(x, y) is null) return false;
        var currentIndex = y * Width + x;
        var current = _runtimeWallTiles[currentIndex];
        var sourceSegments = refreshedWall.UInt32At(0);
        var currentSegments = current.Segments;
        var currentByte1 = current.Byte1;
        var word2 = current.Word2;
        var word4 = current.Word4;
        var word6 = current.Word6;
        var word8 = current.Word8;
        var word10 = current.Word10;
        var word12 = current.Word12;

        // Bit 0x20 takes precedence if both diagonal segment bits are present.
        if ((sourceSegments & 0x10) != 0) currentSegments = 0x10;
        else currentSegments &= 0xef;
        if ((sourceSegments & 0x10) != 0)
        {
            word2 = refreshedWall.WallCategory(0x01);
            word4 = refreshedWall.WallCategory(0x10);
            word6 = refreshedWall.AdjacentWallCategory(0x01);
            word10 = refreshedWall.AdjacentWallCategory(0x10, 2);
            word12 = refreshedWall.AdjacentWallCategory(0x10, 4);
        }
        if ((sourceSegments & 0x20) != 0) currentSegments = 0x20;
        else currentSegments &= 0xdf;
        if ((sourceSegments & 0x20) != 0)
        {
            word2 = refreshedWall.WallCategory(0x01);
            word4 = refreshedWall.WallCategory(0x20);
            word8 = refreshedWall.AdjacentWallCategory(0x01);
            word10 = refreshedWall.AdjacentWallCategory(0x20, 1);
            word12 = refreshedWall.AdjacentWallCategory(0x20, 3);
        }

        if ((sourceSegments & 0x01) != 0)
        {
            currentSegments |= 0x01;
            currentByte1 |= refreshedWall.WallSideOrientation(0x01);
            word2 = refreshedWall.WallCategory(0x01);
            word6 = refreshedWall.AdjacentWallCategory(0x01);
            if (x > 0) AddSegment(x - 1, y, 0x04);
        }
        else if ((currentSegments & 0x01) != 0)
        {
            currentSegments &= 0xfe;
            if (x > 0) RemoveSegment(x - 1, y, 0x04, clearWord12: true);
        }

        if ((sourceSegments & 0x02) != 0)
        {
            currentSegments |= 0x02;
            currentByte1 |= (byte)(refreshedWall.WallSideOrientation(0x02) << 2);
            word4 = refreshedWall.WallCategory(0x02);
            word8 = refreshedWall.AdjacentWallCategory(0x02);
            if (y > 0) AddSegment(x, y - 1, 0x08);
        }
        else if ((currentSegments & 0x02) != 0)
        {
            currentSegments &= 0xfd;
            if (y > 0) RemoveSegment(x, y - 1, 0x08, clearWord10: true);
        }

        if ((sourceSegments & 0x04) != 0)
        {
            currentSegments |= 0x04;
            word12 = refreshedWall.AdjacentWallCategory(0x04);
            if (x + 1 < Width)
                AddSegment(x + 1, y, 0x01, word2: refreshedWall.WallCategory(0x04),
                    orientation: refreshedWall.WallSideOrientation(0x04));
        }
        else if ((currentSegments & 0x04) != 0)
        {
            currentSegments &= 0xfb;
            if (x + 1 < Width) RemoveSegment(x + 1, y, 0x01, clearWord6: true);
        }

        if ((sourceSegments & 0x08) != 0)
        {
            currentSegments |= 0x08;
            word10 = refreshedWall.AdjacentWallCategory(0x08);
            if (y + 1 < Height)
                AddSegment(x, y + 1, 0x02, word4: refreshedWall.WallCategory(0x08),
                    orientation: refreshedWall.WallSideOrientation(0x08), orientationShift: 2);
        }
        else if ((currentSegments & 0x08) != 0)
        {
            currentSegments &= 0xf7;
            if (y + 1 < Height) RemoveSegment(x, y + 1, 0x02, clearWord8: true);
        }

        _runtimeWallTiles[currentIndex] = current with
        {
            Segments = currentSegments,
            Byte1 = currentByte1,
            Word2 = word2,
            Word4 = word4,
            Word6 = word6,
            Word8 = word8,
            Word10 = word10,
            Word12 = word12,
        };

        if (!_wallStyleOverlays.TryGetValue((x, y), out var overlays))
            _wallStyleOverlays[(x, y)] = overlays = [];
        for (var index = 0; index < 6; index++)
            if ((selectedSegments & (1u << index)) != 0) overlays[index] = wallStyle;
        RefreshRoomKeyWallAdjacencyWindow(x, y);
        return true;

        void AddSegment(int tileX, int tileY, byte segment, ushort? word2 = null, ushort? word4 = null,
            byte? orientation = null, int orientationShift = 0)
        {
            var index = tileY * Width + tileX;
            var cell = _runtimeWallTiles[index];
            _runtimeWallTiles[index] = cell with
            {
                Segments = (byte)(cell.Segments | segment),
                Word2 = word2 ?? cell.Word2,
                Word4 = word4 ?? cell.Word4,
                Byte1 = orientation is { } side
                    ? (byte)(cell.Byte1 | ((side & 3) << orientationShift))
                    : cell.Byte1,
            };
        }

        void RemoveSegment(int tileX, int tileY, byte segment, bool clearWord6 = false, bool clearWord8 = false,
            bool clearWord10 = false, bool clearWord12 = false)
        {
            var index = tileY * Width + tileX;
            var cell = _runtimeWallTiles[index];
            _runtimeWallTiles[index] = cell with
            {
                Segments = (byte)(cell.Segments & ~segment),
                Word6 = clearWord6 ? (ushort)0 : cell.Word6,
                Word8 = clearWord8 ? (ushort)0 : cell.Word8,
                Word10 = clearWord10 ? (ushort)0 : cell.Word10,
                Word12 = clearWord12 ? (ushort)0 : cell.Word12,
            };
        }
    }

    public RoomTileStatisticsInput? StatisticsInputAt(int x, int y)
    {
        var walls = ExpandedWallAt(x, y);
        if (walls is null) return null;
        byte? groundByte = _waterGrid is not null ? _waterGrid[y * Width + x] : (byte)0xff;
        ushort? floorWord = _floorGrid is not null ? _floorGrid[y * Width + x] : (ushort)0;
        return new RoomTileStatisticsInput(groundByte, floorWord, walls.Value);
    }

    public ushort RoomAt(int x, int y) => _rooms[y * Width + x];

    public byte DiagonalKind(int x, int y) => InBounds(x, y) ? _diagonalDividers[y * Width + x] : (byte)0;

    public (ushort First, ushort Second)? AdjacentRoomsAtTile(int x, int y)
    {
        if (x < 0 || y < 0 || x >= Width || y >= Height) return null;
        var diagonal = _diagonalDividers[y * Width + x];
        if ((diagonal & 0x10) != 0)
            return (RoomAtPosition(x * 16 + 1, y * 16 + 1), RoomAtPosition(x * 16 + 14, y * 16 + 14));
        if ((diagonal & 0x20) != 0)
            return (RoomAtPosition(x * 16 + 14, y * 16 + 1), RoomAtPosition(x * 16 + 1, y * 16 + 14));
        return null;
    }

    public ushort RoomAtPosition(int worldX, int worldY)
    {
        var x = worldX >> 4;
        var y = worldY >> 4;
        if (x < 0 || y < 0 || x >= Width || y >= Height) return NoRoom;
        var room = RoomAt(x, y);
        if (room != NoRoom) return room;
        var index = y * Width + x;
        var diagonal = _diagonalDividers[index];
        if (diagonal == 0) return NoRoom;

        var fractionX = worldX & 0x0f;
        var fractionY = worldY & 0x0f;
        int adjacentX, adjacentY;
        if ((diagonal & 0x10) != 0)
        {
            if (fractionY < 16 - fractionX) { adjacentX = x - 1; adjacentY = y - 1; }
            else { adjacentX = x + 1; adjacentY = y + 1; }
        }
        else
        {
            if (fractionX < fractionY) { adjacentX = x - 1; adjacentY = y + 1; }
            else { adjacentX = x + 1; adjacentY = y - 1; }
        }

        if (InBounds(adjacentX, y))
        {
            room = RoomAt(adjacentX, y);
            if (room != NoRoom) return room;
        }
        if (InBounds(x, adjacentY))
        {
            room = RoomAt(x, adjacentY);
            if (room != NoRoom) return room;
        }
        return NoRoom;
    }

    private bool InBounds(int x, int y) => x >= 0 && y >= 0 && x < Width && y < Height;

    public static bool HasLevel(IffFile file, int level) =>
        level is >= 1 and <= SimsEngine.Simulation.LotGeometry.MaxSupportedStories &&
        (file.Find(ResourceType.Parse("Arry"), WallLayerId(level)) is not null ||
         file.Find(ResourceType.Parse("Arry"), (ushort)(WallLayerId(level) + 10)) is not null ||
         file.Find(ResourceType.Parse("Arry"), FloorLayerId(level)) is not null ||
         file.Find(ResourceType.Parse("Arry"), (ushort)(FloorLayerId(level) + 10)) is not null ||
         file.Find(ResourceType.Parse("Arry"), FlagsLayerId(level)) is not null);

    private static ushort WallLayerId(int level) => (ushort)((level - 1) * 100 + 2);
    private static ushort WaterLayerId => 9;
    private static ushort FloorLayerId(int level) => (ushort)((level - 1) * 100 + 1);
    private static ushort FlagsLayerId(int level) => (ushort)((level - 1) * 100 + 8);

    internal static bool[] ComputeWallOutsideMask(LotWalls walls)
    {
        const int size = LotWalls.Size;
        bool Blocks(int x, int y, int side)
        {
            var record = walls[x, y];
            if ((record[0] & side) != side) return false;
            int? style = side switch
            {
                1 => walls.GetStyle(x, y, 0),
                2 => walls.GetStyle(x, y, 1),
                4 => x + 1 < size && (walls[x + 1, y][0] & 1) != 0 ? walls.GetStyle(x + 1, y, 0) : null,
                _ => y + 1 < size && (walls[x, y + 1][0] & 2) != 0 ? walls.GetStyle(x, y + 1, 1) : null,
            };
            return style is not { } s || !Open(s);
        }
        bool Diagonal(int x, int y) => (walls[x, y][0] & 0x30) != 0 && !Open(walls.GetStyle(x, y, 1));
        return FloodFillWallOutside(size, size, Blocks, Diagonal);
    }

    private static bool[] FloodFillWallOutside(int width, int height, Func<int, int, int, bool> blocks, Func<int, int, bool> diagonal)
    {
        var outside = new bool[width * height];
        var queue = new Queue<(int X, int Y)>();
        for (var x = 0; x < width; x++)
        for (var y = 0; y < height; y++)
        {
            if ((x != 0 && y != 0 && x != width - 1 && y != height - 1) || diagonal(x, y)) continue;
            outside[y * width + x] = true;
            queue.Enqueue((x, y));
        }

        while (queue.Count > 0)
        {
            var (cx, cy) = queue.Dequeue();
            foreach (var (dx, dy, side) in FloodFillSides)
            {
                int nx = cx + dx, ny = cy + dy;
                if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
                var nIdx = ny * width + nx;
                if (outside[nIdx] || diagonal(nx, ny) || blocks(cx, cy, side)) continue;
                outside[nIdx] = true;
                queue.Enqueue((nx, ny));
            }
        }

        return outside;
    }

    public static RoomMap Build(IffFile file, int level, int width, int height, bool importRuntimeWallGrid = true)
    {
        var walls = ReadWallLayerOrEmpty(file, level, width, height);
        var waterChunk = file.Find(ResourceType.Parse("Arry"), WaterLayerId);
        var groundGrid = waterChunk is null ? null : LotArray.Read(file, waterChunk);
        if (groundGrid is not null && (width > groundGrid.Rows || height > groundGrid.Width || groundGrid.ElementSize != 1))
            throw new ArgumentOutOfRangeException(nameof(width), "lot is larger than the stored ground water layer or its element size is invalid");
        var floorChunk = file.Find(ResourceType.Parse("Arry"), (ushort)(FloorLayerId(level) + 10))
            ?? file.Find(ResourceType.Parse("Arry"), FloorLayerId(level));
        var savedFloorGrid = floorChunk is null ? null : LotArray.Read(file, floorChunk);
        if (savedFloorGrid is not null && (width > savedFloorGrid.Rows || height > savedFloorGrid.Width || savedFloorGrid.ElementSize is not (1 or 2)))
            throw new ArgumentOutOfRangeException(nameof(width), "lot is larger than the stored floor layer or its element size is invalid");
        var classification = level == 1 ? groundGrid : savedFloorGrid;
        if (width > walls.Rows || height > walls.Width) throw new ArgumentOutOfRangeException(nameof(width), "lot is larger than the stored layer");
        byte[]? waterGrid = null;
        if (groundGrid is not null)
        {
            waterGrid = new byte[width * height];
            for (var x = 0; x < width; x++)
            for (var y = 0; y < height; y++)
                waterGrid[y * width + x] = groundGrid.Element(x, y)[0];
        }
        byte[]? tileFlags = null;
        if (file.Find(ResourceType.Parse("Arry"), FlagsLayerId(level)) is { } flagChunk
            && LotArray.Read(file, flagChunk) is { ElementSize: 1 } flagGrid && width <= flagGrid.Rows && height <= flagGrid.Width)
        {
            tileFlags = new byte[width * height];
            for (var x = 0; x < width; x++)
            for (var y = 0; y < height; y++)
                tileFlags[y * width + x] = flagGrid.Element(x, y)[0];
        }
        ushort[]? floorGrid = null;
        if (savedFloorGrid is not null)
        {
            floorGrid = new ushort[width * height];
            for (var x = 0; x < width; x++)
            for (var y = 0; y < height; y++)
                floorGrid[y * width + x] = savedFloorGrid.ElementSize == 2
                    ? System.Buffers.Binary.BinaryPrimitives.ReadUInt16LittleEndian(savedFloorGrid.Element(x, y))
                    : savedFloorGrid.Element(x, y)[0];
        }
        bool Classification(int x, int y) => classification is not null && (level == 1
            ? classification.Element(x, y)[0] < 0x10
            : floorGrid![y * width + x] != 0);
        ReadOnlySpan<byte> Record(int x, int y) => walls.Element(x, y);
        bool Blocks(int x, int y, int side)
        {
            var record = Record(x, y);
            if ((record[0] & side) != side) return false;
            int? style = side switch
            {
                1 => record[2],
                2 => record[3],
                4 => x + 1 < width && (Record(x + 1, y)[0] & 1) != 0 ? Record(x + 1, y)[2] : null,
                _ => y + 1 < height && (Record(x, y + 1)[0] & 2) != 0 ? Record(x, y + 1)[3] : null,
            };
            return style is not { } s || !Open(s);
        }
        bool Diagonal(int x, int y) => (Record(x, y)[0] & 0x30) != 0 && !Open(Record(x, y)[3]);

        var rooms = new ushort[width * height];
        var roomKeyBase = unchecked((ushort)((level + 0x3f) * 0x400));
        var wallTiles = new RoomWallTile[width * height];
        var runtimeWallTiles = new RoomRuntimeWallCell[width * height];
        var diagonalDividers = new byte[width * height];
        var diagonalWalls = new byte[width * height];
        for (var x = 0; x < width; x++)
        for (var y = 0; y < height; y++)
        {
            var record = Record(x, y);
            var index = y * width + x;
            wallTiles[index] = new RoomWallTile(record[0], record[1], record[2], record[3], record[4], record[5], record[6], record[7]);
            // SIMI chunk versions 22 and earlier omit runtime wall cells for upper levels.
            runtimeWallTiles[index] = importRuntimeWallGrid
                ? RoomRuntimeWallCell.FromSavedRecord(wallTiles[index])
                : default;
            diagonalWalls[index] = (byte)(record[0] & 0x30);
            if ((record[0] & 0x30) != 0 && !Open(record[3])) diagonalDividers[index] = (byte)(record[0] & 0x30);
        }
        Array.Fill(rooms, NoRoom);
        var assigned = new bool[width * height];
        var roomTileOrder = new Dictionary<ushort, (int X, int Y)[]>();
        var queue = new Queue<(int x, int y)>();
        ushort next = 0;
        for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
        {
            if (assigned[y * width + x] || Diagonal(x, y)) continue;
            var room = (ushort)(roomKeyBase | next++);
            var classificationClass = Classification(x, y);
            var visited = new List<(int X, int Y)> { (x, y) };
            assigned[y * width + x] = true;
            rooms[y * width + x] = room;
            queue.Enqueue((x, y));
            while (queue.Count > 0)
            {
                var (cx, cy) = queue.Dequeue();
                foreach (var (dx, dy, side) in FloodFillSides)
                {
                    int nx = cx + dx, ny = cy + dy;
                    if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
                    if (assigned[ny * width + nx] || Diagonal(nx, ny) || Classification(nx, ny) != classificationClass || Blocks(cx, cy, side)) continue;
                    assigned[ny * width + nx] = true;
                    rooms[ny * width + nx] = room;
                    visited.Add((nx, ny));
                    queue.Enqueue((nx, ny));
                }
            }
            roomTileOrder.Add(room, visited.ToArray());
        }
        var wallOutsideMask = tileFlags is null ? FloodFillWallOutside(width, height, Blocks, Diagonal) : null;
        return new RoomMap(width, height, level, rooms, wallTiles, runtimeWallTiles, diagonalDividers, diagonalWalls,
            waterGrid, floorGrid, roomTileOrder, next, tileFlags, wallOutsideMask);
    }

    private static readonly (int dx, int dy, int side)[] FloodFillSides = [(0, 1, 8), (0, -1, 2), (1, 0, 4), (-1, 0, 1)];

    private static LotArray ReadWallLayerOrEmpty(IffFile file, int level, int width, int height)
    {
        var arryType = ResourceType.Parse("Arry");
        var baseId = WallLayerId(level);
        if (file.Find(arryType, baseId) is { } baseChunk)
            return LotArray.Read(file, baseChunk);
        if (file.Find(arryType, (ushort)(baseId + 10)) is { } advChunk)
        {
            var adv = LotArray.Read(file, advChunk);
            if (adv.ElementSize == LotWalls.AdvancedRecordSize)
            {
                var converted = new byte[adv.Rows * adv.Width * LotWalls.RecordSize];
                for (var r = 0; r < adv.Rows; r++)
                for (var c = 0; c < adv.Width; c++)
                {
                    var src = adv.Element(r, c);
                    var dst = (r * adv.Width + c) * LotWalls.RecordSize;
                    converted[dst] = src[0];
                    converted[dst + 1] = src[1];
                    converted[dst + 2] = src[2];
                    converted[dst + 3] = src[4];
                    for (var p = 0; p < 4; p++)
                        converted[dst + 4 + p] = src[6 + p * 2];
                }
                return LotArray.Read(file, new IffChunk(arryType, baseId, 0, "", 0,
                    LotArray.CreateEmpty(adv.Rows, adv.Width, LotWalls.RecordSize).ToChunkData(converted, LotWalls.RecordSize)));
            }
        }
        if (level >= 2)
            return LotArray.CreateEmpty(Math.Max(width, LotWalls.Size), Math.Max(height, LotWalls.Size), LotWalls.RecordSize);
        throw new ResourceFormatException(file.Source, null, 0, $"no lot layer {baseId}");
    }
}
