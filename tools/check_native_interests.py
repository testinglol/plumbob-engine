import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
panel = json.loads((root / "logs/native-panel-result.json").read_text())
original = json.loads(Path(panel["panelState"]).read_text())
binary = root / "Sims Native Preview.app/Contents/MacOS/SimsNative"
output = root / "analysis/gameplay-panel/interest-check"
output.mkdir(parents=True, exist_ok=True)
residents = [sim for sim in original["sims"] if sim["household"]]
assert len(residents) == 3 and all(len(sim["interests"]) == 19 for sim in residents)
cases = []
render_count = 0


def render(state, page, width, height, name):
    global render_count
    source = output / (name + ".json")
    source.write_text(json.dumps(state))
    target = output / f"{name}-{width}x{height}.png"
    subprocess.run([str(binary), "--scene", panel["scene"], "--panel-state", str(source), "--subpanel", "interests",
                    "--interest-page", str(page), "--width", str(width), "--height", str(height), "--render", str(target)],
                   check=True, capture_output=True, text=True)
    render_count += 1
    return Image.open(target).convert("RGB")


def bar(image, slot, height):
    x = (613 + slot // 3 * 128) * 2
    y = height - 300 + (73 + slot % 3 * 27) * 2
    return image.crop((x, y, x + 80, y + 32))


for width, height in [(1600, 960), (2048, 1200), (2400, 1800)]:
    columns = max(1, int((width / 2 - 544) / 128))
    capacity = columns * 3
    controls = []
    for value in [0, 1000]:
        state = json.loads(json.dumps(original))
        state["selectedSim"] = residents[0]["id"]
        for sim in state["sims"]:
            if sim["id"] == state["selectedSim"]:
                sim["interests"] = [value] * 19
        controls.append(render(state, 0, width, height, "control-" + str(value)))
    assert ImageChops.difference(bar(controls[0], 0, height), bar(controls[1], 0, height)).getbbox()
    for sim in residents:
        age = sim["career"]["age"]
        topics = [8, 9, 10, 11, 4, 5, 6, 7] if 0 < age < 18 else list(range(8)) + list(range(12, 19))
        state = original | {"selectedSim": sim["id"]}
        for page in range((len(topics) + capacity - 1) // capacity):
            image = render(state, page, width, height, sim["name"] + "-page-" + str(page))
            shown = topics[page * capacity:page * capacity + capacity]
            for row, index in enumerate(shown):
                filled = min(10, max(0, int(sim["interests"][index] / 100))) * 8
                expected = bar(controls[0], row, height)
                if filled:
                    expected.paste(bar(controls[1], row, height).crop((0, 0, filled, 32)), (0, 0))
                assert ImageChops.difference(bar(image, row, height), expected).getbbox() is None, (sim["name"], page, index, filled)
            cases.append({"resident": sim["name"], "resolution": [width, height], "columns": columns, "page": page, "topics": shown, "barsMatchRawData": True})
result = {"result": "passed", "cases": cases, "renderCount": render_count, "livePresentationVerified": False}
(root / "logs/native-interest-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps({"result": "passed", "pages": len(cases), "renderCount": render_count, "originalAdultAndChildTopics": True}))
