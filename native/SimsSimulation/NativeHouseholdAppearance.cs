using FSO.Content;
using FSO.Content.TS1;
using FSO.SimAntics.Utils;

internal sealed record NativeAppearanceChoice(string Id, string Texture, string BodyType = "", string Replacement = "", string HandGroup = "");
internal sealed record NativeAppearanceCatalog(string Gender, string Age, string Skin, NativeAppearanceChoice[] Heads, NativeAppearanceChoice[] Bodies);

internal static class NativeHouseholdAppearance
{
    internal static NativeAppearanceCatalog Catalog(string gender, string age, string skin)
    {
        if (gender is not ("m" or "f")) throw new ArgumentException("Gender must be m or f", nameof(gender));
        if (age is not ("adult" or "child")) throw new ArgumentException("Age must be adult or child", nameof(age));
        if (skin is not ("lgt" or "med" or "drk")) throw new ArgumentException("Skin must be lgt, med or drk", nameof(skin));

        var child = age == "child";
        var simType = gender + (child ? "c" : "a");
        var bodyAvatarType = simType + (child ? "chd" : "");
        var content = Content.Get();
        var textures = ((TS1AvatarTextureProvider)content.AvatarTextures).GetAllNames()
            .Select(RemoveExtension).Where(name => name != null).ToHashSet(StringComparer.OrdinalIgnoreCase);
        var heads = GetItems(content, "c", simType)
            .Select(item => MakeChoice(item, skin, textures, false))
            .Where(choice => choice != null).Cast<NativeAppearanceChoice>()
            .DistinctBy(choice => choice.Id, StringComparer.OrdinalIgnoreCase)
            .OrderBy(choice => choice.Id, StringComparer.OrdinalIgnoreCase).ToArray();
        var bodies = GetItems(content, "b", bodyAvatarType)
            .Select(item => MakeChoice(item, skin, textures, true))
            .Where(choice => choice != null).Cast<NativeAppearanceChoice>()
            .DistinctBy(choice => choice.Id, StringComparer.OrdinalIgnoreCase)
            .OrderBy(choice => choice.Id, StringComparer.OrdinalIgnoreCase).ToArray();
        if (heads.Length == 0 || bodies.Length == 0)
            throw new InvalidOperationException($"No installed head or clothing choices are available for {gender}/{age}/{skin}");
        return new NativeAppearanceCatalog(gender, age, skin, heads, bodies);
    }

    internal static void Apply(SimTemplateCreateInfo info, NativeHouseholdMember member)
    {
        if (string.IsNullOrWhiteSpace(member.HeadChoice) && string.IsNullOrWhiteSpace(member.BodyChoice)) return;
        var catalog = Catalog(member.Code[0].ToString(), member.Code[1] == 'c' ? "child" : "adult", member.Skin);
        var head = string.IsNullOrWhiteSpace(member.HeadChoice) ? null : catalog.Heads.SingleOrDefault(choice => Same(choice.Id, member.HeadChoice));
        var body = string.IsNullOrWhiteSpace(member.BodyChoice) ? null : catalog.Bodies.SingleOrDefault(choice => Same(choice.Id, member.BodyChoice));
        if (!string.IsNullOrWhiteSpace(member.HeadChoice) && head == null)
            throw new ArgumentException("Selected head is not available for this Sim's gender, age and skin");
        if (!string.IsNullOrWhiteSpace(member.BodyChoice) && body == null)
            throw new ArgumentException("Selected clothing is not available for this Sim's gender, age and skin");
        if (body != null && !string.Equals(member.Code[2..], body.BodyType, StringComparison.OrdinalIgnoreCase))
            throw new ArgumentException("Selected body type does not match the appearance code");

        if (head != null) info.BodyStringReplace[2] = head.Replacement;
        if (body != null)
        {
            info.BodyStringReplace[1] = body.Replacement;
            var hand = member.Code[1] == 'c' ? 'u' : member.Code[0];
            info.BodyStringReplace[17] = $"H{hand}LO,HAND=huao{body.HandGroup}";
            info.BodyStringReplace[18] = $"H{hand}RO,HAND=huao{body.HandGroup}";
            info.BodyStringReplace[19] = $"H{hand}LP,HAND=huao{body.HandGroup}";
            info.BodyStringReplace[20] = $"H{hand}RP,HAND=huao{body.HandGroup}";
            info.BodyStringReplace[21] = $"H{hand}LO,HAND=huao{body.HandGroup}";
            info.BodyStringReplace[22] = $"H{hand}RC,HAND=huao{body.HandGroup}";
        }
    }

    private static IEnumerable<string> GetItems(Content content, string collection, string avatarType)
    {
        if (!content.BCFGlobal.CollectionsByName.TryGetValue(collection, out var group) ||
            !group.ClothesByAvatarType.TryGetValue(avatarType, out var items))
            return [];
        return items.ToArray();
    }

    private static NativeAppearanceChoice? MakeChoice(string item, string skin, HashSet<string> textures, bool body)
    {
        var prefix = ExtractID(item) + skin;
        var texture = textures.FirstOrDefault(name => name.StartsWith(prefix, StringComparison.OrdinalIgnoreCase));
        if (texture == null) return null;
        if (!body) return new NativeAppearanceChoice(item, texture, Replacement: $"{item},HEAD-HEAD={texture}");
        var underscore = item.IndexOf('_');
        if (underscore < 3) return null;
        var bodyType = item.Substring(underscore - 3, 3).ToLowerInvariant();
        var handKey = item.IndexOf('_') >= 0 ? item[item.IndexOf('_')..] : item;
        var handTexture = textures.FirstOrDefault(name => name.Equals("huao" + handKey, StringComparison.OrdinalIgnoreCase)) ?? "huao" + skin;
        var handGroup = (RemoveExtension(handTexture) ?? handTexture)[4..];
        return new NativeAppearanceChoice(item, texture, bodyType, $"{item},BODY={texture}", handGroup);
    }

    private static string ExtractID(string item)
    {
        var underscore = item.IndexOf('_');
        return underscore < 0 ? item : item[..underscore];
    }

    private static string? RemoveExtension(string? name)
    {
        if (name == null) return null;
        var extension = name.LastIndexOf('.');
        return extension < 0 ? name : name[..extension];
    }

    private static bool Same(string left, string right) => string.Equals(left, right, StringComparison.OrdinalIgnoreCase);
}
