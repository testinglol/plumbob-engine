#version 450
#extension GL_GOOGLE_include_directive : require
#include "lot.glsl"

layout(set = 2, binding = 0) uniform sampler2D depthMap;
layout(set = 2, binding = 1) uniform sampler2D groundMap;
layout(set = 2, binding = 2) uniform sampler2D indoorMap;
layout(set = 2, binding = 3) uniform sampler2D liftMap;
layout(set = 2, binding = 4) uniform sampler2D overheadMap;
layout(set = 2, binding = 5) uniform sampler2D worldDepthMap;
layout(set = 2, binding = 6) uniform sampler2D worldBackDepthMap;
layout(set = 2, binding = 7) uniform sampler2D voxelMap;
layout(set = 2, binding = 8) uniform sampler2D simMaskMap;
#include "ambientUniforms.glsl"
layout(location = 0) out vec4 color;
#include "lotSurface.glsl"
#include "architecture.glsl"

const int SHADOW_STEPS = 140;
const float MAX_CASTER_HEIGHT = 10.5;
const float WINDOW_SILL = 0.75;
const float WINDOW_TOP = 2.35;
const float MARCH_K = 0.022;

float riseAt(vec2 pixel, float z) {
    float ground = groundAt(pixel);
    float below = groundAt(pixel + vec2(0.0, 4.0));
    if (ground < -1.0e4 || below < -1.0e4) return 0.0;
    float slope = (below - ground) * ambient.view.z / 4.0;
    return slope > 0.1 ? max(0.0, (z - ground) / (slope * 4.0 / 3.0)) : 0.0;
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

vec2 wallRay(vec3 here, float onFlatFloor, vec2 horizN) {
    vec3 sun = ambient.sunLot.xyz;
    float across = length(sun.xy);
    if (across < 1e-3) return vec2(1.0, 0.0);
    ivec2 maskTexSize = textureSize(indoorMap, 0);
    int maskBandH = indoorBandH(maskTexSize);
    int stories = max(1, maskTexSize.y / max(1, 5 * maskBandH));
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
    float maxDist = min(maxReachH, (float(stories) * STORY_HEIGHT + 1.5) / max(rise, 0.12));
    float vis = 1.0;
    float winHit = 0.0;
    float tPrev = 0.0;
    for (int i = 0; i < 64; i++) {
        if ((cell.x < 0 && stepDir.x <= 0) || (cell.x >= maskTexSize.x && stepDir.x >= 0) ||
            (cell.y < 0 && stepDir.y <= 0) || (cell.y >= maskBandH && stepDir.y >= 0)) break;
        bool alongX = next.x < next.y;
        float t = alongX ? next.x : next.y;
        float segEnd = min(t, maxDist);
        int cellCode0 = maskCatFast(cell, 1, 0, maskTexSize, maskBandH, stories);
        if (segEnd > tPrev && cellCode0 != 0) {
            float cellBase0 = ambient.contact.w + float(cellCode0 - 1) / 8.0;
            float zMid = startZ + 0.5 * (tPrev + segEnd) * rise;
            int midRow = clamp(int(floor((zMid - cellBase0 + 0.05) / STORY_HEIGHT)), 0, stories - 1);
            int lowR = max(0, midRow - 1);
            int highR = min(stories - 1, midRow + 1);
            int firstPart = 0;
            int secondPart = 0;
            for (int r = lowR; r <= highR; r++) {
                if (maskCatFast(cell, 0, r, maskTexSize, maskBandH, stories) < 2) continue;
                int p = maskCatFast(cell, 2, r, maskTexSize, maskBandH, stories) & 7;
                if (p == 0) continue;
                if (firstPart == 0) firstPart = p;
                else if (p != firstPart && secondPart == 0) secondPart = p;
            }
            for (int pass = 0; pass < 2; pass++) {
                int part = pass == 0 ? firstPart : secondPart;
                if (part == 0) continue;
                float denom = part <= 2 ? (direction.x - direction.y) : (direction.x + direction.y);
                if (abs(denom) <= 1e-4) continue;
                float tDiag = part <= 2
                    ? ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom
                    : (1.0 - (start.x - float(cell.x)) - (start.y - float(cell.y))) / denom;
                if (tDiag <= tPrev + 1e-4 || tDiag > t + 1e-4 || tDiag > maxDist) continue;
                vec2 uDiag = start + direction * tDiag - vec2(cell);
                if (any(lessThan(uDiag, vec2(-0.01))) || any(greaterThan(uDiag, vec2(1.01)))) continue;
                float zDiag = startZ + tDiag * rise;
                int dRow = clamp(int(floor((zDiag - cellBase0 + 0.05) / STORY_HEIGHT)), 0, stories - 1);
                int hitRow = -1;
                if (maskCatFast(cell, 0, dRow, maskTexSize, maskBandH, stories) >= 2 && (maskCatFast(cell, 2, dRow, maskTexSize, maskBandH, stories) & 7) == part) hitRow = dRow;
                else if (dRow > 0 && maskCatFast(cell, 0, dRow - 1, maskTexSize, maskBandH, stories) >= 2 && (maskCatFast(cell, 2, dRow - 1, maskTexSize, maskBandH, stories) & 7) == part) hitRow = dRow - 1;
                else if (dRow + 1 < stories && maskCatFast(cell, 0, dRow + 1, maskTexSize, maskBandH, stories) >= 2 && (maskCatFast(cell, 2, dRow + 1, maskTexSize, maskBandH, stories) & 7) == part) hitRow = dRow + 1;
                if (hitRow < 0) continue;
                int botRow = hitRow;
                while (botRow > 0 && maskCatFast(cell, 0, botRow - 1, maskTexSize, maskBandH, stories) >= 2 && (maskCatFast(cell, 2, botRow - 1, maskTexSize, maskBandH, stories) & 7) == part) botRow--;
                int topRow = hitRow;
                while (topRow + 1 < stories && maskCatFast(cell, 0, topRow + 1, maskTexSize, maskBandH, stories) >= 2 && (maskCatFast(cell, 2, topRow + 1, maskTexSize, maskBandH, stories) & 7) == part) topRow++;
                float wallBot = floorAt(cell, botRow, cellBase0 + float(botRow) * STORY_HEIGHT);
                float wallTop = floorAt(cell, topRow, cellBase0 + float(topRow) * STORY_HEIGHT) + STORY_HEIGHT;
                float topClearD = 1.0 - smoothstep(wallTop - max(topGuard, 0.16), wallTop - 0.03, here.z);
                if (topClearD > 0.001) {
                    float pen = min(0.045 * tDiag + 0.035, 0.50);
                    float wallV = topClearD * smoothstep(wallBot - 0.04, wallBot + 0.04, zDiag)
                                * (1.0 - smoothstep(wallTop - 0.25 * pen, wallTop + 0.75 * pen, zDiag));
                    float winOpen = 0.0;
                    int winRow = clamp(int(floor((zDiag - cellBase0 + 0.01) / STORY_HEIGHT)), botRow, topRow);
                    int winMask = maskCatFast(cell, 0, winRow, maskTexSize, maskBandH, stories);
                    if (winMask >= 2 && (maskCatFast(cell, 2, winRow, maskTexSize, maskBandH, stories) & 7) == part && (winMask & 1) != 0) {
                        float winFloor = floorAt(cell, winRow, cellBase0 + float(winRow) * STORY_HEIGHT);
                        float relH = zDiag - winFloor;
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
            if (vis <= 0.01) break;
        }
        if (t > maxDist) break;
        float zCross = startZ + t * rise;
        ivec2 to = cell + (alongX ? ivec2(stepDir.x, 0) : ivec2(0, stepDir.y));
        int toCode0 = maskCatFast(to, 1, 0, maskTexSize, maskBandH, stories);
        if ((cellCode0 | toCode0) != 0) {
            float base0 = cellCode0 != 0
                ? ambient.contact.w + float(cellCode0 - 1) / 8.0
                : ambient.contact.w + float(toCode0 - 1) / 8.0;
            if (zCross > base0 + float(stories) * STORY_HEIGHT + 0.25) break;
            int wRow = clamp(int(floor((zCross - base0 + 0.05) / STORY_HEIGHT)), 0, stories - 1);
            vec2 crossing = start + direction * t;
            vec2 edgeStep = alongX ? vec2(float(stepDir.x), 0.0) : vec2(0.0, float(stepDir.y));
            vec2 localA = crossing - vec2(cell) - edgeStep * 0.01;
            vec2 localB = crossing - vec2(to) + edgeStep * 0.01;
            int hitRow = -1;
            for (int off = 0; off <= 2; off++) {
                int r = off == 0 ? wRow : (off == 1 ? wRow - 1 : wRow + 1);
                if (r < 0 || r >= stories) continue;
                int rA = cellCode0 != 0 ? effectiveRoomAt(cell, r, localA) : 0;
                int rB = toCode0 != 0 ? effectiveRoomAt(to, r, localB) : 0;
                if (rA != rB && (rA > 0 || rB > 0)) { hitRow = r; break; }
            }
            if (hitRow >= 0) {
                int botRow = hitRow;
                while (botRow > 0) {
                    int rA = cellCode0 != 0 ? effectiveRoomAt(cell, botRow - 1, localA) : 0;
                    int rB = toCode0 != 0 ? effectiveRoomAt(to, botRow - 1, localB) : 0;
                    if (rA == rB || (rA == 0 && rB == 0)) break;
                    botRow--;
                }
                int topRow = hitRow;
                while (topRow + 1 < stories) {
                    int rA = cellCode0 != 0 ? effectiveRoomAt(cell, topRow + 1, localA) : 0;
                    int rB = toCode0 != 0 ? effectiveRoomAt(to, topRow + 1, localB) : 0;
                    if (rA == rB || (rA == 0 && rB == 0)) break;
                    topRow++;
                }
                float wallBot = floorAt(cell, botRow, floorAt(to, botRow, base0 + float(botRow) * STORY_HEIGHT));
                float wallTop = floorAt(cell, topRow, floorAt(to, topRow, base0 + float(topRow) * STORY_HEIGHT)) + STORY_HEIGHT;
                float topClearO = 1.0 - smoothstep(wallTop - max(topGuard, 0.16), wallTop - 0.03, here.z);
                if (topClearO > 0.001) {
                    float pen = min(0.045 * t + 0.035, 0.50);
                    float wallV = topClearO * smoothstep(wallBot - 0.04, wallBot + 0.04, zCross)
                                * (1.0 - smoothstep(wallTop - 0.25 * pen, wallTop + 0.75 * pen, zCross));
                    float winOpen = 0.0;
                    int winRow = clamp(int(floor((zCross - base0 + 0.01) / STORY_HEIGHT)), botRow, topRow);
                    int cM = maskCatFast(cell, 0, winRow, maskTexSize, maskBandH, stories);
                    int nM = maskCatFast(to, 0, winRow, maskTexSize, maskBandH, stories);
                    int wRA = cellCode0 != 0 ? effectiveRoomAt(cell, winRow, localA) : 0;
                    int wRB = toCode0 != 0 ? effectiveRoomAt(to, winRow, localB) : 0;
                    if (wRA != wRB && (wRA > 0 || wRB > 0) && (cM & 1) != 0 && (nM & 1) != 0) {
                        float winFloor = floorAt(cell, winRow, floorAt(to, winRow, base0 + float(winRow) * STORY_HEIGHT));
                        float relH = zCross - winFloor;
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
        tPrev = t;
        if (alongX) next.x += delta.x; else next.y += delta.y;
    }
    return vec2(vis, winHit * vis);
}

int voxelAoRows(ivec2 oSize) {
    int aoSize = max(1, oSize.x / 4);
    return max(1, (oSize.y - oSize.x - 256) / (512 + aoSize));
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

void clipAxisSlab(float orig, float dir, float lo, float hi, inout float tEnter, inout float tExit) {
    if (abs(dir) < 1e-6) {
        if (orig < lo || orig > hi) {
            tEnter = 1e6;
            tExit = -1e6;
        }
        return;
    }
    float invD = 1.0 / dir;
    float a = (lo - orig) * invD;
    float b = (hi - orig) * invD;
    tEnter = max(tEnter, min(a, b));
    tExit = min(tExit, max(a, b));
}

float rayRelT(float s, float dtBase, float sCap, float relTCap) {
    return s <= sCap
        ? (dtBase / MARCH_K) * (exp(MARCH_K * s) - 1.0)
        : relTCap + 0.36 * (s - sCap);
}

float rayStepOf(float relT, float dtBase, float sCap, float relTCap) {
    if (relT <= 0.0) return 0.0;
    return relT <= relTCap
        ? log(1.0 + MARCH_K * relT / dtBase) / MARCH_K
        : sCap + (relT - relTCap) / 0.36;
}

vec3 sunMarchFast(vec3 here, float start, float canopyClearZ, float selfSimGuard, ivec2 vSize, int stories) {
    bool hasVoxels = vSize.x > 1;
    vec2 invVSize = 1.0 / vec2(max(vSize, ivec2(1)));
    vec2 wSize = vec2(textureSize(worldDepthMap, 0));
    bool hasOverhead = textureSize(overheadMap, 0).x > 1;
    int vAoRows = hasVoxels ? voxelAoRows(vSize) : 1;
    int vHalfH = vSize.x / 2 + 128 + 256 * vAoRows;
    int vAoSize = vSize.x / 4;
    int vAoYBase = vHalfH * 2;
    bool hasColBounds = hasVoxels && vAoSize > 0 && vSize.y >= vAoYBase + vAoSize;
    float vTopMarginHalf = float(64 + 256 * vAoRows);
    ivec2 vSliceMax = ivec2(vSize.x - 1, vHalfH - 1);
    vec2 sLotSz = max(ambient.drift.zw, vec2(1.0));
    int orient = int(ambient.clouds.z + 0.5);
    vec2 camLotSz = max((orient & 1) == 0 ? ambient.drift.zw : ambient.drift.wz, vec2(1.0));
    ivec2 mSize = textureSize(indoorMap, 0);
    int mBandH = indoorBandH(mSize);

    vec3 sunDir = ambient.sunLot.xyz;
    vec2 sunProj = vec2(32.0 * (sunDir.x - sunDir.y),
                        16.0 * (sunDir.x + sunDir.y) - 40.0 * sunDir.z);
    float projLen = length(sunProj);
    vec2 sunDirPx = projLen > 1e-3 ? sunProj / projLen : vec2(1.0, 0.0);
    vec2 sunPerp = vec2(-sunDirPx.y, sunDirPx.x);
    float maxCasterH = max(MAX_CASTER_HEIGHT, float(stories) * STORY_HEIGHT + 4.6);
    float maxVoxelH = float(stories) * STORY_HEIGHT + 3.8;
    float maxSimH = float(stories) * STORY_HEIGHT + 2.4;
    float minCanopyZ = ambient.contact.w + STORY_HEIGHT - 0.45;
    float maxReach = ambient.sunLot.w + 0.2;
    float maxT = min(maxReach, maxCasterH / max(sunDir.z, 0.14));

    float marginLo = -ambient.frame.w + 1.0 / max(ambient.frame.z, 1.0);
    vec2 marginHi = camLotSz + ambient.frame.w - 1.0 / max(ambient.frame.z, 1.0);
    float gridEnter = start;
    float gridExit = maxT;
    clipAxisSlab(here.x, sunDir.x, marginLo, marginHi.x, gridEnter, gridExit);
    clipAxisSlab(here.y, sunDir.y, marginLo, marginHi.y, gridEnter, gridExit);
    if (gridEnter >= gridExit - 0.01) return vec3(1.0);

    vec2 tVox = vec2(1e6, -1e6);
    if (hasVoxels && ambient.voxShadowBounds.x <= ambient.voxShadowBounds.z && ambient.casterZBounds.x <= ambient.casterZBounds.y) {
        float ve = gridEnter;
        float vx = min(gridExit, (maxVoxelH + 0.25) / max(sunDir.z, 1e-4));
        clipAxisSlab(here.x, sunDir.x, ambient.voxShadowBounds.x, ambient.voxShadowBounds.z, ve, vx);
        clipAxisSlab(here.y, sunDir.y, ambient.voxShadowBounds.y, ambient.voxShadowBounds.w, ve, vx);
        clipAxisSlab(here.z, sunDir.z, ambient.casterZBounds.x, ambient.casterZBounds.y, ve, vx);
        if (ve <= vx) tVox = vec2(ve, vx);
    }

    vec2 tRoof = vec2(1e6, -1e6);
    if (hasOverhead && ambient.roofShadowBounds.x <= ambient.roofShadowBounds.z && ambient.casterZBounds.z <= ambient.casterZBounds.w) {
        float re = gridEnter;
        float rx = gridExit;
        clipAxisSlab(here.x, sunDir.x, ambient.roofShadowBounds.x, ambient.roofShadowBounds.z, re, rx);
        clipAxisSlab(here.y, sunDir.y, ambient.roofShadowBounds.y, ambient.roofShadowBounds.w, re, rx);
        clipAxisSlab(here.z, sunDir.z, max(minCanopyZ, ambient.casterZBounds.z), ambient.casterZBounds.w, re, rx);
        if (re <= rx) tRoof = vec2(re, rx);
    }

    float wScale = max(ambient.shadowView.z, 0.5);
    bool hasAnyDynSims = ambient.shadowView.w > 0.5 && ambient.dynShadowBounds.x <= ambient.dynShadowBounds.z;
    vec2 tSim = vec2(1e6, -1e6);
    if (hasAnyDynSims) {
        float se = max(gridEnter, selfSimGuard - 0.18);
        float sx = min(gridExit, (maxSimH + 0.25) / max(sunDir.z, 1e-4));
        vec2 wpOrig = ambient.shadowView.xy + sceneOf(here) * ambient.shadowView.z;
        vec2 wpDir = sunProj * ambient.shadowView.z;
        float simPad = 1.6 * wScale + 0.25 * length(wpDir) + 4.0;
        clipAxisSlab(wpOrig.x, wpDir.x, ambient.dynShadowBounds.x - simPad, ambient.dynShadowBounds.z + simPad, se, sx);
        clipAxisSlab(wpOrig.y, wpDir.y, ambient.dynShadowBounds.y - simPad, ambient.dynShadowBounds.w + simPad, se, sx);
        if (se <= sx) tSim = vec2(se, sx);
    }

    float tEnter = min(tVox.x <= tVox.y ? tVox.x : 1e6,
                   min(tRoof.x <= tRoof.y ? tRoof.x : 1e6,
                       tSim.x <= tSim.y ? tSim.x : 1e6));
    float tExit = max(tVox.x <= tVox.y ? tVox.y : -1e6,
                  max(tRoof.x <= tRoof.y ? tRoof.y : -1e6,
                      tSim.x <= tSim.y ? tSim.y : -1e6));
    if (tEnter > tExit) return vec3(1.0);

    float dtBase = clamp(1.55 / max(projLen, 20.0), 0.056, 0.068);
    float sCap = log(0.36 / dtBase) / MARCH_K;
    float relTCap = (0.36 - dtBase) / MARCH_K;
    int iStart = max(0, int(floor(rayStepOf(tEnter - start, dtBase, sCap, relTCap))));
    int iEnd = min(SHADOW_STEPS, int(ceil(rayStepOf(tExit - start, dtBase, sCap, relTCap))) + 1);
    if (iStart >= iEnd) return vec3(1.0);
    float sunChebRate = max(max(abs(sunDir.x), abs(sunDir.y)), 1e-4);

    vec3 sunDir3 = normalize(sunDir);
    vec3 refAxis = abs(sunDir3.z) < 0.92 ? vec3(0.0, 0.0, 1.0) : vec3(1.0, 0.0, 0.0);
    vec3 coneU = normalize(cross(sunDir3, refAxis));
    vec3 coneV = cross(sunDir3, coneU);

    vec4 laneLit = vec4(1.0);
    vec2 simLaneLit = vec2(1.0);
    float roofLit = 1.0;
    ivec2 prevWinCell = ivec2(-99999);
    int cachedBaseCode0 = 0;

    for (int i = iStart; i < iEnd; i++) {
        float t = start + rayRelT(float(i), dtBase, sCap, relTCap);
        if (t >= gridExit) break;
        float tNext = min(start + rayRelT(float(i + 1), dtBase, sCap, relTCap), gridExit);
        float stepLen = tNext - t;
        if (stepLen <= 1e-4) break;
        float tMid = t + 0.5 * stepLen;

        bool inRoof = tRoof.x <= tRoof.y && tNext >= tRoof.x && t <= tRoof.y;
        bool inVox = tVox.x <= tVox.y && tNext >= tVox.x && t <= tVox.y;
        bool inSim = tSim.x <= tSim.y && tNext >= tSim.x && t <= tSim.y;
        if (!inRoof && !inVox && !inSim) {
            float nextEnter = 1e6;
            if (tVox.x <= tVox.y && tVox.x > tNext) nextEnter = min(nextEnter, tVox.x);
            if (tRoof.x <= tRoof.y && tRoof.x > tNext) nextEnter = min(nextEnter, tRoof.x);
            if (tSim.x <= tSim.y && tSim.x > tNext) nextEnter = min(nextEnter, tSim.x);
            if (nextEnter >= 1e5) break;
            int jumpIdx = int(floor(rayStepOf(nextEnter - start, dtBase, sCap, relTCap))) - 1;
            if (jumpIdx > i) i = jumpIdx;
            continue;
        }

        vec3 qPrev = here + sunDir * t;
        if (!inRoof && !inSim && hasColBounds &&
            qPrev.x >= 0.0 && qPrev.y >= 0.0 && qPrev.x < sLotSz.x && qPrev.y < sLotSz.y) {
            ivec2 cg0 = clamp(ivec2(floor(qPrev.xy * 8.0)), ivec2(0), ivec2(vAoSize - 1));
            int y0 = vAoYBase + cg0.y;
            int m0 = int(texelFetch(voxelMap, ivec2(cg0.x, y0), 0).a * 255.0 + 0.5);
            if (m0 == 0) {
                int dCheb = int(texelFetch(voxelMap, ivec2(vAoSize + cg0.x, y0), 0).a * 255.0 + 0.5);
                if (dCheb >= 2) {
                    float tTarget = min(t + float(dCheb - 1) * 0.125 / sunChebRate, tExit);
                    if (tRoof.x <= tRoof.y && tRoof.x > t) tTarget = min(tTarget, tRoof.x);
                    if (tSim.x <= tSim.y && tSim.x > t) tTarget = min(tTarget, tSim.x);
                    int jumpIdx = int(floor(rayStepOf(tTarget - start, dtBase, sCap, relTCap))) - 1;
                    if (jumpIdx > i) {
                        i = jumpIdx;
                        continue;
                    }
                }
                continue;
            }
        }

        vec3 qMid = here + sunDir * tMid;
        vec3 q = here + sunDir * tNext;
        float relZPrev = qPrev.z - here.z;
        if (qMid.z - here.z > maxCasterH) break;
        float startFade = smoothstep(0.0, dtBase * 1.15, tMid - start);
        float distFade = (1.0 - smoothstep(maxReach * 0.86, maxReach, tMid)) * startFade;

        if (inRoof && max(qPrev.z, q.z) >= minCanopyZ) {
            float roofPen = 0.082 * tMid + 0.055;
            float cOcc = canopyOcclusionAt(qMid.xy, canopyClearZ, qPrev.z, q.z, roofPen) * distFade;
            roofLit = min(roofLit, 1.0 - cOcc);
            if (roofLit <= 0.005) break;
        }

        if ((inVox || inSim) && relZPrev <= maxVoxelH) {
            vec3 dQ = sunDir * stepLen;
            if (inVox) {
                bool checkHull = !hasColBounds || voxelColumnOverlap(qMid.xy, min(qPrev.z, q.z), max(qPrev.z, q.z), vAoSize, vAoYBase, sLotSz);
                if (checkHull) {
                    bool skipWindow = false;
                    ivec2 qCell = ivec2(floor(qMid.xy + ambient.frame.w));
                    if (qCell != prevWinCell) {
                        prevWinCell = qCell;
                        cachedBaseCode0 = maskCatFast(qCell, 1, 0, mSize, mBandH, stories);
                    }
                    int qBaseCode0 = cachedBaseCode0;
                    if (qBaseCode0 != 0) {
                        float qBase0 = ambient.contact.w + float(qBaseCode0 - 1) / 8.0;
                        int qRow = clamp(int(floor((qMid.z - qBase0 + 0.05) / STORY_HEIGHT)), 0, stories - 1);
                        if ((maskCatFast(qCell, 0, qRow, mSize, mBandH, stories) & 1) != 0) {
                            int rCode = qRow == 0 ? qBaseCode0 : maskCatFast(qCell, 1, qRow, mSize, mBandH, stories);
                            float qFloorH = rCode != 0 ? ambient.contact.w + float(qRow) * STORY_HEIGHT + float(rCode - 1) / 8.0 : qBase0 + float(qRow) * STORY_HEIGHT;
                            float qRelH = qMid.z - qFloorH;
                            if (qRelH > WINDOW_SILL - 0.08 && qRelH < WINDOW_TOP + 0.08) {
                                vec2 qFrac = fract(qMid.xy + ambient.frame.w);
                                float edgeDist = min(min(qFrac.x, 1.0 - qFrac.x), min(qFrac.y, 1.0 - qFrac.y));
                                skipWindow = edgeDist < 0.22;
                            }
                        }
                    }
                    if (!skipWindow) {
                        float rTiles = clamp(0.017 + 0.0165 * tMid, 0.017, 0.195);
                        float pad = 0.22 + 1.05 * rTiles;
                        float kTop = 0.06 + 0.38 * rTiles;
                        stepHullCone4(qMid, dQ, coneU, coneV, rTiles, pad, kTop, distFade, vSize, vHalfH, vTopMarginHalf, vSliceMax, sLotSz, invVSize, laneLit);
                    }
                }
            }
            if (inSim && tMid >= selfSimGuard && relZPrev <= maxSimH) {
                float simGate = smoothstep(selfSimGuard, selfSimGuard + 0.22, tMid) * distFade;
                float rSimPx = clamp(0.35 + 0.34 * tMid, 0.35, 2.20) * wScale;
                stepSimCone2(qMid, dQ, 0.18 + 0.02 * rSimPx, rSimPx, sunPerp, simGate, wSize, simLaneLit);
            }
            float maxLane = max(max(laneLit.x, laneLit.y), max(laneLit.z, laneLit.w));
            float maxSim = max(simLaneLit.x, simLaneLit.y);
            if (min(maxLane, maxSim) <= 0.005) {
                roofLit = 0.0;
                break;
            }
        }
    }
    float hullVis = dot(laneLit, vec4(0.25));
    float simVis = 0.5 * (simLaneLit.x + simLaneLit.y);
    float combined = min(roofLit, min(hullVis, simVis));
    return vec3(combined, combined, 1.0);
}

void main() {
    float ambScale = ambient.extent.w > 0.5 ? ambient.extent.w : 1.0;
    vec2 rawPx = (floor(gl_FragCoord.xy) + 0.5) * ambScale;
    if (rawPx.x >= ambient.extent.x || rawPx.y >= ambient.extent.y || ambient.sunLot.w <= 0.0 || ambient.params.z <= 0.001) {
        color = vec4(1.0, 0.0, 1.0, 1.0);
        return;
    }
    ivec2 limitPx = max(ivec2(ambient.extent.xy) - 1, ivec2(0));
    ivec2 fullPx = clamp(ivec2(floor(rawPx)), ivec2(0), limitPx);
    vec2 pixel = vec2(fullPx) + 0.5;
    vec4 centre = positionAt(pixel);
    if (centre.w > 0.75) {
        color = vec4(1.0, 0.0, 1.0, 1.0);
        return;
    }

    const vec3 WORLD_UP = vec3(0.0, -0.8660254, 0.5);
    const vec3 WORLD_TOWARD = vec3(0.0, 0.5, 0.8660254);
    vec3 p = centre.xyz;
    float scale = ambient.view.z;
    ivec2 vSize = textureSize(voxelMap, 0);
    bool hasVoxels = vSize.x > 1;
    int storiesCount = indoorStories();
    vec4 lift = textureSize(liftMap, 0).x > 1 ? texelFetch(liftMap, fullPx, 0) : vec4(0.0);
    bool onSnow = lift.z > 0.5;

    vec3 hereSurf;
    vec2 horizN = vec2(0.0);
    vec3 nLot = vec3(0.0, 0.0, 1.0);
    float onFlatFloor = 1.0;
    float isVertical = 0.0;
    float roofCalm = 0.0;
    float onDynamicSim = 0.0;
    float surfFaceLit = 1.0;
    float selfShadow = 1.0;

    if (centre.w > 0.25 && lift.w <= 0.001) {
        float gKey = (0.62 - texelFetch(groundMap, fullPx, 0).r) / 0.003 + ambient.view.w;
        hereSurf = lotPoint(p.xy, gKey, true, ambient.frame.xy);
        if (onSnow) hereSurf += vec3(0.5 * lift.x, 0.5 * lift.x, lift.y);
    } else {
        vec3 normal;
        vec3 nSurf;
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
                    dx = (lfOk && rfOk) ? 0.5 * (rfP.xyz - lfP.xyz) : (lfOk ? (p - lfP.xyz) : (rfP.xyz - p));
                }
            }
            hasVertGrad = uOk || dOk;
            if (!uOk && !dOk && step > fineStep + 0.5) {
                float fineMaxCont = max(1.8, 1.35 * fineStep / max(scale, 0.25));
                vec4 ufP = positionAt(pixel - vec2(0.0, fineStep)), dfP = positionAt(pixel + vec2(0.0, fineStep));
                bool ufOk = ufP.w < 0.75 && ((ufP.w < 0.75 && ufP.w < 0.25) == isSprite) && abs(p.z - ufP.z) < fineMaxCont;
                bool dfOk = dfP.w < 0.75 && ((dfP.w < 0.75 && dfP.w < 0.25) == isSprite) && abs(dfP.z - p.z) < fineMaxCont;
                hasVertGrad = ufOk || dfOk;
                if (hasVertGrad) {
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
            }
            vec3 rawCross = cross(dy, dx);
            float rawLen = length(rawCross);
            vec3 n = rawLen > 1e-5 ? rawCross / rawLen : vec3(0.0, 0.0, 1.0);
            if (n.z < 0.0) n = -n;
            nSurf = n;
            normal = centre.w > 0.25 ? n : normalize(mix(n, vec3(0.0, 0.0, 1.0), 0.25));
        }

        float key = centre.w < 0.25 ? (0.62 - texelFetch(depthMap, fullPx, 0).r) / 0.003
                                    : (0.62 - texelFetch(groundMap, fullPx, 0).r) / 0.003 + ambient.view.w;
        vec3 here = lotPoint(p.xy, key, centre.w > 0.25, ambient.frame.xy);
        float riseHere;
        if (centre.w > 0.25) {
            riseHere = 0.0;
        } else if (textureSize(overheadMap, 0).x > 1) {
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
        if (onSnow) {
            here += vec3(0.5 * lift.x, 0.5 * lift.x, lift.y);
            onGround = 1.0;
        }

        ivec2 hereCell = ivec2(floor(here.xy + ambient.frame.w));
        float hereBase0 = floorAt(hereCell, 0, here.z);
        int candUpperRow = clamp(int(floor((here.z - hereBase0) / STORY_HEIGHT + 0.5)), 1, max(1, storiesCount - 1));
        float floor2Z = candUpperRow < storiesCount ? floorAt(hereCell, candUpperRow, -100.0) : -100.0;
        float onLevel2Floor = floor2Z > -50.0
            ? (1.0 - smoothstep(0.08, 0.22, abs(here.z - floor2Z))) * smoothstep(0.55, 0.82, dot(nSurf, WORLD_UP))
            : 0.0;
        onFlatFloor = max(onGround, onLevel2Floor);

        float simMaskVal = (centre.w < 0.25 && textureSize(simMaskMap, 0).x > 1)
            ? texture(simMaskMap, pixel / ambient.extent.xy).r
            : 0.0;
        onDynamicSim = smoothstep(0.10, 0.45, simMaskVal);
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
        if (!onSnow && centre.w < 0.25 && onFlatFloor < 0.5 && onDynamicSim < 0.5 && roofSnow < 0.5) {
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
                        int vAoRows = voxelAoRows(vSize);
                        int vHalfH = vSize.x / 2 + 128 + 256 * vAoRows;
                        float vTopMarginHalf = float(64 + 256 * vAoRows);
                        ivec2 vSliceMax = ivec2(vSize.x - 1, vHalfH - 1);
                        vec2 lotSz = max(ambient.drift.zw, vec2(1.0));
                        vec3 hullProbe = vec3(wallPlaneXY + matchedWallN * 0.14, here.z);
                        float selfHull = frontOfWall * dualViewHullSolid(hullProbe, vSize, vHalfH, vTopMarginHalf, vSliceMax, lotSz, 0.09);
                        archWallMatch *= 1.0 - smoothstep(0.20, 0.68, selfHull);
                    }
                }
            }
        }

        float highRoof = (!onSnow && hasVertGrad && archWallMatch < 0.5 && centre.w < 0.25 && onLevel2Floor < 0.25 && riseHere > 115.0 && indoors(here) < 0.20)
            ? smoothstep(115.0, 124.0, riseHere) * smoothstep(0.32, 0.60, dot(normal, WORLD_UP)) * (1.0 - archWallMatch)
            : 0.0;
        roofCalm = clamp(max(roofSnow, highRoof), 0.0, 1.0);

        float nUp = dot(nSurf, WORLD_UP);
        float nToward = dot(nSurf, WORLD_TOWARD);
        float nRight = nSurf.x;
        nLot = vec3((nToward + nRight) * 0.70710678, (nToward - nRight) * 0.70710678, nUp);
        horizN = length(nLot.xy) > 0.15 ? normalize(nLot.xy) : vec2(0.0);

        hereSurf = here;
        if (archWallMatch > 0.001) {
            isVertical = archWallMatch * (1.0 - onFlatFloor) * (1.0 - roofCalm) * (1.0 - onDynamicSim);
            hereSurf = mix(here, matchedWallPos, archWallMatch);
            horizN = matchedWallN;
            vec3 wallViewN = normalize(WORLD_TOWARD * ((matchedWallN.x + matchedWallN.y) * 0.70710678)
                                     + vec3((matchedWallN.x - matchedWallN.y) * 0.70710678, 0.0, 0.0));
            nSurf = normalize(mix(nSurf, wallViewN, archWallMatch));
            nLot = vec3(matchedWallN, 0.0);
        }

        vec3 sunView = normalize(ambient.light.xyz + vec3(0.0, 0.0, 1e-4));
        float faceLit = smoothstep(-0.08, 0.22, dot(nSurf, sunView));
        float sunHorizLen = length(ambient.sunLot.xy);
        vec2 sunDirXY = sunHorizLen > 1e-4 ? ambient.sunLot.xy / sunHorizLen : vec2(1.0, 0.0);
        float vertFaceLit = length(horizN) > 0.5 ? smoothstep(0.0, 0.20, dot(horizN, sunDirXY)) : faceLit;
        surfFaceLit = mix(faceLit, vertFaceLit, isVertical);
        selfShadow = mix(1.0, surfFaceLit, max(isVertical, roofCalm));
        if (selfShadow <= 0.01) {
            color = vec4(0.0, 0.0, 0.0, 1.0);
            return;
        }
    }

    vec2 wall = wallRay(hereSurf, onFlatFloor, mix(horizN, vec2(0.0), onDynamicSim));
    if (wall.x <= 0.01) {
        color = vec4(0.0, 0.0, 0.0, 1.0);
        return;
    }

    float hereRelZ = hereSurf.z - terrainBaseAt(hereSurf.xy, hereSurf.z);
    vec3 marchOrigin = hereSurf + vec3(horizN * (0.20 * isVertical), 0.0) + nLot * (0.18 * roofCalm);
    float marchStart = mix(mix(0.65, 0.18, roofCalm), 0.16, isVertical);
    marchStart = mix(marchStart, 0.06, onFlatFloor);
    float selfSimGuard = mix(0.10, 0.62, onDynamicSim);
    float canopyClearZ = hereRelZ + mix(0.20, -0.05, isVertical);
    vec3 march = sunMarchFast(marchOrigin, marchStart, canopyClearZ, selfSimGuard, vSize, storiesCount);
    float lit = min(min(wall.x, march.x), selfShadow);
    float window = 0.0;
    if (wall.y > 0.001 && march.x > 0.001) {
        vec2 insideOffset = mix(horizN * 0.25, vec2(0.0), onFlatFloor);
        float inside = indoors(hereSurf + vec3(insideOffset, 0.0));
        window = inside * max(onFlatFloor, isVertical * surfFaceLit) * wall.y * march.x;
    }
    color = vec4(lit, window, min(min(wall.x, march.y), selfShadow), march.z);
}
