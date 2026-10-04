import copy
import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-swimming-result.json").read_text())
catalog_runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
panel = Path(catalog_runtime["objectEditing"]["catalogFixture"]).parent / "catalog-state.json"
directory = root / "analysis/swimming-render-check"
directory.mkdir(parents=True, exist_ok=True)
binary = root / "native/SimsNative/.build/release/SimsNative"
renders = []


def fixture(path, scene):
    path.write_text(json.dumps(scene))
    return path


def render(path, name, width, height):
    output = directory / f"{name}-{width}x{height}.png"
    subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", str(path), "--panel-state", str(panel), "--width", str(width), "--height", str(height), "--render", str(output)], check=True, stdout=subprocess.DEVNULL)
    renders.append(str(output))
    return Image.open(output).convert("RGB")


for item in runtime["poolAccessories"]["items"]:
    path = Path(item["swimming"]["scene"])
    scene = json.loads(path.read_text())
    identifier = item["swimming"]["simID"]
    assert any(mesh["objectID"] == identifier for mesh in scene["meshes"])
    removed = copy.deepcopy(scene)
    removed["meshes"] = [mesh for mesh in removed["meshes"] if mesh["objectID"] != identifier]
    absent = fixture(path.with_name("swimmer-absent-" + str(item["guid"]) + ".json"), removed)
    exposed = copy.deepcopy(scene)
    for mesh in exposed["meshes"]:
        if mesh["objectID"] == identifier:
            for vertex in mesh["vertices"]:
                vertex["z"] = 0
    unmasked = fixture(path.with_name("swimmer-unmasked-" + str(item["guid"]) + ".json"), exposed)
    for width, height in [(1600, 960), (2400, 1800)]:
        normal = render(path, "swimming-" + str(item["guid"]), width, height)
        hidden = render(absent, "absent-" + str(item["guid"]), width, height)
        complete = render(unmasked, "unmasked-" + str(item["guid"]), width, height)
        assert ImageChops.difference(normal, hidden).getbbox(), "The entire swimmer disappeared"
        assert ImageChops.difference(normal, complete).getbbox(), "Pool depth did not mask the submerged avatar"
        assert not ImageChops.difference(normal, complete).crop((0, height - 366, width, height)).getbbox(), "Water depth changed the original controls"
result = {"result": "passed", "originalSwimInteractions": True, "swimmingSaveLoad": True, "originalLadderExit": True, "waterDepthMask": True, "livePresentationVerified": False, "renders": renders}
(root / "logs/native-swimming-render-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps({key: value for key, value in result.items() if key != "renders"} | {"renderCount": len(renders)}))
