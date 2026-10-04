using System.Buffers.Binary;
using System.Runtime.CompilerServices;
using FSO.Content.Model;
using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.Vitaboy;
using Microsoft.Xna.Framework;

internal static class AvatarGeometry
{
    internal record Vertex(float X, float Y, float Z, float U, float V, float Nx, float Ny, float Nz);
    internal record Part(byte[] Texture, string Encoding, int Width, int Height, Vertex[] Vertices);
    private sealed class VisualState
    {
        public string OutfitKey = "";
        public SimAvatar? Avatar;
        public HashSet<string> Appearances = new(StringComparer.OrdinalIgnoreCase);
        public List<string> AppearanceFailures = [];
    }
    private sealed class TextureSource { public required byte[] Bytes; }
    private static readonly ConditionalWeakTable<AbstractTextureRef, TextureSource> TextureSources = new();
    private static readonly ConditionalWeakTable<VMAvatar, VisualState> Visuals = new();

    internal static SimAvatar Pose(VMAvatar entity)
    {
        var body = entity.BodyOutfit?.GetContent();
        var head = entity.HeadOutfit?.GetContent();
        var key = $"{body?.TS1AppearanceID}:{body?.TS1TextureID}:{head?.TS1AppearanceID}:{head?.TS1TextureID}:{entity.SkinTone}";
        var visual = Visuals.GetOrCreateValue(entity);
        var appearances = entity.BoundAppearances.Select(VMAvatar.NormalizeAppearanceName).ToHashSet(StringComparer.OrdinalIgnoreCase);
        if (visual.Avatar == null || key != visual.OutfitKey || !visual.Appearances.SetEquals(appearances))
        {
            visual.Avatar = new SimAvatar(entity.Avatar.BaseSkeleton)
            {
                Appearance = entity.SkinTone,
                Body = body,
                Head = head,
                // Cats and dogs have no hand meshes, so they carry no hand group.
                Handgroup = entity.IsCat || entity.IsDog ? null : body
            };
            visual.OutfitKey = key;
            visual.Appearances = appearances;
            visual.AppearanceFailures.Clear();
            foreach (var name in appearances.Order(StringComparer.OrdinalIgnoreCase))
            {
                var bindingCount = visual.Avatar.Bindings.Count;
                try
                {
                    var appearance = ResolveAppearance(name);
                    visual.Avatar.AddAccessory(appearance);
                }
                catch (Exception error)
                {
                    visual.Avatar.Bindings.RemoveRange(bindingCount, visual.Avatar.Bindings.Count - bindingCount);
                    visual.AppearanceFailures.Add($"{name}:{error.Message}");
                }
            }
        }
        var avatar = visual.Avatar;
        avatar.Skeleton = avatar.BaseSkeleton.Clone();
        avatar.LeftHandGesture = entity.Avatar.LeftHandGesture;
        avatar.RightHandGesture = entity.Avatar.RightHandGesture;
        var states = entity.Animations.Where(state => state.Anim != null && state.Weight > 0).ToArray();
        var totalWeight = states.Sum(state => state.Weight);
        foreach (var state in states)
            Animator.RenderFrame(avatar, state.Anim, (int)state.CurrentFrame, state.CurrentFrame % 1, state.Weight / totalWeight);
        if (entity.CarryAnimationState is { } carry)
            Animator.RenderFrame(avatar, carry.Anim, (int)carry.CurrentFrame, carry.CurrentFrame % 1, 1);
        if (entity.Avatar.HeadSeekWeight > 0)
            Animator.ApplyHeadSeek(avatar, entity.Avatar.HeadSeek, Math.Min(1, entity.Avatar.HeadSeekWeight / SimAvatar.HEAD_SEEK_LENGTH));
        avatar.ReloadSkeleton();
        return avatar;
    }

    internal static Appearance ResolveAppearance(string name)
    {
        var content = FSO.Content.Content.Get();
        var appearance = content.AvatarAppearances.Get(name) ?? throw new InvalidDataException("Appearance resource not found");
        foreach (var reference in appearance.Bindings)
        {
            var binding = reference.RealBinding ?? content.AvatarBindings?.Get(reference.TypeID, reference.FileID)
                ?? throw new InvalidDataException("Appearance binding not found");
            var mesh = binding.MeshName != null ? content.AvatarMeshes.Get(binding.MeshName) : content.AvatarMeshes.Get(binding.MeshTypeID, binding.MeshFileID);
            if (mesh == null) throw new InvalidDataException("Appearance mesh not found");
            var texture = binding.MeshName != null ? content.AvatarTextures.Get(binding.TextureName ?? mesh.TextureName) : content.AvatarTextures.Get(binding.TextureTypeID, binding.TextureFileID);
            if (texture is not AbstractTextureRef) throw new InvalidDataException("Appearance texture not found");
        }
        return appearance;
    }

    internal static IReadOnlyList<string> AppearanceFailures(VMAvatar entity) => Visuals.GetOrCreateValue(entity).AppearanceFailures;

    internal static List<Part> Build(VMAvatar entity, NativeEntityTransform transforms) =>
        Build(entity, transforms, new NativeLotCamera(0, 128, 128));

    internal static List<Part> Build(VMAvatar entity, NativeEntityTransform transforms, NativeLotCamera camera)
    {
        var avatar = transforms.Pose(entity);
        var rotation = Matrix.CreateRotationY((float)Math.PI - entity.RadianDirection);
        var origin = transforms.Position(entity);
        var tileX = origin.X;
        var tileY = origin.Y;
        var altitude = origin.Z * 40;
        var scale = NativeEntityTransform.Scale(entity);
        var parts = new List<Part>();
        foreach (var binding in avatar.Bindings)
        {
            if (binding.Texture is not AbstractTextureRef texture || binding.Mesh is not { } mesh)
                throw new InvalidDataException($"Missing avatar mesh or texture for {entity.Name}");
            var bytes = TextureSources.GetValue(texture, source => new TextureSource { Bytes = source.ReadSourceData() }).Bytes;
            string encoding;
            int width, height;
            if (bytes.Length >= 54 && bytes[0] == 'B' && bytes[1] == 'M')
            {
                encoding = "bmp";
                width = BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(18));
                height = Math.Abs((long)BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(22))) <= 4096
                    ? Math.Abs(BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(22))) : 0;
            }
            else if (bytes.Length >= 18 && bytes[2] is 1 or 2 or 3 or 9 or 10 or 11)
            {
                encoding = "tga";
                width = BinaryPrimitives.ReadUInt16LittleEndian(bytes.AsSpan(12));
                height = BinaryPrimitives.ReadUInt16LittleEndian(bytes.AsSpan(14));
            }
            else throw new InvalidDataException("Unsupported avatar texture encoding");
            if (width is < 1 or > 4096 || height is < 1 or > 4096) throw new InvalidDataException("Invalid avatar texture dimensions");
            var vertices = new Vertex[mesh.IndexBuffer.Length];
            for (var index = 0; index < vertices.Length; index++)
            {
                var source = mesh.VertexBuffer[mesh.IndexBuffer[index]];
                var bone = avatar.Skeleton.Bones[(int)source.Parameters.X].AbsoluteMatrix;
                var position = Vector3.Transform(source.Position, bone);
                var normal = Vector3.TransformNormal(source.Normal, bone);
                if (source.Parameters.Z > 0)
                {
                    var blendBone = avatar.Skeleton.Bones[(int)source.Parameters.Y].AbsoluteMatrix;
                    position = Vector3.Lerp(position, Vector3.Transform(source.BvPosition, blendBone), source.Parameters.Z);
                    normal = Vector3.Lerp(normal, Vector3.TransformNormal(source.BvNormal, blendBone), source.Parameters.Z);
                }
                position = Vector3.Transform(position, rotation) / 3 * scale;
                normal = Vector3.TransformNormal(normal, rotation);
                normal = camera.CameraNormal(normal);
                if (normal.LengthSquared() > 0) normal.Normalize();
                var worldX = tileX + position.X;
                var worldY = tileY + position.Z;
                var projected = camera.Project(worldX, worldY, position.Y * 40 + altitude);
                vertices[index] = new Vertex(projected.X, projected.Y,
                    camera.Depth(worldX, worldY, position.Y + altitude / 40),
                    source.TextureCoordinate.X, source.TextureCoordinate.Y, normal.X, normal.Y, normal.Z);
            }
            parts.Add(new Part(bytes, encoding, width, height, vertices));
        }
        return parts;
    }
}
