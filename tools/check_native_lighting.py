import json
from pathlib import Path
import subprocess
import shutil

from PIL import Image, ImageChops, ImageStat


root = Path(__file__).resolve().parents[1]
result = json.loads((root / "logs/native-lighting-result.json").read_text())
assert result["result"] == "passed"
fixtures = result["lighting"]["snapshots"]
directory = Path(fixtures[0]["scene"]).parent
binary = root / "native/SimsNative/.build/release/SimsNative"
state = json.loads((root / "logs/native-roof-result.json").read_text())["roofs"]["state"]
assert Path(state).is_file()
for asset in Path(state).parent.glob("ui-*.bmp"):
    shutil.copy2(asset, directory / asset.name)
renders = []


def render(scene, name, width, height, animation=None):
    output = directory / f"{name}-{width}x{height}.png"
    arguments = [str(binary), "--game", str(root / "runtime/game"), "--scene", str(scene), "--panel-state", state,
                 "--width", str(width), "--height", str(height), "--render", str(output)]
    if animation:
        arguments += ["--animation", str(animation)]
    subprocess.run(arguments, check=True, stdout=subprocess.DEVNULL)
    renders.append(str(output))
    return Image.open(output).convert("RGB")


scenes = {}
for fixture in fixtures:
    key = fixture["hour"], fixture["contribution"]
    scene = json.loads(Path(fixture["scene"]).read_text())
    rooms = scene["lighting"]["rooms"]
    assert all(index == room["id"] and 0 <= room["ambient"] <= 100 and 0 <= room["daylight"] <= 100 for index, room in enumerate(rooms))
    assert all(sprite.get("room") is not None and sprite["room"] < len(rooms) for sprite in scene["sprites"])
    assert all(mesh.get("room") is not None and mesh["room"] < len(rooms) for mesh in scene["meshes"])
    assert any(mesh["objectID"] > 0 for mesh in scene["meshes"])
    assert any(mesh.get("floor") for mesh in scene["meshes"])
    scenes[key] = fixture, scene

for width, height in [(1600, 960), (2400, 1800)]:
    images = {key: render(fixture["scene"], f"lighting-{key[0]}-{key[1]}", width, height) for key, (fixture, _) in scenes.items()}
    lot = (0, 0, width, height - 300)
    panel = (0, height - 300, width, height)
    assert sum(ImageStat.Stat(images[12, 0].crop(lot)).mean) > sum(ImageStat.Stat(images[0, 0].crop(lot)).mean)
    for first, second in [((12, 0), (0, 0)), ((0, 0), (0, 100))]:
        difference = ImageChops.difference(images[first], images[second])
        assert difference.crop(lot).getbbox(), "Lighting did not affect lot rendering"
        assert not difference.crop(panel).getbbox(), "Lot lighting tinted original UI"
    fixture, original = scenes[0, 100]
    for material in ["sprites", "floors", "avatars", "terrain"]:
        control = json.loads(json.dumps(original))
        if material == "sprites":
            for sprite in control["sprites"]:
                sprite["room"] = 65535
        elif material == "terrain":
            control["lighting"]["outside"] = {"r": 255, "g": 255, "b": 255}
        else:
            for mesh in control["meshes"]:
                if (material == "floors" and mesh.get("floor")) or (material == "avatars" and mesh["objectID"] > 0):
                    mesh["room"] = 65535
        path = directory / f"lighting-control-{material}.json"
        path.write_text(json.dumps(control))
        image = render(path, f"lighting-control-{material}", width, height)
        difference = ImageChops.difference(images[0, 100], image)
        assert difference.crop(lot).getbbox(), f"Room lighting missing from {material}"
        assert not difference.crop(panel).getbbox()
    day_fixture, _ = scenes[12, 0]
    animation = json.loads(Path(day_fixture["animation"]).read_text())
    animation["lighting"] = original["lighting"]
    path = directory / "lighting-transition-animation.json"
    path.write_text(json.dumps(animation))
    image = render(day_fixture["scene"], "lighting-transition", width, height, path)
    assert not ImageChops.difference(image, images[0, 100]).getbbox(), "Animation lighting differs from full snapshot"

report = {"result": "passed", "dayNight": True, "lampContribution": True, "staticAndDynamicMaterials": True,
          "animationMatchesSnapshot": True, "originalUIUntinted": True, "livePresentationVerified": False, "renders": renders}
(root / "logs/native-lighting-render-result.json").write_text(json.dumps(report, indent=2))
print(json.dumps({key: value for key, value in report.items() if key != "renders"} | {"renderCount": len(renders)}))
