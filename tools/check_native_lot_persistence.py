"""Saving a lot into its house file and coming back to it.

Starts the simulation host on House 5 of a fresh profile, buys a flamingo and lets time pass, then saves. A save without
`lot` must leave UserData/Houses/House05.iff untouched; a save with `lot` (what the clients send for "Save House") must
write the lot into it. A second host started on the same lot must then come back with the flamingo where it was, the
family budget after the purchase and the saved time of day, and the neighborhood view must still read the house file.
Evicting the family must drop the saved lot.
Results are written to logs/native-lot-persistence-result.json.

Needs the simulation host built in Release.
"""
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
session = root / "runtime/native-sessions" / ("lot-persistence-" + uuid.uuid4().hex)
profile_id = "lot-persistence-" + uuid.uuid4().hex[:12]
profile = root / "runtime/native-profiles" / profile_id
host_binary = root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"
environment = os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")}
flamingo = 0x3659DCA2


class Host:
    def __init__(self, name):
        session.mkdir(parents=True, exist_ok=True)
        self.log = (session / (name + ".log")).open("w")
        self.process = subprocess.Popen([shutil.which("dotnet"), str(host_binary), str(root / "runtime/game"), str(root), "--serve", str(session / name), "5",
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
        self.request("view", editing=True)
        width = state["width"]
        occupied = {(int(item["x"]), int(item["y"])) for item in state["objects"] if item["level"] == 1}
        known = {item["id"] for item in state["objects"]}
        for index, allowed in enumerate(state["buildable"]):
            x, y = index % width, index // width
            if not allowed or any((x + dx, y + dy) in occupied for dx in range(-1, 2) for dy in range(-1, 2)):
                continue
            for _ in range(50):
                try:
                    self.request("buyObject", guid=guid, x=x * 16 + 8, y=y * 16 + 8, level=1, direction=1)
                    break
                except RuntimeError as error:
                    if "active construction command" not in str(error):
                        raise
                    time.sleep(0.05)
            for _ in range(25):
                time.sleep(0.02)
                after = self.request("state")
                bought = [item for item in after["objects"] if item["id"] not in known and item["guid"] == guid]
                if bought:
                    self.request("view", editing=False)
                    return bought[0], after
        raise AssertionError(f"No tile accepted object 0x{guid:08X}")

    def close(self):
        try:
            self.request("quit")
        except RuntimeError:
            pass
        self.process.wait(timeout=60)
        self.log.close()


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def placed(state, guid):
    return sorted((item["x"], item["y"], item["level"], item["direction"]) for item in state["objects"] if item["guid"] == guid)


def main():
    house_file = profile / "UserData/Houses/House05.iff"
    try:
        first = Host("first")
        try:
            start = first.request("state")
            assert start["family"] is not None, "House 5 has no household"
            item, bought = first.buy(flamingo, start)
            assert bought["budget"] < start["budget"], "Buying the flamingo did not charge the family"
            saved = first.step(300)
            original = digest(house_file)
            slot = first.request("save", slot="persistence")
            assert not slot["lot"] and digest(house_file) == original, "A slot-only save changed the house file"
            lot = first.request("save", slot="persistence", lot=True)
            assert lot["lot"] and lot["lotBytes"] > 0, f"The lot was not saved into its house file: {lot}"
            assert digest(house_file) != original, "Saving the lot did not change the house file"
            saved = first.request("state")
        finally:
            first.close()
        assert b"FSOV" in house_file.read_bytes(), "The house file has no saved simulation"

        second = Host("second")
        try:
            back = second.request("state")
            assert placed(back, flamingo) == placed(saved, flamingo), f"The flamingo did not come back: {placed(back, flamingo)} != {placed(saved, flamingo)}"
            assert back["budget"] == saved["budget"], f"The budget came back as {back['budget']}, not {saved['budget']}"
            assert back["family"] == saved["family"], "Another family came back to the lot"
            assert (back["hours"], back["minutes"]) == (saved["hours"], saved["minutes"]), "The time of day was not restored"
            assert sorted(sim["name"] for sim in back["sims"] if sim["household"]) == sorted(sim["name"] for sim in saved["sims"] if sim["household"]), \
                "The household did not come back"
            neighborhood = second.request("neighborhood", mode=1)
            entry = next(entry for entry in neighborhood["entries"] if entry["house"] == 5)
            assert entry["occupied"], "The neighborhood view lost the household"
            running = second.step(120)
            assert running["updates"] >= back["updates"] + 120
        finally:
            second.close()

        # Moving the family out drops the saved simulation, so it cannot come back with the next family (or with them).
        evict = subprocess.run([shutil.which("dotnet"), str(host_binary), str(root / "runtime/game"), str(root), "--export-neighborhood", str(session / "evict"), "1",
                                "--profile-id", profile_id, "--edit", "evict:5"], env=environment, text=True, capture_output=True, timeout=300)
        assert evict.returncode == 0, evict.stderr[-2000:]
        assert b"FSOV" not in house_file.read_bytes(), "Eviction left the family's saved lot in the house file"

        result = {"result": "passed", "flamingo": placed(saved, flamingo), "budget": saved["budget"], "time": [saved["hours"], saved["minutes"]],
                  "houseBytes": house_file.stat().st_size, "lotBytes": lot["lotBytes"]}
        (root / "logs").mkdir(exist_ok=True)
        (root / "logs/native-lot-persistence-result.json").write_text(json.dumps(result, indent=2))
        print(json.dumps(result))
    finally:
        shutil.rmtree(profile, ignore_errors=True)
        shutil.rmtree(session, ignore_errors=True)


if __name__ == "__main__":
    main()
