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
layout(set = 2, binding = 9) uniform sampler2D prevAmbientMap;
layout(set = 2, binding = 10) uniform sampler2D voxelMap;
#include "ambientUniforms.glsl"
layout(location = 0) out vec4 color;
#include "lotSurface.glsl"
#include "architecture.glsl"

const float PI = 3.14159265;
const int SLICES = 3;
const int STEPS = 4;
const int SHADOW_STEPS = 64;
const float MAX_CASTER_HEIGHT = 10.5;
const int LAMP_STEPS = 16;
const int LAMP_MARCH_STEPS = 36;
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
    vec4 bFront = (0.9 - wFront) / 0.003 - key;
    vec4 vis = vFront * smoothstep(0.38 * shellDepth, 0.82 * shellDepth, bFront)
                      * (1.0 - smoothstep(1.85, 2.75, bFront));
    vec4 shlF = vFront * clamp((bFront + 0.55 * frontSoft) / frontSoft, 0.0, 1.0)
                       * clamp((shellDepth - bFront) / backSoft, 0.0, 1.0);
    vec4 shl = shlF;
    if (min(min(shlF.x, shlF.y), min(shlF.z, shlF.w)) < 0.99) {
        vec4 wBack = textureGather(worldBackDepthMap, uv);
        vec4 vBack = step(vec4(0.0001), wBack) * step(wBack, vec4(0.9999));
        vec4 bBack = (0.9 - wBack) / 0.003 - key;
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
        float behind = (0.9 - depth) / 0.003 - key;
        float backSoft = max(0.14, 0.48 * shellDepth);
        return vec2(clamp((behind + 0.06) / 0.18, 0.0, 1.0),
                    clamp((behind + 0.55 * frontSoft) / frontSoft, 0.0, 1.0) * clamp((shellDepth - behind) / backSoft, 0.0, 1.0));
    }
    float ground = texelFetch(groundMap, ivec2(pixel), 0).r;
    if (ground >= 1.0) return vec2(0.0);
    vec3 lot = lotPoint(scene, (0.9 - ground) / 0.003 + ambient.view.w, true, ambient.frame.xy);
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
    vec2 source = lotSource(lot.xy + sun.xy * (ambient.clouds.w - lot.z) / max(sun.z, 0.25));
    vec2 q = (source - ambient.drift.xy) / 9.0;
    float field = 0.5 * valueNoise(q) + 0.25 * valueNoise(q * 2.03 + 17.0) + 0.15 * valueNoise(q * 4.01 + 41.0) + 0.1 * valueNoise(q * 8.05 + 7.0);
    // Cover 0.3 shades about a third of the ground; the edges stay soft, as a cloud's shadow is.
    float threshold = mix(0.72, 0.18, cover);
    float density = smoothstep(threshold - 0.08, threshold + 0.1, field);
    return 1.0 - ambient.clouds.y * density;
}

int effectiveRoomAt(ivec2 cell, int row, vec2 localU) {
    int code = maskAt(cell, row);
    int room = code >> 1;
    if (room == 0) return 0;
    int part = maskAt(cell, row + 4) & 7;
    if (part == 0) return room;
    vec2 toward = part == 1 ? vec2(1.0, -1.0) : part == 2 ? vec2(-1.0, 1.0) : part == 3 ? vec2(-1.0) : vec2(1.0);
    return dot(localU - 0.5, toward) >= 0.0 ? room : 0;
}

// Always-up analytic walls (full STORY_HEIGHT, no ceiling) with window openings: marches a 2D DDA toward the sun and
// returns x = wall visibility (0 occluded, 1 clear), y = peak window-shaft weight (0..1) when light enters through glass.
vec2 wallRay(vec3 here, float onFlatFloor, vec2 horizN) {
    vec3 sun = ambient.sunLot.xyz;
    float across = length(sun.xy);
    if (across < 1e-3) return vec2(1.0, 0.0);
    vec2 direction = sun.xy / across;
    float rise = sun.z / across;
    vec2 start = here.xy + ambient.frame.w + horizN * (0.06 * (1.0 - onFlatFloor));
    float startZ = here.z;
    float topGuard = mix(0.0, 0.12, onFlatFloor);
    ivec2 cell = ivec2(floor(start));
    ivec2 stepDir = ivec2(sign(direction));
    vec2 safeDir = direction + vec2(equal(direction, vec2(0.0))) * 1e-5;
    vec2 delta = abs(1.0 / safeDir);
    vec2 next = (vec2(cell) + max(vec2(stepDir), 0.0) - start) / safeDir;
    float maxReachH = ambient.sunLot.w * across + 0.25;
    float maxDist = min(maxReachH, (2.0 * STORY_HEIGHT + 1.5) / max(rise, 0.12));
    float vis = 1.0;
    float winHit = 0.0;
    float tPrev = 0.0;
    int curM0 = maskAt(cell, 0);
    int curM1 = maskAt(cell, 1);
    for (int i = 0; i < 64; i++) {
        bool alongX = next.x < next.y;
        float t = alongX ? next.x : next.y;
        if (curM0 >= 2 || curM1 >= 2) {
            int part0 = maskAt(cell, 4) & 7;
            int part1 = maskAt(cell, 5) & 7;
            if (part0 != 0 || part1 != 0) {
                float cellBase0 = floorAt(cell, 0, here.z);
                float floor1 = floorAt(cell, 1, cellBase0 + STORY_HEIGHT);
                for (int pass = 0; pass < 2; pass++) {
                    int part = pass == 0 ? (part0 != 0 ? part0 : part1) : (part0 != 0 && part1 != 0 && part1 != part0 ? part1 : 0);
                    if (part == 0) continue;
                    bool diag0 = part == part0;
                    bool diag1 = part == part1;
                    float denom = part <= 2 ? (direction.x - direction.y) : (direction.x + direction.y);
                    if (abs(denom) > 1e-4) {
                        float tDiag = part <= 2
                            ? ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom
                            : (1.0 - (start.x - float(cell.x)) - (start.y - float(cell.y))) / denom;
                        if (tDiag > tPrev + 1e-4 && tDiag <= t + 1e-4 && tDiag <= maxDist) {
                            vec2 uDiag = start + direction * tDiag - vec2(cell);
                            if (all(greaterThanEqual(uDiag, vec2(-0.01))) && all(lessThanEqual(uDiag, vec2(1.01)))) {
                                float wallBot = diag0 ? cellBase0 : floor1;
                                float wallTop = diag1 ? floor1 + STORY_HEIGHT : cellBase0 + STORY_HEIGHT;
                                if (here.z < wallTop - topGuard) {
                                    float zDiag = startZ + tDiag * rise;
                                    float pen = min(0.045 * tDiag + 0.035, 0.50);
                                    float wallV = smoothstep(wallBot - 0.04, wallBot + 0.04, zDiag)
                                                * (1.0 - smoothstep(wallTop - 0.25 * pen, wallTop + 0.75 * pen, zDiag));
                                    float winOpen = 0.0;
                                    int winRow = zDiag >= floor1 ? 1 : 0;
                                    bool hasWinDiag = winRow == 0 ? diag0 : diag1;
                                    if (hasWinDiag && ((winRow == 0 ? curM0 : curM1) & 1) != 0) {
                                        float relH = zDiag - (winRow == 0 ? cellBase0 : floor1);
                                        float along = uDiag.x;
                                        float wPen = 0.04 * tDiag + 0.04;
                                        winOpen = smoothstep(WINDOW_SILL - wPen, WINDOW_SILL + wPen, relH)
                                                * (1.0 - smoothstep(WINDOW_TOP - wPen, WINDOW_TOP + wPen, relH))
                                                * smoothstep(0.14 - wPen, 0.14 + wPen, along)
                                                * smoothstep(0.14 - wPen, 0.14 + wPen, 1.0 - along);
                                    }
                                    float distFade = 1.0 - smoothstep(maxReachH * 0.86, maxReachH, tDiag);
                                    float occ = wallV * (1.0 - winOpen) * distFade;
                                    vis = min(vis, 1.0 - occ);
                                    winHit = max(winHit, winOpen * wallV * distFade);
                                    if (vis <= 0.01) break;
                                }
                            }
                        }
                    }
                }
                if (vis <= 0.01) break;
            }
        }
        if (t > maxDist) break;
        float zCross = startZ + t * rise;
        ivec2 to = cell + (alongX ? ivec2(stepDir.x, 0) : ivec2(0, stepDir.y));
        int nextM0 = maskAt(to, 0);
        int nextM1 = maskAt(to, 1);
        if (curM0 >= 2 || curM1 >= 2 || nextM0 >= 2 || nextM1 >= 2) {
            float base0 = floorAt(cell, 0, floorAt(to, 0, here.z));
            if (zCross > base0 + 2.0 * STORY_HEIGHT + 0.25) break;
            vec2 crossing = start + direction * t;
            vec2 edgeStep = alongX ? vec2(float(stepDir.x), 0.0) : vec2(0.0, float(stepDir.y));
            vec2 localA = crossing - vec2(cell) - edgeStep * 0.01;
            vec2 localB = crossing - vec2(to) + edgeStep * 0.01;
            int r0A = curM0 >= 2 ? effectiveRoomAt(cell, 0, localA) : 0;
            int r0B = nextM0 >= 2 ? effectiveRoomAt(to, 0, localB) : 0;
            int r1A = curM1 >= 2 ? effectiveRoomAt(cell, 1, localA) : 0;
            int r1B = nextM1 >= 2 ? effectiveRoomAt(to, 1, localB) : 0;
            bool hasWall0 = r0A != r0B && (r0A > 0 || r0B > 0);
            bool hasWall1 = r1A != r1B && (r1A > 0 || r1B > 0);
            if (hasWall0 || hasWall1) {
                float floor1 = floorAt(cell, 1, floorAt(to, 1, base0 + STORY_HEIGHT));
                float wallBot = hasWall0 ? base0 : floor1;
                float wallTop = hasWall1 ? floor1 + STORY_HEIGHT : base0 + STORY_HEIGHT;
                if (here.z < wallTop - topGuard) {
                    float pen = min(0.045 * t + 0.035, 0.50);
                    float wallV = smoothstep(wallBot - 0.04, wallBot + 0.04, zCross)
                                * (1.0 - smoothstep(wallTop - 0.25 * pen, wallTop + 0.75 * pen, zCross));
                    float winOpen = 0.0;
                    int winRow = zCross >= floor1 ? 1 : 0;
                    bool hasWinWall = winRow == 0 ? hasWall0 : hasWall1;
                    if (hasWinWall && ((winRow == 0 ? curM0 : curM1) & 1) != 0 && ((winRow == 0 ? nextM0 : nextM1) & 1) != 0) {
                        float relH = zCross - (winRow == 0 ? base0 : floor1);
                        float along = fract(alongX ? crossing.y : crossing.x);
                        float wPen = 0.04 * t + 0.04;
                        winOpen = smoothstep(WINDOW_SILL - wPen, WINDOW_SILL + wPen, relH)
                                * (1.0 - smoothstep(WINDOW_TOP - wPen, WINDOW_TOP + wPen, relH))
                                * smoothstep(0.10 - wPen, 0.10 + wPen, along)
                                * smoothstep(0.10 - wPen, 0.10 + wPen, 1.0 - along);
                    }
                    float distFade = 1.0 - smoothstep(maxReachH * 0.86, maxReachH, t);
                    float occ = wallV * (1.0 - winOpen) * distFade;
                    vis = min(vis, 1.0 - occ);
                    winHit = max(winHit, winOpen * wallV * distFade);
                    if (vis <= 0.01) break;
                }
            }
        }
        cell = to;
        curM0 = nextM0;
        curM1 = nextM1;
        tPrev = t;
        if (alongX) next.x += delta.x; else next.y += delta.y;
    }
    return vec2(vis, winHit * vis);
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

// Exact 4-view dual-orthogonal [backKey, frontKey] depth-interval visual hull test (temporally stable, 2x2 bilinear).
float dualViewHullAt(vec3 q, ivec2 oSize, vec2 lotSz, vec2 jitter, float spreadPx) {
    int halfH = oSize.x / 2 + 256;
    ivec2 sliceMax = ivec2(oSize.x - 1, halfH - 1);
    float pad = 0.18 + 0.02 * spreadPx;
    vec2 op0 = vec2((q.x - q.y + lotSz.x) * 16.0, (q.x + q.y) * 8.0 - q.z * 20.0 + 192.0);
    if (any(lessThan(op0, vec2(0.0))) || op0.x >= float(oSize.x) || op0.y >= float(halfH)) return 0.0;
    float key0 = q.x + q.y + 0.8 * q.z;
    float in0 = sampleHullSlice(op0, key0, 0, sliceMax, pad);
    if (in0 <= 0.01) return 0.0;

    vec3 qB = vec3(lotSz.y - q.y, q.x, q.z);
    vec2 op1 = vec2((qB.x - qB.y + lotSz.x) * 16.0, (qB.x + qB.y) * 8.0 - qB.z * 20.0 + 192.0);
    if (any(lessThan(op1, vec2(0.0))) || op1.x >= float(oSize.x) || op1.y >= float(halfH)) return 0.0;
    float key1 = qB.x + qB.y + 0.8 * qB.z;
    float in1 = sampleHullSlice(op1, key1, halfH, sliceMax, pad);
    return min(in0, in1);
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
    vec4 fKey = (0.9 - wFront) / 0.003;
    vec4 bKey = (0.9 - wBack) / 0.003;
    vec4 inSim = valid * smoothstep(-pad, 0.04, fKey - key) * smoothstep(-pad, 0.04, key - bKey);
    vec2 f = fract(wp - 0.5);
    return mix(mix(inSim.w, inSim.z, f.x), mix(inSim.x, inSim.y, f.x), f.y);
}

float sampleHullFast(vec2 op, float key, int yOffset, ivec2 sliceMax, float pad) {
    ivec2 c = clamp(ivec2(floor(op)), ivec2(0), sliceMax);
    ivec4 r = ivec4(texelFetch(voxelMap, ivec2(c.x, c.y + yOffset), 0) * 255.0 + 0.5);
    int f = r.r * 256 + r.g;
    if (f == 0) return 0.0;
    float frontKey = float(f) / 256.0 - 16.0;
    float backKey = float(r.b * 256 + r.a) / 256.0 - 16.0;
    return smoothstep(-pad, 0.04, frontKey - key) * smoothstep(-pad, 0.04, key - backKey);
}

float dualViewHullFast(vec3 q, ivec2 oSize, vec2 lotSz, float pad) {
    int halfH = oSize.x / 2 + 256;
    ivec2 sliceMax = ivec2(oSize.x - 1, halfH - 1);
    vec2 op0 = vec2((q.x - q.y + lotSz.x) * 16.0, (q.x + q.y) * 8.0 - q.z * 20.0 + 192.0);
    if (any(lessThan(op0, vec2(0.0))) || op0.x >= float(oSize.x) || op0.y >= float(halfH)) return 0.0;
    float in0 = sampleHullFast(op0, q.x + q.y + 0.8 * q.z, 0, sliceMax, pad);
    if (in0 <= 0.01) return 0.0;
    vec3 qB = vec3(lotSz.y - q.y, q.x, q.z);
    vec2 op1 = vec2((qB.x - qB.y + lotSz.x) * 16.0, (qB.x + qB.y) * 8.0 - qB.z * 20.0 + 192.0);
    if (any(lessThan(op1, vec2(0.0))) || op1.x >= float(oSize.x) || op1.y >= float(halfH)) return 0.0;
    float in1 = sampleHullFast(op1, qB.x + qB.y + 0.8 * qB.z, halfH, sliceMax, pad);
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
    float fKey = (0.9 - wFront) / 0.003;
    float bKey = (0.9 - wBack) / 0.003;
    return smoothstep(-pad, 0.04, fKey - key) * smoothstep(-pad, 0.04, key - bKey);
}

// How much of the sun reaches a lot point past the height map, from 0 to 1: march toward the sun across it
// (heightScatter.vert), which holds the highest point the camera sees over each spot of the lot; whatever rises above
// the ray blocks the sun, softening with distance, starting `start` tiles along it. Also returns the height map's and the
// sprite shells' own terms.
vec3 sunMarch(vec3 here, float start, float canopyClearZ) {
    float lit = 1.0, litColumn = 1.0, litShell = 1.0;
    vec2 gridSize = vec2(textureSize(heightMap, 0));
    ivec2 hMax = ivec2(gridSize) - 1;
    ivec2 vSize = textureSize(voxelMap, 0);
    bool hasVoxels = vSize.x > 1;
    vec2 sunProj = vec2(32.0 * (ambient.sunLot.x - ambient.sunLot.y),
                        16.0 * (ambient.sunLot.x + ambient.sunLot.y) - 40.0 * ambient.sunLot.z);
    float projLen = length(sunProj);
    vec2 sunDirPx = projLen > 1e-3 ? sunProj / projLen : vec2(1.0, 0.0);
    vec2 sunPerp = vec2(-sunDirPx.y, sunDirPx.x);
    float maxReach = ambient.sunLot.w + 0.2;
    float maxT = min(maxReach, MAX_CASTER_HEIGHT / max(ambient.sunLot.z, 0.14));
    if (maxT <= start + 0.02) return vec3(1.0);
    float wScale = max(ambient.shadowView.z, 0.5);
    float dtBase = clamp(1.45 / max(projLen, 18.0), 0.045, 0.060);
    float tNoise = noise(floor(gl_FragCoord.xy));
    float tRad = sqrt(noise(floor(gl_FragCoord.xy) + vec2(37.0, 17.0)));
    float tAng = tNoise * 6.2831853;
    vec2 diskJitter = vec2(cos(tAng), sin(tAng)) * (0.55 * tRad);
    float phase = tNoise;
    float signedKeyRate = ambient.sunLot.x + ambient.sunLot.y + 0.8 * ambient.sunLot.z;
    float keyRate = abs(signedKeyRate);
    float keyPerPx = signedKeyRate / max(projLen * wScale, 1.0);
    float sunHorizLen = length(ambient.sunLot.xy);
    vec2 perpTexel = sunHorizLen > 1e-4 ? vec2(-ambient.sunLot.y, ambient.sunLot.x) / sunHorizLen * 0.95 : vec2(0.95, 0.0);
    float solidRun = 0.0;
    vec3 qPrev = here;
    float t = start + dtBase * (1.0 - phase);
    for (int i = 0; i < SHADOW_STEPS; i++) {
        if (t > maxT) break;
        float dt = dtBase + 0.032 * (t - start);
        vec3 q = here + ambient.sunLot.xyz * t;
        if (q.z - here.z > MAX_CASTER_HEIGHT) break;
        vec2 texel = (q.xy + ambient.frame.w) * ambient.frame.z;
        if (any(lessThan(texel, vec2(1.0))) || any(greaterThan(texel, gridSize - 1.0))) break;
        float startFade = smoothstep(0.0, dtBase, t - start);
        float distFade = (1.0 - smoothstep(maxReach * 0.86, maxReach, t)) * startFade;
        float canopyOcc = canopyOcclusionAt(q.xy, canopyClearZ, qPrev.z, q.z, 0.065 * t + 0.04);
        lit = min(lit, 1.0 - canopyOcc * distFade);
        litColumn = min(litColumn, 1.0 - canopyOcc * distFade);
        if (lit <= 0.01 && litColumn <= 0.01) break;
        ivec2 qCell = ivec2(floor(q.xy + ambient.frame.w));
        float qBase0 = floorAt(qCell, 0, here.z);
        int qRow = q.z > qBase0 + STORY_HEIGHT - 0.05 ? 1 : 0;
        bool skipWindow = false;
        if ((maskAt(qCell, qRow) & 1) != 0) {
            float qFloorH = qRow == 0 ? qBase0 : floorAt(qCell, 1, qBase0 + STORY_HEIGHT);
            float qRelH = q.z - qFloorH;
            if (qRelH > WINDOW_SILL - 0.08 && qRelH < WINDOW_TOP + 0.08) {
                vec2 qFrac = fract(q.xy + ambient.frame.w);
                float edgeDist = min(min(qFrac.x, 1.0 - qFrac.x), min(qFrac.y, 1.0 - qFrac.y));
                skipWindow = edgeDist < 0.22;
            }
        }
        if (!skipWindow) {
            float spreadPx = clamp(0.18 + t * 0.65, 0.18, 2.80) * wScale;
            if (hasVoxels) {
                float hullOcc = dualViewHullAt(q, vSize, max(ambient.drift.zw, vec2(1.0)), diskJitter, spreadPx);
                float simOcc = dynamicSimOccAt(q, 0.16 + 0.02 * spreadPx) * smoothstep(0.10, 0.24, t);
                float occ = max(hullOcc, simOcc) * distFade;
                lit = min(lit, 1.0 - occ);
                litColumn = min(litColumn, 1.0 - occ);
                if (lit <= 0.01 && litColumn <= 0.01) break;
            } else {
                float penZ = 0.08 * t + 0.045;
                vec4 tops = (0.5 - textureGather(heightMap, texel / gridSize)) * HEIGHT_RANGE;
                vec4 blocked = clamp((tops - q.z - 0.06) / penZ, 0.0, 1.0);
                vec2 f = fract(texel - 0.5);
                float rawColumn = mix(mix(blocked.w, blocked.z, f.x), mix(blocked.x, blocked.y, f.x), f.y);
                float coreColumn = 0.0;
                if (rawColumn > 0.45) {
                    float topL = (0.5 - texelFetch(heightMap, clamp(ivec2(floor(texel + perpTexel)), ivec2(0), hMax), 0).r) * HEIGHT_RANGE;
                    float topR = (0.5 - texelFetch(heightMap, clamp(ivec2(floor(texel - perpTexel)), ivec2(0), hMax), 0).r) * HEIGHT_RANGE;
                    float sideBlocked = min(clamp((topL - q.z - 0.06) / penZ, 0.0, 1.0),
                                            clamp((topR - q.z - 0.06) / penZ, 0.0, 1.0));
                    float eroded = min(rawColumn, sideBlocked);
                    solidRun = eroded > 0.50 ? solidRun + dt : max(0.0, solidRun - 2.0 * dt);
                    coreColumn = smoothstep(0.45, 0.85, eroded) * smoothstep(0.06, 0.16, solidRun);
                } else {
                    solidRun = max(0.0, solidRun - 2.0 * dt);
                }
                float stepKey = keyRate * dt;
                float canopyLift = smoothstep(1.5, 3.2, q.z - here.z);
                float frontSoft = 0.14 + 0.055 * t;
                float shellDepth = max(0.22, stepKey * 1.80 + 0.16) + 0.16 * coreColumn + 0.22 * canopyLift;
                vec2 seen = hiddenAtSoft(q, spreadPx, sunPerp, sunDirPx, keyPerPx, shellDepth, frontSoft, diskJitter);
                float shell = seen.y * (1.0 / (1.0 + 0.025 * t));
                float colVis = seen.x;
                float occ = max(coreColumn * colVis, shell) * distFade;
                lit = min(lit, 1.0 - occ);
                litColumn = min(litColumn, 1.0 - coreColumn * distFade);
                litShell = min(litShell, 1.0 - shell * distFade);
                if (lit <= 0.01 && litColumn <= 0.01) break;
            }
        }
        qPrev = q;
        t += dt;
    }
    return vec3(lit, litColumn, litShell);
}

float lampWallVis(vec3 here, vec3 lampLot, float onFlatFloor, vec2 horizN) {
    vec2 start = here.xy + ambient.frame.w + horizN * (0.14 * (1.0 - onFlatFloor));
    vec2 end = lampLot.xy + ambient.frame.w;
    vec2 deltaXY = end - start;
    float distXY = length(deltaXY);
    if (distXY < 0.08) return 1.0;
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
    for (int i = 0; i < 16; i++) {
        bool alongX = next.x < next.y;
        float t = alongX ? next.x : next.y;
        float segEnd = min(t, maxT);
        if (segEnd > tPrev) {
            float zMid = here.z + 0.5 * (tPrev + segEnd) * rise;
            float cellBase0 = floorAt(cell, 0, here.z);
            int rowCell = zMid > cellBase0 + STORY_HEIGHT - 0.05 ? 1 : 0;
            int part = maskAt(cell, rowCell + 4) & 7;
            if (part != 0) {
                float denom = part <= 2 ? (direction.x - direction.y) : (direction.x + direction.y);
                if (abs(denom) > 1e-4) {
                    float tDiag = part <= 2
                        ? ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom
                        : (1.0 - (start.x - float(cell.x)) - (start.y - float(cell.y))) / denom;
                    if (tDiag > max(tPrev, 0.03) && tDiag <= segEnd + 1e-4) {
                        vec2 uDiag = start + direction * tDiag - vec2(cell);
                        if (all(greaterThanEqual(uDiag, vec2(-0.01))) && all(lessThanEqual(uDiag, vec2(1.01)))) {
                            float floorH = rowCell == 0 ? cellBase0 : floorAt(cell, 1, cellBase0 + STORY_HEIGHT);
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
            float zCross = here.z + t * rise;
            ivec2 to = cell + (alongX ? ivec2(stepDir.x, 0) : ivec2(0, stepDir.y));
            float base0 = floorAt(cell, 0, floorAt(to, 0, here.z));
            int row = zCross > base0 + STORY_HEIGHT - 0.05 ? 1 : 0;
            vec2 crossing = start + direction * t;
            vec2 edgeStep = alongX ? vec2(float(stepDir.x), 0.0) : vec2(0.0, float(stepDir.y));
            int roomA = effectiveRoomAt(cell, row, crossing - vec2(cell) - edgeStep * 0.01);
            int roomB = effectiveRoomAt(to, row, crossing - vec2(to) + edgeStep * 0.01);
            if (roomA != roomB && (roomA > 0 || roomB > 0)) {
                float floorH = row == 0 ? base0 : floorAt(cell, 1, floorAt(to, 1, base0 + STORY_HEIGHT));
                if (min(here.z, lampLot.z) < floorH + STORY_HEIGHT - topGuard) {
                    float relH = zCross - floorH;
                    float pen = 0.05 + 0.03 * t;
                    float wallV = smoothstep(-0.04, 0.04, relH) * (1.0 - smoothstep(STORY_HEIGHT - pen, STORY_HEIGHT + pen, relH));
                    vis = min(vis, 1.0 - wallV);
                    if (vis <= 0.01) return 0.0;
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

float lampMarch(vec3 here, vec3 lampLot, float onFlatFloor, float isVertical, float nUp, vec2 horizN, bool isFire) {
    vec3 origin = here + vec3(horizN * (0.16 * isVertical), 0.0);
    vec3 toReceiver = origin - lampLot;
    float dist3D = length(toReceiver);
    float horizTop = smoothstep(0.75, 0.92, nUp) * step(origin.z + 0.20, lampLot.z);
    float receiverClear = mix(mix(0.48, 0.14, max(isVertical, horizTop)), 0.08, onFlatFloor);
    float rStart = isFire ? 0.52 : 0.46;
    float rEnd = dist3D - receiverClear;
    if (rEnd <= rStart + 0.03) return 1.0;

    vec3 outDir = toReceiver / dist3D;
    vec2 gridSize = vec2(textureSize(heightMap, 0));
    ivec2 hMax = ivec2(gridSize) - 1;
    ivec2 vSize = textureSize(voxelMap, 0);
    bool hasVoxels = vSize.x > 1;
    vec2 lotSz = max(ambient.drift.zw, vec2(1.0));
    vec2 rayProj = vec2(32.0 * (outDir.x - outDir.y), 16.0 * (outDir.x + outDir.y) - 40.0 * outDir.z);
    float projLen = length(rayProj);
    vec2 rayDirPx = projLen > 1e-3 ? rayProj / projLen : vec2(1.0, 0.0);
    vec2 rayPerp = vec2(-rayDirPx.y, rayDirPx.x);
    float wScale = max(ambient.shadowView.z, 0.5);
    float drBase = clamp(2.40 / max(projLen * wScale, 22.0), 0.048, 0.082);
    float farAccel = max(0.0, (rEnd - rStart - float(LAMP_MARCH_STEPS) * drBase) / 136.0);
    float signedKeyRate = outDir.x + outDir.y + 0.8 * outDir.z;
    float keyRate = abs(signedKeyRate);
    float keyPerPx = signedKeyRate / max(projLen * wScale, 1.0);
    float horizLen = length(outDir.xy);
    vec2 perpTexel = horizLen > 1e-4 ? vec2(-outDir.y, outDir.x) / horizLen * 1.45 : vec2(1.45, 0.0);
    float lightRadiusScenePx = isFire ? 11.0 : 7.0;
    float tNoise = noise(floor(gl_FragCoord.xy) + lampLot.xy * 13.0);
    float tRad = sqrt(noise(floor(gl_FragCoord.xy) + lampLot.xy * 13.0 + vec2(37.0, 17.0)));
    float tAng = tNoise * 6.2831853;
    vec2 diskJitter = vec2(cos(tAng), sin(tAng)) * (0.60 * tRad);

    float r = rStart + tNoise * drBase * 0.5;
    float solidRun = 0.0;
    float lit = 1.0;
    for (int i = 0; i < LAMP_MARCH_STEPS; i++) {
        if (r >= rEnd) break;
        float dr = i < 20 ? drBase : drBase + farAccel * float(i - 19);
        vec3 q = lampLot + outDir * r;
        float xyFromLamp = length(q.xy - lampLot.xy);
        if (xyFromLamp >= (isFire ? 0.45 : 0.42)) {
            vec2 texel = (q.xy + ambient.frame.w) * ambient.frame.z;
            if (all(greaterThanEqual(texel, vec2(1.0))) && all(lessThanEqual(texel, gridSize - 1.0))) {
                float dToReceiver = max(rEnd - r, 0.0);
                float coneFrac = clamp(dToReceiver / max(dist3D, 0.35), 0.0, 1.0);
                float spreadPx = clamp(0.32 + lightRadiusScenePx * coneFrac, 0.32, 4.40) * wScale;
                float occ = 0.0;
                if (hasVoxels) {
                    occ = max(dualViewHullAt(q, vSize, lotSz, diskJitter, spreadPx), dynamicSimOccAt(q, 0.18));
                } else {
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
                        solidRun = eroded > 0.65 ? solidRun + dr : max(0.0, solidRun - 2.0 * dr);
                        coreColumn = smoothstep(0.58, 0.92, eroded) * smoothstep(0.14, 0.28, solidRun);
                    } else {
                        solidRun = max(0.0, solidRun - 2.0 * dr);
                    }
                    float stepKey = keyRate * dr;
                    float canopyLift = smoothstep(1.5, 3.0, max(0.0, q.z - origin.z));
                    float frontSoft = 0.14 + 0.055 * dToReceiver;
                    float shellDepth = max(0.18, stepKey * 1.60 + 0.12) + 0.16 * coreColumn + 0.20 * canopyLift;
                    vec2 seen = hiddenAtSoft(q, spreadPx, rayPerp, rayDirPx, keyPerPx, shellDepth, frontSoft, diskJitter);
                    float shell = seen.y * (0.94 / (1.0 + 0.04 * dToReceiver));
                    occ = max(coreColumn * seen.x, shell);
                }
                float sourceFade = smoothstep(0.0, 0.18, r - rStart);
                float receiverFade = smoothstep(0.0, dr * 1.35, rEnd - r);
                lit = min(lit, 1.0 - occ * sourceFade * receiverFade);
                if (lit <= 0.01) return 0.0;
            }
        }
        r += dr;
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
    float base0 = floorAt(cell, 0, here.z);
    int row = here.z > base0 + STORY_HEIGHT - 0.15 ? 1 : 0;
    int wallEdges = maskAt(cell, row + 6);
    int fenceEdges = maskAt(cell, row + 8);
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
        int part = maskAt(cell, row + 4) & 7;
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

vec3 resolveWallSurface(vec3 rawHere, vec2 sceneXY, float smoothKey, vec2 horizN) {
    int ownBit = abs(horizN.x) > 0.82 ? (horizN.x > 0.0 ? 1 : 2)
               : (abs(horizN.y) > 0.82 ? (horizN.y > 0.0 ? 4 : 8) : 0);
    if (ownBit == 0) return lotPoint(sceneXY, smoothKey, false, ambient.frame.xy);
    vec3 shifted = lotPoint(sceneXY, smoothKey + 0.14, false, ambient.frame.xy);
    vec2 probe = shifted.xy + ambient.frame.w + horizN * 0.12;
    ivec2 c = ivec2(floor(probe));
    vec2 u = fract(probe);
    float b0 = floorAt(c, 0, shifted.z);
    int row = shifted.z > b0 + STORY_HEIGHT - 0.15 ? 1 : 0;
    if ((maskAt(c, row + 6) & ownBit) != 0) return shifted;
    if (ownBit <= 2) {
        if (u.y > 0.74 && (maskAt(c + ivec2(0, 1), row + 6) & ownBit) != 0) {
            shifted.y = float(c.y + 1) + 0.035 - ambient.frame.w;
            return shifted;
        }
        if (u.y < 0.26 && (maskAt(c - ivec2(0, 1), row + 6) & ownBit) != 0) {
            shifted.y = float(c.y) - 0.035 - ambient.frame.w;
            return shifted;
        }
    } else {
        if (u.x > 0.74 && (maskAt(c + ivec2(1, 0), row + 6) & ownBit) != 0) {
            shifted.x = float(c.x + 1) + 0.035 - ambient.frame.w;
            return shifted;
        }
        if (u.x < 0.26 && (maskAt(c - ivec2(1, 0), row + 6) & ownBit) != 0) {
            shifted.x = float(c.x) - 0.035 - ambient.frame.w;
            return shifted;
        }
    }
    return lotPoint(sceneXY, smoothKey, false, ambient.frame.xy);
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
            float base0 = floorAt(cell, 0, here.z);
            int row = here.z > base0 + STORY_HEIGHT - 0.15 ? 1 : 0;
            int wallEdges = maskAt(cell, row + 6);
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
    int halfH = oSize.x / 2 + 256;
    int yBase = halfH * 2;
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
    int xOff = levelRow > 0 ? aoSize : 0;
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
    vec2 wSize = vec2(textureSize(worldDepthMap, 0));
    vec2 wpC = ambient.shadowView.xy + sceneC * ambient.shadowView.z;
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

float voxelGroundAO(vec3 here, int levelRow, ivec2 vSize, out float outContact) {
    vec3 baked = sampleBakedGroundAO(here.xy, levelRow, vSize);
    float simContact = simFootAO(here);
    outContact = max(clamp(baked.r * 0.78, 0.0, 1.0), simContact);
    return clamp(baked.g * 0.44 + baked.b * 0.34 + simContact * 0.16, 0.0, 1.0);
}

float voxelWallAO(vec3 here, vec2 horizN, ivec2 vSize, vec2 lotSz) {
    vec2 tang = vec2(-horizN.y, horizN.x);
    const vec3 OFF[6] = vec3[6](
        vec3(0.13, -0.10,  0.04),
        vec3(0.14,  0.10,  0.04),
        vec3(0.18,  0.00,  0.16),
        vec3(0.25, -0.16, -0.06),
        vec3(0.26,  0.16, -0.06),
        vec3(0.32,  0.00,  0.10)
    );
    const float W[6] = float[6](1.0, 1.0, 0.90, 0.65, 0.65, 0.55);
    float sum = 0.0;
    float wSum = 0.0;
    for (int i = 0; i < 6; i++) {
        vec3 o = OFF[i];
        vec3 q = here + vec3(horizN * o.x + tang * o.y, o.z);
        float occ = dualViewHullAt(q, vSize, lotSz, vec2(0.0), 1.35);
        sum += occ * W[i];
        wSum += W[i];
    }
    return clamp(sum / max(wSum, 1e-4) * 1.30, 0.0, 1.0);
}

void main() {
    float ambScale = ambient.extent.w > 0.5 ? ambient.extent.w : 1.0;
    vec2 pixel = (floor(gl_FragCoord.xy) + 0.5) * ambScale;
    if (pixel.x >= ambient.extent.x || pixel.y >= ambient.extent.y) { color = vec4(0.5, 0.5, 0.5, 1.0); return; }
    vec4 centre = positionAt(pixel);
    if (centre.w > 0.75) { color = vec4(0.5, 0.5, 0.5, 1.0); return; }
    vec3 p = centre.xyz;
    float scale = ambient.view.z;

    vec3 normal;
    vec3 nSurf;
    vec3 pSmooth = p;
    float gradJump;
    {
        bool isSprite = centre.w < 0.25;
        float step = isSprite
            ? clamp(2.6 * scale, max(2.6, ambScale * 1.35), max(5.5, 2.6 * scale))
            : clamp(1.75 * scale, max(1.75, ambScale), max(4.0, 1.75 * scale));
        float maxCont = max(3.5, 1.35 * step / max(scale, 0.25));
        vec3 left = positionAt(pixel - vec2(step, 0)).xyz, right = positionAt(pixel + vec2(step, 0)).xyz;
        vec3 up = positionAt(pixel - vec2(0, step)).xyz, down = positionAt(pixel + vec2(0, step)).xyz;
        bool lOk = abs(p.z - left.z) < maxCont;
        bool rOk = abs(right.z - p.z) < maxCont;
        bool uOk = abs(p.z - up.z) < maxCont;
        bool dOk = abs(down.z - p.z) < maxCont;
        float creaseTol = max(2.2, 0.55 * step / max(scale, 0.25));
        float dLx = p.z - left.z, dRx = right.z - p.z;
        float dUy = p.z - up.z, dDy = down.z - p.z;
        bool xSmooth = lOk && rOk && abs(dRx - dLx) < creaseTol && (dRx * dLx >= -0.05);
        bool ySmooth = uOk && dOk && abs(dDy - dUy) < creaseTol && (dDy * dUy >= -0.05);
        vec3 dx = xSmooth ? 0.5 * (right - left)
                : (lOk ? (p - left)
                : (rOk ? (right - p) : vec3(step / max(scale, 0.25), 0.0, 0.0)));
        vec3 dy = ySmooth ? 0.5 * (down - up)
                : (uOk ? (p - up)
                : (dOk ? (down - p) : vec3(0.0, step / max(scale, 0.25), 0.0)));
        if (isSprite) {
            float step2 = step * 2.0;
            float maxCont2 = max(6.0, 1.55 * step2 / max(scale, 0.25));
            vec3 l2 = positionAt(pixel - vec2(step2, 0)).xyz, r2 = positionAt(pixel + vec2(step2, 0)).xyz;
            vec3 u2 = positionAt(pixel - vec2(0, step2)).xyz, d2 = positionAt(pixel + vec2(0, step2)).xyz;
            bool l2Ok = lOk && abs(left.z - l2.z) < maxCont && abs(p.z - l2.z) < maxCont2 && abs((p.z - left.z) - (left.z - l2.z)) < creaseTol;
            bool r2Ok = rOk && abs(r2.z - right.z) < maxCont && abs(r2.z - p.z) < maxCont2 && abs((r2.z - right.z) - (right.z - p.z)) < creaseTol;
            bool u2Ok = uOk && abs(up.z - u2.z) < maxCont && abs(p.z - u2.z) < maxCont2 && abs((p.z - up.z) - (up.z - u2.z)) < creaseTol;
            bool d2Ok = dOk && abs(d2.z - down.z) < maxCont && abs(d2.z - p.z) < maxCont2 && abs((d2.z - down.z) - (down.z - p.z)) < creaseTol;
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
        gradJump = max(abs(dx.z), abs(dy.z)) / max(step / scale, 1.0);
        normal = centre.w > 0.25 ? n : normalize(mix(n, vec3(0, 0, 1), 0.25));
    }

    ivec2 vSize = textureSize(voxelMap, 0);
    bool hasVoxels = vSize.x > 1;
    vec2 lotSz = max(ambient.drift.zw, vec2(1.0));
    float sliceJitter = noise(floor(gl_FragCoord.xy));
    float radialBase = noise(floor(gl_FragCoord.xy) + vec2(19.0, 43.0));

    float radius = ambient.params.x;
    float thickness = ambient.params.w;
    float visibility = 1.0;
    vec3 bentNormal = normal;
    // Skip screen-space GTAO on flat terrain/floors when 3D world-space voxel/wall/fence AO is active,
    // eliminating foreground-sprite halos (e.g. through fence cutouts and behind tree canopies) and saving GPU cost.
    bool runScreenGTAO = ambient.params.y > 0.001 && !(hasVoxels && centre.w > 0.25 && ambient.sunLot.w > 0.0);
    if (runScreenGTAO) {
        visibility = 0.0;
        vec3 bentAccum = vec3(0.0);
        // Normal-offset bias (~1.6 SPR2 depth LSBs) prevents 8-bit staircase ledges from self-occluding flat sprite planes.
        vec3 pAO = centre.w < 0.25 ? pSmooth + normal * 0.95 : p;
        float aoDistLimit = centre.w > 0.25 ? radius * 1.85 : radius;
        for (int slice = 0; slice < SLICES; slice++) {
            float phi = (float(slice) + sliceJitter) * PI / float(SLICES);
            vec2 direction = vec2(cos(phi), sin(phi));
            vec3 axis = vec3(direction.y, -direction.x, 0.0);
            vec3 projected = normal - axis * dot(normal, axis);
            float projectedLength = max(length(projected), 1e-4);
            float cosN = clamp(projected.z / projectedLength, -1.0, 1.0);
            float n = sign(dot(projected.xy, direction)) * acos(cosN);
            float sliceRadialShift = fract(radialBase + float(slice) * 0.381966);
            float horizons[2];
            for (int side = 0; side < 2; side++) {
                vec2 sideDirection = side == 0 ? direction : -direction;
                float best = -1.0;
                for (int i = 0; i < STEPS; i++) {
                    float t = (float(i) + sliceRadialShift) / float(STEPS);
                    vec2 offset = sideDirection * radius * t * t * scale + sideDirection * 1.5;
                    vec2 samplePixel = pixel + offset;
                    if (any(lessThan(samplePixel, vec2(0))) || samplePixel.x >= ambient.extent.x || samplePixel.y >= ambient.extent.y) break;
                    vec4 samplePos = positionAt(samplePixel);
                    // Flat terrain/floors in front of a vertical sprite (fence, leg) have higher camera depth purely
                    // from isometric foreshortening and must not occlude elevated sprite pixels.
                    if (centre.w < 0.25 && samplePos.w > 0.25) continue;
                    vec3 delta = samplePos.xyz - pAO;
                    float distance = length(delta);
                    float distW = smoothstep(1.0, 0.0, distance / max(aoDistLimit, 1.0));
                    float falloff = distW * distW * clamp((thickness - delta.z) / (0.5 * thickness), 0.0, 1.0);
                    float cosine = mix(-1.0, delta.z / max(distance, 1e-4), falloff);
                    best = max(best, cosine);
                }
                horizons[side] = side == 0 ? acos(clamp(best, -1.0, 1.0)) : -acos(clamp(best, -1.0, 1.0));
            }
            float h1 = n + min(horizons[0] - n, PI / 2.0);
            float h0 = n + max(horizons[1] - n, -PI / 2.0);
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

    float key = centre.w < 0.25 ? (0.9 - texelFetch(depthMap, ivec2(pixel), 0).r) / 0.003
                                : (0.9 - texelFetch(groundMap, ivec2(pixel), 0).r) / 0.003 + ambient.view.w;
    vec3 here = lotPoint(p.xy, key, centre.w > 0.25, ambient.frame.xy);
    float riseHere = riseAt(pixel, p.z);
    float onGround = 1.0 - smoothstep(2.0, 6.0, riseHere);
    vec4 lift = textureSize(liftMap, 0).x > 1 ? texelFetch(liftMap, ivec2(pixel), 0) : vec4(0.0);
    bool onSnow = lift.z > 0.5;
    if (onSnow) {
        here += vec3(0.5 * lift.x, 0.5 * lift.x, lift.y);
        onGround = 1.0;
        occlusion = 1.0;
    }
    float roofSnow = lift.w;
    float highRoof = (!onSnow && centre.w < 0.25 && ambient.sunLot.w > 0.0 && riseHere > 105.0 && indoors(here) < 0.20)
        ? smoothstep(105.0, 122.0, riseHere) * smoothstep(0.32, 0.60, dot(normal, vec3(0.0, -0.8660254, 0.5)))
        : 0.0;
    float roofCalm = clamp(max(roofSnow, highRoof), 0.0, 1.0);
    if (roofCalm > 0.01) {
        occlusion = mix(occlusion, 1.0 - (1.0 - occlusion) * 0.14, roofCalm);
    }
    ivec2 hereCell = ivec2(floor(here.xy + ambient.frame.w));
    float floor2Z = floorAt(hereCell, 1, -100.0);
    float onLevel2Floor = floor2Z > -50.0
        ? (1.0 - smoothstep(0.08, 0.22, abs(here.z - floor2Z))) * smoothstep(0.35, 0.65, normal.z)
        : 0.0;
    float onFlatFloor = max(onGround, onLevel2Floor);
    if (hasVoxels && ambient.sunLot.w > 0.0 && onLevel2Floor > 0.01) {
        occlusion = mix(occlusion, 1.0, onLevel2Floor);
    }
    float wallFloor = 0.0;
    if (onFlatFloor > 0.5 && ambient.sunLot.w > 0.0 && (ambient.params.y > 0.001 || (onSnow && ambient.contact.y > 0.0))) {
        wallFloor = floorWallAO(here);
        if (!onSnow && ambient.params.y > 0.001) {
            occlusion *= 1.0 - 0.42 * clamp(ambient.params.y, 0.0, 1.0) * clamp(wallFloor, 0.0, 1.35);
        }
    }
    float contact = 1.0;
    if (ambient.sunLot.w > 0.0) {
        if ((centre.w > 0.25 || onSnow || onLevel2Floor > 0.5) && (ambient.contact.y > 0.0 || (!onSnow && hasVoxels && ambient.params.y > 0.001))) {
            if (hasVoxels) {
                int levelRow = onLevel2Floor > 0.5 ? 1 : 0;
                float voxelContact = 0.0;
                float voxelHemi = voxelGroundAO(here, levelRow, vSize, voxelContact);
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
                        const ivec2 QO[4] = ivec2[4](ivec2(0, 1), ivec2(1, 1), ivec2(1, 0), ivec2(0, 0));
                        float vals[4] = float[4](g.x, g.y, g.z, g.w);
                        for (int k = 0; k < 4; k++) {
                            float stored = vals[k];
                            if (stored >= 1.0) continue;
                            ivec2 texel = qb + QO[k];
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
                float feet = clamp(0.82 * best + 0.035 * sum, 0.0, 1.0);
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

    const vec3 WORLD_UP = vec3(0.0, -0.8660254, 0.5);
    const vec3 WORLD_TOWARD = vec3(0.0, 0.5, 0.8660254);
    float nUp = dot(nSurf, WORLD_UP);
    float nToward = dot(nSurf, WORLD_TOWARD);
    float nRight = nSurf.x;
    vec3 nLot = vec3((nToward + nRight) * 0.70710678, (nToward - nRight) * 0.70710678, nUp);
    vec2 horizN = length(nLot.xy) > 0.15 ? normalize(nLot.xy) : vec2(0.0);
    float isVertical = (1.0 - onFlatFloor)
        * (1.0 - smoothstep(0.22, 0.42, abs(nUp)))
        * (1.0 - roofCalm)
        * (1.0 - smoothstep(2.5, 4.5, gradJump));

    float onDynamicSim = 0.0;
    if (hasVoxels && ambient.shadowView.w > 0.5 && centre.w < 0.25) {
        vec2 wSize = vec2(textureSize(worldDepthMap, 0));
        vec2 wpSelf = ambient.shadowView.xy + p.xy * ambient.shadowView.z;
        if (all(greaterThanEqual(wpSelf, vec2(0.0))) && all(lessThan(wpSelf, wSize))) {
            float wSelf = texelFetch(worldDepthMap, clamp(ivec2(floor(wpSelf)), ivec2(0), ivec2(wSize) - 1), 0).r;
            if (wSelf < 0.9999 && abs((0.9 - wSelf) / 0.003 - key) < 0.45) {
                onDynamicSim = 1.0;
                occlusion = mix(occlusion, 1.0 - (1.0 - occlusion) * 0.35, onDynamicSim);
            }
        }
    }

    vec3 hereSurf = (centre.w < 0.25 && isVertical > 0.25 && onDynamicSim < 0.5 && ambient.sunLot.w > 0.0)
        ? resolveWallSurface(here, p.xy, pSmooth.z / DEPTH_UNIT, horizN)
        : here;
    float hereRelZ = hereSurf.z - terrainBaseAt(hereSurf.xy, hereSurf.z);
    if (isVertical > 0.01 && onDynamicSim < 0.5 && ambient.params.y > 0.001) {
        vec3 hereWall = (centre.w < 0.25 && ambient.sunLot.w <= 0.0) ? lotPoint(p.xy, pSmooth.z / DEPTH_UNIT, false, ambient.frame.xy) : hereSurf;
        float wallRelZ = hereWall.z - terrainBaseAt(hereWall.xy, hereWall.z);
        float aoStr = clamp(ambient.params.y, 0.0, 1.0) * isVertical;
        float storyRelZ = max(0.0, wallRelZ - floor(max(0.0, wallRelZ + 0.05) / STORY_HEIGHT) * STORY_HEIGHT);
        float baseT = clamp(storyRelZ / 0.45, 0.0, 1.0);
        float baseCrease = exp(-storyRelZ / 0.09) * (1.0 - smoothstep(0.24, 0.45, storyRelZ));
        float baseAO = 1.0 - 0.34 * aoStr * (0.55 * baseCrease + 0.45 * (1.0 - baseT) * (1.0 - baseT));
        float cornerOcc = ambient.sunLot.w > 0.0 ? wallCornerAO(hereWall, horizN) : 0.0;
        float cornerAO = 1.0 - 0.34 * aoStr * cornerOcc;
        float vWallOcc = (hasVoxels && ambient.sunLot.w > 0.0) ? voxelWallAO(hereWall, horizN, vSize, lotSz) * (1.0 - 0.72 * cornerOcc) : 0.0;
        float vWallAO = 1.0 - 0.42 * aoStr * vWallOcc;
        occlusion = mix(occlusion, 1.0, 0.72 * isVertical * cornerOcc);
        occlusion = max(occlusion * baseAO * cornerAO * vWallAO, 0.22);
    }
    if (centre.w < 0.25 && onFlatFloor < 0.5 && onDynamicSim < 0.5 && roofCalm < 0.5 && isVertical < 0.99 && hasVoxels && ambient.sunLot.w > 0.0 && ambient.params.y > 0.001) {
        float storySpriteZ = max(0.0, hereRelZ - floor(max(0.0, hereRelZ + 0.05) / STORY_HEIGHT) * STORY_HEIGHT);
        if (storySpriteZ < 0.28) {
            int spriteRow = hereRelZ > STORY_HEIGHT - 0.15 ? 1 : 0;
            vec3 selfGround = sampleBakedGroundAO(here.xy, spriteRow, vSize);
            float rootOcc = (1.0 - isVertical) * clamp(selfGround.r * 0.70 + selfGround.g * 0.40, 0.0, 1.0) * (1.0 - smoothstep(0.03, 0.24, storySpriteZ));
            occlusion *= 1.0 - 0.18 * clamp(ambient.params.y, 0.0, 1.0) * rootOcc;
        }
    }

    float lit = 1.0, litColumn = 1.0, litShell = 1.0;
    float inside = 0.0;
    if (ambient.sunLot.w > 0.0) {
        vec2 insideOffset = mix(horizN * 0.25, vec2(0.0), onFlatFloor);
        inside = indoors(hereSurf + vec3(insideOffset, 0.0));
    }
    float window = 0.0;
    if (ambient.sunLot.w > 0.0 && ambient.params.z > 0.001) {
        vec3 sunView = normalize(ambient.light.xyz + vec3(0.0, 0.0, 1e-4));
        float ndotl = dot(nSurf, sunView);
        float faceLit = smoothstep(-0.08, 0.22, ndotl);
        float selfShadow = mix(1.0, faceLit, max(isVertical, roofCalm));
        vec2 wall = wallRay(hereSurf, onFlatFloor, horizN);
        vec3 marchOrigin = hereSurf + vec3(horizN * (0.20 * isVertical), 0.0) + nLot * (0.18 * roofCalm);
        float marchStart = mix(mix(0.65, 0.18, roofCalm), 0.16, isVertical);
        marchStart = mix(marchStart, 0.06, onFlatFloor);
        float canopyClearZ = hereRelZ + mix(0.20, -0.05, isVertical);
        vec3 march = (wall.x > 0.01 && selfShadow > 0.01)
            ? sunMarch(marchOrigin, marchStart, canopyClearZ)
            : vec3(0.0);
        lit = min(min(wall.x, march.x), selfShadow);
        litColumn = min(min(wall.x, march.y), selfShadow);
        litShell = march.z;
        window = inside * max(onFlatFloor, isVertical * faceLit) * wall.y * march.x;
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
    vec3 spriteLampNormal = normalize(mix(nSurf, vec3(0.0, 0.0, 1.0), 0.36));
    vec3 lampNormal = centre.w > 0.25 ? nSurf : normalize(mix(spriteLampNormal, nSurf, onLevel2Floor));
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
        vec3 lampLot = vec3(0.0);
        float sameSide = 1.0;
        if (sides) {
            lampLot = lotPoint(lamp.xy, lamp.z, false, ambient.frame.xy);
            if (indoors(lampLot) > 0.25 && (roofCalm > 0.20 || (inside < 0.25 && hereSurf.z > lampLot.z + 1.0))) continue;
            sameSide = lampWallVis(hereSurf, lampLot, onFlatFloor, horizN);
            if (sameSide <= 0.01) continue;
        }
        vec3 direction = toLamp / max(distance, 1e-4);
        float normD = clamp(distance / max(lampReach, 1e-4), 0.0, 1.0);
        float win = clamp(1.0 - normD * normD, 0.0, 1.0);
        float falloff = 1.12 * (win * win) / (1.0 + 11.0 * normD * normD);
        float nearBulb = 1.0 - smoothstep(14.0, 34.0, distance);
        float facing = isFire
            ? clamp(dot(lampNormal, direction) * 0.65 + 0.35, 0.0, 1.0)
            : clamp(dot(lampNormal, direction) * 0.72 + 0.28, 0.0, 1.0);
        facing = mix(facing, 1.0, nearBulb);
        float contrib = strength * flicker * falloff * facing * sameSide;
        if (contrib < 0.0012) continue;
        falloff *= smoothstep(0.0012, 0.0035, contrib);
        maxNearBulb = max(maxNearBulb, nearBulb * clamp(strength * falloff * sameSide, 0.0, 1.0));
        float open = 1.0;
        if (sides) {
            open = lampMarch(hereSurf, lampLot, onFlatFloor, isVertical, nUp, horizN, isFire);
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

    // Directional key/fill shading + bent-normal sky/ground hemisphere GI bounce (Source 2 / XeGTAO style).
    float outdoor = 1.0 - inside;
    float sunWeight = mix(1.0, 0.70, inside);
    vec3 sunViewDir = normalize(ambient.light.xyz + vec3(0.0, 0.0, 1e-4));
    float keyWrap = dot(normal, sunViewDir);
    float bentSunOcc = mix(1.0, smoothstep(-0.40, 0.55, dot(bentNormal, sunViewDir)), 0.28 * (1.0 - onFlatFloor) * (1.0 - roofCalm) * (1.0 - isVertical) * (1.0 - onDynamicSim));
    float shadowActive = clamp(ambient.params.z * 1.8, 0.0, 1.0) * (1.0 - 0.80 * nightFactor);
    float dirShade = 1.0 + (keyWrap * 0.20 - 0.04) * mix(1.0, 0.55, inside) * lit * shadowActive * (1.0 - 0.45 * onFlatFloor) * (1.0 - onDynamicSim);
    dirShade *= mix(1.0, bentSunOcc, shadowActive * lit);
    float deBakeWeight = smoothstep(0.02, 0.10, ambient.params.z) * (1.0 - 0.85 * nightFactor);
    float wallDeBake = exp(-0.42 * clamp(nSurf.x, -0.70, 0.70) * isVertical * deBakeWeight);
    dirShade *= wallDeBake;
    float sunBloom = 1.0 + 0.12 * (1.0 - nightFactor) * lit * sunWeight * shadowActive;

    // Hemisphere indirect GI from the GTAO bent normal: upward crevices get cool sky fill,
    // downward/sideways undersides pick up subtle warm bounce from sunlit ground/floors.
    float bentUp = clamp(dot(bentNormal, WORLD_UP) * 0.5 + 0.5, 0.0, 1.0);
    vec3 skyFill = vec3(0.84, 0.93, 1.14);
    vec3 groundBounce = vec3(1.12, 1.03, 0.86);
    vec3 hemiGI = mix(groundBounce, skyFill, bentUp);
    hemiGI /= dot(hemiGI, LUMA);
    float giStrength = (1.0 - nightFactor) * (1.0 - lit * 0.55) * mix(0.32, 0.16, inside) * (1.0 - 0.65 * onFlatFloor) * (1.0 - 0.75 * isVertical);

    vec3 envBase = dirShade * sunBloom * ambient.lamp.w * mix(vec3(1.0), hemiGI, giStrength);
    vec3 skyTerm = (1.0 - shadowStr) * envBase;
    vec3 sunTerm = (shadowStr * lit) * envBase + 0.22 * ambient.contact.z * window * windowColor;
    float ambOcc = mix(occlusion * contact, 1.0, maxNearBulb);
    // Direct sunlight washes out diffuse sky AO; only tight physical micro-contact remains in direct sun.
    float sunMicroOcc = mix(mix(1.0, occlusion, 0.08) * mix(1.0, contact, 0.26), 1.0, maxNearBulb);
    float lampOcc = mix(mix(1.0, occlusion, 0.52) * mix(1.0, contact, 0.58), 1.0, maxNearBulb);
    vec3 light = ambOcc * skyTerm + sunMicroOcc * sunTerm + lampOcc * totalLamps;

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

    // Thunderstorm lightning illumination: synchronized double-flicker flash illuminating the entire outdoor lot.
    if ((ambient.weather.x > 0.6 || ambient.seasonExtra2.z > 0.5) && ambient.seasonExtra.z < 0.5) {
        float lSlot = floor(ambient.weather.z / 7.0);
        float lChance = ambient.seasonExtra2.z > 0.5 ? 0.55 : (ambient.weather.x - 0.6) * 1.6;
        float lStrikes = step(hash12(vec2(lSlot, 3.0)), lChance);
        float lDt = ambient.weather.z - lSlot * 7.0 - 1.0 - 4.0 * hash12(vec2(lSlot, 7.0));
        float lFlash = lDt < 0.0 ? 0.0 : exp(-lDt * 10.0) + (lDt < 0.18 ? 0.0 : 0.7 * exp(-(lDt - 0.18) * 9.0));
        lFlash = clamp(lFlash * lStrikes, 0.0, 1.0);
        light += occlusion * vec3(0.85, 0.95, 1.25) * (lFlash * 0.75 * outdoor);
    }

    // Rain: wet surfaces outside darken naturally as water soaks in. On the ground, damp patches first gather
    // softly in low depressions, then spread and coalesce into a continuous rain-soaked sheet at high saturation.
    // Exposed rooftops likewise darken richly with rainwater streaks and carry a discrete wet sheen + subtle
    // raindrop impact rings. Standing water stays darker and more discrete than dry surfaces, with a faint sky
    // sheen added in atmosphere.frag. Snow lies in its place in winter.
    float rawWet = ambient.season.x > 1.5 ? 0.0 : ambient.weather.y * outdoor;
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
    if (mode > 13.5) {
        ivec2 oSize = textureSize(voxelMap, 0);
        vec2 lotSz = max(ambient.drift.zw, vec2(1.0));
        float gDepth = texture(groundMap, pixel / ambient.extent.xy).r;
        vec3 rayBase = gDepth < 0.9999 ? lotPoint(p.xy, (0.9 - gDepth) / 0.003, true, ambient.frame.xy) : here;
        float gridLine = (fract(rayBase.x) < 0.04 || fract(rayBase.y) < 0.04) ? 1.15 : 1.0;
        vec3 litGround = vec3(0.46, 0.50, 0.44) * gridLine;
        vec3 shadowGround = vec3(0.06, 0.08, 0.14) * gridLine;
        vec3 baseCol = mix(shadowGround, litGround, clamp(lit, 0.0, 1.0));
        if (oSize.x > 1 && ambient.shadowView.w > 0.5) {
            vec2 wSize = vec2(textureSize(worldDepthMap, 0));
            vec2 wp = ambient.shadowView.xy + p.xy * ambient.shadowView.z;
            float wFront = texelFetch(worldDepthMap, clamp(ivec2(floor(wp)), ivec2(0), ivec2(wSize) - 1), 0).r;
            if (wFront < 0.9999) {
                float frontKeyA = (0.9 - wFront) / 0.003;
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
        // Sun through windows in yellow over the indoor mask in blue.
        int cellMask = maskAt(ivec2(floor(here.xy + ambient.frame.w)), 0);
        color = vec4(window, float(cellMask & 1) * 0.6, inside * 0.5, 1.0);
        return;
    }
    if (mode > 9.5) {
        // The sun shadow's terms: the height map alone in red, the shadow as drawn in green, the sprite shells in blue.
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
        // The lot point under the pixel: tile lines in red and green, altitude in bands of one tile in blue.
        float depth = texelFetch(depthMap, ivec2(pixel), 0).r;
        float ground = texelFetch(groundMap, ivec2(pixel), 0).r;
        float key = depth < 1.0 ? (0.9 - depth) / 0.003 : (0.9 - ground) / 0.003 + ambient.view.w;
        vec3 lot = lotPoint(p.xy, key, depth >= 1.0, ambient.frame.xy);
        vec2 grid = step(0.9, fract(lot.xy));
        color = vec4(grid, step(0.5, fract(lot.z)), 1.0);
        color.rgb = mix(color.rgb, vec3(1.0, 0.8, 0.2), 0.6 * indoors(lot));
        return;
    }
    if (mode > 6.5) { color = vec4(vec3(contact), 1.0); return; }
    if (mode > 5.5) { color = vec4(clamp(lampLight + fireLight, 0.0, 1.0), 1.0); return; }
    if (mode > 4.5) {
        // The lot's depth less the terrain's under it, in units of x + y, at 0.5 + difference / 64.
        float ground = texelFetch(groundMap, ivec2(pixel), 0).r;
        float difference = centre.w < 0.25 && ground < 1.0 ? ((0.9 - texelFetch(depthMap, ivec2(pixel), 0).r) - (0.9 - ground)) / 0.003 : 0.0;
        color = vec4(clamp(0.5 + difference / 64.0, 0.0, 1.0), centre.w, ground < 1.0 ? 1.0 : 0.0, 1.0);
        return;
    }
    if (mode > 3.5) { color = vec4(fract(p.z / 32.0), fract(p.z / 256.0), centre.w, 1.0); return; }
    if (mode > 2.5) { color = vec4(normal * 0.5 + 0.5, 1.0); return; }
    if (mode > 1.5) { color = vec4(vec3(shadow), 1.0); return; }
    if (mode > 0.5) { color = vec4(vec3(occlusion * contact), 1.0); return; }
    if (ambient.prevView.w > 0.5) {
        vec2 prevFullPixel = ambient.prevView.xy + ((pixel - ambient.view.xy) / ambient.view.z) * ambient.prevView.z;
        vec2 ambSize = vec2(textureSize(prevAmbientMap, 0));
        vec2 prevAmbUV = (prevFullPixel / ambScale) / ambSize;
        if (all(greaterThanEqual(prevAmbUV, vec2(0.0))) && all(lessThanEqual(prevAmbUV, vec2(1.0)))) {
            vec3 prevLight = texture(prevAmbientMap, prevAmbUV).rgb * 2.0;
            float diff = length(prevLight - light);
            float alpha = mix(0.65, 1.0, smoothstep(0.02, 0.08, diff));
            light = mix(prevLight, light, alpha);
        }
    }
    // The blur reads only the colour; the alpha tells atmosphere.frag where water stands, for the sky it reflects.
    color = vec4(clamp(light * 0.5, 0.0, 1.0), 1.0 - standing);
}
