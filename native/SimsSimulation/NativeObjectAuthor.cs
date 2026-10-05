using System.Buffers.Binary;
using System.Reflection;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using FSO.Files.FAR1;
using FSO.Files.Formats.IFF;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Engine;

/// <summary>
/// Compiles a JSON object description into a pack holding new IFF objects. Each object starts from an installed original
/// object (its sprites, draw groups, slots and behaviors) and gets its own GUIDs, catalog text, price, definition fields,
/// SimAntics behaviors and interactions. Template chunks the document does not touch are copied byte for byte; changed
/// definition fields are patched in place so every other OBJD field keeps its original value.
/// </summary>
internal static class NativeObjectAuthor
{
    internal sealed record Document
    {
        public int SchemaVersion { get; init; } = 1;
        public required string PackID { get; init; }
        public string? Name { get; init; }
        public string Version { get; init; } = "0.1.0";
        public required ObjectSpec[] Objects { get; init; }
    }

    internal sealed record ObjectSpec
    {
        /// <summary>The IFF file name inside the pack, without extension.</summary>
        public required string File { get; init; }
        /// <summary>An original object file, such as "flamingo.iff", looked up in GameData/Objects.</summary>
        public required string Template { get; init; }
        /// <summary>The GUID of the original object to start from when the template file holds several.</summary>
        public JsonElement? TemplateObject { get; init; }
        /// <summary>The GUID of the lead definition; allocate it with the pack tool's --reserve-object-guid.</summary>
        public required JsonElement Guid { get; init; }
        /// <summary>GUIDs for the template's other definitions (multi-tile parts), in chunk order.</summary>
        public JsonElement[] TileGuids { get; init; } = [];
        public string? CatalogName { get; init; }
        public string? Description { get; init; }
        public int? Price { get; init; }
        /// <summary>Definition fields by their OBJD name, such as RatingFun or LotCategories.</summary>
        public Dictionary<string, int> Fields { get; init; } = [];
        public bool ReplaceInteractions { get; init; }
        /// <summary>Shifts the colors of the template's sprite palettes and catalog icon.</summary>
        public Recolor? Recolor { get; init; }
        /// <summary>Repainted sprite frames, as exported by --export-object-sprites.</summary>
        public SpriteImage[] Sprites { get; init; } = [];
        public Behavior[] Behaviors { get; init; } = [];
        public Interaction[] Interactions { get; init; } = [];
    }

    internal sealed record Behavior
    {
        public required string Name { get; init; }
        public int Args { get; init; }
        public int Locals { get; init; }
        public required Instruction[] Instructions { get; init; }
    }

    internal sealed record Instruction
    {
        public string? Label { get; init; }
        /// <summary>A primitive by its engine name, such as "expression" or "animate sim".</summary>
        public string? Primitive { get; init; }
        /// <summary>A behavior to call: one of this object's behaviors by name, or a BHAV ID.</summary>
        public JsonElement? Call { get; init; }
        public short[]? Args { get; init; }
        /// <summary>A raw opcode with <see cref="OperandHex"/>, for primitives without an operand model.</summary>
        public int? Opcode { get; init; }
        public string? OperandHex { get; init; }
        public Dictionary<string, JsonElement>? Operand { get; init; }
        public JsonElement? True { get; init; }
        public JsonElement? False { get; init; }
    }

    internal sealed record Interaction
    {
        public required string Name { get; init; }
        public required JsonElement Action { get; init; }
        public JsonElement? Test { get; init; }
        public int AutonomyThreshold { get; init; }
        public Dictionary<string, Advertisement> Advertisements { get; init; } = [];
        public bool AllowVisitors { get; init; } = true;
        public bool AllowChildren { get; init; } = true;
        public bool AllowAdults { get; init; } = true;
        public bool Joinable { get; init; }
        public bool RunImmediately { get; init; }
        public bool Debug { get; init; }
    }

    internal sealed record Recolor
    {
        /// <summary>Degrees added to the hue.</summary>
        public double Hue { get; init; }
        public double Saturation { get; init; } = 1;
        public double Lightness { get; init; } = 1;
        /// <summary>Only colors whose hue lies in this range, in degrees; the range may wrap through 0.</summary>
        public double[]? HueRange { get; init; }
        /// <summary>Colors with less saturation, such as grays and wood, keep their color.</summary>
        public double MinimumSaturation { get; init; }
    }

    internal sealed record SpriteImage
    {
        /// <summary>The SPR2 chunk ID.</summary>
        public int Sprite { get; init; }
        public int Frame { get; init; }
        /// <summary>A PNG the size of the original frame, relative to the document.</summary>
        public required string Image { get; init; }
        /// <summary>An optional grayscale PNG of depth values (0 nearest); without it, painted pixels take the nearest original depth.</summary>
        public string? Depth { get; init; }
    }

    internal sealed record Advertisement
    {
        public int Min { get; init; }
        public int Max { get; init; }
        public int Personality { get; init; }
    }

    private sealed class Chunk
    {
        public required string Type;
        public ushort Id;
        public ushort Flags;
        public required string Label;
        public required byte[] Data;
    }

    private static readonly JsonSerializerOptions Json = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        UnmappedMemberHandling = JsonUnmappedMemberHandling.Disallow,
        WriteIndented = true
    };

    private const byte PointerError = 253, PointerTrue = 254, PointerFalse = 255;

    internal static object Compile(string source, string game, string destination)
    {
        if (new FileInfo(source).Length > 8 * 1024 * 1024) throw new InvalidDataException("Object source exceeds size limit");
        var document = JsonSerializer.Deserialize<Document>(File.ReadAllBytes(source), Json) ?? throw new InvalidDataException("Invalid object document");
        return Compile(document, game, destination, Path.GetDirectoryName(Path.GetFullPath(source))!);
    }

    internal static object Compile(Document document, string game, string destination, string? baseDirectory = null)
    {
        var output = Path.GetFullPath(destination);
        if (Directory.Exists(output) || File.Exists(output)) throw new InvalidDataException("Object pack output already exists");
        if (document.SchemaVersion != 1 || !Identifier(document.PackID) || string.IsNullOrWhiteSpace(document.Version) ||
            (document.Name != null && string.IsNullOrWhiteSpace(document.Name)) || document.Objects == null || document.Objects.Length is < 1 or > 64)
            throw new InvalidDataException("Invalid object pack specification");
        if (document.Objects.Select(item => item.File?.ToLowerInvariant()).Distinct().Count() != document.Objects.Length)
            throw new InvalidDataException("Object file names must be unique");
        VMContext.InitVMConfig(true);
        IffFile.TargetTS1 = true;
        var templates = new Templates(Path.GetFullPath(game));
        var guids = new HashSet<uint>();
        var compiled = new List<(string File, byte[] Data, object Summary)>();
        foreach (var spec in document.Objects)
        {
            if (!Identifier(spec.File)) throw new InvalidDataException($"Invalid object file name {spec.File}");
            var (data, summary) = CompileObject(spec, templates.Read(spec.Template), guids, baseDirectory);
            compiled.Add((spec.File.ToLowerInvariant() + ".iff", data, summary));
        }

        var parent = Path.GetDirectoryName(output)!;
        Directory.CreateDirectory(parent);
        var staging = Path.Combine(parent, ".object-" + System.Guid.NewGuid().ToString("N"));
        try
        {
            var folder = Path.Combine(staging, "files", "Downloads", document.PackID.ToLowerInvariant());
            Directory.CreateDirectory(folder);
            foreach (var item in compiled) File.WriteAllBytes(Path.Combine(folder, item.File), item.Data);
            var manifest = new
            {
                schemaVersion = 1, id = document.PackID, name = document.Name ?? document.PackID, version = document.Version,
                baseGameVersion = "1.90", dependencies = Array.Empty<object>(), overrides = Array.Empty<string>()
            };
            File.WriteAllText(Path.Combine(staging, "pack.json"), JsonSerializer.Serialize(manifest, Json));
            Directory.Move(staging, output);
        }
        finally { if (Directory.Exists(staging)) Directory.Delete(staging, true); }
        return new
        {
            pack = output,
            objects = compiled.Select(item => item.Summary).ToArray()
        };
    }

    private static (byte[] Data, object Summary) CompileObject(ObjectSpec spec, byte[] template, HashSet<uint> guids, string? baseDirectory)
    {
        var chunks = ReadIff(template);
        var (lead, definitions) = SelectObject(spec, chunks);
        var tileGuids = (spec.TileGuids ?? []).Select(value => ParseGuid(value, "tile GUID")).ToArray();
        if (tileGuids.Length != definitions.Count - 1)
            throw new InvalidDataException($"Template {spec.Template} has {definitions.Count} definitions; give tileGuids for the {definitions.Count - 1} besides the lead");
        var assigned = new Dictionary<Chunk, uint> { [lead] = ParseGuid(spec.Guid, "GUID") };
        foreach (var (chunk, guid) in definitions.Where(chunk => chunk != lead).Zip(tileGuids)) assigned[chunk] = guid;
        foreach (var guid in assigned.Values)
            if (guid == 0 || !guids.Add(guid)) throw new InvalidDataException($"Object GUID 0x{guid:X8} is zero or used twice");

        var price = spec.Price;
        if (price is < 0 or > ushort.MaxValue) throw new InvalidDataException("Object price must be between 0 and 65535");
        foreach (var name in spec.Fields.Keys)
            if (name is "GUID1" or "GUID2" or "Price" or "TreeTableID" or "CatalogStringsID" or "MasterID" or "SubIndex" || FieldIndex(name) < 0)
                throw new InvalidDataException($"Definition field {name} cannot be set");
        foreach (var definition in definitions)
        {
            var guid = assigned[definition];
            WriteField(definition, "GUID1", (ushort)(guid & 0xFFFF));
            WriteField(definition, "GUID2", (ushort)(guid >> 16));
            if (definition == lead && price.HasValue) WriteField(definition, "Price", (ushort)price.Value);
            if (definition == lead)
                foreach (var (name, value) in spec.Fields)
                {
                    if (value is < short.MinValue or > ushort.MaxValue) throw new InvalidDataException($"Definition field {name} is out of range");
                    WriteField(definition, name, (ushort)value);
                }
        }
        if (spec.CatalogName != null) lead.Label = Label(spec.CatalogName);

        // Catalog text: string 0 is the name and 1 the description, in every language the template carries.
        if (spec.CatalogName != null || spec.Description != null)
        {
            var catalogID = ReadField(lead, "CatalogStringsID");
            var catalog = chunks.FirstOrDefault(chunk => chunk.Type == "CTSS" && chunk.Id == catalogID)
                ?? throw new InvalidDataException($"Template {spec.Template} has no catalog strings");
            var strings = Parse<CTSS>(catalog);
            if (spec.CatalogName != null) Set(strings, 0, Text(spec.CatalogName, "catalog name"));
            if (spec.Description != null) Set(strings, 1, Text(spec.Description, "description"));
            catalog.Data = Serialize(strings);
        }

        // Repainted frames come first so a recolor also applies to them.
        var painted = (spec.Sprites ?? []).Length > 0 ? ApplySprites(spec.Sprites!, chunks, baseDirectory) : null;
        var recolored = spec.Recolor is { } recolor ? ApplyRecolor(recolor, chunks, ReadField(lead, "CatalogStringsID")) : null;

        // Behaviors take free private IDs; calls between them resolve by name.
        var behaviorIDs = new Dictionary<string, ushort>(StringComparer.Ordinal);
        var nextID = (ushort)Math.Max(0x1000, chunks.Where(chunk => chunk.Type == "BHAV" && chunk.Id is >= 0x1000 and < 0x2000)
            .Select(chunk => chunk.Id + 1).DefaultIfEmpty(0x1000).Max());
        foreach (var behavior in spec.Behaviors)
        {
            if (string.IsNullOrWhiteSpace(behavior.Name) || behavior.Name.Length > 60 || !behaviorIDs.TryAdd(behavior.Name, nextID))
                throw new InvalidDataException($"Behavior names must be unique, nonempty and at most 60 characters: {behavior.Name}");
            if (nextID >= 0x2000) throw new InvalidDataException("No private behavior IDs are left in the template");
            nextID++;
        }
        var existing = chunks.Where(chunk => chunk.Type == "BHAV").Select(chunk => chunk.Id).ToHashSet();
        var behaviors = new List<object>();
        foreach (var behavior in spec.Behaviors)
        {
            var bhav = Assemble(behavior, behaviorIDs, existing);
            chunks.Add(new Chunk { Type = "BHAV", Id = behaviorIDs[behavior.Name], Flags = 0x10, Label = Label(behavior.Name), Data = Serialize(bhav) });
            behaviors.Add(new { name = behavior.Name, id = behaviorIDs[behavior.Name], instructions = bhav.Instructions.Length });
        }

        var interactions = new List<object>();
        if (spec.Interactions.Length > 0 || spec.ReplaceInteractions)
        {
            var tableID = ReadField(lead, "TreeTableID");
            var tableChunk = chunks.FirstOrDefault(chunk => chunk.Type == "TTAB" && chunk.Id == tableID);
            var namesChunk = chunks.FirstOrDefault(chunk => chunk.Type == "TTAs" && chunk.Id == tableID);
            if (tableChunk == null)
            {
                // Some decorative templates have no tree table; give every definition a new one.
                tableID = (ushort)Math.Max(0x80, chunks.Where(chunk => chunk.Type is "TTAB" or "TTAs").Select(chunk => chunk.Id + 1).DefaultIfEmpty(0x80).Max());
                foreach (var definition in definitions) WriteField(definition, "TreeTableID", tableID);
                tableChunk = new Chunk { Type = "TTAB", Id = tableID, Flags = 0x10, Label = lead.Label, Data = [] };
                chunks.Add(tableChunk);
            }
            if (namesChunk == null)
            {
                namesChunk = new Chunk { Type = "TTAs", Id = tableID, Flags = 0x10, Label = lead.Label, Data = [] };
                chunks.Add(namesChunk);
            }
            var table = tableChunk.Data.Length == 0 ? new TTAB() : Parse<TTAB>(tableChunk);
            var names = namesChunk.Data.Length == 0 ? new TTAs() : Parse<TTAs>(namesChunk);
            var entries = spec.ReplaceInteractions ? new List<TTABInteraction>() : table.Interactions.ToList();
            foreach (var interaction in spec.Interactions)
            {
                var index = (uint)Math.Max(names.Length, entries.Select(entry => (int)entry.TTAIndex + 1).DefaultIfEmpty(0).Max());
                var entry = new TTABInteraction
                {
                    ActionFunction = Resolve(interaction.Action, behaviorIDs, existing, "action"),
                    TestFunction = interaction.Test is { } test ? Resolve(test, behaviorIDs, existing, "test") : (ushort)0,
                    TTAIndex = index,
                    AutonomyThreshold = (uint)Math.Clamp(interaction.AutonomyThreshold, 0, 100),
                    AttenuationCode = 0,
                    MotiveEntries = Enumerable.Range(0, 16).Select(motive => new TTABMotiveEntry { MotiveIndex = motive }).ToArray(),
                };
                entry.TS1AllowAdults = interaction.AllowAdults;
                entry.TS1AllowChild = interaction.AllowChildren;
                entry.TS1AllowDemoChild = interaction.AllowChildren;
                if (interaction.AllowVisitors) entry.Flags |= TTABFlags.AllowVisitors;
                if (interaction.Joinable) entry.Flags |= TTABFlags.Joinable;
                if (interaction.RunImmediately) entry.Flags |= TTABFlags.RunImmediately;
                if (interaction.Debug) entry.Flags |= TTABFlags.Debug;
                foreach (var (motive, advertisement) in interaction.Advertisements)
                {
                    if (!Enum.TryParse<FSO.SimAntics.Model.VMMotive>(motive, true, out var index16) || (int)index16 is < 0 or > 15)
                        throw new InvalidDataException($"Unknown advertised motive {motive}");
                    if (advertisement.Min is < -100 or > 100 || advertisement.Max is < -1000 or > 1000 || advertisement.Personality is < 0 or > 255)
                        throw new InvalidDataException($"Advertisement for {motive} is out of range");
                    entry.MotiveEntries[(int)index16] = new TTABMotiveEntry
                    {
                        MotiveIndex = (int)index16, EffectRangeMinimum = (short)advertisement.Min,
                        EffectRangeDelta = (short)advertisement.Max, PersonalityModifier = (ushort)advertisement.Personality
                    };
                }
                Set(names, (int)index, Text(interaction.Name, "interaction name"));
                entries.Add(entry);
                interactions.Add(new { name = interaction.Name, index, action = entry.ActionFunction, test = entry.TestFunction });
            }
            if (entries.Count > 255) throw new InvalidDataException("An object can have at most 255 interactions");
            table.Interactions = entries.ToArray();
            tableChunk.Data = Serialize(table);
            namesChunk.Data = Serialize(names);
        }

        var summary = new
        {
            file = spec.File.ToLowerInvariant() + ".iff",
            template = spec.Template,
            guid = assigned[lead],
            tileGuids,
            catalogName = spec.CatalogName,
            price = ReadField(lead, "Price"),
            painted,
            recolored,
            behaviors,
            interactions
        };
        return (WriteIff(chunks), summary);
    }

    /// <summary>
    /// Picks the template object to copy: its lead definition and, for a multi-tile object, every part sharing its master
    /// ID. Definitions and catalog strings of the file's other objects are dropped so their original GUIDs never load twice.
    /// </summary>
    private static (Chunk Lead, List<Chunk> Definitions) SelectObject(ObjectSpec spec, List<Chunk> chunks)
    {
        var all = chunks.Where(chunk => chunk.Type == "OBJD").ToList();
        if (all.Count == 0) throw new InvalidDataException($"Template {spec.Template} holds no object definition");
        uint Guid(Chunk chunk) => ReadField(chunk, "GUID1") | (uint)ReadField(chunk, "GUID2") << 16;
        bool Master(Chunk chunk) => ReadField(chunk, "SubIndex") == 0xFFFF;
        List<Chunk> Group(Chunk lead) => Master(lead) ? all.Where(chunk => ReadField(chunk, "MasterID") == ReadField(lead, "MasterID")).ToList() : [lead];
        var leads = all.Where(chunk => Master(chunk) || ReadField(chunk, "MasterID") == 0).ToList();
        Chunk selected;
        if (spec.TemplateObject is { } wanted)
        {
            var guid = ParseGuid(wanted, "template object");
            selected = leads.FirstOrDefault(chunk => Guid(chunk) == guid)
                ?? throw new InvalidDataException($"Template {spec.Template} has no object 0x{guid:X8}; it has {string.Join(", ", leads.Select(chunk => $"0x{Guid(chunk):X8} ({chunk.Label})"))}");
        }
        else if (leads.Count == 1) selected = leads[0];
        else throw new InvalidDataException($"Template {spec.Template} holds several objects; choose one with templateObject: {string.Join(", ", leads.Select(chunk => $"0x{Guid(chunk):X8} ({chunk.Label})"))}");
        var definitions = Group(selected);
        // Parts are listed in their original chunk order, lead first.
        definitions.Remove(selected);
        definitions.Insert(0, selected);
        var catalogs = definitions.Select(chunk => ReadField(chunk, "CatalogStringsID")).ToHashSet();
        chunks.RemoveAll(chunk => (chunk.Type == "OBJD" && !definitions.Contains(chunk)) || (chunk.Type == "CTSS" && !catalogs.Contains(chunk.Id)));
        return (selected, definitions);
    }

    private static BHAV Assemble(Behavior behavior, Dictionary<string, ushort> behaviorIDs, HashSet<ushort> existing)
    {
        if (behavior.Instructions == null || behavior.Instructions.Length is < 1 or > 253)
            throw new InvalidDataException($"Behavior {behavior.Name} needs 1 to 253 instructions");
        if (behavior.Args is < 0 or > 4 || behavior.Locals is < 0 or > 255)
            throw new InvalidDataException($"Behavior {behavior.Name} takes 0 to 4 arguments and 0 to 255 locals");
        var labels = new Dictionary<string, int>(StringComparer.Ordinal);
        for (var index = 0; index < behavior.Instructions.Length; index++)
            if (behavior.Instructions[index].Label is { } label && !labels.TryAdd(label, index))
                throw new InvalidDataException($"Behavior {behavior.Name} repeats label {label}");
        var instructions = new BHAVInstruction[behavior.Instructions.Length];
        for (var index = 0; index < instructions.Length; index++)
        {
            var source = behavior.Instructions[index];
            var where = $"{behavior.Name} instruction {index}";
            var forms = (source.Primitive != null ? 1 : 0) + (source.Call != null ? 1 : 0) + (source.Opcode != null ? 1 : 0);
            if (forms != 1) throw new InvalidDataException($"{where} needs exactly one of primitive, call or opcode");
            ushort opcode;
            var operand = new byte[8];
            if (source.Call is { } call)
            {
                opcode = Resolve(call, behaviorIDs, existing, where);
                if (source.Operand != null || source.OperandHex != null) throw new InvalidDataException($"{where}: a call takes args, not an operand");
                var args = source.Args ?? [];
                if (args.Length > 4) throw new InvalidDataException($"{where}: a call takes at most four arguments");
                for (var argument = 0; argument < args.Length; argument++) BinaryPrimitives.WriteInt16LittleEndian(operand.AsSpan(argument * 2), args[argument]);
            }
            else if (source.Primitive is { } name)
            {
                var registration = VMContext.Primitives.FirstOrDefault(item => item != null && string.Equals(item.Name, name, StringComparison.OrdinalIgnoreCase))
                    ?? throw new InvalidDataException($"{where}: unknown primitive {name}");
                if (source.Args != null) throw new InvalidDataException($"{where}: only calls take args");
                opcode = registration.Opcode;
                if (source.OperandHex != null) operand = Hex(source.OperandHex, where);
                else if (registration.OperandModel != null) operand = Operand(registration.OperandModel, source.Operand ?? [], where);
                else if (source.Operand is { Count: > 0 }) throw new InvalidDataException($"{where}: {name} has no operand model; use operandHex");
            }
            else
            {
                if (source.Opcode is not (>= 0 and < 256) || VMContext.Primitives[source.Opcode.Value] == null)
                    throw new InvalidDataException($"{where}: opcode must name an installed primitive");
                if (source.Operand != null || source.Args != null) throw new InvalidDataException($"{where}: a raw opcode takes operandHex");
                opcode = (ushort)source.Opcode.Value;
                if (source.OperandHex != null) operand = Hex(source.OperandHex, where);
            }
            instructions[index] = new BHAVInstruction
            {
                Opcode = opcode,
                TruePointer = Pointer(source.True, index, instructions.Length, labels, true, where),
                FalsePointer = Pointer(source.False, index, instructions.Length, labels, false, where),
                Operand = operand
            };
        }
        return new BHAV { Instructions = instructions, Type = 0, Args = (byte)behavior.Args, Locals = (ushort)behavior.Locals, Version = 0 };
    }

    /// <summary>
    /// Replaces sprite frames with painted PNGs. Every frame of an edited SPR2 chunk is quantized together into one new
    /// palette, because TS1 sprites share their chunk's palette; the original palette stays for the chunks that still use it.
    /// </summary>
    private static object ApplySprites(SpriteImage[] images, List<Chunk> chunks, string? baseDirectory)
    {
        if (images.Length > 4096) throw new InvalidDataException("Too many sprite images");
        if (baseDirectory == null) throw new InvalidDataException("Sprite images need a document directory");
        var root = Path.GetFullPath(baseDirectory);
        byte[] Load(string relative, string what)
        {
            if (string.IsNullOrWhiteSpace(relative) || Path.IsPathRooted(relative)) throw new InvalidDataException($"{what} must be a path relative to the document");
            var path = Path.GetFullPath(Path.Combine(root, relative));
            if (!path.StartsWith(root.TrimEnd(Path.DirectorySeparatorChar) + Path.DirectorySeparatorChar, StringComparison.Ordinal))
                throw new InvalidDataException($"{what} {relative} is outside the document directory");
            if (!File.Exists(path)) throw new InvalidDataException($"{what} {relative} does not exist");
            if (new FileInfo(path).Length > 32 * 1024 * 1024) throw new InvalidDataException($"{what} {relative} exceeds size limit");
            return File.ReadAllBytes(path);
        }
        var palettes = new List<object>();
        var nextPalette = chunks.Where(chunk => chunk.Type == "PALT").Select(chunk => chunk.Id + 1).DefaultIfEmpty(1).Max();
        foreach (var group in images.GroupBy(image => image.Sprite))
        {
            var chunk = chunks.FirstOrDefault(chunk => chunk.Type == "SPR2" && chunk.Id == group.Key)
                ?? throw new InvalidDataException($"The template has no sprite {group.Key}");
            var (_, frames) = NativeSpriteArt.DecodeSprite(chunk.Data, Palette(chunks));
            var replaced = new HashSet<int>();
            foreach (var image in group)
            {
                var where = $"sprite {image.Sprite} frame {image.Frame}";
                if (image.Frame < 0 || image.Frame >= frames.Count) throw new InvalidDataException($"Sprite {image.Sprite} has no frame {image.Frame}");
                if (!replaced.Add(image.Frame)) throw new InvalidDataException($"The document paints {where} twice");
                var frame = frames[image.Frame];
                var (width, height, rgba) = NativeSpriteArt.ReadPng(Load(image.Image, "Image"), image.Image);
                if (width != frame.Width || height != frame.Height)
                    throw new InvalidDataException($"{image.Image} is {width}x{height}; {where} is {frame.Width}x{frame.Height}");
                var (originalRgba, originalDepth) = (frame.Rgba, frame.Depth);
                frame.Rgba = rgba;
                frame.Depth = new byte[width * height];
                if (image.Depth is { } depthPath)
                {
                    var (depthWidth, depthHeight, depth) = NativeSpriteArt.ReadPng(Load(depthPath, "Depth"), depthPath);
                    if (depthWidth != width || depthHeight != height) throw new InvalidDataException($"{depthPath} does not match the size of {image.Image}");
                    for (var pixel = 0; pixel < width * height; pixel++) frame.Depth[pixel] = rgba[pixel * 4 + 3] == 0 ? (byte)255 : Math.Min(depth[pixel * 4], (byte)254);
                }
                else NativeSpriteArt.FillDepth(frame, originalDepth, originalRgba);
            }
            if (nextPalette > ushort.MaxValue) throw new InvalidDataException("No palette IDs are left in the template");
            var paletteID = (ushort)nextPalette++;
            var colors = NativeSpriteArt.Quantize(frames);
            var palette = new byte[16 + 768];
            BinaryPrimitives.WriteUInt32LittleEndian(palette, 1);
            BinaryPrimitives.WriteUInt32LittleEndian(palette.AsSpan(4), 256);
            colors.CopyTo(palette, 16);
            chunks.Add(new Chunk { Type = "PALT", Id = paletteID, Flags = 0x10, Label = chunk.Label, Data = palette });
            chunk.Data = NativeSpriteArt.EncodeSprite(frames, paletteID, colors);
            palettes.Add(new { sprite = group.Key, frames = replaced.Order().ToArray(), palette = paletteID });
        }
        return palettes;
    }

    private static Func<ushort, byte[]?> Palette(List<Chunk> chunks) => id =>
    {
        var chunk = chunks.FirstOrDefault(chunk => chunk.Type == "PALT" && chunk.Id == id);
        if (chunk == null || chunk.Data.Length < 16) return null;
        var colors = new byte[768];
        var count = (int)Math.Min(Math.Min(BitConverter.ToUInt32(chunk.Data, 4), 256u), (uint)(chunk.Data.Length - 16) / 3);
        Array.Copy(chunk.Data, 16, colors, 0, count * 3);
        return colors;
    };

    /// <summary>
    /// Writes every SPR2 frame of an original object file as a color PNG and a grayscale depth PNG, with a sprites.json
    /// manifest naming the draw groups and objects that use each frame. Paint the color PNGs and list them in an object's
    /// "sprites" to compile them back.
    /// </summary>
    internal static object ExportSprites(string template, string game, string destination)
    {
        var output = Path.GetFullPath(destination);
        if (Directory.Exists(output) && Directory.EnumerateFileSystemEntries(output).Any()) throw new InvalidDataException("Sprite export directory is not empty");
        VMContext.InitVMConfig(true);
        IffFile.TargetTS1 = true;
        var chunks = ReadIff(new Templates(Path.GetFullPath(game)).Read(template));
        Directory.CreateDirectory(output);
        var usage = new Dictionary<(uint, uint), List<object>>();
        foreach (var chunk in chunks.Where(chunk => chunk.Type == "DGRP"))
        {
            DGRP group;
            try { group = Parse<DGRP>(chunk); } catch (Exception) { continue; }
            foreach (var image in group.Images ?? [])
            foreach (var sprite in image.Sprites ?? [])
            {
                var key = (sprite.SpriteID, sprite.SpriteFrameIndex);
                if (!usage.TryGetValue(key, out var list)) usage[key] = list = [];
                list.Add(new { group = chunk.Id, direction = image.Direction, zoom = image.Zoom });
            }
        }
        var sprites = new List<object>();
        var stem = Path.GetFileNameWithoutExtension(template).ToLowerInvariant();
        foreach (var chunk in chunks.Where(chunk => chunk.Type == "SPR2"))
        {
            var (_, frames) = NativeSpriteArt.DecodeSprite(chunk.Data, Palette(chunks));
            for (var index = 0; index < frames.Count; index++)
            {
                var frame = frames[index];
                if (frame.Width == 0 || frame.Height == 0) continue;
                var name = $"{stem}-{chunk.Id}-{index}";
                File.WriteAllBytes(Path.Combine(output, name + ".png"), NativeSpriteArt.WritePng(frame.Width, frame.Height, frame.Rgba, false));
                File.WriteAllBytes(Path.Combine(output, name + "-depth.png"), NativeSpriteArt.WritePng(frame.Width, frame.Height, frame.Depth, true));
                sprites.Add(new
                {
                    sprite = chunk.Id, frame = index, label = chunk.Label, width = frame.Width, height = frame.Height,
                    image = name + ".png", depth = name + "-depth.png",
                    usedBy = usage.GetValueOrDefault(((uint)chunk.Id, (uint)index)) ?? []
                });
            }
        }
        var objects = chunks.Where(chunk => chunk.Type == "OBJD").Select(chunk => new
        {
            guid = $"0x{ReadField(chunk, "GUID1") | (uint)ReadField(chunk, "GUID2") << 16:X8}", label = chunk.Label,
            groups = new[] { ReadField(chunk, "BaseGraphicID"), ReadField(chunk, "NumGraphics") }
        }).ToArray();
        var manifest = new { template, objects, sprites };
        File.WriteAllText(Path.Combine(output, "sprites.json"), JsonSerializer.Serialize(manifest, Json));
        return new { directory = output, objects = objects.Length, frames = sprites.Count };
    }

    /// <summary>Recolors every sprite palette (PALT) in the file and the lead's catalog icon. Sprites index into these
    /// palettes, so their shading, transparency and depth are unchanged. Pure magenta, the icon's transparent key, is kept.</summary>
    private static object ApplyRecolor(Recolor recolor, List<Chunk> chunks, ushort iconID)
    {
        if (!double.IsFinite(recolor.Hue) || recolor.Hue is < -360 or > 360 || !double.IsFinite(recolor.Saturation) || recolor.Saturation is < 0 or > 4 ||
            !double.IsFinite(recolor.Lightness) || recolor.Lightness is < 0 or > 4 || recolor.MinimumSaturation is < 0 or > 1 ||
            recolor.HueRange is { } range && (range.Length != 2 || range.Any(value => !double.IsFinite(value) || value is < 0 or > 360)))
            throw new InvalidDataException("Recolor takes hue -360..360, saturation and lightness 0..4, minimumSaturation 0..1 and a hueRange of two angles 0..360");
        var palettes = 0;
        var changed = 0;
        foreach (var chunk in chunks.Where(chunk => chunk.Type == "PALT"))
        {
            if (chunk.Data.Length < 16) throw new InvalidDataException($"Palette {chunk.Id} is truncated");
            var count = (int)Math.Min(BitConverter.ToUInt32(chunk.Data, 4), (uint)(chunk.Data.Length - 16) / 3);
            for (var index = 0; index < count; index++) changed += Shift(recolor, chunk.Data, 16 + index * 3, 0, 1, 2, false) ? 1 : 0;
            palettes++;
        }
        var icon = chunks.FirstOrDefault(chunk => chunk.Type == "BMP_" && chunk.Id == iconID);
        var iconColors = 0;
        if (icon != null && icon.Data.Length >= 54 && icon.Data[0] == 'B' && icon.Data[1] == 'M')
        {
            var data = icon.Data;
            var header = BitConverter.ToInt32(data, 14);
            var width = BitConverter.ToInt32(data, 18);
            var height = Math.Abs(BitConverter.ToInt32(data, 22));
            var bits = BitConverter.ToUInt16(data, 28);
            var compression = BitConverter.ToUInt32(data, 30);
            var pixels = BitConverter.ToInt32(data, 10);
            if (bits <= 8)
            {
                var used = BitConverter.ToInt32(data, 46);
                var entries = used > 0 ? used : 1 << bits;
                for (var index = 0; index < entries && 14 + header + index * 4 + 3 <= data.Length; index++)
                    iconColors += Shift(recolor, data, 14 + header + index * 4, 2, 1, 0, true) ? 1 : 0;
            }
            else if ((bits == 24 || bits == 32) && compression is 0 or 3 && width is > 0 and <= 512)
            {
                var stride = (width * bits / 8 + 3) & ~3;
                for (var y = 0; y < height; y++)
                for (var x = 0; x < width; x++)
                {
                    var offset = pixels + y * stride + x * bits / 8;
                    if (offset + 3 > data.Length) break;
                    iconColors += Shift(recolor, data, offset, 2, 1, 0, true) ? 1 : 0;
                }
            }
        }
        return new { palettes, paletteColors = changed, iconColors };
    }

    private static bool Shift(Recolor recolor, byte[] data, int offset, int red, int green, int blue, bool keepKey)
    {
        double r = data[offset + red] / 255.0, g = data[offset + green] / 255.0, b = data[offset + blue] / 255.0;
        if (keepKey && data[offset + red] == 255 && data[offset + green] == 0 && data[offset + blue] == 255) return false;
        var max = Math.Max(r, Math.Max(g, b));
        var min = Math.Min(r, Math.Min(g, b));
        var lightness = (max + min) / 2;
        var delta = max - min;
        var saturation = delta == 0 ? 0 : delta / (1 - Math.Abs(2 * lightness - 1));
        var hue = delta == 0 ? 0 : max == r ? 60 * ((g - b) / delta % 6) : max == g ? 60 * ((b - r) / delta + 2) : 60 * ((r - g) / delta + 4);
        if (hue < 0) hue += 360;
        if (saturation < recolor.MinimumSaturation) return false;
        if (recolor.HueRange is [var from, var to] && !(from <= to ? hue >= from && hue <= to : hue >= from || hue <= to)) return false;
        hue = ((hue + recolor.Hue) % 360 + 360) % 360;
        saturation = Math.Clamp(saturation * recolor.Saturation, 0, 1);
        lightness = Math.Clamp(lightness * recolor.Lightness, 0, 1);
        var chroma = (1 - Math.Abs(2 * lightness - 1)) * saturation;
        var second = chroma * (1 - Math.Abs(hue / 60 % 2 - 1));
        var (rr, gg, bb) = (int)(hue / 60) switch
        {
            0 => (chroma, second, 0.0), 1 => (second, chroma, 0.0), 2 => (0.0, chroma, second),
            3 => (0.0, second, chroma), 4 => (second, 0.0, chroma), _ => (chroma, 0.0, second)
        };
        var match = lightness - chroma / 2;
        var result = new[] { rr + match, gg + match, bb + match }.Select(value => (byte)Math.Clamp(Math.Round(value * 255), 0, 255)).ToArray();
        // Never produce the icon's transparent key by accident.
        if (keepKey && result[0] == 255 && result[1] == 0 && result[2] == 255) result[1] = 1;
        var before = (data[offset + red], data[offset + green], data[offset + blue]);
        (data[offset + red], data[offset + green], data[offset + blue]) = (result[0], result[1], result[2]);
        return before != (result[0], result[1], result[2]);
    }

    /// <summary>"next", "true", "false", "error", a label or an instruction index. A missing true branch goes to the
    /// next instruction (or returns true after the last); a missing false branch is an error.</summary>
    private static byte Pointer(JsonElement? value, int index, int count, Dictionary<string, int> labels, bool truePath, string where)
    {
        var last = index == count - 1;
        if (value is not { } element) return truePath ? (last ? PointerTrue : (byte)(index + 1)) : PointerError;
        if (element.ValueKind == JsonValueKind.Number)
        {
            if (!element.TryGetInt32(out var target) || target < 0 || target >= count)
                throw new InvalidDataException($"{where}: branch target is out of range");
            return (byte)target;
        }
        var name = element.ValueKind == JsonValueKind.String ? element.GetString()! : throw new InvalidDataException($"{where}: invalid branch target");
        return name switch
        {
            "next" when !last => (byte)(index + 1),
            "next" => throw new InvalidDataException($"{where}: the last instruction cannot branch to next"),
            "true" => PointerTrue,
            "false" => PointerFalse,
            "error" => PointerError,
            _ => labels.TryGetValue(name, out var target) ? (byte)target : throw new InvalidDataException($"{where}: unknown label {name}")
        };
    }

    private static ushort Resolve(JsonElement value, Dictionary<string, ushort> behaviorIDs, HashSet<ushort> existing, string where)
    {
        if (value.ValueKind == JsonValueKind.String)
        {
            var name = value.GetString()!;
            if (behaviorIDs.TryGetValue(name, out var id)) return id;
            if (!name.StartsWith("0x", StringComparison.OrdinalIgnoreCase) || !ushort.TryParse(name.AsSpan(2), System.Globalization.NumberStyles.HexNumber, null, out id))
                throw new InvalidDataException($"{where}: unknown behavior {name}");
            value = JsonSerializer.SerializeToElement((int)id);
        }
        if (value.ValueKind != JsonValueKind.Number || !value.TryGetInt32(out var number) || number is < 0x100 or > 0x2FFF)
            throw new InvalidDataException($"{where}: behavior IDs are global (0x100), private (0x1000) or semi-global (0x2000)");
        if (number is >= 0x1000 and < 0x2000 && !existing.Contains((ushort)number) && !behaviorIDs.ContainsValue((ushort)number))
            throw new InvalidDataException($"{where}: private behavior 0x{number:X4} is not in the template");
        return (ushort)number;
    }

    /// <summary>Fills an engine operand model from JSON, then checks that encoding it keeps every value.</summary>
    private static byte[] Operand(Type model, Dictionary<string, JsonElement> values, string where)
    {
        var operand = (VMPrimitiveOperand)Activator.CreateInstance(model)!;
        var members = Members(model);
        foreach (var (name, value) in values)
        {
            var member = members.FirstOrDefault(item => string.Equals(item.Name, name, StringComparison.OrdinalIgnoreCase))
                ?? throw new InvalidDataException($"{where}: {model.Name} has no field {name}; it has {string.Join(", ", members.Select(item => item.Name))}");
            Assign(operand, member, value, where);
        }
        var bytes = new byte[8];
        operand.Write(bytes);
        var check = (VMPrimitiveOperand)Activator.CreateInstance(model)!;
        check.Read(bytes);
        foreach (var name in values.Keys)
        {
            var member = members.First(item => string.Equals(item.Name, name, StringComparison.OrdinalIgnoreCase));
            if (!Equivalent(Value(operand, member), Value(check, member)))
                throw new InvalidDataException($"{where}: {member.Name} does not fit in the {model.Name} encoding");
        }
        return bytes;
    }

    private static MemberInfo[] Members(Type model) =>
        model.GetProperties(BindingFlags.Public | BindingFlags.Instance).Where(property => property.CanWrite && property.CanRead && property.GetIndexParameters().Length == 0)
            .Cast<MemberInfo>().Concat(model.GetFields(BindingFlags.Public | BindingFlags.Instance)).ToArray();

    private static Type MemberType(MemberInfo member) => member is PropertyInfo property ? property.PropertyType : ((FieldInfo)member).FieldType;

    private static object? Value(object target, MemberInfo member) => member is PropertyInfo property ? property.GetValue(target) : ((FieldInfo)member).GetValue(target);

    private static bool Equivalent(object? left, object? right) =>
        left is Array a && right is Array b ? a.Length == b.Length && a.Cast<object>().SequenceEqual(b.Cast<object>()) : Equals(left, right);

    private static void Assign(object target, MemberInfo member, JsonElement value, string where)
    {
        var type = MemberType(member);
        object converted;
        try
        {
            if (type.IsEnum)
                converted = value.ValueKind == JsonValueKind.String
                    ? Enum.Parse(type, value.GetString()!, true)
                    : Enum.ToObject(type, value.GetInt64());
            else if (type == typeof(bool)) converted = value.ValueKind == JsonValueKind.Number ? value.GetInt64() != 0 : value.GetBoolean();
            else if (type.IsArray && type.GetElementType() is { IsPrimitive: true } element)
            {
                var items = value.EnumerateArray().Select(item => Convert.ChangeType(item.GetInt64(), element)).ToArray();
                var array = Array.CreateInstance(element, items.Length);
                for (var index = 0; index < items.Length; index++) array.SetValue(items[index], index);
                converted = array;
            }
            else if (type.IsPrimitive) converted = Convert.ChangeType(value.GetInt64(), type);
            else throw new InvalidDataException($"{where}: {member.Name} cannot be set from JSON");
        }
        catch (Exception error) when (error is FormatException or OverflowException or InvalidOperationException or ArgumentException)
        {
            throw new InvalidDataException($"{where}: invalid value for {member.Name}: {error.Message}");
        }
        if (type.IsEnum && value.ValueKind == JsonValueKind.String && !Enum.IsDefined(type, converted) && !type.IsDefined(typeof(FlagsAttribute), false))
            throw new InvalidDataException($"{where}: {value.GetString()} is not a {type.Name}");
        if (member is PropertyInfo property) property.SetValue(target, converted);
        else ((FieldInfo)member).SetValue(target, converted);
    }

    private static byte[] Hex(string value, string where)
    {
        try
        {
            var bytes = Convert.FromHexString(value.Replace(" ", ""));
            if (bytes.Length > 8) throw new FormatException();
            return bytes.Concat(new byte[8 - bytes.Length]).ToArray();
        }
        catch (FormatException) { throw new InvalidDataException($"{where}: operandHex must be at most eight hexadecimal bytes"); }
    }

    private static uint ParseGuid(JsonElement value, string what)
    {
        if (value.ValueKind == JsonValueKind.Number && value.TryGetUInt32(out var number)) return number;
        if (value.ValueKind == JsonValueKind.String && value.GetString() is { } text && text.StartsWith("0x", StringComparison.OrdinalIgnoreCase) &&
            uint.TryParse(text.AsSpan(2), System.Globalization.NumberStyles.HexNumber, null, out number)) return number;
        throw new InvalidDataException($"Invalid {what}; use a number or a 0x-prefixed hexadecimal string");
    }

    private static string Text(string value, string what)
    {
        if (value.Length is < 1 or > 1000 || value.Contains('\0')) throw new InvalidDataException($"Invalid {what}");
        return value;
    }

    private static string Label(string value) => new string(value.Where(character => character is >= ' ' and < '\u007f').Take(63).ToArray());

    /// <summary>Sets a string in English and in every other language the table carries, growing the table as needed.</summary>
    private static void Set(STR strings, int index, string value)
    {
        for (var language = 0; language < strings.LanguageSets.Length; language++)
        {
            var set = strings.LanguageSets[language] ??= new STRLanguageSet();
            if (language > 0 && set.Strings.Length == 0) continue;
            if (set.Strings.Length <= index)
                set.Strings = set.Strings.Concat(Enumerable.Range(0, index + 1 - set.Strings.Length)
                    .Select(_ => new STRItem { LanguageCode = (byte)(language + 1), Value = "", Comment = "" })).ToArray();
            set.Strings[index].Value = value;
            set.Strings[index].Comment ??= "";
        }
    }

    private static int FieldIndex(string name) =>
        Array.IndexOf(OBJD.VERSION_142_Fields.Concat(OBJD.VERSION_138b_Extra_Fields).ToArray(), name);

    private static ushort ReadField(Chunk definition, string name)
    {
        var offset = 4 + FieldIndex(name) * 2;
        return offset + 2 <= definition.Data.Length ? BinaryPrimitives.ReadUInt16LittleEndian(definition.Data.AsSpan(offset)) : (ushort)0;
    }

    private static void WriteField(Chunk definition, string name, ushort value)
    {
        var index = FieldIndex(name);
        if (index < 0) throw new InvalidDataException($"Unknown definition field {name}");
        var offset = 4 + index * 2;
        if (offset + 2 > definition.Data.Length) throw new InvalidDataException($"The template's definition version has no {name} field");
        BinaryPrimitives.WriteUInt16LittleEndian(definition.Data.AsSpan(offset), value);
    }

    private static T Parse<T>(Chunk chunk) where T : IffChunk, new()
    {
        var parsed = new T { ChunkID = chunk.Id, ChunkLabel = chunk.Label, ChunkType = chunk.Type };
        using var stream = new MemoryStream(chunk.Data);
        parsed.Read(new IffFile(), stream);
        return parsed;
    }

    private static byte[] Serialize(IffChunk chunk)
    {
        using var stream = new MemoryStream();
        if (!chunk.Write(new IffFile(), stream)) throw new InvalidDataException($"The engine cannot write {chunk.GetType().Name} chunks");
        return stream.ToArray();
    }

    private static List<Chunk> ReadIff(byte[] data)
    {
        if (data.Length < 64 || !Encoding.ASCII.GetString(data, 0, 8).StartsWith("IFF FILE", StringComparison.Ordinal))
            throw new InvalidDataException("Template is not an IFF file");
        var chunks = new List<Chunk>();
        var cursor = 64;
        while (cursor + 76 <= data.Length)
        {
            var type = Encoding.ASCII.GetString(data, cursor, 4);
            var size = (int)BinaryPrimitives.ReadUInt32BigEndian(data.AsSpan(cursor + 4));
            if (size < 76 || cursor + size > data.Length) throw new InvalidDataException("Template IFF chunk is truncated");
            var label = Encoding.Latin1.GetString(data, cursor + 12, 64);
            chunks.Add(new Chunk
            {
                Type = type,
                Id = BinaryPrimitives.ReadUInt16BigEndian(data.AsSpan(cursor + 8)),
                Flags = BinaryPrimitives.ReadUInt16BigEndian(data.AsSpan(cursor + 10)),
                Label = label[..(label.IndexOf('\0') is var end and >= 0 ? end : label.Length)],
                Data = data.AsSpan(cursor + 76, size - 76).ToArray()
            });
            cursor += size;
        }
        // The resource map indexes the original layout; the engine does not need it, so it is not carried over.
        chunks.RemoveAll(chunk => chunk.Type == "rsmp");
        return chunks;
    }

    private static byte[] WriteIff(List<Chunk> chunks)
    {
        using var stream = new MemoryStream();
        var header = new byte[64];
        Encoding.ASCII.GetBytes("IFF FILE 2.5:TYPE FOLLOWED BY SIZE\0 JAMIE DOORNBOS & MAXIS 1").CopyTo(header, 0);
        stream.Write(header);
        foreach (var chunk in chunks)
        {
            var head = new byte[76];
            Encoding.ASCII.GetBytes(chunk.Type).CopyTo(head, 0);
            BinaryPrimitives.WriteUInt32BigEndian(head.AsSpan(4), (uint)(chunk.Data.Length + 76));
            BinaryPrimitives.WriteUInt16BigEndian(head.AsSpan(8), chunk.Id);
            BinaryPrimitives.WriteUInt16BigEndian(head.AsSpan(10), chunk.Flags);
            Encoding.Latin1.GetBytes(chunk.Label).CopyTo(head, 12);
            stream.Write(head);
            stream.Write(chunk.Data);
        }
        return stream.ToArray();
    }

    private static bool Identifier(string value) => value != null && value.Length is >= 1 and <= 120 && char.IsAsciiLetterOrDigit(value[0]) &&
        value.All(character => char.IsAsciiLetterOrDigit(character) || character is '-' or '.' or '_') && value is not ("." or "..");

    /// <summary>Original object files, loose or inside the FAR archives of GameData/Objects.</summary>
    private sealed class Templates(string game)
    {
        private readonly string objects = Path.Combine(game, "GameData", "Objects");

        public byte[] Read(string name)
        {
            if (string.IsNullOrWhiteSpace(name) || name.IndexOfAny(['/', '\\']) >= 0 || !name.EndsWith(".iff", StringComparison.OrdinalIgnoreCase))
                throw new InvalidDataException($"Template {name} must be an original object file name such as flamingo.iff");
            if (!Directory.Exists(objects)) throw new InvalidDataException($"No original objects at {objects}");
            var loose = Directory.EnumerateFiles(objects, "*", SearchOption.AllDirectories)
                .FirstOrDefault(path => string.Equals(Path.GetFileName(path), name, StringComparison.OrdinalIgnoreCase));
            if (loose != null) return File.ReadAllBytes(loose);
            foreach (var path in Directory.EnumerateFiles(objects, "*.far", SearchOption.AllDirectories))
            {
                FAR1Archive archive;
                try { archive = new FAR1Archive(path, false); _ = archive.GetAllFarEntries(); }
                catch (Exception) { archive = new FAR1Archive(path, true); }
                try
                {
                    var entry = archive.GetAllFarEntries().FirstOrDefault(item => string.Equals(Path.GetFileName(item.Filename.Replace('\\', '/')), name, StringComparison.OrdinalIgnoreCase));
                    if (entry != null) return archive.GetEntry(entry);
                }
                finally { archive.Close(); }
            }
            throw new InvalidDataException($"Template {name} is not an installed original object");
        }
    }
}
