# Changelog

All notable changes to **Plumbob Engine** are documented in this file.

## [0.9.0] - 2026-11-27

- Added multi-story architecture up to 16 floors with progressive Build-mode floor unlocking and empty-story collapse, full `Arry` save/reload persistence, multi-floor stair routing and direct upper-staircase interaction, an animated HUD story-stack selector (preserving classic 2-story controls), and two-band overhead/voxel exports.
- Added seamless extended lot surroundings (`LotSurroundings`, `SceneExporter.Scenery`) with terrain/hill boundary easing, mirrored and continued roads, and biome-matched off-lot flora integrated with **Enhanced Graphics** and **Seasons**, alongside smooth off-screen vehicle, pedestrian, and stray transit (`OffLotTransit`).
- Added in-app GitHub update checks and self-updating (`ClientUpdater`) with ETag caching, SHA-256 and archive verification, neighborhood update and progress dialogs, and atomic bundle/directory swap-and-relaunch across macOS, Windows, and Linux.
- Upgraded **Enhanced Graphics** with dedicated sun-shadow (`sunShadow`) and indirect-radiance (`radiance`) passes and static-frame convergence, expanded **Seasons** with surrounding-scenery autumn leaf rings, falling-leaf atmosphere particles, and Play Options **Season Length** and **Climate** steppers, and added native Options subpages and `About` popups across **Enhanced Graphics**, **Seasons**, and **Smart Free Will**.
- Added automatic and manual **UI Scale** controls, sharp vector Options/UI controls and icons, streaming `.far` and lazy `Downloads/` `.iff` loading, case-insensitive Linux/macOS archive and audio discovery, nested custom skin/wallpaper/floor catalog loading, saved-lot `OBJM` multi-tile and mid-interaction `PendingActionRequests` recovery, and pet animation, menu-token, and short-step routing fixes.

## [0.8.7] - 2026-11-25

- Fixed classic room and outdoor lot lighting multipliers converting sRGB tints into linear space (`LotRenderer`), preventing washed-out lighting when **Enhanced Graphics** is disabled.

## [0.8.6] - 2026-11-25

- Refined **Seasons** autumn flora classification, expanded per-lot flora stamp capacity, and added deciduous shrub leaf-drop rings with synchronized Metal, Vulkan, and Direct3D 12 trail shaders.
- Added live multi-slot GPU video and synchronized audio capture (`LiveVideoRecorder`) with optional cursor compositing, `--mute-capture`, and smooth scripted camera/clock choreography.

## [0.8.5] - 2026-11-25

- Added the dual-side Simulation and Client Plugin SDK (`ISimsPlugin` + `ISimsClientPlugin` / `ClientPluginHost`) with managed GPU render passes, audio filtering, 2D HUD widgets and toasts, declarative Options pages, declarative pack cheats, and SimAntics global hooks.
- Unified **Enhanced Graphics** and **Seasons** plugin sources under `native/Plugins/` in `PlumbobEngine.sln` with built-in SPIR-V shader reflection, `SimsSDL --build-pack` sealing, and separated core/pack Metal, Vulkan, and Direct3D 12 shaders.
- Added real-time dynamic vehicle shadows and live voxel-map updates for arriving and departing vehicles (School Bus, Carpool, and service cars), along with neighbor menu name and vector UI scroll-arrow polish.

## [0.8.0] - 2026-11-24

- Added multi-stage seasonal deciduous foliage synthesis (autumn leaf drop to winter bare branches), multi-batch snow footprint trails, and updated **Seasons** and **Enhanced Graphics** Metal, Vulkan, and Direct3D 12 shaders.
- Added zero-copy direct pack overlays (`DirectPackOverlay`) to skip filesystem content mounts when only plugin/shader packs are active, along with full stale-session directory cleanup.
- Upgraded base-game roaches stomp/spray BHAV chaining, tightened autonomy candidate filtering, ensured opt-in packs (**Smart Free Will** and **CC Folder Browser**) stay off by default across both standalone bundles and `--packs` multi-pack roots, and added `--record-manifest` video rendering.

## [0.7.1] - 2026-11-23

- Fixed active per-Sim motive deltas (such as bed comfort/energy recovery and work/school shifts) persisting across save/load, with automatic recovery for older mid-sleep and mid-shift saves.
- Enabled editing unoccupied residential lots directly in Simless Buy/Build mode from the neighborhood screen (including vacant lots with stray animals) and excluded Magic Town residential lots from standard Simoleon starter-home highlights.

## [0.7.0] - 2026-11-23

- Added the optional **Smart Free Will** pack (Plugin API v6) with full-lot Sim awareness, personality-driven autonomy, social chain reactions, wordless overhead thought bubbles, and in-game switching between Smart, Mastermind, and Classic Free Will.
- Upgraded **Enhanced Graphics** and **Seasons** with voxel-hull orthographic depth maps, contact and ambient occlusion refinements, and synchronized Metal, Vulkan, and Direct3D 12 shaders.
- Improved SimAntics interaction parity, stair/portal routing, Buy/Build placement ghosts, `Alt+Enter` fullscreen toggling, and live shader hot-reloading (`--hot-reload-shaders`).

## [0.6.1] - 2026-11-22

- Modularized engine, simulation server, scene exporter, lot renderer, and live UI controller assemblies under `PlumbobEngine.sln`, removed external MonoGame framework dependency, hardened shader/bundle verification across macOS (Metal), Windows (Direct3D 12 & Vulkan), and Linux (Vulkan), and bundled **Enhanced Graphics**, **Seasons**, and optional **CC Folder Browser** packs.
