import copy
import json
from pathlib import Path
import struct
import subprocess

from PIL import Image, ImageChops


root = Path(__file__).resolve().parents[1]
panel = json.loads((root / "logs/native-panel-result.json").read_text())
original = json.loads(Path(panel["panelState"]).read_text())
binary = root / "Sims Native Preview.app/Contents/MacOS/SimsNative"
output = root / "analysis/gameplay-panel/relationship-check"
output.mkdir(parents=True, exist_ok=True)
selected = next(sim for sim in original["sims"] if sim["id"] == original["selectedSim"])
portrait = next((item["portrait"] for sim in original["sims"] for item in sim["relationships"] if item["portrait"]), None)
assert portrait and portrait["columns"] == 5
portrait_data = (Path(panel["scene"]).parent / portrait["file"]).read_bytes()
portrait_height = abs(struct.unpack_from("<i", portrait_data, 22)[0])
far = (root / "runtime/game/UIGraphics/UIGraphics.far").read_bytes()
position = struct.unpack_from("<I", far, 12)[0]
count = struct.unpack_from("<I", far, position)[0]
position += 4
for _ in range(count):
    size, stored, offset, length = struct.unpack_from("<IIII", far, position)
    position += 16
    name = far[position:position + length].decode().replace("\\", "/").lower()
    position += length
    if name == "fonts/variablesans_07.ffn":
        font = far[offset:offset + size]
        break
else:
    raise AssertionError("Original relationship font missing")
table = struct.unpack_from("<I", font, 20)[0]
glyph_count = struct.unpack_from("<H", font, 10)[0]
glyphs = []
for index in range(glyph_count):
    entry = table + index * 11
    code = struct.unpack_from("<H", font, entry)[0]
    if code != 160:
        glyphs.append((font[entry + 3], struct.unpack_from("<b", font, entry + 10)[0]))
line_height = max(height + dy for height, dy in glyphs) - min(0, min(dy for _, dy in glyphs))
state = copy.deepcopy(original)
resident = next(sim for sim in state["sims"] if sim["id"] == state["selectedSim"])
scores = [100, 60, 25, 24, 0] + [-index for index in range(1, 17)]
resident["relationships"] = [dict(neighborID=300 + index, guid=300 + index, name=f"Fixture {index}",
    values=[score, index % 2, -score, int(index == 0)], reverseDaily=score, household=index in [3, 4, 20],
    famous=index < 3, portrait=portrait) for index, score in enumerate(scores)]
renders = 0


def render(source, category, page, width, height, label):
    global renders
    path = output / f"{label}.json"
    path.write_text(json.dumps(source))
    target = output / f"{label}-{width}x{height}.png"
    subprocess.run([str(binary), "--scene", panel["scene"], "--panel-state", str(path), "--subpanel", "relationships",
        "--relationship-filter", category, "--relationship-page", str(page), "--width", str(width), "--height", str(height),
        "--render", str(target)], check=True, capture_output=True, text=True)
    renders += 1
    return Image.open(target).convert("RGB")


def bars(image, index, height):
    x = (557 + index * 45) * 2
    y = height - 300 + (68 + portrait_height - 2 + line_height) * 2
    return [image.crop((x, y + dy, x + 80, y + dy + rows)) for dy, rows in [(0, 4), (8, 8)]]


cases = []
for width, height in [(1600, 960), (2048, 1200), (2400, 1800)]:
    capacity = max(1, int((width / 2 - 566) / 45))
    pages = [render(state, "all", page, width, height, "all-page-" + str(page)) for page in range((len(scores) + capacity - 1) // capacity)]
    first = pages[0]
    for category, expected in [("family", [3, 4, 20]), ("friends", [0, 1, 2]), ("famous", [0, 1, 2])]:
        image = render(state, category, 0, width, height, category)
        for index, source in enumerate(expected):
            for actual, reference in zip(bars(image, index, height), bars(pages[source // capacity], source % capacity, height)):
                assert ImageChops.difference(actual, reference).getbbox() is None, (category, source)
        cases.append(dict(filter=category, resolution=[width, height], capacity=capacity, neighborIDs=[300 + index for index in expected]))
    changed = copy.deepcopy(state)
    entry = next(sim for sim in changed["sims"] if sim["id"] == changed["selectedSim"])["relationships"][0]
    entry["reverseDaily"] = 24
    entry["values"][3] = 0
    image = render(changed, "all", 0, width, height, "one-way-no-love")
    icon_y = height - 300 + (68 + portrait_height - 2 + line_height + 8 + line_height) * 2
    crop = (557 * 2, icon_y, 578 * 2, icon_y + 18)
    assert ImageChops.difference(first.crop(crop), image.crop(crop)).getbbox(), "Mutual friendship/love indicators did not update"
    empty = copy.deepcopy(state)
    next(sim for sim in empty["sims"] if sim["id"] == empty["selectedSim"])["relationships"] = []
    render(empty, "all", 0, width, height, "empty")
result = dict(result="passed", renderCount=renders, cases=cases, originalFiveExpressionPortrait=True,
    filtersAndPagingMatchRawRelationships=True, mutualFriendshipAndLoveIndicators=True, livePresentationVerified=False)
(root / "logs/native-relationship-render-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps(result))
