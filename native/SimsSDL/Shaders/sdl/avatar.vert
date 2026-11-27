#version 450
#extension GL_GOOGLE_include_directive : require
#include "quad.glsl"

struct AvatarVertex { vec4 position; vec2 uv; vec2 padding; vec4 normal; };
layout(std430, set = 0, binding = 0) readonly buffer Vertices { AvatarVertex vertices[]; };

layout(location = 0) out vec2 outUV;
layout(location = 1) flat out vec4 outTint;
layout(location = 2) out vec3 outNormal;
// quad.uvRect.x: 0 = avatar lit, 1 = unlit (Character Detail Low), 2 = roof slope shading.
layout(location = 3) flat out float outTextureOnly;
layout(location = 4) flat out vec3 outSunDir;

void main() {
    uint baseVertex = floatBitsToUint(quad.depthInterval.x);
    AvatarVertex vertex = vertices[baseVertex + uint(gl_VertexIndex)];
    vec3 pos = vertex.position.xyz;
    vec3 nrm = vertex.normal.xyz;
    float yaw = quad.depthInterval.y;
    if (yaw != 0.0 && vertex.padding.y > 0.0) {
        float c = cos(yaw);
        float s = sin(yaw);
        float su = pos.x - 0.5;
        float sv = vertex.padding.x;
        float suRot = su * c - sv * s;
        float svRot = sv * c + su * s;
        float dv = (svRot - sv) / (32.0 * vertex.padding.y);
        pos.x = 0.5 + suRot;
        pos.y += 0.5 * (svRot - sv);
        pos.z = clamp(pos.z - dv * 0.003, 0.001, 0.999);
        nrm = vec3(nrm.x * c - nrm.z * s, nrm.y, nrm.z * c + nrm.x * s);
    }
    gl_Position = canvasPosition(quad.rect.xy + pos.xy * quad.rect.zw, pos.z);
    outUV = vertex.uv;
    outTint = quad.tint;
    outNormal = nrm;
    outTextureOnly = quad.uvRect.x;
    outSunDir = quad.uvRect.yzw;
}
