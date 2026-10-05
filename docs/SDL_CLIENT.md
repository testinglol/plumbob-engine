# SimsSDL: the cross-platform front end

`SimsSDL` is a second front end for the native simulation. It uses SDL3 and SDL_GPU (Vulkan on Linux, Metal on macOS, Direct3D 12 on Windows) instead of AppKit and Metal. It builds from the same Swift package as the macOS app and shares `SimsCore` (content, scene model, viewport and picking maths) and `SimsClient` (the simulation host bridge) with it.

Status: it draws lot scenes with the Metal renderer's lot pass: terrain, depth-sorted sprites with per-pixel depth, Sim meshes and room lighting. At near zoom it matches the CPU reference renderer (`tools/render_scene_cpu.py`) to a median difference of 2/255. Live play goes through the simulation host, with the original UI ported from the macOS app: the control panel (needs, mood, job, relationships, personality, skills, household), buy and build modes, pie menus, game dialogs (including name entry and the phone book), the options panel with sound settings, the neighborhood screen, Select a Family, Create a Family, the wardrobe and travel maps. Audio plays through SDL (WAV and MP3, positioned on the lot), including the neighborhood music on a separate audio-only host.

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

# Start at the neighborhood screen, as the original does:
SimsSDL [--game runtime/game] [--workspace <repo>] [--data-root <repo>] [--profile player] [--neighborhood 1] [--no-audio]

# Or go straight to a lot:
SimsSDL --house 5 [...] [--speed 0|1|3|10] [--answer-dialogs] [--script <file>]

# Custom packs (docs/PACKS.md) come from the children of --packs that hold a pack.json:
SimsSDL --packs runtime/packs [...]

# Pack commands print JSON and exit without opening a window:
SimsSDL --packs <dir> --pack-report | --list-plugins | --trust-plugin <pack> | --revoke-plugin <pack>
SimsSDL --packs <dir> --pack-id <pack> --allocate-object-guid <name> | --reserve-object-guid <name>
```

When an enabled pack carries a plugin the player has not trusted (or whose files changed since they trusted it), SimsSDL asks at launch with a message box; Keep Disabled is the default. `--answer-dialogs` skips the question, so unattended runs never load untrusted code. Trust is recorded in `Settings/plugin-trust.json` under the data root.

Build with `-c release` for live play: a debug build cannot keep up with the host's animation stream. The host loads a lot paused; `--speed` sets the speed once the lot is ready, and on an empty lot once Create a Family has moved the family in. `--answer-dialogs` answers each game dialog with its first button, for unattended runs. `--no-audio` starts no audio device.

`--game` defaults to `runtime/game` in the workspace. The workspace is found by searching upward from the executable or the current directory for `native/SimsSimulation`. Live sessions are written to `runtime/native-sessions/<id>`, and the host's log is in `simulation.log` in the session folder. Each session gets its own copy of the game content; SimsSDL deletes it when the host exits, since off APFS it is a full copy; a failed deletion is reported on standard error. A newer .NET runtime than 9 needs `DOTNET_ROLL_FORWARD=Major`. Quitting (the window's close button or SIGTERM) autosaves the lot and waits up to ten seconds for the host to finish.

### Scripted input

`--script FILE` plays a list of inputs into a live window through the same calls the mouse and keyboard reach, and saves screenshots, so UI flows can be run and looked at without a person at the window (for example with `SDL_VIDEO_DRIVER=offscreen`). One command per line; `#` starts a comment:

| Command | Effect |
| --- | --- |
| `wait N` | Do nothing for N frames |
| `waitfor lot\|menu\|panel\|dialog\|nodialog [N]` | Wait until the condition holds, at most N frames (default 1800) |
| `key NAME` | Press `escape`, `enter`, `tab`, `space` or one character |
| `click X Y` | Left click at window pixels |
| `clicksim N` | Left click the N-th household Sim (Tab order, from 0), scrolling the view to it if it is off screen |
| `choose LABEL` | Left click the open pie menu's entry with this label, including submenu names |
| `shot FILE.png` | Write the next frame to a PNG |
| `quit` | End the run |

A timed-out condition, a Sim that cannot be found or a missing pie entry ends the run with exit status 2. `python3 tools/check_sdl_script.py [pie-menu] [plugin-panel]` runs the stored flows against house 5 and writes screenshots to `logs/sdl-script/`; `plugin-panel` trusts the example allowance pack in a temporary data root, chooses Allowance > Details on a child and waits for the plugin's panel.

### Controls

In a live lot the mouse works as in the original: left click for pie menus, buttons and placement, right drag or the arrow keys to scroll, and the wheel to zoom. Keys:

| Key | Action |
| --- | --- |
| P or Space | Pause or resume |
| 1, 2, 3 | Normal, fast and fastest speed |
| Tab | Next Sim in the household |
| W | Cycle walls up, cutaway and down |
| Page Up, Page Down | Story up or down |
| [ and ] | Rotate the camera |
| B, F | Buy and build catalogs |
| R | Rotate the held object |
| Delete or Backspace | Sell the held object |
| S | Save |
| L | Load the saved house; a save that needs uninstalled packs asks before removing their content |
| E | Open the next pack plugin panel; after the last one it closes (Enter or Escape also close it) |
| Enter, Escape | Answer the open dialog with its first button, or cancel it; Escape also closes a pie menu |

Outside live mode (`--scene`), the wheel zooms, the arrow keys or a right drag pan, Escape quits, and a left click prints the object and wall under the cursor.

### Profiling

With `SIMS_PROFILE=1` set, every 120 frames SimsSDL logs the frame rate, the milliseconds each frame spends per phase (SDL events, host events, animation, swapchain, UI, command encoding, GPU wait) and its resident memory, followed by the host events handled in that window with their count and total handling time. `SIMS_DEBUG=1` adds periodic frame and scene details.

The host streams about 30 animation frames a second, each a few hundred kilobytes of JSON with packed Sim meshes, and a full scene snapshot of several megabytes every five seconds while the lot runs. To keep the main thread free, the bridge splits and parses the host's output on its reading queue (animation frames are decoded straight into `SceneAnimation` there), snapshots are decoded on a background thread, and an animation frame only validates what it adds to the snapshot it extends. On the Goth lot at fastest speed this takes main-thread work from about 185 ms to about 7 ms a frame; on lavapipe the rest is software rendering.

### Headless Linux

SimsSDL runs without a GPU on Mesa's lavapipe Vulkan driver.

```sh
export VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json
SDL_VIDEO_DRIVER=offscreen SimsSDL --scene scene.json --png out.png   # no display needed
Xvfb :77 -screen 0 1280x1024x24 &                                     # or a virtual display
DISPLAY=:77 SimsSDL --house 5
DISPLAY=:77 import -window root shot.png                              # ImageMagick screenshot
```
