cbuffer Ambient : register(b0, space3)
{
    float4 ambient_view : packoffset(c0);
    float4 ambient_params : packoffset(c1);
    float4 ambient_light : packoffset(c2);
    float4 ambient_extent : packoffset(c3);
    float4 ambient_lamp : packoffset(c4);
    float4 ambient_contact : packoffset(c5);
    float4 ambient_frame : packoffset(c6);
    float4 ambient_sunLot : packoffset(c7);
    float4 ambient_clouds : packoffset(c8);
    float4 ambient_drift : packoffset(c9);
    float4 ambient_weather : packoffset(c10);
    float4 ambient_tone : packoffset(c11);
    float4 ambient_season : packoffset(c12);
    float4 ambient_lamps[16] : packoffset(c13);
    float4 ambient_prints[16] : packoffset(c29);
    float4 ambient_seasonExtra : packoffset(c45);
    float4 ambient_seasonExtra2 : packoffset(c46);
    float4 ambient_shadowView : packoffset(c47);
};

Texture2D<float4> depthMap : register(t0, space2);
SamplerState _depthMap_sampler : register(s0, space2);
Texture2D<float4> groundMap : register(t1, space2);
SamplerState _groundMap_sampler : register(s1, space2);
Texture2D<float4> indoorMap : register(t3, space2);
SamplerState _indoorMap_sampler : register(s3, space2);
Texture2D<float4> overheadMap : register(t6, space2);
SamplerState _overheadMap_sampler : register(s6, space2);
Texture2D<float4> heightMap : register(t2, space2);
SamplerState _heightMap_sampler : register(s2, space2);
Texture2D<float4> trailMap : register(t5, space2);
SamplerState _trailMap_sampler : register(s5, space2);
Texture2D<float4> source : register(t4, space2);
SamplerState _source_sampler : register(s4, space2);
Texture2D<float4> simMap : register(t7, space2);
SamplerState _simMap_sampler : register(s7, space2);
Texture2D<float4> spriteMap : register(t8, space2);
SamplerState _spriteMap_sampler : register(s8, space2);

static float4 gl_FragCoord;
static float4 color;
static float4 lift;

struct SPIRV_Cross_Input
{
    float4 gl_FragCoord : SV_Position;
};

struct SPIRV_Cross_Output
{
    float4 color : SV_Target0;
    float4 lift : SV_Target1;
};

uint2 spvTextureSize(Texture2D<float4> Tex, uint Level, out uint Param)
{
    uint2 ret;
    Tex.GetDimensions(Level, ret.x, ret.y, Param);
    return ret;
}

float4 positionAt(float2 pixel)
{
    float2 scene = (pixel - ambient_view.xy) / ambient_view.z.xx;
    float depth = depthMap.Load(int3(int2(pixel), 0)).x;
    if (depth < 1.0f)
    {
        return float4(scene, ((0.89999997615814208984375f - depth) / 0.0030000000260770320892333984375f) * 27.7128124237060546875f, 0.0f);
    }
    float ground = groundMap.Load(int3(int2(pixel), 0)).x;
    if (ground < 1.0f)
    {
        return float4(scene, (((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f, 0.5f);
    }
    return float4(scene, -100000.0f, 1.0f);
}

float3 lotPoint(float2 scene, float key, bool terrain, float2 frame)
{
    float2 local = scene - frame;
    float _176;
    if (terrain)
    {
        _176 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _176 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _176;
    float _200;
    if (terrain)
    {
        _200 = key;
    }
    else
    {
        _200 = key - (0.800000011920928955078125f * h);
    }
    float s = _200;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

int maskAt(int2 at, int band)
{
    uint _365_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _365_dummy_parameter));
    bool _368 = at.x < 0;
    bool _375;
    if (!_368)
    {
        _375 = at.y < 0;
    }
    else
    {
        _375 = _368;
    }
    bool _384;
    if (!_375)
    {
        _384 = at.x >= size.x;
    }
    else
    {
        _384 = _375;
    }
    bool _395;
    if (!_384)
    {
        _395 = at.y >= (size.y / 6);
    }
    else
    {
        _395 = _384;
    }
    if (_395)
    {
        return 0;
    }
    return int((indoorMap.Load(int3(int2(at.x, at.y + (band * (size.y / 6))), 0)).x * 255.0f) + 0.5f);
}

float indoors(float3 lot)
{
    float2 cell = (lot.xy + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.20000000298023223876953125f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _461;
    float _474;
    float _508;
    float _523;
    float2 _588;
    float2 _596;
    for (int i = 0; i < 4; i++)
    {
        if ((i & 1) == 1)
        {
            _461 = f.x;
        }
        else
        {
            _461 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _474 = f.y;
        }
        else
        {
            _474 = 1.0f - f.y;
        }
        float weight = _461 * _474;
        int2 at = base + int2(i & 1, i >> 1);
        int2 param = at;
        int param_1 = 2;
        int gCode = maskAt(param, param_1);
        int2 param_2 = at;
        int param_3 = 3;
        int f2Code = maskAt(param_2, param_3);
        if (gCode != 0)
        {
            _508 = ambient_contact.w + (float(gCode - 1) / 8.0f);
        }
        else
        {
            if (f2Code != 0)
            {
                _523 = (ambient_contact.w + (float(f2Code - 1) / 8.0f)) - 2.9500000476837158203125f;
            }
            else
            {
                _523 = ambient_contact.w;
            }
            _508 = _523;
        }
        float ground = _508;
        if (lot.z > ((ground + 5.900000095367431640625f) - 0.100000001490116119384765625f))
        {
            continue;
        }
        int row = int(lot.z > ((ground + 2.9500000476837158203125f) - 0.100000001490116119384765625f));
        int2 param_4 = at;
        int param_5 = row;
        if (maskAt(param_4, param_5) < 2)
        {
            continue;
        }
        int2 param_6 = at;
        int param_7 = row + 4;
        int part = maskAt(param_6, param_7) & 7;
        if (part == 0)
        {
            sum += weight;
            continue;
        }
        if (part == 1)
        {
            _588 = float2(1.0f, -1.0f);
        }
        else
        {
            if (part == 2)
            {
                _596 = float2(-1.0f, 1.0f);
            }
            else
            {
                bool2 _606 = (part == 3).xx;
                _596 = float2(_606.x ? (-1.0f).xx.x : 1.0f.xx.x, _606.y ? (-1.0f).xx.y : 1.0f.xx.y);
            }
            _588 = _596;
        }
        float2 toward = _588;
        sum += (weight * smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((lot.xy + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward)));
    }
    return sum;
}

float architecturalExposure(float3 _point)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _745;
    if (orientation == 1)
    {
        _745 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _759;
        if (orientation == 2)
        {
            _759 = size - _point.xy;
        }
        else
        {
            float2 _769;
            if (orientation == 3)
            {
                _769 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _769 = _point.xy;
            }
            _759 = _769;
        }
        _745 = _759;
    }
    float2 source_1 = _745;
    bool _789 = any(bool2(source_1.x < 0.0f.xx.x, source_1.y < 0.0f.xx.y));
    bool _797;
    if (!_789)
    {
        _797 = any(bool2(source_1.x >= size.x, source_1.y >= size.y));
    }
    else
    {
        _797 = _789;
    }
    if (_797)
    {
        return 1.0f;
    }
    uint _805_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _805_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source_1 * texelsPerTile));
    uint _819_dummy_parameter;
    int2 _819 = int2(spvTextureSize(overheadMap, uint(0), _819_dummy_parameter));
    if (any(bool2(at.x >= _819.x, at.y >= _819.y)))
    {
        return 1.0f;
    }
    int4 data = int4((overheadMap.Load(int3(at, 0)) * 255.0f) + 0.5f.xxxx);
    if (data.w == 0)
    {
        return 1.0f;
    }
    float base = float(((data.y * 256) + data.z) - 32768) / 256.0f;
    int story = int(floor(((_point.z - base) + 0.100000001490116119384765625f) / 2.9500000476837158203125f));
    if ((story < 0) || (story > 4))
    {
        return 1.0f;
    }
    return ((data.x & (1 << story)) != 0) ? 0.0f : 1.0f;
}

float2 lotSource(float2 camera)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _692;
    if (orientation == 1)
    {
        _692 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _706;
        if (orientation == 2)
        {
            _706 = size - camera;
        }
        else
        {
            float2 _715;
            if (orientation == 3)
            {
                _715 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _715 = camera;
            }
            _706 = _715;
        }
        _692 = _706;
    }
    return _692;
}

float topAt(float2 at)
{
    uint _1002_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _1002_dummy_parameter)));
    return (0.5f - heightMap.Sample(_heightMap_sampler, ((at + ambient_frame.w.xx) * ambient_frame.z) / gridSize).x) * 64.0f;
}

float3 srgbToLinear(float3 c)
{
    return lerp(c / 12.9200000762939453125f.xxx, pow((c + 0.054999999701976776123046875f.xxx) / 1.05499994754791259765625f.xxx, 2.400000095367431640625f.xxx), step(0.040449999272823333740234375f.xxx, c));
}

float3 recolor(float3 like, float3 hue)
{
    return hue * (dot(like, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)) / max(dot(hue, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)), 0.001000000047497451305389404296875f));
}

float hash12(float2 q)
{
    float3 r = frac(q.xyx * 0.103100001811981201171875f);
    r += dot(r, r.yzx + 33.3300018310546875f.xxx).xxx;
    return frac((r.x + r.y) * r.z);
}

float valueNoise(float2 q)
{
    float2 i = floor(q);
    float2 f = frac(q);
    f = (f * f) * (3.0f.xx - (f * 2.0f));
    float2 param = i;
    float2 param_1 = i + float2(1.0f, 0.0f);
    float2 param_2 = i + float2(0.0f, 1.0f);
    float2 param_3 = i + 1.0f.xx;
    return lerp(lerp(hash12(param), hash12(param_1), f.x), lerp(hash12(param_2), hash12(param_3), f.x), f.y);
}

float terrainBaseAt(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _893;
    if (orientation == 1)
    {
        _893 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _907;
        if (orientation == 2)
        {
            _907 = size - _point;
        }
        else
        {
            float2 _916;
            if (orientation == 3)
            {
                _916 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _916 = _point;
            }
            _907 = _916;
        }
        _893 = _907;
    }
    float2 source_1 = _893;
    bool _934 = any(bool2(source_1.x < 0.0f.xx.x, source_1.y < 0.0f.xx.y));
    bool _942;
    if (!_934)
    {
        _942 = any(bool2(source_1.x >= size.x, source_1.y >= size.y));
    }
    else
    {
        _942 = _934;
    }
    if (_942)
    {
        return fallback;
    }
    uint _950_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _950_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source_1 * texelsPerTile));
    uint _964_dummy_parameter;
    int2 _964 = int2(spvTextureSize(overheadMap, uint(0), _964_dummy_parameter));
    if (any(bool2(at.x >= _964.x, at.y >= _964.y)))
    {
        return fallback;
    }
    int4 data = int4((overheadMap.Load(int3(at, 0)) * 255.0f) + 0.5f.xxxx);
    if (data.w == 0)
    {
        return fallback;
    }
    return float(((data.y * 256) + data.z) - 32768) / 256.0f;
}

float4 floraAt(float2 at, inout float speciesLumRef)
{
    uint _1119_dummy_parameter;
    int2 size = int2(spvTextureSize(trailMap, uint(0), _1119_dummy_parameter));
    if (size.x < 4)
    {
        speciesLumRef = 0.0f;
        return 0.0f.xxxx;
    }
    float2 param = at;
    float2 texel = ((lotSource(param) + 1.0f.xx) * 32.0f) - 0.5f.xx;
    int2 base = int2(floor(texel));
    float2 f = texel - float2(base);
    float keepGreen = 0.0f;
    float drop = 0.0f;
    float hueSum = 0.0f;
    float lumSum = 0.0f;
    float hueW = 0.0f;
    float _1174;
    float _1187;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(base + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        if ((i & 1) == 1)
        {
            _1174 = f.x;
        }
        else
        {
            _1174 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1187 = f.y;
        }
        else
        {
            _1187 = 1.0f - f.y;
        }
        float w = _1174 * _1187;
        float4 tap = trailMap.Load(int3(c, 0));
        keepGreen += (tap.x * w);
        drop += (tap.y * w);
        if (tap.z > 0.039999999105930328369140625f)
        {
            hueSum += (tap.z * w);
            lumSum += (tap.w * w);
            hueW += w;
        }
    }
    float _1243;
    if (hueW > 9.9999997473787516355514526367188e-05f)
    {
        _1243 = hueSum / hueW;
    }
    else
    {
        _1243 = 0.0f;
    }
    float hue = _1243;
    float _1253;
    if (hueW > 9.9999997473787516355514526367188e-05f)
    {
        _1253 = lerp(0.0199999995529651641845703125f, 0.14000000059604644775390625f, clamp(((lumSum / hueW) - 0.37999999523162841796875f) / 0.23999999463558197021484375f, 0.0f, 1.0f));
    }
    else
    {
        _1253 = 0.0f;
    }
    speciesLumRef = _1253;
    return float4(keepGreen, drop, hue, hueW);
}

float3 makinMagicTreeSrgb(float sunlitT, float speciesHue)
{
    float s = clamp(sunlitT, 0.0f, 1.0f);
    float3 g0 = float3(0.352999985218048095703125f, 0.259000003337860107421875f, 0.086000002920627593994140625f);
    float3 g1 = float3(0.579999983310699462890625f, 0.4550000131130218505859375f, 0.1410000026226043701171875f);
    float3 g2 = float3(0.800000011920928955078125f, 0.579999983310699462890625f, 0.17299999296665191650390625f);
    float3 g3 = float3(0.921999990940093994140625f, 0.70599997043609619140625f, 0.203999996185302734375f);
    float3 g4 = float3(0.984000027179718017578125f, 0.768999993801116943359375f, 0.23499999940395355224609375f);
    float3 _2320;
    if (s < 0.2599999904632568359375f)
    {
        _2320 = lerp(g0, g1, (s / 0.2599999904632568359375f).xxx);
    }
    else
    {
        float3 _2333;
        if (s < 0.540000021457672119140625f)
        {
            _2333 = lerp(g1, g2, ((s - 0.2599999904632568359375f) / 0.2800000011920928955078125f).xxx);
        }
        else
        {
            float3 _2346;
            if (s < 0.7799999713897705078125f)
            {
                _2346 = lerp(g2, g3, ((s - 0.540000021457672119140625f) / 0.23999999463558197021484375f).xxx);
            }
            else
            {
                _2346 = lerp(g3, g4, ((s - 0.7799999713897705078125f) / 0.2199999988079071044921875f).xxx);
            }
            _2333 = _2346;
        }
        _2320 = _2333;
    }
    float3 goldColor = _2320;
    float3 o0 = float3(0.3449999988079071044921875f, 0.203999996185302734375f, 0.0390000008046627044677734375f);
    float3 o1 = float3(0.62000000476837158203125f, 0.3059999942779541015625f, 0.054999999701976776123046875f);
    float3 o2 = float3(0.862999975681304931640625f, 0.4709999859333038330078125f, 0.10999999940395355224609375f);
    float3 o3 = float3(0.972999989986419677734375f, 0.62000000476837158203125f, 0.17299999296665191650390625f);
    float3 o4 = float3(0.984000027179718017578125f, 0.7530000209808349609375f, 0.2269999980926513671875f);
    float3 _2389;
    if (s < 0.2599999904632568359375f)
    {
        _2389 = lerp(o0, o1, (s / 0.2599999904632568359375f).xxx);
    }
    else
    {
        float3 _2401;
        if (s < 0.540000021457672119140625f)
        {
            _2401 = lerp(o1, o2, ((s - 0.2599999904632568359375f) / 0.2800000011920928955078125f).xxx);
        }
        else
        {
            float3 _2414;
            if (s < 0.7799999713897705078125f)
            {
                _2414 = lerp(o2, o3, ((s - 0.540000021457672119140625f) / 0.23999999463558197021484375f).xxx);
            }
            else
            {
                _2414 = lerp(o3, o4, ((s - 0.7799999713897705078125f) / 0.2199999988079071044921875f).xxx);
            }
            _2401 = _2414;
        }
        _2389 = _2401;
    }
    float3 orangeColor = _2389;
    return lerp(goldColor, orangeColor, clamp(speciesHue, 0.0f, 1.0f).xxx);
}

float3 applyAutumnFoliage(float3 col, float3 here, float2 lot, float amount, float outdoor, bool sim, bool mapped, bool hasLiveFloraMap)
{
    float lum = dot(col, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float denom = max(col.y, 0.00200000009499490261077880859375f);
    float blueDrop = (col.y - col.z) / denom;
    float greenVsRed = (col.y - col.x) / denom;
    float foliageGreen = smoothstep(0.319999992847442626953125f, 0.540000021457672119140625f, blueDrop) * smoothstep(-0.180000007152557373046875f, 0.0599999986588954925537109375f, greenVsRed);
    float keepGreen = 0.0f;
    float explicitDeciduous = 0.0f;
    float explicitShrub = 0.0f;
    float stampedLumRef = 0.0f;
    float2 param = (lot * 0.23999999463558197021484375f) + 7.30000019073486328125f.xx;
    float speciesHue = 0.1599999964237213134765625f + (0.579999983310699462890625f * valueNoise(param));
    float _3063;
    if (mapped)
    {
        float2 param_1 = here.xy;
        float param_2 = here.z;
        _3063 = here.z - terrainBaseAt(param_1, param_2);
    }
    else
    {
        _3063 = here.z;
    }
    float relZ = _3063;
    if (hasLiveFloraMap)
    {
        float2 param_3 = here.xy;
        float param_4;
        float4 _3088 = floraAt(param_3, param_4);
        stampedLumRef = param_4;
        float4 flora = _3088;
        float lowBlock = smoothstep(0.1599999964237213134765625f, 0.4000000059604644775390625f, flora.x);
        float tallBlock = smoothstep(0.680000007152557373046875f, 0.87999999523162841796875f, flora.x);
        keepGreen = lerp(lowBlock, tallBlock, smoothstep(1.2999999523162841796875f, 1.7000000476837158203125f, relZ));
        explicitDeciduous = clamp(flora.w * 2.5f, 0.0f, 1.0f);
        explicitShrub = explicitDeciduous * (1.0f - smoothstep(0.0199999995529651641845703125f, 0.119999997317790985107421875f, flora.y));
        speciesHue = lerp(speciesHue, flora.z, explicitDeciduous);
    }
    float isDeciduous = (1.0f - keepGreen) * lerp(smoothstep(0.14000000059604644775390625f, 0.319999992847442626953125f, relZ), 1.0f, explicitShrub);
    float isCanopy = smoothstep(0.64999997615814208984375f, 1.35000002384185791015625f, relZ);
    float defaultLumRef = lerp(0.075999997556209564208984375f, 0.03599999845027923583984375f, isCanopy);
    float _3142;
    if (hasLiveFloraMap && (stampedLumRef > 0.004999999888241291046142578125f))
    {
        _3142 = lerp(defaultLumRef, stampedLumRef, explicitDeciduous);
    }
    else
    {
        _3142 = defaultLumRef;
    }
    float lumRef = _3142;
    float u = lum / max(lumRef, 0.017999999225139617919921875f);
    float sunlit = smoothstep(0.3499999940395355224609375f, 2.2000000476837158203125f, u);
    float2 param_5 = ((lot * 5.5f) + float2(here.z * 3.099999904632568359375f, (-here.z) * 2.400000095367431640625f)) + 19.1000003814697265625f.xx;
    float leafDetail = valueNoise(param_5);
    float sunlitT = clamp(((0.180000007152557373046875f + (0.7400000095367431640625f * sunlit)) + (0.07999999821186065673828125f * leafDetail)) + (0.0500000007450580596923828125f * (amount - 0.5f)), 0.0f, 1.0f);
    float turned = (((sim ? 0.0f : foliageGreen) * isDeciduous) * outdoor) * smoothstep(0.039999999105930328369140625f + (0.0599999986588954925537109375f * (1.0f - sunlit)), 0.2199999988079071044921875f + (0.07999999821186065673828125f * (1.0f - sunlit)), amount);
    if (turned <= 0.004999999888241291046142578125f)
    {
        return col;
    }
    float param_6 = sunlitT;
    float param_7 = speciesHue;
    float3 param_8 = makinMagicTreeSrgb(param_6, param_7);
    float3 hueLin = srgbToLinear(param_8);
    float hueLum = max(dot(hueLin, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)), 0.039999999105930328369140625f);
    float base50 = lerp(0.189999997615814208984375f, 0.2199999988079071044921875f, isCanopy);
    float cap = lerp(0.519999980926513671875f, 0.60000002384185791015625f, isCanopy);
    float rawLum = base50 * pow(max(u, 0.0f), 0.959999978542327880859375f);
    float ratio = rawLum / cap;
    float targetLum = rawLum / pow(1.0f + ((ratio * ratio) * ratio), 0.3333333432674407958984375f);
    float3 turnedColor = hueLin * (targetLum / hueLum);
    float peak = max(turnedColor.x, max(turnedColor.y, turnedColor.z));
    if (peak > 1.0f)
    {
        turnedColor = min(turnedColor, 1.0f.xxx);
        float curLum = dot(turnedColor, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
        if (curLum < targetLum)
        {
            float need = min(targetLum - curLum, 0.100000001490116119384765625f);
            turnedColor.y = min(0.62000000476837158203125f, turnedColor.y + (need / 0.715200006961822509765625f));
        }
    }
    float blend = lerp(0.920000016689300537109375f, 0.9900000095367431640625f, sunlit);
    return lerp(col, turnedColor, (turned * blend).xxx);
}

float pavedAt(inout float2 q)
{
    float2 param = q;
    float2 sourcePoint = lotSource(param);
    bool _1283 = any(bool2(sourcePoint.x < 1.0f.xx.x, sourcePoint.y < 1.0f.xx.y));
    bool _1295;
    if (!_1283)
    {
        float2 _1292 = ambient_drift.zw - 1.0f.xx;
        _1295 = any(bool2(sourcePoint.x > _1292.x, sourcePoint.y > _1292.y));
    }
    else
    {
        _1295 = _1283;
    }
    bool scenery = _1295;
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    if ((orientation == 1) || (orientation == 3))
    {
        size = size.yx;
    }
    float2 edge = clamp(q, 1.5f.xx, size - 1.5f.xx);
    int2 inward = int2(sign(edge - q));
    float2 beyond = abs(edge - q);
    int reach = min(12, int(ceil(max(beyond.x, beyond.y) - 0.5f)));
    q = edge;
    float2 cell = (q + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.4000000059604644775390625f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _1454;
    float _1467;
    float2 _1488;
    float2 _1494;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 2;
        bool _1390 = maskAt(param_1, param_2) == 0;
        bool _1399;
        if (!_1390)
        {
            int2 param_3 = at;
            int param_4 = 0;
            _1399 = maskAt(param_3, param_4) >= 2;
        }
        else
        {
            _1399 = _1390;
        }
        if (_1399)
        {
            continue;
        }
        int2 param_5 = at;
        int param_6 = 4;
        int f4 = maskAt(param_5, param_6);
        if ((f4 & 128) != 0)
        {
            continue;
        }
        if (scenery)
        {
            bool street = true;
            for (int k = 0; (k < reach) && street; k++)
            {
                int2 param_7 = at + (inward * k.xx);
                int param_8 = 4;
                street = (maskAt(param_7, param_8) & 64) != 0;
            }
            if (!street)
            {
                continue;
            }
        }
        if ((i & 1) == 1)
        {
            _1454 = f.x;
        }
        else
        {
            _1454 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1467 = f.y;
        }
        else
        {
            _1467 = 1.0f - f.y;
        }
        float weight = _1454 * _1467;
        int part = f4 & 7;
        if (part != 0)
        {
            if (part == 1)
            {
                _1488 = float2(1.0f, -1.0f);
            }
            else
            {
                if (part == 2)
                {
                    _1494 = float2(-1.0f, 1.0f);
                }
                else
                {
                    bool2 _1500 = (part == 3).xx;
                    _1494 = float2(_1500.x ? (-1.0f).xx.x : 1.0f.xx.x, _1500.y ? (-1.0f).xx.y : 1.0f.xx.y);
                }
                _1488 = _1494;
            }
            float2 toward = _1488;
            weight *= smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((q + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward));
        }
        sum += weight;
    }
    return sum;
}

float cementAt(float2 q)
{
    float2 param = q;
    float2 sourcePoint = lotSource(param);
    bool _1534 = any(bool2(sourcePoint.x < 0.5f.xx.x, sourcePoint.y < 0.5f.xx.y));
    bool _1546;
    if (!_1534)
    {
        float2 _1543 = ambient_drift.zw - 0.5f.xx;
        _1546 = any(bool2(sourcePoint.x > _1543.x, sourcePoint.y > _1543.y));
    }
    else
    {
        _1546 = _1534;
    }
    if (_1546)
    {
        return 0.0f;
    }
    float2 cell = (q + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.4000000059604644775390625f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _1620;
    float _1633;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 2;
        bool _1595 = maskAt(param_1, param_2) == 0;
        bool _1604;
        if (!_1595)
        {
            int2 param_3 = at;
            int param_4 = 0;
            _1604 = maskAt(param_3, param_4) >= 2;
        }
        else
        {
            _1604 = _1595;
        }
        if (_1604)
        {
            continue;
        }
        int2 param_5 = at;
        int param_6 = 4;
        if ((maskAt(param_5, param_6) & 128) == 0)
        {
            continue;
        }
        if ((i & 1) == 1)
        {
            _1620 = f.x;
        }
        else
        {
            _1620 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1633 = f.y;
        }
        else
        {
            _1633 = 1.0f - f.y;
        }
        sum += (_1620 * _1633);
    }
    return sum;
}

float dirtField(float2 l)
{
    float2 param = (l * 0.550000011920928955078125f) + 4.30000019073486328125f.xx;
    float2 param_1 = (l * 0.550000011920928955078125f) + 19.700000762939453125f.xx;
    float2 w = float2(valueNoise(param), valueNoise(param_1)) - 0.5f.xx;
    float2 param_2 = ((l + (w * 1.39999997615814208984375f)) * 0.300000011920928955078125f) + 2.099999904632568359375f.xx;
    float2 param_3 = (l * 0.949999988079071044921875f) + 13.69999980926513671875f.xx;
    float2 param_4 = (l * 2.7999999523162841796875f) + 27.299999237060546875f.xx;
    return ((valueNoise(param_2) * 0.550000011920928955078125f) + (valueNoise(param_3) * 0.300000011920928955078125f)) + (valueNoise(param_4) * 0.1500000059604644775390625f);
}

float peakRiseAt(float2 q, float base)
{
    uint _2063_dummy_parameter;
    int2 size = int2(spvTextureSize(heightMap, uint(0), _2063_dummy_parameter));
    float2 t = ((q + ambient_frame.w.xx) * ambient_frame.z) - 0.5f.xx;
    int2 b = int2(floor(t));
    float peak = 0.0f;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(b + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        peak = max(peak, ((0.5f - heightMap.Load(int3(c, 0)).x) * 64.0f) - base);
    }
    return peak;
}

float treeCrownAt(float2 q, float baseZ)
{
    float2 param = q;
    float param_1 = baseZ;
    float peak = peakRiseAt(param, param_1);
    if (peak <= 2.0499999523162841796875f)
    {
        return 0.0f;
    }
    float2 param_2 = q + float2(0.3499999940395355224609375f, 0.0f);
    float param_3 = baseZ;
    float2 param_4 = q - float2(0.3499999940395355224609375f, 0.0f);
    float param_5 = baseZ;
    float2 param_6 = q + float2(0.0f, 0.3499999940395355224609375f);
    float param_7 = baseZ;
    float2 param_8 = q - float2(0.0f, 0.3499999940395355224609375f);
    float param_9 = baseZ;
    float crownSpan = ((step(1.64999997615814208984375f, peakRiseAt(param_2, param_3)) + step(1.64999997615814208984375f, peakRiseAt(param_4, param_5))) + step(1.64999997615814208984375f, peakRiseAt(param_6, param_7))) + step(1.64999997615814208984375f, peakRiseAt(param_8, param_9));
    if (crownSpan < 2.0f)
    {
        return 0.0f;
    }
    float3 p = float3(q, baseZ + 0.100000001490116119384765625f);
    float3 param_10 = p;
    bool _2179 = indoors(param_10) > 0.0500000007450580596923828125f;
    bool _2187;
    if (!_2179)
    {
        float3 param_11 = p;
        _2187 = architecturalExposure(param_11) < 0.949999988079071044921875f;
    }
    else
    {
        _2187 = _2179;
    }
    if (_2187)
    {
        return 0.0f;
    }
    for (int i = 0; i < 8; i++)
    {
        float a = float(i) * 0.785398185253143310546875f;
        float2 dir = float2(cos(a), sin(a));
        bool connectedHigh = true;
        for (int k = 1; k <= 3; k++)
        {
            float2 nxy = q + (dir * (0.85000002384185791015625f * float(k)));
            float3 np = float3(nxy, baseZ + 0.100000001490116119384765625f);
            bool _2234 = k == 1;
            bool _2249;
            if (_2234)
            {
                float3 param_12 = np;
                bool _2240 = indoors(param_12) > 0.0500000007450580596923828125f;
                bool _2248;
                if (!_2240)
                {
                    float3 param_13 = np;
                    _2248 = architecturalExposure(param_13) < 0.949999988079071044921875f;
                }
                else
                {
                    _2248 = _2240;
                }
                _2249 = _2248;
            }
            else
            {
                _2249 = _2234;
            }
            if (_2249)
            {
                return 0.0f;
            }
            float2 param_14 = nxy;
            if ((topAt(param_14) - baseZ) <= 1.35000002384185791015625f)
            {
                connectedHigh = false;
                break;
            }
            bool _2278;
            if (connectedHigh)
            {
                float3 param_15 = np;
                bool _2269 = indoors(param_15) > 0.0500000007450580596923828125f;
                bool _2277;
                if (!_2269)
                {
                    float3 param_16 = np;
                    _2277 = architecturalExposure(param_16) < 0.949999988079071044921875f;
                }
                else
                {
                    _2277 = _2269;
                }
                _2278 = _2277;
            }
            else
            {
                _2278 = connectedHigh;
            }
            if (_2278)
            {
                return 0.0f;
            }
        }
    }
    return smoothstep(2.0499999523162841796875f, 2.650000095367431640625f, peak);
}

float4 fallenLeafLayer(float2 lot, float freq, float angleRad, float seed, float density, float minSize, float maxSize, float lotPixelScale)
{
    if (density <= 0.004999999888241291046142578125f)
    {
        return 0.0f.xxxx;
    }
    float ca = cos(angleRad);
    float sa = sin(angleRad);
    float2 g = mul(lot * freq, float2x2(float2(ca, sa), float2(-sa, ca)));
    float2 base = floor(g - 0.5f.xx);
    float bestOrder = -1.0f;
    float bestMask = 0.0f;
    float bestShade = 1.0f;
    float bestHue = 0.5f;
    float shadowAcc = 0.0f;
    for (int m = 0; m < 4; m++)
    {
        float2 cell = base + float2(float(m & 1), float(m >> 1));
        float2 param = cell + seed.xx;
        float h1 = hash12(param);
        if (h1 > density)
        {
            continue;
        }
        float2 param_1 = (cell + seed.xx) + float2(17.299999237060546875f, 9.1000003814697265625f);
        float h2 = hash12(param_1);
        float2 param_2 = (cell + seed.xx) + float2(43.700000762939453125f, 29.3999996185302734375f);
        float h3 = hash12(param_2);
        float2 param_3 = (cell + seed.xx) + float2(71.90000152587890625f, 53.200000762939453125f);
        float h4 = hash12(param_3);
        float2 center = (cell + 0.2199999988079071044921875f.xx) + (float2(frac(h1 * 13.69999980926513671875f), frac(h2 * 19.299999237060546875f)) * 0.560000002384185791015625f);
        float2 d = g - center;
        float size = lerp(minSize, maxSize, h3);
        if (dot(d, d) > ((size * size) * 1.440000057220458984375f))
        {
            continue;
        }
        float la = h4 * 6.283185482025146484375f;
        float lc = cos(la);
        float ls = sin(la);
        float2 local = float2((d.x * lc) + (d.y * ls), ((-d.x) * ls) + (d.y * lc)) / size.xx;
        float bend = (frac(h3 * 23.1000003814697265625f) - 0.5f) * 0.36000001430511474609375f;
        float ly = local.y + ((bend * local.x) * local.x);
        float ruffle = 1.0f + (0.0599999986588954925537109375f * sin((local.x * 7.0f) + (h4 * 6.283185482025146484375f)));
        float pinch = max(0.319999992847442626953125f, 1.0f - (0.4199999868869781494140625f * clamp(local.x * local.x, 0.0f, 1.0f))) * ruffle;
        float shape = length(float2(local.x / 0.85000002384185791015625f, ly / (0.4600000083446502685546875f * pinch)));
        float aa = clamp(((lotPixelScale * freq) * 0.85000002384185791015625f) / max(size, 0.119999997317790985107421875f), 0.100000001490116119384765625f, 0.4799999892711639404296875f);
        float alpha = 1.0f - smoothstep(1.0f - aa, 1.0f + aa, shape);
        float2 sOff = mul(0.100000001490116119384765625f.xx * size, float2x2(float2(ca, sa), float2(-sa, ca)));
        float2 sd = d - sOff;
        float2 sLocal = float2((sd.x * lc) + (sd.y * ls), ((-sd.x) * ls) + (sd.y * lc)) / (size * 1.12000000476837158203125f).xx;
        float sly = sLocal.y + ((bend * sLocal.x) * sLocal.x);
        float sPinch = max(0.319999992847442626953125f, 1.0f - (0.4199999868869781494140625f * clamp(sLocal.x * sLocal.x, 0.0f, 1.0f)));
        float sShape = length(float2(sLocal.x / 0.85000002384185791015625f, sly / (0.4799999892711639404296875f * sPinch)));
        float sAlpha = (1.0f - smoothstep(0.64999997615814208984375f, 1.25f, sShape)) * 0.64999997615814208984375f;
        shadowAcc = max(shadowAcc, sAlpha);
        if (alpha > 0.00999999977648258209228515625f)
        {
            float order = h2 + (0.00999999977648258209228515625f * float(m));
            if (order > bestOrder)
            {
                bestOrder = order;
                bestMask = alpha;
                bestShade = 0.86000001430511474609375f + ((0.2800000011920928955078125f * frac((h1 * 31.700000762939453125f) + (h3 * 7.30000019073486328125f))) * smoothstep(-0.89999997615814208984375f, 0.699999988079071044921875f, -local.y));
                bestHue = frac((h4 * 17.299999237060546875f) + (h2 * 5.900000095367431640625f));
            }
        }
    }
    return float4(bestMask, shadowAcc, bestShade, bestHue);
}

float3 fallenLeafColorSrgb(float hueSeed, float speciesHue)
{
    float s = clamp(hueSeed, 0.0f, 1.0f);
    float3 gl0 = float3(0.925000011920928955078125f, 0.862999975681304931640625f, 0.208000004291534423828125f);
    float3 gl1 = float3(0.88999998569488525390625f, 0.698000013828277587890625f, 0.16099999845027923583984375f);
    float3 gl2 = float3(0.834999978542327880859375f, 0.607999980449676513671875f, 0.17299999296665191650390625f);
    float3 gl3 = float3(0.675000011920928955078125f, 0.4550000131130218505859375f, 0.1410000026226043701171875f);
    float3 _2466;
    if (s < 0.3400000035762786865234375f)
    {
        _2466 = lerp(gl0, gl1, (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _2479;
        if (s < 0.699999988079071044921875f)
        {
            _2479 = lerp(gl1, gl2, ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _2479 = lerp(gl2, gl3, ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _2466 = _2479;
    }
    float3 goldLeaf = _2466;
    float3 ol0 = float3(0.9409999847412109375f, 0.579999983310699462890625f, 0.1410000026226043701171875f);
    float3 ol1 = float3(0.910000026226043701171875f, 0.3449999988079071044921875f, 0.09399999678134918212890625f);
    float3 ol2 = float3(0.834999978542327880859375f, 0.607999980449676513671875f, 0.17299999296665191650390625f);
    float3 ol3 = float3(0.53299999237060546875f, 0.2199999988079071044921875f, 0.09399999678134918212890625f);
    float3 _2514;
    if (s < 0.3400000035762786865234375f)
    {
        _2514 = lerp(ol0, ol1, (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _2526;
        if (s < 0.699999988079071044921875f)
        {
            _2526 = lerp(ol1, ol2, ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _2526 = lerp(ol2, ol3, ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _2514 = _2526;
    }
    float3 orangeLeaf = _2514;
    return lerp(goldLeaf, orangeLeaf, clamp(speciesHue, 0.0f, 1.0f).xxx);
}

float3 applyAutumnGround(float3 col, float3 hereG, float2 gLot, float gPixelScale, float amount, float gOutdoor, float gSkyExposed, bool mapped, bool hasLiveFloraMap, bool leavesOnlyOnTurf)
{
    float gLum = dot(col, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float gGreen = smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, (col.y - max(col.x, col.z)) / max(col.y, 0.039999999105930328369140625f));
    float3 outCol = col;
    float _3338;
    if (mapped)
    {
        float2 param = hereG.xy;
        float _3344 = pavedAt(param);
        _3338 = _3344;
    }
    else
    {
        _3338 = 0.0f;
    }
    float autPaved = _3338;
    float _3349;
    if (mapped)
    {
        float2 param_1 = hereG.xy;
        _3349 = cementAt(param_1);
    }
    else
    {
        _3349 = 0.0f;
    }
    float autCement = _3349;
    float onTurf = (gGreen * (1.0f - (0.949999988079071044921875f * autPaved))) * (1.0f - autCement);
    if (onTurf > 0.00999999977648258209228515625f)
    {
        float bladeShade = smoothstep(0.02500000037252902984619140625f, 0.12999999523162841796875f, gLum);
        float3 param_2 = float3(0.40799999237060546875f, 0.23499999940395355224609375f, 0.125f);
        float3 param_3 = float3(0.564999997615814208984375f, 0.477999985218048095703125f, 0.2199999988079071044921875f);
        float3 mmGrass = lerp(srgbToLinear(param_2), srgbToLinear(param_3), bladeShade.xxx);
        float2 param_4 = gLot;
        float mulchPatch = smoothstep(0.519999980926513671875f, 0.839999973773956298828125f, dirtField(param_4)) * amount;
        float3 param_5 = float3(0.45899999141693115234375f, 0.2939999997615814208984375f, 0.157000005245208740234375f);
        float3 mmMulch = srgbToLinear(param_5) * clamp(gLum / 0.0949999988079071044921875f, 0.449999988079071044921875f, 1.25f);
        float3 param_6 = col;
        float3 param_7 = mmGrass;
        float3 autumnTurf = lerp(recolor(param_6, param_7), mmMulch, (mulchPatch * 0.4199999868869781494140625f).xxx);
        outCol = lerp(outCol, autumnTurf, (((onTurf * gOutdoor) * gSkyExposed) * clamp(0.7200000286102294921875f * amount, 0.0f, 0.7799999713897705078125f)).xxx);
    }
    float notWater = 1.0f - smoothstep(0.00999999977648258209228515625f, 0.0500000007450580596923828125f, col.z - max(col.x, col.y));
    float leafGround = ((1.0f - (0.949999988079071044921875f * autPaved)) * (1.0f - (0.89999997615814208984375f * autCement))) * notWater;
    if (leavesOnlyOnTurf)
    {
        leafGround *= smoothstep(0.0199999995529651641845703125f, 0.14000000059604644775390625f, onTurf);
    }
    if (((mapped && (leafGround > 0.0500000007450580596923828125f)) && (gOutdoor > 0.00999999977648258209228515625f)) && (gSkyExposed > 0.00999999977648258209228515625f))
    {
        float innerCanopy = 0.0f;
        float outerCanopy = 0.0f;
        float treeHue = 0.3499999940395355224609375f;
        if (hasLiveFloraMap)
        {
            float unusedLumRef = 0.0f;
            float2 param_8 = hereG.xy;
            float param_9;
            float4 _3485 = floraAt(param_8, param_9);
            unusedLumRef = param_9;
            float4 flora = _3485;
            float2 param_10 = (gLot * 1.39999997615814208984375f) + 9.19999980926513671875f.xx;
            float2 param_11 = (gLot * 3.7999999523162841796875f) + 21.3999996185302734375f.xx;
            float edgeBreak = (((valueNoise(param_10) * 0.64999997615814208984375f) + (valueNoise(param_11) * 0.3499999940395355224609375f)) - 0.5f) * 0.37999999523162841796875f;
            float dropField = clamp(flora.y + (edgeBreak * smoothstep(0.0f, 0.449999988079071044921875f, flora.y)), 0.0f, 1.0f);
            innerCanopy = smoothstep(0.2599999904632568359375f, 0.800000011920928955078125f, dropField);
            outerCanopy = smoothstep(0.0199999995529651641845703125f, 0.540000021457672119140625f, dropField);
            float2 param_12 = (gLot * 0.23999999463558197021484375f) + 7.30000019073486328125f.xx;
            float defaultHue = 0.1599999964237213134765625f + (0.579999983310699462890625f * valueNoise(param_12));
            treeHue = lerp(defaultHue, flora.z, clamp(flora.w * 2.5f, 0.0f, 1.0f));
        }
        else
        {
            float2 param_13 = hereG.xy;
            float param_14 = hereG.z;
            float anyPeak = peakRiseAt(param_13, param_14);
            if (anyPeak <= 2.0499999523162841796875f)
            {
                for (int i = 0; i < 8; i++)
                {
                    float a = float(i) * 0.785398185253143310546875f;
                    float2 param_15 = hereG.xy + (float2(cos(a), sin(a)) * 1.2000000476837158203125f);
                    float param_16 = hereG.z;
                    anyPeak = max(anyPeak, peakRiseAt(param_15, param_16));
                    if (anyPeak > 2.0499999523162841796875f)
                    {
                        break;
                    }
                }
            }
            if (anyPeak > 2.0499999523162841796875f)
            {
                float2 param_17 = hereG.xy;
                float param_18 = hereG.z;
                innerCanopy = treeCrownAt(param_17, param_18);
                outerCanopy = innerCanopy * 0.7200000286102294921875f;
                for (int i_1 = 0; i_1 < 8; i_1++)
                {
                    float a_1 = float(i_1) * 0.785398185253143310546875f;
                    float2 dir = float2(cos(a_1), sin(a_1));
                    float2 param_19 = hereG.xy + (dir * 0.449999988079071044921875f);
                    float param_20 = hereG.z;
                    innerCanopy = max(innerCanopy, 0.939999997615814208984375f * treeCrownAt(param_19, param_20));
                    float2 param_21 = hereG.xy + (dir * 0.89999997615814208984375f);
                    float param_22 = hereG.z;
                    outerCanopy = max(outerCanopy, 0.560000002384185791015625f * treeCrownAt(param_21, param_22));
                }
                outerCanopy = max(outerCanopy, innerCanopy * 0.7200000286102294921875f);
                float2 param_23 = (gLot * 0.23999999463558197021484375f) + 7.30000019073486328125f.xx;
                treeHue = valueNoise(param_23);
            }
        }
        if (outerCanopy > 0.0199999995529651641845703125f)
        {
            float2 param_24 = (gLot * 2.2000000476837158203125f) + 3.7000000476837158203125f.xx;
            float2 param_25 = (gLot * 5.0f) + 11.30000019073486328125f.xx;
            float patchNoise = (valueNoise(param_24) * 0.64999997615814208984375f) + (valueNoise(param_25) * 0.3499999940395355224609375f);
            float baseLumScale = clamp(gLum / 0.100000001490116119384765625f, 0.550000011920928955078125f, 1.14999997615814208984375f) * 0.920000016689300537109375f;
            float leafWeight = (gOutdoor * gSkyExposed) * leafGround;
            float d0 = clamp(((innerCanopy * amount) * smoothstep(0.14000000059604644775390625f, 0.63999998569488525390625f, patchNoise + (0.4199999868869781494140625f * innerCanopy))) * 0.959999978542327880859375f, 0.0f, 0.959999978542327880859375f);
            float d1 = clamp(((max(innerCanopy * 0.87999999523162841796875f, outerCanopy * 0.62000000476837158203125f) * amount) * smoothstep(0.20000000298023223876953125f, 0.699999988079071044921875f, patchNoise + (0.319999992847442626953125f * outerCanopy))) * 0.86000001430511474609375f, 0.0f, 0.87999999523162841796875f);
            float d2 = clamp(((max(innerCanopy * 0.660000026226043701171875f, outerCanopy * 0.4199999868869781494140625f) * amount) * smoothstep(0.2599999904632568359375f, 0.7599999904632568359375f, patchNoise + (0.23999999463558197021484375f * outerCanopy))) * 0.680000007152557373046875f, 0.0f, 0.699999988079071044921875f);
            float2 param_26 = gLot;
            float param_27 = 7.400000095367431640625f;
            float param_28 = 0.0f;
            float param_29 = 3.099999904632568359375f;
            float param_30 = d0;
            float param_31 = 0.300000011920928955078125f;
            float param_32 = 0.4199999868869781494140625f;
            float param_33 = gPixelScale;
            float4 l0 = fallenLeafLayer(param_26, param_27, param_28, param_29, param_30, param_31, param_32, param_33);
            bool _3754 = l0.x > 0.004999999888241291046142578125f;
            bool _3761;
            if (!_3754)
            {
                _3761 = l0.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _3761 = _3754;
            }
            if (_3761)
            {
                outCol *= (1.0f - (((0.319999992847442626953125f * l0.y) * leafWeight) * (1.0f - l0.x)));
                float param_34 = l0.w;
                float param_35 = treeHue;
                float3 param_36 = fallenLeafColorSrgb(param_34, param_35);
                float3 c0 = ((srgbToLinear(param_36) * 0.7799999713897705078125f) * l0.z) * baseLumScale;
                outCol = lerp(outCol, c0, ((l0.x * leafWeight) * 0.939999997615814208984375f).xxx);
            }
            float2 param_37 = gLot;
            float param_38 = 9.3999996185302734375f;
            float param_39 = 0.670000016689300537109375f;
            float param_40 = 19.700000762939453125f;
            float param_41 = d1;
            float param_42 = 0.2800000011920928955078125f;
            float param_43 = 0.4000000059604644775390625f;
            float param_44 = gPixelScale;
            float4 l1 = fallenLeafLayer(param_37, param_38, param_39, param_40, param_41, param_42, param_43, param_44);
            bool _3817 = l1.x > 0.004999999888241291046142578125f;
            bool _3824;
            if (!_3817)
            {
                _3824 = l1.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _3824 = _3817;
            }
            if (_3824)
            {
                outCol *= (1.0f - (((0.300000011920928955078125f * l1.y) * leafWeight) * (1.0f - l1.x)));
                float param_45 = l1.w;
                float param_46 = treeHue;
                float3 param_47 = fallenLeafColorSrgb(param_45, param_46);
                float3 c1 = ((srgbToLinear(param_47) * 1.03999996185302734375f) * l1.z) * baseLumScale;
                outCol = lerp(outCol, c1, ((l1.x * leafWeight) * 0.939999997615814208984375f).xxx);
            }
            float2 param_48 = gLot;
            float param_49 = 11.6000003814697265625f;
            float param_50 = 1.309999942779541015625f;
            float param_51 = 41.299999237060546875f;
            float param_52 = d2;
            float param_53 = 0.2700000107288360595703125f;
            float param_54 = 0.37999999523162841796875f;
            float param_55 = gPixelScale;
            float4 l2 = fallenLeafLayer(param_48, param_49, param_50, param_51, param_52, param_53, param_54, param_55);
            bool _3883 = l2.x > 0.004999999888241291046142578125f;
            bool _3890;
            if (!_3883)
            {
                _3890 = l2.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _3890 = _3883;
            }
            if (_3890)
            {
                outCol *= (1.0f - (((0.2800000011920928955078125f * l2.y) * leafWeight) * (1.0f - l2.x)));
                float param_56 = l2.w;
                float param_57 = treeHue;
                float3 param_58 = fallenLeafColorSrgb(param_56, param_57);
                float3 c2 = ((srgbToLinear(param_58) * 1.17999994754791259765625f) * l2.z) * baseLumScale;
                outCol = lerp(outCol, c2, ((l2.x * leafWeight) * 0.939999997615814208984375f).xxx);
            }
        }
    }
    return outCol;
}

float snowCrust(float2 lq)
{
    float2 param = (lq * 3.599999904632568359375f) + 3.2000000476837158203125f.xx;
    float2 param_1 = (lq * 8.80000019073486328125f) + 17.3999996185302734375f.xx;
    return (valueNoise(param) * 0.64999997615814208984375f) + (valueNoise(param_1) * 0.3499999940395355224609375f);
}

float groundAt(float2 pixel)
{
    float ground = groundMap.Load(int3(int2(pixel), 0)).x;
    float _347;
    if (ground < 1.0f)
    {
        _347 = (((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f;
    }
    else
    {
        _347 = -100000.0f;
    }
    return _347;
}

float nearIndoorWall(float2 xy, float z, float radius)
{
    float w = 0.0f;
    float _2958;
    float _2968;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            _2958 = 1.0f;
        }
        else
        {
            _2958 = (i == 1) ? (-1.0f) : 0.0f;
        }
        if (i == 2)
        {
            _2968 = 1.0f;
        }
        else
        {
            _2968 = (i == 3) ? (-1.0f) : 0.0f;
        }
        float2 card = float2(_2958, _2968) * radius;
        float2 diag = float2((i < 2) ? 1.0f : (-1.0f), ((i & 1) == 1) ? 1.0f : (-1.0f)) * radius;
        float3 param = float3(xy + card, z);
        w = max(w, indoors(param));
        float3 param_1 = float3(xy + diag, z);
        w = max(w, indoors(param_1));
    }
    return w;
}

float wallBank(float2 q, float base)
{
    float2 param = q + float2(0.550000011920928955078125f, 0.0f);
    float2 param_1 = q - float2(0.550000011920928955078125f, 0.0f);
    float2 param_2 = q + float2(0.0f, 0.550000011920928955078125f);
    float2 param_3 = q - float2(0.0f, 0.550000011920928955078125f);
    float nearCheck = max(max(topAt(param), topAt(param_1)), max(topAt(param_2), topAt(param_3)));
    if (nearCheck <= (base + 0.25f))
    {
        return 0.0f;
    }
    float inner = 0.0f;
    float outer = 0.0f;
    for (int i = 0; i < 8; i++)
    {
        float a = float(i) * 0.785398185253143310546875f;
        float2 d = float2(cos(a), sin(a));
        float2 param_4 = q + (d * 0.2199999988079071044921875f);
        inner += smoothstep(0.3499999940395355224609375f, 1.35000002384185791015625f, topAt(param_4) - base);
        float2 param_5 = q + (d * 0.5f);
        outer += smoothstep(0.3499999940395355224609375f, 1.35000002384185791015625f, topAt(param_5) - base);
    }
    return clamp(((inner * 0.62000000476837158203125f) + (outer * 0.37999999523162841796875f)) / 8.0f, 0.0f, 1.0f);
}

float pressedAt(float2 at)
{
    uint _1026_dummy_parameter;
    int2 size = int2(spvTextureSize(trailMap, uint(0), _1026_dummy_parameter));
    if (size.x < 4)
    {
        return 0.0f;
    }
    float2 param = at;
    float2 texel = ((lotSource(param) + 1.0f.xx) * 32.0f) - 0.5f.xx;
    int2 base = int2(floor(texel));
    float2 f = texel - float2(base);
    float sum = 0.0f;
    float _1081;
    float _1095;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(base + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        if ((i & 1) == 1)
        {
            _1081 = f.x;
        }
        else
        {
            _1081 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1095 = f.y;
        }
        else
        {
            _1095 = 1.0f - f.y;
        }
        sum += ((trailMap.Load(int3(c, 0)).x * _1081) * _1095);
    }
    return smoothstep(0.3499999940395355224609375f, 0.64999997615814208984375f, sum);
}

float snowHeight(float2 q, float base, float full, float amount, float groundWear, float isVac)
{
    float3 p3 = float3(q, base + 0.100000001490116119384765625f);
    float3 param = p3;
    float outside = architecturalExposure(param);
    if (outside <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    float3 param_1 = p3;
    float inRoom = indoors(param_1);
    if (inRoom > 0.4799999892711639404296875f)
    {
        return 0.0f;
    }
    outside = min(1.0f - smoothstep(0.319999992847442626953125f, 0.4799999892711639404296875f, inRoom), outside);
    if (outside <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    float2 param_2 = q;
    float2 l = lotSource(param_2);
    float2 param_3 = q;
    float param_4 = base;
    float bank = wallBank(param_3, param_4);
    float2 param_5 = q;
    float overhead = smoothstep(1.2000000476837158203125f, 2.5f, max(0.0f, topAt(param_5) - base));
    float2 param_6 = l;
    float bare = dirtField(param_6);
    float snowCover = smoothstep(0.4199999868869781494140625f, 0.920000016689300537109375f, amount);
    float wearSuppress = lerp(1.0f - (0.85000002384185791015625f * snowCover), 1.0f, isVac);
    float thinSpot = (smoothstep(0.560000002384185791015625f, 0.86000001430511474609375f, bare) * (1.0f - (0.800000011920928955078125f * bank))) * lerp(1.0f - (0.85000002384185791015625f * snowCover), 0.25f, isVac);
    float wear = clamp(max(thinSpot * 0.550000011920928955078125f, (groundWear * 0.7799999713897705078125f) * wearSuppress) + (overhead * 0.2800000011920928955078125f), 0.0f, 0.87999999523162841796875f);
    float2 param_7 = l * 0.85000002384185791015625f;
    float2 param_8 = (l * 2.400000095367431640625f) + 5.0f.xx;
    float2 param_9 = (l * 6.5f) + 11.0f.xx;
    float drift = ((valueNoise(param_7) * 0.449999988079071044921875f) + (valueNoise(param_8) * 0.3499999940395355224609375f)) + (valueNoise(param_9) * 0.20000000298023223876953125f);
    float lying = smoothstep(drift - 0.14000000059604644775390625f, drift + 0.14000000059604644775390625f, (amount * ((1.0f - (0.319999992847442626953125f * overhead)) - (0.300000011920928955078125f * wear))) * 1.25f);
    if (lying <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    float2 param_10 = (l * 0.449999988079071044921875f) + 9.0f.xx;
    float swell = valueNoise(param_10);
    float depthScale = (0.7200000286102294921875f + (0.560000002384185791015625f * swell)) * (1.0f - (0.579999983310699462890625f * wear));
    float2 param_11 = q;
    float _1966 = pavedAt(param_11);
    float paved = _1966;
    float paveKeep = 1.0f - (paved * lerp(0.959999978542327880859375f, 0.99500000476837158203125f, clamp(amount - 0.60000002384185791015625f, 0.0f, 1.0f)));
    float snow = ((((full * lying) * outside) * depthScale) * (1.0f + (0.2199999988079071044921875f * bank))) * paveKeep;
    if (snow <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    float2 param_12 = q;
    return snow - (min(0.02500000037252902984619140625f, snow * 0.5f) * pressedAt(param_12));
}

float3 mixPerceptual(float3 a, float3 b, float t)
{
    float3 m = lerp(sqrt(max(a, 0.0f.xxx)), sqrt(max(b, 0.0f.xxx)), clamp(t, 0.0f, 1.0f).xxx);
    return m * m;
}

void frag_main()
{
    float2 pixel = floor(gl_FragCoord.xy) + 0.5f.xx;
    color = 0.0f.xxxx;
    lift = 0.0f.xxxx;
    bool _3948 = pixel.x >= ambient_extent.x;
    bool _3957;
    if (!_3948)
    {
        _3957 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _3957 = _3948;
    }
    if (_3957)
    {
        return;
    }
    float2 param = pixel;
    float4 centre = positionAt(param);
    if (centre.w > 0.75f)
    {
        return;
    }
    float3 src = source.Load(int3(int2(pixel), 0)).xyz;
    bool ground = centre.w > 0.25f;
    bool mapped = ambient_sunLot.w > 0.0f;
    float _3990;
    if (ground)
    {
        _3990 = ((0.89999997615814208984375f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
    }
    else
    {
        _3990 = (0.89999997615814208984375f - depthMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f;
    }
    float key = _3990;
    float2 param_1 = centre.xy;
    float param_2 = key;
    bool param_3 = ground;
    float2 param_4 = ambient_frame.xy;
    float3 here = lotPoint(param_1, param_2, param_3, param_4);
    float _4029;
    if (mapped)
    {
        float3 param_5 = here;
        _4029 = 1.0f - indoors(param_5);
    }
    else
    {
        _4029 = 1.0f;
    }
    float outdoor = _4029;
    if (mapped && (!ground))
    {
        float3 param_6 = here - float3(0.0f, 0.0f, 0.25f);
        outdoor = min(outdoor, 1.0f - indoors(param_6));
    }
    float _4054;
    if (mapped)
    {
        float3 _4058;
        if (ground)
        {
            _4058 = here;
        }
        else
        {
            _4058 = here + float3(0.0f, 0.0f, 0.449999988079071044921875f);
        }
        float3 param_7 = _4058;
        _4054 = architecturalExposure(param_7);
    }
    else
    {
        _4054 = 1.0f;
    }
    float skyExposed = _4054;
    if (outdoor <= 0.0f)
    {
        return;
    }
    float2 param_8 = here.xy;
    float2 lot = lotSource(param_8);
    float lotPixelScale = max(length(fwidth(lot)), 0.00200000009499490261077880859375f);
    float amount = ambient_season.y;
    float springBloom = clamp(ambient_seasonExtra.y, 0.0f, 1.0f);
    float frost = clamp(ambient_seasonExtra2.y, 0.0f, 1.0f);
    float lum = dot(src, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float green = smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, (src.y - max(src.x, src.z)) / max(src.y, 0.039999999105930328369140625f));
    float _4118;
    if (mapped)
    {
        float2 param_9 = here.xy;
        _4118 = topAt(param_9) - here.z;
    }
    else
    {
        _4118 = 0.0f;
    }
    float over = _4118;
    float covered = smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, over);
    bool _4139;
    if (mapped)
    {
        _4139 = ambient_season.x > 1.5f;
    }
    else
    {
        _4139 = mapped;
    }
    if (_4139)
    {
        float _4153;
        float _4163;
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                _4153 = 1.0f;
            }
            else
            {
                _4153 = (i == 1) ? (-1.0f) : 0.0f;
            }
            if (i == 2)
            {
                _4163 = 1.0f;
            }
            else
            {
                _4163 = (i == 3) ? (-1.0f) : 0.0f;
            }
            float2 offset = float2(_4153, _4163) * 0.3499999940395355224609375f;
            float2 param_10 = here.xy + offset;
            covered += smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, topAt(param_10) - here.z);
        }
        covered /= 5.0f;
    }
    float3 result = src;
    uint _4195_dummy_parameter;
    bool _4197 = int2(spvTextureSize(simMap, uint(0), _4195_dummy_parameter)).x > 1;
    bool _4207;
    if (_4197)
    {
        _4207 = simMap.Load(int3(int2(pixel), 0)).x > 0.5f;
    }
    else
    {
        _4207 = _4197;
    }
    bool sim = _4207;
    bool _4217;
    if (mapped)
    {
        uint _4214_dummy_parameter;
        _4217 = int2(spvTextureSize(trailMap, uint(0), _4214_dummy_parameter)).x > 4;
    }
    else
    {
        _4217 = mapped;
    }
    bool _4227;
    if (_4217)
    {
        _4227 = abs(trailMap.Load(int3(int2(0, 0), 0)).w - 0.5f) < 0.180000007152557373046875f;
    }
    else
    {
        _4227 = _4217;
    }
    bool hasLiveFloraMap = _4227;
    if (ambient_season.x < 0.5f)
    {
        if ((((springBloom > 0.00999999977648258209228515625f) && (skyExposed > 0.001000000047497451305389404296875f)) && ground) && (green > 0.0500000007450580596923828125f))
        {
            float3 param_11 = float3(0.3400000035762786865234375f, 0.449999988079071044921875f, 0.180000007152557373046875f);
            float3 param_12 = src;
            float3 param_13 = srgbToLinear(param_11);
            result = lerp(src, recolor(param_12, param_13), (((green * skyExposed) * springBloom) * 0.180000007152557373046875f).xxx);
        }
        if ((((frost > 0.0199999995529651641845703125f) && (skyExposed > 0.001000000047497451305389404296875f)) && (!sim)) && (green > 0.0500000007450580596923828125f))
        {
            float2 param_14 = lot * 6.0f;
            float2 param_15 = (lot * 19.0f) + 7.099999904632568359375f.xx;
            float rime = smoothstep(0.3499999940395355224609375f, 0.819999992847442626953125f, (valueNoise(param_14) * 0.550000011920928955078125f) + (valueNoise(param_15) * 0.449999988079071044921875f));
            float3 param_16 = float3(0.7799999713897705078125f, 0.86000001430511474609375f, 0.949999988079071044921875f);
            float3 frostTint = srgbToLinear(param_16) * clamp(lum / 0.119999997317790985107421875f, 0.3499999940395355224609375f, 1.25f);
            result = lerp(result, frostTint, ((((frost * rime) * green) * skyExposed) * (ground ? 0.3400000035762786865234375f : 0.2199999988079071044921875f)).xxx);
        }
        float3 _4318 = abs(result - src);
        if (all(bool3(_4318.x < 9.9999997473787516355514526367188e-05f.xxx.x, _4318.y < 9.9999997473787516355514526367188e-05f.xxx.y, _4318.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
        {
            return;
        }
    }
    else
    {
        if (ambient_season.x < 1.5f)
        {
            uint _4336_dummy_parameter;
            bool hasSpriteLayer = int2(spvTextureSize(spriteMap, uint(0), _4336_dummy_parameter)).x > 4;
            float4 _4341;
            if (hasSpriteLayer)
            {
                _4341 = spriteMap.Load(int3(int2(pixel), 0));
            }
            else
            {
                _4341 = 0.0f.xxxx;
            }
            float4 sp = _4341;
            if (!ground)
            {
                bool _4361;
                if (hasSpriteLayer)
                {
                    _4361 = sp.w > 0.00200000009499490261077880859375f;
                }
                else
                {
                    _4361 = hasSpriteLayer;
                }
                bool _4367;
                if (_4361)
                {
                    _4367 = sp.w < 0.9900000095367431640625f;
                }
                else
                {
                    _4367 = _4361;
                }
                if (_4367)
                {
                    float3 F = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                    float3 B = clamp((src - sp.xyz) / max(1.0f - sp.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                    float3 param_17 = F;
                    float3 param_18 = here;
                    float2 param_19 = lot;
                    float param_20 = amount;
                    float param_21 = outdoor;
                    bool param_22 = sim;
                    bool param_23 = mapped;
                    bool param_24 = hasLiveFloraMap;
                    float3 F_aut = applyAutumnFoliage(param_17, param_18, param_19, param_20, param_21, param_22, param_23, param_24);
                    float3 B_aut = B;
                    float gDepth = groundMap.Load(int3(int2(pixel), 0)).x;
                    if ((!sim) && (gDepth < 1.0f))
                    {
                        float gKey = ((0.89999997615814208984375f - gDepth) / 0.0030000000260770320892333984375f) + ambient_view.w;
                        float2 param_25 = centre.xy;
                        float param_26 = gKey;
                        bool param_27 = true;
                        float2 param_28 = ambient_frame.xy;
                        float3 hereG = lotPoint(param_25, param_26, param_27, param_28);
                        float _4445;
                        if (mapped)
                        {
                            float3 param_29 = hereG;
                            _4445 = 1.0f - indoors(param_29);
                        }
                        else
                        {
                            _4445 = 1.0f;
                        }
                        float gOutdoor = _4445;
                        if (gOutdoor > 0.0f)
                        {
                            float _4460;
                            if (mapped)
                            {
                                float3 param_30 = hereG;
                                _4460 = architecturalExposure(param_30);
                            }
                            else
                            {
                                _4460 = 1.0f;
                            }
                            float gSkyExposed = _4460;
                            float2 param_31 = hereG.xy;
                            float2 gLot = lotSource(param_31);
                            float gPixelScale = max(1.0f / (36.0f * max(ambient_view.z, 0.119999997317790985107421875f)), 0.00200000009499490261077880859375f);
                            float3 param_32 = B;
                            float3 param_33 = hereG;
                            float2 param_34 = gLot;
                            float param_35 = gPixelScale;
                            float param_36 = amount;
                            float param_37 = gOutdoor;
                            float param_38 = gSkyExposed;
                            bool param_39 = mapped;
                            bool param_40 = hasLiveFloraMap;
                            bool param_41 = true;
                            B_aut = applyAutumnGround(param_32, param_33, param_34, param_35, param_36, param_37, param_38, param_39, param_40, param_41);
                        }
                    }
                    result = (F_aut * sp.w) + (B_aut * (1.0f - sp.w));
                }
                else
                {
                    bool _4519;
                    if (hasSpriteLayer)
                    {
                        _4519 = sp.w >= 0.9900000095367431640625f;
                    }
                    else
                    {
                        _4519 = hasSpriteLayer;
                    }
                    float3 _4520;
                    if (_4519)
                    {
                        _4520 = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                    }
                    else
                    {
                        _4520 = src;
                    }
                    float3 F_1 = _4520;
                    float3 param_42 = F_1;
                    float3 param_43 = here;
                    float2 param_44 = lot;
                    float param_45 = amount;
                    float param_46 = outdoor;
                    bool param_47 = sim;
                    bool param_48 = mapped;
                    bool param_49 = hasLiveFloraMap;
                    result = applyAutumnFoliage(param_42, param_43, param_44, param_45, param_46, param_47, param_48, param_49);
                }
            }
            else
            {
                float3 param_50 = src;
                float3 param_51 = here;
                float2 param_52 = lot;
                float param_53 = lotPixelScale;
                float param_54 = amount;
                float param_55 = outdoor;
                float param_56 = skyExposed;
                bool param_57 = mapped;
                bool param_58 = hasLiveFloraMap;
                bool param_59 = false;
                result = applyAutumnGround(param_50, param_51, param_52, param_53, param_54, param_55, param_56, param_57, param_58, param_59);
            }
            bool _4578 = ((frost > 0.0199999995529651641845703125f) && (skyExposed > 0.001000000047497451305389404296875f)) && (!sim);
            bool _4585;
            if (_4578)
            {
                _4585 = ground || (green > 0.0500000007450580596923828125f);
            }
            else
            {
                _4585 = _4578;
            }
            if (_4585)
            {
                float2 param_60 = lot * 6.0f;
                float2 param_61 = (lot * 19.0f) + 7.099999904632568359375f.xx;
                float rime_1 = smoothstep(0.37999999523162841796875f, 0.839999973773956298828125f, (valueNoise(param_60) * 0.550000011920928955078125f) + (valueNoise(param_61) * 0.449999988079071044921875f));
                float _4605;
                if (ground)
                {
                    float2 param_62 = here.xy;
                    float _4611 = pavedAt(param_62);
                    _4605 = 1.0f - (0.85000002384185791015625f * _4611);
                }
                else
                {
                    _4605 = green;
                }
                float mask = _4605;
                float3 param_63 = float3(0.7799999713897705078125f, 0.86000001430511474609375f, 0.949999988079071044921875f);
                float3 frostTint_1 = srgbToLinear(param_63) * clamp(lum / 0.119999997317790985107421875f, 0.3499999940395355224609375f, 1.25f);
                result = lerp(result, frostTint_1, ((((frost * rime_1) * mask) * skyExposed) * (ground ? 0.300000011920928955078125f : 0.20000000298023223876953125f)).xxx);
            }
        }
        else
        {
            float winterOutdoor = min(outdoor, skyExposed);
            if (mapped)
            {
                float3 param_64 = here;
                winterOutdoor *= (1.0f - smoothstep(0.319999992847442626953125f, 0.4799999892711639404296875f, indoors(param_64)));
            }
            if (winterOutdoor > 0.0f)
            {
                float3 baseColor = result;
                float _4663;
                if (ground && mapped)
                {
                    float2 param_65 = here.xy;
                    float _4669 = pavedAt(param_65);
                    _4663 = _4669;
                }
                else
                {
                    _4663 = 0.0f;
                }
                float pavedHere = _4663;
                float _4676;
                if (ground && mapped)
                {
                    float2 param_66 = here.xy;
                    _4676 = cementAt(param_66);
                }
                else
                {
                    _4676 = 0.0f;
                }
                float cementHere = _4676;
                float vacLot = 1.0f - smoothstep(0.25f, 0.75f, ambient_seasonExtra.x);
                float _4698;
                if ((ground && (pavedHere < 0.3499999940395355224609375f)) && (cementHere < 0.3499999940395355224609375f))
                {
                    _4698 = smoothstep(0.319999992847442626953125f, 0.519999980926513671875f, src.z) * smoothstep(0.00999999977648258209228515625f, 0.0500000007450580596923828125f, src.z - src.x);
                }
                else
                {
                    _4698 = 0.0f;
                }
                float vacSnowBlue = _4698;
                float isVacSnowLot = clamp(max(vacLot, vacSnowBlue), 0.0f, 1.0f);
                float warmOverGreen = smoothstep(-0.00999999977648258209228515625f, 0.039999999105930328369140625f, (src.x - src.y) / max(src.x, 0.0500000007450580596923828125f));
                float vacWarmth = (src.x - src.z) / max(src.x + src.z, 0.0500000007450580596923828125f);
                float naturalEarth = max(green, smoothstep(0.4000000059604644775390625f, 0.540000021457672119140625f, vacWarmth));
                float _4750;
                if (ground)
                {
                    _4750 = clamp(max(naturalEarth, isVacSnowLot), 0.0f, 1.0f) * (1.0f - cementHere);
                }
                else
                {
                    _4750 = 0.0f;
                }
                float earthMask = _4750;
                float _4767;
                if (ground && (pavedHere < 0.3499999940395355224609375f))
                {
                    _4767 = (((warmOverGreen * smoothstep(0.014999999664723873138427734375f, 0.23999999463558197021484375f, vacWarmth)) * smoothstep(0.02999999932944774627685546875f, 0.100000001490116119384765625f, src.x)) * isVacSnowLot) * (1.0f - cementHere);
                }
                else
                {
                    _4767 = 0.0f;
                }
                float vacDirt = _4767;
                float _4792;
                if (ground && (pavedHere < 0.3499999940395355224609375f))
                {
                    _4792 = (((smoothstep(0.7599999904632568359375f, 1.12000000476837158203125f, src.x / max(src.y, 0.014999999664723873138427734375f)) * smoothstep(0.4199999868869781494140625f, 0.579999983310699462890625f, vacWarmth)) * smoothstep(0.014999999664723873138427734375f, 0.04500000178813934326171875f, max(src.x, src.y))) * (1.0f - isVacSnowLot)) * (1.0f - cementHere);
                }
                else
                {
                    _4792 = 0.0f;
                }
                float homeWear = _4792;
                float terrainWear = max(vacDirt, homeWear);
                float2 param_67 = lot;
                float hereCrust = snowCrust(param_67);
                float3 _4831;
                if (sim)
                {
                    _4831 = baseColor;
                }
                else
                {
                    float3 param_68 = baseColor;
                    float3 param_69 = float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f);
                    _4831 = lerp(baseColor, recolor(param_68, param_69), (0.4000000059604644775390625f * green).xxx);
                }
                float3 dull = _4831;
                if (((ground && (pavedHere < 0.3499999940395355224609375f)) && (isVacSnowLot < 0.5f)) && (earthMask > 0.00999999977648258209228515625f))
                {
                    float3 param_70 = baseColor;
                    float3 param_71 = float3(0.319999992847442626953125f, 0.36000001430511474609375f, 0.2199999988079071044921875f);
                    float3 dormant = lerp(baseColor, recolor(param_70, param_71), (0.550000011920928955078125f * green).xxx);
                    float2 param_72 = lot;
                    float bareMix = clamp(max(terrainWear * 0.85000002384185791015625f, max(smoothstep(0.540000021457672119140625f, 0.86000001430511474609375f, dirtField(param_72)) * 0.7200000286102294921875f, covered * 0.4799999892711639404296875f)), 0.0f, 0.87999999523162841796875f);
                    float3 underDirt = lerp(float3(0.08200000226497650146484375f, 0.04500000178813934326171875f, 0.006000000052154064178466796875f), float3(0.33700001239776611328125f, 0.1780000030994415283203125f, 0.0529999993741512298583984375f), (0.3499999940395355224609375f + (0.550000011920928955078125f * hereCrust)).xxx) * clamp(lum / 0.14000000059604644775390625f, 0.449999988079071044921875f, 1.25f);
                    dull = lerp(dormant, underDirt, (smoothstep(0.119999997317790985107421875f, 0.819999992847442626953125f, bareMix + ((0.5f - hereCrust) * 0.14000000059604644775390625f)) * earthMask).xxx);
                }
                float deep = clamp(amount - 1.0f, 0.0f, 1.0f);
                bool _4917 = !sim;
                bool _4925;
                if (_4917)
                {
                    _4925 = (!ground) || (!mapped);
                }
                else
                {
                    _4925 = _4917;
                }
                if (_4925)
                {
                    float facing = 1.0f;
                    if (!ground)
                    {
                        float3 p = centre.xyz;
                        float s1 = max(2.0f, 2.0f * ambient_view.z);
                        float s2 = s1 * 2.0f;
                        float3 dx = float3(1.0f, 0.0f, 0.0f);
                        float3 dy = float3(0.0f, 1.0f, 0.0f);
                        float wxSum = 0.0f;
                        float wySum = 0.0f;
                        float3 dxAcc = 0.0f.xxx;
                        float3 dyAcc = 0.0f.xxx;
                        for (int r = 0; r < 2; r++)
                        {
                            float st = (r == 0) ? s1 : s2;
                            float w = (r == 0) ? 0.60000002384185791015625f : 0.4000000059604644775390625f;
                            float2 param_73 = pixel - float2(st, 0.0f);
                            float3 l = positionAt(param_73).xyz;
                            float2 param_74 = pixel + float2(st, 0.0f);
                            float3 rt = positionAt(param_74).xyz;
                            bool lOk = abs(l.z - p.z) < 28.0f;
                            bool rOk = abs(rt.z - p.z) < 28.0f;
                            if (lOk && rOk)
                            {
                                dxAcc += ((rt - l) * (0.5f * w));
                                wxSum += w;
                            }
                            else
                            {
                                if (rOk)
                                {
                                    dxAcc += ((rt - p) * w);
                                    wxSum += w;
                                }
                                else
                                {
                                    if (lOk)
                                    {
                                        dxAcc += ((p - l) * w);
                                        wxSum += w;
                                    }
                                }
                            }
                            float2 param_75 = pixel - float2(0.0f, st);
                            float3 u = positionAt(param_75).xyz;
                            float2 param_76 = pixel + float2(0.0f, st);
                            float3 dn = positionAt(param_76).xyz;
                            bool uOk = abs(u.z - p.z) < 28.0f;
                            bool dOk = abs(dn.z - p.z) < 28.0f;
                            if (uOk && dOk)
                            {
                                dyAcc += ((dn - u) * (0.5f * w));
                                wySum += w;
                            }
                            else
                            {
                                if (dOk)
                                {
                                    dyAcc += ((dn - p) * w);
                                    wySum += w;
                                }
                                else
                                {
                                    if (uOk)
                                    {
                                        dyAcc += ((p - u) * w);
                                        wySum += w;
                                    }
                                }
                            }
                        }
                        if (wxSum > 0.0f)
                        {
                            dx = dxAcc / wxSum.xxx;
                        }
                        if (wySum > 0.0f)
                        {
                            dy = dyAcc / wySum.xxx;
                        }
                        float3 n = normalize(cross(dy, dx));
                        if (n.z < 0.0f)
                        {
                            n = -n;
                        }
                        facing = dot(n, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                    }
                    float2 param_77 = lot * 0.89999997615814208984375f;
                    float2 param_78 = (lot * 2.7000000476837158203125f) + 5.0f.xx;
                    float2 param_79 = (lot * 7.5f) + 11.0f.xx;
                    float drift = ((valueNoise(param_77) * 0.4199999868869781494140625f) + (valueNoise(param_78) * 0.3300000131130218505859375f)) + (valueNoise(param_79) * 0.25f);
                    float depth = (amount * (1.0f - (0.300000011920928955078125f * covered))) * 1.25f;
                    float lying = smoothstep(drift - 0.14000000059604644775390625f, drift + 0.14000000059604644775390625f, depth + ((hereCrust - 0.5f) * 0.100000001490116119384765625f));
                    float _5202;
                    if (mapped)
                    {
                        float2 param_80 = pixel;
                        _5202 = groundAt(param_80);
                    }
                    else
                    {
                        _5202 = -100000.0f;
                    }
                    float baseAlt = _5202;
                    float _5214;
                    if (baseAlt > (-10000.0f))
                    {
                        float2 param_81 = centre.xy;
                        float param_82 = baseAlt / 27.7128124237060546875f;
                        bool param_83 = true;
                        float2 param_84 = ambient_frame.xy;
                        _5214 = lotPoint(param_81, param_82, param_83, param_84).z;
                    }
                    else
                    {
                        _5214 = 0.0f;
                    }
                    float groundFallback = _5214;
                    float _5234;
                    if (mapped)
                    {
                        float2 param_85 = here.xy;
                        float param_86 = groundFallback;
                        _5234 = terrainBaseAt(param_85, param_86);
                    }
                    else
                    {
                        _5234 = groundFallback;
                    }
                    float roofBase = _5234;
                    float _5248;
                    if (mapped)
                    {
                        _5248 = here.z - roofBase;
                    }
                    else
                    {
                        _5248 = 0.0f;
                    }
                    float relZ = _5248;
                    int roofWedges = 0;
                    float bestRoofFacing = 0.0f;
                    if ((((!ground) && mapped) && (relZ > 3.0499999523162841796875f)) && (facing > 0.23999999463558197021484375f))
                    {
                        float3 p0 = centre.xyz;
                        float2 maxPx = ambient_extent.xy - 0.5f.xx;
                        float rP = max(2.0f, 6.5f * ambient_view.z);
                        float wP = max(0.800000011920928955078125f, 1.5f * ambient_view.z);
                        float2 dir;
                        for (int i_1 = 0; i_1 < 12; i_1++)
                        {
                            if (i_1 < 8)
                            {
                                float a = float(i_1) * 0.785398185253143310546875f;
                                dir = float2(cos(a), sin(a));
                            }
                            else
                            {
                                float sx = ((i_1 == 8) || (i_1 == 9)) ? 0.89442718029022216796875f : (-0.89442718029022216796875f);
                                float sy = ((i_1 == 8) || (i_1 == 10)) ? 0.447213590145111083984375f : (-0.447213590145111083984375f);
                                dir = float2(sx, sy);
                            }
                            float2 perp = float2(-dir.y, dir.x);
                            float2 pML = clamp((pixel + (dir * (0.5f * rP))) + (perp * (0.5f * wP)), 0.5f.xx, maxPx);
                            float2 pMR = clamp((pixel + (dir * (0.5f * rP))) - (perp * (0.5f * wP)), 0.5f.xx, maxPx);
                            float2 pT = clamp(pixel + (dir * rP), 0.5f.xx, maxPx);
                            float2 pL = clamp((pixel + (dir * rP)) + (perp * wP), 0.5f.xx, maxPx);
                            float2 pR = clamp((pixel + (dir * rP)) - (perp * wP), 0.5f.xx, maxPx);
                            bool _5409 = length(pT - pixel) < (0.699999988079071044921875f * rP);
                            bool _5420;
                            if (!_5409)
                            {
                                _5420 = length(pL - pR) < (0.75f * wP);
                            }
                            else
                            {
                                _5420 = _5409;
                            }
                            if (_5420)
                            {
                                continue;
                            }
                            float2 param_87 = pML;
                            float4 qML = positionAt(param_87);
                            float2 param_88 = pMR;
                            float4 qMR = positionAt(param_88);
                            float2 param_89 = pT;
                            float4 qT = positionAt(param_89);
                            float2 param_90 = pL;
                            float4 qL = positionAt(param_90);
                            float2 param_91 = pR;
                            float4 qR = positionAt(param_91);
                            bool _5446 = qML.w < 0.25f;
                            bool _5457;
                            if (_5446)
                            {
                                _5457 = abs(qML.z - p0.z) < 14.0f;
                            }
                            else
                            {
                                _5457 = _5446;
                            }
                            bool _5463;
                            if (_5457)
                            {
                                _5463 = qMR.w < 0.25f;
                            }
                            else
                            {
                                _5463 = _5457;
                            }
                            bool _5473;
                            if (_5463)
                            {
                                _5473 = abs(qMR.z - p0.z) < 14.0f;
                            }
                            else
                            {
                                _5473 = _5463;
                            }
                            bool _5479;
                            if (_5473)
                            {
                                _5479 = qT.w < 0.25f;
                            }
                            else
                            {
                                _5479 = _5473;
                            }
                            bool _5490;
                            if (_5479)
                            {
                                _5490 = abs(qT.z - p0.z) < 22.0f;
                            }
                            else
                            {
                                _5490 = _5479;
                            }
                            bool _5496;
                            if (_5490)
                            {
                                _5496 = qL.w < 0.25f;
                            }
                            else
                            {
                                _5496 = _5490;
                            }
                            bool _5506;
                            if (_5496)
                            {
                                _5506 = abs(qL.z - p0.z) < 22.0f;
                            }
                            else
                            {
                                _5506 = _5496;
                            }
                            bool _5512;
                            if (_5506)
                            {
                                _5512 = qR.w < 0.25f;
                            }
                            else
                            {
                                _5512 = _5506;
                            }
                            bool _5522;
                            if (_5512)
                            {
                                _5522 = abs(qR.z - p0.z) < 22.0f;
                            }
                            else
                            {
                                _5522 = _5512;
                            }
                            bool _5532;
                            if (_5522)
                            {
                                _5532 = abs(qL.z - qR.z) < 7.5f;
                            }
                            else
                            {
                                _5532 = _5522;
                            }
                            if (_5532)
                            {
                                float3 cr = cross(qL.xyz - p0, qR.xyz - p0);
                                float crLen = length(cr);
                                if (crLen > 1.0f)
                                {
                                    float3 nW = cr / crLen.xxx;
                                    if (nW.z < 0.0f)
                                    {
                                        nW = -nW;
                                    }
                                    float wFacing = dot(nW, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                                    bool _5571 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.89999997615814208984375f);
                                    bool _5577;
                                    if (_5571)
                                    {
                                        _5577 = nW.z > 0.3499999940395355224609375f;
                                    }
                                    else
                                    {
                                        _5577 = _5571;
                                    }
                                    bool _5584;
                                    if (_5577)
                                    {
                                        _5584 = abs(nW.x) > 0.1500000059604644775390625f;
                                    }
                                    else
                                    {
                                        _5584 = _5577;
                                    }
                                    if (_5584)
                                    {
                                        float errML = abs(dot(qML.xyz - p0, nW)) / nW.z;
                                        float errMR = abs(dot(qMR.xyz - p0, nW)) / nW.z;
                                        float errT = abs(dot(qT.xyz - p0, nW)) / nW.z;
                                        if (((errML < 0.550000011920928955078125f) && (errMR < 0.550000011920928955078125f)) && (errT < 0.550000011920928955078125f))
                                        {
                                            roofWedges = 1;
                                            bestRoofFacing = wFacing;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if ((roofWedges == 0) && (facing >= 0.910000026226043701171875f))
                        {
                            float rF = max(6.0f, 22.0f * ambient_view.z);
                            float wF = max(3.0f, 10.0f * ambient_view.z);
                            for (int i_2 = 0; i_2 < 8; i_2++)
                            {
                                float a_1 = float(i_2) * 0.785398185253143310546875f;
                                float2 dir_1 = float2(cos(a_1), sin(a_1));
                                float2 perp_1 = float2(-dir_1.y, dir_1.x);
                                float2 pML_1 = (pixel + (dir_1 * (0.5f * rF))) + (perp_1 * (0.5f * wF));
                                float2 pMR_1 = (pixel + (dir_1 * (0.5f * rF))) - (perp_1 * (0.5f * wF));
                                float2 pT_1 = pixel + (dir_1 * rF);
                                float2 pL_1 = (pixel + (dir_1 * rF)) + (perp_1 * wF);
                                float2 pR_1 = (pixel + (dir_1 * rF)) - (perp_1 * wF);
                                bool _5729 = any(bool2(pML_1.x < 0.5f.xx.x, pML_1.y < 0.5f.xx.y));
                                bool _5737;
                                if (!_5729)
                                {
                                    _5737 = any(bool2(pML_1.x > maxPx.x, pML_1.y > maxPx.y));
                                }
                                else
                                {
                                    _5737 = _5729;
                                }
                                bool _5744;
                                if (!_5737)
                                {
                                    _5744 = any(bool2(pMR_1.x < 0.5f.xx.x, pMR_1.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _5744 = _5737;
                                }
                                bool _5752;
                                if (!_5744)
                                {
                                    _5752 = any(bool2(pMR_1.x > maxPx.x, pMR_1.y > maxPx.y));
                                }
                                else
                                {
                                    _5752 = _5744;
                                }
                                bool _5759;
                                if (!_5752)
                                {
                                    _5759 = any(bool2(pT_1.x < 0.5f.xx.x, pT_1.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _5759 = _5752;
                                }
                                bool _5767;
                                if (!_5759)
                                {
                                    _5767 = any(bool2(pT_1.x > maxPx.x, pT_1.y > maxPx.y));
                                }
                                else
                                {
                                    _5767 = _5759;
                                }
                                bool _5774;
                                if (!_5767)
                                {
                                    _5774 = any(bool2(pL_1.x < 0.5f.xx.x, pL_1.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _5774 = _5767;
                                }
                                bool _5782;
                                if (!_5774)
                                {
                                    _5782 = any(bool2(pL_1.x > maxPx.x, pL_1.y > maxPx.y));
                                }
                                else
                                {
                                    _5782 = _5774;
                                }
                                bool _5789;
                                if (!_5782)
                                {
                                    _5789 = any(bool2(pR_1.x < 0.5f.xx.x, pR_1.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _5789 = _5782;
                                }
                                bool _5797;
                                if (!_5789)
                                {
                                    _5797 = any(bool2(pR_1.x > maxPx.x, pR_1.y > maxPx.y));
                                }
                                else
                                {
                                    _5797 = _5789;
                                }
                                if (_5797)
                                {
                                    continue;
                                }
                                float2 param_92 = pML_1;
                                float4 qML_1 = positionAt(param_92);
                                float2 param_93 = pMR_1;
                                float4 qMR_1 = positionAt(param_93);
                                float2 param_94 = pT_1;
                                float4 qT_1 = positionAt(param_94);
                                float2 param_95 = pL_1;
                                float4 qL_1 = positionAt(param_95);
                                float2 param_96 = pR_1;
                                float4 qR_1 = positionAt(param_96);
                                bool _5823 = qML_1.w < 0.25f;
                                bool _5833;
                                if (_5823)
                                {
                                    _5833 = abs(qML_1.z - p0.z) < 28.0f;
                                }
                                else
                                {
                                    _5833 = _5823;
                                }
                                bool _5839;
                                if (_5833)
                                {
                                    _5839 = qMR_1.w < 0.25f;
                                }
                                else
                                {
                                    _5839 = _5833;
                                }
                                bool _5849;
                                if (_5839)
                                {
                                    _5849 = abs(qMR_1.z - p0.z) < 28.0f;
                                }
                                else
                                {
                                    _5849 = _5839;
                                }
                                bool _5855;
                                if (_5849)
                                {
                                    _5855 = qT_1.w < 0.25f;
                                }
                                else
                                {
                                    _5855 = _5849;
                                }
                                bool _5866;
                                if (_5855)
                                {
                                    _5866 = abs(qT_1.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _5866 = _5855;
                                }
                                bool _5872;
                                if (_5866)
                                {
                                    _5872 = qL_1.w < 0.25f;
                                }
                                else
                                {
                                    _5872 = _5866;
                                }
                                bool _5882;
                                if (_5872)
                                {
                                    _5882 = abs(qL_1.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _5882 = _5872;
                                }
                                bool _5888;
                                if (_5882)
                                {
                                    _5888 = qR_1.w < 0.25f;
                                }
                                else
                                {
                                    _5888 = _5882;
                                }
                                bool _5898;
                                if (_5888)
                                {
                                    _5898 = abs(qR_1.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _5898 = _5888;
                                }
                                bool _5909;
                                if (_5898)
                                {
                                    _5909 = abs(qL_1.z - qR_1.z) < 20.0f;
                                }
                                else
                                {
                                    _5909 = _5898;
                                }
                                if (_5909)
                                {
                                    float3 cr_1 = cross(qL_1.xyz - p0, qR_1.xyz - p0);
                                    float crLen_1 = length(cr_1);
                                    if (crLen_1 > 1.0f)
                                    {
                                        float3 nW_1 = cr_1 / crLen_1.xxx;
                                        if (nW_1.z < 0.0f)
                                        {
                                            nW_1 = -nW_1;
                                        }
                                        float wFacing_1 = dot(nW_1, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                                        bool _5945 = wFacing_1 >= 0.920000016689300537109375f;
                                        bool _5951;
                                        if (_5945)
                                        {
                                            _5951 = nW_1.z > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _5951 = _5945;
                                        }
                                        if (_5951)
                                        {
                                            float errML_1 = abs(dot(qML_1.xyz - p0, nW_1)) / nW_1.z;
                                            float errMR_1 = abs(dot(qMR_1.xyz - p0, nW_1)) / nW_1.z;
                                            float errT_1 = abs(dot(qT_1.xyz - p0, nW_1)) / nW_1.z;
                                            if (((errML_1 < 0.800000011920928955078125f) && (errMR_1 < 0.800000011920928955078125f)) && (errT_1 < 0.800000011920928955078125f))
                                            {
                                                roofWedges = 1;
                                                bestRoofFacing = wFacing_1;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    bool onRoof = ((((!ground) && mapped) && (relZ > 3.0499999523162841796875f)) && (facing > 0.23999999463558197021484375f)) && (roofWedges >= 1);
                    float _6017;
                    if (ground)
                    {
                        _6017 = 1.0f;
                    }
                    else
                    {
                        float _6022;
                        if (onRoof)
                        {
                            _6022 = smoothstep(0.20000000298023223876953125f, 0.519999980926513671875f, max(facing, bestRoofFacing));
                        }
                        else
                        {
                            _6022 = smoothstep((green > 0.5f) ? 0.2599999904632568359375f : 0.4799999892711639404296875f, (green > 0.5f) ? 0.62000000476837158203125f : 0.819999992847442626953125f, facing);
                        }
                        _6017 = _6022;
                    }
                    float settle = _6017;
                    float wallBlock = 0.0f;
                    if (((!ground) && mapped) && (!onRoof))
                    {
                        float z0 = roofBase + 0.100000001490116119384765625f;
                        float z1 = (roofBase + 2.9500000476837158203125f) + 0.100000001490116119384765625f;
                        float wallR = (green > 0.25f) ? 0.10999999940395355224609375f : 0.4799999892711639404296875f;
                        float2 param_97 = here.xy;
                        float param_98 = z0;
                        float param_99 = wallR;
                        float2 param_100 = here.xy;
                        float param_101 = z1;
                        float param_102 = wallR;
                        float2 param_103 = here.xy;
                        float param_104 = here.z;
                        float param_105 = wallR;
                        wallBlock = max(nearIndoorWall(param_97, param_98, param_99), max(nearIndoorWall(param_100, param_101, param_102), nearIndoorWall(param_103, param_104, param_105)));
                        if ((green < 0.25f) && (relZ > 2.7999999523162841796875f))
                        {
                            float2 wallXY1 = here.xy - (1.25f * max(0.0f, relZ - 2.9500000476837158203125f)).xx;
                            float2 wallXY2 = here.xy - (1.25f * max(0.0f, relZ - 5.900000095367431640625f)).xx;
                            float3 param_106 = float3(wallXY1, z0);
                            float2 param_107 = wallXY1;
                            float param_108 = z0;
                            float param_109 = 0.519999980926513671875f;
                            wallBlock = max(wallBlock, max(indoors(param_106), nearIndoorWall(param_107, param_108, param_109)));
                            float3 param_110 = float3(wallXY2, z1);
                            float2 param_111 = wallXY2;
                            float param_112 = z1;
                            float param_113 = 0.519999980926513671875f;
                            wallBlock = max(wallBlock, max(indoors(param_110), nearIndoorWall(param_111, param_112, param_113)));
                        }
                    }
                    settle *= (1.0f - smoothstep(0.0199999995529651641845703125f, 0.25f, wallBlock));
                    float2 param_114 = (lot * 0.449999988079071044921875f) + 9.0f.xx;
                    float swell = valueNoise(param_114);
                    float capShade = ((1.0f - hereCrust) * lerp(0.100000001490116119384765625f, 0.0500000007450580596923828125f, deep)) + ((1.0f - smoothstep(0.20000000298023223876953125f, 0.800000011920928955078125f, swell)) * 0.119999997317790985107421875f);
                    float3 snow = lerp(float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), clamp(capShade, 0.0f, 0.3400000035762786865234375f).xxx);
                    snow *= (1.0f + ((0.319999992847442626953125f * (1.0f - (0.699999988079071044921875f * deep))) * (lum - 0.23999999463558197021484375f)));
                    float daySun = max(0.0f, 1.0f - ambient_weather.w);
                    float2 param_115 = lot * 24.0f;
                    float2 param_116 = (lot * 41.0f) + 31.700000762939453125f.xx;
                    float glint = smoothstep(0.680000007152557373046875f, 0.939999997615814208984375f, valueNoise(param_115) * valueNoise(param_116)) * daySun;
                    snow += ((float3(0.0199999995529651641845703125f, 0.0240000002086162567138671875f, 0.034000001847743988037109375f) * glint) * winterOutdoor);
                    float _6219;
                    if (ground)
                    {
                        _6219 = lying * winterOutdoor;
                    }
                    else
                    {
                        _6219 = ((lying * settle) * winterOutdoor) * (onRoof ? 0.920000016689300537109375f : 0.85000002384185791015625f);
                    }
                    float cover = _6219;
                    result = lerp(dull, snow, clamp(cover, 0.0f, 1.0f).xxx);
                    if ((onRoof && (green < 0.3499999940395355224609375f)) && (cover > 0.0500000007450580596923828125f))
                    {
                        lift.w = clamp(cover, 0.0f, 1.0f);
                    }
                }
                else
                {
                    result = dull;
                }
                if (mapped)
                {
                    float2 param_117 = pixel;
                    float terrain = groundAt(param_117);
                    float _6265;
                    if (ground)
                    {
                        _6265 = here.z;
                    }
                    else
                    {
                        float _6273;
                        if (terrain > (-10000.0f))
                        {
                            float2 param_118 = centre.xy;
                            float param_119 = terrain / 27.7128124237060546875f;
                            bool param_120 = true;
                            float2 param_121 = ambient_frame.xy;
                            _6273 = lotPoint(param_118, param_119, param_120, param_121).z;
                        }
                        else
                        {
                            _6273 = here.z;
                        }
                        _6265 = _6273;
                    }
                    float base = _6265;
                    float full = (0.039999999105930328369140625f * min(amount, 1.0f)) + (0.300000011920928955078125f * deep);
                    float _6303;
                    if (ground)
                    {
                        _6303 = 0.0f;
                    }
                    else
                    {
                        _6303 = max(0.0f, here.z - base);
                    }
                    float h0 = _6303;
                    float top = full * 1.9500000476837158203125f;
                    float wall = 0.0f;
                    if (((!ground) && (h0 < top)) && (!sim))
                    {
                        float2 param_122 = here.xy;
                        float param_123 = base + 0.100000001490116119384765625f;
                        float param_124 = 0.4199999868869781494140625f;
                        float2 param_125 = here.xy;
                        float param_126 = (base + 2.9500000476837158203125f) + 0.100000001490116119384765625f;
                        float param_127 = 0.4199999868869781494140625f;
                        float2 param_128 = here.xy;
                        float param_129 = here.z;
                        float param_130 = 0.4199999868869781494140625f;
                        wall = max(nearIndoorWall(param_122, param_123, param_124), max(nearIndoorWall(param_125, param_126, param_127), nearIndoorWall(param_128, param_129, param_130)));
                    }
                    if (((h0 < top) && (wall < 0.0500000007450580596923828125f)) && (!sim))
                    {
                        float groundWear = (ground && (earthMask > 0.00999999977648258209228515625f)) ? terrainWear : 0.0f;
                        int steps = (amount > 1.0f) ? 6 : 3;
                        float dt = ((top - h0) / 0.4000000059604644775390625f) / float(steps);
                        float hitT = -1.0f;
                        float hitS = 0.0f;
                        float nextS = -1.0f;
                        float prevDiff = 0.0f;
                        float prevS = 0.0f;
                        bool hasPrev = false;
                        int _6394 = steps - 1;
                        for (int i_3 = _6394; i_3 >= 0; i_3--)
                        {
                            float t = float(i_3) * dt;
                            float2 param_131 = here.xy + (0.5f * t).xx;
                            float param_132 = base;
                            float param_133 = full;
                            float param_134 = amount;
                            float param_135 = groundWear;
                            float param_136 = isVacSnowLot;
                            float sh = snowHeight(param_131, param_132, param_133, param_134, param_135, param_136);
                            float diff = sh - (h0 + (0.4000000059604644775390625f * t));
                            if (diff > 0.0f)
                            {
                                hitT = t;
                                hitS = sh;
                                if (hasPrev)
                                {
                                    hitT += ((dt * diff) / max(diff - prevDiff, 9.9999997473787516355514526367188e-05f));
                                    nextS = prevS;
                                }
                                break;
                            }
                            prevDiff = diff;
                            prevS = sh;
                            hasPrev = true;
                        }
                        if (hitT >= 0.0f)
                        {
                            float2 q = here.xy + (0.5f * hitT).xx;
                            bool _6471 = nextS >= 0.0f;
                            bool _6482;
                            if (_6471)
                            {
                                _6482 = (hitS - nextS) > ((0.7200000286102294921875f * dt) + 0.0320000015199184417724609375f);
                            }
                            else
                            {
                                _6482 = _6471;
                            }
                            bool face = _6482;
                            float e = 0.119999997317790985107421875f;
                            float s0 = h0 + (0.4000000059604644775390625f * hitT);
                            float2 param_137 = q + float2(e, 0.0f);
                            float param_138 = base;
                            float param_139 = full;
                            float param_140 = amount;
                            float param_141 = groundWear;
                            float param_142 = isVacSnowLot;
                            float gx = (snowHeight(param_137, param_138, param_139, param_140, param_141, param_142) - s0) / e;
                            float2 param_143 = q + float2(0.0f, e);
                            float param_144 = base;
                            float param_145 = full;
                            float param_146 = amount;
                            float param_147 = groundWear;
                            float param_148 = isVacSnowLot;
                            float gy = (snowHeight(param_143, param_144, param_145, param_146, param_147, param_148) - s0) / e;
                            float3 n2 = normalize(float3(-gx, -gy, 1.0f));
                            float3 sunDir = normalize(ambient_sunLot.xyz);
                            float lit = clamp(1.0f + (1.0499999523162841796875f * (dot(n2, sunDir) - sunDir.z)), 0.7200000286102294921875f, 1.17999994754791259765625f);
                            float2 param_149 = q;
                            float2 lq = lotSource(param_149);
                            float2 param_150 = lq;
                            float qCrust = snowCrust(param_150);
                            float2 param_151 = (lq * 0.449999988079071044921875f) + 9.0f.xx;
                            float qSwell = valueNoise(param_151);
                            float grainShade = ((1.0f - qCrust) * lerp(0.10999999940395355224609375f, 0.039999999105930328369140625f, deep)) + ((1.0f - smoothstep(0.20000000298023223876953125f, 0.800000011920928955078125f, qSwell)) * 0.119999997317790985107421875f);
                            float3 qSnow = lerp(float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), clamp(grainShade, 0.0f, 0.3400000035762786865234375f).xxx);
                            float under = ground ? lum : 0.20999999344348907470703125f;
                            qSnow *= (1.0f + ((0.3499999940395355224609375f * (1.0f - smoothstep(0.02999999932944774627685546875f, 0.119999997317790985107421875f, hitS))) * (under - 0.2800000011920928955078125f)));
                            float _6602;
                            if (ground)
                            {
                                float2 param_152 = q;
                                float _6607 = pavedAt(param_152);
                                _6602 = _6607;
                            }
                            else
                            {
                                _6602 = 0.0f;
                            }
                            float qPaved = _6602;
                            if (ground && (qPaved < 0.3499999940395355224609375f))
                            {
                                float2 param_153 = q;
                                float qEarth = earthMask * (1.0f - cementAt(param_153));
                                if (qEarth > 0.00999999977648258209228515625f)
                                {
                                    float snowCover = smoothstep(0.4199999868869781494140625f, 0.920000016689300537109375f, amount);
                                    float thinness = 1.0f - smoothstep(0.01200000010430812835693359375f, 0.100000001490116119384765625f, hitS);
                                    float2 param_154 = q;
                                    float param_155 = base;
                                    float qBank = wallBank(param_154, param_155);
                                    float2 param_156 = lq;
                                    float patchDirt = smoothstep(0.560000002384185791015625f, 0.87999999523162841796875f, dirtField(param_156)) * (1.0f - (0.800000011920928955078125f * qBank));
                                    float2 param_157 = q;
                                    float canopyDirt = smoothstep(1.2000000476837158203125f, 2.5f, max(0.0f, topAt(param_157) - base)) * lerp(0.449999988079071044921875f, 0.100000001490116119384765625f, snowCover);
                                    float homePatchScale = lerp(0.680000007152557373046875f, 0.0f, smoothstep(0.449999988079071044921875f, 0.87999999523162841796875f, amount));
                                    float vacPatchScale = 0.100000001490116119384765625f;
                                    float patchScale = lerp(homePatchScale, vacPatchScale, isVacSnowLot);
                                    float homeWearFade = lerp(0.7799999713897705078125f, 0.0500000007450580596923828125f, smoothstep(0.4000000059604644775390625f, 0.89999997615814208984375f, amount));
                                    float wearWeight = lerp(homeWearFade, 0.86000001430511474609375f, isVacSnowLot);
                                    float rawDirt = max(terrainWear * wearWeight, max(patchDirt * patchScale, canopyDirt));
                                    float thinScale = lerp(lerp(0.550000011920928955078125f + (0.449999988079071044921875f * thinness), 0.25f + (0.75f * thinness), snowCover), lerp(0.699999988079071044921875f + (0.300000011920928955078125f * thinness), 0.4000000059604644775390625f + (0.60000002384185791015625f * thinness), 1.0f - terrainWear), isVacSnowLot);
                                    float dirtMix = clamp(((rawDirt * thinScale) * (1.0f - qPaved)) * qEarth, 0.0f, 0.86000001430511474609375f);
                                    float dirtBlend = smoothstep(0.119999997317790985107421875f, 0.819999992847442626953125f, dirtMix + ((0.5f - qCrust) * 0.100000001490116119384765625f));
                                    float3 qDirt = lerp(float3(0.08200000226497650146484375f, 0.04500000178813934326171875f, 0.006000000052154064178466796875f), float3(0.33700001239776611328125f, 0.1780000030994415283203125f, 0.0529999993741512298583984375f), (0.3499999940395355224609375f + (0.550000011920928955078125f * qCrust)).xxx) * lerp(0.819999992847442626953125f, 1.14999997615814208984375f, smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, lum));
                                    qDirt = lerp(qDirt, src, ((0.64999997615814208984375f * isVacSnowLot) * smoothstep(0.100000001490116119384765625f, 0.300000011920928955078125f, terrainWear)).xxx);
                                    float3 param_158 = qSnow;
                                    float3 param_159 = qDirt;
                                    float param_160 = dirtBlend;
                                    qSnow = mixPerceptual(param_158, param_159, param_160);
                                }
                            }
                            float2 param_161 = q;
                            float pressed = pressedAt(param_161);
                            if (pressed > 0.0f)
                            {
                                float2 toSun = normalize(ambient_sunLot.xy + 9.9999997473787516355514526367188e-05f.xx) * 0.02999999932944774627685546875f;
                                float2 param_162 = q + toSun;
                                float shaded = clamp(pressed - pressedAt(param_162), 0.0f, 1.0f);
                                float2 param_163 = q - toSun;
                                float facing2 = clamp(pressed - pressedAt(param_163), 0.0f, 1.0f);
                                qSnow = lerp(qSnow, float3(0.4140000045299530029296875f, 0.49500000476837158203125f, 0.6480000019073486328125f), (0.2800000011920928955078125f * pressed).xxx) * ((1.0f - (0.119999997317790985107421875f * shaded)) + (0.070000000298023223876953125f * facing2));
                            }
                            float daySun2 = max(0.0f, 1.0f - ambient_weather.w);
                            float2 param_164 = lq * 24.0f;
                            float2 param_165 = (lq * 41.0f) + 31.700000762939453125f.xx;
                            float qGlint = smoothstep(0.680000007152557373046875f, 0.939999997615814208984375f, valueNoise(param_164) * valueNoise(param_165)) * daySun2;
                            qSnow += (float3(0.0199999995529651641845703125f, 0.0240000002086162567138671875f, 0.034000001847743988037109375f) * qGlint);
                            float3 _6829;
                            if (face)
                            {
                                _6829 = float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f) * (0.89999997615814208984375f + (0.07999999821186065673828125f * qCrust));
                            }
                            else
                            {
                                _6829 = qSnow * lit;
                            }
                            float3 seen = _6829;
                            float edge = smoothstep(0.0040000001899898052215576171875f, 0.02199999988079071044921875f, hitS + (((qCrust - 0.5f) * 0.004999999888241291046142578125f) * (1.0f - qPaved)));
                            result = lerp(result, seen, edge.xxx);
                            if (edge > 0.5f)
                            {
                                lift = float4(hitT, (base + hitS) - here.z, 1.0f, 0.0f);
                            }
                        }
                    }
                }
            }
            else
            {
                float3 _6874 = abs(result - src);
                if (all(bool3(_6874.x < 9.9999997473787516355514526367188e-05f.xxx.x, _6874.y < 9.9999997473787516355514526367188e-05f.xxx.y, _6874.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
                {
                    return;
                }
            }
        }
    }
    color = float4(result, 1.0f);
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    gl_FragCoord = stage_input.gl_FragCoord;
    gl_FragCoord.w = 1.0 / gl_FragCoord.w;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.color = color;
    stage_output.lift = lift;
    return stage_output;
}
