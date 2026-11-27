using System.Globalization;

namespace Local.Seasons;

public sealed partial class SeasonsPlugin
{
    private string? weatherOverride;
    private float? weatherOverrideStartTime;
    private float weatherOverrideBaseSnow;
    private float weatherOverrideBaseWetness;
    private float lastRawSnow;
    private float lastRawWetness;

    public void OnPanelAction(string panelId, string action)
    {
        if (panelId != "season-settings") return;
        var nextClimate = action switch
        {
            "climate-mild" => "mild",
            "climate-temperate" => "temperate",
            "climate-harsh" => "harsh",
            _ => null
        };
        if (nextClimate is not null)
        {
            context.NeighborhoodValues["climate"] = nextClimate;
            published = null;
            lastClientStateSignature = null;
            PublishSeasonLength();
            SyncWeatherAndClientState();
            return;
        }

        var length = action switch { "short" => 3, "normal" => 7, "long" => 14, _ => 0 };
        if (length == 0) return;
        var oldLength = DaysPerSeason;
        Day = checked(Day / oldLength * length + Day % oldLength * length / oldLength);
        context.NeighborhoodValues["daysPerSeason"] = length.ToString(CultureInfo.InvariantCulture);
        published = null;
        lastClientStateSignature = null;
        PublishSeasonLength();
        SyncWeatherAndClientState();
    }

    public IReadOnlyList<string> CheatCommands => ["weather", "season"];

    public string? OnCheat(string command, string[] args)
    {
        if (command == "weather")
        {
            if (args.Length != 1)
                throw new ArgumentException("Cheat Error: Usage: weather <clear|cloud|rain|thunder|snow|auto>");
            var normalized = args[0].ToLowerInvariant() switch
            {
                "clear" or "sun" or "sunny" => "clear",
                "cloud" or "cloudy" or "clouds" => "cloud",
                "rain" or "rainy" => "rain",
                "thunder" or "storm" or "thunderstorm" => "thunder",
                "snow" or "snowy" or "blizzard" => "snow",
                "auto" or "calendar" or "off" or "reset" => "auto",
                _ => null
            };
            if (normalized is null)
                throw new ArgumentException("Cheat Error: Usage: weather <clear|cloud|rain|thunder|snow|auto>");
            weatherOverride = normalized == "auto" ? null : normalized;
            weatherOverrideStartTime = null;
            weatherOverrideBaseSnow = lastRawSnow;
            weatherOverrideBaseWetness = lastRawWetness;
            published = null;
            SyncWeatherAndClientState();
            return weatherOverride is null ? "Weather restored to seasonal calendar." : $"Weather transitioning to {weatherOverride}.";
        }
        if (command == "season")
        {
            if (args.Length is < 1 or > 2)
                throw new ArgumentException("Cheat Error: Usage: season <spring|summer|fall|winter> [day]");
            int targetSeason = args[0].ToLowerInvariant() switch
            {
                "spring" => 0,
                "summer" => 1,
                "fall" or "autumn" => 2,
                "winter" => 3,
                _ => -1
            };
            if (targetSeason < 0)
                throw new ArgumentException("Cheat Error: Usage: season <spring|summer|fall|winter> [day]");
            var length = DaysPerSeason;
            int dayOffset;
            if (args.Length == 2)
            {
                if (!int.TryParse(args[1], CultureInfo.InvariantCulture, out var parsedDay) || parsedDay < 1 || parsedDay > length)
                    throw new ArgumentException($"Cheat Error: Usage: season <spring|summer|fall|winter> [1-{length}]");
                dayOffset = parsedDay - 1;
            }
            else
            {
                dayOffset = 0;
            }
            var delta = (targetSeason - Season(Day) + 4) % 4;
            Day = checked((Day / length + delta) * length + dayOffset);
            weatherOverride = null;
            weatherOverrideStartTime = null;
            lastRawSnow = 0f;
            lastRawWetness = 0f;
            walkers.Clear();
            footprints.Clear();
            published = null;
            PublishSeasonLength();
            SyncWeatherAndClientState();
            return $"Season set to {SeasonNames[targetSeason]} (day {dayOffset + 1} of {length}).";
        }
        return null;
    }

    private void PublishSeasonLength()
    {
        context.SetPanelValue("season-settings", "length", $"Each season lasts {DaysPerSeason} days.");
        context.SetPanelValue("season-settings", "length-season", $"Current season: {SeasonNames[Season(Day)]}");
        context.SetPanelValue("season-settings", "daysPerSeason", DaysPerSeason.ToString(CultureInfo.InvariantCulture));
        context.SetPanelValue("season-settings", "climate", ClimateName);
    }
}
