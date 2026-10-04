import json
import math
from pathlib import Path
import time
import uuid


def check_pool_accessories(request, water, swimming=False):
    baseline = request("state")
    directory = Path(request("scene")).parent
    page = json.loads(Path(water["fixture"]).read_text())
    accessories = [item for item in page["items"] if item.get("guid") is not None]
    assert accessories, "Original Water catalog has no pool accessories"
    width = baseline["width"]
    occupied = {(math.floor(obj["x"]), math.floor(obj["y"])) for obj in baseline["objects"] if obj["level"] == 1}
    pool_size = 5 if swimming else 3
    x, y = next((x, y) for y in range(1, baseline["height"] - pool_size - 1) for x in range(1, width - pool_size - 1)
                if all(baseline["buildable"][ty * width + tx] and not baseline["terrainSloped"][ty * width + tx]
                       and baseline["floors"][ty * width + tx] == 0 and baseline["walls"][ty * width + tx]["segments"] == 0 and (tx, ty) not in occupied
                       for ty in range(y - 1, y + pool_size + 1) for tx in range(x - 1, x + pool_size + 1)))
    floors = list(baseline["floors"])
    for dy in range(pool_size):
        for dx in range(pool_size):
            floors[(y + dy) * width + x + dx] = 65535
    base_slot = "pool-accessories-" + uuid.uuid4().hex
    request("save", slot=base_slot)
    results = []

    def state_until(predicate):
        for attempt in range(50):
            state = request("state")
            if predicate(state):
                return state
            time.sleep(0.02)
        raise AssertionError("Pool accessory command did not produce its expected state")

    try:
        request("architecture", command="FLOOR_RECT", x=x, y=y, level=1, x2=pool_size - 1, y2=pool_size - 1, pattern=65535, style=0)
        pool = state_until(lambda state: state["floors"] == floors)
        pool_slot = base_slot + "-pool"
        request("save", slot=pool_slot)
        scene = Path(request("scene"))
        fixture = directory / "pool-accessory-lot.json"
        fixture.write_text(scene.read_text())
        candidates = [(tx, ty) for ty in range(max(0, y - 2), min(baseline["height"], y + pool_size + 3))
                      for tx in range(max(0, x - 2), min(width, x + pool_size + 3)) if baseline["buildable"][ty * width + tx]]
        for item in accessories:
            request("load", slot=pool_slot)
            assert item["price"] <= pool["budget"], f"Pool fixture cannot afford {item['name']}"
            placement = None
            failure_statuses = {}
            invalid_preview = None
            for tx, ty in candidates:
                for direction in [1, 4, 16, 64]:
                    preview = request("previewObject", guid=item["guid"], x=tx * 16 + 8, y=ty * 16 + 8, level=1, direction=direction)
                    failure_statuses[preview["status"]] = failure_statuses.get(preview["status"], 0) + 1
                    if not preview["valid"] and invalid_preview is None:
                        invalid_preview = preview
                    if preview["valid"]:
                        placement = tx, ty, direction, preview
                        break
                if placement:
                    break
            assert placement, f"No pool-edge tile accepted {item['name']}: {failure_statuses}"
            tx, ty, direction, preview = placement
            assert preview["ghost"] and preview["tiles"] and request("state") == pool
            preview_path = directory / ("pool-accessory-preview-" + str(item["guid"]) + ".json")
            preview_path.write_text(json.dumps(preview))
            assert invalid_preview and invalid_preview["ghost"]
            invalid_path = directory / ("pool-accessory-invalid-" + str(item["guid"]) + ".json")
            invalid_path.write_text(json.dumps(invalid_preview))
            before_ids = {obj["id"] for obj in pool["objects"]}
            request("buyObject", guid=item["guid"], x=tx * 16 + 8, y=ty * 16 + 8, level=1, direction=direction)
            purchased = state_until(lambda state: any(obj["id"] not in before_ids for obj in state["objects"]))
            added = [obj for obj in purchased["objects"] if obj["id"] not in before_ids]
            assert purchased["budget"] == pool["budget"] - item["price"] and purchased["floors"] == floors
            sprite_scene = json.loads(Path(request("scene")).read_text())
            assert any(sprite["objectID"] in {obj["id"] for obj in added} for sprite in sprite_scene["sprites"])
            editable = next(obj for obj in added if obj["movable"] and obj["sellable"])
            move = None
            for mx, my in candidates:
                if (mx, my) == (tx, ty):
                    continue
                for md in [value for value in [1, 4, 16, 64] if value != direction]:
                    candidate = request("previewObject", objectID=editable["id"], x=mx * 16 + 8, y=my * 16 + 8, level=1, direction=md)
                    if candidate["valid"]:
                        move = mx, my, md, candidate
                        break
                if move:
                    break
            assert move, f"Pool accessory could not move and rotate: {item['name']}"
            mx, my, md, candidate = move
            assert request("state") == purchased
            request("moveObject", objectID=editable["id"], x=mx * 16 + 8, y=my * 16 + 8, level=1, direction=md)
            expected_tiles = {(tile["x"], tile["y"], tile["level"]) for tile in candidate["tiles"]}
            def moved_correctly(state):
                group = [obj for obj in state["objects"] if obj["id"] not in before_ids]
                return {(math.floor(obj["x"]), math.floor(obj["y"]), obj["level"]) for obj in group} == expected_tiles and all(obj["direction"] == md for obj in group)
            moved = state_until(moved_correctly)
            assert moved["budget"] == purchased["budget"] and moved["floors"] == floors
            request("save", slot=base_slot + "-" + str(item["guid"]))
            request("load", slot=pool_slot)
            restored = request("load", slot=base_slot + "-" + str(item["guid"]))
            assert restored["objects"] == moved["objects"] and restored["budget"] == moved["budget"] and restored["floors"] == floors
            menu = request("menu", objectID=editable["id"])
            swim_result = None
            if swimming:
                swimmer = next(sim for sim in restored["sims"] if sim["household"] and sim["career"]["age"] >= 18 and sim["career"]["type"] == 0)
                request("selectSim", objectID=swimmer["id"])
                ladder_ids = [obj["id"] for obj in added] if "Ladder" in item["name"] else []
                if not ladder_ids:
                    ladder = next(entry for entry in accessories if "Ladder" in entry["name"])
                    before_ladder = {obj["id"] for obj in restored["objects"]}
                    ladder_placement = None
                    for lx, ly in sorted(candidates, key=lambda point: abs(point[0] - mx) + abs(point[1] - my), reverse=True):
                        for ld in [1, 4, 16, 64]:
                            test = request("previewObject", guid=ladder["guid"], x=lx * 16 + 8, y=ly * 16 + 8, level=1, direction=ld)
                            if test["valid"]:
                                ladder_placement = lx, ly, ld
                                break
                        if ladder_placement:
                            break
                    assert ladder_placement, "Swimming fixture requires an accessible exit ladder"
                    lx, ly, ld = ladder_placement
                    request("buyObject", guid=ladder["guid"], x=lx * 16 + 8, y=ly * 16 + 8, level=1, direction=ld)
                    with_ladder = state_until(lambda state: any(obj["id"] not in before_ladder for obj in state["objects"]))
                    ladder_ids = [obj["id"] for obj in with_ladder["objects"] if obj["id"] not in before_ladder]
                menu = request("menu", objectID=editable["id"])
                entry = next(entry for entry in menu if entry["name"] in ["Get In", "Dive In", "Slide"])
                request("interact", objectID=editable["id"], interaction=entry["interaction"], param0=entry["param0"], **{"global": entry["global"]})
                samples = []
                entry_attempts = 1
                for attempt in range(100):
                    active = request("step", count=100)
                    sim = next(sim for sim in active["sims"] if sim["id"] == active["selectedSim"])
                    samples.append({key: sim[key] for key in ["swimming", "x", "y", "level", "actions"]})
                    if sim["swimming"]:
                        swimmer_scene = directory / ("pool-swimmer-" + str(item["guid"]) + ".json")
                        swimmer_scene.write_text(Path(request("scene")).read_text())
                        swim_result = {"scene": str(swimmer_scene), "simID": sim["id"], "entry": entry["name"], "ticks": (attempt + 1) * 100, "entryAttempts": entry_attempts, "position": [sim["x"], sim["y"], sim["level"]]}
                        break
                    if attempt > 1 and entry_attempts < 5 and not any(action.get("callee") in {obj["id"] for obj in added} for action in sim["actions"]):
                        offered = request("menu", objectID=editable["id"])
                        if any(option["interaction"] == entry["interaction"] and option["param0"] == entry["param0"] and option["global"] == entry["global"] for option in offered):
                            request("interact", objectID=editable["id"], interaction=entry["interaction"], param0=entry["param0"], **{"global": entry["global"]})
                            entry_attempts += 1
                trace = directory / ("pool-swimmer-trace-" + str(item["guid"]) + ".json")
                trace.write_text(json.dumps(samples))
                assert swim_result, f"{item['name']} did not start swimming; inspect {trace}"
                active = request("step", count=300)
                sim = next(sim for sim in active["sims"] if sim["id"] == swimmer["id"])
                assert sim["swimming"] and floors[math.floor(sim["y"]) * width + math.floor(sim["x"])] == 65535
                swimmer_scene.write_text(Path(request("scene")).read_text())
                swim_slot = "swim-" + uuid.uuid4().hex + "-" + str(item["guid"])
                request("save", slot=swim_slot)
                request("step", count=10)
                reloaded = request("load", slot=swim_slot)
                saved_sim = next(sim for sim in reloaded["sims"] if sim["id"] == swimmer["id"])
                assert saved_sim["swimming"] and [saved_sim[key] for key in ["x", "y", "level"]] == [sim[key] for key in ["x", "y", "level"]]
                request("selectSim", objectID=swimmer["id"])
                exits = [(identifier, entry) for identifier in ladder_ids for entry in request("menu", objectID=identifier)]
                exit_id, exit_entry = next((identifier, entry) for identifier, entry in exits if entry["name"] == "Get Out")
                for action in saved_sim["actions"]:
                    if action["cancellable"]:
                        request("cancelAction", objectID=swimmer["id"], token=action["token"])
                request("interact", objectID=exit_id, interaction=exit_entry["interaction"], param0=exit_entry["param0"], **{"global": exit_entry["global"]})
                for attempt in range(100):
                    leaving = request("step", count=100)
                    dry = next(sim for sim in leaving["sims"] if sim["id"] == swimmer["id"])
                    if not dry["swimming"] and leaving["floors"][math.floor(dry["y"]) * width + math.floor(dry["x"])] != 65535:
                        break
                else:
                    raise AssertionError(f"{item['name']} swimmer could not exit through the original ladder")
                swim_result.update({"saveLoad": True, "exit": exit_entry["name"], "swimmingPosition": [sim["x"], sim["y"], sim["level"]]})
                request("load", slot=base_slot + "-" + str(item["guid"]))
            request("sellObject", objectID=editable["id"])
            sold = state_until(lambda state: {obj["id"] for obj in state["objects"]} == before_ids)
            assert sold["budget"] > moved["budget"] and sold["budget"] <= pool["budget"] and sold["floors"] == floors
            results.append({"guid": item["guid"], "name": item["name"], "price": item["price"], "components": len(added), "purchase": True, "moveAndRotate": True, "saveLoad": True, "sale": True, "menu": [entry["name"] for entry in menu], "preview": str(preview_path), "invalidPreview": str(invalid_path), "swimming": swim_result})
    finally:
        restored = request("load", slot=base_slot)
        assert restored["objects"] == baseline["objects"] and restored["floors"] == baseline["floors"] and restored["budget"] == baseline["budget"]
    return {"scene": str(fixture), "origin": [x, y], "items": results}
