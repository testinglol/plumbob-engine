Texture2D<float4> art : register(t0, space2);
SamplerState _art_sampler : register(s0, space2);

static float2 inUV;
static float inTextureOnly;
static float3 inNormal;
static float4 inTint;
static float4 color;

struct SPIRV_Cross_Input
{
    float2 inUV : TEXCOORD0;
    nointerpolation float4 inTint : TEXCOORD1;
    float3 inNormal : TEXCOORD2;
    nointerpolation float inTextureOnly : TEXCOORD3;
};

struct SPIRV_Cross_Output
{
    float4 color : SV_Target0;
};

void frag_main()
{
    float4 sampled = art.Sample(_art_sampler, inUV);
    if (sampled.w < 0.00999999977648258209228515625f)
    {
        discard;
    }
    if (inTextureOnly > 2.5f)
    {
        float waterSd = inNormal.x;
        float inGorge = inNormal.y;
        float cascadeMask = clamp(inNormal.z, 0.0f, 1.0f);
        float depth = max(0.0f, -waterSd);
        float tShoal = smoothstep(0.0f, 2.400000095367431640625f, depth);
        float tMid = smoothstep(1.2999999523162841796875f, 6.400000095367431640625f, depth);
        float tDeep = smoothstep(5.5f, 13.5f, depth);
        float tAbyss = smoothstep(12.5f, 24.0f, depth);
        float3 cShore = float3(0.06800000369548797607421875f, 0.16500000655651092529296875f, 0.25f);
        float3 cShoal = float3(0.04500000178813934326171875f, 0.12399999797344207763671875f, 0.217999994754791259765625f);
        float3 cMid = float3(0.0199999995529651641845703125f, 0.06599999964237213134765625f, 0.16599999368190765380859375f);
        float3 cDeep = float3(0.01200000010430812835693359375f, 0.03599999845027923583984375f, 0.1319999992847442626953125f);
        float3 cAbyss = float3(0.008000000379979610443115234375f, 0.02199999988079071044921875f, 0.1019999980926513671875f);
        float3 cGorge = lerp(float3(0.03599999845027923583984375f, 0.11200000345706939697265625f, 0.20499999821186065673828125f), float3(0.01400000043213367462158203125f, 0.048000000417232513427734375f, 0.14499999582767486572265625f), smoothstep(0.0f, 4.0f, depth).xxx);
        float3 baseWater = lerp(cShore, cShoal, tShoal.xxx);
        baseWater = lerp(baseWater, cMid, tMid.xxx);
        baseWater = lerp(baseWater, cDeep, tDeep.xxx);
        baseWater = lerp(baseWater, cAbyss, tAbyss.xxx);
        baseWater = lerp(baseWater, cGorge, inGorge.xxx);
        float3 cRapid = float3(0.0320000015199184417724609375f, 0.125f, 0.24500000476837158203125f);
        baseWater = lerp(baseWater, cRapid, (cascadeMask * 0.579999983310699462890625f).xxx);
        float alpha = smoothstep(0.07999999821186065673828125f, -0.4199999868869781494140625f, waterSd) * lerp(0.7599999904632568359375f, 1.0f, smoothstep(0.25f, 4.19999980926513671875f, depth));
        float gorgeAlpha = smoothstep(0.07999999821186065673828125f, -0.2800000011920928955078125f, waterSd) * lerp(0.839999973773956298828125f, 0.9900000095367431640625f, smoothstep(0.20000000298023223876953125f, 2.0f, depth));
        alpha = lerp(alpha, gorgeAlpha, inGorge);
        float waveLuma = dot(sampled.xyz, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f));
        float detailLuma = dot(art.Sample(_art_sampler, (inUV * 1.89999997615814208984375f) + float2(0.17000000178813934326171875f, 0.4099999964237213134765625f)).xyz, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f));
        float flowLuma = dot(art.Sample(_art_sampler, (inUV * float2(1.39999997615814208984375f, 3.099999904632568359375f)) + float2(0.430000007152557373046875f, 0.189999997615814208984375f)).xyz, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f));
        float lumaP = pow(max(waveLuma, 0.0f), 0.4544999897480010986328125f);
        float dLumaP = pow(max(detailLuma, 0.0f), 0.4544999897480010986328125f);
        float fLumaP = pow(max(flowLuma, 0.0f), 0.4544999897480010986328125f);
        float rippleMod = lerp(0.7400000095367431640625f, 1.36000001430511474609375f, smoothstep(0.20000000298023223876953125f, 0.63999998569488525390625f, lumaP));
        float3 wRgb = baseWater * rippleMod;
        float glint = smoothstep(0.5299999713897705078125f, 0.7599999904632568359375f, lumaP) * smoothstep(0.4000000059604644775390625f, 0.660000026226043701171875f, dLumaP);
        wRgb = lerp(wRgb, float3(0.2599999904632568359375f, 0.37999999523162841796875f, 0.560000002384185791015625f), (glint * 0.60000002384185791015625f).xxx);
        float sparkle = pow(glint, 2.099999904632568359375f);
        wRgb += (float3(0.23999999463558197021484375f, 0.300000011920928955078125f, 0.37999999523162841796875f) * sparkle);
        float2 flowUV = (inUV * float2(3.599999904632568359375f, 1.35000002384185791015625f)) + float2(0.430000007152557373046875f, 0.189999997615814208984375f);
        float rapidNoise = dot(art.Sample(_art_sampler, flowUV).xyz, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f));
        float rapidP = pow(max(rapidNoise, 0.0f), 0.4544999897480010986328125f);
        float cascadeFoam = (cascadeMask * smoothstep(-0.039999999105930328369140625f, -0.4199999868869781494140625f, waterSd)) * smoothstep(0.23999999463558197021484375f, 0.660000026226043701171875f, ((0.540000021457672119140625f * rapidP) + (0.2800000011920928955078125f * fLumaP)) + (0.180000007152557373046875f * dLumaP));
        float3 foamTint = lerp(float3(0.4600000083446502685546875f, 0.7599999904632568359375f, 0.89999997615814208984375f), float3(0.920000016689300537109375f, 0.959999978542327880859375f, 0.9900000095367431640625f), smoothstep(0.2800000011920928955078125f, 0.819999992847442626953125f, cascadeFoam).xxx);
        wRgb = lerp(wRgb, foamTint, clamp(cascadeFoam * 0.949999988079071044921875f, 0.0f, 0.949999988079071044921875f).xxx);
        float surfPattern = smoothstep(0.319999992847442626953125f, 0.680000007152557373046875f, (0.540000021457672119140625f * lumaP) + (0.4600000083446502685546875f * dLumaP));
        float surfZone = smoothstep(0.2800000011920928955078125f, 0.0f, waterSd) * (1.0f - smoothstep(-0.2599999904632568359375f, -0.7799999713897705078125f, waterSd));
        float surfCrest = clamp(1.0f - (abs(waterSd + 0.1599999964237213134765625f) * 3.0f), 0.0f, 1.0f);
        float surfFoam = (surfZone * smoothstep(0.36000001430511474609375f, 0.7200000286102294921875f, surfPattern + (0.3400000035762786865234375f * surfCrest))) * clamp(1.0f - inGorge, 0.0f, 1.0f);
        wRgb = lerp(wRgb, float3(0.839999973773956298828125f, 0.89999997615814208984375f, 0.949999988079071044921875f), (surfFoam * 0.939999997615814208984375f).xxx);
        alpha = max(alpha, max(surfFoam * 0.7200000286102294921875f, cascadeFoam * 0.64999997615814208984375f));
        alpha *= inTint.w;
        if (alpha < 0.004999999888241291046142578125f)
        {
            discard;
        }
        color = float4((wRgb * inTint.xyz) * alpha, alpha);
        return;
    }
    if (inTextureOnly > 1.5f)
    {
        float w = clamp(inNormal.x, 0.0f, 1.0f);
        float lit = inNormal.y;
        float waterSd_1 = inNormal.z;
        float macroL = dot(art.Sample(_art_sampler, (inUV * 0.23000000417232513427734375f) + float2(0.310000002384185791015625f, 0.670000016689300537109375f)).xyz, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f));
        float3 sandRgb = sampled.xyz * lerp(0.920000016689300537109375f, 1.09000003337860107421875f, smoothstep(0.36000001430511474609375f, 0.62000000476837158203125f, macroL));
        float wet = 1.0f - smoothstep(-0.2800000011920928955078125f, 0.7200000286102294921875f, waterSd_1);
        sandRgb *= lerp(1.0f, 0.800000011920928955078125f, wet);
        float sandLuma = dot(sandRgb, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f));
        float edgeWindow = smoothstep(0.0f, 0.20000000298023223876953125f, w) * (1.0f - smoothstep(0.680000007152557373046875f, 1.0f, w));
        float detail = ((sandLuma - 0.4900000095367431640625f) * 1.14999997615814208984375f) * edgeWindow;
        float alpha_1 = smoothstep(0.300000011920928955078125f, 0.7200000286102294921875f, w + detail) * inTint.w;
        if (alpha_1 < 0.004999999888241291046142578125f)
        {
            discard;
        }
        color = float4(((sandRgb * lit) * inTint.xyz) * alpha_1, alpha_1);
        return;
    }
    if (inTextureOnly > 0.5f)
    {
        float w_1 = clamp(inNormal.x, 0.0f, 1.0f);
        float3 rockA = art.Sample(_art_sampler, (inUV * 0.89999997615814208984375f) + float2(0.070000000298023223876953125f, 0.12999999523162841796875f)).xyz;
        float3 rockB = art.Sample(_art_sampler, float2((inUV.x * 0.37000000476837158203125f) - (inUV.y * 0.10999999940395355224609375f), (inUV.x * 0.0900000035762786865234375f) + (inUV.y * 0.4099999964237213134765625f)) + float2(0.5299999713897705078125f, 0.2899999916553497314453125f)).xyz;
        float3 rockSample = lerp(rockA, rockB, 0.4199999868869781494140625f.xxx);
        float macroL_1 = dot(art.Sample(_art_sampler, (inUV * 0.20999999344348907470703125f) + float2(0.37000000476837158203125f, 0.709999978542327880859375f)).xyz, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f));
        float macroP = pow(max(macroL_1, 0.0f), 0.4544999897480010986328125f);
        float3 rockRgb = (rockSample * float3(0.9700000286102294921875f, 1.0f, 1.03999996185302734375f)) * lerp(0.680000007152557373046875f, 1.2799999713897705078125f, smoothstep(0.23999999463558197021484375f, 0.7599999904632568359375f, macroP));
        float rockLumaP = pow(max(dot(rockRgb, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f)), 0.0f), 0.4544999897480010986328125f);
        float breakupL = dot(art.Sample(_art_sampler, (inUV * 0.430000007152557373046875f) + float2(0.189999997615814208984375f, 0.829999983310699462890625f)).xyz, float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f));
        float breakupP = pow(max(breakupL, 0.0f), 0.4544999897480010986328125f);
        float edgeWindow_1 = smoothstep(0.0199999995529651641845703125f, 0.2800000011920928955078125f, w_1) * (1.0f - smoothstep(0.63999998569488525390625f, 0.980000019073486328125f, w_1));
        float detail_1 = (((rockLumaP - 0.4799999892711639404296875f) * 0.949999988079071044921875f) + ((breakupP - 0.5f) * 1.14999997615814208984375f)) * edgeWindow_1;
        float alpha_2 = smoothstep(0.14000000059604644775390625f, 0.800000011920928955078125f, w_1 + detail_1) * inTint.w;
        if (alpha_2 < 0.004999999888241291046142578125f)
        {
            discard;
        }
        float toeShade = lerp(0.839999973773956298828125f, 1.0f, smoothstep(0.07999999821186065673828125f, 0.4799999892711639404296875f, w_1));
        color = float4(((rockRgb * (inNormal.y * toeShade)) * inTint.xyz) * alpha_2, alpha_2);
        return;
    }
    color = sampled * inTint;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    inUV = stage_input.inUV;
    inTextureOnly = stage_input.inTextureOnly;
    inNormal = stage_input.inNormal;
    inTint = stage_input.inTint;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.color = color;
    return stage_output;
}
