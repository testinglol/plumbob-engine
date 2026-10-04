import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops

root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
fixture = runtime["buildCatalog"]["floorMeshes"]
page = runtime["buildCatalog"]["floor"]["fixture"]
directory = root / "analysis/diagonal-floor-brush-check"
directory.mkdir(parents=True, exist_ok=True)
renders = []
for label, index in [("vertical", 1), ("horizontal", 2)]:
    source = fixture["fixtures"][index]
    target = fixture["targets"][index]
    scene = json.loads(Path(source).read_text())
    tile = target["y"] * scene["lotWidth"] + target["x"]
    terrain = scene["terrainVertices"][tile * 6:tile * 6 + 6]
    for width, height in [(1600, 960), (2400, 1800)]:
        images = {}
        modes = [("baseline", None, False)] + [("half-" + str(half), half, False) for half in target["halves"]] + [("removal", target["halves"][0], True)]
        for name, half, removing in modes:
            output = directory / f"{label}-{name}-{width}x{height}.png"
            brush = [] if half is None else ["--floor-brush", f"{target['x']},{target['y']},{target['x']},{target['y']}", "--floor-half", str(half)] + (["--floor-delete"] if removing else [])
            subprocess.run([str(root / "native/SimsNative/.build/release/SimsNative"), "--game", str(root / "runtime/game"), "--scene", source, "--build-catalog", page, "--width", str(width), "--height", str(height), "--render", str(output)] + brush, check=True, stdout=subprocess.DEVNULL)
            images[name] = Image.open(output).convert("RGB")
            renders.append(str(output))
        scale = min(width / scene["width"], (height - 300) / scene["height"]) * 0.94
        origin = ((width - scene["width"] * scale) / 2, (height - 300 - scene["height"] * scale) / 2)
        for name, half, removing in modes[1:]:
            difference = ImageChops.difference(images["baseline"], images[name])
            bounds = difference.getbbox()
            assert bounds, "Diagonal half preview is missing"
            indices = {1: [0, 1, 2], 2: [3, 4, 5], 3: [0, 1, 4], 4: [1, 2, 4]}[half]
            points = [(terrain[index]["x"] * scale + origin[0], terrain[index]["y"] * scale + origin[1]) for index in indices]
            a, b, c = points
            ab = (b[0] - a[0], b[1] - a[1])
            ac = (c[0] - a[0], c[1] - a[1])
            determinant = ab[0] * ac[1] - ab[1] * ac[0]
            center = (int(sum(point[0] for point in points) / 3), int(sum(point[1] for point in points) / 3))
            background = images["baseline"].getpixel(center)
            actual = images[name].getpixel(center)
            tint = (0.35, 0.12, 0.02) if removing else (0.06, 0.12, 0.32)
            def linear(value):
                value /= 255
                return value / 12.92 if value <= 0.04045 else ((value + 0.055) / 1.055) ** 2.4
            def encoded(value):
                return round(255 * (12.92 * value if value <= 0.0031308 else 1.055 * value ** (1 / 2.4) - 0.055))
            expected = tuple(encoded(linear(channel) * 0.6 + overlay) for channel, overlay in zip(background, tint))
            assert all(abs(value - wanted) <= 3 for value, wanted in zip(actual, expected)), "Half preview does not preserve underlying texture with 40% opacity"
            for y in range(bounds[1], bounds[3]):
                for x in range(bounds[0], bounds[2]):
                    if difference.getpixel((x, y)) == (0, 0, 0):
                        continue
                    ap = (x + 0.5 - a[0], y + 0.5 - a[1])
                    u = (ap[0] * ac[1] - ap[1] * ac[0]) / determinant
                    v = (ab[0] * ap[1] - ab[1] * ap[0]) / determinant
                    assert min(u, v, 1 - u - v) >= -0.01, "Preview alters pixels outside the cursor-selected half"
        assert ImageChops.difference(images["half-" + str(target["halves"][0])], images["removal"]).getbbox(), "Removal intent color is missing"
result = {"result": "passed", "allFourHalfPreviews": True, "removalIntent": True, "translucentOriginalTexture": True, "renders": renders, "livePresentationVerified": False}
(root / "logs/native-diagonal-floor-brush-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result))
