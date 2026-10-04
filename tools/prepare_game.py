import argparse
import json
from pathlib import Path
import shutil
import subprocess
import tempfile


ROOT = Path(__file__).resolve().parents[1]
GROUPS = {
    "SIMS_EXE": ".",
    "Debug_Support": ".",
    "GameData_ALL_Recursive": "GameData",
    "GameData_ALL_Ranger": "GameData",
    "SoundData_SimsSounds": "SoundData",
    "Music_ALL_Recursive": "Music",
    "UIGraphics": "UIGraphics",
    "Downloads": "Downloads",
    "ExpansionShared": "ExpansionShared",
    "ExpansionPackGOLD": "ExpansionPackGOLD",
    "UserData": "UserData",
    "UserData2": "UserData2",
    "TemplateUserData": "TemplateUserData",
    "TemplateDowntown": "TemplateDowntown",
    "TemplateVacation": "TemplateVacation",
    "TemplateCommunity": "TemplateCommunity",
    "TemplateStudiotown": "TemplateStudiotown",
    "TemplateMagicTown": "TemplateMagicTown",
    "TemplateFamilyUnleashed": "TemplateFamilyUnleashed",
    "TemplateNPCs": "TemplateNPCs",
    **{f"ExpansionPack{i}": f"ExpansionPack{i}" for i in range(1, 8)},
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--media", type=Path, default=Path("/Volumes/The Sims 1"))
    args = parser.parse_args()
    destination = ROOT / "runtime/game"
    marker = destination / ".prepared.json"
    if marker.exists():
        print(f"Already prepared: {destination}")
        return
    if destination.exists() and any(destination.iterdir()):
        raise SystemExit("Game directory is nonempty without a completed preparation marker.")
    unshield = ROOT / "tools/unshield/build/src/unshield"
    cabinet = args.media / "Setup/data1.cab"
    if not cabinet.is_file() or not unshield.is_file():
        raise SystemExit("Mount the game ISO and build tools/unshield first.")
    destination.mkdir(parents=True, exist_ok=True)
    manifest = []
    with (ROOT / "logs/preparation.log").open("w") as log:
        for group, relative in GROUPS.items():
            with tempfile.TemporaryDirectory(prefix="sims-extract-") as temporary:
                subprocess.run(
                    [str(unshield), "-R", "-g", group, "-d", temporary, "x", str(cabinet)],
                    check=True, stdout=log, stderr=log,
                )
                source = Path(temporary) / group
                for path in source.rglob("*"):
                    if path.is_file():
                        target = destination / relative / path.relative_to(source)
                        target.parent.mkdir(parents=True, exist_ok=True)
                        shutil.move(str(path), target)
                        manifest.append(str(target.relative_to(destination)))
            print(f"Prepared {group}", flush=True)
    executable = args.media / "The Sims Crack/Sims.exe"
    shutil.copy2(destination / "Sims.exe", ROOT / "analysis/Sims.disc.exe")
    shutil.copy2(executable, destination / "Sims.exe")
    shutil.copy2(executable, ROOT / "analysis/Sims.original.exe")
    marker.write_text(json.dumps({"files": manifest, "media": str(args.media)}, indent=2))
    print(f"Prepared {len(manifest)} files in {destination}")


if __name__ == "__main__":
    main()
