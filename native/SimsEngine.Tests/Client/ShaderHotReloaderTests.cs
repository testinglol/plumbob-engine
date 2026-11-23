using SimsSDL;

namespace SimsEngine.Tests.Client;

public sealed class ShaderHotReloaderTests
{
    [Fact]
    public void ResolveAffectedShaders_PropagatesTransitiveIncludes()
    {
        string tempDir = Path.Combine(Path.GetTempPath(), "sims-shader-hotreload-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(tempDir);
        try
        {
            File.WriteAllText(Path.Combine(tempDir, "base.glsl"), "float f() { return 1.0; }\n");
            File.WriteAllText(Path.Combine(tempDir, "mid.glsl"), "#include \"base.glsl\"\nfloat g() { return f(); }\n");
            File.WriteAllText(Path.Combine(tempDir, "ambient.frag"), "#include \"mid.glsl\"\nvoid main() {}\n");
            File.WriteAllText(Path.Combine(tempDir, "season.frag"), "#include \"base.glsl\"\nvoid main() {}\n");
            File.WriteAllText(Path.Combine(tempDir, "sprite.frag"), "void main() {}\n");

            List<string> fromBase = ShaderHotReloader.ResolveAffectedShaders(tempDir, ["base.glsl"]);
            Assert.Equal(["ambient.frag", "season.frag"], fromBase);

            List<string> fromMid = ShaderHotReloader.ResolveAffectedShaders(tempDir, ["mid.glsl"]);
            Assert.Equal(["ambient.frag"], fromMid);

            List<string> fromSprite = ShaderHotReloader.ResolveAffectedShaders(tempDir, ["sprite.frag"]);
            Assert.Equal(["sprite.frag"], fromSprite);
        }
        finally
        {
            Directory.Delete(tempDir, recursive: true);
        }
    }

    [Fact]
    public void ValidateMetalBindings_ChecksTextureSamplerAndVertexBufferSlots()
    {
        string reflectionJson = """
            {
              "ssbos": [{"name": "Vertices"}],
              "ubos": [{"name": "Quad"}],
              "textures": [{"name": "tex", "binding": 0}]
            }
            """;
        var reflection = ShaderHotReloader.ParseReflection(reflectionJson);
        Assert.True(reflection.HasSsbos);
        Assert.True(reflection.HasQuadUbo);
        Assert.Single(reflection.Textures);

        string validMsl = """
            vertex main0_out main0(constant Quad& quad [[buffer(0)]], const device Vertices& verts [[buffer(1)]], texture2d<float> tex [[texture(0)]], sampler texSmplr [[sampler(0)]])
            """;
        Assert.Empty(ShaderHotReloader.ValidateMetalBindings("avatar.vert", reflection, validMsl));

        string badSlotMsl = """
            vertex main0_out main0(constant Quad& quad [[buffer(0)]], const device Vertices& verts [[buffer(1)]], texture2d<float> tex [[texture(1)]], sampler texSmplr [[sampler(0)]])
            """;
        List<string> problems = ShaderHotReloader.ValidateMetalBindings("avatar.vert", reflection, badSlotMsl);
        Assert.Single(problems);
        Assert.Contains("tex texture slot 1, expected 0", problems[0], StringComparison.Ordinal);
    }

    [Fact]
    public void ProgramLayout_CoversAllProgramsAndFindsKnownShaderSpecs()
    {
        foreach (GPUContext.Program program in Enum.GetValues<GPUContext.Program>())
        {
            var (vertex, fragment, _, _, _) = GPUContext.ProgramLayout(program);
            Assert.EndsWith(".vert", vertex.Name, StringComparison.Ordinal);
            Assert.EndsWith(".frag", fragment.Name, StringComparison.Ordinal);
            Assert.NotNull(GPUContext.FindShaderSpec(vertex.Name));
            Assert.NotNull(GPUContext.FindShaderSpec(fragment.Name));
        }

        var ambientSpec = GPUContext.FindShaderSpec("ambient.frag");
        Assert.NotNull(ambientSpec);
        Assert.Equal(11u, ambientSpec.Value.Samplers);
        Assert.Equal(1u, ambientSpec.Value.Uniforms);
    }
}
