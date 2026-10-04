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
log = (root / "logs/runtime-animation.log").open("w")
process = subprocess.Popen([shutil.which("dotnet"), str(root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"), str(game), str(root), "--serve", str(session), "5"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=log, text=True, env=environment)
messages = queue.Queue()


def read_output():
    try:
        for line in process.stdout:
            messages.put((time.monotonic(), json.loads(line)))
    except Exception as error:
        messages.put(error)
    finally:
        messages.put(None)


threading.Thread(target=read_output, daemon=True).start()
sequence = 0


def receive():
    _, message = messages.get(timeout=30)
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
    state = request("state")
    announcements = []
    for attempt in range(30):
        for prompt in state["dialogs"]:
            assert prompt["title"] != "SimAntics Exception!", prompt
            if prompt["kind"] == 1:
                assert prompt["title"] == "Help System", prompt
                code = 1
            else:
                assert prompt["kind"] == 0 and prompt["message"].startswith(("There's a new cab company", "Recently, there's been talk", "Greetings!", "You can now spend time", "Dear home owner")), prompt
                code = 0
            announcements.append(prompt["message"])
            state = request("dialogResponse", token=prompt["token"], code=code)
        if state["updates"] >= 420 and not state["dialogs"]:
            break
        state = request("step", count=100)
    else:
        raise AssertionError("Startup did not complete")
    sofa = next(item for item in state["objects"] if "sofa" in item["name"].lower())
    choice = next(item for item in request("menu", objectID=sofa["id"]) if item["name"] == "Sit")
    request("interact", objectID=sofa["id"], interaction=choice["interaction"], param0=choice["param0"], **{"global": choice["global"]})
    state = request("step", count=20)
    request("stream", enabled=True)
    baseline_path = sorted((session / "scene").glob("scene-*.json"), key=lambda path: int(path.stem.split("-")[-1]))[-1]
    baseline_revision = int(baseline_path.stem.split("-")[-1])
    original_textures = {path: path.stat().st_mtime_ns for path in (session / "scene").iterdir() if path.suffix != ".json"}
    start = request("speed", value=1)
    frames = []
    timestamps = []
    full_frames = 0
    end_time = time.monotonic() + 2.5
    while time.monotonic() < end_time:
        received, event = messages.get(timeout=10)
        assert event is not None
        if event["type"] == "frame":
            full_frames += 1
            baseline_path = Path(event["scene"])
            baseline_revision = event["revision"]
            frames.clear()
            timestamps.clear()
        if event["type"] == "state":
            assert not event["state"]["dialogs"], event["state"]["dialogs"]
        if event["type"] != "animation":
            continue
        frame = event["frame"]
        assert frame["baseRevision"] == baseline_revision
        assert not frames or frame["sequence"] > frames[-1]["sequence"]
        assert "terrainVertices" not in frame
        assert all(sprite["objectID"] > 0 for sprite in frame["sprites"])
        frames.append(frame)
        timestamps.append(received)
    end = request("speed", value=0)
    time.sleep(0.25)
    pending = []
    while not messages.empty():
        _, event = messages.get_nowait()
        pending.append(event)
    assert not any(event and event["type"] == "animation" for event in pending), "Paused game kept streaming poses"
    frozen = request("state")
    assert frozen["updates"] == end["updates"] and frozen["objects"] == end["objects"]
    assert end["updates"] - start["updates"] >= 120, (start["updates"], end["updates"])
    assert len(frames) >= 30, len(frames)
    fps = (len(frames) - 1) / (timestamps[-1] - timestamps[0])
    assert 24 <= fps <= 36, fps
    pose_hashes = {hashlib.sha256(json.dumps(frame["meshes"]).encode()).hexdigest() for frame in frames}
    assert len(pose_hashes) >= 15, len(pose_hashes)
    assert all(path.stat().st_mtime_ns == modified for path, modified in original_textures.items()), "Cached texture was rewritten"
    snapshot = json.loads(baseline_path.read_text())
    texture_count = len(snapshot["textures"])
    for frame in frames:
        assert frame["textureStart"] == texture_count
        texture_count += len(frame["textures"])
    try:
        request("sceneAck", revision=baseline_revision + 100)
    except RuntimeError:
        pass
    else:
        raise AssertionError("Acknowledgement from a future snapshot was accepted")
    request("sceneAck", revision=baseline_revision)
    assert len(list((session / "scene").glob("scene-*.json"))) <= 2
    assert baseline_path.exists()
    fixture = root / "analysis/animation-check"
    fixture.mkdir(parents=True, exist_ok=True)
    (fixture / "first.json").write_text(json.dumps(frames[0]))
    (fixture / "frames.jsonl").write_text("\n".join(json.dumps(frame) for frame in frames) + "\n")
    result = {"result": "passed", "frames": len(frames), "framesPerSecond": round(fps, 2), "distinctPoses": len(pose_hashes), "updatesPerSecond": round((end["updates"] - start["updates"]) / 2.5, 2), "fullSnapshots": full_frames, "scene": str(baseline_path), "stream": str(fixture / "frames.jsonl"), "pauseStopsStream": True, "cachedTexturesUnchanged": True, "acknowledgedSnapshotCleanup": True}
    (root / "logs/native-animation-result.json").write_text(json.dumps(result, indent=2))
    print(json.dumps(result))
    request("quit")
    process.wait(timeout=10)
    assert process.returncode == 0
    assert hashlib.sha256(original.read_bytes()).hexdigest() == before
finally:
    if process.poll() is None:
        process.terminate()
        process.wait(timeout=10)
    log.close()
