import json
from pathlib import Path
import subprocess
import struct
import base64

from PIL import Image


root = Path(__file__).resolve().parents[1]
output = root / "analysis/depth-check"
output.mkdir(parents=True, exist_ok=True)
(output / "color.rgba").write_bytes(bytes([255, 0, 0, 255] * 3 + [255, 0, 0, 0]))
(output / "blue.rgba").write_bytes(bytes([0, 0, 255, 255]))
(output / "green.rgba").write_bytes(bytes([0, 255, 0, 255]))
(output / "pixels.depth8").write_bytes(bytes([0, 254, 255, 0]))


def vertex(x, y):
    return {"x": x, "y": y, "z": 0.5, "u": 0, "v": 0, "nx": 0, "ny": 1, "nz": 0}


results = []
for size in [128, 512]:
    for static_wall in [False, True]:
        for flip in [False, True]:
            for sprite_first in [False, True]:
                name = f"{size}-wall-{int(static_wall)}-flip-{int(flip)}-sprite-first-{int(sprite_first)}"
                scene = {
                    "schemaVersion": 1, "house": 1, "width": 64, "height": 64, "limitations": [],
                    "textures": [
                        {"file": "color.rgba", "width": 4, "height": 1},
                        {"file": "blue.rgba", "width": 1, "height": 1},
                        {"file": "pixels.depth8", "width": 4, "height": 1, "encoding": "depth8"}],
                    "sprites": [{"texture": 0, "x": 4, "y": 4, "width": 56, "height": 56, "flip": flip,
                                 "layer": 1, "depth": 0 if sprite_first else 2, "objectID": 42,
                                 "depthTexture": 2, "depthNear": 0.3, "depthFar": 0.7}],
                    "meshes": [{"texture": 1, "objectID": 43, "depth": 1,
                                "vertices": [vertex(4, 4), vertex(60, 4), vertex(4, 60),
                                             vertex(4, 60), vertex(60, 4), vertex(60, 60)]}]}
                if static_wall:
                    scene["lotWidth"] = 1
                    scene["lotHeight"] = 1
                    scene["terrainVertices"] = [{"x": 0, "y": 0, "r": 0, "g": 0, "b": 0}] * 6
                    scene["sprites"][0]["objectID"] = 0
                    scene["sprites"][0]["architectureDepth"] = {"x": 0, "y": 0, "level": 1, "configuration": 4}
                scene_file = output / (name + ".json")
                scene_file.write_text(json.dumps(scene))
                png = output / (name + ".png")
                subprocess.run([str(root / "native/SimsNative/.build/release/SimsNative"),
                                "--game", str(root / "runtime/game"), "--packs", str(root / "packs"),
                                "--scene", str(scene_file), "--reload-scene", str(scene_file),
                                "--render", str(png), "--width", str(size), "--height", str(size)],
                               check=True, capture_output=True, text=True)
                with Image.open(png) as image:
                    pixels = [image.getpixel((round((0.03 + x / 64 * 0.94) * size), size // 2))
                              for x in [11, 25, 39, 53]]
                expected_red = 3 if flip else 0
                for index, pixel in enumerate(pixels):
                    if index == expected_red:
                        assert pixel[0] > 200 and pixel[2] < 20, (name, index, pixel, "near sprite must cover mesh")
                    else:
                        assert pixel[2] > 150 and pixel[0] < 20, (name, index, pixel, "mesh must cover far/sentinel/transparent pixels")
                results.append({"case": name, "pixels": pixels, "passed": True})
                if size == 128:
                    packed = b"".join(struct.pack("<8f", point["x"], point["y"], point["z"], point["u"], point["v"], point["nx"], point["ny"], point["nz"]) for point in scene["meshes"][0]["vertices"])
                    animation = {"schemaVersion": 1, "baseRevision": 1, "sequence": 1, "updates": 2,
                        "textureStart": 3, "textures": [{"file": "green.rgba", "width": 1, "height": 1, "encoding": "rgba"}],
                        "sprites": [] if static_wall else scene["sprites"], "meshes": [{"texture": 3, "objectID": 43, "depth": 1, "vertices": base64.b64encode(packed).decode()}]}
                    animation_file = output / (name + "-animation.json")
                    animation_file.write_text(json.dumps(animation))
                    animated_png = output / (name + "-animation.png")
                    subprocess.run([str(root / "native/SimsNative/.build/release/SimsNative"),
                                    "--game", str(root / "runtime/game"), "--scene", str(scene_file),
                                    "--animation", str(animation_file), "--render", str(animated_png),
                                    "--width", str(size), "--height", str(size)], check=True, capture_output=True, text=True)
                    with Image.open(animated_png) as image:
                        animated_pixels = [image.getpixel((round((0.03 + x / 64 * 0.94) * size), size // 2)) for x in [11, 25, 39, 53]]
                    for index, pixel in enumerate(animated_pixels):
                        if index == expected_red:
                            assert pixel[0] > 200 and pixel[1] < 20, (name, index, pixel, "streamed mesh lost sprite depth")
                        else:
                            assert pixel[1] > 150 and pixel[0] < 20, (name, index, pixel, "appended animation texture was not rendered")
                    results.append({"case": name + "-animation", "pixels": animated_pixels, "passed": True})
(root / "logs/native-depth-result.json").write_text(json.dumps(results, indent=2) + "\n")
print(f"Passed {len(results)} Metal depth checks: draw orders, flipped UVs, transparency, sentinel, two resolutions, static wall preservation and streamed meshes with appended textures.")
