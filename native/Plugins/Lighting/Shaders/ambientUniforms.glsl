const int MAX_LAMPS = 16;

layout(std140, set = 3, binding = 0) uniform Ambient {
    vec4 view;
    vec4 params;
    vec4 light;
    vec4 extent;
    vec4 lamp;
    vec4 contact;
    vec4 frame;
    vec4 sunLot;
    vec4 clouds;
    vec4 drift;
    vec4 weather;
    vec4 tone;
    vec4 lamps[MAX_LAMPS];
    vec4 skyExtra;
    vec4 shadowView;
    vec4 prevView;
} ambient;

const vec3 LAMP_COLOR = vec3(1.0, 0.82, 0.58);
const vec3 FIRE_COLOR = vec3(1.0, 0.34, 0.05);
const vec3 LUMA = vec3(0.2126, 0.7152, 0.0722);

vec2 sceneOf(vec3 q) { return vec2(32.0 * (q.x - q.y), 16.0 * (q.x + q.y) - 40.0 * q.z) + ambient.frame.xy; }

float hash12(vec2 q) {
    vec3 r = fract(vec3(q.xyx) * 0.1031);
    r += dot(r, r.yzx + 33.33);
    return fract((r.x + r.y) * r.z);
}
