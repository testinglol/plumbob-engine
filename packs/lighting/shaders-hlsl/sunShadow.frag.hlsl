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
Texture2D<float4> indoorMap : register(t2, space2);
SamplerState _indoorMap_sampler : register(s2, space2);
Texture2D<float4> overheadMap : register(t4, space2);
SamplerState _overheadMap_sampler : register(s4, space2);
Texture2D<float4> voxelMap : register(t7, space2);
SamplerState _voxelMap_sampler : register(s7, space2);
Texture2D<float4> worldDepthMap : register(t5, space2);
SamplerState _worldDepthMap_sampler : register(s5, space2);
Texture2D<float4> worldBackDepthMap : register(t6, space2);
SamplerState _worldBackDepthMap_sampler : register(s6, space2);
Texture2D<float4> liftMap : register(t3, space2);
SamplerState _liftMap_sampler : register(s3, space2);
Texture2D<float4> simMaskMap : register(t8, space2);
SamplerState _simMaskMap_sampler : register(s8, space2);

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

int indoorBandH(int2 size)
{
    if (size.x <= 1)
    {
        return max(1, (size.y / 10));
    }
    int orient = int(ambient_clouds.z + 0.5f);
    int _483;
    if ((orient & 1) == 0)
    {
        _483 = int(ambient_drift.w + 0.5f);
    }
    else
    {
        _483 = int(ambient_drift.z + 0.5f);
    }
    int hTiles = _483;
    int margin = int(ambient_frame.w + 0.5f);
    int _504;
    if (hTiles > 0)
    {
        _504 = hTiles + (2 * margin);
    }
    else
    {
        _504 = size.x;
    }
    return _504;
}

int indoorStories()
{
    uint _522_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _522_dummy_parameter));
    int2 param = size;
    int bandH = indoorBandH(param);
    return max(1, (size.y / max(1, (5 * bandH))));
}

float3 lotPoint(float2 scene, float key, bool terrain, float2 frame)
{
    float2 local = scene - frame;
    float _254;
    if (terrain)
    {
        _254 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _254 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _254;
    float _278;
    if (terrain)
    {
        _278 = key;
    }
    else
    {
        _278 = key - (0.800000011920928955078125f * h);
    }
    float s = _278;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

float groundAt(float2 pixel)
{
    int2 ip = clamp(int2(floor(pixel)), int2(0, 0), max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0)));
    float ground = groundMap.Load(int3(ip, 0)).x;
    float _448;
    if (ground < 1.0f)
    {
        _448 = (((0.62000000476837158203125f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f;
    }
    else
    {
        _448 = -100000.0f;
    }
    return _448;
}

float terrainBaseClamped(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    bool _1059 = size.x <= 0.0f;
    bool _1066;
    if (!_1059)
    {
        _1066 = size.y <= 0.0f;
    }
    else
    {
        _1066 = _1059;
    }
    if (_1066)
    {
        return fallback;
    }
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1079;
    if (orientation == 1)
    {
        _1079 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1093;
        if (orientation == 2)
        {
            _1093 = size - _point;
        }
        else
        {
            float2 _1102;
            if (orientation == 3)
            {
                _1102 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1102 = _point;
            }
            _1093 = _1102;
        }
        _1079 = _1093;
    }
    float2 source = _1079;
    uint _1121_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1121_dummy_parameter));
    bool _1128 = mapSize.y >= (mapSize.x * 2);
    bool _1134;
    if (_1128)
    {
        _1134 = mapSize.x > 1;
    }
    else
    {
        _1134 = _1128;
    }
    int2 _1135;
    if (_1134)
    {
        _1135 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1135 = mapSize;
    }
    int2 baseSize = _1135;
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
    float2 _919;
    if (orientation == 1)
    {
        _919 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _933;
        if (orientation == 2)
        {
            _933 = size - _point;
        }
        else
        {
            float2 _942;
            if (orientation == 3)
            {
                _942 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _942 = _point;
            }
            _933 = _942;
        }
        _919 = _933;
    }
    float2 source = _919;
    bool _961 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _969;
    if (!_961)
    {
        _969 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _969 = _961;
    }
    if (_969)
    {
        return fallback;
    }
    uint _978_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _978_dummy_parameter));
    bool _985 = mapSize.y >= (mapSize.x * 2);
    bool _991;
    if (_985)
    {
        _991 = mapSize.x > 1;
    }
    else
    {
        _991 = _985;
    }
    int2 _992;
    if (_991)
    {
        _992 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _992 = mapSize;
    }
    int2 baseSize = _992;
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
    float _2788;
    if (slope > 0.100000001490116119384765625f)
    {
        _2788 = max(0.0f, (z - ground) / ((slope * 4.0f) / 3.0f));
    }
    else
    {
        _2788 = 0.0f;
    }
    return _2788;
}

int maskCatFast(int2 at, int cat, int row, int2 size, int bandH, int stories)
{
    bool _542 = (row < 0) || (row >= stories);
    bool _549;
    if (!_542)
    {
        _549 = at.x < 0;
    }
    else
    {
        _549 = _542;
    }
    bool _556;
    if (!_549)
    {
        _556 = at.y < 0;
    }
    else
    {
        _556 = _549;
    }
    bool _565;
    if (!_556)
    {
        _565 = at.x >= size.x;
    }
    else
    {
        _565 = _556;
    }
    bool _573;
    if (!_565)
    {
        _573 = at.y >= bandH;
    }
    else
    {
        _573 = _565;
    }
    if (_573)
    {
        return 0;
    }
    int band = (cat * stories) + row;
    bool _584 = band < 0;
    bool _595;
    if (!_584)
    {
        _595 = ((band + 1) * bandH) > size.y;
    }
    else
    {
        _595 = _584;
    }
    if (_595)
    {
        return 0;
    }
    return int((indoorMap.Load(int3(int2(at.x, at.y + (band * bandH)), 0)).x * 255.0f) + 0.5f);
}

int maskCatAt(int2 at, int cat, int row)
{
    uint _621_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _621_dummy_parameter));
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
    float _658;
    if (code == 0)
    {
        _658 = fallback;
    }
    else
    {
        _658 = (ambient_contact.w + (float(row) * 2.9500000476837158203125f)) + (float(code - 1) / 8.0f);
    }
    return _658;
}

float matchArchWall(float3 rawHere, float2 sceneXY, float rawKey, float nSurfX, out float3 outWallPos, out float2 outWallN)
{
    outWallPos = rawHere;
    outWallN = 0.0f.xx;
    uint _4668_dummy_parameter;
    int2 mSize = int2(spvTextureSize(indoorMap, uint(0), _4668_dummy_parameter));
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
    float _4803;
    int _4840;
    int _4847;
    int _4869;
    float _4890;
    float _4983;
    float _5003;
    float2 _5023;
    float2 _5030;
    float2 _5041;
    float2 _5057;
    float2 _5068;
    float2 _5075;
    float _5171;
    float _5348;
    float _5515;
    for (int cy = 0; cy <= 1; cy++)
    {
        for (int cx = 0; cx <= 1; cx++)
        {
            int2 cell = baseCell + int2(cx, cy);
            bool _4760 = cell.x < 0;
            bool _4767;
            if (!_4760)
            {
                _4767 = cell.y < 0;
            }
            else
            {
                _4767 = _4760;
            }
            bool _4776;
            if (!_4767)
            {
                _4776 = cell.x >= mSize.x;
            }
            else
            {
                _4776 = _4767;
            }
            bool _4784;
            if (!_4776)
            {
                _4784 = cell.y >= bandH;
            }
            else
            {
                _4784 = _4776;
            }
            if (_4784)
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
                _4803 = shifted.z;
            }
            else
            {
                _4803 = ambient_contact.w + (float(baseCode - 1) / 8.0f);
            }
            float base0 = _4803;
            int rBase = clamp(int(floor((shifted.z - base0) / 2.9500000476837158203125f)), 0, stories - 1);
            int wBits = 0;
            for (int rOff = 0; rOff <= 2; rOff++)
            {
                if (rOff == 0)
                {
                    _4840 = rBase;
                }
                else
                {
                    if (rOff == 1)
                    {
                        _4847 = rBase - 1;
                    }
                    else
                    {
                        _4847 = rBase + 1;
                    }
                    _4840 = _4847;
                }
                int r = _4840;
                if ((r < 0) || (r >= stories))
                {
                    continue;
                }
                if (r == 0)
                {
                    _4869 = baseCode;
                }
                else
                {
                    int2 param_11 = cell;
                    int param_12 = 1;
                    int param_13 = r;
                    int2 param_14 = mSize;
                    int param_15 = bandH;
                    int param_16 = stories;
                    _4869 = maskCatFast(param_11, param_12, param_13, param_14, param_15, param_16);
                }
                int rowCode = _4869;
                if (rowCode == 0)
                {
                    _4890 = base0 + (float(r) * 2.9500000476837158203125f);
                }
                else
                {
                    _4890 = (ambient_contact.w + (float(r) * 2.9500000476837158203125f)) + (float(rowCode - 1) / 8.0f);
                }
                float floorZ = _4890;
                bool _4915 = shifted.z < (floorZ - 0.1599999964237213134765625f);
                bool _4926;
                if (!_4915)
                {
                    _4926 = shifted.z > ((floorZ + 2.9500000476837158203125f) + 0.07999999821186065673828125f);
                }
                else
                {
                    _4926 = _4915;
                }
                if (_4926)
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
                bool2 _4978 = (d <= 1).xx;
                float2 wn = float2(_4978.x ? float2(1.0f, 0.0f).x : float2(0.0f, 1.0f).x, _4978.y ? float2(1.0f, 0.0f).y : float2(0.0f, 1.0f).y);
                if (d <= 1)
                {
                    _4983 = clamp(atS.y - cMin.y, 0.0f, 1.0f);
                }
                else
                {
                    _4983 = clamp(atS.x - cMin.x, 0.0f, 1.0f);
                }
                float pS = _4983;
                if (d <= 1)
                {
                    _5003 = clamp(atR.y - cMin.y, 0.0f, 1.0f);
                }
                else
                {
                    _5003 = clamp(atR.x - cMin.x, 0.0f, 1.0f);
                }
                float pR = _5003;
                if (d == 0)
                {
                    _5023 = cMin;
                }
                else
                {
                    if (d == 1)
                    {
                        _5030 = float2(cMax.x, cMin.y);
                    }
                    else
                    {
                        if (d == 2)
                        {
                            _5041 = cMin;
                        }
                        else
                        {
                            _5041 = float2(cMin.x, cMax.y);
                        }
                        _5030 = _5041;
                    }
                    _5023 = _5030;
                }
                float2 segA = _5023;
                if (d == 0)
                {
                    _5057 = float2(cMin.x, cMax.y);
                }
                else
                {
                    if (d == 1)
                    {
                        _5068 = cMax;
                    }
                    else
                    {
                        if (d == 2)
                        {
                            _5075 = float2(cMax.x, cMin.y);
                        }
                        else
                        {
                            _5075 = cMax;
                        }
                        _5068 = _5075;
                    }
                    _5057 = _5068;
                }
                float2 segB = _5057;
                float2 clS = lerp(segA, segB, pS.xx);
                float2 clR = lerp(segA, segB, pR.xx);
                float dS = length(atS - clS);
                float dR = length(atR - clR);
                bool useR = (dot(atR - clR, wn) >= (-0.0199999995529651641845703125f)) && (dR < dS);
                float dist = useR ? dR : dS;
                float w = 1.0f - smoothstep(0.07999999821186065673828125f, 0.1599999964237213134765625f, dist);
                if (w > 0.0f)
                {
                    bool2 _5139 = useR.xx;
                    float2 closest = float2(_5139.x ? clR.x : clS.x, _5139.y ? clR.y : clS.y);
                    float pSeg = useR ? pR : pS;
                    float2 segMid = (segA + segB) * 0.5f;
                    float camDelta = (segMid.x + segMid.y) - (closest.x + closest.y);
                    if ((pSeg <= 0.00200000009499490261077880859375f) || (pSeg >= 0.99800002574920654296875f))
                    {
                        _5171 = (camDelta < (-0.20000000298023223876953125f)) ? 0.449999988079071044921875f : 0.14000000059604644775390625f;
                    }
                    else
                    {
                        _5171 = 0.0f;
                    }
                    float endPen = _5171;
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
                    bool2 _5318 = useR_1.xx;
                    float2 closest_1 = float2(_5318.x ? clR_1.x : clS_1.x, _5318.y ? clR_1.y : clS_1.y);
                    float pSeg_1 = useR_1 ? pR_1 : pS_1;
                    float2 segMid_1 = (segA_1 + segB_1) * 0.5f;
                    float camDelta_1 = (segMid_1.x + segMid_1.y) - (closest_1.x + closest_1.y);
                    if ((pSeg_1 <= 0.00200000009499490261077880859375f) || (pSeg_1 >= 0.99800002574920654296875f))
                    {
                        _5348 = (camDelta_1 < (-0.20000000298023223876953125f)) ? 0.449999988079071044921875f : 0.14000000059604644775390625f;
                    }
                    else
                    {
                        _5348 = 0.0f;
                    }
                    float endPen_1 = _5348;
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
                    bool2 _5486 = useR_2.xx;
                    float2 closest_2 = float2(_5486.x ? clR_2.x : clS_2.x, _5486.y ? clR_2.y : clS_2.y);
                    float pSeg_2 = useR_2 ? pR_2 : pS_2;
                    float2 segMid_2 = cMin + 0.5f.xx;
                    float camDelta_2 = (segMid_2.x + segMid_2.y) - (closest_2.x + closest_2.y);
                    if ((pSeg_2 <= 0.00200000009499490261077880859375f) || (pSeg_2 >= 0.99800002574920654296875f))
                    {
                        _5515 = (camDelta_2 < (-0.20000000298023223876953125f)) ? 0.449999988079071044921875f : 0.14000000059604644775390625f;
                    }
                    else
                    {
                        _5515 = 0.0f;
                    }
                    float endPen_2 = _5515;
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

int voxelAoRows(int2 oSize)
{
    int aoSize = max(1, (oSize.x / 4));
    return max(1, (((oSize.y - oSize.x) - 256) / (512 + aoSize)));
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
    bool _4533 = any(bool2(op0.x < 0.0f.xx.x, op0.y < 0.0f.xx.y));
    bool _4543;
    if (!_4533)
    {
        _4543 = op0.x >= float(oSize.x);
    }
    else
    {
        _4543 = _4533;
    }
    bool _4552;
    if (!_4543)
    {
        _4552 = op0.y >= float(halfH);
    }
    else
    {
        _4552 = _4543;
    }
    if (_4552)
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
    bool _4616 = any(bool2(op1.x < 0.0f.xx.x, op1.y < 0.0f.xx.y));
    bool _4626;
    if (!_4616)
    {
        _4626 = op1.x >= float(oSize.x);
    }
    else
    {
        _4626 = _4616;
    }
    bool _4635;
    if (!_4626)
    {
        _4635 = op1.y >= float(halfH);
    }
    else
    {
        _4635 = _4626;
    }
    if (_4635)
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
    uint _682_dummy_parameter;
    int2 mSize = int2(spvTextureSize(indoorMap, uint(0), _682_dummy_parameter));
    int2 param = mSize;
    int bandH = indoorBandH(param);
    int stories = max(1, (mSize.y / max(1, (5 * bandH))));
    float2 cell = (lot.xy + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.20000000298023223876953125f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _735;
    float _748;
    float2 _860;
    float2 _868;
    for (int i = 0; i < 4; i++)
    {
        if ((i & 1) == 1)
        {
            _735 = f.x;
        }
        else
        {
            _735 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _748 = f.y;
        }
        else
        {
            _748 = 1.0f - f.y;
        }
        float weight = _735 * _748;
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
            _860 = float2(1.0f, -1.0f);
        }
        else
        {
            if (part == 2)
            {
                _868 = float2(-1.0f, 1.0f);
            }
            else
            {
                bool2 _878 = (part == 3).xx;
                _868 = float2(_878.x ? (-1.0f).xx.x : 1.0f.xx.x, _878.y ? (-1.0f).xx.y : 1.0f.xx.y);
            }
            _860 = _868;
        }
        float2 toward = _860;
        sum += (weight * smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((lot.xy + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward)));
    }
    return sum;
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
    float2 _2835;
    if (part == 1)
    {
        _2835 = float2(1.0f, -1.0f);
    }
    else
    {
        float2 _2841;
        if (part == 2)
        {
            _2841 = float2(-1.0f, 1.0f);
        }
        else
        {
            bool2 _2847 = (part == 3).xx;
            _2841 = float2(_2847.x ? (-1.0f).xx.x : 1.0f.xx.x, _2847.y ? (-1.0f).xx.y : 1.0f.xx.y);
        }
        _2835 = _2841;
    }
    float2 toward = _2835;
    return (dot(localU - 0.5f.xx, toward) >= 0.0f) ? room : 0;
}

float2 wallRay(float3 here, float onFlatFloor, float2 horizN)
{
    float3 sun = ambient_sunLot.xyz;
    float across = length(sun.xy);
    if (across < 0.001000000047497451305389404296875f)
    {
        return float2(1.0f, 0.0f);
    }
    uint _2878_dummy_parameter;
    int2 maskTexSize = int2(spvTextureSize(indoorMap, uint(0), _2878_dummy_parameter));
    int2 param = maskTexSize;
    int maskBandH = indoorBandH(param);
    int stories = max(1, (maskTexSize.y / max(1, (5 * maskBandH))));
    float2 direction = sun.xy / across.xx;
    float rise = sun.z / across;
    float2 start = (here.xy + ambient_frame.w.xx) + (horizN * (0.0599999986588954925537109375f * (1.0f - onFlatFloor)));
    float startZ = here.z;
    float topGuard = lerp(0.0f, 0.119999997317790985107421875f, onFlatFloor);
    int2 cell = int2(floor(start));
    int2 stepDir = int2(sign(direction));
    float2 safeDir = direction + (float2(bool2(direction.x == 0.0f.xx.x, direction.y == 0.0f.xx.y)) * 9.9999997473787516355514526367188e-06f);
    float2 delta = abs(1.0f.xx / safeDir);
    float2 next = ((float2(cell) + max(float2(stepDir), 0.0f.xx)) - start) / safeDir;
    float maxReachH = (ambient_sunLot.w * across) + 0.25f;
    float maxDist = min(maxReachH, ((float(stories) * 2.9500000476837158203125f) + 1.5f) / max(rise, 0.119999997317790985107421875f));
    float vis = 1.0f;
    float winHit = 0.0f;
    float tPrev = 0.0f;
    float _3045;
    float _3202;
    float _3226;
    int2 _3780;
    float _3813;
    float2 _3862;
    int _3903;
    int _3910;
    int _3932;
    int _3947;
    int _3992;
    int _4008;
    int _4052;
    int _4068;
    int _4217;
    int _4232;
    float _4293;
    for (int i = 0; i < 64; i++)
    {
        bool _2985 = cell.x < 0;
        bool _2991;
        if (_2985)
        {
            _2991 = stepDir.x <= 0;
        }
        else
        {
            _2991 = _2985;
        }
        bool _3006;
        if (!_2991)
        {
            bool _2999 = cell.x >= maskTexSize.x;
            bool _3005;
            if (_2999)
            {
                _3005 = stepDir.x >= 0;
            }
            else
            {
                _3005 = _2999;
            }
            _3006 = _3005;
        }
        else
        {
            _3006 = _2991;
        }
        bool _3019;
        if (!_3006)
        {
            bool _3012 = cell.y < 0;
            bool _3018;
            if (_3012)
            {
                _3018 = stepDir.y <= 0;
            }
            else
            {
                _3018 = _3012;
            }
            _3019 = _3018;
        }
        else
        {
            _3019 = _3006;
        }
        bool _3033;
        if (!_3019)
        {
            bool _3026 = cell.y >= maskBandH;
            bool _3032;
            if (_3026)
            {
                _3032 = stepDir.y >= 0;
            }
            else
            {
                _3032 = _3026;
            }
            _3033 = _3032;
        }
        else
        {
            _3033 = _3019;
        }
        if (_3033)
        {
            break;
        }
        bool alongX = next.x < next.y;
        if (alongX)
        {
            _3045 = next.x;
        }
        else
        {
            _3045 = next.y;
        }
        float t = _3045;
        float segEnd = min(t, maxDist);
        int2 param_1 = cell;
        int param_2 = 1;
        int param_3 = 0;
        int2 param_4 = maskTexSize;
        int param_5 = maskBandH;
        int param_6 = stories;
        int cellCode0 = maskCatFast(param_1, param_2, param_3, param_4, param_5, param_6);
        if ((segEnd > tPrev) && (cellCode0 != 0))
        {
            float cellBase0 = ambient_contact.w + (float(cellCode0 - 1) / 8.0f);
            float zMid = startZ + ((0.5f * (tPrev + segEnd)) * rise);
            int midRow = clamp(int(floor(((zMid - cellBase0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f)), 0, stories - 1);
            int lowR = max(0, (midRow - 1));
            int highR = min((stories - 1), (midRow + 1));
            int firstPart = 0;
            int secondPart = 0;
            for (int r = lowR; r <= highR; r++)
            {
                int2 param_7 = cell;
                int param_8 = 0;
                int param_9 = r;
                int2 param_10 = maskTexSize;
                int param_11 = maskBandH;
                int param_12 = stories;
                if (maskCatFast(param_7, param_8, param_9, param_10, param_11, param_12) < 2)
                {
                    continue;
                }
                int2 param_13 = cell;
                int param_14 = 2;
                int param_15 = r;
                int2 param_16 = maskTexSize;
                int param_17 = maskBandH;
                int param_18 = stories;
                int p = maskCatFast(param_13, param_14, param_15, param_16, param_17, param_18) & 7;
                if (p == 0)
                {
                    continue;
                }
                if (firstPart == 0)
                {
                    firstPart = p;
                }
                else
                {
                    if ((p != firstPart) && (secondPart == 0))
                    {
                        secondPart = p;
                    }
                }
            }
            for (int _pass = 0; _pass < 2; _pass++)
            {
                int part = (_pass == 0) ? firstPart : secondPart;
                if (part == 0)
                {
                    continue;
                }
                if (part <= 2)
                {
                    _3202 = direction.x - direction.y;
                }
                else
                {
                    _3202 = direction.x + direction.y;
                }
                float denom = _3202;
                if (abs(denom) <= 9.9999997473787516355514526367188e-05f)
                {
                    continue;
                }
                if (part <= 2)
                {
                    _3226 = ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom;
                }
                else
                {
                    _3226 = ((1.0f - (start.x - float(cell.x))) - (start.y - float(cell.y))) / denom;
                }
                float tDiag = _3226;
                bool _3265 = tDiag <= (tPrev + 9.9999997473787516355514526367188e-05f);
                bool _3273;
                if (!_3265)
                {
                    _3273 = tDiag > (t + 9.9999997473787516355514526367188e-05f);
                }
                else
                {
                    _3273 = _3265;
                }
                if (_3273 || (tDiag > maxDist))
                {
                    continue;
                }
                float2 uDiag = (start + (direction * tDiag)) - float2(cell);
                bool _3294 = any(bool2(uDiag.x < (-0.00999999977648258209228515625f).xx.x, uDiag.y < (-0.00999999977648258209228515625f).xx.y));
                bool _3303;
                if (!_3294)
                {
                    _3303 = any(bool2(uDiag.x > 1.0099999904632568359375f.xx.x, uDiag.y > 1.0099999904632568359375f.xx.y));
                }
                else
                {
                    _3303 = _3294;
                }
                if (_3303)
                {
                    continue;
                }
                float zDiag = startZ + (tDiag * rise);
                int dRow = clamp(int(floor(((zDiag - cellBase0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f)), 0, stories - 1);
                int hitRow = -1;
                int2 param_19 = cell;
                int param_20 = 0;
                int param_21 = dRow;
                int2 param_22 = maskTexSize;
                int param_23 = maskBandH;
                int param_24 = stories;
                bool _3337 = maskCatFast(param_19, param_20, param_21, param_22, param_23, param_24) >= 2;
                bool _3355;
                if (_3337)
                {
                    int2 param_25 = cell;
                    int param_26 = 2;
                    int param_27 = dRow;
                    int2 param_28 = maskTexSize;
                    int param_29 = maskBandH;
                    int param_30 = stories;
                    _3355 = (maskCatFast(param_25, param_26, param_27, param_28, param_29, param_30) & 7) == part;
                }
                else
                {
                    _3355 = _3337;
                }
                if (_3355)
                {
                    hitRow = dRow;
                }
                else
                {
                    bool _3361 = dRow > 0;
                    bool _3378;
                    if (_3361)
                    {
                        int2 param_31 = cell;
                        int param_32 = 0;
                        int param_33 = dRow - 1;
                        int2 param_34 = maskTexSize;
                        int param_35 = maskBandH;
                        int param_36 = stories;
                        _3378 = maskCatFast(param_31, param_32, param_33, param_34, param_35, param_36) >= 2;
                    }
                    else
                    {
                        _3378 = _3361;
                    }
                    bool _3397;
                    if (_3378)
                    {
                        int2 param_37 = cell;
                        int param_38 = 2;
                        int param_39 = dRow - 1;
                        int2 param_40 = maskTexSize;
                        int param_41 = maskBandH;
                        int param_42 = stories;
                        _3397 = (maskCatFast(param_37, param_38, param_39, param_40, param_41, param_42) & 7) == part;
                    }
                    else
                    {
                        _3397 = _3378;
                    }
                    if (_3397)
                    {
                        hitRow = dRow - 1;
                    }
                    else
                    {
                        bool _3406 = (dRow + 1) < stories;
                        bool _3423;
                        if (_3406)
                        {
                            int2 param_43 = cell;
                            int param_44 = 0;
                            int param_45 = dRow + 1;
                            int2 param_46 = maskTexSize;
                            int param_47 = maskBandH;
                            int param_48 = stories;
                            _3423 = maskCatFast(param_43, param_44, param_45, param_46, param_47, param_48) >= 2;
                        }
                        else
                        {
                            _3423 = _3406;
                        }
                        bool _3442;
                        if (_3423)
                        {
                            int2 param_49 = cell;
                            int param_50 = 2;
                            int param_51 = dRow + 1;
                            int2 param_52 = maskTexSize;
                            int param_53 = maskBandH;
                            int param_54 = stories;
                            _3442 = (maskCatFast(param_49, param_50, param_51, param_52, param_53, param_54) & 7) == part;
                        }
                        else
                        {
                            _3442 = _3423;
                        }
                        if (_3442)
                        {
                            hitRow = dRow + 1;
                        }
                    }
                }
                if (hitRow < 0)
                {
                    continue;
                }
                int botRow = hitRow;
                for (;;)
                {
                    bool _3460 = botRow > 0;
                    bool _3477;
                    if (_3460)
                    {
                        int2 param_55 = cell;
                        int param_56 = 0;
                        int param_57 = botRow - 1;
                        int2 param_58 = maskTexSize;
                        int param_59 = maskBandH;
                        int param_60 = stories;
                        _3477 = maskCatFast(param_55, param_56, param_57, param_58, param_59, param_60) >= 2;
                    }
                    else
                    {
                        _3477 = _3460;
                    }
                    bool _3496;
                    if (_3477)
                    {
                        int2 param_61 = cell;
                        int param_62 = 2;
                        int param_63 = botRow - 1;
                        int2 param_64 = maskTexSize;
                        int param_65 = maskBandH;
                        int param_66 = stories;
                        _3496 = (maskCatFast(param_61, param_62, param_63, param_64, param_65, param_66) & 7) == part;
                    }
                    else
                    {
                        _3496 = _3477;
                    }
                    if (_3496)
                    {
                        botRow--;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                int topRow = hitRow;
                for (;;)
                {
                    bool _3509 = (topRow + 1) < stories;
                    bool _3526;
                    if (_3509)
                    {
                        int2 param_67 = cell;
                        int param_68 = 0;
                        int param_69 = topRow + 1;
                        int2 param_70 = maskTexSize;
                        int param_71 = maskBandH;
                        int param_72 = stories;
                        _3526 = maskCatFast(param_67, param_68, param_69, param_70, param_71, param_72) >= 2;
                    }
                    else
                    {
                        _3526 = _3509;
                    }
                    bool _3545;
                    if (_3526)
                    {
                        int2 param_73 = cell;
                        int param_74 = 2;
                        int param_75 = topRow + 1;
                        int2 param_76 = maskTexSize;
                        int param_77 = maskBandH;
                        int param_78 = stories;
                        _3545 = (maskCatFast(param_73, param_74, param_75, param_76, param_77, param_78) & 7) == part;
                    }
                    else
                    {
                        _3545 = _3526;
                    }
                    if (_3545)
                    {
                        topRow++;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                int2 param_79 = cell;
                int param_80 = botRow;
                float param_81 = cellBase0 + (float(botRow) * 2.9500000476837158203125f);
                float wallBot = floorAt(param_79, param_80, param_81);
                int2 param_82 = cell;
                int param_83 = topRow;
                float param_84 = cellBase0 + (float(topRow) * 2.9500000476837158203125f);
                float wallTop = floorAt(param_82, param_83, param_84) + 2.9500000476837158203125f;
                float topClearD = 1.0f - smoothstep(wallTop - max(topGuard, 0.1599999964237213134765625f), wallTop - 0.02999999932944774627685546875f, here.z);
                if (topClearD > 0.001000000047497451305389404296875f)
                {
                    float pen = min((0.04500000178813934326171875f * tDiag) + 0.0350000001490116119384765625f, 0.5f);
                    float wallV = (topClearD * smoothstep(wallBot - 0.039999999105930328369140625f, wallBot + 0.039999999105930328369140625f, zDiag)) * (1.0f - smoothstep(wallTop - (0.25f * pen), wallTop + (0.75f * pen), zDiag));
                    float winOpen = 0.0f;
                    int winRow = clamp(int(floor(((zDiag - cellBase0) + 0.00999999977648258209228515625f) / 2.9500000476837158203125f)), botRow, topRow);
                    int2 param_85 = cell;
                    int param_86 = 0;
                    int param_87 = winRow;
                    int2 param_88 = maskTexSize;
                    int param_89 = maskBandH;
                    int param_90 = stories;
                    int winMask = maskCatFast(param_85, param_86, param_87, param_88, param_89, param_90);
                    bool _3647 = winMask >= 2;
                    bool _3665;
                    if (_3647)
                    {
                        int2 param_91 = cell;
                        int param_92 = 2;
                        int param_93 = winRow;
                        int2 param_94 = maskTexSize;
                        int param_95 = maskBandH;
                        int param_96 = stories;
                        _3665 = (maskCatFast(param_91, param_92, param_93, param_94, param_95, param_96) & 7) == part;
                    }
                    else
                    {
                        _3665 = _3647;
                    }
                    bool _3671;
                    if (_3665)
                    {
                        _3671 = (winMask & 1) != 0;
                    }
                    else
                    {
                        _3671 = _3665;
                    }
                    if (_3671)
                    {
                        int2 param_97 = cell;
                        int param_98 = winRow;
                        float param_99 = cellBase0 + (float(winRow) * 2.9500000476837158203125f);
                        float winFloor = floorAt(param_97, param_98, param_99);
                        float relH = zDiag - winFloor;
                        float along = uDiag.x;
                        float wPen = (0.039999999105930328369140625f * tDiag) + 0.039999999105930328369140625f;
                        winOpen = ((smoothstep(0.75f - wPen, 0.75f + wPen, relH) * (1.0f - smoothstep(2.349999904632568359375f - wPen, 2.349999904632568359375f + wPen, relH))) * smoothstep(0.14000000059604644775390625f - wPen, 0.14000000059604644775390625f + wPen, along)) * smoothstep(0.14000000059604644775390625f - wPen, 0.14000000059604644775390625f + wPen, 1.0f - along);
                    }
                    float distFade = 1.0f - smoothstep(maxReachH * 0.86000001430511474609375f, maxReachH, tDiag);
                    float occ = (wallV * (1.0f - winOpen)) * distFade;
                    vis = min(vis, 1.0f - occ);
                    winHit = max(winHit, (winOpen * wallV) * distFade);
                    if (vis <= 0.00999999977648258209228515625f)
                    {
                        break;
                    }
                }
            }
            if (vis <= 0.00999999977648258209228515625f)
            {
                break;
            }
        }
        if (t > maxDist)
        {
            break;
        }
        float zCross = startZ + (t * rise);
        if (alongX)
        {
            _3780 = int2(stepDir.x, 0);
        }
        else
        {
            _3780 = int2(0, stepDir.y);
        }
        int2 to = cell + _3780;
        int2 param_100 = to;
        int param_101 = 1;
        int param_102 = 0;
        int2 param_103 = maskTexSize;
        int param_104 = maskBandH;
        int param_105 = stories;
        int toCode0 = maskCatFast(param_100, param_101, param_102, param_103, param_104, param_105);
        if ((cellCode0 | toCode0) != 0)
        {
            if (cellCode0 != 0)
            {
                _3813 = ambient_contact.w + (float(cellCode0 - 1) / 8.0f);
            }
            else
            {
                _3813 = ambient_contact.w + (float(toCode0 - 1) / 8.0f);
            }
            float base0 = _3813;
            if (zCross > ((base0 + (float(stories) * 2.9500000476837158203125f)) + 0.25f))
            {
                break;
            }
            int wRow = clamp(int(floor(((zCross - base0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f)), 0, stories - 1);
            float2 crossing = start + (direction * t);
            if (alongX)
            {
                _3862 = float2(float(stepDir.x), 0.0f);
            }
            else
            {
                _3862 = float2(0.0f, float(stepDir.y));
            }
            float2 edgeStep = _3862;
            float2 localA = (crossing - float2(cell)) - (edgeStep * 0.00999999977648258209228515625f);
            float2 localB = (crossing - float2(to)) + (edgeStep * 0.00999999977648258209228515625f);
            int hitRow_1 = -1;
            for (int off = 0; off <= 2; off++)
            {
                if (off == 0)
                {
                    _3903 = wRow;
                }
                else
                {
                    if (off == 1)
                    {
                        _3910 = wRow - 1;
                    }
                    else
                    {
                        _3910 = wRow + 1;
                    }
                    _3903 = _3910;
                }
                int r_1 = _3903;
                if ((r_1 < 0) || (r_1 >= stories))
                {
                    continue;
                }
                if (cellCode0 != 0)
                {
                    int2 param_106 = cell;
                    int param_107 = r_1;
                    float2 param_108 = localA;
                    _3932 = effectiveRoomAt(param_106, param_107, param_108);
                }
                else
                {
                    _3932 = 0;
                }
                int rA = _3932;
                if (toCode0 != 0)
                {
                    int2 param_109 = to;
                    int param_110 = r_1;
                    float2 param_111 = localB;
                    _3947 = effectiveRoomAt(param_109, param_110, param_111);
                }
                else
                {
                    _3947 = 0;
                }
                int rB = _3947;
                bool _3961 = rA != rB;
                bool _3969;
                if (_3961)
                {
                    _3969 = (rA > 0) || (rB > 0);
                }
                else
                {
                    _3969 = _3961;
                }
                if (_3969)
                {
                    hitRow_1 = r_1;
                    break;
                }
            }
            if (hitRow_1 >= 0)
            {
                int botRow_1 = hitRow_1;
                while (botRow_1 > 0)
                {
                    if (cellCode0 != 0)
                    {
                        int2 param_112 = cell;
                        int param_113 = botRow_1 - 1;
                        float2 param_114 = localA;
                        _3992 = effectiveRoomAt(param_112, param_113, param_114);
                    }
                    else
                    {
                        _3992 = 0;
                    }
                    int rA_1 = _3992;
                    if (toCode0 != 0)
                    {
                        int2 param_115 = to;
                        int param_116 = botRow_1 - 1;
                        float2 param_117 = localB;
                        _4008 = effectiveRoomAt(param_115, param_116, param_117);
                    }
                    else
                    {
                        _4008 = 0;
                    }
                    int rB_1 = _4008;
                    bool _4023 = rA_1 == rB_1;
                    bool _4032;
                    if (!_4023)
                    {
                        _4032 = (rA_1 == 0) && (rB_1 == 0);
                    }
                    else
                    {
                        _4032 = _4023;
                    }
                    if (_4032)
                    {
                        break;
                    }
                    botRow_1--;
                }
                int topRow_1 = hitRow_1;
                while ((topRow_1 + 1) < stories)
                {
                    if (cellCode0 != 0)
                    {
                        int2 param_118 = cell;
                        int param_119 = topRow_1 + 1;
                        float2 param_120 = localA;
                        _4052 = effectiveRoomAt(param_118, param_119, param_120);
                    }
                    else
                    {
                        _4052 = 0;
                    }
                    int rA_2 = _4052;
                    if (toCode0 != 0)
                    {
                        int2 param_121 = to;
                        int param_122 = topRow_1 + 1;
                        float2 param_123 = localB;
                        _4068 = effectiveRoomAt(param_121, param_122, param_123);
                    }
                    else
                    {
                        _4068 = 0;
                    }
                    int rB_2 = _4068;
                    bool _4083 = rA_2 == rB_2;
                    bool _4092;
                    if (!_4083)
                    {
                        _4092 = (rA_2 == 0) && (rB_2 == 0);
                    }
                    else
                    {
                        _4092 = _4083;
                    }
                    if (_4092)
                    {
                        break;
                    }
                    topRow_1++;
                }
                int2 param_124 = to;
                int param_125 = botRow_1;
                float param_126 = base0 + (float(botRow_1) * 2.9500000476837158203125f);
                int2 param_127 = cell;
                int param_128 = botRow_1;
                float param_129 = floorAt(param_124, param_125, param_126);
                float wallBot_1 = floorAt(param_127, param_128, param_129);
                int2 param_130 = to;
                int param_131 = topRow_1;
                float param_132 = base0 + (float(topRow_1) * 2.9500000476837158203125f);
                int2 param_133 = cell;
                int param_134 = topRow_1;
                float param_135 = floorAt(param_130, param_131, param_132);
                float wallTop_1 = floorAt(param_133, param_134, param_135) + 2.9500000476837158203125f;
                float topClearO = 1.0f - smoothstep(wallTop_1 - max(topGuard, 0.1599999964237213134765625f), wallTop_1 - 0.02999999932944774627685546875f, here.z);
                if (topClearO > 0.001000000047497451305389404296875f)
                {
                    float pen_1 = min((0.04500000178813934326171875f * t) + 0.0350000001490116119384765625f, 0.5f);
                    float wallV_1 = (topClearO * smoothstep(wallBot_1 - 0.039999999105930328369140625f, wallBot_1 + 0.039999999105930328369140625f, zCross)) * (1.0f - smoothstep(wallTop_1 - (0.25f * pen_1), wallTop_1 + (0.75f * pen_1), zCross));
                    float winOpen_1 = 0.0f;
                    int winRow_1 = clamp(int(floor(((zCross - base0) + 0.00999999977648258209228515625f) / 2.9500000476837158203125f)), botRow_1, topRow_1);
                    int2 param_136 = cell;
                    int param_137 = 0;
                    int param_138 = winRow_1;
                    int2 param_139 = maskTexSize;
                    int param_140 = maskBandH;
                    int param_141 = stories;
                    int cM = maskCatFast(param_136, param_137, param_138, param_139, param_140, param_141);
                    int2 param_142 = to;
                    int param_143 = 0;
                    int param_144 = winRow_1;
                    int2 param_145 = maskTexSize;
                    int param_146 = maskBandH;
                    int param_147 = stories;
                    int nM = maskCatFast(param_142, param_143, param_144, param_145, param_146, param_147);
                    if (cellCode0 != 0)
                    {
                        int2 param_148 = cell;
                        int param_149 = winRow_1;
                        float2 param_150 = localA;
                        _4217 = effectiveRoomAt(param_148, param_149, param_150);
                    }
                    else
                    {
                        _4217 = 0;
                    }
                    int wRA = _4217;
                    if (toCode0 != 0)
                    {
                        int2 param_151 = to;
                        int param_152 = winRow_1;
                        float2 param_153 = localB;
                        _4232 = effectiveRoomAt(param_151, param_152, param_153);
                    }
                    else
                    {
                        _4232 = 0;
                    }
                    int wRB = _4232;
                    bool _4246 = wRA != wRB;
                    bool _4254;
                    if (_4246)
                    {
                        _4254 = (wRA > 0) || (wRB > 0);
                    }
                    else
                    {
                        _4254 = _4246;
                    }
                    bool _4260;
                    if (_4254)
                    {
                        _4260 = (cM & 1) != 0;
                    }
                    else
                    {
                        _4260 = _4254;
                    }
                    bool _4266;
                    if (_4260)
                    {
                        _4266 = (nM & 1) != 0;
                    }
                    else
                    {
                        _4266 = _4260;
                    }
                    if (_4266)
                    {
                        int2 param_154 = to;
                        int param_155 = winRow_1;
                        float param_156 = base0 + (float(winRow_1) * 2.9500000476837158203125f);
                        int2 param_157 = cell;
                        int param_158 = winRow_1;
                        float param_159 = floorAt(param_154, param_155, param_156);
                        float winFloor_1 = floorAt(param_157, param_158, param_159);
                        float relH_1 = zCross - winFloor_1;
                        if (alongX)
                        {
                            _4293 = crossing.y;
                        }
                        else
                        {
                            _4293 = crossing.x;
                        }
                        float along_1 = frac(_4293);
                        float wPen_1 = (0.039999999105930328369140625f * t) + 0.039999999105930328369140625f;
                        winOpen_1 = ((smoothstep(0.75f - wPen_1, 0.75f + wPen_1, relH_1) * (1.0f - smoothstep(2.349999904632568359375f - wPen_1, 2.349999904632568359375f + wPen_1, relH_1))) * smoothstep(0.100000001490116119384765625f - wPen_1, 0.100000001490116119384765625f + wPen_1, along_1)) * smoothstep(0.100000001490116119384765625f - wPen_1, 0.100000001490116119384765625f + wPen_1, 1.0f - along_1);
                    }
                    float distFade_1 = 1.0f - smoothstep(maxReachH * 0.86000001430511474609375f, maxReachH, t);
                    float occ_1 = (wallV_1 * (1.0f - winOpen_1)) * distFade_1;
                    vis = min(vis, 1.0f - occ_1);
                    winHit = max(winHit, (winOpen_1 * wallV_1) * distFade_1);
                    if (vis <= 0.00999999977648258209228515625f)
                    {
                        break;
                    }
                }
            }
        }
        cell = to;
        tPrev = t;
        if (alongX)
        {
            next.x += delta.x;
        }
        else
        {
            next.y += delta.y;
        }
    }
    return float2(vis, winHit * vis);
}

void clipAxisSlab(float orig, float dir, float lo, float hi, inout float tEnter, inout float tExit)
{
    if (abs(dir) < 9.9999999747524270787835121154785e-07f)
    {
        if ((orig < lo) || (orig > hi))
        {
            tEnter = 1000000.0f;
            tExit = -1000000.0f;
        }
        return;
    }
    float invD = 1.0f / dir;
    float a = (lo - orig) * invD;
    float b = (hi - orig) * invD;
    tEnter = max(tEnter, min(a, b));
    tExit = min(tExit, max(a, b));
}

float2 sceneOf(float3 q)
{
    return float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
}

float rayStepOf(float relT, float dtBase, float sCap, float relTCap)
{
    if (relT <= 0.0f)
    {
        return 0.0f;
    }
    float _7242;
    if (relT <= relTCap)
    {
        _7242 = log(1.0f + ((0.02199999988079071044921875f * relT) / dtBase)) / 0.02199999988079071044921875f;
    }
    else
    {
        _7242 = sCap + ((relT - relTCap) / 0.36000001430511474609375f);
    }
    return _7242;
}

float rayRelT(float s, float dtBase, float sCap, float relTCap)
{
    float _7212;
    if (s <= sCap)
    {
        _7212 = (dtBase / 0.02199999988079071044921875f) * (exp(0.02199999988079071044921875f * s) - 1.0f);
    }
    else
    {
        _7212 = relTCap + (0.36000001430511474609375f * (s - sCap));
    }
    return _7212;
}

float canopyBlockedTexel(int4 data, int slabMask16, bool hasBand1, float canopyClearZ, float qPrevZ, float qZ, float pen, float smoothRoofTop)
{
    bool _1206 = data.w == 0;
    bool _1214;
    if (!_1206)
    {
        _1214 = data.w == 255;
    }
    else
    {
        _1214 = _1206;
    }
    if (_1214)
    {
        return 0.0f;
    }
    bool hasCeil1 = (data.x & 32) != 0;
    bool hasAnyUpper = (data.x & 64) != 0;
    bool _1234 = (!hasCeil1) && (!hasAnyUpper);
    bool _1240;
    if (_1234)
    {
        _1240 = data.w <= 1;
    }
    else
    {
        _1240 = _1234;
    }
    if (_1240)
    {
        return 0.0f;
    }
    float qBase = float(((data.y * 256) + data.z) - 32768) / 256.0f;
    float prevRel = qPrevZ - qBase;
    float curRel = qZ - qBase;
    float topScale = hasBand1 ? 4.0f : 8.0f;
    float _1270;
    if (data.w >= 2)
    {
        float _1275;
        if (smoothRoofTop >= 0.0f)
        {
            _1275 = smoothRoofTop;
        }
        else
        {
            _1275 = float(data.w - 2) / topScale;
        }
        _1270 = _1275;
    }
    else
    {
        _1270 = -1.0f;
    }
    float canopyTop = _1270;
    float botPen = min(pen, 0.14000000059604644775390625f);
    float topPen = min(pen, 0.62000000476837158203125f);
    if (prevRel > ((max(canopyTop, 2.9500000476837158203125f) + 0.3499999940395355224609375f) + (0.64999997615814208984375f * topPen)))
    {
        return 0.0f;
    }
    float occ = 0.0f;
    float clear1 = 1.0f - smoothstep(2.730000019073486328125f, 2.8900001049041748046875f, canopyClearZ);
    if (hasCeil1 && (clear1 > 0.001000000047497451305389404296875f))
    {
        float top1 = max(canopyTop, 3.13000011444091796875f);
        occ = max(occ, (clear1 * smoothstep(2.849999904632568359375f - botPen, 2.849999904632568359375f + botPen, curRel)) * (1.0f - smoothstep(top1 - (0.3499999940395355224609375f * topPen), top1 + (0.64999997615814208984375f * topPen), prevRel)));
    }
    int topUpperStory = 1;
    int upperBits = slabMask16 & 65534;
    if (hasBand1 && (upperBits != 0))
    {
        int _1365;
        if ((upperBits & 65280) != 0)
        {
            _1365 = 16;
        }
        else
        {
            _1365 = ((upperBits & 240) != 0) ? 8 : 4;
        }
        int maxK = _1365;
        for (int k = 2; k <= maxK; k++)
        {
            if ((upperBits & (1 << (k - 1))) == 0)
            {
                continue;
            }
            topUpperStory = k;
            float slabH = float(k) * 2.9500000476837158203125f;
            float clearK = 1.0f - smoothstep(slabH - 0.2199999988079071044921875f, slabH - 0.0599999986588954925537109375f, canopyClearZ);
            if (clearK > 0.001000000047497451305389404296875f)
            {
                float prevH = float(k - 1) * 2.9500000476837158203125f;
                float botK = lerp(prevH - 0.100000001490116119384765625f, slabH - 0.100000001490116119384765625f, smoothstep(prevH - 0.2199999988079071044921875f, prevH - 0.0599999986588954925537109375f, canopyClearZ));
                float topK = max(canopyTop, slabH + 0.180000007152557373046875f);
                occ = max(occ, (clearK * smoothstep(botK - botPen, botK + botPen, curRel)) * (1.0f - smoothstep(topK - (0.3499999940395355224609375f * topPen), topK + (0.64999997615814208984375f * topPen), prevRel)));
            }
        }
    }
    else
    {
        if ((!hasBand1) && hasAnyUpper)
        {
            topUpperStory = 2;
            for (int k_1 = 3; k_1 <= 5; k_1++)
            {
                if ((data.x & (1 << (k_1 - 1))) != 0)
                {
                    topUpperStory = k_1;
                }
            }
            for (int k_2 = 2; k_2 <= topUpperStory; k_2++)
            {
                bool _1498 = k_2 > 2;
                bool _1508;
                if (_1498)
                {
                    _1508 = (data.x & (1 << (k_2 - 1))) == 0;
                }
                else
                {
                    _1508 = _1498;
                }
                if (_1508)
                {
                    continue;
                }
                float slabH_1 = float(k_2) * 2.9500000476837158203125f;
                float clearK_1 = 1.0f - smoothstep(slabH_1 - 0.2199999988079071044921875f, slabH_1 - 0.0599999986588954925537109375f, canopyClearZ);
                if (clearK_1 > 0.001000000047497451305389404296875f)
                {
                    float prevH_1 = float(k_2 - 1) * 2.9500000476837158203125f;
                    float botK_1 = lerp(prevH_1 - 0.100000001490116119384765625f, slabH_1 - 0.100000001490116119384765625f, smoothstep(prevH_1 - 0.2199999988079071044921875f, prevH_1 - 0.0599999986588954925537109375f, canopyClearZ));
                    float topK_1 = max(canopyTop, slabH_1 + 0.180000007152557373046875f);
                    occ = max(occ, (clearK_1 * smoothstep(botK_1 - botPen, botK_1 + botPen, curRel)) * (1.0f - smoothstep(topK_1 - (0.3499999940395355224609375f * topPen), topK_1 + (0.64999997615814208984375f * topPen), prevRel)));
                }
            }
        }
    }
    if (canopyTop >= 2.900000095367431640625f)
    {
        float eaveStories = clamp(floor((canopyTop + 0.0500000007450580596923828125f) / 2.9500000476837158203125f), 1.0f, float(topUpperStory));
        float eaveBase = eaveStories * 2.9500000476837158203125f;
        float clearE = 1.0f - smoothstep(eaveBase - 0.2199999988079071044921875f, eaveBase - 0.0599999986588954925537109375f, canopyClearZ);
        if (clearE > 0.001000000047497451305389404296875f)
        {
            float topR = max(canopyTop, eaveBase + 0.180000007152557373046875f);
            occ = max(occ, (clearE * smoothstep((eaveBase - 0.14000000059604644775390625f) - botPen, (eaveBase - 0.14000000059604644775390625f) + botPen, curRel)) * (1.0f - smoothstep(topR - (0.3499999940395355224609375f * topPen), topR + (0.64999997615814208984375f * topPen), prevRel)));
        }
    }
    return occ;
}

float canopyOcclusionAt(float2 _point, float canopyClearZ, float qPrevZ, float qZ, float pen)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1651;
    if (orientation == 1)
    {
        _1651 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1665;
        if (orientation == 2)
        {
            _1665 = size - _point;
        }
        else
        {
            float2 _1674;
            if (orientation == 3)
            {
                _1674 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1674 = _point;
            }
            _1665 = _1674;
        }
        _1651 = _1665;
    }
    float2 source = _1651;
    bool _1692 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _1700;
    if (!_1692)
    {
        _1700 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _1700 = _1692;
    }
    if (_1700)
    {
        return 0.0f;
    }
    uint _1707_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1707_dummy_parameter));
    bool _1714 = mapSize.y >= (mapSize.x * 2);
    bool _1720;
    if (_1714)
    {
        _1720 = mapSize.x > 1;
    }
    else
    {
        _1720 = _1714;
    }
    bool hasBand1 = _1720;
    int2 _1723;
    if (hasBand1)
    {
        _1723 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1723 = mapSize;
    }
    int2 baseSize = _1723;
    float2 fPos = (source * (float2(baseSize) / max(size, 1.0f.xx))) - 0.5f.xx;
    int2 i0 = int2(floor(fPos));
    float2 f = frac(fPos);
    int2 maxIdx = baseSize - int2(1, 1);
    int2 gi = clamp(i0, int2(0, 0), max((maxIdx - int2(1, 1)), int2(0, 0)));
    float2 gUv = (float2(gi) + 1.0f.xx) / float2(max(mapSize, int2(1, 1)));
    float4 gR = overheadMap.GatherRed(_overheadMap_sampler, gUv);
    float4 gA = overheadMap.GatherAlpha(_overheadMap_sampler, gUv);
    bool _1792 = max(max(gR.x, gR.y), max(gR.z, gR.w)) < 0.123529411852359771728515625f;
    bool _1808;
    if (_1792)
    {
        _1808 = max(max(gA.x, gA.y), max(gA.z, gA.w)) < 0.0058823530562222003936767578125f;
    }
    else
    {
        _1808 = _1792;
    }
    if (_1808)
    {
        return 0.0f;
    }
    int2 p00 = clamp(i0, int2(0, 0), maxIdx);
    int2 p10 = clamp(i0 + int2(1, 0), int2(0, 0), maxIdx);
    int2 p01 = clamp(i0 + int2(0, 1), int2(0, 0), maxIdx);
    int2 p11 = clamp(i0 + int2(1, 1), int2(0, 0), maxIdx);
    int4 c00 = int4((overheadMap.Load(int3(p00, 0)) * 255.0f) + 0.5f.xxxx);
    int4 c10 = int4((overheadMap.Load(int3(p10, 0)) * 255.0f) + 0.5f.xxxx);
    int4 c01 = int4((overheadMap.Load(int3(p01, 0)) * 255.0f) + 0.5f.xxxx);
    int4 c11 = int4((overheadMap.Load(int3(p11, 0)) * 255.0f) + 0.5f.xxxx);
    int rUnion = ((c00.x | c10.x) | c01.x) | c11.x;
    int aMax = max(max(c00.w, c10.w), max(c01.w, c11.w));
    if (((rUnion & 96) == 0) && (aMax <= 1))
    {
        return 0.0f;
    }
    bool _1906 = c00.w != 0;
    bool _1912;
    if (_1906)
    {
        _1912 = c00.w != 255;
    }
    else
    {
        _1912 = _1906;
    }
    bool v00 = _1912;
    bool _1916 = c10.w != 0;
    bool _1922;
    if (_1916)
    {
        _1922 = c10.w != 255;
    }
    else
    {
        _1922 = _1916;
    }
    bool v10 = _1922;
    bool _1926 = c01.w != 0;
    bool _1932;
    if (_1926)
    {
        _1932 = c01.w != 255;
    }
    else
    {
        _1932 = _1926;
    }
    bool v01 = _1932;
    bool _1936 = c11.w != 0;
    bool _1942;
    if (_1936)
    {
        _1942 = c11.w != 255;
    }
    else
    {
        _1942 = _1936;
    }
    bool v11 = _1942;
    if ((((!v00) && (!v10)) && (!v01)) && (!v11))
    {
        return 0.0f;
    }
    float _1959;
    if (v00)
    {
        _1959 = float(((c00.y * 256) + c00.z) - 32768) / 256.0f;
    }
    else
    {
        float _1973;
        if (v10)
        {
            _1973 = float(((c10.y * 256) + c10.z) - 32768) / 256.0f;
        }
        else
        {
            float _1987;
            if (v01)
            {
                _1987 = float(((c01.y * 256) + c01.z) - 32768) / 256.0f;
            }
            else
            {
                _1987 = float(((c11.y * 256) + c11.z) - 32768) / 256.0f;
            }
            _1973 = _1987;
        }
        _1959 = _1973;
    }
    float refBase = _1959;
    if ((qZ - refBase) < 2.5299999713897705078125f)
    {
        return 0.0f;
    }
    float roofOcc = 0.0f;
    if (aMax >= 2)
    {
        float topScale = hasBand1 ? 4.0f : 8.0f;
        if ((qPrevZ - refBase) <= (((float(aMax - 2) / topScale) + 0.60000002384185791015625f) + min(pen, 0.62000000476837158203125f)))
        {
            float2 um = 1.0f.xx - f;
            float4 wx = float4(((um.x * um.x) * um.x) / 6.0f, (((((3.0f * f.x) * f.x) * f.x) - ((6.0f * f.x) * f.x)) + 4.0f) / 6.0f, (((((((-3.0f) * f.x) * f.x) * f.x) + ((3.0f * f.x) * f.x)) + (3.0f * f.x)) + 1.0f) / 6.0f, ((f.x * f.x) * f.x) / 6.0f);
            float4 wy = float4(((um.y * um.y) * um.y) / 6.0f, (((((3.0f * f.y) * f.y) * f.y) - ((6.0f * f.y) * f.y)) + 4.0f) / 6.0f, (((((((-3.0f) * f.y) * f.y) * f.y) + ((3.0f * f.y) * f.y)) + (3.0f * f.y)) + 1.0f) / 6.0f, ((f.y * f.y) * f.y) / 6.0f);
            float2 invM = 1.0f.xx / float2(max(mapSize, int2(1, 1)));
            int2 gTL = clamp(i0 - int2(1, 1), int2(0, 0), max((maxIdx - int2(1, 1)), int2(0, 0)));
            int2 gTR = clamp(i0 + int2(1, -1), int2(0, 0), max((maxIdx - int2(1, 1)), int2(0, 0)));
            int2 gBL = clamp(i0 + int2(-1, 1), int2(0, 0), max((maxIdx - int2(1, 1)), int2(0, 0)));
            int2 gBR = clamp(i0 + int2(1, 1), int2(0, 0), max((maxIdx - int2(1, 1)), int2(0, 0)));
            float4 qTL = floor((overheadMap.GatherAlpha(_overheadMap_sampler, (float2(gTL) + 1.0f.xx) * invM) * 255.0f) + 0.5f.xxxx);
            float4 qTR = floor((overheadMap.GatherAlpha(_overheadMap_sampler, (float2(gTR) + 1.0f.xx) * invM) * 255.0f) + 0.5f.xxxx);
            float4 qBL = floor((overheadMap.GatherAlpha(_overheadMap_sampler, (float2(gBL) + 1.0f.xx) * invM) * 255.0f) + 0.5f.xxxx);
            float4 qBR = floor((overheadMap.GatherAlpha(_overheadMap_sampler, (float2(gBR) + 1.0f.xx) * invM) * 255.0f) + 0.5f.xxxx);
            float4 vTL = step(1.5f.xxxx, qTL) * step(qTL, 254.5f.xxxx);
            float4 vTR = step(1.5f.xxxx, qTR) * step(qTR, 254.5f.xxxx);
            float4 vBL = step(1.5f.xxxx, qBL) * step(qBL, 254.5f.xxxx);
            float4 vBR = step(1.5f.xxxx, qBR) * step(qBR, 254.5f.xxxx);
            float4 wTL = vTL * float4(wx.x * wy.y, wx.y * wy.y, wx.y * wy.x, wx.x * wy.x);
            float4 wTR = vTR * float4(wx.z * wy.y, wx.w * wy.y, wx.w * wy.x, wx.z * wy.x);
            float4 wBL = vBL * float4(wx.x * wy.w, wx.y * wy.w, wx.y * wy.z, wx.x * wy.z);
            float4 wBR = vBR * float4(wx.z * wy.w, wx.w * wy.w, wx.w * wy.z, wx.z * wy.z);
            float roofW = ((dot(wTL, 1.0f.xxxx) + dot(wTR, 1.0f.xxxx)) + dot(wBL, 1.0f.xxxx)) + dot(wBR, 1.0f.xxxx);
            if (roofW > 9.9999997473787516355514526367188e-05f)
            {
                float sumTop = (((dot(wTL, qTL - 2.0f.xxxx) + dot(wTR, qTR - 2.0f.xxxx)) + dot(wBL, qBL - 2.0f.xxxx)) + dot(wBR, qBR - 2.0f.xxxx)) / topScale;
                float smoothRoofTop = sumTop / roofW;
                bool _2440 = c00.w >= 2;
                bool _2446;
                if (_2440)
                {
                    _2446 = c00.w != 255;
                }
                else
                {
                    _2446 = _2440;
                }
                int4 _2447;
                if (_2446)
                {
                    _2447 = c00;
                }
                else
                {
                    bool _2454 = c10.w >= 2;
                    bool _2460;
                    if (_2454)
                    {
                        _2460 = c10.w != 255;
                    }
                    else
                    {
                        _2460 = _2454;
                    }
                    int4 _2461;
                    if (_2460)
                    {
                        _2461 = c10;
                    }
                    else
                    {
                        bool _2468 = c01.w >= 2;
                        bool _2474;
                        if (_2468)
                        {
                            _2474 = c01.w != 255;
                        }
                        else
                        {
                            _2474 = _2468;
                        }
                        bool4 _2478 = _2474.xxxx;
                        _2461 = int4(_2478.x ? c01.x : c11.x, _2478.y ? c01.y : c11.y, _2478.z ? c01.z : c11.z, _2478.w ? c01.w : c11.w);
                    }
                    _2447 = _2461;
                }
                int4 cRef = _2447;
                int4 param = cRef;
                int param_1 = 0;
                bool param_2 = hasBand1;
                float param_3 = canopyClearZ;
                float param_4 = qPrevZ;
                float param_5 = qZ;
                float param_6 = pen;
                float param_7 = smoothRoofTop;
                roofOcc = clamp(roofW, 0.0f, 1.0f) * canopyBlockedTexel(param, param_1, param_2, param_3, param_4, param_5, param_6, param_7);
            }
        }
    }
    if ((rUnion & 96) == 0)
    {
        return roofOcc;
    }
    int s00 = 0;
    int s10 = 0;
    int s01 = 0;
    int s11 = 0;
    bool _2518;
    if (hasBand1)
    {
        _2518 = (rUnion & 64) != 0;
    }
    else
    {
        _2518 = hasBand1;
    }
    if (_2518)
    {
        int2 bOff = int2(0, baseSize.y);
        if ((c00.x & 64) != 0)
        {
            int4 d = int4((overheadMap.Load(int3(p00 + bOff, 0)) * 255.0f) + 0.5f.xxxx);
            s00 = d.z | (d.w << 8);
        }
        if ((c10.x & 64) != 0)
        {
            int4 d_1 = int4((overheadMap.Load(int3(p10 + bOff, 0)) * 255.0f) + 0.5f.xxxx);
            s10 = d_1.z | (d_1.w << 8);
        }
        if ((c01.x & 64) != 0)
        {
            int4 d_2 = int4((overheadMap.Load(int3(p01 + bOff, 0)) * 255.0f) + 0.5f.xxxx);
            s01 = d_2.z | (d_2.w << 8);
        }
        if ((c11.x & 64) != 0)
        {
            int4 d_3 = int4((overheadMap.Load(int3(p11 + bOff, 0)) * 255.0f) + 0.5f.xxxx);
            s11 = d_3.z | (d_3.w << 8);
        }
    }
    float _2622;
    if ((c00.x & 96) != 0)
    {
        int4 param_8 = int4(c00.xyz, 1);
        int param_9 = s00;
        bool param_10 = hasBand1;
        float param_11 = canopyClearZ;
        float param_12 = qPrevZ;
        float param_13 = qZ;
        float param_14 = pen;
        float param_15 = -1.0f;
        _2622 = canopyBlockedTexel(param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15);
    }
    else
    {
        _2622 = 0.0f;
    }
    float b00 = _2622;
    float _2654;
    if ((c10.x & 96) != 0)
    {
        int4 param_16 = int4(c10.xyz, 1);
        int param_17 = s10;
        bool param_18 = hasBand1;
        float param_19 = canopyClearZ;
        float param_20 = qPrevZ;
        float param_21 = qZ;
        float param_22 = pen;
        float param_23 = -1.0f;
        _2654 = canopyBlockedTexel(param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23);
    }
    else
    {
        _2654 = 0.0f;
    }
    float b10 = _2654;
    float _2685;
    if ((c01.x & 96) != 0)
    {
        int4 param_24 = int4(c01.xyz, 1);
        int param_25 = s01;
        bool param_26 = hasBand1;
        float param_27 = canopyClearZ;
        float param_28 = qPrevZ;
        float param_29 = qZ;
        float param_30 = pen;
        float param_31 = -1.0f;
        _2685 = canopyBlockedTexel(param_24, param_25, param_26, param_27, param_28, param_29, param_30, param_31);
    }
    else
    {
        _2685 = 0.0f;
    }
    float b01 = _2685;
    float _2716;
    if ((c11.x & 96) != 0)
    {
        int4 param_32 = int4(c11.xyz, 1);
        int param_33 = s11;
        bool param_34 = hasBand1;
        float param_35 = canopyClearZ;
        float param_36 = qPrevZ;
        float param_37 = qZ;
        float param_38 = pen;
        float param_39 = -1.0f;
        _2716 = canopyBlockedTexel(param_32, param_33, param_34, param_35, param_36, param_37, param_38, param_39);
    }
    else
    {
        _2716 = 0.0f;
    }
    float b11 = _2716;
    return max(roofOcc, lerp(lerp(b00, b10, f.x), lerp(b01, b11, f.x), f.y));
}

bool voxelColumnOverlap(float2 xy, float qMinZ, float qMaxZ, int vAoSize, int vAoYBase, float2 lotSz)
{
    bool _6648 = xy.x < (-0.449999988079071044921875f);
    bool _6655;
    if (!_6648)
    {
        _6655 = xy.y < (-0.449999988079071044921875f);
    }
    else
    {
        _6655 = _6648;
    }
    bool _6665;
    if (!_6655)
    {
        _6665 = xy.x > (lotSz.x + 0.449999988079071044921875f);
    }
    else
    {
        _6665 = _6655;
    }
    bool _6675;
    if (!_6665)
    {
        _6675 = xy.y > (lotSz.y + 0.449999988079071044921875f);
    }
    else
    {
        _6675 = _6665;
    }
    if (_6675)
    {
        return false;
    }
    int2 cg = clamp(int2(floor(xy * 8.0f)), int2(0, 0), (vAoSize - 1).xx);
    int y = vAoYBase + cg.y;
    int allMaxB = int((voxelMap.Load(int3(int2(cg.x, y), 0)).w * 255.0f) + 0.5f);
    bool _6706 = allMaxB == 0;
    bool _6719;
    if (!_6706)
    {
        _6719 = qMinZ > ((float(allMaxB - 1) * 0.125f) - 3.61999988555908203125f);
    }
    else
    {
        _6719 = _6706;
    }
    if (_6719)
    {
        return false;
    }
    int allMinB = int((voxelMap.Load(int3(int2(vAoSize + cg.x, y), 0)).w * 255.0f) + 0.5f);
    bool _6738 = allMinB > 0;
    bool _6749;
    if (_6738)
    {
        _6749 = qMaxZ < ((float(allMinB - 1) * 0.125f) - 4.38000011444091796875f);
    }
    else
    {
        _6749 = _6738;
    }
    if (_6749)
    {
        return false;
    }
    int s1MaxB = int((voxelMap.Load(int3(int2((2 * vAoSize) + cg.x, y), 0)).w * 255.0f) + 0.5f);
    bool _6769 = s1MaxB == 0;
    bool _6780;
    if (!_6769)
    {
        _6780 = qMinZ > ((float(s1MaxB - 1) * 0.125f) - 3.61999988555908203125f);
    }
    else
    {
        _6780 = _6769;
    }
    if (_6780)
    {
        int upMinB = int((voxelMap.Load(int3(int2((3 * vAoSize) + cg.x, y), 0)).w * 255.0f) + 0.5f);
        bool _6799 = upMinB == 0;
        bool _6810;
        if (!_6799)
        {
            _6810 = qMaxZ < ((float(upMinB - 1) * 0.125f) - 4.38000011444091796875f);
        }
        else
        {
            _6810 = _6799;
        }
        if (_6810)
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
    bool _5947 = maxR < 0.5f;
    bool _5958;
    if (!_5947)
    {
        _5958 = (maxR - 14.8999996185302734375f) < (kMin - pad);
    }
    else
    {
        _5958 = _5947;
    }
    if (_5958)
    {
        return 0.0f;
    }
    float4 gB = voxelMap.GatherBlue(_voxelMap_sampler, gUv) * 255.0f;
    bool _5971 = gR.x > 0.5f;
    bool _5981;
    if (_5971)
    {
        _5981 = (gR.x - 14.8999996185302734375f) >= (kMin - pad);
    }
    else
    {
        _5981 = _5971;
    }
    bool _5992;
    if (_5981)
    {
        _5992 = (gB.x - 16.1000003814697265625f) <= (kMax + pad);
    }
    else
    {
        _5992 = _5981;
    }
    bool _5995 = gR.y > 0.5f;
    bool _6005;
    if (_5995)
    {
        _6005 = (gR.y - 14.8999996185302734375f) >= (kMin - pad);
    }
    else
    {
        _6005 = _5995;
    }
    bool _6015;
    if (_6005)
    {
        _6015 = (gB.y - 16.1000003814697265625f) <= (kMax + pad);
    }
    else
    {
        _6015 = _6005;
    }
    bool _6018 = gR.z > 0.5f;
    bool _6028;
    if (_6018)
    {
        _6028 = (gR.z - 14.8999996185302734375f) >= (kMin - pad);
    }
    else
    {
        _6028 = _6018;
    }
    bool _6038;
    if (_6028)
    {
        _6038 = (gB.z - 16.1000003814697265625f) <= (kMax + pad);
    }
    else
    {
        _6038 = _6028;
    }
    bool _6041 = gR.w > 0.5f;
    bool _6051;
    if (_6041)
    {
        _6051 = (gR.w - 14.8999996185302734375f) >= (kMin - pad);
    }
    else
    {
        _6051 = _6041;
    }
    bool _6061;
    if (_6051)
    {
        _6061 = (gB.w - 16.1000003814697265625f) <= (kMax + pad);
    }
    else
    {
        _6061 = _6051;
    }
    bool4 cand = bool4(_5992, _6015, _6038, _6061);
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
    float _6293;
    if (f00 == 0)
    {
        _6293 = 0.0f;
    }
    else
    {
        _6293 = smoothstep(-pad, kTop, ((float(f00) / 256.0f) - 16.0f) - kMin) * smoothstep(-pad, kTop, kMax - ((float((r00.z * 256) + r00.w) / 256.0f) - 16.0f));
    }
    float v00 = _6293;
    float _6327;
    if (f10 == 0)
    {
        _6327 = 0.0f;
    }
    else
    {
        _6327 = smoothstep(-pad, kTop, ((float(f10) / 256.0f) - 16.0f) - kMin) * smoothstep(-pad, kTop, kMax - ((float((r10.z * 256) + r10.w) / 256.0f) - 16.0f));
    }
    float v10 = _6327;
    float _6361;
    if (f01 == 0)
    {
        _6361 = 0.0f;
    }
    else
    {
        _6361 = smoothstep(-pad, kTop, ((float(f01) / 256.0f) - 16.0f) - kMin) * smoothstep(-pad, kTop, kMax - ((float((r01.z * 256) + r01.w) / 256.0f) - 16.0f));
    }
    float v01 = _6361;
    float _6395;
    if (f11 == 0)
    {
        _6395 = 0.0f;
    }
    else
    {
        _6395 = smoothstep(-pad, kTop, ((float(f11) / 256.0f) - 16.0f) - kMin) * smoothstep(-pad, kTop, kMax - ((float((r11.z * 256) + r11.w) / 256.0f) - 16.0f));
    }
    float v11 = _6395;
    return lerp(lerp(v00, v10, f.x), lerp(v01, v11, f.x), f.y);
}

float evalHullInterval3D(float3 qSub, float3 halfStepQ, float pad, float kTop, int2 oSize, int halfH, float topMarginHalf, int2 sliceMax, float2 lotSz, float2 invVSize)
{
    float2 op0 = float2(((qSub.x - qSub.y) + lotSz.x) * 16.0f, (((qSub.x + qSub.y) * 8.0f) - (qSub.z * 20.0f)) + topMarginHalf);
    bool _6466 = any(bool2(op0.x < 0.0f.xx.x, op0.y < 0.0f.xx.y));
    bool _6476;
    if (!_6466)
    {
        _6476 = op0.x >= float(oSize.x);
    }
    else
    {
        _6476 = _6466;
    }
    bool _6485;
    if (!_6476)
    {
        _6485 = op0.y >= float(halfH);
    }
    else
    {
        _6485 = _6476;
    }
    if (_6485)
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
    bool _6573 = any(bool2(op1.x < 0.0f.xx.x, op1.y < 0.0f.xx.y));
    bool _6583;
    if (!_6573)
    {
        _6583 = op1.x >= float(oSize.x);
    }
    else
    {
        _6583 = _6573;
    }
    bool _6592;
    if (!_6583)
    {
        _6592 = op1.y >= float(halfH);
    }
    else
    {
        _6592 = _6583;
    }
    if (_6592)
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
    float2 _6848 = (-marginPx).xx;
    bool _6850 = any(bool2(op0Mid.x < _6848.x, op0Mid.y < _6848.y));
    bool _6862;
    if (!_6850)
    {
        _6862 = op0Mid.x >= (float(oSize.x) + marginPx);
    }
    else
    {
        _6862 = _6850;
    }
    bool _6873;
    if (!_6862)
    {
        _6873 = op0Mid.y >= (float(halfH) + marginPx);
    }
    else
    {
        _6873 = _6862;
    }
    if (_6873)
    {
        return;
    }
    float3 qBMid = float3(lotSz.y - qMid.y, qMid.x, qMid.z);
    float2 op1Mid = float2(((qBMid.x - qBMid.y) + lotSz.x) * 16.0f, (((qBMid.x + qBMid.y) * 8.0f) - (qBMid.z * 20.0f)) + topMarginHalf);
    float2 _6914 = (-marginPx).xx;
    bool _6916 = any(bool2(op1Mid.x < _6914.x, op1Mid.y < _6914.y));
    bool _6928;
    if (!_6916)
    {
        _6928 = op1Mid.x >= (float(oSize.x) + marginPx);
    }
    else
    {
        _6928 = _6916;
    }
    bool _6939;
    if (!_6928)
    {
        _6939 = op1Mid.y >= (float(halfH) + marginPx);
    }
    else
    {
        _6939 = _6928;
    }
    if (_6939)
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
    bool _5568 = any(bool2(wp.x < 0.5f.xx.x, wp.y < 0.5f.xx.y));
    bool _5578;
    if (!_5568)
    {
        float2 _5575 = wSize - 0.5f.xx;
        _5578 = any(bool2(wp.x >= _5575.x, wp.y >= _5575.y));
    }
    else
    {
        _5578 = _5568;
    }
    if (_5578)
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
    bool _5727 = wpMid.x < (ambient_dynShadowBounds.x - rBound);
    bool _5738;
    if (!_5727)
    {
        _5738 = wpMid.y < (ambient_dynShadowBounds.y - rBound);
    }
    else
    {
        _5738 = _5727;
    }
    bool _5749;
    if (!_5738)
    {
        _5749 = wpMid.x > (ambient_dynShadowBounds.z + rBound);
    }
    else
    {
        _5749 = _5738;
    }
    bool _5760;
    if (!_5749)
    {
        _5760 = wpMid.y > (ambient_dynShadowBounds.w + rBound);
    }
    else
    {
        _5760 = _5749;
    }
    if (_5760)
    {
        return;
    }
    bool _5767 = any(bool2(wpMid.x < (-3.0f).xx.x, wpMid.y < (-3.0f).xx.y));
    bool _5777;
    if (!_5767)
    {
        float2 _5774 = wSize + 3.0f.xx;
        _5777 = any(bool2(wpMid.x >= _5774.x, wpMid.y >= _5774.y));
    }
    else
    {
        _5777 = _5767;
    }
    if (_5777)
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

float3 sunMarchFast(float3 here, float start, float canopyClearZ, float selfSimGuard, int2 vSize, int stories)
{
    bool hasVoxels = vSize.x > 1;
    float2 invVSize = 1.0f.xx / float2(max(vSize, int2(1, 1)));
    uint _7275_dummy_parameter;
    float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _7275_dummy_parameter)));
    uint _7280_dummy_parameter;
    bool hasOverhead = int2(spvTextureSize(overheadMap, uint(0), _7280_dummy_parameter)).x > 1;
    int _7285;
    if (hasVoxels)
    {
        int2 param = vSize;
        _7285 = voxelAoRows(param);
    }
    else
    {
        _7285 = 1;
    }
    int vAoRows = _7285;
    int vHalfH = ((vSize.x / 2) + 128) + (256 * vAoRows);
    int vAoSize = vSize.x / 4;
    int vAoYBase = vHalfH * 2;
    bool _7313 = hasVoxels && (vAoSize > 0);
    bool _7322;
    if (_7313)
    {
        _7322 = vSize.y >= (vAoYBase + vAoSize);
    }
    else
    {
        _7322 = _7313;
    }
    bool hasColBounds = _7322;
    float vTopMarginHalf = float(64 + (256 * vAoRows));
    int2 vSliceMax = int2(vSize.x - 1, vHalfH - 1);
    float2 sLotSz = max(ambient_drift.zw, 1.0f.xx);
    int orient = int(ambient_clouds.z + 0.5f);
    float2 _7349;
    if ((orient & 1) == 0)
    {
        _7349 = ambient_drift.zw;
    }
    else
    {
        _7349 = ambient_drift.wz;
    }
    float2 camLotSz = max(_7349, 1.0f.xx);
    uint _7364_dummy_parameter;
    int2 mSize = int2(spvTextureSize(indoorMap, uint(0), _7364_dummy_parameter));
    int2 param_1 = mSize;
    int mBandH = indoorBandH(param_1);
    float3 sunDir = ambient_sunLot.xyz;
    float2 sunProj = float2(32.0f * (sunDir.x - sunDir.y), (16.0f * (sunDir.x + sunDir.y)) - (40.0f * sunDir.z));
    float projLen = length(sunProj);
    float2 _7397;
    if (projLen > 0.001000000047497451305389404296875f)
    {
        _7397 = sunProj / projLen.xx;
    }
    else
    {
        _7397 = float2(1.0f, 0.0f);
    }
    float2 sunDirPx = _7397;
    float2 sunPerp = float2(-sunDirPx.y, sunDirPx.x);
    float maxCasterH = max(10.5f, (float(stories) * 2.9500000476837158203125f) + 4.599999904632568359375f);
    float maxVoxelH = (float(stories) * 2.9500000476837158203125f) + 3.7999999523162841796875f;
    float maxSimH = (float(stories) * 2.9500000476837158203125f) + 2.400000095367431640625f;
    float minCanopyZ = (ambient_contact.w + 2.9500000476837158203125f) - 0.449999988079071044921875f;
    float maxReach = ambient_sunLot.w + 0.20000000298023223876953125f;
    float maxT = min(maxReach, maxCasterH / max(sunDir.z, 0.14000000059604644775390625f));
    float marginLo = (-ambient_frame.w) + (1.0f / max(ambient_frame.z, 1.0f));
    float2 marginHi = (camLotSz + ambient_frame.w.xx) - (1.0f / max(ambient_frame.z, 1.0f)).xx;
    float gridEnter = start;
    float gridExit = maxT;
    float param_2 = here.x;
    float param_3 = sunDir.x;
    float param_4 = marginLo;
    float param_5 = marginHi.x;
    float param_6 = gridEnter;
    float param_7 = gridExit;
    clipAxisSlab(param_2, param_3, param_4, param_5, param_6, param_7);
    gridEnter = param_6;
    gridExit = param_7;
    float param_8 = here.y;
    float param_9 = sunDir.y;
    float param_10 = marginLo;
    float param_11 = marginHi.y;
    float param_12 = gridEnter;
    float param_13 = gridExit;
    clipAxisSlab(param_8, param_9, param_10, param_11, param_12, param_13);
    gridEnter = param_12;
    gridExit = param_13;
    if (gridEnter >= (gridExit - 0.00999999977648258209228515625f))
    {
        return 1.0f.xxx;
    }
    float2 tVox = float2(1000000.0f, -1000000.0f);
    bool _7529;
    if (hasVoxels)
    {
        _7529 = ambient_voxShadowBounds.x <= ambient_voxShadowBounds.z;
    }
    else
    {
        _7529 = hasVoxels;
    }
    bool _7538;
    if (_7529)
    {
        _7538 = ambient_casterZBounds.x <= ambient_casterZBounds.y;
    }
    else
    {
        _7538 = _7529;
    }
    if (_7538)
    {
        float ve = gridEnter;
        float vx = min(gridExit, (maxVoxelH + 0.25f) / max(sunDir.z, 9.9999997473787516355514526367188e-05f));
        float param_14 = here.x;
        float param_15 = sunDir.x;
        float param_16 = ambient_voxShadowBounds.x;
        float param_17 = ambient_voxShadowBounds.z;
        float param_18 = ve;
        float param_19 = vx;
        clipAxisSlab(param_14, param_15, param_16, param_17, param_18, param_19);
        ve = param_18;
        vx = param_19;
        float param_20 = here.y;
        float param_21 = sunDir.y;
        float param_22 = ambient_voxShadowBounds.y;
        float param_23 = ambient_voxShadowBounds.w;
        float param_24 = ve;
        float param_25 = vx;
        clipAxisSlab(param_20, param_21, param_22, param_23, param_24, param_25);
        ve = param_24;
        vx = param_25;
        float param_26 = here.z;
        float param_27 = sunDir.z;
        float param_28 = ambient_casterZBounds.x;
        float param_29 = ambient_casterZBounds.y;
        float param_30 = ve;
        float param_31 = vx;
        clipAxisSlab(param_26, param_27, param_28, param_29, param_30, param_31);
        ve = param_30;
        vx = param_31;
        if (ve <= vx)
        {
            tVox = float2(ve, vx);
        }
    }
    float2 tRoof = float2(1000000.0f, -1000000.0f);
    bool _7627;
    if (hasOverhead)
    {
        _7627 = ambient_roofShadowBounds.x <= ambient_roofShadowBounds.z;
    }
    else
    {
        _7627 = hasOverhead;
    }
    bool _7635;
    if (_7627)
    {
        _7635 = ambient_casterZBounds.z <= ambient_casterZBounds.w;
    }
    else
    {
        _7635 = _7627;
    }
    if (_7635)
    {
        float re = gridEnter;
        float rx = gridExit;
        float param_32 = here.x;
        float param_33 = sunDir.x;
        float param_34 = ambient_roofShadowBounds.x;
        float param_35 = ambient_roofShadowBounds.z;
        float param_36 = re;
        float param_37 = rx;
        clipAxisSlab(param_32, param_33, param_34, param_35, param_36, param_37);
        re = param_36;
        rx = param_37;
        float param_38 = here.y;
        float param_39 = sunDir.y;
        float param_40 = ambient_roofShadowBounds.y;
        float param_41 = ambient_roofShadowBounds.w;
        float param_42 = re;
        float param_43 = rx;
        clipAxisSlab(param_38, param_39, param_40, param_41, param_42, param_43);
        re = param_42;
        rx = param_43;
        float param_44 = here.z;
        float param_45 = sunDir.z;
        float param_46 = max(minCanopyZ, ambient_casterZBounds.z);
        float param_47 = ambient_casterZBounds.w;
        float param_48 = re;
        float param_49 = rx;
        clipAxisSlab(param_44, param_45, param_46, param_47, param_48, param_49);
        re = param_48;
        rx = param_49;
        if (re <= rx)
        {
            tRoof = float2(re, rx);
        }
    }
    float wScale = max(ambient_shadowView.z, 0.5f);
    bool _7716 = ambient_shadowView.w > 0.5f;
    bool _7724;
    if (_7716)
    {
        _7724 = ambient_dynShadowBounds.x <= ambient_dynShadowBounds.z;
    }
    else
    {
        _7724 = _7716;
    }
    bool hasAnyDynSims = _7724;
    float2 tSim = float2(1000000.0f, -1000000.0f);
    if (hasAnyDynSims)
    {
        float se = max(gridEnter, selfSimGuard - 0.180000007152557373046875f);
        float sx = min(gridExit, (maxSimH + 0.25f) / max(sunDir.z, 9.9999997473787516355514526367188e-05f));
        float3 param_50 = here;
        float2 wpOrig = ambient_shadowView.xy + (sceneOf(param_50) * ambient_shadowView.z);
        float2 wpDir = sunProj * ambient_shadowView.z;
        float simPad = ((1.60000002384185791015625f * wScale) + (0.25f * length(wpDir))) + 4.0f;
        float param_51 = wpOrig.x;
        float param_52 = wpDir.x;
        float param_53 = ambient_dynShadowBounds.x - simPad;
        float param_54 = ambient_dynShadowBounds.z + simPad;
        float param_55 = se;
        float param_56 = sx;
        clipAxisSlab(param_51, param_52, param_53, param_54, param_55, param_56);
        se = param_55;
        sx = param_56;
        float param_57 = wpOrig.y;
        float param_58 = wpDir.y;
        float param_59 = ambient_dynShadowBounds.y - simPad;
        float param_60 = ambient_dynShadowBounds.w + simPad;
        float param_61 = se;
        float param_62 = sx;
        clipAxisSlab(param_57, param_58, param_59, param_60, param_61, param_62);
        se = param_61;
        sx = param_62;
        if (se <= sx)
        {
            tSim = float2(se, sx);
        }
    }
    float _7828;
    if (tVox.x <= tVox.y)
    {
        _7828 = tVox.x;
    }
    else
    {
        _7828 = 1000000.0f;
    }
    float _7840;
    if (tRoof.x <= tRoof.y)
    {
        _7840 = tRoof.x;
    }
    else
    {
        _7840 = 1000000.0f;
    }
    float _7852;
    if (tSim.x <= tSim.y)
    {
        _7852 = tSim.x;
    }
    else
    {
        _7852 = 1000000.0f;
    }
    float tEnter = min(_7828, min(_7840, _7852));
    float _7867;
    if (tVox.x <= tVox.y)
    {
        _7867 = tVox.y;
    }
    else
    {
        _7867 = -1000000.0f;
    }
    float _7879;
    if (tRoof.x <= tRoof.y)
    {
        _7879 = tRoof.y;
    }
    else
    {
        _7879 = -1000000.0f;
    }
    float _7891;
    if (tSim.x <= tSim.y)
    {
        _7891 = tSim.y;
    }
    else
    {
        _7891 = -1000000.0f;
    }
    float tExit = max(_7867, max(_7879, _7891));
    if (tEnter > tExit)
    {
        return 1.0f.xxx;
    }
    float dtBase = clamp(1.5499999523162841796875f / max(projLen, 20.0f), 0.056000001728534698486328125f, 0.06800000369548797607421875f);
    float sCap = log(0.36000001430511474609375f / dtBase) / 0.02199999988079071044921875f;
    float relTCap = (0.36000001430511474609375f - dtBase) / 0.02199999988079071044921875f;
    float param_63 = tEnter - start;
    float param_64 = dtBase;
    float param_65 = sCap;
    float param_66 = relTCap;
    int iStart = max(0, int(floor(rayStepOf(param_63, param_64, param_65, param_66))));
    float param_67 = tExit - start;
    float param_68 = dtBase;
    float param_69 = sCap;
    float param_70 = relTCap;
    int iEnd = min(140, (int(ceil(rayStepOf(param_67, param_68, param_69, param_70))) + 1));
    if (iStart >= iEnd)
    {
        return 1.0f.xxx;
    }
    float sunChebRate = max(max(abs(sunDir.x), abs(sunDir.y)), 9.9999997473787516355514526367188e-05f);
    float3 sunDir3 = normalize(sunDir);
    bool3 _7982 = (abs(sunDir3.z) < 0.920000016689300537109375f).xxx;
    float3 refAxis = float3(_7982.x ? float3(0.0f, 0.0f, 1.0f).x : float3(1.0f, 0.0f, 0.0f).x, _7982.y ? float3(0.0f, 0.0f, 1.0f).y : float3(1.0f, 0.0f, 0.0f).y, _7982.z ? float3(0.0f, 0.0f, 1.0f).z : float3(1.0f, 0.0f, 0.0f).z);
    float3 coneU = normalize(cross(sunDir3, refAxis));
    float3 coneV = cross(sunDir3, coneU);
    float4 laneLit = 1.0f.xxxx;
    float2 simLaneLit = 1.0f.xx;
    float roofLit = 1.0f;
    int2 prevWinCell = int2(-99999, -99999);
    int cachedBaseCode0 = 0;
    int _8585;
    float _8606;
    for (int i = iStart; i < iEnd; i++)
    {
        float param_71 = float(i);
        float param_72 = dtBase;
        float param_73 = sCap;
        float param_74 = relTCap;
        float t = start + rayRelT(param_71, param_72, param_73, param_74);
        if (t >= gridExit)
        {
            break;
        }
        float param_75 = float(i + 1);
        float param_76 = dtBase;
        float param_77 = sCap;
        float param_78 = relTCap;
        float tNext = min(start + rayRelT(param_75, param_76, param_77, param_78), gridExit);
        float stepLen = tNext - t;
        if (stepLen <= 9.9999997473787516355514526367188e-05f)
        {
            break;
        }
        float tMid = t + (0.5f * stepLen);
        bool _8064 = tRoof.x <= tRoof.y;
        bool _8071;
        if (_8064)
        {
            _8071 = tNext >= tRoof.x;
        }
        else
        {
            _8071 = _8064;
        }
        bool _8078;
        if (_8071)
        {
            _8078 = t <= tRoof.y;
        }
        else
        {
            _8078 = _8071;
        }
        bool inRoof = _8078;
        bool _8084 = tVox.x <= tVox.y;
        bool _8091;
        if (_8084)
        {
            _8091 = tNext >= tVox.x;
        }
        else
        {
            _8091 = _8084;
        }
        bool _8098;
        if (_8091)
        {
            _8098 = t <= tVox.y;
        }
        else
        {
            _8098 = _8091;
        }
        bool inVox = _8098;
        bool _8104 = tSim.x <= tSim.y;
        bool _8111;
        if (_8104)
        {
            _8111 = tNext >= tSim.x;
        }
        else
        {
            _8111 = _8104;
        }
        bool _8118;
        if (_8111)
        {
            _8118 = t <= tSim.y;
        }
        else
        {
            _8118 = _8111;
        }
        bool inSim = _8118;
        if (((!inRoof) && (!inVox)) && (!inSim))
        {
            float nextEnter = 1000000.0f;
            bool _8134 = tVox.x <= tVox.y;
            bool _8141;
            if (_8134)
            {
                _8141 = tVox.x > tNext;
            }
            else
            {
                _8141 = _8134;
            }
            if (_8141)
            {
                nextEnter = min(nextEnter, tVox.x);
            }
            bool _8152 = tRoof.x <= tRoof.y;
            bool _8159;
            if (_8152)
            {
                _8159 = tRoof.x > tNext;
            }
            else
            {
                _8159 = _8152;
            }
            if (_8159)
            {
                nextEnter = min(nextEnter, tRoof.x);
            }
            bool _8170 = tSim.x <= tSim.y;
            bool _8177;
            if (_8170)
            {
                _8177 = tSim.x > tNext;
            }
            else
            {
                _8177 = _8170;
            }
            if (_8177)
            {
                nextEnter = min(nextEnter, tSim.x);
            }
            if (nextEnter >= 100000.0f)
            {
                break;
            }
            float param_79 = nextEnter - start;
            float param_80 = dtBase;
            float param_81 = sCap;
            float param_82 = relTCap;
            int jumpIdx = int(floor(rayStepOf(param_79, param_80, param_81, param_82))) - 1;
            if (jumpIdx > i)
            {
                i = jumpIdx;
            }
            continue;
        }
        float3 qPrev = here + (sunDir * t);
        bool _8224 = ((!inRoof) && (!inSim)) && hasColBounds;
        bool _8230;
        if (_8224)
        {
            _8230 = qPrev.x >= 0.0f;
        }
        else
        {
            _8230 = _8224;
        }
        bool _8236;
        if (_8230)
        {
            _8236 = qPrev.y >= 0.0f;
        }
        else
        {
            _8236 = _8230;
        }
        bool _8244;
        if (_8236)
        {
            _8244 = qPrev.x < sLotSz.x;
        }
        else
        {
            _8244 = _8236;
        }
        bool _8252;
        if (_8244)
        {
            _8252 = qPrev.y < sLotSz.y;
        }
        else
        {
            _8252 = _8244;
        }
        if (_8252)
        {
            int2 cg0 = clamp(int2(floor(qPrev.xy * 8.0f)), int2(0, 0), (vAoSize - 1).xx);
            int y0 = vAoYBase + cg0.y;
            int m0 = int((voxelMap.Load(int3(int2(cg0.x, y0), 0)).w * 255.0f) + 0.5f);
            if (m0 == 0)
            {
                int dCheb = int((voxelMap.Load(int3(int2(vAoSize + cg0.x, y0), 0)).w * 255.0f) + 0.5f);
                if (dCheb >= 2)
                {
                    float tTarget = min(t + ((float(dCheb - 1) * 0.125f) / sunChebRate), tExit);
                    bool _8319 = tRoof.x <= tRoof.y;
                    bool _8326;
                    if (_8319)
                    {
                        _8326 = tRoof.x > t;
                    }
                    else
                    {
                        _8326 = _8319;
                    }
                    if (_8326)
                    {
                        tTarget = min(tTarget, tRoof.x);
                    }
                    bool _8337 = tSim.x <= tSim.y;
                    bool _8344;
                    if (_8337)
                    {
                        _8344 = tSim.x > t;
                    }
                    else
                    {
                        _8344 = _8337;
                    }
                    if (_8344)
                    {
                        tTarget = min(tTarget, tSim.x);
                    }
                    float param_83 = tTarget - start;
                    float param_84 = dtBase;
                    float param_85 = sCap;
                    float param_86 = relTCap;
                    int jumpIdx_1 = int(floor(rayStepOf(param_83, param_84, param_85, param_86))) - 1;
                    if (jumpIdx_1 > i)
                    {
                        i = jumpIdx_1;
                        continue;
                    }
                }
                continue;
            }
        }
        float3 qMid = here + (sunDir * tMid);
        float3 q = here + (sunDir * tNext);
        float relZPrev = qPrev.z - here.z;
        if ((qMid.z - here.z) > maxCasterH)
        {
            break;
        }
        float startFade = smoothstep(0.0f, dtBase * 1.14999997615814208984375f, tMid - start);
        float distFade = (1.0f - smoothstep(maxReach * 0.86000001430511474609375f, maxReach, tMid)) * startFade;
        bool _8429;
        if (inRoof)
        {
            _8429 = max(qPrev.z, q.z) >= minCanopyZ;
        }
        else
        {
            _8429 = inRoof;
        }
        if (_8429)
        {
            float roofPen = (0.08200000226497650146484375f * tMid) + 0.054999999701976776123046875f;
            float2 param_87 = qMid.xy;
            float param_88 = canopyClearZ;
            float param_89 = qPrev.z;
            float param_90 = q.z;
            float param_91 = roofPen;
            float cOcc = canopyOcclusionAt(param_87, param_88, param_89, param_90, param_91) * distFade;
            roofLit = min(roofLit, 1.0f - cOcc);
            if (roofLit <= 0.004999999888241291046142578125f)
            {
                break;
            }
        }
        if ((inVox || inSim) && (relZPrev <= maxVoxelH))
        {
            float3 dQ = sunDir * stepLen;
            if (inVox)
            {
                bool _8482 = !hasColBounds;
                bool _8508;
                if (!_8482)
                {
                    float2 param_92 = qMid.xy;
                    float param_93 = min(qPrev.z, q.z);
                    float param_94 = max(qPrev.z, q.z);
                    int param_95 = vAoSize;
                    int param_96 = vAoYBase;
                    float2 param_97 = sLotSz;
                    _8508 = voxelColumnOverlap(param_92, param_93, param_94, param_95, param_96, param_97);
                }
                else
                {
                    _8508 = _8482;
                }
                bool checkHull = _8508;
                if (checkHull)
                {
                    bool skipWindow = false;
                    int2 qCell = int2(floor(qMid.xy + ambient_frame.w.xx));
                    if (any(bool2(qCell.x != prevWinCell.x, qCell.y != prevWinCell.y)))
                    {
                        prevWinCell = qCell;
                        int2 param_98 = qCell;
                        int param_99 = 1;
                        int param_100 = 0;
                        int2 param_101 = mSize;
                        int param_102 = mBandH;
                        int param_103 = stories;
                        cachedBaseCode0 = maskCatFast(param_98, param_99, param_100, param_101, param_102, param_103);
                    }
                    int qBaseCode0 = cachedBaseCode0;
                    if (qBaseCode0 != 0)
                    {
                        float qBase0 = ambient_contact.w + (float(qBaseCode0 - 1) / 8.0f);
                        int qRow = clamp(int(floor(((qMid.z - qBase0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f)), 0, stories - 1);
                        int2 param_104 = qCell;
                        int param_105 = 0;
                        int param_106 = qRow;
                        int2 param_107 = mSize;
                        int param_108 = mBandH;
                        int param_109 = stories;
                        if ((maskCatFast(param_104, param_105, param_106, param_107, param_108, param_109) & 1) != 0)
                        {
                            if (qRow == 0)
                            {
                                _8585 = qBaseCode0;
                            }
                            else
                            {
                                int2 param_110 = qCell;
                                int param_111 = 1;
                                int param_112 = qRow;
                                int2 param_113 = mSize;
                                int param_114 = mBandH;
                                int param_115 = stories;
                                _8585 = maskCatFast(param_110, param_111, param_112, param_113, param_114, param_115);
                            }
                            int rCode = _8585;
                            if (rCode != 0)
                            {
                                _8606 = (ambient_contact.w + (float(qRow) * 2.9500000476837158203125f)) + (float(rCode - 1) / 8.0f);
                            }
                            else
                            {
                                _8606 = qBase0 + (float(qRow) * 2.9500000476837158203125f);
                            }
                            float qFloorH = _8606;
                            float qRelH = qMid.z - qFloorH;
                            if ((qRelH > 0.670000016689300537109375f) && (qRelH < 2.4300000667572021484375f))
                            {
                                float2 qFrac = frac(qMid.xy + ambient_frame.w.xx);
                                float edgeDist = min(min(qFrac.x, 1.0f - qFrac.x), min(qFrac.y, 1.0f - qFrac.y));
                                skipWindow = edgeDist < 0.2199999988079071044921875f;
                            }
                        }
                    }
                    if (!skipWindow)
                    {
                        float rTiles = clamp(0.0170000009238719940185546875f + (0.0164999999105930328369140625f * tMid), 0.0170000009238719940185546875f, 0.194999992847442626953125f);
                        float pad = 0.2199999988079071044921875f + (1.0499999523162841796875f * rTiles);
                        float kTop = 0.0599999986588954925537109375f + (0.37999999523162841796875f * rTiles);
                        float3 param_116 = qMid;
                        float3 param_117 = dQ;
                        float3 param_118 = coneU;
                        float3 param_119 = coneV;
                        float param_120 = rTiles;
                        float param_121 = pad;
                        float param_122 = kTop;
                        float param_123 = distFade;
                        int2 param_124 = vSize;
                        int param_125 = vHalfH;
                        float param_126 = vTopMarginHalf;
                        int2 param_127 = vSliceMax;
                        float2 param_128 = sLotSz;
                        float2 param_129 = invVSize;
                        float4 param_130 = laneLit;
                        stepHullCone4(param_116, param_117, param_118, param_119, param_120, param_121, param_122, param_123, param_124, param_125, param_126, param_127, param_128, param_129, param_130);
                        laneLit = param_130;
                    }
                }
            }
            if ((inSim && (tMid >= selfSimGuard)) && (relZPrev <= maxSimH))
            {
                float simGate = smoothstep(selfSimGuard, selfSimGuard + 0.2199999988079071044921875f, tMid) * distFade;
                float rSimPx = clamp(0.3499999940395355224609375f + (0.3400000035762786865234375f * tMid), 0.3499999940395355224609375f, 2.2000000476837158203125f) * wScale;
                float3 param_131 = qMid;
                float3 param_132 = dQ;
                float param_133 = 0.180000007152557373046875f + (0.0199999995529651641845703125f * rSimPx);
                float param_134 = rSimPx;
                float2 param_135 = sunPerp;
                float param_136 = simGate;
                float2 param_137 = wSize;
                float2 param_138 = simLaneLit;
                stepSimCone2(param_131, param_132, param_133, param_134, param_135, param_136, param_137, param_138);
                simLaneLit = param_138;
            }
            float maxLane = max(max(laneLit.x, laneLit.y), max(laneLit.z, laneLit.w));
            float maxSim = max(simLaneLit.x, simLaneLit.y);
            if (min(maxLane, maxSim) <= 0.004999999888241291046142578125f)
            {
                roofLit = 0.0f;
                break;
            }
        }
    }
    float hullVis = dot(laneLit, 0.25f.xxxx);
    float simVis = 0.5f * (simLaneLit.x + simLaneLit.y);
    float combined = min(roofLit, min(hullVis, simVis));
    return float3(combined, combined, 1.0f);
}

void frag_main()
{
    float _8820;
    if (ambient_extent.w > 0.5f)
    {
        _8820 = ambient_extent.w;
    }
    else
    {
        _8820 = 1.0f;
    }
    float ambScale = _8820;
    float2 rawPx = (floor(gl_FragCoord.xy) + 0.5f.xx) * ambScale;
    bool _8841 = rawPx.x >= ambient_extent.x;
    bool _8850;
    if (!_8841)
    {
        _8850 = rawPx.y >= ambient_extent.y;
    }
    else
    {
        _8850 = _8841;
    }
    bool _8857;
    if (!_8850)
    {
        _8857 = ambient_sunLot.w <= 0.0f;
    }
    else
    {
        _8857 = _8850;
    }
    bool _8864;
    if (!_8857)
    {
        _8864 = ambient_params.z <= 0.001000000047497451305389404296875f;
    }
    else
    {
        _8864 = _8857;
    }
    if (_8864)
    {
        color = float4(1.0f, 0.0f, 1.0f, 1.0f);
        return;
    }
    int2 limitPx = max((int2(ambient_extent.xy) - int2(1, 1)), int2(0, 0));
    int2 fullPx = clamp(int2(floor(rawPx)), int2(0, 0), limitPx);
    float2 pixel = float2(fullPx) + 0.5f.xx;
    float2 param = pixel;
    float4 centre = positionAt(param);
    if (centre.w > 0.75f)
    {
        color = float4(1.0f, 0.0f, 1.0f, 1.0f);
        return;
    }
    float3 p = centre.xyz;
    float scale = ambient_view.z;
    uint _8909_dummy_parameter;
    int2 vSize = int2(spvTextureSize(voxelMap, uint(0), _8909_dummy_parameter));
    bool hasVoxels = vSize.x > 1;
    int storiesCount = indoorStories();
    uint _8920_dummy_parameter;
    float4 _8923;
    if (int2(spvTextureSize(liftMap, uint(0), _8920_dummy_parameter)).x > 1)
    {
        _8923 = liftMap.Load(int3(fullPx, 0));
    }
    else
    {
        _8923 = 0.0f.xxxx;
    }
    float4 lift = _8923;
    bool onSnow = lift.z > 0.5f;
    float2 horizN = 0.0f.xx;
    float3 nLot = float3(0.0f, 0.0f, 1.0f);
    float onFlatFloor = 1.0f;
    float isVertical = 0.0f;
    float roofCalm = 0.0f;
    float onDynamicSim = 0.0f;
    float surfFaceLit = 1.0f;
    float selfShadow = 1.0f;
    bool _8947 = centre.w > 0.25f;
    bool _8953;
    if (_8947)
    {
        _8953 = lift.w <= 0.001000000047497451305389404296875f;
    }
    else
    {
        _8953 = _8947;
    }
    float3 hereSurf;
    if (_8953)
    {
        float gKey = ((0.62000000476837158203125f - groundMap.Load(int3(fullPx, 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
        float2 param_1 = p.xy;
        float param_2 = gKey;
        bool param_3 = true;
        float2 param_4 = ambient_frame.xy;
        hereSurf = lotPoint(param_1, param_2, param_3, param_4);
        if (onSnow)
        {
            hereSurf += float3(0.5f * lift.x, 0.5f * lift.x, lift.y);
        }
    }
    else
    {
        bool hasVertGrad = true;
        bool isSprite = centre.w < 0.25f;
        float _9001;
        if (isSprite)
        {
            _9001 = clamp(2.599999904632568359375f * scale, max(2.599999904632568359375f, ambScale * 1.35000002384185791015625f), max(5.5f, 2.599999904632568359375f * scale));
        }
        else
        {
            _9001 = clamp(1.75f * scale, max(1.75f, ambScale), max(4.0f, 1.75f * scale));
        }
        float _step = _9001;
        float maxCont = max(3.5f, (1.35000002384185791015625f * _step) / max(scale, 0.25f));
        float2 param_5 = pixel - float2(_step, 0.0f);
        float4 leftP = positionAt(param_5);
        float2 param_6 = pixel + float2(_step, 0.0f);
        float4 rightP = positionAt(param_6);
        float2 param_7 = pixel - float2(0.0f, _step);
        float4 upP = positionAt(param_7);
        float2 param_8 = pixel + float2(0.0f, _step);
        float4 downP = positionAt(param_8);
        float3 left = leftP.xyz;
        float3 right = rightP.xyz;
        float3 up = upP.xyz;
        float3 down = downP.xyz;
        bool _9078 = leftP.w < 0.75f;
        bool _9086;
        if (_9078)
        {
            _9086 = (leftP.w < 0.25f) == isSprite;
        }
        else
        {
            _9086 = _9078;
        }
        bool _9097;
        if (_9086)
        {
            _9097 = abs(p.z - left.z) < maxCont;
        }
        else
        {
            _9097 = _9086;
        }
        bool lOk = _9097;
        bool _9101 = rightP.w < 0.75f;
        bool _9109;
        if (_9101)
        {
            _9109 = (rightP.w < 0.25f) == isSprite;
        }
        else
        {
            _9109 = _9101;
        }
        bool _9120;
        if (_9109)
        {
            _9120 = abs(right.z - p.z) < maxCont;
        }
        else
        {
            _9120 = _9109;
        }
        bool rOk = _9120;
        bool _9124 = upP.w < 0.75f;
        bool _9132;
        if (_9124)
        {
            _9132 = (upP.w < 0.25f) == isSprite;
        }
        else
        {
            _9132 = _9124;
        }
        bool _9143;
        if (_9132)
        {
            _9143 = abs(p.z - up.z) < maxCont;
        }
        else
        {
            _9143 = _9132;
        }
        bool uOk = _9143;
        bool _9147 = downP.w < 0.75f;
        bool _9155;
        if (_9147)
        {
            _9155 = (downP.w < 0.25f) == isSprite;
        }
        else
        {
            _9155 = _9147;
        }
        bool _9166;
        if (_9155)
        {
            _9166 = abs(down.z - p.z) < maxCont;
        }
        else
        {
            _9166 = _9155;
        }
        bool dOk = _9166;
        float creaseTol = max(2.2000000476837158203125f, (0.550000011920928955078125f * _step) / max(scale, 0.25f));
        float dLx = p.z - left.z;
        float dRx = right.z - p.z;
        float dUy = p.z - up.z;
        float dDy = down.z - p.z;
        bool _9202 = lOk && rOk;
        bool _9211;
        if (_9202)
        {
            _9211 = abs(dRx - dLx) < creaseTol;
        }
        else
        {
            _9211 = _9202;
        }
        bool _9219;
        if (_9211)
        {
            _9219 = (dRx * dLx) >= (-0.0500000007450580596923828125f);
        }
        else
        {
            _9219 = _9211;
        }
        bool xSmooth = _9219;
        bool _9223 = uOk && dOk;
        bool _9232;
        if (_9223)
        {
            _9232 = abs(dDy - dUy) < creaseTol;
        }
        else
        {
            _9232 = _9223;
        }
        bool _9239;
        if (_9232)
        {
            _9239 = (dDy * dUy) >= (-0.0500000007450580596923828125f);
        }
        else
        {
            _9239 = _9232;
        }
        bool ySmooth = _9239;
        float3 _9242;
        if (xSmooth)
        {
            _9242 = (right - left) * 0.5f;
        }
        else
        {
            float3 _9251;
            if (lOk)
            {
                _9251 = p - left;
            }
            else
            {
                float3 _9259;
                if (rOk)
                {
                    _9259 = right - p;
                }
                else
                {
                    _9259 = float3(_step / max(scale, 0.25f), 0.0f, 0.0f);
                }
                _9251 = _9259;
            }
            _9242 = _9251;
        }
        float3 dx = _9242;
        float3 _9276;
        if (ySmooth)
        {
            _9276 = (down - up) * 0.5f;
        }
        else
        {
            float3 _9285;
            if (uOk)
            {
                _9285 = p - up;
            }
            else
            {
                float3 _9293;
                if (dOk)
                {
                    _9293 = down - p;
                }
                else
                {
                    _9293 = float3(0.0f, _step / max(scale, 0.25f), 0.0f);
                }
                _9285 = _9293;
            }
            _9276 = _9285;
        }
        float3 dy = _9276;
        float fineStep = max(1.0f, ambScale);
        bool _9315 = (!lOk) && (!rOk);
        bool _9322;
        if (_9315)
        {
            _9322 = _step > (fineStep + 0.5f);
        }
        else
        {
            _9322 = _9315;
        }
        if (_9322)
        {
            float fineMaxCont = max(1.7999999523162841796875f, (1.35000002384185791015625f * fineStep) / max(scale, 0.25f));
            float2 param_9 = pixel - float2(fineStep, 0.0f);
            float4 lfP = positionAt(param_9);
            float2 param_10 = pixel + float2(fineStep, 0.0f);
            float4 rfP = positionAt(param_10);
            bool _9350 = lfP.w < 0.75f;
            bool _9358;
            if (_9350)
            {
                _9358 = (lfP.w < 0.25f) == isSprite;
            }
            else
            {
                _9358 = _9350;
            }
            bool _9369;
            if (_9358)
            {
                _9369 = abs(p.z - lfP.z) < fineMaxCont;
            }
            else
            {
                _9369 = _9358;
            }
            bool lfOk = _9369;
            bool _9373 = rfP.w < 0.75f;
            bool _9381;
            if (_9373)
            {
                _9381 = (rfP.w < 0.25f) == isSprite;
            }
            else
            {
                _9381 = _9373;
            }
            bool _9392;
            if (_9381)
            {
                _9392 = abs(rfP.z - p.z) < fineMaxCont;
            }
            else
            {
                _9392 = _9381;
            }
            bool rfOk = _9392;
            if (lfOk || rfOk)
            {
                float3 _9401;
                if (lfOk && rfOk)
                {
                    _9401 = (rfP.xyz - lfP.xyz) * 0.5f;
                }
                else
                {
                    float3 _9412;
                    if (lfOk)
                    {
                        _9412 = p - lfP.xyz;
                    }
                    else
                    {
                        _9412 = rfP.xyz - p;
                    }
                    _9401 = _9412;
                }
                dx = _9401;
            }
        }
        hasVertGrad = uOk || dOk;
        bool _9433 = (!uOk) && (!dOk);
        bool _9440;
        if (_9433)
        {
            _9440 = _step > (fineStep + 0.5f);
        }
        else
        {
            _9440 = _9433;
        }
        if (_9440)
        {
            float fineMaxCont_1 = max(1.7999999523162841796875f, (1.35000002384185791015625f * fineStep) / max(scale, 0.25f));
            float2 param_11 = pixel - float2(0.0f, fineStep);
            float4 ufP = positionAt(param_11);
            float2 param_12 = pixel + float2(0.0f, fineStep);
            float4 dfP = positionAt(param_12);
            bool _9467 = ufP.w < 0.75f;
            bool _9481;
            if (_9467)
            {
                bool _9472 = ufP.w < 0.75f;
                bool _9478;
                if (_9472)
                {
                    _9478 = ufP.w < 0.25f;
                }
                else
                {
                    _9478 = _9472;
                }
                _9481 = _9478 == isSprite;
            }
            else
            {
                _9481 = _9467;
            }
            bool _9492;
            if (_9481)
            {
                _9492 = abs(p.z - ufP.z) < fineMaxCont_1;
            }
            else
            {
                _9492 = _9481;
            }
            bool ufOk = _9492;
            bool _9496 = dfP.w < 0.75f;
            bool _9510;
            if (_9496)
            {
                bool _9501 = dfP.w < 0.75f;
                bool _9507;
                if (_9501)
                {
                    _9507 = dfP.w < 0.25f;
                }
                else
                {
                    _9507 = _9501;
                }
                _9510 = _9507 == isSprite;
            }
            else
            {
                _9510 = _9496;
            }
            bool _9521;
            if (_9510)
            {
                _9521 = abs(dfP.z - p.z) < fineMaxCont_1;
            }
            else
            {
                _9521 = _9510;
            }
            bool dfOk = _9521;
            hasVertGrad = ufOk || dfOk;
            if (hasVertGrad)
            {
                float3 _9531;
                if (ufOk && dfOk)
                {
                    _9531 = (dfP.xyz - ufP.xyz) * 0.5f;
                }
                else
                {
                    float3 _9542;
                    if (ufOk)
                    {
                        _9542 = p - ufP.xyz;
                    }
                    else
                    {
                        _9542 = dfP.xyz - p;
                    }
                    _9531 = _9542;
                }
                dy = _9531;
            }
        }
        if (isSprite)
        {
            float step2 = _step * 2.0f;
            float maxCont2 = max(6.0f, (1.5499999523162841796875f * step2) / max(scale, 0.25f));
            float2 param_13 = pixel - float2(step2, 0.0f);
            float4 l2P = positionAt(param_13);
            float2 param_14 = pixel + float2(step2, 0.0f);
            float4 r2P = positionAt(param_14);
            float2 param_15 = pixel - float2(0.0f, step2);
            float4 u2P = positionAt(param_15);
            float2 param_16 = pixel + float2(0.0f, step2);
            float4 d2P = positionAt(param_16);
            float3 l2 = l2P.xyz;
            float3 r2 = r2P.xyz;
            float3 u2 = u2P.xyz;
            float3 d2 = d2P.xyz;
            bool _9616;
            if (lOk)
            {
                _9616 = l2P.w < 0.25f;
            }
            else
            {
                _9616 = lOk;
            }
            bool _9627;
            if (_9616)
            {
                _9627 = abs(left.z - l2.z) < maxCont;
            }
            else
            {
                _9627 = _9616;
            }
            bool _9638;
            if (_9627)
            {
                _9638 = abs(p.z - l2.z) < maxCont2;
            }
            else
            {
                _9638 = _9627;
            }
            bool _9655;
            if (_9638)
            {
                _9655 = abs((p.z - left.z) - (left.z - l2.z)) < creaseTol;
            }
            else
            {
                _9655 = _9638;
            }
            bool l2Ok = _9655;
            bool _9663;
            if (rOk)
            {
                _9663 = r2P.w < 0.25f;
            }
            else
            {
                _9663 = rOk;
            }
            bool _9674;
            if (_9663)
            {
                _9674 = abs(r2.z - right.z) < maxCont;
            }
            else
            {
                _9674 = _9663;
            }
            bool _9685;
            if (_9674)
            {
                _9685 = abs(r2.z - p.z) < maxCont2;
            }
            else
            {
                _9685 = _9674;
            }
            bool _9702;
            if (_9685)
            {
                _9702 = abs((r2.z - right.z) - (right.z - p.z)) < creaseTol;
            }
            else
            {
                _9702 = _9685;
            }
            bool r2Ok = _9702;
            bool _9710;
            if (uOk)
            {
                _9710 = u2P.w < 0.25f;
            }
            else
            {
                _9710 = uOk;
            }
            bool _9721;
            if (_9710)
            {
                _9721 = abs(up.z - u2.z) < maxCont;
            }
            else
            {
                _9721 = _9710;
            }
            bool _9732;
            if (_9721)
            {
                _9732 = abs(p.z - u2.z) < maxCont2;
            }
            else
            {
                _9732 = _9721;
            }
            bool _9749;
            if (_9732)
            {
                _9749 = abs((p.z - up.z) - (up.z - u2.z)) < creaseTol;
            }
            else
            {
                _9749 = _9732;
            }
            bool u2Ok = _9749;
            bool _9757;
            if (dOk)
            {
                _9757 = d2P.w < 0.25f;
            }
            else
            {
                _9757 = dOk;
            }
            bool _9768;
            if (_9757)
            {
                _9768 = abs(d2.z - down.z) < maxCont;
            }
            else
            {
                _9768 = _9757;
            }
            bool _9779;
            if (_9768)
            {
                _9779 = abs(d2.z - p.z) < maxCont2;
            }
            else
            {
                _9779 = _9768;
            }
            bool _9796;
            if (_9779)
            {
                _9796 = abs((d2.z - down.z) - (down.z - p.z)) < creaseTol;
            }
            else
            {
                _9796 = _9779;
            }
            bool d2Ok = _9796;
            if ((xSmooth && l2Ok) && r2Ok)
            {
                dx = (r2 - l2) * 0.25f;
            }
            else
            {
                if (((!xSmooth) && lOk) && rOk)
                {
                    float _9819;
                    if (l2Ok)
                    {
                        _9819 = abs((p.z - left.z) - (left.z - l2.z));
                    }
                    else
                    {
                        _9819 = 10000.0f;
                    }
                    float errL = _9819;
                    float _9839;
                    if (r2Ok)
                    {
                        _9839 = abs((r2.z - right.z) - (right.z - p.z));
                    }
                    else
                    {
                        _9839 = 10000.0f;
                    }
                    float errR = _9839;
                    float3 _9859;
                    if (errR < errL)
                    {
                        float3 _9863;
                        if (r2Ok)
                        {
                            _9863 = (r2 - p) * 0.5f;
                        }
                        else
                        {
                            _9863 = right - p;
                        }
                        _9859 = _9863;
                    }
                    else
                    {
                        float3 _9877;
                        if (l2Ok)
                        {
                            _9877 = (p - l2) * 0.5f;
                        }
                        else
                        {
                            _9877 = p - left;
                        }
                        _9859 = _9877;
                    }
                    dx = _9859;
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
                    float _9912;
                    if (u2Ok)
                    {
                        _9912 = abs((p.z - up.z) - (up.z - u2.z));
                    }
                    else
                    {
                        _9912 = 10000.0f;
                    }
                    float errU = _9912;
                    float _9931;
                    if (d2Ok)
                    {
                        _9931 = abs((d2.z - down.z) - (down.z - p.z));
                    }
                    else
                    {
                        _9931 = 10000.0f;
                    }
                    float errD = _9931;
                    float3 _9951;
                    if (errD < errU)
                    {
                        float3 _9955;
                        if (d2Ok)
                        {
                            _9955 = (d2 - p) * 0.5f;
                        }
                        else
                        {
                            _9955 = down - p;
                        }
                        _9951 = _9955;
                    }
                    else
                    {
                        float3 _9969;
                        if (u2Ok)
                        {
                            _9969 = (p - u2) * 0.5f;
                        }
                        else
                        {
                            _9969 = p - up;
                        }
                        _9951 = _9969;
                    }
                    dy = _9951;
                }
            }
        }
        float3 rawCross = cross(dy, dx);
        float rawLen = length(rawCross);
        float3 _9992;
        if (rawLen > 9.9999997473787516355514526367188e-06f)
        {
            _9992 = rawCross / rawLen.xxx;
        }
        else
        {
            _9992 = float3(0.0f, 0.0f, 1.0f);
        }
        float3 n = _9992;
        if (n.z < 0.0f)
        {
            n = -n;
        }
        float3 nSurf = n;
        float3 _10014;
        if (centre.w > 0.25f)
        {
            _10014 = n;
        }
        else
        {
            _10014 = normalize(lerp(n, float3(0.0f, 0.0f, 1.0f), 0.25f.xxx));
        }
        float3 normal = _10014;
        float _10028;
        if (centre.w < 0.25f)
        {
            _10028 = (0.62000000476837158203125f - depthMap.Load(int3(fullPx, 0)).x) / 0.0030000000260770320892333984375f;
        }
        else
        {
            _10028 = ((0.62000000476837158203125f - groundMap.Load(int3(fullPx, 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
        }
        float key = _10028;
        float2 param_17 = p.xy;
        float param_18 = key;
        bool param_19 = centre.w > 0.25f;
        float2 param_20 = ambient_frame.xy;
        float3 here = lotPoint(param_17, param_18, param_19, param_20);
        float riseHere;
        if (centre.w > 0.25f)
        {
            riseHere = 0.0f;
        }
        else
        {
            uint _10074_dummy_parameter;
            if (int2(spvTextureSize(overheadMap, uint(0), _10074_dummy_parameter)).x > 1)
            {
                float2 param_21 = pixel;
                float gAtHere = groundAt(param_21);
                float _10086;
                if (gAtHere > (-10000.0f))
                {
                    float2 param_22 = p.xy;
                    float param_23 = gAtHere / 27.7128124237060546875f;
                    bool param_24 = true;
                    float2 param_25 = ambient_frame.xy;
                    _10086 = lotPoint(param_22, param_23, param_24, param_25).z;
                }
                else
                {
                    float2 param_26 = here.xy;
                    float param_27 = ambient_contact.w;
                    _10086 = terrainBaseClamped(param_26, param_27);
                }
                float fallbackBaseZ = _10086;
                float2 param_28 = here.xy;
                float param_29 = fallbackBaseZ;
                float groundBaseZ = terrainBaseAt(param_28, param_29);
                riseHere = max(0.0f, here.z - groundBaseZ) * 40.0f;
            }
            else
            {
                float2 param_30 = pixel;
                bool _10128 = groundAt(param_30) < (-10000.0f);
                bool _10137;
                if (!_10128)
                {
                    float2 param_31 = pixel + float2(0.0f, 4.0f);
                    _10137 = groundAt(param_31) < (-10000.0f);
                }
                else
                {
                    _10137 = _10128;
                }
                float _10138;
                if (_10137)
                {
                    _10138 = max(20.0f, (here.z - ambient_contact.w) * 40.0f);
                }
                else
                {
                    float2 param_32 = pixel;
                    float param_33 = p.z;
                    _10138 = riseAt(param_32, param_33);
                }
                riseHere = _10138;
            }
        }
        float onGround = 1.0f - smoothstep(2.0f, 6.0f, riseHere);
        if (onSnow)
        {
            here += float3(0.5f * lift.x, 0.5f * lift.x, lift.y);
            onGround = 1.0f;
        }
        int2 hereCell = int2(floor(here.xy + ambient_frame.w.xx));
        int2 param_34 = hereCell;
        int param_35 = 0;
        float param_36 = here.z;
        float hereBase0 = floorAt(param_34, param_35, param_36);
        int candUpperRow = clamp(int(floor(((here.z - hereBase0) / 2.9500000476837158203125f) + 0.5f)), 1, max(1, (storiesCount - 1)));
        float _10208;
        if (candUpperRow < storiesCount)
        {
            int2 param_37 = hereCell;
            int param_38 = candUpperRow;
            float param_39 = -100.0f;
            _10208 = floorAt(param_37, param_38, param_39);
        }
        else
        {
            _10208 = -100.0f;
        }
        float floor2Z = _10208;
        float _10224;
        if (floor2Z > (-50.0f))
        {
            _10224 = (1.0f - smoothstep(0.07999999821186065673828125f, 0.2199999988079071044921875f, abs(here.z - floor2Z))) * smoothstep(0.550000011920928955078125f, 0.819999992847442626953125f, dot(nSurf, float3(0.0f, -0.866025388240814208984375f, 0.5f)));
        }
        else
        {
            _10224 = 0.0f;
        }
        float onLevel2Floor = _10224;
        onFlatFloor = max(onGround, onLevel2Floor);
        bool _10249 = centre.w < 0.25f;
        bool _10258;
        if (_10249)
        {
            uint _10255_dummy_parameter;
            _10258 = int2(spvTextureSize(simMaskMap, uint(0), _10255_dummy_parameter)).x > 1;
        }
        else
        {
            _10258 = _10249;
        }
        float _10259;
        if (_10258)
        {
            _10259 = simMaskMap.Sample(_simMaskMap_sampler, pixel / ambient_extent.xy).x;
        }
        else
        {
            _10259 = 0.0f;
        }
        float simMaskVal = _10259;
        onDynamicSim = smoothstep(0.100000001490116119384765625f, 0.449999988079071044921875f, simMaskVal);
        bool _10278 = (onDynamicSim < 0.9900000095367431640625f) && hasVoxels;
        bool _10284;
        if (_10278)
        {
            _10284 = ambient_shadowView.w > 0.5f;
        }
        else
        {
            _10284 = _10278;
        }
        bool _10290;
        if (_10284)
        {
            _10290 = centre.w < 0.25f;
        }
        else
        {
            _10290 = _10284;
        }
        if (_10290)
        {
            float2 wpSelf = ambient_shadowView.xy + (p.xy * ambient_shadowView.z);
            bool _10307 = wpSelf.x >= ambient_dynShadowBounds.x;
            bool _10315;
            if (_10307)
            {
                _10315 = wpSelf.y >= ambient_dynShadowBounds.y;
            }
            else
            {
                _10315 = _10307;
            }
            bool _10323;
            if (_10315)
            {
                _10323 = wpSelf.x <= ambient_dynShadowBounds.z;
            }
            else
            {
                _10323 = _10315;
            }
            bool _10331;
            if (_10323)
            {
                _10331 = wpSelf.y <= ambient_dynShadowBounds.w;
            }
            else
            {
                _10331 = _10323;
            }
            if (_10331)
            {
                uint _10337_dummy_parameter;
                float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _10337_dummy_parameter)));
                bool _10341 = all(bool2(wpSelf.x >= 0.0f.xx.x, wpSelf.y >= 0.0f.xx.y));
                bool _10348;
                if (_10341)
                {
                    _10348 = all(bool2(wpSelf.x < wSize.x, wpSelf.y < wSize.y));
                }
                else
                {
                    _10348 = _10341;
                }
                if (_10348)
                {
                    float wSelf = worldDepthMap.Load(int3(clamp(int2(floor(wpSelf)), int2(0, 0), int2(wSize) - int2(1, 1)), 0)).x;
                    bool _10365 = wSelf < 0.99989998340606689453125f;
                    bool _10375;
                    if (_10365)
                    {
                        _10375 = abs(((0.62000000476837158203125f - wSelf) / 0.0030000000260770320892333984375f) - key) < 0.550000011920928955078125f;
                    }
                    else
                    {
                        _10375 = _10365;
                    }
                    if (_10375)
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
        bool _10386 = !onSnow;
        bool _10392;
        if (_10386)
        {
            _10392 = centre.w < 0.25f;
        }
        else
        {
            _10392 = _10386;
        }
        if (((_10392 && (onFlatFloor < 0.5f)) && (onDynamicSim < 0.5f)) && (roofSnow < 0.5f))
        {
            float _10406;
            if (hasVertGrad)
            {
                _10406 = dot(nSurf, float3(0.0f, -0.866025388240814208984375f, 0.5f));
            }
            else
            {
                _10406 = 0.0f;
            }
            float upCheck = _10406;
            float wallStoryRel = max(0.0f, (here.z - hereBase0) - (floor(max(0.0f, (here.z - hereBase0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f) * 2.9500000476837158203125f));
            float midWallBand = smoothstep(0.4600000083446502685546875f, 0.60000002384185791015625f, wallStoryRel) * (1.0f - smoothstep(2.6700000762939453125f, 2.809999942779541015625f, wallStoryRel));
            float upLo = lerp(0.2800000011920928955078125f, 0.560000002384185791015625f, midWallBand);
            float upHi = lerp(0.439999997615814208984375f, 0.7200000286102294921875f, midWallBand);
            if (upCheck < upHi)
            {
                float3 param_40 = here;
                float2 param_41 = p.xy;
                float param_42 = key;
                float param_43 = nSurf.x;
                float3 param_44;
                float2 param_45;
                float _10465 = matchArchWall(param_40, param_41, param_42, param_43, param_44, param_45);
                matchedWallPos = param_44;
                matchedWallN = param_45;
                archWallMatch = _10465;
                if (archWallMatch > 0.001000000047497451305389404296875f)
                {
                    archWallMatch *= (1.0f - smoothstep(upLo, upHi, upCheck));
                    float2 wallPlaneXY = matchedWallPos.xy - (matchedWallN * 0.0350000001490116119384765625f);
                    float frontOfWall = smoothstep(-0.02500000037252902984619140625f, 0.0199999995529651641845703125f, dot(here.xy - wallPlaneXY, matchedWallN));
                    if (hasVoxels && (frontOfWall > 0.001000000047497451305389404296875f))
                    {
                        int2 param_46 = vSize;
                        int vAoRows = voxelAoRows(param_46);
                        int vHalfH = ((vSize.x / 2) + 128) + (256 * vAoRows);
                        float vTopMarginHalf = float(64 + (256 * vAoRows));
                        int2 vSliceMax = int2(vSize.x - 1, vHalfH - 1);
                        float2 lotSz = max(ambient_drift.zw, 1.0f.xx);
                        float3 hullProbe = float3(wallPlaneXY + (matchedWallN * 0.14000000059604644775390625f), here.z);
                        float3 param_47 = hullProbe;
                        int2 param_48 = vSize;
                        int param_49 = vHalfH;
                        float param_50 = vTopMarginHalf;
                        int2 param_51 = vSliceMax;
                        float2 param_52 = lotSz;
                        float param_53 = 0.0900000035762786865234375f;
                        float selfHull = frontOfWall * dualViewHullSolid(param_47, param_48, param_49, param_50, param_51, param_52, param_53);
                        archWallMatch *= (1.0f - smoothstep(0.20000000298023223876953125f, 0.680000007152557373046875f, selfHull));
                    }
                }
            }
        }
        bool _10570 = ((!onSnow) && hasVertGrad) && (archWallMatch < 0.5f);
        bool _10576;
        if (_10570)
        {
            _10576 = centre.w < 0.25f;
        }
        else
        {
            _10576 = _10570;
        }
        bool _10583 = (_10576 && (onLevel2Floor < 0.25f)) && (riseHere > 115.0f);
        bool _10590;
        if (_10583)
        {
            float3 param_54 = here;
            _10590 = indoors(param_54) < 0.20000000298023223876953125f;
        }
        else
        {
            _10590 = _10583;
        }
        float _10591;
        if (_10590)
        {
            _10591 = (smoothstep(115.0f, 124.0f, riseHere) * smoothstep(0.319999992847442626953125f, 0.60000002384185791015625f, dot(normal, float3(0.0f, -0.866025388240814208984375f, 0.5f)))) * (1.0f - archWallMatch);
        }
        else
        {
            _10591 = 0.0f;
        }
        float highRoof = _10591;
        roofCalm = clamp(max(roofSnow, highRoof), 0.0f, 1.0f);
        float nUp = dot(nSurf, float3(0.0f, -0.866025388240814208984375f, 0.5f));
        float nToward = dot(nSurf, float3(0.0f, 0.5f, 0.866025388240814208984375f));
        float nRight = nSurf.x;
        nLot = float3((nToward + nRight) * 0.707106769084930419921875f, (nToward - nRight) * 0.707106769084930419921875f, nUp);
        float2 _10636;
        if (length(nLot.xy) > 0.1500000059604644775390625f)
        {
            _10636 = normalize(nLot.xy);
        }
        else
        {
            _10636 = 0.0f.xx;
        }
        horizN = _10636;
        hereSurf = here;
        if (archWallMatch > 0.001000000047497451305389404296875f)
        {
            isVertical = ((archWallMatch * (1.0f - onFlatFloor)) * (1.0f - roofCalm)) * (1.0f - onDynamicSim);
            hereSurf = lerp(here, matchedWallPos, archWallMatch.xxx);
            horizN = matchedWallN;
            float3 wallViewN = normalize((float3(0.0f, 0.5f, 0.866025388240814208984375f) * ((matchedWallN.x + matchedWallN.y) * 0.707106769084930419921875f)) + float3((matchedWallN.x - matchedWallN.y) * 0.707106769084930419921875f, 0.0f, 0.0f));
            nSurf = normalize(lerp(nSurf, wallViewN, archWallMatch.xxx));
            nLot = float3(matchedWallN, 0.0f);
        }
        float3 sunView = normalize(ambient_light.xyz + float3(0.0f, 0.0f, 9.9999997473787516355514526367188e-05f));
        float faceLit = smoothstep(-0.07999999821186065673828125f, 0.2199999988079071044921875f, dot(nSurf, sunView));
        float sunHorizLen = length(ambient_sunLot.xy);
        float2 _10713;
        if (sunHorizLen > 9.9999997473787516355514526367188e-05f)
        {
            _10713 = ambient_sunLot.xy / sunHorizLen.xx;
        }
        else
        {
            _10713 = float2(1.0f, 0.0f);
        }
        float2 sunDirXY = _10713;
        float _10728;
        if (length(horizN) > 0.5f)
        {
            _10728 = smoothstep(0.0f, 0.20000000298023223876953125f, dot(horizN, sunDirXY));
        }
        else
        {
            _10728 = faceLit;
        }
        float vertFaceLit = _10728;
        surfFaceLit = lerp(faceLit, vertFaceLit, isVertical);
        selfShadow = lerp(1.0f, surfFaceLit, max(isVertical, roofCalm));
        if (selfShadow <= 0.00999999977648258209228515625f)
        {
            color = float4(0.0f, 0.0f, 0.0f, 1.0f);
            return;
        }
    }
    float3 param_55 = hereSurf;
    float param_56 = onFlatFloor;
    float2 param_57 = lerp(horizN, 0.0f.xx, onDynamicSim.xx);
    float2 wall = wallRay(param_55, param_56, param_57);
    if (wall.x <= 0.00999999977648258209228515625f)
    {
        color = float4(0.0f, 0.0f, 0.0f, 1.0f);
        return;
    }
    float2 param_58 = hereSurf.xy;
    float param_59 = hereSurf.z;
    float hereRelZ = hereSurf.z - terrainBaseAt(param_58, param_59);
    float3 marchOrigin = (hereSurf + float3(horizN * (0.20000000298023223876953125f * isVertical), 0.0f)) + (nLot * (0.180000007152557373046875f * roofCalm));
    float marchStart = lerp(lerp(0.64999997615814208984375f, 0.180000007152557373046875f, roofCalm), 0.1599999964237213134765625f, isVertical);
    marchStart = lerp(marchStart, 0.0599999986588954925537109375f, onFlatFloor);
    float selfSimGuard = lerp(0.100000001490116119384765625f, 0.62000000476837158203125f, onDynamicSim);
    float canopyClearZ = hereRelZ + lerp(0.20000000298023223876953125f, -0.0500000007450580596923828125f, isVertical);
    float3 param_60 = marchOrigin;
    float param_61 = marchStart;
    float param_62 = canopyClearZ;
    float param_63 = selfSimGuard;
    int2 param_64 = vSize;
    int param_65 = storiesCount;
    float3 march = sunMarchFast(param_60, param_61, param_62, param_63, param_64, param_65);
    float lit = min(min(wall.x, march.x), selfShadow);
    float window = 0.0f;
    bool _10837 = wall.y > 0.001000000047497451305389404296875f;
    bool _10843;
    if (_10837)
    {
        _10843 = march.x > 0.001000000047497451305389404296875f;
    }
    else
    {
        _10843 = _10837;
    }
    if (_10843)
    {
        float2 insideOffset = lerp(horizN * 0.25f, 0.0f.xx, onFlatFloor.xx);
        float3 param_66 = hereSurf + float3(insideOffset, 0.0f);
        float inside = indoors(param_66);
        window = ((inside * max(onFlatFloor, isVertical * surfFaceLit)) * wall.y) * march.x;
    }
    color = float4(lit, window, min(min(wall.x, march.y), selfShadow), march.z);
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
