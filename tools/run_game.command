#!/bin/zsh
set -eu
task_root="${0:A:h:h}"
wine_bin='/Applications/CrossOver.app/Contents/SharedSupport/CrossOver/bin/wine'
task_bottle="$task_root/runtime/bottles/Sims1Mac"
task_action="${1:-game}"
cd "$task_root/runtime/game"
if [[ "$task_action" == 'registry' ]]; then
    exec "$wine_bin" --bottle "$task_bottle" --debugmsg '-all' regedit /S "$task_root/runtime/sims.reg"
fi
if [[ "$task_action" == 'stop' ]]; then
    exec "$wine_bin" --bottle "$task_bottle" --debugmsg '-all' taskkill /F /IM Sims.exe
fi
if [[ "$task_action" == 'probe' ]]; then
    exec "$wine_bin" --bottle "$task_bottle" --debugmsg '-all' notepad
fi
exec "$wine_bin" --bottle "$task_bottle" --no-convert --workdir 'C:\TheSims' --debugmsg '-all' 'C:\TheSims\Sims.exe' -w -r1024x768 -skip_intro
