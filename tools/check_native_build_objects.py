import copy
import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
checks = runtime["buildCatalog"]["objects"]
state = Path(runtime["objectEditing"]["catalogFixture"]).parent / "catalog-state.json"
directory = root / "analysis/build-object-browser-check"
directory.mkdir(parents=True, exist_ok=True)
binary = root / "native/SimsNative/.build/release/SimsNative"
renders = []
positions = {"door": (367, 55), "window": (409, 55), "stairs": (450, 4), "plants": (279, 57), "fireplace": (502, 8)}
for width, height in [(1600, 960), (2400, 1800)]:
    images = {}
    for check in checks:
        tool = check["tool"]
        fixture = Path(check["fixture"])
        page = json.loads(fixture.read_text())
        fallback = copy.deepcopy(page)
        for item in fallback["items"]:
            item["icon"] = None
        fallback_path = directory / (tool + "-fallback.json")
        fallback_path.write_text(json.dumps(fallback))
        preview = fixture.with_name("build-objects-" + tool + "-preview.json")
        variants = [("catalog", fixture, []), ("fallback", fallback_path, []), ("ghost", fixture, ["--placement-preview", str(preview)]), ("selected", fixture, ["--catalog-guid", str(check["guid"])])]
        for name, path, extra in variants:
            output = directory / f"{tool}-{name}-{width}x{height}.png"
            subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", runtime["scene"], "--panel-state", str(state), "--build-objects", str(path), "--width", str(width), "--height", str(height), "--render", str(output)] + extra, check=True, stdout=subprocess.DEVNULL)
            images[tool, name] = Image.open(output).convert("RGB")
            renders.append(str(output))
        capacity = max(1, min(32, int((width / 2 - 562) / 45))) * 2
        icon_index = next(index for index, item in enumerate(page["items"][:capacity]) if item["icon"])
        columns = capacity // 2
        x, y = 1116 + icon_index % columns * 90, height - 190 + icon_index // columns * 90
        cell = (x, y, x + 90, y + 90)
        assert ImageChops.difference(images[tool, "catalog"].crop(cell), images[tool, "fallback"].crop(cell)).getbbox(), f"Original {tool} thumbnail is missing"
        selected_index = next(index for index, item in enumerate(page["items"][:capacity]) if item["guid"] == check["guid"])
        x, y = 1116 + selected_index % columns * 90, height - 190 + selected_index // columns * 90
        selected_cell = (x, y, x + 90, y + 90)
        assert ImageChops.difference(images[tool, "catalog"].crop(selected_cell), images[tool, "selected"].crop(selected_cell)).getbbox(), f"{tool} selection frame is missing"
        ghost_difference = ImageChops.difference(images[tool, "catalog"], images[tool, "ghost"])
        assert ghost_difference.crop((0, 0, width, height - 366)).getbbox(), f"Build-mode {tool} placement ghost is missing"
        assert not ghost_difference.crop((0, height - 366, width, height)).getbbox(), f"{tool} ghost covers the original controls"
    for tool, (x, y) in positions.items():
        other = next(check["tool"] for check in checks if check["tool"] != tool)
        bounds = (x * 2, height - 200 + y * 2, (x + 25) * 2, height - 200 + (y + 20) * 2)
        assert ImageChops.difference(images[tool, "catalog"].crop(bounds), images[other, "catalog"].crop(bounds)).getbbox(), f"Original {tool} tool has no selected artwork"
    output = directory / f"hand-{width}x{height}.png"
    subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", runtime["scene"], "--panel-state", str(state), "--build-objects", checks[0]["fixture"], "--build-object-tool", "hand", "--width", str(width), "--height", str(height), "--render", str(output)], check=True, stdout=subprocess.DEVNULL)
    hand = Image.open(output).convert("RGB")
    bounds = (1004, height - 90, 1054, height - 50)
    assert ImageChops.difference(hand.crop(bounds), images["door", "catalog"].crop(bounds)).getbbox(), "Original Hand tool has no selected artwork"
    renders.append(str(output))
result = {"result": "passed", "tools": [check["tool"] for check in checks], "originalIcons": True, "selectionFrames": True, "buildModeGhosts": True, "handTool": True, "renders": renders, "livePresentationVerified": False}
(root / "logs/native-build-object-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps({key: value for key, value in result.items() if key != "renders"} | {"renderCount": len(renders)}))
