import json
from pathlib import Path
import subprocess


root = Path(__file__).resolve().parents[1]
audio = json.loads((root / "logs/native-audio-result.json").read_text())["audio"]
binary = root / "native/SimsNative/.build/release/SimsNative"
decoded = []
for resource in audio["resources"]:
    result = json.loads(subprocess.check_output([str(binary), "--inspect-audio", resource["file"]], text=True))
    assert result["frames"] > 0 and result["sampleRate"] > 0 and result["channels"] in [1, 2]
    assert result["peak"] > 0, "Original audio decoded to silence"
    assert abs(result["duration"] - resource["duration"]) < 0.15, "Native duration differs from HIT resource duration"
    decoded.append(resource | {"decoded": result})
result = {"result": "passed", "nativeCodec": "AVFoundation", "livePlaybackVerified": False, "resources": decoded}
(root / "logs/native-audio-decode-result.json").write_text(json.dumps(result, indent=2))
print(json.dumps({"result": "passed", "decodedResources": len(decoded), "livePlaybackVerified": False}))
