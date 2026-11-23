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
    float4 ambient_prevView : packoffset(c48);
};

Texture2D<float4> previous : register(t0, space2);
SamplerState _previous_sampler : register(s0, space2);

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

float print(float2 lot, float4 p)
{
    float foot = abs(p.w);
    bool paw = foot > 1.5f;
    float size = paw ? 1.0f : foot;
    float2 along = float2(cos(p.z), sin(p.z));
    float2 across = float2(-along.y, along.x);
    float _63;
    if (paw)
    {
        _63 = 0.04500000178813934326171875f;
    }
    else
    {
        _63 = 0.064999997615814208984375f * size;
    }
    float2 d = (lot - p.xy) + ((across * sign(p.w)) * _63);
    if (dot(d, d) > 0.0900000035762786865234375f)
    {
        return 0.0f;
    }
    float2 local = float2(dot(d, along), dot(d, across)) / size.xx;
    float edge;
    if (paw)
    {
        edge = (length(local / float2(0.0500000007450580596923828125f, 0.039999999105930328369140625f)) - 1.0f) * 0.039999999105930328369140625f;
    }
    else
    {
        float sole = (length((local - float2(0.02999999932944774627685546875f, 0.0f)) / float2(0.085000000894069671630859375f, 0.0529999993741512298583984375f)) - 1.0f) * 0.0529999993741512298583984375f;
        float heel = (length((local - float2(-0.039999999105930328369140625f, 0.0f)) / float2(0.04500000178813934326171875f, 0.0460000000894069671630859375f)) - 1.0f) * 0.0460000000894069671630859375f;
        edge = min(sole, heel) * size;
    }
    return clamp(0.5f - ((edge * 32.0f) / 1.5f), 0.0f, 1.0f);
}

void frag_main()
{
    int2 at = int2(gl_FragCoord.xy);
    float2 lot = (gl_FragCoord.xy / 32.0f.xx) - 1.0f.xx;
    float4 prev = previous.Load(int3(at, 0));
    if (ambient_season.x > 1.5f)
    {
        bool _187 = ambient_season.w < (-0.5f);
        bool _195;
        if (!_187)
        {
            _195 = prev.w < 0.75f;
        }
        else
        {
            _195 = _187;
        }
        float _196;
        if (_195)
        {
            _196 = 0.0f;
        }
        else
        {
            _196 = max(0.0f, prev.x - ambient_season.z);
        }
        float pressed = _196;
        for (int i = 0; i < 16; i++)
        {
            float foot = ambient_prints[i].w;
            if (foot == 0.0f)
            {
                break;
            }
            if (abs(foot) <= 2.5f)
            {
                float2 param = lot;
                float4 param_1 = ambient_prints[i];
                pressed = max(pressed, print(param, param_1));
            }
        }
        color = float4(pressed, 0.0f, 0.0f, 1.0f);
    }
    else
    {
        if (ambient_season.x > 0.5f)
        {
            bool _258 = ambient_season.w < (-0.5f);
            bool _268;
            if (!_258)
            {
                _268 = abs(prev.w - 0.5f) > 0.1500000059604644775390625f;
            }
            else
            {
                _268 = _258;
            }
            if (_268)
            {
                prev = float4(0.0f, 0.0f, 0.0f, 0.5f);
            }
            float2 _556;
            for (int i_1 = 0; i_1 < 16; i_1++)
            {
                float4 p = ambient_prints[i_1];
                if (p.w == 0.0f)
                {
                    break;
                }
                if (p.w > 3.5f)
                {
                    prev = float4(0.0f, 0.0f, 0.0f, 0.5f);
                    continue;
                }
                bool _299 = p.w >= 1.0f;
                bool _306;
                if (_299)
                {
                    _306 = p.w <= 2.0499999523162841796875f;
                }
                else
                {
                    _306 = _299;
                }
                if (_306)
                {
                    float lumBin = clamp(floor(p.z * 0.100000001490116119384765625f), 0.0f, 60.0f);
                    float r = max(p.z - (lumBin * 10.0f), 0.60000002384185791015625f);
                    float lumEnc = 0.37999999523162841796875f + ((lumBin / 60.0f) * 0.23999999463558197021484375f);
                    float hue = clamp(p.w - 1.0f, 0.07999999821186065673828125f, 0.939999997615814208984375f);
                    float dist = length(lot - p.xy);
                    float leafDrop = 1.0f - smoothstep(r * 0.119999997317790985107421875f, r * 1.0499999523162841796875f, dist);
                    float metaMask = 1.0f - smoothstep(max(0.300000011920928955078125f, r - 0.1500000059604644775390625f), r + 0.449999988079071044921875f, dist);
                    bool _370 = leafDrop > prev.y;
                    bool _389;
                    if (!_370)
                    {
                        bool _376 = metaMask > 0.20000000298023223876953125f;
                        bool _382;
                        if (_376)
                        {
                            _382 = prev.y < 0.0500000007450580596923828125f;
                        }
                        else
                        {
                            _382 = _376;
                        }
                        bool _388;
                        if (_382)
                        {
                            _388 = prev.z < 0.039999999105930328369140625f;
                        }
                        else
                        {
                            _388 = _382;
                        }
                        _389 = _388;
                    }
                    else
                    {
                        _389 = _370;
                    }
                    if (_389)
                    {
                        prev.z = hue;
                        prev.w = lumEnc;
                    }
                    prev.y = max(prev.y, leafDrop);
                }
                else
                {
                    bool _405 = p.w >= 2.0799999237060546875f;
                    bool _412;
                    if (_405)
                    {
                        _412 = p.w <= 3.150000095367431640625f;
                    }
                    else
                    {
                        _412 = _405;
                    }
                    if (_412)
                    {
                        float lumBin_1 = clamp(floor(p.z * 0.100000001490116119384765625f), 0.0f, 60.0f);
                        float r_1 = max(p.z - (lumBin_1 * 10.0f), 0.449999988079071044921875f);
                        float lumEnc_1 = 0.37999999523162841796875f + ((lumBin_1 / 60.0f) * 0.23999999463558197021484375f);
                        float hue_1 = clamp(p.w - 2.099999904632568359375f, 0.07999999821186065673828125f, 0.939999997615814208984375f);
                        bool _446 = length(lot - p.xy) < (r_1 + 0.119999997317790985107421875f);
                        bool _452;
                        if (_446)
                        {
                            _452 = prev.y < 0.0500000007450580596923828125f;
                        }
                        else
                        {
                            _452 = _446;
                        }
                        if (_452)
                        {
                            prev.z = hue_1;
                            prev.w = lumEnc_1;
                        }
                    }
                    else
                    {
                        bool _463 = p.w < (-0.75f);
                        bool _470;
                        if (_463)
                        {
                            _470 = p.w > (-1.25f);
                        }
                        else
                        {
                            _470 = _463;
                        }
                        if (_470)
                        {
                            float r_2 = max(p.z, 0.60000002384185791015625f);
                            float mask = 1.0f - smoothstep(max(0.25f, r_2 - 0.2199999988079071044921875f), r_2 + 0.14000000059604644775390625f, length(lot - p.xy));
                            prev.x = max(prev.x, mask);
                        }
                        else
                        {
                            bool _501 = p.w <= (-1.25f);
                            bool _508;
                            if (_501)
                            {
                                _508 = p.w > (-1.75f);
                            }
                            else
                            {
                                _508 = _501;
                            }
                            if (_508)
                            {
                                float r_3 = max(p.z, 0.4199999868869781494140625f);
                                float mask_1 = 1.0f - smoothstep(max(0.20000000298023223876953125f, r_3 - 0.119999997317790985107421875f), r_3 + 0.100000001490116119384765625f, length(lot - p.xy));
                                prev.x = max(prev.x, 0.63999998569488525390625f * mask_1);
                            }
                            else
                            {
                                bool _539 = p.w <= (-1.75f);
                                bool _546;
                                if (_539)
                                {
                                    _546 = p.w > (-2.75f);
                                }
                                else
                                {
                                    _546 = _539;
                                }
                                if (_546)
                                {
                                    bool horizontal = p.w > (-2.25f);
                                    if (horizontal)
                                    {
                                        _556 = float2(max(p.z, 0.5f) + 0.039999999105930328369140625f, 0.560000002384185791015625f);
                                    }
                                    else
                                    {
                                        _556 = float2(0.560000002384185791015625f, max(p.z, 0.5f) + 0.039999999105930328369140625f);
                                    }
                                    float2 halfSize = _556;
                                    float2 q = abs(lot - p.xy) - halfSize;
                                    float boxDist = length(max(q, 0.0f.xx)) + min(max(q.x, q.y), 0.0f);
                                    float mask_2 = 1.0f - smoothstep(-0.0199999995529651641845703125f, 0.07999999821186065673828125f, boxDist);
                                    prev.x = max(prev.x, 0.63999998569488525390625f * mask_2);
                                }
                            }
                        }
                    }
                }
            }
            color = float4(prev.xyz, clamp(prev.w, 0.37999999523162841796875f, 0.62000000476837158203125f));
        }
        else
        {
            color = float4(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }
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
