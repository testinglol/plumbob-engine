# Legacy client inspection

Inspected on 2 October 2026. Source directory: `/Users/sinh/Downloads/The Sims 1`. The source files were read without executing or changing the Windows client. The native runtime still uses its existing Complete Collection content mount.

## Identity

The `sims.exe` PE version resource identifies **The Sims Legacy Collection 1.10.5**, with the special build label `25th year Release`. Its linker timestamp is 22 February 2025 at 00:33:51 UTC. A linker timestamp is build metadata, not proof of a release date. The executable is 32-bit Windows x86, 10,858,328 bytes, with SHA-256 `0bfd90352698cb8a84b0cab125b198157835451e833dba511b3d3222ff53e9e8`.

The folder includes a separate third-party launcher and an `anadius32` import in the game executable. It should not be described as a verified unmodified EA installation. Those components were not executed or used for the native port. The EA SDK configuration's `applicationVersion` is `1.10.0`; the installer manifest says `1.0.0.124`. These are different metadata fields and do not replace the executable's `1.10.5` file version.

## Asset comparison

The comparison covers matching paths beneath GameData, UIGraphics, expansion directories, ExpansionShared and Downloads, against `runtime/game`. It excludes personal saves and photo albums.

- 2,865 matching files: 2,814 are byte-identical and 51 differ.
- All 794 entries in `UIGraphics/UIGraphics.far` are byte-identical, including the original control artwork and bitmap fonts.
- Inspecting changed archives, including the mapped `ExpansionPack1`/`ExpansionPack` directory, found 530 changed IFF entries and no added or removed entries in those archives.
- Comparing those IFF files plus six changed loose IFF files produced 536 chunk comparisons. Changed existing payloads consist of 535 `rsmp` resource maps and one `STR#` in `GameData/ranger8.iff`.
- `GameData/credits.iff` adds a `STR#` chunk and an `XXXX` chunk. No changed BHAV, BCON, SPR2 or DGRP payloads were found in the compared IFF files.

This evidence supports retaining the original assets for the native UI. It does not establish identical executable gameplay, and it does not prove that every file in either installation is interchangeable. In particular, archive resource maps differ even when behavior and sprite payloads match. The useful modernization reference is primarily the executable's renderer rather than a replacement UI asset set.

Full hashes, file lists and chunk differences are recorded in `analysis/legacy-client-comparison.json`.

## Rendering evidence

Ghidra 12.1.4 imported the executable into the separate `analysis/legacy-ghidra-project/SimsLegacy` project. Initial analysis completed successfully in 179 seconds. The analyzer logged warnings about some data and functions; success is not a guarantee that every inferred type or function boundary is correct.

Recovered code at `0x009d8dc0` loads `vulkan-1.dll` and resolves `vkGetInstanceProcAddr`. The graphics initialization path at `0x00982aa0` invokes renderer initialization and reports `Vulkan Initialization Failed` if it fails. The executable also imports `SetProcessDPIAware`, `GetMonitorInfoA` and `EnumDisplayMonitors`. These are concrete Windows dependencies; this binary is not a native macOS executable.

Thirty-three embedded SPIR-V 1.0 shader modules were extracted with original file offsets and virtual addresses: 12 vertex modules and 21 fragment modules. Every module passed `spirv-val --target-env vulkan1.0`. Sixteen fragment modules write depth. The modules and their disassemblies are under `analysis/legacy-shaders`; `index.json` records their validation and vertex/fragment entry points. References to their data addresses converge on shader initialization at `0x009d1f90`. Eleven selected renderer/font functions were successfully exported under `analysis/legacy-decompiled`, together with their reference addresses.

Several fragment shaders use `DepthReplacing` and write `FragDepth`. For example, `008c1210.spvasm` samples an integer texture, uses a 256-entry lookup table to select one of eight input depth values, discards the sentinel entry, and writes the selected depth. Other shaders sample a separate depth texture and interpolate between input depth values. These operations are evidence for per-pixel depth handling. The exact association of each shader with terrain, objects, walls or overlays must still be traced from renderer setup and draw calls.

## Implications for the native port

Use the Legacy client as an additional reverse-engineering reference while preserving the original executable analysis and asset base. The next useful renderer investigation is the depth-texture encoding and draw-call inputs, which can inform correct Metal occlusion between object sprites and Sim meshes. UI scaling and font rendering are also useful comparison targets.

The shaders have been validated as Vulkan modules; they are not used directly by Metal. The native renderer now exports original SPR2 depth bytes and implements the separate color/depth texture operation in Metal, including the 255 sentinel and 0–254 normalization seen in `008bf478.spvasm`. Eight GPU checks and resident-lot integration pass. Camera-space depth intervals currently derive from the FreeSO rendering reference adapted to our projection; exact Legacy calibration still needs tracing. See `docs/RUNTIME_PROTOCOL.md` for the scene fields and test command. This step does not complete the macOS port or the expansion API. The original UI, native macOS target and custom-pack requirements remain unchanged.

EA's [Legacy Collection documentation](https://help.ea.com/en/articles/the-sims/the-sims-legacy-collection/the-sims-legacy-minimum-requirements/) describes Vulkan rendering, widescreen support and retained original gameplay. Its [27 February 2025 patch notes](https://www.ea.com/ea-play/news/sims-legacy-and-the-sims-2-legacy-patch-notes-27-02) list additional executable fixes. Those release-wide statements do not independently verify every feature or fix in this particular local copy.
