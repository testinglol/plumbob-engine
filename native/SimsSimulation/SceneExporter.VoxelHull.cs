using System.Numerics;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;

namespace SimsSimulation;

internal static partial class SceneExporter
{
    private const float OrthoDepthHalfStep = 1f / 97.97959f;

    internal readonly record struct VoxelStamp(
        IffFile File,
        ushort GroupId,
        Objd Definition,
        int Direction,
        short[]? DynamicSpriteFlags,
        float OriginX,
        float OriginY,
        float OriginZ,
        int Level = 1,
        float GroundAoScale = 1f,
        bool IsFoliage = false);

    private static OverheadMapRecord BuildOrthoDepthMap(
        int lotSize,
        int cameraOrientation,
        List<VoxelStamp> stamps,
        Func<float, float, float>? elevation = null)
    {
        var cam0Orientation = cameraOrientation & 3;
        var cam1Orientation = (cameraOrientation + 1) & 3;
        var cam0 = new LotCamera(cam0Orientation, lotSize, lotSize);
        var cam1 = new LotCamera(cam1Orientation, lotSize, lotSize);
        var maxStampLevel = 2;
        for (var i = 0; i < stamps.Count; i++)
        {
            var lvl = stamps[i].Level;
            if (lvl > maxStampLevel && lvl <= LotGeometry.MaxSupportedStories)
                maxStampLevel = lvl;
        }
        var aoRows = Math.Max(1, (maxStampLevel + 3) / 4);
        var topMarginHalf = 64 + 256 * aoRows;
        var offsetPxY = topMarginHalf * 2;
        var mapWidth = lotSize * 32;
        var aoSize = lotSize * 8;
        var halfHeight = lotSize * 16 + 128 + 256 * aoRows;
        var totalHeight = halfHeight * 2 + aoRows * aoSize;
        var sliceLen = mapWidth * halfHeight;

        var front0 = new ushort[sliceLen];
        var back0 = new ushort[sliceLen];
        var front1 = new ushort[sliceLen];
        var back1 = new ushort[sliceLen];
        var mediumUnitHeight = (float)(Math.Sqrt(64 * 64 / 2.0) * Math.Cos(Math.PI / 6));
        var offsetPxX = lotSize * 32;

        var viewCams = new LotCamera[4];
        for (var c = 0; c < 4; c++)
            viewCams[c] = new LotCamera(c, lotSize, lotSize);

        var aoLen = aoSize * aoSize;
        var aoScales = new byte[]?[maxStampLevel + 1];
        var rawMaxZ = new byte[aoLen];
        var rawMinZ = new byte[aoLen];
        var rawS1MaxZ = new byte[aoLen];
        var rawUpMinZ = new byte[aoLen];
        List<(float Cx, float Cy, int Level)>? treeTrunks = null;

        for (var s = 0; s < stamps.Count; s++)
        {
            var stamp = stamps[s];
            var groupChunk = stamp.File.Find(ResourceType.Dgrp, stamp.GroupId);
            if (groupChunk is null) continue;

            DrawGroup group;
            try { group = CachedGroup(stamp.File, groupChunk); }
            catch (ResourceFormatException) { continue; }

            var dynamicBase = stamp.Definition[ObjdField.DynamicSpritesBaseId];
            var dynamicCount = stamp.Definition[ObjdField.NumDynamicSprites];
            var stampScaleByte = (byte)Math.Clamp((int)MathF.Round(stamp.GroundAoScale * 255f), 1, 255);
            var clampedStampLevel = Math.Clamp(stamp.Level, 1, maxStampLevel);
            var levelScaleMap = aoScales[clampedStampLevel] ??= new byte[aoLen];
            var maxRelZ = 0f;
            var trunkSumX = 0.0;
            var trunkSumY = 0.0;
            var trunkCount = 0;

            for (var cam = 0; cam < 4; cam++)
            {
                var image = SelectedImage(group, stamp.Direction, cam, zoom: 2);
                if (image is null || image.Sprites.Count == 0) continue;
                var viewCam = viewCams[cam];
                var isNative0 = cam == cam0Orientation;
                var isNative1 = cam == cam1Orientation;

                for (var idx = 0; idx < image.Sprites.Count; idx++)
                {
                    var sprite = image.Sprites[idx];
                    if (!DynamicSpriteVisible(sprite.SpriteId, dynamicBase, dynamicCount, stamp.DynamicSpriteFlags))
                        continue;
                    var (frame, legacy, width, height, paletteId) = ReadDgrpPart(stamp.File, sprite, 0, null);
                    if ((frame is null && legacy is null) || !FrameHasPixels(width, height)) continue;
                    var rgba = GetPartRgbaBytes(stamp.File, sprite, frame, legacy, width, height, paletteId);
                    if (rgba is null || rgba.Length < width * height * 4) continue;

                    var (offsetX, offsetY) = RotateCardinalOffset(stamp.Direction, sprite.Offset2, sprite.Offset3);
                    var anchor = viewCam.CameraPoint(stamp.OriginX + offsetX / 16f, stamp.OriginY + offsetY / 16f);
                    var altitude = stamp.OriginZ + sprite.Offset1 / 5f;
                    var baseKey = anchor.X + anchor.Y + 0.8f * altitude;
                    var partLeft = (anchor.X - anchor.Y) * 32f + sprite.X;
                    var partTop = (anchor.X + anchor.Y) * 16f - stamp.OriginZ * 40f - (sprite.Offset1 / 5f) * mediumUnitHeight - height + sprite.Y;
                    var flip = (sprite.Flags & 1) != 0;
                    var depthBytes = frame?.Depth;
                    var hasDepth = depthBytes is not null && depthBytes.Length >= width * height;

                    for (var v = 0; v < height; v++)
                    {
                        var sy = partTop + v + 0.5f;
                        var srcRow = v * width;
                        for (var u = 0; u < width; u++)
                        {
                            var srcIdx = srcRow + u;
                            if (rgba[srcIdx * 4 + 3] < 32) continue;
                            var key = baseKey;
                            if (hasDepth)
                            {
                                var d = depthBytes![srcIdx];
                                if (d >= 255) continue;
                                key = baseKey + (200 - d) * (2f * OrthoDepthHalfStep);
                            }

                            var sx = partLeft + (flip ? width - 1 - u : u) + 0.5f;
                            var z = (16f * key - sy) / 52.8f;
                            var sum = key - 0.8f * z;
                            var uTile = sx / 32f;
                            var vcx = 0.5f * (sum + uTile);
                            var vcy = 0.5f * (sum - uTile);
                            var srcLot = viewCam.SourcePoint(vcx, vcy);

                            // Project 3D point into View 0 (top half)
                            var p0 = cam0.CameraPoint(srcLot.X, srcLot.Y);
                            var relZ = z - stamp.OriginZ;
                            if (stamp.IsFoliage)
                            {
                                if (relZ > maxRelZ) maxRelZ = relZ;
                                if (relZ is >= -0.25f and < 0.65f)
                                {
                                    trunkSumX += p0.X;
                                    trunkSumY += p0.Y;
                                    trunkCount++;
                                }
                            }
                            if (relZ < 0.70f)
                            {
                                var sgx = (int)MathF.Floor(p0.X * 8f);
                                var sgy = (int)MathF.Floor(p0.Y * 8f);
                                if ((uint)sgx < (uint)aoSize && (uint)sgy < (uint)aoSize)
                                {
                                    var sIdx = sgy * aoSize + sgx;
                                    if (stampScaleByte > levelScaleMap[sIdx]) levelScaleMap[sIdx] = stampScaleByte;
                                }
                            }
                            if (p0.X >= -0.50f && p0.Y >= -0.50f && p0.X <= lotSize + 0.50f && p0.Y <= lotSize + 0.50f)
                            {
                                var cgx = Math.Clamp((int)MathF.Floor(p0.X * 8f), 0, aoSize - 1);
                                var cgy = Math.Clamp((int)MathF.Floor(p0.Y * 8f), 0, aoSize - 1);
                                var cIdx = cgy * aoSize + cgx;
                                var zHi = (byte)Math.Clamp((int)MathF.Ceiling((z + 4f) * 8f) + 1, 1, 255);
                                var zLo = (byte)Math.Clamp((int)MathF.Floor((z + 4f) * 8f) + 1, 1, 255);
                                if (zHi > rawMaxZ[cIdx]) rawMaxZ[cIdx] = zHi;
                                if (rawMinZ[cIdx] == 0 || zLo < rawMinZ[cIdx]) rawMinZ[cIdx] = zLo;
                                if (z < EntityTransform.StoryHeight)
                                {
                                    if (zHi > rawS1MaxZ[cIdx]) rawS1MaxZ[cIdx] = zHi;
                                }
                                else
                                {
                                    if (rawUpMinZ[cIdx] == 0 || zLo < rawUpMinZ[cIdx]) rawUpMinZ[cIdx] = zLo;
                                }
                            }
                            var key0 = p0.X + p0.Y + 0.8f * z;
                            var tx0 = isNative0 ? ((int)MathF.Floor(sx) + offsetPxX) >> 1 : (int)MathF.Floor((p0.X - p0.Y + lotSize) * 16f);
                            var ty0 = isNative0 ? ((int)MathF.Floor(sy) + offsetPxY) >> 1 : (int)MathF.Floor((p0.X + p0.Y) * 8f - z * 20f + topMarginHalf);
                            if ((uint)tx0 < (uint)mapWidth && (uint)ty0 < (uint)halfHeight)
                            {
                                var code0 = (ushort)Math.Clamp((int)MathF.Round((key0 + 16f) * 256f), 1, 65535);
                                var dst0 = ty0 * mapWidth + tx0;
                                if (isNative0 && code0 > front0[dst0]) front0[dst0] = code0;
                                if (back0[dst0] == 0 || code0 < back0[dst0]) back0[dst0] = code0;
                            }

                            // Project 3D point into View 1 (bottom half)
                            var p1 = cam1.CameraPoint(srcLot.X, srcLot.Y);
                            var key1 = p1.X + p1.Y + 0.8f * z;
                            var tx1 = isNative1 ? ((int)MathF.Floor(sx) + offsetPxX) >> 1 : (int)MathF.Floor((p1.X - p1.Y + lotSize) * 16f);
                            var ty1 = isNative1 ? ((int)MathF.Floor(sy) + offsetPxY) >> 1 : (int)MathF.Floor((p1.X + p1.Y) * 8f - z * 20f + topMarginHalf);
                            if ((uint)tx1 < (uint)mapWidth && (uint)ty1 < (uint)halfHeight)
                            {
                                var code1 = (ushort)Math.Clamp((int)MathF.Round((key1 + 16f) * 256f), 1, 65535);
                                var dst1 = ty1 * mapWidth + tx1;
                                if (isNative1 && code1 > front1[dst1]) front1[dst1] = code1;
                                if (back1[dst1] == 0 || code1 < back1[dst1]) back1[dst1] = code1;
                            }
                        }
                    }
                }
            }
            if (stamp.IsFoliage && maxRelZ > 1.4f && trunkCount > 0)
            {
                (treeTrunks ??= []).Add(((float)(trunkSumX / trunkCount), (float)(trunkSumY / trunkCount), stamp.Level));
            }
        }

        // Fill 1-texel reprojection gaps in back depth inside each native silhouette.
        static void FillBackHoles(ushort[] front, ushort[] back, int w, int h)
        {
            for (var y = 1; y < h - 1; y++)
            {
                var row = y * w;
                for (var x = 1; x < w - 1; x++)
                {
                    var i = row + x;
                    var f = front[i];
                    if (f == 0) continue;
                    var b = back[i];
                    if (b == 0 || b >= f)
                    {
                        var best = b == 0 ? f : b;
                        for (var dy = -1; dy <= 1; dy++)
                        {
                            var nr = (y + dy) * w;
                            for (var dx = -1; dx <= 1; dx++)
                            {
                                var nb = back[nr + x + dx];
                                if (nb != 0 && nb < best && (f - nb) <= 768)
                                    best = nb;
                            }
                        }
                        back[i] = best;
                    }
                }
            }
        }

        FillBackHoles(front0, back0, mapWidth, halfHeight);
        FillBackHoles(front1, back1, mapWidth, halfHeight);

        var pixels = new byte[mapWidth * totalHeight * 4];
        for (var i = 0; i < sliceLen; i++)
        {
            var f = front0[i];
            if (f != 0)
            {
                var b = back0[i];
                if (b == 0 || b > f) b = f;
                var p = i * 4;
                pixels[p] = (byte)(f >> 8);
                pixels[p + 1] = (byte)(f & 0xff);
                pixels[p + 2] = (byte)(b >> 8);
                pixels[p + 3] = (byte)(b & 0xff);
            }

            var f1 = front1[i];
            if (f1 != 0)
            {
                var b1 = back1[i];
                if (b1 == 0 || b1 > f1) b1 = f1;
                var p1 = (sliceLen + i) * 4;
                pixels[p1] = (byte)(f1 >> 8);
                pixels[p1 + 1] = (byte)(f1 & 0xff);
                pixels[p1 + 2] = (byte)(b1 >> 8);
                pixels[p1 + 3] = (byte)(b1 & 0xff);
            }
        }

        static float SmoothStep(float e0, float e1, float x)
        {
            var t = Math.Clamp((x - e0) / (e1 - e0), 0f, 1f);
            return t * t * (3f - 2f * t);
        }

        float SampleHullSlice(ushort[] front, ushort[] back, float opX, float opY, float key, float pad)
        {
            var px = opX - 0.5f;
            var py = opY - 0.5f;
            var ix = (int)MathF.Floor(px);
            var iy = (int)MathF.Floor(py);
            var fx = Math.Clamp(px - ix, 0f, 1f);
            var fy = Math.Clamp(py - iy, 0f, 1f);
            var x0 = Math.Clamp(ix, 0, mapWidth - 1);
            var x1 = Math.Clamp(ix + 1, 0, mapWidth - 1);
            var y0 = Math.Clamp(iy, 0, halfHeight - 1);
            var y1 = Math.Clamp(iy + 1, 0, halfHeight - 1);

            var i00 = y0 * mapWidth + x0;
            var i10 = y0 * mapWidth + x1;
            var i01 = y1 * mapWidth + x0;
            var i11 = y1 * mapWidth + x1;
            var f00 = front[i00];
            var f10 = front[i10];
            var f01 = front[i01];
            var f11 = front[i11];
            if ((f00 | f10 | f01 | f11) == 0) return 0f;

            float Eval(ushort fVal, ushort bVal)
            {
                if (fVal == 0) return 0f;
                var bEff = bVal == 0 || bVal > fVal ? fVal : bVal;
                var fk = fVal * (1f / 256f) - 16f;
                var bk = bEff * (1f / 256f) - 16f;
                return SmoothStep(-pad, 0.04f, fk - key) * SmoothStep(-pad, 0.04f, key - bk);
            }

            var v00 = Eval(f00, back[i00]);
            var v10 = Eval(f10, back[i10]);
            var v01 = Eval(f01, back[i01]);
            var v11 = Eval(f11, back[i11]);
            var top = v00 + (v10 - v00) * fx;
            var bot = v01 + (v11 - v01) * fx;
            return top + (bot - top) * fy;
        }

        float HullOcc(float cx, float cy, float z, float pad)
        {
            var op0X = (cx - cy + lotSize) * 16f;
            var op0Y = (cx + cy) * 8f - z * 20f + topMarginHalf;
            if (op0X < 0f || op0Y < 0f || op0X >= mapWidth || op0Y >= halfHeight) return 0f;
            var in0 = SampleHullSlice(front0, back0, op0X, op0Y, cx + cy + 0.8f * z, pad);
            if (in0 <= 0.01f) return 0f;

            var cx1 = lotSize - cy;
            var cy1 = cx;
            var op1X = (cx1 - cy1 + lotSize) * 16f;
            var op1Y = (cx1 + cy1) * 8f - z * 20f + topMarginHalf;
            if (op1X < 0f || op1Y < 0f || op1X >= mapWidth || op1Y >= halfHeight) return 0f;
            var in1 = SampleHullSlice(front1, back1, op1X, op1Y, cx1 + cy1 + 0.8f * z, pad);
            return MathF.Min(in0, in1);
        }

        static float[] MakeGaussianKernel(float sigma, int radius)
        {
            var k = new float[radius * 2 + 1];
            var inv2s2 = 1f / (2f * sigma * sigma);
            var sum = 0f;
            for (var i = -radius; i <= radius; i++)
            {
                var w = MathF.Exp(-(i * i) * inv2s2);
                k[i + radius] = w;
                sum += w;
            }
            for (var i = 0; i < k.Length; i++) k[i] /= sum;
            return k;
        }

        static void BlurRegion(float[] src, float[] tmp, float[] dst, int size, int x0, int x1, int y0, int y1, float[] kernel, int radius)
        {
            var bx0 = Math.Max(0, x0 - radius);
            var bx1 = Math.Min(size - 1, x1 + radius);
            var by0 = Math.Max(0, y0 - radius);
            var by1 = Math.Min(size - 1, y1 + radius);

            for (var y = y0; y <= y1; y++)
            {
                var row = y * size;
                for (var x = bx0; x <= bx1; x++)
                {
                    var acc = 0f;
                    for (var k = -radius; k <= radius; k++)
                    {
                        var sx = Math.Clamp(x + k, 0, size - 1);
                        acc += src[row + sx] * kernel[k + radius];
                    }
                    tmp[row + x] = acc;
                }
            }

            for (var y = by0; y <= by1; y++)
            {
                var row = y * size;
                for (var x = bx0; x <= bx1; x++)
                {
                    var acc = 0f;
                    for (var k = -radius; k <= radius; k++)
                    {
                        var sy = Math.Clamp(y + k, 0, size - 1);
                        acc += tmp[sy * size + x] * kernel[k + radius];
                    }
                    dst[row + x] = acc;
                }
            }
        }

        var kContact = MakeGaussianKernel(0.60f, 2);
        var kNear = MakeGaussianKernel(1.15f, 3);
        var kBroad = MakeGaussianKernel(2.15f, 5);
        float[]? rawContact = null;
        float[]? rawBody = null;
        float[]? blurTmp = null;
        float[]? outContact = null;
        float[]? outNear = null;
        float[]? outBroad = null;
        var activeTiles = new bool[lotSize * lotSize];
        var aoBaseOffset = sliceLen * 2 * 4;

        for (var lvl = 1; lvl <= maxStampLevel; lvl++)
        {
            var scaleMap = aoScales[lvl];
            Array.Clear(activeTiles);
            int minTx = lotSize, maxTx = -1, minTy = lotSize, maxTy = -1;
            for (var s = 0; s < stamps.Count; s++)
            {
                var st = stamps[s];
                if (st.Level != lvl) continue;
                var cp = cam0.CameraPoint(st.OriginX + 0.5f, st.OriginY + 0.5f);
                var cx = (int)MathF.Floor(cp.X);
                var cy = (int)MathF.Floor(cp.Y);
                var tx0 = Math.Max(0, cx - 3);
                var tx1 = Math.Min(lotSize - 1, cx + 3);
                var ty0 = Math.Max(0, cy - 3);
                var ty1 = Math.Min(lotSize - 1, cy + 3);
                if (tx0 < minTx) minTx = tx0;
                if (tx1 > maxTx) maxTx = tx1;
                if (ty0 < minTy) minTy = ty0;
                if (ty1 > maxTy) maxTy = ty1;
                for (var ty = ty0; ty <= ty1; ty++)
                for (var tx = tx0; tx <= tx1; tx++)
                    activeTiles[ty * lotSize + tx] = true;
            }

            if (minTx > maxTx) continue;

            rawContact ??= new float[aoLen];
            rawBody ??= new float[aoLen];
            blurTmp ??= new float[aoLen];
            outContact ??= new float[aoLen];
            outNear ??= new float[aoLen];
            outBroad ??= new float[aoLen];
            if (lvl > 1)
            {
                Array.Clear(rawContact);
                Array.Clear(rawBody);
                Array.Clear(blurTmp);
                Array.Clear(outContact);
                Array.Clear(outNear);
                Array.Clear(outBroad);
            }

            var storyLift = (lvl - 1) * EntityTransform.StoryHeight;
            float CornerZ(int tx, int ty)
            {
                if (elevation is null) return storyLift;
                var sp = cam0.SourcePoint(tx, ty);
                return elevation(sp.X, sp.Y) * (1f / 40f) + storyLift;
            }

            for (var ty = minTy; ty <= maxTy; ty++)
            {
                for (var tx = minTx; tx <= maxTx; tx++)
                {
                    if (!activeTiles[ty * lotSize + tx]) continue;
                    var z00 = CornerZ(tx, ty);
                    var z10 = CornerZ(tx + 1, ty);
                    var z01 = CornerZ(tx, ty + 1);
                    var z11 = CornerZ(tx + 1, ty + 1);
                    for (var sy = 0; sy < 8; sy++)
                    {
                        var gy = ty * 8 + sy;
                        var rowIdx = gy * aoSize + tx * 8;
                        for (var sx = 0; sx < 8; sx++)
                        {
                            var gx = tx * 8 + sx;
                            var aoScale = 1f;
                            if (scaleMap is not null)
                            {
                                byte bestScale = 0;
                                var ny0 = Math.Max(0, gy - 1);
                                var ny1 = Math.Min(aoSize - 1, gy + 1);
                                var nx0 = Math.Max(0, gx - 1);
                                var nx1 = Math.Min(aoSize - 1, gx + 1);
                                for (var ny = ny0; ny <= ny1; ny++)
                                {
                                    var nRow = ny * aoSize;
                                    for (var nx = nx0; nx <= nx1; nx++)
                                    {
                                        var sv = scaleMap[nRow + nx];
                                        if (sv > bestScale) bestScale = sv;
                                    }
                                }
                                if (bestScale > 0) aoScale = bestScale * (1f / 255f);
                            }

                            float cSum = 0f, bSum = 0f;
                            for (var qy = 0; qy < 2; qy++)
                            {
                                var v = (sy * 2 + qy + 0.5f) * (1f / 16f);
                                var cy = ty + v;
                                for (var qx = 0; qx < 2; qx++)
                                {
                                    var u = (sx * 2 + qx + 0.5f) * (1f / 16f);
                                    var cx = tx + u;
                                    var z0 = (z00 + (z10 - z00) * u) * (1f - v) + (z01 + (z11 - z01) * u) * v;
                                    var h0 = HullOcc(cx, cy, z0 + 0.04f, 0.05f);
                                    var h1 = HullOcc(cx, cy, z0 + 0.12f, 0.06f);
                                    var h2 = HullOcc(cx, cy, z0 + 0.26f, 0.07f);
                                    var h3 = HullOcc(cx, cy, z0 + 0.46f, 0.07f);
                                    cSum += 0.72f * h0 + 0.28f * h1;
                                    bSum += 0.45f * h0 + 0.27f * h1 + 0.18f * h2 + 0.10f * h3;
                                }
                            }
                            rawContact[rowIdx + sx] = cSum * 0.25f * aoScale;
                            rawBody[rowIdx + sx] = bSum * 0.25f * aoScale;
                        }
                    }
                }
            }

            if (treeTrunks is not null)
            {
                foreach (var (tcx, tcy, tLvl) in treeTrunks)
                {
                    if (tLvl != lvl) continue;
                    var gx0 = Math.Max(0, (int)MathF.Floor((tcx - 0.55f) * 8f));
                    var gx1 = Math.Min(aoSize - 1, (int)MathF.Ceiling((tcx + 0.55f) * 8f));
                    var gy0 = Math.Max(0, (int)MathF.Floor((tcy - 0.55f) * 8f));
                    var gy1 = Math.Min(aoSize - 1, (int)MathF.Ceiling((tcy + 0.55f) * 8f));
                    for (var gy = gy0; gy <= gy1; gy++)
                    {
                        var dy = (gy + 0.5f) * (1f / 8f) - tcy;
                        var rowIdx = gy * aoSize;
                        for (var gx = gx0; gx <= gx1; gx++)
                        {
                            var dx = (gx + 0.5f) * (1f / 8f) - tcx;
                            var dist = MathF.Sqrt(dx * dx + dy * dy);
                            var cDisk = 0.95f * SmoothStep(0.32f, 0.04f, dist);
                            var bDisk = 0.85f * SmoothStep(0.48f, 0.06f, dist);
                            var idx = rowIdx + gx;
                            if (cDisk > rawContact[idx]) rawContact[idx] = cDisk;
                            if (bDisk > rawBody[idx]) rawBody[idx] = bDisk;
                        }
                    }
                }
            }

            var pxMinX = minTx * 8;
            var pxMaxX = maxTx * 8 + 7;
            var pxMinY = minTy * 8;
            var pxMaxY = maxTy * 8 + 7;
            var clearY0 = Math.Max(0, pxMinY - 5);
            var clearRows = Math.Min(aoSize - 1, pxMaxY + 5) - clearY0 + 1;
            BlurRegion(rawContact, blurTmp, outContact, aoSize, pxMinX, pxMaxX, pxMinY, pxMaxY, kContact, 2);
            Array.Clear(blurTmp, clearY0 * aoSize, clearRows * aoSize);
            BlurRegion(rawBody, blurTmp, outNear, aoSize, pxMinX, pxMaxX, pxMinY, pxMaxY, kNear, 3);
            Array.Clear(blurTmp, clearY0 * aoSize, clearRows * aoSize);
            BlurRegion(rawBody, blurTmp, outBroad, aoSize, pxMinX, pxMaxX, pxMinY, pxMaxY, kBroad, 5);

            var wx0 = Math.Max(0, pxMinX - 5);
            var wx1 = Math.Min(aoSize - 1, pxMaxX + 5);
            var wy0 = Math.Max(0, pxMinY - 5);
            var wy1 = Math.Min(aoSize - 1, pxMaxY + 5);
            var sliceIdx = lvl - 1;
            var xSliceOffset = (sliceIdx & 3) * aoSize;
            var ySliceOffset = (sliceIdx >> 2) * aoSize;
            for (var gy = wy0; gy <= wy1; gy++)
            {
                var srcRow = gy * aoSize;
                var dstRow = aoBaseOffset + ((ySliceOffset + gy) * mapWidth + xSliceOffset) * 4;
                for (var gx = wx0; gx <= wx1; gx++)
                {
                    var cVal = 1f - MathF.Exp(-outContact[srcRow + gx] * 1.95f);
                    var nVal = 1f - MathF.Exp(-outNear[srcRow + gx] * 1.35f);
                    var bVal = Math.Clamp(outBroad[srcRow + gx] * 0.82f, 0f, 1f);
                    if (cVal < 0.003f && nVal < 0.003f && bVal < 0.003f) continue;
                    var p = dstRow + gx * 4;
                    pixels[p] = (byte)Math.Clamp((int)MathF.Round(cVal * 255f), 0, 255);
                    pixels[p + 1] = (byte)Math.Clamp((int)MathF.Round(nVal * 255f), 0, 255);
                    pixels[p + 2] = (byte)Math.Clamp((int)MathF.Round(bVal * 255f), 0, 255);
                    pixels[p + 3] = 255;
                }
            }
        }

        const int colDilate = 3;
        var tmpMaxZ = new byte[aoLen];
        var tmpMinZ = new byte[aoLen];
        var tmpS1MaxZ = new byte[aoLen];
        var tmpUpMinZ = new byte[aoLen];
        for (var gy = 0; gy < aoSize; gy++)
        {
            var row = gy * aoSize;
            for (var gx = 0; gx < aoSize; gx++)
            {
                var kx0 = Math.Max(0, gx - colDilate);
                var kx1 = Math.Min(aoSize - 1, gx + colDilate);
                byte mx = 0, mn = 0, s1Mx = 0, upMn = 0;
                for (var kx = kx0; kx <= kx1; kx++)
                {
                    var idx = row + kx;
                    var hi = rawMaxZ[idx];
                    if (hi > mx) mx = hi;
                    var lo = rawMinZ[idx];
                    if (lo != 0 && (mn == 0 || lo < mn)) mn = lo;
                    var s1 = rawS1MaxZ[idx];
                    if (s1 > s1Mx) s1Mx = s1;
                    var up = rawUpMinZ[idx];
                    if (up != 0 && (upMn == 0 || up < upMn)) upMn = up;
                }
                tmpMaxZ[row + gx] = mx;
                tmpMinZ[row + gx] = mn;
                tmpS1MaxZ[row + gx] = s1Mx;
                tmpUpMinZ[row + gx] = upMn;
            }
        }
        var dilMaxZ = new byte[aoLen];
        for (var gy = 0; gy < aoSize; gy++)
        {
            var ky0 = Math.Max(0, gy - colDilate);
            var ky1 = Math.Min(aoSize - 1, gy + colDilate);
            var row0 = aoBaseOffset + gy * mapWidth * 4;
            var row1 = row0 + aoSize * 4;
            var row2 = row0 + aoSize * 8;
            var row3 = row0 + aoSize * 12;
            var dRow = gy * aoSize;
            for (var gx = 0; gx < aoSize; gx++)
            {
                byte mx = 0, mn = 0, s1Mx = 0, upMn = 0;
                for (var ky = ky0; ky <= ky1; ky++)
                {
                    var idx = ky * aoSize + gx;
                    var hi = tmpMaxZ[idx];
                    if (hi > mx) mx = hi;
                    var lo = tmpMinZ[idx];
                    if (lo != 0 && (mn == 0 || lo < mn)) mn = lo;
                    var s1 = tmpS1MaxZ[idx];
                    if (s1 > s1Mx) s1Mx = s1;
                    var up = tmpUpMinZ[idx];
                    if (up != 0 && (upMn == 0 || up < upMn)) upMn = up;
                }
                dilMaxZ[dRow + gx] = mx;
                pixels[row0 + gx * 4 + 3] = mx;
                pixels[row1 + gx * 4 + 3] = mn;
                pixels[row2 + gx * 4 + 3] = s1Mx;
                pixels[row3 + gx * 4 + 3] = upMn;
            }
        }

        var cheb = new byte[aoLen];
        for (var gy = 0; gy < aoSize; gy++)
        {
            var r = gy * aoSize;
            for (var gx = 0; gx < aoSize; gx++)
            {
                if (dilMaxZ[r + gx] != 0)
                {
                    cheb[r + gx] = 0;
                    continue;
                }
                int best = 255;
                if (gx > 0 && cheb[r + gx - 1] + 1 < best) best = cheb[r + gx - 1] + 1;
                if (gy > 0)
                {
                    var pr = r - aoSize;
                    if (cheb[pr + gx] + 1 < best) best = cheb[pr + gx] + 1;
                    if (gx > 0 && cheb[pr + gx - 1] + 1 < best) best = cheb[pr + gx - 1] + 1;
                    if (gx + 1 < aoSize && cheb[pr + gx + 1] + 1 < best) best = cheb[pr + gx + 1] + 1;
                }
                cheb[r + gx] = (byte)best;
            }
        }
        for (var gy = aoSize - 1; gy >= 0; gy--)
        {
            var r = gy * aoSize;
            var row1 = aoBaseOffset + gy * mapWidth * 4 + aoSize * 4;
            for (var gx = aoSize - 1; gx >= 0; gx--)
            {
                int best = cheb[r + gx];
                if (best != 0)
                {
                    if (gx + 1 < aoSize && cheb[r + gx + 1] + 1 < best) best = cheb[r + gx + 1] + 1;
                    if (gy + 1 < aoSize)
                    {
                        var nr = r + aoSize;
                        if (cheb[nr + gx] + 1 < best) best = cheb[nr + gx] + 1;
                        if (gx > 0 && cheb[nr + gx - 1] + 1 < best) best = cheb[nr + gx - 1] + 1;
                        if (gx + 1 < aoSize && cheb[nr + gx + 1] + 1 < best) best = cheb[nr + gx + 1] + 1;
                    }
                    cheb[r + gx] = (byte)best;
                    pixels[row1 + gx * 4 + 3] = (byte)best;
                }
            }
        }

        return new OverheadMapRecord(mapWidth, totalHeight, 32, pixels);
    }
}
