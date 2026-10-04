import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
cutaway = json.loads((root / "logs/native-cutaway-result.json").read_text())["cutaway"]
binary = root / "native/SimsNative/.build/release/SimsNative"
directory = root / "analysis/cutaway-render-check"
directory.mkdir(parents=True, exist_ok=True)
renders = []
for width, height in [(1600, 960), (2400, 1800)]:
    images = {}
    for fixture in cutaway["fixtures"]:
        output = directory / f"{fixture['name']}-{width}x{height}.png"
        subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", fixture["scene"], "--panel-state", cutaway["state"],
                        "--width", str(width), "--height", str(height), "--render", str(output)], check=True, stdout=subprocess.DEVNULL)
        images[fixture["name"]] = Image.open(output).convert("RGB")
        renders.append(str(output))
    for name in ["up", "down"]:
        fixture = next(item for item in cutaway["fixtures"] if item["name"] == name)
        source = Path(fixture["scene"])
        scene = json.loads(source.read_text())
        junctions = [sprite for sprite in scene["sprites"] if sprite.get("junction")]
        assert junctions
        scene["sprites"] = [sprite for sprite in scene["sprites"] if not sprite.get("junction")]
        control = source.with_name(f"junction-control-{name}.json")
        control.write_text(json.dumps(scene))
        output = directory / f"junction-control-{name}-{width}x{height}.png"
        subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", str(control), "--panel-state", cutaway["state"],
                        "--width", str(width), "--height", str(height), "--render", str(output)], check=True, stdout=subprocess.DEVNULL)
        difference = ImageChops.difference(images[name], Image.open(output).convert("RGB"))
        assert difference.crop((0, 0, width, height - 366)).getbbox(), f"{name} junctions were invisible"
        assert difference.crop((0, height - 366, width, height)).getbbox() is None, "Junctions changed original UI"
        renders.append(str(output))
    for name in ["up", "down"]:
        fixture = next(item for item in cutaway["fixtures"] if item["name"] == name)
        source = Path(fixture["scene"])
        scene = json.loads(source.read_text())
        architecture = [sprite for sprite in scene["sprites"] if sprite.get("architectureDepth")]
        assert architecture
        for sprite in architecture:
            for field in ["architectureDepth", "depthTexture", "depthNear", "depthFar"]:
                sprite.pop(field, None)
        control = source.with_name(f"wall-depth-control-{name}.json")
        control.write_text(json.dumps(scene))
        output = directory / f"wall-depth-control-{name}-{width}x{height}.png"
        subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", str(control), "--panel-state", cutaway["state"],
                        "--width", str(width), "--height", str(height), "--render", str(output)], check=True, stdout=subprocess.DEVNULL)
        difference = ImageChops.difference(images[name], Image.open(output).convert("RGB"))
        assert difference.crop((0, 0, width, height - 366)).getbbox(), f"{name} wall depth had no effect"
        assert difference.crop((0, height - 366, width, height)).getbbox() is None, "Wall depth changed original UI"
        renders.append(str(output))
    assert ImageChops.difference(images["up"], images["down"]).crop((0, 0, width, height - 366)).getbbox()
    for fixture in cutaway["fixtures"][2:]:
        image = images[fixture["name"]]
        assert ImageChops.difference(image, images["up"]).crop((0, 0, width, height - 366)).getbbox()
        assert ImageChops.difference(image, images["down"]).crop((0, 0, width, height - 366)).getbbox()
    assert any(ImageChops.difference(images["hover-0"], image).crop((0, 0, width, height - 366)).getbbox() for name, image in images.items() if name.startswith("hover-"))
report = {"result": "passed", "originalDynacutControl": True, "partialWallMasks": True, "junctionVisibility": True, "wallDepthChangesOverlap": True, "roomHoverChanges": True,
          "livePresentationVerified": False, "renders": renders}
(root / "logs/native-cutaway-render-result.json").write_text(json.dumps(report, indent=2))
print(json.dumps({key: value for key, value in report.items() if key != "renders"} | {"renderCount": len(renders)}))
