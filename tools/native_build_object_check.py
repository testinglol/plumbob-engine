import json
import math
from pathlib import Path
import time
import uuid


def check_build_objects(request, catalog):
    baseline = request("state")
    scene = Path(request("scene"))
    slot = "build-objects-" + uuid.uuid4().hex
    request("save", slot=slot)
    checks = []
    try:
        for tool, category in [("door", 8), ("window", 9), ("stairs", 10), ("plants", 11), ("fireplace", 12)]:
            request("load", slot=slot)
            expected = sorted([item for item in catalog["objects"] if item["category"] == category], key=lambda item: (item["price"], item["guid"]))
            page = request("catalogPage", category=category, offset=0, count=64)
            assert expected and page["total"] == len(expected)
            assert [item["guid"] for item in page["items"]] == [item["guid"] for item in expected[:64]]
            assert all(item["category"] == category for item in page["items"])
            assert any(item["icon"] for item in page["items"]), f"Missing original {tool} thumbnails"
            fixture = scene.parent / ("build-objects-" + tool + ".json")
            fixture.write_text(json.dumps(page))
            if page["total"] > 4:
                partial = request("catalogPage", category=category, offset=4, count=2)
                assert [item["guid"] for item in partial["items"]] == [item["guid"] for item in expected[4:6]]
            assert not request("catalogPage", category=category, offset=page["total"], count=64)["items"]
            item = next(item for item in page["items"] if 0 < item["price"] <= baseline["budget"])
            width = baseline["width"]
            tiles = [(index % width, index // width) for index, allowed in enumerate(baseline["buildable"]) if allowed]
            if tool in ["door", "window", "fireplace"]:
                tiles = [tile for tile in tiles if baseline["walls"][tile[1] * width + tile[0]]["segments"] & 3]
            placement = None
            for x, y in tiles[:100]:
                for direction in [1, 4, 16, 64]:
                    preview = request("previewObject", guid=item["guid"], x=x * 16 + 8, y=y * 16 + 8, level=1, direction=direction)
                    if preview["valid"]:
                        placement = x, y, direction, preview
                        break
                if placement:
                    break
            assert placement, f"No tested tile accepted the original {tool}: {item['name']}"
            x, y, direction, preview = placement
            assert preview["ghost"] and preview["tiles"]
            (scene.parent / ("build-objects-" + tool + "-preview.json")).write_text(json.dumps(preview))
            after_preview = request("state")
            if after_preview != baseline:
                (scene.parent / ("build-objects-" + tool + "-mutation.json")).write_text(json.dumps({"before": baseline, "after": after_preview}))
            assert after_preview == baseline, f"{tool} preview mutated the VM"
            before_ids = {obj["id"] for obj in baseline["objects"]}
            request("buyObject", guid=item["guid"], x=x * 16 + 8, y=y * 16 + 8, level=1, direction=direction)
            for attempt in range(50):
                state = request("state")
                added = [obj for obj in state["objects"] if obj["id"] not in before_ids]
                if added:
                    break
                time.sleep(0.02)
            assert added and state["budget"] == baseline["budget"] - item["price"], f"{tool} purchase failed or charged the wrong amount"
            purchase_scene = json.loads(Path(request("scene")).read_text())
            assert any(sprite["objectID"] in {obj["id"] for obj in added} for sprite in purchase_scene["sprites"]), f"{tool} was not exported"
            movable = next(obj for obj in added if obj["movable"])
            moved_preview = None
            for mx, my in tiles[:100]:
                if (mx, my) == (x, y):
                    continue
                for md in [value for value in [1, 4, 16, 64] if value != direction]:
                    candidate = request("previewObject", objectID=movable["id"], x=mx * 16 + 8, y=my * 16 + 8, level=1, direction=md)
                    if candidate["valid"]:
                        moved_preview = mx, my, md, candidate
                        break
                if moved_preview:
                    break
            assert moved_preview, f"No alternate tile and orientation accepted the original {tool}"
            mx, my, md, candidate = moved_preview
            assert request("state") == state, f"{tool} move preview mutated the VM"
            request("moveObject", objectID=movable["id"], x=mx * 16 + 8, y=my * 16 + 8, level=1, direction=md)
            expected_tiles = {(tile["x"], tile["y"], tile["level"]) for tile in candidate["tiles"]}
            for attempt in range(50):
                moved = request("state")
                group = [obj for obj in moved["objects"] if obj["id"] not in before_ids]
                actual_tiles = {(math.floor(obj["x"]), math.floor(obj["y"]), obj["level"]) for obj in group}
                if actual_tiles == expected_tiles and all(obj["direction"] == md for obj in group):
                    break
                time.sleep(0.02)
            assert actual_tiles == expected_tiles and all(obj["direction"] == md for obj in group), f"{tool} movement differs from its placement preview"
            assert {obj["id"] for obj in group} == {obj["id"] for obj in added} and moved["budget"] == state["budget"]
            state = moved
            request("save", slot=slot + "-" + tool)
            persisted = request("load", slot=slot + "-" + tool)
            assert persisted["objects"] == state["objects"] and persisted["budget"] == state["budget"]
            sellable = next(obj for obj in added if obj["sellable"])
            request("sellObject", objectID=sellable["id"])
            for attempt in range(50):
                removed = request("state")
                if not any(obj["id"] in {obj["id"] for obj in added} for obj in removed["objects"]):
                    break
                time.sleep(0.02)
            assert {obj["id"] for obj in removed["objects"]} == before_ids, f"Selling {tool} left object tiles behind"
            assert state["budget"] < removed["budget"] <= baseline["budget"]
            checks.append({"tool": tool, "category": category, "total": page["total"], "guid": item["guid"], "name": item["name"], "price": item["price"], "tiles": len(added), "preview": True, "purchase": True, "moveAndRotate": True, "saveLoad": True, "sale": True, "fixture": str(fixture)})
    finally:
        restored = request("load", slot=slot)
        assert restored["objects"] == baseline["objects"] and restored["budget"] == baseline["budget"]
    return checks
