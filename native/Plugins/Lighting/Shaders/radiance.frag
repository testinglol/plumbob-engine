#version 450
#extension GL_GOOGLE_include_directive : require
#include "lot.glsl"

layout(set = 2, binding = 0) uniform sampler2D depthMap;
layout(set = 2, binding = 1) uniform sampler2D groundMap;
layout(set = 2, binding = 2) uniform sampler2D heightMap;
layout(set = 2, binding = 3) uniform sampler2D indoorMap;
layout(set = 2, binding = 4) uniform sampler2D overheadMap;
layout(set = 2, binding = 5) uniform sampler2D voxelMap;
layout(set = 2, binding = 6) uniform sampler2D sceneColorMap;
#include "ambientUniforms.glsl"
layout(location = 0) out vec4 color;
#include "lotSurface.glsl"
#include "architecture.glsl"

const float WINDOW_SILL = 0.75;
const float WINDOW_TOP = 2.35;

int effectiveRoomAt(ivec2 cell, int row, vec2 localU) {
    int code = maskCatAt(cell, 0, row);
    int room = code >> 1;
    if (room == 0) return 0;
    int part = maskCatAt(cell, 2, row) & 7;
    if (part == 0) return room;
    vec2 toward = part == 1 ? vec2(1.0, -1.0) : part == 2 ? vec2(-1.0, 1.0) : part == 3 ? vec2(-1.0) : vec2(1.0);
    return dot(localU - 0.5, toward) >= 0.0 ? room : 0;
}

bool hasFloorSlabAt(ivec2 cell, int row, vec2 localU) {
    if (maskCatAt(cell, 1, row) == 0) return false;
    int part = maskCatAt(cell, 2, row) & 7;
    if (part == 0) return true;
    vec2 toward = part == 1 ? vec2(1.0, -1.0) : part == 2 ? vec2(-1.0, 1.0) : part == 3 ? vec2(-1.0) : vec2(1.0);
    return dot(localU - 0.5, toward) >= 0.0;
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

int voxelAoRows(ivec2 oSize) {
    int aoSize = max(1, oSize.x / 4);
    return max(1, (oSize.y - oSize.x - 256) / (512 + aoSize));
}

float sampleHullFast(vec2 op, float key, int yOffset, ivec2 sliceMax) {
    ivec2 c = clamp(ivec2(floor(op)), ivec2(0), sliceMax);
    ivec4 r = ivec4(texelFetch(voxelMap, ivec2(c.x, c.y + yOffset), 0) * 255.0 + 0.5);
    int f = r.r * 256 + r.g;
    if (f == 0) return 0.0;
    float fk = float(f) / 256.0 - 16.0;
    float bk = float(r.b * 256 + r.a) / 256.0 - 16.0;
    return smoothstep(-0.20, 0.04, fk - key) * smoothstep(-0.20, 0.04, key - bk);
}

float hullOccFast(vec3 q, ivec2 oSize, int halfH, float topMarginHalf, ivec2 sliceMax, vec2 lotSz) {
    vec2 op0 = vec2((q.x - q.y + lotSz.x) * 16.0, (q.x + q.y) * 8.0 - q.z * 20.0 + topMarginHalf);
    if (any(lessThan(op0, vec2(0.0))) || op0.x >= float(oSize.x) || op0.y >= float(halfH)) return 0.0;
    float in0 = sampleHullFast(op0, q.x + q.y + 0.8 * q.z, 0, sliceMax);
    if (in0 <= 0.01) return 0.0;
    vec3 qB = vec3(lotSz.y - q.y, q.x, q.z);
    vec2 op1 = vec2((qB.x - qB.y + lotSz.x) * 16.0, (qB.x + qB.y) * 8.0 - qB.z * 20.0 + topMarginHalf);
    if (any(lessThan(op1, vec2(0.0))) || op1.x >= float(oSize.x) || op1.y >= float(halfH)) return 0.0;
    return min(in0, sampleHullFast(op1, qB.x + qB.y + 0.8 * qB.z, halfH, sliceMax));
}

vec3 bounceWallRay(vec3 here) {
    vec3 sun = ambient.sunLot.xyz;
    float across = length(sun.xy);
    if (across < 1e-3) return vec3(1.0, 0.0, 0.0);
    ivec2 maskTexSize = textureSize(indoorMap, 0);
    int maskBandH = indoorBandH(maskTexSize);
    int stories = max(1, maskTexSize.y / max(1, 5 * maskBandH));
    vec2 direction = sun.xy / across;
    float rise = sun.z / across;
    vec2 start = here.xy + ambient.frame.w;
    ivec2 cell = ivec2(floor(start));
    ivec2 stepDir = ivec2(sign(direction));
    vec2 safeDir = direction + vec2(equal(direction, vec2(0.0))) * 1e-5;
    vec2 delta = abs(1.0 / safeDir);
    vec2 next = (vec2(cell) + max(vec2(stepDir), 0.0) - start) / safeDir;
    float maxReachH = min(ambient.sunLot.w * across + 0.25, 16.0);
    float vis = 1.0;
    float winHit = 0.0;
    float exitT = 0.0;
    for (int i = 0; i < 24; i++) {
        if ((cell.x < 0 && stepDir.x <= 0) || (cell.x >= maskTexSize.x && stepDir.x >= 0) ||
            (cell.y < 0 && stepDir.y <= 0) || (cell.y >= maskBandH && stepDir.y >= 0)) break;
        bool alongX = next.x < next.y;
        float t = alongX ? next.x : next.y;
        if (t > maxReachH) break;
        float zCross = here.z + t * rise;
        ivec2 to = cell + (alongX ? ivec2(stepDir.x, 0) : ivec2(0, stepDir.y));
        int cellCode0 = maskCatFast(cell, 1, 0, maskTexSize, maskBandH, stories);
        int toCode0 = maskCatFast(to, 1, 0, maskTexSize, maskBandH, stories);
        if ((cellCode0 | toCode0) != 0) {
            float base0 = cellCode0 != 0
                ? ambient.contact.w + float(cellCode0 - 1) / 8.0
                : ambient.contact.w + float(toCode0 - 1) / 8.0;
            int wRow = clamp(int(floor((zCross - base0 + 0.05) / STORY_HEIGHT)), 0, stories - 1);
            vec2 crossing = start + direction * t;
            vec2 edgeStep = alongX ? vec2(float(stepDir.x), 0.0) : vec2(0.0, float(stepDir.y));
            int rA = cellCode0 != 0 ? effectiveRoomAt(cell, wRow, crossing - vec2(cell) - edgeStep * 0.01) : 0;
            int rB = toCode0 != 0 ? effectiveRoomAt(to, wRow, crossing - vec2(to) + edgeStep * 0.01) : 0;
            if (rA != rB && (rA > 0 || rB > 0)) {
                float wallTop = floorAt(cell, wRow, floorAt(to, wRow, base0 + float(wRow) * STORY_HEIGHT)) + STORY_HEIGHT;
                if (here.z < wallTop - 0.12 && zCross < wallTop) {
                    float winOpen = 0.0;
                    int cM = maskCatFast(cell, 0, wRow, maskTexSize, maskBandH, stories);
                    int nM = maskCatFast(to, 0, wRow, maskTexSize, maskBandH, stories);
                    if ((cM & 1) != 0 && (nM & 1) != 0) {
                        float winFloor = floorAt(cell, wRow, floorAt(to, wRow, base0 + float(wRow) * STORY_HEIGHT));
                        float relH = zCross - winFloor;
                        float along = fract(alongX ? crossing.y : crossing.x);
                        winOpen = smoothstep(WINDOW_SILL - 0.12, WINDOW_SILL + 0.08, relH)
                                * (1.0 - smoothstep(WINDOW_TOP - 0.08, WINDOW_TOP + 0.12, relH))
                                * smoothstep(0.06, 0.18, along)
                                * smoothstep(0.06, 0.18, 1.0 - along);
                    }
                    vis = min(vis, winOpen);
                    winHit = max(winHit, winOpen);
                    if (rB == 0) exitT = max(exitT, t);
                    if (vis <= 0.02) break;
                }
            }
        }
        cell = to;
        if (alongX) next.x += delta.x; else next.y += delta.y;
    }
    return vec3(vis, winHit * vis, exitT / across);
}

float fastSunVis(vec3 here, float startT, ivec2 vSize, bool hasVoxels, int vHalfH, float vTopMarginHalf, ivec2 vSliceMax, vec2 sLotSz) {
    vec2 gridSize = vec2(textureSize(heightMap, 0));
    float maxT = min(ambient.sunLot.w, 12.0);
    if (maxT <= startT + 0.05) return 1.0;
    float lit = 1.0;
    vec3 qPrev = here + ambient.sunLot.xyz * startT;
    for (int i = 1; i <= 12; i++) {
        float t = mix(startT, maxT, float(i) / 12.0);
        vec3 q = here + ambient.sunLot.xyz * t;
        float canopy = canopyOcclusionAt(q.xy, here.z + 0.25, qPrev.z, q.z, 0.08 * t + 0.06);
        lit = min(lit, 1.0 - canopy);
        if (lit <= 0.02) return 0.0;
        if (hasVoxels) {
            float hOcc = hullOccFast(q, vSize, vHalfH, vTopMarginHalf, vSliceMax, sLotSz);
            lit = min(lit, 1.0 - hOcc);
        } else {
            vec2 texel = (q.xy + ambient.frame.w) * ambient.frame.z;
            if (all(greaterThanEqual(texel, vec2(1.0))) && all(lessThanEqual(texel, gridSize - 1.0))) {
                float top = (0.5 - texelFetch(heightMap, ivec2(floor(texel)), 0).r) * HEIGHT_RANGE;
                lit = min(lit, 1.0 - clamp((top - q.z - 0.12) / (0.12 * t + 0.15), 0.0, 1.0));
            }
        }
        if (lit <= 0.02) return 0.0;
        qPrev = q;
    }
    return lit;
}

float lampRoomVis(vec3 here, vec3 lampLot) {
    vec2 start = here.xy + ambient.frame.w;
    vec2 end = lampLot.xy + ambient.frame.w;
    vec2 deltaXY = end - start;
    float distXY = length(deltaXY);
    if (distXY < 0.12) return 1.0;
    ivec2 maskTexSize = textureSize(indoorMap, 0);
    int maskBandH = indoorBandH(maskTexSize);
    int stories = max(1, maskTexSize.y / max(1, 5 * maskBandH));
    vec2 direction = deltaXY / distXY;
    float rise = (lampLot.z - here.z) / distXY;
    ivec2 cell = ivec2(floor(start));
    ivec2 stepDir = ivec2(sign(direction));
    vec2 safeDir = direction + vec2(equal(direction, vec2(0.0))) * 1e-5;
    vec2 stepDelta = abs(1.0 / safeDir);
    vec2 next = (vec2(cell) + max(vec2(stepDir), 0.0) - start) / safeDir;
    float maxT = distXY - 0.06;
    for (int i = 0; i < 14; i++) {
        if ((cell.x < 0 && stepDir.x <= 0) || (cell.x >= maskTexSize.x && stepDir.x >= 0) ||
            (cell.y < 0 && stepDir.y <= 0) || (cell.y >= maskBandH && stepDir.y >= 0)) break;
        bool alongX = next.x < next.y;
        float t = alongX ? next.x : next.y;
        if (t > maxT) break;
        ivec2 to = cell + (alongX ? ivec2(stepDir.x, 0) : ivec2(0, stepDir.y));
        if (t > 0.04) {
            int c0 = maskCatFast(cell, 1, 0, maskTexSize, maskBandH, stories);
            int n0 = maskCatFast(to, 1, 0, maskTexSize, maskBandH, stories);
            if ((c0 | n0) != 0) {
                float base0 = c0 != 0 ? ambient.contact.w + float(c0 - 1) / 8.0 : ambient.contact.w + float(n0 - 1) / 8.0;
                float zCross = here.z + t * rise;
                int row = clamp(int(floor((zCross - base0 + 0.05) / STORY_HEIGHT)), 0, stories - 1);
                vec2 crossing = start + direction * t;
                vec2 edgeStep = alongX ? vec2(float(stepDir.x), 0.0) : vec2(0.0, float(stepDir.y));
                int rA = c0 != 0 ? effectiveRoomAt(cell, row, crossing - vec2(cell) - edgeStep * 0.01) : 0;
                int rB = n0 != 0 ? effectiveRoomAt(to, row, crossing - vec2(to) + edgeStep * 0.01) : 0;
                if (rA != rB && (rA > 0 || rB > 0)) return 0.0;
            }
        }
        cell = to;
        if (alongX) next.x += stepDelta.x; else next.y += stepDelta.y;
    }
    return 1.0;
}

bool trySampleVisibleAlbedo(vec3 q, bool allowGround, out vec3 outAlb) {
    outAlb = vec3(0.0);
    vec2 sc = sceneOf(q);
    vec2 px = floor(ambient.view.xy + sc * ambient.view.z) + 0.5;
    if (any(lessThan(px, vec2(0.0))) || px.x >= ambient.extent.x || px.y >= ambient.extent.y) return false;
    ivec2 ip = ivec2(px);
    float expKey = q.x + q.y + 0.8 * q.z;
    float d = texelFetch(depthMap, ip, 0).r;
    if (d < 1.0) {
        float obsKey = (0.62 - d) / 0.003;
        if (abs(obsKey - expKey) > 0.60) return false;
        vec4 s = texelFetch(sceneColorMap, ip, 0);
        if (s.a < 0.05) return false;
        outAlb = clamp(s.rgb, vec3(0.04), vec3(0.86));
        return true;
    }
    if (!allowGround) return false;
    float g = texelFetch(groundMap, ip, 0).r;
    if (g >= 1.0) return false;
    vec3 gl = lotPoint(sc, (0.62 - g) / 0.003 + ambient.view.w, true, ambient.frame.xy);
    if (abs((gl.x + gl.y + 0.8 * gl.z) - expKey) > 0.50) return false;
    vec4 s = texelFetch(sceneColorMap, ip, 0);
    if (s.a < 0.05) return false;
    outAlb = clamp(s.rgb, vec3(0.04), vec3(0.86));
    return true;
}

void main() {
    ivec2 frag = ivec2(gl_FragCoord.xy);
    int orient = int(ambient.clouds.z + 0.5);
    vec2 camLotSz = max((orient & 1) == 0 ? ambient.drift.zw : ambient.drift.wz, vec2(1.0));
    int sliceW = clamp(int(camLotSz.x * 4.0 + 0.5), 16, 512);
    int sliceH = clamp(int(camLotSz.y * 4.0 + 0.5), 16, 512);
    int stories = clamp(indoorStories(), 1, 16);
    int cols = min(stories, 4);
    int colIdx = frag.x / sliceW;
    int rowIdx = frag.y / sliceH;
    int levelRow = rowIdx * 4 + colIdx;
    if (colIdx >= cols || levelRow >= stories) { color = vec4(0.0); return; }

    int lx = frag.x - colIdx * sliceW;
    int ly = frag.y - rowIdx * sliceH;
    vec2 lotXY = (vec2(float(lx) + 0.5, float(ly) + 0.5) / vec2(float(sliceW), float(sliceH))) * camLotSz;
    vec2 cellAt = lotXY + ambient.frame.w;
    ivec2 cell = ivec2(floor(cellAt));
    vec2 localU = cellAt - vec2(cell);
    int wallEdges = maskCatAt(cell, 3, levelRow);
    if (levelRow > 0 && !hasFloorSlabAt(cell, levelRow, localU) && wallEdges == 0) {
        color = vec4(0.0);
        return;
    }

    float base0 = floorAt(cell, 0, terrainBaseClamped(lotXY, ambient.contact.w));
    float floorZ = levelRow == 0 ? base0 : floorAt(cell, levelRow, base0 + float(levelRow) * STORY_HEIGHT);
    vec3 here = vec3(lotXY, floorZ + 0.04);
    int roomHere = effectiveRoomAt(cell, levelRow, localU);
    bool inside = roomHere > 0;

    vec3 surfAlb = vec3(0.0);
    float albW = 0.0;
    vec3 candAlb;
    if (trySampleVisibleAlbedo(here, levelRow == 0, candAlb)) {
        surfAlb += candAlb * 1.4;
        albW += 1.4;
    }
    if (wallEdges != 0 && trySampleVisibleAlbedo(vec3(lotXY, floorZ + 0.90), false, candAlb)) {
        surfAlb += candAlb * 0.9;
        albW += 0.9;
    }
    if (albW < 0.5) {
        const vec2 DIL[4] = vec2[4](vec2(0.42, 0.0), vec2(-0.42, 0.0), vec2(0.0, 0.42), vec2(0.0, -0.42));
        for (int k = 0; k < 4; k++) {
            vec2 qXY = clamp(lotXY + DIL[k], vec2(0.05), camLotSz - vec2(0.05));
            vec2 qAt = qXY + ambient.frame.w;
            ivec2 qCell = ivec2(floor(qAt));
            if (effectiveRoomAt(qCell, levelRow, qAt - vec2(qCell)) != roomHere) continue;
            if (trySampleVisibleAlbedo(vec3(qXY, floorZ + 0.04), levelRow == 0, candAlb)) {
                surfAlb += candAlb;
                albW += 1.0;
            }
        }
    }
    vec3 fallbackAlb = inside
        ? vec3(0.46, 0.41, 0.36)
        : (ambient.skyExtra.x > 0.5 ? vec3(0.76, 0.80, 0.86) : vec3(0.32, 0.36, 0.28));
    surfAlb = albW > 0.01 ? (surfAlb / albW) : fallbackAlb;
    if (!inside) {
        float outLum = dot(surfAlb, LUMA);
        surfAlb = mix(surfAlb, vec3(outLum), 0.42);
    }

    float nightFactor = clamp(ambient.weather.w, 0.0, 1.0);
    float lowSun = 1.0 - smoothstep(0.12, 0.52, ambient.sunLot.z);
    float dayProgress = ambient.tone.w >= 0.0 ? clamp(ambient.tone.w, 0.0, 1.0) : (0.5 + 0.45 * lowSun);
    vec3 warmSun, coolShade, dayWindowColor;
    dayPalette(dayProgress, warmSun, coolShade, dayWindowColor);
    warmSun /= max(dot(warmSun, LUMA), 1e-4);
    dayWindowColor /= max(dot(dayWindowColor, LUMA), 1e-4);

    ivec2 vSize = textureSize(voxelMap, 0);
    bool hasVoxels = vSize.x > 1;
    int vAoRows = hasVoxels ? voxelAoRows(vSize) : 1;
    int vHalfH = vSize.x / 2 + 128 + 256 * vAoRows;
    float vTopMarginHalf = float(64 + 256 * vAoRows);
    ivec2 vSliceMax = ivec2(vSize.x - 1, vHalfH - 1);
    vec2 sLotSz = max(ambient.drift.zw, vec2(1.0));

    vec3 directIrr = vec3(0.0);
    if (ambient.params.z > 0.001 && nightFactor < 0.96) {
        vec3 wRay = bounceWallRay(here);
        if (wRay.x > 0.02 || wRay.y > 0.02) {
            float startT = inside ? max(0.75, wRay.z + 1.10) : 0.14;
            float sunVis = fastSunVis(here, startT, vSize, hasVoxels, vHalfH, vTopMarginHalf, vSliceMax, sLotSz) * cloudLight(here);
            float dayAmt = (1.0 - nightFactor) * ambient.lamp.w;
            if (inside) {
                float patchAmt = max(wRay.x * 0.60, wRay.y * 1.25) * sunVis;
                directIrr += mix(warmSun, dayWindowColor, 0.48) * (patchAmt * dayAmt * 1.15);
            } else {
                directIrr += warmSun * (wRay.x * sunVis * dayAmt * 0.42);
            }
        }
    }

    int lampCount = int(ambient.lamp.x);
    if (lampCount > 0 && ambient.lamp.z > 0.001) {
        float lampReachTiles = max(ambient.lamp.y / 32.0, 2.5);
        for (int i = 0; i < MAX_LAMPS; i++) {
            if (i >= lampCount) break;
            vec4 l = ambient.lamps[i];
            bool isFire = l.w < 0.0;
            float strength = abs(l.w);
            if (strength < 0.01) continue;
            vec3 lampLot = lotPoint(l.xy, l.z, false, ambient.frame.xy);
            if (abs(lampLot.z - floorZ) > STORY_HEIGHT * 0.92) continue;
            float distTiles = length(lampLot.xy - lotXY);
            float maxR = lampReachTiles * (isFire ? 1.15 : 1.0);
            if (distTiles >= maxR) continue;
            float atten = 1.0 - distTiles / maxR;
            atten *= atten;
            if (atten * strength < 0.02) continue;
            float vis = lampRoomVis(here, lampLot);
            if (vis <= 0.01) continue;
            float flicker = 1.0;
            if (isFire) {
                float phase = dot(l.xy, vec2(0.037, 0.053));
                float wave = 0.50 * sin(ambient.weather.z * 5.7 + phase)
                           + 0.32 * sin(ambient.weather.z * 11.3 + phase * 1.7 + 1.1)
                           + 0.18 * sin(ambient.weather.z * 19.1 + phase * 2.3 + 2.4);
                flicker = 0.84 + 0.30 * clamp(0.5 + 0.5 * wave, 0.0, 1.0);
            }
            vec3 lCol = isFire ? FIRE_COLOR * 1.45 : LAMP_COLOR;
            directIrr += lCol * (strength * flicker * atten * vis * ambient.lamp.z * 0.55);
        }
    }

    vec3 bounce = surfAlb * directIrr;
    float peak = max(bounce.r, max(bounce.g, bounce.b));
    if (peak > 0.85) {
        bounce *= (0.85 + (peak - 0.85) / (1.0 + (peak - 0.85) * 1.8)) / peak;
    }
    color = vec4(max(bounce, vec3(0.0)), 1.0);
}
