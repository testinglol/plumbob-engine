using System.Buffers.Binary;
using System.Numerics;
using System.Text;
using System.Text.Json;
using SimsEngine.Character;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;
using SimsSDL.Core;
using SimsSimulation;

namespace SimsEngine.Tests;

public sealed class SceneExporterPerformanceTests
{
    [Fact]
    public void BindPose_And_BoneIndices_ReuseCachedSkeletonLayout()
    {
        var skeleton = new Skeleton("adult",
        [
            new Bone("ROOT", "", [], new Vector3(1f, 2f, 3f), Quaternion.Identity, [0, 0, 0], [0f, 0f]),
            new Bone("PELVIS", "ROOT", [], new Vector3(0f, 1f, 0f), Quaternion.Identity, [0, 0, 1], [0f, 0f]),
            new Bone("SPINE", "PELVIS", [], new Vector3(0f, 2f, 0f), Quaternion.Identity, [0, 0, 1], [0f, 0f]),
            new Bone("HEAD", "SPINE", [], new Vector3(0f, 1.5f, 0f), Quaternion.Identity, [0, 0, 1], [0f, 0f]),
        ]);

        var firstBind = Pose.BindPose(skeleton);
        var secondBind = Pose.BindPose(skeleton);
        Assert.Same(firstBind, secondBind);

        var firstIndices = Pose.BoneIndices(skeleton);
        var secondIndices = Pose.BoneIndices(skeleton);
        Assert.Same(firstIndices, secondIndices);
        Assert.Equal(0, firstIndices["ROOT"]);
        Assert.Equal(3, firstIndices["HEAD"]);

        var emptyAnimation = new Animation("idle", "idle", [], 0, 0, 0, []);
        var emptyCurves = new AnimationCurves([], []);
        var idleSample = Pose.Sample(skeleton, emptyAnimation, emptyCurves, 0.0);
        Assert.Same(firstBind, idleSample);

        var activeMotion = new Motion("SPINE", 2, 30f, [0, 0, 0, -1], [], []);
        var activeAnimation = new Animation("nod", "nod", [], 0, 2, 0, [activeMotion]);
        var activeCurves = new AnimationCurves([0f, 2f, 0f, 0f, 3f, 0f], []);
        var activeSample = Pose.Sample(skeleton, activeAnimation, activeCurves, 0.5);
        Assert.True(activeSample[2].Animated);
        Assert.Equal(new Vector3(1f, 5.5f, 3f), activeSample[2].WorldTranslation);
        Assert.Equal(new Vector3(1f, 7f, 3f), activeSample[3].WorldTranslation);
    }

    [Fact]
    public void Sample_OnCyclicSkeleton_ThrowsInvalidDataException()
    {
        var cyclic = new Skeleton("cyclic",
        [
            new Bone("A", "B", [], Vector3.Zero, Quaternion.Identity, [0, 0, 1], [0f, 0f]),
            new Bone("B", "A", [], Vector3.Zero, Quaternion.Identity, [0, 0, 1], [0f, 0f]),
        ]);
        var emptyAnimation = new Animation("idle", "idle", [], 0, 0, 0, []);
        var emptyCurves = new AnimationCurves([], []);

        Assert.Throws<InvalidDataException>(() => Pose.BindPose(cyclic));
        Assert.Throws<InvalidDataException>(() => Pose.Sample(cyclic, emptyAnimation, emptyCurves, 0.0));
    }

    [Fact]
    public void ExportAndAnimation_SkipStaticRebuild_And_MatchCutawayMask()
    {
        var lot = BuildSyntheticLotWithEnclosedRoom();
        var world = new SimulationWorld();
        var roomMap = RoomMap.Build(lot, 1, 64, 64);
        world.LotRoomMaps[1] = roomMap;
        foreach (var roomId in roomMap.RoomIds)
            world.PersonRoomMotiveEntries[roomId] = new PersonRoomMotiveEntry(100f, IsOutside: roomMap.IsOutside(roomId));
        var registry = new ObjectRegistry();
        var tempRoot = Path.Combine(Path.GetTempPath(), $"sims-perf-test-{Guid.NewGuid():N}");
        var gameRoot = Path.Combine(tempRoot, "game");
        var sceneDir = Path.Combine(tempRoot, "scene");
        Directory.CreateDirectory(gameRoot);
        Directory.CreateDirectory(sceneDir);

        try
        {
            var animState = new SceneExporter.AnimationState();
            const long revision = 7;
            var exportedPath = SceneExporter.Export(
                lot, world, registry, gameRoot, sceneDir,
                house: 1, revision: revision, viewLevel: 1, wallMode: "cutaway",
                cameraOrientation: 0, cutawayTile: (11, 11), roofsVisible: false,
                state: animState, cutawayRooms: null, cutawaySim: (11, 11), cutawayZoom: 2);

            Assert.True(File.Exists(exportedPath));

            Assert.True(SceneExporter.CutawayMaskMatches(
                world, animState, revision, viewLevel: 1, wallMode: "cutaway",
                cameraOrientation: 0, cutawayTile: (12, 12), cutawayRooms: null,
                cutawaySim: (12, 12), cutawayZoom: 2));

            Assert.False(SceneExporter.CutawayMaskMatches(
                world, animState, revision, viewLevel: 1, wallMode: "cutaway",
                cameraOrientation: 0, cutawayTile: (2, 2), cutawayRooms: null,
                cutawaySim: (2, 2), cutawayZoom: 2));

            Assert.False(SceneExporter.CutawayMaskMatches(
                world, animState, revision + 1, viewLevel: 1, wallMode: "cutaway",
                cameraOrientation: 0, cutawayTile: (11, 11), cutawayRooms: null,
                cutawaySim: (11, 11), cutawayZoom: 2));
            Assert.Null(SceneExporter.Animation(
                lot, world, registry, gameRoot, sceneDir,
                house: 1, revision: revision + 1, state: animState, sequence: 1, updates: 1,
                viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0,
                cutawayTile: (12, 12), roofsVisible: false, cutawayRooms: null,
                cutawaySim: (12, 12), cutawayZoom: 2));

            var frame = SceneExporter.Animation(
                lot, world, registry, gameRoot, sceneDir,
                house: 1, revision: revision, state: animState, sequence: 1, updates: 2,
                viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0,
                cutawayTile: (12, 12), roofsVisible: false, cutawayRooms: null,
                cutawaySim: (12, 12), cutawayZoom: 2);

            Assert.NotNull(frame);
            using var doc = JsonDocument.Parse(JsonSerializer.Serialize(frame));
            Assert.Equal(1, doc.RootElement.GetProperty("schemaVersion").GetInt32());
            Assert.Equal(revision, doc.RootElement.GetProperty("baseRevision").GetInt64());
            Assert.Equal(1L, doc.RootElement.GetProperty("sequence").GetInt64());
            Assert.Equal(2L, doc.RootElement.GetProperty("updates").GetInt64());

            var secondFrame = SceneExporter.Animation(
                lot, world, registry, gameRoot, sceneDir,
                house: 1, revision: revision, state: animState, sequence: 2, updates: 3,
                viewLevel: 1, wallMode: "cutaway", cameraOrientation: 0,
                cutawayTile: (12, 12), roofsVisible: false, cutawayRooms: null,
                cutawaySim: (12, 12), cutawayZoom: 2, subTickAlpha: 0.5f);
            Assert.NotNull(secondFrame);
        }
        finally
        {
            if (Directory.Exists(tempRoot)) Directory.Delete(tempRoot, recursive: true);
        }
    }

    private static IffFile BuildSyntheticLotWithEnclosedRoom()
    {
        var header = new byte[IffFile.HeaderSize];
        Encoding.ASCII.GetBytes("IFF FILE 2.5:TYPE FOLLOWED BY SIZE\0 JAMIE DOORNBOS & MAXIS 1").CopyTo(header, 0);
        var iff = new IffFile(header, "synthetic-lot.iff");

        var objtStream = PersistWriter.Start(false, 3, "tjbo");
        objtStream.Int32(0);
        iff = iff.WithAddedChunk(ResourceType.Parse("objt"), 0, objtStream.ToArray());

        const ushort terrainHeightsChunkId = 0;
        const ushort tileFlagsChunkId = 8;
        const ushort wallsChunkId = 2;
        const byte indoorTileFlag = 0x10;
        const byte outdoorTileFlag = 0x14;
        const byte westWallSegment = 1;
        const byte northWallSegment = 2;
        const byte eastWallSegment = 4;
        const byte southWallSegment = 8;

        iff = iff.WithAddedChunk(ResourceType.Parse("Arry"), terrainHeightsChunkId, BuildLotArrayChunk(64, 64, 2, new byte[64 * 64 * 2]));
        var flagBytes = new byte[64 * 64];
        for (var x = 0; x < 64; x++)
        for (var y = 0; y < 64; y++)
            flagBytes[x * 64 + y] = x is >= 10 and <= 13 && y is >= 10 and <= 13 ? indoorTileFlag : outdoorTileFlag;
        iff = iff.WithAddedChunk(ResourceType.Parse("Arry"), tileFlagsChunkId, BuildLotArrayChunk(64, 64, 1, flagBytes));

        var wallBytes = new byte[64 * 64 * 8];
        void SetWall(int row, int col, byte segmentBit, int _)
        {
            var offset = (row * 64 + col) * 8;
            wallBytes[offset] |= segmentBit;
            wallBytes[offset + 1] = 0x0f;
            wallBytes[offset + 2] = 1;
            wallBytes[offset + 3] = 1;
        }

        for (var y = 10; y <= 13; y++)
        {
            SetWall(10, y, westWallSegment, 2);
            SetWall(9, y, eastWallSegment, 0);
            SetWall(14, y, westWallSegment, 2);
            SetWall(13, y, eastWallSegment, 0);
        }
        for (var x = 10; x <= 13; x++)
        {
            SetWall(x, 10, northWallSegment, 3);
            SetWall(x, 9, southWallSegment, 0);
            SetWall(x, 14, northWallSegment, 3);
            SetWall(x, 13, southWallSegment, 0);
        }

        iff = iff.WithAddedChunk(ResourceType.Parse("Arry"), wallsChunkId, BuildLotArrayChunk(64, 64, 8, wallBytes));
        return iff;
    }

    private static byte[] BuildLotArrayChunk(int rows, int width, int elementSize, ReadOnlySpan<byte> data)
    {
        var chunk = new byte[20 + data.Length];
        BinaryPrimitives.WriteInt16LittleEndian(chunk.AsSpan(0, 2), 0);
        BinaryPrimitives.WriteInt16LittleEndian(chunk.AsSpan(2, 2), 0);
        BinaryPrimitives.WriteInt32LittleEndian(chunk.AsSpan(4, 4), rows);
        BinaryPrimitives.WriteInt32LittleEndian(chunk.AsSpan(8, 4), width);
        BinaryPrimitives.WriteInt32LittleEndian(chunk.AsSpan(12, 4), elementSize);
        BinaryPrimitives.WriteUInt32LittleEndian(chunk.AsSpan(16, 4), 0u);
        data.CopyTo(chunk.AsSpan(20));
        return chunk;
    }

    [Fact]
    public void ScenePicker_WallAt_PicksSolidOccludedAndWindowCutoutWalls()
    {
        const int w = 10;
        const int h = 20;
        var opaqueRgba = new byte[w * h * 4];
        for (var i = 0; i < w * h; i++)
        {
            opaqueRgba[i * 4] = 200;
            opaqueRgba[i * 4 + 1] = 200;
            opaqueRgba[i * 4 + 2] = 200;
            opaqueRgba[i * 4 + 3] = 255;
        }
        var solidWallDepth = new byte[w * h];
        Array.Fill(solidWallDepth, (byte)100);
        var occluderDepth = new byte[w * h];
        Array.Fill(occluderDepth, (byte)10);

        // Window texture: opaque columns at x in [0..2] and [7..9] and top/bottom bars at y in [0..3] and [16..19];
        // transparent center cutout at x in [3..6], y in [4..15].
        var windowRgba = new byte[w * h * 4];
        var windowDepth = new byte[w * h];
        for (var y = 0; y < h; y++)
        for (var x = 0; x < w; x++)
        {
            var idx = y * w + x;
            var isCutout = x is >= 3 and <= 6 && y is >= 4 and <= 15;
            windowRgba[idx * 4 + 3] = isCutout ? (byte)0 : (byte)255;
            windowDepth[idx] = isCutout ? (byte)255 : (byte)50;
        }

        var solidWallSide = new LotScene.WallSide(5, 5, 1, 0);
        var windowWallSide = new LotScene.WallSide(6, 5, 1, 1);

        var scene = new LotScene
        {
            SchemaVersion = 1,
            House = 1,
            Width = 200,
            Height = 200,
            Textures =
            [
                new LotScene.Texture("solid.rgba", w, h, "rgba"),
                new LotScene.Texture("solid.depth8", w, h, "depth8"),
                new LotScene.Texture("obj.depth8", w, h, "depth8"),
                new LotScene.Texture("window.rgba", w, h, "rgba"),
                new LotScene.Texture("window.depth8", w, h, "depth8"),
            ],
            Sprites =
            [
                new LotScene.Sprite
                {
                    Texture = 0,
                    X = 10,
                    Y = 10,
                    Width = w,
                    Height = h,
                    Flip = false,
                    Depth = 10f,
                    Layer = 1,
                    DepthTexture = 1,
                    DepthNear = 0.4f,
                    DepthFar = 0.6f,
                    Wall = solidWallSide,
                    Level = 1,
                },
                new LotScene.Sprite
                {
                    Texture = 0,
                    X = 10,
                    Y = 10,
                    Width = w,
                    Height = h,
                    Flip = false,
                    ObjectID = 42,
                    Depth = 20f,
                    Layer = 1,
                    DepthTexture = 2,
                    DepthNear = 0.1f,
                    DepthFar = 0.3f,
                    Level = 1,
                },
                new LotScene.Sprite
                {
                    Texture = 3,
                    X = 15,
                    Y = 10,
                    Width = w,
                    Height = h,
                    Flip = false,
                    Depth = 30f,
                    Layer = 1,
                    DepthTexture = 4,
                    DepthNear = 0.2f,
                    DepthFar = 0.3f,
                    Wall = windowWallSide,
                    Level = 1,
                },
            ],
            Limitations = [],
        };

        var picker = new ScenePicker(scene, [opaqueRgba, solidWallDepth, occluderDepth, windowRgba, windowDepth]);

        // Occluding object (ObjectID 42) must not hide the underlying solid wall from WallAt.
        Assert.Equal(42, picker.ObjectAt(new Vector2(12f, 15f), LotZoom.Medium));
        Assert.Equal(solidWallSide, picker.WallAt(new Vector2(12f, 15f), LotZoom.Medium));

        // Inside windowWall's transparent cutout where solidWall lies behind: solidWall (opaque surface) wins over window cutout.
        Assert.Equal(solidWallSide, picker.WallAt(new Vector2(18.5f, 15f), LotZoom.Medium));

        // Opaque border of closer windowWall overlaps solidWall -> closer windowWall wins.
        Assert.Equal(windowWallSide, picker.WallAt(new Vector2(16f, 15f), LotZoom.Medium));

        // Inside windowWall's transparent cutout with no solid wall behind -> windowWall wins via IsInsideWallSpan,
        // including on repeated queries exercising _wallSpanCache.
        Assert.Equal(windowWallSide, picker.WallAt(new Vector2(20.5f, 15f), LotZoom.Medium));
        Assert.Equal(windowWallSide, picker.WallAt(new Vector2(21f, 18f), LotZoom.Medium));

        // Outside all wall spans -> null.
        Assert.Null(picker.WallAt(new Vector2(50f, 50f), LotZoom.Medium));
    }
}
