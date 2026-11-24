#version 450
// Seasons HD botanical terrain shader: preserves Sims 1's exact per-vertex inLight / inDark hill-shaded ramps
// and continuous inGrass wear/soil map while replacing the 1999 4x2 checkerboard dither and 1px static dots
// with sub-pixel anti-aliased, upward-growing tapered grass blades in back-to-front painter's order.
layout(location = 0) in vec4 inColor;
layout(location = 1) in vec2 inCoordinate;
layout(location = 2) in vec4 inLight;
layout(location = 3) in vec4 inDark;
layout(location = 4) in vec4 inTint;
layout(location = 5) in float inGrass;
layout(location = 6) flat in vec2 inDetail;
layout(location = 0) out vec4 color;

uint hash(ivec2 point, uint salt) {
    uint value = uint(point.x) * 0x8da6b343u ^ uint(point.y) * 0xd8163841u ^ salt * 0xcb1ab31fu;
    value ^= value >> 16; value *= 0x7feb352du;
    value ^= value >> 15; value *= 0x846ca68bu;
    value ^= value >> 16;
    return value;
}

float rand01(ivec2 point, uint salt) {
    return float(hash(point, salt) & 0x00ffffffu) * (1.0 / 16777216.0);
}

vec3 toLinear(vec3 c) {
    return mix(c / 12.92, pow((c + 0.055) / 1.055, vec3(2.4)), step(vec3(0.04045), c));
}

void main() {
    int detail = int(inDetail.x + 0.5);

    // Continuous grass growth/wear from Sims 1's vertex grass attribute (no quantization steps or hard seams).
    float value = inGrass * 255.0 - 128.0;
    float growth = clamp((value + 73.0) / 158.0, 0.0, 1.0);

    // Keep Sims 1's exact hill lighting and soil-to-grass vertex harmony, with only a subtle clean green lift
    // where the vertex itself is healthy green lawn (0% effect on brown soil, sand, or snow terrain).
    float greenness = smoothstep(0.005, 0.032, inLight.g - inLight.r)
                    * smoothstep(0.08, 0.18, inLight.g - inLight.b) * growth;
    vec3 lightCol = clamp(mix(inLight.rgb, inLight.rgb * vec3(0.95, 1.04, 0.96) + vec3(0.0, 0.010, 0.002), 0.60 * greenness), 0.0, 1.0);
    vec3 darkCol  = clamp(mix(inDark.rgb,  inDark.rgb  * vec3(0.93, 1.03, 0.96), 0.60 * greenness), 0.0, 1.0);

    if (detail <= 0) {
        color = vec4(toLinear(lightCol) * inTint.rgb, 1.0);
        return;
    }

    float maxDensity = detail == 1 ? 0.74 : 0.95;
    float minDensity = detail == 1 ? 0.24 : 0.36;
    float density = mix(minDensity, maxDensity, growth);

    // World-locked blade root grid in scene units (~1.56x1.36 Retina px at Medium zoom, ~3.12x2.72 px at Near).
    const vec2 CELL = vec2(0.78, 0.68);
    vec2 p = inCoordinate / CELL;
    vec2 fw = fwidth(p);

    // Fine mineral/thatch ground bed beneath blades (smooth, zero 4x2 checkerboard dither).
    ivec2 grainCell = ivec2(floor(inCoordinate * 1.5));
    float fineGrain = (rand01(grainCell, 91u) - 0.5) * 0.045;
    float bedShade = 0.15 * density + fineGrain;
    vec3 turfSrgb = clamp(mix(lightCol, darkCol, bedShade), 0.0, 1.0);

    // Smooth LOD: full crisp sub-pixel blades at Near & Medium zoom, cross-fading cleanly at Far zoom to avoid shimmer.
    float bladeLod = 1.0 - smoothstep(0.88, 1.55, fw.x);
    float granLod = 1.0 - smoothstep(0.85, 1.75, max(fw.x, fw.y));
    float snowOrSand = smoothstep(0.24, 0.34, inLight.b) * smoothstep(0.10, 0.20, inDark.b);
    float bareSoil = smoothstep(0.16, 0.23, (inLight.r - inLight.g) / max(inLight.r, 0.05))
                   * smoothstep(0.05, 0.15, inLight.r - inLight.b);
    float granularTerrain = max(snowOrSand, bareSoil);
    if (granularTerrain < 0.99) {
        if (bladeLod > 0.01) {
            ivec2 baseCell = ivec2(floor(p));
            float aa = max(fw.x * 0.48, 0.085);
            // Gentle local cowlick flow bends blade lean angles slightly without adding any color blotches.
            float flow = 0.20 * sin(inCoordinate.x * 0.085 + 0.75 * sin(inCoordinate.y * 0.105));
            int bladesPerRoot = detail >= 2 ? 2 : 1;

            // Painter's order back-to-front: dy = 0 (further up screen / behind) -> dy = 3 (lower on screen / in front).
            for (int dy = 0; dy <= 3; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    ivec2 rc = baseCell + ivec2(dx, dy);
                    for (int b = 0; b < 2; b++) {
                        if (b >= bladesPerRoot) break;
                        uint salt = uint(b) * 37u;
                        float spawnThresh = b == 0 ? density : density * growth * 0.82;
                        if (rand01(rc, 1u + salt) >= spawnThresh) continue;

                        vec2 root = vec2(rc) + vec2(
                            0.16 + 0.68 * rand01(rc, 2u + salt),
                            0.18 + 0.68 * rand01(rc, 3u + salt));
                        float rise = root.y - p.y;
                        if (rise <= 0.0) continue;

                        float h = mix(1.75, 3.45, rand01(rc, 4u + salt)) * mix(0.68, 1.04, growth) * (b == 0 ? 1.0 : 0.78);
                        float t = rise / h;
                        if (t >= 1.0) continue;

                        float lean = (rand01(rc, 5u + salt) - 0.5) * 0.62 + flow;
                        float spineX = root.x + lean * t * t;
                        float halfW = mix(0.35, 0.055, pow(t, 0.75));
                        float dist = abs(p.x - spineX);
                        float cov = (1.0 - smoothstep(halfW - aa, halfW + aa, dist)) * bladeLod;
                        if (cov <= 0.005) continue;

                        // Crisp blade-to-blade tone variation + dark root AO + sunlit pointed tip, all in Sims 1's ramp.
                        float bladeTone = rand01(rc, 6u + salt);
                        float shade = mix(0.05, 0.44, bladeTone);
                        shade += 0.22 * (1.0 - smoothstep(0.0, 0.42, t));
                        shade -= 0.14 * smoothstep(0.58, 1.0, t);
                        vec3 bladeCol = clamp(mix(lightCol, darkCol, shade), 0.0, 1.0);
                        turfSrgb = mix(turfSrgb, bladeCol, cov);
                    }
                }
            }
        } else {
            // Far zoom: clean anti-aliased fine turf micro-texture in the exact Sims 1 ramp (zero dither, zero clouds).
            ivec2 farCell = ivec2(floor(inCoordinate * 0.65));
            float farTex = mix(0.04, 0.34, rand01(farCell, 17u)) * density;
            turfSrgb = clamp(mix(lightCol, darkCol, farTex), 0.0, 1.0);
        }
    }
    if (granularTerrain > 0.01) {
        // Soft mineral / snow grain in Sims 1's exact light/dark ramp (no vertical grass blades or noisy static).
        ivec2 gPix = ivec2(floor(inCoordinate * 2.0));
        ivec2 gCoarse = ivec2(floor(inCoordinate * 1.0));
        float g1 = rand01(gPix, 131u);
        float g2 = rand01(gCoarse, 157u);
        float gBlend = mix(0.06, mix(0.02, 0.12, 0.55 * g1 + 0.45 * g2), granLod);
        vec3 granularSrgb = clamp(mix(lightCol, darkCol, gBlend * mix(0.75, 1.05, 1.0 - growth)), 0.0, 1.0);
        turfSrgb = mix(turfSrgb, granularSrgb, granularTerrain);
    }

    color = vec4(toLinear(turfSrgb) * inTint.rgb, 1.0);
}
