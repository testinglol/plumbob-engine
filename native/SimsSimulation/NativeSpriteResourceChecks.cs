using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.Files.Formats.IFF.Chunks;
using System.Text.Json;

internal static class NativeSpriteResourceChecks
{
    internal static object Run(VM vm)
    {
        var checks = 0;
        void Require(bool condition, string message)
        {
            if (!condition) throw new InvalidDataException(message);
            checks++;
        }

        var portals = vm.Entities.OfType<VMGameObject>()
            .Where(entity => entity.Object.OBJ.GUID == 2179383033UL)
            .ToArray();
        Require(portals.Length > 0, "House 5 has no pedestrian portal resource fixture");
        var legacyFrames = 0;
        var intentionalEmptyReferences = 0;
        foreach (var portal in portals)
        {
            var graphic = (ushort)(portal.Object.OBJ.BaseGraphicID + portal.GetValue(VMStackObjectVariable.Graphic));
            var group = portal.Object.Resource.Get<DGRP>(graphic);
            Require(group != null, $"Pedestrian portal {portal.ObjectID} has no DGRP {graphic}");
            for (uint rotation = 0; rotation < 4; rotation++)
            {
                var image = group!.GetImage((uint)portal.Direction, 2, rotation);
                Require(image != null, $"Pedestrian portal {portal.ObjectID} has no medium image at rotation {rotation}");
                var resolved = 0;
                foreach (var sprite in image!.Sprites)
                {
                    var spr2 = portal.Object.Resource.Get<SPR2>((ushort)sprite.SpriteID);
                    if (spr2 != null && sprite.SpriteFrameIndex < spr2.Frames.Length)
                    {
                        resolved++;
                        continue;
                    }
                    var spr = spr2 == null ? portal.Object.Resource.Get<SPR>((ushort)sprite.SpriteID) : null;
                    if (spr != null && sprite.SpriteFrameIndex < spr.Frames.Count)
                    {
                        resolved++;
                        legacyFrames++;
                        continue;
                    }
                    if (sprite.SpriteID == 0 && spr2 == null && spr == null)
                    {
                        intentionalEmptyReferences++;
                        continue;
                    }
                    throw new InvalidDataException($"Pedestrian portal {portal.ObjectID} has unresolved nonempty sprite {sprite.SpriteID}:{sprite.SpriteFrameIndex} at rotation {rotation}");
                }
                Require(resolved > 0, $"Pedestrian portal {portal.ObjectID} has no drawable sprite at rotation {rotation}");
            }
        }
        Require(legacyFrames > 0, "Pedestrian portal fixture did not resolve any legacy SPR frames");
        Require(intentionalEmptyReferences > 0, "Pedestrian portal fixture did not contain an unresolved zero-ID empty entry");

        var stair = vm.Entities.OfType<VMGameObject>().FirstOrDefault(entity => entity.Object.OBJ.GUID == 2044901413UL);
        Require(stair != null, "House 5 has no Stair - Low Pad Medium resource fixture");
        var stairGraphic = (ushort)(stair!.Object.OBJ.BaseGraphicID + stair.GetValue(VMStackObjectVariable.Graphic));
        Require(stair.Object.Resource.Name == "stair.iff" && stair.Object.OBJ.BaseGraphicID == 3000 && stair.GetValue(VMStackObjectVariable.Graphic) == 2,
            "Stair graphic source fields differ from the loaded House 5 fixture");
        Require(stair.Object.Resource.Get<DGRP>(stairGraphic) == null && stair.Object.Resource.Sprites == null,
            "Stair graphic DGRP unexpectedly resolved from its shipped object resources");
        var renderedGroup = (stair.WorldUI as FSO.LotView.Components.ObjectComponent)?.DGRP;
        var baseGraphicAvailable = stair.Object.Resource.Get<DGRP>(stair.Object.OBJ.BaseGraphicID) != null;
        Require(!baseGraphicAvailable && renderedGroup == null,
            "Stair should have no renderable DGRP when both base and active graphics are absent");
        var availableStairGroups = stair.Object.Resource.Iff!.ListAll().Where(chunk => chunk.ChunkType == "DGRP").Select(chunk => chunk.ChunkID).Order().ToArray();
        Require(!availableStairGroups.Contains(stairGraphic), "The missing stair DGRP appears in the loaded stair.iff chunk inventory");
        Require(!availableStairGroups.Contains(stair.Object.OBJ.BaseGraphicID), "The stair base DGRP appears in the loaded stair.iff chunk inventory");

        var exportDirectory = Path.Combine(Path.GetTempPath(), "sims-native-stair-dgrp-" + Guid.NewGuid().ToString("N"));
        try
        {
            var exporter = new LotSceneExporter(vm, exportDirectory);
            for (var orientation = 0; orientation < 4; orientation++)
            {
                var scenePath = exporter.Snapshot(5, 0, revision: orientation + 1, cameraOrientation: orientation);
                using var scene = JsonDocument.Parse(File.ReadAllText(scenePath));
                var missingResources = scene.RootElement.GetProperty("missingResources").EnumerateArray().Select(value => value.GetString() ?? "").ToArray();
                Require(missingResources.Count(value => value.Contains($"guid:{stair.Object.OBJ.GUID}:")) == 1 &&
                    missingResources.Single(value => value.Contains($"guid:{stair.Object.OBJ.GUID}:")).Contains($"requestedGraphic:{stairGraphic}:") &&
                    !scene.RootElement.GetProperty("sprites").EnumerateArray().Any(value => value.GetProperty("objectID").GetInt16() == stair.ObjectID),
                    $"Stair scene export did not preserve the verified missing active DGRP at camera orientation {orientation}");
            }
        }
        finally
        {
            if (Directory.Exists(exportDirectory)) Directory.Delete(exportDirectory, true);
        }

        return new
        {
            checks,
            portalObjects = portals.Length,
            portalRotations = 4,
            resolvedLegacyFrames = legacyFrames,
            intentionalEmptyReferences,
            stairExportOrientations = 4,
            missingStair = new { guid = stair.Object.OBJ.GUID, resource = stair.Object.Resource.Name, baseGraphic = stair.Object.OBJ.BaseGraphicID, graphicOffset = stair.GetValue(VMStackObjectVariable.Graphic), requestedGraphic = stairGraphic, baseGraphicAvailable, renderedGraphic = renderedGroup?.ChunkID, availableDgrpCount = availableStairGroups.Length, availableDgrpIds = availableStairGroups }
        };
    }
}
