#!/bin/zsh
set -eu
task_root="${0:A:h:h}"
export JAVA_TOOL_OPTIONS="-Duser.home=$task_root/runtime/ghidra-home -Dapplication.settingsdir=$task_root/runtime/ghidra-settings -Dapplication.cachedir=$task_root/runtime/ghidra-cache -Dapplication.tempdir=$task_root/runtime/ghidra-tmp"
exec "$task_root/tools/ghidra/ghidra_12.1.4_PUBLIC/support/analyzeHeadless" \
    "$task_root/analysis/ghidra-project" Sims1 \
    -process Sims.original.exe -noanalysis \
    -scriptPath "$task_root/tools/ghidra_scripts" \
    -postScript ExportSimsRenderer.java "$task_root/analysis/full-decompilation" all \
    -log "$task_root/logs/ghidra-full-analysis.log"
