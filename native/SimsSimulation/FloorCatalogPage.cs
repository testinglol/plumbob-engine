using System.Buffers.Binary;
using System.Security.Cryptography;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.World;

namespace SimsSimulation;

// Base floors in floors.iff use SPR2 pattern+256 (medium) and pattern+512 (preview); dynamic .flr files use 257 and 513.
internal static class FloorCatalogPage
{
    private sealed record Item(int Id, string Name, string Description, int Price, string File, IffFile Art, ushort SpriteId, ushort PreviewSpriteId);

    public static object Page(string game, byte language, int offset, int count, string session)
    {
        if (offset is < 0 or > 1_000_000 || count is < 1 or > 64) throw new ArgumentException("Invalid native floor catalog page");
        var build = FloorCatalog.TryOpenCoreIff(game, "Build.iff")
            ?? throw new FileNotFoundException("Build.iff was not found", game);
        var globals = FloorCatalog.TryOpenCoreIff(game, "floors.iff");
        var stringsChunk = build.Find(ResourceType.Str, 0x82) ?? throw new InvalidDataException("Build.iff has no floor STR# 0x82");
        var stringTable = StringTable.Read(build, stringsChunk);
        var strings = stringTable.ForLanguage(language).ToArray();
        var items = new List<Item>();
        if (globals is not null)
        {
            for (var pattern = 1; pattern <= 29 && (pattern - 1) * 3 + 2 < strings.Length; pattern++)
            {
                var at = (pattern - 1) * 3;
                var price = int.TryParse(stringTable.GetString(at, language).Trim(), out var parsed) ? parsed : 0;
                items.Add(new Item(
                    pattern,
                    stringTable.GetString(at + 1, language),
                    stringTable.GetString(at + 2, language),
                    price,
                    "global",
                    globals,
                    checked((ushort)(pattern + 256)),
                    checked((ushort)(pattern + 512))));
            }
        }
        foreach (var entry in FloorCatalog.DynamicEntries(game))
        {
            try
            {
                var iff = entry.Open();
                if (iff.Find(ResourceType.Spr2, 257) is null && iff.Find(ResourceType.Spr2, 513) is null)
                    continue;
                var tableChunk = iff.Find(ResourceType.Str, 0);
                var table = tableChunk is null ? null : StringTable.Read(iff, tableChunk);
                var rawName = table?.GetString(0, language);
                var name = !string.IsNullOrWhiteSpace(rawName) ? rawName : Path.GetFileNameWithoutExtension(entry.FileName);
                var rawPrice = table?.GetString(1, language);
                var price = !string.IsNullOrEmpty(rawPrice) && int.TryParse(rawPrice.Trim(), out var parsed) ? Math.Max(0, parsed) : 0;
                var description = table?.GetString(2, language) ?? "";
                items.Add(new Item(entry.PatternId, name, description, price, entry.FileName, iff, 257, 513));
            }
            catch (Exception error) when (error is IOException or InvalidDataException or ResourceFormatException or ArgumentException or OverflowException)
            {
            }
        }
        var ordered = items.OrderBy(item => item.Price).ThenBy(item => item.Id).ToArray();
        return new
        {
            schemaVersion = 1, kind = "floor", offset, total = ordered.Length,
            items = ordered.Skip(offset).Take(count).Select(item => new
            {
                id = item.Id, name = item.Name, description = item.Description, price = item.Price, file = item.File,
                icon = (item.Id is >= 1 and <= 29 && globals?.Find(ResourceType.Parse("BMP_"), (ushort)item.Id) is { } bmpChunk
                    ? WallCatalogPage.StoreBmp(bmpChunk.Data.ToArray(), 2, session)
                    : null)
                    ?? FloorThumbnailIcon(item.Art, item.PreviewSpriteId, session)
                    ?? FloorThumbnailIcon(item.Art, item.SpriteId, session),
                preview = Icon(item.Art, item.PreviewSpriteId, session) ?? Icon(item.Art, item.SpriteId, session),
            }).ToArray(),
        };
    }

    public static object[] All(string game, byte language)
    {
        var build = FloorCatalog.TryOpenCoreIff(game, "Build.iff")
            ?? throw new FileNotFoundException("Build.iff was not found", game);
        var stringsChunk = build.Find(ResourceType.Str, 0x82) ?? throw new InvalidDataException("Build.iff has no floor STR# 0x82");
        var stringTable = StringTable.Read(build, stringsChunk);
        var strings = stringTable.ForLanguage(language).ToArray();
        var items = new List<(int Id, string File, string Name, int Price)>();
        for (var pattern = 1; pattern <= 29 && (pattern - 1) * 3 + 2 < strings.Length; pattern++)
        {
            var at = (pattern - 1) * 3;
            var price = int.TryParse(stringTable.GetString(at, language).Trim(), out var parsed) ? parsed : 0;
            items.Add((pattern, "global", stringTable.GetString(at + 1, language), price));
        }
        foreach (var entry in FloorCatalog.DynamicEntries(game))
        {
            try
            {
                var iff = entry.Open();
                if (iff.Find(ResourceType.Spr2, 257) is null && iff.Find(ResourceType.Spr2, 513) is null)
                    continue;
                var tableChunk = iff.Find(ResourceType.Str, 0);
                var table = tableChunk is null ? null : StringTable.Read(iff, tableChunk);
                var rawName = table?.GetString(0, language);
                var name = !string.IsNullOrWhiteSpace(rawName) ? rawName : Path.GetFileNameWithoutExtension(entry.FileName);
                var rawPrice = table?.GetString(1, language);
                var price = !string.IsNullOrEmpty(rawPrice) && int.TryParse(rawPrice.Trim(), out var parsed) ? Math.Max(0, parsed) : 0;
                items.Add((entry.PatternId, entry.FileName, name, price));
            }
            catch (Exception error) when (error is IOException or InvalidDataException or ResourceFormatException or ArgumentException or OverflowException)
            {
            }
        }
        if (build.Find(ResourceType.Str, 0x85) is { } waterChunk)
        {
            var waterTable = StringTable.Read(build, waterChunk);
            var waterStrings = waterTable.ForLanguage(language).ToArray();
            if (waterStrings.Length >= 6)
            {
                if (int.TryParse(waterTable.GetString(3, language).Trim(), out var pondPrice))
                    items.Add((65534, "global", waterTable.GetString(4, language), pondPrice));
                if (int.TryParse(waterTable.GetString(0, language).Trim(), out var poolPrice))
                    items.Add((65535, "global", waterTable.GetString(1, language), poolPrice));
            }
        }
        return items.OrderBy(item => item.Id).Select(item => (object)new { id = item.Id, file = item.File, name = item.Name, price = item.Price }).ToArray();
    }

    // Pool (-1 / 65535) and pond (-2 / 65534) entries come from Build.iff STR# 0x85 with floors.iff SPR2 0x420 and 0x800.
    public static object WaterPage(string game, ObjectRegistry registry, byte language, int offset, int count, string session)
    {
        if (offset is < 0 or > 1_000_000 || count is < 1 or > 64) throw new ArgumentException("Invalid native water catalog page");
        var build = FloorCatalog.TryOpenCoreIff(game, "Build.iff")
            ?? throw new FileNotFoundException("Build.iff was not found", game);
        var globals = FloorCatalog.TryOpenCoreIff(game, "floors.iff")
            ?? throw new FileNotFoundException("floors.iff was not found", game);
        var stringsChunk = build.Find(ResourceType.Str, 0x85) ?? throw new InvalidDataException("Build.iff has no water STR# 0x85");
        var strings = StringTable.Read(build, stringsChunk).ForLanguage(language).ToArray();
        var items = new List<(ushort Id, uint? Guid, string Name, string Description, int Price, string File, object? Icon, object? Preview)>();
        if (strings.Length >= 6)
        {
            if (int.TryParse(strings[0].Trim(), out var poolPrice))
                items.Add((65535, null, strings[1], strings[2], poolPrice, "global", Icon(globals, 0x420, session), Icon(globals, 0x420, session)));
            if (int.TryParse(strings[3].Trim(), out var pondPrice))
                items.Add((65534, null, strings[4], strings[5], pondPrice, "global", Icon(globals, 0x800, session), Icon(globals, 0x800, session)));
        }
        // OBJD BuildModeType 7 identifies pool accessories.
        foreach (var source in registry.ByGuid.Values)
        {
            var definition = source.Definition;
            var master = definition[ObjdField.MasterId];
            var subIndex = definition[ObjdField.SubIndex];
            if (definition[ObjdField.BuildModeType] != 7 || definition[ObjdField.Disabled] != 0 || definition[ObjdField.Price] < 0 ||
                (master != 0 && subIndex != ushort.MaxValue) || (master == 0 && subIndex != 0) ||
                (definition[ObjdField.NumGraphics] == 0 && master == 0)) continue;
            items.Add((0, source.Guid, source.CatalogString(0, language) ?? source.Chunk.Label,
                source.CatalogString(1, language) ?? "", definition[ObjdField.Price], "objects/" + source.Guid.ToString("X8"),
                ObjectCatalog.CatalogIcon(source, session), ObjectCatalog.CatalogPreview(source, session)));
        }
        var ordered = items.OrderBy(item => item.Price).ThenBy(item => item.Guid.HasValue).ThenBy(item => item.Guid ?? item.Id).ToArray();
        return new
        {
            schemaVersion = 1, kind = "water", offset, total = ordered.Length,
            items = ordered.Skip(offset).Take(count).Select(item => new
            {
                id = item.Id, guid = item.Guid, name = item.Name, description = item.Description, price = item.Price, file = item.File,
                icon = item.Icon, preview = item.Preview,
            }).ToArray(),
        };
    }

    private static object? Icon(IffFile file, ushort spriteId, string session)
    {
        try
        {
            var chunk = file.Find(ResourceType.Spr2, spriteId);
            if (chunk is null) return null;
            var sprite = DepthSprite.Read(file, chunk);
            var frame = sprite.Frames.FirstOrDefault();
            var paletteChunk = file.Find(ResourceType.Palt, checked((ushort)(sprite.PaletteId is >= 0 and <= ushort.MaxValue ? sprite.PaletteId : 0)))
                ?? file.OfType(ResourceType.Palt).FirstOrDefault();
            if (frame is null || paletteChunk is null || frame.Width is < 1 or > 512 || frame.Height is < 1 or > 512) return null;
            var colors = Palette.Read(file, paletteChunk).Colors;
            var bytes = new byte[54 + frame.Width * frame.Height * 4];
            bytes[0] = (byte)'B'; bytes[1] = (byte)'M'; BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(2), bytes.Length);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(10), 54); BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(14), 40);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(18), frame.Width); BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(22), -frame.Height);
            BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(26), 1); BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(28), 32);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(34), frame.Width * frame.Height * 4);
            for (var i = 0; i < frame.Width * frame.Height; i++)
            {
                var target = 54 + i * 4;
                if (frame.Alpha[i] == 0 || frame.Indices[i] >= colors.Count)
                { bytes[target] = 255; bytes[target + 2] = 255; bytes[target + 3] = 255; continue; }
                var color = colors[frame.Indices[i]];
                bytes[target] = color.Blue; bytes[target + 1] = color.Green; bytes[target + 2] = color.Red;
                bytes[target + 3] = 255;
            }
            var name = "ui-" + Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant() + ".bmp";
            Directory.CreateDirectory(session);
            var path = Path.Combine(session, name);
            if (!File.Exists(path)) File.WriteAllBytes(path, bytes);
            return new { file = name, columns = 1, rows = 1 };
        }
        catch (Exception error) when (error is IOException or InvalidDataException or ResourceFormatException or OverflowException)
        { return null; }
    }

    private static object? FloorThumbnailIcon(IffFile file, ushort spriteId, string session)
    {
        try
        {
            var chunk = file.Find(ResourceType.Spr2, spriteId);
            if (chunk is null) return null;
            var sprite = DepthSprite.Read(file, chunk);
            var frame = sprite.Frames.FirstOrDefault();
            var paletteChunk = file.Find(ResourceType.Palt, checked((ushort)(sprite.PaletteId is >= 0 and <= ushort.MaxValue ? sprite.PaletteId : 0)))
                ?? file.OfType(ResourceType.Palt).FirstOrDefault();
            if (frame is null || paletteChunk is null || frame.Width is < 1 or > 512 || frame.Height is < 1 or > 512) return null;
            var colors = Palette.Read(file, paletteChunk).Colors;

            const int boxSize = 37;
            var scale = Math.Min(1f, Math.Min(boxSize / (float)frame.Width, boxSize / (float)frame.Height));
            var outW = Math.Max(1, (int)Math.Round(frame.Width * scale));
            var outH = Math.Max(1, (int)Math.Round(frame.Height * scale));
            var padX = (boxSize - outW) / 2;
            var padY = (boxSize - outH) / 2;
            const int sheetW = boxSize * 2;
            const int sheetH = boxSize;
            var bytes = new byte[54 + sheetW * sheetH * 4];
            bytes[0] = (byte)'B'; bytes[1] = (byte)'M'; BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(2), bytes.Length);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(10), 54); BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(14), 40);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(18), sheetW); BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(22), -sheetH);
            BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(26), 1); BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(28), 32);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(34), sheetW * sheetH * 4);
            for (var i = 0; i < sheetW * sheetH; i++)
            {
                var t = 54 + i * 4;
                bytes[t] = 255; bytes[t + 2] = 255; bytes[t + 3] = 255;
            }

            for (var dy = 0; dy < outH; dy++)
            {
                var y0 = dy * frame.Height / outH;
                var y1 = Math.Max(y0 + 1, (dy + 1) * frame.Height / outH);
                for (var dx = 0; dx < outW; dx++)
                {
                    var x0 = dx * frame.Width / outW;
                    var x1 = Math.Max(x0 + 1, (dx + 1) * frame.Width / outW);
                    int r = 0, g = 0, b = 0, alphaSum = 0, total = 0;
                    for (var sy = y0; sy < Math.Min(y1, frame.Height); sy++)
                    for (var sx = x0; sx < Math.Min(x1, frame.Width); sx++)
                    {
                        total++;
                        var idx = sy * frame.Width + sx;
                        var rawA = frame.Alpha[idx];
                        if (rawA == 0 || frame.Indices[idx] >= colors.Count) continue;
                        var a = (rawA * 255 + 15) / 31;
                        var c = colors[frame.Indices[idx]];
                        r += c.Red * a;
                        g += c.Green * a;
                        b += c.Blue * a;
                        alphaSum += a;
                    }
                    if (alphaSum == 0 || total == 0) continue;
                    var maxAlpha = total * 255;
                    var bgAlpha = maxAlpha - alphaSum;
                    for (var col = 0; col < 2; col++)
                    {
                        var bg = col == 0 ? (R: 104, G: 164, B: 184) : (R: 152, G: 196, B: 208);
                        var target = 54 + ((padY + dy) * sheetW + col * boxSize + padX + dx) * 4;
                        bytes[target] = (byte)Math.Clamp((b + bg.B * bgAlpha + maxAlpha / 2) / maxAlpha, 0, 255);
                        bytes[target + 1] = (byte)Math.Clamp((g + bg.G * bgAlpha + maxAlpha / 2) / maxAlpha, 0, 255);
                        bytes[target + 2] = (byte)Math.Clamp((r + bg.R * bgAlpha + maxAlpha / 2) / maxAlpha, 0, 255);
                        bytes[target + 3] = 255;
                    }
                }
            }
            return WallCatalogPage.StoreBmp(bytes, 2, session);
        }
        catch (Exception error) when (error is IOException or InvalidDataException or ResourceFormatException or OverflowException)
        { return null; }
    }
}
