#version 450
#extension GL_GOOGLE_include_directive : require

// The rain over the lit lot, blended (premultiplied) over its colour after the ambient term: thin streaks in three
// layers, slanted by the wind, over the sky that puddles reflect (with animated raindrop ripples). In winter it falls
// as snow: soft flakes in three layers, drifting with the wind and swaying as they fall (plus hail and lightning during
// heavy storms). On dry autumn days occasional leaves detach from deciduous trees and flutter down;
// on warm dry summer evenings gentle fireflies glow over exposed outdoor ground.
#include "lot.glsl"
#include "ambientUniforms.glsl"
layout(set = 2, binding = 0) uniform sampler2D ambientMap;  // the ambient term; its alpha is 1 less the standing water
layout(set = 2, binding = 1) uniform sampler2D depthMap;
layout(set = 2, binding = 2) uniform sampler2D groundMap;
layout(set = 2, binding = 3) uniform sampler2D overheadMap;
layout(set = 2, binding = 4) uniform sampler2D trailMap;
layout(set = 2, binding = 5) uniform sampler2D outFloraMap;
layout(location = 0) out vec4 color;
#include "architecture.glsl"

float exposedAt(vec2 pixel) {
    float depth = texelFetch(depthMap, ivec2(pixel), 0).r;
    bool terrain = depth >= 1.0;
    if (terrain) depth = texelFetch(groundMap, ivec2(pixel), 0).r;
    if (depth >= 1.0) return 1.0;
    vec3 point = lotPoint((pixel - ambient.view.xy) / ambient.view.z,
        (0.62 - depth) / 0.003 + (terrain ? ambient.view.w : 0.0), terrain, ambient.frame.xy);
    return architecturalExposure(point);
}

const float DEPTH_UNIT = 27.712813;
const vec3 WORLD_UP = vec3(0.0, -0.8660254, 0.5);

vec4 atmosPosAt(vec2 px) {
    vec2 cpx = clamp(px, vec2(0.5), ambient.extent.xy - 0.5);
    vec2 sc = (cpx - ambient.view.xy) / max(ambient.view.z, 0.25);
    float d = texelFetch(depthMap, ivec2(cpx), 0).r;
    if (d < 1.0) return vec4(sc, (0.62 - d) / 0.003, 0.0);
    float g = texelFetch(groundMap, ivec2(cpx), 0).r;
    if (g < 1.0) return vec4(sc, (0.62 - g) / 0.003 + ambient.view.w, 0.5);
    return vec4(sc, -1.0e5, 1.0);
}

float atmosMeshKey(vec4 pos) {
    if (pos.w < 0.25) return pos.z;
    if (pos.w < 0.75) {
        vec3 lp = lotPoint(pos.xy, pos.z, true, ambient.frame.xy);
        return lp.x + lp.y + 0.8 * lp.z;
    }
    return -1.0e5;
}

// Planar exposed-roof detector pointing into the upper hemisphere so bottom eave pixels match while
// indoor-poking lower-story roof shingles, walls, windows, trees, and covered surfaces are rejected.
bool isExposedRoofAt(vec2 px, float scale, out float outKey) {
    outKey = -1.0e5;
    vec4 c = atmosPosAt(px);
    if (c.w > 0.25) return false;
    vec3 lot = lotPoint(c.xy, c.z, false, ambient.frame.xy);
    if (lot.z - terrainBaseAt(lot.xy, lot.z) <= STORY_HEIGHT + 0.05) return false;
    if (architecturalExposure(lot + vec3(0.0, 0.0, 0.45)) <= 0.5) return false;

    vec3 v0 = vec3(c.xy, c.z * DEPTH_UNIT);
    vec2 maxPx = ambient.extent.xy - 0.5;
    float rP = max(2.0, 6.0 * scale);
    float wP = max(0.8, 1.5 * scale);
    const vec2 PITCH_DIRS[5] = vec2[5](
        vec2(-0.8944272, -0.4472136),
        vec2( 0.8944272, -0.4472136),
        vec2(-0.7071068, -0.7071068),
        vec2( 0.7071068, -0.7071068),
        vec2( 0.0,       -1.0)
    );
    for (int i = 0; i < 5; i++) {
        vec2 dir = PITCH_DIRS[i];
        vec2 perp = vec2(-dir.y, dir.x);
        vec2 pML = px + dir * (0.5 * rP) + perp * (0.5 * wP);
        vec2 pMR = px + dir * (0.5 * rP) - perp * (0.5 * wP);
        vec2 pT  = px + dir * rP;
        vec2 pL  = px + dir * rP + perp * wP;
        vec2 pR  = px + dir * rP - perp * wP;
        if (any(lessThan(pML, vec2(0.5))) || any(greaterThan(pML, maxPx)) ||
            any(lessThan(pMR, vec2(0.5))) || any(greaterThan(pMR, maxPx)) ||
            any(lessThan(pT,  vec2(0.5))) || any(greaterThan(pT,  maxPx)) ||
            any(lessThan(pL,  vec2(0.5))) || any(greaterThan(pL,  maxPx)) ||
            any(lessThan(pR,  vec2(0.5))) || any(greaterThan(pR,  maxPx))) continue;
        vec4 qML = atmosPosAt(pML); vec4 qMR = atmosPosAt(pMR);
        vec4 qT  = atmosPosAt(pT);  vec4 qL  = atmosPosAt(pL); vec4 qR = atmosPosAt(pR);
        vec3 vML = vec3(qML.xy, qML.z * DEPTH_UNIT);
        vec3 vMR = vec3(qMR.xy, qMR.z * DEPTH_UNIT);
        vec3 vT  = vec3(qT.xy,  qT.z  * DEPTH_UNIT);
        vec3 vL  = vec3(qL.xy,  qL.z  * DEPTH_UNIT);
        vec3 vR  = vec3(qR.xy,  qR.z  * DEPTH_UNIT);
        if (qML.w < 0.25 && abs(vML.z - v0.z) < 14.0 &&
            qMR.w < 0.25 && abs(vMR.z - v0.z) < 14.0 &&
            qT.w  < 0.25 && abs(vT.z  - v0.z) < 22.0 &&
            qL.w  < 0.25 && abs(vL.z  - v0.z) < 22.0 &&
            qR.w  < 0.25 && abs(vR.z  - v0.z) < 22.0 &&
            abs(vL.z - vR.z) < 7.5) {
            vec3 cr = cross(vL - v0, vR - v0);
            float crLen = length(cr);
            if (crLen > 1.0) {
                vec3 nW = cr / crLen;
                if (nW.z < 0.0) nW = -nW;
                float wFacing = dot(nW, WORLD_UP);
                if (wFacing > 0.32 && wFacing < 0.90 && nW.z > 0.35 && abs(nW.x) > 0.15) {
                    float errML = abs(dot(vML - v0, nW)) / nW.z;
                    float errMR = abs(dot(vMR - v0, nW)) / nW.z;
                    float errT  = abs(dot(vT  - v0, nW)) / nW.z;
                    if (errML < 0.55 && errMR < 0.55 && errT < 0.55) {
                        outKey = c.z;
                        return true;
                    }
                }
            }
        }
    }
    float rF = max(6.0, 20.0 * scale);
    float wF = max(3.0, 9.0 * scale);
    const vec2 FLAT_DIRS[2] = vec2[2](vec2(-0.7071068, -0.7071068), vec2(0.7071068, -0.7071068));
    for (int i = 0; i < 2; i++) {
        vec2 dir = FLAT_DIRS[i];
        vec2 perp = vec2(-dir.y, dir.x);
        vec2 pML = px + dir * (0.5 * rF) + perp * (0.5 * wF);
        vec2 pMR = px + dir * (0.5 * rF) - perp * (0.5 * wF);
        vec2 pT  = px + dir * rF;
        vec2 pL  = px + dir * rF + perp * wF;
        vec2 pR  = px + dir * rF - perp * wF;
        if (any(lessThan(pML, vec2(0.5))) || any(greaterThan(pML, maxPx)) ||
            any(lessThan(pMR, vec2(0.5))) || any(greaterThan(pMR, maxPx)) ||
            any(lessThan(pT,  vec2(0.5))) || any(greaterThan(pT,  maxPx)) ||
            any(lessThan(pL,  vec2(0.5))) || any(greaterThan(pL,  maxPx)) ||
            any(lessThan(pR,  vec2(0.5))) || any(greaterThan(pR,  maxPx))) continue;
        vec4 qML = atmosPosAt(pML); vec4 qMR = atmosPosAt(pMR);
        vec4 qT  = atmosPosAt(pT);  vec4 qL  = atmosPosAt(pL); vec4 qR = atmosPosAt(pR);
        vec3 vML = vec3(qML.xy, qML.z * DEPTH_UNIT);
        vec3 vMR = vec3(qMR.xy, qMR.z * DEPTH_UNIT);
        vec3 vT  = vec3(qT.xy,  qT.z  * DEPTH_UNIT);
        vec3 vL  = vec3(qL.xy,  qL.z  * DEPTH_UNIT);
        vec3 vR  = vec3(qR.xy,  qR.z  * DEPTH_UNIT);
        if (qML.w < 0.25 && abs(vML.z - v0.z) < 28.0 &&
            qMR.w < 0.25 && abs(vMR.z - v0.z) < 28.0 &&
            qT.w  < 0.25 && abs(vT.z  - v0.z) < 48.0 &&
            qL.w  < 0.25 && abs(vL.z  - v0.z) < 48.0 &&
            qR.w  < 0.25 && abs(vR.z  - v0.z) < 48.0 &&
            abs(vL.z - vR.z) < 20.0) {
            vec3 cr = cross(vL - v0, vR - v0);
            float crLen = length(cr);
            if (crLen > 1.0) {
                vec3 nW = cr / crLen;
                if (nW.z < 0.0) nW = -nW;
                float wFacing = dot(nW, WORLD_UP);
                if (wFacing >= 0.92 && nW.z > 0.35) {
                    float errML = abs(dot(vML - v0, nW)) / nW.z;
                    float errMR = abs(dot(vMR - v0, nW)) / nW.z;
                    float errT  = abs(dot(vT  - v0, nW)) / nW.z;
                    if (errML < 0.80 && errMR < 0.80 && errT < 0.80) {
                        outKey = c.z;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Sparse animated rain droplets dripping from visible outer rooftop eaves (in lot-anchored drip columns).
vec4 rooftopEaveDroplets(vec2 pixel, vec2 q, float scale, float time, float dripDrive) {
    float zoomFade = smoothstep(0.45, 0.90, scale);
    if (zoomFade <= 0.01 || ambient.sunLot.w <= 0.0) return vec4(0.0);

    const float COL_SPACING = 18.0;
    float colX = q.x - ambient.frame.x;
    float colId = floor(colX / COL_SPACING);
    float colHash = hash12(vec2(colId, 47.3));
    float spoutSceneX = (colId + 0.18 + 0.64 * colHash) * COL_SPACING + ambient.frame.x;
    float dxScene = q.x - spoutSceneX;
    if (abs(dxScene) > 1.8) return vec4(0.0);

    float spoutPxX = ambient.view.x + spoutSceneX * scale;
    if (spoutPxX < 2.0 || spoutPxX >= ambient.extent.x - 2.0) return vec4(0.0);

    vec4 cHere = atmosPosAt(pixel);
    float keyPixel = atmosMeshKey(cHere);

    bool found = false;
    float foundDy = 0.0;
    float eaveKey = 0.0;
    for (int i = 0; i <= 13; i++) {
        float dy = 1.0 + 4.0 * float(i);
        float candY = pixel.y - dy * scale;
        if (candY < 2.0) break;
        vec4 cUp = atmosPosAt(vec2(spoutPxX, candY));
        if (cUp.w < 0.25 && cUp.z > keyPixel + 0.02 * dy + 0.12) {
            float candKey = 0.0;
            if (isExposedRoofAt(vec2(spoutPxX, candY), scale, candKey)) {
                found = true;
                foundDy = dy;
                eaveKey = candKey;
                break;
            }
        }
    }
    if (!found) return vec4(0.0);

    float lo = max(0.0, foundDy - 4.0);
    float hi = foundDy;
    for (int k = 0; k < 3; k++) {
        float mid = 0.5 * (lo + hi);
        float candKey = 0.0;
        if (isExposedRoofAt(vec2(spoutPxX, pixel.y - mid * scale), scale, candKey)) {
            hi = mid;
            eaveKey = candKey;
        } else {
            lo = mid;
        }
    }
    float eaveDy = hi;

    // Require clear non-roof overhang drop directly below the detected lip so seams, ridges, and back edges never drip.
    vec2 belowPx1 = vec2(spoutPxX, pixel.y - (eaveDy - 3.5) * scale);
    vec2 belowPx2 = vec2(spoutPxX, pixel.y - (eaveDy - 7.0) * scale);
    float dummyKey = 0.0;
    if (isExposedRoofAt(belowPx1, scale, dummyKey) || isExposedRoofAt(belowPx2, scale, dummyKey)) return vec4(0.0);
    float belowKey = atmosMeshKey(atmosPosAt(belowPx1));
    if (eaveKey - belowKey <= 0.16) return vec4(0.0);

    float fallDist = eaveDy;
    float keyDrop = eaveKey - 0.02 * fallDist;
    if (keyDrop <= keyPixel + 0.12) return vec4(0.0);

    float eaveSceneY = q.y - fallDist;
    float eaveBucket = floor((eaveSceneY - ambient.frame.y) / 16.0);
    float spoutSeed = hash12(vec2(colId, eaveBucket + 19.3));
    if (spoutSeed > 0.32 + 0.38 * dripDrive) return vec4(0.0);

    float period = mix(3.2, 1.45, dripDrive) * (0.72 + 0.65 * hash12(vec2(colId + 11.7, eaveBucket + 71.1)));
    float phaseOff = hash12(vec2(colId + 37.1, eaveBucket + 5.9));
    float phase = fract(time / period + phaseOff);

    bool hanging = phase < 0.20;
    float dropY = 0.0;
    float rx = 0.0;
    float ry = 0.0;
    float fade = 0.0;
    if (hanging) {
        float swell = smoothstep(0.0, 0.18, phase);
        dropY = 0.55 + 0.75 * swell * swell;
        rx = mix(0.28, 0.44, swell);
        ry = mix(0.45, 0.95, swell);
        fade = swell;
    } else if (phase < 0.84) {
        float t = (phase - 0.20) / 0.64;
        dropY = 1.3 + 46.0 * t * t;
        rx = mix(0.40, 0.28, t);
        ry = mix(1.40, 4.40, t);
        fade = 1.0 - smoothstep(0.72, 1.0, t);
    } else {
        return vec4(0.0);
    }

    // Ensure at least a crisp hairline half-width at Medium/Far zoom so droplets never vanish sub-pixel.
    float effRx = max(rx, 0.36 / scale);
    float dropX = clamp(ambient.tone.y * dropY * 0.05, -0.5, 0.5);
    vec2 rel = vec2(dxScene - dropX, fallDist - dropY);
    float vPos = clamp(rel.y / max(ry, 0.2), -1.0, 1.0);
    float taper = rel.y < 0.0 ? mix(1.0, 0.38, -vPos) : mix(1.0, 0.82, vPos);
    float d = length(vec2(rel.x / max(effRx * taper, 0.14), rel.y / max(ry, 0.2)));
    float aa = 0.50 / scale;
    float body = (1.0 - smoothstep(1.0 - aa, 1.0 + aa, d)) * fade * zoomFade;
    if (body <= 0.005) return vec4(0.0);

    // Translucent clear-water shading: soft wispy upper tail concentrating into a glistening lower meniscus
    // (matches falling rainStreakCol translucency — ~0.24..0.34 peak alpha, never opaque milky white).
    float tailGrad = hanging ? mix(0.55, 1.0, smoothstep(-0.85, 0.55, vPos))
                             : smoothstep(-1.0, 0.45, vPos);
    float coreGrad = 1.0 - smoothstep(0.15, 0.98, d);
    vec2 glintPos = vec2(rel.x / max(effRx * 0.72, 0.14), (rel.y - ry * 0.32) / max(ry * 0.48, 0.18));
    float glint = exp(-dot(glintPos, glintPos) * 2.4) * body;
    float rim = smoothstep(0.55, 0.98, d) * body;

    float nightDim = mix(1.0, 0.50, ambient.weather.w);
    float streakCover = body * tailGrad * (0.14 + 0.10 * dripDrive) * (0.65 + 0.35 * coreGrad);
    float glintCover = glint * (0.14 + 0.08 * dripDrive);
    float darkRim = rim * (0.08 + 0.04 * dripDrive);

    vec3 waterCol = vec3(0.66, 0.74, 0.84) * nightDim;
    vec3 glintCol = vec3(0.80, 0.86, 0.94) * nightDim;
    vec3 premulRgb = waterCol * streakCover + glintCol * glintCover;
    float outAlpha = clamp(streakCover + glintCover + darkRim, 0.0, 0.38);
    return vec4(premulRgb, outAlpha);
}

// World-space depth-sliced isometric rain curtains occluded strictly behind foreground surfaces (roofs, walls, trees, hills)
// and lit by actual scene illumination (sunlight, shadows, warm porch lamps, lit windows, and lightning).
vec4 worldRainCurtains(vec2 pixel, vec2 q, float scale, float time, float rain, vec4 surfPos, vec3 localLight, float flash) {
    if (rain <= 0.005 || surfPos.w >= 0.75 || ambient.sunLot.w <= 0.0) return vec4(0.0);
    vec3 surf = lotPoint(surfPos.xy, surfPos.z, surfPos.w > 0.25, ambient.frame.xy);
    float surfD = surf.x + surf.y;
    float u = (q.x - ambient.frame.x) / 32.0;
    float localY = q.y - ambient.frame.y;
    float windSlope = clamp(ambient.tone.y * 0.42 + 0.08, -0.35, 0.35);

    const float SLICE_STEP = 1.65;
    float baseSlice = floor(surfD / SLICE_STEP) + 1.0;
    float streakAcc = 0.0;
    float glintAcc = 0.0;

    for (int slice = 0; slice < 8; slice++) {
        float sliceId = baseSlice + float(slice);
        float Dk = sliceId * SLICE_STEP;
        float dDepth = Dk - surfD;
        float sliceFade = smoothstep(0.0, 0.18, dDepth) * (1.0 - smoothstep(6.0 * SLICE_STEP, 7.9 * SLICE_STEP, dDepth));
        if (sliceFade <= 0.005) continue;

        float h = (16.0 * Dk - localY) / 40.0;
        float colCoord = (u + windSlope * h) * 2.6 + hash12(vec2(sliceId, 13.7)) * 7.31;
        float colId = floor(colCoord);
        float r = hash12(vec2(colId, sliceId * 19.3 + 3.1));
        float center = 0.18 + 0.64 * hash12(vec2(colId, sliceId * 41.7 + 9.2));
        float dxPx = abs(fract(colCoord) - center) * (32.0 / 2.6);
        if (dxPx > 1.8 / max(scale, 0.45) + 0.55) continue;

        float speed = 13.5 + 5.5 * r + 3.5 * rain;
        float period = mix(4.4, 2.7, rain) * (0.82 + 0.36 * r);
        float v = (h + time * speed) / period + r * 11.73;
        float dropId = floor(v);
        float along = fract(v);
        float activeProb = mix(0.32, 0.65, rain);
        if (hash12(vec2(colId + sliceId * 37.0, dropId * 1.7 + 5.3)) > activeProb) continue;

        float streakFrac = (0.36 + 0.26 * r) / period;
        if (along > streakFrac) continue;

        float tAlong = along / streakFrac;
        float halfW = mix(0.46, 0.16, tAlong) / max(scale, 0.50);
        float aa = 0.44 / max(scale, 0.50);
        float acrossMask = 1.0 - smoothstep(max(0.0, halfW - aa), halfW + aa, dxPx);
        if (acrossMask <= 0.005) continue;

        vec3 dropPos = vec3(0.5 * (Dk + u), 0.5 * (Dk - u), h);
        float dropExp = architecturalExposure(dropPos);
        if (dropExp <= 0.05) continue;

        float tailProfile = smoothstep(0.0, 0.09, tAlong) * pow(1.0 - smoothstep(0.09, 1.0, tAlong), 1.65);
        float headGlint = exp(-pow((tAlong - 0.13) / 0.14, 2.0)) * 0.52;
        float depthWeight = mix(1.0, 0.62, clamp(dDepth / (7.5 * SLICE_STEP), 0.0, 1.0));
        float w = acrossMask * (tailProfile + headGlint) * sliceFade * dropExp * depthWeight * (0.75 + 0.35 * r);
        streakAcc += w;
        glintAcc += w * headGlint;
    }

    if (streakAcc <= 0.002) return vec4(0.0);
    vec3 baseTint = mix(vec3(0.72, 0.78, 0.86), vec3(0.38, 0.44, 0.56), ambient.weather.w);
    vec3 litTint = baseTint * mix(vec3(0.68), clamp(localLight, vec3(0.46), vec3(1.80)), 0.70)
                 + vec3(0.60, 0.66, 0.76) * flash;
    float cover = clamp(streakAcc * mix(0.18, 0.28, rain), 0.0, 0.34);
    vec3 rgb = litTint * cover + (litTint * 1.30) * clamp(glintAcc * 0.16, 0.0, 0.14);
    return vec4(rgb, cover);
}

// World-anchored raindrop impact rings and micro-splash crowns on exposed outdoor ground and roof shingles.
vec4 surfaceRainSplashes(vec2 pixel, float scale, float time, float rain, vec4 surfPos, vec3 localLight, float flash) {
    float zoomFade = smoothstep(0.22, 0.48, scale);
    if (zoomFade <= 0.01 || rain <= 0.04 || surfPos.w >= 0.75 || ambient.sunLot.w <= 0.0) return vec4(0.0);

    bool isGround = surfPos.w > 0.25;
    vec3 surf = lotPoint(surfPos.xy, surfPos.z, isGround, ambient.frame.xy);
    if (!isGround) {
        if (surf.z - terrainBaseAt(surf.xy, surf.z) <= STORY_HEIGHT + 0.05) return vec4(0.0);
        if (architecturalExposure(surf + vec3(0.0, 0.0, 0.45)) <= 0.5) return vec4(0.0);
    }

    float splashAcc = 0.0;
    bool verifiedRoof = false;
    for (int layer = 0; layer < 2; layer++) {
        float gridScale = layer == 0 ? 2.4 : 3.8;
        float seedOffset = float(layer) * 53.7;
        vec2 g = surf.xy * gridScale + float(layer) * vec2(0.37, 0.71);
        vec2 cid = floor(g);
        float hProb = hash12(cid + seedOffset + 3.1);
        if (hProb > rain * (layer == 0 ? 0.65 : 0.45)) continue;

        float hTime = hash12(cid + seedOffset + 19.3);
        float age = fract(time * (2.3 + 1.4 * rain + 0.5 * float(layer)) + hTime);
        const float SPLASH_LIFE = 0.26;
        if (age >= SPLASH_LIFE) continue;

        float t = age / SPLASH_LIFE;
        vec2 dropCenter = cid + 0.22 + 0.56 * vec2(hash12(cid + seedOffset + 7.9), hash12(cid + seedOffset + 31.4));
        vec2 delta = g - dropCenter;

        float rDist = length(delta);
        float ringR = mix(0.03, 0.16, t);
        float ringW = (0.044 * gridScale / 2.4) / max(scale, 0.50);
        float ring = (1.0 - smoothstep(0.0, ringW, abs(rDist - ringR))) * pow(1.0 - t, 1.5) * 0.72;

        float sx = (delta.x - delta.y) * 0.7071068;
        float sy = -(delta.x + delta.y) * 0.7071068;
        float hop = sin(t * 3.14159265) * 0.16;
        float spread = 0.08 * t;
        float dotR = (0.048 * gridScale / 2.4) / max(scale, 0.50);
        float d1 = length(vec2((sx - spread) * 2.0, sy - hop));
        float d2 = length(vec2((sx + spread) * 2.0, sy - hop));
        float d0 = length(vec2(sx * 2.0, sy - hop * 0.45));
        float crown = (1.0 - smoothstep(dotR * 0.35, dotR, min(d0, min(d1, d2)))) * (1.0 - t);

        float s = ring + crown;
        if (s > 0.005) {
            if (!isGround && !verifiedRoof) {
                float roofKey = 0.0;
                if (!isExposedRoofAt(pixel, scale, roofKey)) return vec4(0.0);
                verifiedRoof = true;
            }
            splashAcc += s * (layer == 0 ? 1.0 : 0.75);
        }
    }

    if (splashAcc <= 0.002) return vec4(0.0);
    vec3 splashTint = mix(vec3(0.78, 0.84, 0.92), vec3(0.44, 0.50, 0.62), ambient.weather.w)
                    * mix(vec3(0.65), clamp(localLight, vec3(0.44), vec3(1.70)), 0.68)
                    + vec3(0.60, 0.66, 0.76) * flash;
    float alpha = clamp(splashAcc * 0.28 * zoomFade, 0.0, 0.30);
    return vec4(splashTint * alpha, alpha);
}

vec2 lotFromCamera(vec2 camera) {
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    return orientation == 1 ? vec2(camera.y, size.y - camera.x)
         : orientation == 2 ? size - camera
         : orientation == 3 ? vec2(size.x - camera.y, camera.x) : camera;
}

vec2 cameraFromLot(vec2 lot) {
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    return orientation == 1 ? vec2(size.y - lot.y, lot.x)
         : orientation == 2 ? size - lot
         : orientation == 3 ? vec2(lot.y, size.x - lot.x) : lot;
}

// Keep synchronized with season.frag fallenLeafColorSrgb.
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

vec4 treeFallingLeaves(vec2 q, float scale, float time, vec4 surfPos) {
    if (ambient.season.x <= 0.5 || ambient.season.x >= 1.5 || ambient.season.y <= 0.25) return vec4(0.0);
    ivec2 trailSize = textureSize(trailMap, 0);
    ivec2 outSize = textureSize(outFloraMap, 0);
    bool hasInTrail = trailSize.x > 4 && abs(texelFetch(trailMap, ivec2(0, 0), 0).a - 0.5) < 0.18;
    bool hasOutFlora = ambient.prevView.w > 0.5 && ambient.prevView.x > 0.0 && outSize.x > 4;
    if (!hasInTrail && !hasOutFlora) return vec4(0.0);

    vec3 surf = surfPos.w < 0.75
        ? lotPoint(surfPos.xy, surfPos.z, surfPos.w > 0.25, ambient.frame.xy)
        : vec3(0.0);
    float surfKey = atmosMeshKey(surfPos);
    float surfGroundFallback = surfPos.w > 0.25 ? surf.z : terrainBaseClamped(surf.xy, ambient.contact.w);
    float refBaseZ = surfPos.w < 0.75 ? terrainBaseAt(surf.xy, surfGroundFallback) : ambient.contact.w;

    float u = (q.x - ambient.frame.x) / 32.0;
    float localY = q.y - ambient.frame.y;
    float midH = refBaseZ + 1.5;
    float midD = (localY + 40.0 * midH) / 16.0;
    vec2 midCam = vec2(0.5 * (midD + u), 0.5 * (midD - u));
    vec2 midLot = lotFromCamera(midCam);
    vec2 lotSize = ambient.drift.zw;

    const float CELL = 3.0;
    vec2 baseCell = floor(midLot / CELL);
    float spawnProb = clamp((ambient.season.y - 0.25) * 0.80, 0.0, 0.55);
    float dayDim = mix(1.0, 0.28, ambient.weather.w);
    vec4 acc = vec4(0.0);

    for (int oy = -1; oy <= 1; oy++) {
        for (int ox = -1; ox <= 1; ox++) {
            vec2 cell = baseCell + vec2(float(ox), float(oy));
            float period = 16.0 + 10.0 * hash12(cell + vec2(17.3, 41.9));
            float phase = hash12(cell + vec2(53.1, 7.7));
            float cycleT = time / period + phase;
            float cycleId = floor(cycleT);
            float cycleFrac = fract(cycleT);

            float rSpawn = hash12(cell * 1.37 + vec2(cycleId * 13.1, 29.7));
            if (rSpawn > spawnProb) continue;

            float fallDur = 3.8 + 1.6 * hash12(cell + vec2(cycleId * 7.3, 61.1));
            float activeFrac = fallDur / period;
            if (cycleFrac >= activeFrac) continue;
            float p = cycleFrac / activeFrac;

            vec2 spawnLot = (cell + vec2(
                hash12(cell + vec2(cycleId * 19.7, 3.1)),
                hash12(cell + vec2(11.3, cycleId * 23.9)))) * CELL;
            bool inLot = spawnLot.x >= -0.5 && spawnLot.y >= -0.5 && spawnLot.x <= lotSize.x + 0.5 && spawnLot.y <= lotSize.y + 0.5;
            vec4 flora = vec4(0.0);
            if (inLot && hasInTrail) {
                vec2 texel = (spawnLot + TRAIL_MARGIN) * TRAIL_TEXELS - 0.5;
                ivec2 tc = ivec2(floor(texel + 0.5));
                if (any(lessThan(tc, ivec2(0))) || any(greaterThanEqual(tc, trailSize))) continue;
                flora = texelFetch(trailMap, tc, 0);
            } else if (hasOutFlora) {
                vec2 texel = (spawnLot + ambient.prevView.yz) * ambient.prevView.x - 0.5;
                ivec2 tc = ivec2(floor(texel + 0.5));
                if (any(lessThan(tc, ivec2(0))) || any(greaterThanEqual(tc, outSize))) continue;
                flora = texelFetch(outFloraMap, tc, 0);
            } else {
                continue;
            }
            if (flora.g < 0.35 || flora.r > 0.35) continue;

            vec2 spawnCam = cameraFromLot(spawnLot);
            float leafBaseZ = terrainBaseAt(spawnCam, refBaseZ);
            float rH = hash12(cell + vec2(cycleId * 31.3, 47.1));
            float hStart = leafBaseZ + 1.85 + 0.95 * rH;
            float hEnd = leafBaseZ + 0.04;

            float flutterFreq = 1.35 + 0.75 * rH;
            float flutterPhase = rSpawn * 6.28318 * 7.0;
            float swayArg = p * 6.28318 * flutterFreq + flutterPhase;

            float pVert = clamp(p + 0.022 * sin(swayArg * 2.0), 0.0, 1.0);
            float lh = mix(hStart, hEnd, pVert);

            float windMag = 0.28 + 0.26 * abs(ambient.tone.y);
            vec2 driftDir = normalize(vec2(0.75, -0.45) + 0.35 * vec2(rH - 0.5, fract(rSpawn * 17.3) - 0.5));
            vec2 perpDir = vec2(-driftDir.y, driftDir.x);
            float sway = sin(swayArg) * 0.16 * sin(p * 3.14159);
            vec2 leafLot = spawnLot + driftDir * (windMag * p) + perpDir * sway;
            vec2 leafCam = cameraFromLot(leafLot);

            vec2 leafScene = sceneOf(vec3(leafCam, lh));
            vec2 d = q - leafScene;
            if (dot(d, d) > 12.0) continue;

            if (architecturalExposure(vec3(leafCam, lh)) <= 0.5) continue;
            float leafKey = leafCam.x + leafCam.y + 0.8 * lh;
            if (leafKey < surfKey - 0.40) continue;

            float ang = 0.65 * cos(swayArg) + (rH - 0.5) * 1.4;
            float ca = cos(ang), sa = sin(ang);
            vec2 rd = vec2(d.x * ca - d.y * sa, d.x * sa + d.y * ca);
            float tumble = 0.42 + 0.58 * abs(sin(swayArg * 0.85 + 1.1));
            float halfLen = 1.85;
            float halfWid = 0.92 * tumble;
            float lu = rd.x / halfLen;
            float bend = (lu * lu - 0.35) * 0.28 * halfWid;
            float lv = (rd.y - bend) / max(halfWid, 0.28);
            float profile = sqrt(max(0.0, 1.0 - lu * lu)) * (1.0 - 0.25 * lu);
            float edgeSoft = 0.34 / max(scale, 0.5);
            float mask = abs(lu) < 1.0 ? (1.0 - smoothstep(-edgeSoft, edgeSoft, abs(lv) - profile)) : 0.0;
            float lifeFade = smoothstep(0.0, 0.12, p) * (1.0 - smoothstep(0.86, 1.0, p));
            float alpha = mask * 0.78 * lifeFade;
            if (alpha > 0.01) {
                float speciesHue = flora.b > 0.04 ? flora.b : 0.42;
                float hueSeed = fract(rSpawn * 19.37 + rH * 7.13);
                vec3 leafCol = fallenLeafColorSrgb(hueSeed, speciesHue);
                float leafShade = mix(0.78, 1.12, clamp(0.5 - 0.35 * lv + 0.25 * lu, 0.0, 1.0));
                acc += vec4(leafCol * leafShade * dayDim * alpha, alpha);
            }
        }
    }
    return acc;
}

void main() {
    vec2 pixel = floor(gl_FragCoord.xy) + 0.5;
    if (pixel.x >= ambient.extent.x || pixel.y >= ambient.extent.y) { color = vec4(0.0); return; }
    float scale = max(ambient.view.z, 0.25);
    float cover = 0.0;
    float rain = ambient.weather.x;
    float time = ambient.weather.z;
    // Wet ground and shallow rainwater reflect only a discreet, dark-grounded sky sheen (low grazing Fresnel,
    // dimmed heavily under overcast rain clouds and at night) so wet patches stay darker than dry ground.
    float ambScale = ambient.extent.w > 0.5 ? ambient.extent.w : 1.0;
    ivec2 ambLimit = textureSize(ambientMap, 0) - 1;
    vec4 ambientSample = texelFetch(ambientMap, clamp(ivec2(floor(pixel / ambScale)), ivec2(0), ambLimit), 0);
    float water = 1.0 - ambientSample.a;
    vec3 localLight = ambientSample.rgb * 2.0;
    vec4 surfPos = atmosPosAt(pixel);
    vec3 sky = mix(vec3(0.32, 0.40, 0.54), vec3(0.24, 0.27, 0.32), clamp(ambient.clouds.x, 0.0, 1.0))
             * mix(1.0, 0.22, ambient.weather.w);
    vec4 reflection = vec4(sky, 1.0) * 0.028 * water;
    bool snowing = ambient.seasonExtra.z > 0.5 || (abs(ambient.seasonExtra.z) < 0.25 && ambient.season.x > 1.5);
    float hail = clamp(ambient.seasonExtra2.x, 0.0, 1.0);
    float thunderPulse = clamp(ambient.seasonExtra2.z, 0.0, 1.0);
    float fireflies = clamp(ambient.seasonExtra.w, 0.0, 1.0);
    vec2 q = (pixel - ambient.view.xy) / scale;
    float dripDrive = (!snowing && rain > 0.02) ? rain : 0.0;
    vec4 eaveDrip = dripDrive > 0.01 ? rooftopEaveDroplets(pixel, q, scale, time, dripDrive) : vec4(0.0);

    float exposed = exposedAt(pixel);
    if (exposed <= 0.01) {
        color = eaveDrip + reflection * (1.0 - eaveDrip.a);
        return;
    }

    if (rain > 0.0 && snowing) {
        for (int layer = 0; layer < 3; layer++) {
            float cell = 26.0 + 14.0 * float(layer);
            float speed = 40.0 + 25.0 * float(layer);
            float radius = 1.2 + 0.8 * float(layer);
            // The field falls and drifts with the wind; each flake sways about its own column.
            vec2 moved = q - vec2(ambient.tone.y * speed * 1.5 * time, speed * time) + float(layer) * 113.0;
            vec2 at = floor(moved / cell);
            float r = hash12(at + float(layer) * 31.0);
            if (r > rain * 0.9) continue;
            vec2 centre = (at + 0.2 + 0.6 * vec2(hash12(at + 5.0), hash12(at + 9.0))) * cell;
            centre.x += 4.0 * sin(time * (1.2 + r) + r * 40.0);
            float d = length(moved - centre);
            cover += (1.0 - smoothstep(radius * 0.4, radius + 0.5 / scale, d)) * (0.5 + 0.2 * float(layer));
        }
        cover = clamp(cover * 0.8, 0.0, 0.75) * exposed;
        color = vec4(vec3(0.95, 0.96, 1.0) * cover, cover);
        return;
    }
    vec4 rainCol = vec4(0.0);
    if (rain > 0.0) {
        float thunderFlash = 0.0;
        bool hasThunder = rain > 0.6 || thunderPulse > 0.5;
        if (hasThunder) {
            // Thunderstorm: synchronized double flicker of lightning over the whole view (matches ambient.frag).
            float slot = floor(time / 7.0);
            float stormChance = thunderPulse > 0.5 ? 0.55 : (rain - 0.6) * 1.6;
            float strikes = step(hash12(vec2(slot, 3.0)), stormChance);
            float dt = time - slot * 7.0 - 1.0 - 4.0 * hash12(vec2(slot, 7.0));
            float flash = dt < 0.0 ? 0.0 : exp(-dt * 10.0) + (dt < 0.18 ? 0.0 : 0.7 * exp(-(dt - 0.18) * 9.0));
            thunderFlash = clamp(flash * strikes, 0.0, 1.0) * 0.28 * exposed;
        }

        vec4 rain3d = worldRainCurtains(pixel, q, scale, time, rain, surfPos, localLight, thunderFlash);
        vec4 splashes = surfaceRainSplashes(pixel, scale, time, rain, surfPos, localLight, thunderFlash);
        rainCol = rain3d + splashes * (1.0 - rain3d.a);
        cover = rainCol.a;

        float hailCover = 0.0;
        if (hail > 0.05) {
            for (int layer = 0; layer < 2; layer++) {
                float cell = 24.0 + 12.0 * float(layer);
                float speed = 640.0 + 220.0 * float(layer);
                vec2 moved = q - vec2(ambient.tone.y * speed * 0.6 * time, speed * time) + float(layer) * 79.0;
                vec2 at = floor(moved / cell);
                if (hash12(at + float(layer) * 53.0) > hail * 0.45) continue;
                vec2 centre = (at + 0.25 + 0.5 * vec2(hash12(at + 11.0), hash12(at + 19.0))) * cell;
                float r = 1.3 + 0.6 * float(layer);
                hailCover += (1.0 - smoothstep(r * 0.4, r + 0.4 / scale, length(moved - centre))) * 0.55;
            }
            hailCover = clamp(hailCover, 0.0, 0.6) * exposed;
        }
        if (hasThunder || hailCover > 0.001) {
            vec4 baseCol = vec4(rainCol.rgb + vec3(0.95, 0.98, 1.0) * hailCover + vec3(0.92, 0.94, 1.0) * thunderFlash,
                                clamp(rainCol.a + hailCover, 0.0, 0.75)) + reflection * (1.0 - rainCol.a);
            color = eaveDrip + baseCol * (1.0 - eaveDrip.a);
            return;
        }
    }

    vec4 airborne = vec4(0.0);
    if (rain <= 0.02) {
        airborne += treeFallingLeaves(q, scale, time, surfPos);
        if (exposed > 0.5 && fireflies > 0.05) {
            float cell = 320.0;
            vec2 moved = q + vec2(149.0, 83.0);
            vec2 at = floor(moved / cell);
            float r = hash12(at + 29.0);
            if (r <= fireflies * 0.055) {
                vec2 clump = (at + 0.25 + 0.5 * vec2(hash12(at + 5.0), hash12(at + 17.0))) * cell;
                if (length(moved - clump) < 30.0) {
                    for (int k = 0; k < 4; k++) {
                        float fk = float(k);
                        float h1 = hash12(at + vec2(fk * 11.3, 3.7));
                        float h2 = hash12(at + vec2(7.1, fk * 17.9));
                        vec2 pos = clump + vec2(
                            (h1 - 0.5) * 18.0 + 4.5 * sin(time * (0.65 + 0.45 * h2) + fk * 2.1 + h1 * 19.0),
                            (h2 - 0.5) * 12.0 + 3.2 * cos(time * (0.80 + 0.35 * h1) + fk * 3.4 + h2 * 13.0));
                        float pulse = pow(0.5 + 0.5 * sin(time * (0.95 + 0.7 * h1) + fk * 1.9 + h2 * 29.0), 4.2);
                        float dist = length(moved - pos);
                        float core = (1.0 - smoothstep(0.15, 0.85, dist)) * pulse * fireflies * 0.95 * exposed;
                        float halo = exp(-dist * dist / 24.0) * pulse * fireflies * 0.22 * exposed;
                        airborne += vec4(vec3(1.0, 0.94, 0.58) * core + vec3(1.0, 0.86, 0.34) * halo, clamp(core * 0.75 + halo * 0.32, 0.0, 0.85));
                    }
                }
            }
        }
    }

    airborne = clamp(airborne, vec4(0.0), vec4(1.0));
    vec4 baseCol = rainCol + reflection * (1.0 - cover) + airborne * (1.0 - cover);
    color = eaveDrip + baseCol * (1.0 - eaveDrip.a);
}
