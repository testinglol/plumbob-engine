import copy
import json
from pathlib import Path
import subprocess

from PIL import Image, ImageChops

root = Path(__file__).resolve().parents[1]
runtime = json.loads((root / "logs/native-custom-object-result.json").read_text())
page_path = Path(runtime["buildCatalog"]["floor"]["fixture"])
page = json.loads(page_path.read_text())
wall_page = json.loads(Path(runtime["buildCatalog"]["wall"]["fixture"]).read_text())
style_page = json.loads(Path(runtime["buildCatalog"]["wallBuild"]["fixture"]).read_text())
state = Path(runtime["objectEditing"]["catalogFixture"]).parent / "catalog-state.json"
directory = root / "analysis/build-browser-check"
directory.mkdir(parents=True, exist_ok=True)
fallback = copy.deepcopy(page)
for item in fallback["items"]:
    item["icon"] = None
wall_fallback = copy.deepcopy(wall_page)
for item in wall_fallback["items"]:
    item["icon"] = None
style_fallback = copy.deepcopy(style_page)
for item in style_fallback["items"]:
    item["icon"] = None
renders = []
for width, height in [(1600, 960), (2400, 1800)]:
    images = {}
    for name, fixture in [("floor", page), ("fallback", fallback), ("brush", page), ("floor-delete", page), ("wall", wall_page), ("wall-fallback", wall_fallback), ("styles", style_page), ("styles-fallback", style_fallback), ("wall-brush", style_page), ("wall-rectangle", style_page), ("wall-delete", style_page)]:
        path = directory / (name + "-page.json")
        path.write_text(json.dumps(fixture))
        output = directory / f"{name}-{width}x{height}.png"
        brush = {
            "brush": ["--floor-brush", "18,16,19,17"],
            "floor-delete": ["--floor-brush", "18,16,19,17", "--floor-delete"],
            "wall-brush": ["--wall-brush", "18,16,21,16"],
            "wall-rectangle": ["--wall-brush", "18,16,21,18", "--wall-rectangle"],
            "wall-delete": ["--wall-brush", "18,16,21,16", "--wall-delete"],
        }.get(name, [])
        subprocess.run([str(root / "native/SimsNative/.build/release/SimsNative"), "--game", str(root / "runtime/game"), "--scene", runtime["scene"],
                        "--panel-state", str(state), "--build-catalog", str(path), "--width", str(width), "--height", str(height), "--render", str(output)] + brush, check=True, stdout=subprocess.DEVNULL)
        rendered = Image.open(output).convert("RGBA")
        world = rendered.crop((0, 0, width, height - 366))
        terrain_pixels = sum(1 for red, green, blue, alpha in world.getdata() if alpha >= 250 and green > red * 1.2 and green > blue * 1.2 and green > 40)
        assert terrain_pixels > width * height * 0.03, "Terrain is missing or transparent in the saved native render"
        images[name] = rendered.convert("RGB")
        renders.append(str(output))
    difference = ImageChops.difference(images["floor"], images["brush"])
    assert difference.getbbox(), "Floor drag footprint is missing"
    assert not difference.crop((0, height - 366, width, height)).getbbox(), "Floor brush covers original controls"
    assert ImageChops.difference(images["styles"].crop((1116, height - 190, 1206, height - 100)), images["styles-fallback"].crop((1116, height - 190, 1206, height - 100))).getbbox(), "Original wall style thumbnail is missing"
    wall_difference = ImageChops.difference(images["styles"], images["wall-brush"])
    assert wall_difference.getbbox(), "Wall line preview is missing"
    assert not wall_difference.crop((0, height - 366, width, height)).getbbox(), "Wall preview covers original controls"
    for name in ["wall-rectangle", "wall-delete"]:
        edit_difference = ImageChops.difference(images["styles"], images[name])
        assert edit_difference.getbbox(), f"{name} preview is missing"
        assert not edit_difference.crop((0, height - 366, width, height)).getbbox(), f"{name} preview covers original controls"
    assert ImageChops.difference(images["wall-brush"], images["wall-delete"]).getbbox(), "Wall deletion has no distinct intent color"
    removal_difference = ImageChops.difference(images["floor"], images["floor-delete"])
    assert removal_difference.getbbox(), "Floor removal preview is missing"
    assert not removal_difference.crop((0, height - 366, width, height)).getbbox(), "Floor removal preview covers original controls"
    assert ImageChops.difference(images["brush"], images["floor-delete"]).getbbox(), "Floor removal has no distinct intent color"
    columns = max(1, min(32, int((width / 2 - 562) / 45)))
    for index in range(columns * 2):
        x, y = 1116 + index % columns * 90, height - 190 + index // columns * 90
        bounds = (x, y, x + 90, y + 90)
        assert len(set(images["floor"].crop(bounds).getdata())) > 5, f"Floor pattern cell {index} is blank"
    first = (1116, height - 190, 1206, height - 100)
    assert ImageChops.difference(images["floor"].crop(first), images["fallback"].crop(first)).getbbox(), "Original floor thumbnail is missing"
    assert ImageChops.difference(images["wall"].crop(first), images["wall-fallback"].crop(first)).getbbox(), "Original wallpaper thumbnail is missing"
    wallpaper_tool = (816, height - 194, 900, height - 110)
    assert ImageChops.difference(images["floor"].crop(wallpaper_tool), images["wall"].crop(wallpaper_tool)).getbbox(), "Original wallpaper tool selection is missing"
    floor_tool = (634, height - 72, 720, height - 16)
    assert len(set(images["floor"].crop(floor_tool).getdata())) > 30, "Original floor tool artwork is missing"
result = {"result": "passed", "renders": renders, "originalFloorThumbnails": True, "originalToolArtwork": True, "originalWallpaperCatalog": True, "wallStyleCatalog": True, "wallLinePreview": True, "wallRectanglePreview": True, "wallDeletionPreview": True, "opaqueTerrainCoverage": True, "floorDragFootprint": True, "floorRemovalFootprint": True, "livePresentationVerified": False}
(root / "logs/native-build-catalog-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result))
