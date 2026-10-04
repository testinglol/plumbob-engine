# The Sims: native macOS reconstruction

This workspace contains a native ARM64 Metal renderer, a persistent native .NET simulation, and a decompilation reference for the supplied Windows executable. It is an early reconstruction, not a complete playable port. The frontend is being rebuilt from The Sims 1's original UI assets and coordinates, with Retina rendering. The Simitone frontend is not used.

## Source checkout

This repository includes the native source, checks, documentation, decompilation references, and snapshots of the Simitone, locally modified FreeSO, unshield, and widescreen-patcher sources. Their original license files are retained. These snapshots are ordinary repository files; cloning this repository does not require initializing them as submodules.

The game ISO, installed game files, runtime caches, saves, generated app bundles, and logs are kept locally and excluded from Git. Use your own installed Complete Collection folder through `SIMS_GAME_DIR` or the app's first-launch folder picker. Install Xcode and the .NET 9 SDK, restore the dependencies with the command below, and use `tools/run_native.command` or `tools/package_release.command` to build. References below to generated runtime files, logs, and app bundles describe the development workspace; those files are not supplied by a source checkout.

## Run the current previews

Open `Sims Native Preview.app` and choose the installed Complete Collection folder on first launch. The app requires `TemplateUserData/LotLocations.iff`, so it will not retain an older development fixture or any path that lacks Complete Collection neighborhood data. Or run `tools/run_native.command 5` to build both components and start the lot; this command prefers `~/Downloads/The Sims 1` when it contains both the game UI archive and Complete Collection neighborhood data, or accepts another installation through `SIMS_GAME_DIR`. The original artwork now presents household portraits, needs, personality, career, clock, funds, speed controls and a functional action queue. Click a portrait to select a resident, the head button for personality, the briefcase for career, a visible object to open its interaction menu, or a queued action to cancel it. The renderer receives 30 updates per second for original Sim meshes, skins and object animations. Original startup dialogs wait for an explicit response in the native window. Click the original buy-mode button or press `B` to open the original-artwork buy catalog, select an affordable object and click a ground tile to purchase it. `R` rotates the selection; Escape or right-click cancels it. With no catalog item selected, click an editable existing object, then a destination ground tile to move it, or press Delete to sell it. A green/red placement footprint checks engine rules before placement. The selected object’s original directional sprites appear as a translucent placement ghost. Click the original build-mode button to select floor patterns, then click a ground tile or drag a rectangle to paint it. The blue footprint shows the selected area; the simulation applies build restrictions and costs on release. Choose the original wallpaper tool to browse wall patterns, then click a visible wall surface to paint it. Choose the original wall tool to browse walls/fences, select a style and drag a line between lot vertices. Shift-drag builds a rectangular perimeter; Option-drag deletes a wall line. Shift-click a ground tile or visible wallpaper surface to fill that room with the selected pattern. Option-drag removes floors, Option-click removes wallpaper, and Shift-Option-click removes the room’s selected surface type. Build and buy modes remain paused; return to live mode to resume play with the speed controls. Remaining gameplay subpanels, contained-object previews and other build tools are unfinished.

Use P or Space to pause/resume; 1, 2 and 3 choose normal, fast and fastest speeds. Tab selects the next Sim. W switches walls up/down. Drag to pan and scroll to zoom. The macOS Simulation menu also provides Save and Load for the `manual` slot. Closing the app requests an `autosave`. Saves use a separate native profile and do not replace the original game saves.

Original speed controls are reconstructed at their original positions. `analysis/original-speed-controls.json` records the source executable hash and the coordinate initializer instructions. The original bitmap font and interaction categories are also reconstructed. Generic game dialogs use original frame, button and font resources; their exact original layout and specialized screens still need reconstruction. See `docs/ORIGINAL_UI.md`.

For a lot snapshot, run this command from the workspace:

```sh
tools/preview_native_lot.command 5 60
```

The script builds the Swift app and native simulation, loads house 5, advances 60 ticks, exports the ground-floor sprites, original Sim meshes and terrain, and displays them with Metal. This is a static snapshot. It includes wall patterns and masks in walls-down mode, plus per-pixel depth for object sprites with original SPR2 depth data. It omits roofs, room lighting and wall junctions. Missing resources are listed in each scene export. There are no working gameplay controls in this preview.

The installed Xcode and .NET 9 SDK are required. Dependencies are already restored locally. If restoring again, use:

```sh
export DOTNET_CLI_HOME="$PWD/runtime/dotnet"
export NUGET_PACKAGES="$PWD/runtime/nuget"
dotnet restore native/SimsSimulation/SimsSimulation.csproj -p:EnableWindowsTargeting=true -p:NuGetAudit=false --disable-build-servers
```

To rebuild only the Swift app, run `tools/build_native_app.command`.

## Verified results

| Component | Current result |
| --- | --- |
| Original executable analysis | 18,543 detected nonexternal, nonthunk functions exported as Ghidra C pseudocode; all report decompiled |
| Native application | Mach-O ARM64 executable, AppKit window, Metal rendering |
| Original UI assets | 794 resources read from the original FAR archive; original RLE8 BMPs decoded |
| Resolution handling | Offscreen Metal output at 1600 × 1200, 1728 × 1117 and 3456 × 2234; aspect ratio preserved |
| Native simulation | House 1 loads 125 entities; 60 updates produce 123 entities and advance 13:32 to 13:33 |
| Furnished lot | House 5 loads and advances 60 updates; 308 entities, 733 exported sprites, 133 textures |
| Native architecture rendering | Ground-floor walls with original patterns and shape masks; 74 wall segments up and 68 down on live lot 5; Metal terrain triangles from simulation heights and grass state; textured floor meshes follow slopes and diagonal half-tiles |
| Native avatar rendering | Original body/head/hand meshes, BMP/TGA skins, simulation animation poses and Metal mesh depth testing |
| Object sprite depth | 200 depth-bearing sprite instances on the resident lot 5 snapshot; twelve GPU checks pass for sprite/mesh overlap, transparency, flipping, reloading and streamed meshes with appended textures |
| Custom asset packs | Manifest validation, dependencies, deterministic ordering, explicit overrides, path containment |
| Live native runtime | Resident Goth family, pause/resume, Sim selection, original interaction menus, game dialog responses, architecture commands and compatible VM save/load; Mortimer routes to the sofa and reaches the seated posture after Sit is selected |
| Live animation | 76 distinct pose updates at 30.02 updates per second; paused poses stop; textures are retained; the recorded stream replays through Metal |
| Pack-to-simulation integration | Independent cloned content mounts; a test floor registers, is applied to a buildable tile and survives save/load; a test skin overrides an archived original texture |
| Swift verification | 119 tests pass, covering archives, BMP/TGA images, packs, installed-language detection, archived skin overrides, mounts, scene/terrain/mesh/depth validation, Retina hit coordinates, pixel/depth picking, original bitmap fonts, interaction categories, dialog choices, packed animation validation and linear-light transparency |

The full pseudocode is under `analysis/full-decompilation`, with its index in `functions.tsv`. This is inferred code with autogenerated names and types, not the original source and not a directly compilable macOS port. Original UI/display references are also exported under `analysis/decompiled`.

## Architecture and remaining work

`native/SimsNative` owns the AppKit frontend and Metal renderer. It reads original assets through `SimsCore` and creates independent content mounts with ordered pack overlays. `native/SimsSimulation` runs the TS1 SimAntics core from FreeSO without a graphics device. A versioned stdin/stdout protocol carries commands and state. It sends packed incremental animation updates and exports bounded JSON scenes, immutable RGBA sprites, original 8-bit sprite depth maps and encoded BMP/TGA avatar textures, which Swift imports without depending on the Simitone UI. See `docs/RUNTIME_PROTOCOL.md`.

The FreeSO TS1 initialization change is saved in `patches/freeso-headless-ts1.patch`. It allows TS1 resources and avatar providers to initialize in server mode, exposes encoded texture bytes without a graphics device, gives loose skin assets priority over archived resources, freezes TS1 object behavior while paused, and supports the 36,000-tick delay in the Superstar controller. FreeSO is pinned to `f86bbd34b2112296ed786741f640a0535886d180`; the containing Simitone checkout is `4906db3156616bfaffc10ce0963cf08062975fef`. Source licenses remain in their checkouts.

The next required work is complete Metal architecture rendering and smooth avatar animation; localized native UI text and remaining original screens; original-family compatibility; full build/buy, audio and expansion behavior; and sub-tick animation interpolation. The base neighborhood-to-family flow now runs through native controls, saves and reloads a new household, and maps installed Sims.exe language metadata to the simulation string-table code. Original Sims are rendered with depth-tested mesh triangles and simple directional shading. Object sprites with SPR2 depth data now share that depth buffer. Walls and sprites without depth maps still use draw ordering; exact depth calibration and all object intersections need further validation. Roofs, wall junctions and room lighting are not rendered yet. Avatar slot attachment also needs verification. Walls-up/down views work; cutaway mode and camera rotation remain missing. Terrain detail is procedural and uses the simulation's terrain colors, heights and grass state; floor textures now follow terrain vertices, including both diagonal half-tiles. The seven expansion packs' data has been extracted, but their behavior has not all been validated. Fame, vacation and other expansion-specific systems need explicit compatibility tests before the port can be called complete.

The app keeps player data separately from its bundled/source files and the installed game. Its data root is `~/Library/Application Support/Sims Native`; profiles and saves live under `runtime/native-profiles`, while temporary sessions and the .NET CLI home also stay under this data root. A one-time migration copies profiles from the earlier workspace `runtime/native-profiles` location when the new location is empty. Developer and command-line runs default their data root to the workspace; pass `--data-root DIRECTORY` to the simulation host to choose another location. On first app launch, choose the installed PC Complete Collection folder containing `UIGraphics/UIGraphics.far` and `TemplateUserData/LotLocations.iff`; the selected path is remembered in the app's macOS preferences, and game files stay in their original location. The supplied development game data is under `runtime/game`; command-line runs can specify it with `--game`. From the neighborhood screen, choose **File → Import Original Save…** to copy an original save from the game folder or its `UserData` folder into a new native profile; the selected source remains unchanged and the imported profile becomes active on relaunch. Existing CrossOver scripts and bottles are earlier diagnostics and are not part of the native deliverable.

## Custom expansions

See `docs/PACKS.md` and `packs/example`. The same ordered packs now feed both the Swift renderer and the simulation. New floor content and replacement Sim skins have end-to-end integration checks. A custom IFF object pack passes catalog, purchase, collision refund, movement, rotation, save/load and resale checks. New behaviors and authoring tools still need implementation and coverage. Native engine plugins and entirely new game systems do not yet have an implementation or stable API.

## Checks

```sh
xcrun swift test --package-path native/SimsNative --cache-path /tmp/sims-swift-package-cache --scratch-path native/SimsNative/.build
native/SimsNative/.build/release/SimsNative --game "$PWD/runtime/game" --packs "$PWD/packs" --inspect
python3 tools/check_native_runtime.py
python3 tools/check_native_depth.py
python3 tools/check_native_progress.py
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-sleep
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-career
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-interaction
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 51 0 --check-visitors
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-family-membership
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-career-absence
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-social
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-school
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" --check-family-move-in
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" --check-neighborhood-edits
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-career-tracks
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-career-requirements
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" 5 0 --check-services
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll --check-save-compat
DOTNET_CLI_HOME="$PWD/runtime/dotnet" dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll "$PWD/runtime/game" "$PWD" --audit-expansions
python3 tools/check_expansion_resources.py "$PWD/runtime/game"
python3 tools/check_native_plugins.py
tools/package_release.command 1.0.0   # standalone Apple Silicon bundle in dist/
```

The checks added in the latest pass (`--check-career-absence`, `--check-career-requirements`, `--check-social`, `--check-school`, `--check-family-move-in`, `--check-neighborhood-edits`, the visitor departure phase and the new-game picker step) have not been run yet. See "Changes awaiting the final gate" in `docs/PARITY_LEDGER.md`.

The current depth-enabled Metal renders are in `analysis/native-depth-walls-up-retina.png` and `analysis/native-depth-walls-down-retina.png`, both 3456 × 2234. Earlier avatar and architecture renders remain under `analysis`. Logs are under `logs`. The newer Windows client's asset and shader inspection is documented in `docs/LEGACY_CLIENT.md`.

Run `python3 tools/check_native_animation.py` to measure the real lot's live pose stream, check pause, texture reuse and acknowledged snapshot cleanup, and record an animation fixture. The latest result is in `logs/native-animation-result.json`. `--animation PATH` applies one packet to an offscreen scene; `--animation-stream PATH` replays up to 300 recorded packets before rendering. The recorded first/last poses are shown in `analysis/native-animation-first.png` and `analysis/native-animation-last.png`.
