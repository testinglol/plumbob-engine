#version 450
#extension GL_GOOGLE_include_directive : require
#include "lot.glsl"

// One point per sampled screen pixel of the lot's depth, dropped onto a top-down grid of the lot at its reconstructed
// position, keeping the highest (nearest depth) at each texel: a height map of whatever the camera sees, Sims and
// walls included, for the ambient pass's sun shadows. With extent.w set it drops only feet, the lowest opaque pixels of
// something standing straight up from bare ground or a floor, for the ambient pass's contact shadows.
layout(set = 0, binding = 0) uniform sampler2D depthMap;
layout(std140, set = 1, binding = 0) uniform Scatter {
    vec4 view;   // origin x, y (screen pixels), screen pixels per scene pixel, sample stride (screen pixels)
    vec4 extent; // lot area width, height (screen pixels), sample columns, 1 for feet only
    vec4 frame;  // scene x and y of camera tile (0, 0) at altitude 0, grid texels per tile, grid margin (tiles)
    vec4 grid;   // grid width, height (texels)
} scatter;

void main() {
    gl_PointSize = 1.0;
    int columns = int(scatter.extent.z);
    vec2 pixel = floor(vec2(gl_VertexIndex % columns, gl_VertexIndex / columns) * scatter.view.w + mod(scatter.view.xy, vec2(scatter.view.w))) + 0.5;
    float depth = pixel.x < scatter.extent.x && pixel.y < scatter.extent.y ? texelFetch(depthMap, ivec2(pixel), 0).r : 1.0;
    if (depth >= 1.0) { gl_Position = vec4(-2.0, -2.0, 1.0, 1.0); return; }
    vec3 lot = lotPoint((pixel - scatter.view.xy) / scatter.view.z, (0.9 - depth) / 0.003, false, scatter.frame.xy);
    if (scatter.extent.w > 0.5) {
        // A foot has the ground (no lot depth) within two scene pixels below it, and the surface three scene pixels
        // above it rises over the same spot rather than lying flat: a leg's end, a cabinet's base, a trunk's root. A
        // rug or a seat's front edge is no foot, and transparent pixels have no depth to begin with.
        float step = max(scatter.view.z * 1.5, 1.0);
        bool ground = false;
        for (int i = 1; i <= 3; i++) {
            vec2 below = pixel + vec2(0.0, float(i) * step);
            if (below.y >= scatter.extent.y) {
                ground = true;
                break;
            }
            float belowDepth = texelFetch(depthMap, ivec2(below), 0).r;
            if (belowDepth >= 1.0) {
                ground = true;
                break;
            }
            if (lot.z > 1.5) {
                vec3 dn = lotPoint((below - scatter.view.xy) / scatter.view.z, (0.9 - belowDepth) / 0.003, false, scatter.frame.xy);
                if (abs(dn.z - lot.z) < 0.06 && length(dn.xy - lot.xy) > 0.03) {
                    ground = true;
                    break;
                }
            }
        }
        vec2 abovePixel = pixel - vec2(0.0, 3.0 * step);
        float above = abovePixel.y >= 0.0 ? texelFetch(depthMap, ivec2(abovePixel), 0).r : 1.0;
        vec3 up = lotPoint((abovePixel - scatter.view.xy) / scatter.view.z, (0.9 - above) / 0.003, false, scatter.frame.xy);
        if (!ground || above >= 1.0 || up.z - lot.z < 0.03 || length(up.xy - lot.xy) > 0.42) {
            gl_Position = vec4(-2.0, -2.0, 1.0, 1.0);
            return;
        }
    }
    vec2 texel = (lot.xy + scatter.frame.w) * scatter.frame.z;
    gl_Position = vec4(texel.x / scatter.grid.x * 2.0 - 1.0, 1.0 - texel.y / scatter.grid.y * 2.0,
                       clamp(0.5 - lot.z / HEIGHT_RANGE, 0.0, 1.0), 1.0);
}
