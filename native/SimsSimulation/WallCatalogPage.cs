using System.Buffers.Binary;
using System.Security.Cryptography;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.World;

namespace SimsSimulation;

// Base wallpapers use Build.iff STR# 0x83, walls.iff SPR1 1792+id (medium) and BMP_ 512+id; .wll files use SPR1 1793.
internal static class WallCatalogPage
{
    private sealed record Item(int Id, string Name, string Description, int Price, string File, IffFile ArtFile, ushort PatternSpriteId, ushort? BmpChunkId);

    public static object Page(string game, byte language, int offset, int count, string session)
    {
        if (offset is < 0 or > 1_000_000 || count is < 1 or > 64) throw new ArgumentException("Invalid native wallpaper catalog page");
        var build = FloorCatalog.TryOpenCoreIff(game, "Build.iff")
            ?? throw new FileNotFoundException("Build.iff was not found", game);
        var walls = FloorCatalog.TryOpenCoreIff(game, "walls.iff");
        var stringsChunk = build.Find(ResourceType.Str, 0x83) ?? throw new InvalidDataException("Build.iff has no wallpaper STR# 0x83");
        var stringTable = StringTable.Read(build, stringsChunk);
        var strings = stringTable.ForLanguage(language).ToArray();
        var items = new List<Item>();
        var patterns = Math.Min(30, strings.Length / 3);
        if (walls is not null)
        {
            for (var pattern = 1; pattern <= patterns; pattern++)
            {
                var spriteId = checked((ushort)(1792 + pattern));
                if (walls.Find(ResourceType.Spr1, spriteId) is null) continue;
                var at = (pattern - 1) * 3;
                var price = int.TryParse(stringTable.GetString(at, language).Trim(), out var parsed) ? parsed : 0;
                items.Add(new Item(
                    pattern,
                    stringTable.GetString(at + 1, language),
                    stringTable.GetString(at + 2, language),
                    price,
                    "global",
                    walls,
                    spriteId,
                    checked((ushort)(512 + pattern))));
            }
        }
        foreach (var entry in WallpaperCatalog.DynamicEntries(game))
        {
            try
            {
                var iff = entry.Open();
                var spriteId = iff.Find(ResourceType.Spr1, 1793) is not null ? (ushort)1793
                    : iff.Find(ResourceType.Spr1, 2049) is not null ? (ushort)2049
                    : iff.Find(ResourceType.Spr1, 1) is not null ? (ushort)1
                    : (ushort)0;
                if (spriteId == 0) continue;
                var tableChunk = iff.Find(ResourceType.Str, 0);
                var table = tableChunk is null ? null : StringTable.Read(iff, tableChunk);
                var rawName = table?.GetString(0, language);
                var name = !string.IsNullOrWhiteSpace(rawName) ? rawName : Path.GetFileNameWithoutExtension(entry.FileName);
                var rawPrice = table?.GetString(1, language);
                var price = !string.IsNullOrEmpty(rawPrice) && int.TryParse(rawPrice.Trim(), out var parsed) ? Math.Max(0, parsed) : 0;
                var description = table?.GetString(2, language) ?? "";
                items.Add(new Item(entry.PatternId, name, description, price, entry.FileName, iff, spriteId, null));
            }
            catch (Exception error) when (error is IOException or InvalidDataException or ResourceFormatException or ArgumentException or OverflowException)
            {
            }
        }
        var ordered = items.OrderBy(item => item.Price).ThenBy(item => item.Id).ToArray();
        return new
        {
            schemaVersion = 1, kind = "wall", offset, total = ordered.Length,
            items = ordered.Skip(offset).Take(count).Select(item => new
            {
                id = item.Id, name = item.Name, description = item.Description, price = item.Price,
                file = item.File,
                icon = (item.BmpChunkId is { } bmpId && walls?.Find(ResourceType.Parse("BMP_"), bmpId) is { } bmpChunk
                    ? StoreBmp(bmpChunk.Data.ToArray(), 2, session)
                    : null) ?? (walls is not null ? WallThumbnailIcon(walls, item.ArtFile, item.PatternSpriteId, session) : null),
                preview = walls is not null ? WallpaperFlatPreview(walls, item.ArtFile, item.PatternSpriteId, session) : null,
            }).ToArray(),
        };
    }

    public static object[] All(string game, byte language)
    {
        var build = FloorCatalog.TryOpenCoreIff(game, "Build.iff")
            ?? throw new FileNotFoundException("Build.iff was not found", game);
        var walls = FloorCatalog.TryOpenCoreIff(game, "walls.iff");
        var stringsChunk = build.Find(ResourceType.Str, 0x83) ?? throw new InvalidDataException("Build.iff has no wallpaper STR# 0x83");
        var stringTable = StringTable.Read(build, stringsChunk);
        var strings = stringTable.ForLanguage(language).ToArray();
        var items = new List<(int Id, string File, string Name, int Price)>();
        var patterns = Math.Min(30, strings.Length / 3);
        if (walls is not null)
        {
            for (var pattern = 1; pattern <= patterns; pattern++)
            {
                var spriteId = checked((ushort)(1792 + pattern));
                if (walls.Find(ResourceType.Spr1, spriteId) is null) continue;
                var at = (pattern - 1) * 3;
                var price = int.TryParse(stringTable.GetString(at, language).Trim(), out var parsed) ? parsed : 0;
                items.Add((pattern, "global", stringTable.GetString(at + 1, language), price));
            }
        }
        foreach (var entry in WallpaperCatalog.DynamicEntries(game))
        {
            try
            {
                var iff = entry.Open();
                if (iff.Find(ResourceType.Spr1, 1793) is null &&
                    iff.Find(ResourceType.Spr1, 2049) is null &&
                    iff.Find(ResourceType.Spr1, 1) is null)
                {
                    continue;
                }
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
        return items.OrderBy(item => item.Id).Select(item => (object)new { id = item.Id, file = item.File, name = item.Name, price = item.Price }).ToArray();
    }

    internal static object? StoreBmp(byte[]? data, int columns, string session)
    {
        if (data is not { Length: >= 54 and <= 4 * 1024 * 1024 } || data[0] != 'B' || data[1] != 'M') return null;
        var file = "ui-" + Convert.ToHexString(SHA256.HashData(data)).ToLowerInvariant() + ".bmp";
        Directory.CreateDirectory(session);
        var path = Path.Combine(session, file);
        if (!File.Exists(path)) File.WriteAllBytes(path, data);
        return new { file, columns, rows = 1 };
    }

    private static (byte R, byte G, byte B, bool Opaque)[]? BuildFlatWall64x120(IffFile walls, IffFile patternFile, ushort patternSpriteId)
    {
        var patternChunk = patternFile.Find(ResourceType.Spr1, patternSpriteId);
        var maskChunk = walls.Find(ResourceType.Spr1, 514);
        if (patternChunk is null || maskChunk is null) return null;
        var patternSprite = Sprite.Read(patternFile, patternChunk);
        var maskSprite = Sprite.Read(walls, maskChunk);
        var paletteChunk = patternFile.Find(ResourceType.Palt,
            checked((ushort)(patternSprite.PaletteId is >= 0 and <= ushort.MaxValue ? patternSprite.PaletteId : 0)))
            ?? patternFile.OfType(ResourceType.Palt).FirstOrDefault();
        if (paletteChunk is null || patternSprite.Frames.Count == 0 || maskSprite.Frames.Count == 0) return null;
        var colors = Palette.Read(patternFile, paletteChunk).Colors;

        var faceArt = patternSprite.Frames.Count >= 3 ? patternSprite.Frames[2] : patternSprite.Frames[^1];
        var faceMask = patternSprite.Frames.Count >= 3 && maskSprite.Frames.Count >= 3 ? maskSprite.Frames[2] : null;

        IndexedFrame? topCapFrame = null;
        IReadOnlyList<PaletteColor>? topCapColors = null;
        if (walls.Find(ResourceType.Spr1, 4097) is { } capChunk &&
            walls.Find(ResourceType.Palt, 4096) is { } capPaltChunk)
        {
            var capSprite = Sprite.Read(walls, capChunk);
            if (capSprite.Frames.Count > 39 &&
                capSprite.Frames[39].Width == 64 &&
                capSprite.Frames[39].Height >= 16)
            {
                topCapFrame = capSprite.Frames[39];
                topCapColors = Palette.Read(walls, capPaltChunk).Colors;
            }
        }

        const int srcW = 64;
        const int srcH = 120;
        var srcRgb = new (byte R, byte G, byte B, bool Opaque)[srcW * srcH];
        for (var sy = 0; sy < srcH; sy++)
        for (var sx = 0; sx < srcW; sx++)
        {
            if (sy < 4)
            {
                if (topCapFrame is not null && topCapColors is not null)
                {
                    var capIdx = (12 + sy) * 64 + sx;
                    if (topCapFrame.Opaque[capIdx] && topCapFrame.Indices[capIdx] < topCapColors.Count)
                    {
                        var cc = topCapColors[topCapFrame.Indices[capIdx]];
                        srcRgb[sy * srcW + sx] = (cc.Red, cc.Green, cc.Blue, true);
                        continue;
                    }
                }
                srcRgb[sy * srcW + sx] = (144, 112, 72, true);
                continue;
            }

            int ax = faceArt.Width == srcW ? sx : Math.Clamp(sx * faceArt.Width / srcW, 0, faceArt.Width - 1);
            int ay = faceArt.Height == srcH
                ? sy
                : faceArt.Height <= 8
                    ? Math.Clamp((sy - 4) * faceArt.Height / (srcH - 4), 0, faceArt.Height - 1)
                    : Math.Clamp(sy * faceArt.Height / srcH, 0, faceArt.Height - 1);
            if (faceMask is { Width: srcW, Height: srcH } && faceArt.Height > 8 && !faceMask.Opaque[sy * srcW + sx])
                continue;

            var aIdx = ay * faceArt.Width + ax;
            if (!faceArt.Opaque[aIdx] || faceArt.Indices[aIdx] >= colors.Count)
                continue;
            var c = colors[faceArt.Indices[aIdx]];
            srcRgb[sy * srcW + sx] = (c.Red, c.Green, c.Blue, true);
        }
        return srcRgb;
    }

    private static object? WallThumbnailIcon(IffFile walls, IffFile patternFile, ushort patternSpriteId, string session)
    {
        try
        {
            const int srcW = 64;
            const int srcH = 120;
            if (BuildFlatWall64x120(walls, patternFile, patternSpriteId) is not { } srcRgb)
                return null;

            const int boxSize = 37;
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

            // Maxis walls.iff BMP_ 513..545 downsample the 64x120 flat front wall + 4px wood cap at 37/120 scale (19.73x37 centered at x=8.63..28.37).
            const float scale = (float)boxSize / srcH;
            const float dstW = srcW * scale;
            const float dstLeft = (boxSize - dstW) * 0.5f;
            const float dstRight = dstLeft + dstW;

            for (var dstY = 0; dstY < boxSize; dstY++)
            {
                float sy0 = dstY / scale;
                float sy1 = (dstY + 1f) / scale;
                int iy0 = Math.Clamp((int)MathF.Floor(sy0), 0, srcH - 1);
                int iy1 = Math.Clamp((int)MathF.Ceiling(sy1) - 1, 0, srcH - 1);

                for (var dstX = 8; dstX <= 28; dstX++)
                {
                    float ovX0 = MathF.Max(dstX, dstLeft);
                    float ovX1 = MathF.Min(dstX + 1f, dstRight);
                    float coverage = ovX1 - ovX0;
                    if (coverage <= 0f) continue;

                    float sx0 = Math.Clamp((ovX0 - dstLeft) / scale, 0f, srcW);
                    float sx1 = Math.Clamp((ovX1 - dstLeft) / scale, 0f, srcW);
                    int ix0 = Math.Clamp((int)MathF.Floor(sx0), 0, srcW - 1);
                    int ix1 = Math.Clamp((int)MathF.Ceiling(sx1) - 1, 0, srcW - 1);

                    float sumR = 0f, sumG = 0f, sumB = 0f, sumW = 0f, totalW = 0f;
                    for (int iy = iy0; iy <= iy1; iy++)
                    {
                        float wy = MathF.Min(iy + 1f, sy1) - MathF.Max(iy, sy0);
                        if (wy <= 0f) continue;
                        for (int ix = ix0; ix <= ix1; ix++)
                        {
                            float wx = MathF.Min(ix + 1f, sx1) - MathF.Max(ix, sx0);
                            if (wx <= 0f) continue;
                            float w = wx * wy;
                            totalW += w;
                            var p = srcRgb[iy * srcW + ix];
                            if (!p.Opaque) continue;
                            sumR += p.R * w;
                            sumG += p.G * w;
                            sumB += p.B * w;
                            sumW += w;
                        }
                    }

                    if (sumW <= 0f || totalW <= 0f) continue;
                    float alpha = coverage * (sumW / totalW);
                    float avgR = sumR / sumW;
                    float avgG = sumG / sumW;
                    float avgB = sumB / sumW;

                    for (var col = 0; col < 2; col++)
                    {
                        var bg = col == 0 ? (R: 104f, G: 164f, B: 184f) : (R: 152f, G: 196f, B: 208f);
                        var target = 54 + (dstY * sheetW + col * boxSize + dstX) * 4;
                        bytes[target] = (byte)Math.Clamp((int)MathF.Round(avgB * alpha + bg.B * (1f - alpha)), 0, 255);
                        bytes[target + 1] = (byte)Math.Clamp((int)MathF.Round(avgG * alpha + bg.G * (1f - alpha)), 0, 255);
                        bytes[target + 2] = (byte)Math.Clamp((int)MathF.Round(avgR * alpha + bg.R * (1f - alpha)), 0, 255);
                        bytes[target + 3] = 255;
                    }
                }
            }
            return StoreBmp(bytes, 2, session);
        }
        catch (Exception error) when (error is IOException or InvalidDataException or ResourceFormatException or OverflowException)
        { return null; }
    }

    private static object? WallpaperFlatPreview(IffFile walls, IffFile patternFile, ushort patternSpriteId, string session)
    {
        try
        {
            const int srcW = 64;
            const int boxW = 160;
            const int boxH = 119;
            if (BuildFlatWall64x120(walls, patternFile, patternSpriteId) is not { } srcRgb)
                return null;

            var bytes = new byte[54 + boxW * boxH * 4];
            bytes[0] = (byte)'B'; bytes[1] = (byte)'M'; BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(2), bytes.Length);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(10), 54); BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(14), 40);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(18), boxW); BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(22), -boxH);
            BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(26), 1); BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(28), 32);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(34), boxW * boxH * 4);
            for (var i = 0; i < boxW * boxH; i++)
            {
                var t = 54 + i * 4;
                bytes[t] = 255; bytes[t + 2] = 255; bytes[t + 3] = 255;
            }

            const int dstX0 = (boxW - srcW) / 2;
            for (var dy = 0; dy < boxH; dy++)
            for (var sx = 0; sx < srcW; sx++)
            {
                var p = srcRgb[dy * srcW + sx];
                if (!p.Opaque) continue;
                var target = 54 + (dy * boxW + dstX0 + sx) * 4;
                bytes[target] = p.B;
                bytes[target + 1] = p.G;
                bytes[target + 2] = p.R;
                bytes[target + 3] = 255;
            }

            return StoreBmp(bytes, 1, session);
        }
        catch (Exception error) when (error is IOException or InvalidDataException or ResourceFormatException or OverflowException)
        { return null; }
    }

    internal static object? WallSegmentPreview(IffFile walls, IffFile patternFile, ushort style, ushort patternSpriteId, string session)
    {
        try
        {
            var patternChunk = patternFile.Find(ResourceType.Spr1, patternSpriteId);
            var maskId = SceneExporter.WallMaskId(style, down: false, zoom: 1);
            var maskChunk = walls.Find(ResourceType.Spr1, maskId);
            if (patternChunk is null || maskChunk is null) return null;
            var patternSprite = Sprite.Read(patternFile, patternChunk);
            var maskSprite = Sprite.Read(walls, maskChunk);
            var paletteChunk = patternFile.Find(ResourceType.Palt,
                checked((ushort)(patternSprite.PaletteId is >= 0 and <= ushort.MaxValue ? patternSprite.PaletteId : 0)))
                ?? patternFile.OfType(ResourceType.Palt).FirstOrDefault();
            if (paletteChunk is null || patternSprite.Frames.Count < 2 || maskSprite.Frames.Count < 2) return null;
            var colors = Palette.Read(patternFile, paletteChunk).Colors;

            const int boxW = 160;
            const int boxH = 119;
            var anchorX = boxW / 2;
            var baseY = (boxH * 3) / 4;
            var anchorY = style switch
            {
                2 or 13 or 14 => baseY - 16,
                12 => baseY - 2,
                _ => baseY + 14,
            };
            var bottomY = anchorY + 16;
            var faceLeftX = anchorX - 16;

            var bytes = new byte[54 + boxW * boxH * 4];
            bytes[0] = (byte)'B'; bytes[1] = (byte)'M'; BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(2), bytes.Length);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(10), 54); BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(14), 40);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(18), boxW); BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(22), -boxH);
            BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(26), 1); BinaryPrimitives.WriteInt16LittleEndian(bytes.AsSpan(28), 32);
            BinaryPrimitives.WriteInt32LittleEndian(bytes.AsSpan(34), boxW * boxH * 4);
            for (var i = 0; i < boxW * boxH; i++)
            {
                var t = 54 + i * 4;
                bytes[t] = 255; bytes[t + 2] = 255; bytes[t + 3] = 255;
            }

            void BlitMaskedFrame(IndexedFrame art, IndexedFrame mask, int dstX0, int dstY0, int clipX0, int clipWidth)
            {
                for (var sy = 0; sy < art.Height; sy++)
                {
                    var dy = dstY0 + sy;
                    if (dy < 0 || dy >= boxH) continue;
                    var my = sy * mask.Height / art.Height;
                    for (var sx = clipX0; sx < clipX0 + clipWidth && sx < art.Width; sx++)
                    {
                        var dx = dstX0 + (sx - clipX0);
                        if (dx < 0 || dx >= boxW) continue;
                        var idx = sy * art.Width + sx;
                        var mx = sx * mask.Width / art.Width;
                        if (!art.Opaque[idx] || !mask.Opaque[my * mask.Width + mx] || art.Indices[idx] >= colors.Count) continue;
                        var color = colors[art.Indices[idx]];
                        var target = 54 + (dy * boxW + dx) * 4;
                        bytes[target] = color.Blue; bytes[target + 1] = color.Green; bytes[target + 2] = color.Red; bytes[target + 3] = 255;
                    }
                }
            }

            var faceArt = patternSprite.Frames[1];
            var faceMask = maskSprite.Frames[1];
            var faceTopY = bottomY - faceArt.Height;
            if (style == 1)
            {
                var capArt = patternSprite.Frames[0];
                var capMask = maskSprite.Frames[0];
                BlitMaskedFrame(capArt, capMask, faceLeftX - 6, bottomY - capArt.Height, 0, 6);
            }
            BlitMaskedFrame(faceArt, faceMask, faceLeftX, faceTopY, 0, faceArt.Width);

            return StoreBmp(bytes, 1, session);
        }
        catch (Exception error) when (error is IOException or InvalidDataException or ResourceFormatException or OverflowException)
        { return null; }
    }
}
