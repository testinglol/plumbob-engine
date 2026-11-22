using System.Diagnostics;
using System.Globalization;

namespace SimsSDL.Client;

public static class SessionSweeper
{
    internal const string OwnerFile = "owner.pid";
    private static readonly UTF8Encoding Utf8NoBom = new(encoderShouldEmitUTF8Identifier: false);

    private static int CurrentProcessId => Environment.ProcessId;

    private static bool ProcessExists(int pid)
    {
        if (pid <= 0)
        {
            return false;
        }

        try
        {
            using var process = Process.GetProcessById(pid);
            try
            {
                return !process.HasExited;
            }
            catch
            {
                // Access denied implies the target process is still running.
                return true;
            }
        }
        catch (ArgumentException)
        {
            return false;
        }
        catch
        {
            return true;
        }
    }

    public static void Claim(string session)
    {
        ArgumentException.ThrowIfNullOrEmpty(session);
        try
        {
            File.WriteAllText(
                Path.Combine(session, OwnerFile),
                CurrentProcessId.ToString(CultureInfo.InvariantCulture),
                Utf8NoBom);
        }
        catch
        {
        }
    }

    public static IReadOnlyList<string> Sweep(string dataRoot)
    {
        ArgumentException.ThrowIfNullOrEmpty(dataRoot);
        var cleaned = new List<string>();
        var sessions = Path.Combine(dataRoot, "runtime", "sessions");
        if (Directory.Exists(sessions))
        {
            try
            {
                foreach (var session in Directory.EnumerateFileSystemEntries(sessions))
                {
                    if (IsOwned(session) || !Directory.Exists(session))
                    {
                        continue;
                    }

                    string[] mounts;
                    try
                    {
                        mounts = Directory.EnumerateFileSystemEntries(session)
                            .Where(entry =>
                            {
                                var name = Path.GetFileName(entry);
                                return string.Equals(name, "content", StringComparison.Ordinal) ||
                                       name.StartsWith(".mount-", StringComparison.Ordinal);
                            })
                            .ToArray();
                    }
                    catch
                    {
                        continue;
                    }

                    if (mounts.Length == 0)
                    {
                        continue;
                    }

                    foreach (var mount in mounts)
                    {
                        DeleteEntrySafely(mount);
                    }

                    cleaned.Add(session);
                }
            }
            catch
            {
            }
        }

        var sharedContent = Path.Combine(dataRoot, "runtime", "content");
        if (Directory.Exists(sharedContent))
        {
            try
            {
                foreach (var cache in Directory.EnumerateFileSystemEntries(sharedContent))
                {
                    if (!IsOwned(cache) &&
                        !File.Exists(Path.Combine(cache, "content", ".content-cache.json")))
                    {
                        DeleteEntrySafely(cache);
                        cleaned.Add(cache);
                    }
                }
            }
            catch
            {
            }
        }

        return cleaned;
    }

    public static IReadOnlyList<string> SweepContentCaches(string dataRoot, string preserving)
    {
        ArgumentException.ThrowIfNullOrEmpty(dataRoot);
        ArgumentException.ThrowIfNullOrEmpty(preserving);
        var sharedContent = Path.Combine(dataRoot, "runtime", "content");
        if (!Directory.Exists(sharedContent))
        {
            return [];
        }

        var currentPath = NormalizePath(preserving);
        var pathComparison = OperatingSystem.IsWindows() ? StringComparison.OrdinalIgnoreCase : StringComparison.Ordinal;
        var cleaned = new List<string>();
        try
        {
            foreach (var cache in Directory.EnumerateFileSystemEntries(sharedContent))
            {
                if (!string.Equals(NormalizePath(cache), currentPath, pathComparison) && !IsOwned(cache))
                {
                    DeleteEntrySafely(cache);
                    cleaned.Add(cache);
                }
            }
        }
        catch
        {
            return cleaned;
        }

        return cleaned;
    }

    internal static bool IsOwnedByAnotherProcess(string session)
    {
        var owner = Path.Combine(session, OwnerFile);
        try
        {
            if (!File.Exists(owner))
            {
                return false;
            }

            var text = File.ReadAllText(owner, Encoding.UTF8).Trim();
            if (!int.TryParse(text, NumberStyles.Integer, CultureInfo.InvariantCulture, out var pid) || pid <= 0)
            {
                return false;
            }

            return pid != CurrentProcessId && ProcessExists(pid);
        }
        catch
        {
            return false;
        }
    }

    internal static bool IsOwned(string session)
    {
        var owner = Path.Combine(session, OwnerFile);
        try
        {
            if (!File.Exists(owner))
            {
                var modified = File.GetLastWriteTimeUtc(session);
                if (modified == DateTime.MinValue || modified.Year <= 1601)
                {
                    return false;
                }

                const int unownedSessionTtlSeconds = 3600;
                return (DateTime.UtcNow - modified).TotalSeconds < unownedSessionTtlSeconds;
            }

            var text = File.ReadAllText(owner, Encoding.UTF8).Trim();
            if (!int.TryParse(text, NumberStyles.Integer, CultureInfo.InvariantCulture, out var pid) || pid <= 0)
            {
                return false;
            }

            return ProcessExists(pid);
        }
        catch
        {
            return false;
        }
    }

    internal static void DeleteEntrySafely(string path)
    {
        try
        {
            var attrs = File.GetAttributes(path);
            if ((attrs & FileAttributes.ReparsePoint) != 0)
            {
                if ((attrs & FileAttributes.Directory) != 0)
                {
                    Directory.Delete(path, recursive: false);
                }
                else
                {
                    File.Delete(path);
                }
                return;
            }

            if ((attrs & FileAttributes.Directory) != 0)
            {
                Directory.Delete(path, recursive: true);
            }
            else
            {
                File.Delete(path);
            }
        }
        catch
        {
        }
    }

    private static string NormalizePath(string path) =>
        Path.TrimEndingDirectorySeparator(Path.GetFullPath(path));
}
