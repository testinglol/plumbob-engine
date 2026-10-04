import json
from pathlib import Path
import time
import uuid


def check_wall_build(request):
    page = request("buildCatalogPage", kind="wallStyle", offset=0, count=64)
    assert page["schemaVersion"] == 1 and page["kind"] == "wallStyle" and page["total"] == 5
    assert {item["id"] for item in page["items"]} == {1, 2, 12, 13, 14}
    assert all(item["price"] >= 0 and 0 <= item["pattern"] < 65534 for item in page["items"])
    assert all(item["icon"] and item["icon"]["columns"] == 2 and item["icon"]["rows"] == 1 for item in page["items"]), "Wall style thumbnail strips lack frame metadata"
    scene_path = Path(request("scene"))
    fixture = scene_path.parent / "build-wall-style-page.json"
    fixture.write_text(json.dumps(page))
    baseline = request("state")
    width = baseline["width"]
    start = next((x, y) for y in range(6, baseline["height"] - 6) for x in range(6, width - 6)
                 if all(baseline["buildable"][yy * width + xx] and not baseline["terrainSloped"][yy * width + xx] and baseline["walls"][yy * width + xx]["segments"] == 0 and baseline["floors"][yy * width + xx] == 0
                        for yy in range(y - 4, y + 5) for xx in range(x - 4, x + 5))
                 and not any(abs(obj["x"] - x) < 5 and abs(obj["y"] - y) < 5 for obj in baseline["objects"]))
    offsets = [(0, 0), (0, 0), (0, 0), (-1, 0), (-1, 0), (-1, -1), (0, -1), (0, -1)]
    steps = [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]
    bits = [2, 32, 1, 16, 2, 32, 1, 16]
    slot = "wall-build-" + uuid.uuid4().hex
    request("save", slot=slot)
    checked = []
    try:
        for item in page["items"]:
            for direction in range(8) if item["id"] == 1 else [0]:
                request("load", slot=slot)
                expected = json.loads(json.dumps(baseline["walls"]))
                x, y = start[0] + offsets[direction][0], start[1] + offsets[direction][1]
                for offset in range(3):
                    tile = expected[y * width + x]
                    tile["segments"] |= bits[direction]
                    if direction % 2:
                        tile["topRightStyle"] = item["id"]
                        tile["bottomLeftPattern"] = tile["bottomRightPattern"] = item["pattern"]
                        tile["topLeftStyle"] = tile["topLeftPattern"] = 0
                    else:
                        field = "topRight" if bits[direction] == 2 else "topLeft"
                        tile[field + "Style"] = item["id"]
                        tile[field + "Pattern"] = item["pattern"]
                        neighbor = expected[(y - 1) * width + x] if bits[direction] == 2 else expected[y * width + x - 1]
                        neighbor["segments"] |= 8 if bits[direction] == 2 else 4
                        neighbor["bottomLeftPattern" if bits[direction] == 2 else "bottomRightPattern"] = item["pattern"]
                    x += steps[direction][0]
                    y += steps[direction][1]
                request("architecture", command="WALL_LINE", x=start[0], y=start[1], level=1, x2=3, y2=direction, pattern=item["pattern"], style=item["id"])
                for attempt in range(40):
                    edited = request("state")
                    if edited["walls"] == expected:
                        break
                    time.sleep(0.02)
                assert edited["walls"] == expected, f"Wall style {item['id']} direction {direction} mismatch: " + str([(index, wanted, edited["walls"][index]) for index, wanted in enumerate(expected) if wanted != edited["walls"][index]][:8])
                assert edited["floors"] == baseline["floors"]
                assert edited["budget"] == baseline["budget"] - item["price"] * 3
                painted_slot = slot + "-painted"
                request("save", slot=painted_slot)
                request("load", slot=slot)
                persisted = request("load", slot=painted_slot)
                assert persisted["walls"] == expected and persisted["budget"] == edited["budget"]
                scene = json.loads(Path(request("scene")).read_text())
                assert scene["wallSprites"] > 0 and not any(value.startswith("wall:" + str(item["pattern"]) + ":style:" + str(item["id"]) + ":") for value in scene["missingResources"]), "New walls lack render resources"
                deleted = json.loads(json.dumps(expected))
                x, y = start[0] + offsets[direction][0], start[1] + offsets[direction][1]
                for offset in range(3):
                    indices = [(y * width + x, bits[direction])]
                    if direction % 2 == 0:
                        indices.append(((y - 1) * width + x, 8) if bits[direction] == 2 else (y * width + x - 1, 4))
                    for index, bit in indices:
                        deleted[index]["segments"] &= ~bit
                        if deleted[index]["segments"] == 0:
                            deleted[index] = {key: 0 for key in deleted[index]}
                    x += steps[direction][0]
                    y += steps[direction][1]
                request("architecture", command="WALL_DELETE", x=start[0], y=start[1], level=1, x2=3, y2=direction, pattern=item["pattern"], style=item["id"])
                for attempt in range(40):
                    removed = request("state")
                    if removed["walls"] == deleted:
                        break
                    time.sleep(0.02)
                assert removed["walls"] == deleted and removed["floors"] == baseline["floors"], "Wall deletion removed unexpected architecture"
                assert removed["budget"] == edited["budget"] + 21, "Wall deletion did not refund the canonical seven simoleons per segment"
                request("save", slot=painted_slot + "-deleted")
                request("load", slot=slot)
                persisted_delete = request("load", slot=painted_slot + "-deleted")
                assert persisted_delete["walls"] == deleted and persisted_delete["budget"] == removed["budget"]
                checked.append({"style": item["id"], "direction": direction, "segments": 3, "cost": item["price"] * 3, "saveLoad": True, "deletion": True, "deletionRefund": 21})
        rectangles = []
        for item in page["items"]:
            request("load", slot=slot)
            expected = json.loads(json.dumps(baseline["walls"]))
            for x, y, length, direction in [(start[0], start[1], 3, 0), (start[0], start[1], 2, 2), (start[0], start[1] + 2, 3, 0), (start[0] + 3, start[1], 2, 2)]:
                for offset in range(length):
                    tile = expected[y * width + x]
                    bit = 2 if direction == 0 else 1
                    field = "topRight" if direction == 0 else "topLeft"
                    tile["segments"] |= bit
                    tile[field + "Style"] = item["id"]
                    tile[field + "Pattern"] = item["pattern"]
                    neighbor = expected[(y - 1) * width + x] if direction == 0 else expected[y * width + x - 1]
                    neighbor["segments"] |= 8 if direction == 0 else 4
                    neighbor["bottomLeftPattern" if direction == 0 else "bottomRightPattern"] = item["pattern"]
                    x += 1 if direction == 0 else 0
                    y += 1 if direction == 2 else 0
            request("architecture", command="WALL_RECT", x=start[0], y=start[1], level=1, x2=3, y2=2, pattern=item["pattern"], style=item["id"])
            for attempt in range(40):
                edited = request("state")
                if edited["walls"] == expected:
                    break
                time.sleep(0.02)
            assert edited["walls"] == expected and edited["floors"] == baseline["floors"], "Wall rectangle does not match its ten-segment perimeter"
            assert edited["budget"] == baseline["budget"] - item["price"] * 10
            request("save", slot=slot + "-rectangle")
            request("load", slot=slot)
            persisted = request("load", slot=slot + "-rectangle")
            assert persisted["walls"] == expected and persisted["budget"] == edited["budget"]
            rectangles.append({"style": item["id"], "segments": 10, "cost": item["price"] * 10, "saveLoad": True})
    finally:
        restored = request("load", slot=slot)
        assert restored["walls"] == baseline["walls"] and restored["floors"] == baseline["floors"] and restored["budget"] == baseline["budget"]
    return {"fixture": str(fixture), "styles": page["total"], "checks": checked, "rectangles": rectangles}
