struct SurfaceSample
{
    float3 lot;
    float z;
    float soft;
    int cls;
};

static const int2 _1098[8] = { int2(-1, 1), int2(4, 1), int2(1, -1), int2(1, 4), int2(-1, 2), int2(4, 2), int2(2, -1), int2(2, 4) };
static const int2 _1464[8] = { int2(2, 0), int2(-2, 0), int2(0, 2), int2(0, -2), int2(2, 2), int2(-2, 2), int2(2, -2), int2(-2, -2) };

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

Texture2D<float4> depthMap : register(t1, space2);
SamplerState _depthMap_sampler : register(s1, space2);
Texture2D<float4> groundMap : register(t2, space2);
SamplerState _groundMap_sampler : register(s2, space2);
Texture2D<float4> liftMap : register(t3, space2);
SamplerState _liftMap_sampler : register(s3, space2);
Texture2D<float4> simMaskMap : register(t4, space2);
SamplerState _simMaskMap_sampler : register(s4, space2);
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

float3 lotPoint(float2 scene, float key, bool terrain, float2 frame)
{
    float2 local = scene - frame;
    float _69;
    if (terrain)
    {
        _69 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _69 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _69;
    float _93;
    if (terrain)
    {
        _93 = key;
    }
    else
    {
        _93 = key - (0.800000011920928955078125f * h);
    }
    float s = _93;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

SurfaceSample surfaceSampleAt(int2 pixel, bool hasLift, bool hasSimMask)
{
    SurfaceSample s;
    s.lot = 0.0f.xxx;
    s.z = -100000.0f;
    s.soft = 0.0f;
    s.cls = -1;
    float depth = depthMap.Load(int3(pixel, 0)).x;
    bool terrain = depth >= 1.0f;
    if (terrain)
    {
        depth = groundMap.Load(int3(pixel, 0)).x;
    }
    if (depth >= 1.0f)
    {
        return s;
    }
    float scale = max(ambient_view.z, 0.25f);
    float2 scene = ((float2(pixel) + 0.5f.xx) - ambient_view.xy) / scale.xx;
    float _209;
    if (terrain)
    {
        _209 = ambient_view.w;
    }
    else
    {
        _209 = 0.0f;
    }
    float key = ((0.62000000476837158203125f - depth) / 0.0030000000260770320892333984375f) + _209;
    float2 param = scene;
    float param_1 = key;
    bool param_2 = terrain;
    float2 param_3 = ambient_frame.xy;
    float3 surface = lotPoint(param, param_1, param_2, param_3);
    int cls = int(terrain);
    if (hasLift)
    {
        float4 lift = liftMap.Load(int3(pixel, 0));
        if (lift.z > 0.5f)
        {
            surface += float3(0.5f * lift.x, 0.5f * lift.x, lift.y);
            key = (surface.x + surface.y) + (0.800000011920928955078125f * surface.z);
            cls = 2;
        }
        else
        {
            bool _271 = !terrain;
            bool _278;
            if (_271)
            {
                _278 = lift.z < (-0.00200000009499490261077880859375f);
            }
            else
            {
                _278 = _271;
            }
            if (_278)
            {
                s.soft = clamp(-lift.z, 0.0f, 1.0f);
            }
        }
    }
    else
    {
        if (terrain)
        {
            key = (surface.x + surface.y) + (0.800000011920928955078125f * surface.z);
        }
    }
    if ((cls == 0) && hasSimMask)
    {
        s.soft = max(s.soft, simMaskMap.Load(int3(pixel, 0)).x * 0.64999997615814208984375f);
    }
    s.lot = surface;
    s.z = key * 27.7128124237060546875f;
    s.cls = cls;
    return s;
}

float ignBlur(float2 pixel)
{
    return frac(52.98291778564453125f * frac(dot(pixel, float2(0.067110560834407806396484375f, 0.005837149918079376220703125f))));
}

float3 ditherOut(float3 c, int2 pixel, int cls)
{
    if (cls == 2)
    {
        return c;
    }
    float2 cell = float2(pixel);
    float2 param = cell + float2(5.0f, 13.0f);
    float2 param_1 = cell + float2(29.0f, 47.0f);
    float tri = (ignBlur(param) + ignBlur(param_1)) - 1.0f;
    float3 stepLin = lerp(0.000303526991046965122222900390625f.xxx, (pow(max(c, 0.003130800090730190277099609375f.xxx), 0.545000016689300537109375f.xxx) * 2.2000000476837158203125f) / 255.0f.xxx, step(0.003130800090730190277099609375f.xxx, c));
    return clamp(c + (stepLin * (tri * 0.2199999988079071044921875f)), 0.0f.xxx, 1.0f.xxx);
}

bool reconstructPlane(SurfaceSample c, SurfaceSample l, SurfaceSample r, SurfaceSample u, SurfaceSample d, float scale, out float3 outN)
{
    outN = float3(0.0f, 0.0f, 1.0f);
    float maxStep = (0.2800000011920928955078125f / max(scale, 0.3499999940395355224609375f)) + 0.07999999821186065673828125f;
    bool _342 = l.cls == c.cls;
    bool _353;
    if (_342)
    {
        _353 = length(c.lot - l.lot) < maxStep;
    }
    else
    {
        _353 = _342;
    }
    bool lOk = _353;
    bool _359 = r.cls == c.cls;
    bool _370;
    if (_359)
    {
        _370 = length(r.lot - c.lot) < maxStep;
    }
    else
    {
        _370 = _359;
    }
    bool rOk = _370;
    bool _376 = u.cls == c.cls;
    bool _387;
    if (_376)
    {
        _387 = length(c.lot - u.lot) < maxStep;
    }
    else
    {
        _387 = _376;
    }
    bool uOk = _387;
    bool _393 = d.cls == c.cls;
    bool _404;
    if (_393)
    {
        _404 = length(d.lot - c.lot) < maxStep;
    }
    else
    {
        _404 = _393;
    }
    bool dOk = _404;
    if (!(((lOk && rOk) && uOk) && dOk))
    {
        return false;
    }
    float curvX = length((r.lot - c.lot) - (c.lot - l.lot));
    float curvY = length((d.lot - c.lot) - (c.lot - u.lot));
    if (max(curvX, curvY) > 0.054999999701976776123046875f)
    {
        return false;
    }
    float3 cr = cross(r.lot - l.lot, d.lot - u.lot);
    float crLen = length(cr);
    if (crLen <= 9.9999999747524270787835121154785e-07f)
    {
        return false;
    }
    outN = cr / crLen.xxx;
    return true;
}

float effectiveDepthDelta(SurfaceSample here, SurfaceSample tap, bool isPlanar, float3 nLot, float2 deltaPx, float scale, float localTol)
{
    float rawDz = abs(tap.z - here.z);
    float minSoft = min(here.soft, tap.soft);
    bool _500;
    if (isPlanar)
    {
        _500 = tap.cls == here.cls;
    }
    else
    {
        _500 = isPlanar;
    }
    if (_500)
    {
        float planeDist = abs(dot(nLot, tap.lot - here.lot));
        float maxInPlane = (length(deltaPx) / (13.5f * max(scale, 0.25f))) + 0.119999997317790985107421875f;
        float excess3D = max(0.0f, length(tap.lot - here.lot) - maxInPlane);
        return ((planeDist * 2.150000095367431640625f) + (excess3D * 1.85000002384185791015625f)) * 27.7128124237060546875f;
    }
    bool _544 = here.cls >= 1;
    bool _550;
    if (_544)
    {
        _550 = tap.cls >= 1;
    }
    else
    {
        _550 = _544;
    }
    bool snowVsTerrain = _550;
    float _560;
    if ((tap.cls != here.cls) && (!snowVsTerrain))
    {
        _560 = (1.5499999523162841796875f * localTol) * (1.0f - smoothstep(0.100000001490116119384765625f, 0.550000011920928955078125f, minSoft));
    }
    else
    {
        _560 = 0.0f;
    }
    float clsPenalty = _560;
    return rawDz + clsPenalty;
}

void frag_main()
{
    int2 pixel = int2(gl_FragCoord.xy);
    int2 limit = int2(ambient_extent.xy) - int2(1, 1);
    if (any(bool2(pixel.x > limit.x, pixel.y > limit.y)))
    {
        color = 0.5f.xxxx;
        return;
    }
    uint _662_dummy_parameter;
    bool hasLift = int2(spvTextureSize(liftMap, uint(0), _662_dummy_parameter)).x > 1;
    uint _668_dummy_parameter;
    bool hasSimMask = int2(spvTextureSize(simMaskMap, uint(0), _668_dummy_parameter)).x > 1;
    int2 param = pixel;
    bool param_1 = hasLift;
    bool param_2 = hasSimMask;
    SurfaceSample here = surfaceSampleAt(param, param_1, param_2);
    if (here.cls < 0)
    {
        color = float4(0.5f, 0.5f, 0.5f, 1.0f);
        return;
    }
    float scale = max(ambient_view.z, 0.25f);
    float tolerance = lerp(3.2000000476837158203125f, 8.5f, clamp((1.5f - ambient_view.z) / 1.0f, 0.0f, 1.0f));
    float _704;
    if (ambient_extent.w > 0.5f)
    {
        _704 = ambient_extent.w;
    }
    else
    {
        _704 = 1.0f;
    }
    float ambScale = _704;
    float3 total = 0.0f.xxx;
    float weight = 0.0f;
    if (ambScale > 1.5f)
    {
        uint _721_dummy_parameter;
        int2 ambLimit = int2(spvTextureSize(ambientMap, uint(0), _721_dummy_parameter)) - int2(1, 1);
        float2 pCenter = float2(pixel) + 0.5f.xx;
        float2 ambCoord = (pCenter - (floor(0.5f * ambScale) + 0.5f).xx) / ambScale.xx;
        int2 baseAmb = int2(floor(ambCoord)) - int2(1, 1);
        float3 minC = 2.0f.xxx;
        float3 maxC = (-1.0f).xxx;
        int idx = 0;
        float3 cTap[16];
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                int2 ambTap = clamp(baseAmb + int2(x, y), int2(0, 0), ambLimit);
                float3 v = ambientMap.Load(int3(ambTap, 0)).xyz;
                int _788 = idx;
                idx = _788 + 1;
                cTap[_788] = v;
                minC = min(minC, v);
                maxC = max(maxC, v);
            }
        }
        float3 span = maxC - minC;
        if (max(span.x, max(span.y, span.z)) <= 0.0005000000237487256526947021484375f)
        {
            float3 param_3 = cTap[5];
            int2 param_4 = pixel;
            int param_5 = here.cls;
            color = float4(ditherOut(param_3, param_4, param_5), 1.0f);
            return;
        }
        int2 param_6 = clamp(pixel + int2(-1, 0), int2(0, 0), limit);
        bool param_7 = hasLift;
        bool param_8 = hasSimMask;
        SurfaceSample sL = surfaceSampleAt(param_6, param_7, param_8);
        int2 param_9 = clamp(pixel + int2(1, 0), int2(0, 0), limit);
        bool param_10 = hasLift;
        bool param_11 = hasSimMask;
        SurfaceSample sR = surfaceSampleAt(param_9, param_10, param_11);
        int2 param_12 = clamp(pixel + int2(0, -1), int2(0, 0), limit);
        bool param_13 = hasLift;
        bool param_14 = hasSimMask;
        SurfaceSample sU = surfaceSampleAt(param_12, param_13, param_14);
        int2 param_15 = clamp(pixel + int2(0, 1), int2(0, 0), limit);
        bool param_16 = hasLift;
        bool param_17 = hasSimMask;
        SurfaceSample sD = surfaceSampleAt(param_15, param_16, param_17);
        SurfaceSample param_18 = here;
        SurfaceSample param_19 = sL;
        SurfaceSample param_20 = sR;
        SurfaceSample param_21 = sU;
        SurfaceSample param_22 = sD;
        float param_23 = scale;
        float3 param_24;
        bool _896 = reconstructPlane(param_18, param_19, param_20, param_21, param_22, param_23, param_24);
        float3 nLot = param_24;
        bool isPlanar = _896;
        float rMax = 1.96000003814697265625f * ambScale;
        float bestDz = 1000000000.0f;
        float maxTapZ = -1000000000.0f;
        float bestLuma = -1.0f;
        float3 bestColor = 0.5f.xxx;
        float3 brightColor = cTap[5];
        idx = 0;
        for (int y_1 = 0; y_1 < 4; y_1++)
        {
            for (int x_1 = 0; x_1 < 4; x_1++)
            {
                int2 ambTap_1 = clamp(baseAmb + int2(x_1, y_1), int2(0, 0), ambLimit);
                int2 fullTap = clamp(int2(floor((float2(ambTap_1) + 0.5f.xx) * ambScale)), int2(0, 0), limit);
                float2 fullCenter = float2(fullTap) + 0.5f.xx;
                float2 delta = fullCenter - pCenter;
                int _957 = idx;
                idx = _957 + 1;
                float3 tapCol = cTap[_957];
                float uDist = clamp(1.0f - (length(delta) / rMax), 0.0f, 1.0f);
                if (uDist <= 0.0f)
                {
                    continue;
                }
                int2 param_25 = fullTap;
                bool param_26 = hasLift;
                bool param_27 = hasSimMask;
                SurfaceSample tap = surfaceSampleAt(param_25, param_26, param_27);
                if (tap.cls < 0)
                {
                    continue;
                }
                float localTol = tolerance + (22.0f * smoothstep(0.100000001490116119384765625f, 0.64999997615814208984375f, min(here.soft, tap.soft)));
                SurfaceSample param_28 = here;
                SurfaceSample param_29 = tap;
                bool param_30 = isPlanar;
                float3 param_31 = nLot;
                float2 param_32 = delta;
                float param_33 = scale;
                float param_34 = localTol;
                float dz = effectiveDepthDelta(param_28, param_29, param_30, param_31, param_32, param_33, param_34);
                maxTapZ = max(maxTapZ, tap.z);
                float lum = dot(tapCol, float3(0.2125999927520751953125f, 0.715200006961822509765625f, 0.072200000286102294921875f));
                if (lum > bestLuma)
                {
                    bestLuma = lum;
                    brightColor = tapCol;
                }
                if (dz < bestDz)
                {
                    bestDz = dz;
                    bestColor = tapCol;
                }
                float spatialW = (uDist * uDist) * (3.0f - (2.0f * uDist));
                float w = exp((-dz) / localTol) * spatialW;
                total += (tapCol * w);
                weight += w;
            }
        }
        if (weight < 0.0500000007450580596923828125f)
        {
            float rOuter = 2.849999904632568359375f * ambScale;
            for (int i = 0; i < 8; i++)
            {
                int2 ambTap_2 = clamp(baseAmb + _1098[i], int2(0, 0), ambLimit);
                int2 fullTap_1 = clamp(int2(floor((float2(ambTap_2) + 0.5f.xx) * ambScale)), int2(0, 0), limit);
                float2 fullCenter_1 = float2(fullTap_1) + 0.5f.xx;
                float2 delta_1 = fullCenter_1 - pCenter;
                float uDist_1 = clamp(1.0f - (length(delta_1) / rOuter), 0.0f, 1.0f);
                if (uDist_1 <= 0.0f)
                {
                    continue;
                }
                int2 param_35 = fullTap_1;
                bool param_36 = hasLift;
                bool param_37 = hasSimMask;
                SurfaceSample tap_1 = surfaceSampleAt(param_35, param_36, param_37);
                if (tap_1.cls < 0)
                {
                    continue;
                }
                float localTol_1 = tolerance + (22.0f * smoothstep(0.100000001490116119384765625f, 0.64999997615814208984375f, min(here.soft, tap_1.soft)));
                SurfaceSample param_38 = here;
                SurfaceSample param_39 = tap_1;
                bool param_40 = isPlanar;
                float3 param_41 = nLot;
                float2 param_42 = delta_1;
                float param_43 = scale;
                float param_44 = localTol_1;
                float dz_1 = effectiveDepthDelta(param_38, param_39, param_40, param_41, param_42, param_43, param_44);
                float3 tapCol_1 = ambientMap.Load(int3(ambTap_2, 0)).xyz;
                maxTapZ = max(maxTapZ, tap_1.z);
                if (dz_1 < bestDz)
                {
                    bestDz = dz_1;
                    bestColor = tapCol_1;
                }
                float w_1 = exp((-dz_1) / localTol_1) * ((uDist_1 * uDist_1) * (3.0f - (2.0f * uDist_1)));
                total += (tapCol_1 * w_1);
                weight += w_1;
            }
        }
        bool3 _1232 = ((here.z - maxTapZ) > (2.5f * tolerance)).xxx;
        float3 fallbackCol = float3(_1232.x ? brightColor.x : bestColor.x, _1232.y ? brightColor.y : bestColor.y, _1232.z ? brightColor.z : bestColor.z);
        float3 _1238;
        if (weight > 9.9999997473787516355514526367188e-05f)
        {
            _1238 = total / weight.xxx;
        }
        else
        {
            _1238 = fallbackCol;
        }
        float3 resolved = _1238;
        float3 param_45 = resolved;
        int2 param_46 = pixel;
        int param_47 = here.cls;
        color = float4(ditherOut(param_45, param_46, param_47), 1.0f);
        return;
    }
    int gIdx = 0;
    SurfaceSample grid[9];
    SurfaceSample _1289;
    for (int y_2 = -1; y_2 <= 1; y_2++)
    {
        for (int x_2 = -1; x_2 <= 1; x_2++)
        {
            int _1282 = gIdx;
            gIdx = _1282 + 1;
            if ((x_2 == 0) && (y_2 == 0))
            {
                _1289 = here;
            }
            else
            {
                int2 param_48 = clamp(pixel + int2(x_2, y_2), int2(0, 0), limit);
                bool param_49 = hasLift;
                bool param_50 = hasSimMask;
                _1289 = surfaceSampleAt(param_48, param_49, param_50);
            }
            grid[_1282] = _1289;
        }
    }
    SurfaceSample param_51 = here;
    SurfaceSample param_52 = grid[3];
    SurfaceSample param_53 = grid[5];
    SurfaceSample param_54 = grid[1];
    SurfaceSample param_55 = grid[7];
    float param_56 = scale;
    float3 param_57;
    bool _1333 = reconstructPlane(param_51, param_52, param_53, param_54, param_55, param_56, param_57);
    float3 nLot_1 = param_57;
    bool isPlanar_1 = _1333;
    gIdx = 0;
    for (int y_3 = -1; y_3 <= 1; y_3++)
    {
        for (int x_3 = -1; x_3 <= 1; x_3++)
        {
            int2 tapPx = clamp(pixel + int2(x_3, y_3), int2(0, 0), limit);
            int _1360 = gIdx;
            gIdx = _1360 + 1;
            SurfaceSample tap_2 = grid[_1360];
            if (tap_2.cls < 0)
            {
                continue;
            }
            float localTol_2 = tolerance + (22.0f * smoothstep(0.100000001490116119384765625f, 0.64999997615814208984375f, min(here.soft, tap_2.soft)));
            SurfaceSample param_58 = here;
            SurfaceSample param_59 = tap_2;
            bool param_60 = isPlanar_1;
            float3 param_61 = nLot_1;
            float2 param_62 = float2(float(x_3), float(y_3));
            float param_63 = scale;
            float param_64 = localTol_2;
            float dz_2 = effectiveDepthDelta(param_58, param_59, param_60, param_61, param_62, param_63, param_64);
            float w_2 = exp((-dz_2) / localTol_2) * exp((-float((x_3 * x_3) + (y_3 * y_3))) / 2.599999904632568359375f);
            total += (ambientMap.Load(int3(tapPx, 0)).xyz * w_2);
            weight += w_2;
        }
    }
    float outerFade = smoothstep(1.14999997615814208984375f, 1.64999997615814208984375f, ambient_view.z);
    if (outerFade > 0.001000000047497451305389404296875f)
    {
        for (int i_1 = 0; i_1 < 8; i_1++)
        {
            float d2 = float((_1464[i_1].x * _1464[i_1].x) + (_1464[i_1].y * _1464[i_1].y));
            float outerSpatial = outerFade * exp((-d2) / 3.400000095367431640625f);
            int2 tapPx_1 = clamp(pixel + _1464[i_1], int2(0, 0), limit);
            int2 param_65 = tapPx_1;
            bool param_66 = hasLift;
            bool param_67 = hasSimMask;
            SurfaceSample tap_3 = surfaceSampleAt(param_65, param_66, param_67);
            if (tap_3.cls < 0)
            {
                continue;
            }
            float localTol_3 = tolerance + (22.0f * smoothstep(0.100000001490116119384765625f, 0.64999997615814208984375f, min(here.soft, tap_3.soft)));
            SurfaceSample param_68 = here;
            SurfaceSample param_69 = tap_3;
            bool param_70 = isPlanar_1;
            float3 param_71 = nLot_1;
            float2 param_72 = float2(_1464[i_1]);
            float param_73 = scale;
            float param_74 = localTol_3;
            float dz_3 = effectiveDepthDelta(param_68, param_69, param_70, param_71, param_72, param_73, param_74);
            float w_3 = exp((-dz_3) / localTol_3) * outerSpatial;
            total += (ambientMap.Load(int3(tapPx_1, 0)).xyz * w_3);
            weight += w_3;
        }
    }
    float3 _1571;
    if (weight > 9.9999997473787516355514526367188e-05f)
    {
        _1571 = total / weight.xxx;
    }
    else
    {
        _1571 = ambientMap.Load(int3(pixel, 0)).xyz;
    }
    float3 outCol = _1571;
    float3 param_75 = outCol;
    int2 param_76 = pixel;
    int param_77 = here.cls;
    color = float4(ditherOut(param_75, param_76, param_77), 1.0f);
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
