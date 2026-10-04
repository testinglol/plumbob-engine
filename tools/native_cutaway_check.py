import json
from pathlib import Path


def check_cutaway(request, raw_request):
    baseline = request("state")
    directory = Path(request("scene")).parent
    state_path = directory / "cutaway-state.json"
    state_path.write_text(json.dumps(baseline))
    fixtures = []
    def capture(name):
        source = Path(request("scene"))
        scene = json.loads(source.read_text())
        path = directory / f"cutaway-{name}.json"
        path.write_text(json.dumps(scene))
        fixtures.append({"name": name, "scene": str(path)})
        return scene
    try:
        request("walls", mode="up")
        up = capture("up")
        architecture_sprites = [sprite for sprite in up["sprites"] if sprite.get("architectureDepth")]
        assert architecture_sprites and all(sprite.get("depthTexture") is not None for sprite in architecture_sprites)
        assert all(sprite["architectureDepth"]["configuration"] == sprite["wall"]["direction"] + 4 for sprite in architecture_sprites if sprite.get("wall") and sprite["architectureDepth"]["configuration"] in [4, 5])
        configurations = {4: (32, 135, 74, 2, 1), 5: (32, 135, 135, -2, 1),
                          6: (64, 120, 89.5, 0, 1), 7: (8, 116, 45, 0, 1)}
        verified_depths = set()
        for sprite in architecture_sprites:
            texture = up["textures"][sprite["depthTexture"]]
            configuration = sprite["architectureDepth"]["configuration"]
            key = (configuration, texture["file"])
            if key in verified_depths:
                continue
            width, height = texture["width"], texture["height"]
            source_width, source_height, start, delta_x, delta_y = configurations[configuration]
            expected = bytes(max(0, min(254, round(start + delta_x * (x * source_width // width) + delta_y * (y * source_height // height))))
                             for y in range(height) for x in range(width))
            assert (directory / texture["file"]).read_bytes() == expected, "Wall depth differs from original procedural orientation"
            verified_depths.add(key)
        walls = [sprite["wall"] for sprite in up["sprites"] if sprite.get("wall")]
        up_junctions = [sprite for sprite in up["sprites"] if sprite.get("junction")]
        assert up_junctions and all(not sprite["junction"]["down"] for sprite in up_junctions)
        assert all(0 <= sprite["junction"]["frame"] <= 45 and sprite.get("depthTexture") is not None for sprite in up_junctions)
        assert walls and all(wall["cut"] == 0 for wall in walls)
        request("walls", mode="down")
        down = capture("down")
        assert any(sprite["wall"]["cut"] == 3 for sprite in down["sprites"] if sprite.get("wall"))
        down_junctions = [sprite for sprite in down["sprites"] if sprite.get("junction")]
        assert down_junctions and all(sprite["junction"]["down"] for sprite in down_junctions)
        up_by_tile = {(sprite["junction"]["x"], sprite["junction"]["y"]): sprite for sprite in up_junctions}
        matched = 0
        for sprite in down_junctions:
            previous = up_by_tile.get((sprite["junction"]["x"], sprite["junction"]["y"]))
            if previous:
                assert abs(sprite["y"] - previous["y"] - 106) < 0.01
                matched += 1
        assert matched > 0
        request("walls", mode="cutaway")
        for index, wall in enumerate(walls[::max(1, len(walls) // 8)]):
            request("cutaway", x=wall["x"], y=wall["y"])
            scene = capture(f"hover-{index}")
            cuts = {sprite["wall"]["cut"] for sprite in scene["sprites"] if sprite.get("wall")}
            assert cuts <= {0, 1, 2, 3}
        all_cuts = {sprite["wall"]["cut"] for fixture in fixtures[2:] for sprite in json.loads(Path(fixture["scene"]).read_text())["sprites"] if sprite.get("wall")}
        assert {0, 3}.issubset(all_cuts) and all_cuts & {1, 2}, "Cutaway lacks full, low or sloping walls"
        current = request("state")
        live_scene = json.loads(Path(request("scene")).read_text())
        request("view", editing=True)
        editing_scene = capture("editing")
        live_ids = {sprite["objectID"] for sprite in live_scene["sprites"] if sprite["objectID"] > 0}
        edit_ids = {sprite["objectID"] for sprite in editing_scene["sprites"] if sprite["objectID"] > 0}
        assert live_ids <= edit_ids, "Editing view hid a visible live object"
        assert request("state")["editingView"]
        request("view", editing=False)
        assert not request("state")["editingView"]
        for key in ["budget", "objects", "hours", "minutes", "updates"]:
            assert current[key] == baseline[key], f"Cutaway changed {key}"
        for operation, parameters in [("walls", {"mode": "invalid"}), ("cutaway", {"x": -1, "y": 0}), ("cutaway", {"x": current["width"], "y": 0})]:
            try:
                raw_request(operation, **parameters)
            except RuntimeError:
                pass
            else:
                raise AssertionError("Invalid cutaway input was accepted")
        request("roofs", visible=True)
        assert request("state")["wallMode"] == "up"
        request("walls", up=False)
        assert request("state")["wallMode"] == "down" and not request("state")["roofsVisible"]
        try:
            raw_request("cutaway", x=0, y=0)
        except RuntimeError:
            pass
        else:
            raise AssertionError("Hover accepted outside cutaway mode")
        return {"state": str(state_path), "fixtures": fixtures, "wallDepth": True, "proceduralDepthsVerified": len(verified_depths), "junctionGeometry": True, "partialMasks": True, "legacyWalls": True, "viewOnly": True, "livePresentationVerified": False}
    finally:
        request("level", value=baseline["viewLevel"])
        request("walls", mode=baseline["wallMode"])
        request("view", editing=baseline["editingView"])
