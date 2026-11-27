#version 450
#extension GL_GOOGLE_include_directive : require
#include "lot.glsl"

// Depth-sprite ambient occlusion and sun shadows. The lot camera is an orthographic 30° projection, so the depth buffer
// gives each pixel's exact position: scene pixels across and down, and the distance toward the camera from the depth
// key (depth = 0.9 - 0.003 (x + y + 0.8 altitude), one x + y step being 32 cos 30° scene pixels along the view axis).
// Level-1 floors and terrain draw without depth, so where the lot's depth is clear the terrain's own depth (drawn to a
// second target) is used, and where both are clear lies the backdrop around the lot. From those positions the pass
// takes a horizon-based occlusion over a few screen slices (GTAO with a constant view vector) and contact shadows on the
// ground. Sun shadows are cast in the lot itself: each pixel's point on the lot (lot.glsl) marches toward the sun across
// the lot's height map, which heightScatter.vert fills from the same depth. The product is multiplied into the lot's
// colour. Lit lamps add warm light pools, each with its own soft shadow, so the term runs from 0 to 2 and is written at
// half scale for the blur pass's double-modulate blend.
layout(set = 2, binding = 0) uniform sampler2D depthMap;
layout(set = 2, binding = 1) uniform sampler2D groundMap;
layout(set = 2, binding = 2) uniform sampler2D heightMap;
layout(set = 2, binding = 3) uniform sampler2D indoorMap;
layout(set = 2, binding = 4) uniform sampler2D footMap;
layout(set = 2, binding = 6) uniform sampler2D overheadMap;
layout(set = 2, binding = 5) uniform sampler2D liftMap;  // where the season pass found the snow's surface
layout(set = 2, binding = 7) uniform sampler2D worldDepthMap;
layout(set = 2, binding = 8) uniform sampler2D worldBackDepthMap;
layout(set = 2, binding = 9) uniform sampler2D voxelMap;
layout(set = 2, binding = 10) uniform sampler2D simMaskMap;
layout(set = 2, binding = 11) uniform sampler2D sceneColorMap;
layout(set = 2, binding = 12) uniform sampler2D bounceMap;
layout(set = 2, binding = 13) uniform sampler2D sunShadowMap;
#include "ambientUniforms.glsl"
layout(location = 0) out vec4 color;
#include "lotSurface.glsl"
#include "architecture.glsl"

const float PI = 3.14159265;
const int SLICES = 4;
const int STEPS = 4;
const int SHADOW_STEPS = 120;
const float MAX_CASTER_HEIGHT = 10.5;
const int LAMP_STEPS = 16;
const int LAMP_MARCH_STEPS = 32;
const int CONTACT_DIRECTIONS = 8;
const int CONTACT_STEPS = 3;


// How far a surface at depth z under a screen pixel stands above the terrain, in scene pixels up the screen: its depth
// gap to the terrain behind it over the terrain's own depth slope down the screen (a vertical rise r on screen moves a
// surface a third as far toward the camera as the terrain behind it falls back, so the gap is 4/3 of the slope times r).
float riseAt(vec2 pixel, float z) {
    float ground = groundAt(pixel);
    float below = groundAt(pixel + vec2(0.0, 4.0));
    if (ground < -1.0e4 || below < -1.0e4) return 0.0;
    float slope = (below - ground) * ambient.view.z / 4.0;
    return slope > 0.1 ? max(0.0, (z - ground) / (slope * 4.0 / 3.0)) : 0.0;
}

float noise(vec2 pixel) { return fract(52.9829189 * fract(dot(pixel, vec2(0.06711056, 0.00583715)))); }

// Value noise eased to the fifth power, whose slope is smooth across the cells too, so outlines cut from it stay round.
float smoothNoise(vec2 q) {
    vec2 i = floor(q), f = fract(q);
    f = f * f * f * (f * (f * 6.0 - 15.0) + 10.0);
    return mix(mix(hash12(i), hash12(i + vec2(1, 0)), f.x), mix(hash12(i + vec2(0, 1)), hash12(i + vec2(1, 1)), f.x), f.y);
}

// What the camera sees at a lot point. x: how surely the point is hidden (0 where the camera sees past it to a surface
// behind, 1 where a surface stands in front of it or it is off screen); the height map only knows the top of what
// stands over each spot, and a point the camera sees through, such as a gap between leaves, is empty. y: how surely the
// point lies inside a sprite seen in front of it, taking each sprite pixel as a shell SHELL_DEPTH deep: a tree's canopy
// reconstructs as a thin sheet, so this is what lets its silhouette, gaps and all, cast.
vec2 hiddenAtWorld(vec2 wp, float key, vec2 wSize, float shellDepth, float frontSoft) {
    if (any(lessThan(wp, vec2(1.0))) || any(greaterThanEqual(wp, wSize - 1.0))) return vec2(0.0);
    vec2 uv = wp / wSize;
    vec4 wFront = textureGather(worldDepthMap, uv);
    if (min(min(wFront.x, wFront.y), min(wFront.z, wFront.w)) >= 0.9999) return vec2(0.0);
    vec2 f = fract(wp - 0.5);
    float backSoft = max(0.13, 0.48 * shellDepth);
    vec4 vFront = step(wFront, vec4(0.9999));
    vec4 bFront = (0.62 - wFront) / 0.003 - key;
    vec4 vis = vFront * smoothstep(0.38 * shellDepth, 0.82 * shellDepth, bFront)
                      * (1.0 - smoothstep(1.85, 2.75, bFront));
    vec4 shlF = vFront * clamp((bFront + 0.55 * frontSoft) / frontSoft, 0.0, 1.0)
                       * clamp((shellDepth - bFront) / backSoft, 0.0, 1.0);
    vec4 shl = shlF;
    if (min(min(shlF.x, shlF.y), min(shlF.z, shlF.w)) < 0.99) {
        vec4 wBack = textureGather(worldBackDepthMap, uv);
        vec4 vBack = step(vec4(0.0001), wBack) * step(wBack, vec4(0.9999));
        vec4 bBack = (0.62 - wBack) / 0.003 - key;
        vec4 shlB = vBack * clamp((bBack + 0.55 * frontSoft) / frontSoft, 0.0, 1.0)
                          * clamp((shellDepth - bBack) / backSoft, 0.0, 1.0);
        shl = max(shlF, shlB);
    }
    return vec2(
        mix(mix(vis.w, vis.z, f.x), mix(vis.x, vis.y, f.x), f.y),
        mix(mix(shl.w, shl.z, f.x), mix(shl.x, shl.y, f.x), f.y));
}

vec2 hiddenAtSoft(vec3 q, float spreadPx, vec2 rayPerp, vec2 rayDirPx, float keyPerPx, float shellDepth, float frontSoft, vec2 diskJitter) {
    vec2 scene = vec2(32.0 * (q.x - q.y), 16.0 * (q.x + q.y) - 40.0 * q.z) + ambient.frame.xy;
    float key = q.x + q.y + 0.8 * q.z;
    if (ambient.shadowView.w > 0.5) {
        vec2 wSize = vec2(textureSize(worldDepthMap, 0));
        vec2 wp = ambient.shadowView.xy + scene * ambient.shadowView.z;
        float w1 = smoothstep(0.25, 1.00, spreadPx);
        float r = spreadPx * w1;
        vec2 off = rayPerp * (diskJitter.x * r) + rayDirPx * (diskJitter.y * 0.78 * r);
        float kOff = keyPerPx * (diskJitter.y * 0.78 * r);
        return hiddenAtWorld(wp + off, key + kOff, wSize, shellDepth, frontSoft);
    }
    vec2 pixel = floor(ambient.view.xy + scene * ambient.view.z) + 0.5;
    if (any(lessThan(pixel, vec2(0.0))) || pixel.x >= ambient.extent.x || pixel.y >= ambient.extent.y) return vec2(1.0, 0.0);
    float depth = texelFetch(depthMap, ivec2(pixel), 0).r;
    if (depth < 1.0) {
        float behind = (0.62 - depth) / 0.003 - key;
        float backSoft = max(0.14, 0.48 * shellDepth);
        return vec2(clamp((behind + 0.06) / 0.18, 0.0, 1.0),
                    clamp((behind + 0.55 * frontSoft) / frontSoft, 0.0, 1.0) * clamp((shellDepth - behind) / backSoft, 0.0, 1.0));
    }
    float ground = texelFetch(groundMap, ivec2(pixel), 0).r;
    if (ground >= 1.0) return vec2(0.0);
    vec3 lot = lotPoint(scene, (0.62 - ground) / 0.003 + ambient.view.w, true, ambient.frame.xy);
    return vec2(clamp((lot.x + lot.y + 0.8 * lot.z - key + 0.4) / 0.3, 0.0, 1.0), 0.0);
}


// Where sun through a window lands: from an indoor lot point, walk the tiles toward the sun along the floor until the
// room ends. The wall there lets the sun in if a window has parts on both sides of it and the ray crosses it between the
// sill and the lintel, across the middle of the tile (the glass). Returns the opening (0 to 1) and a point 1.5 tiles past
// the wall, clear of the house's own eaves, from which the sun is marched on outside (height map only); heights are taken from the floor of the point's story. The sill and
// lintel heights are inferred from the window sprites.
const float WINDOW_SILL = 0.75;
const float WINDOW_TOP = 2.35;
// Cloud shadows: a drifting field of soft value noise fixed to the lot (not the camera), sampled where the ray toward
// the sun crosses the cloud layer, so the shade slides across the ground as the clouds blow and the sun moves. Returns
// how much of the sun's light the clouds let through.
float cloudLight(vec3 lot) {
    float cover = ambient.clouds.x;
    if (cover <= 0.0 || ambient.clouds.y <= 0.0) return 1.0;
    vec3 sun = ambient.sunLot.xyz;
    float cloudH = max(ambient.clouds.w, lot.z + 4.0);
    vec2 source = lotSource(lot.xy + sun.xy * (cloudH - lot.z) / max(sun.z, 0.25));
    vec2 q = (source - ambient.drift.xy) / 9.0;
    float field = 0.5 * valueNoise(q) + 0.25 * valueNoise(q * 2.03 + 17.0) + 0.15 * valueNoise(q * 4.01 + 41.0) + 0.1 * valueNoise(q * 8.05 + 7.0);
    float threshold = mix(0.72, 0.18, cover);
    float density = smoothstep(threshold - 0.08, threshold + 0.1, field);
    return 1.0 - ambient.clouds.y * density;
}

int effectiveRoomAt(ivec2 cell, int row, vec2 localU) {
    int code = maskCatAt(cell, 0, row);
    int room = code >> 1;
    if (room == 0) return 0;
    int part = maskCatAt(cell, 2, row) & 7;
    if (part == 0) return room;
    vec2 toward = part == 1 ? vec2(1.0, -1.0) : part == 2 ? vec2(-1.0, 1.0) : part == 3 ? vec2(-1.0) : vec2(1.0);
    return dot(localU - 0.5, toward) >= 0.0 ? room : 0;
}

int storyRowAt(ivec2 cell, float z, float fallbackBase, float margin) {
    int stories = indoorStories();
    float base0 = floorAt(cell, 0, fallbackBase);
    return clamp(int(floor((z - base0 + margin) / STORY_HEIGHT)), 0, stories - 1);
}

// How surely a room around a lot point is lit at night, 0 to 1, plus the share of firelight (0..1) in that source.
vec2 lampNearInfo(vec3 q) {
    vec2 at = sceneOf(q);
    float best = 0.0;
    float bestFire = 0.0;
    int lampCount = int(ambient.lamp.x);
    for (int index = 0; index < MAX_LAMPS; index++) {
        if (index >= lampCount) break;
        vec4 lamp = ambient.lamps[index];
        bool isFire = lamp.w < 0.0;
        float strength = abs(lamp.w);
        float hit = strength * clamp(1.0 - length(lamp.xy - at) / (0.8 * ambient.lamp.y * (isFire ? 1.15 : 1.0)), 0.0, 1.0);
        best = max(best, hit);
        if (isFire) bestFire = max(bestFire, hit);
    }
    return vec2(clamp(best * 2.0, 0.0, 1.0), best > 1e-4 ? clamp(bestFire / best, 0.0, 1.0) : 0.0);
}

float lampNear(vec3 q) { return lampNearInfo(q).x; }

// Lit windows at night: warm light spilling from a lit room through its windows onto the outdoor ground in front, fading
// out to two and a half tiles, starting a tile out where light over the sill first reaches the ground. A window is the wall between two tiles that both hold window parts, an indoor room on one
// side and outside on the other (as throughWindow reads them); the room counts as lit where a lamp or fire stands near it.
// Returns vec2(spillAmount, fireShare).
vec2 windowSpillInfo(vec3 here, float onGround) {
    vec2 at = here.xy + ambient.frame.w;
    ivec2 cell = ivec2(floor(at));
    float ground = floorAt(cell, 0, here.z);
    if (onGround <= 0.5 || here.z > ground + STORY_HEIGHT - 0.1 || maskAt(cell, 0) >= 2) return vec2(0.0);
    float best = 0.0;
    vec3 source = vec3(0.0), glass = vec3(0.0);
    for (int y = -3; y <= 3; y++) {
        for (int x = -3; x <= 3; x++) {
            ivec2 room = cell + ivec2(x, y);
            int code = maskAt(room, 0);
            if (code < 2 || (code & 1) == 0) continue;
            for (int d = 0; d < 4; d++) {
                ivec2 step = d == 0 ? ivec2(1, 0) : d == 1 ? ivec2(-1, 0) : d == 2 ? ivec2(0, 1) : ivec2(0, -1);
                int outside = maskAt(room + step, 0);
                if (outside >= 2 || (outside & 1) == 0) continue;
                // Out from the middle of the shared edge (the glass) over the ground, and along the wall past the glass.
                vec2 offset = at - (vec2(room) + 0.5 + vec2(step) * 0.5);
                float out_ = dot(offset, vec2(step));
                if (out_ < 0.0) continue;
                float side = max(0.0, abs(dot(offset, vec2(step.y, step.x))) - 0.3);
                float fall = max(0.0, 1.0 - length(vec2(out_, side)) / 2.6);
                // The wall below the sill hides the ground near it: light from a tile inside the room, 1.5 above the
                // floor, crosses the wall at 1.5 out / (out + 1), which must clear the sill.
                float clear = smoothstep(WINDOW_SILL - 0.1, WINDOW_SILL + 0.15, 1.5 * out_ / (out_ + 1.0));
                if (fall * fall * clear > best) {
                    best = fall * fall * clear;
                    source = vec3(vec2(room) + 0.5 - ambient.frame.w, ground + 1.5);
                    glass = vec3(vec2(room) + 0.5 + vec2(step) * 0.5 - ambient.frame.w, ground + 1.4);
                }
            }
        }
    }
    if (best <= 0.0) return vec2(0.0);
    // Shadowed like a lamp's light: whatever the height map raises between the ground and the glass blocks it, up to
    // a third of a tile short of the wall, which the height map holds too.
    vec2 gridSize = vec2(textureSize(heightMap, 0));
    vec2 toGlass = glass.xy - here.xy;
    float span = length(toGlass);
    if (span < 0.4) {
        vec2 info = lampNearInfo(source);
        return vec2(best * info.x, info.y);
    }
    vec3 end = vec3(glass.xy - toGlass / span * 0.35, glass.z);
    float open = 1.0;
    for (int i = 1; i <= 6; i++) {
        vec3 q = mix(here, end, float(i) / 6.0);
        float top = (0.5 - texture(heightMap, (q.xy + ambient.frame.w) * ambient.frame.z / gridSize).r) * HEIGHT_RANGE;
        open = min(open, 1.0 - clamp((top - q.z - 0.1) / 0.3, 0.0, 1.0));
    }
    vec2 info = lampNearInfo(source);
    return vec2(best * open * info.x, info.y);
}

float windowSpill(vec3 here, float onGround) { return windowSpillInfo(here, onGround).x; }

// Bilinear 2x2 exact 4-view [backKey, frontKey] depth-interval sample for one slice of voxelMap.
float sampleHullSlice(vec2 op, float key, int yOffset, ivec2 sliceMax, float pad) {
    vec2 p = op - 0.5;
    ivec2 i0 = ivec2(floor(p));
    vec2 f = clamp(p - vec2(i0), 0.0, 1.0);
    ivec2 c00 = clamp(i0, ivec2(0), sliceMax);
    ivec2 c10 = clamp(i0 + ivec2(1, 0), ivec2(0), sliceMax);
    ivec2 c01 = clamp(i0 + ivec2(0, 1), ivec2(0), sliceMax);
    ivec2 c11 = clamp(i0 + ivec2(1, 1), ivec2(0), sliceMax);

    ivec4 r00 = ivec4(texelFetch(voxelMap, ivec2(c00.x, c00.y + yOffset), 0) * 255.0 + 0.5);
    ivec4 r10 = ivec4(texelFetch(voxelMap, ivec2(c10.x, c10.y + yOffset), 0) * 255.0 + 0.5);
    ivec4 r01 = ivec4(texelFetch(voxelMap, ivec2(c01.x, c01.y + yOffset), 0) * 255.0 + 0.5);
    ivec4 r11 = ivec4(texelFetch(voxelMap, ivec2(c11.x, c11.y + yOffset), 0) * 255.0 + 0.5);

    int f00 = r00.r * 256 + r00.g;
    int f10 = r10.r * 256 + r10.g;
    int f01 = r01.r * 256 + r01.g;
    int f11 = r11.r * 256 + r11.g;
    if ((f00 | f10 | f01 | f11) == 0) return 0.0;

    float v00 = f00 == 0 ? 0.0 : smoothstep(-pad, 0.04, (float(f00) / 256.0 - 16.0) - key) * smoothstep(-pad, 0.04, key - (float(r00.b * 256 + r00.a) / 256.0 - 16.0));
    float v10 = f10 == 0 ? 0.0 : smoothstep(-pad, 0.04, (float(f10) / 256.0 - 16.0) - key) * smoothstep(-pad, 0.04, key - (float(r10.b * 256 + r10.a) / 256.0 - 16.0));
    float v01 = f01 == 0 ? 0.0 : smoothstep(-pad, 0.04, (float(f01) / 256.0 - 16.0) - key) * smoothstep(-pad, 0.04, key - (float(r01.b * 256 + r01.a) / 256.0 - 16.0));
    float v11 = f11 == 0 ? 0.0 : smoothstep(-pad, 0.04, (float(f11) / 256.0 - 16.0) - key) * smoothstep(-pad, 0.04, key - (float(r11.b * 256 + r11.a) / 256.0 - 16.0));
    return mix(mix(v00, v10, f.x), mix(v01, v11, f.x), f.y);
}

int voxelAoRows(ivec2 oSize) {
    int aoSize = max(1, oSize.x / 4);
    return max(1, (oSize.y - oSize.x - 256) / (512 + aoSize));
}

float dualViewHullAtPrecomp(vec3 q, ivec2 oSize, int halfH, float topMarginHalf, ivec2 sliceMax, vec2 lotSz, float spreadPx) {
    float pad = 0.18 + 0.02 * spreadPx;
    vec2 op0 = vec2((q.x - q.y + lotSz.x) * 16.0, (q.x + q.y) * 8.0 - q.z * 20.0 + topMarginHalf);
    if (any(lessThan(op0, vec2(0.0))) || op0.x >= float(oSize.x) || op0.y >= float(halfH)) return 0.0;
    float key0 = q.x + q.y + 0.8 * q.z;
    float in0 = sampleHullSlice(op0, key0, 0, sliceMax, pad);
    if (in0 <= 0.01) return 0.0;

    vec3 qB = vec3(lotSz.y - q.y, q.x, q.z);
    vec2 op1 = vec2((qB.x - qB.y + lotSz.x) * 16.0, (qB.x + qB.y) * 8.0 - qB.z * 20.0 + topMarginHalf);
    if (any(lessThan(op1, vec2(0.0))) || op1.x >= float(oSize.x) || op1.y >= float(halfH)) return 0.0;
    float key1 = qB.x + qB.y + 0.8 * qB.z;
    float in1 = sampleHullSlice(op1, key1, halfH, sliceMax, pad);
    return min(in0, in1);
}

float dualViewHullAt(vec3 q, ivec2 oSize, vec2 lotSz, vec2 jitter, float spreadPx) {
    int aoRows = voxelAoRows(oSize);
    int halfH = oSize.x / 2 + 128 + 256 * aoRows;
    float topMarginHalf = float(64 + 256 * aoRows);
    ivec2 sliceMax = ivec2(oSize.x - 1, halfH - 1);
    return dualViewHullAtPrecomp(q, oSize, halfH, topMarginHalf, sliceMax, lotSz, spreadPx);
}

// Exact 3D front-to-back depth-interval test for dynamic 3D Sim meshes (worldDepthMap + worldBackDepthMap).
float dynamicSimOccAt(vec3 q, float pad) {
    if (ambient.shadowView.w <= 0.5) return 0.0;
    vec2 scene = vec2(32.0 * (q.x - q.y), 16.0 * (q.x + q.y) - 40.0 * q.z) + ambient.frame.xy;
    vec2 wSize = vec2(textureSize(worldDepthMap, 0));
    vec2 wp = ambient.shadowView.xy + scene * ambient.shadowView.z;
    if (any(lessThan(wp, vec2(0.5))) || any(greaterThanEqual(wp, wSize - 0.5))) return 0.0;
    vec2 uv = wp / wSize;
    vec4 wFront = textureGather(worldDepthMap, uv);
    if (min(min(wFront.x, wFront.y), min(wFront.z, wFront.w)) >= 0.9999) return 0.0;
    vec4 wBack = textureGather(worldBackDepthMap, uv);
    float key = q.x + q.y + 0.8 * q.z;
    vec4 valid = step(wFront, vec4(0.9999)) * step(vec4(0.0001), wBack);
    vec4 fKey = (0.62 - wFront) / 0.003;
    vec4 bKey = (0.62 - wBack) / 0.003;
    vec4 inSim = valid * smoothstep(-pad, 0.04, fKey - key) * smoothstep(-pad, 0.04, key - bKey);
    vec2 f = fract(wp - 0.5);
    return mix(mix(inSim.w, inSim.z, f.x), mix(inSim.x, inSim.y, f.x), f.y);
}

float sampleHullDilated(vec2 op, float key, int yOffset, ivec2 sliceMax, float pad) {
    ivec2 center = ivec2(floor(op));
    float best = 0.0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            ivec2 c = clamp(center + ivec2(dx, dy), ivec2(0), sliceMax);
            ivec4 r = ivec4(texelFetch(voxelMap, ivec2(c.x, c.y + yOffset), 0) * 255.0 + 0.5);
            int f = r.r * 256 + r.g;
            if (f == 0) continue;
            float frontKey = float(f) / 256.0 - 16.0;
            float backKey = float(r.b * 256 + r.a) / 256.0 - 16.0;
            float v = smoothstep(-pad, 0.06, frontKey - key) * smoothstep(-pad, 0.06, key - backKey);
            best = max(best, v);
        }
    }
    return best;
}

float dualViewHullSolid(vec3 q, ivec2 oSize, int halfH, float topMarginHalf, ivec2 sliceMax, vec2 lotSz, float pad) {
    vec2 op0 = vec2((q.x - q.y + lotSz.x) * 16.0, (q.x + q.y) * 8.0 - q.z * 20.0 + topMarginHalf);
    if (any(lessThan(op0, vec2(0.0))) || op0.x >= float(oSize.x) || op0.y >= float(halfH)) return 0.0;
    float in0 = sampleHullDilated(op0, q.x + q.y + 0.8 * q.z, 0, sliceMax, pad);
    if (in0 <= 0.01) return 0.0;
    vec3 qB = vec3(lotSz.y - q.y, q.x, q.z);
    vec2 op1 = vec2((qB.x - qB.y + lotSz.x) * 16.0, (qB.x + qB.y) * 8.0 - qB.z * 20.0 + topMarginHalf);
    if (any(lessThan(op1, vec2(0.0))) || op1.x >= float(oSize.x) || op1.y >= float(halfH)) return 0.0;
    float in1 = sampleHullDilated(op1, qB.x + qB.y + 0.8 * qB.z, halfH, sliceMax, pad);
    return min(in0, in1);
}

float dynamicSimOccFast(vec3 q, float pad) {
    if (ambient.shadowView.w <= 0.5) return 0.0;
    vec2 scene = vec2(32.0 * (q.x - q.y), 16.0 * (q.x + q.y) - 40.0 * q.z) + ambient.frame.xy;
    vec2 wSize = vec2(textureSize(worldDepthMap, 0));
    vec2 wp = ambient.shadowView.xy + scene * ambient.shadowView.z;
    if (any(lessThan(wp, vec2(0.5))) || any(greaterThanEqual(wp, wSize - 0.5))) return 0.0;
    ivec2 c = ivec2(floor(wp));
    float wFront = texelFetch(worldDepthMap, c, 0).r;
    if (wFront >= 0.9999) return 0.0;
    float wBack = texelFetch(worldBackDepthMap, c, 0).r;
    if (wBack <= 0.0001 || wBack >= 0.9999) return 0.0;
    float key = q.x + q.y + 0.8 * q.z;
    float fKey = (0.62 - wFront) / 0.003;
    float bKey = (0.62 - wBack) / 0.003;
    return smoothstep(-pad, 0.04, fKey - key) * smoothstep(-pad, 0.04, key - bKey);
}

float dynamicSimOccInterval(vec2 wp, vec2 wSize, float kMin, float kMax, float pad) {
    if (any(lessThan(wp, vec2(0.5))) || any(greaterThanEqual(wp, wSize - 0.5))) return 0.0;
    vec2 uv = wp / wSize;
    vec4 wFront = textureGather(worldDepthMap, uv);
    if (min(min(wFront.x, wFront.y), min(wFront.z, wFront.w)) >= 0.9999) return 0.0;
    vec4 wBack = textureGather(worldBackDepthMap, uv);
    vec4 valid = step(wFront, vec4(0.9999)) * step(vec4(0.0001), wBack);
    vec4 fKey = (0.62 - wFront) / 0.003;
    vec4 bKey = (0.62 - wBack) / 0.003;
    vec4 inSim = valid * smoothstep(-pad, 0.05, fKey - kMin) * smoothstep(-pad, 0.05, kMax - bKey);
    vec2 f = fract(wp - 0.5);
    return mix(mix(inSim.w, inSim.z, f.x), mix(inSim.x, inSim.y, f.x), f.y);
}

void stepSimCone2(vec3 qMid, vec3 dQ, float pad, float rPx, vec2 sunPerp, float distFade, vec2 wSize, inout vec2 simLaneLit) {
    if (ambient.shadowView.w <= 0.5) return;
    vec2 sceneMid = vec2(32.0 * (qMid.x - qMid.y), 16.0 * (qMid.x + qMid.y) - 40.0 * qMid.z) + ambient.frame.xy;
    vec2 wpMid = ambient.shadowView.xy + sceneMid * ambient.shadowView.z;
    float rBound = 0.5 * rPx + 2.0;
    if (wpMid.x < ambient.dynShadowBounds.x - rBound || wpMid.y < ambient.dynShadowBounds.y - rBound ||
        wpMid.x > ambient.dynShadowBounds.z + rBound || wpMid.y > ambient.dynShadowBounds.w + rBound) return;
    if (any(lessThan(wpMid, vec2(-3.0))) || any(greaterThanEqual(wpMid, wSize + 3.0))) return;
    float kMid = qMid.x + qMid.y + 0.8 * qMid.z;
    float dkHalf = 0.5 * abs(dQ.x + dQ.y + 0.8 * dQ.z);
    float kMin = kMid - dkHalf;
    float kMax = kMid + dkHalf;
    if (rPx <= 1.25) {
        if (max(simLaneLit.x, simLaneLit.y) > 0.006) {
            float occ = dynamicSimOccInterval(wpMid, wSize, kMin, kMax, pad) * distFade;
            simLaneLit = min(simLaneLit, vec2(1.0 - occ));
        }
        return;
    }
    vec2 off = sunPerp * (0.45 * rPx);
    if (simLaneLit.x > 0.006) {
        float occ0 = dynamicSimOccInterval(wpMid - off, wSize, kMin, kMax, pad) * distFade;
        simLaneLit.x = min(simLaneLit.x, 1.0 - occ0);
    }
    if (simLaneLit.y > 0.006) {
        float occ1 = dynamicSimOccInterval(wpMid + off, wSize, kMin, kMax, pad) * distFade;
        simLaneLit.y = min(simLaneLit.y, 1.0 - occ1);
    }
}

float sampleHullIntervalSlice(vec2 op, float kMin, float kMax, float pad, float kTop, int yOffset, ivec2 sliceMax, vec2 invVSize) {
    vec2 p = op - 0.5;
    ivec2 i0 = ivec2(floor(p));
    ivec2 gi = clamp(i0, ivec2(0), max(sliceMax - 1, ivec2(0)));
    vec2 gUv = (vec2(gi) + vec2(1.0, float(yOffset) + 1.0)) * invVSize;
    vec4 gR = textureGather(voxelMap, gUv, 0) * 255.0;
    float maxR = max(max(gR.x, gR.y), max(gR.z, gR.w));
    if (maxR < 0.5 || (maxR - 14.9) < kMin - pad) return 0.0;
    vec4 gB = textureGather(voxelMap, gUv, 2) * 255.0;
    bvec4 cand = bvec4(
        gR.x > 0.5 && (gR.x - 14.9) >= kMin - pad && (gB.x - 16.1) <= kMax + pad,
        gR.y > 0.5 && (gR.y - 14.9) >= kMin - pad && (gB.y - 16.1) <= kMax + pad,
        gR.z > 0.5 && (gR.z - 14.9) >= kMin - pad && (gB.z - 16.1) <= kMax + pad,
        gR.w > 0.5 && (gR.w - 14.9) >= kMin - pad && (gB.w - 16.1) <= kMax + pad);
    if (!any(cand)) return 0.0;

    vec2 f = clamp(p - vec2(i0), 0.0, 1.0);
    if (all(equal(gi, i0))) {
        vec4 gG = textureGather(voxelMap, gUv, 1) * 255.0;
        vec4 gA = textureGather(voxelMap, gUv, 3) * 255.0;
        vec4 fCode = floor(gR + 0.5) * 256.0 + floor(gG + 0.5);
        vec4 bCode = floor(gB + 0.5) * 256.0 + floor(gA + 0.5);
        vec4 fk = fCode * (1.0 / 256.0) - 16.0;
        vec4 bk = bCode * (1.0 / 256.0) - 16.0;
        vec4 nz = step(vec4(0.5), fCode);
        vec4 vv = nz * smoothstep(vec4(-pad), vec4(kTop), fk - kMin) * smoothstep(vec4(-pad), vec4(kTop), kMax - bk);
        return mix(mix(vv.w, vv.z, f.x), mix(vv.x, vv.y, f.x), f.y);
    }

    ivec2 c00 = clamp(i0, ivec2(0), sliceMax);
    ivec2 c10 = clamp(i0 + ivec2(1, 0), ivec2(0), sliceMax);
    ivec2 c01 = clamp(i0 + ivec2(0, 1), ivec2(0), sliceMax);
    ivec2 c11 = clamp(i0 + ivec2(1, 1), ivec2(0), sliceMax);

    ivec4 r00 = ivec4(texelFetch(voxelMap, ivec2(c00.x, c00.y + yOffset), 0) * 255.0 + 0.5);
    ivec4 r10 = ivec4(texelFetch(voxelMap, ivec2(c10.x, c10.y + yOffset), 0) * 255.0 + 0.5);
    ivec4 r01 = ivec4(texelFetch(voxelMap, ivec2(c01.x, c01.y + yOffset), 0) * 255.0 + 0.5);
    ivec4 r11 = ivec4(texelFetch(voxelMap, ivec2(c11.x, c11.y + yOffset), 0) * 255.0 + 0.5);

    int f00 = r00.r * 256 + r00.g;
    int f10 = r10.r * 256 + r10.g;
    int f01 = r01.r * 256 + r01.g;
    int f11 = r11.r * 256 + r11.g;
    if ((f00 | f10 | f01 | f11) == 0) return 0.0;

    float v00 = f00 == 0 ? 0.0 : smoothstep(-pad, kTop, (float(f00) / 256.0 - 16.0) - kMin) * smoothstep(-pad, kTop, kMax - (float(r00.b * 256 + r00.a) / 256.0 - 16.0));
    float v10 = f10 == 0 ? 0.0 : smoothstep(-pad, kTop, (float(f10) / 256.0 - 16.0) - kMin) * smoothstep(-pad, kTop, kMax - (float(r10.b * 256 + r10.a) / 256.0 - 16.0));
    float v01 = f01 == 0 ? 0.0 : smoothstep(-pad, kTop, (float(f01) / 256.0 - 16.0) - kMin) * smoothstep(-pad, kTop, kMax - (float(r01.b * 256 + r01.a) / 256.0 - 16.0));
    float v11 = f11 == 0 ? 0.0 : smoothstep(-pad, kTop, (float(f11) / 256.0 - 16.0) - kMin) * smoothstep(-pad, kTop, kMax - (float(r11.b * 256 + r11.a) / 256.0 - 16.0));
    return mix(mix(v00, v10, f.x), mix(v01, v11, f.x), f.y);
}

float evalHullInterval3D(vec3 qSub, vec3 halfStepQ, float pad, float kTop, ivec2 oSize, int halfH, float topMarginHalf, ivec2 sliceMax, vec2 lotSz, vec2 invVSize) {
    vec2 op0 = vec2((qSub.x - qSub.y + lotSz.x) * 16.0, (qSub.x + qSub.y) * 8.0 - qSub.z * 20.0 + topMarginHalf);
    if (any(lessThan(op0, vec2(0.0))) || op0.x >= float(oSize.x) || op0.y >= float(halfH)) return 0.0;
    float k0Mid = qSub.x + qSub.y + 0.8 * qSub.z;
    float dk0 = abs(halfStepQ.x + halfStepQ.y + 0.8 * halfStepQ.z);
    float in0 = sampleHullIntervalSlice(op0, k0Mid - dk0, k0Mid + dk0, pad, kTop, 0, sliceMax, invVSize);
    if (in0 <= 0.005) return 0.0;

    vec3 qB = vec3(lotSz.y - qSub.y, qSub.x, qSub.z);
    vec2 op1 = vec2((qB.x - qB.y + lotSz.x) * 16.0, (qB.x + qB.y) * 8.0 - qB.z * 20.0 + topMarginHalf);
    if (any(lessThan(op1, vec2(0.0))) || op1.x >= float(oSize.x) || op1.y >= float(halfH)) return 0.0;
    float k1Mid = qB.x + qB.y + 0.8 * qB.z;
    float dk1 = abs(-halfStepQ.y + halfStepQ.x + 0.8 * halfStepQ.z);
    float in1 = sampleHullIntervalSlice(op1, k1Mid - dk1, k1Mid + dk1, pad, kTop, halfH, sliceMax, invVSize);
    return min(in0, in1);
}

bool voxelColumnOverlap(vec2 xy, float qMinZ, float qMaxZ, int vAoSize, int vAoYBase, vec2 lotSz) {
    if (xy.x < -0.45 || xy.y < -0.45 || xy.x > lotSz.x + 0.45 || xy.y > lotSz.y + 0.45) return false;
    ivec2 cg = clamp(ivec2(floor(xy * 8.0)), ivec2(0), ivec2(vAoSize - 1));
    int y = vAoYBase + cg.y;
    int allMaxB = int(texelFetch(voxelMap, ivec2(cg.x, y), 0).a * 255.0 + 0.5);
    if (allMaxB == 0 || qMinZ > float(allMaxB - 1) * 0.125 - 3.62) return false;
    int allMinB = int(texelFetch(voxelMap, ivec2(vAoSize + cg.x, y), 0).a * 255.0 + 0.5);
    if (allMinB > 0 && qMaxZ < float(allMinB - 1) * 0.125 - 4.38) return false;
    int s1MaxB = int(texelFetch(voxelMap, ivec2(2 * vAoSize + cg.x, y), 0).a * 255.0 + 0.5);
    if (s1MaxB == 0 || qMinZ > float(s1MaxB - 1) * 0.125 - 3.62) {
        int upMinB = int(texelFetch(voxelMap, ivec2(3 * vAoSize + cg.x, y), 0).a * 255.0 + 0.5);
        if (upMinB == 0 || qMaxZ < float(upMinB - 1) * 0.125 - 4.38) return false;
    }
    return true;
}

void stepHullCone4(
    vec3 qMid,
    vec3 dQ,
    vec3 coneU,
    vec3 coneV,
    float rTiles,
    float pad,
    float kTop,
    float distFade,
    ivec2 oSize,
    int halfH,
    float topMarginHalf,
    ivec2 sliceMax,
    vec2 lotSz,
    vec2 invVSize,
    inout vec4 laneLit
) {
    float marginPx = rTiles * 24.0 + 3.0;
    vec2 op0Mid = vec2((qMid.x - qMid.y + lotSz.x) * 16.0, (qMid.x + qMid.y) * 8.0 - qMid.z * 20.0 + topMarginHalf);
    if (any(lessThan(op0Mid, vec2(-marginPx))) || op0Mid.x >= float(oSize.x) + marginPx || op0Mid.y >= float(halfH) + marginPx) return;
    vec3 qBMid = vec3(lotSz.y - qMid.y, qMid.x, qMid.z);
    vec2 op1Mid = vec2((qBMid.x - qBMid.y + lotSz.x) * 16.0, (qBMid.x + qBMid.y) * 8.0 - qBMid.z * 20.0 + topMarginHalf);
    if (any(lessThan(op1Mid, vec2(-marginPx))) || op1Mid.x >= float(oSize.x) + marginPx || op1Mid.y >= float(halfH) + marginPx) return;

    vec3 halfStepQ = 0.5 * dQ;
    if (rTiles <= 0.048) {
        if (max(max(laneLit.x, laneLit.y), max(laneLit.z, laneLit.w)) > 0.006) {
            float occC = evalHullInterval3D(qMid, halfStepQ, pad, kTop, oSize, halfH, topMarginHalf, sliceMax, lotSz, invVSize) * distFade;
            laneLit = min(laneLit, vec4(1.0 - occC));
        }
        return;
    }
    vec3 uScaled = coneU * rTiles;
    vec3 vScaled = coneV * rTiles;
    vec3 offA = uScaled * 0.56 + vScaled * 0.24;
    vec3 offB = -uScaled * 0.24 + vScaled * 0.56;
    if (laneLit.x > 0.006) {
        float occ0 = evalHullInterval3D(qMid - offA, halfStepQ, pad, kTop, oSize, halfH, topMarginHalf, sliceMax, lotSz, invVSize) * distFade;
        laneLit.x = min(laneLit.x, 1.0 - occ0);
    }
    if (laneLit.y > 0.006) {
        float occ1 = evalHullInterval3D(qMid - offB, halfStepQ, pad, kTop, oSize, halfH, topMarginHalf, sliceMax, lotSz, invVSize) * distFade;
        laneLit.y = min(laneLit.y, 1.0 - occ1);
    }
    if (laneLit.z > 0.006) {
        float occ2 = evalHullInterval3D(qMid + offB, halfStepQ, pad, kTop, oSize, halfH, topMarginHalf, sliceMax, lotSz, invVSize) * distFade;
        laneLit.z = min(laneLit.z, 1.0 - occ2);
    }
    if (laneLit.w > 0.006) {
        float occ3 = evalHullInterval3D(qMid + offA, halfStepQ, pad, kTop, oSize, halfH, topMarginHalf, sliceMax, lotSz, invVSize) * distFade;
        laneLit.w = min(laneLit.w, 1.0 - occ3);
    }
}

bool hasFloorSlabAt(ivec2 cell, int row, vec2 localU) {
    if (maskCatAt(cell, 1, row) == 0) return false;
    int part = maskCatAt(cell, 2, row) & 7;
    if (part == 0) return true;
    vec2 toward = part == 1 ? vec2(1.0, -1.0) : part == 2 ? vec2(-1.0, 1.0) : part == 3 ? vec2(-1.0) : vec2(1.0);
    return dot(localU - 0.5, toward) >= 0.0;
}

float lampFloorVis(vec3 here, vec3 lampLot, float onFlatFloor) {
    int stories = indoorStories();
    if (stories <= 1) return 1.0;
    ivec2 hCell = ivec2(floor(here.xy + ambient.frame.w));
    ivec2 lCell = ivec2(floor(lampLot.xy + ambient.frame.w));
    float base0 = floorAt(hCell, 0, floorAt(lCell, 0, min(here.z, lampLot.z)));
    float zMin = min(here.z, lampLot.z);
    float zMax = max(here.z, lampLot.z);
    float dz = here.z - lampLot.z;
    int sMin = max(1, int(floor((zMin - base0 - 0.30) / STORY_HEIGHT)));
    int sMax = min(stories - 1, int(ceil((zMax - base0 + 0.30) / STORY_HEIGHT)));
    for (int s = sMin; s <= sMax; s++) {
        float nomZ = base0 + float(s) * STORY_HEIGHT;
        bool between = nomZ > zMin + 0.05 && nomZ < zMax - 0.05;
        bool underReceiverFloor = onFlatFloor > 0.5 && lampLot.z < here.z - 0.20 && abs(here.z - nomZ) < 0.24;
        if (!between && !underReceiverFloor) continue;
        float t = abs(dz) > 1e-4 ? clamp((nomZ - lampLot.z) / dz, 0.0, 1.0) : 1.0;
        vec2 p = mix(lampLot.xy, here.xy, t) + ambient.frame.w;
        ivec2 c = ivec2(floor(p));
        float slabZ = floorAt(c, s, nomZ);
        bool slabBetween = slabZ > zMin + 0.05 && slabZ < zMax - 0.05;
        bool slabUnderFloor = onFlatFloor > 0.5 && lampLot.z < slabZ - 0.20 && abs(here.z - slabZ) < 0.24;
        if ((slabBetween || slabUnderFloor) && hasFloorSlabAt(c, s, p - vec2(c))) {
            return 0.0;
        }
    }
    return 1.0;
}

float lampWallVis(vec3 here, vec3 lampLot, float onFlatFloor, vec2 horizN) {
    vec2 start = here.xy + ambient.frame.w + horizN * (0.14 * (1.0 - onFlatFloor));
    vec2 end = lampLot.xy + ambient.frame.w;
    vec2 deltaXY = end - start;
    float distXY = length(deltaXY);
    if (distXY < 0.08) return 1.0;
    ivec2 maskTexSize = textureSize(indoorMap, 0);
    int maskBandH = indoorBandH(maskTexSize);
    int stories = max(1, maskTexSize.y / max(1, 5 * maskBandH));
    vec2 direction = deltaXY / distXY;
    float rise = (lampLot.z - here.z) / distXY;
    float topGuard = mix(0.0, 0.12, onFlatFloor);
    ivec2 cell = ivec2(floor(start));
    ivec2 stepDir = ivec2(sign(direction));
    vec2 safeDir = direction + vec2(equal(direction, vec2(0.0))) * 1e-5;
    vec2 stepDelta = abs(1.0 / safeDir);
    vec2 next = (vec2(cell) + max(vec2(stepDir), 0.0) - start) / safeDir;
    float maxT = distXY - 0.05;
    float vis = 1.0;
    float tPrev = 0.0;
    for (int i = 0; i < 28; i++) {
        if ((cell.x < 0 && stepDir.x <= 0) || (cell.x >= maskTexSize.x && stepDir.x >= 0) ||
            (cell.y < 0 && stepDir.y <= 0) || (cell.y >= maskBandH && stepDir.y >= 0)) break;
        bool alongX = next.x < next.y;
        float t = alongX ? next.x : next.y;
        float segEnd = min(t, maxT);
        int cellCode0 = maskCatAt(cell, 1, 0);
        if (segEnd > tPrev && cellCode0 != 0) {
            float zMid = here.z + 0.5 * (tPrev + segEnd) * rise;
            float cellBase0 = ambient.contact.w + float(cellCode0 - 1) / 8.0;
            int rowCell = clamp(int(floor((zMid - cellBase0 + 0.05) / STORY_HEIGHT)), 0, stories - 1);
            int part = maskCatAt(cell, 2, rowCell) & 7;
            if (part != 0) {
                float denom = part <= 2 ? (direction.x - direction.y) : (direction.x + direction.y);
                if (abs(denom) > 1e-4) {
                    float tDiag = part <= 2
                        ? ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom
                        : (1.0 - (start.x - float(cell.x)) - (start.y - float(cell.y))) / denom;
                    if (tDiag > max(tPrev, 0.03) && tDiag <= segEnd + 1e-4) {
                        vec2 uDiag = start + direction * tDiag - vec2(cell);
                        if (all(greaterThanEqual(uDiag, vec2(-0.01))) && all(lessThanEqual(uDiag, vec2(1.01)))) {
                            float floorH = rowCell == 0 ? cellBase0 : floorAt(cell, rowCell, cellBase0 + float(rowCell) * STORY_HEIGHT);
                            if (min(here.z, lampLot.z) < floorH + STORY_HEIGHT - topGuard) {
                                float relH = here.z + tDiag * rise - floorH;
                                float pen = 0.05 + 0.03 * tDiag;
                                float wallV = smoothstep(-0.04, 0.04, relH) * (1.0 - smoothstep(STORY_HEIGHT - pen, STORY_HEIGHT + pen, relH));
                                vis = min(vis, 1.0 - wallV);
                                if (vis <= 0.01) return 0.0;
                            }
                        }
                    }
                }
            }
        }
        if (t > maxT) break;
        if (t > 0.03) {
            ivec2 to = cell + (alongX ? ivec2(stepDir.x, 0) : ivec2(0, stepDir.y));
            int toCode0 = maskCatAt(to, 1, 0);
            if ((cellCode0 | toCode0) != 0) {
                float zCross = here.z + t * rise;
                float base0 = cellCode0 != 0
                    ? ambient.contact.w + float(cellCode0 - 1) / 8.0
                    : ambient.contact.w + float(toCode0 - 1) / 8.0;
                int row = clamp(int(floor((zCross - base0 + 0.05) / STORY_HEIGHT)), 0, stories - 1);
                vec2 crossing = start + direction * t;
                vec2 edgeStep = alongX ? vec2(float(stepDir.x), 0.0) : vec2(0.0, float(stepDir.y));
                int roomA = cellCode0 != 0 ? effectiveRoomAt(cell, row, crossing - vec2(cell) - edgeStep * 0.01) : 0;
                int roomB = toCode0 != 0 ? effectiveRoomAt(to, row, crossing - vec2(to) + edgeStep * 0.01) : 0;
                if (roomA != roomB && (roomA > 0 || roomB > 0)) {
                    float floorH = row == 0 ? base0 : floorAt(cell, row, floorAt(to, row, base0 + float(row) * STORY_HEIGHT));
                    if (min(here.z, lampLot.z) < floorH + STORY_HEIGHT - topGuard) {
                        float relH = zCross - floorH;
                        float pen = 0.05 + 0.03 * t;
                        float wallV = smoothstep(-0.04, 0.04, relH) * (1.0 - smoothstep(STORY_HEIGHT - pen, STORY_HEIGHT + pen, relH));
                        vis = min(vis, 1.0 - wallV);
                        if (vis <= 0.01) return 0.0;
                    }
                }
            }
            cell = to;
        } else {
            cell += alongX ? ivec2(stepDir.x, 0) : ivec2(0, stepDir.y);
        }
        tPrev = t;
        if (alongX) next.x += stepDelta.x; else next.y += stepDelta.y;
    }
    return vis;
}

float lampMarch(vec3 here, vec3 lampLot, float onFlatFloor, float isVertical, float nUp, vec2 horizN, bool isFire, float onSim) {
    vec3 origin = here + vec3(horizN * (0.16 * isVertical), 0.0);
    vec3 toReceiver = origin - lampLot;
    float dist3D = length(toReceiver);
    float horizTop = smoothstep(0.75, 0.92, nUp) * step(origin.z + 0.20, lampLot.z);
    float receiverClear = mix(mix(0.48, 0.14, max(isVertical, horizTop)), 0.08, onFlatFloor);
    receiverClear = mix(receiverClear, 0.58, onSim);
    float rStart = isFire ? 0.52 : 0.46;
    float rEnd = dist3D - receiverClear;
    if (rEnd <= rStart + 0.03) return 1.0;

    vec3 outDir = toReceiver / dist3D;
    vec2 gridSize = vec2(textureSize(heightMap, 0));
    ivec2 hMax = ivec2(gridSize) - 1;
    ivec2 vSize = textureSize(voxelMap, 0);
    bool hasVoxels = vSize.x > 1;
    vec2 invVSize = 1.0 / vec2(max(vSize, ivec2(1)));
    vec2 wSize = vec2(textureSize(worldDepthMap, 0));
    int vAoRows = hasVoxels ? voxelAoRows(vSize) : 1;
    int vHalfH = vSize.x / 2 + 128 + 256 * vAoRows;
    int vAoSize = vSize.x / 4;
    int vAoYBase = vHalfH * 2;
    bool hasColBounds = hasVoxels && vAoSize > 0 && vSize.y >= vAoYBase + vAoSize;
    float vTopMarginHalf = float(64 + 256 * vAoRows);
    ivec2 vSliceMax = ivec2(vSize.x - 1, vHalfH - 1);
    vec2 lotSz = max(ambient.drift.zw, vec2(1.0));
    vec2 rayProj = vec2(32.0 * (outDir.x - outDir.y), 16.0 * (outDir.x + outDir.y) - 40.0 * outDir.z);
    float projLen = length(rayProj);
    vec2 rayDirPx = projLen > 1e-3 ? rayProj / projLen : vec2(1.0, 0.0);
    vec2 rayPerp = vec2(-rayDirPx.y, rayDirPx.x);
    float wScale = max(ambient.shadowView.z, 0.5);
    float drBase = clamp(1.50 / max(projLen, 20.0), 0.052, 0.072);
    float spanR = rEnd - rStart;
    float farAccel = max(0.0, (spanR - float(LAMP_MARCH_STEPS) * drBase) / (0.5 * float(LAMP_MARCH_STEPS * (LAMP_MARCH_STEPS - 1))));
    float signedKeyRate = outDir.x + outDir.y + 0.8 * outDir.z;
    float keyRate = abs(signedKeyRate);
    float keyPerPx = signedKeyRate / max(projLen * wScale, 1.0);
    float horizLen = length(outDir.xy);
    vec2 perpTexel = horizLen > 1e-4 ? vec2(-outDir.y, outDir.x) / horizLen * 1.45 : vec2(1.45, 0.0);
    float lightRadiusScenePx = isFire ? 11.0 : 7.0;
    vec2 diskJitter = vec2(0.0);

    vec3 refAxis = abs(outDir.z) < 0.92 ? vec3(0.0, 0.0, 1.0) : vec3(1.0, 0.0, 0.0);
    vec3 coneU = normalize(cross(outDir, refAxis));
    vec3 coneV = cross(outDir, coneU);

    vec4 laneLit = vec4(1.0);
    vec2 simLaneLit = vec2(1.0);

    float r = rStart;
    float solidRun = 0.0;
    float lit = 1.0;
    for (int i = 0; i < LAMP_MARCH_STEPS; i++) {
        if (r >= rEnd) break;
        float dr = drBase + farAccel * float(i);
        float rNext = min(r + dr, rEnd);
        float stepLen = rNext - r;
        if (stepLen <= 1e-4) break;
        float rMid = r + 0.5 * stepLen;
        vec3 q = lampLot + outDir * rMid;
        float xyFromLamp = length(q.xy - lampLot.xy);
        if (xyFromLamp >= (isFire ? 0.45 : 0.42)) {
            vec2 texel = (q.xy + ambient.frame.w) * ambient.frame.z;
            if (all(greaterThanEqual(texel, vec2(1.0))) && all(lessThanEqual(texel, gridSize - 1.0))) {
                float dToReceiver = max(rEnd - rMid, 0.0);
                float coneFrac = clamp(dToReceiver / max(dist3D, 0.35), 0.0, 1.0);
                float spreadPx = clamp(0.32 + lightRadiusScenePx * coneFrac, 0.32, 4.40) * wScale;
                float sourceFade = smoothstep(0.0, 0.18, rMid - rStart);
                float receiverFade = smoothstep(0.0, stepLen * 1.50, rEnd - rMid);
                float fade = sourceFade * receiverFade;
                if (hasVoxels) {
                    vec3 dQ = outDir * stepLen;
                    float halfDz = 0.5 * abs(dQ.z);
                    bool checkLampHull = !hasColBounds || voxelColumnOverlap(q.xy, q.z - halfDz, q.z + halfDz, vAoSize, vAoYBase, lotSz);
                    if (checkLampHull) {
                        float rTiles = clamp(0.017 + (isFire ? 0.175 : 0.125) * coneFrac, 0.017, 0.195);
                        float pad = 0.22 + 1.05 * rTiles;
                        float kTop = 0.06 + 0.38 * rTiles;
                        stepHullCone4(q, dQ, coneU, coneV, rTiles, pad, kTop, fade, vSize, vHalfH, vTopMarginHalf, vSliceMax, lotSz, invVSize, laneLit);
                    }
                    float simLampGuard = onSim > 0.5 ? smoothstep(0.40, 0.65, dToReceiver) : 1.0;
                    if (simLampGuard > 0.01) {
                        float rSimPx = clamp(0.35 + (isFire ? 2.40 : 1.75) * coneFrac, 0.35, 2.40) * wScale;
                        stepSimCone2(q, dQ, 0.18, rSimPx, rayPerp, fade * simLampGuard, wSize, simLaneLit);
                    }
                    float maxLane = max(max(laneLit.x, laneLit.y), max(laneLit.z, laneLit.w));
                    float maxSim = max(simLaneLit.x, simLaneLit.y);
                    if (min(maxLane, maxSim) <= 0.008) return 0.0;
                } else if (onSim < 0.5 || dToReceiver > 0.45) {
                    float penZ = 0.08 + 0.11 * dToReceiver;
                    vec4 tops = (0.5 - textureGather(heightMap, texel / gridSize)) * HEIGHT_RANGE;
                    vec4 blocked = clamp((tops - q.z - 0.05) / penZ, 0.0, 1.0);
                    vec2 f = fract(texel - 0.5);
                    float rawColumn = mix(mix(blocked.w, blocked.z, f.x), mix(blocked.x, blocked.y, f.x), f.y);
                    float coreColumn = 0.0;
                    if (rawColumn > 0.55) {
                        float topL = (0.5 - texelFetch(heightMap, clamp(ivec2(floor(texel + perpTexel)), ivec2(0), hMax), 0).r) * HEIGHT_RANGE;
                        float topR = (0.5 - texelFetch(heightMap, clamp(ivec2(floor(texel - perpTexel)), ivec2(0), hMax), 0).r) * HEIGHT_RANGE;
                        float sideBlocked = min(clamp((topL - q.z - 0.05) / penZ, 0.0, 1.0),
                                                clamp((topR - q.z - 0.05) / penZ, 0.0, 1.0));
                        float eroded = min(rawColumn, sideBlocked);
                        solidRun = eroded > 0.65 ? solidRun + stepLen : max(0.0, solidRun - 2.0 * stepLen);
                        coreColumn = smoothstep(0.58, 0.92, eroded) * smoothstep(0.14, 0.28, solidRun);
                    } else {
                        solidRun = max(0.0, solidRun - 2.0 * stepLen);
                    }
                    float stepKey = keyRate * stepLen;
                    float canopyLift = smoothstep(1.5, 3.0, max(0.0, q.z - origin.z));
                    float frontSoft = 0.14 + 0.055 * dToReceiver;
                    float shellDepth = max(0.18, stepKey * 1.60 + 0.12) + 0.16 * coreColumn + 0.20 * canopyLift;
                    vec2 seen = hiddenAtSoft(q, spreadPx, rayPerp, rayDirPx, keyPerPx, shellDepth, frontSoft, diskJitter);
                    float shell = seen.y * (0.94 / (1.0 + 0.04 * dToReceiver));
                    float occ = max(coreColumn * seen.x, shell);
                    lit = min(lit, 1.0 - occ * fade);
                    if (lit <= 0.01) return 0.0;
                }
            }
        }
        r = rNext;
    }
    if (hasVoxels) {
        float hullVis = dot(laneLit, vec4(0.25));
        float simVis = 0.5 * (simLaneLit.x + simLaneLit.y);
        return min(hullVis, simVis);
    }
    return lit;
}

// Planar roof classifier for rain darkening & sheen: matches continuous pitched or flat roof slopes
// above Story 1 while strictly rejecting indoor-poking roof geometry, walls, windows, and covered fixtures.
bool isRainRoofPixel(vec2 pixel, vec3 p0, vec3 here, vec3 nSurf) {
    float roofBase = terrainBaseAt(here.xy, here.z);
    if (here.z - roofBase <= STORY_HEIGHT + 0.05) return false;
    const vec3 ROOF_UP = vec3(0.0, -0.8660254, 0.5);
    float surfFacing = dot(nSurf, ROOF_UP);
    if (surfFacing <= 0.24) return false;
    if (architecturalExposure(here + vec3(0.0, 0.0, 0.45)) <= 0.5) return false;

    vec2 maxPx = ambient.extent.xy - 0.5;
    float rP = max(2.0, 6.5 * ambient.view.z);
    float wP = max(0.8, 1.5 * ambient.view.z);
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
        vec2 pML = clamp(pixel + dir * (0.5 * rP) + perp * (0.5 * wP), vec2(0.5), maxPx);
        vec2 pMR = clamp(pixel + dir * (0.5 * rP) - perp * (0.5 * wP), vec2(0.5), maxPx);
        vec2 pT  = clamp(pixel + dir * rP,                             vec2(0.5), maxPx);
        vec2 pL  = clamp(pixel + dir * rP + perp * wP,                 vec2(0.5), maxPx);
        vec2 pR  = clamp(pixel + dir * rP - perp * wP,                 vec2(0.5), maxPx);
        if (length(pT - pixel) < 0.70 * rP || length(pL - pR) < 0.75 * wP) continue;
        vec4 qML = positionAt(pML);
        vec4 qMR = positionAt(pMR);
        vec4 qT  = positionAt(pT);
        vec4 qL  = positionAt(pL);
        vec4 qR  = positionAt(pR);
        if (qML.w < 0.25 && abs(qML.z - p0.z) < 14.0 &&
            qMR.w < 0.25 && abs(qMR.z - p0.z) < 14.0 &&
            qT.w  < 0.25 && abs(qT.z  - p0.z) < 22.0 &&
            qL.w  < 0.25 && abs(qL.z  - p0.z) < 22.0 &&
            qR.w  < 0.25 && abs(qR.z  - p0.z) < 22.0 &&
            abs(qL.z - qR.z) < 7.5) {
            vec3 cr = cross(qL.xyz - p0, qR.xyz - p0);
            float crLen = length(cr);
            if (crLen > 1.0) {
                vec3 nW = cr / crLen;
                if (nW.z < 0.0) nW = -nW;
                float wFacing = dot(nW, ROOF_UP);
                if (wFacing > 0.32 && wFacing < 0.90 && nW.z > 0.35 && abs(nW.x) > 0.15) {
                    float errML = abs(dot(qML.xyz - p0, nW)) / nW.z;
                    float errMR = abs(dot(qMR.xyz - p0, nW)) / nW.z;
                    float errT  = abs(dot(qT.xyz  - p0, nW)) / nW.z;
                    if (errML < 0.55 && errMR < 0.55 && errT < 0.55) return true;
                }
            }
        }
    }
    if (surfFacing >= 0.91) {
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
                    float wFacing = dot(nW, ROOF_UP);
                    if (wFacing >= 0.92 && nW.z > 0.35) {
                        float errML = abs(dot(qML.xyz - p0, nW)) / nW.z;
                        float errMR = abs(dot(qMR.xyz - p0, nW)) / nW.z;
                        float errT  = abs(dot(qT.xyz  - p0, nW)) / nW.z;
                        if (errML < 0.80 && errMR < 0.80 && errT < 0.80) return true;
                    }
                }
            }
        }
    }
    return false;
}

void dayPalette(float p, out vec3 sunCol, out vec3 shadeCol, out vec3 winCol) {
    float t1 = smoothstep(0.08, 0.26, p);
    float t2 = smoothstep(0.28, 0.48, p);
    float t3 = smoothstep(0.54, 0.76, p);
    float t4 = smoothstep(0.76, 0.93, p);

    sunCol = mix(vec3(1.26, 0.93, 0.74), vec3(0.94, 1.01, 1.08), t1);
    sunCol = mix(sunCol, vec3(1.02, 1.01, 0.96), t2);
    sunCol = mix(sunCol, vec3(1.14, 1.00, 0.81), t3);
    sunCol = mix(sunCol, vec3(1.30, 0.89, 0.56), t4);

    shadeCol = mix(vec3(0.75, 0.85, 1.25), vec3(0.80, 0.94, 1.22), t1);
    shadeCol = mix(shadeCol, vec3(0.84, 0.94, 1.18), t2);
    shadeCol = mix(shadeCol, vec3(0.79, 0.89, 1.21), t3);
    shadeCol = mix(shadeCol, vec3(0.72, 0.80, 1.26), t4);

    winCol = mix(vec3(1.18, 0.82, 0.58), vec3(0.96, 0.99, 1.04), t1);
    winCol = mix(winCol, vec3(1.02, 0.97, 0.88), t2);
    winCol = mix(winCol, vec3(1.10, 0.88, 0.60), t3);
    winCol = mix(winCol, vec3(1.20, 0.70, 0.36), t4);
}

float floorWallAO(vec3 here) {
    vec2 at = here.xy + ambient.frame.w;
    ivec2 cell = ivec2(floor(at));
    vec2 u = fract(at);
    int row = storyRowAt(cell, here.z, here.z, 0.15);
    int wallEdges = maskCatAt(cell, 3, row);
    int fenceEdges = maskCatAt(cell, 4, row);
    int rHere = effectiveRoomAt(cell, row, u);
    vec2 gridSize = vec2(textureSize(heightMap, 0));
    const float REACH_WALL = 0.56;
    const float REACH_FENCE = 0.30;
    float occ = 0.0;

    for (int d = 0; d < 4; d++) {
        float dist = d == 0 ? u.x : d == 1 ? (1.0 - u.x) : d == 2 ? u.y : (1.0 - u.y);
        if (dist >= REACH_WALL) continue;
        int bit = 1 << d;
        if ((wallEdges & bit) != 0) {
            float crease = exp(-dist / 0.095) * (1.0 - smoothstep(0.28, REACH_WALL, dist));
            float soft = 1.0 - dist / REACH_WALL;
            soft *= soft;
            occ += 0.58 * crease + 0.52 * soft;
            continue;
        }
        if ((fenceEdges & bit) != 0) {
            if (dist < REACH_FENCE) {
                float crease = exp(-dist / 0.075) * (1.0 - smoothstep(0.16, REACH_FENCE, dist));
                float soft = 1.0 - dist / REACH_FENCE;
                soft *= soft;
                occ += 0.68 * (0.60 * crease + 0.48 * soft);
            }
            continue;
        }
        if (wallEdges == 0 && fenceEdges == 0) {
            ivec2 step = d == 0 ? ivec2(-1, 0) : d == 1 ? ivec2(1, 0) : d == 2 ? ivec2(0, -1) : ivec2(0, 1);
            vec2 nbrU = d == 0 ? vec2(0.99, u.y) : d == 1 ? vec2(0.01, u.y) : d == 2 ? vec2(u.x, 0.99) : vec2(u.x, 0.01);
            int rNbr = effectiveRoomAt(cell + step, row, nbrU);
            if (rHere == rNbr || (rHere == 0 && rNbr == 0)) continue;
            vec2 edgeLocal = d == 0 ? vec2(0.0, u.y) : d == 1 ? vec2(1.0, u.y) : d == 2 ? vec2(u.x, 0.0) : vec2(u.x, 1.0);
            vec2 edgePos = vec2(cell) + edgeLocal;
            vec2 dirF = vec2(step);
            float hA = (0.5 - texture(heightMap, (edgePos + dirF * 0.05) * ambient.frame.z / gridSize).r) * HEIGHT_RANGE - here.z;
            float hB = (0.5 - texture(heightMap, (edgePos - dirF * 0.05) * ambient.frame.z / gridSize).r) * HEIGHT_RANGE - here.z;
            float wallPresent = smoothstep(0.08, 0.28, max(hA, hB));
            float crease = exp(-dist / 0.095) * (1.0 - smoothstep(0.28, REACH_WALL, dist));
            float soft = 1.0 - dist / REACH_WALL;
            soft *= soft;
            occ += (0.58 * crease + 0.52 * soft) * wallPresent;
        }
    }

    if ((wallEdges & 0x30) != 0) {
        if ((wallEdges & 0x10) != 0) {
            float dist = abs(u.x - u.y) * 0.70710678;
            if (dist < REACH_WALL) {
                float crease = exp(-dist / 0.095) * (1.0 - smoothstep(0.28, REACH_WALL, dist));
                float soft = 1.0 - dist / REACH_WALL;
                occ += 0.58 * crease + 0.52 * soft * soft;
            }
        }
        if ((wallEdges & 0x20) != 0) {
            float dist = abs(u.x + u.y - 1.0) * 0.70710678;
            if (dist < REACH_WALL) {
                float crease = exp(-dist / 0.095) * (1.0 - smoothstep(0.28, REACH_WALL, dist));
                float soft = 1.0 - dist / REACH_WALL;
                occ += 0.58 * crease + 0.52 * soft * soft;
            }
        }
    } else if ((fenceEdges & 0x30) != 0) {
        if ((fenceEdges & 0x10) != 0) {
            float dist = abs(u.x - u.y) * 0.70710678;
            if (dist < REACH_FENCE) {
                float crease = exp(-dist / 0.075) * (1.0 - smoothstep(0.16, REACH_FENCE, dist));
                float soft = 1.0 - dist / REACH_FENCE;
                occ += 0.68 * (0.60 * crease + 0.48 * soft * soft);
            }
        }
        if ((fenceEdges & 0x20) != 0) {
            float dist = abs(u.x + u.y - 1.0) * 0.70710678;
            if (dist < REACH_FENCE) {
                float crease = exp(-dist / 0.075) * (1.0 - smoothstep(0.16, REACH_FENCE, dist));
                float soft = 1.0 - dist / REACH_FENCE;
                occ += 0.68 * (0.60 * crease + 0.48 * soft * soft);
            }
        }
    } else {
        int part = maskCatAt(cell, 2, row) & 7;
        if (part != 0) {
            float dist = part <= 2 ? abs(u.x - u.y) * 0.70710678 : abs(u.x + u.y - 1.0) * 0.70710678;
            if (dist < REACH_WALL) {
                vec2 edgeLocal = part <= 2 ? vec2(0.5 * (u.x + u.y)) : vec2(0.5 * (u.x - u.y + 1.0), 0.5 * (u.y - u.x + 1.0));
                vec2 edgePos = vec2(cell) + edgeLocal;
                float hD = (0.5 - texture(heightMap, edgePos * ambient.frame.z / gridSize).r) * HEIGHT_RANGE - here.z;
                float wallPresent = smoothstep(0.08, 0.28, hD);
                float crease = exp(-dist / 0.095) * (1.0 - smoothstep(0.28, REACH_WALL, dist));
                float soft = 1.0 - dist / REACH_WALL;
                occ += (0.58 * crease + 0.52 * soft * soft) * wallPresent;
            }
        }
    }
    return clamp(occ, 0.0, 1.45);
}

float matchArchWall(vec3 rawHere, vec2 sceneXY, float rawKey, float nSurfX, out vec3 outWallPos, out vec2 outWallN) {
    outWallPos = rawHere;
    outWallN = vec2(0.0);
    ivec2 mSize = textureSize(indoorMap, 0);
    if (mSize.x <= 1) return 0.0;
    int bandH = indoorBandH(mSize);
    int stories = max(1, mSize.y / max(1, 5 * bandH));

    vec3 shifted = lotPoint(sceneXY, rawKey + 0.14, false, ambient.frame.xy);
    vec2 atS = shifted.xy + ambient.frame.w;
    vec2 atR = rawHere.xy + ambient.frame.w;
    ivec2 baseCell = ivec2(floor(atS - 0.5));

    float bestW = 0.0;
    float bestScore = -1.0e5;
    vec2 bestN = vec2(0.70710678, 0.70710678);
    vec2 snappedAt = atS;
    float hasNx = step(0.15, abs(nSurfX));
    float clampedNx = clamp(nSurfX, -0.75, 0.75);

    for (int cy = 0; cy <= 1; cy++) {
        for (int cx = 0; cx <= 1; cx++) {
            ivec2 cell = baseCell + ivec2(cx, cy);
            if (cell.x < 0 || cell.y < 0 || cell.x >= mSize.x || cell.y >= bandH) continue;
            int baseCode = maskCatFast(cell, 1, 0, mSize, bandH, stories);
            float base0 = baseCode == 0 ? shifted.z : ambient.contact.w + float(baseCode - 1) / 8.0;
            int rBase = clamp(int(floor((shifted.z - base0) / STORY_HEIGHT)), 0, stories - 1);
            int wBits = 0;
            for (int rOff = 0; rOff <= 2; rOff++) {
                int r = rOff == 0 ? rBase : (rOff == 1 ? rBase - 1 : rBase + 1);
                if (r < 0 || r >= stories) continue;
                int rowCode = r == 0 ? baseCode : maskCatFast(cell, 1, r, mSize, bandH, stories);
                float floorZ = rowCode == 0 ? base0 + float(r) * STORY_HEIGHT : ambient.contact.w + float(r) * STORY_HEIGHT + float(rowCode - 1) / 8.0;
                if (shifted.z < floorZ - 0.16 || shifted.z > floorZ + STORY_HEIGHT + 0.08) continue;
                wBits |= maskCatFast(cell, 3, r, mSize, bandH, stories);
            }
            if (wBits == 0) continue;

            vec2 cMin = vec2(cell);
            vec2 cMax = cMin + 1.0;

            for (int d = 0; d < 4; d++) {
                if ((wBits & (1 << d)) == 0) continue;
                vec2 wn = d <= 1 ? vec2(1.0, 0.0) : vec2(0.0, 1.0);
                float pS = d <= 1 ? clamp(atS.y - cMin.y, 0.0, 1.0) : clamp(atS.x - cMin.x, 0.0, 1.0);
                float pR = d <= 1 ? clamp(atR.y - cMin.y, 0.0, 1.0) : clamp(atR.x - cMin.x, 0.0, 1.0);
                vec2 segA = d == 0 ? cMin : d == 1 ? vec2(cMax.x, cMin.y) : d == 2 ? cMin : vec2(cMin.x, cMax.y);
                vec2 segB = d == 0 ? vec2(cMin.x, cMax.y) : d == 1 ? cMax : d == 2 ? vec2(cMax.x, cMin.y) : cMax;
                vec2 clS = mix(segA, segB, pS);
                vec2 clR = mix(segA, segB, pR);
                float dS = length(atS - clS);
                float dR = length(atR - clR);
                bool useR = dot(atR - clR, wn) >= -0.02 && dR < dS;
                float dist = useR ? dR : dS;
                float w = 1.0 - smoothstep(0.08, 0.16, dist);
                if (w > 0.0) {
                    vec2 closest = useR ? clR : clS;
                    float pSeg = useR ? pR : pS;
                    vec2 segMid = 0.5 * (segA + segB);
                    float camDelta = (segMid.x + segMid.y) - (closest.x + closest.y);
                    float endPen = (pSeg <= 0.002 || pSeg >= 0.998) ? (camDelta < -0.20 ? 0.45 : 0.14) : 0.0;
                    float expNx = (wn.x - wn.y) * 0.48;
                    float nxBonus = hasNx * 0.12 * (1.0 - abs(clampedNx - expNx));
                    float score = (1.0 - dist / 0.16) - endPen + nxBonus;
                    bestW = max(bestW, w);
                    if (score > bestScore) {
                        bestScore = score;
                        bestN = wn;
                        snappedAt = closest + wn * 0.035;
                    }
                }
            }
            if ((wBits & 0x20) != 0) {
                vec2 wn = vec2(0.70710678, 0.70710678);
                vec2 segA = vec2(cMin.x, cMax.y);
                vec2 segB = vec2(cMax.x, cMin.y);
                float pS = clamp(0.5 * ((atS.x - cMin.x) - (atS.y - cMax.y)), 0.0, 1.0);
                float pR = clamp(0.5 * ((atR.x - cMin.x) - (atR.y - cMax.y)), 0.0, 1.0);
                vec2 clS = mix(segA, segB, pS);
                vec2 clR = mix(segA, segB, pR);
                float dS = length(atS - clS);
                float dR = length(atR - clR);
                bool useR = dot(atR - clR, wn) >= -0.02 && dR < dS;
                float dist = useR ? dR : dS;
                float w = 1.0 - smoothstep(0.08, 0.16, dist);
                if (w > 0.0) {
                    vec2 closest = useR ? clR : clS;
                    float pSeg = useR ? pR : pS;
                    vec2 segMid = 0.5 * (segA + segB);
                    float camDelta = (segMid.x + segMid.y) - (closest.x + closest.y);
                    float endPen = (pSeg <= 0.002 || pSeg >= 0.998) ? (camDelta < -0.20 ? 0.45 : 0.14) : 0.0;
                    float nxBonus = hasNx * 0.12 * (1.0 - abs(clampedNx));
                    float score = (1.0 - dist / 0.16) - endPen + nxBonus;
                    bestW = max(bestW, w);
                    if (score > bestScore) {
                        bestScore = score;
                        bestN = wn;
                        snappedAt = closest + wn * 0.035;
                    }
                }
            }
            if ((wBits & 0x10) != 0) {
                float pS = clamp(0.5 * ((atS.x - cMin.x) + (atS.y - cMin.y)), 0.0, 1.0);
                float pR = clamp(0.5 * ((atR.x - cMin.x) + (atR.y - cMin.y)), 0.0, 1.0);
                vec2 clS = cMin + vec2(pS, pS);
                vec2 clR = cMin + vec2(pR, pR);
                float side = (atS.x - cMin.x) >= (atS.y - cMin.y) ? 1.0 : -1.0;
                vec2 wn = vec2(0.70710678 * side, -0.70710678 * side);
                float dS = length(atS - clS);
                float dR = length(atR - clR);
                bool useR = dot(atR - clR, wn) >= -0.02 && dR < dS;
                float dist = useR ? dR : dS;
                float w = 1.0 - smoothstep(0.08, 0.16, dist);
                if (w > 0.0) {
                    vec2 closest = useR ? clR : clS;
                    float pSeg = useR ? pR : pS;
                    vec2 segMid = cMin + vec2(0.5, 0.5);
                    float camDelta = (segMid.x + segMid.y) - (closest.x + closest.y);
                    float endPen = (pSeg <= 0.002 || pSeg >= 0.998) ? (camDelta < -0.20 ? 0.45 : 0.14) : 0.0;
                    float score = (1.0 - dist / 0.16) - endPen;
                    bestW = max(bestW, w);
                    if (score > bestScore) {
                        bestScore = score;
                        bestN = wn;
                        snappedAt = closest + wn * 0.035;
                    }
                }
            }
        }
    }

    if (bestW <= 0.001) return 0.0;
    outWallN = bestN;
    outWallPos = vec3(snappedAt - ambient.frame.w, shifted.z);
    return bestW;
}

float spriteWallProximityAO(vec3 here, int row) {
    vec2 at = here.xy + ambient.frame.w;
    ivec2 cell = ivec2(floor(at));
    vec2 u = fract(at);
    int wEdges = maskCatAt(cell, 3, row);
    if (wEdges == 0) return 0.0;
    const float REACH = 0.44;
    float occ = 0.0;
    for (int d = 0; d < 4; d++) {
        if ((wEdges & (1 << d)) == 0) continue;
        float dist = d == 0 ? u.x : d == 1 ? (1.0 - u.x) : d == 2 ? u.y : (1.0 - u.y);
        if (dist >= REACH) continue;
        float t = 1.0 - dist / REACH;
        occ += 0.52 * t * t;
    }
    if ((wEdges & 0x10) != 0) {
        float dist = abs(u.x - u.y) * 0.70710678;
        if (dist < REACH) {
            float t = 1.0 - dist / REACH;
            occ += 0.46 * t * t;
        }
    }
    if ((wEdges & 0x20) != 0) {
        float dist = abs(u.x + u.y - 1.0) * 0.70710678;
        if (dist < REACH) {
            float t = 1.0 - dist / REACH;
            occ += 0.46 * t * t;
        }
    }
    return clamp(occ, 0.0, 1.05);
}

float wallCornerAO(vec3 here, vec2 horizN) {
    vec2 planePos = here.xy + ambient.frame.w;
    vec2 at = planePos + horizN * 0.10;
    ivec2 baseCell = ivec2(floor(at - 0.5));
    const float REACH = 0.46;
    float occ = 0.0;

    for (int cy = 0; cy <= 1; cy++) {
        for (int cx = 0; cx <= 1; cx++) {
            ivec2 cell = baseCell + ivec2(cx, cy);
            int row = storyRowAt(cell, here.z, here.z, 0.15);
            int wallEdges = maskCatAt(cell, 3, row);
            if (wallEdges == 0) continue;
            vec2 cMin = vec2(cell);
            vec2 cMax = cMin + 1.0;

            for (int d = 0; d < 4; d++) {
                if ((wallEdges & (1 << d)) == 0) continue;
                ivec2 step = d == 0 ? ivec2(-1, 0) : d == 1 ? ivec2(1, 0) : d == 2 ? ivec2(0, -1) : ivec2(0, 1);
                float perpWeight = 1.0 - smoothstep(0.76, 0.95, -dot(vec2(step), horizN));
                if (perpWeight <= 0.001) continue;
                vec2 segA = d == 0 ? cMin : d == 1 ? vec2(cMax.x, cMin.y) : d == 2 ? cMin : vec2(cMin.x, cMax.y);
                vec2 segB = d == 0 ? vec2(cMin.x, cMax.y) : d == 1 ? cMax : d == 2 ? vec2(cMax.x, cMin.y) : cMax;
                float frontHemi = smoothstep(0.14, 0.45, max(dot(segA - planePos, horizN), dot(segB - planePos, horizN)));
                if (frontHemi <= 0.001) continue;
                vec2 closest = d <= 1 ? vec2(segA.x, clamp(at.y, cMin.y, cMax.y))
                                      : vec2(clamp(at.x, cMin.x, cMax.x), segA.y);
                float dist = length(at - closest);
                if (dist >= REACH) continue;
                float t = 1.0 - dist / REACH;
                float term = 0.55 * exp(-dist / 0.09) * (1.0 - smoothstep(0.24, REACH, dist)) + 0.45 * t * t;
                occ = max(occ, perpWeight * frontHemi * term);
            }
            if ((wallEdges & 0x10) != 0) {
                vec2 diagN = vec2(-0.70710678, 0.70710678);
                float perpWeight = 1.0 - smoothstep(0.80, 0.97, abs(dot(diagN, horizN)));
                float frontHemi = smoothstep(0.14, 0.45, max(dot(cMin - planePos, horizN), dot(cMax - planePos, horizN)));
                if (perpWeight * frontHemi > 0.001) {
                    float proj = clamp(0.5 * ((at.x - cMin.x) + (at.y - cMin.y)), 0.0, 1.0);
                    float dist = length(at - (cMin + vec2(proj, proj)));
                    if (dist < REACH) {
                        float t = 1.0 - dist / REACH;
                        float term = 0.50 * exp(-dist / 0.09) * (1.0 - smoothstep(0.24, REACH, dist)) + 0.40 * t * t;
                        occ = max(occ, perpWeight * frontHemi * term);
                    }
                }
            }
            if ((wallEdges & 0x20) != 0) {
                vec2 diagN = vec2(0.70710678, 0.70710678);
                float perpWeight = 1.0 - smoothstep(0.80, 0.97, abs(dot(diagN, horizN)));
                vec2 segA = vec2(cMin.x, cMax.y);
                vec2 segB = vec2(cMax.x, cMin.y);
                float frontHemi = smoothstep(0.14, 0.45, max(dot(segA - planePos, horizN), dot(segB - planePos, horizN)));
                if (perpWeight * frontHemi > 0.001) {
                    float proj = clamp(0.5 * ((at.x - cMin.x) - (at.y - cMax.y)), 0.0, 1.0);
                    float dist = length(at - vec2(cMin.x + proj, cMax.y - proj));
                    if (dist < REACH) {
                        float t = 1.0 - dist / REACH;
                        float term = 0.50 * exp(-dist / 0.09) * (1.0 - smoothstep(0.24, REACH, dist)) + 0.40 * t * t;
                        occ = max(occ, perpWeight * frontHemi * term);
                    }
                }
            }
        }
    }
    return clamp(occ, 0.0, 1.0);
}

vec3 sampleBakedGroundAO(vec2 lotXY, int levelRow, ivec2 oSize) {
    int aoSize = oSize.x / 4;
    if (aoSize <= 0 || levelRow < 0) return vec3(0.0);
    int aoRows = voxelAoRows(oSize);
    if ((levelRow >> 2) >= aoRows) return vec3(0.0);
    int halfH = oSize.x / 2 + 128 + 256 * aoRows;
    int yBase = halfH * 2 + (levelRow >> 2) * aoSize;
    if (oSize.y < yBase + aoSize) return vec3(0.0);
    vec2 p = lotXY * 8.0 - 0.5;
    if (p.x < -0.5 || p.y < -0.5 || p.x >= float(aoSize) || p.y >= float(aoSize)) return vec3(0.0);
    ivec2 i0 = ivec2(floor(p));
    vec2 f = clamp(p - vec2(i0), 0.0, 1.0);
    ivec2 maxC = ivec2(aoSize - 1);
    ivec2 c00 = clamp(i0, ivec2(0), maxC);
    ivec2 c10 = clamp(i0 + ivec2(1, 0), ivec2(0), maxC);
    ivec2 c01 = clamp(i0 + ivec2(0, 1), ivec2(0), maxC);
    ivec2 c11 = clamp(i0 + ivec2(1, 1), ivec2(0), maxC);
    int xOff = (levelRow & 3) * aoSize;
    vec3 v00 = texelFetch(voxelMap, ivec2(xOff + c00.x, yBase + c00.y), 0).rgb;
    vec3 v10 = texelFetch(voxelMap, ivec2(xOff + c10.x, yBase + c10.y), 0).rgb;
    vec3 v01 = texelFetch(voxelMap, ivec2(xOff + c01.x, yBase + c01.y), 0).rgb;
    vec3 v11 = texelFetch(voxelMap, ivec2(xOff + c11.x, yBase + c11.y), 0).rgb;
    return mix(mix(v00, v10, f.x), mix(v01, v11, f.x), f.y);
}

float simFootAO(vec3 here) {
    if (ambient.shadowView.w <= 0.5) return 0.0;
    vec3 qC = vec3(here.xy, here.z + 0.055);
    vec2 sceneC = vec2(32.0 * (qC.x - qC.y), 16.0 * (qC.x + qC.y) - 40.0 * qC.z) + ambient.frame.xy;
    vec2 wpC = ambient.shadowView.xy + sceneC * ambient.shadowView.z;
    if (wpC.x < ambient.dynShadowBounds.x - 8.0 || wpC.y < ambient.dynShadowBounds.y - 8.0 ||
        wpC.x > ambient.dynShadowBounds.z + 8.0 || wpC.y > ambient.dynShadowBounds.w + 8.0) return 0.0;
    vec2 wSize = vec2(textureSize(worldDepthMap, 0));
    if (any(lessThan(wpC, vec2(8.0))) || any(greaterThanEqual(wpC, wSize - 8.0))) return 0.0;
    ivec2 ic = ivec2(floor(wpC));
    float dMin = texelFetch(worldDepthMap, ic, 0).r;
    dMin = min(dMin, texelFetch(worldDepthMap, ic + ivec2(-6, -4), 0).r);
    dMin = min(dMin, texelFetch(worldDepthMap, ic + ivec2( 6, -4), 0).r);
    dMin = min(dMin, texelFetch(worldDepthMap, ic + ivec2(-6,  4), 0).r);
    dMin = min(dMin, texelFetch(worldDepthMap, ic + ivec2( 6,  4), 0).r);
    if (dMin >= 0.9999) return 0.0;

    // Contiguous Nyquist-bandlimited 5x5 Gaussian shoe-sole kernel (step = 0.032 tiles): smooth radial peak at r = 0.
    const float KW[5] = float[5](0.0625, 0.25, 0.375, 0.25, 0.0625);
    float acc = 0.0;
    for (int iy = -2; iy <= 2; iy++) {
        float wy = KW[iy + 2];
        for (int ix = -2; ix <= 2; ix++) {
            vec3 q = vec3(here.xy + vec2(float(ix), float(iy)) * 0.034, here.z + 0.055);
            acc += dynamicSimOccAt(q, 0.10) * (KW[ix + 2] * wy);
        }
    }
    return clamp(1.0 - exp(-acc * 2.6), 0.0, 1.0);
}

float offLotGroundAO(vec3 here, float scale, out float outContact) {
    ivec2 limit = ivec2(ambient.extent.xy) - 1;
    vec2 snapScene = floor(sceneOf(here) * 0.5) * 2.0 + 1.0;
    const float DY[3] = float[3](-8.5, -3.5, 2.0);
    float bestC = 0.0, sumC = 0.0;
    float bestH = 0.0, sumH = 0.0;
    for (int r = 0; r < 3; r++) {
        float sy = ambient.view.y + (snapScene.y + DY[r]) * scale;
        if (sy < 0.0 || sy > float(limit.y)) continue;
        int iy = int(floor(sy));
        for (int c = -6; c <= 6; c++) {
            float sx = ambient.view.x + (snapScene.x + float(c) * 2.5) * scale;
            if (sx < 0.0 || sx > float(limit.x)) continue;
            ivec2 sp = ivec2(int(floor(sx)), iy);
            float qDepth = texelFetch(depthMap, sp, 0).r;
            if (qDepth >= 1.0) continue;
            vec2 qScene = (vec2(sp) + 0.5 - ambient.view.xy) / scale;
            vec3 qLot = lotPoint(qScene, (0.62 - qDepth) / 0.003, false, ambient.frame.xy);
            float dz = qLot.z - here.z;
            if (dz < -0.10 || dz > 0.72) continue;
            float dxy = length(qLot.xy - here.xy);
            if (dxy > 0.48) continue;
            float zW = smoothstep(-0.10, 0.01, dz) * (1.0 - smoothstep(0.42, 0.72, dz));
            float cHit = (1.0 - smoothstep(0.04, 0.34, dxy)) * zW;
            float hHit = (1.0 - smoothstep(0.06, 0.48, dxy)) * zW;
            bestC = max(bestC, cHit);
            sumC += cHit;
            bestH = max(bestH, hHit);
            sumH += hHit;
        }
    }
    outContact = clamp(bestC * 0.62 + min(sumC * 0.025, 0.16), 0.0, 0.76);
    return clamp(bestH * 0.38 + min(sumH * 0.022, 0.18), 0.0, 0.56);
}

vec3 multiBounceAO(float ao, vec3 alb) {
    vec3 a = 2.0404 * alb - 0.3324;
    vec3 b = -4.7951 * alb + 0.6417;
    vec3 c = 2.7552 * alb + 0.6903;
    return max(vec3(ao), ((ao * a + b) * ao + c) * ao);
}

float voxelGroundAO(vec3 here, int levelRow, ivec2 vSize, out float outContact) {
    vec3 baked = sampleBakedGroundAO(here.xy, levelRow, vSize);
    float simContact = simFootAO(here);
    const float MOVER_SCALE = 0.52;
    float staticContact = clamp(baked.r * 0.78, 0.0, 1.0);
    float combinedContact = max(staticContact, simContact);
    outContact = staticContact + (combinedContact - staticContact) * mix(1.0, MOVER_SCALE, staticContact);
    float staticHemi = clamp(baked.g * 0.44 + baked.b * 0.34, 0.0, 1.0);
    float combinedHemi = max(staticHemi, clamp(staticHemi + simContact * 0.28, 0.0, 1.0));
    return staticHemi + (combinedHemi - staticHemi) * MOVER_SCALE;
}

float voxelWallAO(vec3 here, vec2 horizN, float floorZ, ivec2 vSize, int vHalfH, float vTopMarginHalf, ivec2 vSliceMax, vec2 lotSz) {
    vec2 tang = vec2(-horizN.y, horizN.x);
    vec2 faceAt = here.xy + ambient.frame.w + horizN * 0.22;
    ivec2 faceCell = ivec2(floor(faceAt));
    int wallRow = storyRowAt(faceCell, here.z, here.z, 0.15);
    int faceRoom = effectiveRoomAt(faceCell, wallRow, fract(faceAt));
    const vec3 OFF[8] = vec3[8](
        vec3(0.22, -0.10,  0.04),
        vec3(0.23,  0.10,  0.04),
        vec3(0.25,  0.00,  0.14),
        vec3(0.32,  0.00,  0.08),
        vec3(0.28,  0.00,  0.34),
        vec3(0.45,  0.00,  0.50),
        vec3(0.30, -0.14, -0.22),
        vec3(0.30,  0.14, -0.22)
    );
    const float W[8] = float[8](1.0, 1.0, 0.85, 0.60, 0.72, 0.50, 0.62, 0.62);
    float ceilLim = floorZ + STORY_HEIGHT - 0.14;
    float floorLim = floorZ + 0.12;
    float sum = 0.0;
    float wSum = 0.0;
    for (int i = 0; i < 8; i++) {
        vec3 o = OFF[i];
        float qz = here.z + o.z;
        if (i >= 4 && i <= 5 && qz > ceilLim) continue;
        if (i >= 6 && qz < floorLim) continue;
        vec3 q = vec3(here.xy + horizN * o.x + tang * o.y, qz);
        vec2 qAt = q.xy + ambient.frame.w;
        ivec2 qCell = ivec2(floor(qAt));
        float sameRoom = effectiveRoomAt(qCell, wallRow, fract(qAt)) == faceRoom ? 1.0 : 0.0;
        float occ = sameRoom > 0.5 ? dualViewHullAtPrecomp(q, vSize, vHalfH, vTopMarginHalf, vSliceMax, lotSz, 0.75) : 0.0;
        sum += occ * W[i];
        wSum += W[i];
    }
    float raw = sum / max(wSum, 1e-4);
    return clamp((raw - 0.035) * 1.32, 0.0, 1.0);
}

float simWallProximityAO(vec3 here, vec2 horizN) {
    if (ambient.shadowView.w <= 0.5) return 0.0;
    vec3 probe = vec3(here.xy + horizN * 0.22, here.z);
    vec2 sc = sceneOf(probe);
    vec2 wp = ambient.shadowView.xy + sc * ambient.shadowView.z;
    if (wp.x < ambient.dynShadowBounds.x - 8.0 || wp.y < ambient.dynShadowBounds.y - 8.0 ||
        wp.x > ambient.dynShadowBounds.z + 8.0 || wp.y > ambient.dynShadowBounds.w + 8.0) return 0.0;
    vec2 wSize = vec2(textureSize(worldDepthMap, 0));
    if (any(lessThan(wp, vec2(6.0))) || any(greaterThanEqual(wp, wSize - 6.0))) return 0.0;
    ivec2 ic = ivec2(floor(wp));
    float dMin = texelFetch(worldDepthMap, ic, 0).r;
    dMin = min(dMin, texelFetch(worldDepthMap, ic + ivec2(-5, 0), 0).r);
    dMin = min(dMin, texelFetch(worldDepthMap, ic + ivec2( 5, 0), 0).r);
    if (dMin >= 0.9999) return 0.0;

    vec2 tang = vec2(-horizN.y, horizN.x);
    float o0 = dynamicSimOccAt(vec3(here.xy + horizN * 0.14, here.z), 0.14);
    float o1 = dynamicSimOccAt(vec3(here.xy + horizN * 0.25 + tang * 0.10, here.z + 0.04), 0.15);
    float o2 = dynamicSimOccAt(vec3(here.xy + horizN * 0.25 - tang * 0.10, here.z + 0.04), 0.15);
    float o3 = dynamicSimOccAt(vec3(here.xy + horizN * 0.38, here.z - 0.06), 0.16);
    return clamp(0.38 * o0 + 0.24 * o1 + 0.24 * o2 + 0.14 * o3, 0.0, 1.0);
}

vec3 sampleStoryBounce(vec2 lotXY, int levelRow, int stories, vec2 camLotSz, ivec2 bSize) {
    if (bSize.x <= 1 || levelRow < 0 || levelRow >= stories) return vec3(0.0);
    int cols = min(stories, 4);
    int rows = max(1, (stories + 3) / 4);
    float sliceW = float(bSize.x) / float(cols);
    float sliceH = float(bSize.y) / float(rows);
    int colIdx = levelRow & 3;
    int rowIdx = levelRow >> 2;
    vec2 localPx = clamp((lotXY / camLotSz) * vec2(sliceW, sliceH), vec2(0.5), vec2(sliceW - 0.5, sliceH - 0.5));
    vec2 uv = (vec2(float(colIdx) * sliceW, float(rowIdx) * sliceH) + localPx) / vec2(bSize);
    vec4 tap = texture(bounceMap, uv);
    return tap.a > 0.02 ? tap.rgb / max(tap.a, 0.05) : vec3(0.0);
}

vec3 gatherRoomBounceGI(vec3 here, vec2 horizN, vec2 nLotXY, float isVertical, float onFlatFloor, float onDynamicSim, int storiesCount) {
    ivec2 bSize = textureSize(bounceMap, 0);
    if (bSize.x <= 1 || ambient.skyExtra.w <= 0.001) return vec3(0.0);
    int orient = int(ambient.clouds.z + 0.5);
    vec2 camLotSz = max((orient & 1) == 0 ? ambient.drift.zw : ambient.drift.wz, vec2(1.0));
    vec2 surfFwd = normalize(mix(vec2(0.70710678, 0.70710678), length(horizN) > 0.15 ? horizN : vec2(0.70710678, 0.70710678), isVertical));
    float frontPush = mix(0.30, 0.0, max(onFlatFloor, onDynamicSim));
    vec2 probeXY = here.xy + surfFwd * frontPush;
    vec2 atHere = probeXY + ambient.frame.w;
    ivec2 cellHere = ivec2(floor(atHere));
    int levelRow = storyRowAt(cellHere, here.z, here.z, 0.18);
    int roomHere = effectiveRoomAt(cellHere, levelRow, atHere - vec2(cellHere));

    vec2 tang = vec2(-surfFwd.y, surfFwd.x);
    vec2 off0, off1, off2, off3, off4;
    vec4 w14;
    float w0;
    if (onFlatFloor < 0.5 && onDynamicSim < 0.5 && isVertical > 0.35) {
        off0 = surfFwd * 0.35;
        off1 = surfFwd * 0.92 + tang * 0.52;
        off2 = surfFwd * 0.92 - tang * 0.52;
        off3 = surfFwd * 1.62 + tang * 0.82;
        off4 = surfFwd * 1.62 - tang * 0.82;
        w0 = 0.28; w14 = vec4(0.22, 0.22, 0.14, 0.14);
    } else if (onFlatFloor > 0.5) {
        off0 = vec2(0.0);
        off1 = vec2( 0.85,  0.35);
        off2 = vec2(-0.85, -0.35);
        off3 = vec2(-0.35,  0.85);
        off4 = vec2( 0.35, -0.85);
        w0 = 0.24; w14 = vec4(0.19);
    } else {
        off0 = surfFwd * 0.28;
        off1 = surfFwd * 0.88 + tang * 0.48;
        off2 = surfFwd * 0.88 - tang * 0.48;
        off3 = -surfFwd * 0.55 + tang * 0.55;
        off4 = -surfFwd * 0.55 - tang * 0.55;
        w0 = 0.30; w14 = vec4(0.22, 0.22, 0.13, 0.13);
    }

    vec3 acc = vec3(0.0);
    float wSum = 0.0;
    for (int k = 0; k < 5; k++) {
        vec2 offK = k == 0 ? off0 : (k == 1 ? off1 : (k == 2 ? off2 : (k == 3 ? off3 : off4)));
        float wK = k == 0 ? w0 : (k == 1 ? w14.x : (k == 2 ? w14.y : (k == 3 ? w14.z : w14.w)));
        vec2 qXY = probeXY + offK;
        if (any(lessThan(qXY, vec2(0.0))) || any(greaterThanEqual(qXY, camLotSz))) continue;
        vec2 qAt = qXY + ambient.frame.w;
        ivec2 qCell = ivec2(floor(qAt));
        int qRoom = effectiveRoomAt(qCell, levelRow, qAt - vec2(qCell));
        if (qRoom != roomHere) continue;
        vec3 b = sampleStoryBounce(qXY, levelRow, storiesCount, camLotSz, bSize);
        acc += b * wK;
        wSum += wK;
    }
    return wSum > 0.01 ? (acc / wSum) : vec3(0.0);
}

void main() {
    float ambScale = ambient.extent.w > 0.5 ? ambient.extent.w : 1.0;
    vec2 rawPx = (floor(gl_FragCoord.xy) + 0.5) * ambScale;
    if (rawPx.x >= ambient.extent.x || rawPx.y >= ambient.extent.y) { color = vec4(0.5, 0.5, 0.5, 1.0); return; }
    ivec2 limitPx = max(ivec2(ambient.extent.xy) - 1, ivec2(0));
    ivec2 fullPx = clamp(ivec2(floor(rawPx)), ivec2(0), limitPx);
    vec2 pixel = vec2(fullPx) + 0.5;
    vec4 centre = positionAt(pixel);
    if (centre.w > 0.75) { color = vec4(0.5, 0.5, 0.5, 1.0); return; }
    vec3 p = centre.xyz;
    float scale = ambient.view.z;

    vec3 normal;
    vec3 nSurf;
    vec3 pSmooth = p;
    float gradJump;
    bool hasVertGrad = true;
    {
        bool isSprite = centre.w < 0.25;
        float step = isSprite
            ? clamp(2.6 * scale, max(2.6, ambScale * 1.35), max(5.5, 2.6 * scale))
            : clamp(1.75 * scale, max(1.75, ambScale), max(4.0, 1.75 * scale));
        float maxCont = max(3.5, 1.35 * step / max(scale, 0.25));
        vec4 leftP = positionAt(pixel - vec2(step, 0)), rightP = positionAt(pixel + vec2(step, 0));
        vec4 upP = positionAt(pixel - vec2(0, step)), downP = positionAt(pixel + vec2(0, step));
        vec3 left = leftP.xyz, right = rightP.xyz, up = upP.xyz, down = downP.xyz;
        bool lOk = leftP.w < 0.75 && ((leftP.w < 0.25) == isSprite) && abs(p.z - left.z) < maxCont;
        bool rOk = rightP.w < 0.75 && ((rightP.w < 0.25) == isSprite) && abs(right.z - p.z) < maxCont;
        bool uOk = upP.w < 0.75 && ((upP.w < 0.25) == isSprite) && abs(p.z - up.z) < maxCont;
        bool dOk = downP.w < 0.75 && ((downP.w < 0.25) == isSprite) && abs(down.z - p.z) < maxCont;
        float creaseTol = max(2.2, 0.55 * step / max(scale, 0.25));
        float dLx = p.z - left.z, dRx = right.z - p.z;
        float dUy = p.z - up.z, dDy = down.z - p.z;
        bool xSmooth = lOk && rOk && abs(dRx - dLx) < creaseTol && (dRx * dLx >= -0.05);
        bool ySmooth = uOk && dOk && abs(dDy - dUy) < creaseTol && (dDy * dUy >= -0.05);
        float dxSpan = step;
        float dySpan = step;
        vec3 dx = xSmooth ? 0.5 * (right - left)
                : (lOk ? (p - left)
                : (rOk ? (right - p) : vec3(step / max(scale, 0.25), 0.0, 0.0)));
        vec3 dy = ySmooth ? 0.5 * (down - up)
                : (uOk ? (p - up)
                : (dOk ? (down - p) : vec3(0.0, step / max(scale, 0.25), 0.0)));
        float fineStep = max(1.0, ambScale);
        if (!lOk && !rOk && step > fineStep + 0.5) {
            float fineMaxCont = max(1.8, 1.35 * fineStep / max(scale, 0.25));
            vec4 lfP = positionAt(pixel - vec2(fineStep, 0.0)), rfP = positionAt(pixel + vec2(fineStep, 0.0));
            bool lfOk = lfP.w < 0.75 && ((lfP.w < 0.25) == isSprite) && abs(p.z - lfP.z) < fineMaxCont;
            bool rfOk = rfP.w < 0.75 && ((rfP.w < 0.25) == isSprite) && abs(rfP.z - p.z) < fineMaxCont;
            if (lfOk || rfOk) {
                dxSpan = fineStep;
                dx = (lfOk && rfOk) ? 0.5 * (rfP.xyz - lfP.xyz) : (lfOk ? (p - lfP.xyz) : (rfP.xyz - p));
            }
        }
        hasVertGrad = uOk || dOk;
        if (!uOk && !dOk && step > fineStep + 0.5) {
            float fineMaxCont = max(1.8, 1.35 * fineStep / max(scale, 0.25));
            vec4 ufP = positionAt(pixel - vec2(0.0, fineStep)), dfP = positionAt(pixel + vec2(0.0, fineStep));
            bool ufOk = ufP.w < 0.75 && ((ufP.w < 0.25) == isSprite) && abs(p.z - ufP.z) < fineMaxCont;
            bool dfOk = dfP.w < 0.75 && ((dfP.w < 0.25) == isSprite) && abs(dfP.z - p.z) < fineMaxCont;
            hasVertGrad = ufOk || dfOk;
            if (hasVertGrad) {
                dySpan = fineStep;
                dy = (ufOk && dfOk) ? 0.5 * (dfP.xyz - ufP.xyz) : (ufOk ? (p - ufP.xyz) : (dfP.xyz - p));
            }
        }
        if (isSprite) {
            float step2 = step * 2.0;
            float maxCont2 = max(6.0, 1.55 * step2 / max(scale, 0.25));
            vec4 l2P = positionAt(pixel - vec2(step2, 0)), r2P = positionAt(pixel + vec2(step2, 0));
            vec4 u2P = positionAt(pixel - vec2(0, step2)), d2P = positionAt(pixel + vec2(0, step2));
            vec3 l2 = l2P.xyz, r2 = r2P.xyz, u2 = u2P.xyz, d2 = d2P.xyz;
            bool l2Ok = lOk && l2P.w < 0.25 && abs(left.z - l2.z) < maxCont && abs(p.z - l2.z) < maxCont2 && abs((p.z - left.z) - (left.z - l2.z)) < creaseTol;
            bool r2Ok = rOk && r2P.w < 0.25 && abs(r2.z - right.z) < maxCont && abs(r2.z - p.z) < maxCont2 && abs((r2.z - right.z) - (right.z - p.z)) < creaseTol;
            bool u2Ok = uOk && u2P.w < 0.25 && abs(up.z - u2.z) < maxCont && abs(p.z - u2.z) < maxCont2 && abs((p.z - up.z) - (up.z - u2.z)) < creaseTol;
            bool d2Ok = dOk && d2P.w < 0.25 && abs(d2.z - down.z) < maxCont && abs(d2.z - p.z) < maxCont2 && abs((d2.z - down.z) - (down.z - p.z)) < creaseTol;
            if (xSmooth && l2Ok && r2Ok) dx = 0.25 * (r2 - l2);
            else if (!xSmooth && lOk && rOk) {
                float errL = l2Ok ? abs((p.z - left.z) - (left.z - l2.z)) : 1e4;
                float errR = r2Ok ? abs((r2.z - right.z) - (right.z - p.z)) : 1e4;
                dx = errR < errL ? (r2Ok ? 0.5 * (r2 - p) : (right - p)) : (l2Ok ? 0.5 * (p - l2) : (p - left));
            }
            if (ySmooth && u2Ok && d2Ok) dy = 0.25 * (d2 - u2);
            else if (!ySmooth && uOk && dOk) {
                float errU = u2Ok ? abs((p.z - up.z) - (up.z - u2.z)) : 1e4;
                float errD = d2Ok ? abs((d2.z - down.z) - (down.z - p.z)) : 1e4;
                dy = errD < errU ? (d2Ok ? 0.5 * (d2 - p) : (down - p)) : (u2Ok ? 0.5 * (p - u2) : (p - up));
            }
            float zSum = p.z * 2.0, zW = 2.0;
            const float Q_TOL = 2.2;
            if (lOk && (xSmooth || !rOk) && abs(left.z - p.z) < Q_TOL) { zSum += left.z; zW += 1.0; }
            if (rOk && (xSmooth || !lOk) && abs(right.z - p.z) < Q_TOL) { zSum += right.z; zW += 1.0; }
            if (uOk && (ySmooth || !dOk) && abs(up.z - p.z) < Q_TOL) { zSum += up.z; zW += 1.0; }
            if (dOk && (ySmooth || !uOk) && abs(down.z - p.z) < Q_TOL) { zSum += down.z; zW += 1.0; }
            if (xSmooth && l2Ok && abs(l2.z - p.z) < Q_TOL * 1.4) { zSum += l2.z * 0.5; zW += 0.5; }
            if (xSmooth && r2Ok && abs(r2.z - p.z) < Q_TOL * 1.4) { zSum += r2.z * 0.5; zW += 0.5; }
            if (ySmooth && u2Ok && abs(u2.z - p.z) < Q_TOL * 1.4) { zSum += u2.z * 0.5; zW += 0.5; }
            if (ySmooth && d2Ok && abs(d2.z - p.z) < Q_TOL * 1.4) { zSum += d2.z * 0.5; zW += 0.5; }
            pSmooth.z = zSum / zW;
        }
        vec3 rawCross = cross(dy, dx);
        float rawLen = length(rawCross);
        vec3 n = rawLen > 1e-5 ? rawCross / rawLen : vec3(0.0, 0.0, 1.0);
        if (n.z < 0.0) n = -n;
        nSurf = n;
        gradJump = max(abs(dx.z) / max(dxSpan / scale, 0.5), abs(dy.z) / max(dySpan / scale, 0.5));
        normal = centre.w > 0.25 ? n : normalize(mix(n, vec3(0, 0, 1), 0.25));
    }

    ivec2 vSize = textureSize(voxelMap, 0);
    bool hasVoxels = vSize.x > 1;
    int vAoRows = hasVoxels ? voxelAoRows(vSize) : 1;
    int vHalfH = vSize.x / 2 + 128 + 256 * vAoRows;
    int vAoSize = vSize.x / 4;
    int vAoYBase = vHalfH * 2;
    bool hasColBounds = hasVoxels && vAoSize > 0 && vSize.y >= vAoYBase + vAoSize;
    float vTopMarginHalf = float(64 + 256 * vAoRows);
    ivec2 vSliceMax = ivec2(vSize.x - 1, vHalfH - 1);
    vec2 lotSz = max(ambient.drift.zw, vec2(1.0));

    float simMaskVal = (centre.w < 0.25 && textureSize(simMaskMap, 0).x > 1)
        ? texture(simMaskMap, pixel / ambient.extent.xy).r
        : 0.0;
    float onAvatarMask = smoothstep(0.10, 0.45, simMaskVal);

    float radius = ambient.params.x;
    float thickness = ambient.params.w;
    float visibility = 1.0;
    vec3 bentNormal = normal;
    bool worldSpaceAO = ambient.sunLot.w > 0.0;
    bool runScreenGTAO = !worldSpaceAO && ambient.params.y > 0.001 && onAvatarMask < 0.5;
    if (runScreenGTAO) {
        visibility = 0.0;
        vec3 bentAccum = vec3(0.0);
        vec3 pAO = centre.w < 0.25 ? pSmooth + normal * 0.95 : p;
        float aoDistLimit = centre.w > 0.25 ? radius * 1.85 : radius;
        for (int slice = 0; slice < SLICES; slice++) {
            float phi = (float(slice) + 0.5) * PI / float(SLICES);
            vec2 direction = vec2(cos(phi), sin(phi));
            vec3 axis = vec3(direction.y, -direction.x, 0.0);
            vec3 projected = normal - axis * dot(normal, axis);
            float projectedLength = max(length(projected), 1e-4);
            float cosN = clamp(projected.z / projectedLength, -1.0, 1.0);
            float n = sign(dot(projected.xy, direction)) * acos(cosN);
            float sliceRadialShift = (float(slice) + 0.5) / float(SLICES);
            vec2 horizons = vec2(0.0);
            for (int side = 0; side < 2; side++) {
                vec2 sideDirection = side == 0 ? direction : -direction;
                float best = -1.0;
                for (int i = 0; i < STEPS; i++) {
                    float t = (float(i) + sliceRadialShift) / float(STEPS);
                    vec2 offset = sideDirection * (radius * t * t + 1.5) * scale;
                    vec2 samplePixel = pixel + offset;
                    if (any(lessThan(samplePixel, vec2(0))) || samplePixel.x >= ambient.extent.x || samplePixel.y >= ambient.extent.y) break;
                    vec4 samplePos = positionAt(samplePixel);
                    if (samplePos.w > 0.75 || (centre.w < 0.25 && samplePos.w > 0.25)) continue;
                    vec3 delta = samplePos.xyz - pAO;
                    float distance = length(delta);
                    float distW = smoothstep(1.0, 0.0, distance / max(aoDistLimit, 1.0));
                    float falloff = distW * distW * clamp((thickness - delta.z) / (0.5 * thickness), 0.0, 1.0);
                    float cosine = mix(-1.0, delta.z / max(distance, 1e-4), falloff);
                    best = max(best, cosine);
                }
                if (side == 0) horizons.x = acos(clamp(best, -1.0, 1.0));
                else horizons.y = -acos(clamp(best, -1.0, 1.0));
            }
            float h1 = n + min(horizons.x - n, PI / 2.0);
            float h0 = n + max(horizons.y - n, -PI / 2.0);
            float sinN = sin(n);
            float sliceVis = projectedLength * 0.25 * ((-cos(2.0 * h0 - n) + cosN + 2.0 * h0 * sinN) + (-cos(2.0 * h1 - n) + cosN + 2.0 * h1 * sinN));
            visibility += sliceVis;
            float bentAng = 0.5 * (h0 + h1);
            vec3 sliceBent = vec3(direction * sin(bentAng), cos(bentAng));
            bentAccum += sliceBent * max(sliceVis, 0.02);
        }
        visibility = clamp(visibility / float(SLICES), 0.0, 1.0);
        float bentLen = length(bentAccum);
        if (bentLen > 1e-4) {
            bentNormal = normalize(mix(normal, bentAccum / bentLen, clamp(ambient.params.y, 0.0, 1.0)));
        }
    }
    const float aoAlbedo = 0.22;
    float mbA = 2.0404 * aoAlbedo - 0.3324;
    float mbB = -4.7951 * aoAlbedo + 0.6417;
    float mbC = 2.7552 * aoAlbedo + 0.6903;
    float multiBounceVis = pow(clamp(visibility * (visibility * (mbA * visibility + mbB) + mbC), 0.0, 1.0), 1.30);
    float occlusion = clamp(mix(1.0, multiBounceVis, ambient.params.y), 0.20, 1.0);

    const vec3 WORLD_UP = vec3(0.0, -0.8660254, 0.5);
    const vec3 WORLD_TOWARD = vec3(0.0, 0.5, 0.8660254);

    float key = centre.w < 0.25 ? (0.62 - texelFetch(depthMap, fullPx, 0).r) / 0.003
                                : (0.62 - texelFetch(groundMap, fullPx, 0).r) / 0.003 + ambient.view.w;
    vec3 here = lotPoint(p.xy, key, centre.w > 0.25, ambient.frame.xy);
    float riseHere;
    if (centre.w > 0.25) {
        riseHere = 0.0;
    } else if (ambient.sunLot.w > 0.0 && textureSize(overheadMap, 0).x > 1) {
        float gAtHere = groundAt(pixel);
        float fallbackBaseZ = gAtHere > -1.0e4
            ? lotPoint(p.xy, gAtHere / DEPTH_UNIT, true, ambient.frame.xy).z
            : terrainBaseClamped(here.xy, ambient.contact.w);
        float groundBaseZ = terrainBaseAt(here.xy, fallbackBaseZ);
        riseHere = max(0.0, here.z - groundBaseZ) * 40.0;
    } else {
        riseHere = (groundAt(pixel) < -1.0e4 || groundAt(pixel + vec2(0.0, 4.0)) < -1.0e4)
            ? max(20.0, (here.z - ambient.contact.w) * 40.0)
            : riseAt(pixel, p.z);
    }
    float onGround = 1.0 - smoothstep(2.0, 6.0, riseHere);
    vec4 lift = textureSize(liftMap, 0).x > 1 ? texelFetch(liftMap, fullPx, 0) : vec4(0.0);
    bool onSnow = lift.z > 0.5;
    if (onSnow) {
        here += vec3(0.5 * lift.x, 0.5 * lift.x, lift.y);
        onGround = 1.0;
        occlusion = 1.0;
    }
    ivec2 hereCell = ivec2(floor(here.xy + ambient.frame.w));
    int storiesCount = indoorStories();
    float hereBase0 = floorAt(hereCell, 0, here.z);
    int candUpperRow = clamp(int(floor((here.z - hereBase0) / STORY_HEIGHT + 0.5)), 1, max(1, storiesCount - 1));
    float floor2Z = candUpperRow < storiesCount ? floorAt(hereCell, candUpperRow, -100.0) : -100.0;
    float onLevel2Floor = floor2Z > -50.0
        ? (1.0 - smoothstep(0.08, 0.22, abs(here.z - floor2Z))) * smoothstep(0.55, 0.82, dot(nSurf, WORLD_UP))
        : 0.0;
    float onFlatFloor = max(onGround, onLevel2Floor);
    float onDynamicSim = onAvatarMask;
    if (onDynamicSim < 0.99 && hasVoxels && ambient.shadowView.w > 0.5 && centre.w < 0.25) {
        vec2 wpSelf = ambient.shadowView.xy + p.xy * ambient.shadowView.z;
        if (wpSelf.x >= ambient.dynShadowBounds.x && wpSelf.y >= ambient.dynShadowBounds.y &&
            wpSelf.x <= ambient.dynShadowBounds.z && wpSelf.y <= ambient.dynShadowBounds.w) {
            vec2 wSize = vec2(textureSize(worldDepthMap, 0));
            if (all(greaterThanEqual(wpSelf, vec2(0.0))) && all(lessThan(wpSelf, wSize))) {
                float wSelf = texelFetch(worldDepthMap, clamp(ivec2(floor(wpSelf)), ivec2(0), ivec2(wSize) - 1), 0).r;
                if (wSelf < 0.9999 && abs((0.62 - wSelf) / 0.003 - key) < 0.55) {
                    onDynamicSim = 1.0;
                }
            }
        }
    }
    float roofSnow = lift.w;
    vec3 matchedWallPos = here;
    vec2 matchedWallN = vec2(0.0);
    float archWallMatch = 0.0;
    if (worldSpaceAO && !onSnow && centre.w < 0.25 && onFlatFloor < 0.5 && onDynamicSim < 0.5 && roofSnow < 0.5) {
        float upCheck = hasVertGrad ? dot(nSurf, WORLD_UP) : 0.0;
        float wallStoryRel = max(0.0, (here.z - hereBase0) - floor(max(0.0, here.z - hereBase0 + 0.05) / STORY_HEIGHT) * STORY_HEIGHT);
        float midWallBand = smoothstep(0.46, 0.60, wallStoryRel) * (1.0 - smoothstep(STORY_HEIGHT - 0.28, STORY_HEIGHT - 0.14, wallStoryRel));
        float upLo = mix(0.28, 0.56, midWallBand);
        float upHi = mix(0.44, 0.72, midWallBand);
        if (upCheck < upHi) {
            archWallMatch = matchArchWall(here, p.xy, key, nSurf.x, matchedWallPos, matchedWallN);
            if (archWallMatch > 0.001) {
                archWallMatch *= 1.0 - smoothstep(upLo, upHi, upCheck);
                vec2 wallPlaneXY = matchedWallPos.xy - matchedWallN * 0.035;
                float frontOfWall = smoothstep(-0.025, 0.020, dot(here.xy - wallPlaneXY, matchedWallN));
                if (hasVoxels && frontOfWall > 0.001) {
                    vec3 hullProbe = vec3(wallPlaneXY + matchedWallN * 0.14, here.z);
                    float selfHull = frontOfWall * dualViewHullSolid(hullProbe, vSize, vHalfH, vTopMarginHalf, vSliceMax, lotSz, 0.09);
                    archWallMatch *= 1.0 - smoothstep(0.20, 0.68, selfHull);
                }
            }
        }
    }
    float highRoof = (!onSnow && hasVertGrad && archWallMatch < 0.5 && centre.w < 0.25 && onLevel2Floor < 0.25 && ambient.sunLot.w > 0.0 && riseHere > 115.0 && indoors(here) < 0.20)
        ? smoothstep(115.0, 124.0, riseHere) * smoothstep(0.32, 0.60, dot(normal, WORLD_UP)) * (1.0 - archWallMatch)
        : 0.0;
    float roofCalm = clamp(max(roofSnow, highRoof), 0.0, 1.0);
    if (roofCalm > 0.01) {
        occlusion = mix(occlusion, 1.0 - (1.0 - occlusion) * 0.14, roofCalm);
    }
    if (worldSpaceAO && onLevel2Floor > 0.01) {
        occlusion = mix(occlusion, 1.0, onLevel2Floor);
    }
    float wallFloor = 0.0;
    if (onFlatFloor > 0.5 && worldSpaceAO && (ambient.params.y > 0.001 || (onSnow && ambient.contact.y > 0.0))) {
        wallFloor = floorWallAO(here);
        if (!onSnow && ambient.params.y > 0.001) {
            occlusion *= 1.0 - 0.42 * clamp(ambient.params.y, 0.0, 1.0) * clamp(wallFloor, 0.0, 1.35);
        }
    }
    float contact = 1.0;
    if (worldSpaceAO) {
        if ((centre.w > 0.25 || onSnow || onLevel2Floor > 0.5) && (ambient.contact.y > 0.0 || (!onSnow && hasVoxels && ambient.params.y > 0.001))) {
            if (hasVoxels) {
                int levelRow = onLevel2Floor > 0.5 ? candUpperRow : 0;
                float voxelContact = 0.0;
                float voxelHemi = voxelGroundAO(here, levelRow, vSize, voxelContact);
                float borderDist = min(min(here.x, lotSz.x - here.x), min(here.y, lotSz.y - here.y));
                if (onLevel2Floor <= 0.5 && borderDist < 0.35) {
                    float wOff = 1.0 - smoothstep(-0.05, 0.35, borderDist);
                    float offContact = 0.0;
                    float offHemi = offLotGroundAO(here, scale, offContact);
                    voxelContact = max(voxelContact, offContact * wOff);
                    voxelHemi = max(voxelHemi, offHemi * wOff);
                }
                if (!onSnow && ambient.params.y > 0.001) {
                    float voxelVis = 1.0 - 0.36 * clamp(ambient.params.y, 0.0, 1.0) * voxelHemi;
                    occlusion = max(occlusion * voxelVis, 0.30);
                }
                if (ambient.contact.y > 0.0) {
                    float combinedContact = voxelContact;
                    if (onSnow) {
                        combinedContact = max(combinedContact, 0.55 * clamp(wallFloor, 0.0, 1.0));
                    }
                    contact = 1.0 - ambient.contact.y * clamp(combinedContact, 0.0, 1.0);
                }
            } else if (ambient.contact.y > 0.0) {
                const float FOOT_REACH = 0.22;
                float detail = ambient.frame.z;
                ivec2 footSize = textureSize(footMap, 0);
                vec2 invFootSize = 1.0 / vec2(footSize);
                vec2 at = (here.xy + ambient.frame.w) * detail;
                float best = 0.0, sum = 0.0;
                ivec2 base = ivec2(floor(at - 1.5));
                for (int qy = 0; qy < 4; qy += 2) {
                    for (int qx = 0; qx < 4; qx += 2) {
                        ivec2 qb = base + ivec2(qx, qy);
                        if (qb.x + 1 < 0 || qb.y + 1 < 0 || qb.x >= footSize.x || qb.y >= footSize.y) continue;
                        vec4 g = textureGather(footMap, (vec2(qb) + 1.0) * invFootSize);
                        if (min(min(g.x, g.y), min(g.z, g.w)) >= 1.0) continue;
                        for (int k = 0; k < 4; k++) {
                            float stored = k == 0 ? g.x : (k == 1 ? g.y : (k == 2 ? g.z : g.w));
                            if (stored >= 1.0) continue;
                            ivec2 qo = k == 0 ? ivec2(0, 1) : (k == 1 ? ivec2(1, 1) : (k == 2 ? ivec2(1, 0) : ivec2(0, 0)));
                            ivec2 texel = qb + qo;
                            if (any(lessThan(texel, ivec2(0))) || any(greaterThanEqual(texel, footSize))) continue;
                            float footZ = (0.5 - stored) * HEIGHT_RANGE;
                            if (abs(footZ - here.z) > 0.25) continue;
                            float near = max(0.0, 1.0 - length((vec2(texel) + 0.5 - at) / detail) / FOOT_REACH);
                            float w = pow(near, 1.35);
                            best = max(best, w);
                            sum += w;
                        }
                    }
                }
                float feet = max(clamp(0.82 * best + 0.035 * sum, 0.0, 1.0), simFootAO(here));
                vec2 gridSize = vec2(textureSize(heightMap, 0));
                vec2 hCenter = (here.xy + ambient.frame.w) * ambient.frame.z;
                float over = (0.5 - texture(heightMap, hCenter / gridSize).r) * HEIGHT_RANGE - here.z;
                float under = smoothstep(0.2, 0.4, over) * (1.0 - smoothstep(2.0, 2.6, over));
                contact = 1.0 - ambient.contact.y * clamp(feet + 0.35 * under, 0.0, 1.0);
            }
        }
    } else if (onGround > 0.0 && ambient.contact.y > 0.0) {
        float contactRadius = ambient.contact.x;
        vec2 footHere = p.xy + vec2(0.0, riseHere);
        float covered = 0.0;
        for (int d = 0; d < CONTACT_DIRECTIONS; d++) {
            float phi = (float(d) + 0.5) * 2.0 * PI / float(CONTACT_DIRECTIONS);
            vec2 direction = vec2(cos(phi), sin(phi));
            float dirShift = 0.20 + 0.25 * float(d & 1);
            float best = 0.0;
            for (int i = 1; i <= CONTACT_STEPS; i++) {
                float t = (float(i) - dirShift) / float(CONTACT_STEPS);
                vec2 samplePixel = pixel + direction * contactRadius * t * scale;
                if (any(lessThan(samplePixel, vec2(0))) || samplePixel.x >= ambient.extent.x || samplePixel.y >= ambient.extent.y) break;
                vec4 q = positionAt(samplePixel);
                if (q.w > 0.75) continue;
                float rise = riseAt(samplePixel, q.z);
                float height = (rise - riseHere) / 0.8660254;
                float along = length((q.xy + vec2(0.0, rise) - footHere) * vec2(1.0, 2.0));
                if (height < 1.0 || along > contactRadius) continue;
                float near = 1.0 - along / contactRadius;
                best = max(best, height / (height + 0.5 * along + 2.0) * near);
            }
            covered += best;
        }
        contact = 1.0 - ambient.contact.y * onGround * clamp(covered / float(CONTACT_DIRECTIONS) * 4.0, 0.0, 1.0);
    }

    float nUp = dot(nSurf, WORLD_UP);
    float nToward = dot(nSurf, WORLD_TOWARD);
    float nRight = nSurf.x;
    vec3 nLot = vec3((nToward + nRight) * 0.70710678, (nToward - nRight) * 0.70710678, nUp);
    vec2 horizN = length(nLot.xy) > 0.15 ? normalize(nLot.xy) : vec2(0.0);

    float isVertical = 0.0;
    vec3 hereSurf = here;
    if (worldSpaceAO) {
        if (archWallMatch > 0.001) {
            isVertical = archWallMatch * (1.0 - onFlatFloor) * (1.0 - roofCalm) * (1.0 - onDynamicSim);
            hereSurf = mix(here, matchedWallPos, archWallMatch);
            horizN = matchedWallN;
            vec3 wallViewN = normalize(WORLD_TOWARD * ((matchedWallN.x + matchedWallN.y) * 0.70710678)
                                     + vec3((matchedWallN.x - matchedWallN.y) * 0.70710678, 0.0, 0.0));
            nSurf = normalize(mix(nSurf, wallViewN, archWallMatch));
            normal = normalize(mix(normal, normalize(mix(wallViewN, vec3(0.0, 0.0, 1.0), 0.25)), archWallMatch));
            nUp = dot(nSurf, WORLD_UP);
            nLot = vec3(matchedWallN, 0.0);
        }
    } else {
        isVertical = (1.0 - onFlatFloor)
            * (1.0 - smoothstep(0.22, 0.42, abs(nUp)))
            * (1.0 - roofCalm)
            * (1.0 - smoothstep(2.5, 4.5, gradJump))
            * (1.0 - onDynamicSim);
    }
    if (onDynamicSim > 0.01) {
        occlusion = mix(occlusion, 1.0 - (1.0 - occlusion) * 0.20, onDynamicSim);
    }

    float inside = 0.0;
    if (ambient.sunLot.w > 0.0) {
        vec2 insideOffset = mix(horizN * 0.25, vec2(0.0), onFlatFloor);
        inside = indoors(hereSurf + vec3(insideOffset, 0.0));
    }

    float hereRelZ = hereSurf.z - terrainBaseAt(hereSurf.xy, hereSurf.z);
    float vertSkyLift = 1.0;
    if (isVertical > 0.01 && !onSnow && onDynamicSim < 0.5 && ambient.params.y > 0.001) {
        vec3 hereWall = (centre.w < 0.25 && !worldSpaceAO) ? lotPoint(p.xy, pSmooth.z / DEPTH_UNIT, false, ambient.frame.xy) : hereSurf;
        float wallRelZ = hereWall.z - terrainBaseAt(hereWall.xy, hereWall.z);
        float aoStr = clamp(ambient.params.y, 0.0, 1.0) * isVertical;
        float zWall = max(0.0, wallRelZ);
        float storyIdx = floor(max(0.0, wallRelZ + 0.05) / STORY_HEIGHT);
        float storyRelZ = max(0.0, wallRelZ - storyIdx * STORY_HEIGHT);
        float zNorm = zWall / STORY_HEIGHT;
        float ramp = zNorm / (0.70 + zNorm);
        float rawVertGrad = mix(0.54, 1.20, ramp);
        vertSkyLift = mix(1.0, rawVertGrad, aoStr);
        float groundCrease = exp(-zWall / 0.11) * (1.0 - smoothstep(0.26, 0.52, zWall));
        float upperFloorCrease = step(0.5, storyIdx) * inside * exp(-storyRelZ / 0.09) * (1.0 - smoothstep(0.20, 0.42, storyRelZ));
        float baseAO = 1.0 - aoStr * clamp(0.22 * groundCrease + 0.14 * upperFloorCrease, 0.0, 0.32);
        float cornerOcc = worldSpaceAO ? wallCornerAO(hereWall, horizN) : 0.0;
        float cornerAO = 1.0 - 0.34 * aoStr * cornerOcc;
        float wallFloorZ = (hereWall.z - wallRelZ) + storyIdx * STORY_HEIGHT;
        float staticWallOcc = (hasVoxels && worldSpaceAO)
            ? voxelWallAO(hereWall, horizN, wallFloorZ, vSize, vHalfH, vTopMarginHalf, vSliceMax, lotSz) * (1.0 - 0.72 * cornerOcc)
            : 0.0;
        float simWallOcc = worldSpaceAO ? simWallProximityAO(hereWall, horizN) * (1.0 - 0.65 * cornerOcc) : 0.0;
        float combinedWallOcc = max(staticWallOcc, simWallOcc);
        float vWallOcc = staticWallOcc + (combinedWallOcc - staticWallOcc) * 0.50;
        float vWallAO = 1.0 - 0.44 * aoStr * vWallOcc;
        occlusion = mix(occlusion, 1.0, 0.72 * isVertical * cornerOcc);
        occlusion = max(occlusion * baseAO * cornerAO * vWallAO, 0.22);
    }
    if (!onSnow && centre.w < 0.25 && onFlatFloor < 0.5 && onDynamicSim < 0.5 && roofCalm < 0.5 && isVertical < 0.99 && worldSpaceAO && ambient.params.y > 0.001) {
        float aoParam = clamp(ambient.params.y, 0.0, 1.0) * (1.0 - isVertical);
        float zProp = max(0.0, hereRelZ);
        float propNorm = zProp / STORY_HEIGHT;
        float propGrad = mix(0.82, 1.06, propNorm / (0.65 + propNorm));
        vertSkyLift *= mix(1.0, propGrad, aoParam);
        float storySpriteZ = max(0.0, hereRelZ - floor(max(0.0, hereRelZ + 0.05) / STORY_HEIGHT) * STORY_HEIGHT);
        int spriteRow = clamp(int(floor((hereRelZ + 0.15) / STORY_HEIGHT)), 0, storiesCount - 1);
        float spriteOcc = 0.0;
        if (storySpriteZ < 0.52) {
            float selfBase = 0.55;
            float clusterDensity = 0.0;
            if (hasVoxels && all(greaterThanEqual(here.xy, vec2(0.0))) && all(lessThan(here.xy, lotSz))) {
                vec3 selfGround = sampleBakedGroundAO(here.xy, spriteRow, vSize);
                selfBase = clamp(selfGround.r * 0.65 + selfGround.g * 0.42, 0.0, 1.0);
                clusterDensity = selfGround.b;
            }
            float rootFade = 1.0 - smoothstep(0.03, 0.25, storySpriteZ);
            float bodyFade = 1.0 - smoothstep(0.06, 0.52, storySpriteZ);
            spriteOcc += 0.20 * selfBase * rootFade + 0.14 * clusterDensity * bodyFade;
        }
        float wallCrevice = spriteWallProximityAO(here, spriteRow) * (1.0 - smoothstep(STORY_HEIGHT - 0.35, STORY_HEIGHT, storySpriteZ));
        spriteOcc += 0.26 * wallCrevice;
        if (hasVoxels) {
            float gapClear = 1.0 - dualViewHullAtPrecomp(here + vec3(0.0, 0.0, 0.26), vSize, vHalfH, vTopMarginHalf, vSliceMax, lotSz, 0.5);
            if (gapClear > 0.35) {
                float overNear = dualViewHullAtPrecomp(here + vec3(0.0, 0.0, 0.52), vSize, vHalfH, vTopMarginHalf, vSliceMax, lotSz, 1.2);
                float overFar = dualViewHullAtPrecomp(here + vec3(0.0, 0.0, 0.90), vSize, vHalfH, vTopMarginHalf, vSliceMax, lotSz, 1.6);
                spriteOcc += 0.24 * gapClear * max(overNear * 0.85, overFar * 0.55);
            }
        }
        occlusion = max(occlusion * (1.0 - aoParam * clamp(spriteOcc, 0.0, 0.58)), 0.32);
    }

    float lit = 1.0, litColumn = 1.0, litShell = 1.0;
    float window = 0.0;
    if (ambient.sunLot.w > 0.0 && ambient.params.z > 0.001 && textureSize(sunShadowMap, 0).x > 1) {
        vec4 sunTap = texelFetch(sunShadowMap, ivec2(gl_FragCoord.xy), 0);
        lit = sunTap.x;
        window = sunTap.y;
        litColumn = sunTap.z;
        litShell = sunTap.w;
    }
    float sky = ambient.sunLot.w > 0.0 ? cloudLight(here) : 1.0;
    window *= sky;
    lit *= sky;
    float shadowStr = clamp(ambient.params.z * mix(1.0, 0.68, inside) * (1.0 + 0.28 * isVertical * (1.0 - 0.55 * inside)) * mix(1.0, 0.72, roofCalm), 0.0, 0.85);
    float shadow = mix(1.0, lit, shadowStr);

    vec3 lampLight = vec3(0.0);
    vec3 fireLight = vec3(0.0);
    float maxNearBulb = 0.0;
    int lampCount = int(ambient.lamp.x);
    float reach = ambient.lamp.y;
    bool sides = ambient.sunLot.w > 0.0;
    float tFire = ambient.weather.z;
    vec3 pLamp = vec3(p.xy, (here.x + here.y + 0.8 * here.z) * DEPTH_UNIT);
    float isObjectSprite = (centre.w < 0.25 ? 1.0 : 0.0)
        * (1.0 - onFlatFloor)
        * (1.0 - isVertical)
        * (1.0 - roofCalm)
        * (1.0 - onDynamicSim);
    vec3 spriteLampNormal = normalize(mix(nSurf, vec3(0.0, 0.0, 1.0), max(mix(0.36, 0.85, onDynamicSim), 0.78 * isObjectSprite)));
    vec3 lampNormal = centre.w > 0.25 ? nSurf : normalize(mix(spriteLampNormal, nSurf, onLevel2Floor));
    float fireGainEst = ambient.lamp.z * mix(2.35, 1.15, smoothstep(0.35, 1.35, ambient.lamp.z));
    if (lampCount > 0 && (ambient.lamp.z > 0.001 || ambient.extent.z > 5.5)) {
        for (int index = 0; index < MAX_LAMPS; index++) {
            if (index >= lampCount) break;
            vec4 lamp = ambient.lamps[index];
            bool isFire = lamp.w < 0.0;
            float strength = abs(lamp.w);
            vec3 toLamp = vec3(lamp.xy, lamp.z * DEPTH_UNIT) - pLamp;
            float distance = length(toLamp);
            float flicker01 = 0.5;
            float flicker = 1.0;
            if (isFire) {
                float phase = dot(lamp.xy, vec2(0.037, 0.053));
                float wave = 0.50 * sin(tFire * 5.7 + phase)
                           + 0.32 * sin(tFire * 11.3 + phase * 1.7 + 1.1)
                           + 0.18 * sin(tFire * 19.1 + phase * 2.3 + 2.4);
                flicker01 = clamp(0.5 + 0.5 * wave, 0.0, 1.0);
                flicker = 0.84 + 0.30 * flicker01;
            }
            float lampReach = isFire ? reach * (1.42 + 0.08 * flicker01) : reach * 1.35;
            if (distance >= lampReach) continue;
            vec3 direction = toLamp / max(distance, 1e-4);
            float normD = clamp(distance / max(lampReach, 1e-4), 0.0, 1.0);
            float win = clamp(1.0 - normD * normD, 0.0, 1.0);
            float falloff = 1.12 * (win * win) / (1.0 + 11.0 * normD * normD);
            float nearBulb = 1.0 - smoothstep(14.0, 34.0, distance);
            float facing = isFire
                ? clamp(dot(lampNormal, direction) * 0.65 + 0.35, 0.0, 1.0)
                : clamp(dot(lampNormal, direction) * 0.72 + 0.28, 0.0, 1.0);
            facing = mix(facing, 1.0, nearBulb);
            float rawContrib = strength * flicker * falloff * facing;
            if (rawContrib < 0.0012) continue;
            if (ambient.extent.z < 0.5 && rawContrib * (isFire ? fireGainEst : ambient.lamp.z) < 0.0005) continue;
            vec3 lampLot = vec3(0.0);
            float sameSide = 1.0;
            if (sides) {
                lampLot = lotPoint(lamp.xy, lamp.z, false, ambient.frame.xy);
                if (indoors(lampLot) > 0.25 && (roofCalm > 0.20 || (inside < 0.25 && hereSurf.z > lampLot.z + 1.0))) continue;
                sameSide = lampFloorVis(hereSurf, lampLot, onFlatFloor);
                if (sameSide <= 0.01) continue;
                sameSide *= lampWallVis(hereSurf, lampLot, onFlatFloor, horizN);
                if (sameSide <= 0.01) continue;
            }
            float contrib = rawContrib * sameSide;
            if (contrib < 0.0012) continue;
            falloff *= smoothstep(0.0012, 0.0035, contrib);
            maxNearBulb = max(maxNearBulb, nearBulb * clamp(strength * falloff * sameSide, 0.0, 1.0));
            float open = 1.0;
            if (sides) {
                open = lampMarch(hereSurf, lampLot, onFlatFloor, isVertical, nUp, mix(horizN, vec2(0.0), onDynamicSim), isFire, onDynamicSim);
            } else {
                for (int i = 1; i < LAMP_STEPS; i++) {
                    float t = (float(i) - 0.5) / float(LAMP_STEPS) * distance;
                    if (isFire && distance - t < 22.0) continue;
                    vec3 q = pLamp + direction * t;
                    vec2 samplePixel = ambient.view.xy + q.xy * scale;
                    if (any(lessThan(samplePixel, vec2(0))) || samplePixel.x >= ambient.extent.x || samplePixel.y >= ambient.extent.y) break;
                    vec4 samplePos = positionAt(samplePixel);
                    float sampleZ = samplePos.z;
                    if (samplePos.w > 0.25 && samplePos.w < 0.75) {
                        vec3 sampleLot = lotPoint(samplePos.xy, samplePos.z / DEPTH_UNIT, true, ambient.frame.xy);
                        sampleZ = (sampleLot.x + sampleLot.y + 0.8 * sampleLot.z) * DEPTH_UNIT;
                    }
                    float h = sampleZ - q.z;
                    if (h > 2.0) {
                        float thickFade = 1.0 - smoothstep(0.65 * thickness, thickness, h);
                        open = min(open, 1.0 - thickFade * clamp((h - 2.0) / (0.1 * t + 3.0), 0.0, 1.0));
                    }
                }
            }
            if (isFire) {
                vec3 fireTint = mix(vec3(1.0, 0.24, 0.03), vec3(1.0, 0.42, 0.08), flicker01);
                fireLight += fireTint * (strength * flicker * falloff * facing * open * sameSide);
            } else {
                vec3 coreLampCol = mix(vec3(1.08, 0.98, 0.86), LAMP_COLOR, smoothstep(0.08, 0.65, normD));
                lampLight += coreLampCol * (strength * falloff * facing * open * sameSide);
            }
        }
    }
    float nightFactor = clamp(ambient.weather.w, 0.0, 1.0);
    float lowSun = 1.0 - smoothstep(0.12, 0.52, ambient.sunLot.z);
    float dayProgress = ambient.tone.w >= 0.0 ? clamp(ambient.tone.w, 0.0, 1.0) : (0.5 + 0.45 * lowSun);
    vec3 warmSun, coolShade, dayWindowColor;
    dayPalette(dayProgress, warmSun, coolShade, dayWindowColor);
    vec3 moonWindowColor = vec3(0.68, 0.82, 1.18);
    vec3 windowColor = mix(dayWindowColor, moonWindowColor, smoothstep(0.55, 0.90, nightFactor));
    float fireBoost = mix(2.35, 1.15, smoothstep(0.35, 1.35, ambient.lamp.z));
    vec3 lamps = ambient.lamp.z * lampLight;
    vec3 fires = ambient.lamp.z * fireBoost * fireLight;
    float firePeak = max(fires.r, max(fires.g, fires.b));
    if (firePeak > 1.35) {
        float compressed = 1.35 + (firePeak - 1.35) / (1.0 + (firePeak - 1.35) * 1.6);
        fires *= compressed / firePeak;
    }
    vec3 totalLamps = lamps + fires;

    float outdoor = 1.0 - inside;
    float sunWeight = mix(1.0, 0.70, inside);
    vec3 sunViewDir = normalize(ambient.light.xyz + vec3(0.0, 0.0, 1e-4));
    float keyWrap = dot(normal, sunViewDir);
    float bentSunOcc = runScreenGTAO
        ? mix(1.0, smoothstep(-0.40, 0.55, dot(bentNormal, sunViewDir)), 0.28 * (1.0 - onFlatFloor) * (1.0 - roofCalm) * (1.0 - isVertical) * (1.0 - onDynamicSim))
        : 1.0;
    float shadowActive = clamp(ambient.params.z * 1.8, 0.0, 1.0) * (1.0 - 0.80 * nightFactor);
    float dirShade = 1.0 + (keyWrap * 0.20 - 0.04) * mix(1.0, 0.55, inside) * lit * shadowActive * (1.0 - 0.45 * onFlatFloor) * (1.0 - onDynamicSim) * (1.0 - 0.88 * isObjectSprite);
    dirShade *= mix(1.0, bentSunOcc, shadowActive * lit);
    float deBakeWeight = smoothstep(0.02, 0.10, ambient.params.z) * (1.0 - 0.85 * nightFactor);
    float wallDeBake = exp(-0.42 * clamp(nSurf.x, -0.70, 0.70) * isVertical * deBakeWeight);
    dirShade *= wallDeBake;
    float sunBloom = 1.0 + 0.12 * (1.0 - nightFactor) * lit * sunWeight * shadowActive;

    float bentUp = clamp(dot(mix(bentNormal, WORLD_UP, 0.5 * isObjectSprite), WORLD_UP) * 0.5 + 0.5, 0.0, 1.0);
    vec3 skyFill = vec3(0.84, 0.93, 1.14);
    vec3 groundBounce = vec3(1.12, 1.03, 0.86);
    vec3 hemiGI = mix(groundBounce, skyFill, bentUp);
    hemiGI /= dot(hemiGI, LUMA);
    float giStrength = (1.0 - nightFactor) * (1.0 - lit * 0.55) * mix(0.32, 0.16, inside) * (1.0 - 0.65 * onFlatFloor) * (1.0 - 0.75 * isVertical) * (1.0 - 0.70 * isObjectSprite);

    vec3 bounceAlbedo = vec3(0.28);
    bool hasSceneAlbedo = false;
    if (!onSnow && textureSize(sceneColorMap, 0).x > 1) {
        vec4 baseCol = texelFetch(sceneColorMap, fullPx, 0);
        if (baseCol.a > 0.02) {
            vec3 rawAlb = clamp(baseCol.rgb, vec3(0.03), vec3(0.88));
            float rawLum = max(dot(rawAlb, LUMA), 1e-4);
            bounceAlbedo = clamp(rawAlb * (mix(0.34, rawLum, 0.46) / rawLum), vec3(0.05), vec3(0.76));
            hasSceneAlbedo = true;
        }
    }
    vec3 mbOcc = (!onSnow && hasSceneAlbedo && occlusion < 0.999)
        ? mix(vec3(occlusion), multiBounceAO(occlusion, bounceAlbedo), 0.64)
        : vec3(occlusion);

    vec3 roomBounceGI = (!onSnow && worldSpaceAO && ambient.params.y > 0.001)
        ? gatherRoomBounceGI(hereSurf, horizN, nLot.xy, isVertical, onFlatFloor, onDynamicSim, storiesCount)
        : vec3(0.0);
    float bounceShadeMask = (1.0 - 0.68 * lit * clamp(shadowStr * 1.6, 0.0, 1.0)) * mix(0.22, 1.0, inside);
    vec3 giTerm = roomBounceGI * (0.30 * clamp(ambient.params.y, 0.0, 1.2) * bounceShadeMask) * mix(vec3(1.0), mbOcc, 0.45);

    float effVertGrad = mix(mix(vertSkyLift, mix(vertSkyLift, 1.03, 0.22), lit * shadowActive), 1.0, 0.65 * maxNearBulb);
    vec3 envBase = (dirShade * effVertGrad) * sunBloom * ambient.lamp.w * mix(vec3(1.0), hemiGI, giStrength);
    vec3 skyTerm = (1.0 - shadowStr) * envBase;
    vec3 sunTerm = (shadowStr * lit) * envBase + 0.22 * ambient.contact.z * window * windowColor;
    vec3 ambOcc = mix(mbOcc * contact, vec3(1.0), maxNearBulb);
    float sunOccCouple = mix(0.08, 0.38, isVertical);
    vec3 sunMicroOcc = mix(mix(vec3(1.0), mbOcc, sunOccCouple) * mix(1.0, contact, 0.26), vec3(1.0), maxNearBulb);
    vec3 lampOcc = mix(mix(vec3(1.0), mbOcc, 0.52) * mix(1.0, contact, 0.58), vec3(1.0), maxNearBulb);
    vec3 light = ambOcc * skyTerm + sunMicroOcc * sunTerm + lampOcc * totalLamps + giTerm;

    float daylight = 1.0 - nightFactor;
    vec3 sunTint = mix(coolShade, warmSun, lit);
    sunTint /= dot(sunTint, LUMA);
    float fireShare = dot(fires, LUMA) / (ambient.lamp.w + dot(fires, LUMA) + 1e-4);
    vec3 tint = mix(vec3(1.0), sunTint, clamp(ambient.tone.x, 0.0, 1.35) * daylight * mix(1.0, 0.65, inside) * (1.0 - 0.85 * fireShare));

    float twilight = dayProgress < 0.5
        ? smoothstep(0.55, 0.80, nightFactor) * (1.0 - smoothstep(0.85, 0.98, nightFactor))
        : smoothstep(0.28, 0.58, nightFactor) * (1.0 - smoothstep(0.72, 0.96, nightFactor));
    vec3 blueHour = vec3(0.76, 0.88, 1.24) / dot(vec3(0.76, 0.88, 1.24), LUMA);
    float lampShare = dot(totalLamps, LUMA) / (ambient.lamp.w + dot(totalLamps, LUMA) + 1e-4);
    tint = mix(tint, blueHour, twilight * mix(1.0, 0.35, inside) * ambient.tone.x * 0.70 * (1.0 - lampShare));

    vec3 moonLit = vec3(0.64, 0.82, 1.38);
    vec3 moonShade = vec3(0.54, 0.72, 1.44);
    vec3 moon = mix(moonShade, moonLit, lit);
    tint = mix(tint, moon, nightFactor * mix(1.0, 0.42, inside) * 0.88 * (1.0 - lampShare));
    light *= tint;

    if (nightFactor > 0.05 && ambient.sunLot.w > 0.0 && centre.w > 0.25) {
        vec2 spill = windowSpillInfo(here, onGround);
        vec3 spillColor = mix(LAMP_COLOR, FIRE_COLOR, spill.y);
        light += occlusion * 0.70 * nightFactor * spill.x * spillColor;
    }

    if ((ambient.weather.x > 0.6 || ambient.skyExtra.z > 0.5) && ambient.skyExtra.y < 0.5) {
        float lSlot = floor(ambient.weather.z / 7.0);
        float lChance = ambient.skyExtra.z > 0.5 ? 0.55 : (ambient.weather.x - 0.6) * 1.6;
        float lStrikes = step(hash12(vec2(lSlot, 3.0)), lChance);
        float lDt = ambient.weather.z - lSlot * 7.0 - 1.0 - 4.0 * hash12(vec2(lSlot, 7.0));
        float lFlash = lDt < 0.0 ? 0.0 : exp(-lDt * 10.0) + (lDt < 0.18 ? 0.0 : 0.7 * exp(-(lDt - 0.18) * 9.0));
        lFlash = clamp(lFlash * lStrikes, 0.0, 1.0);
        light += occlusion * vec3(0.85, 0.95, 1.25) * (lFlash * 0.75 * outdoor);
    }

    float rawWet = ambient.skyExtra.x > 0.5 ? 0.0 : ambient.weather.y * outdoor;
    float wet = rawWet * architecturalExposure(here);
    float standing = 0.0;
    if (rawWet > 0.0) {
        bool onRoof = centre.w < 0.25 && ambient.sunLot.w > 0.0 && isRainRoofPixel(pixel, p, here, nSurf);
        if (onRoof) {
            float roofWet = rawWet * architecturalExposure(here + vec3(0.0, 0.0, 0.45));
            vec2 source = lotSource(here.xy);
            vec2 a = mat2(0.8, 0.6, -0.6, 0.8) * source;
            vec2 b = mat2(0.28, -0.96, 0.96, 0.28) * source;
            float roofField = 0.55 * smoothNoise(a / 1.9 + 5.3)
                            + 0.30 * smoothNoise(b / 0.85 + 19.7)
                            + 0.15 * smoothNoise(vec2(source.x * 2.6 + here.z * 0.4, source.y * 2.6 - here.z * 0.4));
            float spread = smoothstep(0.08, 0.82, roofWet);
            float roofPatch = smoothstep(mix(0.62, 0.08, spread), mix(0.80, 0.34, spread), roofField)
                            * smoothstep(0.05, 0.26, roofWet);
            float roofFull = smoothstep(0.45, 0.88, roofWet);
            float roofSoak = max(roofPatch, roofFull * (0.80 + 0.20 * smoothstep(0.20, 0.80, roofField)));
            vec3 roofTint = mix(vec3(0.62, 0.65, 0.70), vec3(0.50, 0.54, 0.60),
                                roofFull * 0.65 + smoothstep(0.45, 0.85, roofField) * 0.35);
            light *= mix(vec3(1.0), roofTint, roofSoak);
            standing = clamp(roofSoak * mix(0.35, 0.72, smoothstep(0.35, 0.80, roofField)), 0.0, 0.78);
            if (ambient.weather.x > 0.0 && roofSoak > 0.20) {
                vec2 rg = source * 4.2 + vec2(here.z * 0.7, -here.z * 0.5);
                vec2 rid = floor(rg);
                vec2 rdrop = rid + 0.25 + 0.5 * vec2(hash12(rid + 11.3), hash12(rid + 23.7));
                float rage = fract(ambient.weather.z * (1.1 + 0.65 * ambient.weather.x) + hash12(rid + 5.1));
                float ring = (1.0 - smoothstep(0.0, 0.08, abs(length(rg - rdrop) - rage * 0.32))) * (1.0 - rage);
                light *= 1.0 + 0.16 * ring * roofSoak * ambient.weather.x;
            } else {
                light *= 1.0 + 0.06 * roofSoak * (1.0 - smoothstep(0.2, 0.6, ambient.weather.w))
                       * (1.0 - clamp(ambient.clouds.x, 0.0, 1.0));
            }
        } else if (wet > 0.0) {
            // Vertical walls & props dampen modestly; ground darkens further via the spreading wet sheet below.
            light *= mix(vec3(1.0), vec3(0.82, 0.84, 0.87), wet * mix(0.45, 0.65, onGround));
            if (centre.w > 0.25 && onGround > 0.5) {
                vec2 source = lotSource(here.xy);
                // Multi-scale organic drainage field turned off the tile grid so wet areas follow broad natural basins
                // rather than small repetitive blobs.
                vec2 a = mat2(0.8, 0.6, -0.6, 0.8) * source;
                vec2 b = mat2(0.28, -0.96, 0.96, 0.28) * source;
                vec2 c = mat2(-0.6, 0.8, -0.8, -0.6) * source;
                float field = 0.52 * smoothNoise(a / 2.4)
                            + 0.33 * smoothNoise(b / 1.15 + 13.0)
                            + 0.15 * smoothNoise(c / 0.55 + 29.0);

                // Progressive ground coverage: starts as discrete soft-edged dark damp patches/puddles (wet 0.2..0.55),
                // spreads and merges across the yard (0.55..0.82), and covers the soaked ground cleanly at high saturation (0.82..1.0).
                float spread = smoothstep(0.12, 0.92, wet);
                float level = mix(0.68, 0.10, spread);
                float edge = mix(0.16, 0.24, spread);
                float patchWet = smoothstep(level, level + edge, field) * smoothstep(0.08, 0.30, wet);
                float fullSheet = smoothstep(0.68, 0.95, wet);
                float soaked = max(patchWet, fullSheet * (0.72 + 0.28 * smoothstep(0.25, 0.78, field)));

                // Deeper drainage depressions where a thin film of standing rainwater collects and ripples.
                float poolLevel = mix(0.72, 0.42, spread);
                float pool = smoothstep(poolLevel, poolLevel + 0.16, field) * smoothstep(0.22, 0.55, wet);

                // Wet ground looks genuinely darker and richer (water lowers diffuse albedo) — never lighter than dry ground.
                // Deep pools darken slightly more with a subtle cool damp tint.
                vec3 soakTint = mix(vec3(0.72, 0.74, 0.78), vec3(0.62, 0.66, 0.73), pool * 0.75);
                light *= mix(vec3(1.0), soakTint, soaked);

                // Water film intensity handed to atmosphere.frag for a discrete, dark-grounded sky sheen.
                // Covers gently across soaked ground at saturation, strongest in pools.
                standing = clamp(pool * 0.70 + soaked * fullSheet * 0.35, 0.0, 0.90);

                if (ambient.weather.x > 0.0 && (pool > 0.02 || soaked > 0.35)) {
                    vec2 g = source * 3.2;
                    vec2 id = floor(g);
                    vec2 drop = id + 0.25 + 0.5 * vec2(hash12(id), hash12(id + 7.1));
                    float age = fract(ambient.weather.z * (0.85 + 0.55 * ambient.weather.x) + hash12(id + 3.7));
                    float r1 = (1.0 - smoothstep(0.0, 0.065, abs(length(g - drop) - age * 0.44))) * (1.0 - age);
                    float age2 = fract(age + 0.5);
                    float r2 = (1.0 - smoothstep(0.0, 0.055, abs(length(g - drop) - age2 * 0.40))) * (1.0 - age2) * 0.50;
                    float rippleMask = clamp(pool * 0.85 + soaked * fullSheet * 0.40, 0.0, 1.0);
                    light *= 1.0 + 0.32 * (r1 + r2) * rippleMask * ambient.weather.x;
                } else {
                    // Subtle damp specular lift only when sunlight peeks out after rain.
                    light *= 1.0 + 0.04 * soaked * (1.0 - smoothstep(0.2, 0.6, ambient.weather.w)) * (1.0 - clamp(ambient.clouds.x, 0.0, 1.0));
                }
            }
        }
    }

    float mode = ambient.extent.z;
    if (mode > 14.5) {
        vec3 dbgGI = gatherRoomBounceGI(hereSurf, horizN, nLot.xy, isVertical, onFlatFloor, onDynamicSim, storiesCount);
        color = vec4(clamp(dbgGI * 1.8 + (mbOcc - vec3(occlusion)) * 1.4, 0.0, 1.0), 1.0);
        return;
    }
    if (mode > 13.5) {
        ivec2 oSize = textureSize(voxelMap, 0);
        vec2 lotSz = max(ambient.drift.zw, vec2(1.0));
        float gDepth = texture(groundMap, pixel / ambient.extent.xy).r;
        vec3 rayBase = gDepth < 0.9999 ? lotPoint(p.xy, (0.62 - gDepth) / 0.003, true, ambient.frame.xy) : here;
        float gridLine = (fract(rayBase.x) < 0.04 || fract(rayBase.y) < 0.04) ? 1.15 : 1.0;
        vec3 litGround = vec3(0.46, 0.50, 0.44) * gridLine;
        vec3 shadowGround = vec3(0.06, 0.08, 0.14) * gridLine;
        vec3 baseCol = mix(shadowGround, litGround, clamp(lit, 0.0, 1.0));
        if (oSize.x > 1 && ambient.shadowView.w > 0.5) {
            vec2 wSize = vec2(textureSize(worldDepthMap, 0));
            vec2 wp = ambient.shadowView.xy + p.xy * ambient.shadowView.z;
            float wFront = texelFetch(worldDepthMap, clamp(ivec2(floor(wp)), ivec2(0), ivec2(wSize) - 1), 0).r;
            if (wFront < 0.9999) {
                float frontKeyA = (0.62 - wFront) / 0.003;
                float baseKeyA = rayBase.x + rayBase.y + 0.8 * rayBase.z;
                float sFront = (frontKeyA - baseKeyA) / 2.64;
                float sEnd = max(-0.2, sFront - 2.4);
                const int STEPS_DBG = 48;
                vec3 hitCol = baseCol;
                bool hit = false;
                for (int i = 0; i <= STEPS_DBG; i++) {
                    float s = mix(sFront, sEnd, float(i) / float(STEPS_DBG));
                    vec3 q = rayBase + vec3(1.0, 1.0, 0.8) * s;
                    float oOcc = dualViewHullAt(q, oSize, lotSz, vec2(0.0), 0.0);
                    if (oOcc > 0.35) {
                        float relZ = max(0.0, q.z - rayBase.z);
                        float hNorm = clamp(relZ / 4.5, 0.0, 1.0);
                        vec3 ramp = mix(vec3(0.20, 0.78, 0.98), mix(vec3(0.35, 0.95, 0.40), vec3(1.0, 0.55, 0.18), clamp(hNorm * 2.0 - 1.0, 0.0, 1.0)), clamp(hNorm * 2.0, 0.0, 1.0));
                        hitCol = ramp * (0.65 + 0.35 * oOcc);
                        hit = true;
                        break;
                    }
                }
                color = vec4(hit ? hitCol : vec3(0.85, 0.20, 0.45), 1.0);
            } else {
                color = vec4(baseCol, 1.0);
            }
        } else {
            color = vec4(baseCol, 1.0);
        }
        return;
    }
    if (mode > 12.5) {
        // Lit windows: the spill on the ground in green over how surely a lamp lights the spot in blue.
        color = vec4(0.0, windowSpill(here, onGround), lampNear(here), 1.0);
        return;
    }
    if (mode > 11.5) { color = vec4(vec3(sky), 1.0); return; }
    if (mode > 10.5) {
        ivec2 dbgCell = ivec2(floor(here.xy + ambient.frame.w));
        int dbgRow = storyRowAt(dbgCell, here.z, here.z, 0.15);
        int cellMask = maskCatAt(dbgCell, 0, dbgRow);
        color = vec4(window, float(cellMask & 1) * 0.6, inside * 0.5, 1.0);
        return;
    }
    if (mode > 9.5) {
        color = vec4(litColumn, lit, litShell, 1.0);
        return;
    }
    if (mode > 8.5) {
        // The height map from above, under the pixel's lot point: the highest point over it in bands of one tile.
        vec2 gridSize = vec2(textureSize(heightMap, 0));
        float top = (0.5 - texture(heightMap, (here.xy + ambient.frame.w) * ambient.frame.z / gridSize).r) * HEIGHT_RANGE;
        color = vec4(clamp(top / 6.0, 0.0, 1.0), fract(top), top < -16.0 ? 1.0 : 0.0, 1.0);
        return;
    }
    if (mode > 7.5) {
        float depth = texelFetch(depthMap, ivec2(pixel), 0).r;
        float ground = texelFetch(groundMap, ivec2(pixel), 0).r;
        float key = depth < 1.0 ? (0.62 - depth) / 0.003 : (0.62 - ground) / 0.003 + ambient.view.w;
        vec3 lot = lotPoint(p.xy, key, depth >= 1.0, ambient.frame.xy);
        vec2 grid = step(0.9, fract(lot.xy));
        color = vec4(grid, step(0.5, fract(lot.z)), 1.0);
        color.rgb = mix(color.rgb, vec3(1.0, 0.8, 0.2), 0.6 * indoors(lot));
        return;
    }
    if (mode > 6.5) { color = vec4(vec3(contact), 1.0); return; }
    if (mode > 5.5) { color = vec4(clamp(lampLight + fireLight, 0.0, 1.0), 1.0); return; }
    if (mode > 4.5) {
        float ground = texelFetch(groundMap, ivec2(pixel), 0).r;
        float difference = centre.w < 0.25 && ground < 1.0 ? ((0.62 - texelFetch(depthMap, ivec2(pixel), 0).r) - (0.62 - ground)) / 0.003 : 0.0;
        color = vec4(clamp(0.5 + difference / 64.0, 0.0, 1.0), centre.w, ground < 1.0 ? 1.0 : 0.0, 1.0);
        return;
    }
    if (mode > 3.5) { color = vec4(fract(p.z / 32.0), fract(p.z / 256.0), centre.w, 1.0); return; }
    if (mode > 2.5) { color = vec4(normal * 0.5 + 0.5, 1.0); return; }
    if (mode > 1.5) { color = vec4(vec3(shadow), 1.0); return; }
    if (mode > 0.5) { color = vec4(vec3(occlusion * contact), 1.0); return; }
    vec3 outHalf = clamp(light * 0.5, 0.0, 1.0);
    color = vec4(outHalf, 1.0 - standing);
}
