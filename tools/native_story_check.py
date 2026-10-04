import json
import math
from pathlib import Path
import time
import uuid


def check_stories(request, raw_request):
    baseline = request("state")
    directory = Path(request("scene")).parent
    slot = "stories-" + uuid.uuid4().hex
    request("save", slot=slot)
    width = baseline["width"]
    views = []

    def until(predicate):
        for attempt in range(50):
            state = request("state")
            if predicate(state):
                return state
            time.sleep(0.02)
        raise AssertionError("Story edit did not produce its expected state")

    def snapshot(label):
        source = Path(request("scene"))
        path = directory / (label + ".json")
        path.write_text(source.read_text())
        return path, json.loads(path.read_text())

    try:
        for level in range(1, baseline["stories"] + 1):
            state = request("level", value=level)
            assert state["objects"] == baseline["objects"] and state["budget"] == baseline["budget"]
            path, scene = snapshot("story-" + str(level))
            assert scene["viewLevel"] == level and scene["stories"] == baseline["stories"]
            assert all(1 <= item["level"] <= level for item in scene["sprites"] + scene["meshes"])
            assert len(scene["placementVertices"]) == len(scene["terrainVertices"])
            for ground, upper in zip(scene["terrainVertices"], scene["placementVertices"]):
                assert abs(ground["x"] - upper["x"]) < 0.001
                assert abs(ground["y"] - upper["y"] - (level - 1) * 118) < 0.001
            views.append({"level": level, "scene": str(path), "floorTiles": sum(mesh.get("floor", {}).get("level") == level for mesh in scene["meshes"] if mesh.get("floor")), "wallSprites": scene["wallSprites"]})
        request("level", value=2)
        upper = request("state")
        assert any(upper["floors"]), "Original fixture has no second-story floor"
        for invalid in [0, baseline["stories"] + 1]:
            try:
                raw_request("level", value=invalid)
            except RuntimeError as error:
                assert "Story is outside" in str(error)
            else:
                raise AssertionError("Invalid story was accepted")
        assert request("state") == upper
        pattern = next(item for item in request("catalog")["floors"] if item["id"] < 65534 and item["price"] > 0 and item["id"] not in upper["floors"])
        candidates = [(index % width, index // width) for index, tile in enumerate(upper["floors"]) if tile and upper["buildable"][index] and upper["walls"][index]["segments"] & 48 == 0]
        assert candidates, "No supported second-story test tile"
        x, y = candidates[0]
        floors = list(upper["floors"])
        floors[y * width + x] = pattern["id"]
        request("architecture", command="FLOOR_RECT", x=x, y=y, level=2, x2=0, y2=0, pattern=pattern["id"], style=0)
        painted = until(lambda state: state["floors"] == floors)
        painted_path, painted_scene = snapshot("story-2-painted")
        assert any(mesh.get("floor") == {"x": x, "y": y, "pattern": pattern["id"], "half": 0, "water": None, "level": 2} for mesh in painted_scene["meshes"])
        request("level", value=1)
        assert request("state")["floors"] == baseline["floors"]
        request("level", value=2)
        catalog_page = request("catalogPage", category=0, offset=0, count=64)
        catalog_path = directory / "story-object-catalog.json"
        catalog_path.write_text(json.dumps(catalog_page))
        items = catalog_page["items"]
        placement = None
        for item in items:
            if item["price"] > painted["budget"]:
                continue
            for tx, ty in candidates:
                preview = request("previewObject", guid=item["guid"], x=tx * 16 + 8, y=ty * 16 + 8, level=2, direction=1)
                if preview["valid"]:
                    placement = item, tx, ty, preview
                    break
            if placement:
                break
        assert placement, "No original object can be placed on a supported upper floor"
        item, tx, ty, preview = placement
        assert preview["ghost"] and all(tile["level"] == 2 for tile in preview["tiles"])
        preview_path = directory / "story-2-preview.json"
        preview_path.write_text(json.dumps(preview))
        before_ids = {obj["id"] for obj in painted["objects"]}
        request("buyObject", guid=item["guid"], x=tx * 16 + 8, y=ty * 16 + 8, level=2, direction=1)
        purchased = until(lambda state: any(obj["id"] not in before_ids for obj in state["objects"]))
        added = [obj for obj in purchased["objects"] if obj["id"] not in before_ids]
        assert all(obj["level"] == 2 for obj in added) and purchased["budget"] == painted["budget"] - item["price"]
        object_path, scene = snapshot("story-2-object")
        assert any(sprite["objectID"] in {obj["id"] for obj in added} and sprite["level"] == 2 for sprite in scene["sprites"])
        state_path = directory / "story-2-state.json"
        state_path.write_text(json.dumps(purchased))
        editable = next(obj for obj in added if obj["movable"] and obj["sellable"])
        move = None
        for mx, my in candidates:
            if (mx, my) == (tx, ty):
                continue
            test = request("previewObject", objectID=editable["id"], x=mx * 16 + 8, y=my * 16 + 8, level=2, direction=4)
            if test["valid"]:
                move = mx, my, test
                break
        assert move, "Upper object could not move and rotate"
        mx, my, test = move
        request("moveObject", objectID=editable["id"], x=mx * 16 + 8, y=my * 16 + 8, level=2, direction=4)
        moved = until(lambda state: all(obj["direction"] == 4 for obj in state["objects"] if obj["id"] not in before_ids))
        assert {(math.floor(obj["x"]), math.floor(obj["y"]), obj["level"]) for obj in moved["objects"] if obj["id"] not in before_ids} == {(tile["x"], tile["y"], tile["level"]) for tile in test["tiles"]}
        request("save", slot=slot + "-upper")
        request("load", slot=slot)
        restored = request("load", slot=slot + "-upper")
        assert restored["floors"] == floors and restored["objects"] == moved["objects"] and restored["budget"] == moved["budget"]
        request("level", value=1)
        ground_path, ground_scene = snapshot("story-1-upper-hidden")
        assert not any(sprite["objectID"] in {obj["id"] for obj in added} for sprite in ground_scene["sprites"])
        assert request("state")["floors"] == baseline["floors"]
        request("level", value=2)
        request("sellObject", objectID=editable["id"])
        sold = until(lambda state: {obj["id"] for obj in state["objects"]} == before_ids)
        assert sold["floors"] == floors and sold["budget"] > moved["budget"]
        restored = request("load", slot=slot)
        actor = next(sim for sim in restored["sims"] if sim["household"] and sim["career"]["age"] >= 18 and sim["career"]["type"] == 0)
        request("selectSim", objectID=actor["id"])
        route_target = None
        for target in restored["objects"]:
            if target["level"] != 2:
                continue
            for entry in request("menu", objectID=target["id"]):
                if entry["name"] in ["Paint", "Practice Painting", "Nap", "Play"]:
                    route_target = target, entry
                    break
            if route_target:
                break
        assert route_target, "Original upper-story fixture has no suitable interaction"
        target, entry = route_target
        request("interact", objectID=target["id"], interaction=entry["interaction"], param0=entry["param0"], **{"global": entry["global"]})
        routing_samples = []
        for attempt in range(100):
            routed = request("step", count=100)
            sim = next(sim for sim in routed["sims"] if sim["id"] == actor["id"])
            routing_samples.append({key: sim[key] for key in ["x", "y", "level", "actions"]})
            if sim["level"] == 2:
                break
        else:
            trace = directory / "story-routing-trace.json"
            trace.write_text(json.dumps(routing_samples))
            raise AssertionError(f"Original routing did not bring the Sim to the upper-story object; inspect {trace}")
        sim_path, sim_scene = snapshot("story-2-sim")
        assert any(mesh["objectID"] == actor["id"] and mesh["level"] == 2 for mesh in sim_scene["meshes"])
        sim_state = directory / "story-2-sim-state.json"
        sim_state.write_text(json.dumps(routed))
        request("save", slot=slot + "-sim")
        request("step", count=10)
        sim_reloaded = request("load", slot=slot + "-sim")
        assert next(sim for sim in sim_reloaded["sims"] if sim["id"] == actor["id"])["level"] == 2
        return {"catalog": str(catalog_path), "routingBetweenStories": True, "routingTarget": target["name"], "routingInteraction": entry["name"], "upperSimScene": str(sim_path), "upperSimState": str(sim_state), "upperSimID": actor["id"], "views": views, "paintedScene": str(painted_path), "objectScene": str(object_path), "state": str(state_path), "groundScene": str(ground_path), "preview": str(preview_path), "object": item["name"], "level": 2, "paint": True, "groundFloorUnchanged": True, "purchaseMoveRotateSale": True, "saveLoad": True, "hiddenAboveSelectedStory": True, "invalidStoryRejected": True}
    finally:
        request("level", value=baseline["viewLevel"])
        restored = request("load", slot=slot)
        assert restored["floors"] == baseline["floors"] and restored["objects"] == baseline["objects"] and restored["budget"] == baseline["budget"]
