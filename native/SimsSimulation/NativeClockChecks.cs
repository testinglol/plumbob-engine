using FSO.SimAntics;

internal static class NativeClockChecks
{
    public static object Run(VM vm)
    {
        var clock = new VMClock();
        var boundaries = new (int Hour, int Minute, int Expected)[]
        {
            (0, 0, 1),
            (5, 59, 1),
            (6, 0, 0),
            (17, 59, 0),
            (18, 0, 1),
            (23, 59, 1)
        };
        foreach (var boundary in boundaries)
        {
            clock.Hours = boundary.Hour;
            clock.Minutes = boundary.Minute;
            if (clock.TimeOfDay != boundary.Expected)
                throw new InvalidDataException($"Clock phase was incorrect at {boundary.Hour:D2}:{boundary.Minute:D2}");
        }
        foreach (var boundary in boundaries)
        {
            vm.Context.Clock.Hours = boundary.Hour;
            vm.Context.Clock.Minutes = boundary.Minute;
            if (vm.GetGlobalValue(4) != boundary.Expected)
                throw new InvalidDataException($"Script-visible clock phase was incorrect at {boundary.Hour:D2}:{boundary.Minute:D2}");
        }
        return new { checks = boundaries.Length * 2, daytimeStartsAt = "06:00", daytimeEndsAt = "18:00", dayNightBoundaries = true };
    }
}
