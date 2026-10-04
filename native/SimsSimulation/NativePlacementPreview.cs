using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Engine.TSOTransaction;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.Model;
using FSO.SimAntics.NetPlay.Drivers;
using FSO.SimAntics.Utils;
using FSO.LotView.Model;
using Microsoft.Xna.Framework;

internal static class NativePlacementPreview
{
    public static object Evaluate(VM source, uint? guid, short? objectID, LotTilePos position, Direction direction, LotSceneExporter exporter)
    {
        using var data = new MemoryStream();
        using (var writer = new BinaryWriter(data, System.Text.Encoding.UTF8, true)) source.Save().SerializeInto(writer);
        data.Position = 0;
        var snapshot = new VMMarshal();
        using (var reader = new BinaryReader(data, System.Text.Encoding.UTF8, true)) snapshot.Deserialize(reader);
        var copy = new VM(new VMContext(null), new VMServerDriver(new VMTS1GlobalLinkStub()), new VMNullHeadlineProvider());
        copy.Init();
        var savedFamily = (snapshot.PlatformState as FSO.SimAntics.Model.TS1Platform.VMTS1LotState)?.CurrentFamily;
        copy.Load(snapshot);
        copy.TS1State.CurrentFamily = savedFamily;
        if (savedFamily != null) copy.TS1State.ActivateFamily(copy, savedFamily);
        var group = objectID.HasValue ? copy.GetObjectById(objectID.Value)?.MultitileGroup : copy.Context.CreateObjectInstance(guid!.Value, LotTilePos.OUT_OF_WORLD, direction);
        if (group == null || group.Objects.Count == 0) throw new InvalidOperationException("Object has no placement group");
        var rotation = Matrix.CreateRotationZ((float)(Math.Log2((byte)direction) * Math.PI / 4));
        var baseOffset = group.Offsets[group.Objects.IndexOf(group.BaseObject)];
        var positions = new Dictionary<short, LotTilePos>();
        var tiles = group.Offsets.Select((offset, index) =>
        {
            var rotated = Vector3.Transform(new Vector3(offset.x - baseOffset.x, offset.y - baseOffset.y, 0), rotation);
            var target = new LotTilePos((short)Math.Round(position.x + rotated.X), (short)Math.Round(position.y + rotated.Y), (sbyte)(position.Level + offset.Level));
            positions[group.Objects[index].ObjectID] = target;
            return new { x = (int)Math.Floor(target.x / 16.0), y = (int)Math.Floor(target.y / 16.0), level = (int)target.Level };
        }).Distinct().ToArray();
        var status = group.ChangePosition(position, direction, copy.Context, VMPlaceRequestFlags.UserPlacement).Status;
        return new { schemaVersion = 1, valid = status == VMPlacementError.Success, status = status.ToString(), tiles, ghost = exporter.PlacementGhost(copy, group.Objects.OfType<VMGameObject>(), positions, direction) };
    }
}
