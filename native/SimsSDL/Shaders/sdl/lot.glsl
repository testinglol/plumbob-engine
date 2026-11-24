vec3 lotPoint(vec2 scene, float key, bool terrain, vec2 frame) {
    vec2 local = scene - frame;
    float h = terrain ? (16.0 * key - local.y) / 40.0 : (16.0 * key - local.y) / 52.8;
    float s = terrain ? key : key - 0.8 * h;
    float u = local.x / 32.0;
    return vec3(0.5 * (s + u), 0.5 * (s - u), h);
}

const float HEIGHT_RANGE = 64.0;
const float STORY_HEIGHT = 2.95;
