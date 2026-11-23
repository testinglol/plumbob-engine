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
}
