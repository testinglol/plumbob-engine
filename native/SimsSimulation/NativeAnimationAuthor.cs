using System.Text.Json;
using System.Text.Json.Serialization;
using FSO.Files.FAR1;
using FSO.Files.Utils;
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
        public string? Skeleton { get; init; }
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

    internal static object Compile(string source, string destination, string? game = null)
    {
        if (new FileInfo(source).Length > 32 * 1024 * 1024) throw new InvalidDataException("Animation source exceeds size limit");
        var input = File.ReadAllBytes(source);
        var document = JsonSerializer.Deserialize<Document>(input, Json) ?? throw new InvalidDataException("Invalid animation document");
        return Compile(document, destination, game);
    }

    /// <summary>
    /// Compiles the document. With the installed game folder, every clip's bones are checked against its installed
    /// skeletons: against the named <c>skeleton</c> when the document gives one, otherwise each clip must fit at least one
    /// skeleton. A bone name the skeleton lacks would otherwise be skipped silently when the clip plays.
    /// </summary>
    internal static object Compile(Document document, string destination, string? game = null)
    {
        if (document.Skeleton != null && game == null)
            throw new InvalidDataException("Checking bones against skeleton " + document.Skeleton + " needs the installed game folder");
        var skeletons = game == null ? null : InstalledSkeletons(game);
        Skeleton? target = null;
        if (skeletons != null && document.Skeleton != null &&
            !skeletons.TryGetValue(document.Skeleton, out target))
            throw new InvalidDataException($"Unknown skeleton {document.Skeleton}; installed skeletons are {string.Join(", ", skeletons.Keys.Order(StringComparer.Ordinal))}");
        var fitted = new List<string?>();
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
            fitted.Add(skeletons == null ? null : FitSkeleton(clip, target, skeletons));
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
            return new { pack = output, metadata = "Downloads/" + metadata, animations = compiled.Select((item, index) => new
            {
                name = item.Animation.Name, skeleton = fitted[index], frames = item.Animation.NumFrames, duration = item.Animation.Duration,
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

    private static string FitSkeleton(Clip clip, Skeleton? target, Dictionary<string, Skeleton> skeletons)
    {
        static string[] Missing(Clip clip, Skeleton skeleton) =>
            clip.Tracks.Select(track => track.Bone).Where(bone => !skeleton.Bones.Any(item => item.Name == bone)).ToArray();
        if (target != null)
        {
            var missing = Missing(clip, target);
            if (missing.Length > 0)
                throw new InvalidDataException($"Clip {clip.Name} animates bones that skeleton {target.Name} lacks: {string.Join(", ", missing)}");
            return target.Name;
        }
        var fit = skeletons.Values.OrderBy(skeleton => skeleton.Name, StringComparer.Ordinal).FirstOrDefault(skeleton => Missing(clip, skeleton).Length == 0);
        if (fit != null) return fit.Name;
        var unknown = clip.Tracks.Select(track => track.Bone).Where(bone => !skeletons.Values.Any(skeleton => skeleton.Bones.Any(item => item.Name == bone))).Distinct().ToArray();
        throw new InvalidDataException(unknown.Length > 0
            ? $"Clip {clip.Name} animates bones that no installed skeleton has: {string.Join(", ", unknown)}"
            : $"Clip {clip.Name} animates bones from more than one skeleton; name its skeleton to see which bones it lacks");
    }

    /// <summary>The skeletons defined by the installed BCF and CMX files, loose or in FAR archives, by case-insensitive name.</summary>
    internal static Dictionary<string, Skeleton> InstalledSkeletons(string game)
    {
        var skeletons = new Dictionary<string, Skeleton>(StringComparer.OrdinalIgnoreCase);
        void Add(string name, byte[] data)
        {
            var cmx = name.EndsWith(".cmx", StringComparison.OrdinalIgnoreCase);
            if (!cmx && !name.EndsWith(".bcf", StringComparison.OrdinalIgnoreCase)) return;
            try
            {
                using var stream = new MemoryStream(data);
                using var io = cmx ? new BCFReadString(stream, true) : (BCFReadProxy)IoBuffer.FromStream(stream, ByteOrder.LITTLE_ENDIAN);
                var count = io.ReadInt32();
                if (count is < 1 or > 64) return;
                for (var index = 0; index < count; index++)
                {
                    var skeleton = new Skeleton();
                    skeleton.Read(io, true);
                    if (!string.IsNullOrEmpty(skeleton.Name)) skeletons.TryAdd(skeleton.Name, skeleton);
                }
            }
            catch (Exception error) when (error is IOException or FormatException or ArgumentException or IndexOutOfRangeException or OverflowException or InvalidDataException)
            {
                // Files that are not readable animation containers define no skeletons.
            }
        }
        foreach (var path in Directory.EnumerateFiles(game, "*", SearchOption.AllDirectories))
        {
            if (path.EndsWith(".far", StringComparison.OrdinalIgnoreCase))
            {
                FAR1Archive archive;
                try { archive = new FAR1Archive(path, false); _ = archive.GetAllFarEntries(); }
                catch (Exception) { archive = new FAR1Archive(path, true); }
                try
                {
                    foreach (var entry in archive.GetAllFarEntries())
                        if (entry.Filename.EndsWith(".cmx", StringComparison.OrdinalIgnoreCase) || entry.Filename.EndsWith(".bcf", StringComparison.OrdinalIgnoreCase))
                            Add(entry.Filename, archive.GetEntry(entry));
                }
                finally { archive.Close(); }
            }
            else if (new FileInfo(path).Length < 64 * 1024 * 1024) Add(path, File.ReadAllBytes(path));
        }
        if (skeletons.Count == 0) throw new InvalidDataException($"No skeletons are installed under {game}");
        return skeletons;
    }
}
