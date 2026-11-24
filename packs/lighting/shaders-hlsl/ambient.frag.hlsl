static const float _8553[5] = { 0.0625f, 0.25f, 0.375f, 0.25f, 0.0625f };
static const float3 _8673[6] = { float3(0.12999999523162841796875f, -0.100000001490116119384765625f, 0.039999999105930328369140625f), float3(0.14000000059604644775390625f, 0.100000001490116119384765625f, 0.039999999105930328369140625f), float3(0.180000007152557373046875f, 0.0f, 0.1599999964237213134765625f), float3(0.25f, -0.1599999964237213134765625f, -0.0599999986588954925537109375f), float3(0.2599999904632568359375f, 0.1599999964237213134765625f, -0.0599999986588954925537109375f), float3(0.319999992847442626953125f, 0.0f, 0.100000001490116119384765625f) };
static const float _8708[6] = { 1.0f, 1.0f, 0.89999997615814208984375f, 0.64999997615814208984375f, 0.64999997615814208984375f, 0.550000011920928955078125f };
static const int2 _10618[4] = { int2(0, 1), int2(1, 1), int2(1, 0), int2(0, 0) };

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
    float4 ambient_prevView : packoffset(c30);
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
Texture2D<float4> voxelMap : register(t10, space2);
SamplerState _voxelMap_sampler : register(s10, space2);
Texture2D<float4> liftMap : register(t5, space2);
SamplerState _liftMap_sampler : register(s5, space2);
Texture2D<float4> footMap : register(t4, space2);
SamplerState _footMap_sampler : register(s4, space2);
Texture2D<float4> prevAmbientMap : register(t9, space2);
SamplerState _prevAmbientMap_sampler : register(s9, space2);

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

float _noise(float2 pixel)
{
    return frac(52.98291778564453125f * frac(dot(pixel, float2(0.067110560834407806396484375f, 0.005837149918079376220703125f))));
}

float3 lotPoint(float2 scene, float key, bool terrain, float2 frame)
{
    float2 local = scene - frame;
    float _250;
    if (terrain)
    {
        _250 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _250 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _250;
    float _274;
    if (terrain)
    {
        _274 = key;
    }
    else
    {
        _274 = key - (0.800000011920928955078125f * h);
    }
    float s = _274;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

float groundAt(float2 pixel)
{
    float ground = groundMap.Load(int3(int2(pixel), 0)).x;
    float _444;
    if (ground < 1.0f)
    {
        _444 = (((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f;
    }
    else
    {
        _444 = -100000.0f;
    }
    return _444;
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
    float _1590;
    if (slope > 0.100000001490116119384765625f)
    {
        _1590 = max(0.0f, (z - ground) / ((slope * 4.0f) / 3.0f));
    }
    else
    {
        _1590 = 0.0f;
    }
    return _1590;
}

int maskAt(int2 at, int band)
{
    uint _462_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _462_dummy_parameter));
    int bandH = size.y / 10;
    bool _470 = at.x < 0;
    bool _477;
    if (!_470)
    {
        _477 = at.y < 0;
    }
    else
    {
        _477 = _470;
    }
    bool _486;
    if (!_477)
    {
        _486 = at.x >= size.x;
    }
    else
    {
        _486 = _477;
    }
    bool _494;
    if (!_486)
    {
        _494 = at.y >= bandH;
    }
    else
    {
        _494 = _486;
    }
    if (_494)
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
    float _585;
    float _598;
    float _631;
    float _644;
    float2 _709;
    float2 _717;
    for (int i = 0; i < 4; i++)
    {
        if ((i & 1) == 1)
        {
            _585 = f.x;
        }
        else
        {
            _585 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _598 = f.y;
        }
        else
        {
            _598 = 1.0f - f.y;
        }
        float weight = _585 * _598;
        int2 at = base + int2(i & 1, i >> 1);
        int2 param = at;
        int param_1 = 2;
        int gCode = maskAt(param, param_1);
        int2 param_2 = at;
        int param_3 = 3;
        int f2Code = maskAt(param_2, param_3);
        if (gCode != 0)
        {
            _631 = ambient_contact.w + (float(gCode - 1) / 8.0f);
        }
        else
        {
            if (f2Code != 0)
            {
                _644 = (ambient_contact.w + (float(f2Code - 1) / 8.0f)) - 2.9500000476837158203125f;
            }
            else
            {
                _644 = ambient_contact.w;
            }
            _631 = _644;
        }
        float ground = _631;
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
            _709 = float2(1.0f, -1.0f);
        }
        else
        {
            if (part == 2)
            {
                _717 = float2(-1.0f, 1.0f);
            }
            else
            {
                bool2 _727 = (part == 3).xx;
                _717 = float2(_727.x ? (-1.0f).xx.x : 1.0f.xx.x, _727.y ? (-1.0f).xx.y : 1.0f.xx.y);
            }
            _709 = _717;
        }
        float2 toward = _709;
        sum += (weight * smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((lot.xy + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward)));
    }
    return sum;
}

float floorAt(int2 at, int row, float fallback)
{
    int2 param = at;
    int param_1 = row + 2;
    int code = maskAt(param, param_1);
    float _527;
    if (code == 0)
    {
        _527 = fallback;
    }
    else
    {
        _527 = ambient_contact.w + (float(code - 1) / 8.0f);
    }
    return _527;
}

int effectiveRoomAt(int2 cell, int row, float2 localU)
{
    int2 param = cell;
    int param_1 = row;
    int code = maskAt(param, param_1);
    int room = code >> 1;
    if (room == 0)
    {
        return 0;
    }
    int2 param_2 = cell;
    int param_3 = row + 4;
    int part = maskAt(param_2, param_3) & 7;
    if (part == 0)
    {
        return room;
    }
    float2 _2240;
    if (part == 1)
    {
        _2240 = float2(1.0f, -1.0f);
    }
    else
    {
        float2 _2246;
        if (part == 2)
        {
            _2246 = float2(-1.0f, 1.0f);
        }
        else
        {
            bool2 _2252 = (part == 3).xx;
            _2246 = float2(_2252.x ? (-1.0f).xx.x : 1.0f.xx.x, _2252.y ? (-1.0f).xx.y : 1.0f.xx.y);
        }
        _2240 = _2246;
    }
    float2 toward = _2240;
    return (dot(localU - 0.5f.xx, toward) >= 0.0f) ? room : 0;
}

float floorWallAO(float3 here)
{
    float2 at = here.xy + ambient_frame.w.xx;
    int2 cell = int2(floor(at));
    float2 u = frac(at);
    int2 param = cell;
    int param_1 = 0;
    float param_2 = here.z;
    float base0 = floorAt(param, param_1, param_2);
    int row = int(here.z > ((base0 + 2.9500000476837158203125f) - 0.1500000059604644775390625f));
    int2 param_3 = cell;
    int param_4 = row + 6;
    int wallEdges = maskAt(param_3, param_4);
    int2 param_5 = cell;
    int param_6 = row + 8;
    int fenceEdges = maskAt(param_5, param_6);
    int2 param_7 = cell;
    int param_8 = row;
    float2 param_9 = u;
    int rHere = effectiveRoomAt(param_7, param_8, param_9);
    uint _6933_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _6933_dummy_parameter)));
    float occ = 0.0f;
    float _6947;
    float _6955;
    float _6964;
    int2 _7062;
    int2 _7068;
    float2 _7081;
    float2 _7090;
    float2 _7099;
    float2 _7140;
    float2 _7149;
    float2 _7158;
    for (int d = 0; d < 4; d++)
    {
        if (d == 0)
        {
            _6947 = u.x;
        }
        else
        {
            if (d == 1)
            {
                _6955 = 1.0f - u.x;
            }
            else
            {
                if (d == 2)
                {
                    _6964 = u.y;
                }
                else
                {
                    _6964 = 1.0f - u.y;
                }
                _6955 = _6964;
            }
            _6947 = _6955;
        }
        float dist = _6947;
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
                _7062 = int2(-1, 0);
            }
            else
            {
                if (d == 1)
                {
                    _7068 = int2(1, 0);
                }
                else
                {
                    bool2 _7074 = (d == 2).xx;
                    _7068 = int2(_7074.x ? int2(0, -1).x : int2(0, 1).x, _7074.y ? int2(0, -1).y : int2(0, 1).y);
                }
                _7062 = _7068;
            }
            int2 _step = _7062;
            if (d == 0)
            {
                _7081 = float2(0.9900000095367431640625f, u.y);
            }
            else
            {
                if (d == 1)
                {
                    _7090 = float2(0.00999999977648258209228515625f, u.y);
                }
                else
                {
                    if (d == 2)
                    {
                        _7099 = float2(u.x, 0.9900000095367431640625f);
                    }
                    else
                    {
                        _7099 = float2(u.x, 0.00999999977648258209228515625f);
                    }
                    _7090 = _7099;
                }
                _7081 = _7090;
            }
            float2 nbrU = _7081;
            int2 param_10 = cell + _step;
            int param_11 = row;
            float2 param_12 = nbrU;
            int rNbr = effectiveRoomAt(param_10, param_11, param_12);
            bool _7124 = rHere == rNbr;
            bool _7133;
            if (!_7124)
            {
                _7133 = (rHere == 0) && (rNbr == 0);
            }
            else
            {
                _7133 = _7124;
            }
            if (_7133)
            {
                continue;
            }
            if (d == 0)
            {
                _7140 = float2(0.0f, u.y);
            }
            else
            {
                if (d == 1)
                {
                    _7149 = float2(1.0f, u.y);
                }
                else
                {
                    if (d == 2)
                    {
                        _7158 = float2(u.x, 0.0f);
                    }
                    else
                    {
                        _7158 = float2(u.x, 1.0f);
                    }
                    _7149 = _7158;
                }
                _7140 = _7149;
            }
            float2 edgeLocal = _7140;
            float2 edgePos = float2(cell) + edgeLocal;
            float2 dirF = float2(_step);
            float hA = ((0.5f - heightMap.Sample(_heightMap_sampler, ((edgePos + (dirF * 0.0500000007450580596923828125f)) * ambient_frame.z) / gridSize).x) * 64.0f) - here.z;
            float hB = ((0.5f - heightMap.Sample(_heightMap_sampler, ((edgePos - (dirF * 0.0500000007450580596923828125f)) * ambient_frame.z) / gridSize).x) * 64.0f) - here.z;
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
            int2 param_13 = cell;
            int param_14 = row + 4;
            int part = maskAt(param_13, param_14) & 7;
            if (part != 0)
            {
                float _7436;
                if (part <= 2)
                {
                    _7436 = abs(u.x - u.y) * 0.707106769084930419921875f;
                }
                else
                {
                    _7436 = abs((u.x + u.y) - 1.0f) * 0.707106769084930419921875f;
                }
                float dist_5 = _7436;
                if (dist_5 < 0.560000002384185791015625f)
                {
                    float2 _7463;
                    if (part <= 2)
                    {
                        _7463 = (0.5f * (u.x + u.y)).xx;
                    }
                    else
                    {
                        _7463 = float2(0.5f * ((u.x - u.y) + 1.0f), 0.5f * ((u.y - u.x) + 1.0f));
                    }
                    float2 edgeLocal_1 = _7463;
                    float2 edgePos_1 = float2(cell) + edgeLocal_1;
                    float hD = ((0.5f - heightMap.Sample(_heightMap_sampler, (edgePos_1 * ambient_frame.z) / gridSize).x) * 64.0f) - here.z;
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
    int halfH = (oSize.x / 2) + 256;
    int yBase = halfH * 2;
    if (oSize.y < (yBase + aoSize))
    {
        return 0.0f.xxx;
    }
    float2 p = (lotXY * 8.0f) - 0.5f.xx;
    bool _8274 = p.x < (-0.5f);
    bool _8281;
    if (!_8274)
    {
        _8281 = p.y < (-0.5f);
    }
    else
    {
        _8281 = _8274;
    }
    bool _8290;
    if (!_8281)
    {
        _8290 = p.x >= float(aoSize);
    }
    else
    {
        _8290 = _8281;
    }
    bool _8299;
    if (!_8290)
    {
        _8299 = p.y >= float(aoSize);
    }
    else
    {
        _8299 = _8290;
    }
    if (_8299)
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
    int xOff = (levelRow > 0) ? aoSize : 0;
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
    uint _4087_dummy_parameter;
    float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _4087_dummy_parameter)));
    float2 wp = ambient_shadowView.xy + (scene * ambient_shadowView.z);
    bool _4101 = any(bool2(wp.x < 0.5f.xx.x, wp.y < 0.5f.xx.y));
    bool _4111;
    if (!_4101)
    {
        float2 _4108 = wSize - 0.5f.xx;
        _4111 = any(bool2(wp.x >= _4108.x, wp.y >= _4108.y));
    }
    else
    {
        _4111 = _4101;
    }
    if (_4111)
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
    float4 fKey = (0.89999997615814208984375f.xxxx - wFront) / 0.0030000000260770320892333984375f.xxxx;
    float4 bKey = (0.89999997615814208984375f.xxxx - wBack) / 0.0030000000260770320892333984375f.xxxx;
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
    uint _8457_dummy_parameter;
    float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _8457_dummy_parameter)));
    float2 wpC = ambient_shadowView.xy + (sceneC * ambient_shadowView.z);
    bool _8471 = any(bool2(wpC.x < 8.0f.xx.x, wpC.y < 8.0f.xx.y));
    bool _8481;
    if (!_8471)
    {
        float2 _8478 = wSize - 8.0f.xx;
        _8481 = any(bool2(wpC.x >= _8478.x, wpC.y >= _8478.y));
    }
    else
    {
        _8481 = _8471;
    }
    if (_8481)
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
        float wy = _8553[iy + 2];
        for (int ix = -2; ix <= 2; ix++)
        {
            float3 q = float3(here.xy + (float2(float(ix), float(iy)) * 0.034000001847743988037109375f), here.z + 0.054999999701976776123046875f);
            float3 param = q;
            float param_1 = 0.100000001490116119384765625f;
            acc += (dynamicSimOccAt(param, param_1) * (_8553[ix + 2] * wy));
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
    outContact = max(clamp(baked.x * 0.7799999713897705078125f, 0.0f, 1.0f), simContact);
    return clamp(((baked.y * 0.439999997615814208984375f) + (baked.z * 0.3400000035762786865234375f)) + (simContact * 0.1599999964237213134765625f), 0.0f, 1.0f);
}

float3 resolveWallSurface(float3 rawHere, float2 sceneXY, float smoothKey, float2 horizN)
{
    int _7546;
    if (abs(horizN.x) > 0.819999992847442626953125f)
    {
        _7546 = (horizN.x > 0.0f) ? 1 : 2;
    }
    else
    {
        int _7558;
        if (abs(horizN.y) > 0.819999992847442626953125f)
        {
            _7558 = (horizN.y > 0.0f) ? 4 : 8;
        }
        else
        {
            _7558 = 0;
        }
        _7546 = _7558;
    }
    int ownBit = _7546;
    if (ownBit == 0)
    {
        float2 param = sceneXY;
        float param_1 = smoothKey;
        bool param_2 = false;
        float2 param_3 = ambient_frame.xy;
        return lotPoint(param, param_1, param_2, param_3);
    }
    float2 param_4 = sceneXY;
    float param_5 = smoothKey + 0.14000000059604644775390625f;
    bool param_6 = false;
    float2 param_7 = ambient_frame.xy;
    float3 shifted = lotPoint(param_4, param_5, param_6, param_7);
    float2 probe = (shifted.xy + ambient_frame.w.xx) + (horizN * 0.119999997317790985107421875f);
    int2 c = int2(floor(probe));
    float2 u = frac(probe);
    int2 param_8 = c;
    int param_9 = 0;
    float param_10 = shifted.z;
    float b0 = floorAt(param_8, param_9, param_10);
    int row = int(shifted.z > ((b0 + 2.9500000476837158203125f) - 0.1500000059604644775390625f));
    int2 param_11 = c;
    int param_12 = row + 6;
    if ((maskAt(param_11, param_12) & ownBit) != 0)
    {
        return shifted;
    }
    if (ownBit <= 2)
    {
        bool _7647 = u.y > 0.7400000095367431640625f;
        bool _7660;
        if (_7647)
        {
            int2 param_13 = c + int2(0, 1);
            int param_14 = row + 6;
            _7660 = (maskAt(param_13, param_14) & ownBit) != 0;
        }
        else
        {
            _7660 = _7647;
        }
        if (_7660)
        {
            shifted.y = (float(c.y + 1) + 0.0350000001490116119384765625f) - ambient_frame.w;
            return shifted;
        }
        bool _7676 = u.y < 0.2599999904632568359375f;
        bool _7689;
        if (_7676)
        {
            int2 param_15 = c - int2(0, 1);
            int param_16 = row + 6;
            _7689 = (maskAt(param_15, param_16) & ownBit) != 0;
        }
        else
        {
            _7689 = _7676;
        }
        if (_7689)
        {
            shifted.y = (float(c.y) - 0.0350000001490116119384765625f) - ambient_frame.w;
            return shifted;
        }
    }
    else
    {
        bool _7705 = u.x > 0.7400000095367431640625f;
        bool _7718;
        if (_7705)
        {
            int2 param_17 = c + int2(1, 0);
            int param_18 = row + 6;
            _7718 = (maskAt(param_17, param_18) & ownBit) != 0;
        }
        else
        {
            _7718 = _7705;
        }
        if (_7718)
        {
            shifted.x = (float(c.x + 1) + 0.0350000001490116119384765625f) - ambient_frame.w;
            return shifted;
        }
        bool _7734 = u.x < 0.2599999904632568359375f;
        bool _7747;
        if (_7734)
        {
            int2 param_19 = c - int2(1, 0);
            int param_20 = row + 6;
            _7747 = (maskAt(param_19, param_20) & ownBit) != 0;
        }
        else
        {
            _7747 = _7734;
        }
        if (_7747)
        {
            shifted.x = (float(c.x) - 0.0350000001490116119384765625f) - ambient_frame.w;
            return shifted;
        }
    }
    float2 param_21 = sceneXY;
    float param_22 = smoothKey;
    bool param_23 = false;
    float2 param_24 = ambient_frame.xy;
    return lotPoint(param_21, param_22, param_23, param_24);
}

float terrainBaseAt(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1012;
    if (orientation == 1)
    {
        _1012 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1026;
        if (orientation == 2)
        {
            _1026 = size - _point;
        }
        else
        {
            float2 _1035;
            if (orientation == 3)
            {
                _1035 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1035 = _point;
            }
            _1026 = _1035;
        }
        _1012 = _1026;
    }
    float2 source = _1012;
    bool _1053 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _1061;
    if (!_1053)
    {
        _1061 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _1061 = _1053;
    }
    if (_1061)
    {
        return fallback;
    }
    uint _1069_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _1069_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
    uint _1083_dummy_parameter;
    int2 _1083 = int2(spvTextureSize(overheadMap, uint(0), _1083_dummy_parameter));
    if (any(bool2(at.x >= _1083.x, at.y >= _1083.y)))
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

float wallCornerAO(float3 here, float2 horizN)
{
    float2 planePos = here.xy + ambient_frame.w.xx;
    float2 at = planePos + (horizN * 0.100000001490116119384765625f);
    int2 baseCell = int2(floor(at - 0.5f.xx));
    float occ = 0.0f;
    int2 _7867;
    int2 _7873;
    float2 _7899;
    float2 _7906;
    float2 _7917;
    float2 _7933;
    float2 _7944;
    float2 _7951;
    float2 _7985;
    for (int cy = 0; cy <= 1; cy++)
    {
        for (int cx = 0; cx <= 1; cx++)
        {
            int2 cell = baseCell + int2(cx, cy);
            int2 param = cell;
            int param_1 = 0;
            float param_2 = here.z;
            float base0 = floorAt(param, param_1, param_2);
            int row = int(here.z > ((base0 + 2.9500000476837158203125f) - 0.1500000059604644775390625f));
            int2 param_3 = cell;
            int param_4 = row + 6;
            int wallEdges = maskAt(param_3, param_4);
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
                    _7867 = int2(-1, 0);
                }
                else
                {
                    if (d == 1)
                    {
                        _7873 = int2(1, 0);
                    }
                    else
                    {
                        bool2 _7879 = (d == 2).xx;
                        _7873 = int2(_7879.x ? int2(0, -1).x : int2(0, 1).x, _7879.y ? int2(0, -1).y : int2(0, 1).y);
                    }
                    _7867 = _7873;
                }
                int2 _step = _7867;
                float perpWeight = 1.0f - smoothstep(0.7599999904632568359375f, 0.949999988079071044921875f, -dot(float2(_step), horizN));
                if (perpWeight <= 0.001000000047497451305389404296875f)
                {
                    continue;
                }
                if (d == 0)
                {
                    _7899 = cMin;
                }
                else
                {
                    if (d == 1)
                    {
                        _7906 = float2(cMax.x, cMin.y);
                    }
                    else
                    {
                        if (d == 2)
                        {
                            _7917 = cMin;
                        }
                        else
                        {
                            _7917 = float2(cMin.x, cMax.y);
                        }
                        _7906 = _7917;
                    }
                    _7899 = _7906;
                }
                float2 segA = _7899;
                if (d == 0)
                {
                    _7933 = float2(cMin.x, cMax.y);
                }
                else
                {
                    if (d == 1)
                    {
                        _7944 = cMax;
                    }
                    else
                    {
                        if (d == 2)
                        {
                            _7951 = float2(cMax.x, cMin.y);
                        }
                        else
                        {
                            _7951 = cMax;
                        }
                        _7944 = _7951;
                    }
                    _7933 = _7944;
                }
                float2 segB = _7933;
                float frontHemi = smoothstep(0.14000000059604644775390625f, 0.449999988079071044921875f, max(dot(segA - planePos, horizN), dot(segB - planePos, horizN)));
                if (frontHemi <= 0.001000000047497451305389404296875f)
                {
                    continue;
                }
                if (d <= 1)
                {
                    _7985 = float2(segA.x, clamp(at.y, cMin.y, cMax.y));
                }
                else
                {
                    _7985 = float2(clamp(at.x, cMin.x, cMax.x), segA.y);
                }
                float2 closest = _7985;
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
    float _3739;
    if (f00 == 0)
    {
        _3739 = 0.0f;
    }
    else
    {
        _3739 = smoothstep(-pad, 0.039999999105930328369140625f, ((float(f00) / 256.0f) - 16.0f) - key) * smoothstep(-pad, 0.039999999105930328369140625f, key - ((float((r00.z * 256) + r00.w) / 256.0f) - 16.0f));
    }
    float v00 = _3739;
    float _3771;
    if (f10 == 0)
    {
        _3771 = 0.0f;
    }
    else
    {
        _3771 = smoothstep(-pad, 0.039999999105930328369140625f, ((float(f10) / 256.0f) - 16.0f) - key) * smoothstep(-pad, 0.039999999105930328369140625f, key - ((float((r10.z * 256) + r10.w) / 256.0f) - 16.0f));
    }
    float v10 = _3771;
    float _3803;
    if (f01 == 0)
    {
        _3803 = 0.0f;
    }
    else
    {
        _3803 = smoothstep(-pad, 0.039999999105930328369140625f, ((float(f01) / 256.0f) - 16.0f) - key) * smoothstep(-pad, 0.039999999105930328369140625f, key - ((float((r01.z * 256) + r01.w) / 256.0f) - 16.0f));
    }
    float v01 = _3803;
    float _3835;
    if (f11 == 0)
    {
        _3835 = 0.0f;
    }
    else
    {
        _3835 = smoothstep(-pad, 0.039999999105930328369140625f, ((float(f11) / 256.0f) - 16.0f) - key) * smoothstep(-pad, 0.039999999105930328369140625f, key - ((float((r11.z * 256) + r11.w) / 256.0f) - 16.0f));
    }
    float v11 = _3835;
    return lerp(lerp(v00, v10, f.x), lerp(v01, v11, f.x), f.y);
}

float dualViewHullAt(float3 q, int2 oSize, float2 lotSz, float2 jitter, float spreadPx)
{
    int halfH = (oSize.x / 2) + 256;
    int2 sliceMax = int2(oSize.x - 1, halfH - 1);
    float pad = 0.180000007152557373046875f + (0.0199999995529651641845703125f * spreadPx);
    float2 op0 = float2(((q.x - q.y) + lotSz.x) * 16.0f, (((q.x + q.y) * 8.0f) - (q.z * 20.0f)) + 192.0f);
    bool _3922 = any(bool2(op0.x < 0.0f.xx.x, op0.y < 0.0f.xx.y));
    bool _3932;
    if (!_3922)
    {
        _3932 = op0.x >= float(oSize.x);
    }
    else
    {
        _3932 = _3922;
    }
    bool _3941;
    if (!_3932)
    {
        _3941 = op0.y >= float(halfH);
    }
    else
    {
        _3941 = _3932;
    }
    if (_3941)
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
    float2 op1 = float2(((qB.x - qB.y) + lotSz.x) * 16.0f, (((qB.x + qB.y) * 8.0f) - (qB.z * 20.0f)) + 192.0f);
    bool _4006 = any(bool2(op1.x < 0.0f.xx.x, op1.y < 0.0f.xx.y));
    bool _4016;
    if (!_4006)
    {
        _4016 = op1.x >= float(oSize.x);
    }
    else
    {
        _4016 = _4006;
    }
    bool _4025;
    if (!_4016)
    {
        _4025 = op1.y >= float(halfH);
    }
    else
    {
        _4025 = _4016;
    }
    if (_4025)
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

float voxelWallAO(float3 here, float2 horizN, int2 vSize, float2 lotSz)
{
    float2 tang = float2(-horizN.y, horizN.x);
    float sum = 0.0f;
    float wSum = 0.0f;
    for (int i = 0; i < 6; i++)
    {
        float3 o = _8673[i];
        float3 q = here + float3((horizN * o.x) + (tang * o.y), o.z);
        float3 param = q;
        int2 param_1 = vSize;
        float2 param_2 = lotSz;
        float2 param_3 = 0.0f.xx;
        float param_4 = 1.35000002384185791015625f;
        float occ = dualViewHullAt(param, param_1, param_2, param_3, param_4);
        sum += (occ * _8708[i]);
        wSum += _8708[i];
    }
    return clamp((sum / max(wSum, 9.9999997473787516355514526367188e-05f)) * 1.2999999523162841796875f, 0.0f, 1.0f);
}

float2 wallRay(float3 here, float onFlatFloor, float2 horizN)
{
    float3 sun = ambient_sunLot.xyz;
    float across = length(sun.xy);
    if (across < 0.001000000047497451305389404296875f)
    {
        return float2(1.0f, 0.0f);
    }
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
    float maxDist = min(maxReachH, 7.400000095367431640625f / max(rise, 0.119999997317790985107421875f));
    float vis = 1.0f;
    float winHit = 0.0f;
    float tPrev = 0.0f;
    int2 param = cell;
    int param_1 = 0;
    int curM0 = maskAt(param, param_1);
    int2 param_2 = cell;
    int param_3 = 1;
    int curM1 = maskAt(param_2, param_3);
    float _2386;
    int _2448;
    float _2485;
    float _2508;
    float _2592;
    int2 _2767;
    float2 _2831;
    int _2863;
    int _2877;
    int _2891;
    int _2905;
    float _2965;
    float _3051;
    for (int i = 0; i < 64; i++)
    {
        bool alongX = next.x < next.y;
        if (alongX)
        {
            _2386 = next.x;
        }
        else
        {
            _2386 = next.y;
        }
        float t = _2386;
        if ((curM0 >= 2) || (curM1 >= 2))
        {
            int2 param_4 = cell;
            int param_5 = 4;
            int part0 = maskAt(param_4, param_5) & 7;
            int2 param_6 = cell;
            int param_7 = 5;
            int part1 = maskAt(param_6, param_7) & 7;
            if ((part0 != 0) || (part1 != 0))
            {
                int2 param_8 = cell;
                int param_9 = 0;
                float param_10 = here.z;
                float cellBase0 = floorAt(param_8, param_9, param_10);
                int2 param_11 = cell;
                int param_12 = 1;
                float param_13 = cellBase0 + 2.9500000476837158203125f;
                float floor1 = floorAt(param_11, param_12, param_13);
                for (int _pass = 0; _pass < 2; _pass++)
                {
                    if (_pass == 0)
                    {
                        _2448 = (part0 != 0) ? part0 : part1;
                    }
                    else
                    {
                        _2448 = (((part0 != 0) && (part1 != 0)) && (part1 != part0)) ? part1 : 0;
                    }
                    int part = _2448;
                    if (part == 0)
                    {
                        continue;
                    }
                    bool diag0 = part == part0;
                    bool diag1 = part == part1;
                    if (part <= 2)
                    {
                        _2485 = direction.x - direction.y;
                    }
                    else
                    {
                        _2485 = direction.x + direction.y;
                    }
                    float denom = _2485;
                    if (abs(denom) > 9.9999997473787516355514526367188e-05f)
                    {
                        if (part <= 2)
                        {
                            _2508 = ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom;
                        }
                        else
                        {
                            _2508 = ((1.0f - (start.x - float(cell.x))) - (start.y - float(cell.y))) / denom;
                        }
                        float tDiag = _2508;
                        bool _2547 = tDiag > (tPrev + 9.9999997473787516355514526367188e-05f);
                        bool _2554;
                        if (_2547)
                        {
                            _2554 = tDiag <= (t + 9.9999997473787516355514526367188e-05f);
                        }
                        else
                        {
                            _2554 = _2547;
                        }
                        if (_2554 && (tDiag <= maxDist))
                        {
                            float2 uDiag = (start + (direction * tDiag)) - float2(cell);
                            bool _2574 = all(bool2(uDiag.x >= (-0.00999999977648258209228515625f).xx.x, uDiag.y >= (-0.00999999977648258209228515625f).xx.y));
                            bool _2582;
                            if (_2574)
                            {
                                _2582 = all(bool2(uDiag.x <= 1.0099999904632568359375f.xx.x, uDiag.y <= 1.0099999904632568359375f.xx.y));
                            }
                            else
                            {
                                _2582 = _2574;
                            }
                            if (_2582)
                            {
                                float wallBot = diag0 ? cellBase0 : floor1;
                                if (diag1)
                                {
                                    _2592 = floor1 + 2.9500000476837158203125f;
                                }
                                else
                                {
                                    _2592 = cellBase0 + 2.9500000476837158203125f;
                                }
                                float wallTop = _2592;
                                if (here.z < (wallTop - topGuard))
                                {
                                    float zDiag = startZ + (tDiag * rise);
                                    float pen = min((0.04500000178813934326171875f * tDiag) + 0.0350000001490116119384765625f, 0.5f);
                                    float wallV = smoothstep(wallBot - 0.039999999105930328369140625f, wallBot + 0.039999999105930328369140625f, zDiag) * (1.0f - smoothstep(wallTop - (0.25f * pen), wallTop + (0.75f * pen), zDiag));
                                    float winOpen = 0.0f;
                                    int winRow = int(zDiag >= floor1);
                                    bool hasWinDiag = (winRow == 0) ? diag0 : diag1;
                                    bool _2665;
                                    if (hasWinDiag)
                                    {
                                        _2665 = (((winRow == 0) ? curM0 : curM1) & 1) != 0;
                                    }
                                    else
                                    {
                                        _2665 = hasWinDiag;
                                    }
                                    if (_2665)
                                    {
                                        float relH = zDiag - ((winRow == 0) ? cellBase0 : floor1);
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
                        }
                    }
                }
                if (vis <= 0.00999999977648258209228515625f)
                {
                    break;
                }
            }
        }
        if (t > maxDist)
        {
            break;
        }
        float zCross = startZ + (t * rise);
        if (alongX)
        {
            _2767 = int2(stepDir.x, 0);
        }
        else
        {
            _2767 = int2(0, stepDir.y);
        }
        int2 to = cell + _2767;
        int2 param_14 = to;
        int param_15 = 0;
        int nextM0 = maskAt(param_14, param_15);
        int2 param_16 = to;
        int param_17 = 1;
        int nextM1 = maskAt(param_16, param_17);
        if ((((curM0 >= 2) || (curM1 >= 2)) || (nextM0 >= 2)) || (nextM1 >= 2))
        {
            int2 param_18 = to;
            int param_19 = 0;
            float param_20 = here.z;
            int2 param_21 = cell;
            int param_22 = 0;
            float param_23 = floorAt(param_18, param_19, param_20);
            float base0 = floorAt(param_21, param_22, param_23);
            if (zCross > ((base0 + 5.900000095367431640625f) + 0.25f))
            {
                break;
            }
            float2 crossing = start + (direction * t);
            if (alongX)
            {
                _2831 = float2(float(stepDir.x), 0.0f);
            }
            else
            {
                _2831 = float2(0.0f, float(stepDir.y));
            }
            float2 edgeStep = _2831;
            float2 localA = (crossing - float2(cell)) - (edgeStep * 0.00999999977648258209228515625f);
            float2 localB = (crossing - float2(to)) + (edgeStep * 0.00999999977648258209228515625f);
            if (curM0 >= 2)
            {
                int2 param_24 = cell;
                int param_25 = 0;
                float2 param_26 = localA;
                _2863 = effectiveRoomAt(param_24, param_25, param_26);
            }
            else
            {
                _2863 = 0;
            }
            int r0A = _2863;
            if (nextM0 >= 2)
            {
                int2 param_27 = to;
                int param_28 = 0;
                float2 param_29 = localB;
                _2877 = effectiveRoomAt(param_27, param_28, param_29);
            }
            else
            {
                _2877 = 0;
            }
            int r0B = _2877;
            if (curM1 >= 2)
            {
                int2 param_30 = cell;
                int param_31 = 1;
                float2 param_32 = localA;
                _2891 = effectiveRoomAt(param_30, param_31, param_32);
            }
            else
            {
                _2891 = 0;
            }
            int r1A = _2891;
            if (nextM1 >= 2)
            {
                int2 param_33 = to;
                int param_34 = 1;
                float2 param_35 = localB;
                _2905 = effectiveRoomAt(param_33, param_34, param_35);
            }
            else
            {
                _2905 = 0;
            }
            int r1B = _2905;
            bool _2919 = r0A != r0B;
            bool _2927;
            if (_2919)
            {
                _2927 = (r0A > 0) || (r0B > 0);
            }
            else
            {
                _2927 = _2919;
            }
            bool hasWall0 = _2927;
            bool _2931 = r1A != r1B;
            bool _2939;
            if (_2931)
            {
                _2939 = (r1A > 0) || (r1B > 0);
            }
            else
            {
                _2939 = _2931;
            }
            bool hasWall1 = _2939;
            if (hasWall0 || hasWall1)
            {
                int2 param_36 = to;
                int param_37 = 1;
                float param_38 = base0 + 2.9500000476837158203125f;
                int2 param_39 = cell;
                int param_40 = 1;
                float param_41 = floorAt(param_36, param_37, param_38);
                float floor1_1 = floorAt(param_39, param_40, param_41);
                float wallBot_1 = hasWall0 ? base0 : floor1_1;
                if (hasWall1)
                {
                    _2965 = floor1_1 + 2.9500000476837158203125f;
                }
                else
                {
                    _2965 = base0 + 2.9500000476837158203125f;
                }
                float wallTop_1 = _2965;
                if (here.z < (wallTop_1 - topGuard))
                {
                    float pen_1 = min((0.04500000178813934326171875f * t) + 0.0350000001490116119384765625f, 0.5f);
                    float wallV_1 = smoothstep(wallBot_1 - 0.039999999105930328369140625f, wallBot_1 + 0.039999999105930328369140625f, zCross) * (1.0f - smoothstep(wallTop_1 - (0.25f * pen_1), wallTop_1 + (0.75f * pen_1), zCross));
                    float winOpen_1 = 0.0f;
                    int winRow_1 = int(zCross >= floor1_1);
                    bool hasWinWall = (winRow_1 == 0) ? hasWall0 : hasWall1;
                    bool _3028;
                    if (hasWinWall)
                    {
                        _3028 = (((winRow_1 == 0) ? curM0 : curM1) & 1) != 0;
                    }
                    else
                    {
                        _3028 = hasWinWall;
                    }
                    bool _3038;
                    if (_3028)
                    {
                        _3038 = (((winRow_1 == 0) ? nextM0 : nextM1) & 1) != 0;
                    }
                    else
                    {
                        _3038 = _3028;
                    }
                    if (_3038)
                    {
                        float relH_1 = zCross - ((winRow_1 == 0) ? base0 : floor1_1);
                        if (alongX)
                        {
                            _3051 = crossing.y;
                        }
                        else
                        {
                            _3051 = crossing.x;
                        }
                        float along_1 = frac(_3051);
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
        curM0 = nextM0;
        curM1 = nextM1;
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

float canopyBlockedTexel(int4 data, float canopyClearZ, float qPrevZ, float qZ, float pen)
{
    bool _1119 = data.w == 0;
    bool _1127;
    if (!_1119)
    {
        _1127 = data.w == 255;
    }
    else
    {
        _1127 = _1119;
    }
    if (_1127)
    {
        return 0.0f;
    }
    float qBase = float(((data.y * 256) + data.z) - 32768) / 256.0f;
    float prevRel = qPrevZ - qBase;
    float curRel = qZ - qBase;
    bool hasCeil1 = (data.x & 32) != 0;
    bool hasStory2 = (data.x & 64) != 0;
    float _1165;
    if (data.w >= 2)
    {
        _1165 = float(data.w - 2) / 16.0f;
    }
    else
    {
        _1165 = -1.0f;
    }
    float canopyTop = _1165;
    float botPen = min(pen, 0.14000000059604644775390625f);
    float topPen = min(pen, 0.550000011920928955078125f);
    float occ = 0.0f;
    if (hasCeil1 && (canopyClearZ < 2.9500000476837158203125f))
    {
        float top1 = max(canopyTop, 3.13000011444091796875f);
        occ = max(occ, smoothstep(2.849999904632568359375f - botPen, 2.849999904632568359375f + botPen, curRel) * (1.0f - smoothstep(top1 - (0.3499999940395355224609375f * topPen), top1 + (0.64999997615814208984375f * topPen), prevRel)));
    }
    if (hasStory2 && (canopyClearZ < 5.900000095367431640625f))
    {
        float bot2 = (canopyClearZ < 2.9500000476837158203125f) ? 2.849999904632568359375f : 5.80000019073486328125f;
        float top2 = max(canopyTop, 6.0799999237060546875f);
        occ = max(occ, smoothstep(bot2 - botPen, bot2 + botPen, curRel) * (1.0f - smoothstep(top2 - (0.3499999940395355224609375f * topPen), top2 + (0.64999997615814208984375f * topPen), prevRel)));
    }
    if (canopyTop >= 2.900000095367431640625f)
    {
        float eaveBase = (canopyTop >= 5.849999904632568359375f) ? 5.900000095367431640625f : 2.9500000476837158203125f;
        if (canopyClearZ < eaveBase)
        {
            float topR = max(canopyTop, eaveBase + 0.180000007152557373046875f);
            occ = max(occ, smoothstep((eaveBase - 0.14000000059604644775390625f) - botPen, (eaveBase - 0.14000000059604644775390625f) + botPen, curRel) * (1.0f - smoothstep(topR - (0.3499999940395355224609375f * topPen), topR + (0.64999997615814208984375f * topPen), prevRel)));
        }
    }
    return occ;
}

float canopyOcclusionAt(float2 _point, float canopyClearZ, float qPrevZ, float qZ, float pen)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _1314;
    if (orientation == 1)
    {
        _1314 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1328;
        if (orientation == 2)
        {
            _1328 = size - _point;
        }
        else
        {
            float2 _1337;
            if (orientation == 3)
            {
                _1337 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1337 = _point;
            }
            _1328 = _1337;
        }
        _1314 = _1328;
    }
    float2 source = _1314;
    bool _1355 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _1363;
    if (!_1355)
    {
        _1363 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _1363 = _1355;
    }
    if (_1363)
    {
        return 0.0f;
    }
    uint _1370_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1370_dummy_parameter));
    float2 fPos = (source * (float2(mapSize) / max(size, 1.0f.xx))) - 0.5f.xx;
    int2 i0 = int2(floor(fPos));
    float2 f = frac(fPos);
    int2 maxIdx = mapSize - int2(1, 1);
    int4 c00 = int4((overheadMap.Load(int3(clamp(i0, int2(0, 0), maxIdx), 0)) * 255.0f) + 0.5f.xxxx);
    int4 c10 = int4((overheadMap.Load(int3(clamp(i0 + int2(1, 0), int2(0, 0), maxIdx), 0)) * 255.0f) + 0.5f.xxxx);
    int4 c01 = int4((overheadMap.Load(int3(clamp(i0 + int2(0, 1), int2(0, 0), maxIdx), 0)) * 255.0f) + 0.5f.xxxx);
    int4 c11 = int4((overheadMap.Load(int3(clamp(i0 + int2(1, 1), int2(0, 0), maxIdx), 0)) * 255.0f) + 0.5f.xxxx);
    bool _1446 = c00.w != 0;
    bool _1452;
    if (_1446)
    {
        _1452 = c00.w != 255;
    }
    else
    {
        _1452 = _1446;
    }
    bool v00 = _1452;
    bool _1456 = c10.w != 0;
    bool _1462;
    if (_1456)
    {
        _1462 = c10.w != 255;
    }
    else
    {
        _1462 = _1456;
    }
    bool v10 = _1462;
    bool _1466 = c01.w != 0;
    bool _1472;
    if (_1466)
    {
        _1472 = c01.w != 255;
    }
    else
    {
        _1472 = _1466;
    }
    bool v01 = _1472;
    bool _1476 = c11.w != 0;
    bool _1482;
    if (_1476)
    {
        _1482 = c11.w != 255;
    }
    else
    {
        _1482 = _1476;
    }
    bool v11 = _1482;
    if ((((!v00) && (!v10)) && (!v01)) && (!v11))
    {
        return 0.0f;
    }
    int4 param = c00;
    float param_1 = canopyClearZ;
    float param_2 = qPrevZ;
    float param_3 = qZ;
    float param_4 = pen;
    float b00 = canopyBlockedTexel(param, param_1, param_2, param_3, param_4);
    int4 param_5 = c10;
    float param_6 = canopyClearZ;
    float param_7 = qPrevZ;
    float param_8 = qZ;
    float param_9 = pen;
    float b10 = canopyBlockedTexel(param_5, param_6, param_7, param_8, param_9);
    int4 param_10 = c01;
    float param_11 = canopyClearZ;
    float param_12 = qPrevZ;
    float param_13 = qZ;
    float param_14 = pen;
    float b01 = canopyBlockedTexel(param_10, param_11, param_12, param_13, param_14);
    int4 param_15 = c11;
    float param_16 = canopyClearZ;
    float param_17 = qPrevZ;
    float param_18 = qZ;
    float param_19 = pen;
    float b11 = canopyBlockedTexel(param_15, param_16, param_17, param_18, param_19);
    return lerp(lerp(b00, b10, f.x), lerp(b01, b11, f.x), f.y);
}

float2 hiddenAtWorld(float2 wp, float key, float2 wSize, float shellDepth, float frontSoft)
{
    bool _1667 = any(bool2(wp.x < 1.0f.xx.x, wp.y < 1.0f.xx.y));
    bool _1677;
    if (!_1667)
    {
        float2 _1674 = wSize - 1.0f.xx;
        _1677 = any(bool2(wp.x >= _1674.x, wp.y >= _1674.y));
    }
    else
    {
        _1677 = _1667;
    }
    if (_1677)
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
    float4 bFront = ((0.89999997615814208984375f.xxxx - wFront) / 0.0030000000260770320892333984375f.xxxx) - key.xxxx;
    float4 vis = (vFront * smoothstep((0.37999999523162841796875f * shellDepth).xxxx, (0.819999992847442626953125f * shellDepth).xxxx, bFront)) * (1.0f.xxxx - smoothstep(1.85000002384185791015625f.xxxx, 2.75f.xxxx, bFront));
    float4 shlF = (vFront * clamp((bFront + (0.550000011920928955078125f * frontSoft).xxxx) / frontSoft.xxxx, 0.0f.xxxx, 1.0f.xxxx)) * clamp((shellDepth.xxxx - bFront) / backSoft.xxxx, 0.0f.xxxx, 1.0f.xxxx);
    float4 shl = shlF;
    if (min(min(shlF.x, shlF.y), min(shlF.z, shlF.w)) < 0.9900000095367431640625f)
    {
        float4 wBack = worldBackDepthMap.GatherRed(_worldBackDepthMap_sampler, uv);
        float4 vBack = step(9.9999997473787516355514526367188e-05f.xxxx, wBack) * step(wBack, 0.99989998340606689453125f.xxxx);
        float4 bBack = ((0.89999997615814208984375f.xxxx - wBack) / 0.0030000000260770320892333984375f.xxxx) - key.xxxx;
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
        uint _1923_dummy_parameter;
        float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _1923_dummy_parameter)));
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
    bool _1996 = any(bool2(pixel.x < 0.0f.xx.x, pixel.y < 0.0f.xx.y));
    bool _2005;
    if (!_1996)
    {
        _2005 = pixel.x >= ambient_extent.x;
    }
    else
    {
        _2005 = _1996;
    }
    bool _2014;
    if (!_2005)
    {
        _2014 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _2014 = _2005;
    }
    if (_2014)
    {
        return float2(1.0f, 0.0f);
    }
    float depth = depthMap.Load(int3(int2(pixel), 0)).x;
    if (depth < 1.0f)
    {
        float behind = ((0.89999997615814208984375f - depth) / 0.0030000000260770320892333984375f) - key;
        float backSoft = max(0.14000000059604644775390625f, 0.4799999892711639404296875f * shellDepth);
        return float2(clamp((behind + 0.0599999986588954925537109375f) / 0.180000007152557373046875f, 0.0f, 1.0f), clamp((behind + (0.550000011920928955078125f * frontSoft)) / frontSoft, 0.0f, 1.0f) * clamp((shellDepth - behind) / backSoft, 0.0f, 1.0f));
    }
    float ground = groundMap.Load(int3(int2(pixel), 0)).x;
    if (ground >= 1.0f)
    {
        return 0.0f.xx;
    }
    float2 param_5 = scene;
    float param_6 = ((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w;
    bool param_7 = true;
    float2 param_8 = ambient_frame.xy;
    float3 lot = lotPoint(param_5, param_6, param_7, param_8);
    return float2(clamp(((((lot.x + lot.y) + (0.800000011920928955078125f * lot.z)) - key) + 0.4000000059604644775390625f) / 0.300000011920928955078125f, 0.0f, 1.0f), 0.0f);
}

float3 sunMarch(float3 here, float start, float canopyClearZ)
{
    float lit = 1.0f;
    float litColumn = 1.0f;
    float litShell = 1.0f;
    uint _4222_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _4222_dummy_parameter)));
    int2 hMax = int2(gridSize) - int2(1, 1);
    uint _4232_dummy_parameter;
    int2 vSize = int2(spvTextureSize(voxelMap, uint(0), _4232_dummy_parameter));
    bool hasVoxels = vSize.x > 1;
    float2 sunProj = float2(32.0f * (ambient_sunLot.x - ambient_sunLot.y), (16.0f * (ambient_sunLot.x + ambient_sunLot.y)) - (40.0f * ambient_sunLot.z));
    float projLen = length(sunProj);
    float2 _4261;
    if (projLen > 0.001000000047497451305389404296875f)
    {
        _4261 = sunProj / projLen.xx;
    }
    else
    {
        _4261 = float2(1.0f, 0.0f);
    }
    float2 sunDirPx = _4261;
    float2 sunPerp = float2(-sunDirPx.y, sunDirPx.x);
    float maxReach = ambient_sunLot.w + 0.20000000298023223876953125f;
    float maxT = min(maxReach, 10.5f / max(ambient_sunLot.z, 0.14000000059604644775390625f));
    if (maxT <= (start + 0.0199999995529651641845703125f))
    {
        return 1.0f.xxx;
    }
    float wScale = max(ambient_shadowView.z, 0.5f);
    float dtBase = clamp(1.4500000476837158203125f / max(projLen, 18.0f), 0.04500000178813934326171875f, 0.0599999986588954925537109375f);
    float2 param = floor(gl_FragCoord.xy);
    float tNoise = _noise(param);
    float2 param_1 = floor(gl_FragCoord.xy) + float2(37.0f, 17.0f);
    float tRad = sqrt(_noise(param_1));
    float tAng = tNoise * 6.283185482025146484375f;
    float2 diskJitter = float2(cos(tAng), sin(tAng)) * (0.550000011920928955078125f * tRad);
    float phase = tNoise;
    float signedKeyRate = (ambient_sunLot.x + ambient_sunLot.y) + (0.800000011920928955078125f * ambient_sunLot.z);
    float keyRate = abs(signedKeyRate);
    float keyPerPx = signedKeyRate / max(projLen * wScale, 1.0f);
    float sunHorizLen = length(ambient_sunLot.xy);
    float2 _4369;
    if (sunHorizLen > 9.9999997473787516355514526367188e-05f)
    {
        _4369 = (float2(-ambient_sunLot.y, ambient_sunLot.x) / sunHorizLen.xx) * 0.949999988079071044921875f;
    }
    else
    {
        _4369 = float2(0.949999988079071044921875f, 0.0f);
    }
    float2 perpTexel = _4369;
    float solidRun = 0.0f;
    float3 qPrev = here;
    float t = start + (dtBase * (1.0f - phase));
    float _4554;
    float _4780;
    for (int i = 0; i < 64; i++)
    {
        if (t > maxT)
        {
            break;
        }
        float dt = dtBase + (0.0320000015199184417724609375f * (t - start));
        float3 q = here + (ambient_sunLot.xyz * t);
        if ((q.z - here.z) > 10.5f)
        {
            break;
        }
        float2 texel = (q.xy + ambient_frame.w.xx) * ambient_frame.z;
        bool _4447 = any(bool2(texel.x < 1.0f.xx.x, texel.y < 1.0f.xx.y));
        bool _4457;
        if (!_4447)
        {
            float2 _4454 = gridSize - 1.0f.xx;
            _4457 = any(bool2(texel.x > _4454.x, texel.y > _4454.y));
        }
        else
        {
            _4457 = _4447;
        }
        if (_4457)
        {
            break;
        }
        float startFade = smoothstep(0.0f, dtBase, t - start);
        float distFade = (1.0f - smoothstep(maxReach * 0.86000001430511474609375f, maxReach, t)) * startFade;
        float2 param_2 = q.xy;
        float param_3 = canopyClearZ;
        float param_4 = qPrev.z;
        float param_5 = q.z;
        float param_6 = (0.064999997615814208984375f * t) + 0.039999999105930328369140625f;
        float canopyOcc = canopyOcclusionAt(param_2, param_3, param_4, param_5, param_6);
        lit = min(lit, 1.0f - (canopyOcc * distFade));
        litColumn = min(litColumn, 1.0f - (canopyOcc * distFade));
        if ((lit <= 0.00999999977648258209228515625f) && (litColumn <= 0.00999999977648258209228515625f))
        {
            break;
        }
        int2 qCell = int2(floor(q.xy + ambient_frame.w.xx));
        int2 param_7 = qCell;
        int param_8 = 0;
        float param_9 = here.z;
        float qBase0 = floorAt(param_7, param_8, param_9);
        int qRow = int(q.z > ((qBase0 + 2.9500000476837158203125f) - 0.0500000007450580596923828125f));
        bool skipWindow = false;
        int2 param_10 = qCell;
        int param_11 = qRow;
        if ((maskAt(param_10, param_11) & 1) != 0)
        {
            if (qRow == 0)
            {
                _4554 = qBase0;
            }
            else
            {
                int2 param_12 = qCell;
                int param_13 = 1;
                float param_14 = qBase0 + 2.9500000476837158203125f;
                _4554 = floorAt(param_12, param_13, param_14);
            }
            float qFloorH = _4554;
            float qRelH = q.z - qFloorH;
            if ((qRelH > 0.670000016689300537109375f) && (qRelH < 2.4300000667572021484375f))
            {
                float2 qFrac = frac(q.xy + ambient_frame.w.xx);
                float edgeDist = min(min(qFrac.x, 1.0f - qFrac.x), min(qFrac.y, 1.0f - qFrac.y));
                skipWindow = edgeDist < 0.2199999988079071044921875f;
            }
        }
        if (!skipWindow)
        {
            float spreadPx = clamp(0.180000007152557373046875f + (t * 0.64999997615814208984375f), 0.180000007152557373046875f, 2.7999999523162841796875f) * wScale;
            if (hasVoxels)
            {
                float3 param_15 = q;
                int2 param_16 = vSize;
                float2 param_17 = max(ambient_drift.zw, 1.0f.xx);
                float2 param_18 = diskJitter;
                float param_19 = spreadPx;
                float hullOcc = dualViewHullAt(param_15, param_16, param_17, param_18, param_19);
                float3 param_20 = q;
                float param_21 = 0.1599999964237213134765625f + (0.0199999995529651641845703125f * spreadPx);
                float simOcc = dynamicSimOccAt(param_20, param_21) * smoothstep(0.100000001490116119384765625f, 0.23999999463558197021484375f, t);
                float occ = max(hullOcc, simOcc) * distFade;
                lit = min(lit, 1.0f - occ);
                litColumn = min(litColumn, 1.0f - occ);
                if ((lit <= 0.00999999977648258209228515625f) && (litColumn <= 0.00999999977648258209228515625f))
                {
                    break;
                }
            }
            else
            {
                float penZ = (0.07999999821186065673828125f * t) + 0.04500000178813934326171875f;
                float4 tops = (0.5f.xxxx - heightMap.GatherRed(_heightMap_sampler, texel / gridSize)) * 64.0f;
                float4 blocked = clamp(((tops - q.z.xxxx) - 0.0599999986588954925537109375f.xxxx) / penZ.xxxx, 0.0f.xxxx, 1.0f.xxxx);
                float2 f = frac(texel - 0.5f.xx);
                float rawColumn = lerp(lerp(blocked.w, blocked.z, f.x), lerp(blocked.x, blocked.y, f.x), f.y);
                float coreColumn = 0.0f;
                if (rawColumn > 0.449999988079071044921875f)
                {
                    float topL = (0.5f - heightMap.Load(int3(clamp(int2(floor(texel + perpTexel)), int2(0, 0), hMax), 0)).x) * 64.0f;
                    float topR = (0.5f - heightMap.Load(int3(clamp(int2(floor(texel - perpTexel)), int2(0, 0), hMax), 0)).x) * 64.0f;
                    float sideBlocked = min(clamp(((topL - q.z) - 0.0599999986588954925537109375f) / penZ, 0.0f, 1.0f), clamp(((topR - q.z) - 0.0599999986588954925537109375f) / penZ, 0.0f, 1.0f));
                    float eroded = min(rawColumn, sideBlocked);
                    if (eroded > 0.5f)
                    {
                        _4780 = solidRun + dt;
                    }
                    else
                    {
                        _4780 = max(0.0f, solidRun - (2.0f * dt));
                    }
                    solidRun = _4780;
                    coreColumn = smoothstep(0.449999988079071044921875f, 0.85000002384185791015625f, eroded) * smoothstep(0.0599999986588954925537109375f, 0.1599999964237213134765625f, solidRun);
                }
                else
                {
                    solidRun = max(0.0f, solidRun - (2.0f * dt));
                }
                float stepKey = keyRate * dt;
                float canopyLift = smoothstep(1.5f, 3.2000000476837158203125f, q.z - here.z);
                float frontSoft = 0.14000000059604644775390625f + (0.054999999701976776123046875f * t);
                float shellDepth = (max(0.2199999988079071044921875f, (stepKey * 1.7999999523162841796875f) + 0.1599999964237213134765625f) + (0.1599999964237213134765625f * coreColumn)) + (0.2199999988079071044921875f * canopyLift);
                float3 param_22 = q;
                float param_23 = spreadPx;
                float2 param_24 = sunPerp;
                float2 param_25 = sunDirPx;
                float param_26 = keyPerPx;
                float param_27 = shellDepth;
                float param_28 = frontSoft;
                float2 param_29 = diskJitter;
                float2 seen = hiddenAtSoft(param_22, param_23, param_24, param_25, param_26, param_27, param_28, param_29);
                float shell = seen.y * (1.0f / (1.0f + (0.02500000037252902984619140625f * t)));
                float colVis = seen.x;
                float occ_1 = max(coreColumn * colVis, shell) * distFade;
                lit = min(lit, 1.0f - occ_1);
                litColumn = min(litColumn, 1.0f - (coreColumn * distFade));
                litShell = min(litShell, 1.0f - (shell * distFade));
                if ((lit <= 0.00999999977648258209228515625f) && (litColumn <= 0.00999999977648258209228515625f))
                {
                    break;
                }
            }
        }
        qPrev = q;
        t += dt;
    }
    return float3(lit, litColumn, litShell);
}

float2 lotSource(float2 camera)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _813;
    if (orientation == 1)
    {
        _813 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _827;
        if (orientation == 2)
        {
            _827 = size - camera;
        }
        else
        {
            float2 _836;
            if (orientation == 3)
            {
                _836 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _836 = camera;
            }
            _827 = _836;
        }
        _813 = _827;
    }
    return _813;
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
    bool _2111 = cover <= 0.0f;
    bool _2118;
    if (!_2111)
    {
        _2118 = ambient_clouds.y <= 0.0f;
    }
    else
    {
        _2118 = _2111;
    }
    if (_2118)
    {
        return 1.0f;
    }
    float3 sun = ambient_sunLot.xyz;
    float2 param = lot.xy + ((sun.xy * (ambient_clouds.w - lot.z)) / max(sun.z, 0.25f).xx);
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
    float _5009;
    float _5067;
    float _5090;
    float _5163;
    int2 _5242;
    float2 _5282;
    float _5339;
    int2 _5400;
    for (int i = 0; i < 16; i++)
    {
        bool alongX = next.x < next.y;
        if (alongX)
        {
            _5009 = next.x;
        }
        else
        {
            _5009 = next.y;
        }
        float t = _5009;
        float segEnd = min(t, maxT);
        if (segEnd > tPrev)
        {
            float zMid = here.z + ((0.5f * (tPrev + segEnd)) * rise);
            int2 param = cell;
            int param_1 = 0;
            float param_2 = here.z;
            float cellBase0 = floorAt(param, param_1, param_2);
            int rowCell = int(zMid > ((cellBase0 + 2.9500000476837158203125f) - 0.0500000007450580596923828125f));
            int2 param_3 = cell;
            int param_4 = rowCell + 4;
            int part = maskAt(param_3, param_4) & 7;
            if (part != 0)
            {
                if (part <= 2)
                {
                    _5067 = direction.x - direction.y;
                }
                else
                {
                    _5067 = direction.x + direction.y;
                }
                float denom = _5067;
                if (abs(denom) > 9.9999997473787516355514526367188e-05f)
                {
                    if (part <= 2)
                    {
                        _5090 = ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom;
                    }
                    else
                    {
                        _5090 = ((1.0f - (start.x - float(cell.x))) - (start.y - float(cell.y))) / denom;
                    }
                    float tDiag = _5090;
                    bool _5130 = tDiag > max(tPrev, 0.02999999932944774627685546875f);
                    bool _5137;
                    if (_5130)
                    {
                        _5137 = tDiag <= (segEnd + 9.9999997473787516355514526367188e-05f);
                    }
                    else
                    {
                        _5137 = _5130;
                    }
                    if (_5137)
                    {
                        float2 uDiag = (start + (direction * tDiag)) - float2(cell);
                        bool _5151 = all(bool2(uDiag.x >= (-0.00999999977648258209228515625f).xx.x, uDiag.y >= (-0.00999999977648258209228515625f).xx.y));
                        bool _5157;
                        if (_5151)
                        {
                            _5157 = all(bool2(uDiag.x <= 1.0099999904632568359375f.xx.x, uDiag.y <= 1.0099999904632568359375f.xx.y));
                        }
                        else
                        {
                            _5157 = _5151;
                        }
                        if (_5157)
                        {
                            if (rowCell == 0)
                            {
                                _5163 = cellBase0;
                            }
                            else
                            {
                                int2 param_5 = cell;
                                int param_6 = 1;
                                float param_7 = cellBase0 + 2.9500000476837158203125f;
                                _5163 = floorAt(param_5, param_6, param_7);
                            }
                            float floorH = _5163;
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
            float zCross = here.z + (t * rise);
            if (alongX)
            {
                _5242 = int2(stepDir.x, 0);
            }
            else
            {
                _5242 = int2(0, stepDir.y);
            }
            int2 to = cell + _5242;
            int2 param_8 = to;
            int param_9 = 0;
            float param_10 = here.z;
            int2 param_11 = cell;
            int param_12 = 0;
            float param_13 = floorAt(param_8, param_9, param_10);
            float base0 = floorAt(param_11, param_12, param_13);
            int row = int(zCross > ((base0 + 2.9500000476837158203125f) - 0.0500000007450580596923828125f));
            float2 crossing = start + (direction * t);
            if (alongX)
            {
                _5282 = float2(float(stepDir.x), 0.0f);
            }
            else
            {
                _5282 = float2(0.0f, float(stepDir.y));
            }
            float2 edgeStep = _5282;
            int2 param_14 = cell;
            int param_15 = row;
            float2 param_16 = (crossing - float2(cell)) - (edgeStep * 0.00999999977648258209228515625f);
            int roomA = effectiveRoomAt(param_14, param_15, param_16);
            int2 param_17 = to;
            int param_18 = row;
            float2 param_19 = (crossing - float2(to)) + (edgeStep * 0.00999999977648258209228515625f);
            int roomB = effectiveRoomAt(param_17, param_18, param_19);
            bool _5325 = roomA != roomB;
            bool _5333;
            if (_5325)
            {
                _5333 = (roomA > 0) || (roomB > 0);
            }
            else
            {
                _5333 = _5325;
            }
            if (_5333)
            {
                if (row == 0)
                {
                    _5339 = base0;
                }
                else
                {
                    int2 param_20 = to;
                    int param_21 = 1;
                    float param_22 = base0 + 2.9500000476837158203125f;
                    int2 param_23 = cell;
                    int param_24 = 1;
                    float param_25 = floorAt(param_20, param_21, param_22);
                    _5339 = floorAt(param_23, param_24, param_25);
                }
                float floorH_1 = _5339;
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
            cell = to;
        }
        else
        {
            if (alongX)
            {
                _5400 = int2(stepDir.x, 0);
            }
            else
            {
                _5400 = int2(0, stepDir.y);
            }
            cell += _5400;
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

float lampMarch(float3 here, float3 lampLot, float onFlatFloor, float isVertical, float nUp, float2 horizN, bool isFire)
{
    float3 origin = here + float3(horizN * (0.1599999964237213134765625f * isVertical), 0.0f);
    float3 toReceiver = origin - lampLot;
    float dist3D = length(toReceiver);
    float horizTop = smoothstep(0.75f, 0.920000016689300537109375f, nUp) * step(origin.z + 0.20000000298023223876953125f, lampLot.z);
    float receiverClear = lerp(lerp(0.4799999892711639404296875f, 0.14000000059604644775390625f, max(isVertical, horizTop)), 0.07999999821186065673828125f, onFlatFloor);
    float rStart = isFire ? 0.519999980926513671875f : 0.4600000083446502685546875f;
    float rEnd = dist3D - receiverClear;
    if (rEnd <= (rStart + 0.02999999932944774627685546875f))
    {
        return 1.0f;
    }
    float3 outDir = toReceiver / dist3D.xxx;
    uint _5494_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _5494_dummy_parameter)));
    int2 hMax = int2(gridSize) - int2(1, 1);
    uint _5504_dummy_parameter;
    int2 vSize = int2(spvTextureSize(voxelMap, uint(0), _5504_dummy_parameter));
    bool hasVoxels = vSize.x > 1;
    float2 lotSz = max(ambient_drift.zw, 1.0f.xx);
    float2 rayProj = float2(32.0f * (outDir.x - outDir.y), (16.0f * (outDir.x + outDir.y)) - (40.0f * outDir.z));
    float projLen = length(rayProj);
    float2 _5538;
    if (projLen > 0.001000000047497451305389404296875f)
    {
        _5538 = rayProj / projLen.xx;
    }
    else
    {
        _5538 = float2(1.0f, 0.0f);
    }
    float2 rayDirPx = _5538;
    float2 rayPerp = float2(-rayDirPx.y, rayDirPx.x);
    float wScale = max(ambient_shadowView.z, 0.5f);
    float drBase = clamp(2.400000095367431640625f / max(projLen * wScale, 22.0f), 0.048000000417232513427734375f, 0.08200000226497650146484375f);
    float farAccel = max(0.0f, ((rEnd - rStart) - (36.0f * drBase)) / 136.0f);
    float signedKeyRate = (outDir.x + outDir.y) + (0.800000011920928955078125f * outDir.z);
    float keyRate = abs(signedKeyRate);
    float keyPerPx = signedKeyRate / max(projLen * wScale, 1.0f);
    float horizLen = length(outDir.xy);
    float2 _5607;
    if (horizLen > 9.9999997473787516355514526367188e-05f)
    {
        _5607 = (float2(-outDir.y, outDir.x) / horizLen.xx) * 1.4500000476837158203125f;
    }
    else
    {
        _5607 = float2(1.4500000476837158203125f, 0.0f);
    }
    float2 perpTexel = _5607;
    float lightRadiusScenePx = isFire ? 11.0f : 7.0f;
    float2 param = floor(gl_FragCoord.xy) + (lampLot.xy * 13.0f);
    float tNoise = _noise(param);
    float2 param_1 = (floor(gl_FragCoord.xy) + (lampLot.xy * 13.0f)) + float2(37.0f, 17.0f);
    float tRad = sqrt(_noise(param_1));
    float tAng = tNoise * 6.283185482025146484375f;
    float2 diskJitter = float2(cos(tAng), sin(tAng)) * (0.60000002384185791015625f * tRad);
    float r = rStart + ((tNoise * drBase) * 0.5f);
    float solidRun = 0.0f;
    float lit = 1.0f;
    float _5691;
    float _5899;
    for (int i = 0; i < 36; i++)
    {
        if (r >= rEnd)
        {
            break;
        }
        if (i < 20)
        {
            _5691 = drBase;
        }
        else
        {
            _5691 = drBase + (farAccel * float(i - 19));
        }
        float dr = _5691;
        float3 q = lampLot + (outDir * r);
        float xyFromLamp = length(q.xy - lampLot.xy);
        if (xyFromLamp >= (isFire ? 0.449999988079071044921875f : 0.4199999868869781494140625f))
        {
            float2 texel = (q.xy + ambient_frame.w.xx) * ambient_frame.z;
            bool _5737 = all(bool2(texel.x >= 1.0f.xx.x, texel.y >= 1.0f.xx.y));
            bool _5746;
            if (_5737)
            {
                float2 _5743 = gridSize - 1.0f.xx;
                _5746 = all(bool2(texel.x <= _5743.x, texel.y <= _5743.y));
            }
            else
            {
                _5746 = _5737;
            }
            if (_5746)
            {
                float dToReceiver = max(rEnd - r, 0.0f);
                float coneFrac = clamp(dToReceiver / max(dist3D, 0.3499999940395355224609375f), 0.0f, 1.0f);
                float spreadPx = clamp(0.319999992847442626953125f + (lightRadiusScenePx * coneFrac), 0.319999992847442626953125f, 4.400000095367431640625f) * wScale;
                float occ = 0.0f;
                if (hasVoxels)
                {
                    float3 param_2 = q;
                    int2 param_3 = vSize;
                    float2 param_4 = lotSz;
                    float2 param_5 = diskJitter;
                    float param_6 = spreadPx;
                    float3 param_7 = q;
                    float param_8 = 0.180000007152557373046875f;
                    occ = max(dualViewHullAt(param_2, param_3, param_4, param_5, param_6), dynamicSimOccAt(param_7, param_8));
                }
                else
                {
                    float penZ = 0.07999999821186065673828125f + (0.10999999940395355224609375f * dToReceiver);
                    float4 tops = (0.5f.xxxx - heightMap.GatherRed(_heightMap_sampler, texel / gridSize)) * 64.0f;
                    float4 blocked = clamp(((tops - q.z.xxxx) - 0.0500000007450580596923828125f.xxxx) / penZ.xxxx, 0.0f.xxxx, 1.0f.xxxx);
                    float2 f = frac(texel - 0.5f.xx);
                    float rawColumn = lerp(lerp(blocked.w, blocked.z, f.x), lerp(blocked.x, blocked.y, f.x), f.y);
                    float coreColumn = 0.0f;
                    if (rawColumn > 0.550000011920928955078125f)
                    {
                        float topL = (0.5f - heightMap.Load(int3(clamp(int2(floor(texel + perpTexel)), int2(0, 0), hMax), 0)).x) * 64.0f;
                        float topR = (0.5f - heightMap.Load(int3(clamp(int2(floor(texel - perpTexel)), int2(0, 0), hMax), 0)).x) * 64.0f;
                        float sideBlocked = min(clamp(((topL - q.z) - 0.0500000007450580596923828125f) / penZ, 0.0f, 1.0f), clamp(((topR - q.z) - 0.0500000007450580596923828125f) / penZ, 0.0f, 1.0f));
                        float eroded = min(rawColumn, sideBlocked);
                        if (eroded > 0.64999997615814208984375f)
                        {
                            _5899 = solidRun + dr;
                        }
                        else
                        {
                            _5899 = max(0.0f, solidRun - (2.0f * dr));
                        }
                        solidRun = _5899;
                        coreColumn = smoothstep(0.579999983310699462890625f, 0.920000016689300537109375f, eroded) * smoothstep(0.14000000059604644775390625f, 0.2800000011920928955078125f, solidRun);
                    }
                    else
                    {
                        solidRun = max(0.0f, solidRun - (2.0f * dr));
                    }
                    float stepKey = keyRate * dr;
                    float canopyLift = smoothstep(1.5f, 3.0f, max(0.0f, q.z - origin.z));
                    float frontSoft = 0.14000000059604644775390625f + (0.054999999701976776123046875f * dToReceiver);
                    float shellDepth = (max(0.180000007152557373046875f, (stepKey * 1.60000002384185791015625f) + 0.119999997317790985107421875f) + (0.1599999964237213134765625f * coreColumn)) + (0.20000000298023223876953125f * canopyLift);
                    float3 param_9 = q;
                    float param_10 = spreadPx;
                    float2 param_11 = rayPerp;
                    float2 param_12 = rayDirPx;
                    float param_13 = keyPerPx;
                    float param_14 = shellDepth;
                    float param_15 = frontSoft;
                    float2 param_16 = diskJitter;
                    float2 seen = hiddenAtSoft(param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16);
                    float shell = seen.y * (0.939999997615814208984375f / (1.0f + (0.039999999105930328369140625f * dToReceiver)));
                    occ = max(coreColumn * seen.x, shell);
                }
                float sourceFade = smoothstep(0.0f, 0.180000007152557373046875f, r - rStart);
                float receiverFade = smoothstep(0.0f, dr * 1.35000002384185791015625f, rEnd - r);
                lit = min(lit, 1.0f - ((occ * sourceFade) * receiverFade));
                if (lit <= 0.00999999977648258209228515625f)
                {
                    return 0.0f;
                }
            }
        }
        r += dr;
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

float2 sceneOf(float3 q)
{
    return float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
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
    float _3225;
    if (best > 9.9999997473787516355514526367188e-05f)
    {
        _3225 = clamp(bestFire / best, 0.0f, 1.0f);
    }
    else
    {
        _3225 = 0.0f;
    }
    return float2(clamp(best * 2.0f, 0.0f, 1.0f), _3225);
}

float2 windowSpillInfo(float3 here, float onGround)
{
    float2 at = here.xy + ambient_frame.w.xx;
    int2 cell = int2(floor(at));
    int2 param = cell;
    int param_1 = 0;
    float param_2 = here.z;
    float ground = floorAt(param, param_1, param_2);
    bool _3263 = onGround <= 0.5f;
    bool _3273;
    if (!_3263)
    {
        _3273 = here.z > ((ground + 2.9500000476837158203125f) - 0.100000001490116119384765625f);
    }
    else
    {
        _3273 = _3263;
    }
    bool _3282;
    if (!_3273)
    {
        int2 param_3 = cell;
        int param_4 = 0;
        _3282 = maskAt(param_3, param_4) >= 2;
    }
    else
    {
        _3282 = _3273;
    }
    if (_3282)
    {
        return 0.0f.xx;
    }
    float best = 0.0f;
    float3 source = 0.0f.xxx;
    float3 glass = 0.0f.xxx;
    int2 _3341;
    int2 _3347;
    for (int y = -3; y <= 3; y++)
    {
        for (int x = -3; x <= 3; x++)
        {
            int2 room = cell + int2(x, y);
            int2 param_5 = room;
            int param_6 = 0;
            int code = maskAt(param_5, param_6);
            bool _3319 = code < 2;
            bool _3326;
            if (!_3319)
            {
                _3326 = (code & 1) == 0;
            }
            else
            {
                _3326 = _3319;
            }
            if (_3326)
            {
                continue;
            }
            for (int d = 0; d < 4; d++)
            {
                if (d == 0)
                {
                    _3341 = int2(1, 0);
                }
                else
                {
                    if (d == 1)
                    {
                        _3347 = int2(-1, 0);
                    }
                    else
                    {
                        bool2 _3356 = (d == 2).xx;
                        _3347 = int2(_3356.x ? int2(0, 1).x : int2(0, -1).x, _3356.y ? int2(0, 1).y : int2(0, -1).y);
                    }
                    _3341 = _3347;
                }
                int2 _step = _3341;
                int2 param_7 = room + _step;
                int param_8 = 0;
                int outside = maskAt(param_7, param_8);
                bool _3368 = outside >= 2;
                bool _3375;
                if (!_3368)
                {
                    _3375 = (outside & 1) == 0;
                }
                else
                {
                    _3375 = _3368;
                }
                if (_3375)
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
    uint _3490_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _3490_dummy_parameter)));
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
        float top = (0.5f - heightMap.Sample(_heightMap_sampler, ((q.xy + ambient_frame.w.xx) * ambient_frame.z) / gridSize).x) * 64.0f;
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
    float2 _866;
    if (orientation == 1)
    {
        _866 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _880;
        if (orientation == 2)
        {
            _880 = size - _point.xy;
        }
        else
        {
            float2 _890;
            if (orientation == 3)
            {
                _890 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _890 = _point.xy;
            }
            _880 = _890;
        }
        _866 = _880;
    }
    float2 source = _866;
    bool _910 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _918;
    if (!_910)
    {
        _918 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _918 = _910;
    }
    if (_918)
    {
        return 1.0f;
    }
    uint _926_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _926_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
    uint _940_dummy_parameter;
    int2 _940 = int2(spvTextureSize(overheadMap, uint(0), _940_dummy_parameter));
    if (any(bool2(at.x >= _940.x, at.y >= _940.y)))
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
        bool _6191 = length(pT - pixel) < (0.699999988079071044921875f * rP);
        bool _6202;
        if (!_6191)
        {
            _6202 = length(pL - pR) < (0.75f * wP);
        }
        else
        {
            _6202 = _6191;
        }
        if (_6202)
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
        bool _6228 = qML.w < 0.25f;
        bool _6239;
        if (_6228)
        {
            _6239 = abs(qML.z - p0.z) < 14.0f;
        }
        else
        {
            _6239 = _6228;
        }
        bool _6245;
        if (_6239)
        {
            _6245 = qMR.w < 0.25f;
        }
        else
        {
            _6245 = _6239;
        }
        bool _6255;
        if (_6245)
        {
            _6255 = abs(qMR.z - p0.z) < 14.0f;
        }
        else
        {
            _6255 = _6245;
        }
        bool _6261;
        if (_6255)
        {
            _6261 = qT.w < 0.25f;
        }
        else
        {
            _6261 = _6255;
        }
        bool _6271;
        if (_6261)
        {
            _6271 = abs(qT.z - p0.z) < 22.0f;
        }
        else
        {
            _6271 = _6261;
        }
        bool _6277;
        if (_6271)
        {
            _6277 = qL.w < 0.25f;
        }
        else
        {
            _6277 = _6271;
        }
        bool _6287;
        if (_6277)
        {
            _6287 = abs(qL.z - p0.z) < 22.0f;
        }
        else
        {
            _6287 = _6277;
        }
        bool _6293;
        if (_6287)
        {
            _6293 = qR.w < 0.25f;
        }
        else
        {
            _6293 = _6287;
        }
        bool _6303;
        if (_6293)
        {
            _6303 = abs(qR.z - p0.z) < 22.0f;
        }
        else
        {
            _6303 = _6293;
        }
        bool _6314;
        if (_6303)
        {
            _6314 = abs(qL.z - qR.z) < 7.5f;
        }
        else
        {
            _6314 = _6303;
        }
        if (_6314)
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
                bool _6353 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.89999997615814208984375f);
                bool _6359;
                if (_6353)
                {
                    _6359 = nW.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _6359 = _6353;
                }
                bool _6366;
                if (_6359)
                {
                    _6366 = abs(nW.x) > 0.1500000059604644775390625f;
                }
                else
                {
                    _6366 = _6359;
                }
                if (_6366)
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
            bool _6507 = any(bool2(pML_1.x < 0.5f.xx.x, pML_1.y < 0.5f.xx.y));
            bool _6515;
            if (!_6507)
            {
                _6515 = any(bool2(pML_1.x > maxPx.x, pML_1.y > maxPx.y));
            }
            else
            {
                _6515 = _6507;
            }
            bool _6522;
            if (!_6515)
            {
                _6522 = any(bool2(pMR_1.x < 0.5f.xx.x, pMR_1.y < 0.5f.xx.y));
            }
            else
            {
                _6522 = _6515;
            }
            bool _6530;
            if (!_6522)
            {
                _6530 = any(bool2(pMR_1.x > maxPx.x, pMR_1.y > maxPx.y));
            }
            else
            {
                _6530 = _6522;
            }
            bool _6537;
            if (!_6530)
            {
                _6537 = any(bool2(pT_1.x < 0.5f.xx.x, pT_1.y < 0.5f.xx.y));
            }
            else
            {
                _6537 = _6530;
            }
            bool _6545;
            if (!_6537)
            {
                _6545 = any(bool2(pT_1.x > maxPx.x, pT_1.y > maxPx.y));
            }
            else
            {
                _6545 = _6537;
            }
            bool _6552;
            if (!_6545)
            {
                _6552 = any(bool2(pL_1.x < 0.5f.xx.x, pL_1.y < 0.5f.xx.y));
            }
            else
            {
                _6552 = _6545;
            }
            bool _6560;
            if (!_6552)
            {
                _6560 = any(bool2(pL_1.x > maxPx.x, pL_1.y > maxPx.y));
            }
            else
            {
                _6560 = _6552;
            }
            bool _6567;
            if (!_6560)
            {
                _6567 = any(bool2(pR_1.x < 0.5f.xx.x, pR_1.y < 0.5f.xx.y));
            }
            else
            {
                _6567 = _6560;
            }
            bool _6575;
            if (!_6567)
            {
                _6575 = any(bool2(pR_1.x > maxPx.x, pR_1.y > maxPx.y));
            }
            else
            {
                _6575 = _6567;
            }
            if (_6575)
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
            bool _6601 = qML_1.w < 0.25f;
            bool _6612;
            if (_6601)
            {
                _6612 = abs(qML_1.z - p0.z) < 28.0f;
            }
            else
            {
                _6612 = _6601;
            }
            bool _6618;
            if (_6612)
            {
                _6618 = qMR_1.w < 0.25f;
            }
            else
            {
                _6618 = _6612;
            }
            bool _6628;
            if (_6618)
            {
                _6628 = abs(qMR_1.z - p0.z) < 28.0f;
            }
            else
            {
                _6628 = _6618;
            }
            bool _6634;
            if (_6628)
            {
                _6634 = qT_1.w < 0.25f;
            }
            else
            {
                _6634 = _6628;
            }
            bool _6645;
            if (_6634)
            {
                _6645 = abs(qT_1.z - p0.z) < 48.0f;
            }
            else
            {
                _6645 = _6634;
            }
            bool _6651;
            if (_6645)
            {
                _6651 = qL_1.w < 0.25f;
            }
            else
            {
                _6651 = _6645;
            }
            bool _6661;
            if (_6651)
            {
                _6661 = abs(qL_1.z - p0.z) < 48.0f;
            }
            else
            {
                _6661 = _6651;
            }
            bool _6667;
            if (_6661)
            {
                _6667 = qR_1.w < 0.25f;
            }
            else
            {
                _6667 = _6661;
            }
            bool _6677;
            if (_6667)
            {
                _6677 = abs(qR_1.z - p0.z) < 48.0f;
            }
            else
            {
                _6677 = _6667;
            }
            bool _6687;
            if (_6677)
            {
                _6687 = abs(qL_1.z - qR_1.z) < 20.0f;
            }
            else
            {
                _6687 = _6677;
            }
            if (_6687)
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
                    bool _6723 = wFacing_1 >= 0.920000016689300537109375f;
                    bool _6729;
                    if (_6723)
                    {
                        _6729 = nW_1.z > 0.3499999940395355224609375f;
                    }
                    else
                    {
                        _6729 = _6723;
                    }
                    if (_6729)
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
    float _8737;
    if (ambient_extent.w > 0.5f)
    {
        _8737 = ambient_extent.w;
    }
    else
    {
        _8737 = 1.0f;
    }
    float ambScale = _8737;
    float2 pixel = (floor(gl_FragCoord.xy) + 0.5f.xx) * ambScale;
    bool _8756 = pixel.x >= ambient_extent.x;
    bool _8765;
    if (!_8756)
    {
        _8765 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _8765 = _8756;
    }
    if (_8765)
    {
        color = float4(0.5f, 0.5f, 0.5f, 1.0f);
        return;
    }
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
    bool isSprite = centre.w < 0.25f;
    float _8796;
    if (isSprite)
    {
        _8796 = clamp(2.599999904632568359375f * scale, max(2.599999904632568359375f, ambScale * 1.35000002384185791015625f), max(5.5f, 2.599999904632568359375f * scale));
    }
    else
    {
        _8796 = clamp(1.75f * scale, max(1.75f, ambScale), max(4.0f, 1.75f * scale));
    }
    float _step = _8796;
    float maxCont = max(3.5f, (1.35000002384185791015625f * _step) / max(scale, 0.25f));
    float2 param_1 = pixel - float2(_step, 0.0f);
    float3 left = positionAt(param_1).xyz;
    float2 param_2 = pixel + float2(_step, 0.0f);
    float3 right = positionAt(param_2).xyz;
    float2 param_3 = pixel - float2(0.0f, _step);
    float3 up = positionAt(param_3).xyz;
    float2 param_4 = pixel + float2(0.0f, _step);
    float3 down = positionAt(param_4).xyz;
    bool lOk = abs(p.z - left.z) < maxCont;
    bool rOk = abs(right.z - p.z) < maxCont;
    bool uOk = abs(p.z - up.z) < maxCont;
    bool dOk = abs(down.z - p.z) < maxCont;
    float creaseTol = max(2.2000000476837158203125f, (0.550000011920928955078125f * _step) / max(scale, 0.25f));
    float dLx = p.z - left.z;
    float dRx = right.z - p.z;
    float dUy = p.z - up.z;
    float dDy = down.z - p.z;
    bool _8931 = lOk && rOk;
    bool _8940;
    if (_8931)
    {
        _8940 = abs(dRx - dLx) < creaseTol;
    }
    else
    {
        _8940 = _8931;
    }
    bool _8948;
    if (_8940)
    {
        _8948 = (dRx * dLx) >= (-0.0500000007450580596923828125f);
    }
    else
    {
        _8948 = _8940;
    }
    bool xSmooth = _8948;
    bool _8952 = uOk && dOk;
    bool _8961;
    if (_8952)
    {
        _8961 = abs(dDy - dUy) < creaseTol;
    }
    else
    {
        _8961 = _8952;
    }
    bool _8968;
    if (_8961)
    {
        _8968 = (dDy * dUy) >= (-0.0500000007450580596923828125f);
    }
    else
    {
        _8968 = _8961;
    }
    bool ySmooth = _8968;
    float3 _8971;
    if (xSmooth)
    {
        _8971 = (right - left) * 0.5f;
    }
    else
    {
        float3 _8980;
        if (lOk)
        {
            _8980 = p - left;
        }
        else
        {
            float3 _8988;
            if (rOk)
            {
                _8988 = right - p;
            }
            else
            {
                _8988 = float3(_step / max(scale, 0.25f), 0.0f, 0.0f);
            }
            _8980 = _8988;
        }
        _8971 = _8980;
    }
    float3 dx = _8971;
    float3 _9005;
    if (ySmooth)
    {
        _9005 = (down - up) * 0.5f;
    }
    else
    {
        float3 _9014;
        if (uOk)
        {
            _9014 = p - up;
        }
        else
        {
            float3 _9022;
            if (dOk)
            {
                _9022 = down - p;
            }
            else
            {
                _9022 = float3(0.0f, _step / max(scale, 0.25f), 0.0f);
            }
            _9014 = _9022;
        }
        _9005 = _9014;
    }
    float3 dy = _9005;
    if (isSprite)
    {
        float step2 = _step * 2.0f;
        float maxCont2 = max(6.0f, (1.5499999523162841796875f * step2) / max(scale, 0.25f));
        float2 param_5 = pixel - float2(step2, 0.0f);
        float3 l2 = positionAt(param_5).xyz;
        float2 param_6 = pixel + float2(step2, 0.0f);
        float3 r2 = positionAt(param_6).xyz;
        float2 param_7 = pixel - float2(0.0f, step2);
        float3 u2 = positionAt(param_7).xyz;
        float2 param_8 = pixel + float2(0.0f, step2);
        float3 d2 = positionAt(param_8).xyz;
        bool _9095;
        if (lOk)
        {
            _9095 = abs(left.z - l2.z) < maxCont;
        }
        else
        {
            _9095 = lOk;
        }
        bool _9106;
        if (_9095)
        {
            _9106 = abs(p.z - l2.z) < maxCont2;
        }
        else
        {
            _9106 = _9095;
        }
        bool _9123;
        if (_9106)
        {
            _9123 = abs((p.z - left.z) - (left.z - l2.z)) < creaseTol;
        }
        else
        {
            _9123 = _9106;
        }
        bool l2Ok = _9123;
        bool _9136;
        if (rOk)
        {
            _9136 = abs(r2.z - right.z) < maxCont;
        }
        else
        {
            _9136 = rOk;
        }
        bool _9147;
        if (_9136)
        {
            _9147 = abs(r2.z - p.z) < maxCont2;
        }
        else
        {
            _9147 = _9136;
        }
        bool _9164;
        if (_9147)
        {
            _9164 = abs((r2.z - right.z) - (right.z - p.z)) < creaseTol;
        }
        else
        {
            _9164 = _9147;
        }
        bool r2Ok = _9164;
        bool _9177;
        if (uOk)
        {
            _9177 = abs(up.z - u2.z) < maxCont;
        }
        else
        {
            _9177 = uOk;
        }
        bool _9188;
        if (_9177)
        {
            _9188 = abs(p.z - u2.z) < maxCont2;
        }
        else
        {
            _9188 = _9177;
        }
        bool _9205;
        if (_9188)
        {
            _9205 = abs((p.z - up.z) - (up.z - u2.z)) < creaseTol;
        }
        else
        {
            _9205 = _9188;
        }
        bool u2Ok = _9205;
        bool _9218;
        if (dOk)
        {
            _9218 = abs(d2.z - down.z) < maxCont;
        }
        else
        {
            _9218 = dOk;
        }
        bool _9229;
        if (_9218)
        {
            _9229 = abs(d2.z - p.z) < maxCont2;
        }
        else
        {
            _9229 = _9218;
        }
        bool _9246;
        if (_9229)
        {
            _9246 = abs((d2.z - down.z) - (down.z - p.z)) < creaseTol;
        }
        else
        {
            _9246 = _9229;
        }
        bool d2Ok = _9246;
        if ((xSmooth && l2Ok) && r2Ok)
        {
            dx = (r2 - l2) * 0.25f;
        }
        else
        {
            if (((!xSmooth) && lOk) && rOk)
            {
                float _9269;
                if (l2Ok)
                {
                    _9269 = abs((p.z - left.z) - (left.z - l2.z));
                }
                else
                {
                    _9269 = 10000.0f;
                }
                float errL = _9269;
                float _9289;
                if (r2Ok)
                {
                    _9289 = abs((r2.z - right.z) - (right.z - p.z));
                }
                else
                {
                    _9289 = 10000.0f;
                }
                float errR = _9289;
                float3 _9309;
                if (errR < errL)
                {
                    float3 _9313;
                    if (r2Ok)
                    {
                        _9313 = (r2 - p) * 0.5f;
                    }
                    else
                    {
                        _9313 = right - p;
                    }
                    _9309 = _9313;
                }
                else
                {
                    float3 _9327;
                    if (l2Ok)
                    {
                        _9327 = (p - l2) * 0.5f;
                    }
                    else
                    {
                        _9327 = p - left;
                    }
                    _9309 = _9327;
                }
                dx = _9309;
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
                float _9362;
                if (u2Ok)
                {
                    _9362 = abs((p.z - up.z) - (up.z - u2.z));
                }
                else
                {
                    _9362 = 10000.0f;
                }
                float errU = _9362;
                float _9381;
                if (d2Ok)
                {
                    _9381 = abs((d2.z - down.z) - (down.z - p.z));
                }
                else
                {
                    _9381 = 10000.0f;
                }
                float errD = _9381;
                float3 _9401;
                if (errD < errU)
                {
                    float3 _9405;
                    if (d2Ok)
                    {
                        _9405 = (d2 - p) * 0.5f;
                    }
                    else
                    {
                        _9405 = down - p;
                    }
                    _9401 = _9405;
                }
                else
                {
                    float3 _9419;
                    if (u2Ok)
                    {
                        _9419 = (p - u2) * 0.5f;
                    }
                    else
                    {
                        _9419 = p - up;
                    }
                    _9401 = _9419;
                }
                dy = _9401;
            }
        }
        float zSum = p.z * 2.0f;
        float zW = 2.0f;
        bool _9444;
        if (lOk)
        {
            _9444 = xSmooth || (!rOk);
        }
        else
        {
            _9444 = lOk;
        }
        bool _9454;
        if (_9444)
        {
            _9454 = abs(left.z - p.z) < 2.2000000476837158203125f;
        }
        else
        {
            _9454 = _9444;
        }
        if (_9454)
        {
            zSum += left.z;
            zW += 1.0f;
        }
        bool _9470;
        if (rOk)
        {
            _9470 = xSmooth || (!lOk);
        }
        else
        {
            _9470 = rOk;
        }
        bool _9480;
        if (_9470)
        {
            _9480 = abs(right.z - p.z) < 2.2000000476837158203125f;
        }
        else
        {
            _9480 = _9470;
        }
        if (_9480)
        {
            zSum += right.z;
            zW += 1.0f;
        }
        bool _9496;
        if (uOk)
        {
            _9496 = ySmooth || (!dOk);
        }
        else
        {
            _9496 = uOk;
        }
        bool _9506;
        if (_9496)
        {
            _9506 = abs(up.z - p.z) < 2.2000000476837158203125f;
        }
        else
        {
            _9506 = _9496;
        }
        if (_9506)
        {
            zSum += up.z;
            zW += 1.0f;
        }
        bool _9522;
        if (dOk)
        {
            _9522 = ySmooth || (!uOk);
        }
        else
        {
            _9522 = dOk;
        }
        bool _9532;
        if (_9522)
        {
            _9532 = abs(down.z - p.z) < 2.2000000476837158203125f;
        }
        else
        {
            _9532 = _9522;
        }
        if (_9532)
        {
            zSum += down.z;
            zW += 1.0f;
        }
        bool _9543 = xSmooth && l2Ok;
        bool _9554;
        if (_9543)
        {
            _9554 = abs(l2.z - p.z) < 3.0799999237060546875f;
        }
        else
        {
            _9554 = _9543;
        }
        if (_9554)
        {
            zSum += (l2.z * 0.5f);
            zW += 0.5f;
        }
        bool _9566 = xSmooth && r2Ok;
        bool _9576;
        if (_9566)
        {
            _9576 = abs(r2.z - p.z) < 3.0799999237060546875f;
        }
        else
        {
            _9576 = _9566;
        }
        if (_9576)
        {
            zSum += (r2.z * 0.5f);
            zW += 0.5f;
        }
        bool _9588 = ySmooth && u2Ok;
        bool _9598;
        if (_9588)
        {
            _9598 = abs(u2.z - p.z) < 3.0799999237060546875f;
        }
        else
        {
            _9598 = _9588;
        }
        if (_9598)
        {
            zSum += (u2.z * 0.5f);
            zW += 0.5f;
        }
        bool _9610 = ySmooth && d2Ok;
        bool _9620;
        if (_9610)
        {
            _9620 = abs(d2.z - p.z) < 3.0799999237060546875f;
        }
        else
        {
            _9620 = _9610;
        }
        if (_9620)
        {
            zSum += (d2.z * 0.5f);
            zW += 0.5f;
        }
        pSmooth.z = zSum / zW;
    }
    float3 rawCross = cross(dy, dx);
    float rawLen = length(rawCross);
    float3 _9644;
    if (rawLen > 9.9999997473787516355514526367188e-06f)
    {
        _9644 = rawCross / rawLen.xxx;
    }
    else
    {
        _9644 = float3(0.0f, 0.0f, 1.0f);
    }
    float3 n = _9644;
    if (n.z < 0.0f)
    {
        n = -n;
    }
    float3 nSurf = n;
    float gradJump = max(abs(dx.z), abs(dy.z)) / max(_step / scale, 1.0f);
    float3 _9680;
    if (centre.w > 0.25f)
    {
        _9680 = n;
    }
    else
    {
        _9680 = normalize(lerp(n, float3(0.0f, 0.0f, 1.0f), 0.25f.xxx));
    }
    float3 normal = _9680;
    uint _9693_dummy_parameter;
    int2 vSize = int2(spvTextureSize(voxelMap, uint(0), _9693_dummy_parameter));
    bool hasVoxels = vSize.x > 1;
    float2 lotSz = max(ambient_drift.zw, 1.0f.xx);
    float2 param_9 = floor(gl_FragCoord.xy);
    float sliceJitter = _noise(param_9);
    float2 param_10 = floor(gl_FragCoord.xy) + float2(19.0f, 43.0f);
    float radialBase = _noise(param_10);
    float radius = ambient_params.x;
    float thickness = ambient_params.w;
    float visibility = 1.0f;
    float3 bentNormal = normal;
    bool _9731 = ambient_params.y > 0.001000000047497451305389404296875f;
    bool _9748;
    if (_9731)
    {
        bool _9740;
        if (hasVoxels)
        {
            _9740 = centre.w > 0.25f;
        }
        else
        {
            _9740 = hasVoxels;
        }
        bool _9746;
        if (_9740)
        {
            _9746 = ambient_sunLot.w > 0.0f;
        }
        else
        {
            _9746 = _9740;
        }
        _9748 = !_9746;
    }
    else
    {
        _9748 = _9731;
    }
    bool runScreenGTAO = _9748;
    if (runScreenGTAO)
    {
        visibility = 0.0f;
        float3 bentAccum = 0.0f.xxx;
        float3 _9757;
        if (centre.w < 0.25f)
        {
            _9757 = pSmooth + (normal * 0.949999988079071044921875f);
        }
        else
        {
            _9757 = p;
        }
        float3 pAO = _9757;
        float _9771;
        if (centre.w > 0.25f)
        {
            _9771 = radius * 1.85000002384185791015625f;
        }
        else
        {
            _9771 = radius;
        }
        float aoDistLimit = _9771;
        float2 _9854;
        float horizons[2];
        float _9980;
        for (int slice = 0; slice < 3; slice++)
        {
            float phi = ((float(slice) + sliceJitter) * 3.1415927410125732421875f) / 3.0f;
            float2 direction = float2(cos(phi), sin(phi));
            float3 axis = float3(direction.y, -direction.x, 0.0f);
            float3 projected = normal - (axis * dot(normal, axis));
            float projectedLength = max(length(projected), 9.9999997473787516355514526367188e-05f);
            float cosN = clamp(projected.z / projectedLength, -1.0f, 1.0f);
            float n_1 = sign(dot(projected.xy, direction)) * acos(cosN);
            float sliceRadialShift = frac(radialBase + (float(slice) * 0.38196599483489990234375f));
            for (int side = 0; side < 2; side++)
            {
                if (side == 0)
                {
                    _9854 = direction;
                }
                else
                {
                    _9854 = -direction;
                }
                float2 sideDirection = _9854;
                float best = -1.0f;
                for (int i = 0; i < 4; i++)
                {
                    float t = (float(i) + sliceRadialShift) / 4.0f;
                    float2 offset = ((((sideDirection * radius) * t) * t) * scale) + (sideDirection * 1.5f);
                    float2 samplePixel = pixel + offset;
                    bool _9896 = any(bool2(samplePixel.x < 0.0f.xx.x, samplePixel.y < 0.0f.xx.y));
                    bool _9905;
                    if (!_9896)
                    {
                        _9905 = samplePixel.x >= ambient_extent.x;
                    }
                    else
                    {
                        _9905 = _9896;
                    }
                    bool _9914;
                    if (!_9905)
                    {
                        _9914 = samplePixel.y >= ambient_extent.y;
                    }
                    else
                    {
                        _9914 = _9905;
                    }
                    if (_9914)
                    {
                        break;
                    }
                    float2 param_11 = samplePixel;
                    float4 samplePos = positionAt(param_11);
                    bool _9924 = centre.w < 0.25f;
                    bool _9930;
                    if (_9924)
                    {
                        _9930 = samplePos.w > 0.25f;
                    }
                    else
                    {
                        _9930 = _9924;
                    }
                    if (_9930)
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
                    _9980 = acos(clamp(best, -1.0f, 1.0f));
                }
                else
                {
                    _9980 = -acos(clamp(best, -1.0f, 1.0f));
                }
                horizons[side] = _9980;
            }
            float h1 = n_1 + min(horizons[0] - n_1, 1.57079637050628662109375f);
            float h0 = n_1 + max(horizons[1] - n_1, -1.57079637050628662109375f);
            float sinN = sin(n_1);
            float sliceVis = (projectedLength * 0.25f) * ((((-cos((2.0f * h0) - n_1)) + cosN) + ((2.0f * h0) * sinN)) + (((-cos((2.0f * h1) - n_1)) + cosN) + ((2.0f * h1) * sinN)));
            visibility += sliceVis;
            float bentAng = 0.5f * (h0 + h1);
            float3 sliceBent = float3(direction * sin(bentAng), cos(bentAng));
            bentAccum += (sliceBent * max(sliceVis, 0.0199999995529651641845703125f));
        }
        visibility = clamp(visibility / 3.0f, 0.0f, 1.0f);
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
    float _10124;
    if (centre.w < 0.25f)
    {
        _10124 = (0.89999997615814208984375f - depthMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f;
    }
    else
    {
        _10124 = ((0.89999997615814208984375f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
    }
    float key = _10124;
    float2 param_12 = p.xy;
    float param_13 = key;
    bool param_14 = centre.w > 0.25f;
    float2 param_15 = ambient_frame.xy;
    float3 here = lotPoint(param_12, param_13, param_14, param_15);
    float2 param_16 = pixel;
    float param_17 = p.z;
    float riseHere = riseAt(param_16, param_17);
    float onGround = 1.0f - smoothstep(2.0f, 6.0f, riseHere);
    uint _10178_dummy_parameter;
    float4 _10181;
    if (int2(spvTextureSize(liftMap, uint(0), _10178_dummy_parameter)).x > 1)
    {
        _10181 = liftMap.Load(int3(int2(pixel), 0));
    }
    else
    {
        _10181 = 0.0f.xxxx;
    }
    float4 lift = _10181;
    bool onSnow = lift.z > 0.5f;
    if (onSnow)
    {
        here += float3(0.5f * lift.x, 0.5f * lift.x, lift.y);
        onGround = 1.0f;
        occlusion = 1.0f;
    }
    float roofSnow = lift.w;
    bool _10215 = !onSnow;
    bool _10221;
    if (_10215)
    {
        _10221 = centre.w < 0.25f;
    }
    else
    {
        _10221 = _10215;
    }
    bool _10227;
    if (_10221)
    {
        _10227 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _10227 = _10221;
    }
    bool _10231 = _10227 && (riseHere > 105.0f);
    bool _10238;
    if (_10231)
    {
        float3 param_18 = here;
        _10238 = indoors(param_18) < 0.20000000298023223876953125f;
    }
    else
    {
        _10238 = _10231;
    }
    float _10239;
    if (_10238)
    {
        _10239 = smoothstep(105.0f, 122.0f, riseHere) * smoothstep(0.319999992847442626953125f, 0.60000002384185791015625f, dot(normal, float3(0.0f, -0.866025388240814208984375f, 0.5f)));
    }
    else
    {
        _10239 = 0.0f;
    }
    float highRoof = _10239;
    float roofCalm = clamp(max(roofSnow, highRoof), 0.0f, 1.0f);
    if (roofCalm > 0.00999999977648258209228515625f)
    {
        occlusion = lerp(occlusion, 1.0f - ((1.0f - occlusion) * 0.14000000059604644775390625f), roofCalm);
    }
    int2 hereCell = int2(floor(here.xy + ambient_frame.w.xx));
    int2 param_19 = hereCell;
    int param_20 = 1;
    float param_21 = -100.0f;
    float floor2Z = floorAt(param_19, param_20, param_21);
    float _10287;
    if (floor2Z > (-50.0f))
    {
        _10287 = (1.0f - smoothstep(0.07999999821186065673828125f, 0.2199999988079071044921875f, abs(here.z - floor2Z))) * smoothstep(0.3499999940395355224609375f, 0.64999997615814208984375f, normal.z);
    }
    else
    {
        _10287 = 0.0f;
    }
    float onLevel2Floor = _10287;
    float onFlatFloor = max(onGround, onLevel2Floor);
    bool _10313;
    if (hasVoxels)
    {
        _10313 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _10313 = hasVoxels;
    }
    if (_10313 && (onLevel2Floor > 0.00999999977648258209228515625f))
    {
        occlusion = lerp(occlusion, 1.0f, onLevel2Floor);
    }
    float wallFloor = 0.0f;
    bool _10324 = onFlatFloor > 0.5f;
    bool _10330;
    if (_10324)
    {
        _10330 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _10330 = _10324;
    }
    bool _10347;
    if (_10330)
    {
        bool _10335 = ambient_params.y > 0.001000000047497451305389404296875f;
        bool _10346;
        if (!_10335)
        {
            bool _10345;
            if (onSnow)
            {
                _10345 = ambient_contact.y > 0.0f;
            }
            else
            {
                _10345 = onSnow;
            }
            _10346 = _10345;
        }
        else
        {
            _10346 = _10335;
        }
        _10347 = _10346;
    }
    else
    {
        _10347 = _10330;
    }
    if (_10347)
    {
        float3 param_22 = here;
        wallFloor = floorWallAO(param_22);
        bool _10354 = !onSnow;
        bool _10360;
        if (_10354)
        {
            _10360 = ambient_params.y > 0.001000000047497451305389404296875f;
        }
        else
        {
            _10360 = _10354;
        }
        if (_10360)
        {
            occlusion *= (1.0f - ((0.4199999868869781494140625f * clamp(ambient_params.y, 0.0f, 1.0f)) * clamp(wallFloor, 0.0f, 1.35000002384185791015625f)));
        }
    }
    float contact = 1.0f;
    if (ambient_sunLot.w > 0.0f)
    {
        bool _10386 = ((centre.w > 0.25f) || onSnow) || (onLevel2Floor > 0.5f);
        bool _10406;
        if (_10386)
        {
            bool _10391 = ambient_contact.y > 0.0f;
            bool _10405;
            if (!_10391)
            {
                bool _10398 = (!onSnow) && hasVoxels;
                bool _10404;
                if (_10398)
                {
                    _10404 = ambient_params.y > 0.001000000047497451305389404296875f;
                }
                else
                {
                    _10404 = _10398;
                }
                _10405 = _10404;
            }
            else
            {
                _10405 = _10391;
            }
            _10406 = _10405;
        }
        else
        {
            _10406 = _10386;
        }
        if (_10406)
        {
            if (hasVoxels)
            {
                int levelRow = int(onLevel2Floor > 0.5f);
                float voxelContact = 0.0f;
                float3 param_23 = here;
                int param_24 = levelRow;
                int2 param_25 = vSize;
                float param_26;
                float _10425 = voxelGroundAO(param_23, param_24, param_25, param_26);
                voxelContact = param_26;
                float voxelHemi = _10425;
                bool _10428 = !onSnow;
                bool _10434;
                if (_10428)
                {
                    _10434 = ambient_params.y > 0.001000000047497451305389404296875f;
                }
                else
                {
                    _10434 = _10428;
                }
                if (_10434)
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
                    uint _10483_dummy_parameter;
                    int2 footSize = int2(spvTextureSize(footMap, uint(0), _10483_dummy_parameter));
                    float2 invFootSize = 1.0f.xx / float2(footSize);
                    float2 at = (here.xy + ambient_frame.w.xx) * detail;
                    float best_1 = 0.0f;
                    float sum = 0.0f;
                    int2 base = int2(floor(at - 1.5f.xx));
                    for (int qy = 0; qy < 4; qy += 2)
                    {
                        for (int qx = 0; qx < 4; qx += 2)
                        {
                            int2 qb = base + int2(qx, qy);
                            bool _10531 = (qb.x + 1) < 0;
                            bool _10539;
                            if (!_10531)
                            {
                                _10539 = (qb.y + 1) < 0;
                            }
                            else
                            {
                                _10539 = _10531;
                            }
                            bool _10548;
                            if (!_10539)
                            {
                                _10548 = qb.x >= footSize.x;
                            }
                            else
                            {
                                _10548 = _10539;
                            }
                            bool _10557;
                            if (!_10548)
                            {
                                _10557 = qb.y >= footSize.y;
                            }
                            else
                            {
                                _10557 = _10548;
                            }
                            if (_10557)
                            {
                                continue;
                            }
                            float4 g = footMap.GatherRed(_footMap_sampler, (float2(qb) + 1.0f.xx) * invFootSize);
                            if (min(min(g.x, g.y), min(g.z, g.w)) >= 1.0f)
                            {
                                continue;
                            }
                            float _10597[4] = { g.x, g.y, g.z, g.w };
                            float vals[4] = _10597;
                            for (int k = 0; k < 4; k++)
                            {
                                float stored = vals[k];
                                if (stored >= 1.0f)
                                {
                                    continue;
                                }
                                int2 texel = qb + _10618[k];
                                bool _10627 = any(bool2(texel.x < int2(0, 0).x, texel.y < int2(0, 0).y));
                                bool _10635;
                                if (!_10627)
                                {
                                    _10635 = any(bool2(texel.x >= footSize.x, texel.y >= footSize.y));
                                }
                                else
                                {
                                    _10635 = _10627;
                                }
                                if (_10635)
                                {
                                    continue;
                                }
                                float footZ = (0.5f - stored) * 64.0f;
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
                    float feet = clamp((0.819999992847442626953125f * best_1) + (0.0350000001490116119384765625f * sum), 0.0f, 1.0f);
                    uint _10691_dummy_parameter;
                    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _10691_dummy_parameter)));
                    float2 hCenter = (here.xy + ambient_frame.w.xx) * ambient_frame.z;
                    float over = ((0.5f - heightMap.Sample(_heightMap_sampler, hCenter / gridSize).x) * 64.0f) - here.z;
                    float under = smoothstep(0.20000000298023223876953125f, 0.4000000059604644775390625f, over) * (1.0f - smoothstep(2.0f, 2.599999904632568359375f, over));
                    contact = 1.0f - (ambient_contact.y * clamp(feet + (0.3499999940395355224609375f * under), 0.0f, 1.0f));
                }
            }
        }
    }
    else
    {
        bool _10733 = onGround > 0.0f;
        bool _10739;
        if (_10733)
        {
            _10739 = ambient_contact.y > 0.0f;
        }
        else
        {
            _10739 = _10733;
        }
        if (_10739)
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
                    bool _10806 = any(bool2(samplePixel_1.x < 0.0f.xx.x, samplePixel_1.y < 0.0f.xx.y));
                    bool _10815;
                    if (!_10806)
                    {
                        _10815 = samplePixel_1.x >= ambient_extent.x;
                    }
                    else
                    {
                        _10815 = _10806;
                    }
                    bool _10824;
                    if (!_10815)
                    {
                        _10824 = samplePixel_1.y >= ambient_extent.y;
                    }
                    else
                    {
                        _10824 = _10815;
                    }
                    if (_10824)
                    {
                        break;
                    }
                    float2 param_27 = samplePixel_1;
                    float4 q = positionAt(param_27);
                    if (q.w > 0.75f)
                    {
                        continue;
                    }
                    float2 param_28 = samplePixel_1;
                    float param_29 = q.z;
                    float rise = riseAt(param_28, param_29);
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
    float2 _10930;
    if (length(nLot.xy) > 0.1500000059604644775390625f)
    {
        _10930 = normalize(nLot.xy);
    }
    else
    {
        _10930 = 0.0f.xx;
    }
    float2 horizN = _10930;
    float isVertical = (((1.0f - onFlatFloor) * (1.0f - smoothstep(0.2199999988079071044921875f, 0.4199999868869781494140625f, abs(nUp)))) * (1.0f - roofCalm)) * (1.0f - smoothstep(2.5f, 4.5f, gradJump));
    float onDynamicSim = 0.0f;
    bool _10962;
    if (hasVoxels)
    {
        _10962 = ambient_shadowView.w > 0.5f;
    }
    else
    {
        _10962 = hasVoxels;
    }
    bool _10968;
    if (_10962)
    {
        _10968 = centre.w < 0.25f;
    }
    else
    {
        _10968 = _10962;
    }
    if (_10968)
    {
        uint _10974_dummy_parameter;
        float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _10974_dummy_parameter)));
        float2 wpSelf = ambient_shadowView.xy + (p.xy * ambient_shadowView.z);
        bool _10988 = all(bool2(wpSelf.x >= 0.0f.xx.x, wpSelf.y >= 0.0f.xx.y));
        bool _10995;
        if (_10988)
        {
            _10995 = all(bool2(wpSelf.x < wSize.x, wpSelf.y < wSize.y));
        }
        else
        {
            _10995 = _10988;
        }
        if (_10995)
        {
            float wSelf = worldDepthMap.Load(int3(clamp(int2(floor(wpSelf)), int2(0, 0), int2(wSize) - int2(1, 1)), 0)).x;
            bool _11012 = wSelf < 0.99989998340606689453125f;
            bool _11022;
            if (_11012)
            {
                _11022 = abs(((0.89999997615814208984375f - wSelf) / 0.0030000000260770320892333984375f) - key) < 0.449999988079071044921875f;
            }
            else
            {
                _11022 = _11012;
            }
            if (_11022)
            {
                onDynamicSim = 1.0f;
                occlusion = lerp(occlusion, 1.0f - ((1.0f - occlusion) * 0.3499999940395355224609375f), onDynamicSim);
            }
        }
    }
    bool _11041 = ((centre.w < 0.25f) && (isVertical > 0.25f)) && (onDynamicSim < 0.5f);
    bool _11047;
    if (_11041)
    {
        _11047 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _11047 = _11041;
    }
    float3 _11048;
    if (_11047)
    {
        float3 param_30 = here;
        float2 param_31 = p.xy;
        float param_32 = pSmooth.z / 27.7128124237060546875f;
        float2 param_33 = horizN;
        _11048 = resolveWallSurface(param_30, param_31, param_32, param_33);
    }
    else
    {
        _11048 = here;
    }
    float3 hereSurf = _11048;
    float2 param_34 = hereSurf.xy;
    float param_35 = hereSurf.z;
    float hereRelZ = hereSurf.z - terrainBaseAt(param_34, param_35);
    bool _11081 = (isVertical > 0.00999999977648258209228515625f) && (onDynamicSim < 0.5f);
    bool _11087;
    if (_11081)
    {
        _11087 = ambient_params.y > 0.001000000047497451305389404296875f;
    }
    else
    {
        _11087 = _11081;
    }
    if (_11087)
    {
        bool _11093 = centre.w < 0.25f;
        bool _11099;
        if (_11093)
        {
            _11099 = ambient_sunLot.w <= 0.0f;
        }
        else
        {
            _11099 = _11093;
        }
        float3 _11100;
        if (_11099)
        {
            float2 param_36 = p.xy;
            float param_37 = pSmooth.z / 27.7128124237060546875f;
            bool param_38 = false;
            float2 param_39 = ambient_frame.xy;
            _11100 = lotPoint(param_36, param_37, param_38, param_39);
        }
        else
        {
            _11100 = hereSurf;
        }
        float3 hereWall = _11100;
        float2 param_40 = hereWall.xy;
        float param_41 = hereWall.z;
        float wallRelZ = hereWall.z - terrainBaseAt(param_40, param_41);
        float aoStr = clamp(ambient_params.y, 0.0f, 1.0f) * isVertical;
        float storyRelZ = max(0.0f, wallRelZ - (floor(max(0.0f, wallRelZ + 0.0500000007450580596923828125f) / 2.9500000476837158203125f) * 2.9500000476837158203125f));
        float baseT = clamp(storyRelZ / 0.449999988079071044921875f, 0.0f, 1.0f);
        float baseCrease = exp((-storyRelZ) / 0.0900000035762786865234375f) * (1.0f - smoothstep(0.23999999463558197021484375f, 0.449999988079071044921875f, storyRelZ));
        float baseAO = 1.0f - ((0.3400000035762786865234375f * aoStr) * ((0.550000011920928955078125f * baseCrease) + ((0.449999988079071044921875f * (1.0f - baseT)) * (1.0f - baseT))));
        float _11177;
        if (ambient_sunLot.w > 0.0f)
        {
            float3 param_42 = hereWall;
            float2 param_43 = horizN;
            _11177 = wallCornerAO(param_42, param_43);
        }
        else
        {
            _11177 = 0.0f;
        }
        float cornerOcc = _11177;
        float cornerAO = 1.0f - ((0.3400000035762786865234375f * aoStr) * cornerOcc);
        bool _11200;
        if (hasVoxels)
        {
            _11200 = ambient_sunLot.w > 0.0f;
        }
        else
        {
            _11200 = hasVoxels;
        }
        float _11201;
        if (_11200)
        {
            float3 param_44 = hereWall;
            float2 param_45 = horizN;
            int2 param_46 = vSize;
            float2 param_47 = lotSz;
            _11201 = voxelWallAO(param_44, param_45, param_46, param_47) * (1.0f - (0.7200000286102294921875f * cornerOcc));
        }
        else
        {
            _11201 = 0.0f;
        }
        float vWallOcc = _11201;
        float vWallAO = 1.0f - ((0.4199999868869781494140625f * aoStr) * vWallOcc);
        occlusion = lerp(occlusion, 1.0f, (0.7200000286102294921875f * isVertical) * cornerOcc);
        occlusion = max(((occlusion * baseAO) * cornerAO) * vWallAO, 0.2199999988079071044921875f);
    }
    bool _11255 = (((((centre.w < 0.25f) && (onFlatFloor < 0.5f)) && (onDynamicSim < 0.5f)) && (roofCalm < 0.5f)) && (isVertical < 0.9900000095367431640625f)) && hasVoxels;
    bool _11261;
    if (_11255)
    {
        _11261 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _11261 = _11255;
    }
    bool _11267;
    if (_11261)
    {
        _11267 = ambient_params.y > 0.001000000047497451305389404296875f;
    }
    else
    {
        _11267 = _11261;
    }
    if (_11267)
    {
        float storySpriteZ = max(0.0f, hereRelZ - (floor(max(0.0f, hereRelZ + 0.0500000007450580596923828125f) / 2.9500000476837158203125f) * 2.9500000476837158203125f));
        if (storySpriteZ < 0.2800000011920928955078125f)
        {
            int spriteRow = int(hereRelZ > 2.7999999523162841796875f);
            float2 param_48 = here.xy;
            int param_49 = spriteRow;
            int2 param_50 = vSize;
            float3 selfGround = sampleBakedGroundAO(param_48, param_49, param_50);
            float rootOcc = ((1.0f - isVertical) * clamp((selfGround.x * 0.699999988079071044921875f) + (selfGround.y * 0.4000000059604644775390625f), 0.0f, 1.0f)) * (1.0f - smoothstep(0.02999999932944774627685546875f, 0.23999999463558197021484375f, storySpriteZ));
            occlusion *= (1.0f - ((0.180000007152557373046875f * clamp(ambient_params.y, 0.0f, 1.0f)) * rootOcc));
        }
    }
    float lit = 1.0f;
    float litColumn = 1.0f;
    float litShell = 1.0f;
    float inside = 0.0f;
    if (ambient_sunLot.w > 0.0f)
    {
        float2 insideOffset = lerp(horizN * 0.25f, 0.0f.xx, onFlatFloor.xx);
        float3 param_51 = hereSurf + float3(insideOffset, 0.0f);
        inside = indoors(param_51);
    }
    float window = 0.0f;
    bool _11348 = ambient_sunLot.w > 0.0f;
    bool _11354;
    if (_11348)
    {
        _11354 = ambient_params.z > 0.001000000047497451305389404296875f;
    }
    else
    {
        _11354 = _11348;
    }
    if (_11354)
    {
        float3 sunView = normalize(ambient_light.xyz + float3(0.0f, 0.0f, 9.9999997473787516355514526367188e-05f));
        float ndotl = dot(nSurf, sunView);
        float faceLit = smoothstep(-0.07999999821186065673828125f, 0.2199999988079071044921875f, ndotl);
        float selfShadow = lerp(1.0f, faceLit, max(isVertical, roofCalm));
        float3 param_52 = hereSurf;
        float param_53 = onFlatFloor;
        float2 param_54 = horizN;
        float2 wall = wallRay(param_52, param_53, param_54);
        float3 marchOrigin = (hereSurf + float3(horizN * (0.20000000298023223876953125f * isVertical), 0.0f)) + (nLot * (0.180000007152557373046875f * roofCalm));
        float marchStart = lerp(lerp(0.64999997615814208984375f, 0.180000007152557373046875f, roofCalm), 0.1599999964237213134765625f, isVertical);
        marchStart = lerp(marchStart, 0.0599999986588954925537109375f, onFlatFloor);
        float canopyClearZ = hereRelZ + lerp(0.20000000298023223876953125f, -0.0500000007450580596923828125f, isVertical);
        float3 _11421;
        if ((wall.x > 0.00999999977648258209228515625f) && (selfShadow > 0.00999999977648258209228515625f))
        {
            float3 param_55 = marchOrigin;
            float param_56 = marchStart;
            float param_57 = canopyClearZ;
            _11421 = sunMarch(param_55, param_56, param_57);
        }
        else
        {
            _11421 = 0.0f.xxx;
        }
        float3 march = _11421;
        lit = min(min(wall.x, march.x), selfShadow);
        litColumn = min(min(wall.x, march.y), selfShadow);
        litShell = march.z;
        window = ((inside * max(onFlatFloor, isVertical * faceLit)) * wall.y) * march.x;
    }
    float _11466;
    if (ambient_sunLot.w > 0.0f)
    {
        float3 param_58 = here;
        _11466 = cloudLight(param_58);
    }
    else
    {
        _11466 = 1.0f;
    }
    float sky = _11466;
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
    float3 spriteLampNormal = normalize(lerp(nSurf, float3(0.0f, 0.0f, 1.0f), 0.36000001430511474609375f.xxx));
    float3 _11544;
    if (centre.w > 0.25f)
    {
        _11544 = nSurf;
    }
    else
    {
        _11544 = normalize(lerp(spriteLampNormal, nSurf, onLevel2Floor.xxx));
    }
    float3 lampNormal = _11544;
    float _11647;
    float _11761;
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
            _11647 = reach * (1.41999995708465576171875f + (0.07999999821186065673828125f * flicker01));
        }
        else
        {
            _11647 = reach * 1.35000002384185791015625f;
        }
        float lampReach = _11647;
        if (_distance_1 >= lampReach)
        {
            continue;
        }
        float3 lampLot = 0.0f.xxx;
        float sameSide = 1.0f;
        if (sides)
        {
            float2 param_59 = lamp.xy;
            float param_60 = lamp.z;
            bool param_61 = false;
            float2 param_62 = ambient_frame.xy;
            lampLot = lotPoint(param_59, param_60, param_61, param_62);
            float3 param_63 = lampLot;
            bool _11686 = indoors(param_63) > 0.25f;
            bool _11706;
            if (_11686)
            {
                bool _11690 = roofCalm > 0.20000000298023223876953125f;
                bool _11705;
                if (!_11690)
                {
                    bool _11695 = inside < 0.25f;
                    bool _11704;
                    if (_11695)
                    {
                        _11704 = hereSurf.z > (lampLot.z + 1.0f);
                    }
                    else
                    {
                        _11704 = _11695;
                    }
                    _11705 = _11704;
                }
                else
                {
                    _11705 = _11690;
                }
                _11706 = _11705;
            }
            else
            {
                _11706 = _11686;
            }
            if (_11706)
            {
                continue;
            }
            float3 param_64 = hereSurf;
            float3 param_65 = lampLot;
            float param_66 = onFlatFloor;
            float2 param_67 = horizN;
            sameSide = lampWallVis(param_64, param_65, param_66, param_67);
            if (sameSide <= 0.00999999977648258209228515625f)
            {
                continue;
            }
        }
        float3 direction_2 = toLamp / max(_distance_1, 9.9999997473787516355514526367188e-05f).xxx;
        float normD = clamp(_distance_1 / max(lampReach, 9.9999997473787516355514526367188e-05f), 0.0f, 1.0f);
        float win = clamp(1.0f - (normD * normD), 0.0f, 1.0f);
        float falloff_1 = (1.12000000476837158203125f * (win * win)) / (1.0f + ((11.0f * normD) * normD));
        float nearBulb = 1.0f - smoothstep(14.0f, 34.0f, _distance_1);
        if (isFire)
        {
            _11761 = clamp((dot(lampNormal, direction_2) * 0.64999997615814208984375f) + 0.3499999940395355224609375f, 0.0f, 1.0f);
        }
        else
        {
            _11761 = clamp((dot(lampNormal, direction_2) * 0.7200000286102294921875f) + 0.2800000011920928955078125f, 0.0f, 1.0f);
        }
        float facing = _11761;
        facing = lerp(facing, 1.0f, nearBulb);
        float contrib = (((strength * flicker) * falloff_1) * facing) * sameSide;
        if (contrib < 0.00120000005699694156646728515625f)
        {
            continue;
        }
        falloff_1 *= smoothstep(0.00120000005699694156646728515625f, 0.0035000001080334186553955078125f, contrib);
        maxNearBulb = max(maxNearBulb, nearBulb * clamp((strength * falloff_1) * sameSide, 0.0f, 1.0f));
        float open = 1.0f;
        if (sides)
        {
            float3 param_68 = hereSurf;
            float3 param_69 = lampLot;
            float param_70 = onFlatFloor;
            float param_71 = isVertical;
            float param_72 = nUp;
            float2 param_73 = horizN;
            bool param_74 = isFire;
            open = lampMarch(param_68, param_69, param_70, param_71, param_72, param_73, param_74);
        }
        else
        {
            for (int i_2 = 1; i_2 < 16; i_2++)
            {
                float t_2 = ((float(i_2) - 0.5f) / 16.0f) * _distance_1;
                bool _11854;
                if (isFire)
                {
                    _11854 = (_distance_1 - t_2) < 22.0f;
                }
                else
                {
                    _11854 = isFire;
                }
                if (_11854)
                {
                    continue;
                }
                float3 q_1 = pLamp + (direction_2 * t_2);
                float2 samplePixel_2 = ambient_view.xy + (q_1.xy * scale);
                bool _11875 = any(bool2(samplePixel_2.x < 0.0f.xx.x, samplePixel_2.y < 0.0f.xx.y));
                bool _11884;
                if (!_11875)
                {
                    _11884 = samplePixel_2.x >= ambient_extent.x;
                }
                else
                {
                    _11884 = _11875;
                }
                bool _11893;
                if (!_11884)
                {
                    _11893 = samplePixel_2.y >= ambient_extent.y;
                }
                else
                {
                    _11893 = _11884;
                }
                if (_11893)
                {
                    break;
                }
                float2 param_75 = samplePixel_2;
                float4 samplePos_1 = positionAt(param_75);
                float sampleZ = samplePos_1.z;
                bool _11906 = samplePos_1.w > 0.25f;
                bool _11912;
                if (_11906)
                {
                    _11912 = samplePos_1.w < 0.75f;
                }
                else
                {
                    _11912 = _11906;
                }
                if (_11912)
                {
                    float2 param_76 = samplePos_1.xy;
                    float param_77 = samplePos_1.z / 27.7128124237060546875f;
                    bool param_78 = true;
                    float2 param_79 = ambient_frame.xy;
                    float3 sampleLot = lotPoint(param_76, param_77, param_78, param_79);
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
    float nightFactor = clamp(ambient_weather.w, 0.0f, 1.0f);
    float lowSun = 1.0f - smoothstep(0.119999997317790985107421875f, 0.519999980926513671875f, ambient_sunLot.z);
    float _12031;
    if (ambient_tone.w >= 0.0f)
    {
        _12031 = clamp(ambient_tone.w, 0.0f, 1.0f);
    }
    else
    {
        _12031 = 0.5f + (0.449999988079071044921875f * lowSun);
    }
    float dayProgress = _12031;
    float param_80 = dayProgress;
    float3 param_81;
    float3 param_82;
    float3 param_83;
    dayPalette(param_80, param_81, param_82, param_83);
    float3 warmSun = param_81;
    float3 coolShade = param_82;
    float3 dayWindowColor = param_83;
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
    float bentSunOcc = lerp(1.0f, smoothstep(-0.4000000059604644775390625f, 0.550000011920928955078125f, dot(bentNormal, sunViewDir)), (((0.2800000011920928955078125f * (1.0f - onFlatFloor)) * (1.0f - roofCalm)) * (1.0f - isVertical)) * (1.0f - onDynamicSim));
    float shadowActive = clamp(ambient_params.z * 1.7999999523162841796875f, 0.0f, 1.0f) * (1.0f - (0.800000011920928955078125f * nightFactor));
    float dirShade = 1.0f + (((((((keyWrap * 0.20000000298023223876953125f) - 0.039999999105930328369140625f) * lerp(1.0f, 0.550000011920928955078125f, inside)) * lit) * shadowActive) * (1.0f - (0.449999988079071044921875f * onFlatFloor))) * (1.0f - onDynamicSim));
    dirShade *= lerp(1.0f, bentSunOcc, shadowActive * lit);
    float deBakeWeight = smoothstep(0.0199999995529651641845703125f, 0.100000001490116119384765625f, ambient_params.z) * (1.0f - (0.85000002384185791015625f * nightFactor));
    float wallDeBake = exp((((-0.4199999868869781494140625f) * clamp(nSurf.x, -0.699999988079071044921875f, 0.699999988079071044921875f)) * isVertical) * deBakeWeight);
    dirShade *= wallDeBake;
    float sunBloom = 1.0f + ((((0.119999997317790985107421875f * (1.0f - nightFactor)) * lit) * sunWeight) * shadowActive);
    float bentUp = clamp((dot(bentNormal, float3(0.0f, -0.866025388240814208984375f, 0.5f)) * 0.5f) + 0.5f, 0.0f, 1.0f);
    float3 skyFill = float3(0.839999973773956298828125f, 0.930000007152557373046875f, 1.13999998569488525390625f);
    float3 groundBounce = float3(1.12000000476837158203125f, 1.0299999713897705078125f, 0.86000001430511474609375f);
    float3 hemiGI = lerp(groundBounce, skyFill, bentUp.xxx);
    hemiGI /= dot(hemiGI, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)).xxx;
    float giStrength = ((((1.0f - nightFactor) * (1.0f - (lit * 0.550000011920928955078125f))) * lerp(0.319999992847442626953125f, 0.1599999964237213134765625f, inside)) * (1.0f - (0.64999997615814208984375f * onFlatFloor))) * (1.0f - (0.75f * isVertical));
    float3 envBase = lerp(1.0f.xxx, hemiGI, giStrength.xxx) * ((dirShade * sunBloom) * ambient_lamp.w);
    float3 skyTerm = envBase * (1.0f - shadowStr);
    float3 sunTerm = (envBase * (shadowStr * lit)) + (windowColor * ((0.2199999988079071044921875f * ambient_contact.z) * window));
    float ambOcc = lerp(occlusion * contact, 1.0f, maxNearBulb);
    float sunMicroOcc = lerp(lerp(1.0f, occlusion, 0.07999999821186065673828125f) * lerp(1.0f, contact, 0.2599999904632568359375f), 1.0f, maxNearBulb);
    float lampOcc = lerp(lerp(1.0f, occlusion, 0.519999980926513671875f) * lerp(1.0f, contact, 0.579999983310699462890625f), 1.0f, maxNearBulb);
    float3 light = ((skyTerm * ambOcc) + (sunTerm * sunMicroOcc)) + (totalLamps * lampOcc);
    float daylight = 1.0f - nightFactor;
    float3 sunTint = lerp(coolShade, warmSun, lit.xxx);
    sunTint /= dot(sunTint, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)).xxx;
    float fireShare = dot(fires, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)) / ((ambient_lamp.w + dot(fires, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f))) + 9.9999997473787516355514526367188e-05f);
    float3 tint = lerp(1.0f.xxx, sunTint, (((clamp(ambient_tone.x, 0.0f, 1.35000002384185791015625f) * daylight) * lerp(1.0f, 0.64999997615814208984375f, inside)) * (1.0f - (0.85000002384185791015625f * fireShare))).xxx);
    float _12367;
    if (dayProgress < 0.5f)
    {
        _12367 = smoothstep(0.550000011920928955078125f, 0.800000011920928955078125f, nightFactor) * (1.0f - smoothstep(0.85000002384185791015625f, 0.980000019073486328125f, nightFactor));
    }
    else
    {
        _12367 = smoothstep(0.2800000011920928955078125f, 0.579999983310699462890625f, nightFactor) * (1.0f - smoothstep(0.7200000286102294921875f, 0.959999978542327880859375f, nightFactor));
    }
    float twilight = _12367;
    float3 blueHour = float3(0.863165557384490966796875f, 0.99945485591888427734375f, 1.40832269191741943359375f);
    float lampShare = dot(totalLamps, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)) / ((ambient_lamp.w + dot(totalLamps, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f))) + 9.9999997473787516355514526367188e-05f);
    tint = lerp(tint, blueHour, ((((twilight * lerp(1.0f, 0.3499999940395355224609375f, inside)) * ambient_tone.x) * 0.699999988079071044921875f) * (1.0f - lampShare)).xxx);
    float3 moonLit = float3(0.63999998569488525390625f, 0.819999992847442626953125f, 1.37999999523162841796875f);
    float3 moonShade = float3(0.540000021457672119140625f, 0.7200000286102294921875f, 1.440000057220458984375f);
    float3 moon = lerp(moonShade, moonLit, lit.xxx);
    tint = lerp(tint, moon, (((nightFactor * lerp(1.0f, 0.4199999868869781494140625f, inside)) * 0.87999999523162841796875f) * (1.0f - lampShare)).xxx);
    light *= tint;
    bool _12443 = nightFactor > 0.0500000007450580596923828125f;
    bool _12449;
    if (_12443)
    {
        _12449 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _12449 = _12443;
    }
    bool _12455;
    if (_12449)
    {
        _12455 = centre.w > 0.25f;
    }
    else
    {
        _12455 = _12449;
    }
    if (_12455)
    {
        float3 param_84 = here;
        float param_85 = onGround;
        float2 spill = windowSpillInfo(param_84, param_85);
        float3 spillColor = lerp(float3(1.0f, 0.819999992847442626953125f, 0.579999983310699462890625f), float3(1.0f, 0.3400000035762786865234375f, 0.0500000007450580596923828125f), spill.y.xxx);
        light += (spillColor * (((occlusion * 0.699999988079071044921875f) * nightFactor) * spill.x));
    }
    bool _12483 = ambient_weather.x > 0.60000002384185791015625f;
    bool _12491;
    if (!_12483)
    {
        _12491 = ambient_skyExtra.z > 0.5f;
    }
    else
    {
        _12491 = _12483;
    }
    bool _12497;
    if (_12491)
    {
        _12497 = ambient_skyExtra.y < 0.5f;
    }
    else
    {
        _12497 = _12491;
    }
    if (_12497)
    {
        float lSlot = floor(ambient_weather.z / 7.0f);
        float _12509;
        if (ambient_skyExtra.z > 0.5f)
        {
            _12509 = 0.550000011920928955078125f;
        }
        else
        {
            _12509 = (ambient_weather.x - 0.60000002384185791015625f) * 1.60000002384185791015625f;
        }
        float lChance = _12509;
        float2 param_86 = float2(lSlot, 3.0f);
        float lStrikes = step(hash12(param_86), lChance);
        float2 param_87 = float2(lSlot, 7.0f);
        float lDt = ((ambient_weather.z - (lSlot * 7.0f)) - 1.0f) - (4.0f * hash12(param_87));
        float _12541;
        if (lDt < 0.0f)
        {
            _12541 = 0.0f;
        }
        else
        {
            float _12551;
            if (lDt < 0.180000007152557373046875f)
            {
                _12551 = 0.0f;
            }
            else
            {
                _12551 = 0.699999988079071044921875f * exp((-(lDt - 0.180000007152557373046875f)) * 9.0f);
            }
            _12541 = exp((-lDt) * 10.0f) + _12551;
        }
        float lFlash = _12541;
        lFlash = clamp(lFlash * lStrikes, 0.0f, 1.0f);
        light += ((float3(0.85000002384185791015625f, 0.949999988079071044921875f, 1.25f) * occlusion) * ((lFlash * 0.75f) * outdoor));
    }
    float _12582;
    if (ambient_skyExtra.x > 0.5f)
    {
        _12582 = 0.0f;
    }
    else
    {
        _12582 = ambient_weather.y * outdoor;
    }
    float rawWet = _12582;
    float3 param_88 = here;
    float wet = rawWet * architecturalExposure(param_88);
    float standing = 0.0f;
    if (rawWet > 0.0f)
    {
        bool _12605 = centre.w < 0.25f;
        bool _12611;
        if (_12605)
        {
            _12611 = ambient_sunLot.w > 0.0f;
        }
        else
        {
            _12611 = _12605;
        }
        bool _12623;
        if (_12611)
        {
            float2 param_89 = pixel;
            float3 param_90 = p;
            float3 param_91 = here;
            float3 param_92 = nSurf;
            _12623 = isRainRoofPixel(param_89, param_90, param_91, param_92);
        }
        else
        {
            _12623 = _12611;
        }
        bool onRoof = _12623;
        if (onRoof)
        {
            float3 param_93 = here + float3(0.0f, 0.0f, 0.449999988079071044921875f);
            float roofWet = rawWet * architecturalExposure(param_93);
            float2 param_94 = here.xy;
            float2 source = lotSource(param_94);
            float2 a = mul(source, float2x2(float2(0.800000011920928955078125f, 0.60000002384185791015625f), float2(-0.60000002384185791015625f, 0.800000011920928955078125f)));
            float2 b = mul(source, float2x2(float2(0.2800000011920928955078125f, -0.959999978542327880859375f), float2(0.959999978542327880859375f, 0.2800000011920928955078125f)));
            float2 param_95 = (a / 1.89999997615814208984375f.xx) + 5.30000019073486328125f.xx;
            float2 param_96 = (b / 0.85000002384185791015625f.xx) + 19.700000762939453125f.xx;
            float2 param_97 = float2((source.x * 2.599999904632568359375f) + (here.z * 0.4000000059604644775390625f), (source.y * 2.599999904632568359375f) - (here.z * 0.4000000059604644775390625f));
            float roofField = ((0.550000011920928955078125f * smoothNoise(param_95)) + (0.300000011920928955078125f * smoothNoise(param_96))) + (0.1500000059604644775390625f * smoothNoise(param_97));
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
                float2 param_98 = rid + 11.30000019073486328125f.xx;
                float2 param_99 = rid + 23.700000762939453125f.xx;
                float2 rdrop = (rid + 0.25f.xx) + (float2(hash12(param_98), hash12(param_99)) * 0.5f);
                float2 param_100 = rid + 5.099999904632568359375f.xx;
                float rage = frac((ambient_weather.z * (1.10000002384185791015625f + (0.64999997615814208984375f * ambient_weather.x))) + hash12(param_100));
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
                    float2 param_101 = here.xy;
                    float2 source_1 = lotSource(param_101);
                    float2 a_1 = mul(source_1, float2x2(float2(0.800000011920928955078125f, 0.60000002384185791015625f), float2(-0.60000002384185791015625f, 0.800000011920928955078125f)));
                    float2 b_1 = mul(source_1, float2x2(float2(0.2800000011920928955078125f, -0.959999978542327880859375f), float2(0.959999978542327880859375f, 0.2800000011920928955078125f)));
                    float2 c = mul(source_1, float2x2(float2(-0.60000002384185791015625f, 0.800000011920928955078125f), float2(-0.800000011920928955078125f, -0.60000002384185791015625f)));
                    float2 param_102 = a_1 / 2.400000095367431640625f.xx;
                    float2 param_103 = (b_1 / 1.14999997615814208984375f.xx) + 13.0f.xx;
                    float2 param_104 = (c / 0.550000011920928955078125f.xx) + 29.0f.xx;
                    float field = ((0.519999980926513671875f * smoothNoise(param_102)) + (0.3300000131130218505859375f * smoothNoise(param_103))) + (0.1500000059604644775390625f * smoothNoise(param_104));
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
                    bool _12976 = ambient_weather.x > 0.0f;
                    bool _12984;
                    if (_12976)
                    {
                        _12984 = (pool > 0.0199999995529651641845703125f) || (soaked > 0.3499999940395355224609375f);
                    }
                    else
                    {
                        _12984 = _12976;
                    }
                    if (_12984)
                    {
                        float2 g_1 = source_1 * 3.2000000476837158203125f;
                        float2 id = floor(g_1);
                        float2 param_105 = id;
                        float2 param_106 = id + 7.099999904632568359375f.xx;
                        float2 drop = (id + 0.25f.xx) + (float2(hash12(param_105), hash12(param_106)) * 0.5f);
                        float2 param_107 = id + 3.7000000476837158203125f.xx;
                        float age = frac((ambient_weather.z * (0.85000002384185791015625f + (0.550000011920928955078125f * ambient_weather.x))) + hash12(param_107));
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
    if (mode > 13.5f)
    {
        uint _13106_dummy_parameter;
        int2 oSize = int2(spvTextureSize(voxelMap, uint(0), _13106_dummy_parameter));
        float2 lotSz_1 = max(ambient_drift.zw, 1.0f.xx);
        float gDepth = groundMap.Sample(_groundMap_sampler, pixel / ambient_extent.xy).x;
        float3 _13124;
        if (gDepth < 0.99989998340606689453125f)
        {
            float2 param_108 = p.xy;
            float param_109 = (0.89999997615814208984375f - gDepth) / 0.0030000000260770320892333984375f;
            bool param_110 = true;
            float2 param_111 = ambient_frame.xy;
            _13124 = lotPoint(param_108, param_109, param_110, param_111);
        }
        else
        {
            _13124 = here;
        }
        float3 rayBase = _13124;
        bool _13147 = frac(rayBase.x) < 0.039999999105930328369140625f;
        bool _13155;
        if (!_13147)
        {
            _13155 = frac(rayBase.y) < 0.039999999105930328369140625f;
        }
        else
        {
            _13155 = _13147;
        }
        float gridLine = _13155 ? 1.14999997615814208984375f : 1.0f;
        float3 litGround = float3(0.4600000083446502685546875f, 0.5f, 0.439999997615814208984375f) * gridLine;
        float3 shadowGround = float3(0.0599999986588954925537109375f, 0.07999999821186065673828125f, 0.14000000059604644775390625f) * gridLine;
        float3 baseCol = lerp(shadowGround, litGround, clamp(lit, 0.0f, 1.0f).xxx);
        bool _13174 = oSize.x > 1;
        bool _13180;
        if (_13174)
        {
            _13180 = ambient_shadowView.w > 0.5f;
        }
        else
        {
            _13180 = _13174;
        }
        if (_13180)
        {
            uint _13186_dummy_parameter;
            float2 wSize_1 = float2(int2(spvTextureSize(worldDepthMap, uint(0), _13186_dummy_parameter)));
            float2 wp = ambient_shadowView.xy + (p.xy * ambient_shadowView.z);
            float wFront = worldDepthMap.Load(int3(clamp(int2(floor(wp)), int2(0, 0), int2(wSize_1) - int2(1, 1)), 0)).x;
            if (wFront < 0.99989998340606689453125f)
            {
                float frontKeyA = (0.89999997615814208984375f - wFront) / 0.0030000000260770320892333984375f;
                float baseKeyA = (rayBase.x + rayBase.y) + (0.800000011920928955078125f * rayBase.z);
                float sFront = (frontKeyA - baseKeyA) / 2.6400001049041748046875f;
                float sEnd = max(-0.20000000298023223876953125f, sFront - 2.400000095367431640625f);
                float3 hitCol = baseCol;
                bool hit = false;
                for (int i_3 = 0; i_3 <= 48; i_3++)
                {
                    float s = lerp(sFront, sEnd, float(i_3) / 48.0f);
                    float3 q_2 = rayBase + (float3(1.0f, 1.0f, 0.800000011920928955078125f) * s);
                    float3 param_112 = q_2;
                    int2 param_113 = oSize;
                    float2 param_114 = lotSz_1;
                    float2 param_115 = 0.0f.xx;
                    float param_116 = 0.0f;
                    float oOcc = dualViewHullAt(param_112, param_113, param_114, param_115, param_116);
                    if (oOcc > 0.3499999940395355224609375f)
                    {
                        float relZ = max(0.0f, q_2.z - rayBase.z);
                        float hNorm = clamp(relZ / 4.5f, 0.0f, 1.0f);
                        float3 ramp = lerp(float3(0.20000000298023223876953125f, 0.7799999713897705078125f, 0.980000019073486328125f), lerp(float3(0.3499999940395355224609375f, 0.949999988079071044921875f, 0.4000000059604644775390625f), float3(1.0f, 0.550000011920928955078125f, 0.180000007152557373046875f), clamp((hNorm * 2.0f) - 1.0f, 0.0f, 1.0f).xxx), clamp(hNorm * 2.0f, 0.0f, 1.0f).xxx);
                        hitCol = ramp * (0.64999997615814208984375f + (0.3499999940395355224609375f * oOcc));
                        hit = true;
                        break;
                    }
                }
                bool3 _13316 = hit.xxx;
                color = float4(float3(_13316.x ? hitCol.x : float3(0.85000002384185791015625f, 0.20000000298023223876953125f, 0.449999988079071044921875f).x, _13316.y ? hitCol.y : float3(0.85000002384185791015625f, 0.20000000298023223876953125f, 0.449999988079071044921875f).y, _13316.z ? hitCol.z : float3(0.85000002384185791015625f, 0.20000000298023223876953125f, 0.449999988079071044921875f).z), 1.0f);
            }
            else
            {
                color = float4(baseCol, 1.0f);
            }
        }
        else
        {
            color = float4(baseCol, 1.0f);
        }
        return;
    }
    if (mode > 12.5f)
    {
        float3 param_117 = here;
        float param_118 = onGround;
        float3 param_119 = here;
        color = float4(0.0f, windowSpill(param_117, param_118), lampNear(param_119), 1.0f);
        return;
    }
    if (mode > 11.5f)
    {
        color = float4(sky.xxx, 1.0f);
        return;
    }
    if (mode > 10.5f)
    {
        int2 param_120 = int2(floor(here.xy + ambient_frame.w.xx));
        int param_121 = 0;
        int cellMask = maskAt(param_120, param_121);
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
        uint _13405_dummy_parameter;
        float2 gridSize_1 = float2(int2(spvTextureSize(heightMap, uint(0), _13405_dummy_parameter)));
        float top = (0.5f - heightMap.Sample(_heightMap_sampler, ((here.xy + ambient_frame.w.xx) * ambient_frame.z) / gridSize_1).x) * 64.0f;
        color = float4(clamp(top / 6.0f, 0.0f, 1.0f), frac(top), float(top < (-16.0f)), 1.0f);
        return;
    }
    if (mode > 7.5f)
    {
        float depth = depthMap.Load(int3(int2(pixel), 0)).x;
        float ground = groundMap.Load(int3(int2(pixel), 0)).x;
        float _13456;
        if (depth < 1.0f)
        {
            _13456 = (0.89999997615814208984375f - depth) / 0.0030000000260770320892333984375f;
        }
        else
        {
            _13456 = ((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w;
        }
        float key_1 = _13456;
        float2 param_122 = p.xy;
        float param_123 = key_1;
        bool param_124 = depth >= 1.0f;
        float2 param_125 = ambient_frame.xy;
        float3 lot = lotPoint(param_122, param_123, param_124, param_125);
        float2 grid = step(0.89999997615814208984375f.xx, frac(lot.xy));
        color = float4(grid, step(0.5f, frac(lot.z)), 1.0f);
        float4 _13498 = color;
        float3 param_126 = lot;
        float3 _13506 = lerp(_13498.xyz, float3(1.0f, 0.800000011920928955078125f, 0.20000000298023223876953125f), (0.60000002384185791015625f * indoors(param_126)).xxx);
        color.x = _13506.x;
        color.y = _13506.y;
        color.z = _13506.z;
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
        float _13559;
        if ((centre.w < 0.25f) && (ground_1 < 1.0f))
        {
            _13559 = ((0.89999997615814208984375f - depthMap.Load(int3(int2(pixel), 0)).x) - (0.89999997615814208984375f - ground_1)) / 0.0030000000260770320892333984375f;
        }
        else
        {
            _13559 = 0.0f;
        }
        float difference = _13559;
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
    if (ambient_prevView.w > 0.5f)
    {
        float2 prevFullPixel = ambient_prevView.xy + (((pixel - ambient_view.xy) / ambient_view.z.xx) * ambient_prevView.z);
        uint _13666_dummy_parameter;
        float2 ambSize = float2(int2(spvTextureSize(prevAmbientMap, uint(0), _13666_dummy_parameter)));
        float2 prevAmbUV = (prevFullPixel / ambScale.xx) / ambSize;
        bool _13677 = all(bool2(prevAmbUV.x >= 0.0f.xx.x, prevAmbUV.y >= 0.0f.xx.y));
        bool _13683;
        if (_13677)
        {
            _13683 = all(bool2(prevAmbUV.x <= 1.0f.xx.x, prevAmbUV.y <= 1.0f.xx.y));
        }
        else
        {
            _13683 = _13677;
        }
        if (_13683)
        {
            float3 prevLight = prevAmbientMap.Sample(_prevAmbientMap_sampler, prevAmbUV).xyz * 2.0f;
            float diff = length(prevLight - light);
            float alpha = lerp(0.64999997615814208984375f, 1.0f, smoothstep(0.0199999995529651641845703125f, 0.07999999821186065673828125f, diff));
            light = lerp(prevLight, light, alpha.xxx);
        }
    }
    color = float4(clamp(light * 0.5f, 0.0f.xxx, 1.0f.xxx), 1.0f - standing);
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
