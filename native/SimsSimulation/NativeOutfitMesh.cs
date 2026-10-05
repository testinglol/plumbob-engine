using System.Globalization;
using System.Text;
using FSO.Files.Utils;
using FSO.Vitaboy;
using FSO.Vitaboy.Model;
using Microsoft.Xna.Framework;

/// <summary>
/// Body meshes for authored outfits. A TS1 mesh (<c>.skn</c>, plain-text BMF) stores each vertex in the space of the one bone
/// it follows, grouped by bone, plus "blend" copies of some vertices in a second bone's space with a weight, which bend
/// joints. Export puts the mesh in the skeleton's rest pose as a Wavefront OBJ. Import re-skins an edited OBJ: every vertex
/// takes the bone and blend of the nearest original vertex and is converted back into those bones' spaces, so the rest pose
/// reproduces the OBJ exactly and the new shape follows the skeleton the way the nearest part of the original did.
/// </summary>
internal static class NativeOutfitMesh
{
    private const int MaximumVertices = 30_000;
    private const int MaximumFaces = 60_000;

    /// <summary>A mesh vertex in the rest pose: position, normal and texture coordinate, with its bones.</summary>
    private readonly record struct Skinned(Vector3 Position, Vector3 Normal, Vector2 UV, int Bone, int BlendBone, float Weight);

    internal static Mesh Read(byte[] data)
    {
        var mesh = new Mesh();
        using var io = new BCFReadString(new MemoryStream(data), false);
        mesh.Read(io, true);
        if (mesh.BoneBindings.Length == 0 || mesh.VertexBuffer.Length == 0) throw new InvalidDataException("The mesh has no vertices");
        return mesh;
    }

    /// <summary>The mesh's bone names, by binding.</summary>
    private static string[] Bones(Mesh mesh) => mesh.BoneBindings.Select(binding => binding.BoneName).ToArray();

    /// <summary>Every vertex in the rest pose of <paramref name="skeleton"/>, blended the way the renderer blends it.</summary>
    private static Skinned[] RestPose(Mesh mesh, Skeleton skeleton)
    {
        var bones = Bones(mesh).Select(name => skeleton.GetBone(name) ?? throw new InvalidDataException($"Skeleton {skeleton.Name} has no bone {name}")).ToArray();
        var vertexBone = new int[mesh.VertexBuffer.Length];
        var blendBone = new int[mesh.BlendData.Length];
        for (var index = 0; index < mesh.BoneBindings.Length; index++)
        {
            var binding = mesh.BoneBindings[index];
            for (var vertex = 0; vertex < binding.RealVertexCount; vertex++) vertexBone[binding.FirstRealVertex + vertex] = index;
            for (var blend = 0; blend < binding.BlendVertexCount; blend++) blendBone[binding.FirstBlendVertex + blend] = index;
        }
        var result = new Skinned[mesh.VertexBuffer.Length];
        for (var index = 0; index < result.Length; index++)
        {
            var vertex = mesh.VertexBuffer[index];
            var matrix = bones[vertexBone[index]].AbsoluteMatrix;
            result[index] = new Skinned(Vector3.Transform(vertex.Position, matrix), Vector3.TransformNormal(vertex.Normal, matrix), vertex.TextureCoordinate,
                                        vertexBone[index], -1, 0);
        }
        for (var blend = 0; blend < mesh.BlendData.Length; blend++)
        {
            var data = mesh.BlendData[blend];
            if (data.OtherVertex < 0 || data.OtherVertex >= result.Length) throw new InvalidDataException("The mesh blends a vertex it does not have");
            var matrix = bones[blendBone[blend]].AbsoluteMatrix;
            var vertex = result[data.OtherVertex];
            result[data.OtherVertex] = vertex with
            {
                Position = Vector3.Lerp(vertex.Position, Vector3.Transform(mesh.BlendVerts[blend], matrix), data.Weight),
                Normal = Vector3.Lerp(vertex.Normal, Vector3.TransformNormal(mesh.BlendNormals[blend], matrix), data.Weight),
                BlendBone = blendBone[blend], Weight = data.Weight
            };
        }
        return result;
    }

    /// <summary>The mesh as a Wavefront OBJ in the rest pose. Texture V is flipped to OBJ's bottom-up convention.</summary>
    internal static string ExportObj(Mesh mesh, Skeleton skeleton, string name)
    {
        var vertices = RestPose(mesh, skeleton);
        var text = new StringBuilder();
        text.Append("# ").Append(name).Append(", rest pose of skeleton ").Append(skeleton.Name).Append('\n');
        text.Append("o ").Append(name).Append('\n');
        foreach (var vertex in vertices) text.Append(Invariant($"v {vertex.Position.X:R} {vertex.Position.Y:R} {vertex.Position.Z:R}\n"));
        foreach (var vertex in vertices) text.Append(Invariant($"vt {vertex.UV.X:R} {1 - vertex.UV.Y:R}\n"));
        foreach (var vertex in vertices)
        {
            var normal = vertex.Normal.LengthSquared() > 0 ? Vector3.Normalize(vertex.Normal) : Vector3.Up;
            text.Append(Invariant($"vn {normal.X:R} {normal.Y:R} {normal.Z:R}\n"));
        }
        for (var face = 0; face + 2 < mesh.IndexBuffer.Length; face += 3)
        {
            text.Append('f');
            for (var corner = 0; corner < 3; corner++)
            {
                var index = mesh.IndexBuffer[face + corner] + 1;
                text.Append(' ').Append(index).Append('/').Append(index).Append('/').Append(index);
            }
            text.Append('\n');
        }
        return text.ToString();
    }

    private static string Invariant(FormattableString value) => value.ToString(CultureInfo.InvariantCulture);

    /// <summary>A parsed OBJ: one vertex per distinct position/texture/normal corner, and triangles over them.</summary>
    private sealed record Obj(Vector3[] Positions, Vector2[] UVs, Vector3[] Normals, int[] Triangles);

    private static Obj ParseObj(string text, string what)
    {
        var positions = new List<Vector3>();
        var uvs = new List<Vector2>();
        var normals = new List<Vector3>();
        var corners = new Dictionary<(int, int, int), int>();
        var outPositions = new List<Vector3>();
        var outUVs = new List<Vector2>();
        var outNormals = new List<int>();
        var triangles = new List<int>();
        var lineNumber = 0;
        float Number(string value)
        {
            if (!float.TryParse(value, NumberStyles.Float, CultureInfo.InvariantCulture, out var number) || !float.IsFinite(number) || MathF.Abs(number) > 1000)
                throw new InvalidDataException($"{what} line {lineNumber}: {value} is not a coordinate");
            return number;
        }
        int Reference(string value, int count, string kind)
        {
            if (!int.TryParse(value, NumberStyles.AllowLeadingSign, CultureInfo.InvariantCulture, out var index) || index == 0)
                throw new InvalidDataException($"{what} line {lineNumber}: {value} is not a {kind} index");
            var resolved = index > 0 ? index - 1 : count + index;
            if (resolved < 0 || resolved >= count) throw new InvalidDataException($"{what} line {lineNumber}: {kind} {value} does not exist");
            return resolved;
        }
        foreach (var raw in text.Split('\n'))
        {
            lineNumber++;
            var line = raw.Trim();
            var comment = line.IndexOf('#');
            if (comment >= 0) line = line[..comment].Trim();
            if (line.Length == 0) continue;
            var parts = line.Split((char[]?)null, StringSplitOptions.RemoveEmptyEntries);
            switch (parts[0])
            {
                case "v":
                    if (parts.Length < 4) throw new InvalidDataException($"{what} line {lineNumber}: a vertex needs x, y and z");
                    positions.Add(new Vector3(Number(parts[1]), Number(parts[2]), Number(parts[3])));
                    break;
                case "vt":
                    if (parts.Length < 3) throw new InvalidDataException($"{what} line {lineNumber}: a texture coordinate needs u and v");
                    uvs.Add(new Vector2(Number(parts[1]), 1 - Number(parts[2])));
                    break;
                case "vn":
                    if (parts.Length < 4) throw new InvalidDataException($"{what} line {lineNumber}: a normal needs x, y and z");
                    normals.Add(new Vector3(Number(parts[1]), Number(parts[2]), Number(parts[3])));
                    break;
                case "f":
                    if (parts.Length < 4) throw new InvalidDataException($"{what} line {lineNumber}: a face needs at least three corners");
                    var face = new int[parts.Length - 1];
                    for (var corner = 0; corner < face.Length; corner++)
                    {
                        var fields = parts[corner + 1].Split('/');
                        if (fields.Length < 2 || fields[1].Length == 0)
                            throw new InvalidDataException($"{what} line {lineNumber}: every corner needs a texture coordinate (v/vt or v/vt/vn)");
                        var key = (Reference(fields[0], positions.Count, "vertex"), Reference(fields[1], uvs.Count, "texture coordinate"),
                                   fields.Length > 2 && fields[2].Length > 0 ? Reference(fields[2], normals.Count, "normal") : -1);
                        if (!corners.TryGetValue(key, out var vertex))
                        {
                            vertex = outPositions.Count;
                            if (vertex >= MaximumVertices) throw new InvalidDataException($"{what} has more than {MaximumVertices} distinct vertices");
                            corners.Add(key, vertex);
                            outPositions.Add(positions[key.Item1]);
                            outUVs.Add(uvs[key.Item2]);
                            outNormals.Add(key.Item3);
                        }
                        face[corner] = vertex;
                    }
                    // Polygons become a fan of triangles.
                    for (var corner = 1; corner + 1 < face.Length; corner++)
                    {
                        triangles.Add(face[0]); triangles.Add(face[corner]); triangles.Add(face[corner + 1]);
                        if (triangles.Count / 3 > MaximumFaces) throw new InvalidDataException($"{what} has more than {MaximumFaces} triangles");
                    }
                    break;
                case "o" or "g" or "s" or "mtllib" or "usemtl" or "l":
                    break;
                default:
                    throw new InvalidDataException($"{what} line {lineNumber}: {parts[0]} is not supported");
            }
        }
        if (triangles.Count == 0) throw new InvalidDataException($"{what} has no faces");

        // Corners without a normal take the area-weighted normal of the faces at their position.
        var smooth = new Dictionary<Vector3, Vector3>();
        for (var index = 0; index < triangles.Count; index += 3)
        {
            var (a, b, c) = (outPositions[triangles[index]], outPositions[triangles[index + 1]], outPositions[triangles[index + 2]]);
            var normal = Vector3.Cross(b - a, c - a);
            foreach (var position in new[] { a, b, c }) smooth[position] = smooth.GetValueOrDefault(position) + normal;
        }
        var resolvedNormals = outNormals.Select((normal, index) =>
        {
            var value = normal >= 0 ? normals[normal] : smooth.GetValueOrDefault(outPositions[index]);
            return value.LengthSquared() > 1e-12f ? Vector3.Normalize(value) : Vector3.Up;
        }).ToArray();
        return new Obj(outPositions.ToArray(), outUVs.ToArray(), resolvedNormals, triangles.ToArray());
    }

    /// <summary>
    /// Builds a mesh from an edited OBJ, skinned like <paramref name="template"/>. The result binds the template's bones in the
    /// template's order. Reports how far the farthest vertex is from the original surface it took its bones from.
    /// </summary>
    internal static (Mesh Mesh, float Farthest) Import(string objText, string what, Mesh template, Skeleton skeleton, string skinName, string textureName)
    {
        var obj = ParseObj(objText, what);
        var original = RestPose(template, skeleton);
        var boneNames = Bones(template);
        var bones = boneNames.Select(name => skeleton.GetBone(name)!).ToArray();
        var inverse = bones.Select(bone => Matrix.Invert(bone.AbsoluteMatrix)).ToArray();

        // Nearest original vertex, preferring one with the same texture coordinate where several share a position.
        var farthest = 0f;
        var skinned = new Skinned[obj.Positions.Length];
        for (var index = 0; index < skinned.Length; index++)
        {
            var position = obj.Positions[index];
            var best = 0;
            var bestScore = float.MaxValue;
            for (var candidate = 0; candidate < original.Length; candidate++)
            {
                var score = Vector3.DistanceSquared(position, original[candidate].Position) + 1e-6f * Vector2.DistanceSquared(obj.UVs[index], original[candidate].UV);
                if (score < bestScore) (best, bestScore) = (candidate, score);
            }
            farthest = MathF.Max(farthest, Vector3.Distance(position, original[best].Position));
            skinned[index] = new Skinned(position, obj.Normals[index], obj.UVs[index], original[best].Bone, original[best].BlendBone, original[best].Weight);
        }

        // Vertices are stored grouped by bone, and blend copies grouped by their second bone.
        var order = Enumerable.Range(0, skinned.Length).OrderBy(index => skinned[index].Bone).ThenBy(index => index).ToArray();
        var newIndex = new int[skinned.Length];
        for (var index = 0; index < order.Length; index++) newIndex[order[index]] = index;
        var blends = order.Where(index => skinned[index].BlendBone >= 0 && skinned[index].Weight > 0)
            .OrderBy(index => skinned[index].BlendBone).ThenBy(index => newIndex[index]).ToArray();

        var mesh = new Mesh
        {
            SkinName = skinName, TextureName = textureName,
            VertexBuffer = order.Select(index =>
            {
                var vertex = skinned[index];
                return new VitaboyVertex
                {
                    Position = Vector3.Transform(vertex.Position, inverse[vertex.Bone]),
                    Normal = Vector3.Normalize(Vector3.TransformNormal(vertex.Normal, inverse[vertex.Bone])),
                    TextureCoordinate = vertex.UV
                };
            }).ToArray(),
            IndexBuffer = obj.Triangles.Select(index => newIndex[index]).ToArray(),
            NumPrimitives = obj.Triangles.Length / 3,
            BlendData = blends.Select(index => new BlendData { OtherVertex = newIndex[index], Weight = skinned[index].Weight }).ToArray(),
            BlendVerts = blends.Select(index => Vector3.Transform(skinned[index].Position, inverse[skinned[index].BlendBone])).ToArray(),
            BlendNormals = blends.Select(index => Vector3.Normalize(Vector3.TransformNormal(skinned[index].Normal, inverse[skinned[index].BlendBone]))).ToArray(),
            BoneBindings = boneNames.Select((name, bone) =>
            {
                var first = Array.FindIndex(order, index => skinned[index].Bone == bone);
                var firstBlend = Array.FindIndex(blends, index => skinned[index].BlendBone == bone);
                return new BoneBinding
                {
                    BoneName = name, BoneIndex = bone,
                    FirstRealVertex = first < 0 ? 0 : first, RealVertexCount = order.Count(index => skinned[index].Bone == bone),
                    FirstBlendVertex = firstBlend, BlendVertexCount = blends.Count(index => skinned[index].BlendBone == bone)
                };
            }).ToArray()
        };
        return (mesh, farthest);
    }

    /// <summary>Writes a mesh as TS1 plain-text BMF (<c>.skn</c>), in the order <see cref="Mesh.Read"/> reads it.</summary>
    internal static byte[] Write(Mesh mesh)
    {
        var text = new StringBuilder();
        void Line(FormattableString value) => text.Append(value.ToString(CultureInfo.InvariantCulture)).Append('\n');
        text.Append(mesh.SkinName).Append('\n').Append(mesh.TextureName).Append('\n');
        Line($"{mesh.BoneBindings.Length}");
        foreach (var binding in mesh.BoneBindings) text.Append(binding.BoneName).Append('\n');
        Line($"{mesh.NumPrimitives}");
        for (var index = 0; index < mesh.IndexBuffer.Length; index += 3) Line($"{mesh.IndexBuffer[index]} {mesh.IndexBuffer[index + 1]} {mesh.IndexBuffer[index + 2]}");
        Line($"{mesh.BoneBindings.Length}");
        foreach (var binding in mesh.BoneBindings)
            Line($"{binding.BoneIndex} {binding.FirstRealVertex} {binding.RealVertexCount} {(binding.BlendVertexCount == 0 ? -1 : binding.FirstBlendVertex)} {binding.BlendVertexCount}");
        Line($"{mesh.VertexBuffer.Length}");
        foreach (var vertex in mesh.VertexBuffer) Line($"{vertex.TextureCoordinate.X:R} {vertex.TextureCoordinate.Y:R}");
        Line($"{mesh.BlendData.Length}");
        // Plain-text BMF lists the blended vertex first, then the weight in 1/32768ths.
        foreach (var blend in mesh.BlendData) Line($"{blend.OtherVertex} {(int)MathF.Round(blend.Weight * 0x8000)}");
        Line($"{mesh.VertexBuffer.Length}");
        // The reader negates X, so it is written negated.
        foreach (var vertex in mesh.VertexBuffer)
            Line($"{-vertex.Position.X:R} {vertex.Position.Y:R} {vertex.Position.Z:R} {-vertex.Normal.X:R} {vertex.Normal.Y:R} {vertex.Normal.Z:R}");
        for (var index = 0; index < mesh.BlendVerts.Length; index++)
            Line($"{-mesh.BlendVerts[index].X:R} {mesh.BlendVerts[index].Y:R} {mesh.BlendVerts[index].Z:R} {-mesh.BlendNormals[index].X:R} {mesh.BlendNormals[index].Y:R} {mesh.BlendNormals[index].Z:R}");
        return Encoding.ASCII.GetBytes(text.ToString());
    }
}
