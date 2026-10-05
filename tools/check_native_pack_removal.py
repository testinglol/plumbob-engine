"""Uninstalling a pack whose object is on a saved lot.

Builds a pack holding a copy of the original flamingo under its own GUID, buys it on House 5 and queues a Sim on it,
saves, then starts a host on content without the pack. Loading must be refused until the client opts in with
`removePacks`; the opted-in load removes the flamingo, refunds it, resets the Sim, drops the pack from the save's
records and keeps the simulation running. Results are written to logs/native-pack-removal-result.json.

Needs a pack tool binary (SimsNative on macOS or SimsSDL elsewhere; override with SIMS_PACK_TOOL) and the
simulation host built in Release.
"""
import json
import os
from pathlib import Path
import queue
import shutil
import struct
import subprocess
import threading
import time
import uuid


root = Path(__file__).resolve().parents[1]
session = root / "runtime/native-sessions" / ("pack-removal-" + uuid.uuid4().hex)
packs = session / "packs"
pack_id = "local.removal-check"
guid = 0xF1A0_0071
price = 37


def flamingo_fixture():
    archive = (root / "runtime/game/GameData/Objects/Objects.far").read_bytes()
    assert archive[:8] == b"FAR!byAZ" and struct.unpack_from("<I", archive, 8)[0] == 1
    cursor = struct.unpack_from("<I", archive, 12)[0]
    count = struct.unpack_from("<I", archive, cursor)[0]
    cursor += 4
    for _ in range(count):
        size, stored, offset, length = struct.unpack_from("<4I", archive, cursor)
        cursor += 16
        name = archive[cursor:cursor + length].decode("latin1")
        cursor += length
        if name.lower() == "flamingo.iff":
            assert size == stored
            fixture = bytearray(archive[offset:offset + size])
            break
    else:
        raise AssertionError("Original flamingo resource was not found")
    cursor = 64
    while cursor < len(fixture):
        size = struct.unpack_from(">I", fixture, cursor + 4)[0]
        if fixture[cursor:cursor + 4] == b"OBJD":
            payload = cursor + 76
            struct.pack_into("<I", fixture, payload + 28, guid)
            struct.pack_into("<H", fixture, payload + 36, price)
        cursor += size
    return bytes(fixture)


def pack_tool():
    if os.environ.get("SIMS_PACK_TOOL"):
        return [os.environ["SIMS_PACK_TOOL"]]
    for name in ["SimsNative", "SimsSDL"]:
        binary = root / "native/SimsNative/.build/release" / name
        if binary.exists():
            return [str(binary)]
    raise AssertionError("Build SimsNative or SimsSDL in release first")


def mount(name, collection):
    destination = session / name
    subprocess.run(pack_tool() + ["--game", str(root / "runtime/game"), "--packs", str(collection), "--mount", str(destination)],
                   check=True, stdout=subprocess.DEVNULL)
    return destination


class Host:
    def __init__(self, content, name):
        environment = os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")}
        self.log = (session / (name + ".log")).open("w")
        host = root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"
        self.process = subprocess.Popen([shutil.which("dotnet"), str(host), str(content), str(root), "--serve", str(session / name), "5"],
                                        stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=self.log, text=True, env=environment)
        self.messages = queue.Queue()
        self.events = []
        self.sequence = 0
        threading.Thread(target=self.read, daemon=True).start()
        hello = self.receive()
        assert hello["type"] == "hello", hello

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
        if operation in ["buyObject"]:
            self.request("view", editing=True)
        self.sequence += 1
        identifier = str(self.sequence)
        self.process.stdin.write(json.dumps({"id": identifier, "op": operation} | parameters) + "\n")
        self.process.stdin.flush()
        while True:
            message = self.receive()
            if message.get("type") == "frame" and message.get("revision"):
                self.revision = message["revision"]
            elif message.get("type") not in ["response", "frame", "animation", "audio"]:
                self.events.append(message)
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

    def close(self):
        try:
            self.request("quit")
        except RuntimeError:
            pass
        self.process.wait(timeout=60)
        self.log.close()


def main():
    asset = packs / pack_id / "files/Downloads" / pack_id / "removal-flamingo.iff"
    asset.parent.mkdir(parents=True)
    asset.write_bytes(flamingo_fixture())
    (packs / pack_id / "pack.json").write_text(json.dumps({"schemaVersion": 1, "id": pack_id, "name": "Pack removal fixture", "version": "0.1.0",
                                                          "baseGameVersion": "1.90", "dependencies": [], "overrides": []}))
    empty = session / "no-packs"
    empty.mkdir()
    with_pack = mount("with-pack", packs)
    without_pack = mount("without-pack", empty)
    slot = "removal-" + uuid.uuid4().hex[:12]

    host = Host(with_pack, "installed")
    try:
        baseline = host.step(30)
        catalog = host.request("catalog")
        assert any(item["guid"] == guid for item in catalog["objects"]), "The pack object is missing from the catalog"
        width = baseline["width"]
        occupied = {(int(item["x"]), int(item["y"])) for item in baseline["objects"] if item["level"] == 1}
        tiles = [(index % width, index // width) for index, allowed in enumerate(baseline["buildable"])
                 if allowed and (index % width, index // width) not in occupied]
        known = {item["id"] for item in baseline["objects"]}
        bought = None
        for x, y in tiles[:20]:
            host.request("buyObject", guid=guid, x=x * 16 + 8, y=y * 16 + 8, level=1, direction=1)
            for _ in range(50):
                time.sleep(0.02)
                state = host.request("state")
                bought = next((item for item in state["objects"] if item["id"] not in known and item["guid"] == guid), None)
                if bought:
                    break
            if bought:
                break
        assert bought, "No tested tile accepted the pack object"
        assert state["budget"] == baseline["budget"] - price
        host.request("view", editing=False)
        menu = [entry for entry in host.request("menu", objectID=bought["id"]) if not entry["global"]]
        assert menu, "The pack object has no interactions"
        host.request("interact", objectID=bought["id"], interaction=menu[0]["interaction"], param0=menu[0]["param0"])
        saved = host.step(10)
        host.request("save", slot=slot)
    finally:
        host.close()

    host = Host(without_pack, "removed")
    try:
        assert not any(item["guid"] == guid for item in host.request("catalog")["objects"])
        try:
            host.request("load", slot=slot)
            raise AssertionError("A save that needs a removed pack loaded without consent")
        except RuntimeError as error:
            assert pack_id in str(error) and "removePacks" in str(error), error
        restored = host.request("load", slot=slot, removePacks=True)
        migrated = next(event for event in host.events if event.get("type") == "saveMigrated")
        assert migrated["removed"] == [pack_id + "@0.1.0"], migrated
        assert [item["guid"] for item in migrated["removedObjects"]] == [guid], migrated
        refund = migrated["refund"]
        assert 0 < refund <= price, migrated
        assert migrated["resetObjects"] >= 1, "The Sim queued on the removed object was not reset"
        assert migrated["backup"], "No backup was taken before removing the pack"
        assert not any(item["guid"] == guid for item in restored["objects"])
        assert restored["budget"] == saved["budget"] + refund, (restored["budget"], saved["budget"], refund)
        assert len([item for item in restored["objects"] if item["avatar"]]) == len([item for item in saved["objects"] if item["avatar"]])
        advanced = host.step(300)
        assert advanced["updates"] >= restored["updates"] + 300
        host.request("save", slot=slot)
        host.events.clear()
        host.request("load", slot=slot)
        assert not any(event.get("type") == "saveMigrated" for event in host.events), "A save without the pack still needs migration"
        backups = host.request("saveBackups", slot=slot)["backups"]
        assert migrated["backup"] in backups
    finally:
        host.close()

    result = {"result": "passed", "pack": pack_id, "guid": guid, "refund": refund, "resetObjects": migrated["resetObjects"],
              "consentRequired": True, "backup": migrated["backup"], "simulationAdvanced": True}
    (root / "logs").mkdir(exist_ok=True)
    (root / "logs/native-pack-removal-result.json").write_text(json.dumps(result, indent=2))
    print(json.dumps(result))
    shutil.rmtree(session, ignore_errors=True)


main()
