import copy
import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
page_path = Path(runtime["objectEditing"]["catalogFixture"])
page = json.loads(page_path.read_text())
state = json.loads((page_path.parent / "catalog-state.json").read_text())
assert len(page["items"]) >= 30
directory = root / "analysis/buy-browser-check"
directory.mkdir(parents=True, exist_ok=True)
states = {"normal": state, "unaffordable": state | {"budget": 0}, "fallback": state}
fallback = copy.deepcopy(page)
for item in fallback["items"]:
    item["icon"] = None
pages = {"normal": page, "unaffordable": page, "fallback": fallback}
renders = []
for width, height in [(1600, 960), (2400, 1800)]:
    images = {}
    for name in states:
        fixture = directory / (name + "-page.json")
        fixture.write_text(json.dumps(pages[name]))
        status = directory / (name + "-state.json")
        status.write_text(json.dumps(states[name]))
        output = directory / f"{name}-{width}x{height}.png"
        subprocess.run([str(root / "native/SimsNative/.build/release/SimsNative"), "--game", str(root / "runtime/game"),
                        "--scene", runtime["scene"], "--panel-state", str(status), "--buy-catalog", str(fixture),
                        "--width", str(width), "--height", str(height), "--render", str(output)], check=True, stdout=subprocess.DEVNULL)
        image = Image.open(output).convert("RGB")
        assert image.size == (width, height)
        images[name] = image
        renders.append(str(output))
    top = height - 200
    first = (842, top, 932, top + 90)
    second = (938, top, 1028, top + 90)
    normal = images["normal"].crop(first)
    disabled = images["unaffordable"].crop(first)
    missing = images["fallback"].crop(first)
    assert ImageChops.difference(normal, disabled).getbbox(), "Unaffordable thumbnail has no disabled state"
    assert ImageChops.difference(normal, missing).getbbox(), "Fallback thumbnail did not replace the catalog icon"
    assert ImageChops.difference(missing, images["fallback"].crop(second)).getbbox() is None, "Fallback cells render differently"
    assert sum(red > 150 and red > green * 1.4 and blue > green * 1.4 for red, green, blue in normal.getdata()) > 20, "The custom object's original pink flamingo icon is missing"
    columns = min(32, max(1, int((width / 2 - 445) / 48)))
    for index in range(columns * 2):
        x = 842 + index % columns * 96
        y = top + index // columns * 100
        assert len(set(images["normal"].crop((x, y, x + 90, y + 90)).getdata())) > 5, f"Catalog cell {index} is blank"
result = {"result": "passed", "renders": renders, "normalAndDisabledStates": True, "originalPackThumbnail": True, "fallbackFrame": True,
          "livePresentationVerified": False}
(root / "logs/native-buy-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result))
