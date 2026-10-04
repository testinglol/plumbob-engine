import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import uuid


root = Path(__file__).resolve().parents[1]
session = root / "runtime/native-sessions" / ("custom-object-" + uuid.uuid4().hex)
packs = session / "packs"
pack = packs / "local.object-check"
asset = pack / "files/Downloads/local.object-check/native-flamingo.iff"
asset.parent.mkdir(parents=True)
source = root / "runtime/game/GameData/Objects/Objects.far"
archive = source.read_bytes()
source_hash = hashlib.sha256(archive).hexdigest()
assert archive[:8] == b"FAR!byAZ" and struct.unpack_from("<I", archive, 8)[0] == 1
cursor = struct.unpack_from("<I", archive, 12)[0]
count = struct.unpack_from("<I", archive, cursor)[0]
cursor += 4
fixture = None
for index in range(count):
    size, stored, offset, length = struct.unpack_from("<4I", archive, cursor)
    cursor += 16
    name = archive[cursor:cursor + length].decode("latin1")
    cursor += length
    if name.lower() == "flamingo.iff":
        assert size == stored and offset + size <= len(archive)
        fixture = bytearray(archive[offset:offset + size])
        break
assert fixture is not None, "Original flamingo resource was not found"
guid = 0xF1A00001
cursor = 64
definitions = 0
while cursor < len(fixture):
    assert cursor + 76 <= len(fixture)
    size = struct.unpack_from(">I", fixture, cursor + 4)[0]
    assert size >= 76 and cursor + size <= len(fixture)
    if fixture[cursor:cursor + 4] == b"OBJD":
        payload = cursor + 76
        object_chunk_id = struct.unpack_from(">H", fixture, cursor + 8)[0]
        assert struct.unpack_from("<I", fixture, payload)[0] == 138
        assert struct.unpack_from("<I", fixture, payload + 28)[0] == 0x3659DCA2
        struct.pack_into("<I", fixture, payload + 28, guid)
        struct.pack_into("<H", fixture, payload + 36, 37)
        label = b"Native Custom Flamingo"
        fixture[cursor + 12:cursor + 76] = label + bytes(64 - len(label))
        definitions += 1
    cursor += size
assert definitions == 1 and cursor == len(fixture)
asset.write_bytes(fixture)
manifest = {"schemaVersion": 1, "id": "local.object-check", "name": "Native object integration fixture", "version": "0.1.0", "baseGameVersion": "1.90", "dependencies": [], "overrides": []}
(pack / "pack.json").write_text(json.dumps(manifest, indent=2))
binary = root / "native/SimsNative/.build/release/SimsNative"
arguments = [str(binary), "--game", str(root / "runtime/game"), "--packs", str(packs)]
report = json.loads(subprocess.check_output(arguments + ["--pack-report"], text=True))
assert report["resources"][0]["owner"] == "local.object-check"
assert report["objects"] == [{"guid": guid, "chunkID": object_chunk_id, "path": "downloads/local.object-check/native-flamingo.iff", "owner": "local.object-check"}]
initial_fingerprint = report["fingerprint"]
manifest_before = (pack / "pack.json").read_bytes()
allocation = json.loads(subprocess.check_output(arguments + ["--allocate-object-guid", "flamingo", "--pack-id", manifest["id"]], text=True))
assert (pack / "pack.json").read_bytes() == manifest_before
assert allocation["guid"] & 0xF0000000 == 0xE0000000
reservation = json.loads(subprocess.check_output(arguments + ["--reserve-object-guid", "flamingo", "--pack-id", manifest["id"]], text=True))
assert reservation == allocation
guid = reservation["guid"]
manifest = json.loads((pack / "pack.json").read_text())
assert manifest["objectGUIDs"] == {"flamingo": guid}
cursor = 64
while cursor < len(fixture):
    size = struct.unpack_from(">I", fixture, cursor + 4)[0]
    if fixture[cursor:cursor + 4] == b"OBJD":
        struct.pack_into("<I", fixture, cursor + 76 + 28, guid)
    cursor += size
asset.write_bytes(fixture)
assert json.loads(subprocess.check_output(arguments + ["--allocate-object-guid", "flamingo", "--pack-id", manifest["id"]], text=True)) == allocation
report = json.loads(subprocess.check_output(arguments + ["--pack-report"], text=True))
assert report["fingerprint"] != initial_fingerprint
assert report["reservations"] == [allocation]
assert report["objects"][0]["guid"] == guid
base_collision = bytearray(fixture)
cursor = 64
while cursor < len(base_collision):
    size = struct.unpack_from(">I", base_collision, cursor + 4)[0]
    if base_collision[cursor:cursor + 4] == b"OBJD":
        struct.pack_into("<I", base_collision, cursor + 76 + 28, 0x3659DCA2)
    cursor += size
asset.write_bytes(base_collision)
base_conflict_mount = session / "rejected-base-content"
base_conflict = subprocess.run(arguments + ["--mount", str(base_conflict_mount)], text=True, capture_output=True)
assert base_conflict.returncode != 0 and "Object GUID 0x3659DCA2 conflicts: base:" in base_conflict.stderr
assert not base_conflict_mount.exists()
asset.write_bytes(fixture)
alias_asset = asset.with_name("flamingo.iff")
asset.rename(alias_asset)
alias_mount = session / "rejected-alias-content"
alias_conflict = subprocess.run(arguments + ["--mount", str(alias_mount)], text=True, capture_output=True)
assert alias_conflict.returncode != 0 and "Object resource name flamingo.iff conflicts: base:" in alias_conflict.stderr
assert not alias_mount.exists()
alias_asset.rename(asset)
conflict_pack = packs / "local.conflict-check"
conflict_asset = conflict_pack / "files/Downloads/local.conflict-check/duplicate.iff"
conflict_asset.parent.mkdir(parents=True)
conflict_asset.write_bytes(fixture)
conflict_manifest = manifest | {"id": "local.conflict-check"}
(conflict_pack / "pack.json").write_text(json.dumps(conflict_manifest))
conflict_mount = session / "rejected-content"
conflict = subprocess.run(arguments + ["--mount", str(conflict_mount)], text=True, capture_output=True)
assert conflict.returncode != 0 and f"Object GUID 0x{guid:08X} conflicts" in conflict.stderr
assert not conflict_mount.exists()
conflict_asset.unlink()
(conflict_pack / "pack.json").unlink()
conflict_asset.parent.rmdir()
(conflict_asset.parent.parent).rmdir()
(conflict_pack / "files").rmdir()
conflict_pack.rmdir()
mount = session / "content"
subprocess.run(arguments + ["--mount", str(mount)], check=True, stdout=subprocess.DEVNULL)
metadata = json.loads((mount / ".native-pack-stack.json").read_text())
assert metadata["fingerprint"] == report["fingerprint"]
environment = os.environ | {"SIMS_TEST_GAME": str(mount), "SIMS_TEST_OBJECTS": "1", "SIMS_TEST_OBJECT_GUID": hex(guid)}
result = json.loads(subprocess.check_output(["python3", str(root / "tools/check_native_runtime.py")], env=environment, text=True))
assert result["objectEditing"]["guid"] == guid
assert result["objectEditing"]["name"] == "Native Custom Flamingo"
assert result["objectEditing"]["price"] == 37
assert hashlib.sha256(source.read_bytes()).hexdigest() == source_hash
result["customObjectPack"] = {"pack": str(pack), "fingerprint": report["fingerprint"], "sourceArchiveUnchanged": True, "duplicateGUIDRejectedBeforeMount": True, "baseGUIDRejectedBeforeMount": True, "baseFilenameAliasRejectedBeforeMount": True, "allocatedGUID": guid, "reservationPersisted": True}
destination = root / "logs/native-custom-object-result.json"
destination.write_text(json.dumps(result, indent=2))
print(json.dumps(result))
