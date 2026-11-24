static const int2 _5049[4] = { int2(-1, 0), int2(1, 0), int2(0, -1), int2(0, 1) };
static const float3 _9296[14] = { float3(-3.5f, -2.5f, 1.0f), float3(3.5f, -2.5f, 1.0f), float3(-3.5f, 2.5f, 1.0f), float3(3.5f, 2.5f, 1.0f), float3(0.0f, -6.5f, 1.2999999523162841796875f), float3(0.0f, 6.5f, 1.2999999523162841796875f), float3(-6.5f, 0.0f, 1.0f), float3(6.5f, 0.0f, 1.0f), float3(-9.5f, -6.5f, 0.800000011920928955078125f), float3(9.5f, -6.5f, 0.800000011920928955078125f), float3(-9.5f, 6.5f, 0.800000011920928955078125f), float3(9.5f, 6.5f, 0.800000011920928955078125f), float3(0.0f, -12.5f, 0.75f), float3(0.0f, 12.5f, 0.75f) };
static const float3 _9832[9] = { float3(0.0f, -4.5f, 0.1599999964237213134765625f), float3(-3.5f, -5.5f, 0.119999997317790985107421875f), float3(3.5f, -5.5f, 0.119999997317790985107421875f), float3(0.0f, -9.5f, 0.180000007152557373046875f), float3(-5.5f, -10.5f, 0.10999999940395355224609375f), float3(5.5f, -10.5f, 0.10999999940395355224609375f), float3(0.0f, -15.5f, 0.100000001490116119384765625f), float3(-4.5f, -15.5f, 0.0500000007450580596923828125f), float3(4.5f, -15.5f, 0.0500000007450580596923828125f) };

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
    float _4986;
    if (stLift.z < (-0.00200000009499490261077880859375f))
    {
        _4986 = -stLift.z;
    }
    else
    {
        _4986 = 0.0f;
    }
    float capCover = _4986;
    float snowAct = (stLift.z > 0.5f) ? 1.0f : capCover;
    bool _5002 = ambient_view.z >= 1.35000002384185791015625f;
    bool _5009;
    if (_5002)
    {
        _5009 = stLift.z < (-0.0005000000237487256526947021484375f);
    }
    else
    {
        _5009 = _5002;
    }
    if (_5009)
    {
        float dC = depthMap.Load(int3(ip, 0)).x;
        float dTol = lerp(0.0013999999500811100006103515625f, 0.00449999980628490447998046875f, clamp(stLift.x, 0.0f, 1.0f));
        float3 accCol = pre * 0.699999988079071044921875f;
        float accCov = capCover * 0.699999988079071044921875f;
        float accW = 0.699999988079071044921875f;
        float _5073;
        for (int k = 0; k < 4; k++)
        {
            int2 np = clamp(ip + _5049[k], int2(0, 0), maxI);
            float4 nLift = trailMap.Load(int3(np, 0));
            if (nLift.z >= (-0.0005000000237487256526947021484375f))
            {
                continue;
            }
            if (nLift.z < (-0.00200000009499490261077880859375f))
            {
                _5073 = -nLift.z;
            }
            else
            {
                _5073 = 0.0f;
            }
            float nCov = _5073;
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
        bool _5164;
        if (hasSpriteLayer)
        {
            _5164 = stLift.z >= (-0.0005000000237487256526947021484375f);
        }
        else
        {
            _5164 = hasSpriteLayer;
        }
        if (_5164)
        {
            float4 sp = spriteMap.Load(int3(ip, 0));
            bool _5176 = sp.w > 0.0040000001899898052215576171875f;
            bool _5182;
            if (_5176)
            {
                _5182 = sp.w < 0.9900000095367431640625f;
            }
            else
            {
                _5182 = _5176;
            }
            if (_5182)
            {
                float3 F = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                float3 param = F;
                float fFol = foliageOf(param);
                float fBlos = smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, F.z) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, F.z / max(F.y, 0.0199999995529651641845703125f));
                float fPlant = clamp(max(fFol, fBlos), 0.0f, 1.0f);
                bool hasDrift = stLift.z > 0.5f;
                float _5220;
                if (hasDrift)
                {
                    _5220 = stLift.y;
                }
                else
                {
                    _5220 = -1.0f;
                }
                float driftH = _5220;
                float coreW = 0.0f;
                float snowCovSum = 0.0f;
                float3 snowColSum = 0.0f.xxx;
                float _5297;
                float _5303;
                float _5316;
                float _5324;
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
                        bool _5290;
                        if (hasDrift)
                        {
                            _5290 = nLift_1.y <= (driftH + 0.0599999986588954925537109375f);
                        }
                        else
                        {
                            _5290 = hasDrift;
                        }
                        if (_5290)
                        {
                            continue;
                        }
                        if (r2 == 1)
                        {
                            _5297 = 2.0f;
                        }
                        else
                        {
                            if (r2 == 2)
                            {
                                _5303 = 1.2000000476837158203125f;
                            }
                            else
                            {
                                _5303 = (r2 == 4) ? 0.550000011920928955078125f : 0.3499999940395355224609375f;
                            }
                            _5297 = _5303;
                        }
                        float w_1 = _5297;
                        if (nLift_1.x > 0.300000011920928955078125f)
                        {
                            _5316 = smoothstep(0.0500000007450580596923828125f, 0.25f, fPlant);
                        }
                        else
                        {
                            if (r2 <= 2)
                            {
                                _5324 = 1.0f - smoothstep(0.20000000298023223876953125f, 0.5f, fFol);
                            }
                            else
                            {
                                _5324 = 0.0f;
                            }
                            _5316 = _5324;
                        }
                        float matW_1 = _5316;
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
                bool _5377 = coreW > 9.9999997473787516355514526367188e-05f;
                bool _5391;
                if (_5377)
                {
                    bool _5383 = (snowCovSum > 9.9999997473787516355514526367188e-05f) || hasDrift;
                    bool _5390;
                    if (!_5383)
                    {
                        _5390 = stLift.x > 0.5f;
                    }
                    else
                    {
                        _5390 = _5383;
                    }
                    _5391 = _5390;
                }
                else
                {
                    _5391 = _5377;
                }
                if (_5391)
                {
                    float avgCov = clamp(snowCovSum / coreW, 0.0f, 1.0f);
                    bool _5407;
                    if (!hasDrift)
                    {
                        _5407 = stLift.x > 0.5f;
                    }
                    else
                    {
                        _5407 = hasDrift;
                    }
                    float3 _5408;
                    if (_5407)
                    {
                        _5408 = pre;
                    }
                    else
                    {
                        _5408 = clamp((orig - sp.xyz) / max(1.0f - sp.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                    }
                    float3 B_winter = _5408;
                    float3 param_1 = F;
                    float3 param_2 = float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f);
                    float3 param_3 = F;
                    float3 F_dull = lerp(F, recolor(param_1, param_2), ((0.37999999523162841796875f * greenOf(param_3)) * smoothstep(0.0f, 0.3499999940395355224609375f, ambient_season.y)).xxx);
                    float3 _5444;
                    if (avgCov > 0.004999999888241291046142578125f)
                    {
                        _5444 = lerp(F_dull, snowColSum / max(snowCovSum, 9.9999997473787516355514526367188e-05f).xxx, avgCov.xxx);
                    }
                    else
                    {
                        _5444 = F_dull;
                    }
                    float3 F_snow = _5444;
                    pre = (F_snow * sp.w) + (B_winter * (1.0f - sp.w));
                    float _5470;
                    if (hasDrift)
                    {
                        _5470 = 1.0f;
                    }
                    else
                    {
                        _5470 = max(snowAct, sp.w * avgCov);
                    }
                    snowAct = _5470;
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
    float _236;
    if (terrain)
    {
        _236 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _236 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _236;
    float _260;
    if (terrain)
    {
        _260 = key;
    }
    else
    {
        _260 = key - (0.800000011920928955078125f * h);
    }
    float s = _260;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

int maskAt(int2 at, int band)
{
    uint _425_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _425_dummy_parameter));
    int bandH = size.y / 10;
    bool _433 = at.x < 0;
    bool _440;
    if (!_433)
    {
        _440 = at.y < 0;
    }
    else
    {
        _440 = _433;
    }
    bool _449;
    if (!_440)
    {
        _449 = at.x >= size.x;
    }
    else
    {
        _449 = _440;
    }
    bool _457;
    if (!_449)
    {
        _457 = at.y >= bandH;
    }
    else
    {
        _457 = _449;
    }
    if (_457)
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
    float _522;
    float _535;
    float _569;
    float _584;
    float2 _649;
    float2 _657;
    for (int i = 0; i < 4; i++)
    {
        if ((i & 1) == 1)
        {
            _522 = f.x;
        }
        else
        {
            _522 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _535 = f.y;
        }
        else
        {
            _535 = 1.0f - f.y;
        }
        float weight = _522 * _535;
        int2 at = base + int2(i & 1, i >> 1);
        int2 param = at;
        int param_1 = 2;
        int gCode = maskAt(param, param_1);
        int2 param_2 = at;
        int param_3 = 3;
        int f2Code = maskAt(param_2, param_3);
        if (gCode != 0)
        {
            _569 = ambient_contact.w + (float(gCode - 1) / 8.0f);
        }
        else
        {
            if (f2Code != 0)
            {
                _584 = (ambient_contact.w + (float(f2Code - 1) / 8.0f)) - 2.9500000476837158203125f;
            }
            else
            {
                _584 = ambient_contact.w;
            }
            _569 = _584;
        }
        float ground = _569;
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
            _649 = float2(1.0f, -1.0f);
        }
        else
        {
            if (part == 2)
            {
                _657 = float2(-1.0f, 1.0f);
            }
            else
            {
                bool2 _667 = (part == 3).xx;
                _657 = float2(_667.x ? (-1.0f).xx.x : 1.0f.xx.x, _667.y ? (-1.0f).xx.y : 1.0f.xx.y);
            }
            _649 = _657;
        }
        float2 toward = _649;
        sum += (weight * smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((lot.xy + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward)));
    }
    return sum;
}

float architecturalExposure(float3 _point)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _806;
    if (orientation == 1)
    {
        _806 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _820;
        if (orientation == 2)
        {
            _820 = size - _point.xy;
        }
        else
        {
            float2 _830;
            if (orientation == 3)
            {
                _830 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _830 = _point.xy;
            }
            _820 = _830;
        }
        _806 = _820;
    }
    float2 source_1 = _806;
    bool _850 = any(bool2(source_1.x < 0.0f.xx.x, source_1.y < 0.0f.xx.y));
    bool _858;
    if (!_850)
    {
        _858 = any(bool2(source_1.x >= size.x, source_1.y >= size.y));
    }
    else
    {
        _858 = _850;
    }
    if (_858)
    {
        return 1.0f;
    }
    uint _866_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _866_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source_1 * texelsPerTile));
    uint _880_dummy_parameter;
    int2 _880 = int2(spvTextureSize(overheadMap, uint(0), _880_dummy_parameter));
    if (any(bool2(at.x >= _880.x, at.y >= _880.y)))
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
    float2 _753;
    if (orientation == 1)
    {
        _753 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _767;
        if (orientation == 2)
        {
            _767 = size - camera;
        }
        else
        {
            float2 _776;
            if (orientation == 3)
            {
                _776 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _776 = camera;
            }
            _767 = _776;
        }
        _753 = _767;
    }
    return _753;
}

float topAt(float2 at)
{
    uint _1063_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _1063_dummy_parameter)));
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
    float2 _954;
    if (orientation == 1)
    {
        _954 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _968;
        if (orientation == 2)
        {
            _968 = size - _point;
        }
        else
        {
            float2 _977;
            if (orientation == 3)
            {
                _977 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _977 = _point;
            }
            _968 = _977;
        }
        _954 = _968;
    }
    float2 source_1 = _954;
    bool _995 = any(bool2(source_1.x < 0.0f.xx.x, source_1.y < 0.0f.xx.y));
    bool _1003;
    if (!_995)
    {
        _1003 = any(bool2(source_1.x >= size.x, source_1.y >= size.y));
    }
    else
    {
        _1003 = _995;
    }
    if (_1003)
    {
        return fallback;
    }
    uint _1011_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _1011_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source_1 * texelsPerTile));
    uint _1025_dummy_parameter;
    int2 _1025 = int2(spvTextureSize(overheadMap, uint(0), _1025_dummy_parameter));
    if (any(bool2(at.x >= _1025.x, at.y >= _1025.y)))
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
    uint _1180_dummy_parameter;
    int2 size = int2(spvTextureSize(trailMap, uint(0), _1180_dummy_parameter));
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
    float _1235;
    float _1248;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(base + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        if ((i & 1) == 1)
        {
            _1235 = f.x;
        }
        else
        {
            _1235 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1248 = f.y;
        }
        else
        {
            _1248 = 1.0f - f.y;
        }
        float w = _1235 * _1248;
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
    float _1304;
    if (hueW > 9.9999997473787516355514526367188e-05f)
    {
        _1304 = hueSum / hueW;
    }
    else
    {
        _1304 = 0.0f;
    }
    float hue = _1304;
    float _1314;
    if (hueW > 9.9999997473787516355514526367188e-05f)
    {
        _1314 = lerp(0.0199999995529651641845703125f, 0.14000000059604644775390625f, clamp(((lumSum / hueW) - 0.37999999523162841796875f) / 0.23999999463558197021484375f, 0.0f, 1.0f));
    }
    else
    {
        _1314 = 0.0f;
    }
    speciesLumRef = _1314;
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
    float3 _2467;
    if (s < 0.2599999904632568359375f)
    {
        _2467 = lerp(g0, g1, (s / 0.2599999904632568359375f).xxx);
    }
    else
    {
        float3 _2479;
        if (s < 0.540000021457672119140625f)
        {
            _2479 = lerp(g1, g2, ((s - 0.2599999904632568359375f) / 0.2800000011920928955078125f).xxx);
        }
        else
        {
            float3 _2493;
            if (s < 0.7799999713897705078125f)
            {
                _2493 = lerp(g2, g3, ((s - 0.540000021457672119140625f) / 0.23999999463558197021484375f).xxx);
            }
            else
            {
                _2493 = lerp(g3, g4, ((s - 0.7799999713897705078125f) / 0.2199999988079071044921875f).xxx);
            }
            _2479 = _2493;
        }
        _2467 = _2479;
    }
    float3 goldColor = _2467;
    float3 o0 = float3(0.3449999988079071044921875f, 0.203999996185302734375f, 0.0390000008046627044677734375f);
    float3 o1 = float3(0.62000000476837158203125f, 0.3059999942779541015625f, 0.054999999701976776123046875f);
    float3 o2 = float3(0.862999975681304931640625f, 0.4709999859333038330078125f, 0.10999999940395355224609375f);
    float3 o3 = float3(0.972999989986419677734375f, 0.62000000476837158203125f, 0.17299999296665191650390625f);
    float3 o4 = float3(0.984000027179718017578125f, 0.7530000209808349609375f, 0.2269999980926513671875f);
    float3 _2536;
    if (s < 0.2599999904632568359375f)
    {
        _2536 = lerp(o0, o1, (s / 0.2599999904632568359375f).xxx);
    }
    else
    {
        float3 _2548;
        if (s < 0.540000021457672119140625f)
        {
            _2548 = lerp(o1, o2, ((s - 0.2599999904632568359375f) / 0.2800000011920928955078125f).xxx);
        }
        else
        {
            float3 _2561;
            if (s < 0.7799999713897705078125f)
            {
                _2561 = lerp(o2, o3, ((s - 0.540000021457672119140625f) / 0.23999999463558197021484375f).xxx);
            }
            else
            {
                _2561 = lerp(o3, o4, ((s - 0.7799999713897705078125f) / 0.2199999988079071044921875f).xxx);
            }
            _2548 = _2561;
        }
        _2536 = _2548;
    }
    float3 orangeColor = _2536;
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
    float _3261;
    if (mapped)
    {
        float2 param_1 = here.xy;
        float param_2 = here.z;
        _3261 = here.z - terrainBaseAt(param_1, param_2);
    }
    else
    {
        _3261 = here.z;
    }
    float relZ = _3261;
    if (hasLiveFloraMap)
    {
        float2 param_3 = here.xy;
        float param_4;
        float4 _3286 = floraAt(param_3, param_4);
        stampedLumRef = param_4;
        float4 flora = _3286;
        float lowBlock = smoothstep(0.1599999964237213134765625f, 0.4000000059604644775390625f, flora.x);
        float tallBlock = smoothstep(0.680000007152557373046875f, 0.87999999523162841796875f, flora.x);
        keepGreen = lerp(lowBlock, tallBlock, smoothstep(1.2999999523162841796875f, 1.7000000476837158203125f, relZ));
        explicitDeciduous = clamp(flora.w * 2.5f, 0.0f, 1.0f);
        explicitShrub = explicitDeciduous * (1.0f - smoothstep(0.0199999995529651641845703125f, 0.119999997317790985107421875f, flora.y));
        speciesHue = lerp(speciesHue, flora.z, explicitDeciduous);
    }
    float _3322;
    if (hasLiveFloraMap)
    {
        _3322 = explicitDeciduous;
    }
    else
    {
        _3322 = smoothstep(0.14000000059604644775390625f, 0.319999992847442626953125f, relZ);
    }
    float isDeciduous = (1.0f - keepGreen) * _3322;
    float isCanopy = smoothstep(0.64999997615814208984375f, 1.35000002384185791015625f, relZ);
    float defaultLumRef = lerp(0.075999997556209564208984375f, 0.03599999845027923583984375f, isCanopy);
    float _3344;
    if (hasLiveFloraMap && (stampedLumRef > 0.004999999888241291046142578125f))
    {
        _3344 = lerp(defaultLumRef, stampedLumRef, explicitDeciduous);
    }
    else
    {
        _3344 = defaultLumRef;
    }
    float lumRef = _3344;
    float u = lum / max(lumRef, 0.017999999225139617919921875f);
    float sunlit = smoothstep(0.3499999940395355224609375f, 2.2000000476837158203125f, u);
    float2 param_5 = ((lot * 5.5f) + float2(here.z * 3.099999904632568359375f, (-here.z) * 2.400000095367431640625f)) + 19.1000003814697265625f.xx;
    float leafDetail = valueNoise(param_5);
    float sunlitT = clamp(((0.180000007152557373046875f + (0.7400000095367431640625f * sunlit)) + (0.07999999821186065673828125f * leafDetail)) + (0.0500000007450580596923828125f * (amount - 0.5f)), 0.0f, 1.0f);
    float evergreenWarm = ((((sim ? 0.0f : foliageGreen) * keepGreen) * outdoor) * smoothstep(0.07999999821186065673828125f, 0.699999988079071044921875f, amount)) * (0.14000000059604644775390625f + (0.1599999964237213134765625f * leafDetail));
    float turned = (((sim ? 0.0f : foliageGreen) * isDeciduous) * outdoor) * smoothstep(0.039999999105930328369140625f + (0.0599999986588954925537109375f * (1.0f - sunlit)), 0.2199999988079071044921875f + (0.07999999821186065673828125f * (1.0f - sunlit)), amount);
    if ((turned <= 0.004999999888241291046142578125f) && (evergreenWarm <= 0.004999999888241291046142578125f))
    {
        return col;
    }
    float3 _3443;
    if (evergreenWarm > 0.004999999888241291046142578125f)
    {
        float3 param_6 = col;
        float3 param_7 = float3(0.4799999892711639404296875f, 0.439999997615814208984375f, 0.14000000059604644775390625f);
        _3443 = lerp(col, recolor(param_6, param_7), evergreenWarm.xxx);
    }
    else
    {
        _3443 = col;
    }
    float3 baseCol = _3443;
    if (turned <= 0.004999999888241291046142578125f)
    {
        return baseCol;
    }
    float param_8 = sunlitT;
    float param_9 = speciesHue;
    float3 param_10 = makinMagicTreeSrgb(param_8, param_9);
    float3 hueLin = srgbToLinear(param_10);
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
    return lerp(baseCol, turnedColor, (turned * blend).xxx);
}

float pavedAt(inout float2 q)
{
    float2 param = q;
    float2 sourcePoint = lotSource(param);
    bool _1344 = any(bool2(sourcePoint.x < 1.0f.xx.x, sourcePoint.y < 1.0f.xx.y));
    bool _1356;
    if (!_1344)
    {
        float2 _1353 = ambient_drift.zw - 1.0f.xx;
        _1356 = any(bool2(sourcePoint.x > _1353.x, sourcePoint.y > _1353.y));
    }
    else
    {
        _1356 = _1344;
    }
    bool scenery = _1356;
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
    float _1515;
    float _1528;
    float2 _1549;
    float2 _1555;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 2;
        bool _1451 = maskAt(param_1, param_2) == 0;
        bool _1460;
        if (!_1451)
        {
            int2 param_3 = at;
            int param_4 = 0;
            _1460 = maskAt(param_3, param_4) >= 2;
        }
        else
        {
            _1460 = _1451;
        }
        if (_1460)
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
            _1515 = f.x;
        }
        else
        {
            _1515 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1528 = f.y;
        }
        else
        {
            _1528 = 1.0f - f.y;
        }
        float weight = _1515 * _1528;
        int part = f4 & 7;
        if (part != 0)
        {
            if (part == 1)
            {
                _1549 = float2(1.0f, -1.0f);
            }
            else
            {
                if (part == 2)
                {
                    _1555 = float2(-1.0f, 1.0f);
                }
                else
                {
                    bool2 _1561 = (part == 3).xx;
                    _1555 = float2(_1561.x ? (-1.0f).xx.x : 1.0f.xx.x, _1561.y ? (-1.0f).xx.y : 1.0f.xx.y);
                }
                _1549 = _1555;
            }
            float2 toward = _1549;
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
    bool _1595 = any(bool2(sourcePoint.x < 0.5f.xx.x, sourcePoint.y < 0.5f.xx.y));
    bool _1607;
    if (!_1595)
    {
        float2 _1604 = ambient_drift.zw - 0.5f.xx;
        _1607 = any(bool2(sourcePoint.x > _1604.x, sourcePoint.y > _1604.y));
    }
    else
    {
        _1607 = _1595;
    }
    if (_1607)
    {
        return 0.0f;
    }
    float2 cell = (q + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.4000000059604644775390625f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _1681;
    float _1694;
    for (int i = 0; i < 4; i++)
    {
        int2 at = base + int2(i & 1, i >> 1);
        int2 param_1 = at;
        int param_2 = 2;
        bool _1656 = maskAt(param_1, param_2) == 0;
        bool _1665;
        if (!_1656)
        {
            int2 param_3 = at;
            int param_4 = 0;
            _1665 = maskAt(param_3, param_4) >= 2;
        }
        else
        {
            _1665 = _1656;
        }
        if (_1665)
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
            _1681 = f.x;
        }
        else
        {
            _1681 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1694 = f.y;
        }
        else
        {
            _1694 = 1.0f - f.y;
        }
        sum += (_1681 * _1694);
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
    uint _2209_dummy_parameter;
    int2 size = int2(spvTextureSize(heightMap, uint(0), _2209_dummy_parameter));
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
    bool _2324 = indoors(param_10) > 0.0500000007450580596923828125f;
    bool _2332;
    if (!_2324)
    {
        float3 param_11 = p;
        _2332 = architecturalExposure(param_11) < 0.949999988079071044921875f;
    }
    else
    {
        _2332 = _2324;
    }
    if (_2332)
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
            bool _2380 = k == 1;
            bool _2395;
            if (_2380)
            {
                float3 param_12 = np;
                bool _2386 = indoors(param_12) > 0.0500000007450580596923828125f;
                bool _2394;
                if (!_2386)
                {
                    float3 param_13 = np;
                    _2394 = architecturalExposure(param_13) < 0.949999988079071044921875f;
                }
                else
                {
                    _2394 = _2386;
                }
                _2395 = _2394;
            }
            else
            {
                _2395 = _2380;
            }
            if (_2395)
            {
                return 0.0f;
            }
            float2 param_14 = nxy;
            if ((topAt(param_14) - baseZ) <= 1.35000002384185791015625f)
            {
                connectedHigh = false;
                break;
            }
            bool _2424;
            if (connectedHigh)
            {
                float3 param_15 = np;
                bool _2415 = indoors(param_15) > 0.0500000007450580596923828125f;
                bool _2423;
                if (!_2415)
                {
                    float3 param_16 = np;
                    _2423 = architecturalExposure(param_16) < 0.949999988079071044921875f;
                }
                else
                {
                    _2423 = _2415;
                }
                _2424 = _2423;
            }
            else
            {
                _2424 = connectedHigh;
            }
            if (_2424)
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
    float3 _2613;
    if (s < 0.3400000035762786865234375f)
    {
        _2613 = lerp(gl0, gl1, (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _2626;
        if (s < 0.699999988079071044921875f)
        {
            _2626 = lerp(gl1, gl2, ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _2626 = lerp(gl2, gl3, ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _2613 = _2626;
    }
    float3 goldLeaf = _2613;
    float3 ol0 = float3(0.9409999847412109375f, 0.579999983310699462890625f, 0.1410000026226043701171875f);
    float3 ol1 = float3(0.910000026226043701171875f, 0.3449999988079071044921875f, 0.09399999678134918212890625f);
    float3 ol2 = float3(0.834999978542327880859375f, 0.607999980449676513671875f, 0.17299999296665191650390625f);
    float3 ol3 = float3(0.53299999237060546875f, 0.2199999988079071044921875f, 0.09399999678134918212890625f);
    float3 _2660;
    if (s < 0.3400000035762786865234375f)
    {
        _2660 = lerp(ol0, ol1, (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _2672;
        if (s < 0.699999988079071044921875f)
        {
            _2672 = lerp(ol1, ol2, ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _2672 = lerp(ol2, ol3, ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _2660 = _2672;
    }
    float3 orangeLeaf = _2660;
    return lerp(goldLeaf, orangeLeaf, clamp(speciesHue, 0.0f, 1.0f).xxx);
}

float3 applyAutumnGround(float3 col, float3 hereG, float2 gLot, float gPixelScale, float amount, float gOutdoor, float gSkyExposed, bool mapped, bool hasLiveFloraMap, bool leavesOnlyOnTurf)
{
    float gLum = dot(col, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
    float gGreen = smoothstep(0.0599999986588954925537109375f, 0.2199999988079071044921875f, (col.y - max(col.x, col.z)) / max(col.y, 0.039999999105930328369140625f));
    float3 outCol = col;
    float _3583;
    if (mapped)
    {
        float2 param = hereG.xy;
        float _3589 = pavedAt(param);
        _3583 = _3589;
    }
    else
    {
        _3583 = 0.0f;
    }
    float autPaved = _3583;
    float _3594;
    if (mapped)
    {
        float2 param_1 = hereG.xy;
        _3594 = cementAt(param_1);
    }
    else
    {
        _3594 = 0.0f;
    }
    float autCement = _3594;
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
            float4 _3729 = floraAt(param_8, param_9);
            unusedLumRef = param_9;
            float4 flora = _3729;
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
            bool _3997 = l0.x > 0.004999999888241291046142578125f;
            bool _4004;
            if (!_3997)
            {
                _4004 = l0.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _4004 = _3997;
            }
            if (_4004)
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
            bool _4060 = l1.x > 0.004999999888241291046142578125f;
            bool _4067;
            if (!_4060)
            {
                _4067 = l1.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _4067 = _4060;
            }
            if (_4067)
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
            bool _4126 = l2.x > 0.004999999888241291046142578125f;
            bool _4133;
            if (!_4126)
            {
                _4133 = l2.y > 0.004999999888241291046142578125f;
            }
            else
            {
                _4133 = _4126;
            }
            if (_4133)
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
    float _4184;
    if (isGroundF > 0.5f)
    {
        float2 param_1 = xy;
        float _4189 = pavedAt(param_1);
        _4184 = _4189;
    }
    else
    {
        _4184 = 0.0f;
    }
    float pavedHere = _4184;
    float _4195;
    if (isGroundF > 0.5f)
    {
        float2 param_2 = xy;
        _4195 = cementAt(param_2);
    }
    else
    {
        _4195 = 0.0f;
    }
    float cementHere = _4195;
    float _4212;
    if (((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f)) && (cementHere < 0.3499999940395355224609375f))
    {
        _4212 = smoothstep(0.319999992847442626953125f, 0.519999980926513671875f, c.z) * smoothstep(0.00999999977648258209228515625f, 0.0500000007450580596923828125f, c.z - c.x);
    }
    else
    {
        _4212 = 0.0f;
    }
    float vacSnowBlue = _4212;
    isVacSnowLot = clamp(max(vacLot, vacSnowBlue), 0.0f, 1.0f);
    float warmOverGreen = smoothstep(-0.00999999977648258209228515625f, 0.039999999105930328369140625f, (c.x - c.y) / max(c.x, 0.0500000007450580596923828125f));
    float vacWarmth = (c.x - c.z) / max(c.x + c.z, 0.0500000007450580596923828125f);
    float naturalEarth = max(greenOut, smoothstep(0.4000000059604644775390625f, 0.540000021457672119140625f, vacWarmth));
    earthMask = (isGroundF * clamp(max(naturalEarth, isVacSnowLot), 0.0f, 1.0f)) * (1.0f - cementHere);
    float _4276;
    if ((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f))
    {
        _4276 = (((warmOverGreen * smoothstep(0.014999999664723873138427734375f, 0.23999999463558197021484375f, vacWarmth)) * smoothstep(0.02999999932944774627685546875f, 0.100000001490116119384765625f, c.x)) * isVacSnowLot) * (1.0f - cementHere);
    }
    else
    {
        _4276 = 0.0f;
    }
    float vacDirt = _4276;
    float _4301;
    if ((isGroundF > 0.5f) && (pavedHere < 0.3499999940395355224609375f))
    {
        _4301 = (((smoothstep(0.7599999904632568359375f, 1.12000000476837158203125f, c.x / max(c.y, 0.014999999664723873138427734375f)) * smoothstep(0.4199999868869781494140625f, 0.579999983310699462890625f, vacWarmth)) * smoothstep(0.014999999664723873138427734375f, 0.04500000178813934326171875f, max(c.x, c.y))) * (1.0f - isVacSnowLot)) * (1.0f - cementHere);
    }
    else
    {
        _4301 = 0.0f;
    }
    float homeWear = _4301;
    terrainWear = max(vacDirt, homeWear);
}

float snowCrust(float2 lq)
{
    float2 param = (lq * 3.599999904632568359375f) + 3.2000000476837158203125f.xx;
    float2 param_1 = (lq * 8.80000019073486328125f) + 17.3999996185302734375f.xx;
    return (valueNoise(param) * 0.64999997615814208984375f) + (valueNoise(param_1) * 0.3499999940395355224609375f);
}

float3 winterDullColor(float3 c, float2 xy, float2 lotPt, float lumVal, float greenVal, float hereCrust, float earthMask, float terrainWear, float isVacSnowLot, float coveredVal, bool isGround, float amount)
{
    float snowPresence = smoothstep(0.0f, 0.3499999940395355224609375f, amount);
    bool3 _4344 = (isGround && (isVacSnowLot < 0.5f)).xxx;
    float3 targetHue = float3(_4344.x ? float3(0.310000002384185791015625f, 0.37999999523162841796875f, 0.2800000011920928955078125f).x : float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f).x, _4344.y ? float3(0.310000002384185791015625f, 0.37999999523162841796875f, 0.2800000011920928955078125f).y : float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f).y, _4344.z ? float3(0.310000002384185791015625f, 0.37999999523162841796875f, 0.2800000011920928955078125f).z : float3(0.300000011920928955078125f, 0.4199999868869781494140625f, 0.36000001430511474609375f).z);
    float3 param = c;
    float3 param_1 = targetHue;
    return lerp(c, recolor(param, param_1), ((0.37999999523162841796875f * greenVal) * snowPresence).xxx);
}

float groundAt(float2 pixel)
{
    float ground = groundMap.Load(int3(int2(pixel), 0)).x;
    float _407;
    if (ground < 1.0f)
    {
        _407 = (((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f;
    }
    else
    {
        _407 = -100000.0f;
    }
    return _407;
}

float nearIndoorWall(float2 xy, float z, float radius)
{
    float w = 0.0f;
    float _3157;
    float _3167;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            _3157 = 1.0f;
        }
        else
        {
            _3157 = (i == 1) ? (-1.0f) : 0.0f;
        }
        if (i == 2)
        {
            _3167 = 1.0f;
        }
        else
        {
            _3167 = (i == 3) ? (-1.0f) : 0.0f;
        }
        float2 card = float2(_3157, _3167) * radius;
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

float pressedAt(float2 at)
{
    uint _1087_dummy_parameter;
    int2 size = int2(spvTextureSize(trailMap, uint(0), _1087_dummy_parameter));
    if (size.x < 4)
    {
        return 0.0f;
    }
    float2 param = at;
    float2 texel = ((lotSource(param) + 1.0f.xx) * 32.0f) - 0.5f.xx;
    int2 base = int2(floor(texel));
    float2 f = texel - float2(base);
    float sum = 0.0f;
    float _1142;
    float _1156;
    for (int i = 0; i < 4; i++)
    {
        int2 c = clamp(base + int2(i & 1, i >> 1), int2(0, 0), size - int2(1, 1));
        if ((i & 1) == 1)
        {
            _1142 = f.x;
        }
        else
        {
            _1142 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _1156 = f.y;
        }
        else
        {
            _1156 = 1.0f - f.y;
        }
        sum += ((trailMap.Load(int3(c, 0)).x * _1142) * _1156);
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
    float _2111 = pavedAt(param_12);
    float paved = _2111;
    float paveKeep = 1.0f - (paved * lerp(0.959999978542327880859375f, 0.99500000476837158203125f, clamp(amount - 0.60000002384185791015625f, 0.0f, 1.0f)));
    float snow = ((((full * onset) * outside) * depthScale) * (1.0f + (0.1599999964237213134765625f * bank))) * paveKeep;
    if (snow <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    float2 param_13 = q;
    return snow - (min(0.02500000037252902984619140625f, snow * 0.5f) * pressedAt(param_13));
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
    int _4444 = steps - 1;
    for (int i = _4444; i >= 0; i--)
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
    float _4524;
    if (nextS >= 0.0f)
    {
        _4524 = smoothstep((0.7200000286102294921875f * dt) + 0.017999999225139617919921875f, (0.7200000286102294921875f * dt) + 0.05200000107288360595703125f, hitS - nextS);
    }
    else
    {
        _4524 = 0.0f;
    }
    float faceBlend = _4524;
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
    float _4663;
    if (isGround)
    {
        float2 param_30 = q;
        float _4668 = pavedAt(param_30);
        _4663 = _4668;
    }
    else
    {
        _4663 = 0.0f;
    }
    float qPaved = _4663;
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
        float normSnow = hitS / 0.054999999701976776123046875f;
        float notPaved = 1.0f - smoothstep(0.25f, 0.64999997615814208984375f, qPaved);
        float2 param_43 = (lq * 22.0f) + 4.099999904632568359375f.xx;
        float2 param_44 = (lq * 39.0f) + 13.69999980926513671875f.xx;
        float tuft = (valueNoise(param_43) * 0.64999997615814208984375f) + (valueNoise(param_44) * 0.3499999940395355224609375f);
        float3 param_45 = srcCol;
        float grassBlade = greenOf(param_45) * clamp((0.449999988079071044921875f * smoothstep(0.039999999105930328369140625f, 0.1599999964237213134765625f, lumVal)) + (0.550000011920928955078125f * tuft), 0.0f, 1.0f);
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
    float3 param_46 = baseCol;
    float3 param_47 = seen;
    float param_48 = edge;
    return mixPerceptual(param_46, param_47, param_48);
}

void frag_main()
{
    float2 pixel = floor(gl_FragCoord.xy) + 0.5f.xx;
    color = 0.0f.xxxx;
    lift = 0.0f.xxxx;
    bool _5512 = pixel.x >= ambient_extent.x;
    bool _5521;
    if (!_5512)
    {
        _5521 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _5521 = _5512;
    }
    if (_5521)
    {
        return;
    }
    bool _5527 = ambient_season.x >= 1.5f;
    bool _5534;
    if (_5527)
    {
        _5534 = ambient_seasonExtra2.w > 0.5f;
    }
    else
    {
        _5534 = _5527;
    }
    if (_5534)
    {
        int2 ip = int2(floor(gl_FragCoord.xy));
        int2 maxI = max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0));
        float4 stLift = trailMap.Load(int3(ip, 0));
        float4 _5558;
        if (stLift.z > 0.5f)
        {
            _5558 = stLift;
        }
        else
        {
            float _5566;
            if (stLift.z < (-0.00200000009499490261077880859375f))
            {
                _5566 = stLift.z;
            }
            else
            {
                _5566 = 0.0f;
            }
            _5558 = float4(0.0f, 0.0f, _5566, stLift.w);
        }
        lift = _5558;
        uint _5580_dummy_parameter;
        bool hasSpriteLayer = int2(spvTextureSize(spriteMap, uint(0), _5580_dummy_parameter)).x > 4;
        int2 param = ip;
        int2 param_1 = maxI;
        bool param_2 = hasSpriteLayer;
        float4 _5590 = resolveWinterPixel(param, param_1, param_2);
        float4 cM = _5590;
        float3 origM = overheadMap.Load(int3(ip, 0)).xyz;
        uint _5601_dummy_parameter;
        bool _5603 = int2(spvTextureSize(simMap, uint(0), _5601_dummy_parameter)).x > 1;
        bool _5612;
        if (_5603)
        {
            _5612 = simMap.Load(int3(ip, 0)).x > 0.5f;
        }
        else
        {
            _5612 = _5603;
        }
        bool isSim = _5612;
        if (isSim)
        {
            float3 _5620 = abs(cM.xyz - origM);
            if (all(bool3(_5620.x < 9.9999997473787516355514526367188e-05f.xxx.x, _5620.y < 9.9999997473787516355514526367188e-05f.xxx.y, _5620.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
            {
                return;
            }
            color = float4(cM.xyz, 1.0f);
            return;
        }
        int2 param_3 = ip + int2(0, -1);
        int2 param_4 = maxI;
        bool param_5 = hasSpriteLayer;
        float4 _5642 = resolveWinterPixel(param_3, param_4, param_5);
        float4 cN = _5642;
        int2 param_6 = ip + int2(0, 1);
        int2 param_7 = maxI;
        bool param_8 = hasSpriteLayer;
        float4 _5651 = resolveWinterPixel(param_6, param_7, param_8);
        float4 cS = _5651;
        int2 param_9 = ip + int2(-1, 0);
        int2 param_10 = maxI;
        bool param_11 = hasSpriteLayer;
        float4 _5660 = resolveWinterPixel(param_9, param_10, param_11);
        float4 cW = _5660;
        int2 param_12 = ip + int2(1, 0);
        int2 param_13 = maxI;
        bool param_14 = hasSpriteLayer;
        float4 _5669 = resolveWinterPixel(param_12, param_13, param_14);
        float4 cE = _5669;
        int2 param_15 = ip + int2(-1, -1);
        int2 param_16 = maxI;
        bool param_17 = hasSpriteLayer;
        float4 _5679 = resolveWinterPixel(param_15, param_16, param_17);
        float4 cNW = _5679;
        int2 param_18 = ip + int2(1, -1);
        int2 param_19 = maxI;
        bool param_20 = hasSpriteLayer;
        float4 _5689 = resolveWinterPixel(param_18, param_19, param_20);
        float4 cNE = _5689;
        int2 param_21 = ip + int2(-1, 1);
        int2 param_22 = maxI;
        bool param_23 = hasSpriteLayer;
        float4 _5699 = resolveWinterPixel(param_21, param_22, param_23);
        float4 cSW = _5699;
        int2 param_24 = ip + int2(1, 1);
        int2 param_25 = maxI;
        bool param_26 = hasSpriteLayer;
        float4 _5709 = resolveWinterPixel(param_24, param_25, param_26);
        float4 cSE = _5709;
        float sMax = max(cM.w, max(max(max(cN.w, cS.w), max(cE.w, cW.w)), max(max(cNW.w, cNE.w), max(cSW.w, cSE.w))));
        if (sMax < 0.02999999932944774627685546875f)
        {
            float3 _5745 = abs(cM.xyz - origM);
            if (all(bool3(_5745.x < 9.9999997473787516355514526367188e-05f.xxx.x, _5745.y < 9.9999997473787516355514526367188e-05f.xxx.y, _5745.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
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
        int2 _5932;
        if (isHorz)
        {
            _5932 = int2(0, is1Steeper ? (-1) : 1);
        }
        else
        {
            _5932 = int2(is1Steeper ? (-1) : 1, 0);
        }
        int2 stepPerp = _5932;
        bool2 _5945 = isHorz.xx;
        int2 stepTan = int2(_5945.x ? int2(1, 0).x : int2(0, 1).x, _5945.y ? int2(1, 0).y : int2(0, 1).y);
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
                float4 _5989 = resolveWinterPixel(param_36, param_37, param_38);
                float3 param_39 = _5989.xyz;
                int2 param_40 = pN + stepPerp;
                int2 param_41 = maxI;
                bool param_42 = hasSpriteLayer;
                float4 _6001 = resolveWinterPixel(param_40, param_41, param_42);
                float3 param_43 = _6001.xyz;
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
                float4 _6035 = resolveWinterPixel(param_44, param_45, param_46);
                float3 param_47 = _6035.xyz;
                int2 param_48 = pP + stepPerp;
                int2 param_49 = maxI;
                bool param_50 = hasSpriteLayer;
                float4 _6047 = resolveWinterPixel(param_48, param_49, param_50);
                float3 param_51 = _6047.xyz;
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
        float _6096;
        if (goodSpan)
        {
            _6096 = max(0.0f, 0.5f - (dMin / spanLen));
        }
        else
        {
            _6096 = 0.0f;
        }
        float edgeBlend = _6096;
        float avg9 = (((((2.0f * (((lN + lS) + lE) + lW)) + lNW) + lNE) + lSW) + lSE) / 12.0f;
        float subpix = clamp(abs(avg9 - lM) / max(lRange, 9.9999997473787516355514526367188e-05f), 0.0f, 1.0f);
        subpix = smoothstep(0.0f, 1.0f, subpix);
        float subpixAA = (0.64999997615814208984375f * subpix) * subpix;
        int2 perpPx = clamp(ip + stepPerp, int2(0, 0), maxI);
        uint _6150_dummy_parameter;
        bool _6152 = int2(spvTextureSize(simMap, uint(0), _6150_dummy_parameter)).x > 1;
        bool _6161;
        if (_6152)
        {
            _6161 = simMap.Load(int3(perpPx, 0)).x > 0.5f;
        }
        else
        {
            _6161 = _6152;
        }
        bool perpSim = _6161;
        float _6164;
        if (perpSim)
        {
            _6164 = 0.0f;
        }
        else
        {
            _6164 = max(edgeBlend, subpixAA) * smoothstep(0.039999999105930328369140625f, 0.180000007152557373046875f, sMax);
        }
        float finalBlend = _6164;
        float3 _6179;
        if (stepPerp.y < 0)
        {
            _6179 = cN.xyz;
        }
        else
        {
            float3 _6188;
            if (stepPerp.y > 0)
            {
                _6188 = cS.xyz;
            }
            else
            {
                float3 _6197;
                if (stepPerp.x < 0)
                {
                    _6197 = cW.xyz;
                }
                else
                {
                    _6197 = cE.xyz;
                }
                _6188 = _6197;
            }
            _6179 = _6188;
        }
        float3 perpCol = _6179;
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
    float _6250;
    if (ground)
    {
        _6250 = ((0.89999997615814208984375f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
    }
    else
    {
        _6250 = (0.89999997615814208984375f - depthMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f;
    }
    float key = _6250;
    float2 param_56 = centre.xy;
    float param_57 = key;
    bool param_58 = ground;
    float2 param_59 = ambient_frame.xy;
    float3 here = lotPoint(param_56, param_57, param_58, param_59);
    float _6289;
    if (mapped)
    {
        float3 param_60 = here;
        _6289 = 1.0f - indoors(param_60);
    }
    else
    {
        _6289 = 1.0f;
    }
    float outdoor = _6289;
    if (mapped && (!ground))
    {
        float3 param_61 = here - float3(0.0f, 0.0f, 0.25f);
        outdoor = min(outdoor, 1.0f - indoors(param_61));
    }
    float _6314;
    if (mapped)
    {
        float3 _6318;
        if (ground)
        {
            _6318 = here;
        }
        else
        {
            _6318 = here + float3(0.0f, 0.0f, 0.449999988079071044921875f);
        }
        float3 param_62 = _6318;
        _6314 = architecturalExposure(param_62);
    }
    else
    {
        _6314 = 1.0f;
    }
    float skyExposed = _6314;
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
    float _6377;
    if (mapped)
    {
        float2 param_64 = here.xy;
        _6377 = topAt(param_64) - here.z;
    }
    else
    {
        _6377 = 0.0f;
    }
    float over = _6377;
    float covered = smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, over);
    bool _6398;
    if (mapped)
    {
        _6398 = ambient_season.x > 1.5f;
    }
    else
    {
        _6398 = mapped;
    }
    if (_6398)
    {
        float _6412;
        float _6422;
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                _6412 = 1.0f;
            }
            else
            {
                _6412 = (i == 1) ? (-1.0f) : 0.0f;
            }
            if (i == 2)
            {
                _6422 = 1.0f;
            }
            else
            {
                _6422 = (i == 3) ? (-1.0f) : 0.0f;
            }
            float2 offset = float2(_6412, _6422) * 0.3499999940395355224609375f;
            float2 param_65 = here.xy + offset;
            covered += smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, topAt(param_65) - here.z);
        }
        covered /= 5.0f;
    }
    float3 result = src;
    uint _6453_dummy_parameter;
    bool _6455 = int2(spvTextureSize(simMap, uint(0), _6453_dummy_parameter)).x > 1;
    bool _6465;
    if (_6455)
    {
        _6465 = simMap.Load(int3(int2(pixel), 0)).x > 0.5f;
    }
    else
    {
        _6465 = _6455;
    }
    bool sim = _6465;
    bool _6475;
    if (mapped)
    {
        uint _6472_dummy_parameter;
        _6475 = int2(spvTextureSize(trailMap, uint(0), _6472_dummy_parameter)).x > 4;
    }
    else
    {
        _6475 = mapped;
    }
    bool _6485;
    if (_6475)
    {
        _6485 = abs(trailMap.Load(int3(int2(0, 0), 0)).w - 0.5f) < 0.180000007152557373046875f;
    }
    else
    {
        _6485 = _6475;
    }
    bool hasLiveFloraMap = _6485;
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
        float3 _6574 = abs(result - src);
        if (all(bool3(_6574.x < 9.9999997473787516355514526367188e-05f.xxx.x, _6574.y < 9.9999997473787516355514526367188e-05f.xxx.y, _6574.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
        {
            return;
        }
    }
    else
    {
        if (ambient_season.x < 1.5f)
        {
            uint _6589_dummy_parameter;
            bool hasSpriteLayer_1 = int2(spvTextureSize(spriteMap, uint(0), _6589_dummy_parameter)).x > 4;
            float4 _6594;
            if (hasSpriteLayer_1)
            {
                _6594 = spriteMap.Load(int3(int2(pixel), 0));
            }
            else
            {
                _6594 = 0.0f.xxxx;
            }
            float4 sp = _6594;
            if (!ground)
            {
                bool _6614;
                if (hasSpriteLayer_1)
                {
                    _6614 = sp.w > 0.00200000009499490261077880859375f;
                }
                else
                {
                    _6614 = hasSpriteLayer_1;
                }
                bool _6620;
                if (_6614)
                {
                    _6620 = sp.w < 0.9900000095367431640625f;
                }
                else
                {
                    _6620 = _6614;
                }
                if (_6620)
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
                        float _6698;
                        if (mapped)
                        {
                            float3 param_84 = hereG;
                            _6698 = 1.0f - indoors(param_84);
                        }
                        else
                        {
                            _6698 = 1.0f;
                        }
                        float gOutdoor = _6698;
                        if (gOutdoor > 0.0f)
                        {
                            float _6713;
                            if (mapped)
                            {
                                float3 param_85 = hereG;
                                _6713 = architecturalExposure(param_85);
                            }
                            else
                            {
                                _6713 = 1.0f;
                            }
                            float gSkyExposed = _6713;
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
                    bool _6772;
                    if (hasSpriteLayer_1)
                    {
                        _6772 = sp.w >= 0.9900000095367431640625f;
                    }
                    else
                    {
                        _6772 = hasSpriteLayer_1;
                    }
                    float3 _6773;
                    if (_6772)
                    {
                        _6773 = clamp(sp.xyz / sp.w.xxx, 0.0f.xxx, 1.0f.xxx);
                    }
                    else
                    {
                        _6773 = src;
                    }
                    float3 F_1 = _6773;
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
            bool _6831 = ((frost > 0.0199999995529651641845703125f) && (skyExposed > 0.001000000047497451305389404296875f)) && (!sim);
            bool _6838;
            if (_6831)
            {
                _6838 = ground || (green > 0.0500000007450580596923828125f);
            }
            else
            {
                _6838 = _6831;
            }
            if (_6838)
            {
                float2 param_115 = lot * 6.0f;
                float2 param_116 = (lot * 19.0f) + 7.099999904632568359375f.xx;
                float rime_1 = smoothstep(0.37999999523162841796875f, 0.839999973773956298828125f, (valueNoise(param_115) * 0.550000011920928955078125f) + (valueNoise(param_116) * 0.449999988079071044921875f));
                float _6858;
                if (ground)
                {
                    float2 param_117 = here.xy;
                    float _6864 = pavedAt(param_117);
                    _6858 = 1.0f - (0.85000002384185791015625f * _6864);
                }
                else
                {
                    _6858 = green;
                }
                float mask = _6858;
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
                uint _6913_dummy_parameter;
                bool hasSpriteLayer_2 = int2(spvTextureSize(spriteMap, uint(0), _6913_dummy_parameter)).x > 4;
                float4 _6918;
                if (hasSpriteLayer_2)
                {
                    _6918 = spriteMap.Load(int3(int2(pixel), 0));
                }
                else
                {
                    _6918 = 0.0f.xxxx;
                }
                float4 sp_1 = _6918;
                bool _6935;
                if (hasSpriteLayer_2)
                {
                    _6935 = sp_1.w > 0.0040000001899898052215576171875f;
                }
                else
                {
                    _6935 = hasSpriteLayer_2;
                }
                bool _6941;
                if (_6935)
                {
                    _6941 = sp_1.w < 0.9900000095367431640625f;
                }
                else
                {
                    _6941 = _6935;
                }
                bool hasPartialSprite = _6941;
                float3 _6944;
                if (hasPartialSprite)
                {
                    _6944 = clamp((src - sp_1.xyz) / max(1.0f - sp_1.w, 0.0199999995529651641845703125f).xxx, 0.0f.xxx, 1.0f.xxx);
                }
                else
                {
                    _6944 = src;
                }
                float3 spriteB = _6944;
                float3 _6963;
                if (hasPartialSprite)
                {
                    _6963 = clamp(sp_1.xyz / sp_1.w.xxx, 0.0f.xxx, 1.0f.xxx);
                }
                else
                {
                    _6963 = src;
                }
                float3 spriteF = _6963;
                float3 _6980;
                if (ground && hasPartialSprite)
                {
                    _6980 = spriteB;
                }
                else
                {
                    bool3 _6991 = ((!ground) && hasPartialSprite).xxx;
                    _6980 = float3(_6991.x ? spriteF.x : src.x, _6991.y ? spriteF.y : src.y, _6991.z ? spriteF.z : src.z);
                }
                float3 workSrc = _6980;
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
                float3 _7031;
                if (sim)
                {
                    _7031 = workSrc;
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
                    float param_141 = amount;
                    _7031 = winterDullColor(param_130, param_131, param_132, param_133, param_134, param_135, param_136, param_137, param_138, param_139, param_140, param_141);
                }
                float3 dull = _7031;
                float deep = clamp(amount - 1.0f, 0.0f, 1.0f);
                float poolWater = 0.0f;
                bool _7069 = !sim;
                bool _7077;
                if (_7069)
                {
                    _7077 = (!ground) || (!mapped);
                }
                else
                {
                    _7077 = _7069;
                }
                if (_7077)
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
                            float2 param_142 = lPx;
                            float4 ql = positionAt(param_142);
                            float2 param_143 = rPx;
                            float4 qr = positionAt(param_143);
                            float dxl = abs(p.x - ql.x);
                            float dxr = abs(qr.x - p.x);
                            bool _7176 = (ql.w < 0.25f) && (dxl > 0.25f);
                            bool _7191;
                            if (_7176)
                            {
                                _7191 = abs(ql.z - p.z) < ((1.60000002384185791015625f * dxl) + 4.5f);
                            }
                            else
                            {
                                _7191 = _7176;
                            }
                            bool lOk = _7191;
                            bool _7198 = (qr.w < 0.25f) && (dxr > 0.25f);
                            bool _7211;
                            if (_7198)
                            {
                                _7211 = abs(qr.z - p.z) < ((1.60000002384185791015625f * dxr) + 4.5f);
                            }
                            else
                            {
                                _7211 = _7198;
                            }
                            bool rOk = _7211;
                            if (workGreen < 0.1500000059604644775390625f)
                            {
                                bool _7228;
                                if (lOk)
                                {
                                    float3 param_144 = source.Load(int3(int2(lPx), 0)).xyz;
                                    _7228 = greenOf(param_144) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _7228 = lOk;
                                }
                                if (_7228)
                                {
                                    lOk = false;
                                }
                                bool _7243;
                                if (rOk)
                                {
                                    float3 param_145 = source.Load(int3(int2(rPx), 0)).xyz;
                                    _7243 = greenOf(param_145) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _7243 = rOk;
                                }
                                if (_7243)
                                {
                                    rOk = false;
                                }
                                if (r == 0)
                                {
                                    if (lOk)
                                    {
                                        float2 mPx = floor(clamp(pixel - float2(0.5f * st, 0.0f), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_146 = mPx;
                                        float4 qm = positionAt(param_146);
                                        bool _7270 = qm.w >= 0.25f;
                                        bool _7289;
                                        if (!_7270)
                                        {
                                            _7289 = abs(qm.z - p.z) >= ((1.60000002384185791015625f * abs(p.x - qm.x)) + 4.5f);
                                        }
                                        else
                                        {
                                            _7289 = _7270;
                                        }
                                        bool _7302;
                                        if (!_7289)
                                        {
                                            float3 param_147 = source.Load(int3(int2(mPx), 0)).xyz;
                                            _7302 = greenOf(param_147) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _7302 = _7289;
                                        }
                                        if (_7302)
                                        {
                                            lOk = false;
                                        }
                                    }
                                    if (rOk)
                                    {
                                        float2 mPx_1 = floor(clamp(pixel + float2(0.5f * st, 0.0f), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_148 = mPx_1;
                                        float4 qm_1 = positionAt(param_148);
                                        bool _7325 = qm_1.w >= 0.25f;
                                        bool _7344;
                                        if (!_7325)
                                        {
                                            _7344 = abs(qm_1.z - p.z) >= ((1.60000002384185791015625f * abs(qm_1.x - p.x)) + 4.5f);
                                        }
                                        else
                                        {
                                            _7344 = _7325;
                                        }
                                        bool _7357;
                                        if (!_7344)
                                        {
                                            float3 param_149 = source.Load(int3(int2(mPx_1), 0)).xyz;
                                            _7357 = greenOf(param_149) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _7357 = _7344;
                                        }
                                        if (_7357)
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
                            float2 param_150 = uPx;
                            float4 qu = positionAt(param_150);
                            float2 param_151 = dPx;
                            float4 qd = positionAt(param_151);
                            float dyu = abs(p.y - qu.y);
                            float dyd = abs(qd.y - p.y);
                            bool _7469 = (qu.w < 0.25f) && (dyu > 0.25f);
                            bool _7482;
                            if (_7469)
                            {
                                _7482 = abs(qu.z - p.z) < ((2.2000000476837158203125f * dyu) + 4.5f);
                            }
                            else
                            {
                                _7482 = _7469;
                            }
                            bool uOk = _7482;
                            bool _7489 = (qd.w < 0.25f) && (dyd > 0.25f);
                            bool _7502;
                            if (_7489)
                            {
                                _7502 = abs(qd.z - p.z) < ((2.2000000476837158203125f * dyd) + 4.5f);
                            }
                            else
                            {
                                _7502 = _7489;
                            }
                            bool dOk = _7502;
                            if (workGreen < 0.1500000059604644775390625f)
                            {
                                bool _7519;
                                if (uOk)
                                {
                                    float3 param_152 = source.Load(int3(int2(uPx), 0)).xyz;
                                    _7519 = greenOf(param_152) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _7519 = uOk;
                                }
                                if (_7519)
                                {
                                    uOk = false;
                                }
                                bool _7534;
                                if (dOk)
                                {
                                    float3 param_153 = source.Load(int3(int2(dPx), 0)).xyz;
                                    _7534 = greenOf(param_153) > 0.3499999940395355224609375f;
                                }
                                else
                                {
                                    _7534 = dOk;
                                }
                                if (_7534)
                                {
                                    dOk = false;
                                }
                                if (r == 0)
                                {
                                    if (uOk)
                                    {
                                        float2 mPx_2 = floor(clamp(pixel - float2(0.0f, 0.5f * st), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_154 = mPx_2;
                                        float4 qm_2 = positionAt(param_154);
                                        bool _7561 = qm_2.w >= 0.25f;
                                        bool _7580;
                                        if (!_7561)
                                        {
                                            _7580 = abs(qm_2.z - p.z) >= ((2.2000000476837158203125f * abs(p.y - qm_2.y)) + 4.5f);
                                        }
                                        else
                                        {
                                            _7580 = _7561;
                                        }
                                        bool _7593;
                                        if (!_7580)
                                        {
                                            float3 param_155 = source.Load(int3(int2(mPx_2), 0)).xyz;
                                            _7593 = greenOf(param_155) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _7593 = _7580;
                                        }
                                        if (_7593)
                                        {
                                            uOk = false;
                                        }
                                    }
                                    if (dOk)
                                    {
                                        float2 mPx_3 = floor(clamp(pixel + float2(0.0f, 0.5f * st), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                        float2 param_156 = mPx_3;
                                        float4 qm_3 = positionAt(param_156);
                                        bool _7616 = qm_3.w >= 0.25f;
                                        bool _7635;
                                        if (!_7616)
                                        {
                                            _7635 = abs(qm_3.z - p.z) >= ((2.2000000476837158203125f * abs(qm_3.y - p.y)) + 4.5f);
                                        }
                                        else
                                        {
                                            _7635 = _7616;
                                        }
                                        bool _7648;
                                        if (!_7635)
                                        {
                                            float3 param_157 = source.Load(int3(int2(mPx_3), 0)).xyz;
                                            _7648 = greenOf(param_157) > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _7648 = _7635;
                                        }
                                        if (_7648)
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
                    float2 param_158 = (lot * 0.180000007152557373046875f) + 4.30000019073486328125f.xx;
                    float2 param_159 = (lot * 0.4199999868869781494140625f) + 13.1000003814697265625f.xx;
                    float macroWind = (valueNoise(param_158) * 0.7400000095367431640625f) + (valueNoise(param_159) * 0.2599999904632568359375f);
                    float effDepth = max(0.0f, (amount * (1.0f - (0.319999992847442626953125f * covered))) + (((macroWind - 0.5f) * 0.0500000007450580596923828125f) * smoothstep(0.0f, 0.1599999964237213134765625f, amount)));
                    float lying = clamp(lerp(0.449999988079071044921875f * smoothstep(0.01200000010430812835693359375f, 0.2800000011920928955078125f, effDepth), 1.0f, smoothstep(0.20000000298023223876953125f, 0.680000007152557373046875f, effDepth)), 0.0f, 1.0f);
                    float _7801;
                    if (mapped)
                    {
                        float2 param_160 = pixel;
                        _7801 = groundAt(param_160);
                    }
                    else
                    {
                        _7801 = -100000.0f;
                    }
                    float baseAlt = _7801;
                    float _7813;
                    if (baseAlt > (-10000.0f))
                    {
                        float2 param_161 = centre.xy;
                        float param_162 = baseAlt / 27.7128124237060546875f;
                        bool param_163 = true;
                        float2 param_164 = ambient_frame.xy;
                        _7813 = lotPoint(param_161, param_162, param_163, param_164).z;
                    }
                    else
                    {
                        _7813 = 0.0f;
                    }
                    float groundFallback = _7813;
                    float _7833;
                    if (mapped)
                    {
                        float2 param_165 = here.xy;
                        float param_166 = groundFallback;
                        _7833 = terrainBaseAt(param_165, param_166);
                    }
                    else
                    {
                        _7833 = groundFallback;
                    }
                    float roofBase = _7833;
                    float _7847;
                    if (mapped)
                    {
                        _7847 = here.z - roofBase;
                    }
                    else
                    {
                        _7847 = 0.0f;
                    }
                    float relZ = _7847;
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
                            bool _8029 = length(pT - pixel) < (0.64999997615814208984375f * rP);
                            bool _8040;
                            if (!_8029)
                            {
                                _8040 = length(pL - pR) < (0.75f * wP);
                            }
                            else
                            {
                                _8040 = _8029;
                            }
                            if (_8040)
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
                            bool _8066 = qML.w < 0.25f;
                            bool _8077;
                            if (_8066)
                            {
                                _8077 = abs(qML.z - p0.z) < 75.0f;
                            }
                            else
                            {
                                _8077 = _8066;
                            }
                            bool _8083;
                            if (_8077)
                            {
                                _8083 = qMR.w < 0.25f;
                            }
                            else
                            {
                                _8083 = _8077;
                            }
                            bool _8093;
                            if (_8083)
                            {
                                _8093 = abs(qMR.z - p0.z) < 75.0f;
                            }
                            else
                            {
                                _8093 = _8083;
                            }
                            bool _8099;
                            if (_8093)
                            {
                                _8099 = qT.w < 0.25f;
                            }
                            else
                            {
                                _8099 = _8093;
                            }
                            bool _8110;
                            if (_8099)
                            {
                                _8110 = abs(qT.z - p0.z) < 130.0f;
                            }
                            else
                            {
                                _8110 = _8099;
                            }
                            bool _8116;
                            if (_8110)
                            {
                                _8116 = qL.w < 0.25f;
                            }
                            else
                            {
                                _8116 = _8110;
                            }
                            bool _8126;
                            if (_8116)
                            {
                                _8126 = abs(qL.z - p0.z) < 130.0f;
                            }
                            else
                            {
                                _8126 = _8116;
                            }
                            bool _8132;
                            if (_8126)
                            {
                                _8132 = qR.w < 0.25f;
                            }
                            else
                            {
                                _8132 = _8126;
                            }
                            bool _8142;
                            if (_8132)
                            {
                                _8142 = abs(qR.z - p0.z) < 130.0f;
                            }
                            else
                            {
                                _8142 = _8132;
                            }
                            bool _8153;
                            if (_8142)
                            {
                                _8153 = abs(qL.z - qR.z) < 45.0f;
                            }
                            else
                            {
                                _8153 = _8142;
                            }
                            if (_8153)
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
                                    bool _8192 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.939999997615814208984375f);
                                    bool _8198;
                                    if (_8192)
                                    {
                                        _8198 = nW.z > 0.02500000037252902984619140625f;
                                    }
                                    else
                                    {
                                        _8198 = _8192;
                                    }
                                    bool _8205;
                                    if (_8198)
                                    {
                                        _8205 = abs(nW.x) > 0.119999997317790985107421875f;
                                    }
                                    else
                                    {
                                        _8205 = _8198;
                                    }
                                    if (_8205)
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
                                float2 param_172 = pB;
                                float4 qB = positionAt(param_172);
                                bool _8330 = qB.w >= 0.25f;
                                bool _8342;
                                if (!_8330)
                                {
                                    _8342 = abs(qB.z - p0.z) >= 60.0f;
                                }
                                else
                                {
                                    _8342 = _8330;
                                }
                                if (_8342)
                                {
                                    continue;
                                }
                                float2 pML_1 = clamp(floor((pB + (dir_1 * (0.5f * rP))) + (perp_1 * (0.5f * wP))) + 0.5f.xx, 0.5f.xx, maxPx);
                                float2 pMR_1 = clamp(floor((pB + (dir_1 * (0.5f * rP))) - (perp_1 * (0.5f * wP))) + 0.5f.xx, 0.5f.xx, maxPx);
                                float2 pT_1 = clamp(floor(pB + (dir_1 * rP)) + 0.5f.xx, 0.5f.xx, maxPx);
                                float2 pL_1 = clamp(floor((pB + (dir_1 * rP)) + (perp_1 * wP)) + 0.5f.xx, 0.5f.xx, maxPx);
                                float2 pR_1 = clamp(floor((pB + (dir_1 * rP)) - (perp_1 * wP)) + 0.5f.xx, 0.5f.xx, maxPx);
                                bool _8427 = length(pT_1 - pB) < (0.64999997615814208984375f * rP);
                                bool _8438;
                                if (!_8427)
                                {
                                    _8438 = length(pL_1 - pR_1) < (0.75f * wP);
                                }
                                else
                                {
                                    _8438 = _8427;
                                }
                                if (_8438)
                                {
                                    continue;
                                }
                                float2 param_173 = pML_1;
                                float4 qML_1 = positionAt(param_173);
                                float2 param_174 = pMR_1;
                                float4 qMR_1 = positionAt(param_174);
                                float2 param_175 = pT_1;
                                float4 qT_1 = positionAt(param_175);
                                float2 param_176 = pL_1;
                                float4 qL_1 = positionAt(param_176);
                                float2 param_177 = pR_1;
                                float4 qR_1 = positionAt(param_177);
                                bool _8464 = qML_1.w < 0.25f;
                                bool _8474;
                                if (_8464)
                                {
                                    _8474 = abs(qML_1.z - qB.z) < 75.0f;
                                }
                                else
                                {
                                    _8474 = _8464;
                                }
                                bool _8480;
                                if (_8474)
                                {
                                    _8480 = qMR_1.w < 0.25f;
                                }
                                else
                                {
                                    _8480 = _8474;
                                }
                                bool _8490;
                                if (_8480)
                                {
                                    _8490 = abs(qMR_1.z - qB.z) < 75.0f;
                                }
                                else
                                {
                                    _8490 = _8480;
                                }
                                bool _8496;
                                if (_8490)
                                {
                                    _8496 = qT_1.w < 0.25f;
                                }
                                else
                                {
                                    _8496 = _8490;
                                }
                                bool _8506;
                                if (_8496)
                                {
                                    _8506 = abs(qT_1.z - qB.z) < 130.0f;
                                }
                                else
                                {
                                    _8506 = _8496;
                                }
                                bool _8512;
                                if (_8506)
                                {
                                    _8512 = qL_1.w < 0.25f;
                                }
                                else
                                {
                                    _8512 = _8506;
                                }
                                bool _8522;
                                if (_8512)
                                {
                                    _8522 = abs(qL_1.z - qB.z) < 130.0f;
                                }
                                else
                                {
                                    _8522 = _8512;
                                }
                                bool _8528;
                                if (_8522)
                                {
                                    _8528 = qR_1.w < 0.25f;
                                }
                                else
                                {
                                    _8528 = _8522;
                                }
                                bool _8538;
                                if (_8528)
                                {
                                    _8538 = abs(qR_1.z - qB.z) < 130.0f;
                                }
                                else
                                {
                                    _8538 = _8528;
                                }
                                bool _8548;
                                if (_8538)
                                {
                                    _8548 = abs(qL_1.z - qR_1.z) < 45.0f;
                                }
                                else
                                {
                                    _8548 = _8538;
                                }
                                if (_8548)
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
                                        bool _8589 = (wFacing_1 > 0.319999992847442626953125f) && (wFacing_1 < 0.939999997615814208984375f);
                                        bool _8595;
                                        if (_8589)
                                        {
                                            _8595 = nW_1.z > 0.02500000037252902984619140625f;
                                        }
                                        else
                                        {
                                            _8595 = _8589;
                                        }
                                        bool _8602;
                                        if (_8595)
                                        {
                                            _8602 = abs(nW_1.x) > 0.119999997317790985107421875f;
                                        }
                                        else
                                        {
                                            _8602 = _8595;
                                        }
                                        if (_8602)
                                        {
                                            float errML_1 = abs(dot(qML_1.xyz - qB.xyz, nW_1));
                                            float errMR_1 = abs(dot(qMR_1.xyz - qB.xyz, nW_1));
                                            float errT_1 = abs(dot(qT_1.xyz - qB.xyz, nW_1));
                                            float err0 = abs(dot(p0 - qB.xyz, nW_1));
                                            bool _8650 = ((errML_1 < planeTol) && (errMR_1 < planeTol)) && (errT_1 < planeTol);
                                            bool _8657;
                                            if (_8650)
                                            {
                                                _8657 = err0 < (planeTol * 2.2000000476837158203125f);
                                            }
                                            else
                                            {
                                                _8657 = _8650;
                                            }
                                            if (_8657)
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
                                bool _8759 = any(bool2(pML_2.x < 0.5f.xx.x, pML_2.y < 0.5f.xx.y));
                                bool _8767;
                                if (!_8759)
                                {
                                    _8767 = any(bool2(pML_2.x > maxPx.x, pML_2.y > maxPx.y));
                                }
                                else
                                {
                                    _8767 = _8759;
                                }
                                bool _8774;
                                if (!_8767)
                                {
                                    _8774 = any(bool2(pMR_2.x < 0.5f.xx.x, pMR_2.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _8774 = _8767;
                                }
                                bool _8782;
                                if (!_8774)
                                {
                                    _8782 = any(bool2(pMR_2.x > maxPx.x, pMR_2.y > maxPx.y));
                                }
                                else
                                {
                                    _8782 = _8774;
                                }
                                bool _8789;
                                if (!_8782)
                                {
                                    _8789 = any(bool2(pT_2.x < 0.5f.xx.x, pT_2.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _8789 = _8782;
                                }
                                bool _8797;
                                if (!_8789)
                                {
                                    _8797 = any(bool2(pT_2.x > maxPx.x, pT_2.y > maxPx.y));
                                }
                                else
                                {
                                    _8797 = _8789;
                                }
                                bool _8804;
                                if (!_8797)
                                {
                                    _8804 = any(bool2(pL_2.x < 0.5f.xx.x, pL_2.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _8804 = _8797;
                                }
                                bool _8812;
                                if (!_8804)
                                {
                                    _8812 = any(bool2(pL_2.x > maxPx.x, pL_2.y > maxPx.y));
                                }
                                else
                                {
                                    _8812 = _8804;
                                }
                                bool _8819;
                                if (!_8812)
                                {
                                    _8819 = any(bool2(pR_2.x < 0.5f.xx.x, pR_2.y < 0.5f.xx.y));
                                }
                                else
                                {
                                    _8819 = _8812;
                                }
                                bool _8827;
                                if (!_8819)
                                {
                                    _8827 = any(bool2(pR_2.x > maxPx.x, pR_2.y > maxPx.y));
                                }
                                else
                                {
                                    _8827 = _8819;
                                }
                                if (_8827)
                                {
                                    continue;
                                }
                                float2 param_178 = pML_2;
                                float4 qML_2 = positionAt(param_178);
                                float2 param_179 = pMR_2;
                                float4 qMR_2 = positionAt(param_179);
                                float2 param_180 = pT_2;
                                float4 qT_2 = positionAt(param_180);
                                float2 param_181 = pL_2;
                                float4 qL_2 = positionAt(param_181);
                                float2 param_182 = pR_2;
                                float4 qR_2 = positionAt(param_182);
                                bool _8853 = qML_2.w < 0.25f;
                                bool _8864;
                                if (_8853)
                                {
                                    _8864 = abs(qML_2.z - p0.z) < 28.0f;
                                }
                                else
                                {
                                    _8864 = _8853;
                                }
                                bool _8870;
                                if (_8864)
                                {
                                    _8870 = qMR_2.w < 0.25f;
                                }
                                else
                                {
                                    _8870 = _8864;
                                }
                                bool _8880;
                                if (_8870)
                                {
                                    _8880 = abs(qMR_2.z - p0.z) < 28.0f;
                                }
                                else
                                {
                                    _8880 = _8870;
                                }
                                bool _8886;
                                if (_8880)
                                {
                                    _8886 = qT_2.w < 0.25f;
                                }
                                else
                                {
                                    _8886 = _8880;
                                }
                                bool _8897;
                                if (_8886)
                                {
                                    _8897 = abs(qT_2.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _8897 = _8886;
                                }
                                bool _8903;
                                if (_8897)
                                {
                                    _8903 = qL_2.w < 0.25f;
                                }
                                else
                                {
                                    _8903 = _8897;
                                }
                                bool _8913;
                                if (_8903)
                                {
                                    _8913 = abs(qL_2.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _8913 = _8903;
                                }
                                bool _8919;
                                if (_8913)
                                {
                                    _8919 = qR_2.w < 0.25f;
                                }
                                else
                                {
                                    _8919 = _8913;
                                }
                                bool _8929;
                                if (_8919)
                                {
                                    _8929 = abs(qR_2.z - p0.z) < 48.0f;
                                }
                                else
                                {
                                    _8929 = _8919;
                                }
                                bool _8940;
                                if (_8929)
                                {
                                    _8940 = abs(qL_2.z - qR_2.z) < 20.0f;
                                }
                                else
                                {
                                    _8940 = _8929;
                                }
                                if (_8940)
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
                                        bool _8976 = wFacing_2 >= 0.920000016689300537109375f;
                                        bool _8982;
                                        if (_8976)
                                        {
                                            _8982 = nW_2.z > 0.3499999940395355224609375f;
                                        }
                                        else
                                        {
                                            _8982 = _8976;
                                        }
                                        if (_8982)
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
                    bool _9049 = ((!ground) && mapped) && (!onRoof);
                    bool _9055;
                    if (_9049)
                    {
                        _9055 = abs(relZ) < 0.2199999988079071044921875f;
                    }
                    else
                    {
                        _9055 = _9049;
                    }
                    float _9059;
                    if (_9055 && (facing > 0.819999992847442626953125f))
                    {
                        _9059 = (smoothstep(0.14000000059604644775390625f, 0.2599999904632568359375f, workSrc.z) * smoothstep(1.5499999523162841796875f, 2.150000095367431640625f, workSrc.z / max(workSrc.x, 0.014999999664723873138427734375f))) * smoothstep(1.25f, 1.75f, workSrc.y / max(workSrc.x, 0.014999999664723873138427734375f));
                    }
                    else
                    {
                        _9059 = 0.0f;
                    }
                    poolWater = _9059;
                    float settle = 1.0f;
                    float organic = 0.0f;
                    float pillowField = 0.0f;
                    float3 param_183 = workSrc;
                    float isFoliage = foliageOf(param_183);
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
                            float eaveBase = (relZ > 5.457499980926513671875f) ? 5.900000095367431640625f : 2.9500000476837158203125f;
                            float upSlope = clamp((relZ - eaveBase) / 2.5074999332427978515625f, 0.0f, 1.0f);
                            float2 param_184 = float2(dot(lot, float2(0.92847669124603271484375f, 0.37139070034027099609375f)) * 0.0900000035762786865234375f, dot(lot, float2(-0.37139070034027099609375f, 0.92847669124603271484375f)) * 0.23999999463558197021484375f) + float2(6.30000019073486328125f, 2.900000095367431640625f);
                            float roofRibbon = valueNoise(param_184);
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
                            float3 param_185 = workSrc;
                            float selfFol = foliageOf(param_185);
                            bool _9208 = (selfFol < 0.1500000059604644775390625f) && (workLum > 0.07999999821186065673828125f);
                            bool _9214;
                            if (_9208)
                            {
                                _9214 = workSrc.z > 0.07999999821186065673828125f;
                            }
                            else
                            {
                                _9214 = _9208;
                            }
                            bool _9223;
                            if (_9214)
                            {
                                _9223 = workSrc.z > (0.680000007152557373046875f * workSrc.y);
                            }
                            else
                            {
                                _9223 = _9214;
                            }
                            bool blossomCand = _9223;
                            bool _9229 = (selfFol < 0.1500000059604644775390625f) && (workLum < 0.02500000037252902984619140625f);
                            bool _9241;
                            if (_9229)
                            {
                                _9241 = workSrc.y > (1.2000000476837158203125f * max(workSrc.x, workSrc.z));
                            }
                            else
                            {
                                _9241 = _9229;
                            }
                            bool darkCreviceCand = _9241;
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
                            float _9444;
                            float4 tapData[14];
                            for (int i_4 = 0; i_4 < 14; i_4++)
                            {
                                float2 qPx = floor(clamp(pixel + (_9296[i_4].xy * sc), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                float2 param_186 = qPx;
                                float4 q = positionAt(param_186);
                                if (q.w < 0.25f)
                                {
                                    float2 dxy = q.xy - p_1.xy;
                                    float dist = length(dxy);
                                    float3 qCol = source.Load(int3(int2(qPx), 0)).xyz;
                                    float3 param_187 = qCol;
                                    float qFol = foliageOf(param_187);
                                    float qBlos = smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, qCol.z) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, qCol.z / max(qCol.y, 0.0199999995529651641845703125f));
                                    float qPlant = max(qFol, 0.60000002384185791015625f * qBlos);
                                    float fw = _9296[i_4].z * (1.0f - smoothstep(12.0f, 22.0f, abs(q.z - p_1.z)));
                                    rawFolNbr += (qFol * fw);
                                    rawFolW += fw;
                                    if (i_4 < 4)
                                    {
                                        float tw = _9296[i_4].z * (1.0f - smoothstep(10.0f, 18.0f, abs(q.z - p_1.z)));
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
                                                _9444 = 0.0f;
                                            }
                                            else
                                            {
                                                _9444 = 1.0f - smoothstep((1.7999999523162841796875f * dist) + 3.0f, (2.2000000476837158203125f * dist) + 6.0f, abs(q.z - p_1.z));
                                            }
                                            dw = _9444;
                                            if (dw > 9.9999997473787516355514526367188e-05f)
                                            {
                                                float2 mPx_4 = floor(clamp((pixel + qPx) * 0.5f, 0.0f.xx, maxIdx)) + 0.5f.xx;
                                                float2 param_188 = mPx_4;
                                                float4 qm_4 = positionAt(param_188);
                                                bool _9483 = qm_4.w >= 0.25f;
                                                bool _9502;
                                                if (!_9483)
                                                {
                                                    _9502 = abs(qm_4.z - (0.5f * (p_1.z + q.z))) >= ((1.7999999523162841796875f * (0.5f * dist)) + 5.0f);
                                                }
                                                else
                                                {
                                                    _9502 = _9483;
                                                }
                                                bool _9515;
                                                if (!_9502)
                                                {
                                                    float3 param_189 = source.Load(int3(int2(mPx_4), 0)).xyz;
                                                    _9515 = foliageOf(param_189) > 0.3499999940395355224609375f;
                                                }
                                                else
                                                {
                                                    _9515 = _9502;
                                                }
                                                if (_9515)
                                                {
                                                    dw = 0.0f;
                                                }
                                            }
                                        }
                                    }
                                    float wt = _9296[i_4].z * dw;
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
                                float _9797;
                                if (errW > 9.9999997473787516355514526367188e-05f)
                                {
                                    _9797 = errSum / errW;
                                }
                                else
                                {
                                    _9797 = 0.0f;
                                }
                                planeErr = _9797;
                            }
                            float topClear = 0.0f;
                            float overhang = 0.0f;
                            for (int i_7 = 0; i_7 < 9; i_7++)
                            {
                                float2 qPx_1 = floor(clamp(pixel + (_9832[i_7].xy * sc), 0.0f.xx, maxIdx)) + 0.5f.xx;
                                float2 param_190 = qPx_1;
                                float4 q_1 = positionAt(param_190);
                                float distY = max(p_1.y - q_1.y, 1.0f);
                                float openW = max(step(0.25f, q_1.w), smoothstep(18.0f, 36.0f, zSmooth - q_1.z));
                                float slopeOpen = smoothstep(-0.2199999988079071044921875f, 0.519999980926513671875f, (zSmooth - q_1.z) / distY);
                                float overT = (1.0f - openW) * smoothstep(0.1599999964237213134765625f, 0.85000002384185791015625f, (q_1.z - zSmooth) / distY);
                                float wt_3 = _9832[i_7].z;
                                topClear += ((openW + ((1.0f - openW) * slopeOpen)) * wt_3);
                                overhang += (overT * wt_3);
                            }
                            float greenLocal = greenNbr / max(greenW, 9.9999997473787516355514526367188e-05f);
                            float _9918;
                            if (tightW > 9.9999997473787516355514526367188e-05f)
                            {
                                _9918 = tightGreen / tightW;
                            }
                            else
                            {
                                _9918 = 0.0f;
                            }
                            float tg = _9918;
                            float selfFoliage = smoothstep(0.07999999821186065673828125f, 0.2800000011920928955078125f, selfFol);
                            float blossom = ((smoothstep(0.07999999821186065673828125f, 0.180000007152557373046875f, workLum) * smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, workSrc.z)) * smoothstep(0.680000007152557373046875f, 0.920000016689300537109375f, workSrc.z / max(workSrc.y, 0.0199999995529651641845703125f))) * smoothstep(0.5f, 0.800000011920928955078125f, tg);
                            float _9949;
                            if (darkCreviceCand)
                            {
                                _9949 = smoothstep(0.579999983310699462890625f, 0.819999992847442626953125f, tg) * smoothstep(2.599999904632568359375f, 3.599999904632568359375f, tightW);
                            }
                            else
                            {
                                _9949 = 0.0f;
                            }
                            float darkCrevice = _9949;
                            isFoliage = max(selfFoliage, max(blossom, darkCrevice));
                            organic = (isFoliage * smoothstep(0.23999999463558197021484375f, 0.4799999892711639404296875f, greenLocal)) * smoothstep(0.949999988079071044921875f, 1.85000002384185791015625f, planeErr);
                            float _9976;
                            if (det > 64.0f)
                            {
                                _9976 = smoothstep(1.14999997615814208984375f, 0.4000000059604644775390625f, planeErr);
                            }
                            else
                            {
                                _9976 = 0.0f;
                            }
                            float planarFactor = _9976;
                            float solidSupport = smoothstep(2.599999904632568359375f, 5.19999980926513671875f, wSum) * smoothstep(48.0f, 128.0f, det);
                            float nearFolFrac = rawFolNbr / max(rawFolW, 9.9999997473787516355514526367188e-05f);
                            float notBushRim = lerp(1.0f, 1.0f - (smoothstep(0.14000000059604644775390625f, 0.36000001430511474609375f, nearFolFrac) * (1.0f - isFoliage)), smoothstep(0.0500000007450580596923828125f, 0.180000007152557373046875f, relZ));
                            float solidFacing = max(facing, facMacro * planarFactor);
                            float settleSolid = ((smoothstep(0.60000002384185791015625f, 0.86000001430511474609375f, solidFacing) * solidSupport) * notBushRim) * (1.0f - smoothstep(0.2800000011920928955078125f, 0.550000011920928955078125f, overhang));
                            float2 param_191 = centre.xy;
                            float param_192 = zSmooth / 27.7128124237060546875f;
                            bool param_193 = false;
                            float2 param_194 = ambient_frame.xy;
                            float3 hereSm = lotPoint(param_191, param_192, param_193, param_194);
                            float2 param_195 = hereSm.xy;
                            float2 lotSm = lotSource(param_195);
                            float edgeSupport = smoothstep(1.60000002384185791015625f, 5.19999980926513671875f, folW);
                            float leafSoft = smoothstep(0.014999999664723873138427734375f, 0.12999999523162841796875f, workLum);
                            float2 param_196 = (lotSm * 1.39999997615814208984375f) + float2(hereSm.z * 1.10000002384185791015625f, (-hereSm.z) * 0.89999997615814208984375f);
                            float pillowNoise = valueNoise(param_196);
                            float dome = (facMacro * 0.4600000083446502685546875f) + (topClear * 0.540000021457672119140625f);
                            pillowField = ((dome * (1.0f - smoothstep(0.20000000298023223876953125f, 0.579999983310699462890625f, overhang))) + ((pillowNoise - 0.5f) * 0.07999999821186065673828125f)) + ((leafSoft - 0.449999988079071044921875f) * 0.0500000007450580596923828125f);
                            float folAmt = max(0.0f, amount * (1.0f - (0.300000011920928955078125f * covered)));
                            float snowGrow = clamp(folAmt / 1.14999997615814208984375f, 0.0f, 1.0f);
                            float settleFoliage = smoothstep(0.540000021457672119140625f - (0.180000007152557373046875f * snowGrow), 0.86000001430511474609375f - (0.100000001490116119384765625f * snowGrow), pillowField) * edgeSupport;
                            settle = lerp(settleSolid, settleFoliage, organic) * (1.0f - poolWater);
                            if (organic > 0.00999999977648258209228515625f)
                            {
                                capLot = lerp(lot, lotSm, organic.xx);
                                float2 param_197 = capLot;
                                capCrust = snowCrust(param_197);
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
                        float z0 = roofBase + 0.100000001490116119384765625f;
                        float z1 = (roofBase + 2.9500000476837158203125f) + 0.100000001490116119384765625f;
                        float wallR = (isFoliage > 0.25f) ? 0.10999999940395355224609375f : 0.4799999892711639404296875f;
                        float2 param_198 = here.xy;
                        float param_199 = z0;
                        float param_200 = wallR;
                        float2 param_201 = here.xy;
                        float param_202 = z1;
                        float param_203 = wallR;
                        float2 param_204 = here.xy;
                        float param_205 = here.z;
                        float param_206 = wallR;
                        wallBlock = max(nearIndoorWall(param_198, param_199, param_200), max(nearIndoorWall(param_201, param_202, param_203), nearIndoorWall(param_204, param_205, param_206)));
                        if ((isFoliage < 0.25f) && (relZ > 2.7999999523162841796875f))
                        {
                            float2 wallXY1 = here.xy - (1.25f * max(0.0f, relZ - 2.9500000476837158203125f)).xx;
                            float2 wallXY2 = here.xy - (1.25f * max(0.0f, relZ - 5.900000095367431640625f)).xx;
                            float3 param_207 = float3(wallXY1, z0);
                            float2 param_208 = wallXY1;
                            float param_209 = z0;
                            float param_210 = 0.519999980926513671875f;
                            wallBlock = max(wallBlock, max(indoors(param_207), nearIndoorWall(param_208, param_209, param_210)));
                            float3 param_211 = float3(wallXY2, z1);
                            float2 param_212 = wallXY2;
                            float param_213 = z1;
                            float param_214 = 0.519999980926513671875f;
                            wallBlock = max(wallBlock, max(indoors(param_211), nearIndoorWall(param_212, param_213, param_214)));
                        }
                    }
                    settle *= (1.0f - smoothstep(0.0199999995529651641845703125f, 0.25f, wallBlock));
                    float2 param_215 = (capLot * 0.2599999904632568359375f) + 9.0f.xx;
                    float swell = valueNoise(param_215);
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
                    float2 param_216 = capLot * 24.0f;
                    float2 param_217 = (capLot * 41.0f) + 31.700000762939453125f.xx;
                    float glint = smoothstep(0.680000007152557373046875f, 0.939999997615814208984375f, valueNoise(param_216) * valueNoise(param_217)) * daySun;
                    snow += ((float3(0.0199999995529651641845703125f, 0.0240000002086162567138671875f, 0.034000001847743988037109375f) * glint) * winterOutdoor);
                    float _10344;
                    if (onRoof)
                    {
                        _10344 = lerp(0.87999999523162841796875f, 0.939999997615814208984375f, smoothstep(0.5f, 1.0499999523162841796875f, amount));
                    }
                    else
                    {
                        _10344 = lerp(0.86000001430511474609375f, 0.920000016689300537109375f, organic);
                    }
                    float capAlpha = _10344;
                    float _10356;
                    if (ground)
                    {
                        _10356 = capLying * winterOutdoor;
                    }
                    else
                    {
                        _10356 = clamp(((capLying * settle) * winterOutdoor) * capAlpha, 0.0f, 1.0f);
                    }
                    float cover = _10356;
                    float3 param_218 = dull;
                    float3 param_219 = snow;
                    float param_220 = cover;
                    result = mixPerceptual(param_218, param_219, param_220);
                    if (poolWater > 0.00999999977648258209228515625f)
                    {
                        float coolT = smoothstep(0.0f, 0.4000000059604644775390625f, amount) * winterOutdoor;
                        float3 param_221 = workSrc;
                        float3 param_222 = float3(0.20000000298023223876953125f, 0.37999999523162841796875f, 0.540000021457672119140625f);
                        float3 coldPool = lerp(workSrc, recolor(param_221, param_222), (0.3400000035762786865234375f * coolT).xxx);
                        float2 param_223 = here.xy;
                        float param_224 = roofBase;
                        float rimBank = wallBank(param_223, param_224);
                        float iceFreeze = smoothstep(0.319999992847442626953125f - (0.100000001490116119384765625f * rimBank), 1.0499999523162841796875f - (0.1500000059604644775390625f * rimBank), amount * (1.0f - (0.25f * covered))) * winterOutdoor;
                        float3 iceCol = lerp(float3(0.4600000083446502685546875f, 0.550000011920928955078125f, 0.7200000286102294921875f), float3(0.7599999904632568359375f, 0.829999983310699462890625f, 0.939999997615814208984375f), (0.550000011920928955078125f + (0.25f * capCrust)).xxx) * clamp(0.7200000286102294921875f + (0.550000011920928955078125f * workLum), 0.680000007152557373046875f, 1.0499999523162841796875f);
                        float3 icedPool = lerp(coldPool, iceCol, (iceFreeze * (0.4199999868869781494140625f + (0.2599999904632568359375f * rimBank))).xxx);
                        result = lerp(result, icedPool, poolWater.xxx);
                    }
                    if ((!ground) && hasPartialSprite)
                    {
                        float3 B_win = spriteB;
                        bool _10465;
                        if (mapped)
                        {
                            _10465 = groundMap.Load(int3(int2(pixel), 0)).x < 1.0f;
                        }
                        else
                        {
                            _10465 = mapped;
                        }
                        bool _10486;
                        if (_10465)
                        {
                            float3 param_225 = spriteB;
                            bool _10471 = greenOf(param_225) > 0.0500000007450580596923828125f;
                            bool _10485;
                            if (!_10471)
                            {
                                bool _10476 = vacLot > 0.5f;
                                bool _10484;
                                if (_10476)
                                {
                                    _10484 = spriteB.z > spriteB.x;
                                }
                                else
                                {
                                    _10484 = _10476;
                                }
                                _10485 = _10484;
                            }
                            else
                            {
                                _10485 = _10471;
                            }
                            _10486 = _10485;
                        }
                        else
                        {
                            _10486 = _10465;
                        }
                        if (_10486)
                        {
                            float gKey_1 = ((0.89999997615814208984375f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
                            float2 param_226 = centre.xy;
                            float param_227 = gKey_1;
                            bool param_228 = true;
                            float2 param_229 = ambient_frame.xy;
                            float3 hereG_1 = lotPoint(param_226, param_227, param_228, param_229);
                            float3 param_230 = hereG_1;
                            float3 param_231 = hereG_1;
                            float gWinOut = min(1.0f - indoors(param_230), architecturalExposure(param_231));
                            if (gWinOut > 0.0f)
                            {
                                float2 param_232 = hereG_1.xy;
                                float2 gLot_1 = lotSource(param_232);
                                float2 param_233 = hereG_1.xy;
                                float gOver = smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, topAt(param_233) - hereG_1.z);
                                float3 param_234 = spriteB;
                                float2 param_235 = hereG_1.xy;
                                float param_236 = 1.0f;
                                float param_237 = vacLot;
                                float param_238;
                                float param_239;
                                float param_240;
                                float param_241;
                                float param_242;
                                evalGroundTerms(param_234, param_235, param_236, param_237, param_238, param_239, param_240, param_241, param_242);
                                float gVacSnow = param_238;
                                float gEarth = param_239;
                                float gWear = param_240;
                                float gGrn = param_241;
                                float gLum = param_242;
                                float2 param_243 = gLot_1;
                                float3 param_244 = spriteB;
                                float2 param_245 = hereG_1.xy;
                                float2 param_246 = gLot_1;
                                float param_247 = gLum;
                                float param_248 = gGrn;
                                float param_249 = snowCrust(param_243);
                                float param_250 = gEarth;
                                float param_251 = gWear;
                                float param_252 = gVacSnow;
                                float param_253 = gOver;
                                bool param_254 = true;
                                float param_255 = amount;
                                float3 gDull = winterDullColor(param_244, param_245, param_246, param_247, param_248, param_249, param_250, param_251, param_252, param_253, param_254, param_255);
                                float3 param_256 = spriteB;
                                float3 param_257 = gDull;
                                float param_258 = gLum;
                                float3 param_259 = hereG_1;
                                float param_260 = hereG_1.z;
                                float param_261 = 0.0f;
                                float param_262 = amount;
                                float param_263 = deep;
                                float param_264 = gEarth;
                                float param_265 = gWear;
                                float param_266 = gVacSnow;
                                bool param_267 = true;
                                float param_268;
                                float param_269;
                                float param_270;
                                float3 _10622 = marchSnowDrift(param_256, param_257, param_258, param_259, param_260, param_261, param_262, param_263, param_264, param_265, param_266, param_267, param_268, param_269, param_270);
                                float gEdge = param_268;
                                float gHitT = param_269;
                                float gHitS = param_270;
                                float3 gMarch = _10622;
                                B_win = lerp(spriteB, gMarch, gWinOut.xxx);
                            }
                        }
                        result = (result * sp_1.w) + (B_win * (1.0f - sp_1.w));
                    }
                    if (!ground)
                    {
                        float _10650;
                        if (mapped && (baseAlt > (-10000.0f)))
                        {
                            _10650 = groundFallback;
                        }
                        else
                        {
                            _10650 = here.z;
                        }
                        float baseG = _10650;
                        float _10663;
                        if (mapped && (baseAlt > (-10000.0f)))
                        {
                            _10663 = max(0.0f, here.z - baseG);
                        }
                        else
                        {
                            _10663 = 1.0f;
                        }
                        float h0Cap = _10663;
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
                    float2 param_271 = pixel;
                    float terrain = groundAt(param_271);
                    float _10707;
                    if (ground)
                    {
                        _10707 = here.z;
                    }
                    else
                    {
                        float _10715;
                        if (terrain > (-10000.0f))
                        {
                            float2 param_272 = centre.xy;
                            float param_273 = terrain / 27.7128124237060546875f;
                            bool param_274 = true;
                            float2 param_275 = ambient_frame.xy;
                            _10715 = lotPoint(param_272, param_273, param_274, param_275).z;
                        }
                        else
                        {
                            _10715 = here.z;
                        }
                        _10707 = _10715;
                    }
                    float base = _10707;
                    float _10738;
                    if (ground)
                    {
                        _10738 = 0.0f;
                    }
                    else
                    {
                        _10738 = max(0.0f, here.z - base);
                    }
                    float h0 = _10738;
                    float3 param_276 = workSrc;
                    float3 param_277 = result;
                    float param_278 = workLum;
                    float3 param_279 = here;
                    float param_280 = base;
                    float param_281 = h0;
                    float param_282 = amount;
                    float param_283 = deep;
                    float param_284 = earthMask;
                    float param_285 = terrainWear;
                    float param_286 = isVacSnowLot;
                    bool param_287 = ground;
                    float param_288;
                    float param_289;
                    float param_290;
                    float3 _10778 = marchSnowDrift(param_276, param_277, param_278, param_279, param_280, param_281, param_282, param_283, param_284, param_285, param_286, param_287, param_288, param_289, param_290);
                    float mEdge = param_288;
                    float mHitT = param_289;
                    float mHitS = param_290;
                    result = _10778;
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
                float3 _10821 = abs(result - src);
                if (all(bool3(_10821.x < 9.9999997473787516355514526367188e-05f.xxx.x, _10821.y < 9.9999997473787516355514526367188e-05f.xxx.y, _10821.z < 9.9999997473787516355514526367188e-05f.xxx.z)))
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
