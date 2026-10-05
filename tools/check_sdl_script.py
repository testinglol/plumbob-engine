#!/usr/bin/env python3
"""Plays UI flows in the SimsSDL window with scripted input (`SimsSDL --script`) and keeps a screenshot of each step.

Builds nothing: build SimsSDL (`swift build -c release --product SimsSDL`), SimsSimulation and the example plugin first.
Run without a display by setting SDL_VIDEO_DRIVER=offscreen. Screenshots of the installed game's art go to
logs/sdl-script/ (ignored by git); look at them to check what the player sees.

Flows:
  pie-menu      open the household's control panel on load, click a Sim and show its pie menu
  plugin-panel  trust the example allowance pack, choose Allowance > Details on a child and open the plugin's panel
  modes         open buy mode, switch to build mode, return to live mode
"""
import os, shutil, subprocess, sys, tempfile
from pathlib import Path

root = Path(__file__).resolve().parents[1]
game = Path(os.environ.get("SIMS_GAME_DIR", Path.home() / "Downloads/The Sims 1"))
app = root / "native/SimsNative/.build/release/SimsSDL"
shots = root / "logs/sdl-script"
pack_id = "local.example-allowance"
env = {**os.environ, "DOTNET_CLI_HOME": str(root / "runtime/dotnet"), "DOTNET_ROLL_FORWARD": os.environ.get("DOTNET_ROLL_FORWARD", "Major")}

flows = {
    "pie-menu": """
        waitfor lot 3600
        wait 300
        shot {shots}/pie-menu-1-lot.png
        clicksim 1
        waitfor menu 600
        wait 5
        shot {shots}/pie-menu-2-menu.png
        key escape
        quit
    """,
    "plugin-panel": """
        waitfor lot 3600
        wait 300
        clicksim 2
        waitfor menu 600
        choose Allowance
        wait 5
        shot {shots}/plugin-panel-1-submenu.png
        choose Details
        waitfor panel 600
        wait 10
        shot {shots}/plugin-panel-2-panel.png
        quit
    """,
    "modes": """
        waitfor lot 3600
        wait 120
        key b
        wait 120
        shot {shots}/modes-1-buy.png
        key f
        wait 120
        shot {shots}/modes-2-build.png
        key f
        wait 60
        shot {shots}/modes-3-live.png
        quit
    """,
}


def run(name, work):
    data = work / "data"
    arguments = ["--game", str(game), "--data-root", str(data)]
    if name == "plugin-panel":
        packs = work / "packs"
        shutil.copytree(root / "examples/plugin-pack", packs / "plugin-pack")
        arguments += ["--packs", str(packs)]
        trust = subprocess.run([str(app), *arguments, "--trust-plugin", pack_id], capture_output=True, text=True, env=env)
        if trust.returncode != 0:
            return f"trust failed: {trust.stderr[-400:]}"
    script = work / f"{name}.script"
    script.write_text("\n".join(line.strip() for line in flows[name].format(shots=shots).splitlines()) + "\n")
    result = subprocess.run([str(app), "--house", "5", "--no-audio", *arguments, "--script", str(script)],
                            capture_output=True, text=True, env=env, timeout=600)
    failure = next((line for line in result.stderr.splitlines() if "script failed" in line), None)
    if result.returncode != 0:
        return failure or f"exit {result.returncode}: {result.stderr[-400:]}"
    missing = [line.split()[1] for line in script.read_text().splitlines() if line.startswith("shot ") and not Path(line.split()[1]).exists()]
    return f"missing screenshots {missing}" if missing else None


def main():
    if not app.exists():
        raise SystemExit(f"Missing {app}; build SimsSDL first")
    selected = sys.argv[1:] or list(flows)
    shots.mkdir(parents=True, exist_ok=True)
    failed = False
    for name in selected:
        work = Path(tempfile.mkdtemp(prefix=f"sims-sdl-{name}-"))
        try:
            error = run(name, work)
        finally:
            shutil.rmtree(work, ignore_errors=True)
        print(f"{'FAIL' if error else 'ok'}  {name}" + (f": {error}" if error else ""))
        failed |= error is not None
    print(f"screenshots in {shots}")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
