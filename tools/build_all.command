#!/bin/zsh
set -euo pipefail
export PATH="/opt/homebrew/bin:/usr/local/bin:$HOME/.dotnet:$PATH"
task_root="${0:A:h:h}"
export DOTNET_CLI_HOME="${DOTNET_CLI_HOME:-$task_root/runtime/dotnet}"
export NUGET_PACKAGES="${NUGET_PACKAGES:-$task_root/runtime/nuget}"
mkdir -p "$DOTNET_CLI_HOME" "$NUGET_PACKAGES"

cd "$task_root"

./tools/build_sdl_shaders.sh

dotnet build "$task_root/native/Plugins/CcBrowser/LocalCcBrowser.csproj" -c Release -m:1 --disable-build-servers -p:NuGetAudit=false -nologo -clp:ErrorsOnly
mkdir -p "$task_root/packs/cc-browser/plugin"
cp "$task_root/native/Plugins/CcBrowser/bin/Release/net9.0/LocalCcBrowser.dll" "$task_root/packs/cc-browser/plugin/LocalCcBrowser.dll"

if [[ -d "$task_root/expansions/seasons" && -x "$task_root/tools/seasons/build_seasons_pack.command" ]]; then
  "$task_root/tools/seasons/build_seasons_pack.command"
fi
if [[ -d "$task_root/expansions/lighting" && -x "$task_root/tools/lighting/build_lighting_pack.command" ]]; then
  "$task_root/tools/lighting/build_lighting_pack.command"
fi

"$task_root/tools/build_native_app.command"
