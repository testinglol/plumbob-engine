#version 450
#extension GL_GOOGLE_include_directive : require
#include "quad.glsl"

struct TerrainVertex { vec2 position; vec2 padding; vec4 color; };
layout(std430, set = 0, binding = 0) readonly buffer Vertices { TerrainVertex vertices[]; };

layout(location = 0) out vec4 outColor;
layout(location = 1) out vec2 outCoordinate;

void main() {
    TerrainVertex vertex = vertices[gl_VertexIndex];
    gl_Position = canvasPosition(quad.rect.xy + vertex.position * quad.rect.zw, 0.0);
    outColor = vertex.color * quad.tint;
    outCoordinate = vertex.position;
}
