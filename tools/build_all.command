#!/bin/zsh
set -euo pipefail
export PATH="/opt/homebrew/bin:/usr/local/bin:$HOME/.dotnet:$PATH"
task_root="${0:A:h:h}"
export DOTNET_CLI_HOME="${DOTNET_CLI_HOME:-$task_root/runtime/dotnet}"
export NUGET_PACKAGES="${NUGET_PACKAGES:-$task_root/runtime/nuget}"
mkdir -p "$DOTNET_CLI_HOME" "$NUGET_PACKAGES"

cd "$task_root"

./tools/build_sdl_shaders.sh

dotnet build "$task_root/PlumbobEngine.sln" -c Release -m:1 --disable-build-servers -p:EnableWindowsTargeting=true -p:NuGetAudit=false -nologo -clp:ErrorsOnly

sdl_cli="$task_root/native/SimsSDL/bin/Release/net9.0/SimsSDL.dll"
dotnet "$sdl_cli" --build-pack "$task_root/packs/cc-browser" --pack-source "$task_root/native/Plugins/CcBrowser" >/dev/null
dotnet "$sdl_cli" --build-pack "$task_root/packs/smart-free-will" --pack-source "$task_root/native/Plugins/SmartFreeWill" >/dev/null
dotnet "$sdl_cli" --build-pack "$task_root/packs/lighting" --pack-source "$task_root/native/Plugins/Lighting" >/dev/null
dotnet "$sdl_cli" --build-pack "$task_root/packs/seasons" --pack-source "$task_root/native/Plugins/Seasons" >/dev/null

"$task_root/tools/build_native_app.command"
