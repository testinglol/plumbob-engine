Texture2D<float4> art : register(t0, space2);
SamplerState _art_sampler : register(s0, space2);
Texture2D<float4> depthMap : register(t1, space2);
SamplerState _depthMap_sampler : register(s1, space2);

static float gl_FragDepth;
static float2 inUV;
static float4 inDepthInterval;
static float4 color;
static float4 inTint;

struct SPIRV_Cross_Input
{
    float2 inUV : TEXCOORD0;
    nointerpolation float4 inTint : TEXCOORD1;
    nointerpolation float4 inDepthInterval : TEXCOORD2;
};

struct SPIRV_Cross_Output
{
    float4 color : SV_Target0;
    float gl_FragDepth : SV_Depth;
};

uint2 spvTextureSize(Texture2D<float4> Tex, uint Level, out uint Param)
{
    uint2 ret;
    Tex.GetDimensions(Level, ret.x, ret.y, Param);
    return ret;
}

float4 fetchArt(int2 dims, int2 c)
{
    return art.Load(int3(clamp(c, int2(0, 0), dims - int2(1, 1)), 0));
}

float semiTap(float a)
{
    return float((a > 0.02999999932944774627685546875f) && (a < 0.949999988079071044921875f));
}

float colorDist(float4 a, float4 b)
{
    float3 pa = sqrt(max(a.xyz, 0.0f.xxx));
    float3 pb = sqrt(max(b.xyz, 0.0f.xxx));
    float3 d = pa - pb;
    float da = a.w - b.w;
    return sqrt((dot(d, d) * 0.64999997615814208984375f) + ((da * da) * 1.35000002384185791015625f));
}

bool shouldBevelCorner(float4 K, float4 A, float4 B, float4 O, int2 dims, int2 i0, int2 s1Off, int2 s2Off)
{
    float4 M = (A + B) * 0.5f;
    float4 param = A;
    float4 param_1 = B;
    float dAB = colorDist(param, param_1);
    float4 param_2 = K;
    float4 param_3 = A;
    float dKA = colorDist(param_2, param_3);
    float4 param_4 = K;
    float4 param_5 = B;
    float dKB = colorDist(param_4, param_5);
    float minDK = min(dKA, dKB);
    bool _155 = dAB >= 0.2199999988079071044921875f;
    bool _164;
    if (!_155)
    {
        _164 = (dAB * 2.0f) >= minDK;
    }
    else
    {
        _164 = _155;
    }
    if (_164 || (minDK <= 0.07999999821186065673828125f))
    {
        return false;
    }
    float4 param_6 = O;
    float4 param_7 = M;
    float dOM = colorDist(param_6, param_7);
    float4 param_8 = K;
    float4 param_9 = M;
    float dKM = colorDist(param_8, param_9);
    if (dOM < (dKM * 0.64999997615814208984375f))
    {
        return true;
    }
    bool _199 = M.w > (K.w + 0.25f);
    bool _208;
    if (_199)
    {
        _208 = O.w < (M.w - 0.25f);
    }
    else
    {
        _208 = _199;
    }
    if (_208)
    {
        return true;
    }
    if (dOM < 0.2199999988079071044921875f)
    {
        int2 param_10 = dims;
        int2 param_11 = i0 + s1Off;
        float4 S1 = fetchArt(param_10, param_11);
        int2 param_12 = dims;
        int2 param_13 = i0 + s2Off;
        float4 S2 = fetchArt(param_12, param_13);
        float4 param_14 = K;
        float4 param_15 = S1;
        float4 param_16 = K;
        float4 param_17 = S2;
        float dKS = min(colorDist(param_14, param_15), colorDist(param_16, param_17));
        bool _246 = dKS < 0.23999999463558197021484375f;
        bool _254;
        if (_246)
        {
            _254 = (dKS * 1.7999999523162841796875f) < minDK;
        }
        else
        {
            _254 = _246;
        }
        return _254;
    }
    return false;
}

float fetchDepth(int2 dims, int2 c)
{
    return depthMap.Load(int3(clamp(c, int2(0, 0), dims - int2(1, 1)), 0)).x;
}

void frag_main()
{
    uint _261_dummy_parameter;
    int2 artDims = int2(spvTextureSize(art, uint(0), _261_dummy_parameter));
    uint _265_dummy_parameter;
    int2 depthDims = int2(spvTextureSize(depthMap, uint(0), _265_dummy_parameter));
    float2 texSize = float2(artDims);
    float2 halfTexel = 0.5f.xx / texSize;
    float2 clampedUV = clamp(inUV, halfTexel, 1.0f.xx - halfTexel);
    float2 texel = clampedUV * texSize;
    float2 fw = max(fwidth(texel), 9.9999997473787516355514526367188e-05f.xx);
    if (inDepthInterval.w < 0.5f)
    {
        int2 nearest = clamp(int2(clamp(inUV, 0.0f.xx, 1.0f.xx) * texSize), int2(0, 0), artDims - int2(1, 1));
        float4 raw = art.Load(int3(nearest, 0));
        int2 depthCoord = clamp(int2(clamp(inUV, 0.0f.xx, 1.0f.xx) * float2(depthDims)), int2(0, 0), depthDims - int2(1, 1));
        float d = depthMap.Load(int3(depthCoord, 0)).x;
        if (d >= 1.0f)
        {
            discard;
        }
        if (inDepthInterval.w < (-0.5f))
        {
            bool _354 = raw.w >= inDepthInterval.z;
            bool _362;
            if (!_354)
            {
                _362 = raw.w < 0.0039215688593685626983642578125f;
            }
            else
            {
                _362 = _354;
            }
            if (_362)
            {
                discard;
            }
            float stepBias = max(1.9999999949504854157567024230957e-06f, (0.25f * abs(inDepthInterval.y - inDepthInterval.x)) / 254.0f);
            color = raw * inTint;
            gl_FragDepth = max(0.0f, lerp(inDepthInterval.x, inDepthInterval.y, (d * 255.0f) / 254.0f) - stepBias);
            return;
        }
        if (raw.w < inDepthInterval.z)
        {
            discard;
        }
        float _409 = raw.w;
        float4 _411 = raw;
        float3 _414 = _411.xyz / max(_409, 9.9999997473787516355514526367188e-05f).xxx;
        raw.x = _414.x;
        raw.y = _414.y;
        raw.z = _414.z;
        raw.w = 1.0f;
        color = raw * inTint;
        gl_FragDepth = lerp(inDepthInterval.x, inDepthInterval.y, (d * 255.0f) / 254.0f);
        return;
    }
    float2 p = texel - 0.5f.xx;
    int2 i0 = int2(floor(p));
    float2 f = p - float2(i0);
    bool minified = max(fw.x, fw.y) > 1.0499999523162841796875f;
    float4 c00 = 0.0f.xxxx;
    float4 c10 = 0.0f.xxxx;
    float4 c01 = 0.0f.xxxx;
    float4 c11 = 0.0f.xxxx;
    float4 sampled;
    float maxTapA;
    if (minified)
    {
        sampled = art.Sample(_art_sampler, clampedUV);
        if (sampled.w < 0.0039215688593685626983642578125f)
        {
            discard;
        }
        maxTapA = sampled.w;
        int2 param = artDims;
        int2 param_1 = i0;
        c00 = fetchArt(param, param_1);
        int2 param_2 = artDims;
        int2 param_3 = i0 + int2(1, 0);
        c10 = fetchArt(param_2, param_3);
        int2 param_4 = artDims;
        int2 param_5 = i0 + int2(0, 1);
        c01 = fetchArt(param_4, param_5);
        int2 param_6 = artDims;
        int2 param_7 = i0 + int2(1, 1);
        c11 = fetchArt(param_6, param_7);
    }
    else
    {
        int2 param_8 = artDims;
        int2 param_9 = i0;
        c00 = fetchArt(param_8, param_9);
        int2 param_10 = artDims;
        int2 param_11 = i0 + int2(1, 0);
        c10 = fetchArt(param_10, param_11);
        int2 param_12 = artDims;
        int2 param_13 = i0 + int2(0, 1);
        c01 = fetchArt(param_12, param_13);
        int2 param_14 = artDims;
        int2 param_15 = i0 + int2(1, 1);
        c11 = fetchArt(param_14, param_15);
        maxTapA = max(max(c00.w, c10.w), max(c01.w, c11.w));
        if (maxTapA < 0.0039215688593685626983642578125f)
        {
            discard;
        }
        float param_16 = c00.w;
        float param_17 = c10.w;
        float param_18 = c01.w;
        float param_19 = c11.w;
        float semiX = lerp(max(semiTap(param_16), semiTap(param_17)), max(semiTap(param_18), semiTap(param_19)), f.y);
        float param_20 = c00.w;
        float param_21 = c01.w;
        float param_22 = c10.w;
        float param_23 = c11.w;
        float semiY = lerp(max(semiTap(param_20), semiTap(param_21)), max(semiTap(param_22), semiTap(param_23)), f.x);
        float2 baseFw = min(fw, 1.0f.xx);
        float2 effFw = float2(lerp(baseFw.x, max(baseFw.x, 0.85000002384185791015625f), semiX), lerp(baseFw.y, max(baseFw.y, 0.85000002384185791015625f), semiY));
        float2 ws = clamp(((f - 0.5f.xx) / effFw) + 0.5f.xx, 0.0f.xx, 1.0f.xx);
        ws = (ws * ws) * (3.0f.xx - (ws * 2.0f));
        float w00 = (1.0f - ws.x) * (1.0f - ws.y);
        float w10 = ws.x * (1.0f - ws.y);
        float w01 = (1.0f - ws.x) * ws.y;
        float w11 = ws.x * ws.y;
        float aaWidth = clamp(0.5f * max(effFw.x, effFw.y), 0.0599999986588954925537109375f, 0.5f);
        if ((f.x + f.y) < (0.5f + aaWidth))
        {
            float4 param_24 = c00;
            float4 param_25 = c10;
            float4 param_26 = c01;
            float4 param_27 = c11;
            int2 param_28 = artDims;
            int2 param_29 = i0;
            int2 param_30 = int2(-1, 1);
            int2 param_31 = int2(1, -1);
            if (shouldBevelCorner(param_24, param_25, param_26, param_27, param_28, param_29, param_30, param_31))
            {
                float bevel = 1.0f - smoothstep(0.5f - aaWidth, 0.5f + aaWidth, f.x + f.y);
                float cut = max(0.0f, w00 - bevel);
                w00 -= cut;
                w10 += (0.5f * cut);
                w01 += (0.5f * cut);
            }
        }
        else
        {
            if (((1.0f - f.x) + (1.0f - f.y)) < (0.5f + aaWidth))
            {
                float4 param_32 = c11;
                float4 param_33 = c10;
                float4 param_34 = c01;
                float4 param_35 = c00;
                int2 param_36 = artDims;
                int2 param_37 = i0;
                int2 param_38 = int2(2, 0);
                int2 param_39 = int2(0, 2);
                if (shouldBevelCorner(param_32, param_33, param_34, param_35, param_36, param_37, param_38, param_39))
                {
                    float bevel_1 = 1.0f - smoothstep(0.5f - aaWidth, 0.5f + aaWidth, (1.0f - f.x) + (1.0f - f.y));
                    float cut_1 = max(0.0f, w11 - bevel_1);
                    w11 -= cut_1;
                    w10 += (0.5f * cut_1);
                    w01 += (0.5f * cut_1);
                }
            }
            else
            {
                if (((1.0f - f.x) + f.y) < (0.5f + aaWidth))
                {
                    float4 param_40 = c10;
                    float4 param_41 = c00;
                    float4 param_42 = c11;
                    float4 param_43 = c01;
                    int2 param_44 = artDims;
                    int2 param_45 = i0;
                    int2 param_46 = int2(2, 1);
                    int2 param_47 = int2(0, -1);
                    if (shouldBevelCorner(param_40, param_41, param_42, param_43, param_44, param_45, param_46, param_47))
                    {
                        float bevel_2 = 1.0f - smoothstep(0.5f - aaWidth, 0.5f + aaWidth, (1.0f - f.x) + f.y);
                        float cut_2 = max(0.0f, w10 - bevel_2);
                        w10 -= cut_2;
                        w00 += (0.5f * cut_2);
                        w11 += (0.5f * cut_2);
                    }
                }
                else
                {
                    if ((f.x + (1.0f - f.y)) < (0.5f + aaWidth))
                    {
                        float4 param_48 = c01;
                        float4 param_49 = c00;
                        float4 param_50 = c11;
                        float4 param_51 = c10;
                        int2 param_52 = artDims;
                        int2 param_53 = i0;
                        int2 param_54 = int2(-1, 0);
                        int2 param_55 = int2(1, 2);
                        if (shouldBevelCorner(param_48, param_49, param_50, param_51, param_52, param_53, param_54, param_55))
                        {
                            float bevel_3 = 1.0f - smoothstep(0.5f - aaWidth, 0.5f + aaWidth, f.x + (1.0f - f.y));
                            float cut_3 = max(0.0f, w01 - bevel_3);
                            w01 -= cut_3;
                            w00 += (0.5f * cut_3);
                            w11 += (0.5f * cut_3);
                        }
                    }
                }
            }
        }
        sampled = (((c00 * w00) + (c10 * w10)) + (c01 * w01)) + (c11 * w11);
    }
    bool _930;
    if (!minified)
    {
        _930 = maxTapA >= inDepthInterval.z;
    }
    else
    {
        _930 = minified;
    }
    float _931;
    if (_930)
    {
        _931 = min(inDepthInterval.z, 0.4900000095367431640625f);
    }
    else
    {
        _931 = inDepthInterval.z;
    }
    float coreCutoff = _931;
    bool isEdgePass = inDepthInterval.w > 1.5f;
    if (isEdgePass)
    {
        bool _953 = sampled.w >= coreCutoff;
        bool _960;
        if (!_953)
        {
            _960 = sampled.w < 0.0039215688593685626983642578125f;
        }
        else
        {
            _960 = _953;
        }
        if (_960)
        {
            discard;
        }
    }
    else
    {
        if (sampled.w < coreCutoff)
        {
            discard;
        }
        sampled = float4(sampled.xyz / max(sampled.w, 9.9999997473787516355514526367188e-05f).xxx, 1.0f);
    }
    int2 param_56 = depthDims;
    int2 param_57 = i0;
    float d00 = fetchDepth(param_56, param_57);
    int2 param_58 = depthDims;
    int2 param_59 = i0 + int2(1, 0);
    float d10 = fetchDepth(param_58, param_59);
    int2 param_60 = depthDims;
    int2 param_61 = i0 + int2(0, 1);
    float d01 = fetchDepth(param_60, param_61);
    int2 param_62 = depthDims;
    int2 param_63 = i0 + int2(1, 1);
    float d11 = fetchDepth(param_62, param_63);
    float minValidD = 2.0f;
    float maxValidD = -1.0f;
    float minCoreD = 2.0f;
    bool _1015 = d00 < 1.0f;
    bool _1021;
    if (_1015)
    {
        _1021 = c00.w > 0.0f;
    }
    else
    {
        _1021 = _1015;
    }
    if (_1021)
    {
        minValidD = min(minValidD, d00);
        maxValidD = max(maxValidD, d00);
        if (c00.w >= 0.5f)
        {
            minCoreD = min(minCoreD, d00);
        }
    }
    bool _1039 = d10 < 1.0f;
    bool _1045;
    if (_1039)
    {
        _1045 = c10.w > 0.0f;
    }
    else
    {
        _1045 = _1039;
    }
    if (_1045)
    {
        minValidD = min(minValidD, d10);
        maxValidD = max(maxValidD, d10);
        if (c10.w >= 0.5f)
        {
            minCoreD = min(minCoreD, d10);
        }
    }
    bool _1063 = d01 < 1.0f;
    bool _1069;
    if (_1063)
    {
        _1069 = c01.w > 0.0f;
    }
    else
    {
        _1069 = _1063;
    }
    if (_1069)
    {
        minValidD = min(minValidD, d01);
        maxValidD = max(maxValidD, d01);
        if (c01.w >= 0.5f)
        {
            minCoreD = min(minCoreD, d01);
        }
    }
    bool _1087 = d11 < 1.0f;
    bool _1093;
    if (_1087)
    {
        _1093 = c11.w > 0.0f;
    }
    else
    {
        _1093 = _1087;
    }
    if (_1093)
    {
        minValidD = min(minValidD, d11);
        maxValidD = max(maxValidD, d11);
        if (c11.w >= 0.5f)
        {
            minCoreD = min(minCoreD, d11);
        }
    }
    if ((minValidD >= 1.0f) && minified)
    {
        int r = max(1, int(round(0.5f * max(fw.x, fw.y))));
        int2 center = clamp(int2(texel), int2(0, 0), depthDims - int2(1, 1));
        int2 param_64 = depthDims;
        int2 param_65 = center + int2(-r, -r);
        float n0 = fetchDepth(param_64, param_65);
        int2 param_66 = depthDims;
        int2 param_67 = center + int2(r, -r);
        float n1 = fetchDepth(param_66, param_67);
        int2 param_68 = depthDims;
        int2 param_69 = center + int2(-r, r);
        float n2 = fetchDepth(param_68, param_69);
        int2 param_70 = depthDims;
        int2 param_71 = center + r.xx;
        float n3 = fetchDepth(param_70, param_71);
        if (n0 < 1.0f)
        {
            minValidD = min(minValidD, n0);
        }
        if (n1 < 1.0f)
        {
            minValidD = min(minValidD, n1);
        }
        if (n2 < 1.0f)
        {
            minValidD = min(minValidD, n2);
        }
        if (n3 < 1.0f)
        {
            minValidD = min(minValidD, n3);
        }
        maxValidD = minValidD;
    }
    if (minValidD >= 1.0f)
    {
        discard;
    }
    float resolvedDepth;
    if (isEdgePass)
    {
        resolvedDepth = (minCoreD < 1.0f) ? minCoreD : minValidD;
    }
    else
    {
        int2 nearCoord = clamp(int2(clamp(inUV, 0.0f.xx, 1.0f.xx) * float2(depthDims)), int2(0, 0), depthDims - int2(1, 1));
        float nearD = depthMap.Load(int3(nearCoord, 0)).x;
        if ((maxValidD - minValidD) <= 0.01568627543747425079345703125f)
        {
            bool _1249 = d00 < 1.0f;
            bool _1255;
            if (_1249)
            {
                _1255 = c00.w > 0.0f;
            }
            else
            {
                _1255 = _1249;
            }
            float _1256;
            if (_1255)
            {
                _1256 = ((1.0f - f.x) * (1.0f - f.y)) * c00.w;
            }
            else
            {
                _1256 = 0.0f;
            }
            float dw00 = _1256;
            bool _1273 = d10 < 1.0f;
            bool _1279;
            if (_1273)
            {
                _1279 = c10.w > 0.0f;
            }
            else
            {
                _1279 = _1273;
            }
            float _1280;
            if (_1279)
            {
                _1280 = (f.x * (1.0f - f.y)) * c10.w;
            }
            else
            {
                _1280 = 0.0f;
            }
            float dw10 = _1280;
            bool _1296 = d01 < 1.0f;
            bool _1302;
            if (_1296)
            {
                _1302 = c01.w > 0.0f;
            }
            else
            {
                _1302 = _1296;
            }
            float _1303;
            if (_1302)
            {
                _1303 = ((1.0f - f.x) * f.y) * c01.w;
            }
            else
            {
                _1303 = 0.0f;
            }
            float dw01 = _1303;
            bool _1319 = d11 < 1.0f;
            bool _1325;
            if (_1319)
            {
                _1325 = c11.w > 0.0f;
            }
            else
            {
                _1325 = _1319;
            }
            float _1326;
            if (_1325)
            {
                _1326 = (f.x * f.y) * c11.w;
            }
            else
            {
                _1326 = 0.0f;
            }
            float dw11 = _1326;
            float dwSum = ((dw00 + dw10) + dw01) + dw11;
            float _1350;
            if (dwSum > 9.9999997473787516355514526367188e-06f)
            {
                _1350 = ((((d00 * dw00) + (d10 * dw10)) + (d01 * dw01)) + (d11 * dw11)) / dwSum;
            }
            else
            {
                _1350 = minValidD;
            }
            resolvedDepth = _1350;
        }
        else
        {
            float _1376;
            if (nearD < 1.0f)
            {
                _1376 = nearD;
            }
            else
            {
                _1376 = (minCoreD < 1.0f) ? minCoreD : minValidD;
            }
            resolvedDepth = _1376;
        }
    }
    float fragZ = lerp(inDepthInterval.x, inDepthInterval.y, (resolvedDepth * 255.0f) / 254.0f);
    if (isEdgePass)
    {
        float stepBias_1 = max(1.9999999949504854157567024230957e-06f, (0.25f * abs(inDepthInterval.y - inDepthInterval.x)) / 254.0f);
        fragZ = max(0.0f, fragZ - stepBias_1);
    }
    color = sampled * inTint;
    gl_FragDepth = fragZ;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    inUV = stage_input.inUV;
    inDepthInterval = stage_input.inDepthInterval;
    inTint = stage_input.inTint;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.gl_FragDepth = gl_FragDepth;
    stage_output.color = color;
    return stage_output;
}
