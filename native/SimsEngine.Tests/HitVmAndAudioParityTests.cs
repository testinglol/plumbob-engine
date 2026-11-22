using System.Buffers.Binary;
using System.Reflection;
using System.Text;
using System.Text.Json;
using SimsEngine.Formats;
using SimsSDL;
using SimsSDL.Core;
using SimsSDL.UI;
using Xunit;

namespace SimsEngine.Tests;

public class HitVmAndAudioParityTests
{
    private const byte OpNote = 0x01;
    private const byte OpNoteOn = 0x02;
    private const byte OpLoadB = 0x04;
    private const byte OpLoadL = 0x05;
    private const byte OpSet = 0x06;
    private const byte OpCall = 0x07;
    private const byte OpReturn = 0x08;
    private const byte OpWait = 0x09;
    private const byte OpWaitSamp = 0x0b;
    private const byte OpEnd = 0x0c;
    private const byte OpAdd = 0x10;
    private const byte OpSub = 0x11;
    private const byte OpDiv = 0x12;
    private const byte OpMul = 0x13;
    private const byte OpCmp = 0x14;
    private const byte OpError = 0x1b;
    private const byte OpGetVar = 0x1f;
    private const byte OpLoop = 0x20;
    private const byte OpSetLoop = 0x21;
    private const byte OpCallback = 0x22;
    private const byte OpSmartChoose = 0x27;
    private const byte OpMax = 0x2d;
    private const byte OpMin = 0x2e;
    private const byte OpInc = 0x2f;
    private const byte OpDec = 0x30;
    private const byte OpPrintReg = 0x31;
    private const byte OpKillTrk = 0x33;
    private const byte OpIfEq = 0x3e;
    private const byte OpIfLt = 0x41;
    private const byte OpSmartSetList = 0x44;
    private const byte OpSeqGroupKill = 0x45;
    private const byte OpSeqGroupReturn = 0x47;
    private const byte OpGetSrcDataField = 0x48;
    private const byte OpSeqGroupTrkId = 0x49;
    private const byte OpSetLL = 0x4a;
    private const byte OpWaitEq = 0x4d;

    private static string? LocateGameDirectory() => TestGameLocator.Locate();

    private static List<byte> BuildBytes(Action<List<byte>> emit)
    {
        var list = new List<byte>();
        emit(list);
        return list;
    }

    private static void EmitInt32(List<byte> buf, int val)
    {
        Span<byte> tmp = stackalloc byte[4];
        BinaryPrimitives.WriteInt32LittleEndian(tmp, val);
        buf.AddRange(tmp);
    }

    [Fact]
    public void HitVm_OpcodesTrackDataJumpsArithmeticWaitAndNoteOffTick_ExecuteGenuinely()
    {
        var hit = new List<byte>();
        var tkdOffsets = new Dictionary<int, int>();

        tkdOffsets[100] = hit.Count;
        hit.AddRange([OpLoadB, HitReg.V8, 0]);
        hit.AddRange([OpGetSrcDataField, HitReg.V1, HitReg.Arg1, HitReg.V8]);
        hit.AddRange([OpLoadB, HitReg.V2, 2]);
        hit.AddRange([OpCmp, HitReg.V1, HitReg.V2]);
        hit.Add(OpIfEq); EmitInt32(hit, 200);
        hit.Add(OpError);

        tkdOffsets[200] = hit.Count;
        hit.AddRange([OpLoadB, HitReg.V3, 10]);
        hit.AddRange([OpLoadB, HitReg.V4, 3]);
        hit.AddRange([OpAdd, HitReg.V3, HitReg.V4]);
        hit.AddRange([OpSub, HitReg.V3, HitReg.V4]);
        hit.AddRange([OpMul, HitReg.V3, HitReg.V4]);
        hit.AddRange([OpDiv, HitReg.V3, HitReg.V4]);
        hit.AddRange([OpInc, HitReg.V3]);
        hit.AddRange([OpDec, HitReg.V3]);
        hit.Add(OpMax); hit.Add(HitReg.V3); EmitInt32(hit, 8); // Sims.exe HIT max caps to min(reg, imm32)
        hit.Add(OpMin); hit.Add(HitReg.V3); EmitInt32(hit, 12); // Sims.exe HIT min floors to max(reg, imm32)
        hit.Add(OpCall); EmitInt32(hit, 300);
        hit.Add(OpLoadL); hit.Add(HitReg.Patch); EmitInt32(hit, 50);
        hit.AddRange([OpLoadB, HitReg.V5, 4]);
        hit.AddRange([OpNote, HitReg.V5, HitReg.V5]);
        hit.AddRange([OpLoadB, HitReg.V6, 2]);
        hit.AddRange([OpWait, HitReg.V6]);
        hit.Add(OpWaitSamp);
        hit.Add(OpEnd);

        tkdOffsets[300] = hit.Count;
        hit.Add(OpLoadL); hit.Add(HitReg.Pitch); EmitInt32(hit, 4800);
        hit.Add(OpReturn);

        var mod = new HitBankModule("test", hit.ToArray());
        foreach (var (k, v) in tkdOffsets) mod.TrackDataOffsets[k] = v;
        mod.Patches[50] = new HotPatchDef(50, "PchTest", "test.wav", false);
        var trk = new HotTrackDef(1, "TrkTest", "FX", 1024, 10, 20, 0, "@100", tkdOffsets[100], false, true, mod);
        mod.Tracks[1] = trk;

        var vm = new HitVm([mod], getSourceDataField: (obj, fld) => (obj == 77 && fld == 0) ? 2 : 0, rng: new Random(1));
        var thread = vm.StartTrack(trk, arg1: 77);
        Assert.NotNull(thread);
        Assert.Equal(12, thread.Registers[HitReg.V3]);
        Assert.Equal(4800, thread.Registers[HitReg.Pitch]);

        var cmds = vm.DrainCommands();
        var startCmd = Assert.Single(cmds.OfType<HitStartVoiceCommand>());
        Assert.Equal(50, startCmd.PatchId);
        Assert.Equal(2.0f, startCmd.PitchScale, 3);
        vm.BindVoice(thread.InstanceId, 901);

        vm.StepTicks(2);
        Assert.Empty(vm.DrainCommands());
        Assert.NotNull(vm.GetThread(thread.InstanceId));

        vm.StepTicks(2);
        var stopCmds = vm.DrainCommands();
        var stopCmd = Assert.Single(stopCmds.OfType<HitStopVoiceCommand>());
        Assert.Equal(901, stopCmd.VoiceId);
    }

    [Fact]
    public void HitSmartList_CrushAndFifoRecycling_FollowsDecompiledSemantics()
    {
        var list = new HitSmartList([10, 20, 30, 40]);
        Assert.Equal(2, list.Crush);
        Assert.False(list.HasExplicitCrush);

        var rng = new Random(42);
        var picks = new List<int>();
        for (int i = 0; i < 6; i++)
        {
            picks.Add(list.Choose(rng)!.Value);
        }
        for (int i = 2; i < picks.Count; i++)
        {
            Assert.NotEqual(picks[i - 1], picks[i]);
            Assert.NotEqual(picks[i - 2], picks[i]);
        }

        var full = new HitSmartList([1, 2, 3], explicitCrush: 1_000_000);
        Assert.True(full.HasExplicitCrush);
        var round1 = new[] { full.Choose(rng)!.Value, full.Choose(rng)!.Value, full.Choose(rng)!.Value };
        Assert.Equal(3, round1.Distinct().Count());
        var round2 = new[] { full.Choose(rng)!.Value, full.Choose(rng)!.Value, full.Choose(rng)!.Value };
        Assert.Equal(round1, round2);
    }

    [Fact]
    public void HitVm_DuckingSeqGroupFadeAndTargetForwarding_ExecuteCorrectly()
    {
        var hit = new List<byte>();
        var tkdOffsets = new Dictionary<int, int>();

        tkdOffsets[1] = hit.Count;
        hit.Add(OpSetLoop);
        hit.AddRange([OpNoteOn, 10]);
        hit.Add(OpWaitSamp);
        hit.Add(OpLoop);

        tkdOffsets[2] = hit.Count;
        hit.AddRange([OpLoadB, HitReg.V1, 30]);
        hit.AddRange([OpSet, HitReg.MainDuckPri, HitReg.V1]);
        hit.AddRange([OpNoteOn, 20]);
        hit.AddRange([OpLoadB, HitReg.V2, 3]);
        hit.AddRange([OpWait, HitReg.V2]);
        hit.AddRange([OpLoadB, HitReg.V1, 0]);
        hit.AddRange([OpSet, HitReg.MainDuckPri, HitReg.V1]);
        hit.Add(OpEnd);

        tkdOffsets[3] = hit.Count;
        hit.AddRange([OpSet, HitReg.Target, HitReg.Arg1]);
        hit.Add(OpLoadL); hit.Add(HitReg.FadeDest); EmitInt32(hit, 0);
        hit.AddRange([OpLoadB, HitReg.FadeVar, HitReg.Vol]);
        hit.Add(OpLoadL); hit.Add(HitReg.FadeSpeed); EmitInt32(hit, 512);
        hit.AddRange([OpLoadB, HitReg.FadeOn, 1]);
        hit.AddRange([OpLoadB, HitReg.V1, 0]);
        hit.AddRange([OpWaitEq, HitReg.FadeOn, HitReg.V1]);
        hit.AddRange([OpSetLL, HitReg.V2, HitReg.Arg1]);
        hit.AddRange([OpLoadB, HitReg.Target, 0]);
        hit.AddRange([OpKillTrk, HitReg.V2]);
        hit.Add(OpEnd);

        var mod = new HitBankModule("duckfade", hit.ToArray());
        foreach (var (k, v) in tkdOffsets) mod.TrackDataOffsets[k] = v;
        mod.Patches[10] = new HotPatchDef(10, "PchMusic", "music.wav", true);
        mod.Patches[20] = new HotPatchDef(20, "PchSting", "sting.wav", false);
        var trk1 = new HotTrackDef(1, "Music", "MUSIC", 1024, 10, 20, 10, "@1", tkdOffsets[1], true, false, mod);
        var trk2 = new HotTrackDef(2, "Sting", "FX", 1024, 30, 20, 20, "@2", tkdOffsets[2], false, false, mod);
        var trk3 = new HotTrackDef(3, "Fader", "FX", 1024, 10, 20, 0, "@3", tkdOffsets[3], false, false, mod);
        mod.Tracks[1] = trk1;
        mod.Tracks[2] = trk2;
        mod.Tracks[3] = trk3;

        var vm = new HitVm([mod], rng: new Random(1));
        var t1 = vm.StartTrack(trk1)!;
        var s1 = Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        Assert.Equal(1.0f, s1.Gain, 3);
        vm.BindVoice(t1.InstanceId, 101);

        var t2 = vm.StartTrack(trk2)!;
        var cmds2 = vm.DrainCommands();
        Assert.Equal(30, vm.MainDuckPriority);
        var duckUpdate = Assert.Single(cmds2.OfType<HitUpdateVoiceCommand>(), u => u.VoiceId == 101);
        Assert.Equal(0.5f, duckUpdate.Gain, 3);
        vm.BindVoice(t2.InstanceId, 102);

        vm.StepTicks(3);
        var cmds3 = vm.DrainCommands();
        Assert.Equal(0, vm.MainDuckPriority);
        var unduckUpdate = Assert.Single(cmds3.OfType<HitUpdateVoiceCommand>(), u => u.VoiceId == 101);
        Assert.Equal(1.0f, unduckUpdate.Gain, 3);

        vm.StartTrack(trk3, arg1: 1);
        vm.DrainCommands();
        vm.StepTicks(6);
        var fadeCmds = vm.DrainCommands();
        Assert.Contains(fadeCmds.OfType<HitUpdateVoiceCommand>(), u => u.VoiceId == 101 && u.Gain < 0.6f);
        Assert.Contains(fadeCmds.OfType<HitStopVoiceCommand>(), s => s.VoiceId == 101);
        Assert.Null(vm.GetThread(t1.InstanceId));
    }

    [Fact]
    public void HitVm_SeqGroupKillAndReturn_ManageExclusiveGroupThreads()
    {
        var hit = new List<byte>();
        var tkdOffsets = new Dictionary<int, int>();

        tkdOffsets[1] = hit.Count;
        hit.AddRange([OpSeqGroupKill, HitReg.Arg1]);
        hit.AddRange([OpSeqGroupTrkId, HitReg.Arg1, HitReg.V1]);
        hit.AddRange([OpNoteOn, 10]);
        hit.Add(OpWaitSamp);
        hit.Add(OpEnd);

        tkdOffsets[2] = hit.Count;
        hit.AddRange([OpSeqGroupReturn, HitReg.Arg1]);
        hit.AddRange([OpNoteOn, 10]);
        hit.Add(OpEnd);

        var mod = new HitBankModule("seq", hit.ToArray());
        foreach (var (k, v) in tkdOffsets) mod.TrackDataOffsets[k] = v;
        mod.Patches[10] = new HotPatchDef(10, "Pch", "a.wav", false);
        var trk1 = new HotTrackDef(11, "T1", "VOX", 1024, 10, 20, 10, "@1", tkdOffsets[1], false, true, mod);
        var trk2 = new HotTrackDef(12, "T2", "VOX", 1024, 10, 20, 10, "@2", tkdOffsets[2], false, true, mod);
        mod.Tracks[11] = trk1;
        mod.Tracks[12] = trk2;

        var vm = new HitVm([mod]);
        var t1 = vm.StartTrack(trk1, arg1: 55)!;
        Assert.Equal(11, t1.Registers[HitReg.V1]);
        Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        vm.BindVoice(t1.InstanceId, 501);

        var t2 = vm.StartTrack(trk2, arg1: 55)!;
        Assert.Empty(vm.DrainCommands());
        Assert.Null(vm.GetThread(t2.InstanceId));

        var t3 = vm.StartTrack(trk1, arg1: 55)!;
        Assert.True(t1.FadeKillPending);
        Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        vm.StepTicks(10);
        Assert.Contains(vm.DrainCommands().OfType<HitStopVoiceCommand>(), s => s.VoiceId == 501);
        Assert.Null(vm.GetThread(t1.InstanceId));
        Assert.NotNull(vm.GetThread(t3.InstanceId));
    }

    [Fact]
    public void AudioEvent_PitchScale_SerializesAndValidates()
    {
        var valid = AudioEvent.FromJson("""
            {"command":"play","voice":1,"file":"audio/test.wav","duration":1.0,"group":"FX","volume":0.8,"pan":0.0,"loop":false,"pitchScale":0.5}
            """);
        valid.Validate();
        Assert.Equal(0.5f, valid.PitchScale);

        var badZero = valid with { PitchScale = 0f };
        Assert.Throws<ContentError>(() => badZero.Validate());

        var badHigh = valid with { PitchScale = 4.5f };
        Assert.Throws<ContentError>(() => badHigh.Validate());

        var badNaN = valid with { PitchScale = float.NaN };
        Assert.Throws<ContentError>(() => badNaN.Validate());
    }

    [Fact]
    public void AudioMixer_PitchScaleResampling_MuffleAndEndedCleanup_WorkAccurately()
    {
        var mixer = new AudioMixer();
        var samples = new float[200];
        for (int f = 0; f < 100; f++)
        {
            samples[f * 2] = f / 100f;
            samples[f * 2 + 1] = f / 100f;
        }

        var vFast = new AudioMixer.Voice(samples) { PitchScale = 2.0f };
        mixer.Set(1, vFast);
        mixer.MixAndPut(nint.Zero, 40);
        Assert.Empty(mixer.TakeEnded());
        mixer.MixAndPut(nint.Zero, 20);
        Assert.Equal([1L], mixer.TakeEnded());

        var loopSamples = new float[8];
        var vSlow = new AudioMixer.Voice(loopSamples) { PitchScale = 0.5f, Loop = true };
        mixer.Set(2, vSlow);
        mixer.MixAndPut(nint.Zero, 3);
        mixer.Update(2, (ref AudioMixer.Voice v) =>
        {
            Assert.Equal(1.5, v.FramePosition, 6);
            v.PitchScale = 1.0f;
        });
        mixer.MixAndPut(nint.Zero, 3);
        mixer.Update(2, (ref AudioMixer.Voice v) =>
        {
            Assert.Equal(0.5, v.FramePosition, 6);
        });
        Assert.Empty(mixer.TakeEnded());

        mixer.Set(3, new AudioMixer.Voice([]) { Loop = false });
        mixer.MixAndPut(nint.Zero, 4);
        mixer.Set(3, null);
        Assert.Empty(mixer.TakeEnded());
    }

    [Fact]
    public void HitAudioRuntime_ModeTransitionsPlaylistsTvAndPersistence_RealAssets()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null) return;

        var tempDir = Path.Combine(Path.GetTempPath(), $"sims-m1-parity-{Guid.NewGuid():N}");
        var profileDir = Path.Combine(tempDir, "profile");
        Directory.CreateDirectory(profileDir);
        try
        {
            var events = new List<object>();
            using var audio = new HitAudioRuntime(Path.Combine(tempDir, "session"), profileDir, msg =>
            {
                if (msg is not null) events.Add(msg);
            }, gameDir);

            events.Clear();
            Assert.True(audio.Play("bkground_load"));
            var loadMsg = events[^1];
            Assert.Contains("loadloop", loadMsg.GetType().GetProperty("file")?.GetValue(loadMsg)?.ToString(), StringComparison.OrdinalIgnoreCase);
            Assert.Equal(true, loadMsg.GetType().GetProperty("loop")?.GetValue(loadMsg));

            events.Clear();
            Assert.True(audio.Play("bkground_buy1"));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "stop");
            var play1 = events.Last(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            Assert.Equal(false, play1.GetType().GetProperty("loop")?.GetValue(play1));
            var buyVoice1 = (long)play1.GetType().GetProperty("voice")?.GetValue(play1)!;
            var buyFile1 = play1.GetType().GetProperty("file")?.GetValue(play1)?.ToString();

            events.Clear();
            audio.End(buyVoice1);
            var play2 = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            var buyVoice2 = (long)play2.GetType().GetProperty("voice")?.GetValue(play2)!;
            var buyFile2 = play2.GetType().GetProperty("file")?.GetValue(play2)?.ToString();
            Assert.NotEqual(buyFile1, buyFile2);

            events.Clear();
            Assert.True(audio.PlayForSimulationObject("stereo_country", ownerID: 42, pan: true, zoom: true));
            var stereoPlay = events.Last(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            var stereoVoice = (long)stereoPlay.GetType().GetProperty("voice")?.GetValue(stereoPlay)!;
            var stereoFile1 = stereoPlay.GetType().GetProperty("file")?.GetValue(stereoPlay)?.ToString();

            events.Clear();
            audio.End(stereoVoice);
            var stereoPlay2 = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            var stereoVoice2 = (long)stereoPlay2.GetType().GetProperty("voice")?.GetValue(stereoPlay2)!;
            Assert.NotEqual(stereoFile1, stereoPlay2.GetType().GetProperty("file")?.GetValue(stereoPlay2)?.ToString());

            events.Clear();
            Assert.True(audio.Play("radio_next_song", ownerID: 42));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "stop" && (long)e.GetType().GetProperty("voice")?.GetValue(e)! == stereoVoice2);
            var stereoPlay3 = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            var stereoVoice3 = (long)stereoPlay3.GetType().GetProperty("voice")?.GetValue(stereoPlay3)!;

            events.Clear();
            Assert.True(audio.Play("bkground_fade"));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "stop" && (long)e.GetType().GetProperty("voice")?.GetValue(e)! == buyVoice2);
            Assert.DoesNotContain(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "stop" && (long)e.GetType().GetProperty("voice")?.GetValue(e)! == stereoVoice3);

            Assert.True(audio.PlayLotAmbience(5));
            events.Clear();
            Assert.True(audio.Play("bkground_option"));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "pause");
            events.Clear();
            Assert.True(audio.Play("bkground_live"));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "resume");

            // simssound.HIT defines tv_action_cheap pitch=2400 (0.5x).
            events.Clear();
            Assert.True(audio.PlayForSimulationObject("tv_action_cheap", ownerID: 99, pan: true, zoom: true));
            var tvPlay = events.Last(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            Assert.Equal(0.5f, (float)tvPlay.GetType().GetProperty("pitchScale")?.GetValue(tvPlay)!, 3);
            var tvVoice = (long)tvPlay.GetType().GetProperty("voice")?.GetValue(tvPlay)!;

            events.Clear();
            Assert.True(audio.Play("tv_turn_off", ownerID: 99));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "stop" && (long)e.GetType().GetProperty("voice")?.GetValue(e)! == tvVoice);

            events.Clear();
            audio.End(tvVoice);
            Assert.Empty(events);

            audio.SetVolume("FX", 0.3f);
            audio.SetVolume("MUSIC", 0.7f);
            audio.SetVolume("VOX", 0.2f);
            audio.SetVolume("AMBIENCE", 0.9f);

            var audioJsonPath = Path.Combine(profileDir, "Settings", "audio.json");
            Assert.True(File.Exists(audioJsonPath));
            using (var doc = JsonDocument.Parse(File.ReadAllText(audioJsonPath)))
            {
                Assert.Equal(1, doc.RootElement.GetProperty("schemaVersion").GetInt32());
                var vols = doc.RootElement.GetProperty("volumes");
                Assert.Equal(0.3f, vols[0].GetSingle(), 3);
                Assert.Equal(0.7f, vols[1].GetSingle(), 3);
                Assert.Equal(0.2f, vols[2].GetSingle(), 3);
                Assert.Equal(0.9f, vols[3].GetSingle(), 3);
            }

            using var reloaded = new HitAudioRuntime(Path.Combine(tempDir, "session2"), profileDir, _ => { }, gameDir);
            dynamic state = reloaded.State();
            var reloadedVols = (Dictionary<string, float>)state.volumes;
            Assert.Equal(0.3f, reloadedVols["FX"], 3);
            Assert.Equal(0.7f, reloadedVols["MUSIC"], 3);
            Assert.Equal(0.2f, reloadedVols["VOX"], 3);
            Assert.Equal(0.9f, reloadedVols["AMBIENCE"], 3);

            File.WriteAllText(audioJsonPath, "{not valid json");
            using var fallback = new HitAudioRuntime(Path.Combine(tempDir, "session3"), profileDir, _ => { }, gameDir);
            dynamic fbState = fallback.State();
            var fbVols = (Dictionary<string, float>)fbState.volumes;
            Assert.Equal(0.8f, fbVols["FX"], 3);
            Assert.Equal(0.8f, fbVols["MUSIC"], 3);
            Assert.Equal(0.8f, fbVols["VOX"], 3);
            Assert.Equal(1.0f, fbVols["AMBIENCE"], 3);

            using var gameProfileGuard = new HitAudioRuntime(Path.Combine(tempDir, "session4"), gameDir, _ => { }, gameDir);
            gameProfileGuard.SetVolume("FX", 0.4f);
            Assert.False(File.Exists(Path.Combine(gameDir, "Settings", "audio.json")));
        }
        finally
        {
            try { Directory.Delete(tempDir, true); } catch { }
        }
    }

    [Fact]
    public void SoundBank_TvSuperstarPrefixMatching_ResolvesNonLoopingPlaylists()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null) return;

        var tempDir = Path.Combine(Path.GetTempPath(), $"sims-tv-ss-{Guid.NewGuid():N}");
        try
        {
            using var bank = new SoundBank(gameDir, tempDir);
            foreach (var cue in new[] { "tv_superstar_animal", "tv_superstar_animal_norm", "tv_superstar_entertainment", "tv_superstar_news", "tv_superstar_sports" })
            {
                var res = bank.Resolve(cue);
                Assert.NotNull(res);
                Assert.Equal("FX", res.Group);
                Assert.False(res.IsLoop);
                Assert.True(res.IsPlaylist);
            }
        }
        finally
        {
            try { Directory.Delete(tempDir, true); } catch { }
        }
    }

    [Fact]
    public void HitVm_ModuleScoping_IsolatesCollidingPatchesAndGlobalHitLists_AndRejectsNullEntryOffset()
    {
        byte[] BuildChooseAndPlayBytecode(int loops)
        {
            var buf = new List<byte>();
            if (loops > 0)
            {
                buf.AddRange([OpLoadB, HitReg.V1, 0]);
                buf.AddRange([OpLoadB, HitReg.V2, (byte)loops]);
                int loopOffset = buf.Count;
                buf.AddRange([OpInc, HitReg.V1]);
                buf.AddRange([OpCmp, HitReg.V1, HitReg.V2]);
                buf.Add(OpIfLt); EmitInt32(buf, 2);
                _ = loopOffset;
            }
            buf.AddRange([OpLoadL, HitReg.V3]); EmitInt32(buf, 500);
            buf.AddRange([OpSmartSetList, HitReg.V3]);
            buf.AddRange([OpSmartChoose, HitReg.Patch]);
            buf.AddRange([OpNoteOn, 0]);
            buf.Add(OpWaitSamp);
            buf.Add(OpEnd);
            return buf.ToArray();
        }

        var hitA = BuildChooseAndPlayBytecode(loops: 60);
        var modA = new HitBankModule("modA", hitA);
        modA.TrackDataOffsets[1] = 0;
        modA.TrackDataOffsets[2] = 6;
        modA.Patches[6400] = new HotPatchDef(6400, "PatchA", "a_6400.wav", false);
        modA.GlobalHitLists[500] = [6400];
        var trkA = new HotTrackDef(6403, "TrackA", "FX", 1024, 10, 20, 6400, "@1", 0, false, true, modA, modA);
        modA.Tracks[6403] = trkA;

        var hitB = BuildChooseAndPlayBytecode(loops: 0);
        var modB = new HitBankModule("modB", hitB);
        modB.TrackDataOffsets[1] = 0;
        modB.Patches[6400] = new HotPatchDef(6400, "PatchB", "b_6400.wav", false);
        modB.GlobalHitLists[500] = [6400];
        var trkB = new HotTrackDef(6403, "TrackB", "FX", 1024, 10, 20, 6400, "@1", 0, false, true, modB, modB);
        modB.Tracks[6403] = trkB;

        var nullOffsetTrack = new HotTrackDef(9999, "NullTrack", "FX", 1024, 10, 20, 6400, "@missing", null, false, true, modA, modA);

        var vm = new HitVm([modA, modB]);

        Assert.Null(vm.StartTrack(nullOffsetTrack, arg1: 1));
        Assert.Empty(vm.DrainCommands());

        var tA = vm.StartTrack(trkA, arg1: 10)!;
        Assert.NotNull(tA);
        Assert.Empty(vm.DrainCommands());
        Assert.True(tA.WaitUntilTick > vm.CurrentTick);
        vm.StepTicks(1);
        var startA = Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        Assert.Equal(6400, startA.PatchId);
        Assert.Same(modA, startA.Bank);

        var tB = vm.StartTrack(trkB, arg1: 20)!;
        Assert.NotNull(tB);
        var startB = Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        Assert.Equal(6400, startB.PatchId);
        Assert.Same(modB, startB.Bank);
    }

    [Fact]
    public void HitSmartList_Remove_DrainsUsedDownToCrush()
    {
        var list = new HitSmartList([1, 2, 3, 4]);
        Assert.Equal(2, list.Crush);
        var rng = new Random(123);

        int? c1 = list.Choose(rng);
        int? c2 = list.Choose(rng);
        Assert.NotNull(c1);
        Assert.NotNull(c2);
        Assert.Equal(2, list.Available.Count);
        Assert.Equal(2, list.Used.Count);

        foreach (int remaining in list.Available.ToArray())
        {
            list.Remove(remaining);
        }

        Assert.Equal(2, list.TotalCount);
        Assert.Equal(1, list.Crush);
        Assert.True(list.Used.Count <= list.Crush, $"Expected Used.Count ({list.Used.Count}) <= Crush ({list.Crush}).");
        Assert.Single(list.Used);
        Assert.Single(list.Available);
    }

    [Fact]
    public void SoundBank_RealAssets_IsolatesPlantCarnivoreVsSc4Drinks_VoxHitLists_AndCrossModuleGenericTracks()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null) return;

        var tempDir = Path.Combine(Path.GetTempPath(), $"sims-m1-r2-assets-{Guid.NewGuid():N}");
        var profileDir = Path.Combine(tempDir, "profile");
        Directory.CreateDirectory(profileDir);
        try
        {
            var events = new List<object>();
            using var bank = new SoundBank(gameDir, Path.Combine(tempDir, "session-bank"));
            using var audio = new HitAudioRuntime(Path.Combine(tempDir, "session-rt"), profileDir, msg =>
            {
                if (msg is not null) events.Add(msg);
            }, gameDir);

            var cplantTrack = bank.GetTrackForEvent("cplant");
            var sc4Track = bank.GetTrackForEvent("sc_wait_anx_vox");
            if (cplantTrack != null && sc4Track != null)
            {
                var cplantPatch = bank.ResolvePatchById(6400, "FX", false, true, trackId: cplantTrack.TrackId, bank: cplantTrack.Bank);
                Assert.NotNull(cplantPatch);
                Assert.Contains("cplant1", cplantPatch.RelativePath, StringComparison.OrdinalIgnoreCase);

                var sc4Patch = bank.ResolvePatchById(6400, "VOX", false, true, trackId: sc4Track.TrackId, bank: sc4Track.Bank);
                Assert.NotNull(sc4Patch);
                Assert.Contains("vox_confused_huhk17", sc4Patch.RelativePath, StringComparison.OrdinalIgnoreCase);
            }

            (string Cue, char Demo)[] voxCases =
            [
                ("vox_complimentee_reject", 'k'),
                ("Vox_Dancee_Decline", 'm'),
                ("Vox_Dancee_Decline", 'f'),
                ("vox_entertainee_boo", 'm'),
                ("vox_entertainee_boo", 'f'),
                ("vox_entertainee_laugh", 'f'),
                ("vox_juggler_tada", 'm')
            ];
            short owner = 100;
            foreach (var (cue, demo) in voxCases)
            {
                events.Clear();
                owner++;
                Assert.True(audio.PlayForSimulationObject(cue, owner, pan: true, zoom: true, voiceTypeOverride: demo), $"Expected '{cue}' ({demo}) to play");
                var play = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
                var file = play.GetType().GetProperty("file")?.GetValue(play)?.ToString();
                Assert.False(string.IsNullOrEmpty(file));
                audio.RemoveOwner(owner);
            }

            events.Clear();
            Assert.True(audio.PlayForSimulationObject("stereo_rock", ownerID: 201, pan: true, zoom: true));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            audio.RemoveOwner(201);

            events.Clear();
            Assert.True(audio.PlayForSimulationObject("tv_action_cheap", ownerID: 202, pan: true, zoom: true));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            audio.RemoveOwner(202);

            foreach (var evName in new[] { "santa_appear", "bull_start", "shd_Vn01" })
            {
                var trk = bank.GetTrackForEvent(evName);
                if (trk is null) continue;
                Assert.True(trk.EntryOffset is > 0, $"Expected {evName} EntryOffset > 0");
                Assert.NotNull(trk.CodeBank);

                events.Clear();
                Assert.True(audio.PlayForSimulationObject(evName, ownerID: 301, pan: true, zoom: true));
                Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
                audio.RemoveOwner(301);
            }
        }
        finally
        {
            try { Directory.Delete(tempDir, true); } catch { }
        }
    }

    [Fact]
    public void HitAudioRuntime_DirectTurnOnTv_ModeDuckingOnStart_MultiSyllableVox_AndSpeed3Vox()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null) return;

        var tempDir = Path.Combine(Path.GetTempPath(), $"sims-m1-r2-rt-{Guid.NewGuid():N}");
        var profileDir = Path.Combine(tempDir, "profile");
        Directory.CreateDirectory(profileDir);
        try
        {
            var events = new List<object>();
            using var audio = new HitAudioRuntime(Path.Combine(tempDir, "session"), profileDir, msg =>
            {
                if (msg is not null) events.Add(msg);
            }, gameDir);

            Assert.True(audio.PlayForSimulationObject("stereo_classical", ownerID: 42, pan: true, zoom: true));
            var stereo1 = (long)events.Last(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play")
                .GetType().GetProperty("voice")?.GetValue(events.Last(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play"))!;

            events.Clear();
            Assert.True(audio.PlayForSimulationObject("stereo_rock", ownerID: 42, pan: true, zoom: true));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "stop" && (long)e.GetType().GetProperty("voice")?.GetValue(e)! == stereo1);
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            audio.RemoveOwner(42);

            events.Clear();
            Assert.True(audio.PlayForSimulationObject("tv_action_cheap", ownerID: 43, pan: true, zoom: true));
            var tv1 = (long)events.Last(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play")
                .GetType().GetProperty("voice")?.GetValue(events.Last(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play"))!;

            events.Clear();
            Assert.True(audio.PlayForSimulationObject("tv_romance_cheap", ownerID: 43, pan: true, zoom: true));
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "stop" && (long)e.GetType().GetProperty("voice")?.GetValue(e)! == tv1);
            Assert.Contains(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            audio.RemoveOwner(43);

            events.Clear();
            Assert.True(audio.Play("sting_kiss_polite", -1));
            events.Clear();
            Assert.True(audio.Play("bkground_buy1"));
            var buyPlay = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            float buyVol = (float)buyPlay.GetType().GetProperty("volume")?.GetValue(buyPlay)!;
            Assert.Equal(0.4f, buyVol, 3);
            audio.Reset();

            events.Clear();
            Assert.True(audio.PlayForSimulationObject("hottub_getin_vox", ownerID: 55, pan: true, zoom: true, voiceTypeOverride: 'f'));
            var firstPlay = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            long vId = (long)firstPlay.GetType().GetProperty("voice")?.GetValue(firstPlay)!;
            string firstFile = firstPlay.GetType().GetProperty("file")?.GetValue(firstPlay)?.ToString()!;
            Assert.Contains("f", Path.GetFileNameWithoutExtension(firstFile), StringComparison.OrdinalIgnoreCase);

            events.Clear();
            audio.End(vId);
            for (int i = 0; i < 60 && !events.Any(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play"); i++)
            {
                Thread.Sleep(25);
                audio.Tick();
            }
            var nextSyllable = events.LastOrDefault(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            Assert.NotNull(nextSyllable);
            string nextFile = nextSyllable.GetType().GetProperty("file")?.GetValue(nextSyllable)?.ToString()!;
            Assert.Contains("f", Path.GetFileNameWithoutExtension(nextFile), StringComparison.OrdinalIgnoreCase);
            audio.RemoveOwner(55);

            audio.SuppressActiveDuplicates = true;
            audio.SetSimulationSpeed(3);
            events.Clear();
            Assert.True(audio.PlayForSimulationObject("vox_laugh_giggle", ownerID: 71, pan: true, zoom: true, voiceTypeOverride: 'm'));
            Assert.True(audio.PlayForSimulationObject("vox_laugh_giggle", ownerID: 72, pan: true, zoom: true, voiceTypeOverride: 'f'));
            Assert.Equal(2, events.Count(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play"));
            Assert.Equal(2, audio.ActiveVoiceCount);
        }
        finally
        {
            try { Directory.Delete(tempDir, true); } catch { }
        }
    }

    [Fact]
    public void AudioMixer_Set_PurgesStaleEndedOnReuse_And_EvictIfFull_SkipsActiveOverwrite()
    {
        var mixer = new AudioMixer();
        mixer.Set(10, new AudioMixer.Voice(new float[8]) { Loop = false });
        mixer.MixAndPut(nint.Zero, 16);
        Assert.Equal(0, mixer.Count);

        mixer.Set(10, new AudioMixer.Voice(new float[200]) { Loop = false });
        Assert.Empty(mixer.TakeEnded());
        Assert.Equal(1, mixer.Count);

        mixer.Clear();
        for (long i = 1; i <= 256; i++)
        {
            mixer.Set(i, new AudioMixer.Voice(new float[8]) { Loop = false });
        }
        Assert.Equal(256, mixer.Count);
        Assert.Null(mixer.EvictIfFull(256, protectedVoice: 1, incomingVoice: 42));
        Assert.Equal(256, mixer.Count);

        Assert.Equal(2L, mixer.EvictIfFull(256, protectedVoice: 1, incomingVoice: 257));
        Assert.Equal(255, mixer.Count);
    }

    [Fact]
    public void UtkAudio_TruncatedUtm0_ThrowsWithoutFabricatingZeros()
    {
        byte[] headerOnly = new byte[32];
        headerOnly[0] = (byte)'U';
        headerOnly[1] = (byte)'T';
        headerOnly[2] = (byte)'M';
        headerOnly[3] = (byte)'0';
        BinaryPrimitives.WriteUInt32LittleEndian(headerOnly.AsSpan(4, 4), 88200);
        BinaryPrimitives.WriteUInt16LittleEndian(headerOnly.AsSpan(14, 2), 1);
        BinaryPrimitives.WriteUInt32LittleEndian(headerOnly.AsSpan(16, 4), 22050);

        Assert.Throws<ArgumentException>(() => UtkAudio.Decode(headerOnly));

        byte[] truncatedPayload = new byte[34];
        headerOnly.CopyTo(truncatedPayload, 0);
        truncatedPayload[32] = 0x55;
        truncatedPayload[33] = 0xAA;

        Assert.Throws<EndOfStreamException>(() => UtkAudio.Decode(truncatedPayload));
    }

    private static byte[] BuildSyntheticFarArchive(params (string Name, byte[] Data)[] entries)
    {
        using var ms = new MemoryStream();
        ms.Write("FAR!byAZ"u8);
        Span<byte> tmp = stackalloc byte[4];
        BinaryPrimitives.WriteUInt32LittleEndian(tmp, 1);
        ms.Write(tmp);
        ms.Write(stackalloc byte[4]);

        var offsets = new int[entries.Length];
        for (int i = 0; i < entries.Length; i++)
        {
            offsets[i] = (int)ms.Position;
            ms.Write(entries[i].Data);
        }

        uint manifestOffset = (uint)ms.Position;
        BinaryPrimitives.WriteUInt32LittleEndian(tmp, (uint)entries.Length);
        ms.Write(tmp);
        for (int i = 0; i < entries.Length; i++)
        {
            var nameBytes = Encoding.Latin1.GetBytes(entries[i].Name);
            BinaryPrimitives.WriteUInt32LittleEndian(tmp, (uint)entries[i].Data.Length);
            ms.Write(tmp);
            BinaryPrimitives.WriteUInt32LittleEndian(tmp, (uint)entries[i].Data.Length);
            ms.Write(tmp);
            BinaryPrimitives.WriteUInt32LittleEndian(tmp, (uint)offsets[i]);
            ms.Write(tmp);
            BinaryPrimitives.WriteUInt32LittleEndian(tmp, (uint)nameBytes.Length);
            ms.Write(tmp);
            ms.Write(nameBytes);
        }

        ms.Position = 12;
        BinaryPrimitives.WriteUInt32LittleEndian(tmp, manifestOffset);
        ms.Write(tmp);
        return ms.ToArray();
    }

    [Fact]
    public void HitVm_OutOfRangeRegisters_KillThreadWithoutExecutingTrailingNoteOn_AndAllowLiteralZeroOperands()
    {
        var invalidRegs = new byte[] { 0x00, 0x80 };
        var cases = new List<(string Label, byte[] Body)>();

        foreach (byte bad in invalidRegs)
        {
            cases.Add(($"loadl_0x{bad:X2}", BuildBytes(b =>
            {
                b.AddRange([OpLoadL, bad]);
                EmitInt32(b, 1);
            }).ToArray()));
            cases.Add(($"set_dest_0x{bad:X2}", [OpSet, bad, HitReg.V1]));
            cases.Add(($"set_src_0x{bad:X2}", [OpSet, HitReg.V1, bad]));
            cases.Add(($"wait_0x{bad:X2}", [OpWait, bad]));
            cases.Add(($"callback_r1_0x{bad:X2}", [OpCallback, bad, HitReg.V1]));
            cases.Add(($"callback_r2_0x{bad:X2}", [OpCallback, HitReg.V1, bad]));
            cases.Add(($"printreg_0x{bad:X2}", [OpPrintReg, bad]));
            cases.Add(($"get_var_dest_0x{bad:X2}", [OpGetVar, bad, HitReg.V1]));
            cases.Add(($"get_var_src_0x{bad:X2}", [OpGetVar, HitReg.V1, bad]));
            cases.Add(($"get_var_indirect_0x{bad:X2}", BuildBytes(b =>
            {
                b.AddRange([OpLoadL, HitReg.V2]);
                EmitInt32(b, bad);
                b.AddRange([OpGetVar, HitReg.V1, HitReg.V2]);
            }).ToArray()));
        }

        foreach (var (label, body) in cases)
        {
            var hit = new List<byte>(body);
            hit.AddRange([OpNoteOn, 2, OpEnd]);

            var mod = new HitBankModule($"bad_{label}", hit.ToArray());
            mod.TrackDataOffsets[100] = 0;
            mod.Patches[2] = new HotPatchDef(2, "Pch2", "two.wav", false);
            var trk = new HotTrackDef(10, "TrkBad", "FX", 1024, 10, 20, 0, "@100", 0, false, true, mod);
            mod.Tracks[10] = trk;

            var vm = new HitVm([mod], rng: new Random(1));
            var thread = vm.StartTrack(trk, arg1: 1);
            Assert.NotNull(thread);
            Assert.True(thread.Killed, $"{label} should kill the thread.");
            Assert.Equal(0, vm.ActiveThreadCount);
            Assert.Null(vm.GetThread(thread.InstanceId));
            Assert.Empty(vm.DrainCommands());
        }

        var validHit = new List<byte>();
        validHit.AddRange([OpLoadB, HitReg.V1, 0x00]);
        validHit.Add(OpLoadL); validHit.Add(HitReg.Patch); EmitInt32(validHit, 50);
        validHit.AddRange([OpNoteOn, 0x00]);
        validHit.Add(OpEnd);

        var validMod = new HitBankModule("valid_lit_zero", validHit.ToArray());
        validMod.TrackDataOffsets[200] = 0;
        validMod.Patches[50] = new HotPatchDef(50, "Pch50", "fifty.wav", false);
        var validTrk = new HotTrackDef(20, "TrkValid", "FX", 1024, 10, 20, 0, "@200", 0, false, true, validMod);
        validMod.Tracks[20] = validTrk;

        var validVm = new HitVm([validMod], rng: new Random(1));
        var validThread = validVm.StartTrack(validTrk, arg1: 1);
        Assert.NotNull(validThread);
        Assert.Equal(0, validThread.Registers[HitReg.V1]);
        var start = Assert.Single(validVm.DrainCommands().OfType<HitStartVoiceCommand>());
        Assert.Equal(50, start.PatchId);
    }

    [Fact]
    public void HitVm_StepThreadFade_OutOfRangeFadeVar_KillsThreadCleanly()
    {
        foreach (byte badReg in new byte[] { 0x00, 0x80 })
        {
            var hit = BuildBytes(b =>
            {
                b.AddRange([OpLoadL, HitReg.V1]); EmitInt32(b, badReg);
                b.AddRange([OpSet, HitReg.FadeVar, HitReg.V1]);
                b.AddRange([OpLoadB, HitReg.FadeSpeed, 10]);
                b.AddRange([OpLoadB, HitReg.FadeDest, 50]);
                b.AddRange([OpLoadB, HitReg.FadeOn, 1]);
                b.AddRange([OpLoadB, HitReg.V2, 5]);
                b.AddRange([OpWait, HitReg.V2]);
                b.Add(OpEnd);
            });

            var mod = new HitBankModule("fade_bad", hit.ToArray());
            mod.TrackDataOffsets[1] = 0;
            var trk = new HotTrackDef(1, "TrkFadeBad", "FX", 1024, 10, 20, 0, "@1", 0, false, true, mod);
            mod.Tracks[1] = trk;

            var vm = new HitVm([mod], rng: new Random(1));
            var thread = vm.StartTrack(trk);
            Assert.NotNull(thread);
            Assert.False(thread.Killed);

            vm.StepTicks(1);
            Assert.True(thread.Killed);
            Assert.Equal(0, vm.ActiveThreadCount);
        }
    }

    [Fact]
    public void AmbienceSequencer_FinalNonRandNote_PlaysAndWrapsOnNextBeat()
    {
        var tempDir = Path.Combine(Path.GetTempPath(), $"sims-m1-r3-fsc-{Guid.NewGuid():N}");
        var soundData = Path.Combine(tempDir, "SoundData");
        Directory.CreateDirectory(soundData);
        try
        {
            var wavBytes = HitAudioRuntime.CreateWav(22050, 1, 16, new byte[2205 * 2]);
            var fscText =
                "FSC V1.0\n" +
                "HEAD\t1024\t1\t0\t8\t1\t2\t120\t4\t0\t0\t0\t0\t0\t0\n" +
                "cells\n" +
                "0\t1024\t0\t512\t0\t0\t0\t0\t0\t0\t1\t1\t0\t20\t0\t0\t0\t0\t0\tamb_bed.wav\n" +
                "1\t1024\t0\t512\t0\t0\t0\t0\t0\t0\t1\t0\t0\t20\t0\t0\t0\t0\t0\tamb_final.wav\n";
            var fscBytes = Encoding.UTF8.GetBytes(fscText);

            File.WriteAllBytes(
                Path.Combine(soundData, "SoundData.far"),
                BuildSyntheticFarArchive(
                    ("Outdoors/sim_amb.fsc", fscBytes),
                    ("amb_bed.wav", wavBytes),
                    ("amb_final.wav", wavBytes)));

            var playedFiles = new List<string>();
            using var audio = new HitAudioRuntime(Path.Combine(tempDir, "session"), Path.Combine(tempDir, "profile"), msg =>
            {
                var cmd = msg.GetType().GetProperty("command")?.GetValue(msg)?.ToString();
                if (cmd == "play")
                {
                    playedFiles.Add(msg.GetType().GetProperty("file")?.GetValue(msg)?.ToString() ?? "");
                }
            }, tempDir);

            Assert.True(audio.Play("setambience_backyard", -1));
            Assert.Single(playedFiles);
            Assert.Contains("amb_bed", playedFiles[0], StringComparison.OrdinalIgnoreCase);

            var seqField = typeof(HitAudioRuntime).GetField("ambience", BindingFlags.Instance | BindingFlags.NonPublic)!;
            var sequencer = (HitAudioRuntime.AmbienceSequencer)seqField.GetValue(audio)!;

            playedFiles.Clear();
            sequencer.NextBeat();
            sequencer.NextBeat();
            sequencer.NextBeat();

            Assert.Equal(3, playedFiles.Count);
            Assert.Contains("amb_bed", playedFiles[0], StringComparison.OrdinalIgnoreCase);
            Assert.Contains("amb_final", playedFiles[1], StringComparison.OrdinalIgnoreCase);
            Assert.Contains("amb_bed", playedFiles[2], StringComparison.OrdinalIgnoreCase);
        }
        finally
        {
            try { Directory.Delete(tempDir, true); } catch { }
        }
    }

    [Fact]
    public void HitAudioRuntime_KillAll_ClearsOrphanedThreadStateAndDuckPriority()
    {
        var gameDir = LocateGameDirectory();
        if (gameDir is null) return;

        var tempDir = Path.Combine(Path.GetTempPath(), $"sims-m1-r3-killall-{Guid.NewGuid():N}");
        Directory.CreateDirectory(tempDir);
        try
        {
            var events = new List<object>();
            using var audio = new HitAudioRuntime(Path.Combine(tempDir, "session"), Path.Combine(tempDir, "profile"), msg =>
            {
                if (msg is not null) events.Add(msg);
            }, gameDir);

            Assert.True(audio.PlayForSimulationObject("hottub_getin_vox", ownerID: 55, pan: true, zoom: true, voiceTypeOverride: 'f'));
            var firstPlay = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            long vId = (long)firstPlay.GetType().GetProperty("voice")?.GetValue(firstPlay)!;
            audio.End(vId);

            Assert.True(audio.Play("sting_kiss_polite", -1));

            Assert.True(audio.Play("kill_all"));
            Assert.Equal(0, audio.ActiveVoiceCount);

            var flags = BindingFlags.Instance | BindingFlags.NonPublic;
            var threadToVoice = (System.Collections.IDictionary)typeof(HitAudioRuntime).GetField("threadToVoice", flags)!.GetValue(audio)!;
            var voiceToThread = (System.Collections.IDictionary)typeof(HitAudioRuntime).GetField("voiceToThread", flags)!.GetValue(audio)!;
            var pendingCtx = (System.Collections.IDictionary)typeof(HitAudioRuntime).GetField("pendingThreadContext", flags)!.GetValue(audio)!;
            var demoOverrides = (System.Collections.IDictionary)typeof(HitAudioRuntime).GetField("threadDemographicOverrides", flags)!.GetValue(audio)!;
            int lastDuck = (int)typeof(HitAudioRuntime).GetField("lastVmDuckPriority", flags)!.GetValue(audio)!;

            Assert.Empty(threadToVoice);
            Assert.Empty(voiceToThread);
            Assert.Empty(pendingCtx);
            Assert.Empty(demoOverrides);
            Assert.Equal(0, lastDuck);

            events.Clear();
            Assert.True(audio.Play("bkground_buy1"));
            var buyPlay = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            float buyVol = (float)buyPlay.GetType().GetProperty("volume")?.GetValue(buyPlay)!;
            Assert.Equal(0.8f, buyVol, 3);
        }
        finally
        {
            try { Directory.Delete(tempDir, true); } catch { }
        }
    }

    [Fact]
    public void HitVm_SimulationPause_FreezesSimThreadsPreservesTimersAndDefersVoiceEndUntilUnpause()
    {
        var hit = new List<byte>();
        var tkdOffsets = new Dictionary<int, int>();

        tkdOffsets[1] = hit.Count;
        hit.AddRange([OpNoteOn, 10]);
        hit.Add(OpWaitSamp);
        hit.AddRange([OpLoadB, HitReg.V1, 4]);
        hit.AddRange([OpWait, HitReg.V1]);
        hit.Add(OpLoadL); hit.Add(HitReg.Patch); EmitInt32(hit, 11);
        hit.AddRange([OpLoadB, HitReg.V2, 3]);
        hit.AddRange([OpNote, HitReg.V2, HitReg.V2]);
        hit.AddRange([OpLoadB, HitReg.V3, 10]);
        hit.AddRange([OpWait, HitReg.V3]);
        hit.Add(OpEnd);

        tkdOffsets[2] = hit.Count;
        hit.AddRange([OpNoteOn, 20]);
        hit.AddRange([OpLoadB, HitReg.V1, 2]);
        hit.AddRange([OpWait, HitReg.V1]);
        hit.AddRange([OpNoteOn, 21]);
        hit.Add(OpEnd);

        var mod = new HitBankModule("simpause", hit.ToArray());
        foreach (var (k, v) in tkdOffsets) mod.TrackDataOffsets[k] = v;
        mod.Patches[10] = new HotPatchDef(10, "PchSim1", "sim1.wav", false);
        mod.Patches[11] = new HotPatchDef(11, "PchSim2", "sim2.wav", false);
        mod.Patches[20] = new HotPatchDef(20, "PchUi1", "ui1.wav", false);
        mod.Patches[21] = new HotPatchDef(21, "PchUi2", "ui2.wav", false);
        var trkSim = new HotTrackDef(1, "TrkSim", "VOX", 1024, 10, 20, 0, "@1", tkdOffsets[1], false, true, mod);
        var trkUi = new HotTrackDef(2, "TrkUi", "FX", 1024, 10, 20, 0, "@2", tkdOffsets[2], false, false, mod);
        mod.Tracks[1] = trkSim;
        mod.Tracks[2] = trkUi;

        var vm = new HitVm([mod], rng: new Random(1));
        var simThread = vm.StartTrack(trkSim, arg1: 55)!;
        var simStart1 = Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        Assert.Equal(10, simStart1.PatchId);
        vm.BindVoice(simThread.InstanceId, 1001);

        vm.SetSimulationPaused(t => t.VoiceOwnerId > 0, true);
        Assert.True(simThread.PausedBySimulation);

        var uiThread = vm.StartTrack(trkUi, arg1: -4)!;
        var uiStart1 = Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        Assert.Equal(20, uiStart1.PatchId);
        vm.BindVoice(uiThread.InstanceId, 2001);

        Assert.True(vm.OnVoiceEnded(1001));
        Assert.Empty(vm.DrainCommands());
        Assert.False(simThread.WaitingForSample);

        vm.StepTicks(4);
        var uiStart2 = Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        Assert.Equal(21, uiStart2.PatchId);
        Assert.Null(vm.GetThread(uiThread.InstanceId));
        Assert.NotNull(vm.GetThread(simThread.InstanceId));

        vm.SetSimulationPaused(t => t.VoiceOwnerId > 0, false);
        Assert.False(simThread.PausedBySimulation);

        vm.StepTicks(1);
        Assert.Empty(vm.DrainCommands());

        vm.StepTicks(3);
        Assert.Empty(vm.DrainCommands());

        vm.StepTicks(1);
        var simStart2 = Assert.Single(vm.DrainCommands().OfType<HitStartVoiceCommand>());
        Assert.Equal(11, simStart2.PatchId);
        vm.BindVoice(simThread.InstanceId, 1002);

        vm.SetSimulationPaused(t => t.VoiceOwnerId > 0, true);
        vm.StepTicks(10);
        Assert.Empty(vm.DrainCommands());

        vm.SetSimulationPaused(t => t.VoiceOwnerId > 0, false);
        vm.StepTicks(2);
        Assert.Empty(vm.DrainCommands());

        vm.StepTicks(1);
        var stopCmd = Assert.Single(vm.DrainCommands().OfType<HitStopVoiceCommand>());
        Assert.Equal(1002, stopCmd.VoiceId);
    }

    [Fact]
    public void HitAudioRuntime_SimulationPause_StopsMultiSyllableVoxContinuationAndPausesNewSimVoices()
    {
        var mockTemp = Path.Combine(Path.GetTempPath(), $"sims-sim-pause-mock-{Guid.NewGuid():N}");
        Directory.CreateDirectory(mockTemp);
        try
        {
            var mockEvents = new List<object>();
            using var mockAudio = new HitAudioRuntime(Path.Combine(mockTemp, "session"), Path.Combine(mockTemp, "profile"), msg =>
            {
                if (msg is not null) mockEvents.Add(msg);
            }, game: null);

            mockAudio.SetSimulationPaused(true);
            Assert.True(mockAudio.PlayForSimulationObject("vox_talk_neutral", ownerID: 42, pan: false, zoom: false, voiceTypeOverride: 'm'));
            Assert.Equal(2, mockEvents.Count);
            Assert.Equal("play", mockEvents[0].GetType().GetProperty("command")?.GetValue(mockEvents[0])?.ToString());
            long vId = Convert.ToInt64(mockEvents[0].GetType().GetProperty("voice")?.GetValue(mockEvents[0]));
            Assert.Equal("pause", mockEvents[1].GetType().GetProperty("command")?.GetValue(mockEvents[1])?.ToString());
            Assert.Equal(vId, Convert.ToInt64(mockEvents[1].GetType().GetProperty("voice")?.GetValue(mockEvents[1])));

            mockEvents.Clear();
            mockAudio.SetSimulationPaused(false);
            var resume = Assert.Single(mockEvents);
            Assert.Equal("resume", resume.GetType().GetProperty("command")?.GetValue(resume)?.ToString());
            Assert.Equal(vId, Convert.ToInt64(resume.GetType().GetProperty("voice")?.GetValue(resume)));
        }
        finally
        {
            try { Directory.Delete(mockTemp, true); } catch { }
        }

        var gameDir = LocateGameDirectory();
        if (gameDir is null) return;

        var tempDir = Path.Combine(Path.GetTempPath(), $"sims-sim-pause-real-{Guid.NewGuid():N}");
        Directory.CreateDirectory(tempDir);
        try
        {
            var events = new List<object>();
            using var audio = new HitAudioRuntime(Path.Combine(tempDir, "session"), Path.Combine(tempDir, "profile"), msg =>
            {
                if (msg is not null) events.Add(msg);
            }, gameDir);

            Assert.True(audio.PlayForSimulationObject("hottub_getin_vox", ownerID: 55, pan: true, zoom: true, voiceTypeOverride: 'f'));
            var firstPlay = Assert.Single(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play");
            long firstVoiceId = (long)firstPlay.GetType().GetProperty("voice")?.GetValue(firstPlay)!;

            events.Clear();
            audio.SetSimulationPaused(true);
            Assert.Contains(events, e =>
                e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "pause" &&
                (long)e.GetType().GetProperty("voice")?.GetValue(e)! == firstVoiceId);

            events.Clear();
            audio.End(firstVoiceId);
            for (int i = 0; i < 10; i++)
            {
                Thread.Sleep(15);
                audio.Tick();
            }
            Assert.DoesNotContain(events, e =>
                e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play" &&
                Convert.ToInt32(e.GetType().GetProperty("ownerID")?.GetValue(e)) == 55);

            events.Clear();
            Assert.True(audio.Play("ui_click", -4));
            Assert.True(audio.Play("bkground_buy1"));
            Assert.Equal(2, events.Count(e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play"));
            Assert.DoesNotContain(events, e => e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "pause");

            events.Clear();
            audio.SetSimulationPaused(false);
            for (int i = 0; i < 60 && !events.Any(e =>
                e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play" &&
                Convert.ToInt32(e.GetType().GetProperty("ownerID")?.GetValue(e)) == 55); i++)
            {
                Thread.Sleep(25);
                audio.Tick();
            }
            Assert.Contains(events, e =>
                e.GetType().GetProperty("command")?.GetValue(e)?.ToString() == "play" &&
                Convert.ToInt32(e.GetType().GetProperty("ownerID")?.GetValue(e)) == 55);
            audio.RemoveOwner(55);
        }
        finally
        {
            try { Directory.Delete(tempDir, true); } catch { }
        }
    }
}
