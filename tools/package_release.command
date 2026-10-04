#!/bin/zsh
# Builds a standalone Apple Silicon bundle: dist/Sims Native.app
# It contains the Swift client, a self-contained .NET simulation host and the FreeSO runtime content, but no
# Electronic Arts game assets. Players choose their own installed game folder on first launch.
#   tools/package_release.command [VERSION]
set -euo pipefail
root="${0:A:h:h}"
version="${1:-1.0.0}"
build="$(date +%Y%m%d%H%M)"
dist="$root/dist"
app="$dist/Sims Native.app"
work="$root/.package-staging/release-$build"
export DOTNET_CLI_HOME="$root/runtime/dotnet"
export NUGET_PACKAGES="$root/runtime/nuget"

rm -rf "$app"
mkdir -p "$dist" "$work"

xcrun swift build --package-path "$root/native/SimsNative" --configuration release --arch arm64 \
  --cache-path /tmp/sims-swift-package-cache --scratch-path "$root/native/SimsNative/.build"
swift_binary="$(xcrun swift build --package-path "$root/native/SimsNative" --configuration release --arch arm64 --show-bin-path \
  --scratch-path "$root/native/SimsNative/.build")/SimsNative"

dotnet publish "$root/native/SimsSimulation/SimsSimulation.csproj" -c Release -r osx-arm64 --self-contained true \
  -p:EnableWindowsTargeting=true -p:NuGetAudit=false -p:DebugType=None --disable-build-servers -o "$work/host"

workspace="$app/Contents/Resources/workspace"
host_dir="$workspace/native/SimsSimulation/bin/Release/net9.0"
content_src="$root/engine/Simitone/FreeSO/TSOClient/tso.content"
content_dst="$workspace/engine/Simitone/FreeSO/TSOClient/tso.content"
mkdir -p "$app/Contents/MacOS" "$host_dir" "$content_dst"
cp "$swift_binary" "$app/Contents/MacOS/SimsNative"
chmod 755 "$app/Contents/MacOS/SimsNative"
ditto "$work/host" "$host_dir"
ditto "$content_src/Content" "$content_dst/Content"
sed -e "s/__VERSION__/$version/" -e "s/__BUILD__/$build/" "$root/native/SimsNative/ReleaseInfo.plist" > "$app/Contents/Info.plist"
codesign --force --deep --sign - "$app"

echo "Built $app"
game_args=(--game "$root/runtime/game")
if [[ -n "${SIMS_GAME_DIR:-}" ]]; then game_args+=(--game "$SIMS_GAME_DIR"); fi
python3 "$root/tools/check_release_bundle.py" "$app" "${game_args[@]}"
