"""Authoring a clothing pack from JSON and wearing it in the native engine.

Compiles examples/outfit-pack.json (a recolor of two installed casual outfits) and a painted outfit made from exported
template textures, mounts both packs through the native loader and checks that:
- the pack report names the new appearances,
- Create-A-Sim lists the new bodies for every skin tone, with their new textures,
- the engine's appearance preview binds exactly the compiled texture,
- a recolor changes only the colors in its hue range (the skin stays as it was),
- a painted texture arrives pixel for pixel.
It also tries invalid documents and checks each is refused with a message, before any pack exists.
Results are written to logs/native-outfit-authoring-result.json.

Needs the simulation host built in Release and SimsNative or SimsSDL built in release.
"""
import colorsys
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import uuid

from PIL import Image


root = Path(__file__).resolve().parents[1]
game = root / "runtime/game"
session = root / "runtime/native-sessions" / ("outfit-authoring-" + uuid.uuid4().hex)
environment = os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")}
simulation = [shutil.which("dotnet"), str(root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll")]
binary = next((root / "native/SimsNative/.build/release" / name for name in ["SimsNative", "SimsSDL"]
               if (root / "native/SimsNative/.build/release" / name).exists()), None)
assert binary, "Build SimsNative or SimsSDL in release first"
tones = ["lgt", "med", "drk"]


def run(*arguments):
    return subprocess.run(simulation + [str(argument) for argument in arguments], env=environment, capture_output=True, text=True)


def compile_outfits(source, pack):
    process = run("--compile-outfit", source, game, pack)
    assert process.returncode == 0, process.stderr[-2000:] + process.stdout[-2000:]
    return json.loads(process.stdout)


def pixels(image):
    data = image.tobytes()
    return [tuple(data[index:index + 3]) for index in range(0, len(data), 3)]


def in_range(pixel, recolor):
    hue, _, saturation = colorsys.rgb_to_hls(*[channel / 255 for channel in pixel])
    low, high = recolor["hueRange"]
    return saturation >= recolor["minimumSaturation"] and low <= hue * 360 <= high


def main():
    session.mkdir(parents=True)
    packs = session / "packs"
    try:
        # Recolored outfits.
        example = json.loads((root / "examples/outfit-pack.json").read_text())
        recolored = compile_outfits(root / "examples/outfit-pack.json", packs / example["packID"])
        names = sorted(outfit["name"] for outfit in recolored["outfits"])
        assert names == ["b950mafat_teal", "b950mafit_teal"], names

        # Template textures, exported to paint over.
        exported = session / "exported"
        process = run("--export-outfit-textures", "b002mafit_01", game, exported)
        assert process.returncode == 0, process.stderr[-2000:]
        assert sorted(tone["tone"] for tone in json.loads(process.stdout)["tones"]) == sorted(tones)
        templates = {tone: Image.open(exported / f"{tone}.png").convert("RGB") for tone in tones}

        # A painted outfit: the exported textures with a stripe painted across them.
        painted_directory = session / "painted"
        painted_directory.mkdir()
        for tone in tones:
            image = templates[tone].copy()
            for x in range(image.width):
                for y in range(100, 120):
                    image.putpixel((x, y), (200, 30, 40))
            image.save(painted_directory / f"{tone}.png")
        painted_document = json.loads((exported / "outfit.json").read_text())
        painted_document["packID"] = "local.painted-outfit"
        painted_document["outfits"][0]["textures"] = {tone: f"{tone}.png" for tone in tones}
        (painted_directory / "outfit.json").write_text(json.dumps(painted_document))
        painted = compile_outfits(painted_directory / "outfit.json", packs / "local.painted-outfit")
        assert [outfit["name"] for outfit in painted["outfits"]] == ["b900mafit_mine"]

        report = json.loads(subprocess.check_output([str(binary), "--game", str(game), "--packs", str(packs), "--pack-report"], text=True))
        appearances = sorted(resource["name"] for resource in report["avatarResources"] if resource["kind"] == "appearance")
        assert appearances == ["b900mafit_mine", "b950mafat_teal", "b950mafit_teal"], appearances

        # The recolor touched only its hue range; the painted texture is the painting.
        recolor = example["outfits"][0]["recolor"]
        skins = packs / example["packID"] / "files/GameData/Skins"
        changed = 0
        for tone in tones:
            compiled = Image.open(skins / f"b950mafit{tone}_teal.bmp").convert("RGB")
            assert compiled.size == templates[tone].size
            for before, after in zip(pixels(templates[tone]), pixels(compiled)):
                if in_range(before, recolor):
                    changed += before != after
                else:
                    assert before == after, f"The {tone} recolor changed {before} outside its hue range"
            painting = Image.open(painted_directory / f"{tone}.png").convert("RGB")
            result = Image.open(packs / "local.painted-outfit/files/GameData/Skins" / f"b900mafit{tone}_mine.bmp").convert("RGB")
            assert result.tobytes() == painting.tobytes(), f"The painted {tone} texture changed"
        assert changed > 1000, "The recolor changed almost nothing"

        mount = session / "game"
        subprocess.run([str(binary), "--game", str(game), "--packs", str(packs), "--mount", str(mount)], check=True, capture_output=True, text=True)
        try:
            for tone in tones:
                process = run(mount, root, "--appearance-catalog", "m", "adult", tone)
                assert process.returncode == 0, process.stderr[-2000:]
                bodies = {body["id"]: body for body in json.loads(process.stdout)["bodies"]}
                for name, texture in [("b950mafit_teal", f"b950mafit{tone}_teal"), ("b950mafat_teal", f"b950mafat{tone}_teal"),
                                      ("b900mafit_mine", f"b900mafit{tone}_mine")]:
                    assert name in bodies, f"Create-A-Sim does not offer {name} for {tone} skin"
                    assert bodies[name]["texture"] == texture, bodies[name]
            previews = {}
            for body, texture in [("b950mafit_teal", skins / "b950mafitlgt_teal.bmp"),
                                  ("b900mafit_mine", packs / "local.painted-outfit/files/GameData/Skins/b900mafitlgt_mine.bmp")]:
                output = session / ("preview-" + body)
                process = run(mount, root, "--appearance-preview", output, "m", "adult", "lgt", "c001ma_ross", body)
                assert process.returncode == 0, process.stderr[-2000:]
                document = json.loads((output / "cas-preview/preview.json").read_text())
                bound = {hashlib.sha256((output / "cas-preview" / item["file"]).read_bytes()).hexdigest() for item in document["textures"]}
                assert hashlib.sha256(texture.read_bytes()).hexdigest() in bound, f"The preview of {body} does not wear its compiled texture"
                previews[body] = len(document["meshes"])
        finally:
            shutil.rmtree(mount, ignore_errors=True)  # a full copy of the game

        # Invalid documents are refused before a pack exists.
        base = {"template": "b002mafit_01", "number": 951, "suffix": "bad", "recolor": {"hue": 90}}
        cases = {
            "taken-number": {"number": 2},
            "unknown-template": {"template": "b002mazzz_01"},
            "not-an-outfit-name": {"template": "chair"},
            "suffix": {"suffix": "bad-suffix"},
            "number-range": {"number": 1000},
            "collection": {"collection": "q"},
            "no-change": {"recolor": None},
            "tone": {"recolor": None, "textures": {"pale": "lgt.png"}},
            "painting-outside": {"recolor": None, "textures": {"lgt": "../outside.png"}},
            "recolor-range": {"recolor": {"hue": 900}},
            "recolor-nothing": {"recolor": {"hue": 90, "hueRange": [300, 301], "minimumSaturation": 1}},
        }
        refused = {}
        invalid = session / "invalid"
        invalid.mkdir()
        shutil.copy(painted_directory / "lgt.png", invalid / "lgt.png")
        documents = {name: [{key: value for key, value in (base | change).items() if value is not None}] for name, change in cases.items()}
        documents["duplicate"] = [base, base | {"recolor": {"hue": 40}}]
        documents["existing-output"] = [base]
        for name, outfits in documents.items():
            source = invalid / f"{name}.json"
            source.write_text(json.dumps({"schemaVersion": 1, "packID": "local.invalid-" + name, "outfits": outfits}))
            pack = invalid / ("pack-" + name)
            if name == "existing-output":
                pack.mkdir()
            process = run("--compile-outfit", source, game, pack)
            assert process.returncode != 0, f"{name} was accepted"
            assert "Unhandled exception" not in process.stderr and process.stderr.strip(), f"{name}: {process.stderr[-2000:]}"
            assert name == "existing-output" or not pack.exists(), f"{name} left a pack behind"
            refused[name] = process.stderr.strip().splitlines()[-1]

        result = {"result": "passed", "outfits": names + ["b900mafit_mine"], "recoloredPixels": changed, "previewMeshes": previews, "refused": refused}
        (root / "logs").mkdir(exist_ok=True)
        (root / "logs/native-outfit-authoring-result.json").write_text(json.dumps(result, indent=2))
        print(json.dumps(result))
    finally:
        shutil.rmtree(session, ignore_errors=True)


if __name__ == "__main__":
    main()
