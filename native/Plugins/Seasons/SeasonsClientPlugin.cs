using System.Numerics;
using System.Runtime.InteropServices;
using System.Text.Json;
using SimsNative.Plugins;

namespace Local.Seasons;

public sealed class SeasonsClientPlugin : ISimsClientPlugin
{
    private const string WidgetId = "season-indicator";
    private const string ShaderDir = "Downloads/local.seasons/shaders/";
    private const float TrailTexels = 32f;
    private const float TrailMargin = 1f;
    private const int MaxLamps = 16;
    private const int MaxPrints = 16;
    private const int UniformVec4Count = 17 + MaxLamps + MaxPrints;

    private static readonly string[] SeasonNames = ["Spring", "Summer", "Autumn", "Winter"];
    private static readonly PluginRenderStage[] BothStages = [PluginRenderStage.PreLighting, PluginRenderStage.Atmosphere];
    private static readonly PluginRenderStage[] PreOnlyStage = [PluginRenderStage.PreLighting];
    private static readonly PluginRenderStage[] AtmosOnlyStage = [PluginRenderStage.Atmosphere];
    private static readonly PluginRenderStage[] NoStages = [];
    private static readonly byte[] NeutralLightingTermRgba = [128, 128, 128, 255];
    private static readonly JsonSerializerOptions WireJsonOptions = new() { PropertyNameCaseInsensitive = true };
    private static readonly byte[][] SeasonIcons =
    [
        RenderSeasonIcon(0),
        RenderSeasonIcon(1),
        RenderSeasonIcon(2),
        RenderSeasonIcon(3),
    ];

    private IClientPluginContext _context = null!;
    private bool _imagesRegistered;
    private bool _active;
    private int _house;
    private int _season;
    private string? _tooltip;
    private int _lastAnnouncedHouse;
    private int _lastAnnouncedSeason = -1;
    private string? _pendingBanner;

    private SeasonsWireState? _state;
    private readonly List<Vector4> _pendingPrints = [];
    private long _lastPrintSeq;
    private string _trailKey = string.Empty;
    private int _trailSlot;
    private float _trailFill;
    private double _runningClockSeconds;

    public void Initialize(IClientPluginContext context) => _context = context;

    public string? TerrainFragmentShader =>
        _state is { SeasonalTerrain: true, House: > 0 } ? ShaderDir + "terrain.frag" : null;

    public IReadOnlyList<PluginRenderStage> RenderStages
    {
        get
        {
            if (_state is not { House: > 0 } s)
                return NoStages;
            bool lightingActive = _context.Blackboard.TryGetValue("lighting.active", out float la) && la > 0.5f;
            bool needsPre = s.SurfaceMode != 0
                || s.SpringBloom > 0.01f
                || (!lightingActive && (s.CloudCover > 0.05f || s.Wetness > 0.02f));
            bool needsAtmos = s.Atmosphere;
            if (needsPre && needsAtmos) return BothStages;
            if (needsPre) return PreOnlyStage;
            if (needsAtmos) return AtmosOnlyStage;
            return NoStages;
        }
    }

    public void OnServerState(ReadOnlySpan<byte> stateBytes)
    {
        try
        {
            if (JsonSerializer.Deserialize<SeasonsWireState>(stateBytes, WireJsonOptions) is { } parsed)
            {
                ApplyWireState(parsed);
                return;
            }
        }
        catch (JsonException)
        {
        }

        try
        {
            using var doc = JsonDocument.Parse(stateBytes.ToArray());
            var root = doc.RootElement;
            bool active = root.TryGetProperty("active", out var aEl) && aEl.ValueKind == JsonValueKind.True;
            int house = root.TryGetProperty("house", out var hEl) && hEl.TryGetInt32(out int h) ? h : 0;
            int season = root.TryGetProperty("season", out var sEl) && sEl.TryGetInt32(out int s) ? ((s % 4) + 4) % 4 : 0;
            string cycleTip = root.TryGetProperty("cycleTooltip", out var cEl) ? cEl.GetString() ?? string.Empty : string.Empty;
            string weatherTip = root.TryGetProperty("weatherTooltip", out var wEl) ? wEl.GetString() ?? string.Empty : string.Empty;
            UpdateHudFields(active, house, season, cycleTip, weatherTip);
        }
        catch (JsonException)
        {
        }
    }

    private void ApplyWireState(SeasonsWireState next)
    {
        if (_state?.House != next.House)
        {
            _pendingPrints.Clear();
            _lastPrintSeq = 0;
            _trailKey = string.Empty;
            _trailFill = 0f;
        }

        _state = next;
        int season = ((next.Season % 4) + 4) % 4;
        UpdateHudFields(next.Active, next.House, season, next.CycleTooltip, next.WeatherTooltip);

        if (next.Prints is { Length: > 0 })
        {
            foreach (var mark in next.Prints)
            {
                if (mark.Sequence > _lastPrintSeq)
                {
                    _pendingPrints.Add(new Vector4(mark.X, mark.Y, mark.Heading, mark.Foot));
                    _lastPrintSeq = mark.Sequence;
                }
            }
            if (_pendingPrints.Count > 128)
                _pendingPrints.RemoveRange(0, _pendingPrints.Count - 128);
        }
    }

    private void UpdateHudFields(bool active, int house, int season, string cycleTip, string weatherTip)
    {
        if (active)
        {
            if (_lastAnnouncedHouse == house && _lastAnnouncedSeason >= 0 && _lastAnnouncedSeason != season)
                _pendingBanner = $"{SeasonNames[season]} has arrived";
            _lastAnnouncedHouse = house;
            _lastAnnouncedSeason = season;
        }
        else if (house != _lastAnnouncedHouse)
        {
            _lastAnnouncedHouse = 0;
            _lastAnnouncedSeason = -1;
            _pendingBanner = null;
        }

        _active = active;
        _house = house;
        _season = season;
        _tooltip = active
            ? (!string.IsNullOrEmpty(cycleTip) && !string.IsNullOrEmpty(weatherTip)
                ? $"{cycleTip} · {weatherTip}"
                : !string.IsNullOrEmpty(cycleTip) ? cycleTip : weatherTip)
            : null;
    }

    public void UpdateAudio(IPluginAudioContext audio)
    {
        if (_state is { House: > 0 } s)
            audio.SetEnvironmentMuffle(s.AudioGain, s.AudioCutoff);
        else
            audio.SetEnvironmentMuffle(1f, 0f);
    }

    public void Render(IPluginRenderContext render)
    {
        if (_state is not { House: > 0 } s || render.Scene.DebugViewMode != 0)
            return;

        var scene = render.Scene;
        if (render.Stage == PluginRenderStage.PreLighting || !RenderStages.Contains(PluginRenderStage.PreLighting))
        {
            if (scene.TimeOverrideSeconds is float overrideSec)
                _runningClockSeconds = overrideSec;
            else
                _runningClockSeconds = (_runningClockSeconds + scene.DeltaSeconds) % 3600.0;
        }

        float seconds = scene.TimeOverrideSeconds ?? (float)_runningClockSeconds;
        bool lightingActive = _context.Blackboard.TryGetValue("lighting.active", out float la) && la > 0.5f;

        Vector3 sunInLot = scene.SunDirectionOverride ?? new Vector3(
            _context.Blackboard.TryGetValue("lighting.sunUp", out float su) ? su : s.SunUp,
            _context.Blackboard.TryGetValue("lighting.sunToward", out float st) ? st : s.SunToward,
            _context.Blackboard.TryGetValue("lighting.sunRight", out float sr) ? sr : s.SunRight);
        var up = new Vector3(0f, -0.8660254f, 0.5f);
        var toward = new Vector3(0f, 0.5f, 0.8660254f);
        var right = new Vector3(1f, 0f, 0f);
        Vector3 sun = up * sunInLot.X + toward * sunInLot.Y + right * sunInLot.Z;
        sun /= MathF.Max(1e-6f, sun.Length());

        float invSqrt2 = 1f / MathF.Sqrt(2f);
        var sunTiles = new Vector3((sunInLot.Y + sunInLot.Z) * invSqrt2, (sunInLot.Y - sunInLot.Z) * invSqrt2, sunInLot.X);
        sunTiles /= MathF.Max(1e-6f, sunTiles.Length());

        Vector2 wind = new(s.WindX, s.WindY);
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
        float glow = lightingActive && _context.Blackboard.TryGetValue("lighting.nightGlow", out float ng) ? ng : (lightingActive ? s.NightGlow : 0f);
        bool hasHeightFrame = scene.LotHeightFrame.HasValue;

        Span<Vector4> uniforms = stackalloc Vector4[UniformVec4Count];
        uniforms[0] = new Vector4(scene.ViewportOrigin.X, scene.ViewportOrigin.Y, scene.ViewportScale, s.GroundOffset);
        uniforms[1] = new Vector4(38f, lightingActive ? 1f : 0f, 0f, 16f);
        uniforms[2] = new Vector4(sun, s.SunReach);
        uniforms[3] = new Vector4(scene.CanvasSize.X, scene.CanvasSize.Y, 0f, 1f);
        uniforms[4] = new Vector4(scene.Lights.Count, 240f, 0f, 1f);
        uniforms[5] = new Vector4(10f, 0f, 0f, scene.IndoorBaseAltitude);
        uniforms[6] = scene.LotHeightFrame ?? new Vector4(0f, 0f, 1f, 0f);
        uniforms[7] = new Vector4(sunTiles, hasHeightFrame ? s.SunReach : 0f);
        uniforms[8] = new Vector4(s.CloudCover, s.CloudShade, scene.CameraOrientation, s.CloudHeight);
        uniforms[9] = new Vector4(drift.X, drift.Y, scene.LotWidth, scene.LotHeight);
        uniforms[10] = new Vector4(s.Precipitation, s.Wetness, seconds, hasHeightFrame ? glow : 0f);
        uniforms[11] = new Vector4(0f, slant, windStrength, s.DayProgress);
        uniforms[12] = new Vector4(s.SurfaceMode, s.SurfaceAmount, 0f, 0f);
        for (int i = 0; i < scene.Lights.Count && i < MaxLamps; i++)
        {
            var l = scene.Lights[i];
            uniforms[13 + i] = new Vector4(l.X, l.Y, l.Toward, l.SignedIntensity);
        }
        int printsOffset = 13 + MaxLamps;
        int extraOffset = printsOffset + MaxPrints;
        uniforms[extraOffset] = new Vector4(s.SeasonalTerrain ? 1f : 0f, s.SpringBloom, s.Snowfall, s.Fireflies);
        uniforms[extraOffset + 1] = new Vector4(s.Hail, s.Frost, s.Thunder, 0f);
        uniforms[extraOffset + 2] = scene.WorldShadowViewport ?? Vector4.Zero;
        uniforms[extraOffset + 3] = Vector4.Zero;

        if (render.Stage == PluginRenderStage.PreLighting)
        {
            RenderPreLighting(render, s, uniforms, printsOffset, extraOffset);
        }
        else if (render.Stage == PluginRenderStage.Atmosphere)
        {
            RenderAtmosphere(render, uniforms);
        }
    }

    private void RenderPreLighting(
        IPluginRenderContext render,
        SeasonsWireState s,
        Span<Vector4> uniforms,
        int printsOffset,
        int extraOffset)
    {
        var scene = render.Scene;
        var sceneColor = render.AcquireSceneBuffer(SceneBufferKind.SceneColor);
        var sceneDepth = render.AcquireSceneBuffer(SceneBufferKind.SceneDepth);
        var groundDepth = render.AcquireSceneBuffer(SceneBufferKind.GroundDepth);
        var heightMap = render.AcquireSceneBuffer(SceneBufferKind.LotHeightMap);
        var indoorMask = render.AcquireSceneBuffer(SceneBufferKind.IndoorArchitectureMask);
        var overheadMap = render.AcquireSceneBuffer(SceneBufferKind.OverheadMap);
        var simMask = render.AcquireSceneBuffer(SceneBufferKind.AvatarMask);

        bool displaced = s.DisplacedSurface && scene.LotHeightFrame.HasValue;
        bool winterTwoPass = s.SurfaceMode == 2;

        var sourceCopy = render.GetOrCreateTarget("source", sceneColor.Width, sceneColor.Height, PluginTextureFormat.ColorSrgb8, out _);
        var seasonDepth = render.GetOrCreateTarget("seasonDepth", sceneDepth.Width, sceneDepth.Height, PluginTextureFormat.Depth32Float, out _);
        render.CopyTexture(sceneColor, sourceCopy);
        render.CopyTexture(sceneDepth, seasonDepth);

        PluginTextureHandle? seasonStage = null;
        if (winterTwoPass)
        {
            var stageTex = render.GetOrCreateTarget("seasonStage", sceneColor.Width, sceneColor.Height, PluginTextureFormat.ColorSrgb8, out _);
            render.CopyTexture(sceneColor, stageTex);
            seasonStage = stageTex;
        }

        PluginTextureHandle spriteLayer = s.SurfaceMode is 1 or 2
            ? render.AcquireSceneBuffer(SceneBufferKind.DepthSpriteColor)
            : render.AcquireSceneBuffer(SceneBufferKind.EmptyTransparent);

        float alphaCutoff = s.SurfaceMode == 1
            ? (1f / 255f)
            : (s.SurfaceMode == 2 && displaced ? 0.68f : 0.18f);
        render.StampDepthSprites(seasonDepth, alphaCutoff);

        PluginTextureHandle trail = render.AcquireSceneBuffer(SceneBufferKind.EmptyIndoorMask);
        if (displaced && scene.LotWidth > 0 && scene.LotHeight > 0)
        {
            _trailFill += s.TrailRecovery * MathF.Min((float)scene.DeltaSeconds, 1f);
            float fill = _trailFill >= 0.02f ? _trailFill : 0f;
            if (fill > 0f)
                _trailFill = 0f;

            int trailW = (int)((scene.LotWidth + 2f * TrailMargin) * TrailTexels);
            int trailH = (int)((scene.LotHeight + 2f * TrailMargin) * TrailTexels);
            var t0 = render.GetOrCreateTarget("trail0", trailW, trailH, PluginTextureFormat.ColorSrgb8, out bool c0);
            var t1 = render.GetOrCreateTarget("trail1", trailW, trailH, PluginTextureFormat.ColorSrgb8, out bool c1);
            string key = $"{scene.House}-{scene.LotWidth}x{scene.LotHeight}";
            float trailState = 0f;
            if (c0 || c1 || !string.Equals(_trailKey, key, StringComparison.Ordinal))
            {
                _trailKey = key;
                trailState = -1f;
            }

            int take = Math.Min(MaxPrints, _pendingPrints.Count);
            for (int i = 0; i < MaxPrints; i++)
                uniforms[printsOffset + i] = i < take ? _pendingPrints[i] : Vector4.Zero;
            if (take > 0)
                _pendingPrints.RemoveRange(0, take);

            uniforms[12].Z = fill;
            uniforms[12].W = trailState;
            PluginTextureHandle prevTrail = _trailSlot == 0 ? t0 : t1;
            _trailSlot = 1 - _trailSlot;
            trail = _trailSlot == 0 ? t0 : t1;

            ReadOnlySpan<PluginTextureHandle> trailInput = [prevTrail];
            render.DrawFullscreenPass(
                ShaderDir + "trail.frag",
                trail,
                PluginBlendMode.Opaque,
                loadTarget: false,
                trailInput,
                MemoryMarshal.AsBytes(uniforms));

            while (_pendingPrints.Count > 0)
            {
                int more = Math.Min(MaxPrints, _pendingPrints.Count);
                for (int i = 0; i < MaxPrints; i++)
                    uniforms[printsOffset + i] = i < more ? _pendingPrints[i] : Vector4.Zero;
                _pendingPrints.RemoveRange(0, more);
                uniforms[12].Z = 0f;
                uniforms[12].W = 0f;
                prevTrail = trail;
                _trailSlot = 1 - _trailSlot;
                trail = _trailSlot == 0 ? t0 : t1;
                ReadOnlySpan<PluginTextureHandle> moreInput = [prevTrail];
                render.DrawFullscreenPass(
                    ShaderDir + "trail.frag",
                    trail,
                    PluginBlendMode.Opaque,
                    loadTarget: false,
                    moreInput,
                    MemoryMarshal.AsBytes(uniforms));
            }

            render.ShareTexture("seasons.trail", trail);
        }

        var seasonLift = render.GetOrCreateTarget("seasonLift", sceneColor.Width, sceneColor.Height, PluginTextureFormat.Float16Rgba, out _);
        if (winterTwoPass && seasonStage is { } stageTarget)
        {
            var stageLift = render.GetOrCreateTarget("seasonStageLift", sceneColor.Width, sceneColor.Height, PluginTextureFormat.Float16Rgba, out _);
            uniforms[extraOffset + 1].W = 0f;
            ReadOnlySpan<PluginTextureHandle> pass1Inputs =
            [
                seasonDepth, groundDepth, heightMap, indoorMask, sourceCopy, trail, overheadMap, simMask, spriteLayer,
            ];
            render.DrawFullscreenPass(
                ShaderDir + "season.frag",
                stageTarget,
                PluginBlendMode.AlphaPremultiplied,
                loadTarget: true,
                pass1Inputs,
                MemoryMarshal.AsBytes(uniforms),
                secondaryTarget: stageLift);

            uniforms[extraOffset + 1].W = 1f;
            ReadOnlySpan<PluginTextureHandle> pass2Inputs =
            [
                seasonDepth, groundDepth, heightMap, indoorMask, stageTarget, stageLift, sourceCopy, simMask, spriteLayer,
            ];
            render.DrawFullscreenPass(
                ShaderDir + "season.frag",
                sceneColor,
                PluginBlendMode.AlphaPremultiplied,
                loadTarget: true,
                pass2Inputs,
                MemoryMarshal.AsBytes(uniforms),
                secondaryTarget: seasonLift);
            uniforms[extraOffset + 1].W = 0f;
        }
        else
        {
            ReadOnlySpan<PluginTextureHandle> seasonInputs =
            [
                seasonDepth, groundDepth, heightMap, indoorMask, sourceCopy, trail, overheadMap, simMask, spriteLayer,
            ];
            render.DrawFullscreenPass(
                ShaderDir + "season.frag",
                sceneColor,
                PluginBlendMode.AlphaPremultiplied,
                loadTarget: true,
                seasonInputs,
                MemoryMarshal.AsBytes(uniforms),
                secondaryTarget: seasonLift);
        }

        if (displaced)
            render.ShareTexture("surface.lift", seasonLift);
    }

    private void RenderAtmosphere(IPluginRenderContext render, Span<Vector4> uniforms)
    {
        var sceneColor = render.AcquireSceneBuffer(SceneBufferKind.SceneColor);
        var sceneDepth = render.AcquireSceneBuffer(SceneBufferKind.SceneDepth);
        var groundDepth = render.AcquireSceneBuffer(SceneBufferKind.GroundDepth);
        var overheadMap = render.AcquireSceneBuffer(SceneBufferKind.OverheadMap);
        var trail = render.TryGetSharedTexture("seasons.trail", out var sharedTrail)
            ? sharedTrail
            : render.AcquireSceneBuffer(SceneBufferKind.EmptyIndoorMask);

        PluginTextureHandle lightingTerm;
        if (render.TryGetSharedTexture("lighting.term", out var sharedTerm))
        {
            lightingTerm = sharedTerm;
            float ambScale = sceneColor.Width > sharedTerm.Width ? 2f : 1f;
            uniforms[3].W = ambScale;
        }
        else
        {
            lightingTerm = render.UploadTexture("neutralTerm", 1, 1, NeutralLightingTermRgba);
            uniforms[3].W = 1f;
        }

        ReadOnlySpan<PluginTextureHandle> atmosInputs = [lightingTerm, sceneDepth, groundDepth, overheadMap, trail];
        render.DrawFullscreenPass(
            ShaderDir + "atmosphere.frag",
            sceneColor,
            PluginBlendMode.AlphaPremultiplied,
            loadTarget: true,
            atmosInputs,
            MemoryMarshal.AsBytes(uniforms));
    }

    public void BuildHud(IPluginUiContext ui)
    {
        if (!_imagesRegistered)
        {
            for (int i = 0; i < 4; i++)
                ui.RegisterImage($"season-{i}", 40, 40, SeasonIcons[i], logicalWidth: 10, logicalHeight: 10);
            _imagesRegistered = true;
        }

        if (_pendingBanner is { } banner && ui.InLiveMode)
        {
            ui.ShowToastBanner(banner, 4.5);
            _pendingBanner = null;
        }

        if (_active && _house > 0 && !ui.ControlPanelMinimized)
        {
            ui.DrawWidget(
                WidgetId,
                $"season-{_season}",
                PluginHudAnchor.ControlPanel,
                new PluginUiRect(149, 88, 10, 10),
                _tooltip);
        }
    }

    public bool OnHudClick(string widgetId)
    {
        if (!string.Equals(widgetId, WidgetId, StringComparison.Ordinal) || !_active)
            return false;
        _context.SendServerCommand("show-forecast");
        return true;
    }

    private static byte[] RenderSeasonIcon(int seasonIndex)
    {
        const int size1x = 10;
        const int scale = 4;
        const int fw = size1x * scale;
        const int fh = size1x * scale;
        byte[] rgba = new byte[fw * fh * 4];
        float aa = 1.4f / fw;

        static float SmoothStep(float edge0, float edge1, float x)
        {
            float t = Math.Clamp((x - edge0) / (edge1 - edge0), 0f, 1f);
            return t * t * (3f - 2f * t);
        }

        static float SdSeg(float px, float py, float ax, float ay, float bx, float by)
        {
            float pax = px - ax, pay = py - ay;
            float bax = bx - ax, bay = by - ay;
            float h = Math.Clamp((pax * bax + pay * bay) / MathF.Max(1e-6f, bax * bax + bay * bay), 0f, 1f);
            float dx = pax - bax * h, dy = pay - bay * h;
            return MathF.Sqrt(dx * dx + dy * dy);
        }

        static float SdSun(float u, float v)
        {
            float r = MathF.Sqrt(u * u + v * v);
            float d = r - 0.42f;
            for (int k = 0; k < 8; k++)
            {
                float a = k * MathF.PI / 4f;
                float ca = MathF.Cos(a), sa = MathF.Sin(a);
                d = MathF.Min(d, SdSeg(u, v, ca * 0.58f, sa * 0.58f, ca * 0.88f, sa * 0.88f) - 0.085f);
            }
            return d;
        }

        static float SdBlossom(float u, float v)
        {
            float d = 1e6f;
            for (int k = 0; k < 5; k++)
            {
                float a = k * (2f * MathF.PI / 5f) - MathF.PI / 2f;
                float px = MathF.Cos(a) * 0.42f, py = MathF.Sin(a) * 0.42f;
                d = MathF.Min(d, MathF.Sqrt((u - px) * (u - px) + (v - py) * (v - py)) - 0.34f);
            }
            float hole = 0.21f - MathF.Sqrt(u * u + v * v);
            return MathF.Max(d, hole);
        }

        static float SdLeaf(float u, float v)
        {
            float ru = (u + v) * 0.7071f;
            float rv = (-u + v) * 0.7071f;
            float body = MathF.Max(
                MathF.Sqrt((ru - 0.38f) * (ru - 0.38f) + rv * rv) - 0.84f,
                MathF.Sqrt((ru + 0.38f) * (ru + 0.38f) + rv * rv) - 0.84f);
            float stem = SdSeg(u, v, -0.78f, 0.78f, -0.30f, 0.30f) - 0.085f;
            float vein = 0.055f - SdSeg(u, v, -0.32f, 0.32f, 0.36f, -0.36f);
            return MathF.Min(MathF.Max(body, vein), stem);
        }

        static float SdSnowflake(float u, float v)
        {
            float d = 1e6f;
            for (int k = 0; k < 3; k++)
            {
                float a = k * (MathF.PI / 3f);
                float ca = MathF.Cos(a), sa = MathF.Sin(a);
                d = MathF.Min(d, SdSeg(u, v, -ca * 0.86f, -sa * 0.86f, ca * 0.86f, sa * 0.86f) - 0.085f);
                for (int s = -1; s <= 1; s += 2)
                {
                    float bx = ca * 0.52f * s, by = sa * 0.52f * s;
                    float a1 = a + 0.72f, a2 = a - 0.72f;
                    d = MathF.Min(d, SdSeg(u, v, bx, by, bx + MathF.Cos(a1) * 0.28f * s, by + MathF.Sin(a1) * 0.28f * s) - 0.065f);
                    d = MathF.Min(d, SdSeg(u, v, bx, by, bx + MathF.Cos(a2) * 0.28f * s, by + MathF.Sin(a2) * 0.28f * s) - 0.065f);
                }
            }
            return d;
        }

        for (int py = 0; py < fh; py++)
        {
            float v = ((py + 0.5f) / fh) * 2f - 1f;
            for (int px = 0; px < fw; px++)
            {
                float u = ((px + 0.5f) / fw) * 2f - 1f;
                float sd = seasonIndex switch
                {
                    0 => SdBlossom(u, v),
                    1 => SdSun(u, v),
                    2 => SdLeaf(u, v),
                    _ => SdSnowflake(u, v),
                };
                float fill = SmoothStep(aa, -aa, sd);
                if (fill <= 0.001f) continue;
                int o = (py * fw + px) * 4;
                rgba[o] = 0x29;
                rgba[o + 1] = 0xE6;
                rgba[o + 2] = 0x5E;
                rgba[o + 3] = (byte)Math.Clamp((int)MathF.Round(fill * 255f), 0, 255);
            }
        }

        return rgba;
    }
}
