#version 450

#extension GL_GOOGLE_include_directive : require
#include "lot.glsl"

layout(set = 2, binding = 0) uniform sampler2D ambientMap;
layout(set = 2, binding = 1) uniform sampler2D depthMap;
layout(set = 2, binding = 2) uniform sampler2D groundMap;
layout(set = 2, binding = 3) uniform sampler2D liftMap;
#include "ambientUniforms.glsl"
layout(location = 0) out vec4 color;

const float DEPTH_UNIT = 27.712813;

vec2 surfaceInfoAt(ivec2 pixel, bool hasLift) {
    float depth = texelFetch(depthMap, pixel, 0).r;
    bool terrain = depth >= 1.0;
    if (terrain) depth = texelFetch(groundMap, pixel, 0).r;
    if (depth >= 1.0) return vec2(-1.0e5, 0.0);
    float key = (0.9 - depth) / 0.003 + (terrain ? ambient.view.w : 0.0);
    float capSnow = 0.0;
    if (hasLift) {
        vec4 lift = texelFetch(liftMap, pixel, 0);
        if (lift.z > 0.5) {
            vec2 scene = (vec2(pixel) + 0.5 - ambient.view.xy) / ambient.view.z;
            vec3 surface = lotPoint(scene, key, terrain, ambient.frame.xy);
            surface += vec3(0.5 * lift.x, 0.5 * lift.x, lift.y);
            key = surface.x + surface.y + 0.8 * surface.z;
        } else if (!terrain && lift.z < -0.002) {
            capSnow = clamp(-lift.z, 0.0, 1.0);
        }
    }
    return vec2(key * DEPTH_UNIT, capSnow);
}

void main() {
    ivec2 pixel = ivec2(gl_FragCoord.xy);
    ivec2 limit = ivec2(ambient.extent.xy) - 1;
    if (any(greaterThan(pixel, limit))) { color = vec4(0.5); return; }
    bool hasLift = textureSize(liftMap, 0).x > 1;
    vec2 hereInfo = surfaceInfoAt(pixel, hasLift);
    float z = hereInfo.x;
    float tolerance = mix(3.2, 8.5, clamp((1.5 - ambient.view.z) / 1.0, 0.0, 1.0));
    float ambScale = ambient.extent.w > 0.5 ? ambient.extent.w : 1.0;
    vec3 total = vec3(0.0);
    float weight = 0.0;
    if (ambScale > 1.5) {
        ivec2 ambLimit = textureSize(ambientMap, 0) - 1;
        vec2 ambPos = (vec2(pixel) + 0.5) / ambScale - 0.5;
        ivec2 baseAmb = ivec2(round(ambPos));
        float bestDz = 1.0e9;
        vec3 bestColor = vec3(0.5);
        for (int y = -1; y <= 1; y++) {
            for (int x = -1; x <= 1; x++) {
                ivec2 ambTap = clamp(baseAmb + ivec2(x, y), ivec2(0), ambLimit);
                vec2 fullCenter = (vec2(ambTap) + 0.5) * ambScale;
                ivec2 fullTap = clamp(ivec2(floor(fullCenter)), ivec2(0), limit);
                vec2 delta = fullCenter - (vec2(pixel) + 0.5);
                vec2 tapInfo = surfaceInfoAt(fullTap, hasLift);
                float localTol = tolerance + 22.0 * smoothstep(0.10, 0.65, min(hereInfo.y, tapInfo.y));
                float dz = abs(tapInfo.x - z);
                vec3 tapCol = texelFetch(ambientMap, ambTap, 0).rgb;
                if (dz < bestDz) {
                    bestDz = dz;
                    bestColor = tapCol;
                }
                float w = exp(-dz / localTol) * exp(-dot(delta, delta) / (3.2 * ambScale * ambScale));
                total += tapCol * w;
                weight += w;
            }
        }
        color = vec4(weight > 1e-5 ? total / weight : bestColor, 1.0);
        return;
    }
    for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
            ivec2 tap = clamp(pixel + ivec2(x, y), ivec2(0), limit);
            vec2 tapInfo = surfaceInfoAt(tap, hasLift);
            float localTol = tolerance + 22.0 * smoothstep(0.10, 0.65, min(hereInfo.y, tapInfo.y));
            float dz = abs(tapInfo.x - z);
            float w = exp(-dz / localTol) * exp(-float(x * x + y * y) / 2.6);
            total += texelFetch(ambientMap, tap, 0).rgb * w;
            weight += w;
        }
    }
    if (ambient.view.z >= 1.4) {
        const ivec2 OUTER[8] = ivec2[8](
            ivec2(2, 0), ivec2(-2, 0), ivec2(0, 2), ivec2(0, -2),
            ivec2(2, 2), ivec2(-2, 2), ivec2(2, -2), ivec2(-2, -2));
        for (int i = 0; i < 8; i++) {
            float d2 = float(OUTER[i].x * OUTER[i].x + OUTER[i].y * OUTER[i].y);
            float outerSpatial = exp(-d2 / 3.4);
            ivec2 tap = clamp(pixel + OUTER[i], ivec2(0), limit);
            vec2 tapInfo = surfaceInfoAt(tap, hasLift);
            float localTol = tolerance + 22.0 * smoothstep(0.10, 0.65, min(hereInfo.y, tapInfo.y));
            float dz = abs(tapInfo.x - z);
            float w = exp(-dz / localTol) * outerSpatial;
            total += texelFetch(ambientMap, tap, 0).rgb * w;
            weight += w;
        }
    }
    color = vec4(total / weight, 1.0);
}
