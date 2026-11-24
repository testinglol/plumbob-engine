// Shared uniforms for LotRenderer.encodeAmbient lighting and weather passes.
const int MAX_LAMPS = 16;
const int MAX_PRINTS = 16;
// The trail map (LotRenderer.trailTexels, trailMargin): texels per lot tile, and the tiles around the lot it covers.
const float TRAIL_TEXELS = 32.0;
const float TRAIL_MARGIN = 1.0;
layout(std140, set = 3, binding = 0) uniform Ambient {
    vec4 view;    // origin x, y (screen pixels), screen pixels per scene pixel, terrain depth offset (units of x + y)
    vec4 params;  // occlusion radius (scene pixels), occlusion strength, shadow strength, occluder thickness
    vec4 light;   // direction toward the sun in view space (unused here), shadow reach (tiles)
    vec4 extent;  // lot area in screen pixels: width, height; debug mode
    vec4 lamp;    // lamp count, lamp reach (scene pixels), lamp gain, light away from lamps
    vec4 contact; // contact shadow radius (scene pixels), strength, light added by sun through windows, the indoor
                  // mask's lowest floor altitude
    vec4 frame;   // scene x and y of camera tile (0, 0) at altitude 0, height map texels per tile, its margin (tiles)
    vec4 sunLot;  // direction toward the sun in camera tiles (x, y, altitude), shadow reach (tiles)
    vec4 clouds;  // cloud cover (0 clear to 1 overcast), how much sun a cloud takes, camera orientation, cloud height (tiles)
    vec4 drift;   // how far the clouds have blown (lot tiles, x and y), the lot's width and height (tiles)
    vec4 weather; // rain (0 to 1), how wet the ground is (0 to 1), seconds of running clock, night glow (0 day to 1 night)
    vec4 tone;    // warm sun and cool shade strength, rain slant (screen x per screen y), wind strength (0 to 1), day progress (0 sunrise..1 sunset, <0 unset)
    vec4 season;  // 0 as drawn, 1 autumn, 2 winter; how far into it (0 to 1); trail fill since the last frame; −1 to
                  // start the trail over
    vec4 lamps[MAX_LAMPS];  // scene x, y, distance toward the camera (units of x + y), signed intensity (negative = fire)
    vec4 prints[MAX_PRINTS];  // footprints to stamp: lot x, y (tiles), heading (radians), foot (±1 an adult's right or
                              // left shoe, ±0.75 a child's, ±2 a paw, 0 none)
    vec4 seasonExtra;         // x: botanical grass quality (0..1), y: spring bloom (0..1), z: snowfall (-1 rain, 0 auto, 1 snow), w: fireflies (0..1)
    vec4 seasonExtra2;        // x: hail (0..1), y: frost (0..1), z: thunder (0..1), w: reserved
    vec4 shadowView;          // whole-lot world shadow depth viewport: origin x, y, scale, active (>0.5)
    vec4 prevView;            // previous frame viewport: origin x, y, scale, frameIndex + 1 (0 = reset history)
} ambient;

const vec3 LAMP_COLOR = vec3(1.0, 0.82, 0.58);
const vec3 FIRE_COLOR = vec3(1.0, 0.34, 0.05);
const vec3 LUMA = vec3(0.2126, 0.7152, 0.0722);

// A lot point (camera tiles and altitude) on the scene, in scene pixels.
vec2 sceneOf(vec3 q) { return vec2(32.0 * (q.x - q.y), 16.0 * (q.x + q.y) - 40.0 * q.z) + ambient.frame.xy; }

float hash12(vec2 q) {
    vec3 r = fract(vec3(q.xyx) * 0.1031);
    r += dot(r, r.yzx + 33.33);
    return fract((r.x + r.y) * r.z);
}
