static const float2 _4339[4] = { float2(0.4199999868869781494140625f, 0.0f), float2(-0.4199999868869781494140625f, 0.0f), float2(0.0f, 0.4199999868869781494140625f), float2(0.0f, -0.4199999868869781494140625f) };

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

Texture2D<float4> indoorMap : register(t3, space2);
SamplerState _indoorMap_sampler : register(s3, space2);
Texture2D<float4> overheadMap : register(t4, space2);
SamplerState _overheadMap_sampler : register(s4, space2);
Texture2D<float4> voxelMap : register(t5, space2);
SamplerState _voxelMap_sampler : register(s5, space2);
Texture2D<float4> heightMap : register(t2, space2);
SamplerState _heightMap_sampler : register(s2, space2);
Texture2D<float4> depthMap : register(t0, space2);
SamplerState _depthMap_sampler : register(s0, space2);
Texture2D<float4> sceneColorMap : register(t6, space2);
SamplerState _sceneColorMap_sampler : register(s6, space2);
Texture2D<float4> groundMap : register(t1, space2);
SamplerState _groundMap_sampler : register(s1, space2);

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

int indoorBandH(int2 size)
{
    if (size.x <= 1)
    {
        return max(1, (size.y / 10));
    }
    int orient = int(ambient_clouds.z + 0.5f);
    int _305;
    if ((orient & 1) == 0)
    {
        _305 = int(ambient_drift.w + 0.5f);
    }
    else
    {
        _305 = int(ambient_drift.z + 0.5f);
    }
    int hTiles = _305;
    int margin = int(ambient_frame.w + 0.5f);
    int _327;
    if (hTiles > 0)
    {
        _327 = hTiles + (2 * margin);
    }
    else
    {
        _327 = size.x;
    }
    return _327;
}

int indoorStories()
{
    uint _348_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _348_dummy_parameter));
    int2 param = size;
    int bandH = indoorBandH(param);
    return max(1, (size.y / max(1, (5 * bandH))));
}

int maskCatFast(int2 at, int cat, int row, int2 size, int bandH, int stories)
{
    bool _368 = (row < 0) || (row >= stories);
    bool _375;
    if (!_368)
    {
        _375 = at.x < 0;
    }
    else
    {
        _375 = _368;
    }
    bool _382;
    if (!_375)
    {
        _382 = at.y < 0;
    }
    else
    {
        _382 = _375;
    }
    bool _391;
    if (!_382)
    {
        _391 = at.x >= size.x;
    }
    else
    {
        _391 = _382;
    }
    bool _399;
    if (!_391)
    {
        _399 = at.y >= bandH;
    }
    else
    {
        _399 = _391;
    }
    if (_399)
    {
        return 0;
    }
    int band = (cat * stories) + row;
    bool _410 = band < 0;
    bool _421;
    if (!_410)
    {
        _421 = ((band + 1) * bandH) > size.y;
    }
    else
    {
        _421 = _410;
    }
    if (_421)
    {
        return 0;
    }
    return int((indoorMap.Load(int3(int2(at.x, at.y + (band * bandH)), 0)).x * 255.0f) + 0.5f);
}

int maskCatAt(int2 at, int cat, int row)
{
    uint _447_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _447_dummy_parameter));
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
    float2 _2412;
    if (part == 1)
    {
        _2412 = float2(1.0f, -1.0f);
    }
    else
    {
        float2 _2418;
        if (part == 2)
        {
            _2418 = float2(-1.0f, 1.0f);
        }
        else
        {
            bool2 _2424 = (part == 3).xx;
            _2418 = float2(_2424.x ? (-1.0f).xx.x : 1.0f.xx.x, _2424.y ? (-1.0f).xx.y : 1.0f.xx.y);
        }
        _2412 = _2418;
    }
    float2 toward = _2412;
    return dot(localU - 0.5f.xx, toward) >= 0.0f;
}

float terrainBaseClamped(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    bool _611 = size.x <= 0.0f;
    bool _618;
    if (!_611)
    {
        _618 = size.y <= 0.0f;
    }
    else
    {
        _618 = _611;
    }
    if (_618)
    {
        return fallback;
    }
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _631;
    if (orientation == 1)
    {
        _631 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _645;
        if (orientation == 2)
        {
            _645 = size - _point;
        }
        else
        {
            float2 _654;
            if (orientation == 3)
            {
                _654 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _654 = _point;
            }
            _645 = _654;
        }
        _631 = _645;
    }
    float2 source = _631;
    uint _674_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _674_dummy_parameter));
    bool _681 = mapSize.y >= (mapSize.x * 2);
    bool _687;
    if (_681)
    {
        _687 = mapSize.x > 1;
    }
    else
    {
        _687 = _681;
    }
    int2 _688;
    if (_687)
    {
        _688 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _688 = mapSize;
    }
    int2 baseSize = _688;
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

float floorAt(int2 at, int row, float fallback)
{
    int2 param = at;
    int param_1 = 1;
    int param_2 = row;
    int code = maskCatAt(param, param_1, param_2);
    float _484;
    if (code == 0)
    {
        _484 = fallback;
    }
    else
    {
        _484 = (ambient_contact.w + (float(row) * 2.9500000476837158203125f)) + (float(code - 1) / 8.0f);
    }
    return _484;
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
    float2 _2355;
    if (part == 1)
    {
        _2355 = float2(1.0f, -1.0f);
    }
    else
    {
        float2 _2362;
        if (part == 2)
        {
            _2362 = float2(-1.0f, 1.0f);
        }
        else
        {
            bool2 _2370 = (part == 3).xx;
            _2362 = float2(_2370.x ? (-1.0f).xx.x : 1.0f.xx.x, _2370.y ? (-1.0f).xx.y : 1.0f.xx.y);
        }
        _2355 = _2362;
    }
    float2 toward = _2355;
    return (dot(localU - 0.5f.xx, toward) >= 0.0f) ? room : 0;
}

float2 sceneOf(float3 q)
{
    return float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
}

float3 lotPoint(float2 scene, float key, bool terrain, float2 frame)
{
    float2 local = scene - frame;
    float _168;
    if (terrain)
    {
        _168 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _168 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _168;
    float _192;
    if (terrain)
    {
        _192 = key;
    }
    else
    {
        _192 = key - (0.800000011920928955078125f * h);
    }
    float s = _192;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

bool trySampleVisibleAlbedo(float3 q, bool allowGround, out float3 outAlb)
{
    outAlb = 0.0f.xxx;
    float3 param = q;
    float2 sc = sceneOf(param);
    float2 px = floor(ambient_view.xy + (sc * ambient_view.z)) + 0.5f.xx;
    bool _3933 = any(bool2(px.x < 0.0f.xx.x, px.y < 0.0f.xx.y));
    bool _3942;
    if (!_3933)
    {
        _3942 = px.x >= ambient_extent.x;
    }
    else
    {
        _3942 = _3933;
    }
    bool _3951;
    if (!_3942)
    {
        _3951 = px.y >= ambient_extent.y;
    }
    else
    {
        _3951 = _3942;
    }
    if (_3951)
    {
        return false;
    }
    int2 ip = int2(px);
    float expKey = (q.x + q.y) + (0.800000011920928955078125f * q.z);
    float d = depthMap.Load(int3(ip, 0)).x;
    if (d < 1.0f)
    {
        float obsKey = (0.62000000476837158203125f - d) / 0.0030000000260770320892333984375f;
        if (abs(obsKey - expKey) > 0.60000002384185791015625f)
        {
            return false;
        }
        float4 s = sceneColorMap.Load(int3(ip, 0));
        if (s.w < 0.0500000007450580596923828125f)
        {
            return false;
        }
        outAlb = clamp(s.xyz, 0.039999999105930328369140625f.xxx, 0.86000001430511474609375f.xxx);
        return true;
    }
    if (!allowGround)
    {
        return false;
    }
    float g = groundMap.Load(int3(ip, 0)).x;
    if (g >= 1.0f)
    {
        return false;
    }
    float2 param_1 = sc;
    float param_2 = ((0.62000000476837158203125f - g) / 0.0030000000260770320892333984375f) + ambient_view.w;
    bool param_3 = true;
    float2 param_4 = ambient_frame.xy;
    float3 gl = lotPoint(param_1, param_2, param_3, param_4);
    if (abs(((gl.x + gl.y) + (0.800000011920928955078125f * gl.z)) - expKey) > 0.5f)
    {
        return false;
    }
    float4 s_1 = sceneColorMap.Load(int3(ip, 0));
    if (s_1.w < 0.0500000007450580596923828125f)
    {
        return false;
    }
    outAlb = clamp(s_1.xyz, 0.039999999105930328369140625f.xxx, 0.86000001430511474609375f.xxx);
    return true;
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

int voxelAoRows(int2 oSize)
{
    int aoSize = max(1, (oSize.x / 4));
    return max(1, (((oSize.y - oSize.x) - 256) / (512 + aoSize)));
}

float3 bounceWallRay(float3 here)
{
    float3 sun = ambient_sunLot.xyz;
    float across = length(sun.xy);
    if (across < 0.001000000047497451305389404296875f)
    {
        return float3(1.0f, 0.0f, 0.0f);
    }
    uint _2902_dummy_parameter;
    int2 maskTexSize = int2(spvTextureSize(indoorMap, uint(0), _2902_dummy_parameter));
    int2 param = maskTexSize;
    int maskBandH = indoorBandH(param);
    int stories = max(1, (maskTexSize.y / max(1, (5 * maskBandH))));
    float2 direction = sun.xy / across.xx;
    float rise = sun.z / across;
    float2 start = here.xy + ambient_frame.w.xx;
    int2 cell = int2(floor(start));
    int2 stepDir = int2(sign(direction));
    float2 safeDir = direction + (float2(bool2(direction.x == 0.0f.xx.x, direction.y == 0.0f.xx.y)) * 9.9999997473787516355514526367188e-06f);
    float2 delta = abs(1.0f.xx / safeDir);
    float2 next = ((float2(cell) + max(float2(stepDir), 0.0f.xx)) - start) / safeDir;
    float maxReachH = min((ambient_sunLot.w * across) + 0.25f, 16.0f);
    float vis = 1.0f;
    float winHit = 0.0f;
    float exitT = 0.0f;
    float _3047;
    int2 _3072;
    float _3117;
    float2 _3155;
    int _3171;
    int _3192;
    float _3316;
    for (int i = 0; i < 24; i++)
    {
        bool _2987 = cell.x < 0;
        bool _2993;
        if (_2987)
        {
            _2993 = stepDir.x <= 0;
        }
        else
        {
            _2993 = _2987;
        }
        bool _3008;
        if (!_2993)
        {
            bool _3001 = cell.x >= maskTexSize.x;
            bool _3007;
            if (_3001)
            {
                _3007 = stepDir.x >= 0;
            }
            else
            {
                _3007 = _3001;
            }
            _3008 = _3007;
        }
        else
        {
            _3008 = _2993;
        }
        bool _3021;
        if (!_3008)
        {
            bool _3014 = cell.y < 0;
            bool _3020;
            if (_3014)
            {
                _3020 = stepDir.y <= 0;
            }
            else
            {
                _3020 = _3014;
            }
            _3021 = _3020;
        }
        else
        {
            _3021 = _3008;
        }
        bool _3035;
        if (!_3021)
        {
            bool _3028 = cell.y >= maskBandH;
            bool _3034;
            if (_3028)
            {
                _3034 = stepDir.y >= 0;
            }
            else
            {
                _3034 = _3028;
            }
            _3035 = _3034;
        }
        else
        {
            _3035 = _3021;
        }
        if (_3035)
        {
            break;
        }
        bool alongX = next.x < next.y;
        if (alongX)
        {
            _3047 = next.x;
        }
        else
        {
            _3047 = next.y;
        }
        float t = _3047;
        if (t > maxReachH)
        {
            break;
        }
        float zCross = here.z + (t * rise);
        if (alongX)
        {
            _3072 = int2(stepDir.x, 0);
        }
        else
        {
            _3072 = int2(0, stepDir.y);
        }
        int2 to = cell + _3072;
        int2 param_1 = cell;
        int param_2 = 1;
        int param_3 = 0;
        int2 param_4 = maskTexSize;
        int param_5 = maskBandH;
        int param_6 = stories;
        int cellCode0 = maskCatFast(param_1, param_2, param_3, param_4, param_5, param_6);
        int2 param_7 = to;
        int param_8 = 1;
        int param_9 = 0;
        int2 param_10 = maskTexSize;
        int param_11 = maskBandH;
        int param_12 = stories;
        int toCode0 = maskCatFast(param_7, param_8, param_9, param_10, param_11, param_12);
        if ((cellCode0 | toCode0) != 0)
        {
            if (cellCode0 != 0)
            {
                _3117 = ambient_contact.w + (float(cellCode0 - 1) / 8.0f);
            }
            else
            {
                _3117 = ambient_contact.w + (float(toCode0 - 1) / 8.0f);
            }
            float base0 = _3117;
            int wRow = clamp(int(floor(((zCross - base0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f)), 0, stories - 1);
            float2 crossing = start + (direction * t);
            if (alongX)
            {
                _3155 = float2(float(stepDir.x), 0.0f);
            }
            else
            {
                _3155 = float2(0.0f, float(stepDir.y));
            }
            float2 edgeStep = _3155;
            if (cellCode0 != 0)
            {
                int2 param_13 = cell;
                int param_14 = wRow;
                float2 param_15 = (crossing - float2(cell)) - (edgeStep * 0.00999999977648258209228515625f);
                _3171 = effectiveRoomAt(param_13, param_14, param_15);
            }
            else
            {
                _3171 = 0;
            }
            int rA = _3171;
            if (toCode0 != 0)
            {
                int2 param_16 = to;
                int param_17 = wRow;
                float2 param_18 = (crossing - float2(to)) + (edgeStep * 0.00999999977648258209228515625f);
                _3192 = effectiveRoomAt(param_16, param_17, param_18);
            }
            else
            {
                _3192 = 0;
            }
            int rB = _3192;
            bool _3212 = rA != rB;
            bool _3220;
            if (_3212)
            {
                _3220 = (rA > 0) || (rB > 0);
            }
            else
            {
                _3220 = _3212;
            }
            if (_3220)
            {
                int2 param_19 = to;
                int param_20 = wRow;
                float param_21 = base0 + (float(wRow) * 2.9500000476837158203125f);
                int2 param_22 = cell;
                int param_23 = wRow;
                float param_24 = floorAt(param_19, param_20, param_21);
                float wallTop = floorAt(param_22, param_23, param_24) + 2.9500000476837158203125f;
                if ((here.z < (wallTop - 0.119999997317790985107421875f)) && (zCross < wallTop))
                {
                    float winOpen = 0.0f;
                    int2 param_25 = cell;
                    int param_26 = 0;
                    int param_27 = wRow;
                    int2 param_28 = maskTexSize;
                    int param_29 = maskBandH;
                    int param_30 = stories;
                    int cM = maskCatFast(param_25, param_26, param_27, param_28, param_29, param_30);
                    int2 param_31 = to;
                    int param_32 = 0;
                    int param_33 = wRow;
                    int2 param_34 = maskTexSize;
                    int param_35 = maskBandH;
                    int param_36 = stories;
                    int nM = maskCatFast(param_31, param_32, param_33, param_34, param_35, param_36);
                    bool _3283 = (cM & 1) != 0;
                    bool _3289;
                    if (_3283)
                    {
                        _3289 = (nM & 1) != 0;
                    }
                    else
                    {
                        _3289 = _3283;
                    }
                    if (_3289)
                    {
                        int2 param_37 = to;
                        int param_38 = wRow;
                        float param_39 = base0 + (float(wRow) * 2.9500000476837158203125f);
                        int2 param_40 = cell;
                        int param_41 = wRow;
                        float param_42 = floorAt(param_37, param_38, param_39);
                        float winFloor = floorAt(param_40, param_41, param_42);
                        float relH = zCross - winFloor;
                        if (alongX)
                        {
                            _3316 = crossing.y;
                        }
                        else
                        {
                            _3316 = crossing.x;
                        }
                        float along = frac(_3316);
                        winOpen = ((smoothstep(0.62999999523162841796875f, 0.829999983310699462890625f, relH) * (1.0f - smoothstep(2.269999980926513671875f, 2.4700000286102294921875f, relH))) * smoothstep(0.0599999986588954925537109375f, 0.180000007152557373046875f, along)) * smoothstep(0.0599999986588954925537109375f, 0.180000007152557373046875f, 1.0f - along);
                    }
                    vis = min(vis, winOpen);
                    winHit = max(winHit, winOpen);
                    if (rB == 0)
                    {
                        exitT = max(exitT, t);
                    }
                    if (vis <= 0.0199999995529651641845703125f)
                    {
                        break;
                    }
                }
            }
        }
        cell = to;
        if (alongX)
        {
            next.x += delta.x;
        }
        else
        {
            next.y += delta.y;
        }
    }
    return float3(vis, winHit * vis, exitT / across);
}

float canopyBlockedTexel(int4 data, int slabMask16, bool hasBand1, float canopyClearZ, float qPrevZ, float qZ, float pen, float smoothRoofTop)
{
    bool _764 = data.w == 0;
    bool _772;
    if (!_764)
    {
        _772 = data.w == 255;
    }
    else
    {
        _772 = _764;
    }
    if (_772)
    {
        return 0.0f;
    }
    bool hasCeil1 = (data.x & 32) != 0;
    bool hasAnyUpper = (data.x & 64) != 0;
    bool _792 = (!hasCeil1) && (!hasAnyUpper);
    bool _798;
    if (_792)
    {
        _798 = data.w <= 1;
    }
    else
    {
        _798 = _792;
    }
    if (_798)
    {
        return 0.0f;
    }
    float qBase = float(((data.y * 256) + data.z) - 32768) / 256.0f;
    float prevRel = qPrevZ - qBase;
    float curRel = qZ - qBase;
    float topScale = hasBand1 ? 4.0f : 8.0f;
    float _828;
    if (data.w >= 2)
    {
        float _833;
        if (smoothRoofTop >= 0.0f)
        {
            _833 = smoothRoofTop;
        }
        else
        {
            _833 = float(data.w - 2) / topScale;
        }
        _828 = _833;
    }
    else
    {
        _828 = -1.0f;
    }
    float canopyTop = _828;
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
        int _925;
        if ((upperBits & 65280) != 0)
        {
            _925 = 16;
        }
        else
        {
            _925 = ((upperBits & 240) != 0) ? 8 : 4;
        }
        int maxK = _925;
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
                bool _1061 = k_2 > 2;
                bool _1071;
                if (_1061)
                {
                    _1071 = (data.x & (1 << (k_2 - 1))) == 0;
                }
                else
                {
                    _1071 = _1061;
                }
                if (_1071)
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
    float2 _1214;
    if (orientation == 1)
    {
        _1214 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1228;
        if (orientation == 2)
        {
            _1228 = size - _point;
        }
        else
        {
            float2 _1237;
            if (orientation == 3)
            {
                _1237 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1237 = _point;
            }
            _1228 = _1237;
        }
        _1214 = _1228;
    }
    float2 source = _1214;
    bool _1256 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _1264;
    if (!_1256)
    {
        _1264 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _1264 = _1256;
    }
    if (_1264)
    {
        return 0.0f;
    }
    uint _1271_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1271_dummy_parameter));
    bool _1278 = mapSize.y >= (mapSize.x * 2);
    bool _1284;
    if (_1278)
    {
        _1284 = mapSize.x > 1;
    }
    else
    {
        _1284 = _1278;
    }
    bool hasBand1 = _1284;
    int2 _1287;
    if (hasBand1)
    {
        _1287 = int2(mapSize.x, mapSize.x);
    }
    else
    {
        _1287 = mapSize;
    }
    int2 baseSize = _1287;
    float2 fPos = (source * (float2(baseSize) / max(size, 1.0f.xx))) - 0.5f.xx;
    int2 i0 = int2(floor(fPos));
    float2 f = frac(fPos);
    int2 maxIdx = baseSize - int2(1, 1);
    int2 gi = clamp(i0, int2(0, 0), max((maxIdx - int2(1, 1)), int2(0, 0)));
    float2 gUv = (float2(gi) + 1.0f.xx) / float2(max(mapSize, int2(1, 1)));
    float4 gR = overheadMap.GatherRed(_overheadMap_sampler, gUv);
    float4 gA = overheadMap.GatherAlpha(_overheadMap_sampler, gUv);
    bool _1357 = max(max(gR.x, gR.y), max(gR.z, gR.w)) < 0.123529411852359771728515625f;
    bool _1373;
    if (_1357)
    {
        _1373 = max(max(gA.x, gA.y), max(gA.z, gA.w)) < 0.0058823530562222003936767578125f;
    }
    else
    {
        _1373 = _1357;
    }
    if (_1373)
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
    bool _1471 = c00.w != 0;
    bool _1477;
    if (_1471)
    {
        _1477 = c00.w != 255;
    }
    else
    {
        _1477 = _1471;
    }
    bool v00 = _1477;
    bool _1481 = c10.w != 0;
    bool _1487;
    if (_1481)
    {
        _1487 = c10.w != 255;
    }
    else
    {
        _1487 = _1481;
    }
    bool v10 = _1487;
    bool _1491 = c01.w != 0;
    bool _1497;
    if (_1491)
    {
        _1497 = c01.w != 255;
    }
    else
    {
        _1497 = _1491;
    }
    bool v01 = _1497;
    bool _1501 = c11.w != 0;
    bool _1507;
    if (_1501)
    {
        _1507 = c11.w != 255;
    }
    else
    {
        _1507 = _1501;
    }
    bool v11 = _1507;
    if ((((!v00) && (!v10)) && (!v01)) && (!v11))
    {
        return 0.0f;
    }
    float _1524;
    if (v00)
    {
        _1524 = float(((c00.y * 256) + c00.z) - 32768) / 256.0f;
    }
    else
    {
        float _1538;
        if (v10)
        {
            _1538 = float(((c10.y * 256) + c10.z) - 32768) / 256.0f;
        }
        else
        {
            float _1552;
            if (v01)
            {
                _1552 = float(((c01.y * 256) + c01.z) - 32768) / 256.0f;
            }
            else
            {
                _1552 = float(((c11.y * 256) + c11.z) - 32768) / 256.0f;
            }
            _1538 = _1552;
        }
        _1524 = _1538;
    }
    float refBase = _1524;
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
                bool _2003 = c00.w >= 2;
                bool _2009;
                if (_2003)
                {
                    _2009 = c00.w != 255;
                }
                else
                {
                    _2009 = _2003;
                }
                int4 _2010;
                if (_2009)
                {
                    _2010 = c00;
                }
                else
                {
                    bool _2017 = c10.w >= 2;
                    bool _2023;
                    if (_2017)
                    {
                        _2023 = c10.w != 255;
                    }
                    else
                    {
                        _2023 = _2017;
                    }
                    int4 _2024;
                    if (_2023)
                    {
                        _2024 = c10;
                    }
                    else
                    {
                        bool _2031 = c01.w >= 2;
                        bool _2037;
                        if (_2031)
                        {
                            _2037 = c01.w != 255;
                        }
                        else
                        {
                            _2037 = _2031;
                        }
                        bool4 _2041 = _2037.xxxx;
                        _2024 = int4(_2041.x ? c01.x : c11.x, _2041.y ? c01.y : c11.y, _2041.z ? c01.z : c11.z, _2041.w ? c01.w : c11.w);
                    }
                    _2010 = _2024;
                }
                int4 cRef = _2010;
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
    bool _2081;
    if (hasBand1)
    {
        _2081 = (rUnion & 64) != 0;
    }
    else
    {
        _2081 = hasBand1;
    }
    if (_2081)
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
    float _2185;
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
        _2185 = canopyBlockedTexel(param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15);
    }
    else
    {
        _2185 = 0.0f;
    }
    float b00 = _2185;
    float _2217;
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
        _2217 = canopyBlockedTexel(param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23);
    }
    else
    {
        _2217 = 0.0f;
    }
    float b10 = _2217;
    float _2248;
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
        _2248 = canopyBlockedTexel(param_24, param_25, param_26, param_27, param_28, param_29, param_30, param_31);
    }
    else
    {
        _2248 = 0.0f;
    }
    float b01 = _2248;
    float _2279;
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
        _2279 = canopyBlockedTexel(param_32, param_33, param_34, param_35, param_36, param_37, param_38, param_39);
    }
    else
    {
        _2279 = 0.0f;
    }
    float b11 = _2279;
    return max(roofOcc, lerp(lerp(b00, b10, f.x), lerp(b01, b11, f.x), f.y));
}

float sampleHullFast(float2 op, float key, int yOffset, int2 sliceMax)
{
    int2 c = clamp(int2(floor(op)), int2(0, 0), sliceMax);
    int4 r = int4((voxelMap.Load(int3(int2(c.x, c.y + yOffset), 0)) * 255.0f) + 0.5f.xxxx);
    int f = (r.x * 256) + r.y;
    if (f == 0)
    {
        return 0.0f;
    }
    float fk = (float(f) / 256.0f) - 16.0f;
    float bk = (float((r.z * 256) + r.w) / 256.0f) - 16.0f;
    return smoothstep(-0.20000000298023223876953125f, 0.039999999105930328369140625f, fk - key) * smoothstep(-0.20000000298023223876953125f, 0.039999999105930328369140625f, key - bk);
}

float hullOccFast(float3 q, int2 oSize, int halfH, float topMarginHalf, int2 sliceMax, float2 lotSz)
{
    float2 op0 = float2(((q.x - q.y) + lotSz.x) * 16.0f, (((q.x + q.y) * 8.0f) - (q.z * 20.0f)) + topMarginHalf);
    bool _2759 = any(bool2(op0.x < 0.0f.xx.x, op0.y < 0.0f.xx.y));
    bool _2769;
    if (!_2759)
    {
        _2769 = op0.x >= float(oSize.x);
    }
    else
    {
        _2769 = _2759;
    }
    bool _2778;
    if (!_2769)
    {
        _2778 = op0.y >= float(halfH);
    }
    else
    {
        _2778 = _2769;
    }
    if (_2778)
    {
        return 0.0f;
    }
    float2 param = op0;
    float param_1 = (q.x + q.y) + (0.800000011920928955078125f * q.z);
    int param_2 = 0;
    int2 param_3 = sliceMax;
    float in0 = sampleHullFast(param, param_1, param_2, param_3);
    if (in0 <= 0.00999999977648258209228515625f)
    {
        return 0.0f;
    }
    float3 qB = float3(lotSz.y - q.y, q.x, q.z);
    float2 op1 = float2(((qB.x - qB.y) + lotSz.x) * 16.0f, (((qB.x + qB.y) * 8.0f) - (qB.z * 20.0f)) + topMarginHalf);
    bool _2841 = any(bool2(op1.x < 0.0f.xx.x, op1.y < 0.0f.xx.y));
    bool _2851;
    if (!_2841)
    {
        _2851 = op1.x >= float(oSize.x);
    }
    else
    {
        _2851 = _2841;
    }
    bool _2860;
    if (!_2851)
    {
        _2860 = op1.y >= float(halfH);
    }
    else
    {
        _2860 = _2851;
    }
    if (_2860)
    {
        return 0.0f;
    }
    float2 param_4 = op1;
    float param_5 = (qB.x + qB.y) + (0.800000011920928955078125f * qB.z);
    int param_6 = halfH;
    int2 param_7 = sliceMax;
    return min(in0, sampleHullFast(param_4, param_5, param_6, param_7));
}

float fastSunVis(float3 here, float startT, int2 vSize, bool hasVoxels, int vHalfH, float vTopMarginHalf, int2 vSliceMax, float2 sLotSz)
{
    uint _3395_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _3395_dummy_parameter)));
    float maxT = min(ambient_sunLot.w, 12.0f);
    if (maxT <= (startT + 0.0500000007450580596923828125f))
    {
        return 1.0f;
    }
    float lit = 1.0f;
    float3 qPrev = here + (ambient_sunLot.xyz * startT);
    for (int i = 1; i <= 12; i++)
    {
        float t = lerp(startT, maxT, float(i) / 12.0f);
        float3 q = here + (ambient_sunLot.xyz * t);
        float2 param = q.xy;
        float param_1 = here.z + 0.25f;
        float param_2 = qPrev.z;
        float param_3 = q.z;
        float param_4 = (0.07999999821186065673828125f * t) + 0.0599999986588954925537109375f;
        float canopy = canopyOcclusionAt(param, param_1, param_2, param_3, param_4);
        lit = min(lit, 1.0f - canopy);
        if (lit <= 0.0199999995529651641845703125f)
        {
            return 0.0f;
        }
        if (hasVoxels)
        {
            float3 param_5 = q;
            int2 param_6 = vSize;
            int param_7 = vHalfH;
            float param_8 = vTopMarginHalf;
            int2 param_9 = vSliceMax;
            float2 param_10 = sLotSz;
            float hOcc = hullOccFast(param_5, param_6, param_7, param_8, param_9, param_10);
            lit = min(lit, 1.0f - hOcc);
        }
        else
        {
            float2 texel = (q.xy + ambient_frame.w.xx) * ambient_frame.z;
            bool _3504 = all(bool2(texel.x >= 1.0f.xx.x, texel.y >= 1.0f.xx.y));
            bool _3513;
            if (_3504)
            {
                float2 _3510 = gridSize - 1.0f.xx;
                _3513 = all(bool2(texel.x <= _3510.x, texel.y <= _3510.y));
            }
            else
            {
                _3513 = _3504;
            }
            if (_3513)
            {
                float top = (0.5f - heightMap.Load(int3(int2(floor(texel)), 0)).x) * 128.0f;
                lit = min(lit, 1.0f - clamp(((top - q.z) - 0.119999997317790985107421875f) / ((0.119999997317790985107421875f * t) + 0.1500000059604644775390625f), 0.0f, 1.0f));
            }
        }
        if (lit <= 0.0199999995529651641845703125f)
        {
            return 0.0f;
        }
        qPrev = q;
    }
    return lit;
}

float2 lotSource(float2 camera)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _563;
    if (orientation == 1)
    {
        _563 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _577;
        if (orientation == 2)
        {
            _577 = size - camera;
        }
        else
        {
            float2 _587;
            if (orientation == 3)
            {
                _587 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _587 = camera;
            }
            _577 = _587;
        }
        _563 = _577;
    }
    return _563;
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
    bool _2550 = cover <= 0.0f;
    bool _2557;
    if (!_2550)
    {
        _2557 = ambient_clouds.y <= 0.0f;
    }
    else
    {
        _2557 = _2550;
    }
    if (_2557)
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

float lampRoomVis(float3 here, float3 lampLot)
{
    float2 start = here.xy + ambient_frame.w.xx;
    float2 end = lampLot.xy + ambient_frame.w.xx;
    float2 deltaXY = end - start;
    float distXY = length(deltaXY);
    if (distXY < 0.119999997317790985107421875f)
    {
        return 1.0f;
    }
    uint _3580_dummy_parameter;
    int2 maskTexSize = int2(spvTextureSize(indoorMap, uint(0), _3580_dummy_parameter));
    int2 param = maskTexSize;
    int maskBandH = indoorBandH(param);
    int stories = max(1, (maskTexSize.y / max(1, (5 * maskBandH))));
    float2 direction = deltaXY / distXY.xx;
    float rise = (lampLot.z - here.z) / distXY;
    int2 cell = int2(floor(start));
    int2 stepDir = int2(sign(direction));
    float2 safeDir = direction + (float2(bool2(direction.x == 0.0f.xx.x, direction.y == 0.0f.xx.y)) * 9.9999997473787516355514526367188e-06f);
    float2 stepDelta = abs(1.0f.xx / safeDir);
    float2 next = ((float2(cell) + max(float2(stepDir), 0.0f.xx)) - start) / safeDir;
    float maxT = distXY - 0.0599999986588954925537109375f;
    float _3712;
    int2 _3730;
    float _3779;
    float2 _3824;
    int _3840;
    int _3861;
    for (int i = 0; i < 14; i++)
    {
        bool _3652 = cell.x < 0;
        bool _3658;
        if (_3652)
        {
            _3658 = stepDir.x <= 0;
        }
        else
        {
            _3658 = _3652;
        }
        bool _3673;
        if (!_3658)
        {
            bool _3666 = cell.x >= maskTexSize.x;
            bool _3672;
            if (_3666)
            {
                _3672 = stepDir.x >= 0;
            }
            else
            {
                _3672 = _3666;
            }
            _3673 = _3672;
        }
        else
        {
            _3673 = _3658;
        }
        bool _3686;
        if (!_3673)
        {
            bool _3679 = cell.y < 0;
            bool _3685;
            if (_3679)
            {
                _3685 = stepDir.y <= 0;
            }
            else
            {
                _3685 = _3679;
            }
            _3686 = _3685;
        }
        else
        {
            _3686 = _3673;
        }
        bool _3700;
        if (!_3686)
        {
            bool _3693 = cell.y >= maskBandH;
            bool _3699;
            if (_3693)
            {
                _3699 = stepDir.y >= 0;
            }
            else
            {
                _3699 = _3693;
            }
            _3700 = _3699;
        }
        else
        {
            _3700 = _3686;
        }
        if (_3700)
        {
            break;
        }
        bool alongX = next.x < next.y;
        if (alongX)
        {
            _3712 = next.x;
        }
        else
        {
            _3712 = next.y;
        }
        float t = _3712;
        if (t > maxT)
        {
            break;
        }
        if (alongX)
        {
            _3730 = int2(stepDir.x, 0);
        }
        else
        {
            _3730 = int2(0, stepDir.y);
        }
        int2 to = cell + _3730;
        if (t > 0.039999999105930328369140625f)
        {
            int2 param_1 = cell;
            int param_2 = 1;
            int param_3 = 0;
            int2 param_4 = maskTexSize;
            int param_5 = maskBandH;
            int param_6 = stories;
            int c0 = maskCatFast(param_1, param_2, param_3, param_4, param_5, param_6);
            int2 param_7 = to;
            int param_8 = 1;
            int param_9 = 0;
            int2 param_10 = maskTexSize;
            int param_11 = maskBandH;
            int param_12 = stories;
            int n0 = maskCatFast(param_7, param_8, param_9, param_10, param_11, param_12);
            if ((c0 | n0) != 0)
            {
                if (c0 != 0)
                {
                    _3779 = ambient_contact.w + (float(c0 - 1) / 8.0f);
                }
                else
                {
                    _3779 = ambient_contact.w + (float(n0 - 1) / 8.0f);
                }
                float base0 = _3779;
                float zCross = here.z + (t * rise);
                int row = clamp(int(floor(((zCross - base0) + 0.0500000007450580596923828125f) / 2.9500000476837158203125f)), 0, stories - 1);
                float2 crossing = start + (direction * t);
                if (alongX)
                {
                    _3824 = float2(float(stepDir.x), 0.0f);
                }
                else
                {
                    _3824 = float2(0.0f, float(stepDir.y));
                }
                float2 edgeStep = _3824;
                if (c0 != 0)
                {
                    int2 param_13 = cell;
                    int param_14 = row;
                    float2 param_15 = (crossing - float2(cell)) - (edgeStep * 0.00999999977648258209228515625f);
                    _3840 = effectiveRoomAt(param_13, param_14, param_15);
                }
                else
                {
                    _3840 = 0;
                }
                int rA = _3840;
                if (n0 != 0)
                {
                    int2 param_16 = to;
                    int param_17 = row;
                    float2 param_18 = (crossing - float2(to)) + (edgeStep * 0.00999999977648258209228515625f);
                    _3861 = effectiveRoomAt(param_16, param_17, param_18);
                }
                else
                {
                    _3861 = 0;
                }
                int rB = _3861;
                bool _3881 = rA != rB;
                bool _3889;
                if (_3881)
                {
                    _3889 = (rA > 0) || (rB > 0);
                }
                else
                {
                    _3889 = _3881;
                }
                if (_3889)
                {
                    return 0.0f;
                }
            }
        }
        cell = to;
        if (alongX)
        {
            next.x += stepDelta.x;
        }
        else
        {
            next.y += stepDelta.y;
        }
    }
    return 1.0f;
}

void frag_main()
{
    int2 frag = int2(gl_FragCoord.xy);
    int orient = int(ambient_clouds.z + 0.5f);
    float2 _4091;
    if ((orient & 1) == 0)
    {
        _4091 = ambient_drift.zw;
    }
    else
    {
        _4091 = ambient_drift.wz;
    }
    float2 camLotSz = max(_4091, 1.0f.xx);
    int sliceW = clamp(int((camLotSz.x * 4.0f) + 0.5f), 16, 512);
    int sliceH = clamp(int((camLotSz.y * 4.0f) + 0.5f), 16, 512);
    int stories = clamp(indoorStories(), 1, 16);
    int cols = min(stories, 4);
    int colIdx = frag.x / sliceW;
    int rowIdx = frag.y / sliceH;
    int levelRow = (rowIdx * 4) + colIdx;
    if ((colIdx >= cols) || (levelRow >= stories))
    {
        color = 0.0f.xxxx;
        return;
    }
    int lx = frag.x - (colIdx * sliceW);
    int ly = frag.y - (rowIdx * sliceH);
    float2 lotXY = (float2(float(lx) + 0.5f, float(ly) + 0.5f) / float2(float(sliceW), float(sliceH))) * camLotSz;
    float2 cellAt = lotXY + ambient_frame.w.xx;
    int2 cell = int2(floor(cellAt));
    float2 localU = cellAt - float2(cell);
    int2 param = cell;
    int param_1 = 3;
    int param_2 = levelRow;
    int wallEdges = maskCatAt(param, param_1, param_2);
    bool _4204 = levelRow > 0;
    bool _4215;
    if (_4204)
    {
        int2 param_3 = cell;
        int param_4 = levelRow;
        float2 param_5 = localU;
        _4215 = !hasFloorSlabAt(param_3, param_4, param_5);
    }
    else
    {
        _4215 = _4204;
    }
    if (_4215 && (wallEdges == 0))
    {
        color = 0.0f.xxxx;
        return;
    }
    float2 param_6 = lotXY;
    float param_7 = ambient_contact.w;
    int2 param_8 = cell;
    int param_9 = 0;
    float param_10 = terrainBaseClamped(param_6, param_7);
    float base0 = floorAt(param_8, param_9, param_10);
    float _4237;
    if (levelRow == 0)
    {
        _4237 = base0;
    }
    else
    {
        int2 param_11 = cell;
        int param_12 = levelRow;
        float param_13 = base0 + (float(levelRow) * 2.9500000476837158203125f);
        _4237 = floorAt(param_11, param_12, param_13);
    }
    float floorZ = _4237;
    float3 here = float3(lotXY, floorZ + 0.039999999105930328369140625f);
    int2 param_14 = cell;
    int param_15 = levelRow;
    float2 param_16 = localU;
    int roomHere = effectiveRoomAt(param_14, param_15, param_16);
    bool inside = roomHere > 0;
    float3 surfAlb = 0.0f.xxx;
    float albW = 0.0f;
    float3 param_17 = here;
    bool param_18 = levelRow == 0;
    float3 param_19;
    bool _4281 = trySampleVisibleAlbedo(param_17, param_18, param_19);
    float3 candAlb = param_19;
    if (_4281)
    {
        surfAlb += (candAlb * 1.39999997615814208984375f);
        albW += 1.39999997615814208984375f;
    }
    bool _4293 = wallEdges != 0;
    bool _4308;
    if (_4293)
    {
        float3 param_20 = float3(lotXY, floorZ + 0.89999997615814208984375f);
        bool param_21 = false;
        float3 param_22;
        bool _4306 = trySampleVisibleAlbedo(param_20, param_21, param_22);
        candAlb = param_22;
        _4308 = _4306;
    }
    else
    {
        _4308 = _4293;
    }
    if (_4308)
    {
        surfAlb += (candAlb * 0.89999997615814208984375f);
        albW += 0.89999997615814208984375f;
    }
    if (albW < 0.5f)
    {
        float3 param_28;
        for (int k = 0; k < 4; k++)
        {
            float2 qXY = clamp(lotXY + _4339[k], 0.0500000007450580596923828125f.xx, camLotSz - 0.0500000007450580596923828125f.xx);
            float2 qAt = qXY + ambient_frame.w.xx;
            int2 qCell = int2(floor(qAt));
            int2 param_23 = qCell;
            int param_24 = levelRow;
            float2 param_25 = qAt - float2(qCell);
            if (effectiveRoomAt(param_23, param_24, param_25) != roomHere)
            {
                continue;
            }
            float3 param_26 = float3(qXY, floorZ + 0.039999999105930328369140625f);
            bool param_27 = levelRow == 0;
            bool _4386 = trySampleVisibleAlbedo(param_26, param_27, param_28);
            candAlb = param_28;
            if (_4386)
            {
                surfAlb += candAlb;
                albW += 1.0f;
            }
        }
    }
    float3 _4399;
    if (inside)
    {
        _4399 = float3(0.4600000083446502685546875f, 0.4099999964237213134765625f, 0.36000001430511474609375f);
    }
    else
    {
        bool3 _4414 = (ambient_skyExtra.x > 0.5f).xxx;
        _4399 = float3(_4414.x ? float3(0.7599999904632568359375f, 0.800000011920928955078125f, 0.86000001430511474609375f).x : float3(0.319999992847442626953125f, 0.36000001430511474609375f, 0.2800000011920928955078125f).x, _4414.y ? float3(0.7599999904632568359375f, 0.800000011920928955078125f, 0.86000001430511474609375f).y : float3(0.319999992847442626953125f, 0.36000001430511474609375f, 0.2800000011920928955078125f).y, _4414.z ? float3(0.7599999904632568359375f, 0.800000011920928955078125f, 0.86000001430511474609375f).z : float3(0.319999992847442626953125f, 0.36000001430511474609375f, 0.2800000011920928955078125f).z);
    }
    float3 fallbackAlb = _4399;
    float3 _4419;
    if (albW > 0.00999999977648258209228515625f)
    {
        _4419 = surfAlb / albW.xxx;
    }
    else
    {
        _4419 = fallbackAlb;
    }
    surfAlb = _4419;
    if (!inside)
    {
        float outLum = dot(surfAlb, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
        surfAlb = lerp(surfAlb, outLum.xxx, 0.4199999868869781494140625f.xxx);
    }
    float nightFactor = clamp(ambient_weather.w, 0.0f, 1.0f);
    float lowSun = 1.0f - smoothstep(0.119999997317790985107421875f, 0.519999980926513671875f, ambient_sunLot.z);
    float _4460;
    if (ambient_tone.w >= 0.0f)
    {
        _4460 = clamp(ambient_tone.w, 0.0f, 1.0f);
    }
    else
    {
        _4460 = 0.5f + (0.449999988079071044921875f * lowSun);
    }
    float dayProgress = _4460;
    float param_29 = dayProgress;
    float3 param_30;
    float3 param_31;
    float3 param_32;
    dayPalette(param_29, param_30, param_31, param_32);
    float3 warmSun = param_30;
    float3 coolShade = param_31;
    float3 dayWindowColor = param_32;
    warmSun /= max(dot(warmSun, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)), 9.9999997473787516355514526367188e-05f).xxx;
    dayWindowColor /= max(dot(dayWindowColor, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)), 9.9999997473787516355514526367188e-05f).xxx;
    uint _4499_dummy_parameter;
    int2 vSize = int2(spvTextureSize(voxelMap, uint(0), _4499_dummy_parameter));
    bool hasVoxels = vSize.x > 1;
    int _4506;
    if (hasVoxels)
    {
        int2 param_33 = vSize;
        _4506 = voxelAoRows(param_33);
    }
    else
    {
        _4506 = 1;
    }
    int vAoRows = _4506;
    int vHalfH = ((vSize.x / 2) + 128) + (256 * vAoRows);
    float vTopMarginHalf = float(64 + (256 * vAoRows));
    int2 vSliceMax = int2(vSize.x - 1, vHalfH - 1);
    float2 sLotSz = max(ambient_drift.zw, 1.0f.xx);
    float3 directIrr = 0.0f.xxx;
    if ((ambient_params.z > 0.001000000047497451305389404296875f) && (nightFactor < 0.959999978542327880859375f))
    {
        float3 param_34 = here;
        float3 wRay = bounceWallRay(param_34);
        bool _4555 = wRay.x > 0.0199999995529651641845703125f;
        bool _4562;
        if (!_4555)
        {
            _4562 = wRay.y > 0.0199999995529651641845703125f;
        }
        else
        {
            _4562 = _4555;
        }
        if (_4562)
        {
            float _4567;
            if (inside)
            {
                _4567 = max(0.75f, wRay.z + 1.10000002384185791015625f);
            }
            else
            {
                _4567 = 0.14000000059604644775390625f;
            }
            float startT = _4567;
            float3 param_35 = here;
            float param_36 = startT;
            int2 param_37 = vSize;
            bool param_38 = hasVoxels;
            int param_39 = vHalfH;
            float param_40 = vTopMarginHalf;
            int2 param_41 = vSliceMax;
            float2 param_42 = sLotSz;
            float3 param_43 = here;
            float sunVis = fastSunVis(param_35, param_36, param_37, param_38, param_39, param_40, param_41, param_42) * cloudLight(param_43);
            float dayAmt = (1.0f - nightFactor) * ambient_lamp.w;
            if (inside)
            {
                float patchAmt = max(wRay.x * 0.60000002384185791015625f, wRay.y * 1.25f) * sunVis;
                directIrr += (lerp(warmSun, dayWindowColor, 0.4799999892711639404296875f.xxx) * ((patchAmt * dayAmt) * 1.14999997615814208984375f));
            }
            else
            {
                directIrr += (warmSun * (((wRay.x * sunVis) * dayAmt) * 0.4199999868869781494140625f));
            }
        }
    }
    int lampCount = int(ambient_lamp.x);
    bool _4646 = lampCount > 0;
    bool _4652;
    if (_4646)
    {
        _4652 = ambient_lamp.z > 0.001000000047497451305389404296875f;
    }
    else
    {
        _4652 = _4646;
    }
    if (_4652)
    {
        float lampReachTiles = max(ambient_lamp.y / 32.0f, 2.5f);
        for (int i = 0; i < 16; i++)
        {
            if (i >= lampCount)
            {
                break;
            }
            float4 l = ambient_lamps[i];
            bool isFire = l.w < 0.0f;
            float strength = abs(l.w);
            if (strength < 0.00999999977648258209228515625f)
            {
                continue;
            }
            float2 param_44 = l.xy;
            float param_45 = l.z;
            bool param_46 = false;
            float2 param_47 = ambient_frame.xy;
            float3 lampLot = lotPoint(param_44, param_45, param_46, param_47);
            if (abs(lampLot.z - floorZ) > 2.7139999866485595703125f)
            {
                continue;
            }
            float distTiles = length(lampLot.xy - lotXY);
            float maxR = lampReachTiles * (isFire ? 1.14999997615814208984375f : 1.0f);
            if (distTiles >= maxR)
            {
                continue;
            }
            float atten = 1.0f - (distTiles / maxR);
            atten *= atten;
            if ((atten * strength) < 0.0199999995529651641845703125f)
            {
                continue;
            }
            float3 param_48 = here;
            float3 param_49 = lampLot;
            float vis = lampRoomVis(param_48, param_49);
            if (vis <= 0.00999999977648258209228515625f)
            {
                continue;
            }
            float flicker = 1.0f;
            if (isFire)
            {
                float phase = dot(l.xy, float2(0.037000000476837158203125f, 0.0529999993741512298583984375f));
                float wave = ((0.5f * sin((ambient_weather.z * 5.69999980926513671875f) + phase)) + (0.319999992847442626953125f * sin(((ambient_weather.z * 11.30000019073486328125f) + (phase * 1.7000000476837158203125f)) + 1.10000002384185791015625f))) + (0.180000007152557373046875f * sin(((ambient_weather.z * 19.1000003814697265625f) + (phase * 2.2999999523162841796875f)) + 2.400000095367431640625f));
                flicker = 0.839999973773956298828125f + (0.300000011920928955078125f * clamp(0.5f + (0.5f * wave), 0.0f, 1.0f));
            }
            bool3 _4817 = isFire.xxx;
            float3 lCol = float3(_4817.x ? float3(1.4500000476837158203125f, 0.4930000007152557373046875f, 0.072499997913837432861328125f).x : float3(1.0f, 0.819999992847442626953125f, 0.579999983310699462890625f).x, _4817.y ? float3(1.4500000476837158203125f, 0.4930000007152557373046875f, 0.072499997913837432861328125f).y : float3(1.0f, 0.819999992847442626953125f, 0.579999983310699462890625f).y, _4817.z ? float3(1.4500000476837158203125f, 0.4930000007152557373046875f, 0.072499997913837432861328125f).z : float3(1.0f, 0.819999992847442626953125f, 0.579999983310699462890625f).z);
            directIrr += (lCol * (((((strength * flicker) * atten) * vis) * ambient_lamp.z) * 0.550000011920928955078125f));
        }
    }
    float3 bounce = surfAlb * directIrr;
    float peak = max(bounce.x, max(bounce.y, bounce.z));
    if (peak > 0.85000002384185791015625f)
    {
        bounce *= ((0.85000002384185791015625f + ((peak - 0.85000002384185791015625f) / (1.0f + ((peak - 0.85000002384185791015625f) * 1.7999999523162841796875f)))) / peak);
    }
    color = float4(max(bounce, 0.0f.xxx), 1.0f);
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
