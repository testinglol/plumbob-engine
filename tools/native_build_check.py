import json
from pathlib import Path
import struct
import time
import uuid

from native_room_fill_check import check_room_fill
from native_wall_build_check import check_wall_build
from native_floor_mesh_check import check_floor_meshes
from native_build_object_check import check_build_objects
from native_water_check import check_water
from native_pool_accessory_check import check_pool_accessories


def check_build_catalog(request, catalog):
    baseline = request("state")
    scene = Path(request("scene"))
    pages = {}
    for kind, source in [("floor", "floors"), ("wall", "walls")]:
        expected = sorted([item for item in catalog[source] if 0 < item["id"] < 65534 and item["price"] >= 0], key=lambda item: (item["price"], item["id"]))
        page = request("buildCatalogPage", kind=kind, offset=0, count=64)
        assert page["schemaVersion"] == 1 and page["kind"] == kind and page["total"] == len(expected)
        assert [item["id"] for item in page["items"]] == [item["id"] for item in expected[:64]]
        assert all(item["price"] == expected[index]["price"] and item["name"] == expected[index]["name"] for index, item in enumerate(page["items"]))
        icons = [item["icon"] for item in page["items"] if item["icon"]]
        assert icons, f"{kind} patterns have no original thumbnails"
        for icon in icons:
            data = (scene.parent / icon["file"]).read_bytes()
            assert data[:2] == b"BM" and len(data) <= 4 * 1024 * 1024
            width, height = struct.unpack_from("<ii", data, 18)
            assert 0 < width <= 512 and 0 < abs(height) <= 512
        empty = request("buildCatalogPage", kind=kind, offset=len(expected), count=64)
        assert not empty["items"] and empty["total"] == len(expected)
        path = scene.parent / f"build-{kind}-page.json"
        path.write_text(json.dumps(page))
        pages[kind] = {"total": len(expected), "icons": len(icons), "fixture": str(path)}
    for parameters in [{"kind": "unknown", "offset": 0, "count": 1}, {"kind": "floor", "offset": -1, "count": 1}, {"kind": "wall", "offset": 0, "count": 65}]:
        try:
            request("buildCatalogPage", **parameters)
        except RuntimeError:
            pass
        else:
            raise AssertionError(f"Invalid build catalog request accepted: {parameters}")
    assert request("state") == baseline, "Reading build patterns mutated simulation state"
    width = baseline["width"]
    index = next(index for index in range(len(baseline["floors"]) - width - 1)
                 if index % width < width - 1 and all(0 < baseline["floors"][tile] < 65534 and baseline["buildable"][tile]
                 for tile in [index, index + 1, index + width, index + width + 1]))
    tiles = [index, index + 1, index + width, index + width + 1]
    pattern = next(item for item in catalog["floors"] if 0 < item["id"] < 65534
                   and all(item["id"] != baseline["floors"][tile] for tile in tiles)
                   and 0 <= item["price"] * 4 <= baseline["budget"])
    slot = "build-" + uuid.uuid4().hex
    request("save", slot=slot)
    try:
        request("architecture", command="FLOOR_RECT", x=index % baseline["width"], y=index // baseline["width"], level=1, x2=1, y2=1, pattern=pattern["id"], style=0)
        for attempt in range(30):
            edited = request("state")
            if all(edited["floors"][tile] == pattern["id"] for tile in tiles):
                break
            time.sleep(0.02)
        assert all(edited["floors"][tile] == pattern["id"] for tile in tiles), "Native floor rectangle did not paint all four tiles"
        assert all(edited["floors"][tile] == baseline["floors"][tile] for tile in range(len(baseline["floors"])) if tile not in tiles), "Floor rectangle changed tiles outside its bounds"
        exported = json.loads(Path(request("scene")).read_text())
        assert exported["sprites"], "Painted lot has no rendered scene"
        request("architecture", command="FLOOR_RECT", x=index % baseline["width"], y=index // baseline["width"], level=1, x2=1, y2=1, pattern=0, style=0)
        for attempt in range(30):
            removed = request("state")
            if all(removed["floors"][tile] == 0 for tile in tiles):
                break
            time.sleep(0.02)
        assert all(removed["floors"][tile] == 0 for tile in tiles), "Floor rectangle removal missed selected tiles"
        assert all(removed["floors"][tile] == edited["floors"][tile] for tile in range(len(removed["floors"])) if tile not in tiles)
        old_cost = pattern["price"] * len(tiles) * 2
        assert removed["budget"] == edited["budget"] + (old_cost - old_cost // 5) // 2, f"Floor removal budget: {removed['budget']}, before: {edited['budget']}, expected refund: {(old_cost - old_cost // 5) // 2}, pattern: {pattern}"
        request("save", slot=slot + "-removed")
        request("load", slot=slot)
        persisted_removal = request("load", slot=slot + "-removed")
        assert persisted_removal["floors"] == removed["floors"] and persisted_removal["budget"] == removed["budget"]
        pages["paint"] = {"pattern": pattern["id"], "tile": [index % baseline["width"], index // baseline["width"]], "tileCount": len(tiles), "extent": [1, 1], "applied": True, "removal": True, "removalSaveLoad": True}
    finally:
        restored = request("load", slot=slot)
        assert restored["floors"] == baseline["floors"] and restored["budget"] == baseline["budget"]
    baseline = request("state")
    exported = json.loads(Path(request("scene")).read_text())
    side = next(sprite["wall"] for sprite in exported["sprites"] if sprite.get("wall") and baseline["buildable"][sprite["wall"]["y"] * baseline["width"] + sprite["wall"]["x"]])
    index = side["y"] * baseline["width"] + side["x"]
    segment = baseline["walls"][index]["segments"]
    field = "bottomRightPattern" if segment & 48 else ["topLeftPattern", "topRightPattern", "bottomRightPattern", "bottomLeftPattern"][side["direction"]]
    pattern = next(item for item in catalog["walls"] if 0 < item["id"] < 65534 and item["id"] != baseline["walls"][index][field] and 0 <= item["price"] <= baseline["budget"])
    slot = "wall-" + uuid.uuid4().hex
    request("save", slot=slot)
    try:
        request("architecture", command="PATTERN_DOT", x=side["x"], y=side["y"], level=side["level"], x2=side["direction"], y2=side["direction"], pattern=pattern["id"], style=0)
        for attempt in range(30):
            edited = request("state")
            if edited["walls"][index][field] == pattern["id"]:
                break
            time.sleep(0.02)
        expected = json.loads(json.dumps(baseline["walls"]))
        expected[index][field] = pattern["id"]
        assert edited["walls"] == expected, "Wallpaper command did not change exactly the selected wall surface"
        assert edited["floors"] == baseline["floors"], "Wallpaper changed floor patterns"
        request("save", slot=slot + "-painted")
        restored = request("load", slot=slot)
        assert restored["walls"] == baseline["walls"] and restored["budget"] == baseline["budget"]
        persisted = request("load", slot=slot + "-painted")
        assert persisted["walls"] == expected and persisted["budget"] == edited["budget"]
        request("architecture", command="PATTERN_DOT", x=side["x"], y=side["y"], level=side["level"], x2=side["direction"], y2=side["direction"], pattern=0, style=0)
        expected_removal = json.loads(json.dumps(expected))
        expected_removal[index][field] = 0
        for attempt in range(30):
            removed = request("state")
            if removed["walls"] == expected_removal:
                break
            time.sleep(0.02)
        assert removed["walls"] == expected_removal and removed["floors"] == baseline["floors"], "Wallpaper removal changed unexpected architecture"
        assert removed["budget"] == edited["budget"] + pattern["price"] - pattern["price"] // 5
        request("save", slot=slot + "-removed")
        request("load", slot=slot)
        persisted_removal = request("load", slot=slot + "-removed")
        assert persisted_removal["walls"] == expected_removal and persisted_removal["budget"] == removed["budget"]
        pages["wallPaint"] = {"pattern": pattern["id"], "side": side, "field": field, "applied": True, "saveLoad": True, "removal": True, "removalSaveLoad": True}
    finally:
        restored = request("load", slot=slot)
        assert restored["walls"] == baseline["walls"] and restored["budget"] == baseline["budget"]
    pages["roomFill"] = check_room_fill(request, catalog)
    pages["wallBuild"] = check_wall_build(request)
    pages["floorMeshes"] = check_floor_meshes(request, catalog)
    pages["objects"] = check_build_objects(request, catalog)
    pages["water"] = check_water(request, catalog)
    pages["poolAccessories"] = check_pool_accessories(request, pages["water"])
    return pages
