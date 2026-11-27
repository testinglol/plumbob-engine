#version 450
#extension GL_GOOGLE_include_directive : require
#include "lot.glsl"

// The season over the lot's unlit colour, before the ambient pass lights it, so the sun, shadows and lamps fall on
// what it adds as on the rest. Autumn turns foliage (green sprite pixels outdoors) yellow, orange and red, keeping each
// pixel's brightness so the art's own shading stays, varying tree by tree; the grass goes toward straw and fallen leaves
// gather on the ground, thickest under canopies. Winter lays snow on what faces the sky outdoors and has nothing over
// it (the ground, the tops of shrubs, trees, fences and furniture), patchy at first and closing over as it deepens,
// and dulls the evergreen. The snow on the ground has depth: a height field over the lot (thin at first, about a third
// of a tile past full cover, piled against walls and lumpy in drifts, pressed down where feet have trodden) that each
// pixel marches toward the camera, so snow in front hides the bottoms of walls, trunks and legs, its edges show a
// shaded side and its top takes the sun by its slope. Writes the changed colour over the lot (and nothing elsewhere).
layout(set = 2, binding = 0) uniform sampler2D depthMap;
layout(set = 2, binding = 1) uniform sampler2D groundMap;
layout(set = 2, binding = 2) uniform sampler2D heightMap;
layout(set = 2, binding = 3) uniform sampler2D indoorMap;
layout(set = 2, binding = 4) uniform sampler2D source;
layout(set = 2, binding = 5) uniform sampler2D trailMap;
layout(set = 2, binding = 6) uniform sampler2D overheadMap;
// 1 where a Sim was drawn: Sims keep their own colours, under neither snow nor turned leaves.
layout(set = 2, binding = 7) uniform sampler2D simMap;
layout(set = 2, binding = 8) uniform sampler2D spriteMap;
layout(set = 2, binding = 9) uniform sampler2D outFloraMap;
#include "ambientUniforms.glsl"
layout(location = 0) out vec4 color;
layout(location = 1) out vec4 lift;  // how far along the view (x + y) and up the snow's surface lies, 1 where it is seen
#include "lotSurface.glsl"
#include "architecture.glsl"

const vec3 WORLD_UP = vec3(0.0, -0.8660254, 0.5);  // the lot's up in the view's basis (x right, y down, z toward us)
const vec3 SNOW = vec3(0.76, 0.83, 0.94);
const vec3 SNOW_SHADE = vec3(0.46, 0.55, 0.72);
const vec3 DIRT_LIGHT = vec3(0.337, 0.178, 0.053);  // Vacation warm winter dirt (#9D7541 linear)
const vec3 DIRT_DARK = vec3(0.082, 0.045, 0.006);   // Vacation dark soil grain (#513C12 linear)

// The highest point the height map holds over a lot point (camera tiles), or far below where it holds none.
float topAt(vec2 at) {
    vec2 gridSize = vec2(textureSize(heightMap, 0));
    return (0.5 - texture(heightMap, (at + ambient.frame.w) * ambient.frame.z / gridSize).r) * HEIGHT_RANGE;
}

// How pressed the snow is at a lot point (camera tiles; 0 untouched, 1 trodden), from the trail map on the lot's own
// tiles: filtered between its texels and cut at the middle of each print's soft edge, so a print's outline is sharp.
float pressedAt(vec2 at) {
    ivec2 size = textureSize(trailMap, 0);
    if (size.x < 4) return 0.0;
    vec2 texel = (lotSource(at) + TRAIL_MARGIN) * TRAIL_TEXELS - 0.5;
    if (texel.x < -0.5 || texel.y < -0.5 || texel.x > float(size.x) - 0.5 || texel.y > float(size.y) - 0.5) return 0.0;
    ivec2 base = ivec2(floor(texel));
    vec2 f = texel - vec2(base);
    float sum = 0.0;
    for (int i = 0; i < 4; i++) {
        ivec2 c = clamp(base + ivec2(i & 1, i >> 1), ivec2(0), size - 1);
        sum += texelFetch(trailMap, c, 0).r * ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
    }
    return smoothstep(0.35, 0.65, sum);
}

vec4 sampleFloraTex(sampler2D tex, vec2 lotPt, float texels, vec2 margin, out float speciesLumRef) {
    ivec2 size = textureSize(tex, 0);
    if (size.x < 4) {
        speciesLumRef = 0.0;
        return vec4(0.0);
    }
    vec2 texel = (lotPt + margin) * texels - 0.5;
    if (texel.x < -0.5 || texel.y < -0.5 || texel.x > float(size.x) - 0.5 || texel.y > float(size.y) - 0.5) {
        speciesLumRef = 0.0;
        return vec4(0.0);
    }
    ivec2 base = ivec2(floor(texel));
    vec2 f = texel - vec2(base);
    float keepGreen = 0.0;
    float drop = 0.0;
    float hueSum = 0.0;
    float lumSum = 0.0;
    float hueW = 0.0;
    for (int i = 0; i < 4; i++) {
        ivec2 c = clamp(base + ivec2(i & 1, i >> 1), ivec2(0), size - 1);
        float w = ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
        vec4 tap = texelFetch(tex, c, 0);
        keepGreen += tap.r * w;
        drop += tap.g * w;
        if (tap.b > 0.04) {
            hueSum += tap.b * w;
            lumSum += tap.a * w;
            hueW += w;
        }
    }
    float hue = hueW > 1e-4 ? hueSum / hueW : 0.0;
    speciesLumRef = hueW > 1e-4
        ? mix(0.020, 0.140, clamp((lumSum / hueW - 0.38) / 0.24, 0.0, 1.0))
        : 0.0;
    return vec4(keepGreen, drop, hue, hueW);
}

vec4 floraAt(vec2 at, out float speciesLumRef) {
    vec2 lotPt = lotSource(at);
    vec2 lotSize = ambient.drift.zw;
    vec2 outsideDist = max(max(-lotPt, lotPt - lotSize), vec2(0.0));
    float outDist = max(outsideDist.x, outsideDist.y);
    ivec2 inSize = textureSize(trailMap, 0);
    bool hasIn = inSize.x > 4 && abs(texelFetch(trailMap, ivec2(0, 0), 0).a - 0.5) < 0.18;
    bool hasOut = ambient.prevView.w > 0.5 && ambient.prevView.x > 0.0 && textureSize(outFloraMap, 0).x > 4;
    if (hasIn && (!hasOut || outDist <= 0.55)) {
        return sampleFloraTex(trailMap, lotPt, TRAIL_TEXELS, vec2(TRAIL_MARGIN), speciesLumRef);
    }
    if (hasOut && (!hasIn || outDist >= 0.92)) {
        return sampleFloraTex(outFloraMap, lotPt, ambient.prevView.x, ambient.prevView.yz, speciesLumRef);
    }
    if (!hasIn && !hasOut) {
        speciesLumRef = 0.0;
        return vec4(0.0);
    }
    float t = smoothstep(0.55, 0.92, outDist);
    float lumIn = 0.0, lumOut = 0.0;
    vec4 fIn = sampleFloraTex(trailMap, lotPt, TRAIL_TEXELS, vec2(TRAIL_MARGIN), lumIn);
    vec4 fOut = sampleFloraTex(outFloraMap, lotPt, ambient.prevView.x, ambient.prevView.yz, lumOut);
    speciesLumRef = lumIn > 0.0 && lumOut > 0.0 ? mix(lumIn, lumOut, t) : (lumOut > 0.0 ? lumOut : lumIn);
    float hue = fIn.w > 1e-4 && fOut.w > 1e-4 ? mix(fIn.z, fOut.z, t) : (fOut.w > 1e-4 ? fOut.z : fIn.z);
    return vec4(mix(fIn.x, fOut.x, t), mix(fIn.y, fOut.y, t), hue, mix(fIn.w, fOut.w, t));
}

// How far what stands over a lot point rises above `base` (tiles, 0 where nothing does), filtered between the height
// map's texels so the snow's shape does not follow its grid.
float riseAt(vec2 q, float base) {
    ivec2 size = textureSize(heightMap, 0);
    vec2 t = (q + ambient.frame.w) * ambient.frame.z - 0.5;
    ivec2 b = ivec2(floor(t));
    vec2 f = t - vec2(b);
    float sum = 0.0;
    for (int i = 0; i < 4; i++) {
        ivec2 c = clamp(b + ivec2(i & 1, i >> 1), ivec2(0), size - 1);
        float rise = max(0.0, (0.5 - texelFetch(heightMap, c, 0).r) * HEIGHT_RANGE - base);
        sum += rise * ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
    }
    return sum;
}

// The snow's height (tiles) over the ground at a lot point, for a full depth `full` and ground at `base`: patchy while
// thin, less under a roof or canopy high overhead, none indoors, piled up beside walls and objects, lumpy in drifts
// and pressed down where feet have trodden.
// How much of an outdoor floor (road, sidewalk, patio) lies at a camera-tile point, filtered between tile centres as
// indoors() is. Paved ground is kept ploughed and shovelled, so cars and Sims keep to it through deep snow.
float pavedAt(vec2 q) {
    vec2 sourcePoint = lotSource(q);
    bool scenery = any(lessThan(sourcePoint, vec2(1.0))) || any(greaterThan(sourcePoint, ambient.drift.zw - 1.0));
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    if (orientation == 1 || orientation == 3) size = size.yx;
    vec2 edge = clamp(q, vec2(1.5), size - vec2(1.5));
    // Beyond the lot the client mirrors a street that runs along the edge across it, to its own width, and continues
    // one that leaves the lot: the point is paved while the street reaches as far inward as the point lies outside.
    ivec2 inward = ivec2(sign(edge - q));
    vec2 beyond = abs(edge - q);
    int reach = min(12, int(ceil(max(beyond.x, beyond.y) - 0.5)));
    q = edge;
    vec2 cell = q + ambient.frame.w - 0.5;
    ivec2 base = ivec2(floor(cell));
    vec2 f = clamp((fract(cell) - 0.5) / 0.4 + 0.5, 0.0, 1.0);
    float sum = 0.0;
    for (int i = 0; i < 4; i++) {
        ivec2 at = base + ivec2(i & 1, i >> 1);
        if (maskCatAt(at, 1, 0) == 0 || maskCatAt(at, 0, 0) >= 2) continue;
        int f4 = maskCatAt(at, 2, 0);
        if ((f4 & 160) != 0) continue;
        if (scenery) {
            bool street = true;
            for (int k = 0; k < reach && street; k++) street = (maskCatAt(at + inward * k, 2, 0) & 64) != 0;
            if (!street) continue;
        }
        float weight = ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
        int part = f4 & 7;
        if (part != 0) {
            vec2 toward = part == 1 ? vec2(1.0, -1.0) : part == 2 ? vec2(-1.0, 1.0) : part == 3 ? vec2(-1.0) : vec2(1.0);
            weight *= smoothstep(-0.06, 0.06, dot(q + ambient.frame.w - vec2(at) - 0.5, toward));
        }
        sum += weight;
    }
    return sum;
}

float cementAt(vec2 q) {
    vec2 sourcePoint = lotSource(q);
    if (any(lessThan(sourcePoint, vec2(0.5))) || any(greaterThan(sourcePoint, ambient.drift.zw - 0.5))) return 0.0;
    vec2 cell = q + ambient.frame.w - 0.5;
    ivec2 base = ivec2(floor(cell));
    vec2 f = clamp((fract(cell) - 0.5) / 0.4 + 0.5, 0.0, 1.0);
    float sum = 0.0;
    for (int i = 0; i < 4; i++) {
        ivec2 at = base + ivec2(i & 1, i >> 1);
        if (maskCatAt(at, 1, 0) == 0 || maskCatAt(at, 0, 0) >= 2) continue;
        if ((maskCatAt(at, 2, 0) & 128) == 0) continue;
        sum += ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
    }
    return sum;
}

float waterAt(vec2 q) {
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    if (orientation == 1 || orientation == 3) size = size.yx;
    vec2 edge = clamp(q, vec2(1.5), size - vec2(1.5));
    vec2 cell = edge + ambient.frame.w - 0.5;
    ivec2 base = ivec2(floor(cell));
    vec2 f = fract(cell);
    float sum = 0.0;
    for (int i = 0; i < 4; i++) {
        ivec2 at = base + ivec2(i & 1, i >> 1);
        if (maskCatAt(at, 1, 0) == 0 || maskCatAt(at, 0, 0) >= 2) continue;
        if ((maskCatAt(at, 2, 0) & 32) == 0) continue;
        sum += ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
    }
    return sum;
}

float pondWaterOf(vec3 c) {
    return smoothstep(1.18, 1.65, c.b / max(c.r, 0.0008))
         * smoothstep(0.92, 1.22, c.b / max(c.g, 0.0008))
         * smoothstep(0.003, 0.010, c.b);
}

float samplePondWaterTap(ivec2 ip, ivec2 maxI, bool hasSprite) {
    ip = clamp(ip, ivec2(0), maxI);
    vec3 c = texelFetch(source, ip, 0).rgb;
    if (hasSprite) {
        vec4 sp = texelFetch(spriteMap, ip, 0);
        if (sp.a > 0.004 && sp.a < 0.99) {
            c = clamp((c - sp.rgb) / max(1.0 - sp.a, 0.02), vec3(0.0), vec3(1.0));
        }
    }
    return pondWaterOf(c);
}

float samplePondGroundWater(vec2 q, float base) {
    vec2 scene = vec2(32.0 * (q.x - q.y), 16.0 * (q.x + q.y) - 40.0 * base) + ambient.frame.xy;
    vec2 px = scene * ambient.view.z + ambient.view.xy;
    if (px.x < 0.5 || px.y < 0.5 || px.x >= ambient.extent.x - 0.5 || px.y >= ambient.extent.y - 0.5)
        return smoothstep(0.55, 0.90, waterAt(q));
    ivec2 maxI = max(ivec2(ambient.extent.xy) - 1, ivec2(0));
    ivec2 ip0 = clamp(ivec2(floor(px)), ivec2(0), maxI);
    bool hasSprite = textureSize(spriteMap, 0).x > 4;
    if (texelFetch(depthMap, ip0, 0).r < 1.0) {
        float stepPx = max(2.0, 3.0 * ambient.view.z);
        const vec2 OFFS[4] = vec2[4](vec2(1.0, 0.0), vec2(-1.0, 0.0), vec2(0.0, 1.0), vec2(0.0, -1.0));
        float acc = 0.0;
        float wSum = 0.0;
        for (int k = 0; k < 4; k++) {
            ivec2 np = clamp(ivec2(floor(px + OFFS[k] * stepPx)), ivec2(0), maxI);
            if (texelFetch(depthMap, np, 0).r >= 1.0) {
                acc += samplePondWaterTap(np, maxI, hasSprite);
                wSum += 1.0;
            }
        }
        return wSum > 0.0 ? acc / wSum : smoothstep(0.55, 0.90, waterAt(q));
    }
    vec2 t = px - 0.5;
    ivec2 b = ivec2(floor(t));
    vec2 f = t - vec2(b);
    float sum = 0.0;
    for (int i = 0; i < 4; i++) {
        ivec2 cIdx = clamp(b + ivec2(i & 1, i >> 1), ivec2(0), maxI);
        float w = ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
        float tap = texelFetch(depthMap, cIdx, 0).r >= 1.0
            ? samplePondWaterTap(cIdx, maxI, hasSprite)
            : samplePondWaterTap(ip0, maxI, hasSprite);
        sum += tap * w;
    }
    return sum;
}

float pondBasinKeep(vec2 q, float base) {
    if (waterAt(q) <= 0.008) return 1.0;
    float w0 = samplePondGroundWater(q, base);
    const float R1 = 0.048;
    const float R2 = 0.072;
    float wCard = 0.25 * (
        samplePondGroundWater(q + vec2(R1, 0.0), base) +
        samplePondGroundWater(q - vec2(R1, 0.0), base) +
        samplePondGroundWater(q + vec2(0.0, R1), base) +
        samplePondGroundWater(q - vec2(0.0, R1), base));
    if (w0 > 0.85 && wCard > 0.80) return 0.0;
    float wDiag = 0.25 * (
        samplePondGroundWater(q + vec2(R2, R2), base) +
        samplePondGroundWater(q - vec2(R2, R2), base) +
        samplePondGroundWater(q + vec2(R2, -R2), base) +
        samplePondGroundWater(q - vec2(R2, -R2), base));
    float wSmooth = 0.26 * w0 + 0.44 * wCard + 0.30 * wDiag;
    return 1.0 - smoothstep(0.08, 0.56, wSmooth);
}

// Organic, domain-warped 2-5 tile winter earth patches (modeled on Vacation's scattered worn-dirt patches).
float dirtField(vec2 l) {
    vec2 w = vec2(valueNoise(l * 0.55 + 4.3), valueNoise(l * 0.55 + 19.7)) - 0.5;
    return valueNoise((l + w * 1.4) * 0.30 + 2.1) * 0.55
         + valueNoise(l * 0.95 + 13.7) * 0.30
         + valueNoise(l * 2.8 + 27.3) * 0.15;
}

// Smooth radial snowdrift banking beside walls/fences (clamped per tap so tall 2-story walls never create a hard box step).
float wallBank(vec2 q, float base) {
    float nearCheck = max(
        max(max(topAt(q + vec2(0.68, 0.0)), topAt(q - vec2(0.68, 0.0))),
            max(topAt(q + vec2(0.0, 0.68)), topAt(q - vec2(0.0, 0.68)))),
        max(max(topAt(q + vec2(0.48, 0.48)), topAt(q - vec2(0.48, 0.48))),
            max(topAt(q + vec2(0.48, -0.48)), topAt(q - vec2(0.48, -0.48)))));
    if (nearCheck <= base + 0.25) return 0.0;
    float r1 = 0.0, r2 = 0.0, r3 = 0.0;
    for (int i = 0; i < 8; i++) {
        float a = float(i) * 0.7853982;
        vec2 d = vec2(cos(a), sin(a));
        r1 += smoothstep(0.35, 1.35, topAt(q + d * 0.18) - base);
        r2 += smoothstep(0.35, 1.35, topAt(q + d * 0.36) - base);
        r3 += smoothstep(0.35, 1.35, topAt(q + d * 0.54) - base);
    }
    return clamp((r1 * 0.50 + r2 * 0.35 + r3 * 0.15) / 8.0, 0.0, 1.0);
}

float snowHeight(vec2 q, float base, float full, float amount, float groundWear, float isVac) {
    if (amount <= 0.001) return 0.0;
    vec3 p3 = vec3(q, base + 0.1);
    float outside = architecturalExposure(p3);
    if (outside <= 0.001) return 0.0;
    float inRoom = indoors(p3);
    if (inRoom > 0.48) return 0.0;
    outside = min(1.0 - smoothstep(0.32, 0.48, inRoom), outside);
    if (outside <= 0.001) return 0.0;
    vec2 l = lotSource(q);
    float bank = wallBank(q, base);
    float overhead = smoothstep(1.1, 2.5, max(0.0, topAt(q) - base));
    overhead += smoothstep(1.1, 2.5, max(0.0, topAt(q + vec2(0.28, 0.0)) - base));
    overhead += smoothstep(1.1, 2.5, max(0.0, topAt(q - vec2(0.28, 0.0)) - base));
    overhead += smoothstep(1.1, 2.5, max(0.0, topAt(q + vec2(0.0, 0.28)) - base));
    overhead += smoothstep(1.1, 2.5, max(0.0, topAt(q - vec2(0.0, 0.28)) - base));
    overhead *= 0.2;
    float vacWear = isVac * groundWear * 0.72;
    const vec2 wDir = vec2(0.9284767, 0.3713907);
    const vec2 wPerp = vec2(-0.3713907, 0.9284767);
    vec2 wCoord = vec2(dot(l, wDir) * 0.085, dot(l, wPerp) * 0.22);
    float windSwell = valueNoise(wCoord + vec2(3.7, 7.1)) * 0.76 + valueNoise(l * 0.14 + 11.3) * 0.24;
    float shelterDelay = (0.16 * overhead + 0.14 * vacWear) * (1.0 - 0.62 * smoothstep(0.42, 1.05, amount));
    float windLead = ((windSwell - 0.5) * 0.18 + 0.05 * bank) * smoothstep(0.0, 0.10, amount) * (1.0 - 0.65 * smoothstep(0.55, 1.05, amount));
    float effAmt = max(0.0, amount * (1.0 + 0.14 * bank) - shelterDelay + windLead);
    float onset = clamp(effAmt / max(amount, 1e-4), 0.0, 1.35);
    if (onset <= 0.001) return 0.0;
    float depthScale = (0.84 + 0.32 * windSwell) * (1.0 - 0.24 * overhead - 0.45 * vacWear);
    float paved = pavedAt(q);
    float paveKeep = 1.0 - paved * mix(0.96, 0.995, clamp(amount - 0.6, 0.0, 1.0));
    float waterKeep = pondBasinKeep(q, base);
    float snow = full * onset * outside * depthScale * (1.0 + 0.16 * bank) * paveKeep * waterKeep;
    if (snow <= 0.001) return 0.0;
    return snow - min(0.025, snow * 0.5) * pressedAt(q);
}

// The same brightness as `like` in a new colour.
vec3 recolor(vec3 like, vec3 hue) { return hue * (dot(like, LUMA) / max(dot(hue, LUMA), 1e-3)); }

vec3 srgbToLinear(vec3 c) {
    return mix(c / 12.92, pow((c + 0.055) / 1.055, vec3(2.4)), step(vec3(0.04045), c));
}

// Perceptual (gamma-2) blend matching Sims 1's sRGB snow-to-dirt ramp so cool snow + warm dirt stays warm taupe rather than greying out.
vec3 mixPerceptual(vec3 a, vec3 b, float t) {
    vec3 m = mix(sqrt(max(a, vec3(0.0))), sqrt(max(b, vec3(0.0))), clamp(t, 0.0, 1.0));
    return m * m;
}

float peakRiseAt(vec2 q, float base) {
    ivec2 size = textureSize(heightMap, 0);
    vec2 t = (q + ambient.frame.w) * ambient.frame.z - 0.5;
    ivec2 b = ivec2(floor(t));
    float peak = 0.0;
    for (int i = 0; i < 4; i++) {
        ivec2 c = clamp(b + ivec2(i & 1, i >> 1), ivec2(0), size - 1);
        peak = max(peak, (0.5 - texelFetch(heightMap, c, 0).r) * HEIGHT_RANGE - base);
    }
    return peak;
}

float treeCrownAt(vec2 q, float baseZ) {
    float peak = peakRiseAt(q, baseZ);
    if (peak <= 2.05) return 0.0;
    // Require a real tree canopy footprint (at least 2 of 4 neighbors at 0.35 tiles also rise > 1.65),
    // rejecting thin poles, streetlights, and narrow tombstones.
    float crownSpan = step(1.65, peakRiseAt(q + vec2(0.35, 0.0), baseZ))
                    + step(1.65, peakRiseAt(q - vec2(0.35, 0.0), baseZ))
                    + step(1.65, peakRiseAt(q + vec2(0.0, 0.35), baseZ))
                    + step(1.65, peakRiseAt(q - vec2(0.0, 0.35), baseZ));
    if (crownSpan < 2.0) return 0.0;
    vec3 p = vec3(q, baseZ + 0.1);
    if (indoors(p) > 0.05 || architecturalExposure(p) < 0.95) return 0.0;
    // Reject house roof eaves & multi-tile architectural overhangs bridging continuously out from indoor rooms.
    for (int i = 0; i < 8; i++) {
        float a = float(i) * 0.7853982;
        vec2 dir = vec2(cos(a), sin(a));
        bool connectedHigh = true;
        for (int k = 1; k <= 3; k++) {
            vec2 nxy = q + dir * (0.85 * float(k));
            vec3 np = vec3(nxy, baseZ + 0.1);
            if (k == 1 && (indoors(np) > 0.05 || architecturalExposure(np) < 0.95)) return 0.0;
            if (topAt(nxy) - baseZ <= 1.35) {
                connectedHigh = false;
                break;
            }
            if (connectedHigh && (indoors(np) > 0.05 || architecturalExposure(np) < 0.95)) return 0.0;
        }
    }
    return smoothstep(2.05, 2.65, peak);
}

vec3 autumnRamp5(vec3 c0, vec3 c1, vec3 c2, vec3 c3, vec3 c4, float s) {
    return s < 0.25 ? mix(c0, c1, s / 0.25)
         : s < 0.52 ? mix(c1, c2, (s - 0.25) / 0.27)
         : s < 0.78 ? mix(c2, c3, (s - 0.52) / 0.26)
         : mix(c3, c4, (s - 0.78) / 0.22);
}

vec3 makinMagicTreeSrgb(float sunlitT, float familyHue) {
    float s = clamp(sunlitT, 0.0, 1.0);
    float h = clamp(familyHue, 0.0, 1.0);

    vec3 goldColor = autumnRamp5(
        vec3(0.325, 0.247, 0.078),
        vec3(0.580, 0.451, 0.137),
        vec3(0.808, 0.635, 0.180),
        vec3(0.925, 0.784, 0.251),
        vec3(0.984, 0.882, 0.349),
        s);

    vec3 tangerineColor = autumnRamp5(
        vec3(0.349, 0.169, 0.047),
        vec3(0.620, 0.306, 0.075),
        vec3(0.839, 0.459, 0.125),
        vec3(0.949, 0.612, 0.180),
        vec3(0.984, 0.769, 0.251),
        s);

    vec3 scarletColor = autumnRamp5(
        vec3(0.306, 0.086, 0.027),
        vec3(0.537, 0.145, 0.047),
        vec3(0.745, 0.224, 0.075),
        vec3(0.894, 0.353, 0.118),
        vec3(0.965, 0.525, 0.180),
        s);

    vec3 burgundyColor = autumnRamp5(
        vec3(0.255, 0.082, 0.090),
        vec3(0.412, 0.161, 0.169),
        vec3(0.561, 0.239, 0.247),
        vec3(0.706, 0.345, 0.353),
        vec3(0.835, 0.467, 0.475),
        s);

    if (h < 0.34) return mix(goldColor, tangerineColor, h / 0.34);
    if (h < 0.70) return mix(tangerineColor, scarletColor, (h - 0.34) / 0.36);
    return mix(scarletColor, burgundyColor, (h - 0.70) / 0.30);
}

// Keep synchronized with atmosphere.frag fallenLeafColorSrgb.
vec3 fallenLeafColorSrgb(float hueSeed, float speciesHue) {
    float s = clamp(hueSeed, 0.0, 1.0);
    float h = clamp(speciesHue, 0.0, 1.0);

    vec3 goldLeaf = s < 0.34 ? mix(vec3(0.945, 0.867, 0.255), vec3(0.898, 0.710, 0.173), s / 0.34)
        : s < 0.72 ? mix(vec3(0.898, 0.710, 0.173), vec3(0.835, 0.565, 0.165), (s - 0.34) / 0.38)
        : mix(vec3(0.835, 0.565, 0.165), vec3(0.686, 0.455, 0.141), (s - 0.72) / 0.28);

    vec3 spellboundLeaf = s < 0.28 ? mix(vec3(0.953, 0.835, 0.235), vec3(0.945, 0.588, 0.145), s / 0.28)
        : s < 0.64 ? mix(vec3(0.945, 0.588, 0.145), vec3(0.894, 0.345, 0.098), (s - 0.28) / 0.36)
        : mix(vec3(0.894, 0.345, 0.098), vec3(0.682, 0.235, 0.082), (s - 0.64) / 0.36);

    vec3 scarletLeaf = s < 0.32 ? mix(vec3(0.949, 0.655, 0.184), vec3(0.890, 0.349, 0.106), s / 0.32)
        : s < 0.70 ? mix(vec3(0.890, 0.349, 0.106), vec3(0.757, 0.208, 0.078), (s - 0.32) / 0.38)
        : mix(vec3(0.757, 0.208, 0.078), vec3(0.545, 0.149, 0.067), (s - 0.70) / 0.30);

    vec3 burgundyLeaf = s < 0.34 ? mix(vec3(0.820, 0.451, 0.459), vec3(0.682, 0.314, 0.325), s / 0.34)
        : s < 0.70 ? mix(vec3(0.682, 0.314, 0.325), vec3(0.549, 0.220, 0.231), (s - 0.34) / 0.36)
        : mix(vec3(0.549, 0.220, 0.231), vec3(0.396, 0.145, 0.157), (s - 0.70) / 0.30);

    if (h < 0.30) return mix(goldLeaf, spellboundLeaf, h / 0.30);
    if (h < 0.62) return mix(spellboundLeaf, scarletLeaf, (h - 0.30) / 0.32);
    if (h < 0.80) return mix(scarletLeaf, burgundyLeaf, (h - 0.62) / 0.18);
    return burgundyLeaf;
}

// One z-ordered layer of organic curved fallen tree leaves + subtle ground contact shadow.
// Returns x = leaf alpha, y = contact shadow, z = per-leaf shade, w = per-leaf hue seed.
vec4 fallenLeafLayer(vec2 lot, float freq, float angleRad, float seed, float density, float minSize, float maxSize, float lotPixelScale) {
    if (density <= 0.005) return vec4(0.0);
    float ca = cos(angleRad), sa = sin(angleRad);
    vec2 g = mat2(ca, sa, -sa, ca) * (lot * freq);
    vec2 base = floor(g - 0.5);
    float bestOrder = -1.0;
    float bestMask = 0.0;
    float bestShade = 1.0;
    float bestHue = 0.5;
    float shadowAcc = 0.0;
    for (int m = 0; m < 4; m++) {
        vec2 cell = base + vec2(float(m & 1), float(m >> 1));
        float h1 = hash12(cell + seed);
        if (h1 > density) continue;
        float h2 = hash12(cell + seed + vec2(17.3, 9.1));
        float h3 = hash12(cell + seed + vec2(43.7, 29.4));
        float h4 = hash12(cell + seed + vec2(71.9, 53.2));
        vec2 center = cell + 0.22 + 0.56 * vec2(fract(h1 * 13.7), fract(h2 * 19.3));
        vec2 d = g - center;
        float size = mix(minSize, maxSize, h3);
        if (dot(d, d) > size * size * 1.44) continue;
        float la = h4 * 6.2831853;
        float lc = cos(la), ls = sin(la);
        vec2 local = vec2(d.x * lc + d.y * ls, -d.x * ls + d.y * lc) / size;
        float bend = (fract(h3 * 23.1) - 0.5) * 0.36;
        float ly = local.y + bend * local.x * local.x;
        float ruffle = 1.0 + 0.06 * sin(local.x * 7.0 + h4 * 6.2831853);
        float pinch = max(0.32, 1.0 - 0.42 * clamp(local.x * local.x, 0.0, 1.0)) * ruffle;
        float shape = length(vec2(local.x / 0.85, ly / (0.46 * pinch)));
        float aa = clamp(lotPixelScale * freq * 0.85 / max(size, 0.12), 0.10, 0.48);
        float alpha = 1.0 - smoothstep(1.0 - aa, 1.0 + aa, shape);

        vec2 sOff = mat2(ca, sa, -sa, ca) * (vec2(0.10, 0.10) * size);
        vec2 sd = d - sOff;
        vec2 sLocal = vec2(sd.x * lc + sd.y * ls, -sd.x * ls + sd.y * lc) / (size * 1.12);
        float sly = sLocal.y + bend * sLocal.x * sLocal.x;
        float sPinch = max(0.32, 1.0 - 0.42 * clamp(sLocal.x * sLocal.x, 0.0, 1.0));
        float sShape = length(vec2(sLocal.x / 0.85, sly / (0.48 * sPinch)));
        float sAlpha = (1.0 - smoothstep(0.65, 1.25, sShape)) * 0.65;
        shadowAcc = max(shadowAcc, sAlpha);

        if (alpha > 0.01) {
            float order = h2 + 0.01 * float(m);
            if (order > bestOrder) {
                bestOrder = order;
                bestMask = alpha;
                bestShade = 0.86 + 0.28 * fract(h1 * 31.7 + h3 * 7.3) * smoothstep(-0.9, 0.7, -local.y);
                bestHue = fract(h4 * 17.3 + h2 * 5.9);
            }
        }
    }
    return vec4(bestMask, shadowAcc, bestShade, bestHue);
}

// Smooth wind-packed snow crust variation (silky surface without per-pixel gritty noise).
float snowCrust(vec2 lq) {
    return valueNoise(lq * 3.6 + 3.2) * 0.65 + valueNoise(lq * 8.8 + 17.4) * 0.35;
}

float greenOf(vec3 c) {
    return smoothstep(0.06, 0.22, (c.g - max(c.r, c.b)) / max(c.g, 0.04));
}

float foliageOf(vec3 c) {
    float g = greenOf(c);
    float olive = smoothstep(1.30, 1.80, c.g / max(c.b, 0.008))
                * smoothstep(1.10, 0.96, c.r / max(c.g, 0.008))
                * smoothstep(0.015, 0.045, c.g);
    return max(g, 0.85 * olive);
}

// How close a non-ground pixel is to an indoor room boundary (exterior/cutaway walls sit right on this edge).
float nearIndoorWall(vec2 xy, float z, float radius) {
    float w = 0.0;
    for (int i = 0; i < 4; i++) {
        vec2 card = radius * vec2(i == 0 ? 1.0 : i == 1 ? -1.0 : 0.0, i == 2 ? 1.0 : i == 3 ? -1.0 : 0.0);
        vec2 diag = radius * vec2(i < 2 ? 1.0 : -1.0, (i & 1) == 1 ? 1.0 : -1.0);
        w = max(w, indoors(vec3(xy + card, z)));
        w = max(w, indoors(vec3(xy + diag, z)));
    }
    return w;
}

vec3 applyAutumnFoliage(vec3 col, vec3 here, float fallbackBaseZ, vec2 lot, float amount, float outdoor, bool sim, bool mapped, bool hasLiveFloraMap, out float outFolAct) {
    outFolAct = 0.0;
    float lum = dot(col, LUMA);
    float denom = max(col.g, 0.002);
    float blueDrop = (col.g - col.b) / denom;
    float greenVsRed = (col.g - col.r) / denom;
    float keepGreen = 0.0;
    float explicitDeciduous = 0.0;
    float stampedLumRef = 0.0;
    float speciesHue = 0.14 + 0.76 * valueNoise(lot * 0.24 + 7.3);
    float relZ = mapped ? (here.z - terrainBaseAt(here.xy, fallbackBaseZ)) : here.z;
    if (hasLiveFloraMap) {
        vec4 flora = floraAt(here.xy, stampedLumRef);
        float lowBlock = smoothstep(0.22, 0.46, flora.r);
        float tallBlock = smoothstep(0.70, 0.88, flora.r);
        keepGreen = mix(lowBlock, tallBlock, smoothstep(1.25, 1.65, relZ));
        explicitDeciduous = clamp(flora.w * 2.5, 0.0, 1.0);
        speciesHue = mix(speciesHue, flora.b, explicitDeciduous);
    }
    float strictFoliage = smoothstep(0.20, 0.50, blueDrop) * smoothstep(-0.22, 0.06, greenVsRed);
    float coolLeafFoliage = smoothstep(0.12, 0.34, blueDrop) * smoothstep(0.08, 0.26, greenVsRed);
    float foliageGreen = mix(strictFoliage, max(strictFoliage, coolLeafFoliage), explicitDeciduous);
    float isDeciduous = (1.0 - keepGreen) * (hasLiveFloraMap ? explicitDeciduous : smoothstep(0.14, 0.32, relZ));
    float isCanopy = smoothstep(0.85, 1.45, relZ);
    float defaultLumRef = mix(0.076, 0.036, isCanopy);
    float lumRef = (hasLiveFloraMap && stampedLumRef > 0.005)
        ? mix(defaultLumRef, stampedLumRef, explicitDeciduous)
        : defaultLumRef;
    float u = lum / max(lumRef, 0.018);
    float sunlit = 0.86 * smoothstep(0.16, 1.95, u) + 0.14 * clamp(u / 2.35, 0.0, 1.0);
    float leafDetail = valueNoise(lot * 5.5 + vec2(here.z * 3.1, -here.z * 2.4) + 19.1);
    float boughCluster = valueNoise(lot * 2.3 + vec2(relZ * 1.9, -relZ * 1.5) + 5.7) * 0.65
                       + valueNoise(lot * 5.2 - vec2(relZ * 2.7, relZ * 2.1) + 31.4) * 0.35;
    float sunlitT = clamp(0.05 + 0.88 * sunlit + 0.09 * (leafDetail - 0.5) + 0.04 * (amount - 0.5), 0.0, 1.0);
    float evergreenWarm = (sim ? 0.0 : strictFoliage) * keepGreen * outdoor
                        * smoothstep(0.08, 0.70, amount) * (0.14 + 0.16 * leafDetail);
    float turned = (sim ? 0.0 : foliageGreen) * isDeciduous * outdoor
                 * smoothstep(0.04 + 0.06 * (1.0 - sunlit), 0.22 + 0.08 * (1.0 - sunlit), amount);
    float decBranch = (!sim && hasLiveFloraMap) ? isDeciduous * outdoor * smoothstep(0.35, 0.85, relZ) : 0.0;
    outFolAct = max(max(turned, evergreenWarm), decBranch);
    if (turned <= 0.005 && evergreenWarm <= 0.005) return col;
    vec3 baseCol = evergreenWarm > 0.005
        ? mix(col, recolor(col, vec3(0.48, 0.44, 0.14)), evergreenWarm)
        : col;
    if (turned <= 0.005) return baseCol;

    float localHue = speciesHue;
    if (speciesHue >= 0.77) {
        float burgShift = (boughCluster - 0.5) * 0.12 + (leafDetail - 0.5) * 0.06;
        localHue = clamp(0.76 + (speciesHue - 0.77) * 1.15 + burgShift, 0.75, 1.0);
    } else if (isCanopy > 0.35) {
        float spellWeight = smoothstep(0.18, 0.36, speciesHue);
        float crownGold = (smoothstep(1.85, 3.15, relZ) * 0.52 + sunlit * 0.48) * 0.24 * spellWeight;
        float boughBlaze = (0.54 - boughCluster) * mix(0.18, 0.46, spellWeight);
        localHue = clamp(speciesHue - crownGold + boughBlaze + (leafDetail - 0.5) * 0.06, 0.02, 0.69);
    } else {
        float tipFlare = smoothstep(0.48, 0.86, leafDetail * 0.62 + sunlit * 0.38) * (1.0 - smoothstep(0.44, 0.68, speciesHue));
        float shrubVar = (boughCluster - 0.5) * 0.16;
        localHue = clamp(speciesHue + 0.30 * tipFlare + shrubVar, 0.04, 0.69);
    }

    vec3 turnedColor = srgbToLinear(makinMagicTreeSrgb(sunlitT, localHue));
    float darkCrevice = mix(0.40, 1.0, smoothstep(0.03, 0.34, u));
    float brightSpark = 1.0 + 0.12 * clamp(u - 1.65, 0.0, 1.15);
    turnedColor *= darkCrevice * brightSpark;
    float peak = max(turnedColor.r, max(turnedColor.g, turnedColor.b));
    if (peak > 1.0) turnedColor /= peak;
    float blend = mix(0.94, 0.995, sunlit);
    return mix(baseCol, turnedColor, turned * blend);
}

vec3 applyAutumnGround(vec3 col, vec3 hereG, vec2 gLot, float gPixelScale, float amount, float gOutdoor, float gSkyExposed, bool mapped, bool hasLiveFloraMap, bool leavesOnlyOnTurf) {
    float gLum = dot(col, LUMA);
    float pondWater = pondWaterOf(col);
    float gGreen = smoothstep(0.06, 0.22, (col.g - max(col.r, col.b)) / max(col.g, 0.04)) * (1.0 - pondWater);
    vec3 outCol = col;
    float autPaved = mapped ? pavedAt(hereG.xy) : 0.0;
    float autCement = mapped ? cementAt(hereG.xy) : 0.0;
    float autWaterTile = mapped ? waterAt(hereG.xy) : 0.0;
    float onTurf = gGreen * (1.0 - 0.95 * autPaved) * (1.0 - autCement);
    if (onTurf > 0.01) {
        float bladeShade = smoothstep(0.025, 0.13, gLum);
        vec3 mmGrass = mix(srgbToLinear(vec3(0.408, 0.235, 0.125)), srgbToLinear(vec3(0.565, 0.478, 0.220)), bladeShade);
        float mulchPatch = smoothstep(0.52, 0.84, dirtField(gLot)) * amount;
        vec3 mmMulch = srgbToLinear(vec3(0.459, 0.294, 0.157)) * clamp(gLum / 0.095, 0.45, 1.25);
        vec3 autumnTurf = mix(recolor(col, mmGrass), mmMulch, mulchPatch * 0.42);
        outCol = mix(outCol, autumnTurf, onTurf * gOutdoor * gSkyExposed * clamp(0.72 * amount, 0.0, 0.78));
    }
    if (autWaterTile > 0.02 && pondWater < 0.85) {
        float warmSand = smoothstep(0.01, 0.08, col.r - col.g)
                       * smoothstep(0.03, 0.12, col.g - col.b)
                       * (1.0 - pondWater)
                       * smoothstep(0.02, 0.25, autWaterTile);
        if (warmSand > 0.01) {
            vec3 autBank = mix(recolor(col, srgbToLinear(vec3(0.48, 0.35, 0.20))), col * vec3(0.88, 0.80, 0.68), 0.35);
            outCol = mix(outCol, autBank, warmSand * gOutdoor * gSkyExposed * clamp(0.75 * amount, 0.0, 0.80));
        }
    }
    if (pondWater > 0.02) {
        vec3 autWater = mix(col, col * vec3(0.84, 0.88, 0.92), clamp(0.55 * amount, 0.0, 0.55) * gOutdoor * gSkyExposed);
        outCol = mix(outCol, autWater, pondWater);
    }
    float notWater = (1.0 - pondWater) * (1.0 - smoothstep(0.01, 0.05, col.b - max(col.r, col.g)));
    float leafGround = (1.0 - 0.95 * autPaved) * (1.0 - 0.90 * autCement) * notWater;
    if (leavesOnlyOnTurf) leafGround *= smoothstep(0.02, 0.14, onTurf);
    if (mapped && leafGround > 0.05 && gOutdoor > 0.01 && gSkyExposed > 0.01) {
        float innerCanopy = 0.0;
        float outerCanopy = 0.0;
        float treeHue = 0.35;
        if (hasLiveFloraMap) {
            float unusedLumRef = 0.0;
            vec4 flora = floraAt(hereG.xy, unusedLumRef);
            float edgeBreak = (valueNoise(gLot * 1.4 + 9.2) * 0.65 + valueNoise(gLot * 3.8 + 21.4) * 0.35 - 0.5) * 0.38;
            float dropField = clamp(flora.g + edgeBreak * smoothstep(0.0, 0.45, flora.g), 0.0, 1.0);
            innerCanopy = smoothstep(0.26, 0.80, dropField);
            outerCanopy = smoothstep(0.02, 0.54, dropField);
            float defaultHue = 0.16 + 0.58 * valueNoise(gLot * 0.24 + 7.3);
            treeHue = mix(defaultHue, flora.b, clamp(flora.w * 2.5, 0.0, 1.0));
        } else {
            float anyPeak = peakRiseAt(hereG.xy, hereG.z);
            if (anyPeak <= 2.05) {
                for (int i = 0; i < 8; i++) {
                    float a = float(i) * 0.7853982;
                    anyPeak = max(anyPeak, peakRiseAt(hereG.xy + vec2(cos(a), sin(a)) * 1.20, hereG.z));
                    if (anyPeak > 2.05) break;
                }
            }
            if (anyPeak > 2.05) {
                innerCanopy = treeCrownAt(hereG.xy, hereG.z);
                outerCanopy = innerCanopy * 0.72;
                for (int i = 0; i < 8; i++) {
                    float a = float(i) * 0.7853982;
                    vec2 dir = vec2(cos(a), sin(a));
                    innerCanopy = max(innerCanopy, 0.94 * treeCrownAt(hereG.xy + dir * 0.45, hereG.z));
                    outerCanopy = max(outerCanopy, 0.56 * treeCrownAt(hereG.xy + dir * 0.90, hereG.z));
                }
                outerCanopy = max(outerCanopy, innerCanopy * 0.72);
                treeHue = valueNoise(gLot * 0.24 + 7.3);
            }
        }
        if (outerCanopy > 0.02) {
            float patchNoise = valueNoise(gLot * 2.2 + 3.7) * 0.65 + valueNoise(gLot * 5.0 + 11.3) * 0.35;
            float baseLumScale = clamp(gLum / 0.10, 0.55, 1.15) * 0.92;
            float leafWeight = gOutdoor * gSkyExposed * leafGround;

            float d0 = clamp(innerCanopy * amount * smoothstep(0.14, 0.64, patchNoise + 0.42 * innerCanopy) * 0.96, 0.0, 0.96);
            float d1 = clamp(max(innerCanopy * 0.88, outerCanopy * 0.62) * amount * smoothstep(0.20, 0.70, patchNoise + 0.32 * outerCanopy) * 0.86, 0.0, 0.88);
            float d2 = clamp(max(innerCanopy * 0.66, outerCanopy * 0.42) * amount * smoothstep(0.26, 0.76, patchNoise + 0.24 * outerCanopy) * 0.68, 0.0, 0.70);

            vec4 l0 = fallenLeafLayer(gLot,  7.4, 0.00,  3.1, d0, 0.30, 0.42, gPixelScale);
            if (l0.x > 0.005 || l0.y > 0.005) {
                outCol *= 1.0 - 0.32 * l0.y * leafWeight * (1.0 - l0.x);
                vec3 c0 = srgbToLinear(fallenLeafColorSrgb(l0.w, treeHue)) * 0.78 * l0.z * baseLumScale;
                outCol = mix(outCol, c0, l0.x * leafWeight * 0.94);
            }
            vec4 l1 = fallenLeafLayer(gLot,  9.4, 0.67, 19.7, d1, 0.28, 0.40, gPixelScale);
            if (l1.x > 0.005 || l1.y > 0.005) {
                outCol *= 1.0 - 0.30 * l1.y * leafWeight * (1.0 - l1.x);
                vec3 c1 = srgbToLinear(fallenLeafColorSrgb(l1.w, treeHue)) * 1.04 * l1.z * baseLumScale;
                outCol = mix(outCol, c1, l1.x * leafWeight * 0.94);
            }
            vec4 l2 = fallenLeafLayer(gLot, 11.6, 1.31, 41.3, d2, 0.27, 0.38, gPixelScale);
            if (l2.x > 0.005 || l2.y > 0.005) {
                outCol *= 1.0 - 0.28 * l2.y * leafWeight * (1.0 - l2.x);
                vec3 c2 = srgbToLinear(fallenLeafColorSrgb(l2.w, treeHue)) * 1.18 * l2.z * baseLumScale;
                outCol = mix(outCol, c2, l2.x * leafWeight * 0.94);
            }
        }
    }
    return outCol;
}

void evalGroundTerms(
    vec3 c, vec2 xy, float isGroundF, float vacLot, out float isVacSnowLot,
    out float earthMask, out float terrainWear, out float greenOut, out float lumOut)
{
    lumOut = dot(c, LUMA);
    float pondBlue = pondWaterOf(c);
    greenOut = greenOf(c) * (1.0 - pondBlue);
    float pavedHere = isGroundF > 0.5 ? pavedAt(xy) : 0.0;
    float cementHere = isGroundF > 0.5 ? cementAt(xy) : 0.0;
    float waterHere = isGroundF > 0.5 ? waterAt(xy) : 0.0;
    float vacSnowBlue = (isGroundF > 0.5 && pavedHere < 0.35 && cementHere < 0.35 && waterHere < 0.10)
        ? smoothstep(0.32, 0.52, c.b) * smoothstep(0.01, 0.05, c.b - c.r)
        : 0.0;
    isVacSnowLot = clamp(max(vacLot, vacSnowBlue), 0.0, 1.0);
    float warmOverGreen = smoothstep(-0.01, 0.04, (c.r - c.g) / max(c.r, 0.05));
    float vacWarmth = (c.r - c.b) / max(c.r + c.b, 0.05);
    float naturalEarth = max(greenOut, smoothstep(0.34, 0.52, vacWarmth)) * (1.0 - pondBlue);
    earthMask = isGroundF * clamp(max(naturalEarth, isVacSnowLot * (1.0 - pondBlue)), 0.0, 1.0) * (1.0 - cementHere);
    float vacDirt = (isGroundF > 0.5 && pavedHere < 0.35 && pondBlue < 0.25)
        ? warmOverGreen * smoothstep(0.015, 0.24, vacWarmth) * smoothstep(0.03, 0.10, c.r)
          * isVacSnowLot * (1.0 - cementHere)
        : 0.0;
    float homeWear = (isGroundF > 0.5 && pavedHere < 0.35 && waterHere < 0.10 && pondBlue < 0.25)
        ? smoothstep(0.76, 1.12, c.r / max(c.g, 0.015))
          * smoothstep(0.42, 0.58, vacWarmth)
          * smoothstep(0.015, 0.045, max(c.r, c.g))
          * (1.0 - isVacSnowLot) * (1.0 - cementHere)
        : 0.0;
    terrainWear = max(vacDirt, homeWear);
}

vec3 winterDullColor(vec3 c, vec3 herePt, vec2 lotPt, float lumVal, float greenVal, float hereCrust, float earthMask, float terrainWear, float isVacSnowLot, float coveredVal, bool isGround, float amount) {
    float snowPresence = smoothstep(0.0, 0.35, amount);
    if (isGround) {
        vec2 xy = herePt.xy;
        float wTile = waterAt(xy);
        float pondWater = pondWaterOf(c);
        if (wTile > 0.008) {
            float baseZ = herePt.z;
            const float R1 = 0.055;
            const float R2 = 0.115;
            float wInner = 0.25 * (
                samplePondGroundWater(xy + vec2(R1, 0.0), baseZ) +
                samplePondGroundWater(xy - vec2(R1, 0.0), baseZ) +
                samplePondGroundWater(xy + vec2(0.0, R1), baseZ) +
                samplePondGroundWater(xy - vec2(0.0, R1), baseZ));
            float wOuter = 0.125 * (
                samplePondGroundWater(xy + vec2(R2, 0.0), baseZ) +
                samplePondGroundWater(xy - vec2(R2, 0.0), baseZ) +
                samplePondGroundWater(xy + vec2(0.0, R2), baseZ) +
                samplePondGroundWater(xy - vec2(0.0, R2), baseZ) +
                samplePondGroundWater(xy + vec2(0.707 * R2, 0.707 * R2), baseZ) +
                samplePondGroundWater(xy + vec2(-0.707 * R2, 0.707 * R2), baseZ) +
                samplePondGroundWater(xy + vec2(0.707 * R2, -0.707 * R2), baseZ) +
                samplePondGroundWater(xy + vec2(-0.707 * R2, -0.707 * R2), baseZ));
            float freezeNoise = valueNoise(lotPt * 2.4 + 5.7) * 0.60 + valueNoise(lotPt * 6.8 + 19.3) * 0.40;
            float wField = 0.45 * wInner + 0.55 * wOuter;
            float shoreRim = smoothstep(0.04, 0.78, (1.0 - wField) + (freezeNoise - 0.5) * 0.24);
            float ripple = clamp((lumVal - 0.040) * 3.0, -0.07, 0.09);
            vec3 coldWater = mix(c, srgbToLinear(vec3(0.16, 0.28, 0.42)) * clamp(lumVal / 0.042, 0.65, 1.35), 0.58 * snowPresence);
            float effFreeze = amount * (1.0 - 0.18 * coveredVal) + 0.28 * shoreRim + (freezeNoise - 0.5) * 0.16;
            float iceSheet = smoothstep(0.15, 0.66, effFreeze);
            float rimeCover = smoothstep(0.42, 1.12, effFreeze + 0.24 * shoreRim + (hereCrust - 0.5) * 0.18);
            vec3 blueIce = srgbToLinear(vec3(0.46, 0.59, 0.73)) * (0.94 + ripple + 0.11 * hereCrust);
            vec3 frostRim = mix(SNOW_SHADE, SNOW, 0.54 + 0.28 * hereCrust);
            vec3 frozen = mix(blueIce, frostRim, clamp(0.24 * rimeCover + 0.64 * shoreRim * smoothstep(0.18, 0.70, amount), 0.0, 0.90));
            vec3 icedPond = mix(coldWater, frozen, iceSheet);

            float bankMask = clamp(max(max(wInner, wOuter) * 2.2, smoothstep(0.08, 0.36, (c.r - c.b) / max(c.r + c.b, 0.04)) * (1.0 - greenVal)), 0.0, 1.0);
            vec3 coldBank = recolor(c, srgbToLinear(vec3(0.42, 0.45, 0.49)));
            vec3 snowBank = mix(SNOW_SHADE, SNOW, 0.62 + 0.24 * hereCrust);
            vec3 frostedBank = mix(coldBank, snowBank, smoothstep(0.08, 0.42, amount));
            vec3 nonWaterCol = mix(c, frostedBank, bankMask * snowPresence);
            if (pondWater > 0.01 || bankMask > 0.01) {
                return mix(nonWaterCol, icedPond, pondWater);
            }
        }
    }
    vec3 targetHue = (isGround && isVacSnowLot < 0.5) ? vec3(0.31, 0.38, 0.28) : vec3(0.30, 0.42, 0.36);
    return mix(c, recolor(c, targetHue), 0.38 * greenVal * snowPresence);
}

vec3 marchSnowDrift(
    vec3 srcCol, vec3 baseCol, float lumVal, vec3 pt, float baseZ, float h0,
    float amount, float deep, float earthMask, float terrainWear, float isVacSnowLot, bool isGround,
    out float outEdge, out float outHitT, out float outHitS)
{
    outEdge = 0.0;
    outHitT = -1.0;
    outHitS = 0.0;
    float full = 0.055 * min(amount, 1.0) + 0.285 * deep;
    float top = full * 1.95;
    if (h0 >= top) return baseCol;
    if (!isGround) {
        float wall = max(nearIndoorWall(pt.xy, baseZ + 0.1, 0.42),
                     max(nearIndoorWall(pt.xy, baseZ + STORY_HEIGHT + 0.1, 0.42), nearIndoorWall(pt.xy, pt.z, 0.42)));
        if (wall >= 0.05) return baseCol;
    }
    float groundWear = (isGround && earthMask > 0.01) ? terrainWear : 0.0;
    int steps = amount > 1.0 ? 6 : 3;
    float dt = (top - h0) / 0.4 / float(steps);
    float hitT = -1.0, hitS = 0.0, nextS = -1.0;
    float prevDiff = 0.0, prevS = 0.0;
    bool hasPrev = false;
    for (int i = steps - 1; i >= 0; i--) {
        float t = float(i) * dt;
        float sh = snowHeight(pt.xy + 0.5 * t, baseZ, full, amount, groundWear, isVacSnowLot);
        float diff = sh - (h0 + 0.4 * t);
        if (diff > 0.0) {
            hitT = t;
            hitS = sh;
            if (hasPrev) {
                hitT += dt * diff / max(diff - prevDiff, 1e-4);
                nextS = prevS;
            }
            break;
        }
        prevDiff = diff;
        prevS = sh;
        hasPrev = true;
    }
    if (hitT < 0.0) return baseCol;
    vec2 q = pt.xy + 0.5 * hitT;
    float faceBlend = nextS >= 0.0
        ? smoothstep(1.8 * 0.4 * dt + 0.018, 1.8 * 0.4 * dt + 0.052, hitS - nextS)
        : 0.0;
    float e = 0.12;
    float s0 = h0 + 0.4 * hitT;
    float gx = (snowHeight(q + vec2(e, 0.0), baseZ, full, amount, groundWear, isVacSnowLot) - s0) / e;
    float gy = (snowHeight(q + vec2(0.0, e), baseZ, full, amount, groundWear, isVacSnowLot) - s0) / e;
    vec3 n2 = normalize(vec3(-gx, -gy, 1.0));
    vec3 sunDir = normalize(ambient.sunLot.xyz);
    float lit = clamp(1.0 + 1.05 * (dot(n2, sunDir) - sunDir.z), 0.72, 1.18);
    vec2 lq = lotSource(q);
    float qCrust = snowCrust(lq);
    float qSwell = valueNoise(lq * 0.26 + 9.0);
    float grainShade = (1.0 - qCrust) * mix(0.09, 0.04, deep) + (1.0 - smoothstep(0.2, 0.8, qSwell)) * 0.09;
    vec3 qSnow = mix(SNOW, SNOW_SHADE, clamp(grainShade, 0.0, 0.30));
    float under = isGround ? lumVal : 0.21;
    qSnow *= 1.0 + 0.32 * (1.0 - smoothstep(0.025, 0.10, hitS)) * (under - 0.26);
    float qPaved = isGround ? pavedAt(q) : 0.0;
    if (isGround && qPaved < 0.35 && isVacSnowLot > 0.35) {
        float qEarth = earthMask * (1.0 - cementAt(q));
        if (qEarth > 0.01) {
            float thinness = 1.0 - smoothstep(0.012, 0.10, hitS);
            float qBank = wallBank(q, baseZ);
            float patchDirt = smoothstep(0.56, 0.88, dirtField(lq)) * (1.0 - 0.80 * qBank);
            float rawDirt = max(terrainWear * 0.86, patchDirt * 0.10);
            float thinScale = mix(0.70 + 0.30 * thinness, 0.40 + 0.60 * thinness, 1.0 - terrainWear);
            float dirtMix = clamp(rawDirt * thinScale * (1.0 - qPaved) * qEarth, 0.0, 0.86);
            float dirtBlend = smoothstep(0.12, 0.82, dirtMix + (0.5 - qCrust) * 0.10) * isVacSnowLot;
            vec3 qDirt = mix(DIRT_DARK, DIRT_LIGHT, 0.35 + 0.55 * qCrust) * mix(0.82, 1.15, smoothstep(0.06, 0.22, lumVal));
            qDirt = mix(qDirt, srcCol, 0.65 * isVacSnowLot * smoothstep(0.10, 0.30, terrainWear));
            qSnow = mixPerceptual(qSnow, qDirt, dirtBlend);
        }
    }
    float pressed = pressedAt(q);
    if (pressed > 0.0) {
        vec2 toSun = normalize(ambient.sunLot.xy + vec2(1e-4)) * 0.03;
        float shaded = clamp(pressed - pressedAt(q + toSun), 0.0, 1.0);
        float facing2 = clamp(pressed - pressedAt(q - toSun), 0.0, 1.0);
        qSnow = mix(qSnow, SNOW_SHADE * 0.90, 0.28 * pressed) * (1.0 - 0.12 * shaded + 0.07 * facing2);
    }
    float daySun2 = max(0.0, 1.0 - ambient.weather.w);
    float qGlint = smoothstep(0.68, 0.94, valueNoise(lq * 24.0) * valueNoise(lq * 41.0 + 31.7)) * daySun2;
    qSnow += vec3(0.020, 0.024, 0.034) * qGlint;
    vec3 seen = mix(qSnow * lit, SNOW_SHADE * (0.90 + 0.08 * qCrust), faceBlend);
    float edge;
    if (isGround) {
        float pondWater = pondWaterOf(srcCol);
        float normSnow = hitS / 0.055;
        float notPaved = 1.0 - smoothstep(0.25, 0.65, qPaved);
        float tuft = valueNoise(lq * 22.0 + 4.1) * 0.65 + valueNoise(lq * 39.0 + 13.7) * 0.35;
        float grassBlade = greenOf(srcCol) * (1.0 - pondWater) * clamp(0.45 * smoothstep(0.04, 0.16, lumVal) + 0.55 * tuft, 0.0, 1.0);
        float dust = smoothstep(0.02, 0.30, normSnow)
                   * (1.0 - 0.48 * grassBlade * (1.0 - smoothstep(0.22, 0.62, normSnow)))
                   * notPaved;
        float blanket = smoothstep(0.22, 0.68, normSnow - 0.12 * grassBlade) * notPaved;
        edge = clamp(mix(0.42 * dust, 1.0, blanket), 0.0, 1.0);
    } else {
        edge = smoothstep(0.006, 0.024, hitS);
    }
    outEdge = edge;
    outHitT = hitT;
    outHitS = hitS;
    return mixPerceptual(baseCol, seen, edge);
}

float snowLuma(vec3 c) {
    return sqrt(max(dot(c, LUMA), 0.0));
}

float autumnEdgeMetric(vec3 c) {
    vec3 p = sqrt(max(c, vec3(0.0)));
    return dot(p, vec3(0.30, 0.56, 0.14)) + 0.36 * (p.r - p.b);
}

vec4 resolveWinterPixel(ivec2 ip, ivec2 maxI, bool hasSpriteLayer) {
    ip = clamp(ip, ivec2(0), maxI);
    vec3 pre = texelFetch(source, ip, 0).rgb;
    vec4 stLift = texelFetch(trailMap, ip, 0);
    vec3 orig = texelFetch(overheadMap, ip, 0).rgb;
    float capCover = stLift.z < -0.002 ? -stLift.z : 0.0;
    float snowAct = stLift.z > 0.5 ? 1.0 : capCover;
    if (ambient.view.z >= 1.35 && stLift.z < -0.0005) {
        float dC = texelFetch(depthMap, ip, 0).r;
        float dTol = mix(0.0014, 0.0045, clamp(stLift.x, 0.0, 1.0));
        const ivec2 CARD[4] = ivec2[4](ivec2(-1, 0), ivec2(1, 0), ivec2(0, -1), ivec2(0, 1));
        vec3 accCol = pre * 0.70;
        float accCov = capCover * 0.70;
        float accW = 0.70;
        for (int k = 0; k < 4; k++) {
            ivec2 np = clamp(ip + CARD[k], ivec2(0), maxI);
            vec4 nLift = texelFetch(trailMap, np, 0);
            if (nLift.z >= -0.0005) continue;
            float nCov = nLift.z < -0.002 ? -nLift.z : 0.0;
            float pairSnow = max(capCover, nCov);
            if (pairSnow < 0.04) continue;
            float dN = texelFetch(depthMap, np, 0).r;
            float dzW = 1.0 - smoothstep(0.65 * dTol, dTol, abs(dN - dC));
            float matW = 1.0 - smoothstep(0.25, 0.60, abs(nLift.x - stLift.x));
            float w = 0.075 * dzW * matW * smoothstep(0.04, 0.20, pairSnow);
            if (w <= 1e-4) continue;
            accCol += w * texelFetch(source, np, 0).rgb;
            accCov += w * nCov;
            accW += w;
        }
        pre = accCol / accW;
        snowAct = max(snowAct, accCov / accW);
    } else if (hasSpriteLayer && stLift.z >= -0.0005) {
        vec4 sp = texelFetch(spriteMap, ip, 0);
        if (sp.a > 0.004 && sp.a < 0.99) {
            vec3 F = clamp(sp.rgb / sp.a, vec3(0.0), vec3(1.0));
            float fFol = foliageOf(F);
            float fBlos = smoothstep(0.08, 0.16, F.b) * smoothstep(0.68, 0.92, F.b / max(F.g, 0.02));
            float fPlant = clamp(max(fFol, fBlos), 0.0, 1.0);
            bool hasDrift = stLift.z > 0.5;
            float driftH = hasDrift ? stLift.y : -1.0;
            float coreW = 0.0;
            float snowCovSum = 0.0;
            vec3 snowColSum = vec3(0.0);
            for (int oy = -2; oy <= 2; oy++) {
                for (int ox = -2; ox <= 2; ox++) {
                    int r2 = ox * ox + oy * oy;
                    if (r2 == 0 || r2 > 5) continue;
                    ivec2 np = clamp(ip + ivec2(ox, oy), ivec2(0), maxI);
                    vec4 nLift = texelFetch(trailMap, np, 0);
                    if (nLift.z >= -0.0005) continue;
                    if (hasDrift && nLift.y <= driftH + 0.06) continue;
                    float w = r2 == 1 ? 2.0 : (r2 == 2 ? 1.2 : (r2 == 4 ? 0.55 : 0.35));
                    float matW = nLift.x > 0.30
                        ? smoothstep(0.05, 0.25, fPlant)
                        : (r2 <= 2 ? 1.0 - smoothstep(0.20, 0.50, fFol) : 0.0);
                    float cw = w * matW;
                    if (cw <= 1e-4) continue;
                    coreW += cw;
                    if (nLift.z < -0.002) {
                        float nc = -nLift.z;
                        vec3 nCol = texelFetch(source, np, 0).rgb;
                        snowCovSum += cw * nc;
                        snowColSum += cw * nc * nCol;
                    }
                }
            }
            if (coreW > 1e-4 && (snowCovSum > 1e-4 || hasDrift || stLift.x > 0.5)) {
                float avgCov = clamp(snowCovSum / coreW, 0.0, 1.0);
                vec3 B_winter = (hasDrift || stLift.x > 0.5) ? pre : clamp((orig - sp.rgb) / max(1.0 - sp.a, 0.02), vec3(0.0), vec3(1.0));
                vec3 F_dull = mix(F, recolor(F, vec3(0.30, 0.42, 0.36)), 0.38 * greenOf(F) * smoothstep(0.0, 0.35, ambient.season.y));
                vec3 F_snow = avgCov > 0.005 ? mix(F_dull, snowColSum / max(snowCovSum, 1e-4), avgCov) : F_dull;
                pre = sp.a * F_snow + (1.0 - sp.a) * B_winter;
                snowAct = hasDrift ? 1.0 : max(snowAct, sp.a * avgCov);
            }
        }
    }
    snowAct = max(snowAct, smoothstep(0.025, 0.14, length(pre - orig)));
    return vec4(pre, clamp(snowAct, 0.0, 1.0));
}

void main() {
    vec2 pixel = floor(gl_FragCoord.xy) + 0.5;
    color = vec4(0.0);
    lift = vec4(0.0);
    if (pixel.x >= ambient.extent.x || pixel.y >= ambient.extent.y) return;
    if (ambient.season.x >= 0.5 && ambient.season.x < 1.5 && ambient.seasonExtra2.w > 0.5) {
        ivec2 ip = ivec2(floor(gl_FragCoord.xy));
        ivec2 maxI = max(ivec2(ambient.extent.xy) - 1, ivec2(0));
        vec3 cM = texelFetch(source, ip, 0).rgb;
        vec3 origM = texelFetch(overheadMap, ip, 0).rgb;
        bool isSim = textureSize(simMap, 0).x > 1 && texelFetch(simMap, ip, 0).r > 0.5;
        if (isSim) {
            if (all(lessThan(abs(cM - origM), vec3(1e-4)))) return;
            color = vec4(cM, 1.0);
            return;
        }
        float fM = texelFetch(trailMap, ip, 0).x;
        float fN = texelFetch(trailMap, clamp(ip + ivec2(0, -1), ivec2(0), maxI), 0).x;
        float fS = texelFetch(trailMap, clamp(ip + ivec2(0,  1), ivec2(0), maxI), 0).x;
        float fW = texelFetch(trailMap, clamp(ip + ivec2(-1, 0), ivec2(0), maxI), 0).x;
        float fE = texelFetch(trailMap, clamp(ip + ivec2( 1, 0), ivec2(0), maxI), 0).x;
        float fNW = texelFetch(trailMap, clamp(ip + ivec2(-1, -1), ivec2(0), maxI), 0).x;
        float fNE = texelFetch(trailMap, clamp(ip + ivec2( 1, -1), ivec2(0), maxI), 0).x;
        float fSW = texelFetch(trailMap, clamp(ip + ivec2(-1,  1), ivec2(0), maxI), 0).x;
        float fSE = texelFetch(trailMap, clamp(ip + ivec2( 1,  1), ivec2(0), maxI), 0).x;
        float fMax = max(fM, max(max(max(fN, fS), max(fE, fW)), max(max(fNW, fNE), max(fSW, fSE))));
        if (fMax < 0.03) {
            if (all(lessThan(abs(cM - origM), vec3(1e-4)))) return;
            color = vec4(cM, 1.0);
            return;
        }
        vec3 cN = texelFetch(source, clamp(ip + ivec2(0, -1), ivec2(0), maxI), 0).rgb;
        vec3 cS = texelFetch(source, clamp(ip + ivec2(0,  1), ivec2(0), maxI), 0).rgb;
        vec3 cW = texelFetch(source, clamp(ip + ivec2(-1, 0), ivec2(0), maxI), 0).rgb;
        vec3 cE = texelFetch(source, clamp(ip + ivec2( 1, 0), ivec2(0), maxI), 0).rgb;
        vec3 cNW = texelFetch(source, clamp(ip + ivec2(-1, -1), ivec2(0), maxI), 0).rgb;
        vec3 cNE = texelFetch(source, clamp(ip + ivec2( 1, -1), ivec2(0), maxI), 0).rgb;
        vec3 cSW = texelFetch(source, clamp(ip + ivec2(-1,  1), ivec2(0), maxI), 0).rgb;
        vec3 cSE = texelFetch(source, clamp(ip + ivec2( 1,  1), ivec2(0), maxI), 0).rgb;
        float lM = autumnEdgeMetric(cM);
        float lN = autumnEdgeMetric(cN);
        float lS = autumnEdgeMetric(cS);
        float lW = autumnEdgeMetric(cW);
        float lE = autumnEdgeMetric(cE);
        float lNW = autumnEdgeMetric(cNW);
        float lNE = autumnEdgeMetric(cNE);
        float lSW = autumnEdgeMetric(cSW);
        float lSE = autumnEdgeMetric(cSE);
        float lMin = min(lM, min(min(lN, lS), min(lE, lW)));
        float lMax = max(lM, max(max(lN, lS), max(lE, lW)));
        float lRange = lMax - lMin;
        if (lRange < max(0.030, abs(lMax) * 0.055)) {
            if (all(lessThan(abs(cM - origM), vec3(1e-4)))) return;
            color = vec4(cM, 1.0);
            return;
        }
        float edgeHorz = abs(-2.0 * lW + lNW + lSW) + 2.0 * abs(-2.0 * lM + lN + lS) + abs(-2.0 * lE + lNE + lSE);
        float edgeVert = abs(-2.0 * lN + lNW + lNE) + 2.0 * abs(-2.0 * lM + lW + lE) + abs(-2.0 * lS + lSW + lSE);
        bool isHorz = edgeHorz >= edgeVert;
        float l1 = isHorz ? lN : lW;
        float l2 = isHorz ? lS : lE;
        float g1 = abs(l1 - lM);
        float g2 = abs(l2 - lM);
        bool is1Steeper = g1 >= g2;
        float gradScaled = 0.24 * max(g1, g2);
        ivec2 stepPerp = isHorz ? ivec2(0, is1Steeper ? -1 : 1) : ivec2(is1Steeper ? -1 : 1, 0);
        ivec2 stepTan = isHorz ? ivec2(1, 0) : ivec2(0, 1);
        float lAvg = 0.5 * (lM + (is1Steeper ? l1 : l2));
        float lEndN = lAvg, lEndP = lAvg;
        bool doneN = false, doneP = false;
        int distN = 7, distP = 7;
        for (int s = 1; s <= 6; s++) {
            if (!doneN) {
                ivec2 pN = clamp(ip - stepTan * s, ivec2(0), maxI);
                ivec2 pNp = clamp(pN + stepPerp, ivec2(0), maxI);
                float aN = 0.5 * (autumnEdgeMetric(texelFetch(source, pN, 0).rgb) + autumnEdgeMetric(texelFetch(source, pNp, 0).rgb));
                lEndN = aN - lAvg;
                if (abs(lEndN) >= gradScaled) { doneN = true; distN = s; }
            }
            if (!doneP) {
                ivec2 pP = clamp(ip + stepTan * s, ivec2(0), maxI);
                ivec2 pPp = clamp(pP + stepPerp, ivec2(0), maxI);
                float aP = 0.5 * (autumnEdgeMetric(texelFetch(source, pP, 0).rgb) + autumnEdgeMetric(texelFetch(source, pPp, 0).rgb));
                lEndP = aP - lAvg;
                if (abs(lEndP) >= gradScaled) { doneP = true; distP = s; }
            }
            if (doneN && doneP) break;
        }
        float dMin = float(min(distN, distP));
        float spanLen = float(distN + distP);
        bool goodSpan = ((distN <= distP ? lEndN : lEndP) < 0.0) != (lM < lAvg);
        float edgeBlend = goodSpan ? max(0.0, 0.5 - dMin / spanLen) : 0.0;
        float avg9 = (2.0 * (lN + lS + lE + lW) + lNW + lNE + lSW + lSE) / 12.0;
        float subpix = clamp(abs(avg9 - lM) / max(lRange, 1e-4), 0.0, 1.0);
        subpix = smoothstep(0.0, 1.0, subpix);
        float subpixAA = 0.58 * subpix * subpix;
        ivec2 perpPx = clamp(ip + stepPerp, ivec2(0), maxI);
        bool perpSim = textureSize(simMap, 0).x > 1 && texelFetch(simMap, perpPx, 0).r > 0.5;
        float finalBlend = perpSim ? 0.0 : max(edgeBlend, subpixAA) * smoothstep(0.03, 0.16, fMax);
        vec3 perpCol = stepPerp.y < 0 ? cN : (stepPerp.y > 0 ? cS : (stepPerp.x < 0 ? cW : cE));
        float fMinCard = min(fM, min(min(fN, fS), min(fE, fW)));
        vec3 cardSqrt = 0.25 * (sqrt(max(cN, vec3(0.0))) + sqrt(max(cS, vec3(0.0))) + sqrt(max(cW, vec3(0.0))) + sqrt(max(cE, vec3(0.0))));
        vec3 targetCol = fMinCard > 0.45 ? mixPerceptual(cardSqrt * cardSqrt, perpCol, clamp(edgeBlend * 2.0, 0.0, 1.0)) : perpCol;
        vec3 aaCol = mixPerceptual(cM, targetCol, clamp(finalBlend, 0.0, 0.68));
        if (all(lessThan(abs(aaCol - origM), vec3(1e-4)))) return;
        color = vec4(aaCol, 1.0);
        return;
    }
    if (ambient.season.x >= 1.5 && ambient.seasonExtra2.w > 0.5) {
        ivec2 ip = ivec2(floor(gl_FragCoord.xy));
        ivec2 maxI = max(ivec2(ambient.extent.xy) - 1, ivec2(0));
        vec4 stLift = texelFetch(trailMap, ip, 0);
        lift = stLift.z > 0.5 ? stLift : vec4(0.0, 0.0, stLift.z < -0.002 ? stLift.z : 0.0, stLift.w);
        bool hasSpriteLayer = textureSize(spriteMap, 0).x > 4;
        vec4 cM = resolveWinterPixel(ip, maxI, hasSpriteLayer);
        vec3 origM = texelFetch(overheadMap, ip, 0).rgb;
        bool isSim = textureSize(simMap, 0).x > 1 && texelFetch(simMap, ip, 0).r > 0.5;
        if (isSim) {
            if (all(lessThan(abs(cM.rgb - origM), vec3(1e-4)))) return;
            color = vec4(cM.rgb, 1.0);
            return;
        }
        vec4 cN = resolveWinterPixel(ip + ivec2(0, -1), maxI, hasSpriteLayer);
        vec4 cS = resolveWinterPixel(ip + ivec2(0,  1), maxI, hasSpriteLayer);
        vec4 cW = resolveWinterPixel(ip + ivec2(-1, 0), maxI, hasSpriteLayer);
        vec4 cE = resolveWinterPixel(ip + ivec2( 1, 0), maxI, hasSpriteLayer);
        vec4 cNW = resolveWinterPixel(ip + ivec2(-1, -1), maxI, hasSpriteLayer);
        vec4 cNE = resolveWinterPixel(ip + ivec2( 1, -1), maxI, hasSpriteLayer);
        vec4 cSW = resolveWinterPixel(ip + ivec2(-1,  1), maxI, hasSpriteLayer);
        vec4 cSE = resolveWinterPixel(ip + ivec2( 1,  1), maxI, hasSpriteLayer);
        float sMax = max(cM.a, max(max(max(cN.a, cS.a), max(cE.a, cW.a)), max(max(cNW.a, cNE.a), max(cSW.a, cSE.a))));
        if (sMax < 0.03) {
            if (all(lessThan(abs(cM.rgb - origM), vec3(1e-4)))) return;
            color = vec4(cM.rgb, 1.0);
            return;
        }
        float lM = snowLuma(cM.rgb);
        float lN = snowLuma(cN.rgb);
        float lS = snowLuma(cS.rgb);
        float lW = snowLuma(cW.rgb);
        float lE = snowLuma(cE.rgb);
        float lNW = snowLuma(cNW.rgb);
        float lNE = snowLuma(cNE.rgb);
        float lSW = snowLuma(cSW.rgb);
        float lSE = snowLuma(cSE.rgb);
        float lMin = min(lM, min(min(lN, lS), min(lE, lW)));
        float lMax = max(lM, max(max(lN, lS), max(lE, lW)));
        float lRange = lMax - lMin;
        if (lRange < max(0.035, lMax * 0.065) || sMax < 0.04) {
            color = vec4(cM.rgb, 1.0);
            return;
        }
        float edgeHorz = abs(-2.0 * lW + lNW + lSW) + 2.0 * abs(-2.0 * lM + lN + lS) + abs(-2.0 * lE + lNE + lSE);
        float edgeVert = abs(-2.0 * lN + lNW + lNE) + 2.0 * abs(-2.0 * lM + lW + lE) + abs(-2.0 * lS + lSW + lSE);
        bool isHorz = edgeHorz >= edgeVert;
        float l1 = isHorz ? lN : lW;
        float l2 = isHorz ? lS : lE;
        float g1 = abs(l1 - lM);
        float g2 = abs(l2 - lM);
        bool is1Steeper = g1 >= g2;
        float gradScaled = 0.25 * max(g1, g2);
        ivec2 stepPerp = isHorz ? ivec2(0, is1Steeper ? -1 : 1) : ivec2(is1Steeper ? -1 : 1, 0);
        ivec2 stepTan = isHorz ? ivec2(1, 0) : ivec2(0, 1);
        float lAvg = 0.5 * (lM + (is1Steeper ? l1 : l2));
        float lEndN = lAvg, lEndP = lAvg;
        bool doneN = false, doneP = false;
        int distN = 7, distP = 7;
        for (int s = 1; s <= 6; s++) {
            if (!doneN) {
                ivec2 pN = ip - stepTan * s;
                float aN = 0.5 * (snowLuma(resolveWinterPixel(pN, maxI, hasSpriteLayer).rgb)
                                + snowLuma(resolveWinterPixel(pN + stepPerp, maxI, hasSpriteLayer).rgb));
                lEndN = aN - lAvg;
                if (abs(lEndN) >= gradScaled) { doneN = true; distN = s; }
            }
            if (!doneP) {
                ivec2 pP = ip + stepTan * s;
                float aP = 0.5 * (snowLuma(resolveWinterPixel(pP, maxI, hasSpriteLayer).rgb)
                                + snowLuma(resolveWinterPixel(pP + stepPerp, maxI, hasSpriteLayer).rgb));
                lEndP = aP - lAvg;
                if (abs(lEndP) >= gradScaled) { doneN = doneN; doneP = true; distP = s; }
            }
            if (doneN && doneP) break;
        }
        float dMin = float(min(distN, distP));
        float spanLen = float(distN + distP);
        bool goodSpan = ((distN <= distP ? lEndN : lEndP) < 0.0) != (lM < lAvg);
        float edgeBlend = goodSpan ? max(0.0, 0.5 - dMin / spanLen) : 0.0;
        float avg9 = (2.0 * (lN + lS + lE + lW) + lNW + lNE + lSW + lSE) / 12.0;
        float subpix = clamp(abs(avg9 - lM) / max(lRange, 1e-4), 0.0, 1.0);
        subpix = smoothstep(0.0, 1.0, subpix);
        float subpixAA = 0.65 * subpix * subpix;
        ivec2 perpPx = clamp(ip + stepPerp, ivec2(0), maxI);
        bool perpSim = textureSize(simMap, 0).x > 1 && texelFetch(simMap, perpPx, 0).r > 0.5;
        float finalBlend = perpSim ? 0.0 : max(edgeBlend, subpixAA) * smoothstep(0.04, 0.18, sMax);
        vec3 perpCol = stepPerp.y < 0 ? cN.rgb : (stepPerp.y > 0 ? cS.rgb : (stepPerp.x < 0 ? cW.rgb : cE.rgb));
        color = vec4(mixPerceptual(cM.rgb, perpCol, clamp(finalBlend, 0.0, 0.72)), 1.0);
        return;
    }
    vec4 centre = positionAt(pixel);
    if (centre.w > 0.75) return;
    vec3 src = texelFetch(source, ivec2(pixel), 0).rgb;
    bool ground = centre.w > 0.25;
    bool mapped = ambient.sunLot.w > 0.0;
    float key = ground ? (0.62 - texelFetch(groundMap, ivec2(pixel), 0).r) / 0.003 + ambient.view.w
                       : (0.62 - texelFetch(depthMap, ivec2(pixel), 0).r) / 0.003;
    vec3 here = lotPoint(centre.xy, key, ground, ambient.frame.xy);
    float outdoor = mapped ? 1.0 - indoors(here) : 1.0;
    // Something rising out of a room up to an open floor above (the top of a staircase) is still indoors: a sprite
    // is judged a quarter tile under its surface, where a deck chair is still on its deck.
    if (mapped && !ground) outdoor = min(outdoor, 1.0 - indoors(here - vec3(0.0, 0.0, 0.25)));
    // Sky exposure is evaluated independently of season so covered porch/gazebo pixels remain invariant across seasons.
    // For elevated non-ground surfaces (like pitched roofs), test slightly above the surface so a roof does not mask itself.
    float skyExposed = mapped ? architecturalExposure(ground ? here : here + vec3(0.0, 0.0, 0.45)) : 1.0;
    if (outdoor <= 0.0) return;
    vec2 lot = lotSource(here.xy);  // fixed to the lot, so the pattern stays put when the camera turns
    float lotPixelScale = max(length(fwidth(lot)), 0.002);
    float amount = ambient.season.y;
    float springBloom = clamp(ambient.seasonExtra.y, 0.0, 1.0);
    float frost = clamp(ambient.seasonExtra2.y, 0.0, 1.0);
    float lum = dot(src, LUMA);
    float srcPondBlue = ground ? pondWaterOf(src) : 0.0;
    float green = smoothstep(0.06, 0.22, (src.g - max(src.r, src.b)) / max(src.g, 0.04)) * (1.0 - srcPondBlue);
    // What stands over the point, and whether a tree's canopy is near (for the fallen leaves).
    float over = mapped ? topAt(here.xy) - here.z : 0.0;
    float covered = smoothstep(0.3, 0.9, over);
    if (mapped && ambient.season.x > 1.5) {
        // The height map steps tile by tile, so the cover is averaged around the point to keep its edge soft.
        for (int i = 0; i < 4; i++) {
            vec2 offset = 0.35 * vec2(i == 0 ? 1.0 : i == 1 ? -1.0 : 0.0, i == 2 ? 1.0 : i == 3 ? -1.0 : 0.0);
            covered += smoothstep(0.3, 0.9, topAt(here.xy + offset) - here.z);
        }
        covered /= 5.0;
    }
    vec3 result = src;
    bool sim = textureSize(simMap, 0).x > 1 && texelFetch(simMap, ivec2(pixel), 0).r > 0.5;
    bool hasInFloraMap = mapped && textureSize(trailMap, 0).x > 4
                      && abs(texelFetch(trailMap, ivec2(0, 0), 0).a - 0.5) < 0.18;
    bool hasOutFloraMap = mapped && ambient.prevView.w > 0.5 && ambient.prevView.x > 0.0
                       && textureSize(outFloraMap, 0).x > 4;
    bool hasLiveFloraMap = hasInFloraMap || hasOutFloraMap;

    if (ambient.season.x < 0.5) {
        if (springBloom > 0.01 && skyExposed > 0.001 && ground && green > 0.05) {
            result = mix(src, recolor(src, srgbToLinear(vec3(0.34, 0.45, 0.18))), green * skyExposed * springBloom * 0.18);
        }
        if (frost > 0.02 && skyExposed > 0.001 && !sim && green > 0.05) {
            float rime = smoothstep(0.35, 0.82, valueNoise(lot * 6.0) * 0.55 + valueNoise(lot * 19.0 + 7.1) * 0.45);
            vec3 frostTint = srgbToLinear(vec3(0.78, 0.86, 0.95)) * clamp(lum / 0.12, 0.35, 1.25);
            result = mix(result, frostTint, frost * rime * green * skyExposed * (ground ? 0.34 : 0.22));
        }
        if (ambient.params.y < 0.01 && ambient.season.x < 1.5 && skyExposed > 0.001) {
            float overcastDim = 1.0 - 0.24 * clamp(ambient.clouds.x, 0.0, 1.0) - 0.12 * clamp(ambient.weather.x, 0.0, 1.0);
            float wetDark = 1.0 - 0.22 * clamp(ambient.weather.y, 0.0, 1.0) * (ground ? 1.0 : 0.55);
            result *= mix(1.0, overcastDim * wetDark, skyExposed);
        }
        if (all(lessThan(abs(result - src), vec3(1e-4)))) return;
    } else if (ambient.season.x < 1.5) {
        bool hasSpriteLayer = textureSize(spriteMap, 0).x > 4;
        vec4 sp = hasSpriteLayer ? texelFetch(spriteMap, ivec2(pixel), 0) : vec4(0.0);
        float folAct = 0.0;
        if (!ground) {
            float autGroundAlt = mapped ? groundAt(pixel) : -1.0e5;
            float autFallbackBase = autGroundAlt > -1.0e4
                ? lotPoint(centre.xy, autGroundAlt / DEPTH_UNIT, true, ambient.frame.xy).z
                : terrainBaseClamped(here.xy, ambient.contact.w);
            if (hasSpriteLayer && sp.a > 0.002 && sp.a < 0.99) {
                vec3 F = clamp(sp.rgb / sp.a, vec3(0.0), vec3(1.0));
                vec3 B = clamp((src - sp.rgb) / max(1.0 - sp.a, 0.02), vec3(0.0), vec3(1.0));
                vec3 F_aut = applyAutumnFoliage(F, here, autFallbackBase, lot, amount, outdoor, sim, mapped, hasLiveFloraMap, folAct);
                folAct *= smoothstep(0.02, 0.25, sp.a);
                vec3 B_aut = B;
                float gDepth = texelFetch(groundMap, ivec2(pixel), 0).r;
                if (!sim && gDepth < 1.0) {
                    float gKey = (0.62 - gDepth) / 0.003 + ambient.view.w;
                    vec3 hereG = lotPoint(centre.xy, gKey, true, ambient.frame.xy);
                    float gOutdoor = mapped ? 1.0 - indoors(hereG) : 1.0;
                    if (gOutdoor > 0.0) {
                        float gSkyExposed = mapped ? architecturalExposure(hereG) : 1.0;
                        vec2 gLot = lotSource(hereG.xy);
                        float gPixelScale = max(1.0 / (36.0 * max(ambient.view.z, 0.12)), 0.002);
                        B_aut = applyAutumnGround(B, hereG, gLot, gPixelScale, amount, gOutdoor, gSkyExposed, mapped, hasLiveFloraMap, true);
                    }
                }
                result = sp.a * F_aut + (1.0 - sp.a) * B_aut;
            } else {
                vec3 F = (hasSpriteLayer && sp.a >= 0.99) ? clamp(sp.rgb / sp.a, vec3(0.0), vec3(1.0)) : src;
                result = applyAutumnFoliage(F, here, autFallbackBase, lot, amount, outdoor, sim, mapped, hasLiveFloraMap, folAct);
            }
            if (!sim && folAct > 0.01) {
                lift = vec4(clamp(folAct, 0.0, 1.0), 0.0, 0.0, 0.0);
            }
        } else {
            result = applyAutumnGround(src, here, lot, lotPixelScale, amount, outdoor, skyExposed, mapped, hasLiveFloraMap, false);
        }
        if (frost > 0.02 && skyExposed > 0.001 && !sim && (ground || green > 0.05)) {
            float rime = smoothstep(0.38, 0.84, valueNoise(lot * 6.0) * 0.55 + valueNoise(lot * 19.0 + 7.1) * 0.45);
            float mask = ground ? (1.0 - 0.85 * pavedAt(here.xy)) : green;
            vec3 frostTint = srgbToLinear(vec3(0.78, 0.86, 0.95)) * clamp(lum / 0.12, 0.35, 1.25);
            result = mix(result, frostTint, frost * rime * mask * skyExposed * (ground ? 0.30 : 0.20));
        }
    } else {
        float winterOutdoor = min(outdoor, skyExposed);
        if (mapped) winterOutdoor *= 1.0 - smoothstep(0.32, 0.48, indoors(here));
        if (winterOutdoor > 0.0) {
            bool hasSpriteLayer = textureSize(spriteMap, 0).x > 4;
            vec4 sp = hasSpriteLayer ? texelFetch(spriteMap, ivec2(pixel), 0) : vec4(0.0);
            bool hasPartialSprite = hasSpriteLayer && sp.a > 0.004 && sp.a < 0.99;
            vec3 spriteB = hasPartialSprite ? clamp((src - sp.rgb) / max(1.0 - sp.a, 0.02), vec3(0.0), vec3(1.0)) : src;
            vec3 spriteF = hasPartialSprite ? clamp(sp.rgb / sp.a, vec3(0.0), vec3(1.0)) : src;
            vec3 workSrc = (ground && hasPartialSprite) ? spriteB : ((!ground && hasPartialSprite) ? spriteF : src);
            float vacLot = 1.0 - smoothstep(0.25, 0.75, ambient.seasonExtra.x);
            float isVacSnowLot, earthMask, terrainWear, workGreen, workLum;
            evalGroundTerms(workSrc, here.xy, ground ? 1.0 : 0.0, vacLot, isVacSnowLot, earthMask, terrainWear, workGreen, workLum);
            float hereCrust = snowCrust(lot);
            vec3 dull = sim ? workSrc : winterDullColor(workSrc, here, lot, workLum, workGreen, hereCrust, earthMask, terrainWear, isVacSnowLot, covered, ground, amount);
            float deep = clamp(amount - 1.0, 0.0, 1.0);
            float poolWater = 0.0;
            if (!sim && (!ground || !mapped)) {
                vec2 maxIdx = ambient.extent.xy - 1.0;
                float facing = 1.0;
                if (!ground) {
                    vec3 p = centre.xyz;
                    float s1 = max(2.0, 2.0 * ambient.view.z);
                    float s2 = s1 * 2.0;
                    float wxSum = 0.0, wySum = 0.0;
                    vec3 dxAcc = vec3(0.0), dyAcc = vec3(0.0);
                    bool lOk1 = false, rOk1 = false, uOk1 = false, dOk1 = false;
                    for (int r = 0; r < 2; r++) {
                        float st = r == 0 ? s1 : s2;
                        float w = r == 0 ? 0.60 : 0.40;
                        vec2 lPx = floor(clamp(pixel - vec2(st, 0.0), vec2(0.0), maxIdx)) + 0.5;
                        vec2 rPx = floor(clamp(pixel + vec2(st, 0.0), vec2(0.0), maxIdx)) + 0.5;
                        vec4 ql = positionAt(lPx);
                        vec4 qr = positionAt(rPx);
                        float dxl = abs(p.x - ql.x);
                        float dxr = abs(qr.x - p.x);
                        bool lOk = ql.w < 0.25 && dxl > 0.25 && abs(ql.z - p.z) < 1.6 * dxl + 4.5;
                        bool rOk = qr.w < 0.25 && dxr > 0.25 && abs(qr.z - p.z) < 1.6 * dxr + 4.5;
                        if (workGreen < 0.15) {
                            if (lOk && greenOf(texelFetch(source, ivec2(lPx), 0).rgb) > 0.35) lOk = false;
                            if (rOk && greenOf(texelFetch(source, ivec2(rPx), 0).rgb) > 0.35) rOk = false;
                            if (r == 0) {
                                if (lOk) {
                                    vec2 mPx = floor(clamp(pixel - vec2(0.5 * st, 0.0), vec2(0.0), maxIdx)) + 0.5;
                                    vec4 qm = positionAt(mPx);
                                    if (qm.w >= 0.25 || abs(qm.z - p.z) >= 1.6 * abs(p.x - qm.x) + 4.5 || greenOf(texelFetch(source, ivec2(mPx), 0).rgb) > 0.35) lOk = false;
                                }
                                if (rOk) {
                                    vec2 mPx = floor(clamp(pixel + vec2(0.5 * st, 0.0), vec2(0.0), maxIdx)) + 0.5;
                                    vec4 qm = positionAt(mPx);
                                    if (qm.w >= 0.25 || abs(qm.z - p.z) >= 1.6 * abs(qm.x - p.x) + 4.5 || greenOf(texelFetch(source, ivec2(mPx), 0).rgb) > 0.35) rOk = false;
                                }
                            } else {
                                lOk = lOk && lOk1;
                                rOk = rOk && rOk1;
                            }
                        }
                        if (r == 0) { lOk1 = lOk; rOk1 = rOk; }
                        if (lOk && rOk) { dxAcc += (qr.xyz - ql.xyz) * (0.5 * w); wxSum += w; }
                        else if (rOk)   { dxAcc += (qr.xyz - p) * w;              wxSum += w; }
                        else if (lOk)   { dxAcc += (p - ql.xyz) * w;              wxSum += w; }

                        vec2 uPx = floor(clamp(pixel - vec2(0.0, st), vec2(0.0), maxIdx)) + 0.5;
                        vec2 dPx = floor(clamp(pixel + vec2(0.0, st), vec2(0.0), maxIdx)) + 0.5;
                        vec4 qu = positionAt(uPx);
                        vec4 qd = positionAt(dPx);
                        float dyu = abs(p.y - qu.y);
                        float dyd = abs(qd.y - p.y);
                        bool uOk = qu.w < 0.25 && dyu > 0.25 && abs(qu.z - p.z) < 2.2 * dyu + 4.5;
                        bool dOk = qd.w < 0.25 && dyd > 0.25 && abs(qd.z - p.z) < 2.2 * dyd + 4.5;
                        if (workGreen < 0.15) {
                            if (uOk && greenOf(texelFetch(source, ivec2(uPx), 0).rgb) > 0.35) uOk = false;
                            if (dOk && greenOf(texelFetch(source, ivec2(dPx), 0).rgb) > 0.35) dOk = false;
                            if (r == 0) {
                                if (uOk) {
                                    vec2 mPx = floor(clamp(pixel - vec2(0.0, 0.5 * st), vec2(0.0), maxIdx)) + 0.5;
                                    vec4 qm = positionAt(mPx);
                                    if (qm.w >= 0.25 || abs(qm.z - p.z) >= 2.2 * abs(p.y - qm.y) + 4.5 || greenOf(texelFetch(source, ivec2(mPx), 0).rgb) > 0.35) uOk = false;
                                }
                                if (dOk) {
                                    vec2 mPx = floor(clamp(pixel + vec2(0.0, 0.5 * st), vec2(0.0), maxIdx)) + 0.5;
                                    vec4 qm = positionAt(mPx);
                                    if (qm.w >= 0.25 || abs(qm.z - p.z) >= 2.2 * abs(qm.y - p.y) + 4.5 || greenOf(texelFetch(source, ivec2(mPx), 0).rgb) > 0.35) dOk = false;
                                }
                            } else {
                                uOk = uOk && uOk1;
                                dOk = dOk && dOk1;
                            }
                        }
                        if (r == 0) { uOk1 = uOk; dOk1 = dOk; }
                        if (uOk && dOk) { dyAcc += (qd.xyz - qu.xyz) * (0.5 * w); wySum += w; }
                        else if (dOk)   { dyAcc += (qd.xyz - p) * w;              wySum += w; }
                        else if (uOk)   { dyAcc += (p - qu.xyz) * w;              wySum += w; }
                    }
                    facing = 0.0;
                    if (wxSum > 0.0 && wySum > 0.0) {
                        vec3 dx = dxAcc / wxSum;
                        vec3 dy = dyAcc / wySum;
                        vec3 cr = cross(dy, dx);
                        float crLen = length(cr);
                        if (crLen > 1e-5) {
                            vec3 n = cr / crLen;
                            if (n.z < 0.0) n = -n;
                            facing = clamp(dot(n, WORLD_UP), 0.0, 1.0);
                        }
                    }
                }
                float macroWind = valueNoise(lot * 0.18 + 4.3) * 0.74 + valueNoise(lot * 0.42 + 13.1) * 0.26;
                float effDepth = max(0.0, amount * (1.0 - 0.32 * covered) + (macroWind - 0.5) * 0.05 * smoothstep(0.0, 0.16, amount));
                float lying = clamp(mix(0.45 * smoothstep(0.012, 0.28, effDepth), 1.0, smoothstep(0.20, 0.68, effDepth)), 0.0, 1.0);
                float baseAlt = mapped ? groundAt(pixel) : -1.0e5;
                float groundFallback = baseAlt > -1.0e4 ? lotPoint(centre.xy, baseAlt / DEPTH_UNIT, true, ambient.frame.xy).z : ambient.contact.w;
                float roofBase = mapped ? terrainBaseAt(here.xy, groundFallback) : groundFallback;
                float relZ = mapped ? here.z - roofBase : 0.0;
                int roofWedges = 0;
                float bestRoofFacing = 0.0;
                if (!ground && mapped && relZ > STORY_HEIGHT + 0.08 && workGreen < 0.35) {
                    vec3 p0 = centre.xyz;
                    vec2 maxPx = ambient.extent.xy - 0.5;
                    float rP = max(3.0, 6.5 * ambient.view.z);
                    float wP = max(1.2, 1.5 * ambient.view.z);
                    float planeTol = clamp(0.32 / max(ambient.view.z, 0.25), 0.32, 1.15);
                    for (int i = 0; i < 12; i++) {
                        vec2 dir;
                        if (i < 8) {
                            float a = float(i) * 0.7853982;
                            dir = vec2(cos(a), sin(a));
                        } else {
                            float sx = (i == 8 || i == 9) ? 0.8944272 : -0.8944272;
                            float sy = (i == 8 || i == 10) ? 0.4472136 : -0.4472136;
                            dir = vec2(sx, sy);
                        }
                        vec2 perp = vec2(-dir.y, dir.x);
                        vec2 pML = clamp(floor(pixel + dir * (0.5 * rP) + perp * (0.5 * wP)) + 0.5, vec2(0.5), maxPx);
                        vec2 pMR = clamp(floor(pixel + dir * (0.5 * rP) - perp * (0.5 * wP)) + 0.5, vec2(0.5), maxPx);
                        vec2 pT  = clamp(floor(pixel + dir * rP)                             + 0.5, vec2(0.5), maxPx);
                        vec2 pL  = clamp(floor(pixel + dir * rP + perp * wP)                 + 0.5, vec2(0.5), maxPx);
                        vec2 pR  = clamp(floor(pixel + dir * rP - perp * wP)                 + 0.5, vec2(0.5), maxPx);
                        if (length(pT - pixel) < 0.65 * rP || length(pL - pR) < 0.75 * wP) continue;
                        vec4 qML = positionAt(pML);
                        vec4 qMR = positionAt(pMR);
                        vec4 qT  = positionAt(pT);
                        vec4 qL  = positionAt(pL);
                        vec4 qR  = positionAt(pR);
                        if (qML.w < 0.25 && abs(qML.z - p0.z) < 75.0 &&
                            qMR.w < 0.25 && abs(qMR.z - p0.z) < 75.0 &&
                            qT.w  < 0.25 && abs(qT.z  - p0.z) < 130.0 &&
                            qL.w  < 0.25 && abs(qL.z  - p0.z) < 130.0 &&
                            qR.w  < 0.25 && abs(qR.z  - p0.z) < 130.0 &&
                            abs(qL.z - qR.z) < 45.0) {
                            vec3 cr = cross(qL.xyz - p0, qR.xyz - p0);
                            float crLen = length(cr);
                            if (crLen > 1.0) {
                                vec3 nW = cr / crLen;
                                if (nW.z < 0.0) nW = -nW;
                                float wFacing = dot(nW, WORLD_UP);
                                if (wFacing > 0.32 && wFacing < 0.94 && nW.z > 0.025 && abs(nW.x) > 0.12) {
                                    float errML = abs(dot(qML.xyz - p0, nW));
                                    float errMR = abs(dot(qMR.xyz - p0, nW));
                                    float errT  = abs(dot(qT.xyz  - p0, nW));
                                    if (errML < planeTol && errMR < planeTol && errT < planeTol) {
                                        roofWedges = 1;
                                        bestRoofFacing = wFacing;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (roofWedges == 0) {
                        float shift = max(2.0, 5.0 * ambient.view.z);
                        for (int i = 0; i < 12; i++) {
                            vec2 dir;
                            if (i < 8) {
                                float a = float(i) * 0.7853982;
                                dir = vec2(cos(a), sin(a));
                            } else {
                                float sx = (i == 8 || i == 9) ? 0.8944272 : -0.8944272;
                                float sy = (i == 8 || i == 10) ? 0.4472136 : -0.4472136;
                                dir = vec2(sx, sy);
                            }
                            vec2 perp = vec2(-dir.y, dir.x);
                            vec2 pB = clamp(floor(pixel + dir * shift) + 0.5, vec2(0.5), maxPx);
                            if (length(pB - pixel) < 1.0) continue;
                            vec4 qB = positionAt(pB);
                            if (qB.w >= 0.25 || abs(qB.z - p0.z) >= 60.0) continue;
                            vec2 pML = clamp(floor(pB + dir * (0.5 * rP) + perp * (0.5 * wP)) + 0.5, vec2(0.5), maxPx);
                            vec2 pMR = clamp(floor(pB + dir * (0.5 * rP) - perp * (0.5 * wP)) + 0.5, vec2(0.5), maxPx);
                            vec2 pT  = clamp(floor(pB + dir * rP)                             + 0.5, vec2(0.5), maxPx);
                            vec2 pL  = clamp(floor(pB + dir * rP + perp * wP)                 + 0.5, vec2(0.5), maxPx);
                            vec2 pR  = clamp(floor(pB + dir * rP - perp * wP)                 + 0.5, vec2(0.5), maxPx);
                            if (length(pT - pB) < 0.65 * rP || length(pL - pR) < 0.75 * wP) continue;
                            vec4 qML = positionAt(pML);
                            vec4 qMR = positionAt(pMR);
                            vec4 qT  = positionAt(pT);
                            vec4 qL  = positionAt(pL);
                            vec4 qR  = positionAt(pR);
                            if (qML.w < 0.25 && abs(qML.z - qB.z) < 75.0 &&
                                qMR.w < 0.25 && abs(qMR.z - qB.z) < 75.0 &&
                                qT.w  < 0.25 && abs(qT.z  - qB.z) < 130.0 &&
                                qL.w  < 0.25 && abs(qL.z  - qB.z) < 130.0 &&
                                qR.w  < 0.25 && abs(qR.z  - qB.z) < 130.0 &&
                                abs(qL.z - qR.z) < 45.0) {
                                vec3 cr = cross(qL.xyz - qB.xyz, qR.xyz - qB.xyz);
                                float crLen = length(cr);
                                if (crLen > 1.0) {
                                    vec3 nW = cr / crLen;
                                    if (nW.z < 0.0) nW = -nW;
                                    float wFacing = dot(nW, WORLD_UP);
                                    if (wFacing > 0.32 && wFacing < 0.94 && nW.z > 0.025 && abs(nW.x) > 0.12) {
                                        float errML = abs(dot(qML.xyz - qB.xyz, nW));
                                        float errMR = abs(dot(qMR.xyz - qB.xyz, nW));
                                        float errT  = abs(dot(qT.xyz  - qB.xyz, nW));
                                        float err0  = abs(dot(p0      - qB.xyz, nW));
                                        if (errML < planeTol && errMR < planeTol && errT < planeTol && err0 < planeTol * 2.2) {
                                            roofWedges = 1;
                                            bestRoofFacing = wFacing;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (roofWedges == 0 && facing >= 0.91) {
                        float rF = max(6.0, 22.0 * ambient.view.z);
                        float wF = max(3.0, 10.0 * ambient.view.z);
                        for (int i = 0; i < 8; i++) {
                            float a = float(i) * 0.7853982;
                            vec2 dir = vec2(cos(a), sin(a));
                            vec2 perp = vec2(-dir.y, dir.x);
                            vec2 pML = pixel + dir * (0.5 * rF) + perp * (0.5 * wF);
                            vec2 pMR = pixel + dir * (0.5 * rF) - perp * (0.5 * wF);
                            vec2 pT  = pixel + dir * rF;
                            vec2 pL  = pixel + dir * rF + perp * wF;
                            vec2 pR  = pixel + dir * rF - perp * wF;
                            if (any(lessThan(pML, vec2(0.5))) || any(greaterThan(pML, maxPx)) ||
                                any(lessThan(pMR, vec2(0.5))) || any(greaterThan(pMR, maxPx)) ||
                                any(lessThan(pT,  vec2(0.5))) || any(greaterThan(pT,  maxPx)) ||
                                any(lessThan(pL,  vec2(0.5))) || any(greaterThan(pL,  maxPx)) ||
                                any(lessThan(pR,  vec2(0.5))) || any(greaterThan(pR,  maxPx))) continue;
                            vec4 qML = positionAt(pML);
                            vec4 qMR = positionAt(pMR);
                            vec4 qT  = positionAt(pT);
                            vec4 qL  = positionAt(pL);
                            vec4 qR  = positionAt(pR);
                            if (qML.w < 0.25 && abs(qML.z - p0.z) < 28.0 &&
                                qMR.w < 0.25 && abs(qMR.z - p0.z) < 28.0 &&
                                qT.w  < 0.25 && abs(qT.z  - p0.z) < 48.0 &&
                                qL.w  < 0.25 && abs(qL.z  - p0.z) < 48.0 &&
                                qR.w  < 0.25 && abs(qR.z  - p0.z) < 48.0 &&
                                abs(qL.z - qR.z) < 20.0) {
                                vec3 cr = cross(qL.xyz - p0, qR.xyz - p0);
                                float crLen = length(cr);
                                if (crLen > 1.0) {
                                    vec3 nW = cr / crLen;
                                    if (nW.z < 0.0) nW = -nW;
                                    float wFacing = dot(nW, WORLD_UP);
                                    if (wFacing >= 0.92 && nW.z > 0.35) {
                                        float errML = abs(dot(qML.xyz - p0, nW)) / nW.z;
                                        float errMR = abs(dot(qMR.xyz - p0, nW)) / nW.z;
                                        float errT  = abs(dot(qT.xyz  - p0, nW)) / nW.z;
                                        if (errML < 0.80 && errMR < 0.80 && errT < 0.80) {
                                            roofWedges = 1;
                                            bestRoofFacing = wFacing;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                bool onRoof = !ground && mapped && (relZ > STORY_HEIGHT + 0.08) && (roofWedges >= 1);
                poolWater = (!ground && mapped && !onRoof && abs(relZ) < 0.22 && facing > 0.82)
                    ? smoothstep(0.14, 0.26, workSrc.b)
                      * smoothstep(1.55, 2.15, workSrc.b / max(workSrc.r, 0.015))
                      * smoothstep(1.25, 1.75, workSrc.g / max(workSrc.r, 0.015))
                    : 0.0;
                float settle = 1.0;
                float organic = 0.0;
                float pillowField = 0.0;
                float isFoliage = foliageOf(workSrc);
                vec2 capLot = lot;
                float capCrust = hereCrust;
                float capLying = lying;
                if (!ground) {
                    if (onRoof) {
                        float roofSlope = max(facing, bestRoofFacing);
                        settle = smoothstep(0.20, 0.48, roofSlope);
                        float pitchHold = smoothstep(0.24, 0.78, roofSlope);
                        float eaveBase = max(1.0, floor((relZ + 0.15 * STORY_HEIGHT) / STORY_HEIGHT)) * STORY_HEIGHT;
                        float upSlope = clamp((relZ - eaveBase) / max(0.85 * STORY_HEIGHT, 0.5), 0.0, 1.0);
                        const vec2 rwDir = vec2(0.9284767, 0.3713907);
                        const vec2 rwPerp = vec2(-0.3713907, 0.9284767);
                        float roofRibbon = valueNoise(vec2(dot(lot, rwDir) * 0.09, dot(lot, rwPerp) * 0.24) + vec2(6.3, 2.9));
                        float tileRidge = smoothstep(0.05, 0.22, workLum);
                        float eaveLead = (0.15 * (1.0 - upSlope) + (roofRibbon - 0.5) * 0.14)
                                       * smoothstep(0.0, 0.10, amount) * (1.0 - 0.65 * smoothstep(0.50, 0.95, amount));
                        float roofAmt = max(0.0, amount * (0.86 + 0.22 * pitchHold) + eaveLead);
                        float roofDust = smoothstep(0.02, 0.30, roofAmt)
                                       * (1.0 - 0.42 * tileRidge * (1.0 - smoothstep(0.22, 0.60, roofAmt)));
                        float roofBlanket = smoothstep(0.22, 0.68, roofAmt - 0.10 * tileRidge);
                        capLying = clamp(mix(0.42 * roofDust, 1.0, roofBlanket), 0.0, 1.0);
                    } else {
                        const vec3 RING_TAPS[14] = vec3[14](
                            vec3(-3.5, -2.5, 1.0), vec3( 3.5, -2.5, 1.0),
                            vec3(-3.5,  2.5, 1.0), vec3( 3.5,  2.5, 1.0),
                            vec3( 0.0, -6.5, 1.3), vec3( 0.0,  6.5, 1.3),
                            vec3(-6.5,  0.0, 1.0), vec3( 6.5,  0.0, 1.0),
                            vec3(-9.5, -6.5, 0.8), vec3( 9.5, -6.5, 0.8),
                            vec3(-9.5,  6.5, 0.8), vec3( 9.5,  6.5, 0.8),
                            vec3( 0.0,-12.5, 0.75), vec3(0.0, 12.5, 0.75)
                        );
                        const vec3 UP_TAPS[9] = vec3[9](
                            vec3( 0.0,  -4.5, 0.16), vec3(-3.5,  -5.5, 0.12), vec3( 3.5,  -5.5, 0.12),
                            vec3( 0.0,  -9.5, 0.18), vec3(-5.5, -10.5, 0.11), vec3( 5.5, -10.5, 0.11),
                            vec3( 0.0, -15.5, 0.10), vec3(-4.5, -15.5, 0.05), vec3( 4.5, -15.5, 0.05)
                        );
                        vec3 p = centre.xyz;
                        float sc = max(ambient.view.z, 0.25);
                        float selfFol = foliageOf(workSrc);
                        bool blossomCand = (selfFol < 0.15) && (workLum > 0.08) && (workSrc.b > 0.08) && (workSrc.b > 0.68 * workSrc.g);
                        bool darkCreviceCand = (selfFol < 0.15) && (workLum < 0.025) && (workSrc.g > 1.20 * max(workSrc.r, workSrc.b));
                        float wSum = 0.35;
                        float folW = 0.35 * smoothstep(0.05, 0.25, selfFol);
                        float mxSum = 0.0, mySum = 0.0, mzSum = 0.35 * p.z;
                        float greenNbr = selfFol, greenW = 1.0;
                        float rawFolNbr = selfFol, rawFolW = 1.0;
                        float tightGreen = 0.0, tightW = 0.0;
                        vec4 tapData[14];
                        for (int i = 0; i < 14; i++) {
                            vec2 qPx = floor(clamp(pixel + RING_TAPS[i].xy * sc, vec2(0.0), maxIdx)) + 0.5;
                            vec4 q = positionAt(qPx);
                            if (q.w < 0.25) {
                                vec2 dxy = q.xy - p.xy;
                                float dist = length(dxy);
                                vec3 qCol = texelFetch(source, ivec2(qPx), 0).rgb;
                                float qFol = foliageOf(qCol);
                                float qBlos = smoothstep(0.08, 0.16, qCol.b) * smoothstep(0.68, 0.92, qCol.b / max(qCol.g, 0.02));
                                float qPlant = max(qFol, 0.60 * qBlos);
                                float fw = RING_TAPS[i].z * (1.0 - smoothstep(12.0, 22.0, abs(q.z - p.z)));
                                rawFolNbr += qFol * fw;
                                rawFolW += fw;
                                if (i < 4) {
                                    float tw = RING_TAPS[i].z * (1.0 - smoothstep(10.0, 18.0, abs(q.z - p.z)));
                                    tightGreen += qFol * tw;
                                    tightW += tw;
                                }
                                float dw;
                                if (selfFol >= 0.15) {
                                    dw = (1.0 - smoothstep(20.0, 42.0, abs(q.z - p.z))) * smoothstep(0.06, 0.30, qPlant);
                                } else if (blossomCand || darkCreviceCand) {
                                    dw = (1.0 - smoothstep(14.0, 28.0, abs(q.z - p.z))) * smoothstep(0.06, 0.30, qPlant);
                                } else {
                                    dw = qFol > 0.35 ? 0.0 : (1.0 - smoothstep(1.8 * dist + 3.0, 2.2 * dist + 6.0, abs(q.z - p.z)));
                                    if (dw > 1e-4) {
                                        vec2 mPx = floor(clamp(0.5 * (pixel + qPx), vec2(0.0), maxIdx)) + 0.5;
                                        vec4 qm = positionAt(mPx);
                                        if (qm.w >= 0.25 || abs(qm.z - 0.5 * (p.z + q.z)) >= 1.8 * (0.5 * dist) + 5.0 || foliageOf(texelFetch(source, ivec2(mPx), 0).rgb) > 0.35) {
                                            dw = 0.0;
                                        }
                                    }
                                }
                                float wt = RING_TAPS[i].z * dw;
                                if (wt > 1e-4) {
                                    wSum += wt;
                                    folW += wt * smoothstep(0.10, 0.45, qPlant);
                                    mxSum += wt * dxy.x;
                                    mySum += wt * dxy.y;
                                    mzSum += wt * q.z;
                                    greenNbr += qFol * wt;
                                    greenW += wt;
                                    tapData[i] = vec4(dxy.x, dxy.y, q.z, wt);
                                } else {
                                    tapData[i] = vec4(0.0);
                                }
                            } else {
                                tapData[i] = vec4(0.0);
                            }
                        }
                        float mx = mxSum / wSum;
                        float my = mySum / wSum;
                        float zSmooth = mzSum / wSum;
                        float sxx = 0.35 * mx * mx;
                        float syy = 0.35 * my * my;
                        float sxy = 0.35 * mx * my;
                        float sxz = -0.35 * mx * (p.z - zSmooth);
                        float syz = -0.35 * my * (p.z - zSmooth);
                        for (int i = 0; i < 14; i++) {
                            float wt = tapData[i].w;
                            if (wt > 0.0) {
                                float dx = tapData[i].x - mx;
                                float dy = tapData[i].y - my;
                                float dz = tapData[i].z - zSmooth;
                                sxx += wt * dx * dx;
                                syy += wt * dy * dy;
                                sxy += wt * dx * dy;
                                sxz += wt * dx * dz;
                                syz += wt * dy * dz;
                            }
                        }
                        float det = sxx * syy - sxy * sxy;
                        float gx_m = 0.0, gy_m = 0.0;
                        float facMacro = 0.0;
                        float planeErr = 0.0;
                        // 2x2 determinant > 64 rejects 1D vertical/diagonal iron fence bars while keeping 2D caps/foliage.
                        if (det > 64.0) {
                            gx_m = (syy * sxz - sxy * syz) / det;
                            gy_m = (sxx * syz - sxy * sxz) / det;
                            vec3 nm = normalize(vec3(-gx_m, -gy_m, 1.0));
                            facMacro = clamp(dot(nm, WORLD_UP), 0.0, 1.0);
                            float errSum = 0.0, errW = 0.0;
                            for (int i = 0; i < 14; i++) {
                                float wt = tapData[i].w;
                                if (wt > 0.0) {
                                    float pred = zSmooth + gx_m * (tapData[i].x - mx) + gy_m * (tapData[i].y - my);
                                    errSum += wt * abs(tapData[i].z - pred);
                                    errW += wt;
                                }
                            }
                            planeErr = errW > 1e-4 ? errSum / errW : 0.0;
                        }
                        float topClear = 0.0, overhang = 0.0;
                        for (int i = 0; i < 9; i++) {
                            vec2 qPx = floor(clamp(pixel + UP_TAPS[i].xy * sc, vec2(0.0), maxIdx)) + 0.5;
                            vec4 q = positionAt(qPx);
                            float distY = max(p.y - q.y, 1.0);
                            float openW = max(step(0.25, q.w), smoothstep(18.0, 36.0, zSmooth - q.z));
                            float slopeOpen = smoothstep(-0.22, 0.52, (zSmooth - q.z) / distY);
                            float overT = (1.0 - openW) * smoothstep(0.16, 0.85, (q.z - zSmooth) / distY);
                            float wt = UP_TAPS[i].z;
                            topClear += (openW + (1.0 - openW) * slopeOpen) * wt;
                            overhang += overT * wt;
                        }
                        float greenLocal = greenNbr / max(greenW, 1e-4);
                        float tg = tightW > 1e-4 ? tightGreen / tightW : 0.0;
                        float selfFoliage = smoothstep(0.08, 0.28, selfFol);
                        float blossom = smoothstep(0.08, 0.18, workLum)
                                      * smoothstep(0.08, 0.16, workSrc.b)
                                      * smoothstep(0.68, 0.92, workSrc.b / max(workSrc.g, 0.02))
                                      * smoothstep(0.50, 0.80, tg);
                        float darkCrevice = darkCreviceCand ? smoothstep(0.58, 0.82, tg) * smoothstep(2.6, 3.6, tightW) : 0.0;
                        isFoliage = max(selfFoliage, max(blossom, darkCrevice));
                        organic = isFoliage * smoothstep(0.24, 0.48, greenLocal) * smoothstep(0.95, 1.85, planeErr);

                        float planarFactor = det > 64.0 ? smoothstep(1.15, 0.40, planeErr) : 0.0;
                        float solidSupport = smoothstep(2.6, 5.2, wSum) * smoothstep(48.0, 128.0, det);
                        float nearFolFrac = rawFolNbr / max(rawFolW, 1e-4);
                        float notBushRim = mix(1.0, 1.0 - smoothstep(0.14, 0.36, nearFolFrac) * (1.0 - isFoliage), smoothstep(0.05, 0.18, relZ));
                        float solidFacing = max(facing, facMacro * planarFactor);
                        float settleSolid = smoothstep(0.60, 0.86, solidFacing) * solidSupport * notBushRim * (1.0 - smoothstep(0.28, 0.55, overhang));

                        vec3 hereSm = lotPoint(centre.xy, zSmooth / DEPTH_UNIT, false, ambient.frame.xy);
                        vec2 lotSm = lotSource(hereSm.xy);
                        float edgeSupport = smoothstep(1.6, 5.2, folW);
                        float leafSoft = smoothstep(0.015, 0.13, workLum);
                        float pillowNoise = valueNoise(lotSm * 1.4 + vec2(hereSm.z * 1.1, -hereSm.z * 0.9));
                        float dome = facMacro * 0.46 + topClear * 0.54;
                        pillowField = dome * (1.0 - smoothstep(0.20, 0.58, overhang)) + (pillowNoise - 0.5) * 0.08 + (leafSoft - 0.45) * 0.05;
                        float folAmt = max(0.0, amount * (1.0 - 0.30 * covered));
                        float snowGrow = clamp(folAmt / 1.15, 0.0, 1.0);
                        float settleFoliage = smoothstep(0.54 - 0.18 * snowGrow, 0.86 - 0.10 * snowGrow, pillowField) * edgeSupport;
                        settle = mix(settleSolid, settleFoliage, organic) * (1.0 - poolWater);
                        if (organic > 0.01) {
                            capLot = mix(lot, lotSm, organic);
                            capCrust = snowCrust(capLot);
                            float folDust = smoothstep(0.015, 0.28, folAmt);
                            float folBlanket = smoothstep(0.20, 0.68, folAmt);
                            float folLying = clamp(mix(0.46 * folDust, 1.0, folBlanket), 0.0, 1.0);
                            capLying = mix(lying, folLying, organic);
                        }
                    }
                }
                float wallBlock = 0.0;
                if (!ground && mapped && !onRoof) {
                    int storiesN = indoorStories();
                    float wallR = isFoliage > 0.25 ? 0.11 : 0.48;
                    wallBlock = nearIndoorWall(here.xy, here.z, wallR);
                    int maxCheckRow = min(storiesN - 1, max(1, int(floor(max(0.0, relZ + 0.15) / STORY_HEIGHT))));
                    for (int r = 0; r <= maxCheckRow; r++) {
                        float zr = roofBase + float(r) * STORY_HEIGHT + 0.1;
                        wallBlock = max(wallBlock, nearIndoorWall(here.xy, zr, wallR));
                        if (isFoliage < 0.25 && relZ > float(r + 1) * STORY_HEIGHT - 0.15) {
                            vec2 wallXY = here.xy - vec2(1.25 * max(0.0, relZ - float(r + 1) * STORY_HEIGHT));
                            wallBlock = max(wallBlock, max(indoors(vec3(wallXY, zr)), nearIndoorWall(wallXY, zr, 0.52)));
                        }
                    }
                }
                settle *= 1.0 - smoothstep(0.02, 0.25, wallBlock);
                float swell = valueNoise(capLot * 0.26 + 9.0);
                float capShade = (1.0 - capCrust) * mix(0.09, 0.04, deep) + (1.0 - smoothstep(0.2, 0.8, swell)) * 0.09;
                vec3 snow = mix(SNOW, SNOW_SHADE, clamp(capShade, 0.0, 0.30));
                snow *= 1.0 + 0.32 * (1.0 - 0.7 * deep) * (workLum - 0.24);
                if (!ground && !onRoof && organic > 0.01) {
                    float pillowTop = smoothstep(0.42, 0.82, pillowField);
                    float orgShade = clamp((1.0 - pillowTop) * 0.48 + (1.0 - capCrust) * 0.06, 0.0, 0.52);
                    vec3 snowOrg = mix(SNOW, SNOW_SHADE, orgShade) * (0.96 + 0.08 * smoothstep(0.015, 0.13, workLum));
                    snow = mix(snow, snowOrg, organic);
                }
                float daySun = max(0.0, 1.0 - ambient.weather.w);
                float glint = smoothstep(0.68, 0.94, valueNoise(capLot * 24.0) * valueNoise(capLot * 41.0 + 31.7)) * daySun;
                snow += vec3(0.020, 0.024, 0.034) * glint * winterOutdoor;
                float capAlpha = onRoof ? mix(0.88, 0.94, smoothstep(0.50, 1.05, amount)) : mix(0.86, 0.92, organic);
                float cover = ground ? capLying * winterOutdoor : clamp(capLying * settle * winterOutdoor * capAlpha, 0.0, 1.0);
                result = mixPerceptual(dull, snow, cover);
                if (poolWater > 0.01) {
                    float coolT = smoothstep(0.0, 0.40, amount) * winterOutdoor;
                    vec3 coldPool = mix(workSrc, recolor(workSrc, vec3(0.20, 0.38, 0.54)), 0.34 * coolT);
                    float rimBank = wallBank(here.xy, roofBase);
                    float iceFreeze = smoothstep(0.32 - 0.10 * rimBank, 1.05 - 0.15 * rimBank, amount * (1.0 - 0.25 * covered)) * winterOutdoor;
                    vec3 iceCol = mix(SNOW_SHADE, SNOW, 0.55 + 0.25 * capCrust) * clamp(0.72 + 0.55 * workLum, 0.68, 1.05);
                    vec3 icedPool = mix(coldPool, iceCol, iceFreeze * (0.42 + 0.26 * rimBank));
                    result = mix(result, icedPool, poolWater);
                }
                if (!ground && hasPartialSprite) {
                    vec3 B_win = spriteB;
                    if (mapped && texelFetch(groundMap, ivec2(pixel), 0).r < 1.0
                        && (greenOf(spriteB) > 0.05 || (vacLot > 0.5 && spriteB.b > spriteB.r))) {
                        float gKey = (0.62 - texelFetch(groundMap, ivec2(pixel), 0).r) / 0.003 + ambient.view.w;
                        vec3 hereG = lotPoint(centre.xy, gKey, true, ambient.frame.xy);
                        float gWinOut = min(1.0 - indoors(hereG), architecturalExposure(hereG));
                        if (gWinOut > 0.0) {
                            vec2 gLot = lotSource(hereG.xy);
                            float gOver = smoothstep(0.3, 0.9, topAt(hereG.xy) - hereG.z);
                            float gVacSnow, gEarth, gWear, gGrn, gLum;
                            evalGroundTerms(spriteB, hereG.xy, 1.0, vacLot, gVacSnow, gEarth, gWear, gGrn, gLum);
                            vec3 gDull = winterDullColor(spriteB, hereG, gLot, gLum, gGrn, snowCrust(gLot), gEarth, gWear, gVacSnow, gOver, true, amount);
                            float gEdge, gHitT, gHitS;
                            vec3 gMarch = marchSnowDrift(spriteB, gDull, gLum, hereG, hereG.z, 0.0, amount, deep, gEarth, gWear, gVacSnow, true, gEdge, gHitT, gHitS);
                            B_win = mix(spriteB, gMarch, gWinOut);
                        }
                    }
                    result = sp.a * result + (1.0 - sp.a) * B_win;
                }
                if (!ground) {
                    float baseG = mapped
                        ? terrainBaseAt(here.xy, baseAlt > -1.0e4 ? groundFallback : terrainBaseClamped(here.xy, ambient.contact.w))
                        : here.z;
                    float h0Cap = mapped ? max(0.0, here.z - baseG) : 1.0;
                    float roofW = (onRoof && workGreen < 0.35 && cover > 0.05) ? cover : 0.0;
                    lift = vec4(isFoliage, h0Cap, -max(cover, 0.001), roofW);
                }
            } else {
                result = dull;
            }
            if (mapped && !sim && poolWater < 0.5) {
                float terrain = groundAt(pixel);
                float fallbackBase = terrain > -1.0e4
                    ? lotPoint(centre.xy, terrain / DEPTH_UNIT, true, ambient.frame.xy).z
                    : terrainBaseClamped(here.xy, ambient.contact.w);
                float base = ground ? here.z : terrainBaseAt(here.xy, fallbackBase);
                float h0 = ground ? 0.0 : max(0.0, here.z - base);
                float mEdge, mHitT, mHitS;
                result = marchSnowDrift(workSrc, result, workLum, here, base, h0, amount, deep, earthMask, terrainWear, isVacSnowLot, ground, mEdge, mHitT, mHitS);
                if (mEdge > 0.85 && mHitS > 0.032) {
                    lift = vec4(mHitT, base + mHitS - here.z, 1.0, 0.0);
                } else if (ground && hasPartialSprite) {
                    lift = vec4(1.0, 0.0, 0.0, 0.0);
                }
            } else if (!mapped && ground && hasPartialSprite && !sim) {
                lift = vec4(1.0, 0.0, 0.0, 0.0);
            }
        } else {
            // Covered under an architectural overhang in Winter: emit only if botanical turf modified ground.
            if (ambient.params.y < 0.01 && ambient.season.x < 1.5 && skyExposed > 0.001) {
            float overcastDim = 1.0 - 0.24 * clamp(ambient.clouds.x, 0.0, 1.0) - 0.12 * clamp(ambient.weather.x, 0.0, 1.0);
            float wetDark = 1.0 - 0.22 * clamp(ambient.weather.y, 0.0, 1.0) * (ground ? 1.0 : 0.55);
            result *= mix(1.0, overcastDim * wetDark, skyExposed);
        }
        if (all(lessThan(abs(result - src), vec3(1e-4)))) return;
        }
    }
    if (ambient.params.y < 0.01 && ambient.season.x >= 0.5 && skyExposed > 0.001) {
        float overcastDim = 1.0 - 0.22 * clamp(ambient.clouds.x, 0.0, 1.0) - 0.10 * clamp(ambient.weather.x, 0.0, 1.0);
        float wetDark = ambient.season.x < 1.5 ? (1.0 - 0.22 * clamp(ambient.weather.y, 0.0, 1.0) * (ground ? 1.0 : 0.55)) : 1.0;
        result *= mix(1.0, overcastDim * wetDark, skyExposed);
    }
    color = vec4(result, 1.0);
}
