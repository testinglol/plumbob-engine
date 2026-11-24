using System.Text.Json;
using SimsNative.Plugins;

namespace Local.Seasons;

public sealed class SeasonsClientPlugin : ISimsClientPlugin
{
    private const string WidgetId = "season-indicator";
    private static readonly string[] SeasonNames = ["Spring", "Summer", "Autumn", "Winter"];
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

    public void Initialize(IClientPluginContext context) => _context = context;

    public void OnServerState(ReadOnlySpan<byte> state)
    {
        try
        {
            using var doc = JsonDocument.Parse(state.ToArray());
            var root = doc.RootElement;
            bool active = root.TryGetProperty("active", out var aEl) && aEl.ValueKind == JsonValueKind.True;
            int house = root.TryGetProperty("house", out var hEl) && hEl.TryGetInt32(out int h) ? h : 0;
            int season = root.TryGetProperty("season", out var sEl) && sEl.TryGetInt32(out int s) ? ((s % 4) + 4) % 4 : 0;
            string cycleTip = root.TryGetProperty("cycleTooltip", out var cEl) ? cEl.GetString() ?? string.Empty : string.Empty;
            string weatherTip = root.TryGetProperty("weatherTooltip", out var wEl) ? wEl.GetString() ?? string.Empty : string.Empty;

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
        catch (JsonException)
        {
        }
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
