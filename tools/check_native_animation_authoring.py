import hashlib
import json
import math
import os
from pathlib import Path
import shutil
import subprocess
import uuid

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
session = root / "runtime/native-sessions" / ("animation-authoring-" + uuid.uuid4().hex)
session.mkdir(parents=True)
environment = os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")}
# SimsSDL renders PNGs without a display through SDL's offscreen video driver.
render_environment = os.environ | {"SDL_VIDEO_DRIVER": os.environ.get("SDL_VIDEO_DRIVER", "offscreen")}
simulation = [shutil.which("dotnet"), str(root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll")]
# SimsNative on macOS, SimsSDL elsewhere; only SimsNative can stream an animation into a scene.
binary = next((root / "native/SimsNative/.build/release" / name for name in ["SimsNative", "SimsSDL"]
               if (root / "native/SimsNative/.build/release" / name).exists()), None)
assert binary, "Build SimsNative or SimsSDL in release first"
streams = binary.name == "SimsNative"
# SimsSDL frames the lot corner at its default zoom; zoomed out the animated Sim is in view.
render_flag = ["--render"] if streams else ["--zoom", "far", "--png"]
original = root / "runtime/game/UserData/Houses/House05.iff"
before = hashlib.sha256(original.read_bytes()).hexdigest()
frames = 30
base_clip = {"name": "native-authoring-wave", "frames": frames, "tracks": [{
    "bone": "ROOT", "translations": [[0.2 * math.sin(index * 0.1), 0.01 * index, 0] for index in range(frames)],
    "rotations": [[0, math.sin(index * 0.005), 0, math.cos(index * 0.005)] for index in range(frames)],
    "events": [{"time": 900, "properties": {"xevt": "13"}}, {"time": 0, "properties": {"xevt": "11"}},
               {"time": 33, "properties": {"xevt": "12"}}]}]}
results = []
for encoding in ["bcf", "cmx"]:
    directory = session / encoding
    source = directory / "animation.json"
    source.parent.mkdir(parents=True)
    document = {"schemaVersion": 1, "packID": "local.animation-" + encoding, "encoding": encoding, "animations": [base_clip]}
    source.write_text(json.dumps(document))
    packs = directory / "packs"
    pack = packs / document["packID"]
    compiler = subprocess.run(simulation + ["--compile-animation", str(source), str(pack), str(root / "runtime/game")], env=environment, capture_output=True, text=True)
    (directory / "compiler.log").write_text(compiler.stderr)
    compiler.check_returncode()
    compiled = json.loads(compiler.stdout)
    assert [clip["skeleton"] for clip in compiled["animations"]] == ["adult"], "ROOT motion was not fitted to the adult skeleton"
    report = json.loads(subprocess.check_output([str(binary), "--game", str(root / "runtime/game"), "--packs", str(packs), "--pack-report"], text=True))
    assert report["avatarResources"] == [{"kind": "animation", "name": base_clip["name"], "owner": document["packID"],
                                         "path": f"downloads/{document['packID']}.{encoding}"}]
    manifest_before = (pack / "pack.json").read_bytes()
    repeated = subprocess.run(simulation + ["--compile-animation", str(source), str(pack)], env=environment, capture_output=True, text=True)
    assert repeated.returncode != 0 and (pack / "pack.json").read_bytes() == manifest_before
    mount = directory / "game"
    subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--packs", str(packs), "--mount", str(mount)], check=True, capture_output=True, text=True)
    process = subprocess.run(simulation + [str(mount), str(root), "5", "0", "--check-animations"], env=environment, capture_output=True, text=True)
    (directory / "runtime.log").write_text(process.stderr)
    process.check_returncode()
    runtime = json.loads(process.stdout)
    render_directory = directory / "renders"
    render_directory.mkdir()
    renders = []
    for width, height in [(1600, 960), (2400, 1800)]:
        images = {}
        for fixture in runtime["animations"]["fixtures"]:
            output = render_directory / f"{fixture['name']}-{width}x{height}.png"
            subprocess.run([str(binary), "--game", str(mount), "--scene", fixture["scene"], "--width", str(width),
                            "--height", str(height), *render_flag, str(output)], check=True, capture_output=True, text=True, env=render_environment)
            images[fixture["name"]] = Image.open(output).convert("RGB")
            renders.append(str(output))
        assert ImageChops.difference(images["start"], images["middle"]).getbbox(), "Authored motion did not change native pose"
        assert ImageChops.difference(images["middle"], images["end"]).getbbox(), "Authored motion stopped before final frames"
        assert ImageChops.difference(images["middle"], images["loaded"]).getbbox() is None, "Save/load changed authored pose"
        if not streams:
            continue
        start = next(fixture for fixture in runtime["animations"]["fixtures"] if fixture["name"] == "start")
        output = render_directory / f"streamed-middle-{width}x{height}.png"
        subprocess.run([str(binary), "--game", str(mount), "--scene", start["scene"], "--animation", runtime["animations"]["animation"],
                        "--width", str(width), "--height", str(height), *render_flag, str(output)], check=True, capture_output=True, text=True, env=render_environment)
        assert ImageChops.difference(images["middle"], Image.open(output).convert("RGB")).getbbox() is None, "Streamed authored motion differed from snapshot"
        renders.append(str(output))
    shutil.rmtree(mount)  # a full copy of the game; the renders above are what the result points to
    results.append({"encoding": encoding, "compiler": compiled, "fingerprint": report["fingerprint"], "runtime": runtime, "renders": renders})
invalid = []
for name, change in [
    ("unknown-field", lambda doc: doc.update(unknown=True)),
    ("unsafe-name", lambda doc: doc["animations"][0].update(name="../escape")),
    ("hidden-name", lambda doc: doc["animations"][0].update(name=".hidden")),
    ("hidden-pack", lambda doc: doc.update(packID=".hidden")),
    ("empty-display-name", lambda doc: doc.update(name=" ")),
    ("duplicate-clip", lambda doc: doc["animations"].append(json.loads(json.dumps(doc["animations"][0])))),
    ("duplicate-bone", lambda doc: doc["animations"][0]["tracks"].append(json.loads(json.dumps(doc["animations"][0]["tracks"][0])))),
    ("unrepresentable-string", lambda doc: doc["animations"][0]["tracks"][0].update(bone="RÖÖT")),
    ("sample-count", lambda doc: doc["animations"][0]["tracks"][0].update(translations=[[0, 0, 0]])),
    ("rotation", lambda doc: doc["animations"][0]["tracks"][0].update(rotations=[[0, 0, 0, 2]] * frames)),
    ("event-time", lambda doc: doc["animations"][0]["tracks"][0]["events"][0].update(time=1000)),
    # Bones are checked against the skeletons of the installed game.
    ("unknown-bone", lambda doc: doc["animations"][0]["tracks"][0].update(bone="WINGTIP")),
    ("unknown-skeleton", lambda doc: doc.update(skeleton="dragon")),
    ("bone-not-in-skeleton", lambda doc: (doc.update(skeleton="child"), doc["animations"][0]["tracks"][0].update(bone="WINGTIP"))),
    ("skeleton-without-game", lambda doc: doc.update(skeleton="child")),
]:
    document = json.loads(json.dumps({"packID": "local.invalid-animation", "animations": [base_clip]}))
    change(document)
    source = session / (name + ".json")
    source.write_text(json.dumps(document))
    output = session / (name + "-pack")
    game = [] if name == "skeleton-without-game" else [str(root / "runtime/game")]
    process = subprocess.run(simulation + ["--compile-animation", str(source), str(output)] + game, env=environment, capture_output=True, text=True)
    assert process.returncode != 0 and not output.exists(), f"Invalid animation {name} created a pack"
    assert "Unhandled exception" not in process.stderr, process.stderr[-2000:]
    invalid.append(name)
assert hashlib.sha256(original.read_bytes()).hexdigest() == before
report = {"result": "passed", "formats": results, "invalidSourcesRejectedBeforeOutput": invalid, "baseLotUnchanged": True, "livePresentationVerified": False}
(root / "logs/native-animation-authoring-result.json").write_text(json.dumps(report, indent=2))
print(json.dumps({"result": "passed", "formats": [item["encoding"] for item in results],
                  "originalAnimationsDecoded": [item["runtime"]["animations"]["originalAnimationsDecoded"] for item in results],
                  "checks": [item["runtime"]["animations"]["checks"] for item in results],
                  "renderCount": sum(len(item["renders"]) for item in results), "invalidSources": invalid, "baseLotUnchanged": True}))
