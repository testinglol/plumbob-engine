#!/usr/bin/env python3
"""Resource-discovery check for the seven official expansions.

For each pack it verifies its archive parses and is not empty, that its HIT sound banks have their companion tables, that
its neighborhood art exists in the UI archive, and that every lot listed for its map in LotLocations.iff has a house file in
the installed templates. This is the first item of each pack's completion checklist; it does not exercise behavior.
"""
import argparse
import json
import struct
import sys
from pathlib import Path

PACKS = [
    # name, folder, travel mode (LotLocations STR#), template folder, UI art that must exist, sound banks
    ("Livin' Large", "ExpansionPack1", None, None, [], ["ExpansionPack1/xpack.HIT"]),
    ("House Party", "ExpansionPack2", None, None, [], ["ExpansionShared/Sound/HouseParty.HIT"]),
    ("Hot Date", "ExpansionPack3", 2, "TemplateDowntown", ["Downtown/DScreen.bmp", "Downtown/dscreen00.bmp"], ["ExpansionShared/Sound/HotDate.HIT"]),
    ("Vacation", "ExpansionPack4", 3, "TemplateVacation", ["VIsland/visland.bmp", "VIsland/visland_waves001.bmp"], ["ExpansionShared/Sound/vacsnd.HIT"]),
    ("Unleashed", "ExpansionPack5", 4, "TemplateCommunity", ["Community/NScreen_unleashed.bmp"], []),
    ("Superstar", "ExpansionPack6", 5, "TemplateStudiotown", ["Studiotown/DScreen.bmp"], ["ExpansionPack6/Sound/sep6snds.HIT"]),
    ("Makin' Magic", "ExpansionPack7", 7, "TemplateMagicTown", ["Magicland/DScreen.bmp"], []),
]


def far_entries(path: Path) -> dict[str, int]:
    data = path.read_bytes()
    if data[:8] != b"FAR!byAZ":
        raise ValueError(f"{path.name} is not a FAR archive")
    offset = struct.unpack_from("<I", data, 12)[0]
    count = struct.unpack_from("<I", data, offset)[0]
    position = offset + 4
    entries = {}
    for _ in range(count):
        size, _, _, name_length = struct.unpack_from("<IIII", data, position)
        position += 16
        entries[data[position:position + name_length].decode("latin1").replace("\\", "/").lower()] = size
        position += name_length
    return entries


def string_chunks(path: Path) -> dict[int, list[str]]:
    data = path.read_bytes()
    position = 64
    result: dict[int, list[str]] = {}
    while position + 76 <= len(data):
        kind = data[position:position + 4]
        size = struct.unpack_from(">I", data, position + 4)[0]
        chunk_id = struct.unpack_from(">H", data, position + 8)[0]
        if size < 76 or position + size > len(data):
            break
        if kind == b"STR#":
            cursor, end = position + 76, position + size
            fmt = struct.unpack_from("<h", data, cursor)[0]
            cursor += 2
            strings: list[str] = []
            if cursor < end:
                count = struct.unpack_from("<H", data, cursor)[0]
                cursor += 2

                def c_string() -> str:
                    nonlocal cursor
                    stop = data.index(b"\0", cursor)
                    value = data[cursor:stop].decode("latin1")
                    cursor = stop + 1
                    return value

                for _ in range(count):
                    if fmt == -3:
                        language = data[cursor]
                        cursor += 1
                        value = c_string()
                        c_string()
                        if language in (0, 1):
                            strings.append(value)
                    elif fmt == -2:
                        strings.append(c_string())
                        c_string()
                    elif fmt == -1:
                        strings.append(c_string())
                    elif fmt == 0:
                        length = data[cursor]
                        cursor += 1
                        strings.append(data[cursor:cursor + length].decode("latin1"))
                        cursor += length
            result[chunk_id] = strings
        position += size
    return result


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("game", type=Path)
    args = parser.parse_args()
    game = args.game.resolve()
    ui = {name.lower(): size for name, size in far_entries(game / "UIGraphics/UIGraphics.far").items()}
    # The installed collection keeps lot lists for each map in several LotLocations.iff files; later templates hold supersets.
    lots: dict[int, list[str]] = {}
    for source in ("GameData", "TemplateCommunity", "TemplateStudiotown", "TemplateMagicTown", "TemplateUserData"):
        candidate = game / source / "LotLocations.iff"
        if candidate.exists():
            for mode, lines in string_chunks(candidate).items():
                if len(lines) >= len(lots.get(mode, [])):
                    lots[mode] = lines
    house_files = {p.name.lower() for folder in [game / "TemplateUserData/Houses", *game.glob("Template*")] if folder.exists() for p in folder.glob("House*.iff")}
    report, failures = [], 0
    for name, folder, mode, template, art, banks in PACKS:
        problems = []
        pack_dir = game / folder
        if not pack_dir.exists() and folder == "ExpansionPack1":
            pack_dir = game / "ExpansionPack"  # the installed collection's name for Livin' Large
        archives = list(pack_dir.glob("*.far")) if pack_dir.exists() else []
        entries = 0
        if not pack_dir.exists():
            problems.append(f"{folder} is missing")
        elif not archives:
            problems.append(f"{folder} has no archive")
        for archive in archives:
            try:
                parsed = far_entries(archive)
                entries += len(parsed)
                if not parsed:
                    problems.append(f"{archive.name} is empty")
            except (ValueError, struct.error) as error:
                problems.append(str(error))
        for bank in banks:
            base = pack_dir / bank[len(folder) + 1:] if bank.startswith(folder + "/") else game / bank
            for suffix in (".HIT", ".hsm", ".hot"):
                if not any(path.exists() for path in (base.with_suffix(suffix), base.with_suffix(suffix.lower()), base.with_suffix(suffix.upper()))):
                    problems.append(f"sound bank {bank} lacks its {suffix} companion")
        for resource in art:
            if ("nbhd/" + resource.lower()) not in ui and resource.lower() not in ui:
                problems.append(f"UI archive lacks {resource}")
        listed = []
        if mode is not None:
            if template and not (game / template).exists():
                problems.append(f"{template} is missing")
            listed = [int(line.split(",")[0]) for line in lots.get(mode, []) if line.strip()]
            if not listed:
                problems.append(f"LotLocations.iff has no lots for mode {mode}")
            for house in listed:
                if f"house{house:02d}.iff" not in house_files:
                    problems.append(f"mode {mode} lists lot {house} with no installed house file")
        failures += bool(problems)
        report.append({"pack": name, "archiveEntries": entries, "mapLots": len(listed), "problems": problems})
    print(json.dumps({"result": "failed" if failures else "passed", "packs": report}, indent=2))
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
