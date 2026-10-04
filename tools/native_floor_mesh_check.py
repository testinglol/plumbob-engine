import json
from pathlib import Path
import time
import uuid


def check_floor_meshes(request, catalog):
    baseline = request("state")
    width = baseline["width"]
    pattern = next(item for item in catalog["floors"] if 0 < item["id"] < 65534 and 0 <= item["price"] <= baseline["budget"])
    fixtures = []
    targets = []
    half_edits = []
    slot = "floor-mesh-" + uuid.uuid4().hex
    request("save", slot=slot)

    def check_scene(tile, halves):
        path = Path(request("scene"))
        scene = json.loads(path.read_text())
        meshes = [mesh for mesh in scene["meshes"] if mesh.get("floor") and mesh["floor"]["x"] == tile % width and mesh["floor"]["y"] == tile // width]
        assert sorted(mesh["floor"]["half"] for mesh in meshes) == sorted(halves)
        terrain = scene["terrainVertices"][tile * 6:tile * 6 + 6]
        corners = {0: [0, 1, 2, 3, 4, 5], 1: [0, 1, 2], 2: [3, 4, 5], 3: [0, 1, 4], 4: [1, 2, 4]}
        for mesh in meshes:
            assert mesh["objectID"] == 0 and mesh["unlit"] and mesh["layer"] == 0 and mesh["floor"]["pattern"] == pattern["id"]
            assert [(vertex["x"], vertex["y"]) for vertex in mesh["vertices"]] == [(terrain[index]["x"], terrain[index]["y"]) for index in corners[mesh["floor"]["half"]]]
            assert all(vertex["z"] == 1 and 0 <= vertex["u"] <= 1 and 0 <= vertex["v"] <= 1 for vertex in mesh["vertices"])
        fixtures.append(str(path))
        return scene

    try:
        eligible = [index for index in range(len(baseline["floors"])) if baseline["buildable"][index] and baseline["walls"][index]["segments"] == 0
                    and not any(abs(obj["x"] - index % width) < 1.5 and abs(obj["y"] - index // width) < 1.5 for obj in baseline["objects"])]
        slope = next(index for index in eligible if baseline["terrainSloped"][index])
        flat = next(index for index in eligible if not baseline["terrainSloped"][index] and not baseline["floors"][index])
        for tile, direction, halves in [(slope, None, [0]), (flat, 1, [1, 2]), (flat, 3, [3, 4])]:
            request("load", slot=slot)
            request("architecture", command="FLOOR_RECT", x=tile % width, y=tile // width, level=1, x2=0, y2=0, pattern=pattern["id"], style=0)
            for attempt in range(40):
                state = request("state")
                if state["floors"][tile] == pattern["id"]:
                    break
                time.sleep(0.02)
            assert state["floors"][tile] == pattern["id"]
            if direction is not None:
                start_x = tile % width + (1 if direction == 3 else 0)
                request("architecture", command="WALL_LINE", x=start_x, y=tile // width, level=1, x2=1, y2=direction, pattern=0, style=1)
                for attempt in range(40):
                    state = request("state")
                    if state["walls"][tile]["segments"] & 48:
                        break
                    time.sleep(0.02)
                assert state["walls"][tile]["segments"] & 48 and state["floors"][tile] == 0
            if direction is not None:
                case_slot = slot + "-diagonal-" + str(direction)
                request("save", slot=case_slot)
                replacement = next(item for item in catalog["floors"] if 0 < item["id"] < 65534 and item["id"] != pattern["id"] and 0 <= item["price"] <= state["budget"])
                for half in halves:
                    before = request("load", slot=case_slot)
                    field = "topLeftPattern" if half in [1, 4] else "topLeftStyle"
                    style = 1 if half == 1 else 2 if half == 4 else 0
                    expected = json.loads(json.dumps(before["walls"]))
                    expected[tile][field] = replacement["id"]
                    request("architecture", command="FLOOR_RECT", x=tile % width, y=tile // width, level=1, x2=0, y2=0, pattern=replacement["id"], style=style)
                    for attempt in range(40):
                        painted = request("state")
                        if painted["walls"] == expected:
                            break
                        time.sleep(0.02)
                    assert painted["walls"] == expected and painted["floors"] == before["floors"], "Half-tile painting changed the opposite half or other architecture"
                    assert painted["budget"] == before["budget"] + (pattern["price"] - pattern["price"] // 5) // 2 - replacement["price"] // 2
                    expected[tile][field] = 0
                    request("architecture", command="FLOOR_RECT", x=tile % width, y=tile // width, level=1, x2=0, y2=0, pattern=0, style=style)
                    for attempt in range(40):
                        removed = request("state")
                        if removed["walls"] == expected:
                            break
                        time.sleep(0.02)
                    assert removed["walls"] == expected and removed["floors"] == before["floors"], "Half-tile removal changed the opposite half"
                    assert removed["budget"] == painted["budget"] + (replacement["price"] - replacement["price"] // 5) // 2
                    blank_scene = json.loads(Path(request("scene")).read_text())
                    assert blank_scene["floorDiagonals"][tile] == (32 if half in [1, 2] else 16), "Blank half lost diagonal picking metadata"
                    remaining = [mesh["floor"]["half"] for mesh in blank_scene["meshes"] if mesh.get("floor") and mesh["floor"]["x"] == tile % width and mesh["floor"]["y"] == tile // width]
                    assert remaining == [value for value in halves if value != half]
                    request("save", slot=case_slot + "-removed")
                    request("load", slot=case_slot)
                    persisted = request("load", slot=case_slot + "-removed")
                    assert persisted["walls"] == expected and persisted["budget"] == removed["budget"]
                    half_edits.append({"half": half, "style": style, "paint": True, "removal": True, "oppositeHalfUnchanged": True, "saveLoad": True})
                request("load", slot=case_slot)
            scene = check_scene(tile, halves)
            targets.append({"x": tile % width, "y": tile // width, "halves": halves})
            if direction is None:
                terrain = scene["terrainVertices"][tile * 6:tile * 6 + 6]
                assert terrain[0]["y"] + terrain[2]["y"] != terrain[1]["y"] + terrain[4]["y"] or terrain[1]["y"] != terrain[4]["y"] or terrain[2]["y"] - terrain[0]["y"] != 32
    finally:
        restored = request("load", slot=slot)
        assert restored["floors"] == baseline["floors"] and restored["walls"] == baseline["walls"] and restored["budget"] == baseline["budget"]
    return {"slopedFloor": True, "diagonalHalves": [1, 2, 3, 4], "fixtures": fixtures, "targets": targets, "halfEdits": half_edits}
