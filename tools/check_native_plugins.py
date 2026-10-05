#!/usr/bin/env python3
"""End-to-end check of the gameplay plugin SDK against the example allowance pack.

Builds nothing: run tools/build_example_plugin.command and build SimsNative/SimsSimulation first.
Covers pack validation, explicit trust, hash verification, plugin loading, panel values and actions, the API version 2
lot calls (objects, a chore queued through the pie menu, a changed need), namespaced plugin state in saves, and
rejection of untrusted or tampered plugins.
"""
import json, os, shutil, subprocess, sys, tempfile, time
from pathlib import Path

root = Path(__file__).resolve().parents[1]
game = Path(os.environ.get("SIMS_GAME_DIR", Path.home() / "Downloads/The Sims 1"))
app = next((root / "native/SimsNative/.build/release" / name for name in ["SimsNative", "SimsSDL"]
            if (root / "native/SimsNative/.build/release" / name).exists()), root / "native/SimsNative/.build/release/SimsNative")
host = root / "native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll"
pack_id = "local.example-allowance"
env = {**os.environ, "DOTNET_CLI_HOME": str(root / "runtime/dotnet")}


def cli(*args, check=True):
    result = subprocess.run([str(app), "--game", str(game), *args], capture_output=True, text=True, env=env)
    if check and result.returncode != 0:
        raise SystemExit(f"{' '.join(args)} failed: {result.stderr[-600:]}")
    return result


class Host:
    def __init__(self, mount, work, data_root):
        session = work / ("session-" + str(time.time_ns()))
        self.process = subprocess.Popen(
            ["dotnet", str(host), str(mount), str(root), "--serve", str(session), "5", "--profile-id", "plugin-check", "--data-root", str(data_root)],
            stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True, env=env)
        self.events = []
        self.counter = 0
        self.hello = self.until(lambda e: e.get("type") == "hello")

    def read(self, timeout=90):
        deadline = time.time() + timeout
        while time.time() < deadline:
            line = self.process.stdout.readline()
            if not line:
                raise SystemExit("host exited")
            try:
                event = json.loads(line)
            except json.JSONDecodeError:
                continue
            self.events.append(event)
            return event
        raise SystemExit("timed out")

    def until(self, predicate, timeout=90):
        for event in self.events:
            if predicate(event):
                return event
        deadline = time.time() + timeout
        while time.time() < deadline:
            event = self.read(timeout)
            if predicate(event):
                return event
        raise SystemExit("timed out waiting for an event")

    def call(self, op, **fields):
        self.counter += 1
        identifier = str(self.counter)
        self.process.stdin.write(json.dumps({"op": op, "id": identifier, **fields}) + "\n")
        self.process.stdin.flush()
        return self.until(lambda e: e.get("type") == "response" and e.get("id") == identifier)

    def close(self):
        try:
            self.call("quit")
        except SystemExit:
            pass
        self.process.kill()


def plugin_state(hello, events):
    states = {s["packId"]: s for s in hello.get("plugins", [])}
    for event in events:
        if event.get("type") == "plugin":
            states[event["packId"]] = event
    return states.get(pack_id, {}).get("state")


def run():
    work = Path(tempfile.mkdtemp(prefix="sims-plugin-check-"))
    checks = []
    try:
        packs = work / "packs"
        packs.mkdir()
        shutil.copytree(root / "examples/plugin-pack", packs / "plugin-pack")
        data = work / "data"
        report = json.loads(cli("--packs", str(packs), "--pack-report").stdout)
        plugin = report["plugins"][0]
        assert plugin["packID"] == pack_id and report["panels"][0]["id"] == "allowance"
        checks.append("pack report lists plugin, panel and migration sources")

        # 1. Untrusted: the plugin must not run.
        cli("--packs", str(packs), "--mount", str(work / "mount-untrusted"))
        host_a = Host(work / "mount-untrusted", work, data)
        state = plugin_state(host_a.hello, host_a.events)
        assert state == "untrusted", f"expected untrusted, got {state}"
        host_a.close()
        checks.append("untrusted plugin is blocked")

        # 2. Trusted: loads, publishes panel values, reacts to actions, persists namespaced state.
        listing = json.loads(cli("--packs", str(packs), "--data-root", str(data), "--trust-plugin", pack_id).stdout)
        assert listing["plugins"][0]["trusted"] is True
        cli("--packs", str(packs), "--mount", str(work / "mount-trusted"))
        host_b = Host(work / "mount-trusted", work, data)
        state = plugin_state(host_b.hello, host_b.events)
        assert state == "loaded", f"expected loaded, got {state}"
        panels = host_b.call("pluginPanels")["result"]["panels"]
        values = next(p["values"] for p in panels if p["panelId"] == "allowance")
        assert values["status"].startswith("Paid each morning"), values
        checks.append("trusted plugin loads and publishes panel values")
        host_b.call("pluginAction", packId=pack_id, panelId="allowance", action="pause")
        panels = host_b.call("pluginPanels")["result"]["panels"]
        values = next(p["values"] for p in panels if p["panelId"] == "allowance")
        assert values["status"] == "Payments paused", values
        checks.append("panel action reaches the plugin")
        bad = host_b.call("pluginAction", packId=pack_id, panelId="nope", action="pause")
        assert bad.get("ok") is False
        checks.append("unknown panel is rejected")

        # API version 2: the plugin reads lot objects, sends a Sim to a chore through the pie menu and changes a motive.
        state = host_b.call("state")["result"]
        counted = int(values["objects"].split()[0])  # published at the last panel update; the lot may have changed since
        assert counted > 0 and abs(counted - len(state["objects"])) <= 5, (values["objects"], len(state["objects"]))
        checks.append("plugin reads lot objects")
        host_b.call("pluginAction", packId=pack_id, panelId="allowance", action="chore")
        chore = next(p["values"] for p in host_b.call("pluginPanels")["result"]["panels"] if p["panelId"] == "allowance")["chore"]
        name, _, task = chore.partition(": ")
        interaction = next((c for c in ["Water", "Bring In", "Clean", "Repair", "Feed Fish", "Empty"] if task.startswith(c + " ")), None)
        assert interaction, f"no chore was queued: {chore}"
        for _ in range(20):
            host_b.call("step", count=5)
            state = host_b.call("state")["result"]
            sim = next(s for s in state["sims"] if s["name"] == name)
            if any(a["name"] == interaction for a in sim["actions"]):
                break
        else:
            raise SystemExit(f"{name} never queued {interaction}: {[a['name'] for a in sim['actions']]}")
        checks.append("plugin queues an interaction through the pie menu")
        energy = sim["motives"]["Energy"]
        host_b.call("pluginAction", packId=pack_id, panelId="allowance", action="coffee")
        label = next(p["values"] for p in host_b.call("pluginPanels")["result"]["panels"] if p["panelId"] == "allowance")["chore"]
        changed = int(label.rsplit(" ", 1)[1])
        assert changed == min(100, energy + 20) or abs(changed - min(100, energy + 20)) <= 1, (energy, label)
        sim = next(s for s in host_b.call("state")["result"]["sims"] if s["name"] == name)
        assert abs(sim["motives"]["Energy"] - changed) <= 1, (sim["motives"]["Energy"], changed)
        checks.append("plugin changes a need")
        # Tidy rescales the household's autonomous choices; the plugin counts what it was offered.
        host_b.call("freeWill", enabled=True)
        host_b.call("pluginAction", packId=pack_id, panelId="allowance", action="tidy")
        for _ in range(60):
            host_b.call("step", count=30)
            for dialog in host_b.call("state")["result"]["dialogs"]:  # a blocking dialog stops every Sim
                host_b.call("dialogResponse", token=dialog["token"], code=0)
            autonomy = next(p["values"] for p in host_b.call("pluginPanels")["result"]["panels"] if p["panelId"] == "allowance")["autonomy"]
            if autonomy.startswith("Tidy: ") and int(autonomy.split()[1]) > 0:  # "Tidy: F of C choices were chores"
                break
        else:
            raise SystemExit(f"autonomy never asked the plugin: {autonomy}")
        checks.append("plugin scores autonomous choices")
        host_b.call("pluginAction", packId=pack_id, panelId="allowance", action="tidy")
        # Pie menu entries: the selected adult is offered "Allowance/Pay Now" on a household child, and choosing it pays.
        host_b.call("pluginAction", packId=pack_id, panelId="allowance", action="resume")  # paused allowances offer nothing
        state = host_b.call("state")["result"]
        child = next(s for s in state["sims"] if s["name"].startswith("Cassandra"))
        entries = host_b.call("menu", objectID=child["id"])["result"]
        entry = next((e for e in entries if e.get("plugin") == pack_id), None)
        assert entry and entry["name"] == "Allowance/Pay Now" and entry["entry"] == "pay-now", entries
        adult = next(s for s in state["sims"] if s["name"].startswith("Mortimer"))
        assert not any(e.get("plugin") for e in host_b.call("menu", objectID=adult["id"])["result"]), "Pay Now offered on an adult"
        funds = state["budget"]
        chosen = host_b.call("interact", objectID=child["id"], interaction=0, plugin=pack_id, entry="pay-now")
        assert chosen.get("ok") and chosen["result"]["accepted"], chosen
        assert host_b.call("state")["result"]["budget"] == funds + 50, "Pay Now did not pay"
        label = next(p["values"] for p in host_b.call("pluginPanels")["result"]["panels"] if p["panelId"] == "allowance")["chore"]
        assert label.startswith("Paid Cassandra"), label
        refused = host_b.call("interact", objectID=adult["id"], interaction=0, plugin=pack_id, entry="pay-now")
        assert refused.get("ok") is False, refused
        checks.append("plugin adds a pie menu entry and receives the choice")
        shown = host_b.call("interact", objectID=child["id"], interaction=0, plugin=pack_id, entry="details")
        assert shown.get("ok") and shown["result"]["panel"] == "allowance" and shown["result"]["anchorId"] == child["id"], shown
        assert any(e.get("type") == "pluginPanelShow" and e.get("panelId") == "allowance" and e.get("anchorId") == child["id"] for e in host_b.events), "no anchored pluginPanelShow event"
        checks.append("plugin opens its panel beside a Sim from its pie menu")
        host_b.call("pluginAction", packId=pack_id, panelId="allowance", action="pause")
        saved = host_b.call("save", slot="plugin")
        assert saved.get("ok"), saved
        envelope = json.loads(Path(saved["result"]["path"]).read_text())
        record = envelope["plugins"][pack_id]
        assert envelope["schemaVersion"] == 2 and record["stateVersion"] == 2 and record["data"], envelope.get("plugins")
        assert any(p["id"] == pack_id for p in envelope["packs"])
        checks.append("save stores namespaced plugin state and pack versions")
        host_b.call("pluginAction", packId=pack_id, panelId="allowance", action="resume")
        loaded = host_b.call("load", slot="plugin")
        assert loaded.get("ok"), loaded
        values = next(p["values"] for p in host_b.call("pluginPanels")["result"]["panels"] if p["panelId"] == "allowance")
        assert values["status"] == "Payments paused", f"load did not restore plugin state: {values}"
        checks.append("load restores plugin state")

        # 3. A save from a newer plugin state version is refused and the session is untouched.
        path = Path(saved["result"]["path"])
        newer = json.loads(path.read_text())
        newer["plugins"][pack_id]["stateVersion"] = 9
        path.with_name("newer.json").write_text(json.dumps(newer))
        refused = host_b.call("load", slot="newer")
        assert refused.get("ok") is False and "newer state version" in refused.get("error", ""), refused
        checks.append("newer plugin state version is rejected")

        # 4. An older state version is migrated by the plugin (version 1 had no paused flag).
        older = json.loads(path.read_text())
        older["plugins"][pack_id]["stateVersion"] = 1
        path.with_name("older.json").write_text(json.dumps(older))
        assert host_b.call("load", slot="older").get("ok")
        values = next(p["values"] for p in host_b.call("pluginPanels")["result"]["panels"] if p["panelId"] == "allowance")
        assert values["status"].startswith("Paid each morning"), f"version 1 state should resume payments: {values}"
        checks.append("older plugin state is migrated by the plugin")

        # 5. A save naming a plugin that is not loaded is refused.
        missing = json.loads(path.read_text())
        missing["plugins"]["local.other"] = missing["plugins"][pack_id]
        path.with_name("missing.json").write_text(json.dumps(missing))
        refused = host_b.call("load", slot="missing")
        assert refused.get("ok") is False and "local.other" in refused.get("error", ""), refused
        checks.append("saved state for a missing plugin is rejected")
        host_b.close()

        # 6. Tampering after trust is rejected.
        cli("--packs", str(packs), "--mount", str(work / "mount-tampered"))
        dll = next((work / "mount-tampered/.native-plugins" / pack_id).glob("*.dll"))
        dll.write_bytes(dll.read_bytes() + b"\0")
        host_c = Host(work / "mount-tampered", work, data)
        state = plugin_state(host_c.hello, host_c.events)
        assert state == "rejected", f"expected rejected, got {state}"
        host_c.close()
        checks.append("tampered plugin files are rejected")

        # 7. Revoking trust blocks the plugin again.
        cli("--packs", str(packs), "--data-root", str(data), "--revoke-plugin", pack_id)
        host_d = Host(work / "mount-trusted", work, data)
        assert plugin_state(host_d.hello, host_d.events) == "untrusted"
        host_d.close()
        checks.append("revoked trust blocks the plugin")
        print(json.dumps({"result": "passed", "checks": checks}, indent=2))
        return 0
    except AssertionError as error:
        print(json.dumps({"result": "failed", "passed": checks, "error": str(error)}, indent=2))
        return 1
    finally:
        shutil.rmtree(work, ignore_errors=True)


if __name__ == "__main__":
    sys.exit(run())
