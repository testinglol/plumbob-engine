namespace Local.Seasons;

public sealed partial class SeasonsPlugin
{
    private static readonly string[] HolidayNames = ["Blossom Day", "Splash Day", "Harvest Day", "Snowflake Day"];

    private string? Holiday(int day) => Into(day) == DaysPerSeason / 2 ? HolidayNames[Season(day)] : null;
}
