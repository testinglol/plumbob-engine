#version 450
layout(set = 2, binding = 0) uniform sampler2D art;
layout(set = 2, binding = 1) uniform sampler2D depthMap;
layout(location = 0) in vec2 inUV;
layout(location = 1) flat in vec4 inTint;
layout(location = 2) flat in vec4 inDepthInterval;
layout(location = 0) out vec4 color;
void main() {
    vec4 sampled = texture(art, inUV);
    if (sampled.a < 0.25) discard;
    ivec2 dimensions = textureSize(depthMap, 0);
    ivec2 coordinate = min(ivec2(clamp(inUV, 0.0, 1.0) * vec2(dimensions)), dimensions - 1);
    float depth = texelFetch(depthMap, coordinate, 0).r;
    if (depth >= 1.0) discard;
    color = sampled * inTint;
    gl_FragDepth = mix(inDepthInterval.x, inDepthInterval.y, depth * 255.0 / 254.0);
}
