using System.Buffers;
using System.Diagnostics;
using System.Threading.Channels;

namespace SimsSDL;

internal sealed class LiveVideoRecorder : IDisposable
{
    public readonly record struct CursorOverlay(
        OriginalCursors.CursorSprite Sprite,
        int PixelX,
        int PixelY,
        int Scale);

    private sealed record QueuedFrame(
        byte[] Buffer,
        int ByteLength,
        int RepeatCount,
        CursorOverlay? Cursor);

    private struct TransferSlot
    {
        public nint Buffer;
        public nint Fence;
        public int RepeatCount;
        public CursorOverlay? Cursor;
        public bool Busy;
    }

    private const int SlotCount = 4;

    private readonly GPUContext _gpu;
    private readonly string _outputPath;
    private readonly string _tempVideoPath;
    private readonly string _tempAudioPath;
    private readonly string _ffmpegPath;
    private readonly int _width;
    private readonly int _height;
    private readonly int _fps;
    private readonly int _frameBytes;
    private readonly bool _captureAudio;
    private readonly bool _exactFrameStep;
    private readonly TransferSlot[] _slots = new TransferSlot[SlotCount];
    private readonly Channel<QueuedFrame> _channel;
    private readonly Process _ffmpeg;
    private readonly Task<string> _stderrTask;
    private readonly Task _writerTask;
    private readonly FileStream? _audioFile;

    private GPUTexture? _scaledTarget;
    private float[] _audioScratch = [];
    private long _startStamp;
    private bool _started;
    private long _emittedVideoFrames;
    private long _emittedAudioFrames;
    private int _nextSlot;
    private int _disposed;

    public string OutputPath => _outputPath;

    public LiveVideoRecorder(
        GPUContext gpu,
        string outputPath,
        int width,
        int height,
        int fps,
        bool captureAudio,
        string ffmpegPath,
        bool exactFrameStep = false)
    {
        ArgumentNullException.ThrowIfNull(gpu);
        ArgumentException.ThrowIfNullOrEmpty(outputPath);

        _gpu = gpu;
        _outputPath = Path.GetFullPath(outputPath);
        _width = Math.Max(2, width & ~1);
        _height = Math.Max(2, height & ~1);
        _fps = Math.Clamp(fps, 1, 120);
        _frameBytes = checked(_width * _height * 4);
        _captureAudio = captureAudio;
        _exactFrameStep = exactFrameStep;
        _ffmpegPath = ffmpegPath;

        string? dir = Path.GetDirectoryName(_outputPath);
        if (!string.IsNullOrEmpty(dir))
        {
            Directory.CreateDirectory(dir);
        }

        string token = Guid.NewGuid().ToString("N")[..8];
        _tempVideoPath = $"{_outputPath}.{token}.video.mp4";
        _tempAudioPath = $"{_outputPath}.{token}.audio.f32";

        try
        {
            var transferInfo = new SDL_GPUTransferBufferCreateInfo
            {
                usage = SDL_GPU_TRANSFERBUFFERUSAGE_DOWNLOAD,
                size = (uint)_frameBytes,
            };
            for (int i = 0; i < SlotCount; i++)
            {
                nint handle = SDL_CreateGPUTransferBuffer(_gpu.Device, in transferInfo);
                if (handle == nint.Zero)
                {
                    throw new SDLError("SDL_CreateGPUTransferBuffer");
                }
                _slots[i].Buffer = handle;
            }

            if (_captureAudio)
            {
                _audioFile = new FileStream(_tempAudioPath, FileMode.Create, FileAccess.Write, FileShare.None, 65536);
            }

            var psi = new ProcessStartInfo
            {
                FileName = _ffmpegPath,
                UseShellExecute = false,
                RedirectStandardInput = true,
                RedirectStandardError = true,
            };
            psi.ArgumentList.Add("-y");
            psi.ArgumentList.Add("-f");
            psi.ArgumentList.Add("rawvideo");
            psi.ArgumentList.Add("-pix_fmt");
            psi.ArgumentList.Add("rgba");
            psi.ArgumentList.Add("-s");
            psi.ArgumentList.Add(FormattableString.Invariant($"{_width}x{_height}"));
            psi.ArgumentList.Add("-r");
            psi.ArgumentList.Add(_fps.ToString(CultureInfo.InvariantCulture));
            psi.ArgumentList.Add("-i");
            psi.ArgumentList.Add("-");
            psi.ArgumentList.Add("-c:v");
            psi.ArgumentList.Add("libx264");
            psi.ArgumentList.Add("-crf");
            psi.ArgumentList.Add("16");
            psi.ArgumentList.Add("-preset");
            psi.ArgumentList.Add("fast");
            psi.ArgumentList.Add("-pix_fmt");
            psi.ArgumentList.Add("yuv420p");
            psi.ArgumentList.Add(_tempVideoPath);

            _ffmpeg = Process.Start(psi) ?? throw new ContentError("Could not start ffmpeg.");
            _stderrTask = _ffmpeg.StandardError.ReadToEndAsync();

            _channel = Channel.CreateBounded<QueuedFrame>(new BoundedChannelOptions(12)
            {
                SingleReader = true,
                SingleWriter = true,
                FullMode = BoundedChannelFullMode.Wait,
            });
            _writerTask = Task.Run(WriterLoopAsync);
        }
        catch
        {
            CleanupHandlesOnly();
            throw;
        }
    }

    public unsafe int? EncodeBeforeSubmit(nint command, GPUTexture sourceColor, CursorOverlay? cursor)
    {
        if (Volatile.Read(ref _disposed) != 0)
            return null;

        int dueFrames;
        if (_exactFrameStep)
        {
            dueFrames = 1;
        }
        else if (!_started)
        {
            _started = true;
            _startStamp = Stopwatch.GetTimestamp();
            dueFrames = 1;
        }
        else
        {
            double elapsed = Stopwatch.GetElapsedTime(_startStamp).TotalSeconds;
            long targetFrames = 1 + (long)Math.Floor(elapsed * _fps);
            long delta = targetFrames - _emittedVideoFrames;
            if (delta <= 0)
                return null;
            dueFrames = (int)Math.Min(delta, 4);
        }

        int slot = AcquireSlot();
        GPUTexture downloadSource = sourceColor;
        CursorOverlay? adjustedCursor = cursor;
        if (sourceColor.Width != _width || sourceColor.Height != _height)
        {
            if (_scaledTarget is null || _scaledTarget.Width != _width || _scaledTarget.Height != _height)
            {
                _scaledTarget?.Dispose();
                _scaledTarget = _gpu.MakeTexture(
                    _width,
                    _height,
                    GPUContext.ColorFormat,
                    SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER);
            }

            var blit = new SDL_GPUBlitInfo
            {
                source = new SDL_GPUBlitRegion
                {
                    texture = sourceColor.Handle,
                    w = (uint)sourceColor.Width,
                    h = (uint)sourceColor.Height,
                },
                destination = new SDL_GPUBlitRegion
                {
                    texture = _scaledTarget.Handle,
                    w = (uint)_width,
                    h = (uint)_height,
                },
                load_op = SDL_GPU_LOADOP_DONT_CARE,
                filter = SDL_GPU_FILTER_LINEAR,
            };
            SDL_BlitGPUTexture(command, in blit);
            downloadSource = _scaledTarget;

            if (cursor is { } c && sourceColor.Width > 0 && sourceColor.Height > 0)
            {
                double sx = (double)_width / sourceColor.Width;
                double sy = (double)_height / sourceColor.Height;
                adjustedCursor = c with
                {
                    PixelX = (int)Math.Round(c.PixelX * sx),
                    PixelY = (int)Math.Round(c.PixelY * sy),
                    Scale = Math.Max(1, (int)Math.Round(c.Scale * Math.Min(sx, sy))),
                };
            }
        }

        nint copy = SDL_BeginGPUCopyPass(command);
        if (copy == nint.Zero)
        {
            throw new SDLError("SDL_BeginGPUCopyPass");
        }

        var region = new SDL_GPUTextureRegion
        {
            texture = downloadSource.Handle,
            w = (uint)_width,
            h = (uint)_height,
            d = 1,
        };
        var destination = new SDL_GPUTextureTransferInfo
        {
            transfer_buffer = _slots[slot].Buffer,
            offset = 0,
            pixels_per_row = (uint)_width,
            rows_per_layer = (uint)_height,
        };
        SDL_DownloadFromGPUTexture(copy, in region, in destination);
        SDL_EndGPUCopyPass(copy);

        _slots[slot].Busy = true;
        _slots[slot].Fence = nint.Zero;
        _slots[slot].RepeatCount = dueFrames;
        _slots[slot].Cursor = adjustedCursor;
        _emittedVideoFrames += dueFrames;

        if (_captureAudio && _audioFile is not null)
        {
            long targetAudio = (long)Math.Round(_emittedVideoFrames * ((double)SDLAudioPlayer.SampleRate / _fps));
            int audioFrames = (int)Math.Max(0, targetAudio - _emittedAudioFrames);
            if (audioFrames > 0)
            {
                int floats = audioFrames * 2;
                if (_audioScratch.Length < floats)
                    _audioScratch = new float[floats];
                Span<float> pcm = _audioScratch.AsSpan(0, floats);
                SDLAudioPlayer.CaptureMixedFrames(pcm, audioFrames);
                _audioFile.Write(MemoryMarshal.AsBytes(pcm));
                _emittedAudioFrames += audioFrames;
            }
        }

        return slot;
    }

    public void AttachFence(int slot, nint fence)
    {
        if ((uint)slot < SlotCount && _slots[slot].Busy)
        {
            _slots[slot].Fence = fence;
        }
    }

    public void OnFenceSignaled(nint fence)
    {
        if (fence == nint.Zero || Volatile.Read(ref _disposed) != 0)
            return;

        for (int i = 0; i < SlotCount; i++)
        {
            if (_slots[i].Busy && _slots[i].Fence == fence)
            {
                HarvestSlot(i);
            }
        }
    }

    private unsafe int AcquireSlot()
    {
        for (int attempt = 0; attempt < SlotCount; attempt++)
        {
            int candidate = (_nextSlot + attempt) % SlotCount;
            if (!_slots[candidate].Busy)
            {
                _nextSlot = (candidate + 1) % SlotCount;
                return candidate;
            }
        }

        int oldest = _nextSlot;
        if (_slots[oldest].Fence is nint fence and not 0)
        {
            nint f = fence;
            _ = SDL_WaitForGPUFences(_gpu.Device, true, &f, 1);
        }
        HarvestSlot(oldest);
        _nextSlot = (oldest + 1) % SlotCount;
        return oldest;
    }

    private void HarvestSlot(int index)
    {
        ref TransferSlot slot = ref _slots[index];
        if (!slot.Busy)
            return;

        nint mapped = SDL_MapGPUTransferBuffer(_gpu.Device, slot.Buffer, false);
        if (mapped == nint.Zero)
        {
            slot.Busy = false;
            slot.Fence = nint.Zero;
            throw new SDLError("SDL_MapGPUTransferBuffer");
        }

        byte[] rented = ArrayPool<byte>.Shared.Rent(_frameBytes);
        try
        {
            Marshal.Copy(mapped, rented, 0, _frameBytes);
        }
        finally
        {
            SDL_UnmapGPUTransferBuffer(_gpu.Device, slot.Buffer);
        }

        int repeat = slot.RepeatCount;
        CursorOverlay? cursor = slot.Cursor;
        slot.Busy = false;
        slot.Fence = nint.Zero;
        slot.Cursor = null;

        if (!_channel.Writer.TryWrite(new QueuedFrame(rented, _frameBytes, repeat, cursor)))
        {
            _channel.Writer.WriteAsync(new QueuedFrame(rented, _frameBytes, repeat, cursor)).AsTask().GetAwaiter().GetResult();
        }
    }

    private async Task WriterLoopAsync()
    {
        Stream stdin = _ffmpeg.StandardInput.BaseStream;
        await foreach (QueuedFrame item in _channel.Reader.ReadAllAsync().ConfigureAwait(false))
        {
            try
            {
                if (item.Cursor is { } cursor)
                {
                    CompositeCursor(item.Buffer, _width, _height, cursor);
                }

                for (int r = 0; r < item.RepeatCount; r++)
                {
                    await stdin.WriteAsync(item.Buffer.AsMemory(0, item.ByteLength)).ConfigureAwait(false);
                }
            }
            finally
            {
                ArrayPool<byte>.Shared.Return(item.Buffer);
            }
        }
    }

    private static void CompositeCursor(byte[] frameRgba, int frameW, int frameH, CursorOverlay overlay)
    {
        var sprite = overlay.Sprite;
        int scale = Math.Max(1, overlay.Scale);
        int originX = overlay.PixelX - sprite.HotX * scale;
        int originY = overlay.PixelY - sprite.HotY * scale;
        int drawW = sprite.Width * scale;
        int drawH = sprite.Height * scale;
        byte[] src = sprite.Rgba;

        int startY = Math.Max(0, -originY);
        int endY = Math.Min(drawH, frameH - originY);
        int startX = Math.Max(0, -originX);
        int endX = Math.Min(drawW, frameW - originX);

        for (int dy = startY; dy < endY; dy++)
        {
            int sy = dy / scale;
            int dstRow = (originY + dy) * frameW;
            int srcRow = sy * sprite.Width;
            for (int dx = startX; dx < endX; dx++)
            {
                int sx = dx / scale;
                int sIdx = (srcRow + sx) * 4;
                int sa = src[sIdx + 3];
                if (sa == 0)
                    continue;

                int dIdx = (dstRow + originX + dx) * 4;
                if (sa == 255)
                {
                    frameRgba[dIdx] = src[sIdx];
                    frameRgba[dIdx + 1] = src[sIdx + 1];
                    frameRgba[dIdx + 2] = src[sIdx + 2];
                    frameRgba[dIdx + 3] = 255;
                }
                else
                {
                    int inv = 255 - sa;
                    frameRgba[dIdx] = (byte)((src[sIdx] * sa + frameRgba[dIdx] * inv + 127) / 255);
                    frameRgba[dIdx + 1] = (byte)((src[sIdx + 1] * sa + frameRgba[dIdx + 1] * inv + 127) / 255);
                    frameRgba[dIdx + 2] = (byte)((src[sIdx + 2] * sa + frameRgba[dIdx + 2] * inv + 127) / 255);
                    frameRgba[dIdx + 3] = 255;
                }
            }
        }
    }

    private void CleanupHandlesOnly()
    {
        _scaledTarget?.Dispose();
        _scaledTarget = null;
        for (int i = 0; i < SlotCount; i++)
        {
            if (_slots[i].Buffer != nint.Zero)
            {
                SDL_ReleaseGPUTransferBuffer(_gpu.Device, _slots[i].Buffer);
                _slots[i].Buffer = nint.Zero;
            }
        }
        try { _audioFile?.Dispose(); } catch { }
        try { if (_ffmpeg is { HasExited: false }) _ffmpeg.Kill(entireProcessTree: true); } catch { }
        try { _ffmpeg?.Dispose(); } catch { }
        TryDelete(_tempVideoPath);
        TryDelete(_tempAudioPath);
    }

    private static void TryDelete(string path)
    {
        try
        {
            if (File.Exists(path))
                File.Delete(path);
        }
        catch
        {
        }
    }

    public unsafe void Dispose()
    {
        if (Interlocked.Exchange(ref _disposed, 1) != 0)
            return;

        Exception? finishError = null;
        try
        {
            for (int i = 0; i < SlotCount; i++)
            {
                if (_slots[i].Busy)
                {
                    if (_slots[i].Fence is nint fence and not 0)
                    {
                        nint f = fence;
                        _ = SDL_WaitForGPUFences(_gpu.Device, true, &f, 1);
                    }
                    HarvestSlot(i);
                }
            }

            _channel.Writer.TryComplete();
            _writerTask.GetAwaiter().GetResult();

            _ffmpeg.StandardInput.BaseStream.Flush();
            _ffmpeg.StandardInput.Close();
            _ffmpeg.WaitForExit();
            string stderr = _stderrTask.GetAwaiter().GetResult();
            if (_ffmpeg.ExitCode != 0)
            {
                throw new ContentError($"ffmpeg video encode failed ({_ffmpeg.ExitCode}): {stderr}");
            }

            if (_audioFile is not null)
            {
                _audioFile.Flush();
                _audioFile.Dispose();
            }

            if (_emittedVideoFrames > 0)
            {
                if (_captureAudio && _emittedAudioFrames > 0 && File.Exists(_tempAudioPath))
                {
                    var muxPsi = new ProcessStartInfo
                    {
                        FileName = _ffmpegPath,
                        UseShellExecute = false,
                        RedirectStandardError = true,
                    };
                    muxPsi.ArgumentList.Add("-y");
                    muxPsi.ArgumentList.Add("-i");
                    muxPsi.ArgumentList.Add(_tempVideoPath);
                    muxPsi.ArgumentList.Add("-f");
                    muxPsi.ArgumentList.Add("f32le");
                    muxPsi.ArgumentList.Add("-ar");
                    muxPsi.ArgumentList.Add(SDLAudioPlayer.SampleRate.ToString(CultureInfo.InvariantCulture));
                    muxPsi.ArgumentList.Add("-ac");
                    muxPsi.ArgumentList.Add("2");
                    muxPsi.ArgumentList.Add("-i");
                    muxPsi.ArgumentList.Add(_tempAudioPath);
                    muxPsi.ArgumentList.Add("-c:v");
                    muxPsi.ArgumentList.Add("copy");
                    muxPsi.ArgumentList.Add("-c:a");
                    muxPsi.ArgumentList.Add("aac");
                    muxPsi.ArgumentList.Add("-b:a");
                    muxPsi.ArgumentList.Add("320k");
                    muxPsi.ArgumentList.Add("-shortest");
                    muxPsi.ArgumentList.Add("-movflags");
                    muxPsi.ArgumentList.Add("+faststart");
                    muxPsi.ArgumentList.Add(_outputPath);

                    using Process mux = Process.Start(muxPsi) ?? throw new ContentError("Could not start ffmpeg muxer.");
                    string muxErr = mux.StandardError.ReadToEnd();
                    mux.WaitForExit();
                    if (mux.ExitCode != 0)
                    {
                        throw new ContentError($"ffmpeg audio mux failed ({mux.ExitCode}): {muxErr}");
                    }
                }
                else
                {
                    File.Move(_tempVideoPath, _outputPath, overwrite: true);
                }

                Console.Error.WriteLine(FormattableString.Invariant(
                    $"SimsSDL: recorded {_outputPath} ({_emittedVideoFrames} frames, {_emittedVideoFrames / (double)_fps:0.00}s)"));
            }
        }
        catch (Exception ex)
        {
            finishError = ex;
        }
        finally
        {
            CleanupHandlesOnly();
        }

        if (finishError is not null)
            throw finishError;
    }
}
