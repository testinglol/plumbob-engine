using System.Text.Json;
using System.Text.Json.Serialization;
using FSO.Vitaboy;
using Microsoft.Xna.Framework;

internal static class NativeAnimationAuthor
{
    internal sealed record Document
    {
        public int SchemaVersion { get; init; } = 1;
        public required string PackID { get; init; }
        public string? Name { get; init; }
        public string Version { get; init; } = "0.1.0";
        public string Encoding { get; init; } = "bcf";
        public required Clip[] Animations { get; init; }
    }
    internal sealed record Clip
    {
        public required string Name { get; init; }
        public required int Frames { get; init; }
        public bool Moving { get; init; }
        public float Distance { get; init; }
        public required Track[] Tracks { get; init; }
    }
    internal sealed record Track
    {
        public required string Bone { get; init; }
        public float[][]? Translations { get; init; }
        public float[][]? Rotations { get; init; }
        public Dictionary<string, string>[] Properties { get; init; } = [];
        public Event[] Events { get; init; } = [];
    }
    internal sealed record Event
    {
        public required int Time { get; init; }
        public required Dictionary<string, string> Properties { get; init; }
    }
    private static readonly JsonSerializerOptions Json = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        UnmappedMemberHandling = JsonUnmappedMemberHandling.Disallow,
        WriteIndented = true
    };

    internal static object Compile(string source, string destination)
    {
        if (new FileInfo(source).Length > 32 * 1024 * 1024) throw new InvalidDataException("Animation source exceeds size limit");
        var input = File.ReadAllBytes(source);
        var document = JsonSerializer.Deserialize<Document>(input, Json) ?? throw new InvalidDataException("Invalid animation document");
        return Compile(document, destination);
    }

    internal static object Compile(Document document, string destination)
    {
        var output = Path.GetFullPath(destination);
        if (Directory.Exists(output) || File.Exists(output)) throw new InvalidDataException("Animation output already exists");
        if (document.SchemaVersion != 1 || !Identifier(document.PackID, false) || string.IsNullOrWhiteSpace(document.Version) ||
            (document.Name != null && string.IsNullOrWhiteSpace(document.Name)) ||
            document.Encoding is not ("bcf" or "cmx") || document.Animations == null || document.Animations.Length is < 1 or > 256)
            throw new InvalidDataException("Invalid animation pack specification");
        var names = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        var compiled = new List<(Animation Animation, CFP Curves)>();
        foreach (var clip in document.Animations)
        {
            if (clip == null || !Identifier(clip.Name, true) || !names.Add(clip.Name) || clip.Frames is < 1 or > 10000 ||
                !float.IsFinite(clip.Distance) || clip.Tracks == null || clip.Tracks.Length is < 1 or > 512)
                throw new InvalidDataException("Invalid or duplicate animation clip");
            var translations = new List<Vector3>();
            var rotations = new List<Quaternion>();
            var motions = new List<AnimationMotion>();
            var bones = new HashSet<string>(StringComparer.Ordinal);
            var duration = clip.Frames * 1000f / 30;
            foreach (var track in clip.Tracks)
            {
                if (track == null || !bones.Add(track.Bone) || string.IsNullOrWhiteSpace(track.Bone)) throw new InvalidDataException("Invalid or duplicate motion bone");
                ValidateString(track.Bone, document.Encoding);
                var motion = new AnimationMotion
                {
                    BoneName = track.Bone, FrameCount = (uint)clip.Frames, Duration = duration,
                    HasTranslation = track.Translations != null, HasRotation = track.Rotations != null,
                    FirstTranslationIndex = translations.Count, FirstRotationIndex = rotations.Count,
                    Properties = (track.Properties ?? throw new InvalidDataException("Null motion properties")).Select(properties => Properties(properties, document.Encoding)).ToArray(),
                    TimeProperties = [new TimePropertyList { Items = (track.Events ?? throw new InvalidDataException("Null animation events")).Select(item =>
                    {
                        if (item == null || item.Time < 0 || item.Time >= duration) throw new InvalidDataException("Animation event is outside clip duration");
                        return new TimePropertyListItem { ID = item.Time, Properties = Properties(item.Properties, document.Encoding) };
                    }).ToArray() }]
                };
                if (track.Translations != null)
                {
                    ValidateSamples(track.Translations, clip.Frames, 3);
                    translations.AddRange(track.Translations.Select(value => new Vector3(value[0], value[1], value[2])));
                }
                if (track.Rotations != null)
                {
                    ValidateSamples(track.Rotations, clip.Frames, 4);
                    foreach (var value in track.Rotations)
                    {
                        var rotation = new Quaternion(value[0], value[1], value[2], value[3]);
                        var length = rotation.LengthSquared();
                        if (!float.IsFinite(length) || Math.Abs(length - 1) > 0.01f) throw new InvalidDataException("Animation rotations must be unit quaternions");
                        rotations.Add(rotation);
                    }
                }
                if (translations.Count > CFP.MaximumVectors || rotations.Count > CFP.MaximumVectors) throw new InvalidDataException("Animation vector limit exceeded");
                motions.Add(motion);
            }
            var animation = new Animation
            {
                Name = clip.Name.ToLowerInvariant(), XSkillName = clip.Name.ToLowerInvariant(), Duration = duration,
                Distance = clip.Distance, IsMoving = (byte)(clip.Moving ? 1 : 0), NumFrames = clip.Frames,
                TranslationCount = (uint)translations.Count, RotationCount = (uint)rotations.Count,
                Translations = translations.ToArray(), Rotations = rotations.ToArray(), Motions = motions.ToArray()
            };
            var curves = new CFP();
            curves.CompressAnim(animation);
            compiled.Add((animation, curves));
        }
        var parent = Path.GetDirectoryName(output)!;
        Directory.CreateDirectory(parent);
        var staging = Path.Combine(parent, ".animation-" + Guid.NewGuid().ToString("N"));
        try
        {
            var resources = Path.Combine(staging, "files", "Downloads");
            Directory.CreateDirectory(resources);
            var metadata = document.PackID.ToLowerInvariant() + "." + document.Encoding;
            using (var stream = File.Create(Path.Combine(resources, metadata)))
                new BCF([], [], compiled.Select(item => item.Animation).ToArray()).Write(stream, document.Encoding == "cmx");
            foreach (var item in compiled) File.WriteAllBytes(Path.Combine(resources, item.Animation.XSkillName + ".cfp"), item.Curves.Data);
            var manifest = new
            {
                schemaVersion = 1, id = document.PackID, name = document.Name ?? document.PackID, version = document.Version,
                baseGameVersion = "1.90", dependencies = Array.Empty<object>(), overrides = Array.Empty<string>()
            };
            File.WriteAllText(Path.Combine(staging, "pack.json"), JsonSerializer.Serialize(manifest, Json));
            Directory.Move(staging, output);
            return new { pack = output, metadata = "Downloads/" + metadata, animations = compiled.Select(item => new
            {
                name = item.Animation.Name, frames = item.Animation.NumFrames, duration = item.Animation.Duration,
                translations = item.Animation.TranslationCount, rotations = item.Animation.RotationCount, curveBytes = item.Curves.Data.Length
            }).ToArray(), maximumChannelEncodingError = CFP.MaximumEncodingError };
        }
        finally { if (Directory.Exists(staging)) Directory.Delete(staging, true); }
    }

    private static bool Identifier(string value, bool underscore) => value != null && value.Length is >= 1 and <= 120 && char.IsAsciiLetterOrDigit(value[0]) &&
        value.All(character => char.IsAsciiLetterOrDigit(character) || character is '-' or '.' || (underscore && character == '_')) && value is not ("." or "..");

    private static void ValidateSamples(float[][] samples, int frames, int dimensions)
    {
        if (samples.Length != frames || samples.Any(value => value == null || value.Length != dimensions || value.Any(number => !float.IsFinite(number))))
            throw new InvalidDataException("Animation sample dimensions or frame count differ");
    }

    private static void ValidateString(string value, string encoding)
    {
        if (value == null || value.Contains('\n') || value.Contains('\r') || value.Contains('\0') || value.Length > 4096 ||
            (encoding == "bcf" && (value.Length > 255 || value.Any(character => character > 127))))
            throw new InvalidDataException("Animation string cannot be represented by its container encoding");
    }

    private static PropertyList Properties(Dictionary<string, string> values, string encoding)
    {
        if (values == null || values.Count > 1024) throw new InvalidDataException("Invalid animation properties");
        foreach (var pair in values) { ValidateString(pair.Key, encoding); ValidateString(pair.Value, encoding); }
        return new PropertyList { Items = [new PropertyListItem { KeyPairs = values.Select(pair => new KeyValuePair<string, string>(pair.Key, pair.Value)).ToList() }] };
    }
}
