import copy
import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops

root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
fixtures = runtime["buildCatalog"]["floorMeshes"]["fixtures"]
directory = root / "analysis/floor-mesh-check"
directory.mkdir(parents=True, exist_ok=True)
renders = []
for label, fixture, target in zip(["slope", "vertical-diagonal", "horizontal-diagonal"], fixtures, runtime["buildCatalog"]["floorMeshes"]["targets"]):
    path = Path(fixture)
    scene = json.loads(path.read_text())
    floor_meshes = [mesh for mesh in scene["meshes"] if mesh.get("floor")]
    selected = [mesh for mesh in floor_meshes if mesh["floor"]["x"] == target["x"] and mesh["floor"]["y"] == target["y"]]
    stripped = copy.deepcopy(scene)
    stripped["meshes"] = [mesh for mesh in stripped["meshes"] if not (mesh.get("floor") and mesh["floor"]["x"] == target["x"] and mesh["floor"]["y"] == target["y"])]
    stripped_path = path.parent / (label + "-without-floor.json")
    stripped_path.write_text(json.dumps(stripped))
    for width, height in [(1600, 960), (2400, 1800)]:
        images = {}
        for name, source in [("floor", path), ("without", stripped_path)]:
            output = directory / f"{label}-{name}-{width}x{height}.png"
            subprocess.run([str(root / "native/SimsNative/.build/release/SimsNative"), "--game", str(root / "runtime/game"), "--scene", str(source), "--controls", "--width", str(width), "--height", str(height), "--render", str(output)], check=True, stdout=subprocess.DEVNULL)
            images[name] = Image.open(output).convert("RGBA")
            renders.append(str(output))
        difference = ImageChops.difference(images["floor"].convert("RGB"), images["without"].convert("RGB"))
        bounds = difference.getbbox()
        assert bounds, f"{label} floor triangles are invisible"
        scale = min(width / scene["width"], (height - 300) / scene["height"]) * 0.94
        origin_x = (width - scene["width"] * scale) / 2
        origin_y = (height - 300 - scene["height"] * scale) / 2
        vertices = [vertex for mesh in selected for vertex in mesh["vertices"]]
        expected = (min(vertex["x"] for vertex in vertices) * scale + origin_x - 2,
                    min(vertex["y"] for vertex in vertices) * scale + origin_y - 2,
                    max(vertex["x"] for vertex in vertices) * scale + origin_x + 2,
                    max(vertex["y"] for vertex in vertices) * scale + origin_y + 2)
        assert bounds[0] >= expected[0] and bounds[1] >= expected[1] and bounds[2] <= expected[2] and bounds[3] <= expected[3], "Floor mesh alters pixels outside its projected terrain geometry"
        assert all(alpha == 255 for *rgb, alpha in images["floor"].crop(bounds).getdata()), "Floor rendering leaves transparent holes"
result = {"result": "passed", "slopedFloor": True, "diagonalHalves": True, "renders": renders, "livePresentationVerified": False}
(root / "logs/native-floor-mesh-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result))
