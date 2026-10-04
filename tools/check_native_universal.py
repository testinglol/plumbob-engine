import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops

root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
page = Path(runtime["objectEditing"]["catalogFixture"])
controls = json.loads((root / "analysis/original-universal-controls.json").read_text())["controls"]
directory = root / "analysis/universal-controls-check"
directory.mkdir(parents=True, exist_ok=True)
renders = []
for width, height in [(1600, 960), (2400, 1800)]:
    images = {}
    for mode in ["live", "buy"]:
        output = directory / f"{mode}-{width}x{height}.png"
        command = [str(root / "native/SimsNative/.build/release/SimsNative"), "--game", str(root / "runtime/game"), "--scene", runtime["scene"],
                   "--panel-state", str(page.parent / "catalog-state.json"), "--width", str(width), "--height", str(height), "--render", str(output)]
        if mode == "buy":
            command += ["--buy-catalog", str(page)]
        subprocess.run(command, check=True, stdout=subprocess.DEVNULL)
        images[mode] = Image.open(output).convert("RGB")
        renders.append(str(output))
    sizes = {"live": (50, 50), "buy": (45, 47), "build": (39, 39), "zoomIn": (27, 27), "zoomOut": (27, 27), "wallsUp": (21, 21), "wallsDown": (22, 15), "story1": (21, 11), "story2": (22, 15)}
    for control in controls:
        x, y = control["x"]["value"] * 2, height - 366 + control["y"]["value"] * 2
        w, h = sizes[control["name"]]
        bounds = (x, y, x + w * 2, y + h * 2)
        live = images["live"].crop(bounds)
        buy = images["buy"].crop(bounds)
        minimum = 3 if control["name"] in ["story1", "story2"] else 30
        assert len(set(live.getdata())) > minimum and len(set(buy.getdata())) > minimum, f"Original control is blank: {control['name']}"
        if control["name"] in ["live", "buy"]:
            assert ImageChops.difference(live, buy).getbbox(), f"Mode selection does not change {control['name']} artwork"
result = {"result": "passed", "renders": renders, "originalControlsVisible": True, "modeSelectionStates": True, "livePresentationVerified": False}
(root / "logs/native-universal-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result))
