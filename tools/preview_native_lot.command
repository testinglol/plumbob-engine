#!/bin/zsh
set -eu
task_root="${0:A:h:h}"
task_house="${1:-5}"
task_ticks="${2:-60}"
export DOTNET_CLI_HOME="$task_root/runtime/dotnet"
export NUGET_PACKAGES="$task_root/runtime/nuget"
"$task_root/tools/build_native_app.command"
dotnet build "$task_root/native/SimsSimulation/SimsSimulation.csproj" -c Release --no-restore --disable-build-servers -p:EnableWindowsTargeting=true -p:UseSharedCompilation=false
task_scene="$task_root/runtime/native-scenes/house$task_house"
dotnet "$task_root/native/SimsSimulation/bin/Release/net9.0/SimsSimulation.dll" "$task_root/runtime/game" "$task_root" "$task_house" "$task_ticks" "$task_scene"
exec "$task_root/Sims Native Preview.app/Contents/MacOS/SimsNative" --game "$task_root/runtime/game" --packs "$task_root/packs" --scene "$task_scene/scene.json"
