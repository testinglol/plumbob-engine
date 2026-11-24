using System.Text.Json;
using SimsNative.Plugins;

namespace Local.Lighting;

public sealed class LightingPlugin : ISimsPlugin, IPluginEnvironmentProvider
{
    private const string PanelId = "lighting-settings";
    private const string Assets = "Downloads/local.lighting/";

    private IPluginContext context = null!;
    private Dictionary<string, float> defaults = new();
    private string? publishedSignature;

    public void Initialize(IPluginContext context)
    {
        this.context = context;
        defaults = JsonSerializer.Deserialize<Dictionary<string, float>>(context.ReadPluginData("lighting.json"))
            ?? throw new InvalidDataException("Missing lighting.json");
        PublishPanel();
    }

    public byte[] SaveState() => [];
    public void LoadState(int savedStateVersion, byte[] data) => publishedSignature = null;

    private bool Flag(string key, bool fallback = true) =>
        context.NeighborhoodValues.TryGetValue(key, out var val) ? !string.Equals(val, "off", StringComparison.OrdinalIgnoreCase) : fallback;

    private void Toggle(string key) =>
        context.NeighborhoodValues[key] = Flag(key) ? "off" : "on";

    private static float Smooth(float x) { x = Math.Clamp(x, 0, 1); return x * x * (3 - 2 * x); }

    public void OnPanelAction(string panelId, string action)
    {
        if (panelId != PanelId) return;
        switch (action)
        {
            case "toggle-enabled": Toggle("enabled"); break;
            case "toggle-shadows": Toggle("shadows"); break;
            case "toggle-ao": Toggle("ao"); break;
            case "toggle-cycle": Toggle("cycle"); break;
            case "toggle-hd-lots": Toggle("hdLots"); break;
            default: return;
        }

        publishedSignature = null;
        PublishPanel();
    }

    private void PublishPanel()
    {
        var enabled = Flag("enabled");
        var shadows = Flag("shadows");
        var ao = Flag("ao");
        var cycle = Flag("cycle");
        var hdLots = Flag("hdLots");
        var sig = $"{enabled}|{shadows}|{ao}|{cycle}|{hdLots}";
        if (publishedSignature == sig) return;
        publishedSignature = sig;
        context.SetPanelValue(PanelId, "enabled", enabled ? "on" : "off");
        context.SetPanelValue(PanelId, "shadows", shadows ? "on" : "off");
        context.SetPanelValue(PanelId, "ao", ao ? "on" : "off");
        context.SetPanelValue(PanelId, "cycle", cycle ? "on" : "off");
        context.SetPanelValue(PanelId, "hdLots", hdLots ? "on" : "off");
    }

    public PluginEnvironment? GetEnvironment(PluginEnvironmentClock clock)
    {
        PublishPanel();

        var enabled = Flag("enabled");
        var shadowsOn = enabled && Flag("shadows");
        var aoOn = enabled && Flag("ao");
        var cycleOn = enabled && Flag("cycle");

        var shadowVal = shadowsOn ? 0.56f : 0f;
        var aoVal = aoOn ? 1.00f : 0f;
        var contactVal = aoOn ? 0.62f : 0f;
        var windowVal = shadowsOn ? 1.55f : 0f;
        var lampVal = cycleOn ? 1.25f : 0f;
        var tintVal = cycleOn ? 0.78f : 0f;
        var nightVal = cycleOn ? 0.15f : 1.0f;

        var hour = Math.Clamp(clock.Minutes, 0, 1439) / 60f;
        const float rise = 6f;
        const float set = 20f;
        var sunRise = rise - 0.75f;
        var day = (hour - sunRise) / (set - sunRise);
        var daylight = day > 0 && day < 1;
        var light = cycleOn ? Smooth((hour - rise + 0.75f) / 1.75f) * Smooth((set + 0.75f - hour) / 2.0f) : 1f;

        var nightSpan = 24f - (set - sunRise);
        var nightAge = hour >= set ? hour - set : hour + (24f - set);
        var moonPhase = Math.Clamp(nightAge / Math.Max(1f, nightSpan), 0f, 1f);
        var moonElevation = (0.18f + 0.65f * MathF.Sin(MathF.PI * moonPhase)) * 0.5f * MathF.PI * 0.75f;
        var moonAzimuth = MathF.Atan2(-0.25f, -1f) + (MathF.Atan2(0.85f, 0.35f) - MathF.Atan2(-0.25f, -1f)) * moonPhase;
        var moonGround = MathF.Cos(moonElevation);
        var moonUp = MathF.Sin(moonElevation);
        var moonToward = moonGround * (MathF.Cos(moonAzimuth) + MathF.Sin(moonAzimuth)) / MathF.Sqrt(2);
        var moonRight = moonGround * (MathF.Cos(moonAzimuth) - MathF.Sin(moonAzimuth)) / MathF.Sqrt(2);
        var moonStrength = !daylight ? Math.Min(1f, Math.Min(moonPhase / 0.12f, (1f - moonPhase) / 0.12f)) : 0f;

        float bodyUp, bodyToward, bodyRight, shadowOut, windowOut;
        if (daylight || !cycleOn)
        {
            var sunDay = cycleOn ? day : 0.42f;
            var elevation = (0.14f + 0.62f * MathF.Sin(MathF.PI * sunDay)) * 0.5f * MathF.PI * 0.8f;
            var azimuth = MathF.Atan2(0.2f, -1) + (MathF.Atan2(1, 0.2f) - MathF.Atan2(0.2f, -1)) * sunDay;
            var ground = MathF.Cos(elevation);
            bodyUp = MathF.Sin(elevation);
            bodyToward = ground * (MathF.Cos(azimuth) + MathF.Sin(azimuth)) / MathF.Sqrt(2);
            bodyRight = ground * (MathF.Cos(azimuth) - MathF.Sin(azimuth)) / MathF.Sqrt(2);
            var strength = cycleOn ? Math.Min(1, Math.Min(day / 0.035f, (1 - day) / 0.06f)) : 1f;
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

        var values = new Dictionary<string, float>(defaults)
        {
            ["occlusion"] = aoVal,
            ["contact"] = contactVal,
            ["sunUp"] = bodyUp,
            ["sunToward"] = bodyToward,
            ["sunRight"] = bodyRight,
            ["night"] = nightVal,
            ["shadow"] = shadowOut,
            ["windowSun"] = windowOut,
            ["reach"] = MathF.Min(34f, MathF.Max(defaults["reach"], 10.0f) / MathF.Max(0.22f, bodyUp)),
        };

        var lampScale = 1 + (0.25f - 1) * light;
        values["base"] = nightVal + (1 - nightVal) * light;
        values["lampGain"] = lampVal * lampScale;
        values["glow"] = cycleOn ? Math.Clamp((lampScale - 0.25f) / 0.75f, 0, 1) : 0f;
        values["tint"] = tintVal;
        values["dayProgress"] = enabled ? (cycleOn ? Math.Clamp(day, 0f, 1f) : 0.5f) : -1f;
        values["enhancedLighting"] = enabled ? 1f : 0f;

        values["lightingShadowScale"] = defaults["shadow"] > 0 ? shadowVal / defaults["shadow"] : 1f;
        values["lightingWindowSunScale"] = defaults["windowSun"] > 0 ? windowVal / defaults["windowSun"] : 1f;
        values["lightingLampScale"] = defaults["lampGain"] > 0 ? lampVal / defaults["lampGain"] : 1f;
        values["lightingTintScale"] = defaults["tint"] > 0 ? tintVal / defaults["tint"] : 1f;
        values["lightingNight"] = nightVal;
        values["lightingMoonShadow"] = shadowsOn && cycleOn ? shadowVal * 0.14f : 0f;
        values["lightingMoonWindow"] = shadowsOn && cycleOn ? windowVal * 0.08f : 0f;
        values["lightingMoonUp"] = moonUp;
        values["lightingMoonToward"] = moonToward;
        values["lightingMoonRight"] = moonRight;
        values["lightingMoonReach"] = MathF.Min(34f, MathF.Max(defaults["reach"], 10.0f) / MathF.Max(0.22f, moonUp));

        return new PluginEnvironment
        {
            Parameters = values,
            Shaders = new[] { "ambient.frag", "ambientBlur.frag", "groundDepth.vert", "heightScatter.vert", "depthOnly.frag", "fullscreen.vert" }
                .ToDictionary(name => name.Split('.')[0], name => Assets + "shaders/" + name)
        };
    }
}
