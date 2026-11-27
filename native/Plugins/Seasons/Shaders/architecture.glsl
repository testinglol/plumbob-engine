// Seasons weather policy over generic physical architecture. Include after
// lot.glsl, ambientUniforms.glsl and the overheadMap sampler declaration.
// The data is supplied independently of visible roof/upper-floor geometry.
float architecturalExposure(vec3 point) {
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    vec2 source = orientation == 1 ? vec2(point.y, size.y - point.x)
                : orientation == 2 ? size - point.xy
                : orientation == 3 ? vec2(size.x - point.y, point.x) : point.xy;
    if (any(lessThan(source, vec2(0))) || any(greaterThanEqual(source, size))) return 1.0;
    ivec2 mapSize = textureSize(overheadMap, 0);
    bool hasBand1 = mapSize.y >= mapSize.x * 2 && mapSize.x > 1;
    ivec2 baseSize = hasBand1 ? ivec2(mapSize.x, mapSize.x) : mapSize;
    vec2 texelsPerTile = vec2(baseSize) / max(size, vec2(1.0));
    ivec2 at = ivec2(floor(source * texelsPerTile));
    if (any(greaterThanEqual(at, baseSize))) return 1.0;
    ivec4 data = ivec4(texelFetch(overheadMap, at, 0) * 255.0 + 0.5);
    if (data.a == 0) return 1.0;
    float base = float(data.g * 256 + data.b - 32768) / 256.0;
    int story = int(floor((point.z - base + 0.1) / STORY_HEIGHT));
    if (story < 0) return 1.0;
    if (hasBand1) {
        if (story > 15) return 1.0;
        ivec4 b1 = ivec4(texelFetch(overheadMap, ivec2(at.x, at.y + baseSize.y), 0) * 255.0 + 0.5);
        int covered16 = b1.r | (b1.g << 8);
        return (covered16 & (1 << story)) != 0 ? 0.0 : 1.0;
    }
    if (story > 4) return 1.0;
    return (data.r & (1 << story)) != 0 ? 0.0 : 1.0;
}

float terrainBaseAt(vec2 point, float fallback) {
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    vec2 source = orientation == 1 ? vec2(point.y, size.y - point.x)
                : orientation == 2 ? size - point
                : orientation == 3 ? vec2(size.x - point.y, point.x) : point;
    if (any(lessThan(source, vec2(0))) || any(greaterThanEqual(source, size))) return fallback;
    ivec2 mapSize = textureSize(overheadMap, 0);
    ivec2 baseSize = (mapSize.y >= mapSize.x * 2 && mapSize.x > 1) ? ivec2(mapSize.x, mapSize.x) : mapSize;
    vec2 texelsPerTile = vec2(baseSize) / max(size, vec2(1.0));
    ivec2 at = ivec2(floor(source * texelsPerTile));
    if (any(greaterThanEqual(at, baseSize))) return fallback;
    ivec4 data = ivec4(texelFetch(overheadMap, at, 0) * 255.0 + 0.5);
    if (data.a == 0) return fallback;
    return float(data.g * 256 + data.b - 32768) / 256.0;
}

float terrainBaseClamped(vec2 point, float fallback) {
    vec2 size = ambient.drift.zw;
    if (size.x <= 0.0 || size.y <= 0.0) return fallback;
    int orientation = int(ambient.clouds.z + 0.5);
    vec2 source = orientation == 1 ? vec2(point.y, size.y - point.x)
                : orientation == 2 ? size - point
                : orientation == 3 ? vec2(size.x - point.y, point.x) : point;
    ivec2 mapSize = textureSize(overheadMap, 0);
    ivec2 baseSize = (mapSize.y >= mapSize.x * 2 && mapSize.x > 1) ? ivec2(mapSize.x, mapSize.x) : mapSize;
    if (baseSize.x <= 1) return fallback;
    vec2 clamped = clamp(source, vec2(0.0), max(size - vec2(1e-3), vec2(0.0)));
    vec2 texelsPerTile = vec2(baseSize) / max(size, vec2(1.0));
    ivec2 at = clamp(ivec2(floor(clamped * texelsPerTile)), ivec2(0), baseSize - 1);
    ivec4 data = ivec4(texelFetch(overheadMap, at, 0) * 255.0 + 0.5);
    if (data.a == 0) return fallback;
    return float(data.g * 256 + data.b - 32768) / 256.0;
}

float canopyBlockedTexel(ivec4 data, int slabMask16, bool hasBand1, float canopyClearZ, float qPrevZ, float qZ, float pen, float smoothRoofTop) {
    if (data.a == 0 || data.a == 255) return 0.0;
    bool hasCeil1 = (data.r & 32) != 0;
    bool hasAnyUpper = (data.r & 64) != 0;
    if (!hasCeil1 && !hasAnyUpper && data.a <= 1) return 0.0;
    float qBase = float(data.g * 256 + data.b - 32768) / 256.0;
    float prevRel = qPrevZ - qBase;
    float curRel = qZ - qBase;
    float topScale = hasBand1 ? 4.0 : 8.0;
    float canopyTop = data.a >= 2 ? (smoothRoofTop >= 0.0 ? smoothRoofTop : float(data.a - 2) / topScale) : -1.0;
    float botPen = min(pen, 0.14);
    float topPen = min(pen, 0.62);
    if (prevRel > max(canopyTop, STORY_HEIGHT) + 0.35 + 0.65 * topPen) return 0.0;
    float occ = 0.0;
    float clear1 = 1.0 - smoothstep(STORY_HEIGHT - 0.22, STORY_HEIGHT - 0.06, canopyClearZ);
    if (hasCeil1 && clear1 > 0.001) {
        float top1 = max(canopyTop, STORY_HEIGHT + 0.18);
        occ = max(occ, clear1 * smoothstep(STORY_HEIGHT - 0.10 - botPen, STORY_HEIGHT - 0.10 + botPen, curRel)
                     * (1.0 - smoothstep(top1 - 0.35 * topPen, top1 + 0.65 * topPen, prevRel)));
    }
    int topUpperStory = 1;
    int upperBits = slabMask16 & 65534;
    if (hasBand1 && upperBits != 0) {
        int maxK = (upperBits & 65280) != 0 ? 16 : ((upperBits & 240) != 0 ? 8 : 4);
        for (int k = 2; k <= maxK; k++) {
            if ((upperBits & (1 << (k - 1))) == 0) continue;
            topUpperStory = k;
            float slabH = float(k) * STORY_HEIGHT;
            float clearK = 1.0 - smoothstep(slabH - 0.22, slabH - 0.06, canopyClearZ);
            if (clearK > 0.001) {
                float prevH = float(k - 1) * STORY_HEIGHT;
                float botK = mix(prevH - 0.10, slabH - 0.10, smoothstep(prevH - 0.22, prevH - 0.06, canopyClearZ));
                float topK = max(canopyTop, slabH + 0.18);
                occ = max(occ, clearK * smoothstep(botK - botPen, botK + botPen, curRel)
                             * (1.0 - smoothstep(topK - 0.35 * topPen, topK + 0.65 * topPen, prevRel)));
            }
        }
    } else if (!hasBand1 && hasAnyUpper) {
        topUpperStory = 2;
        for (int k = 3; k <= 5; k++) {
            if ((data.r & (1 << (k - 1))) != 0) topUpperStory = k;
        }
        for (int k = 2; k <= topUpperStory; k++) {
            if (k > 2 && (data.r & (1 << (k - 1))) == 0) continue;
            float slabH = float(k) * STORY_HEIGHT;
            float clearK = 1.0 - smoothstep(slabH - 0.22, slabH - 0.06, canopyClearZ);
            if (clearK > 0.001) {
                float prevH = float(k - 1) * STORY_HEIGHT;
                float botK = mix(prevH - 0.10, slabH - 0.10, smoothstep(prevH - 0.22, prevH - 0.06, canopyClearZ));
                float topK = max(canopyTop, slabH + 0.18);
                occ = max(occ, clearK * smoothstep(botK - botPen, botK + botPen, curRel)
                             * (1.0 - smoothstep(topK - 0.35 * topPen, topK + 0.65 * topPen, prevRel)));
            }
        }
    }
    if (canopyTop >= STORY_HEIGHT - 0.05) {
        float eaveStories = clamp(floor((canopyTop + 0.05) / STORY_HEIGHT), 1.0, float(topUpperStory));
        float eaveBase = eaveStories * STORY_HEIGHT;
        float clearE = 1.0 - smoothstep(eaveBase - 0.22, eaveBase - 0.06, canopyClearZ);
        if (clearE > 0.001) {
            float topR = max(canopyTop, eaveBase + 0.18);
            occ = max(occ, clearE * smoothstep(eaveBase - 0.14 - botPen, eaveBase - 0.14 + botPen, curRel)
                         * (1.0 - smoothstep(topR - 0.35 * topPen, topR + 0.65 * topPen, prevRel)));
        }
    }
    return occ;
}

float canopyOcclusionAt(vec2 point, float canopyClearZ, float qPrevZ, float qZ, float pen) {
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    vec2 source = orientation == 1 ? vec2(point.y, size.y - point.x)
                : orientation == 2 ? size - point
                : orientation == 3 ? vec2(size.x - point.y, point.x) : point;
    if (any(lessThan(source, vec2(0.0))) || any(greaterThanEqual(source, size))) return 0.0;
    ivec2 mapSize = textureSize(overheadMap, 0);
    bool hasBand1 = mapSize.y >= mapSize.x * 2 && mapSize.x > 1;
    ivec2 baseSize = hasBand1 ? ivec2(mapSize.x, mapSize.x) : mapSize;
    vec2 fPos = source * (vec2(baseSize) / max(size, vec2(1.0))) - 0.5;
    ivec2 i0 = ivec2(floor(fPos));
    vec2 f = fract(fPos);
    ivec2 maxIdx = baseSize - 1;
    ivec2 gi = clamp(i0, ivec2(0), max(maxIdx - 1, ivec2(0)));
    vec2 gUv = (vec2(gi) + 1.0) / vec2(max(mapSize, ivec2(1)));
    vec4 gR = textureGather(overheadMap, gUv, 0);
    vec4 gA = textureGather(overheadMap, gUv, 3);
    if (max(max(gR.x, gR.y), max(gR.z, gR.w)) < (31.5 / 255.0) &&
        max(max(gA.x, gA.y), max(gA.z, gA.w)) < (1.5 / 255.0)) return 0.0;
    ivec2 p00 = clamp(i0, ivec2(0), maxIdx);
    ivec2 p10 = clamp(i0 + ivec2(1, 0), ivec2(0), maxIdx);
    ivec2 p01 = clamp(i0 + ivec2(0, 1), ivec2(0), maxIdx);
    ivec2 p11 = clamp(i0 + ivec2(1, 1), ivec2(0), maxIdx);
    ivec4 c00 = ivec4(texelFetch(overheadMap, p00, 0) * 255.0 + 0.5);
    ivec4 c10 = ivec4(texelFetch(overheadMap, p10, 0) * 255.0 + 0.5);
    ivec4 c01 = ivec4(texelFetch(overheadMap, p01, 0) * 255.0 + 0.5);
    ivec4 c11 = ivec4(texelFetch(overheadMap, p11, 0) * 255.0 + 0.5);
    int rUnion = c00.r | c10.r | c01.r | c11.r;
    int aMax = max(max(c00.a, c10.a), max(c01.a, c11.a));
    if ((rUnion & 96) == 0 && aMax <= 1) return 0.0;
    bool v00 = c00.a != 0 && c00.a != 255;
    bool v10 = c10.a != 0 && c10.a != 255;
    bool v01 = c01.a != 0 && c01.a != 255;
    bool v11 = c11.a != 0 && c11.a != 255;
    if (!v00 && !v10 && !v01 && !v11) return 0.0;

    float refBase = v00 ? float(c00.g * 256 + c00.b - 32768) / 256.0
                  : v10 ? float(c10.g * 256 + c10.b - 32768) / 256.0
                  : v01 ? float(c01.g * 256 + c01.b - 32768) / 256.0
                        : float(c11.g * 256 + c11.b - 32768) / 256.0;
    if (qZ - refBase < STORY_HEIGHT - 0.42) return 0.0;

    float roofOcc = 0.0;
    if (aMax >= 2) {
        float topScale = hasBand1 ? 4.0 : 8.0;
        if (qPrevZ - refBase <= float(aMax - 2) / topScale + 0.60 + min(pen, 0.62)) {
            vec2 um = 1.0 - f;
            vec4 wx = vec4(
                (um.x * um.x * um.x) / 6.0,
                (3.0 * f.x * f.x * f.x - 6.0 * f.x * f.x + 4.0) / 6.0,
                (-3.0 * f.x * f.x * f.x + 3.0 * f.x * f.x + 3.0 * f.x + 1.0) / 6.0,
                (f.x * f.x * f.x) / 6.0);
            vec4 wy = vec4(
                (um.y * um.y * um.y) / 6.0,
                (3.0 * f.y * f.y * f.y - 6.0 * f.y * f.y + 4.0) / 6.0,
                (-3.0 * f.y * f.y * f.y + 3.0 * f.y * f.y + 3.0 * f.y + 1.0) / 6.0,
                (f.y * f.y * f.y) / 6.0);
            vec2 invM = 1.0 / vec2(max(mapSize, ivec2(1)));
            ivec2 gTL = clamp(i0 - ivec2(1, 1), ivec2(0), max(maxIdx - 1, ivec2(0)));
            ivec2 gTR = clamp(i0 + ivec2(1, -1), ivec2(0), max(maxIdx - 1, ivec2(0)));
            ivec2 gBL = clamp(i0 + ivec2(-1, 1), ivec2(0), max(maxIdx - 1, ivec2(0)));
            ivec2 gBR = clamp(i0 + ivec2(1, 1), ivec2(0), max(maxIdx - 1, ivec2(0)));
            vec4 qTL = floor(textureGather(overheadMap, (vec2(gTL) + 1.0) * invM, 3) * 255.0 + 0.5);
            vec4 qTR = floor(textureGather(overheadMap, (vec2(gTR) + 1.0) * invM, 3) * 255.0 + 0.5);
            vec4 qBL = floor(textureGather(overheadMap, (vec2(gBL) + 1.0) * invM, 3) * 255.0 + 0.5);
            vec4 qBR = floor(textureGather(overheadMap, (vec2(gBR) + 1.0) * invM, 3) * 255.0 + 0.5);
            vec4 vTL = step(vec4(1.5), qTL) * step(qTL, vec4(254.5));
            vec4 vTR = step(vec4(1.5), qTR) * step(qTR, vec4(254.5));
            vec4 vBL = step(vec4(1.5), qBL) * step(qBL, vec4(254.5));
            vec4 vBR = step(vec4(1.5), qBR) * step(qBR, vec4(254.5));
            vec4 wTL = vTL * vec4(wx.x * wy.y, wx.y * wy.y, wx.y * wy.x, wx.x * wy.x);
            vec4 wTR = vTR * vec4(wx.z * wy.y, wx.w * wy.y, wx.w * wy.x, wx.z * wy.x);
            vec4 wBL = vBL * vec4(wx.x * wy.w, wx.y * wy.w, wx.y * wy.z, wx.x * wy.z);
            vec4 wBR = vBR * vec4(wx.z * wy.w, wx.w * wy.w, wx.w * wy.z, wx.z * wy.z);
            float roofW = dot(wTL, vec4(1.0)) + dot(wTR, vec4(1.0)) + dot(wBL, vec4(1.0)) + dot(wBR, vec4(1.0));
            if (roofW > 1e-4) {
                float sumTop = (dot(wTL, qTL - 2.0) + dot(wTR, qTR - 2.0) + dot(wBL, qBL - 2.0) + dot(wBR, qBR - 2.0)) / topScale;
                float smoothRoofTop = sumTop / roofW;
                ivec4 cRef = c00.a >= 2 && c00.a != 255 ? c00 : (c10.a >= 2 && c10.a != 255 ? c10 : (c01.a >= 2 && c01.a != 255 ? c01 : c11));
                roofOcc = clamp(roofW, 0.0, 1.0) * canopyBlockedTexel(cRef, 0, hasBand1, canopyClearZ, qPrevZ, qZ, pen, smoothRoofTop);
            }
        }
    }
    if ((rUnion & 96) == 0) return roofOcc;

    int s00 = 0, s10 = 0, s01 = 0, s11 = 0;
    if (hasBand1 && (rUnion & 64) != 0) {
        ivec2 bOff = ivec2(0, baseSize.y);
        if ((c00.r & 64) != 0) { ivec4 d = ivec4(texelFetch(overheadMap, p00 + bOff, 0) * 255.0 + 0.5); s00 = d.b | (d.a << 8); }
        if ((c10.r & 64) != 0) { ivec4 d = ivec4(texelFetch(overheadMap, p10 + bOff, 0) * 255.0 + 0.5); s10 = d.b | (d.a << 8); }
        if ((c01.r & 64) != 0) { ivec4 d = ivec4(texelFetch(overheadMap, p01 + bOff, 0) * 255.0 + 0.5); s01 = d.b | (d.a << 8); }
        if ((c11.r & 64) != 0) { ivec4 d = ivec4(texelFetch(overheadMap, p11 + bOff, 0) * 255.0 + 0.5); s11 = d.b | (d.a << 8); }
    }
    float b00 = (c00.r & 96) != 0 ? canopyBlockedTexel(ivec4(c00.rgb, 1), s00, hasBand1, canopyClearZ, qPrevZ, qZ, pen, -1.0) : 0.0;
    float b10 = (c10.r & 96) != 0 ? canopyBlockedTexel(ivec4(c10.rgb, 1), s10, hasBand1, canopyClearZ, qPrevZ, qZ, pen, -1.0) : 0.0;
    float b01 = (c01.r & 96) != 0 ? canopyBlockedTexel(ivec4(c01.rgb, 1), s01, hasBand1, canopyClearZ, qPrevZ, qZ, pen, -1.0) : 0.0;
    float b11 = (c11.r & 96) != 0 ? canopyBlockedTexel(ivec4(c11.rgb, 1), s11, hasBand1, canopyClearZ, qPrevZ, qZ, pen, -1.0) : 0.0;
    return max(roofOcc, mix(mix(b00, b10, f.x), mix(b01, b11, f.x), f.y));
}
