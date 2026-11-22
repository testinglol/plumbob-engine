struct SpriteInstance
{
    float4 rect;
    float4 uvRect;
    float4 tint;
    float4 params;
};

static const float2 _98[6] = { 0.0f.xx, float2(1.0f, 0.0f), float2(0.0f, 1.0f), float2(0.0f, 1.0f), float2(1.0f, 0.0f), 1.0f.xx };

cbuffer Quad : register(b0, space1)
{
    float4 quad_rect : packoffset(c0);
    float4 quad_canvasPadding : packoffset(c1);
    float4 quad_uvRect : packoffset(c2);
    float4 quad_depthInterval : packoffset(c3);
    float4 quad_tint : packoffset(c4);
};

ByteAddressBuffer _75 : register(t0, space0);

static float4 gl_Position;
static int gl_VertexIndex;
static float2 outUV;
static float4 outTint;
static float4 outDepthInterval;
static float outOpacity;
static float4 outUVRect;

struct SPIRV_Cross_Input
{
    uint gl_VertexIndex : SV_VertexID;
};

struct SPIRV_Cross_Output
{
    float2 outUV : TEXCOORD0;
    nointerpolation float4 outTint : TEXCOORD1;
    nointerpolation float4 outDepthInterval : TEXCOORD2;
    nointerpolation float outOpacity : TEXCOORD3;
    nointerpolation float4 outUVRect : TEXCOORD4;
    float4 gl_Position : SV_Position;
};

float4 canvasPosition(float2 pixel, float z)
{
    float2 canvas = quad_canvasPadding.xy;
    return float4(((pixel.x / canvas.x) * 2.0f) - 1.0f, 1.0f - ((pixel.y / canvas.y) * 2.0f), z, 1.0f);
}

void vert_main()
{
    uint idx = uint(gl_VertexIndex);
    uint instanceIdx = asuint(quad_depthInterval.x) + (idx / 6u);
    uint cornerIdx = idx % 6u;
    SpriteInstance _80;
    _80.rect = asfloat(_75.Load4(instanceIdx * 64 + 0));
    _80.uvRect = asfloat(_75.Load4(instanceIdx * 64 + 16));
    _80.tint = asfloat(_75.Load4(instanceIdx * 64 + 32));
    _80.params = asfloat(_75.Load4(instanceIdx * 64 + 48));
    SpriteInstance inst;
    inst.rect = _80.rect;
    inst.uvRect = _80.uvRect;
    inst.tint = _80.tint;
    inst.params = _80.params;
    float2 uv = _98[cornerIdx];
    float2 param = inst.rect.xy + (uv * inst.rect.zw);
    float param_1 = 0.0f;
    gl_Position = canvasPosition(param, param_1);
    float _127;
    if (inst.params.x > 0.0f)
    {
        _127 = 1.0f - uv.x;
    }
    else
    {
        _127 = uv.x;
    }
    float2 source = float2(_127, uv.y);
    outUV = inst.uvRect.xy + (source * inst.uvRect.zw);
    outTint = inst.tint;
    outDepthInterval = float4(0.0f, 0.0f, inst.params.z, inst.params.w);
    outOpacity = inst.params.y;
    outUVRect = inst.uvRect;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    gl_VertexIndex = int(stage_input.gl_VertexIndex);
    vert_main();
    SPIRV_Cross_Output stage_output;
    stage_output.gl_Position = gl_Position;
    stage_output.outUV = outUV;
    stage_output.outTint = outTint;
    stage_output.outDepthInterval = outDepthInterval;
    stage_output.outOpacity = outOpacity;
    stage_output.outUVRect = outUVRect;
    return stage_output;
}
