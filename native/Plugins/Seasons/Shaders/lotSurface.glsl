// What the ambient, season and atmosphere passes share about the lot under a screen pixel: its position from the
// lot's depth and the terrain's, and the indoor mask. Include after the samplers depthMap, groundMap and indoorMap and
// ambientUniforms.glsl.

const float DEPTH_UNIT = 27.712813;  // 32 cos 30°: scene pixels along the view axis per unit of x + y

// The view-space position under a screen pixel, in scene pixels; w is 0 on the lot's depth, 0.5 on the terrain and
// 1 on the backdrop, which lies far behind.
vec4 positionAt(vec2 pixel) {
    vec2 scene = (pixel - ambient.view.xy) / ambient.view.z;
    float depth = texelFetch(depthMap, ivec2(pixel), 0).r;
    if (depth < 1.0) return vec4(scene, (0.9 - depth) / 0.003 * DEPTH_UNIT, 0.0);
    float ground = texelFetch(groundMap, ivec2(pixel), 0).r;
    if (ground < 1.0) return vec4(scene, ((0.9 - ground) / 0.003 + ambient.view.w) * DEPTH_UNIT, 0.5);
    return vec4(scene, -1.0e5, 1.0);
}

// The terrain's distance toward the camera under a screen pixel, or far behind where there is none.
float groundAt(vec2 pixel) {
    float ground = texelFetch(groundMap, ivec2(pixel), 0).r;
    return ground < 1.0 ? ((0.9 - ground) / 0.003 + ambient.view.w) * DEPTH_UNIT : -1.0e5;
}

// The indoor mask's byte for a camera tile in one of its bands, or 0 off the mask. Bands 0 and 1 hold the floors'
// rooms: bit 0 marks a window part, the rest is 0 outside and otherwise a code for the indoor room. Bands 2 and 3 hold
// the floors' altitudes.
int maskAt(ivec2 at, int band) {
    ivec2 size = textureSize(indoorMap, 0);
    int bandH = size.y / 10;
    if (at.x < 0 || at.y < 0 || at.x >= size.x || at.y >= bandH) return 0;
    return int(texelFetch(indoorMap, ivec2(at.x, at.y + band * bandH), 0).r * 255.0 + 0.5);
}

// The altitude of a story's floor over a camera tile, or the fallback where the tile has none.
float floorAt(ivec2 at, int row, float fallback) {
    int code = maskAt(at, row + 2);
    return code == 0 ? fallback : ambient.contact.w + float(code - 1) / 8.0;
}

// How far indoors a lot point is (0 outside, 1 inside), from the mask: the first floor's tiles, or the second's above
// it, filtered between tile centres. Points above the second floor are outside.
float indoors(vec3 lot) {
    vec2 cell = lot.xy + ambient.frame.w - 0.5;
    ivec2 base = ivec2(floor(cell));
    // Sharpened toward the tile edge, so a room's last half tile does not fade toward outside.
    vec2 f = clamp((fract(cell) - 0.5) / 0.2 + 0.5, 0.0, 1.0);
    float sum = 0.0;
    for (int i = 0; i < 4; i++) {
        float weight = ((i & 1) == 1 ? f.x : 1.0 - f.x) * ((i >> 1) == 1 ? f.y : 1.0 - f.y);
        ivec2 at = base + ivec2(i & 1, i >> 1);
        int gCode = maskAt(at, 2);
        int f2Code = maskAt(at, 3);
        float ground = gCode != 0 ? ambient.contact.w + float(gCode - 1) / 8.0
                     : f2Code != 0 ? ambient.contact.w + float(f2Code - 1) / 8.0 - STORY_HEIGHT
                     : ambient.contact.w;
        if (lot.z > ground + 2.0 * STORY_HEIGHT - 0.1) continue;
        int row = lot.z > ground + STORY_HEIGHT - 0.1 ? 1 : 0;
        if (maskAt(at, row) < 2) continue;
        // A diagonal wall leaves only one half of its tile indoors: the side of the diagonal toward that half.
        int part = maskAt(at, row + 4) & 7;
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
