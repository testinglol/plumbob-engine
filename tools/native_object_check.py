import json
import os
from pathlib import Path
import time
import uuid
import struct


def check_objects(request, catalog):
    custom_guid = os.environ.get("SIMS_TEST_OBJECT_GUID")
    product = next(item for item in catalog["objects"] if item["guid"] == int(custom_guid, 0)) if custom_guid else next(item for item in catalog["objects"] if "flamingo" in (item["catalogName"] or item["name"] or "").lower())
    baseline = request("state")
    assert all(not item["movable"] and not item["sellable"] for item in baseline["objects"] if item["avatar"])
    all_category = sorted([item for item in catalog["objects"] if item["category"] == product["category"]], key=lambda item: (item["price"], item["guid"]))
    product_offset = next(index for index, item in enumerate(all_category) if item["guid"] == product["guid"])
    catalog_page = request("catalogPage", category=product["category"], offset=product_offset, count=64)
    assert catalog_page["total"] == len(all_category)
    assert [item["guid"] for item in catalog_page["items"]] == [item["guid"] for item in all_category[product_offset:product_offset + 64]]
    preview = catalog_page["items"][0]
    assert preview["name"] and preview["description"] and preview["price"] == product["price"]
    assert preview["icon"], "Catalog object has no original thumbnail"
    initial_scene = Path(request("scene"))
    icon = (initial_scene.parent / preview["icon"]["file"]).read_bytes()
    assert icon[:2] == b"BM" and len(icon) <= 4 * 1024 * 1024
    icon_width, icon_height = struct.unpack_from("<ii", icon, 18)
    assert icon_width % preview["icon"]["columns"] == 0 and abs(icon_height) % preview["icon"]["rows"] == 0
    (initial_scene.parent / "catalog-page.json").write_text(json.dumps(catalog_page))
    (initial_scene.parent / "catalog-state.json").write_text(json.dumps(baseline))
    width = baseline["width"]
    occupied = {(int(item["x"]), int(item["y"])) for item in baseline["objects"] if item["level"] == 1}
    tiles = [(index % width, index // width) for index, allowed in enumerate(baseline["buildable"])
             if allowed and (index % width, index // width) not in occupied]
    before_ids = {item["id"] for item in baseline["objects"]}
    preview_x, preview_y = tiles[0]
    before_preview = request("state")
    started = time.monotonic()
    placement_preview = request("previewObject", guid=product["guid"], x=preview_x * 16 + 8, y=preview_y * 16 + 8, level=1, direction=1)
    preview_ms = round((time.monotonic() - started) * 1000, 1)
    assert placement_preview["schemaVersion"] == 1 and placement_preview["tiles"]
    assert request("state") == before_preview, "Placement preview mutated live simulation state"
    bought = None
    for x, y in tiles[:20]:
        request("buyObject", guid=product["guid"], x=x * 16 + 8, y=y * 16 + 8, level=1, direction=1)
        for attempt in range(50):
            time.sleep(0.02)
            purchased = request("state")
            added = [item for item in purchased["objects"] if item["id"] not in before_ids]
            if added:
                bought = next(item for item in added if not item["avatar"])
                break
        if bought:
            break
        assert purchased["budget"] == baseline["budget"], "Failed placement did not refund the purchase"
    assert bought, "No tested buildable tile accepted the catalog flamingo"
    assert bought["movable"] and bought["sellable"], "Purchased object is unavailable to native editing tools"
    assert purchased["budget"] == baseline["budget"] - product["price"], (product, purchased["budget"], baseline["budget"])
    assert (bought["x"], bought["y"], bought["direction"]) == (x + 0.5, y + 0.5, 1)
    assert request("menu", objectID=bought["id"]), "Purchased object has no original interactions"
    scene = json.loads(Path(request("scene")).read_text())
    assert any(sprite["objectID"] == bought["id"] for sprite in scene["sprites"]), "Purchased object is absent from the rendered scene"
    placed_ids = {item["id"] for item in purchased["objects"]}
    collision_preview = request("previewObject", guid=product["guid"], x=x * 16 + 8, y=y * 16 + 8, level=1, direction=1)
    assert not collision_preview["valid"] and collision_preview["status"] != "Success"
    self_preview = request("previewObject", objectID=bought["id"], x=x * 16 + 8, y=y * 16 + 8, level=1, direction=1)
    assert self_preview["valid"], "Move preview collided with its own source object"
    assert self_preview["ghost"] and self_preview["ghost"]["scene"]["sprites"], "Original object ghost artwork was not exported"
    assert collision_preview["ghost"] and collision_preview["ghost"]["scene"]["sprites"], "Invalid placement lost its object ghost"
    rotated_preview = request("previewObject", objectID=bought["id"], x=x * 16 + 8, y=y * 16 + 8, level=1, direction=4)
    assert rotated_preview["valid"] and rotated_preview["ghost"]
    def ghost_signature(preview):
        ghost = preview["ghost"]
        return [(ghost["scene"]["textures"][sprite["texture"]]["file"], sprite["x"], sprite["y"], sprite["flip"]) for sprite in ghost["scene"]["sprites"]]
    assert ghost_signature(self_preview) != ghost_signature(rotated_preview), "Rotated preview kept the same directional artwork"
    (initial_scene.parent / "placement-invalid-preview.json").write_text(json.dumps(collision_preview))
    (initial_scene.parent / "placement-rotated-preview.json").write_text(json.dumps(rotated_preview))
    assert request("state") == purchased, "Move preview mutated live simulation state"
    (initial_scene.parent / "placement-preview.json").write_text(json.dumps(self_preview))
    request("buyObject", guid=product["guid"], x=x * 16 + 8, y=y * 16 + 8, level=1, direction=1)
    for attempt in range(50):
        time.sleep(0.02)
        rejected = request("state")
        assert {item["id"] for item in rejected["objects"]} == placed_ids, "Colliding purchase created another object"
    assert rejected["budget"] == purchased["budget"], "Colliding purchase did not refund family funds"
    for operation, parameters in [
        ("catalogPage", {"category": 13, "offset": 0, "count": 2}),
        ("catalogPage", {"category": product["category"], "offset": -1, "count": 2}),
        ("catalogPage", {"category": product["category"], "offset": 0, "count": 65}),
        ("moveObject", {"objectID": bought["id"], "x": -1, "y": 8, "level": 1, "direction": 1}),
        ("moveObject", {"objectID": bought["id"], "x": x * 16 + 8, "y": y * 16 + 8, "level": 1, "direction": 3}),
        ("sellObject", {"objectID": baseline["selectedSim"]}),
        ("buyObject", {"guid": 0, "x": x * 16 + 8, "y": y * 16 + 8, "level": 1, "direction": 1}),
    ]:
        try:
            request(operation, **parameters)
        except RuntimeError:
            pass
        else:
            raise AssertionError(f"Invalid object edit was accepted: {operation}, {parameters}")
    move_x, move_y = next(tile for tile in tiles if tile != (x, y))
    request("moveObject", objectID=bought["id"], x=move_x * 16 + 8, y=move_y * 16 + 8, level=1, direction=4)
    for attempt in range(50):
        time.sleep(0.02)
        edited = request("state")
        moved = next(item for item in edited["objects"] if item["id"] == bought["id"])
        if (moved["x"], moved["y"], moved["direction"]) == (move_x + 0.5, move_y + 0.5, 4):
            break
    assert (moved["x"], moved["y"], moved["direction"]) == (move_x + 0.5, move_y + 0.5, 4), "Object did not move and rotate"
    assert edited["budget"] == purchased["budget"], "Moving an object changed family funds"
    slot = "objects-" + uuid.uuid4().hex
    request("save", slot=slot)
    loaded = request("load", slot=slot)
    assert next(item for item in loaded["objects"] if item["id"] == bought["id"]) == next(item for item in edited["objects"] if item["id"] == bought["id"])
    assert loaded["budget"] == edited["budget"]
    request("sellObject", objectID=bought["id"])
    for attempt in range(50):
        time.sleep(0.02)
        sold = request("state")
        if all(item["id"] != bought["id"] for item in sold["objects"]) and sold["budget"] == baseline["budget"]:
            break
    assert all(item["id"] != bought["id"] for item in sold["objects"]), "Sold object remains on the lot"
    assert sold["budget"] == baseline["budget"], "Resale did not restore the new object's price"
    return {"guid": product["guid"], "name": product["catalogName"] or product["name"], "price": product["price"], "catalogPreview": True, "catalogFixture": str(initial_scene.parent / "catalog-page.json"), "purchaseSceneExported": True, "failedPlacementRefund": True, "moveAndRotate": True, "saveLoad": True, "resale": True, "invalidEditsRejected": True, "placementPreview": True, "objectGhost": True, "previewMilliseconds": preview_ms, "placementFixture": str(initial_scene.parent / "placement-preview.json")}
