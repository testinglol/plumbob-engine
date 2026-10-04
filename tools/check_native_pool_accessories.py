import copy
import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
accessories = runtime["buildCatalog"]["poolAccessories"]
page_path = Path(runtime["buildCatalog"]["water"]["fixture"])
page = json.loads(page_path.read_text())
state_path = Path(runtime["objectEditing"]["catalogFixture"]).parent / "catalog-state.json"
state = json.loads(state_path.read_text())
directory = root / "analysis/pool-accessory-render-check"
directory.mkdir(parents=True, exist_ok=True)
fallback = copy.deepcopy(page)
for item in fallback["items"]:
    item["icon"] = None
fallback_path = directory / "catalog-fallback.json"
fallback_path.write_text(json.dumps(fallback))
unaffordable = copy.deepcopy(state)
unaffordable["budget"] = 0
unaffordable_path = directory / "catalog-unaffordable.json"
unaffordable_path.write_text(json.dumps(unaffordable))
binary = root / "native/SimsNative/.build/release/SimsNative"
renders = []


def render(name, extra=None, catalog=page_path, panel=state_path):
    output = directory / f"{name}-{width}x{height}.png"
    subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", accessories["scene"], "--panel-state", str(panel), "--build-catalog", str(catalog), "--width", str(width), "--height", str(height), "--render", str(output)] + (extra or []), check=True, stdout=subprocess.DEVNULL)
    renders.append(str(output))
    return Image.open(output).convert("RGB")


for width, height in [(1600, 960), (2400, 1800)]:
    normal = render("catalog")
    unknown = render("fallback", catalog=fallback_path)
    disabled = render("unaffordable", panel=unaffordable_path)
    columns = max(1, min(32, int((width / 2 - 562) / 45)))
    for accessory in accessories["items"]:
        guid = accessory["guid"]
        index = next(index for index, item in enumerate(page["items"]) if item.get("guid") == guid)
        assert index < columns * 2
        x, y = 1116 + index % columns * 90, height - 190 + index // columns * 90
        cell = (x, y, x + 90, y + 90)
        assert ImageChops.difference(normal.crop(cell), unknown.crop(cell)).getbbox(), "Original pool accessory thumbnail is missing"
        assert ImageChops.difference(normal.crop(cell), disabled.crop(cell)).getbbox(), "Unaffordable pool accessory frame is missing"
        selected = render("selected-" + str(guid), ["--catalog-guid", str(guid)])
        assert ImageChops.difference(normal.crop(cell), selected.crop(cell)).getbbox(), "Pool accessory selection was treated as a floor pattern"
        valid = render("valid-" + str(guid), ["--catalog-guid", str(guid), "--placement-preview", accessory["preview"]])
        invalid = render("invalid-" + str(guid), ["--catalog-guid", str(guid), "--placement-preview", accessory["invalidPreview"]])
        for name, image in [("valid", valid), ("invalid", invalid)]:
            difference = ImageChops.difference(selected, image)
            assert difference.crop((0, 0, width, height - 366)).getbbox(), f"{name} pool accessory ghost is missing"
            assert not difference.crop((0, height - 366, width, height)).getbbox(), "Pool accessory ghost covers the original controls"
result = {"result": "passed", "accessories": [item["name"] for item in accessories["items"]], "originalIcons": True, "selectionAndAffordability": True, "validAndInvalidGhosts": True, "renders": renders, "livePresentationVerified": False}
(root / "logs/native-pool-accessory-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps({key: value for key, value in result.items() if key != "renders"} | {"renderCount": len(renders)}))
