"""A compiled outfit chosen at a dresser, worn on the lot and after a reload.

Compiles examples/outfit-pack.json, mounts it over the game and starts the simulation host on House 5 of a fresh profile.
Mortimer buys Dresser - Cheap and uses Change Clothes. The wardrobe must list the compiled outfit; choosing it must
re-dress him on the spot (the original dresser sets the everyday outfit and the Sim walks away wearing it), and a second
host started on the saved lot must come back with him still wearing it.
Results are written to logs/native-wardrobe-result.json.

Needs the simulation host and SimsNative or SimsSDL built in release.
"""
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
game = root / "runtime/game"
session = root / "runtime/native-sessions" / ("wardrobe-" + uuid.uuid4().hex)
profile_id = "wardrobe-" + uuid.uuid4().hex[:12]
profile = root / "runtime/native-profiles" / profile_id
host_binary = root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"
environment = os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")}
binary = next((root / "native/SimsNative/.build/release" / name for name in ["SimsNative", "SimsSDL"]
               if (root / "native/SimsNative/.build/release" / name).exists()), None)
dresser = 265604335  # Dresser - Cheap
change_clothes = 11
outfit = "b950mafit_teal"
texture = "b950mafitlgt_teal"


class Host:
    def __init__(self, content, name):
        self.log = (session / (name + ".log")).open("w")
        self.process = subprocess.Popen([shutil.which("dotnet"), str(host_binary), str(content), str(root), "--serve", str(session / name), "5",
                                         "--profile-id", profile_id],
                                        stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=self.log, text=True, env=environment)
        self.messages = queue.Queue()
        self.sequence = 0
        threading.Thread(target=self.read, daemon=True).start()
        assert self.receive()["type"] == "hello"

    def read(self):
        try:
            for line in self.process.stdout:
                self.messages.put(json.loads(line))
        finally:
            self.messages.put(None)

    def receive(self):
        message = self.messages.get(timeout=120)
        if message is None:
            raise RuntimeError(f"Simulation exited with {self.process.poll()}; inspect {self.log.name}")
        return message

    def request(self, operation, **parameters):
        self.sequence += 1
        identifier = str(self.sequence)
        self.process.stdin.write(json.dumps({"id": identifier, "op": operation} | parameters) + "\n")
        self.process.stdin.flush()
        while True:
            message = self.receive()
            if message.get("type") == "response" and message.get("id") == identifier:
                if not message["ok"]:
                    raise RuntimeError(message["error"])
                return message.get("result")

    def step(self, count):
        state = self.request("state")
        target = state["updates"] + count
        for _ in range(64):
            for dialog in state["dialogs"]:
                state = self.request("dialogResponse", token=dialog["token"], code=0)
            if state["updates"] >= target:
                return state
            state = self.request("step", count=target - state["updates"])
        raise AssertionError("The simulation did not advance")

    def buy(self, guid, state):
        # A multi-tile object's parts carry their own GUIDs, so take whatever appeared.
        self.request("view", editing=True)
        width = state["width"]
        occupied = {(int(item["x"]), int(item["y"])) for item in state["objects"] if item["level"] == 1}
        known = {item["id"] for item in state["objects"]}
        for index, allowed in enumerate(state["buildable"]):
            x, y = index % width, index // width
            if not allowed or any((x + dx, y + dy) in occupied for dx in range(-1, 3) for dy in range(-1, 3)):
                continue
            self.request("buyObject", guid=guid, x=x * 16 + 8, y=y * 16 + 8, level=1, direction=1)
            for _ in range(25):
                time.sleep(0.02)
                after = self.request("state")
                bought = [item for item in after["objects"] if item["id"] not in known]
                if bought:
                    self.request("view", editing=False)
                    return bought, after
        raise AssertionError(f"No tile accepted object 0x{guid:08X}")

    def close(self):
        try:
            self.request("quit")
        except RuntimeError:
            pass
        self.process.wait(timeout=60)
        self.log.close()


def selected(state):
    return next(sim for sim in state["sims"] if sim["name"].startswith("Mortimer"))


def main():
    assert binary, "Build SimsNative or SimsSDL in release first"
    session.mkdir(parents=True)
    packs = session / "packs"
    mount = session / "game"
    try:
        process = subprocess.run([shutil.which("dotnet"), str(host_binary), "--compile-outfit", str(root / "examples/outfit-pack.json"), str(game),
                                  str(packs / "example.teal-jeans")], env=environment, capture_output=True, text=True)
        assert process.returncode == 0, process.stderr[-2000:]
        subprocess.run([str(binary), "--game", str(game), "--packs", str(packs), "--mount", str(mount)], check=True, capture_output=True, text=True)

        host = Host(mount, "play")
        try:
            state = host.step(30)
            before = selected(state)["bodyTexture"]
            assert before and before.lower() != texture, before
            parts, state = host.buy(dresser, state)
            part = next(item for item in parts if any(entry["name"] == "Change Clothes" for entry in host.request("menu", objectID=item["id"])))
            host.request("interact", objectID=part["id"], interaction=change_clothes, param0=0)
            choices = None
            for _ in range(200):
                state = host.request("state")
                if state["dialogs"]:
                    try:
                        choices = host.request("outfitChoices")["choices"]
                        break
                    except RuntimeError:  # a dialog that is not the wardrobe
                        host.request("dialogResponse", token=state["dialogs"][0]["token"], code=0)
                        continue
                host.request("step", count=30)
            assert choices, "The dresser never opened the wardrobe"
            names = [choice["name"] for choice in choices]
            assert outfit in names, f"The wardrobe does not offer {outfit}: {names}"
            index = next(choice["index"] for choice in choices if choice["name"] == outfit)
            host.request("dialogResponse", token=state["dialogs"][0]["token"], code=1, text=str(index))
            worn = None
            for step in range(60):
                state = host.step(30)
                worn = selected(state)["bodyTexture"]
                if worn and worn.lower() == texture:
                    break
            assert worn and worn.lower() == texture, f"Mortimer still wears {worn} after choosing {outfit}"
            changed_after = step + 1
            host.request("save", slot="wardrobe", lot=True)
        finally:
            host.close()

        host = Host(mount, "reload")
        try:
            state = host.request("state")
            reloaded = selected(state)["bodyTexture"]
            assert reloaded and reloaded.lower() == texture, f"After reloading, Mortimer wears {reloaded}"
        finally:
            host.close()

        result = {"result": "passed", "before": before, "offered": len(names), "outfit": outfit, "wornAfterSteps": changed_after * 30,
                  "reloaded": reloaded}
        (root / "logs").mkdir(exist_ok=True)
        (root / "logs/native-wardrobe-result.json").write_text(json.dumps(result, indent=2))
        print(json.dumps(result))
    finally:
        shutil.rmtree(session, ignore_errors=True)  # holds a full copy of the game
        shutil.rmtree(profile, ignore_errors=True)


if __name__ == "__main__":
    main()
