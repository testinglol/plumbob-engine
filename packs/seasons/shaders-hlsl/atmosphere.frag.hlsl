static const float2 _738[5] = { float2(-0.89442718029022216796875f, -0.447213590145111083984375f), float2(0.89442718029022216796875f, -0.447213590145111083984375f), (-0.7071068286895751953125f).xx, float2(0.7071068286895751953125f, -0.7071068286895751953125f), float2(0.0f, -1.0f) };
static const float2 _1153[2] = { (-0.7071068286895751953125f).xx, float2(0.7071068286895751953125f, -0.7071068286895751953125f) };

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

Texture2D<float4> overheadMap : register(t3, space2);
SamplerState _overheadMap_sampler : register(s3, space2);
Texture2D<float4> depthMap : register(t1, space2);
SamplerState _depthMap_sampler : register(s1, space2);
Texture2D<float4> groundMap : register(t2, space2);
SamplerState _groundMap_sampler : register(s2, space2);
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
    float _88;
    if (terrain)
    {
        _88 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _88 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _88;
    float _112;
    if (terrain)
    {
        _112 = key;
    }
    else
    {
        _112 = key - (0.800000011920928955078125f * h);
    }
    float s = _112;
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
    float2 _360;
    if (orientation == 1)
    {
        _360 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _374;
        if (orientation == 2)
        {
            _374 = size - _point;
        }
        else
        {
            float2 _383;
            if (orientation == 3)
            {
                _383 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _383 = _point;
            }
            _374 = _383;
        }
        _360 = _374;
    }
    float2 source = _360;
    bool _401 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _409;
    if (!_401)
    {
        _409 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _409 = _401;
    }
    if (_409)
    {
        return fallback;
    }
    uint _417_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _417_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
    uint _431_dummy_parameter;
    int2 _431 = int2(spvTextureSize(overheadMap, uint(0), _431_dummy_parameter));
    if (any(bool2(at.x >= _431.x, at.y >= _431.y)))
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
    float2 _195;
    if (orientation == 1)
    {
        _195 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _210;
        if (orientation == 2)
        {
            _210 = size - _point.xy;
        }
        else
        {
            float2 _221;
            if (orientation == 3)
            {
                _221 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _221 = _point.xy;
            }
            _210 = _221;
        }
        _195 = _210;
    }
    float2 source = _195;
    bool _243 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _251;
    if (!_243)
    {
        _251 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _251 = _243;
    }
    if (_251)
    {
        return 1.0f;
    }
    uint _265_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _265_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
    uint _281_dummy_parameter;
    int2 _281 = int2(spvTextureSize(overheadMap, uint(0), _281_dummy_parameter));
    if (any(bool2(at.x >= _281.x, at.y >= _281.y)))
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
        float2 dir = _738[i];
        float2 perp = float2(-dir.y, dir.x);
        float2 pML = (px + (dir * (0.5f * rP))) + (perp * (0.5f * wP));
        float2 pMR = (px + (dir * (0.5f * rP))) - (perp * (0.5f * wP));
        float2 pT = px + (dir * rP);
        float2 pL = (px + (dir * rP)) + (perp * wP);
        float2 pR = (px + (dir * rP)) - (perp * wP);
        bool _803 = any(bool2(pML.x < 0.5f.xx.x, pML.y < 0.5f.xx.y));
        bool _811;
        if (!_803)
        {
            _811 = any(bool2(pML.x > maxPx.x, pML.y > maxPx.y));
        }
        else
        {
            _811 = _803;
        }
        bool _818;
        if (!_811)
        {
            _818 = any(bool2(pMR.x < 0.5f.xx.x, pMR.y < 0.5f.xx.y));
        }
        else
        {
            _818 = _811;
        }
        bool _826;
        if (!_818)
        {
            _826 = any(bool2(pMR.x > maxPx.x, pMR.y > maxPx.y));
        }
        else
        {
            _826 = _818;
        }
        bool _833;
        if (!_826)
        {
            _833 = any(bool2(pT.x < 0.5f.xx.x, pT.y < 0.5f.xx.y));
        }
        else
        {
            _833 = _826;
        }
        bool _841;
        if (!_833)
        {
            _841 = any(bool2(pT.x > maxPx.x, pT.y > maxPx.y));
        }
        else
        {
            _841 = _833;
        }
        bool _848;
        if (!_841)
        {
            _848 = any(bool2(pL.x < 0.5f.xx.x, pL.y < 0.5f.xx.y));
        }
        else
        {
            _848 = _841;
        }
        bool _856;
        if (!_848)
        {
            _856 = any(bool2(pL.x > maxPx.x, pL.y > maxPx.y));
        }
        else
        {
            _856 = _848;
        }
        bool _863;
        if (!_856)
        {
            _863 = any(bool2(pR.x < 0.5f.xx.x, pR.y < 0.5f.xx.y));
        }
        else
        {
            _863 = _856;
        }
        bool _871;
        if (!_863)
        {
            _871 = any(bool2(pR.x > maxPx.x, pR.y > maxPx.y));
        }
        else
        {
            _871 = _863;
        }
        if (_871)
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
        bool _942 = qML.w < 0.25f;
        bool _953;
        if (_942)
        {
            _953 = abs(vML.z - v0.z) < 14.0f;
        }
        else
        {
            _953 = _942;
        }
        bool _959;
        if (_953)
        {
            _959 = qMR.w < 0.25f;
        }
        else
        {
            _959 = _953;
        }
        bool _969;
        if (_959)
        {
            _969 = abs(vMR.z - v0.z) < 14.0f;
        }
        else
        {
            _969 = _959;
        }
        bool _975;
        if (_969)
        {
            _975 = qT.w < 0.25f;
        }
        else
        {
            _975 = _969;
        }
        bool _986;
        if (_975)
        {
            _986 = abs(vT.z - v0.z) < 22.0f;
        }
        else
        {
            _986 = _975;
        }
        bool _992;
        if (_986)
        {
            _992 = qL.w < 0.25f;
        }
        else
        {
            _992 = _986;
        }
        bool _1002;
        if (_992)
        {
            _1002 = abs(vL.z - v0.z) < 22.0f;
        }
        else
        {
            _1002 = _992;
        }
        bool _1008;
        if (_1002)
        {
            _1008 = qR.w < 0.25f;
        }
        else
        {
            _1008 = _1002;
        }
        bool _1018;
        if (_1008)
        {
            _1018 = abs(vR.z - v0.z) < 22.0f;
        }
        else
        {
            _1018 = _1008;
        }
        bool _1029;
        if (_1018)
        {
            _1029 = abs(vL.z - vR.z) < 7.5f;
        }
        else
        {
            _1029 = _1018;
        }
        if (_1029)
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
                bool _1069 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.89999997615814208984375f);
                bool _1076;
                if (_1069)
                {
                    _1076 = nW.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _1076 = _1069;
                }
                bool _1084;
                if (_1076)
                {
                    _1084 = abs(nW.x) > 0.1500000059604644775390625f;
                }
                else
                {
                    _1084 = _1076;
                }
                if (_1084)
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
        float2 dir_1 = _1153[i_1];
        float2 perp_1 = float2(-dir_1.y, dir_1.x);
        float2 pML_1 = (px + (dir_1 * (0.5f * rF))) + (perp_1 * (0.5f * wF));
        float2 pMR_1 = (px + (dir_1 * (0.5f * rF))) - (perp_1 * (0.5f * wF));
        float2 pT_1 = px + (dir_1 * rF);
        float2 pL_1 = (px + (dir_1 * rF)) + (perp_1 * wF);
        float2 pR_1 = (px + (dir_1 * rF)) - (perp_1 * wF);
        bool _1218 = any(bool2(pML_1.x < 0.5f.xx.x, pML_1.y < 0.5f.xx.y));
        bool _1226;
        if (!_1218)
        {
            _1226 = any(bool2(pML_1.x > maxPx.x, pML_1.y > maxPx.y));
        }
        else
        {
            _1226 = _1218;
        }
        bool _1233;
        if (!_1226)
        {
            _1233 = any(bool2(pMR_1.x < 0.5f.xx.x, pMR_1.y < 0.5f.xx.y));
        }
        else
        {
            _1233 = _1226;
        }
        bool _1241;
        if (!_1233)
        {
            _1241 = any(bool2(pMR_1.x > maxPx.x, pMR_1.y > maxPx.y));
        }
        else
        {
            _1241 = _1233;
        }
        bool _1248;
        if (!_1241)
        {
            _1248 = any(bool2(pT_1.x < 0.5f.xx.x, pT_1.y < 0.5f.xx.y));
        }
        else
        {
            _1248 = _1241;
        }
        bool _1256;
        if (!_1248)
        {
            _1256 = any(bool2(pT_1.x > maxPx.x, pT_1.y > maxPx.y));
        }
        else
        {
            _1256 = _1248;
        }
        bool _1263;
        if (!_1256)
        {
            _1263 = any(bool2(pL_1.x < 0.5f.xx.x, pL_1.y < 0.5f.xx.y));
        }
        else
        {
            _1263 = _1256;
        }
        bool _1271;
        if (!_1263)
        {
            _1271 = any(bool2(pL_1.x > maxPx.x, pL_1.y > maxPx.y));
        }
        else
        {
            _1271 = _1263;
        }
        bool _1278;
        if (!_1271)
        {
            _1278 = any(bool2(pR_1.x < 0.5f.xx.x, pR_1.y < 0.5f.xx.y));
        }
        else
        {
            _1278 = _1271;
        }
        bool _1286;
        if (!_1278)
        {
            _1286 = any(bool2(pR_1.x > maxPx.x, pR_1.y > maxPx.y));
        }
        else
        {
            _1286 = _1278;
        }
        if (_1286)
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
        bool _1357 = qML_1.w < 0.25f;
        bool _1368;
        if (_1357)
        {
            _1368 = abs(vML_1.z - v0.z) < 28.0f;
        }
        else
        {
            _1368 = _1357;
        }
        bool _1374;
        if (_1368)
        {
            _1374 = qMR_1.w < 0.25f;
        }
        else
        {
            _1374 = _1368;
        }
        bool _1384;
        if (_1374)
        {
            _1384 = abs(vMR_1.z - v0.z) < 28.0f;
        }
        else
        {
            _1384 = _1374;
        }
        bool _1390;
        if (_1384)
        {
            _1390 = qT_1.w < 0.25f;
        }
        else
        {
            _1390 = _1384;
        }
        bool _1401;
        if (_1390)
        {
            _1401 = abs(vT_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1401 = _1390;
        }
        bool _1407;
        if (_1401)
        {
            _1407 = qL_1.w < 0.25f;
        }
        else
        {
            _1407 = _1401;
        }
        bool _1417;
        if (_1407)
        {
            _1417 = abs(vL_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1417 = _1407;
        }
        bool _1423;
        if (_1417)
        {
            _1423 = qR_1.w < 0.25f;
        }
        else
        {
            _1423 = _1417;
        }
        bool _1433;
        if (_1423)
        {
            _1433 = abs(vR_1.z - v0.z) < 48.0f;
        }
        else
        {
            _1433 = _1423;
        }
        bool _1443;
        if (_1433)
        {
            _1443 = abs(vL_1.z - vR_1.z) < 20.0f;
        }
        else
        {
            _1443 = _1433;
        }
        if (_1443)
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
                bool _1478 = wFacing_1 >= 0.920000016689300537109375f;
                bool _1484;
                if (_1478)
                {
                    _1484 = nW_1.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _1484 = _1478;
                }
                if (_1484)
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
    bool _1539 = zoomFade <= 0.00999999977648258209228515625f;
    bool _1547;
    if (!_1539)
    {
        _1547 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _1547 = _1539;
    }
    if (_1547)
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
    bool _1601 = spoutPxX < 2.0f;
    bool _1610;
    if (!_1601)
    {
        _1610 = spoutPxX >= (ambient_extent.x - 2.0f);
    }
    else
    {
        _1610 = _1601;
    }
    if (_1610)
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
        bool _1660 = cUp.w < 0.25f;
        bool _1673;
        if (_1660)
        {
            _1673 = cUp.z > ((keyPixel + (0.0199999995529651641845703125f * dy)) + 0.119999997317790985107421875f);
        }
        else
        {
            _1673 = _1660;
        }
        if (_1673)
        {
            float candKey = 0.0f;
            float2 param_4 = float2(spoutPxX, candY);
            float param_5 = scale;
            bool _1684 = isExposedRoofAt(param_4, param_5, param_6);
            candKey = param_6;
            if (_1684)
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
        bool _1730 = isExposedRoofAt(param_7, param_8, param_9);
        candKey_1 = param_9;
        if (_1730)
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
    bool _1770 = isExposedRoofAt(param_10, param_11, param_12);
    dummyKey = param_12;
    bool _1782;
    if (!_1770)
    {
        float2 param_13 = belowPx2;
        float param_14 = scale;
        float param_15;
        bool _1780 = isExposedRoofAt(param_13, param_14, param_15);
        dummyKey = param_15;
        _1782 = _1780;
    }
    else
    {
        _1782 = _1770;
    }
    if (_1782)
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
    float _1970;
    if (rel.y < 0.0f)
    {
        _1970 = lerp(1.0f, 0.37999999523162841796875f, -vPos);
    }
    else
    {
        _1970 = lerp(1.0f, 0.819999992847442626953125f, vPos);
    }
    float taper = _1970;
    float d = length(float2(rel.x / max(effRx * taper, 0.14000000059604644775390625f), rel.y / max(ry, 0.20000000298023223876953125f)));
    float aa = 0.5f / scale;
    float body = ((1.0f - smoothstep(1.0f - aa, 1.0f + aa, d)) * fade) * zoomFade;
    if (body <= 0.004999999888241291046142578125f)
    {
        return 0.0f.xxxx;
    }
    float _2020;
    if (hanging)
    {
        _2020 = lerp(0.550000011920928955078125f, 1.0f, smoothstep(-0.85000002384185791015625f, 0.550000011920928955078125f, vPos));
    }
    else
    {
        _2020 = smoothstep(-1.0f, 0.449999988079071044921875f, vPos);
    }
    float tailGrad = _2020;
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
    float _507;
    if (terrain)
    {
        _507 = ambient_view.w;
    }
    else
    {
        _507 = 0.0f;
    }
    float2 param = (pixel - ambient_view.xy) / ambient_view.z.xx;
    float param_1 = ((0.89999997615814208984375f - depth) / 0.0030000000260770320892333984375f) + _507;
    bool param_2 = terrain;
    float2 param_3 = ambient_frame.xy;
    float3 _point = lotPoint(param, param_1, param_2, param_3);
    float3 param_4 = _point;
    return architecturalExposure(param_4);
}

float4 worldRainCurtains(float2 pixel, float2 q, float scale, float time, float rain, float4 surfPos, float3 localLight, float flash)
{
    bool _2136 = rain <= 0.004999999888241291046142578125f;
    bool _2143;
    if (!_2136)
    {
        _2143 = surfPos.w >= 0.75f;
    }
    else
    {
        _2143 = _2136;
    }
    bool _2150;
    if (!_2143)
    {
        _2150 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _2150 = _2143;
    }
    if (_2150)
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
    bool _2541 = (zoomFade <= 0.00999999977648258209228515625f) || (rain <= 0.039999999105930328369140625f);
    bool _2548;
    if (!_2541)
    {
        _2548 = surfPos.w >= 0.75f;
    }
    else
    {
        _2548 = _2541;
    }
    bool _2555;
    if (!_2548)
    {
        _2555 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _2555 = _2548;
    }
    if (_2555)
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
                bool _2841 = isExposedRoofAt(param_11, param_12, param_13);
                roofKey = param_13;
                if (!_2841)
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

void frag_main()
{
    float2 pixel = floor(gl_FragCoord.xy) + 0.5f.xx;
    bool _2908 = pixel.x >= ambient_extent.x;
    bool _2917;
    if (!_2908)
    {
        _2917 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _2917 = _2908;
    }
    if (_2917)
    {
        color = 0.0f.xxxx;
        return;
    }
    float scale = max(ambient_view.z, 0.25f);
    float cover = 0.0f;
    float rain = ambient_weather.x;
    float time = ambient_weather.z;
    float _2938;
    if (ambient_extent.w > 0.5f)
    {
        _2938 = ambient_extent.w;
    }
    else
    {
        _2938 = 1.0f;
    }
    float ambScale = _2938;
    uint _2949_dummy_parameter;
    int2 ambLimit = int2(spvTextureSize(ambientMap, uint(0), _2949_dummy_parameter)) - int2(1, 1);
    float4 ambientSample = ambientMap.Load(int3(clamp(int2(floor(pixel / ambScale.xx)), int2(0, 0), ambLimit), 0));
    float water = 1.0f - ambientSample.w;
    float3 localLight = ambientSample.xyz * 2.0f;
    float2 param = pixel;
    float4 surfPos = atmosPosAt(param);
    float3 sky = lerp(float3(0.319999992847442626953125f, 0.4000000059604644775390625f, 0.540000021457672119140625f), float3(0.23999999463558197021484375f, 0.2700000107288360595703125f, 0.319999992847442626953125f), clamp(ambient_clouds.x, 0.0f, 1.0f).xxx) * lerp(1.0f, 0.2199999988079071044921875f, ambient_weather.w);
    float4 reflection = (float4(sky, 1.0f) * 0.0280000008642673492431640625f) * water;
    bool _3006 = ambient_seasonExtra.z > 0.5f;
    bool _3021;
    if (!_3006)
    {
        bool _3013 = abs(ambient_seasonExtra.z) < 0.25f;
        bool _3020;
        if (_3013)
        {
            _3020 = ambient_season.x > 1.5f;
        }
        else
        {
            _3020 = _3013;
        }
        _3021 = _3020;
    }
    else
    {
        _3021 = _3006;
    }
    bool snowing = _3021;
    float hail = clamp(ambient_seasonExtra2.x, 0.0f, 1.0f);
    float thunderPulse = clamp(ambient_seasonExtra2.z, 0.0f, 1.0f);
    float fireflies = clamp(ambient_seasonExtra.w, 0.0f, 1.0f);
    float2 q = (pixel - ambient_view.xy) / scale.xx;
    bool _3046 = !snowing;
    bool _3058;
    if (_3046)
    {
        bool _3050 = rain > 0.0199999995529651641845703125f;
        bool _3057;
        if (!_3050)
        {
            _3057 = ambient_weather.y > 0.300000011920928955078125f;
        }
        else
        {
            _3057 = _3050;
        }
        _3058 = _3057;
    }
    else
    {
        _3058 = _3046;
    }
    float _3059;
    if (_3058)
    {
        _3059 = clamp(max(rain, smoothstep(0.300000011920928955078125f, 0.89999997615814208984375f, ambient_weather.y) * 0.550000011920928955078125f), 0.0f, 1.0f);
    }
    else
    {
        _3059 = 0.0f;
    }
    float dripDrive = _3059;
    float4 _3074;
    if (dripDrive > 0.00999999977648258209228515625f)
    {
        float2 param_1 = pixel;
        float2 param_2 = q;
        float param_3 = scale;
        float param_4 = time;
        float param_5 = dripDrive;
        _3074 = rooftopEaveDroplets(param_1, param_2, param_3, param_4, param_5);
    }
    else
    {
        _3074 = 0.0f.xxxx;
    }
    float4 eaveDrip = _3074;
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
            float _3274;
            if (thunderPulse > 0.5f)
            {
                _3274 = 0.550000011920928955078125f;
            }
            else
            {
                _3274 = (rain - 0.60000002384185791015625f) * 1.60000002384185791015625f;
            }
            float stormChance = _3274;
            float2 param_10 = float2(slot, 3.0f);
            float strikes = step(hash12(param_10), stormChance);
            float2 param_11 = float2(slot, 7.0f);
            float dt = ((time - (slot * 7.0f)) - 1.0f) - (4.0f * hash12(param_11));
            float _3305;
            if (dt < 0.0f)
            {
                _3305 = 0.0f;
            }
            else
            {
                float _3316;
                if (dt < 0.180000007152557373046875f)
                {
                    _3316 = 0.0f;
                }
                else
                {
                    _3316 = 0.699999988079071044921875f * exp((-(dt - 0.180000007152557373046875f)) * 9.0f);
                }
                _3305 = exp((-dt) * 10.0f) + _3316;
            }
            float flash = _3305;
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
    if ((rain <= 0.0199999995529651641845703125f) && (exposed > 0.5f))
    {
        bool _3545 = ambient_season.x > 0.5f;
        bool _3551;
        if (_3545)
        {
            _3551 = ambient_season.x < 1.5f;
        }
        else
        {
            _3551 = _3545;
        }
        bool _3557;
        if (_3551)
        {
            _3557 = ambient_season.y > 0.25f;
        }
        else
        {
            _3557 = _3551;
        }
        if (_3557)
        {
            float leafDensity = clamp((ambient_season.y - 0.25f) * 0.2800000011920928955078125f, 0.0f, 0.2199999988079071044921875f);
            float dayDim = lerp(1.0f, 0.2800000011920928955078125f, ambient_weather.w);
            float _3786;
            float3 _3814;
            for (int layer_2 = 0; layer_2 < 2; layer_2++)
            {
                float cell_2 = 96.0f + (44.0f * float(layer_2));
                float driftX = (38.0f + (18.0f * float(layer_2))) * (0.64999997615814208984375f + (0.5f * abs(ambient_tone.y)));
                float driftY = 18.0f + (9.0f * float(layer_2));
                float2 moved_2 = (q - float2(driftX * time, driftY * time)) + (float(layer_2) * 197.0f).xx;
                float2 at_2 = floor(moved_2 / cell_2.xx);
                float2 param_30 = at_2 + (float(layer_2) * 43.0f).xx;
                float r_2 = hash12(param_30);
                if (r_2 > leafDensity)
                {
                    continue;
                }
                float2 param_31 = at_2 + 7.0f.xx;
                float2 param_32 = at_2 + 13.0f.xx;
                float2 centre_2 = ((at_2 + 0.25f.xx) + (float2(hash12(param_31), hash12(param_32)) * 0.5f)) * cell_2;
                centre_2.x += (9.0f * sin((time * (1.10000002384185791015625f + r_2)) + (r_2 * 31.0f)));
                centre_2.y += (5.0f * cos((time * (1.60000002384185791015625f + r_2)) + (r_2 * 19.0f)));
                float2 d_1 = moved_2 - centre_2;
                float ang = (time * (1.7999999523162841796875f + (1.39999997615814208984375f * r_2))) + (r_2 * 6.28318023681640625f);
                float ca = cos(ang);
                float sa = sin(ang);
                float2 rd = float2((d_1.x * ca) - (d_1.y * sa), (d_1.x * sa) + (d_1.y * ca));
                float tumble = 0.449999988079071044921875f + (0.550000011920928955078125f * abs(sin((time * (2.599999904632568359375f + (1.7999999523162841796875f * r_2))) + (r_2 * 17.0f))));
                float halfLen = 1.75f;
                float halfWid = 0.89999997615814208984375f * tumble;
                float u = rd.x / halfLen;
                float bend = (((u * u) - 0.3499999940395355224609375f) * 0.2800000011920928955078125f) * halfWid;
                float v = (rd.y - bend) / max(halfWid, 0.2800000011920928955078125f);
                float profile = sqrt(max(0.0f, 1.0f - (u * u))) * (1.0f - (0.25f * u));
                float edgeSoft = 0.319999992847442626953125f / max(scale, 0.5f);
                if (abs(u) < 1.0f)
                {
                    _3786 = 1.0f - smoothstep(-edgeSoft, edgeSoft, abs(v) - profile);
                }
                else
                {
                    _3786 = 0.0f;
                }
                float mask = _3786;
                float alpha = (mask * 0.7200000286102294921875f) * exposed;
                if (alpha > 0.00999999977648258209228515625f)
                {
                    if (r_2 < (leafDensity * 0.4000000059604644775390625f))
                    {
                        _3814 = float3(0.86000001430511474609375f, 0.660000026226043701171875f, 0.17000000178813934326171875f);
                    }
                    else
                    {
                        bool3 _3828 = (r_2 < (leafDensity * 0.75f)).xxx;
                        _3814 = float3(_3828.x ? float3(0.819999992847442626953125f, 0.4000000059604644775390625f, 0.10999999940395355224609375f).x : float3(0.680000007152557373046875f, 0.2800000011920928955078125f, 0.100000001490116119384765625f).x, _3828.y ? float3(0.819999992847442626953125f, 0.4000000059604644775390625f, 0.10999999940395355224609375f).y : float3(0.680000007152557373046875f, 0.2800000011920928955078125f, 0.100000001490116119384765625f).y, _3828.z ? float3(0.819999992847442626953125f, 0.4000000059604644775390625f, 0.10999999940395355224609375f).z : float3(0.680000007152557373046875f, 0.2800000011920928955078125f, 0.100000001490116119384765625f).z);
                    }
                    float3 leafCol = _3814;
                    float leafShade = lerp(0.7599999904632568359375f, 1.12000000476837158203125f, clamp((0.5f - (0.3499999940395355224609375f * v)) + (0.25f * u), 0.0f, 1.0f));
                    airborne += float4(((leafCol * leafShade) * dayDim) * alpha, alpha);
                }
            }
        }
        else
        {
            bool _3860 = ambient_season.x < 0.5f;
            bool _3866;
            if (_3860)
            {
                _3866 = ambient_seasonExtra.y > 0.449999988079071044921875f;
            }
            else
            {
                _3866 = _3860;
            }
            bool _3872;
            if (_3866)
            {
                _3872 = ambient_weather.w < 0.5f;
            }
            else
            {
                _3872 = _3866;
            }
            if (_3872)
            {
                float petalDensity = clamp((ambient_seasonExtra.y - 0.449999988079071044921875f) * 0.2199999988079071044921875f, 0.0f, 0.119999997317790985107421875f);
                float cell_3 = 112.0f;
                float2 moved_3 = (q - float2(26.0f * time, 14.0f * time)) + 71.0f.xx;
                float2 at_3 = floor(moved_3 / cell_3.xx);
                float2 param_33 = at_3 + 61.0f.xx;
                float r_3 = hash12(param_33);
                if (r_3 <= petalDensity)
                {
                    float2 param_34 = at_3 + 3.0f.xx;
                    float2 param_35 = at_3 + 11.0f.xx;
                    float2 centre_3 = ((at_3 + 0.25f.xx) + (float2(hash12(param_34), hash12(param_35)) * 0.5f)) * cell_3;
                    centre_3.x += (7.0f * sin((time * (1.0f + r_3)) + (r_3 * 27.0f)));
                    centre_3.y += (4.0f * cos((time * (1.39999997615814208984375f + r_3)) + (r_3 * 17.0f)));
                    float alpha_1 = (((1.0f - smoothstep(0.699999988079071044921875f, 1.4500000476837158203125f, length(moved_3 - centre_3))) * 0.64999997615814208984375f) * (1.0f - ambient_weather.w)) * exposed;
                    airborne += float4(float3(0.980000019073486328125f, 0.87999999523162841796875f, 0.920000016689300537109375f) * alpha_1, alpha_1);
                }
            }
        }
        if (fireflies > 0.0500000007450580596923828125f)
        {
            float cell_4 = 320.0f;
            float2 moved_4 = q + float2(149.0f, 83.0f);
            float2 at_4 = floor(moved_4 / cell_4.xx);
            float2 param_36 = at_4 + 29.0f.xx;
            float r_4 = hash12(param_36);
            if (r_4 <= (fireflies * 0.054999999701976776123046875f))
            {
                float2 param_37 = at_4 + 5.0f.xx;
                float2 param_38 = at_4 + 17.0f.xx;
                float2 clump = ((at_4 + 0.25f.xx) + (float2(hash12(param_37), hash12(param_38)) * 0.5f)) * cell_4;
                if (length(moved_4 - clump) < 30.0f)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        float fk = float(k);
                        float2 param_39 = at_4 + float2(fk * 11.30000019073486328125f, 3.7000000476837158203125f);
                        float h1 = hash12(param_39);
                        float2 param_40 = at_4 + float2(7.099999904632568359375f, fk * 17.8999996185302734375f);
                        float h2 = hash12(param_40);
                        float2 pos = clump + float2(((h1 - 0.5f) * 18.0f) + (4.5f * sin(((time * (0.64999997615814208984375f + (0.449999988079071044921875f * h2))) + (fk * 2.099999904632568359375f)) + (h1 * 19.0f))), ((h2 - 0.5f) * 12.0f) + (3.2000000476837158203125f * cos(((time * (0.800000011920928955078125f + (0.3499999940395355224609375f * h1))) + (fk * 3.400000095367431640625f)) + (h2 * 13.0f))));
                        float pulse = pow(0.5f + (0.5f * sin(((time * (0.949999988079071044921875f + (0.699999988079071044921875f * h1))) + (fk * 1.89999997615814208984375f)) + (h2 * 29.0f))), 4.19999980926513671875f);
                        float dist = length(moved_4 - pos);
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
