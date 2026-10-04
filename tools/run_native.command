#!/bin/zsh
set -eu
task_root="${0:A:h:h}"
task_house="${1:-5}"
if [[ -n "${SIMS_GAME_DIR:-}" ]]; then
  task_game="$SIMS_GAME_DIR"
elif [[ -r "$HOME/Downloads/The Sims 1/UIGraphics/UIGraphics.far" && -r "$HOME/Downloads/The Sims 1/TemplateUserData/LotLocations.iff" ]]; then
  task_game="$HOME/Downloads/The Sims 1"
else
  task_game="$task_root/runtime/game"
fi
export DOTNET_CLI_HOME="$task_root/runtime/dotnet"
export NUGET_PACKAGES="$task_root/runtime/nuget"
dotnet build "$task_root/native/SimsSimulation/SimsSimulation.csproj" -c Release --no-restore --disable-build-servers -p:EnableWindowsTargeting=true -p:UseSharedCompilation=false
"$task_root/tools/build_native_app.command"
exec "$task_root/Sims Native Preview.app/Contents/MacOS/SimsNative" --workspace "$task_root" --game "$task_game" --packs "$task_root/packs" --live --house "$task_house"
