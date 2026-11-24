static const float2 _784[5] = { float2(-0.89442718029022216796875f, -0.447213590145111083984375f), float2(0.89442718029022216796875f, -0.447213590145111083984375f), (-0.7071068286895751953125f).xx, float2(0.7071068286895751953125f, -0.7071068286895751953125f), float2(0.0f, -1.0f) };
static const float2 _1199[2] = { (-0.7071068286895751953125f).xx, float2(0.7071068286895751953125f, -0.7071068286895751953125f) };

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

Texture2D<float4> overheadMap : register(t3, space2);
SamplerState _overheadMap_sampler : register(s3, space2);
Texture2D<float4> depthMap : register(t1, space2);
SamplerState _depthMap_sampler : register(s1, space2);
Texture2D<float4> groundMap : register(t2, space2);
SamplerState _groundMap_sampler : register(s2, space2);
Texture2D<float4> trailMap : register(t4, space2);
SamplerState _trailMap_sampler : register(s4, space2);
Texture2D<float4> ambientMap : register(t0, space2);
SamplerState _ambientMap_sampler : register(s0, space2);

static float4 gl_FragCoord;
static float4 color;

struct SPIRV_Cross_Input
{
    float4 gl_FragCoord : SV_Position;
};

struct SPIRV_Cross_Output
{
    float4 color : SV_Target0;
};

uint2 spvTextureSize(Texture2D<float4> Tex, uint Level, out uint Param)
{
    uint2 ret;
    Tex.GetDimensions(Level, ret.x, ret.y, Param);
    return ret;
}

float4 atmosPosAt(float2 px)
{
    float2 cpx = clamp(px, 0.5f.xx, ambient_extent.xy - 0.5f.xx);
    float2 sc = (cpx - ambient_view.xy) / max(ambient_view.z, 0.25f).xx;
    float d = depthMap.Load(int3(int2(cpx), 0)).x;
    if (d < 1.0f)
    {
        return float4(sc, (0.89999997615814208984375f - d) / 0.0030000000260770320892333984375f, 0.0f);
    }
    float g = groundMap.Load(int3(int2(cpx), 0)).x;
    if (g < 1.0f)
    {
        return float4(sc, ((0.89999997615814208984375f - g) / 0.0030000000260770320892333984375f) + ambient_view.w, 0.5f);
    }
    return float4(sc, -100000.0f, 1.0f);
}

float hash12(float2 q)
{
    float3 r = frac(q.xyx * 0.103100001811981201171875f);
    r += dot(r, r.yzx + 33.3300018310546875f.xxx).xxx;
    return frac((r.x + r.y) * r.z);
}

float3 lotPoint(float2 scene, float key, bool terrain, float2 frame)
{
    float2 local = scene - frame;
    float _111;
    if (terrain)
    {
        _111 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _111 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _111;
    float _135;
    if (terrain)
    {
        _135 = key;
    }
    else
    {
        _135 = key - (0.800000011920928955078125f * h);
    }
    float s = _135;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

float atmosMeshKey(float4 pos)
{
    if (pos.w < 0.25f)
    {
        return pos.z;
    }
    if (pos.w < 0.75f)
    {
        float2 param = pos.xy;
        float param_1 = pos.z;
        bool param_2 = true;
        float2 param_3 = ambient_frame.xy;
        float3 lp = lotPoint(param, param_1, param_2, param_3);
        return (lp.x + lp.y) + (0.800000011920928955078125f * lp.z);
    }
    return -100000.0f;
}

float terrainBaseAt(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _407;
    if (orientation == 1)
    {
        _407 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _421;
        if (orientation == 2)
        {
            _421 = size - _point;
        }
        else
        {
            float2 _430;
            if (orientation == 3)
            {
                _430 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _430 = _point;
            }
            _421 = _430;
        }
        _407 = _421;
    }
    float2 source = _407;
    bool _448 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _456;
    if (!_448)
    {
        _456 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _456 = _448;
    }
    if (_456)
    {
        return fallback;
    }
    uint _464_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _464_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
    uint _478_dummy_parameter;
    int2 _478 = int2(spvTextureSize(overheadMap, uint(0), _478_dummy_parameter));
    if (any(bool2(at.x >= _478.x, at.y >= _478.y)))
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

float architecturalExposure(float3 _point)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _242;
    if (orientation == 1)
    {
        _242 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _257;
        if (orientation == 2)
        {
            _257 = size - _point.xy;
        }
        else
        {
            float2 _268;
            if (orientation == 3)
            {
                _268 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _268 = _point.xy;
            }
            _257 = _268;
        }
        _242 = _257;
    }
    float2 source = _242;
    bool _290 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _298;
    if (!_290)
    {
        _298 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _298 = _290;
    }
    if (_298)
    {
        return 1.0f;
    }
    uint _312_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _312_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
    uint _328_dummy_parameter;
    int2 _328 = int2(spvTextureSize(overheadMap, uint(0), _328_dummy_parameter));
    if (any(bool2(at.x >= _328.x, at.y >= _328.y)))
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

bool isExposedRoofAt(float2 px, float scale, out float outKey)
{
    outKey = -100000.0f;
    float2 param = px;
    float4 c = atmosPosAt(param);
    if (c.w > 0.25f)
    {
        return false;
    }
    float2 param_1 = c.xy;
    float param_2 = c.z;
    bool param_3 = false;
    float2 param_4 = ambient_frame.xy;
    float3 lot = lotPoint(param_1, param_2, param_3, param_4);
    float2 param_5 = lot.xy;
    float param_6 = lot.z;
    if ((lot.z - terrainBaseAt(param_5, param_6)) <= 3.0f)
    {
        return false;
    }
    float3 param_7 = lot + float3(0.0f, 0.0f, 0.449999988079071044921875f);
    if (architecturalExposure(param_7) <= 0.5f)
    {
        return false;
    }
    float3 v0 = float3(c.xy, c.z * 27.7128124237060546875f);
    float2 maxPx = ambient_extent.xy - 0.5f.xx;
    float rP = max(2.0f, 6.0f * scale);
    float wP = max(0.800000011920928955078125f, 1.5f * scale);
    for (int i = 0; i < 5; i++)
    {
        float2 dir = _784[i];
        float2 perp = float2(-dir.y, dir.x);
        float2 pML = (px + (dir * (0.5f * rP))) + (perp * (0.5f * wP));
        float2 pMR = (px + (dir * (0.5f * rP))) - (perp * (0.5f * wP));
        float2 pT = px + (dir * rP);
        float2 pL = (px + (dir * rP)) + (perp * wP);
        float2 pR = (px + (dir * rP)) - (perp * wP);
        bool _849 = any(bool2(pML.x < 0.5f.xx.x, pML.y < 0.5f.xx.y));
        bool _857;
        if (!_849)
        {
            _857 = any(bool2(pML.x > maxPx.x, pML.y > maxPx.y));
        }
        else
        {
            _857 = _849;
        }
        bool _864;
        if (!_857)
        {
            _864 = any(bool2(pMR.x < 0.5f.xx.x, pMR.y < 0.5f.xx.y));
        }
        else
        {
            _864 = _857;
        }
        bool _872;
        if (!_864)
        {
            _872 = any(bool2(pMR.x > maxPx.x, pMR.y > maxPx.y));
        }
        else
        {
            _872 = _864;
        }
        bool _879;
        if (!_872)
        {
            _879 = any(bool2(pT.x < 0.5f.xx.x, pT.y < 0.5f.xx.y));
        }
        else
        {
            _879 = _872;
        }
        bool _887;
        if (!_879)
        {
            _887 = any(bool2(pT.x > maxPx.x, pT.y > maxPx.y));
        }
        else
        {
            _887 = _879;
        }
        bool _894;
        if (!_887)
        {
            _894 = any(bool2(pL.x < 0.5f.xx.x, pL.y < 0.5f.xx.y));
        }
        else
        {
            _894 = _887;
        }
        bool _902;
        if (!_894)
        {
            _902 = any(bool2(pL.x > maxPx.x, pL.y > maxPx.y));
        }
        else
        {
            _902 = _894;
        }
        bool _909;
        if (!_902)
        {
            _909 = any(bool2(pR.x < 0.5f.xx.x, pR.y < 0.5f.xx.y));
        }
        else
        {
            _909 = _902;
        }
        bool _917;
        if (!_909)
        {
            _917 = any(bool2(pR.x > maxPx.x, pR.y > maxPx.y));
        }
        else
        {
            _917 = _909;
        }
        if (_917)
        {
            continue;
        }
        float2 param_8 = pML;
        float4 qML = atmosPosAt(param_8);
        float2 param_9 = pMR;
        float4 qMR = atmosPosAt(param_9);
        float2 param_10 = pT;
        float4 qT = atmosPosAt(param_10);
        float2 param_11 = pL;
        float4 qL = atmosPosAt(param_11);
        float2 param_12 = pR;
        float4 qR = atmosPosAt(param_12);
        float3 vML = float3(qML.xy, qML.z * 27.7128124237060546875f);
        float3 vMR = float3(qMR.xy, qMR.z * 27.7128124237060546875f);
        float3 vT = float3(qT.xy, qT.z * 27.7128124237060546875f);
        float3 vL = float3(qL.xy, qL.z * 27.7128124237060546875f);
        float3 vR = float3(qR.xy, qR.z * 27.7128124237060546875f);
        bool _988 = qML.w < 0.25f;
        bool _999;
        if (_988)
        {
            _999 = abs(vML.z - v0.z) < 14.0f;
        }
        else
        {
            _999 = _988;
        }
        bool _1005;
        if (_999)
        {
            _1005 = qMR.w < 0.25f;
        }
        else
        {
            _1005 = _999;
        }
        bool _1015;
        if (_1005)
        {
            _1015 = abs(vMR.z - v0.z) < 14.0f;
        }
        else
        {
            _1015 = _1005;
        }
        bool _1021;
        if (_1015)
        {
            _1021 = qT.w < 0.25f;
        }
        else
        {
            _1021 = _1015;
        }
        bool _1032;
        if (_1021)
        {
            _1032 = abs(vT.z - v0.z) < 22.0f;
        }
        else
        {
            _1032 = _1021;
        }
        bool _1038;
        if (_1032)
        {
            _1038 = qL.w < 0.25f;
        }
        else
        {
            _1038 = _1032;
        }
        bool _1048;
        if (_1038)
        {
            _1048 = abs(vL.z - v0.z) < 22.0f;
        }
        else
        {
            _1048 = _1038;
        }
        bool _1054;
        if (_1048)
        {
            _1054 = qR.w < 0.25f;
        }
        else
        {
            _1054 = _1048;
        }
        bool _1064;
        if (_1054)
        {
            _1064 = abs(vR.z - v0.z) < 22.0f;
        }
        else
        {
            _1064 = _1054;
        }
        bool _1075;
        if (_1064)
        {
            _1075 = abs(vL.z - vR.z) < 7.5f;
        }
        else
        {
            _1075 = _1064;
        }
        if (_1075)
        {
            float3 cr = cross(vL - v0, vR - v0);
            float crLen = length(cr);
            if (crLen > 1.0f)
            {
                float3 nW = cr / crLen.xxx;
                if (nW.z < 0.0f)
                {
                    nW = -nW;
                }
                float wFacing = dot(nW, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                bool _1115 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.89999997615814208984375f);
                bool _1122;
                if (_1115)
                {
                    _1122 = nW.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _1122 = _1115;
                }
                bool _1130;
                if (_1122)
                {
                    _1130 = abs(nW.x) > 0.1500000059604644775390625f;
                }
                else
                {
                    _1130 = _1122;
                }
                if (_1130)
                {
                    float errML = abs(dot(vML - v0, nW)) / nW.z;
                    float errMR = abs(dot(vMR - v0, nW)) / nW.z;
                    float errT = abs(dot(vT - v0, nW)) / nW.z;
                    if (((errML < 0.550000011920928955078125f) && (errMR < 0.550000011920928955078125f)) && (errT < 0.550000011920928955078125f))
                    {
                        outKey = c.z;
                        return true;
                    }
                }
            }
        }
    }
    float rF = max(6.0f, 20.0f * scale);
    float wF = max(3.0f, 9.0f * scale);
    for (int i_1 = 0; i_1 < 2; i_1++)
    {
        float2 dir_1 = _1199[i_1];
        float2 perp_1 = float2(-dir_1.y, dir_1.x);
        float2 pML_1 = (px + (dir_1 * (0.5f * rF))) + (perp_1 * (0.5f * wF));
        float2 pMR_1 = (px + (dir_1 * (0.5f * rF))) - (perp_1 * (0.5f * wF));
        float2 pT_1 = px + (dir_1 * rF);
        float2 pL_1 = (px + (dir_1 * rF)) + (perp_1 * wF);
        float2 pR_1 = (px + (dir_1 * rF)) - (perp_1 * wF);
        bool _1264 = any(bool2(pML_1.x < 0.5f.xx.x, pML_1.y < 0.5f.xx.y));
        bool _1272;
        if (!_1264)
        {
            _1272 = any(bool2(pML_1.x > maxPx.x, pML_1.y > maxPx.y));
        }
        else
        {
            _1272 = _1264;
        }
        bool _1279;
        if (!_1272)
        {
            _1279 = any(bool2(pMR_1.x < 0.5f.xx.x, pMR_1.y < 0.5f.xx.y));
        }
        else
        {
            _1279 = _1272;
        }
        bool _1287;
        if (!_1279)
        {
            _1287 = any(bool2(pMR_1.x > maxPx.x, pMR_1.y > maxPx.y));
        }
        else
        {
            _1287 = _1279;
        }
        bool _1294;
        if (!_1287)
        {
            _1294 = any(bool2(pT_1.x < 0.5f.xx.x, pT_1.y < 0.5f.xx.y));
        }
        else
        {
            _1294 = _1287;
        }
        bool _1302;
        if (!_1294)
        {
            _1302 = any(bool2(pT_1.x > maxPx.x, pT_1.y > maxPx.y));
        }
        else
        {
            _1302 = _1294;
        }
        bool _1309;
        if (!_1302)
        {
            _1309 = any(bool2(pL_1.x < 0.5f.xx.x, pL_1.y < 0.5f.xx.y));
        }
        else
        {
            _1309 = _1302;
        }
        bool _1317;
        if (!_1309)
        {
            _1317 = any(bool2(pL_1.x > maxPx.x, pL_1.y > maxPx.y));
        }
        else
        {
            _1317 = _1309;
        }
        bool _1324;
        if (!_1317)
        {
            _1324 = any(bool2(pR_1.x < 0.5f.xx.x, pR_1.y < 0.5f.xx.y));
        }
        else
        {
            _1324 = _1317;
        }
        bool _1332;
        if (!_1324)
        {
            _1332 = any(bool2(pR_1.x > maxPx.x, pR_1.y > maxPx.y));
        }
        else
        {
            _1332 = _1324;
        }
        if (_1332)
        {
            continue;
        }
        float2 param_13 = pML_1;
        float4 qML_1 = atmosPosAt(param_13);
        float2 param_14 = pMR_1;
        float4 qMR_1 = atmosPosAt(param_14);
        float2 param_15 = pT_1;
        float4 qT_1 = atmosPosAt(param_15);
        float2 param_16 = pL_1;
        float4 qL_1 = atmosPosAt(param_16);
        float2 param_17 = pR_1;
        float4 qR_1 = atmosPosAt(param_17);
        float3 vML_1 = float3(qML_1.xy, qML_1.z * 27.7128124237060546875f);
        float3 vMR_1 = float3(qMR_1.xy, qMR_1.z * 27.7128124237060546875f);
        float3 vT_1 = float3(qT_1.xy, qT_1.z * 27.7128124237060546875f);
        float3 vL_1 = float3(qL_1.xy, qL_1.z * 27.7128124237060546875f);
        float3 vR_1 = float3(qR_1.xy, qR_1.z * 27.7128124237060546875f);
        bool _1403 = qML_1.w < 0.25f;
        bool _1414;
        if (_1403)
        {
            _1414 = abs(vML_1.z - v0.z) < 28.0f;
        }
        else
        {
            _1414 = _1403;
        }
        bool _1420;
        if (_1414)
        {
            _1420 = qMR_1.w < 0.25f;
        }
        else
        {
            _1420 = _1414;
        }
        bool _1430;
        if (_1420)
        {
            _1430 = abs(vMR_1.z - v0.z) < 28.0f;
        }
        else
        {
            _1430 = _1420;
        }
        bool _1436;
        if (_1430)
        {
            _1436 = qT_1.w < 0.25f;
        }
        else
        {
            _1436 = _1430;
        }
        bool _1447;
        if (_1436)
        {
            _1447 = abs(vT_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1447 = _1436;
        }
        bool _1453;
        if (_1447)
        {
            _1453 = qL_1.w < 0.25f;
        }
        else
        {
            _1453 = _1447;
        }
        bool _1463;
        if (_1453)
        {
            _1463 = abs(vL_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1463 = _1453;
        }
        bool _1469;
        if (_1463)
        {
            _1469 = qR_1.w < 0.25f;
        }
        else
        {
            _1469 = _1463;
        }
        bool _1479;
        if (_1469)
        {
            _1479 = abs(vR_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1479 = _1469;
        }
        bool _1489;
        if (_1479)
        {
            _1489 = abs(vL_1.z - vR_1.z) < 20.0f;
        }
        else
        {
            _1489 = _1479;
        }
        if (_1489)
        {
            float3 cr_1 = cross(vL_1 - v0, vR_1 - v0);
            float crLen_1 = length(cr_1);
            if (crLen_1 > 1.0f)
            {
                float3 nW_1 = cr_1 / crLen_1.xxx;
                if (nW_1.z < 0.0f)
                {
                    nW_1 = -nW_1;
                }
                float wFacing_1 = dot(nW_1, float3(0.0f, -0.866025388240814208984375f, 0.5f));
                bool _1524 = wFacing_1 >= 0.920000016689300537109375f;
                bool _1530;
                if (_1524)
                {
                    _1530 = nW_1.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _1530 = _1524;
                }
                if (_1530)
                {
                    float errML_1 = abs(dot(vML_1 - v0, nW_1)) / nW_1.z;
                    float errMR_1 = abs(dot(vMR_1 - v0, nW_1)) / nW_1.z;
                    float errT_1 = abs(dot(vT_1 - v0, nW_1)) / nW_1.z;
                    if (((errML_1 < 0.800000011920928955078125f) && (errMR_1 < 0.800000011920928955078125f)) && (errT_1 < 0.800000011920928955078125f))
                    {
                        outKey = c.z;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

float4 rooftopEaveDroplets(float2 pixel, float2 q, float scale, float time, float dripDrive)
{
    float zoomFade = smoothstep(0.449999988079071044921875f, 0.89999997615814208984375f, scale);
    bool _1585 = zoomFade <= 0.00999999977648258209228515625f;
    bool _1593;
    if (!_1585)
    {
        _1593 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _1593 = _1585;
    }
    if (_1593)
    {
        return 0.0f.xxxx;
    }
    float colX = q.x - ambient_frame.x;
    float colId = floor(colX / 18.0f);
    float2 param = float2(colId, 47.299999237060546875f);
    float colHash = hash12(param);
    float spoutSceneX = (((colId + 0.180000007152557373046875f) + (0.63999998569488525390625f * colHash)) * 18.0f) + ambient_frame.x;
    float dxScene = q.x - spoutSceneX;
    if (abs(dxScene) > 1.7999999523162841796875f)
    {
        return 0.0f.xxxx;
    }
    float spoutPxX = ambient_view.x + (spoutSceneX * scale);
    bool _1647 = spoutPxX < 2.0f;
    bool _1656;
    if (!_1647)
    {
        _1656 = spoutPxX >= (ambient_extent.x - 2.0f);
    }
    else
    {
        _1656 = _1647;
    }
    if (_1656)
    {
        return 0.0f.xxxx;
    }
    float2 param_1 = pixel;
    float4 cHere = atmosPosAt(param_1);
    float4 param_2 = cHere;
    float keyPixel = atmosMeshKey(param_2);
    bool found = false;
    float foundDy = 0.0f;
    float eaveKey = 0.0f;
    float param_6;
    for (int i = 0; i <= 13; i++)
    {
        float dy = 1.0f + (4.0f * float(i));
        float candY = pixel.y - (dy * scale);
        if (candY < 2.0f)
        {
            break;
        }
        float2 param_3 = float2(spoutPxX, candY);
        float4 cUp = atmosPosAt(param_3);
        bool _1706 = cUp.w < 0.25f;
        bool _1719;
        if (_1706)
        {
            _1719 = cUp.z > ((keyPixel + (0.0199999995529651641845703125f * dy)) + 0.119999997317790985107421875f);
        }
        else
        {
            _1719 = _1706;
        }
        if (_1719)
        {
            float candKey = 0.0f;
            float2 param_4 = float2(spoutPxX, candY);
            float param_5 = scale;
            bool _1730 = isExposedRoofAt(param_4, param_5, param_6);
            candKey = param_6;
            if (_1730)
            {
                found = true;
                foundDy = dy;
                eaveKey = candKey;
                break;
            }
        }
    }
    if (!found)
    {
        return 0.0f.xxxx;
    }
    float lo = max(0.0f, foundDy - 4.0f);
    float hi = foundDy;
    float param_9;
    for (int k = 0; k < 3; k++)
    {
        float mid = 0.5f * (lo + hi);
        float candKey_1 = 0.0f;
        float2 param_7 = float2(spoutPxX, pixel.y - (mid * scale));
        float param_8 = scale;
        bool _1776 = isExposedRoofAt(param_7, param_8, param_9);
        candKey_1 = param_9;
        if (_1776)
        {
            hi = mid;
            eaveKey = candKey_1;
        }
        else
        {
            lo = mid;
        }
    }
    float eaveDy = hi;
    float2 belowPx1 = float2(spoutPxX, pixel.y - ((eaveDy - 3.5f) * scale));
    float2 belowPx2 = float2(spoutPxX, pixel.y - ((eaveDy - 7.0f) * scale));
    float dummyKey = 0.0f;
    float2 param_10 = belowPx1;
    float param_11 = scale;
    float param_12;
    bool _1816 = isExposedRoofAt(param_10, param_11, param_12);
    dummyKey = param_12;
    bool _1828;
    if (!_1816)
    {
        float2 param_13 = belowPx2;
        float param_14 = scale;
        float param_15;
        bool _1826 = isExposedRoofAt(param_13, param_14, param_15);
        dummyKey = param_15;
        _1828 = _1826;
    }
    else
    {
        _1828 = _1816;
    }
    if (_1828)
    {
        return 0.0f.xxxx;
    }
    float2 param_16 = belowPx1;
    float4 param_17 = atmosPosAt(param_16);
    float belowKey = atmosMeshKey(param_17);
    if ((eaveKey - belowKey) <= 0.1599999964237213134765625f)
    {
        return 0.0f.xxxx;
    }
    float fallDist = eaveDy;
    float keyDrop = eaveKey - (0.0199999995529651641845703125f * fallDist);
    if (keyDrop <= (keyPixel + 0.119999997317790985107421875f))
    {
        return 0.0f.xxxx;
    }
    float eaveSceneY = q.y - fallDist;
    float eaveBucket = floor((eaveSceneY - ambient_frame.y) / 16.0f);
    float2 param_18 = float2(colId, eaveBucket + 19.299999237060546875f);
    float spoutSeed = hash12(param_18);
    if (spoutSeed > (0.319999992847442626953125f + (0.37999999523162841796875f * dripDrive)))
    {
        return 0.0f.xxxx;
    }
    float2 param_19 = float2(colId + 11.69999980926513671875f, eaveBucket + 71.09999847412109375f);
    float period = lerp(3.2000000476837158203125f, 1.4500000476837158203125f, dripDrive) * (0.7200000286102294921875f + (0.64999997615814208984375f * hash12(param_19)));
    float2 param_20 = float2(colId + 37.09999847412109375f, eaveBucket + 5.900000095367431640625f);
    float phaseOff = hash12(param_20);
    float phase = frac((time / period) + phaseOff);
    bool hanging = phase < 0.20000000298023223876953125f;
    float dropY = 0.0f;
    float rx = 0.0f;
    float ry = 0.0f;
    float fade = 0.0f;
    if (hanging)
    {
        float swell = smoothstep(0.0f, 0.180000007152557373046875f, phase);
        dropY = 0.550000011920928955078125f + ((0.75f * swell) * swell);
        rx = lerp(0.2800000011920928955078125f, 0.439999997615814208984375f, swell);
        ry = lerp(0.449999988079071044921875f, 0.949999988079071044921875f, swell);
        fade = swell;
    }
    else
    {
        if (phase < 0.839999973773956298828125f)
        {
            float t = (phase - 0.20000000298023223876953125f) / 0.63999998569488525390625f;
            dropY = 1.2999999523162841796875f + ((46.0f * t) * t);
            rx = lerp(0.4000000059604644775390625f, 0.2800000011920928955078125f, t);
            ry = lerp(1.39999997615814208984375f, 4.400000095367431640625f, t);
            fade = 1.0f - smoothstep(0.7200000286102294921875f, 1.0f, t);
        }
        else
        {
            return 0.0f.xxxx;
        }
    }
    float effRx = max(rx, 0.36000001430511474609375f / scale);
    float dropX = clamp((ambient_tone.y * dropY) * 0.0500000007450580596923828125f, -0.5f, 0.5f);
    float2 rel = float2(dxScene - dropX, fallDist - dropY);
    float vPos = clamp(rel.y / max(ry, 0.20000000298023223876953125f), -1.0f, 1.0f);
    float _2016;
    if (rel.y < 0.0f)
    {
        _2016 = lerp(1.0f, 0.37999999523162841796875f, -vPos);
    }
    else
    {
        _2016 = lerp(1.0f, 0.819999992847442626953125f, vPos);
    }
    float taper = _2016;
    float d = length(float2(rel.x / max(effRx * taper, 0.14000000059604644775390625f), rel.y / max(ry, 0.20000000298023223876953125f)));
    float aa = 0.5f / scale;
    float body = ((1.0f - smoothstep(1.0f - aa, 1.0f + aa, d)) * fade) * zoomFade;
    if (body <= 0.004999999888241291046142578125f)
    {
        return 0.0f.xxxx;
    }
    float _2066;
    if (hanging)
    {
        _2066 = lerp(0.550000011920928955078125f, 1.0f, smoothstep(-0.85000002384185791015625f, 0.550000011920928955078125f, vPos));
    }
    else
    {
        _2066 = smoothstep(-1.0f, 0.449999988079071044921875f, vPos);
    }
    float tailGrad = _2066;
    float coreGrad = 1.0f - smoothstep(0.1500000059604644775390625f, 0.980000019073486328125f, d);
    float2 glintPos = float2(rel.x / max(effRx * 0.7200000286102294921875f, 0.14000000059604644775390625f), (rel.y - (ry * 0.319999992847442626953125f)) / max(ry * 0.4799999892711639404296875f, 0.180000007152557373046875f));
    float glint = exp((-dot(glintPos, glintPos)) * 2.400000095367431640625f) * body;
    float rim = smoothstep(0.550000011920928955078125f, 0.980000019073486328125f, d) * body;
    float nightDim = lerp(1.0f, 0.5f, ambient_weather.w);
    float streakCover = ((body * tailGrad) * (0.14000000059604644775390625f + (0.100000001490116119384765625f * dripDrive))) * (0.64999997615814208984375f + (0.3499999940395355224609375f * coreGrad));
    float glintCover = glint * (0.14000000059604644775390625f + (0.07999999821186065673828125f * dripDrive));
    float darkRim = rim * (0.07999999821186065673828125f + (0.039999999105930328369140625f * dripDrive));
    float3 waterCol = float3(0.660000026226043701171875f, 0.7400000095367431640625f, 0.839999973773956298828125f) * nightDim;
    float3 glintCol = float3(0.800000011920928955078125f, 0.86000001430511474609375f, 0.939999997615814208984375f) * nightDim;
    float3 premulRgb = (waterCol * streakCover) + (glintCol * glintCover);
    float outAlpha = clamp((streakCover + glintCover) + darkRim, 0.0f, 0.37999999523162841796875f);
    return float4(premulRgb, outAlpha);
}

float exposedAt(float2 pixel)
{
    float depth = depthMap.Load(int3(int2(pixel), 0)).x;
    bool terrain = depth >= 1.0f;
    if (terrain)
    {
        depth = groundMap.Load(int3(int2(pixel), 0)).x;
    }
    if (depth >= 1.0f)
    {
        return 1.0f;
    }
    float _554;
    if (terrain)
    {
        _554 = ambient_view.w;
    }
    else
    {
        _554 = 0.0f;
    }
    float2 param = (pixel - ambient_view.xy) / ambient_view.z.xx;
    float param_1 = ((0.89999997615814208984375f - depth) / 0.0030000000260770320892333984375f) + _554;
    bool param_2 = terrain;
    float2 param_3 = ambient_frame.xy;
    float3 _point = lotPoint(param, param_1, param_2, param_3);
    float3 param_4 = _point;
    return architecturalExposure(param_4);
}

float4 worldRainCurtains(float2 pixel, float2 q, float scale, float time, float rain, float4 surfPos, float3 localLight, float flash)
{
    bool _2182 = rain <= 0.004999999888241291046142578125f;
    bool _2189;
    if (!_2182)
    {
        _2189 = surfPos.w >= 0.75f;
    }
    else
    {
        _2189 = _2182;
    }
    bool _2196;
    if (!_2189)
    {
        _2196 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _2196 = _2189;
    }
    if (_2196)
    {
        return 0.0f.xxxx;
    }
    float2 param = surfPos.xy;
    float param_1 = surfPos.z;
    bool param_2 = surfPos.w > 0.25f;
    float2 param_3 = ambient_frame.xy;
    float3 surf = lotPoint(param, param_1, param_2, param_3);
    float surfD = surf.x + surf.y;
    float u = (q.x - ambient_frame.x) / 32.0f;
    float localY = q.y - ambient_frame.y;
    float windSlope = clamp((ambient_tone.y * 0.4199999868869781494140625f) + 0.07999999821186065673828125f, -0.3499999940395355224609375f, 0.3499999940395355224609375f);
    float baseSlice = floor(surfD / 1.64999997615814208984375f) + 1.0f;
    float streakAcc = 0.0f;
    float glintAcc = 0.0f;
    for (int slice = 0; slice < 8; slice++)
    {
        float sliceId = baseSlice + float(slice);
        float Dk = sliceId * 1.64999997615814208984375f;
        float dDepth = Dk - surfD;
        float sliceFade = smoothstep(0.0f, 0.180000007152557373046875f, dDepth) * (1.0f - smoothstep(9.8999996185302734375f, 13.034999847412109375f, dDepth));
        if (sliceFade <= 0.004999999888241291046142578125f)
        {
            continue;
        }
        float h = ((16.0f * Dk) - localY) / 40.0f;
        float2 param_4 = float2(sliceId, 13.69999980926513671875f);
        float colCoord = ((u + (windSlope * h)) * 2.599999904632568359375f) + (hash12(param_4) * 7.309999942779541015625f);
        float colId = floor(colCoord);
        float2 param_5 = float2(colId, (sliceId * 19.299999237060546875f) + 3.099999904632568359375f);
        float r = hash12(param_5);
        float2 param_6 = float2(colId, (sliceId * 41.700000762939453125f) + 9.19999980926513671875f);
        float center = 0.180000007152557373046875f + (0.63999998569488525390625f * hash12(param_6));
        float dxPx = abs(frac(colCoord) - center) * 12.30769252777099609375f;
        if (dxPx > ((1.7999999523162841796875f / max(scale, 0.449999988079071044921875f)) + 0.550000011920928955078125f))
        {
            continue;
        }
        float speed = (13.5f + (5.5f * r)) + (3.5f * rain);
        float period = lerp(4.400000095367431640625f, 2.7000000476837158203125f, rain) * (0.819999992847442626953125f + (0.36000001430511474609375f * r));
        float v = ((h + (time * speed)) / period) + (r * 11.729999542236328125f);
        float dropId = floor(v);
        float along = frac(v);
        float activeProb = lerp(0.319999992847442626953125f, 0.64999997615814208984375f, rain);
        float2 param_7 = float2(colId + (sliceId * 37.0f), (dropId * 1.7000000476837158203125f) + 5.30000019073486328125f);
        if (hash12(param_7) > activeProb)
        {
            continue;
        }
        float streakFrac = (0.36000001430511474609375f + (0.2599999904632568359375f * r)) / period;
        if (along > streakFrac)
        {
            continue;
        }
        float tAlong = along / streakFrac;
        float halfW = lerp(0.4600000083446502685546875f, 0.1599999964237213134765625f, tAlong) / max(scale, 0.5f);
        float aa = 0.439999997615814208984375f / max(scale, 0.5f);
        float acrossMask = 1.0f - smoothstep(max(0.0f, halfW - aa), halfW + aa, dxPx);
        if (acrossMask <= 0.004999999888241291046142578125f)
        {
            continue;
        }
        float3 dropPos = float3(0.5f * (Dk + u), 0.5f * (Dk - u), h);
        float3 param_8 = dropPos;
        float dropExp = architecturalExposure(param_8);
        if (dropExp <= 0.0500000007450580596923828125f)
        {
            continue;
        }
        float tailProfile = smoothstep(0.0f, 0.0900000035762786865234375f, tAlong) * pow(1.0f - smoothstep(0.0900000035762786865234375f, 1.0f, tAlong), 1.64999997615814208984375f);
        float headGlint = exp(-pow((tAlong - 0.12999999523162841796875f) / 0.14000000059604644775390625f, 2.0f)) * 0.519999980926513671875f;
        float depthWeight = lerp(1.0f, 0.62000000476837158203125f, clamp(dDepth / 12.375f, 0.0f, 1.0f));
        float w = ((((acrossMask * (tailProfile + headGlint)) * sliceFade) * dropExp) * depthWeight) * (0.75f + (0.3499999940395355224609375f * r));
        streakAcc += w;
        glintAcc += (w * headGlint);
    }
    if (streakAcc <= 0.00200000009499490261077880859375f)
    {
        return 0.0f.xxxx;
    }
    float3 baseTint = lerp(float3(0.7200000286102294921875f, 0.7799999713897705078125f, 0.86000001430511474609375f), float3(0.37999999523162841796875f, 0.439999997615814208984375f, 0.560000002384185791015625f), ambient_weather.w.xxx);
    float3 litTint = (baseTint * lerp(0.680000007152557373046875f.xxx, clamp(localLight, 0.4600000083446502685546875f.xxx, 1.7999999523162841796875f.xxx), 0.699999988079071044921875f.xxx)) + (float3(0.60000002384185791015625f, 0.660000026226043701171875f, 0.7599999904632568359375f) * flash);
    float cover = clamp(streakAcc * lerp(0.180000007152557373046875f, 0.2800000011920928955078125f, rain), 0.0f, 0.3400000035762786865234375f);
    float3 rgb = (litTint * cover) + ((litTint * 1.2999999523162841796875f) * clamp(glintAcc * 0.1599999964237213134765625f, 0.0f, 0.14000000059604644775390625f));
    return float4(rgb, cover);
}

float4 surfaceRainSplashes(float2 pixel, float scale, float time, float rain, float4 surfPos, float3 localLight, float flash)
{
    float zoomFade = smoothstep(0.2199999988079071044921875f, 0.4799999892711639404296875f, scale);
    bool _2587 = (zoomFade <= 0.00999999977648258209228515625f) || (rain <= 0.039999999105930328369140625f);
    bool _2594;
    if (!_2587)
    {
        _2594 = surfPos.w >= 0.75f;
    }
    else
    {
        _2594 = _2587;
    }
    bool _2601;
    if (!_2594)
    {
        _2601 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _2601 = _2594;
    }
    if (_2601)
    {
        return 0.0f.xxxx;
    }
    bool isGround = surfPos.w > 0.25f;
    float2 param = surfPos.xy;
    float param_1 = surfPos.z;
    bool param_2 = isGround;
    float2 param_3 = ambient_frame.xy;
    float3 surf = lotPoint(param, param_1, param_2, param_3);
    if (!isGround)
    {
        float2 param_4 = surf.xy;
        float param_5 = surf.z;
        if ((surf.z - terrainBaseAt(param_4, param_5)) <= 3.0f)
        {
            return 0.0f.xxxx;
        }
        float3 param_6 = surf + float3(0.0f, 0.0f, 0.449999988079071044921875f);
        if (architecturalExposure(param_6) <= 0.5f)
        {
            return 0.0f.xxxx;
        }
    }
    float splashAcc = 0.0f;
    bool verifiedRoof = false;
    float param_13;
    for (int layer = 0; layer < 2; layer++)
    {
        float gridScale = (layer == 0) ? 2.400000095367431640625f : 3.7999999523162841796875f;
        float seedOffset = float(layer) * 53.700000762939453125f;
        float2 g = (surf.xy * gridScale) + (float2(0.37000000476837158203125f, 0.709999978542327880859375f) * float(layer));
        float2 cid = floor(g);
        float2 param_7 = (cid + seedOffset.xx) + 3.099999904632568359375f.xx;
        float hProb = hash12(param_7);
        if (hProb > (rain * ((layer == 0) ? 0.64999997615814208984375f : 0.449999988079071044921875f)))
        {
            continue;
        }
        float2 param_8 = (cid + seedOffset.xx) + 19.299999237060546875f.xx;
        float hTime = hash12(param_8);
        float age = frac((time * ((2.2999999523162841796875f + (1.39999997615814208984375f * rain)) + (0.5f * float(layer)))) + hTime);
        if (age >= 0.2599999904632568359375f)
        {
            continue;
        }
        float t = age / 0.2599999904632568359375f;
        float2 param_9 = (cid + seedOffset.xx) + 7.900000095367431640625f.xx;
        float2 param_10 = (cid + seedOffset.xx) + 31.3999996185302734375f.xx;
        float2 dropCenter = (cid + 0.2199999988079071044921875f.xx) + (float2(hash12(param_9), hash12(param_10)) * 0.560000002384185791015625f);
        float2 delta = g - dropCenter;
        float rDist = length(delta);
        float ringR = lerp(0.02999999932944774627685546875f, 0.1599999964237213134765625f, t);
        float ringW = ((0.0439999997615814208984375f * gridScale) / 2.400000095367431640625f) / max(scale, 0.5f);
        float ring = ((1.0f - smoothstep(0.0f, ringW, abs(rDist - ringR))) * pow(1.0f - t, 1.5f)) * 0.7200000286102294921875f;
        float sx = (delta.x - delta.y) * 0.7071068286895751953125f;
        float sy = (-(delta.x + delta.y)) * 0.7071068286895751953125f;
        float hop = sin(t * 3.1415927410125732421875f) * 0.1599999964237213134765625f;
        float spread = 0.07999999821186065673828125f * t;
        float dotR = ((0.048000000417232513427734375f * gridScale) / 2.400000095367431640625f) / max(scale, 0.5f);
        float d1 = length(float2((sx - spread) * 2.0f, sy - hop));
        float d2 = length(float2((sx + spread) * 2.0f, sy - hop));
        float d0 = length(float2(sx * 2.0f, sy - (hop * 0.449999988079071044921875f)));
        float crown = (1.0f - smoothstep(dotR * 0.3499999940395355224609375f, dotR, min(d0, min(d1, d2)))) * (1.0f - t);
        float s = ring + crown;
        if (s > 0.004999999888241291046142578125f)
        {
            if ((!isGround) && (!verifiedRoof))
            {
                float roofKey = 0.0f;
                float2 param_11 = pixel;
                float param_12 = scale;
                bool _2887 = isExposedRoofAt(param_11, param_12, param_13);
                roofKey = param_13;
                if (!_2887)
                {
                    return 0.0f.xxxx;
                }
                verifiedRoof = true;
            }
            splashAcc += (s * ((layer == 0) ? 1.0f : 0.75f));
        }
    }
    if (splashAcc <= 0.00200000009499490261077880859375f)
    {
        return 0.0f.xxxx;
    }
    float3 splashTint = (lerp(float3(0.7799999713897705078125f, 0.839999973773956298828125f, 0.920000016689300537109375f), float3(0.439999997615814208984375f, 0.5f, 0.62000000476837158203125f), ambient_weather.w.xxx) * lerp(0.64999997615814208984375f.xxx, clamp(localLight, 0.439999997615814208984375f.xxx, 1.7000000476837158203125f.xxx), 0.680000007152557373046875f.xxx)) + (float3(0.60000002384185791015625f, 0.660000026226043701171875f, 0.7599999904632568359375f) * flash);
    float alpha = clamp((splashAcc * 0.2800000011920928955078125f) * zoomFade, 0.0f, 0.300000011920928955078125f);
    return float4(splashTint * alpha, alpha);
}

float2 lotFromCamera(float2 camera)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _2953;
    if (orientation == 1)
    {
        _2953 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _2967;
        if (orientation == 2)
        {
            _2967 = size - camera;
        }
        else
        {
            float2 _2976;
            if (orientation == 3)
            {
                _2976 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _2976 = camera;
            }
            _2967 = _2976;
        }
        _2953 = _2967;
    }
    return _2953;
}

float2 cameraFromLot(float2 lot)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _3005;
    if (orientation == 1)
    {
        _3005 = float2(size.y - lot.y, lot.x);
    }
    else
    {
        float2 _3019;
        if (orientation == 2)
        {
            _3019 = size - lot;
        }
        else
        {
            float2 _3028;
            if (orientation == 3)
            {
                _3028 = float2(lot.y, size.x - lot.x);
            }
            else
            {
                _3028 = lot;
            }
            _3019 = _3028;
        }
        _3005 = _3019;
    }
    return _3005;
}

float2 sceneOf(float3 q)
{
    return float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
}

float3 fallenLeafColorSrgb(float hueSeed, float speciesHue)
{
    float s = clamp(hueSeed, 0.0f, 1.0f);
    float3 gl0 = float3(0.925000011920928955078125f, 0.862999975681304931640625f, 0.208000004291534423828125f);
    float3 gl1 = float3(0.88999998569488525390625f, 0.698000013828277587890625f, 0.16099999845027923583984375f);
    float3 gl2 = float3(0.834999978542327880859375f, 0.607999980449676513671875f, 0.17299999296665191650390625f);
    float3 gl3 = float3(0.675000011920928955078125f, 0.4550000131130218505859375f, 0.1410000026226043701171875f);
    float3 _3072;
    if (s < 0.3400000035762786865234375f)
    {
        _3072 = lerp(gl0, gl1, (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _3084;
        if (s < 0.699999988079071044921875f)
        {
            _3084 = lerp(gl1, gl2, ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _3084 = lerp(gl2, gl3, ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _3072 = _3084;
    }
    float3 goldLeaf = _3072;
    float3 ol0 = float3(0.9409999847412109375f, 0.579999983310699462890625f, 0.1410000026226043701171875f);
    float3 ol1 = float3(0.910000026226043701171875f, 0.3449999988079071044921875f, 0.09399999678134918212890625f);
    float3 ol2 = float3(0.834999978542327880859375f, 0.607999980449676513671875f, 0.17299999296665191650390625f);
    float3 ol3 = float3(0.53299999237060546875f, 0.2199999988079071044921875f, 0.09399999678134918212890625f);
    float3 _3120;
    if (s < 0.3400000035762786865234375f)
    {
        _3120 = lerp(ol0, ol1, (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _3132;
        if (s < 0.699999988079071044921875f)
        {
            _3132 = lerp(ol1, ol2, ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _3132 = lerp(ol2, ol3, ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _3120 = _3132;
    }
    float3 orangeLeaf = _3120;
    return lerp(goldLeaf, orangeLeaf, clamp(speciesHue, 0.0f, 1.0f).xxx);
}

float4 treeFallingLeaves(float2 q, float scale, float time, float4 surfPos)
{
    bool _3163 = ambient_season.x <= 0.5f;
    bool _3170;
    if (!_3163)
    {
        _3170 = ambient_season.x >= 1.5f;
    }
    else
    {
        _3170 = _3163;
    }
    bool _3177;
    if (!_3170)
    {
        _3177 = ambient_season.y <= 0.25f;
    }
    else
    {
        _3177 = _3170;
    }
    if (_3177)
    {
        return 0.0f.xxxx;
    }
    uint _3185_dummy_parameter;
    int2 trailSize = int2(spvTextureSize(trailMap, uint(0), _3185_dummy_parameter));
    bool _3188 = trailSize.x <= 4;
    bool _3200;
    if (!_3188)
    {
        _3200 = abs(trailMap.Load(int3(int2(0, 0), 0)).w - 0.5f) >= 0.180000007152557373046875f;
    }
    else
    {
        _3200 = _3188;
    }
    if (_3200)
    {
        return 0.0f.xxxx;
    }
    float3 _3208;
    if (surfPos.w < 0.75f)
    {
        float2 param = surfPos.xy;
        float param_1 = surfPos.z;
        bool param_2 = surfPos.w > 0.25f;
        float2 param_3 = ambient_frame.xy;
        _3208 = lotPoint(param, param_1, param_2, param_3);
    }
    else
    {
        _3208 = 0.0f.xxx;
    }
    float3 surf = _3208;
    float4 param_4 = surfPos;
    float surfKey = atmosMeshKey(param_4);
    float _3237;
    if (surfPos.w < 0.75f)
    {
        float2 param_5 = surf.xy;
        float param_6 = surf.z;
        _3237 = terrainBaseAt(param_5, param_6);
    }
    else
    {
        _3237 = 0.0f;
    }
    float refBaseZ = _3237;
    float u = (q.x - ambient_frame.x) / 32.0f;
    float localY = q.y - ambient_frame.y;
    float midH = refBaseZ + 1.5f;
    float midD = (localY + (40.0f * midH)) / 16.0f;
    float2 midCam = float2(0.5f * (midD + u), 0.5f * (midD - u));
    float2 param_7 = midCam;
    float2 midLot = lotFromCamera(param_7);
    float2 baseCell = floor(midLot / 3.0f.xx);
    float spawnProb = clamp((ambient_season.y - 0.25f) * 0.800000011920928955078125f, 0.0f, 0.550000011920928955078125f);
    float dayDim = lerp(1.0f, 0.2800000011920928955078125f, ambient_weather.w);
    float4 acc = 0.0f.xxxx;
    float _3716;
    float _3750;
    for (int oy = -1; oy <= 1; oy++)
    {
        for (int ox = -1; ox <= 1; ox++)
        {
            float2 cell = baseCell + float2(float(ox), float(oy));
            float2 param_8 = cell + float2(17.299999237060546875f, 41.90000152587890625f);
            float period = 16.0f + (10.0f * hash12(param_8));
            float2 param_9 = cell + float2(53.09999847412109375f, 7.69999980926513671875f);
            float phase = hash12(param_9);
            float cycleT = (time / period) + phase;
            float cycleId = floor(cycleT);
            float cycleFrac = frac(cycleT);
            float2 param_10 = (cell * 1.37000000476837158203125f) + float2(cycleId * 13.1000003814697265625f, 29.700000762939453125f);
            float rSpawn = hash12(param_10);
            if (rSpawn > spawnProb)
            {
                continue;
            }
            float2 param_11 = cell + float2(cycleId * 7.30000019073486328125f, 61.09999847412109375f);
            float fallDur = 3.7999999523162841796875f + (1.60000002384185791015625f * hash12(param_11));
            float activeFrac = fallDur / period;
            if (cycleFrac >= activeFrac)
            {
                continue;
            }
            float p = cycleFrac / activeFrac;
            float2 param_12 = cell + float2(cycleId * 19.700000762939453125f, 3.099999904632568359375f);
            float2 param_13 = cell + float2(11.30000019073486328125f, cycleId * 23.8999996185302734375f);
            float2 spawnLot = (cell + float2(hash12(param_12), hash12(param_13))) * 3.0f;
            float2 texel = ((spawnLot + 1.0f.xx) * 32.0f) - 0.5f.xx;
            int2 tc = int2(floor(texel + 0.5f.xx));
            bool _3439 = any(bool2(tc.x < int2(0, 0).x, tc.y < int2(0, 0).y));
            bool _3447;
            if (!_3439)
            {
                _3447 = any(bool2(tc.x >= trailSize.x, tc.y >= trailSize.y));
            }
            else
            {
                _3447 = _3439;
            }
            if (_3447)
            {
                continue;
            }
            float4 flora = trailMap.Load(int3(tc, 0));
            bool _3458 = flora.y < 0.3499999940395355224609375f;
            bool _3465;
            if (!_3458)
            {
                _3465 = flora.x > 0.3499999940395355224609375f;
            }
            else
            {
                _3465 = _3458;
            }
            if (_3465)
            {
                continue;
            }
            float2 param_14 = spawnLot;
            float2 spawnCam = cameraFromLot(param_14);
            float2 param_15 = spawnCam;
            float param_16 = refBaseZ;
            float leafBaseZ = terrainBaseAt(param_15, param_16);
            float2 param_17 = cell + float2(cycleId * 31.299999237060546875f, 47.09999847412109375f);
            float rH = hash12(param_17);
            float hStart = (leafBaseZ + 1.85000002384185791015625f) + (0.949999988079071044921875f * rH);
            float hEnd = leafBaseZ + 0.039999999105930328369140625f;
            float flutterFreq = 1.35000002384185791015625f + (0.75f * rH);
            float flutterPhase = (rSpawn * 6.28318023681640625f) * 7.0f;
            float swayArg = ((p * 6.28318023681640625f) * flutterFreq) + flutterPhase;
            float pVert = clamp(p + (0.02199999988079071044921875f * sin(swayArg * 2.0f)), 0.0f, 1.0f);
            float lh = lerp(hStart, hEnd, pVert);
            float windMag = 0.2800000011920928955078125f + (0.2599999904632568359375f * abs(ambient_tone.y));
            float2 driftDir = normalize(float2(0.75f, -0.449999988079071044921875f) + (float2(rH - 0.5f, frac(rSpawn * 17.299999237060546875f) - 0.5f) * 0.3499999940395355224609375f));
            float2 perpDir = float2(-driftDir.y, driftDir.x);
            float sway = (sin(swayArg) * 0.1599999964237213134765625f) * sin(p * 3.141590118408203125f);
            float2 leafLot = (spawnLot + (driftDir * (windMag * p))) + (perpDir * sway);
            float2 param_18 = leafLot;
            float2 leafCam = cameraFromLot(param_18);
            float3 param_19 = float3(leafCam, lh);
            float2 leafScene = sceneOf(param_19);
            float2 d = q - leafScene;
            if (dot(d, d) > 12.0f)
            {
                continue;
            }
            float3 param_20 = float3(leafCam, lh);
            if (architecturalExposure(param_20) <= 0.5f)
            {
                continue;
            }
            float leafKey = (leafCam.x + leafCam.y) + (0.800000011920928955078125f * lh);
            if (leafKey < (surfKey - 0.4000000059604644775390625f))
            {
                continue;
            }
            float ang = (0.64999997615814208984375f * cos(swayArg)) + ((rH - 0.5f) * 1.39999997615814208984375f);
            float ca = cos(ang);
            float sa = sin(ang);
            float2 rd = float2((d.x * ca) - (d.y * sa), (d.x * sa) + (d.y * ca));
            float tumble = 0.4199999868869781494140625f + (0.579999983310699462890625f * abs(sin((swayArg * 0.85000002384185791015625f) + 1.10000002384185791015625f)));
            float halfLen = 1.85000002384185791015625f;
            float halfWid = 0.920000016689300537109375f * tumble;
            float lu = rd.x / halfLen;
            float bend = (((lu * lu) - 0.3499999940395355224609375f) * 0.2800000011920928955078125f) * halfWid;
            float lv = (rd.y - bend) / max(halfWid, 0.2800000011920928955078125f);
            float profile = sqrt(max(0.0f, 1.0f - (lu * lu))) * (1.0f - (0.25f * lu));
            float edgeSoft = 0.3400000035762786865234375f / max(scale, 0.5f);
            if (abs(lu) < 1.0f)
            {
                _3716 = 1.0f - smoothstep(-edgeSoft, edgeSoft, abs(lv) - profile);
            }
            else
            {
                _3716 = 0.0f;
            }
            float mask = _3716;
            float lifeFade = smoothstep(0.0f, 0.119999997317790985107421875f, p) * (1.0f - smoothstep(0.86000001430511474609375f, 1.0f, p));
            float alpha = (mask * 0.7799999713897705078125f) * lifeFade;
            if (alpha > 0.00999999977648258209228515625f)
            {
                if (flora.z > 0.039999999105930328369140625f)
                {
                    _3750 = flora.z;
                }
                else
                {
                    _3750 = 0.4199999868869781494140625f;
                }
                float speciesHue = _3750;
                float hueSeed = frac((rSpawn * 19.3700008392333984375f) + (rH * 7.13000011444091796875f));
                float param_21 = hueSeed;
                float param_22 = speciesHue;
                float3 leafCol = fallenLeafColorSrgb(param_21, param_22);
                float leafShade = lerp(0.7799999713897705078125f, 1.12000000476837158203125f, clamp((0.5f - (0.3499999940395355224609375f * lv)) + (0.25f * lu), 0.0f, 1.0f));
                acc += float4(((leafCol * leafShade) * dayDim) * alpha, alpha);
            }
        }
    }
    return acc;
}

void frag_main()
{
    float2 pixel = floor(gl_FragCoord.xy) + 0.5f.xx;
    bool _3815 = pixel.x >= ambient_extent.x;
    bool _3824;
    if (!_3815)
    {
        _3824 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _3824 = _3815;
    }
    if (_3824)
    {
        color = 0.0f.xxxx;
        return;
    }
    float scale = max(ambient_view.z, 0.25f);
    float cover = 0.0f;
    float rain = ambient_weather.x;
    float time = ambient_weather.z;
    float _3845;
    if (ambient_extent.w > 0.5f)
    {
        _3845 = ambient_extent.w;
    }
    else
    {
        _3845 = 1.0f;
    }
    float ambScale = _3845;
    uint _3856_dummy_parameter;
    int2 ambLimit = int2(spvTextureSize(ambientMap, uint(0), _3856_dummy_parameter)) - int2(1, 1);
    float4 ambientSample = ambientMap.Load(int3(clamp(int2(floor(pixel / ambScale.xx)), int2(0, 0), ambLimit), 0));
    float water = 1.0f - ambientSample.w;
    float3 localLight = ambientSample.xyz * 2.0f;
    float2 param = pixel;
    float4 surfPos = atmosPosAt(param);
    float3 sky = lerp(float3(0.319999992847442626953125f, 0.4000000059604644775390625f, 0.540000021457672119140625f), float3(0.23999999463558197021484375f, 0.2700000107288360595703125f, 0.319999992847442626953125f), clamp(ambient_clouds.x, 0.0f, 1.0f).xxx) * lerp(1.0f, 0.2199999988079071044921875f, ambient_weather.w);
    float4 reflection = (float4(sky, 1.0f) * 0.0280000008642673492431640625f) * water;
    bool _3912 = ambient_seasonExtra.z > 0.5f;
    bool _3926;
    if (!_3912)
    {
        bool _3919 = abs(ambient_seasonExtra.z) < 0.25f;
        bool _3925;
        if (_3919)
        {
            _3925 = ambient_season.x > 1.5f;
        }
        else
        {
            _3925 = _3919;
        }
        _3926 = _3925;
    }
    else
    {
        _3926 = _3912;
    }
    bool snowing = _3926;
    float hail = clamp(ambient_seasonExtra2.x, 0.0f, 1.0f);
    float thunderPulse = clamp(ambient_seasonExtra2.z, 0.0f, 1.0f);
    float fireflies = clamp(ambient_seasonExtra.w, 0.0f, 1.0f);
    float2 q = (pixel - ambient_view.xy) / scale.xx;
    float dripDrive = ((!snowing) && (rain > 0.0199999995529651641845703125f)) ? rain : 0.0f;
    float4 _3960;
    if (dripDrive > 0.00999999977648258209228515625f)
    {
        float2 param_1 = pixel;
        float2 param_2 = q;
        float param_3 = scale;
        float param_4 = time;
        float param_5 = dripDrive;
        _3960 = rooftopEaveDroplets(param_1, param_2, param_3, param_4, param_5);
    }
    else
    {
        _3960 = 0.0f.xxxx;
    }
    float4 eaveDrip = _3960;
    float2 param_6 = pixel;
    float exposed = exposedAt(param_6);
    if (exposed <= 0.00999999977648258209228515625f)
    {
        color = eaveDrip + (reflection * (1.0f - eaveDrip.w));
        return;
    }
    if ((rain > 0.0f) && snowing)
    {
        for (int layer = 0; layer < 3; layer++)
        {
            float cell = 26.0f + (14.0f * float(layer));
            float speed = 40.0f + (25.0f * float(layer));
            float radius = 1.2000000476837158203125f + (0.800000011920928955078125f * float(layer));
            float2 moved = (q - float2(((ambient_tone.y * speed) * 1.5f) * time, speed * time)) + (float(layer) * 113.0f).xx;
            float2 at = floor(moved / cell.xx);
            float2 param_7 = at + (float(layer) * 31.0f).xx;
            float r = hash12(param_7);
            if (r > (rain * 0.89999997615814208984375f))
            {
                continue;
            }
            float2 param_8 = at + 5.0f.xx;
            float2 param_9 = at + 9.0f.xx;
            float2 centre = ((at + 0.20000000298023223876953125f.xx) + (float2(hash12(param_8), hash12(param_9)) * 0.60000002384185791015625f)) * cell;
            centre.x += (4.0f * sin((time * (1.2000000476837158203125f + r)) + (r * 40.0f)));
            float d = length(moved - centre);
            cover += ((1.0f - smoothstep(radius * 0.4000000059604644775390625f, radius + (0.5f / scale), d)) * (0.5f + (0.20000000298023223876953125f * float(layer))));
        }
        cover = clamp(cover * 0.800000011920928955078125f, 0.0f, 0.75f) * exposed;
        color = float4(float3(0.949999988079071044921875f, 0.959999978542327880859375f, 1.0f) * cover, cover);
        return;
    }
    float4 rainCol = 0.0f.xxxx;
    if (rain > 0.0f)
    {
        float thunderFlash = 0.0f;
        bool hasThunder = (rain > 0.60000002384185791015625f) || (thunderPulse > 0.5f);
        if (hasThunder)
        {
            float slot = floor(time / 7.0f);
            float _4160;
            if (thunderPulse > 0.5f)
            {
                _4160 = 0.550000011920928955078125f;
            }
            else
            {
                _4160 = (rain - 0.60000002384185791015625f) * 1.60000002384185791015625f;
            }
            float stormChance = _4160;
            float2 param_10 = float2(slot, 3.0f);
            float strikes = step(hash12(param_10), stormChance);
            float2 param_11 = float2(slot, 7.0f);
            float dt = ((time - (slot * 7.0f)) - 1.0f) - (4.0f * hash12(param_11));
            float _4190;
            if (dt < 0.0f)
            {
                _4190 = 0.0f;
            }
            else
            {
                float _4200;
                if (dt < 0.180000007152557373046875f)
                {
                    _4200 = 0.0f;
                }
                else
                {
                    _4200 = 0.699999988079071044921875f * exp((-(dt - 0.180000007152557373046875f)) * 9.0f);
                }
                _4190 = exp((-dt) * 10.0f) + _4200;
            }
            float flash = _4190;
            thunderFlash = (clamp(flash * strikes, 0.0f, 1.0f) * 0.2800000011920928955078125f) * exposed;
        }
        float2 param_12 = pixel;
        float2 param_13 = q;
        float param_14 = scale;
        float param_15 = time;
        float param_16 = rain;
        float4 param_17 = surfPos;
        float3 param_18 = localLight;
        float param_19 = thunderFlash;
        float4 rain3d = worldRainCurtains(param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19);
        float2 param_20 = pixel;
        float param_21 = scale;
        float param_22 = time;
        float param_23 = rain;
        float4 param_24 = surfPos;
        float3 param_25 = localLight;
        float param_26 = thunderFlash;
        float4 splashes = surfaceRainSplashes(param_20, param_21, param_22, param_23, param_24, param_25, param_26);
        rainCol = rain3d + (splashes * (1.0f - rain3d.w));
        cover = rainCol.w;
        float hailCover = 0.0f;
        if (hail > 0.0500000007450580596923828125f)
        {
            for (int layer_1 = 0; layer_1 < 2; layer_1++)
            {
                float cell_1 = 24.0f + (12.0f * float(layer_1));
                float speed_1 = 640.0f + (220.0f * float(layer_1));
                float2 moved_1 = (q - float2(((ambient_tone.y * speed_1) * 0.60000002384185791015625f) * time, speed_1 * time)) + (float(layer_1) * 79.0f).xx;
                float2 at_1 = floor(moved_1 / cell_1.xx);
                float2 param_27 = at_1 + (float(layer_1) * 53.0f).xx;
                if (hash12(param_27) > (hail * 0.449999988079071044921875f))
                {
                    continue;
                }
                float2 param_28 = at_1 + 11.0f.xx;
                float2 param_29 = at_1 + 19.0f.xx;
                float2 centre_1 = ((at_1 + 0.25f.xx) + (float2(hash12(param_28), hash12(param_29)) * 0.5f)) * cell_1;
                float r_1 = 1.2999999523162841796875f + (0.60000002384185791015625f * float(layer_1));
                hailCover += ((1.0f - smoothstep(r_1 * 0.4000000059604644775390625f, r_1 + (0.4000000059604644775390625f / scale), length(moved_1 - centre_1))) * 0.550000011920928955078125f);
            }
            hailCover = clamp(hailCover, 0.0f, 0.60000002384185791015625f) * exposed;
        }
        if (hasThunder || (hailCover > 0.001000000047497451305389404296875f))
        {
            float4 baseCol = float4((rainCol.xyz + (float3(0.949999988079071044921875f, 0.980000019073486328125f, 1.0f) * hailCover)) + (float3(0.920000016689300537109375f, 0.939999997615814208984375f, 1.0f) * thunderFlash), clamp(rainCol.w + hailCover, 0.0f, 0.75f)) + (reflection * (1.0f - rainCol.w));
            color = eaveDrip + (baseCol * (1.0f - eaveDrip.w));
            return;
        }
    }
    float4 airborne = 0.0f.xxxx;
    if (rain <= 0.0199999995529651641845703125f)
    {
        float2 param_30 = q;
        float param_31 = scale;
        float param_32 = time;
        float4 param_33 = surfPos;
        airborne += treeFallingLeaves(param_30, param_31, param_32, param_33);
        if ((exposed > 0.5f) && (fireflies > 0.0500000007450580596923828125f))
        {
            float cell_2 = 320.0f;
            float2 moved_2 = q + float2(149.0f, 83.0f);
            float2 at_2 = floor(moved_2 / cell_2.xx);
            float2 param_34 = at_2 + 29.0f.xx;
            float r_2 = hash12(param_34);
            if (r_2 <= (fireflies * 0.054999999701976776123046875f))
            {
                float2 param_35 = at_2 + 5.0f.xx;
                float2 param_36 = at_2 + 17.0f.xx;
                float2 clump = ((at_2 + 0.25f.xx) + (float2(hash12(param_35), hash12(param_36)) * 0.5f)) * cell_2;
                if (length(moved_2 - clump) < 30.0f)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        float fk = float(k);
                        float2 param_37 = at_2 + float2(fk * 11.30000019073486328125f, 3.7000000476837158203125f);
                        float h1 = hash12(param_37);
                        float2 param_38 = at_2 + float2(7.099999904632568359375f, fk * 17.8999996185302734375f);
                        float h2 = hash12(param_38);
                        float2 pos = clump + float2(((h1 - 0.5f) * 18.0f) + (4.5f * sin(((time * (0.64999997615814208984375f + (0.449999988079071044921875f * h2))) + (fk * 2.099999904632568359375f)) + (h1 * 19.0f))), ((h2 - 0.5f) * 12.0f) + (3.2000000476837158203125f * cos(((time * (0.800000011920928955078125f + (0.3499999940395355224609375f * h1))) + (fk * 3.400000095367431640625f)) + (h2 * 13.0f))));
                        float pulse = pow(0.5f + (0.5f * sin(((time * (0.949999988079071044921875f + (0.699999988079071044921875f * h1))) + (fk * 1.89999997615814208984375f)) + (h2 * 29.0f))), 4.19999980926513671875f);
                        float dist = length(moved_2 - pos);
                        float core = ((((1.0f - smoothstep(0.1500000059604644775390625f, 0.85000002384185791015625f, dist)) * pulse) * fireflies) * 0.949999988079071044921875f) * exposed;
                        float halo = (((exp(((-dist) * dist) / 24.0f) * pulse) * fireflies) * 0.2199999988079071044921875f) * exposed;
                        airborne += float4((float3(1.0f, 0.939999997615814208984375f, 0.579999983310699462890625f) * core) + (float3(1.0f, 0.86000001430511474609375f, 0.3400000035762786865234375f) * halo), clamp((core * 0.75f) + (halo * 0.319999992847442626953125f), 0.0f, 0.85000002384185791015625f));
                    }
                }
            }
        }
    }
    airborne = clamp(airborne, 0.0f.xxxx, 1.0f.xxxx);
    float4 baseCol_1 = (rainCol + (reflection * (1.0f - cover))) + (airborne * (1.0f - cover));
    color = eaveDrip + (baseCol_1 * (1.0f - eaveDrip.w));
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    gl_FragCoord = stage_input.gl_FragCoord;
    gl_FragCoord.w = 1.0 / gl_FragCoord.w;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.color = color;
    return stage_output;
}
