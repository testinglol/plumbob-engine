"""Compiling custom objects with SimAntics behaviors and playing them.

Compiles examples/object-pack.json with `SimsSimulation --compile-object`: a flamingo recolored blue with a new "Make a Wish" interaction
(a test behavior that offers it once per flamingo, and an action behavior that walks the Sim to the flamingo, plays the
flamingo's consider and approve animations and two celebration clips it adds to its own animation tables, adds §7, tops
up Fun and marks the wish
used in an object attribute that must survive saving)
and a multi-tile banquet table made from one of the four-part dining tables, with its own tree table. A second pack repaints
the flamingo: its sprite frames are exported with `--export-object-sprites`, painted green at test time (the top third,
widened by a pixel to cover formerly transparent pixels) and compiled back, and the painted frames must be what the
renderer draws. The example's French and German translations must show in a host started in French, and the template's
own accented strings in other languages must survive compiling. The pack is mounted
through the native loader and both objects are bought, used, saved, loaded and sold on House 5. Malformed documents
must be rejected before any pack is written. Results are written to logs/native-object-authoring-result.json.

Needs a pack tool binary (SimsNative on macOS or SimsSDL elsewhere; override with SIMS_PACK_TOOL) and the simulation
host built in Release.
"""
import colorsys
import copy
import json
import math
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
original_flamingo = 0x3659DCA2
painted_guid = 0xE5A10011
paint = (40, 200, 60, 255)
missing_clip = "a2o-painted-flamingo-missing"


def hues(pixels):
    """Counts saturated visible pixels by hue: pink/red (280..40 degrees) and blue (180..260)."""
    counts = {"pink": 0, "blue": 0, "green": 0}
    for data in pixels:
        for index in range(0, len(data), 4):
            red, green, blue, alpha = data[index:index + 4]
            if alpha <= 128 or (red, green, blue) == (255, 0, 255):
                continue
            hue, _, saturation = colorsys.rgb_to_hls(red / 255, green / 255, blue / 255)
            if saturation < 0.3:
                continue
            hue *= 360
            if hue >= 280 or hue <= 40:
                counts["pink"] += 1
            elif 180 <= hue <= 260:
                counts["blue"] += 1
            elif 90 <= hue <= 160:
                counts["green"] += 1
    return counts


def sprite_textures(host, object_id):
    """The RGBA textures the renderer draws for an object, as (width, height, pixels)."""
    scene_path = Path(host.request("scene"))
    scene = json.loads(scene_path.read_text())
    textures = {sprite["texture"] for sprite in scene["sprites"] if sprite["objectID"] == object_id}
    assert textures, f"Object {object_id} has no sprites in the scene"
    return [(scene["textures"][texture]["width"], scene["textures"][texture]["height"],
             (scene_path.parent / scene["textures"][texture]["file"]).read_bytes()) for texture in textures]


def sprite_hues(host, object_id):
    return hues(pixels for _, _, pixels in sprite_textures(host, object_id))


def paint_sprites():
    """Exports the flamingo's frames and paints them; returns the painted pack document and the painted frames."""
    from PIL import Image
    art = session / "art"
    exported = subprocess.run([shutil.which("dotnet"), str(host_binary), "--export-object-sprites", "flamingo.iff", str(root / "runtime/game"), str(art)],
                              env=environment, text=True, capture_output=True)
    assert exported.returncode == 0, exported.stderr
    manifest = json.loads((art / "sprites.json").read_text())
    assert manifest["objects"][0]["guid"] == f"0x{original_flamingo:08X}" and manifest["sprites"], manifest
    assert all(entry["usedBy"] for entry in manifest["sprites"]), "Every flamingo frame is drawn by its draw group"
    images, frames = [], {}
    for entry in manifest["sprites"]:
        image = Image.open(art / entry["image"]).convert("RGBA")
        assert image.size == (entry["width"], entry["height"]) and Image.open(art / entry["depth"]).mode == "L"
        pixels = image.load()
        width, height = image.size
        for y in range(height // 3):
            visible = [x for x in range(width) if pixels[x, y][3] > 0]
            for x in range(max(0, min(visible, default=width) - 1), min(width, max(visible, default=-2) + 2)):
                pixels[x, y] = paint
        name = "painted-" + entry["image"]
        image.save(art / name)
        images.append({"sprite": entry["sprite"], "frame": entry["frame"], "image": "art/" + name})
        frames[(width, height)] = image.tobytes()
    painted = {"schemaVersion": 1, "packID": "local.painted-objects", "objects": [{
        "file": "painted-flamingo", "template": "flamingo.iff", "guid": f"0x{painted_guid:08X}",
        "catalogName": "Painted Flamingo", "description": "A flamingo with a freshly painted green head.", "price": 20,
        "sprites": images}]}
    return painted, frames


def icon_pixels(host, item):
    from PIL import Image
    return Image.open(host.scene / item["icon"]["file"]).convert("RGBA").tobytes()


def iff_strings(path, types):
    """The raw byte strings of an IFF file's TS1 string chunks, as (language code, bytes)."""
    data = path.read_bytes()
    cursor, found = 64, []
    while cursor + 76 <= len(data):
        size = int.from_bytes(data[cursor + 4:cursor + 8], "big")
        body = data[cursor + 76:cursor + size]
        if data[cursor:cursor + 4].decode("latin-1") in types and int.from_bytes(body[:2], "little", signed=True) == -3:
            position = 4
            for _ in range(int.from_bytes(body[2:4], "little")):
                language = body[position]
                end = body.index(0, position + 1)
                found.append((language, body[position + 1:end]))
                position = body.index(0, end + 1) + 1
        cursor += size
    return found


def catalog_item(host, catalog, guid):
    category = catalog[guid]["category"]
    page = host.request("catalogPage", category=category, offset=0, count=64)
    while not any(item["guid"] == guid for item in page["items"]) and page["offset"] + 64 < page["total"]:
        page = host.request("catalogPage", category=category, offset=page["offset"] + 64, count=64)
    return next(item for item in page["items"] if item["guid"] == guid), page


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
    def __init__(self, content, name, language=None):
        self.log = (session / (name + ".log")).open("w")
        self.scene = session / name / "scene"
        self.process = subprocess.Popen([shutil.which("dotnet"), str(host_binary), str(content), str(root), "--serve", str(session / name), "5"] + (["--language", str(language)] if language else []),
                                        stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=self.log, text=True, env=environment)
        self.messages = queue.Queue()
        self.sequence = 0
        threading.Thread(target=self.read, daemon=True).start()
        self.hello = self.receive()
        assert self.hello["type"] == "hello"

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
        if message.get("type") == "frame":
            self.revision = message["revision"]
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
                # Every step writes a scene file; acknowledging lets the server delete the older ones during long walks.
                if getattr(self, "revision", 0) > 0:
                    self.request("sceneAck", revision=self.revision)
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
        assert result.returncode != 0 and message in result.stderr and "Unhandled exception" not in result.stderr, (name, result.stderr)
        assert not (packs / broken["packID"]).exists()
        rejected[name] = result.stderr.strip()
    reject("unknownPrimitive", lambda d: d["objects"][0]["behaviors"][0]["instructions"][0].update(primitive="levitate"), "unknown primitive levitate")
    reject("unknownOperandField", lambda d: d["objects"][0]["behaviors"][0]["instructions"][6]["operand"].update(volume=3), "has no field volume")
    reject("operandOverflow", lambda d: d["objects"][0]["behaviors"][0]["instructions"][6]["operand"].update(lhsData=70000), "invalid value for LhsData")
    reject("unknownAnimation", lambda d: d["objects"][0]["behaviors"][0]["instructions"][3]["operand"].update(animationID="fly"), "unknown animation fly")
    reject("animationSource", lambda d: d["objects"][0]["behaviors"][0]["instructions"][3]["operand"].update(source="Global"), "its source must be Object")
    reject("animationClipName", lambda d: d["objects"][0]["animations"][0].update(adult="a2o wave.anim"), "Invalid adult clip")
    reject("unknownLabel", lambda d: d["objects"][0]["behaviors"][0]["instructions"][0].update(true="nowhere"), "unknown label nowhere")
    reject("unknownBehavior", lambda d: d["objects"][0]["interactions"][0].update(action="Missing"), "unknown behavior Missing")
    reject("missingTileGuids", lambda d: d["objects"][1].update(tileGuids=[]), "give tileGuids")
    reject("ambiguousTemplate", lambda d: d["objects"][1].pop("templateObject"), "holds several objects")
    reject("duplicateGuid", lambda d: d["objects"][1].update(guid=d["objects"][0]["guid"]), "used twice")
    reject("protectedField", lambda d: d["objects"][0]["fields"].update(MasterID=3), "cannot be set")
    reject("unknownLanguage", lambda d: d["objects"][0]["translations"].update(Klingon={"catalogName": "x"}), "Unknown language Klingon")
    reject("unknownTranslatedInteraction", lambda d: d["objects"][0]["translations"]["French"]["interactions"].update(Fly="Voler"), "unknown interaction Fly")
    reject("nonLatin1Text", lambda d: d["objects"][0]["translations"]["French"].update(catalogName="Flamant \u2605"), "outside Latin-1")
    # The template's own strings in other languages keep their accented characters.
    compiled_flamingo = packs / document["packID"] / "files/Downloads" / document["packID"] / (document["objects"][0]["file"] + ".iff")
    accented = [text for _, text in iff_strings(compiled_flamingo, {"TTAs"}) if any(value > 127 for value in text)]
    assert accented, "Compiling replaced the template's accented strings"
    # The document's animations land at one index in both the adult and the child animation table.
    animation_strings = [text.decode("latin-1") for _, text in iff_strings(compiled_flamingo, {"STR#"})]
    for entry in document["objects"][0]["animations"]:
        assert entry["adult"] in animation_strings and entry["child"] in animation_strings, (entry, animation_strings)
    added = {item["name"]: item["index"] for item in summary["objects"][0]["animations"]}
    assert sorted(added) == sorted(entry["name"] for entry in document["objects"][0]["animations"]) and min(added.values()) >= 13, added

    painted, painted_frames = paint_sprites()
    def reject_paint(name, change, message):
        broken = copy.deepcopy(painted)
        broken["packID"] = "local.rejected-" + name
        change(broken["objects"][0]["sprites"])
        result = compile_pack(broken, broken["packID"])
        assert result.returncode != 0 and message in result.stderr and "Unhandled exception" not in result.stderr, (name, result.stderr)
        assert not (packs / broken["packID"]).exists()
        rejected[name] = result.stderr.strip()
    reject_paint("spriteSize", lambda sprites: sprites[0].update(image=sprites[-1]["image"]), "; sprite 128 frame 0 is")
    reject_paint("spriteOutsideDocument", lambda sprites: sprites[0].update(image="../" + sprites[0]["image"]), "outside the document directory")
    reject_paint("missingSprite", lambda sprites: sprites[0].update(sprite=999), "has no sprite 999")
    reject_paint("missingFrame", lambda sprites: sprites[0].update(frame=99), "has no frame 99")
    # The painted flamingo also carries the wish, with an adult celebration clip the game does not have: the name is
    # well formed so it compiles, and the host reports it when the pack is enabled.
    for key in ["animations", "behaviors", "interactions"]:
        painted["objects"][0][key] = copy.deepcopy(document["objects"][0][key])
    painted["objects"][0]["animations"][0]["adult"] = missing_clip
    compiled = compile_pack(painted, painted["packID"])
    assert compiled.returncode == 0, compiled.stderr
    painted_summary = json.loads(compiled.stdout)["objects"][0]
    assert painted_summary["painted"][0]["frames"] == list(range(len(painted["objects"][0]["sprites"]))), painted_summary

    content = session / "content"
    subprocess.run(pack_tool() + ["--game", str(root / "runtime/game"), "--packs", str(packs), "--mount", str(content)], check=True, stdout=subprocess.DEVNULL)
    slot = "authoring-" + uuid.uuid4().hex[:12]
    host = Host(content, "play")
    try:
        # Only the painted pack's broken adult clip is reported: the wishing pack's clips and template entries all exist.
        warnings = host.hello.get("packWarnings")
        assert warnings and len(warnings) == 1 and warnings[0]["packId"] == painted["packID"] and missing_clip in warnings[0]["message"], warnings
        pack_warnings = warnings
        catalog = {item["guid"]: item for item in host.request("catalog")["objects"]}
        for guid, price, spec in [(flamingo_guid, 45, document["objects"][0]), (table_guid, 140, document["objects"][1])]:
            assert catalog[guid]["price"] == price, catalog[guid]
            # Buy mode shows the catalog strings: name and description in the player's language.
            item, page = catalog_item(host, catalog, guid)
            assert item["name"] == spec["catalogName"] and item["description"] == spec["description"] and item["icon"], {k: item[k] for k in ["name", "description"]}
            if guid == flamingo_guid:
                icons = {guid: item, original_flamingo: next(entry for entry in page["items"] if entry["guid"] == original_flamingo)}
        # The recolor turns the pink flamingo in the catalog icon blue and leaves the rest of the icon alone.
        original_icon, recolored_icon = icon_pixels(host, icons[original_flamingo]), icon_pixels(host, icons[flamingo_guid])
        icon_hues = {"original": hues([original_icon]), "recolored": hues([recolored_icon])}
        assert len(original_icon) == len(recolored_icon) and icon_hues["original"]["pink"] > 30 and icon_hues["recolored"]["pink"] == 0 \
            and icon_hues["recolored"]["blue"] >= icon_hues["original"]["blue"] + icon_hues["original"]["pink"], icon_hues
        changed = [index for index in range(0, len(original_icon), 4) if original_icon[index:index + 4] != recolored_icon[index:index + 4]]
        recolor = document["objects"][0]["recolor"]
        def in_range(pixel):
            hue, _, saturation = colorsys.rgb_to_hls(*(value / 255 for value in pixel))
            low, high = recolor["hueRange"]
            return saturation >= recolor["minimumSaturation"] and (hue * 360 >= low or hue * 360 <= high)
        assert changed and all(in_range(original_icon[index:index + 3]) for index in changed), "The recolor touched pixels outside its hue range"
        state = host.step(30)
        before = state["budget"]
        (flamingo,), state = host.buy(flamingo_guid, {flamingo_guid}, state)
        assert state["budget"] == before - 45, (before, state["budget"])
        (pink, ), state = host.buy(original_flamingo, {original_flamingo}, state)
        (green, ), state = host.buy(painted_guid, {painted_guid}, state)
        sprite_counts = {"original": sprite_hues(host, pink["id"]), "recolored": sprite_hues(host, flamingo["id"]), "painted": sprite_hues(host, green["id"])}
        # The renderer draws the painted frames: the same coverage, and colors within palette rounding of the paint.
        drawn = sprite_textures(host, green["id"])
        painted_match = []
        for width, height, pixels in drawn:
            expected = painted_frames[(width, height)]
            assert [pixels[index] > 0 for index in range(3, len(pixels), 4)] == [expected[index] > 0 for index in range(3, len(expected), 4)], "Painted coverage differs"
            difference = max(abs(pixels[index] - expected[index]) for index in range(len(pixels)) if index % 4 != 3 and expected[index - index % 4 + 3] > 0)
            painted_pixels = sum(1 for index in range(0, len(pixels), 4) if tuple(expected[index:index + 4]) == paint)
            assert difference <= 48 and painted_pixels > 0, (width, height, difference)
            painted_match.append({"width": width, "height": height, "paintedPixels": painted_pixels, "largestChannelDifference": difference})
        assert sprite_counts["painted"]["green"] >= sum(item["paintedPixels"] for item in painted_match) and sprite_counts["original"]["green"] == 0, sprite_counts
        assert sprite_counts["original"]["pink"] > 40 and sprite_counts["recolored"]["pink"] == 0 \
            and sprite_counts["recolored"]["blue"] >= sprite_counts["original"]["pink"] + sprite_counts["original"]["blue"], sprite_counts

        # The test behavior offers the wish only while the flamingo's attribute 0 is still 0.
        entries = menu(host, flamingo["id"])
        names = [entry["name"] for entry in entries]
        assert "Make a Wish" in names, names
        assert "View" in names, "The template's own interactions were lost"
        wish = next(entry for entry in entries if entry["name"] == "Make a Wish")
        budget = state["budget"]
        host.request("interact", objectID=flamingo["id"], interaction=wish["interaction"], param0=wish["param0"])
        # The wish is a queued Sim action: the Sim walks to the flamingo's routing slot and plays its animations before
        # the budget changes.
        # consider and approve come from the template's tables; the celebration is the document's own animations entry.
        wish_clips = ["consider", "approve", "dance-inplace-handsupstart", "dance-inplace-handsupstop"]
        state, seen, trace = host.request("state"), [], []
        for step in range(3000):
            if state["budget"] == budget + 7:
                break
            if step % 150 == 0:
                trace.append([(sim["name"], sim.get("animation"), [action["name"] for action in sim["actions"]], round(sim["x"], 1), round(sim["y"], 1)) for sim in state["sims"] if sim["household"]])
            for sim in state["sims"]:
                name = (sim.get("animation") or "").lower()
                if name[4:] in wish_clips and name[:4] in ("a2o-", "c2o-") and (not seen or seen[-1][0] != name):
                    seen.append((name, math.hypot(sim["x"] - flamingo["x"], sim["y"] - flamingo["y"])))
            state = host.step(2)
        assert state["budget"] == budget + 7, ("The wish was not granted", seen, (flamingo["x"], flamingo["y"]), trace)
        assert [name[4:] for name, _ in seen] == wish_clips, seen
        assert all(distance < 2.5 for _, distance in seen), ("The Sim animated away from the flamingo", seen)
        wish_animations = [{"animation": name, "distance": round(distance, 2)} for name, distance in seen]
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

    # A host started in French shows the translated catalog text and pie menu; untranslated objects fall back to the
    # document's default text rather than the template's.
    host = Host(content, "french", language=3)
    try:
        french = document["objects"][0]["translations"]["French"]
        catalog = {item["guid"]: item for item in host.request("catalog")["objects"]}
        item, _ = catalog_item(host, catalog, flamingo_guid)
        assert (item["name"], item["description"]) == (french["catalogName"], french["description"]), item
        item, _ = catalog_item(host, catalog, painted_guid)
        assert item["name"] == painted["objects"][0]["catalogName"], item
        state = host.step(30)
        (flamingo,), state = host.buy(flamingo_guid, {flamingo_guid}, state)
        names = [entry["name"] for entry in menu(host, flamingo["id"])]
        assert french["interactions"]["Make a Wish"] in names and "Make a Wish" not in names, names
        translated = {"catalogName": french["catalogName"], "menu": names}
    finally:
        host.close()

    result = {"result": "passed", "pack": document["packID"], "objects": summary["objects"], "multiTileParts": len(table_parts),
              "tableRefund": refund, "french": translated, "spriteHues": sprite_counts, "iconHues": icon_hues,
              "painted": painted_summary["painted"], "paintedTextures": painted_match, "wishAnimations": wish_animations, "packWarnings": pack_warnings,
              "rejectedBeforeWrite": rejected}
    (root / "logs").mkdir(exist_ok=True)
    (root / "logs/native-object-authoring-result.json").write_text(json.dumps(result, indent=2))
    print(json.dumps({key: result[key] for key in ["result", "pack", "multiTileParts", "tableRefund"]}))
    shutil.rmtree(session, ignore_errors=True)



try:
    main()
finally:
    # The mounted content is a full game copy; keep only the logs of a failed run.
    shutil.rmtree(session / "content", ignore_errors=True)
