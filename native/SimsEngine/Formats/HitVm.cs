using System.Buffers.Binary;

namespace SimsEngine.Formats;

// Sims.exe HIT VM parity (0057e3dc.c, 0057dac6.c, 0057dbfe.c).
public sealed class HitVm
{
    public const float SecondsPerTick = 0.005f; // 200 Hz HIT clock (0057163b.c:462)
    public const int MaxInstructionsPerTick = 100; // 0057dbfe.c:14
    public const int MaxTicksPerStep = 40;

    private const byte OpNote = 0x01;
    private const byte OpNoteOn = 0x02;
    private const byte OpNoteOff = 0x03;
    private const byte OpLoadB = 0x04;
    private const byte OpLoadL = 0x05;
    private const byte OpSet = 0x06;
    private const byte OpCall = 0x07;
    private const byte OpReturn = 0x08;
    private const byte OpWait = 0x09;
    private const byte OpWaitSamp = 0x0b;
    private const byte OpEnd = 0x0c;
    private const byte OpJump = 0x0d;
    private const byte OpTest = 0x0e;
    private const byte OpNop = 0x0f;
    private const byte OpAdd = 0x10;
    private const byte OpSub = 0x11;
    private const byte OpDiv = 0x12;
    private const byte OpMul = 0x13;
    private const byte OpCmp = 0x14;
    private const byte OpLess = 0x15;
    private const byte OpGreater = 0x16;
    private const byte OpNot = 0x17;
    private const byte OpRand = 0x18;
    private const byte OpAbs = 0x19;
    private const byte OpError = 0x1b;
    private const byte OpAssert = 0x1c;
    private const byte OpAddToGroup = 0x1d;
    private const byte OpRemoveFromGroup = 0x1e;
    private const byte OpGetVar = 0x1f;
    private const byte OpLoop = 0x20;
    private const byte OpSetLoop = 0x21;
    private const byte OpCallback = 0x22;
    private const byte OpSmartAdd = 0x23;
    private const byte OpSmartRemove = 0x24;
    private const byte OpSmartRemoveAll = 0x25;
    private const byte OpSmartSetCrit = 0x26;
    private const byte OpSmartChoose = 0x27;
    private const byte OpAnd = 0x28;
    private const byte OpNand = 0x29;
    private const byte OpOr = 0x2a;
    private const byte OpNor = 0x2b;
    private const byte OpXor = 0x2c;
    private const byte OpMax = 0x2d;
    private const byte OpMin = 0x2e;
    private const byte OpInc = 0x2f;
    private const byte OpDec = 0x30;
    private const byte OpPrintReg = 0x31;
    private const byte OpPlayTrk = 0x32;
    private const byte OpKillTrk = 0x33;
    private const byte OpTest1 = 0x3a;
    private const byte OpTest2 = 0x3b;
    private const byte OpTest3 = 0x3c;
    private const byte OpTest4 = 0x3d;
    private const byte OpIfEq = 0x3e;
    private const byte OpIfNe = 0x3f;
    private const byte OpIfGt = 0x40;
    private const byte OpIfLt = 0x41;
    private const byte OpIfGe = 0x42;
    private const byte OpIfLe = 0x43;
    private const byte OpSmartSetList = 0x44;
    private const byte OpSeqGroupKill = 0x45;
    private const byte OpSeqGroupWait = 0x46;
    private const byte OpSeqGroupReturn = 0x47;
    private const byte OpGetSrcDataField = 0x48;
    private const byte OpSeqGroupTrkId = 0x49;
    private const byte OpSetLL = 0x4a;
    private const byte OpSetLT = 0x4b;
    private const byte OpSetTL = 0x4c;
    private const byte OpWaitEq = 0x4d;
    private const byte OpWaitNe = 0x4e;
    private const byte OpWaitGt = 0x4f;
    private const byte OpWaitLt = 0x50;
    private const byte OpWaitGe = 0x51;
    private const byte OpWaitLe = 0x52;
    private const byte OpChainPatch = 0x53;

    public sealed class TrackThread
    {
        public required int InstanceId { get; init; }
        public required HotTrackDef Track { get; init; }
        public required HitBankModule Bank { get; init; }
        public HitBankModule CodeBank { get; init; } = null!;
        public required string EventName { get; init; }
        public int[] Registers { get; } = new int[0x64];
        public int Pc { get; set; }
        public int LoopPoint { get; set; }
        public Stack<int> CallStack { get; } = new();
        public bool Zf { get; set; }
        public bool Gt { get; set; }
        public bool Lt { get; set; }
        public long WaitUntilTick { get; set; }
        public long NoteOffTick { get; set; }
        public bool WaitingForSample { get; set; }
        public bool FadeKillPending { get; set; }
        public bool PausedBySimulation { get; internal set; }
        internal long SimulationPausedAtTick { get; set; }
        internal bool ResumeOnUnpause { get; set; }
        public int TargetThreadOrTrackId { get; set; }
        public int SourceObjectId { get; set; }
        public int VoiceOwnerId { get; set; }
        public int? ParentThreadId { get; set; }
        public long ActiveVoiceId { get; set; }
        public bool PendingVoiceBind { get; set; }
        public HitSmartList LocalSmartList { get; } = new();
        public HitSmartList ActiveSmartList { get; set; }
        public bool Killed { get; set; }

        public TrackThread()
        {
            ActiveSmartList = LocalSmartList;
        }
    }

    private readonly List<HitBankModule> modules = [];
    private readonly Dictionary<int, HotTrackDef> tracksById = [];
    private readonly Dictionary<int, HotPatchDef> patchesById = [];
    private readonly Dictionary<HitBankModule, Dictionary<int, HitSmartList>> moduleSmartLists = [];
    private readonly Dictionary<int, HitSmartList> extraSmartLists = [];
    private readonly Dictionary<int, HitSmartList> globalSmartLists = [];
    private readonly Dictionary<int, TrackThread> threads = [];
    private readonly Dictionary<long, int> voiceToThread = [];
    private readonly Dictionary<int, int> seqGroups = [];
    private readonly Dictionary<int, int> duckers = [];
    private readonly int[] globalRegisters = new int[0x20];
    private readonly Func<int, int, int>? getSourceDataField;
    private readonly Random rng;
    private readonly Queue<HitVmCommand> pendingCommands = new();

    private long currentTick = 1;
    private float tickAccumulator;
    private int nextThreadId = 1;
    private readonly HitSmartList emptySmartList = new();

    public long CurrentTick => currentTick;
    public int ActiveThreadCount => threads.Count;
    public int MainDuckPriority => globalRegisters[HitReg.MainDuckPri - 0x64];
    public bool IsPaused { get; set; }
    public int? CurrentThreadId { get; private set; }
    public event Action<TrackThread, TrackThread?>? ThreadStarted;
    public event Action<int>? ThreadKilled;

    public HitVm(
        IEnumerable<HitBankModule> bankModules,
        IReadOnlyDictionary<int, (int[] Items, int? ExplicitCrush)>? extraHitLists = null,
        IReadOnlyDictionary<int, HotPatchDef>? extraPatches = null,
        Func<int, int, int>? getSourceDataField = null,
        Random? rng = null)
    {
        this.getSourceDataField = getSourceDataField;
        this.rng = rng ?? new Random();

        globalRegisters[HitReg.SimSpeed - 0x64] = 1;
        globalRegisters[HitReg.MainVol - 0x64] = HitReg.DefaultVolume;

        foreach (var mod in bankModules)
        {
            modules.Add(mod);
            foreach (var (tid, trk) in mod.Tracks)
            {
                tracksById[tid] = trk;
            }
            foreach (var (pid, pch) in mod.Patches)
            {
                patchesById[pid] = pch;
            }
            var modLists = new Dictionary<int, HitSmartList>();
            foreach (var (hid, items) in mod.GlobalHitLists)
            {
                if (items.Length > 0)
                {
                    var list = new HitSmartList(items);
                    modLists[hid] = list;
                    globalSmartLists[hid] = list;
                }
            }
            moduleSmartLists[mod] = modLists;
        }

        if (extraPatches != null)
        {
            foreach (var (pid, pch) in extraPatches)
            {
                patchesById[pid] = pch;
            }
        }

        if (extraHitLists != null)
        {
            foreach (var (hid, (items, crush)) in extraHitLists)
            {
                extraSmartLists[hid] = new HitSmartList(items, crush);
            }
        }
    }

    public int GetGlobalRegister(int reg)
    {
        if (reg is >= 0x64 and <= 0x7f)
            return globalRegisters[reg - 0x64];
        return 0;
    }

    public void SetGlobalRegister(int reg, int value)
    {
        if (reg is >= 0x64 and <= 0x7f)
            globalRegisters[reg - 0x64] = value;
    }

    public TrackThread? GetThread(int instanceId) => threads.GetValueOrDefault(instanceId);

    public IReadOnlyList<HitVmCommand> DrainCommands()
    {
        if (pendingCommands.Count == 0) return [];
        var list = new List<HitVmCommand>(pendingCommands.Count);
        while (pendingCommands.Count > 0)
            list.Add(pendingCommands.Dequeue());
        return list;
    }

    public TrackThread? StartTrack(
        HotTrackDef track,
        int arg1 = 0,
        int arg2 = 0,
        int arg3 = 0,
        int arg4 = 0,
        string? eventName = null,
        bool runInitialBurst = true,
        int? voiceOwnerId = null)
    {
        var bank = track.Bank ?? modules.FirstOrDefault();
        var codeBank = track.CodeBank ?? bank;
        if (bank == null || codeBank == null) return null;
        if (track.EntryOffset is not { } entryOffset || entryOffset < 0 || entryOffset >= codeBank.HitBytes.Length)
            return null;

        var thread = new TrackThread
        {
            InstanceId = nextThreadId++,
            Track = track,
            Bank = bank,
            CodeBank = codeBank,
            EventName = eventName ?? track.Symbol,
            Pc = entryOffset,
            LoopPoint = entryOffset,
            SourceObjectId = arg1,
            VoiceOwnerId = voiceOwnerId ?? (track.IsPositionalObjectTrack ? arg1 : -1)
        };

        thread.Registers[HitReg.Arg1] = arg1;
        thread.Registers[HitReg.Arg2] = arg2;
        thread.Registers[HitReg.Arg3] = arg3;
        thread.Registers[HitReg.Arg4] = arg4;
        thread.Registers[HitReg.Priority] = 0x20;
        thread.Registers[HitReg.Vol] = track.InitialVol > 0 ? track.InitialVol : HitReg.DefaultVolume;
        thread.Registers[HitReg.ExtVol] = HitReg.DefaultVolume;
        thread.Registers[HitReg.Pan] = HitReg.DefaultPan;
        thread.Registers[HitReg.Pitch] = HitReg.DefaultPitch;
        thread.Registers[HitReg.DuckPri] = track.DuckPriority;
        thread.Registers[HitReg.MinDistance] = 100;
        thread.Registers[HitReg.MaxDistance] = 10000;
        thread.Registers[HitReg.IsLooped] = track.IsLoopedHint ? 1 : 0;
        thread.Registers[HitReg.Source] = arg1;
        thread.Registers[HitReg.Patch] = track.InitialPatchId;
        thread.Registers[HitReg.Spl] = track.Spl > 0 ? track.Spl : 20;

        threads[thread.InstanceId] = thread;

        if (runInitialBurst)
        {
            StepThread(thread);
        }

        return thread;
    }

    public void RunInitialBurst(TrackThread thread) => StepThread(thread);

    public void BindVoice(int threadId, long voiceId)
    {
        if (threads.TryGetValue(threadId, out var thread))
        {
            if (thread.ActiveVoiceId != 0 && thread.ActiveVoiceId != voiceId)
            {
                voiceToThread.Remove(thread.ActiveVoiceId);
            }
            thread.PendingVoiceBind = false;
            thread.ActiveVoiceId = voiceId;
            thread.Registers[HitReg.IsPlaying] = 1;
            voiceToThread[voiceId] = threadId;
        }
    }

    public void ClearPendingVoiceBind(int threadId)
    {
        if (threads.TryGetValue(threadId, out var thread))
        {
            thread.PendingVoiceBind = false;
        }
    }

    public bool OnVoiceEnded(long voiceId)
    {
        if (!voiceToThread.Remove(voiceId, out var threadId))
            return false;

        if (!threads.TryGetValue(threadId, out var thread) || thread.Killed)
            return false;

        if (thread.ActiveVoiceId == voiceId)
        {
            thread.ActiveVoiceId = 0;
            thread.Registers[HitReg.IsPlaying] = 0;
        }

        if (thread.WaitingForSample || IsPreSampleWait(thread))
        {
            thread.WaitingForSample = false;
            if (thread.PausedBySimulation)
            {
                thread.ResumeOnUnpause = true;
                thread.WaitUntilTick = 0;
            }
            else if (IsPaused || thread.Registers[HitReg.Paused] != 0)
            {
                thread.WaitUntilTick = Math.Max(1, currentTick);
            }
            else
            {
                thread.WaitUntilTick = currentTick;
                StepThread(thread);
            }
        }

        return true;
    }

    private static bool IsPreSampleWait(TrackThread thread)
    {
        // Station/TV tracks execute `wait 250` before `wait_samp` (0x0b) while a voice is playing.
        // If the voice ends early (e.g., short clip or radio_next_song), resume directly into wait_samp.
        var hit = thread.CodeBank.HitBytes;
        return thread.Pc >= 0 && thread.Pc < hit.Length && hit[thread.Pc] == OpWaitSamp;
    }

    public void SetThreadSimulationPaused(int threadId, bool paused)
    {
        if (threads.TryGetValue(threadId, out var thread))
            SetThreadSimulationPaused(thread, paused);
    }

    public void SetSimulationPaused(Func<TrackThread, bool> shouldPause, bool paused)
    {
        foreach (var thread in threads.Values)
        {
            if (paused)
            {
                if (!thread.PausedBySimulation && shouldPause(thread))
                    SetThreadSimulationPaused(thread, true);
            }
            else if (thread.PausedBySimulation)
            {
                SetThreadSimulationPaused(thread, false);
            }
        }
    }

    private void SetThreadSimulationPaused(TrackThread thread, bool paused)
    {
        if (thread.PausedBySimulation == paused) return;
        if (paused)
        {
            thread.PausedBySimulation = true;
            thread.SimulationPausedAtTick = currentTick;
        }
        else
        {
            thread.PausedBySimulation = false;
            if (thread.ResumeOnUnpause)
            {
                thread.ResumeOnUnpause = false;
                thread.WaitUntilTick = Math.Max(1, currentTick);
            }
            else
            {
                long deltaTicks = Math.Max(0, currentTick - thread.SimulationPausedAtTick);
                if (thread.WaitUntilTick > 0)
                    thread.WaitUntilTick += deltaTicks;
                if (thread.NoteOffTick > 0)
                    thread.NoteOffTick += deltaTicks;
            }
        }
    }

    public void KillThreadsForOwner(int ownerId)
    {
        foreach (var thread in threads.Values.Where(t => t.VoiceOwnerId == ownerId).ToArray())
        {
            KillThread(thread);
        }
    }

    public void KillThreadsForTrackId(int trackId)
    {
        foreach (var thread in threads.Values.Where(t => t.Track.TrackId == trackId || t.InstanceId == trackId).ToArray())
        {
            KillThread(thread);
        }
    }

    public void KillThread(int threadId)
    {
        if (threads.TryGetValue(threadId, out var thread))
        {
            KillThread(thread);
        }
    }

    public void Reset()
    {
        foreach (var thread in threads.Values.ToArray())
        {
            if (thread.ActiveVoiceId != 0)
            {
                pendingCommands.Enqueue(new HitStopVoiceCommand(thread.InstanceId, thread.ActiveVoiceId));
            }
        }
        threads.Clear();
        voiceToThread.Clear();
        seqGroups.Clear();
        tickAccumulator = 0f;
        if (duckers.Count > 0)
        {
            duckers.Clear();
            globalRegisters[HitReg.MainDuckPri - 0x64] = 0;
        }
    }

    public void Tick(float deltaSeconds)
    {
        if (IsPaused || deltaSeconds <= 0f) return;
        tickAccumulator += deltaSeconds;
        int steps = 0;
        while (tickAccumulator >= SecondsPerTick && steps < MaxTicksPerStep)
        {
            tickAccumulator -= SecondsPerTick;
            StepOneTick();
            steps++;
        }
        if (tickAccumulator > SecondsPerTick * MaxTicksPerStep)
        {
            tickAccumulator = 0f;
        }
    }

    public void StepTicks(int tickCount)
    {
        for (int i = 0; i < tickCount; i++)
        {
            StepOneTick();
        }
    }

    private void StepOneTick()
    {
        currentTick++;
        foreach (var thread in threads.Values.ToArray())
        {
            if (thread.Killed) continue;
            if (thread.PausedBySimulation || thread.Registers[HitReg.Paused] != 0) continue;

            StepThreadFade(thread);
            if (thread.Killed) continue;

            if (thread.FadeKillPending && thread.Registers[HitReg.FadeOn] == 0)
            {
                thread.FadeKillPending = false;
                KillThread(thread);
                continue;
            }

            if (thread.NoteOffTick != 0 && currentTick >= thread.NoteOffTick)
            {
                thread.NoteOffTick = 0;
                if (thread.ActiveVoiceId != 0)
                {
                    pendingCommands.Enqueue(new HitStopVoiceCommand(thread.InstanceId, thread.ActiveVoiceId));
                    voiceToThread.Remove(thread.ActiveVoiceId);
                    thread.ActiveVoiceId = 0;
                    thread.Registers[HitReg.IsPlaying] = 0;
                }
            }

            if (thread.WaitUntilTick != 0 && currentTick >= thread.WaitUntilTick)
            {
                StepThread(thread);
            }
        }
    }

    private void StepThreadFade(TrackThread thread)
    {
        // 0057dac6.c:17-36
        if (thread.Registers[HitReg.FadeOn] == 0) return;

        int targetReg = thread.Registers[HitReg.FadeVar];
        if (!IsValidRegister(targetReg))
        {
            KillThread(thread);
            return;
        }
        int dest = thread.Registers[HitReg.FadeDest];
        int speed = thread.Registers[HitReg.FadeSpeed];
        int current = GetReg(thread, targetReg, forceLocal: false);
        if (thread.Killed) return;

        if (speed == 0)
        {
            thread.Registers[HitReg.FadeOn] = 0;
            return;
        }

        if ((current < dest) != (speed > 0))
        {
            speed = -speed;
        }

        int next = current + speed;
        if ((speed > 0 && next > dest) || (speed < 0 && next < dest) || next == dest)
        {
            thread.Registers[HitReg.FadeOn] = 0;
            next = dest;
        }

        SetReg(thread, targetReg, next, forceLocal: false);
    }

    private void StepThread(TrackThread thread)
    {
        if (thread.Killed) return;
        thread.WaitUntilTick = 0;
        thread.WaitingForSample = false;

        var hit = thread.CodeBank.HitBytes;
        if (hit.Length == 0 || thread.Pc < 0 || thread.Pc >= hit.Length)
        {
            KillThread(thread);
            return;
        }

        int? prevThreadId = CurrentThreadId;
        CurrentThreadId = thread.InstanceId;
        try
        {
            for (int budget = 0; budget < MaxInstructionsPerTick; budget++)
            {
                if (thread.Killed || thread.WaitUntilTick != 0 || thread.Pc < 0 || thread.Pc >= hit.Length)
                    break;

                if (!ExecuteSingleInstruction(thread, hit))
                    break;
            }

            if (!thread.Killed && thread.WaitUntilTick == 0)
            {
                if (thread.Pc < 0 || thread.Pc >= hit.Length)
                    KillThread(thread);
                else
                    thread.WaitUntilTick = currentTick + 1;
            }
        }
        finally
        {
            CurrentThreadId = prevThreadId;
        }
    }

    private bool ExecuteSingleInstruction(TrackThread thread, byte[] hit)
    {
        int instrStart = thread.Pc;
        byte op = hit[thread.Pc++];

        switch (op)
        {
            case OpNote:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                int r1 = hit[thread.Pc++];
                int r2 = hit[thread.Pc++];
                if (!TryReadReg(thread, r1, false, out int noteArg) || !TryReadReg(thread, r2, false, out int dur))
                    return false;
                thread.NoteOffTick = currentTick + Math.Max(0, dur);
                EmitNoteOn(thread, noteArg);
                return true;
            }
            case OpNoteOn:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte b1 = hit[thread.Pc++];
                EmitNoteOn(thread, b1);
                return true;
            }
            case OpNoteOff:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                thread.Pc++;
                StopThreadVoice(thread);
                return true;
            }
            case OpLoadB:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte val = hit[thread.Pc++];
                return TryWriteReg(thread, dest, val, false);
            }
            case OpLoadL:
            {
                if (thread.Pc + 5 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                int val = BinaryPrimitives.ReadInt32LittleEndian(hit.AsSpan(thread.Pc, 4));
                thread.Pc += 4;
                return TryWriteReg(thread, dest, val, false);
            }
            case OpSet:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                if (!TryReadReg(thread, src, false, out int val)) return false;
                return TryWriteReg(thread, dest, val, false);
            }
            case OpCall:
            {
                if (thread.Pc + 4 > hit.Length) { KillThread(thread); return false; }
                int tkdId = BinaryPrimitives.ReadInt32LittleEndian(hit.AsSpan(thread.Pc, 4));
                thread.Pc += 4;
                if (ResolveTrackDataOffset(thread.CodeBank, tkdId, out int targetPc))
                {
                    thread.CallStack.Push(thread.Pc);
                    thread.Pc = targetPc;
                }
                else
                {
                    KillThread(thread);
                    return false;
                }
                return true;
            }
            case OpReturn:
            case OpEnd:
            {
                if (thread.CallStack.Count > 0)
                {
                    thread.Pc = thread.CallStack.Pop();
                    return true;
                }
                KillThread(thread);
                return false;
            }
            case OpWait:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int rawTicks)) return false;
                int ticks = Math.Max(0, rawTicks);
                if (ticks == 0) return true;
                thread.WaitUntilTick = currentTick + ticks;
                return false;
            }
            case OpWaitSamp:
            {
                if (thread.ActiveVoiceId == 0 && !thread.PendingVoiceBind)
                    return true;
                thread.Pc = instrStart;
                thread.WaitingForSample = true;
                thread.WaitUntilTick = currentTick + 2;
                return false;
            }
            case OpJump:
            {
                if (thread.Pc + 4 > hit.Length) { KillThread(thread); return false; }
                int tkdId = BinaryPrimitives.ReadInt32LittleEndian(hit.AsSpan(thread.Pc, 4));
                thread.Pc += 4;
                if (ResolveTrackDataOffset(thread.CodeBank, tkdId, out int targetPc))
                {
                    thread.Pc = targetPc;
                    return true;
                }
                KillThread(thread);
                return false;
            }
            case OpTest:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int v)) return false;
                thread.Zf = v == 0;
                thread.Gt = v > 0;
                thread.Lt = v < 0;
                return true;
            }
            case OpNop:
            case OpAddToGroup:
            case OpRemoveFromGroup:
            case OpSeqGroupWait:
                return true;
            case OpAdd:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, a + b, false);
            }
            case OpSub:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, a - b, false);
            }
            case OpDiv:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int dividend) || !TryReadReg(thread, src, false, out int divisor)) return false;
                if (divisor != 0)
                {
                    return TryWriteReg(thread, dest, dividend / divisor, false);
                }
                return true;
            }
            case OpMul:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, a * b, false);
            }
            case OpCmp:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte r1 = hit[thread.Pc++];
                byte r2 = hit[thread.Pc++];
                if (!TryReadReg(thread, r1, false, out int a) || !TryReadReg(thread, r2, false, out int b)) return false;
                thread.Zf = a == b;
                thread.Gt = a > b;
                thread.Lt = a < b;
                return true;
            }
            case OpLess:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, a < b ? 1 : 0, false);
            }
            case OpGreater:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, a > b ? 1 : 0, false);
            }
            case OpNot:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a)) return false;
                return TryWriteReg(thread, dest, a == 0 ? 1 : 0, false);
            }
            case OpRand:
            {
                if (thread.Pc + 3 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte minR = hit[thread.Pc++];
                byte maxR = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                if (!TryReadReg(thread, minR, false, out int minVal) || !TryReadReg(thread, maxR, false, out int maxVal)) return false;
                int span = maxVal - minVal;
                int chosen = span > 0 ? minVal + rng.Next(span) : minVal;
                return TryWriteReg(thread, dest, chosen, false);
            }
            case OpAbs:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int val)) return false;
                return TryWriteReg(thread, dest, val == int.MinValue ? int.MaxValue : Math.Abs(val), false);
            }
            case OpError:
            {
                KillThread(thread);
                return false;
            }
            case OpAssert:
            {
                if (thread.Pc + 1 <= hit.Length) thread.Pc++;
                KillThread(thread);
                return false;
            }
            case OpGetVar:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                if (!TryReadReg(thread, src, false, out int indirectReg)) return false;
                if (!TryReadReg(thread, indirectReg, false, out int indirectVal)) return false;
                return TryWriteReg(thread, dest, indirectVal, false);
            }
            case OpLoop:
            {
                thread.Pc = thread.LoopPoint;
                return true;
            }
            case OpSetLoop:
            {
                thread.LoopPoint = thread.Pc;
                return true;
            }
            case OpCallback:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte r1 = hit[thread.Pc++];
                byte r2 = hit[thread.Pc++];
                if (!IsValidRegister(r1) || !IsValidRegister(r2)) { KillThread(thread); return false; }
                return true;
            }
            case OpSmartAdd:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int val)) return false;
                thread.ActiveSmartList.Add(val);
                return true;
            }
            case OpSmartRemove:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int val)) return false;
                thread.ActiveSmartList.Remove(val);
                return true;
            }
            case OpSmartRemoveAll:
            {
                thread.ActiveSmartList.Clear();
                return true;
            }
            case OpSmartSetCrit:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int val)) return false;
                thread.ActiveSmartList.SetCrush(val);
                return true;
            }
            case OpSmartChoose:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                int? chosen = thread.ActiveSmartList.Choose(rng);
                if (chosen.HasValue)
                {
                    return TryWriteReg(thread, dest, chosen.Value, false);
                }
                return true;
            }
            case OpAnd: // Sims.exe computes a > b (0057e3dc.c:444-449)
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, a > b ? 1 : 0, false);
            }
            case OpNand:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, (a == 0 || b == 0) ? 1 : 0, false);
            }
            case OpOr:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, a | b, false);
            }
            case OpNor:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, (a == 0 && b == 0) ? 1 : 0, false);
            }
            case OpXor:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a) || !TryReadReg(thread, src, false, out int b)) return false;
                return TryWriteReg(thread, dest, a ^ b, false);
            }
            case OpMax: // Sims.exe caps to min(reg, imm32) (0057e3dc.c:526-540)
            {
                if (thread.Pc + 5 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                int imm = BinaryPrimitives.ReadInt32LittleEndian(hit.AsSpan(thread.Pc, 4));
                thread.Pc += 4;
                if (!TryReadReg(thread, dest, false, out int a)) return false;
                return TryWriteReg(thread, dest, Math.Min(a, imm), false);
            }
            case OpMin: // Sims.exe floors to max(reg, imm32) (0057e3dc.c:541-555)
            {
                if (thread.Pc + 5 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                int imm = BinaryPrimitives.ReadInt32LittleEndian(hit.AsSpan(thread.Pc, 4));
                thread.Pc += 4;
                if (!TryReadReg(thread, dest, false, out int a)) return false;
                return TryWriteReg(thread, dest, Math.Max(a, imm), false);
            }
            case OpInc:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a)) return false;
                return TryWriteReg(thread, dest, a + 1, false);
            }
            case OpDec:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                if (!TryReadReg(thread, dest, false, out int a)) return false;
                return TryWriteReg(thread, dest, a - 1, false);
            }
            case OpPrintReg:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!IsValidRegister(src)) { KillThread(thread); return false; }
                return true;
            }
            case OpPlayTrk:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int targetTrkId)) return false;
                if (TryFindTrack(thread.Bank, targetTrkId, out var childTrack))
                {
                    var child = StartTrack(
                        childTrack,
                        GetReg(thread, HitReg.Arg1, true),
                        GetReg(thread, HitReg.Arg2, true),
                        GetReg(thread, HitReg.Arg3, true),
                        0,
                        childTrack.Symbol,
                        runInitialBurst: false,
                        voiceOwnerId: childTrack.IsPositionalObjectTrack ? thread.VoiceOwnerId : -1);
                    if (child != null)
                    {
                        child.ParentThreadId = thread.InstanceId;
                        child.SourceObjectId = GetReg(thread, HitReg.Source, false);
                        child.Registers[HitReg.Source] = child.SourceObjectId;
                        ThreadStarted?.Invoke(child, thread);
                        StepThread(child);
                    }
                }
                return true;
            }
            case OpKillTrk:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int targetId)) return false;
                KillThreadsForTrackId(targetId);
                return true;
            }
            case OpTest1:
                return true;
            case OpTest2:
                SetReg(thread, HitReg.Pitch, 0xe10, false);
                return true;
            case OpTest3:
                SetReg(thread, HitReg.Pitch, 0x1004, false);
                return true;
            case OpTest4:
                SetReg(thread, HitReg.Pitch, 0x1210, false);
                return true;
            case OpIfEq:
            case OpIfNe:
            case OpIfGt:
            case OpIfLt:
            case OpIfGe:
            case OpIfLe:
            {
                if (thread.Pc + 4 > hit.Length) { KillThread(thread); return false; }
                int tkdId = BinaryPrimitives.ReadInt32LittleEndian(hit.AsSpan(thread.Pc, 4));
                thread.Pc += 4;
                bool cond = op switch
                {
                    OpIfEq => thread.Zf,
                    OpIfNe => !thread.Zf,
                    OpIfGt => thread.Gt && !thread.Zf,
                    OpIfLt => thread.Lt && !thread.Zf,
                    OpIfGe => thread.Gt || thread.Zf,
                    OpIfLe => thread.Lt || thread.Zf,
                    _ => false
                };
                if (cond && ResolveTrackDataOffset(thread.CodeBank, tkdId, out int targetPc))
                {
                    thread.Pc = targetPc;
                }
                return true;
            }
            case OpSmartSetList:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int listId)) return false;
                if (listId == 0)
                {
                    thread.ActiveSmartList = thread.LocalSmartList;
                }
                else if (moduleSmartLists.TryGetValue(thread.Bank, out var bankLists) && bankLists.TryGetValue(listId, out var bankList))
                {
                    thread.ActiveSmartList = bankList;
                }
                else if (thread.Bank.GlobalHitLists.TryGetValue(listId, out var arr) && arr.Length > 0)
                {
                    var created = new HitSmartList(arr);
                    if (bankLists == null)
                    {
                        bankLists = [];
                        moduleSmartLists[thread.Bank] = bankLists;
                    }
                    bankLists[listId] = created;
                    globalSmartLists.TryAdd(listId, created);
                    thread.ActiveSmartList = created;
                }
                else if (extraSmartLists.TryGetValue(listId, out var extraList))
                {
                    thread.ActiveSmartList = extraList;
                }
                else if (globalSmartLists.TryGetValue(listId, out var list))
                {
                    thread.ActiveSmartList = list;
                }
                else
                {
                    thread.ActiveSmartList = emptySmartList;
                }
                return true;
            }
            case OpSeqGroupKill:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int grp)) return false;
                if (seqGroups.TryGetValue(grp, out var priorId) &&
                    priorId != 0 &&
                    priorId != thread.InstanceId &&
                    threads.TryGetValue(priorId, out var prior) &&
                    !prior.Killed)
                {
                    if (GetReg(prior, HitReg.ExtVol, false) == 0)
                    {
                        KillThread(prior);
                    }
                    else if (!prior.FadeKillPending)
                    {
                        SetReg(prior, HitReg.FadeSpeed, 200, false);
                        SetReg(prior, HitReg.FadeVar, HitReg.ExtVol, false);
                        SetReg(prior, HitReg.FadeDest, 0, false);
                        SetReg(prior, HitReg.FadeOn, 1, false);
                        prior.FadeKillPending = true;
                    }
                }
                seqGroups[grp] = thread.InstanceId;
                return true;
            }
            case OpSeqGroupReturn:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int grp)) return false;
                if (seqGroups.TryGetValue(grp, out var ownerId) &&
                    ownerId != 0 &&
                    ownerId != thread.InstanceId &&
                    threads.ContainsKey(ownerId))
                {
                    KillThread(thread);
                    return false;
                }
                seqGroups[grp] = thread.InstanceId;
                return true;
            }
            case OpGetSrcDataField:
            {
                if (thread.Pc + 3 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte objReg = hit[thread.Pc++];
                byte fieldReg = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                if (!TryReadReg(thread, objReg, false, out int objId) || !TryReadReg(thread, fieldReg, false, out int fieldId)) return false;
                int val = getSourceDataField?.Invoke(objId, fieldId) ?? 0;
                return TryWriteReg(thread, dest, val, false);
            }
            case OpSeqGroupTrkId: // 0057e3dc.c:791-800
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte grpReg = hit[thread.Pc++];
                byte dest = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                if (!TryReadReg(thread, grpReg, false, out int grp)) return false;
                int ownerTid = 0;
                if (seqGroups.TryGetValue(grp, out var ownerInst) && threads.TryGetValue(ownerInst, out var ownerThread))
                {
                    ownerTid = ownerThread.Track.TrackId;
                }
                return TryWriteReg(thread, dest, ownerTid, false);
            }
            case OpSetLL:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                if (!TryReadReg(thread, src, forceLocal: true, out int val)) return false;
                return TryWriteReg(thread, dest, val, forceLocal: true);
            }
            case OpSetLT:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                if (!TryReadReg(thread, src, forceLocal: true, out int val)) return false;
                return TryWriteReg(thread, dest, val, forceLocal: false);
            }
            case OpSetTL:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte dest = hit[thread.Pc++];
                byte src = hit[thread.Pc++];
                if (!IsValidRegister(dest)) { KillThread(thread); return false; }
                if (!TryReadReg(thread, src, forceLocal: false, out int val)) return false;
                return TryWriteReg(thread, dest, val, forceLocal: true);
            }
            case OpWaitEq:
            case OpWaitNe:
            case OpWaitGt:
            case OpWaitLt:
            case OpWaitGe:
            case OpWaitLe:
            {
                if (thread.Pc + 2 > hit.Length) { KillThread(thread); return false; }
                byte r1 = hit[thread.Pc++];
                byte r2 = hit[thread.Pc++];
                if (!TryReadReg(thread, r1, false, out int a) || !TryReadReg(thread, r2, false, out int b)) return false;
                bool satisfied = op switch
                {
                    OpWaitEq => a == b,
                    OpWaitNe => a != b,
                    OpWaitGt => a > b,
                    OpWaitLt => a < b,
                    OpWaitGe => a >= b,
                    OpWaitLe => a <= b,
                    _ => true
                };
                if (satisfied) return true;
                thread.Pc = instrStart;
                thread.WaitUntilTick = currentTick + 2;
                return false;
            }
            case OpChainPatch:
            {
                if (thread.Pc + 1 > hit.Length) { KillThread(thread); return false; }
                byte src = hit[thread.Pc++];
                if (!TryReadReg(thread, src, false, out int patchId)) return false;
                if (thread.ActiveVoiceId != 0)
                {
                    pendingCommands.Enqueue(new HitChainPatchCommand(thread.InstanceId, thread.ActiveVoiceId, patchId, thread.Bank));
                }
                else
                {
                    SetReg(thread, HitReg.Patch, patchId, false);
                    EmitNoteOn(thread, 0);
                }
                return true;
            }
            default:
            {
                KillThread(thread);
                return false;
            }
        }
    }

    private static bool IsValidRegister(int reg) => reg is >= 1 and <= 0x7f;

    private bool TryReadReg(TrackThread thread, int reg, bool forceLocal, out int value)
    {
        if (!IsValidRegister(reg))
        {
            KillThread(thread);
            value = 0;
            return false;
        }
        value = GetReg(thread, reg, forceLocal);
        return !thread.Killed;
    }

    private bool TryWriteReg(TrackThread thread, int reg, int value, bool forceLocal)
    {
        if (!IsValidRegister(reg))
        {
            KillThread(thread);
            return false;
        }
        SetReg(thread, reg, value, forceLocal);
        return !thread.Killed;
    }

    public int GetReg(TrackThread thread, int reg, bool forceLocal)
    {
        if (!IsValidRegister(reg))
        {
            KillThread(thread);
            return 0;
        }

        if (reg is >= 0x64 and <= 0x7f)
            return globalRegisters[reg - 0x64];

        if (!forceLocal && reg != HitReg.Target && thread.TargetThreadOrTrackId != 0)
        {
            var target = FindTargetThread(thread.TargetThreadOrTrackId);
            if (target != null && target != thread)
                return GetReg(target, reg, forceLocal: true);
        }

        if (reg is >= 1 and < 0x64)
            return thread.Registers[reg];

        return 0;
    }

    public void SetReg(TrackThread thread, int reg, int value, bool forceLocal)
    {
        if (!IsValidRegister(reg))
        {
            KillThread(thread);
            return;
        }

        thread.Zf = value == 0;
        thread.Gt = value > 0;
        thread.Lt = value < 0;

        if (reg is >= 0x64 and <= 0x7f)
        {
            if (reg == HitReg.MainDuckPri)
            {
                UpdateDucker(thread.InstanceId, value);
            }
            else
            {
                globalRegisters[reg - 0x64] = value;
                if (reg == HitReg.MainVol)
                {
                    RefreshAllVoiceVolumes();
                }
            }
            return;
        }

        if (!forceLocal && reg != HitReg.Target && thread.TargetThreadOrTrackId != 0)
        {
            var target = FindTargetThread(thread.TargetThreadOrTrackId);
            if (target != null && target != thread)
            {
                SetReg(target, reg, value, forceLocal: true);
                return;
            }
        }

        if (reg is < 1 or >= 0x64) return;

        thread.Registers[reg] = value;

        if (reg == HitReg.Target)
        {
            thread.TargetThreadOrTrackId = value;
            return;
        }

        if (thread.ActiveVoiceId != 0 && reg is HitReg.Vol or HitReg.ExtVol or HitReg.Pan or HitReg.Pitch or HitReg.DuckPri)
        {
            EmitVoiceUpdate(thread);
        }
    }

    private void UpdateDucker(int threadId, int duckValue)
    {
        if (duckValue == 0)
            duckers.Remove(threadId);
        else
            duckers[threadId] = duckValue;

        int maxDuck = 0;
        foreach (var v in duckers.Values)
        {
            if (v > maxDuck) maxDuck = v;
        }

        if (globalRegisters[HitReg.MainDuckPri - 0x64] != maxDuck)
        {
            globalRegisters[HitReg.MainDuckPri - 0x64] = maxDuck;
            RefreshAllVoiceVolumes();
        }
    }

    private void RefreshAllVoiceVolumes()
    {
        foreach (var thread in threads.Values)
        {
            if (!thread.Killed && thread.ActiveVoiceId != 0)
            {
                EmitVoiceUpdate(thread);
            }
        }
    }

    private void EmitVoiceUpdate(TrackThread thread)
    {
        var (gain, pan, pitchScale) = ComputeChannelParams(thread);
        pendingCommands.Enqueue(new HitUpdateVoiceCommand(thread.InstanceId, thread.ActiveVoiceId, gain, pan, pitchScale));
    }

    private void EmitNoteOn(TrackThread thread, int noteArg)
    {
        int patchId = thread.Registers[HitReg.Patch];
        if (patchId <= 1 && noteArg > 1)
        {
            patchId = noteArg;
        }
        if (patchId <= 0) return;

        StopThreadVoice(thread);

        HotPatchDef? patch = ResolvePatch(thread.Bank, patchId);
        bool isLoop = thread.Registers[HitReg.IsLooped] != 0 || (patch?.IsLoop ?? false);
        // Radio/TV dynamic AutoPatch clips play non-looped so wait_samp advances on Ended.
        if (patchId >= 0x20000)
        {
            isLoop = false;
        }
        var (gain, pan, pitchScale) = ComputeChannelParams(thread, patch);
        thread.PendingVoiceBind = true;
        pendingCommands.Enqueue(new HitStartVoiceCommand(
            thread.InstanceId,
            thread.Track.TrackId,
            patchId,
            thread.Track.Group,
            isLoop,
            gain,
            pan,
            pitchScale,
            thread.SourceObjectId,
            thread.Track.IsPositionalObjectTrack,
            thread.EventName,
            thread.Bank));
    }

    private (float Gain, float Pan, float PitchScale) ComputeChannelParams(TrackThread thread, HotPatchDef? patch = null)
    {
        int vol = Math.Max(0, thread.Registers[HitReg.Vol]);
        int extVol = Math.Max(0, thread.Registers[HitReg.ExtVol]);
        int mainVol = Math.Max(0, globalRegisters[HitReg.MainVol - 0x64]);
        float gain = Math.Clamp((vol / 1024.0f) * (extVol / 1024.0f) * (mainVol / 1024.0f), 0.0f, 1.0f);

        int mainDuck = globalRegisters[HitReg.MainDuckPri - 0x64];
        if (mainDuck != 0 && thread.Registers[HitReg.DuckPri] < mainDuck)
        {
            gain *= 0.5f;
        }

        int panRaw = thread.Registers[HitReg.Pan];
        float pan = Math.Clamp((panRaw - 512) / 512.0f, -1.0f, 1.0f);

        int trackPitch = thread.Registers[HitReg.Pitch];
        patch ??= ResolvePatch(thread.Bank, thread.Registers[HitReg.Patch]);
        int patchPitch = patch?.Pitch ?? HitReg.DefaultPitch;
        int combinedPitch = trackPitch + patchPitch - HitReg.DefaultPitch;
        float pitchScale = combinedPitch == HitReg.DefaultPitch
            ? 1.0f
            : Math.Clamp(MathF.Pow(2.0f, (combinedPitch - HitReg.DefaultPitch) / 1200.0f), 0.0625f, 4.0f);

        return (gain, pan, pitchScale);
    }

    private void StopThreadVoice(TrackThread thread)
    {
        thread.PendingVoiceBind = false;
        if (thread.ActiveVoiceId != 0)
        {
            long vid = thread.ActiveVoiceId;
            thread.ActiveVoiceId = 0;
            thread.Registers[HitReg.IsPlaying] = 0;
            voiceToThread.Remove(vid);
            pendingCommands.Enqueue(new HitStopVoiceCommand(thread.InstanceId, vid));
        }
    }

    private void KillThread(TrackThread thread)
    {
        if (thread.Killed) return;
        thread.Killed = true;
        StopThreadVoice(thread);
        threads.Remove(thread.InstanceId);

        if (duckers.ContainsKey(thread.InstanceId))
        {
            UpdateDucker(thread.InstanceId, 0);
        }

        foreach (var grp in seqGroups.Where(kv => kv.Value == thread.InstanceId).Select(kv => kv.Key).ToArray())
        {
            seqGroups.Remove(grp);
        }

        ThreadKilled?.Invoke(thread.InstanceId);
    }

    private TrackThread? FindTargetThread(int targetId)
    {
        if (threads.TryGetValue(targetId, out var byInst) && !byInst.Killed)
            return byInst;
        return threads.Values.FirstOrDefault(t => !t.Killed && t.Track.TrackId == targetId);
    }

    private static bool ResolveTrackDataOffset(HitBankModule bank, int tkdId, out int offset)
    {
        if (bank.TrackDataOffsets.TryGetValue(tkdId, out offset) && offset >= 0 && offset < bank.HitBytes.Length)
            return true;
        offset = 0;
        return false;
    }

    private bool TryFindTrack(HitBankModule preferredBank, int trackId, out HotTrackDef track)
    {
        if (preferredBank.Tracks.TryGetValue(trackId, out track!)) return true;
        return tracksById.TryGetValue(trackId, out track!);
    }

    private HotPatchDef? ResolvePatch(HitBankModule preferredBank, int patchId)
    {
        if (preferredBank.Patches.TryGetValue(patchId, out var bankPatch))
            return bankPatch;
        return patchesById.GetValueOrDefault(patchId);
    }
}
