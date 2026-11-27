static const float _10617[5] = { 0.0625f, 0.25f, 0.375f, 0.25f, 0.0625f };
static const float _10711[3] = { -8.5f, -3.5f, 2.0f };
static const float3 _11061[8] = { float3(0.2199999988079071044921875f, -0.100000001490116119384765625f, 0.039999999105930328369140625f), float3(0.23000000417232513427734375f, 0.100000001490116119384765625f, 0.039999999105930328369140625f), float3(0.25f, 0.0f, 0.14000000059604644775390625f), float3(0.319999992847442626953125f, 0.0f, 0.07999999821186065673828125f), float3(0.2800000011920928955078125f, 0.0f, 0.3400000035762786865234375f), float3(0.449999988079071044921875f, 0.0f, 0.5f), float3(0.300000011920928955078125f, -0.14000000059604644775390625f, -0.2199999988079071044921875f), float3(0.300000011920928955078125f, 0.14000000059604644775390625f, -0.2199999988079071044921875f) };
static const float _11158[8] = { 1.0f, 1.0f, 0.85000002384185791015625f, 0.60000002384185791015625f, 0.7200000286102294921875f, 0.5f, 0.62000000476837158203125f, 0.62000000476837158203125f };

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
    float4 ambient_lamps[16] : packoffset(c12);
    float4 ambient_skyExtra : packoffset(c28);
    float4 ambient_shadowView : packoffset(c29);
    float4 ambient_dynShadowBounds : packoffset(c30);
    float4 ambient_voxShadowBounds : packoffset(c31);
    float4 ambient_roofShadowBounds : packoffset(c32);
    float4 ambient_casterZBounds : packoffset(c33);
};

Texture2D<float4> depthMap : register(t0, space2);
SamplerState _depthMap_sampler : register(s0, space2);
Texture2D<float4> groundMap : register(t1, space2);
SamplerState _groundMap_sampler : register(s1, space2);
Texture2D<float4> indoorMap : register(t3, space2);
SamplerState _indoorMap_sampler : register(s3, space2);
Texture2D<float4> overheadMap : register(t6, space2);
SamplerState _overheadMap_sampler : register(s6, space2);
Texture2D<float4> worldDepthMap : register(t7, space2);
SamplerState _worldDepthMap_sampler : register(s7, space2);
Texture2D<float4> worldBackDepthMap : register(t8, space2);
SamplerState _worldBackDepthMap_sampler : register(s8, space2);
Texture2D<float4> heightMap : register(t2, space2);
SamplerState _heightMap_sampler : register(s2, space2);
Texture2D<float4> voxelMap : register(t9, space2);
SamplerState _voxelMap_sampler : register(s9, space2);
Texture2D<float4> bounceMap : register(t12, space2);
SamplerState _bounceMap_sampler : register(s12, space2);
Texture2D<float4> simMaskMap : register(t10, space2);
SamplerState _simMaskMap_sampler : register(s10, space2);
Texture2D<float4> liftMap : register(t5, space2);
SamplerState _liftMap_sampler : register(s5, space2);
Texture2D<float4> footMap : register(t4, space2);
SamplerState _footMap_sampler : register(s4, space2);
Texture2D<float4> sunShadowMap : register(t13, space2);
SamplerState _sunShadowMap_sampler : register(s13, space2);
Texture2D<float4> sceneColorMap : register(t11, space2);
SamplerState _sceneColorMap_sampler : register(s11, space2);

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

int voxelAoRows(int2 oSize)
{
    int aoSize = max(1, (oSize.x / 4));
    return max(1, (((oSize.y - oSize.x) - 256) / (512 + aoSize)));
}

float3 lotPoint(float2 scene, float key, bool terrain, float2 frame)
{
    float2 local = scene - frame;
    float _407;
    if (terrain)
    {
        _407 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _407 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _407;
    float _431;
    if (terrain)
    {
        _431 = key;
    }
    else
    {
        _431 = key - (0.800000011920928955078125f * h);
    }
    float s = _431;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

float groundAt(float2 pixel)
{
    int2 ip = clamp(int2(floor(pixel)), int2(0, 0), max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0)));
    float ground = groundMap.Load(int3(ip, 0)).x;
    float _628;
    if (ground < 1.0f)
    {
        _628 = (((0.62000000476837158203125f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f;
    }
    else
    {
        _628 = -100000.0f;
    }
    return _628;
}

float terrainBaseClamped(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    bool _1615 = size.x <= 0.0f;
    bool _1622;
    if (!_1615)
    {
        _1622 = size.y <= 0.0f;
    }
    else
    {
        _1622 = _1615;
    }
    if (_1622)
    {
        return fallback;
    }
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1635;
    if (orientation == 1)
    {
        _1635 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1649;
        if (orientation == 2)
        {
            _1649 = size - _point;
        }
        else
        {
            float2 _1658;
            if (orientation == 3)
            {
                _1658 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1658 = _point;
            }
            _1649 = _1658;
        }
        _1635 = _1649;
    }
    float2 source = _1635;
    uint _1677_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1677_dummy_parameter));
    bool _1684 = mapSize.y >= (mapSize.x * 2);
    bool _1690;
    if (_1684)
    {
        _1690 = mapSize.x > 1;
    }
    else
    {
        _1690 = _1684;
    }
    int2 _1691;
    if (_1690)
    {
        _1691 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1691 = mapSize;
    }
    int2 baseSize = _1691;
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

float terrainBaseAt(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1480;
    if (orientation == 1)
    {
        _1480 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1494;
        if (orientation == 2)
        {
            _1494 = size - _point;
        }
        else
        {
            float2 _1503;
            if (orientation == 3)
            {
                _1503 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1503 = _point;
            }
            _1494 = _1503;
        }
        _1480 = _1494;
    }
    float2 source = _1480;
    bool _1521 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _1529;
    if (!_1521)
    {
        _1529 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _1529 = _1521;
    }
    if (_1529)
    {
        return fallback;
    }
    uint _1537_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1537_dummy_parameter));
    bool _1544 = mapSize.y >= (mapSize.x * 2);
    bool _1550;
    if (_1544)
    {
        _1550 = mapSize.x > 1;
    }
    else
    {
        _1550 = _1544;
    }
    int2 _1551;
    if (_1550)
    {
        _1551 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1551 = mapSize;
    }
    int2 baseSize = _1551;
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

float riseAt(float2 pixel, float z)
{
    float2 param = pixel;
    float ground = groundAt(param);
    float2 param_1 = pixel + float2(0.0f, 4.0f);
    float below = groundAt(param_1);
    if ((ground < (-10000.0f)) || (below < (-10000.0f)))
    {
        return 0.0f;
    }
    float slope = ((below - ground) * ambient_view.z) / 4.0f;
    float _1790;
    if (slope > 0.100000001490116119384765625f)
    {
        _1790 = max(0.0f, (z - ground) / ((slope * 4.0f) / 3.0f));
    }
    else
    {
        _1790 = 0.0f;
    }
    return _1790;
}

int indoorBandH(int2 size)
{
    if (size.x <= 1)
    {
        return max(1, (size.y / 10));
    }
    int orient = int(ambient_clouds.z + 0.5f);
    int _663;
    if ((orient & 1) == 0)
    {
        _663 = int(ambient_drift.w + 0.5f);
    }
    else
    {
        _663 = int(ambient_drift.z + 0.5f);
    }
    int hTiles = _663;
    int margin = int(ambient_frame.w + 0.5f);
    int _684;
    if (hTiles > 0)
    {
        _684 = hTiles + (2 * margin);
    }
    else
    {
        _684 = size.x;
    }
    return _684;
}

int indoorStories()
{
    uint _702_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _702_dummy_parameter));
    int2 param = size;
    int bandH = indoorBandH(param);
    return max(1, (size.y / max(1, (5 * bandH))));
}

int maskCatFast(int2 at, int cat, int row, int2 size, int bandH, int stories)
{
    bool _793 = (row < 0) || (row >= stories);
    bool _800;
    if (!_793)
    {
        _800 = at.x < 0;
    }
    else
    {
        _800 = _793;
    }
    bool _807;
    if (!_800)
    {
        _807 = at.y < 0;
    }
    else
    {
        _807 = _800;
    }
    bool _816;
    if (!_807)
    {
        _816 = at.x >= size.x;
    }
    else
    {
        _816 = _807;
    }
    bool _824;
    if (!_816)
    {
        _824 = at.y >= bandH;
    }
    else
    {
        _824 = _816;
    }
    if (_824)
    {
        return 0;
    }
    int band = (cat * stories) + row;
    bool _835 = band < 0;
    bool _846;
    if (!_835)
    {
        _846 = ((band + 1) * bandH) > size.y;
    }
    else
    {
        _846 = _835;
    }
    if (_846)
    {
        return 0;
    }
    return int((indoorMap.Load(int3(int2(at.x, at.y + (band * bandH)), 0)).x * 255.0f) + 0.5f);
}

int maskCatAt(int2 at, int cat, int row)
{
    uint _871_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _871_dummy_parameter));
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

float floorAt(int2 at, int row, float fallback)
{
    int2 param = at;
    int param_1 = 1;
    int param_2 = row;
    int code = maskCatAt(param, param_1, param_2);
    float _908;
    if (code == 0)
    {
        _908 = fallback;
    }
    else
    {
        _908 = (ambient_contact.w + (float(row) * 2.9500000476837158203125f)) + (float(code - 1) / 8.0f);
    }
    return _908;
}

float matchArchWall(float3 rawHere, float2 sceneXY, float rawKey, float nSurfX, out float3 outWallPos, out float2 outWallN)
{
    outWallPos = rawHere;
    outWallN = 0.0f.xx;
    uint _8733_dummy_parameter;
    int2 mSize = int2(spvTextureSize(indoorMap, uint(0), _8733_dummy_parameter));
    if (mSize.x <= 1)
    {
        return 0.0f;
    }
    int2 param = mSize;
    int bandH = indoorBandH(param);
    int stories = max(1, (mSize.y / max(1, (5 * bandH))));
    float2 param_1 = sceneXY;
    float param_2 = rawKey + 0.14000000059604644775390625f;
    bool param_3 = false;
    float2 param_4 = ambient_frame.xy;
    float3 shifted = lotPoint(param_1, param_2, param_3, param_4);
    float2 atS = shifted.xy + ambient_frame.w.xx;
    float2 atR = rawHere.xy + ambient_frame.w.xx;
    int2 baseCell = int2(floor(atS - 0.5f.xx));
    float bestW = 0.0f;
    float bestScore = -100000.0f;
    float2 bestN = 0.707106769084930419921875f.xx;
    float2 snappedAt = atS;
    float hasNx = step(0.1500000059604644775390625f, abs(nSurfX));
    float clampedNx = clamp(nSurfX, -0.75f, 0.75f);
    float _8865;
    int _8902;
    int _8909;
    int _8931;
    float _8952;
    float _9043;
    float _9063;
    float2 _9083;
    float2 _9090;
    float2 _9101;
    float2 _9117;
    float2 _9128;
    float2 _9135;
    float _9231;
    float _9407;
    float _9573;
    for (int cy = 0; cy <= 1; cy++)
    {
        for (int cx = 0; cx <= 1; cx++)
        {
            int2 cell = baseCell + int2(cx, cy);
            bool _8822 = cell.x < 0;
            bool _8829;
            if (!_8822)
            {
                _8829 = cell.y < 0;
            }
            else
            {
                _8829 = _8822;
            }
            bool _8838;
            if (!_8829)
            {
                _8838 = cell.x >= mSize.x;
            }
            else
            {
                _8838 = _8829;
            }
            bool _8846;
            if (!_8838)
            {
                _8846 = cell.y >= bandH;
            }
            else
            {
                _8846 = _8838;
            }
            if (_8846)
            {
                continue;
            }
            int2 param_5 = cell;
            int param_6 = 1;
            int param_7 = 0;
            int2 param_8 = mSize;
            int param_9 = bandH;
            int param_10 = stories;
            int baseCode = maskCatFast(param_5, param_6, param_7, param_8, param_9, param_10);
            if (baseCode == 0)
            {
                _8865 = shifted.z;
            }
            else
            {
                _8865 = ambient_contact.w + (float(baseCode - 1) / 8.0f);
            }
            float base0 = _8865;
            int rBase = clamp(int(floor((shifted.z - base0) / 2.9500000476837158203125f)), 0, stories - 1);
            int wBits = 0;
            for (int rOff = 0; rOff <= 2; rOff++)
            {
                if (rOff == 0)
                {
                    _8902 = rBase;
                }
                else
                {
                    if (rOff == 1)
                    {
                        _8909 = rBase - 1;
                    }
                    else
                    {
                        _8909 = rBase + 1;
                    }
                    _8902 = _8909;
                }
                int r = _8902;
                if ((r < 0) || (r >= stories))
                {
                    continue;
                }
                if (r == 0)
                {
                    _8931 = baseCode;
                }
                else
                {
                    int2 param_11 = cell;
                    int param_12 = 1;
                    int param_13 = r;
                    int2 param_14 = mSize;
                    int param_15 = bandH;
                    int param_16 = stories;
                    _8931 = maskCatFast(param_11, param_12, param_13, param_14, param_15, param_16);
                }
                int rowCode = _8931;
                if (rowCode == 0)
                {
                    _8952 = base0 + (float(r) * 2.9500000476837158203125f);
                }
                else
                {
                    _8952 = (ambient_contact.w + (float(r) * 2.9500000476837158203125f)) + (float(rowCode - 1) / 8.0f);
                }
                float floorZ = _8952;
                bool _8977 = shifted.z < (floorZ - 0.1599999964237213134765625f);
                bool _8987;
                if (!_8977)
                {
                    _8987 = shifted.z > ((floorZ + 2.9500000476837158203125f) + 0.07999999821186065673828125f);
                }
                else
                {
                    _8987 = _8977;
                }
                if (_8987)
                {
                    continue;
                }
                int2 param_17 = cell;
                int param_18 = 3;
                int param_19 = r;
                int2 param_20 = mSize;
                int param_21 = bandH;
                int param_22 = stories;
                wBits |= maskCatFast(param_17, param_18, param_19, param_20, param_21, param_22);
            }
            if (wBits == 0)
            {
                continue;
            }
            float2 cMin = float2(cell);
            float2 cMax = cMin + 1.0f.xx;
            for (int d = 0; d < 4; d++)
            {
                if ((wBits & (1 << d)) == 0)
                {
                    continue;
                }
                bool2 _9038 = (d <= 1).xx;
                float2 wn = float2(_9038.x ? float2(1.0f, 0.0f).x : float2(0.0f, 1.0f).x, _9038.y ? float2(1.0f, 0.0f).y : float2(0.0f, 1.0f).y);
                if (d <= 1)
                {
                    _9043 = clamp(atS.y - cMin.y, 0.0f, 1.0f);
                }
                else
                {
                    _9043 = clamp(atS.x - cMin.x, 0.0f, 1.0f);
                }
                float pS = _9043;
                if (d <= 1)
                {
                    _9063 = clamp(atR.y - cMin.y, 0.0f, 1.0f);
                }
                else
                {
                    _9063 = clamp(atR.x - cMin.x, 0.0f, 1.0f);
                }
                float pR = _9063;
                if (d == 0)
                {
                    _9083 = cMin;
                }
                else
                {
                    if (d == 1)
                    {
                        _9090 = float2(cMax.x, cMin.y);
                    }
                    else
                    {
                        if (d == 2)
                        {
                            _9101 = cMin;
                        }
                        else
                        {
                            _9101 = float2(cMin.x, cMax.y);
                        }
                        _9090 = _9101;
                    }
                    _9083 = _9090;
                }
                float2 segA = _9083;
                if (d == 0)
                {
                    _9117 = float2(cMin.x, cMax.y);
                }
                else
                {
                    if (d == 1)
                    {
                        _9128 = cMax;
                    }
                    else
                    {
                        if (d == 2)
                        {
                            _9135 = float2(cMax.x, cMin.y);
                        }
                        else
                        {
                            _9135 = cMax;
                        }
                        _9128 = _9135;
                    }
                    _9117 = _9128;
                }
                float2 segB = _9117;
                float2 clS = lerp(segA, segB, pS.xx);
                float2 clR = lerp(segA, segB, pR.xx);
                float dS = length(atS - clS);
                float dR = length(atR - clR);
                bool useR = (dot(atR - clR, wn) >= (-0.0199999995529651641845703125f)) && (dR < dS);
                float dist = useR ? dR : dS;
                float w = 1.0f - smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, dist);
                if (w > 0.0f)
                {
                    bool2 _9199 = useR.xx;
                    float2 closest = float2(_9199.x ? clR.x : clS.x, _9199.y ? clR.y : clS.y);
                    float pSeg = useR ? pR : pS;
                    float2 segMid = (segA + segB) * 0.5f;
                    float camDelta = (segMid.x + segMid.y) - (closest.x + closest.y);
                    if ((pSeg <= 0.00200000009499490261077880859375f) || (pSeg >= 0.99800002574920654296875f))
                    {
                        _9231 = (camDelta < (-0.20000000298023223876953125f)) ? 0.449999988079071044921875f : 0.14000000059604644775390625f;
                    }
                    else
                    {
                        _9231 = 0.0f;
                    }
                    float endPen = _9231;
                    float expNx = (wn.x - wn.y) * 0.4799999892711639404296875f;
                    float nxBonus = (hasNx * 0.119999997317790985107421875f) * (1.0f - abs(clampedNx - expNx));
                    float score = ((1.0f - (dist / 0.1599999964237213134765625f)) - endPen) + nxBonus;
                    bestW = max(bestW, w);
                    if (score > bestScore)
                    {
                        bestScore = score;
                        bestN = wn;
                        snappedAt = closest + (wn * 0.0350000001490116119384765625f);
                    }
                }
            }
            if ((wBits & 32) != 0)
            {
                float2 wn_1 = 0.707106769084930419921875f.xx;
                float2 segA_1 = float2(cMin.x, cMax.y);
                float2 segB_1 = float2(cMax.x, cMin.y);
                float pS_1 = clamp(0.5f * ((atS.x - cMin.x) - (atS.y - cMax.y)), 0.0f, 1.0f);
                float pR_1 = clamp(0.5f * ((atR.x - cMin.x) - (atR.y - cMax.y)), 0.0f, 1.0f);
                float2 clS_1 = lerp(segA_1, segB_1, pS_1.xx);
                float2 clR_1 = lerp(segA_1, segB_1, pR_1.xx);
                float dS_1 = length(atS - clS_1);
                float dR_1 = length(atR - clR_1);
                bool useR_1 = (dot(atR - clR_1, wn_1) >= (-0.0199999995529651641845703125f)) && (dR_1 < dS_1);
                float dist_1 = useR_1 ? dR_1 : dS_1;
                float w_1 = 1.0f - smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, dist_1);
                if (w_1 > 0.0f)
                {
                    bool2 _9377 = useR_1.xx;
                    float2 closest_1 = float2(_9377.x ? clR_1.x : clS_1.x, _9377.y ? clR_1.y : clS_1.y);
                    float pSeg_1 = useR_1 ? pR_1 : pS_1;
                    float2 segMid_1 = (segA_1 + segB_1) * 0.5f;
                    float camDelta_1 = (segMid_1.x + segMid_1.y) - (closest_1.x + closest_1.y);
                    if ((pSeg_1 <= 0.00200000009499490261077880859375f) || (pSeg_1 >= 0.99800002574920654296875f))
                    {
                        _9407 = (camDelta_1 < (-0.20000000298023223876953125f)) ? 0.449999988079071044921875f : 0.14000000059604644775390625f;
                    }
                    else
                    {
                        _9407 = 0.0f;
                    }
                    float endPen_1 = _9407;
                    float nxBonus_1 = (hasNx * 0.119999997317790985107421875f) * (1.0f - abs(clampedNx));
                    float score_1 = ((1.0f - (dist_1 / 0.1599999964237213134765625f)) - endPen_1) + nxBonus_1;
                    bestW = max(bestW, w_1);
                    if (score_1 > bestScore)
                    {
                        bestScore = score_1;
                        bestN = wn_1;
                        snappedAt = closest_1 + (wn_1 * 0.0350000001490116119384765625f);
                    }
                }
            }
            if ((wBits & 16) != 0)
            {
                float pS_2 = clamp(0.5f * ((atS.x - cMin.x) + (atS.y - cMin.y)), 0.0f, 1.0f);
                float pR_2 = clamp(0.5f * ((atR.x - cMin.x) + (atR.y - cMin.y)), 0.0f, 1.0f);
                float2 clS_2 = cMin + pS_2.xx;
                float2 clR_2 = cMin + pR_2.xx;
                float side = ((atS.x - cMin.x) >= (atS.y - cMin.y)) ? 1.0f : (-1.0f);
                float2 wn_2 = float2(0.707106769084930419921875f * side, (-0.707106769084930419921875f) * side);
                float dS_2 = length(atS - clS_2);
                float dR_2 = length(atR - clR_2);
                bool useR_2 = (dot(atR - clR_2, wn_2) >= (-0.0199999995529651641845703125f)) && (dR_2 < dS_2);
                float dist_2 = useR_2 ? dR_2 : dS_2;
                float w_2 = 1.0f - smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, dist_2);
                if (w_2 > 0.0f)
                {
                    bool2 _9545 = useR_2.xx;
                    float2 closest_2 = float2(_9545.x ? clR_2.x : clS_2.x, _9545.y ? clR_2.y : clS_2.y);
                    float pSeg_2 = useR_2 ? pR_2 : pS_2;
                    float2 segMid_2 = cMin + 0.5f.xx;
                    float camDelta_2 = (segMid_2.x + segMid_2.y) - (closest_2.x + closest_2.y);
                    if ((pSeg_2 <= 0.00200000009499490261077880859375f) || (pSeg_2 >= 0.99800002574920654296875f))
                    {
                        _9573 = (camDelta_2 < (-0.20000000298023223876953125f)) ? 0.449999988079071044921875f : 0.14000000059604644775390625f;
                    }
                    else
                    {
                        _9573 = 0.0f;
                    }
                    float endPen_2 = _9573;
                    float score_2 = (1.0f - (dist_2 / 0.1599999964237213134765625f)) - endPen_2;
                    bestW = max(bestW, w_2);
                    if (score_2 > bestScore)
                    {
                        bestScore = score_2;
                        bestN = wn_2;
                        snappedAt = closest_2 + (wn_2 * 0.0350000001490116119384765625f);
                    }
                }
            }
        }
    }
    if (bestW <= 0.001000000047497451305389404296875f)
    {
        return 0.0f;
    }
    outWallN = bestN;
    outWallPos = float3(snappedAt - ambient_frame.w.xx, shifted.z);
    return bestW;
}

float sampleHullDilated(float2 op, float key, int yOffset, int2 sliceMax, float pad)
{
    int2 center = int2(floor(op));
    float best = 0.0f;
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            int2 c = clamp(center + int2(dx, dy), int2(0, 0), sliceMax);
            int4 r = int4((voxelMap.Load(int3(int2(c.x, c.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
            int f = (r.x * 256) + r.y;
            if (f == 0)
            {
                continue;
            }
            float frontKey = (float(f) / 256.0f) - 16.0f;
            float backKey = (float((r.z * 256) + r.w) / 256.0f) - 16.0f;
            float v = smoothstep(-pad, 0.0599999986588954925537109375f, frontKey - key) * smoothstep(-pad, 0.0599999986588954925537109375f, key - backKey);
            best = max(best, v);
        }
    }
    return best;
}

float dualViewHullSolid(float3 q, int2 oSize, int halfH, float topMarginHalf, int2 sliceMax, float2 lotSz, float pad)
{
    float2 op0 = float2(((q.x - q.y) + lotSz.x) * 16.0f, (((q.x + q.y) * 8.0f) - (q.z * 20.0f)) + topMarginHalf);
    bool _3727 = any(bool2(op0.x < 0.0f.xx.x, op0.y < 0.0f.xx.y));
    bool _3737;
    if (!_3727)
    {
        _3737 = op0.x >= float(oSize.x);
    }
    else
    {
        _3737 = _3727;
    }
    bool _3746;
    if (!_3737)
    {
        _3746 = op0.y >= float(halfH);
    }
    else
    {
        _3746 = _3737;
    }
    if (_3746)
    {
        return 0.0f;
    }
    float2 param = op0;
    float param_1 = (q.x + q.y) + (0.800000011920928955078125f * q.z);
    int param_2 = 0;
    int2 param_3 = sliceMax;
    float param_4 = pad;
    float in0 = sampleHullDilated(param, param_1, param_2, param_3, param_4);
    if (in0 <= 0.00999999977648258209228515625f)
    {
        return 0.0f;
    }
    float3 qB = float3(lotSz.y - q.y, q.x, q.z);
    float2 op1 = float2(((qB.x - qB.y) + lotSz.x) * 16.0f, (((qB.x + qB.y) * 8.0f) - (qB.z * 20.0f)) + topMarginHalf);
    bool _3810 = any(bool2(op1.x < 0.0f.xx.x, op1.y < 0.0f.xx.y));
    bool _3820;
    if (!_3810)
    {
        _3820 = op1.x >= float(oSize.x);
    }
    else
    {
        _3820 = _3810;
    }
    bool _3829;
    if (!_3820)
    {
        _3829 = op1.y >= float(halfH);
    }
    else
    {
        _3829 = _3820;
    }
    if (_3829)
    {
        return 0.0f;
    }
    float2 param_5 = op1;
    float param_6 = (qB.x + qB.y) + (0.800000011920928955078125f * qB.z);
    int param_7 = halfH;
    int2 param_8 = sliceMax;
    float param_9 = pad;
    float in1 = sampleHullDilated(param_5, param_6, param_7, param_8, param_9);
    return min(in0, in1);
}

float indoors(float3 lot)
{
    uint _932_dummy_parameter;
    int2 mSize = int2(spvTextureSize(indoorMap, uint(0), _932_dummy_parameter));
    int2 param = mSize;
    int bandH = indoorBandH(param);
    int stories = max(1, (mSize.y / max(1, (5 * bandH))));
    float2 cell = (lot.xy + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.20000000298023223876953125f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _985;
    float _998;
    float2 _1110;
    float2 _1118;
    for (int i = 0; i < 4; i++)
    {
        if ((i & 1) == 1)
        {
            _985 = f.x;
        }
        else
        {
            _985 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _998 = f.y;
        }
        else
        {
            _998 = 1.0f - f.y;
        }
        float weight = _985 * _998;
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
            _1110 = float2(1.0f, -1.0f);
        }
        else
        {
            if (part == 2)
            {
                _1118 = float2(-1.0f, 1.0f);
            }
            else
            {
                bool2 _1128 = (part == 3).xx;
                _1118 = float2(_1128.x ? (-1.0f).xx.x : 1.0f.xx.x, _1128.y ? (-1.0f).xx.y : 1.0f.xx.y);
            }
            _1110 = _1118;
        }
        float2 toward = _1110;
        sum += (weight * smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((lot.xy + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward)));
    }
    return sum;
}

int storyRowAt(int2 cell, float z, float fallbackBase, float margin)
{
    int stories = indoorStories();
    int2 param = cell;
    int param_1 = 0;
    float param_2 = fallbackBase;
    float base0 = floorAt(param, param_1, param_2);
    return clamp(int(floor(((z - base0) + margin) / 2.9500000476837158203125f)), 0, stories - 1);
}

int effectiveRoomAt(int2 cell, int row, float2 localU)
{
    int2 param = cell;
    int param_1 = 0;
    int param_2 = row;
    int code = maskCatAt(param, param_1, param_2);
    int room = code >> 1;
    if (room == 0)
    {
        return 0;
    }
    int2 param_3 = cell;
    int param_4 = 2;
    int param_5 = row;
    int part = maskCatAt(param_3, param_4, param_5) & 7;
    if (part == 0)
    {
        return room;
    }
    float2 _2438;
    if (part == 1)
    {
        _2438 = float2(1.0f, -1.0f);
    }
    else
    {
        float2 _2444;
        if (part == 2)
        {
            _2444 = float2(-1.0f, 1.0f);
        }
        else
        {
            bool2 _2450 = (part == 3).xx;
            _2444 = float2(_2450.x ? (-1.0f).xx.x : 1.0f.xx.x, _2450.y ? (-1.0f).xx.y : 1.0f.xx.y);
        }
        _2438 = _2444;
    }
    float2 toward = _2438;
    return (dot(localU - 0.5f.xx, toward) >= 0.0f) ? room : 0;
}

float floorWallAO(float3 here)
{
    float2 at = here.xy + ambient_frame.w.xx;
    int2 cell = int2(floor(at));
    float2 u = frac(at);
    int2 param = cell;
    float param_1 = here.z;
    float param_2 = here.z;
    float param_3 = 0.1500000059604644775390625f;
    int row = storyRowAt(param, param_1, param_2, param_3);
    int2 param_4 = cell;
    int param_5 = 3;
    int param_6 = row;
    int wallEdges = maskCatAt(param_4, param_5, param_6);
    int2 param_7 = cell;
    int param_8 = 4;
    int param_9 = row;
    int fenceEdges = maskCatAt(param_7, param_8, param_9);
    int2 param_10 = cell;
    int param_11 = row;
    float2 param_12 = u;
    int rHere = effectiveRoomAt(param_10, param_11, param_12);
    uint _8121_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _8121_dummy_parameter)));
    float occ = 0.0f;
    float _8135;
    float _8143;
    float _8152;
    int2 _8250;
    int2 _8256;
    float2 _8269;
    float2 _8278;
    float2 _8287;
    float2 _8328;
    float2 _8337;
    float2 _8346;
    for (int d = 0; d < 4; d++)
    {
        if (d == 0)
        {
            _8135 = u.x;
        }
        else
        {
            if (d == 1)
            {
                _8143 = 1.0f - u.x;
            }
            else
            {
                if (d == 2)
                {
                    _8152 = u.y;
                }
                else
                {
                    _8152 = 1.0f - u.y;
                }
                _8143 = _8152;
            }
            _8135 = _8143;
        }
        float dist = _8135;
        if (dist >= 0.560000002384185791015625f)
        {
            continue;
        }
        int bit = 1 << d;
        if ((wallEdges & bit) != 0)
        {
            float crease = exp((-dist) / 0.0949999988079071044921875f) * (1.0f - smoothstep(0.2800000011920928955078125f, 0.560000002384185791015625f, dist));
            float soft = 1.0f - (dist / 0.560000002384185791015625f);
            soft *= soft;
            occ += ((0.579999983310699462890625f * crease) + (0.519999980926513671875f * soft));
            continue;
        }
        if ((fenceEdges & bit) != 0)
        {
            if (dist < 0.300000011920928955078125f)
            {
                float crease_1 = exp((-dist) / 0.07500000298023223876953125f) * (1.0f - smoothstep(0.1599999964237213134765625f, 0.300000011920928955078125f, dist));
                float soft_1 = 1.0f - (dist / 0.300000011920928955078125f);
                soft_1 *= soft_1;
                occ += (0.680000007152557373046875f * ((0.60000002384185791015625f * crease_1) + (0.4799999892711639404296875f * soft_1)));
            }
            continue;
        }
        if ((wallEdges == 0) && (fenceEdges == 0))
        {
            if (d == 0)
            {
                _8250 = int2(-1, 0);
            }
            else
            {
                if (d == 1)
                {
                    _8256 = int2(1, 0);
                }
                else
                {
                    bool2 _8262 = (d == 2).xx;
                    _8256 = int2(_8262.x ? int2(0, -1).x : int2(0, 1).x, _8262.y ? int2(0, -1).y : int2(0, 1).y);
                }
                _8250 = _8256;
            }
            int2 _step = _8250;
            if (d == 0)
            {
                _8269 = float2(0.9900000095367431640625f, u.y);
            }
            else
            {
                if (d == 1)
                {
                    _8278 = float2(0.00999999977648258209228515625f, u.y);
                }
                else
                {
                    if (d == 2)
                    {
                        _8287 = float2(u.x, 0.9900000095367431640625f);
                    }
                    else
                    {
                        _8287 = float2(u.x, 0.00999999977648258209228515625f);
                    }
                    _8278 = _8287;
                }
                _8269 = _8278;
            }
            float2 nbrU = _8269;
            int2 param_13 = cell + _step;
            int param_14 = row;
            float2 param_15 = nbrU;
            int rNbr = effectiveRoomAt(param_13, param_14, param_15);
            bool _8312 = rHere == rNbr;
            bool _8321;
            if (!_8312)
            {
                _8321 = (rHere == 0) && (rNbr == 0);
            }
            else
            {
                _8321 = _8312;
            }
            if (_8321)
            {
                continue;
            }
            if (d == 0)
            {
                _8328 = float2(0.0f, u.y);
            }
            else
            {
                if (d == 1)
                {
                    _8337 = float2(1.0f, u.y);
                }
                else
                {
                    if (d == 2)
                    {
                        _8346 = float2(u.x, 0.0f);
                    }
                    else
                    {
                        _8346 = float2(u.x, 1.0f);
                    }
                    _8337 = _8346;
                }
                _8328 = _8337;
            }
            float2 edgeLocal = _8328;
            float2 edgePos = float2(cell) + edgeLocal;
            float2 dirF = float2(_step);
            float hA = ((0.5f - heightMap.Sample(_heightMap_sampler, ((edgePos + (dirF * 0.0500000007450580596923828125f)) * ambient_frame.z) / gridSize).x) * 128.0f) - here.z;
            float hB = ((0.5f - heightMap.Sample(_heightMap_sampler, ((edgePos - (dirF * 0.0500000007450580596923828125f)) * ambient_frame.z) / gridSize).x) * 128.0f) - here.z;
            float wallPresent = smoothstep(0.07999999821186065673828125f, 0.2800000011920928955078125f, max(hA, hB));
            float crease_2 = exp((-dist) / 0.0949999988079071044921875f) * (1.0f - smoothstep(0.2800000011920928955078125f, 0.560000002384185791015625f, dist));
            float soft_2 = 1.0f - (dist / 0.560000002384185791015625f);
            soft_2 *= soft_2;
            occ += (((0.579999983310699462890625f * crease_2) + (0.519999980926513671875f * soft_2)) * wallPresent);
        }
    }
    if ((wallEdges & 48) != 0)
    {
        if ((wallEdges & 16) != 0)
        {
            float dist_1 = abs(u.x - u.y) * 0.707106769084930419921875f;
            if (dist_1 < 0.560000002384185791015625f)
            {
                float crease_3 = exp((-dist_1) / 0.0949999988079071044921875f) * (1.0f - smoothstep(0.2800000011920928955078125f, 0.560000002384185791015625f, dist_1));
                float soft_3 = 1.0f - (dist_1 / 0.560000002384185791015625f);
                occ += ((0.579999983310699462890625f * crease_3) + ((0.519999980926513671875f * soft_3) * soft_3));
            }
        }
        if ((wallEdges & 32) != 0)
        {
            float dist_2 = abs((u.x + u.y) - 1.0f) * 0.707106769084930419921875f;
            if (dist_2 < 0.560000002384185791015625f)
            {
                float crease_4 = exp((-dist_2) / 0.0949999988079071044921875f) * (1.0f - smoothstep(0.2800000011920928955078125f, 0.560000002384185791015625f, dist_2));
                float soft_4 = 1.0f - (dist_2 / 0.560000002384185791015625f);
                occ += ((0.579999983310699462890625f * crease_4) + ((0.519999980926513671875f * soft_4) * soft_4));
            }
        }
    }
    else
    {
        if ((fenceEdges & 48) != 0)
        {
            if ((fenceEdges & 16) != 0)
            {
                float dist_3 = abs(u.x - u.y) * 0.707106769084930419921875f;
                if (dist_3 < 0.300000011920928955078125f)
                {
                    float crease_5 = exp((-dist_3) / 0.07500000298023223876953125f) * (1.0f - smoothstep(0.1599999964237213134765625f, 0.300000011920928955078125f, dist_3));
                    float soft_5 = 1.0f - (dist_3 / 0.300000011920928955078125f);
                    occ += (0.680000007152557373046875f * ((0.60000002384185791015625f * crease_5) + ((0.4799999892711639404296875f * soft_5) * soft_5)));
                }
            }
            if ((fenceEdges & 32) != 0)
            {
                float dist_4 = abs((u.x + u.y) - 1.0f) * 0.707106769084930419921875f;
                if (dist_4 < 0.300000011920928955078125f)
                {
                    float crease_6 = exp((-dist_4) / 0.07500000298023223876953125f) * (1.0f - smoothstep(0.1599999964237213134765625f, 0.300000011920928955078125f, dist_4));
                    float soft_6 = 1.0f - (dist_4 / 0.300000011920928955078125f);
                    occ += (0.680000007152557373046875f * ((0.60000002384185791015625f * crease_6) + ((0.4799999892711639404296875f * soft_6) * soft_6)));
                }
            }
        }
        else
        {
            int2 param_16 = cell;
            int param_17 = 2;
            int param_18 = row;
            int part = maskCatAt(param_16, param_17, param_18) & 7;
            if (part != 0)
            {
                float _8624;
                if (part <= 2)
                {
                    _8624 = abs(u.x - u.y) * 0.707106769084930419921875f;
                }
                else
                {
                    _8624 = abs((u.x + u.y) - 1.0f) * 0.707106769084930419921875f;
                }
                float dist_5 = _8624;
                if (dist_5 < 0.560000002384185791015625f)
                {
                    float2 _8651;
                    if (part <= 2)
                    {
                        _8651 = (0.5f * (u.x + u.y)).xx;
                    }
                    else
                    {
                        _8651 = float2(0.5f * ((u.x - u.y) + 1.0f), 0.5f * ((u.y - u.x) + 1.0f));
                    }
                    float2 edgeLocal_1 = _8651;
                    float2 edgePos_1 = float2(cell) + edgeLocal_1;
                    float hD = ((0.5f - heightMap.Sample(_heightMap_sampler, (edgePos_1 * ambient_frame.z) / gridSize).x) * 128.0f) - here.z;
                    float wallPresent_1 = smoothstep(0.07999999821186065673828125f, 0.2800000011920928955078125f, hD);
                    float crease_7 = exp((-dist_5) / 0.0949999988079071044921875f) * (1.0f - smoothstep(0.2800000011920928955078125f, 0.560000002384185791015625f, dist_5));
                    float soft_7 = 1.0f - (dist_5 / 0.560000002384185791015625f);
                    occ += (((0.579999983310699462890625f * crease_7) + ((0.519999980926513671875f * soft_7) * soft_7)) * wallPresent_1);
                }
            }
        }
    }
    return clamp(occ, 0.0f, 1.4500000476837158203125f);
}

float3 sampleBakedGroundAO(float2 lotXY, int levelRow, int2 oSize)
{
    int aoSize = oSize.x / 4;
    if ((aoSize <= 0) || (levelRow < 0))
    {
        return 0.0f.xxx;
    }
    int2 param = oSize;
    int aoRows = voxelAoRows(param);
    if ((levelRow >> 2) >= aoRows)
    {
        return 0.0f.xxx;
    }
    int halfH = ((oSize.x / 2) + 128) + (256 * aoRows);
    int yBase = (halfH * 2) + ((levelRow >> 2) * aoSize);
    if (oSize.y < (yBase + aoSize))
    {
        return 0.0f.xxx;
    }
    float2 p = (lotXY * 8.0f) - 0.5f.xx;
    bool _10299 = p.x < (-0.5f);
    bool _10306;
    if (!_10299)
    {
        _10306 = p.y < (-0.5f);
    }
    else
    {
        _10306 = _10299;
    }
    bool _10315;
    if (!_10306)
    {
        _10315 = p.x >= float(aoSize);
    }
    else
    {
        _10315 = _10306;
    }
    bool _10324;
    if (!_10315)
    {
        _10324 = p.y >= float(aoSize);
    }
    else
    {
        _10324 = _10315;
    }
    if (_10324)
    {
        return 0.0f.xxx;
    }
    int2 i0 = int2(floor(p));
    float2 f = clamp(p - float2(i0), 0.0f.xx, 1.0f.xx);
    int2 maxC = (aoSize - 1).xx;
    int2 c00 = clamp(i0, int2(0, 0), maxC);
    int2 c10 = clamp(i0 + int2(1, 0), int2(0, 0), maxC);
    int2 c01 = clamp(i0 + int2(0, 1), int2(0, 0), maxC);
    int2 c11 = clamp(i0 + int2(1, 1), int2(0, 0), maxC);
    int xOff = (levelRow & 3) * aoSize;
    float3 v00 = voxelMap.Load(int3(int2(xOff + c00.x, yBase + c00.y), 0)).xyz;
    float3 v10 = voxelMap.Load(int3(int2(xOff + c10.x, yBase + c10.y), 0)).xyz;
    float3 v01 = voxelMap.Load(int3(int2(xOff + c01.x, yBase + c01.y), 0)).xyz;
    float3 v11 = voxelMap.Load(int3(int2(xOff + c11.x, yBase + c11.y), 0)).xyz;
    return lerp(lerp(v00, v10, f.x.xxx), lerp(v01, v11, f.x.xxx), f.y.xxx);
}

float dynamicSimOccAt(float3 q, float pad)
{
    if (ambient_shadowView.w <= 0.5f)
    {
        return 0.0f;
    }
    float2 scene = float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
    uint _3478_dummy_parameter;
    float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _3478_dummy_parameter)));
    float2 wp = ambient_shadowView.xy + (scene * ambient_shadowView.z);
    bool _3492 = any(bool2(wp.x < 0.5f.xx.x, wp.y < 0.5f.xx.y));
    bool _3502;
    if (!_3492)
    {
        float2 _3499 = wSize - 0.5f.xx;
        _3502 = any(bool2(wp.x >= _3499.x, wp.y >= _3499.y));
    }
    else
    {
        _3502 = _3492;
    }
    if (_3502)
    {
        return 0.0f;
    }
    float2 uv = wp / wSize;
    float4 wFront = worldDepthMap.GatherRed(_worldDepthMap_sampler, uv);
    if (min(min(wFront.x, wFront.y), min(wFront.z, wFront.w)) >= 0.99989998340606689453125f)
    {
        return 0.0f;
    }
    float4 wBack = worldBackDepthMap.GatherRed(_worldBackDepthMap_sampler, uv);
    float key = (q.x + q.y) + (0.800000011920928955078125f * q.z);
    float4 valid = step(wFront, 0.99989998340606689453125f.xxxx) * step(9.9999997473787516355514526367188e-05f.xxxx, wBack);
    float4 fKey = (0.62000000476837158203125f.xxxx - wFront) / 0.0030000000260770320892333984375f.xxxx;
    float4 bKey = (0.62000000476837158203125f.xxxx - wBack) / 0.0030000000260770320892333984375f.xxxx;
    float4 inSim = (valid * smoothstep((-pad).xxxx, 0.039999999105930328369140625f.xxxx, fKey - key.xxxx)) * smoothstep((-pad).xxxx, 0.039999999105930328369140625f.xxxx, key.xxxx - bKey);
    float2 f = frac(wp - 0.5f.xx);
    return lerp(lerp(inSim.w, inSim.z, f.x), lerp(inSim.x, inSim.y, f.x), f.y);
}

float simFootAO(float3 here)
{
    if (ambient_shadowView.w <= 0.5f)
    {
        return 0.0f;
    }
    float3 qC = float3(here.xy, here.z + 0.054999999701976776123046875f);
    float2 sceneC = float2(32.0f * (qC.x - qC.y), (16.0f * (qC.x + qC.y)) - (40.0f * qC.z)) + ambient_frame.xy;
    float2 wpC = ambient_shadowView.xy + (sceneC * ambient_shadowView.z);
    bool _10493 = wpC.x < (ambient_dynShadowBounds.x - 8.0f);
    bool _10503;
    if (!_10493)
    {
        _10503 = wpC.y < (ambient_dynShadowBounds.y - 8.0f);
    }
    else
    {
        _10503 = _10493;
    }
    bool _10513;
    if (!_10503)
    {
        _10513 = wpC.x > (ambient_dynShadowBounds.z + 8.0f);
    }
    else
    {
        _10513 = _10503;
    }
    bool _10523;
    if (!_10513)
    {
        _10523 = wpC.y > (ambient_dynShadowBounds.w + 8.0f);
    }
    else
    {
        _10523 = _10513;
    }
    if (_10523)
    {
        return 0.0f;
    }
    uint _10530_dummy_parameter;
    float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _10530_dummy_parameter)));
    bool _10535 = any(bool2(wpC.x < 8.0f.xx.x, wpC.y < 8.0f.xx.y));
    bool _10545;
    if (!_10535)
    {
        float2 _10542 = wSize - 8.0f.xx;
        _10545 = any(bool2(wpC.x >= _10542.x, wpC.y >= _10542.y));
    }
    else
    {
        _10545 = _10535;
    }
    if (_10545)
    {
        return 0.0f;
    }
    int2 ic = int2(floor(wpC));
    float dMin = worldDepthMap.Load(int3(ic, 0)).x;
    dMin = min(dMin, worldDepthMap.Load(int3(ic + int2(-6, -4), 0)).x);
    dMin = min(dMin, worldDepthMap.Load(int3(ic + int2(6, -4), 0)).x);
    dMin = min(dMin, worldDepthMap.Load(int3(ic + int2(-6, 4), 0)).x);
    dMin = min(dMin, worldDepthMap.Load(int3(ic + int2(6, 4), 0)).x);
    if (dMin >= 0.99989998340606689453125f)
    {
        return 0.0f;
    }
    float acc = 0.0f;
    for (int iy = -2; iy <= 2; iy++)
    {
        float wy = _10617[iy + 2];
        for (int ix = -2; ix <= 2; ix++)
        {
            float3 q = float3(here.xy + (float2(float(ix), float(iy)) * 0.034000001847743988037109375f), here.z + 0.054999999701976776123046875f);
            float3 param = q;
            float param_1 = 0.100000001490116119384765625f;
            acc += (dynamicSimOccAt(param, param_1) * (_10617[ix + 2] * wy));
        }
    }
    return clamp(1.0f - exp((-acc) * 2.599999904632568359375f), 0.0f, 1.0f);
}

float voxelGroundAO(float3 here, int levelRow, int2 vSize, out float outContact)
{
    float2 param = here.xy;
    int param_1 = levelRow;
    int2 param_2 = vSize;
    float3 baked = sampleBakedGroundAO(param, param_1, param_2);
    float3 param_3 = here;
    float simContact = simFootAO(param_3);
    float staticContact = clamp(baked.x * 0.7799999713897705078125f, 0.0f, 1.0f);
    float combinedContact = max(staticContact, simContact);
    outContact = staticContact + ((combinedContact - staticContact) * lerp(1.0f, 0.519999980926513671875f, staticContact));
    float staticHemi = clamp((baked.y * 0.439999997615814208984375f) + (baked.z * 0.3400000035762786865234375f), 0.0f, 1.0f);
    float combinedHemi = max(staticHemi, clamp(staticHemi + (simContact * 0.2800000011920928955078125f), 0.0f, 1.0f));
    return staticHemi + ((combinedHemi - staticHemi) * 0.519999980926513671875f);
}

float2 sceneOf(float3 q)
{
    return float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
}

float offLotGroundAO(float3 here, float scale, inout float outContact)
{
    int2 limit = int2(ambient_extent.xy) - int2(1, 1);
    float3 param = here;
    float2 snapScene = (floor(sceneOf(param) * 0.5f) * 2.0f) + 1.0f.xx;
    float bestC = 0.0f;
    float sumC = 0.0f;
    float bestH = 0.0f;
    float sumH = 0.0f;
    for (int r = 0; r < 3; r++)
    {
        float sy = ambient_view.y + ((snapScene.y + _10711[r]) * scale);
        bool _10722 = sy < 0.0f;
        bool _10731;
        if (!_10722)
        {
            _10731 = sy > float(limit.y);
        }
        else
        {
            _10731 = _10722;
        }
        if (_10731)
        {
            continue;
        }
        int iy = int(floor(sy));
        for (int c = -6; c <= 6; c++)
        {
            float sx = ambient_view.x + ((snapScene.x + (float(c) * 2.5f)) * scale);
            bool _10761 = sx < 0.0f;
            bool _10770;
            if (!_10761)
            {
                _10770 = sx > float(limit.x);
            }
            else
            {
                _10770 = _10761;
            }
            if (_10770)
            {
                continue;
            }
            int2 sp = int2(int(floor(sx)), iy);
            float qDepth = depthMap.Load(int3(sp, 0)).x;
            if (qDepth >= 1.0f)
            {
                continue;
            }
            float2 qScene = ((float2(sp) + 0.5f.xx) - ambient_view.xy) / scale.xx;
            float2 param_1 = qScene;
            float param_2 = (0.62000000476837158203125f - qDepth) / 0.0030000000260770320892333984375f;
            bool param_3 = false;
            float2 param_4 = ambient_frame.xy;
            float3 qLot = lotPoint(param_1, param_2, param_3, param_4);
            float dz = qLot.z - here.z;
            if ((dz < (-0.100000001490116119384765625f)) || (dz > 0.7200000286102294921875f))
            {
                continue;
            }
            float dxy = length(qLot.xy - here.xy);
            if (dxy > 0.4799999892711639404296875f)
            {
                continue;
            }
            float zW = smoothstep(-0.100000001490116119384765625f, 0.00999999977648258209228515625f, dz) * (1.0f - smoothstep(0.4199999868869781494140625f, 0.7200000286102294921875f, dz));
            float cHit = (1.0f - smoothstep(0.039999999105930328369140625f, 0.3400000035762786865234375f, dxy)) * zW;
            float hHit = (1.0f - smoothstep(0.0599999986588954925537109375f, 0.4799999892711639404296875f, dxy)) * zW;
            bestC = max(bestC, cHit);
            sumC += cHit;
            bestH = max(bestH, hHit);
            sumH += hHit;
        }
    }
    outContact = clamp((bestC * 0.62000000476837158203125f) + min(sumC * 0.02500000037252902984619140625f, 0.1599999964237213134765625f), 0.0f, 0.7599999904632568359375f);
    return clamp((bestH * 0.37999999523162841796875f) + min(sumH * 0.02199999988079071044921875f, 0.180000007152557373046875f), 0.0f, 0.560000002384185791015625f);
}

float wallCornerAO(float3 here, float2 horizN)
{
    float2 planePos = here.xy + ambient_frame.w.xx;
    float2 at = planePos + (horizN * 0.100000001490116119384765625f);
    int2 baseCell = int2(floor(at - 0.5f.xx));
    float occ = 0.0f;
    int2 _9866;
    int2 _9872;
    float2 _9899;
    float2 _9906;
    float2 _9917;
    float2 _9933;
    float2 _9944;
    float2 _9951;
    float2 _9985;
    for (int cy = 0; cy <= 1; cy++)
    {
        for (int cx = 0; cx <= 1; cx++)
        {
            int2 cell = baseCell + int2(cx, cy);
            int2 param = cell;
            float param_1 = here.z;
            float param_2 = here.z;
            float param_3 = 0.1500000059604644775390625f;
            int row = storyRowAt(param, param_1, param_2, param_3);
            int2 param_4 = cell;
            int param_5 = 3;
            int param_6 = row;
            int wallEdges = maskCatAt(param_4, param_5, param_6);
            if (wallEdges == 0)
            {
                continue;
            }
            float2 cMin = float2(cell);
            float2 cMax = cMin + 1.0f.xx;
            for (int d = 0; d < 4; d++)
            {
                if ((wallEdges & (1 << d)) == 0)
                {
                    continue;
                }
                if (d == 0)
                {
                    _9866 = int2(-1, 0);
                }
                else
                {
                    if (d == 1)
                    {
                        _9872 = int2(1, 0);
                    }
                    else
                    {
                        bool2 _9878 = (d == 2).xx;
                        _9872 = int2(_9878.x ? int2(0, -1).x : int2(0, 1).x, _9878.y ? int2(0, -1).y : int2(0, 1).y);
                    }
                    _9866 = _9872;
                }
                int2 _step = _9866;
                float perpWeight = 1.0f - smoothstep(0.7599999904632568359375f, 0.949999988079071044921875f, -dot(float2(_step), horizN));
                if (perpWeight <= 0.001000000047497451305389404296875f)
                {
                    continue;
                }
                if (d == 0)
                {
                    _9899 = cMin;
                }
                else
                {
                    if (d == 1)
                    {
                        _9906 = float2(cMax.x, cMin.y);
                    }
                    else
                    {
                        if (d == 2)
                        {
                            _9917 = cMin;
                        }
                        else
                        {
                            _9917 = float2(cMin.x, cMax.y);
                        }
                        _9906 = _9917;
                    }
                    _9899 = _9906;
                }
                float2 segA = _9899;
                if (d == 0)
                {
                    _9933 = float2(cMin.x, cMax.y);
                }
                else
                {
                    if (d == 1)
                    {
                        _9944 = cMax;
                    }
                    else
                    {
                        if (d == 2)
                        {
                            _9951 = float2(cMax.x, cMin.y);
                        }
                        else
                        {
                            _9951 = cMax;
                        }
                        _9944 = _9951;
                    }
                    _9933 = _9944;
                }
                float2 segB = _9933;
                float frontHemi = smoothstep(0.14000000059604644775390625f, 0.449999988079071044921875f, max(dot(segA - planePos, horizN), dot(segB - planePos, horizN)));
                if (frontHemi <= 0.001000000047497451305389404296875f)
                {
                    continue;
                }
                if (d <= 1)
                {
                    _9985 = float2(segA.x, clamp(at.y, cMin.y, cMax.y));
                }
                else
                {
                    _9985 = float2(clamp(at.x, cMin.x, cMax.x), segA.y);
                }
                float2 closest = _9985;
                float dist = length(at - closest);
                if (dist >= 0.4600000083446502685546875f)
                {
                    continue;
                }
                float t = 1.0f - (dist / 0.4600000083446502685546875f);
                float term = ((0.550000011920928955078125f * exp((-dist) / 0.0900000035762786865234375f)) * (1.0f - smoothstep(0.23999999463558197021484375f, 0.4600000083446502685546875f, dist))) + ((0.449999988079071044921875f * t) * t);
                occ = max(occ, (perpWeight * frontHemi) * term);
            }
            if ((wallEdges & 16) != 0)
            {
                float2 diagN = float2(-0.707106769084930419921875f, 0.707106769084930419921875f);
                float perpWeight_1 = 1.0f - smoothstep(0.800000011920928955078125f, 0.9700000286102294921875f, abs(dot(diagN, horizN)));
                float frontHemi_1 = smoothstep(0.14000000059604644775390625f, 0.449999988079071044921875f, max(dot(cMin - planePos, horizN), dot(cMax - planePos, horizN)));
                if ((perpWeight_1 * frontHemi_1) > 0.001000000047497451305389404296875f)
                {
                    float proj = clamp(0.5f * ((at.x - cMin.x) + (at.y - cMin.y)), 0.0f, 1.0f);
                    float dist_1 = length(at - (cMin + proj.xx));
                    if (dist_1 < 0.4600000083446502685546875f)
                    {
                        float t_1 = 1.0f - (dist_1 / 0.4600000083446502685546875f);
                        float term_1 = ((0.5f * exp((-dist_1) / 0.0900000035762786865234375f)) * (1.0f - smoothstep(0.23999999463558197021484375f, 0.4600000083446502685546875f, dist_1))) + ((0.4000000059604644775390625f * t_1) * t_1);
                        occ = max(occ, (perpWeight_1 * frontHemi_1) * term_1);
                    }
                }
            }
            if ((wallEdges & 32) != 0)
            {
                float2 diagN_1 = 0.707106769084930419921875f.xx;
                float perpWeight_2 = 1.0f - smoothstep(0.800000011920928955078125f, 0.9700000286102294921875f, abs(dot(diagN_1, horizN)));
                float2 segA_1 = float2(cMin.x, cMax.y);
                float2 segB_1 = float2(cMax.x, cMin.y);
                float frontHemi_2 = smoothstep(0.14000000059604644775390625f, 0.449999988079071044921875f, max(dot(segA_1 - planePos, horizN), dot(segB_1 - planePos, horizN)));
                if ((perpWeight_2 * frontHemi_2) > 0.001000000047497451305389404296875f)
                {
                    float proj_1 = clamp(0.5f * ((at.x - cMin.x) - (at.y - cMax.y)), 0.0f, 1.0f);
                    float dist_2 = length(at - float2(cMin.x + proj_1, cMax.y - proj_1));
                    if (dist_2 < 0.4600000083446502685546875f)
                    {
                        float t_2 = 1.0f - (dist_2 / 0.4600000083446502685546875f);
                        float term_2 = ((0.5f * exp((-dist_2) / 0.0900000035762786865234375f)) * (1.0f - smoothstep(0.23999999463558197021484375f, 0.4600000083446502685546875f, dist_2))) + ((0.4000000059604644775390625f * t_2) * t_2);
                        occ = max(occ, (perpWeight_2 * frontHemi_2) * term_2);
                    }
                }
            }
        }
    }
    return clamp(occ, 0.0f, 1.0f);
}

float sampleHullSlice(float2 op, float key, int yOffset, int2 sliceMax, float pad)
{
    float2 p = op - 0.5f.xx;
    int2 i0 = int2(floor(p));
    float2 f = clamp(p - float2(i0), 0.0f.xx, 1.0f.xx);
    int2 c00 = clamp(i0, int2(0, 0), sliceMax);
    int2 c10 = clamp(i0 + int2(1, 0), int2(0, 0), sliceMax);
    int2 c01 = clamp(i0 + int2(0, 1), int2(0, 0), sliceMax);
    int2 c11 = clamp(i0 + int2(1, 1), int2(0, 0), sliceMax);
    int4 r00 = int4((voxelMap.Load(int3(int2(c00.x, c00.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int4 r10 = int4((voxelMap.Load(int3(int2(c10.x, c10.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int4 r01 = int4((voxelMap.Load(int3(int2(c01.x, c01.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int4 r11 = int4((voxelMap.Load(int3(int2(c11.x, c11.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int f00 = (r00.x * 256) + r00.y;
    int f10 = (r10.x * 256) + r10.y;
    int f01 = (r01.x * 256) + r01.y;
    int f11 = (r11.x * 256) + r11.y;
    if ((((f00 | f10) | f01) | f11) == 0)
    {
        return 0.0f;
    }
    float _3078;
    if (f00 == 0)
    {
        _3078 = 0.0f;
    }
    else
    {
        _3078 = smoothstep(-pad, 0.039999999105930328369140625f, ((float(f00) / 256.0f) - 16.0f) - key) * smoothstep(-pad, 0.039999999105930328369140625f, key - ((float((r00.z * 256) + r00.w) / 256.0f) - 16.0f));
    }
    float v00 = _3078;
    float _3111;
    if (f10 == 0)
    {
        _3111 = 0.0f;
    }
    else
    {
        _3111 = smoothstep(-pad, 0.039999999105930328369140625f, ((float(f10) / 256.0f) - 16.0f) - key) * smoothstep(-pad, 0.039999999105930328369140625f, key - ((float((r10.z * 256) + r10.w) / 256.0f) - 16.0f));
    }
    float v10 = _3111;
    float _3143;
    if (f01 == 0)
    {
        _3143 = 0.0f;
    }
    else
    {
        _3143 = smoothstep(-pad, 0.039999999105930328369140625f, ((float(f01) / 256.0f) - 16.0f) - key) * smoothstep(-pad, 0.039999999105930328369140625f, key - ((float((r01.z * 256) + r01.w) / 256.0f) - 16.0f));
    }
    float v01 = _3143;
    float _3175;
    if (f11 == 0)
    {
        _3175 = 0.0f;
    }
    else
    {
        _3175 = smoothstep(-pad, 0.039999999105930328369140625f, ((float(f11) / 256.0f) - 16.0f) - key) * smoothstep(-pad, 0.039999999105930328369140625f, key - ((float((r11.z * 256) + r11.w) / 256.0f) - 16.0f));
    }
    float v11 = _3175;
    return lerp(lerp(v00, v10, f.x), lerp(v01, v11, f.x), f.y);
}

float dualViewHullAtPrecomp(float3 q, int2 oSize, int halfH, float topMarginHalf, int2 sliceMax, float2 lotSz, float spreadPx)
{
    float pad = 0.180000007152557373046875f + (0.0199999995529651641845703125f * spreadPx);
    float2 op0 = float2(((q.x - q.y) + lotSz.x) * 16.0f, (((q.x + q.y) * 8.0f) - (q.z * 20.0f)) + topMarginHalf);
    bool _3268 = any(bool2(op0.x < 0.0f.xx.x, op0.y < 0.0f.xx.y));
    bool _3278;
    if (!_3268)
    {
        _3278 = op0.x >= float(oSize.x);
    }
    else
    {
        _3278 = _3268;
    }
    bool _3287;
    if (!_3278)
    {
        _3287 = op0.y >= float(halfH);
    }
    else
    {
        _3287 = _3278;
    }
    if (_3287)
    {
        return 0.0f;
    }
    float key0 = (q.x + q.y) + (0.800000011920928955078125f * q.z);
    float2 param = op0;
    float param_1 = key0;
    int param_2 = 0;
    int2 param_3 = sliceMax;
    float param_4 = pad;
    float in0 = sampleHullSlice(param, param_1, param_2, param_3, param_4);
    if (in0 <= 0.00999999977648258209228515625f)
    {
        return 0.0f;
    }
    float3 qB = float3(lotSz.y - q.y, q.x, q.z);
    float2 op1 = float2(((qB.x - qB.y) + lotSz.x) * 16.0f, (((qB.x + qB.y) * 8.0f) - (qB.z * 20.0f)) + topMarginHalf);
    bool _3354 = any(bool2(op1.x < 0.0f.xx.x, op1.y < 0.0f.xx.y));
    bool _3364;
    if (!_3354)
    {
        _3364 = op1.x >= float(oSize.x);
    }
    else
    {
        _3364 = _3354;
    }
    bool _3373;
    if (!_3364)
    {
        _3373 = op1.y >= float(halfH);
    }
    else
    {
        _3373 = _3364;
    }
    if (_3373)
    {
        return 0.0f;
    }
    float key1 = (qB.x + qB.y) + (0.800000011920928955078125f * qB.z);
    float2 param_5 = op1;
    float param_6 = key1;
    int param_7 = halfH;
    int2 param_8 = sliceMax;
    float param_9 = pad;
    float in1 = sampleHullSlice(param_5, param_6, param_7, param_8, param_9);
    return min(in0, in1);
}

float voxelWallAO(float3 here, float2 horizN, float floorZ, int2 vSize, int vHalfH, float vTopMarginHalf, int2 vSliceMax, float2 lotSz)
{
    float2 tang = float2(-horizN.y, horizN.x);
    float2 faceAt = (here.xy + ambient_frame.w.xx) + (horizN * 0.2199999988079071044921875f);
    int2 faceCell = int2(floor(faceAt));
    int2 param = faceCell;
    float param_1 = here.z;
    float param_2 = here.z;
    float param_3 = 0.1500000059604644775390625f;
    int wallRow = storyRowAt(param, param_1, param_2, param_3);
    int2 param_4 = faceCell;
    int param_5 = wallRow;
    float2 param_6 = frac(faceAt);
    int faceRoom = effectiveRoomAt(param_4, param_5, param_6);
    float ceilLim = (floorZ + 2.9500000476837158203125f) - 0.14000000059604644775390625f;
    float floorLim = floorZ + 0.119999997317790985107421875f;
    float sum = 0.0f;
    float wSum = 0.0f;
    float _11137;
    for (int i = 0; i < 8; i++)
    {
        float3 o = _11061[i];
        float qz = here.z + o.z;
        if (((i >= 4) && (i <= 5)) && (qz > ceilLim))
        {
            continue;
        }
        if ((i >= 6) && (qz < floorLim))
        {
            continue;
        }
        float3 q = float3((here.xy + (horizN * o.x)) + (tang * o.y), qz);
        float2 qAt = q.xy + ambient_frame.w.xx;
        int2 qCell = int2(floor(qAt));
        int2 param_7 = qCell;
        int param_8 = wallRow;
        float2 param_9 = frac(qAt);
        float sameRoom = float(effectiveRoomAt(param_7, param_8, param_9) == faceRoom);
        if (sameRoom > 0.5f)
        {
            float3 param_10 = q;
            int2 param_11 = vSize;
            int param_12 = vHalfH;
            float param_13 = vTopMarginHalf;
            int2 param_14 = vSliceMax;
            float2 param_15 = lotSz;
            float param_16 = 0.75f;
            _11137 = dualViewHullAtPrecomp(param_10, param_11, param_12, param_13, param_14, param_15, param_16);
        }
        else
        {
            _11137 = 0.0f;
        }
        float occ = _11137;
        sum += (occ * _11158[i]);
        wSum += _11158[i];
    }
    float raw = sum / max(wSum, 9.9999997473787516355514526367188e-05f);
    return clamp((raw - 0.0350000001490116119384765625f) * 1.32000005245208740234375f, 0.0f, 1.0f);
}

float simWallProximityAO(float3 here, float2 horizN)
{
    if (ambient_shadowView.w <= 0.5f)
    {
        return 0.0f;
    }
    float3 probe = float3(here.xy + (horizN * 0.2199999988079071044921875f), here.z);
    float3 param = probe;
    float2 sc = sceneOf(param);
    float2 wp = ambient_shadowView.xy + (sc * ambient_shadowView.z);
    bool _11222 = wp.x < (ambient_dynShadowBounds.x - 8.0f);
    bool _11232;
    if (!_11222)
    {
        _11232 = wp.y < (ambient_dynShadowBounds.y - 8.0f);
    }
    else
    {
        _11232 = _11222;
    }
    bool _11242;
    if (!_11232)
    {
        _11242 = wp.x > (ambient_dynShadowBounds.z + 8.0f);
    }
    else
    {
        _11242 = _11232;
    }
    bool _11252;
    if (!_11242)
    {
        _11252 = wp.y > (ambient_dynShadowBounds.w + 8.0f);
    }
    else
    {
        _11252 = _11242;
    }
    if (_11252)
    {
        return 0.0f;
    }
    uint _11259_dummy_parameter;
    float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _11259_dummy_parameter)));
    bool _11264 = any(bool2(wp.x < 6.0f.xx.x, wp.y < 6.0f.xx.y));
    bool _11274;
    if (!_11264)
    {
        float2 _11271 = wSize - 6.0f.xx;
        _11274 = any(bool2(wp.x >= _11271.x, wp.y >= _11271.y));
    }
    else
    {
        _11274 = _11264;
    }
    if (_11274)
    {
        return 0.0f;
    }
    int2 ic = int2(floor(wp));
    float dMin = worldDepthMap.Load(int3(ic, 0)).x;
    dMin = min(dMin, worldDepthMap.Load(int3(ic + int2(-5, 0), 0)).x);
    dMin = min(dMin, worldDepthMap.Load(int3(ic + int2(5, 0), 0)).x);
    if (dMin >= 0.99989998340606689453125f)
    {
        return 0.0f;
    }
    float2 tang = float2(-horizN.y, horizN.x);
    float3 param_1 = float3(here.xy + (horizN * 0.14000000059604644775390625f), here.z);
    float param_2 = 0.14000000059604644775390625f;
    float o0 = dynamicSimOccAt(param_1, param_2);
    float3 param_3 = float3((here.xy + (horizN * 0.25f)) + (tang * 0.100000001490116119384765625f), here.z + 0.039999999105930328369140625f);
    float param_4 = 0.1500000059604644775390625f;
    float o1 = dynamicSimOccAt(param_3, param_4);
    float3 param_5 = float3((here.xy + (horizN * 0.25f)) - (tang * 0.100000001490116119384765625f), here.z + 0.039999999105930328369140625f);
    float param_6 = 0.1500000059604644775390625f;
    float o2 = dynamicSimOccAt(param_5, param_6);
    float3 param_7 = float3(here.xy + (horizN * 0.37999999523162841796875f), here.z - 0.0599999986588954925537109375f);
    float param_8 = 0.1599999964237213134765625f;
    float o3 = dynamicSimOccAt(param_7, param_8);
    return clamp((((0.37999999523162841796875f * o0) + (0.23999999463558197021484375f * o1)) + (0.23999999463558197021484375f * o2)) + (0.14000000059604644775390625f * o3), 0.0f, 1.0f);
}

float spriteWallProximityAO(float3 here, int row)
{
    float2 at = here.xy + ambient_frame.w.xx;
    int2 cell = int2(floor(at));
    float2 u = frac(at);
    int2 param = cell;
    int param_1 = 3;
    int param_2 = row;
    int wEdges = maskCatAt(param, param_1, param_2);
    if (wEdges == 0)
    {
        return 0.0f;
    }
    float occ = 0.0f;
    float _9670;
    float _9678;
    float _9687;
    for (int d = 0; d < 4; d++)
    {
        if ((wEdges & (1 << d)) == 0)
        {
            continue;
        }
        if (d == 0)
        {
            _9670 = u.x;
        }
        else
        {
            if (d == 1)
            {
                _9678 = 1.0f - u.x;
            }
            else
            {
                if (d == 2)
                {
                    _9687 = u.y;
                }
                else
                {
                    _9687 = 1.0f - u.y;
                }
                _9678 = _9687;
            }
            _9670 = _9678;
        }
        float dist = _9670;
        if (dist >= 0.439999997615814208984375f)
        {
            continue;
        }
        float t = 1.0f - (dist / 0.439999997615814208984375f);
        occ += ((0.519999980926513671875f * t) * t);
    }
    if ((wEdges & 16) != 0)
    {
        float dist_1 = abs(u.x - u.y) * 0.707106769084930419921875f;
        if (dist_1 < 0.439999997615814208984375f)
        {
            float t_1 = 1.0f - (dist_1 / 0.439999997615814208984375f);
            occ += ((0.4600000083446502685546875f * t_1) * t_1);
        }
    }
    if ((wEdges & 32) != 0)
    {
        float dist_2 = abs((u.x + u.y) - 1.0f) * 0.707106769084930419921875f;
        if (dist_2 < 0.439999997615814208984375f)
        {
            float t_2 = 1.0f - (dist_2 / 0.439999997615814208984375f);
            occ += ((0.4600000083446502685546875f * t_2) * t_2);
        }
    }
    return clamp(occ, 0.0f, 1.0499999523162841796875f);
}

float2 lotSource(float2 camera)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1212;
    if (orientation == 1)
    {
        _1212 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _1226;
        if (orientation == 2)
        {
            _1226 = size - camera;
        }
        else
        {
            float2 _1235;
            if (orientation == 3)
            {
                _1235 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _1235 = camera;
            }
            _1226 = _1235;
        }
        _1212 = _1226;
    }
    return _1212;
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

float cloudLight(float3 lot)
{
    float cover = ambient_clouds.x;
    bool _2302 = cover <= 0.0f;
    bool _2309;
    if (!_2302)
    {
        _2309 = ambient_clouds.y <= 0.0f;
    }
    else
    {
        _2309 = _2302;
    }
    if (_2309)
    {
        return 1.0f;
    }
    float3 sun = ambient_sunLot.xyz;
    float cloudH = max(ambient_clouds.w, lot.z + 4.0f);
    float2 param = lot.xy + ((sun.xy * (cloudH - lot.z)) / max(sun.z, 0.25f).xx);
    float2 source = lotSource(param);
    float2 q = (source - ambient_drift.xy) / 9.0f.xx;
    float2 param_1 = q;
    float2 param_2 = (q * 2.0299999713897705078125f) + 17.0f.xx;
    float2 param_3 = (q * 4.0100002288818359375f) + 41.0f.xx;
    float2 param_4 = (q * 8.05000019073486328125f) + 7.0f.xx;
    float field = (((0.5f * valueNoise(param_1)) + (0.25f * valueNoise(param_2))) + (0.1500000059604644775390625f * valueNoise(param_3))) + (0.100000001490116119384765625f * valueNoise(param_4));
    float threshold = lerp(0.7200000286102294921875f, 0.180000007152557373046875f, cover);
    float density = smoothstep(threshold - 0.07999999821186065673828125f, threshold + 0.100000001490116119384765625f, field);
    return 1.0f - (ambient_clouds.y * density);
}

bool hasFloorSlabAt(int2 cell, int row, float2 localU)
{
    int2 param = cell;
    int param_1 = 1;
    int param_2 = row;
    if (maskCatAt(param, param_1, param_2) == 0)
    {
        return false;
    }
    int2 param_3 = cell;
    int param_4 = 2;
    int param_5 = row;
    int part = maskCatAt(param_3, param_4, param_5) & 7;
    if (part == 0)
    {
        return true;
    }
    float2 _5481;
    if (part == 1)
    {
        _5481 = float2(1.0f, -1.0f);
    }
    else
    {
        float2 _5487;
        if (part == 2)
        {
            _5487 = float2(-1.0f, 1.0f);
        }
        else
        {
            bool2 _5493 = (part == 3).xx;
            _5487 = float2(_5493.x ? (-1.0f).xx.x : 1.0f.xx.x, _5493.y ? (-1.0f).xx.y : 1.0f.xx.y);
        }
        _5481 = _5487;
    }
    float2 toward = _5481;
    return dot(localU - 0.5f.xx, toward) >= 0.0f;
}

float lampFloorVis(float3 here, float3 lampLot, float onFlatFloor)
{
    int stories = indoorStories();
    if (stories <= 1)
    {
        return 1.0f;
    }
    int2 hCell = int2(floor(here.xy + ambient_frame.w.xx));
    int2 lCell = int2(floor(lampLot.xy + ambient_frame.w.xx));
    int2 param = lCell;
    int param_1 = 0;
    float param_2 = min(here.z, lampLot.z);
    int2 param_3 = hCell;
    int param_4 = 0;
    float param_5 = floorAt(param, param_1, param_2);
    float base0 = floorAt(param_3, param_4, param_5);
    float zMin = min(here.z, lampLot.z);
    float zMax = max(here.z, lampLot.z);
    float dz = here.z - lampLot.z;
    int sMin = max(1, int(floor(((zMin - base0) - 0.300000011920928955078125f) / 2.9500000476837158203125f)));
    int sMax = min((stories - 1), int(ceil(((zMax - base0) + 0.300000011920928955078125f) / 2.9500000476837158203125f)));
    float _5645;
    for (int s = sMin; s <= sMax; s++)
    {
        float nomZ = base0 + (float(s) * 2.9500000476837158203125f);
        bool _5604 = nomZ > (zMin + 0.0500000007450580596923828125f);
        bool _5611;
        if (_5604)
        {
            _5611 = nomZ < (zMax - 0.0500000007450580596923828125f);
        }
        else
        {
            _5611 = _5604;
        }
        bool between = _5611;
        bool _5614 = onFlatFloor > 0.5f;
        bool _5623;
        if (_5614)
        {
            _5623 = lampLot.z < (here.z - 0.20000000298023223876953125f);
        }
        else
        {
            _5623 = _5614;
        }
        bool _5632;
        if (_5623)
        {
            _5632 = abs(here.z - nomZ) < 0.23999999463558197021484375f;
        }
        else
        {
            _5632 = _5623;
        }
        bool underReceiverFloor = _5632;
        if ((!between) && (!underReceiverFloor))
        {
            continue;
        }
        if (abs(dz) > 9.9999997473787516355514526367188e-05f)
        {
            _5645 = clamp((nomZ - lampLot.z) / dz, 0.0f, 1.0f);
        }
        else
        {
            _5645 = 1.0f;
        }
        float t = _5645;
        float2 p = lerp(lampLot.xy, here.xy, t.xx) + ambient_frame.w.xx;
        int2 c = int2(floor(p));
        int2 param_6 = c;
        int param_7 = s;
        float param_8 = nomZ;
        float slabZ = floorAt(param_6, param_7, param_8);
        bool _5685 = slabZ > (zMin + 0.0500000007450580596923828125f);
        bool _5692;
        if (_5685)
        {
            _5692 = slabZ < (zMax - 0.0500000007450580596923828125f);
        }
        else
        {
            _5692 = _5685;
        }
        bool slabBetween = _5692;
        bool _5695 = onFlatFloor > 0.5f;
        bool _5703;
        if (_5695)
        {
            _5703 = lampLot.z < (slabZ - 0.20000000298023223876953125f);
        }
        else
        {
            _5703 = _5695;
        }
        bool _5712;
        if (_5703)
        {
            _5712 = abs(here.z - slabZ) < 0.23999999463558197021484375f;
        }
        else
        {
            _5712 = _5703;
        }
        bool slabUnderFloor = _5712;
        bool _5715 = slabBetween || slabUnderFloor;
        bool _5728;
        if (_5715)
        {
            int2 param_9 = c;
            int param_10 = s;
            float2 param_11 = p - float2(c);
            _5728 = hasFloorSlabAt(param_9, param_10, param_11);
        }
        else
        {
            _5728 = _5715;
        }
        if (_5728)
        {
            return 0.0f;
        }
    }
    return 1.0f;
}

float lampWallVis(float3 here, float3 lampLot, float onFlatFloor, float2 horizN)
{
    float2 start = (here.xy + ambient_frame.w.xx) + (horizN * (0.14000000059604644775390625f * (1.0f - onFlatFloor)));
    float2 end = lampLot.xy + ambient_frame.w.xx;
    float2 deltaXY = end - start;
    float distXY = length(deltaXY);
    if (distXY < 0.07999999821186065673828125f)
    {
        return 1.0f;
    }
    uint _5771_dummy_parameter;
    int2 maskTexSize = int2(spvTextureSize(indoorMap, uint(0), _5771_dummy_parameter));
    int2 param = maskTexSize;
    int maskBandH = indoorBandH(param);
    int stories = max(1, (maskTexSize.y / max(1, (5 * maskBandH))));
    float2 direction = deltaXY / distXY.xx;
    float rise = (lampLot.z - here.z) / distXY;
    float topGuard = lerp(0.0f, 0.119999997317790985107421875f, onFlatFloor);
    int2 cell = int2(floor(start));
    int2 stepDir = int2(sign(direction));
    float2 safeDir = direction + (float2(bool2(direction.x == 0.0f.xx.x, direction.y == 0.0f.xx.y)) * 9.9999997473787516355514526367188e-06f);
    float2 stepDelta = abs(1.0f.xx / safeDir);
    float2 next = ((float2(cell) + max(float2(stepDir), 0.0f.xx)) - start) / safeDir;
    float maxT = distXY - 0.0500000007450580596923828125f;
    float vis = 1.0f;
    float tPrev = 0.0f;
    float _5910;
    float _5981;
    float _6004;
    float _6081;
    int2 _6157;
    float _6191;
    float2 _6229;
    int _6245;
    int _6266;
    float _6300;
    int2 _6366;
    for (int i = 0; i < 28; i++)
    {
        bool _5850 = cell.x < 0;
        bool _5856;
        if (_5850)
        {
            _5856 = stepDir.x <= 0;
        }
        else
        {
            _5856 = _5850;
        }
        bool _5871;
        if (!_5856)
        {
            bool _5864 = cell.x >= maskTexSize.x;
            bool _5870;
            if (_5864)
            {
                _5870 = stepDir.x >= 0;
            }
            else
            {
                _5870 = _5864;
            }
            _5871 = _5870;
        }
        else
        {
            _5871 = _5856;
        }
        bool _5884;
        if (!_5871)
        {
            bool _5877 = cell.y < 0;
            bool _5883;
            if (_5877)
            {
                _5883 = stepDir.y <= 0;
            }
            else
            {
                _5883 = _5877;
            }
            _5884 = _5883;
        }
        else
        {
            _5884 = _5871;
        }
        bool _5898;
        if (!_5884)
        {
            bool _5891 = cell.y >= maskBandH;
            bool _5897;
            if (_5891)
            {
                _5897 = stepDir.y >= 0;
            }
            else
            {
                _5897 = _5891;
            }
            _5898 = _5897;
        }
        else
        {
            _5898 = _5884;
        }
        if (_5898)
        {
            break;
        }
        bool alongX = next.x < next.y;
        if (alongX)
        {
            _5910 = next.x;
        }
        else
        {
            _5910 = next.y;
        }
        float t = _5910;
        float segEnd = min(t, maxT);
        int2 param_1 = cell;
        int param_2 = 1;
        int param_3 = 0;
        int cellCode0 = maskCatAt(param_1, param_2, param_3);
        if ((segEnd > tPrev) && (cellCode0 != 0))
        {
            float zMid = here.z + ((0.5f * (tPrev + segEnd)) * rise);
            float cellBase0 = ambient_contact.w + (float(cellCode0 - 1) / 8.0f);
            int rowCell = clamp(int(floor(((zMid - cellBase0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f)), 0, stories - 1);
            int2 param_4 = cell;
            int param_5 = 2;
            int param_6 = rowCell;
            int part = maskCatAt(param_4, param_5, param_6) & 7;
            if (part != 0)
            {
                if (part <= 2)
                {
                    _5981 = direction.x - direction.y;
                }
                else
                {
                    _5981 = direction.x + direction.y;
                }
                float denom = _5981;
                if (abs(denom) > 9.9999997473787516355514526367188e-05f)
                {
                    if (part <= 2)
                    {
                        _6004 = ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom;
                    }
                    else
                    {
                        _6004 = ((1.0f - (start.x - float(cell.x))) - (start.y - float(cell.y))) / denom;
                    }
                    float tDiag = _6004;
                    bool _6044 = tDiag > max(tPrev, 0.02999999932944774627685546875f);
                    bool _6051;
                    if (_6044)
                    {
                        _6051 = tDiag <= (segEnd + 9.9999997473787516355514526367188e-05f);
                    }
                    else
                    {
                        _6051 = _6044;
                    }
                    if (_6051)
                    {
                        float2 uDiag = (start + (direction * tDiag)) - float2(cell);
                        bool _6067 = all(bool2(uDiag.x >= (-0.00999999977648258209228515625f).xx.x, uDiag.y >= (-0.00999999977648258209228515625f).xx.y));
                        bool _6075;
                        if (_6067)
                        {
                            _6075 = all(bool2(uDiag.x <= 1.0099999904632568359375f.xx.x, uDiag.y <= 1.0099999904632568359375f.xx.y));
                        }
                        else
                        {
                            _6075 = _6067;
                        }
                        if (_6075)
                        {
                            if (rowCell == 0)
                            {
                                _6081 = cellBase0;
                            }
                            else
                            {
                                int2 param_7 = cell;
                                int param_8 = rowCell;
                                float param_9 = cellBase0 + (float(rowCell) * 2.9500000476837158203125f);
                                _6081 = floorAt(param_7, param_8, param_9);
                            }
                            float floorH = _6081;
                            if (min(here.z, lampLot.z) < ((floorH + 2.9500000476837158203125f) - topGuard))
                            {
                                float relH = (here.z + (tDiag * rise)) - floorH;
                                float pen = 0.0500000007450580596923828125f + (0.02999999932944774627685546875f * tDiag);
                                float wallV = smoothstep(-0.039999999105930328369140625f, 0.039999999105930328369140625f, relH) * (1.0f - smoothstep(2.9500000476837158203125f - pen, 2.9500000476837158203125f + pen, relH));
                                vis = min(vis, 1.0f - wallV);
                                if (vis <= 0.00999999977648258209228515625f)
                                {
                                    return 0.0f;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (t > maxT)
        {
            break;
        }
        if (t > 0.02999999932944774627685546875f)
        {
            if (alongX)
            {
                _6157 = int2(stepDir.x, 0);
            }
            else
            {
                _6157 = int2(0, stepDir.y);
            }
            int2 to = cell + _6157;
            int2 param_10 = to;
            int param_11 = 1;
            int param_12 = 0;
            int toCode0 = maskCatAt(param_10, param_11, param_12);
            if ((cellCode0 | toCode0) != 0)
            {
                float zCross = here.z + (t * rise);
                if (cellCode0 != 0)
                {
                    _6191 = ambient_contact.w + (float(cellCode0 - 1) / 8.0f);
                }
                else
                {
                    _6191 = ambient_contact.w + (float(toCode0 - 1) / 8.0f);
                }
                float base0 = _6191;
                int row = clamp(int(floor(((zCross - base0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f)), 0, stories - 1);
                float2 crossing = start + (direction * t);
                if (alongX)
                {
                    _6229 = float2(float(stepDir.x), 0.0f);
                }
                else
                {
                    _6229 = float2(0.0f, float(stepDir.y));
                }
                float2 edgeStep = _6229;
                if (cellCode0 != 0)
                {
                    int2 param_13 = cell;
                    int param_14 = row;
                    float2 param_15 = (crossing - float2(cell)) - (edgeStep * 0.00999999977648258209228515625f);
                    _6245 = effectiveRoomAt(param_13, param_14, param_15);
                }
                else
                {
                    _6245 = 0;
                }
                int roomA = _6245;
                if (toCode0 != 0)
                {
                    int2 param_16 = to;
                    int param_17 = row;
                    float2 param_18 = (crossing - float2(to)) + (edgeStep * 0.00999999977648258209228515625f);
                    _6266 = effectiveRoomAt(param_16, param_17, param_18);
                }
                else
                {
                    _6266 = 0;
                }
                int roomB = _6266;
                bool _6286 = roomA != roomB;
                bool _6294;
                if (_6286)
                {
                    _6294 = (roomA > 0) || (roomB > 0);
                }
                else
                {
                    _6294 = _6286;
                }
                if (_6294)
                {
                    if (row == 0)
                    {
                        _6300 = base0;
                    }
                    else
                    {
                        int2 param_19 = to;
                        int param_20 = row;
                        float param_21 = base0 + (float(row) * 2.9500000476837158203125f);
                        int2 param_22 = cell;
                        int param_23 = row;
                        float param_24 = floorAt(param_19, param_20, param_21);
                        _6300 = floorAt(param_22, param_23, param_24);
                    }
                    float floorH_1 = _6300;
                    if (min(here.z, lampLot.z) < ((floorH_1 + 2.9500000476837158203125f) - topGuard))
                    {
                        float relH_1 = zCross - floorH_1;
                        float pen_1 = 0.0500000007450580596923828125f + (0.02999999932944774627685546875f * t);
                        float wallV_1 = smoothstep(-0.039999999105930328369140625f, 0.039999999105930328369140625f, relH_1) * (1.0f - smoothstep(2.9500000476837158203125f - pen_1, 2.9500000476837158203125f + pen_1, relH_1));
                        vis = min(vis, 1.0f - wallV_1);
                        if (vis <= 0.00999999977648258209228515625f)
                        {
                            return 0.0f;
                        }
                    }
                }
            }
            cell = to;
        }
        else
        {
            if (alongX)
            {
                _6366 = int2(stepDir.x, 0);
            }
            else
            {
                _6366 = int2(0, stepDir.y);
            }
            cell += _6366;
        }
        tPrev = t;
        if (alongX)
        {
            next.x += stepDelta.x;
        }
        else
        {
            next.y += stepDelta.y;
        }
    }
    return vis;
}

bool voxelColumnOverlap(float2 xy, float qMinZ, float qMaxZ, int vAoSize, int vAoYBase, float2 lotSz)
{
    bool _4937 = xy.x < (-0.449999988079071044921875f);
    bool _4944;
    if (!_4937)
    {
        _4944 = xy.y < (-0.449999988079071044921875f);
    }
    else
    {
        _4944 = _4937;
    }
    bool _4954;
    if (!_4944)
    {
        _4954 = xy.x > (lotSz.x + 0.449999988079071044921875f);
    }
    else
    {
        _4954 = _4944;
    }
    bool _4964;
    if (!_4954)
    {
        _4964 = xy.y > (lotSz.y + 0.449999988079071044921875f);
    }
    else
    {
        _4964 = _4954;
    }
    if (_4964)
    {
        return false;
    }
    int2 cg = clamp(int2(floor(xy * 8.0f)), int2(0, 0), (vAoSize - 1).xx);
    int y = vAoYBase + cg.y;
    int allMaxB = int((voxelMap.Load(int3(int2(cg.x, y), 0)).w * 255.0f) + 0.5f);
    bool _4996 = allMaxB == 0;
    bool _5009;
    if (!_4996)
    {
        _5009 = qMinZ > ((float(allMaxB - 1) * 0.125f) - 3.61999988555908203125f);
    }
    else
    {
        _5009 = _4996;
    }
    if (_5009)
    {
        return false;
    }
    int allMinB = int((voxelMap.Load(int3(int2(vAoSize + cg.x, y), 0)).w * 255.0f) + 0.5f);
    bool _5028 = allMinB > 0;
    bool _5039;
    if (_5028)
    {
        _5039 = qMaxZ < ((float(allMinB - 1) * 0.125f) - 4.38000011444091796875f);
    }
    else
    {
        _5039 = _5028;
    }
    if (_5039)
    {
        return false;
    }
    int s1MaxB = int((voxelMap.Load(int3(int2((2 * vAoSize) + cg.x, y), 0)).w * 255.0f) + 0.5f);
    bool _5059 = s1MaxB == 0;
    bool _5070;
    if (!_5059)
    {
        _5070 = qMinZ > ((float(s1MaxB - 1) * 0.125f) - 3.61999988555908203125f);
    }
    else
    {
        _5070 = _5059;
    }
    if (_5070)
    {
        int upMinB = int((voxelMap.Load(int3(int2((3 * vAoSize) + cg.x, y), 0)).w * 255.0f) + 0.5f);
        bool _5089 = upMinB == 0;
        bool _5100;
        if (!_5089)
        {
            _5100 = qMaxZ < ((float(upMinB - 1) * 0.125f) - 4.38000011444091796875f);
        }
        else
        {
            _5100 = _5089;
        }
        if (_5100)
        {
            return false;
        }
    }
    return true;
}

float sampleHullIntervalSlice(float2 op, float kMin, float kMax, float pad, float kTop, int yOffset, int2 sliceMax, float2 invVSize)
{
    float2 p = op - 0.5f.xx;
    int2 i0 = int2(floor(p));
    int2 gi = clamp(i0, int2(0, 0), max((sliceMax - int2(1, 1)), int2(0, 0)));
    float2 gUv = (float2(gi) + float2(1.0f, float(yOffset) + 1.0f)) * invVSize;
    float4 gR = voxelMap.GatherRed(_voxelMap_sampler, gUv) * 255.0f;
    float maxR = max(max(gR.x, gR.y), max(gR.z, gR.w));
    bool _4235 = maxR < 0.5f;
    bool _4246;
    if (!_4235)
    {
        _4246 = (maxR - 14.8999996185302734375f) < (kMin - pad);
    }
    else
    {
        _4246 = _4235;
    }
    if (_4246)
    {
        return 0.0f;
    }
    float4 gB = voxelMap.GatherBlue(_voxelMap_sampler, gUv) * 255.0f;
    bool _4260 = gR.x > 0.5f;
    bool _4270;
    if (_4260)
    {
        _4270 = (gR.x - 14.8999996185302734375f) >= (kMin - pad);
    }
    else
    {
        _4270 = _4260;
    }
    bool _4281;
    if (_4270)
    {
        _4281 = (gB.x - 16.1000003814697265625f) <= (kMax + pad);
    }
    else
    {
        _4281 = _4270;
    }
    bool _4284 = gR.y > 0.5f;
    bool _4294;
    if (_4284)
    {
        _4294 = (gR.y - 14.8999996185302734375f) >= (kMin - pad);
    }
    else
    {
        _4294 = _4284;
    }
    bool _4304;
    if (_4294)
    {
        _4304 = (gB.y - 16.1000003814697265625f) <= (kMax + pad);
    }
    else
    {
        _4304 = _4294;
    }
    bool _4307 = gR.z > 0.5f;
    bool _4317;
    if (_4307)
    {
        _4317 = (gR.z - 14.8999996185302734375f) >= (kMin - pad);
    }
    else
    {
        _4317 = _4307;
    }
    bool _4327;
    if (_4317)
    {
        _4327 = (gB.z - 16.1000003814697265625f) <= (kMax + pad);
    }
    else
    {
        _4327 = _4317;
    }
    bool _4330 = gR.w > 0.5f;
    bool _4340;
    if (_4330)
    {
        _4340 = (gR.w - 14.8999996185302734375f) >= (kMin - pad);
    }
    else
    {
        _4340 = _4330;
    }
    bool _4350;
    if (_4340)
    {
        _4350 = (gB.w - 16.1000003814697265625f) <= (kMax + pad);
    }
    else
    {
        _4350 = _4340;
    }
    bool4 cand = bool4(_4281, _4304, _4327, _4350);
    if (!any(cand))
    {
        return 0.0f;
    }
    float2 f = clamp(p - float2(i0), 0.0f.xx, 1.0f.xx);
    if (all(bool2(gi.x == i0.x, gi.y == i0.y)))
    {
        float4 gG = voxelMap.GatherGreen(_voxelMap_sampler, gUv) * 255.0f;
        float4 gA = voxelMap.GatherAlpha(_voxelMap_sampler, gUv) * 255.0f;
        float4 fCode = (floor(gR + 0.5f.xxxx) * 256.0f) + floor(gG + 0.5f.xxxx);
        float4 bCode = (floor(gB + 0.5f.xxxx) * 256.0f) + floor(gA + 0.5f.xxxx);
        float4 fk = (fCode * 0.00390625f) - 16.0f.xxxx;
        float4 bk = (bCode * 0.00390625f) - 16.0f.xxxx;
        float4 nz = step(0.5f.xxxx, fCode);
        float4 vv = (nz * smoothstep((-pad).xxxx, kTop.xxxx, fk - kMin.xxxx)) * smoothstep((-pad).xxxx, kTop.xxxx, kMax.xxxx - bk);
        return lerp(lerp(vv.w, vv.z, f.x), lerp(vv.x, vv.y, f.x), f.y);
    }
    int2 c00 = clamp(i0, int2(0, 0), sliceMax);
    int2 c10 = clamp(i0 + int2(1, 0), int2(0, 0), sliceMax);
    int2 c01 = clamp(i0 + int2(0, 1), int2(0, 0), sliceMax);
    int2 c11 = clamp(i0 + int2(1, 1), int2(0, 0), sliceMax);
    int4 r00 = int4((voxelMap.Load(int3(int2(c00.x, c00.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int4 r10 = int4((voxelMap.Load(int3(int2(c10.x, c10.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int4 r01 = int4((voxelMap.Load(int3(int2(c01.x, c01.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int4 r11 = int4((voxelMap.Load(int3(int2(c11.x, c11.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int f00 = (r00.x * 256) + r00.y;
    int f10 = (r10.x * 256) + r10.y;
    int f01 = (r01.x * 256) + r01.y;
    int f11 = (r11.x * 256) + r11.y;
    if ((((f00 | f10) | f01) | f11) == 0)
    {
        return 0.0f;
    }
    float _4582;
    if (f00 == 0)
    {
        _4582 = 0.0f;
    }
    else
    {
        _4582 = smoothstep(-pad, kTop, ((float(f00) / 256.0f) - 16.0f) - kMin) * smoothstep(-pad, kTop, kMax - ((float((r00.z * 256) + r00.w) / 256.0f) - 16.0f));
    }
    float v00 = _4582;
    float _4616;
    if (f10 == 0)
    {
        _4616 = 0.0f;
    }
    else
    {
        _4616 = smoothstep(-pad, kTop, ((float(f10) / 256.0f) - 16.0f) - kMin) * smoothstep(-pad, kTop, kMax - ((float((r10.z * 256) + r10.w) / 256.0f) - 16.0f));
    }
    float v10 = _4616;
    float _4650;
    if (f01 == 0)
    {
        _4650 = 0.0f;
    }
    else
    {
        _4650 = smoothstep(-pad, kTop, ((float(f01) / 256.0f) - 16.0f) - kMin) * smoothstep(-pad, kTop, kMax - ((float((r01.z * 256) + r01.w) / 256.0f) - 16.0f));
    }
    float v01 = _4650;
    float _4684;
    if (f11 == 0)
    {
        _4684 = 0.0f;
    }
    else
    {
        _4684 = smoothstep(-pad, kTop, ((float(f11) / 256.0f) - 16.0f) - kMin) * smoothstep(-pad, kTop, kMax - ((float((r11.z * 256) + r11.w) / 256.0f) - 16.0f));
    }
    float v11 = _4684;
    return lerp(lerp(v00, v10, f.x), lerp(v01, v11, f.x), f.y);
}

float evalHullInterval3D(float3 qSub, float3 halfStepQ, float pad, float kTop, int2 oSize, int halfH, float topMarginHalf, int2 sliceMax, float2 lotSz, float2 invVSize)
{
    float2 op0 = float2(((qSub.x - qSub.y) + lotSz.x) * 16.0f, (((qSub.x + qSub.y) * 8.0f) - (qSub.z * 20.0f)) + topMarginHalf);
    bool _4755 = any(bool2(op0.x < 0.0f.xx.x, op0.y < 0.0f.xx.y));
    bool _4765;
    if (!_4755)
    {
        _4765 = op0.x >= float(oSize.x);
    }
    else
    {
        _4765 = _4755;
    }
    bool _4774;
    if (!_4765)
    {
        _4774 = op0.y >= float(halfH);
    }
    else
    {
        _4774 = _4765;
    }
    if (_4774)
    {
        return 0.0f;
    }
    float k0Mid = (qSub.x + qSub.y) + (0.800000011920928955078125f * qSub.z);
    float dk0 = abs((halfStepQ.x + halfStepQ.y) + (0.800000011920928955078125f * halfStepQ.z));
    float2 param = op0;
    float param_1 = k0Mid - dk0;
    float param_2 = k0Mid + dk0;
    float param_3 = pad;
    float param_4 = kTop;
    int param_5 = 0;
    int2 param_6 = sliceMax;
    float2 param_7 = invVSize;
    float in0 = sampleHullIntervalSlice(param, param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    if (in0 <= 0.004999999888241291046142578125f)
    {
        return 0.0f;
    }
    float3 qB = float3(lotSz.y - qSub.y, qSub.x, qSub.z);
    float2 op1 = float2(((qB.x - qB.y) + lotSz.x) * 16.0f, (((qB.x + qB.y) * 8.0f) - (qB.z * 20.0f)) + topMarginHalf);
    bool _4862 = any(bool2(op1.x < 0.0f.xx.x, op1.y < 0.0f.xx.y));
    bool _4872;
    if (!_4862)
    {
        _4872 = op1.x >= float(oSize.x);
    }
    else
    {
        _4872 = _4862;
    }
    bool _4881;
    if (!_4872)
    {
        _4881 = op1.y >= float(halfH);
    }
    else
    {
        _4881 = _4872;
    }
    if (_4881)
    {
        return 0.0f;
    }
    float k1Mid = (qB.x + qB.y) + (0.800000011920928955078125f * qB.z);
    float dk1 = abs(((-halfStepQ.y) + halfStepQ.x) + (0.800000011920928955078125f * halfStepQ.z));
    float2 param_8 = op1;
    float param_9 = k1Mid - dk1;
    float param_10 = k1Mid + dk1;
    float param_11 = pad;
    float param_12 = kTop;
    int param_13 = halfH;
    int2 param_14 = sliceMax;
    float2 param_15 = invVSize;
    float in1 = sampleHullIntervalSlice(param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15);
    return min(in0, in1);
}

void stepHullCone4(float3 qMid, float3 dQ, float3 coneU, float3 coneV, float rTiles, float pad, float kTop, float distFade, int2 oSize, int halfH, float topMarginHalf, int2 sliceMax, float2 lotSz, float2 invVSize, inout float4 laneLit)
{
    float marginPx = (rTiles * 24.0f) + 3.0f;
    float2 op0Mid = float2(((qMid.x - qMid.y) + lotSz.x) * 16.0f, (((qMid.x + qMid.y) * 8.0f) - (qMid.z * 20.0f)) + topMarginHalf);
    float2 _5137 = (-marginPx).xx;
    bool _5139 = any(bool2(op0Mid.x < _5137.x, op0Mid.y < _5137.y));
    bool _5151;
    if (!_5139)
    {
        _5151 = op0Mid.x >= (float(oSize.x) + marginPx);
    }
    else
    {
        _5151 = _5139;
    }
    bool _5162;
    if (!_5151)
    {
        _5162 = op0Mid.y >= (float(halfH) + marginPx);
    }
    else
    {
        _5162 = _5151;
    }
    if (_5162)
    {
        return;
    }
    float3 qBMid = float3(lotSz.y - qMid.y, qMid.x, qMid.z);
    float2 op1Mid = float2(((qBMid.x - qBMid.y) + lotSz.x) * 16.0f, (((qBMid.x + qBMid.y) * 8.0f) - (qBMid.z * 20.0f)) + topMarginHalf);
    float2 _5203 = (-marginPx).xx;
    bool _5205 = any(bool2(op1Mid.x < _5203.x, op1Mid.y < _5203.y));
    bool _5217;
    if (!_5205)
    {
        _5217 = op1Mid.x >= (float(oSize.x) + marginPx);
    }
    else
    {
        _5217 = _5205;
    }
    bool _5228;
    if (!_5217)
    {
        _5228 = op1Mid.y >= (float(halfH) + marginPx);
    }
    else
    {
        _5228 = _5217;
    }
    if (_5228)
    {
        return;
    }
    float3 halfStepQ = dQ * 0.5f;
    if (rTiles <= 0.048000000417232513427734375f)
    {
        if (max(max(laneLit.x, laneLit.y), max(laneLit.z, laneLit.w)) > 0.006000000052154064178466796875f)
        {
            float3 param = qMid;
            float3 param_1 = halfStepQ;
            float param_2 = pad;
            float param_3 = kTop;
            int2 param_4 = oSize;
            int param_5 = halfH;
            float param_6 = topMarginHalf;
            int2 param_7 = sliceMax;
            float2 param_8 = lotSz;
            float2 param_9 = invVSize;
            float occC = evalHullInterval3D(param, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9) * distFade;
            laneLit = min(laneLit, (1.0f - occC).xxxx);
        }
        return;
    }
    float3 uScaled = coneU * rTiles;
    float3 vScaled = coneV * rTiles;
    float3 offA = (uScaled * 0.560000002384185791015625f) + (vScaled * 0.23999999463558197021484375f);
    float3 offB = ((-uScaled) * 0.23999999463558197021484375f) + (vScaled * 0.560000002384185791015625f);
    if (laneLit.x > 0.006000000052154064178466796875f)
    {
        float3 param_10 = qMid - offA;
        float3 param_11 = halfStepQ;
        float param_12 = pad;
        float param_13 = kTop;
        int2 param_14 = oSize;
        int param_15 = halfH;
        float param_16 = topMarginHalf;
        int2 param_17 = sliceMax;
        float2 param_18 = lotSz;
        float2 param_19 = invVSize;
        float occ0 = evalHullInterval3D(param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19) * distFade;
        laneLit.x = min(laneLit.x, 1.0f - occ0);
    }
    if (laneLit.y > 0.006000000052154064178466796875f)
    {
        float3 param_20 = qMid - offB;
        float3 param_21 = halfStepQ;
        float param_22 = pad;
        float param_23 = kTop;
        int2 param_24 = oSize;
        int param_25 = halfH;
        float param_26 = topMarginHalf;
        int2 param_27 = sliceMax;
        float2 param_28 = lotSz;
        float2 param_29 = invVSize;
        float occ1 = evalHullInterval3D(param_20, param_21, param_22, param_23, param_24, param_25, param_26, param_27, param_28, param_29) * distFade;
        laneLit.y = min(laneLit.y, 1.0f - occ1);
    }
    if (laneLit.z > 0.006000000052154064178466796875f)
    {
        float3 param_30 = qMid + offB;
        float3 param_31 = halfStepQ;
        float param_32 = pad;
        float param_33 = kTop;
        int2 param_34 = oSize;
        int param_35 = halfH;
        float param_36 = topMarginHalf;
        int2 param_37 = sliceMax;
        float2 param_38 = lotSz;
        float2 param_39 = invVSize;
        float occ2 = evalHullInterval3D(param_30, param_31, param_32, param_33, param_34, param_35, param_36, param_37, param_38, param_39) * distFade;
        laneLit.z = min(laneLit.z, 1.0f - occ2);
    }
    if (laneLit.w > 0.006000000052154064178466796875f)
    {
        float3 param_40 = qMid + offA;
        float3 param_41 = halfStepQ;
        float param_42 = pad;
        float param_43 = kTop;
        int2 param_44 = oSize;
        int param_45 = halfH;
        float param_46 = topMarginHalf;
        int2 param_47 = sliceMax;
        float2 param_48 = lotSz;
        float2 param_49 = invVSize;
        float occ3 = evalHullInterval3D(param_40, param_41, param_42, param_43, param_44, param_45, param_46, param_47, param_48, param_49) * distFade;
        laneLit.w = min(laneLit.w, 1.0f - occ3);
    }
}

float dynamicSimOccInterval(float2 wp, float2 wSize, float kMin, float kMax, float pad)
{
    bool _3860 = any(bool2(wp.x < 0.5f.xx.x, wp.y < 0.5f.xx.y));
    bool _3870;
    if (!_3860)
    {
        float2 _3867 = wSize - 0.5f.xx;
        _3870 = any(bool2(wp.x >= _3867.x, wp.y >= _3867.y));
    }
    else
    {
        _3870 = _3860;
    }
    if (_3870)
    {
        return 0.0f;
    }
    float2 uv = wp / wSize;
    float4 wFront = worldDepthMap.GatherRed(_worldDepthMap_sampler, uv);
    if (min(min(wFront.x, wFront.y), min(wFront.z, wFront.w)) >= 0.99989998340606689453125f)
    {
        return 0.0f;
    }
    float4 wBack = worldBackDepthMap.GatherRed(_worldBackDepthMap_sampler, uv);
    float4 valid = step(wFront, 0.99989998340606689453125f.xxxx) * step(9.9999997473787516355514526367188e-05f.xxxx, wBack);
    float4 fKey = (0.62000000476837158203125f.xxxx - wFront) / 0.0030000000260770320892333984375f.xxxx;
    float4 bKey = (0.62000000476837158203125f.xxxx - wBack) / 0.0030000000260770320892333984375f.xxxx;
    float4 inSim = (valid * smoothstep((-pad).xxxx, 0.0500000007450580596923828125f.xxxx, fKey - kMin.xxxx)) * smoothstep((-pad).xxxx, 0.0500000007450580596923828125f.xxxx, kMax.xxxx - bKey);
    float2 f = frac(wp - 0.5f.xx);
    return lerp(lerp(inSim.w, inSim.z, f.x), lerp(inSim.x, inSim.y, f.x), f.y);
}

void stepSimCone2(float3 qMid, float3 dQ, float pad, float rPx, float2 sunPerp, float distFade, float2 wSize, inout float2 simLaneLit)
{
    if (ambient_shadowView.w <= 0.5f)
    {
        return;
    }
    float2 sceneMid = float2(32.0f * (qMid.x - qMid.y), (16.0f * (qMid.x + qMid.y)) - (40.0f * qMid.z)) + ambient_frame.xy;
    float2 wpMid = ambient_shadowView.xy + (sceneMid * ambient_shadowView.z);
    float rBound = (0.5f * rPx) + 2.0f;
    bool _4013 = wpMid.x < (ambient_dynShadowBounds.x - rBound);
    bool _4024;
    if (!_4013)
    {
        _4024 = wpMid.y < (ambient_dynShadowBounds.y - rBound);
    }
    else
    {
        _4024 = _4013;
    }
    bool _4035;
    if (!_4024)
    {
        _4035 = wpMid.x > (ambient_dynShadowBounds.z + rBound);
    }
    else
    {
        _4035 = _4024;
    }
    bool _4046;
    if (!_4035)
    {
        _4046 = wpMid.y > (ambient_dynShadowBounds.w + rBound);
    }
    else
    {
        _4046 = _4035;
    }
    if (_4046)
    {
        return;
    }
    bool _4054 = any(bool2(wpMid.x < (-3.0f).xx.x, wpMid.y < (-3.0f).xx.y));
    bool _4064;
    if (!_4054)
    {
        float2 _4061 = wSize + 3.0f.xx;
        _4064 = any(bool2(wpMid.x >= _4061.x, wpMid.y >= _4061.y));
    }
    else
    {
        _4064 = _4054;
    }
    if (_4064)
    {
        return;
    }
    float kMid = (qMid.x + qMid.y) + (0.800000011920928955078125f * qMid.z);
    float dkHalf = 0.5f * abs((dQ.x + dQ.y) + (0.800000011920928955078125f * dQ.z));
    float kMin = kMid - dkHalf;
    float kMax = kMid + dkHalf;
    if (rPx <= 1.25f)
    {
        if (max(simLaneLit.x, simLaneLit.y) > 0.006000000052154064178466796875f)
        {
            float2 param = wpMid;
            float2 param_1 = wSize;
            float param_2 = kMin;
            float param_3 = kMax;
            float param_4 = pad;
            float occ = dynamicSimOccInterval(param, param_1, param_2, param_3, param_4) * distFade;
            simLaneLit = min(simLaneLit, (1.0f - occ).xx);
        }
        return;
    }
    float2 off = sunPerp * (0.449999988079071044921875f * rPx);
    if (simLaneLit.x > 0.006000000052154064178466796875f)
    {
        float2 param_5 = wpMid - off;
        float2 param_6 = wSize;
        float param_7 = kMin;
        float param_8 = kMax;
        float param_9 = pad;
        float occ0 = dynamicSimOccInterval(param_5, param_6, param_7, param_8, param_9) * distFade;
        simLaneLit.x = min(simLaneLit.x, 1.0f - occ0);
    }
    if (simLaneLit.y > 0.006000000052154064178466796875f)
    {
        float2 param_10 = wpMid + off;
        float2 param_11 = wSize;
        float param_12 = kMin;
        float param_13 = kMax;
        float param_14 = pad;
        float occ1 = dynamicSimOccInterval(param_10, param_11, param_12, param_13, param_14) * distFade;
        simLaneLit.y = min(simLaneLit.y, 1.0f - occ1);
    }
}

float2 hiddenAtWorld(float2 wp, float key, float2 wSize, float shellDepth, float frontSoft)
{
    bool _1856 = any(bool2(wp.x < 1.0f.xx.x, wp.y < 1.0f.xx.y));
    bool _1866;
    if (!_1856)
    {
        float2 _1863 = wSize - 1.0f.xx;
        _1866 = any(bool2(wp.x >= _1863.x, wp.y >= _1863.y));
    }
    else
    {
        _1866 = _1856;
    }
    if (_1866)
    {
        return 0.0f.xx;
    }
    float2 uv = wp / wSize;
    float4 wFront = worldDepthMap.GatherRed(_worldDepthMap_sampler, uv);
    if (min(min(wFront.x, wFront.y), min(wFront.z, wFront.w)) >= 0.99989998340606689453125f)
    {
        return 0.0f.xx;
    }
    float2 f = frac(wp - 0.5f.xx);
    float backSoft = max(0.12999999523162841796875f, 0.4799999892711639404296875f * shellDepth);
    float4 vFront = step(wFront, 0.99989998340606689453125f.xxxx);
    float4 bFront = ((0.62000000476837158203125f.xxxx - wFront) / 0.0030000000260770320892333984375f.xxxx) - key.xxxx;
    float4 vis = (vFront * smoothstep((0.37999999523162841796875f * shellDepth).xxxx, (0.819999992847442626953125f * shellDepth).xxxx, bFront)) * (1.0f.xxxx - smoothstep(1.85000002384185791015625f.xxxx, 2.75f.xxxx, bFront));
    float4 shlF = (vFront * clamp((bFront + (0.550000011920928955078125f * frontSoft).xxxx) / frontSoft.xxxx, 0.0f.xxxx, 1.0f.xxxx)) * clamp((shellDepth.xxxx - bFront) / backSoft.xxxx, 0.0f.xxxx, 1.0f.xxxx);
    float4 shl = shlF;
    if (min(min(shlF.x, shlF.y), min(shlF.z, shlF.w)) < 0.9900000095367431640625f)
    {
        float4 wBack = worldBackDepthMap.GatherRed(_worldBackDepthMap_sampler, uv);
        float4 vBack = step(9.9999997473787516355514526367188e-05f.xxxx, wBack) * step(wBack, 0.99989998340606689453125f.xxxx);
        float4 bBack = ((0.62000000476837158203125f.xxxx - wBack) / 0.0030000000260770320892333984375f.xxxx) - key.xxxx;
        float4 shlB = (vBack * clamp((bBack + (0.550000011920928955078125f * frontSoft).xxxx) / frontSoft.xxxx, 0.0f.xxxx, 1.0f.xxxx)) * clamp((shellDepth.xxxx - bBack) / backSoft.xxxx, 0.0f.xxxx, 1.0f.xxxx);
        shl = max(shlF, shlB);
    }
    return float2(lerp(lerp(vis.w, vis.z, f.x), lerp(vis.x, vis.y, f.x), f.y), lerp(lerp(shl.w, shl.z, f.x), lerp(shl.x, shl.y, f.x), f.y));
}

float2 hiddenAtSoft(float3 q, float spreadPx, float2 rayPerp, float2 rayDirPx, float keyPerPx, float shellDepth, float frontSoft, float2 diskJitter)
{
    float2 scene = float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
    float key = (q.x + q.y) + (0.800000011920928955078125f * q.z);
    if (ambient_shadowView.w > 0.5f)
    {
        uint _2112_dummy_parameter;
        float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _2112_dummy_parameter)));
        float2 wp = ambient_shadowView.xy + (scene * ambient_shadowView.z);
        float w1 = smoothstep(0.25f, 1.0f, spreadPx);
        float r = spreadPx * w1;
        float2 off = (rayPerp * (diskJitter.x * r)) + (rayDirPx * ((diskJitter.y * 0.7799999713897705078125f) * r));
        float kOff = keyPerPx * ((diskJitter.y * 0.7799999713897705078125f) * r);
        float2 param = wp + off;
        float param_1 = key + kOff;
        float2 param_2 = wSize;
        float param_3 = shellDepth;
        float param_4 = frontSoft;
        return hiddenAtWorld(param, param_1, param_2, param_3, param_4);
    }
    float2 pixel = floor(ambient_view.xy + (scene * ambient_view.z)) + 0.5f.xx;
    bool _2185 = any(bool2(pixel.x < 0.0f.xx.x, pixel.y < 0.0f.xx.y));
    bool _2194;
    if (!_2185)
    {
        _2194 = pixel.x >= ambient_extent.x;
    }
    else
    {
        _2194 = _2185;
    }
    bool _2203;
    if (!_2194)
    {
        _2203 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _2203 = _2194;
    }
    if (_2203)
    {
        return float2(1.0f, 0.0f);
    }
    float depth = depthMap.Load(int3(int2(pixel), 0)).x;
    if (depth < 1.0f)
    {
        float behind = ((0.62000000476837158203125f - depth) / 0.0030000000260770320892333984375f) - key;
        float backSoft = max(0.14000000059604644775390625f, 0.4799999892711639404296875f * shellDepth);
        return float2(clamp((behind + 0.0599999986588954925537109375f) / 0.180000007152557373046875f, 0.0f, 1.0f), clamp((behind + (0.550000011920928955078125f * frontSoft)) / frontSoft, 0.0f, 1.0f) * clamp((shellDepth - behind) / backSoft, 0.0f, 1.0f));
    }
    float ground = groundMap.Load(int3(int2(pixel), 0)).x;
    if (ground >= 1.0f)
    {
        return 0.0f.xx;
    }
    float2 param_5 = scene;
    float param_6 = ((0.62000000476837158203125f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w;
    bool param_7 = true;
    float2 param_8 = ambient_frame.xy;
    float3 lot = lotPoint(param_5, param_6, param_7, param_8);
    return float2(clamp(((((lot.x + lot.y) + (0.800000011920928955078125f * lot.z)) - key) + 0.4000000059604644775390625f) / 0.300000011920928955078125f, 0.0f, 1.0f), 0.0f);
}

float lampMarch(float3 here, float3 lampLot, float onFlatFloor, float isVertical, float nUp, float2 horizN, bool isFire, float onSim)
{
    float3 origin = here + float3(horizN * (0.1599999964237213134765625f * isVertical), 0.0f);
    float3 toReceiver = origin - lampLot;
    float dist3D = length(toReceiver);
    float horizTop = smoothstep(0.75f, 0.920000016689300537109375f, nUp) * step(origin.z + 0.20000000298023223876953125f, lampLot.z);
    float receiverClear = lerp(lerp(0.4799999892711639404296875f, 0.14000000059604644775390625f, max(isVertical, horizTop)), 0.07999999821186065673828125f, onFlatFloor);
    receiverClear = lerp(receiverClear, 0.579999983310699462890625f, onSim);
    float rStart = isFire ? 0.519999980926513671875f : 0.4600000083446502685546875f;
    float rEnd = dist3D - receiverClear;
    if (rEnd <= (rStart + 0.02999999932944774627685546875f))
    {
        return 1.0f;
    }
    float3 outDir = toReceiver / dist3D.xxx;
    uint _6466_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _6466_dummy_parameter)));
    int2 hMax = int2(gridSize) - int2(1, 1);
    uint _6476_dummy_parameter;
    int2 vSize = int2(spvTextureSize(voxelMap, uint(0), _6476_dummy_parameter));
    bool hasVoxels = vSize.x > 1;
    float2 invVSize = 1.0f.xx / float2(max(vSize, int2(1, 1)));
    uint _6490_dummy_parameter;
    float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _6490_dummy_parameter)));
    int _6494;
    if (hasVoxels)
    {
        int2 param = vSize;
        _6494 = voxelAoRows(param);
    }
    else
    {
        _6494 = 1;
    }
    int vAoRows = _6494;
    int vHalfH = ((vSize.x / 2) + 128) + (256 * vAoRows);
    int vAoSize = vSize.x / 4;
    int vAoYBase = vHalfH * 2;
    bool _6521 = hasVoxels && (vAoSize > 0);
    bool _6530;
    if (_6521)
    {
        _6530 = vSize.y >= (vAoYBase + vAoSize);
    }
    else
    {
        _6530 = _6521;
    }
    bool hasColBounds = _6530;
    float vTopMarginHalf = float(64 + (256 * vAoRows));
    int2 vSliceMax = int2(vSize.x - 1, vHalfH - 1);
    float2 lotSz = max(ambient_drift.zw, 1.0f.xx);
    float2 rayProj = float2(32.0f * (outDir.x - outDir.y), (16.0f * (outDir.x + outDir.y)) - (40.0f * outDir.z));
    float projLen = length(rayProj);
    float2 _6572;
    if (projLen > 0.001000000047497451305389404296875f)
    {
        _6572 = rayProj / projLen.xx;
    }
    else
    {
        _6572 = float2(1.0f, 0.0f);
    }
    float2 rayDirPx = _6572;
    float2 rayPerp = float2(-rayDirPx.y, rayDirPx.x);
    float wScale = max(ambient_shadowView.z, 0.5f);
    float drBase = clamp(1.5f / max(projLen, 20.0f), 0.05200000107288360595703125f, 0.0719999969005584716796875f);
    float spanR = rEnd - rStart;
    float farAccel = max(0.0f, (spanR - (32.0f * drBase)) / 496.0f);
    float signedKeyRate = (outDir.x + outDir.y) + (0.800000011920928955078125f * outDir.z);
    float keyRate = abs(signedKeyRate);
    float keyPerPx = signedKeyRate / max(projLen * wScale, 1.0f);
    float horizLen = length(outDir.xy);
    float2 _6638;
    if (horizLen > 9.9999997473787516355514526367188e-05f)
    {
        _6638 = (float2(-outDir.y, outDir.x) / horizLen.xx) * 1.4500000476837158203125f;
    }
    else
    {
        _6638 = float2(1.4500000476837158203125f, 0.0f);
    }
    float2 perpTexel = _6638;
    float lightRadiusScenePx = isFire ? 11.0f : 7.0f;
    float2 diskJitter = 0.0f.xx;
    bool3 _6668 = (abs(outDir.z) < 0.920000016689300537109375f).xxx;
    float3 refAxis = float3(_6668.x ? float3(0.0f, 0.0f, 1.0f).x : float3(1.0f, 0.0f, 0.0f).x, _6668.y ? float3(0.0f, 0.0f, 1.0f).y : float3(1.0f, 0.0f, 0.0f).y, _6668.z ? float3(0.0f, 0.0f, 1.0f).z : float3(1.0f, 0.0f, 0.0f).z);
    float3 coneU = normalize(cross(outDir, refAxis));
    float3 coneV = cross(outDir, coneU);
    float4 laneLit = 1.0f.xxxx;
    float2 simLaneLit = 1.0f.xx;
    float r = rStart;
    float solidRun = 0.0f;
    float lit = 1.0f;
    float _6906;
    float _7089;
    for (int i = 0; i < 32; i++)
    {
        if (r >= rEnd)
        {
            break;
        }
        float dr = drBase + (farAccel * float(i));
        float rNext = min(r + dr, rEnd);
        float stepLen = rNext - r;
        if (stepLen <= 9.9999997473787516355514526367188e-05f)
        {
            break;
        }
        float rMid = r + (0.5f * stepLen);
        float3 q = lampLot + (outDir * rMid);
        float xyFromLamp = length(q.xy - lampLot.xy);
        if (xyFromLamp >= (isFire ? 0.449999988079071044921875f : 0.4199999868869781494140625f))
        {
            float2 texel = (q.xy + ambient_frame.w.xx) * ambient_frame.z;
            bool _6760 = all(bool2(texel.x >= 1.0f.xx.x, texel.y >= 1.0f.xx.y));
            bool _6769;
            if (_6760)
            {
                float2 _6766 = gridSize - 1.0f.xx;
                _6769 = all(bool2(texel.x <= _6766.x, texel.y <= _6766.y));
            }
            else
            {
                _6769 = _6760;
            }
            if (_6769)
            {
                float dToReceiver = max(rEnd - rMid, 0.0f);
                float coneFrac = clamp(dToReceiver / max(dist3D, 0.3499999940395355224609375f), 0.0f, 1.0f);
                float spreadPx = clamp(0.319999992847442626953125f + (lightRadiusScenePx * coneFrac), 0.319999992847442626953125f, 4.400000095367431640625f) * wScale;
                float sourceFade = smoothstep(0.0f, 0.180000007152557373046875f, rMid - rStart);
                float receiverFade = smoothstep(0.0f, stepLen * 1.5f, rEnd - rMid);
                float fade = sourceFade * receiverFade;
                if (hasVoxels)
                {
                    float3 dQ = outDir * stepLen;
                    float halfDz = 0.5f * abs(dQ.z);
                    bool _6823 = !hasColBounds;
                    bool _6847;
                    if (!_6823)
                    {
                        float2 param_1 = q.xy;
                        float param_2 = q.z - halfDz;
                        float param_3 = q.z + halfDz;
                        int param_4 = vAoSize;
                        int param_5 = vAoYBase;
                        float2 param_6 = lotSz;
                        _6847 = voxelColumnOverlap(param_1, param_2, param_3, param_4, param_5, param_6);
                    }
                    else
                    {
                        _6847 = _6823;
                    }
                    bool checkLampHull = _6847;
                    if (checkLampHull)
                    {
                        float rTiles = clamp(0.0170000009238719940185546875f + ((isFire ? 0.17499999701976776123046875f : 0.125f) * coneFrac), 0.0170000009238719940185546875f, 0.194999992847442626953125f);
                        float pad = 0.2199999988079071044921875f + (1.0499999523162841796875f * rTiles);
                        float kTop = 0.0599999986588954925537109375f + (0.37999999523162841796875f * rTiles);
                        float3 param_7 = q;
                        float3 param_8 = dQ;
                        float3 param_9 = coneU;
                        float3 param_10 = coneV;
                        float param_11 = rTiles;
                        float param_12 = pad;
                        float param_13 = kTop;
                        float param_14 = fade;
                        int2 param_15 = vSize;
                        int param_16 = vHalfH;
                        float param_17 = vTopMarginHalf;
                        int2 param_18 = vSliceMax;
                        float2 param_19 = lotSz;
                        float2 param_20 = invVSize;
                        float4 param_21 = laneLit;
                        stepHullCone4(param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21);
                        laneLit = param_21;
                    }
                    if (onSim > 0.5f)
                    {
                        _6906 = smoothstep(0.4000000059604644775390625f, 0.64999997615814208984375f, dToReceiver);
                    }
                    else
                    {
                        _6906 = 1.0f;
                    }
                    float simLampGuard = _6906;
                    if (simLampGuard > 0.00999999977648258209228515625f)
                    {
                        float rSimPx = clamp(0.3499999940395355224609375f + ((isFire ? 2.400000095367431640625f : 1.75f) * coneFrac), 0.3499999940395355224609375f, 2.400000095367431640625f) * wScale;
                        float3 param_22 = q;
                        float3 param_23 = dQ;
                        float param_24 = 0.180000007152557373046875f;
                        float param_25 = rSimPx;
                        float2 param_26 = rayPerp;
                        float param_27 = fade * simLampGuard;
                        float2 param_28 = wSize;
                        float2 param_29 = simLaneLit;
                        stepSimCone2(param_22, param_23, param_24, param_25, param_26, param_27, param_28, param_29);
                        simLaneLit = param_29;
                    }
                    float maxLane = max(max(laneLit.x, laneLit.y), max(laneLit.z, laneLit.w));
                    float maxSim = max(simLaneLit.x, simLaneLit.y);
                    if (min(maxLane, maxSim) <= 0.008000000379979610443115234375f)
                    {
                        return 0.0f;
                    }
                }
                else
                {
                    if ((onSim < 0.5f) || (dToReceiver > 0.449999988079071044921875f))
                    {
                        float penZ = 0.07999999821186065673828125f + (0.10999999940395355224609375f * dToReceiver);
                        float4 tops = (0.5f.xxxx - heightMap.GatherRed(_heightMap_sampler, texel / gridSize)) * 128.0f;
                        float4 blocked = clamp(((tops - q.z.xxxx) - 0.0500000007450580596923828125f.xxxx) / penZ.xxxx, 0.0f.xxxx, 1.0f.xxxx);
                        float2 f = frac(texel - 0.5f.xx);
                        float rawColumn = lerp(lerp(blocked.w, blocked.z, f.x), lerp(blocked.x, blocked.y, f.x), f.y);
                        float coreColumn = 0.0f;
                        if (rawColumn > 0.550000011920928955078125f)
                        {
                            float topL = (0.5f - heightMap.Load(int3(clamp(int2(floor(texel + perpTexel)), int2(0, 0), hMax), 0)).x) * 128.0f;
                            float topR = (0.5f - heightMap.Load(int3(clamp(int2(floor(texel - perpTexel)), int2(0, 0), hMax), 0)).x) * 128.0f;
                            float sideBlocked = min(clamp(((topL - q.z) - 0.0500000007450580596923828125f) / penZ, 0.0f, 1.0f), clamp(((topR - q.z) - 0.0500000007450580596923828125f) / penZ, 0.0f, 1.0f));
                            float eroded = min(rawColumn, sideBlocked);
                            if (eroded > 0.64999997615814208984375f)
                            {
                                _7089 = solidRun + stepLen;
                            }
                            else
                            {
                                _7089 = max(0.0f, solidRun - (2.0f * stepLen));
                            }
                            solidRun = _7089;
                            coreColumn = smoothstep(0.579999983310699462890625f, 0.920000016689300537109375f, eroded) * smoothstep(0.14000000059604644775390625f, 0.2800000011920928955078125f, solidRun);
                        }
                        else
                        {
                            solidRun = max(0.0f, solidRun - (2.0f * stepLen));
                        }
                        float stepKey = keyRate * stepLen;
                        float canopyLift = smoothstep(1.5f, 3.0f, max(0.0f, q.z - origin.z));
                        float frontSoft = 0.14000000059604644775390625f + (0.054999999701976776123046875f * dToReceiver);
                        float shellDepth = (max(0.180000007152557373046875f, (stepKey * 1.60000002384185791015625f) + 0.119999997317790985107421875f) + (0.1599999964237213134765625f * coreColumn)) + (0.20000000298023223876953125f * canopyLift);
                        float3 param_30 = q;
                        float param_31 = spreadPx;
                        float2 param_32 = rayPerp;
                        float2 param_33 = rayDirPx;
                        float param_34 = keyPerPx;
                        float param_35 = shellDepth;
                        float param_36 = frontSoft;
                        float2 param_37 = diskJitter;
                        float2 seen = hiddenAtSoft(param_30, param_31, param_32, param_33, param_34, param_35, param_36, param_37);
                        float shell = seen.y * (0.939999997615814208984375f / (1.0f + (0.039999999105930328369140625f * dToReceiver)));
                        float occ = max(coreColumn * seen.x, shell);
                        lit = min(lit, 1.0f - (occ * fade));
                        if (lit <= 0.00999999977648258209228515625f)
                        {
                            return 0.0f;
                        }
                    }
                }
            }
        }
        r = rNext;
    }
    if (hasVoxels)
    {
        float hullVis = dot(laneLit, 0.25f.xxxx);
        float simVis = 0.5f * (simLaneLit.x + simLaneLit.y);
        return min(hullVis, simVis);
    }
    return lit;
}

void dayPalette(float p, inout float3 sunCol, inout float3 shadeCol, inout float3 winCol)
{
    float t1 = smoothstep(0.07999999821186065673828125f, 0.2599999904632568359375f, p);
    float t2 = smoothstep(0.2800000011920928955078125f, 0.4799999892711639404296875f, p);
    float t3 = smoothstep(0.540000021457672119140625f, 0.7599999904632568359375f, p);
    float t4 = smoothstep(0.7599999904632568359375f, 0.930000007152557373046875f, p);
    sunCol = lerp(float3(1.2599999904632568359375f, 0.930000007152557373046875f, 0.7400000095367431640625f), float3(0.939999997615814208984375f, 1.0099999904632568359375f, 1.08000004291534423828125f), t1.xxx);
    sunCol = lerp(sunCol, float3(1.019999980926513671875f, 1.0099999904632568359375f, 0.959999978542327880859375f), t2.xxx);
    sunCol = lerp(sunCol, float3(1.13999998569488525390625f, 1.0f, 0.810000002384185791015625f), t3.xxx);
    sunCol = lerp(sunCol, float3(1.2999999523162841796875f, 0.88999998569488525390625f, 0.560000002384185791015625f), t4.xxx);
    shadeCol = lerp(float3(0.75f, 0.85000002384185791015625f, 1.25f), float3(0.800000011920928955078125f, 0.939999997615814208984375f, 1.2200000286102294921875f), t1.xxx);
    shadeCol = lerp(shadeCol, float3(0.839999973773956298828125f, 0.939999997615814208984375f, 1.17999994754791259765625f), t2.xxx);
    shadeCol = lerp(shadeCol, float3(0.790000021457672119140625f, 0.88999998569488525390625f, 1.21000003814697265625f), t3.xxx);
    shadeCol = lerp(shadeCol, float3(0.7200000286102294921875f, 0.800000011920928955078125f, 1.2599999904632568359375f), t4.xxx);
    winCol = lerp(float3(1.17999994754791259765625f, 0.819999992847442626953125f, 0.579999983310699462890625f), float3(0.959999978542327880859375f, 0.9900000095367431640625f, 1.03999996185302734375f), t1.xxx);
    winCol = lerp(winCol, float3(1.019999980926513671875f, 0.9700000286102294921875f, 0.87999999523162841796875f), t2.xxx);
    winCol = lerp(winCol, float3(1.10000002384185791015625f, 0.87999999523162841796875f, 0.60000002384185791015625f), t3.xxx);
    winCol = lerp(winCol, float3(1.2000000476837158203125f, 0.699999988079071044921875f, 0.36000001430511474609375f), t4.xxx);
}

float3 multiBounceAO(float ao, float3 alb)
{
    float3 a = (alb * 2.040400028228759765625f) - 0.3323999941349029541015625f.xxx;
    float3 b = (alb * (-4.79510021209716796875f)) + 0.6417000293731689453125f.xxx;
    float3 c = (alb * 2.755199909210205078125f) + 0.69029998779296875f.xxx;
    return max(ao.xxx, ((((a * ao) + b) * ao) + c) * ao);
}

float3 sampleStoryBounce(float2 lotXY, int levelRow, int stories, float2 camLotSz, int2 bSize)
{
    if (((bSize.x <= 1) || (levelRow < 0)) || (levelRow >= stories))
    {
        return 0.0f.xxx;
    }
    int cols = min(stories, 4);
    int rows = max(1, ((stories + 3) / 4));
    float sliceW = float(bSize.x) / float(cols);
    float sliceH = float(bSize.y) / float(rows);
    int colIdx = levelRow & 3;
    int rowIdx = levelRow >> 2;
    float2 localPx = clamp((lotXY / camLotSz) * float2(sliceW, sliceH), 0.5f.xx, float2(sliceW - 0.5f, sliceH - 0.5f));
    float2 uv = (float2(float(colIdx) * sliceW, float(rowIdx) * sliceH) + localPx) / float2(bSize);
    float4 tap = bounceMap.Sample(_bounceMap_sampler, uv);
    float3 _11476;
    if (tap.w > 0.0199999995529651641845703125f)
    {
        _11476 = tap.xyz / max(tap.w, 0.0500000007450580596923828125f).xxx;
    }
    else
    {
        _11476 = 0.0f.xxx;
    }
    return _11476;
}

float3 gatherRoomBounceGI(float3 here, float2 horizN, float2 nLotXY, float isVertical, float onFlatFloor, float onDynamicSim, int storiesCount)
{
    uint _11493_dummy_parameter;
    int2 bSize = int2(spvTextureSize(bounceMap, uint(0), _11493_dummy_parameter));
    bool _11496 = bSize.x <= 1;
    bool _11504;
    if (!_11496)
    {
        _11504 = ambient_skyExtra.w <= 0.001000000047497451305389404296875f;
    }
    else
    {
        _11504 = _11496;
    }
    if (_11504)
    {
        return 0.0f.xxx;
    }
    int orient = int(ambient_clouds.z + 0.5f);
    float2 _11517;
    if ((orient & 1) == 0)
    {
        _11517 = ambient_drift.zw;
    }
    else
    {
        _11517 = ambient_drift.wz;
    }
    float2 camLotSz = max(_11517, 1.0f.xx);
    bool2 _11534 = (length(horizN) > 0.1500000059604644775390625f).xx;
    float2 surfFwd = normalize(lerp(0.707106769084930419921875f.xx, float2(_11534.x ? horizN.x : 0.707106769084930419921875f.xx.x, _11534.y ? horizN.y : 0.707106769084930419921875f.xx.y), isVertical.xx));
    float frontPush = lerp(0.300000011920928955078125f, 0.0f, max(onFlatFloor, onDynamicSim));
    float2 probeXY = here.xy + (surfFwd * frontPush);
    float2 atHere = probeXY + ambient_frame.w.xx;
    int2 cellHere = int2(floor(atHere));
    int2 param = cellHere;
    float param_1 = here.z;
    float param_2 = here.z;
    float param_3 = 0.180000007152557373046875f;
    int levelRow = storyRowAt(param, param_1, param_2, param_3);
    int2 param_4 = cellHere;
    int param_5 = levelRow;
    float2 param_6 = atHere - float2(cellHere);
    int roomHere = effectiveRoomAt(param_4, param_5, param_6);
    float2 tang = float2(-surfFwd.y, surfFwd.x);
    float2 off0;
    float2 off1;
    float2 off2;
    float2 off3;
    float2 off4;
    float w0;
    float4 w14;
    if (((onFlatFloor < 0.5f) && (onDynamicSim < 0.5f)) && (isVertical > 0.3499999940395355224609375f))
    {
        off0 = surfFwd * 0.3499999940395355224609375f;
        off1 = (surfFwd * 0.920000016689300537109375f) + (tang * 0.519999980926513671875f);
        off2 = (surfFwd * 0.920000016689300537109375f) - (tang * 0.519999980926513671875f);
        off3 = (surfFwd * 1.62000000476837158203125f) + (tang * 0.819999992847442626953125f);
        off4 = (surfFwd * 1.62000000476837158203125f) - (tang * 0.819999992847442626953125f);
        w0 = 0.2800000011920928955078125f;
        w14 = float4(0.2199999988079071044921875f, 0.2199999988079071044921875f, 0.14000000059604644775390625f, 0.14000000059604644775390625f);
    }
    else
    {
        if (onFlatFloor > 0.5f)
        {
            off0 = 0.0f.xx;
            off1 = float2(0.85000002384185791015625f, 0.3499999940395355224609375f);
            off2 = float2(-0.85000002384185791015625f, -0.3499999940395355224609375f);
            off3 = float2(-0.3499999940395355224609375f, 0.85000002384185791015625f);
            off4 = float2(0.3499999940395355224609375f, -0.85000002384185791015625f);
            w0 = 0.23999999463558197021484375f;
            w14 = 0.189999997615814208984375f.xxxx;
        }
        else
        {
            off0 = surfFwd * 0.2800000011920928955078125f;
            off1 = (surfFwd * 0.87999999523162841796875f) + (tang * 0.4799999892711639404296875f);
            off2 = (surfFwd * 0.87999999523162841796875f) - (tang * 0.4799999892711639404296875f);
            off3 = ((-surfFwd) * 0.550000011920928955078125f) + (tang * 0.550000011920928955078125f);
            off4 = ((-surfFwd) * 0.550000011920928955078125f) - (tang * 0.550000011920928955078125f);
            w0 = 0.300000011920928955078125f;
            w14 = float4(0.2199999988079071044921875f, 0.2199999988079071044921875f, 0.12999999523162841796875f, 0.12999999523162841796875f);
        }
    }
    float3 acc = 0.0f.xxx;
    float wSum = 0.0f;
    float2 _11684;
    float2 _11691;
    float2 _11698;
    float _11715;
    float _11722;
    float _11730;
    float _11738;
    for (int k = 0; k < 5; k++)
    {
        if (k == 0)
        {
            _11684 = off0;
        }
        else
        {
            if (k == 1)
            {
                _11691 = off1;
            }
            else
            {
                if (k == 2)
                {
                    _11698 = off2;
                }
                else
                {
                    bool2 _11707 = (k == 3).xx;
                    _11698 = float2(_11707.x ? off3.x : off4.x, _11707.y ? off3.y : off4.y);
                }
                _11691 = _11698;
            }
            _11684 = _11691;
        }
        float2 offK = _11684;
        if (k == 0)
        {
            _11715 = w0;
        }
        else
        {
            if (k == 1)
            {
                _11722 = w14.x;
            }
            else
            {
                if (k == 2)
                {
                    _11730 = w14.y;
                }
                else
                {
                    if (k == 3)
                    {
                        _11738 = w14.z;
                    }
                    else
                    {
                        _11738 = w14.w;
                    }
                    _11730 = _11738;
                }
                _11722 = _11730;
            }
            _11715 = _11722;
        }
        float wK = _11715;
        float2 qXY = probeXY + offK;
        bool _11756 = any(bool2(qXY.x < 0.0f.xx.x, qXY.y < 0.0f.xx.y));
        bool _11764;
        if (!_11756)
        {
            _11764 = any(bool2(qXY.x >= camLotSz.x, qXY.y >= camLotSz.y));
        }
        else
        {
            _11764 = _11756;
        }
        if (_11764)
        {
            continue;
        }
        float2 qAt = qXY + ambient_frame.w.xx;
        int2 qCell = int2(floor(qAt));
        int2 param_7 = qCell;
        int param_8 = levelRow;
        float2 param_9 = qAt - float2(qCell);
        int qRoom = effectiveRoomAt(param_7, param_8, param_9);
        if (qRoom != roomHere)
        {
            continue;
        }
        float2 param_10 = qXY;
        int param_11 = levelRow;
        int param_12 = storiesCount;
        float2 param_13 = camLotSz;
        int2 param_14 = bSize;
        float3 b = sampleStoryBounce(param_10, param_11, param_12, param_13, param_14);
        acc += (b * wK);
        wSum += wK;
    }
    float3 _11819;
    if (wSum > 0.00999999977648258209228515625f)
    {
        _11819 = acc / wSum.xxx;
    }
    else
    {
        _11819 = 0.0f.xxx;
    }
    return _11819;
}

int maskAt(int2 at, int band)
{
    uint _720_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _720_dummy_parameter));
    int2 param = size;
    int bandH = indoorBandH(param);
    bool _727 = at.x < 0;
    bool _734;
    if (!_727)
    {
        _734 = at.y < 0;
    }
    else
    {
        _734 = _727;
    }
    bool _743;
    if (!_734)
    {
        _743 = at.x >= size.x;
    }
    else
    {
        _743 = _734;
    }
    bool _751;
    if (!_743)
    {
        _751 = at.y >= bandH;
    }
    else
    {
        _751 = _743;
    }
    bool _754 = _751 || (band < 0);
    bool _765;
    if (!_754)
    {
        _765 = ((band + 1) * bandH) > size.y;
    }
    else
    {
        _765 = _754;
    }
    if (_765)
    {
        return 0;
    }
    return int((indoorMap.Load(int3(int2(at.x, at.y + (band * bandH)), 0)).x * 255.0f) + 0.5f);
}

float2 lampNearInfo(float3 q)
{
    float3 param = q;
    float2 at = sceneOf(param);
    float best = 0.0f;
    float bestFire = 0.0f;
    int lampCount = int(ambient_lamp.x);
    for (int index = 0; index < 16; index++)
    {
        if (index >= lampCount)
        {
            break;
        }
        float4 lamp = ambient_lamps[index];
        bool isFire = lamp.w < 0.0f;
        float strength = abs(lamp.w);
        float hit = strength * clamp(1.0f - (length(lamp.xy - at) / ((0.800000011920928955078125f * ambient_lamp.y) * (isFire ? 1.14999997615814208984375f : 1.0f))), 0.0f, 1.0f);
        best = max(best, hit);
        if (isFire)
        {
            bestFire = max(bestFire, hit);
        }
    }
    float _2558;
    if (best > 9.9999997473787516355514526367188e-05f)
    {
        _2558 = clamp(bestFire / best, 0.0f, 1.0f);
    }
    else
    {
        _2558 = 0.0f;
    }
    return float2(clamp(best * 2.0f, 0.0f, 1.0f), _2558);
}

float2 windowSpillInfo(float3 here, float onGround)
{
    float2 at = here.xy + ambient_frame.w.xx;
    int2 cell = int2(floor(at));
    int2 param = cell;
    int param_1 = 0;
    float param_2 = here.z;
    float ground = floorAt(param, param_1, param_2);
    bool _2596 = onGround <= 0.5f;
    bool _2606;
    if (!_2596)
    {
        _2606 = here.z > ((ground + 2.9500000476837158203125f) - 0.100000001490116119384765625f);
    }
    else
    {
        _2606 = _2596;
    }
    bool _2615;
    if (!_2606)
    {
        int2 param_3 = cell;
        int param_4 = 0;
        _2615 = maskAt(param_3, param_4) >= 2;
    }
    else
    {
        _2615 = _2606;
    }
    if (_2615)
    {
        return 0.0f.xx;
    }
    float best = 0.0f;
    float3 source = 0.0f.xxx;
    float3 glass = 0.0f.xxx;
    int2 _2674;
    int2 _2681;
    for (int y = -3; y <= 3; y++)
    {
        for (int x = -3; x <= 3; x++)
        {
            int2 room = cell + int2(x, y);
            int2 param_5 = room;
            int param_6 = 0;
            int code = maskAt(param_5, param_6);
            bool _2652 = code < 2;
            bool _2659;
            if (!_2652)
            {
                _2659 = (code & 1) == 0;
            }
            else
            {
                _2659 = _2652;
            }
            if (_2659)
            {
                continue;
            }
            for (int d = 0; d < 4; d++)
            {
                if (d == 0)
                {
                    _2674 = int2(1, 0);
                }
                else
                {
                    if (d == 1)
                    {
                        _2681 = int2(-1, 0);
                    }
                    else
                    {
                        bool2 _2691 = (d == 2).xx;
                        _2681 = int2(_2691.x ? int2(0, 1).x : int2(0, -1).x, _2691.y ? int2(0, 1).y : int2(0, -1).y);
                    }
                    _2674 = _2681;
                }
                int2 _step = _2674;
                int2 param_7 = room + _step;
                int param_8 = 0;
                int outside = maskAt(param_7, param_8);
                bool _2703 = outside >= 2;
                bool _2710;
                if (!_2703)
                {
                    _2710 = (outside & 1) == 0;
                }
                else
                {
                    _2710 = _2703;
                }
                if (_2710)
                {
                    continue;
                }
                float2 offset = at - ((float2(room) + 0.5f.xx) + (float2(_step) * 0.5f));
                float out_ = dot(offset, float2(_step));
                if (out_ < 0.0f)
                {
                    continue;
                }
                float side = max(0.0f, abs(dot(offset, float2(float(_step.y), float(_step.x)))) - 0.300000011920928955078125f);
                float fall = max(0.0f, 1.0f - (length(float2(out_, side)) / 2.599999904632568359375f));
                float clear = smoothstep(0.64999997615814208984375f, 0.89999997615814208984375f, (1.5f * out_) / (out_ + 1.0f));
                if (((fall * fall) * clear) > best)
                {
                    best = (fall * fall) * clear;
                    source = float3((float2(room) + 0.5f.xx) - ambient_frame.w.xx, ground + 1.5f);
                    glass = float3(((float2(room) + 0.5f.xx) + (float2(_step) * 0.5f)) - ambient_frame.w.xx, ground + 1.39999997615814208984375f);
                }
            }
        }
    }
    if (best <= 0.0f)
    {
        return 0.0f.xx;
    }
    uint _2827_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _2827_dummy_parameter)));
    float2 toGlass = glass.xy - here.xy;
    float span = length(toGlass);
    if (span < 0.4000000059604644775390625f)
    {
        float3 param_9 = source;
        float2 info = lampNearInfo(param_9);
        return float2(best * info.x, info.y);
    }
    float3 end = float3(glass.xy - ((toGlass / span.xx) * 0.3499999940395355224609375f), glass.z);
    float open = 1.0f;
    for (int i = 1; i <= 6; i++)
    {
        float3 q = lerp(here, end, (float(i) / 6.0f).xxx);
        float top = (0.5f - heightMap.Sample(_heightMap_sampler, ((q.xy + ambient_frame.w.xx) * ambient_frame.z) / gridSize).x) * 128.0f;
        open = min(open, 1.0f - clamp(((top - q.z) - 0.100000001490116119384765625f) / 0.300000011920928955078125f, 0.0f, 1.0f));
    }
    float3 param_10 = source;
    float2 info_1 = lampNearInfo(param_10);
    return float2((best * open) * info_1.x, info_1.y);
}

float architecturalExposure(float3 _point)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1265;
    if (orientation == 1)
    {
        _1265 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1279;
        if (orientation == 2)
        {
            _1279 = size - _point.xy;
        }
        else
        {
            float2 _1289;
            if (orientation == 3)
            {
                _1289 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1289 = _point.xy;
            }
            _1279 = _1289;
        }
        _1265 = _1279;
    }
    float2 source = _1265;
    bool _1309 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _1317;
    if (!_1309)
    {
        _1317 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _1317 = _1309;
    }
    if (_1317)
    {
        return 1.0f;
    }
    uint _1325_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1325_dummy_parameter));
    bool _1332 = mapSize.y >= (mapSize.x * 2);
    bool _1338;
    if (_1332)
    {
        _1338 = mapSize.x > 1;
    }
    else
    {
        _1338 = _1332;
    }
    bool hasBand1 = _1338;
    int2 _1341;
    if (hasBand1)
    {
        _1341 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1341 = mapSize;
    }
    int2 baseSize = _1341;
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

bool isRainRoofPixel(float2 pixel, float3 p0, float3 here, float3 nSurf)
{
    float2 param = here.xy;
    float param_1 = here.z;
    float roofBase = terrainBaseAt(param, param_1);
    if ((here.z - roofBase) <= 3.0f)
    {
        return false;
    }
    float surfFacing = dot(nSurf, float3(0.0f, -0.866025388240814208984375f, 0.5f));
    if (surfFacing <= 0.23999999463558197021484375f)
    {
        return false;
    }
    float3 param_2 = here + float3(0.0f, 0.0f, 0.449999988079071044921875f);
    if (architecturalExposure(param_2) <= 0.5f)
    {
        return false;
    }
    float2 maxPx = ambient_extent.xy - 0.5f.xx;
    float rP = max(2.0f, 6.5f * ambient_view.z);
    float wP = max(0.800000011920928955078125f, 1.5f * ambient_view.z);
    float2 dir;
    for (int i = 0; i < 12; i++)
    {
        if (i < 8)
        {
            float a = float(i) * 0.785398185253143310546875f;
            dir = float2(cos(a), sin(a));
        }
        else
        {
            float sx = ((i == 8) || (i == 9)) ? 0.89442718029022216796875f : (-0.89442718029022216796875f);
            float sy = ((i == 8) || (i == 10)) ? 0.447213590145111083984375f : (-0.447213590145111083984375f);
            dir = float2(sx, sy);
        }
        float2 perp = float2(-dir.y, dir.x);
        float2 pML = clamp((pixel + (dir * (0.5f * rP))) + (perp * (0.5f * wP)), 0.5f.xx, maxPx);
        float2 pMR = clamp((pixel + (dir * (0.5f * rP))) - (perp * (0.5f * wP)), 0.5f.xx, maxPx);
        float2 pT = clamp(pixel + (dir * rP), 0.5f.xx, maxPx);
        float2 pL = clamp((pixel + (dir * rP)) + (perp * wP), 0.5f.xx, maxPx);
        float2 pR = clamp((pixel + (dir * rP)) - (perp * wP), 0.5f.xx, maxPx);
        bool _7383 = length(pT - pixel) < (0.699999988079071044921875f * rP);
        bool _7394;
        if (!_7383)
        {
            _7394 = length(pL - pR) < (0.75f * wP);
        }
        else
        {
            _7394 = _7383;
        }
        if (_7394)
        {
            continue;
        }
        float2 param_3 = pML;
        float4 qML = positionAt(param_3);
        float2 param_4 = pMR;
        float4 qMR = positionAt(param_4);
        float2 param_5 = pT;
        float4 qT = positionAt(param_5);
        float2 param_6 = pL;
        float4 qL = positionAt(param_6);
        float2 param_7 = pR;
        float4 qR = positionAt(param_7);
        bool _7420 = qML.w < 0.25f;
        bool _7431;
        if (_7420)
        {
            _7431 = abs(qML.z - p0.z) < 14.0f;
        }
        else
        {
            _7431 = _7420;
        }
        bool _7437;
        if (_7431)
        {
            _7437 = qMR.w < 0.25f;
        }
        else
        {
            _7437 = _7431;
        }
        bool _7447;
        if (_7437)
        {
            _7447 = abs(qMR.z - p0.z) < 14.0f;
        }
        else
        {
            _7447 = _7437;
        }
        bool _7453;
        if (_7447)
        {
            _7453 = qT.w < 0.25f;
        }
        else
        {
            _7453 = _7447;
        }
        bool _7464;
        if (_7453)
        {
            _7464 = abs(qT.z - p0.z) < 22.0f;
        }
        else
        {
            _7464 = _7453;
        }
        bool _7470;
        if (_7464)
        {
            _7470 = qL.w < 0.25f;
        }
        else
        {
            _7470 = _7464;
        }
        bool _7480;
        if (_7470)
        {
            _7480 = abs(qL.z - p0.z) < 22.0f;
        }
        else
        {
            _7480 = _7470;
        }
        bool _7486;
        if (_7480)
        {
            _7486 = qR.w < 0.25f;
        }
        else
        {
            _7486 = _7480;
        }
        bool _7496;
        if (_7486)
        {
            _7496 = abs(qR.z - p0.z) < 22.0f;
        }
        else
        {
            _7496 = _7486;
        }
        bool _7507;
        if (_7496)
        {
            _7507 = abs(qL.z - qR.z) < 7.5f;
        }
        else
        {
            _7507 = _7496;
        }
        if (_7507)
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
                bool _7546 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.89999997615814208984375f);
                bool _7552;
                if (_7546)
                {
                    _7552 = nW.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _7552 = _7546;
                }
                bool _7559;
                if (_7552)
                {
                    _7559 = abs(nW.x) > 0.1500000059604644775390625f;
                }
                else
                {
                    _7559 = _7552;
                }
                if (_7559)
                {
                    float errML = abs(dot(qML.xyz - p0, nW)) / nW.z;
                    float errMR = abs(dot(qMR.xyz - p0, nW)) / nW.z;
                    float errT = abs(dot(qT.xyz - p0, nW)) / nW.z;
                    if (((errML < 0.550000011920928955078125f) && (errMR < 0.550000011920928955078125f)) && (errT < 0.550000011920928955078125f))
                    {
                        return true;
                    }
                }
            }
        }
    }
    if (surfFacing >= 0.910000026226043701171875f)
    {
        float rF = max(6.0f, 22.0f * ambient_view.z);
        float wF = max(3.0f, 10.0f * ambient_view.z);
        for (int i_1 = 0; i_1 < 8; i_1++)
        {
            float a_1 = float(i_1) * 0.785398185253143310546875f;
            float2 dir_1 = float2(cos(a_1), sin(a_1));
            float2 perp_1 = float2(-dir_1.y, dir_1.x);
            float2 pML_1 = (pixel + (dir_1 * (0.5f * rF))) + (perp_1 * (0.5f * wF));
            float2 pMR_1 = (pixel + (dir_1 * (0.5f * rF))) - (perp_1 * (0.5f * wF));
            float2 pT_1 = pixel + (dir_1 * rF);
            float2 pL_1 = (pixel + (dir_1 * rF)) + (perp_1 * wF);
            float2 pR_1 = (pixel + (dir_1 * rF)) - (perp_1 * wF);
            bool _7700 = any(bool2(pML_1.x < 0.5f.xx.x, pML_1.y < 0.5f.xx.y));
            bool _7708;
            if (!_7700)
            {
                _7708 = any(bool2(pML_1.x > maxPx.x, pML_1.y > maxPx.y));
            }
            else
            {
                _7708 = _7700;
            }
            bool _7715;
            if (!_7708)
            {
                _7715 = any(bool2(pMR_1.x < 0.5f.xx.x, pMR_1.y < 0.5f.xx.y));
            }
            else
            {
                _7715 = _7708;
            }
            bool _7723;
            if (!_7715)
            {
                _7723 = any(bool2(pMR_1.x > maxPx.x, pMR_1.y > maxPx.y));
            }
            else
            {
                _7723 = _7715;
            }
            bool _7730;
            if (!_7723)
            {
                _7730 = any(bool2(pT_1.x < 0.5f.xx.x, pT_1.y < 0.5f.xx.y));
            }
            else
            {
                _7730 = _7723;
            }
            bool _7738;
            if (!_7730)
            {
                _7738 = any(bool2(pT_1.x > maxPx.x, pT_1.y > maxPx.y));
            }
            else
            {
                _7738 = _7730;
            }
            bool _7745;
            if (!_7738)
            {
                _7745 = any(bool2(pL_1.x < 0.5f.xx.x, pL_1.y < 0.5f.xx.y));
            }
            else
            {
                _7745 = _7738;
            }
            bool _7753;
            if (!_7745)
            {
                _7753 = any(bool2(pL_1.x > maxPx.x, pL_1.y > maxPx.y));
            }
            else
            {
                _7753 = _7745;
            }
            bool _7760;
            if (!_7753)
            {
                _7760 = any(bool2(pR_1.x < 0.5f.xx.x, pR_1.y < 0.5f.xx.y));
            }
            else
            {
                _7760 = _7753;
            }
            bool _7768;
            if (!_7760)
            {
                _7768 = any(bool2(pR_1.x > maxPx.x, pR_1.y > maxPx.y));
            }
            else
            {
                _7768 = _7760;
            }
            if (_7768)
            {
                continue;
            }
            float2 param_8 = pML_1;
            float4 qML_1 = positionAt(param_8);
            float2 param_9 = pMR_1;
            float4 qMR_1 = positionAt(param_9);
            float2 param_10 = pT_1;
            float4 qT_1 = positionAt(param_10);
            float2 param_11 = pL_1;
            float4 qL_1 = positionAt(param_11);
            float2 param_12 = pR_1;
            float4 qR_1 = positionAt(param_12);
            bool _7794 = qML_1.w < 0.25f;
            bool _7805;
            if (_7794)
            {
                _7805 = abs(qML_1.z - p0.z) < 28.0f;
            }
            else
            {
                _7805 = _7794;
            }
            bool _7811;
            if (_7805)
            {
                _7811 = qMR_1.w < 0.25f;
            }
            else
            {
                _7811 = _7805;
            }
            bool _7821;
            if (_7811)
            {
                _7821 = abs(qMR_1.z - p0.z) < 28.0f;
            }
            else
            {
                _7821 = _7811;
            }
            bool _7827;
            if (_7821)
            {
                _7827 = qT_1.w < 0.25f;
            }
            else
            {
                _7827 = _7821;
            }
            bool _7838;
            if (_7827)
            {
                _7838 = abs(qT_1.z - p0.z) < 48.0f;
            }
            else
            {
                _7838 = _7827;
            }
            bool _7844;
            if (_7838)
            {
                _7844 = qL_1.w < 0.25f;
            }
            else
            {
                _7844 = _7838;
            }
            bool _7854;
            if (_7844)
            {
                _7854 = abs(qL_1.z - p0.z) < 48.0f;
            }
            else
            {
                _7854 = _7844;
            }
            bool _7860;
            if (_7854)
            {
                _7860 = qR_1.w < 0.25f;
            }
            else
            {
                _7860 = _7854;
            }
            bool _7870;
            if (_7860)
            {
                _7870 = abs(qR_1.z - p0.z) < 48.0f;
            }
            else
            {
                _7870 = _7860;
            }
            bool _7880;
            if (_7870)
            {
                _7880 = abs(qL_1.z - qR_1.z) < 20.0f;
            }
            else
            {
                _7880 = _7870;
            }
            if (_7880)
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
                    bool _7916 = wFacing_1 >= 0.920000016689300537109375f;
                    bool _7922;
                    if (_7916)
                    {
                        _7922 = nW_1.z > 0.3499999940395355224609375f;
                    }
                    else
                    {
                        _7922 = _7916;
                    }
                    if (_7922)
                    {
                        float errML_1 = abs(dot(qML_1.xyz - p0, nW_1)) / nW_1.z;
                        float errMR_1 = abs(dot(qMR_1.xyz - p0, nW_1)) / nW_1.z;
                        float errT_1 = abs(dot(qT_1.xyz - p0, nW_1)) / nW_1.z;
                        if (((errML_1 < 0.800000011920928955078125f) && (errMR_1 < 0.800000011920928955078125f)) && (errT_1 < 0.800000011920928955078125f))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

float smoothNoise(float2 q)
{
    float2 i = floor(q);
    float2 f = frac(q);
    f = ((f * f) * f) * ((f * ((f * 6.0f) - 15.0f.xx)) + 10.0f.xx);
    float2 param = i;
    float2 param_1 = i + float2(1.0f, 0.0f);
    float2 param_2 = i + float2(0.0f, 1.0f);
    float2 param_3 = i + 1.0f.xx;
    return lerp(lerp(hash12(param), hash12(param_1), f.x), lerp(hash12(param_2), hash12(param_3), f.x), f.y);
}

float dualViewHullAt(float3 q, int2 oSize, float2 lotSz, float2 jitter, float spreadPx)
{
    int2 param = oSize;
    int aoRows = voxelAoRows(param);
    int halfH = ((oSize.x / 2) + 128) + (256 * aoRows);
    float topMarginHalf = float(64 + (256 * aoRows));
    int2 sliceMax = int2(oSize.x - 1, halfH - 1);
    float3 param_1 = q;
    int2 param_2 = oSize;
    int param_3 = halfH;
    float param_4 = topMarginHalf;
    int2 param_5 = sliceMax;
    float2 param_6 = lotSz;
    float param_7 = spreadPx;
    return dualViewHullAtPrecomp(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

float windowSpill(float3 here, float onGround)
{
    float3 param = here;
    float param_1 = onGround;
    return windowSpillInfo(param, param_1).x;
}

float lampNear(float3 q)
{
    float3 param = q;
    return lampNearInfo(param).x;
}

void frag_main()
{
    float _11834;
    if (ambient_extent.w > 0.5f)
    {
        _11834 = ambient_extent.w;
    }
    else
    {
        _11834 = 1.0f;
    }
    float ambScale = _11834;
    float2 rawPx = (floor(gl_FragCoord.xy) + 0.5f.xx) * ambScale;
    bool _11855 = rawPx.x >= ambient_extent.x;
    bool _11864;
    if (!_11855)
    {
        _11864 = rawPx.y >= ambient_extent.y;
    }
    else
    {
        _11864 = _11855;
    }
    if (_11864)
    {
        color = float4(0.5f, 0.5f, 0.5f, 1.0f);
        return;
    }
    int2 limitPx = max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0));
    int2 fullPx = clamp(int2(floor(rawPx)), int2(0, 0), limitPx);
    float2 pixel = float2(fullPx) + 0.5f.xx;
    float2 param = pixel;
    float4 centre = positionAt(param);
    if (centre.w > 0.75f)
    {
        color = float4(0.5f, 0.5f, 0.5f, 1.0f);
        return;
    }
    float3 p = centre.xyz;
    float scale = ambient_view.z;
    float3 pSmooth = p;
    bool hasVertGrad = true;
    bool isSprite = centre.w < 0.25f;
    float _11915;
    if (isSprite)
    {
        _11915 = clamp(2.599999904632568359375f * scale, max(2.599999904632568359375f, ambScale * 1.35000002384185791015625f), max(5.5f, 2.599999904632568359375f * scale));
    }
    else
    {
        _11915 = clamp(1.75f * scale, max(1.75f, ambScale), max(4.0f, 1.75f * scale));
    }
    float _step = _11915;
    float maxCont = max(3.5f, (1.35000002384185791015625f * _step) / max(scale, 0.25f));
    float2 param_1 = pixel - float2(_step, 0.0f);
    float4 leftP = positionAt(param_1);
    float2 param_2 = pixel + float2(_step, 0.0f);
    float4 rightP = positionAt(param_2);
    float2 param_3 = pixel - float2(0.0f, _step);
    float4 upP = positionAt(param_3);
    float2 param_4 = pixel + float2(0.0f, _step);
    float4 downP = positionAt(param_4);
    float3 left = leftP.xyz;
    float3 right = rightP.xyz;
    float3 up = upP.xyz;
    float3 down = downP.xyz;
    bool _11990 = leftP.w < 0.75f;
    bool _11998;
    if (_11990)
    {
        _11998 = (leftP.w < 0.25f) == isSprite;
    }
    else
    {
        _11998 = _11990;
    }
    bool _12009;
    if (_11998)
    {
        _12009 = abs(p.z - left.z) < maxCont;
    }
    else
    {
        _12009 = _11998;
    }
    bool lOk = _12009;
    bool _12013 = rightP.w < 0.75f;
    bool _12021;
    if (_12013)
    {
        _12021 = (rightP.w < 0.25f) == isSprite;
    }
    else
    {
        _12021 = _12013;
    }
    bool _12032;
    if (_12021)
    {
        _12032 = abs(right.z - p.z) < maxCont;
    }
    else
    {
        _12032 = _12021;
    }
    bool rOk = _12032;
    bool _12036 = upP.w < 0.75f;
    bool _12044;
    if (_12036)
    {
        _12044 = (upP.w < 0.25f) == isSprite;
    }
    else
    {
        _12044 = _12036;
    }
    bool _12055;
    if (_12044)
    {
        _12055 = abs(p.z - up.z) < maxCont;
    }
    else
    {
        _12055 = _12044;
    }
    bool uOk = _12055;
    bool _12059 = downP.w < 0.75f;
    bool _12067;
    if (_12059)
    {
        _12067 = (downP.w < 0.25f) == isSprite;
    }
    else
    {
        _12067 = _12059;
    }
    bool _12078;
    if (_12067)
    {
        _12078 = abs(down.z - p.z) < maxCont;
    }
    else
    {
        _12078 = _12067;
    }
    bool dOk = _12078;
    float creaseTol = max(2.2000000476837158203125f, (0.550000011920928955078125f * _step) / max(scale, 0.25f));
    float dLx = p.z - left.z;
    float dRx = right.z - p.z;
    float dUy = p.z - up.z;
    float dDy = down.z - p.z;
    bool _12114 = lOk && rOk;
    bool _12123;
    if (_12114)
    {
        _12123 = abs(dRx - dLx) < creaseTol;
    }
    else
    {
        _12123 = _12114;
    }
    bool _12131;
    if (_12123)
    {
        _12131 = (dRx * dLx) >= (-0.0500000007450580596923828125f);
    }
    else
    {
        _12131 = _12123;
    }
    bool xSmooth = _12131;
    bool _12135 = uOk && dOk;
    bool _12144;
    if (_12135)
    {
        _12144 = abs(dDy - dUy) < creaseTol;
    }
    else
    {
        _12144 = _12135;
    }
    bool _12151;
    if (_12144)
    {
        _12151 = (dDy * dUy) >= (-0.0500000007450580596923828125f);
    }
    else
    {
        _12151 = _12144;
    }
    bool ySmooth = _12151;
    float dxSpan = _step;
    float dySpan = _step;
    float3 _12158;
    if (xSmooth)
    {
        _12158 = (right - left) * 0.5f;
    }
    else
    {
        float3 _12167;
        if (lOk)
        {
            _12167 = p - left;
        }
        else
        {
            float3 _12175;
            if (rOk)
            {
                _12175 = right - p;
            }
            else
            {
                _12175 = float3(_step / max(scale, 0.25f), 0.0f, 0.0f);
            }
            _12167 = _12175;
        }
        _12158 = _12167;
    }
    float3 dx = _12158;
    float3 _12192;
    if (ySmooth)
    {
        _12192 = (down - up) * 0.5f;
    }
    else
    {
        float3 _12201;
        if (uOk)
        {
            _12201 = p - up;
        }
        else
        {
            float3 _12209;
            if (dOk)
            {
                _12209 = down - p;
            }
            else
            {
                _12209 = float3(0.0f, _step / max(scale, 0.25f), 0.0f);
            }
            _12201 = _12209;
        }
        _12192 = _12201;
    }
    float3 dy = _12192;
    float fineStep = max(1.0f, ambScale);
    bool _12231 = (!lOk) && (!rOk);
    bool _12238;
    if (_12231)
    {
        _12238 = _step > (fineStep + 0.5f);
    }
    else
    {
        _12238 = _12231;
    }
    if (_12238)
    {
        float fineMaxCont = max(1.7999999523162841796875f, (1.35000002384185791015625f * fineStep) / max(scale, 0.25f));
        float2 param_5 = pixel - float2(fineStep, 0.0f);
        float4 lfP = positionAt(param_5);
        float2 param_6 = pixel + float2(fineStep, 0.0f);
        float4 rfP = positionAt(param_6);
        bool _12266 = lfP.w < 0.75f;
        bool _12274;
        if (_12266)
        {
            _12274 = (lfP.w < 0.25f) == isSprite;
        }
        else
        {
            _12274 = _12266;
        }
        bool _12285;
        if (_12274)
        {
            _12285 = abs(p.z - lfP.z) < fineMaxCont;
        }
        else
        {
            _12285 = _12274;
        }
        bool lfOk = _12285;
        bool _12289 = rfP.w < 0.75f;
        bool _12297;
        if (_12289)
        {
            _12297 = (rfP.w < 0.25f) == isSprite;
        }
        else
        {
            _12297 = _12289;
        }
        bool _12308;
        if (_12297)
        {
            _12308 = abs(rfP.z - p.z) < fineMaxCont;
        }
        else
        {
            _12308 = _12297;
        }
        bool rfOk = _12308;
        if (lfOk || rfOk)
        {
            dxSpan = fineStep;
            float3 _12318;
            if (lfOk && rfOk)
            {
                _12318 = (rfP.xyz - lfP.xyz) * 0.5f;
            }
            else
            {
                float3 _12329;
                if (lfOk)
                {
                    _12329 = p - lfP.xyz;
                }
                else
                {
                    _12329 = rfP.xyz - p;
                }
                _12318 = _12329;
            }
            dx = _12318;
        }
    }
    hasVertGrad = uOk || dOk;
    bool _12350 = (!uOk) && (!dOk);
    bool _12357;
    if (_12350)
    {
        _12357 = _step > (fineStep + 0.5f);
    }
    else
    {
        _12357 = _12350;
    }
    if (_12357)
    {
        float fineMaxCont_1 = max(1.7999999523162841796875f, (1.35000002384185791015625f * fineStep) / max(scale, 0.25f));
        float2 param_7 = pixel - float2(0.0f, fineStep);
        float4 ufP = positionAt(param_7);
        float2 param_8 = pixel + float2(0.0f, fineStep);
        float4 dfP = positionAt(param_8);
        bool _12384 = ufP.w < 0.75f;
        bool _12392;
        if (_12384)
        {
            _12392 = (ufP.w < 0.25f) == isSprite;
        }
        else
        {
            _12392 = _12384;
        }
        bool _12403;
        if (_12392)
        {
            _12403 = abs(p.z - ufP.z) < fineMaxCont_1;
        }
        else
        {
            _12403 = _12392;
        }
        bool ufOk = _12403;
        bool _12407 = dfP.w < 0.75f;
        bool _12415;
        if (_12407)
        {
            _12415 = (dfP.w < 0.25f) == isSprite;
        }
        else
        {
            _12415 = _12407;
        }
        bool _12426;
        if (_12415)
        {
            _12426 = abs(dfP.z - p.z) < fineMaxCont_1;
        }
        else
        {
            _12426 = _12415;
        }
        bool dfOk = _12426;
        hasVertGrad = ufOk || dfOk;
        if (hasVertGrad)
        {
            dySpan = fineStep;
            float3 _12437;
            if (ufOk && dfOk)
            {
                _12437 = (dfP.xyz - ufP.xyz) * 0.5f;
            }
            else
            {
                float3 _12448;
                if (ufOk)
                {
                    _12448 = p - ufP.xyz;
                }
                else
                {
                    _12448 = dfP.xyz - p;
                }
                _12437 = _12448;
            }
            dy = _12437;
        }
    }
    if (isSprite)
    {
        float step2 = _step * 2.0f;
        float maxCont2 = max(6.0f, (1.5499999523162841796875f * step2) / max(scale, 0.25f));
        float2 param_9 = pixel - float2(step2, 0.0f);
        float4 l2P = positionAt(param_9);
        float2 param_10 = pixel + float2(step2, 0.0f);
        float4 r2P = positionAt(param_10);
        float2 param_11 = pixel - float2(0.0f, step2);
        float4 u2P = positionAt(param_11);
        float2 param_12 = pixel + float2(0.0f, step2);
        float4 d2P = positionAt(param_12);
        float3 l2 = l2P.xyz;
        float3 r2 = r2P.xyz;
        float3 u2 = u2P.xyz;
        float3 d2 = d2P.xyz;
        bool _12523;
        if (lOk)
        {
            _12523 = l2P.w < 0.25f;
        }
        else
        {
            _12523 = lOk;
        }
        bool _12534;
        if (_12523)
        {
            _12534 = abs(left.z - l2.z) < maxCont;
        }
        else
        {
            _12534 = _12523;
        }
        bool _12545;
        if (_12534)
        {
            _12545 = abs(p.z - l2.z) < maxCont2;
        }
        else
        {
            _12545 = _12534;
        }
        bool _12562;
        if (_12545)
        {
            _12562 = abs((p.z - left.z) - (left.z - l2.z)) < creaseTol;
        }
        else
        {
            _12562 = _12545;
        }
        bool l2Ok = _12562;
        bool _12570;
        if (rOk)
        {
            _12570 = r2P.w < 0.25f;
        }
        else
        {
            _12570 = rOk;
        }
        bool _12581;
        if (_12570)
        {
            _12581 = abs(r2.z - right.z) < maxCont;
        }
        else
        {
            _12581 = _12570;
        }
        bool _12592;
        if (_12581)
        {
            _12592 = abs(r2.z - p.z) < maxCont2;
        }
        else
        {
            _12592 = _12581;
        }
        bool _12609;
        if (_12592)
        {
            _12609 = abs((r2.z - right.z) - (right.z - p.z)) < creaseTol;
        }
        else
        {
            _12609 = _12592;
        }
        bool r2Ok = _12609;
        bool _12617;
        if (uOk)
        {
            _12617 = u2P.w < 0.25f;
        }
        else
        {
            _12617 = uOk;
        }
        bool _12628;
        if (_12617)
        {
            _12628 = abs(up.z - u2.z) < maxCont;
        }
        else
        {
            _12628 = _12617;
        }
        bool _12639;
        if (_12628)
        {
            _12639 = abs(p.z - u2.z) < maxCont2;
        }
        else
        {
            _12639 = _12628;
        }
        bool _12656;
        if (_12639)
        {
            _12656 = abs((p.z - up.z) - (up.z - u2.z)) < creaseTol;
        }
        else
        {
            _12656 = _12639;
        }
        bool u2Ok = _12656;
        bool _12664;
        if (dOk)
        {
            _12664 = d2P.w < 0.25f;
        }
        else
        {
            _12664 = dOk;
        }
        bool _12675;
        if (_12664)
        {
            _12675 = abs(d2.z - down.z) < maxCont;
        }
        else
        {
            _12675 = _12664;
        }
        bool _12686;
        if (_12675)
        {
            _12686 = abs(d2.z - p.z) < maxCont2;
        }
        else
        {
            _12686 = _12675;
        }
        bool _12703;
        if (_12686)
        {
            _12703 = abs((d2.z - down.z) - (down.z - p.z)) < creaseTol;
        }
        else
        {
            _12703 = _12686;
        }
        bool d2Ok = _12703;
        if ((xSmooth && l2Ok) && r2Ok)
        {
            dx = (r2 - l2) * 0.25f;
        }
        else
        {
            if (((!xSmooth) && lOk) && rOk)
            {
                float _12726;
                if (l2Ok)
                {
                    _12726 = abs((p.z - left.z) - (left.z - l2.z));
                }
                else
                {
                    _12726 = 10000.0f;
                }
                float errL = _12726;
                float _12746;
                if (r2Ok)
                {
                    _12746 = abs((r2.z - right.z) - (right.z - p.z));
                }
                else
                {
                    _12746 = 10000.0f;
                }
                float errR = _12746;
                float3 _12766;
                if (errR < errL)
                {
                    float3 _12770;
                    if (r2Ok)
                    {
                        _12770 = (r2 - p) * 0.5f;
                    }
                    else
                    {
                        _12770 = right - p;
                    }
                    _12766 = _12770;
                }
                else
                {
                    float3 _12784;
                    if (l2Ok)
                    {
                        _12784 = (p - l2) * 0.5f;
                    }
                    else
                    {
                        _12784 = p - left;
                    }
                    _12766 = _12784;
                }
                dx = _12766;
            }
        }
        if ((ySmooth && u2Ok) && d2Ok)
        {
            dy = (d2 - u2) * 0.25f;
        }
        else
        {
            if (((!ySmooth) && uOk) && dOk)
            {
                float _12819;
                if (u2Ok)
                {
                    _12819 = abs((p.z - up.z) - (up.z - u2.z));
                }
                else
                {
                    _12819 = 10000.0f;
                }
                float errU = _12819;
                float _12838;
                if (d2Ok)
                {
                    _12838 = abs((d2.z - down.z) - (down.z - p.z));
                }
                else
                {
                    _12838 = 10000.0f;
                }
                float errD = _12838;
                float3 _12858;
                if (errD < errU)
                {
                    float3 _12862;
                    if (d2Ok)
                    {
                        _12862 = (d2 - p) * 0.5f;
                    }
                    else
                    {
                        _12862 = down - p;
                    }
                    _12858 = _12862;
                }
                else
                {
                    float3 _12876;
                    if (u2Ok)
                    {
                        _12876 = (p - u2) * 0.5f;
                    }
                    else
                    {
                        _12876 = p - up;
                    }
                    _12858 = _12876;
                }
                dy = _12858;
            }
        }
        float zSum = p.z * 2.0f;
        float zW = 2.0f;
        bool _12901;
        if (lOk)
        {
            _12901 = xSmooth || (!rOk);
        }
        else
        {
            _12901 = lOk;
        }
        bool _12911;
        if (_12901)
        {
            _12911 = abs(left.z - p.z) < 2.2000000476837158203125f;
        }
        else
        {
            _12911 = _12901;
        }
        if (_12911)
        {
            zSum += left.z;
            zW += 1.0f;
        }
        bool _12927;
        if (rOk)
        {
            _12927 = xSmooth || (!lOk);
        }
        else
        {
            _12927 = rOk;
        }
        bool _12937;
        if (_12927)
        {
            _12937 = abs(right.z - p.z) < 2.2000000476837158203125f;
        }
        else
        {
            _12937 = _12927;
        }
        if (_12937)
        {
            zSum += right.z;
            zW += 1.0f;
        }
        bool _12953;
        if (uOk)
        {
            _12953 = ySmooth || (!dOk);
        }
        else
        {
            _12953 = uOk;
        }
        bool _12963;
        if (_12953)
        {
            _12963 = abs(up.z - p.z) < 2.2000000476837158203125f;
        }
        else
        {
            _12963 = _12953;
        }
        if (_12963)
        {
            zSum += up.z;
            zW += 1.0f;
        }
        bool _12979;
        if (dOk)
        {
            _12979 = ySmooth || (!uOk);
        }
        else
        {
            _12979 = dOk;
        }
        bool _12989;
        if (_12979)
        {
            _12989 = abs(down.z - p.z) < 2.2000000476837158203125f;
        }
        else
        {
            _12989 = _12979;
        }
        if (_12989)
        {
            zSum += down.z;
            zW += 1.0f;
        }
        bool _13000 = xSmooth && l2Ok;
        bool _13011;
        if (_13000)
        {
            _13011 = abs(l2.z - p.z) < 3.0799999237060546875f;
        }
        else
        {
            _13011 = _13000;
        }
        if (_13011)
        {
            zSum += (l2.z * 0.5f);
            zW += 0.5f;
        }
        bool _13023 = xSmooth && r2Ok;
        bool _13033;
        if (_13023)
        {
            _13033 = abs(r2.z - p.z) < 3.0799999237060546875f;
        }
        else
        {
            _13033 = _13023;
        }
        if (_13033)
        {
            zSum += (r2.z * 0.5f);
            zW += 0.5f;
        }
        bool _13045 = ySmooth && u2Ok;
        bool _13055;
        if (_13045)
        {
            _13055 = abs(u2.z - p.z) < 3.0799999237060546875f;
        }
        else
        {
            _13055 = _13045;
        }
        if (_13055)
        {
            zSum += (u2.z * 0.5f);
            zW += 0.5f;
        }
        bool _13067 = ySmooth && d2Ok;
        bool _13077;
        if (_13067)
        {
            _13077 = abs(d2.z - p.z) < 3.0799999237060546875f;
        }
        else
        {
            _13077 = _13067;
        }
        if (_13077)
        {
            zSum += (d2.z * 0.5f);
            zW += 0.5f;
        }
        pSmooth.z = zSum / zW;
    }
    float3 rawCross = cross(dy, dx);
    float rawLen = length(rawCross);
    float3 _13101;
    if (rawLen > 9.9999997473787516355514526367188e-06f)
    {
        _13101 = rawCross / rawLen.xxx;
    }
    else
    {
        _13101 = float3(0.0f, 0.0f, 1.0f);
    }
    float3 n = _13101;
    if (n.z < 0.0f)
    {
        n = -n;
    }
    float3 nSurf = n;
    float gradJump = max(abs(dx.z) / max(dxSpan / scale, 0.5f), abs(dy.z) / max(dySpan / scale, 0.5f));
    float3 _13141;
    if (centre.w > 0.25f)
    {
        _13141 = n;
    }
    else
    {
        _13141 = normalize(lerp(n, float3(0.0f, 0.0f, 1.0f), 0.25f.xxx));
    }
    float3 normal = _13141;
    uint _13154_dummy_parameter;
    int2 vSize = int2(spvTextureSize(voxelMap, uint(0), _13154_dummy_parameter));
    bool hasVoxels = vSize.x > 1;
    int _13161;
    if (hasVoxels)
    {
        int2 param_13 = vSize;
        _13161 = voxelAoRows(param_13);
    }
    else
    {
        _13161 = 1;
    }
    int vAoRows = _13161;
    int vHalfH = ((vSize.x / 2) + 128) + (256 * vAoRows);
    int vAoSize = vSize.x / 4;
    int vAoYBase = vHalfH * 2;
    bool _13188 = hasVoxels && (vAoSize > 0);
    bool _13197;
    if (_13188)
    {
        _13197 = vSize.y >= (vAoYBase + vAoSize);
    }
    else
    {
        _13197 = _13188;
    }
    bool hasColBounds = _13197;
    float vTopMarginHalf = float(64 + (256 * vAoRows));
    int2 vSliceMax = int2(vSize.x - 1, vHalfH - 1);
    float2 lotSz = max(ambient_drift.zw, 1.0f.xx);
    bool _13218 = centre.w < 0.25f;
    bool _13227;
    if (_13218)
    {
        uint _13224_dummy_parameter;
        _13227 = int2(spvTextureSize(simMaskMap, uint(0), _13224_dummy_parameter)).x > 1;
    }
    else
    {
        _13227 = _13218;
    }
    float _13228;
    if (_13227)
    {
        _13228 = simMaskMap.Sample(_simMaskMap_sampler, pixel / ambient_extent.xy).x;
    }
    else
    {
        _13228 = 0.0f;
    }
    float simMaskVal = _13228;
    float onAvatarMask = smoothstep(0.100000001490116119384765625f, 0.449999988079071044921875f, simMaskVal);
    float radius = ambient_params.x;
    float thickness = ambient_params.w;
    float visibility = 1.0f;
    float3 bentNormal = normal;
    bool worldSpaceAO = ambient_sunLot.w > 0.0f;
    bool _13259 = !worldSpaceAO;
    bool _13265;
    if (_13259)
    {
        _13265 = ambient_params.y > 0.001000000047497451305389404296875f;
    }
    else
    {
        _13265 = _13259;
    }
    bool runScreenGTAO = _13265 && (onAvatarMask < 0.5f);
    if (runScreenGTAO)
    {
        visibility = 0.0f;
        float3 bentAccum = 0.0f.xxx;
        float3 _13277;
        if (centre.w < 0.25f)
        {
            _13277 = pSmooth + (normal * 0.949999988079071044921875f);
        }
        else
        {
            _13277 = p;
        }
        float3 pAO = _13277;
        float _13291;
        if (centre.w > 0.25f)
        {
            _13291 = radius * 1.85000002384185791015625f;
        }
        else
        {
            _13291 = radius;
        }
        float aoDistLimit = _13291;
        float2 _13371;
        for (int slice = 0; slice < 4; slice++)
        {
            float phi = ((float(slice) + 0.5f) * 3.1415927410125732421875f) / 4.0f;
            float2 direction = float2(cos(phi), sin(phi));
            float3 axis = float3(direction.y, -direction.x, 0.0f);
            float3 projected = normal - (axis * dot(normal, axis));
            float projectedLength = max(length(projected), 9.9999997473787516355514526367188e-05f);
            float cosN = clamp(projected.z / projectedLength, -1.0f, 1.0f);
            float n_1 = sign(dot(projected.xy, direction)) * acos(cosN);
            float sliceRadialShift = (float(slice) + 0.5f) / 4.0f;
            float2 horizons = 0.0f.xx;
            for (int side = 0; side < 2; side++)
            {
                if (side == 0)
                {
                    _13371 = direction;
                }
                else
                {
                    _13371 = -direction;
                }
                float2 sideDirection = _13371;
                float best = -1.0f;
                for (int i = 0; i < 4; i++)
                {
                    float t = (float(i) + sliceRadialShift) / 4.0f;
                    float2 offset = (sideDirection * (((radius * t) * t) + 1.5f)) * scale;
                    float2 samplePixel = pixel + offset;
                    bool _13411 = any(bool2(samplePixel.x < 0.0f.xx.x, samplePixel.y < 0.0f.xx.y));
                    bool _13420;
                    if (!_13411)
                    {
                        _13420 = samplePixel.x >= ambient_extent.x;
                    }
                    else
                    {
                        _13420 = _13411;
                    }
                    bool _13429;
                    if (!_13420)
                    {
                        _13429 = samplePixel.y >= ambient_extent.y;
                    }
                    else
                    {
                        _13429 = _13420;
                    }
                    if (_13429)
                    {
                        break;
                    }
                    float2 param_14 = samplePixel;
                    float4 samplePos = positionAt(param_14);
                    bool _13439 = samplePos.w > 0.75f;
                    bool _13452;
                    if (!_13439)
                    {
                        bool _13445 = centre.w < 0.25f;
                        bool _13451;
                        if (_13445)
                        {
                            _13451 = samplePos.w > 0.25f;
                        }
                        else
                        {
                            _13451 = _13445;
                        }
                        _13452 = _13451;
                    }
                    else
                    {
                        _13452 = _13439;
                    }
                    if (_13452)
                    {
                        continue;
                    }
                    float3 delta = samplePos.xyz - pAO;
                    float _distance = length(delta);
                    float distW = smoothstep(1.0f, 0.0f, _distance / max(aoDistLimit, 1.0f));
                    float falloff = (distW * distW) * clamp((thickness - delta.z) / (0.5f * thickness), 0.0f, 1.0f);
                    float cosine = lerp(-1.0f, delta.z / max(_distance, 9.9999997473787516355514526367188e-05f), falloff);
                    best = max(best, cosine);
                }
                if (side == 0)
                {
                    horizons.x = acos(clamp(best, -1.0f, 1.0f));
                }
                else
                {
                    horizons.y = -acos(clamp(best, -1.0f, 1.0f));
                }
            }
            float h1 = n_1 + min(horizons.x - n_1, 1.57079637050628662109375f);
            float h0 = n_1 + max(horizons.y - n_1, -1.57079637050628662109375f);
            float sinN = sin(n_1);
            float sliceVis = (projectedLength * 0.25f) * ((((-cos((2.0f * h0) - n_1)) + cosN) + ((2.0f * h0) * sinN)) + (((-cos((2.0f * h1) - n_1)) + cosN) + ((2.0f * h1) * sinN)));
            visibility += sliceVis;
            float bentAng = 0.5f * (h0 + h1);
            float3 sliceBent = float3(direction * sin(bentAng), cos(bentAng));
            bentAccum += (sliceBent * max(sliceVis, 0.0199999995529651641845703125f));
        }
        visibility = clamp(visibility / 4.0f, 0.0f, 1.0f);
        float bentLen = length(bentAccum);
        if (bentLen > 9.9999997473787516355514526367188e-05f)
        {
            bentNormal = normalize(lerp(normal, bentAccum / bentLen.xxx, clamp(ambient_params.y, 0.0f, 1.0f).xxx));
        }
    }
    float mbA = 0.116488002240657806396484375f;
    float mbB = -0.4132219851016998291015625f;
    float mbC = 1.29644405841827392578125f;
    float multiBounceVis = pow(clamp(visibility * ((visibility * ((mbA * visibility) + mbB)) + mbC), 0.0f, 1.0f), 1.2999999523162841796875f);
    float occlusion = clamp(lerp(1.0f, multiBounceVis, ambient_params.y), 0.20000000298023223876953125f, 1.0f);
    float _13641;
    if (centre.w < 0.25f)
    {
        _13641 = (0.62000000476837158203125f - depthMap.Load(int3(fullPx, 0)).x) / 0.0030000000260770320892333984375f;
    }
    else
    {
        _13641 = ((0.62000000476837158203125f - groundMap.Load(int3(fullPx, 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
    }
    float key = _13641;
    float2 param_15 = p.xy;
    float param_16 = key;
    bool param_17 = centre.w > 0.25f;
    float2 param_18 = ambient_frame.xy;
    float3 here = lotPoint(param_15, param_16, param_17, param_18);
    float riseHere;
    if (centre.w > 0.25f)
    {
        riseHere = 0.0f;
    }
    else
    {
        bool _13687 = ambient_sunLot.w > 0.0f;
        bool _13695;
        if (_13687)
        {
            uint _13692_dummy_parameter;
            _13695 = int2(spvTextureSize(overheadMap, uint(0), _13692_dummy_parameter)).x > 1;
        }
        else
        {
            _13695 = _13687;
        }
        if (_13695)
        {
            float2 param_19 = pixel;
            float gAtHere = groundAt(param_19);
            float _13705;
            if (gAtHere > (-10000.0f))
            {
                float2 param_20 = p.xy;
                float param_21 = gAtHere / 27.7128124237060546875f;
                bool param_22 = true;
                float2 param_23 = ambient_frame.xy;
                _13705 = lotPoint(param_20, param_21, param_22, param_23).z;
            }
            else
            {
                float2 param_24 = here.xy;
                float param_25 = ambient_contact.w;
                _13705 = terrainBaseClamped(param_24, param_25);
            }
            float fallbackBaseZ = _13705;
            float2 param_26 = here.xy;
            float param_27 = fallbackBaseZ;
            float groundBaseZ = terrainBaseAt(param_26, param_27);
            riseHere = max(0.0f, here.z - groundBaseZ) * 40.0f;
        }
        else
        {
            float2 param_28 = pixel;
            bool _13747 = groundAt(param_28) < (-10000.0f);
            bool _13756;
            if (!_13747)
            {
                float2 param_29 = pixel + float2(0.0f, 4.0f);
                _13756 = groundAt(param_29) < (-10000.0f);
            }
            else
            {
                _13756 = _13747;
            }
            float _13757;
            if (_13756)
            {
                _13757 = max(20.0f, (here.z - ambient_contact.w) * 40.0f);
            }
            else
            {
                float2 param_30 = pixel;
                float param_31 = p.z;
                _13757 = riseAt(param_30, param_31);
            }
            riseHere = _13757;
        }
    }
    float onGround = 1.0f - smoothstep(2.0f, 6.0f, riseHere);
    uint _13783_dummy_parameter;
    float4 _13786;
    if (int2(spvTextureSize(liftMap, uint(0), _13783_dummy_parameter)).x > 1)
    {
        _13786 = liftMap.Load(int3(fullPx, 0));
    }
    else
    {
        _13786 = 0.0f.xxxx;
    }
    float4 lift = _13786;
    bool onSnow = lift.z > 0.5f;
    if (onSnow)
    {
        here += float3(0.5f * lift.x, 0.5f * lift.x, lift.y);
        onGround = 1.0f;
        occlusion = 1.0f;
    }
    int2 hereCell = int2(floor(here.xy + ambient_frame.w.xx));
    int storiesCount = indoorStories();
    int2 param_32 = hereCell;
    int param_33 = 0;
    float param_34 = here.z;
    float hereBase0 = floorAt(param_32, param_33, param_34);
    int candUpperRow = clamp(int(floor(((here.z - hereBase0) / 2.9500000476837158203125f) + 0.5f)), 1, max(1, (storiesCount - 1)));
    float _13850;
    if (candUpperRow < storiesCount)
    {
        int2 param_35 = hereCell;
        int param_36 = candUpperRow;
        float param_37 = -100.0f;
        _13850 = floorAt(param_35, param_36, param_37);
    }
    else
    {
        _13850 = -100.0f;
    }
    float floor2Z = _13850;
    float _13866;
    if (floor2Z > (-50.0f))
    {
        _13866 = (1.0f - smoothstep(0.07999999821186065673828125f, 0.2199999988079071044921875f, abs(here.z - floor2Z))) * smoothstep(0.550000011920928955078125f, 0.819999992847442626953125f, dot(nSurf, float3(0.0f, -0.866025388240814208984375f, 0.5f)));
    }
    else
    {
        _13866 = 0.0f;
    }
    float onLevel2Floor = _13866;
    float onFlatFloor = max(onGround, onLevel2Floor);
    float onDynamicSim = onAvatarMask;
    bool _13891 = (onDynamicSim < 0.9900000095367431640625f) && hasVoxels;
    bool _13897;
    if (_13891)
    {
        _13897 = ambient_shadowView.w > 0.5f;
    }
    else
    {
        _13897 = _13891;
    }
    bool _13903;
    if (_13897)
    {
        _13903 = centre.w < 0.25f;
    }
    else
    {
        _13903 = _13897;
    }
    if (_13903)
    {
        float2 wpSelf = ambient_shadowView.xy + (p.xy * ambient_shadowView.z);
        bool _13920 = wpSelf.x >= ambient_dynShadowBounds.x;
        bool _13928;
        if (_13920)
        {
            _13928 = wpSelf.y >= ambient_dynShadowBounds.y;
        }
        else
        {
            _13928 = _13920;
        }
        bool _13936;
        if (_13928)
        {
            _13936 = wpSelf.x <= ambient_dynShadowBounds.z;
        }
        else
        {
            _13936 = _13928;
        }
        bool _13944;
        if (_13936)
        {
            _13944 = wpSelf.y <= ambient_dynShadowBounds.w;
        }
        else
        {
            _13944 = _13936;
        }
        if (_13944)
        {
            uint _13950_dummy_parameter;
            float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _13950_dummy_parameter)));
            bool _13954 = all(bool2(wpSelf.x >= 0.0f.xx.x, wpSelf.y >= 0.0f.xx.y));
            bool _13961;
            if (_13954)
            {
                _13961 = all(bool2(wpSelf.x < wSize.x, wpSelf.y < wSize.y));
            }
            else
            {
                _13961 = _13954;
            }
            if (_13961)
            {
                float wSelf = worldDepthMap.Load(int3(clamp(int2(floor(wpSelf)), int2(0, 0), int2(wSize) - int2(1, 1)), 0)).x;
                bool _13978 = wSelf < 0.99989998340606689453125f;
                bool _13988;
                if (_13978)
                {
                    _13988 = abs(((0.62000000476837158203125f - wSelf) / 0.0030000000260770320892333984375f) - key) < 0.550000011920928955078125f;
                }
                else
                {
                    _13988 = _13978;
                }
                if (_13988)
                {
                    onDynamicSim = 1.0f;
                }
            }
        }
    }
    float roofSnow = lift.w;
    float3 matchedWallPos = here;
    float2 matchedWallN = 0.0f.xx;
    float archWallMatch = 0.0f;
    bool _14001 = worldSpaceAO && (!onSnow);
    bool _14007;
    if (_14001)
    {
        _14007 = centre.w < 0.25f;
    }
    else
    {
        _14007 = _14001;
    }
    if (((_14007 && (onFlatFloor < 0.5f)) && (onDynamicSim < 0.5f)) && (roofSnow < 0.5f))
    {
        float _14021;
        if (hasVertGrad)
        {
            _14021 = dot(nSurf, float3(0.0f, -0.866025388240814208984375f, 0.5f));
        }
        else
        {
            _14021 = 0.0f;
        }
        float upCheck = _14021;
        float wallStoryRel = max(0.0f, (here.z - hereBase0) - (floor(max(0.0f, (here.z - hereBase0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f) * 2.9500000476837158203125f));
        float midWallBand = smoothstep(0.4600000083446502685546875f, 0.60000002384185791015625f, wallStoryRel) * (1.0f - smoothstep(2.6700000762939453125f, 2.809999942779541015625f, wallStoryRel));
        float upLo = lerp(0.2800000011920928955078125f, 0.560000002384185791015625f, midWallBand);
        float upHi = lerp(0.439999997615814208984375f, 0.7200000286102294921875f, midWallBand);
        if (upCheck < upHi)
        {
            float3 param_38 = here;
            float2 param_39 = p.xy;
            float param_40 = key;
            float param_41 = nSurf.x;
            float3 param_42;
            float2 param_43;
            float _14076 = matchArchWall(param_38, param_39, param_40, param_41, param_42, param_43);
            matchedWallPos = param_42;
            matchedWallN = param_43;
            archWallMatch = _14076;
            if (archWallMatch > 0.001000000047497451305389404296875f)
            {
                archWallMatch *= (1.0f - smoothstep(upLo, upHi, upCheck));
                float2 wallPlaneXY = matchedWallPos.xy - (matchedWallN * 0.0350000001490116119384765625f);
                float frontOfWall = smoothstep(-0.02500000037252902984619140625f, 0.0199999995529651641845703125f, dot(here.xy - wallPlaneXY, matchedWallN));
                if (hasVoxels && (frontOfWall > 0.001000000047497451305389404296875f))
                {
                    float3 hullProbe = float3(wallPlaneXY + (matchedWallN * 0.14000000059604644775390625f), here.z);
                    float3 param_44 = hullProbe;
                    int2 param_45 = vSize;
                    int param_46 = vHalfH;
                    float param_47 = vTopMarginHalf;
                    int2 param_48 = vSliceMax;
                    float2 param_49 = lotSz;
                    float param_50 = 0.0900000035762786865234375f;
                    float selfHull = frontOfWall * dualViewHullSolid(param_44, param_45, param_46, param_47, param_48, param_49, param_50);
                    archWallMatch *= (1.0f - smoothstep(0.20000000298023223876953125f, 0.680000007152557373046875f, selfHull));
                }
            }
        }
    }
    bool _14150 = ((!onSnow) && hasVertGrad) && (archWallMatch < 0.5f);
    bool _14156;
    if (_14150)
    {
        _14156 = centre.w < 0.25f;
    }
    else
    {
        _14156 = _14150;
    }
    bool _14159 = _14156 && (onLevel2Floor < 0.25f);
    bool _14165;
    if (_14159)
    {
        _14165 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _14165 = _14159;
    }
    bool _14169 = _14165 && (riseHere > 115.0f);
    bool _14176;
    if (_14169)
    {
        float3 param_51 = here;
        _14176 = indoors(param_51) < 0.20000000298023223876953125f;
    }
    else
    {
        _14176 = _14169;
    }
    float _14177;
    if (_14176)
    {
        _14177 = (smoothstep(115.0f, 124.0f, riseHere) * smoothstep(0.319999992847442626953125f, 0.60000002384185791015625f, dot(normal, float3(0.0f, -0.866025388240814208984375f, 0.5f)))) * (1.0f - archWallMatch);
    }
    else
    {
        _14177 = 0.0f;
    }
    float highRoof = _14177;
    float roofCalm = clamp(max(roofSnow, highRoof), 0.0f, 1.0f);
    if (roofCalm > 0.00999999977648258209228515625f)
    {
        occlusion = lerp(occlusion, 1.0f - ((1.0f - occlusion) * 0.14000000059604644775390625f), roofCalm);
    }
    if (worldSpaceAO && (onLevel2Floor > 0.00999999977648258209228515625f))
    {
        occlusion = lerp(occlusion, 1.0f, onLevel2Floor);
    }
    float wallFloor = 0.0f;
    bool _14221 = (onFlatFloor > 0.5f) && worldSpaceAO;
    bool _14238;
    if (_14221)
    {
        bool _14226 = ambient_params.y > 0.001000000047497451305389404296875f;
        bool _14237;
        if (!_14226)
        {
            bool _14236;
            if (onSnow)
            {
                _14236 = ambient_contact.y > 0.0f;
            }
            else
            {
                _14236 = onSnow;
            }
            _14237 = _14236;
        }
        else
        {
            _14237 = _14226;
        }
        _14238 = _14237;
    }
    else
    {
        _14238 = _14221;
    }
    if (_14238)
    {
        float3 param_52 = here;
        wallFloor = floorWallAO(param_52);
        bool _14245 = !onSnow;
        bool _14251;
        if (_14245)
        {
            _14251 = ambient_params.y > 0.001000000047497451305389404296875f;
        }
        else
        {
            _14251 = _14245;
        }
        if (_14251)
        {
            occlusion *= (1.0f - ((0.4199999868869781494140625f * clamp(ambient_params.y, 0.0f, 1.0f)) * clamp(wallFloor, 0.0f, 1.35000002384185791015625f)));
        }
    }
    float contact = 1.0f;
    if (worldSpaceAO)
    {
        bool _14275 = ((centre.w > 0.25f) || onSnow) || (onLevel2Floor > 0.5f);
        bool _14295;
        if (_14275)
        {
            bool _14280 = ambient_contact.y > 0.0f;
            bool _14294;
            if (!_14280)
            {
                bool _14287 = (!onSnow) && hasVoxels;
                bool _14293;
                if (_14287)
                {
                    _14293 = ambient_params.y > 0.001000000047497451305389404296875f;
                }
                else
                {
                    _14293 = _14287;
                }
                _14294 = _14293;
            }
            else
            {
                _14294 = _14280;
            }
            _14295 = _14294;
        }
        else
        {
            _14295 = _14275;
        }
        if (_14295)
        {
            if (hasVoxels)
            {
                int levelRow = (onLevel2Floor > 0.5f) ? candUpperRow : 0;
                float voxelContact = 0.0f;
                float3 param_53 = here;
                int param_54 = levelRow;
                int2 param_55 = vSize;
                float param_56;
                float _14315 = voxelGroundAO(param_53, param_54, param_55, param_56);
                voxelContact = param_56;
                float voxelHemi = _14315;
                float borderDist = min(min(here.x, lotSz.x - here.x), min(here.y, lotSz.y - here.y));
                if ((onLevel2Floor <= 0.5f) && (borderDist < 0.3499999940395355224609375f))
                {
                    float wOff = 1.0f - smoothstep(-0.0500000007450580596923828125f, 0.3499999940395355224609375f, borderDist);
                    float offContact = 0.0f;
                    float3 param_57 = here;
                    float param_58 = scale;
                    float param_59;
                    float _14353 = offLotGroundAO(param_57, param_58, param_59);
                    offContact = param_59;
                    float offHemi = _14353;
                    voxelContact = max(voxelContact, offContact * wOff);
                    voxelHemi = max(voxelHemi, offHemi * wOff);
                }
                bool _14366 = !onSnow;
                bool _14372;
                if (_14366)
                {
                    _14372 = ambient_params.y > 0.001000000047497451305389404296875f;
                }
                else
                {
                    _14372 = _14366;
                }
                if (_14372)
                {
                    float voxelVis = 1.0f - ((0.36000001430511474609375f * clamp(ambient_params.y, 0.0f, 1.0f)) * voxelHemi);
                    occlusion = max(occlusion * voxelVis, 0.300000011920928955078125f);
                }
                if (ambient_contact.y > 0.0f)
                {
                    float combinedContact = voxelContact;
                    if (onSnow)
                    {
                        combinedContact = max(combinedContact, 0.550000011920928955078125f * clamp(wallFloor, 0.0f, 1.0f));
                    }
                    contact = 1.0f - (ambient_contact.y * clamp(combinedContact, 0.0f, 1.0f));
                }
            }
            else
            {
                if (ambient_contact.y > 0.0f)
                {
                    float detail = ambient_frame.z;
                    uint _14421_dummy_parameter;
                    int2 footSize = int2(spvTextureSize(footMap, uint(0), _14421_dummy_parameter));
                    float2 invFootSize = 1.0f.xx / float2(footSize);
                    float2 at = (here.xy + ambient_frame.w.xx) * detail;
                    float best_1 = 0.0f;
                    float sum = 0.0f;
                    int2 base = int2(floor(at - 1.5f.xx));
                    float _14534;
                    float _14542;
                    float _14550;
                    int2 _14569;
                    int2 _14575;
                    for (int qy = 0; qy < 4; qy += 2)
                    {
                        for (int qx = 0; qx < 4; qx += 2)
                        {
                            int2 qb = base + int2(qx, qy);
                            bool _14469 = (qb.x + 1) < 0;
                            bool _14477;
                            if (!_14469)
                            {
                                _14477 = (qb.y + 1) < 0;
                            }
                            else
                            {
                                _14477 = _14469;
                            }
                            bool _14486;
                            if (!_14477)
                            {
                                _14486 = qb.x >= footSize.x;
                            }
                            else
                            {
                                _14486 = _14477;
                            }
                            bool _14495;
                            if (!_14486)
                            {
                                _14495 = qb.y >= footSize.y;
                            }
                            else
                            {
                                _14495 = _14486;
                            }
                            if (_14495)
                            {
                                continue;
                            }
                            float4 g = footMap.GatherRed(_footMap_sampler, (float2(qb) + 1.0f.xx) * invFootSize);
                            if (min(min(g.x, g.y), min(g.z, g.w)) >= 1.0f)
                            {
                                continue;
                            }
                            for (int k = 0; k < 4; k++)
                            {
                                if (k == 0)
                                {
                                    _14534 = g.x;
                                }
                                else
                                {
                                    if (k == 1)
                                    {
                                        _14542 = g.y;
                                    }
                                    else
                                    {
                                        if (k == 2)
                                        {
                                            _14550 = g.z;
                                        }
                                        else
                                        {
                                            _14550 = g.w;
                                        }
                                        _14542 = _14550;
                                    }
                                    _14534 = _14542;
                                }
                                float stored = _14534;
                                if (stored >= 1.0f)
                                {
                                    continue;
                                }
                                if (k == 0)
                                {
                                    _14569 = int2(0, 1);
                                }
                                else
                                {
                                    if (k == 1)
                                    {
                                        _14575 = int2(1, 1);
                                    }
                                    else
                                    {
                                        bool2 _14581 = (k == 2).xx;
                                        _14575 = int2(_14581.x ? int2(1, 0).x : int2(0, 0).x, _14581.y ? int2(1, 0).y : int2(0, 0).y);
                                    }
                                    _14569 = _14575;
                                }
                                int2 qo = _14569;
                                int2 texel = qb + qo;
                                bool _14591 = any(bool2(texel.x < int2(0, 0).x, texel.y < int2(0, 0).y));
                                bool _14599;
                                if (!_14591)
                                {
                                    _14599 = any(bool2(texel.x >= footSize.x, texel.y >= footSize.y));
                                }
                                else
                                {
                                    _14599 = _14591;
                                }
                                if (_14599)
                                {
                                    continue;
                                }
                                float footZ = (0.5f - stored) * 128.0f;
                                if (abs(footZ - here.z) > 0.25f)
                                {
                                    continue;
                                }
                                float near = max(0.0f, 1.0f - (length(((float2(texel) + 0.5f.xx) - at) / detail.xx) / 0.2199999988079071044921875f));
                                float w = pow(near, 1.35000002384185791015625f);
                                best_1 = max(best_1, w);
                                sum += w;
                            }
                        }
                    }
                    float3 param_60 = here;
                    float feet = max(clamp((0.819999992847442626953125f * best_1) + (0.0350000001490116119384765625f * sum), 0.0f, 1.0f), simFootAO(param_60));
                    uint _14659_dummy_parameter;
                    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _14659_dummy_parameter)));
                    float2 hCenter = (here.xy + ambient_frame.w.xx) * ambient_frame.z;
                    float over = ((0.5f - heightMap.Sample(_heightMap_sampler, hCenter / gridSize).x) * 128.0f) - here.z;
                    float under = smoothstep(0.20000000298023223876953125f, 0.4000000059604644775390625f, over) * (1.0f - smoothstep(2.0f, 2.599999904632568359375f, over));
                    contact = 1.0f - (ambient_contact.y * clamp(feet + (0.3499999940395355224609375f * under), 0.0f, 1.0f));
                }
            }
        }
    }
    else
    {
        bool _14701 = onGround > 0.0f;
        bool _14707;
        if (_14701)
        {
            _14707 = ambient_contact.y > 0.0f;
        }
        else
        {
            _14707 = _14701;
        }
        if (_14707)
        {
            float contactRadius = ambient_contact.x;
            float2 footHere = p.xy + float2(0.0f, riseHere);
            float covered = 0.0f;
            for (int d = 0; d < 8; d++)
            {
                float phi_1 = (((float(d) + 0.5f) * 2.0f) * 3.1415927410125732421875f) / 8.0f;
                float2 direction_1 = float2(cos(phi_1), sin(phi_1));
                float dirShift = 0.20000000298023223876953125f + (0.25f * float(d & 1));
                float best_2 = 0.0f;
                for (int i_1 = 1; i_1 <= 3; i_1++)
                {
                    float t_1 = (float(i_1) - dirShift) / 3.0f;
                    float2 samplePixel_1 = pixel + (((direction_1 * contactRadius) * t_1) * scale);
                    bool _14774 = any(bool2(samplePixel_1.x < 0.0f.xx.x, samplePixel_1.y < 0.0f.xx.y));
                    bool _14783;
                    if (!_14774)
                    {
                        _14783 = samplePixel_1.x >= ambient_extent.x;
                    }
                    else
                    {
                        _14783 = _14774;
                    }
                    bool _14792;
                    if (!_14783)
                    {
                        _14792 = samplePixel_1.y >= ambient_extent.y;
                    }
                    else
                    {
                        _14792 = _14783;
                    }
                    if (_14792)
                    {
                        break;
                    }
                    float2 param_61 = samplePixel_1;
                    float4 q = positionAt(param_61);
                    if (q.w > 0.75f)
                    {
                        continue;
                    }
                    float2 param_62 = samplePixel_1;
                    float param_63 = q.z;
                    float rise = riseAt(param_62, param_63);
                    float height = (rise - riseHere) / 0.866025388240814208984375f;
                    float along = length(((q.xy + float2(0.0f, rise)) - footHere) * float2(1.0f, 2.0f));
                    if ((height < 1.0f) || (along > contactRadius))
                    {
                        continue;
                    }
                    float near_1 = 1.0f - (along / contactRadius);
                    best_2 = max(best_2, (height / ((height + (0.5f * along)) + 2.0f)) * near_1);
                }
                covered += best_2;
            }
            contact = 1.0f - ((ambient_contact.y * onGround) * clamp((covered / 8.0f) * 4.0f, 0.0f, 1.0f));
        }
    }
    float nUp = dot(nSurf, float3(0.0f, -0.866025388240814208984375f, 0.5f));
    float nToward = dot(nSurf, float3(0.0f, 0.5f, 0.866025388240814208984375f));
    float nRight = nSurf.x;
    float3 nLot = float3((nToward + nRight) * 0.707106769084930419921875f, (nToward - nRight) * 0.707106769084930419921875f, nUp);
    float2 _14898;
    if (length(nLot.xy) > 0.1500000059604644775390625f)
    {
        _14898 = normalize(nLot.xy);
    }
    else
    {
        _14898 = 0.0f.xx;
    }
    float2 horizN = _14898;
    float isVertical = 0.0f;
    float3 hereSurf = here;
    if (worldSpaceAO)
    {
        if (archWallMatch > 0.001000000047497451305389404296875f)
        {
            isVertical = ((archWallMatch * (1.0f - onFlatFloor)) * (1.0f - roofCalm)) * (1.0f - onDynamicSim);
            hereSurf = lerp(here, matchedWallPos, archWallMatch.xxx);
            horizN = matchedWallN;
            float3 wallViewN = normalize((float3(0.0f, 0.5f, 0.866025388240814208984375f) * ((matchedWallN.x + matchedWallN.y) * 0.707106769084930419921875f)) + float3((matchedWallN.x - matchedWallN.y) * 0.707106769084930419921875f, 0.0f, 0.0f));
            nSurf = normalize(lerp(nSurf, wallViewN, archWallMatch.xxx));
            normal = normalize(lerp(normal, normalize(lerp(wallViewN, float3(0.0f, 0.0f, 1.0f), 0.25f.xxx)), archWallMatch.xxx));
            nUp = dot(nSurf, float3(0.0f, -0.866025388240814208984375f, 0.5f));
            nLot = float3(matchedWallN, 0.0f);
        }
    }
    else
    {
        isVertical = ((((1.0f - onFlatFloor) * (1.0f - smoothstep(0.2199999988079071044921875f, 0.4199999868869781494140625f, abs(nUp)))) * (1.0f - roofCalm)) * (1.0f - smoothstep(2.5f, 4.5f, gradJump))) * (1.0f - onDynamicSim);
    }
    if (onDynamicSim > 0.00999999977648258209228515625f)
    {
        occlusion = lerp(occlusion, 1.0f - ((1.0f - occlusion) * 0.20000000298023223876953125f), onDynamicSim);
    }
    float inside = 0.0f;
    if (ambient_sunLot.w > 0.0f)
    {
        float2 insideOffset = lerp(horizN * 0.25f, 0.0f.xx, onFlatFloor.xx);
        float3 param_64 = hereSurf + float3(insideOffset, 0.0f);
        inside = indoors(param_64);
    }
    float2 param_65 = hereSurf.xy;
    float param_66 = hereSurf.z;
    float hereRelZ = hereSurf.z - terrainBaseAt(param_65, param_66);
    float vertSkyLift = 1.0f;
    bool _15039 = ((isVertical > 0.00999999977648258209228515625f) && (!onSnow)) && (onDynamicSim < 0.5f);
    bool _15045;
    if (_15039)
    {
        _15045 = ambient_params.y > 0.001000000047497451305389404296875f;
    }
    else
    {
        _15045 = _15039;
    }
    if (_15045)
    {
        float3 _15055;
        if ((centre.w < 0.25f) && (!worldSpaceAO))
        {
            float2 param_67 = p.xy;
            float param_68 = pSmooth.z / 27.7128124237060546875f;
            bool param_69 = false;
            float2 param_70 = ambient_frame.xy;
            _15055 = lotPoint(param_67, param_68, param_69, param_70);
        }
        else
        {
            _15055 = hereSurf;
        }
        float3 hereWall = _15055;
        float2 param_71 = hereWall.xy;
        float param_72 = hereWall.z;
        float wallRelZ = hereWall.z - terrainBaseAt(param_71, param_72);
        float aoStr = clamp(ambient_params.y, 0.0f, 1.0f) * isVertical;
        float zWall = max(0.0f, wallRelZ);
        float storyIdx = floor(max(0.0f, wallRelZ + 0.0500000007450580596923828125f) / 2.9500000476837158203125f);
        float storyRelZ = max(0.0f, wallRelZ - (storyIdx * 2.9500000476837158203125f));
        float zNorm = zWall / 2.9500000476837158203125f;
        float ramp = zNorm / (0.699999988079071044921875f + zNorm);
        float rawVertGrad = lerp(0.540000021457672119140625f, 1.2000000476837158203125f, ramp);
        vertSkyLift = lerp(1.0f, rawVertGrad, aoStr);
        float groundCrease = exp((-zWall) / 0.10999999940395355224609375f) * (1.0f - smoothstep(0.2599999904632568359375f, 0.519999980926513671875f, zWall));
        float upperFloorCrease = ((step(0.5f, storyIdx) * inside) * exp((-storyRelZ) / 0.0900000035762786865234375f)) * (1.0f - smoothstep(0.20000000298023223876953125f, 0.4199999868869781494140625f, storyRelZ));
        float baseAO = 1.0f - (aoStr * clamp((0.2199999988079071044921875f * groundCrease) + (0.14000000059604644775390625f * upperFloorCrease), 0.0f, 0.319999992847442626953125f));
        float _15155;
        if (worldSpaceAO)
        {
            float3 param_73 = hereWall;
            float2 param_74 = horizN;
            _15155 = wallCornerAO(param_73, param_74);
        }
        else
        {
            _15155 = 0.0f;
        }
        float cornerOcc = _15155;
        float cornerAO = 1.0f - ((0.3400000035762786865234375f * aoStr) * cornerOcc);
        float wallFloorZ = (hereWall.z - wallRelZ) + (storyIdx * 2.9500000476837158203125f);
        float _15183;
        if (hasVoxels && worldSpaceAO)
        {
            float3 param_75 = hereWall;
            float2 param_76 = horizN;
            float param_77 = wallFloorZ;
            int2 param_78 = vSize;
            int param_79 = vHalfH;
            float param_80 = vTopMarginHalf;
            int2 param_81 = vSliceMax;
            float2 param_82 = lotSz;
            _15183 = voxelWallAO(param_75, param_76, param_77, param_78, param_79, param_80, param_81, param_82) * (1.0f - (0.7200000286102294921875f * cornerOcc));
        }
        else
        {
            _15183 = 0.0f;
        }
        float staticWallOcc = _15183;
        float _15211;
        if (worldSpaceAO)
        {
            float3 param_83 = hereWall;
            float2 param_84 = horizN;
            _15211 = simWallProximityAO(param_83, param_84) * (1.0f - (0.64999997615814208984375f * cornerOcc));
        }
        else
        {
            _15211 = 0.0f;
        }
        float simWallOcc = _15211;
        float combinedWallOcc = max(staticWallOcc, simWallOcc);
        float vWallOcc = staticWallOcc + ((combinedWallOcc - staticWallOcc) * 0.5f);
        float vWallAO = 1.0f - ((0.439999997615814208984375f * aoStr) * vWallOcc);
        occlusion = lerp(occlusion, 1.0f, (0.7200000286102294921875f * isVertical) * cornerOcc);
        occlusion = max(((occlusion * baseAO) * cornerAO) * vWallAO, 0.2199999988079071044921875f);
    }
    bool _15257 = !onSnow;
    bool _15263;
    if (_15257)
    {
        _15263 = centre.w < 0.25f;
    }
    else
    {
        _15263 = _15257;
    }
    bool _15277 = ((((_15263 && (onFlatFloor < 0.5f)) && (onDynamicSim < 0.5f)) && (roofCalm < 0.5f)) && (isVertical < 0.9900000095367431640625f)) && worldSpaceAO;
    bool _15283;
    if (_15277)
    {
        _15283 = ambient_params.y > 0.001000000047497451305389404296875f;
    }
    else
    {
        _15283 = _15277;
    }
    if (_15283)
    {
        float aoParam = clamp(ambient_params.y, 0.0f, 1.0f) * (1.0f - isVertical);
        float zProp = max(0.0f, hereRelZ);
        float propNorm = zProp / 2.9500000476837158203125f;
        float propGrad = lerp(0.819999992847442626953125f, 1.059999942779541015625f, propNorm / (0.64999997615814208984375f + propNorm));
        vertSkyLift *= lerp(1.0f, propGrad, aoParam);
        float storySpriteZ = max(0.0f, hereRelZ - (floor(max(0.0f, hereRelZ + 0.0500000007450580596923828125f) / 2.9500000476837158203125f) * 2.9500000476837158203125f));
        int spriteRow = clamp(int(floor((hereRelZ + 0.1500000059604644775390625f) / 2.9500000476837158203125f)), 0, storiesCount - 1);
        float spriteOcc = 0.0f;
        if (storySpriteZ < 0.519999980926513671875f)
        {
            float selfBase = 0.550000011920928955078125f;
            float clusterDensity = 0.0f;
            bool _15344;
            if (hasVoxels)
            {
                _15344 = all(bool2(here.xy.x >= 0.0f.xx.x, here.xy.y >= 0.0f.xx.y));
            }
            else
            {
                _15344 = hasVoxels;
            }
            bool _15352;
            if (_15344)
            {
                _15352 = all(bool2(here.xy.x < lotSz.x, here.xy.y < lotSz.y));
            }
            else
            {
                _15352 = _15344;
            }
            if (_15352)
            {
                float2 param_85 = here.xy;
                int param_86 = spriteRow;
                int2 param_87 = vSize;
                float3 selfGround = sampleBakedGroundAO(param_85, param_86, param_87);
                selfBase = clamp((selfGround.x * 0.64999997615814208984375f) + (selfGround.y * 0.4199999868869781494140625f), 0.0f, 1.0f);
                clusterDensity = selfGround.z;
            }
            float rootFade = 1.0f - smoothstep(0.02999999932944774627685546875f, 0.25f, storySpriteZ);
            float bodyFade = 1.0f - smoothstep(0.0599999986588954925537109375f, 0.519999980926513671875f, storySpriteZ);
            spriteOcc += (((0.20000000298023223876953125f * selfBase) * rootFade) + ((0.14000000059604644775390625f * clusterDensity) * bodyFade));
        }
        float3 param_88 = here;
        int param_89 = spriteRow;
        float wallCrevice = spriteWallProximityAO(param_88, param_89) * (1.0f - smoothstep(2.599999904632568359375f, 2.9500000476837158203125f, storySpriteZ));
        spriteOcc += (0.2599999904632568359375f * wallCrevice);
        if (hasVoxels)
        {
            float3 param_90 = here + float3(0.0f, 0.0f, 0.2599999904632568359375f);
            int2 param_91 = vSize;
            int param_92 = vHalfH;
            float param_93 = vTopMarginHalf;
            int2 param_94 = vSliceMax;
            float2 param_95 = lotSz;
            float param_96 = 0.5f;
            float gapClear = 1.0f - dualViewHullAtPrecomp(param_90, param_91, param_92, param_93, param_94, param_95, param_96);
            if (gapClear > 0.3499999940395355224609375f)
            {
                float3 param_97 = here + float3(0.0f, 0.0f, 0.519999980926513671875f);
                int2 param_98 = vSize;
                int param_99 = vHalfH;
                float param_100 = vTopMarginHalf;
                int2 param_101 = vSliceMax;
                float2 param_102 = lotSz;
                float param_103 = 1.2000000476837158203125f;
                float overNear = dualViewHullAtPrecomp(param_97, param_98, param_99, param_100, param_101, param_102, param_103);
                float3 param_104 = here + float3(0.0f, 0.0f, 0.89999997615814208984375f);
                int2 param_105 = vSize;
                int param_106 = vHalfH;
                float param_107 = vTopMarginHalf;
                int2 param_108 = vSliceMax;
                float2 param_109 = lotSz;
                float param_110 = 1.60000002384185791015625f;
                float overFar = dualViewHullAtPrecomp(param_104, param_105, param_106, param_107, param_108, param_109, param_110);
                spriteOcc += ((0.23999999463558197021484375f * gapClear) * max(overNear * 0.85000002384185791015625f, overFar * 0.550000011920928955078125f));
            }
        }
        occlusion = max(occlusion * (1.0f - (aoParam * clamp(spriteOcc, 0.0f, 0.579999983310699462890625f))), 0.319999992847442626953125f);
    }
    float lit = 1.0f;
    float litColumn = 1.0f;
    float litShell = 1.0f;
    float window = 0.0f;
    bool _15490 = ambient_sunLot.w > 0.0f;
    bool _15496;
    if (_15490)
    {
        _15496 = ambient_params.z > 0.001000000047497451305389404296875f;
    }
    else
    {
        _15496 = _15490;
    }
    bool _15505;
    if (_15496)
    {
        uint _15502_dummy_parameter;
        _15505 = int2(spvTextureSize(sunShadowMap, uint(0), _15502_dummy_parameter)).x > 1;
    }
    else
    {
        _15505 = _15496;
    }
    if (_15505)
    {
        float4 sunTap = sunShadowMap.Load(int3(int2(gl_FragCoord.xy), 0));
        lit = sunTap.x;
        window = sunTap.y;
        litColumn = sunTap.z;
        litShell = sunTap.w;
    }
    float _15527;
    if (ambient_sunLot.w > 0.0f)
    {
        float3 param_111 = here;
        _15527 = cloudLight(param_111);
    }
    else
    {
        _15527 = 1.0f;
    }
    float sky = _15527;
    window *= sky;
    lit *= sky;
    float shadowStr = clamp(((ambient_params.z * lerp(1.0f, 0.680000007152557373046875f, inside)) * (1.0f + ((0.2800000011920928955078125f * isVertical) * (1.0f - (0.550000011920928955078125f * inside))))) * lerp(1.0f, 0.7200000286102294921875f, roofCalm), 0.0f, 0.85000002384185791015625f);
    float shadow = lerp(1.0f, lit, shadowStr);
    float3 lampLight = 0.0f.xxx;
    float3 fireLight = 0.0f.xxx;
    float maxNearBulb = 0.0f;
    int lampCount = int(ambient_lamp.x);
    float reach = ambient_lamp.y;
    bool sides = ambient_sunLot.w > 0.0f;
    float tFire = ambient_weather.z;
    float3 pLamp = float3(p.xy, ((here.x + here.y) + (0.800000011920928955078125f * here.z)) * 27.7128124237060546875f);
    float isObjectSprite = (((float(centre.w < 0.25f) * (1.0f - onFlatFloor)) * (1.0f - isVertical)) * (1.0f - roofCalm)) * (1.0f - onDynamicSim);
    float3 spriteLampNormal = normalize(lerp(nSurf, float3(0.0f, 0.0f, 1.0f), max(lerp(0.36000001430511474609375f, 0.85000002384185791015625f, onDynamicSim), 0.7799999713897705078125f * isObjectSprite).xxx));
    float3 _15627;
    if (centre.w > 0.25f)
    {
        _15627 = nSurf;
    }
    else
    {
        _15627 = normalize(lerp(spriteLampNormal, nSurf, onLevel2Floor.xxx));
    }
    float3 lampNormal = _15627;
    float fireGainEst = ambient_lamp.z * lerp(2.349999904632568359375f, 1.14999997615814208984375f, smoothstep(0.3499999940395355224609375f, 1.35000002384185791015625f, ambient_lamp.z));
    bool _15649 = lampCount > 0;
    bool _15662;
    if (_15649)
    {
        bool _15654 = ambient_lamp.z > 0.001000000047497451305389404296875f;
        bool _15661;
        if (!_15654)
        {
            _15661 = ambient_extent.z > 5.5f;
        }
        else
        {
            _15661 = _15654;
        }
        _15662 = _15661;
    }
    else
    {
        _15662 = _15649;
    }
    if (_15662)
    {
        float _15756;
        float _15812;
        float _15853;
        for (int index = 0; index < 16; index++)
        {
            if (index >= lampCount)
            {
                break;
            }
            float4 lamp = ambient_lamps[index];
            bool isFire = lamp.w < 0.0f;
            float strength = abs(lamp.w);
            float3 toLamp = float3(lamp.xy, lamp.z * 27.7128124237060546875f) - pLamp;
            float _distance_1 = length(toLamp);
            float flicker01 = 0.5f;
            float flicker = 1.0f;
            if (isFire)
            {
                float phase = dot(lamp.xy, float2(0.037000000476837158203125f, 0.0529999993741512298583984375f));
                float wave = ((0.5f * sin((tFire * 5.69999980926513671875f) + phase)) + (0.319999992847442626953125f * sin(((tFire * 11.30000019073486328125f) + (phase * 1.7000000476837158203125f)) + 1.10000002384185791015625f))) + (0.180000007152557373046875f * sin(((tFire * 19.1000003814697265625f) + (phase * 2.2999999523162841796875f)) + 2.400000095367431640625f));
                flicker01 = clamp(0.5f + (0.5f * wave), 0.0f, 1.0f);
                flicker = 0.839999973773956298828125f + (0.300000011920928955078125f * flicker01);
            }
            if (isFire)
            {
                _15756 = reach * (1.41999995708465576171875f + (0.07999999821186065673828125f * flicker01));
            }
            else
            {
                _15756 = reach * 1.35000002384185791015625f;
            }
            float lampReach = _15756;
            if (_distance_1 >= lampReach)
            {
                continue;
            }
            float3 direction_2 = toLamp / max(_distance_1, 9.9999997473787516355514526367188e-05f).xxx;
            float normD = clamp(_distance_1 / max(lampReach, 9.9999997473787516355514526367188e-05f), 0.0f, 1.0f);
            float win = clamp(1.0f - (normD * normD), 0.0f, 1.0f);
            float falloff_1 = (1.12000000476837158203125f * (win * win)) / (1.0f + ((11.0f * normD) * normD));
            float nearBulb = 1.0f - smoothstep(14.0f, 34.0f, _distance_1);
            if (isFire)
            {
                _15812 = clamp((dot(lampNormal, direction_2) * 0.64999997615814208984375f) + 0.3499999940395355224609375f, 0.0f, 1.0f);
            }
            else
            {
                _15812 = clamp((dot(lampNormal, direction_2) * 0.7200000286102294921875f) + 0.2800000011920928955078125f, 0.0f, 1.0f);
            }
            float facing = _15812;
            facing = lerp(facing, 1.0f, nearBulb);
            float rawContrib = ((strength * flicker) * falloff_1) * facing;
            if (rawContrib < 0.00120000005699694156646728515625f)
            {
                continue;
            }
            bool _15848 = ambient_extent.z < 0.5f;
            bool _15864;
            if (_15848)
            {
                if (isFire)
                {
                    _15853 = fireGainEst;
                }
                else
                {
                    _15853 = ambient_lamp.z;
                }
                _15864 = (rawContrib * _15853) < 0.0005000000237487256526947021484375f;
            }
            else
            {
                _15864 = _15848;
            }
            if (_15864)
            {
                continue;
            }
            float3 lampLot = 0.0f.xxx;
            float sameSide = 1.0f;
            if (sides)
            {
                float2 param_112 = lamp.xy;
                float param_113 = lamp.z;
                bool param_114 = false;
                float2 param_115 = ambient_frame.xy;
                lampLot = lotPoint(param_112, param_113, param_114, param_115);
                float3 param_116 = lampLot;
                bool _15888 = indoors(param_116) > 0.25f;
                bool _15908;
                if (_15888)
                {
                    bool _15892 = roofCalm > 0.20000000298023223876953125f;
                    bool _15907;
                    if (!_15892)
                    {
                        bool _15897 = inside < 0.25f;
                        bool _15906;
                        if (_15897)
                        {
                            _15906 = hereSurf.z > (lampLot.z + 1.0f);
                        }
                        else
                        {
                            _15906 = _15897;
                        }
                        _15907 = _15906;
                    }
                    else
                    {
                        _15907 = _15892;
                    }
                    _15908 = _15907;
                }
                else
                {
                    _15908 = _15888;
                }
                if (_15908)
                {
                    continue;
                }
                float3 param_117 = hereSurf;
                float3 param_118 = lampLot;
                float param_119 = onFlatFloor;
                sameSide = lampFloorVis(param_117, param_118, param_119);
                if (sameSide <= 0.00999999977648258209228515625f)
                {
                    continue;
                }
                float3 param_120 = hereSurf;
                float3 param_121 = lampLot;
                float param_122 = onFlatFloor;
                float2 param_123 = horizN;
                sameSide *= lampWallVis(param_120, param_121, param_122, param_123);
                if (sameSide <= 0.00999999977648258209228515625f)
                {
                    continue;
                }
            }
            float contrib = rawContrib * sameSide;
            if (contrib < 0.00120000005699694156646728515625f)
            {
                continue;
            }
            falloff_1 *= smoothstep(0.00120000005699694156646728515625f, 0.0035000001080334186553955078125f, contrib);
            maxNearBulb = max(maxNearBulb, nearBulb * clamp((strength * falloff_1) * sameSide, 0.0f, 1.0f));
            float open = 1.0f;
            if (sides)
            {
                float3 param_124 = hereSurf;
                float3 param_125 = lampLot;
                float param_126 = onFlatFloor;
                float param_127 = isVertical;
                float param_128 = nUp;
                float2 param_129 = lerp(horizN, 0.0f.xx, onDynamicSim.xx);
                bool param_130 = isFire;
                float param_131 = onDynamicSim;
                open = lampMarch(param_124, param_125, param_126, param_127, param_128, param_129, param_130, param_131);
            }
            else
            {
                for (int i_2 = 1; i_2 < 16; i_2++)
                {
                    float t_2 = ((float(i_2) - 0.5f) / 16.0f) * _distance_1;
                    bool _16011;
                    if (isFire)
                    {
                        _16011 = (_distance_1 - t_2) < 22.0f;
                    }
                    else
                    {
                        _16011 = isFire;
                    }
                    if (_16011)
                    {
                        continue;
                    }
                    float3 q_1 = pLamp + (direction_2 * t_2);
                    float2 samplePixel_2 = ambient_view.xy + (q_1.xy * scale);
                    bool _16032 = any(bool2(samplePixel_2.x < 0.0f.xx.x, samplePixel_2.y < 0.0f.xx.y));
                    bool _16041;
                    if (!_16032)
                    {
                        _16041 = samplePixel_2.x >= ambient_extent.x;
                    }
                    else
                    {
                        _16041 = _16032;
                    }
                    bool _16050;
                    if (!_16041)
                    {
                        _16050 = samplePixel_2.y >= ambient_extent.y;
                    }
                    else
                    {
                        _16050 = _16041;
                    }
                    if (_16050)
                    {
                        break;
                    }
                    float2 param_132 = samplePixel_2;
                    float4 samplePos_1 = positionAt(param_132);
                    float sampleZ = samplePos_1.z;
                    bool _16063 = samplePos_1.w > 0.25f;
                    bool _16069;
                    if (_16063)
                    {
                        _16069 = samplePos_1.w < 0.75f;
                    }
                    else
                    {
                        _16069 = _16063;
                    }
                    if (_16069)
                    {
                        float2 param_133 = samplePos_1.xy;
                        float param_134 = samplePos_1.z / 27.7128124237060546875f;
                        bool param_135 = true;
                        float2 param_136 = ambient_frame.xy;
                        float3 sampleLot = lotPoint(param_133, param_134, param_135, param_136);
                        sampleZ = ((sampleLot.x + sampleLot.y) + (0.800000011920928955078125f * sampleLot.z)) * 27.7128124237060546875f;
                    }
                    float h = sampleZ - q_1.z;
                    if (h > 2.0f)
                    {
                        float thickFade = 1.0f - smoothstep(0.64999997615814208984375f * thickness, thickness, h);
                        open = min(open, 1.0f - (thickFade * clamp((h - 2.0f) / ((0.100000001490116119384765625f * t_2) + 3.0f), 0.0f, 1.0f)));
                    }
                }
            }
            if (isFire)
            {
                float3 fireTint = lerp(float3(1.0f, 0.23999999463558197021484375f, 0.02999999932944774627685546875f), float3(1.0f, 0.4199999868869781494140625f, 0.07999999821186065673828125f), flicker01.xxx);
                fireLight += (fireTint * (((((strength * flicker) * falloff_1) * facing) * open) * sameSide));
            }
            else
            {
                float3 coreLampCol = lerp(float3(1.08000004291534423828125f, 0.980000019073486328125f, 0.86000001430511474609375f), float3(1.0f, 0.819999992847442626953125f, 0.579999983310699462890625f), smoothstep(0.07999999821186065673828125f, 0.64999997615814208984375f, normD).xxx);
                lampLight += (coreLampCol * ((((strength * falloff_1) * facing) * open) * sameSide));
            }
        }
    }
    float nightFactor = clamp(ambient_weather.w, 0.0f, 1.0f);
    float lowSun = 1.0f - smoothstep(0.119999997317790985107421875f, 0.519999980926513671875f, ambient_sunLot.z);
    float _16189;
    if (ambient_tone.w >= 0.0f)
    {
        _16189 = clamp(ambient_tone.w, 0.0f, 1.0f);
    }
    else
    {
        _16189 = 0.5f + (0.449999988079071044921875f * lowSun);
    }
    float dayProgress = _16189;
    float param_137 = dayProgress;
    float3 param_138;
    float3 param_139;
    float3 param_140;
    dayPalette(param_137, param_138, param_139, param_140);
    float3 warmSun = param_138;
    float3 coolShade = param_139;
    float3 dayWindowColor = param_140;
    float3 moonWindowColor = float3(0.680000007152557373046875f, 0.819999992847442626953125f, 1.17999994754791259765625f);
    float3 windowColor = lerp(dayWindowColor, moonWindowColor, smoothstep(0.550000011920928955078125f, 0.89999997615814208984375f, nightFactor).xxx);
    float fireBoost = lerp(2.349999904632568359375f, 1.14999997615814208984375f, smoothstep(0.3499999940395355224609375f, 1.35000002384185791015625f, ambient_lamp.z));
    float3 lamps = lampLight * ambient_lamp.z;
    float3 fires = fireLight * (ambient_lamp.z * fireBoost);
    float firePeak = max(fires.x, max(fires.y, fires.z));
    if (firePeak > 1.35000002384185791015625f)
    {
        float compressed = 1.35000002384185791015625f + ((firePeak - 1.35000002384185791015625f) / (1.0f + ((firePeak - 1.35000002384185791015625f) * 1.60000002384185791015625f)));
        fires *= (compressed / firePeak);
    }
    float3 totalLamps = lamps + fires;
    float outdoor = 1.0f - inside;
    float sunWeight = lerp(1.0f, 0.699999988079071044921875f, inside);
    float3 sunViewDir = normalize(ambient_light.xyz + float3(0.0f, 0.0f, 9.9999997473787516355514526367188e-05f));
    float keyWrap = dot(normal, sunViewDir);
    float _16288;
    if (runScreenGTAO)
    {
        _16288 = lerp(1.0f, smoothstep(-0.4000000059604644775390625f, 0.550000011920928955078125f, dot(bentNormal, sunViewDir)), (((0.2800000011920928955078125f * (1.0f - onFlatFloor)) * (1.0f - roofCalm)) * (1.0f - isVertical)) * (1.0f - onDynamicSim));
    }
    else
    {
        _16288 = 1.0f;
    }
    float bentSunOcc = _16288;
    float shadowActive = clamp(ambient_params.z * 1.7999999523162841796875f, 0.0f, 1.0f) * (1.0f - (0.800000011920928955078125f * nightFactor));
    float dirShade = 1.0f + ((((((((keyWrap * 0.20000000298023223876953125f) - 0.039999999105930328369140625f) * lerp(1.0f, 0.550000011920928955078125f, inside)) * lit) * shadowActive) * (1.0f - (0.449999988079071044921875f * onFlatFloor))) * (1.0f - onDynamicSim)) * (1.0f - (0.87999999523162841796875f * isObjectSprite)));
    dirShade *= lerp(1.0f, bentSunOcc, shadowActive * lit);
    float deBakeWeight = smoothstep(0.0199999995529651641845703125f, 0.100000001490116119384765625f, ambient_params.z) * (1.0f - (0.85000002384185791015625f * nightFactor));
    float wallDeBake = exp((((-0.4199999868869781494140625f) * clamp(nSurf.x, -0.699999988079071044921875f, 0.699999988079071044921875f)) * isVertical) * deBakeWeight);
    dirShade *= wallDeBake;
    float sunBloom = 1.0f + ((((0.119999997317790985107421875f * (1.0f - nightFactor)) * lit) * sunWeight) * shadowActive);
    float bentUp = clamp((dot(lerp(bentNormal, float3(0.0f, -0.866025388240814208984375f, 0.5f), (0.5f * isObjectSprite).xxx), float3(0.0f, -0.866025388240814208984375f, 0.5f)) * 0.5f) + 0.5f, 0.0f, 1.0f);
    float3 skyFill = float3(0.839999973773956298828125f, 0.930000007152557373046875f, 1.13999998569488525390625f);
    float3 groundBounce = float3(1.12000000476837158203125f, 1.0299999713897705078125f, 0.86000001430511474609375f);
    float3 hemiGI = lerp(groundBounce, skyFill, bentUp.xxx);
    hemiGI /= dot(hemiGI, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)).xxx;
    float giStrength = (((((1.0f - nightFactor) * (1.0f - (lit * 0.550000011920928955078125f))) * lerp(0.319999992847442626953125f, 0.1599999964237213134765625f, inside)) * (1.0f - (0.64999997615814208984375f * onFlatFloor))) * (1.0f - (0.75f * isVertical))) * (1.0f - (0.699999988079071044921875f * isObjectSprite));
    float3 bounceAlbedo = 0.2800000011920928955078125f.xxx;
    bool hasSceneAlbedo = false;
    bool _16440 = !onSnow;
    bool _16449;
    if (_16440)
    {
        uint _16446_dummy_parameter;
        _16449 = int2(spvTextureSize(sceneColorMap, uint(0), _16446_dummy_parameter)).x > 1;
    }
    else
    {
        _16449 = _16440;
    }
    if (_16449)
    {
        float4 baseCol = sceneColorMap.Load(int3(fullPx, 0));
        if (baseCol.w > 0.0199999995529651641845703125f)
        {
            float3 rawAlb = clamp(baseCol.xyz, 0.02999999932944774627685546875f.xxx, 0.87999999523162841796875f.xxx);
            float rawLum = max(dot(rawAlb, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)), 9.9999997473787516355514526367188e-05f);
            bounceAlbedo = clamp(rawAlb * (lerp(0.3400000035762786865234375f, rawLum, 0.4600000083446502685546875f) / rawLum), 0.0500000007450580596923828125f.xxx, 0.7599999904632568359375f.xxx);
            hasSceneAlbedo = true;
        }
    }
    float3 _16490;
    if (((!onSnow) && hasSceneAlbedo) && (occlusion < 0.999000012874603271484375f))
    {
        float param_141 = occlusion;
        float3 param_142 = bounceAlbedo;
        _16490 = lerp(occlusion.xxx, multiBounceAO(param_141, param_142), 0.63999998569488525390625f.xxx);
    }
    else
    {
        _16490 = occlusion.xxx;
    }
    float3 mbOcc = _16490;
    bool _16511 = (!onSnow) && worldSpaceAO;
    bool _16517;
    if (_16511)
    {
        _16517 = ambient_params.y > 0.001000000047497451305389404296875f;
    }
    else
    {
        _16517 = _16511;
    }
    float3 _16518;
    if (_16517)
    {
        float3 param_143 = hereSurf;
        float2 param_144 = horizN;
        float2 param_145 = nLot.xy;
        float param_146 = isVertical;
        float param_147 = onFlatFloor;
        float param_148 = onDynamicSim;
        int param_149 = storiesCount;
        _16518 = gatherRoomBounceGI(param_143, param_144, param_145, param_146, param_147, param_148, param_149);
    }
    else
    {
        _16518 = 0.0f.xxx;
    }
    float3 roomBounceGI = _16518;
    float bounceShadeMask = (1.0f - ((0.680000007152557373046875f * lit) * clamp(shadowStr * 1.60000002384185791015625f, 0.0f, 1.0f))) * lerp(0.2199999988079071044921875f, 1.0f, inside);
    float3 giTerm = (roomBounceGI * ((0.300000011920928955078125f * clamp(ambient_params.y, 0.0f, 1.2000000476837158203125f)) * bounceShadeMask)) * lerp(1.0f.xxx, mbOcc, 0.449999988079071044921875f.xxx);
    float effVertGrad = lerp(lerp(vertSkyLift, lerp(vertSkyLift, 1.0299999713897705078125f, 0.2199999988079071044921875f), lit * shadowActive), 1.0f, 0.64999997615814208984375f * maxNearBulb);
    float3 envBase = lerp(1.0f.xxx, hemiGI, giStrength.xxx) * (((dirShade * effVertGrad) * sunBloom) * ambient_lamp.w);
    float3 skyTerm = envBase * (1.0f - shadowStr);
    float3 sunTerm = (envBase * (shadowStr * lit)) + (windowColor * ((0.2199999988079071044921875f * ambient_contact.z) * window));
    float3 ambOcc = lerp(mbOcc * contact, 1.0f.xxx, maxNearBulb.xxx);
    float sunOccCouple = lerp(0.07999999821186065673828125f, 0.37999999523162841796875f, isVertical);
    float3 sunMicroOcc = lerp(lerp(1.0f.xxx, mbOcc, sunOccCouple.xxx) * lerp(1.0f, contact, 0.2599999904632568359375f), 1.0f.xxx, maxNearBulb.xxx);
    float3 lampOcc = lerp(lerp(1.0f.xxx, mbOcc, 0.519999980926513671875f.xxx) * lerp(1.0f, contact, 0.579999983310699462890625f), 1.0f.xxx, maxNearBulb.xxx);
    float3 light = (((ambOcc * skyTerm) + (sunMicroOcc * sunTerm)) + (lampOcc * totalLamps)) + giTerm;
    float daylight = 1.0f - nightFactor;
    float3 sunTint = lerp(coolShade, warmSun, lit.xxx);
    sunTint /= dot(sunTint, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)).xxx;
    float fireShare = dot(fires, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)) / ((ambient_lamp.w + dot(fires, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f))) + 9.9999997473787516355514526367188e-05f);
    float3 tint = lerp(1.0f.xxx, sunTint, (((clamp(ambient_tone.x, 0.0f, 1.35000002384185791015625f) * daylight) * lerp(1.0f, 0.64999997615814208984375f, inside)) * (1.0f - (0.85000002384185791015625f * fireShare))).xxx);
    float _16696;
    if (dayProgress < 0.5f)
    {
        _16696 = smoothstep(0.550000011920928955078125f, 0.800000011920928955078125f, nightFactor) * (1.0f - smoothstep(0.85000002384185791015625f, 0.980000019073486328125f, nightFactor));
    }
    else
    {
        _16696 = smoothstep(0.2800000011920928955078125f, 0.579999983310699462890625f, nightFactor) * (1.0f - smoothstep(0.7200000286102294921875f, 0.959999978542327880859375f, nightFactor));
    }
    float twilight = _16696;
    float3 blueHour = float3(0.863165557384490966796875f, 0.99945485591888427734375f, 1.40832269191741943359375f);
    float lampShare = dot(totalLamps, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)) / ((ambient_lamp.w + dot(totalLamps, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f))) + 9.9999997473787516355514526367188e-05f);
    tint = lerp(tint, blueHour, ((((twilight * lerp(1.0f, 0.3499999940395355224609375f, inside)) * ambient_tone.x) * 0.699999988079071044921875f) * (1.0f - lampShare)).xxx);
    float3 moonLit = float3(0.63999998569488525390625f, 0.819999992847442626953125f, 1.37999999523162841796875f);
    float3 moonShade = float3(0.540000021457672119140625f, 0.7200000286102294921875f, 1.440000057220458984375f);
    float3 moon = lerp(moonShade, moonLit, lit.xxx);
    tint = lerp(tint, moon, (((nightFactor * lerp(1.0f, 0.4199999868869781494140625f, inside)) * 0.87999999523162841796875f) * (1.0f - lampShare)).xxx);
    light *= tint;
    bool _16771 = nightFactor > 0.0500000007450580596923828125f;
    bool _16777;
    if (_16771)
    {
        _16777 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _16777 = _16771;
    }
    bool _16783;
    if (_16777)
    {
        _16783 = centre.w > 0.25f;
    }
    else
    {
        _16783 = _16777;
    }
    if (_16783)
    {
        float3 param_150 = here;
        float param_151 = onGround;
        float2 spill = windowSpillInfo(param_150, param_151);
        float3 spillColor = lerp(float3(1.0f, 0.819999992847442626953125f, 0.579999983310699462890625f), float3(1.0f, 0.3400000035762786865234375f, 0.0500000007450580596923828125f), spill.y.xxx);
        light += (spillColor * (((occlusion * 0.699999988079071044921875f) * nightFactor) * spill.x));
    }
    bool _16811 = ambient_weather.x > 0.60000002384185791015625f;
    bool _16818;
    if (!_16811)
    {
        _16818 = ambient_skyExtra.z > 0.5f;
    }
    else
    {
        _16818 = _16811;
    }
    bool _16824;
    if (_16818)
    {
        _16824 = ambient_skyExtra.y < 0.5f;
    }
    else
    {
        _16824 = _16818;
    }
    if (_16824)
    {
        float lSlot = floor(ambient_weather.z / 7.0f);
        float _16836;
        if (ambient_skyExtra.z > 0.5f)
        {
            _16836 = 0.550000011920928955078125f;
        }
        else
        {
            _16836 = (ambient_weather.x - 0.60000002384185791015625f) * 1.60000002384185791015625f;
        }
        float lChance = _16836;
        float2 param_152 = float2(lSlot, 3.0f);
        float lStrikes = step(hash12(param_152), lChance);
        float2 param_153 = float2(lSlot, 7.0f);
        float lDt = ((ambient_weather.z - (lSlot * 7.0f)) - 1.0f) - (4.0f * hash12(param_153));
        float _16868;
        if (lDt < 0.0f)
        {
            _16868 = 0.0f;
        }
        else
        {
            float _16878;
            if (lDt < 0.180000007152557373046875f)
            {
                _16878 = 0.0f;
            }
            else
            {
                _16878 = 0.699999988079071044921875f * exp((-(lDt - 0.180000007152557373046875f)) * 9.0f);
            }
            _16868 = exp((-lDt) * 10.0f) + _16878;
        }
        float lFlash = _16868;
        lFlash = clamp(lFlash * lStrikes, 0.0f, 1.0f);
        light += ((float3(0.85000002384185791015625f, 0.949999988079071044921875f, 1.25f) * occlusion) * ((lFlash * 0.75f) * outdoor));
    }
    float _16909;
    if (ambient_skyExtra.x > 0.5f)
    {
        _16909 = 0.0f;
    }
    else
    {
        _16909 = ambient_weather.y * outdoor;
    }
    float rawWet = _16909;
    float3 param_154 = here;
    float wet = rawWet * architecturalExposure(param_154);
    float standing = 0.0f;
    if (rawWet > 0.0f)
    {
        bool _16932 = centre.w < 0.25f;
        bool _16938;
        if (_16932)
        {
            _16938 = ambient_sunLot.w > 0.0f;
        }
        else
        {
            _16938 = _16932;
        }
        bool _16950;
        if (_16938)
        {
            float2 param_155 = pixel;
            float3 param_156 = p;
            float3 param_157 = here;
            float3 param_158 = nSurf;
            _16950 = isRainRoofPixel(param_155, param_156, param_157, param_158);
        }
        else
        {
            _16950 = _16938;
        }
        bool onRoof = _16950;
        if (onRoof)
        {
            float3 param_159 = here + float3(0.0f, 0.0f, 0.449999988079071044921875f);
            float roofWet = rawWet * architecturalExposure(param_159);
            float2 param_160 = here.xy;
            float2 source = lotSource(param_160);
            float2 a = mul(source, float2x2(float2(0.800000011920928955078125f, 0.60000002384185791015625f), float2(-0.60000002384185791015625f, 0.800000011920928955078125f)));
            float2 b = mul(source, float2x2(float2(0.2800000011920928955078125f, -0.959999978542327880859375f), float2(0.959999978542327880859375f, 0.2800000011920928955078125f)));
            float2 param_161 = (a / 1.89999997615814208984375f.xx) + 5.30000019073486328125f.xx;
            float2 param_162 = (b / 0.85000002384185791015625f.xx) + 19.700000762939453125f.xx;
            float2 param_163 = float2((source.x * 2.599999904632568359375f) + (here.z * 0.4000000059604644775390625f), (source.y * 2.599999904632568359375f) - (here.z * 0.4000000059604644775390625f));
            float roofField = ((0.550000011920928955078125f * smoothNoise(param_161)) + (0.300000011920928955078125f * smoothNoise(param_162))) + (0.1500000059604644775390625f * smoothNoise(param_163));
            float spread = smoothstep(0.07999999821186065673828125f, 0.819999992847442626953125f, roofWet);
            float roofPatch = smoothstep(lerp(0.62000000476837158203125f, 0.07999999821186065673828125f, spread), lerp(0.800000011920928955078125f, 0.3400000035762786865234375f, spread), roofField) * smoothstep(0.0500000007450580596923828125f, 0.2599999904632568359375f, roofWet);
            float roofFull = smoothstep(0.449999988079071044921875f, 0.87999999523162841796875f, roofWet);
            float roofSoak = max(roofPatch, roofFull * (0.800000011920928955078125f + (0.20000000298023223876953125f * smoothstep(0.20000000298023223876953125f, 0.800000011920928955078125f, roofField))));
            float3 roofTint = lerp(float3(0.62000000476837158203125f, 0.64999997615814208984375f, 0.699999988079071044921875f), float3(0.5f, 0.540000021457672119140625f, 0.60000002384185791015625f), ((roofFull * 0.64999997615814208984375f) + (smoothstep(0.449999988079071044921875f, 0.85000002384185791015625f, roofField) * 0.3499999940395355224609375f)).xxx);
            light *= lerp(1.0f.xxx, roofTint, roofSoak.xxx);
            standing = clamp(roofSoak * lerp(0.3499999940395355224609375f, 0.7200000286102294921875f, smoothstep(0.3499999940395355224609375f, 0.800000011920928955078125f, roofField)), 0.0f, 0.7799999713897705078125f);
            if ((ambient_weather.x > 0.0f) && (roofSoak > 0.20000000298023223876953125f))
            {
                float2 rg = (source * 4.19999980926513671875f) + float2(here.z * 0.699999988079071044921875f, (-here.z) * 0.5f);
                float2 rid = floor(rg);
                float2 param_164 = rid + 11.30000019073486328125f.xx;
                float2 param_165 = rid + 23.700000762939453125f.xx;
                float2 rdrop = (rid + 0.25f.xx) + (float2(hash12(param_164), hash12(param_165)) * 0.5f);
                float2 param_166 = rid + 5.099999904632568359375f.xx;
                float rage = frac((ambient_weather.z * (1.10000002384185791015625f + (0.64999997615814208984375f * ambient_weather.x))) + hash12(param_166));
                float ring = (1.0f - smoothstep(0.0f, 0.07999999821186065673828125f, abs(length(rg - rdrop) - (rage * 0.319999992847442626953125f)))) * (1.0f - rage);
                light *= (1.0f + (((0.1599999964237213134765625f * ring) * roofSoak) * ambient_weather.x));
            }
            else
            {
                light *= (1.0f + (((0.0599999986588954925537109375f * roofSoak) * (1.0f - smoothstep(0.20000000298023223876953125f, 0.60000002384185791015625f, ambient_weather.w))) * (1.0f - clamp(ambient_clouds.x, 0.0f, 1.0f))));
            }
        }
        else
        {
            if (wet > 0.0f)
            {
                light *= lerp(1.0f.xxx, float3(0.819999992847442626953125f, 0.839999973773956298828125f, 0.87000000476837158203125f), (wet * lerp(0.449999988079071044921875f, 0.64999997615814208984375f, onGround)).xxx);
                if ((centre.w > 0.25f) && (onGround > 0.5f))
                {
                    float2 param_167 = here.xy;
                    float2 source_1 = lotSource(param_167);
                    float2 a_1 = mul(source_1, float2x2(float2(0.800000011920928955078125f, 0.60000002384185791015625f), float2(-0.60000002384185791015625f, 0.800000011920928955078125f)));
                    float2 b_1 = mul(source_1, float2x2(float2(0.2800000011920928955078125f, -0.959999978542327880859375f), float2(0.959999978542327880859375f, 0.2800000011920928955078125f)));
                    float2 c = mul(source_1, float2x2(float2(-0.60000002384185791015625f, 0.800000011920928955078125f), float2(-0.800000011920928955078125f, -0.60000002384185791015625f)));
                    float2 param_168 = a_1 / 2.400000095367431640625f.xx;
                    float2 param_169 = (b_1 / 1.14999997615814208984375f.xx) + 13.0f.xx;
                    float2 param_170 = (c / 0.550000011920928955078125f.xx) + 29.0f.xx;
                    float field = ((0.519999980926513671875f * smoothNoise(param_168)) + (0.3300000131130218505859375f * smoothNoise(param_169))) + (0.1500000059604644775390625f * smoothNoise(param_170));
                    float spread_1 = smoothstep(0.119999997317790985107421875f, 0.920000016689300537109375f, wet);
                    float level = lerp(0.680000007152557373046875f, 0.100000001490116119384765625f, spread_1);
                    float edge = lerp(0.1599999964237213134765625f, 0.23999999463558197021484375f, spread_1);
                    float patchWet = smoothstep(level, level + edge, field) * smoothstep(0.07999999821186065673828125f, 0.300000011920928955078125f, wet);
                    float fullSheet = smoothstep(0.680000007152557373046875f, 0.949999988079071044921875f, wet);
                    float soaked = max(patchWet, fullSheet * (0.7200000286102294921875f + (0.2800000011920928955078125f * smoothstep(0.25f, 0.7799999713897705078125f, field))));
                    float poolLevel = lerp(0.7200000286102294921875f, 0.4199999868869781494140625f, spread_1);
                    float pool = smoothstep(poolLevel, poolLevel + 0.1599999964237213134765625f, field) * smoothstep(0.2199999988079071044921875f, 0.550000011920928955078125f, wet);
                    float3 soakTint = lerp(float3(0.7200000286102294921875f, 0.7400000095367431640625f, 0.7799999713897705078125f), float3(0.62000000476837158203125f, 0.660000026226043701171875f, 0.730000019073486328125f), (pool * 0.75f).xxx);
                    light *= lerp(1.0f.xxx, soakTint, soaked.xxx);
                    standing = clamp((pool * 0.699999988079071044921875f) + ((soaked * fullSheet) * 0.3499999940395355224609375f), 0.0f, 0.89999997615814208984375f);
                    bool _17303 = ambient_weather.x > 0.0f;
                    bool _17311;
                    if (_17303)
                    {
                        _17311 = (pool > 0.0199999995529651641845703125f) || (soaked > 0.3499999940395355224609375f);
                    }
                    else
                    {
                        _17311 = _17303;
                    }
                    if (_17311)
                    {
                        float2 g_1 = source_1 * 3.2000000476837158203125f;
                        float2 id = floor(g_1);
                        float2 param_171 = id;
                        float2 param_172 = id + 7.099999904632568359375f.xx;
                        float2 drop = (id + 0.25f.xx) + (float2(hash12(param_171), hash12(param_172)) * 0.5f);
                        float2 param_173 = id + 3.7000000476837158203125f.xx;
                        float age = frac((ambient_weather.z * (0.85000002384185791015625f + (0.550000011920928955078125f * ambient_weather.x))) + hash12(param_173));
                        float r1 = (1.0f - smoothstep(0.0f, 0.064999997615814208984375f, abs(length(g_1 - drop) - (age * 0.439999997615814208984375f)))) * (1.0f - age);
                        float age2 = frac(age + 0.5f);
                        float r2_1 = ((1.0f - smoothstep(0.0f, 0.054999999701976776123046875f, abs(length(g_1 - drop) - (age2 * 0.4000000059604644775390625f)))) * (1.0f - age2)) * 0.5f;
                        float rippleMask = clamp((pool * 0.85000002384185791015625f) + ((soaked * fullSheet) * 0.4000000059604644775390625f), 0.0f, 1.0f);
                        light *= (1.0f + (((0.319999992847442626953125f * (r1 + r2_1)) * rippleMask) * ambient_weather.x));
                    }
                    else
                    {
                        light *= (1.0f + (((0.039999999105930328369140625f * soaked) * (1.0f - smoothstep(0.20000000298023223876953125f, 0.60000002384185791015625f, ambient_weather.w))) * (1.0f - clamp(ambient_clouds.x, 0.0f, 1.0f))));
                    }
                }
            }
        }
    }
    float mode = ambient_extent.z;
    if (mode > 14.5f)
    {
        float3 param_174 = hereSurf;
        float2 param_175 = horizN;
        float2 param_176 = nLot.xy;
        float param_177 = isVertical;
        float param_178 = onFlatFloor;
        float param_179 = onDynamicSim;
        int param_180 = storiesCount;
        float3 dbgGI = gatherRoomBounceGI(param_174, param_175, param_176, param_177, param_178, param_179, param_180);
        color = float4(clamp((dbgGI * 1.7999999523162841796875f) + ((mbOcc - occlusion.xxx) * 1.39999997615814208984375f), 0.0f.xxx, 1.0f.xxx), 1.0f);
        return;
    }
    if (mode > 13.5f)
    {
        uint _17473_dummy_parameter;
        int2 oSize = int2(spvTextureSize(voxelMap, uint(0), _17473_dummy_parameter));
        float2 lotSz_1 = max(ambient_drift.zw, 1.0f.xx);
        float gDepth = groundMap.Sample(_groundMap_sampler, pixel / ambient_extent.xy).x;
        float3 _17491;
        if (gDepth < 0.99989998340606689453125f)
        {
            float2 param_181 = p.xy;
            float param_182 = (0.62000000476837158203125f - gDepth) / 0.0030000000260770320892333984375f;
            bool param_183 = true;
            float2 param_184 = ambient_frame.xy;
            _17491 = lotPoint(param_181, param_182, param_183, param_184);
        }
        else
        {
            _17491 = here;
        }
        float3 rayBase = _17491;
        bool _17514 = frac(rayBase.x) < 0.039999999105930328369140625f;
        bool _17522;
        if (!_17514)
        {
            _17522 = frac(rayBase.y) < 0.039999999105930328369140625f;
        }
        else
        {
            _17522 = _17514;
        }
        float gridLine = _17522 ? 1.14999997615814208984375f : 1.0f;
        float3 litGround = float3(0.4600000083446502685546875f, 0.5f, 0.439999997615814208984375f) * gridLine;
        float3 shadowGround = float3(0.0599999986588954925537109375f, 0.07999999821186065673828125f, 0.14000000059604644775390625f) * gridLine;
        float3 baseCol_1 = lerp(shadowGround, litGround, clamp(lit, 0.0f, 1.0f).xxx);
        bool _17541 = oSize.x > 1;
        bool _17547;
        if (_17541)
        {
            _17547 = ambient_shadowView.w > 0.5f;
        }
        else
        {
            _17547 = _17541;
        }
        if (_17547)
        {
            uint _17553_dummy_parameter;
            float2 wSize_1 = float2(int2(spvTextureSize(worldDepthMap, uint(0), _17553_dummy_parameter)));
            float2 wp = ambient_shadowView.xy + (p.xy * ambient_shadowView.z);
            float wFront = worldDepthMap.Load(int3(clamp(int2(floor(wp)), int2(0, 0), int2(wSize_1) - int2(1, 1)), 0)).x;
            if (wFront < 0.99989998340606689453125f)
            {
                float frontKeyA = (0.62000000476837158203125f - wFront) / 0.0030000000260770320892333984375f;
                float baseKeyA = (rayBase.x + rayBase.y) + (0.800000011920928955078125f * rayBase.z);
                float sFront = (frontKeyA - baseKeyA) / 2.6400001049041748046875f;
                float sEnd = max(-0.20000000298023223876953125f, sFront - 2.400000095367431640625f);
                float3 hitCol = baseCol_1;
                bool hit = false;
                for (int i_3 = 0; i_3 <= 48; i_3++)
                {
                    float s = lerp(sFront, sEnd, float(i_3) / 48.0f);
                    float3 q_2 = rayBase + (float3(1.0f, 1.0f, 0.800000011920928955078125f) * s);
                    float3 param_185 = q_2;
                    int2 param_186 = oSize;
                    float2 param_187 = lotSz_1;
                    float2 param_188 = 0.0f.xx;
                    float param_189 = 0.0f;
                    float oOcc = dualViewHullAt(param_185, param_186, param_187, param_188, param_189);
                    if (oOcc > 0.3499999940395355224609375f)
                    {
                        float relZ = max(0.0f, q_2.z - rayBase.z);
                        float hNorm = clamp(relZ / 4.5f, 0.0f, 1.0f);
                        float3 ramp_1 = lerp(float3(0.20000000298023223876953125f, 0.7799999713897705078125f, 0.980000019073486328125f), lerp(float3(0.3499999940395355224609375f, 0.949999988079071044921875f, 0.4000000059604644775390625f), float3(1.0f, 0.550000011920928955078125f, 0.180000007152557373046875f), clamp((hNorm * 2.0f) - 1.0f, 0.0f, 1.0f).xxx), clamp(hNorm * 2.0f, 0.0f, 1.0f).xxx);
                        hitCol = ramp_1 * (0.64999997615814208984375f + (0.3499999940395355224609375f * oOcc));
                        hit = true;
                        break;
                    }
                }
                bool3 _17681 = hit.xxx;
                color = float4(float3(_17681.x ? hitCol.x : float3(0.85000002384185791015625f, 0.20000000298023223876953125f, 0.449999988079071044921875f).x, _17681.y ? hitCol.y : float3(0.85000002384185791015625f, 0.20000000298023223876953125f, 0.449999988079071044921875f).y, _17681.z ? hitCol.z : float3(0.85000002384185791015625f, 0.20000000298023223876953125f, 0.449999988079071044921875f).z), 1.0f);
            }
            else
            {
                color = float4(baseCol_1, 1.0f);
            }
        }
        else
        {
            color = float4(baseCol_1, 1.0f);
        }
        return;
    }
    if (mode > 12.5f)
    {
        float3 param_190 = here;
        float param_191 = onGround;
        float3 param_192 = here;
        color = float4(0.0f, windowSpill(param_190, param_191), lampNear(param_192), 1.0f);
        return;
    }
    if (mode > 11.5f)
    {
        color = float4(sky.xxx, 1.0f);
        return;
    }
    if (mode > 10.5f)
    {
        int2 dbgCell = int2(floor(here.xy + ambient_frame.w.xx));
        int2 param_193 = dbgCell;
        float param_194 = here.z;
        float param_195 = here.z;
        float param_196 = 0.1500000059604644775390625f;
        int dbgRow = storyRowAt(param_193, param_194, param_195, param_196);
        int2 param_197 = dbgCell;
        int param_198 = 0;
        int param_199 = dbgRow;
        int cellMask = maskCatAt(param_197, param_198, param_199);
        color = float4(window, float(cellMask & 1) * 0.60000002384185791015625f, inside * 0.5f, 1.0f);
        return;
    }
    if (mode > 9.5f)
    {
        color = float4(litColumn, lit, litShell, 1.0f);
        return;
    }
    if (mode > 8.5f)
    {
        uint _17786_dummy_parameter;
        float2 gridSize_1 = float2(int2(spvTextureSize(heightMap, uint(0), _17786_dummy_parameter)));
        float top = (0.5f - heightMap.Sample(_heightMap_sampler, ((here.xy + ambient_frame.w.xx) * ambient_frame.z) / gridSize_1).x) * 128.0f;
        color = float4(clamp(top / 6.0f, 0.0f, 1.0f), frac(top), float(top < (-16.0f)), 1.0f);
        return;
    }
    if (mode > 7.5f)
    {
        float depth = depthMap.Load(int3(int2(pixel), 0)).x;
        float ground = groundMap.Load(int3(int2(pixel), 0)).x;
        float _17837;
        if (depth < 1.0f)
        {
            _17837 = (0.62000000476837158203125f - depth) / 0.0030000000260770320892333984375f;
        }
        else
        {
            _17837 = ((0.62000000476837158203125f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w;
        }
        float key_1 = _17837;
        float2 param_200 = p.xy;
        float param_201 = key_1;
        bool param_202 = depth >= 1.0f;
        float2 param_203 = ambient_frame.xy;
        float3 lot = lotPoint(param_200, param_201, param_202, param_203);
        float2 grid = step(0.89999997615814208984375f.xx, frac(lot.xy));
        color = float4(grid, step(0.5f, frac(lot.z)), 1.0f);
        float4 _17879 = color;
        float3 param_204 = lot;
        float3 _17887 = lerp(_17879.xyz, float3(1.0f, 0.800000011920928955078125f, 0.20000000298023223876953125f), (0.60000002384185791015625f * indoors(param_204)).xxx);
        color.x = _17887.x;
        color.y = _17887.y;
        color.z = _17887.z;
        return;
    }
    if (mode > 6.5f)
    {
        color = float4(contact.xxx, 1.0f);
        return;
    }
    if (mode > 5.5f)
    {
        color = float4(clamp(lampLight + fireLight, 0.0f.xxx, 1.0f.xxx), 1.0f);
        return;
    }
    if (mode > 4.5f)
    {
        float ground_1 = groundMap.Load(int3(int2(pixel), 0)).x;
        float _17940;
        if ((centre.w < 0.25f) && (ground_1 < 1.0f))
        {
            _17940 = ((0.62000000476837158203125f - depthMap.Load(int3(int2(pixel), 0)).x) - (0.62000000476837158203125f - ground_1)) / 0.0030000000260770320892333984375f;
        }
        else
        {
            _17940 = 0.0f;
        }
        float difference = _17940;
        color = float4(clamp(0.5f + (difference / 64.0f), 0.0f, 1.0f), centre.w, float(ground_1 < 1.0f), 1.0f);
        return;
    }
    if (mode > 3.5f)
    {
        color = float4(frac(p.z / 32.0f), frac(p.z / 256.0f), centre.w, 1.0f);
        return;
    }
    if (mode > 2.5f)
    {
        color = float4((normal * 0.5f) + 0.5f.xxx, 1.0f);
        return;
    }
    if (mode > 1.5f)
    {
        color = float4(shadow.xxx, 1.0f);
        return;
    }
    if (mode > 0.5f)
    {
        color = float4((occlusion * contact).xxx, 1.0f);
        return;
    }
    float3 outHalf = clamp(light * 0.5f, 0.0f.xxx, 1.0f.xxx);
    color = float4(outHalf, 1.0f - standing);
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
