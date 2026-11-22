static const int2 _6997[4] = { int2(0, 1), int2(1, 1), int2(1, 0), int2(0, 0) };

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
Texture2D<float4> liftMap : register(t5, space2);
SamplerState _liftMap_sampler : register(s5, space2);
Texture2D<float4> footMap : register(t4, space2);
SamplerState _footMap_sampler : register(s4, space2);

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
    float _195;
    if (terrain)
    {
        _195 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _195 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _195;
    float _219;
    if (terrain)
    {
        _219 = key;
    }
    else
    {
        _219 = key - (0.800000011920928955078125f * h);
    }
    float s = _219;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

float groundAt(float2 pixel)
{
    float ground = groundMap.Load(int3(int2(pixel), 0)).x;
    float _390;
    if (ground < 1.0f)
    {
        _390 = (((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w) * 27.7128124237060546875f;
    }
    else
    {
        _390 = -100000.0f;
    }
    return _390;
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
    float _1535;
    if (slope > 0.100000001490116119384765625f)
    {
        _1535 = max(0.0f, (z - ground) / ((slope * 4.0f) / 3.0f));
    }
    else
    {
        _1535 = 0.0f;
    }
    return _1535;
}

int maskAt(int2 at, int band)
{
    uint _408_dummy_parameter;
    int2 size = int2(spvTextureSize(indoorMap, uint(0), _408_dummy_parameter));
    bool _411 = at.x < 0;
    bool _418;
    if (!_411)
    {
        _418 = at.y < 0;
    }
    else
    {
        _418 = _411;
    }
    bool _427;
    if (!_418)
    {
        _427 = at.x >= size.x;
    }
    else
    {
        _427 = _418;
    }
    bool _437;
    if (!_427)
    {
        _437 = at.y >= (size.y / 6);
    }
    else
    {
        _437 = _427;
    }
    if (_437)
    {
        return 0;
    }
    return int((indoorMap.Load(int3(int2(at.x, at.y + (band * (size.y / 6))), 0)).x * 255.0f) + 0.5f);
}

float indoors(float3 lot)
{
    float2 cell = (lot.xy + ambient_frame.w.xx) - 0.5f.xx;
    int2 base = int2(floor(cell));
    float2 f = clamp(((frac(cell) - 0.5f.xx) / 0.20000000298023223876953125f.xx) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
    float sum = 0.0f;
    float _530;
    float _543;
    float _576;
    float _589;
    float2 _654;
    float2 _662;
    for (int i = 0; i < 4; i++)
    {
        if ((i & 1) == 1)
        {
            _530 = f.x;
        }
        else
        {
            _530 = 1.0f - f.x;
        }
        if ((i >> 1) == 1)
        {
            _543 = f.y;
        }
        else
        {
            _543 = 1.0f - f.y;
        }
        float weight = _530 * _543;
        int2 at = base + int2(i & 1, i >> 1);
        int2 param = at;
        int param_1 = 2;
        int gCode = maskAt(param, param_1);
        int2 param_2 = at;
        int param_3 = 3;
        int f2Code = maskAt(param_2, param_3);
        if (gCode != 0)
        {
            _576 = ambient_contact.w + (float(gCode - 1) / 8.0f);
        }
        else
        {
            if (f2Code != 0)
            {
                _589 = (ambient_contact.w + (float(f2Code - 1) / 8.0f)) - 2.9500000476837158203125f;
            }
            else
            {
                _589 = ambient_contact.w;
            }
            _576 = _589;
        }
        float ground = _576;
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
            _654 = float2(1.0f, -1.0f);
        }
        else
        {
            if (part == 2)
            {
                _662 = float2(-1.0f, 1.0f);
            }
            else
            {
                bool2 _672 = (part == 3).xx;
                _662 = float2(_672.x ? (-1.0f).xx.x : 1.0f.xx.x, _672.y ? (-1.0f).xx.y : 1.0f.xx.y);
            }
            _654 = _662;
        }
        float2 toward = _654;
        sum += (weight * smoothstep(-0.0599999986588954925537109375f, 0.0599999986588954925537109375f, dot(((lot.xy + ambient_frame.w.xx) - float2(at)) - 0.5f.xx, toward)));
    }
    return sum;
}

float floorAt(int2 at, int row, float fallback)
{
    int2 param = at;
    int param_1 = row + 2;
    int code = maskAt(param, param_1);
    float _472;
    if (code == 0)
    {
        _472 = fallback;
    }
    else
    {
        _472 = ambient_contact.w + (float(code - 1) / 8.0f);
    }
    return _472;
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
    float2 _2344;
    if (part == 1)
    {
        _2344 = float2(1.0f, -1.0f);
    }
    else
    {
        float2 _2350;
        if (part == 2)
        {
            _2350 = float2(-1.0f, 1.0f);
        }
        else
        {
            bool2 _2356 = (part == 3).xx;
            _2350 = float2(_2356.x ? (-1.0f).xx.x : 1.0f.xx.x, _2356.y ? (-1.0f).xx.y : 1.0f.xx.y);
        }
        _2344 = _2350;
    }
    float2 toward = _2344;
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
    float _2490;
    int _2552;
    float _2589;
    float _2612;
    float _2696;
    int2 _2871;
    float2 _2935;
    int _2967;
    int _2981;
    int _2995;
    int _3009;
    float _3069;
    float _3155;
    for (int i = 0; i < 64; i++)
    {
        bool alongX = next.x < next.y;
        if (alongX)
        {
            _2490 = next.x;
        }
        else
        {
            _2490 = next.y;
        }
        float t = _2490;
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
                        _2552 = (part0 != 0) ? part0 : part1;
                    }
                    else
                    {
                        _2552 = (((part0 != 0) && (part1 != 0)) && (part1 != part0)) ? part1 : 0;
                    }
                    int part = _2552;
                    if (part == 0)
                    {
                        continue;
                    }
                    bool diag0 = part == part0;
                    bool diag1 = part == part1;
                    if (part <= 2)
                    {
                        _2589 = direction.x - direction.y;
                    }
                    else
                    {
                        _2589 = direction.x + direction.y;
                    }
                    float denom = _2589;
                    if (abs(denom) > 9.9999997473787516355514526367188e-05f)
                    {
                        if (part <= 2)
                        {
                            _2612 = ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom;
                        }
                        else
                        {
                            _2612 = ((1.0f - (start.x - float(cell.x))) - (start.y - float(cell.y))) / denom;
                        }
                        float tDiag = _2612;
                        bool _2651 = tDiag > (tPrev + 9.9999997473787516355514526367188e-05f);
                        bool _2658;
                        if (_2651)
                        {
                            _2658 = tDiag <= (t + 9.9999997473787516355514526367188e-05f);
                        }
                        else
                        {
                            _2658 = _2651;
                        }
                        if (_2658 && (tDiag <= maxDist))
                        {
                            float2 uDiag = (start + (direction * tDiag)) - float2(cell);
                            bool _2678 = all(bool2(uDiag.x >= (-0.00999999977648258209228515625f).xx.x, uDiag.y >= (-0.00999999977648258209228515625f).xx.y));
                            bool _2686;
                            if (_2678)
                            {
                                _2686 = all(bool2(uDiag.x <= 1.0099999904632568359375f.xx.x, uDiag.y <= 1.0099999904632568359375f.xx.y));
                            }
                            else
                            {
                                _2686 = _2678;
                            }
                            if (_2686)
                            {
                                float wallBot = diag0 ? cellBase0 : floor1;
                                if (diag1)
                                {
                                    _2696 = floor1 + 2.9500000476837158203125f;
                                }
                                else
                                {
                                    _2696 = cellBase0 + 2.9500000476837158203125f;
                                }
                                float wallTop = _2696;
                                if (here.z < (wallTop - topGuard))
                                {
                                    float zDiag = startZ + (tDiag * rise);
                                    float pen = min((0.04500000178813934326171875f * tDiag) + 0.0350000001490116119384765625f, 0.5f);
                                    float wallV = smoothstep(wallBot - 0.039999999105930328369140625f, wallBot + 0.039999999105930328369140625f, zDiag) * (1.0f - smoothstep(wallTop - (0.25f * pen), wallTop + (0.75f * pen), zDiag));
                                    float winOpen = 0.0f;
                                    int winRow = int(zDiag >= floor1);
                                    bool hasWinDiag = (winRow == 0) ? diag0 : diag1;
                                    bool _2769;
                                    if (hasWinDiag)
                                    {
                                        _2769 = (((winRow == 0) ? curM0 : curM1) & 1) != 0;
                                    }
                                    else
                                    {
                                        _2769 = hasWinDiag;
                                    }
                                    if (_2769)
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
            _2871 = int2(stepDir.x, 0);
        }
        else
        {
            _2871 = int2(0, stepDir.y);
        }
        int2 to = cell + _2871;
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
                _2935 = float2(float(stepDir.x), 0.0f);
            }
            else
            {
                _2935 = float2(0.0f, float(stepDir.y));
            }
            float2 edgeStep = _2935;
            float2 localA = (crossing - float2(cell)) - (edgeStep * 0.00999999977648258209228515625f);
            float2 localB = (crossing - float2(to)) + (edgeStep * 0.00999999977648258209228515625f);
            if (curM0 >= 2)
            {
                int2 param_24 = cell;
                int param_25 = 0;
                float2 param_26 = localA;
                _2967 = effectiveRoomAt(param_24, param_25, param_26);
            }
            else
            {
                _2967 = 0;
            }
            int r0A = _2967;
            if (nextM0 >= 2)
            {
                int2 param_27 = to;
                int param_28 = 0;
                float2 param_29 = localB;
                _2981 = effectiveRoomAt(param_27, param_28, param_29);
            }
            else
            {
                _2981 = 0;
            }
            int r0B = _2981;
            if (curM1 >= 2)
            {
                int2 param_30 = cell;
                int param_31 = 1;
                float2 param_32 = localA;
                _2995 = effectiveRoomAt(param_30, param_31, param_32);
            }
            else
            {
                _2995 = 0;
            }
            int r1A = _2995;
            if (nextM1 >= 2)
            {
                int2 param_33 = to;
                int param_34 = 1;
                float2 param_35 = localB;
                _3009 = effectiveRoomAt(param_33, param_34, param_35);
            }
            else
            {
                _3009 = 0;
            }
            int r1B = _3009;
            bool _3023 = r0A != r0B;
            bool _3031;
            if (_3023)
            {
                _3031 = (r0A > 0) || (r0B > 0);
            }
            else
            {
                _3031 = _3023;
            }
            bool hasWall0 = _3031;
            bool _3035 = r1A != r1B;
            bool _3043;
            if (_3035)
            {
                _3043 = (r1A > 0) || (r1B > 0);
            }
            else
            {
                _3043 = _3035;
            }
            bool hasWall1 = _3043;
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
                    _3069 = floor1_1 + 2.9500000476837158203125f;
                }
                else
                {
                    _3069 = base0 + 2.9500000476837158203125f;
                }
                float wallTop_1 = _3069;
                if (here.z < (wallTop_1 - topGuard))
                {
                    float pen_1 = min((0.04500000178813934326171875f * t) + 0.0350000001490116119384765625f, 0.5f);
                    float wallV_1 = smoothstep(wallBot_1 - 0.039999999105930328369140625f, wallBot_1 + 0.039999999105930328369140625f, zCross) * (1.0f - smoothstep(wallTop_1 - (0.25f * pen_1), wallTop_1 + (0.75f * pen_1), zCross));
                    float winOpen_1 = 0.0f;
                    int winRow_1 = int(zCross >= floor1_1);
                    bool hasWinWall = (winRow_1 == 0) ? hasWall0 : hasWall1;
                    bool _3132;
                    if (hasWinWall)
                    {
                        _3132 = (((winRow_1 == 0) ? curM0 : curM1) & 1) != 0;
                    }
                    else
                    {
                        _3132 = hasWinWall;
                    }
                    bool _3142;
                    if (_3132)
                    {
                        _3142 = (((winRow_1 == 0) ? nextM0 : nextM1) & 1) != 0;
                    }
                    else
                    {
                        _3142 = _3132;
                    }
                    if (_3142)
                    {
                        float relH_1 = zCross - ((winRow_1 == 0) ? base0 : floor1_1);
                        if (alongX)
                        {
                            _3155 = crossing.y;
                        }
                        else
                        {
                            _3155 = crossing.x;
                        }
                        float along_1 = frac(_3155);
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

float terrainBaseAt(float2 _point, float fallback)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _957;
    if (orientation == 1)
    {
        _957 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _971;
        if (orientation == 2)
        {
            _971 = size - _point;
        }
        else
        {
            float2 _980;
            if (orientation == 3)
            {
                _980 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _980 = _point;
            }
            _971 = _980;
        }
        _957 = _971;
    }
    float2 source = _957;
    bool _998 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _1006;
    if (!_998)
    {
        _1006 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _1006 = _998;
    }
    if (_1006)
    {
        return fallback;
    }
    uint _1014_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _1014_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
    uint _1028_dummy_parameter;
    int2 _1028 = int2(spvTextureSize(overheadMap, uint(0), _1028_dummy_parameter));
    if (any(bool2(at.x >= _1028.x, at.y >= _1028.y)))
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

float canopyBlockedTexel(int4 data, float canopyClearZ, float qPrevZ, float qZ, float pen)
{
    bool _1064 = data.w == 0;
    bool _1072;
    if (!_1064)
    {
        _1072 = data.w == 255;
    }
    else
    {
        _1072 = _1064;
    }
    if (_1072)
    {
        return 0.0f;
    }
    float qBase = float(((data.y * 256) + data.z) - 32768) / 256.0f;
    float prevRel = qPrevZ - qBase;
    float curRel = qZ - qBase;
    bool hasCeil1 = (data.x & 32) != 0;
    bool hasStory2 = (data.x & 64) != 0;
    float _1110;
    if (data.w >= 2)
    {
        _1110 = float(data.w - 2) / 16.0f;
    }
    else
    {
        _1110 = -1.0f;
    }
    float canopyTop = _1110;
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
    float2 _1259;
    if (orientation == 1)
    {
        _1259 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _1273;
        if (orientation == 2)
        {
            _1273 = size - _point;
        }
        else
        {
            float2 _1282;
            if (orientation == 3)
            {
                _1282 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _1282 = _point;
            }
            _1273 = _1282;
        }
        _1259 = _1273;
    }
    float2 source = _1259;
    bool _1300 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _1308;
    if (!_1300)
    {
        _1308 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _1308 = _1300;
    }
    if (_1308)
    {
        return 0.0f;
    }
    uint _1315_dummy_parameter;
    int2 mapSize = int2(spvTextureSize(overheadMap, uint(0), _1315_dummy_parameter));
    float2 fPos = (source * (float2(mapSize) / max(size, 1.0f.xx))) - 0.5f.xx;
    int2 i0 = int2(floor(fPos));
    float2 f = frac(fPos);
    int2 maxIdx = mapSize - int2(1, 1);
    int4 c00 = int4((overheadMap.Load(int3(clamp(i0, int2(0, 0), maxIdx), 0)) * 255.0f) + 0.5f.xxxx);
    int4 c10 = int4((overheadMap.Load(int3(clamp(i0 + int2(1, 0), int2(0, 0), maxIdx), 0)) * 255.0f) + 0.5f.xxxx);
    int4 c01 = int4((overheadMap.Load(int3(clamp(i0 + int2(0, 1), int2(0, 0), maxIdx), 0)) * 255.0f) + 0.5f.xxxx);
    int4 c11 = int4((overheadMap.Load(int3(clamp(i0 + int2(1, 1), int2(0, 0), maxIdx), 0)) * 255.0f) + 0.5f.xxxx);
    bool _1391 = c00.w != 0;
    bool _1397;
    if (_1391)
    {
        _1397 = c00.w != 255;
    }
    else
    {
        _1397 = _1391;
    }
    bool v00 = _1397;
    bool _1401 = c10.w != 0;
    bool _1407;
    if (_1401)
    {
        _1407 = c10.w != 255;
    }
    else
    {
        _1407 = _1401;
    }
    bool v10 = _1407;
    bool _1411 = c01.w != 0;
    bool _1417;
    if (_1411)
    {
        _1417 = c01.w != 255;
    }
    else
    {
        _1417 = _1411;
    }
    bool v01 = _1417;
    bool _1421 = c11.w != 0;
    bool _1427;
    if (_1421)
    {
        _1427 = c11.w != 255;
    }
    else
    {
        _1427 = _1421;
    }
    bool v11 = _1427;
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
    bool _1612 = any(bool2(wp.x < 1.0f.xx.x, wp.y < 1.0f.xx.y));
    bool _1622;
    if (!_1612)
    {
        float2 _1619 = wSize - 1.0f.xx;
        _1622 = any(bool2(wp.x >= _1619.x, wp.y >= _1619.y));
    }
    else
    {
        _1622 = _1612;
    }
    if (_1622)
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

float2 hiddenAtSoft(float3 q, float spreadPx, float2 rayPerp, float2 rayDirPx, float keyPerPx, float shellDepth, float frontSoft, float jitterAngle)
{
    float2 scene = float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
    float key = (q.x + q.y) + (0.800000011920928955078125f * q.z);
    if (ambient_shadowView.w > 0.5f)
    {
        uint _1868_dummy_parameter;
        float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _1868_dummy_parameter)));
        float2 wp = ambient_shadowView.xy + (scene * ambient_shadowView.z);
        float w1 = smoothstep(0.25f, 1.0f, spreadPx);
        if (w1 <= 0.0199999995529651641845703125f)
        {
            float2 param = wp;
            float param_1 = key;
            float2 param_2 = wSize;
            float param_3 = shellDepth;
            float param_4 = frontSoft;
            return hiddenAtWorld(param, param_1, param_2, param_3, param_4);
        }
        float cs = cos(jitterAngle);
        float sn = sin(jitterAngle);
        float r = spreadPx * (0.64999997615814208984375f * w1);
        float2 off = (rayPerp * (cs * r)) + (rayDirPx * ((sn * 0.7799999713897705078125f) * r));
        float kOff = keyPerPx * ((sn * 0.7799999713897705078125f) * r);
        float2 param_5 = wp + off;
        float param_6 = key + kOff;
        float2 param_7 = wSize;
        float param_8 = shellDepth;
        float param_9 = frontSoft;
        float2 sA = hiddenAtWorld(param_5, param_6, param_7, param_8, param_9);
        float2 param_10 = wp - off;
        float param_11 = key - kOff;
        float2 param_12 = wSize;
        float param_13 = shellDepth;
        float param_14 = frontSoft;
        float2 sB = hiddenAtWorld(param_10, param_11, param_12, param_13, param_14);
        return (sA + sB) * 0.5f;
    }
    float2 pixel = floor(ambient_view.xy + (scene * ambient_view.z)) + 0.5f.xx;
    bool _1983 = any(bool2(pixel.x < 0.0f.xx.x, pixel.y < 0.0f.xx.y));
    bool _1992;
    if (!_1983)
    {
        _1992 = pixel.x >= ambient_extent.x;
    }
    else
    {
        _1992 = _1983;
    }
    bool _2001;
    if (!_1992)
    {
        _2001 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _2001 = _1992;
    }
    if (_2001)
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
    float2 param_15 = scene;
    float param_16 = ((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w;
    bool param_17 = true;
    float2 param_18 = ambient_frame.xy;
    float3 lot = lotPoint(param_15, param_16, param_17, param_18);
    return float2(clamp(((((lot.x + lot.y) + (0.800000011920928955078125f * lot.z)) - key) + 0.4000000059604644775390625f) / 0.300000011920928955078125f, 0.0f, 1.0f), 0.0f);
}

float2 hiddenAtFast(float3 q, float spreadPx, float2 rayPerp, float2 rayDirPx, float keyPerPx, float shellDepth, float frontSoft, float jitterAngle)
{
    float2 scene = float2(32.0f * (q.x - q.y), (16.0f * (q.x + q.y)) - (40.0f * q.z)) + ambient_frame.xy;
    float key = (q.x + q.y) + (0.800000011920928955078125f * q.z);
    if (ambient_shadowView.w > 0.5f)
    {
        uint _2134_dummy_parameter;
        float2 wSize = float2(int2(spvTextureSize(worldDepthMap, uint(0), _2134_dummy_parameter)));
        float2 wp = ambient_shadowView.xy + (scene * ambient_shadowView.z);
        float w1 = smoothstep(0.25f, 1.0f, spreadPx);
        float r = spreadPx * (0.550000011920928955078125f * w1);
        float2 off = (rayPerp * (cos(jitterAngle) * r)) + (rayDirPx * ((sin(jitterAngle) * 0.7799999713897705078125f) * r));
        float kOff = keyPerPx * ((sin(jitterAngle) * 0.7799999713897705078125f) * r);
        float2 param = wp + off;
        float param_1 = key + kOff;
        float2 param_2 = wSize;
        float param_3 = shellDepth;
        float param_4 = frontSoft;
        return hiddenAtWorld(param, param_1, param_2, param_3, param_4);
    }
    float3 param_5 = q;
    float param_6 = spreadPx;
    float2 param_7 = rayPerp;
    float2 param_8 = rayDirPx;
    float param_9 = keyPerPx;
    float param_10 = shellDepth;
    float param_11 = frontSoft;
    float param_12 = jitterAngle;
    return hiddenAtSoft(param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12);
}

float3 sunMarch(float3 here, float start, float canopyClearZ)
{
    float lit = 1.0f;
    float litColumn = 1.0f;
    float litShell = 1.0f;
    uint _3711_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _3711_dummy_parameter)));
    int2 hMax = int2(gridSize) - int2(1, 1);
    float2 sunProj = float2(32.0f * (ambient_sunLot.x - ambient_sunLot.y), (16.0f * (ambient_sunLot.x + ambient_sunLot.y)) - (40.0f * ambient_sunLot.z));
    float projLen = length(sunProj);
    float2 _3742;
    if (projLen > 0.001000000047497451305389404296875f)
    {
        _3742 = sunProj / projLen.xx;
    }
    else
    {
        _3742 = float2(1.0f, 0.0f);
    }
    float2 sunDirPx = _3742;
    float2 sunPerp = float2(-sunDirPx.y, sunDirPx.x);
    float maxReach = ambient_sunLot.w + 0.20000000298023223876953125f;
    float maxT = min(maxReach, 10.5f / max(ambient_sunLot.z, 0.14000000059604644775390625f));
    if (maxT <= (start + 0.0199999995529651641845703125f))
    {
        return 1.0f.xxx;
    }
    float wScale = max(ambient_shadowView.z, 0.5f);
    float dtBase = clamp(2.599999904632568359375f / max(projLen, 18.0f), 0.064999997615814208984375f, 0.104999996721744537353515625f);
    float uMax = 26.0f;
    float farK = max(0.0f, (maxT - start) - (44.0f * dtBase)) / (uMax * uMax);
    float phase = frac((dot(here, ambient_sunLot.xyz) + start) / dtBase);
    float2 param = floor(gl_FragCoord.xy);
    float baseJitter = _noise(param) * 6.283185482025146484375f;
    float signedKeyRate = (ambient_sunLot.x + ambient_sunLot.y) + (0.800000011920928955078125f * ambient_sunLot.z);
    float keyRate = abs(signedKeyRate);
    float keyPerPx = signedKeyRate / max(projLen * wScale, 1.0f);
    float sunHorizLen = length(ambient_sunLot.xy);
    float2 _3854;
    if (sunHorizLen > 9.9999997473787516355514526367188e-05f)
    {
        _3854 = (float2(-ambient_sunLot.y, ambient_sunLot.x) / sunHorizLen.xx) * 1.4500000476837158203125f;
    }
    else
    {
        _3854 = float2(1.4500000476837158203125f, 0.0f);
    }
    float2 perpTexel = _3854;
    float solidRun = 0.0f;
    float3 qPrev = here;
    float _4053;
    float _4216;
    for (int i = 0; i < 44; i++)
    {
        float s = (float(i) + 1.0f) - phase;
        float u = max(0.0f, s - 18.0f);
        float t = (start + (s * dtBase)) + ((farK * u) * u);
        if (t > maxT)
        {
            break;
        }
        float dt = dtBase + ((2.0f * farK) * u);
        float3 q = here + (ambient_sunLot.xyz * t);
        if ((q.z - here.z) > 10.5f)
        {
            break;
        }
        float2 texel = (q.xy + ambient_frame.w.xx) * ambient_frame.z;
        bool _3947 = any(bool2(texel.x < 1.0f.xx.x, texel.y < 1.0f.xx.y));
        bool _3957;
        if (!_3947)
        {
            float2 _3954 = gridSize - 1.0f.xx;
            _3957 = any(bool2(texel.x > _3954.x, texel.y > _3954.y));
        }
        else
        {
            _3957 = _3947;
        }
        if (_3957)
        {
            break;
        }
        float startFade = smoothstep(0.0f, dtBase, t - start);
        float distFade = (1.0f - smoothstep(maxReach * 0.86000001430511474609375f, maxReach, t)) * startFade;
        float2 param_1 = q.xy;
        float param_2 = canopyClearZ;
        float param_3 = qPrev.z;
        float param_4 = q.z;
        float param_5 = (0.064999997615814208984375f * t) + 0.039999999105930328369140625f;
        float canopyOcc = canopyOcclusionAt(param_1, param_2, param_3, param_4, param_5);
        lit = min(lit, 1.0f - (canopyOcc * distFade));
        litColumn = min(litColumn, 1.0f - (canopyOcc * distFade));
        if ((lit <= 0.00999999977648258209228515625f) && (litColumn <= 0.00999999977648258209228515625f))
        {
            break;
        }
        int2 qCell = int2(floor(q.xy + ambient_frame.w.xx));
        int2 param_6 = qCell;
        int param_7 = 0;
        float param_8 = here.z;
        float qBase0 = floorAt(param_6, param_7, param_8);
        int qRow = int(q.z > ((qBase0 + 2.9500000476837158203125f) - 0.0500000007450580596923828125f));
        bool skipWindow = false;
        int2 param_9 = qCell;
        int param_10 = qRow;
        if ((maskAt(param_9, param_10) & 1) != 0)
        {
            if (qRow == 0)
            {
                _4053 = qBase0;
            }
            else
            {
                int2 param_11 = qCell;
                int param_12 = 1;
                float param_13 = qBase0 + 2.9500000476837158203125f;
                _4053 = floorAt(param_11, param_12, param_13);
            }
            float qFloorH = _4053;
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
            float penZ = (0.07999999821186065673828125f * t) + 0.04500000178813934326171875f;
            float4 tops = (0.5f.xxxx - heightMap.GatherRed(_heightMap_sampler, texel / gridSize)) * 64.0f;
            float4 blocked = clamp(((tops - q.z.xxxx) - 0.0599999986588954925537109375f.xxxx) / penZ.xxxx, 0.0f.xxxx, 1.0f.xxxx);
            float2 f = frac(texel - 0.5f.xx);
            float rawColumn = lerp(lerp(blocked.w, blocked.z, f.x), lerp(blocked.x, blocked.y, f.x), f.y);
            float coreColumn = 0.0f;
            if (rawColumn > 0.550000011920928955078125f)
            {
                float topL = (0.5f - heightMap.Load(int3(clamp(int2(floor(texel + perpTexel)), int2(0, 0), hMax), 0)).x) * 64.0f;
                float topR = (0.5f - heightMap.Load(int3(clamp(int2(floor(texel - perpTexel)), int2(0, 0), hMax), 0)).x) * 64.0f;
                float sideBlocked = min(clamp(((topL - q.z) - 0.0599999986588954925537109375f) / penZ, 0.0f, 1.0f), clamp(((topR - q.z) - 0.0599999986588954925537109375f) / penZ, 0.0f, 1.0f));
                float eroded = min(rawColumn, sideBlocked);
                if (eroded > 0.64999997615814208984375f)
                {
                    _4216 = solidRun + dt;
                }
                else
                {
                    _4216 = max(0.0f, solidRun - (2.0f * dt));
                }
                solidRun = _4216;
                coreColumn = smoothstep(0.579999983310699462890625f, 0.920000016689300537109375f, eroded) * smoothstep(0.14000000059604644775390625f, 0.2800000011920928955078125f, solidRun);
            }
            else
            {
                solidRun = max(0.0f, solidRun - (2.0f * dt));
            }
            float spreadPx = clamp(0.2800000011920928955078125f + (t * 1.14999997615814208984375f), 0.2800000011920928955078125f, 4.400000095367431640625f) * wScale;
            float stepKey = keyRate * dt;
            float canopyLift = smoothstep(1.5f, 3.2000000476837158203125f, q.z - here.z);
            float frontSoft = 0.14000000059604644775390625f + (0.054999999701976776123046875f * t);
            float shellDepth = (max(0.180000007152557373046875f, (stepKey * 1.60000002384185791015625f) + 0.119999997317790985107421875f) + (0.1599999964237213134765625f * coreColumn)) + (0.2199999988079071044921875f * canopyLift);
            float3 param_14 = q;
            float param_15 = spreadPx;
            float2 param_16 = sunPerp;
            float2 param_17 = sunDirPx;
            float param_18 = keyPerPx;
            float param_19 = shellDepth;
            float param_20 = frontSoft;
            float param_21 = baseJitter + (float(i) * 2.3999631404876708984375f);
            float2 seen = hiddenAtFast(param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21);
            float shell = seen.y * (1.0f / (1.0f + (0.02500000037252902984619140625f * t)));
            float occ = max(coreColumn * seen.x, shell) * distFade;
            lit = min(lit, 1.0f - occ);
            litColumn = min(litColumn, 1.0f - (coreColumn * distFade));
            litShell = min(litShell, 1.0f - (shell * distFade));
            if ((lit <= 0.00999999977648258209228515625f) && (litColumn <= 0.00999999977648258209228515625f))
            {
                break;
            }
        }
        qPrev = q;
    }
    return float3(lit, litColumn, litShell);
}

float2 lotSource(float2 camera)
{
    float2 size = ambient_drift.zw;
    int orientation = int(ambient_clouds.z + 0.5f);
    float2 _758;
    if (orientation == 1)
    {
        _758 = float2(camera.y, size.y - camera.x);
    }
    else
    {
        float2 _772;
        if (orientation == 2)
        {
            _772 = size - camera;
        }
        else
        {
            float2 _781;
            if (orientation == 3)
            {
                _781 = float2(size.x - camera.y, camera.x);
            }
            else
            {
                _781 = camera;
            }
            _772 = _781;
        }
        _758 = _772;
    }
    return _758;
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
    bool _2215 = cover <= 0.0f;
    bool _2222;
    if (!_2215)
    {
        _2222 = ambient_clouds.y <= 0.0f;
    }
    else
    {
        _2222 = _2215;
    }
    if (_2222)
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
    float _4456;
    float _4514;
    float _4537;
    float _4610;
    int2 _4689;
    float2 _4729;
    float _4786;
    int2 _4847;
    for (int i = 0; i < 16; i++)
    {
        bool alongX = next.x < next.y;
        if (alongX)
        {
            _4456 = next.x;
        }
        else
        {
            _4456 = next.y;
        }
        float t = _4456;
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
                    _4514 = direction.x - direction.y;
                }
                else
                {
                    _4514 = direction.x + direction.y;
                }
                float denom = _4514;
                if (abs(denom) > 9.9999997473787516355514526367188e-05f)
                {
                    if (part <= 2)
                    {
                        _4537 = ((start.y - float(cell.y)) - (start.x - float(cell.x))) / denom;
                    }
                    else
                    {
                        _4537 = ((1.0f - (start.x - float(cell.x))) - (start.y - float(cell.y))) / denom;
                    }
                    float tDiag = _4537;
                    bool _4577 = tDiag > max(tPrev, 0.02999999932944774627685546875f);
                    bool _4584;
                    if (_4577)
                    {
                        _4584 = tDiag <= (segEnd + 9.9999997473787516355514526367188e-05f);
                    }
                    else
                    {
                        _4584 = _4577;
                    }
                    if (_4584)
                    {
                        float2 uDiag = (start + (direction * tDiag)) - float2(cell);
                        bool _4598 = all(bool2(uDiag.x >= (-0.00999999977648258209228515625f).xx.x, uDiag.y >= (-0.00999999977648258209228515625f).xx.y));
                        bool _4604;
                        if (_4598)
                        {
                            _4604 = all(bool2(uDiag.x <= 1.0099999904632568359375f.xx.x, uDiag.y <= 1.0099999904632568359375f.xx.y));
                        }
                        else
                        {
                            _4604 = _4598;
                        }
                        if (_4604)
                        {
                            if (rowCell == 0)
                            {
                                _4610 = cellBase0;
                            }
                            else
                            {
                                int2 param_5 = cell;
                                int param_6 = 1;
                                float param_7 = cellBase0 + 2.9500000476837158203125f;
                                _4610 = floorAt(param_5, param_6, param_7);
                            }
                            float floorH = _4610;
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
                _4689 = int2(stepDir.x, 0);
            }
            else
            {
                _4689 = int2(0, stepDir.y);
            }
            int2 to = cell + _4689;
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
                _4729 = float2(float(stepDir.x), 0.0f);
            }
            else
            {
                _4729 = float2(0.0f, float(stepDir.y));
            }
            float2 edgeStep = _4729;
            int2 param_14 = cell;
            int param_15 = row;
            float2 param_16 = (crossing - float2(cell)) - (edgeStep * 0.00999999977648258209228515625f);
            int roomA = effectiveRoomAt(param_14, param_15, param_16);
            int2 param_17 = to;
            int param_18 = row;
            float2 param_19 = (crossing - float2(to)) + (edgeStep * 0.00999999977648258209228515625f);
            int roomB = effectiveRoomAt(param_17, param_18, param_19);
            bool _4772 = roomA != roomB;
            bool _4780;
            if (_4772)
            {
                _4780 = (roomA > 0) || (roomB > 0);
            }
            else
            {
                _4780 = _4772;
            }
            if (_4780)
            {
                if (row == 0)
                {
                    _4786 = base0;
                }
                else
                {
                    int2 param_20 = to;
                    int param_21 = 1;
                    float param_22 = base0 + 2.9500000476837158203125f;
                    int2 param_23 = cell;
                    int param_24 = 1;
                    float param_25 = floorAt(param_20, param_21, param_22);
                    _4786 = floorAt(param_23, param_24, param_25);
                }
                float floorH_1 = _4786;
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
                _4847 = int2(stepDir.x, 0);
            }
            else
            {
                _4847 = int2(0, stepDir.y);
            }
            cell += _4847;
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
    float rStart = isFire ? 0.519999980926513671875f : 0.4000000059604644775390625f;
    float rEnd = dist3D - receiverClear;
    if (rEnd <= (rStart + 0.02999999932944774627685546875f))
    {
        return 1.0f;
    }
    float3 outDir = toReceiver / dist3D.xxx;
    uint _4939_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _4939_dummy_parameter)));
    int2 hMax = int2(gridSize) - int2(1, 1);
    float2 rayProj = float2(32.0f * (outDir.x - outDir.y), (16.0f * (outDir.x + outDir.y)) - (40.0f * outDir.z));
    float projLen = length(rayProj);
    float2 _4970;
    if (projLen > 0.001000000047497451305389404296875f)
    {
        _4970 = rayProj / projLen.xx;
    }
    else
    {
        _4970 = float2(1.0f, 0.0f);
    }
    float2 rayDirPx = _4970;
    float2 rayPerp = float2(-rayDirPx.y, rayDirPx.x);
    float wScale = max(ambient_shadowView.z, 0.5f);
    float drBase = clamp(3.099999904632568359375f / max(projLen * wScale, 22.0f), 0.064999997615814208984375f, 0.104999996721744537353515625f);
    float farAccel = max(0.0f, ((rEnd - rStart) - (32.0f * drBase)) / 105.0f);
    float signedKeyRate = (outDir.x + outDir.y) + (0.800000011920928955078125f * outDir.z);
    float keyRate = abs(signedKeyRate);
    float keyPerPx = signedKeyRate / max(projLen * wScale, 1.0f);
    float horizLen = length(outDir.xy);
    float2 _5036;
    if (horizLen > 9.9999997473787516355514526367188e-05f)
    {
        _5036 = (float2(-outDir.y, outDir.x) / horizLen.xx) * 1.4500000476837158203125f;
    }
    else
    {
        _5036 = float2(1.4500000476837158203125f, 0.0f);
    }
    float2 perpTexel = _5036;
    float lightRadiusScenePx = isFire ? 11.0f : 7.0f;
    float2 param = floor(gl_FragCoord.xy) + (lampLot.xy * 13.0f);
    float baseJitter = _noise(param) * 6.283185482025146484375f;
    float r = rStart;
    float solidRun = 0.0f;
    float lit = 1.0f;
    float _5089;
    float _5260;
    for (int i = 0; i < 32; i++)
    {
        if (r >= rEnd)
        {
            break;
        }
        if (i < 18)
        {
            _5089 = drBase;
        }
        else
        {
            _5089 = drBase + (farAccel * float(i - 17));
        }
        float dr = _5089;
        float3 q = lampLot + (outDir * r);
        float xyFromLamp = length(q.xy - lampLot.xy);
        if (xyFromLamp >= (isFire ? 0.449999988079071044921875f : 0.3400000035762786865234375f))
        {
            float2 texel = (q.xy + ambient_frame.w.xx) * ambient_frame.z;
            bool _5135 = all(bool2(texel.x >= 1.0f.xx.x, texel.y >= 1.0f.xx.y));
            bool _5144;
            if (_5135)
            {
                float2 _5141 = gridSize - 1.0f.xx;
                _5144 = all(bool2(texel.x <= _5141.x, texel.y <= _5141.y));
            }
            else
            {
                _5144 = _5135;
            }
            if (_5144)
            {
                float dToReceiver = max(rEnd - r, 0.0f);
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
                        _5260 = solidRun + dr;
                    }
                    else
                    {
                        _5260 = max(0.0f, solidRun - (2.0f * dr));
                    }
                    solidRun = _5260;
                    coreColumn = smoothstep(0.579999983310699462890625f, 0.920000016689300537109375f, eroded) * smoothstep(0.14000000059604644775390625f, 0.2800000011920928955078125f, solidRun);
                }
                else
                {
                    solidRun = max(0.0f, solidRun - (2.0f * dr));
                }
                float coneFrac = clamp(dToReceiver / max(dist3D, 0.3499999940395355224609375f), 0.0f, 1.0f);
                float spreadPx = clamp(0.319999992847442626953125f + (lightRadiusScenePx * coneFrac), 0.319999992847442626953125f, 4.400000095367431640625f) * wScale;
                float stepKey = keyRate * dr;
                float canopyLift = smoothstep(1.5f, 3.0f, max(0.0f, q.z - origin.z));
                float frontSoft = 0.14000000059604644775390625f + (0.054999999701976776123046875f * dToReceiver);
                float shellDepth = (max(0.180000007152557373046875f, (stepKey * 1.60000002384185791015625f) + 0.119999997317790985107421875f) + (0.1599999964237213134765625f * coreColumn)) + (0.20000000298023223876953125f * canopyLift);
                float3 param_1 = q;
                float param_2 = spreadPx;
                float2 param_3 = rayPerp;
                float2 param_4 = rayDirPx;
                float param_5 = keyPerPx;
                float param_6 = shellDepth;
                float param_7 = frontSoft;
                float param_8 = baseJitter + (float(i) * 2.3999631404876708984375f);
                float2 seen = hiddenAtFast(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
                float shell = seen.y * (0.939999997615814208984375f / (1.0f + (0.039999999105930328369140625f * dToReceiver)));
                float occ = max(coreColumn * seen.x, shell);
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
    float _3329;
    if (best > 9.9999997473787516355514526367188e-05f)
    {
        _3329 = clamp(bestFire / best, 0.0f, 1.0f);
    }
    else
    {
        _3329 = 0.0f;
    }
    return float2(clamp(best * 2.0f, 0.0f, 1.0f), _3329);
}

float2 windowSpillInfo(float3 here, float onGround)
{
    float2 at = here.xy + ambient_frame.w.xx;
    int2 cell = int2(floor(at));
    int2 param = cell;
    int param_1 = 0;
    float param_2 = here.z;
    float ground = floorAt(param, param_1, param_2);
    bool _3367 = onGround <= 0.5f;
    bool _3377;
    if (!_3367)
    {
        _3377 = here.z > ((ground + 2.9500000476837158203125f) - 0.100000001490116119384765625f);
    }
    else
    {
        _3377 = _3367;
    }
    bool _3386;
    if (!_3377)
    {
        int2 param_3 = cell;
        int param_4 = 0;
        _3386 = maskAt(param_3, param_4) >= 2;
    }
    else
    {
        _3386 = _3377;
    }
    if (_3386)
    {
        return 0.0f.xx;
    }
    float best = 0.0f;
    float3 source = 0.0f.xxx;
    float3 glass = 0.0f.xxx;
    int2 _3445;
    int2 _3451;
    for (int y = -3; y <= 3; y++)
    {
        for (int x = -3; x <= 3; x++)
        {
            int2 room = cell + int2(x, y);
            int2 param_5 = room;
            int param_6 = 0;
            int code = maskAt(param_5, param_6);
            bool _3423 = code < 2;
            bool _3430;
            if (!_3423)
            {
                _3430 = (code & 1) == 0;
            }
            else
            {
                _3430 = _3423;
            }
            if (_3430)
            {
                continue;
            }
            for (int d = 0; d < 4; d++)
            {
                if (d == 0)
                {
                    _3445 = int2(1, 0);
                }
                else
                {
                    if (d == 1)
                    {
                        _3451 = int2(-1, 0);
                    }
                    else
                    {
                        bool2 _3460 = (d == 2).xx;
                        _3451 = int2(_3460.x ? int2(0, 1).x : int2(0, -1).x, _3460.y ? int2(0, 1).y : int2(0, -1).y);
                    }
                    _3445 = _3451;
                }
                int2 _step = _3445;
                int2 param_7 = room + _step;
                int param_8 = 0;
                int outside = maskAt(param_7, param_8);
                bool _3472 = outside >= 2;
                bool _3479;
                if (!_3472)
                {
                    _3479 = (outside & 1) == 0;
                }
                else
                {
                    _3479 = _3472;
                }
                if (_3479)
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
    uint _3594_dummy_parameter;
    float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _3594_dummy_parameter)));
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
    float2 _811;
    if (orientation == 1)
    {
        _811 = float2(_point.y, size.y - _point.x);
    }
    else
    {
        float2 _825;
        if (orientation == 2)
        {
            _825 = size - _point.xy;
        }
        else
        {
            float2 _835;
            if (orientation == 3)
            {
                _835 = float2(size.x - _point.y, _point.x);
            }
            else
            {
                _835 = _point.xy;
            }
            _825 = _835;
        }
        _811 = _825;
    }
    float2 source = _811;
    bool _855 = any(bool2(source.x < 0.0f.xx.x, source.y < 0.0f.xx.y));
    bool _863;
    if (!_855)
    {
        _863 = any(bool2(source.x >= size.x, source.y >= size.y));
    }
    else
    {
        _863 = _855;
    }
    if (_863)
    {
        return 1.0f;
    }
    uint _871_dummy_parameter;
    float2 texelsPerTile = float2(int2(spvTextureSize(overheadMap, uint(0), _871_dummy_parameter))) / max(size, 1.0f.xx);
    int2 at = int2(floor(source * texelsPerTile));
    uint _885_dummy_parameter;
    int2 _885 = int2(spvTextureSize(overheadMap, uint(0), _885_dummy_parameter));
    if (any(bool2(at.x >= _885.x, at.y >= _885.y)))
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
        bool _5573 = length(pT - pixel) < (0.699999988079071044921875f * rP);
        bool _5584;
        if (!_5573)
        {
            _5584 = length(pL - pR) < (0.75f * wP);
        }
        else
        {
            _5584 = _5573;
        }
        if (_5584)
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
        bool _5610 = qML.w < 0.25f;
        bool _5621;
        if (_5610)
        {
            _5621 = abs(qML.z - p0.z) < 14.0f;
        }
        else
        {
            _5621 = _5610;
        }
        bool _5627;
        if (_5621)
        {
            _5627 = qMR.w < 0.25f;
        }
        else
        {
            _5627 = _5621;
        }
        bool _5637;
        if (_5627)
        {
            _5637 = abs(qMR.z - p0.z) < 14.0f;
        }
        else
        {
            _5637 = _5627;
        }
        bool _5643;
        if (_5637)
        {
            _5643 = qT.w < 0.25f;
        }
        else
        {
            _5643 = _5637;
        }
        bool _5653;
        if (_5643)
        {
            _5653 = abs(qT.z - p0.z) < 22.0f;
        }
        else
        {
            _5653 = _5643;
        }
        bool _5659;
        if (_5653)
        {
            _5659 = qL.w < 0.25f;
        }
        else
        {
            _5659 = _5653;
        }
        bool _5669;
        if (_5659)
        {
            _5669 = abs(qL.z - p0.z) < 22.0f;
        }
        else
        {
            _5669 = _5659;
        }
        bool _5675;
        if (_5669)
        {
            _5675 = qR.w < 0.25f;
        }
        else
        {
            _5675 = _5669;
        }
        bool _5685;
        if (_5675)
        {
            _5685 = abs(qR.z - p0.z) < 22.0f;
        }
        else
        {
            _5685 = _5675;
        }
        bool _5696;
        if (_5685)
        {
            _5696 = abs(qL.z - qR.z) < 7.5f;
        }
        else
        {
            _5696 = _5685;
        }
        if (_5696)
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
                bool _5735 = (wFacing > 0.319999992847442626953125f) && (wFacing < 0.89999997615814208984375f);
                bool _5741;
                if (_5735)
                {
                    _5741 = nW.z > 0.3499999940395355224609375f;
                }
                else
                {
                    _5741 = _5735;
                }
                bool _5748;
                if (_5741)
                {
                    _5748 = abs(nW.x) > 0.1500000059604644775390625f;
                }
                else
                {
                    _5748 = _5741;
                }
                if (_5748)
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
            bool _5889 = any(bool2(pML_1.x < 0.5f.xx.x, pML_1.y < 0.5f.xx.y));
            bool _5897;
            if (!_5889)
            {
                _5897 = any(bool2(pML_1.x > maxPx.x, pML_1.y > maxPx.y));
            }
            else
            {
                _5897 = _5889;
            }
            bool _5904;
            if (!_5897)
            {
                _5904 = any(bool2(pMR_1.x < 0.5f.xx.x, pMR_1.y < 0.5f.xx.y));
            }
            else
            {
                _5904 = _5897;
            }
            bool _5912;
            if (!_5904)
            {
                _5912 = any(bool2(pMR_1.x > maxPx.x, pMR_1.y > maxPx.y));
            }
            else
            {
                _5912 = _5904;
            }
            bool _5919;
            if (!_5912)
            {
                _5919 = any(bool2(pT_1.x < 0.5f.xx.x, pT_1.y < 0.5f.xx.y));
            }
            else
            {
                _5919 = _5912;
            }
            bool _5927;
            if (!_5919)
            {
                _5927 = any(bool2(pT_1.x > maxPx.x, pT_1.y > maxPx.y));
            }
            else
            {
                _5927 = _5919;
            }
            bool _5934;
            if (!_5927)
            {
                _5934 = any(bool2(pL_1.x < 0.5f.xx.x, pL_1.y < 0.5f.xx.y));
            }
            else
            {
                _5934 = _5927;
            }
            bool _5942;
            if (!_5934)
            {
                _5942 = any(bool2(pL_1.x > maxPx.x, pL_1.y > maxPx.y));
            }
            else
            {
                _5942 = _5934;
            }
            bool _5949;
            if (!_5942)
            {
                _5949 = any(bool2(pR_1.x < 0.5f.xx.x, pR_1.y < 0.5f.xx.y));
            }
            else
            {
                _5949 = _5942;
            }
            bool _5957;
            if (!_5949)
            {
                _5957 = any(bool2(pR_1.x > maxPx.x, pR_1.y > maxPx.y));
            }
            else
            {
                _5957 = _5949;
            }
            if (_5957)
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
            bool _5983 = qML_1.w < 0.25f;
            bool _5994;
            if (_5983)
            {
                _5994 = abs(qML_1.z - p0.z) < 28.0f;
            }
            else
            {
                _5994 = _5983;
            }
            bool _6000;
            if (_5994)
            {
                _6000 = qMR_1.w < 0.25f;
            }
            else
            {
                _6000 = _5994;
            }
            bool _6010;
            if (_6000)
            {
                _6010 = abs(qMR_1.z - p0.z) < 28.0f;
            }
            else
            {
                _6010 = _6000;
            }
            bool _6016;
            if (_6010)
            {
                _6016 = qT_1.w < 0.25f;
            }
            else
            {
                _6016 = _6010;
            }
            bool _6027;
            if (_6016)
            {
                _6027 = abs(qT_1.z - p0.z) < 48.0f;
            }
            else
            {
                _6027 = _6016;
            }
            bool _6033;
            if (_6027)
            {
                _6033 = qL_1.w < 0.25f;
            }
            else
            {
                _6033 = _6027;
            }
            bool _6043;
            if (_6033)
            {
                _6043 = abs(qL_1.z - p0.z) < 48.0f;
            }
            else
            {
                _6043 = _6033;
            }
            bool _6049;
            if (_6043)
            {
                _6049 = qR_1.w < 0.25f;
            }
            else
            {
                _6049 = _6043;
            }
            bool _6059;
            if (_6049)
            {
                _6059 = abs(qR_1.z - p0.z) < 48.0f;
            }
            else
            {
                _6059 = _6049;
            }
            bool _6070;
            if (_6059)
            {
                _6070 = abs(qL_1.z - qR_1.z) < 20.0f;
            }
            else
            {
                _6070 = _6059;
            }
            if (_6070)
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
                    bool _6106 = wFacing_1 >= 0.920000016689300537109375f;
                    bool _6112;
                    if (_6106)
                    {
                        _6112 = nW_1.z > 0.3499999940395355224609375f;
                    }
                    else
                    {
                        _6112 = _6106;
                    }
                    if (_6112)
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
    float _6167;
    if (ambient_extent.w > 0.5f)
    {
        _6167 = ambient_extent.w;
    }
    else
    {
        _6167 = 1.0f;
    }
    float ambScale = _6167;
    float2 pixel = (floor(gl_FragCoord.xy) + 0.5f.xx) * ambScale;
    bool _6186 = pixel.x >= ambient_extent.x;
    bool _6195;
    if (!_6186)
    {
        _6195 = pixel.y >= ambient_extent.y;
    }
    else
    {
        _6195 = _6186;
    }
    if (_6195)
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
    float _step = max(1.0f, 1.5f * scale);
    float2 param_1 = pixel - float2(_step, 0.0f);
    float3 left = positionAt(param_1).xyz;
    float2 param_2 = pixel + float2(_step, 0.0f);
    float3 right = positionAt(param_2).xyz;
    float2 param_3 = pixel - float2(0.0f, _step);
    float3 up = positionAt(param_3).xyz;
    float2 param_4 = pixel + float2(0.0f, _step);
    float3 down = positionAt(param_4).xyz;
    float3 _6268;
    if (abs(right.z - p.z) < abs(p.z - left.z))
    {
        _6268 = right - p;
    }
    else
    {
        _6268 = p - left;
    }
    float3 dx = _6268;
    float3 _6293;
    if (abs(down.z - p.z) < abs(p.z - up.z))
    {
        _6293 = down - p;
    }
    else
    {
        _6293 = p - up;
    }
    float3 dy = _6293;
    float3 rawCross = cross(dy, dx);
    float rawLen = length(rawCross);
    float3 _6314;
    if (rawLen > 9.9999997473787516355514526367188e-06f)
    {
        _6314 = rawCross / rawLen.xxx;
    }
    else
    {
        _6314 = float3(0.0f, 0.0f, 1.0f);
    }
    float3 n = _6314;
    if (n.z < 0.0f)
    {
        n = -n;
    }
    float3 nSurf = n;
    float gradJump = max(abs(dx.z), abs(dy.z)) / max(_step / scale, 1.0f);
    float3 normal = normalize(lerp(n, float3(0.0f, 0.0f, 1.0f), 0.25f.xxx));
    float radius = ambient_params.x;
    float thickness = ambient_params.w;
    float visibility = 1.0f;
    if (ambient_params.y > 0.001000000047497451305389404296875f)
    {
        visibility = 0.0f;
        float2 param_5 = floor(gl_FragCoord.xy);
        float sliceJitter = _noise(param_5);
        float2 _6442;
        float horizons[2];
        float _6552;
        for (int slice = 0; slice < 3; slice++)
        {
            float phi = ((float(slice) + sliceJitter) * 3.1415927410125732421875f) / 3.0f;
            float2 direction = float2(cos(phi), sin(phi));
            float3 axis = float3(direction.y, -direction.x, 0.0f);
            float3 projected = normal - (axis * dot(normal, axis));
            float projectedLength = max(length(projected), 9.9999997473787516355514526367188e-05f);
            float cosN = clamp(projected.z / projectedLength, -1.0f, 1.0f);
            float n_1 = sign(dot(projected.xy, direction)) * acos(cosN);
            float sliceRadialShift = 0.3499999940395355224609375f + (0.300000011920928955078125f * float(slice & 1));
            for (int side = 0; side < 2; side++)
            {
                if (side == 0)
                {
                    _6442 = direction;
                }
                else
                {
                    _6442 = -direction;
                }
                float2 sideDirection = _6442;
                float best = -1.0f;
                for (int i = 0; i < 4; i++)
                {
                    float t = (float(i) + sliceRadialShift) / 4.0f;
                    float2 offset = ((((sideDirection * radius) * t) * t) * scale) + (sideDirection * 1.5f);
                    float2 samplePixel = pixel + offset;
                    bool _6484 = any(bool2(samplePixel.x < 0.0f.xx.x, samplePixel.y < 0.0f.xx.y));
                    bool _6493;
                    if (!_6484)
                    {
                        _6493 = samplePixel.x >= ambient_extent.x;
                    }
                    else
                    {
                        _6493 = _6484;
                    }
                    bool _6502;
                    if (!_6493)
                    {
                        _6502 = samplePixel.y >= ambient_extent.y;
                    }
                    else
                    {
                        _6502 = _6493;
                    }
                    if (_6502)
                    {
                        break;
                    }
                    float2 param_6 = samplePixel;
                    float3 delta = positionAt(param_6).xyz - p;
                    float _distance = length(delta);
                    float falloff = clamp((radius - _distance) / (0.4000000059604644775390625f * radius), 0.0f, 1.0f) * clamp((thickness - delta.z) / (0.5f * thickness), 0.0f, 1.0f);
                    float cosine = lerp(-1.0f, delta.z / max(_distance, 9.9999997473787516355514526367188e-05f), falloff);
                    best = max(best, cosine);
                }
                if (side == 0)
                {
                    _6552 = acos(clamp(best, -1.0f, 1.0f));
                }
                else
                {
                    _6552 = -acos(clamp(best, -1.0f, 1.0f));
                }
                horizons[side] = _6552;
            }
            float h1 = n_1 + min(horizons[0] - n_1, 1.57079637050628662109375f);
            float h0 = n_1 + max(horizons[1] - n_1, -1.57079637050628662109375f);
            float sinN = sin(n_1);
            visibility += ((projectedLength * 0.25f) * ((((-cos((2.0f * h0) - n_1)) + cosN) + ((2.0f * h0) * sinN)) + (((-cos((2.0f * h1) - n_1)) + cosN) + ((2.0f * h1) * sinN))));
        }
        visibility = clamp(visibility / 3.0f, 0.0f, 1.0f);
    }
    float multiBounceVis = visibility * (1.0f + (0.14000000059604644775390625f * (1.0f - visibility)));
    float occlusion = clamp(lerp(1.0f, clamp(multiBounceVis, 0.0f, 1.0f), ambient_params.y), 0.180000007152557373046875f, 1.0f);
    float _6643;
    if (centre.w < 0.25f)
    {
        _6643 = (0.89999997615814208984375f - depthMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f;
    }
    else
    {
        _6643 = ((0.89999997615814208984375f - groundMap.Load(int3(int2(pixel), 0)).x) / 0.0030000000260770320892333984375f) + ambient_view.w;
    }
    float key = _6643;
    float2 param_7 = p.xy;
    float param_8 = key;
    bool param_9 = centre.w > 0.25f;
    float2 param_10 = ambient_frame.xy;
    float3 here = lotPoint(param_7, param_8, param_9, param_10);
    float2 param_11 = pixel;
    float param_12 = p.z;
    float riseHere = riseAt(param_11, param_12);
    float onGround = 1.0f - smoothstep(2.0f, 6.0f, riseHere);
    uint _6697_dummy_parameter;
    float4 _6700;
    if (int2(spvTextureSize(liftMap, uint(0), _6697_dummy_parameter)).x > 1)
    {
        _6700 = liftMap.Load(int3(int2(pixel), 0));
    }
    else
    {
        _6700 = 0.0f.xxxx;
    }
    float4 lift = _6700;
    bool onSnow = lift.z > 0.5f;
    if (onSnow)
    {
        here += float3(0.5f * lift.x, 0.5f * lift.x, lift.y);
        onGround = 1.0f;
        occlusion = 1.0f;
    }
    float roofSnow = lift.w;
    bool _6734 = !onSnow;
    bool _6740;
    if (_6734)
    {
        _6740 = centre.w < 0.25f;
    }
    else
    {
        _6740 = _6734;
    }
    bool _6746;
    if (_6740)
    {
        _6746 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _6746 = _6740;
    }
    bool _6749 = _6746 && (riseHere > 105.0f);
    bool _6756;
    if (_6749)
    {
        float3 param_13 = here;
        _6756 = indoors(param_13) < 0.20000000298023223876953125f;
    }
    else
    {
        _6756 = _6749;
    }
    float _6757;
    if (_6756)
    {
        _6757 = smoothstep(105.0f, 122.0f, riseHere) * smoothstep(0.319999992847442626953125f, 0.60000002384185791015625f, dot(normal, float3(0.0f, -0.866025388240814208984375f, 0.5f)));
    }
    else
    {
        _6757 = 0.0f;
    }
    float highRoof = _6757;
    float roofCalm = clamp(max(roofSnow, highRoof), 0.0f, 1.0f);
    if (roofCalm > 0.00999999977648258209228515625f)
    {
        occlusion = lerp(occlusion, 1.0f - ((1.0f - occlusion) * 0.14000000059604644775390625f), roofCalm);
    }
    int2 hereCell = int2(floor(here.xy + ambient_frame.w.xx));
    int2 param_14 = hereCell;
    int param_15 = 1;
    float param_16 = -100.0f;
    float floor2Z = floorAt(param_14, param_15, param_16);
    float _6806;
    if (floor2Z > (-50.0f))
    {
        _6806 = (1.0f - smoothstep(0.07999999821186065673828125f, 0.2199999988079071044921875f, abs(here.z - floor2Z))) * smoothstep(0.3499999940395355224609375f, 0.64999997615814208984375f, normal.z);
    }
    else
    {
        _6806 = 0.0f;
    }
    float onLevel2Floor = _6806;
    float onFlatFloor = max(onGround, onLevel2Floor);
    float contact = 1.0f;
    if (ambient_sunLot.w > 0.0f)
    {
        bool _6839 = ((centre.w > 0.25f) || onSnow) || (onLevel2Floor > 0.5f);
        bool _6845;
        if (_6839)
        {
            _6845 = ambient_contact.y > 0.0f;
        }
        else
        {
            _6845 = _6839;
        }
        if (_6845)
        {
            float detail = ambient_frame.z;
            uint _6855_dummy_parameter;
            int2 footSize = int2(spvTextureSize(footMap, uint(0), _6855_dummy_parameter));
            float2 invFootSize = 1.0f.xx / float2(footSize);
            float2 at = (here.xy + ambient_frame.w.xx) * detail;
            float best_1 = 0.0f;
            float sum = 0.0f;
            if ((0.125f * detail) <= 2.0099999904632568359375f)
            {
                int2 base = int2(floor(at - 1.5f.xx));
                for (int qy = 0; qy < 4; qy += 2)
                {
                    for (int qx = 0; qx < 4; qx += 2)
                    {
                        int2 qb = base + int2(qx, qy);
                        bool _6910 = (qb.x + 1) < 0;
                        bool _6918;
                        if (!_6910)
                        {
                            _6918 = (qb.y + 1) < 0;
                        }
                        else
                        {
                            _6918 = _6910;
                        }
                        bool _6927;
                        if (!_6918)
                        {
                            _6927 = qb.x >= footSize.x;
                        }
                        else
                        {
                            _6927 = _6918;
                        }
                        bool _6936;
                        if (!_6927)
                        {
                            _6936 = qb.y >= footSize.y;
                        }
                        else
                        {
                            _6936 = _6927;
                        }
                        if (_6936)
                        {
                            continue;
                        }
                        float4 g = footMap.GatherRed(_footMap_sampler, (float2(qb) + 1.0f.xx) * invFootSize);
                        if (min(min(g.x, g.y), min(g.z, g.w)) >= 1.0f)
                        {
                            continue;
                        }
                        float _6976[4] = { g.x, g.y, g.z, g.w };
                        float vals[4] = _6976;
                        for (int k = 0; k < 4; k++)
                        {
                            float stored = vals[k];
                            if (stored >= 1.0f)
                            {
                                continue;
                            }
                            int2 texel = qb + _6997[k];
                            bool _7006 = any(bool2(texel.x < int2(0, 0).x, texel.y < int2(0, 0).y));
                            bool _7014;
                            if (!_7006)
                            {
                                _7014 = any(bool2(texel.x >= footSize.x, texel.y >= footSize.y));
                            }
                            else
                            {
                                _7014 = _7006;
                            }
                            if (_7014)
                            {
                                continue;
                            }
                            float footZ = (0.5f - stored) * 64.0f;
                            if (abs(footZ - here.z) > 0.25f)
                            {
                                continue;
                            }
                            float near = max(0.0f, 1.0f - (length(((float2(texel) + 0.5f.xx) - at) / detail.xx) / 0.125f));
                            best_1 = max(best_1, near * near);
                            sum += (near * near);
                        }
                    }
                }
            }
            else
            {
                int2 centreTexel = int2(floor(at));
                int footR = clamp(int(ceil(0.125f * detail)), 1, 4);
                int _7074 = -footR;
                for (int y = _7074; y <= footR; y++)
                {
                    int _7085 = -footR;
                    for (int x = _7085; x <= footR; x++)
                    {
                        int2 texel_1 = centreTexel + int2(x, y);
                        bool _7102 = any(bool2(texel_1.x < int2(0, 0).x, texel_1.y < int2(0, 0).y));
                        bool _7110;
                        if (!_7102)
                        {
                            _7110 = any(bool2(texel_1.x >= footSize.x, texel_1.y >= footSize.y));
                        }
                        else
                        {
                            _7110 = _7102;
                        }
                        if (_7110)
                        {
                            continue;
                        }
                        float stored_1 = footMap.Load(int3(texel_1, 0)).x;
                        if (stored_1 >= 1.0f)
                        {
                            continue;
                        }
                        float footZ_1 = (0.5f - stored_1) * 64.0f;
                        if (abs(footZ_1 - here.z) > 0.25f)
                        {
                            continue;
                        }
                        float near_1 = max(0.0f, 1.0f - (length(((float2(texel_1) + 0.5f.xx) - at) / detail.xx) / 0.125f));
                        best_1 = max(best_1, near_1 * near_1);
                        sum += (near_1 * near_1);
                    }
                }
            }
            float feet = clamp((0.699999988079071044921875f * best_1) + (0.039999999105930328369140625f * sum), 0.0f, 1.0f);
            uint _7176_dummy_parameter;
            float2 gridSize = float2(int2(spvTextureSize(heightMap, uint(0), _7176_dummy_parameter)));
            float over = ((0.5f - heightMap.Sample(_heightMap_sampler, ((here.xy + ambient_frame.w.xx) * ambient_frame.z) / gridSize).x) * 64.0f) - here.z;
            float under = smoothstep(0.20000000298023223876953125f, 0.4000000059604644775390625f, over) * (1.0f - smoothstep(2.0f, 2.599999904632568359375f, over));
            contact = 1.0f - (ambient_contact.y * clamp(feet + (0.300000011920928955078125f * under), 0.0f, 1.0f));
        }
    }
    else
    {
        bool _7216 = onGround > 0.0f;
        bool _7222;
        if (_7216)
        {
            _7222 = ambient_contact.y > 0.0f;
        }
        else
        {
            _7222 = _7216;
        }
        if (_7222)
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
                    bool _7289 = any(bool2(samplePixel_1.x < 0.0f.xx.x, samplePixel_1.y < 0.0f.xx.y));
                    bool _7298;
                    if (!_7289)
                    {
                        _7298 = samplePixel_1.x >= ambient_extent.x;
                    }
                    else
                    {
                        _7298 = _7289;
                    }
                    bool _7307;
                    if (!_7298)
                    {
                        _7307 = samplePixel_1.y >= ambient_extent.y;
                    }
                    else
                    {
                        _7307 = _7298;
                    }
                    if (_7307)
                    {
                        break;
                    }
                    float2 param_17 = samplePixel_1;
                    float4 q = positionAt(param_17);
                    if (q.w > 0.75f)
                    {
                        continue;
                    }
                    float2 param_18 = samplePixel_1;
                    float param_19 = q.z;
                    float rise = riseAt(param_18, param_19);
                    float height = (rise - riseHere) / 0.866025388240814208984375f;
                    float along = length(((q.xy + float2(0.0f, rise)) - footHere) * float2(1.0f, 2.0f));
                    if ((height < 1.0f) || (along > contactRadius))
                    {
                        continue;
                    }
                    float near_2 = 1.0f - (along / contactRadius);
                    best_2 = max(best_2, (height / ((height + (0.5f * along)) + 2.0f)) * near_2);
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
    float2 _7414;
    if (length(nLot.xy) > 0.1500000059604644775390625f)
    {
        _7414 = normalize(nLot.xy);
    }
    else
    {
        _7414 = 0.0f.xx;
    }
    float2 horizN = _7414;
    float isVertical = (((1.0f - onFlatFloor) * (1.0f - smoothstep(0.2199999988079071044921875f, 0.4199999868869781494140625f, abs(nUp)))) * (1.0f - roofCalm)) * (1.0f - smoothstep(2.5f, 4.5f, gradJump));
    float lit = 1.0f;
    float litColumn = 1.0f;
    float litShell = 1.0f;
    float inside = 0.0f;
    if (ambient_sunLot.w > 0.0f)
    {
        float2 insideOffset = lerp(horizN * 0.25f, 0.0f.xx, onFlatFloor.xx);
        float3 param_20 = here + float3(insideOffset, 0.0f);
        inside = indoors(param_20);
    }
    float window = 0.0f;
    bool _7466 = ambient_sunLot.w > 0.0f;
    bool _7472;
    if (_7466)
    {
        _7472 = ambient_params.z > 0.001000000047497451305389404296875f;
    }
    else
    {
        _7472 = _7466;
    }
    if (_7472)
    {
        float3 sunView = normalize(ambient_light.xyz + float3(0.0f, 0.0f, 9.9999997473787516355514526367188e-05f));
        float ndotl = dot(nSurf, sunView);
        float faceLit = smoothstep(-0.07999999821186065673828125f, 0.2199999988079071044921875f, ndotl);
        float selfShadow = lerp(1.0f, faceLit, max(isVertical, roofCalm));
        float3 param_21 = here;
        float param_22 = onFlatFloor;
        float2 param_23 = horizN;
        float2 wall = wallRay(param_21, param_22, param_23);
        float3 marchOrigin = (here + float3(horizN * (0.20000000298023223876953125f * isVertical), 0.0f)) + (nLot * (0.180000007152557373046875f * roofCalm));
        float marchStart = lerp(lerp(0.64999997615814208984375f, 0.180000007152557373046875f, roofCalm), 0.119999997317790985107421875f, isVertical);
        marchStart = lerp(marchStart, 0.0599999986588954925537109375f, onFlatFloor);
        float2 param_24 = here.xy;
        float param_25 = here.z;
        float hereRelZ = here.z - terrainBaseAt(param_24, param_25);
        float canopyClearZ = hereRelZ + lerp(0.20000000298023223876953125f, -0.0500000007450580596923828125f, isVertical);
        float3 _7551;
        if ((wall.x > 0.00999999977648258209228515625f) && (selfShadow > 0.00999999977648258209228515625f))
        {
            float3 param_26 = marchOrigin;
            float param_27 = marchStart;
            float param_28 = canopyClearZ;
            _7551 = sunMarch(param_26, param_27, param_28);
        }
        else
        {
            _7551 = 0.0f.xxx;
        }
        float3 march = _7551;
        lit = min(min(wall.x, march.x), selfShadow);
        litColumn = min(min(wall.x, march.y), selfShadow);
        litShell = march.z;
        window = ((inside * max(onFlatFloor, isVertical * faceLit)) * wall.y) * march.x;
    }
    float _7596;
    if (ambient_sunLot.w > 0.0f)
    {
        float3 param_29 = here;
        _7596 = cloudLight(param_29);
    }
    else
    {
        _7596 = 1.0f;
    }
    float sky = _7596;
    window *= sky;
    lit *= sky;
    float shadowStr = clamp(((ambient_params.z * lerp(1.0f, 0.680000007152557373046875f, inside)) * (1.0f + ((0.2800000011920928955078125f * isVertical) * (1.0f - (0.550000011920928955078125f * inside))))) * lerp(1.0f, 0.7200000286102294921875f, roofCalm), 0.0f, 0.85000002384185791015625f);
    float shadow = lerp(1.0f, lit, shadowStr);
    float3 lampLight = 0.0f.xxx;
    float3 fireLight = 0.0f.xxx;
    int lampCount = int(ambient_lamp.x);
    float reach = ambient_lamp.y;
    bool sides = ambient_sunLot.w > 0.0f;
    float tFire = ambient_weather.z;
    float3 pLamp = float3(p.xy, ((here.x + here.y) + (0.800000011920928955078125f * here.z)) * 27.7128124237060546875f);
    float3 spriteLampNormal = normalize(lerp(nSurf, float3(0.0f, 0.0f, 1.0f), 0.36000001430511474609375f.xxx));
    float3 _7676;
    if (centre.w > 0.25f)
    {
        _7676 = nSurf;
    }
    else
    {
        _7676 = normalize(lerp(spriteLampNormal, nSurf, onLevel2Floor.xxx));
    }
    float3 lampNormal = _7676;
    float _7782;
    float _7846;
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
            _7782 = reach * (1.10000002384185791015625f + (0.07999999821186065673828125f * flicker01));
        }
        else
        {
            _7782 = reach;
        }
        float lampReach = _7782;
        if (_distance_1 >= lampReach)
        {
            continue;
        }
        float3 lampLot = 0.0f.xxx;
        float sameSide = 1.0f;
        if (sides)
        {
            float2 param_30 = lamp.xy;
            float param_31 = lamp.z;
            bool param_32 = false;
            float2 param_33 = ambient_frame.xy;
            lampLot = lotPoint(param_30, param_31, param_32, param_33);
            float3 param_34 = here;
            float3 param_35 = lampLot;
            float param_36 = onFlatFloor;
            float2 param_37 = horizN;
            sameSide = lampWallVis(param_34, param_35, param_36, param_37);
            if (sameSide <= 0.00999999977648258209228515625f)
            {
                continue;
            }
        }
        float3 direction_2 = toLamp / max(_distance_1, 9.9999997473787516355514526367188e-05f).xxx;
        float falloff_1 = 1.0f - (_distance_1 / lampReach);
        falloff_1 *= falloff_1;
        if (isFire)
        {
            _7846 = clamp((dot(lampNormal, direction_2) * 0.550000011920928955078125f) + 0.449999988079071044921875f, 0.0f, 1.0f);
        }
        else
        {
            _7846 = clamp((dot(lampNormal, direction_2) * 0.60000002384185791015625f) + 0.4000000059604644775390625f, 0.0f, 1.0f);
        }
        float facing = _7846;
        if (((((strength * flicker) * falloff_1) * facing) * sameSide) < 0.014999999664723873138427734375f)
        {
            continue;
        }
        float open = 1.0f;
        if (sides)
        {
            float3 param_38 = here;
            float3 param_39 = lampLot;
            float param_40 = onFlatFloor;
            float param_41 = isVertical;
            float param_42 = nUp;
            float2 param_43 = horizN;
            bool param_44 = isFire;
            open = lampMarch(param_38, param_39, param_40, param_41, param_42, param_43, param_44);
        }
        else
        {
            for (int i_2 = 1; i_2 < 16; i_2++)
            {
                float t_2 = ((float(i_2) - 0.5f) / 16.0f) * _distance_1;
                bool _7919;
                if (isFire)
                {
                    _7919 = (_distance_1 - t_2) < 22.0f;
                }
                else
                {
                    _7919 = isFire;
                }
                if (_7919)
                {
                    continue;
                }
                float3 q_1 = pLamp + (direction_2 * t_2);
                float2 samplePixel_2 = ambient_view.xy + (q_1.xy * scale);
                bool _7940 = any(bool2(samplePixel_2.x < 0.0f.xx.x, samplePixel_2.y < 0.0f.xx.y));
                bool _7949;
                if (!_7940)
                {
                    _7949 = samplePixel_2.x >= ambient_extent.x;
                }
                else
                {
                    _7949 = _7940;
                }
                bool _7958;
                if (!_7949)
                {
                    _7958 = samplePixel_2.y >= ambient_extent.y;
                }
                else
                {
                    _7958 = _7949;
                }
                if (_7958)
                {
                    break;
                }
                float2 param_45 = samplePixel_2;
                float4 samplePos = positionAt(param_45);
                float sampleZ = samplePos.z;
                bool _7971 = samplePos.w > 0.25f;
                bool _7977;
                if (_7971)
                {
                    _7977 = samplePos.w < 0.75f;
                }
                else
                {
                    _7977 = _7971;
                }
                if (_7977)
                {
                    float2 param_46 = samplePos.xy;
                    float param_47 = samplePos.z / 27.7128124237060546875f;
                    bool param_48 = true;
                    float2 param_49 = ambient_frame.xy;
                    float3 sampleLot = lotPoint(param_46, param_47, param_48, param_49);
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
            lampLight += (float3(1.0f, 0.819999992847442626953125f, 0.579999983310699462890625f) * ((((strength * falloff_1) * facing) * open) * sameSide));
        }
    }
    float nightFactor = clamp(ambient_weather.w, 0.0f, 1.0f);
    float lowSun = 1.0f - smoothstep(0.119999997317790985107421875f, 0.519999980926513671875f, ambient_sunLot.z);
    float3 dayWindowColor = lerp(float3(1.0f, 0.939999997615814208984375f, 0.819999992847442626953125f), float3(1.13999998569488525390625f, 0.680000007152557373046875f, 0.36000001430511474609375f), lowSun.xxx);
    float3 moonWindowColor = float3(0.680000007152557373046875f, 0.819999992847442626953125f, 1.14999997615814208984375f);
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
    float keyWrap = dot(normal, normalize(ambient_light.xyz + float3(0.0f, 0.0f, 9.9999997473787516355514526367188e-05f)));
    float shadowActive = clamp(ambient_params.z * 1.7999999523162841796875f, 0.0f, 1.0f);
    float dirShade = 1.0f + ((((((keyWrap * 0.180000007152557373046875f) - 0.039999999105930328369140625f) * lerp(1.0f, 0.550000011920928955078125f, inside)) * lit) * shadowActive) * (1.0f - (0.449999988079071044921875f * onFlatFloor)));
    float deBakeWeight = smoothstep(0.0199999995529651641845703125f, 0.100000001490116119384765625f, ambient_params.z);
    float wallDeBake = exp((((-0.4199999868869781494140625f) * clamp(nSurf.x, -0.699999988079071044921875f, 0.699999988079071044921875f)) * isVertical) * deBakeWeight);
    dirShade *= wallDeBake;
    float sunBloom = 1.0f + ((((0.10999999940395355224609375f * (1.0f - nightFactor)) * lit) * sunWeight) * shadowActive);
    float3 light = (((((shadow * dirShade) * sunBloom) * ambient_lamp.w).xxx + totalLamps) + (windowColor * ((0.2199999988079071044921875f * ambient_contact.z) * window))) * (occlusion * contact);
    float daylight = clamp((1.0f - nightFactor) * clamp(ambient_params.z * 2.0f, 0.0f, 1.0f), 0.0f, 1.0f);
    float3 warmSun = lerp(float3(1.09000003337860107421875f, 1.0099999904632568359375f, 0.910000026226043701171875f), float3(1.2599999904632568359375f, 0.86000001430511474609375f, 0.579999983310699462890625f), lowSun.xxx);
    float3 coolShade = lerp(float3(0.839999973773956298828125f, 0.939999997615814208984375f, 1.17999994754791259765625f), float3(0.7200000286102294921875f, 0.839999973773956298828125f, 1.2400000095367431640625f), lowSun.xxx);
    float3 sunTint = lerp(coolShade, warmSun, lit.xxx);
    sunTint /= dot(sunTint, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)).xxx;
    float fireShare = dot(fires, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)) / ((ambient_lamp.w + dot(fires, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f))) + 9.9999997473787516355514526367188e-05f);
    float3 tint = lerp(1.0f.xxx, sunTint, (((clamp(ambient_tone.x, 0.0f, 1.35000002384185791015625f) * daylight) * lerp(1.0f, 0.64999997615814208984375f, inside)) * (1.0f - (0.85000002384185791015625f * fireShare))).xxx);
    float twilight = smoothstep(0.1500000059604644775390625f, 0.519999980926513671875f, nightFactor) * (1.0f - smoothstep(0.62000000476837158203125f, 0.949999988079071044921875f, nightFactor));
    float3 blueHour = float3(0.8899211883544921875f, 1.0011613368988037109375f, 1.3126337528228759765625f);
    float lampShare = dot(totalLamps, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f)) / ((ambient_lamp.w + dot(totalLamps, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f))) + 9.9999997473787516355514526367188e-05f);
    tint = lerp(tint, blueHour, ((((twilight * lerp(1.0f, 0.3499999940395355224609375f, inside)) * ambient_tone.x) * 0.64999997615814208984375f) * (1.0f - lampShare)).xxx);
    float3 moonLit = float3(0.887847900390625f, 1.004113674163818359375f, 1.2894933223724365234375f);
    float3 moonShade = float3(0.857108414173126220703125f, 0.996098995208740234375f, 1.4594008922576904296875f);
    float3 moon = lerp(moonShade, moonLit, lit.xxx);
    tint = lerp(tint, moon, (((nightFactor * lerp(1.0f, 0.3499999940395355224609375f, inside)) * 0.680000007152557373046875f) * (1.0f - lampShare)).xxx);
    light *= tint;
    bool _8375 = nightFactor > 0.0500000007450580596923828125f;
    bool _8381;
    if (_8375)
    {
        _8381 = ambient_sunLot.w > 0.0f;
    }
    else
    {
        _8381 = _8375;
    }
    bool _8387;
    if (_8381)
    {
        _8387 = centre.w > 0.25f;
    }
    else
    {
        _8387 = _8381;
    }
    if (_8387)
    {
        float3 param_50 = here;
        float param_51 = onGround;
        float2 spill = windowSpillInfo(param_50, param_51);
        float3 spillColor = lerp(float3(1.0f, 0.819999992847442626953125f, 0.579999983310699462890625f), float3(1.0f, 0.3400000035762786865234375f, 0.0500000007450580596923828125f), spill.y.xxx);
        light += (spillColor * (((occlusion * 1.0499999523162841796875f) * nightFactor) * spill.x));
    }
    bool _8416 = ambient_weather.x > 0.60000002384185791015625f;
    bool _8423;
    if (!_8416)
    {
        _8423 = ambient_seasonExtra2.z > 0.5f;
    }
    else
    {
        _8423 = _8416;
    }
    bool _8430;
    if (_8423)
    {
        _8430 = ambient_seasonExtra.z < 0.5f;
    }
    else
    {
        _8430 = _8423;
    }
    if (_8430)
    {
        float lSlot = floor(ambient_weather.z / 7.0f);
        float _8442;
        if (ambient_seasonExtra2.z > 0.5f)
        {
            _8442 = 0.550000011920928955078125f;
        }
        else
        {
            _8442 = (ambient_weather.x - 0.60000002384185791015625f) * 1.60000002384185791015625f;
        }
        float lChance = _8442;
        float2 param_52 = float2(lSlot, 3.0f);
        float lStrikes = step(hash12(param_52), lChance);
        float2 param_53 = float2(lSlot, 7.0f);
        float lDt = ((ambient_weather.z - (lSlot * 7.0f)) - 1.0f) - (4.0f * hash12(param_53));
        float _8474;
        if (lDt < 0.0f)
        {
            _8474 = 0.0f;
        }
        else
        {
            float _8484;
            if (lDt < 0.180000007152557373046875f)
            {
                _8484 = 0.0f;
            }
            else
            {
                _8484 = 0.699999988079071044921875f * exp((-(lDt - 0.180000007152557373046875f)) * 9.0f);
            }
            _8474 = exp((-lDt) * 10.0f) + _8484;
        }
        float lFlash = _8474;
        lFlash = clamp(lFlash * lStrikes, 0.0f, 1.0f);
        light += ((float3(0.85000002384185791015625f, 0.949999988079071044921875f, 1.25f) * occlusion) * ((lFlash * 0.75f) * outdoor));
    }
    float _8516;
    if (ambient_season.x > 1.5f)
    {
        _8516 = 0.0f;
    }
    else
    {
        _8516 = ambient_weather.y * outdoor;
    }
    float rawWet = _8516;
    float3 param_54 = here;
    float wet = rawWet * architecturalExposure(param_54);
    float standing = 0.0f;
    if (rawWet > 0.0f)
    {
        bool _8539 = centre.w < 0.25f;
        bool _8545;
        if (_8539)
        {
            _8545 = ambient_sunLot.w > 0.0f;
        }
        else
        {
            _8545 = _8539;
        }
        bool _8557;
        if (_8545)
        {
            float2 param_55 = pixel;
            float3 param_56 = p;
            float3 param_57 = here;
            float3 param_58 = nSurf;
            _8557 = isRainRoofPixel(param_55, param_56, param_57, param_58);
        }
        else
        {
            _8557 = _8545;
        }
        bool onRoof = _8557;
        if (onRoof)
        {
            float3 param_59 = here + float3(0.0f, 0.0f, 0.449999988079071044921875f);
            float roofWet = rawWet * architecturalExposure(param_59);
            float2 param_60 = here.xy;
            float2 source = lotSource(param_60);
            float2 a = mul(source, float2x2(float2(0.800000011920928955078125f, 0.60000002384185791015625f), float2(-0.60000002384185791015625f, 0.800000011920928955078125f)));
            float2 b = mul(source, float2x2(float2(0.2800000011920928955078125f, -0.959999978542327880859375f), float2(0.959999978542327880859375f, 0.2800000011920928955078125f)));
            float2 param_61 = (a / 1.89999997615814208984375f.xx) + 5.30000019073486328125f.xx;
            float2 param_62 = (b / 0.85000002384185791015625f.xx) + 19.700000762939453125f.xx;
            float2 param_63 = float2((source.x * 2.599999904632568359375f) + (here.z * 0.4000000059604644775390625f), (source.y * 2.599999904632568359375f) - (here.z * 0.4000000059604644775390625f));
            float roofField = ((0.550000011920928955078125f * smoothNoise(param_61)) + (0.300000011920928955078125f * smoothNoise(param_62))) + (0.1500000059604644775390625f * smoothNoise(param_63));
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
                float2 param_64 = rid + 11.30000019073486328125f.xx;
                float2 param_65 = rid + 23.700000762939453125f.xx;
                float2 rdrop = (rid + 0.25f.xx) + (float2(hash12(param_64), hash12(param_65)) * 0.5f);
                float2 param_66 = rid + 5.099999904632568359375f.xx;
                float rage = frac((ambient_weather.z * (1.10000002384185791015625f + (0.64999997615814208984375f * ambient_weather.x))) + hash12(param_66));
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
                    float2 param_67 = here.xy;
                    float2 source_1 = lotSource(param_67);
                    float2 a_1 = mul(source_1, float2x2(float2(0.800000011920928955078125f, 0.60000002384185791015625f), float2(-0.60000002384185791015625f, 0.800000011920928955078125f)));
                    float2 b_1 = mul(source_1, float2x2(float2(0.2800000011920928955078125f, -0.959999978542327880859375f), float2(0.959999978542327880859375f, 0.2800000011920928955078125f)));
                    float2 c = mul(source_1, float2x2(float2(-0.60000002384185791015625f, 0.800000011920928955078125f), float2(-0.800000011920928955078125f, -0.60000002384185791015625f)));
                    float2 param_68 = a_1 / 2.400000095367431640625f.xx;
                    float2 param_69 = (b_1 / 1.14999997615814208984375f.xx) + 13.0f.xx;
                    float2 param_70 = (c / 0.550000011920928955078125f.xx) + 29.0f.xx;
                    float field = ((0.519999980926513671875f * smoothNoise(param_68)) + (0.3300000131130218505859375f * smoothNoise(param_69))) + (0.1500000059604644775390625f * smoothNoise(param_70));
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
                    bool _8914 = ambient_weather.x > 0.0f;
                    bool _8922;
                    if (_8914)
                    {
                        _8922 = (pool > 0.0199999995529651641845703125f) || (soaked > 0.3499999940395355224609375f);
                    }
                    else
                    {
                        _8922 = _8914;
                    }
                    if (_8922)
                    {
                        float2 g_1 = source_1 * 3.2000000476837158203125f;
                        float2 id = floor(g_1);
                        float2 param_71 = id;
                        float2 param_72 = id + 7.099999904632568359375f.xx;
                        float2 drop = (id + 0.25f.xx) + (float2(hash12(param_71), hash12(param_72)) * 0.5f);
                        float2 param_73 = id + 3.7000000476837158203125f.xx;
                        float age = frac((ambient_weather.z * (0.85000002384185791015625f + (0.550000011920928955078125f * ambient_weather.x))) + hash12(param_73));
                        float r1 = (1.0f - smoothstep(0.0f, 0.064999997615814208984375f, abs(length(g_1 - drop) - (age * 0.439999997615814208984375f)))) * (1.0f - age);
                        float age2 = frac(age + 0.5f);
                        float r2 = ((1.0f - smoothstep(0.0f, 0.054999999701976776123046875f, abs(length(g_1 - drop) - (age2 * 0.4000000059604644775390625f)))) * (1.0f - age2)) * 0.5f;
                        float rippleMask = clamp((pool * 0.85000002384185791015625f) + ((soaked * fullSheet) * 0.4000000059604644775390625f), 0.0f, 1.0f);
                        light *= (1.0f + (((0.319999992847442626953125f * (r1 + r2)) * rippleMask) * ambient_weather.x));
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
    if (mode > 12.5f)
    {
        float3 param_74 = here;
        float param_75 = onGround;
        float3 param_76 = here;
        color = float4(0.0f, windowSpill(param_74, param_75), lampNear(param_76), 1.0f);
        return;
    }
    if (mode > 11.5f)
    {
        color = float4(sky.xxx, 1.0f);
        return;
    }
    if (mode > 10.5f)
    {
        int2 param_77 = int2(floor(here.xy + ambient_frame.w.xx));
        int param_78 = 0;
        int cellMask = maskAt(param_77, param_78);
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
        uint _9107_dummy_parameter;
        float2 gridSize_1 = float2(int2(spvTextureSize(heightMap, uint(0), _9107_dummy_parameter)));
        float top = (0.5f - heightMap.Sample(_heightMap_sampler, ((here.xy + ambient_frame.w.xx) * ambient_frame.z) / gridSize_1).x) * 64.0f;
        color = float4(clamp(top / 6.0f, 0.0f, 1.0f), frac(top), float(top < (-16.0f)), 1.0f);
        return;
    }
    if (mode > 7.5f)
    {
        float depth = depthMap.Load(int3(int2(pixel), 0)).x;
        float ground = groundMap.Load(int3(int2(pixel), 0)).x;
        float _9158;
        if (depth < 1.0f)
        {
            _9158 = (0.89999997615814208984375f - depth) / 0.0030000000260770320892333984375f;
        }
        else
        {
            _9158 = ((0.89999997615814208984375f - ground) / 0.0030000000260770320892333984375f) + ambient_view.w;
        }
        float key_1 = _9158;
        float2 param_79 = p.xy;
        float param_80 = key_1;
        bool param_81 = depth >= 1.0f;
        float2 param_82 = ambient_frame.xy;
        float3 lot = lotPoint(param_79, param_80, param_81, param_82);
        float2 grid = step(0.89999997615814208984375f.xx, frac(lot.xy));
        color = float4(grid, step(0.5f, frac(lot.z)), 1.0f);
        float4 _9200 = color;
        float3 param_83 = lot;
        float3 _9208 = lerp(_9200.xyz, float3(1.0f, 0.800000011920928955078125f, 0.20000000298023223876953125f), (0.60000002384185791015625f * indoors(param_83)).xxx);
        color.x = _9208.x;
        color.y = _9208.y;
        color.z = _9208.z;
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
        float _9262;
        if ((centre.w < 0.25f) && (ground_1 < 1.0f))
        {
            _9262 = ((0.89999997615814208984375f - depthMap.Load(int3(int2(pixel), 0)).x) - (0.89999997615814208984375f - ground_1)) / 0.0030000000260770320892333984375f;
        }
        else
        {
            _9262 = 0.0f;
        }
        float difference = _9262;
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
