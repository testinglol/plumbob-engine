static const float2 _2788[4] = { float2(1.0f, 0.0f), float2(-1.0f, 0.0f), float2(0.0f, 1.0f), float2(0.0f, -1.0f) };
static const int2 _7067[4] = { int2(-1, 0), int2(1, 0), int2(0, -1), int2(0, 1) };
static const float3 _12225[14] = { float3(-3.5f, -2.5f, 1.0f), float3(3.5f, -2.5f, 1.0f), float3(-3.5f, 2.5f, 1.0f), float3(3.5f, 2.5f, 1.0f), float3(0.0f, -6.5f, 1.2999999523162841796875f), float3(0.0f, 6.5f, 1.2999999523162841796875f), float3(-6.5f, 0.0f, 1.0f), float3(6.5f, 0.0f, 1.0f), float3(-9.5f, -6.5f, 0.800000011920928955078125f), float3(9.5f, -6.5f, 0.800000011920928955078125f), float3(-9.5f, 6.5f, 0.800000011920928955078125f), float3(9.5f, 6.5f, 0.800000011920928955078125f), float3(0.0f, -12.5f, 0.75f), float3(0.0f, 12.5f, 0.75f) };
static const float3 _12762[9] = { float3(0.0f, -4.5f, 0.1599999964237213134765625f), float3(-3.5f, -5.5f, 0.119999997317790985107421875f), float3(3.5f, -5.5f, 0.119999997317790985107421875f), float3(0.0f, -9.5f, 0.180000007152557373046875f), float3(-5.5f, -10.5f, 0.10999999940395355224609375f), float3(5.5f, -10.5f, 0.10999999940395355224609375f), float3(0.0f, -15.5f, 0.100000001490116119384765625f), float3(-4.5f, -15.5f, 0.0500000007450580596923828125f), float3(4.5f, -15.5f, 0.0500000007450580596923828125f) };

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
    float4 ambient_prevView : packoffset(c48);
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
Texture2D<float4> outFloraMap : register(t9, space2);
SamplerState _outFloraMap_sampler : register(s9, space2);
Texture2D<float4> source : register(t4, space2);
SamplerState _source_sampler : register(s4, space2);
Texture2D<float4> spriteMap : register(t8, space2);
SamplerState _spriteMap_sampler : register(s8, space2);
Texture2D<float4> simMap : register(t7, space2);
SamplerState _simMap_sampler : register(s7, space2);

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

float autumnEdgeMetric(float3 c)
{
    float3 p = sqrt(max(c, 0.0f.xxx));
    return dot(p, float3(0.300000011920928955078125f, 0.560000002384185791015625f, 0.14000000059604644775390625f)) + (0.36000001430511474609375f * (p.x - p.z));
}

float3 mixPerceptual(float3 a, float3 b, float t)
{
    float3 m = lerp(sqrt(max(a, 0.0f.xxx)), sqrt(max(b, 0.0f.xxx)), clamp(t, 0.0f, 1.0f).xxx);
    return m * m;
}

float greenOf(float3 c)
{
    return smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, (c.y - max(c.x, c.z)) / max(c.y, 0.039999999105930328369140625f));
}

float foliageOf(float3 c)
{
    float3 param = c;
    float g = greenOf(param);
    float olive = (smoothstep(1.2999999523162841796875f, 1.7999999523162841796875f, c.y / max(c.z, 0.008000000379979610443115234375f)) * smoothstep(1.10000002384185791015625f, 0.959999978542327880859375f, c.x / max(c.y, 0.008000000379979610443115234375f))) * smoothstep(0.014999999664723873138427734375f, 0.04500000178813934326171875f, c.y);
    return max(g, 0.85000002384185791015625f * olive);
}

float3 recolor(float3 like, float3 hue)
{
    return hue * (dot(like, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)) / max(dot(hue, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)), 0.001000000047497451305389404296875f));
}

float4 resolveWinterPixel(inout int2 ip, int2 maxI, bool hasSpriteLayer)
{
    ip = clamp(ip, int2(0, 0), maxI);
    float3 pre = source.Load(int3(ip, 0)).xyz;
    float4 stLift = trailMap.Load(int3(ip, 0));
    float3 orig = overheadMap.Load(int3(ip, 0)).xyz;
    float _7005;
    if (stLift.z < (-0.00200000009499490261077880859375f))
    {
        _7005 = -stLift.z;
    }
    else
    {
        _7005 = 0.0f;
    }
    float capCover = _7005;
    float snowAct = (stLift.z > 0.5f) ? 1.0f : capCover;
    bool _7021 = ambient_view.z >= 1.35000002384185791015625f;
    bool _7028;
    if (_7021)
    {
        _7028 = stLift.z < (-0.0005000000237487256526947021484375f);
    }
    else
    {
        _7028 = _7021;
    }
    if (_7028)
    {
        float dC = depthMap.Load(int3(ip, 0)).x;
        float dTol = lerp(0.0013999999500811100006103515625f, 0.00449999980628490447998046875f, clamp(stLift.x, 0.0f, 1.0f));
        float3 accCol = pre * 0.699999988079071044921875f;
        float accCov = capCover * 0.699999988079071044921875f;
        float accW = 0.699999988079071044921875f;
        float _7091;
        for (int k = 0; k < 4; k++)
        {
            int2 np = clamp(ip + _7067[k], int2(0, 0), maxI);
            float4 nLift = trailMap.Load(int3(np, 0));
            if (nLift.z >= (-0.0005000000237487256526947021484375f))
            {
                continue;
            }
            if (nLift.z < (-0.00200000009499490261077880859375f))
            {
                _7091 = -nLift.z;
            }
            else
            {
                _7091 = 0.0f;
            }
            float nCov = _7091;
            float pairSnow = max(capCover, nCov);
            if (pairSnow < 0.039999999105930328369140625f)
            {
                continue;
            }
            float dN = depthMap.Load(int3(np, 0)).x;
            float dzW = 1.0f - smoothstep(0.64999997615814208984375f * dTol, dTol, abs(dN - dC));
            float matW = 1.0f - smoothstep(0.25f, 0.60000002384185791015625f, abs(nLift.x - stLift.x));
            float w = ((0.07500000298023223876953125f * dzW) * matW) * smoothstep(0.039999999105930328369140625f, 0.20000000298023223876953125f, pairSnow);
            if (w <= 9.9999997473787516355514526367188e-05f)
            {
                continue;
            }
            accCol += (source.Load(int3(np, 0)).xyz * w);
            accCov += (w * nCov);
            accW += w;
        }
        pre = accCol / accW.xxx;
        snowAct = max(snowAct, accCov / accW);
    }
    else
    {
        bool _7181;
        if (hasSpriteLayer)
        {
            _7181 = stLift.z >= (-0.0005000000237487256526947021484375f);
        }
        else
        {
            _7181 = hasSpriteLayer;
        }
        if (_7181)
        {
            float4 sp = spriteMap.Load(int3(ip, 0));
            bool _7191 = sp.w > 0.0040000001899898052215576171875f;
            bool _7197;
            if (_7191)
            {
                _7197 = sp.w < 0.9900000095367431640625f;
            }
            else
            {
                _7197 = _7191;
            }
            if (_7197)
            {
                float3 F = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                float3 param = F;
                float fFol = foliageOf(param);
                float fBlos = smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, F.z) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, F.z / max(F.y, 0.0199999995529651641845703125f));
                float fPlant = clamp(max(fFol, fBlos), 0.0f, 1.0f);
                bool hasDrift = stLift.z > 0.5f;
                float _7235;
                if (hasDrift)
                {
                    _7235 = stLift.y;
                }
                else
                {
                    _7235 = -1.0f;
                }
                float driftH = _7235;
                float coreW = 0.0f;
                float snowCovSum = 0.0f;
                float3 snowColSum = 0.0f.xxx;
                float _7312;
                float _7318;
                float _7331;
                float _7339;
                for (int oy = -2; oy <= 2; oy++)
                {
                    for (int ox = -2; ox <= 2; ox++)
                    {
                        int r2 = (ox * ox) + (oy * oy);
                        if ((r2 == 0) || (r2 > 5))
                        {
                            continue;
                        }
                        int2 np_1 = clamp(ip + int2(ox, oy), int2(0, 0), maxI);
                        float4 nLift_1 = trailMap.Load(int3(np_1, 0));
                        if (nLift_1.z >= (-0.0005000000237487256526947021484375f))
                        {
                            continue;
                        }
                        bool _7305;
                        if (hasDrift)
                        {
                            _7305 = nLift_1.y <= (driftH + 0.0599999986588954925537109375f);
                        }
                        else
                        {
                            _7305 = hasDrift;
                        }
                        if (_7305)
                        {
                            continue;
                        }
                        if (r2 == 1)
                        {
                            _7312 = 2.0f;
                        }
                        else
                        {
                            if (r2 == 2)
                            {
                                _7318 = 1.2000000476837158203125f;
                            }
                            else
                            {
                                _7318 = (r2 == 4) ? 0.550000011920928955078125f : 0.3499999940395355224609375f;
                            }
                            _7312 = _7318;
                        }
                        float w_1 = _7312;
                        if (nLift_1.x > 0.300000011920928955078125f)
                        {
                            _7331 = smoothstep(0.0500000007450580596923828125f, 0.25f, fPlant);
                        }
                        else
                        {
                            if (r2 <= 2)
                            {
                                _7339 = 1.0f - smoothstep(0.20000000298023223876953125f, 0.5f, fFol);
                            }
                            else
                            {
                                _7339 = 0.0f;
                            }
                            _7331 = _7339;
                        }
                        float matW_1 = _7331;
                        float cw = w_1 * matW_1;
                        if (cw <= 9.9999997473787516355514526367188e-05f)
                        {
                            continue;
                        }
                        coreW += cw;
                        if (nLift_1.z < (-0.00200000009499490261077880859375f))
                        {
                            float nc = -nLift_1.z;
                            float3 nCol = source.Load(int3(np_1, 0)).xyz;
                            snowCovSum += (cw * nc);
                            snowColSum += (nCol * (cw * nc));
                        }
                    }
                }
                bool _7392 = coreW > 9.9999997473787516355514526367188e-05f;
                bool _7406;
                if (_7392)
                {
                    bool _7398 = (snowCovSum > 9.9999997473787516355514526367188e-05f) || hasDrift;
                    bool _7405;
                    if (!_7398)
                    {
                        _7405 = stLift.x > 0.5f;
                    }
                    else
                    {
                        _7405 = _7398;
                    }
                    _7406 = _7405;
                }
                else
                {
                    _7406 = _7392;
                }
                if (_7406)
                {
                    float avgCov = clamp(snowCovSum / coreW, 0.0f, 1.0f);
                    bool _7422;
                    if (!hasDrift)
                    {
                        _7422 = stLift.x > 0.5f;
                    }
                    else
                    {
                        _7422 = hasDrift;
                    }
                    float3 _7423;
                    if (_7422)
                    {
                        _7423 = pre;
                    }
                    else
                    {
                        _7423 = clamp((orig - sp.xyz) / max(1.0f - sp.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                    }
                    float3 B_winter = _7423;
                    float3 param_1 = F;
                    float3 param_2 = float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f);
                    float3 param_3 = F;
                    float3 F_dull = lerp(F, recolor(param_1, param_2), ((0.37999999523162841796875f * greenOf(param_3)) * smoothstep(0.0f, 0.3499999940395355224609375f, ambient_season.y)).xxx);
                    float3 _7459;
                    if (avgCov > 0.004999999888241291046142578125f)
                    {
                        _7459 = lerp(F_dull, snowColSum / max(snowCovSum, 9.9999997473787516355514526367188e-05f).xxx, avgCov.xxx);
                    }
                    else
                    {
                        _7459 = F_dull;
                    }
                    float3 F_snow = _7459;
                    pre = (F_snow * sp.w) + (B_winter * (1.0f - sp.w));
                    float _7485;
                    if (hasDrift)
                    {
                        _7485 = 1.0f;
                    }
                    else
                    {
                        _7485 = max(snowAct, sp.w * avgCov);
                    }
                    snowAct = _7485;
                }
            }
        }
    }
    snowAct = max(snowAct, smoothstep(0.02500000037252902984619140625f, 0.14000000059604644775390625f, length(pre - orig)));
    return float4(pre, clamp(snowAct, 0.0f, 1.0f));
}

float snowLuma(float3 c)
{
    return sqrt(max(dot(c, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)), 0.0f));
}

float4 positionAt(float2 pixel)
{
    int2 ip = clamp(int2(floor(pixel)), int2(0, 0), max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0)));
    float2 scene = ((float2(ip) + 0.5f.xx) - ambient_view.xy) / ambient_view.z.xx;
    float depth = depthMap.Load(int3(ip, 0)).x;
    if (depth < 1.0f)
    {
        return float4(scene, ((0.62000000476837158203125f - depth) / 0.0030000000260770320892333984375f) * 27.7128124237060546875f, 0.0f);
    }
    float ground = groundMap.Load(int3(ip, 0)).x;
    if (ground < 1.0f)
    {
        return float4(scene, (((0.62000000476837158203125f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f, 0.5f);
    }
    return float4(scene, -100000.0f, 1.0f);
}

float3 lotPoint(float2 scene, float key, bool terrain, float2 frame)
{
    float2 local = scene - frame;
    float _302;
    if (terrain)
    {
        _302 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _302 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _302;
    float _326;
    if (terrain)
    {
        _326 = key;
    }
    else
    {
        _326 = key - (0.800000011920928955078125f * h);
    }
    float s = _326;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

int indoorBandH(int2 size)
{
    if (size.x <= 1)
    {
        return max(1, (size.y / 10));
    }
    int orient = int(ambient_clouds.z + 0.5f);
    int _532;
    if ((orient & 1) == 0)
    {
        _532 = int(ambient_drift.w + 0.5f);
    }
    else
    {
        _532 = int(ambient_drift.z + 0.5f);
    }
    int hTiles = _532;
    int margin = int(ambient_frame.w + 0.5f);
    int _554;
    if (hTiles > 0)
    {
        _554 = hTiles + (2 * margin);
    }
    else
    {
        _554 = size.x;
    }
    return _554;
}

int maskCatFast(int2 at, int cat, int row, int2 size, int bandH, int stories)
{
    bool _592 = (row < 0) || (row >= stories);
    bool _599;
    if (!_592)
    {
        _599 = at.x < 0;
    }
    else
    {
        _599 = _592;
    }
    bool _606;
    if (!_599)
    {
        _606 = at.y < 0;
    }
    else
    {
        _606 = _599;
    }
    bool _615;
    if (!_606)
    {
        _615 = at.x >= size.x;
    }
    else
    {
        _615 = _606;
    }
    bool _623;
    if (!_615)
    {
        _623 = at.y >= bandH;
    }
    else
    {
        _623 = _615;
    }
    if (_623)
    {
        return 0;
    }
    int band = (cat * stories) + row;
    bool _634 = band < 0;
    bool _645;
    if (!_634)
    {
        _645 = ((band + 1) * bandH) > size.y;
    }
    else
    {
        _645 = _634;
    }
    if (_645)
    {
        return 0;
    }
    return int((indoorMap.Load(int3(int2(at.x, at.y + (band * bandH)), 0)).x * 255.0f) + 0.5f);
}

float indoors(float3 lot)
{
    uint _702_dummy_parameter;
    int2 mSize = int2(spvTextureSize(indoorMap, uint(0), _702_dummy_parameter));
    int2 param = mSize;
    int bandH = indoorBandH(param);
    int stories = max(1, (mSize.y / max(1, (5 * bandH))));
    float2 cell = (lot.xy + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.20000000298023223876953125f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _755;
    float _768;
    float2 _882;
    float2 _890;
    for (int i = 0; i < 4; i++)
    {
        if ((i & 1) == 1)
        {
            _755 = f.x;
        }
        else
        {
            _755 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _768 = f.y;
        }
        else
        {
            _768 = 1.0f - f.y;
        }
        float weight = _755 * _768;
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 1;
        int param_3 = 0;
        int2 param_4 = mSize;
        int param_5 = bandH;
        int param_6 = stories;
        int baseCode = maskCatFast(param_1, param_2, param_3, param_4, param_5, param_6);
        if (baseCode == 0)
        {
            continue;
        }
        float ground = ambient_contact.w + (float(baseCode - 1) / 8.0f);
        if (lot.z > ((ground + (float(stories) * 2.9500000476837158203125f)) - 0.100000001490116119384765625f))
        {
            continue;
        }
        int row = clamp(int(floor(((lot.z - ground) + 0.099899999797344207763671875f) / 2.9500000476837158203125f)), 0, stories - 1);
        int2 param_7 = at;
        int param_8 = 0;
        int param_9 = row;
        int2 param_10 = mSize;
        int param_11 = bandH;
        int param_12 = stories;
        if (maskCatFast(param_7, param_8, param_9, param_10, param_11, param_12) < 2)
        {
            continue;
        }
        int2 param_13 = at;
        int param_14 = 2;
        int param_15 = row;
        int2 param_16 = mSize;
        int param_17 = bandH;
        int param_18 = stories;
        int part = maskCatFast(param_13, param_14, param_15, param_16, param_17, param_18) & 7;
        if (part == 0)
        {
            sum += weight;
            continue;
        }
        if (part == 1)
        {
            _882 = float2(1.0f, -1.0f);
        }
        else
        {
            if (part == 2)
            {
                _890 = float2(-1.0f, 1.0f);
            }
            else
            {
                bool2 _900 = (part == 3).xx;
                _890 = float2(_900.x ? (-1.0f).xx.x : 1.0f.xx.x, _900.y ? (-1.0f).xx.y : 1.0f.xx.y);
            }
            _882 = _890;
        }
        float2 toward = _882;
        sum += (weight * smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((lot.xy + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward)));
    }
    return sum;
}

float architecturalExposure(float3 _point)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1037;
    if (orientation == 1)
    {
        _1037 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1051;
        if (orientation == 2)
        {
            _1051 = size - _point.xy;
        }
        else
        {
            float2 _1061;
            if (orientation == 3)
            {
                _1061 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1061 = _point.xy;
            }
            _1051 = _1061;
        }
        _1037 = _1051;
    }
    float2 source_1 = _1037;
    bool _1081 = any(bool2(source_1.x < 0.0f.xx.x, source_1.y < 0.0f.xx.y));
    bool _1089;
    if (!_1081)
    {
        _1089 = any(bool2(source_1.x >= size.x, source_1.y >= size.y));
    }
    else
    {
        _1089 = _1081;
    }
    if (_1089)
    {
        return 1.0f;
    }
    uint _1097_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1097_dummy_parameter));
    bool _1104 = mapSize.y >= (mapSize.x * 2);
    bool _1110;
    if (_1104)
    {
        _1110 = mapSize.x > 1;
    }
    else
    {
        _1110 = _1104;
    }
    bool hasBand1 = _1110;
    int2 _1113;
    if (hasBand1)
    {
        _1113 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1113 = mapSize;
    }
    int2 baseSize = _1113;
    float2 texelsPerTile = float2(baseSize) / max(size, 1.0f.xx);
    int2 at = int2(floor(source_1 * texelsPerTile));
    if (any(bool2(at.x >= baseSize.x, at.y >= baseSize.y)))
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
    if (story < 0)
    {
        return 1.0f;
    }
    if (hasBand1)
    {
        if (story > 15)
        {
            return 1.0f;
        }
        int4 b1 = int4((overheadMap.Load(int3(int2(at.x, at.y + baseSize.y), 0)) * 255.0f) + 0.5f.xxxx);
        int covered16 = b1.x | (b1.y << 8);
        return ((covered16 & (1 << story)) != 0) ? 0.0f : 1.0f;
    }
    if (story > 4)
    {
        return 1.0f;
    }
    return ((data.x & (1 << story)) != 0) ? 0.0f : 1.0f;
}

float2 lotSource(float2 camera)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _984;
    if (orientation == 1)
    {
        _984 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _998;
        if (orientation == 2)
        {
            _998 = size - camera;
        }
        else
        {
            float2 _1007;
            if (orientation == 3)
            {
                _1007 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _1007 = camera;
            }
            _998 = _1007;
        }
        _984 = _998;
    }
    return _984;
}

float pondWaterOf(float3 c)
{
    return (smoothstep(1.17999994754791259765625f, 1.64999997615814208984375f, c.z / max(c.x, 0.0007999999797903001308441162109375f)) * smoothstep(0.920000016689300537109375f, 1.2200000286102294921875f, c.z / max(c.y, 0.0007999999797903001308441162109375f))) * smoothstep(0.0030000000260770320892333984375f, 0.00999999977648258209228515625f, c.z);
}

float topAt(float2 at)
{
    uint _1536_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _1536_dummy_parameter)));
    return (0.5f - heightMap.Sample(_heightMap_sampler, ((at + ambient_frame.w.xx) * ambient_frame.z) / gridSize).x) * 128.0f;
}

float3 srgbToLinear(float3 c)
{
    return lerp(c / 12.9200000762939453125f.xxx, pow((c + 0.054999999701976776123046875f.xxx) / 1.05499994754791259765625f.xxx, 2.400000095367431640625f.xxx), step(0.040449999272823333740234375f.xxx, c));
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

float groundAt(float2 pixel)
{
    int2 ip = clamp(int2(floor(pixel)), int2(0, 0), max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0)));
    float ground = groundMap.Load(int3(ip, 0)).x;
    float _497;
    if (ground < 1.0f)
    {
        _497 = (((0.62000000476837158203125f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f;
    }
    else
    {
        _497 = -100000.0f;
    }
    return _497;
}

float terrainBaseClamped(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    bool _1387 = size.x <= 0.0f;
    bool _1394;
    if (!_1387)
    {
        _1394 = size.y <= 0.0f;
    }
    else
    {
        _1394 = _1387;
    }
    if (_1394)
    {
        return fallback;
    }
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1407;
    if (orientation == 1)
    {
        _1407 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1421;
        if (orientation == 2)
        {
            _1421 = size - _point;
        }
        else
        {
            float2 _1430;
            if (orientation == 3)
            {
                _1430 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1430 = _point;
            }
            _1421 = _1430;
        }
        _1407 = _1421;
    }
    float2 source_1 = _1407;
    uint _1449_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1449_dummy_parameter));
    bool _1456 = mapSize.y >= (mapSize.x * 2);
    bool _1462;
    if (_1456)
    {
        _1462 = mapSize.x > 1;
    }
    else
    {
        _1462 = _1456;
    }
    int2 _1463;
    if (_1462)
    {
        _1463 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1463 = mapSize;
    }
    int2 baseSize = _1463;
    if (baseSize.x <= 1)
    {
        return fallback;
    }
    float2 clamped = clamp(source_1, 0.0f.xx, max(size - 0.001000000047497451305389404296875f.xx, 0.0f.xx));
    float2 texelsPerTile = float2(baseSize) / max(size, 1.0f.xx);
    int2 at = clamp(int2(floor(clamped * texelsPerTile)), int2(0, 0), baseSize - int2(1, 1));
    int4 data = int4((overheadMap.Load(int3(at, 0)) * 255.0f) + 0.5f.xxxx);
    if (data.w == 0)
    {
        return fallback;
    }
    return float(((data.y * 256) + data.z) - 32768) / 256.0f;
}

float terrainBaseAt(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1252;
    if (orientation == 1)
    {
        _1252 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1266;
        if (orientation == 2)
        {
            _1266 = size - _point;
        }
        else
        {
            float2 _1275;
            if (orientation == 3)
            {
                _1275 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1275 = _point;
            }
            _1266 = _1275;
        }
        _1252 = _1266;
    }
    float2 source_1 = _1252;
    bool _1293 = any(bool2(source_1.x < 0.0f.xx.x, source_1.y < 0.0f.xx.y));
    bool _1301;
    if (!_1293)
    {
        _1301 = any(bool2(source_1.x >= size.x, source_1.y >= size.y));
    }
    else
    {
        _1301 = _1293;
    }
    if (_1301)
    {
        return fallback;
    }
    uint _1309_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1309_dummy_parameter));
    bool _1316 = mapSize.y >= (mapSize.x * 2);
    bool _1322;
    if (_1316)
    {
        _1322 = mapSize.x > 1;
    }
    else
    {
        _1322 = _1316;
    }
    int2 _1323;
    if (_1322)
    {
        _1323 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1323 = mapSize;
    }
    int2 baseSize = _1323;
    float2 texelsPerTile = float2(baseSize) / max(size, 1.0f.xx);
    int2 at = int2(floor(source_1 * texelsPerTile));
    if (any(bool2(at.x >= baseSize.x, at.y >= baseSize.y)))
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

float4 sampleFloraTex(Texture2D<float4> tex, SamplerState _tex_sampler, float2 lotPt, float texels, float2 margin, inout float speciesLumRef)
{
    uint _1688_dummy_parameter;
    int2 size = int2(spvTextureSize(tex, uint(0), _1688_dummy_parameter));
    if (size.x < 4)
    {
        speciesLumRef = 0.0f;
        return 0.0f.xxxx;
    }
    float2 texel = ((lotPt + margin) * texels) - 0.5f.xx;
    bool _1706 = texel.x < (-0.5f);
    bool _1713;
    if (!_1706)
    {
        _1713 = texel.y < (-0.5f);
    }
    else
    {
        _1713 = _1706;
    }
    bool _1724;
    if (!_1713)
    {
        _1724 = texel.x > (float(size.x) - 0.5f);
    }
    else
    {
        _1724 = _1713;
    }
    bool _1735;
    if (!_1724)
    {
        _1735 = texel.y > (float(size.y) - 0.5f);
    }
    else
    {
        _1735 = _1724;
    }
    if (_1735)
    {
        speciesLumRef = 0.0f;
        return 0.0f.xxxx;
    }
    int2 base = int2(floor(texel));
    float2 f = texel - float2(base);
    float keepGreen = 0.0f;
    float drop = 0.0f;
    float hueSum = 0.0f;
    float lumSum = 0.0f;
    float hueW = 0.0f;
    float _1777;
    float _1790;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(base + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        if ((i & 1) == 1)
        {
            _1777 = f.x;
        }
        else
        {
            _1777 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1790 = f.y;
        }
        else
        {
            _1790 = 1.0f - f.y;
        }
        float w = _1777 * _1790;
        float4 tap = tex.Load(int3(c, 0));
        keepGreen += (tap.x * w);
        drop += (tap.y * w);
        if (tap.z > 0.039999999105930328369140625f)
        {
            hueSum += (tap.z * w);
            lumSum += (tap.w * w);
            hueW += w;
        }
    }
    float _1846;
    if (hueW > 9.9999997473787516355514526367188e-05f)
    {
        _1846 = hueSum / hueW;
    }
    else
    {
        _1846 = 0.0f;
    }
    float hue = _1846;
    float _1856;
    if (hueW > 9.9999997473787516355514526367188e-05f)
    {
        _1856 = lerp(0.0199999995529651641845703125f, 0.14000000059604644775390625f, clamp(((lumSum / hueW) - 0.37999999523162841796875f) / 0.23999999463558197021484375f, 0.0f, 1.0f));
    }
    else
    {
        _1856 = 0.0f;
    }
    speciesLumRef = _1856;
    return float4(keepGreen, drop, hue, hueW);
}

float4 floraAt(float2 at, out float speciesLumRef)
{
    float2 param = at;
    float2 lotPt = lotSource(param);
    float2 lotSize = ambient_drift.zw;
    float2 outsideDist = max(max(-lotPt, lotPt - lotSize), 0.0f.xx);
    float outDist = max(outsideDist.x, outsideDist.y);
    uint _1904_dummy_parameter;
    int2 inSize = int2(spvTextureSize(trailMap, uint(0), _1904_dummy_parameter));
    bool _1908 = inSize.x > 4;
    bool _1919;
    if (_1908)
    {
        _1919 = abs(trailMap.Load(int3(int2(0, 0), 0)).w - 0.5f) < 0.180000007152557373046875f;
    }
    else
    {
        _1919 = _1908;
    }
    bool hasIn = _1919;
    bool _1924 = ambient_prevView.w > 0.5f;
    bool _1930;
    if (_1924)
    {
        _1930 = ambient_prevView.x > 0.0f;
    }
    else
    {
        _1930 = _1924;
    }
    bool _1939;
    if (_1930)
    {
        uint _1936_dummy_parameter;
        _1939 = int2(spvTextureSize(outFloraMap, uint(0), _1936_dummy_parameter)).x > 4;
    }
    else
    {
        _1939 = _1930;
    }
    bool hasOut = _1939;
    bool _1949;
    if (hasIn)
    {
        _1949 = (!hasOut) || (outDist <= 0.550000011920928955078125f);
    }
    else
    {
        _1949 = hasIn;
    }
    if (_1949)
    {
        float2 param_1 = lotPt;
        float param_2 = 32.0f;
        float2 param_3 = 1.0f.xx;
        float param_4;
        float4 _1957 = sampleFloraTex(trailMap, _trailMap_sampler, param_1, param_2, param_3, param_4);
        speciesLumRef = param_4;
        return _1957;
    }
    bool _1969;
    if (hasOut)
    {
        _1969 = (!hasIn) || (outDist >= 0.920000016689300537109375f);
    }
    else
    {
        _1969 = hasOut;
    }
    if (_1969)
    {
        float2 param_5 = lotPt;
        float param_6 = ambient_prevView.x;
        float2 param_7 = ambient_prevView.yz;
        float param_8;
        float4 _1982 = sampleFloraTex(outFloraMap, _outFloraMap_sampler, param_5, param_6, param_7, param_8);
        speciesLumRef = param_8;
        return _1982;
    }
    if ((!hasIn) && (!hasOut))
    {
        speciesLumRef = 0.0f;
        return 0.0f.xxxx;
    }
    float t = smoothstep(0.550000011920928955078125f, 0.920000016689300537109375f, outDist);
    float lumIn = 0.0f;
    float lumOut = 0.0f;
    float2 param_9 = lotPt;
    float param_10 = 32.0f;
    float2 param_11 = 1.0f.xx;
    float param_12;
    float4 _2004 = sampleFloraTex(trailMap, _trailMap_sampler, param_9, param_10, param_11, param_12);
    lumIn = param_12;
    float4 fIn = _2004;
    float2 param_13 = lotPt;
    float param_14 = ambient_prevView.x;
    float2 param_15 = ambient_prevView.yz;
    float param_16;
    float4 _2017 = sampleFloraTex(outFloraMap, _outFloraMap_sampler, param_13, param_14, param_15, param_16);
    lumOut = param_16;
    float4 fOut = _2017;
    float _2024;
    if ((lumIn > 0.0f) && (lumOut > 0.0f))
    {
        _2024 = lerp(lumIn, lumOut, t);
    }
    else
    {
        _2024 = (lumOut > 0.0f) ? lumOut : lumIn;
    }
    speciesLumRef = _2024;
    bool _2041 = fIn.w > 9.9999997473787516355514526367188e-05f;
    bool _2047;
    if (_2041)
    {
        _2047 = fOut.w > 9.9999997473787516355514526367188e-05f;
    }
    else
    {
        _2047 = _2041;
    }
    float _2048;
    if (_2047)
    {
        _2048 = lerp(fIn.z, fOut.z, t);
    }
    else
    {
        float _2061;
        if (fOut.w > 9.9999997473787516355514526367188e-05f)
        {
            _2061 = fOut.z;
        }
        else
        {
            _2061 = fIn.z;
        }
        _2048 = _2061;
    }
    float hue = _2048;
    return float4(lerp(fIn.x, fOut.x, t), lerp(fIn.y, fOut.y, t), hue, lerp(fIn.w, fOut.w, t));
}

float3 autumnRamp5(float3 c0, float3 c1, float3 c2, float3 c3, float3 c4, float s)
{
    float3 _3767;
    if (s < 0.25f)
    {
        _3767 = lerp(c0, c1, (s / 0.25f).xxx);
    }
    else
    {
        float3 _3780;
        if (s < 0.519999980926513671875f)
        {
            _3780 = lerp(c1, c2, ((s - 0.25f) / 0.2700000107288360595703125f).xxx);
        }
        else
        {
            float3 _3795;
            if (s < 0.7799999713897705078125f)
            {
                _3795 = lerp(c2, c3, ((s - 0.519999980926513671875f) / 0.2599999904632568359375f).xxx);
            }
            else
            {
                _3795 = lerp(c3, c4, ((s - 0.7799999713897705078125f) / 0.2199999988079071044921875f).xxx);
            }
            _3780 = _3795;
        }
        _3767 = _3780;
    }
    return _3767;
}

float3 makinMagicTreeSrgb(float sunlitT, float familyHue)
{
    float s = clamp(sunlitT, 0.0f, 1.0f);
    float h = clamp(familyHue, 0.0f, 1.0f);
    float3 param = float3(0.324999988079071044921875f, 0.24699999392032623291015625f, 0.078000001609325408935546875f);
    float3 param_1 = float3(0.579999983310699462890625f, 0.4510000050067901611328125f, 0.1369999945163726806640625f);
    float3 param_2 = float3(0.808000028133392333984375f, 0.6349999904632568359375f, 0.180000007152557373046875f);
    float3 param_3 = float3(0.925000011920928955078125f, 0.783999979496002197265625f, 0.250999987125396728515625f);
    float3 param_4 = float3(0.984000027179718017578125f, 0.882000029087066650390625f, 0.3490000069141387939453125f);
    float param_5 = s;
    float3 goldColor = autumnRamp5(param, param_1, param_2, param_3, param_4, param_5);
    float3 param_6 = float3(0.3490000069141387939453125f, 0.1689999997615814208984375f, 0.046999998390674591064453125f);
    float3 param_7 = float3(0.62000000476837158203125f, 0.3059999942779541015625f, 0.07500000298023223876953125f);
    float3 param_8 = float3(0.8389999866485595703125f, 0.45899999141693115234375f, 0.125f);
    float3 param_9 = float3(0.94900000095367431640625f, 0.611999988555908203125f, 0.180000007152557373046875f);
    float3 param_10 = float3(0.984000027179718017578125f, 0.768999993801116943359375f, 0.250999987125396728515625f);
    float param_11 = s;
    float3 tangerineColor = autumnRamp5(param_6, param_7, param_8, param_9, param_10, param_11);
    float3 param_12 = float3(0.3059999942779541015625f, 0.086000002920627593994140625f, 0.02700000070035457611083984375f);
    float3 param_13 = float3(0.537000000476837158203125f, 0.14499999582767486572265625f, 0.046999998390674591064453125f);
    float3 param_14 = float3(0.74500000476837158203125f, 0.2240000069141387939453125f, 0.07500000298023223876953125f);
    float3 param_15 = float3(0.893999993801116943359375f, 0.352999985218048095703125f, 0.1180000007152557373046875f);
    float3 param_16 = float3(0.964999973773956298828125f, 0.52499997615814208984375f, 0.180000007152557373046875f);
    float param_17 = s;
    float3 scarletColor = autumnRamp5(param_12, param_13, param_14, param_15, param_16, param_17);
    float3 param_18 = float3(0.25499999523162841796875f, 0.08200000226497650146484375f, 0.0900000035762786865234375f);
    float3 param_19 = float3(0.412000000476837158203125f, 0.16099999845027923583984375f, 0.1689999997615814208984375f);
    float3 param_20 = float3(0.56099998950958251953125f, 0.2389999926090240478515625f, 0.24699999392032623291015625f);
    float3 param_21 = float3(0.70599997043609619140625f, 0.3449999988079071044921875f, 0.352999985218048095703125f);
    float3 param_22 = float3(0.834999978542327880859375f, 0.46700000762939453125f, 0.4749999940395355224609375f);
    float param_23 = s;
    float3 burgundyColor = autumnRamp5(param_18, param_19, param_20, param_21, param_22, param_23);
    if (h < 0.3400000035762786865234375f)
    {
        return lerp(goldColor, tangerineColor, (h / 0.3400000035762786865234375f).xxx);
    }
    if (h < 0.699999988079071044921875f)
    {
        return lerp(tangerineColor, scarletColor, ((h - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
    }
    return lerp(scarletColor, burgundyColor, ((h - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
}

float3 applyAutumnFoliage(float3 col, float3 here, float fallbackBaseZ, float2 lot, float amount, float outdoor, bool sim, bool mapped, bool hasLiveFloraMap, out float outFolAct)
{
    outFolAct = 0.0f;
    float lum = dot(col, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float denom = max(col.y, 0.00200000009499490261077880859375f);
    float blueDrop = (col.y - col.z) / denom;
    float greenVsRed = (col.y - col.x) / denom;
    float keepGreen = 0.0f;
    float explicitDeciduous = 0.0f;
    float stampedLumRef = 0.0f;
    float2 param = (lot * 0.23999999463558197021484375f) + 7.30000019073486328125f.xx;
    float speciesHue = 0.14000000059604644775390625f + (0.7599999904632568359375f * valueNoise(param));
    float _4719;
    if (mapped)
    {
        float2 param_1 = here.xy;
        float param_2 = fallbackBaseZ;
        _4719 = here.z - terrainBaseAt(param_1, param_2);
    }
    else
    {
        _4719 = here.z;
    }
    float relZ = _4719;
    if (hasLiveFloraMap)
    {
        float2 param_3 = here.xy;
        float param_4;
        float4 _4743 = floraAt(param_3, param_4);
        stampedLumRef = param_4;
        float4 flora = _4743;
        float lowBlock = smoothstep(0.2199999988079071044921875f, 0.4600000083446502685546875f, flora.x);
        float tallBlock = smoothstep(0.699999988079071044921875f, 0.87999999523162841796875f, flora.x);
        keepGreen = lerp(lowBlock, tallBlock, smoothstep(1.25f, 1.64999997615814208984375f, relZ));
        explicitDeciduous = clamp(flora.w * 2.5f, 0.0f, 1.0f);
        speciesHue = lerp(speciesHue, flora.z, explicitDeciduous);
    }
    float strictFoliage = smoothstep(0.20000000298023223876953125f, 0.5f, blueDrop) * smoothstep(-0.2199999988079071044921875f, 0.0599999986588954925537109375f, greenVsRed);
    float coolLeafFoliage = smoothstep(0.119999997317790985107421875f, 0.3400000035762786865234375f, blueDrop) * smoothstep(0.07999999821186065673828125f, 0.2599999904632568359375f, greenVsRed);
    float foliageGreen = lerp(strictFoliage, max(strictFoliage, coolLeafFoliage), explicitDeciduous);
    float _4792;
    if (hasLiveFloraMap)
    {
        _4792 = explicitDeciduous;
    }
    else
    {
        _4792 = smoothstep(0.14000000059604644775390625f, 0.319999992847442626953125f, relZ);
    }
    float isDeciduous = (1.0f - keepGreen) * _4792;
    float isCanopy = smoothstep(0.85000002384185791015625f, 1.4500000476837158203125f, relZ);
    float defaultLumRef = lerp(0.075999997556209564208984375f, 0.03599999845027923583984375f, isCanopy);
    float _4815;
    if (hasLiveFloraMap && (stampedLumRef > 0.004999999888241291046142578125f))
    {
        _4815 = lerp(defaultLumRef, stampedLumRef, explicitDeciduous);
    }
    else
    {
        _4815 = defaultLumRef;
    }
    float lumRef = _4815;
    float u = lum / max(lumRef, 0.017999999225139617919921875f);
    float sunlit = (0.86000001430511474609375f * smoothstep(0.1599999964237213134765625f, 1.9500000476837158203125f, u)) + (0.14000000059604644775390625f * clamp(u / 2.349999904632568359375f, 0.0f, 1.0f));
    float2 param_5 = ((lot * 5.5f) + float2(here.z * 3.099999904632568359375f, (-here.z) * 2.400000095367431640625f)) + 19.1000003814697265625f.xx;
    float leafDetail = valueNoise(param_5);
    float2 param_6 = ((lot * 2.2999999523162841796875f) + float2(relZ * 1.89999997615814208984375f, (-relZ) * 1.5f)) + 5.69999980926513671875f.xx;
    float2 param_7 = ((lot * 5.19999980926513671875f) - float2(relZ * 2.7000000476837158203125f, relZ * 2.099999904632568359375f)) + 31.3999996185302734375f.xx;
    float boughCluster = (valueNoise(param_6) * 0.64999997615814208984375f) + (valueNoise(param_7) * 0.3499999940395355224609375f);
    float sunlitT = clamp(((0.0500000007450580596923828125f + (0.87999999523162841796875f * sunlit)) + (0.0900000035762786865234375f * (leafDetail - 0.5f))) + (0.039999999105930328369140625f * (amount - 0.5f)), 0.0f, 1.0f);
    float evergreenWarm = ((((sim ? 0.0f : strictFoliage) * keepGreen) * outdoor) * smoothstep(0.07999999821186065673828125f, 0.699999988079071044921875f, amount)) * (0.14000000059604644775390625f + (0.1599999964237213134765625f * leafDetail));
    float turned = (((sim ? 0.0f : foliageGreen) * isDeciduous) * outdoor) * smoothstep(0.039999999105930328369140625f + (0.0599999986588954925537109375f * (1.0f - sunlit)), 0.2199999988079071044921875f + (0.07999999821186065673828125f * (1.0f - sunlit)), amount);
    float _4948;
    if ((!sim) && hasLiveFloraMap)
    {
        _4948 = (isDeciduous * outdoor) * smoothstep(0.3499999940395355224609375f, 0.85000002384185791015625f, relZ);
    }
    else
    {
        _4948 = 0.0f;
    }
    float decBranch = _4948;
    outFolAct = max(max(turned, evergreenWarm), decBranch);
    if ((turned <= 0.004999999888241291046142578125f) && (evergreenWarm <= 0.004999999888241291046142578125f))
    {
        return col;
    }
    float3 _4976;
    if (evergreenWarm > 0.004999999888241291046142578125f)
    {
        float3 param_8 = col;
        float3 param_9 = float3(0.4799999892711639404296875f, 0.439999997615814208984375f, 0.14000000059604644775390625f);
        _4976 = lerp(col, recolor(param_8, param_9), evergreenWarm.xxx);
    }
    else
    {
        _4976 = col;
    }
    float3 baseCol = _4976;
    if (turned <= 0.004999999888241291046142578125f)
    {
        return baseCol;
    }
    float localHue = speciesHue;
    if (speciesHue >= 0.769999980926513671875f)
    {
        float burgShift = ((boughCluster - 0.5f) * 0.119999997317790985107421875f) + ((leafDetail - 0.5f) * 0.0599999986588954925537109375f);
        localHue = clamp((0.7599999904632568359375f + ((speciesHue - 0.769999980926513671875f) * 1.14999997615814208984375f)) + burgShift, 0.75f, 1.0f);
    }
    else
    {
        if (isCanopy > 0.3499999940395355224609375f)
        {
            float spellWeight = smoothstep(0.180000007152557373046875f, 0.36000001430511474609375f, speciesHue);
            float crownGold = (((smoothstep(1.85000002384185791015625f, 3.150000095367431640625f, relZ) * 0.519999980926513671875f) + (sunlit * 0.4799999892711639404296875f)) * 0.23999999463558197021484375f) * spellWeight;
            float boughBlaze = (0.540000021457672119140625f - boughCluster) * lerp(0.180000007152557373046875f, 0.4600000083446502685546875f, spellWeight);
            localHue = clamp(((speciesHue - crownGold) + boughBlaze) + ((leafDetail - 0.5f) * 0.0599999986588954925537109375f), 0.0199999995529651641845703125f, 0.689999997615814208984375f);
        }
        else
        {
            float tipFlare = smoothstep(0.4799999892711639404296875f, 0.86000001430511474609375f, (leafDetail * 0.62000000476837158203125f) + (sunlit * 0.37999999523162841796875f)) * (1.0f - smoothstep(0.439999997615814208984375f, 0.680000007152557373046875f, speciesHue));
            float shrubVar = (boughCluster - 0.5f) * 0.1599999964237213134765625f;
            localHue = clamp((speciesHue + (0.300000011920928955078125f * tipFlare)) + shrubVar, 0.039999999105930328369140625f, 0.689999997615814208984375f);
        }
    }
    float param_10 = sunlitT;
    float param_11 = localHue;
    float3 param_12 = makinMagicTreeSrgb(param_10, param_11);
    float3 turnedColor = srgbToLinear(param_12);
    float darkCrevice = lerp(0.4000000059604644775390625f, 1.0f, smoothstep(0.02999999932944774627685546875f, 0.3400000035762786865234375f, u));
    float brightSpark = 1.0f + (0.119999997317790985107421875f * clamp(u - 1.64999997615814208984375f, 0.0f, 1.14999997615814208984375f));
    turnedColor *= (darkCrevice * brightSpark);
    float peak = max(turnedColor.x, max(turnedColor.y, turnedColor.z));
    if (peak > 1.0f)
    {
        turnedColor /= peak.xxx;
    }
    float blend = lerp(0.939999997615814208984375f, 0.99500000476837158203125f, sunlit);
    return lerp(baseCol, turnedColor, (turned * blend).xxx);
}

int maskCatAt(int2 at, int cat, int row)
{
    uint _671_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _671_dummy_parameter));
    int2 param = size;
    int bandH = indoorBandH(param);
    int stories = max(1, (size.y / max(1, (5 * bandH))));
    int2 param_1 = at;
    int param_2 = cat;
    int param_3 = row;
    int2 param_4 = size;
    int param_5 = bandH;
    int param_6 = stories;
    return maskCatFast(param_1, param_2, param_3, param_4, param_5, param_6);
}

float pavedAt(inout float2 q)
{
    float2 param = q;
    float2 sourcePoint = lotSource(param);
    bool _2100 = any(bool2(sourcePoint.x < 1.0f.xx.x, sourcePoint.y < 1.0f.xx.y));
    bool _2112;
    if (!_2100)
    {
        float2 _2109 = ambient_drift.zw - 1.0f.xx;
        _2112 = any(bool2(sourcePoint.x > _2109.x, sourcePoint.y > _2109.y));
    }
    else
    {
        _2112 = _2100;
    }
    bool scenery = _2112;
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
    float _2275;
    float _2288;
    float2 _2309;
    float2 _2315;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 1;
        int param_3 = 0;
        bool _2208 = maskCatAt(param_1, param_2, param_3) == 0;
        bool _2218;
        if (!_2208)
        {
            int2 param_4 = at;
            int param_5 = 0;
            int param_6 = 0;
            _2218 = maskCatAt(param_4, param_5, param_6) >= 2;
        }
        else
        {
            _2218 = _2208;
        }
        if (_2218)
        {
            continue;
        }
        int2 param_7 = at;
        int param_8 = 2;
        int param_9 = 0;
        int f4 = maskCatAt(param_7, param_8, param_9);
        if ((f4 & 160) != 0)
        {
            continue;
        }
        if (scenery)
        {
            bool street = true;
            for (int k = 0; (k < reach) && street; k++)
            {
                int2 param_10 = at + (inward * k.xx);
                int param_11 = 2;
                int param_12 = 0;
                street = (maskCatAt(param_10, param_11, param_12) & 64) != 0;
            }
            if (!street)
            {
                continue;
            }
        }
        if ((i & 1) == 1)
        {
            _2275 = f.x;
        }
        else
        {
            _2275 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _2288 = f.y;
        }
        else
        {
            _2288 = 1.0f - f.y;
        }
        float weight = _2275 * _2288;
        int part = f4 & 7;
        if (part != 0)
        {
            if (part == 1)
            {
                _2309 = float2(1.0f, -1.0f);
            }
            else
            {
                if (part == 2)
                {
                    _2315 = float2(-1.0f, 1.0f);
                }
                else
                {
                    bool2 _2321 = (part == 3).xx;
                    _2315 = float2(_2321.x ? (-1.0f).xx.x : 1.0f.xx.x, _2321.y ? (-1.0f).xx.y : 1.0f.xx.y);
                }
                _2309 = _2315;
            }
            float2 toward = _2309;
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
    bool _2355 = any(bool2(sourcePoint.x < 0.5f.xx.x, sourcePoint.y < 0.5f.xx.y));
    bool _2367;
    if (!_2355)
    {
        float2 _2364 = ambient_drift.zw - 0.5f.xx;
        _2367 = any(bool2(sourcePoint.x > _2364.x, sourcePoint.y > _2364.y));
    }
    else
    {
        _2367 = _2355;
    }
    if (_2367)
    {
        return 0.0f;
    }
    float2 cell = (q + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.4000000059604644775390625f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _2445;
    float _2458;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 1;
        int param_3 = 0;
        bool _2417 = maskCatAt(param_1, param_2, param_3) == 0;
        bool _2427;
        if (!_2417)
        {
            int2 param_4 = at;
            int param_5 = 0;
            int param_6 = 0;
            _2427 = maskCatAt(param_4, param_5, param_6) >= 2;
        }
        else
        {
            _2427 = _2417;
        }
        if (_2427)
        {
            continue;
        }
        int2 param_7 = at;
        int param_8 = 2;
        int param_9 = 0;
        if ((maskCatAt(param_7, param_8, param_9) & 128) == 0)
        {
            continue;
        }
        if ((i & 1) == 1)
        {
            _2445 = f.x;
        }
        else
        {
            _2445 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _2458 = f.y;
        }
        else
        {
            _2458 = 1.0f - f.y;
        }
        sum += (_2445 * _2458);
    }
    return sum;
}

float waterAt(float2 q)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    if ((orientation == 1) || (orientation == 3))
    {
        size = size.yx;
    }
    float2 edge = clamp(q, 1.5f.xx, size - 1.5f.xx);
    float2 cell = (edge + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = frac(cell);
    float sum = 0.0f;
    float _2564;
    float _2577;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param = at;
        int param_1 = 1;
        int param_2 = 0;
        bool _2536 = maskCatAt(param, param_1, param_2) == 0;
        bool _2546;
        if (!_2536)
        {
            int2 param_3 = at;
            int param_4 = 0;
            int param_5 = 0;
            _2546 = maskCatAt(param_3, param_4, param_5) >= 2;
        }
        else
        {
            _2546 = _2536;
        }
        if (_2546)
        {
            continue;
        }
        int2 param_6 = at;
        int param_7 = 2;
        int param_8 = 0;
        if ((maskCatAt(param_6, param_7, param_8) & 32) == 0)
        {
            continue;
        }
        if ((i & 1) == 1)
        {
            _2564 = f.x;
        }
        else
        {
            _2564 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _2577 = f.y;
        }
        else
        {
            _2577 = 1.0f - f.y;
        }
        sum += (_2564 * _2577);
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
    uint _3539_dummy_parameter;
    int2 size = int2(spvTextureSize(heightMap, uint(0), _3539_dummy_parameter));
    float2 t = ((q + ambient_frame.w.xx) * ambient_frame.z) - 0.5f.xx;
    int2 b = int2(floor(t));
    float peak = 0.0f;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(b + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        peak = max(peak, ((0.5f - heightMap.Load(int3(c, 0)).x) * 128.0f) - base);
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
    bool _3653 = indoors(param_10) > 0.0500000007450580596923828125f;
    bool _3661;
    if (!_3653)
    {
        float3 param_11 = p;
        _3661 = architecturalExposure(param_11) < 0.949999988079071044921875f;
    }
    else
    {
        _3661 = _3653;
    }
    if (_3661)
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
            bool _3708 = k == 1;
            bool _3723;
            if (_3708)
            {
                float3 param_12 = np;
                bool _3714 = indoors(param_12) > 0.0500000007450580596923828125f;
                bool _3722;
                if (!_3714)
                {
                    float3 param_13 = np;
                    _3722 = architecturalExposure(param_13) < 0.949999988079071044921875f;
                }
                else
                {
                    _3722 = _3714;
                }
                _3723 = _3722;
            }
            else
            {
                _3723 = _3708;
            }
            if (_3723)
            {
                return 0.0f;
            }
            float2 param_14 = nxy;
            if ((topAt(param_14) - baseZ) <= 1.35000002384185791015625f)
            {
                connectedHigh = false;
                break;
            }
            bool _3752;
            if (connectedHigh)
            {
                float3 param_15 = np;
                bool _3743 = indoors(param_15) > 0.0500000007450580596923828125f;
                bool _3751;
                if (!_3743)
                {
                    float3 param_16 = np;
                    _3751 = architecturalExposure(param_16) < 0.949999988079071044921875f;
                }
                else
                {
                    _3751 = _3743;
                }
                _3752 = _3751;
            }
            else
            {
                _3752 = connectedHigh;
            }
            if (_3752)
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
    float h = clamp(speciesHue, 0.0f, 1.0f);
    float3 _3970;
    if (s < 0.3400000035762786865234375f)
    {
        _3970 = lerp(float3(0.944999992847442626953125f, 0.86699998378753662109375f, 0.25499999523162841796875f), float3(0.8980000019073486328125f, 0.709999978542327880859375f, 0.17299999296665191650390625f), (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _3987;
        if (s < 0.7200000286102294921875f)
        {
            _3987 = lerp(float3(0.8980000019073486328125f, 0.709999978542327880859375f, 0.17299999296665191650390625f), float3(0.834999978542327880859375f, 0.564999997615814208984375f, 0.16500000655651092529296875f), ((s - 0.3400000035762786865234375f) / 0.37999999523162841796875f).xxx);
        }
        else
        {
            _3987 = lerp(float3(0.834999978542327880859375f, 0.564999997615814208984375f, 0.16500000655651092529296875f), float3(0.68599998950958251953125f, 0.4550000131130218505859375f, 0.1410000026226043701171875f), ((s - 0.7200000286102294921875f) / 0.2800000011920928955078125f).xxx);
        }
        _3970 = _3987;
    }
    float3 goldLeaf = _3970;
    float3 _4013;
    if (s < 0.2800000011920928955078125f)
    {
        _4013 = lerp(float3(0.953000009059906005859375f, 0.834999978542327880859375f, 0.23499999940395355224609375f), float3(0.944999992847442626953125f, 0.587999999523162841796875f, 0.14499999582767486572265625f), (s / 0.2800000011920928955078125f).xxx);
    }
    else
    {
        float3 _4029;
        if (s < 0.63999998569488525390625f)
        {
            _4029 = lerp(float3(0.944999992847442626953125f, 0.587999999523162841796875f, 0.14499999582767486572265625f), float3(0.893999993801116943359375f, 0.3449999988079071044921875f, 0.097999997437000274658203125f), ((s - 0.2800000011920928955078125f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _4029 = lerp(float3(0.893999993801116943359375f, 0.3449999988079071044921875f, 0.097999997437000274658203125f), float3(0.681999981403350830078125f, 0.23499999940395355224609375f, 0.08200000226497650146484375f), ((s - 0.63999998569488525390625f) / 0.36000001430511474609375f).xxx);
        }
        _4013 = _4029;
    }
    float3 spellboundLeaf = _4013;
    float3 _4052;
    if (s < 0.319999992847442626953125f)
    {
        _4052 = lerp(float3(0.94900000095367431640625f, 0.6549999713897705078125f, 0.18400000035762786865234375f), float3(0.88999998569488525390625f, 0.3490000069141387939453125f, 0.105999998748302459716796875f), (s / 0.319999992847442626953125f).xxx);
    }
    else
    {
        float3 _4068;
        if (s < 0.699999988079071044921875f)
        {
            _4068 = lerp(float3(0.88999998569488525390625f, 0.3490000069141387939453125f, 0.105999998748302459716796875f), float3(0.757000029087066650390625f, 0.208000004291534423828125f, 0.078000001609325408935546875f), ((s - 0.319999992847442626953125f) / 0.37999999523162841796875f).xxx);
        }
        else
        {
            _4068 = lerp(float3(0.757000029087066650390625f, 0.208000004291534423828125f, 0.078000001609325408935546875f), float3(0.545000016689300537109375f, 0.14900000393390655517578125f, 0.0670000016689300537109375f), ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _4052 = _4068;
    }
    float3 scarletLeaf = _4052;
    float3 _4094;
    if (s < 0.3400000035762786865234375f)
    {
        _4094 = lerp(float3(0.819999992847442626953125f, 0.4510000050067901611328125f, 0.45899999141693115234375f), float3(0.681999981403350830078125f, 0.31400001049041748046875f, 0.324999988079071044921875f), (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _4108;
        if (s < 0.699999988079071044921875f)
        {
            _4108 = lerp(float3(0.681999981403350830078125f, 0.31400001049041748046875f, 0.324999988079071044921875f), float3(0.5490000247955322265625f, 0.2199999988079071044921875f, 0.231000006198883056640625f), ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _4108 = lerp(float3(0.5490000247955322265625f, 0.2199999988079071044921875f, 0.231000006198883056640625f), float3(0.3959999978542327880859375f, 0.14499999582767486572265625f, 0.157000005245208740234375f), ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _4094 = _4108;
    }
    float3 burgundyLeaf = _4094;
    if (h < 0.300000011920928955078125f)
    {
        return lerp(goldLeaf, spellboundLeaf, (h / 0.300000011920928955078125f).xxx);
    }
    if (h < 0.62000000476837158203125f)
    {
        return lerp(spellboundLeaf, scarletLeaf, ((h - 0.300000011920928955078125f) / 0.319999992847442626953125f).xxx);
    }
    if (h < 0.800000011920928955078125f)
    {
        return lerp(scarletLeaf, burgundyLeaf, ((h - 0.62000000476837158203125f) / 0.180000007152557373046875f).xxx);
    }
    return burgundyLeaf;
}

float3 applyAutumnGround(float3 col, float3 hereG, float2 gLot, float gPixelScale, float amount, float gOutdoor, float gSkyExposed, bool mapped, bool hasLiveFloraMap, bool leavesOnlyOnTurf)
{
    float gLum = dot(col, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float3 param = col;
    float pondWater = pondWaterOf(param);
    float gGreen = smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, (col.y - max(col.x, col.z)) / max(col.y, 0.039999999105930328369140625f)) * (1.0f - pondWater);
    float3 outCol = col;
    float _5163;
    if (mapped)
    {
        float2 param_1 = hereG.xy;
        float _5169 = pavedAt(param_1);
        _5163 = _5169;
    }
    else
    {
        _5163 = 0.0f;
    }
    float autPaved = _5163;
    float _5174;
    if (mapped)
    {
        float2 param_2 = hereG.xy;
        _5174 = cementAt(param_2);
    }
    else
    {
        _5174 = 0.0f;
    }
    float autCement = _5174;
    float _5185;
    if (mapped)
    {
        float2 param_3 = hereG.xy;
        _5185 = waterAt(param_3);
    }
    else
    {
        _5185 = 0.0f;
    }
    float autWaterTile = _5185;
    float onTurf = (gGreen * (1.0f - (0.949999988079071044921875f * autPaved))) * (1.0f - autCement);
    if (onTurf > 0.00999999977648258209228515625f)
    {
        float bladeShade = smoothstep(0.02500000037252902984619140625f, 0.12999999523162841796875f, gLum);
        float3 param_4 = float3(0.40799999237060546875f, 0.23499999940395355224609375f, 0.125f);
        float3 param_5 = float3(0.564999997615814208984375f, 0.477999985218048095703125f, 0.2199999988079071044921875f);
        float3 mmGrass = lerp(srgbToLinear(param_4), srgbToLinear(param_5), bladeShade.xxx);
        float2 param_6 = gLot;
        float mulchPatch = smoothstep(0.519999980926513671875f, 0.839999973773956298828125f, dirtField(param_6)) * amount;
        float3 param_7 = float3(0.45899999141693115234375f, 0.2939999997615814208984375f, 0.157000005245208740234375f);
        float3 mmMulch = srgbToLinear(param_7) * clamp(gLum / 0.0949999988079071044921875f, 0.449999988079071044921875f, 1.25f);
        float3 param_8 = col;
        float3 param_9 = mmGrass;
        float3 autumnTurf = lerp(recolor(param_8, param_9), mmMulch, (mulchPatch * 0.4199999868869781494140625f).xxx);
        outCol = lerp(outCol, autumnTurf, (((onTurf * gOutdoor) * gSkyExposed) * clamp(0.7200000286102294921875f * amount, 0.0f, 0.7799999713897705078125f)).xxx);
    }
    if ((autWaterTile > 0.0199999995529651641845703125f) && (pondWater < 0.85000002384185791015625f))
    {
        float warmSand = ((smoothstep(0.00999999977648258209228515625f, 0.07999999821186065673828125f, col.x - col.y) * smoothstep(0.02999999932944774627685546875f, 0.119999997317790985107421875f, col.y - col.z)) * (1.0f - pondWater)) * smoothstep(0.0199999995529651641845703125f, 0.25f, autWaterTile);
        if (warmSand > 0.00999999977648258209228515625f)
        {
            float3 param_10 = float3(0.4799999892711639404296875f, 0.3499999940395355224609375f, 0.20000000298023223876953125f);
            float3 param_11 = col;
            float3 param_12 = srgbToLinear(param_10);
            float3 autBank = lerp(recolor(param_11, param_12), col * float3(0.87999999523162841796875f, 0.800000011920928955078125f, 0.680000007152557373046875f), 0.3499999940395355224609375f.xxx);
            outCol = lerp(outCol, autBank, (((warmSand * gOutdoor) * gSkyExposed) * clamp(0.75f * amount, 0.0f, 0.800000011920928955078125f)).xxx);
        }
    }
    if (pondWater > 0.0199999995529651641845703125f)
    {
        float3 autWater = lerp(col, col * float3(0.839999973773956298828125f, 0.87999999523162841796875f, 0.920000016689300537109375f), ((clamp(0.550000011920928955078125f * amount, 0.0f, 0.550000011920928955078125f) * gOutdoor) * gSkyExposed).xxx);
        outCol = lerp(outCol, autWater, pondWater.xxx);
    }
    float notWater = (1.0f - pondWater) * (1.0f - smoothstep(0.00999999977648258209228515625f, 0.0500000007450580596923828125f, col.z - max(col.x, col.y)));
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
            float2 param_13 = hereG.xy;
            float param_14;
            float4 _5399 = floraAt(param_13, param_14);
            unusedLumRef = param_14;
            float4 flora = _5399;
            float2 param_15 = (gLot * 1.39999997615814208984375f) + 9.19999980926513671875f.xx;
            float2 param_16 = (gLot * 3.7999999523162841796875f) + 21.3999996185302734375f.xx;
            float edgeBreak = (((valueNoise(param_15) * 0.64999997615814208984375f) + (valueNoise(param_16) * 0.3499999940395355224609375f)) - 0.5f) * 0.37999999523162841796875f;
            float dropField = clamp(flora.y + (edgeBreak * smoothstep(0.0f, 0.449999988079071044921875f, flora.y)), 0.0f, 1.0f);
            innerCanopy = smoothstep(0.2599999904632568359375f, 0.800000011920928955078125f, dropField);
            outerCanopy = smoothstep(0.0199999995529651641845703125f, 0.540000021457672119140625f, dropField);
            float2 param_17 = (gLot * 0.23999999463558197021484375f) + 7.30000019073486328125f.xx;
            float defaultHue = 0.1599999964237213134765625f + (0.579999983310699462890625f * valueNoise(param_17));
            treeHue = lerp(defaultHue, flora.z, clamp(flora.w * 2.5f, 0.0f, 1.0f));
        }
        else
        {
            float2 param_18 = hereG.xy;
            float param_19 = hereG.z;
            float anyPeak = peakRiseAt(param_18, param_19);
            if (anyPeak <= 2.0499999523162841796875f)
            {
                for (int i = 0; i < 8; i++)
                {
                    float a = float(i) * 0.785398185253143310546875f;
                    float2 param_20 = hereG.xy + (float2(cos(a), sin(a)) * 1.2000000476837158203125f);
                    float param_21 = hereG.z;
                    anyPeak = max(anyPeak, peakRiseAt(param_20, param_21));
                    if (anyPeak > 2.0499999523162841796875f)
                    {
                        break;
                    }
                }
            }
            if (anyPeak > 2.0499999523162841796875f)
            {
                float2 param_22 = hereG.xy;
                float param_23 = hereG.z;
                innerCanopy = treeCrownAt(param_22, param_23);
                outerCanopy = innerCanopy * 0.7200000286102294921875f;
                for (int i_1 = 0; i_1 < 8; i_1++)
                {
                    float a_1 = float(i_1) * 0.785398185253143310546875f;
                    float2 dir = float2(cos(a_1), sin(a_1));
                    float2 param_24 = hereG.xy + (dir * 0.449999988079071044921875f);
                    float param_25 = hereG.z;
                    innerCanopy = max(innerCanopy, 0.939999997615814208984375f * treeCrownAt(param_24, param_25));
                    float2 param_26 = hereG.xy + (dir * 0.89999997615814208984375f);
                    float param_27 = hereG.z;
                    outerCanopy = max(outerCanopy, 0.560000002384185791015625f * treeCrownAt(param_26, param_27));
                }
                outerCanopy = max(outerCanopy, innerCanopy * 0.7200000286102294921875f);
                float2 param_28 = (gLot * 0.23999999463558197021484375f) + 7.30000019073486328125f.xx;
                treeHue = valueNoise(param_28);
            }
        }
        if (outerCanopy > 0.0199999995529651641845703125f)
        {
            float2 param_29 = (gLot * 2.2000000476837158203125f) + 3.7000000476837158203125f.xx;
            float2 param_30 = (gLot * 5.0f) + 11.30000019073486328125f.xx;
            float patchNoise = (valueNoise(param_29) * 0.64999997615814208984375f) + (valueNoise(param_30) * 0.3499999940395355224609375f);
            float baseLumScale = clamp(gLum / 0.100000001490116119384765625f, 0.550000011920928955078125f, 1.14999997615814208984375f) * 0.920000016689300537109375f;
            float leafWeight = (gOutdoor * gSkyExposed) * leafGround;
            float d0 = clamp(((innerCanopy * amount) * smoothstep(0.14000000059604644775390625f, 0.63999998569488525390625f, patchNoise + (0.4199999868869781494140625f * innerCanopy))) * 0.959999978542327880859375f, 0.0f, 0.959999978542327880859375f);
            float d1 = clamp(((max(innerCanopy * 0.87999999523162841796875f, outerCanopy * 0.62000000476837158203125f) * amount) * smoothstep(0.20000000298023223876953125f, 0.699999988079071044921875f, patchNoise + (0.319999992847442626953125f * outerCanopy))) * 0.86000001430511474609375f, 0.0f, 0.87999999523162841796875f);
            float d2 = clamp(((max(innerCanopy * 0.660000026226043701171875f, outerCanopy * 0.4199999868869781494140625f) * amount) * smoothstep(0.2599999904632568359375f, 0.7599999904632568359375f, patchNoise + (0.23999999463558197021484375f * outerCanopy))) * 0.680000007152557373046875f, 0.0f, 0.699999988079071044921875f);
            float2 param_31 = gLot;
            float param_32 = 7.400000095367431640625f;
            float param_33 = 0.0f;
            float param_34 = 3.099999904632568359375f;
            float param_35 = d0;
            float param_36 = 0.300000011920928955078125f;
            float param_37 = 0.4199999868869781494140625f;
            float param_38 = gPixelScale;
            float4 l0 = fallenLeafLayer(param_31, param_32, param_33, param_34, param_35, param_36, param_37, param_38);
            bool _5665 = l0.x > 0.004999999888241291046142578125f;
            bool _5672;
            if (!_5665)
            {
                _5672 = l0.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _5672 = _5665;
            }
            if (_5672)
            {
                outCol *= (1.0f - (((0.319999992847442626953125f * l0.y) * leafWeight) * (1.0f - l0.x)));
                float param_39 = l0.w;
                float param_40 = treeHue;
                float3 param_41 = fallenLeafColorSrgb(param_39, param_40);
                float3 c0 = ((srgbToLinear(param_41) * 0.7799999713897705078125f) * l0.z) * baseLumScale;
                outCol = lerp(outCol, c0, ((l0.x * leafWeight) * 0.939999997615814208984375f).xxx);
            }
            float2 param_42 = gLot;
            float param_43 = 9.3999996185302734375f;
            float param_44 = 0.670000016689300537109375f;
            float param_45 = 19.700000762939453125f;
            float param_46 = d1;
            float param_47 = 0.2800000011920928955078125f;
            float param_48 = 0.4000000059604644775390625f;
            float param_49 = gPixelScale;
            float4 l1 = fallenLeafLayer(param_42, param_43, param_44, param_45, param_46, param_47, param_48, param_49);
            bool _5728 = l1.x > 0.004999999888241291046142578125f;
            bool _5735;
            if (!_5728)
            {
                _5735 = l1.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _5735 = _5728;
            }
            if (_5735)
            {
                outCol *= (1.0f - (((0.300000011920928955078125f * l1.y) * leafWeight) * (1.0f - l1.x)));
                float param_50 = l1.w;
                float param_51 = treeHue;
                float3 param_52 = fallenLeafColorSrgb(param_50, param_51);
                float3 c1 = ((srgbToLinear(param_52) * 1.03999996185302734375f) * l1.z) * baseLumScale;
                outCol = lerp(outCol, c1, ((l1.x * leafWeight) * 0.939999997615814208984375f).xxx);
            }
            float2 param_53 = gLot;
            float param_54 = 11.6000003814697265625f;
            float param_55 = 1.309999942779541015625f;
            float param_56 = 41.299999237060546875f;
            float param_57 = d2;
            float param_58 = 0.2700000107288360595703125f;
            float param_59 = 0.37999999523162841796875f;
            float param_60 = gPixelScale;
            float4 l2 = fallenLeafLayer(param_53, param_54, param_55, param_56, param_57, param_58, param_59, param_60);
            bool _5793 = l2.x > 0.004999999888241291046142578125f;
            bool _5800;
            if (!_5793)
            {
                _5800 = l2.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _5800 = _5793;
            }
            if (_5800)
            {
                outCol *= (1.0f - (((0.2800000011920928955078125f * l2.y) * leafWeight) * (1.0f - l2.x)));
                float param_61 = l2.w;
                float param_62 = treeHue;
                float3 param_63 = fallenLeafColorSrgb(param_61, param_62);
                float3 c2 = ((srgbToLinear(param_63) * 1.17999994754791259765625f) * l2.z) * baseLumScale;
                outCol = lerp(outCol, c2, ((l2.x * leafWeight) * 0.939999997615814208984375f).xxx);
            }
        }
    }
    return outCol;
}

void evalGroundTerms(float3 c, float2 xy, float isGroundF, float vacLot, inout float isVacSnowLot, out float earthMask, out float terrainWear, inout float greenOut, out float lumOut)
{
    lumOut = dot(c, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float3 param = c;
    float pondBlue = pondWaterOf(param);
    float3 param_1 = c;
    greenOut = greenOf(param_1) * (1.0f - pondBlue);
    float _5857;
    if (isGroundF > 0.5f)
    {
        float2 param_2 = xy;
        float _5862 = pavedAt(param_2);
        _5857 = _5862;
    }
    else
    {
        _5857 = 0.0f;
    }
    float pavedHere = _5857;
    float _5868;
    if (isGroundF > 0.5f)
    {
        float2 param_3 = xy;
        _5868 = cementAt(param_3);
    }
    else
    {
        _5868 = 0.0f;
    }
    float cementHere = _5868;
    float _5879;
    if (isGroundF > 0.5f)
    {
        float2 param_4 = xy;
        _5879 = waterAt(param_4);
    }
    else
    {
        _5879 = 0.0f;
    }
    float waterHere = _5879;
    float _5899;
    if ((((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f)) && (cementHere < 0.3499999940395355224609375f)) && (waterHere < 0.100000001490116119384765625f))
    {
        _5899 = smoothstep(0.319999992847442626953125f, 0.519999980926513671875f, c.z) * smoothstep(0.00999999977648258209228515625f, 0.0500000007450580596923828125f, c.z - c.x);
    }
    else
    {
        _5899 = 0.0f;
    }
    float vacSnowBlue = _5899;
    isVacSnowLot = clamp(max(vacLot, vacSnowBlue), 0.0f, 1.0f);
    float warmOverGreen = smoothstep(-0.00999999977648258209228515625f, 0.039999999105930328369140625f, (c.x - c.y) / max(c.x, 0.0500000007450580596923828125f));
    float vacWarmth = (c.x - c.z) / max(c.x + c.z, 0.0500000007450580596923828125f);
    float naturalEarth = max(greenOut, smoothstep(0.3400000035762786865234375f, 0.519999980926513671875f, vacWarmth)) * (1.0f - pondBlue);
    earthMask = (isGroundF * clamp(max(naturalEarth, isVacSnowLot * (1.0f - pondBlue)), 0.0f, 1.0f)) * (1.0f - cementHere);
    float _5972;
    if (((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f)) && (pondBlue < 0.25f))
    {
        _5972 = (((warmOverGreen * smoothstep(0.014999999664723873138427734375f, 0.23999999463558197021484375f, vacWarmth)) * smoothstep(0.02999999932944774627685546875f, 0.100000001490116119384765625f, c.x)) * isVacSnowLot) * (1.0f - cementHere);
    }
    else
    {
        _5972 = 0.0f;
    }
    float vacDirt = _5972;
    float _6002;
    if ((((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f)) && (waterHere < 0.100000001490116119384765625f)) && (pondBlue < 0.25f))
    {
        _6002 = (((smoothstep(0.7599999904632568359375f, 1.12000000476837158203125f, c.x / max(c.y, 0.014999999664723873138427734375f)) * smoothstep(0.4199999868869781494140625f, 0.579999983310699462890625f, vacWarmth)) * smoothstep(0.014999999664723873138427734375f, 0.04500000178813934326171875f, max(c.x, c.y))) * (1.0f - isVacSnowLot)) * (1.0f - cementHere);
    }
    else
    {
        _6002 = 0.0f;
    }
    float homeWear = _6002;
    terrainWear = max(vacDirt, homeWear);
}

float snowCrust(float2 lq)
{
    float2 param = (lq * 3.599999904632568359375f) + 3.2000000476837158203125f.xx;
    float2 param_1 = (lq * 8.80000019073486328125f) + 17.3999996185302734375f.xx;
    return (valueNoise(param) * 0.64999997615814208984375f) + (valueNoise(param_1) * 0.3499999940395355224609375f);
}

float samplePondWaterTap(inout int2 ip, int2 maxI, bool hasSprite)
{
    ip = clamp(ip, int2(0, 0), maxI);
    float3 c = source.Load(int3(ip, 0)).xyz;
    if (hasSprite)
    {
        float4 sp = spriteMap.Load(int3(ip, 0));
        bool _2643 = sp.w > 0.0040000001899898052215576171875f;
        bool _2650;
        if (_2643)
        {
            _2650 = sp.w < 0.9900000095367431640625f;
        }
        else
        {
            _2650 = _2643;
        }
        if (_2650)
        {
            c = clamp((c - sp.xyz) / max(1.0f - sp.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
        }
    }
    float3 param = c;
    return pondWaterOf(param);
}

float samplePondGroundWater(float2 q, float base)
{
    float2 scene = float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * base)) + ambient_frame.xy;
    float2 px = (scene * ambient_view.z) + ambient_view.xy;
    bool _2703 = px.x < 0.5f;
    bool _2710;
    if (!_2703)
    {
        _2710 = px.y < 0.5f;
    }
    else
    {
        _2710 = _2703;
    }
    bool _2720;
    if (!_2710)
    {
        _2720 = px.x >= (ambient_extent.x - 0.5f);
    }
    else
    {
        _2720 = _2710;
    }
    bool _2730;
    if (!_2720)
    {
        _2730 = px.y >= (ambient_extent.y - 0.5f);
    }
    else
    {
        _2730 = _2720;
    }
    if (_2730)
    {
        float2 param = q;
        return smoothstep(0.550000011920928955078125f, 0.89999997615814208984375f, waterAt(param));
    }
    int2 maxI = max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0));
    int2 ip0 = clamp(int2(floor(px)), int2(0, 0), maxI);
    uint _2756_dummy_parameter;
    bool hasSprite = int2(spvTextureSize(spriteMap, uint(0), _2756_dummy_parameter)).x > 4;
    if (depthMap.Load(int3(ip0, 0)).x < 1.0f)
    {
        float stepPx = max(2.0f, 3.0f * ambient_view.z);
        float acc = 0.0f;
        float wSum = 0.0f;
        for (int k = 0; k < 4; k++)
        {
            int2 np = clamp(int2(floor(px + (_2788[k] * stepPx))), int2(0, 0), maxI);
            if (depthMap.Load(int3(np, 0)).x >= 1.0f)
            {
                int2 param_1 = np;
                int2 param_2 = maxI;
                bool param_3 = hasSprite;
                float _2815 = samplePondWaterTap(param_1, param_2, param_3);
                acc += _2815;
                wSum += 1.0f;
            }
        }
        float _2824;
        if (wSum > 0.0f)
        {
            _2824 = acc / wSum;
        }
        else
        {
            float2 param_4 = q;
            _2824 = smoothstep(0.550000011920928955078125f, 0.89999997615814208984375f, waterAt(param_4));
        }
        return _2824;
    }
    float2 t = px - 0.5f.xx;
    int2 b = int2(floor(t));
    float2 f = t - float2(b);
    float sum = 0.0f;
    float _2873;
    float _2886;
    float _2904;
    for (int i = 0; i < 4; i++)
    {
        int2 cIdx = clamp(b + int2(i & 1, i >> 1), int2(0, 0), maxI);
        if ((i & 1) == 1)
        {
            _2873 = f.x;
        }
        else
        {
            _2873 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _2886 = f.y;
        }
        else
        {
            _2886 = 1.0f - f.y;
        }
        float w = _2873 * _2886;
        if (depthMap.Load(int3(cIdx, 0)).x >= 1.0f)
        {
            int2 param_5 = cIdx;
            int2 param_6 = maxI;
            bool param_7 = hasSprite;
            float _2913 = samplePondWaterTap(param_5, param_6, param_7);
            _2904 = _2913;
        }
        else
        {
            int2 param_8 = ip0;
            int2 param_9 = maxI;
            bool param_10 = hasSprite;
            float _2921 = samplePondWaterTap(param_8, param_9, param_10);
            _2904 = _2921;
        }
        float tap = _2904;
        sum += (tap * w);
    }
    return sum;
}

float3 winterDullColor(float3 c, float3 herePt, float2 lotPt, float lumVal, float greenVal, float hereCrust, float earthMask, float terrainWear, float isVacSnowLot, float coveredVal, bool isGround, float amount)
{
    float snowPresence = smoothstep(0.0f, 0.3499999940395355224609375f, amount);
    if (isGround)
    {
        float2 xy = herePt.xy;
        float2 param = xy;
        float wTile = waterAt(param);
        float3 param_1 = c;
        float pondWater = pondWaterOf(param_1);
        if (wTile > 0.008000000379979610443115234375f)
        {
            float baseZ = herePt.z;
            float2 param_2 = xy + float2(0.054999999701976776123046875f, 0.0f);
            float param_3 = baseZ;
            float2 param_4 = xy - float2(0.054999999701976776123046875f, 0.0f);
            float param_5 = baseZ;
            float2 param_6 = xy + float2(0.0f, 0.054999999701976776123046875f);
            float param_7 = baseZ;
            float2 param_8 = xy - float2(0.0f, 0.054999999701976776123046875f);
            float param_9 = baseZ;
            float wInner = 0.25f * (((samplePondGroundWater(param_2, param_3) + samplePondGroundWater(param_4, param_5)) + samplePondGroundWater(param_6, param_7)) + samplePondGroundWater(param_8, param_9));
            float2 param_10 = xy + float2(0.115000002086162567138671875f, 0.0f);
            float param_11 = baseZ;
            float2 param_12 = xy - float2(0.115000002086162567138671875f, 0.0f);
            float param_13 = baseZ;
            float2 param_14 = xy + float2(0.0f, 0.115000002086162567138671875f);
            float param_15 = baseZ;
            float2 param_16 = xy - float2(0.0f, 0.115000002086162567138671875f);
            float param_17 = baseZ;
            float2 param_18 = xy + 0.0813049972057342529296875f.xx;
            float param_19 = baseZ;
            float2 param_20 = xy + float2(-0.0813049972057342529296875f, 0.0813049972057342529296875f);
            float param_21 = baseZ;
            float2 param_22 = xy + float2(0.0813049972057342529296875f, -0.0813049972057342529296875f);
            float param_23 = baseZ;
            float2 param_24 = xy + (-0.0813049972057342529296875f).xx;
            float param_25 = baseZ;
            float wOuter = 0.125f * (((((((samplePondGroundWater(param_10, param_11) + samplePondGroundWater(param_12, param_13)) + samplePondGroundWater(param_14, param_15)) + samplePondGroundWater(param_16, param_17)) + samplePondGroundWater(param_18, param_19)) + samplePondGroundWater(param_20, param_21)) + samplePondGroundWater(param_22, param_23)) + samplePondGroundWater(param_24, param_25));
            float2 param_26 = (lotPt * 2.400000095367431640625f) + 5.69999980926513671875f.xx;
            float2 param_27 = (lotPt * 6.80000019073486328125f) + 19.299999237060546875f.xx;
            float freezeNoise = (valueNoise(param_26) * 0.60000002384185791015625f) + (valueNoise(param_27) * 0.4000000059604644775390625f);
            float wField = (0.449999988079071044921875f * wInner) + (0.550000011920928955078125f * wOuter);
            float shoreRim = smoothstep(0.039999999105930328369140625f, 0.7799999713897705078125f, (1.0f - wField) + ((freezeNoise - 0.5f) * 0.23999999463558197021484375f));
            float ripple = clamp((lumVal - 0.039999999105930328369140625f) * 3.0f, -0.070000000298023223876953125f, 0.0900000035762786865234375f);
            float3 param_28 = float3(0.1599999964237213134765625f, 0.2800000011920928955078125f, 0.4199999868869781494140625f);
            float3 coldWater = lerp(c, srgbToLinear(param_28) * clamp(lumVal / 0.0419999994337558746337890625f, 0.64999997615814208984375f, 1.35000002384185791015625f), (0.579999983310699462890625f * snowPresence).xxx);
            float effFreeze = ((amount * (1.0f - (0.180000007152557373046875f * coveredVal))) + (0.2800000011920928955078125f * shoreRim)) + ((freezeNoise - 0.5f) * 0.1599999964237213134765625f);
            float iceSheet = smoothstep(0.1500000059604644775390625f, 0.660000026226043701171875f, effFreeze);
            float rimeCover = smoothstep(0.4199999868869781494140625f, 1.12000000476837158203125f, (effFreeze + (0.23999999463558197021484375f * shoreRim)) + ((hereCrust - 0.5f) * 0.180000007152557373046875f));
            float3 param_29 = float3(0.4600000083446502685546875f, 0.589999973773956298828125f, 0.730000019073486328125f);
            float3 blueIce = srgbToLinear(param_29) * ((0.939999997615814208984375f + ripple) + (0.10999999940395355224609375f * hereCrust));
            float3 frostRim = lerp(float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), (0.540000021457672119140625f + (0.2800000011920928955078125f * hereCrust)).xxx);
            float3 frozen = lerp(blueIce, frostRim, clamp((0.23999999463558197021484375f * rimeCover) + ((0.63999998569488525390625f * shoreRim) * smoothstep(0.180000007152557373046875f, 0.699999988079071044921875f, amount)), 0.0f, 0.89999997615814208984375f).xxx);
            float3 icedPond = lerp(coldWater, frozen, iceSheet.xxx);
            float bankMask = clamp(max(max(wInner, wOuter) * 2.2000000476837158203125f, smoothstep(0.07999999821186065673828125f, 0.36000001430511474609375f, (c.x - c.z) / max(c.x + c.z, 0.039999999105930328369140625f)) * (1.0f - greenVal)), 0.0f, 1.0f);
            float3 param_30 = float3(0.4199999868869781494140625f, 0.449999988079071044921875f, 0.4900000095367431640625f);
            float3 param_31 = c;
            float3 param_32 = srgbToLinear(param_30);
            float3 coldBank = recolor(param_31, param_32);
            float3 snowBank = lerp(float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), (0.62000000476837158203125f + (0.23999999463558197021484375f * hereCrust)).xxx);
            float3 frostedBank = lerp(coldBank, snowBank, smoothstep(0.07999999821186065673828125f, 0.4199999868869781494140625f, amount).xxx);
            float3 nonWaterCol = lerp(c, frostedBank, (bankMask * snowPresence).xxx);
            if ((pondWater > 0.00999999977648258209228515625f) || (bankMask > 0.00999999977648258209228515625f))
            {
                return lerp(nonWaterCol, icedPond, pondWater.xxx);
            }
        }
    }
    bool3 _6348 = (isGround && (isVacSnowLot < 0.5f)).xxx;
    float3 targetHue = float3(_6348.x ? float3(0.310000002384185791015625f, 0.37999999523162841796875f, 0.2800000011920928955078125f).x : float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f).x, _6348.y ? float3(0.310000002384185791015625f, 0.37999999523162841796875f, 0.2800000011920928955078125f).y : float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f).y, _6348.z ? float3(0.310000002384185791015625f, 0.37999999523162841796875f, 0.2800000011920928955078125f).z : float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f).z);
    float3 param_33 = c;
    float3 param_34 = targetHue;
    return lerp(c, recolor(param_33, param_34), ((0.37999999523162841796875f * greenVal) * snowPresence).xxx);
}

int indoorStories()
{
    uint _572_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _572_dummy_parameter));
    int2 param = size;
    int bandH = indoorBandH(param);
    return max(1, (size.y / max(1, (5 * bandH))));
}

float nearIndoorWall(float2 xy, float z, float radius)
{
    float w = 0.0f;
    float _4623;
    float _4633;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            _4623 = 1.0f;
        }
        else
        {
            _4623 = (i == 1) ? (-1.0f) : 0.0f;
        }
        if (i == 2)
        {
            _4633 = 1.0f;
        }
        else
        {
            _4633 = (i == 3) ? (-1.0f) : 0.0f;
        }
        float2 card = float2(_4623, _4633) * radius;
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
    float2 param = q + float2(0.680000007152557373046875f, 0.0f);
    float2 param_1 = q - float2(0.680000007152557373046875f, 0.0f);
    float2 param_2 = q + float2(0.0f, 0.680000007152557373046875f);
    float2 param_3 = q - float2(0.0f, 0.680000007152557373046875f);
    float2 param_4 = q + 0.4799999892711639404296875f.xx;
    float2 param_5 = q - 0.4799999892711639404296875f.xx;
    float2 param_6 = q + float2(0.4799999892711639404296875f, -0.4799999892711639404296875f);
    float2 param_7 = q - float2(0.4799999892711639404296875f, -0.4799999892711639404296875f);
    float nearCheck = max(max(max(topAt(param), topAt(param_1)), max(topAt(param_2), topAt(param_3))), max(max(topAt(param_4), topAt(param_5)), max(topAt(param_6), topAt(param_7))));
    if (nearCheck <= (base + 0.25f))
    {
        return 0.0f;
    }
    float r1 = 0.0f;
    float r2 = 0.0f;
    float r3 = 0.0f;
    for (int i = 0; i < 8; i++)
    {
        float a = float(i) * 0.785398185253143310546875f;
        float2 d = float2(cos(a), sin(a));
        float2 param_8 = q + (d * 0.180000007152557373046875f);
        r1 += smoothstep(0.3499999940395355224609375f, 1.35000002384185791015625f, topAt(param_8) - base);
        float2 param_9 = q + (d * 0.36000001430511474609375f);
        r2 += smoothstep(0.3499999940395355224609375f, 1.35000002384185791015625f, topAt(param_9) - base);
        float2 param_10 = q + (d * 0.540000021457672119140625f);
        r3 += smoothstep(0.3499999940395355224609375f, 1.35000002384185791015625f, topAt(param_10) - base);
    }
    return clamp((((r1 * 0.5f) + (r2 * 0.3499999940395355224609375f)) + (r3 * 0.1500000059604644775390625f)) / 8.0f, 0.0f, 1.0f);
}

float pondBasinKeep(float2 q, float base)
{
    float2 param = q;
    if (waterAt(param) <= 0.008000000379979610443115234375f)
    {
        return 1.0f;
    }
    float2 param_1 = q;
    float param_2 = base;
    float w0 = samplePondGroundWater(param_1, param_2);
    float2 param_3 = q + float2(0.048000000417232513427734375f, 0.0f);
    float param_4 = base;
    float2 param_5 = q - float2(0.048000000417232513427734375f, 0.0f);
    float param_6 = base;
    float2 param_7 = q + float2(0.0f, 0.048000000417232513427734375f);
    float param_8 = base;
    float2 param_9 = q - float2(0.0f, 0.048000000417232513427734375f);
    float param_10 = base;
    float wCard = 0.25f * (((samplePondGroundWater(param_3, param_4) + samplePondGroundWater(param_5, param_6)) + samplePondGroundWater(param_7, param_8)) + samplePondGroundWater(param_9, param_10));
    if ((w0 > 0.85000002384185791015625f) && (wCard > 0.800000011920928955078125f))
    {
        return 0.0f;
    }
    float2 param_11 = q + 0.0719999969005584716796875f.xx;
    float param_12 = base;
    float2 param_13 = q - 0.0719999969005584716796875f.xx;
    float param_14 = base;
    float2 param_15 = q + float2(0.0719999969005584716796875f, -0.0719999969005584716796875f);
    float param_16 = base;
    float2 param_17 = q - float2(0.0719999969005584716796875f, -0.0719999969005584716796875f);
    float param_18 = base;
    float wDiag = 0.25f * (((samplePondGroundWater(param_11, param_12) + samplePondGroundWater(param_13, param_14)) + samplePondGroundWater(param_15, param_16)) + samplePondGroundWater(param_17, param_18));
    float wSmooth = ((0.2599999904632568359375f * w0) + (0.439999997615814208984375f * wCard)) + (0.300000011920928955078125f * wDiag);
    return 1.0f - smoothstep(0.07999999821186065673828125f, 0.560000002384185791015625f, wSmooth);
}

float pressedAt(float2 at)
{
    uint _1560_dummy_parameter;
    int2 size = int2(spvTextureSize(trailMap, uint(0), _1560_dummy_parameter));
    if (size.x < 4)
    {
        return 0.0f;
    }
    float2 param = at;
    float2 texel = ((lotSource(param) + 1.0f.xx) * 32.0f) - 0.5f.xx;
    bool _1579 = texel.x < (-0.5f);
    bool _1586;
    if (!_1579)
    {
        _1586 = texel.y < (-0.5f);
    }
    else
    {
        _1586 = _1579;
    }
    bool _1597;
    if (!_1586)
    {
        _1597 = texel.x > (float(size.x) - 0.5f);
    }
    else
    {
        _1597 = _1586;
    }
    bool _1608;
    if (!_1597)
    {
        _1608 = texel.y > (float(size.y) - 0.5f);
    }
    else
    {
        _1608 = _1597;
    }
    if (_1608)
    {
        return 0.0f;
    }
    int2 base = int2(floor(texel));
    float2 f = texel - float2(base);
    float sum = 0.0f;
    float _1650;
    float _1664;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(base + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        if ((i & 1) == 1)
        {
            _1650 = f.x;
        }
        else
        {
            _1650 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1664 = f.y;
        }
        else
        {
            _1664 = 1.0f - f.y;
        }
        sum += ((trailMap.Load(int3(c, 0)).x * _1650) * _1664);
    }
    return smoothstep(0.3499999940395355224609375f, 0.64999997615814208984375f, sum);
}

float snowHeight(float2 q, float base, float full, float amount, float groundWear, float isVac)
{
    if (amount <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
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
    float overhead = smoothstep(1.10000002384185791015625f, 2.5f, max(0.0f, topAt(param_5) - base));
    float2 param_6 = q + float2(0.2800000011920928955078125f, 0.0f);
    overhead += smoothstep(1.10000002384185791015625f, 2.5f, max(0.0f, topAt(param_6) - base));
    float2 param_7 = q - float2(0.2800000011920928955078125f, 0.0f);
    overhead += smoothstep(1.10000002384185791015625f, 2.5f, max(0.0f, topAt(param_7) - base));
    float2 param_8 = q + float2(0.0f, 0.2800000011920928955078125f);
    overhead += smoothstep(1.10000002384185791015625f, 2.5f, max(0.0f, topAt(param_8) - base));
    float2 param_9 = q - float2(0.0f, 0.2800000011920928955078125f);
    overhead += smoothstep(1.10000002384185791015625f, 2.5f, max(0.0f, topAt(param_9) - base));
    overhead *= 0.20000000298023223876953125f;
    float vacWear = (isVac * groundWear) * 0.7200000286102294921875f;
    float2 wCoord = float2(dot(l, float2(0.92847669124603271484375f, 0.37139070034027099609375f)) * 0.085000000894069671630859375f, dot(l, float2(-0.37139070034027099609375f, 0.92847669124603271484375f)) * 0.2199999988079071044921875f);
    float2 param_10 = wCoord + float2(3.7000000476837158203125f, 7.099999904632568359375f);
    float2 param_11 = (l * 0.14000000059604644775390625f) + 11.30000019073486328125f.xx;
    float windSwell = (valueNoise(param_10) * 0.7599999904632568359375f) + (valueNoise(param_11) * 0.23999999463558197021484375f);
    float shelterDelay = ((0.1599999964237213134765625f * overhead) + (0.14000000059604644775390625f * vacWear)) * (1.0f - (0.62000000476837158203125f * smoothstep(0.4199999868869781494140625f, 1.0499999523162841796875f, amount)));
    float windLead = ((((windSwell - 0.5f) * 0.180000007152557373046875f) + (0.0500000007450580596923828125f * bank)) * smoothstep(0.0f, 0.100000001490116119384765625f, amount)) * (1.0f - (0.64999997615814208984375f * smoothstep(0.550000011920928955078125f, 1.0499999523162841796875f, amount)));
    float effAmt = max(0.0f, ((amount * (1.0f + (0.14000000059604644775390625f * bank))) - shelterDelay) + windLead);
    float onset = clamp(effAmt / max(amount, 9.9999997473787516355514526367188e-05f), 0.0f, 1.35000002384185791015625f);
    if (onset <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    float depthScale = (0.839999973773956298828125f + (0.319999992847442626953125f * windSwell)) * ((1.0f - (0.23999999463558197021484375f * overhead)) - (0.449999988079071044921875f * vacWear));
    float2 param_12 = q;
    float _3434 = pavedAt(param_12);
    float paved = _3434;
    float paveKeep = 1.0f - (paved * lerp(0.959999978542327880859375f, 0.99500000476837158203125f, clamp(amount - 0.60000002384185791015625f, 0.0f, 1.0f)));
    float2 param_13 = q;
    float param_14 = base;
    float waterKeep = pondBasinKeep(param_13, param_14);
    float snow = (((((full * onset) * outside) * depthScale) * (1.0f + (0.1599999964237213134765625f * bank))) * paveKeep) * waterKeep;
    if (snow <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    float2 param_15 = q;
    return snow - (min(0.02500000037252902984619140625f, snow * 0.5f) * pressedAt(param_15));
}

float3 marchSnowDrift(float3 srcCol, float3 baseCol, float lumVal, float3 pt, float baseZ, float h0, float amount, float deep, float earthMask, float terrainWear, float isVacSnowLot, bool isGround, out float outEdge, out float outHitT, out float outHitS)
{
    outEdge = 0.0f;
    outHitT = -1.0f;
    outHitS = 0.0f;
    float full = (0.054999999701976776123046875f * min(amount, 1.0f)) + (0.2849999964237213134765625f * deep);
    float top = full * 1.9500000476837158203125f;
    if (h0 >= top)
    {
        return baseCol;
    }
    if (!isGround)
    {
        float2 param = pt.xy;
        float param_1 = baseZ + 0.100000001490116119384765625f;
        float param_2 = 0.4199999868869781494140625f;
        float2 param_3 = pt.xy;
        float param_4 = (baseZ + 2.9500000476837158203125f) + 0.100000001490116119384765625f;
        float param_5 = 0.4199999868869781494140625f;
        float2 param_6 = pt.xy;
        float param_7 = pt.z;
        float param_8 = 0.4199999868869781494140625f;
        float wall = max(nearIndoorWall(param, param_1, param_2), max(nearIndoorWall(param_3, param_4, param_5), nearIndoorWall(param_6, param_7, param_8)));
        if (wall >= 0.0500000007450580596923828125f)
        {
            return baseCol;
        }
    }
    float groundWear = (isGround && (earthMask > 0.00999999977648258209228515625f)) ? terrainWear : 0.0f;
    int steps = (amount > 1.0f) ? 6 : 3;
    float dt = ((top - h0) / 0.4000000059604644775390625f) / float(steps);
    float hitT = -1.0f;
    float hitS = 0.0f;
    float nextS = -1.0f;
    float prevDiff = 0.0f;
    float prevS = 0.0f;
    bool hasPrev = false;
    int _6447 = steps - 1;
    for (int i = _6447; i >= 0; i--)
    {
        float t = float(i) * dt;
        float2 param_9 = pt.xy + (0.5f * t).xx;
        float param_10 = baseZ;
        float param_11 = full;
        float param_12 = amount;
        float param_13 = groundWear;
        float param_14 = isVacSnowLot;
        float sh = snowHeight(param_9, param_10, param_11, param_12, param_13, param_14);
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
    if (hitT < 0.0f)
    {
        return baseCol;
    }
    float2 q = pt.xy + (0.5f * hitT).xx;
    float _6527;
    if (nextS >= 0.0f)
    {
        _6527 = smoothstep((0.7200000286102294921875f * dt) + 0.017999999225139617919921875f, (0.7200000286102294921875f * dt) + 0.05200000107288360595703125f, hitS - nextS);
    }
    else
    {
        _6527 = 0.0f;
    }
    float faceBlend = _6527;
    float e = 0.119999997317790985107421875f;
    float s0 = h0 + (0.4000000059604644775390625f * hitT);
    float2 param_15 = q + float2(e, 0.0f);
    float param_16 = baseZ;
    float param_17 = full;
    float param_18 = amount;
    float param_19 = groundWear;
    float param_20 = isVacSnowLot;
    float gx = (snowHeight(param_15, param_16, param_17, param_18, param_19, param_20) - s0) / e;
    float2 param_21 = q + float2(0.0f, e);
    float param_22 = baseZ;
    float param_23 = full;
    float param_24 = amount;
    float param_25 = groundWear;
    float param_26 = isVacSnowLot;
    float gy = (snowHeight(param_21, param_22, param_23, param_24, param_25, param_26) - s0) / e;
    float3 n2 = normalize(float3(-gx, -gy, 1.0f));
    float3 sunDir = normalize(ambient_sunLot.xyz);
    float lit = clamp(1.0f + (1.0499999523162841796875f * (dot(n2, sunDir) - sunDir.z)), 0.7200000286102294921875f, 1.17999994754791259765625f);
    float2 param_27 = q;
    float2 lq = lotSource(param_27);
    float2 param_28 = lq;
    float qCrust = snowCrust(param_28);
    float2 param_29 = (lq * 0.2599999904632568359375f) + 9.0f.xx;
    float qSwell = valueNoise(param_29);
    float grainShade = ((1.0f - qCrust) * lerp(0.0900000035762786865234375f, 0.039999999105930328369140625f, deep)) + ((1.0f - smoothstep(0.20000000298023223876953125f, 0.800000011920928955078125f, qSwell)) * 0.0900000035762786865234375f);
    float3 qSnow = lerp(float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), clamp(grainShade, 0.0f, 0.300000011920928955078125f).xxx);
    float under = isGround ? lumVal : 0.20999999344348907470703125f;
    qSnow *= (1.0f + ((0.319999992847442626953125f * (1.0f - smoothstep(0.02500000037252902984619140625f, 0.100000001490116119384765625f, hitS))) * (under - 0.2599999904632568359375f)));
    float _6662;
    if (isGround)
    {
        float2 param_30 = q;
        float _6667 = pavedAt(param_30);
        _6662 = _6667;
    }
    else
    {
        _6662 = 0.0f;
    }
    float qPaved = _6662;
    if ((isGround && (qPaved < 0.3499999940395355224609375f)) && (isVacSnowLot > 0.3499999940395355224609375f))
    {
        float2 param_31 = q;
        float qEarth = earthMask * (1.0f - cementAt(param_31));
        if (qEarth > 0.00999999977648258209228515625f)
        {
            float thinness = 1.0f - smoothstep(0.01200000010430812835693359375f, 0.100000001490116119384765625f, hitS);
            float2 param_32 = q;
            float param_33 = baseZ;
            float qBank = wallBank(param_32, param_33);
            float2 param_34 = lq;
            float patchDirt = smoothstep(0.560000002384185791015625f, 0.87999999523162841796875f, dirtField(param_34)) * (1.0f - (0.800000011920928955078125f * qBank));
            float rawDirt = max(terrainWear * 0.86000001430511474609375f, patchDirt * 0.100000001490116119384765625f);
            float thinScale = lerp(0.699999988079071044921875f + (0.300000011920928955078125f * thinness), 0.4000000059604644775390625f + (0.60000002384185791015625f * thinness), 1.0f - terrainWear);
            float dirtMix = clamp(((rawDirt * thinScale) * (1.0f - qPaved)) * qEarth, 0.0f, 0.86000001430511474609375f);
            float dirtBlend = smoothstep(0.119999997317790985107421875f, 0.819999992847442626953125f, dirtMix + ((0.5f - qCrust) * 0.100000001490116119384765625f)) * isVacSnowLot;
            float3 qDirt = lerp(float3(0.08200000226497650146484375f, 0.04500000178813934326171875f, 0.006000000052154064178466796875f), float3(0.33700001239776611328125f, 0.1780000030994415283203125f, 0.0529999993741512298583984375f), (0.3499999940395355224609375f + (0.550000011920928955078125f * qCrust)).xxx) * lerp(0.819999992847442626953125f, 1.14999997615814208984375f, smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, lumVal));
            qDirt = lerp(qDirt, srcCol, ((0.64999997615814208984375f * isVacSnowLot) * smoothstep(0.100000001490116119384765625f, 0.300000011920928955078125f, terrainWear)).xxx);
            float3 param_35 = qSnow;
            float3 param_36 = qDirt;
            float param_37 = dirtBlend;
            qSnow = mixPerceptual(param_35, param_36, param_37);
        }
    }
    float2 param_38 = q;
    float pressed = pressedAt(param_38);
    if (pressed > 0.0f)
    {
        float2 toSun = normalize(ambient_sunLot.xy + 9.9999997473787516355514526367188e-05f.xx) * 0.02999999932944774627685546875f;
        float2 param_39 = q + toSun;
        float shaded = clamp(pressed - pressedAt(param_39), 0.0f, 1.0f);
        float2 param_40 = q - toSun;
        float facing2 = clamp(pressed - pressedAt(param_40), 0.0f, 1.0f);
        qSnow = lerp(qSnow, float3(0.4140000045299530029296875f, 0.49500000476837158203125f, 0.6480000019073486328125f), (0.2800000011920928955078125f * pressed).xxx) * ((1.0f - (0.119999997317790985107421875f * shaded)) + (0.070000000298023223876953125f * facing2));
    }
    float daySun2 = max(0.0f, 1.0f - ambient_weather.w);
    float2 param_41 = lq * 24.0f;
    float2 param_42 = (lq * 41.0f) + 31.700000762939453125f.xx;
    float qGlint = smoothstep(0.680000007152557373046875f, 0.939999997615814208984375f, valueNoise(param_41) * valueNoise(param_42)) * daySun2;
    qSnow += (float3(0.0199999995529651641845703125f, 0.0240000002086162567138671875f, 0.034000001847743988037109375f) * qGlint);
    float3 seen = lerp(qSnow * lit, float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f) * (0.89999997615814208984375f + (0.07999999821186065673828125f * qCrust)), faceBlend.xxx);
    float edge;
    if (isGround)
    {
        float3 param_43 = srcCol;
        float pondWater = pondWaterOf(param_43);
        float normSnow = hitS / 0.054999999701976776123046875f;
        float notPaved = 1.0f - smoothstep(0.25f, 0.64999997615814208984375f, qPaved);
        float2 param_44 = (lq * 22.0f) + 4.099999904632568359375f.xx;
        float2 param_45 = (lq * 39.0f) + 13.69999980926513671875f.xx;
        float tuft = (valueNoise(param_44) * 0.64999997615814208984375f) + (valueNoise(param_45) * 0.3499999940395355224609375f);
        float3 param_46 = srcCol;
        float grassBlade = (greenOf(param_46) * (1.0f - pondWater)) * clamp((0.449999988079071044921875f * smoothstep(0.039999999105930328369140625f, 0.1599999964237213134765625f, lumVal)) + (0.550000011920928955078125f * tuft), 0.0f, 1.0f);
        float dust = (smoothstep(0.0199999995529651641845703125f, 0.300000011920928955078125f, normSnow) * (1.0f - ((0.4799999892711639404296875f * grassBlade) * (1.0f - smoothstep(0.2199999988079071044921875f, 0.62000000476837158203125f, normSnow))))) * notPaved;
        float blanket = smoothstep(0.2199999988079071044921875f, 0.680000007152557373046875f, normSnow - (0.119999997317790985107421875f * grassBlade)) * notPaved;
        edge = clamp(lerp(0.4199999868869781494140625f * dust, 1.0f, blanket), 0.0f, 1.0f);
    }
    else
    {
        edge = smoothstep(0.006000000052154064178466796875f, 0.0240000002086162567138671875f, hitS);
    }
    outEdge = edge;
    outHitT = hitT;
    outHitS = hitS;
    float3 param_47 = baseCol;
    float3 param_48 = seen;
    float param_49 = edge;
    return mixPerceptual(param_47, param_48, param_49);
}

void frag_main()
{
    float2 pixel = floor(gl_FragCoord.xy) + 0.5f.xx;
    color = 0.0f.xxxx;
    lift = 0.0f.xxxx;
    bool _7527 = pixel.x >= ambient_extent.x;
    bool _7536;
    if (!_7527)
    {
        _7536 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _7536 = _7527;
    }
    if (_7536)
    {
        return;
    }
    bool _7542 = ambient_season.x >= 0.5f;
    bool _7548;
    if (_7542)
    {
        _7548 = ambient_season.x < 1.5f;
    }
    else
    {
        _7548 = _7542;
    }
    bool _7555;
    if (_7548)
    {
        _7555 = ambient_seasonExtra2.w > 0.5f;
    }
    else
    {
        _7555 = _7548;
    }
    if (_7555)
    {
        int2 ip = int2(floor(gl_FragCoord.xy));
        int2 maxI = max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0));
        float3 cM = source.Load(int3(ip, 0)).xyz;
        float3 origM = overheadMap.Load(int3(ip, 0)).xyz;
        uint _7587_dummy_parameter;
        bool _7589 = int2(spvTextureSize(simMap, uint(0), _7587_dummy_parameter)).x > 1;
        bool _7598;
        if (_7589)
        {
            _7598 = simMap.Load(int3(ip, 0)).x > 0.5f;
        }
        else
        {
            _7598 = _7589;
        }
        bool isSim = _7598;
        if (isSim)
        {
            float3 _7605 = abs(cM - origM);
            if (all(bool3(_7605.x < 9.9999997473787516355514526367188e-05f.xxx.x, _7605.y < 9.9999997473787516355514526367188e-05f.xxx.y, _7605.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
            {
                return;
            }
            color = float4(cM, 1.0f);
            return;
        }
        float fM = trailMap.Load(int3(ip, 0)).x;
        float fN = trailMap.Load(int3(clamp(ip + int2(0, -1), int2(0, 0), maxI), 0)).x;
        float fS = trailMap.Load(int3(clamp(ip + int2(0, 1), int2(0, 0), maxI), 0)).x;
        float fW = trailMap.Load(int3(clamp(ip + int2(-1, 0), int2(0, 0), maxI), 0)).x;
        float fE = trailMap.Load(int3(clamp(ip + int2(1, 0), int2(0, 0), maxI), 0)).x;
        float fNW = trailMap.Load(int3(clamp(ip + int2(-1, -1), int2(0, 0), maxI), 0)).x;
        float fNE = trailMap.Load(int3(clamp(ip + int2(1, -1), int2(0, 0), maxI), 0)).x;
        float fSW = trailMap.Load(int3(clamp(ip + int2(-1, 1), int2(0, 0), maxI), 0)).x;
        float fSE = trailMap.Load(int3(clamp(ip + int2(1, 1), int2(0, 0), maxI), 0)).x;
        float fMax = max(fM, max(max(max(fN, fS), max(fE, fW)), max(max(fNW, fNE), max(fSW, fSE))));
        if (fMax < 0.02999999932944774627685546875f)
        {
            float3 _7725 = abs(cM - origM);
            if (all(bool3(_7725.x < 9.9999997473787516355514526367188e-05f.xxx.x, _7725.y < 9.9999997473787516355514526367188e-05f.xxx.y, _7725.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
            {
                return;
            }
            color = float4(cM, 1.0f);
            return;
        }
        float3 cN = source.Load(int3(clamp(ip + int2(0, -1), int2(0, 0), maxI), 0)).xyz;
        float3 cS = source.Load(int3(clamp(ip + int2(0, 1), int2(0, 0), maxI), 0)).xyz;
        float3 cW = source.Load(int3(clamp(ip + int2(-1, 0), int2(0, 0), maxI), 0)).xyz;
        float3 cE = source.Load(int3(clamp(ip + int2(1, 0), int2(0, 0), maxI), 0)).xyz;
        float3 cNW = source.Load(int3(clamp(ip + int2(-1, -1), int2(0, 0), maxI), 0)).xyz;
        float3 cNE = source.Load(int3(clamp(ip + int2(1, -1), int2(0, 0), maxI), 0)).xyz;
        float3 cSW = source.Load(int3(clamp(ip + int2(-1, 1), int2(0, 0), maxI), 0)).xyz;
        float3 cSE = source.Load(int3(clamp(ip + int2(1, 1), int2(0, 0), maxI), 0)).xyz;
        float3 param = cM;
        float lM = autumnEdgeMetric(param);
        float3 param_1 = cN;
        float lN = autumnEdgeMetric(param_1);
        float3 param_2 = cS;
        float lS = autumnEdgeMetric(param_2);
        float3 param_3 = cW;
        float lW = autumnEdgeMetric(param_3);
        float3 param_4 = cE;
        float lE = autumnEdgeMetric(param_4);
        float3 param_5 = cNW;
        float lNW = autumnEdgeMetric(param_5);
        float3 param_6 = cNE;
        float lNE = autumnEdgeMetric(param_6);
        float3 param_7 = cSW;
        float lSW = autumnEdgeMetric(param_7);
        float3 param_8 = cSE;
        float lSE = autumnEdgeMetric(param_8);
        float lMin = min(lM, min(min(lN, lS), min(lE, lW)));
        float lMax = max(lM, max(max(lN, lS), max(lE, lW)));
        float lRange = lMax - lMin;
        if (lRange < max(0.02999999932944774627685546875f, abs(lMax) * 0.054999999701976776123046875f))
        {
            float3 _7880 = abs(cM - origM);
            if (all(bool3(_7880.x < 9.9999997473787516355514526367188e-05f.xxx.x, _7880.y < 9.9999997473787516355514526367188e-05f.xxx.y, _7880.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
            {
                return;
            }
            color = float4(cM, 1.0f);
            return;
        }
        float edgeHorz = (abs((((-2.0f) * lW) + lNW) + lSW) + (2.0f * abs((((-2.0f) * lM) + lN) + lS))) + abs((((-2.0f) * lE) + lNE) + lSE);
        float edgeVert = (abs((((-2.0f) * lN) + lNW) + lNE) + (2.0f * abs((((-2.0f) * lM) + lW) + lE))) + abs((((-2.0f) * lS) + lSW) + lSE);
        bool isHorz = edgeHorz >= edgeVert;
        float l1 = isHorz ? lN : lW;
        float l2 = isHorz ? lS : lE;
        float g1 = abs(l1 - lM);
        float g2 = abs(l2 - lM);
        bool is1Steeper = g1 >= g2;
        float gradScaled = 0.23999999463558197021484375f * max(g1, g2);
        int2 _7978;
        if (isHorz)
        {
            _7978 = int2(0, is1Steeper ? (-1) : 1);
        }
        else
        {
            _7978 = int2(is1Steeper ? (-1) : 1, 0);
        }
        int2 stepPerp = _7978;
        bool2 _7991 = isHorz.xx;
        int2 stepTan = int2(_7991.x ? int2(1, 0).x : int2(0, 1).x, _7991.y ? int2(1, 0).y : int2(0, 1).y);
        float lAvg = 0.5f * (lM + (is1Steeper ? l1 : l2));
        float lEndN = lAvg;
        float lEndP = lAvg;
        bool doneN = false;
        bool doneP = false;
        int distN = 7;
        int distP = 7;
        for (int s = 1; s <= 6; s++)
        {
            if (!doneN)
            {
                int2 pN = clamp(ip - (stepTan * s.xx), int2(0, 0), maxI);
                int2 pNp = clamp(pN + stepPerp, int2(0, 0), maxI);
                float3 param_9 = source.Load(int3(pN, 0)).xyz;
                float3 param_10 = source.Load(int3(pNp, 0)).xyz;
                float aN = 0.5f * (autumnEdgeMetric(param_9) + autumnEdgeMetric(param_10));
                lEndN = aN - lAvg;
                if (abs(lEndN) >= gradScaled)
                {
                    doneN = true;
                    distN = s;
                }
            }
            if (!doneP)
            {
                int2 pP = clamp(ip + (stepTan * s.xx), int2(0, 0), maxI);
                int2 pPp = clamp(pP + stepPerp, int2(0, 0), maxI);
                float3 param_11 = source.Load(int3(pP, 0)).xyz;
                float3 param_12 = source.Load(int3(pPp, 0)).xyz;
                float aP = 0.5f * (autumnEdgeMetric(param_11) + autumnEdgeMetric(param_12));
                lEndP = aP - lAvg;
                if (abs(lEndP) >= gradScaled)
                {
                    doneP = true;
                    distP = s;
                }
            }
            if (doneN && doneP)
            {
                break;
            }
        }
        float dMin = float(min(distN, distP));
        float spanLen = float(distN + distP);
        bool goodSpan = (((distN <= distP) ? lEndN : lEndP) < 0.0f) != (lM < lAvg);
        float _8141;
        if (goodSpan)
        {
            _8141 = max(0.0f, 0.5f - (dMin / spanLen));
        }
        else
        {
            _8141 = 0.0f;
        }
        float edgeBlend = _8141;
        float avg9 = (((((2.0f * (((lN + lS) + lE) + lW)) + lNW) + lNE) + lSW) + lSE) / 12.0f;
        float subpix = clamp(abs(avg9 - lM) / max(lRange, 9.9999997473787516355514526367188e-05f), 0.0f, 1.0f);
        subpix = smoothstep(0.0f, 1.0f, subpix);
        float subpixAA = (0.579999983310699462890625f * subpix) * subpix;
        int2 perpPx = clamp(ip + stepPerp, int2(0, 0), maxI);
        uint _8195_dummy_parameter;
        bool _8197 = int2(spvTextureSize(simMap, uint(0), _8195_dummy_parameter)).x > 1;
        bool _8206;
        if (_8197)
        {
            _8206 = simMap.Load(int3(perpPx, 0)).x > 0.5f;
        }
        else
        {
            _8206 = _8197;
        }
        bool perpSim = _8206;
        float _8209;
        if (perpSim)
        {
            _8209 = 0.0f;
        }
        else
        {
            _8209 = max(edgeBlend, subpixAA) * smoothstep(0.02999999932944774627685546875f, 0.1599999964237213134765625f, fMax);
        }
        float finalBlend = _8209;
        float3 _8224;
        if (stepPerp.y < 0)
        {
            _8224 = cN;
        }
        else
        {
            float3 _8232;
            if (stepPerp.y > 0)
            {
                _8232 = cS;
            }
            else
            {
                bool3 _8242 = (stepPerp.x < 0).xxx;
                _8232 = float3(_8242.x ? cW.x : cE.x, _8242.y ? cW.y : cE.y, _8242.z ? cW.z : cE.z);
            }
            _8224 = _8232;
        }
        float3 perpCol = _8224;
        float fMinCard = min(fM, min(min(fN, fS), min(fE, fW)));
        float3 cardSqrt = (((sqrt(max(cN, 0.0f.xxx)) + sqrt(max(cS, 0.0f.xxx))) + sqrt(max(cW, 0.0f.xxx))) + sqrt(max(cE, 0.0f.xxx))) * 0.25f;
        float3 _8276;
        if (fMinCard > 0.449999988079071044921875f)
        {
            float3 param_13 = cardSqrt * cardSqrt;
            float3 param_14 = perpCol;
            float param_15 = clamp(edgeBlend * 2.0f, 0.0f, 1.0f);
            _8276 = mixPerceptual(param_13, param_14, param_15);
        }
        else
        {
            _8276 = perpCol;
        }
        float3 targetCol = _8276;
        float3 param_16 = cM;
        float3 param_17 = targetCol;
        float param_18 = clamp(finalBlend, 0.0f, 0.680000007152557373046875f);
        float3 aaCol = mixPerceptual(param_16, param_17, param_18);
        float3 _8305 = abs(aaCol - origM);
        if (all(bool3(_8305.x < 9.9999997473787516355514526367188e-05f.xxx.x, _8305.y < 9.9999997473787516355514526367188e-05f.xxx.y, _8305.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
        {
            return;
        }
        color = float4(aaCol, 1.0f);
        return;
    }
    bool _8319 = ambient_season.x >= 1.5f;
    bool _8325;
    if (_8319)
    {
        _8325 = ambient_seasonExtra2.w > 0.5f;
    }
    else
    {
        _8325 = _8319;
    }
    if (_8325)
    {
        int2 ip_1 = int2(floor(gl_FragCoord.xy));
        int2 maxI_1 = max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0));
        float4 stLift = trailMap.Load(int3(ip_1, 0));
        float4 _8349;
        if (stLift.z > 0.5f)
        {
            _8349 = stLift;
        }
        else
        {
            float _8357;
            if (stLift.z < (-0.00200000009499490261077880859375f))
            {
                _8357 = stLift.z;
            }
            else
            {
                _8357 = 0.0f;
            }
            _8349 = float4(0.0f, 0.0f, _8357, stLift.w);
        }
        lift = _8349;
        uint _8371_dummy_parameter;
        bool hasSpriteLayer = int2(spvTextureSize(spriteMap, uint(0), _8371_dummy_parameter)).x > 4;
        int2 param_19 = ip_1;
        int2 param_20 = maxI_1;
        bool param_21 = hasSpriteLayer;
        float4 _8381 = resolveWinterPixel(param_19, param_20, param_21);
        float4 cM_1 = _8381;
        float3 origM_1 = overheadMap.Load(int3(ip_1, 0)).xyz;
        uint _8391_dummy_parameter;
        bool _8393 = int2(spvTextureSize(simMap, uint(0), _8391_dummy_parameter)).x > 1;
        bool _8402;
        if (_8393)
        {
            _8402 = simMap.Load(int3(ip_1, 0)).x > 0.5f;
        }
        else
        {
            _8402 = _8393;
        }
        bool isSim_1 = _8402;
        if (isSim_1)
        {
            float3 _8410 = abs(cM_1.xyz - origM_1);
            if (all(bool3(_8410.x < 9.9999997473787516355514526367188e-05f.xxx.x, _8410.y < 9.9999997473787516355514526367188e-05f.xxx.y, _8410.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
            {
                return;
            }
            color = float4(cM_1.xyz, 1.0f);
            return;
        }
        int2 param_22 = ip_1 + int2(0, -1);
        int2 param_23 = maxI_1;
        bool param_24 = hasSpriteLayer;
        float4 _8431 = resolveWinterPixel(param_22, param_23, param_24);
        float4 cN_1 = _8431;
        int2 param_25 = ip_1 + int2(0, 1);
        int2 param_26 = maxI_1;
        bool param_27 = hasSpriteLayer;
        float4 _8440 = resolveWinterPixel(param_25, param_26, param_27);
        float4 cS_1 = _8440;
        int2 param_28 = ip_1 + int2(-1, 0);
        int2 param_29 = maxI_1;
        bool param_30 = hasSpriteLayer;
        float4 _8449 = resolveWinterPixel(param_28, param_29, param_30);
        float4 cW_1 = _8449;
        int2 param_31 = ip_1 + int2(1, 0);
        int2 param_32 = maxI_1;
        bool param_33 = hasSpriteLayer;
        float4 _8458 = resolveWinterPixel(param_31, param_32, param_33);
        float4 cE_1 = _8458;
        int2 param_34 = ip_1 + int2(-1, -1);
        int2 param_35 = maxI_1;
        bool param_36 = hasSpriteLayer;
        float4 _8467 = resolveWinterPixel(param_34, param_35, param_36);
        float4 cNW_1 = _8467;
        int2 param_37 = ip_1 + int2(1, -1);
        int2 param_38 = maxI_1;
        bool param_39 = hasSpriteLayer;
        float4 _8476 = resolveWinterPixel(param_37, param_38, param_39);
        float4 cNE_1 = _8476;
        int2 param_40 = ip_1 + int2(-1, 1);
        int2 param_41 = maxI_1;
        bool param_42 = hasSpriteLayer;
        float4 _8485 = resolveWinterPixel(param_40, param_41, param_42);
        float4 cSW_1 = _8485;
        int2 param_43 = ip_1 + int2(1, 1);
        int2 param_44 = maxI_1;
        bool param_45 = hasSpriteLayer;
        float4 _8494 = resolveWinterPixel(param_43, param_44, param_45);
        float4 cSE_1 = _8494;
        float sMax = max(cM_1.w, max(max(max(cN_1.w, cS_1.w), max(cE_1.w, cW_1.w)), max(max(cNW_1.w, cNE_1.w), max(cSW_1.w, cSE_1.w))));
        if (sMax < 0.02999999932944774627685546875f)
        {
            float3 _8530 = abs(cM_1.xyz - origM_1);
            if (all(bool3(_8530.x < 9.9999997473787516355514526367188e-05f.xxx.x, _8530.y < 9.9999997473787516355514526367188e-05f.xxx.y, _8530.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
            {
                return;
            }
            color = float4(cM_1.xyz, 1.0f);
            return;
        }
        float3 param_46 = cM_1.xyz;
        float lM_1 = snowLuma(param_46);
        float3 param_47 = cN_1.xyz;
        float lN_1 = snowLuma(param_47);
        float3 param_48 = cS_1.xyz;
        float lS_1 = snowLuma(param_48);
        float3 param_49 = cW_1.xyz;
        float lW_1 = snowLuma(param_49);
        float3 param_50 = cE_1.xyz;
        float lE_1 = snowLuma(param_50);
        float3 param_51 = cNW_1.xyz;
        float lNW_1 = snowLuma(param_51);
        float3 param_52 = cNE_1.xyz;
        float lNE_1 = snowLuma(param_52);
        float3 param_53 = cSW_1.xyz;
        float lSW_1 = snowLuma(param_53);
        float3 param_54 = cSE_1.xyz;
        float lSE_1 = snowLuma(param_54);
        float lMin_1 = min(lM_1, min(min(lN_1, lS_1), min(lE_1, lW_1)));
        float lMax_1 = max(lM_1, max(max(lN_1, lS_1), max(lE_1, lW_1)));
        float lRange_1 = lMax_1 - lMin_1;
        if ((lRange_1 < max(0.0350000001490116119384765625f, lMax_1 * 0.064999997615814208984375f)) || (sMax < 0.039999999105930328369140625f))
        {
            color = float4(cM_1.xyz, 1.0f);
            return;
        }
        float edgeHorz_1 = (abs((((-2.0f) * lW_1) + lNW_1) + lSW_1) + (2.0f * abs((((-2.0f) * lM_1) + lN_1) + lS_1))) + abs((((-2.0f) * lE_1) + lNE_1) + lSE_1);
        float edgeVert_1 = (abs((((-2.0f) * lN_1) + lNW_1) + lNE_1) + (2.0f * abs((((-2.0f) * lM_1) + lW_1) + lE_1))) + abs((((-2.0f) * lS_1) + lSW_1) + lSE_1);
        bool isHorz_1 = edgeHorz_1 >= edgeVert_1;
        float l1_1 = isHorz_1 ? lN_1 : lW_1;
        float l2_1 = isHorz_1 ? lS_1 : lE_1;
        float g1_1 = abs(l1_1 - lM_1);
        float g2_1 = abs(l2_1 - lM_1);
        bool is1Steeper_1 = g1_1 >= g2_1;
        float gradScaled_1 = 0.25f * max(g1_1, g2_1);
        int2 _8716;
        if (isHorz_1)
        {
            _8716 = int2(0, is1Steeper_1 ? (-1) : 1);
        }
        else
        {
            _8716 = int2(is1Steeper_1 ? (-1) : 1, 0);
        }
        int2 stepPerp_1 = _8716;
        bool2 _8729 = isHorz_1.xx;
        int2 stepTan_1 = int2(_8729.x ? int2(1, 0).x : int2(0, 1).x, _8729.y ? int2(1, 0).y : int2(0, 1).y);
        float lAvg_1 = 0.5f * (lM_1 + (is1Steeper_1 ? l1_1 : l2_1));
        float lEndN_1 = lAvg_1;
        float lEndP_1 = lAvg_1;
        bool doneN_1 = false;
        bool doneP_1 = false;
        int distN_1 = 7;
        int distP_1 = 7;
        for (int s_1 = 1; s_1 <= 6; s_1++)
        {
            if (!doneN_1)
            {
                int2 pN_1 = ip_1 - (stepTan_1 * s_1.xx);
                int2 param_55 = pN_1;
                int2 param_56 = maxI_1;
                bool param_57 = hasSpriteLayer;
                float4 _8773 = resolveWinterPixel(param_55, param_56, param_57);
                float3 param_58 = _8773.xyz;
                int2 param_59 = pN_1 + stepPerp_1;
                int2 param_60 = maxI_1;
                bool param_61 = hasSpriteLayer;
                float4 _8785 = resolveWinterPixel(param_59, param_60, param_61);
                float3 param_62 = _8785.xyz;
                float aN_1 = 0.5f * (snowLuma(param_58) + snowLuma(param_62));
                lEndN_1 = aN_1 - lAvg_1;
                if (abs(lEndN_1) >= gradScaled_1)
                {
                    doneN_1 = true;
                    distN_1 = s_1;
                }
            }
            if (!doneP_1)
            {
                int2 pP_1 = ip_1 + (stepTan_1 * s_1.xx);
                int2 param_63 = pP_1;
                int2 param_64 = maxI_1;
                bool param_65 = hasSpriteLayer;
                float4 _8819 = resolveWinterPixel(param_63, param_64, param_65);
                float3 param_66 = _8819.xyz;
                int2 param_67 = pP_1 + stepPerp_1;
                int2 param_68 = maxI_1;
                bool param_69 = hasSpriteLayer;
                float4 _8831 = resolveWinterPixel(param_67, param_68, param_69);
                float3 param_70 = _8831.xyz;
                float aP_1 = 0.5f * (snowLuma(param_66) + snowLuma(param_70));
                lEndP_1 = aP_1 - lAvg_1;
                if (abs(lEndP_1) >= gradScaled_1)
                {
                    doneN_1 = doneN_1;
                    doneP_1 = true;
                    distP_1 = s_1;
                }
            }
            if (doneN_1 && doneP_1)
            {
                break;
            }
        }
        float dMin_1 = float(min(distN_1, distP_1));
        float spanLen_1 = float(distN_1 + distP_1);
        bool goodSpan_1 = (((distN_1 <= distP_1) ? lEndN_1 : lEndP_1) < 0.0f) != (lM_1 < lAvg_1);
        float _8880;
        if (goodSpan_1)
        {
            _8880 = max(0.0f, 0.5f - (dMin_1 / spanLen_1));
        }
        else
        {
            _8880 = 0.0f;
        }
        float edgeBlend_1 = _8880;
        float avg9_1 = (((((2.0f * (((lN_1 + lS_1) + lE_1) + lW_1)) + lNW_1) + lNE_1) + lSW_1) + lSE_1) / 12.0f;
        float subpix_1 = clamp(abs(avg9_1 - lM_1) / max(lRange_1, 9.9999997473787516355514526367188e-05f), 0.0f, 1.0f);
        subpix_1 = smoothstep(0.0f, 1.0f, subpix_1);
        float subpixAA_1 = (0.64999997615814208984375f * subpix_1) * subpix_1;
        int2 perpPx_1 = clamp(ip_1 + stepPerp_1, int2(0, 0), maxI_1);
        uint _8933_dummy_parameter;
        bool _8935 = int2(spvTextureSize(simMap, uint(0), _8933_dummy_parameter)).x > 1;
        bool _8944;
        if (_8935)
        {
            _8944 = simMap.Load(int3(perpPx_1, 0)).x > 0.5f;
        }
        else
        {
            _8944 = _8935;
        }
        bool perpSim_1 = _8944;
        float _8947;
        if (perpSim_1)
        {
            _8947 = 0.0f;
        }
        else
        {
            _8947 = max(edgeBlend_1, subpixAA_1) * smoothstep(0.039999999105930328369140625f, 0.180000007152557373046875f, sMax);
        }
        float finalBlend_1 = _8947;
        float3 _8962;
        if (stepPerp_1.y < 0)
        {
            _8962 = cN_1.xyz;
        }
        else
        {
            float3 _8971;
            if (stepPerp_1.y > 0)
            {
                _8971 = cS_1.xyz;
            }
            else
            {
                float3 _8980;
                if (stepPerp_1.x < 0)
                {
                    _8980 = cW_1.xyz;
                }
                else
                {
                    _8980 = cE_1.xyz;
                }
                _8971 = _8980;
            }
            _8962 = _8971;
        }
        float3 perpCol_1 = _8962;
        float3 param_71 = cM_1.xyz;
        float3 param_72 = perpCol_1;
        float param_73 = clamp(finalBlend_1, 0.0f, 0.7200000286102294921875f);
        color = float4(mixPerceptual(param_71, param_72, param_73), 1.0f);
        return;
    }
    float2 param_74 = pixel;
    float4 centre = positionAt(param_74);
    if (centre.w > 0.75f)
    {
        return;
    }
    float3 src = source.Load(int3(int2(pixel), 0)).xyz;
    bool ground = centre.w > 0.25f;
    bool mapped = ambient_sunLot.w > 0.0f;
    float _9032;
    if (ground)
    {
        _9032 = ((0.62000000476837158203125f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
    }
    else
    {
        _9032 = (0.62000000476837158203125f - depthMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f;
    }
    float key = _9032;
    float2 param_75 = centre.xy;
    float param_76 = key;
    bool param_77 = ground;
    float2 param_78 = ambient_frame.xy;
    float3 here = lotPoint(param_75, param_76, param_77, param_78);
    float _9071;
    if (mapped)
    {
        float3 param_79 = here;
        _9071 = 1.0f - indoors(param_79);
    }
    else
    {
        _9071 = 1.0f;
    }
    float outdoor = _9071;
    if (mapped && (!ground))
    {
        float3 param_80 = here - float3(0.0f, 0.0f, 0.25f);
        outdoor = min(outdoor, 1.0f - indoors(param_80));
    }
    float _9096;
    if (mapped)
    {
        float3 _9100;
        if (ground)
        {
            _9100 = here;
        }
        else
        {
            _9100 = here + float3(0.0f, 0.0f, 0.449999988079071044921875f);
        }
        float3 param_81 = _9100;
        _9096 = architecturalExposure(param_81);
    }
    else
    {
        _9096 = 1.0f;
    }
    float skyExposed = _9096;
    if (outdoor <= 0.0f)
    {
        return;
    }
    float2 param_82 = here.xy;
    float2 lot = lotSource(param_82);
    float lotPixelScale = max(length(fwidth(lot)), 0.00200000009499490261077880859375f);
    float amount = ambient_season.y;
    float springBloom = clamp(ambient_seasonExtra.y, 0.0f, 1.0f);
    float frost = clamp(ambient_seasonExtra2.y, 0.0f, 1.0f);
    float lum = dot(src, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float _9144;
    if (ground)
    {
        float3 param_83 = src;
        _9144 = pondWaterOf(param_83);
    }
    else
    {
        _9144 = 0.0f;
    }
    float srcPondBlue = _9144;
    float green = smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, (src.y - max(src.x, src.z)) / max(src.y, 0.039999999105930328369140625f)) * (1.0f - srcPondBlue);
    float _9171;
    if (mapped)
    {
        float2 param_84 = here.xy;
        _9171 = topAt(param_84) - here.z;
    }
    else
    {
        _9171 = 0.0f;
    }
    float over = _9171;
    float covered = smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, over);
    bool _9192;
    if (mapped)
    {
        _9192 = ambient_season.x > 1.5f;
    }
    else
    {
        _9192 = mapped;
    }
    if (_9192)
    {
        float _9206;
        float _9216;
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                _9206 = 1.0f;
            }
            else
            {
                _9206 = (i == 1) ? (-1.0f) : 0.0f;
            }
            if (i == 2)
            {
                _9216 = 1.0f;
            }
            else
            {
                _9216 = (i == 3) ? (-1.0f) : 0.0f;
            }
            float2 offset = float2(_9206, _9216) * 0.3499999940395355224609375f;
            float2 param_85 = here.xy + offset;
            covered += smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, topAt(param_85) - here.z);
        }
        covered /= 5.0f;
    }
    float3 result = src;
    uint _9247_dummy_parameter;
    bool _9249 = int2(spvTextureSize(simMap, uint(0), _9247_dummy_parameter)).x > 1;
    bool _9259;
    if (_9249)
    {
        _9259 = simMap.Load(int3(int2(pixel), 0)).x > 0.5f;
    }
    else
    {
        _9259 = _9249;
    }
    bool sim = _9259;
    bool _9269;
    if (mapped)
    {
        uint _9266_dummy_parameter;
        _9269 = int2(spvTextureSize(trailMap, uint(0), _9266_dummy_parameter)).x > 4;
    }
    else
    {
        _9269 = mapped;
    }
    bool _9279;
    if (_9269)
    {
        _9279 = abs(trailMap.Load(int3(int2(0, 0), 0)).w - 0.5f) < 0.180000007152557373046875f;
    }
    else
    {
        _9279 = _9269;
    }
    bool hasInFloraMap = _9279;
    bool _9287;
    if (mapped)
    {
        _9287 = ambient_prevView.w > 0.5f;
    }
    else
    {
        _9287 = mapped;
    }
    bool _9293;
    if (_9287)
    {
        _9293 = ambient_prevView.x > 0.0f;
    }
    else
    {
        _9293 = _9287;
    }
    bool _9301;
    if (_9293)
    {
        uint _9298_dummy_parameter;
        _9301 = int2(spvTextureSize(outFloraMap, uint(0), _9298_dummy_parameter)).x > 4;
    }
    else
    {
        _9301 = _9293;
    }
    bool hasOutFloraMap = _9301;
    bool hasLiveFloraMap = hasInFloraMap || hasOutFloraMap;
    if (ambient_season.x < 0.5f)
    {
        if ((((springBloom > 0.00999999977648258209228515625f) && (skyExposed > 0.001000000047497451305389404296875f)) && ground) && (green > 0.0500000007450580596923828125f))
        {
            float3 param_86 = float3(0.3400000035762786865234375f, 0.449999988079071044921875f, 0.180000007152557373046875f);
            float3 param_87 = src;
            float3 param_88 = srgbToLinear(param_86);
            result = lerp(src, recolor(param_87, param_88), (((green * skyExposed) * springBloom) * 0.180000007152557373046875f).xxx);
        }
        if ((((frost > 0.0199999995529651641845703125f) && (skyExposed > 0.001000000047497451305389404296875f)) && (!sim)) && (green > 0.0500000007450580596923828125f))
        {
            float2 param_89 = lot * 6.0f;
            float2 param_90 = (lot * 19.0f) + 7.099999904632568359375f.xx;
            float rime = smoothstep(0.3499999940395355224609375f, 0.819999992847442626953125f, (valueNoise(param_89) * 0.550000011920928955078125f) + (valueNoise(param_90) * 0.449999988079071044921875f));
            float3 param_91 = float3(0.7799999713897705078125f, 0.86000001430511474609375f, 0.949999988079071044921875f);
            float3 frostTint = srgbToLinear(param_91) * clamp(lum / 0.119999997317790985107421875f, 0.3499999940395355224609375f, 1.25f);
            result = lerp(result, frostTint, ((((frost * rime) * green) * skyExposed) * (ground ? 0.3400000035762786865234375f : 0.2199999988079071044921875f)).xxx);
        }
        bool _9393 = ambient_params.y < 0.00999999977648258209228515625f;
        bool _9399;
        if (_9393)
        {
            _9399 = ambient_season.x < 1.5f;
        }
        else
        {
            _9399 = _9393;
        }
        if (_9399 && (skyExposed > 0.001000000047497451305389404296875f))
        {
            float overcastDim = (1.0f - (0.23999999463558197021484375f * clamp(ambient_clouds.x, 0.0f, 1.0f))) - (0.119999997317790985107421875f * clamp(ambient_weather.x, 0.0f, 1.0f));
            float wetDark = 1.0f - ((0.2199999988079071044921875f * clamp(ambient_weather.y, 0.0f, 1.0f)) * (ground ? 1.0f : 0.550000011920928955078125f));
            result *= lerp(1.0f, overcastDim * wetDark, skyExposed);
        }
        float3 _9435 = abs(result - src);
        if (all(bool3(_9435.x < 9.9999997473787516355514526367188e-05f.xxx.x, _9435.y < 9.9999997473787516355514526367188e-05f.xxx.y, _9435.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
        {
            return;
        }
    }
    else
    {
        if (ambient_season.x < 1.5f)
        {
            uint _9450_dummy_parameter;
            bool hasSpriteLayer_1 = int2(spvTextureSize(spriteMap, uint(0), _9450_dummy_parameter)).x > 4;
            float4 _9455;
            if (hasSpriteLayer_1)
            {
                _9455 = spriteMap.Load(int3(int2(pixel), 0));
            }
            else
            {
                _9455 = 0.0f.xxxx;
            }
            float4 sp = _9455;
            float folAct = 0.0f;
            if (!ground)
            {
                float _9472;
                if (mapped)
                {
                    float2 param_92 = pixel;
                    _9472 = groundAt(param_92);
                }
                else
                {
                    _9472 = -100000.0f;
                }
                float autGroundAlt = _9472;
                float _9484;
                if (autGroundAlt > (-10000.0f))
                {
                    float2 param_93 = centre.xy;
                    float param_94 = autGroundAlt / 27.7128124237060546875f;
                    bool param_95 = true;
                    float2 param_96 = ambient_frame.xy;
                    _9484 = lotPoint(param_93, param_94, param_95, param_96).z;
                }
                else
                {
                    float2 param_97 = here.xy;
                    float param_98 = ambient_contact.w;
                    _9484 = terrainBaseClamped(param_97, param_98);
                }
                float autFallbackBase = _9484;
                bool _9515;
                if (hasSpriteLayer_1)
                {
                    _9515 = sp.w > 0.00200000009499490261077880859375f;
                }
                else
                {
                    _9515 = hasSpriteLayer_1;
                }
                bool _9521;
                if (_9515)
                {
                    _9521 = sp.w < 0.9900000095367431640625f;
                }
                else
                {
                    _9521 = _9515;
                }
                if (_9521)
                {
                    float3 F = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                    float3 B = clamp((src - sp.xyz) / max(1.0f - sp.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                    float3 param_99 = F;
                    float3 param_100 = here;
                    float param_101 = autFallbackBase;
                    float2 param_102 = lot;
                    float param_103 = amount;
                    float param_104 = outdoor;
                    bool param_105 = sim;
                    bool param_106 = mapped;
                    bool param_107 = hasLiveFloraMap;
                    float param_108;
                    float3 _9564 = applyAutumnFoliage(param_99, param_100, param_101, param_102, param_103, param_104, param_105, param_106, param_107, param_108);
                    folAct = param_108;
                    float3 F_aut = _9564;
                    folAct *= smoothstep(0.0199999995529651641845703125f, 0.25f, sp.w);
                    float3 B_aut = B;
                    float gDepth = groundMap.Load(int3(int2(pixel), 0)).x;
                    if ((!sim) && (gDepth < 1.0f))
                    {
                        float gKey = ((0.62000000476837158203125f - gDepth) / 0.0030000000260770320892333984375f) + ambient_view.w;
                        float2 param_109 = centre.xy;
                        float param_110 = gKey;
                        bool param_111 = true;
                        float2 param_112 = ambient_frame.xy;
                        float3 hereG = lotPoint(param_109, param_110, param_111, param_112);
                        float _9608;
                        if (mapped)
                        {
                            float3 param_113 = hereG;
                            _9608 = 1.0f - indoors(param_113);
                        }
                        else
                        {
                            _9608 = 1.0f;
                        }
                        float gOutdoor = _9608;
                        if (gOutdoor > 0.0f)
                        {
                            float _9623;
                            if (mapped)
                            {
                                float3 param_114 = hereG;
                                _9623 = architecturalExposure(param_114);
                            }
                            else
                            {
                                _9623 = 1.0f;
                            }
                            float gSkyExposed = _9623;
                            float2 param_115 = hereG.xy;
                            float2 gLot = lotSource(param_115);
                            float gPixelScale = max(1.0f / (36.0f * max(ambient_view.z, 0.119999997317790985107421875f)), 0.00200000009499490261077880859375f);
                            float3 param_116 = B;
                            float3 param_117 = hereG;
                            float2 param_118 = gLot;
                            float param_119 = gPixelScale;
                            float param_120 = amount;
                            float param_121 = gOutdoor;
                            float param_122 = gSkyExposed;
                            bool param_123 = mapped;
                            bool param_124 = hasLiveFloraMap;
                            bool param_125 = true;
                            B_aut = applyAutumnGround(param_116, param_117, param_118, param_119, param_120, param_121, param_122, param_123, param_124, param_125);
                        }
                    }
                    result = (F_aut * sp.w) + (B_aut * (1.0f - sp.w));
                }
                else
                {
                    bool _9682;
                    if (hasSpriteLayer_1)
                    {
                        _9682 = sp.w >= 0.9900000095367431640625f;
                    }
                    else
                    {
                        _9682 = hasSpriteLayer_1;
                    }
                    float3 _9683;
                    if (_9682)
                    {
                        _9683 = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                    }
                    else
                    {
                        _9683 = src;
                    }
                    float3 F_1 = _9683;
                    float3 param_126 = F_1;
                    float3 param_127 = here;
                    float param_128 = autFallbackBase;
                    float2 param_129 = lot;
                    float param_130 = amount;
                    float param_131 = outdoor;
                    bool param_132 = sim;
                    bool param_133 = mapped;
                    bool param_134 = hasLiveFloraMap;
                    float param_135;
                    float3 _9715 = applyAutumnFoliage(param_126, param_127, param_128, param_129, param_130, param_131, param_132, param_133, param_134, param_135);
                    folAct = param_135;
                    result = _9715;
                }
                if ((!sim) && (folAct > 0.00999999977648258209228515625f))
                {
                    lift = float4(clamp(folAct, 0.0f, 1.0f), 0.0f, 0.0f, 0.0f);
                }
            }
            else
            {
                float3 param_136 = src;
                float3 param_137 = here;
                float2 param_138 = lot;
                float param_139 = lotPixelScale;
                float param_140 = amount;
                float param_141 = outdoor;
                float param_142 = skyExposed;
                bool param_143 = mapped;
                bool param_144 = hasLiveFloraMap;
                bool param_145 = false;
                result = applyAutumnGround(param_136, param_137, param_138, param_139, param_140, param_141, param_142, param_143, param_144, param_145);
            }
            bool _9755 = ((frost > 0.0199999995529651641845703125f) && (skyExposed > 0.001000000047497451305389404296875f)) && (!sim);
            bool _9762;
            if (_9755)
            {
                _9762 = ground || (green > 0.0500000007450580596923828125f);
            }
            else
            {
                _9762 = _9755;
            }
            if (_9762)
            {
                float2 param_146 = lot * 6.0f;
                float2 param_147 = (lot * 19.0f) + 7.099999904632568359375f.xx;
                float rime_1 = smoothstep(0.37999999523162841796875f, 0.839999973773956298828125f, (valueNoise(param_146) * 0.550000011920928955078125f) + (valueNoise(param_147) * 0.449999988079071044921875f));
                float _9782;
                if (ground)
                {
                    float2 param_148 = here.xy;
                    float _9788 = pavedAt(param_148);
                    _9782 = 1.0f - (0.85000002384185791015625f * _9788);
                }
                else
                {
                    _9782 = green;
                }
                float mask = _9782;
                float3 param_149 = float3(0.7799999713897705078125f, 0.86000001430511474609375f, 0.949999988079071044921875f);
                float3 frostTint_1 = srgbToLinear(param_149) * clamp(lum / 0.119999997317790985107421875f, 0.3499999940395355224609375f, 1.25f);
                result = lerp(result, frostTint_1, ((((frost * rime_1) * mask) * skyExposed) * (ground ? 0.300000011920928955078125f : 0.20000000298023223876953125f)).xxx);
            }
        }
        else
        {
            float winterOutdoor = min(outdoor, skyExposed);
            if (mapped)
            {
                float3 param_150 = here;
                winterOutdoor *= (1.0f - smoothstep(0.319999992847442626953125f, 0.4799999892711639404296875f, indoors(param_150)));
            }
            if (winterOutdoor > 0.0f)
            {
                uint _9837_dummy_parameter;
                bool hasSpriteLayer_2 = int2(spvTextureSize(spriteMap, uint(0), _9837_dummy_parameter)).x > 4;
                float4 _9842;
                if (hasSpriteLayer_2)
                {
                    _9842 = spriteMap.Load(int3(int2(pixel), 0));
                }
                else
                {
                    _9842 = 0.0f.xxxx;
                }
                float4 sp_1 = _9842;
                bool _9859;
                if (hasSpriteLayer_2)
                {
                    _9859 = sp_1.w > 0.0040000001899898052215576171875f;
                }
                else
                {
                    _9859 = hasSpriteLayer_2;
                }
                bool _9865;
                if (_9859)
                {
                    _9865 = sp_1.w < 0.9900000095367431640625f;
                }
                else
                {
                    _9865 = _9859;
                }
                bool hasPartialSprite = _9865;
                float3 _9868;
                if (hasPartialSprite)
                {
                    _9868 = clamp((src - sp_1.xyz) / max(1.0f - sp_1.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                }
                else
                {
                    _9868 = src;
                }
                float3 spriteB = _9868;
                float3 _9887;
                if (hasPartialSprite)
                {
                    _9887 = clamp(sp_1.xyz / sp_1.w.xxx, 0.0f.xxx, 1.0f.xxx);
                }
                else
                {
                    _9887 = src;
                }
                float3 spriteF = _9887;
                float3 _9904;
                if (ground && hasPartialSprite)
                {
                    _9904 = spriteB;
                }
                else
                {
                    bool3 _9915 = ((!ground) && hasPartialSprite).xxx;
                    _9904 = float3(_9915.x ? spriteF.x : src.x, _9915.y ? spriteF.y : src.y, _9915.z ? spriteF.z : src.z);
                }
                float3 workSrc = _9904;
                float vacLot = 1.0f - smoothstep(0.25f, 0.75f, ambient_seasonExtra.x);
                float3 param_151 = workSrc;
                float2 param_152 = here.xy;
                float param_153 = float(ground);
                float param_154 = vacLot;
                float param_155;
                float param_156;
                float param_157;
                float param_158;
                float param_159;
                evalGroundTerms(param_151, param_152, param_153, param_154, param_155, param_156, param_157, param_158, param_159);
                float isVacSnowLot = param_155;
                float earthMask = param_156;
                float terrainWear = param_157;
                float workGreen = param_158;
                float workLum = param_159;
                float2 param_160 = lot;
                float hereCrust = snowCrust(param_160);
                float3 _9955;
                if (sim)
                {
                    _9955 = workSrc;
                }
                else
                {
                    float3 param_161 = workSrc;
                    float3 param_162 = here;
                    float2 param_163 = lot;
                    float param_164 = workLum;
                    float param_165 = workGreen;
                    float param_166 = hereCrust;
                    float param_167 = earthMask;
                    float param_168 = terrainWear;
                    float param_169 = isVacSnowLot;
                    float param_170 = covered;
                    bool param_171 = ground;
                    float param_172 = amount;
                    _9955 = winterDullColor(param_161, param_162, param_163, param_164, param_165, param_166, param_167, param_168, param_169, param_170, param_171, param_172);
                }
                float3 dull = _9955;
                float deep = clamp(amount - 1.0f, 0.0f, 1.0f);
                float poolWater = 0.0f;
                bool _9992 = !sim;
                bool _10000;
                if (_9992)
                {
                    _10000 = (!ground) || (!mapped);
                }
                else
                {
                    _10000 = _9992;
                }
                if (_10000)
                {
                    float2 maxIdx = ambient_extent.xy - 1.0f.xx;
                    float facing = 1.0f;
                    if (!ground)
                    {
                        float3 p = centre.xyz;
                        float s1 = max(2.0f, 2.0f * ambient_view.z);
                        float s2 = s1 * 2.0f;
                        float wxSum = 0.0f;
                        float wySum = 0.0f;
                        float3 dxAcc = 0.0f.xxx;
                        float3 dyAcc = 0.0f.xxx;
                        bool lOk1 = false;
                        bool rOk1 = false;
                        bool uOk1 = false;
                        bool dOk1 = false;
                        for (int r = 0; r < 2; r++)
                        {
                            float st = (r == 0) ? s1 : s2;
                            float w = (r == 0) ? 0.60000002384185791015625f : 0.4000000059604644775390625f;
                            float2 lPx = floor(clamp(pixel - float2(st, 0.0f), 0.0f.xx, maxIdx)) + 0.5f.xx;
                            float2 rPx = floor(clamp(pixel + float2(st, 0.0f), 0.0f.xx, maxIdx)) + 0.5f.xx;
                            float2 param_173 = lPx;
                            float4 ql = positionAt(param_173);
                            float2 param_174 = rPx;
                            float4 qr = positionAt(param_174);
                            float dxl = abs(p.x - ql.x);
                            float dxr = abs(qr.x - p.x);
                            bool _10099 = (ql.w < 0.25f) && (dxl > 0.25f);
                            bool _10114;
                            if (_10099)
                            {
                                _10114 = abs(ql.z - p.z) < ((1.60000002384185791015625f * dxl) + 4.5f);
                            }
                            else
                            {
                                _10114 = _10099;
                            }
                            bool lOk = _10114;
                            bool _10121 = (qr.w < 0.25f) && (dxr > 0.25f);
                            bool _10134;
                            if (_10121)
                            {
                                _10134 = abs(qr.z - p.z) < ((1.60000002384185791015625f * dxr) + 4.5f);
                            }
                            else
                            {
                                _10134 = _10121;
                            }
                            bool rOk = _10134;
                            if (workGreen < 0.1500000059604644775390625f)
                            {
                                bool _10151;
                                if (lOk)
                                {
                                    float3 param_175 = source.Load(int3(int2(lPx), 0)).xyz;
                                    _10151 = greenOf(param_175) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _10151 = lOk;
                                }
                                if (_10151)
                                {
                                    lOk = false;
                                }
                                bool _10166;
                                if (rOk)
                                {
                                    float3 param_176 = source.Load(int3(int2(rPx), 0)).xyz;
                                    _10166 = greenOf(param_176) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _10166 = rOk;
                                }
                                if (_10166)
                                {
                                    rOk = false;
                                }
                                if (r == 0)
                                {
                                    if (lOk)
                                    {
                                        float2 mPx = floor(clamp(pixel - float2(0.5f * st, 0.0f), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_177 = mPx;
                                        float4 qm = positionAt(param_177);
                                        bool _10193 = qm.w >= 0.25f;
                                        bool _10212;
                                        if (!_10193)
                                        {
                                            _10212 = abs(qm.z - p.z) >= ((1.60000002384185791015625f * abs(p.x - qm.x)) + 4.5f);
                                        }
                                        else
                                        {
                                            _10212 = _10193;
                                        }
                                        bool _10225;
                                        if (!_10212)
                                        {
                                            float3 param_178 = source.Load(int3(int2(mPx), 0)).xyz;
                                            _10225 = greenOf(param_178) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _10225 = _10212;
                                        }
                                        if (_10225)
                                        {
                                            lOk = false;
                                        }
                                    }
                                    if (rOk)
                                    {
                                        float2 mPx_1 = floor(clamp(pixel + float2(0.5f * st, 0.0f), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_179 = mPx_1;
                                        float4 qm_1 = positionAt(param_179);
                                        bool _10248 = qm_1.w >= 0.25f;
                                        bool _10267;
                                        if (!_10248)
                                        {
                                            _10267 = abs(qm_1.z - p.z) >= ((1.60000002384185791015625f * abs(qm_1.x - p.x)) + 4.5f);
                                        }
                                        else
                                        {
                                            _10267 = _10248;
                                        }
                                        bool _10280;
                                        if (!_10267)
                                        {
                                            float3 param_180 = source.Load(int3(int2(mPx_1), 0)).xyz;
                                            _10280 = greenOf(param_180) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _10280 = _10267;
                                        }
                                        if (_10280)
                                        {
                                            rOk = false;
                                        }
                                    }
                                }
                                else
                                {
                                    lOk = lOk && lOk1;
                                    rOk = rOk && rOk1;
                                }
                            }
                            if (r == 0)
                            {
                                lOk1 = lOk;
                                rOk1 = rOk;
                            }
                            if (lOk && rOk)
                            {
                                dxAcc += ((qr.xyz - ql.xyz) * (0.5f * w));
                                wxSum += w;
                            }
                            else
                            {
                                if (rOk)
                                {
                                    dxAcc += ((qr.xyz - p) * w);
                                    wxSum += w;
                                }
                                else
                                {
                                    if (lOk)
                                    {
                                        dxAcc += ((p - ql.xyz) * w);
                                        wxSum += w;
                                    }
                                }
                            }
                            float2 uPx = floor(clamp(pixel - float2(0.0f, st), 0.0f.xx, maxIdx)) + 0.5f.xx;
                            float2 dPx = floor(clamp(pixel + float2(0.0f, st), 0.0f.xx, maxIdx)) + 0.5f.xx;
                            float2 param_181 = uPx;
                            float4 qu = positionAt(param_181);
                            float2 param_182 = dPx;
                            float4 qd = positionAt(param_182);
                            float dyu = abs(p.y - qu.y);
                            float dyd = abs(qd.y - p.y);
                            bool _10392 = (qu.w < 0.25f) && (dyu > 0.25f);
                            bool _10405;
                            if (_10392)
                            {
                                _10405 = abs(qu.z - p.z) < ((2.2000000476837158203125f * dyu) + 4.5f);
                            }
                            else
                            {
                                _10405 = _10392;
                            }
                            bool uOk = _10405;
                            bool _10412 = (qd.w < 0.25f) && (dyd > 0.25f);
                            bool _10425;
                            if (_10412)
                            {
                                _10425 = abs(qd.z - p.z) < ((2.2000000476837158203125f * dyd) + 4.5f);
                            }
                            else
                            {
                                _10425 = _10412;
                            }
                            bool dOk = _10425;
                            if (workGreen < 0.1500000059604644775390625f)
                            {
                                bool _10442;
                                if (uOk)
                                {
                                    float3 param_183 = source.Load(int3(int2(uPx), 0)).xyz;
                                    _10442 = greenOf(param_183) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _10442 = uOk;
                                }
                                if (_10442)
                                {
                                    uOk = false;
                                }
                                bool _10457;
                                if (dOk)
                                {
                                    float3 param_184 = source.Load(int3(int2(dPx), 0)).xyz;
                                    _10457 = greenOf(param_184) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _10457 = dOk;
                                }
                                if (_10457)
                                {
                                    dOk = false;
                                }
                                if (r == 0)
                                {
                                    if (uOk)
                                    {
                                        float2 mPx_2 = floor(clamp(pixel - float2(0.0f, 0.5f * st), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_185 = mPx_2;
                                        float4 qm_2 = positionAt(param_185);
                                        bool _10484 = qm_2.w >= 0.25f;
                                        bool _10503;
                                        if (!_10484)
                                        {
                                            _10503 = abs(qm_2.z - p.z) >= ((2.2000000476837158203125f * abs(p.y - qm_2.y)) + 4.5f);
                                        }
                                        else
                                        {
                                            _10503 = _10484;
                                        }
                                        bool _10516;
                                        if (!_10503)
                                        {
                                            float3 param_186 = source.Load(int3(int2(mPx_2), 0)).xyz;
                                            _10516 = greenOf(param_186) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _10516 = _10503;
                                        }
                                        if (_10516)
                                        {
                                            uOk = false;
                                        }
                                    }
                                    if (dOk)
                                    {
                                        float2 mPx_3 = floor(clamp(pixel + float2(0.0f, 0.5f * st), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_187 = mPx_3;
                                        float4 qm_3 = positionAt(param_187);
                                        bool _10539 = qm_3.w >= 0.25f;
                                        bool _10558;
                                        if (!_10539)
                                        {
                                            _10558 = abs(qm_3.z - p.z) >= ((2.2000000476837158203125f * abs(qm_3.y - p.y)) + 4.5f);
                                        }
                                        else
                                        {
                                            _10558 = _10539;
                                        }
                                        bool _10571;
                                        if (!_10558)
                                        {
                                            float3 param_188 = source.Load(int3(int2(mPx_3), 0)).xyz;
                                            _10571 = greenOf(param_188) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _10571 = _10558;
                                        }
                                        if (_10571)
                                        {
                                            dOk = false;
                                        }
                                    }
                                }
                                else
                                {
                                    uOk = uOk && uOk1;
                                    dOk = dOk && dOk1;
                                }
                            }
                            if (r == 0)
                            {
                                uOk1 = uOk;
                                dOk1 = dOk;
                            }
                            if (uOk && dOk)
                            {
                                dyAcc += ((qd.xyz - qu.xyz) * (0.5f * w));
                                wySum += w;
                            }
                            else
                            {
                                if (dOk)
                                {
                                    dyAcc += ((qd.xyz - p) * w);
                                    wySum += w;
                                }
                                else
                                {
                                    if (uOk)
                                    {
                                        dyAcc += ((p - qu.xyz) * w);
                                        wySum += w;
                                    }
                                }
                            }
                        }
                        facing = 0.0f;
                        if ((wxSum > 0.0f) && (wySum > 0.0f))
                        {
                            float3 dx = dxAcc / wxSum.xxx;
                            float3 dy = dyAcc / wySum.xxx;
                            float3 cr = cross(dy, dx);
                            float crLen = length(cr);
                            if (crLen > 9.9999997473787516355514526367188e-06f)
                            {
                                float3 n = cr / crLen.xxx;
                                if (n.z < 0.0f)
                                {
                                    n = -n;
                                }
                                facing = clamp(dot(n, float3(0.0f, -0.866025388240814208984375f, 0.5f)), 0.0f, 1.0f);
                            }
                        }
                    }
                    float2 param_189 = (lot * 0.180000007152557373046875f) + 4.30000019073486328125f.xx;
                    float2 param_190 = (lot * 0.4199999868869781494140625f) + 13.1000003814697265625f.xx;
                    float macroWind = (valueNoise(param_189) * 0.7400000095367431640625f) + (valueNoise(param_190) * 0.2599999904632568359375f);
                    float effDepth = max(0.0f, (amount * (1.0f - (0.319999992847442626953125f * covered))) + (((macroWind - 0.5f) * 0.0500000007450580596923828125f) * smoothstep(0.0f, 0.1599999964237213134765625f, amount)));
                    float lying = clamp(lerp(0.449999988079071044921875f * smoothstep(0.01200000010430812835693359375f, 0.2800000011920928955078125f, effDepth), 1.0f, smoothstep(0.20000000298023223876953125f, 0.680000007152557373046875f, effDepth)), 0.0f, 1.0f);
                    float _10725;
                    if (mapped)
                    {
                        float2 param_191 = pixel;
                        _10725 = groundAt(param_191);
                    }
                    else
                    {
                        _10725 = -100000.0f;
                    }
                    float baseAlt = _10725;
                    float _10736;
                    if (baseAlt > (-10000.0f))
                    {
                        float2 param_192 = centre.xy;
                        float param_193 = baseAlt / 27.7128124237060546875f;
                        bool param_194 = true;
                        float2 param_195 = ambient_frame.xy;
                        _10736 = lotPoint(param_192, param_193, param_194, param_195).z;
                    }
                    else
                    {
                        _10736 = ambient_contact.w;
                    }
                    float groundFallback = _10736;
                    float _10758;
                    if (mapped)
                    {
                        float2 param_196 = here.xy;
                        float param_197 = groundFallback;
                        _10758 = terrainBaseAt(param_196, param_197);
                    }
                    else
                    {
                        _10758 = groundFallback;
                    }
                    float roofBase = _10758;
                    float _10772;
                    if (mapped)
                    {
                        _10772 = here.z - roofBase;
                    }
                    else
                    {
                        _10772 = 0.0f;
                    }
                    float relZ = _10772;
                    int roofWedges = 0;
                    float bestRoofFacing = 0.0f;
                    if ((((!ground) && mapped) && (relZ > 3.0299999713897705078125f)) && (workGreen < 0.3499999940395355224609375f))
                    {
                        float3 p0 = centre.xyz;
                        float2 maxPx = ambient_extent.xy - 0.5f.xx;
                        float rP = max(3.0f, 6.5f * ambient_view.z);
                        float wP = max(1.2000000476837158203125f, 1.5f * ambient_view.z);
                        float planeTol = clamp(0.319999992847442626953125f / max(ambient_view.z, 0.25f), 0.319999992847442626953125f, 1.14999997615814208984375f);
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
                            float2 pML = clamp(floor((pixel + (dir * (0.5f * rP))) + (perp * (0.5f * wP))) + 0.5f.xx, 0.5f.xx, maxPx);
                            float2 pMR = clamp(floor((pixel + (dir * (0.5f * rP))) - (perp * (0.5f * wP))) + 0.5f.xx, 0.5f.xx, maxPx);
                            float2 pT = clamp(floor(pixel + (dir * rP)) + 0.5f.xx, 0.5f.xx, maxPx);
                            float2 pL = clamp(floor((pixel + (dir * rP)) + (perp * wP)) + 0.5f.xx, 0.5f.xx, maxPx);
                            float2 pR = clamp(floor((pixel + (dir * rP)) - (perp * wP)) + 0.5f.xx, 0.5f.xx, maxPx);
                            bool _10954 = length(pT - pixel) < (0.64999997615814208984375f * rP);
                            bool _10965;
                            if (!_10954)
                            {
                                _10965 = length(pL - pR) < (0.75f * wP);
                            }
                            else
                            {
                                _10965 = _10954;
                            }
                            if (_10965)
                            {
                                continue;
                            }
                            float2 param_198 = pML;
                            float4 qML = positionAt(param_198);
                            float2 param_199 = pMR;
                            float4 qMR = positionAt(param_199);
                            float2 param_200 = pT;
                            float4 qT = positionAt(param_200);
                            float2 param_201 = pL;
                            float4 qL = positionAt(param_201);
                            float2 param_202 = pR;
                            float4 qR = positionAt(param_202);
                            bool _10991 = qML.w < 0.25f;
                            bool _11002;
                            if (_10991)
                            {
                                _11002 = abs(qML.z - p0.z) < 75.0f;
                            }
                            else
                            {
                                _11002 = _10991;
                            }
                            bool _11008;
                            if (_11002)
                            {
                                _11008 = qMR.w < 0.25f;
                            }
                            else
                            {
                                _11008 = _11002;
                            }
                            bool _11018;
                            if (_11008)
                            {
                                _11018 = abs(qMR.z - p0.z) < 75.0f;
                            }
                            else
                            {
                                _11018 = _11008;
                            }
                            bool _11024;
                            if (_11018)
                            {
                                _11024 = qT.w < 0.25f;
                            }
                            else
                            {
                                _11024 = _11018;
                            }
                            bool _11035;
                            if (_11024)
                            {
                                _11035 = abs(qT.z - p0.z) < 130.0f;
                            }
                            else
                            {
                                _11035 = _11024;
                            }
                            bool _11041;
                            if (_11035)
                            {
                                _11041 = qL.w < 0.25f;
                            }
                            else
                            {
                                _11041 = _11035;
                            }
                            bool _11051;
                            if (_11041)
                            {
                                _11051 = abs(qL.z - p0.z) < 130.0f;
                            }
                            else
                            {
                                _11051 = _11041;
                            }
                            bool _11057;
                            if (_11051)
                            {
                                _11057 = qR.w < 0.25f;
                            }
                            else
                            {
                                _11057 = _11051;
                            }
                            bool _11067;
                            if (_11057)
                            {
                                _11067 = abs(qR.z - p0.z) < 130.0f;
                            }
                            else
                            {
                                _11067 = _11057;
                            }
                            bool _11078;
                            if (_11067)
                            {
                                _11078 = abs(qL.z - qR.z) < 45.0f;
                            }
                            else
                            {
                                _11078 = _11067;
                            }
                            if (_11078)
                            {
                                float3 cr_1 = cross(qL.xyz - p0, qR.xyz - p0);
                                float crLen_1 = length(cr_1);
                                if (crLen_1 > 1.0f)
                                {
                                    float3 nW = cr_1 / crLen_1.xxx;
                                    if (nW.z < 0.0f)
                                    {
                                        nW = -nW;
                                    }
                                    float wFacing = dot(nW, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                                    bool _11117 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.939999997615814208984375f);
                                    bool _11123;
                                    if (_11117)
                                    {
                                        _11123 = nW.z > 0.02500000037252902984619140625f;
                                    }
                                    else
                                    {
                                        _11123 = _11117;
                                    }
                                    bool _11130;
                                    if (_11123)
                                    {
                                        _11130 = abs(nW.x) > 0.119999997317790985107421875f;
                                    }
                                    else
                                    {
                                        _11130 = _11123;
                                    }
                                    if (_11130)
                                    {
                                        float errML = abs(dot(qML.xyz - p0, nW));
                                        float errMR = abs(dot(qMR.xyz - p0, nW));
                                        float errT = abs(dot(qT.xyz - p0, nW));
                                        if (((errML < planeTol) && (errMR < planeTol)) && (errT < planeTol))
                                        {
                                            roofWedges = 1;
                                            bestRoofFacing = wFacing;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (roofWedges == 0)
                        {
                            float shift = max(2.0f, 5.0f * ambient_view.z);
                            float2 dir_1;
                            for (int i_2 = 0; i_2 < 12; i_2++)
                            {
                                if (i_2 < 8)
                                {
                                    float a_1 = float(i_2) * 0.785398185253143310546875f;
                                    dir_1 = float2(cos(a_1), sin(a_1));
                                }
                                else
                                {
                                    float sx_1 = ((i_2 == 8) || (i_2 == 9)) ? 0.89442718029022216796875f : (-0.89442718029022216796875f);
                                    float sy_1 = ((i_2 == 8) || (i_2 == 10)) ? 0.447213590145111083984375f : (-0.447213590145111083984375f);
                                    dir_1 = float2(sx_1, sy_1);
                                }
                                float2 perp_1 = float2(-dir_1.y, dir_1.x);
                                float2 pB = clamp(floor(pixel + (dir_1 * shift)) + 0.5f.xx, 0.5f.xx, maxPx);
                                if (length(pB - pixel) < 1.0f)
                                {
                                    continue;
                                }
                                float2 param_203 = pB;
                                float4 qB = positionAt(param_203);
                                bool _11255 = qB.w >= 0.25f;
                                bool _11267;
                                if (!_11255)
                                {
                                    _11267 = abs(qB.z - p0.z) >= 60.0f;
                                }
                                else
                                {
                                    _11267 = _11255;
                                }
                                if (_11267)
                                {
                                    continue;
                                }
                                float2 pML_1 = clamp(floor((pB + (dir_1 * (0.5f * rP))) + (perp_1 * (0.5f * wP))) + 0.5f.xx, 0.5f.xx, maxPx);
                                float2 pMR_1 = clamp(floor((pB + (dir_1 * (0.5f * rP))) - (perp_1 * (0.5f * wP))) + 0.5f.xx, 0.5f.xx, maxPx);
                                float2 pT_1 = clamp(floor(pB + (dir_1 * rP)) + 0.5f.xx, 0.5f.xx, maxPx);
                                float2 pL_1 = clamp(floor((pB + (dir_1 * rP)) + (perp_1 * wP)) + 0.5f.xx, 0.5f.xx, maxPx);
                                float2 pR_1 = clamp(floor((pB + (dir_1 * rP)) - (perp_1 * wP)) + 0.5f.xx, 0.5f.xx, maxPx);
                                bool _11352 = length(pT_1 - pB) < (0.64999997615814208984375f * rP);
                                bool _11363;
                                if (!_11352)
                                {
                                    _11363 = length(pL_1 - pR_1) < (0.75f * wP);
                                }
                                else
                                {
                                    _11363 = _11352;
                                }
                                if (_11363)
                                {
                                    continue;
                                }
                                float2 param_204 = pML_1;
                                float4 qML_1 = positionAt(param_204);
                                float2 param_205 = pMR_1;
                                float4 qMR_1 = positionAt(param_205);
                                float2 param_206 = pT_1;
                                float4 qT_1 = positionAt(param_206);
                                float2 param_207 = pL_1;
                                float4 qL_1 = positionAt(param_207);
                                float2 param_208 = pR_1;
                                float4 qR_1 = positionAt(param_208);
                                bool _11389 = qML_1.w < 0.25f;
                                bool _11399;
                                if (_11389)
                                {
                                    _11399 = abs(qML_1.z - qB.z) < 75.0f;
                                }
                                else
                                {
                                    _11399 = _11389;
                                }
                                bool _11405;
                                if (_11399)
                                {
                                    _11405 = qMR_1.w < 0.25f;
                                }
                                else
                                {
                                    _11405 = _11399;
                                }
                                bool _11415;
                                if (_11405)
                                {
                                    _11415 = abs(qMR_1.z - qB.z) < 75.0f;
                                }
                                else
                                {
                                    _11415 = _11405;
                                }
                                bool _11421;
                                if (_11415)
                                {
                                    _11421 = qT_1.w < 0.25f;
                                }
                                else
                                {
                                    _11421 = _11415;
                                }
                                bool _11431;
                                if (_11421)
                                {
                                    _11431 = abs(qT_1.z - qB.z) < 130.0f;
                                }
                                else
                                {
                                    _11431 = _11421;
                                }
                                bool _11437;
                                if (_11431)
                                {
                                    _11437 = qL_1.w < 0.25f;
                                }
                                else
                                {
                                    _11437 = _11431;
                                }
                                bool _11447;
                                if (_11437)
                                {
                                    _11447 = abs(qL_1.z - qB.z) < 130.0f;
                                }
                                else
                                {
                                    _11447 = _11437;
                                }
                                bool _11453;
                                if (_11447)
                                {
                                    _11453 = qR_1.w < 0.25f;
                                }
                                else
                                {
                                    _11453 = _11447;
                                }
                                bool _11463;
                                if (_11453)
                                {
                                    _11463 = abs(qR_1.z - qB.z) < 130.0f;
                                }
                                else
                                {
                                    _11463 = _11453;
                                }
                                bool _11473;
                                if (_11463)
                                {
                                    _11473 = abs(qL_1.z - qR_1.z) < 45.0f;
                                }
                                else
                                {
                                    _11473 = _11463;
                                }
                                if (_11473)
                                {
                                    float3 cr_2 = cross(qL_1.xyz - qB.xyz, qR_1.xyz - qB.xyz);
                                    float crLen_2 = length(cr_2);
                                    if (crLen_2 > 1.0f)
                                    {
                                        float3 nW_1 = cr_2 / crLen_2.xxx;
                                        if (nW_1.z < 0.0f)
                                        {
                                            nW_1 = -nW_1;
                                        }
                                        float wFacing_1 = dot(nW_1, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                                        bool _11514 = (wFacing_1 > 0.319999992847442626953125f) && (wFacing_1 < 0.939999997615814208984375f);
                                        bool _11520;
                                        if (_11514)
                                        {
                                            _11520 = nW_1.z > 0.02500000037252902984619140625f;
                                        }
                                        else
                                        {
                                            _11520 = _11514;
                                        }
                                        bool _11527;
                                        if (_11520)
                                        {
                                            _11527 = abs(nW_1.x) > 0.119999997317790985107421875f;
                                        }
                                        else
                                        {
                                            _11527 = _11520;
                                        }
                                        if (_11527)
                                        {
                                            float errML_1 = abs(dot(qML_1.xyz - qB.xyz, nW_1));
                                            float errMR_1 = abs(dot(qMR_1.xyz - qB.xyz, nW_1));
                                            float errT_1 = abs(dot(qT_1.xyz - qB.xyz, nW_1));
                                            float err0 = abs(dot(p0 - qB.xyz, nW_1));
                                            bool _11575 = ((errML_1 < planeTol) && (errMR_1 < planeTol)) && (errT_1 < planeTol);
                                            bool _11582;
                                            if (_11575)
                                            {
                                                _11582 = err0 < (planeTol * 2.2000000476837158203125f);
                                            }
                                            else
                                            {
                                                _11582 = _11575;
                                            }
                                            if (_11582)
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
                        if ((roofWedges == 0) && (facing >= 0.910000026226043701171875f))
                        {
                            float rF = max(6.0f, 22.0f * ambient_view.z);
                            float wF = max(3.0f, 10.0f * ambient_view.z);
                            for (int i_3 = 0; i_3 < 8; i_3++)
                            {
                                float a_2 = float(i_3) * 0.785398185253143310546875f;
                                float2 dir_2 = float2(cos(a_2), sin(a_2));
                                float2 perp_2 = float2(-dir_2.y, dir_2.x);
                                float2 pML_2 = (pixel + (dir_2 * (0.5f * rF))) + (perp_2 * (0.5f * wF));
                                float2 pMR_2 = (pixel + (dir_2 * (0.5f * rF))) - (perp_2 * (0.5f * wF));
                                float2 pT_2 = pixel + (dir_2 * rF);
                                float2 pL_2 = (pixel + (dir_2 * rF)) + (perp_2 * wF);
                                float2 pR_2 = (pixel + (dir_2 * rF)) - (perp_2 * wF);
                                bool _11685 = any(bool2(pML_2.x < 0.5f.xx.x, pML_2.y < 0.5f.xx.y));
                                bool _11693;
                                if (!_11685)
                                {
                                    _11693 = any(bool2(pML_2.x > maxPx.x, pML_2.y > maxPx.y));
                                }
                                else
                                {
                                    _11693 = _11685;
                                }
                                bool _11700;
                                if (!_11693)
                                {
                                    _11700 = any(bool2(pMR_2.x < 0.5f.xx.x, pMR_2.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _11700 = _11693;
                                }
                                bool _11708;
                                if (!_11700)
                                {
                                    _11708 = any(bool2(pMR_2.x > maxPx.x, pMR_2.y > maxPx.y));
                                }
                                else
                                {
                                    _11708 = _11700;
                                }
                                bool _11715;
                                if (!_11708)
                                {
                                    _11715 = any(bool2(pT_2.x < 0.5f.xx.x, pT_2.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _11715 = _11708;
                                }
                                bool _11723;
                                if (!_11715)
                                {
                                    _11723 = any(bool2(pT_2.x > maxPx.x, pT_2.y > maxPx.y));
                                }
                                else
                                {
                                    _11723 = _11715;
                                }
                                bool _11730;
                                if (!_11723)
                                {
                                    _11730 = any(bool2(pL_2.x < 0.5f.xx.x, pL_2.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _11730 = _11723;
                                }
                                bool _11738;
                                if (!_11730)
                                {
                                    _11738 = any(bool2(pL_2.x > maxPx.x, pL_2.y > maxPx.y));
                                }
                                else
                                {
                                    _11738 = _11730;
                                }
                                bool _11745;
                                if (!_11738)
                                {
                                    _11745 = any(bool2(pR_2.x < 0.5f.xx.x, pR_2.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _11745 = _11738;
                                }
                                bool _11753;
                                if (!_11745)
                                {
                                    _11753 = any(bool2(pR_2.x > maxPx.x, pR_2.y > maxPx.y));
                                }
                                else
                                {
                                    _11753 = _11745;
                                }
                                if (_11753)
                                {
                                    continue;
                                }
                                float2 param_209 = pML_2;
                                float4 qML_2 = positionAt(param_209);
                                float2 param_210 = pMR_2;
                                float4 qMR_2 = positionAt(param_210);
                                float2 param_211 = pT_2;
                                float4 qT_2 = positionAt(param_211);
                                float2 param_212 = pL_2;
                                float4 qL_2 = positionAt(param_212);
                                float2 param_213 = pR_2;
                                float4 qR_2 = positionAt(param_213);
                                bool _11779 = qML_2.w < 0.25f;
                                bool _11790;
                                if (_11779)
                                {
                                    _11790 = abs(qML_2.z - p0.z) < 28.0f;
                                }
                                else
                                {
                                    _11790 = _11779;
                                }
                                bool _11796;
                                if (_11790)
                                {
                                    _11796 = qMR_2.w < 0.25f;
                                }
                                else
                                {
                                    _11796 = _11790;
                                }
                                bool _11806;
                                if (_11796)
                                {
                                    _11806 = abs(qMR_2.z - p0.z) < 28.0f;
                                }
                                else
                                {
                                    _11806 = _11796;
                                }
                                bool _11812;
                                if (_11806)
                                {
                                    _11812 = qT_2.w < 0.25f;
                                }
                                else
                                {
                                    _11812 = _11806;
                                }
                                bool _11823;
                                if (_11812)
                                {
                                    _11823 = abs(qT_2.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _11823 = _11812;
                                }
                                bool _11829;
                                if (_11823)
                                {
                                    _11829 = qL_2.w < 0.25f;
                                }
                                else
                                {
                                    _11829 = _11823;
                                }
                                bool _11839;
                                if (_11829)
                                {
                                    _11839 = abs(qL_2.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _11839 = _11829;
                                }
                                bool _11845;
                                if (_11839)
                                {
                                    _11845 = qR_2.w < 0.25f;
                                }
                                else
                                {
                                    _11845 = _11839;
                                }
                                bool _11855;
                                if (_11845)
                                {
                                    _11855 = abs(qR_2.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _11855 = _11845;
                                }
                                bool _11866;
                                if (_11855)
                                {
                                    _11866 = abs(qL_2.z - qR_2.z) < 20.0f;
                                }
                                else
                                {
                                    _11866 = _11855;
                                }
                                if (_11866)
                                {
                                    float3 cr_3 = cross(qL_2.xyz - p0, qR_2.xyz - p0);
                                    float crLen_3 = length(cr_3);
                                    if (crLen_3 > 1.0f)
                                    {
                                        float3 nW_2 = cr_3 / crLen_3.xxx;
                                        if (nW_2.z < 0.0f)
                                        {
                                            nW_2 = -nW_2;
                                        }
                                        float wFacing_2 = dot(nW_2, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                                        bool _11902 = wFacing_2 >= 0.920000016689300537109375f;
                                        bool _11908;
                                        if (_11902)
                                        {
                                            _11908 = nW_2.z > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _11908 = _11902;
                                        }
                                        if (_11908)
                                        {
                                            float errML_2 = abs(dot(qML_2.xyz - p0, nW_2)) / nW_2.z;
                                            float errMR_2 = abs(dot(qMR_2.xyz - p0, nW_2)) / nW_2.z;
                                            float errT_2 = abs(dot(qT_2.xyz - p0, nW_2)) / nW_2.z;
                                            if (((errML_2 < 0.800000011920928955078125f) && (errMR_2 < 0.800000011920928955078125f)) && (errT_2 < 0.800000011920928955078125f))
                                            {
                                                roofWedges = 1;
                                                bestRoofFacing = wFacing_2;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    bool onRoof = (((!ground) && mapped) && (relZ > 3.0299999713897705078125f)) && (roofWedges >= 1);
                    bool _11975 = ((!ground) && mapped) && (!onRoof);
                    bool _11981;
                    if (_11975)
                    {
                        _11981 = abs(relZ) < 0.2199999988079071044921875f;
                    }
                    else
                    {
                        _11981 = _11975;
                    }
                    float _11985;
                    if (_11981 && (facing > 0.819999992847442626953125f))
                    {
                        _11985 = (smoothstep(0.14000000059604644775390625f, 0.2599999904632568359375f, workSrc.z) * smoothstep(1.5499999523162841796875f, 2.150000095367431640625f, workSrc.z / max(workSrc.x, 0.014999999664723873138427734375f))) * smoothstep(1.25f, 1.75f, workSrc.y / max(workSrc.x, 0.014999999664723873138427734375f));
                    }
                    else
                    {
                        _11985 = 0.0f;
                    }
                    poolWater = _11985;
                    float settle = 1.0f;
                    float organic = 0.0f;
                    float pillowField = 0.0f;
                    float3 param_214 = workSrc;
                    float isFoliage = foliageOf(param_214);
                    float2 capLot = lot;
                    float capCrust = hereCrust;
                    float capLying = lying;
                    if (!ground)
                    {
                        if (onRoof)
                        {
                            float roofSlope = max(facing, bestRoofFacing);
                            settle = smoothstep(0.20000000298023223876953125f, 0.4799999892711639404296875f, roofSlope);
                            float pitchHold = smoothstep(0.23999999463558197021484375f, 0.7799999713897705078125f, roofSlope);
                            float eaveBase = max(1.0f, floor((relZ + 0.44249999523162841796875f) / 2.9500000476837158203125f)) * 2.9500000476837158203125f;
                            float upSlope = clamp((relZ - eaveBase) / 2.5074999332427978515625f, 0.0f, 1.0f);
                            float2 param_215 = float2(dot(lot, float2(0.92847669124603271484375f, 0.37139070034027099609375f)) * 0.0900000035762786865234375f, dot(lot, float2(-0.37139070034027099609375f, 0.92847669124603271484375f)) * 0.23999999463558197021484375f) + float2(6.30000019073486328125f, 2.900000095367431640625f);
                            float roofRibbon = valueNoise(param_215);
                            float tileRidge = smoothstep(0.0500000007450580596923828125f, 0.2199999988079071044921875f, workLum);
                            float eaveLead = (((0.1500000059604644775390625f * (1.0f - upSlope)) + ((roofRibbon - 0.5f) * 0.14000000059604644775390625f)) * smoothstep(0.0f, 0.100000001490116119384765625f, amount)) * (1.0f - (0.64999997615814208984375f * smoothstep(0.5f, 0.949999988079071044921875f, amount)));
                            float roofAmt = max(0.0f, (amount * (0.86000001430511474609375f + (0.2199999988079071044921875f * pitchHold))) + eaveLead);
                            float roofDust = smoothstep(0.0199999995529651641845703125f, 0.300000011920928955078125f, roofAmt) * (1.0f - ((0.4199999868869781494140625f * tileRidge) * (1.0f - smoothstep(0.2199999988079071044921875f, 0.60000002384185791015625f, roofAmt))));
                            float roofBlanket = smoothstep(0.2199999988079071044921875f, 0.680000007152557373046875f, roofAmt - (0.100000001490116119384765625f * tileRidge));
                            capLying = clamp(lerp(0.4199999868869781494140625f * roofDust, 1.0f, roofBlanket), 0.0f, 1.0f);
                        }
                        else
                        {
                            float3 p_1 = centre.xyz;
                            float sc = max(ambient_view.z, 0.25f);
                            float3 param_216 = workSrc;
                            float selfFol = foliageOf(param_216);
                            bool _12137 = (selfFol < 0.1500000059604644775390625f) && (workLum > 0.07999999821186065673828125f);
                            bool _12143;
                            if (_12137)
                            {
                                _12143 = workSrc.z > 0.07999999821186065673828125f;
                            }
                            else
                            {
                                _12143 = _12137;
                            }
                            bool _12152;
                            if (_12143)
                            {
                                _12152 = workSrc.z > (0.680000007152557373046875f * workSrc.y);
                            }
                            else
                            {
                                _12152 = _12143;
                            }
                            bool blossomCand = _12152;
                            bool _12158 = (selfFol < 0.1500000059604644775390625f) && (workLum < 0.02500000037252902984619140625f);
                            bool _12170;
                            if (_12158)
                            {
                                _12170 = workSrc.y > (1.2000000476837158203125f * max(workSrc.x, workSrc.z));
                            }
                            else
                            {
                                _12170 = _12158;
                            }
                            bool darkCreviceCand = _12170;
                            float wSum = 0.3499999940395355224609375f;
                            float folW = 0.3499999940395355224609375f * smoothstep(0.0500000007450580596923828125f, 0.25f, selfFol);
                            float mxSum = 0.0f;
                            float mySum = 0.0f;
                            float mzSum = 0.3499999940395355224609375f * p_1.z;
                            float greenNbr = selfFol;
                            float greenW = 1.0f;
                            float rawFolNbr = selfFol;
                            float rawFolW = 1.0f;
                            float tightGreen = 0.0f;
                            float tightW = 0.0f;
                            float dw;
                            float _12373;
                            float4 tapData[14];
                            for (int i_4 = 0; i_4 < 14; i_4++)
                            {
                                float2 qPx = floor(clamp(pixel + (_12225[i_4].xy * sc), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                float2 param_217 = qPx;
                                float4 q = positionAt(param_217);
                                if (q.w < 0.25f)
                                {
                                    float2 dxy = q.xy - p_1.xy;
                                    float dist = length(dxy);
                                    float3 qCol = source.Load(int3(int2(qPx), 0)).xyz;
                                    float3 param_218 = qCol;
                                    float qFol = foliageOf(param_218);
                                    float qBlos = smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, qCol.z) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, qCol.z / max(qCol.y, 0.0199999995529651641845703125f));
                                    float qPlant = max(qFol, 0.60000002384185791015625f * qBlos);
                                    float fw = _12225[i_4].z * (1.0f - smoothstep(12.0f, 22.0f, abs(q.z - p_1.z)));
                                    rawFolNbr += (qFol * fw);
                                    rawFolW += fw;
                                    if (i_4 < 4)
                                    {
                                        float tw = _12225[i_4].z * (1.0f - smoothstep(10.0f, 18.0f, abs(q.z - p_1.z)));
                                        tightGreen += (qFol * tw);
                                        tightW += tw;
                                    }
                                    if (selfFol >= 0.1500000059604644775390625f)
                                    {
                                        dw = (1.0f - smoothstep(20.0f, 42.0f, abs(q.z - p_1.z))) * smoothstep(0.0599999986588954925537109375f, 0.300000011920928955078125f, qPlant);
                                    }
                                    else
                                    {
                                        if (blossomCand || darkCreviceCand)
                                        {
                                            dw = (1.0f - smoothstep(14.0f, 28.0f, abs(q.z - p_1.z))) * smoothstep(0.0599999986588954925537109375f, 0.300000011920928955078125f, qPlant);
                                        }
                                        else
                                        {
                                            if (qFol > 0.3499999940395355224609375f)
                                            {
                                                _12373 = 0.0f;
                                            }
                                            else
                                            {
                                                _12373 = 1.0f - smoothstep((1.7999999523162841796875f * dist) + 3.0f, (2.2000000476837158203125f * dist) + 6.0f, abs(q.z - p_1.z));
                                            }
                                            dw = _12373;
                                            if (dw > 9.9999997473787516355514526367188e-05f)
                                            {
                                                float2 mPx_4 = floor(clamp((pixel + qPx) * 0.5f, 0.0f.xx, maxIdx)) + 0.5f.xx;
                                                float2 param_219 = mPx_4;
                                                float4 qm_4 = positionAt(param_219);
                                                bool _12412 = qm_4.w >= 0.25f;
                                                bool _12431;
                                                if (!_12412)
                                                {
                                                    _12431 = abs(qm_4.z - (0.5f * (p_1.z + q.z))) >= ((1.7999999523162841796875f * (0.5f * dist)) + 5.0f);
                                                }
                                                else
                                                {
                                                    _12431 = _12412;
                                                }
                                                bool _12444;
                                                if (!_12431)
                                                {
                                                    float3 param_220 = source.Load(int3(int2(mPx_4), 0)).xyz;
                                                    _12444 = foliageOf(param_220) > 0.3499999940395355224609375f;
                                                }
                                                else
                                                {
                                                    _12444 = _12431;
                                                }
                                                if (_12444)
                                                {
                                                    dw = 0.0f;
                                                }
                                            }
                                        }
                                    }
                                    float wt = _12225[i_4].z * dw;
                                    if (wt > 9.9999997473787516355514526367188e-05f)
                                    {
                                        wSum += wt;
                                        folW += (wt * smoothstep(0.100000001490116119384765625f, 0.449999988079071044921875f, qPlant));
                                        mxSum += (wt * dxy.x);
                                        mySum += (wt * dxy.y);
                                        mzSum += (wt * q.z);
                                        greenNbr += (qFol * wt);
                                        greenW += wt;
                                        tapData[i_4] = float4(dxy.x, dxy.y, q.z, wt);
                                    }
                                    else
                                    {
                                        tapData[i_4] = 0.0f.xxxx;
                                    }
                                }
                                else
                                {
                                    tapData[i_4] = 0.0f.xxxx;
                                }
                            }
                            float mx = mxSum / wSum;
                            float my = mySum / wSum;
                            float zSmooth = mzSum / wSum;
                            float sxx = (0.3499999940395355224609375f * mx) * mx;
                            float syy = (0.3499999940395355224609375f * my) * my;
                            float sxy = (0.3499999940395355224609375f * mx) * my;
                            float sxz = ((-0.3499999940395355224609375f) * mx) * (p_1.z - zSmooth);
                            float syz = ((-0.3499999940395355224609375f) * my) * (p_1.z - zSmooth);
                            for (int i_5 = 0; i_5 < 14; i_5++)
                            {
                                float wt_1 = tapData[i_5].w;
                                if (wt_1 > 0.0f)
                                {
                                    float dx_1 = tapData[i_5].x - mx;
                                    float dy_1 = tapData[i_5].y - my;
                                    float dz = tapData[i_5].z - zSmooth;
                                    sxx += ((wt_1 * dx_1) * dx_1);
                                    syy += ((wt_1 * dy_1) * dy_1);
                                    sxy += ((wt_1 * dx_1) * dy_1);
                                    sxz += ((wt_1 * dx_1) * dz);
                                    syz += ((wt_1 * dy_1) * dz);
                                }
                            }
                            float det = (sxx * syy) - (sxy * sxy);
                            float gx_m = 0.0f;
                            float gy_m = 0.0f;
                            float facMacro = 0.0f;
                            float planeErr = 0.0f;
                            if (det > 64.0f)
                            {
                                gx_m = ((syy * sxz) - (sxy * syz)) / det;
                                gy_m = ((sxx * syz) - (sxy * sxz)) / det;
                                float3 nm = normalize(float3(-gx_m, -gy_m, 1.0f));
                                facMacro = clamp(dot(nm, float3(0.0f, -0.866025388240814208984375f, 0.5f)), 0.0f, 1.0f);
                                float errSum = 0.0f;
                                float errW = 0.0f;
                                for (int i_6 = 0; i_6 < 14; i_6++)
                                {
                                    float wt_2 = tapData[i_6].w;
                                    if (wt_2 > 0.0f)
                                    {
                                        float pred = (zSmooth + (gx_m * (tapData[i_6].x - mx))) + (gy_m * (tapData[i_6].y - my));
                                        errSum += (wt_2 * abs(tapData[i_6].z - pred));
                                        errW += wt_2;
                                    }
                                }
                                float _12727;
                                if (errW > 9.9999997473787516355514526367188e-05f)
                                {
                                    _12727 = errSum / errW;
                                }
                                else
                                {
                                    _12727 = 0.0f;
                                }
                                planeErr = _12727;
                            }
                            float topClear = 0.0f;
                            float overhang = 0.0f;
                            for (int i_7 = 0; i_7 < 9; i_7++)
                            {
                                float2 qPx_1 = floor(clamp(pixel + (_12762[i_7].xy * sc), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                float2 param_221 = qPx_1;
                                float4 q_1 = positionAt(param_221);
                                float distY = max(p_1.y - q_1.y, 1.0f);
                                float openW = max(step(0.25f, q_1.w), smoothstep(18.0f, 36.0f, zSmooth - q_1.z));
                                float slopeOpen = smoothstep(-0.2199999988079071044921875f, 0.519999980926513671875f, (zSmooth - q_1.z) / distY);
                                float overT = (1.0f - openW) * smoothstep(0.1599999964237213134765625f, 0.85000002384185791015625f, (q_1.z - zSmooth) / distY);
                                float wt_3 = _12762[i_7].z;
                                topClear += ((openW + ((1.0f - openW) * slopeOpen)) * wt_3);
                                overhang += (overT * wt_3);
                            }
                            float greenLocal = greenNbr / max(greenW, 9.9999997473787516355514526367188e-05f);
                            float _12847;
                            if (tightW > 9.9999997473787516355514526367188e-05f)
                            {
                                _12847 = tightGreen / tightW;
                            }
                            else
                            {
                                _12847 = 0.0f;
                            }
                            float tg = _12847;
                            float selfFoliage = smoothstep(0.07999999821186065673828125f, 0.2800000011920928955078125f, selfFol);
                            float blossom = ((smoothstep(0.07999999821186065673828125f, 0.180000007152557373046875f, workLum) * smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, workSrc.z)) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, workSrc.z / max(workSrc.y, 0.0199999995529651641845703125f))) * smoothstep(0.5f, 0.800000011920928955078125f, tg);
                            float _12878;
                            if (darkCreviceCand)
                            {
                                _12878 = smoothstep(0.579999983310699462890625f, 0.819999992847442626953125f, tg) * smoothstep(2.599999904632568359375f, 3.599999904632568359375f, tightW);
                            }
                            else
                            {
                                _12878 = 0.0f;
                            }
                            float darkCrevice = _12878;
                            isFoliage = max(selfFoliage, max(blossom, darkCrevice));
                            organic = (isFoliage * smoothstep(0.23999999463558197021484375f, 0.4799999892711639404296875f, greenLocal)) * smoothstep(0.949999988079071044921875f, 1.85000002384185791015625f, planeErr);
                            float _12904;
                            if (det > 64.0f)
                            {
                                _12904 = smoothstep(1.14999997615814208984375f, 0.4000000059604644775390625f, planeErr);
                            }
                            else
                            {
                                _12904 = 0.0f;
                            }
                            float planarFactor = _12904;
                            float solidSupport = smoothstep(2.599999904632568359375f, 5.19999980926513671875f, wSum) * smoothstep(48.0f, 128.0f, det);
                            float nearFolFrac = rawFolNbr / max(rawFolW, 9.9999997473787516355514526367188e-05f);
                            float notBushRim = lerp(1.0f, 1.0f - (smoothstep(0.14000000059604644775390625f, 0.36000001430511474609375f, nearFolFrac) * (1.0f - isFoliage)), smoothstep(0.0500000007450580596923828125f, 0.180000007152557373046875f, relZ));
                            float solidFacing = max(facing, facMacro * planarFactor);
                            float settleSolid = ((smoothstep(0.60000002384185791015625f, 0.86000001430511474609375f, solidFacing) * solidSupport) * notBushRim) * (1.0f - smoothstep(0.2800000011920928955078125f, 0.550000011920928955078125f, overhang));
                            float2 param_222 = centre.xy;
                            float param_223 = zSmooth / 27.7128124237060546875f;
                            bool param_224 = false;
                            float2 param_225 = ambient_frame.xy;
                            float3 hereSm = lotPoint(param_222, param_223, param_224, param_225);
                            float2 param_226 = hereSm.xy;
                            float2 lotSm = lotSource(param_226);
                            float edgeSupport = smoothstep(1.60000002384185791015625f, 5.19999980926513671875f, folW);
                            float leafSoft = smoothstep(0.014999999664723873138427734375f, 0.12999999523162841796875f, workLum);
                            float2 param_227 = (lotSm * 1.39999997615814208984375f) + float2(hereSm.z * 1.10000002384185791015625f, (-hereSm.z) * 0.89999997615814208984375f);
                            float pillowNoise = valueNoise(param_227);
                            float dome = (facMacro * 0.4600000083446502685546875f) + (topClear * 0.540000021457672119140625f);
                            pillowField = ((dome * (1.0f - smoothstep(0.20000000298023223876953125f, 0.579999983310699462890625f, overhang))) + ((pillowNoise - 0.5f) * 0.07999999821186065673828125f)) + ((leafSoft - 0.449999988079071044921875f) * 0.0500000007450580596923828125f);
                            float folAmt = max(0.0f, amount * (1.0f - (0.300000011920928955078125f * covered)));
                            float snowGrow = clamp(folAmt / 1.14999997615814208984375f, 0.0f, 1.0f);
                            float settleFoliage = smoothstep(0.540000021457672119140625f - (0.180000007152557373046875f * snowGrow), 0.86000001430511474609375f - (0.100000001490116119384765625f * snowGrow), pillowField) * edgeSupport;
                            settle = lerp(settleSolid, settleFoliage, organic) * (1.0f - poolWater);
                            if (organic > 0.00999999977648258209228515625f)
                            {
                                capLot = lerp(lot, lotSm, organic.xx);
                                float2 param_228 = capLot;
                                capCrust = snowCrust(param_228);
                                float folDust = smoothstep(0.014999999664723873138427734375f, 0.2800000011920928955078125f, folAmt);
                                float folBlanket = smoothstep(0.20000000298023223876953125f, 0.680000007152557373046875f, folAmt);
                                float folLying = clamp(lerp(0.4600000083446502685546875f * folDust, 1.0f, folBlanket), 0.0f, 1.0f);
                                capLying = lerp(lying, folLying, organic);
                            }
                        }
                    }
                    float wallBlock = 0.0f;
                    if (((!ground) && mapped) && (!onRoof))
                    {
                        int storiesN = indoorStories();
                        float wallR = (isFoliage > 0.25f) ? 0.10999999940395355224609375f : 0.4799999892711639404296875f;
                        float2 param_229 = here.xy;
                        float param_230 = here.z;
                        float param_231 = wallR;
                        wallBlock = nearIndoorWall(param_229, param_230, param_231);
                        int maxCheckRow = min((storiesN - 1), max(1, int(floor(max(0.0f, relZ + 0.1500000059604644775390625f) / 2.9500000476837158203125f))));
                        for (int r_1 = 0; r_1 <= maxCheckRow; r_1++)
                        {
                            float zr = (roofBase + (float(r_1) * 2.9500000476837158203125f)) + 0.100000001490116119384765625f;
                            float2 param_232 = here.xy;
                            float param_233 = zr;
                            float param_234 = wallR;
                            wallBlock = max(wallBlock, nearIndoorWall(param_232, param_233, param_234));
                            bool _13126 = isFoliage < 0.25f;
                            bool _13136;
                            if (_13126)
                            {
                                _13136 = relZ > ((float(r_1 + 1) * 2.9500000476837158203125f) - 0.1500000059604644775390625f);
                            }
                            else
                            {
                                _13136 = _13126;
                            }
                            if (_13136)
                            {
                                float2 wallXY = here.xy - (1.25f * max(0.0f, relZ - (float(r_1 + 1) * 2.9500000476837158203125f))).xx;
                                float3 param_235 = float3(wallXY, zr);
                                float2 param_236 = wallXY;
                                float param_237 = zr;
                                float param_238 = 0.519999980926513671875f;
                                wallBlock = max(wallBlock, max(indoors(param_235), nearIndoorWall(param_236, param_237, param_238)));
                            }
                        }
                    }
                    settle *= (1.0f - smoothstep(0.0199999995529651641845703125f, 0.25f, wallBlock));
                    float2 param_239 = (capLot * 0.2599999904632568359375f) + 9.0f.xx;
                    float swell = valueNoise(param_239);
                    float capShade = ((1.0f - capCrust) * lerp(0.0900000035762786865234375f, 0.039999999105930328369140625f, deep)) + ((1.0f - smoothstep(0.20000000298023223876953125f, 0.800000011920928955078125f, swell)) * 0.0900000035762786865234375f);
                    float3 snow = lerp(float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), clamp(capShade, 0.0f, 0.300000011920928955078125f).xxx);
                    snow *= (1.0f + ((0.319999992847442626953125f * (1.0f - (0.699999988079071044921875f * deep))) * (workLum - 0.23999999463558197021484375f)));
                    if (((!ground) && (!onRoof)) && (organic > 0.00999999977648258209228515625f))
                    {
                        float pillowTop = smoothstep(0.4199999868869781494140625f, 0.819999992847442626953125f, pillowField);
                        float orgShade = clamp(((1.0f - pillowTop) * 0.4799999892711639404296875f) + ((1.0f - capCrust) * 0.0599999986588954925537109375f), 0.0f, 0.519999980926513671875f);
                        float3 snowOrg = lerp(float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), orgShade.xxx) * (0.959999978542327880859375f + (0.07999999821186065673828125f * smoothstep(0.014999999664723873138427734375f, 0.12999999523162841796875f, workLum)));
                        snow = lerp(snow, snowOrg, organic.xxx);
                    }
                    float daySun = max(0.0f, 1.0f - ambient_weather.w);
                    float2 param_240 = capLot * 24.0f;
                    float2 param_241 = (capLot * 41.0f) + 31.700000762939453125f.xx;
                    float glint = smoothstep(0.680000007152557373046875f, 0.939999997615814208984375f, valueNoise(param_240) * valueNoise(param_241)) * daySun;
                    snow += ((float3(0.0199999995529651641845703125f, 0.0240000002086162567138671875f, 0.034000001847743988037109375f) * glint) * winterOutdoor);
                    float _13272;
                    if (onRoof)
                    {
                        _13272 = lerp(0.87999999523162841796875f, 0.939999997615814208984375f, smoothstep(0.5f, 1.0499999523162841796875f, amount));
                    }
                    else
                    {
                        _13272 = lerp(0.86000001430511474609375f, 0.920000016689300537109375f, organic);
                    }
                    float capAlpha = _13272;
                    float _13284;
                    if (ground)
                    {
                        _13284 = capLying * winterOutdoor;
                    }
                    else
                    {
                        _13284 = clamp(((capLying * settle) * winterOutdoor) * capAlpha, 0.0f, 1.0f);
                    }
                    float cover = _13284;
                    float3 param_242 = dull;
                    float3 param_243 = snow;
                    float param_244 = cover;
                    result = mixPerceptual(param_242, param_243, param_244);
                    if (poolWater > 0.00999999977648258209228515625f)
                    {
                        float coolT = smoothstep(0.0f, 0.4000000059604644775390625f, amount) * winterOutdoor;
                        float3 param_245 = workSrc;
                        float3 param_246 = float3(0.20000000298023223876953125f, 0.37999999523162841796875f, 0.540000021457672119140625f);
                        float3 coldPool = lerp(workSrc, recolor(param_245, param_246), (0.3400000035762786865234375f * coolT).xxx);
                        float2 param_247 = here.xy;
                        float param_248 = roofBase;
                        float rimBank = wallBank(param_247, param_248);
                        float iceFreeze = smoothstep(0.319999992847442626953125f - (0.100000001490116119384765625f * rimBank), 1.0499999523162841796875f - (0.1500000059604644775390625f * rimBank), amount * (1.0f - (0.25f * covered))) * winterOutdoor;
                        float3 iceCol = lerp(float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), (0.550000011920928955078125f + (0.25f * capCrust)).xxx) * clamp(0.7200000286102294921875f + (0.550000011920928955078125f * workLum), 0.680000007152557373046875f, 1.0499999523162841796875f);
                        float3 icedPool = lerp(coldPool, iceCol, (iceFreeze * (0.4199999868869781494140625f + (0.2599999904632568359375f * rimBank))).xxx);
                        result = lerp(result, icedPool, poolWater.xxx);
                    }
                    if ((!ground) && hasPartialSprite)
                    {
                        float3 B_win = spriteB;
                        bool _13393;
                        if (mapped)
                        {
                            _13393 = groundMap.Load(int3(int2(pixel), 0)).x < 1.0f;
                        }
                        else
                        {
                            _13393 = mapped;
                        }
                        bool _13414;
                        if (_13393)
                        {
                            float3 param_249 = spriteB;
                            bool _13399 = greenOf(param_249) > 0.0500000007450580596923828125f;
                            bool _13413;
                            if (!_13399)
                            {
                                bool _13404 = vacLot > 0.5f;
                                bool _13412;
                                if (_13404)
                                {
                                    _13412 = spriteB.z > spriteB.x;
                                }
                                else
                                {
                                    _13412 = _13404;
                                }
                                _13413 = _13412;
                            }
                            else
                            {
                                _13413 = _13399;
                            }
                            _13414 = _13413;
                        }
                        else
                        {
                            _13414 = _13393;
                        }
                        if (_13414)
                        {
                            float gKey_1 = ((0.62000000476837158203125f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
                            float2 param_250 = centre.xy;
                            float param_251 = gKey_1;
                            bool param_252 = true;
                            float2 param_253 = ambient_frame.xy;
                            float3 hereG_1 = lotPoint(param_250, param_251, param_252, param_253);
                            float3 param_254 = hereG_1;
                            float3 param_255 = hereG_1;
                            float gWinOut = min(1.0f - indoors(param_254), architecturalExposure(param_255));
                            if (gWinOut > 0.0f)
                            {
                                float2 param_256 = hereG_1.xy;
                                float2 gLot_1 = lotSource(param_256);
                                float2 param_257 = hereG_1.xy;
                                float gOver = smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, topAt(param_257) - hereG_1.z);
                                float3 param_258 = spriteB;
                                float2 param_259 = hereG_1.xy;
                                float param_260 = 1.0f;
                                float param_261 = vacLot;
                                float param_262;
                                float param_263;
                                float param_264;
                                float param_265;
                                float param_266;
                                evalGroundTerms(param_258, param_259, param_260, param_261, param_262, param_263, param_264, param_265, param_266);
                                float gVacSnow = param_262;
                                float gEarth = param_263;
                                float gWear = param_264;
                                float gGrn = param_265;
                                float gLum = param_266;
                                float2 param_267 = gLot_1;
                                float3 param_268 = spriteB;
                                float3 param_269 = hereG_1;
                                float2 param_270 = gLot_1;
                                float param_271 = gLum;
                                float param_272 = gGrn;
                                float param_273 = snowCrust(param_267);
                                float param_274 = gEarth;
                                float param_275 = gWear;
                                float param_276 = gVacSnow;
                                float param_277 = gOver;
                                bool param_278 = true;
                                float param_279 = amount;
                                float3 gDull = winterDullColor(param_268, param_269, param_270, param_271, param_272, param_273, param_274, param_275, param_276, param_277, param_278, param_279);
                                float3 param_280 = spriteB;
                                float3 param_281 = gDull;
                                float param_282 = gLum;
                                float3 param_283 = hereG_1;
                                float param_284 = hereG_1.z;
                                float param_285 = 0.0f;
                                float param_286 = amount;
                                float param_287 = deep;
                                float param_288 = gEarth;
                                float param_289 = gWear;
                                float param_290 = gVacSnow;
                                bool param_291 = true;
                                float param_292;
                                float param_293;
                                float param_294;
                                float3 _13549 = marchSnowDrift(param_280, param_281, param_282, param_283, param_284, param_285, param_286, param_287, param_288, param_289, param_290, param_291, param_292, param_293, param_294);
                                float gEdge = param_292;
                                float gHitT = param_293;
                                float gHitS = param_294;
                                float3 gMarch = _13549;
                                B_win = lerp(spriteB, gMarch, gWinOut.xxx);
                            }
                        }
                        result = (result * sp_1.w) + (B_win * (1.0f - sp_1.w));
                    }
                    if (!ground)
                    {
                        float _13574;
                        if (mapped)
                        {
                            float _13579;
                            if (baseAlt > (-10000.0f))
                            {
                                _13579 = groundFallback;
                            }
                            else
                            {
                                float2 param_295 = here.xy;
                                float param_296 = ambient_contact.w;
                                _13579 = terrainBaseClamped(param_295, param_296);
                            }
                            float2 param_297 = here.xy;
                            float param_298 = _13579;
                            _13574 = terrainBaseAt(param_297, param_298);
                        }
                        else
                        {
                            _13574 = here.z;
                        }
                        float baseG = _13574;
                        float _13603;
                        if (mapped)
                        {
                            _13603 = max(0.0f, here.z - baseG);
                        }
                        else
                        {
                            _13603 = 1.0f;
                        }
                        float h0Cap = _13603;
                        float roofW = ((onRoof && (workGreen < 0.3499999940395355224609375f)) && (cover > 0.0500000007450580596923828125f)) ? cover : 0.0f;
                        lift = float4(isFoliage, h0Cap, -max(cover, 0.001000000047497451305389404296875f), roofW);
                    }
                }
                else
                {
                    result = dull;
                }
                if ((mapped && (!sim)) && (poolWater < 0.5f))
                {
                    float2 param_299 = pixel;
                    float terrain = groundAt(param_299);
                    float _13648;
                    if (terrain > (-10000.0f))
                    {
                        float2 param_300 = centre.xy;
                        float param_301 = terrain / 27.7128124237060546875f;
                        bool param_302 = true;
                        float2 param_303 = ambient_frame.xy;
                        _13648 = lotPoint(param_300, param_301, param_302, param_303).z;
                    }
                    else
                    {
                        float2 param_304 = here.xy;
                        float param_305 = ambient_contact.w;
                        _13648 = terrainBaseClamped(param_304, param_305);
                    }
                    float fallbackBase = _13648;
                    float _13675;
                    if (ground)
                    {
                        _13675 = here.z;
                    }
                    else
                    {
                        float2 param_306 = here.xy;
                        float param_307 = fallbackBase;
                        _13675 = terrainBaseAt(param_306, param_307);
                    }
                    float base = _13675;
                    float _13690;
                    if (ground)
                    {
                        _13690 = 0.0f;
                    }
                    else
                    {
                        _13690 = max(0.0f, here.z - base);
                    }
                    float h0 = _13690;
                    float3 param_308 = workSrc;
                    float3 param_309 = result;
                    float param_310 = workLum;
                    float3 param_311 = here;
                    float param_312 = base;
                    float param_313 = h0;
                    float param_314 = amount;
                    float param_315 = deep;
                    float param_316 = earthMask;
                    float param_317 = terrainWear;
                    float param_318 = isVacSnowLot;
                    bool param_319 = ground;
                    float param_320;
                    float param_321;
                    float param_322;
                    float3 _13730 = marchSnowDrift(param_308, param_309, param_310, param_311, param_312, param_313, param_314, param_315, param_316, param_317, param_318, param_319, param_320, param_321, param_322);
                    float mEdge = param_320;
                    float mHitT = param_321;
                    float mHitS = param_322;
                    result = _13730;
                    if ((mEdge > 0.85000002384185791015625f) && (mHitS > 0.0320000015199184417724609375f))
                    {
                        lift = float4(mHitT, (base + mHitS) - here.z, 1.0f, 0.0f);
                    }
                    else
                    {
                        if (ground && hasPartialSprite)
                        {
                            lift = float4(1.0f, 0.0f, 0.0f, 0.0f);
                        }
                    }
                }
                else
                {
                    if ((((!mapped) && ground) && hasPartialSprite) && (!sim))
                    {
                        lift = float4(1.0f, 0.0f, 0.0f, 0.0f);
                    }
                }
            }
            else
            {
                bool _13772 = ambient_params.y < 0.00999999977648258209228515625f;
                bool _13778;
                if (_13772)
                {
                    _13778 = ambient_season.x < 1.5f;
                }
                else
                {
                    _13778 = _13772;
                }
                if (_13778 && (skyExposed > 0.001000000047497451305389404296875f))
                {
                    float overcastDim_1 = (1.0f - (0.23999999463558197021484375f * clamp(ambient_clouds.x, 0.0f, 1.0f))) - (0.119999997317790985107421875f * clamp(ambient_weather.x, 0.0f, 1.0f));
                    float wetDark_1 = 1.0f - ((0.2199999988079071044921875f * clamp(ambient_weather.y, 0.0f, 1.0f)) * (ground ? 1.0f : 0.550000011920928955078125f));
                    result *= lerp(1.0f, overcastDim_1 * wetDark_1, skyExposed);
                }
                float3 _13814 = abs(result - src);
                if (all(bool3(_13814.x < 9.9999997473787516355514526367188e-05f.xxx.x, _13814.y < 9.9999997473787516355514526367188e-05f.xxx.y, _13814.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
                {
                    return;
                }
            }
        }
    }
    bool _13822 = ambient_params.y < 0.00999999977648258209228515625f;
    bool _13828;
    if (_13822)
    {
        _13828 = ambient_season.x >= 0.5f;
    }
    else
    {
        _13828 = _13822;
    }
    if (_13828 && (skyExposed > 0.001000000047497451305389404296875f))
    {
        float overcastDim_2 = (1.0f - (0.2199999988079071044921875f * clamp(ambient_clouds.x, 0.0f, 1.0f))) - (0.100000001490116119384765625f * clamp(ambient_weather.x, 0.0f, 1.0f));
        float _13849;
        if (ambient_season.x < 1.5f)
        {
            _13849 = 1.0f - ((0.2199999988079071044921875f * clamp(ambient_weather.y, 0.0f, 1.0f)) * (ground ? 1.0f : 0.550000011920928955078125f));
        }
        else
        {
            _13849 = 1.0f;
        }
        float wetDark_2 = _13849;
        result *= lerp(1.0f, overcastDim_2 * wetDark_2, skyExposed);
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
