"""Compiling custom objects with SimAntics behaviors and playing them.

Compiles examples/object-pack.json with `SimsSimulation --compile-object`: a flamingo with a new "Make a Wish" interaction
(a test behavior that offers it once per flamingo, and an action behavior that adds §7, tops up Fun and marks the wish
used in an object attribute that must survive saving)
and a multi-tile banquet table made from one of the four-part dining tables, with its own tree table. The pack is mounted
through the native loader and both objects are bought, used, saved, loaded and sold on House 5. Malformed documents
must be rejected before any pack is written. Results are written to logs/native-object-authoring-result.json.

Needs a pack tool binary (SimsNative on macOS or SimsSDL elsewhere; override with SIMS_PACK_TOOL) and the simulation
host built in Release.
"""
import copy
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
session = root / "runtime/native-sessions" / ("object-authoring-" + uuid.uuid4().hex)
packs = session / "packs"
host_binary = root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"
environment = os.environ | {"DOTNET_CLI_HOME": str(root / "runtime/dotnet")}
document = json.loads((root / "examples/object-pack.json").read_text())
flamingo_guid = int(document["objects"][0]["guid"], 16)
table_guid = int(document["objects"][1]["guid"], 16)
table_parts = {int(value, 16) for value in document["objects"][1]["tileGuids"]}


def compile_pack(source, name):
    path = session / (name + ".json")
    path.write_text(json.dumps(source))
    return subprocess.run([shutil.which("dotnet"), str(host_binary), "--compile-object", str(path), str(root / "runtime/game"), str(packs / name)],
                          env=environment, text=True, capture_output=True)


def pack_tool():
    if os.environ.get("SIMS_PACK_TOOL"):
        return [os.environ["SIMS_PACK_TOOL"]]
    for name in ["SimsNative", "SimsSDL"]:
        binary = root / "native/SimsNative/.build/release" / name
        if binary.exists():
            return [str(binary)]
    raise AssertionError("Build SimsNative or SimsSDL in release first")


class Host:
    def __init__(self, content, name):
        self.log = (session / (name + ".log")).open("w")
        self.process = subprocess.Popen([shutil.which("dotnet"), str(host_binary), str(content), str(root), "--serve", str(session / name), "5"],
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

    def until(self, predicate, limit=1200):
        state = self.request("state")
        for _ in range(limit // 30):
            if predicate(state):
                return state
            state = self.step(30)
        raise AssertionError("The expected simulation state was not reached")

    def buy(self, guid, parts, state):
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
                bought = [item for item in after["objects"] if item["id"] not in known and item["guid"] in parts]
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


def sim(state):
    return next(item for item in state["sims"] if item["household"])


def menu(host, object_id):
    return [entry for entry in host.request("menu", objectID=object_id) if not entry["global"]]


def main():
    packs.mkdir(parents=True)
    compiled = compile_pack(document, document["packID"])
    assert compiled.returncode == 0, compiled.stderr
    summary = json.loads(compiled.stdout)
    assert [item["guid"] for item in summary["objects"]] == [flamingo_guid, table_guid]
    assert sorted(summary["objects"][1]["tileGuids"]) == sorted(table_parts)

    # Malformed documents fail before a pack directory exists.
    rejected = {}
    def reject(name, change, message):
        broken = copy.deepcopy(document)
        broken["packID"] = "local.rejected-" + name
        change(broken)
        result = compile_pack(broken, broken["packID"])
        assert result.returncode != 0 and message in result.stderr, (name, result.stderr)
        assert not (packs / broken["packID"]).exists()
        rejected[name] = result.stderr.strip()
    reject("unknownPrimitive", lambda d: d["objects"][0]["behaviors"][0]["instructions"][0].update(primitive="levitate"), "unknown primitive levitate")
    reject("unknownOperandField", lambda d: d["objects"][0]["behaviors"][0]["instructions"][1]["operand"].update(volume=3), "has no field volume")
    reject("operandOverflow", lambda d: d["objects"][0]["behaviors"][0]["instructions"][1]["operand"].update(lhsData=70000), "invalid value for LhsData")
    reject("unknownLabel", lambda d: d["objects"][0]["behaviors"][0]["instructions"][0].update(true="nowhere"), "unknown label nowhere")
    reject("unknownBehavior", lambda d: d["objects"][0]["interactions"][0].update(action="Missing"), "unknown behavior Missing")
    reject("missingTileGuids", lambda d: d["objects"][1].update(tileGuids=[]), "give tileGuids")
    reject("ambiguousTemplate", lambda d: d["objects"][1].pop("templateObject"), "holds several objects")
    reject("duplicateGuid", lambda d: d["objects"][1].update(guid=d["objects"][0]["guid"]), "used twice")
    reject("protectedField", lambda d: d["objects"][0]["fields"].update(MasterID=3), "cannot be set")

    content = session / "content"
    subprocess.run(pack_tool() + ["--game", str(root / "runtime/game"), "--packs", str(packs), "--mount", str(content)], check=True, stdout=subprocess.DEVNULL)
    slot = "authoring-" + uuid.uuid4().hex[:12]
    host = Host(content, "play")
    try:
        catalog = {item["guid"]: item for item in host.request("catalog")["objects"]}
        for guid, price, spec in [(flamingo_guid, 45, document["objects"][0]), (table_guid, 140, document["objects"][1])]:
            assert catalog[guid]["price"] == price, catalog[guid]
            # Buy mode shows the catalog strings: name and description in the player's language.
            category = catalog[guid]["category"]
            page = host.request("catalogPage", category=category, offset=0, count=64)
            while not any(item["guid"] == guid for item in page["items"]) and page["offset"] + 64 < page["total"]:
                page = host.request("catalogPage", category=category, offset=page["offset"] + 64, count=64)
            item = next(item for item in page["items"] if item["guid"] == guid)
            assert item["name"] == spec["catalogName"] and item["description"] == spec["description"] and item["icon"], {k: item[k] for k in ["name", "description"]}
        state = host.step(30)
        before = state["budget"]
        (flamingo,), state = host.buy(flamingo_guid, {flamingo_guid}, state)
        assert state["budget"] == before - 45, (before, state["budget"])

        # The test behavior offers the wish only while the flamingo's attribute 0 is still 0.
        entries = menu(host, flamingo["id"])
        names = [entry["name"] for entry in entries]
        assert "Make a Wish" in names, names
        assert "View" in names, "The template's own interactions were lost"
        wish = next(entry for entry in entries if entry["name"] == "Make a Wish")
        budget = state["budget"]
        host.request("interact", objectID=flamingo["id"], interaction=wish["interaction"], param0=wish["param0"])
        state = host.until(lambda current: current["budget"] == budget + 7)
        state = host.step(30)
        assert state["budget"] == budget + 7, "The wish was granted more than once"
        assert "Make a Wish" not in [entry["name"] for entry in menu(host, flamingo["id"])], "The test behavior did not hide the interaction"

        budget = state["budget"]
        parts, state = host.buy(table_guid, table_parts, state)
        state = host.step(5)
        parts = [item for item in state["objects"] if item["guid"] in table_parts]
        assert len(parts) == 4, parts
        assert state["budget"] == budget - 140, (budget, state["budget"])
        knock = next(entry for entry in menu(host, parts[0]["id"]) if entry["name"] == "Knock on Wood")
        budget = state["budget"]
        host.request("interact", objectID=parts[0]["id"], interaction=knock["interaction"], param0=knock["param0"])
        state = host.until(lambda current: current["budget"] == budget + 1)
        host.request("save", slot=slot)
        saved = state
    finally:
        host.close()

    host = Host(content, "reload")
    try:
        state = host.request("load", slot=slot)
        guids = [item["guid"] for item in state["objects"]]
        assert guids.count(flamingo_guid) == 1 and sorted(guid for guid in guids if guid in table_parts) == sorted(table_parts), guids
        assert state["budget"] == saved["budget"]
        part = next(item for item in state["objects"] if item["guid"] in table_parts)
        assert "Knock on Wood" in [entry["name"] for entry in menu(host, part["id"])]
        flamingo = next(item for item in state["objects"] if item["guid"] == flamingo_guid)
        names = [entry["name"] for entry in menu(host, flamingo["id"])]
        assert "View" in names and "Make a Wish" not in names, ("The used wish did not survive saving", names)
        host.request("view", editing=True)
        budget = state["budget"]
        host.request("sellObject", objectID=part["id"])
        state = host.step(5)
        assert not any(item["guid"] in table_parts for item in state["objects"]), "Selling one part did not remove the whole table"
        refund = state["budget"] - budget
        assert 0 < refund <= 140, refund
        host.request("view", editing=False)
        host.step(300)
    finally:
        host.close()

    result = {"result": "passed", "pack": document["packID"], "objects": summary["objects"], "multiTileParts": len(table_parts),
              "tableRefund": refund, "rejectedBeforeWrite": rejected}
    (root / "logs").mkdir(exist_ok=True)
    (root / "logs/native-object-authoring-result.json").write_text(json.dumps(result, indent=2))
    print(json.dumps({key: result[key] for key in ["result", "pack", "multiTileParts", "tableRefund"]}))
    shutil.rmtree(session, ignore_errors=True)


main()
