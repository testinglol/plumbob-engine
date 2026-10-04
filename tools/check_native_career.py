import copy
import json
from pathlib import Path
import subprocess
from PIL import Image


root = Path(__file__).resolve().parents[1]
panel = json.loads((root / "logs/native-panel-result.json").read_text())
initial_file = Path(panel["panelState"])
initial = json.loads(initial_file.read_text())
output = root / "analysis/gameplay-panel/career-check"
output.mkdir(parents=True, exist_ok=True)
residents = [sim for sim in initial["sims"] if sim["household"]]
assert len(residents) == 3
skills = ["Cooking", "Mechanical", "Charisma", "Body", "Logic", "Creativity"]
fixtures = [(sim["name"], initial | {"selectedSim": sim["id"]}) for sim in residents]
custom = copy.deepcopy(initial)
selected = next(sim for sim in custom["sims"] if sim["id"] == custom["selectedSim"])
selected["skills"] = dict(zip(skills, [299, 1000, -100, 1100, 400, 850]))
selected["career"] |= {"type": 9, "level": 0, "school": False, "age": 27,
                       "title": "Senior Containment Technician", "salary": 999,
                       "performanceLabel": "Excellent", "familyFriends": 1,
                       "currentLevelRequirements": [0] * 10,
                       "nextLevelRequirements": [2, 300, 1000, 200, 1000, 500, 800, 0, 0, 0]}
fixtures.append(("custom-skills", custom))
results = []
for width, height in [(1600, 960), (2400, 1800)]:
    label_pixels = None
    metadata_pixels = set()
    for name, state in fixtures:
        sim = next(item for item in state["sims"] if item["id"] == state["selectedSim"])
        state_file = output / (name + ".json")
        state_file.write_text(json.dumps(state))
        png = output / f"{name}-{width}x{height}.png"
        subprocess.run([str(root / "Sims Native Preview.app/Contents/MacOS/SimsNative"),
                        "--scene", panel["scene"], "--panel-state", str(initial_file),
                        "--subpanel", "career", "--reload-panel-state", str(state_file),
                        "--render", str(png), "--width", str(width), "--height", str(height)],
                       check=True, capture_output=True, text=True)
        with Image.open(png) as image:
            top = height - 300
            labels = image.crop((1220, top + 110, 1352, top + 285)).tobytes()
            if label_pixels is None:
                label_pixels = labels
                assert sum(1 for offset in range(0, len(labels), 4) if min(labels[offset:offset + 3]) > 180) > 100
            else:
                assert labels == label_pixels, "Skill labels changed after resident update"
            metadata = image.crop((1046, top + 100, 1220, height)).tobytes()
            if name != "custom-skills":
                assert metadata not in metadata_pixels, "Employed, unemployed and school metadata must differ"
                metadata_pixels.add(metadata)
            requirements = sim["career"].get("nextLevelRequirements")
            for row, skill in enumerate(skills):
                value = sim["skills"][skill]
                points = min(10, max(0, int(value / 100)))
                required = requirements[row + 1] if requirements else None
                marker = min(10, max(0, int(required / 100))) * 4 - 1 if required is not None and required > value else None
                y = top + (62 + row * 15) * 2
                for column in range(10):
                    x = column * 4 + 2
                    if marker is not None and marker <= x < marker + 4:
                        continue
                    active = image.getpixel(((677 + x) * 2, y))[0] < 10
                    assert active == (column < points), (name, skill, column, active, points)
                if marker is not None:
                    assert image.getpixel(((677 + marker + 2) * 2, y))[0] > 100, (name, skill, "missing next-level marker")
        results.append({"resident": name, "resolution": [width, height], "skillBarsMatchState": True, "nextLevelMarkersMatchState": True})
(root / "logs/native-career-result.json").write_text(json.dumps({"result": "passed", "cases": results}, indent=2) + "\n")
print(f"Passed {len(results)} Career renders: employment, unemployment, school and nonzero skills with next-level requirements.")
