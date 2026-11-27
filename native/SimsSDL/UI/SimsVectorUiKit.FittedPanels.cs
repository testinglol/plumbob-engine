using System.Collections.Concurrent;
using System.Text.Json;
using SimsSDL.Core;

namespace SimsSDL.UI;

public static partial class SimsVectorUiKit
{
    private static readonly ConcurrentDictionary<string, FittedPanel> FittedPanels = new(StringComparer.Ordinal);
    private static readonly ConcurrentDictionary<int, float[]> MasterRibbonSdfByScale = new();

    public enum ModePatchKind
    {
        Live,
        Buy,
        Build,
        Camera,
        Options,
    }

    public static VectorBannerRenderer.RasterImage RenderControlPanelModePatch(ModePatchKind kind, int scale = 8)
    {
        scale = Math.Clamp(scale, 1, 8);
        string key = $"modepatch_v1:{kind}:{scale}";
        if (Cache.TryGetValue(key, out var cached))
            return cached;

        (int ox, int oy, int w1x, int h1x, float cx, float cy, float arcR, float arcHw, float a0Deg, float a1Deg,
         float bx, float by, float br, float sx, float sy, float tx, float ty, float capR) = kind switch
        {
            ModePatchKind.Live => (7, 30, 213, 153, 35.53f, 30.11f, 25.788f, 1.031f, 14.325f, 173.016f, 34.078f, 59.5f, 1.561f, 20.5f, 63.5f, 0.99f, 0.14f, 3.0f),
            ModePatchKind.Buy => (64, 35, 156, 148, 91.718f, 42.401f, 23.293f, 1.024f, 24.916f, 190.334f, 84.768f, 67.722f, 1.264f, 71.391f, 70.059f, 0.94f, 0.34f, 2.332f),
            ModePatchKind.Build => (113, 51, 107, 132, 136.825f, 63.363f, 20.05f, 0.776f, 37.0f, 204.75f, 126.048f, 83.722f, 1.461f, 117.223f, 85.177f, 0.86f, 0.51f, 2.098f),
            ModePatchKind.Camera => (165, 83, 55, 100, 189.218f, 109.059f, 15.232f, 0.77f, 63.416f, 224.834f, 176.56f, 121.322f, 1.222f, 169.5f, 118.802f, 0.67f, 0.74f, 2.0f),
            _ => (183, 83, 37, 100, 203.878f, 135.901f, 11.363f, 0.654f, 73.166f, 240.334f, 192.57f, 143.177f, 1.15f, 186.8f, 138.5f, 0.52f, 0.85f, 1.636f),
        };

        float[] dMaster = MasterRibbonSdfByScale.GetOrAdd(scale, static s =>
        {
            var lp = FittedPanels.GetOrAdd("livepatch", LoadFittedPanel);
            float[] src = lp.Layers[0].Contours[2];
            float[] shifted = new float[src.Length];
            for (int i = 0; i < src.Length; i += 2)
            {
                shifted[i] = src[i] + 7f;
                shifted[i + 1] = src[i + 1] + 30f;
            }
            float[] raw = PanelDistanceField([shifted], 220 * s, 183 * s, s, 6f);
            for (int i = 0; i < raw.Length; i++)
                raw[i] -= 0.05f;
            return raw;
        });

        int ubW = 220 * scale;
        int ubH = 183 * scale;
        int pw = w1x * scale;
        int ph = h1x * scale;
        byte[] rgba = new byte[pw * ph * 4];
        float inv = 1f / scale;

        float aMid = (a0Deg + a1Deg) * (0.5f * MathF.PI / 180f);
        float aHalf = (a1Deg - a0Deg) * (0.5f * MathF.PI / 180f);
        float cosMid = MathF.Cos(aMid), sinMid = MathF.Sin(aMid);
        float cosHalf = MathF.Cos(aHalf), sinHalf = MathF.Sin(aHalf);
        float endX = arcR * cosHalf, endY = arcR * sinHalf;

        float tNorm = MathF.Sqrt(tx * tx + ty * ty);
        float utx = tx / tNorm, uty = ty / tNorm;
        bool clipStart = kind != ModePatchKind.Live;

        float SdCradleAndBead(float x, float y)
        {
            float dx = x - cx, dy = y - cy;
            float rx = cosMid * dx + sinMid * dy;
            float ry = MathF.Abs(-sinMid * dx + cosMid * dy);
            float r = MathF.Sqrt(rx * rx + ry * ry);
            float sdArc = rx >= r * cosHalf
                ? MathF.Abs(r - arcR) - arcHw
                : MathF.Sqrt((rx - endX) * (rx - endX) + (ry - endY) * (ry - endY)) - arcHw;
            float dBead = br - MathF.Sqrt((x - bx) * (x - bx) + (y - by) * (y - by));
            return MathF.Max(-sdArc, dBead);
        }

        float SampleRibbon(float x, float y)
        {
            float fx = Math.Clamp(x * scale - 0.5f, 0f, ubW - 1.001f);
            float fy = Math.Clamp(y * scale - 0.5f, 0f, ubH - 1.001f);
            int x0 = (int)fx, y0 = (int)fy;
            float kx = fx - x0, ky = fy - y0;
            int r0 = y0 * ubW, r1 = (y0 + 1) * ubW;
            float d = (dMaster[r0 + x0] * (1f - kx) + dMaster[r0 + x0 + 1] * kx) * (1f - ky)
                    + (dMaster[r1 + x0] * (1f - kx) + dMaster[r1 + x0 + 1] * kx) * ky;
            if (!clipStart)
                return d;
            float u = (x - sx) * utx + (y - sy) * uty;
            if (u >= 0f)
                return d;
            float v = -(x - sx) * uty + (y - sy) * utx;
            float dCap = capR - MathF.Sqrt(u * u + v * v);
            return MathF.Min(d, dCap);
        }

        Parallel.For(0, ph, py =>
        {
            float y = oy + (py + 0.5f) * inv;
            float bridgeT = SmoothStep(147f, 153f, y);
            float dxRib = 0.85f * (1f - bridgeT);
            int rowOff = py * pw;

            for (int px = 0; px < pw; px++)
            {
                float x = ox + (px + 0.5f) * inv;
                float dCb = SdCradleAndBead(x, y);
                float dRib = SampleRibbon(x, y);
                float dAll = MathF.Max(dCb, dRib);
                float afg = Math.Clamp(0.5f + dAll * scale, 0f, 1f);

                float dCbSh = SdCradleAndBead(x - 0.90f, y - 0.95f);
                float shCb = Math.Clamp(0.5f + dCbSh * scale * 0.75f, 0f, 1f) * 0.92f;

                float dRibSh = SampleRibbon(x - dxRib, y - 0.95f);
                float rightMask = 1f - SmoothStep(212f, 214f, x);
                float opRib = (0.92f * (1f - bridgeT) + 0.52f * bridgeT) * rightMask;
                float shRib = Math.Clamp(0.5f + dRibSh * scale * 0.75f, 0f, 1f) * opRib;

                float sh = MathF.Max(shCb, shRib);
                float under = sh * (1f - afg);
                float outA = afg + under;
                if (outA <= 0.001f)
                    continue;

                float cr = Math.Clamp(254f - MathF.Max(0f, 3.60311f * x - 0.00248f * y - 655.47535f), 100f, 254f);
                float cg = Math.Clamp(254f - MathF.Max(0f, 2.81570f * x - 0.09701f * y - 493.59143f), 100f, 254f);
                float cb = Math.Clamp(254f - MathF.Max(0f, 2.39775f * x - 0.11034f * y - 412.32616f), 100f, 254f);
                if (x > 210.5f && dRib > -1f)
                {
                    float rightRim = SmoothStep(210.5f, 212.8f, x) * (1f - SmoothStep(0.6f, 2.0f, dRib));
                    cr = Lerp(cr, 136f, rightRim);
                    cg = Lerp(cg, 137f, rightRim);
                    cb = Lerp(cb, 165f, rightRim);
                }

                float scaleRgb = afg / outA;
                int dst = (rowOff + px) * 4;
                rgba[dst] = Byte(cr * scaleRgb);
                rgba[dst + 1] = Byte(cg * scaleRgb);
                rgba[dst + 2] = Byte(cb * scaleRgb);
                rgba[dst + 3] = Byte(outA * 255f);
            }
        });

        var img = new VectorBannerRenderer.RasterImage(pw, ph, rgba, new CGSize(w1x, h1x));
        Cache[key] = img;
        return img;
    }

    public static VectorBannerRenderer.RasterImage RenderFittedPanel(string name, int scale = 4)
    {
        scale = Math.Clamp(scale, 1, 8);
        string key = $"panel_fit_v50:{name}:{scale}";
        if (Cache.TryGetValue(key, out var cached))
            return cached;

        var panel = FittedPanels.GetOrAdd(name, LoadFittedPanel);
        int pw = panel.Width * scale;
        int ph = panel.Height * scale;
        int n = pw * ph;
        int layerCount = panel.Layers.Length;
        float reach = panel.HeightStops[^1] + 1f;
        float inv = 1f / scale;

        var dists = new float[layerCount][];
        for (int li = 0; li < layerCount; li++)
            dists[li] = PanelDistanceField(panel.Layers[li].Contours, pw, ph, scale, reach);

        var bevelDists = new float[layerCount][];
        for (int li = 0; li < layerCount; li++)
        {
            float[] raw = dists[li];
            if (li == 0 && layerCount > 1)
            {
                raw = new float[n];
                float[] d0 = dists[0];
                float[] d1 = dists[1];
                for (int i = 0; i < n; i++)
                    raw[i] = MathF.Min(d0[i], -d1[i]);
            }
            else if (li == 1 && layerCount >= 5)
            {
                // Cut recessed bevel groove into field around housing (layer 2).
                raw = new float[n];
                float[] d1 = dists[1];
                float[] d2 = dists[2];
                for (int i = 0; i < n; i++)
                    raw[i] = MathF.Min(d1[i], -d2[i]);
            }
            bevelDists[li] = panel.CornerSmooth > 0.01f
                ? SepGaussianBlurSdf(raw, pw, ph, panel.CornerSmooth * scale, scale)
                : raw;
        }

        float[]? padRecessSdf = null;
        if (panel.PadRecess > 0.001f && layerCount >= 5)
        {
            float pSmooth = panel.PadRecessSmooth > 0f ? panel.PadRecessSmooth : panel.CornerSmooth;
            padRecessSdf = pSmooth > 0.01f
                ? SepGaussianBlurSdf(dists[4], pw, ph, pSmooth * scale, scale)
                : dists[4];
        }
        float padRecessW = panel.PadRecessWidth > 0.1f ? panel.PadRecessWidth : 4.5f;

        var weights = new float[layerCount][];
        var layerHeights = new float[layerCount][];
        for (int li = 0; li < layerCount; li++)
        {
            weights[li] = new float[n];
            layerHeights[li] = new float[n];
        }
        float[] compositeHeight = new float[n];
        Parallel.For(0, n, i =>
        {
            float rest = 1f;
            float padRecessDelta = 0f;
            if (padRecessSdf is not null)
            {
                float outD = MathF.Max(0f, -padRecessSdf[i]);
                if (outD < padRecessW)
                {
                    float g = 1f - outD / padRecessW;
                    padRecessDelta = panel.PadRecess * 5.5f * g * g * (3f - 2f * g);
                }
            }
            float wellsRecessDelta = 0f;
            if (panel.WellsRecess > 0.001f && layerCount >= 5)
            {
                float outD = MathF.Max(0f, -bevelDists[3][i]);
                if (outD < 4.5f)
                {
                    float g = 1f - outD / 4.5f;
                    wellsRecessDelta = panel.WellsRecess * 10f * g * g * (3f - 2f * g);
                }
            }

            for (int li = layerCount - 1; li >= 0; li--)
            {
                float d = dists[li][i];
                float c = Math.Clamp(0.5f + d * scale, 0f, 1f);
                float w = c * rest;
                weights[li][i] = w;
                rest *= 1f - c;

                float lh = Profile(panel.Layers[li].Profile, bevelDists[li][i]);
                if (li is 1 or 2)
                    lh -= padRecessDelta;
                if (li == 2)
                    lh -= wellsRecessDelta;
                layerHeights[li][i] = lh;
                compositeHeight[i] += w * lh;
            }
        });

        float effNormalBlur = MathF.Max(panel.NormalBlur, 0.35f) * scale;
        var layerSmooth = new float[layerCount][];
        var layerCreaseBase = new float[layerCount][];
        for (int li = 0; li < layerCount; li++)
        {
            layerSmooth[li] = SepGaussianBlur(layerHeights[li], pw, ph, effNormalBlur);
            layerCreaseBase[li] = SepGaussianBlur(layerHeights[li], pw, ph, MathF.Max(panel.CreaseBlur, 0.35f) * scale);
        }
        float[] cast = CastShadow(compositeHeight, pw, ph, panel.LightAngle, panel.CastReach, scale);

        float lx = MathF.Cos(panel.LightAltitude) * MathF.Cos(panel.LightAngle);
        float ly = MathF.Cos(panel.LightAltitude) * MathF.Sin(panel.LightAngle);
        float lz = MathF.Sin(panel.LightAltitude);
        float hz = 1f + lz;
        float hn = MathF.Sqrt(lx * lx + ly * ly + hz * hz);
        float flatSpec = MathF.Pow(hz / hn, panel.Gloss);
        float[][][] gains = panel.Layers
            .Select(l => new[] { l.Highlight, l.Shadow, l.Specular, l.Crease, l.Ridge, l.Cast })
            .ToArray();

        byte[] rgba = new byte[n * 4];
        Parallel.For(0, ph, py =>
        {
            Span<float> terms = stackalloc float[6];
            float y = (py + 0.5f) * inv;
            int yUp = Math.Max(py - 1, 0), yDown = Math.Min(py + 1, ph - 1);
            for (int px = 0; px < pw; px++)
            {
                int i = py * pw + px;
                int xLeft = Math.Max(px - 1, 0), xRight = Math.Min(px + 1, pw - 1);
                float x = (px + 0.5f) * inv;
                float r = 0f, g = 0f, b = 0f;
                for (int li = 0; li < layerCount; li++)
                {
                    float w = weights[li][i];
                    if (w <= 0f)
                        continue;

                    float[] sm = layerSmooth[li];
                    float[] lh = layerHeights[li];
                    float[] cb = layerCreaseBase[li];
                    float gx = (sm[py * pw + xRight] - sm[py * pw + xLeft]) / (xRight - xLeft) * scale;
                    float gy = (sm[yDown * pw + px] - sm[yUp * pw + px]) / (yDown - yUp) * scale;
                    float nz = 1f / MathF.Sqrt(1f + gx * gx + gy * gy);
                    float diffuse = (-gx * lx - gy * ly + lz) * nz - lz;
                    float ndh = (-gx * lx - gy * ly + hz) * nz / hn;
                    float crease = cb[i] - lh[i];
                    terms[0] = MathF.Max(0f, diffuse);
                    float rawShadow = MathF.Max(0f, -diffuse);
                    float dirShadow = rawShadow > 0f ? MathF.Pow(rawShadow, 0.55f) * 0.85f : 0f;
                    if (panel.ShadowWrap > 0.001f)
                    {
                        float slope = MathF.Sqrt(gx * gx + gy * gy) * nz;
                        float notLit = 1f - Math.Clamp(terms[0] * 1.8f, 0f, 1f);
                        float evenShadow = MathF.Min(1f, slope * 1.25f) * notLit * 0.85f;
                        terms[1] = Lerp(dirShadow, evenShadow, Math.Clamp(panel.ShadowWrap, 0f, 1f));
                    }
                    else
                    {
                        terms[1] = dirShadow;
                    }
                    terms[2] = MathF.Max(0f, MathF.Pow(MathF.Max(0f, ndh), panel.Gloss) - flatSpec);
                    terms[3] = MathF.Max(0f, crease);
                    terms[4] = MathF.Max(0f, -crease);
                    terms[5] = cast[i];

                    var layer = panel.Layers[li];
                    float shadeD = li == 0 ? MathF.Max(panel.EdgeInset, dists[0][i]) : dists[li][i];
                    var c = StopShade(layer.Flat, panel.HeightStops, shadeD);
                    if (panel.Zones.Length > 0)
                    {
                        float restZ = 1f;
                        for (int z = 0; z < panel.Zones.Length; z++)
                        {
                            float[] zone = panel.Zones[z];
                            float zw = Math.Clamp((zone[2] - MathF.Sqrt((x - zone[0]) * (x - zone[0]) + (y - zone[1]) * (y - zone[1]))) / zone[3] + 0.5f, 0f, 1f);
                            restZ *= 1f - zw;
                        }
                        c = (c.R * restZ, c.G * restZ, c.B * restZ);
                        for (int z = 0; z < panel.Zones.Length; z++)
                        {
                            float[] zone = panel.Zones[z];
                            float[] zf = layer.ZoneFlat[z];
                            float dxz = x - zone[0], dyz = y - zone[1];
                            float zw = Math.Clamp((zone[2] - MathF.Sqrt(dxz * dxz + dyz * dyz)) / zone[3] + 0.5f, 0f, 1f);
                            float gxZ = zf.Length >= 6 ? zw * dxz / MathF.Max(1e-4f, zone[2]) : 0f;
                            float gyZ = zf.Length >= 9 ? zw * dyz / MathF.Max(1e-4f, zone[2]) : 0f;
                            c = (
                                c.R + zw * zf[0] + (zf.Length >= 6 ? gxZ * zf[3] : 0f) + (zf.Length >= 9 ? gyZ * zf[6] : 0f),
                                c.G + zw * zf[1] + (zf.Length >= 6 ? gxZ * zf[4] : 0f) + (zf.Length >= 9 ? gyZ * zf[7] : 0f),
                                c.B + zw * zf[2] + (zf.Length >= 6 ? gxZ * zf[5] : 0f) + (zf.Length >= 9 ? gyZ * zf[8] : 0f));
                        }
                    }
                    float[][] lg = gains[li];
                    float specVal = terms[2];
                    if (layerCount >= 5 && li is 1 or 2)
                    {
                        float outPad = -dists[4][i];
                        if (li == 1)
                        {
                            float padMask = SmoothStep(4.0f, 7.0f, outPad);
                            float botMask = 1f - SmoothStep(panel.Height - 10.5f, panel.Height - 5.5f, y);
                            specVal *= padMask * botMask;
                        }
                        else
                        {
                            // Fade contact specular right against pad's overhanging rim and roll off into the bottom screen bevel.
                            float padContact = SmoothStep(0.4f, 2.4f, outPad);
                            float botCorner = x < 62f ? 1f - SmoothStep(panel.Height - 13.5f, panel.Height - 4.5f, y) : 1f;
                            specVal *= padContact * botCorner;
                        }
                    }
                    for (int t = 0; t < lg.Length; t++)
                    {
                        float tv = t == 2 ? specVal : terms[t];
                        c = (c.R + tv * lg[t][0], c.G + tv * lg[t][1], c.B + tv * lg[t][2]);
                    }
                    r += w * c.R;
                    g += w * c.G;
                    b += w * c.B;
                }

                float a = Math.Clamp(0.5f + dists[0][i] * scale, 0f, 1f);
                float ia = a > 1e-4f ? 1f / a : 0f;
                float pr = r * ia, pg = g * ia, pb = b * ia;
                if (panel.ShadowDepth > 0.001f)
                {
                    float castNorm = cast[i] / (cast[i] + 10f);
                    float sDark = Math.Clamp(panel.ShadowDepth * (0.30f * terms[1] + 0.40f * castNorm), 0f, 0.45f);
                    float sMul = 1f - sDark;
                    pr *= sMul;
                    pg *= sMul;
                    pb *= sMul;
                }
                // Crisp tight bottom/bottom-right rim highlight on recessed LCD wells (layer 3)
                // using the well contour's own inward normal so it always hugs the bottom lip.
                if (panel.RimBounce > 0.001f && layerCount >= 5 && weights[3][i] > 0.01f)
                {
                    float[] d3 = dists[3];
                    float rimEdge = Math.Clamp(1f - MathF.Max(0f, d3[i]) / 2.2f, 0f, 1f);
                    if (rimEdge > 0f)
                    {
                        float nx3 = (d3[py * pw + xRight] - d3[py * pw + xLeft]) / (xRight - xLeft);
                        float ny3 = (d3[yDown * pw + px] - d3[yUp * pw + px]) / (yDown - yUp);
                        float invLen = 1f / MathF.Max(1e-4f, MathF.Sqrt(nx3 * nx3 + ny3 * ny3));
                        // Inward normal (nx3, ny3) points UP on the bottom rim; dot with upper-left light (lx, ly).
                        float rimDot = MathF.Max(0f, (nx3 * lx + ny3 * ly) * invLen);
                        float rimSpec = MathF.Pow(rimDot, 1.8f) * rimEdge * rimEdge * panel.RimBounce * weights[3][i];
                        pr += rimSpec * 150f;
                        pg += rimSpec * 162f;
                        pb += rimSpec * 205f;
                    }
                }
                rgba[i * 4] = Byte(pr);
                rgba[i * 4 + 1] = Byte(pg);
                rgba[i * 4 + 2] = Byte(pb);
                rgba[i * 4 + 3] = Byte(a * 255f);
            }
        });

        if (panel.DropShadow is { Length: >= 7 } ds)
        {
            int sx = (int)MathF.Round(ds[0] * scale);
            int sy = (int)MathF.Round(ds[1] * scale);
            float[] shiftedA = new float[n];
            Parallel.For(0, ph, py =>
            {
                int srcY = py - sy;
                if ((uint)srcY >= (uint)ph)
                    return;
                int srcRow = srcY * pw;
                int dstRow = py * pw;
                for (int px = 0; px < pw; px++)
                {
                    int srcX = px - sx;
                    if ((uint)srcX < (uint)pw)
                        shiftedA[dstRow + px] = Math.Clamp(0.5f + dists[0][srcRow + srcX] * scale, 0f, 1f);
                }
            });
            float[] sa = SepGaussianBlur(shiftedA, pw, ph, MathF.Max(0.15f, ds[2] * scale));
            float sr = ds[3], sg = ds[4], sb = ds[5], sop = ds[6];
            Parallel.For(0, n, i =>
            {
                float a = rgba[i * 4 + 3] / 255f;
                float under = sa[i] * sop * (1f - a);
                float outA = a + under;
                if (outA <= 1e-4f)
                    return;
                float invOut = 1f / outA;
                rgba[i * 4] = Byte((rgba[i * 4] * a + sr * under) * invOut);
                rgba[i * 4 + 1] = Byte((rgba[i * 4 + 1] * a + sg * under) * invOut);
                rgba[i * 4 + 2] = Byte((rgba[i * 4 + 2] * a + sb * under) * invOut);
                rgba[i * 4 + 3] = Byte(outA * 255f);
            });
        }

        var img = new VectorBannerRenderer.RasterImage(pw, ph, rgba, new CGSize(panel.Width, panel.Height));
        Cache[key] = img;
        return img;
    }

    // Extrapolates linearly off canvas edges (d - overshoot / scale) instead of clamping so screen-edge bevels keep full slope and depth.
    private static float[] SepGaussianBlurSdf(float[] src, int w, int h, float sigma, int scale)
    {
        if (sigma <= 0.05f)
            return (float[])src.Clone();
        int radius = Math.Max(1, (int)MathF.Ceiling(sigma * 3f));
        float[] kernel = new float[radius * 2 + 1];
        float sum = 0f;
        float inv2s2 = 1f / (2f * sigma * sigma);
        for (int k = -radius; k <= radius; k++)
        {
            float v = MathF.Exp(-k * k * inv2s2);
            kernel[k + radius] = v;
            sum += v;
        }
        for (int k = 0; k < kernel.Length; k++)
            kernel[k] /= sum;

        float invScale = 1f / scale;
        float[] tmp = new float[w * h];
        float[] dst = new float[w * h];

        Parallel.For(0, h, y =>
        {
            int row = y * w;
            for (int x = 0; x < w; x++)
            {
                float acc = 0f;
                for (int k = -radius; k <= radius; k++)
                {
                    int sx = x + k;
                    float sample = sx < 0
                        ? src[row] + sx * invScale
                        : sx >= w
                            ? src[row + w - 1] - (sx - (w - 1)) * invScale
                            : src[row + sx];
                    acc += sample * kernel[k + radius];
                }
                tmp[row + x] = acc;
            }
        });

        Parallel.For(0, h, y =>
        {
            int row = y * w;
            for (int x = 0; x < w; x++)
            {
                float acc = 0f;
                for (int k = -radius; k <= radius; k++)
                {
                    int sy = y + k;
                    float sample = sy < 0
                        ? tmp[x] + sy * invScale
                        : sy >= h
                            ? tmp[(h - 1) * w + x] - (sy - (h - 1)) * invScale
                            : tmp[sy * w + x];
                    acc += sample * kernel[k + radius];
                }
                dst[row + x] = acc;
            }
        });

        return dst;
    }

    private static float[] CastShadow(float[] height, int pw, int ph, float angle, float reach, int scale)
    {
        float cosA = MathF.Cos(angle);
        float sinA = MathF.Sin(angle);
        float maxDist = reach * scale;
        int samples = Math.Max(8, (int)MathF.Ceiling(reach * 2f));
        float[] lift = new float[pw * ph];
        Parallel.For(0, ph, py =>
        {
            int row = py * pw;
            for (int px = 0; px < pw; px++)
            {
                float h0 = height[row + px];
                float acc = 0f;
                float wSum = 0f;
                for (int s = 1; s <= samples; s++)
                {
                    float distPx = maxDist * s / samples;
                    float fx = Math.Clamp(px + cosA * distPx, 0f, pw - 1.001f);
                    float fy = Math.Clamp(py + sinA * distPx, 0f, ph - 1.001f);
                    int x0 = (int)fx, y0 = (int)fy;
                    float tx = fx - x0, ty = fy - y0;
                    int r0 = y0 * pw, r1 = (y0 + 1) * pw;
                    float hs = (height[r0 + x0] * (1f - tx) + height[r0 + x0 + 1] * tx) * (1f - ty)
                             + (height[r1 + x0] * (1f - tx) + height[r1 + x0 + 1] * tx) * ty;
                    float w = 1f - 0.55f * (s - 1f) / samples;
                    float diff = hs - h0;
                    if (diff > 0f)
                        acc += diff * w;
                    wSum += w;
                }
                lift[row + px] = wSum > 0f ? acc / wSum : 0f;
            }
        });
        return SepGaussianBlur(lift, pw, ph, MathF.Max(0.8f, maxDist * 0.35f));
    }

    private static float Profile(float[] p, float d)
    {
        float width = MathF.Max(0.001f, p[2]);
        float power = p[3];
        // Extend t smoothly slightly below 0 (where CornerSmooth pulls convex corners inward)
        // so height, slope, and curvature remain C-infinity continuous across d = 0.
        float t = Math.Clamp(d / width, -0.45f, 1f);
        return p[0] + p[1] * (1f - MathF.Pow(1f - t, power));
    }

    private static (float R, float G, float B) StopShade(float[] rgb, float[] stops, float d)
    {
        // Clamp d >= 0.5 so anti-aliased edge pixels never sample unconstrained negative-distance
        // regression stops (d < 0) or the 0px anti-aliasing-edge spike (d = 0).
        d = MathF.Max(0.5f, d);
        int j = 0;
        while (j < stops.Length - 2 && d > stops[j + 1])
            j++;
        float fd = Math.Clamp((d - stops[j]) / (stops[j + 1] - stops[j]), 0f, 1f);
        return (Lerp(rgb[j * 3], rgb[j * 3 + 3], fd), Lerp(rgb[j * 3 + 1], rgb[j * 3 + 4], fd), Lerp(rgb[j * 3 + 2], rgb[j * 3 + 5], fd));
    }

    private static float[] PanelDistanceField(float[][] contours, int pw, int ph, int scale, float reach)
    {
        var segs = new List<(float X0, float Y0, float X1, float Y1)>();
        foreach (float[] c in contours)
        {
            int count = c.Length / 2;
            for (int k = 0; k < count; k++)
            {
                int k1 = (k + 1) % count;
                segs.Add((c[k * 2], c[k * 2 + 1], c[k1 * 2], c[k1 * 2 + 1]));
            }
        }

        float[] d = new float[pw * ph];
        float inv = 1f / scale;
        Parallel.For(0, ph, py =>
        {
            float y = (py + 0.5f) * inv;
            var near = new List<(float X0, float Y0, float X1, float Y1)>();
            var crossings = new List<float>();
            foreach (var s in segs)
            {
                if (MathF.Min(s.Y0, s.Y1) - reach <= y && MathF.Max(s.Y0, s.Y1) + reach >= y)
                    near.Add(s);
                if ((s.Y0 > y) != (s.Y1 > y))
                    crossings.Add(s.X0 + (y - s.Y0) * (s.X1 - s.X0) / (s.Y1 - s.Y0));
            }
            crossings.Sort();

            int crossed = 0;
            for (int px = 0; px < pw; px++)
            {
                float x = (px + 0.5f) * inv;
                while (crossed < crossings.Count && crossings[crossed] < x)
                    crossed++;
                float best = reach * reach;
                foreach (var s in near)
                {
                    if (MathF.Min(s.X0, s.X1) - reach > x || MathF.Max(s.X0, s.X1) + reach < x)
                        continue;
                    float vx = s.X1 - s.X0, vy = s.Y1 - s.Y0;
                    float t = Math.Clamp(((x - s.X0) * vx + (y - s.Y0) * vy) / (vx * vx + vy * vy + 1e-12f), 0f, 1f);
                    float cx = s.X0 + t * vx - x, cy = s.Y0 + t * vy - y;
                    best = MathF.Min(best, cx * cx + cy * cy);
                }
                float dist = MathF.Sqrt(best);
                d[py * pw + px] = (crossed & 1) == 1 ? dist : -dist;
            }
        });
        return d;
    }

    private static FittedPanel LoadFittedPanel(string name)
    {
        string suffix = $".VectorUI.Panels.{name}.json";
        var asm = typeof(SimsVectorUiKit).Assembly;
        string resName = asm.GetManifestResourceNames().FirstOrDefault(n => n.EndsWith(suffix, StringComparison.OrdinalIgnoreCase))
            ?? throw new ContentError($"Missing embedded panel model '{name}.json'");
        using Stream stream = asm.GetManifestResourceStream(resName)
            ?? throw new ContentError($"Could not open embedded panel model '{resName}'");
        return JsonSerializer.Deserialize<FittedPanel>(stream, FittedPanelJson)
            ?? throw new ContentError($"Empty panel model '{resName}'");
    }

    private static readonly JsonSerializerOptions FittedPanelJson = new() { PropertyNameCaseInsensitive = true };

    private sealed record FittedPanel(
        int Width,
        int Height,
        float NormalBlur,
        float[] HeightStops,
        float LightAngle,
        float LightAltitude,
        float Gloss,
        float CreaseBlur,
        float CastReach,
        float[][] Zones,
        FittedPanelLayer[] Layers,
        float EdgeInset = 0f,
        float[]? DropShadow = null,
        float CornerSmooth = 0f,
        float PadRecess = 0f,
        float WellsRecess = 0f,
        float ShadowDepth = 0f,
        float RimBounce = 0f,
        float ShadowWrap = 0f,
        float PadRecessWidth = 4.5f,
        float PadRecessSmooth = 2.5f);

    private sealed record FittedPanelLayer(
        string Name,
        float[][] Contours,
        float[] Profile,
        float[] Flat,
        float[][] ZoneFlat,
        float[] Highlight,
        float[] Shadow,
        float[] Specular,
        float[] Crease,
        float[] Ridge,
        float[] Cast);
}
