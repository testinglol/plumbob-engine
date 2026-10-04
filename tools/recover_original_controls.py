import hashlib
import json
from pathlib import Path
import struct
import capstone


root = Path(__file__).resolve().parents[1]
source = root / "analysis/Sims.original.exe"
data = source.read_bytes()
pe = struct.unpack_from("<I", data, 0x3C)[0]
count = struct.unpack_from("<H", data, pe + 6)[0]
optional_size = struct.unpack_from("<H", data, pe + 20)[0]
image_base = struct.unpack_from("<I", data, pe + 52)[0]
sections = [struct.unpack_from("<IIII", data, pe + 24 + optional_size + index * 40 + 8) for index in range(count)]


def read_initializer(address):
    pattern = b"\xC7\x05" + struct.pack("<I", address)
    offset = data.find(pattern)
    if offset < 0 or data.find(pattern, offset + 1) >= 0:
        raise ValueError(f"Expected one original coordinate initializer for {address:#x}")
    value = struct.unpack_from("<i", data, offset + len(pattern))[0]
    location = next(image_base + virtual_address + offset - raw_offset for virtual_size, virtual_address, raw_size, raw_offset in sections if raw_offset <= offset < raw_offset + raw_size)
    return {"value": value, "instruction": hex(location), "fileOffset": hex(offset)}


controls = []
for name, address, asset, columns, rows in [
    ("pause", 0x6F4500, "cpanel/Buttons/pause.bmp", 4, 2),
    ("speed1", 0x6F44F8, "cpanel/Buttons/Speed1.bmp", 4, 1),
    ("speed2", 0x6F44F0, "cpanel/Buttons/Speed2.bmp", 4, 1),
    ("speed3", 0x6F44E8, "cpanel/Buttons/Speed3.bmp", 4, 1),
]:
    controls.append({"name": name, "x": read_initializer(address), "y": read_initializer(address + 4), "asset": asset, "columns": columns, "rows": rows})
result = {"source": str(source.relative_to(root)), "sha256": hashlib.sha256(data).hexdigest(), "controls": controls, "constructionFunction": "0x005382a4", "positionFunction": "0x004cb21d", "panelHeight": 183, "panelAsset": "cpanel/Backgrounds/UniversalBack.tga", "livePanelHeight": 150}
output = root / "analysis/original-speed-controls.json"
output.write_text(json.dumps(result, indent=2) + "\n")
print(output)


def read_coordinate_table(address, count, start, end):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    decoder.detail = True
    registers = {}
    stack = []
    writes = {}
    for instruction in decoder.disasm(bytes(read_original(start, f"<{end - start}B")), start):
        operands = instruction.operands
        if instruction.mnemonic == "push" and operands[0].type == capstone.x86.X86_OP_IMM:
            stack.append(operands[0].imm)
        elif instruction.mnemonic == "pop" and operands[0].type == capstone.x86.X86_OP_REG and stack:
            registers[operands[0].reg] = stack.pop()
        elif instruction.mnemonic == "mov" and len(operands) == 2:
            source = operands[1]
            value = source.imm if source.type == capstone.x86.X86_OP_IMM else registers.get(source.reg) if source.type == capstone.x86.X86_OP_REG else None
            target = operands[0]
            if target.type == capstone.x86.X86_OP_REG:
                registers[target.reg] = value
            elif target.type == capstone.x86.X86_OP_MEM and target.mem.base == 0 and target.mem.index == 0:
                if address <= target.mem.disp < address + count * 8 and value is not None:
                    writes[target.mem.disp] = {"value": value, "instruction": hex(instruction.address)}
        elif instruction.mnemonic == "ret":
            break
        else:
            raise ValueError(f"Unsupported coordinate initializer at {instruction.address:#x}")
    if len(writes) != count * 2:
        raise ValueError(f"Incomplete coordinate initializer at {start:#x}")
    return [{"x": writes[address + index * 8], "y": writes[address + index * 8 + 4]} for index in range(count)]


def read_original(address, format):
    size = struct.calcsize(format)
    for virtual_size, virtual_address, raw_size, raw_offset in sections:
        relative = address - image_base - virtual_address
        if 0 <= relative and relative + size <= raw_size:
            return list(struct.unpack_from(format, data, raw_offset + relative))
    raise ValueError(f"Original data at {address:#x} is not backed by the executable")


zodiac = read_original(0x6C5BE8, "<60f")
personality = {
    "source": str(source.relative_to(root)), "sha256": hashlib.sha256(data).hexdigest(),
    "constructionFunction": "0x0051dfa3", "layoutFunction": "0x005186da",
    "widgetInitializeFunction": "0x00521022", "labelAlignmentFunction": "0x00521577", "drawingFunction": "0x005212a3",
    "traitFields": read_original(0x66C600, "<5i"), "traitNames": ["Neat", "Outgoing", "Active", "Playful", "Nice"],
    "englishLayout": {"parent": [520, 50], "rightEdge": 202, "top": 8, "rowStep": 18, "labelPadding": 6, "widgetExtraWidth": 49},
    "backgroundAsset": "cpanel/Backgrounds/PersBkg.bmp", "backgroundSize": [40, 14],
    "barAsset": "cpanel/HouseSubBars.BMP", "barSize": [40, 16], "barOffsetY": -1,
    "quantization": {"divisor": 100, "range": [0, 10], "pixelsPerPoint": 4},
    "zodiac": {"function": "0x0048432f", "fields": read_original(0x6C5BD4, "<5i"), "scale": read_original(0x666A4C, "<f")[0],
               "profiles": [zodiac[index:index + 5] for index in range(0, 60, 5)], "selection": "minimum squared distance; first profile wins a tie"},
    "remainingParity": ["exact font bindings", "localization", "pet trait labels", "tooltips and zodiac popup", "frontend-derived unset zodiac is not written back into person data"]
}
output = root / "analysis/original-personality-controls.json"
output.write_text(json.dumps(personality, indent=2) + "\n")
print(output)

career = {
    "source": str(source.relative_to(root)), "sha256": hashlib.sha256(data).hexdigest(),
    "constructionFunction": "0x0052efca", "initializeFunction": "0x0052f3ac", "layoutFunction": "0x005186da",
    "drawingFunction": "0x00530296", "skillFields": read_original(0x66DFEC, "<6i"),
    "jobLevelGetter": "0x004ea85e", "nextLevelGetter": "0x004ea908", "unmetSkillGetter": "0x004ea95f",
    "performanceThresholds": read_original(0x666528, "<4f"),
    "originalStrings": {"file": "GameData/Live.iff", "labels": 136, "tooltips": 137, "workRatings": 4096, "schoolGrades": 4097},
    "livePanelLocalParent": {"x": read_initializer(0x6F3A80), "y": read_initializer(0x6F3A84)},
    "englishSkillLabels": read_coordinate_table(0x6F43D0, 6, 0x52EAD1, 0x52EB2F),
    "englishSkillBars": read_coordinate_table(0x6F42B0, 6, 0x52ED23, 0x52ED83),
    "englishMetadata": read_coordinate_table(0x6F4220, 4, 0x52EE73, 0x52EEB3),
    "englishMetadataSizes": read_coordinate_table(0x6F41C0, 4, 0x52EF42, 0x52EF79),
    "skills": [{"name": name, "field": field} for name, field in [("Cooking", 10), ("Mechanical", 12), ("Charisma", 11), ("Body", 17), ("Logic", 18), ("Creativity", 15)]],
    "assets": {"skillBars": {"resourceID": 4901, "file": "cpanel/JobSubBars.bmp"}, "skillBarsOff": {"resourceID": 4920, "file": "cpanel/Backgrounds/JobSubBarsOff.bmp"}, "jobButton": {"resourceID": 4902}, "jobPopup": {"resourceID": 4905}},
    "remainingParity": ["exact title wrapping, female titles and font bindings", "original metadata formatting", "job icon and popup mapping", "original requirement brackets and tooltips", "family-friend counter freshness", "localization", "exact school presentation and pets", "live presentation fault"]
}
output = root / "analysis/original-career-controls.json"
output.write_text(json.dumps(career, indent=2) + "\n")
print(output)


buy = {
    "source": str(source.relative_to(root)), "sha256": hashlib.sha256(data).hexdigest(),
    "constructor": "0x00504da4", "initialize": "0x00505151", "categoryLayout": "0x005067d2",
    "parent": {"x": read_initializer(0x6F35F0), "y": read_initializer(0x6F35F4), "height": 100},
    "categoryResourceIDs": read_original(0x6CC41C, "<8I"),
    "categoryPositionsRelativeToParentY": read_coordinate_table(0x6F3500, 8, 0x504599, 0x504635),
    "roomResourceIDs": read_original(0x6CC3DC, "<8I"),
    "roomPositionsRelativeToParentY": read_coordinate_table(0x6F3580, 8, 0x50447C, 0x504516),
    "thumbnailRegion": {"xRelativeToParent": 201, "yRelativeToParent": 0, "height": 100, "initializeInstruction": "0x0050520c"},
    "thumbnailTemplate": {"resourceID": 4300, "asset": "cpanel/Catalog/ThumbTemplate.bmp", "columns": 4, "size": [45, 45]},
    "patch": {"resourceID": 4804, "asset": "cpanel/Backgrounds/BuyPatch.bmp", "positionRelativeToUniversal": [64, 35]},
    "remaining": ["Thumbnail spacing and exact state binding", "Room and subsort browsing", "Mode button hit regions", "Placement preview and cursor", "Live presentation verification"]
}
output = root / "analysis/original-buy-controls.json"
output.write_text(json.dumps(buy, indent=2) + "\n")
print(output)

universal_controls = []
for name, address, resource, asset in [
    ("live", 0x6F4570, 2010, "People.bmp"),
    ("buy", 0x6F4558, 2008, "Objects.bmp"),
    ("build", 0x6F4560, 2003, "Arch.bmp"),
    ("zoomIn", 0x6F4598, 2013, "ZoomIn.bmp"),
    ("zoomOut", 0x6F4590, 2014, "ZoomOut.bmp"),
    ("wallsUp", 0x6F4588, 2006, "NoCut.bmp"),
    ("wallsCutaway", 0x6F4580, 2004, "Dynacut.bmp"),
    ("wallsDown", 0x6F4578, 2007, "NoWall.bmp"),
    ("options", 0x6F4568, 2009, "Options.bmp"),
]:
    universal_controls.append({"name": name, "resourceID": resource, "x": read_initializer(address), "y": read_initializer(address + 4), "asset": "cpanel/Buttons/" + asset, "columns": 4, "rows": 1})
output = root / "analysis/original-universal-controls.json"
output.write_text(json.dumps({"source": str(source.relative_to(root)), "sha256": hashlib.sha256(data).hexdigest(), "constructionFunction": "0x005382a4", "panelHeight": 183, "controls": universal_controls}, indent=2) + "\n")
print(output)

build_positions = read_coordinate_table(0x6F2BA0, 12, 0x005002A5, 0x00500376)
build_ids = read_original(0x6CC264, "<12I")
output = root / "analysis/original-build-controls.json"
output.write_text(json.dumps({"source": str(source.relative_to(root)), "sha256": hashlib.sha256(data).hexdigest(), "constructionFunction": "0x0050044b", "initFunction": "0x00500572", "layoutFunction": "0x00500d30", "tools": [{"resourceID": ident, **position} for ident, position in zip(build_ids, build_positions)], "patch": {"resourceID": 4805, "positionRelativeToUniversal": [113, 51]}, "catalog": {"xRelativeToParent": 338, "yRelativeToParent": 5, "width": 45, "height": 45, "stepX": 45, "stepY": 45}}, indent=2) + "\n")
print(output)
