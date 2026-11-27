#version 450

#extension GL_GOOGLE_include_directive : require
#include "lot.glsl"

layout(set = 2, binding = 0) uniform sampler2D ambientMap;
layout(set = 2, binding = 1) uniform sampler2D depthMap;
layout(set = 2, binding = 2) uniform sampler2D groundMap;
layout(set = 2, binding = 3) uniform sampler2D liftMap;
layout(set = 2, binding = 4) uniform sampler2D simMaskMap;
#include "ambientUniforms.glsl"
layout(location = 0) out vec4 color;

const float DEPTH_UNIT = 27.712813;

struct SurfaceSample {
    vec3 lot;
    float z;
    float soft;
    int cls;
};

float ignBlur(vec2 pixel) {
    return fract(52.9829189 * fract(dot(pixel, vec2(0.06711056, 0.00583715))));
}

SurfaceSample surfaceSampleAt(ivec2 pixel, bool hasLift, bool hasSimMask) {
    SurfaceSample s;
    s.lot = vec3(0.0);
    s.z = -1.0e5;
    s.soft = 0.0;
    s.cls = -1;

    float depth = texelFetch(depthMap, pixel, 0).r;
    bool terrain = depth >= 1.0;
    if (terrain) depth = texelFetch(groundMap, pixel, 0).r;
    if (depth >= 1.0) return s;

    float scale = max(ambient.view.z, 0.25);
    vec2 scene = (vec2(pixel) + 0.5 - ambient.view.xy) / scale;
    float key = (0.62 - depth) / 0.003 + (terrain ? ambient.view.w : 0.0);
    vec3 surface = lotPoint(scene, key, terrain, ambient.frame.xy);
    int cls = terrain ? 1 : 0;

    if (hasLift) {
        vec4 lift = texelFetch(liftMap, pixel, 0);
        if (lift.z > 0.5) {
            surface += vec3(0.5 * lift.x, 0.5 * lift.x, lift.y);
            key = surface.x + surface.y + 0.8 * surface.z;
            cls = 2;
        } else if (!terrain && lift.z < -0.002) {
            s.soft = clamp(-lift.z, 0.0, 1.0);
        }
    } else if (terrain) {
        key = surface.x + surface.y + 0.8 * surface.z;
    }

    if (cls == 0 && hasSimMask) {
        s.soft = max(s.soft, texelFetch(simMaskMap, pixel, 0).r * 0.65);
    }

    s.lot = surface;
    s.z = key * DEPTH_UNIT;
    s.cls = cls;
    return s;
}

bool reconstructPlane(SurfaceSample c, SurfaceSample l, SurfaceSample r, SurfaceSample u, SurfaceSample d, float scale, out vec3 outN) {
    outN = vec3(0.0, 0.0, 1.0);
    float maxStep = 0.28 / max(scale, 0.35) + 0.08;
    bool lOk = l.cls == c.cls && length(c.lot - l.lot) < maxStep;
    bool rOk = r.cls == c.cls && length(r.lot - c.lot) < maxStep;
    bool uOk = u.cls == c.cls && length(c.lot - u.lot) < maxStep;
    bool dOk = d.cls == c.cls && length(d.lot - c.lot) < maxStep;
    if (!(lOk && rOk && uOk && dOk)) return false;

    float curvX = length((r.lot - c.lot) - (c.lot - l.lot));
    float curvY = length((d.lot - c.lot) - (c.lot - u.lot));
    if (max(curvX, curvY) > 0.055) return false;

    vec3 cr = cross(r.lot - l.lot, d.lot - u.lot);
    float crLen = length(cr);
    if (crLen <= 1e-6) return false;
    outN = cr / crLen;
    return true;
}

float effectiveDepthDelta(SurfaceSample here, SurfaceSample tap, bool isPlanar, vec3 nLot, vec2 deltaPx, float scale, float localTol) {
    float rawDz = abs(tap.z - here.z);
    float minSoft = min(here.soft, tap.soft);
    if (isPlanar && tap.cls == here.cls) {
        float planeDist = abs(dot(nLot, tap.lot - here.lot));
        float maxInPlane = length(deltaPx) / (13.5 * max(scale, 0.25)) + 0.12;
        float excess3D = max(0.0, length(tap.lot - here.lot) - maxInPlane);
        return (planeDist * 2.15 + excess3D * 1.85) * DEPTH_UNIT;
    }
    bool snowVsTerrain = (here.cls >= 1 && tap.cls >= 1);
    float clsPenalty = (tap.cls != here.cls && !snowVsTerrain)
        ? 1.55 * localTol * (1.0 - smoothstep(0.10, 0.55, minSoft))
        : 0.0;
    return rawDz + clsPenalty;
}

vec3 ditherOut(vec3 c, ivec2 pixel, int cls) {
    if (cls == 2) return c;
    vec2 cell = vec2(pixel);
    float tri = ignBlur(cell + vec2(5.0, 13.0)) + ignBlur(cell + vec2(29.0, 47.0)) - 1.0;
    vec3 stepLin = mix(vec3(1.0 / (12.92 * 255.0)), 2.2 * pow(max(c, vec3(0.0031308)), vec3(0.545)) / 255.0, step(vec3(0.0031308), c));
    return clamp(c + tri * 0.22 * stepLin, 0.0, 1.0);
}

void main() {
    ivec2 pixel = ivec2(gl_FragCoord.xy);
    ivec2 limit = ivec2(ambient.extent.xy) - 1;
    if (any(greaterThan(pixel, limit))) { color = vec4(0.5); return; }
    bool hasLift = textureSize(liftMap, 0).x > 1;
    bool hasSimMask = textureSize(simMaskMap, 0).x > 1;
    SurfaceSample here = surfaceSampleAt(pixel, hasLift, hasSimMask);
    if (here.cls < 0) { color = vec4(0.5, 0.5, 0.5, 1.0); return; }

    float scale = max(ambient.view.z, 0.25);
    float tolerance = mix(3.2, 8.5, clamp((1.5 - ambient.view.z) / 1.0, 0.0, 1.0));
    float ambScale = ambient.extent.w > 0.5 ? ambient.extent.w : 1.0;
    vec3 total = vec3(0.0);
    float weight = 0.0;

    if (ambScale > 1.5) {
        ivec2 ambLimit = textureSize(ambientMap, 0) - 1;
        vec2 pCenter = vec2(pixel) + 0.5;
        vec2 ambCoord = (pCenter - (floor(0.5 * ambScale) + 0.5)) / ambScale;
        ivec2 baseAmb = ivec2(floor(ambCoord)) - 1;
        vec3 cTap[16];
        vec3 minC = vec3(2.0);
        vec3 maxC = vec3(-1.0);
        int idx = 0;
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                ivec2 ambTap = clamp(baseAmb + ivec2(x, y), ivec2(0), ambLimit);
                vec3 v = texelFetch(ambientMap, ambTap, 0).rgb;
                cTap[idx++] = v;
                minC = min(minC, v);
                maxC = max(maxC, v);
            }
        }
        vec3 span = maxC - minC;
        if (max(span.r, max(span.g, span.b)) <= 0.0005) {
            color = vec4(ditherOut(cTap[5], pixel, here.cls), 1.0);
            return;
        }

        SurfaceSample sL = surfaceSampleAt(clamp(pixel + ivec2(-1, 0), ivec2(0), limit), hasLift, hasSimMask);
        SurfaceSample sR = surfaceSampleAt(clamp(pixel + ivec2( 1, 0), ivec2(0), limit), hasLift, hasSimMask);
        SurfaceSample sU = surfaceSampleAt(clamp(pixel + ivec2(0, -1), ivec2(0), limit), hasLift, hasSimMask);
        SurfaceSample sD = surfaceSampleAt(clamp(pixel + ivec2(0,  1), ivec2(0), limit), hasLift, hasSimMask);
        vec3 nLot;
        bool isPlanar = reconstructPlane(here, sL, sR, sU, sD, scale, nLot);

        float rMax = 1.96 * ambScale;
        float bestDz = 1.0e9;
        float maxTapZ = -1.0e9;
        float bestLuma = -1.0;
        vec3 bestColor = vec3(0.5);
        vec3 brightColor = cTap[5];
        idx = 0;
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                ivec2 ambTap = clamp(baseAmb + ivec2(x, y), ivec2(0), ambLimit);
                ivec2 fullTap = clamp(ivec2(floor((vec2(ambTap) + 0.5) * ambScale)), ivec2(0), limit);
                vec2 fullCenter = vec2(fullTap) + 0.5;
                vec2 delta = fullCenter - pCenter;
                vec3 tapCol = cTap[idx++];
                float uDist = clamp(1.0 - length(delta) / rMax, 0.0, 1.0);
                if (uDist <= 0.0) continue;
                SurfaceSample tap = surfaceSampleAt(fullTap, hasLift, hasSimMask);
                if (tap.cls < 0) continue;
                float localTol = tolerance + 22.0 * smoothstep(0.10, 0.65, min(here.soft, tap.soft));
                float dz = effectiveDepthDelta(here, tap, isPlanar, nLot, delta, scale, localTol);
                maxTapZ = max(maxTapZ, tap.z);
                float lum = dot(tapCol, LUMA);
                if (lum > bestLuma) {
                    bestLuma = lum;
                    brightColor = tapCol;
                }
                if (dz < bestDz) {
                    bestDz = dz;
                    bestColor = tapCol;
                }
                float spatialW = uDist * uDist * (3.0 - 2.0 * uDist);
                float w = exp(-dz / localTol) * spatialW;
                total += tapCol * w;
                weight += w;
            }
        }
        if (weight < 0.05) {
            const ivec2 RING_OUT[8] = ivec2[8](
                ivec2(-1, 1), ivec2(4, 1), ivec2(1, -1), ivec2(1, 4),
                ivec2(-1, 2), ivec2(4, 2), ivec2(2, -1), ivec2(2, 4));
            float rOuter = 2.85 * ambScale;
            for (int i = 0; i < 8; i++) {
                ivec2 ambTap = clamp(baseAmb + RING_OUT[i], ivec2(0), ambLimit);
                ivec2 fullTap = clamp(ivec2(floor((vec2(ambTap) + 0.5) * ambScale)), ivec2(0), limit);
                vec2 fullCenter = vec2(fullTap) + 0.5;
                vec2 delta = fullCenter - pCenter;
                float uDist = clamp(1.0 - length(delta) / rOuter, 0.0, 1.0);
                if (uDist <= 0.0) continue;
                SurfaceSample tap = surfaceSampleAt(fullTap, hasLift, hasSimMask);
                if (tap.cls < 0) continue;
                float localTol = tolerance + 22.0 * smoothstep(0.10, 0.65, min(here.soft, tap.soft));
                float dz = effectiveDepthDelta(here, tap, isPlanar, nLot, delta, scale, localTol);
                vec3 tapCol = texelFetch(ambientMap, ambTap, 0).rgb;
                maxTapZ = max(maxTapZ, tap.z);
                if (dz < bestDz) {
                    bestDz = dz;
                    bestColor = tapCol;
                }
                float w = exp(-dz / localTol) * (uDist * uDist * (3.0 - 2.0 * uDist));
                total += tapCol * w;
                weight += w;
            }
        }
        vec3 fallbackCol = (here.z - maxTapZ > 2.5 * tolerance) ? brightColor : bestColor;
        vec3 resolved = weight > 1e-4 ? total / weight : fallbackCol;
        color = vec4(ditherOut(resolved, pixel, here.cls), 1.0);
        return;
    }

    SurfaceSample grid[9];
    int gIdx = 0;
    for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
            grid[gIdx++] = (x == 0 && y == 0)
                ? here
                : surfaceSampleAt(clamp(pixel + ivec2(x, y), ivec2(0), limit), hasLift, hasSimMask);
        }
    }
    vec3 nLot;
    bool isPlanar = reconstructPlane(here, grid[3], grid[5], grid[1], grid[7], scale, nLot);

    gIdx = 0;
    for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
            ivec2 tapPx = clamp(pixel + ivec2(x, y), ivec2(0), limit);
            SurfaceSample tap = grid[gIdx++];
            if (tap.cls < 0) continue;
            float localTol = tolerance + 22.0 * smoothstep(0.10, 0.65, min(here.soft, tap.soft));
            float dz = effectiveDepthDelta(here, tap, isPlanar, nLot, vec2(float(x), float(y)), scale, localTol);
            float w = exp(-dz / localTol) * exp(-float(x * x + y * y) / 2.6);
            total += texelFetch(ambientMap, tapPx, 0).rgb * w;
            weight += w;
        }
    }
    float outerFade = smoothstep(1.15, 1.65, ambient.view.z);
    if (outerFade > 0.001) {
        const ivec2 OUTER[8] = ivec2[8](
            ivec2(2, 0), ivec2(-2, 0), ivec2(0, 2), ivec2(0, -2),
            ivec2(2, 2), ivec2(-2, 2), ivec2(2, -2), ivec2(-2, -2));
        for (int i = 0; i < 8; i++) {
            float d2 = float(OUTER[i].x * OUTER[i].x + OUTER[i].y * OUTER[i].y);
            float outerSpatial = outerFade * exp(-d2 / 3.4);
            ivec2 tapPx = clamp(pixel + OUTER[i], ivec2(0), limit);
            SurfaceSample tap = surfaceSampleAt(tapPx, hasLift, hasSimMask);
            if (tap.cls < 0) continue;
            float localTol = tolerance + 22.0 * smoothstep(0.10, 0.65, min(here.soft, tap.soft));
            float dz = effectiveDepthDelta(here, tap, isPlanar, nLot, vec2(OUTER[i]), scale, localTol);
            float w = exp(-dz / localTol) * outerSpatial;
            total += texelFetch(ambientMap, tapPx, 0).rgb * w;
            weight += w;
        }
    }
    vec3 outCol = weight > 1e-4 ? total / weight : texelFetch(ambientMap, pixel, 0).rgb;
    color = vec4(ditherOut(outCol, pixel, here.cls), 1.0);
}
