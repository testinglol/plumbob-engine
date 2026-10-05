# Custom content pack contract

A pack is a directory with `pack.json` and a `files` directory. Resource paths inside `files` follow the original game's layout. Both the Swift renderer and the simulation use the ordered pack stack. Live sessions clone the base files and apply overlays in a separate content mount.

```json
{
  "schemaVersion": 1,
  "id": "local.my-expansion",
  "name": "My expansion",
  "version": "0.1.0",
  "baseGameVersion": "1.90",
  "dependencies": [],
  "overrides": []
}
```

Use a stable unique ID. Dependencies specify `id` and an exact `version`, or `*`. The loader orders dependencies first and independent packs by ID. Missing dependencies, incompatible versions, cycles and duplicate pack IDs fail before loading.

The loader scans winning pack IFF resources, including IFF entries inside FAR archives, for object definitions before creating a mount. Nonzero object GUIDs must be unique across the enabled custom packs and within each resource. Conflict errors identify both pack IDs, resource paths and OBJD chunk IDs. Explicit file overrides remove the earlier file’s definitions from this check. To replace an existing custom object, use its original resource path and declare that path in `overrides`; a second filename with the same GUID is rejected. Each tile definition in a multi-tile object needs its own GUID.

`--pack-report` includes an `objects` array sorted by numeric GUID, with `guid`, `chunkID`, `path` and `owner`. An archived object's path uses `archive.far::entry.iff`. The loader also checks these GUIDs against installed base and official expansion IFF definitions in FAR archives and loose Downloads resources. A new filename cannot reuse an installed object's GUID. Replacing its original loose IFF or complete FAR archive requires an explicit override at that resource path; the replaced container's old definitions are excluded. Original zero-GUID placeholders do not reserve an identity. Original duplicate definitions are tolerated, but a new pack collision with any unreplaced definition is rejected. GUID allocation and persistent reservations are described below. Pack IFF headers, chunk boundaries and supported OBJD versions (136, 138–142) are also validated.

Supported resource roots are `GameData`, `UIGraphics`, `Downloads`, `SoundData`, `Music` and `ExpansionShared`. Typical paths are:

```text
files/Downloads/local.my-expansion/my-object.iff
files/GameData/Floors/my-floor.flr
files/GameData/Walls/my-wall.wll
files/GameData/Skins/my-skin.skn
files/GameData/Skins/my-skin.bmp
files/UIGraphics/cpanel/Backgrounds/PanelBack.bmp
```

If replacing a base-game resource or a resource provided by an earlier pack, list its complete game-relative path in `overrides`. For example:

```json
"overrides": ["UIGraphics/cpanel/Backgrounds/PanelBack.bmp"]
```

Paths compare without case sensitivity, and both Windows and Unix separators are accepted. Absolute paths, traversal, duplicate normalized paths, unsupported extensions and symlinks escaping the pack directory are rejected. A declared override must exist in the pack.

Place packs under the workspace's `packs` directory. The native app discovers each child containing `pack.json`; `--packs DIRECTORY` selects a different pack collection. The example pack is intentionally empty except for a content-placement note.

Validate a collection and inspect its resolved resources before starting a game:

```sh
native/SimsNative/.build/release/SimsNative --game "$PWD/runtime/game" --packs "$PWD/packs" --pack-report
```

This command uses the game's loader, including dependency, base-resource override and skin-alias checks. It exits unsuccessfully on validation errors. Successful output is JSON with ordered `id@version` entries and a save-compatibility fingerprint. Each winning resource lists its normalized path, owning pack, providers in load order, explicit override declaration, byte count and SHA-256. The last provider owns the resource. Base-game assets are not listed as pack providers. The report reads content without creating a mount or changing saves, and does not require Metal or an unlocked desktop.

The fingerprint uses the same calculation as simulation mounts. It changes when a winning asset changes; modifying an asset hidden by a later pack does not change it. Pack IDs and versions also participate. This validates loading and save identity, not the behavior of a custom IFF object or the visual correctness of its artwork.

The current renderer decodes BMP and TGA images for Sim skins, and RGBA sprite exports. Other permitted formats are reserved for the corresponding original game providers; permitting a file in a manifest does not mean the Swift renderer can decode it.

The verified test pack adds a new `.flr` file. It appears under its own filename and ID in the simulator's floor catalog, is applied through the architecture command interface, and survives a VM save/load round trip. The test reuses an original floor resource to exercise the loading path; it is not new artwork.

A replacement skin must declare an override even when the original texture resides inside a FAR archive. Loose BMP/TGA textures and SKN/BMF meshes take priority over archived resources in the simulation. Skin resources are looked up by filename, so packs cannot supply the same skin filename under different skin directories. A skin that conflicts with another loose base skin path is rejected. Use one consistent resource path and the original extension for replacements. BMP/TGA textures and SKN/BMF meshes share a lookup identity within each pair; the loader rejects aliases that would otherwise be silently ignored by the engine’s format priority.

The skin integration fixture replaces Mortimer’s body texture with a small solid-color BMP and verifies its hash in the exported mesh texture. This proves texture replacement. New clothing is written by the outfit compiler (see "Author custom outfits"); newly authored meshes and every skin format in gameplay remain unvalidated.

Each mount records ordered pack IDs/versions and a fingerprint of their winning asset paths and hashes. Native saves require the same fingerprint. Changing pack contents, even without changing the version, prevents an incompatible save from loading.

Object IFF lookup uses the case-insensitive basename, not the containing directory. The loader rejects two winning resources with the same object filename, including loose/archive combinations and IFFs without OBJD chunks that would hide another resource. A unique GUID does not permit a second `chair.iff` under another folder. The same rule checks installed base/expansion archives and Downloads files. Use a unique object filename, or replace the original resource container through an explicit path override. Loose IFFs containing object definitions must be under Downloads; archived IFFs can be in FAR containers. Names containing `globals` are excluded by the engine's object lookup and cannot supply object definitions. These checks prevent accepted packs from silently losing objects to provider priority.

Custom objects with new SimAntics behaviors can be compiled from JSON; see "Author custom objects" below. Uninstalling a pack is covered under "Uninstalling a pack" below. This is not a finished expansion SDK; see "Gameplay plugins, panels and save migration" below for the first code-bearing pack contract.

The simulation protocol exposes `buyObject`, `moveObject` and `sellObject` for catalog entries, including entries loaded from packs. These commands use the engine's placement and transaction logic. The original flamingo has passed purchase, collision refunds, movement, rotation, scene export, save/load and resale checks. See `docs/RUNTIME_PROTOCOL.md` for parameters and the integration command. The native frontend uses the original buy-mode artwork and catalog layout.

Run `python3 tools/check_native_custom_objects.py` to test a separate custom-object pack. The tool extracts the locally installed flamingo IFF into an isolated fixture, starts with fixture GUID `0xF1A00001`, changes its definition label and price to §37, then allocates and reserves a production candidate, updates the OBJD GUID and mounts the pack with the native loader. It verifies catalog discovery and the same object lifecycle checks, including collision refunds. It tests both a second custom filename with the same GUID and reuse of the original flamingo GUID, checking rejection before either content mount is created. The native mount fingerprint matches the pack report, and the base archive and original lot remain unchanged. Results are in `logs/native-custom-object-result.json`. The initial GUID is only a fixture value; the runtime object uses the persisted allocator result.

The fixture also renames its unique-GUID object to the original `flamingo.iff` basename and checks rejection before a mount is created. This proves that filename alias detection works independently of GUID collision detection against actual installed archives.

This fixture reuses original graphics and SimAntics behavior. It proves that a separate IFF with its own identity loads and persists through the pack path; new artwork, newly authored behavior trees and multi-tile behavior still need dedicated coverage. Sprite export is checked, but the fixture does not verify live Metal presentation.

Pack objects also appear in `catalogPage` with CTSS names/descriptions and original BMP thumbnails. A definition's internal OBJD label is distinct from its displayed CTSS name; changing only the definition label does not rename the catalog text. The fixture tests this data path without creating an alternate interface.


## Stable object GUIDs

A manifest can reserve logical object identities before their IFFs exist:

```json
"objectGUIDs": {
  "furniture.chair": 3892318742
}
```

The numeric value above is illustrative; obtain an available ID from the native allocator. Logical names use 1..128 lowercase ASCII letters, digits, dots, underscores or hyphens. Each name retains one nonzero GUID. Duplicate reserved GUIDs within or across packs are rejected. A reservation may match an actual definition in its own pack. A dependent explicit replacement at the same resource container can retain the original pack's reservation. A different resource or pack cannot take a reserved identity. Reservations also check installed base/expansion definitions, even when the reserving pack has no object IFF yet.

To propose an available ID without changing files:

```sh
native/SimsNative/.build/release/SimsNative --game "$PWD/runtime/game" --packs "$PWD/packs" --pack-id local.my-expansion --allocate-object-guid furniture.chair
```

To persist that identity in the target pack's manifest:

```sh
native/SimsNative/.build/release/SimsNative --game "$PWD/runtime/game" --packs "$PWD/packs" --pack-id local.my-expansion --reserve-object-guid furniture.chair
```

Both commands return JSON with `owner`, `name` and numeric `guid`. The target pack must be enabled. The allocator hashes pack ID, logical name and a collision counter, producing candidates in 0xE0000000..0xEFFFFFFF. It checks all installed original object GUIDs, loaded object definitions and reservations, including IDs from explicitly replaced original containers. It retries occupied candidates and reports failure after 4096 attempts. Previously persisted names return their exact reserved GUID instead of recomputing it. This namespace is an application convention; it does not provide a global guarantee against content absent from the enabled installation. Load-time collision validation remains authoritative.

Reservation writes preserve other manifest fields, lock the manifest, reject changes since it was loaded and replace it atomically. This avoids stale writers silently losing existing IDs. The command does not rewrite IFF references: author the object's OBJD and behavior references with the reserved ID. Multi-tile components need separate logical names and GUIDs. Keep reservations when moving or renaming source files; do not recycle removed object identities without a migration plan.

Pack reports include `reservations`. Ordered reservations participate in the same save fingerprint as winning assets and pack versions. Adding or changing a reservation changes compatibility; packs without reservations retain their previous fingerprint calculation. Save migration remains unfinished.

The native build and 87 Swift tests pass, covering deterministic allocation, occupied candidates, validation, persistence, stale manifest detection, collisions with original content, cross-pack conflicts and explicit inherited replacements. The full custom-object integration runs the allocator CLI, verifies that proposal mode is read-only, persists a reservation, checks stable reallocation and report/mount fingerprints, then exercises the allocated GUID through purchase, movement/rotation, placement previews, save/load and resale. It retains all original archive/lot immutability and collision checks.

## Script and animation attachments

Native avatar export now binds the simulation's recorded `BoundAppearances` alongside the Sim's body, head and hand meshes. Both script names ending in `.apr` and bare animation `dress`/`undress` names resolve through the TS1 appearance provider; case and extension aliases share one visual binding. VM suit primitives and animation dress/undress events share canonical bind/unbind methods, so a bare name can remove the same attachment added with an `.apr` name. Older saves containing bare or mixed-case names remain readable. Adding or removing an appearance refreshes the cached visual, while an unchanged appearance set retains it. Outfit changes rebuild the visual with its current attachments. Existing VM serialization preserves the recorded appearance names.

A pack can provide a uniquely named appearance in CMX under `GameData/Skins`, `ExpansionShared/SkinsBuy` or `Downloads`, or in binary BCF under `Downloads`, with bindings to installed or pack-provided meshes/textures. FAR-contained CMX/BCF also participate in the engine lookup. Script references and animation events use the appearance name inside that container. Referenced meshes and textures must resolve. Missing appearances or dependencies produce resource diagnostics while preserving the valid body, head and other attachments. Both snapshots and animation exports include these diagnostics. Internal appearance, skeleton and animation names are validated against other winning pack containers and installed content before mounting.

Run `python3 tools/check_native_appearances.py`. It binds and exports 74 original appearances referenced by script string tables, checks simultaneous attachments, temporary-register suit selection, repeated dress, removal, bare names, outfit changes, missing-resource isolation and serialized VM save/load. It creates an isolated CMX pack with a new appearance name and original binding data, mounts it through the native loader and verifies native rendering. Offscreen controls compare the attachment lifecycle and streamed update against full snapshots at two resolutions. This proves new appearance identity and the shared attachment path; newly authored meshes, animation behavior, clothing catalogs and complete expansion compatibility remain unfinished.

## Avatar container identities

The loader reads text CMX version 300 and binary BCF to index internal `appearance`, `skeleton` and `animation` names. Each kind has its own namespace. Names compare without case sensitivity, matching the original provider lookup for the installed content. Pack reports expose `avatarResources` with kind, name, owning pack and full container path; FAR entries use `archive-path::entry-path`. Resource hashes already cover these definitions, so adding this report field does not change the fingerprint calculation.

Duplicate internal names within a supplied container, between winning pack containers or against installed original content are rejected. Replacing the same resource path through an explicit override replaces its definitions as one container; hidden earlier definitions do not participate. Original archives may contain repeated legacy definitions and are not rejected merely for those repetitions.

The engine searches loose CMX under GameData/Skins, ExpansionShared/SkinsBuy and Downloads; loose BCF/CFP must be under Downloads. CMX/BCF/CFP inside FAR archives are included. Files containing `globals` in their basename are excluded by the provider and cannot supply these pack resources. Two supplied containers cannot share the same case-insensitive filename under different paths, even if empty or containing different definitions.

An explicit loose replacement can retain an archived container's filename. Replacing an installed loose container must use its original game-relative path, which prevents engine folder priority from silently ignoring a replacement under another directory. Replacing a FAR file replaces that container's definitions. A new container with an existing internal name does not become an override merely by listing its new path in the manifest.

Five native tests cover complete skeleton, binding and animation-property traversal in both encodings, grouped CMX numeric lines, BOM handling, truncation, invalid counts, duplicate names, lookup folders, filename aliases, pack dependencies, explicit replacements and original archives. The appearance integration additionally attempts duplicate pack names and reuse of an original appearance name, checks rejection before either mount exists, then mounts the valid custom appearance and exercises the original/native attachment path. Missing referenced meshes/textures are reported during native export; full author-time dependency validation, CFP curve validation, migrations and a finished authoring SDK remain required work.

## Compile custom animations

The offline compiler converts a JSON animation document into an ordinary content pack with one BCF or CMX container and a CFP curve file for each clip. It does not initialize the game. Build the simulation project first, then compile the example into a new directory:

```sh
dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll --compile-animation examples/animation-pack.json packs/local.example-animation runtime/game
```

The destination must not exist. The compiler validates the document before writing resources, stages the complete pack and renames it into place. Enable the generated pack through the existing pack loader. Internal animation identities and filename conflicts use the same validation as other packs. The example is a two-frame ROOT motion to demonstrate the source format, not a complete gameplay interaction.

Source documents use schema version 1, a pack ID, optional display name and version, an `encoding` of `bcf` or `cmx`, and an `animations` array. Each clip has a unique `name`, `frames` and bone `tracks`. Translation samples contain X/Y/Z values; rotation samples contain unit quaternions in X/Y/Z/W order. Each supplied channel must contain one sample per frame. Channels are optional, allowing property-only tracks. Bone names must match the target skeleton exactly. An optional document-level `skeleton` names it (`adult`, `child`, `dog`, `kat` and `effects1` in a full install); without one each clip is fitted to the first installed skeleton, by name, that has all of its bones. The optional third argument is the installed game folder: the compiler reads every skeleton from its BCF and CMX files, loose or in FAR archives, rejects bones the skeleton lacks and reports the fitted skeleton per clip. Without the game folder bones are not checked, and naming a skeleton is an error. Optional `moving` and `distance` fields populate original motion metadata.

Clip metadata uses the original 30-frame-per-second time base. Timed `events` have an integer millisecond `time` inside the clip duration and a string `properties` dictionary. Track `properties` is an array of dictionaries. SimAntics controls playback speed and consumes original property names such as `xevt`, `dress` and `undress`. The runtime sorts events chronologically and preserves consumed/pending events through save/load. An interaction can reference the internal clip name without `.anim` in its ANIM string table and execute the original Animate Sim primitive. See "Author custom objects" below for writing those behavior trees.

Unknown source fields, duplicate clip/bone names, invalid sample counts, nonfinite values, nonunit quaternions, out-of-range events and strings unrepresentable in the chosen container are rejected. BCF strings are ASCII and at most 255 characters; CMX strings can contain Unicode but cannot contain line breaks or NUL. The compiler does not create missing behavior dependencies.

The shared CFP codec now resets each of its seven channels, bounds repeat runs, uses the original repeat-count convention and rejects malformed values before assigning animation arrays. Encoded values retain a maximum per-channel error of approximately 0.001607. Run `python3 tools/check_native_animation_authoring.py` for both container formats, original curve sampling, custom playback through Animate Sim, chronological and reverse events, serialized save/load and streamed/full-scene pose comparisons. Its 20 offscreen Metal renders cover 1600×960 and 2400×1800. Where only SimsSDL is built (Linux), the 16 snapshot renders go through SDL's offscreen driver zoomed out and the streamed comparison is skipped. The test also compiles against the installed skeletons and rejects unknown bones and skeletons. This is headless integration coverage; live presentation remains unverified. The installed sample `k2o-cathouse-levelone-sit-look-back.anim` lacks resolvable curve data and is recorded separately from successfully decoded originals. Behavior trees that play a compiled clip can be written with the object compiler below.

## Author custom objects

The object compiler turns a JSON document into a content pack of new objects. Each object starts from an installed original object, gets its own GUIDs, catalog text and price, and can gain new SimAntics behaviors and interactions. Build the simulation project first, then compile the example:

```sh
dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll --compile-object examples/object-pack.json runtime/game packs/example.wishing-objects
```

The arguments are the source document, the game directory that holds the templates, and a new pack directory. The output is a `pack.json` with `files/Downloads/<pack id>/<file>.iff` for each object. Mount it through the pack loader like any other pack. The compiler validates everything before writing, stages the pack in a temporary directory, and moves it into place. It refuses an existing destination. On success it prints a JSON summary with each object's GUIDs, the BHAV ID assigned to each behavior, and the tree-table index of each interaction.

### Document

A document has `schemaVersion` 1, a `packID`, an optional `name` and `version`, and an `objects` array. Unknown fields are rejected everywhere. Each object has:

| Field | Meaning |
|---|---|
| `file` | IFF name inside the pack, without extension. It must be unique and must not reuse an original object filename (see the filename rules above). |
| `template` | An original object filename such as `flamingo.iff`, found loose or in a FAR archive under `GameData/Objects`. |
| `templateObject` | Required when the template file holds several objects: the GUID of the one to keep. The compiler keeps that object and its multi-tile parts, and removes the other definitions and the catalog strings only they used. The error lists the choices. |
| `guid` | GUID of the lead definition. Reserve it with `--reserve-object-guid`. |
| `tileGuids` | One GUID per further definition (multi-tile part), in chunk order. A count that does not match is rejected. |
| `catalogName`, `description` | Catalog strings 0 and 1, written to every language in the template. The lead definition's label becomes the catalog name. |
| `translations` | Text for other languages, keyed by language name; see "Translations" below. |
| `price` | 0 to 65535. |
| `recolor` | Shifts the template's colors; see "Recolors" below. |
| `sprites` | Repainted sprite frames; see "Painted sprites" below. |
| `fields` | Other OBJD fields by name, such as `RatingFun` or `NumAttributes`. GUID, price, tree table, catalog strings, master and sub-index fields cannot be set. |
| `behaviors` | New BHAVs, described below. |
| `interactions` | New pie-menu entries, appended to the template's own unless `replaceInteractions` is true. |

All GUIDs in a document must be different. Load-time collision checks against installed content and other packs still apply.

### Behaviors

A behavior has a `name` (unique, at most 60 characters), `args` (0 to 4), `locals` (0 to 255) and 1 to 253 `instructions`. Behaviors get free private BHAV IDs after the template's own. Each instruction uses exactly one of three forms:

- `primitive` with an `operand` object. Use the engine's primitive name, such as `expression`, `budget` or `animate sim`. Operand fields use the engine's operand model names in camelCase, with enums given by name. The compiler encodes the operand, reads it back and rejects any value that does not survive encoding. An unknown field is rejected, and the error lists the valid ones.
- `call` with up to four short `args`. The target is one of this object's behaviors by name, or a BHAV ID: global from 0x100, private from 0x1000 (it must exist in the template or the document) or semi-global from 0x2000.
- `opcode` with `operandHex` (at most eight bytes), for installed primitives without an operand model.

An instruction may have a `label`. Its `true` and `false` branches can name a label, an instruction index, `next`, `true`, `false` or `error`. A missing `true` branch goes to the next instruction, or returns true after the last one. A missing `false` branch is an error, so give every instruction that can fail an explicit `false`.

The primitives run with the original scopes. In an interaction, `My…` scopes refer to the Sim running it and `StackObject…` scopes refer to the object. Object attributes grow on demand and are saved. Raise `NumAttributes` when a behavior keeps state in them.

### Recolors

`recolor` takes `hue` (degrees added, -360 to 360), `saturation` and `lightness` multipliers (0 to 4, default 1), an optional `hueRange` of two angles that limits the change to those hues (the range may wrap through 0) and a `minimumSaturation` (0 to 1) that leaves grays, whites and wood alone. It rewrites every PALT palette in the file. Sprites index into these palettes, so shading, transparency and depth stay exact. It also recolors the lead's catalog icon, keeping pure magenta, the client's transparent key, and never producing it. The summary reports how many palette and icon colors changed. Templates differ in how their colors are split across palettes; use `hueRange` to keep a color that should not change, such as the buy-mode icon's teal background.

### Translations

`translations` maps a language name (`EnglishUK`, `French`, `German`, `Italian`, `Spanish`, `Dutch`, `Danish`, `Swedish`, `Norwegian`, `Finish`, `Hebrew`, `Russian`, `Portuguese`, `Japanese`, `Polish`, `SimplifiedChinese`, `TraditionalChinese`, `Thai`, `Korean`; the engine's spelling) to an optional `catalogName`, `description` and `interactions`, which maps an interaction's document name to its pie-menu text. The default text goes to every language first, so a language without a translation shows the document's text rather than the template's original. A language the template lacks starts as a copy of the default strings. Object strings are one byte per character, so text must stay within Latin-1; the compiler rejects other characters instead of writing `?`. The host shows a language with `--language CODE` (French is 3).

### Painted sprites

Export a template's artwork, paint it, and list the painted frames in `sprites`:

```sh
dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll --export-object-sprites flamingo.iff runtime/game art
```

The export writes each SPR2 frame as `<template>-<sprite>-<frame>.png` (RGBA) and `<template>-<sprite>-<frame>-depth.png` (grayscale depth, 0 nearest and 255 empty). Its `sprites.json` lists every frame with its size and the draw groups, directions (1, 4, 16, 64) and zooms (1 far to 3 near) that draw it, plus each object's GUID and draw-group range. The output directory must be new or empty. Exported art comes from the game, so keep it out of the repository.

Each `sprites` entry has `sprite` (the SPR2 ID), `frame`, `image` and an optional `depth`, with paths relative to the document's directory. A path outside that directory is rejected. A painted image must have the original frame's size, because draw groups place frames by fixed offsets. Fully transparent pixels stay empty and partly transparent pixels keep their alpha. Without a depth image, pixels take the depth of the nearest originally visible pixel, so small touch-ups and outlines sort correctly. For a new shape, edit the exported depth image too.

TS1 sprites share one palette per SPR2 chunk, so the compiler re-quantizes every frame of an edited chunk together into a new 255-color palette and leaves the original palette to any other chunk. Unchanged frames come back exactly while the chunk needs no more than 255 colors. Recolors apply after painting. The summary lists each painted sprite, its frames and its new palette ID.

### Interactions

An interaction has a `name` (the pie-menu text), an `action` and an optional `test` behavior. Both are given by name or BHAV ID. It also takes an `autonomyThreshold` and `advertisements` keyed by motive name (`Fun`, `Hunger`, …) with `min`, `max` and `personality`. The flags `allowVisitors`, `allowChildren` and `allowAdults` default to true. `joinable`, `runImmediately` and `debug` default to false. A template without a tree table gets a new one, shared by all its definitions.

### Example and test

`examples/object-pack.json` has two objects:

- **Wishing Flamingo:** built from the flamingo, recolored from pink to blue and translated into French. Its "Make a Wish" interaction is offered once per flamingo: the test behavior checks the flamingo's attribute 0, and the action adds §7, sets the Sim's Fun to 100 and marks the attribute.
- **Banquet Table:** built from the cheapest of the four-part dining tables in `DiningTables.iff`. It has five new GUIDs, its own tree table and a "Knock on Wood" interaction that adds §1, with German text.

Run `python3 tools/check_native_object_authoring.py` to test the compiler. It needs SimsSDL or SimsNative built in release, and Pillow.

1. It compiles the example. Twelve malformed documents must fail before any pack directory exists: an unknown primitive, an unknown operand field, an operand overflow, an unknown label, an unknown behavior, a tile count mismatch, an ambiguous template, a duplicate GUID and a protected field. An unknown language, a translation of an unknown interaction and text outside Latin-1 must fail too. The compiled flamingo must keep the template's accented strings in other languages.
2. It exports the flamingo's sprites into the test session and paints the top third of every frame green, one pixel wider than the original outline, then compiles a second pack with this Painted Flamingo. A wrong frame size, a path outside the document directory, a missing sprite and a missing frame must be rejected.
3. It mounts the packs and checks the buy-mode catalog names, descriptions, icons and prices. The recolored icon must have no pink pixels left, and every pixel it changed must be in the recolor's hue range.
4. It buys the flamingo, an original one and the painted one. The exported scene sprites must show the pink pixels turned blue. The painted flamingo's drawn textures must have the painted coverage and colors, green where it was painted. It then runs the wish, checking the budget and that the menu hides the used wish.
5. It buys the table, checking that all four parts appear and that the price is paid once, then runs "Knock on Wood" and saves.
6. A new host loads the save and checks the GUIDs, the budget, both menus and the used wish. It then sells one table part and checks that the whole table goes with a refund.
7. A host started in French must show the flamingo's French name, description and pie-menu entry, and the document's default name for the untranslated Painted Flamingo.

Results are in `logs/native-object-authoring-result.json`.

Painted sprites keep their template's frame sizes and draw groups, so a new object needs a template of roughly its shape. The compiler does not author new draw groups or meshes. It also does not author new string tables beyond the catalog and interaction names, or new animation tables.


## Author custom outfits

The outfit compiler turns a JSON document into a pack of new clothing. Each outfit starts from an installed outfit (its template), keeps the template's meshes and bone bindings, and gets its own name and body textures. Create-A-Sim and the wardrobe read the same outfit collections, by name, so a compiled outfit appears in both for every skin tone it has a texture for. Build the simulation project first, then compile the example:

```sh
dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll --compile-outfit examples/outfit-pack.json runtime/game packs/example.teal-jeans
```

The arguments are the source document, the game directory that holds the templates, and a new pack directory. The compiler validates everything before writing, stages the pack and moves it into place, and refuses an existing destination. It prints a JSON summary of each outfit's name, meshes and textures.

TS1 names outfits `<collection><number><body type>_<suffix>`, for example `b002mafit_01`: collection `b` (the everyday clothes Create-A-Sim offers; `f` formal, `s` swimwear, `l` sleepwear, `w` winter and `h` high-fashion are the other wardrobes), a three-digit number, a body type such as `mafit` (male adult fit) or `fcchd` (female child), and a suffix. Its body textures are `<collection><number><body type><tone>_<anything>`, for tones `lgt`, `med` and `drk`. The compiler writes `GameData/Skins/<name>.cmx` and one BMP per tone into the pack.

A document has `schemaVersion` 1, a `packID`, an optional `name` and `version`, and an `outfits` array. Unknown fields are rejected. Each outfit has:

| Field | Meaning |
|---|---|
| `template` | An installed outfit name such as `b002mafit_01`, loose or in a FAR archive. Its body type carries over. |
| `number` | 0 to 999. No installed appearance or texture may already use this collection, number and body type, and two outfits in one document may not share one. |
| `suffix` | 1 to 32 letters or digits. |
| `collection` | Optional; defaults to the template's. |
| `recolor` | The object compiler's recolor (see "Recolors" above), applied to each template texture. Use `hueRange` and `minimumSaturation` to change the clothes and keep the skin. A recolor that changes no colors is an error. |
| `textures` | Painted textures keyed by tone (`lgt`, `med`, `drk`), PNG paths relative to the document. A painted tone replaces the template texture; the recolor still applies to it. |
| `meshes` | Reshaped body meshes keyed by the template mesh they replace (such as `xskin-b002mafit_01-PELVIS-BODY`), OBJ paths relative to the document. See "Reshape an outfit" below. |

Give a `recolor`, `textures`, `meshes` or a combination. An outfit with only meshes keeps the template's textures under its new name. Tones without a painted texture are recolored from the template's texture for that tone. Hand textures with the template's suffix are copied under the new suffix.

To paint an outfit, export its template textures:

```sh
dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll --export-outfit-textures b002mafit_01 runtime/game art
```

This writes `lgt.png`, `med.png` and `drk.png` (the UV layout the meshes expect) and a starting `outfit.json` that uses them. Painted textures may be any size up to 1024×1024; keep the layout. Exported art comes from the game, so keep it out of the repository.

`examples/outfit-pack.json` turns the jeans of two casual outfits teal. Run `python3 tools/check_native_outfit_authoring.py` to test the compiler. It needs SimsSDL or SimsNative built in release, and Pillow. It compiles the example, a painted outfit made from exported textures, and two reshaped outfits from an exported body mesh (one unchanged, one with widened legs), checks that the recolor changed only pixels in its hue range and that the painting arrives pixel for pixel, mounts both packs, checks that Create-A-Sim offers each outfit for every tone with its new texture, checks that the engine's appearance preview wears the compiled texture, and checks that the unchanged mesh previews exactly like the template while the reshaped one does not. It then checks that eighteen invalid documents are refused before any pack exists, among them a taken number, an unknown template, a bad suffix or tone, a painting outside the document directory, a recolor that changes nothing, an unknown mesh, an OBJ without texture coordinates or with an unsupported line or index, and a mesh moved too far from the body. Results are in `logs/native-outfit-authoring-result.json`.

`python3 tools/check_native_wardrobe.py` checks a compiled outfit in play. It compiles the example, mounts it, and starts the simulation host on House 5 of a fresh profile. Mortimer buys Dresser - Cheap and uses Change Clothes. The check passes when the wardrobe lists `b950mafit_teal`, choosing it re-dresses him at once (as in the original, the dresser sets the everyday outfit and the Sim walks away wearing it), and a second host started on the saved lot shows him still wearing it. Results are in `logs/native-wardrobe-result.json`.

### Reshape an outfit

To change the shape of an outfit, export its body meshes:

```sh
dotnet native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll --export-outfit-mesh b002mafit_01 runtime/game art
```

This writes one Wavefront OBJ per mesh, named after the mesh, with the Sim standing in the skeleton's rest pose (Y up, about 3 units tall for an adult), texture coordinates for the outfit's textures and normals. It prints the meshes with their vertex and triangle counts and the bones they follow. Edit the OBJ in any modeler, keeping its position and scale, and list it under `meshes`.

TS1 meshes are skinned: each vertex follows one bone, and vertices near joints also blend toward a second bone. An OBJ carries no bones, so the compiler gives each vertex the bone, blend bone and weight of the nearest vertex of the template mesh (texture coordinates break ties along seams) and converts it into those bones' spaces. In the rest pose the compiled mesh is exactly the OBJ; when the Sim moves, each part follows the part of the original it is closest to. Reshape, add or remove vertices freely, but keep each part near the original body part that should carry it: a vertex more than 1.5 units from every template vertex is refused.

The importer reads `v`, `vt`, `vn` and `f` lines and ignores `o`, `g`, `s`, `mtllib`, `usemtl` and `l`; any other line is an error. Every face corner needs a texture coordinate; normals are optional and computed smooth where missing. Polygons are split into triangles, and negative indices count from the end. A mesh may have up to 30,000 vertices and 60,000 triangles. The compiled mesh is `GameData/Skins/xskin-<new outfit name>-<part>.skn`, and the new appearance binds it in place of the template mesh.

The compiler does not author heads, new bones or skeleton bindings beyond the template's.

## Gameplay plugins, panels and save migration

This contract is implemented. `SimsSimulation.dll --check-plugins [plugin folder]` exercises it without game files, using the example plugin. It covers trust and digest gating, load, ticks, panel actions, save, version migration, saved-state validation and failure isolation. `python3 tools/check_native_plugins.py` drives the same plugin on a running lot (House 5) through SimsNative or SimsSDL; set `SIMS_GAME_DIR` to the game directory.

A manifest can add three optional fields:

```json
"plugin": { "assembly": "plugin/MyPack.dll", "entryType": "My.Namespace.Entry", "apiVersion": 1, "stateVersion": 1 },
"panels": ["panels/status.json"],
"saveMigration": { "from": ["0.1.0"] }
```

`plugin/` and `panels/` sit next to `files/`. A code-only pack still needs a `files` directory. The assembly references `native/SimsPluginApi` (namespace `SimsNative.Plugins`, contract version 2) without copying it. The entry type implements `ISimsPlugin`; all calls run on the simulation thread. `IPluginContext` offers clock, pause state, funds, household Sims and motives, validated `TryCharge`/`TryPay`, up to 256 small namespaced values that persist automatically, and `SetPanelValue` for the pack's declared panels. A plugin that throws is disabled for the session.

The host loads `apiVersion` 1 and 2. Version 2 adds lot calls to `IPluginSimulation`:

| Member | Meaning |
|---|---|
| `Objects` | Every object on the lot, Sims included: object ID, GUID, name, tile, level and the lead object of its multi-tile group. |
| `GetInteractions(sim, object)` | The pie menu a household Sim is offered on an object right now. |
| `TryQueueInteraction(sim, object, id, param0, global)` | Queues an entry of that menu as if the player picked it. It fails without a change while a blocking dialog is open or when the entry is not offered. |
| `GetQueuedActions(sim)` | The names in a household Sim's action queue, the running one first. |
| `ChangeMotive(sim, motive, delta)` | Changes a need (energy 5, comfort 6, hunger 7, hygiene 8, bladder 9, social 14, fun 15) by up to 100 either way, clamped to -100 through 100, and returns the new value. |

Version 2 plugins can also override `ISimsPlugin.ScoreAutonomy(choice, score)`. When any Sim on the lot chooses for itself, each interaction it may pick passes through every loaded plugin that overrides it, in load order. `PluginAutonomyChoice` names the Sim, whether it belongs to the household, the object and its GUID, and the interaction's ID and name. The returned score must be a finite number; it is clamped to 0 through 1,000,000, and a score of 0 removes the choice. The engine then picks among the four best as before. A plugin whose scorer throws or returns NaN is disabled like any other failure.

Only household Sims can be directed. A version 1 plugin that reaches a version 2 member gets `NotSupportedException` and is disabled.

Plugins never run without an explicit local trust action. The trust digest is SHA-256 over `name:sha256` lines for every `.dll`/`.json` file in the plugin folder. Trust is recorded per pack ID, version and digest in `DATA_ROOT/Settings/plugin-trust.json`. Grant or revoke it with `--trust-plugin PACK_ID` or `--revoke-plugin PACK_ID`, and list states with `--list-plugins`. The app also asks once per launch for each untrusted plugin; "Keep Disabled" is the default. SimsSDL takes the same pack flags (with `--packs DIR`) and asks with a message box; `--answer-dialogs` skips the question and keeps plugins disabled. Content mounts copy the plugin folder into `.native-plugins/PACK_ID/`. The simulation re-hashes that copy, checks the trust store and loads it in its own collectible `AssemblyLoadContext`. Plugin and panel digests join the save fingerprint only when present, so packs without them keep their earlier fingerprints.

Panels are declarative JSON (`schemaVersion` 1): an `id`, `title`, 800×600 logical `frame` and up to 64 `label`, `button`, `meter`, `image` and `list` elements. Elements sit below a 36-point title band and above a 44-point close band. Buttons send `action` names to `OnPanelAction`; other elements read `binding` values. Swift draws panels with the original dialog frame, list tile, WinBtn sheet, slider art and bitmap font. Panels appear at the end of the Simulation menu; in SimsSDL the E key cycles through them.

Plugin state is saved under the pack ID with the manifest `stateVersion`. A save from a newer state version is rejected, and older state is passed to `LoadState` for migration. See `docs/RUNTIME_PROTOCOL.md` for save backups and pack-version migration. `examples/plugin-pack` with `native/SimsExamplePlugin` (staged by `tools/build_example_plugin.command`) is a daily allowance system with a panel and a state migration from version 1. Its Chore button sends an adult to the first chore the lot's pie menus offer (watering flowers, bringing in the paper and similar), its Coffee button raises that adult's energy by 20, and its Tidy button makes household Sims rate chores fifty times higher when they choose for themselves, with a count of how often chores were among their options.

## Uninstalling a pack

Removing a pack from the collection never changes a save on its own. A save that records a pack which is no longer enabled is refused, and the `load` response names every missing pack in `missingPacks`. The clients then ask the player whether to load anyway; only that explicit choice (`load` with `removePacks: true`) continues:

- The slot is backed up first, so reinstalling the pack and restoring the backup brings the old lot back.
- Every object whose definition no longer resolves is removed with the rest of its multi-tile group and anything it holds. Each removed group is refunded to the household at its sale value (purchase price less wear). A Sim held by a removed object is detached, never removed.
- Sims and objects whose threads ran code from a removed definition, or referred to a removed object, are reset, as the engine does after a SimAntics error. Dialogs raised by or about them are dropped.
- The removed pack's plugin state is discarded. Floors and walls from the pack fall back as the engine does for any missing floor or wall.
- The `saveMigrated` event lists the removed packs, the removed objects with their refunds, the total refund and the number of reset objects.

The next save no longer records the pack, so it loads without the question. `python3 tools/check_native_pack_removal.py` checks this on House 5: it buys a pack object, queues a Sim on it, saves, and loads the save on content without the pack. Results are in `logs/native-pack-removal-result.json`. `SimsSimulation.dll --check-save-compat` covers the same rules on a synthetic snapshot without game files.
