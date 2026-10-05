using System.Security.Cryptography;
using System.Text.Json;
using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.LotView.Model;
using FSO.SimAntics;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Model;
using FSO.SimAntics.Utils;
using FSO.Vitaboy;

internal static class NativeHouseholdAppearancePreview
{
    private sealed record PreviewTexture(string File, int Width, int Height, string Encoding);
    private sealed record PreviewVertex(float X, float Y, float Z, float U, float V, float Nx, float Ny, float Nz);
    private sealed record PreviewMesh(int Texture, int ObjectID, float Depth, PreviewVertex[] Vertices, int Layer);
    private sealed record PreviewDocument(int SchemaVersion, float Width, float Height, PreviewTexture[] Textures, PreviewMesh[] Meshes);

    internal static object Export(string session, string gender, string age, string skin, string headChoice, string bodyChoice)
    {
        var catalog = NativeHouseholdAppearance.Catalog(gender, age, skin);
        var body = catalog.Bodies.SingleOrDefault(choice => string.Equals(choice.Id, bodyChoice, StringComparison.OrdinalIgnoreCase))
            ?? throw new ArgumentException("Selected clothing is not available for this Sim's gender, age and skin");
        if (!catalog.Heads.Any(choice => string.Equals(choice.Id, headChoice, StringComparison.OrdinalIgnoreCase)))
            throw new ArgumentException("Selected head is not available for this Sim's gender, age and skin");

        var code = gender + (age == "child" ? "c" : "a") + body.BodyType;
        var member = new NativeHouseholdMember("Preview", "", code, skin, [500, 500, 500, 500, 500], headChoice, bodyChoice);
        var info = new SimTemplateCreateInfo(code, skin);
        NativeHouseholdAppearance.Apply(info, member);

        var avatar = Avatar(info, age == "child", skin);
        var parts = AvatarGeometry.Build(avatar, new NativeEntityTransform((_, _) => 0), new NativeLotCamera(0, 128, 128));
        if (parts.Count == 0 || parts.Sum(part => part.Vertices.Length) > 250_000)
            throw new InvalidDataException("The selected Sim appearance produced invalid preview geometry");

        return Write(session, parts);
    }

    /// <summary>A standing template Sim wearing the chosen head and body, for previews and portraits.</summary>
    internal static VMAvatar Avatar(SimTemplateCreateInfo info, bool child, string skin)
    {
        var age = child ? "child" : "adult";
        var content = Content.Get();
        var template = content.WorldObjects.Get(SimitoneNeighbourGenerator.TEMPLATE_GUID)
            ?? throw new InvalidDataException("The installed Sim template is missing");
        var avatar = new VMAvatar(template) { Animations = [] };
        avatar.Position = new LotTilePos(64 * 16, 64 * 16, 1);
        avatar.RadianDirection = MathF.PI;
        avatar.Avatar = new SimAvatar(content.AvatarSkeletons.Get((age == "child" ? "child" : "adult") + ".skel"));
        var bodyStrings = new STR();
        for (var index = 0; index <= 22; index++)
            bodyStrings.InsertString(index, new STRItem { Value = info.BodyStringReplace.GetValueOrDefault(index, ""), Comment = "" });
        avatar.BodyOutfit = new VMOutfitReference(bodyStrings, false);
        avatar.HeadOutfit = new VMOutfitReference(info.BodyStringReplace[2], true);
        avatar.SkinTone = skin switch
        {
            "lgt" => AppearanceType.Light,
            "med" => AppearanceType.Medium,
            _ => AppearanceType.Dark
        };
        return avatar;
    }

    /// <summary>Normalizes avatar geometry into a unit square and writes preview.json plus its textures.</summary>
    internal static object Write(string session, IReadOnlyList<AvatarGeometry.Part> parts)
    {
        var minX = parts.SelectMany(part => part.Vertices).Min(vertex => vertex.X);
        var maxX = parts.SelectMany(part => part.Vertices).Max(vertex => vertex.X);
        var minY = parts.SelectMany(part => part.Vertices).Min(vertex => vertex.Y);
        var maxY = parts.SelectMany(part => part.Vertices).Max(vertex => vertex.Y);
        var rangeX = maxX - minX;
        var rangeY = maxY - minY;
        if (!float.IsFinite(rangeX) || !float.IsFinite(rangeY) || rangeX <= 0 || rangeY <= 0)
            throw new InvalidDataException("The selected Sim appearance has invalid preview bounds");
        var scale = MathF.Min(0.88f / rangeX, 0.94f / rangeY);
        var centerX = (minX + maxX) / 2;

        var directory = Path.Combine(session, "cas-preview");
        if (Directory.Exists(directory)) Directory.Delete(directory, true);
        var textureDirectory = Path.Combine(directory, "textures");
        Directory.CreateDirectory(textureDirectory);
        var textures = new List<PreviewTexture>();
        var textureIndices = new Dictionary<string, int>(StringComparer.Ordinal);
        var meshes = new List<PreviewMesh>();
        foreach (var part in parts)
        {
            var key = Convert.ToHexString(SHA256.HashData(part.Texture));
            if (!textureIndices.TryGetValue(key, out var textureIndex))
            {
                textureIndex = textures.Count;
                textureIndices.Add(key, textureIndex);
                var file = $"textures/{key}.{part.Encoding}";
                File.WriteAllBytes(Path.Combine(directory, file), part.Texture);
                textures.Add(new PreviewTexture(file, part.Width, part.Height, part.Encoding));
            }
            var vertices = part.Vertices.Select(vertex => new PreviewVertex(
                0.5f + (vertex.X - centerX) * scale,
                0.03f + (vertex.Y - minY) * scale,
                vertex.Z,
                vertex.U,
                vertex.V,
                vertex.Nx,
                vertex.Ny,
                vertex.Nz)).ToArray();
            meshes.Add(new PreviewMesh(textureIndex, 0, 0.5f, vertices, 1));
        }

        var path = Path.Combine(directory, "preview.json");
        var temporary = path + ".tmp";
        var document = new PreviewDocument(1, 1, 1, textures.ToArray(), meshes.ToArray());
        try
        {
            File.WriteAllText(temporary, JsonSerializer.Serialize(document, new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
            File.Move(temporary, path, true);
        }
        finally
        {
            if (File.Exists(temporary)) File.Delete(temporary);
        }
        return new { file = "cas-preview/preview.json", schemaVersion = 1, meshes = meshes.Count, textures = textures.Count };
    }
}
