using System.Globalization;

/// <summary>
/// The Complete Collection's numbered neighborhoods. The original scans for <c>UserData</c> folders, reads the number
/// after the name (plain <c>UserData</c> is neighborhood 1), keeps them in a sorted map, remembers the current one in
/// <c>SIMS_CURRENT_NEIGHBORHOOD_NUM</c>, and the banner's Previous/Next buttons step through them with wrap-around
/// (<c>0x0042a53a</c>, <c>0x0042a368</c>, <c>0x0042a3ca</c>, <c>0x0042a3f4</c>).
/// </summary>
internal static class NativeNeighborhoods
{
    internal const int Maximum = 99;

    /// <summary>The neighborhood the host was started with; neighborhood 1 unless <c>--neighborhood</c> chose another.</summary>
    internal static int Current { get; set; } = 1;

    internal static string DirectoryName(int number) =>
        number is < 1 or > Maximum ? throw new ArgumentOutOfRangeException(nameof(number), "Neighborhood numbers run from 1 through 99")
            : number == 1 ? "UserData" : "UserData" + number.ToString(CultureInfo.InvariantCulture);

    /// <summary>The current neighborhood's folder inside a native profile.</summary>
    internal static string UserData(string profile) => Path.Combine(profile, DirectoryName(Current));

    /// <summary>Installed neighborhoods in a profile, in the original's ascending order.</summary>
    internal static int[] Installed(string profile)
    {
        if (!Directory.Exists(profile)) return [];
        return Directory.GetDirectories(profile)
            .Select(path => Number(Path.GetFileName(path)))
            .Where(number => number.HasValue && File.Exists(Path.Combine(profile, DirectoryName(number.Value), "Neighborhood.iff")))
            .Select(number => number!.Value)
            .Distinct()
            .Order()
            .ToArray();
    }

    /// <summary>The neighborhood number of a folder name, or null when it is not a neighborhood folder.</summary>
    internal static int? Number(string? name)
    {
        if (name == null || !name.StartsWith("UserData", StringComparison.OrdinalIgnoreCase)) return null;
        var suffix = name["UserData".Length..];
        if (suffix.Length == 0) return 1;
        return suffix.All(char.IsAsciiDigit) && int.TryParse(suffix, NumberStyles.None, CultureInfo.InvariantCulture, out var number) &&
               number is >= 2 and <= Maximum ? number : null;
    }
}
