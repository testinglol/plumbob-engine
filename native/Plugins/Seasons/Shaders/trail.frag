#version 450
#extension GL_GOOGLE_include_directive : require

// Where feet have pressed the snow, on the lot's own tiles (TRAIL_TEXELS a tile, TRAIL_MARGIN around the lot): the
// last frame's trail, filled back in by the snow that fell since, with the prints made since stamped over it. Each
// print is a shoe (a rounded sole and a smaller heel with a gap between, set off to its side of the walk) or a pet's
// oval paw, soft over about a texel so the season pass can draw its edge crisply between texels.
layout(set = 2, binding = 0) uniform sampler2D previous;
#include "ambientUniforms.glsl"
layout(location = 0) out vec4 color;

// How deep a print presses at `lot` (0 to 1).
float print(vec2 lot, vec4 p) {
    float foot = abs(p.w);
    bool paw = foot > 1.5;
    float size = paw ? 1.0 : foot;
    vec2 along = vec2(cos(p.z), sin(p.z)), across = vec2(-along.y, along.x);
    // Right feet fall to the right of the walk, left to the left.
    vec2 d = lot - p.xy + across * sign(p.w) * (paw ? 0.045 : 0.065 * size);
    if (dot(d, d) > 0.09) return 0.0;
    vec2 local = vec2(dot(d, along), dot(d, across)) / size;
    // Distances (tiles) outside each part's edge, as an ellipse's: (length in radii − 1) times its smaller radius.
    float edge;
    if (paw) {
        edge = (length(local / vec2(0.05, 0.04)) - 1.0) * 0.04;
    } else {
        // A boot presses one connected silhouette into powder; separated heel
        // and toe holes read as two tiny dots when the snow is deep.
        float sole = (length((local - vec2(0.03, 0.0)) / vec2(0.085, 0.053)) - 1.0) * 0.053;
        float heel = (length((local - vec2(-0.04, 0.0)) / vec2(0.045, 0.046)) - 1.0) * 0.046;
        edge = min(sole, heel) * size;
    }
    return clamp(0.5 - edge * TRAIL_TEXELS / 1.5, 0.0, 1.0);
}

void main() {
    ivec2 at = ivec2(gl_FragCoord.xy);
    float texels = ambient.prevView.x > 0.0 ? ambient.prevView.x : TRAIL_TEXELS;
    vec2 margin = ambient.prevView.x > 0.0 ? ambient.prevView.yz : vec2(TRAIL_MARGIN);
    vec2 lot = gl_FragCoord.xy / texels - margin;
    float texPad = max(0.0, 0.65 / texels - 0.02);
    vec4 prev = texelFetch(previous, at, 0);

    if (ambient.season.x > 1.5) {
        float pressed = (ambient.season.w < -0.5 || prev.a < 0.75)
            ? 0.0
            : max(0.0, prev.r - ambient.season.z);
        for (int i = 0; i < MAX_PRINTS; i++) {
            float foot = ambient.prints[i].w;
            if (foot == 0.0) break;
            if (abs(foot) <= 2.5)
                pressed = max(pressed, print(lot, ambient.prints[i]));
        }
        color = vec4(pressed, 0.0, 0.0, 1.0);
    } else if (ambient.season.x > 0.5) {
        if (ambient.season.w < -0.5 || abs(prev.a - 0.5) > 0.15)
            prev = vec4(0.0, 0.0, 0.0, 0.5);
        for (int i = 0; i < MAX_PRINTS; i++) {
            vec4 p = ambient.prints[i];
            if (p.w == 0.0) break;
            if (p.w > 3.5) {
                prev = vec4(0.0, 0.0, 0.0, 0.5);
                continue;
            }
            if (p.w >= 1.0 && p.w <= 2.05) {
                float lumBin = clamp(floor(p.z * 0.1), 0.0, 60.0);
                float r = max(p.z - lumBin * 10.0, 0.6);
                float lumEnc = 0.38 + (lumBin / 60.0) * 0.24;
                float hue = clamp(p.w - 1.0, 0.08, 0.94);
                float dist = length(lot - p.xy);
                float leafDrop = 1.0 - smoothstep(r * 0.12, r * 1.05, dist);
                float metaMask = 1.0 - smoothstep(max(0.30, r - 0.15), r + 0.45 + texPad, dist);
                float coreClear = 1.0 - smoothstep(0.28, 0.48, dist);
                prev.r *= 1.0 - coreClear;
                if (leafDrop > prev.g || (metaMask > 0.14 && prev.g < 0.05 && prev.b < 0.04)) {
                    prev.b = hue;
                    prev.a = lumEnc;
                }
                prev.g = max(prev.g, leafDrop);
            } else if (p.w >= 2.08 && p.w <= 3.15) {
                float lumBin = clamp(floor(p.z * 0.1), 0.0, 60.0);
                float r = max(p.z - lumBin * 10.0, 0.45);
                float lumEnc = 0.38 + (lumBin / 60.0) * 0.24;
                float hue = clamp(p.w - 2.1, 0.08, 0.94);
                float dist = length(lot - p.xy);
                float shrubMeta = 1.0 - smoothstep(max(0.28, r - 0.08), r + 0.42 + texPad, dist);
                float coreClear = 1.0 - smoothstep(0.30, 0.48, dist);
                prev.r *= 1.0 - coreClear;
                if ((coreClear > 0.25 && prev.g < 0.72) || (shrubMeta > 0.12 && prev.b < 0.04)) {
                    prev.b = hue;
                    prev.a = lumEnc;
                }
                float shrubDrop = 0.52 * (1.0 - smoothstep(r * 0.20, r * 1.45, dist));
                prev.g = max(prev.g, shrubDrop);
            } else if (p.w < -0.75 && p.w > -1.25) {
                float r = max(p.z, 0.6);
                float mask = 1.0 - smoothstep(max(0.25, r - 0.22 + texPad * 0.5), r + 0.14 + texPad, length(lot - p.xy));
                prev.r = max(prev.r, mask);
            } else if (p.w <= -1.25 && p.w > -1.75) {
                float r = max(p.z, 0.40);
                float mask = 1.0 - smoothstep(max(0.18, r - 0.14 + texPad * 0.35), r + 0.04 + texPad * 0.5, length(lot - p.xy));
                prev.r = max(prev.r, 0.64 * mask);
            } else if (p.w <= -1.75 && p.w > -2.75) {
                bool horizontal = p.w > -2.25;
                vec2 halfSize = horizontal ? vec2(max(p.z, 0.50) + 0.04, 0.56) : vec2(0.56, max(p.z, 0.50) + 0.04);
                vec2 q = abs(lot - p.xy) - halfSize;
                float boxDist = length(max(q, vec2(0.0))) + min(max(q.x, q.y), 0.0);
                float mask = 1.0 - smoothstep(-0.02, 0.08, boxDist);
                prev.r = max(prev.r, 0.64 * mask);
            }
        }
        color = vec4(prev.rgb, clamp(prev.a, 0.38, 0.62));
    } else {
        color = vec4(0.0, 0.0, 0.0, 1.0);
    }
}
