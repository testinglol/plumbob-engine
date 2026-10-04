import json
from pathlib import Path
import time
import uuid


def check_water(request, catalog):
    baseline = request("state")
    directory = Path(request("scene")).parent
    page = request("buildCatalogPage", kind="water", offset=0, count=64)
    expected = sorted([item for item in catalog["floors"] if item["id"] >= 65534], key=lambda item: (item["price"], item["id"]))
    patterns = [item for item in page["items"] if item.get("guid") is None]
    accessories = [item for item in page["items"] if item.get("guid") is not None]
    expected_accessories = sorted([item for item in catalog["objects"] if item["category"] == 14], key=lambda item: (item["price"], item["guid"]))
    assert page["total"] == len(expected) + len(expected_accessories) and [item["id"] for item in patterns] == [item["id"] for item in expected]
    assert [item["guid"] for item in accessories] == [item["guid"] for item in expected_accessories]
    assert all(item["icon"] and item["icon"]["columns"] == 1 for item in patterns)
    assert all(item["id"] == 0 and item["icon"] for item in accessories)
    page_path = directory / "build-water-page.json"
    page_path.write_text(json.dumps(page))
    assert not request("buildCatalogPage", kind="water", offset=page["total"], count=64)["items"]
    width, height = baseline["width"], baseline["height"]
    occupied = {(int(obj["x"]), int(obj["y"])) for obj in baseline["objects"] if obj["level"] == 1}
    origin = next((x, y) for y in range(2, height - 5) for x in range(2, width - 5)
                  if all(baseline["buildable"][ty * width + tx] and baseline["floors"][ty * width + tx] == 0 and baseline["walls"][ty * width + tx]["segments"] == 0 and (tx, ty) not in occupied
                         for ty in range(y, y + 3) for tx in range(x, x + 3)))
    x, y = origin
    indices = [(y + dy) * width + x + dx for dy in range(3) for dx in range(3)]
    center = (y + 1) * width + x + 1
    slot = "water-" + uuid.uuid4().hex
    request("save", slot=slot)
    cases = []

    def wait_for(floors):
        for attempt in range(40):
            state = request("state")
            if state["floors"] == floors:
                return state
            time.sleep(0.02)
        raise AssertionError("Water edit did not match the expected floor grid")

    def snapshot(label, floors):
        path = Path(request("scene"))
        scene = json.loads(path.read_text())
        assert not any(value in scene["missingResources"] for value in ["floor:65534", "floor:65535"])
        meshes = [mesh for mesh in scene["meshes"] if (mesh.get("floor") or {}).get("pattern", 0) >= 65534]
        corners = set()
        sprites = set()
        directions = [(0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1)]
        for mesh in meshes:
            floor = mesh["floor"]
            tx, ty, pattern = floor["x"], floor["y"], floor["pattern"]
            assert floors[ty * width + tx] == pattern
            mask = sum(1 << index for index, (dx, dy) in enumerate(directions)
                       if tx + dx <= 0 or ty + dy <= 0 or tx + dx >= width - 1 or ty + dy >= height - 1 or floors[(ty + dy) * width + tx + dx] == pattern)
            variant = (bool(mask & 1) + 2 * bool(mask & 64) + 4 * bool(mask & 16) + 8 * bool(mask & 4))
            expected_corners = [0x434 + index for index, (pair, diagonal) in enumerate([(65, 128), (80, 32), (20, 8), (5, 2)]) if mask & pair == pair and not mask & diagonal] if pattern == 65535 else []
            assert floor["water"] == {"adjacency": mask, "sprite": (0x410 if pattern == 65535 else 0x800) + variant, "corners": expected_corners}
            assert len(mesh["vertices"]) == 6 and mesh["objectID"] == 0 and mesh["unlit"] and mesh["layer"] == 0
            texture = scene["textures"][mesh["texture"]]
            pixels = (directory / texture["file"]).read_bytes()
            assert texture["encoding"] == "rgba" and len(pixels) == texture["width"] * texture["height"] * 4
            assert any(pixels[index] for index in range(3, len(pixels), 4)), "Water artwork is entirely transparent"
            corners.update(expected_corners)
            sprites.add(floor["water"]["sprite"])
        assert len(meshes) == sum(pattern >= 65534 for pattern in floors)
        fixture = directory / (label + ".json")
        fixture.write_text(json.dumps(scene))
        return {"scene": str(fixture), "tiles": len(meshes), "sprites": sorted(sprites), "corners": sorted(corners)}

    try:
        for item in patterns:
            request("load", slot=slot)
            pattern, price = item["id"], item["price"]
            assert baseline["budget"] >= price * 9
            floors = list(baseline["floors"])
            for index in indices:
                floors[index] = pattern
            request("architecture", command="FLOOR_RECT", x=x, y=y, level=1, x2=2, y2=2, pattern=pattern, style=0)
            full = wait_for(floors)
            assert full["walls"] == baseline["walls"] and full["objects"] == baseline["objects"]
            assert full["budget"] == baseline["budget"] - price * 9
            full_fixture = snapshot("water-full-" + str(pattern), floors)
            floors[center] = 0
            request("architecture", command="FLOOR_RECT", x=x + 1, y=y + 1, level=1, x2=0, y2=0, pattern=0, style=0)
            ring = wait_for(floors)
            assert ring["budget"] == full["budget"] + price - price // 5
            ring_fixture = snapshot("water-ring-" + str(pattern), floors)
            if pattern == 65535:
                assert ring_fixture["corners"] == [0x434, 0x435, 0x436, 0x437], "Concave pool edges did not use all four original inner-corner sprites"
            request("save", slot=slot + "-" + str(pattern))
            request("load", slot=slot)
            persisted = request("load", slot=slot + "-" + str(pattern))
            assert persisted["floors"] == ring["floors"] and persisted["budget"] == ring["budget"] and persisted["walls"] == ring["walls"]
            other = next(value for value in patterns if value["id"] != pattern)
            floors[indices[0]] = other["id"]
            request("architecture", command="FLOOR_RECT", x=x, y=y, level=1, x2=0, y2=0, pattern=other["id"], style=0)
            mixed = wait_for(floors)
            assert mixed["budget"] == ring["budget"] + price - price // 5 - other["price"]
            mixed_fixture = snapshot("water-mixed-" + str(pattern), floors)
            for index in indices:
                floors[index] = 0
            request("architecture", command="FLOOR_RECT", x=x, y=y, level=1, x2=2, y2=2, pattern=0, style=0)
            removed = wait_for(floors)
            assert removed["budget"] == mixed["budget"] + (price - price // 5) * 7 + other["price"] - other["price"] // 5
            assert removed["walls"] == baseline["walls"] and removed["objects"] == baseline["objects"]
            removed_fixture = snapshot("water-removed-" + str(pattern), floors)
            cases.append({"pattern": pattern, "price": price, "full": full_fixture, "ring": ring_fixture, "mixed": mixed_fixture, "removed": removed_fixture, "saveLoad": True, "costAndRefund": True})
    finally:
        restored = request("load", slot=slot)
        assert restored["floors"] == baseline["floors"] and restored["budget"] == baseline["budget"] and restored["walls"] == baseline["walls"]
    return {"fixture": str(page_path), "origin": list(origin), "cases": cases}
