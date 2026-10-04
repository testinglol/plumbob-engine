# Native macOS parity workplan

This plan covers the PC Complete Collection and its seven official expansions. The native app keeps the original Sims 1 interface and behavior, uses the installed game files as its content source, and stores ongoing play in a separate native profile. The Swift/AppKit/Metal client and .NET SimAntics host remain connected through the versioned runtime protocol.

Work proceeds serially. Each gate is closed before the next one becomes the main implementation target. A successful build or resource mount alone does not close a player-facing flow. Validation uses builds, scripted protocol/simulation scenarios, offscreen renders, and offline audio checks; the original game is not launched for manual play. Detailed evidence and current verification live in [PARITY_LEDGER.md](PARITY_LEDGER.md).

## Gate order

| Gate | Complete player flow | Exit condition |
| --- | --- | --- |
| 0. Baseline and known defects | Stable source/content baseline; reproducible reports for neighborhood visibility and world placement alignment | Build all native targets; export each available neighborhood mode; keep source `UserData` unchanged; record the observed coordinates, hit targets, and render evidence for the two reported display defects. |
| 1. Start a household | Launch, choose/import a neighborhood household or start a new one, create Sims, choose a home, enter the lot, save, quit, and reload | Script the whole path through native UI/protocol boundaries. Verify language selection, original family/CAS screens and controls, adult requirement, appearance choices and preview, household placement/funds, profile recovery, save/load, and unchanged installed files. |
| 2. Base-game live simulation | Play a household over time and complete ordinary daily routines | Headless scenarios cover time/speed/pause, autonomy, motives, interactions and outcomes, visitors, relationships, skills, careers, household membership, inventory, object state, lot changes, and persistence. Every reachable base-game command is implemented or tied to evidence that the original game disallows it. |
| 3. Lot presentation and construction | Navigate, view, build, buy, place, move, and sell on a residential lot | Fix world coordinate/anchor and hit-test agreement, including flat ground; verify sprites, depth, walls/cutaways, levels, roofs, lighting/shadows, water, terrain, and animation. Exercise architecture and object transactions, undo/redo, budgets, save/load, and UI scaling. |
| 4. Original frontend and audio | Use the remaining everyday screens and hear the correct transitions and feedback | Reconstruct the original UI assets, states, input, and navigation for live panels, dialogs, phone, relationships, careers, options, build/buy, and special panels. Check music, ambience, effects, voices, and UI sounds for enable/disable, volume, transition, and offline decoding. |
| 5. Official expansions | Play and save expansion-specific content in release order | Close one pack's objects, scripts, careers/activities, panels, neighborhood/travel routes, sounds, and save compatibility before advancing to the next pack. Pets receive their own full lifecycle gate under Unleashed. |
| 6. Custom expansion SDK | Install and play a custom pack that adds content and a new system | Validate a versioned pack with assets, scripts, objects, sounds, and a new neighborhood; require explicit trust before loading C# gameplay code; render versioned declarative panel data in the original visual style; migrate namespaced save data across supported versions. |
| 7. Package and release | Install and run the native app on a supported Apple Silicon Mac | Produce a repeatable macOS 14+ bundle; verify runtime dependencies, game-data selection, locale fallback, user-profile isolation, backups, upgrade behavior, and that the app bundle contains no EA assets. Publish the versioned pack/plugin API documentation. |

## Player-facing flow inventory

These flows are the scope checklist for the gates above. A flow remains partial until both its behavior and its player-facing path are covered.

### Startup, neighborhood, and household

- Find or select the installed Complete Collection, identify its language from its own resources, and explain missing or mixed-language resources without falling back silently.
- Create or recover the separate native profile; keep source installation files read-only from the native app's perspective.
- Show the original neighborhood art, occupancy/zoning, lot prices, available lots, and each installed neighborhood mode. Select occupied lots, vacant lots, community destinations, and travel destinations with the correct original restrictions.
- Import an existing original household and its neighborhood/lot state; preserve the original save. Support explicit source choice, interrupted-copy recovery, and repeat imports without corrupting the profile.
- Build and edit a family in the original family UI. Create adult and child Sims with original name, biography, personality, zodiac, gender, skin, head, clothing, and preview controls. Enforce valid household composition and lot affordability.
- Move in, enter the selected lot, save, reload, leave and return from travel, and recover from a failed or interrupted save. Confirm household, Sim, lot, and expansion state survive each transition.

### Everyday simulation and lot tools

- Run the simulation at the original speeds and pause behavior; verify clock progression, motives, autonomy, queueing, cancellation, visitors, and day/night transitions.
- Exercise interactions from pie menus through completion, failure, cancellation, and resulting motive, relationship, skill, career, inventory, object, and household changes.
- Cover routing, collision, doors, stairs, multi-tile objects, room/comfort calculations, placement validation, transactions, and lot entry/exit. Compare exported object/sim anchors with clicks, footprints, and sprites on flat ground and across elevations.
- Cover buy/build catalogs, category and page navigation, selection, placement, rotation, move, sale, architecture editing, refunds, budget limits, undo/redo, and blocked actions.
- Verify live panels and specialized screens read the same state the simulation saves, and that UI commands cannot bypass engine validation.

### UI, graphics, accessibility, and sound

- Keep original artwork, hierarchy, text treatment, and behavior. Do not substitute Simitone's redesigned UI. Rebuild screens with original assets and evidence rather than approximating final placement from names alone.
- Preserve an 800×600 logical interface, letterbox where required, and keep controls and hit targets aligned at Retina and wide drawable sizes.
- Cover windows, overlays, dialogs, focus, keyboard/mouse/controller navigation, accessibility labels, localized text, and sound feedback for every screen.
- Validate terrain, sprites, meshes, depth, sorting, wall modes, roofs, room lighting, shadows, water, cutaways, camera transforms, and animated avatars/objects. Maintain a fixture for known flat-ground placement alignment.
- Decode and route original music, ambience, effects, voices, and UI feedback through one documented owner/lifecycle. Verify options, volume, transitions, and save/load where audio state is persisted.

### Pets and expansion packs

For every pack, use the same completion checklist: resource discovery; original UI and controls; behavior trees/primitives and outcomes; object catalog and placement; activities/career/skills where present; neighborhood and travel routes; audio; save/load and compatibility with a household that also contains base-game content.

1. **Livin’ Large:** new objects and interactions, behavior changes, catalogs, and persistence.
2. **House Party:** party systems, guest behavior, objects, scoring/outcomes, UI, sounds, and persistence.
3. **Hot Date:** Downtown travel, date/social behavior, lots, objects, UI, sounds, and return-home state.
4. **Vacation:** vacation travel and destinations, lodging/activities, inventory/trip state, UI, sounds, and return-home recovery.
5. **Unleashed:** Old Town and outdoor content, cats and dogs, pet creation/import, pet needs and care, autonomy/interactions, household limits, UI, sounds, and save/load.
6. **Superstar:** Studio Town travel, fame/career progression, activities, objects, panels, sounds, and persistence.
7. **Makin’ Magic:** Magic Town travel, magic skills/duels/spells, charms and ingredients, objects, special screens, sounds, and persistence.

Pets are not complete when their records load: creation/selection, ownership, needs, care, autonomy, interaction, visual presentation, and save/load must all pass.

### Custom content and release

- Keep existing asset-pack validation and extend it with a documented, versioned manifest for scripts, objects, sounds, and additional neighborhood data.
- Separate data-only packs from code-bearing gameplay plugins. Require an explicit per-plugin local trust action before executing C# code; validate API and pack versions before loading.
- Give plugins a constrained, versioned simulation API and a declarative panel schema. The Swift client owns rendering and draws panels using original-style primitives/assets.
- Namespace pack save data, include pack/plugin versions in save compatibility, and test forward migration, missing packs, rejected versions, and rollback to a backup.
- Ship only the native client/runtime and original-game-independent tooling. Read licensed assets from the player's installation and document installation, import, profile location, backup, and removal behavior.

## Rules for closing a gate

- Link each result to its original resource/decompilation evidence and to the check that exercises it.
- Test the whole path, including player-facing input, state change, failure/cancel behavior, and save/load where applicable.
- Keep known gaps visible in the parity ledger. Do not describe asset presence, an export, or a successful build as functional parity.
- Do not begin expansion or SDK work to avoid unresolved base-game behavior. Record evidence-based exceptions when the original game intentionally omits a feature.
