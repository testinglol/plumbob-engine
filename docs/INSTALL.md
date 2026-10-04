# Installing, backing up and removing Sims Native

This describes the release bundle built by `tools/package_release.command`. It has not been built or run yet; the final gate verifies every statement below.

## Requirements

- An Apple Silicon Mac running macOS 14 or later. The bundle includes its own .NET runtime.
- A legitimate PC copy of The Sims Complete Collection. The app contains no Electronic Arts files; `tools/check_release_bundle.py` compares every bundled file's SHA-256 with the installed game and fails on a match or on game-format files.

## First launch

1. Open `Sims Native.app`. If macOS blocks it, use Control-click → Open once (the bundle is ad-hoc signed, not notarized).
2. Choose the installed game folder. It must contain `UIGraphics/UIGraphics.far` and `TemplateUserData/LotLocations.iff`. The choice is remembered. The game folder is read-only to the app.
3. The language comes from the installed `Sims.exe` resources. A missing or unsupported language falls back to English (US).

## Where things live

| Item | Location |
| --- | --- |
| Profiles, saves, sessions | `~/Library/Application Support/Sims Native/runtime/native-profiles` |
| Save backups | `<profile>/Saves/backups`, newest five per slot |
| Options (Play and Graphics) | `~/Library/Application Support/Sims Native/Settings/options.json` |
| Plugin trust | `~/Library/Application Support/Sims Native/Settings/plugin-trust.json` |
| Custom packs | `~/Library/Application Support/Sims Native/packs/<pack>/pack.json` |
| Game folder choice | the app's macOS preferences (`local.sims.native.gameInstallPath`) |

## Importing an original save

File → Import Original Save… copies the chosen game or `UserData` folder, including `UserData2` and later neighborhoods, into a new profile. The original files are never changed. Imports can be repeated; each creates its own profile.

## Backups and rollback

Every save keeps the previous file under `Saves/backups`. Loading a save after a pack version change makes another copy first. The `saveBackups` and `restoreBackup` protocol commands list and restore copies. To roll back by hand, replace `Saves/<slot>.json` with a file from `Saves/backups`.

## Upgrading

Replace the app bundle. Profiles and settings are outside the bundle and are kept. A save made by a newer engine is refused rather than loaded.

## Removing

Delete `Sims Native.app`. To remove all data too, delete `~/Library/Application Support/Sims Native` and the app's preferences (`defaults delete local.sims.native`). The installed game is untouched.
