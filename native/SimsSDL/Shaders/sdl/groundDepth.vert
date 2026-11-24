#version 450
#extension GL_GOOGLE_include_directive : require
#include "quad.glsl"

struct TerrainVertex { vec2 position; vec2 grass; vec4 color; vec4 dark; };
layout(std430, set = 0, binding = 0) readonly buffer Vertices { TerrainVertex vertices[]; };

void main() {
    TerrainVertex vertex = vertices[gl_VertexIndex];
    gl_Position = canvasPosition(quad.rect.xy + vertex.position * quad.rect.zw, vertex.grass.y);
}
