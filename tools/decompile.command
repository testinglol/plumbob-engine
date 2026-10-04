#!/bin/zsh
set -eu
task_root="${0:A:h:h}"
mkdir -p "$task_root/analysis/ghidra-project" "$task_root/analysis/decompiled" "$task_root/runtime/ghidra-home"
export JAVA_TOOL_OPTIONS="-Duser.home=$task_root/runtime/ghidra-home -Dapplication.settingsdir=$task_root/runtime/ghidra-settings -Dapplication.cachedir=$task_root/runtime/ghidra-cache -Dapplication.tempdir=$task_root/runtime/ghidra-tmp"
if [[ -f "$task_root/analysis/ghidra-project/Sims1.gpr" ]]; then
    exec "$task_root/tools/ghidra/ghidra_12.1.4_PUBLIC/support/analyzeHeadless" \
        "$task_root/analysis/ghidra-project" Sims1 \
        -process Sims.original.exe -noanalysis \
        -scriptPath "$task_root/tools/ghidra_scripts" \
        -postScript ExportSimsRenderer.java "$task_root/analysis/decompiled" 0x4f485b 0x004d0023 0x00509a74 0x0050a2a2 0x004f4f41 \
        -log "$task_root/logs/ghidra-analysis.log"
fi
exec "$task_root/tools/ghidra/ghidra_12.1.4_PUBLIC/support/analyzeHeadless" \
    "$task_root/analysis/ghidra-project" Sims1 \
    -import "$task_root/analysis/Sims.original.exe" \
    -max-cpu 4 -analysisTimeoutPerFile 300 \
    -scriptPath "$task_root/tools/ghidra_scripts" \
    -postScript ExportSimsRenderer.java "$task_root/analysis/decompiled" 0x4f485b 0x004d0023 0x00509a74 0x0050a2a2 0x004f4f41 \
    -log "$task_root/logs/ghidra-analysis.log"
