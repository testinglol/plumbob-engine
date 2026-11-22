static const int2 _499[8] = { int2(2, 0), int2(-2, 0), int2(0, 2), int2(0, -2), int2(2, 2), int2(-2, 2), int2(2, -2), int2(-2, -2) };

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

Texture2D<float4> depthMap : register(t1, space2);
SamplerState _depthMap_sampler : register(s1, space2);
Texture2D<float4> groundMap : register(t2, space2);
SamplerState _groundMap_sampler : register(s2, space2);
Texture2D<float4> liftMap : register(t3, space2);
SamplerState _liftMap_sampler : register(s3, space2);
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
    float _33;
    if (terrain)
    {
        _33 = ((16.0f * key) - local.y) / 40.0f;
    }
    else
    {
        _33 = ((16.0f * key) - local.y) / 52.799999237060546875f;
    }
    float h = _33;
    float _57;
    if (terrain)
    {
        _57 = key;
    }
    else
    {
        _57 = key - (0.800000011920928955078125f * h);
    }
    float s = _57;
    float u = local.x / 32.0f;
    return float3(0.5f * (s + u), 0.5f * (s - u), h);
}

float zetaAt(int2 pixel)
{
    float depth = depthMap.Load(int3(pixel, 0)).x;
    bool terrain = depth >= 1.0f;
    if (terrain)
    {
        depth = groundMap.Load(int3(pixel, 0)).x;
    }
    if (depth >= 1.0f)
    {
        return -100000.0f;
    }
    float _125;
    if (terrain)
    {
        _125 = ambient_view.w;
    }
    else
    {
        _125 = 0.0f;
    }
    float key = ((0.89999997615814208984375f - depth) / 0.0030000000260770320892333984375f) + _125;
    uint _145_dummy_parameter;
    if (int2(spvTextureSize(liftMap, uint(0), _145_dummy_parameter)).x > 1)
    {
        float3 lift = liftMap.Load(int3(pixel, 0)).xyz;
        if (lift.z > 0.5f)
        {
            float2 scene = ((float2(pixel) + 0.5f.xx) - ambient_view.xy) / ambient_view.z.xx;
            float2 param = scene;
            float param_1 = key;
            bool param_2 = terrain;
            float2 param_3 = ambient_frame.xy;
            float3 surface = lotPoint(param, param_1, param_2, param_3);
            surface += float3(0.5f * lift.x, 0.5f * lift.x, lift.y);
            key = (surface.x + surface.y) + (0.800000011920928955078125f * surface.z);
        }
    }
    return key * 27.7128124237060546875f;
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
    int2 param = pixel;
    float z = zetaAt(param);
    float tolerance = 3.599999904632568359375f + (2.5f / max(ambient_view.z, 0.25f));
    float _258;
    if (ambient_extent.w > 0.5f)
    {
        _258 = ambient_extent.w;
    }
    else
    {
        _258 = 1.0f;
    }
    float ambScale = _258;
    float3 total = 0.0f.xxx;
    float weight = 0.0f;
    if (ambScale > 1.5f)
    {
        uint _277_dummy_parameter;
        int2 ambLimit = int2(spvTextureSize(ambientMap, uint(0), _277_dummy_parameter)) - int2(1, 1);
        float2 ambPos = ((float2(pixel) + 0.5f.xx) / ambScale.xx) - 0.5f.xx;
        int2 baseAmb = int2(round(ambPos));
        for (int y = -1; y <= 1; y++)
        {
            for (int x = -1; x <= 1; x++)
            {
                int2 ambTap = clamp(baseAmb + int2(x, y), int2(0, 0), ambLimit);
                float2 fullCenter = (float2(ambTap) + 0.5f.xx) * ambScale;
                int2 fullTap = clamp(int2(floor(fullCenter)), int2(0, 0), limit);
                float2 delta = fullCenter - (float2(pixel) + 0.5f.xx);
                int2 param_1 = fullTap;
                float dz = abs(zetaAt(param_1) - z);
                float w = exp((-dz) / tolerance) * exp((-dot(delta, delta)) / ((2.599999904632568359375f * ambScale) * ambScale));
                total += (ambientMap.Load(int3(ambTap, 0)).xyz * w);
                weight += w;
            }
        }
        float3 _385;
        if (weight > 9.9999999747524270787835121154785e-07f)
        {
            _385 = total / weight.xxx;
        }
        else
        {
            _385 = ambientMap.Load(int3(clamp(baseAmb, int2(0, 0), ambLimit), 0)).xyz;
        }
        color = float4(_385, 1.0f);
        return;
    }
    for (int y_1 = -1; y_1 <= 1; y_1++)
    {
        for (int x_1 = -1; x_1 <= 1; x_1++)
        {
            int2 tap = clamp(pixel + int2(x_1, y_1), int2(0, 0), limit);
            int2 param_2 = tap;
            float dz_1 = abs(zetaAt(param_2) - z);
            float w_1 = exp((-dz_1) / tolerance) * exp((-float((x_1 * x_1) + (y_1 * y_1))) / 2.599999904632568359375f);
            total += (ambientMap.Load(int3(tap, 0)).xyz * w_1);
            weight += w_1;
        }
    }
    if (ambient_view.z >= 1.39999997615814208984375f)
    {
        for (int i = 0; i < 8; i++)
        {
            float d2 = float((_499[i].x * _499[i].x) + (_499[i].y * _499[i].y));
            float outerSpatial = exp((-d2) / 3.400000095367431640625f);
            int2 tap_1 = clamp(pixel + _499[i], int2(0, 0), limit);
            int2 param_3 = tap_1;
            float dz_2 = abs(zetaAt(param_3) - z);
            float w_2 = exp((-dz_2) / tolerance) * outerSpatial;
            total += (ambientMap.Load(int3(tap_1, 0)).xyz * w_2);
            weight += w_2;
        }
    }
    color = float4(total / weight.xxx, 1.0f);
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
