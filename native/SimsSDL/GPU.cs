using System.Collections.Concurrent;
using System.Numerics;

namespace SimsSDL;

public sealed class SDLError : Exception
{
    public SDLError(string context)
        : base($"{context}: {SDL_GetError()}")
    {
    }
}

[StructLayout(LayoutKind.Sequential)]
public struct Quad
{
    public Vector4 Rect;
    public Vector4 CanvasPadding;
    public Vector4 UvRect;
    public Vector4 DepthInterval;
    public Vector4 Tint;

    public Quad()
    {
        Rect = Vector4.Zero;
        CanvasPadding = Vector4.Zero;
        UvRect = new Vector4(0f, 0f, 1f, 1f);
        DepthInterval = Vector4.Zero;
        Tint = Vector4.One;
    }

    public Quad(Vector4 rect, Vector2 canvas, bool flip = false, float opacity = 1f)
    {
        Rect = rect;
        CanvasPadding = new Vector4(canvas.X, canvas.Y, flip ? 1f : 0f, opacity);
        UvRect = new Vector4(0f, 0f, 1f, 1f);
        DepthInterval = Vector4.Zero;
        Tint = Vector4.One;
    }
}

[StructLayout(LayoutKind.Sequential)]
public struct TerrainVertex
{
    public Vector2 Position;

    // x: grass blade/wear state [0..1] (terrain.frag); y: ground depth (groundDepth.vert).
    public Vector2 Grass;

    // Normalized sRGB Color/Dark ramp endpoints interpolated in sRGB before toLinear in terrain.frag.
    public Vector4 Color;
    public Vector4 Dark;

    public TerrainVertex()
    {
        Position = Vector2.Zero;
        Grass = Vector2.Zero;
        Color = Vector4.Zero;
        Dark = Vector4.Zero;
    }

    public TerrainVertex(Vector2 position, Vector2 grass, Vector4 color, Vector4 dark)
    {
        Position = position;
        Grass = grass;
        Color = color;
        Dark = dark;
    }
}

[StructLayout(LayoutKind.Sequential)]
public struct AvatarVertex
{
    public Vector4 Position;
    public Vector2 Uv;
    public Vector2 Padding;
    public Vector4 Normal;

    public AvatarVertex()
    {
        Position = Vector4.Zero;
        Uv = Vector2.Zero;
        Padding = Vector2.Zero;
        Normal = Vector4.Zero;
    }

    public AvatarVertex(Vector4 position, Vector2 uv, Vector4 normal)
    {
        Position = position;
        Uv = uv;
        Padding = Vector2.Zero;
        Normal = normal;
    }
}

[StructLayout(LayoutKind.Sequential)]
public struct SpriteBatchVertex
{
    public Vector4 Rect;
    public Vector4 UvRect;
    public Vector4 Tint;
    public Vector4 Params;

    public SpriteBatchVertex(Vector4 rect, Vector4 uvRect, Vector4 tint, float flip, float opacity, float uiThreshold, float antiAlias)
    {
        Rect = rect;
        UvRect = uvRect;
        Tint = tint;
        Params = new Vector4(flip, opacity, uiThreshold, antiAlias);
    }
}

// Refcounted so child textures/buffers finalize before SDL_DestroyGPUDevice regardless of GC finalizer order.
public sealed class GPUDevice : IDisposable
{
    private nint _handle;
    private int _refs;
    private int _ownerReleased;

    public nint Handle => Volatile.Read(ref _handle);

    public GPUDevice(nint handle)
    {
        if (handle == nint.Zero)
            throw new ArgumentException("GPU device handle cannot be zero.", nameof(handle));
        _handle = handle;
        _refs = 1;
    }

    internal bool Retain()
    {
        while (true)
        {
            int current = Volatile.Read(ref _refs);
            if (current <= 0)
                return false;
            if (Interlocked.CompareExchange(ref _refs, current + 1, current) == current)
                return true;
        }
    }

    internal void ReleaseRef()
    {
        if (Interlocked.Decrement(ref _refs) == 0)
        {
            nint handle = Interlocked.Exchange(ref _handle, nint.Zero);
            if (handle != nint.Zero)
                SDL_DestroyGPUDevice(handle);
        }
    }

    private void ReleaseOwnerRef()
    {
        if (Interlocked.Exchange(ref _ownerReleased, 1) == 0)
            ReleaseRef();
    }

    public void Dispose()
    {
        ReleaseOwnerRef();
        GC.SuppressFinalize(this);
    }

    ~GPUDevice() => ReleaseOwnerRef();
}

public sealed class GPUTexture : IDisposable
{
    private readonly GPUDevice _device;
    private readonly long _byteSize;
    private nint _handle;
    private int _disposed;
    private int _refs = 1;
    private Action<GPUTexture>? _onZeroRefs;

    public nint Handle => Volatile.Read(ref _handle);
    public int Width { get; }
    public int Height { get; }
    public uint Format { get; }
    public uint NumLevels { get; }
    public int SampleCount { get; }

    public GPUTexture(
        nint handle,
        int width,
        int height,
        uint format,
        GPUDevice device,
        long byteSize = -1,
        uint numLevels = 1,
        int sampleCount = SDL_GPU_SAMPLECOUNT_1)
    {
        ArgumentNullException.ThrowIfNull(device);
        if (handle == nint.Zero)
            throw new ArgumentException("GPU texture handle cannot be zero.", nameof(handle));
        if (!device.Retain())
            throw new ObjectDisposedException(nameof(GPUDevice));
        _handle = handle;
        Width = width;
        Height = height;
        Format = format;
        NumLevels = Math.Max(1u, numLevels);
        SampleCount = sampleCount;
        _device = device;
        _byteSize = byteSize >= 0 ? byteSize : EstimateByteSize(width, height, format, NumLevels, sampleCount);
        if (_byteSize > 0)
            GC.AddMemoryPressure(_byteSize);
    }

    private static long EstimateByteSize(int width, int height, uint format, uint numLevels, int sampleCount)
    {
        long baseBytes = (long)Math.Max(1, width) * Math.Max(1, height) * format switch
        {
            SDL_GPU_TEXTUREFORMAT_R8_UNORM => 1L,
            SDL_GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT => 8L,
            _ => 4L,
        };
        long samples = sampleCount switch
        {
            SDL_GPU_SAMPLECOUNT_2 => 2L,
            SDL_GPU_SAMPLECOUNT_4 => 4L,
            _ => 1L,
        };
        long scaled = baseBytes * samples;
        return numLevels > 1 ? scaled * 4L / 3L : scaled;
    }

    private void ReleaseNative()
    {
        if (Interlocked.Exchange(ref _disposed, 1) != 0)
            return;
        nint handle = Interlocked.Exchange(ref _handle, nint.Zero);
        if (handle != nint.Zero)
        {
            nint dev = _device.Handle;
            if (dev != nint.Zero)
                SDL_ReleaseGPUTexture(dev, handle);
        }
        if (_byteSize > 0)
            GC.RemoveMemoryPressure(_byteSize);
        _device.ReleaseRef();
    }

    internal bool TryRetain()
    {
        while (true)
        {
            int current = Volatile.Read(ref _refs);
            if (current <= 0 || Volatile.Read(ref _disposed) != 0)
                return false;
            if (Interlocked.CompareExchange(ref _refs, current + 1, current) == current)
                return true;
        }
    }

    internal void SetZeroRefCallback(Action<GPUTexture> callback)
    {
        _onZeroRefs = callback;
    }

    public void Dispose()
    {
        if (Interlocked.Decrement(ref _refs) == 0)
        {
            _onZeroRefs?.Invoke(this);
            ReleaseNative();
            GC.SuppressFinalize(this);
        }
    }

    ~GPUTexture() => ReleaseNative();
}

public sealed class GPUBuffer : IDisposable
{
    private readonly GPUDevice _device;
    private readonly long _byteSize;
    private nint _handle;
    private int _disposed;

    public nint Handle => Volatile.Read(ref _handle);
    public int Count { get; }
    public long ByteSize => _byteSize;

    public GPUBuffer(nint handle, int count, GPUDevice device, long byteSize = 0)
    {
        ArgumentNullException.ThrowIfNull(device);
        if (handle == nint.Zero)
            throw new ArgumentException("GPU buffer handle cannot be zero.", nameof(handle));
        if (!device.Retain())
            throw new ObjectDisposedException(nameof(GPUDevice));
        _handle = handle;
        Count = count;
        _device = device;
        _byteSize = byteSize > 0 ? byteSize : Math.Max(0L, count);
        if (_byteSize > 0)
            GC.AddMemoryPressure(_byteSize);
    }

    private void ReleaseNative()
    {
        if (Interlocked.Exchange(ref _disposed, 1) != 0)
            return;
        nint handle = Interlocked.Exchange(ref _handle, nint.Zero);
        if (handle != nint.Zero)
        {
            nint dev = _device.Handle;
            if (dev != nint.Zero)
                SDL_ReleaseGPUBuffer(dev, handle);
        }
        if (_byteSize > 0)
            GC.RemoveMemoryPressure(_byteSize);
        _device.ReleaseRef();
    }

    public void Dispose()
    {
        ReleaseNative();
        GC.SuppressFinalize(this);
    }

    ~GPUBuffer() => ReleaseNative();
}

public sealed class GPUContext : IDisposable
{
    public enum DepthMode
    {
        Flat,
        Mesh,
        MeshEdge,
        MeshDepthPrepass,
        MeshDepthBack,
        MeshEqual,
    }

    public enum Program
    {
        Sprite,
        SpriteBatch,
        Ghost,
        SpriteDepth,
        Terrain,
        Placement,
        Surface,
        Avatar,
        Ambient,
        AmbientBlur,
        Atmosphere,
        Season,
        Trail,
        GroundDepth,
        HeightScatter,
        AvatarMask,
        Censor,
    }

    public const uint ColorFormat = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB;

    public const uint LiftFormat = SDL_GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT;

    public const uint DepthFormat = SDL_GPU_TEXTUREFORMAT_D32_FLOAT;

    public const uint MaskFormat = SDL_GPU_TEXTUREFORMAT_R8_UNORM;

    public readonly record struct SharedTextureKey(int Width, int Height, bool Depth8, bool Mipmapped, ulong Hash1, ulong Hash2);

    internal readonly record struct ShaderSpec(string Name, int Stage, uint Samplers = 0, uint StorageBuffers = 0, uint Uniforms = 0);

    private readonly record struct PipelineKey(Program Program, DepthMode Depth, int SampleCount, string EffectPart);

    private readonly GPUDevice _owner;
    private readonly Dictionary<string, nint> _shaders = new(StringComparer.Ordinal);
    private readonly Dictionary<PipelineKey, nint> _pipelines = new();
    private readonly Dictionary<PipelineKey, (nint Vertex, nint Fragment)> _pipelineShaderHandles = new();
    private readonly Dictionary<string, string> _hotCoreShaders = new(StringComparer.Ordinal);
    private readonly Dictionary<string, string> _hotEffectShaders = new(StringComparer.Ordinal);
    private readonly ConcurrentDictionary<SharedTextureKey, GPUTexture> _sharedTextures = new();
    private nint _batchCommand;
    private nint _batchCopy;
    private int _disposed;

    public static SharedTextureKey ComputeContentKey(int width, int height, bool depth8, bool mipmapped, ReadOnlySpan<byte> pixels)
    {
        ulong h1 = 14695981039346656037UL ^ (uint)pixels.Length;
        ulong h2 = 0x9E3779B97F4A7C15UL ^ ((ulong)(uint)width << 32) ^ (uint)height;
        int i = 0;
        int limit = pixels.Length - 7;
        while (i < limit)
        {
            ulong v = MemoryMarshal.Read<ulong>(pixels.Slice(i, 8));
            h1 = (h1 ^ v) * 1099511628211UL;
            h2 = BitOperations.RotateLeft(h2 ^ (v * 0xBF58476D1CE4E5B9UL), 27) * 0x94D049BB133111EBUL;
            i += 8;
        }
        while (i < pixels.Length)
        {
            byte b = pixels[i++];
            h1 = (h1 ^ b) * 1099511628211UL;
            h2 = BitOperations.RotateLeft(h2 + b, 11) * 0x94D049BB133111EBUL;
        }
        return new SharedTextureKey(width, height, depth8, mipmapped, h1, h2);
    }

    public bool ContainsSharedTexture(SharedTextureKey key) =>
        _sharedTextures.TryGetValue(key, out GPUTexture? existing) && existing.Handle != nint.Zero;

    public GPUTexture? TryAcquireSharedTexture(SharedTextureKey key)
    {
        if (_sharedTextures.TryGetValue(key, out GPUTexture? existing) && existing.TryRetain())
            return existing;
        return null;
    }

    public void RegisterSharedTexture(SharedTextureKey key, GPUTexture texture)
    {
        texture.SetZeroRefCallback(t => _sharedTextures.TryRemove(new KeyValuePair<SharedTextureKey, GPUTexture>(key, t)));
        _sharedTextures[key] = texture;
    }

    public nint Device => _owner.Handle;
    public string DriverName => SDL_GetGPUDeviceDriver(Device);
    public int PreferredSampleCount { get; private set; }
    public nint Sampler { get; private set; }
    public nint RoofSampler { get; private set; }
    public nint AnisoSampler { get; private set; }

    public nint PixelSampler { get; private set; }

    public Dictionary<string, string> EffectShaders { get; set; } = new(StringComparer.Ordinal);
    public IReadOnlyDictionary<string, string> HotCoreShaders => _hotCoreShaders;
    public IReadOnlyDictionary<string, string> HotEffectShaders => _hotEffectShaders;
    public bool UsesMetalShaders => (SDL_GetGPUShaderFormats(Device) & SDL_GPU_SHADERFORMAT_MSL) != 0;
    public bool UsesDxilShaders => !UsesMetalShaders && (SDL_GetGPUShaderFormats(Device) & SDL_GPU_SHADERFORMAT_DXIL) != 0;

    public nint SpriteDepthPipeline => Pipeline(Program.SpriteDepth, DepthMode.Mesh);
    public nint SpriteDepthEdgePipeline => Pipeline(Program.SpriteDepth, DepthMode.MeshEdge);

    public GPUContext(string? preferredDriver = null)
    {
        string? driverHint = string.IsNullOrWhiteSpace(preferredDriver)
            ? Environment.GetEnvironmentVariable("SIMS_GPU_DRIVER")
            : preferredDriver;
        if (string.IsNullOrWhiteSpace(driverHint))
            driverHint = null;

        uint requestedFormats = SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_MSL |
            (ShaderDirectory is { } shaderDir && File.Exists(Path.Combine(shaderDir, "sprite.vert.dxil")) ? SDL_GPU_SHADERFORMAT_DXIL : 0);
        AppLog.Info(FormattableString.Invariant(
            $"Calling SDL_CreateGPUDevice (requestedFormats=0x{requestedFormats:X}, driverHint={driverHint ?? "<auto>"})..."));
        nint device = SDL_CreateGPUDevice(requestedFormats, false, driverHint);
        if (device == nint.Zero)
            throw new SDLError("SDL_CreateGPUDevice");

        _owner = new GPUDevice(device);
        // Retain device so child resources finalize before the device is destroyed.
        _owner.Retain();
        try
        {
            PreferredSampleCount = SDL_GPU_SAMPLECOUNT_1;
            foreach (int candidate in new[] { SDL_GPU_SAMPLECOUNT_4, SDL_GPU_SAMPLECOUNT_2 })
            {
                if (SDL_GPUTextureSupportsSampleCount(Device, ColorFormat, candidate) &&
                    SDL_GPUTextureSupportsSampleCount(Device, DepthFormat, candidate))
                {
                    PreferredSampleCount = candidate;
                    break;
                }
            }

            Sampler = MakeSampler(SDL_GPU_FILTER_LINEAR, SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE);
            RoofSampler = MakeSampler(SDL_GPU_FILTER_LINEAR, SDL_GPU_SAMPLERADDRESSMODE_REPEAT, SDL_GPU_SAMPLERMIPMAPMODE_LINEAR, 16f);
            AnisoSampler = MakeSampler(SDL_GPU_FILTER_LINEAR, SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE, SDL_GPU_SAMPLERMIPMAPMODE_LINEAR, 16f);
            PixelSampler = MakeSampler(SDL_GPU_FILTER_NEAREST, SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE);
        }
        catch
        {
            ReleaseNative();
            GC.SuppressFinalize(this);
            throw;
        }
    }

    private nint MakeSampler(
        int filter,
        int address,
        int mipmapMode = SDL_GPU_SAMPLERMIPMAPMODE_NEAREST,
        float maxAnisotropy = 1f)
    {
        var info = new SDL_GPUSamplerCreateInfo
        {
            min_filter = filter,
            mag_filter = filter,
            mipmap_mode = mipmapMode,
            address_mode_u = address,
            address_mode_v = address,
            address_mode_w = address,
            max_lod = mipmapMode == SDL_GPU_SAMPLERMIPMAPMODE_LINEAR ? 1000f : 0f,
            enable_anisotropy = maxAnisotropy > 1f ? (byte)1 : (byte)0,
            max_anisotropy = maxAnisotropy,
        };
        nint sampler = SDL_CreateGPUSampler(Device, in info);
        if (sampler == nint.Zero)
            throw new SDLError("SDL_CreateGPUSampler");
        return sampler;
    }

    internal static string? ResolvedShaderDirectory => ShaderDirectory;

    private static string? ShaderDirectory
    {
        get
        {
            string? env = Environment.GetEnvironmentVariable("SIMS_SDL_SHADERS");
            if (!string.IsNullOrEmpty(env))
                return env;
            return SimsAssetPaths.FindShadersDirectory();
        }
    }

    public bool SupportsShaderAsset(string basePath)
    {
        if (string.IsNullOrWhiteSpace(basePath))
            return false;

        uint formats = SDL_GetGPUShaderFormats(Device);
        if ((formats & SDL_GPU_SHADERFORMAT_MSL) != 0)
            return File.Exists(basePath + ".msl");
        if ((formats & SDL_GPU_SHADERFORMAT_DXIL) != 0 && File.Exists(basePath + ".dxil"))
            return true;
        if ((formats & SDL_GPU_SHADERFORMAT_SPIRV) != 0 && File.Exists(basePath + ".spv"))
            return true;
        return false;
    }

    internal static (ShaderSpec Vertex, ShaderSpec Fragment, bool Blended, bool Multiplied, bool DepthOnly) ProgramLayout(Program program) =>
        program switch
        {
            Program.GroundDepth => (
                new ShaderSpec("groundDepth.vert", SDL_GPU_SHADERSTAGE_VERTEX, StorageBuffers: 1, Uniforms: 1),
                new ShaderSpec("depthOnly.frag", SDL_GPU_SHADERSTAGE_FRAGMENT),
                true, false, true),
            Program.HeightScatter => (
                new ShaderSpec("heightScatter.vert", SDL_GPU_SHADERSTAGE_VERTEX, Samplers: 1, Uniforms: 1),
                new ShaderSpec("depthOnly.frag", SDL_GPU_SHADERSTAGE_FRAGMENT),
                true, false, true),
            Program.Ambient => (
                new ShaderSpec("fullscreen.vert", SDL_GPU_SHADERSTAGE_VERTEX),
                new ShaderSpec("ambient.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 11, Uniforms: 1),
                false, true, false),
            Program.AmbientBlur => (
                new ShaderSpec("fullscreen.vert", SDL_GPU_SHADERSTAGE_VERTEX),
                new ShaderSpec("ambientBlur.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 4, Uniforms: 1),
                true, true, false),
            Program.Atmosphere => (
                new ShaderSpec("fullscreen.vert", SDL_GPU_SHADERSTAGE_VERTEX),
                new ShaderSpec("atmosphere.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 4, Uniforms: 1),
                true, false, false),
            Program.Season => (
                new ShaderSpec("fullscreen.vert", SDL_GPU_SHADERSTAGE_VERTEX),
                new ShaderSpec("season.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 9, Uniforms: 1),
                true, false, false),
            Program.Trail => (
                new ShaderSpec("fullscreen.vert", SDL_GPU_SHADERSTAGE_VERTEX),
                new ShaderSpec("trail.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 1, Uniforms: 1),
                false, false, false),
            Program.SpriteBatch => (
                new ShaderSpec("spriteBatch.vert", SDL_GPU_SHADERSTAGE_VERTEX, StorageBuffers: 1, Uniforms: 1),
                new ShaderSpec("sprite.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 1),
                true, false, false),
            Program.Sprite => (
                new ShaderSpec("sprite.vert", SDL_GPU_SHADERSTAGE_VERTEX, Uniforms: 1),
                new ShaderSpec("sprite.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 1),
                true, false, false),
            Program.Ghost => (
                new ShaderSpec("sprite.vert", SDL_GPU_SHADERSTAGE_VERTEX, Uniforms: 1),
                new ShaderSpec("ghost.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 1),
                true, false, false),
            Program.SpriteDepth => (
                new ShaderSpec("sprite.vert", SDL_GPU_SHADERSTAGE_VERTEX, Uniforms: 1),
                new ShaderSpec("spriteDepth.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 2),
                true, false, false),
            Program.Censor => (
                new ShaderSpec("sprite.vert", SDL_GPU_SHADERSTAGE_VERTEX, Uniforms: 1),
                new ShaderSpec("censor.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 2),
                false, false, false),
            Program.Terrain => (
                new ShaderSpec("terrain.vert", SDL_GPU_SHADERSTAGE_VERTEX, StorageBuffers: 1, Uniforms: 1),
                new ShaderSpec("terrain.frag", SDL_GPU_SHADERSTAGE_FRAGMENT),
                false, false, false),
            Program.Placement => (
                new ShaderSpec("terrain.vert", SDL_GPU_SHADERSTAGE_VERTEX, StorageBuffers: 1, Uniforms: 1),
                new ShaderSpec("placement.frag", SDL_GPU_SHADERSTAGE_FRAGMENT),
                true, false, false),
            Program.Surface => (
                new ShaderSpec("avatar.vert", SDL_GPU_SHADERSTAGE_VERTEX, StorageBuffers: 1, Uniforms: 1),
                new ShaderSpec("surface.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 1),
                true, false, false),
            Program.Avatar => (
                new ShaderSpec("avatar.vert", SDL_GPU_SHADERSTAGE_VERTEX, StorageBuffers: 1, Uniforms: 1),
                new ShaderSpec("avatar.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 1),
                true, false, false),
            Program.AvatarMask => (
                new ShaderSpec("avatar.vert", SDL_GPU_SHADERSTAGE_VERTEX, StorageBuffers: 1, Uniforms: 1),
                new ShaderSpec("avatarMask.frag", SDL_GPU_SHADERSTAGE_FRAGMENT, Samplers: 1),
                false, false, false),
            _ => throw new ArgumentOutOfRangeException(nameof(program), program, null),
        };

    internal static ShaderSpec? FindShaderSpec(string name)
    {
        foreach (Program program in Enum.GetValues<Program>())
        {
            var (vertex, fragment, _, _, _) = ProgramLayout(program);
            if (string.Equals(vertex.Name, name, StringComparison.Ordinal))
                return vertex;
            if (string.Equals(fragment.Name, name, StringComparison.Ordinal))
                return fragment;
        }
        return null;
    }

    private string CurrentEffectPart() =>
        EffectShaders.Count == 0
            ? string.Empty
            : string.Join("|", EffectShaders.OrderBy(static kv => kv.Key, StringComparer.Ordinal).Select(static kv => kv.Value));

    private string? ResolveShaderSource(
        string name,
        IReadOnlyDictionary<string, string>? coreOverrides = null,
        IReadOnlyDictionary<string, string>? effectOverrides = null)
    {
        if (EffectShaders.TryGetValue(name, out string? effectPath))
        {
            IReadOnlyDictionary<string, string> eff = effectOverrides ?? _hotEffectShaders;
            return eff.TryGetValue(name, out string? hotEffect) ? hotEffect : effectPath;
        }

        IReadOnlyDictionary<string, string> core = coreOverrides ?? _hotCoreShaders;
        if (core.TryGetValue(name, out string? hotCore))
            return hotCore;

        return ShaderDirectory is { Length: > 0 } dir
            ? Path.Combine(dir, name)
            : null;
    }

    private unsafe nint CreateShaderHandle(ShaderSpec spec, string? source)
    {
        uint formats = SDL_GetGPUShaderFormats(Device);
        bool metal = (formats & SDL_GPU_SHADERFORMAT_MSL) != 0;
        bool dxil = !metal && (formats & SDL_GPU_SHADERFORMAT_DXIL) != 0 && source is not null && File.Exists(source + ".dxil");
        if (string.IsNullOrEmpty(source))
            throw new ContentError("SDL shaders are missing");

        string path = source + (metal ? ".msl" : dxil ? ".dxil" : ".spv");
        byte[] code;
        if (metal)
        {
            string text = File.ReadAllText(path, Encoding.UTF8)
                .Replace("#include <simd/simd.h>", string.Empty, StringComparison.Ordinal);
            int byteCount = Encoding.UTF8.GetByteCount(text);
            code = new byte[byteCount + 1];
            Encoding.UTF8.GetBytes(text, 0, text.Length, code, 0);
            code[byteCount] = 0;
        }
        else
        {
            code = File.ReadAllBytes(path);
        }

        if (code.Length == 0)
            throw new ContentError($"Empty SDL shader: {path}");

        ReadOnlySpan<byte> entryBytes = metal ? "main0\0"u8 : "main\0"u8;
        nint created;
        fixed (byte* codePtr = code)
        fixed (byte* entryPtr = entryBytes)
        {
            var info = new SDL_GPUShaderCreateInfo
            {
                code_size = (nuint)code.Length,
                code = (nint)codePtr,
                entrypoint = (nint)entryPtr,
                format = metal ? SDL_GPU_SHADERFORMAT_MSL : dxil ? SDL_GPU_SHADERFORMAT_DXIL : SDL_GPU_SHADERFORMAT_SPIRV,
                stage = spec.Stage,
                num_samplers = spec.Samplers,
                num_storage_buffers = spec.StorageBuffers,
                num_uniform_buffers = spec.Uniforms,
            };
            created = SDL_CreateGPUShader(Device, in info);
        }

        if (created == nint.Zero)
            throw new SDLError($"SDL_CreateGPUShader {spec.Name}");
        return created;
    }

    private nint Shader(ShaderSpec spec)
    {
        string? source = ResolveShaderSource(spec.Name);
        string key = source ?? spec.Name;
        if (_shaders.TryGetValue(key, out nint cached))
            return cached;

        nint created = CreateShaderHandle(spec, source);
        _shaders[key] = created;
        return created;
    }

    private unsafe nint CreateGraphicsPipelineHandle(
        Program program,
        DepthMode depth,
        int sampleCount,
        nint vertex,
        nint fragment,
        bool blended,
        bool multiplied,
        bool depthOnly)
    {
        var color = new SDL_GPUColorTargetDescription
        {
            format = program == Program.AvatarMask ? MaskFormat : ColorFormat,
            blend_state = depth is DepthMode.MeshDepthPrepass or DepthMode.MeshDepthBack
                ? new SDL_GPUColorTargetBlendState
                {
                    enable_blend = 0,
                    enable_color_write_mask = 1,
                    color_write_mask = 0,
                }
                : new SDL_GPUColorTargetBlendState
                {
                    enable_blend = blended ? (byte)1 : (byte)0,
                    src_color_blendfactor = SDL_GPU_BLENDFACTOR_ONE,
                    dst_color_blendfactor = SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,
                    color_blend_op = SDL_GPU_BLENDOP_ADD,
                    src_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ONE,
                    dst_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,
                    alpha_blend_op = SDL_GPU_BLENDOP_ADD,
                },
        };
        if (multiplied && depth is not (DepthMode.MeshDepthPrepass or DepthMode.MeshDepthBack))
        {
            // Double modulate blend: ambient is written at half scale so lamps brighten.
            color.blend_state.src_color_blendfactor = SDL_GPU_BLENDFACTOR_DST_COLOR;
            color.blend_state.dst_color_blendfactor = SDL_GPU_BLENDFACTOR_SRC_COLOR;
            color.blend_state.src_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ZERO;
            color.blend_state.dst_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ONE;
        }

        bool noDepth = multiplied
            || program == Program.Atmosphere
            || program == Program.Season
            || program == Program.Trail
            || program == Program.Censor;

        int targetCount = program == Program.Season ? 2 : 1;
        SDL_GPUColorTargetDescription* targets = stackalloc SDL_GPUColorTargetDescription[2];
        targets[0] = color;
        if (program == Program.Season)
        {
            // Writes snow surface positions for the ambient pass to evaluate lighting.
            targets[1] = new SDL_GPUColorTargetDescription { format = LiftFormat };
        }

        var info = new SDL_GPUGraphicsPipelineCreateInfo
        {
            vertex_shader = vertex,
            fragment_shader = fragment,
            primitive_type = program == Program.HeightScatter ? SDL_GPU_PRIMITIVETYPE_POINTLIST : SDL_GPU_PRIMITIVETYPE_TRIANGLELIST,
            rasterizer_state = new SDL_GPURasterizerState
            {
                fill_mode = SDL_GPU_FILLMODE_FILL,
                cull_mode = SDL_GPU_CULLMODE_NONE,
            },
            multisample_state = new SDL_GPUMultisampleState
            {
                sample_count = sampleCount,
            },
            depth_stencil_state = new SDL_GPUDepthStencilState
            {
                enable_depth_test = !noDepth ? (byte)1 : (byte)0,
                // Mask and translucent sprite-edge passes read depth without writing to it.
                enable_depth_write = (depth is DepthMode.Mesh or DepthMode.MeshDepthPrepass or DepthMode.MeshDepthBack && !noDepth && program != Program.AvatarMask) ? (byte)1 : (byte)0,
                compare_op = depth == DepthMode.Flat ? SDL_GPU_COMPAREOP_ALWAYS
                    : depth == DepthMode.MeshEqual ? SDL_GPU_COMPAREOP_EQUAL
                    : depth == DepthMode.MeshDepthBack ? SDL_GPU_COMPAREOP_GREATER_OR_EQUAL
                    : SDL_GPU_COMPAREOP_LESS_OR_EQUAL,
            },
            target_info = new SDL_GPUGraphicsPipelineTargetInfo
            {
                color_target_descriptions = depthOnly ? nint.Zero : (nint)targets,
                num_color_targets = depthOnly ? 0u : (uint)targetCount,
                depth_stencil_format = DepthFormat,
                has_depth_stencil_target = !noDepth ? (byte)1 : (byte)0,
            },
        };
        if (depthOnly)
        {
            info.depth_stencil_state.enable_depth_write = 1;
            info.depth_stencil_state.compare_op = SDL_GPU_COMPAREOP_LESS_OR_EQUAL;
        }

        nint created = SDL_CreateGPUGraphicsPipeline(Device, in info);
        if (created == nint.Zero)
            throw new SDLError($"SDL_CreateGPUGraphicsPipeline {program}-{depth}-{sampleCount}");
        return created;
    }

    public nint Pipeline(Program program, DepthMode depth, int sampleCount = SDL_GPU_SAMPLECOUNT_1)
    {
        var key = new PipelineKey(program, depth, sampleCount, CurrentEffectPart());
        if (_pipelines.TryGetValue(key, out nint cached))
            return cached;

        var (vertexSpec, fragmentSpec, blended, multiplied, depthOnly) = ProgramLayout(program);
        nint vertex = Shader(vertexSpec);
        nint fragment = Shader(fragmentSpec);
        nint created = CreateGraphicsPipelineHandle(program, depth, sampleCount, vertex, fragment, blended, multiplied, depthOnly);
        _pipelines[key] = created;
        _pipelineShaderHandles[key] = (vertex, fragment);
        return created;
    }

    public bool TryHotReloadShaders(
        IReadOnlyDictionary<string, string>? coreUpdates,
        IReadOnlyDictionary<string, string>? effectUpdates,
        Action waitForGpuIdle,
        out string? error)
    {
        ArgumentNullException.ThrowIfNull(waitForGpuIdle);

        var nextCore = new Dictionary<string, string>(_hotCoreShaders, StringComparer.Ordinal);
        var nextEffect = new Dictionary<string, string>(_hotEffectShaders, StringComparer.Ordinal);
        var changedNames = new HashSet<string>(StringComparer.Ordinal);

        if (coreUpdates is not null)
        {
            foreach (var (name, path) in coreUpdates)
            {
                nextCore[name] = path;
                changedNames.Add(name);
            }
        }

        if (effectUpdates is not null)
        {
            foreach (var (name, path) in effectUpdates)
            {
                nextEffect[name] = path;
                changedNames.Add(name);
            }
        }

        return ApplyHotShaderState(nextCore, nextEffect, changedNames, waitForGpuIdle, out error);
    }

    public bool ResetHotShaders(Action waitForGpuIdle, out string? error)
    {
        ArgumentNullException.ThrowIfNull(waitForGpuIdle);
        var changedNames = new HashSet<string>(_hotCoreShaders.Keys, StringComparer.Ordinal);
        changedNames.UnionWith(_hotEffectShaders.Keys);
        if (changedNames.Count == 0)
        {
            error = null;
            return true;
        }

        return ApplyHotShaderState(
            new Dictionary<string, string>(StringComparer.Ordinal),
            new Dictionary<string, string>(StringComparer.Ordinal),
            changedNames,
            waitForGpuIdle,
            out error);
    }

    private bool ApplyHotShaderState(
        Dictionary<string, string> nextCore,
        Dictionary<string, string> nextEffect,
        HashSet<string> changedNames,
        Action waitForGpuIdle,
        out string? error)
    {
        var stagedShaders = new Dictionary<string, nint>(StringComparer.Ordinal);
        var stagedPipelines = new Dictionary<PipelineKey, (nint Pipeline, nint Vertex, nint Fragment)>();
        string activeEffectPart = CurrentEffectPart();

        nint ResolveOrStageShader(ShaderSpec spec, string? explicitSource = null)
        {
            string? source = explicitSource ?? ResolveShaderSource(spec.Name, nextCore, nextEffect);
            string key = source ?? spec.Name;
            if (stagedShaders.TryGetValue(key, out nint staged))
                return staged;
            if (_shaders.TryGetValue(key, out nint existing))
                return existing;
            nint created = CreateShaderHandle(spec, source);
            stagedShaders[key] = created;
            return created;
        }

        try
        {
            foreach (string name in changedNames)
            {
                if (FindShaderSpec(name) is not { } spec)
                    continue;
                if (nextCore.TryGetValue(name, out string? corePath))
                    _ = ResolveOrStageShader(spec, corePath);
                if (nextEffect.TryGetValue(name, out string? effectPath))
                    _ = ResolveOrStageShader(spec, effectPath);
            }

            foreach (PipelineKey key in _pipelines.Keys)
            {
                if (!string.Equals(key.EffectPart, activeEffectPart, StringComparison.Ordinal))
                    continue;
                var (vertexSpec, fragmentSpec, blended, multiplied, depthOnly) = ProgramLayout(key.Program);
                if (!changedNames.Contains(vertexSpec.Name) && !changedNames.Contains(fragmentSpec.Name))
                    continue;

                nint vertex = ResolveOrStageShader(vertexSpec);
                nint fragment = ResolveOrStageShader(fragmentSpec);
                nint pipeline = CreateGraphicsPipelineHandle(
                    key.Program,
                    key.Depth,
                    key.SampleCount,
                    vertex,
                    fragment,
                    blended,
                    multiplied,
                    depthOnly);
                stagedPipelines[key] = (pipeline, vertex, fragment);
            }
        }
        catch (Exception ex)
        {
            foreach (var entry in stagedPipelines.Values)
                SDL_ReleaseGPUGraphicsPipeline(Device, entry.Pipeline);
            foreach (nint shader in stagedShaders.Values)
                SDL_ReleaseGPUShader(Device, shader);
            error = ex.Message;
            return false;
        }

        waitForGpuIdle();

        var oldPipelines = new List<nint>();
        var staleKeys = new List<PipelineKey>();
        foreach (var (key, existingPipeline) in _pipelines)
        {
            if (!string.Equals(key.EffectPart, activeEffectPart, StringComparison.Ordinal))
            {
                staleKeys.Add(key);
                oldPipelines.Add(existingPipeline);
            }
        }
        foreach (PipelineKey stale in staleKeys)
        {
            _pipelines.Remove(stale);
            _pipelineShaderHandles.Remove(stale);
        }

        foreach (var (key, staged) in stagedPipelines)
        {
            if (_pipelines.TryGetValue(key, out nint previous))
                oldPipelines.Add(previous);
            _pipelines[key] = staged.Pipeline;
            _pipelineShaderHandles[key] = (staged.Vertex, staged.Fragment);
        }

        _hotCoreShaders.Clear();
        foreach (var (k, v) in nextCore)
            _hotCoreShaders[k] = v;
        _hotEffectShaders.Clear();
        foreach (var (k, v) in nextEffect)
            _hotEffectShaders[k] = v;

        foreach (var (k, h) in stagedShaders)
            _shaders[k] = h;

        var keepShaders = new HashSet<nint>();
        foreach (var (v, f) in _pipelineShaderHandles.Values)
        {
            keepShaders.Add(v);
            keepShaders.Add(f);
        }
        foreach (string path in _hotCoreShaders.Values)
        {
            if (_shaders.TryGetValue(path, out nint h))
                keepShaders.Add(h);
        }
        foreach (string path in _hotEffectShaders.Values)
        {
            if (_shaders.TryGetValue(path, out nint h))
                keepShaders.Add(h);
        }
        foreach (Program program in Enum.GetValues<Program>())
        {
            var (vertexSpec, fragmentSpec, _, _, _) = ProgramLayout(program);
            if (ResolveShaderSource(vertexSpec.Name) is { } vs && _shaders.TryGetValue(vs, out nint vh))
                keepShaders.Add(vh);
            if (ResolveShaderSource(fragmentSpec.Name) is { } fs && _shaders.TryGetValue(fs, out nint fh))
                keepShaders.Add(fh);
        }

        var oldShaders = new List<nint>();
        var removedShaderKeys = new List<string>();
        foreach (var (k, h) in _shaders)
        {
            if (!keepShaders.Contains(h))
            {
                removedShaderKeys.Add(k);
                oldShaders.Add(h);
            }
        }
        foreach (string k in removedShaderKeys)
            _shaders.Remove(k);

        foreach (nint pipeline in oldPipelines)
            SDL_ReleaseGPUGraphicsPipeline(Device, pipeline);
        foreach (nint shader in oldShaders)
            SDL_ReleaseGPUShader(Device, shader);

        error = null;
        return true;
    }

    public static uint CalcMipLevels(int width, int height) =>
        (uint)(1 + BitOperations.Log2((uint)Math.Max(1, Math.Max(width, height))));

    public GPUTexture MakeTexture(
        int width,
        int height,
        uint format,
        uint usage,
        uint numLevels = 1,
        int sampleCount = SDL_GPU_SAMPLECOUNT_1)
    {
        uint clampedLevels = Math.Max(1u, numLevels);
        var info = new SDL_GPUTextureCreateInfo
        {
            type = SDL_GPU_TEXTURETYPE_2D,
            format = format,
            usage = usage,
            width = (uint)Math.Max(1, width),
            height = (uint)Math.Max(1, height),
            layer_count_or_depth = 1,
            num_levels = clampedLevels,
            sample_count = sampleCount,
        };
        nint texture = SDL_CreateGPUTexture(Device, in info);
        if (texture == nint.Zero)
            throw new SDLError("SDL_CreateGPUTexture");
        return new GPUTexture(texture, width, height, format, _owner, numLevels: clampedLevels, sampleCount: sampleCount);
    }

    public GPUTexture UploadDataTexture(int width, int height, ReadOnlySpan<byte> pixels)
    {
        GPUTexture texture = MakeTexture(width, height, SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM, SDL_GPU_TEXTUREUSAGE_SAMPLER);
        try
        {
            byte[] copyBytes = pixels.ToArray();
            ReadOnlyMemory<byte>[] chunks = [copyBytes];
            Upload(chunks, (copy, transfer, offsets) =>
            {
                var source = new SDL_GPUTextureTransferInfo
                {
                    transfer_buffer = transfer,
                    offset = offsets[0],
                    pixels_per_row = (uint)width,
                    rows_per_layer = (uint)height,
                };
                var region = new SDL_GPUTextureRegion
                {
                    texture = texture.Handle,
                    w = (uint)width,
                    h = (uint)height,
                    d = 1,
                };
                SDL_UploadToGPUTexture(copy, in source, in region, false);
            });
            return texture;
        }
        catch
        {
            texture.Dispose();
            throw;
        }
    }

    public List<GPUTexture> UploadTextures(IReadOnlyList<(int Width, int Height, bool Depth8, byte[] Pixels)> images) =>
        UploadTextures(images, ReadOnlySpan<bool>.Empty);

    public List<GPUTexture> UploadTextures(
        IReadOnlyList<(int Width, int Height, bool Depth8, byte[] Pixels)> images,
        ReadOnlySpan<bool> mipmapped)
    {
        var result = new List<GPUTexture>(images.Count);
        if (images.Count == 0)
            return result;

        try
        {
            var numLevelsPerImage = new uint[images.Count];
            int mipmappedCount = 0;
            long totalMipPixels = 0;
            for (int i = 0; i < images.Count; i++)
            {
                var image = images[i];
                bool wantMips = !image.Depth8
                    && i < mipmapped.Length
                    && mipmapped[i]
                    && (image.Width > 1 || image.Height > 1);
                uint numLevels = wantMips ? CalcMipLevels(image.Width, image.Height) : 1u;
                numLevelsPerImage[i] = numLevels;
                if (numLevels > 1)
                {
                    mipmappedCount++;
                    totalMipPixels += (long)image.Width * image.Height;
                }

                result.Add(MakeTexture(
                    image.Width,
                    image.Height,
                    image.Depth8 ? SDL_GPU_TEXTUREFORMAT_R8_UNORM : ColorFormat,
                    SDL_GPU_TEXTUREUSAGE_SAMPLER,
                    numLevels: numLevels));
            }

            var mipChains = mipmappedCount > 0 ? new byte[]?[images.Count][] : null;
            if (mipChains is not null)
            {
                if (mipmappedCount > 1 && totalMipPixels >= 32768)
                {
                    Parallel.For(0, images.Count, i =>
                    {
                        uint numLevels = numLevelsPerImage[i];
                        if (numLevels <= 1) return;
                        var image = images[i];
                        var chain = new byte[numLevels - 1][];
                        int lw = image.Width;
                        int lh = image.Height;
                        byte[] cur = image.Pixels;
                        for (uint level = 1; level < numLevels; level++)
                        {
                            cur = SimsSDL.Core.SpritePixels.DownsamplePremultipliedSrgbBox(cur, lw, lh);
                            lw = Math.Max(1, lw >> 1);
                            lh = Math.Max(1, lh >> 1);
                            chain[level - 1] = cur;
                        }
                        mipChains[i] = chain;
                    });
                }
                else
                {
                    for (int i = 0; i < images.Count; i++)
                    {
                        uint numLevels = numLevelsPerImage[i];
                        if (numLevels <= 1) continue;
                        var image = images[i];
                        var chain = new byte[numLevels - 1][];
                        int lw = image.Width;
                        int lh = image.Height;
                        byte[] cur = image.Pixels;
                        for (uint level = 1; level < numLevels; level++)
                        {
                            cur = SimsSDL.Core.SpritePixels.DownsamplePremultipliedSrgbBox(cur, lw, lh);
                            lw = Math.Max(1, lw >> 1);
                            lh = Math.Max(1, lh >> 1);
                            chain[level - 1] = cur;
                        }
                        mipChains[i] = chain;
                    }
                }
            }

            var chunks = new List<ReadOnlyMemory<byte>>(images.Count * 2);
            var uploads = new List<(int TexIndex, uint MipLevel, int Width, int Height, int ChunkIndex)>(images.Count * 2);

            for (int i = 0; i < images.Count; i++)
            {
                var image = images[i];
                uint numLevels = numLevelsPerImage[i];
                int levelWidth = image.Width;
                int levelHeight = image.Height;
                int baseChunkIndex = chunks.Count;
                chunks.Add(image.Pixels);
                uploads.Add((i, 0u, levelWidth, levelHeight, baseChunkIndex));

                if (numLevels > 1 && mipChains?[i] is { } chain)
                {
                    for (uint level = 1; level < numLevels; level++)
                    {
                        levelWidth = Math.Max(1, levelWidth >> 1);
                        levelHeight = Math.Max(1, levelHeight >> 1);
                        int chunkIndex = chunks.Count;
                        chunks.Add(chain[level - 1]!);
                        uploads.Add((i, level, levelWidth, levelHeight, chunkIndex));
                    }
                }
            }

            Upload(CollectionsMarshal.AsSpan(chunks), (copy, transfer, offsets) =>
            {
                foreach (var item in uploads)
                {
                    var source = new SDL_GPUTextureTransferInfo
                    {
                        transfer_buffer = transfer,
                        offset = offsets[item.ChunkIndex],
                        pixels_per_row = (uint)item.Width,
                        rows_per_layer = (uint)item.Height,
                    };
                    var region = new SDL_GPUTextureRegion
                    {
                        texture = result[item.TexIndex].Handle,
                        mip_level = item.MipLevel,
                        w = (uint)item.Width,
                        h = (uint)item.Height,
                        d = 1,
                    };
                    SDL_UploadToGPUTexture(copy, in source, in region, false);
                }
            });
            return result;
        }
        catch
        {
            foreach (GPUTexture texture in result)
                texture.Dispose();
            throw;
        }
    }

    public GPUBuffer? MakeStorageBuffer<TElement>(List<TElement> elements)
        where TElement : unmanaged
    {
        ArgumentNullException.ThrowIfNull(elements);
        return MakeStorageBuffer<TElement>(CollectionsMarshal.AsSpan(elements));
    }

    public GPUBuffer? MakeStorageBuffer<TElement>(TElement[] elements)
        where TElement : unmanaged
    {
        ArgumentNullException.ThrowIfNull(elements);
        return MakeStorageBuffer<TElement>(elements.AsSpan());
    }

    public GPUBuffer? MakeStorageBuffer<TElement>(IReadOnlyList<TElement> elements)
        where TElement : unmanaged
    {
        ArgumentNullException.ThrowIfNull(elements);
        if (elements.Count == 0)
            return null;
        if (elements is List<TElement> list)
            return MakeStorageBuffer<TElement>(CollectionsMarshal.AsSpan(list));
        if (elements is TElement[] array)
            return MakeStorageBuffer<TElement>(array.AsSpan());
        var copy = new TElement[elements.Count];
        for (int i = 0; i < copy.Length; i++)
            copy[i] = elements[i];
        return MakeStorageBuffer<TElement>(copy.AsSpan());
    }

    public unsafe GPUBuffer? MakeStorageBuffer<TElement>(ReadOnlySpan<TElement> elements)
        where TElement : unmanaged
    {
        if (elements.IsEmpty)
            return null;

        ReadOnlySpan<byte> rawBytes = MemoryMarshal.AsBytes(elements);
        byte[] data = rawBytes.ToArray();
        var info = new SDL_GPUBufferCreateInfo
        {
            usage = SDL_GPU_BUFFERUSAGE_GRAPHICS_STORAGE_READ,
            size = (uint)data.Length,
        };
        nint buffer = SDL_CreateGPUBuffer(Device, in info);
        if (buffer == nint.Zero)
            throw new SDLError("SDL_CreateGPUBuffer");

        var result = new GPUBuffer(buffer, elements.Length, _owner, data.Length);
        try
        {
            UploadBufferBytes(result, rawBytes, cycle: false);
            return result;
        }
        catch
        {
            result.Dispose();
            throw;
        }
    }

    public unsafe GPUBuffer MakeStorageBufferCapacity<TElement>(int capacity)
        where TElement : unmanaged
    {
        ArgumentOutOfRangeException.ThrowIfNegativeOrZero(capacity);
        long totalBytes = checked((long)capacity * sizeof(TElement));
        var info = new SDL_GPUBufferCreateInfo
        {
            usage = SDL_GPU_BUFFERUSAGE_GRAPHICS_STORAGE_READ,
            size = checked((uint)totalBytes),
        };
        nint buffer = SDL_CreateGPUBuffer(Device, in info);
        if (buffer == nint.Zero)
            throw new SDLError("SDL_CreateGPUBuffer");
        return new GPUBuffer(buffer, capacity, _owner, totalBytes);
    }

    public unsafe void UploadIntoBuffer<TElement>(GPUBuffer target, ReadOnlySpan<TElement> elements)
        where TElement : unmanaged
    {
        ArgumentNullException.ThrowIfNull(target);
        if (elements.IsEmpty)
            return;

        ReadOnlySpan<byte> rawBytes = MemoryMarshal.AsBytes(elements);
        if (rawBytes.Length > target.ByteSize)
            throw new ArgumentOutOfRangeException(nameof(elements), $"Upload of {rawBytes.Length} bytes exceeds buffer size {target.ByteSize}.");

        UploadBufferBytes(target, rawBytes, cycle: false);
    }

    private unsafe void UploadBufferBytes(GPUBuffer target, ReadOnlySpan<byte> rawBytes, bool cycle)
    {
        if (rawBytes.IsEmpty)
            return;

        int allocSize = Math.Max(4, (rawBytes.Length + 3) & ~3);
        var transferInfo = new SDL_GPUTransferBufferCreateInfo
        {
            usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD,
            size = (uint)allocSize,
        };
        nint transfer = SDL_CreateGPUTransferBuffer(Device, in transferInfo);
        if (transfer == nint.Zero)
            throw new SDLError("SDL_CreateGPUTransferBuffer");

        try
        {
            nint mapped = SDL_MapGPUTransferBuffer(Device, transfer, false);
            if (mapped == nint.Zero)
                throw new SDLError("SDL_MapGPUTransferBuffer");
            try
            {
                fixed (byte* srcPtr = rawBytes)
                {
                    Buffer.MemoryCopy(srcPtr, (void*)mapped, allocSize, rawBytes.Length);
                }
            }
            finally
            {
                SDL_UnmapGPUTransferBuffer(Device, transfer);
            }

            nint targetHandle = target.Handle;
            uint byteLength = (uint)rawBytes.Length;
            void Record(nint copy)
            {
                var source = new SDL_GPUTransferBufferLocation
                {
                    transfer_buffer = transfer,
                    offset = 0,
                };
                var region = new SDL_GPUBufferRegion
                {
                    buffer = targetHandle,
                    offset = 0,
                    size = byteLength,
                };
                SDL_UploadToGPUBuffer(copy, in source, in region, cycle);
            }

            if (EnsureBatchCopyPass() is var batchCopy && batchCopy != nint.Zero)
            {
                Record(batchCopy);
                return;
            }

            nint command = SDL_AcquireGPUCommandBuffer(Device);
            if (command == nint.Zero)
                throw new SDLError("SDL_AcquireGPUCommandBuffer");
            nint copy = SDL_BeginGPUCopyPass(command);
            if (copy == nint.Zero)
            {
                _ = SDL_SubmitGPUCommandBuffer(command);
                throw new SDLError("SDL_BeginGPUCopyPass");
            }
            Record(copy);
            SDL_EndGPUCopyPass(copy);
            if (!SDL_SubmitGPUCommandBuffer(command))
                throw new SDLError("SDL_SubmitGPUCommandBuffer");
        }
        finally
        {
            SDL_ReleaseGPUTransferBuffer(Device, transfer);
        }
    }

    private nint EnsureBatchCopyPass()
    {
        if (_batchCopy != nint.Zero)
            return _batchCopy;
        if (_batchCommand == nint.Zero)
            return nint.Zero;
        nint copy = SDL_BeginGPUCopyPass(_batchCommand);
        if (copy == nint.Zero)
            throw new SDLError("SDL_BeginGPUCopyPass");
        _batchCopy = copy;
        return copy;
    }

    private unsafe void Upload(ReadOnlySpan<ReadOnlyMemory<byte>> chunks, Action<nint, nint, uint[]> encode)
    {
        uint[] offsets = new uint[chunks.Length];
        int total = 0;
        for (int i = 0; i < chunks.Length; i++)
        {
            offsets[i] = (uint)total;
            total = checked(total + ((chunks[i].Length + 3) & ~3));
        }

        int allocSize = Math.Max(4, total);
        var info = new SDL_GPUTransferBufferCreateInfo
        {
            usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD,
            size = (uint)allocSize,
        };
        nint transfer = SDL_CreateGPUTransferBuffer(Device, in info);
        if (transfer == nint.Zero)
            throw new SDLError("SDL_CreateGPUTransferBuffer");

        try
        {
            nint mapped = SDL_MapGPUTransferBuffer(Device, transfer, false);
            if (mapped == nint.Zero)
                throw new SDLError("SDL_MapGPUTransferBuffer");
            try
            {
                byte* dstBase = (byte*)mapped;
                for (int i = 0; i < chunks.Length; i++)
                {
                    ReadOnlySpan<byte> span = chunks[i].Span;
                    if (span.IsEmpty)
                        continue;
                    fixed (byte* srcPtr = span)
                    {
                        Buffer.MemoryCopy(srcPtr, dstBase + offsets[i], allocSize - offsets[i], span.Length);
                    }
                }
            }
            finally
            {
                SDL_UnmapGPUTransferBuffer(Device, transfer);
            }

            if (EnsureBatchCopyPass() is var batchCopy && batchCopy != nint.Zero)
            {
                encode(batchCopy, transfer, offsets);
                return;
            }

            nint command = SDL_AcquireGPUCommandBuffer(Device);
            if (command == nint.Zero)
                throw new SDLError("SDL_AcquireGPUCommandBuffer");
            nint copy = SDL_BeginGPUCopyPass(command);
            if (copy == nint.Zero)
            {
                _ = SDL_SubmitGPUCommandBuffer(command);
                throw new SDLError("SDL_BeginGPUCopyPass");
            }
            encode(copy, transfer, offsets);
            SDL_EndGPUCopyPass(copy);
            if (!SDL_SubmitGPUCommandBuffer(command))
                throw new SDLError("SDL_SubmitGPUCommandBuffer");
        }
        finally
        {
            SDL_ReleaseGPUTransferBuffer(Device, transfer);
        }
    }

    public void BatchingUploads(Action body) => BatchingUploads(nint.Zero, body);

    public void BatchingUploads(nint command, Action body)
    {
        ArgumentNullException.ThrowIfNull(body);
        BatchingUploads<byte>(command, () =>
        {
            body();
            return 0;
        });
    }

    public TResult BatchingUploads<TResult>(Func<TResult> body) => BatchingUploads(nint.Zero, body);

    public TResult BatchingUploads<TResult>(nint command, Func<TResult> body)
    {
        ArgumentNullException.ThrowIfNull(body);
        if (_batchCommand != nint.Zero)
            return body();

        bool owned = command == nint.Zero;
        if (owned)
        {
            command = SDL_AcquireGPUCommandBuffer(Device);
            if (command == nint.Zero)
                throw new SDLError("SDL_AcquireGPUCommandBuffer");
        }

        _batchCommand = command;
        try
        {
            return body();
        }
        finally
        {
            _batchCommand = nint.Zero;
            nint copy = _batchCopy;
            _batchCopy = nint.Zero;
            if (copy != nint.Zero)
                SDL_EndGPUCopyPass(copy);
            if (owned)
                _ = SDL_SubmitGPUCommandBuffer(command);
        }
    }

    public unsafe byte[] ReadPixels(GPUTexture texture)
    {
        ArgumentNullException.ThrowIfNull(texture);
        int size = checked(texture.Width * texture.Height * 4);
        if (size <= 0)
            return [];

        var info = new SDL_GPUTransferBufferCreateInfo
        {
            usage = SDL_GPU_TRANSFERBUFFERUSAGE_DOWNLOAD,
            size = (uint)size,
        };
        nint transfer = SDL_CreateGPUTransferBuffer(Device, in info);
        if (transfer == nint.Zero)
            throw new SDLError("SDL_CreateGPUTransferBuffer");

        try
        {
            nint command = SDL_AcquireGPUCommandBuffer(Device);
            if (command == nint.Zero)
                throw new SDLError("readback");
            nint copy = SDL_BeginGPUCopyPass(command);
            if (copy == nint.Zero)
            {
                _ = SDL_SubmitGPUCommandBuffer(command);
                throw new SDLError("readback");
            }

            var region = new SDL_GPUTextureRegion
            {
                texture = texture.Handle,
                w = (uint)texture.Width,
                h = (uint)texture.Height,
                d = 1,
            };
            var destination = new SDL_GPUTextureTransferInfo
            {
                transfer_buffer = transfer,
                offset = 0,
                pixels_per_row = (uint)texture.Width,
                rows_per_layer = (uint)texture.Height,
            };
            SDL_DownloadFromGPUTexture(copy, in region, in destination);
            SDL_EndGPUCopyPass(copy);

            nint fence = SDL_SubmitGPUCommandBufferAndAcquireFence(command);
            if (fence == nint.Zero)
                throw new SDLError("SDL_SubmitGPUCommandBufferAndAcquireFence");
            nint fenceSlot = fence;
            _ = SDL_WaitForGPUFences(Device, true, &fenceSlot, 1);
            SDL_ReleaseGPUFence(Device, fence);

            nint mapped = SDL_MapGPUTransferBuffer(Device, transfer, false);
            if (mapped == nint.Zero)
                throw new SDLError("SDL_MapGPUTransferBuffer");
            try
            {
                byte[] result = new byte[size];
                Marshal.Copy(mapped, result, 0, size);
                return result;
            }
            finally
            {
                SDL_UnmapGPUTransferBuffer(Device, transfer);
            }
        }
        finally
        {
            SDL_ReleaseGPUTransferBuffer(Device, transfer);
        }
    }

    private void ReleaseNative()
    {
        if (Interlocked.Exchange(ref _disposed, 1) != 0)
            return;

        nint dev = _owner.Handle;
        if (dev != nint.Zero)
        {
            foreach (nint pipeline in _pipelines.Values)
                SDL_ReleaseGPUGraphicsPipeline(dev, pipeline);
            foreach (nint shader in _shaders.Values)
                SDL_ReleaseGPUShader(dev, shader);
            if (Sampler != nint.Zero)
                SDL_ReleaseGPUSampler(dev, Sampler);
            if (RoofSampler != nint.Zero)
                SDL_ReleaseGPUSampler(dev, RoofSampler);
            if (AnisoSampler != nint.Zero)
                SDL_ReleaseGPUSampler(dev, AnisoSampler);
            if (PixelSampler != nint.Zero)
                SDL_ReleaseGPUSampler(dev, PixelSampler);
        }

        _pipelines.Clear();
        _pipelineShaderHandles.Clear();
        _shaders.Clear();
        _hotCoreShaders.Clear();
        _hotEffectShaders.Clear();
        _sharedTextures.Clear();
        Sampler = nint.Zero;
        RoofSampler = nint.Zero;
        AnisoSampler = nint.Zero;
        PixelSampler = nint.Zero;

        _owner.ReleaseRef();
        _owner.Dispose();
    }

    public void Dispose()
    {
        ReleaseNative();
        GC.SuppressFinalize(this);
    }

    ~GPUContext() => ReleaseNative();
}
