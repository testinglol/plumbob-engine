using System.Buffers.Binary;
using System.Runtime.CompilerServices;
using System.Globalization;
using System.Numerics;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using SimsEngine.Character;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;

namespace SimsSimulation;

internal sealed class AvatarSceneGeometry
{
    internal readonly record struct Vertex(float X, float Y, float Z, float U, float V, float Nx, float Ny, float Nz);

    [ThreadStatic]
    private static Vertex[]? s_projectedScratch;

    [ThreadStatic]
    private static (Vector3 Position, Vector3 Normal, Vector2 UV)[]? s_posedScratch;
    internal sealed record Part(byte[] Texture, string TextureHash, string Encoding, int Width, int Height, Vertex[] Vertices, bool IgnoreRoomLighting = false);
    internal sealed record CensorBounds(float X, float Y, float Width, float Height, float Depth);

    private sealed record AppearanceSource(Appearance Appearance, CharacterFile File, CharacterData Data, CharacterSearchPath Path);
    private sealed record TextureSource(byte[] Bytes, string Sha1Hex, string Encoding, int Width, int Height, string FileName);
    private sealed record AnimationSource(Animation Animation, AnimationCurves Curves);
    private sealed record SkateMesh(Vector3[] Positions, Vector2[] UVs, Vector3[] Normals,
        (int Position, int UV, int Normal)[] Corners, TextureSource Texture);
    private sealed record SkateFrame(float[] Translation, float[] Rotation);
    private sealed record SkateSideFrame(string SlotJoint, SkateFrame Slot, string FootJoint, SkateFrame Foot);
    private sealed record SkateSkeletonFrames(string Age, Dictionary<string, SkateSideFrame> Frames);
    private sealed record SkateAttachmentFrames(int SchemaVersion, string CoordinateSystem,
        Dictionary<string, SkateSkeletonFrames> Skeletons);
    private sealed record HandPropEntry(string Stem, string Bone, float[] AdultMatrix, float[] ChildMatrix);
    private sealed record HandPropManifest(int SchemaVersion, Dictionary<string, HandPropEntry> Props);
    private sealed record HandPropBinding(string Stem, string Bone, Matrix4x4 AdultMatrix, Matrix4x4 ChildMatrix);

    private sealed class SkeletonInfo
    {
        public readonly Skeleton Skeleton;
        public readonly HashSet<string> BoneSet;
        public readonly Dictionary<string, int> IndexByNameIgnoreCase;
        public readonly Dictionary<string, int> IndexByNameOrdinal;
        public readonly string Signature;

        public SkeletonInfo(Skeleton skeleton)
        {
            Skeleton = skeleton;
            var count = skeleton.Bones.Count;
            BoneSet = new HashSet<string>(count, StringComparer.Ordinal);
            IndexByNameIgnoreCase = new Dictionary<string, int>(count, StringComparer.OrdinalIgnoreCase);
            IndexByNameOrdinal = new Dictionary<string, int>(count, StringComparer.Ordinal);
            var sigBuilder = new StringBuilder(skeleton.Name.Length + count * 8);
            sigBuilder.Append(skeleton.Name).Append('\0');
            for (var i = 0; i < count; i++)
            {
                var name = skeleton.Bones[i].Name;
                BoneSet.Add(name);
                IndexByNameIgnoreCase.TryAdd(name, i);
                IndexByNameOrdinal.TryAdd(name, i);
                if (i > 0) sigBuilder.Append('|');
                sigBuilder.Append(name);
            }
            Signature = sigBuilder.ToString();
        }
    }

    private sealed class SkeletonMeshMap(int[]? boneIndices, string? missingBoneName)
    {
        public readonly int[]? BoneIndices = boneIndices;
        public readonly string? MissingBoneName = missingBoneName;
    }

    private sealed class MeshBindingLayout
    {
        public readonly bool HasInvalidBoneIndex;
        public readonly int[] BoneForVertex;
        public readonly int[] BlendBoneForVertex;
        public readonly float[] BlendWeightForVertex;
        public readonly int[] BlendVertexForVertex;
        public readonly bool[] IsLeftFootVertex;
        public readonly bool[] IsRightFootVertex;
        public readonly bool[] IsHeadBoneVertex;
        public readonly int[] FlatFaceIndices;
        public readonly (int A, int B, int C)[] FacesTuples;
        private readonly ConditionalWeakTable<Skeleton, SkeletonMeshMap> skeletonMaps = new();

        public MeshBindingLayout(Mesh mesh)
        {
            var vertexCount = mesh.TextureCoordinates.Count;
            BoneForVertex = new int[vertexCount];
            BlendBoneForVertex = new int[vertexCount];
            Array.Fill(BlendBoneForVertex, -1);
            BlendWeightForVertex = new float[vertexCount];
            BlendVertexForVertex = new int[vertexCount];
            foreach (var binding in mesh.Bindings)
            {
                if (binding.Bone < 0 || binding.Bone >= mesh.Bones.Count)
                {
                    HasInvalidBoneIndex = true;
                    break;
                }
                for (var vertex = binding.FirstVertex; vertex < binding.FirstVertex + binding.VertexCount; vertex++)
                    BoneForVertex[vertex] = binding.Bone;
                for (var index = binding.FirstBlend; index < binding.FirstBlend + binding.BlendCount; index++)
                {
                    var blend = mesh.Blends[index];
                    BlendBoneForVertex[blend.Vertex] = binding.Bone;
                    BlendWeightForVertex[blend.Vertex] = blend.Weight / 32768f;
                    BlendVertexForVertex[blend.Vertex] = vertexCount + index;
                }
            }

            IsLeftFootVertex = new bool[vertexCount];
            IsRightFootVertex = new bool[vertexCount];
            IsHeadBoneVertex = new bool[vertexCount];
            if (!HasInvalidBoneIndex && mesh.Bones.Count > 0)
            {
                var boneIsLeftFoot = new bool[mesh.Bones.Count];
                var boneIsRightFoot = new bool[mesh.Bones.Count];
                var boneIsHead = new bool[mesh.Bones.Count];
                for (var b = 0; b < mesh.Bones.Count; b++)
                {
                    var name = mesh.Bones[b];
                    boneIsLeftFoot[b] = name.Equals("L_FOOT", StringComparison.OrdinalIgnoreCase);
                    boneIsRightFoot[b] = name.Equals("R_FOOT", StringComparison.OrdinalIgnoreCase);
                    boneIsHead[b] = name.Equals("HEAD", StringComparison.OrdinalIgnoreCase);
                }
                for (var v = 0; v < vertexCount; v++)
                {
                    var primary = BoneForVertex[v];
                    var blendBone = BlendBoneForVertex[v];
                    IsLeftFootVertex[v] = boneIsLeftFoot[primary] || (blendBone >= 0 && boneIsLeftFoot[blendBone]);
                    IsRightFootVertex[v] = boneIsRightFoot[primary] || (blendBone >= 0 && boneIsRightFoot[blendBone]);
                    IsHeadBoneVertex[v] = boneIsHead[primary];
                }
            }

            var faceCount = mesh.Faces.Count;
            FlatFaceIndices = new int[faceCount * 3];
            FacesTuples = new (int A, int B, int C)[faceCount];
            for (var f = 0; f < faceCount; f++)
            {
                var face = mesh.Faces[f];
                FlatFaceIndices[f * 3] = face.A;
                FlatFaceIndices[f * 3 + 1] = face.B;
                FlatFaceIndices[f * 3 + 2] = face.C;
                FacesTuples[f] = (face.A, face.B, face.C);
            }
        }

        public SkeletonMeshMap ResolveSkeleton(Mesh mesh, Skeleton skeleton) =>
            skeletonMaps.GetValue(skeleton, s =>
            {
                var info = GetSkeletonInfo(s);
                foreach (var binding in mesh.Bindings)
                {
                    var boneName = mesh.Bones[binding.Bone];
                    if (!info.IndexByNameOrdinal.ContainsKey(boneName))
                        return new SkeletonMeshMap(null, boneName);
                }
                var map = new int[mesh.Bones.Count];
                for (var b = 0; b < mesh.Bones.Count; b++)
                    map[b] = info.IndexByNameOrdinal.TryGetValue(mesh.Bones[b], out var idx) ? idx : -1;
                return new SkeletonMeshMap(map, null);
            });
    }

    private static readonly ConditionalWeakTable<ObjectRegistry, AvatarSceneGeometry> Instances = new();
    private static readonly ConditionalWeakTable<Skeleton, SkeletonInfo> SkeletonInfos = new();
    private static readonly ConditionalWeakTable<Mesh, MeshBindingLayout> MeshLayouts = new();
    private static readonly TextureSource FallbackWhiteTexture = CreateSolidWhiteTexture();
    private static SkeletonInfo GetSkeletonInfo(Skeleton skeleton) => SkeletonInfos.GetValue(skeleton, static s => new SkeletonInfo(s));
    private static MeshBindingLayout GetMeshLayout(Mesh mesh) => MeshLayouts.GetValue(mesh, static m => new MeshBindingLayout(m));

    private readonly Lock _instanceLock = new();
    private readonly string gameRoot;
    private readonly ObjectRegistry registry;
    private readonly CharacterSearchPath skins;
    private readonly CharacterSearchPath textures;
    private readonly Dictionary<string, AppearanceSource> appearances = new(StringComparer.OrdinalIgnoreCase);
    private readonly Dictionary<string, Mesh> meshes = new(StringComparer.OrdinalIgnoreCase);
    private readonly Dictionary<string, TextureSource> textureCache = new(StringComparer.OrdinalIgnoreCase);
    private Dictionary<string, string>? textureStemByLower;
    private readonly Dictionary<(byte R, byte G, byte B), (byte[] Bytes, string Hash)> plumbobTextures = [];
    private readonly Dictionary<(IffFile File, ushort ChunkId), IReadOnlyList<string>> bodyStringsCache = [];
    private readonly Dictionary<string, SkateMesh> skateMeshes = new(StringComparer.OrdinalIgnoreCase);
    private SkateAttachmentFrames? skateAttachmentFrames;
    private Dictionary<uint, HandPropBinding>? handPropBindings;
    private readonly Dictionary<string, AnimationSource?> animations = new(StringComparer.OrdinalIgnoreCase);
    private readonly AvatarAnimations.SharedCharacterIndex sharedIndex;
    private CharacterSearchPath? animationPath;
    private IReadOnlyDictionary<string, CharacterFile[]>? curveFiles;
    private readonly List<Skeleton> skeletons = [];
    private readonly List<SkeletonInfo> uniqueSkeletons = [];
    private sealed class PersonGeometryState
    {
        public Vector3? HeadPosition;
        public Vector3? HeadAttachmentPosition;
        public Vector3? HandPosition;
        public Vector3? LeftHandPosition;
        public Vector3? PelvisPosition;
        public Vector3? HeadSeekRegistration;
        public Vector3? HeadFakeRegistration;
        public Vector3? AvatarRootPosition;
        public float? AvatarRootDirection;
        public CensorBounds? Censor;
        public (long Updates, float RootX, float RootY, float RootDirection, int Level, int ControlState) LastTickRoot;
        public (long Updates, float RootX, float RootY, float RootDirection, int Level, int ControlState) PrevTickRoot;
    }

    private readonly ConditionalWeakTable<XPerson, PersonGeometryState> personStates = new();
    private PersonGeometryState StateFor(XPerson person) => personStates.GetOrCreateValue(person);
    private PersonGeometryState? TryStateFor(XPerson person) => personStates.TryGetValue(person, out var state) ? state : null;

    private AvatarSceneGeometry(string gameRoot, ObjectRegistry registry)
    {
        this.gameRoot = gameRoot;
        this.registry = registry;
        sharedIndex = AvatarAnimations.GetSharedIndex(gameRoot, registry);
        skins = sharedIndex.Skins;
        textures = sharedIndex.Textures;
        animationPath = sharedIndex.Animation;
        curveFiles = sharedIndex.CurveFiles;
        for (var i = 0; i < sharedIndex.ParsedFiles.Count; i++)
        {
            var parsed = sharedIndex.ParsedFiles[i];
            skeletons.AddRange(parsed.Data.Skeletons);
            for (var a = 0; a < parsed.Data.Appearances.Count; a++)
            {
                var appearance = parsed.Data.Appearances[a];
                appearances.TryAdd(appearance.Name, new AppearanceSource(appearance, parsed.File, parsed.Data, parsed.Path));
            }
        }
        var seenSignatures = new HashSet<string>(StringComparer.Ordinal);
        foreach (var skeleton in skeletons)
        {
            var info = GetSkeletonInfo(skeleton);
            if (seenSignatures.Add(info.Signature)) uniqueSkeletons.Add(info);
        }
    }

    internal static AvatarSceneGeometry For(string gameRoot, ObjectRegistry registry) =>
        Instances.GetValue(registry, _ => new AvatarSceneGeometry(gameRoot, registry));

    internal sealed record PosedHeadMesh(Vector3[] Positions, Vector3[] Normals, Vector2[] UVs, bool[] OnHead,
        (int A, int B, int C)[] Faces, byte[] Texture, Vector3? HeadPivot = null, float HeadHeight = 0f,
        Vector3? HeadOrigin = null, float HeadScale = 1f);

    internal bool HasHandPropMesh(uint guid) => ReadHandPropBindings().ContainsKey(guid);

    internal IReadOnlyList<Part> Build(XPerson person, int level, int cameraOrientation,
        Func<float, float, float> elevation, LotCamera camera, List<PosedHeadMesh>? headMeshes = null,
        Vector3? attachmentRoot = null, float? inheritedRootDirection = null, int headIndicatorKind = 0,
        float subTickAlpha = 0f, long updates = 0, ISimulationCareerHost? careerHost = null,
        IReadOnlyList<uint>? heldPropGuids = null)
    {
        var character = person.PresentationCharacter ?? person.SavedCharacter;
        if (character is null)
        {
            PrepareRootTransform(person, level, elevation, camera, headMeshes, attachmentRoot, inheritedRootDirection, subTickAlpha, updates);
            if (headMeshes is null && TryStateFor(person) is { } missingCharState) missingCharState.Censor = null;
            return Array.Empty<Part>();
        }
        var effectiveParts = character.Parts.Count >= 5
            ? character.Parts
            : character.Parts.Concat(Enumerable.Repeat(("NONE", ""), 5 - character.Parts.Count)).ToArray();

        var (bodyPair, leftHandPair, rightHandPair, headPair) = ResolveEffectiveParts(person, effectiveParts, careerHost);
        var selected = new List<(string Name, string? Texture, string? TextureFilter, string SavedName, int Role)>();
        const int RoleBody = 0;
        const int RoleHand = 1;
        const int RoleHead = 2;
        const int RoleExtra = 3;
        AddPair(bodyPair, RoleBody);
        AddPair(leftHandPair, RoleHand);
        AddPair(rightHandPair, RoleHand);
        AddPair(headPair, RoleHead);
        var extraPartStart = selected.Count;
        var seenExtraParts = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        foreach (var extraPart in character.ExtraParts.Concat(person.TransientExtraParts))
        {
            var normalizedExtra = NormalizeAppearance(extraPart.Item1.Trim());
            if (normalizedExtra.Length > 0 && !normalizedExtra.Equals("NONE", StringComparison.OrdinalIgnoreCase) &&
                seenExtraParts.Add(normalizedExtra))
                AddPair(extraPart, RoleExtra);
        }
        if (extraPartStart == 0 && appearances.Count > 0)
        {
            var fallbackMarker = PersonFallbackMarker(person);
            if (BodyFallbackByMarker(fallbackMarker) is { } fallbackBody)
                selected.Insert(extraPartStart++, (fallbackBody, null, null, fallbackBody, RoleBody));
            if (HeadFallbackByMarker(fallbackMarker) is { } fallbackHead)
                selected.Insert(extraPartStart++, (fallbackHead.Appearance.Name, null, null, fallbackHead.Appearance.Name, RoleHead));
        }
        if (selected.Count == 0)
        {
            PrepareRootTransform(person, level, elevation, camera, headMeshes, attachmentRoot, inheritedRootDirection, subTickAlpha, updates);
            if (headMeshes is null && TryStateFor(person) is { } emptySelectedState) emptySelectedState.Censor = null;
            return Array.Empty<Part>();
        }

        var resolved = new List<(string Name, AppearanceSource source, (Binding Binding, Mesh Mesh, TextureSource Texture)[] bindings, bool IsExtraPart)>();
        for (var selectedIndex = 0; selectedIndex < selected.Count; selectedIndex++)
        {
            var isExtraPart = selectedIndex >= extraPartStart;
            var item = selected[selectedIndex];
            var normalizedName = NormalizeAppearance(item.Name);
            var source = appearances.GetValueOrDefault(normalizedName);
            if (source is null)
            {
                if (normalizedName.StartsWith("accessory-", StringComparison.OrdinalIgnoreCase))
                    source = appearances.GetValueOrDefault(normalizedName["accessory-".Length..]);
                else if (normalizedName.StartsWith("suit-", StringComparison.OrdinalIgnoreCase))
                    source = appearances.GetValueOrDefault(normalizedName["suit-".Length..]);
                // Normalizes a typo in the chemistry set expansion pack string table where the suit name
                // mismatches its registered character definition.
                if (source is null &&
                    (normalizedName.Equals("suit-chemset-heed-stars104", StringComparison.OrdinalIgnoreCase) ||
                     normalizedName.Equals("chemset-heed-stars104", StringComparison.OrdinalIgnoreCase)))
                    source = appearances.GetValueOrDefault("suit-chemsuit-heed-stars104");
            }
            if (source is null && (item.Role == RoleBody || normalizedName.StartsWith("b", StringComparison.OrdinalIgnoreCase)))
            {
                var fallback = BodyFallback(normalizedName) ?? BodyFallbackByMarker(PersonFallbackMarker(person));
                source = fallback is null ? null : appearances.GetValueOrDefault(fallback);
            }
            if (source is null && (item.Role == RoleHead || normalizedName.StartsWith("c", StringComparison.OrdinalIgnoreCase)))
                source = HeadFallback(normalizedName) ?? HeadFallbackByMarker(PersonFallbackMarker(person));
            if (source is null)
            {
                if (item.Role == RoleHand || normalizedName.StartsWith("h", StringComparison.OrdinalIgnoreCase) || isExtraPart)
                    continue;
                continue;
            }
            var bindingsList = new List<(Binding Binding, Mesh Mesh, TextureSource Texture)>(source.Appearance.Bindings.Count);
            foreach (var binding in source.Appearance.Bindings)
            {
                Mesh mesh;
                try { mesh = ReadMesh(source.Path, binding.Mesh); }
                catch (InvalidDataException) when (isExtraPart) { continue; }
                var useOverride = item.Texture is not null &&
                    (item.TextureFilter is null || binding.Mesh.Contains(item.TextureFilter, StringComparison.OrdinalIgnoreCase));
                var requestedTexture = useOverride ? item.Texture! : mesh.Texture;
                TextureSource texture;
                try { texture = ReadTexture(requestedTexture); }
                catch (InvalidDataException) when (useOverride)
                {
                    try { texture = ReadTexture(mesh.Texture); }
                    catch (InvalidDataException) when (isExtraPart) { texture = FallbackWhiteTexture; }
                }
                catch (InvalidDataException) when (isExtraPart)
                {
                    texture = FallbackWhiteTexture;
                }
                bindingsList.Add((binding, mesh, texture));
            }
            var bindings = bindingsList.ToArray();
            if (bindings.Length == 0)
                continue;
            resolved.Add((item.Name, source, bindings, isExtraPart));
        }

        if (resolved.Count == 0)
        {
            PrepareRootTransform(person, level, elevation, camera, headMeshes, attachmentRoot, inheritedRootDirection, subTickAlpha, updates);
            if (headMeshes is null && TryStateFor(person) is { } emptyResolvedState) emptyResolvedState.Censor = null;
            return Array.Empty<Part>();
        }

        var coreRequiredBones = new HashSet<string>(StringComparer.Ordinal);
        var allRequiredBones = new HashSet<string>(StringComparer.Ordinal);
        AppearanceSource? bodySource = null;
        var primaryBodyName = selected[0].Name;
        for (var r = 0; r < resolved.Count; r++)
        {
            var entry = resolved[r];
            if (bodySource is null && entry.Name.Equals(primaryBodyName, StringComparison.OrdinalIgnoreCase))
                bodySource = entry.source;
            for (var b = 0; b < entry.bindings.Length; b++)
            {
                var meshBones = entry.bindings[b].Mesh.Bones;
                for (var mb = 0; mb < meshBones.Count; mb++)
                {
                    var boneName = meshBones[mb];
                    allRequiredBones.Add(boneName);
                    if (!entry.IsExtraPart) coreRequiredBones.Add(boneName);
                }
            }
        }
        bodySource ??= resolved[0].source;
        Skeleton skeleton;
        try { skeleton = SelectSkeleton(bodySource, allRequiredBones, person); }
        catch (InvalidDataException) when (allRequiredBones.Count > coreRequiredBones.Count)
        {
            skeleton = SelectSkeleton(bodySource, coreRequiredBones, person);
        }
        var skeletonInfo = GetSkeletonInfo(skeleton);
        var pose = headMeshes is null
            ? Pose.ApplyHeadAdjustment(skeleton, AnimationPose(person, skeleton, subTickAlpha), person.AnimatorHeadAdjustment)
            : Pose.BindPose(skeleton);
        var boneMatrices = new Matrix4x4[pose.Count];
        for (var b = 0; b < pose.Count; b++)
        {
            var bone = pose[b];
            var matrix = Matrix4x4.CreateFromQuaternion(Pose.BoneMatrixRotation(bone.WorldRotation));
            matrix.M41 = bone.WorldTranslation.X;
            matrix.M42 = bone.WorldTranslation.Y;
            matrix.M43 = bone.WorldTranslation.Z;
            boneMatrices[b] = matrix;
        }

        var (tileX, tileY, altitude, rootDirection) = PrepareRootTransform(
            person, level, elevation, camera, headMeshes, attachmentRoot, inheritedRootDirection, subTickAlpha, updates);
        var facing = AvatarDirection.LotFacingAngle(rootDirection);
        var facingMatrix = headMeshes is null ? Matrix4x4.CreateRotationY(facing) : Matrix4x4.Identity;
        var headName = NormalizeAppearance(headPair.Item1.Trim());
        var headResolved = headName.Length > 0 && !headName.Equals("NONE", StringComparison.OrdinalIgnoreCase)
            ? resolved.FirstOrDefault(item => item.Name.Equals(headName, StringComparison.OrdinalIgnoreCase))
            : default;
        // Filter to HEAD-bone bindings across suits to drop quadruped body parts while keeping head accessories.
        var headBindingsList = headMeshes is null
            ? null
            : resolved.SelectMany(item => item.bindings)
                .Where(item => item.Binding.Bone.Equals("HEAD", StringComparison.OrdinalIgnoreCase))
                .ToArray();
        if (headBindingsList is { Length: 0 })
            headBindingsList = headResolved.bindings ?? resolved[^1].bindings;
        var headBindings = headBindingsList?.Select(item => item.Mesh).ToHashSet();
        var skullMeshes = headBindingsList?
            .Where(item => item.Binding.Mesh.Contains("HEAD-HEAD", StringComparison.OrdinalIgnoreCase))
            .Select(item => item.Mesh)
            .ToHashSet();
        if (skullMeshes is { Count: 0 })
        {
            skullMeshes = headBindingsList?
                .Where(item => !item.Binding.Mesh.Contains("-HAIR", StringComparison.OrdinalIgnoreCase) &&
                               !item.Binding.Mesh.Contains("-HAT", StringComparison.OrdinalIgnoreCase) &&
                               !item.Binding.Mesh.Contains("-ACC", StringComparison.OrdinalIgnoreCase) &&
                               !item.Binding.Mesh.Contains("-SPECS", StringComparison.OrdinalIgnoreCase))
                .Select(item => item.Mesh)
                .ToHashSet();
        }
        if (skullMeshes is { Count: 0 }) skullMeshes = headBindings;
        var scale = person.AnimatorBodyScale;
        var rootTransform = facingMatrix * Matrix4x4.CreateScale(scale / 3f) *
                           Matrix4x4.CreateTranslation(AvatarCoordinates.RootTranslation(tileX, tileY, altitude));
        var bodyStrings = ReadBodyStrings(person);
        CacheHeadSeekRegistrations(person, pose, skeletonInfo, bodyStrings, rootTransform);
        BonePose? FindBoneIgnoreCase(string name) =>
            skeletonInfo.IndexByNameIgnoreCase.TryGetValue(name, out var idx) ? pose[idx] : null;
        var headIndex = skeletonInfo.IndexByNameIgnoreCase.TryGetValue("HEAD", out var foundHeadIdx) ? foundHeadIdx : -1;
        var head = headIndex >= 0 ? pose[headIndex] : null;
        Vector3? headOrigin = null;
        Vector3? pieHeadPivot = null;
        var pieHeadHeight = 0.24f * scale;
        if (head is not null)
        {
            if (headMeshes is not null)
            {
                // Override bind-pose neck tilt (e.g. quadrupeds) to upright camera-facing pose with 10-degree isometric pitch.
                var uprightHead = Matrix4x4.CreateRotationZ(MathF.PI * 0.5f) * Matrix4x4.CreateRotationX(10f * MathF.PI / 180f);
                uprightHead.M41 = head.WorldTranslation.X;
                uprightHead.M42 = head.WorldTranslation.Y;
                uprightHead.M43 = head.WorldTranslation.Z;
                boneMatrices[headIndex] = uprightHead;
            }
            var personState = StateFor(person);
            var headRoot = Vector3.Transform(head.WorldTranslation, rootTransform);
            personState.HeadPosition = AvatarCoordinates.ToLot(headRoot);
            headOrigin = headRoot;
            pieHeadPivot = headRoot + new Vector3(0f, 0.105f * scale, 0f);
        }
        var activePersonState = StateFor(person);
        var headAttachmentBoneName = bodyStrings is { Count: > 3 } && !string.IsNullOrWhiteSpace(bodyStrings[3])
            ? bodyStrings[3]
            : "HEAD";
        var headAttachmentSuffix = bodyStrings is { Count: > 4 } && !string.IsNullOrWhiteSpace(bodyStrings[4])
            ? bodyStrings[4]
            : "Top";
        var headAttachmentBone = FindBoneIgnoreCase(headAttachmentBoneName) ?? head;
        if (headAttachmentBone is not null)
        {
            var headAttachmentRoot = Vector3.Transform(Pose.RegistrationTranslation(headAttachmentBone, headAttachmentSuffix), rootTransform);
            activePersonState.HeadAttachmentPosition = AvatarCoordinates.ToLot(headAttachmentRoot);
        }
        var handBoneName = bodyStrings is { Count: > 5 } && !string.IsNullOrWhiteSpace(bodyStrings[5])
            ? bodyStrings[5]
            : "R_HAND";
        var handSuffix = bodyStrings is { Count: > 6 } && !string.IsNullOrWhiteSpace(bodyStrings[6])
            ? bodyStrings[6]
            : "Palm";
        var hand = FindBoneIgnoreCase(handBoneName) ?? FindBoneIgnoreCase("R_HAND");
        if (hand is not null)
        {
            var handRoot = Vector3.Transform(Pose.RegistrationTranslation(hand, handSuffix), rootTransform);
            activePersonState.HandPosition = AvatarCoordinates.ToLot(handRoot);
        }
        var leftHand = FindBoneIgnoreCase("L_HAND");
        if (leftHand is not null)
        {
            var leftHandRoot = Vector3.Transform(Pose.RegistrationTranslation(leftHand, handSuffix), rootTransform);
            activePersonState.LeftHandPosition = AvatarCoordinates.ToLot(leftHandRoot);
        }
        else
        {
            activePersonState.LeftHandPosition = null;
        }
        var pelvis = FindBoneIgnoreCase("PELVIS");
        if (pelvis is not null)
        {
            var pelvisRoot = Vector3.Transform(pelvis.WorldTranslation, rootTransform);
            activePersonState.PelvisPosition = AvatarCoordinates.ToLot(pelvisRoot);
        }
        var parts = new List<Part>();
        var hasSkates = person.InteractionAttachments.Contains(InteractionLifecycle.SkateAttachment);
        Dictionary<string, List<Vector3>>? skateFootPositions = hasSkates
            ? new Dictionary<string, List<Vector3>>(StringComparer.OrdinalIgnoreCase) { ["left"] = [], ["right"] = [] }
            : null;
        var leftFootPositions = skateFootPositions?["left"];
        var rightFootPositions = skateFootPositions?["right"];
        // CensorshipFlags: 0x80 censors full body; 0x01..0x7F selects clusters from the -needs mesh.
        var rawCensorFlags = headMeshes is null ? unchecked((ushort)person[PersonData.CensorshipFlags]) : (ushort)0;
        var fullBodyCensor = (rawCensorFlags & 0x80) != 0;
        var censorMask = fullBodyCensor ? 0x7f : (rawCensorFlags & 0x7f);
        var needsSource = !fullBodyCensor && censorMask != 0
            ? appearances.GetValueOrDefault($"{skeleton.Name}-needs")
            : null;
        var hasCensorBounds = false;
        var censorMinX = float.MaxValue;
        var censorMinY = float.MaxValue;
        var censorMaxX = float.MinValue;
        var censorMaxY = float.MinValue;
        var censorMinDepth = float.MaxValue;

        foreach (var (_, _, bindings, isExtraPart) in resolved)
        foreach (var (outfitBinding, mesh, texture) in bindings)
        {
            var censorThisBinding = rawCensorFlags != 0 &&
                (fullBodyCensor || (needsSource is null && outfitBinding.Integers.Length > 0 && (outfitBinding.Integers[0] & censorMask) != 0));
            if (mesh.Faces.Count * 3 > 250_000) throw new InvalidDataException($"Sim {person.Id} avatar mesh exceeds the scene vertex limit");
            var meshLayout = GetMeshLayout(mesh);
            if (meshLayout.HasInvalidBoneIndex) throw new InvalidDataException($"Sim {person.Id} mesh binding names an unknown bone");
            var skeletonMap = meshLayout.ResolveSkeleton(mesh, skeleton);
            if (skeletonMap.BoneIndices is not { } meshBoneToSkeleton)
            {
                if (isExtraPart) continue;
                throw new InvalidDataException($"Sim {person.Id} skeleton {skeleton.Name} has no mesh bone {skeletonMap.MissingBoneName}");
            }

            var boneForVertex = meshLayout.BoneForVertex;
            var blendBoneForVertex = meshLayout.BlendBoneForVertex;
            var blendWeightForVertex = meshLayout.BlendWeightForVertex;
            var blendVertexForVertex = meshLayout.BlendVertexForVertex;
            var vertexCount = mesh.TextureCoordinates.Count;
            var needHeadPose = headBindings is not null && headBindings.Contains(mesh);
            var projected = s_projectedScratch;
            if (projected is null || projected.Length < vertexCount)
            {
                projected = new Vertex[Math.Max(vertexCount, 256)];
                s_projectedScratch = projected;
            }
            (Vector3 Position, Vector3 Normal, Vector2 UV)[]? posed = null;
            if (needHeadPose)
            {
                posed = s_posedScratch;
                if (posed is null || posed.Length < vertexCount)
                {
                    posed = new (Vector3 Position, Vector3 Normal, Vector2 UV)[Math.Max(vertexCount, 256)];
                    s_posedScratch = posed;
                }
            }
            var skateScale = scale / 3f;
            for (var vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++)
            {
                var matrix = boneMatrices[meshBoneToSkeleton[boneForVertex[vertexIndex]]];
                var source = mesh.Vertices[vertexIndex];
                var position = Vector3.Transform(source.Position, matrix);
                var normal = Vector3.TransformNormal(source.Normal, matrix);
                var blendBone = blendBoneForVertex[vertexIndex];
                if (blendBone >= 0)
                {
                    var blendMatrix = boneMatrices[meshBoneToSkeleton[blendBone]];
                    var blendSource = mesh.Vertices[blendVertexForVertex[vertexIndex]];
                    var blendPosition = Vector3.Transform(blendSource.Position, blendMatrix);
                    var blendWeight = blendWeightForVertex[vertexIndex];
                    position = Vector3.Lerp(position, blendPosition, blendWeight);
                    // Blend vertex normals in original SKN/BMF assets are exported from the wrong
                    // vertex index and frequently point inward; only blend positions, keeping the
                    // primary bone's transformed normal.
                }
                normal = Vector3.TransformNormal(normal, facingMatrix);
                var cameraNormal = camera.CameraNormal(new Vector3(normal.Z, normal.Y, normal.X));
                if (cameraNormal.LengthSquared() > 0) cameraNormal = Vector3.Normalize(cameraNormal);
                if (hasSkates)
                {
                    if (meshLayout.IsLeftFootVertex[vertexIndex])
                        leftFootPositions!.Add(Vector3.Transform(position, facingMatrix) * skateScale);
                    else if (meshLayout.IsRightFootVertex[vertexIndex])
                        rightFootPositions!.Add(Vector3.Transform(position, facingMatrix) * skateScale);
                }
                var rootPosition = Vector3.Transform(position, rootTransform);
                var uv = mesh.TextureCoordinates[vertexIndex];
                if (posed is not null)
                    posed[vertexIndex] = (rootPosition, new Vector3(cameraNormal.X, cameraNormal.Y, cameraNormal.Z), uv);

                var lotPosition = AvatarCoordinates.ToLot(rootPosition);
                var point = camera.Project(lotPosition.X, lotPosition.Y, rootPosition.Y * 40);
                var vertexDepth = camera.Depth(lotPosition.X, lotPosition.Y, rootPosition.Y);
                projected[vertexIndex] = new Vertex(point.X, point.Y, vertexDepth,
                    uv.X, uv.Y, cameraNormal.X, cameraNormal.Y, cameraNormal.Z);
            }

            if (posed is not null)
            {
                var framesHead = skullMeshes is null || skullMeshes.Contains(mesh);
                var headPositionsOut = new Vector3[vertexCount];
                var headNormalsOut = new Vector3[vertexCount];
                var headUvsOut = new Vector2[vertexCount];
                var onHeadOut = new bool[vertexCount];
                for (var v = 0; v < vertexCount; v++)
                {
                    headPositionsOut[v] = posed[v].Position;
                    headNormalsOut[v] = posed[v].Normal;
                    headUvsOut[v] = posed[v].UV;
                    onHeadOut[v] = framesHead && meshLayout.IsHeadBoneVertex[v];
                }
                headMeshes!.Add(new PosedHeadMesh(headPositionsOut, headNormalsOut,
                    headUvsOut, onHeadOut,
                    meshLayout.FacesTuples, texture.Bytes, pieHeadPivot, pieHeadHeight, headOrigin, scale));
            }
            var flatFaces = meshLayout.FlatFaceIndices;
            var vertices = new Vertex[flatFaces.Length];
            if (censorThisBinding)
            {
                for (var output = 0; output < flatFaces.Length; output++)
                {
                    var v = projected[flatFaces[output]];
                    hasCensorBounds = true;
                    if (v.X < censorMinX) censorMinX = v.X;
                    if (v.Y < censorMinY) censorMinY = v.Y;
                    if (v.X > censorMaxX) censorMaxX = v.X;
                    if (v.Y > censorMaxY) censorMaxY = v.Y;
                    if (v.Z < censorMinDepth) censorMinDepth = v.Z;
                    vertices[output] = v;
                }
            }
            else
            {
                for (var output = 0; output < flatFaces.Length; output++)
                    vertices[output] = projected[flatFaces[output]];
            }
            parts.Add(new Part(texture.Bytes, texture.Sha1Hex, texture.Encoding, texture.Width, texture.Height, vertices));
        }
        if (headMeshes is null)
        {
            if (needsSource is not null)
            {
                foreach (var needsBinding in needsSource.Appearance.Bindings)
                {
                    if (needsBinding.Integers.Length == 0 || (needsBinding.Integers[0] & censorMask) == 0) continue;
                    Mesh needsMesh;
                    try { needsMesh = ReadMesh(needsSource.Path, needsBinding.Mesh); }
                    catch (InvalidDataException) { continue; }
                    if (needsMesh.TextureCoordinates.Count == 0 || needsMesh.TextureCoordinates.Count > 250_000) continue;

                    var needsLayout = GetMeshLayout(needsMesh);
                    if (needsLayout.HasInvalidBoneIndex) continue;
                    if (needsLayout.ResolveSkeleton(needsMesh, skeleton).BoneIndices is not { } needsBoneMap) continue;

                    var needsBoneForVertex = needsLayout.BoneForVertex;
                    var needsBlendBone = needsLayout.BlendBoneForVertex;
                    var needsBlendWeight = needsLayout.BlendWeightForVertex;
                    var needsBlendVertex = needsLayout.BlendVertexForVertex;
                    for (var vertexIndex = 0; vertexIndex < needsMesh.TextureCoordinates.Count; vertexIndex++)
                    {
                        var matrix = boneMatrices[needsBoneMap[needsBoneForVertex[vertexIndex]]];
                        var position = Vector3.Transform(needsMesh.Vertices[vertexIndex].Position, matrix);
                        var blendBone = needsBlendBone[vertexIndex];
                        if (blendBone >= 0)
                        {
                            var blendMatrix = boneMatrices[needsBoneMap[blendBone]];
                            var blendPosition = Vector3.Transform(needsMesh.Vertices[needsBlendVertex[vertexIndex]].Position, blendMatrix);
                            position = Vector3.Lerp(position, blendPosition, needsBlendWeight[vertexIndex]);
                        }
                        var rootPosition = Vector3.Transform(position, rootTransform);
                        var lotPosition = AvatarCoordinates.ToLot(rootPosition);
                        var point = camera.Project(lotPosition.X, lotPosition.Y, rootPosition.Y * 40);
                        var needsDepth = camera.Depth(lotPosition.X, lotPosition.Y, rootPosition.Y);
                        hasCensorBounds = true;
                        if (point.X < censorMinX) censorMinX = point.X;
                        if (point.Y < censorMinY) censorMinY = point.Y;
                        if (point.X > censorMaxX) censorMaxX = point.X;
                        if (point.Y > censorMaxY) censorMaxY = point.Y;
                        if (needsDepth < censorMinDepth) censorMinDepth = needsDepth;
                    }
                }
            }

            if (hasCensorBounds && censorMinX < censorMaxX && censorMinY < censorMaxY)
            {
                var pelvisLot = TryStateFor(person)?.PelvisPosition is { } cachedPelvis
                    ? cachedPelvis
                    : new Vector3(tileX, tileY, altitude + 0.5f);
                var baseCensorDepth = Math.Min(camera.Depth(pelvisLot.X, pelvisLot.Y, pelvisLot.Z) - 0.0013428f, censorMinDepth - 0.0001f);
                var censorDepth = Math.Clamp(baseCensorDepth, 0.001f, 0.999f);
                // Expands censor bounds by 2 medium-zoom scene units, scaling to 1, 2, or 4 screen pixels
                // depending on the active zoom level.
                StateFor(person).Censor = new CensorBounds(censorMinX - 2f, censorMinY - 2f,
                    censorMaxX - censorMinX + 4f, censorMaxY - censorMinY + 4f, censorDepth);
            }
            else
            {
                if (TryStateFor(person) is { } clearCensorState) clearCensorState.Censor = null;
            }
        }
        if (hasSkates)
            AddSkateParts(person, parts, skateFootPositions!, tileX, tileY, altitude, camera);
        if (headMeshes is null && heldPropGuids is { Count: > 0 })
            AddHandPropParts(person, heldPropGuids, skeletonInfo, boneMatrices, facingMatrix, rootTransform, camera, parts);
        if (headMeshes is null && headIndicatorKind is 1 or 2 or 3 && head is not null)
            AddHeadIndicatorPart(person, headIndicatorKind, head, facingMatrix, rootTransform, camera, parts, subTickAlpha);
        return parts;

        void AddPair((string, string) pair, int role)
        {
            var name = pair.Item1.Trim();
            if (name.Length == 0 || name.Equals("NONE", StringComparison.OrdinalIgnoreCase)) return;
            var rawTex = pair.Item2;
            var semicolon = rawTex.IndexOf(';');
            if (semicolon >= 0) rawTex = rawTex[..semicolon];
            var equals = rawTex.IndexOf('=');
            var filter = equals >= 0 ? rawTex[..equals].Trim() : null;
            if (filter?.Length == 0) filter = null;
            var texture = equals >= 0 ? rawTex[(equals + 1)..].Trim() : (rawTex.Length > 0 ? rawTex.Trim() : null);
            if (texture?.Length == 0) texture = null;
            selected.Add((name.EndsWith(".apr", StringComparison.OrdinalIgnoreCase) ? name[..^4] : name, texture, filter, name, role));
        }
    }

    private (float TileX, float TileY, float Altitude, float RootDirection) PrepareRootTransform(
        XPerson person, int level, Func<float, float, float> elevation, LotCamera camera,
        List<PosedHeadMesh>? headMeshes, Vector3? attachmentRoot, float? inheritedRootDirection,
        float subTickAlpha, long updates)
    {
        var route = person.NativeRoute;
        var rootFtileX = (person.AnimatorRootX is { } rootX && float.IsFinite(rootX)
            ? rootX
            : route is { } activeRoute && float.IsFinite(activeRoute.MotionX)
                ? activeRoute.MotionX
            : person.Position.X) + person.AnimatorDisplacementX;
        var rootFtileY = (person.AnimatorRootY is { } rootY && float.IsFinite(rootY)
            ? rootY
            : route is { } activeRouteY && float.IsFinite(activeRouteY.MotionY)
                ? activeRouteY.MotionY
            : person.Position.Y) + person.AnimatorDisplacementY;
        var baseRootDirection = AvatarDirection.RootDirection(person.AnimatorRootDirection,
            person[ObjectData.Direction], person.AnimatorDisplacementDirection, inheritedRootDirection);
        var rootDirection = baseRootDirection;
        var rootState = StateFor(person);
        if (headMeshes is null && updates > 0)
        {
            var controlState = person.AnimatorControlState;
            var lastRoot = rootState.LastTickRoot;
            if (lastRoot.Updates != updates)
            {
                if (lastRoot.Updates > 0) rootState.PrevTickRoot = lastRoot;
                lastRoot = (updates, rootFtileX, rootFtileY, baseRootDirection, level, controlState);
                rootState.LastTickRoot = lastRoot;
            }
            var prevRoot = rootState.PrevTickRoot;
            var hasPrevRoot = prevRoot.Updates > 0 &&
                prevRoot.Level == level && prevRoot.Updates == updates - 1;
            if (subTickAlpha > 0f && route is { } subRoute && person.AnimationPlayback is { RouteDriven: true } playback)
            {
                var sampleCount = playback.Clip.StandardRootMotionSamples?.Count ?? 0;
                if (controlState is 4 or 5 && sampleCount > 0 && playback.Clip.DurationMilliseconds > 0f)
                {
                    var turnScale = subRoute.TurnRootPracticeScale ?? person.AnimatorWalkingScale;
                    var subFrame = Math.Min(sampleCount,
                        subRoute.MotionPracticeFrame + sampleCount * (subTickAlpha * 42f * MathF.Abs(turnScale) / playback.Clip.DurationMilliseconds));
                    var phase = Math.Clamp(subFrame / sampleCount, 0f, 1f);
                    if (subRoute.TurnRootOriginX is { } ox && subRoute.TurnRootOriginY is { } oy &&
                        subRoute.TurnRootTargetX is { } tx && subRoute.TurnRootTargetY is { } ty)
                    {
                        rootFtileX = ox + (tx - ox) * phase + person.AnimatorDisplacementX;
                        rootFtileY = oy + (ty - oy) * phase + person.AnimatorDisplacementY;
                    }
                    if (inheritedRootDirection is null &&
                        subRoute.TurnRootStartDirection is { } sd && subRoute.TurnRootPracticeDirection is { } pd)
                    {
                        rootDirection = AvatarDirection.Wrap(sd + (pd - sd) * phase + person.AnimatorDisplacementDirection);
                    }
                }
                else if (controlState is 6 or 11 && sampleCount > 0 && playback.Clip.DurationMilliseconds > 0f &&
                         subRoute.StartRootOriginX is { } sx && subRoute.StartRootOriginY is { } sy &&
                         subRoute.StartRootTargetX is { } stx && subRoute.StartRootTargetY is { } sty)
                {
                    var startScale = MathF.Abs(person.AnimatorWalkingScale);
                    var subFrame = Math.Min(sampleCount,
                        subRoute.MotionPracticeFrame + sampleCount * (subTickAlpha * 42f * startScale / playback.Clip.DurationMilliseconds));
                    var phase = Math.Clamp(subFrame / sampleCount, 0f, 1f);
                    rootFtileX = sx + (stx - sx) * phase + person.AnimatorDisplacementX;
                    rootFtileY = sy + (sty - sy) * phase + person.AnimatorDisplacementY;
                }
                else if (controlState is 9 or 10 && subRoute.AnimatorFollowState == 1 && subRoute.TransitionTargetX is null)
                {
                    var hasTarget = subRoute.MotionTargetX != int.MinValue && subRoute.MotionTargetY != int.MinValue;
                    var stepX = person.AnimatorProjectedRootStepX;
                    var stepY = person.AnimatorProjectedRootStepY;
                    var stepSq = stepX * stepX + stepY * stepY;
                    if (stepSq is <= 0.0001f or >= 16f && hasPrevRoot && prevRoot.ControlState is 9 or 10)
                    {
                        stepX = lastRoot.RootX - prevRoot.RootX;
                        stepY = lastRoot.RootY - prevRoot.RootY;
                        stepSq = stepX * stepX + stepY * stepY;
                    }
                    if (stepSq is > 0.0001f and < 16f)
                    {
                        var speed = MathF.Sqrt(stepSq);
                        var maxMove = speed * subTickAlpha;
                        if (hasTarget && subRoute.MotionTargetIsDestination)
                        {
                            var remX = subRoute.MotionTargetX - lastRoot.RootX;
                            var remY = subRoute.MotionTargetY - lastRoot.RootY;
                            maxMove = MathF.Min(maxMove, MathF.Sqrt(remX * remX + remY * remY));
                        }
                        rootFtileX = lastRoot.RootX + (stepX / speed) * maxMove;
                        rootFtileY = lastRoot.RootY + (stepY / speed) * maxMove;
                    }
                    else if (hasTarget && playback.Clip.DurationMilliseconds > 0f && playback.Clip.StandardDistance > 0f)
                    {
                        var toTargetX = subRoute.MotionTargetX - lastRoot.RootX;
                        var toTargetY = subRoute.MotionTargetY - lastRoot.RootY;
                        var toTargetSq = toTargetX * toTargetX + toTargetY * toTargetY;
                        if (toTargetSq > 0.0001f)
                        {
                            var nominalStep = playback.Clip.StandardDistance * (16f / 3f) *
                                (42f * MathF.Abs(playback.PracticeScale) / playback.Clip.DurationMilliseconds);
                            var dist = MathF.Sqrt(toTargetSq);
                            var move = MathF.Min(nominalStep * subTickAlpha, dist);
                            rootFtileX = lastRoot.RootX + (toTargetX / dist) * move;
                            rootFtileY = lastRoot.RootY + (toTargetY / dist) * move;
                        }
                    }

                    if (inheritedRootDirection is null && hasPrevRoot && prevRoot.ControlState is 9 or 10 && !subRoute.EndFollowPending)
                    {
                        var angVel = AvatarDirection.ShortestDelta(prevRoot.RootDirection, lastRoot.RootDirection);
                        if (MathF.Abs(angVel) is > 0.0001f and <= 0.35f)
                        {
                            var delta = angVel * subTickAlpha;
                            if (stepSq > 0.0001f)
                            {
                                var targetHeading = AvatarDirection.Toward(stepX, stepY);
                                var remaining = AvatarDirection.ShortestDelta(lastRoot.RootDirection, targetHeading);
                                if (angVel * remaining > 0f && MathF.Abs(delta) > MathF.Abs(remaining))
                                    delta = remaining;
                                else if (angVel * remaining <= 0f)
                                    delta = 0f;
                            }
                            rootDirection = AvatarDirection.Wrap(lastRoot.RootDirection + delta);
                        }
                    }
                }
            }
        }
        var tileX = rootFtileX / 16f;
        var tileY = rootFtileY / 16f;
        var levelDelta = level - 1;
        float sampledElevation;
        if (attachmentRoot is null)
        {
            var fx0 = MathF.Floor(rootFtileX);
            var fy0 = MathF.Floor(rootFtileY);
            var tx = rootFtileX - fx0;
            var ty = rootFtileY - fy0;
            var e00 = elevation(fx0 / 16f, fy0 / 16f);
            var e10 = elevation((fx0 + 1f) / 16f, fy0 / 16f);
            var e01 = elevation(fx0 / 16f, (fy0 + 1f) / 16f);
            var e11 = elevation((fx0 + 1f) / 16f, (fy0 + 1f) / 16f);
            var e0 = e00 + (e10 - e00) * tx;
            var e1 = e01 + (e11 - e01) * tx;
            sampledElevation = e0 + (e1 - e0) * ty;
        }
        else
        {
            sampledElevation = elevation(AvatarCoordinates.ElevationSample(rootFtileX),
                AvatarCoordinates.ElevationSample(rootFtileY));
        }
        var altitude = sampledElevation / 40 + levelDelta * EntityTransform.StoryHeight;
        if (attachmentRoot is { } inheritedRoot)
        {
            tileX = inheritedRoot.X;
            tileY = inheritedRoot.Y;
            altitude = inheritedRoot.Z;
        }
        rootState.AvatarRootPosition = new Vector3(tileX, tileY, altitude);
        rootState.AvatarRootDirection = rootDirection;
        return (tileX, tileY, altitude, rootDirection);
    }

    private string? ResolveCategorySuit(IReadOnlyList<string>? values, int index, char category, int? fallbackIndex = null)
    {
        if (values is null) return null;
        static string StripComment(string value)
        {
            var semicolon = value.IndexOf(';');
            return (semicolon >= 0 ? value[..semicolon] : value).Trim();
        }
        var existing = values.Count > index ? StripComment(values[index]) : "";
        if (existing.Equals("ADDED", StringComparison.OrdinalIgnoreCase)) existing = "";
        if (existing.Length == 0 && fallbackIndex is { } fallback && values.Count > fallback)
        {
            existing = StripComment(values[fallback]);
            if (existing.Equals("ADDED", StringComparison.OrdinalIgnoreCase)) existing = "";
        }
        if (existing.Length > 0) return existing;
        if (values.Count <= 14 || values.Count <= 1) return null;

        var avatarType = StripComment(values[1]).ToLowerInvariant();
        if (avatarType.Length <= 4) return null;
        avatarType = avatarType[4..];
        var separator = avatarType.IndexOf('_');
        if (separator >= 0) avatarType = avatarType[..separator];
        var skin = StripComment(values[14]).ToLowerInvariant();
        if (avatarType.Length == 0 || skin.Length == 0) return null;
        var texturesByPrefix = textures.Files.Select(file => Path.GetFileNameWithoutExtension(file.Name).ToLowerInvariant()).ToArray();

        foreach (var name in appearances.Keys)
        {
            var candidate = name.ToLowerInvariant();
            if (candidate.Length < 5 || candidate[0] != category ||
                !char.IsDigit(candidate[1]) || !char.IsDigit(candidate[2]) || !char.IsDigit(candidate[3])) continue;
            var underscore = candidate.IndexOf('_');
            var candidateType = candidate[4..(underscore < 0 ? candidate.Length : underscore)];
            if (candidateType.EndsWith("lgt", StringComparison.Ordinal) || candidateType.EndsWith("med", StringComparison.Ordinal) ||
                candidateType.EndsWith("drk", StringComparison.Ordinal)) candidateType = candidateType[..^3];
            if (!candidateType.Equals(avatarType, StringComparison.Ordinal)) continue;
            var idEnd = candidate.IndexOf('_');
            if (idEnd < 0) idEnd = candidate.Length;
            var prefix = candidate[..idEnd] + skin;
            var texture = texturesByPrefix.FirstOrDefault(item => item.StartsWith(prefix, StringComparison.Ordinal));
            if (texture is not null) return $"{candidate},BODY={texture}";
        }
        return null;
    }

    internal string? ResolveSimCategorySuit(XPerson person, char categoryPrefix, int bodyStringIndex)
    {
        char lowerCategory = char.ToLowerInvariant(categoryPrefix);
        var values = ReadBodyStrings(person);
        if (ResolveCategorySuit(values, bodyStringIndex, lowerCategory) is { Length: > 0 } resolved) return resolved;
        var child = PersonAgeCategory.IsChild(person[PersonData.PersonAge]);
        var female = person[PersonData.Gender] != 0;
        var prefix = child ? (female ? "fc" : "mc") : (female ? "fa" : "ma");
        var skin = values is { Count: > 14 } ? values[14].Split(';')[0].Trim().ToLowerInvariant() : "lgt";
        if (skin.Length == 0) skin = "lgt";
        var texturesByPrefix = textures.Files.Select(file => Path.GetFileNameWithoutExtension(file.Name).ToLowerInvariant()).ToArray();
        foreach (var name in appearances.Keys)
        {
            var candidate = name.ToLowerInvariant();
            if (candidate.Length < 6 || candidate[0] != lowerCategory ||
                !char.IsDigit(candidate[1]) || !char.IsDigit(candidate[2]) || !char.IsDigit(candidate[3])) continue;
            if (!candidate[4..].StartsWith(prefix, StringComparison.Ordinal)) continue;
            var idEnd = candidate.IndexOf('_');
            var baseId = idEnd < 0 ? candidate : candidate[..idEnd];
            var texture = texturesByPrefix.FirstOrDefault(item => item.StartsWith(baseId + skin, StringComparison.Ordinal))
                ?? texturesByPrefix.FirstOrDefault(item => item.StartsWith(baseId, StringComparison.Ordinal));
            if (texture is not null) return $"{candidate},BODY={texture}";
        }
        return null;
    }

    private sealed record OutfitTemplate(
        string? BodyMesh,
        string? BodyTex,
        string? FallbackBodyMesh = null,
        string? FallbackBodyTex = null,
        string? HeadMesh = null,
        string? HeadTex = null,
        string? FallbackHeadMesh = null,
        string? FallbackHeadTex = null,
        string? HandTex = null,
        string? FallbackHandTex = null);

    private static OutfitTemplate? ResolveSpecialOutfitTemplate(int currentOutfit) => currentOutfit switch
    {
        19 => new("superstar$gaFit_movieactor1", "superstar$gaFit$c_movieactor1"),
        20 => new("superstar$gaFit_movieactor2", "superstar$gaFit$c_movieactor2"),
        21 => new("superstar$gaFit_movieactor3", "superstar$gaFit$c_movieactor3"),
        22 => new("Superstar$gAfit_Doctor", "Superstar$gAfit$c_Doctor"),
        23 => new("Superstar$gAfit_Relative", "Superstar$gAfit$c_Relative"),
        24 => new("Runway$gAfit_Coffee", "Runway$gAfit$c_Coffee"),
        25 => new("Runway$gAfit_Floral", "Runway$gAfit$c_Floral"),
        26 => new("Runway$gAfit_Architectural", "Runway$gAfit$c_Architectural"),
        >= 27 and <= 32 => RunwayTemplate(currentOutfit switch
        {
            27 => "Formal1",
            28 => "Formal2",
            29 => "Formal3",
            30 => "Lingerie1",
            31 => "Lingerie2",
            _ => "Lingerie3",
        }),
        33 => new("Superstar$gAfit_JumpSuit", "Superstar$gAfit$c_JumpSuit"),
        34 => new("Superstar$gAfit_WetSuit", "Superstar$gAfit$c_WetSuit"),
        35 => new("Superstar$gAFit_BackupDancerDance", "Superstar$gAFit$c_BackupDancerDance"),
        36 => new("Superstar$gAfit_BackupDancerPop", "Superstar$gAfit$c_BackupDancerPop"),
        37 => new("Superstar$gAfit_BackupDancerRock", "Superstar$gAfit$c_BackupDancerRock"),
        38 => new("MagicMAFat_BeeKeeper", "MagicMAFat_BeeKeeper", HandTex: "HUA$h_BeeKeeper"),
        39 => new("Magic$gAFit_BlueGenie", "BMagic$gAFit_BlueGenie",
            HeadMesh: "CMagic$gA_BlueGenie", HeadTex: "CMagic$gAFit_BlueGenie",
            FallbackHeadMesh: "CMagic$gAFit_BlueGenie", FallbackHeadTex: "CMagic$gA_BlueGenie",
            HandTex: "H$gA$h_BlueGenie"),
        40 => new("MagicMAFit_Minotaur", "BMagicMAFit_Minotaur",
            HeadMesh: "CMagicMAFit_Minotaur", HeadTex: "CMagicMAFit_Minotaur", HandTex: "HMA$h_Minotaur"),
        41 => new("Magic$gAFit_Spookshow", "Magic$gAFit$c_Spookshow"),
        42 => new("Magic$gAFit_SideShow", "Magic$gAFit$c_SideShow"),
        43 => new("MagicFAFit_Vampire", "MagicFAFit_Vampire",
            HeadMesh: "CMagicFAFit_Vampire", HeadTex: "CMagicFAFit_Vampire",
            FallbackHeadMesh: "CMagicFAFit_Vampire", FallbackHeadTex: "CMagicFA$c_Vampiress",
            HandTex: "HFA$h_Vampire", FallbackHandTex: "HUA$h_Vampiress"),
        44 => new("Magic$gAFit_Werewolf", "Magic$gAFit_Werewolf",
            HeadMesh: "CMagic$gAFit_Werewolf", HeadTex: "CMagic$gAFit_Werewolf", HandTex: "HMA$h_Werewolf"),
        45 => new("MagicMAFit_Headless", "MagicMAFit_Headless",
            HeadMesh: "CMagicMA_Headless", HeadTex: "CMagicMA_Headless", HandTex: "HUA$h_Headless"),
        46 => new("MagicMAFat_Troll", "MagicMAFat_Troll",
            HeadMesh: "CMagicMAFat_Troll", HeadTex: "CMagicMAFat_Troll", HandTex: "HUA$h_Troll"),
        47 => new("MagicMAFat_Hunchback", "MagicMAFat_Hunchback",
            HeadMesh: "CMagicMAFat_Hunchback", HeadTex: "CMagicMAFat_Hunchback", HandTex: "HUA$h_Hunchback"),
        48 => new("Magic$gAFit_Sorcerer", "Magic$gAFit_Sorcerer",
            HeadMesh: "CMagic$gAFit_Sorcerer", HeadTex: "CMagic$gAFit_Sorcerer", HandTex: "HMA$h_Sorcerer"),
        49 => new("MagicFAFit_Witch", "MagicFAFit_Witch",
            HeadMesh: "CMagicFAFit_Witch", HeadTex: "CMagicFAFit_Witch", HandTex: "HUA$h_Hunchback"),
        50 => new("MagicFAFat_Ogress", "BMagicFAFat_Ogress",
            HeadMesh: "CMagicFAFat_Ogress", HeadTex: "CMagicFAFat_Ogress", HandTex: "HFA$h_Ogress"),
        51 => new("MagicFASkn_Crone", "BMagicFASkn_Crone",
            HeadMesh: "CMagicFASkn_Crone", HeadTex: "CMagicFASkn_Crone", HandTex: "HFA$h_Crone"),
        52 => new("MagicFASkn_Nymph", "BMagicFASkn_Nymph",
            HeadMesh: "CMagicFASkn_Nymph", HeadTex: "CMagicFASkn_Nymph", HandTex: "HUA$h_Nymph"),
        53 => new("MagicMCChd_Goblin", "MagicMCChd_Goblin",
            HeadMesh: "CMagicMCChd_Goblin", HeadTex: "CMagicMCChd_Goblin", HandTex: "HUC$h_Goblin"),
        54 => new("MagicFCChd_WizardGirl", "MagicFCChd_WizardGirl",
            HeadMesh: "CMagicFC_WizardGirl", HeadTex: "CMagicFC_WizardGirl", HandTex: "HFC$h_WizardGirl"),
        57 => new(null, null, HeadMesh: "CMagicMAFat_Donkey", HeadTex: "CMagicMAFat_Donkey"),
        58 => new("MagicMASkn_Vampire", "MagicMASkn_Vampire",
            HeadMesh: "CMagicMASkn_Vampire", HeadTex: "CMagicMASkn_Vampire", HandTex: "HMA$h_Vampire"),
        59 => new("MagicMAFit_PrinceCharming", "MagicMAFitlgt_PrinceCharming"),
        60 => new("MagicMCChd_Skeleton", "MagicMCChd_Skeleton",
            HeadMesh: "CMagicMCChd_Skeleton", HeadTex: "CMagicMCChd_Skeleton", HandTex: "GUA$h_SkeletonChild"),
        _ => null,
    };

    private static OutfitTemplate RunwayTemplate(string name) =>
        new($"Runway$gA$b_{name}", $"Runway$gA$b$c_{name}", $"Runway$gAfit_{name}", $"Runway$gAfit$c_{name}");

    internal ((string, string) Body, (string, string) LeftHand, (string, string) RightHand, (string, string) Head) ResolveEffectivePartsForTest(
        XPerson person, ISimulationCareerHost? careerHost = null)
    {
        var character = person.PresentationCharacter ?? person.SavedCharacter;
        var effectiveParts = character is null
            ? Enumerable.Repeat(("NONE", ""), 5).ToArray()
            : character.Parts.Count >= 5
                ? character.Parts
                : character.Parts.Concat(Enumerable.Repeat(("NONE", ""), 5 - character.Parts.Count)).ToArray();
        return ResolveEffectiveParts(person, effectiveParts, careerHost);
    }

    private ((string, string) Body, (string, string) LeftHand, (string, string) RightHand, (string, string) Head) ResolveEffectiveParts(
        XPerson person, IReadOnlyList<(string, string)> parts, ISimulationCareerHost? careerHost = null)
    {
        var body = parts[0];
        var leftHand = parts[2];
        var rightHand = parts[3];
        var head = parts[4];

        var values = ReadBodyStrings(person);
        var objectEntry = person.TypeRecord is { } type ? registry.Find(unchecked((uint)type.Key)) : null;
        // VitaBoyFlags bit 0x8: single-suit actors index outfits directly in body strings.
        if (objectEntry is not null && (objectEntry.Definition[ObjdField.VitaBoyFlags] & 8) != 0)
        {
            if (IsUnsetPart(body.Item1))
            {
                var fallbackPetBody = BodyString(values, 1);
                if (fallbackPetBody.Length > 0 && !fallbackPetBody.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                    body = ParseSuitSpecification(fallbackPetBody);
            }
            var petOutfit = (int)person[PersonData.CurrentOutfit];
            if (person.PresentationCharacter is null && petOutfit > 0)
            {
                var petSuit = BodyString(values, petOutfit);
                if (petSuit.Length > 0 && !petSuit.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                    body = ParseSuitSpecification(petSuit);
            }
            return (body, leftHand, rightHand, head);
        }

        var defaultLeftHand = BodyString(values, 17);
        var defaultRightHand = BodyString(values, 18);
        if (person.PresentationCharacter is null)
        {
            if (IsUnsetPart(body.Item1))
            {
                var fallbackBody = BodyString(values, 1);
                if (fallbackBody.Length > 0) body = ParseSuitSpecification(fallbackBody);
            }
            if (IsUnsetPart(head.Item1))
            {
                var fallbackHead = BodyString(values, 2);
                if (fallbackHead.Length > 0) head = ParseSuitSpecification(fallbackHead);
            }
            // Restore idle hands from body strings 17-18 for gesture 0 in case saved state omitted them while carrying.
            if (defaultLeftHand.Length > 0)
                leftHand = ParseSuitSpecification(defaultLeftHand);
            if (defaultRightHand.Length > 0)
                rightHand = ParseSuitSpecification(defaultRightHand);
        }

        var currentOutfit = (person.AnimatorBodyStringMode & 6) != 0 ? 0 : (int)person[PersonData.CurrentOutfit];
        if (currentOutfit != 0 && (person.PresentationCharacter is null || currentOutfit is 1 or 2 or 4 or 5 or 17 or 18))
        {
            if (defaultLeftHand.Length > 0) leftHand = ParseSuitSpecification(defaultLeftHand);
            if (defaultRightHand.Length > 0) rightHand = ParseSuitSpecification(defaultRightHand);
        }

        var leftGesture = (int)person[PersonData.HandGestureLeft];
        var rightGesture = (int)person[PersonData.HandGestureRight];
        var leftHiddenByGesture3 = leftGesture == 3;
        var rightHiddenByGesture3 = rightGesture == 3;
        leftHand = leftGesture switch
        {
            1 => ResolveGesturePart(values, 19, leftHand),
            2 => ResolveGesturePart(values, 21, leftHand),
            3 => ("NONE", ""),
            4 => ResolveGesturePart(values, 25, leftHand),
            _ => leftHand,
        };
        rightHand = rightGesture switch
        {
            1 => ResolveGesturePart(values, 20, rightHand),
            2 => ResolveGesturePart(values, 22, rightHand),
            3 => ("NONE", ""),
            4 => ResolveGesturePart(values, 26, rightHand),
            _ => rightHand,
        };

        var genderString = BodyString(values, 12);
        var isFemale = genderString.Equals("female", StringComparison.OrdinalIgnoreCase)
            ? true
            : genderString.Equals("male", StringComparison.OrdinalIgnoreCase)
                ? false
                : (person[PersonData.Gender] & 1) != 0;
        var age = int.TryParse(BodyString(values, 13), NumberStyles.Integer, CultureInfo.InvariantCulture, out var parsedAge)
            ? parsedAge
            : (int)person[PersonData.PersonAge];
        var isChild = age is > 0 and < 18;
        var rawSkin = BodyString(values, 14).ToLowerInvariant();
        var skin = rawSkin is "lgt" or "med" or "drk"
            ? rawSkin
            : person[PersonData.SkinColor] switch
            {
                2 => "drk",
                3 => "med",
                _ => "lgt",
            };
        var bodySourceName = BodyString(values, 1);
        if (bodySourceName.Length == 0) bodySourceName = body.Item1;
        var bodyFit = InferBodyFit(bodySourceName);

        if (currentOutfit != 0)
        {
            switch (currentOutfit)
            {
                case 1:
                    if (ResolveCategorySuit(values, 15, 'f') is { } formal && formal.Length > 0)
                        body = ParseSuitSpecification(formal);
                    break;
                case 2:
                    if (ResolveCategorySuit(values, 31, 's', fallbackIndex: 16) is { } swim && swim.Length > 0)
                        body = ParseSuitSpecification(swim);
                    break;
                case 3:
                {
                    var careerLevel = isChild ? (short)0 : person[PersonData.JobPromotionLevel];
                    if (careerHost is not null && careerHost.TryGetCareerUniform(
                        person[PersonData.JobType], careerLevel, isFemale,
                        out var careerMesh, out var careerSkin))
                    {
                        var tex = string.IsNullOrWhiteSpace(careerSkin) ? careerMesh : careerSkin;
                        if (!string.IsNullOrWhiteSpace(careerMesh) &&
                            !careerMesh.Equals("none", StringComparison.OrdinalIgnoreCase))
                        {
                            ApplyBody(careerMesh, tex);
                        }
                        else if (!string.IsNullOrWhiteSpace(tex) &&
                            !tex.Equals("none", StringComparison.OrdinalIgnoreCase))
                        {
                            ApplyBody(tex, tex);
                        }
                    }
                    break;
                }
                case 4:
                {
                    var nudeBody = BodyString(values, 27);
                    var nudeLeft = BodyString(values, 28);
                    var nudeRight = BodyString(values, 29);
                    var nudeOverride = BodyString(values, 30);
                    if (isChild)
                    {
                        if (nudeBody.Length > 0 && !nudeBody.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                            body = ParseSuitSpecification(nudeBody);
                    }
                    else if (nudeOverride.Length > 0 && !nudeOverride.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                    {
                        body = ParseSuitSpecification(nudeOverride);
                    }
                    else
                    {
                        if (nudeBody.Length > 0 && !nudeBody.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                            body = ParseSuitSpecification(nudeBody);
                        if (!leftHiddenByGesture3 && nudeLeft.Length > 0 && !nudeLeft.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                            leftHand = ParseSuitSpecification(nudeLeft);
                        if (!rightHiddenByGesture3 && nudeRight.Length > 0 && !nudeRight.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                            rightHand = ParseSuitSpecification(nudeRight);
                    }
                    break;
                }
                case 5:
                {
                    var explicitPajama = BodyString(values, 32);
                    if (explicitPajama.Length > 0 && !explicitPajama.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                    {
                        body = ParseSuitSpecification(explicitPajama);
                    }
                    else if (!(isChild
                        ? (ApplyBody("pjs$gchd", "pajama$g$c") || ApplyBody("pjs$gchd", "pjs$g$c"))
                        : ApplyBody("pajama$g$b", "pajama$g$c")))
                    {
                        if (ResolveCategorySuit(values, 32, 'l') is { } pajamas && pajamas.Length > 0)
                            body = ParseSuitSpecification(pajamas);
                    }
                    break;
                }
                case 6:
                case 7:
                {
                    var neg = currentOutfit == 7;
                    ApplyBody(isChild ? "skeletonchd_01" : "skeleton_01", neg ? "skeleneg_01" : "skeleton_01");
                    ApplyHead(isChild ? "c_kidskull" : "c_skeleton", neg ? "c_skeleneg" : "c_skeleton");
                    ApplyHands(neg ? "_GUAO_sneg" : "_GUAO_skel");
                    break;
                }
                case >= 8 and <= 16:
                {
                    var style = currentOutfit switch
                    {
                        8 => "toga",
                        9 => "cow",
                        10 => "luau",
                        11 => "rave",
                        12 => "cost",
                        13 => "nice",
                        14 => "swim",
                        15 => "pj",
                        _ => "disco",
                    };
                    var ageCode = isChild ? "c" : "afit";
                    var variant = Math.Clamp((int)person[PersonData.CostumeTrunkOffsetHouseParty], 0, isChild ? 1 : 9) + 1;
                    if (!ApplyBody($"ct-{style}-$g{ageCode}-{variant:D2}", $"ct-{style}-$g{ageCode}$c-{variant:D2}") && variant != 1)
                        ApplyBody($"ct-{style}-$g{ageCode}-01", $"ct-{style}-$g{ageCode}$c-01");
                    break;
                }
                case 17:
                    if (ResolveCategorySuit(values, 33, 'w') is { } winter && winter.Length > 0)
                        body = ParseSuitSpecification(winter);
                    break;
                case 18:
                    if (ResolveCategorySuit(values, 34, 'h') is { } highFashion && highFashion.Length > 0)
                        body = ParseSuitSpecification(highFashion);
                    break;
                case 55:
                case 56:
                {
                    var stage = currentOutfit == 56 ? (int)person[PersonData.CostumeTrunkOffsetHouseParty] : 0;
                    var stageMesh = stage switch
                    {
                        1 => "MagicMAFit_MummyTorso",
                        2 => "MagicMAFit_MummyLegs",
                        3 => "MagicMAFit_MummyArms",
                        _ => "MagicMAFit_MummyFull",
                    };
                    if (!ApplyBody(stageMesh, "MagicMAFit_Mummy") && stage != 0)
                        ApplyBody("MagicMAFit_MummyFull", "MagicMAFit_Mummy");
                    ApplyHands("HUA$h_Mummy");
                    ApplyHead("CMagicMA_Mummy", "CMagicMA_Mummy");
                    break;
                }
                default:
                    if (ResolveSpecialOutfitTemplate(currentOutfit) is { } spec)
                    {
                        if (spec.BodyMesh is not null &&
                            !ApplyBody(spec.BodyMesh, spec.BodyTex ?? spec.BodyMesh) &&
                            spec.FallbackBodyMesh is not null)
                            ApplyBody(spec.FallbackBodyMesh, spec.FallbackBodyTex ?? spec.FallbackBodyMesh);
                        if (spec.HeadMesh is not null &&
                            !ApplyHead(spec.HeadMesh, spec.HeadTex ?? spec.HeadMesh) &&
                            spec.FallbackHeadMesh is not null)
                            ApplyHead(spec.FallbackHeadMesh, spec.FallbackHeadTex ?? spec.FallbackHeadMesh);
                        if (spec.HandTex is not null)
                            ApplyHands(spec.HandTex, spec.FallbackHandTex);
                    }
                    break;
            }
        }

        if (IsUnsetPart(body.Item1))
        {
            var fallbackBody = BodyString(values, 1);
            if (fallbackBody.Length > 0 && !fallbackBody.Equals("ADDED", StringComparison.OrdinalIgnoreCase))
                body = ParseSuitSpecification(fallbackBody);
        }

        return (body, leftHand, rightHand, head);

        bool ApplyBody(string meshTemplate, string texTemplate)
        {
            var apr = ResolveSuitAppearance(meshTemplate);
            if (apr is null) return false;
            var tex = ResolveSuitTexture(texTemplate) ?? ResolveSuitTexture(meshTemplate);
            body = (apr, tex is not null ? "BODY=" + tex : "");
            return true;
        }

        bool ApplyHead(string meshTemplate, string texTemplate)
        {
            var apr = ResolveSuitAppearance(meshTemplate);
            if (apr is null) return false;
            var tex = ResolveSuitTexture(texTemplate) ?? ResolveSuitTexture(meshTemplate);
            head = (apr, tex is not null ? "HEAD=" + tex : "");
            return true;
        }

        void ApplyHands(string template, string? fallbackTemplate = null)
        {
            leftHand = ApplyHandTemplate(leftHand, leftGesture, leftHiddenByGesture3, template, fallbackTemplate);
            rightHand = ApplyHandTemplate(rightHand, rightGesture, rightHiddenByGesture3, template, fallbackTemplate);
        }

        (string, string) ApplyHandTemplate((string, string) handPair, int gesture, bool hiddenByGesture3,
            string template, string? fallbackTemplate)
        {
            if (hiddenByGesture3 || IsUnsetPart(handPair.Item1)) return handPair;
            var pose = ResolveHandPoseChar(gesture, handPair.Item1);
            var tex = ResolveSuitTexture(ExpandSuitTemplate(template, isFemale, isChild, bodyFit, skin, pose));
            if (tex is null && fallbackTemplate is not null)
                tex = ResolveSuitTexture(ExpandSuitTemplate(fallbackTemplate, isFemale, isChild, bodyFit, skin, pose));
            return tex is not null ? (handPair.Item1, "HAND=" + tex) : handPair;
        }

        string? ResolveSuitAppearance(string template)
        {
            var expanded = ExpandSuitTemplate(template, isFemale, isChild, bodyFit, skin, 'O');
            var normalized = NormalizeAppearance(expanded);
            if (appearances.ContainsKey(normalized))
                return normalized.EndsWith(".apr", StringComparison.OrdinalIgnoreCase) ? normalized : normalized + ".apr";
            var stemQuery = expanded.EndsWith(".apr", StringComparison.OrdinalIgnoreCase) ? expanded[..^4] : expanded;
            if (stemQuery.Length == 0) return null;
            foreach (var key in appearances.Keys)
            {
                if (key.Contains(stemQuery, StringComparison.OrdinalIgnoreCase))
                {
                    var matched = NormalizeAppearance(key);
                    return matched.EndsWith(".apr", StringComparison.OrdinalIgnoreCase) ? matched : matched + ".apr";
                }
            }
            return null;
        }

        string? ResolveSuitTexture(string template)
        {
            var expanded = ExpandSuitTemplate(template, isFemale, isChild, bodyFit, skin, 'O');
            if (expanded.EndsWith(".bmp", StringComparison.OrdinalIgnoreCase)) expanded = expanded[..^4];
            textureStemByLower ??= BuildTextureStemMap();
            if (textureStemByLower.TryGetValue(expanded.ToLowerInvariant(), out var resolved))
                return resolved;
            if (expanded.Length == 0) return null;
            foreach (var stem in textureStemByLower.Values)
            {
                if (stem.Contains(expanded, StringComparison.OrdinalIgnoreCase))
                    return stem;
            }
            return null;
        }

        static char ResolveHandPoseChar(int gesture, string appearanceName)
        {
            if (gesture == 1) return 'P';
            if (gesture == 2) return 'C';
            var normalized = NormalizeAppearance(appearanceName);
            if (normalized.EndsWith(".apr", StringComparison.Ordinal)) normalized = normalized[..^4];
            if (normalized.Length > 0)
            {
                var last = char.ToUpperInvariant(normalized[^1]);
                if (last is 'O' or 'P' or 'C') return last;
            }
            return 'O';
        }

        static string InferBodyFit(string source)
        {
            var comma = source.IndexOf(',');
            var stem = (comma >= 0 ? source[..comma] : source).Trim();
            var underscore = stem.IndexOf('_');
            if (underscore >= 0) stem = stem[..underscore];
            if (stem.EndsWith("fat", StringComparison.OrdinalIgnoreCase)) return "fat";
            if (stem.EndsWith("skn", StringComparison.OrdinalIgnoreCase)) return "skn";
            return "fit";
        }

        static string ExpandSuitTemplate(string template, bool female, bool child, string fit, string simSkin, char handPose)
        {
            if (!template.Contains('$')) return template;
            var g = female ? "f" : "m";
            var a = child ? "c" : "a";
            var h = handPose.ToString();
            var sb = new System.Text.StringBuilder(template.Length + 8);
            for (var i = 0; i < template.Length; i++)
            {
                if (template[i] == '$' && i + 1 < template.Length)
                {
                    switch (char.ToLowerInvariant(template[i + 1]))
                    {
                        case 'g': sb.Append(g); i++; continue;
                        case 'a': sb.Append(a); i++; continue;
                        case 'b': sb.Append(fit); i++; continue;
                        case 'c': sb.Append(simSkin); i++; continue;
                        case 'h': sb.Append(h); i++; continue;
                    }
                }
                sb.Append(template[i]);
            }
            return sb.ToString();
        }

        static bool IsUnsetPart(string name) =>
            string.IsNullOrWhiteSpace(name) || name.Trim().Equals("NONE", StringComparison.OrdinalIgnoreCase);

        static string BodyString(IReadOnlyList<string>? table, int index)
        {
            if (table is null || table.Count <= index) return "";
            var raw = table[index];
            var semicolon = raw.IndexOf(';');
            return (semicolon >= 0 ? raw[..semicolon] : raw).Trim();
        }

        static (string, string) ResolveGesturePart(IReadOnlyList<string>? table, int index, (string, string) fallback)
        {
            var raw = BodyString(table, index);
            return raw.Length > 0 ? ParseSuitSpecification(raw) : fallback;
        }

        static (string, string) ParseSuitSpecification(string specification)
        {
            var comma = specification.IndexOf(',');
            var appearance = (comma >= 0 ? specification[..comma] : specification).Trim();
            if (!appearance.Equals("NONE", StringComparison.OrdinalIgnoreCase) &&
                !appearance.EndsWith(".apr", StringComparison.OrdinalIgnoreCase))
                appearance += ".apr";
            var binding = comma >= 0 ? specification[(comma + 1)..].Trim() : "";
            return (appearance, binding);
        }
    }

    private Dictionary<string, string> BuildTextureStemMap()
    {
        var map = new Dictionary<string, string>(textures.Files.Count, StringComparer.OrdinalIgnoreCase);
        foreach (var file in textures.Files)
        {
            var stem = Path.GetFileNameWithoutExtension(file.Name);
            if (stem.Length > 0) map.TryAdd(stem.ToLowerInvariant(), stem);
        }
        return map;
    }

    internal Vector3? HeadPosition(XPerson person) => TryStateFor(person)?.HeadPosition;

    internal Vector3? HeadAttachmentPosition(XPerson person) => TryStateFor(person)?.HeadAttachmentPosition;

    internal Vector3? HandPosition(XPerson person) => TryStateFor(person)?.HandPosition;

    internal Vector3? LeftHandPosition(XPerson person) => TryStateFor(person)?.LeftHandPosition;

    internal Vector3? PelvisPosition(XPerson person) => TryStateFor(person)?.PelvisPosition;

    internal Vector3? SlotAttachmentPosition(XPerson person, int hierarchySlot) => hierarchySlot switch
    {
        1 or 5 => HandPosition(person),
        2 => HeadPosition(person),
        3 => PelvisPosition(person) ?? LeftHandPosition(person),
        4 => HeadAttachmentPosition(person),
        _ => null,
    };

    internal CensorBounds? Censor(XPerson person) => TryStateFor(person)?.Censor;

    private IReadOnlyList<string>? ReadBodyStrings(XPerson person)
    {
        var objectEntry = person.TypeRecord is { } type ? registry.Find(unchecked((uint)type.Key)) : null;
        var stringsId = objectEntry?.Definition[ObjdField.BodyStringsId] ?? 0;
        if (stringsId == 0) return null;
        var key = (objectEntry!.File, stringsId);
        if (bodyStringsCache.TryGetValue(key, out var cached)) return cached;
        var bodyChunk = objectEntry.File.Find(ResourceType.Str, stringsId);
        if (bodyChunk is null) return null;
        var parsed = StringTable.Read(objectEntry.File, bodyChunk).ForLanguage(1);
        bodyStringsCache[key] = parsed;
        return parsed;
    }

    internal Vector3? HeadSeekRegistration(XPerson person) => TryStateFor(person)?.HeadSeekRegistration;

    internal Vector3? HeadFakeRegistration(XPerson person) => TryStateFor(person)?.HeadFakeRegistration;

    internal void ClearHeadSeekRegistrations(XPerson person)
    {
        if (TryStateFor(person) is { } state)
        {
            state.HeadSeekRegistration = null;
            state.HeadFakeRegistration = null;
        }
        person.AnimatorHeadSeekRegistrationsAvailable = false;
    }

    private void CacheHeadSeekRegistrations(XPerson person, IReadOnlyList<BonePose> pose, SkeletonInfo skeletonInfo,
        IReadOnlyList<string>? values, Matrix4x4 rootTransform)
    {
        ClearHeadSeekRegistrations(person);
        if (values is null || values.Count <= 4) return;

        var state = StateFor(person);
        var actor = Registration(values[3], values[4]);
        state.HeadSeekRegistration = actor;
        var headFake = Registration(values[3], "HeadFake");
        state.HeadFakeRegistration = headFake;
        person.AnimatorHeadSeekRegistrationsAvailable = actor.HasValue && headFake.HasValue;

        Vector3? Registration(string boneName, string? suffix)
        {
            if (!skeletonInfo.IndexByNameOrdinal.TryGetValue(boneName, out var boneIdx)) return null;
            var position = Pose.RegistrationTranslation(pose[boneIdx], suffix);
            return Vector3.Transform(position, rootTransform);
        }
    }

    internal List<PosedHeadMesh> BuildHeadMeshes(XPerson person, int level, int cameraOrientation,
        Func<float, float, float> elevation, LotCamera camera)
    {
        var state = StateFor(person);
        var head = state.HeadPosition;
        var headAttachment = state.HeadAttachmentPosition;
        var hand = state.HandPosition;
        var leftHand = state.LeftHandPosition;
        var pelvis = state.PelvisPosition;
        var root = state.AvatarRootPosition;
        var direction = state.AvatarRootDirection;
        var headSeek = state.HeadSeekRegistration;
        var headFake = state.HeadFakeRegistration;
        var hadHeadSeekRegistrationsAvailable = person.AnimatorHeadSeekRegistrationsAvailable;
        try
        {
            var meshes = new List<PosedHeadMesh>();
            Build(person, level, cameraOrientation, elevation, camera, meshes);
            return meshes;
        }
        finally
        {
            state.HeadPosition = head;
            state.HeadAttachmentPosition = headAttachment;
            state.HandPosition = hand;
            state.LeftHandPosition = leftHand;
            state.PelvisPosition = pelvis;
            state.AvatarRootPosition = root;
            state.AvatarRootDirection = direction;
            state.HeadSeekRegistration = headSeek;
            state.HeadFakeRegistration = headFake;
            person.AnimatorHeadSeekRegistrationsAvailable = hadHeadSeekRegistrationsAvailable;
        }
    }

    internal float? RootDirection(XPerson person) => TryStateFor(person)?.AvatarRootDirection;

    internal Vector3 RootPosition(XPerson person) => TryStateFor(person)?.AvatarRootPosition is { } position
        ? position
        : throw new InvalidOperationException($"Sim {person.Id} avatar root position was not prepared");

    private IReadOnlyList<BonePose> AnimationPose(XPerson person, Skeleton skeleton, float subTickAlpha = 0f)
    {
        var pose = Pose.BindPose(skeleton);
        foreach (var practice in person.GetAnimationPracticeApplicationOrder()) pose = Sample(practice, pose);
        return pose;

        IReadOnlyList<BonePose> Sample(AvatarAnimationPlayback playback, IReadOnlyList<BonePose> basis)
        {
            if (ResolveAnimation(playback.Clip.Name) is not { } source)
                throw new InvalidDataException($"Sim {person.Id} is playing {playback.Clip.Name}, but its original animation curves are not installed");

            var sampleFrame = playback.Frame;
            if (subTickAlpha > 0f && !playback.EndReached && playback.InterpolatePose &&
                playback.Clip.DurationMilliseconds > 0f && playback.Clip.FrameCount > 0)
            {
                var frameCount = (float)playback.Clip.FrameCount;
                sampleFrame += (subTickAlpha * 42f * playback.PracticeScale / playback.Clip.DurationMilliseconds) * frameCount;
                if (playback.Loop)
                {
                    sampleFrame %= frameCount;
                    if (sampleFrame < 0f) sampleFrame += frameCount;
                }
                else
                {
                    sampleFrame = Math.Clamp(sampleFrame, 0f, Math.Max(0f, frameCount - 1f));
                }
            }
            var weight = playback.EvaluatePracticeWeight(person.AnimatorMilliseconds, subTickAlpha);
            return Pose.Sample(skeleton, source.Animation, source.Curves, sampleFrame, basis, weight,
                playback.Loop, playback.InterpolatePose, playback.AllowUnblendedOverride);
        }
    }

    internal Vector3? ResolveAnchorBoneAvatarPosition(XPerson person, string boneName)
    {
        lock (_instanceLock)
        {
            return ResolveAnchorBoneAvatarPositionCore(person, boneName);
        }
    }

    private Vector3? ResolveAnchorBoneAvatarPositionCore(XPerson person, string boneName)
    {
        if (string.IsNullOrWhiteSpace(boneName) ||
            (person.PresentationCharacter ?? person.SavedCharacter) is not { } character)
            return null;
        if (person.AnimationPlayback is { } primary && ResolveAnimation(primary.Clip.Name) is null)
            return null;

        var effectiveParts = character.Parts.Count >= 5
            ? character.Parts
            : character.Parts.Concat(Enumerable.Repeat(("NONE", ""), 5 - character.Parts.Count)).ToArray();

        var (bodyPair, leftHandPair, rightHandPair, headPair) = ResolveEffectiveParts(person, effectiveParts);
        var bodyName = NormalizeAppearance(bodyPair.Item1);
        var body = ResolveAppearance(bodyName);
        if (body is null)
        {
            var fallbackBody = BodyFallbackByMarker(PersonFallbackMarker(person));
            body = fallbackBody is null ? null : appearances.GetValueOrDefault(fallbackBody);
            if (body is null) return null;
        }

        try
        {
            var coreNames = new[] { leftHandPair.Item1, rightHandPair.Item1, headPair.Item1 }
                .Where(name => !string.IsNullOrWhiteSpace(name) && !name.Equals("NONE", StringComparison.OrdinalIgnoreCase));
            var sourceList = new List<AppearanceSource> { body };
            foreach (var name in coreNames)
            {
                var normalized = NormalizeAppearance(name);
                var source = ResolveAppearance(normalized);
                if (source is not null) sourceList.Add(source);
            }
            var requiredBones = new HashSet<string>(StringComparer.Ordinal);
            foreach (var source in sourceList)
            {
                foreach (var binding in source.Appearance.Bindings)
                {
                    try { requiredBones.UnionWith(ReadMesh(source.Path, binding.Mesh).Bones); }
                    catch (InvalidDataException) { }
                }
            }
            var skeleton = SelectSkeleton(body, requiredBones, person);
            var skeletonInfo = GetSkeletonInfo(skeleton);
            if (!skeletonInfo.IndexByNameIgnoreCase.TryGetValue(boneName, out var boneIndex))
                return null;

            var pose = Pose.BindPose(skeleton);
            foreach (var practice in person.GetAnimationPracticeApplicationOrder())
            {
                if (ResolveAnimation(practice.Clip.Name) is not { } animSource)
                    continue;
                var weight = practice.EvaluatePracticeWeight(person.AnimatorMilliseconds);
                pose = Pose.Sample(skeleton, animSource.Animation, animSource.Curves, practice.Frame, pose,
                    weight, practice.Loop, practice.InterpolatePose, practice.AllowUnblendedOverride);
            }
            return pose[boneIndex].WorldTranslation;
        }
        catch (InvalidDataException)
        {
            return null;
        }

        AppearanceSource? ResolveAppearance(string name)
        {
            if (string.IsNullOrWhiteSpace(name) || name.Equals("NONE", StringComparison.OrdinalIgnoreCase))
                return null;
            var source = appearances.GetValueOrDefault(name);
            if (source is not null) return source;
            if (name.StartsWith('b'))
                return BodyFallback(name) is { } bodyFallback ? appearances.GetValueOrDefault(bodyFallback) : null;
            return name.StartsWith('c') ? HeadFallback(name) : null;
        }
    }

    internal (float MarkerOneStride, float MarkerTwoStride)? LocomotionStrides(XPerson person, string animationName)
    {
        lock (_instanceLock)
        {
            return LocomotionStridesCore(person, animationName);
        }
    }

    private (float MarkerOneStride, float MarkerTwoStride)? LocomotionStridesCore(XPerson person, string animationName)
    {
        if ((person.PresentationCharacter ?? person.SavedCharacter) is not { Parts.Count: 5 } character ||
            ResolveAnimation(animationName) is not { } animationSource)
            return null;

        var (bodyPair, leftHandPair, rightHandPair, headPair) = ResolveEffectiveParts(person, character.Parts);
        var bodyName = NormalizeAppearance(bodyPair.Item1);
        var body = ResolveAppearance(bodyName);
        if (body is null) return null;

        try
        {
            var coreNames = new[] { leftHandPair.Item1, rightHandPair.Item1, headPair.Item1 }
                .Where(name => !string.IsNullOrWhiteSpace(name) && !name.Equals("NONE", StringComparison.OrdinalIgnoreCase));
            var sourceList = new List<AppearanceSource> { body };
            foreach (var name in coreNames)
            {
                var normalized = NormalizeAppearance(name);
                var source = ResolveAppearance(normalized);
                if (source is null && !normalized.StartsWith('h')) return null;
                if (source is not null) sourceList.Add(source);
            }
            var requiredBones = new HashSet<string>(StringComparer.Ordinal);
            foreach (var source in sourceList)
                foreach (var binding in source.Appearance.Bindings)
                    requiredBones.UnionWith(ReadMesh(source.Path, binding.Mesh).Bones);
            var skeleton = SelectSkeleton(body, requiredBones, person);
            var gameSkeleton = skeleton;
            var markerOne = LocomotionMarker(animationSource.Animation, "1");
            var markerTwo = LocomotionMarker(animationSource.Animation, "2");
            if (markerOne is not { Bone.Length: > 0 } || markerTwo is not { Bone.Length: > 0 }) return null;
            var frameCount = animationSource.Animation.PlaybackFrameCount;
            if (frameCount <= 0) return null;
            return Pose.LocomotionStrides(gameSkeleton, animationSource.Animation, animationSource.Curves,
                markerOne.Value.NormalizedTime * frameCount, markerOne.Value.Bone,
                markerTwo.Value.NormalizedTime * frameCount, markerTwo.Value.Bone);
        }
        catch (InvalidDataException)
        {
            return null;
        }

        static AvatarAnimationMarker? LocomotionMarker(Animation animation, string value) =>
            animation.FindTagTime("anchor", value) is { } tag
                ? new AvatarAnimationMarker(tag.Time / animation.Floats[0], tag.Bone)
                : null;

        AppearanceSource? ResolveAppearance(string name)
        {
            var source = appearances.GetValueOrDefault(name);
            if (source is not null) return source;
            if (name.StartsWith('b'))
                return BodyFallback(name) is { } bodyFallback ? appearances.GetValueOrDefault(bodyFallback) : null;
            return name.StartsWith('c') ? HeadFallback(name) : null;
        }
    }

    private AnimationSource? ResolveAnimation(string name)
    {
        if (animations.TryGetValue(name, out var cached)) return cached;
        var curvesIndex = curveFiles ?? sharedIndex.CurveFiles;
        if (sharedIndex.AnimationsByName.TryGetValue(name, out var animationCandidates))
        {
            for (var i = 0; i < animationCandidates.Count; i++)
            {
                var animation = animationCandidates[i];
                if (!curvesIndex.TryGetValue(animation.CurveName + ".cfp", out var candidates)) continue;
                for (var c = 0; c < candidates.Length; c++)
                {
                    var candidate = candidates[c];
                    try
                    {
                        var curves = AnimationCurveFile.Read(candidate.Read(), candidate.Source + ":" + candidate.Name,
                            animation.TranslationCount, animation.RotationCount);
                        return animations[name] = new AnimationSource(animation, curves);
                    }
                    catch (ResourceFormatException) { }
                }
            }
        }
        animations[name] = null;
        return null;
    }

    private string? BodyFallback(string name) => BodyFallbackByMarker(Category(name));

    private string? BodyFallbackByMarker(string marker)
    {
        var common = marker switch
        {
            "ma" => "b007mafit_01",
            "fa" => "b010fafit_01",
            _ => null,
        };
        if (common is not null && appearances.ContainsKey(common)) return common;
        return appearances.Values.FirstOrDefault(source => source.Appearance.Name.StartsWith('b') &&
            source.Appearance.Name.Length > 5 && Category(source.Appearance.Name) == marker &&
            source.Appearance.Bindings.Any(binding => binding.Mesh.Contains("BODY", StringComparison.OrdinalIgnoreCase)))?.Appearance.Name
            ?? appearances.Values.FirstOrDefault(source => source.Appearance.Name.StartsWith('b') &&
                source.Appearance.Bindings.Any(binding => binding.Mesh.Contains("BODY", StringComparison.OrdinalIgnoreCase)))?.Appearance.Name;
    }

    private AppearanceSource? HeadFallback(string name) => HeadFallbackByMarker(Category(name));

    private AppearanceSource? HeadFallbackByMarker(string marker) =>
        appearances.Values.FirstOrDefault(source => source.Appearance.Name.StartsWith('c') &&
            source.Appearance.Name.Length > 5 && Category(source.Appearance.Name) == marker &&
            source.Appearance.Bindings.Any(binding => binding.Mesh.Contains("HEAD-HEAD", StringComparison.OrdinalIgnoreCase)))
        ?? appearances.Values.FirstOrDefault(source => source.Appearance.Name.StartsWith('c') &&
            source.Appearance.Bindings.Any(binding => binding.Mesh.Contains("HEAD-HEAD", StringComparison.OrdinalIgnoreCase)));

    private static string PersonFallbackMarker(XPerson person)
    {
        if (person.AnimatorBodyStringMode is 2 or 3) return "dg";
        if (person.AnimatorBodyStringMode is 4 or 5) return "ct";
        var isChild = PersonAgeCategory.IsChild(person[PersonData.PersonAge]);
        var isFemale = person[PersonData.Gender] == 1;
        return (isChild, isFemale) switch
        {
            (true, true) => "fc",
            (true, false) => "mc",
            (false, true) => "fa",
            _ => "ma",
        };
    }

    private static string Category(string name) => name.Length >= 6 ? name.Substring(4, 2).ToLowerInvariant() : "";

    private Skeleton SelectSkeleton(AppearanceSource body, HashSet<string> requiredBones, XPerson person)
    {
        var bodyAppearanceCategory = Category(body.Appearance.Name);
        var isChildAppearance = bodyAppearanceCategory is "mc" or "fc" or "uc" ||
            body.Appearance.Name.Contains("Chd_", StringComparison.OrdinalIgnoreCase);
        var bodyStrings = ReadBodyStrings(person);
        var bodySkeleton = bodyStrings is { Count: > 0 } ? bodyStrings[0].Trim() : "";
        var preferred = PersonAgeCategory.IsChild(person[PersonData.PersonAge]) || isChildAppearance
            ? "child"
            : !string.IsNullOrWhiteSpace(bodySkeleton)
                ? bodySkeleton
                : person.AnimatorBodyStringMode is 2 or 3
                    ? "dog"
                    : person.AnimatorBodyStringMode is 4 or 5
                        ? "cat"
                        : "adult";
        Skeleton? bestSkeleton = null;
        var bestPreferred = false;
        var bestCoverage = -1;
        HashSet<string>? seenBodySignatures = body.Data.Skeletons.Count > 0
            ? new HashSet<string>(body.Data.Skeletons.Count, StringComparer.Ordinal)
            : null;
        for (var i = 0; i < body.Data.Skeletons.Count; i++)
        {
            var info = GetSkeletonInfo(body.Data.Skeletons[i]);
            if (!seenBodySignatures!.Add(info.Signature)) continue;
            EvaluateCandidate(info);
        }
        for (var i = 0; i < uniqueSkeletons.Count; i++)
        {
            var info = uniqueSkeletons[i];
            if (seenBodySignatures is not null && seenBodySignatures.Contains(info.Signature)) continue;
            EvaluateCandidate(info);
        }
        return bestSkeleton
            ?? throw new InvalidDataException($"No installed avatar skeleton covers Sim {person.Id}'s saved mesh bones");

        void EvaluateCandidate(SkeletonInfo info)
        {
            if (!info.BoneSet.IsSupersetOf(requiredBones)) return;
            var isPreferred = info.Skeleton.Name.Equals(preferred, StringComparison.OrdinalIgnoreCase);
            if (bestSkeleton is not null && bestPreferred && !isPreferred) return;
            var coverage = 0;
            var bones = info.Skeleton.Bones;
            for (var b = 0; b < bones.Count; b++)
                if (requiredBones.Contains(bones[b].Name)) coverage++;
            if (bestSkeleton is null || (isPreferred && !bestPreferred) || coverage > bestCoverage)
            {
                bestSkeleton = info.Skeleton;
                bestPreferred = isPreferred;
                bestCoverage = coverage;
            }
        }
    }

    private Mesh ReadMesh(CharacterSearchPath path, string name)
    {
        CharacterFile resource;
        try
        {
            resource = Find(path, name, ".skn", ".bmf");
        }
        catch (InvalidDataException)
        {
            animationPath ??= CharacterSearchPath.Animation(gameRoot, registry);
            var fallbackPath = ReferenceEquals(path, skins) ? animationPath : skins;
            resource = Find(fallbackPath, name, ".skn", ".bmf");
        }
        if (meshes.TryGetValue(resource.Source, out var cached)) return cached;
        var bytes = resource.Read();
        var parsed = resource.Extension.Equals(".skn", StringComparison.OrdinalIgnoreCase)
            ? Mesh.ReadText(bytes, resource.Source)
            : Mesh.ReadBinary(bytes, resource.Source);
        meshes.Add(resource.Source, parsed);
        return parsed;
    }

    private static TextureSource CreateSolidWhiteTexture()
    {
        var bytes = new byte[4 * 4 * 4];
        Array.Fill(bytes, (byte)255);
        return new TextureSource(bytes, Convert.ToHexString(SHA1.HashData(bytes), 0, 6), "rgba", 4, 4, "__white_fallback");
    }

    private TextureSource ReadTexture(string? name)
    {
        if (string.IsNullOrWhiteSpace(name)) throw new InvalidDataException("Saved avatar binding has no texture name");
        var resource = Find(textures, name, ".bmp", ".tga");
        if (textureCache.TryGetValue(resource.Source, out var cached)) return cached;
        var bytes = resource.Read().ToArray();
        int width, height;
        if (resource.Extension.Equals(".bmp", StringComparison.OrdinalIgnoreCase) && bytes.Length >= 54 && bytes[0] == 'B' && bytes[1] == 'M')
        {
            width = BitConverter.ToInt32(bytes, 18);
            height = Math.Abs(BitConverter.ToInt32(bytes, 22));
        }
        else if (resource.Extension.Equals(".tga", StringComparison.OrdinalIgnoreCase) && bytes.Length >= 18)
        {
            width = BitConverter.ToUInt16(bytes, 12);
            height = BitConverter.ToUInt16(bytes, 14);
        }
        else throw new InvalidDataException($"Avatar texture {name} is not a readable BMP or TGA");
        if (width is < 1 or > 4096 || height is < 1 or > 4096) throw new InvalidDataException($"Avatar texture {name} has invalid dimensions");
        var result = new TextureSource(bytes, Convert.ToHexString(SHA1.HashData(bytes), 0, 6), resource.Extension[1..].ToLowerInvariant(), width, height, resource.Name);
        textureCache.Add(resource.Source, result);
        return result;
    }

    // indicatorKind: 1 = selected (green-to-red by mood), 2 = date (G/B swapped), 3 = celebrity (gold).
    internal static (byte R, byte G, byte B) PlumbobColor(int indicatorKind, int mood)
    {
        var r = 1.0f;
        var g = 1.0f;
        var b = 1.0f;
        if (indicatorKind == 3)
        {
            b = 0.0f;
        }
        else
        {
            var fVar3 = Math.Clamp(mood * 0.01f, -1.0f, 1.0f);
            if (fVar3 >= 0.0f)
            {
                r = 1.0f - fVar3;
                b = 1.0f - fVar3;
                if (fVar3 < 0.5f) b -= 0.5f - fVar3;
            }
            else
            {
                var fVar4 = 1.0f - fVar3 * fVar3;
                b = fVar4;
                g = fVar4;
                if (fVar3 > -0.5f) b -= fVar3 + 0.5f;
            }
            if (indicatorKind == 2)
                (g, b) = (b, g);
        }
        return (
            (byte)Math.Clamp((int)MathF.Round(r * 255f), 0, 255),
            (byte)Math.Clamp((int)MathF.Round(g * 255f), 0, 255),
            (byte)Math.Clamp((int)MathF.Round(b * 255f), 0, 255));
    }

    private void AddHeadIndicatorPart(XPerson person, int indicatorKind, BonePose head,
        Matrix4x4 facingMatrix, Matrix4x4 parentRootTransform, LotCamera camera, List<Part> parts,
        float subTickAlpha = 0f)
    {
        var appearanceName = indicatorKind switch
        {
            1 => "head-arrow",
            2 => "head-arrow-date",
            3 => "head-star",
            _ => null,
        };
        if (appearanceName is null || !appearances.TryGetValue(appearanceName, out var source)) return;

        var colorKey = PlumbobColor(indicatorKind, (int)person[Motive.Mood]);
        if (!plumbobTextures.TryGetValue(colorKey, out var plumbobTex))
        {
            const int rampWidth = 32;
            var bytes = new byte[rampWidth * 4];
            for (var x = 0; x < rampWidth; x++)
            {
                var t = x / (float)(rampWidth - 1);
                float r, g, b;
                if (t <= 0.65f)
                {
                    var k = 0.42f + (t / 0.65f) * 0.58f;
                    r = colorKey.R * k;
                    g = colorKey.G * k;
                    b = colorKey.B * k;
                }
                else
                {
                    var spec = (t - 0.65f) / 0.35f;
                    var highlight = spec * spec * 0.68f;
                    r = colorKey.R + (255f - colorKey.R) * highlight;
                    g = colorKey.G + (255f - colorKey.G) * highlight;
                    b = colorKey.B + (255f - colorKey.B) * highlight;
                }
                var offset = x * 4;
                bytes[offset] = (byte)Math.Clamp((int)MathF.Round(r), 0, 255);
                bytes[offset + 1] = (byte)Math.Clamp((int)MathF.Round(g), 0, 255);
                bytes[offset + 2] = (byte)Math.Clamp((int)MathF.Round(b), 0, 255);
                bytes[offset + 3] = 255;
            }
            plumbobTex = (bytes, Convert.ToHexString(SHA1.HashData(bytes), 0, 6));
            plumbobTextures[colorKey] = plumbobTex;
        }
        var textureBytes = plumbobTex.Bytes;
        var textureHash = plumbobTex.Hash;

        var elapsedMs = person.AnimatorMilliseconds + subTickAlpha * 42f;
        var spinAngle = (MathF.PI + MathF.PI) * elapsedMs * 0.001f * 0.5f;
        var sx = MathF.Sin(MathF.PI * 0.25f);
        var cx = MathF.Cos(MathF.PI * 0.25f);
        var sz = MathF.Sin(spinAngle * 0.5f);
        var cz = MathF.Cos(spinAngle * 0.5f);
        var localRotation = new Quaternion(sx * cz, sx * sz, cx * sz, cx * cz);
        var worldRotation = Quaternion.Conjugate(localRotation);
        var boneMatrix = Matrix4x4.CreateFromQuaternion(Pose.BoneMatrixRotation(worldRotation));
        boneMatrix.M42 = 3.0f;

        var headRoot = Vector3.Transform(head.WorldTranslation, parentRootTransform);
        var indicatorRootTransform = facingMatrix * Matrix4x4.CreateScale(1f / 3f) *
                                     Matrix4x4.CreateTranslation(headRoot);

        var keyLight = new Vector3(-0.32444283f, 0.8111071f, -0.48666427f);
        var specHalf = Vector3.Normalize(keyLight + new Vector3(0f, 0.25f, -0.97f));

        foreach (var binding in source.Appearance.Bindings)
        {
            var mesh = ReadMesh(source.Path, binding.Mesh);
            if (mesh.Faces.Count == 0 || mesh.Faces.Count * 3 > 250_000) continue;
            var posed = new (Vector3 Position, Vector3 Normal, Vector2 UV)[mesh.TextureCoordinates.Count];
            for (var vertexIndex = 0; vertexIndex < posed.Length; vertexIndex++)
            {
                var vertex = mesh.Vertices[vertexIndex];
                var position = Vector3.Transform(vertex.Position, boneMatrix);
                var normal = Vector3.TransformNormal(vertex.Normal, boneMatrix);
                normal = Vector3.TransformNormal(normal, facingMatrix);
                var rootPosition = Vector3.Transform(position, indicatorRootTransform);
                posed[vertexIndex] = (rootPosition, normal, mesh.TextureCoordinates[vertexIndex]);
            }
            var flatFaces = GetMeshLayout(mesh).FlatFaceIndices;
            var vertices = new Vertex[flatFaces.Length];
            for (var tri = 0; tri + 2 < flatFaces.Length; tri += 3)
            {
                var a = posed[flatFaces[tri]];
                var b = posed[flatFaces[tri + 1]];
                var c = posed[flatFaces[tri + 2]];

                var faceNormal = Vector3.Cross(b.Position - a.Position, c.Position - a.Position);
                var avgVertexNormal = a.Normal + b.Normal + c.Normal;
                if (faceNormal.LengthSquared() > 1e-8f)
                {
                    if (Vector3.Dot(faceNormal, avgVertexNormal) < 0f)
                        faceNormal = -faceNormal;
                }
                else
                {
                    faceNormal = avgVertexNormal;
                }

                var normal = camera.CameraNormal(new Vector3(faceNormal.Z, faceNormal.Y, faceNormal.X));
                if (normal.LengthSquared() > 0) normal = Vector3.Normalize(normal);

                var ndotl = MathF.Max(0f, Vector3.Dot(normal, keyLight));
                var hemi = 0.5f + 0.5f * normal.Y;
                var spec = MathF.Pow(MathF.Max(0f, Vector3.Dot(normal, specHalf)), 8f);
                var rampU = Math.Clamp(0.05f + ndotl * 0.62f + hemi * 0.14f + spec * 0.35f, 0.02f, 0.98f);

                for (var corner = 0; corner < 3; corner++)
                {
                    var item = posed[flatFaces[tri + corner]];
                    var lotPosition = AvatarCoordinates.ToLot(item.Position);
                    var worldX = lotPosition.X;
                    var worldY = lotPosition.Y;
                    var point = camera.Project(worldX, worldY, item.Position.Y * 40);
                    vertices[tri + corner] = new Vertex(point.X, point.Y, camera.Depth(worldX, worldY, item.Position.Y),
                        rampU, 0.5f, normal.X, normal.Y, normal.Z);
                }
            }
            parts.Add(new Part(textureBytes, textureHash, "rgba", 32, 1, vertices, IgnoreRoomLighting: true));
        }
    }

    private void AddSkateParts(XPerson person, List<Part> parts,
        IReadOnlyDictionary<string, List<Vector3>> footPositions,
        float tileX, float tileY, float altitude, LotCamera camera)
    {
        var age = PersonAgeCategory.IsChild(person[PersonData.PersonAge]) ? "child" : "adult";
        Add("left");
        Add("right");

        void Add(string side)
        {
            var stem = $"accessoryskateice{age}{side}";
            var mesh = ReadSkateMesh(stem);
            var points = footPositions[side];
            if (points.Count < 3)
                throw new InvalidDataException($"Sim {person.Id} has no skinned {side} foot vertices for skate attachment {stem}");
            var footMin = new Vector3(points.Min(point => point.X), points.Min(point => point.Y), points.Min(point => point.Z));
            var footMax = new Vector3(points.Max(point => point.X), points.Max(point => point.Y), points.Max(point => point.Z));
            var shoeSpanX = footMax.X - footMin.X;
            var shoeSpanZ = footMax.Z - footMin.Z;
            var longAxisIsX = shoeSpanX > shoeSpanZ;
            var shoeLength = Math.Max(0.12f, Math.Max(shoeSpanX, shoeSpanZ) * 1.12f);
            var shoeWidth = Math.Max(0.035f, Math.Min(Math.Max(shoeSpanX, 0.04f), Math.Max(shoeSpanZ, 0.04f)));
            var sourceMinX = mesh.Positions.Min(point => -point.X);
            var sourceMaxX = mesh.Positions.Max(point => -point.X);
            var sourceMinY = mesh.Positions.Min(point => point.Y);
            var sourceMaxY = mesh.Positions.Max(point => point.Y);
            var sourceMinZ = mesh.Positions.Min(point => point.Z);
            var sourceMaxZ = mesh.Positions.Max(point => point.Z);

            var vertices = new Vertex[mesh.Corners.Length];
            for (var index = 0; index < mesh.Corners.Length; index++)
            {
                var corner = mesh.Corners[index];
                var source = mesh.Positions[corner.Position];
                var along = (source.Y - sourceMinY) / Math.Max(0.0001f, sourceMaxY - sourceMinY);
                var across = (-source.X - sourceMinX) / Math.Max(0.0001f, sourceMaxX - sourceMinX);
                var height = (source.Z - sourceMinZ) / Math.Max(0.0001f, sourceMaxZ - sourceMinZ);
                var centerX = (footMin.X + footMax.X) * 0.5f;
                var centerZ = (footMin.Z + footMax.Z) * 0.5f;
                var posed = longAxisIsX
                    ? new Vector3(centerX - shoeLength * 0.5f + along * shoeLength,
                        footMin.Y - 0.012f + height * 0.004f,
                        centerZ - shoeWidth * 0.5f + across * shoeWidth)
                    : new Vector3(centerX - shoeWidth * 0.5f + across * shoeWidth,
                        footMin.Y - 0.012f + height * 0.004f,
                        centerZ - shoeLength * 0.5f + along * shoeLength);
                var lotPosition = AvatarCoordinates.ToLot(posed);
                var worldX = tileX + lotPosition.X;
                var worldY = tileY + lotPosition.Y;
                var bladeDepth = camera.Depth(worldX, worldY, posed.Y + altitude);
                var point = camera.Project(worldX, worldY, posed.Y * 40 + altitude * 40);
                var normal = camera.CameraNormal(new Vector3(0, 1, 0));
                if (normal.LengthSquared() > 0) normal = Vector3.Normalize(normal);
                var uv = mesh.UVs[corner.UV];
                vertices[index] = new Vertex(point.X, point.Y, bladeDepth,
                    uv.X, uv.Y, normal.X, normal.Y, normal.Z);
            }
            parts.Add(new Part(mesh.Texture.Bytes, mesh.Texture.Sha1Hex, mesh.Texture.Encoding, mesh.Texture.Width, mesh.Texture.Height, vertices));
        }
    }

    private static readonly Matrix4x4 SourceAxis = new(
        -1, 0, 0, 0,
         0, 0, 1, 0,
         0, 1, 0, 0,
         0, 0, 0, 1);
    private static readonly Matrix4x4 SourceAxisInverse = Matrix4x4.Transpose(SourceAxis);

    private static Vector3 SourcePositionNative(Vector3 source)
    {
        return Vector3.Transform(source * 3, SourceAxis);
    }

    private static Matrix4x4 BoneMatrix(BonePose bone)
    {
        var matrix = Matrix4x4.CreateFromQuaternion(bone.WorldRotation);
        matrix.M41 = bone.WorldTranslation.X;
        matrix.M42 = bone.WorldTranslation.Y;
        matrix.M43 = bone.WorldTranslation.Z;
        return matrix;
    }

    private static Matrix4x4 SourceFrameMatrix(SkateFrame frame)
    {
        if (frame is null || frame.Translation is null || frame.Rotation is null ||
            frame.Translation.Length != 3 || frame.Rotation.Length != 4 ||
            frame.Translation.Any(value => !float.IsFinite(value)) || frame.Rotation.Any(value => !float.IsFinite(value)))
            throw new InvalidDataException("Source skate attachment frame has invalid CRES transform data");
        var rotation = new Quaternion(frame.Rotation[0], frame.Rotation[1], frame.Rotation[2], frame.Rotation[3]);
        if (rotation.LengthSquared() < 0.99f || rotation.LengthSquared() > 1.01f)
            throw new InvalidDataException("Source skate attachment frame has a non-unit CRES quaternion");
        var matrix = Matrix4x4.CreateFromQuaternion(Quaternion.Normalize(rotation));
        matrix.M41 = frame.Translation[0];
        matrix.M42 = frame.Translation[1];
        matrix.M43 = frame.Translation[2];
        return matrix;
    }

    private SkateAttachmentFrames ReadSkateAttachmentFrames()
    {
        if (skateAttachmentFrames is not null) return skateAttachmentFrames;
        var file = skins.Find("ice-skate-attachment-frames.txt")
            ?? throw new InvalidDataException("Source skate ankle-grip frame metadata is missing in the installed pack");
        var metadata = JsonSerializer.Deserialize<SkateAttachmentFrames>(file.Read().Span,
            new JsonSerializerOptions { PropertyNameCaseInsensitive = true })
            ?? throw new InvalidDataException("Source skate ankle-grip frame metadata is empty");
        if (metadata.SchemaVersion != 1 || metadata.CoordinateSystem is null ||
            !metadata.CoordinateSystem.Equals("source Sims 2 CRES; Z-up", StringComparison.Ordinal))
            throw new InvalidDataException("Source skate ankle-grip frame metadata has an unsupported schema or coordinate system");
        if (metadata.Skeletons is null)
            throw new InvalidDataException("Source skate attachment metadata has no adult/child skeleton table");
        foreach (var (age, leftFoot, rightFoot) in new[] { ("adult", "L_FOOT", "R_FOOT"), ("child", "L_FOOT", "R_FOOT") })
        {
            if (!metadata.Skeletons.TryGetValue(age, out var skeleton) ||
                skeleton is null || skeleton.Age is null || !skeleton.Age.Equals(age, StringComparison.OrdinalIgnoreCase) ||
                skeleton.Frames is null || skeleton.Frames.Count != 2 ||
                !skeleton.Frames.TryGetValue("left", out var left) || !skeleton.Frames.TryGetValue("right", out var right) ||
                left is null || right is null || left.Slot is null || left.Foot is null || right.Slot is null || right.Foot is null ||
                left.SlotJoint is null || right.SlotJoint is null || left.FootJoint is null || right.FootJoint is null ||
                !left.SlotJoint.Equals("l_ankle_grip", StringComparison.OrdinalIgnoreCase) ||
                !right.SlotJoint.Equals("r_ankle_grip", StringComparison.OrdinalIgnoreCase) ||
                !left.FootJoint.Equals(leftFoot, StringComparison.OrdinalIgnoreCase) ||
                !right.FootJoint.Equals(rightFoot, StringComparison.OrdinalIgnoreCase))
                throw new InvalidDataException($"Source skate attachment metadata has invalid {age} left/right ankle-grip bindings");
            _ = SourceFrameMatrix(left.Slot);
            _ = SourceFrameMatrix(left.Foot);
            _ = SourceFrameMatrix(right.Slot);
            _ = SourceFrameMatrix(right.Foot);
        }
        skateAttachmentFrames = metadata;
        return metadata;
    }

    private IReadOnlyDictionary<uint, HandPropBinding> ReadHandPropBindings()
    {
        if (handPropBindings is not null) return handPropBindings;
        var file = skins.Find("hand-prop-attachments.txt");
        if (file is null)
        {
            handPropBindings = [];
            return handPropBindings;
        }
        var manifest = JsonSerializer.Deserialize<HandPropManifest>(file.Read().Span,
            new JsonSerializerOptions { PropertyNameCaseInsensitive = true })
            ?? throw new InvalidDataException("Hand prop attachment metadata is empty");
        if (manifest.SchemaVersion != 1 || manifest.Props is null)
            throw new InvalidDataException("Hand prop attachment metadata has an unsupported schema");

        static Matrix4x4 ParseMatrix(float[] values, string key, string label)
        {
            if (values is null || values.Length != 12 || values.Any(v => !float.IsFinite(v)))
                throw new InvalidDataException($"Hand prop {key} has invalid {label} transform");
            return new Matrix4x4(
                values[0], values[1], values[2], 0f,
                values[3], values[4], values[5], 0f,
                values[6], values[7], values[8], 0f,
                values[9], values[10], values[11], 1f);
        }

        var parsed = new Dictionary<uint, HandPropBinding>(manifest.Props.Count);
        foreach (var (rawKey, entry) in manifest.Props)
        {
            var hex = rawKey.StartsWith("0x", StringComparison.OrdinalIgnoreCase) ? rawKey[2..] : rawKey;
            if (!uint.TryParse(hex, NumberStyles.HexNumber, CultureInfo.InvariantCulture, out var guid))
                throw new InvalidDataException($"Hand prop metadata key '{rawKey}' is not a valid hex GUID");
            if (entry is null || string.IsNullOrWhiteSpace(entry.Stem) || string.IsNullOrWhiteSpace(entry.Bone))
                throw new InvalidDataException($"Hand prop {rawKey} is missing a mesh stem or target bone");
            var bone = entry.Bone.Equals("R_HAND", StringComparison.OrdinalIgnoreCase)
                ? "R_HAND"
                : entry.Bone.Equals("L_HAND", StringComparison.OrdinalIgnoreCase)
                    ? "L_HAND"
                    : throw new InvalidDataException($"Hand prop {rawKey} names unsupported bone '{entry.Bone}'");
            parsed[guid] = new HandPropBinding(
                entry.Stem.Trim(),
                bone,
                ParseMatrix(entry.AdultMatrix, rawKey, "adultMatrix"),
                ParseMatrix(entry.ChildMatrix, rawKey, "childMatrix"));
        }
        handPropBindings = parsed;
        return handPropBindings;
    }

    private void AddHandPropParts(XPerson person, IReadOnlyList<uint> heldPropGuids, SkeletonInfo skeletonInfo,
        Matrix4x4[] boneMatrices, Matrix4x4 facingMatrix, Matrix4x4 rootTransform, LotCamera camera, List<Part> parts)
    {
        var bindings = ReadHandPropBindings();
        if (bindings.Count == 0) return;
        var isChild = PersonAgeCategory.IsChild(person[PersonData.PersonAge]);
        for (var p = 0; p < heldPropGuids.Count; p++)
        {
            if (!bindings.TryGetValue(heldPropGuids[p], out var binding)) continue;
            if (!skeletonInfo.IndexByNameIgnoreCase.TryGetValue(binding.Bone, out var handBoneIndex)) continue;
            var mesh = ReadSkateMesh(binding.Stem);
            var localMatrix = isChild ? binding.ChildMatrix : binding.AdultMatrix;
            var combined = localMatrix * boneMatrices[handBoneIndex];
            var vertices = new Vertex[mesh.Corners.Length];
            for (var index = 0; index < mesh.Corners.Length; index++)
            {
                var corner = mesh.Corners[index];
                var pos = Vector3.Transform(mesh.Positions[corner.Position], combined);
                var norm = Vector3.TransformNormal(mesh.Normals[corner.Normal], combined);
                if (norm.LengthSquared() > 1e-12f) norm = Vector3.Normalize(norm);
                norm = Vector3.TransformNormal(norm, facingMatrix);
                var camNorm = camera.CameraNormal(new Vector3(norm.Z, norm.Y, norm.X));
                if (camNorm.LengthSquared() > 0f) camNorm = Vector3.Normalize(camNorm);
                var rootPos = Vector3.Transform(pos, rootTransform);
                var lotPos = AvatarCoordinates.ToLot(rootPos);
                var point = camera.Project(lotPos.X, lotPos.Y, rootPos.Y * 40f);
                var depth = camera.Depth(lotPos.X, lotPos.Y, rootPos.Y);
                var rawUv = mesh.UVs[corner.UV];
                vertices[index] = new Vertex(point.X, point.Y, depth, rawUv.X, 1f - rawUv.Y, camNorm.X, camNorm.Y, camNorm.Z);
            }
            parts.Add(new Part(mesh.Texture.Bytes, mesh.Texture.Sha1Hex, mesh.Texture.Encoding, mesh.Texture.Width, mesh.Texture.Height, vertices));
        }
    }

    private SkateMesh ReadSkateMesh(string stem)
    {
        if (skateMeshes.TryGetValue(stem, out var cached)) return cached;
        var obj = skins.Find(stem + ".obj")
            ?? throw new InvalidDataException($"Source skate attachment mesh {stem}.obj is not installed in the installed pack");
        var mtl = skins.Find(stem + ".mtl")
            ?? throw new InvalidDataException($"Source skate attachment material {stem}.mtl is missing");
        var textureName = Encoding.ASCII.GetString(mtl.Read().Span).Split('\n')
            .Select(line => line.Trim().Split((char[]?)null, StringSplitOptions.RemoveEmptyEntries))
            .FirstOrDefault(parts => parts.Length == 2 && parts[0].Equals("map_Kd", StringComparison.OrdinalIgnoreCase))?[1]
            ?? throw new InvalidDataException($"Source skate attachment material {stem}.mtl has no diffuse texture");
        var textureFile = skins.Find(textureName)
            ?? throw new InvalidDataException($"Source skate texture {textureName} is missing in the installed pack");
        var textureBytes = textureFile.Read().ToArray();
        if (textureFile.Extension.Equals(".png", StringComparison.OrdinalIgnoreCase) && textureBytes.Length >= 24 &&
            textureBytes.AsSpan(0, 8).SequenceEqual(new byte[] { 137, 80, 78, 71, 13, 10, 26, 10 }))
        {
            var width = BinaryPrimitives.ReadInt32BigEndian(textureBytes.AsSpan(16, 4));
            var height = BinaryPrimitives.ReadInt32BigEndian(textureBytes.AsSpan(20, 4));
            if (width is < 1 or > 4096 || height is < 1 or > 4096)
                throw new InvalidDataException($"Source skate texture {textureName} has invalid dimensions");
            var model = ParseSkateObj(Encoding.ASCII.GetString(obj.Read().Span), stem,
                new TextureSource(textureBytes, Convert.ToHexString(SHA1.HashData(textureBytes), 0, 6), "png", width, height, textureFile.Name));
            skateMeshes.Add(stem, model);
            return model;
        }
        throw new InvalidDataException($"Source skate texture {textureName} is not a PNG");
    }

    private static SkateMesh ParseSkateObj(string source, string stem, TextureSource texture)
    {
        var positions = new List<Vector3>();
        var uvs = new List<Vector2>();
        var normals = new List<Vector3>();
        var corners = new List<(int Position, int UV, int Normal)>();
        var lineNumber = 0;
        foreach (var rawLine in source.Split('\n'))
        {
            lineNumber++;
            var line = rawLine.Trim();
            if (line.Length == 0 || line[0] == '#') continue;
            var fields = line.Split((char[]?)null, StringSplitOptions.RemoveEmptyEntries);
            float Number(int index)
            {
                if (index >= fields.Length || !float.TryParse(fields[index], NumberStyles.Float, CultureInfo.InvariantCulture, out var value) ||
                    !float.IsFinite(value) || MathF.Abs(value) > 1000)
                    throw new InvalidDataException($"Skate OBJ {stem}.obj line {lineNumber} has an invalid coordinate");
                return value;
            }
            if (fields[0] == "v") positions.Add(new Vector3(Number(1), Number(2), Number(3)));
            else if (fields[0] == "vt") uvs.Add(new Vector2(Number(1), Number(2)));
            else if (fields[0] == "vn") normals.Add(new Vector3(Number(1), Number(2), Number(3)));
            else if (fields[0] == "f")
            {
                if (fields.Length != 4) throw new InvalidDataException($"Skate OBJ {stem}.obj line {lineNumber} is not a triangle");
                for (var corner = 1; corner <= 3; corner++)
                {
                    var indexes = fields[corner].Split('/');
                    if (indexes.Length != 3 || !int.TryParse(indexes[0], NumberStyles.None, CultureInfo.InvariantCulture, out var p) ||
                        !int.TryParse(indexes[1], NumberStyles.None, CultureInfo.InvariantCulture, out var uv) ||
                        !int.TryParse(indexes[2], NumberStyles.None, CultureInfo.InvariantCulture, out var n) ||
                        p < 1 || p > positions.Count || uv < 1 || uv > uvs.Count || n < 1 || n > normals.Count)
                        throw new InvalidDataException($"Skate OBJ {stem}.obj line {lineNumber} has an invalid face index");
                    corners.Add((p - 1, uv - 1, n - 1));
                }
            }
            if (positions.Count > 10_000 || uvs.Count > 10_000 || normals.Count > 10_000 || corners.Count > 60_000)
                throw new InvalidDataException($"Source skate mesh {stem}.obj exceeds the native scene limits");
        }
        if (positions.Count == 0 || uvs.Count == 0 || normals.Count == 0 || corners.Count == 0 || corners.Count % 3 != 0)
            throw new InvalidDataException($"Source skate mesh {stem}.obj has incomplete geometry");
        return new SkateMesh(positions.ToArray(), uvs.ToArray(), normals.ToArray(), corners.ToArray(), texture);
    }

    private static CharacterFile Find(CharacterSearchPath path, string name, params string[] extensions)
    {
        var stem = Path.GetFileName(name.Trim());
        if (Path.HasExtension(stem)) return path.Find(stem)
            ?? throw new InvalidDataException($"Avatar resource {name} is missing from the original search path");
        foreach (var extension in extensions)
            if (path.Find(stem + extension) is { } found) return found;
        throw new InvalidDataException($"Avatar resource {name} is missing from the original search path");
    }

    private static string NormalizeAppearance(string name)
    {
        var trimmed = name.Trim();
        foreach (var suffix in new[] { ".cmx.bcf", ".apr", ".bcf", ".cmx" })
        {
            if (trimmed.EndsWith(suffix, StringComparison.OrdinalIgnoreCase))
                return trimmed[..^suffix.Length];
        }
        return trimmed;
    }
}
