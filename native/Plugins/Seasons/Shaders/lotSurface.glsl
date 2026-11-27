// What the ambient, season and atmosphere passes share about the lot under a screen pixel: its position from the
// lot's depth and the terrain's, and the indoor mask. Include after the samplers depthMap, groundMap and indoorMap and
// ambientUniforms.glsl.

const float DEPTH_UNIT = 27.712813;  // 32 cos 30°: scene pixels along the view axis per unit of x + y

vec4 positionAt(vec2 pixel) {
    ivec2 ip = clamp(ivec2(floor(pixel)), ivec2(0), max(ivec2(ambient.extent.xy) - 1, ivec2(0)));
    vec2 scene = (vec2(ip) + 0.5 - ambient.view.xy) / ambient.view.z;
    float depth = texelFetch(depthMap, ip, 0).r;
    if (depth < 1.0) return vec4(scene, (0.62 - depth) / 0.003 * DEPTH_UNIT, 0.0);
    float ground = texelFetch(groundMap, ip, 0).r;
    if (ground < 1.0) return vec4(scene, ((0.62 - ground) / 0.003 + ambient.view.w) * DEPTH_UNIT, 0.5);
    return vec4(scene, -1.0e5, 1.0);
}

float groundAt(vec2 pixel) {
    ivec2 ip = clamp(ivec2(floor(pixel)), ivec2(0), max(ivec2(ambient.extent.xy) - 1, ivec2(0)));
    float ground = texelFetch(groundMap, ip, 0).r;
    return ground < 1.0 ? ((0.62 - ground) / 0.003 + ambient.view.w) * DEPTH_UNIT : -1.0e5;
}

int indoorBandH(ivec2 size) {
    if (size.x <= 1) return max(1, size.y / 10);
    int orient = int(ambient.clouds.z + 0.5);
    int hTiles = (orient & 1) == 0 ? int(ambient.drift.w + 0.5) : int(ambient.drift.z + 0.5);
    int margin = int(ambient.frame.w + 0.5);
    return hTiles > 0 ? hTiles + 2 * margin : size.x;
}

int indoorStories() {
    ivec2 size = textureSize(indoorMap, 0);
    int bandH = indoorBandH(size);
    return max(1, size.y / max(1, 5 * bandH));
}

int maskAt(ivec2 at, int band) {
    ivec2 size = textureSize(indoorMap, 0);
    int bandH = indoorBandH(size);
    if (at.x < 0 || at.y < 0 || at.x >= size.x || at.y >= bandH || band < 0 || (band + 1) * bandH > size.y) return 0;
    return int(texelFetch(indoorMap, ivec2(at.x, at.y + band * bandH), 0).r * 255.0 + 0.5);
}

int maskCatFast(ivec2 at, int cat, int row, ivec2 size, int bandH, int stories) {
    if (row < 0 || row >= stories || at.x < 0 || at.y < 0 || at.x >= size.x || at.y >= bandH) return 0;
    int band = cat * stories + row;
    if (band < 0 || (band + 1) * bandH > size.y) return 0;
    return int(texelFetch(indoorMap, ivec2(at.x, at.y + band * bandH), 0).r * 255.0 + 0.5);
}

int maskCatAt(ivec2 at, int cat, int row) {
    ivec2 size = textureSize(indoorMap, 0);
    int bandH = indoorBandH(size);
    int stories = max(1, size.y / max(1, 5 * bandH));
    return maskCatFast(at, cat, row, size, bandH, stories);
}

float floorAt(ivec2 at, int row, float fallback) {
    int code = maskCatAt(at, 1, row);
    return code == 0 ? fallback : ambient.contact.w + float(row) * STORY_HEIGHT + float(code - 1) / 8.0;
}

float indoors(vec3 lot) {
    ivec2 mSize = textureSize(indoorMap, 0);
    int bandH = indoorBandH(mSize);
    int stories = max(1, mSize.y / max(1, 5 * bandH));
    vec2 cell = lot.xy + ambient.frame.w - 0.5;
    ivec2 base = ivec2(floor(cell));
    vec2 f = clamp((fract(cell) - 0.5) / 0.2 + 0.5, 0.0, 1.0);
    float sum = 0.0;
    for (int i = 0; i < 4; i++) {
        float weight = ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
        ivec2 at = base + ivec2(i & 1, i >> 1);
        int baseCode = maskCatFast(at, 1, 0, mSize, bandH, stories);
        if (baseCode == 0) continue;
        float ground = ambient.contact.w + float(baseCode - 1) / 8.0;
        if (lot.z > ground + float(stories) * STORY_HEIGHT - 0.1) continue;
        int row = clamp(int(floor((lot.z - ground + 0.0999) / STORY_HEIGHT)), 0, stories - 1);
        if (maskCatFast(at, 0, row, mSize, bandH, stories) < 2) continue;
        int part = maskCatFast(at, 2, row, mSize, bandH, stories) & 7;
        if (part == 0) { sum += weight; continue; }
        vec2 toward = part == 1 ? vec2(1.0, -1.0) : part == 2 ? vec2(-1.0, 1.0) : part == 3 ? vec2(-1.0) : vec2(1.0);
        sum += weight * smoothstep(-0.06, 0.06, dot(lot.xy + ambient.frame.w - vec2(at) - 0.5, toward));
    }
    return sum;
}

// Smooth value noise over unit cells.
float valueNoise(vec2 q) {
    vec2 i = floor(q), f = fract(q);
    f = f * f * (3.0 - 2.0 * f);
    return mix(mix(hash12(i), hash12(i + vec2(1, 0)), f.x), mix(hash12(i + vec2(0, 1)), hash12(i + vec2(1, 1)), f.x), f.y);
}
// Camera tiles back to the lot's own tiles, so what is fixed to the lot (clouds, puddles) stays put when the camera turns.
vec2 lotSource(vec2 camera) {
    vec2 size = ambient.drift.zw;
    int orientation = int(ambient.clouds.z + 0.5);
    return orientation == 1 ? vec2(camera.y, size.y - camera.x)
         : orientation == 2 ? size - camera
         : orientation == 3 ? vec2(size.x - camera.y, camera.x) : camera;
}
