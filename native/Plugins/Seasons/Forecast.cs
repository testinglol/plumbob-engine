using System.Globalization;

namespace Local.Seasons;

// Today's weather reports exact conditions, while tomorrow's forecast is deterministically generated from
// the seed and calendar with roughly 75% accuracy.
public sealed partial class SeasonsPlugin
{
    private const string Panel = "forecast";
    private const float StormRain = 0.6f;
    private bool Storm(float time) => Precipitation(time) > StormRain && FallingAt(time) != "snow";
    private static readonly string[] SeasonNames = ["Spring", "Summer", "Autumn", "Winter"];

    private static string Clock(float time)
    {
        var hour = ((int)MathF.Round(time) % 24 + 24) % 24;
        return hour switch { 0 => "midnight", 12 => "noon", < 12 => hour + " AM", _ => hour - 12 + " PM" };
    }

    private static string Period(float hour) => hour < 5 ? "overnight" : hour < 12 ? "in the morning" : hour < 17 ? "in the afternoon" : hour < 21 ? "in the evening" : "tonight";
    private static string Degrees(float value) => ((int)MathF.Round(value)).ToString(CultureInfo.InvariantCulture) + "°F";
    private static string Capital(string text) => char.ToUpperInvariant(text[0]) + text[1..];

    private string Condition(float time, bool snowing, bool daylight)
    {
        var rain = Precipitation(time);
        if (rain > 0.02f)
        {
            var kind = FallingAt(time);
            if (kind == "snow") return rain > StormRain ? "heavy snow" : "snowing";
            if (kind == "thunder" || rain > StormRain) return "thunderstorm";
            return "raining";
        }
        var cover = CloudCover(time);
        return cover < 0.35f ? daylight ? "sunny" : "clear" : cover < 0.55f ? "partly cloudy" : cover < 0.8f ? "cloudy" : "overcast";
    }

    private string Today(int day, float time)
    {
        foreach (var front in new[] { day - 1, day })
        {
            if (WeatherAt(front).Sky != 2) continue;
            var (start, end) = Front(front);
            if (end < day * 24 || time > end) continue;
            if (time >= start) return $"{Capital(Falling(front))} until about {Clock(end)}{(end >= (day + 1) * 24 ? " tomorrow" : "")}";
            return $"{Capital(Falling(front))} from about {Clock(start)}";
        }
        foreach (var front in new[] { day, day - 1 })
            if (WeatherAt(front).Sky == 2 && Front(front).End >= day * 24) return Capital(Falling(front)) + " has passed";
        return WeatherAt(day).Sky == 0 ? "Fair skies" : "Cloudy";
    }

    private string Tomorrow(int day)
    {
        var next = day + 1;
        var actual = WeatherAt(next);
        var predicted = RandomValue(next, 7) < 0.75f ? actual.Sky : (actual.Sky + (RandomValue(next, 8) < 0.5f ? 1 : 2)) % 3;
        var sure = RandomValue(next, 9) < (predicted == actual.Sky ? 0.7f : 0.35f);
        var hour = actual.Sky == 2 ? actual.Start : 1 + RandomValue(next, 10) * 20;
        return predicted switch
        {
            0 => sure ? "Sunny" : "Mostly sunny",
            1 => sure ? "Cloudy" : "Some clouds",
            _ => sure ? $"{Capital(Falling(next))} likely {Period(hour)}" : "Chance of " + Falling(next),
        };
    }

    private (int Day, float Hour, bool Seasonal, bool Snowing)? published;
    private void PublishForecast(int day, float hour, bool seasonal, bool snowing)
    {
        if (published == (day, hour, seasonal, snowing)) return;
        published = (day, hour, seasonal, snowing);
        if (!seasonal)
        {
            foreach (var binding in new[] { "season", "now", "today", "today-temps", "tomorrow", "tomorrow-temps", "next" })
                context.SetPanelValue(Panel, binding, "");
            context.SetPanelValue(Panel, "today", "This town keeps its own weather.");
            return;
        }
        var time = day * 24 + hour;
        var (rise, set) = Daylight(time / 24, true);
        var season = Season(day);
        var left = DaysPerSeason - Into(day);
        var guess = HighOf(day + 1) + (RandomValue(day + 1, 11) - 0.5f) * 6;
        context.SetPanelValue(Panel, "season", $"{SeasonNames[season]}, day {Into(day) + 1} of {DaysPerSeason}{(Holiday(day) is { } holiday ? " — " + holiday : "")}");
        context.SetPanelValue(Panel, "now", $"Now: {Degrees(Temperature(time, true))}, {Condition(time, snowing, hour >= rise && hour < set)}");
        context.SetPanelValue(Panel, "today", "Today: " + Today(day, time));
        context.SetPanelValue(Panel, "today-temps", $"High {Degrees(HighOf(day))}, low {Degrees(LowOf(day))}");
        context.SetPanelValue(Panel, "tomorrow", "Tomorrow: " + Tomorrow(day) + (Holiday(day + 1) is { } coming ? $" ({coming})" : ""));
        context.SetPanelValue(Panel, "tomorrow-temps", "High near " + Degrees(guess));
        context.SetPanelValue(Panel, "next", $"{SeasonNames[(season + 1) % 4]} begins {(left == 1 ? "tomorrow" : $"in {left} days")}");
    }
}
