static const int2 _4943[4] = { int2(-1, 0), int2(1, 0), int2(0, -1), int2(0, 1) };
static const float3 _8634[14] = { float3(-3.5f, -2.5f, 1.0f), float3(3.5f, -2.5f, 1.0f), float3(-3.5f, 2.5f, 1.0f), float3(3.5f, 2.5f, 1.0f), float3(0.0f, -6.5f, 1.2999999523162841796875f), float3(0.0f, 6.5f, 1.2999999523162841796875f), float3(-6.5f, 0.0f, 1.0f), float3(6.5f, 0.0f, 1.0f), float3(-9.5f, -6.5f, 0.800000011920928955078125f), float3(9.5f, -6.5f, 0.800000011920928955078125f), float3(-9.5f, 6.5f, 0.800000011920928955078125f), float3(9.5f, 6.5f, 0.800000011920928955078125f), float3(0.0f, -12.5f, 0.75f), float3(0.0f, 12.5f, 0.75f) };
static const float3 _9169[9] = { float3(0.0f, -4.5f, 0.1599999964237213134765625f), float3(-3.5f, -5.5f, 0.119999997317790985107421875f), float3(3.5f, -5.5f, 0.119999997317790985107421875f), float3(0.0f, -9.5f, 0.180000007152557373046875f), float3(-5.5f, -10.5f, 0.10999999940395355224609375f), float3(5.5f, -10.5f, 0.10999999940395355224609375f), float3(0.0f, -15.5f, 0.100000001490116119384765625f), float3(-4.5f, -15.5f, 0.0500000007450580596923828125f), float3(4.5f, -15.5f, 0.0500000007450580596923828125f) };

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
    float _4880;
    if (stLift.z < (-0.00200000009499490261077880859375f))
    {
        _4880 = -stLift.z;
    }
    else
    {
        _4880 = 0.0f;
    }
    float capCover = _4880;
    float snowAct = (stLift.z > 0.5f) ? 1.0f : capCover;
    bool _4896 = ambient_view.z >= 1.35000002384185791015625f;
    bool _4903;
    if (_4896)
    {
        _4903 = stLift.z < (-0.0005000000237487256526947021484375f);
    }
    else
    {
        _4903 = _4896;
    }
    if (_4903)
    {
        float dC = depthMap.Load(int3(ip, 0)).x;
        float dTol = lerp(0.0013999999500811100006103515625f, 0.00449999980628490447998046875f, clamp(stLift.x, 0.0f, 1.0f));
        float3 accCol = pre * 0.699999988079071044921875f;
        float accCov = capCover * 0.699999988079071044921875f;
        float accW = 0.699999988079071044921875f;
        float _4967;
        for (int k = 0; k < 4; k++)
        {
            int2 np = clamp(ip + _4943[k], int2(0, 0), maxI);
            float4 nLift = trailMap.Load(int3(np, 0));
            if (nLift.z >= (-0.0005000000237487256526947021484375f))
            {
                continue;
            }
            if (nLift.z < (-0.00200000009499490261077880859375f))
            {
                _4967 = -nLift.z;
            }
            else
            {
                _4967 = 0.0f;
            }
            float nCov = _4967;
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
        bool _5058;
        if (hasSpriteLayer)
        {
            _5058 = stLift.z >= (-0.0005000000237487256526947021484375f);
        }
        else
        {
            _5058 = hasSpriteLayer;
        }
        if (_5058)
        {
            float4 sp = spriteMap.Load(int3(ip, 0));
            bool _5069 = sp.w > 0.0040000001899898052215576171875f;
            bool _5075;
            if (_5069)
            {
                _5075 = sp.w < 0.9900000095367431640625f;
            }
            else
            {
                _5075 = _5069;
            }
            if (_5075)
            {
                float3 F = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                float3 param = F;
                float fFol = foliageOf(param);
                float fBlos = smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, F.z) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, F.z / max(F.y, 0.0199999995529651641845703125f));
                float fPlant = clamp(max(fFol, fBlos), 0.0f, 1.0f);
                bool hasDrift = stLift.z > 0.5f;
                float _5113;
                if (hasDrift)
                {
                    _5113 = stLift.y;
                }
                else
                {
                    _5113 = -1.0f;
                }
                float driftH = _5113;
                float coreW = 0.0f;
                float snowCovSum = 0.0f;
                float3 snowColSum = 0.0f.xxx;
                float _5190;
                float _5196;
                float _5209;
                float _5217;
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
                        bool _5183;
                        if (hasDrift)
                        {
                            _5183 = nLift_1.y <= (driftH + 0.0599999986588954925537109375f);
                        }
                        else
                        {
                            _5183 = hasDrift;
                        }
                        if (_5183)
                        {
                            continue;
                        }
                        if (r2 == 1)
                        {
                            _5190 = 2.0f;
                        }
                        else
                        {
                            if (r2 == 2)
                            {
                                _5196 = 1.2000000476837158203125f;
                            }
                            else
                            {
                                _5196 = (r2 == 4) ? 0.550000011920928955078125f : 0.3499999940395355224609375f;
                            }
                            _5190 = _5196;
                        }
                        float w_1 = _5190;
                        if (nLift_1.x > 0.300000011920928955078125f)
                        {
                            _5209 = smoothstep(0.0500000007450580596923828125f, 0.25f, fPlant);
                        }
                        else
                        {
                            if (r2 <= 2)
                            {
                                _5217 = 1.0f - smoothstep(0.20000000298023223876953125f, 0.5f, fFol);
                            }
                            else
                            {
                                _5217 = 0.0f;
                            }
                            _5209 = _5217;
                        }
                        float matW_1 = _5209;
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
                bool _5270 = coreW > 9.9999997473787516355514526367188e-05f;
                bool _5284;
                if (_5270)
                {
                    bool _5276 = (snowCovSum > 9.9999997473787516355514526367188e-05f) || hasDrift;
                    bool _5283;
                    if (!_5276)
                    {
                        _5283 = stLift.x > 0.5f;
                    }
                    else
                    {
                        _5283 = _5276;
                    }
                    _5284 = _5283;
                }
                else
                {
                    _5284 = _5270;
                }
                if (_5284)
                {
                    float avgCov = clamp(snowCovSum / coreW, 0.0f, 1.0f);
                    bool _5300;
                    if (!hasDrift)
                    {
                        _5300 = stLift.x > 0.5f;
                    }
                    else
                    {
                        _5300 = hasDrift;
                    }
                    float3 _5301;
                    if (_5300)
                    {
                        _5301 = pre;
                    }
                    else
                    {
                        _5301 = clamp((orig - sp.xyz) / max(1.0f - sp.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                    }
                    float3 B_winter = _5301;
                    float3 param_1 = F;
                    float3 param_2 = float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f);
                    float3 param_3 = F;
                    float3 F_dull = lerp(F, recolor(param_1, param_2), (0.4000000059604644775390625f * greenOf(param_3)).xxx);
                    float3 _5333;
                    if (avgCov > 0.004999999888241291046142578125f)
                    {
                        _5333 = lerp(F_dull, snowColSum / max(snowCovSum, 9.9999997473787516355514526367188e-05f).xxx, avgCov.xxx);
                    }
                    else
                    {
                        _5333 = F_dull;
                    }
                    float3 F_snow = _5333;
                    pre = (F_snow * sp.w) + (B_winter * (1.0f - sp.w));
                    float _5359;
                    if (hasDrift)
                    {
                        _5359 = 1.0f;
                    }
                    else
                    {
                        _5359 = max(snowAct, sp.w * avgCov);
                    }
                    snowAct = _5359;
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

float3 mixPerceptual(float3 a, float3 b, float t)
{
    float3 m = lerp(sqrt(max(a, 0.0f.xxx)), sqrt(max(b, 0.0f.xxx)), clamp(t, 0.0f, 1.0f).xxx);
    return m * m;
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
    float _235;
    if (terrain)
    {
        _235 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _235 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _235;
    float _259;
    if (terrain)
    {
        _259 = key;
    }
    else
    {
        _259 = key - (0.800000011920928955078125f * h);
    }
    float s = _259;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

int maskAt(int2 at, int band)
{
    uint _424_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _424_dummy_parameter));
    int bandH = size.y / 10;
    bool _432 = at.x < 0;
    bool _439;
    if (!_432)
    {
        _439 = at.y < 0;
    }
    else
    {
        _439 = _432;
    }
    bool _448;
    if (!_439)
    {
        _448 = at.x >= size.x;
    }
    else
    {
        _448 = _439;
    }
    bool _456;
    if (!_448)
    {
        _456 = at.y >= bandH;
    }
    else
    {
        _456 = _448;
    }
    if (_456)
    {
        return 0;
    }
    return int((indoorMap.Load(int3(int2(at.x, at.y + (band * bandH)), 0)).x * 255.0f) + 0.5f);
}

float indoors(float3 lot)
{
    float2 cell = (lot.xy + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.20000000298023223876953125f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _521;
    float _534;
    float _568;
    float _583;
    float2 _648;
    float2 _656;
    for (int i = 0; i < 4; i++)
    {
        if ((i & 1) == 1)
        {
            _521 = f.x;
        }
        else
        {
            _521 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _534 = f.y;
        }
        else
        {
            _534 = 1.0f - f.y;
        }
        float weight = _521 * _534;
        int2 at = base + int2(i & 1, i >> 1);
        int2 param = at;
        int param_1 = 2;
        int gCode = maskAt(param, param_1);
        int2 param_2 = at;
        int param_3 = 3;
        int f2Code = maskAt(param_2, param_3);
        if (gCode != 0)
        {
            _568 = ambient_contact.w + (float(gCode - 1) / 8.0f);
        }
        else
        {
            if (f2Code != 0)
            {
                _583 = (ambient_contact.w + (float(f2Code - 1) / 8.0f)) - 2.9500000476837158203125f;
            }
            else
            {
                _583 = ambient_contact.w;
            }
            _568 = _583;
        }
        float ground = _568;
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
            _648 = float2(1.0f, -1.0f);
        }
        else
        {
            if (part == 2)
            {
                _656 = float2(-1.0f, 1.0f);
            }
            else
            {
                bool2 _666 = (part == 3).xx;
                _656 = float2(_666.x ? (-1.0f).xx.x : 1.0f.xx.x, _666.y ? (-1.0f).xx.y : 1.0f.xx.y);
            }
            _648 = _656;
        }
        float2 toward = _648;
        sum += (weight * smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((lot.xy + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward)));
    }
    return sum;
}

float architecturalExposure(float3 _point)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _805;
    if (orientation == 1)
    {
        _805 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _819;
        if (orientation == 2)
        {
            _819 = size - _point.xy;
        }
        else
        {
            float2 _829;
            if (orientation == 3)
            {
                _829 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _829 = _point.xy;
            }
            _819 = _829;
        }
        _805 = _819;
    }
    float2 source_1 = _805;
    bool _849 = any(bool2(source_1.x < 0.0f.xx.x, source_1.y < 0.0f.xx.y));
    bool _857;
    if (!_849)
    {
        _857 = any(bool2(source_1.x >= size.x, source_1.y >= size.y));
    }
    else
    {
        _857 = _849;
    }
    if (_857)
    {
        return 1.0f;
    }
    uint _865_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _865_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source_1 * texelsPerTile));
    uint _879_dummy_parameter;
    int2 _879 = int2(spvTextureSize(overheadMap, uint(0), _879_dummy_parameter));
    if (any(bool2(at.x >= _879.x, at.y >= _879.y)))
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
    float2 _752;
    if (orientation == 1)
    {
        _752 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _766;
        if (orientation == 2)
        {
            _766 = size - camera;
        }
        else
        {
            float2 _775;
            if (orientation == 3)
            {
                _775 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _775 = camera;
            }
            _766 = _775;
        }
        _752 = _766;
    }
    return _752;
}

float topAt(float2 at)
{
    uint _1062_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _1062_dummy_parameter)));
    return (0.5f - heightMap.Sample(_heightMap_sampler, ((at + ambient_frame.w.xx) * ambient_frame.z) / gridSize).x) * 64.0f;
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

float terrainBaseAt(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _953;
    if (orientation == 1)
    {
        _953 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _967;
        if (orientation == 2)
        {
            _967 = size - _point;
        }
        else
        {
            float2 _976;
            if (orientation == 3)
            {
                _976 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _976 = _point;
            }
            _967 = _976;
        }
        _953 = _967;
    }
    float2 source_1 = _953;
    bool _994 = any(bool2(source_1.x < 0.0f.xx.x, source_1.y < 0.0f.xx.y));
    bool _1002;
    if (!_994)
    {
        _1002 = any(bool2(source_1.x >= size.x, source_1.y >= size.y));
    }
    else
    {
        _1002 = _994;
    }
    if (_1002)
    {
        return fallback;
    }
    uint _1010_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _1010_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source_1 * texelsPerTile));
    uint _1024_dummy_parameter;
    int2 _1024 = int2(spvTextureSize(overheadMap, uint(0), _1024_dummy_parameter));
    if (any(bool2(at.x >= _1024.x, at.y >= _1024.y)))
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
    uint _1179_dummy_parameter;
    int2 size = int2(spvTextureSize(trailMap, uint(0), _1179_dummy_parameter));
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
    float _1234;
    float _1247;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(base + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        if ((i & 1) == 1)
        {
            _1234 = f.x;
        }
        else
        {
            _1234 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1247 = f.y;
        }
        else
        {
            _1247 = 1.0f - f.y;
        }
        float w = _1234 * _1247;
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
    float _1303;
    if (hueW > 9.9999997473787516355514526367188e-05f)
    {
        _1303 = hueSum / hueW;
    }
    else
    {
        _1303 = 0.0f;
    }
    float hue = _1303;
    float _1313;
    if (hueW > 9.9999997473787516355514526367188e-05f)
    {
        _1313 = lerp(0.0199999995529651641845703125f, 0.14000000059604644775390625f, clamp(((lumSum / hueW) - 0.37999999523162841796875f) / 0.23999999463558197021484375f, 0.0f, 1.0f));
    }
    else
    {
        _1313 = 0.0f;
    }
    speciesLumRef = _1313;
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
    float3 _2380;
    if (s < 0.2599999904632568359375f)
    {
        _2380 = lerp(g0, g1, (s / 0.2599999904632568359375f).xxx);
    }
    else
    {
        float3 _2393;
        if (s < 0.540000021457672119140625f)
        {
            _2393 = lerp(g1, g2, ((s - 0.2599999904632568359375f) / 0.2800000011920928955078125f).xxx);
        }
        else
        {
            float3 _2406;
            if (s < 0.7799999713897705078125f)
            {
                _2406 = lerp(g2, g3, ((s - 0.540000021457672119140625f) / 0.23999999463558197021484375f).xxx);
            }
            else
            {
                _2406 = lerp(g3, g4, ((s - 0.7799999713897705078125f) / 0.2199999988079071044921875f).xxx);
            }
            _2393 = _2406;
        }
        _2380 = _2393;
    }
    float3 goldColor = _2380;
    float3 o0 = float3(0.3449999988079071044921875f, 0.203999996185302734375f, 0.0390000008046627044677734375f);
    float3 o1 = float3(0.62000000476837158203125f, 0.3059999942779541015625f, 0.054999999701976776123046875f);
    float3 o2 = float3(0.862999975681304931640625f, 0.4709999859333038330078125f, 0.10999999940395355224609375f);
    float3 o3 = float3(0.972999989986419677734375f, 0.62000000476837158203125f, 0.17299999296665191650390625f);
    float3 o4 = float3(0.984000027179718017578125f, 0.7530000209808349609375f, 0.2269999980926513671875f);
    float3 _2449;
    if (s < 0.2599999904632568359375f)
    {
        _2449 = lerp(o0, o1, (s / 0.2599999904632568359375f).xxx);
    }
    else
    {
        float3 _2461;
        if (s < 0.540000021457672119140625f)
        {
            _2461 = lerp(o1, o2, ((s - 0.2599999904632568359375f) / 0.2800000011920928955078125f).xxx);
        }
        else
        {
            float3 _2474;
            if (s < 0.7799999713897705078125f)
            {
                _2474 = lerp(o2, o3, ((s - 0.540000021457672119140625f) / 0.23999999463558197021484375f).xxx);
            }
            else
            {
                _2474 = lerp(o3, o4, ((s - 0.7799999713897705078125f) / 0.2199999988079071044921875f).xxx);
            }
            _2461 = _2474;
        }
        _2449 = _2461;
    }
    float3 orangeColor = _2449;
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
    float _3174;
    if (mapped)
    {
        float2 param_1 = here.xy;
        float param_2 = here.z;
        _3174 = here.z - terrainBaseAt(param_1, param_2);
    }
    else
    {
        _3174 = here.z;
    }
    float relZ = _3174;
    if (hasLiveFloraMap)
    {
        float2 param_3 = here.xy;
        float param_4;
        float4 _3199 = floraAt(param_3, param_4);
        stampedLumRef = param_4;
        float4 flora = _3199;
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
    float _3252;
    if (hasLiveFloraMap && (stampedLumRef > 0.004999999888241291046142578125f))
    {
        _3252 = lerp(defaultLumRef, stampedLumRef, explicitDeciduous);
    }
    else
    {
        _3252 = defaultLumRef;
    }
    float lumRef = _3252;
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
    bool _1343 = any(bool2(sourcePoint.x < 1.0f.xx.x, sourcePoint.y < 1.0f.xx.y));
    bool _1355;
    if (!_1343)
    {
        float2 _1352 = ambient_drift.zw - 1.0f.xx;
        _1355 = any(bool2(sourcePoint.x > _1352.x, sourcePoint.y > _1352.y));
    }
    else
    {
        _1355 = _1343;
    }
    bool scenery = _1355;
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
    float _1514;
    float _1527;
    float2 _1548;
    float2 _1554;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 2;
        bool _1450 = maskAt(param_1, param_2) == 0;
        bool _1459;
        if (!_1450)
        {
            int2 param_3 = at;
            int param_4 = 0;
            _1459 = maskAt(param_3, param_4) >= 2;
        }
        else
        {
            _1459 = _1450;
        }
        if (_1459)
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
            _1514 = f.x;
        }
        else
        {
            _1514 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1527 = f.y;
        }
        else
        {
            _1527 = 1.0f - f.y;
        }
        float weight = _1514 * _1527;
        int part = f4 & 7;
        if (part != 0)
        {
            if (part == 1)
            {
                _1548 = float2(1.0f, -1.0f);
            }
            else
            {
                if (part == 2)
                {
                    _1554 = float2(-1.0f, 1.0f);
                }
                else
                {
                    bool2 _1560 = (part == 3).xx;
                    _1554 = float2(_1560.x ? (-1.0f).xx.x : 1.0f.xx.x, _1560.y ? (-1.0f).xx.y : 1.0f.xx.y);
                }
                _1548 = _1554;
            }
            float2 toward = _1548;
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
    bool _1594 = any(bool2(sourcePoint.x < 0.5f.xx.x, sourcePoint.y < 0.5f.xx.y));
    bool _1606;
    if (!_1594)
    {
        float2 _1603 = ambient_drift.zw - 0.5f.xx;
        _1606 = any(bool2(sourcePoint.x > _1603.x, sourcePoint.y > _1603.y));
    }
    else
    {
        _1606 = _1594;
    }
    if (_1606)
    {
        return 0.0f;
    }
    float2 cell = (q + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.4000000059604644775390625f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _1680;
    float _1693;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 2;
        bool _1655 = maskAt(param_1, param_2) == 0;
        bool _1664;
        if (!_1655)
        {
            int2 param_3 = at;
            int param_4 = 0;
            _1664 = maskAt(param_3, param_4) >= 2;
        }
        else
        {
            _1664 = _1655;
        }
        if (_1664)
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
            _1680 = f.x;
        }
        else
        {
            _1680 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1693 = f.y;
        }
        else
        {
            _1693 = 1.0f - f.y;
        }
        sum += (_1680 * _1693);
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
    uint _2123_dummy_parameter;
    int2 size = int2(spvTextureSize(heightMap, uint(0), _2123_dummy_parameter));
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
    bool _2239 = indoors(param_10) > 0.0500000007450580596923828125f;
    bool _2247;
    if (!_2239)
    {
        float3 param_11 = p;
        _2247 = architecturalExposure(param_11) < 0.949999988079071044921875f;
    }
    else
    {
        _2247 = _2239;
    }
    if (_2247)
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
            bool _2294 = k == 1;
            bool _2309;
            if (_2294)
            {
                float3 param_12 = np;
                bool _2300 = indoors(param_12) > 0.0500000007450580596923828125f;
                bool _2308;
                if (!_2300)
                {
                    float3 param_13 = np;
                    _2308 = architecturalExposure(param_13) < 0.949999988079071044921875f;
                }
                else
                {
                    _2308 = _2300;
                }
                _2309 = _2308;
            }
            else
            {
                _2309 = _2294;
            }
            if (_2309)
            {
                return 0.0f;
            }
            float2 param_14 = nxy;
            if ((topAt(param_14) - baseZ) <= 1.35000002384185791015625f)
            {
                connectedHigh = false;
                break;
            }
            bool _2338;
            if (connectedHigh)
            {
                float3 param_15 = np;
                bool _2329 = indoors(param_15) > 0.0500000007450580596923828125f;
                bool _2337;
                if (!_2329)
                {
                    float3 param_16 = np;
                    _2337 = architecturalExposure(param_16) < 0.949999988079071044921875f;
                }
                else
                {
                    _2337 = _2329;
                }
                _2338 = _2337;
            }
            else
            {
                _2338 = connectedHigh;
            }
            if (_2338)
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
    float3 _2526;
    if (s < 0.3400000035762786865234375f)
    {
        _2526 = lerp(gl0, gl1, (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _2539;
        if (s < 0.699999988079071044921875f)
        {
            _2539 = lerp(gl1, gl2, ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _2539 = lerp(gl2, gl3, ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _2526 = _2539;
    }
    float3 goldLeaf = _2526;
    float3 ol0 = float3(0.9409999847412109375f, 0.579999983310699462890625f, 0.1410000026226043701171875f);
    float3 ol1 = float3(0.910000026226043701171875f, 0.3449999988079071044921875f, 0.09399999678134918212890625f);
    float3 ol2 = float3(0.834999978542327880859375f, 0.607999980449676513671875f, 0.17299999296665191650390625f);
    float3 ol3 = float3(0.53299999237060546875f, 0.2199999988079071044921875f, 0.09399999678134918212890625f);
    float3 _2574;
    if (s < 0.3400000035762786865234375f)
    {
        _2574 = lerp(ol0, ol1, (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _2586;
        if (s < 0.699999988079071044921875f)
        {
            _2586 = lerp(ol1, ol2, ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _2586 = lerp(ol2, ol3, ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _2574 = _2586;
    }
    float3 orangeLeaf = _2574;
    return lerp(goldLeaf, orangeLeaf, clamp(speciesHue, 0.0f, 1.0f).xxx);
}

float3 applyAutumnGround(float3 col, float3 hereG, float2 gLot, float gPixelScale, float amount, float gOutdoor, float gSkyExposed, bool mapped, bool hasLiveFloraMap, bool leavesOnlyOnTurf)
{
    float gLum = dot(col, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float gGreen = smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, (col.y - max(col.x, col.z)) / max(col.y, 0.039999999105930328369140625f));
    float3 outCol = col;
    float _3448;
    if (mapped)
    {
        float2 param = hereG.xy;
        float _3454 = pavedAt(param);
        _3448 = _3454;
    }
    else
    {
        _3448 = 0.0f;
    }
    float autPaved = _3448;
    float _3459;
    if (mapped)
    {
        float2 param_1 = hereG.xy;
        _3459 = cementAt(param_1);
    }
    else
    {
        _3459 = 0.0f;
    }
    float autCement = _3459;
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
            float4 _3595 = floraAt(param_8, param_9);
            unusedLumRef = param_9;
            float4 flora = _3595;
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
            bool _3864 = l0.x > 0.004999999888241291046142578125f;
            bool _3871;
            if (!_3864)
            {
                _3871 = l0.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _3871 = _3864;
            }
            if (_3871)
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
            bool _3927 = l1.x > 0.004999999888241291046142578125f;
            bool _3934;
            if (!_3927)
            {
                _3934 = l1.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _3934 = _3927;
            }
            if (_3934)
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
            bool _3993 = l2.x > 0.004999999888241291046142578125f;
            bool _4000;
            if (!_3993)
            {
                _4000 = l2.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _4000 = _3993;
            }
            if (_4000)
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

void evalGroundTerms(float3 c, float2 xy, float isGroundF, float vacLot, inout float isVacSnowLot, out float earthMask, out float terrainWear, inout float greenOut, out float lumOut)
{
    lumOut = dot(c, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float3 param = c;
    greenOut = greenOf(param);
    float _4051;
    if (isGroundF > 0.5f)
    {
        float2 param_1 = xy;
        float _4056 = pavedAt(param_1);
        _4051 = _4056;
    }
    else
    {
        _4051 = 0.0f;
    }
    float pavedHere = _4051;
    float _4062;
    if (isGroundF > 0.5f)
    {
        float2 param_2 = xy;
        _4062 = cementAt(param_2);
    }
    else
    {
        _4062 = 0.0f;
    }
    float cementHere = _4062;
    float _4079;
    if (((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f)) && (cementHere < 0.3499999940395355224609375f))
    {
        _4079 = smoothstep(0.319999992847442626953125f, 0.519999980926513671875f, c.z) * smoothstep(0.00999999977648258209228515625f, 0.0500000007450580596923828125f, c.z - c.x);
    }
    else
    {
        _4079 = 0.0f;
    }
    float vacSnowBlue = _4079;
    isVacSnowLot = clamp(max(vacLot, vacSnowBlue), 0.0f, 1.0f);
    float warmOverGreen = smoothstep(-0.00999999977648258209228515625f, 0.039999999105930328369140625f, (c.x - c.y) / max(c.x, 0.0500000007450580596923828125f));
    float vacWarmth = (c.x - c.z) / max(c.x + c.z, 0.0500000007450580596923828125f);
    float naturalEarth = max(greenOut, smoothstep(0.4000000059604644775390625f, 0.540000021457672119140625f, vacWarmth));
    earthMask = (isGroundF * clamp(max(naturalEarth, isVacSnowLot), 0.0f, 1.0f)) * (1.0f - cementHere);
    float _4143;
    if ((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f))
    {
        _4143 = (((warmOverGreen * smoothstep(0.014999999664723873138427734375f, 0.23999999463558197021484375f, vacWarmth)) * smoothstep(0.02999999932944774627685546875f, 0.100000001490116119384765625f, c.x)) * isVacSnowLot) * (1.0f - cementHere);
    }
    else
    {
        _4143 = 0.0f;
    }
    float vacDirt = _4143;
    float _4168;
    if ((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f))
    {
        _4168 = (((smoothstep(0.7599999904632568359375f, 1.12000000476837158203125f, c.x / max(c.y, 0.014999999664723873138427734375f)) * smoothstep(0.4199999868869781494140625f, 0.579999983310699462890625f, vacWarmth)) * smoothstep(0.014999999664723873138427734375f, 0.04500000178813934326171875f, max(c.x, c.y))) * (1.0f - isVacSnowLot)) * (1.0f - cementHere);
    }
    else
    {
        _4168 = 0.0f;
    }
    float homeWear = _4168;
    terrainWear = max(vacDirt, homeWear);
}

float snowCrust(float2 lq)
{
    float2 param = (lq * 3.599999904632568359375f) + 3.2000000476837158203125f.xx;
    float2 param_1 = (lq * 8.80000019073486328125f) + 17.3999996185302734375f.xx;
    return (valueNoise(param) * 0.64999997615814208984375f) + (valueNoise(param_1) * 0.3499999940395355224609375f);
}

float3 winterDullColor(float3 c, float2 xy, float2 lotPt, float lumVal, float greenVal, float hereCrust, float earthMask, float terrainWear, float isVacSnowLot, float coveredVal, bool isGround)
{
    float3 param = c;
    float3 param_1 = float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f);
    float3 dullCol = lerp(c, recolor(param, param_1), (0.4000000059604644775390625f * greenVal).xxx);
    bool _4217;
    if (isGround)
    {
        float2 param_2 = xy;
        float _4215 = pavedAt(param_2);
        _4217 = _4215 < 0.3499999940395355224609375f;
    }
    else
    {
        _4217 = isGround;
    }
    if ((_4217 && (isVacSnowLot < 0.5f)) && (earthMask > 0.00999999977648258209228515625f))
    {
        float3 param_3 = c;
        float3 param_4 = float3(0.319999992847442626953125f, 0.36000001430511474609375f, 0.2199999988079071044921875f);
        float3 dormant = lerp(c, recolor(param_3, param_4), (0.550000011920928955078125f * greenVal).xxx);
        float2 param_5 = lotPt;
        float bareMix = clamp(max(terrainWear * 0.85000002384185791015625f, max(smoothstep(0.540000021457672119140625f, 0.86000001430511474609375f, dirtField(param_5)) * 0.7200000286102294921875f, coveredVal * 0.4799999892711639404296875f)), 0.0f, 0.87999999523162841796875f);
        float3 underDirt = lerp(float3(0.08200000226497650146484375f, 0.04500000178813934326171875f, 0.006000000052154064178466796875f), float3(0.33700001239776611328125f, 0.1780000030994415283203125f, 0.0529999993741512298583984375f), (0.3499999940395355224609375f + (0.550000011920928955078125f * hereCrust)).xxx) * clamp(lumVal / 0.14000000059604644775390625f, 0.449999988079071044921875f, 1.25f);
        dullCol = lerp(dormant, underDirt, (smoothstep(0.119999997317790985107421875f, 0.819999992847442626953125f, bareMix + ((0.5f - hereCrust) * 0.14000000059604644775390625f)) * earthMask).xxx);
    }
    return dullCol;
}

float groundAt(float2 pixel)
{
    float ground = groundMap.Load(int3(int2(pixel), 0)).x;
    float _406;
    if (ground < 1.0f)
    {
        _406 = (((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f;
    }
    else
    {
        _406 = -100000.0f;
    }
    return _406;
}

float nearIndoorWall(float2 xy, float z, float radius)
{
    float w = 0.0f;
    float _3069;
    float _3079;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            _3069 = 1.0f;
        }
        else
        {
            _3069 = (i == 1) ? (-1.0f) : 0.0f;
        }
        if (i == 2)
        {
            _3079 = 1.0f;
        }
        else
        {
            _3079 = (i == 3) ? (-1.0f) : 0.0f;
        }
        float2 card = float2(_3069, _3079) * radius;
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
    uint _1086_dummy_parameter;
    int2 size = int2(spvTextureSize(trailMap, uint(0), _1086_dummy_parameter));
    if (size.x < 4)
    {
        return 0.0f;
    }
    float2 param = at;
    float2 texel = ((lotSource(param) + 1.0f.xx) * 32.0f) - 0.5f.xx;
    int2 base = int2(floor(texel));
    float2 f = texel - float2(base);
    float sum = 0.0f;
    float _1141;
    float _1155;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(base + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        if ((i & 1) == 1)
        {
            _1141 = f.x;
        }
        else
        {
            _1141 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1155 = f.y;
        }
        else
        {
            _1155 = 1.0f - f.y;
        }
        sum += ((trailMap.Load(int3(c, 0)).x * _1141) * _1155);
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
    float _2026 = pavedAt(param_11);
    float paved = _2026;
    float paveKeep = 1.0f - (paved * lerp(0.959999978542327880859375f, 0.99500000476837158203125f, clamp(amount - 0.60000002384185791015625f, 0.0f, 1.0f)));
    float snow = ((((full * lying) * outside) * depthScale) * (1.0f + (0.2199999988079071044921875f * bank))) * paveKeep;
    if (snow <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    float2 param_12 = q;
    return snow - (min(0.02500000037252902984619140625f, snow * 0.5f) * pressedAt(param_12));
}

float3 marchSnowDrift(float3 srcCol, float3 baseCol, float lumVal, float3 pt, float baseZ, float h0, float amount, float deep, float earthMask, float terrainWear, float isVacSnowLot, bool isGround, out float outEdge, out float outHitT, out float outHitS)
{
    outEdge = 0.0f;
    outHitT = -1.0f;
    outHitS = 0.0f;
    float full = (0.039999999105930328369140625f * min(amount, 1.0f)) + (0.300000011920928955078125f * deep);
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
    int _4366 = steps - 1;
    for (int i = _4366; i >= 0; i--)
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
    float _4446;
    if (nextS >= 0.0f)
    {
        _4446 = smoothstep((0.7200000286102294921875f * dt) + 0.017999999225139617919921875f, (0.7200000286102294921875f * dt) + 0.05200000107288360595703125f, hitS - nextS);
    }
    else
    {
        _4446 = 0.0f;
    }
    float faceBlend = _4446;
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
    float2 param_29 = (lq * 0.449999988079071044921875f) + 9.0f.xx;
    float qSwell = valueNoise(param_29);
    float grainShade = ((1.0f - qCrust) * lerp(0.10999999940395355224609375f, 0.039999999105930328369140625f, deep)) + ((1.0f - smoothstep(0.20000000298023223876953125f, 0.800000011920928955078125f, qSwell)) * 0.119999997317790985107421875f);
    float3 qSnow = lerp(float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), clamp(grainShade, 0.0f, 0.3400000035762786865234375f).xxx);
    float under = isGround ? lumVal : 0.20999999344348907470703125f;
    qSnow *= (1.0f + ((0.3499999940395355224609375f * (1.0f - smoothstep(0.02999999932944774627685546875f, 0.119999997317790985107421875f, hitS))) * (under - 0.2800000011920928955078125f)));
    float _4584;
    if (isGround)
    {
        float2 param_30 = q;
        float _4589 = pavedAt(param_30);
        _4584 = _4589;
    }
    else
    {
        _4584 = 0.0f;
    }
    float qPaved = _4584;
    if (isGround && (qPaved < 0.3499999940395355224609375f))
    {
        float2 param_31 = q;
        float qEarth = earthMask * (1.0f - cementAt(param_31));
        if (qEarth > 0.00999999977648258209228515625f)
        {
            float snowCover = smoothstep(0.4199999868869781494140625f, 0.920000016689300537109375f, amount);
            float thinness = 1.0f - smoothstep(0.01200000010430812835693359375f, 0.100000001490116119384765625f, hitS);
            float2 param_32 = q;
            float param_33 = baseZ;
            float qBank = wallBank(param_32, param_33);
            float2 param_34 = lq;
            float patchDirt = smoothstep(0.560000002384185791015625f, 0.87999999523162841796875f, dirtField(param_34)) * (1.0f - (0.800000011920928955078125f * qBank));
            float2 param_35 = q;
            float canopyDirt = smoothstep(1.2000000476837158203125f, 2.5f, max(0.0f, topAt(param_35) - baseZ)) * lerp(0.449999988079071044921875f, 0.100000001490116119384765625f, snowCover);
            float homePatchScale = lerp(0.680000007152557373046875f, 0.0f, smoothstep(0.449999988079071044921875f, 0.87999999523162841796875f, amount));
            float vacPatchScale = 0.100000001490116119384765625f;
            float patchScale = lerp(homePatchScale, vacPatchScale, isVacSnowLot);
            float homeWearFade = lerp(0.7799999713897705078125f, 0.0500000007450580596923828125f, smoothstep(0.4000000059604644775390625f, 0.89999997615814208984375f, amount));
            float wearWeight = lerp(homeWearFade, 0.86000001430511474609375f, isVacSnowLot);
            float rawDirt = max(terrainWear * wearWeight, max(patchDirt * patchScale, canopyDirt));
            float thinScale = lerp(lerp(0.550000011920928955078125f + (0.449999988079071044921875f * thinness), 0.25f + (0.75f * thinness), snowCover), lerp(0.699999988079071044921875f + (0.300000011920928955078125f * thinness), 0.4000000059604644775390625f + (0.60000002384185791015625f * thinness), 1.0f - terrainWear), isVacSnowLot);
            float dirtMix = clamp(((rawDirt * thinScale) * (1.0f - qPaved)) * qEarth, 0.0f, 0.86000001430511474609375f);
            float dirtBlend = smoothstep(0.119999997317790985107421875f, 0.819999992847442626953125f, dirtMix + ((0.5f - qCrust) * 0.100000001490116119384765625f));
            float3 qDirt = lerp(float3(0.08200000226497650146484375f, 0.04500000178813934326171875f, 0.006000000052154064178466796875f), float3(0.33700001239776611328125f, 0.1780000030994415283203125f, 0.0529999993741512298583984375f), (0.3499999940395355224609375f + (0.550000011920928955078125f * qCrust)).xxx) * lerp(0.819999992847442626953125f, 1.14999997615814208984375f, smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, lumVal));
            qDirt = lerp(qDirt, srcCol, ((0.64999997615814208984375f * isVacSnowLot) * smoothstep(0.100000001490116119384765625f, 0.300000011920928955078125f, terrainWear)).xxx);
            float3 param_36 = qSnow;
            float3 param_37 = qDirt;
            float param_38 = dirtBlend;
            qSnow = mixPerceptual(param_36, param_37, param_38);
        }
    }
    float2 param_39 = q;
    float pressed = pressedAt(param_39);
    if (pressed > 0.0f)
    {
        float2 toSun = normalize(ambient_sunLot.xy + 9.9999997473787516355514526367188e-05f.xx) * 0.02999999932944774627685546875f;
        float2 param_40 = q + toSun;
        float shaded = clamp(pressed - pressedAt(param_40), 0.0f, 1.0f);
        float2 param_41 = q - toSun;
        float facing2 = clamp(pressed - pressedAt(param_41), 0.0f, 1.0f);
        qSnow = lerp(qSnow, float3(0.4140000045299530029296875f, 0.49500000476837158203125f, 0.6480000019073486328125f), (0.2800000011920928955078125f * pressed).xxx) * ((1.0f - (0.119999997317790985107421875f * shaded)) + (0.070000000298023223876953125f * facing2));
    }
    float daySun2 = max(0.0f, 1.0f - ambient_weather.w);
    float2 param_42 = lq * 24.0f;
    float2 param_43 = (lq * 41.0f) + 31.700000762939453125f.xx;
    float qGlint = smoothstep(0.680000007152557373046875f, 0.939999997615814208984375f, valueNoise(param_42) * valueNoise(param_43)) * daySun2;
    qSnow += (float3(0.0199999995529651641845703125f, 0.0240000002086162567138671875f, 0.034000001847743988037109375f) * qGlint);
    float3 seen = lerp(qSnow * lit, float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f) * (0.89999997615814208984375f + (0.07999999821186065673828125f * qCrust)), faceBlend.xxx);
    float edge = smoothstep(0.0040000001899898052215576171875f, 0.02199999988079071044921875f, hitS + (((qCrust - 0.5f) * 0.004999999888241291046142578125f) * (1.0f - qPaved)));
    outEdge = edge;
    outHitT = hitT;
    outHitS = hitS;
    return lerp(baseCol, seen, edge.xxx);
}

void frag_main()
{
    float2 pixel = floor(gl_FragCoord.xy) + 0.5f.xx;
    color = 0.0f.xxxx;
    lift = 0.0f.xxxx;
    bool _5401 = pixel.x >= ambient_extent.x;
    bool _5410;
    if (!_5401)
    {
        _5410 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _5410 = _5401;
    }
    if (_5410)
    {
        return;
    }
    bool _5416 = ambient_season.x >= 1.5f;
    bool _5423;
    if (_5416)
    {
        _5423 = ambient_seasonExtra2.w > 0.5f;
    }
    else
    {
        _5423 = _5416;
    }
    if (_5423)
    {
        int2 ip = int2(floor(gl_FragCoord.xy));
        int2 maxI = max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0));
        float4 stLift = trailMap.Load(int3(ip, 0));
        float4 _5447;
        if (stLift.z > 0.5f)
        {
            _5447 = stLift;
        }
        else
        {
            float _5455;
            if (stLift.z < (-0.00200000009499490261077880859375f))
            {
                _5455 = stLift.z;
            }
            else
            {
                _5455 = 0.0f;
            }
            _5447 = float4(0.0f, 0.0f, _5455, stLift.w);
        }
        lift = _5447;
        uint _5469_dummy_parameter;
        bool hasSpriteLayer = int2(spvTextureSize(spriteMap, uint(0), _5469_dummy_parameter)).x > 4;
        int2 param = ip;
        int2 param_1 = maxI;
        bool param_2 = hasSpriteLayer;
        float4 _5479 = resolveWinterPixel(param, param_1, param_2);
        float4 cM = _5479;
        float3 origM = overheadMap.Load(int3(ip, 0)).xyz;
        uint _5490_dummy_parameter;
        bool _5492 = int2(spvTextureSize(simMap, uint(0), _5490_dummy_parameter)).x > 1;
        bool _5501;
        if (_5492)
        {
            _5501 = simMap.Load(int3(ip, 0)).x > 0.5f;
        }
        else
        {
            _5501 = _5492;
        }
        bool isSim = _5501;
        if (isSim)
        {
            float3 _5509 = abs(cM.xyz - origM);
            if (all(bool3(_5509.x < 9.9999997473787516355514526367188e-05f.xxx.x, _5509.y < 9.9999997473787516355514526367188e-05f.xxx.y, _5509.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
            {
                return;
            }
            color = float4(cM.xyz, 1.0f);
            return;
        }
        int2 param_3 = ip + int2(0, -1);
        int2 param_4 = maxI;
        bool param_5 = hasSpriteLayer;
        float4 _5532 = resolveWinterPixel(param_3, param_4, param_5);
        float4 cN = _5532;
        int2 param_6 = ip + int2(0, 1);
        int2 param_7 = maxI;
        bool param_8 = hasSpriteLayer;
        float4 _5541 = resolveWinterPixel(param_6, param_7, param_8);
        float4 cS = _5541;
        int2 param_9 = ip + int2(-1, 0);
        int2 param_10 = maxI;
        bool param_11 = hasSpriteLayer;
        float4 _5550 = resolveWinterPixel(param_9, param_10, param_11);
        float4 cW = _5550;
        int2 param_12 = ip + int2(1, 0);
        int2 param_13 = maxI;
        bool param_14 = hasSpriteLayer;
        float4 _5559 = resolveWinterPixel(param_12, param_13, param_14);
        float4 cE = _5559;
        int2 param_15 = ip + int2(-1, -1);
        int2 param_16 = maxI;
        bool param_17 = hasSpriteLayer;
        float4 _5569 = resolveWinterPixel(param_15, param_16, param_17);
        float4 cNW = _5569;
        int2 param_18 = ip + int2(1, -1);
        int2 param_19 = maxI;
        bool param_20 = hasSpriteLayer;
        float4 _5579 = resolveWinterPixel(param_18, param_19, param_20);
        float4 cNE = _5579;
        int2 param_21 = ip + int2(-1, 1);
        int2 param_22 = maxI;
        bool param_23 = hasSpriteLayer;
        float4 _5589 = resolveWinterPixel(param_21, param_22, param_23);
        float4 cSW = _5589;
        int2 param_24 = ip + int2(1, 1);
        int2 param_25 = maxI;
        bool param_26 = hasSpriteLayer;
        float4 _5599 = resolveWinterPixel(param_24, param_25, param_26);
        float4 cSE = _5599;
        float sMax = max(cM.w, max(max(max(cN.w, cS.w), max(cE.w, cW.w)), max(max(cNW.w, cNE.w), max(cSW.w, cSE.w))));
        if (sMax < 0.02999999932944774627685546875f)
        {
            float3 _5635 = abs(cM.xyz - origM);
            if (all(bool3(_5635.x < 9.9999997473787516355514526367188e-05f.xxx.x, _5635.y < 9.9999997473787516355514526367188e-05f.xxx.y, _5635.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
            {
                return;
            }
            color = float4(cM.xyz, 1.0f);
            return;
        }
        float3 param_27 = cM.xyz;
        float lM = snowLuma(param_27);
        float3 param_28 = cN.xyz;
        float lN = snowLuma(param_28);
        float3 param_29 = cS.xyz;
        float lS = snowLuma(param_29);
        float3 param_30 = cW.xyz;
        float lW = snowLuma(param_30);
        float3 param_31 = cE.xyz;
        float lE = snowLuma(param_31);
        float3 param_32 = cNW.xyz;
        float lNW = snowLuma(param_32);
        float3 param_33 = cNE.xyz;
        float lNE = snowLuma(param_33);
        float3 param_34 = cSW.xyz;
        float lSW = snowLuma(param_34);
        float3 param_35 = cSE.xyz;
        float lSE = snowLuma(param_35);
        float lMin = min(lM, min(min(lN, lS), min(lE, lW)));
        float lMax = max(lM, max(max(lN, lS), max(lE, lW)));
        float lRange = lMax - lMin;
        if ((lRange < max(0.0350000001490116119384765625f, lMax * 0.064999997615814208984375f)) || (sMax < 0.039999999105930328369140625f))
        {
            color = float4(cM.xyz, 1.0f);
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
        float gradScaled = 0.25f * max(g1, g2);
        int2 _5822;
        if (isHorz)
        {
            _5822 = int2(0, is1Steeper ? (-1) : 1);
        }
        else
        {
            _5822 = int2(is1Steeper ? (-1) : 1, 0);
        }
        int2 stepPerp = _5822;
        bool2 _5835 = isHorz.xx;
        int2 stepTan = int2(_5835.x ? int2(1, 0).x : int2(0, 1).x, _5835.y ? int2(1, 0).y : int2(0, 1).y);
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
                int2 pN = ip - (stepTan * s.xx);
                int2 param_36 = pN;
                int2 param_37 = maxI;
                bool param_38 = hasSpriteLayer;
                float4 _5879 = resolveWinterPixel(param_36, param_37, param_38);
                float3 param_39 = _5879.xyz;
                int2 param_40 = pN + stepPerp;
                int2 param_41 = maxI;
                bool param_42 = hasSpriteLayer;
                float4 _5891 = resolveWinterPixel(param_40, param_41, param_42);
                float3 param_43 = _5891.xyz;
                float aN = 0.5f * (snowLuma(param_39) + snowLuma(param_43));
                lEndN = aN - lAvg;
                if (abs(lEndN) >= gradScaled)
                {
                    doneN = true;
                    distN = s;
                }
            }
            if (!doneP)
            {
                int2 pP = ip + (stepTan * s.xx);
                int2 param_44 = pP;
                int2 param_45 = maxI;
                bool param_46 = hasSpriteLayer;
                float4 _5925 = resolveWinterPixel(param_44, param_45, param_46);
                float3 param_47 = _5925.xyz;
                int2 param_48 = pP + stepPerp;
                int2 param_49 = maxI;
                bool param_50 = hasSpriteLayer;
                float4 _5937 = resolveWinterPixel(param_48, param_49, param_50);
                float3 param_51 = _5937.xyz;
                float aP = 0.5f * (snowLuma(param_47) + snowLuma(param_51));
                lEndP = aP - lAvg;
                if (abs(lEndP) >= gradScaled)
                {
                    doneN = doneN;
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
        float _5986;
        if (goodSpan)
        {
            _5986 = max(0.0f, 0.5f - (dMin / spanLen));
        }
        else
        {
            _5986 = 0.0f;
        }
        float edgeBlend = _5986;
        float avg9 = (((((2.0f * (((lN + lS) + lE) + lW)) + lNW) + lNE) + lSW) + lSE) / 12.0f;
        float subpix = clamp(abs(avg9 - lM) / max(lRange, 9.9999997473787516355514526367188e-05f), 0.0f, 1.0f);
        subpix = smoothstep(0.0f, 1.0f, subpix);
        float subpixAA = (0.64999997615814208984375f * subpix) * subpix;
        int2 perpPx = clamp(ip + stepPerp, int2(0, 0), maxI);
        uint _6040_dummy_parameter;
        bool _6042 = int2(spvTextureSize(simMap, uint(0), _6040_dummy_parameter)).x > 1;
        bool _6051;
        if (_6042)
        {
            _6051 = simMap.Load(int3(perpPx, 0)).x > 0.5f;
        }
        else
        {
            _6051 = _6042;
        }
        bool perpSim = _6051;
        float _6054;
        if (perpSim)
        {
            _6054 = 0.0f;
        }
        else
        {
            _6054 = max(edgeBlend, subpixAA) * smoothstep(0.039999999105930328369140625f, 0.180000007152557373046875f, sMax);
        }
        float finalBlend = _6054;
        float3 _6069;
        if (stepPerp.y < 0)
        {
            _6069 = cN.xyz;
        }
        else
        {
            float3 _6078;
            if (stepPerp.y > 0)
            {
                _6078 = cS.xyz;
            }
            else
            {
                float3 _6087;
                if (stepPerp.x < 0)
                {
                    _6087 = cW.xyz;
                }
                else
                {
                    _6087 = cE.xyz;
                }
                _6078 = _6087;
            }
            _6069 = _6078;
        }
        float3 perpCol = _6069;
        float3 param_52 = cM.xyz;
        float3 param_53 = perpCol;
        float param_54 = clamp(finalBlend, 0.0f, 0.7200000286102294921875f);
        color = float4(mixPerceptual(param_52, param_53, param_54), 1.0f);
        return;
    }
    float2 param_55 = pixel;
    float4 centre = positionAt(param_55);
    if (centre.w > 0.75f)
    {
        return;
    }
    float3 src = source.Load(int3(int2(pixel), 0)).xyz;
    bool ground = centre.w > 0.25f;
    bool mapped = ambient_sunLot.w > 0.0f;
    float _6139;
    if (ground)
    {
        _6139 = ((0.89999997615814208984375f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
    }
    else
    {
        _6139 = (0.89999997615814208984375f - depthMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f;
    }
    float key = _6139;
    float2 param_56 = centre.xy;
    float param_57 = key;
    bool param_58 = ground;
    float2 param_59 = ambient_frame.xy;
    float3 here = lotPoint(param_56, param_57, param_58, param_59);
    float _6178;
    if (mapped)
    {
        float3 param_60 = here;
        _6178 = 1.0f - indoors(param_60);
    }
    else
    {
        _6178 = 1.0f;
    }
    float outdoor = _6178;
    if (mapped && (!ground))
    {
        float3 param_61 = here - float3(0.0f, 0.0f, 0.25f);
        outdoor = min(outdoor, 1.0f - indoors(param_61));
    }
    float _6203;
    if (mapped)
    {
        float3 _6207;
        if (ground)
        {
            _6207 = here;
        }
        else
        {
            _6207 = here + float3(0.0f, 0.0f, 0.449999988079071044921875f);
        }
        float3 param_62 = _6207;
        _6203 = architecturalExposure(param_62);
    }
    else
    {
        _6203 = 1.0f;
    }
    float skyExposed = _6203;
    if (outdoor <= 0.0f)
    {
        return;
    }
    float2 param_63 = here.xy;
    float2 lot = lotSource(param_63);
    float lotPixelScale = max(length(fwidth(lot)), 0.00200000009499490261077880859375f);
    float amount = ambient_season.y;
    float springBloom = clamp(ambient_seasonExtra.y, 0.0f, 1.0f);
    float frost = clamp(ambient_seasonExtra2.y, 0.0f, 1.0f);
    float lum = dot(src, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float green = smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, (src.y - max(src.x, src.z)) / max(src.y, 0.039999999105930328369140625f));
    float _6266;
    if (mapped)
    {
        float2 param_64 = here.xy;
        _6266 = topAt(param_64) - here.z;
    }
    else
    {
        _6266 = 0.0f;
    }
    float over = _6266;
    float covered = smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, over);
    bool _6287;
    if (mapped)
    {
        _6287 = ambient_season.x > 1.5f;
    }
    else
    {
        _6287 = mapped;
    }
    if (_6287)
    {
        float _6301;
        float _6311;
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                _6301 = 1.0f;
            }
            else
            {
                _6301 = (i == 1) ? (-1.0f) : 0.0f;
            }
            if (i == 2)
            {
                _6311 = 1.0f;
            }
            else
            {
                _6311 = (i == 3) ? (-1.0f) : 0.0f;
            }
            float2 offset = float2(_6301, _6311) * 0.3499999940395355224609375f;
            float2 param_65 = here.xy + offset;
            covered += smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, topAt(param_65) - here.z);
        }
        covered /= 5.0f;
    }
    float3 result = src;
    uint _6342_dummy_parameter;
    bool _6344 = int2(spvTextureSize(simMap, uint(0), _6342_dummy_parameter)).x > 1;
    bool _6354;
    if (_6344)
    {
        _6354 = simMap.Load(int3(int2(pixel), 0)).x > 0.5f;
    }
    else
    {
        _6354 = _6344;
    }
    bool sim = _6354;
    bool _6364;
    if (mapped)
    {
        uint _6361_dummy_parameter;
        _6364 = int2(spvTextureSize(trailMap, uint(0), _6361_dummy_parameter)).x > 4;
    }
    else
    {
        _6364 = mapped;
    }
    bool _6374;
    if (_6364)
    {
        _6374 = abs(trailMap.Load(int3(int2(0, 0), 0)).w - 0.5f) < 0.180000007152557373046875f;
    }
    else
    {
        _6374 = _6364;
    }
    bool hasLiveFloraMap = _6374;
    if (ambient_season.x < 0.5f)
    {
        if ((((springBloom > 0.00999999977648258209228515625f) && (skyExposed > 0.001000000047497451305389404296875f)) && ground) && (green > 0.0500000007450580596923828125f))
        {
            float3 param_66 = float3(0.3400000035762786865234375f, 0.449999988079071044921875f, 0.180000007152557373046875f);
            float3 param_67 = src;
            float3 param_68 = srgbToLinear(param_66);
            result = lerp(src, recolor(param_67, param_68), (((green * skyExposed) * springBloom) * 0.180000007152557373046875f).xxx);
        }
        if ((((frost > 0.0199999995529651641845703125f) && (skyExposed > 0.001000000047497451305389404296875f)) && (!sim)) && (green > 0.0500000007450580596923828125f))
        {
            float2 param_69 = lot * 6.0f;
            float2 param_70 = (lot * 19.0f) + 7.099999904632568359375f.xx;
            float rime = smoothstep(0.3499999940395355224609375f, 0.819999992847442626953125f, (valueNoise(param_69) * 0.550000011920928955078125f) + (valueNoise(param_70) * 0.449999988079071044921875f));
            float3 param_71 = float3(0.7799999713897705078125f, 0.86000001430511474609375f, 0.949999988079071044921875f);
            float3 frostTint = srgbToLinear(param_71) * clamp(lum / 0.119999997317790985107421875f, 0.3499999940395355224609375f, 1.25f);
            result = lerp(result, frostTint, ((((frost * rime) * green) * skyExposed) * (ground ? 0.3400000035762786865234375f : 0.2199999988079071044921875f)).xxx);
        }
        float3 _6464 = abs(result - src);
        if (all(bool3(_6464.x < 9.9999997473787516355514526367188e-05f.xxx.x, _6464.y < 9.9999997473787516355514526367188e-05f.xxx.y, _6464.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
        {
            return;
        }
    }
    else
    {
        if (ambient_season.x < 1.5f)
        {
            uint _6479_dummy_parameter;
            bool hasSpriteLayer_1 = int2(spvTextureSize(spriteMap, uint(0), _6479_dummy_parameter)).x > 4;
            float4 _6484;
            if (hasSpriteLayer_1)
            {
                _6484 = spriteMap.Load(int3(int2(pixel), 0));
            }
            else
            {
                _6484 = 0.0f.xxxx;
            }
            float4 sp = _6484;
            if (!ground)
            {
                bool _6504;
                if (hasSpriteLayer_1)
                {
                    _6504 = sp.w > 0.00200000009499490261077880859375f;
                }
                else
                {
                    _6504 = hasSpriteLayer_1;
                }
                bool _6510;
                if (_6504)
                {
                    _6510 = sp.w < 0.9900000095367431640625f;
                }
                else
                {
                    _6510 = _6504;
                }
                if (_6510)
                {
                    float3 F = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                    float3 B = clamp((src - sp.xyz) / max(1.0f - sp.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                    float3 param_72 = F;
                    float3 param_73 = here;
                    float2 param_74 = lot;
                    float param_75 = amount;
                    float param_76 = outdoor;
                    bool param_77 = sim;
                    bool param_78 = mapped;
                    bool param_79 = hasLiveFloraMap;
                    float3 F_aut = applyAutumnFoliage(param_72, param_73, param_74, param_75, param_76, param_77, param_78, param_79);
                    float3 B_aut = B;
                    float gDepth = groundMap.Load(int3(int2(pixel), 0)).x;
                    if ((!sim) && (gDepth < 1.0f))
                    {
                        float gKey = ((0.89999997615814208984375f - gDepth) / 0.0030000000260770320892333984375f) + ambient_view.w;
                        float2 param_80 = centre.xy;
                        float param_81 = gKey;
                        bool param_82 = true;
                        float2 param_83 = ambient_frame.xy;
                        float3 hereG = lotPoint(param_80, param_81, param_82, param_83);
                        float _6588;
                        if (mapped)
                        {
                            float3 param_84 = hereG;
                            _6588 = 1.0f - indoors(param_84);
                        }
                        else
                        {
                            _6588 = 1.0f;
                        }
                        float gOutdoor = _6588;
                        if (gOutdoor > 0.0f)
                        {
                            float _6603;
                            if (mapped)
                            {
                                float3 param_85 = hereG;
                                _6603 = architecturalExposure(param_85);
                            }
                            else
                            {
                                _6603 = 1.0f;
                            }
                            float gSkyExposed = _6603;
                            float2 param_86 = hereG.xy;
                            float2 gLot = lotSource(param_86);
                            float gPixelScale = max(1.0f / (36.0f * max(ambient_view.z, 0.119999997317790985107421875f)), 0.00200000009499490261077880859375f);
                            float3 param_87 = B;
                            float3 param_88 = hereG;
                            float2 param_89 = gLot;
                            float param_90 = gPixelScale;
                            float param_91 = amount;
                            float param_92 = gOutdoor;
                            float param_93 = gSkyExposed;
                            bool param_94 = mapped;
                            bool param_95 = hasLiveFloraMap;
                            bool param_96 = true;
                            B_aut = applyAutumnGround(param_87, param_88, param_89, param_90, param_91, param_92, param_93, param_94, param_95, param_96);
                        }
                    }
                    result = (F_aut * sp.w) + (B_aut * (1.0f - sp.w));
                }
                else
                {
                    bool _6662;
                    if (hasSpriteLayer_1)
                    {
                        _6662 = sp.w >= 0.9900000095367431640625f;
                    }
                    else
                    {
                        _6662 = hasSpriteLayer_1;
                    }
                    float3 _6663;
                    if (_6662)
                    {
                        _6663 = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                    }
                    else
                    {
                        _6663 = src;
                    }
                    float3 F_1 = _6663;
                    float3 param_97 = F_1;
                    float3 param_98 = here;
                    float2 param_99 = lot;
                    float param_100 = amount;
                    float param_101 = outdoor;
                    bool param_102 = sim;
                    bool param_103 = mapped;
                    bool param_104 = hasLiveFloraMap;
                    result = applyAutumnFoliage(param_97, param_98, param_99, param_100, param_101, param_102, param_103, param_104);
                }
            }
            else
            {
                float3 param_105 = src;
                float3 param_106 = here;
                float2 param_107 = lot;
                float param_108 = lotPixelScale;
                float param_109 = amount;
                float param_110 = outdoor;
                float param_111 = skyExposed;
                bool param_112 = mapped;
                bool param_113 = hasLiveFloraMap;
                bool param_114 = false;
                result = applyAutumnGround(param_105, param_106, param_107, param_108, param_109, param_110, param_111, param_112, param_113, param_114);
            }
            bool _6721 = ((frost > 0.0199999995529651641845703125f) && (skyExposed > 0.001000000047497451305389404296875f)) && (!sim);
            bool _6728;
            if (_6721)
            {
                _6728 = ground || (green > 0.0500000007450580596923828125f);
            }
            else
            {
                _6728 = _6721;
            }
            if (_6728)
            {
                float2 param_115 = lot * 6.0f;
                float2 param_116 = (lot * 19.0f) + 7.099999904632568359375f.xx;
                float rime_1 = smoothstep(0.37999999523162841796875f, 0.839999973773956298828125f, (valueNoise(param_115) * 0.550000011920928955078125f) + (valueNoise(param_116) * 0.449999988079071044921875f));
                float _6748;
                if (ground)
                {
                    float2 param_117 = here.xy;
                    float _6754 = pavedAt(param_117);
                    _6748 = 1.0f - (0.85000002384185791015625f * _6754);
                }
                else
                {
                    _6748 = green;
                }
                float mask = _6748;
                float3 param_118 = float3(0.7799999713897705078125f, 0.86000001430511474609375f, 0.949999988079071044921875f);
                float3 frostTint_1 = srgbToLinear(param_118) * clamp(lum / 0.119999997317790985107421875f, 0.3499999940395355224609375f, 1.25f);
                result = lerp(result, frostTint_1, ((((frost * rime_1) * mask) * skyExposed) * (ground ? 0.300000011920928955078125f : 0.20000000298023223876953125f)).xxx);
            }
        }
        else
        {
            float winterOutdoor = min(outdoor, skyExposed);
            if (mapped)
            {
                float3 param_119 = here;
                winterOutdoor *= (1.0f - smoothstep(0.319999992847442626953125f, 0.4799999892711639404296875f, indoors(param_119)));
            }
            if (winterOutdoor > 0.0f)
            {
                uint _6803_dummy_parameter;
                bool hasSpriteLayer_2 = int2(spvTextureSize(spriteMap, uint(0), _6803_dummy_parameter)).x > 4;
                float4 _6808;
                if (hasSpriteLayer_2)
                {
                    _6808 = spriteMap.Load(int3(int2(pixel), 0));
                }
                else
                {
                    _6808 = 0.0f.xxxx;
                }
                float4 sp_1 = _6808;
                bool _6825;
                if (hasSpriteLayer_2)
                {
                    _6825 = sp_1.w > 0.0040000001899898052215576171875f;
                }
                else
                {
                    _6825 = hasSpriteLayer_2;
                }
                bool _6831;
                if (_6825)
                {
                    _6831 = sp_1.w < 0.9900000095367431640625f;
                }
                else
                {
                    _6831 = _6825;
                }
                bool hasPartialSprite = _6831;
                float3 _6834;
                if (hasPartialSprite)
                {
                    _6834 = clamp((src - sp_1.xyz) / max(1.0f - sp_1.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                }
                else
                {
                    _6834 = src;
                }
                float3 spriteB = _6834;
                float3 _6853;
                if (hasPartialSprite)
                {
                    _6853 = clamp(sp_1.xyz / sp_1.w.xxx, 0.0f.xxx, 1.0f.xxx);
                }
                else
                {
                    _6853 = src;
                }
                float3 spriteF = _6853;
                float3 _6870;
                if (ground && hasPartialSprite)
                {
                    _6870 = spriteB;
                }
                else
                {
                    bool3 _6881 = ((!ground) && hasPartialSprite).xxx;
                    _6870 = float3(_6881.x ? spriteF.x : src.x, _6881.y ? spriteF.y : src.y, _6881.z ? spriteF.z : src.z);
                }
                float3 workSrc = _6870;
                float vacLot = 1.0f - smoothstep(0.25f, 0.75f, ambient_seasonExtra.x);
                float3 param_120 = workSrc;
                float2 param_121 = here.xy;
                float param_122 = float(ground);
                float param_123 = vacLot;
                float param_124;
                float param_125;
                float param_126;
                float param_127;
                float param_128;
                evalGroundTerms(param_120, param_121, param_122, param_123, param_124, param_125, param_126, param_127, param_128);
                float isVacSnowLot = param_124;
                float earthMask = param_125;
                float terrainWear = param_126;
                float workGreen = param_127;
                float workLum = param_128;
                float2 param_129 = lot;
                float hereCrust = snowCrust(param_129);
                float3 _6921;
                if (sim)
                {
                    _6921 = workSrc;
                }
                else
                {
                    float3 param_130 = workSrc;
                    float2 param_131 = here.xy;
                    float2 param_132 = lot;
                    float param_133 = workLum;
                    float param_134 = workGreen;
                    float param_135 = hereCrust;
                    float param_136 = earthMask;
                    float param_137 = terrainWear;
                    float param_138 = isVacSnowLot;
                    float param_139 = covered;
                    bool param_140 = ground;
                    _6921 = winterDullColor(param_130, param_131, param_132, param_133, param_134, param_135, param_136, param_137, param_138, param_139, param_140);
                }
                float3 dull = _6921;
                float deep = clamp(amount - 1.0f, 0.0f, 1.0f);
                bool _6956 = !sim;
                bool _6964;
                if (_6956)
                {
                    _6964 = (!ground) || (!mapped);
                }
                else
                {
                    _6964 = _6956;
                }
                if (_6964)
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
                            float2 param_141 = lPx;
                            float4 ql = positionAt(param_141);
                            float2 param_142 = rPx;
                            float4 qr = positionAt(param_142);
                            float dxl = abs(p.x - ql.x);
                            float dxr = abs(qr.x - p.x);
                            bool _7063 = (ql.w < 0.25f) && (dxl > 0.25f);
                            bool _7078;
                            if (_7063)
                            {
                                _7078 = abs(ql.z - p.z) < ((1.60000002384185791015625f * dxl) + 4.5f);
                            }
                            else
                            {
                                _7078 = _7063;
                            }
                            bool lOk = _7078;
                            bool _7085 = (qr.w < 0.25f) && (dxr > 0.25f);
                            bool _7098;
                            if (_7085)
                            {
                                _7098 = abs(qr.z - p.z) < ((1.60000002384185791015625f * dxr) + 4.5f);
                            }
                            else
                            {
                                _7098 = _7085;
                            }
                            bool rOk = _7098;
                            if (workGreen < 0.1500000059604644775390625f)
                            {
                                bool _7115;
                                if (lOk)
                                {
                                    float3 param_143 = source.Load(int3(int2(lPx), 0)).xyz;
                                    _7115 = greenOf(param_143) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _7115 = lOk;
                                }
                                if (_7115)
                                {
                                    lOk = false;
                                }
                                bool _7130;
                                if (rOk)
                                {
                                    float3 param_144 = source.Load(int3(int2(rPx), 0)).xyz;
                                    _7130 = greenOf(param_144) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _7130 = rOk;
                                }
                                if (_7130)
                                {
                                    rOk = false;
                                }
                                if (r == 0)
                                {
                                    if (lOk)
                                    {
                                        float2 mPx = floor(clamp(pixel - float2(0.5f * st, 0.0f), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_145 = mPx;
                                        float4 qm = positionAt(param_145);
                                        bool _7157 = qm.w >= 0.25f;
                                        bool _7176;
                                        if (!_7157)
                                        {
                                            _7176 = abs(qm.z - p.z) >= ((1.60000002384185791015625f * abs(p.x - qm.x)) + 4.5f);
                                        }
                                        else
                                        {
                                            _7176 = _7157;
                                        }
                                        bool _7189;
                                        if (!_7176)
                                        {
                                            float3 param_146 = source.Load(int3(int2(mPx), 0)).xyz;
                                            _7189 = greenOf(param_146) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _7189 = _7176;
                                        }
                                        if (_7189)
                                        {
                                            lOk = false;
                                        }
                                    }
                                    if (rOk)
                                    {
                                        float2 mPx_1 = floor(clamp(pixel + float2(0.5f * st, 0.0f), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_147 = mPx_1;
                                        float4 qm_1 = positionAt(param_147);
                                        bool _7212 = qm_1.w >= 0.25f;
                                        bool _7231;
                                        if (!_7212)
                                        {
                                            _7231 = abs(qm_1.z - p.z) >= ((1.60000002384185791015625f * abs(qm_1.x - p.x)) + 4.5f);
                                        }
                                        else
                                        {
                                            _7231 = _7212;
                                        }
                                        bool _7244;
                                        if (!_7231)
                                        {
                                            float3 param_148 = source.Load(int3(int2(mPx_1), 0)).xyz;
                                            _7244 = greenOf(param_148) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _7244 = _7231;
                                        }
                                        if (_7244)
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
                            float2 param_149 = uPx;
                            float4 qu = positionAt(param_149);
                            float2 param_150 = dPx;
                            float4 qd = positionAt(param_150);
                            float dyu = abs(p.y - qu.y);
                            float dyd = abs(qd.y - p.y);
                            bool _7356 = (qu.w < 0.25f) && (dyu > 0.25f);
                            bool _7369;
                            if (_7356)
                            {
                                _7369 = abs(qu.z - p.z) < ((2.2000000476837158203125f * dyu) + 4.5f);
                            }
                            else
                            {
                                _7369 = _7356;
                            }
                            bool uOk = _7369;
                            bool _7376 = (qd.w < 0.25f) && (dyd > 0.25f);
                            bool _7389;
                            if (_7376)
                            {
                                _7389 = abs(qd.z - p.z) < ((2.2000000476837158203125f * dyd) + 4.5f);
                            }
                            else
                            {
                                _7389 = _7376;
                            }
                            bool dOk = _7389;
                            if (workGreen < 0.1500000059604644775390625f)
                            {
                                bool _7406;
                                if (uOk)
                                {
                                    float3 param_151 = source.Load(int3(int2(uPx), 0)).xyz;
                                    _7406 = greenOf(param_151) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _7406 = uOk;
                                }
                                if (_7406)
                                {
                                    uOk = false;
                                }
                                bool _7421;
                                if (dOk)
                                {
                                    float3 param_152 = source.Load(int3(int2(dPx), 0)).xyz;
                                    _7421 = greenOf(param_152) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _7421 = dOk;
                                }
                                if (_7421)
                                {
                                    dOk = false;
                                }
                                if (r == 0)
                                {
                                    if (uOk)
                                    {
                                        float2 mPx_2 = floor(clamp(pixel - float2(0.0f, 0.5f * st), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_153 = mPx_2;
                                        float4 qm_2 = positionAt(param_153);
                                        bool _7448 = qm_2.w >= 0.25f;
                                        bool _7467;
                                        if (!_7448)
                                        {
                                            _7467 = abs(qm_2.z - p.z) >= ((2.2000000476837158203125f * abs(p.y - qm_2.y)) + 4.5f);
                                        }
                                        else
                                        {
                                            _7467 = _7448;
                                        }
                                        bool _7480;
                                        if (!_7467)
                                        {
                                            float3 param_154 = source.Load(int3(int2(mPx_2), 0)).xyz;
                                            _7480 = greenOf(param_154) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _7480 = _7467;
                                        }
                                        if (_7480)
                                        {
                                            uOk = false;
                                        }
                                    }
                                    if (dOk)
                                    {
                                        float2 mPx_3 = floor(clamp(pixel + float2(0.0f, 0.5f * st), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_155 = mPx_3;
                                        float4 qm_3 = positionAt(param_155);
                                        bool _7503 = qm_3.w >= 0.25f;
                                        bool _7522;
                                        if (!_7503)
                                        {
                                            _7522 = abs(qm_3.z - p.z) >= ((2.2000000476837158203125f * abs(qm_3.y - p.y)) + 4.5f);
                                        }
                                        else
                                        {
                                            _7522 = _7503;
                                        }
                                        bool _7535;
                                        if (!_7522)
                                        {
                                            float3 param_156 = source.Load(int3(int2(mPx_3), 0)).xyz;
                                            _7535 = greenOf(param_156) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _7535 = _7522;
                                        }
                                        if (_7535)
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
                    float2 param_157 = lot * 0.89999997615814208984375f;
                    float2 param_158 = (lot * 2.7000000476837158203125f) + 5.0f.xx;
                    float2 param_159 = (lot * 7.5f) + 11.0f.xx;
                    float drift = ((valueNoise(param_157) * 0.4199999868869781494140625f) + (valueNoise(param_158) * 0.3300000131130218505859375f)) + (valueNoise(param_159) * 0.25f);
                    float depth = (amount * (1.0f - (0.300000011920928955078125f * covered))) * 1.25f;
                    float lying = smoothstep(drift - 0.14000000059604644775390625f, drift + 0.14000000059604644775390625f, depth + ((hereCrust - 0.5f) * 0.100000001490116119384765625f));
                    float _7692;
                    if (mapped)
                    {
                        float2 param_160 = pixel;
                        _7692 = groundAt(param_160);
                    }
                    else
                    {
                        _7692 = -100000.0f;
                    }
                    float baseAlt = _7692;
                    float _7704;
                    if (baseAlt > (-10000.0f))
                    {
                        float2 param_161 = centre.xy;
                        float param_162 = baseAlt / 27.7128124237060546875f;
                        bool param_163 = true;
                        float2 param_164 = ambient_frame.xy;
                        _7704 = lotPoint(param_161, param_162, param_163, param_164).z;
                    }
                    else
                    {
                        _7704 = 0.0f;
                    }
                    float groundFallback = _7704;
                    float _7724;
                    if (mapped)
                    {
                        float2 param_165 = here.xy;
                        float param_166 = groundFallback;
                        _7724 = terrainBaseAt(param_165, param_166);
                    }
                    else
                    {
                        _7724 = groundFallback;
                    }
                    float roofBase = _7724;
                    float _7738;
                    if (mapped)
                    {
                        _7738 = here.z - roofBase;
                    }
                    else
                    {
                        _7738 = 0.0f;
                    }
                    float relZ = _7738;
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
                            bool _7898 = length(pT - pixel) < (0.699999988079071044921875f * rP);
                            bool _7909;
                            if (!_7898)
                            {
                                _7909 = length(pL - pR) < (0.75f * wP);
                            }
                            else
                            {
                                _7909 = _7898;
                            }
                            if (_7909)
                            {
                                continue;
                            }
                            float2 param_167 = pML;
                            float4 qML = positionAt(param_167);
                            float2 param_168 = pMR;
                            float4 qMR = positionAt(param_168);
                            float2 param_169 = pT;
                            float4 qT = positionAt(param_169);
                            float2 param_170 = pL;
                            float4 qL = positionAt(param_170);
                            float2 param_171 = pR;
                            float4 qR = positionAt(param_171);
                            bool _7935 = qML.w < 0.25f;
                            bool _7946;
                            if (_7935)
                            {
                                _7946 = abs(qML.z - p0.z) < 14.0f;
                            }
                            else
                            {
                                _7946 = _7935;
                            }
                            bool _7952;
                            if (_7946)
                            {
                                _7952 = qMR.w < 0.25f;
                            }
                            else
                            {
                                _7952 = _7946;
                            }
                            bool _7962;
                            if (_7952)
                            {
                                _7962 = abs(qMR.z - p0.z) < 14.0f;
                            }
                            else
                            {
                                _7962 = _7952;
                            }
                            bool _7968;
                            if (_7962)
                            {
                                _7968 = qT.w < 0.25f;
                            }
                            else
                            {
                                _7968 = _7962;
                            }
                            bool _7979;
                            if (_7968)
                            {
                                _7979 = abs(qT.z - p0.z) < 22.0f;
                            }
                            else
                            {
                                _7979 = _7968;
                            }
                            bool _7985;
                            if (_7979)
                            {
                                _7985 = qL.w < 0.25f;
                            }
                            else
                            {
                                _7985 = _7979;
                            }
                            bool _7995;
                            if (_7985)
                            {
                                _7995 = abs(qL.z - p0.z) < 22.0f;
                            }
                            else
                            {
                                _7995 = _7985;
                            }
                            bool _8001;
                            if (_7995)
                            {
                                _8001 = qR.w < 0.25f;
                            }
                            else
                            {
                                _8001 = _7995;
                            }
                            bool _8011;
                            if (_8001)
                            {
                                _8011 = abs(qR.z - p0.z) < 22.0f;
                            }
                            else
                            {
                                _8011 = _8001;
                            }
                            bool _8021;
                            if (_8011)
                            {
                                _8021 = abs(qL.z - qR.z) < 7.5f;
                            }
                            else
                            {
                                _8021 = _8011;
                            }
                            if (_8021)
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
                                    bool _8060 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.89999997615814208984375f);
                                    bool _8066;
                                    if (_8060)
                                    {
                                        _8066 = nW.z > 0.3499999940395355224609375f;
                                    }
                                    else
                                    {
                                        _8066 = _8060;
                                    }
                                    bool _8073;
                                    if (_8066)
                                    {
                                        _8073 = abs(nW.x) > 0.1500000059604644775390625f;
                                    }
                                    else
                                    {
                                        _8073 = _8066;
                                    }
                                    if (_8073)
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
                                bool _8218 = any(bool2(pML_1.x < 0.5f.xx.x, pML_1.y < 0.5f.xx.y));
                                bool _8226;
                                if (!_8218)
                                {
                                    _8226 = any(bool2(pML_1.x > maxPx.x, pML_1.y > maxPx.y));
                                }
                                else
                                {
                                    _8226 = _8218;
                                }
                                bool _8233;
                                if (!_8226)
                                {
                                    _8233 = any(bool2(pMR_1.x < 0.5f.xx.x, pMR_1.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _8233 = _8226;
                                }
                                bool _8241;
                                if (!_8233)
                                {
                                    _8241 = any(bool2(pMR_1.x > maxPx.x, pMR_1.y > maxPx.y));
                                }
                                else
                                {
                                    _8241 = _8233;
                                }
                                bool _8248;
                                if (!_8241)
                                {
                                    _8248 = any(bool2(pT_1.x < 0.5f.xx.x, pT_1.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _8248 = _8241;
                                }
                                bool _8256;
                                if (!_8248)
                                {
                                    _8256 = any(bool2(pT_1.x > maxPx.x, pT_1.y > maxPx.y));
                                }
                                else
                                {
                                    _8256 = _8248;
                                }
                                bool _8263;
                                if (!_8256)
                                {
                                    _8263 = any(bool2(pL_1.x < 0.5f.xx.x, pL_1.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _8263 = _8256;
                                }
                                bool _8271;
                                if (!_8263)
                                {
                                    _8271 = any(bool2(pL_1.x > maxPx.x, pL_1.y > maxPx.y));
                                }
                                else
                                {
                                    _8271 = _8263;
                                }
                                bool _8278;
                                if (!_8271)
                                {
                                    _8278 = any(bool2(pR_1.x < 0.5f.xx.x, pR_1.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _8278 = _8271;
                                }
                                bool _8286;
                                if (!_8278)
                                {
                                    _8286 = any(bool2(pR_1.x > maxPx.x, pR_1.y > maxPx.y));
                                }
                                else
                                {
                                    _8286 = _8278;
                                }
                                if (_8286)
                                {
                                    continue;
                                }
                                float2 param_172 = pML_1;
                                float4 qML_1 = positionAt(param_172);
                                float2 param_173 = pMR_1;
                                float4 qMR_1 = positionAt(param_173);
                                float2 param_174 = pT_1;
                                float4 qT_1 = positionAt(param_174);
                                float2 param_175 = pL_1;
                                float4 qL_1 = positionAt(param_175);
                                float2 param_176 = pR_1;
                                float4 qR_1 = positionAt(param_176);
                                bool _8312 = qML_1.w < 0.25f;
                                bool _8323;
                                if (_8312)
                                {
                                    _8323 = abs(qML_1.z - p0.z) < 28.0f;
                                }
                                else
                                {
                                    _8323 = _8312;
                                }
                                bool _8329;
                                if (_8323)
                                {
                                    _8329 = qMR_1.w < 0.25f;
                                }
                                else
                                {
                                    _8329 = _8323;
                                }
                                bool _8339;
                                if (_8329)
                                {
                                    _8339 = abs(qMR_1.z - p0.z) < 28.0f;
                                }
                                else
                                {
                                    _8339 = _8329;
                                }
                                bool _8345;
                                if (_8339)
                                {
                                    _8345 = qT_1.w < 0.25f;
                                }
                                else
                                {
                                    _8345 = _8339;
                                }
                                bool _8356;
                                if (_8345)
                                {
                                    _8356 = abs(qT_1.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _8356 = _8345;
                                }
                                bool _8362;
                                if (_8356)
                                {
                                    _8362 = qL_1.w < 0.25f;
                                }
                                else
                                {
                                    _8362 = _8356;
                                }
                                bool _8372;
                                if (_8362)
                                {
                                    _8372 = abs(qL_1.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _8372 = _8362;
                                }
                                bool _8378;
                                if (_8372)
                                {
                                    _8378 = qR_1.w < 0.25f;
                                }
                                else
                                {
                                    _8378 = _8372;
                                }
                                bool _8388;
                                if (_8378)
                                {
                                    _8388 = abs(qR_1.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _8388 = _8378;
                                }
                                bool _8399;
                                if (_8388)
                                {
                                    _8399 = abs(qL_1.z - qR_1.z) < 20.0f;
                                }
                                else
                                {
                                    _8399 = _8388;
                                }
                                if (_8399)
                                {
                                    float3 cr_2 = cross(qL_1.xyz - p0, qR_1.xyz - p0);
                                    float crLen_2 = length(cr_2);
                                    if (crLen_2 > 1.0f)
                                    {
                                        float3 nW_1 = cr_2 / crLen_2.xxx;
                                        if (nW_1.z < 0.0f)
                                        {
                                            nW_1 = -nW_1;
                                        }
                                        float wFacing_1 = dot(nW_1, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                                        bool _8435 = wFacing_1 >= 0.920000016689300537109375f;
                                        bool _8441;
                                        if (_8435)
                                        {
                                            _8441 = nW_1.z > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _8441 = _8435;
                                        }
                                        if (_8441)
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
                    float settle = 1.0f;
                    float organic = 0.0f;
                    float pillowField = 0.0f;
                    float3 param_177 = workSrc;
                    float isFoliage = foliageOf(param_177);
                    float2 capLot = lot;
                    float capCrust = hereCrust;
                    float capLying = lying;
                    if (!ground)
                    {
                        if (onRoof)
                        {
                            settle = smoothstep(0.20000000298023223876953125f, 0.519999980926513671875f, max(facing, bestRoofFacing));
                        }
                        else
                        {
                            float3 p_1 = centre.xyz;
                            float sc = max(ambient_view.z, 0.25f);
                            float3 param_178 = workSrc;
                            float selfFol = foliageOf(param_178);
                            bool _8546 = (selfFol < 0.1500000059604644775390625f) && (workLum > 0.07999999821186065673828125f);
                            bool _8552;
                            if (_8546)
                            {
                                _8552 = workSrc.z > 0.07999999821186065673828125f;
                            }
                            else
                            {
                                _8552 = _8546;
                            }
                            bool _8561;
                            if (_8552)
                            {
                                _8561 = workSrc.z > (0.680000007152557373046875f * workSrc.y);
                            }
                            else
                            {
                                _8561 = _8552;
                            }
                            bool blossomCand = _8561;
                            bool _8567 = (selfFol < 0.1500000059604644775390625f) && (workLum < 0.02500000037252902984619140625f);
                            bool _8579;
                            if (_8567)
                            {
                                _8579 = workSrc.y > (1.2000000476837158203125f * max(workSrc.x, workSrc.z));
                            }
                            else
                            {
                                _8579 = _8567;
                            }
                            bool darkCreviceCand = _8579;
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
                            float _8781;
                            float4 tapData[14];
                            for (int i_3 = 0; i_3 < 14; i_3++)
                            {
                                float2 qPx = floor(clamp(pixel + (_8634[i_3].xy * sc), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                float2 param_179 = qPx;
                                float4 q = positionAt(param_179);
                                if (q.w < 0.25f)
                                {
                                    float2 dxy = q.xy - p_1.xy;
                                    float dist = length(dxy);
                                    float3 qCol = source.Load(int3(int2(qPx), 0)).xyz;
                                    float3 param_180 = qCol;
                                    float qFol = foliageOf(param_180);
                                    float qBlos = smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, qCol.z) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, qCol.z / max(qCol.y, 0.0199999995529651641845703125f));
                                    float qPlant = max(qFol, 0.60000002384185791015625f * qBlos);
                                    float fw = _8634[i_3].z * (1.0f - smoothstep(12.0f, 22.0f, abs(q.z - p_1.z)));
                                    rawFolNbr += (qFol * fw);
                                    rawFolW += fw;
                                    if (i_3 < 4)
                                    {
                                        float tw = _8634[i_3].z * (1.0f - smoothstep(10.0f, 18.0f, abs(q.z - p_1.z)));
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
                                                _8781 = 0.0f;
                                            }
                                            else
                                            {
                                                _8781 = 1.0f - smoothstep((1.7999999523162841796875f * dist) + 3.0f, (2.2000000476837158203125f * dist) + 6.0f, abs(q.z - p_1.z));
                                            }
                                            dw = _8781;
                                            if (dw > 9.9999997473787516355514526367188e-05f)
                                            {
                                                float2 mPx_4 = floor(clamp((pixel + qPx) * 0.5f, 0.0f.xx, maxIdx)) + 0.5f.xx;
                                                float2 param_181 = mPx_4;
                                                float4 qm_4 = positionAt(param_181);
                                                bool _8820 = qm_4.w >= 0.25f;
                                                bool _8839;
                                                if (!_8820)
                                                {
                                                    _8839 = abs(qm_4.z - (0.5f * (p_1.z + q.z))) >= ((1.7999999523162841796875f * (0.5f * dist)) + 5.0f);
                                                }
                                                else
                                                {
                                                    _8839 = _8820;
                                                }
                                                bool _8852;
                                                if (!_8839)
                                                {
                                                    float3 param_182 = source.Load(int3(int2(mPx_4), 0)).xyz;
                                                    _8852 = foliageOf(param_182) > 0.3499999940395355224609375f;
                                                }
                                                else
                                                {
                                                    _8852 = _8839;
                                                }
                                                if (_8852)
                                                {
                                                    dw = 0.0f;
                                                }
                                            }
                                        }
                                    }
                                    float wt = _8634[i_3].z * dw;
                                    if (wt > 9.9999997473787516355514526367188e-05f)
                                    {
                                        wSum += wt;
                                        folW += (wt * smoothstep(0.100000001490116119384765625f, 0.449999988079071044921875f, qPlant));
                                        mxSum += (wt * dxy.x);
                                        mySum += (wt * dxy.y);
                                        mzSum += (wt * q.z);
                                        greenNbr += (qFol * wt);
                                        greenW += wt;
                                        tapData[i_3] = float4(dxy.x, dxy.y, q.z, wt);
                                    }
                                    else
                                    {
                                        tapData[i_3] = 0.0f.xxxx;
                                    }
                                }
                                else
                                {
                                    tapData[i_3] = 0.0f.xxxx;
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
                            for (int i_4 = 0; i_4 < 14; i_4++)
                            {
                                float wt_1 = tapData[i_4].w;
                                if (wt_1 > 0.0f)
                                {
                                    float dx_1 = tapData[i_4].x - mx;
                                    float dy_1 = tapData[i_4].y - my;
                                    float dz = tapData[i_4].z - zSmooth;
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
                                for (int i_5 = 0; i_5 < 14; i_5++)
                                {
                                    float wt_2 = tapData[i_5].w;
                                    if (wt_2 > 0.0f)
                                    {
                                        float pred = (zSmooth + (gx_m * (tapData[i_5].x - mx))) + (gy_m * (tapData[i_5].y - my));
                                        errSum += (wt_2 * abs(tapData[i_5].z - pred));
                                        errW += wt_2;
                                    }
                                }
                                float _9134;
                                if (errW > 9.9999997473787516355514526367188e-05f)
                                {
                                    _9134 = errSum / errW;
                                }
                                else
                                {
                                    _9134 = 0.0f;
                                }
                                planeErr = _9134;
                            }
                            float topClear = 0.0f;
                            float overhang = 0.0f;
                            for (int i_6 = 0; i_6 < 9; i_6++)
                            {
                                float2 qPx_1 = floor(clamp(pixel + (_9169[i_6].xy * sc), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                float2 param_183 = qPx_1;
                                float4 q_1 = positionAt(param_183);
                                float distY = max(p_1.y - q_1.y, 1.0f);
                                float openW = max(step(0.25f, q_1.w), smoothstep(18.0f, 36.0f, zSmooth - q_1.z));
                                float slopeOpen = smoothstep(-0.2199999988079071044921875f, 0.519999980926513671875f, (zSmooth - q_1.z) / distY);
                                float overT = (1.0f - openW) * smoothstep(0.1599999964237213134765625f, 0.85000002384185791015625f, (q_1.z - zSmooth) / distY);
                                float wt_3 = _9169[i_6].z;
                                topClear += ((openW + ((1.0f - openW) * slopeOpen)) * wt_3);
                                overhang += (overT * wt_3);
                            }
                            float greenLocal = greenNbr / max(greenW, 9.9999997473787516355514526367188e-05f);
                            float _9255;
                            if (tightW > 9.9999997473787516355514526367188e-05f)
                            {
                                _9255 = tightGreen / tightW;
                            }
                            else
                            {
                                _9255 = 0.0f;
                            }
                            float tg = _9255;
                            float selfFoliage = smoothstep(0.07999999821186065673828125f, 0.2800000011920928955078125f, selfFol);
                            float blossom = ((smoothstep(0.07999999821186065673828125f, 0.180000007152557373046875f, workLum) * smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, workSrc.z)) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, workSrc.z / max(workSrc.y, 0.0199999995529651641845703125f))) * smoothstep(0.5f, 0.800000011920928955078125f, tg);
                            float _9286;
                            if (darkCreviceCand)
                            {
                                _9286 = smoothstep(0.579999983310699462890625f, 0.819999992847442626953125f, tg) * smoothstep(2.599999904632568359375f, 3.599999904632568359375f, tightW);
                            }
                            else
                            {
                                _9286 = 0.0f;
                            }
                            float darkCrevice = _9286;
                            isFoliage = max(selfFoliage, max(blossom, darkCrevice));
                            organic = (isFoliage * smoothstep(0.23999999463558197021484375f, 0.4799999892711639404296875f, greenLocal)) * smoothstep(0.949999988079071044921875f, 1.85000002384185791015625f, planeErr);
                            float _9313;
                            if (det > 64.0f)
                            {
                                _9313 = smoothstep(1.14999997615814208984375f, 0.4000000059604644775390625f, planeErr);
                            }
                            else
                            {
                                _9313 = 0.0f;
                            }
                            float planarFactor = _9313;
                            float solidSupport = smoothstep(2.599999904632568359375f, 5.19999980926513671875f, wSum) * smoothstep(48.0f, 128.0f, det);
                            float nearFolFrac = rawFolNbr / max(rawFolW, 9.9999997473787516355514526367188e-05f);
                            float notBushRim = 1.0f - (smoothstep(0.14000000059604644775390625f, 0.36000001430511474609375f, nearFolFrac) * (1.0f - isFoliage));
                            float solidFacing = max(facing, facMacro * planarFactor);
                            float settleSolid = ((smoothstep(0.60000002384185791015625f, 0.86000001430511474609375f, solidFacing) * solidSupport) * notBushRim) * (1.0f - smoothstep(0.2800000011920928955078125f, 0.550000011920928955078125f, overhang));
                            float2 param_184 = centre.xy;
                            float param_185 = zSmooth / 27.7128124237060546875f;
                            bool param_186 = false;
                            float2 param_187 = ambient_frame.xy;
                            float3 hereSm = lotPoint(param_184, param_185, param_186, param_187);
                            float2 param_188 = hereSm.xy;
                            float2 lotSm = lotSource(param_188);
                            float edgeSupport = smoothstep(1.60000002384185791015625f, 5.19999980926513671875f, folW);
                            float leafSoft = smoothstep(0.014999999664723873138427734375f, 0.12999999523162841796875f, workLum);
                            float2 param_189 = (lotSm * 2.400000095367431640625f) + float2(hereSm.z * 1.7000000476837158203125f, (-hereSm.z) * 1.2000000476837158203125f);
                            float2 param_190 = (lotSm * 5.19999980926513671875f) + float2((-hereSm.z) * 2.5f, hereSm.z * 2.099999904632568359375f);
                            float pillowNoise = (valueNoise(param_189) * 0.64999997615814208984375f) + (valueNoise(param_190) * 0.3499999940395355224609375f);
                            float dome = (facMacro * 0.4600000083446502685546875f) + (topClear * 0.540000021457672119140625f);
                            pillowField = ((dome * (1.0f - smoothstep(0.20000000298023223876953125f, 0.579999983310699462890625f, overhang))) + ((pillowNoise - 0.5f) * 0.119999997317790985107421875f)) + ((leafSoft - 0.449999988079071044921875f) * 0.0599999986588954925537109375f);
                            float snowGrow = clamp(amount, 0.0f, 1.35000002384185791015625f) / 1.35000002384185791015625f;
                            float settleFoliage = smoothstep(0.4199999868869781494140625f - (0.07999999821186065673828125f * snowGrow), 0.819999992847442626953125f - (0.070000000298023223876953125f * snowGrow), pillowField) * edgeSupport;
                            settle = lerp(settleSolid, settleFoliage, organic);
                            if (organic > 0.00999999977648258209228515625f)
                            {
                                capLot = lerp(lot, lotSm, organic.xx);
                                float2 param_191 = capLot;
                                capCrust = snowCrust(param_191);
                                float2 param_192 = capLot * 0.89999997615814208984375f;
                                float2 param_193 = (capLot * 2.7000000476837158203125f) + 5.0f.xx;
                                float2 param_194 = (capLot * 7.5f) + 11.0f.xx;
                                float smDrift = ((valueNoise(param_192) * 0.4199999868869781494140625f) + (valueNoise(param_193) * 0.3300000131130218505859375f)) + (valueNoise(param_194) * 0.25f);
                                capLying = lerp(lying, smoothstep(smDrift - 0.14000000059604644775390625f, smDrift + 0.14000000059604644775390625f, depth + ((capCrust - 0.5f) * 0.100000001490116119384765625f)), organic);
                            }
                        }
                    }
                    float wallBlock = 0.0f;
                    if (((!ground) && mapped) && (!onRoof))
                    {
                        float z0 = roofBase + 0.100000001490116119384765625f;
                        float z1 = (roofBase + 2.9500000476837158203125f) + 0.100000001490116119384765625f;
                        float wallR = (isFoliage > 0.25f) ? 0.10999999940395355224609375f : 0.4799999892711639404296875f;
                        float2 param_195 = here.xy;
                        float param_196 = z0;
                        float param_197 = wallR;
                        float2 param_198 = here.xy;
                        float param_199 = z1;
                        float param_200 = wallR;
                        float2 param_201 = here.xy;
                        float param_202 = here.z;
                        float param_203 = wallR;
                        wallBlock = max(nearIndoorWall(param_195, param_196, param_197), max(nearIndoorWall(param_198, param_199, param_200), nearIndoorWall(param_201, param_202, param_203)));
                        if ((isFoliage < 0.25f) && (relZ > 2.7999999523162841796875f))
                        {
                            float2 wallXY1 = here.xy - (1.25f * max(0.0f, relZ - 2.9500000476837158203125f)).xx;
                            float2 wallXY2 = here.xy - (1.25f * max(0.0f, relZ - 5.900000095367431640625f)).xx;
                            float3 param_204 = float3(wallXY1, z0);
                            float2 param_205 = wallXY1;
                            float param_206 = z0;
                            float param_207 = 0.519999980926513671875f;
                            wallBlock = max(wallBlock, max(indoors(param_204), nearIndoorWall(param_205, param_206, param_207)));
                            float3 param_208 = float3(wallXY2, z1);
                            float2 param_209 = wallXY2;
                            float param_210 = z1;
                            float param_211 = 0.519999980926513671875f;
                            wallBlock = max(wallBlock, max(indoors(param_208), nearIndoorWall(param_209, param_210, param_211)));
                        }
                    }
                    settle *= (1.0f - smoothstep(0.0199999995529651641845703125f, 0.25f, wallBlock));
                    float2 param_212 = (capLot * 0.449999988079071044921875f) + 9.0f.xx;
                    float swell = valueNoise(param_212);
                    float capShade = ((1.0f - capCrust) * lerp(0.100000001490116119384765625f, 0.0500000007450580596923828125f, deep)) + ((1.0f - smoothstep(0.20000000298023223876953125f, 0.800000011920928955078125f, swell)) * 0.119999997317790985107421875f);
                    float3 snow = lerp(float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), clamp(capShade, 0.0f, 0.3400000035762786865234375f).xxx);
                    snow *= (1.0f + ((0.319999992847442626953125f * (1.0f - (0.699999988079071044921875f * deep))) * (workLum - 0.23999999463558197021484375f)));
                    if (((!ground) && (!onRoof)) && (organic > 0.00999999977648258209228515625f))
                    {
                        float pillowTop = smoothstep(0.4199999868869781494140625f, 0.819999992847442626953125f, pillowField);
                        float orgShade = clamp(((1.0f - pillowTop) * 0.4799999892711639404296875f) + ((1.0f - capCrust) * 0.0599999986588954925537109375f), 0.0f, 0.519999980926513671875f);
                        float3 snowOrg = lerp(float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), orgShade.xxx) * (0.959999978542327880859375f + (0.07999999821186065673828125f * smoothstep(0.014999999664723873138427734375f, 0.12999999523162841796875f, workLum)));
                        snow = lerp(snow, snowOrg, organic.xxx);
                    }
                    float daySun = max(0.0f, 1.0f - ambient_weather.w);
                    float2 param_213 = capLot * 24.0f;
                    float2 param_214 = (capLot * 41.0f) + 31.700000762939453125f.xx;
                    float glint = smoothstep(0.680000007152557373046875f, 0.939999997615814208984375f, valueNoise(param_213) * valueNoise(param_214)) * daySun;
                    snow += ((float3(0.0199999995529651641845703125f, 0.0240000002086162567138671875f, 0.034000001847743988037109375f) * glint) * winterOutdoor);
                    float _9703;
                    if (onRoof)
                    {
                        _9703 = 0.920000016689300537109375f;
                    }
                    else
                    {
                        _9703 = lerp(0.86000001430511474609375f, 0.920000016689300537109375f, organic);
                    }
                    float capAlpha = _9703;
                    float _9712;
                    if (ground)
                    {
                        _9712 = capLying * winterOutdoor;
                    }
                    else
                    {
                        _9712 = clamp(((capLying * settle) * winterOutdoor) * capAlpha, 0.0f, 1.0f);
                    }
                    float cover = _9712;
                    result = lerp(dull, snow, cover.xxx);
                    if ((!ground) && hasPartialSprite)
                    {
                        float3 B_win = spriteB;
                        bool _9751;
                        if (mapped)
                        {
                            _9751 = groundMap.Load(int3(int2(pixel), 0)).x < 1.0f;
                        }
                        else
                        {
                            _9751 = mapped;
                        }
                        bool _9772;
                        if (_9751)
                        {
                            float3 param_215 = spriteB;
                            bool _9757 = greenOf(param_215) > 0.0500000007450580596923828125f;
                            bool _9771;
                            if (!_9757)
                            {
                                bool _9762 = vacLot > 0.5f;
                                bool _9770;
                                if (_9762)
                                {
                                    _9770 = spriteB.z > spriteB.x;
                                }
                                else
                                {
                                    _9770 = _9762;
                                }
                                _9771 = _9770;
                            }
                            else
                            {
                                _9771 = _9757;
                            }
                            _9772 = _9771;
                        }
                        else
                        {
                            _9772 = _9751;
                        }
                        if (_9772)
                        {
                            float gKey_1 = ((0.89999997615814208984375f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
                            float2 param_216 = centre.xy;
                            float param_217 = gKey_1;
                            bool param_218 = true;
                            float2 param_219 = ambient_frame.xy;
                            float3 hereG_1 = lotPoint(param_216, param_217, param_218, param_219);
                            float3 param_220 = hereG_1;
                            float3 param_221 = hereG_1;
                            float gWinOut = min(1.0f - indoors(param_220), architecturalExposure(param_221));
                            if (gWinOut > 0.0f)
                            {
                                float2 param_222 = hereG_1.xy;
                                float2 gLot_1 = lotSource(param_222);
                                float2 param_223 = hereG_1.xy;
                                float gOver = smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, topAt(param_223) - hereG_1.z);
                                float3 param_224 = spriteB;
                                float2 param_225 = hereG_1.xy;
                                float param_226 = 1.0f;
                                float param_227 = vacLot;
                                float param_228;
                                float param_229;
                                float param_230;
                                float param_231;
                                float param_232;
                                evalGroundTerms(param_224, param_225, param_226, param_227, param_228, param_229, param_230, param_231, param_232);
                                float gVacSnow = param_228;
                                float gEarth = param_229;
                                float gWear = param_230;
                                float gGrn = param_231;
                                float gLum = param_232;
                                float2 param_233 = gLot_1;
                                float3 param_234 = spriteB;
                                float2 param_235 = hereG_1.xy;
                                float2 param_236 = gLot_1;
                                float param_237 = gLum;
                                float param_238 = gGrn;
                                float param_239 = snowCrust(param_233);
                                float param_240 = gEarth;
                                float param_241 = gWear;
                                float param_242 = gVacSnow;
                                float param_243 = gOver;
                                bool param_244 = true;
                                float3 gDull = winterDullColor(param_234, param_235, param_236, param_237, param_238, param_239, param_240, param_241, param_242, param_243, param_244);
                                float3 param_245 = spriteB;
                                float3 param_246 = gDull;
                                float param_247 = gLum;
                                float3 param_248 = hereG_1;
                                float param_249 = hereG_1.z;
                                float param_250 = 0.0f;
                                float param_251 = amount;
                                float param_252 = deep;
                                float param_253 = gEarth;
                                float param_254 = gWear;
                                float param_255 = gVacSnow;
                                bool param_256 = true;
                                float param_257;
                                float param_258;
                                float param_259;
                                float3 _9906 = marchSnowDrift(param_245, param_246, param_247, param_248, param_249, param_250, param_251, param_252, param_253, param_254, param_255, param_256, param_257, param_258, param_259);
                                float gEdge = param_257;
                                float gHitT = param_258;
                                float gHitS = param_259;
                                float3 gMarch = _9906;
                                B_win = lerp(spriteB, gMarch, gWinOut.xxx);
                            }
                        }
                        result = (result * sp_1.w) + (B_win * (1.0f - sp_1.w));
                    }
                    if (!ground)
                    {
                        float _9934;
                        if (mapped && (baseAlt > (-10000.0f)))
                        {
                            _9934 = groundFallback;
                        }
                        else
                        {
                            _9934 = here.z;
                        }
                        float baseG = _9934;
                        float _9947;
                        if (mapped && (baseAlt > (-10000.0f)))
                        {
                            _9947 = max(0.0f, here.z - baseG);
                        }
                        else
                        {
                            _9947 = 1.0f;
                        }
                        float h0Cap = _9947;
                        float roofW = ((onRoof && (workGreen < 0.3499999940395355224609375f)) && (cover > 0.0500000007450580596923828125f)) ? cover : 0.0f;
                        lift = float4(isFoliage, h0Cap, -max(cover, 0.001000000047497451305389404296875f), roofW);
                    }
                }
                else
                {
                    result = dull;
                }
                if (mapped && (!sim))
                {
                    float2 param_260 = pixel;
                    float terrain = groundAt(param_260);
                    float _9988;
                    if (ground)
                    {
                        _9988 = here.z;
                    }
                    else
                    {
                        float _9996;
                        if (terrain > (-10000.0f))
                        {
                            float2 param_261 = centre.xy;
                            float param_262 = terrain / 27.7128124237060546875f;
                            bool param_263 = true;
                            float2 param_264 = ambient_frame.xy;
                            _9996 = lotPoint(param_261, param_262, param_263, param_264).z;
                        }
                        else
                        {
                            _9996 = here.z;
                        }
                        _9988 = _9996;
                    }
                    float base = _9988;
                    float _10019;
                    if (ground)
                    {
                        _10019 = 0.0f;
                    }
                    else
                    {
                        _10019 = max(0.0f, here.z - base);
                    }
                    float h0 = _10019;
                    float3 param_265 = workSrc;
                    float3 param_266 = result;
                    float param_267 = workLum;
                    float3 param_268 = here;
                    float param_269 = base;
                    float param_270 = h0;
                    float param_271 = amount;
                    float param_272 = deep;
                    float param_273 = earthMask;
                    float param_274 = terrainWear;
                    float param_275 = isVacSnowLot;
                    bool param_276 = ground;
                    float param_277;
                    float param_278;
                    float param_279;
                    float3 _10059 = marchSnowDrift(param_265, param_266, param_267, param_268, param_269, param_270, param_271, param_272, param_273, param_274, param_275, param_276, param_277, param_278, param_279);
                    float mEdge = param_277;
                    float mHitT = param_278;
                    float mHitS = param_279;
                    result = _10059;
                    if (mEdge > 0.5f)
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
                float3 _10098 = abs(result - src);
                if (all(bool3(_10098.x < 9.9999997473787516355514526367188e-05f.xxx.x, _10098.y < 9.9999997473787516355514526367188e-05f.xxx.y, _10098.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
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
