using System.Diagnostics;
using System.Security.Cryptography;
using System.Text.RegularExpressions;

namespace SimsSDL.Client;

public static class PackTool
{
    private static readonly JsonSerializerOptions IndentedCamelOptions = new()
    {
        WriteIndented = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
    };

    private static readonly JsonSerializerOptions IndentedOptions = new()
    {
        WriteIndented = true,
    };

    private static readonly Regex HlslStageStructRegex = new(
        @"struct\s+(SPIRV_Cross_(?:Input|Output))\s*\{(.*?)\};",
        RegexOptions.Singleline | RegexOptions.Compiled);

    private static readonly Regex HlslStageFieldRegex = new(
        @"^\s*(nointerpolation\s+)?(\w+)\s+\w+\s*:\s*([A-Za-z0-9_]+)\s*;\s*$",
        RegexOptions.Compiled);

    public abstract record Command
    {
        private Command() { }

        public sealed record Report : Command;
        public sealed record ListPlugins : Command;
        public sealed record TrustPlugin(string PackId) : Command;
        public sealed record RevokePlugin(string PackId) : Command;
        public sealed record AllocateObjectGuid(string PackId, string Name) : Command;
        public sealed record ReserveObjectGuid(string PackId, string Name) : Command;

        public sealed record Validate : Command;

        public sealed record Mount(string Path) : Command;
        public sealed record Seal(string PackDirectory) : Command;
        public sealed record Build(string PackDirectory, string? SourceDirectory) : Command;
    }

    public static GameContent LoadContent(string game, string? packs)
    {
        ArgumentException.ThrowIfNullOrEmpty(game);
        var directories = new List<string>();
        if (!string.IsNullOrEmpty(packs) && Directory.Exists(packs))
        {
            foreach (var entry in Directory.EnumerateDirectories(packs))
            {
                if (File.Exists(Path.Combine(entry, "pack.json")))
                {
                    directories.Add(entry);
                }
            }
        }

        return new GameContent(game, directories);
    }

    public static (byte[] Report, bool Valid) Validate(string game, string? packs)
    {
        ArgumentException.ThrowIfNullOrEmpty(game);
        var directories = new List<string>();
        if (!string.IsNullOrEmpty(packs) && Directory.Exists(packs))
        {
            try
            {
                directories = Directory.EnumerateDirectories(packs)
                    .Where(dir => File.Exists(Path.Combine(dir, "pack.json")))
                    .OrderBy(dir => Path.GetFileName(dir), StringComparer.Ordinal)
                    .ToList();
            }
            catch
            {
                directories = [];
            }
        }

        var problems = new List<SortedDictionary<string, string>>();
        var readable = new List<(string Directory, ContentPack Pack)>();
        var listing = new List<SortedDictionary<string, object?>>();

        static string ErrorMessage(Exception error) => error switch
        {
            ContentError contentError => contentError.Message,
            JsonException jsonException => jsonException.Message,
            _ => error.Message,
        };

        void AddProblem(string pack, string stage, string problem) =>
            problems.Add(new SortedDictionary<string, string>(StringComparer.Ordinal)
            {
                ["pack"] = pack,
                ["problem"] = problem,
                ["stage"] = stage,
            });

        foreach (var directory in directories)
        {
            var dirName = Path.GetFileName(directory);
            try
            {
                var pack = new ContentPack(directory);
                readable.Add((directory, pack));
                listing.Add(new SortedDictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["directory"] = dirName,
                    ["files"] = pack.Assets.Count,
                    ["id"] = pack.Manifest.Id,
                    ["panels"] = pack.PanelFiles.Count,
                    ["plugin"] = pack.PluginAssembly is not null,
                    ["version"] = pack.Manifest.Version,
                });
            }
            catch (Exception error)
            {
                AddProblem(dirName, "pack", ErrorMessage(error));
                listing.Add(new SortedDictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["directory"] = dirName,
                    ["unreadable"] = true,
                });
            }
        }

        var seen = new Dictionary<string, string>(StringComparer.Ordinal);
        foreach (var entry in readable)
        {
            var id = entry.Pack.Manifest.Id;
            var dirName = Path.GetFileName(entry.Directory);
            if (seen.TryGetValue(id, out var first))
            {
                AddProblem(id, "together", $"Duplicate pack ID in {first} and {dirName}");
            }
            else
            {
                seen[id] = dirName;
            }
        }

        foreach (var entry in readable)
        {
            foreach (var dependency in entry.Pack.Manifest.Dependencies)
            {
                var match = readable
                    .Select(candidate => candidate.Pack)
                    .FirstOrDefault(pack => string.Equals(pack.Manifest.Id, dependency.Id, StringComparison.Ordinal));
                if (match is null)
                {
                    AddProblem(entry.Pack.Manifest.Id, "together", $"Requires {dependency.Id}, which is not in the pack folder");
                }
                else if (!string.Equals(dependency.Version, "*", StringComparison.Ordinal) &&
                         !string.Equals(match.Manifest.Version, dependency.Version, StringComparison.Ordinal))
                {
                    AddProblem(
                        entry.Pack.Manifest.Id,
                        "together",
                        $"Requires {dependency.Id} version {dependency.Version}, found {match.Manifest.Version}");
                }
            }
        }

        var stackProblem = problems.Any(problem => string.Equals(problem["stage"], "together", StringComparison.Ordinal));
        foreach (var entry in readable)
        {
            try
            {
                _ = new PackStack([entry.Pack]);
            }
            catch (Exception error)
            {
                var msg = ErrorMessage(error);
                if (msg.Contains("requires", StringComparison.Ordinal))
                {
                    continue;
                }

                AddProblem(entry.Pack.Manifest.Id, "alone", msg);
                stackProblem = true;
            }
        }

        if (!stackProblem && readable.Count > 0)
        {
            try
            {
                _ = new PackStack(readable.Select(entry => entry.Pack).ToList());
            }
            catch (Exception error)
            {
                AddProblem("(all)", "together", ErrorMessage(error));
                stackProblem = true;
            }
        }

        if (!stackProblem && readable.Count > 0)
        {
            try
            {
                _ = new GameContent(game, readable.Select(entry => entry.Directory).ToList());
            }
            catch (Exception error)
            {
                AddProblem("(all)", "base game", ErrorMessage(error));
                foreach (var entry in readable)
                {
                    PackStack? alone = null;
                    try
                    {
                        alone = new PackStack([entry.Pack]);
                    }
                    catch
                    {
                        alone = null;
                    }

                    if (alone is null || alone.Ordered.Count != 1)
                    {
                        continue;
                    }

                    try
                    {
                        _ = new GameContent(game, [entry.Directory]);
                    }
                    catch (Exception aloneError)
                    {
                        AddProblem(entry.Pack.Manifest.Id, "base game alone", ErrorMessage(aloneError));
                    }
                }
            }
        }

        var result = new SortedDictionary<string, object?>(StringComparer.Ordinal)
        {
            ["packs"] = listing,
            ["problems"] = problems,
            ["valid"] = problems.Count == 0,
        };
        var reportBytes = JsonSerializer.SerializeToUtf8Bytes(result, IndentedCamelOptions);
        return (reportBytes, problems.Count == 0);
    }

    public static byte[] Run(Command command, GameContent content, string dataRoot)
    {
        ArgumentNullException.ThrowIfNull(command);
        ArgumentNullException.ThrowIfNull(content);
        ArgumentException.ThrowIfNullOrEmpty(dataRoot);

        switch (command)
        {
            case Command.Validate:
                throw new ContentError("validate runs before content loads; use PackTool.Validate");

            case Command.Report:
                return JsonSerializer.SerializeToUtf8Bytes(content.Packs.Report(), IndentedCamelOptions);

            case Command.Mount(var path):
            {
                var destination = Path.GetFullPath(path);
                content.Materialize(destination);
                var payload = new SortedDictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["fingerprint"] = content.Packs.Report().Fingerprint,
                    ["mount"] = destination,
                };
                return JsonSerializer.SerializeToUtf8Bytes(payload, IndentedCamelOptions);
            }

            case Command.AllocateObjectGuid(var packId, var name):
                return JsonSerializer.SerializeToUtf8Bytes(content.AllocateObjectGUID(packId, name), IndentedCamelOptions);

            case Command.ReserveObjectGuid(var packId, var name):
                return JsonSerializer.SerializeToUtf8Bytes(content.ReserveObjectGUID(packId, name), IndentedCamelOptions);

            case Command.ListPlugins or Command.TrustPlugin or Command.RevokePlugin:
            {
                var store = new PluginTrustStore(dataRoot);
                var plugins = content.Packs.PluginReports();
                if (command is Command.TrustPlugin trustCommand)
                {
                    var plugin = plugins.FirstOrDefault(p =>
                        string.Equals(p.PackID, trustCommand.PackId, StringComparison.Ordinal));
                    if (plugin is null)
                    {
                        throw new ContentError($"No enabled pack named {trustCommand.PackId} declares a plugin");
                    }

                    store.Trust(plugin);
                }
                else if (command is Command.RevokePlugin revokeCommand)
                {
                    if (!store.Revoke(revokeCommand.PackId))
                    {
                        throw new ContentError($"Plugin {revokeCommand.PackId} was not trusted");
                    }
                }

                var listing = plugins.Select(plugin => new SortedDictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["apiVersion"] = plugin.ApiVersion,
                    ["entryType"] = plugin.EntryType,
                    ["packID"] = plugin.PackID,
                    ["sha256"] = plugin.Sha256,
                    ["stateVersion"] = plugin.StateVersion,
                    ["trusted"] = store.IsTrusted(plugin),
                    ["version"] = plugin.Version,
                }).ToList();

                var result = new SortedDictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["plugins"] = listing,
                    ["trustStore"] = store.Url,
                };
                return JsonSerializer.SerializeToUtf8Bytes(result, IndentedCamelOptions);
            }

            default:
                throw new ContentError($"Unsupported pack command: {command}");
        }
    }

    public static IReadOnlyList<(PackPluginReport Plugin, string Name)> UntrustedPlugins(GameContent content, string dataRoot)
    {
        ArgumentNullException.ThrowIfNull(content);
        ArgumentException.ThrowIfNullOrEmpty(dataRoot);

        try
        {
            var plugins = content.Packs.PluginReports();
            if (plugins.Count == 0)
            {
                return [];
            }

            var store = new PluginTrustStore(dataRoot);
            return plugins
                .Where(plugin => !store.IsTrusted(plugin))
                .Select(plugin =>
                {
                    var packName = content.Packs.Ordered
                        .FirstOrDefault(pack => string.Equals(pack.Manifest.Id, plugin.PackID, StringComparison.Ordinal))
                        ?.Manifest.Name ?? plugin.PackID;
                    return (plugin, packName);
                })
                .ToList();
        }
        catch
        {
            return [];
        }
    }

    public static void Trust(PackPluginReport plugin, string dataRoot)
    {
        ArgumentNullException.ThrowIfNull(plugin);
        ArgumentException.ThrowIfNullOrEmpty(dataRoot);

        var store = new PluginTrustStore(dataRoot);
        store.Trust(plugin);
    }

    public static byte[] SealPack(string packDirectory)
    {
        ArgumentException.ThrowIfNullOrEmpty(packDirectory);
        string fullPackDir = Path.GetFullPath(packDirectory);
        string manifestPath = Path.Combine(fullPackDir, "pack.json");
        if (!File.Exists(manifestPath))
            throw new ContentError($"Pack manifest not found at {manifestPath}");

        using var manifestDoc = JsonDocument.Parse(File.ReadAllBytes(manifestPath));
        string packId = manifestDoc.RootElement.GetProperty("id").GetString()
            ?? throw new ContentError($"Pack at {fullPackDir} is missing id");

        var resources = new SortedDictionary<string, string>(StringComparer.Ordinal);
        string filesRoot = Path.Combine(fullPackDir, "files");
        if (Directory.Exists(filesRoot))
        {
            foreach (string file in Directory.EnumerateFiles(filesRoot, "*", SearchOption.AllDirectories))
            {
                string fileName = Path.GetFileName(file);
                if (fileName.Equals(".DS_Store", StringComparison.OrdinalIgnoreCase) ||
                    fileName.Equals(".gitkeep", StringComparison.OrdinalIgnoreCase))
                    continue;
                string rel = Path.GetRelativePath(filesRoot, file).Replace('\\', '/').ToLowerInvariant();
                string hash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(file))).ToLowerInvariant();
                resources[rel] = hash;
            }
        }

        string pluginDir = Path.Combine(fullPackDir, "plugin");
        string resourcesPath = Path.Combine(pluginDir, "resources.json");
        if (resources.Count > 0 || File.Exists(resourcesPath))
        {
            Directory.CreateDirectory(pluginDir);
            string json = JsonSerializer.Serialize(resources, IndentedOptions).Replace("\r\n", "\n", StringComparison.Ordinal) + "\n";
            File.WriteAllText(resourcesPath, json, new UTF8Encoding(false));
        }

        var report = new SortedDictionary<string, object?>(StringComparer.Ordinal)
        {
            ["packId"] = packId,
            ["resourcesSealed"] = resources.Count,
        };
        return JsonSerializer.SerializeToUtf8Bytes(report, IndentedCamelOptions);
    }

    public static byte[] BuildPack(string packDirectory, string? sourceDirectory = null, string? gameDirectory = null)
    {
        ArgumentException.ThrowIfNullOrEmpty(packDirectory);
        string fullPackDir = Path.GetFullPath(packDirectory);
        string fullSourceDir = string.IsNullOrWhiteSpace(sourceDirectory)
            ? fullPackDir
            : Path.GetFullPath(sourceDirectory);

        string manifestPath = Path.Combine(fullPackDir, "pack.json");
        if (!File.Exists(manifestPath))
        {
            string srcManifest = Path.Combine(fullSourceDir, "pack.json");
            if (File.Exists(srcManifest))
            {
                Directory.CreateDirectory(fullPackDir);
                File.Copy(srcManifest, manifestPath, overwrite: true);
            }
            else
            {
                throw new ContentError($"Pack manifest not found at {manifestPath}");
            }
        }

        using var manifestDoc = JsonDocument.Parse(File.ReadAllBytes(manifestPath));
        string packId = manifestDoc.RootElement.GetProperty("id").GetString()
            ?? throw new ContentError($"Pack at {fullPackDir} is missing id");
        string? assemblyRel = manifestDoc.RootElement.TryGetProperty("plugin", out var pluginEl)
            && pluginEl.TryGetProperty("assembly", out var asmEl)
                ? asmEl.GetString()
                : null;

        string? compiledAssembly = null;
        string? csproj = Directory.Exists(fullSourceDir)
            ? Directory.EnumerateFiles(fullSourceDir, "*.csproj", SearchOption.TopDirectoryOnly).FirstOrDefault()
            : null;
        if (csproj is not null && assemblyRel is not null)
        {
            RunExternalProcess("dotnet", [
                "build", csproj,
                "-c", "Release",
                "-m:1",
                "--disable-build-servers",
                "-p:NuGetAudit=false",
                "-nologo",
                "-clp:ErrorsOnly",
            ]);
            string asmName = Path.GetFileName(assemblyRel);
            string builtDll = Path.Combine(Path.GetDirectoryName(csproj)!, "bin", "Release", "net9.0", asmName);
            if (!File.Exists(builtDll))
                throw new ContentError($"Expected compiled plugin assembly not found at {builtDll}");
            string destDll = Path.GetFullPath(Path.Combine(fullPackDir, assemblyRel));
            Directory.CreateDirectory(Path.GetDirectoryName(destDll)!);
            File.Copy(builtDll, destDll, overwrite: true);
            string builtDeps = Path.ChangeExtension(builtDll, ".deps.json");
            string destDeps = Path.ChangeExtension(destDll, ".deps.json");
            if (File.Exists(builtDeps) && File.Exists(destDeps))
                File.Copy(builtDeps, destDeps, overwrite: true);
            compiledAssembly = assemblyRel;
        }

        string? shaderSrcDir = new[]
            {
                Path.Combine(fullSourceDir, "Shaders"),
                Path.Combine(fullSourceDir, "shaders"),
                Path.Combine(fullPackDir, "Shaders"),
                Path.Combine(fullPackDir, "shaders"),
            }
            .FirstOrDefault(Directory.Exists);

        int shadersCompiled = 0;
        if (shaderSrcDir is not null)
        {
            string shaderOutDir = Path.Combine(fullPackDir, "files", "Downloads", packId, "shaders");
            string hlslOutDir = Path.Combine(fullPackDir, "shaders-hlsl");
            shadersCompiled = CompileShaderDirectory(shaderSrcDir, shaderOutDir, hlslOutDir);
        }

        string? objectsDir = new[]
            {
                Path.Combine(fullSourceDir, "objects"),
                Path.Combine(fullPackDir, "objects"),
            }
            .FirstOrDefault(Directory.Exists);
        int objectsCompiled = 0;
        if (objectsDir is not null && !string.IsNullOrWhiteSpace(gameDirectory) && Directory.Exists(gameDirectory))
        {
            string objectOutDir = Path.Combine(fullPackDir, "files", "Downloads", packId, "objects");
            foreach (string specFile in Directory.EnumerateFiles(objectsDir, "*.json", SearchOption.TopDirectoryOnly)
                         .OrderBy(static p => p, StringComparer.Ordinal))
            {
                Directory.CreateDirectory(objectOutDir);
                SimsSimulation.ObjectAuthor.Compile(specFile, gameDirectory, objectOutDir);
                objectsCompiled++;
            }
        }

        int sealedCount = 0;
        if (Directory.Exists(Path.Combine(fullPackDir, "files")) || compiledAssembly is not null)
        {
            using var sealDoc = JsonDocument.Parse(SealPack(fullPackDir));
            sealedCount = sealDoc.RootElement.GetProperty("resourcesSealed").GetInt32();
        }

        var report = new SortedDictionary<string, object?>(StringComparer.Ordinal)
        {
            ["assembly"] = compiledAssembly,
            ["objectsCompiled"] = objectsCompiled,
            ["packId"] = packId,
            ["resourcesSealed"] = sealedCount,
            ["shadersCompiled"] = shadersCompiled,
        };
        return JsonSerializer.SerializeToUtf8Bytes(report, IndentedCamelOptions);
    }

    internal static int CompileShaderDirectory(string sourceDir, string outputDir, string hlslOutDir)
    {
        var sources = Directory.EnumerateFiles(sourceDir)
            .Where(static f => f.EndsWith(".vert", StringComparison.Ordinal) || f.EndsWith(".frag", StringComparison.Ordinal))
            .OrderBy(static f => Path.GetFileName(f), StringComparer.Ordinal)
            .ToList();
        if (sources.Count == 0)
            return 0;

        Directory.CreateDirectory(outputDir);
        Directory.CreateDirectory(hlslOutDir);

        foreach (string shaderPath in sources)
        {
            string name = Path.GetFileName(shaderPath);
            string spvOut = Path.Combine(outputDir, name + ".spv");
            RunExternalProcess("glslangValidator", ["-V", "--quiet", $"-I{sourceDir}", "-o", spvOut, shaderPath]);
        }

        var generatedHlsl = new Dictionary<string, string>(StringComparer.Ordinal);
        foreach (string shaderPath in sources)
        {
            string name = Path.GetFileName(shaderPath);
            string spvPath = Path.Combine(outputDir, name + ".spv");
            var reflected = SpirvReflection.Reflect(File.ReadAllBytes(spvPath));

            var mslArgs = new List<string> { spvPath, "--msl", "--msl-version", "20100" };
            if (reflected.StorageBuffers == 0)
                mslArgs.Add("--msl-decoration-binding");
            string msl = NormalizeShaderText(RunExternalProcess("spirv-cross", mslArgs));
            ValidateMetalBindings(spvPath, msl);
            File.WriteAllText(Path.Combine(outputDir, name + ".msl"), msl, new UTF8Encoding(false));

            string hlsl = NormalizeShaderText(RunExternalProcess("spirv-cross", [spvPath, "--hlsl", "--shader-model", "60", "--hlsl-enable-compat"]));
            File.WriteAllText(Path.Combine(hlslOutDir, name + ".hlsl"), hlsl, new UTF8Encoding(false));
            generatedHlsl[name] = hlsl;
        }

        ValidateStageLinkage(generatedHlsl);

        string? dxc = FindDxcExecutable();
        if (dxc is not null)
        {
            foreach (var (name, _) in generatedHlsl.OrderBy(static kv => kv.Key, StringComparer.Ordinal))
            {
                string profile = name.EndsWith(".vert", StringComparison.Ordinal) ? "vs_6_0" : "ps_6_0";
                string hlslPath = Path.Combine(hlslOutDir, name + ".hlsl");
                string dxilPath = Path.Combine(outputDir, name + ".dxil");
                RunExternalProcess(dxc, ["-T", profile, "-E", "main", "-O3", "-Fo", dxilPath, hlslPath]);
            }
        }

        return sources.Count;
    }

    private static string NormalizeShaderText(string text)
    {
        var lines = text.Replace("\r\n", "\n", StringComparison.Ordinal).Split('\n')
            .Select(static l => l.TrimEnd());
        return string.Join('\n', lines).TrimEnd() + "\n";
    }

    private static void ValidateMetalBindings(string spvPath, string msl)
    {
        string reflectJson = RunExternalProcess("spirv-cross", [spvPath, "--reflect"]);
        using var doc = JsonDocument.Parse(reflectJson);
        if (!doc.RootElement.TryGetProperty("textures", out var textures))
            return;
        foreach (var tex in textures.EnumerateArray())
        {
            string name = tex.GetProperty("name").GetString() ?? "";
            int expected = tex.GetProperty("binding").GetInt32();
            foreach (var (varName, kind) in new[] { (name, "texture"), (name + "Smplr", "sampler") })
            {
                var match = Regex.Match(msl, @"\b" + Regex.Escape(varName) + @"\s*\[\[" + kind + @"\((\d+)\)\]\]");
                int? actual = match.Success ? int.Parse(match.Groups[1].Value, System.Globalization.CultureInfo.InvariantCulture) : null;
                if (actual != expected)
                    throw new ContentError($"{Path.GetFileName(spvPath)}: {varName} {kind} slot {actual}, expected {expected}");
            }
        }
    }

    private static List<(string Interp, string Type, string Semantic)> ParseHlslStageStruct(string hlsl, string structName)
    {
        foreach (Match m in HlslStageStructRegex.Matches(hlsl))
        {
            if (!string.Equals(m.Groups[1].Value, structName, StringComparison.Ordinal))
                continue;
            var fields = new List<(string, string, string)>();
            foreach (string rawLine in m.Groups[2].Value.Split('\n'))
            {
                string line = rawLine.Trim();
                if (line.Length == 0)
                    continue;
                Match fm = HlslStageFieldRegex.Match(line);
                if (!fm.Success)
                    throw new ContentError($"Unrecognized HLSL stage struct field in {structName}: {line}");
                fields.Add((fm.Groups[1].Value.Trim(), fm.Groups[2].Value.Trim(), fm.Groups[3].Value.Trim()));
            }
            return fields;
        }
        return [];
    }

    private static void ValidateStageLinkage(IReadOnlyDictionary<string, string> generatedHlsl)
    {
        var verts = generatedHlsl
            .Where(static kv => kv.Key.EndsWith(".vert", StringComparison.Ordinal))
            .ToDictionary(static kv => kv.Key, static kv => ParseHlslStageStruct(kv.Value, "SPIRV_Cross_Output"), StringComparer.Ordinal);
        if (GPUContext.ResolvedShaderDirectory is { } coreShaderDir && Directory.Exists(coreShaderDir))
        {
            string coreHlslDir = Path.Combine(coreShaderDir, "hlsl");
            if (Directory.Exists(coreHlslDir))
            {
                foreach (string coreVert in Directory.EnumerateFiles(coreHlslDir, "*.vert.hlsl"))
                {
                    string stem = Path.GetFileName(coreVert)[..^".hlsl".Length];
                    if (!verts.ContainsKey(stem))
                        verts[stem] = ParseHlslStageStruct(File.ReadAllText(coreVert), "SPIRV_Cross_Output");
                }
            }
            else
            {
                foreach (string coreVertSpv in Directory.EnumerateFiles(coreShaderDir, "*.vert.spv"))
                {
                    string stem = Path.GetFileName(coreVertSpv)[..^".spv".Length];
                    if (!verts.ContainsKey(stem))
                    {
                        string coreHlsl = NormalizeShaderText(RunExternalProcess("spirv-cross", [coreVertSpv, "--hlsl", "--shader-model", "60", "--hlsl-enable-compat"]));
                        verts[stem] = ParseHlslStageStruct(coreHlsl, "SPIRV_Cross_Output");
                    }
                }
            }
        }

        static bool Compatible(List<(string Interp, string Type, string Sem)> vsOut, List<(string Interp, string Type, string Sem)> psIn)
        {
            if (psIn.Count > vsOut.Count)
                return false;
            for (int i = 0; i < psIn.Count; i++)
            {
                bool interpOk = psIn[i].Interp == vsOut[i].Interp || psIn[i].Sem == "SV_Position";
                if (!interpOk || psIn[i].Type != vsOut[i].Type || psIn[i].Sem != vsOut[i].Sem)
                    return false;
            }
            return true;
        }

        foreach (var (name, hlsl) in generatedHlsl)
        {
            if (!name.EndsWith(".frag", StringComparison.Ordinal))
                continue;
            var psIn = ParseHlslStageStruct(hlsl, "SPIRV_Cross_Input");
            if (psIn.Count == 0)
                continue;
            if (!verts.Values.Any(vsOut => Compatible(vsOut, psIn)))
                throw new ContentError($"D3D12 stage linkage mismatch for {name}: no vertex shader satisfies fragment inputs");
        }
    }

    private static string? FindDxcExecutable()
    {
        string? env = Environment.GetEnvironmentVariable("DXC");
        if (!string.IsNullOrWhiteSpace(env) && File.Exists(env))
            return env;
        string pathEnv = Environment.GetEnvironmentVariable("PATH") ?? string.Empty;
        string exeName = OperatingSystem.IsWindows() ? "dxc.exe" : "dxc";
        foreach (string dir in pathEnv.Split(Path.PathSeparator, StringSplitOptions.RemoveEmptyEntries))
        {
            string candidate = Path.Combine(dir, exeName);
            if (File.Exists(candidate))
                return candidate;
        }
        return null;
    }

    private static string RunExternalProcess(string fileName, IReadOnlyList<string> arguments)
    {
        var psi = new ProcessStartInfo(fileName)
        {
            RedirectStandardOutput = true,
            RedirectStandardError = true,
            UseShellExecute = false,
            CreateNoWindow = true,
        };
        string currentPath = Environment.GetEnvironmentVariable("PATH") ?? string.Empty;
        if (!OperatingSystem.IsWindows() && !currentPath.Contains("/opt/homebrew/bin", StringComparison.Ordinal))
            psi.Environment["PATH"] = $"/opt/homebrew/bin:/usr/local/bin:{currentPath}";
        foreach (string arg in arguments)
            psi.ArgumentList.Add(arg);

        using var proc = Process.Start(psi) ?? throw new ContentError($"Failed to start {fileName}");
        string stdout = proc.StandardOutput.ReadToEnd();
        string stderr = proc.StandardError.ReadToEnd();
        proc.WaitForExit();
        if (proc.ExitCode != 0)
            throw new ContentError($"{fileName} exited with code {proc.ExitCode}: {(string.IsNullOrWhiteSpace(stderr) ? stdout : stderr).Trim()}");
        return stdout;
    }
}
