import copy
import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
stories = json.loads((root / "logs/native-story-result.json").read_text())["stories"]
directory = root / "analysis/story-render-check"
directory.mkdir(parents=True, exist_ok=True)
binary = root / "native/SimsNative/.build/release/SimsNative"
renders = []


def render(path, name, width, height, extra=None, state=None):
    output = directory / f"{name}-{width}x{height}.png"
    subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", str(path), "--panel-state", state or stories["state"], "--width", str(width), "--height", str(height), "--render", str(output)] + (extra or []), check=True, stdout=subprocess.DEVNULL)
    renders.append(str(output))
    return Image.open(output).convert("RGB")


original = json.loads(Path(stories["views"][1]["scene"]).read_text())
scene_path = Path(stories["objectScene"])
objects = json.loads(scene_path.read_text())
old_ids = {sprite["objectID"] for sprite in original["sprites"]}
new_ids = {sprite["objectID"] for sprite in objects["sprites"]} - old_ids
assert new_ids, "No upper-story object sprite was added"
removed = copy.deepcopy(objects)
removed["sprites"] = [sprite for sprite in removed["sprites"] if sprite["objectID"] not in new_ids]
absent_path = scene_path.with_name("story-2-object-absent.json")
absent_path.write_text(json.dumps(removed))
sim_path = Path(stories["upperSimScene"])
sim_scene = json.loads(sim_path.read_text())
sim_scene["meshes"] = [mesh for mesh in sim_scene["meshes"] if mesh["objectID"] != stories["upperSimID"]]
sim_absent = sim_path.with_name("story-2-sim-absent.json")
sim_absent.write_text(json.dumps(sim_scene))
for width, height in [(1600, 960), (2400, 1800)]:
    views = {view["level"]: render(view["scene"], "level-" + str(view["level"]), width, height) for view in stories["views"]}
    assert ImageChops.difference(views[1], views[2]).crop((0, 0, width, height - 366)).getbbox(), "Upper story did not change visible architecture"
    for x, y, w, h in [(5, 92, 21, 11), (5, 77, 22, 15)]:
        cell = (x * 2, height - 366 + y * 2, (x + w) * 2, height - 366 + (y + h) * 2)
        assert ImageChops.difference(views[1].crop(cell), views[2].crop(cell)).getbbox(), "Original story selector did not change its selected frame"
    normal = render(stories["objectScene"], "upper-object", width, height)
    absent = render(absent_path, "upper-object-absent", width, height)
    assert ImageChops.difference(normal, absent).crop((0, 0, width, height - 366)).getbbox(), "Upper object was not rendered"
    base = render(stories["views"][1]["scene"], "upper-buy", width, height, ["--buy-catalog", stories["catalog"]])
    ghost = render(stories["views"][1]["scene"], "upper-ghost", width, height, ["--buy-catalog", stories["catalog"], "--placement-preview", stories["preview"]])
    diff = ImageChops.difference(base, ghost)
    assert diff.crop((0, 0, width, height - 366)).getbbox(), "Upper-story footprint or original ghost is missing"
    assert not diff.crop((0, height - 366, width, height)).getbbox(), "Upper ghost covers original controls"
    avatar = render(stories["upperSimScene"], "upper-sim", width, height, state=stories["upperSimState"])
    no_avatar = render(sim_absent, "upper-sim-absent", width, height, state=stories["upperSimState"])
    assert ImageChops.difference(avatar, no_avatar).crop((0, 0, width, height - 366)).getbbox(), "Sim on the upper story is missing"
result = {"result": "passed", "visibleStories": len(stories["views"]), "originalStorySelectors": True, "upperObjectsAndSims": True, "upperPlacementPreview": True, "livePresentationVerified": False, "renders": renders}
(root / "logs/native-story-render-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps({key: value for key, value in result.items() if key != "renders"} | {"renderCount": len(renders)}))
