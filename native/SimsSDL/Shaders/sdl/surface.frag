#version 450
layout(set = 2, binding = 0) uniform sampler2D art;
layout(location = 0) in vec2 inUV;
layout(location = 1) flat in vec4 inTint;
layout(location = 2) in vec3 inNormal;
layout(location = 3) flat in float inTextureOnly;
layout(location = 0) out vec4 color;
void main() {
    vec4 sampled = texture(art, inUV);
    if (sampled.a < 0.01) discard;
    if (inTextureOnly > 2.5) {
        float waterSd = inNormal.x;
        float inGorge = inNormal.y;
        float cascadeMask = clamp(inNormal.z, 0.0, 1.0);
        float depth = max(0.0, -waterSd);
        float tShoal = smoothstep(0.0, 2.4, depth);
        float tMid = smoothstep(1.3, 6.4, depth);
        float tDeep = smoothstep(5.5, 13.5, depth);
        float tAbyss = smoothstep(12.5, 24.0, depth);
        vec3 cShore = vec3(0.068, 0.165, 0.250);
        vec3 cShoal = vec3(0.045, 0.124, 0.218);
        vec3 cMid = vec3(0.020, 0.066, 0.166);
        vec3 cDeep = vec3(0.012, 0.036, 0.132);
        vec3 cAbyss = vec3(0.008, 0.022, 0.102);
        vec3 cGorge = mix(vec3(0.036, 0.112, 0.205), vec3(0.014, 0.048, 0.145), smoothstep(0.0, 4.0, depth));
        vec3 baseWater = mix(cShore, cShoal, tShoal);
        baseWater = mix(baseWater, cMid, tMid);
        baseWater = mix(baseWater, cDeep, tDeep);
        baseWater = mix(baseWater, cAbyss, tAbyss);
        baseWater = mix(baseWater, cGorge, inGorge);
        vec3 cRapid = vec3(0.032, 0.125, 0.245);
        baseWater = mix(baseWater, cRapid, cascadeMask * 0.58);

        float alpha = smoothstep(0.08, -0.42, waterSd) * mix(0.76, 1.0, smoothstep(0.25, 4.2, depth));
        float gorgeAlpha = smoothstep(0.08, -0.28, waterSd) * mix(0.84, 0.99, smoothstep(0.20, 2.0, depth));
        alpha = mix(alpha, gorgeAlpha, inGorge);

        float waveLuma = dot(sampled.rgb, vec3(0.299, 0.587, 0.114));
        float detailLuma = dot(texture(art, inUV * 1.9 + vec2(0.17, 0.41)).rgb, vec3(0.299, 0.587, 0.114));
        float flowLuma = dot(texture(art, inUV * vec2(1.4, 3.1) + vec2(0.43, 0.19)).rgb, vec3(0.299, 0.587, 0.114));
        float lumaP = pow(max(waveLuma, 0.0), 0.4545);
        float dLumaP = pow(max(detailLuma, 0.0), 0.4545);
        float fLumaP = pow(max(flowLuma, 0.0), 0.4545);
        float rippleMod = mix(0.74, 1.36, smoothstep(0.20, 0.64, lumaP));
        vec3 wRgb = baseWater * rippleMod;
        float glint = smoothstep(0.53, 0.76, lumaP) * smoothstep(0.40, 0.66, dLumaP);
        wRgb = mix(wRgb, vec3(0.26, 0.38, 0.56), glint * 0.60);
        float sparkle = pow(glint, 2.1);
        wRgb += vec3(0.24, 0.30, 0.38) * sparkle;

        vec2 flowUV = inUV * vec2(3.6, 1.35) + vec2(0.43, 0.19);
        float rapidNoise = dot(texture(art, flowUV).rgb, vec3(0.299, 0.587, 0.114));
        float rapidP = pow(max(rapidNoise, 0.0), 0.4545);
        float cascadeFoam = cascadeMask * smoothstep(-0.04, -0.42, waterSd) * smoothstep(0.24, 0.66, 0.54 * rapidP + 0.28 * fLumaP + 0.18 * dLumaP);
        vec3 foamTint = mix(vec3(0.46, 0.76, 0.90), vec3(0.92, 0.96, 0.99), smoothstep(0.28, 0.82, cascadeFoam));
        wRgb = mix(wRgb, foamTint, clamp(cascadeFoam * 0.95, 0.0, 0.95));

        float surfPattern = smoothstep(0.32, 0.68, 0.54 * lumaP + 0.46 * dLumaP);
        float surfZone = smoothstep(0.28, 0.0, waterSd) * (1.0 - smoothstep(-0.26, -0.78, waterSd));
        float surfCrest = clamp(1.0 - abs(waterSd + 0.16) * 3.0, 0.0, 1.0);
        float surfFoam = surfZone * smoothstep(0.36, 0.72, surfPattern + 0.34 * surfCrest) * clamp(1.0 - inGorge, 0.0, 1.0);
        wRgb = mix(wRgb, vec3(0.84, 0.90, 0.95), surfFoam * 0.94);
        alpha = max(alpha, max(surfFoam * 0.72, cascadeFoam * 0.65));
        alpha *= inTint.a;
        if (alpha < 0.005) discard;
        color = vec4(wRgb * inTint.rgb * alpha, alpha);
        return;
    }
    if (inTextureOnly > 1.5) {
        float w = clamp(inNormal.x, 0.0, 1.0);
        float lit = inNormal.y;
        float waterSd = inNormal.z;
        float macroL = dot(texture(art, inUV * 0.23 + vec2(0.31, 0.67)).rgb, vec3(0.299, 0.587, 0.114));
        vec3 sandRgb = sampled.rgb * mix(0.92, 1.09, smoothstep(0.36, 0.62, macroL));
        float wet = 1.0 - smoothstep(-0.28, 0.72, waterSd);
        sandRgb *= mix(1.0, 0.80, wet);
        float sandLuma = dot(sandRgb, vec3(0.299, 0.587, 0.114));
        float edgeWindow = smoothstep(0.0, 0.20, w) * (1.0 - smoothstep(0.68, 1.0, w));
        float detail = (sandLuma - 0.49) * 1.15 * edgeWindow;
        float alpha = smoothstep(0.30, 0.72, w + detail) * inTint.a;
        if (alpha < 0.005) discard;
        color = vec4(sandRgb * lit * inTint.rgb * alpha, alpha);
        return;
    }
    if (inTextureOnly > 0.5) {
        float w = clamp(inNormal.x, 0.0, 1.0);
        vec3 rockA = texture(art, inUV * 0.90 + vec2(0.07, 0.13)).rgb;
        vec3 rockB = texture(art, vec2(inUV.x * 0.37 - inUV.y * 0.11, inUV.x * 0.09 + inUV.y * 0.41) + vec2(0.53, 0.29)).rgb;
        vec3 rockSample = mix(rockA, rockB, 0.42);
        float macroL = dot(texture(art, inUV * 0.21 + vec2(0.37, 0.71)).rgb, vec3(0.299, 0.587, 0.114));
        float macroP = pow(max(macroL, 0.0), 0.4545);
        vec3 rockRgb = rockSample * vec3(0.97, 1.00, 1.04) * mix(0.68, 1.28, smoothstep(0.24, 0.76, macroP));
        float rockLumaP = pow(max(dot(rockRgb, vec3(0.299, 0.587, 0.114)), 0.0), 0.4545);
        float breakupL = dot(texture(art, inUV * 0.43 + vec2(0.19, 0.83)).rgb, vec3(0.299, 0.587, 0.114));
        float breakupP = pow(max(breakupL, 0.0), 0.4545);
        float edgeWindow = smoothstep(0.02, 0.28, w) * (1.0 - smoothstep(0.64, 0.98, w));
        float detail = ((rockLumaP - 0.48) * 0.95 + (breakupP - 0.50) * 1.15) * edgeWindow;
        float alpha = smoothstep(0.14, 0.80, w + detail) * inTint.a;
        if (alpha < 0.005) discard;
        float toeShade = mix(0.84, 1.0, smoothstep(0.08, 0.48, w));
        color = vec4(rockRgb * (inNormal.y * toeShade) * inTint.rgb * alpha, alpha);
        return;
    }
    color = sampled * inTint;
}
