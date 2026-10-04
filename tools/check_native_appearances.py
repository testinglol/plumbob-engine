import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import uuid

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
game = Path(os.environ.get("SIMS_TEST_GAME", root / "runtime/game"))
original = root / "runtime/game/UserData/Houses/House05.iff"
before = hashlib.sha256(original.read_bytes()).hexdigest()
process = subprocess.run([shutil.which("dotnet"), str(root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"),
                          str(game), str(root), "5", "0", "--check-appearances"],
                         env=os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")}, capture_output=True, text=True)
(root / "logs/native-appearance-runtime.log").write_text(process.stderr)
process.check_returncode()
report = json.loads(process.stdout)
assert hashlib.sha256(original.read_bytes()).hexdigest() == before
fixtures = report["appearances"]["fixtures"]
directory = root / "analysis/appearance-render-check" / uuid.uuid4().hex
directory.mkdir(parents=True, exist_ok=True)
renders = []
for width, height in [(1600, 960), (2400, 1800)]:
    images = {}
    for fixture in fixtures:
        output = directory / f"{fixture['name']}-{width}x{height}.png"
        subprocess.run([str(root / "native/SimsNative/.build/release/SimsNative"), "--game", str(game),
                        "--scene", fixture["scene"], "--width", str(width), "--height", str(height), "--render", str(output)],
                       check=True, capture_output=True, text=True)
        images[fixture["name"]] = Image.open(output).convert("RGB")
        renders.append(str(output))
    baseline = next(fixture for fixture in fixtures if fixture["name"] == "baseline")
    output = directory / f"streamed-bound-{width}x{height}.png"
    subprocess.run([str(root / "native/SimsNative/.build/release/SimsNative"), "--game", str(game),
                    "--scene", baseline["scene"], "--animation", report["appearances"]["boundAnimation"],
                    "--width", str(width), "--height", str(height), "--render", str(output)], check=True, capture_output=True, text=True)
    assert ImageChops.difference(images["bound"], Image.open(output).convert("RGB")).getbbox() is None, "Streamed attachment differs from full scene"
    renders.append(str(output))
    assert ImageChops.difference(images["baseline"], images["bound"]).getbbox(), "Bound appearance did not change rendered pixels"
    assert ImageChops.difference(images["baseline"], images["removed"]).getbbox() is None, "Removing attachment left stale pixels"
    assert ImageChops.difference(images["bound"], images["loaded"]).getbbox() is None, "Save/load changed appearance pixels"
    assert ImageChops.difference(images["bound"], images["missing"]).getbbox() is None, "Missing appearance damaged valid attachments or Sim"
    assert ImageChops.difference(images["bound"], images["swimwear"]).getbbox(), "Outfit change was not rendered"
    if "custom" in images:
        assert ImageChops.difference(images["bound"], images["custom"]).getbbox() is None, "Pack appearance with identical bindings rendered differently"
report["baseLotUnchanged"] = True
report["renders"] = renders
report["appearancePixelsVerified"] = True
(root / "logs/native-appearance-result.json").write_text(json.dumps(report, indent=2))
if not os.environ.get("SIMS_APPEARANCE_CUSTOM"):
    session = root / "runtime/native-sessions" / ("custom-appearance-" + uuid.uuid4().hex)
    packs = session / "packs"
    pack = packs / "local.appearance-check"
    asset = pack / "files/GameData/Skins/native-attachment-check.cmx"
    asset.parent.mkdir(parents=True)
    shutil.copyfile(report["appearances"]["customFile"], asset)
    manifest = {"schemaVersion": 1, "id": "local.appearance-check", "name": "Native appearance fixture",
                "version": "0.1.0", "baseGameVersion": "1.90", "dependencies": [], "overrides": []}
    (pack / "pack.json").write_text(json.dumps(manifest, indent=2))
    binary = root / "native/SimsNative/.build/release/SimsNative"
    arguments = [str(binary), "--game", str(root / "runtime/game"), "--packs", str(packs)]
    pack_report = json.loads(subprocess.check_output(arguments + ["--pack-report"], text=True))
    assert pack_report["resources"][0]["owner"] == "local.appearance-check"
    assert pack_report["avatarResources"] == [{"kind": "appearance", "name": "native-attachment-check",
                                              "path": "gamedata/skins/native-attachment-check.cmx", "owner": "local.appearance-check"}]
    duplicate = packs / "local.appearance-conflict"
    duplicate_asset = duplicate / "files/GameData/Skins/different-container.cmx"
    duplicate_asset.parent.mkdir(parents=True)
    duplicate_asset.write_bytes(asset.read_bytes())
    duplicate_manifest = manifest | {"id": "local.appearance-conflict"}
    (duplicate / "pack.json").write_text(json.dumps(duplicate_manifest))
    rejected_mount = session / "conflict-game"
    failure = subprocess.run(arguments + ["--mount", str(rejected_mount)], capture_output=True, text=True)
    assert failure.returncode != 0 and "appearance:native-attachment-check" in failure.stderr and not rejected_mount.exists()
    shutil.rmtree(duplicate)
    original_asset = asset.read_bytes()
    assert original_asset.count(b"native-attachment-check") == 1
    asset.write_bytes(original_asset.replace(b"native-attachment-check", report["appearances"]["name"].removesuffix(".apr").encode()))
    rejected_base_mount = session / "base-conflict-game"
    failure = subprocess.run(arguments + ["--mount", str(rejected_base_mount)], capture_output=True, text=True)
    assert failure.returncode != 0 and "appearance:" in failure.stderr and not rejected_base_mount.exists()
    asset.write_bytes(original_asset)
    mount = session / "game"
    subprocess.run(arguments + ["--mount", str(mount)], check=True, stdout=subprocess.DEVNULL)
    subprocess.run(["python3", str(Path(__file__))], env=os.environ | {"SIMS_TEST_GAME": str(mount), "SIMS_APPEARANCE_CUSTOM": "1"}, check=True, capture_output=True, text=True)
    custom_report = json.loads((root / "logs/native-appearance-result.json").read_text())
    assert custom_report["appearances"]["customAppearanceLoaded"]
    report["customPack"] = {"pack": str(pack), "fingerprint": pack_report["fingerprint"], "customAppearanceLoaded": True,
                            "renders": custom_report["renders"], "pixelParityWithOriginalBinding": True, "internalNameConflictRejectedBeforeMount": True,
                            "baseInternalNameConflictRejectedBeforeMount": True}
    (root / "logs/native-appearance-result.json").write_text(json.dumps(report, indent=2))
print(json.dumps({"result": report["result"], "appearance": report["appearances"]["name"],
                  "originalAppearanceChecks": report["appearances"]["originalAppearanceChecks"],
                  "checks": report["appearances"]["checks"], "renders": len(renders) + len(report.get("customPack", {}).get("renders", [])),
                  "customAppearanceLoaded": report["appearances"]["customAppearanceLoaded"] or "customPack" in report, "baseLotUnchanged": True}))
