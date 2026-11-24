# Changelog

All notable changes to **Plumbob Engine** are documented in this file.

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
