import json
import time
import uuid


def check_room_fill(request, catalog):
    baseline = request("state")
    width, height = baseline["width"], baseline["height"]
    seen = set()
    rooms = []
    for seed in range(width * height):
        if seed in seen or not baseline["buildable"][seed]:
            continue
        room, pending = set(), [seed]
        while pending:
            tile = pending.pop()
            if tile in room:
                continue
            room.add(tile)
            x, y = tile % width, tile // width
            for dx, dy, bit in [(-1, 0, 1), (0, -1, 2), (1, 0, 4), (0, 1, 8)]:
                nx, ny = x + dx, y + dy
                if not (0 <= nx < width and 0 <= ny < height):
                    continue
                neighbor = ny * width + nx
                if baseline["buildable"][neighbor] and not baseline["walls"][tile]["segments"] & bit and neighbor not in room:
                    pending.append(neighbor)
        seen.update(room)
        if 4 <= len(room) <= 128 and all(0 < baseline["floors"][tile] < 65534 and baseline["walls"][tile]["segments"] < 16 for tile in room):
            rooms.append(room)
    room = min(rooms, key=len)
    seed = min(room)
    result = {"seed": [seed % width, seed // width], "tileCount": len(room)}
    slot = "room-fill-" + uuid.uuid4().hex
    request("save", slot=slot)
    try:
        for kind, command, removing in [("floor", "FLOOR_FILL", False), ("wall", "PATTERN_FILL", False), ("floor", "FLOOR_FILL", True), ("wall", "PATTERN_FILL", True)]:
            request("load", slot=slot)
            source = catalog["floors" if kind == "floor" else "walls"]
            pattern = min((item for item in source if 0 < item["id"] < 65534 and 0 <= item["price"] <= baseline["budget"] // (len(room) * 4)), key=lambda item: (item["price"], item["id"]))
            if removing:
                pattern = {"id": 0, "price": 0}
            expected_floors = list(baseline["floors"])
            expected_walls = json.loads(json.dumps(baseline["walls"]))
            surfaces = []
            for tile in room:
                if kind == "floor":
                    expected_floors[tile] = pattern["id"]
                    continue
                x, y = tile % width, tile // width
                wall = baseline["walls"][tile]
                for dx, dy, bit, field, style in [(-1, 0, 1, "topLeftPattern", wall["topLeftStyle"]), (0, -1, 2, "topRightPattern", wall["topRightStyle"]),
                                               (1, 0, 4, "bottomRightPattern", baseline["walls"][tile + 1]["topLeftStyle"] if x + 1 < width else 0),
                                               (0, 1, 8, "bottomLeftPattern", baseline["walls"][tile + width]["topRightStyle"] if y + 1 < height else 0)]:
                    neighbor = (y + dy) * width + x + dx
                    if neighbor not in room and wall["segments"] & bit and style == 1:
                        expected_walls[tile][field] = pattern["id"]
                        surfaces.append([tile, field])
            assert expected_floors != baseline["floors"] or expected_walls != baseline["walls"], "Room fill fixture has no changes"
            request("architecture", command=command, x=seed % width, y=seed // width, level=1, x2=0, y2=0, pattern=pattern["id"], style=0)
            for attempt in range(40):
                edited = request("state")
                if edited["floors"] == expected_floors and edited["walls"] == expected_walls:
                    break
                time.sleep(0.02)
            assert edited["floors"] == expected_floors, f"{kind} fill changed flooring outside the selected room or missed tiles"
            assert edited["walls"] == expected_walls, f"{kind} fill changed unexpected wall surfaces"
            prices = {item["id"]: max(0, item["price"]) for item in source}
            if kind == "floor":
                replaced = [baseline["floors"][tile] for tile in room if baseline["floors"][tile] != pattern["id"]]
                old_cost = sum(prices.get(old, 0) for old in replaced) * 2
                refund = (old_cost - old_cost // 5) // 2
            else:
                replaced = [baseline["walls"][tile][field] for tile, field in surfaces if baseline["walls"][tile][field] != pattern["id"]]
                old_cost = sum(prices.get(old, 0) for old in replaced)
                refund = old_cost - old_cost // 5
            expected_budget = baseline["budget"] - len(replaced) * pattern["price"] + refund
            assert edited["budget"] == expected_budget, f"{kind} fill charged an unexpected cost or refund"
            painted_slot = slot + "-" + kind + ("-removed" if removing else "")
            request("save", slot=painted_slot)
            request("load", slot=slot)
            persisted = request("load", slot=painted_slot)
            assert persisted["floors"] == expected_floors and persisted["walls"] == expected_walls and persisted["budget"] == edited["budget"]
            result[kind + ("Removal" if removing else "")] = {"pattern": pattern["id"], "applied": True, "saveLoad": True, "wallSurfaces": len(surfaces), "costAndRefund": True}
    finally:
        restored = request("load", slot=slot)
        assert restored["floors"] == baseline["floors"] and restored["walls"] == baseline["walls"] and restored["budget"] == baseline["budget"]
    return result
