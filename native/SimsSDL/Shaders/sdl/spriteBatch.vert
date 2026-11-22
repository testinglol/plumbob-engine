#version 450
#extension GL_GOOGLE_include_directive : require
#include "quad.glsl"

struct SpriteInstance {
    vec4 rect;
    vec4 uvRect;
    vec4 tint;
    vec4 params;
};
layout(std430, set = 0, binding = 0) readonly buffer Vertices { SpriteInstance vertices[]; };

layout(location = 0) out vec2 outUV;
layout(location = 1) flat out vec4 outTint;
layout(location = 2) flat out vec4 outDepthInterval;
layout(location = 3) flat out float outOpacity;
layout(location = 4) flat out vec4 outUVRect;

const vec2 corners[6] = vec2[6](vec2(0, 0), vec2(1, 0), vec2(0, 1), vec2(0, 1), vec2(1, 0), vec2(1, 1));

void main() {
    uint idx = uint(gl_VertexIndex);
    uint instanceIdx = floatBitsToUint(quad.depthInterval.x) + (idx / 6u);
    uint cornerIdx = idx % 6u;
    SpriteInstance inst = vertices[instanceIdx];
    vec2 uv = corners[cornerIdx];
    gl_Position = canvasPosition(inst.rect.xy + uv * inst.rect.zw, 0.0);
    vec2 source = vec2(inst.params.x > 0.0 ? 1.0 - uv.x : uv.x, uv.y);
    outUV = inst.uvRect.xy + source * inst.uvRect.zw;
    outTint = inst.tint;
    outDepthInterval = vec4(0.0, 0.0, inst.params.z, inst.params.w);
    outOpacity = inst.params.y;
    outUVRect = inst.uvRect;
}
