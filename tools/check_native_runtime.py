import hashlib
import json
import os
from pathlib import Path
import queue
import shutil
import subprocess
import threading
import time
import uuid


root = Path(__file__).resolve().parents[1]
session = root / "runtime/native-sessions" / ("check-" + uuid.uuid4().hex)
game = Path(os.environ.get("SIMS_TEST_GAME", root / "runtime/game"))
original = root / "runtime/game/UserData/Houses/House05.iff"
before = hashlib.sha256(original.read_bytes()).hexdigest()
environment = os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")}
log = (root / "logs/runtime-integration.log").open("w")
process = subprocess.Popen([shutil.which("dotnet"), str(root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"), str(game), str(root), "--serve", str(session), "5"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=log, text=True, env=environment)
messages = queue.Queue()


def read_output():
    try:
        for line in process.stdout:
            messages.put(json.loads(line))
    except Exception as error:
        messages.put(error)
    finally:
        messages.put(None)


threading.Thread(target=read_output, daemon=True).start()
sequence = 0
last_scene_revision = 0
audio_events = []


def receive():
    message = messages.get(timeout=30)
    if message is None:
        raise RuntimeError(f"Simulation exited with {process.poll()}; inspect {log.name}")
    if isinstance(message, Exception):
        raise message
    return message


def raw_request(operation, **parameters):
    global sequence, last_scene_revision
    if operation in ["architecture", "buyObject", "moveObject", "sellObject", "previewObject", "roof"]:
        raw_request("view", editing=True)
    sequence += 1
    identifier = str(sequence)
    process.stdin.write(json.dumps({"id": identifier, "op": operation} | parameters) + "\n")
    process.stdin.flush()
    while True:
        message = receive()
        if message.get("type") == "audioError":
            print(json.dumps(message), file=__import__("sys").stderr)
        if message.get("type") == "audio":
            audio_events.append(message)
        if message.get("type") == "frame":
            last_scene_revision = max(last_scene_revision, message["revision"])
        if message.get("type") == "response" and message.get("id") == identifier:
            if not message["ok"]:
                raise RuntimeError(message["error"])
            result = message.get("result")
            if operation == "scene":
                source = Path(result)
                fixture = source.with_name("fixture-" + source.name)
                fixture.write_bytes(source.read_bytes())
                result = str(fixture)
            if operation not in ["sceneAck", "quit"] and last_scene_revision > 0:
                raw_request("sceneAck", revision=last_scene_revision)
            return result


def request(operation, **parameters):
    if operation != "step":
        return raw_request(operation, **parameters)
    state = raw_request("state")
    target = state["updates"] + parameters["count"]
    for attempt in range(64):
        for dialog in state["dialogs"]:
            if dialog["title"] == "Help System" and dialog["kind"] == 1:
                code = 1
            elif dialog["kind"] == 0 and dialog["message"].startswith(("There's a new cab company in town!", "Recently, there's been talk of strange happenings", "Greetings! The SimCity Entertainment Oversight Committee", "You can now spend time with your family and neighbors", "Dear home owner, Vacation Island Tours")):
                code = 0
            elif (os.environ.get("SIMS_TEST_SWIMMING") or os.environ.get("SIMS_TEST_STORIES_ONLY") or os.environ.get("SIMS_TEST_AUDIO_ONLY")) and dialog["kind"] == 0 and dialog["title"] in ["Car Pool", "School Bus"] and "will arrive in about an hour" in dialog["message"]:
                code = 0
            else:
                raise AssertionError(f"Unexpected game dialog during integration check: {dialog}")
            state = raw_request("dialogResponse", token=dialog["token"], code=code)
        remaining = target - state["updates"]
        if remaining <= 0:
            return state
        state = raw_request("step", count=remaining)
    raise AssertionError("Original startup dialogs did not finish")


try:
    hello = receive()
    assert hello["type"] == "hello" and hello["protocolVersion"] == 1
    assert hello["architecture"] == "Arm64"
    initial = request("state")
    assert initial["family"] is not None and len(initial["sims"]) >= 3
    if os.environ.get("SIMS_TEST_CUTAWAY_ONLY"):
        from native_cutaway_check import check_cutaway
        result = {"result": "passed", "cutaway": check_cutaway(request, raw_request)}
        assert hashlib.sha256(original.read_bytes()).hexdigest() == before
        result["baseLotUnchanged"] = True
        (root / "logs/native-cutaway-result.json").write_text(json.dumps(result, indent=2))
        print(json.dumps(result))
        raise SystemExit(0)
    if os.environ.get("SIMS_TEST_AUDIO_ONLY"):
        from native_audio_check import check_audio
        result = {"result": "passed", "audio": check_audio(request, raw_request, audio_events)}
        assert hashlib.sha256(original.read_bytes()).hexdigest() == before
        result["baseLotUnchanged"] = True
        (root / "logs/native-audio-result.json").write_text(json.dumps(result, indent=2))
        print(json.dumps(result))
        raise SystemExit(0)
    if os.environ.get("SIMS_TEST_ROOFS_ONLY"):
        from native_roof_check import check_roofs
        result = {"result": "passed", "roofs": check_roofs(request, raw_request)}
        assert hashlib.sha256(original.read_bytes()).hexdigest() == before
        result["baseLotUnchanged"] = True
        (root / "logs/native-roof-result.json").write_text(json.dumps(result, indent=2))
        print(json.dumps(result))
        raise SystemExit(0)
    if os.environ.get("SIMS_TEST_STORIES_ONLY"):
        from native_story_check import check_stories
        result = {"result": "passed", "stories": check_stories(request, raw_request)}
        (root / "logs/native-story-result.json").write_text(json.dumps(result, indent=2))
        print(json.dumps(result))
        raise SystemExit(0)
    if os.environ.get("SIMS_TEST_POOL_ONLY"):
        from native_water_check import check_water
        from native_pool_accessory_check import check_pool_accessories
        catalog = request("catalog")
        water = check_water(request, catalog)
        accessories = check_pool_accessories(request, water, swimming=bool(os.environ.get("SIMS_TEST_SWIMMING")))
        result = {"result": "passed", "water": water, "poolAccessories": accessories}
        if os.environ.get("SIMS_TEST_SWIMMING"):
            (root / "logs/native-swimming-result.json").write_text(json.dumps(result, indent=2))
        print(json.dumps(result))
        raise SystemExit(0)
    wall_scenes = {}
    for up in [False, True]:
        state = request("walls", up=up)
        assert state["wallsUp"] == up
        scene_path = Path(request("scene"))
        data = json.loads(scene_path.read_text())
        assert data["wallsUp"] == up and data["wallSprites"] > 0
        assert data["lotWidth"] == initial["width"] and data["lotHeight"] == initial["height"]
        assert len(data["terrainVertices"]) == initial["width"] * initial["height"] * 6
        meshes = [mesh for mesh in data["meshes"] if mesh["objectID"] > 0]
        assert {mesh["objectID"] for mesh in meshes} == {sim["id"] for sim in initial["sims"]}, "The resident family is missing rendered meshes"
        assert sum(len(mesh["vertices"]) for mesh in meshes) > 1000
        assert all(data["textures"][mesh["texture"]]["encoding"] in ["bmp", "tga"] for mesh in meshes)
        depth_sprites = [sprite for sprite in data["sprites"] if sprite.get("depthTexture") is not None]
        assert any(sprite["objectID"] > 0 for sprite in depth_sprites), "Original object sprite depth maps were not exported"
        for sprite in depth_sprites:
            texture = data["textures"][sprite["depthTexture"]]
            color = data["textures"][sprite["texture"]]
            assert texture["encoding"] == "depth8"
            assert (texture["width"], texture["height"]) == (color["width"], color["height"])
            assert len((scene_path.parent / texture["file"]).read_bytes()) == texture["width"] * texture["height"]
            assert 0 <= sprite["depthNear"] <= sprite["depthFar"] <= 1
            assert sprite["layer"] == 1
            if sprite.get("junction") or sprite.get("architectureDepth"):
                assert sprite["objectID"] == 0
            else:
                assert sprite["objectID"] != 0
        if os.environ.get("SIMS_TEST_CUSTOM_SKIN"):
            mortimer = next(sim for sim in initial["sims"] if sim["name"] == "Mortimer")
            skin = game / "GameData/Skins/B004MAFitlgt_rat.bmp"
            expected_hash = hashlib.sha256(skin.read_bytes()).hexdigest()
            assert any(expected_hash in data["textures"][mesh["texture"]]["file"] for mesh in meshes if mesh["objectID"] == mortimer["id"]), "The pack skin was replaced by the archived base-game texture"
        snapshot = scene_path.with_name("walls-up.json" if up else "walls-down.json")
        snapshot.write_text(json.dumps(data))
        wall_scenes[up] = data
    assert wall_scenes[True]["wallSprites"] >= wall_scenes[False]["wallSprites"]
    assert wall_scenes[True]["textures"] != wall_scenes[False]["textures"], "Wall masks did not change with the view mode"
    request("walls", up=False)
    catalog = request("catalog")
    from native_build_check import check_build_catalog
    build_catalog = check_build_catalog(request, catalog)
    custom = next((floor for floor in catalog["floors"] if floor["file"] == "native-custom-check.flr"), None)
    if os.environ.get("SIMS_TEST_CUSTOM_FLOOR"):
        assert custom, "Custom pack floor is absent from the simulation catalog"
        width = initial["width"]
        index = next(index for index, value in enumerate(initial["floors"]) if 0 < value < 65534 and initial["buildable"][index])
        request("architecture", command="FLOOR_RECT", x=index % width, y=index // width, level=1, x2=0, y2=0, pattern=custom["id"], style=0)
        for attempt in range(20):
            initial = request("step", count=4)
            if initial["floors"][index] == custom["id"]:
                break
            time.sleep(0.02)
        assert initial["floors"][index] == custom["id"], ("Custom floor was not applied", index, initial["floors"][index], custom, initial["budget"])
    time.sleep(0.15)
    assert request("state")["updates"] == initial["updates"]
    advanced = request("step", count=120)
    assert advanced["updates"] == initial["updates"] + 120
    assert (advanced["hours"], advanced["minutes"], advanced["seconds"]) != (initial["hours"], initial["minutes"], initial["seconds"])
    animated_scene = json.loads(Path(request("scene")).read_text())
    def mesh_positions(scene):
        return [(mesh["objectID"], [[vertex[axis] for axis in ["x", "y", "z"]] for vertex in mesh["vertices"]]) for mesh in scene["meshes"]]
    assert mesh_positions(animated_scene) != mesh_positions(wall_scenes[False]), "Sim mesh poses did not advance with simulation"
    slot = "check-" + uuid.uuid4().hex
    request("save", slot=slot)
    request("step", count=120)
    restored = request("load", slot=slot)
    for key in ["updates", "hours", "minutes", "seconds", "family", "budget", "sims", "floors"]:
        assert restored[key] == advanced[key], (key, restored[key], advanced[key])
    object_check = None
    if os.environ.get("SIMS_TEST_OBJECTS"):
        from native_object_check import check_objects
        assert {"buyObject", "moveObject", "sellObject"}.issubset(hello["commands"])
        object_check = check_objects(request, catalog)
        restored = request("load", slot=slot)
    menus = []
    menu_fixture = None
    renderable_ids = {sprite["objectID"] for sprite in animated_scene["sprites"]} | {mesh["objectID"] for mesh in animated_scene["meshes"]}
    for item in restored["objects"]:
        if item["avatar"] or item["id"] not in renderable_ids:
            continue
        menu = request("menu", objectID=item["id"])
        local = [entry for entry in menu if not entry["global"] and entry["name"]]
        if local:
            menus.append((item, local))
            if len(menus) == 3 and not os.environ.get("SIMS_TEST_MENU_FIXTURE"):
                break
    assert menus, "No original object interactions are available"
    if os.environ.get("SIMS_TEST_MENU_FIXTURE"):
        fixture_item, fixture_menu = max(menus, key=lambda pair: len(pair[1]))
        directory = root / "analysis/menu-check"
        directory.mkdir(parents=True, exist_ok=True)
        menu_fixture = directory / "original-menu.json"
        menu_fixture.write_text(json.dumps({"entries": fixture_menu, "objectID": fixture_item["id"], "selectedSim": restored["selectedSim"], "x": 430, "y": 300}))
        (directory / "state.json").write_text(json.dumps(restored))
    item, menu = menus[0]
    choice = menu[0]
    request("interact", objectID=item["id"], interaction=choice["interaction"], param0=choice["param0"], **{"global": choice["global"]})
    request("step", count=30)
    request("speed", value=3)
    time.sleep(0.2)
    running = request("state")
    assert running["updates"] > restored["updates"] + 30
    paused = request("speed", value=0)
    time.sleep(0.15)
    assert request("state")["updates"] == paused["updates"]
    scene = Path(request("scene"))
    assert json.loads(scene.read_text())["sprites"]
    request("quit")
    process.wait(timeout=10)
    assert process.returncode == 0
    assert hashlib.sha256(original.read_bytes()).hexdigest() == before
    print(json.dumps({"result": "passed", "architecture": hello["architecture"], "family": initial["family"], "sims": len(initial["sims"]), "interaction": choice["name"], "saveLoad": "clock, motives and family restored", "baseLotUnchanged": True, "customFloor": custom, "buildCatalog": build_catalog, "objectEditing": object_check, "skins": [{key: sim[key] for key in ["name", "bodyTexture", "headTexture"]} for sim in initial["sims"]], "wallsUp": wall_scenes[True]["wallSprites"], "wallsDown": wall_scenes[False]["wallSprites"], "depthSprites": len(depth_sprites), "menuFixture": str(menu_fixture) if menu_fixture else None, "scene": str(scene)}))
finally:
    if process.poll() is None:
        process.kill()
        process.wait()
    log.close()
