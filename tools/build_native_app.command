#!/bin/zsh
set -eu
task_root="${0:A:h:h}"
xcrun swift build --package-path "$task_root/native/SimsNative" --configuration release --cache-path /tmp/sims-swift-package-cache --scratch-path "$task_root/native/SimsNative/.build"
task_app="$task_root/Sims Native Preview.app"
mkdir -p "$task_app/Contents/MacOS"
task_binary=$(mktemp "$task_app/Contents/MacOS/SimsNative.XXXXXX")
trap 'rm -f "$task_binary"' EXIT
cp "$task_root/native/SimsNative/.build/release/SimsNative" "$task_binary"
chmod 755 "$task_binary"
mv -f "$task_binary" "$task_app/Contents/MacOS/SimsNative"
cp "$task_root/native/SimsNative/AppInfo.plist" "$task_app/Contents/Info.plist"
codesign --force --sign - "$task_app"
print "Built $task_app"
