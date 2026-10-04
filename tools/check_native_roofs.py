import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
roofs = json.loads((root / "logs/native-roof-result.json").read_text())["roofs"]
directory = root / "analysis/roof-render-check"
directory.mkdir(parents=True, exist_ok=True)
binary = root / "native/SimsNative/.build/release/SimsNative"
renders = []


def render(scene, name, width, height, catalog=False):
    output = directory / f"{name}-{width}x{height}.png"
    command = [str(binary), "--game", str(root / "runtime/game"), "--scene", str(scene), "--panel-state", roofs["state"],
               "--width", str(width), "--height", str(height), "--render", str(output)]
    if catalog:
        command += ["--build-catalog", roofs["catalog"]]
    subprocess.run(command, check=True, stdout=subprocess.DEVNULL)
    renders.append(str(output))
    return Image.open(output).convert("RGB")


for width, height in [(1600, 960), (2400, 1800)]:
    images = {}
    for fixture in roofs["fixtures"]:
        path = Path(fixture["scene"])
        name = f"roof-{fixture['style']}-{fixture['pitch']}"
        image = render(path, name, width, height)
        images[fixture["style"], fixture["pitch"]] = image
        absent = json.loads(path.read_text())
        absent["meshes"] = [mesh for mesh in absent["meshes"] if not mesh.get("roof")]
        absent_path = path.with_name(name + "-absent.json")
        absent_path.write_text(json.dumps(absent))
        control = render(absent_path, name + "-absent", width, height)
        assert ImageChops.difference(image, control).crop((0, 0, width, height - 366)).getbbox(), "Roof faces did not render"
        assert not ImageChops.difference(image, control).crop((0, height - 366, width, height)).getbbox(), "Roof covers original controls"
    for pitch in [0, 0.66, 1.25]:
        assert ImageChops.difference(images[0, pitch], images[1, pitch]).getbbox(), "Roof materials did not change rendered faces"
    for pitch in [0, 1.25]:
        assert ImageChops.difference(images[0, pitch], images[0, 0.66]).getbbox(), "Roof pitch did not affect rendering"
    for fixture in [roofs["fixtures"][1], roofs["fixtures"][2]]:
        path = Path(fixture["scene"])
        absent = json.loads(path.read_text())
        absent["meshes"] = [mesh for mesh in absent["meshes"] if (mesh.get("roof") or {}).get("part") != "edge"]
        absent_path = path.with_name(path.stem + "-edges-absent.json")
        absent_path.write_text(json.dumps(absent))
        control = render(absent_path, path.stem + "-edges-absent", width, height)
        assert ImageChops.difference(images[fixture["style"], fixture["pitch"]], control).crop((0, 0, width, height - 366)).getbbox(), "Roof eaves did not render"
    render(roofs["fixtures"][1]["scene"], "roof-catalog", width, height, catalog=True)

result = {"result": "passed", "originalMaterials": True, "pitchEndpoints": True, "originalRoofCatalog": True,
          "livePresentationVerified": False, "renders": renders}
(root / "logs/native-roof-render-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps({key: value for key, value in result.items() if key != "renders"} | {"renderCount": len(renders)}))
