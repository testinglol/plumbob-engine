#!/bin/zsh
# Builds the example gameplay plugin and stages it into examples/plugin-pack/plugin.
# Copy examples/plugin-pack into packs/ to enable it, then trust it explicitly:
#   native/SimsNative/.build/release/SimsNative --game GAME --packs packs --trust-plugin local.example-allowance
set -euo pipefail
cd "${0:A:h}/.."
export DOTNET_CLI_HOME="$PWD/runtime/dotnet"
export NUGET_PACKAGES="$PWD/runtime/nuget"
dotnet build native/SimsExamplePlugin/SimsExamplePlugin.csproj -c Release -p:NuGetAudit=false --disable-build-servers
mkdir -p examples/plugin-pack/plugin
cp native/SimsExamplePlugin/bin/Release/net9.0/LocalExampleAllowance.dll examples/plugin-pack/plugin/
if [[ -f native/SimsExamplePlugin/bin/Release/net9.0/LocalExampleAllowance.deps.json ]]; then
  cp native/SimsExamplePlugin/bin/Release/net9.0/LocalExampleAllowance.deps.json examples/plugin-pack/plugin/
fi
echo "Staged examples/plugin-pack/plugin"
