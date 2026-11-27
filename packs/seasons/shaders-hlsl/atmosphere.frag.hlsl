static const float2 _1031[5] = { float2(-0.89442718029022216796875f, -0.447213590145111083984375f), float2(0.89442718029022216796875f, -0.447213590145111083984375f), (-0.7071068286895751953125f).xx, float2(0.7071068286895751953125f, -0.7071068286895751953125f), float2(0.0f, -1.0f) };
static const float2 _1447[2] = { (-0.7071068286895751953125f).xx, float2(0.7071068286895751953125f, -0.7071068286895751953125f) };

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
Texture2D<float4> outFloraMap : register(t5, space2);
SamplerState _outFloraMap_sampler : register(s5, space2);
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
        return float4(sc, (0.62000000476837158203125f - d) / 0.0030000000260770320892333984375f, 0.0f);
    }
    float g = groundMap.Load(int3(int2(cpx), 0)).x;
    if (g < 1.0f)
    {
        return float4(sc, ((0.62000000476837158203125f - g) / 0.0030000000260770320892333984375f) + ambient_view.w, 0.5f);
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
    float _115;
    if (terrain)
    {
        _115 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _115 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _115;
    float _139;
    if (terrain)
    {
        _139 = key;
    }
    else
    {
        _139 = key - (0.800000011920928955078125f * h);
    }
    float s = _139;
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
    float2 _478;
    if (orientation == 1)
    {
        _478 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _492;
        if (orientation == 2)
        {
            _492 = size - _point;
        }
        else
        {
            float2 _501;
            if (orientation == 3)
            {
                _501 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _501 = _point;
            }
            _492 = _501;
        }
        _478 = _492;
    }
    float2 source = _478;
    bool _519 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _527;
    if (!_519)
    {
        _527 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _527 = _519;
    }
    if (_527)
    {
        return fallback;
    }
    uint _535_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _535_dummy_parameter));
    bool _542 = mapSize.y >= (mapSize.x * 2);
    bool _548;
    if (_542)
    {
        _548 = mapSize.x > 1;
    }
    else
    {
        _548 = _542;
    }
    int2 _549;
    if (_548)
    {
        _549 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _549 = mapSize;
    }
    int2 baseSize = _549;
    float2 texelsPerTile = float2(baseSize) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
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

float architecturalExposure(float3 _point)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _246;
    if (orientation == 1)
    {
        _246 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _261;
        if (orientation == 2)
        {
            _261 = size - _point.xy;
        }
        else
        {
            float2 _272;
            if (orientation == 3)
            {
                _272 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _272 = _point.xy;
            }
            _261 = _272;
        }
        _246 = _261;
    }
    float2 source = _246;
    bool _294 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _302;
    if (!_294)
    {
        _302 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _302 = _294;
    }
    if (_302)
    {
        return 1.0f;
    }
    uint _317_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _317_dummy_parameter));
    bool _324 = mapSize.y >= (mapSize.x * 2);
    bool _330;
    if (_324)
    {
        _330 = mapSize.x > 1;
    }
    else
    {
        _330 = _324;
    }
    bool hasBand1 = _330;
    int2 _333;
    if (hasBand1)
    {
        _333 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _333 = mapSize;
    }
    int2 baseSize = _333;
    float2 texelsPerTile = float2(baseSize) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
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
        float2 dir = _1031[i];
        float2 perp = float2(-dir.y, dir.x);
        float2 pML = (px + (dir * (0.5f * rP))) + (perp * (0.5f * wP));
        float2 pMR = (px + (dir * (0.5f * rP))) - (perp * (0.5f * wP));
        float2 pT = px + (dir * rP);
        float2 pL = (px + (dir * rP)) + (perp * wP);
        float2 pR = (px + (dir * rP)) - (perp * wP);
        bool _1096 = any(bool2(pML.x < 0.5f.xx.x, pML.y < 0.5f.xx.y));
        bool _1104;
        if (!_1096)
        {
            _1104 = any(bool2(pML.x > maxPx.x, pML.y > maxPx.y));
        }
        else
        {
            _1104 = _1096;
        }
        bool _1111;
        if (!_1104)
        {
            _1111 = any(bool2(pMR.x < 0.5f.xx.x, pMR.y < 0.5f.xx.y));
        }
        else
        {
            _1111 = _1104;
        }
        bool _1119;
        if (!_1111)
        {
            _1119 = any(bool2(pMR.x > maxPx.x, pMR.y > maxPx.y));
        }
        else
        {
            _1119 = _1111;
        }
        bool _1126;
        if (!_1119)
        {
            _1126 = any(bool2(pT.x < 0.5f.xx.x, pT.y < 0.5f.xx.y));
        }
        else
        {
            _1126 = _1119;
        }
        bool _1134;
        if (!_1126)
        {
            _1134 = any(bool2(pT.x > maxPx.x, pT.y > maxPx.y));
        }
        else
        {
            _1134 = _1126;
        }
        bool _1141;
        if (!_1134)
        {
            _1141 = any(bool2(pL.x < 0.5f.xx.x, pL.y < 0.5f.xx.y));
        }
        else
        {
            _1141 = _1134;
        }
        bool _1149;
        if (!_1141)
        {
            _1149 = any(bool2(pL.x > maxPx.x, pL.y > maxPx.y));
        }
        else
        {
            _1149 = _1141;
        }
        bool _1156;
        if (!_1149)
        {
            _1156 = any(bool2(pR.x < 0.5f.xx.x, pR.y < 0.5f.xx.y));
        }
        else
        {
            _1156 = _1149;
        }
        bool _1164;
        if (!_1156)
        {
            _1164 = any(bool2(pR.x > maxPx.x, pR.y > maxPx.y));
        }
        else
        {
            _1164 = _1156;
        }
        if (_1164)
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
        bool _1235 = qML.w < 0.25f;
        bool _1246;
        if (_1235)
        {
            _1246 = abs(vML.z - v0.z) < 14.0f;
        }
        else
        {
            _1246 = _1235;
        }
        bool _1252;
        if (_1246)
        {
            _1252 = qMR.w < 0.25f;
        }
        else
        {
            _1252 = _1246;
        }
        bool _1262;
        if (_1252)
        {
            _1262 = abs(vMR.z - v0.z) < 14.0f;
        }
        else
        {
            _1262 = _1252;
        }
        bool _1268;
        if (_1262)
        {
            _1268 = qT.w < 0.25f;
        }
        else
        {
            _1268 = _1262;
        }
        bool _1279;
        if (_1268)
        {
            _1279 = abs(vT.z - v0.z) < 22.0f;
        }
        else
        {
            _1279 = _1268;
        }
        bool _1285;
        if (_1279)
        {
            _1285 = qL.w < 0.25f;
        }
        else
        {
            _1285 = _1279;
        }
        bool _1295;
        if (_1285)
        {
            _1295 = abs(vL.z - v0.z) < 22.0f;
        }
        else
        {
            _1295 = _1285;
        }
        bool _1301;
        if (_1295)
        {
            _1301 = qR.w < 0.25f;
        }
        else
        {
            _1301 = _1295;
        }
        bool _1311;
        if (_1301)
        {
            _1311 = abs(vR.z - v0.z) < 22.0f;
        }
        else
        {
            _1311 = _1301;
        }
        bool _1322;
        if (_1311)
        {
            _1322 = abs(vL.z - vR.z) < 7.5f;
        }
        else
        {
            _1322 = _1311;
        }
        if (_1322)
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
                bool _1363 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.89999997615814208984375f);
                bool _1370;
                if (_1363)
                {
                    _1370 = nW.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _1370 = _1363;
                }
                bool _1378;
                if (_1370)
                {
                    _1378 = abs(nW.x) > 0.1500000059604644775390625f;
                }
                else
                {
                    _1378 = _1370;
                }
                if (_1378)
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
        float2 dir_1 = _1447[i_1];
        float2 perp_1 = float2(-dir_1.y, dir_1.x);
        float2 pML_1 = (px + (dir_1 * (0.5f * rF))) + (perp_1 * (0.5f * wF));
        float2 pMR_1 = (px + (dir_1 * (0.5f * rF))) - (perp_1 * (0.5f * wF));
        float2 pT_1 = px + (dir_1 * rF);
        float2 pL_1 = (px + (dir_1 * rF)) + (perp_1 * wF);
        float2 pR_1 = (px + (dir_1 * rF)) - (perp_1 * wF);
        bool _1512 = any(bool2(pML_1.x < 0.5f.xx.x, pML_1.y < 0.5f.xx.y));
        bool _1520;
        if (!_1512)
        {
            _1520 = any(bool2(pML_1.x > maxPx.x, pML_1.y > maxPx.y));
        }
        else
        {
            _1520 = _1512;
        }
        bool _1527;
        if (!_1520)
        {
            _1527 = any(bool2(pMR_1.x < 0.5f.xx.x, pMR_1.y < 0.5f.xx.y));
        }
        else
        {
            _1527 = _1520;
        }
        bool _1535;
        if (!_1527)
        {
            _1535 = any(bool2(pMR_1.x > maxPx.x, pMR_1.y > maxPx.y));
        }
        else
        {
            _1535 = _1527;
        }
        bool _1542;
        if (!_1535)
        {
            _1542 = any(bool2(pT_1.x < 0.5f.xx.x, pT_1.y < 0.5f.xx.y));
        }
        else
        {
            _1542 = _1535;
        }
        bool _1550;
        if (!_1542)
        {
            _1550 = any(bool2(pT_1.x > maxPx.x, pT_1.y > maxPx.y));
        }
        else
        {
            _1550 = _1542;
        }
        bool _1557;
        if (!_1550)
        {
            _1557 = any(bool2(pL_1.x < 0.5f.xx.x, pL_1.y < 0.5f.xx.y));
        }
        else
        {
            _1557 = _1550;
        }
        bool _1565;
        if (!_1557)
        {
            _1565 = any(bool2(pL_1.x > maxPx.x, pL_1.y > maxPx.y));
        }
        else
        {
            _1565 = _1557;
        }
        bool _1572;
        if (!_1565)
        {
            _1572 = any(bool2(pR_1.x < 0.5f.xx.x, pR_1.y < 0.5f.xx.y));
        }
        else
        {
            _1572 = _1565;
        }
        bool _1580;
        if (!_1572)
        {
            _1580 = any(bool2(pR_1.x > maxPx.x, pR_1.y > maxPx.y));
        }
        else
        {
            _1580 = _1572;
        }
        if (_1580)
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
        bool _1651 = qML_1.w < 0.25f;
        bool _1662;
        if (_1651)
        {
            _1662 = abs(vML_1.z - v0.z) < 28.0f;
        }
        else
        {
            _1662 = _1651;
        }
        bool _1668;
        if (_1662)
        {
            _1668 = qMR_1.w < 0.25f;
        }
        else
        {
            _1668 = _1662;
        }
        bool _1678;
        if (_1668)
        {
            _1678 = abs(vMR_1.z - v0.z) < 28.0f;
        }
        else
        {
            _1678 = _1668;
        }
        bool _1684;
        if (_1678)
        {
            _1684 = qT_1.w < 0.25f;
        }
        else
        {
            _1684 = _1678;
        }
        bool _1695;
        if (_1684)
        {
            _1695 = abs(vT_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1695 = _1684;
        }
        bool _1701;
        if (_1695)
        {
            _1701 = qL_1.w < 0.25f;
        }
        else
        {
            _1701 = _1695;
        }
        bool _1711;
        if (_1701)
        {
            _1711 = abs(vL_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1711 = _1701;
        }
        bool _1717;
        if (_1711)
        {
            _1717 = qR_1.w < 0.25f;
        }
        else
        {
            _1717 = _1711;
        }
        bool _1727;
        if (_1717)
        {
            _1727 = abs(vR_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1727 = _1717;
        }
        bool _1737;
        if (_1727)
        {
            _1737 = abs(vL_1.z - vR_1.z) < 20.0f;
        }
        else
        {
            _1737 = _1727;
        }
        if (_1737)
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
                bool _1772 = wFacing_1 >= 0.920000016689300537109375f;
                bool _1778;
                if (_1772)
                {
                    _1778 = nW_1.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _1778 = _1772;
                }
                if (_1778)
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
    bool _1833 = zoomFade <= 0.00999999977648258209228515625f;
    bool _1841;
    if (!_1833)
    {
        _1841 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _1841 = _1833;
    }
    if (_1841)
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
    bool _1895 = spoutPxX < 2.0f;
    bool _1904;
    if (!_1895)
    {
        _1904 = spoutPxX >= (ambient_extent.x - 2.0f);
    }
    else
    {
        _1904 = _1895;
    }
    if (_1904)
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
        bool _1954 = cUp.w < 0.25f;
        bool _1967;
        if (_1954)
        {
            _1967 = cUp.z > ((keyPixel + (0.0199999995529651641845703125f * dy)) + 0.119999997317790985107421875f);
        }
        else
        {
            _1967 = _1954;
        }
        if (_1967)
        {
            float candKey = 0.0f;
            float2 param_4 = float2(spoutPxX, candY);
            float param_5 = scale;
            bool _1978 = isExposedRoofAt(param_4, param_5, param_6);
            candKey = param_6;
            if (_1978)
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
        bool _2024 = isExposedRoofAt(param_7, param_8, param_9);
        candKey_1 = param_9;
        if (_2024)
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
    bool _2064 = isExposedRoofAt(param_10, param_11, param_12);
    dummyKey = param_12;
    bool _2076;
    if (!_2064)
    {
        float2 param_13 = belowPx2;
        float param_14 = scale;
        float param_15;
        bool _2074 = isExposedRoofAt(param_13, param_14, param_15);
        dummyKey = param_15;
        _2076 = _2074;
    }
    else
    {
        _2076 = _2064;
    }
    if (_2076)
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
    float _2264;
    if (rel.y < 0.0f)
    {
        _2264 = lerp(1.0f, 0.37999999523162841796875f, -vPos);
    }
    else
    {
        _2264 = lerp(1.0f, 0.819999992847442626953125f, vPos);
    }
    float taper = _2264;
    float d = length(float2(rel.x / max(effRx * taper, 0.14000000059604644775390625f), rel.y / max(ry, 0.20000000298023223876953125f)));
    float aa = 0.5f / scale;
    float body = ((1.0f - smoothstep(1.0f - aa, 1.0f + aa, d)) * fade) * zoomFade;
    if (body <= 0.004999999888241291046142578125f)
    {
        return 0.0f.xxxx;
    }
    float _2314;
    if (hanging)
    {
        _2314 = lerp(0.550000011920928955078125f, 1.0f, smoothstep(-0.85000002384185791015625f, 0.550000011920928955078125f, vPos));
    }
    else
    {
        _2314 = smoothstep(-1.0f, 0.449999988079071044921875f, vPos);
    }
    float tailGrad = _2314;
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
    float _801;
    if (terrain)
    {
        _801 = ambient_view.w;
    }
    else
    {
        _801 = 0.0f;
    }
    float2 param = (pixel - ambient_view.xy) / ambient_view.z.xx;
    float param_1 = ((0.62000000476837158203125f - depth) / 0.0030000000260770320892333984375f) + _801;
    bool param_2 = terrain;
    float2 param_3 = ambient_frame.xy;
    float3 _point = lotPoint(param, param_1, param_2, param_3);
    float3 param_4 = _point;
    return architecturalExposure(param_4);
}

float4 worldRainCurtains(float2 pixel, float2 q, float scale, float time, float rain, float4 surfPos, float3 localLight, float flash)
{
    bool _2430 = rain <= 0.004999999888241291046142578125f;
    bool _2437;
    if (!_2430)
    {
        _2437 = surfPos.w >= 0.75f;
    }
    else
    {
        _2437 = _2430;
    }
    bool _2444;
    if (!_2437)
    {
        _2444 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _2444 = _2437;
    }
    if (_2444)
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
    bool _2834 = (zoomFade <= 0.00999999977648258209228515625f) || (rain <= 0.039999999105930328369140625f);
    bool _2841;
    if (!_2834)
    {
        _2841 = surfPos.w >= 0.75f;
    }
    else
    {
        _2841 = _2834;
    }
    bool _2848;
    if (!_2841)
    {
        _2848 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _2848 = _2841;
    }
    if (_2848)
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
                bool _3134 = isExposedRoofAt(param_11, param_12, param_13);
                roofKey = param_13;
                if (!_3134)
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

float terrainBaseClamped(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    bool _613 = size.x <= 0.0f;
    bool _620;
    if (!_613)
    {
        _620 = size.y <= 0.0f;
    }
    else
    {
        _620 = _613;
    }
    if (_620)
    {
        return fallback;
    }
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _633;
    if (orientation == 1)
    {
        _633 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _647;
        if (orientation == 2)
        {
            _647 = size - _point;
        }
        else
        {
            float2 _656;
            if (orientation == 3)
            {
                _656 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _656 = _point;
            }
            _647 = _656;
        }
        _633 = _647;
    }
    float2 source = _633;
    uint _675_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _675_dummy_parameter));
    bool _682 = mapSize.y >= (mapSize.x * 2);
    bool _688;
    if (_682)
    {
        _688 = mapSize.x > 1;
    }
    else
    {
        _688 = _682;
    }
    int2 _689;
    if (_688)
    {
        _689 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _689 = mapSize;
    }
    int2 baseSize = _689;
    if (baseSize.x <= 1)
    {
        return fallback;
    }
    float2 clamped = clamp(source, 0.0f.xx, max(size - 0.001000000047497451305389404296875f.xx, 0.0f.xx));
    float2 texelsPerTile = float2(baseSize) / max(size, 1.0f.xx);
    int2 at = clamp(int2(floor(clamped * texelsPerTile)), int2(0, 0), baseSize - int2(1, 1));
    int4 data = int4((overheadMap.Load(int3(at, 0)) * 255.0f) + 0.5f.xxxx);
    if (data.w == 0)
    {
        return fallback;
    }
    return float(((data.y * 256) + data.z) - 32768) / 256.0f;
}

float2 lotFromCamera(float2 camera)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _3200;
    if (orientation == 1)
    {
        _3200 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _3214;
        if (orientation == 2)
        {
            _3214 = size - camera;
        }
        else
        {
            float2 _3223;
            if (orientation == 3)
            {
                _3223 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _3223 = camera;
            }
            _3214 = _3223;
        }
        _3200 = _3214;
    }
    return _3200;
}

float2 cameraFromLot(float2 lot)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _3252;
    if (orientation == 1)
    {
        _3252 = float2(size.y - lot.y, lot.x);
    }
    else
    {
        float2 _3266;
        if (orientation == 2)
        {
            _3266 = size - lot;
        }
        else
        {
            float2 _3275;
            if (orientation == 3)
            {
                _3275 = float2(lot.y, size.x - lot.x);
            }
            else
            {
                _3275 = lot;
            }
            _3266 = _3275;
        }
        _3252 = _3266;
    }
    return _3252;
}

float2 sceneOf(float3 q)
{
    return float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
}

float3 fallenLeafColorSrgb(float hueSeed, float speciesHue)
{
    float s = clamp(hueSeed, 0.0f, 1.0f);
    float h = clamp(speciesHue, 0.0f, 1.0f);
    float3 _3302;
    if (s < 0.3400000035762786865234375f)
    {
        _3302 = lerp(float3(0.944999992847442626953125f, 0.86699998378753662109375f, 0.25499999523162841796875f), float3(0.8980000019073486328125f, 0.709999978542327880859375f, 0.17299999296665191650390625f), (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _3319;
        if (s < 0.7200000286102294921875f)
        {
            _3319 = lerp(float3(0.8980000019073486328125f, 0.709999978542327880859375f, 0.17299999296665191650390625f), float3(0.834999978542327880859375f, 0.564999997615814208984375f, 0.16500000655651092529296875f), ((s - 0.3400000035762786865234375f) / 0.37999999523162841796875f).xxx);
        }
        else
        {
            _3319 = lerp(float3(0.834999978542327880859375f, 0.564999997615814208984375f, 0.16500000655651092529296875f), float3(0.68599998950958251953125f, 0.4550000131130218505859375f, 0.1410000026226043701171875f), ((s - 0.7200000286102294921875f) / 0.2800000011920928955078125f).xxx);
        }
        _3302 = _3319;
    }
    float3 goldLeaf = _3302;
    float3 _3346;
    if (s < 0.2800000011920928955078125f)
    {
        _3346 = lerp(float3(0.953000009059906005859375f, 0.834999978542327880859375f, 0.23499999940395355224609375f), float3(0.944999992847442626953125f, 0.587999999523162841796875f, 0.14499999582767486572265625f), (s / 0.2800000011920928955078125f).xxx);
    }
    else
    {
        float3 _3362;
        if (s < 0.63999998569488525390625f)
        {
            _3362 = lerp(float3(0.944999992847442626953125f, 0.587999999523162841796875f, 0.14499999582767486572265625f), float3(0.893999993801116943359375f, 0.3449999988079071044921875f, 0.097999997437000274658203125f), ((s - 0.2800000011920928955078125f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _3362 = lerp(float3(0.893999993801116943359375f, 0.3449999988079071044921875f, 0.097999997437000274658203125f), float3(0.681999981403350830078125f, 0.23499999940395355224609375f, 0.08200000226497650146484375f), ((s - 0.63999998569488525390625f) / 0.36000001430511474609375f).xxx);
        }
        _3346 = _3362;
    }
    float3 spellboundLeaf = _3346;
    float3 _3388;
    if (s < 0.319999992847442626953125f)
    {
        _3388 = lerp(float3(0.94900000095367431640625f, 0.6549999713897705078125f, 0.18400000035762786865234375f), float3(0.88999998569488525390625f, 0.3490000069141387939453125f, 0.105999998748302459716796875f), (s / 0.319999992847442626953125f).xxx);
    }
    else
    {
        float3 _3406;
        if (s < 0.699999988079071044921875f)
        {
            _3406 = lerp(float3(0.88999998569488525390625f, 0.3490000069141387939453125f, 0.105999998748302459716796875f), float3(0.757000029087066650390625f, 0.208000004291534423828125f, 0.078000001609325408935546875f), ((s - 0.319999992847442626953125f) / 0.37999999523162841796875f).xxx);
        }
        else
        {
            _3406 = lerp(float3(0.757000029087066650390625f, 0.208000004291534423828125f, 0.078000001609325408935546875f), float3(0.545000016689300537109375f, 0.14900000393390655517578125f, 0.0670000016689300537109375f), ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _3388 = _3406;
    }
    float3 scarletLeaf = _3388;
    float3 _3433;
    if (s < 0.3400000035762786865234375f)
    {
        _3433 = lerp(float3(0.819999992847442626953125f, 0.4510000050067901611328125f, 0.45899999141693115234375f), float3(0.681999981403350830078125f, 0.31400001049041748046875f, 0.324999988079071044921875f), (s / 0.3400000035762786865234375f).xxx);
    }
    else
    {
        float3 _3449;
        if (s < 0.699999988079071044921875f)
        {
            _3449 = lerp(float3(0.681999981403350830078125f, 0.31400001049041748046875f, 0.324999988079071044921875f), float3(0.5490000247955322265625f, 0.2199999988079071044921875f, 0.231000006198883056640625f), ((s - 0.3400000035762786865234375f) / 0.36000001430511474609375f).xxx);
        }
        else
        {
            _3449 = lerp(float3(0.5490000247955322265625f, 0.2199999988079071044921875f, 0.231000006198883056640625f), float3(0.3959999978542327880859375f, 0.14499999582767486572265625f, 0.157000005245208740234375f), ((s - 0.699999988079071044921875f) / 0.300000011920928955078125f).xxx);
        }
        _3433 = _3449;
    }
    float3 burgundyLeaf = _3433;
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

float4 treeFallingLeaves(float2 q, float scale, float time, float4 surfPos)
{
    bool _3512 = ambient_season.x <= 0.5f;
    bool _3519;
    if (!_3512)
    {
        _3519 = ambient_season.x >= 1.5f;
    }
    else
    {
        _3519 = _3512;
    }
    bool _3526;
    if (!_3519)
    {
        _3526 = ambient_season.y <= 0.25f;
    }
    else
    {
        _3526 = _3519;
    }
    if (_3526)
    {
        return 0.0f.xxxx;
    }
    uint _3534_dummy_parameter;
    int2 trailSize = int2(spvTextureSize(trailMap, uint(0), _3534_dummy_parameter));
    uint _3539_dummy_parameter;
    int2 outSize = int2(spvTextureSize(outFloraMap, uint(0), _3539_dummy_parameter));
    bool _3543 = trailSize.x > 4;
    bool _3553;
    if (_3543)
    {
        _3553 = abs(trailMap.Load(int3(int2(0, 0), 0)).w - 0.5f) < 0.180000007152557373046875f;
    }
    else
    {
        _3553 = _3543;
    }
    bool hasInTrail = _3553;
    bool _3558 = ambient_prevView.w > 0.5f;
    bool _3564;
    if (_3558)
    {
        _3564 = ambient_prevView.x > 0.0f;
    }
    else
    {
        _3564 = _3558;
    }
    bool _3570;
    if (_3564)
    {
        _3570 = outSize.x > 4;
    }
    else
    {
        _3570 = _3564;
    }
    bool hasOutFlora = _3570;
    if ((!hasInTrail) && (!hasOutFlora))
    {
        return 0.0f.xxxx;
    }
    float3 _3583;
    if (surfPos.w < 0.75f)
    {
        float2 param = surfPos.xy;
        float param_1 = surfPos.z;
        bool param_2 = surfPos.w > 0.25f;
        float2 param_3 = ambient_frame.xy;
        _3583 = lotPoint(param, param_1, param_2, param_3);
    }
    else
    {
        _3583 = 0.0f.xxx;
    }
    float3 surf = _3583;
    float4 param_4 = surfPos;
    float surfKey = atmosMeshKey(param_4);
    float _3612;
    if (surfPos.w > 0.25f)
    {
        _3612 = surf.z;
    }
    else
    {
        float2 param_5 = surf.xy;
        float param_6 = ambient_contact.w;
        _3612 = terrainBaseClamped(param_5, param_6);
    }
    float surfGroundFallback = _3612;
    float _3630;
    if (surfPos.w < 0.75f)
    {
        float2 param_7 = surf.xy;
        float param_8 = surfGroundFallback;
        _3630 = terrainBaseAt(param_7, param_8);
    }
    else
    {
        _3630 = ambient_contact.w;
    }
    float refBaseZ = _3630;
    float u = (q.x - ambient_frame.x) / 32.0f;
    float localY = q.y - ambient_frame.y;
    float midH = refBaseZ + 1.5f;
    float midD = (localY + (40.0f * midH)) / 16.0f;
    float2 midCam = float2(0.5f * (midD + u), 0.5f * (midD - u));
    float2 param_9 = midCam;
    float2 midLot = lotFromCamera(param_9);
    float2 lotSize = ambient_drift.zw;
    float2 baseCell = floor(midLot / 3.0f.xx);
    float spawnProb = clamp((ambient_season.y - 0.25f) * 0.800000011920928955078125f, 0.0f, 0.550000011920928955078125f);
    float dayDim = lerp(1.0f, 0.2800000011920928955078125f, ambient_weather.w);
    float4 acc = 0.0f.xxxx;
    float _4189;
    float _4223;
    for (int oy = -1; oy <= 1; oy++)
    {
        for (int ox = -1; ox <= 1; ox++)
        {
            float2 cell = baseCell + float2(float(ox), float(oy));
            float2 param_10 = cell + float2(17.299999237060546875f, 41.90000152587890625f);
            float period = 16.0f + (10.0f * hash12(param_10));
            float2 param_11 = cell + float2(53.09999847412109375f, 7.69999980926513671875f);
            float phase = hash12(param_11);
            float cycleT = (time / period) + phase;
            float cycleId = floor(cycleT);
            float cycleFrac = frac(cycleT);
            float2 param_12 = (cell * 1.37000000476837158203125f) + float2(cycleId * 13.1000003814697265625f, 29.700000762939453125f);
            float rSpawn = hash12(param_12);
            if (rSpawn > spawnProb)
            {
                continue;
            }
            float2 param_13 = cell + float2(cycleId * 7.30000019073486328125f, 61.09999847412109375f);
            float fallDur = 3.7999999523162841796875f + (1.60000002384185791015625f * hash12(param_13));
            float activeFrac = fallDur / period;
            if (cycleFrac >= activeFrac)
            {
                continue;
            }
            float p = cycleFrac / activeFrac;
            float2 param_14 = cell + float2(cycleId * 19.700000762939453125f, 3.099999904632568359375f);
            float2 param_15 = cell + float2(11.30000019073486328125f, cycleId * 23.8999996185302734375f);
            float2 spawnLot = (cell + float2(hash12(param_14), hash12(param_15))) * 3.0f;
            bool _3825 = spawnLot.x >= (-0.5f);
            bool _3831;
            if (_3825)
            {
                _3831 = spawnLot.y >= (-0.5f);
            }
            else
            {
                _3831 = _3825;
            }
            bool _3840;
            if (_3831)
            {
                _3840 = spawnLot.x <= (lotSize.x + 0.5f);
            }
            else
            {
                _3840 = _3831;
            }
            bool _3849;
            if (_3840)
            {
                _3849 = spawnLot.y <= (lotSize.y + 0.5f);
            }
            else
            {
                _3849 = _3840;
            }
            bool inLot = _3849;
            float4 flora = 0.0f.xxxx;
            if (inLot && hasInTrail)
            {
                float2 texel = ((spawnLot + 1.0f.xx) * 32.0f) - 0.5f.xx;
                int2 tc = int2(floor(texel + 0.5f.xx));
                bool _3871 = any(bool2(tc.x < int2(0, 0).x, tc.y < int2(0, 0).y));
                bool _3879;
                if (!_3871)
                {
                    _3879 = any(bool2(tc.x >= trailSize.x, tc.y >= trailSize.y));
                }
                else
                {
                    _3879 = _3871;
                }
                if (_3879)
                {
                    continue;
                }
                flora = trailMap.Load(int3(tc, 0));
            }
            else
            {
                if (hasOutFlora)
                {
                    float2 texel_1 = ((spawnLot + ambient_prevView.yz) * ambient_prevView.x) - 0.5f.xx;
                    int2 tc_1 = int2(floor(texel_1 + 0.5f.xx));
                    bool _3910 = any(bool2(tc_1.x < int2(0, 0).x, tc_1.y < int2(0, 0).y));
                    bool _3918;
                    if (!_3910)
                    {
                        _3918 = any(bool2(tc_1.x >= outSize.x, tc_1.y >= outSize.y));
                    }
                    else
                    {
                        _3918 = _3910;
                    }
                    if (_3918)
                    {
                        continue;
                    }
                    flora = outFloraMap.Load(int3(tc_1, 0));
                }
                else
                {
                    continue;
                }
            }
            bool _3930 = flora.y < 0.3499999940395355224609375f;
            bool _3937;
            if (!_3930)
            {
                _3937 = flora.x > 0.3499999940395355224609375f;
            }
            else
            {
                _3937 = _3930;
            }
            if (_3937)
            {
                continue;
            }
            float2 param_16 = spawnLot;
            float2 spawnCam = cameraFromLot(param_16);
            float2 param_17 = spawnCam;
            float param_18 = refBaseZ;
            float leafBaseZ = terrainBaseAt(param_17, param_18);
            float2 param_19 = cell + float2(cycleId * 31.299999237060546875f, 47.09999847412109375f);
            float rH = hash12(param_19);
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
            float2 param_20 = leafLot;
            float2 leafCam = cameraFromLot(param_20);
            float3 param_21 = float3(leafCam, lh);
            float2 leafScene = sceneOf(param_21);
            float2 d = q - leafScene;
            if (dot(d, d) > 12.0f)
            {
                continue;
            }
            float3 param_22 = float3(leafCam, lh);
            if (architecturalExposure(param_22) <= 0.5f)
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
                _4189 = 1.0f - smoothstep(-edgeSoft, edgeSoft, abs(lv) - profile);
            }
            else
            {
                _4189 = 0.0f;
            }
            float mask = _4189;
            float lifeFade = smoothstep(0.0f, 0.119999997317790985107421875f, p) * (1.0f - smoothstep(0.86000001430511474609375f, 1.0f, p));
            float alpha = (mask * 0.7799999713897705078125f) * lifeFade;
            if (alpha > 0.00999999977648258209228515625f)
            {
                if (flora.z > 0.039999999105930328369140625f)
                {
                    _4223 = flora.z;
                }
                else
                {
                    _4223 = 0.4199999868869781494140625f;
                }
                float speciesHue = _4223;
                float hueSeed = frac((rSpawn * 19.3700008392333984375f) + (rH * 7.13000011444091796875f));
                float param_23 = hueSeed;
                float param_24 = speciesHue;
                float3 leafCol = fallenLeafColorSrgb(param_23, param_24);
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
    bool _4288 = pixel.x >= ambient_extent.x;
    bool _4297;
    if (!_4288)
    {
        _4297 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _4297 = _4288;
    }
    if (_4297)
    {
        color = 0.0f.xxxx;
        return;
    }
    float scale = max(ambient_view.z, 0.25f);
    float cover = 0.0f;
    float rain = ambient_weather.x;
    float time = ambient_weather.z;
    float _4318;
    if (ambient_extent.w > 0.5f)
    {
        _4318 = ambient_extent.w;
    }
    else
    {
        _4318 = 1.0f;
    }
    float ambScale = _4318;
    uint _4329_dummy_parameter;
    int2 ambLimit = int2(spvTextureSize(ambientMap, uint(0), _4329_dummy_parameter)) - int2(1, 1);
    float4 ambientSample = ambientMap.Load(int3(clamp(int2(floor(pixel / ambScale.xx)), int2(0, 0), ambLimit), 0));
    float water = 1.0f - ambientSample.w;
    float3 localLight = ambientSample.xyz * 2.0f;
    float2 param = pixel;
    float4 surfPos = atmosPosAt(param);
    float3 sky = lerp(float3(0.319999992847442626953125f, 0.4000000059604644775390625f, 0.540000021457672119140625f), float3(0.23999999463558197021484375f, 0.2700000107288360595703125f, 0.319999992847442626953125f), clamp(ambient_clouds.x, 0.0f, 1.0f).xxx) * lerp(1.0f, 0.2199999988079071044921875f, ambient_weather.w);
    float4 reflection = (float4(sky, 1.0f) * 0.0280000008642673492431640625f) * water;
    bool _4384 = ambient_seasonExtra.z > 0.5f;
    bool _4398;
    if (!_4384)
    {
        bool _4391 = abs(ambient_seasonExtra.z) < 0.25f;
        bool _4397;
        if (_4391)
        {
            _4397 = ambient_season.x > 1.5f;
        }
        else
        {
            _4397 = _4391;
        }
        _4398 = _4397;
    }
    else
    {
        _4398 = _4384;
    }
    bool snowing = _4398;
    float hail = clamp(ambient_seasonExtra2.x, 0.0f, 1.0f);
    float thunderPulse = clamp(ambient_seasonExtra2.z, 0.0f, 1.0f);
    float fireflies = clamp(ambient_seasonExtra.w, 0.0f, 1.0f);
    float2 q = (pixel - ambient_view.xy) / scale.xx;
    float dripDrive = ((!snowing) && (rain > 0.0199999995529651641845703125f)) ? rain : 0.0f;
    float4 _4432;
    if (dripDrive > 0.00999999977648258209228515625f)
    {
        float2 param_1 = pixel;
        float2 param_2 = q;
        float param_3 = scale;
        float param_4 = time;
        float param_5 = dripDrive;
        _4432 = rooftopEaveDroplets(param_1, param_2, param_3, param_4, param_5);
    }
    else
    {
        _4432 = 0.0f.xxxx;
    }
    float4 eaveDrip = _4432;
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
            float _4632;
            if (thunderPulse > 0.5f)
            {
                _4632 = 0.550000011920928955078125f;
            }
            else
            {
                _4632 = (rain - 0.60000002384185791015625f) * 1.60000002384185791015625f;
            }
            float stormChance = _4632;
            float2 param_10 = float2(slot, 3.0f);
            float strikes = step(hash12(param_10), stormChance);
            float2 param_11 = float2(slot, 7.0f);
            float dt = ((time - (slot * 7.0f)) - 1.0f) - (4.0f * hash12(param_11));
            float _4662;
            if (dt < 0.0f)
            {
                _4662 = 0.0f;
            }
            else
            {
                float _4672;
                if (dt < 0.180000007152557373046875f)
                {
                    _4672 = 0.0f;
                }
                else
                {
                    _4672 = 0.699999988079071044921875f * exp((-(dt - 0.180000007152557373046875f)) * 9.0f);
                }
                _4662 = exp((-dt) * 10.0f) + _4672;
            }
            float flash = _4662;
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
