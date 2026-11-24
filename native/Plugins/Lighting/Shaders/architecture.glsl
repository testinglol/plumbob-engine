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
    vec2 texelsPerTile = vec2(textureSize(overheadMap, 0)) / max(size, vec2(1.0));
    ivec2 at = ivec2(floor(source * texelsPerTile));
    if (any(greaterThanEqual(at, textureSize(overheadMap, 0)))) return 1.0;
    ivec4 data = ivec4(texelFetch(overheadMap, at, 0) * 255.0 + 0.5);
    if (data.a == 0) return 1.0;
    float base = float(data.g * 256 + data.b - 32768) / 256.0;
    int story = int(floor((point.z - base + 0.1) / STORY_HEIGHT));
    if (story < 0 || story > 4) return 1.0;
    return (data.r & (1 << story)) != 0 ? 0.0 : 1.0;
}

float terrainBaseAt(vec2 point, float fallback) {
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    vec2 source = orientation == 1 ? vec2(point.y, size.y - point.x)
                : orientation == 2 ? size - point
                : orientation == 3 ? vec2(size.x - point.y, point.x) : point;
    if (any(lessThan(source, vec2(0))) || any(greaterThanEqual(source, size))) return fallback;
    vec2 texelsPerTile = vec2(textureSize(overheadMap, 0)) / max(size, vec2(1.0));
    ivec2 at = ivec2(floor(source * texelsPerTile));
    if (any(greaterThanEqual(at, textureSize(overheadMap, 0)))) return fallback;
    ivec4 data = ivec4(texelFetch(overheadMap, at, 0) * 255.0 + 0.5);
    if (data.a == 0) return fallback;
    return float(data.g * 256 + data.b - 32768) / 256.0;
}

float canopyBlockedTexel(ivec4 data, float canopyClearZ, float qPrevZ, float qZ, float pen) {
    if (data.a == 0 || data.a == 255) return 0.0;
    float qBase = float(data.g * 256 + data.b - 32768) / 256.0;
    float prevRel = qPrevZ - qBase;
    float curRel = qZ - qBase;
    bool hasCeil1 = (data.r & 32) != 0;
    bool hasStory2 = (data.r & 64) != 0;
    float canopyTop = data.a >= 2 ? float(data.a - 2) / 16.0 : -1.0;
    float botPen = min(pen, 0.14);
    float topPen = min(pen, 0.55);
    float occ = 0.0;
    if (hasCeil1 && canopyClearZ < STORY_HEIGHT) {
        float top1 = max(canopyTop, STORY_HEIGHT + 0.18);
        occ = max(occ, smoothstep(STORY_HEIGHT - 0.10 - botPen, STORY_HEIGHT - 0.10 + botPen, curRel)
                     * (1.0 - smoothstep(top1 - 0.35 * topPen, top1 + 0.65 * topPen, prevRel)));
    }
    if (hasStory2 && canopyClearZ < 2.0 * STORY_HEIGHT) {
        float bot2 = canopyClearZ < STORY_HEIGHT ? STORY_HEIGHT - 0.10 : 2.0 * STORY_HEIGHT - 0.10;
        float top2 = max(canopyTop, 2.0 * STORY_HEIGHT + 0.18);
        occ = max(occ, smoothstep(bot2 - botPen, bot2 + botPen, curRel)
                     * (1.0 - smoothstep(top2 - 0.35 * topPen, top2 + 0.65 * topPen, prevRel)));
    }
    if (canopyTop >= STORY_HEIGHT - 0.05) {
        float eaveBase = canopyTop >= 2.0 * STORY_HEIGHT - 0.05 ? 2.0 * STORY_HEIGHT : STORY_HEIGHT;
        if (canopyClearZ < eaveBase) {
            float topR = max(canopyTop, eaveBase + 0.18);
            occ = max(occ, smoothstep(eaveBase - 0.14 - botPen, eaveBase - 0.14 + botPen, curRel)
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
    vec2 fPos = source * (vec2(mapSize) / max(size, vec2(1.0))) - 0.5;
    ivec2 i0 = ivec2(floor(fPos));
    vec2 f = fract(fPos);
    ivec2 maxIdx = mapSize - 1;
    ivec4 c00 = ivec4(texelFetch(overheadMap, clamp(i0, ivec2(0), maxIdx), 0) * 255.0 + 0.5);
    ivec4 c10 = ivec4(texelFetch(overheadMap, clamp(i0 + ivec2(1, 0), ivec2(0), maxIdx), 0) * 255.0 + 0.5);
    ivec4 c01 = ivec4(texelFetch(overheadMap, clamp(i0 + ivec2(0, 1), ivec2(0), maxIdx), 0) * 255.0 + 0.5);
    ivec4 c11 = ivec4(texelFetch(overheadMap, clamp(i0 + ivec2(1, 1), ivec2(0), maxIdx), 0) * 255.0 + 0.5);
    bool v00 = c00.a != 0 && c00.a != 255;
    bool v10 = c10.a != 0 && c10.a != 255;
    bool v01 = c01.a != 0 && c01.a != 255;
    bool v11 = c11.a != 0 && c11.a != 255;
    if (!v00 && !v10 && !v01 && !v11) return 0.0;
    float b00 = canopyBlockedTexel(c00, canopyClearZ, qPrevZ, qZ, pen);
    float b10 = canopyBlockedTexel(c10, canopyClearZ, qPrevZ, qZ, pen);
    float b01 = canopyBlockedTexel(c01, canopyClearZ, qPrevZ, qZ, pen);
    float b11 = canopyBlockedTexel(c11, canopyClearZ, qPrevZ, qZ, pen);
    return mix(mix(b00, b10, f.x), mix(b01, b11, f.x), f.y);
}
