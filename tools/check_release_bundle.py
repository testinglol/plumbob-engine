#!/usr/bin/env python3
"""Verifies a Sims Native release bundle.

Checks the manifest, Apple Silicon architecture, the self-contained simulation host layout and that no file in the
bundle is a copy of a file from an installed game. Pass each game folder with --game (repeatable).
"""
import argparse
import hashlib
import json
import plistlib
import subprocess
import sys
from pathlib import Path

GAME_EXTENSIONS = {".far", ".iff", ".hit", ".hsm", ".hot", ".xa", ".skn", ".bcf", ".cmx", ".cfp", ".flr", ".wll", ".tds", ".ranger"}


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("bundle", type=Path)
    parser.add_argument("--game", action="append", default=[], type=Path)
    args = parser.parse_args()
    bundle = args.bundle.resolve()
    problems: list[str] = []
    report: dict[str, object] = {"bundle": str(bundle)}

    plist_path = bundle / "Contents/Info.plist"
    if not plist_path.exists():
        problems.append("Info.plist is missing")
    else:
        info = plistlib.loads(plist_path.read_bytes())
        report["version"] = info.get("CFBundleShortVersionString")
        if info.get("LSMinimumSystemVersion") != "14.0":
            problems.append("LSMinimumSystemVersion must be 14.0")
        if info.get("CFBundleExecutable") != "SimsNative":
            problems.append("CFBundleExecutable must be SimsNative")

    executable = bundle / "Contents/MacOS/SimsNative"
    host = bundle / "Contents/Resources/workspace/native/SimsSimulation/bin/Release/net9.0"
    for path in (executable, host / "SimsSimulation", host / "libhostfxr.dylib", host / "SimsSimulation.dll"):
        if not path.exists():
            problems.append(f"missing {path.relative_to(bundle)}")
    if not (bundle / "Contents/Resources/workspace/engine/Simitone/FreeSO/TSOClient/tso.content/Content").exists():
        problems.append("missing FreeSO runtime content")

    for path in (executable, host / "SimsSimulation"):
        if path.exists():
            description = subprocess.run(["file", str(path)], capture_output=True, text=True).stdout
            if "arm64" not in description:
                problems.append(f"{path.name} is not arm64: {description.strip()}")
    if (host / "libhostfxr.dylib").exists() and not (host / "SimsSimulation.runtimeconfig.json").exists():
        problems.append("self-contained host has no runtimeconfig")

    source_hashes: dict[str, str] = {}
    for game in args.game:
        if not game.exists():
            continue
        for path in game.rglob("*"):
            if path.is_file() and not path.is_symlink() and path.stat().st_size > 0:
                source_hashes.setdefault(sha256(path), str(path))
    files = [path for path in bundle.rglob("*") if path.is_file() and not path.is_symlink()]
    copied = []
    for path in files:
        if path.suffix.lower() in GAME_EXTENSIONS:
            problems.append(f"game-format file in bundle: {path.relative_to(bundle)}")
        if path.stat().st_size > 0 and (digest := sha256(path)) in source_hashes:
            copied.append((str(path.relative_to(bundle)), source_hashes[digest]))
    for bundled, original in copied:
        problems.append(f"bundle file {bundled} is identical to installed game file {original}")
    report.update(files=len(files), gameFoldersScanned=len([g for g in args.game if g.exists()]), installedFileHashes=len(source_hashes),
                  identicalToInstalled=len(copied))
    report["result"] = "passed" if not problems else "failed"
    report["problems"] = problems
    print(json.dumps(report, indent=2))
    return 0 if not problems else 1


if __name__ == "__main__":
    sys.exit(main())
