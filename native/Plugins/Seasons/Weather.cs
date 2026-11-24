namespace Local.Seasons;

// Weather is a deterministic function of the neighborhood seed and calendar day, using absolute hour
// timestamps that allow weather fronts to span across midnight.
public sealed partial class SeasonsPlugin
{
    // The cut time specifies when a weather front has been dissipated, fading precipitation linearly over
    // the preceding 90 minutes.
    private sealed record Weather(int Sky, float Start, float Hours, float Intensity, float Cut = float.MaxValue, string Kind = "");
    private sealed record ClimateRules(float SnowRate, float SunnyMelt, float BasePack, float MaxPack, float SpringMelt, float WinterWet, float Shift);
    private static readonly Dictionary<string, ClimateRules> Climates = new()
    {
        ["mild"] = new(0.6f, 0.15f, 0.2f, 1.2f, 1.5f, 0.25f, 10),
        ["temperate"] = new(1, 0.08f, 0.3f, 2, 2.5f, 0.35f, 0),
        ["harsh"] = new(1.4f, 0.04f, 0.5f, 2, 4, 0.45f, -12),
    };
    private string ClimateName => context.NeighborhoodValues.TryGetValue("climate", out var name) && Climates.ContainsKey(name) ? name : configuration.Climate;
    private ClimateRules Rules => Climates[ClimateName];

    private Weather WeatherAt(int day)
    {
        if (weatherOverride is { } kind) return kind switch
        {
            "clear" => new(0, 0, 0, 0),
            "cloud" => new(1, 0, 0, 0),
            "rain" => new(2, 0, 24, 0.56f, Kind: "rain"),
            "thunder" => new(2, 0, 24, 0.89f, Kind: "thunder"),
            "snow" => new(2, 0, 24, 0.67f, Kind: "snow"),
            _ => Natural(day)
        };
        return Natural(day);
    }

    private Weather Natural(int day)
    {
        if (day < 0) return new(0, 0, 0, 0);
        var season = Season(day);
        if (season == 3 && Into(day) == 0) return new(2, 7, 10, 0.55f);
        var roll = RandomValue(day, 1);
        var (sun, cloud) = season switch
        {
            0 => (0.42f, 0.16f),
            1 => (0.68f, 0.14f),
            2 => (0.28f, 0.14f),
            _ => (Math.Max(0.15f, 0.50f - Rules.WinterWet), 0.12f),
        };
        var sky = roll < sun ? 0 : roll < sun + cloud ? 1 : 2;
        var hours = season is 2 or 3
            ? 5f + RandomValue(day, 3) * 8f
            : 4f + RandomValue(day, 3) * 6f;
        var intensity = season is 2 or 3
            ? 0.35f + RandomValue(day, 4) * 0.55f
            : 0.28f + RandomValue(day, 4) * 0.55f;
        return new(sky, 1f + RandomValue(day, 2) * 19f, hours, intensity);
    }

    private static float Smooth(float x) { x = Math.Clamp(x, 0, 1); return x * x * (3 - 2 * x); }
    private (float Start, float End) Front(int day)
    {
        var weather = WeatherAt(day);
        return (day * 24 + weather.Start, day * 24 + Math.Min(weather.Start + weather.Hours, weather.Cut));
    }

    // Precipitation intensity ramps up linearly over 90 minutes, sustains peak intensity, and tapers off
    // over the same duration.
    private float FrontRain(int day, float time)
    {
        var weather = WeatherAt(day);
        if (weather.Sky != 2) return 0;
        var (start, end) = Front(day);
        var ramp = Math.Min(1.5f, weather.Hours / 3);
        var cleared = weather.Cut < float.MaxValue ? Smooth((end - time) / 1.5f) : 1;
        return weather.Intensity * Math.Min(Smooth((time - start) / ramp), Math.Min(Smooth((start + weather.Hours - time) / ramp), cleared));
    }

    private float Precipitation(float time)
    {
        if (weatherOverride is { } kind)
        {
            var elapsed = Math.Max(0f, time - (weatherOverrideStartTime ?? time));
            return kind switch
            {
                "rain" => 0.11f + 0.45f * Smooth(elapsed / 1.2f),
                "thunder" => 0.16f + 0.73f * Smooth(elapsed / 1.2f),
                "snow" => 0.11f + 0.56f * Smooth(elapsed / 1.5f),
                _ => 0f,
            };
        }
        var day = (int)MathF.Floor(time / 24);
        return Math.Max(FrontRain(day, time), FrontRain(day - 1, time));
    }

    private string Falling(int front) => WeatherAt(front).Kind switch
    {
        "rain" or "thunder" or "snow" => WeatherAt(front).Kind,
        _ => weatherOverride == "snow" || Season(Math.Max(0, front)) == 3 ? "snow" : "rain"
    };
    private string FallingAt(float time)
    {
        var day = (int)MathF.Floor(time / 24);
        var front = Front(day).Start <= time && Front(day).End >= time ? day : day - 1;
        return Falling(front);
    }

    // Cloud cover only appears during passing cloud banks (cloudy days) and around weather fronts,
    // building smoothly beforehand and clearing afterward so sunny days stay clear.
    private float CloudCover(float time)
    {
        if (weatherOverride is { } kind)
        {
            var elapsed = Math.Max(0f, time - (weatherOverrideStartTime ?? time));
            return kind switch
            {
                "clear" => 0.35f * (1f - Smooth(elapsed / 0.75f)),
                "cloud" => 0.20f + 0.45f * Smooth(elapsed / 0.75f),
                "rain" or "thunder" or "snow" => 0.25f + 0.60f * Smooth(elapsed / 1.0f),
                _ => 0f,
            };
        }
        var day = (int)MathF.Floor(time / 24);
        float Gathered(int d)
        {
            var weather = WeatherAt(d);
            if (weather.Sky == 0) return 0;
            if (weather.Sky == 1)
            {
                if (weather.Hours <= 0) return 0.6f;
                var (cStart, cEnd) = Front(d);
                return 0.6f * Math.Min(Smooth((time - cStart + 1.5f) / 1.5f), Smooth((cEnd + 1.5f - time) / 1.5f));
            }
            var (start, end) = Front(d);
            return 0.85f * Math.Min(Smooth((time - start + 1.5f) / 1.5f), Smooth((end + 1.5f - time) / 1.5f));
        }
        return Math.Max(Gathered(day + 1), Math.Max(Gathered(day), Gathered(day - 1)));
    }

    // Ground saturation builds gradually over two hours of rainfall — starting as dark damp patches and
    // spreading across the ground — and dries at season-dependent rates.
    private float Wetness(float time)
    {
        if (weatherOverride is { } kind)
        {
            var elapsed = Math.Max(0f, time - (weatherOverrideStartTime ?? time));
            return kind switch
            {
                "rain" => Math.Clamp(weatherOverrideBaseWetness + elapsed / 2.0f, 0f, 0.92f),
                "thunder" => Math.Clamp(weatherOverrideBaseWetness + elapsed / 1.4f, 0f, 1.0f),
                "clear" => Math.Max(0f, weatherOverrideBaseWetness - elapsed / 1.8f),
                "cloud" => Math.Max(0f, weatherOverrideBaseWetness - elapsed / 2.6f),
                "snow" => 0f,
                _ => 0f,
            };
        }
        var day = (int)MathF.Floor(time / 24);
        var drying = Season(Math.Max(0, day)) == 1 ? 1.5f : 3;
        float Of(int front)
        {
            var weather = WeatherAt(front);
            if (weather.Sky != 2 || Falling(front) is not ("rain" or "thunder")) return 0;
            var (start, end) = Front(front);
            return Math.Min(1, 0.5f + weather.Intensity) * Math.Min(Smooth((time - start - 0.20f) / 2.0f), 1 - Math.Clamp((time - end) / drying, 0, 1));
        }
        return Math.Max(Of(day), Of(day - 1));
    }

    // Calculates snowfall accumulation for a winter front as duration multiplied by intensity divided by
    // eight, scaled by the climate factor.
    private float Fallen(int front, int firstWinterDay, float time)
    {
        var weather = WeatherAt(front);
        if (weather.Sky != 2 || Falling(front) != "snow") return 0;
        var (start, end) = Front(front);
        return Rules.SnowRate * weather.Intensity * Math.Clamp(time - start, 0, end - start) / 8;
    }

    private float SnowPack(int day, float hour)
    {
        var currentTime = day * 24 + hour;
        if (weatherOverride is { } kind)
        {
            var elapsed = Math.Max(0f, currentTime - (weatherOverrideStartTime ?? currentTime));
            if (kind == "snow")
                return Math.Clamp(weatherOverrideBaseSnow + elapsed * 0.24f, 0f, Rules.MaxPack);
            if (kind is "clear" or "cloud" or "rain" or "thunder")
                return Math.Max(0f, weatherOverrideBaseSnow - elapsed * (kind == "rain" || kind == "thunder" ? 0.55f : 0.35f));
        }
        var first = day - Into(day);
        var isWinter = Season(day) == 3;
        float Laid(int on, float until) => Fallen(on, first, until) - Fallen(on, first, on * 24) + Fallen(on - 1, first, until) - Fallen(on - 1, first, on * 24);
        var pack = 0f;
        for (var past = first; past < day; past++)
        {
            var gained = Laid(past, (past + 1) * 24);
            var minKeep = isWinter && (pack + gained) > 0f ? Math.Min(pack + gained, Rules.BasePack) : 0f;
            pack = Math.Clamp(pack + gained - (WeatherAt(past).Sky == 0 ? Rules.SunnyMelt : 0), minKeep, Rules.MaxPack);
        }
        var todaySnow = Math.Clamp(pack + Laid(day, currentTime), 0f, Rules.MaxPack);
        if (isWinter && DaysPerSeason >= 2)
        {
            var winterFrac = (Into(day) + hour / 24f) / DaysPerSeason;
            var activelySnowing = Precipitation(currentTime) > 0.02f && FallingAt(currentTime) == "snow";
            if (winterFrac > 0.76f && !activelySnowing)
            {
                todaySnow *= 1f - Smooth((winterFrac - 0.76f) / 0.24f) * 0.36f;
            }
        }
        return todaySnow;
    }

    // Interpolates smoothly from zero at midsummer to one at midwinter to modulate daylight duration.
    private float Winterness(float dayTime)
    {
        var year = 4f * DaysPerSeason;
        return (1 - MathF.Cos(2 * MathF.PI * (dayTime - DaysPerSeason / 2f) / year)) / 2;
    }

    private (float Rise, float Set) Daylight(float dayTime, bool seasonal)
    {
        if (!seasonal) return (6, 20);
        var winter = Winterness(dayTime);
        return (5.5f + 1.5f * winter, 21 - 3 * winter);
    }

    // Calculates daily high temperatures based on the seasonal climate baseline, diurnal variation, and
    // cloud or precipitation cooling.
    private float HighOf(int day)
    {
        var winter = Winterness(day + 0.5f);
        var sky = WeatherAt(day).Sky;
        return 84 - 50 * winter + Rules.Shift * winter + (RandomValue(day, 5) - 0.5f) * 12 - sky * 4;
    }

    private float LowOf(int day) => HighOf(day) - (WeatherAt(day).Sky == 0 ? 20 : 12);

    private float Temperature(float time, bool seasonal)
    {
        var day = (int)MathF.Floor(time / 24);
        var hour = time - day * 24;
        var rise = Daylight(day, seasonal).Rise;
        if (hour < rise) return HighOf(day - 1) + (LowOf(day) - HighOf(day - 1)) * Smooth((hour + 9) / (rise + 9));
        if (hour < 15) return LowOf(day) + (HighOf(day) - LowOf(day)) * Smooth((hour - rise) / (15 - rise));
        return HighOf(day) + (LowOf(day + 1) - HighOf(day)) * Smooth((hour - 15) / (24 + Daylight(day + 1, seasonal).Rise - 15));
    }
}
