using SimsSDL;
using SimsSDL.Interop;

namespace SimsEngine.Tests.Client;

public sealed class InputAndFullscreenTests
{
    private const ushort KmodLctrl = 0x40;
    private const ushort KmodCaps = 0x2000;

    [Theory]
    [InlineData(Sdl3Native.SDLK_RETURN, Sdl3Native.SDL_KMOD_LALT)]
    [InlineData(Sdl3Native.SDLK_KP_ENTER, Sdl3Native.SDL_KMOD_LALT)]
    [InlineData(Sdl3Native.SDLK_RETURN, Sdl3Native.SDL_KMOD_RALT)]
    [InlineData(Sdl3Native.SDLK_KP_ENTER, Sdl3Native.SDL_KMOD_RALT)]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_RALT | KmodLctrl))]
    [InlineData(Sdl3Native.SDLK_KP_ENTER, (ushort)(Sdl3Native.SDL_KMOD_RALT | KmodLctrl))]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_LALT | Sdl3Native.SDL_KMOD_NUM))]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_LALT | KmodCaps))]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_RALT | Sdl3Native.SDL_KMOD_NUM | KmodCaps))]
    public void IsToggleFullscreenShortcut_MatchesAltAndAltGrEnterVariants(uint key, ushort mods)
    {
        Assert.True(SimsSDL.Program.IsToggleFullscreenShortcut(key, mods));
    }

    [Theory]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)0)]
    [InlineData(Sdl3Native.SDLK_KP_ENTER, (ushort)0)]
    [InlineData(Sdl3Native.SDLK_RETURN, Sdl3Native.SDL_KMOD_CTRL)]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_LALT | Sdl3Native.SDL_KMOD_SHIFT))]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_RALT | Sdl3Native.SDL_KMOD_SHIFT))]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_LALT | Sdl3Native.SDL_KMOD_GUI))]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_RALT | Sdl3Native.SDL_KMOD_GUI))]
    [InlineData(Sdl3Native.SDLK_RETURN, (ushort)(Sdl3Native.SDL_KMOD_LALT | Sdl3Native.SDL_KMOD_CTRL))]
    [InlineData(Sdl3Native.SDLK_SPACE, Sdl3Native.SDL_KMOD_LALT)]
    [InlineData((uint)'f', Sdl3Native.SDL_KMOD_LALT)]
    public void IsToggleFullscreenShortcut_RejectsNonMatchingModifiersAndKeys(uint key, ushort mods)
    {
        Assert.False(SimsSDL.Program.IsToggleFullscreenShortcut(key, mods));
    }

    [Fact]
    public void MapLiveKey_MapsDeleteBackspaceAndUnnumlockedNumpadPeriod()
    {
        Assert.IsType<LiveController.Key.Delete>(SimsSDL.Program.MapLiveKey(Sdl3Native.SDLK_DELETE));
        Assert.IsType<LiveController.Key.Backspace>(SimsSDL.Program.MapLiveKey(Sdl3Native.SDLK_BACKSPACE));
        Assert.IsType<LiveController.Key.Delete>(SimsSDL.Program.MapLiveKey(Sdl3Native.SDLK_KP_PERIOD, 0));
        Assert.Null(SimsSDL.Program.MapLiveKey(Sdl3Native.SDLK_KP_PERIOD, Sdl3Native.SDL_KMOD_NUM));
    }

    [Fact]
    public void Sdl3Native_FullscreenAndKeypadConstantsMatchCApi()
    {
        Assert.Equal(1UL, Sdl3Native.SDL_WINDOW_FULLSCREEN);
        Assert.Equal((ushort)0x100, Sdl3Native.SDL_KMOD_LALT);
        Assert.Equal((ushort)0x200, Sdl3Native.SDL_KMOD_RALT);
        Assert.Equal((ushort)0x1000, Sdl3Native.SDL_KMOD_NUM);
        Assert.Equal(0x40000063u, Sdl3Native.SDLK_KP_PERIOD);
    }

    [Fact]
    public void PrepareWindowIconPixels_PadsFullBleedIconToMacOsDockGridAndIsIdempotent()
    {
        byte[] fullBleed = new byte[128 * 128 * 4];
        for (int i = 0; i < 128 * 128; i++)
        {
            fullBleed[(i * 4) + 0] = 12;
            fullBleed[(i * 4) + 1] = 68;
            fullBleed[(i * 4) + 2] = 156;
            fullBleed[(i * 4) + 3] = 255;
        }

        (byte[] nonMacPixels, int nonMacW, int nonMacH) = SimsSDL.Program.PrepareWindowIconPixels(fullBleed, 128, 128, isMacOs: false);
        Assert.Same(fullBleed, nonMacPixels);
        Assert.Equal(128, nonMacW);
        Assert.Equal(128, nonMacH);

        (byte[] macPixels, int macW, int macH) = SimsSDL.Program.PrepareWindowIconPixels(fullBleed, 128, 128, isMacOs: true);
        Assert.Equal(160, macW);
        Assert.Equal(160, macH);
        Assert.Equal(0, macPixels[3]);
        Assert.Equal(0, macPixels[((0 * macW) + 80) * 4 + 3]);

        int centerIdx = (((macH / 2) * macW) + (macW / 2)) * 4;
        Assert.Equal((byte)12, macPixels[centerIdx + 0]);
        Assert.Equal((byte)68, macPixels[centerIdx + 1]);
        Assert.Equal((byte)156, macPixels[centerIdx + 2]);
        Assert.Equal((byte)255, macPixels[centerIdx + 3]);

        (byte[] secondPass, int secondW, int secondH) = SimsSDL.Program.PrepareWindowIconPixels(macPixels, macW, macH, isMacOs: true);
        Assert.Same(macPixels, secondPass);
        Assert.Equal(macW, secondW);
        Assert.Equal(macH, secondH);
    }

    [Fact]
    public void MacOsInfoPlists_BothReferenceAppIcon()
    {
        string repoRoot = Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "..", "..", "..", "..", ".."));
        string previewPlist = File.ReadAllText(Path.Combine(repoRoot, "native", "SimsSDL", "PreviewInfo.plist"));
        string releasePlist = File.ReadAllText(Path.Combine(repoRoot, "native", "SimsSDL", "ReleaseInfo.plist"));

        Assert.Contains("<key>CFBundleIconFile</key><string>AppIcon</string>", previewPlist, StringComparison.Ordinal);
        Assert.Contains("<key>CFBundleIconFile</key><string>AppIcon</string>", releasePlist, StringComparison.Ordinal);
    }

    [Fact]
    public void PrepareWindowIconPixels_ScalesDistSims1IconToMacOsDockBounds()
    {
        string repoRoot = Path.GetFullPath(Path.Combine(AppContext.BaseDirectory, "..", "..", "..", "..", ".."));
        byte[] pngBytes = File.ReadAllBytes(Path.Combine(repoRoot, "dist", "sims1-icon.png"));
        StbImageSharp.ImageResult decoded = StbImageSharp.ImageResult.FromMemory(
            pngBytes,
            StbImageSharp.ColorComponents.RedGreenBlueAlpha);

        (byte[] macPixels, int macW, int macH) = SimsSDL.Program.PrepareWindowIconPixels(
            decoded.Data,
            decoded.Width,
            decoded.Height,
            isMacOs: true);

        Assert.Equal(160, macW);
        Assert.Equal(160, macH);

        int minX = macW, minY = macH, maxX = -1, maxY = -1;
        for (int y = 0; y < macH; y++)
        {
            for (int x = 0; x < macW; x++)
            {
                if (macPixels[((y * macW) + x) * 4 + 3] >= 128)
                {
                    minX = Math.Min(minX, x);
                    maxX = Math.Max(maxX, x);
                    minY = Math.Min(minY, y);
                    maxY = Math.Max(maxY, y);
                }
            }
        }

        Assert.Equal(16, minX);
        Assert.Equal(143, maxX);
        Assert.Equal(16, minY);
        Assert.Equal(143, maxY);
    }
}
