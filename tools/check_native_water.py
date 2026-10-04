import copy
import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
water = runtime["buildCatalog"]["water"]
page_path = Path(water["fixture"])
page = json.loads(page_path.read_text())
state = Path(runtime["objectEditing"]["catalogFixture"]).parent / "catalog-state.json"
directory = root / "analysis/water-render-check"
directory.mkdir(parents=True, exist_ok=True)
binary = root / "native/SimsNative/.build/release/SimsNative"
renders = []
corner_textures = set()
for case in water["cases"]:
    if case["pattern"] != 65535:
        continue
    full = json.loads(Path(case["full"]["scene"]).read_text())
    ring = json.loads(Path(case["ring"]["scene"]).read_text())
    full_tiles = {(mesh["floor"]["x"], mesh["floor"]["y"]): mesh for mesh in full["meshes"] if (mesh.get("floor") or {}).get("pattern") == 65535}
    for mesh in ring["meshes"]:
        floor = mesh.get("floor") or {}
        if floor.get("water") and floor["water"]["corners"]:
            original = full_tiles[floor["x"], floor["y"]]
            assert floor["water"]["sprite"] == original["floor"]["water"]["sprite"]
            assert ring["textures"][mesh["texture"]]["file"] != full["textures"][original["texture"]]["file"], "Pool corner was recorded but not composited into the texture"
            corner_textures.update(floor["water"]["corners"])
assert corner_textures == {0x434, 0x435, 0x436, 0x437}


def render(scene, output, extra=None, catalog=page_path):
    subprocess.run([str(binary), "--game", str(root / "runtime/game"), "--scene", str(scene), "--panel-state", str(state), "--build-catalog", str(catalog), "--width", str(width), "--height", str(height), "--render", str(output)] + (extra or []), check=True, stdout=subprocess.DEVNULL)
    renders.append(str(output))
    return Image.open(output).convert("RGB")


for width, height in [(1600, 960), (2400, 1800)]:
    for case in water["cases"]:
        for phase in ["full", "ring", "mixed"]:
            scene_path = Path(case[phase]["scene"])
            scene = json.loads(scene_path.read_text())
            meshes = [mesh for mesh in scene["meshes"] if (mesh.get("floor") or {}).get("pattern", 0) >= 65534]
            baseline = copy.deepcopy(scene)
            baseline["meshes"] = [mesh for mesh in baseline["meshes"] if (mesh.get("floor") or {}).get("pattern", 0) < 65534]
            baseline_path = scene_path.with_name(f"water-baseline-{case['pattern']}-{phase}.json")
            baseline_path.write_text(json.dumps(baseline))
            original = render(baseline_path, directory / f"baseline-{case['pattern']}-{phase}-{width}x{height}.png")
            rendered = render(scene_path, directory / f"water-{case['pattern']}-{phase}-{width}x{height}.png")
            difference = ImageChops.difference(original, rendered)
            bounds = difference.getbbox()
            assert bounds, "Native water artwork is invisible"
            scale = min(width / scene["width"], (height - 300) / scene["height"]) * 0.94
            ox, oy = (width - scene["width"] * scale) / 2, (height - 300 - scene["height"] * scale) / 2
            vertices = [vertex for mesh in meshes for vertex in mesh["vertices"]]
            left = min(vertex["x"] for vertex in vertices) * scale + ox
            right = max(vertex["x"] for vertex in vertices) * scale + ox
            top = min(vertex["y"] for vertex in vertices) * scale + oy
            bottom = max(vertex["y"] for vertex in vertices) * scale + oy
            assert bounds[0] >= left - 2 and bounds[1] >= top - 2 and bounds[2] <= right + 2 and bounds[3] <= bottom + 2, "Water pixels escape the actual terrain-aligned tile region"
            assert not difference.crop((0, height - 366, width, height)).getbbox(), "Water covers original controls"
    removed_path = water["cases"][0]["removed"]["scene"]
    base = render(removed_path, directory / f"catalog-{width}x{height}.png")
    fallback = copy.deepcopy(page)
    for item in fallback["items"]:
        item["icon"] = None
    fallback_path = directory / "water-fallback.json"
    fallback_path.write_text(json.dumps(fallback))
    unknown = render(removed_path, directory / f"catalog-fallback-{width}x{height}.png", catalog=fallback_path)
    columns = max(1, min(32, int((width / 2 - 562) / 45)))
    for index, item in enumerate(page["items"]):
        if item.get("guid") is not None:
            continue
        x, y = 1116 + index % columns * 90, height - 190 + index // columns * 90
        cell = (x, y, x + 90, y + 90)
        assert ImageChops.difference(base.crop(cell), unknown.crop(cell)).getbbox(), "Original pool or pond catalog thumbnail is missing"
    x, y = water["origin"]
    for mode, extra in [("brush", []), ("removal", ["--floor-delete"])]:
        image = render(removed_path, directory / f"{mode}-{width}x{height}.png", ["--floor-brush", f"{x},{y},{x + 2},{y + 2}"] + extra)
        difference = ImageChops.difference(base, image)
        assert difference.getbbox() and not difference.crop((0, height - 366, width, height)).getbbox()
result = {"result": "passed", "pool": True, "pond": True, "originalCornerTextures": sorted(corner_textures), "mixedWaterEdges": True, "originalCatalogIcons": True, "brushAndRemoval": True, "terrainAligned": True, "renders": renders, "livePresentationVerified": False}
(root / "logs/native-water-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps({key: value for key, value in result.items() if key != "renders"} | {"renderCount": len(renders)}))
