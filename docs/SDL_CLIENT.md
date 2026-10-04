# SimsSDL: the cross-platform front end

`SimsSDL` is a second front end for the native simulation. It uses SDL3 and SDL_GPU (Vulkan on Linux, Metal on macOS, Direct3D 12 on Windows) instead of AppKit and Metal. It builds from the same Swift package as the macOS app and shares `SimsCore` (content, scene model, viewport and picking maths) and `SimsClient` (the simulation host bridge) with it.

Status: it draws exported lot scenes with the Metal renderer's lot pass: terrain, depth-sorted sprites with per-pixel depth, Sim meshes and room lighting. At near zoom it matches the CPU reference renderer (`tools/render_scene_cpu.py`) to a median difference of 2/255. It can play a lot live through the simulation host. The original UI overlays (control panel, buy and build modes, pie menus, dialogs) and audio are not ported yet. Live mode shows only the lot, with an empty panel area.

## Build

Install the Swift 6 toolchain, SDL3 (`libsdl3-dev`, or a local build with `sdl3.pc` on `PKG_CONFIG_PATH`) and, for live mode, the .NET 9 SDK.

```sh
cd native/SimsNative
swift build --product SimsSDL      # off macOS SimsSDL is always built
SIMS_SDL=1 swift build --product SimsSDL   # on macOS SDL3 is opt-in
swift test                         # SimsCore tests, on every platform
```

The SPIR-V, MSL and DXIL shaders in `Sources/SimsSDL/Shaders` are generated from `Shaders/sdl/*.hlsl` by `tools/build_sdl_shaders.sh`. Run it after changing a shader.

Live mode also needs the simulation host:

```sh
export DOTNET_CLI_HOME="$PWD/runtime/dotnet"
dotnet build -c Release native/SimsSimulation/SimsSimulation.csproj
```

## Run

```sh
# One exported scene, rendered offscreen to a PNG (default scale 2):
SimsSDL --scene <dir>/scene.json --png out.png [--width 1280 --height 960 --zoom near|medium|far --scale 2 --no-lighting]

# The same scene in a window:
SimsSDL --scene <dir>/scene.json

# Play a lot live through the simulation host:
SimsSDL --house 5 [--game runtime/game] [--workspace <repo>] [--data-root <repo>] [--profile player] [--neighborhood 1] \
        [--speed 0|1|3|10] [--answer-dialogs]
```

Build with `-c release` for live play: a debug build cannot keep up with the host's animation stream. The host loads a lot paused; `--speed` sets the speed once the lot is ready. Game dialogs are printed to standard error until the dialog UI is ported. Y or Enter, N and C answer the oldest one, and `--answer-dialogs` answers each with yes or OK. In a live lot P pauses or resumes, and 1, 2 and 3 pick normal, fast and fastest speed.

`--game` defaults to `runtime/game` in the workspace. The workspace is found by searching upward from the executable or the current directory for `native/SimsSimulation`. Live sessions are written to `runtime/native-sessions/<id>`, and the host's log is in `simulation.log` in the session folder. A newer .NET runtime than 9 needs `DOTNET_ROLL_FORWARD=Major`.

In a window, the mouse wheel zooms, the arrow keys or a right drag pan, Escape quits, and a left click prints the object and wall under the cursor.

### Headless Linux

SimsSDL runs without a GPU on Mesa's lavapipe Vulkan driver.

```sh
export VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json
SDL_VIDEO_DRIVER=offscreen SimsSDL --scene scene.json --png out.png   # no display needed
Xvfb :77 -screen 0 1280x1024x24 &                                     # or a virtual display
DISPLAY=:77 SimsSDL --house 5
DISPLAY=:77 import -window root shot.png                              # ImageMagick screenshot
```
