using System.Buffers.Binary;
using System.Text;
using System.Text.Json;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;
using SimsSimulation;

namespace SimsEngine.Tests;

public sealed class FloorCatalogTests
{
    [Fact]
    public void OpensSortedFlrResourcesAtTheFirstDynamicPatternId()
    {
        var root = Path.Combine(Path.GetTempPath(), "floor-catalog-" + Guid.NewGuid().ToString("N"));
        var floors = Path.Combine(root, "GameData", "Floors");
        Directory.CreateDirectory(floors);
        try
        {
            var buildStrings = new ChunkBuilder().S16(-3).S16(3)
                .U8(1).CString("10").CString("").U8(1).CString("Base").CString("").U8(1).CString("base").CString("");
            File.WriteAllBytes(Path.Combine(root, "GameData", "Build.iff"),
                ChunkBuilder.File(("STR#", 0x82, buildStrings.ToArray())));
            File.WriteAllBytes(Path.Combine(floors, "zeta.flr"), FloorFile("Zeta", "42"));
            File.WriteAllBytes(Path.Combine(floors, "alpha.flr"), FloorFile("Alpha", "37"));

            var catalog = FloorCatalog.Open(root);

            Assert.Equal(37, catalog.Price(256));
            Assert.Equal(42, catalog.Price(257));
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [Fact]
    public void IncludesProviderAssignedFlrIdsBeyondBuildStringCatalog()
    {
        var strings = new ChunkBuilder().S16(-3).S16(3)
            .U8(1).CString("10").CString("")
            .U8(1).CString("Carpet").CString("")
            .U8(1).CString("base floor").CString("");
        var build = new IffFile(ChunkBuilder.File(("STR#", 0x82, strings.ToArray())), "Build.iff");

        var catalog = FloorCatalog.Read(build, dynamicFloors:
        [
            KeyValuePair.Create(256, 37),
            KeyValuePair.Create(65534, 100),
        ]);

        Assert.True(catalog.Contains(1));
        Assert.True(catalog.Contains(256));
        Assert.Equal(37, catalog.Price(256));
        Assert.False(catalog.Contains(65534));
    }

    [Fact]
    public void ReadLotMaterialMap_PrefersChunk1_HandlesMultiEntryAndHighPatternIds_AndToleratesMalformedChunks()
    {
        var chunk0 = PersistWriter.Start(false, 0, "mRLF");
        chunk0.Int32(1);
        chunk0.String("legacy.flr");
        chunk0.Int32(1);
        chunk0.Byte(2);
        chunk0.Byte(1);
        chunk0.Int32(0);

        var chunk1 = PersistWriter.Start(false, 0, "mRLF");
        chunk1.Int32(2);
        chunk1.String("multi.flr");
        chunk1.Int32(2);
        chunk1.Int16(520);
        chunk1.Int16(1);
        chunk1.Int32(0);
        chunk1.Int16(521);
        chunk1.Int16(2);
        chunk1.Int32(0);
        chunk1.String("second.flr");
        chunk1.Int32(1);
        chunk1.Int16(530);
        chunk1.Int16(1);
        chunk1.Int32(0);

        var lot = new IffFile(
            ChunkBuilder.File(("FLRm", 0, chunk0.ToArray()), ("FLRm", 1, chunk1.ToArray())),
            "lot.iff");

        var mapped = SceneExporter.ReadLotMaterialMap(lot, ResourceType.Parse("FLRm"));

        Assert.False(mapped.ContainsKey(258));
        Assert.Equal("multi.flr", mapped[520]);
        Assert.Equal("multi.flr", mapped[521]);
        Assert.Equal("second.flr", mapped[530]);

        var truncated = PersistWriter.Start(false, 0, "mRLF");
        truncated.Int32(2);
        truncated.String("broken.flr");
        var malformedLot = new IffFile(
            ChunkBuilder.File(("FLRm", 1, truncated.ToArray())),
            "broken.iff");

        Assert.Empty(SceneExporter.ReadLotMaterialMap(malformedLot, ResourceType.Parse("FLRm")));
    }

    [Fact]
    public void OldTownHouses_MaterialMapsAndExpansionFarTextures_ResolveCompletely()
    {
        var gameDir = TestGameLocator.Locate();
        if (gameDir is null)
            return;

        var house69Path = Path.Combine(gameDir, "TemplateCommunity", "House69.iff");
        var house73Path = Path.Combine(gameDir, "TemplateCommunity", "House73.iff");
        var ep5Far = Path.Combine(gameDir, "ExpansionPack5", "ExpansionPack5.far");
        if (!File.Exists(house69Path) || !File.Exists(house73Path) || !File.Exists(ep5Far))
            return;

        var flrm = ResourceType.Parse("FLRm");
        var walm = ResourceType.Parse("WALm");

        var lot69 = IffFile.Open(house69Path);
        var floors69 = SceneExporter.ReadLotMaterialMap(lot69, flrm);
        var walls69 = SceneExporter.ReadLotMaterialMap(lot69, walm);

        Assert.Contains("terrafina.flr", floors69.Values, StringComparer.OrdinalIgnoreCase);
        Assert.Contains("almostjade.flr", floors69.Values, StringComparer.OrdinalIgnoreCase);
        Assert.Contains("hazelfloor.flr", floors69.Values, StringComparer.OrdinalIgnoreCase);
        Assert.Contains("tomatocoulis.wll", walls69.Values, StringComparer.OrdinalIgnoreCase);
        Assert.Contains("primarilygreenpaneling.wll", walls69.Values, StringComparer.OrdinalIgnoreCase);

        foreach (var file in floors69.Values)
            Assert.True(FloorCatalog.TryOpenFloorIffByName(gameDir, file, out var iff) && iff is not null, $"Missing floor {file}");
        foreach (var file in walls69.Values)
            Assert.True(WallpaperCatalog.TryOpenWallpaperIffByName(gameDir, file, out var iff) && iff is not null, $"Missing wall {file}");

        var lot73 = IffFile.Open(house73Path);
        var floors73 = SceneExporter.ReadLotMaterialMap(lot73, flrm);
        var walls73 = SceneExporter.ReadLotMaterialMap(lot73, walm);

        Assert.Contains("flanksteakbricks.flr", floors73.Values, StringComparer.OrdinalIgnoreCase);
        Assert.Contains("frozenlavapavers.flr", floors73.Values, StringComparer.OrdinalIgnoreCase);
        Assert.Contains("bananabricks.wll", walls73.Values, StringComparer.OrdinalIgnoreCase);

        foreach (var file in floors73.Values)
            Assert.True(FloorCatalog.TryOpenFloorIffByName(gameDir, file, out var iff) && iff is not null, $"Missing floor {file}");
        foreach (var file in walls73.Values)
            Assert.True(WallpaperCatalog.TryOpenWallpaperIffByName(gameDir, file, out var iff) && iff is not null, $"Missing wall {file}");
    }

    [Fact]
    public void LotWalls_AndSceneExporter_UseArry12HighPatterns_PreserveOnEdit_AndFallbackMissingWalls()
    {
        var tempRoot = Path.Combine(Path.GetTempPath(), $"sims-arry12-walls-{Guid.NewGuid():N}");
        var gameRoot = Path.Combine(tempRoot, "game");
        var wallsDir = Path.Combine(gameRoot, "GameData", "Walls");
        var sceneDir = Path.Combine(tempRoot, "scene");
        Directory.CreateDirectory(wallsDir);
        Directory.CreateDirectory(sceneDir);

        try
        {
            var basePalt = new ChunkBuilder().U32(1).U32(2).U32(0).U32(0).Raw([10, 20, 30, 200, 190, 180]).ToArray();
            var greenPalt = new ChunkBuilder().U32(1).U32(2).U32(0).U32(0).Raw([10, 20, 30, 40, 180, 90]).ToArray();
            var buildStrings = new ChunkBuilder().S16(-3).S16(3)
                .U8(1).CString("4").CString("")
                .U8(1).CString("Drywall").CString("")
                .U8(1).CString("Drywall desc").CString("");
            File.WriteAllBytes(
                Path.Combine(gameRoot, "GameData", "Build.iff"),
                ChunkBuilder.File(("STR#", 0x83, buildStrings.ToArray())));
            File.WriteAllBytes(
                Path.Combine(gameRoot, "GameData", "walls.iff"),
                ChunkBuilder.File(
                    ("PALT", 1, basePalt),
                    ("SPR#", 2, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 3, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 514, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 515, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 1026, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 1027, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 1536, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 1792, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 2048, BuildSolidWallSpr1(4, paltId: 1, colorIndex: 1)),
                    ("SPR#", 4096, BuildSolidWallSpr1(64, paltId: 1, colorIndex: 1)),
                    ("SPR#", 4097, BuildSolidWallSpr1(64, paltId: 1, colorIndex: 1)),
                    ("SPR#", 4098, BuildSolidWallSpr1(64, paltId: 1, colorIndex: 1))));
            File.WriteAllBytes(
                Path.Combine(wallsDir, "green.wll"),
                ChunkBuilder.File(
                    ("PALT", 1537, greenPalt),
                    ("SPR#", 1, BuildSolidWallSpr1(4, paltId: 1537, colorIndex: 1)),
                    ("SPR#", 1793, BuildSolidWallSpr1(4, paltId: 1537, colorIndex: 1)),
                    ("SPR#", 2049, BuildSolidWallSpr1(4, paltId: 1537, colorIndex: 1))));

            var arr2 = new byte[64 * 64 * 8];
            var arr12 = new byte[64 * 64 * 14];
            void SetCell(int x, int y, byte seg, ushort style0, ushort style1, ushort pat4)
            {
                var off2 = (x * 64 + y) * 8;
                arr2[off2] = seg;
                arr2[off2 + 2] = unchecked((byte)style0);
                arr2[off2 + 3] = unchecked((byte)style1);
                arr2[off2 + 4] = unchecked((byte)pat4);

                var off12 = (x * 64 + y) * 14;
                arr12[off12] = seg;
                arr12[off12 + 1] = 15;
                BinaryPrimitives.WriteUInt16LittleEndian(arr12.AsSpan(off12 + 2, 2), style0);
                BinaryPrimitives.WriteUInt16LittleEndian(arr12.AsSpan(off12 + 4, 2), style1);
                BinaryPrimitives.WriteUInt16LittleEndian(arr12.AsSpan(off12 + 6, 2), pat4);
            }

            SetCell(10, 10, 0x01, 1, 1, 275); // Arry2 low byte = 19, Arry12 = 275 (green.wll)
            SetCell(12, 10, 0x01, 1, 1, 500); // Unmapped pattern -> falls back to drywall instead of invisible
            SetCell(14, 10, 0x01, 1, 1, 303); // Arry2 low byte = 47, Arry12 = 303 (preserved on edit)

            var walm = PersistWriter.Start(false, 0, "mLAW");
            walm.Int32(1);
            walm.String("green.wll");
            walm.Int32(1);
            walm.Int16(275);
            walm.Int16(1);
            walm.Int32(0);

            var header = new byte[IffFile.HeaderSize];
            Encoding.ASCII.GetBytes("IFF FILE 2.5:TYPE FOLLOWED BY SIZE\0 JAMIE DOORNBOS & MAXIS 1").CopyTo(header, 0);
            var objt = PersistWriter.Start(false, 3, "tjbo");
            objt.Int32(0);
            var lot = new IffFile(
                ChunkBuilder.File(
                    ("objt", 0, objt.ToArray()),
                    ("WALm", 1, walm.ToArray()),
                    ("Arry", 0, BuildLotArrayChunk(64, 64, 2, new byte[64 * 64 * 2])),
                    ("Arry", 2, BuildLotArrayChunk(64, 64, 8, arr2)),
                    ("Arry", 8, BuildLotArrayChunk(64, 64, 1, Enumerable.Repeat((byte)0x14, 64 * 64).ToArray())),
                    ("Arry", 11, BuildLotArrayChunk(64, 64, 2, new byte[64 * 64 * 2])),
                    ("Arry", 12, BuildLotArrayChunk(64, 64, 14, arr12))),
                "synthetic-arry12.iff");

            // 1. LotWalls reads 16-bit Arry 12 patterns, edits via WallpaperTool, and preserves unmodified 16-bit cells.
            var wallGrid = LotWalls.Read(lot, 1);
            Assert.Equal((ushort)275, wallGrid.GetPattern(10, 10, 4));
            Assert.Equal((ushort)303, wallGrid.GetPattern(14, 10, 4));
            var wpTool = new WallpaperTool(wallGrid, WallpaperCatalog.Read(new IffFile(ChunkBuilder.File(("STR#", 0x83, buildStrings.ToArray())), "Build.iff")), new TestBudget(1000));
            Assert.True(wpTool.Dot(14, 10, 1, 0, 1, erase: false));
            var editedLot = wallGrid.WriteTo(lot);
            var reloaded = LotWalls.Read(editedLot, 1);
            Assert.Equal((ushort)1, reloaded.GetPattern(14, 10, 4));
            Assert.Equal((ushort)275, reloaded.GetPattern(10, 10, 4));
            Assert.Equal((ushort)500, reloaded.GetPattern(12, 10, 4));

            // 2. SceneExporter reads Arry 12 (resolving 275 -> green.wll) and falls back to drywall for missing wall 500.
            var registry = ObjectRegistry.Scan(gameRoot);
            var scenePath = SceneExporter.Export(lot, new SimulationWorld { ObjectRegistry = registry }, registry, gameRoot, sceneDir, house: 1, revision: 1, wallMode: "up");
            var sceneJson = JsonDocument.Parse(File.ReadAllText(scenePath)).RootElement;
            var textures = sceneJson.GetProperty("textures").EnumerateArray().ToArray();
            var sprites = sceneJson.GetProperty("sprites").EnumerateArray().ToArray();
            var missing = sceneJson.GetProperty("missingResources").EnumerateArray().Select(e => e.GetString()!).ToArray();

            Assert.Contains("wall:500:resource", missing);
            var wallSprites = sprites.Where(s => s.TryGetProperty("wall", out var w) && w.ValueKind == JsonValueKind.Object).ToArray();
            Assert.Equal(3, wallSprites.Length);

            var sprite275 = wallSprites.Single(s => s.GetProperty("wall").GetProperty("x").GetInt32() == 10);
            var tex275File = textures[sprite275.GetProperty("texture").GetInt32()].GetProperty("file").GetString()!;
            Assert.StartsWith("wall-275-", tex275File);
            var rgba275 = File.ReadAllBytes(Path.Combine(sceneDir, tex275File));
            Assert.Contains(Enumerable.Range(0, rgba275.Length / 4), p => rgba275[p * 4 + 3] > 0 && rgba275[p * 4 + 1] == 180);

            var sprite500 = wallSprites.Single(s => s.GetProperty("wall").GetProperty("x").GetInt32() == 12);
            var tex500File = textures[sprite500.GetProperty("texture").GetInt32()].GetProperty("file").GetString()!;
            Assert.StartsWith("wall-500-", tex500File);
            var rgba500 = File.ReadAllBytes(Path.Combine(sceneDir, tex500File));
            Assert.Contains(Enumerable.Range(0, rgba500.Length / 4), p => rgba500[p * 4 + 3] > 0 && rgba500[p * 4] == 200);
        }
        finally
        {
            if (Directory.Exists(tempRoot))
                Directory.Delete(tempRoot, recursive: true);
        }
    }

    [Fact]
    public void ExpansionHouses_SceneExport_ResolvesArry12Wallpapers_WithoutInvisibleOrTruncatedWalls()
    {
        var gameDir = TestGameLocator.Locate();
        if (gameDir is null)
            return;

        string? FindHouse(int houseNumber, string fallbackFolder)
        {
            var userHouse = Path.Combine(gameDir, "UserData", "Houses", $"House{houseNumber:D2}.iff");
            if (File.Exists(userHouse)) return userHouse;
            var templateHouse = Path.Combine(gameDir, fallbackFolder, $"House{houseNumber:D2}.iff");
            return File.Exists(templateHouse) ? templateHouse : null;
        }

        var house69 = FindHouse(69, "TemplateCommunity");
        var house73 = FindHouse(73, "TemplateCommunity");
        var house21 = FindHouse(21, "TemplateDowntown");
        if (house69 is null || house73 is null || house21 is null)
            return;

        var tempDir = Path.Combine(Path.GetTempPath(), $"sims-arry12-real-{Guid.NewGuid():N}");
        Directory.CreateDirectory(tempDir);
        try
        {
            var userData = Path.Combine(gameDir, "UserData");
            var registry = ObjectRegistry.Scan(gameDir, Path.Combine(userData, "Characters"));

            (JsonElement Root, string SceneDir) ExportHouse(string path, int houseNumber, int orientation)
            {
                var boot = WorldBootstrap.Load(gameDir, path, lotKey: houseNumber, userDataPath: userData, existingRegistry: registry);
                var houseSceneDir = Path.Combine(tempDir, $"h{houseNumber}");
                Directory.CreateDirectory(houseSceneDir);
                var scenePath = SceneExporter.Export(boot.Lot, boot.World, boot.Registry, gameDir, houseSceneDir,
                    house: checked((short)houseNumber), revision: 1, viewLevel: 1, wallMode: "up", cameraOrientation: orientation);
                return (JsonDocument.Parse(File.ReadAllText(scenePath)).RootElement, Path.GetDirectoryName(scenePath)!);
            }

            void AssertCleanWalls(JsonElement root, string sceneDir, int houseNumber)
            {
                var missing = root.GetProperty("missingResources").EnumerateArray().Select(e => e.GetString()!).ToArray();
                var archMissing = missing.Where(m =>
                    m.StartsWith("wall", StringComparison.OrdinalIgnoreCase) ||
                    m.StartsWith("floor", StringComparison.OrdinalIgnoreCase)).ToArray();
                Assert.Empty(archMissing);

                var textures = root.GetProperty("textures").EnumerateArray().ToArray();
                var wallSprites = root.GetProperty("sprites").EnumerateArray()
                    .Where(s => s.TryGetProperty("wall", out var w) && w.ValueKind == JsonValueKind.Object)
                    .ToArray();
                Assert.NotEmpty(wallSprites);
                foreach (var ws in wallSprites)
                {
                    var file = textures[ws.GetProperty("texture").GetInt32()].GetProperty("file").GetString()!;
                    var bytes = File.ReadAllBytes(Path.Combine(sceneDir, file));
                    Assert.True(Enumerable.Range(0, bytes.Length / 4).Any(p => bytes[p * 4 + 3] > 0),
                        $"House {houseNumber} emitted transparent wall texture {file}");
                }
            }

            var (root69, dir69) = ExportHouse(house69, 69, orientation: 3);
            AssertCleanWalls(root69, dir69, 69);
            var tex69 = root69.GetProperty("textures").EnumerateArray().Select(t => t.GetProperty("file").GetString()!).ToArray();
            Assert.Contains(tex69, f => f.StartsWith("wall-275-", StringComparison.Ordinal));
            Assert.Contains(tex69, f => f.StartsWith("wall-258-", StringComparison.Ordinal));
            Assert.DoesNotContain(tex69, f => f.StartsWith("wall-19-", StringComparison.Ordinal));

            var (root73, dir73) = ExportHouse(house73, 73, orientation: 0);
            AssertCleanWalls(root73, dir73, 73);
            var tex73 = root73.GetProperty("textures").EnumerateArray().Select(t => t.GetProperty("file").GetString()!).ToArray();
            Assert.Contains(tex73, f => f.StartsWith("wall-260-", StringComparison.Ordinal));

            var (root21, dir21) = ExportHouse(house21, 21, orientation: 0);
            AssertCleanWalls(root21, dir21, 21);
            var tex21 = root21.GetProperty("textures").EnumerateArray().Select(t => t.GetProperty("file").GetString()!).ToArray();
            Assert.Contains(tex21, f => f.StartsWith("wall-276-", StringComparison.Ordinal));
            Assert.Contains(tex21, f => f.StartsWith("wall-292-", StringComparison.Ordinal));
            Assert.Contains(tex21, f => f.StartsWith("wall-298-", StringComparison.Ordinal));
        }
        finally
        {
            if (Directory.Exists(tempDir))
                Directory.Delete(tempDir, recursive: true);
        }
    }

    private sealed class TestBudget(int funds) : IFamilyBudget
    {
        public int Funds { get; private set; } = funds;
        public int ReadFamilyBudget() => Funds;
        public void AlterFamilyBudget(int expenseType, int amount) => Funds -= amount;
    }

    private static byte[] BuildLotArrayChunk(int rows, int width, int elementSize, ReadOnlySpan<byte> data)
    {
        var chunk = new byte[20 + data.Length];
        BinaryPrimitives.WriteInt16LittleEndian(chunk.AsSpan(2, 2), 1);
        BinaryPrimitives.WriteInt32LittleEndian(chunk.AsSpan(4, 4), rows);
        BinaryPrimitives.WriteInt32LittleEndian(chunk.AsSpan(8, 4), width);
        BinaryPrimitives.WriteInt32LittleEndian(chunk.AsSpan(12, 4), elementSize);
        data.CopyTo(chunk.AsSpan(20));
        return chunk;
    }

    private static byte[] BuildSolidWallSpr1(int frameCount, uint paltId, byte colorIndex)
    {
        var headerSize = 12 + frameCount * 4;
        var builder = new ChunkBuilder().U32(504).U32((uint)frameCount).U32(paltId);
        for (var i = 0; i < frameCount; i++) builder.U32((uint)headerSize);
        return builder
            .U16(0).U16(0).U16(2).U16(2)
            .U8(4).U8(0).U8(2).U8(2).U8(colorIndex).U8(colorIndex).U8(5).U8(0)
            .ToArray();
    }

    private static byte[] FloorFile(string name, string price)
    {
        var strings = new ChunkBuilder().S16(-3).S16(3)
            .U8(1).CString(name).CString("")
            .U8(1).CString(price).CString("")
            .U8(1).CString("test floor").CString("");
        return ChunkBuilder.File(("STR#", 0, strings.ToArray()));
    }
}
