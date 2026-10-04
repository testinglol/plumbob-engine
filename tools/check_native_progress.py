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
log = (root / "logs/runtime-progress.log").open("w")
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


def receive():
    message = messages.get(timeout=30)
    if message is None:
        raise RuntimeError(f"Simulation exited with {process.poll()}; inspect {log.name}")
    if isinstance(message, Exception):
        raise message
    return message


def request(operation, **parameters):
    global sequence
    sequence += 1
    identifier = str(sequence)
    process.stdin.write(json.dumps({"id": identifier, "op": operation} | parameters) + "\n")
    process.stdin.flush()
    while True:
        message = receive()
        if message.get("type") == "response" and message.get("id") == identifier:
            if not message["ok"]:
                raise RuntimeError(message["error"])
            return message.get("result")


try:
    hello = receive()
    initial = request("state")
    request("speed", value=1)
    time.sleep(1.5)
    blocked = request("state")
    assert blocked["speed"] == -2
    dialog = next(item for item in blocked["dialogs"] if item["blocking"])
    assert dialog["kind"] == 1 and dialog["title"] == "Help System"
    assert "help system activated?" in dialog["message"]
    fixture = root / "analysis/menu-check/original-dialog.json"
    fixture.parent.mkdir(parents=True, exist_ok=True)
    fixture.write_text(json.dumps(dialog))
    print(json.dumps({"blockedAt": blocked["updates"], "dialog": dialog}))
    for operation, parameters in [("speed", {"value": 10}), ("step", {"count": 120}), ("dialogResponse", {"token": "stale", "code": 0}), ("dialogResponse", {"token": dialog["token"], "code": 2})]:
        try:
            request(operation, **parameters)
        except RuntimeError:
            pass
        else:
            raise AssertionError(f"Invalid blocked operation was accepted: {operation}")
        assert request("state")["speed"] == -2
    slot = "dialog-check-" + uuid.uuid4().hex
    request("save", slot=slot)
    restored = request("load", slot=slot)
    current = next(item for item in restored["dialogs"] if item["blocking"])
    assert current["token"] != dialog["token"] and current["message"] == dialog["message"]
    try:
        request("dialogResponse", token=dialog["token"], code=1)
    except RuntimeError:
        pass
    else:
        raise AssertionError("Response from before loading a save was accepted")
    resumed = request("dialogResponse", token=current["token"], code=1)
    assert resumed["speed"] == 1 and not resumed["dialogs"]
    time.sleep(1)
    state = request("state")
    assert state["updates"] > resumed["updates"], "Live simulation stalled after answering the game dialog"
    early_announcements = []
    for prompt in state["dialogs"]:
        assert prompt["kind"] == 0 and prompt["message"].startswith(("There's a new cab company", "Recently, there's been talk", "Greetings!", "You can now spend time", "Dear home owner")), prompt
        early_announcements.append(prompt["message"])
        state = request("dialogResponse", token=prompt["token"], code=0)
    assert state["speed"] == 1
    assert (state["hours"], state["minutes"], state["seconds"]) != (resumed["hours"], resumed["minutes"], resumed["seconds"])
    paused = request("speed", value=0)
    time.sleep(0.2)
    frozen = request("state")
    for key in ["sims", "objects", "hours", "minutes", "seconds", "updates", "dialogs"]:
        assert paused[key] == frozen[key], f"Paused simulation changed {key}"
    sofa = next(item for item in state["objects"] if "sofa" in item["name"].lower())
    choice = next(item for item in request("menu", objectID=sofa["id"]) if item["name"] == "Sit")
    request("interact", objectID=sofa["id"], interaction=choice["interaction"], param0=choice["param0"], **{"global": choice["global"]})
    request("step", count=2)
    start = request("state")
    resident = next(item for item in start["sims"] if item["id"] == start["selectedSim"])
    assert any(item["name"] == "Sit" for item in resident["actions"])
    end = start
    target_updates = start["updates"] + 600
    announcements = list(early_announcements)
    for attempt in range(40):
        assert not any(item["title"] == "SimAntics Exception!" for item in end["dialogs"]), end["dialogs"]
        for prompt in end["dialogs"]:
            assert prompt["kind"] in [0, 1, 2, 4], prompt
            announcements.append(prompt["message"])
            end = request("dialogResponse", token=prompt["token"], code=1 if prompt["kind"] == 1 else 0)
        remaining = target_updates - end["updates"]
        if remaining <= 0:
            break
        end = request("step", count=min(remaining, 100))
    else:
        raise AssertionError("Startup scripts never returned to the lot")
    sim_start = next(item for item in start["objects"] if item["id"] == start["selectedSim"])
    sim_end = next(item for item in end["objects"] if item["id"] == end["selectedSim"])
    assert (sim_start["x"], sim_start["y"]) != (sim_end["x"], sim_end["y"]), "Queued Sit action did not route the Sim"
    assert not end["dialogs"]
    seated = next(item for item in end["sims"] if item["id"] == end["selectedSim"])
    for attempt in range(24):
        if seated["posture"] == 1:
            break
        end = request("step", count=100)
        assert not end["dialogs"], end["dialogs"]
        seated = next(item for item in end["sims"] if item["id"] == end["selectedSim"])
    assert seated["posture"] == 1 and any(item["name"] == "Sit" and item["callee"] == sofa["id"] for item in seated["actions"]), "Sim reached the sofa but did not execute Sit"
    assert hashlib.sha256(original.read_bytes()).hexdigest() == before
    print(json.dumps({"result": "passed", "dialogResponse": "No", "resumedSpeed": resumed["speed"], "updates": end["updates"], "simMoved": [sim_start["x"], sim_start["y"], sim_end["x"], sim_end["y"]], "seatedPosture": seated["posture"], "saveRestoresDialog": True, "staleResponsesRejected": True, "baseLotUnchanged": True, "startupAnnouncements": announcements, "scene": request("scene")}))
    request("quit")
    process.wait(timeout=10)
finally:
    if process.poll() is None:
        process.kill()
        process.wait()
    log.close()
