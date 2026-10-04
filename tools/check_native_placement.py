import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops

root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
editing = runtime["objectEditing"]
page = Path(editing["catalogFixture"])
preview = json.loads(Path(editing["placementFixture"]).read_text())
assert preview["valid"]
directory = root / "analysis/placement-check"
directory.mkdir(parents=True, exist_ok=True)
renders = []
for width, height in [(1600, 960), (2400, 1800)]:
    images = {}
    for name, fixture in [("baseline", None), ("valid", preview), ("invalid", json.loads((page.parent / "placement-invalid-preview.json").read_text())), ("rotated", json.loads((page.parent / "placement-rotated-preview.json").read_text())), ("footprint", preview | {"ghost": None})]:
        output = directory / f"{name}-{width}x{height}.png"
        command = [str(root / "native/SimsNative/.build/release/SimsNative"), "--game", str(root / "runtime/game"), "--scene", runtime["scene"],
                   "--panel-state", str(page.parent / "catalog-state.json"), "--buy-catalog", str(page),
                   "--width", str(width), "--height", str(height), "--render", str(output)]
        if fixture is not None:
            path = directory / (name + ".json")
            path.write_text(json.dumps(fixture))
            command += ["--placement-preview", str(path)]
        subprocess.run(command, check=True, stdout=subprocess.DEVNULL)
        images[name] = Image.open(output).convert("RGB")
        renders.append(str(output))
    bounds = ImageChops.difference(images["baseline"], images["valid"]).getbbox()
    assert bounds and bounds[3] <= height - 300, "Placement footprint is absent or enters the UI panel"
    assert ImageChops.difference(images["valid"], images["footprint"]).getbbox(), "Object ghost is missing from its footprint"
    assert ImageChops.difference(images["valid"], images["rotated"]).getbbox(), "Rotation did not change rendered object artwork"
    assert ImageChops.difference(images["valid"], images["invalid"]).getbbox(), "Valid and invalid footprints render identically"
    assert sum(green > red for red, green, blue in images["valid"].crop(bounds).getdata()) > sum(green > red for red, green, blue in images["invalid"].crop(bounds).getdata())
result = {"result": "passed", "renders": renders, "validAndInvalidFootprints": True, "originalObjectGhost": True, "directionalArtwork": True, "livePresentationVerified": False}
(root / "logs/native-placement-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result))
