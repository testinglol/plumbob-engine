using FSO.LotView.Components;
using FSO.LotView.Model;
using FSO.SimAntics;
using FSO.SimAntics.Model;
using Microsoft.Xna.Framework;

internal static class NativeAttachmentChecks
{
    public static int Run(VM vm)
    {
        var objects = vm.Entities.OfType<VMGameObject>().Where(entity => entity.Position.x >= 0 && entity.Position.Level == 1 && entity.Container == null).ToArray();
        var parents = objects.Where(entity => entity.Slots?.Slots.TryGetValue(0, out var slots) == true && slots.Count > 0).ToArray();
        if (parents.Length < 2) throw new Exception("Attachment fixture requires original objects with containment slots");
        var avatar = vm.Entities.OfType<VMAvatar>().First(entity => entity.Position.x >= 0 && entity.Container == null);
        var child = objects.First(entity => !parents.Contains(entity));
        var oldContainer = child.Container;
        var oldSlot = child.ContainerSlot;
        var avatarContainer = avatar.Container;
        var avatarSlot = avatar.ContainerSlot;
        var scale = avatar.GetPersonData(VMPersonDataVariable.TS1ScalingSim);
        var checks = 0;
        static float Elevation(float x, float y) => x * 0.4f + y * 0.2f;
        void Equal(Vector3 actual, Vector3 expected)
        {
            if (Vector3.Distance(actual, expected) > 0.0001f) throw new Exception($"Native slot transform {actual} differs from original world transform {expected}");
            checks++;
        }
        try
        {
            foreach (var parent in parents)
            {
                var originalDirection = parent.Direction;
                var slots = parent.Slots.Slots[0];
                try
                {
                    foreach (var direction in new byte[] { 1, 2, 4, 8, 16, 32, 64, 128 })
                    {
                        parent.Direction = (Direction)direction;
                        var origin = new NativeEntityTransform(Elevation).Position(parent);
                        var original = new ObjectComponent(parent.Object) { ContainerSlots = slots, Direction = parent.Direction, Position = origin };
                        for (short slot = 0; slot < slots.Count; slot++)
                        {
                            child.Container = parent;
                            child.ContainerSlot = slot;
                            Equal(new NativeEntityTransform(Elevation).Position(child), original.GetSLOTPosition(slot, false));
                            avatar.Container = parent;
                            avatar.ContainerSlot = slot;
                            Equal(new NativeEntityTransform(Elevation).Position(avatar), original.GetSLOTPosition(slot, true) + new Vector3(0.5f, 0.5f, (1 - NativeEntityTransform.Scale(avatar)) / 2));
                            avatar.Container = null;
                        }
                    }
                }
                finally { parent.Direction = originalDirection; }
            }
            child.Container = avatar;
            foreach (var percentage in new short[] { 50, 100, 125 })
            {
                avatar.SetPersonData(VMPersonDataVariable.TS1ScalingSim, percentage);
                var transforms = new NativeEntityTransform(Elevation);
                var original = new AvatarComponent { Avatar = transforms.Pose(avatar), Scale = NativeEntityTransform.Scale(avatar), RadianDirection = avatar.RadianDirection, Position = transforms.Position(avatar) };
                for (short slot = 0; slot < 3; slot++)
                {
                    child.ContainerSlot = slot;
                    Equal(new NativeEntityTransform(Elevation).Position(child), original.GetSLOTPosition(slot, false));
                }
            }
            avatar.SetPersonData(VMPersonDataVariable.TS1ScalingSim, scale);
            var inner = parents[1];
            var outer = parents[0];
            var previousParent = inner.Container;
            var previousSlot = inner.ContainerSlot;
            try
            {
                inner.Container = outer;
                inner.ContainerSlot = 0;
                child.Container = inner;
                child.ContainerSlot = 0;
                var transforms = new NativeEntityTransform(Elevation);
                var originalOuter = new ObjectComponent(outer.Object) { ContainerSlots = outer.Slots.Slots[0], Direction = outer.Direction, Position = transforms.Position(outer) };
                var originalInner = new ObjectComponent(inner.Object) { ContainerSlots = inner.Slots.Slots[0], Direction = inner.Direction, Container = originalOuter, ContainerSlot = 0 };
                Equal(transforms.Position(child), originalInner.GetSLOTPosition(0, false));
                inner.Container = child;
                try { new NativeEntityTransform(Elevation).Position(child); throw new Exception("Containment cycle was accepted"); }
                catch (InvalidDataException) { checks++; }
            }
            finally { inner.Container = previousParent; inner.ContainerSlot = previousSlot; }
        }
        finally
        {
            child.Container = oldContainer;
            child.ContainerSlot = oldSlot;
            avatar.Container = avatarContainer;
            avatar.ContainerSlot = avatarSlot;
            avatar.SetPersonData(VMPersonDataVariable.TS1ScalingSim, scale);
        }
        return checks;
    }
}
