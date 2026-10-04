using FSO.Files.Formats.IFF.Chunks;
using FSO.LotView.Model;
using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.Vitaboy;
using Microsoft.Xna.Framework;

internal sealed class NativeEntityTransform(Func<float, float, float> elevation)
{
    public const float StoryHeight = 2.95f;
    private readonly Dictionary<VMEntity, Vector3> positions = [];
    private readonly Dictionary<VMAvatar, SimAvatar> poses = [];
    private readonly HashSet<VMEntity> resolving = [];
    private static readonly string[] SlotBones = ["R_FINGER0", "HEAD", "PELVIS"];

    public static float Scale(VMAvatar avatar)
    {
        var value = avatar.GetPersonData(VMPersonDataVariable.TS1ScalingSim);
        return value > 0 ? value / 100f : 1;
    }

    public SimAvatar Pose(VMAvatar avatar)
    {
        if (!poses.TryGetValue(avatar, out var pose)) poses.Add(avatar, pose = AvatarGeometry.Pose(avatar));
        return pose;
    }

    public Vector3 Position(VMEntity entity)
    {
        if (positions.TryGetValue(entity, out var position)) return position;
        if (!resolving.Add(entity)) throw new InvalidDataException("Object containment contains a cycle");
        try
        {
            if (entity.Container is { } container)
            {
                position = SlotPosition(container, entity.ContainerSlot, entity is VMAvatar);
                if (entity is VMAvatar avatar) position += new Vector3(0.5f, 0.5f, (1 - Scale(avatar)) / 2);
            }
            else
            {
                position = Position(entity.Position);
            }
            positions.Add(entity, position);
            return position;
        }
        finally { resolving.Remove(entity); }
    }

    public Vector3 Position(LotTilePos position)
    {
        var x = position.x / 16f;
        var y = position.y / 16f;
        return new Vector3(x, y, (position.Level - 1) * StoryHeight + elevation(x + 0.5f, y + 0.5f) / 40);
    }

    private Vector3 SlotPosition(VMEntity container, int slot, bool avatar)
    {
        var origin = Position(container);
        if (container is VMAvatar owner)
        {
            if (slot < 0 || slot >= SlotBones.Length) throw new InvalidDataException("Invalid avatar containment slot");
            var bone = Pose(owner).Skeleton.GetBone(SlotBones[slot]).AbsolutePosition / 3 * Scale(owner);
            var offset = Vector3.Transform(new Vector3(bone.X, bone.Z, bone.Y), Matrix.CreateRotationZ(owner.RadianDirection + MathF.PI));
            return origin + offset - new Vector3(0.5f, 0.5f, 0);
        }
        if (container.Slots is not { } definition || !definition.Slots.TryGetValue(0, out var slots) || slot < 0 || slot >= slots.Count) return origin;
        var item = slots[slot];
        var height = item.Height is 0 or 5 ? item.Offset.Z :
            item.Height >= 1 && item.Height <= SLOT.HeightOffsets.Length ? SLOT.HeightOffsets[item.Height - 1] :
            throw new InvalidDataException("Invalid object containment slot height");
        var relative = new Vector3(item.Offset.X / 16, item.Offset.Y / 16, avatar ? 0 : height / 5);
        return origin + Vector3.Transform(relative, Matrix.CreateRotationZ(container.RadianDirection));
    }
}
