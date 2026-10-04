import json
import math
from pathlib import Path
import uuid


def check_roofs(request, raw_request):
    baseline = request("state")
    slot = "roof-" + uuid.uuid4().hex
    request("save", slot=slot)
    directory = Path(request("scene")).parent
    fixtures = []
    try:
        visible = request("roofs", visible=True)
        assert visible["roofsVisible"] and visible["wallsUp"]
        catalog = request("buildCatalogPage", kind="roof", offset=0, count=64)
        assert catalog["total"] >= 2 and catalog["items"][0]["id"] == 0
        assert all(item["price"] == 0 and item["icon"] for item in catalog["items"])
        catalog_path = directory / "roof-catalog.json"
        catalog_path.write_text(json.dumps(catalog))
        vertices_by_pitch = {}
        for style in [catalog["items"][0]["id"], catalog["items"][1]["id"]]:
            for pitch in [0, 0.66, 1.25]:
                state = request("roof", style=style, pitch=pitch)
                assert state["roofStyle"] == style and abs(state["roofPitch"] - pitch) < 0.0001
                assert state["budget"] == baseline["budget"] and state["objects"] == baseline["objects"]
                source = Path(request("scene"))
                scene = json.loads(source.read_text())
                path = directory / f"roof-{style}-{pitch}.json"
                path.write_text(json.dumps(scene))
                roofs = [mesh for mesh in scene["meshes"] if mesh.get("roof")]
                assert roofs, "Original room layout produced no roof"
                assert {mesh["roof"]["part"] for mesh in roofs} == {"surface", "edge"}
                assert all(mesh["layer"] == 2 and mesh["objectID"] == 0 and not mesh["unlit"] for mesh in roofs)
                for mesh in roofs:
                    assert mesh["roof"]["style"] == style and mesh["level"] <= scene["viewLevel"]
                    assert mesh["vertices"] and len(mesh["vertices"]) % 3 == 0
                    assert scene["textures"][mesh["texture"]]["encoding"] == ("png" if mesh["roof"]["part"] == "edge" else "bmp")
                    for vertex in mesh["vertices"]:
                        assert all(math.isfinite(value) for value in vertex.values())
                        assert 0 <= vertex["x"] <= scene["width"] + 1 and 0 <= vertex["y"] <= scene["height"] + 1
                        assert 0 <= vertex["z"] <= 1
                coordinates = [(v["x"], v["y"], v["z"]) for mesh in roofs for v in mesh["vertices"]]
                assert any(abs(v["u"]) > 1 or abs(v["v"]) > 1 for mesh in roofs for v in mesh["vertices"])
                if pitch in vertices_by_pitch:
                    assert coordinates == vertices_by_pitch[pitch], "Changing material changed geometry"
                vertices_by_pitch[pitch] = coordinates
                fixtures.append({"style": style, "pitch": pitch, "scene": str(path), "vertices": len(coordinates)})
        assert vertices_by_pitch[0] != vertices_by_pitch[0.66] != vertices_by_pitch[1.25]
        saved = request("state")
        request("save", slot=slot + "-edited")
        request("load", slot=slot)
        restored = request("load", slot=slot + "-edited")
        assert restored["roofStyle"] == saved["roofStyle"] and restored["roofPitch"] == saved["roofPitch"]
        for style, pitch in [(catalog["total"], 0.66), (0, -0.1), (0, 1.26)]:
            try:
                raw_request("roof", style=style, pitch=pitch)
            except RuntimeError as error:
                assert "Invalid roof style or pitch" in str(error)
            else:
                raise AssertionError("Invalid roof settings accepted")
        current = request("state")
        assert (current["roofStyle"], current["roofPitch"]) == (saved["roofStyle"], saved["roofPitch"])
        request("level", value=1)
        hidden = json.loads(Path(request("scene")).read_text())
        assert not hidden["roofsVisible"] and not any(mesh.get("roof") for mesh in hidden["meshes"])
        state_path = directory / "roof-state.json"
        state_path.write_text(json.dumps(saved))
        return {"fixtures": fixtures, "catalog": str(catalog_path), "state": str(state_path), "saveLoad": True, "invalidSettingsRejected": True}
    finally:
        request("load", slot=slot)
