using System.Numerics;
using System.Runtime.InteropServices;
using System.Text.Json;
using SimsNative.Plugins;

namespace Local.Lighting;

public sealed class LightingClientPlugin : ISimsClientPlugin
{
    private const string Assets = "Downloads/local.lighting/shaders/";
    private const int MaxLamps = 16;
    private const int UniformVec4Count = 15 + MaxLamps;
    private static readonly PluginRenderStage[] ActiveStages = [PluginRenderStage.Lighting];
    private static readonly PluginRenderStage[] EmptyStages = [];

    private IClientPluginContext _context = null!;
    private Dictionary<string, float> _defaults = new(StringComparer.Ordinal);
    private bool _enabled = true;
    private bool _shadows = true;
    private bool _ao = true;
    private bool _cycle = true;
    private int _minutes = 720;

    private int _termSlot;
    private string _historyKey = string.Empty;
    private Vector3 _prevView;
    private int _frameIndex;
    private double _runningClockSeconds;

    public void Initialize(IClientPluginContext context)
    {
        _context = context;
        _defaults = JsonSerializer.Deserialize<Dictionary<string, float>>(context.ReadPluginData("lighting.json"))
            ?? throw new InvalidDataException("Missing lighting.json");
        PublishBlackboard(sun: new Vector3(1f, 0f, 0f), shadowStrength: 0.56f, nightGlow: 0f);
    }

    public bool SuppressVanillaRoomLighting => _enabled;

    public IReadOnlyList<PluginRenderStage> RenderStages => _enabled ? ActiveStages : EmptyStages;

    public void OnServerState(ReadOnlySpan<byte> data)
    {
        try
        {
            using var doc = JsonDocument.Parse(data.ToArray());
            var root = doc.RootElement;
            if (root.TryGetProperty("enabled", out var enEl) && (enEl.ValueKind is JsonValueKind.True or JsonValueKind.False))
                _enabled = enEl.GetBoolean();
            if (root.TryGetProperty("shadows", out var shEl) && (shEl.ValueKind is JsonValueKind.True or JsonValueKind.False))
                _shadows = shEl.GetBoolean();
            if (root.TryGetProperty("ao", out var aoEl) && (aoEl.ValueKind is JsonValueKind.True or JsonValueKind.False))
                _ao = aoEl.GetBoolean();
            if (root.TryGetProperty("cycle", out var cyEl) && (cyEl.ValueKind is JsonValueKind.True or JsonValueKind.False))
                _cycle = cyEl.GetBoolean();
            if (root.TryGetProperty("minutes", out var mEl) && mEl.TryGetInt32(out int m))
                _minutes = Math.Clamp(m, 0, 1439);
        }
        catch (JsonException)
        {
        }

        if (!_enabled)
            PublishBlackboard(new Vector3(1f, 0f, 0f), 0f, 0f);
    }

    private float Default(string key, float fallback = 0f) =>
        _defaults.TryGetValue(key, out float v) ? v : fallback;

    private float Sky(string key, float fallback = 0f) =>
        _context.Blackboard.TryGetValue(key, out float v) && float.IsFinite(v) ? v : fallback;

    private static float Smooth(float x)
    {
        x = Math.Clamp(x, 0f, 1f);
        return x * x * (3f - 2f * x);
    }

    private void PublishBlackboard(Vector3 sun, float shadowStrength, float nightGlow)
    {
        _context.SetBlackboardValue("lighting.active", _enabled ? 1f : 0f);
        _context.SetBlackboardValue("lighting.shadows", _enabled ? shadowStrength : 0f);
        _context.SetBlackboardValue("lighting.sunUp", sun.X);
        _context.SetBlackboardValue("lighting.sunToward", sun.Y);
        _context.SetBlackboardValue("lighting.sunRight", sun.Z);
        _context.SetBlackboardValue("lighting.nightGlow", _enabled ? nightGlow : 0f);
    }

    public void Render(IPluginRenderContext render)
    {
        if (!_enabled || render.Stage != PluginRenderStage.Lighting)
            return;

        var scene = render.Scene;
        if (scene.TimeOverrideSeconds is float overrideSec)
            _runningClockSeconds = overrideSec;
        else
            _runningClockSeconds = (_runningClockSeconds + scene.DeltaSeconds) % 3600.0;
        float seconds = scene.TimeOverrideSeconds ?? (float)_runningClockSeconds;

        bool shadowsOn = _shadows && scene.ShadowsEnabled;
        bool aoOn = _ao;
        bool cycleOn = _cycle;

        float cover = Math.Clamp(Sky("sky.cloudCover"), 0f, 1f);
        float rain = Math.Clamp(Sky("sky.precipitation"), 0f, 1f);
        float wetness = Math.Clamp(Sky("sky.wetness"), 0f, 1f);
        float snowPack = Sky("sky.snowPack");
        float snowfall = Sky("sky.snowfall");
        float thunder = Sky("sky.thunder");
        float rise = Sky("sky.sunrise", 6f);
        float set = Sky("sky.sunset", 20f);
        float elevationScale = Sky("sky.elevationScale", 0.8f);
        float tintWeatherScale = Sky("sky.tintScale", 1f);
        Vector2 wind = new(Sky("sky.windX"), Sky("sky.windY"));
        float cloudHeight = Sky("sky.cloudHeight", Default("cloudHeight", 18f));
        float cloudShade = Sky("sky.cloudShade", Default("cloudShade", 0.35f) * cover);

        float shadowVal = shadowsOn ? 0.56f : 0f;
        float aoVal = aoOn ? 1.00f : 0f;
        float contactVal = aoOn && scene.ShadowsEnabled ? 0.62f : 0f;
        float windowVal = shadowsOn ? 1.55f : 0f;
        float lampVal = cycleOn ? 1.25f : 0f;
        float tintVal = cycleOn ? 0.78f * tintWeatherScale : 0f;
        float nightVal = cycleOn ? 0.15f : 1.0f;

        float hour = _minutes / 60f;
        float sunRise = rise - 0.75f;
        float day = (hour - sunRise) / MathF.Max(1f, set - sunRise);
        bool daylight = day > 0f && day < 1f;
        float skyDim = 1f - 0.35f * cover - 0.15f * rain;
        float light = cycleOn
            ? Smooth((hour - rise + 0.75f) / 1.75f) * Smooth((set + 0.75f - hour) / 2.0f) * Math.Clamp(skyDim, 0.35f, 1f)
            : 1f;

        float nightSpan = 24f - (set - sunRise);
        float nightAge = hour >= set ? hour - set : hour + (24f - set);
        float moonPhase = Math.Clamp(nightAge / MathF.Max(1f, nightSpan), 0f, 1f);
        float moonElevation = (0.18f + 0.65f * MathF.Sin(MathF.PI * moonPhase)) * 0.5f * MathF.PI * 0.75f;
        float moonAzimuth = MathF.Atan2(-0.25f, -1f) + (MathF.Atan2(0.85f, 0.35f) - MathF.Atan2(-0.25f, -1f)) * moonPhase;
        float moonGround = MathF.Cos(moonElevation);
        float moonUp = MathF.Sin(moonElevation);
        float moonToward = moonGround * (MathF.Cos(moonAzimuth) + MathF.Sin(moonAzimuth)) / MathF.Sqrt(2f);
        float moonRight = moonGround * (MathF.Cos(moonAzimuth) - MathF.Sin(moonAzimuth)) / MathF.Sqrt(2f);
        float moonClear = Math.Clamp(1f - cover * 1.15f, 0f, 1f) * Math.Clamp(1f - rain * 4f, 0f, 1f);
        float moonStrength = !daylight ? Math.Min(1f, Math.Min(moonPhase / 0.12f, (1f - moonPhase) / 0.12f)) * moonClear : 0f;

        float bodyUp, bodyToward, bodyRight, shadowOut, windowOut;
        if (daylight || !cycleOn)
        {
            float sunDay = cycleOn ? day : 0.42f;
            float elevation = (0.14f + 0.62f * MathF.Sin(MathF.PI * sunDay)) * 0.5f * MathF.PI * elevationScale;
            float azimuth = MathF.Atan2(0.2f, -1f) + (MathF.Atan2(1f, 0.2f) - MathF.Atan2(0.2f, -1f)) * sunDay;
            float ground = MathF.Cos(elevation);
            bodyUp = MathF.Sin(elevation);
            bodyToward = ground * (MathF.Cos(azimuth) + MathF.Sin(azimuth)) / MathF.Sqrt(2f);
            bodyRight = ground * (MathF.Cos(azimuth) - MathF.Sin(azimuth)) / MathF.Sqrt(2f);
            float directSunFade = Math.Max(0f, 1f - Math.Max(0f, cover - 0.35f) / 0.55f) * (1f - 0.7f * rain);
            float strength = (cycleOn ? Math.Min(1f, Math.Min(day / 0.035f, (1f - day) / 0.06f)) : 1f) * directSunFade;
            shadowOut = shadowVal * strength;
            windowOut = windowVal * strength;
        }
        else
        {
            bodyUp = moonUp;
            bodyToward = moonToward;
            bodyRight = moonRight;
            shadowOut = shadowVal * 0.14f * moonStrength;
            windowOut = windowVal * 0.08f * moonStrength;
        }

        Vector3 sunInLot = scene.SunDirectionOverride ?? new Vector3(bodyUp, bodyToward, bodyRight);
        float lampScale = 1f + (0.25f - 1f) * light;
        float baseLight = nightVal + (1f - nightVal) * light;
        float lampGain = lampVal * lampScale;
        float glow = cycleOn ? Math.Clamp((lampScale - 0.25f) / 0.75f, 0f, 1f) : 0f;
        float tint = tintVal * (1f - 0.75f * cover) * Smooth((light - nightVal) / MathF.Max(0.05f, 1f - nightVal));
        float dayProgress = cycleOn ? Math.Clamp(day, 0f, 1f) : 0.5f;
        float reach = MathF.Min(34f, MathF.Max(Default("reach", 14f), 10.0f) / MathF.Max(0.22f, sunInLot.X));

        PublishBlackboard(sunInLot, MathF.Max(shadowOut, MathF.Max(aoVal, contactVal)), glow);

        var up = new Vector3(0f, -0.8660254f, 0.5f);
        var toward = new Vector3(0f, 0.5f, 0.8660254f);
        var right = new Vector3(1f, 0f, 0f);
        Vector3 sun = up * sunInLot.X + toward * sunInLot.Y + right * sunInLot.Z;
        sun /= MathF.Max(1e-6f, sun.Length());

        float invSqrt2 = 1f / MathF.Sqrt(2f);
        var sunTiles = new Vector3((sunInLot.Y + sunInLot.Z) * invSqrt2, (sunInLot.Y - sunInLot.Z) * invSqrt2, sunInLot.X);
        sunTiles /= MathF.Max(1e-6f, sunTiles.Length());

        float orientation = scene.CameraOrientation;
        Vector2 rotatedWind = scene.CameraOrientation switch
        {
            1 => new Vector2(-wind.Y, wind.X),
            2 => -wind,
            3 => new Vector2(wind.Y, -wind.X),
            _ => wind,
        };
        float slant = MathF.Min(0.6f, MathF.Max(-0.6f, (rotatedWind.X - rotatedWind.Y) * 32f * 3f / 900f));
        float windStrength = MathF.Min(1f, wind.Length() / 1.5f);
        Vector2 drift = wind * seconds;

        var sceneColor = render.AcquireSceneBuffer(SceneBufferKind.SceneColor);
        var sceneDepth = render.AcquireSceneBuffer(SceneBufferKind.SceneDepth);
        var groundDepth = render.AcquireSceneBuffer(SceneBufferKind.GroundDepth);
        var heightMap = render.AcquireSceneBuffer(SceneBufferKind.LotHeightMap);
        var footMap = render.AcquireSceneBuffer(SceneBufferKind.LotFootHeightMap);
        var worldDepth = render.AcquireSceneBuffer(SceneBufferKind.WorldShadowDepth);
        var worldBackDepth = render.AcquireSceneBuffer(SceneBufferKind.WorldShadowBackDepth);
        var indoorMask = render.AcquireSceneBuffer(SceneBufferKind.IndoorArchitectureMask);
        var overheadMap = render.AcquireSceneBuffer(SceneBufferKind.OverheadMap);
        var voxelMap = render.AcquireSceneBuffer(SceneBufferKind.VoxelMap);
        var liftMap = render.TryGetSharedTexture("surface.lift", out var sharedLift)
            ? sharedLift
            : render.AcquireSceneBuffer(SceneBufferKind.EmptyFloat16);

        bool halfRes = scene.DebugViewMode == 0 && (sceneColor.Width > 1280 || sceneColor.Height > 900);
        float ambScale = halfRes ? 2f : 1f;
        int termW = halfRes ? (sceneColor.Width + 1) / 2 : sceneColor.Width;
        int termH = halfRes ? (sceneColor.Height + 1) / 2 : sceneColor.Height;

        PluginTextureHandle term;
        PluginTextureHandle prevTerm;
        if (scene.DebugViewMode > 0)
        {
            term = sceneColor;
            prevTerm = render.AcquireSceneBuffer(SceneBufferKind.EmptyFloat16);
            _historyKey = string.Empty;
        }
        else
        {
            var t0 = render.GetOrCreateTarget("term0", termW, termH, PluginTextureFormat.ColorSrgb8, out bool c0);
            var t1 = render.GetOrCreateTarget("term1", termW, termH, PluginTextureFormat.ColorSrgb8, out bool c1);
            if (c0 || c1)
                _historyKey = string.Empty;
            _termSlot = 1 - _termSlot;
            term = _termSlot == 0 ? t0 : t1;
            prevTerm = _termSlot == 0 ? t1 : t0;
        }

        int surfaceKey = snowPack > 0.5f ? 2 : 0;
        string historyKey = $"{scene.House}:{scene.SceneRevision}:{scene.CameraOrientation}:{scene.ViewLevel}:{scene.RoofsVisible}:{surfaceKey}:{termW}x{termH}";
        bool historyValid = scene.DebugViewMode == 0 && string.Equals(_historyKey, historyKey, StringComparison.Ordinal);
        _frameIndex = historyValid ? (_frameIndex + 1) & 15 : 0;

        bool hasHeightFrame = scene.LotHeightFrame.HasValue;
        Span<Vector4> uniforms = stackalloc Vector4[UniformVec4Count];
        uniforms[0] = new Vector4(scene.ViewportOrigin.X, scene.ViewportOrigin.Y, scene.ViewportScale, Default("groundOffset"));
        uniforms[1] = new Vector4(Default("radius", 38f), aoVal, shadowOut, Default("thickness", 16f));
        uniforms[2] = new Vector4(sun, reach);
        uniforms[3] = new Vector4(scene.CanvasSize.X, scene.CanvasSize.Y, scene.DebugViewMode, ambScale);
        uniforms[4] = new Vector4(scene.Lights.Count, Default("lampReach", 240f), lampGain, baseLight);
        uniforms[5] = new Vector4(Default("contactRadius", 10f), contactVal, hasHeightFrame ? windowOut : 0f, scene.IndoorBaseAltitude);
        uniforms[6] = scene.LotHeightFrame ?? new Vector4(0f, 0f, 1f, 0f);
        uniforms[7] = new Vector4(sunTiles, hasHeightFrame ? reach : 0f);
        uniforms[8] = new Vector4(cover, cloudShade, orientation, cloudHeight);
        uniforms[9] = new Vector4(drift.X, drift.Y, scene.LotWidth, scene.LotHeight);
        uniforms[10] = new Vector4(rain, wetness, seconds, hasHeightFrame ? glow : 0f);
        uniforms[11] = new Vector4(tint, slant, windStrength, dayProgress);
        for (int i = 0; i < scene.Lights.Count && i < MaxLamps; i++)
        {
            var l = scene.Lights[i];
            uniforms[12 + i] = new Vector4(l.X, l.Y, l.Toward, l.SignedIntensity);
        }
        int ext = 12 + MaxLamps;
        uniforms[ext] = new Vector4(snowPack, snowfall, thunder, 0f);
        uniforms[ext + 1] = scene.WorldShadowViewport ?? Vector4.Zero;
        uniforms[ext + 2] = new Vector4(_prevView.X, _prevView.Y, _prevView.Z, historyValid ? (_frameIndex + 1f) : 0f);

        ReadOnlySpan<byte> uniformBytes = MemoryMarshal.AsBytes(uniforms);
        ReadOnlySpan<PluginTextureHandle> ambientInputs =
        [
            sceneDepth,
            groundDepth,
            heightMap,
            indoorMask,
            footMap,
            liftMap,
            overheadMap,
            worldDepth,
            worldBackDepth,
            prevTerm,
            voxelMap,
        ];
        render.DrawFullscreenPass(
            Assets + "ambient.frag",
            term,
            PluginBlendMode.Opaque,
            loadTarget: scene.DebugViewMode > 0,
            ambientInputs,
            uniformBytes,
            linearSamplerMask: 1u << 9);

        if (scene.DebugViewMode != 0)
            return;

        _historyKey = historyKey;
        _prevView = new Vector3(scene.ViewportOrigin.X, scene.ViewportOrigin.Y, scene.ViewportScale);
        render.ShareTexture("lighting.term", term);

        ReadOnlySpan<PluginTextureHandle> blurInputs = [term, sceneDepth, groundDepth, liftMap];
        render.DrawFullscreenPass(
            Assets + "ambientBlur.frag",
            sceneColor,
            PluginBlendMode.DoubleModulate,
            loadTarget: true,
            blurInputs,
            uniformBytes);
    }
}
