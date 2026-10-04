using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics.Model;
using FSO.LotView.Components;
using FSO.SimAntics;
using Microsoft.Xna.Framework;

/// <summary>
/// Places every ground-floor object sprite the way FreeSO's medium-zoom DGRPRenderer does, in all four rotations, and
/// requires the native exporter to land each one on the same pixel. FreeSO draws walls and objects from the screen image
/// of the same world corner (WorldSpace.GetScreenFromTile), so the native wall anchor fixes the screen translation for
/// each rotation and the object sprites are compared against it. Multi-tile objects are covered because each part is
/// its own entity with its own corner.
/// </summary>
internal static class NativeObjectPlacementChecks
{
    // WorldSpace medium zoom: OneUnitDistance = sqrt(64²/2), cadge 68 wide with its baseline 174 px down.
    private static readonly float UnitHeight = (float)(Math.Sqrt(64 * 64 / 2.0) * Math.Cos(Math.PI / 6));

    // WorldSpace.GetScreenFromTile for TopLeft, TopRight, BottomRight and BottomLeft.
    private static Vector2 Screen(int rotation, Vector3 tile)
    {
        var (x, y, z) = (tile.X, tile.Y, tile.Z * UnitHeight);
        return rotation switch
        {
            0 => new Vector2((x - y) * 32, (x + y) * 16 - z),
            1 => new Vector2((-x - y) * 32, (x - y) * 16 - z),
            2 => new Vector2((-x + y) * 32, (-x - y) * 16 - z),
            _ => new Vector2((x + y) * 32, (-x + y) * 16 - z)
        };
    }

    internal static object Run(VM vm)
    {
        var width = vm.Context.Architecture.Width;
        var height = vm.Context.Architecture.Height;
        var transforms = new NativeEntityTransform((_, _) => 0);
        var objects = vm.Entities.OfType<VMGameObject>()
            .Where(entity => entity.Container == null && entity.Position.Level == 1 && entity.Position.x >= 0 &&
                             entity.Position.y >= 0 && entity.GetValue(VMStackObjectVariable.Hidden) == 0)
            .ToArray();
        if (objects.Length == 0) throw new InvalidDataException("Object placement check found no ground-floor objects");
        var multiTile = objects.Where(entity => entity.MultitileGroup.Objects.Count > 1).ToArray();
        if (multiTile.Length == 0) throw new InvalidDataException("Object placement check found no multi-tile objects");

        var sprites = 0;
        var maxError = 0;
        var rotations = new List<object>();
        for (var rotation = 0; rotation < 4; rotation++)
        {
            var camera = new NativeLotCamera(rotation, width, height);

            // The native wall at camera tile c starts at ProjectCamera(c) - (34, 158) + rect; FreeSO's starts at
            // Screen(source corner) + rect after scrolling. Their difference must be one translation for the lot.
            Vector2? translation = null;
            foreach (var (cx, cy) in new[] { (0, 0), (5, 0), (0, 7), (11, 13), (width - 1, height - 1) })
            {
                var (sx, sy) = camera.SourceTile(cx, cy);
                var native = camera.ProjectCamera(cx, cy) - new Vector2(34, 158);
                var difference = native - Screen(rotation, new Vector3(sx, sy, 0));
                translation ??= difference;
                if (Vector2.Distance(difference, translation.Value) > 0.01f)
                    throw new InvalidDataException($"Rotation {rotation}: wall anchor at camera tile {cx},{cy} moves by {difference - translation.Value} relative to FreeSO");
            }
            var t = translation!.Value;

            var rotationSprites = 0;
            foreach (var entity in objects)
            {
                var group = (entity.WorldUI as ObjectComponent)?.DGRP ??
                            entity.Object.Resource.Get<DGRP>((ushort)(entity.Object.OBJ.BaseGraphicID + entity.GetValue(VMStackObjectVariable.Graphic)));
                var image = group?.GetImage((uint)entity.Direction, 2, (uint)rotation);
                if (image == null) continue;
                var centre = transforms.Position(entity);
                var corner = centre - new Vector3(0.5f, 0.5f, 0);
                var turn = Matrix.CreateRotationZ(entity.RadianDirection);
                foreach (var sprite in image.Sprites)
                {
                    var frameHeight = entity.Object.Resource.Get<SPR2>((ushort)sprite.SpriteID)?.Frames.ElementAtOrDefault((int)sprite.SpriteFrameIndex)?.Height
                                      ?? entity.Object.Resource.Get<SPR>((ushort)sprite.SpriteID)?.Frames.ElementAtOrDefault((int)sprite.SpriteFrameIndex)?.Height;
                    if (frameHeight is null or 0) continue;

                    // DGRPRenderer: pxX = CadgeWidth/2 + SpriteOffset.X, pxY = CadgeBaseLine - height + SpriteOffset.Y,
                    // pxOff = GetScreenFromTile(rotZ(direction)(ObjectOffset * (1/16, 1/16, 1/5))), truncated to int.
                    var relative = Vector3.Transform(sprite.ObjectOffset * new Vector3(1 / 16f, 1 / 16f, 1 / 5f), turn);
                    var pxOff = Screen(rotation, relative);
                    var local = new Vector2((int)(34 + sprite.SpriteOffset.X + pxOff.X),
                        (int)(174 - frameHeight.Value + sprite.SpriteOffset.Y + pxOff.Y));
                    var expected = Screen(rotation, corner) + t + local;

                    var offset = Vector3.Transform(sprite.ObjectOffset, turn);
                    var (nx, ny) = LotSceneExporter.SpriteOrigin(camera, centre, offset, sprite.SpriteOffset, frameHeight.Value);
                    var error = (int)Math.Ceiling(Math.Max(Math.Abs(nx - expected.X), Math.Abs(ny - expected.Y)));
                    if (error > 1)
                        throw new InvalidDataException($"Rotation {rotation}: {entity.Name} ({entity.ObjectID}) sprite {sprite.SpriteID}:{sprite.SpriteFrameIndex} at {nx},{ny}; FreeSO places it at {expected.X},{expected.Y}");
                    maxError = Math.Max(maxError, error);
                    rotationSprites++;
                }
            }
            if (rotationSprites == 0) throw new InvalidDataException($"Rotation {rotation} placed no object sprites");
            sprites += rotationSprites;
            rotations.Add(new { rotation, translation = new[] { t.X, t.Y }, sprites = rotationSprites });
        }

        return new
        {
            objects = objects.Length,
            multiTileParts = multiTile.Length,
            multiTileObjects = multiTile.Select(entity => entity.MultitileGroup).Distinct().Count(),
            sprites,
            maxErrorPixels = maxError,
            rotations
        };
    }
}
