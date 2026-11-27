using System.Text.Json;
using SimsSDL;
using SimsSDL.Client;
using Xunit;

namespace SimsEngine.Tests.Client;

public sealed class SpirvAndPackToolTests
{
    private static string RepoRoot =>
        Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "..", "..", "..", "..", ".."));

    [Fact]
    public void SpirvReflectionMatchesAllCoreShaders()
    {
        string shaderDir = Path.Combine(RepoRoot, "native", "SimsSDL", "Shaders");
        var expected = new Dictionary<string, (int Stage, uint Samplers, uint Storage, uint Uniforms)>(StringComparer.Ordinal)
        {
            ["avatar.frag.spv"] = (1, 1, 0, 0),
            ["avatar.vert.spv"] = (0, 0, 1, 1),
            ["avatarMask.frag.spv"] = (1, 1, 0, 0),
            ["censor.frag.spv"] = (1, 2, 0, 0),
            ["depthOnly.frag.spv"] = (1, 0, 0, 0),
            ["fullscreen.vert.spv"] = (0, 0, 0, 0),
            ["ghost.frag.spv"] = (1, 1, 0, 0),
            ["groundDepth.vert.spv"] = (0, 0, 1, 1),
            ["heightScatter.vert.spv"] = (0, 1, 0, 1),
            ["placement.frag.spv"] = (1, 0, 0, 0),
            ["sprite.frag.spv"] = (1, 1, 0, 0),
            ["sprite.vert.spv"] = (0, 0, 0, 1),
            ["spriteBatch.vert.spv"] = (0, 0, 1, 1),
            ["spriteDepth.frag.spv"] = (1, 2, 0, 0),
            ["surface.frag.spv"] = (1, 1, 0, 0),
            ["terrain.frag.spv"] = (1, 0, 0, 0),
            ["terrain.vert.spv"] = (0, 0, 1, 1),
        };

        foreach (var (fileName, spec) in expected)
        {
            var reflected = SpirvReflection.Reflect(File.ReadAllBytes(Path.Combine(shaderDir, fileName)));
            Assert.Equal(spec.Stage, reflected.Stage);
            Assert.Equal(spec.Samplers, reflected.Samplers);
            Assert.Equal(spec.Storage, reflected.StorageBuffers);
            Assert.Equal(spec.Uniforms, reflected.UniformBuffers);
        }
    }

    [Fact]
    public void SpirvReflectionReflectsAllBundledPackShaders()
    {
        string packsDir = Path.Combine(RepoRoot, "packs");
        var spvFiles = Directory.EnumerateFiles(packsDir, "*.spv", SearchOption.AllDirectories).ToList();
        Assert.NotEmpty(spvFiles);

        foreach (string spvPath in spvFiles)
        {
            var reflected = SpirvReflection.Reflect(File.ReadAllBytes(spvPath));
            int expectedStage = spvPath.Contains(".vert.", StringComparison.Ordinal) ? 0 : 1;
            Assert.Equal(expectedStage, reflected.Stage);
        }

        string lightingShaderDir = Path.Combine(packsDir, "lighting", "files", "Downloads", "local.lighting", "shaders");
        string[] lightingSpv = Directory.EnumerateFiles(lightingShaderDir, "*.spv").Select(static p => Path.GetFileName(p)!).OrderBy(static n => n).ToArray();
        Assert.Equal(new[] { "ambient.frag.spv", "ambientBlur.frag.spv", "radiance.frag.spv", "sunShadow.frag.spv" }, lightingSpv);

        string seasonsShaderDir = Path.Combine(packsDir, "seasons", "files", "Downloads", "local.seasons", "shaders");
        string[] seasonsSpv = Directory.EnumerateFiles(seasonsShaderDir, "*.spv").Select(static p => Path.GetFileName(p)!).OrderBy(static n => n).ToArray();
        Assert.Equal(new[] { "atmosphere.frag.spv", "season.frag.spv", "terrain.frag.spv", "trail.frag.spv" }, seasonsSpv);
    }

    [Fact]
    public void PackToolSealWritesDeterministicResourcesManifest()
    {
        string tempDir = Path.Combine(Path.GetTempPath(), "plumbob-packtool-test-" + Guid.NewGuid().ToString("N"));
        try
        {
            Directory.CreateDirectory(Path.Combine(tempDir, "files", "Downloads", "local.test"));
            File.WriteAllText(Path.Combine(tempDir, "pack.json"), """
                {
                  "schemaVersion": 1,
                  "id": "local.test",
                  "name": "Test Pack",
                  "version": "1.0.0",
                  "baseGameVersion": "1.90",
                  "dependencies": [],
                  "overrides": []
                }
                """);
            File.WriteAllBytes(Path.Combine(tempDir, "files", "Downloads", "local.test", "Sample.TXT"), "hello"u8.ToArray());

            byte[] reportBytes = PackTool.SealPack(tempDir);
            using var report = JsonDocument.Parse(reportBytes);
            Assert.Equal("local.test", report.RootElement.GetProperty("packId").GetString());
            Assert.Equal(1, report.RootElement.GetProperty("resourcesSealed").GetInt32());

            string resourcesJson = File.ReadAllText(Path.Combine(tempDir, "plugin", "resources.json"));
            using var resources = JsonDocument.Parse(resourcesJson);
            Assert.Equal(
                "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824",
                resources.RootElement.GetProperty("downloads/local.test/sample.txt").GetString());
        }
        finally
        {
            if (Directory.Exists(tempDir))
                Directory.Delete(tempDir, recursive: true);
        }
    }
}
