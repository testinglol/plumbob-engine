#version 450
#extension GL_GOOGLE_include_directive : require
#include "lot.glsl"

layout(set = 0, binding = 0) uniform sampler2D depthMap;
layout(std140, set = 1, binding = 0) uniform Scatter {
    vec4 view;
    vec4 extent;
    vec4 frame;
    vec4 grid;
} scatter;

void main() {
    gl_PointSize = 1.0;
    int columns = int(scatter.extent.z);
    vec2 pixel = floor(vec2(gl_VertexIndex % columns, gl_VertexIndex / columns) * scatter.view.w + mod(scatter.view.xy, vec2(scatter.view.w))) + 0.5;
    float depth = pixel.x < scatter.extent.x && pixel.y < scatter.extent.y ? texelFetch(depthMap, ivec2(pixel), 0).r : 1.0;
    if (depth >= 1.0) { gl_Position = vec4(-2.0, -2.0, 1.0, 1.0); return; }
    vec3 lot = lotPoint((pixel - scatter.view.xy) / scatter.view.z, (0.62 - depth) / 0.003, false, scatter.frame.xy);
    if (scatter.extent.w > 0.5) {
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
                vec3 dn = lotPoint((below - scatter.view.xy) / scatter.view.z, (0.62 - belowDepth) / 0.003, false, scatter.frame.xy);
                if (abs(dn.z - lot.z) < 0.06 && length(dn.xy - lot.xy) > 0.03) {
                    ground = true;
                    break;
                }
            }
        }
        vec2 abovePixel = pixel - vec2(0.0, 3.0 * step);
        float above = abovePixel.y >= 0.0 ? texelFetch(depthMap, ivec2(abovePixel), 0).r : 1.0;
        vec3 up = lotPoint((abovePixel - scatter.view.xy) / scatter.view.z, (0.62 - above) / 0.003, false, scatter.frame.xy);
        if (!ground || above >= 1.0 || up.z - lot.z < 0.03 || length(up.xy - lot.xy) > 0.42) {
            gl_Position = vec4(-2.0, -2.0, 1.0, 1.0);
            return;
        }
    }
    vec2 texel = (lot.xy + scatter.frame.w) * scatter.frame.z;
    gl_Position = vec4(texel.x / scatter.grid.x * 2.0 - 1.0, 1.0 - texel.y / scatter.grid.y * 2.0,
                       clamp(0.5 - lot.z / HEIGHT_RANGE, 0.0, 1.0), 1.0);
}
