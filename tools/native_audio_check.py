import json
from pathlib import Path
import time
import uuid
import wave


def check_audio(request, raw_request, events):
    baseline = request("state")
    slot = "audio-" + uuid.uuid4().hex
    request("save", slot=slot)
    session = Path(request("scene")).parent.parent
    try:
        request("audio", enabled=True)
        records = []
        for name in ["ui_click", "ui_piemenu_appear", "ui_queued", "vox_laugh_giggle", "phone_ring"]:
            start = len(events)
            assert request("audioEvent", name=name, **({"ownerID": baseline["selectedSim"]} if name.startswith("vox_") else {}))["played"], f"Missing original event {name}"
            plays = []
            for attempt in range(60):
                time.sleep(0.02)
                request("state")
                plays = [event for event in events[start:] if event["command"] == "play"]
                if plays:
                    break
            if not plays:
                audio_state = request("audioState")
                raise AssertionError(f"Original HIT script produced no audio for {name}: {audio_state}")
            for play in plays:
                file = session / play["file"]
                assert file.exists() and 0 < play["duration"] <= 3600
                assert 0 <= play["volume"] <= 1 and -1 <= play["pan"] <= 1
                if file.suffix == ".wav":
                    with wave.open(str(file)) as audio:
                        assert audio.getnframes() > 0 and audio.getframerate() > 0
                        assert abs(audio.getnframes() / audio.getframerate() - play["duration"]) < 0.001
                if name.startswith("vox_"):
                    assert play["group"] == "VOX" and play["ownerID"] == baseline["selectedSim"] and play["spatial"]
                records.append({"name": name, "file": str(file), "duration": play["duration"], "group": play["group"]})
                request("audioEnded", voice=play["voice"])
        volume = request("audioVolume", group="VOX", volume=0.35)
        assert abs(volume["volumes"]["VOX"] - 0.35) < 0.0001
        for group, value in [("unknown", 0.5), ("FX", -0.1), ("MUSIC", 1.1)]:
            try:
                raw_request("audioVolume", group=group, volume=value)
            except RuntimeError as error:
                assert "Invalid audio group volume" in str(error)
            else:
                raise AssertionError("Invalid audio volume accepted")
        start = len(events)
        assert request("audioEvent", name="ui_nhood_bdoze_loop")["played"]
        loops = []
        for attempt in range(60):
            time.sleep(0.02)
            request("state")
            loops = [event for event in events[start:] if event["command"] == "play" and event["loop"]]
            if loops:
                break
        assert loops, "Original loop patch was not looped"
        for play in loops:
            request("audioEnded", voice=play["voice"])
        start = len(events)
        mode_music = request("modeMusic", mode="buy")
        assert mode_music == {"name": "bkground_buy1", "played": True}, mode_music
        music = []
        for attempt in range(100):
            time.sleep(0.02)
            request("state")
            music = [event for event in events[start:] if event["command"] == "play" and event["group"] == "MUSIC"]
            if music:
                break
        assert music, "Original mode music produced no MP3"
        records += [{"name": "bkground_buy1", "file": str(session / play["file"]), "duration": play["duration"], "group": play["group"]} for play in music]
        assert request("modeMusic", mode="build")["name"] == "bkground_build"
        for name in ["station_dtnhood", "station_vacation", "station_unleashed", "music_superstar_transition", "music_magictown_buy", "music_magictown_build"]:
            assert request("audioEvent", name=name)["played"], f"Missing expansion mode music {name}"
        assert request("modeMusic", mode="live")["name"] == "bkground_live"
        unchanged = request("state")
        for key in ["budget", "objects", "floors", "walls", "sims", "updates"]:
            assert unchanged[key] == baseline[key], f"UI audio mutated {key}"
        assert not request("audioEvent", name="native_missing_event")["played"]
        item = request("catalogPage", category=0, offset=0, count=1)["items"][0]
        start = len(events)
        request("previewObject", guid=item["guid"], x=16 * 16 + 8, y=20 * 16 + 8, level=1, direction=1)
        time.sleep(0.05)
        request("state")
        assert not any(event["command"] == "play" for event in events[start:]), "Isolated object preview emitted audio"
        target = next(obj for obj in baseline["objects"] if "tombstone" in obj["name"].lower())
        action = next(entry for entry in request("menu", objectID=target["id"]) if entry["name"] == "Mourn")
        start = len(events)
        request("interact", objectID=target["id"], interaction=action["interaction"], param0=action["param0"], **{"global": action["global"]})
        gameplay = []
        for attempt in range(30):
            request("step", count=100)
            gameplay = [event for event in events[start:] if event["command"] == "play" and event.get("ownerID", 0) > 0 and event.get("spatial")]
            if gameplay:
                break
        assert gameplay, "Original interaction or animation emitted no spatial audio"
        time.sleep(0.04)
        request("state")
        assert any(event["command"] == "pause" for event in events[start:]), "Pausing did not pause owned audio"
        request("speed", value=1)
        time.sleep(0.04)
        request("state")
        assert any(event["command"] == "resume" for event in events[start:]), "Resuming did not resume owned audio"
        request("speed", value=0)
        records += [{"name": "Mourn gameplay", "file": str(session / play["file"]), "duration": play["duration"], "group": play["group"]} for play in gameplay]
        start = len(events)
        request("load", slot=slot)
        assert any(event["command"] == "reset" for event in events[start:])
        assert abs(request("audioState")["volumes"]["VOX"] - 0.35) < 0.0001
        start = len(events)
        request("audio", enabled=False)
        assert any(event["command"] == "reset" for event in events[start:])
        try:
            raw_request("audioEvent", name="ui_click")
        except RuntimeError as error:
            assert "Audio is disabled" in str(error)
        else:
            raise AssertionError("Disabled audio accepted a play request")
        path = session / "audio-events.json"
        path.write_text(json.dumps(events, indent=2))
        return {"resources": records, "events": str(path), "originalHITScripts": True, "modeMusic": True, "loopPatch": True, "groupVolume": True, "loadReset": True, "silentObjectPreview": True, "scriptAndAnimationAudio": True, "pauseResume": True, "livePlaybackVerified": False}
    finally:
        request("audio", enabled=False)
        request("load", slot=slot)
