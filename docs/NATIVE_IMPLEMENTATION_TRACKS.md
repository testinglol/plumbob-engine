# Native implementation tracks

The target is the complete native macOS game with its original UI. Extreme customization follows that foundation. Live presentation testing is deferred by request; implementation uses executable evidence, headless simulation checks and offscreen rendering.

Implementation proceeds serially in the active task. A registered primitive, successful build or static reference scan does not establish complete gameplay parity. The current scope and acceptance gates are recorded in `docs/PARITY_LEDGER.md`.

| Track | Current scope | Review requirement |
| --- | --- | --- |
| Script primitives | Tutorial, motive selection and UI effects; typed engine callbacks | Original operands, control flow and native callback handling |
| Script memory | TS1 scope reads/writes, neighbor records and index bounds | Original dispatch and real object-script regressions |
| Clock, needs and motives | Script-visible day/night phase, TS1 motive decay, sleep recovery and fixed-point state | Original outdoor daylight/dawn/dusk/night tuning (`analysis/full-decompilation/004666a9.c`) and motive update evidence (`00420fe9.c`); tests for phase boundaries, fractional carry, tuning, sleep and wake transitions |
| Autonomy | Dynamic action strings, motive-ad changes and per-choice scoring | Original TTAB/BHAV resources; variant-level checks plus `--check-autonomy` on an installed occupied lot |
| House status | Valuation, structural statistics and original rating formulas | Original data sources and formula provenance |
| Construction | Terrain editing, undo and architecture consistency | Canonical funds, room updates and save/load |
| Camera and geometry | Shared orientation transforms, picking and cutaway | Render/picking agreement across camera orientations |
| Neighborhood lifecycle | Original neighborhood/family screens and lot selection | Original resources and persistent family state |
| Audio | Ambience/FSC and original sound options | Canonical event scheduling and volume persistence |
| Gameplay lifecycle | Expansion controller behavior and character lifecycle | Original scripts, cross-lot state and complete record persistence |

The behavior audit (`--audit-behaviors`) scans all loaded object resources, globals and referenced semiglobals, including mounted custom content. It reports unregistered primitive references, unresolved routine references and resource failures. Unresolved references may be intentional or unreachable. Dynamic tree calls and registered handlers require separate behavioral review.

The persistence path preserves full modern 256-field neighbor records, legacy 80-field records and all 16 neighborhood record values. Neighborhood script access remains read-only and permits indices 1–15; record zero is preserved as opaque data. Headless save/load fixtures cover off-lot relationships, extended record fields and five expansion travel destinations.
