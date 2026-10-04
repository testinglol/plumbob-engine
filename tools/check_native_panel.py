import hashlib
import json
import os
from pathlib import Path
import queue
import shutil
import subprocess
import struct
import threading
import time
import uuid


root = Path(__file__).resolve().parents[1]
session = root / "runtime/native-sessions" / ("panel-" + uuid.uuid4().hex)
fixture = root / "analysis/gameplay-panel"
fixture.mkdir(parents=True, exist_ok=True)
original = root / "runtime/game/UserData/Houses/House05.iff"
before = hashlib.sha256(original.read_bytes()).hexdigest()
slot = "panel-check-" + uuid.uuid4().hex
log = (root / "logs/runtime-panel.log").open("w")
process = subprocess.Popen([shutil.which("dotnet"), str(root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"), str(root / "runtime/game"), str(root), "--serve", str(session), "5"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=log, text=True, env=os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")})
messages = queue.Queue()
sequence = 0


def original_residents():
    data = (root / "runtime/game/UserData/Neighborhood.iff").read_bytes()
    position = 64
    while position + 76 <= len(data):
        size = int.from_bytes(data[position + 4:position + 8], "big")
        assert size >= 76 and position + size <= len(data)
        if data[position:position + 4] == b"NBRS":
            chunk = data[position + 76:position + size]
            break
        position += size
    else:
        raise AssertionError("Original neighborhood has no residents")
    assert chunk[8:12] == b"SRBN"
    position = 16
    residents = {}
    for index in range(struct.unpack_from("<I", chunk, 12)[0]):
        occupied = struct.unpack_from("<i", chunk, position)[0]
        position += 4
        if occupied != 1:
            continue
        version = struct.unpack_from("<i", chunk, position)[0]
        position += 4 + (4 if version == 10 else 0)
        end = chunk.index(0, position)
        name = chunk[position:end].decode("latin1")
        position = end + 1 + (1 if len(name) % 2 == 0 else 0)
        mode = struct.unpack_from("<i", chunk, position + 4)[0]
        position += 8
        person = None
        if mode > 0:
            size = 160 if version == 4 else 512
            person = struct.unpack_from("<" + "h" * (size // 2), chunk, position)
            position += size
        neighbor_id = struct.unpack_from("<h", chunk, position)[0]
        position += 10
        relationships = struct.unpack_from("<i", chunk, position)[0]
        position += 4
        for relationship in range(relationships):
            key_count, key, value_count = struct.unpack_from("<iii", chunk, position)
            assert key_count == 1 and value_count >= 0
            position += 12 + value_count * 4
        if person:
            residents[neighbor_id] = {"personality": {name: person[field] for name, field in [("Neat", 7), ("Outgoing", 6), ("Active", 3), ("Playful", 5), ("Nice", 2)]}, "personType": person[32], "zodiac": person[70],
                                      "skills": {name: person[field] for name, field in [("Cooking", 10), ("Mechanical", 12), ("Charisma", 11), ("Body", 17), ("Logic", 18), ("Creativity", 15)]},
                                      "career": {"type": person[56], "level": person[57], "age": person[58]},
                                      "interests": [person[field] for field in [46, 47, 48, 49, 50, 51, 52, 53, 46, 47, 48, 49, 13, 14, 16, 20, 26, 54, 55]]}
    return residents


def read_output():
    try:
        for line in process.stdout:
            messages.put(json.loads(line))
    except Exception as error:
        messages.put(error)
    finally:
        messages.put(None)


threading.Thread(target=read_output, daemon=True).start()


def request(operation, **parameters):
    global sequence
    sequence += 1
    identifier = str(sequence)
    process.stdin.write(json.dumps({"id": identifier, "op": operation} | parameters) + "\n")
    process.stdin.flush()
    while True:
        message = messages.get(timeout=30)
        if message is None:
            raise RuntimeError(f"Simulation exited with {process.poll()}; inspect {log.name}")
        if isinstance(message, Exception):
            raise message
        if message.get("type") == "response" and message.get("id") == identifier:
            if not message["ok"]:
                raise RuntimeError(message["error"])
            return message.get("result")


def rejected(operation, **parameters):
    try:
        request(operation, **parameters)
    except RuntimeError:
        return
    raise AssertionError(f"Invalid {operation} accepted")


def resident(state):
    return next(sim for sim in state["sims"] if sim["id"] == state["selectedSim"])


def original_values(sim, expected):
    observed = {key: sim[key] for key in expected}
    observed["career"] = {key: sim["career"][key] for key in expected["career"]}
    return observed


def advance(state, count):
    for attempt in range(64):
        for dialog in state["dialogs"]:
            assert dialog["kind"] in [0, 1, 2, 4] and dialog["title"] != "SimAntics Exception!", dialog
            state = request("dialogResponse", token=dialog["token"], code=1 if dialog["kind"] == 1 else 0)
        if count <= 0 and not state["dialogs"]:
            return state
        previous = state["updates"]
        state = request("step", count=min(100, max(1, count)))
        count -= state["updates"] - previous
    raise AssertionError("Game scripts did not return to the lot")


try:
    source_residents = original_residents()
    state = advance(request("state"), 800)
    state = request("speed", value=0)
    household = [sim for sim in state["sims"] if sim["household"]]
    assert len(household) == 3 and state["selectedSim"] in [sim["id"] for sim in household]
    saved_careers = {sim["neighborID"]: sim["career"] for sim in household}
    for sim in household:
        expected = source_residents[sim["neighborID"]]
        assert original_values(sim, expected) == expected, (sim["name"], expected, sim)
        career = sim["career"]
        if career["currentLevelRequirements"] is not None:
            assert len(career["currentLevelRequirements"]) == 10 and isinstance(career["title"], str)
            assert career["salary"] is not None and career["startHour"] is not None and career["endHour"] is not None
        portrait = sim["portrait"]
        assert portrait and portrait["columns"] == 3 and portrait["rows"] == 1
        data = (session / "scene" / portrait["file"]).read_bytes()
        assert data[:2] == b"BM" and hashlib.sha256(data).hexdigest() in portrait["file"]
        chosen = request("selectSim", objectID=sim["id"])
        assert chosen["selectedSim"] == sim["id"]
    for sim in state["sims"]:
        if not sim["household"]:
            rejected("selectSim", objectID=sim["id"])
    rejected("selectSim", objectID=32767)
    assert request("state")["selectedSim"] == household[-1]["id"]
    state = request("selectSim", objectID=household[0]["id"])
    (fixture / "live-state.json").write_text(json.dumps(state))
    sofa = next(item for item in state["objects"] if "sofa" in item["name"].lower())
    choice = next(item for item in request("menu", objectID=sofa["id"]) if item["name"] == "Sit")
    request("interact", objectID=sofa["id"], interaction=choice["interaction"], param0=choice["param0"], **{"global": choice["global"]})
    state = request("step", count=2)
    action = next(action for action in resident(state)["actions"] if action["name"] == "Sit" and action["callee"] == sofa["id"])
    assert action["visible"] and action["cancellable"] and action["icon"]
    request("save", slot=slot)
    rejected("cancelAction", objectID=household[1]["id"], token=action["token"])
    rejected("cancelAction", objectID=state["selectedSim"], token="stale")
    restored = request("load", slot=slot)
    for sim in restored["sims"]:
        if sim["household"]:
            expected = source_residents[sim["neighborID"]]
            assert original_values(sim, expected) == expected
            assert sim["career"] == saved_careers[sim["neighborID"]]
    rejected("cancelAction", objectID=state["selectedSim"], token=action["token"])
    restored_action = next(item for item in resident(restored)["actions"] if item["name"] == "Sit" and item["callee"] == sofa["id"])
    assert restored_action["token"] != action["token"]
    pending = request("cancelAction", objectID=restored["selectedSim"], token=restored_action["token"])
    pending_action = next((item for item in resident(pending)["actions"] if item["token"] == restored_action["token"]), None)
    assert pending_action is None or pending_action["cancelRequested"]
    state = advance(pending, 200)
    assert not any(item["token"] == restored_action["token"] for item in resident(state)["actions"])
    rejected("cancelAction", objectID=state["selectedSim"], token=restored_action["token"])
    request("interact", objectID=sofa["id"], interaction=choice["interaction"], param0=choice["param0"], **{"global": choice["global"]})
    state = request("step", count=2)
    queued_scene = request("scene")
    (fixture / "queued-state.json").write_text(json.dumps(state))
    for attempt in range(40):
        if resident(state)["posture"] == 1:
            break
        state = advance(state, 100)
    else:
        raise AssertionError("Sim did not sit down")
    active = next(item for item in resident(state)["actions"] if item["name"] == "Sit" and item["active"])
    cancelled = request("cancelAction", objectID=state["selectedSim"], token=active["token"])
    assert next(item for item in resident(cancelled)["actions"] if item["token"] == active["token"])["cancelRequested"]
    state = advance(cancelled, 400)
    assert not any(item["token"] == active["token"] for item in resident(state)["actions"]), "Active Sit did not complete cancellation"
    assert hashlib.sha256(original.read_bytes()).hexdigest() == before
    result = {"result": "passed", "householdPortraits": len(household), "personalityMatchesOriginalNeighborhood": True, "personalitySurvivesSaveLoad": True, "skillsAndCareerMatchOriginalNeighborhood": True, "skillsAndCareerSurviveSaveLoad": True, "invalidSelectionPreservesState": True, "staleActionRejectedAfterLoad": True, "wrongSimCancellationRejected": True, "queuedCancellation": True, "activeSitCancellation": True, "baseLotUnchanged": True, "scene": queued_scene, "panelState": str(fixture / "queued-state.json")}
    (root / "logs/native-panel-result.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result))
    request("quit")
    process.wait(timeout=10)
finally:
    if process.poll() is None:
        process.kill()
        process.wait()
    log.close()
    save = root / "runtime/native-profiles/player/Saves" / (slot + ".json")
    if save.exists():
        save.unlink()
