using FSO.LotView;
using FSO.LotView.Components;
using FSO.LotView.Model;
using FSO.SimAntics;
using System.Text.Json;

internal static class NativeCameraGeometryChecks
{
    internal static object Run(VM vm)
    {
        var checks = 0;
        void Require(bool condition, string message)
        {
            if (!condition) throw new InvalidDataException(message);
            checks++;
        }

        var flatTransforms = new NativeEntityTransform((_, _) => 0);
        var flatObjects = vm.Entities.OfType<VMGameObject>()
            .Where(entity => entity.Container == null && entity.Position.Level == 1 && entity.Position.x >= 0 && entity.Position.y >= 0)
            .Take(12).ToArray();
        Require(flatObjects.Length > 0, "The camera geometry fixture has no ground-floor objects to check");
        foreach (var entity in flatObjects)
        {
            // VMGameObject.Position stores WorldUI.Position = tile centre − (½,½), the corner DGRPRenderer draws from;
            // the native anchor is the tile centre, so shift it back before comparing.
            // (The headless VM never positions its WorldUI, so apply the same setter formula here.)
            var expected = entity.Position.ToVector3() - new Microsoft.Xna.Framework.Vector3(0.5f, 0.5f, 0);
            var actual = flatTransforms.Position(entity) - new Microsoft.Xna.Framework.Vector3(0.5f, 0.5f, 0);
            Require(Microsoft.Xna.Framework.Vector3.Distance(actual, expected) < 0.001f,
                $"Flat-ground object {entity.ObjectID} anchor differs from its original ObjectComponent position: expected {expected}, actual {actual}");
        }
        var flatAvatars = vm.Entities.OfType<VMAvatar>()
            .Where(entity => entity.Container == null && entity.Position.Level == 1 && entity.Position.x >= 0 && entity.Position.y >= 0)
            .Take(8).ToArray();
        Require(flatAvatars.Length > 0, "The camera geometry fixture has no ground-floor avatars to check");
        foreach (var entity in flatAvatars)
        {
            var expected = entity.Position.ToVector3();
            var actual = flatTransforms.Position(entity);
            Require(Microsoft.Xna.Framework.Vector3.Distance(actual, expected) < 0.001f,
                $"Flat-ground avatar {entity.ObjectID} anchor differs from its original AvatarComponent position: expected {expected}, actual {actual}");
        }

        for (var orientation = 0; orientation < 4; orientation++)
        {
            const int width = 4;
            const int height = 3;
            const int sourceX = 1;
            const int sourceY = 1;
            var walls = new WallTile[width * height];
            walls[sourceY * width + sourceX] = new WallTile
            {
                Segments = WallSegments.TopLeft | WallSegments.TopRight,
                TopLeftPattern = 101, TopRightPattern = 202, BottomLeftPattern = 303, BottomRightPattern = 404,
                TopLeftStyle = 11, TopRightStyle = 12, ObjSetTLStyle = 21, ObjSetTRStyle = 22,
                TopLeftDoor = true, TopRightDoor = false
            };
            walls[(sourceY + 1) * width + sourceX] = new WallTile { TopRightStyle = 32, ObjSetTRStyle = 42, TopRightDoor = true };
            walls[sourceY * width + sourceX + 1] = new WallTile { TopLeftStyle = 31, ObjSetTLStyle = 41, TopLeftDoor = false };
            var diagonalSource = new WallTile
            {
                Segments = WallSegments.HorizontalDiag,
                TopLeftPattern = 303, TopLeftStyle = 404, TopRightPattern = 505, TopRightStyle = 606,
                BottomLeftPattern = 707, BottomRightPattern = 808
            };
            walls[1 * width + 3] = diagonalSource;
            var blueprint = new Blueprint(width, height) { Cutaway = new bool[width * height] };
            blueprint.Walls[0] = walls;
            var cuts = new WallCuts[width * height];
            cuts[sourceY * width + sourceX] = new WallCuts { TLCut = WallCut.DownLeftUpRight, TRCut = WallCut.DownRightUpLeft };
            cuts[(sourceY + 1) * width + sourceX] = new WallCuts { TRCut = WallCut.Down };
            cuts[sourceY * width + sourceX + 1] = new WallCuts { TLCut = WallCut.Up };
            var up = new JunctionFlags[width * height];
            var down = new JunctionFlags[width * height];
            up[sourceY * width + sourceX] = JunctionFlags.TopLeft | JunctionFlags.DiagLeft;
            down[sourceY * width + sourceX] = JunctionFlags.TopRight | JunctionFlags.DiagBottom;
            var source = new WallComponent.WallGeometry { Width = width, Height = height, Walls = walls, Cuts = cuts, UpJunctions = up, DownJunctions = down };
            var rotated = WallComponent.RotateForCamera(blueprint, 1, source, (WorldRotation)orientation);
            var outputWidth = orientation % 2 == 0 ? width : height;
            var outputHeight = orientation % 2 == 0 ? height : width;
            Require(rotated.Width == outputWidth && rotated.Height == outputHeight, "Rotated wall grid dimensions differ from camera dimensions");

            var camera = new NativeLotCamera(orientation, width, height);
            var cameraPoint = camera.CameraPoint(sourceX + 0.5f, sourceY + 0.5f);
            var outputX = (int)MathF.Floor(cameraPoint.X);
            var outputY = (int)MathF.Floor(cameraPoint.Y);
            Require(camera.SourceTile(outputX, outputY) == (sourceX, sourceY), "Rotated wall picking did not map the emitted cell back to its source tile");
            var wall = rotated.Walls[outputY * rotated.Width + outputX];
            var expectedSegments = orientation switch
            {
                0 => WallSegments.TopLeft | WallSegments.TopRight,
                1 => WallSegments.TopRight | WallSegments.BottomRight,
                2 => WallSegments.BottomRight | WallSegments.BottomLeft,
                _ => WallSegments.BottomLeft | WallSegments.TopLeft
            };
            var expectedPatterns = orientation switch
            {
                0 => (101, 202, 303, 404),
                1 => (303, 101, 404, 202),
                2 => (404, 303, 202, 101),
                _ => (202, 404, 101, 303)
            };
            var expectedSides = orientation switch
            {
                0 => (11, 12, 21, 22, true, false),
                1 => (32, 11, 42, 21, true, true),
                2 => (31, 32, 41, 42, false, true),
                _ => (12, 31, 22, 41, false, false)
            };
            Require(wall.Segments == expectedSegments, "Orthogonal walls must remain in frames 0/1 after every quarter turn");
            Require((wall.TopLeftPattern, wall.TopRightPattern, wall.BottomLeftPattern, wall.BottomRightPattern) == expectedPatterns,
                $"Asymmetric orthogonal wall patterns changed sides during rotation {orientation}: actual {(wall.TopLeftPattern, wall.TopRightPattern, wall.BottomLeftPattern, wall.BottomRightPattern)}, expected {expectedPatterns}");
            Require((wall.TopLeftStyle, wall.TopRightStyle, wall.ObjSetTLStyle, wall.ObjSetTRStyle, wall.TopLeftDoor, wall.TopRightDoor) == expectedSides,
                $"Orthogonal wall styles, object styles, or doors changed incorrectly at rotation {orientation}: actual {(wall.TopLeftStyle, wall.TopRightStyle, wall.ObjSetTLStyle, wall.ObjSetTRStyle, wall.TopLeftDoor, wall.TopRightDoor)}, expected {expectedSides}");

            var expectedCuts = orientation switch
            {
                0 => (WallCut.DownLeftUpRight, WallCut.DownRightUpLeft),
                1 => (WallCut.Down, WallCut.DownLeftUpRight),
                2 => (WallCut.Up, WallCut.Down),
                _ => (WallCut.DownRightUpLeft, WallCut.Up)
            };
            var actualCuts = rotated.Cuts[outputY * rotated.Width + outputX];
            Require((actualCuts.TLCut, actualCuts.TRCut) == expectedCuts,
                $"Rotated wall cuts did not use expected neighbors at rotation {orientation}: actual {(actualCuts.TLCut, actualCuts.TRCut)}, expected {expectedCuts}");

            var expectedUp = orientation switch
            {
                0 => JunctionFlags.TopLeft | JunctionFlags.DiagLeft,
                1 => JunctionFlags.TopRight | JunctionFlags.DiagTop,
                2 => JunctionFlags.BottomRight | JunctionFlags.DiagRight,
                _ => JunctionFlags.BottomLeft | JunctionFlags.DiagBottom
            };
            var expectedDown = orientation switch
            {
                0 => JunctionFlags.TopRight | JunctionFlags.DiagBottom,
                1 => JunctionFlags.BottomRight | JunctionFlags.DiagLeft,
                2 => JunctionFlags.BottomLeft | JunctionFlags.DiagTop,
                _ => JunctionFlags.TopLeft | JunctionFlags.DiagRight
            };
            var outputOffset = outputY * rotated.Width + outputX;
            Require(rotated.UpJunctions[outputOffset] == expectedUp && rotated.DownJunctions[outputOffset] == expectedDown,
                "Rotated wall junction flags moved to the wrong corner or diagonal");
            Require((JunctionFlags)camera.UnrotateJunction((int)expectedUp) == up[sourceY * width + sourceX],
                "Exported junction picking metadata does not round-trip to its original source flags");

            var diagonalPoint = camera.CameraPoint(3.5f, 1.5f);
            var diagonalX = (int)MathF.Floor(diagonalPoint.X);
            var diagonalY = (int)MathF.Floor(diagonalPoint.Y);
            var diagonal = rotated.Walls[diagonalY * rotated.Width + diagonalX];
            var expectedDiagonal = orientation % 2 == 0 ? WallSegments.HorizontalDiag : WallSegments.VerticalDiag;
            Require(diagonal.Segments == expectedDiagonal, "Diagonal walls must remain in frames 2/3 after every quarter turn");
            var expectedDiagonalSides = orientation switch
            {
                0 => (303, 505, 707, 808, 404, 606),
                1 => (404, 0, 808, 707, 303, 606),
                2 => (404, 0, 808, 707, 303, 606),
                _ => (303, 0, 707, 808, 404, 606)
            };
            Require((diagonal.TopLeftPattern, diagonal.TopRightPattern, diagonal.BottomLeftPattern, diagonal.BottomRightPattern, diagonal.TopLeftStyle, diagonal.TopRightStyle) == expectedDiagonalSides,
                $"Asymmetric diagonal patterns and styles did not match rotation {orientation}: actual {(diagonal.TopLeftPattern, diagonal.TopRightPattern, diagonal.BottomLeftPattern, diagonal.BottomRightPattern, diagonal.TopLeftStyle, diagonal.TopRightStyle)}, expected {expectedDiagonalSides}");
            var expectedPickingSides = orientation switch
            {
                0 => (0, 1, 2, 3),
                1 => (3, 0, 1, 2),
                2 => (2, 3, 0, 1),
                _ => (1, 2, 3, 0)
            };
            Require((camera.SourceWallDirection(0), camera.SourceWallDirection(1), camera.SourceWallDirection(2), camera.SourceWallDirection(3)) == expectedPickingSides,
                "Emitted wall picking directions do not map back to the corresponding source-side metadata");

            var gridWalls = new WallTile[width * height];
            for (var y = 0; y < height; y++)
            for (var x = 0; x < width; x++)
            {
                var marker = (ushort)(1000 + y * width + x);
                gridWalls[y * width + x] = new WallTile
                {
                    Segments = WallSegments.TopLeft | WallSegments.TopRight,
                    TopLeftPattern = marker, TopRightPattern = marker, BottomLeftPattern = marker, BottomRightPattern = marker,
                    TopLeftStyle = 1, TopRightStyle = 1
                };
            }
            blueprint.Walls[0] = gridWalls;
            var gridGeometry = WallComponent.RotateForCamera(blueprint, 1,
                new WallComponent.WallGeometry { Width = width, Height = height, Walls = gridWalls, Cuts = new WallCuts[width * height],
                    UpJunctions = new JunctionFlags[width * height], DownJunctions = new JunctionFlags[width * height] }, (WorldRotation)orientation);
            for (var y = 0; y < height; y++)
            for (var x = 0; x < width; x++)
            {
                var cell = camera.CameraPoint(x + 0.5f, y + 0.5f);
                var destX = (int)MathF.Floor(cell.X);
                var destY = (int)MathF.Floor(cell.Y);
                var expectedMarker = (ushort)(1000 + y * width + x);
                var dest = gridGeometry.Walls[destY * gridGeometry.Width + destX];
                Require(camera.SourceTile(destX, destY) == (x, y) &&
                        (dest.TopLeftPattern == expectedMarker || dest.TopRightPattern == expectedMarker ||
                         dest.BottomLeftPattern == expectedMarker || dest.BottomRightPattern == expectedMarker),
                    "Boundary wall cell or source marker did not round-trip through the exported camera grid");
            }
        }

        var sceneWallPicks = 0;
        var architecture = vm.Context.Architecture;
        var outputDirectory = Directory.CreateTempSubdirectory("camera-wall-metadata-");
        try
        {
            var exporter = new LotSceneExporter(vm, outputDirectory.FullName);
            for (var orientation = 0; orientation < 4; orientation++)
            {
                var cuts = new bool[architecture.Width * architecture.Height];
                var path = exporter.Snapshot(5, 0, wallsUp: true, revision: orientation + 1, viewLevel: 1,
                    wallMode: "up", cuts: cuts, cameraOrientation: orientation);
                var sceneCamera = new NativeLotCamera(orientation, architecture.Width, architecture.Height);
                using var scene = JsonDocument.Parse(File.ReadAllText(path));
                var sprites = scene.RootElement.GetProperty("sprites");
                foreach (var sprite in sprites.EnumerateArray())
                {
                    if (!sprite.TryGetProperty("wall", out var wall) || wall.ValueKind != JsonValueKind.Object) continue;
                    var x = wall.GetProperty("x").GetInt32();
                    var y = wall.GetProperty("y").GetInt32();
                    var level = wall.GetProperty("level").GetInt32();
                    var direction = wall.GetProperty("direction").GetInt32();
                    Require(x >= 0 && y >= 0 && x < architecture.Width && y < architecture.Height && level is >= 1 && level <= architecture.Stories,
                        "Exported wall picking metadata points outside the source architecture grid");
                    Require(direction is >= 0 and <= 3, "Exported wall picking metadata is outside the original four wall sides");
                    var sourceWall = architecture.Walls[level - 1][y * architecture.Width + x];
                    if ((sourceWall.Segments & WallSegments.AnyDiag) != 0)
                    {
                        var expectedDiagonal = orientation % 2 == 0 ? sourceWall.Segments :
                            sourceWall.Segments == WallSegments.HorizontalDiag ? WallSegments.VerticalDiag : WallSegments.HorizontalDiag;
                        var cameraTile = sceneCamera.CameraPoint(x + 0.5f, y + 0.5f);
                        var cameraX = (int)MathF.Floor(cameraTile.X);
                        var cameraY = (int)MathF.Floor(cameraTile.Y);
                        var rotatedWalls = NativeCutaway.Walls(vm, (sbyte)level, cuts, true, (FSO.LotView.WorldRotation)orientation);
                        var cameraWall = rotatedWalls.Walls[cameraY * rotatedWalls.Width + cameraX];
                        Require(cameraWall.Segments == expectedDiagonal,
                            $"Exported diagonal wall picker at ({x},{y}) did not point to its rotated source primitive at rotation {orientation}");
                    }
                    else
                    {
                        var sourceSide = (WallSegments)(1 << direction);
                        Require((sourceWall.Segments & sourceSide) != 0,
                            $"Exported wall picker at ({x},{y}) direction {direction} has no matching canonical source side at rotation {orientation}; segments {(byte)sourceWall.Segments}, patterns {(sourceWall.TopLeftPattern, sourceWall.TopRightPattern, sourceWall.BottomLeftPattern, sourceWall.BottomRightPattern)}");
                    }
                    sceneWallPicks++;
                }
            }
            Require(sceneWallPicks > 0, "The loaded lot did not emit any wall picking metadata for camera validation");
        }
        finally { outputDirectory.Delete(true); }

        return new { checks, orientations = 4, orthogonalFrames = true, diagonalFrames = true, wallPicking = true,
            cutAndJunctionTransforms = true, sceneWallPicks };
    }
}
