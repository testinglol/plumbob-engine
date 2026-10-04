import json
from pathlib import Path
import subprocess
from PIL import Image


root = Path(__file__).resolve().parents[1]
panel_result = json.loads((root / "logs/native-panel-result.json").read_text())
initial_file = Path(panel_result["panelState"])
initial = json.loads(initial_file.read_text())
output = root / "analysis/gameplay-panel/render-check"
output.mkdir(parents=True, exist_ok=True)
residents = [sim for sim in initial["sims"] if sim["household"]]
assert len(residents) == 3
results = []
for width, height in [(1600, 960), (2400, 1800)]:
    label_pixels = None
    for sim in residents:
        state = initial | {"selectedSim": sim["id"]}
        state_file = output / (sim["name"] + ".json")
        state_file.write_text(json.dumps(state))
        png = output / f"{sim['name']}-{width}x{height}.png"
        subprocess.run([str(root / "Sims Native Preview.app/Contents/MacOS/SimsNative"),
                        "--scene", panel_result["scene"], "--panel-state", str(initial_file),
                        "--subpanel", "personality", "--reload-panel-state", str(state_file),
                        "--render", str(png), "--width", str(width), "--height", str(height)],
                       check=True, capture_output=True, text=True)
        with Image.open(png) as image:
            top = height - 300
            labels = image.crop((1220, top + 116, 1352, height)).tobytes()
            if label_pixels is None:
                label_pixels = labels
                assert sum(1 for offset in range(0, len(labels), 4) if min(labels[offset:offset + 3]) > 180) > 300
            else:
                assert labels == label_pixels, "Trait labels changed or disappeared after resident update"
            for index, trait in enumerate(["Neat", "Outgoing", "Active", "Playful", "Nice"]):
                filled = sum(1 for column in range(10) if image.getpixel(((679 + column * 4 + 2) * 2, top + (65 + index * 18) * 2))[0] < 10)
                assert filled == min(10, max(0, sim["personality"][trait] // 100)), (sim["name"], trait, filled)
        results.append({"resident": sim["name"], "resolution": [width, height], "labelsStable": True, "allFiveTraitBarsMatchSimulation": True})
(root / "logs/native-subpanel-result.json").write_text(json.dumps({"result": "passed", "cases": results}, indent=2) + "\n")
print(f"Passed {len(results)} original personality panel renders: all Goth residents, repeated state updates and two resolutions.")
