// Lot points from the lot camera's screen and depth, inverting the exporter's projection (NativeLotCamera): a point at
// camera tile (x, y) and altitude h (tile units; a story is 2.95) lands at scene x = 32 (x - y) + frame.x and
// scene y = 16 (x + y) - 40 h + frame.y, and its depth key (0.9 - depth) / 0.003 is x + y + 0.8 h on sprites and
// meshes but only x + y on the terrain, which draws its depth without the elevation.
vec3 lotPoint(vec2 scene, float key, bool terrain, vec2 frame) {
    vec2 local = scene - frame;
    float h = terrain ? (16.0 * key - local.y) / 40.0 : (16.0 * key - local.y) / 52.8;
    float s = terrain ? key : key - 0.8 * h;
    float u = local.x / 32.0;
    return vec3(0.5 * (s + u), 0.5 * (s - u), h);
}

// The lot's height map stores the highest point over each texel as depth 0.5 - h / HEIGHT_RANGE, cleared to 1 (none).
const float HEIGHT_RANGE = 128.0;
// One floor of a building, in tiles of altitude.
const float STORY_HEIGHT = 2.95;
