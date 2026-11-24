using System.Globalization;
using System.Text.Json;
using SimsNative.Plugins;

namespace Local.Seasons;

public sealed partial class SeasonsPlugin : ISimsPlugin, IPluginEnvironmentProvider
{
    private sealed record Configuration(int DaysPerSeason, int InitialDay, Dictionary<string, float>? Lighting = null, string Climate = "temperate");
    private sealed record Legacy(int Days, int Seed);
    private IPluginContext context = null!;
    private Configuration configuration = new(7, 0);
    private int? lastDay;
    private int lastHouse;
    private int Day { get => int.Parse(context.NeighborhoodValues["day"], CultureInfo.InvariantCulture); set => context.NeighborhoodValues["day"] = value.ToString(CultureInfo.InvariantCulture); }
    private int Seed => int.Parse(context.NeighborhoodValues["seed"], CultureInfo.InvariantCulture);
    private const string Assets = "Downloads/local.seasons/";
    // Igloo objects query global 428 to check for a snowy vacation lot and melt if false, requiring home
    // lots to report true while snow cover persists.
    private static readonly uint[] SnowLotObjects = [0xE8B4C5C2, 0xECC356FA, 0xEAC98806, 0xEF2F5FEC, 0xE54B255F, 0xE98BF6D4, 0xED83553C, 0xE5CBDCDE,
        0xE5D851AB, 0xED2F3ED9, 0xEF3AEAF3, 0xEFD201FA, 0xE5351007, 0xE75D2262, 0xEC14E825, 0xE053CAF9, 0xE685E2EB];

    public void Initialize(IPluginContext context)
    {
        this.context = context;
        configuration = JsonSerializer.Deserialize<Configuration>(context.ReadPluginData("seasons.json"), new JsonSerializerOptions { PropertyNameCaseInsensitive = true }) ?? throw new InvalidDataException("Missing Seasons configuration");
        if (configuration.DaysPerSeason is < 1 or > 90 || configuration.InitialDay < 0 || configuration.Climate is not { } name || !Climates.TryGetValue(name, out _))
            throw new InvalidDataException("Invalid Seasons configuration");
        if (context.NeighborhoodValues.Count == 0)
        {
            Legacy? legacy = null;
            try
            {
                if (context.ReadLegacyNeighborhoodData("Seasons.json") is { } bytes) legacy = JsonSerializer.Deserialize<Legacy>(bytes);
            }
            catch (JsonException) { }
            Day = legacy is { Days: >= 0, Seed: > 0 } ? legacy.Days : configuration.InitialDay;
            context.NeighborhoodValues["seed"] = (legacy is { Days: >= 0, Seed: > 0 } ? legacy.Seed : Random.Shared.Next(1, int.MaxValue)).ToString(CultureInfo.InvariantCulture);
        }
        if (Day < 0 || Seed <= 0) throw new InvalidDataException("Invalid Seasons calendar");

    }

    public byte[]? SaveState() => SaveExposure();
    public void LoadState(int savedStateVersion, byte[] data)
    {
        lastDay = null;
        lastHouse = 0;
        published = null;
        weatherOverride = null;
        weatherOverrideStartTime = null;
        weatherOverrideBaseSnow = 0f;
        weatherOverrideBaseWetness = 0f;
        lastRawSnow = 0f;
        lastRawWetness = 0f;
        ResetExposure();
        ResetAutumnFlora();
        restoreNeighborhoodExposure = false;
        snowAttributesAt = null;
        walkers.Clear();
        footprints.Clear();
        pendingSnowballFights.Clear();
        pendingSnowballHouse = -1;
        if (!context.NeighborhoodValues.ContainsKey("day"))
            Day = configuration.InitialDay;
        if (!context.NeighborhoodValues.ContainsKey("seed"))
            context.NeighborhoodValues["seed"] = Random.Shared.Next(1, int.MaxValue).ToString(CultureInfo.InvariantCulture);
        RestoreExposure(savedStateVersion, data);
    }
    private int DaysPerSeason => context.NeighborhoodValues.TryGetValue("daysPerSeason", out var value)
        && int.TryParse(value, out var days) && days is >= 1 and <= 90 ? days : configuration.DaysPerSeason;
    private int Season(int day) => (day / DaysPerSeason + 1) % 4;
    private int Into(int day) => day % DaysPerSeason;
    private static bool Seasonal(int house) => house > 0 && !(house is >= 21 and <= 30 or >= 40 and <= 48 or >= 81 and <= 99);

    private float RandomValue(int day, ulong salt)
    {
        unchecked
        {
            var value = (ulong)Seed * 0x9E3779B97F4A7C15UL ^ (ulong)day * 0xBF58476D1CE4E5B9UL ^ salt * 0x94D049BB133111EBUL;
            value ^= value >> 31;
            value *= 0xD6E8FEB86659FD93UL;
            value ^= value >> 32;
            return (value >> 40) / (float)(1 << 24);
        }
    }

    public PluginEnvironment? GetEnvironment(PluginEnvironmentClock clock)
    {
        if (clock.House > 0)
        {
            var day = (clock.Month - 1) * 30 + clock.DayOfMonth - 1;
            if (clock.House == lastHouse && lastDay is int last)
            {
                var passed = ((day - last) % 360 + 360) % 360;
                if (passed is >= 1 and <= 2) Day = checked(Day + passed);
            }
            if (clock.House != lastHouse) { walkers.Clear(); footprints.Clear(); ResetAutumnFlora(); }
            lastDay = day;
            lastHouse = clock.House;
        }
        var dayIndex = Day;
        var hour = Math.Clamp(clock.Minutes, 0, 1439) / 60f;
        var time = dayIndex * 24 + hour;
        if (weatherOverride is not null)
        {
            if (weatherOverrideStartTime is null || time < weatherOverrideStartTime.Value)
            {
                weatherOverrideStartTime = time;
                weatherOverrideBaseSnow = lastRawSnow;
                weatherOverrideBaseWetness = lastRawWetness;
            }
        }
        var season = Season(dayIndex);
        var into = Into(dayIndex);
        var rain = QuantizePrecipitation(Precipitation(time));
        var cover = CloudCover(time);
        var (mode, amount, wetness) = Ground(dayIndex, hour);
        var seasonal = clock.House == 0 ? clock.MapMode == 1 : Seasonal(clock.House);
        var vacationWinter = clock.House is >= 40 and <= 42;
        if (!seasonal) { mode = 0; amount = 0; rain = 0; wetness = 0; cover = 0; }
        if (vacationWinter) { mode = 2; amount = 1.4f; rain = 0.35f; cover = 0.48f; wetness = 0; }
        Track(clock.Actors, mode == 2 && clock.House > 0);
        var home = Seasonal(clock.House);
        var (rise, set) = Daylight(time / 24, home);
        if (clock.House > 0)
        {
            PublishForecast(dayIndex, hour, home, mode == 2);
            PublishSeasonLength();
        }
        var daytime = hour >= rise && hour < set;
        var fallingSnow = vacationWinter ? rain > 0.02f : (rain > 0.02f && FallingAt(time) == "snow");
        var icon = rain > 0.02f ? (fallingSnow ? "snow" : "rain") : cover < 0.35f ? daytime ? "sun" : "moon" : "cloud";
        var tempF = vacationWinter ? 24f + 4f * MathF.Sin((hour - 9f) * MathF.PI / 12f) : Temperature(time, true);
        var sky = vacationWinter ? $"Snowing, {Degrees(tempF)}" : $"{Capital(Condition(time, mode == 2, daytime))}, {Degrees(tempF)}";
        var muffle = mode == 2 ? Math.Min(1, 0.6f * Math.Min(1, amount) + 0.25f * Math.Max(0, amount - 1) + 0.3f * rain) : 0;
        var parameters = vacationWinter
            ? Lighting(hour, rise, set, 0.42f, 0.08f, 3)
            : Lighting(hour, rise, set, cover, rain, seasonal ? season : 1);
        var springBloom = seasonal && season == 0 && mode == 0
            ? Smooth(1f - MathF.Abs((into + hour / 24f) / DaysPerSeason - 0.5f) * 1.4f) * 0.85f + 0.15f
            : 0f;
        var eveningDist = hour >= 19.5f ? Math.Clamp((hour - 19.5f) / 2f, 0f, 1f) : hour < 4.5f ? Math.Clamp((4.5f - hour) / 2f, 0f, 1f) : 0f;
        var fireflyNight = RandomValue(dayIndex, 19) < 0.15f;
        var fireflies = seasonal && season == 1 && mode == 0 && rain <= 0.02f && cover < 0.25f && tempF >= 68f && fireflyNight ? eveningDist * 0.85f : 0f;
        var hail = seasonal && season is 0 or 2 && rain > 0.68f && !fallingSnow ? 0.6f : 0f;
        var frost = vacationWinter ? 0.55f : 0f;
        var seasonFrac = (into + hour / 24f) / Math.Max(1, DaysPerSeason);
        var foliageStage = 0;
        if (seasonal)
        {
            if (vacationWinter)
            {
                foliageStage = 9;
            }
            else if (season == 2)
            {
                foliageStage = mode == 2 && amount >= 0.70f
                    ? 9
                    : Math.Clamp((int)(seasonFrac * 9f), 0, 8);
            }
            else if (season == 3)
            {
                foliageStage = seasonFrac < 0.70f ? 9
                    : seasonFrac < 0.80f ? 8
                    : seasonFrac < 0.90f ? 7
                    : 6;
            }
            else if (season == 0)
            {
                foliageStage = seasonFrac < 0.10f ? 5
                    : seasonFrac < 0.20f ? 4
                    : seasonFrac < 0.30f ? 3
                    : seasonFrac < 0.40f ? 2
                    : seasonFrac < 0.50f ? 1
                    : 0;
            }
        }
        parameters["grassQuality"] = seasonal ? 1f : 0f;
        parameters["springBloom"] = springBloom;
        parameters["snowfall"] = rain > 0.01f ? (fallingSnow ? 1f : -1f) : 0f;
        parameters["fireflies"] = fireflies;
        parameters["hail"] = hail;
        parameters["frost"] = frost;
        parameters["thunder"] = seasonal && rain > 0.25f && FallingAt(time) == "thunder" ? 1f : 0f;
        parameters["foliageStage"] = foliageStage;

        var autumnLeavesAirborne = seasonal && mode == 1 && amount > 0.25f && rain <= 0.02f;

        if (mode == 1 && home && clock.House > 0)
        {
            if (lastAutumnEnvMode >= 0 && lastAutumnEnvMode != 1)
            {
                autumnFloraHouse = 0;
                autumnFloraHash = 0;
            }
            TryRefreshAutumnFlora(clock.House);
        }
        lastAutumnEnvMode = mode;
        var useAutumnFlora = mode == 1 && home && clock.House > 0 && autumnFloraHouse == clock.House;

        return new PluginEnvironment
        {
            Parameters = parameters,
            SurfaceMode = mode, SurfaceAmount = amount, CloudCover = cover, Precipitation = rain, Wetness = wetness,
            // Winter clothing is worn throughout winter, whenever snow cover is present, or on freezing mornings.
            OutdoorSuit = home && (season == 3 || mode == 2 && (amount > 0 || rain > 0) || tempF <= 42f) ? 17 : null,
            AudioGain = 1 - 0.30f * muffle, AudioCutoff = muffle <= 0.01f ? 0 : 20000 * MathF.Pow(3200f / 20000, muffle),
            Atmosphere = rain > 0 || (wetness > 0 && mode != 2) || fireflies > 0.05f || autumnLeavesAirborne,
            SnowLotObjects = (home || vacationWinter) && mode == 2 && amount > 0 ? SnowLotObjects : [],
            DisplacedSurface = mode == 2 || useAutumnFlora, TrailRecovery = mode == 2 ? rain / 60 : 0, Footprints = useAutumnFlora ? autumnPrints.ToArray() : footprints.ToArray(),
            Indicator = seasonal && clock.House > 0 ? new(season, 4, Assets + "ui/cycle.tga", Assets + "ui/" + icon + ".tga", sky, $"{SeasonNames[season]} — day {into + 1} of {DaysPerSeason}{(Holiday(dayIndex) is { } holiday ? " · " + holiday : "")}", Assets + "ui/window.tga", Assets + "ui/drum.tga") : null,
            Shaders = new[] { "ambient.frag", "ambientBlur.frag", "atmosphere.frag", "season.frag", "trail.frag", "groundDepth.vert", "heightScatter.vert", "depthOnly.frag", "fullscreen.vert", "terrain.frag" }
                .ToDictionary(name => name.Split('.')[0], name => Assets + "shaders/" + name)
        };
    }

    private static readonly float[] SnowStageAmounts =
    [
        0.00f,
        0.08f,
        0.17f,
        0.27f,
        0.39f,
        0.53f,
        0.70f,
        0.92f,
        1.16f,
        1.40f,
    ];

    private static float QuantizeSnow(float raw)
    {
        if (raw <= 0.02f) return 0f;
        var stage = raw < 0.12f ? 1
            : raw < 0.22f ? 2
            : raw < 0.33f ? 3
            : raw < 0.46f ? 4
            : raw < 0.61f ? 5
            : raw < 0.81f ? 6
            : raw < 1.04f ? 7
            : raw < 1.28f ? 8
            : 9;
        return SnowStageAmounts[stage];
    }

    private static float QuantizePrecipitation(float raw)
    {
        if (raw <= 0.02f) return 0f;
        var stage = Math.Clamp((int)MathF.Round(Math.Clamp(raw, 0f, 1f) * 9f), 1, 9);
        return stage / 9f;
    }

    private static float QuantizeWetness(float raw)
    {
        if (raw <= 0.02f) return 0f;
        var stage = Math.Clamp((int)MathF.Ceiling(Math.Clamp(raw, 0f, 1f) * 9f), 1, 9);
        return stage / 9f;
    }

    private (int Mode, float Amount, float Wetness) Ground(int day, float hour)
    {
        var season = Season(day);
        var into = Into(day);
        var rawWetness = Wetness(day * 24 + hour);
        var rawSnow = SnowPack(day, hour);
        lastRawWetness = rawWetness;
        lastRawSnow = rawSnow;
        var wetness = QuantizeWetness(rawWetness);
        var snow = QuantizeSnow(rawSnow);
        if (snow > 0 && (weatherOverride is not null || season != 3 || into > 0 || hour >= WeatherAt(day).Start)) return (2, snow, 0);
        var progress = into + hour / 24;
        if (season == 2)
        {
            var autumnStage = MathF.Round(Math.Clamp(0.28f + progress / 2.4f, 0f, 1f) * 9f) / 9f;
            return (1, autumnStage, wetness);
        }
        if (season == 3) return (2, snow, 0);
        if (season == 0)
        {
            var previous = day - into - 1;
            var left = previous >= 0 && Season(previous) == 3 ? SnowPack(previous, 24) : 0;
            var melt = Math.Max(0, 1 - progress / Rules.SpringMelt);
            var springSnow = QuantizeSnow(left * melt);
            if (springSnow > 0) return (2, springSnow, QuantizeWetness(Math.Max(rawWetness, 0.6f * melt)));
        }
        return (0, 0, wetness);
    }

    // Sunlight follows a camera-relative arc between sunrise and sunset, with seasonal sun elevation and
    // color warmth tuned per season, smooth 90-minute dawn/dusk transitions, and rain/storm dimming that
    // eliminates direct sunlight and sun shadows while boosting lamps.
    private Dictionary<string, float> Lighting(float hour, float rise, float set, float cover, float rain, int season)
    {
        var values = new Dictionary<string, float>(configuration.Lighting ?? throw new InvalidDataException("Missing lighting configuration"));
        float Value(string key) => values[key];
        var sunRise = rise - 0.75f;
        var day = (hour - sunRise) / (set - sunRise);
        var daylight = day > 0 && day < 1;
        var light = Smooth((hour - rise + 0.75f) / 1.5f) * Smooth((set + 0.75f - hour) / 1.5f);
        var elevationScale = season switch { 0 => 0.95f, 1 => 1.05f, 2 => 0.86f, _ => 0.72f };
        var elevation = (0.14f + 0.62f * MathF.Sin(MathF.PI * day)) * 0.5f * MathF.PI * 0.8f * elevationScale;
        var azimuth = MathF.Atan2(0.2f, -1) + (MathF.Atan2(1, 0.2f) - MathF.Atan2(0.2f, -1)) * day;
        var ground = MathF.Cos(elevation);
        values["sunUp"] = MathF.Sin(elevation);
        values["sunToward"] = ground * (MathF.Cos(azimuth) + MathF.Sin(azimuth)) / MathF.Sqrt(2);
        values["sunRight"] = ground * (MathF.Cos(azimuth) - MathF.Sin(azimuth)) / MathF.Sqrt(2);
        var strength = daylight ? Math.Min(1, Math.Min(day / 0.035f, (1 - day) / 0.06f)) : 0;
        var overcast = Math.Clamp((cover - 0.35f) / 0.55f, 0, 1);
        var precipBlock = Smooth(rain / 0.22f);
        var directSun = strength * (1 - 0.82f * overcast) * (1 - precipBlock);
        values["shadow"] *= directSun;
        values["windowSun"] *= directSun;
        values["reach"] = MathF.Min(34f, MathF.Max(values["reach"], 10.0f) / MathF.Max(0.22f, values["sunUp"]));
        var gloom = Math.Clamp(overcast * 0.85f + precipBlock * 0.35f, 0, 1);
        var lampScale = 1 + (Math.Max(0.25f, 0.25f + 0.52f * gloom) - 1) * light;
        values["base"] = Value("night") + (1 - 0.16f * overcast - 0.12f * precipBlock - Value("night")) * light;
        values["lampGain"] *= lampScale;
        values["glow"] = Math.Clamp((lampScale - 0.25f) / 0.75f, 0, 1);
        var seasonalTint = season switch
        {
            0 => 1.05f,
            1 => 1.00f,
            2 => day > 0.55f ? 1.18f : 1.08f,
            _ => 0.78f,
        };
        values["tint"] *= (1 - overcast) * (1 - precipBlock) * seasonalTint;
        values["dayProgress"] = Math.Clamp(day, 0f, 1f);
        return values;
    }

    private sealed record Walker(float X, float Y, float Travelled, bool Right);
    private readonly Dictionary<int, Walker> walkers = [];
    private readonly Queue<PluginFootprint> footprints = [];
    private long sequence;
    private void Track(PluginActor[] actors, bool active)
    {
        if (!active) { walkers.Clear(); footprints.Clear(); return; }
        foreach (var actor in actors)
        {
            if (actor.Level != 1 || actor.Swimming) { walkers.Remove(actor.Id); continue; }
            if (!walkers.TryGetValue(actor.Id, out var walker)) { walkers[actor.Id] = new(actor.X, actor.Y, 0, false); continue; }
            var dx = actor.X - walker.X;
            var dy = actor.Y - walker.Y;
            var length = MathF.Sqrt(dx * dx + dy * dy);
            if (length < 0.0001f) continue;
            if (length > 3) { walkers[actor.Id] = new(actor.X, actor.Y, 0, false); continue; }
            var stride = actor.Pet ? 0.2f : actor.Child ? 0.3f : 0.4f;
            var foot = actor.Pet ? 2 : actor.Child ? 0.75f : 1;
            var along = stride - walker.Travelled;
            var right = walker.Right;
            for (; along <= length; along += stride)
            {
                right = !right;
                footprints.Enqueue(new(++sequence, walker.X + dx * along / length, walker.Y + dy * along / length, MathF.Atan2(dy, dx), right ? foot : -foot));
                while (footprints.Count > 64) footprints.Dequeue();
            }
            walkers[actor.Id] = new(actor.X, actor.Y, stride - (along - length), right);
        }
        foreach (var id in walkers.Keys.Where(id => !actors.Any(actor => actor.Id == id)).ToArray()) walkers.Remove(id);
    }
}
