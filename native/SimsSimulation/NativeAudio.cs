using System.Buffers.Binary;
using System.Diagnostics;
using System.Security.Cryptography;
using FSO.Content.TS1;
using FSO.Files.HIT;
using FSO.HIT;
using FSO.SimAntics;
using Microsoft.Xna.Framework.Audio;

internal sealed class NativeAudio : IDisposable
{
    internal const short NeighborhoodOwnerID = -25;
    private readonly string directory;
    private readonly string settingsPath;
    private readonly Action<object> output;
    private readonly Dictionary<string, HITAudioClip> clips = new(StringComparer.OrdinalIgnoreCase);
    private readonly Dictionary<long, Voice> voices = [];
    private readonly HashSet<string> failedResources = new(StringComparer.OrdinalIgnoreCase);
    private readonly float[] volumes = [1, 1, 1, 1];
    private long sequence;
    private readonly Queue<(string Name, uint PC, byte Opcode, int[] Registers)> trace = new();
    public bool Enabled { get; private set; }

    public NativeAudio(string directory, string profileDirectory, Action<object> output)
    {
        this.directory = directory;
        this.output = output;
        settingsPath = Path.Combine(profileDirectory, "Settings", "audio.json");
        Directory.CreateDirectory(directory);
        LoadVolumes();
        Configure();
    }

    private void LoadVolumes()
    {
        if (!File.Exists(settingsPath)) return;
        try
        {
            using var document = System.Text.Json.JsonDocument.Parse(File.ReadAllBytes(settingsPath));
            var root = document.RootElement;
            if (root.ValueKind != System.Text.Json.JsonValueKind.Object ||
                !root.TryGetProperty("schemaVersion", out var schema) || !schema.TryGetInt32(out var version) || version != 1 ||
                !root.TryGetProperty("volumes", out var values) || values.ValueKind != System.Text.Json.JsonValueKind.Array || values.GetArrayLength() != volumes.Length) return;
            var restored = new float[volumes.Length];
            for (var index = 0; index < restored.Length; index++)
            {
                if (!values[index].TryGetSingle(out var value) || !float.IsFinite(value) || value < 0 || value > 1) return;
                restored[index] = value;
            }
            Array.Copy(restored, volumes, volumes.Length);
        }
        catch (IOException) { }
        catch (System.Text.Json.JsonException) { }
        catch (UnauthorizedAccessException) { }
    }

    private void SaveVolumes()
    {
        var directory = Path.GetDirectoryName(settingsPath)!;
        Directory.CreateDirectory(directory);
        var temporary = settingsPath + ".tmp-" + Guid.NewGuid().ToString("N");
        try
        {
            var bytes = System.Text.Json.JsonSerializer.SerializeToUtf8Bytes(new { schemaVersion = 1, volumes });
            File.WriteAllBytes(temporary, bytes);
            File.Move(temporary, settingsPath, true);
        }
        finally
        {
            if (File.Exists(temporary)) File.Delete(temporary);
        }
    }

    private void Configure()
    {
        HITVM.Init();
        var hit = HITVM.Get();
        hit.NativeAudioEnabled = Enabled;
        hit.InstructionTrace = (thread, pc, opcode) => { if (trace.Count >= 128) trace.Dequeue(); trace.Enqueue((thread.Name, pc, opcode, Enumerable.Range(0, 4).Select(thread.ReadVar).ToArray())); };
        hit.ThreadError = (thread, error) => output(new { type = "audioError", name = thread.Name, pc = thread.PC, error = error.Message });
        hit.AudioFactory = FromPatch;
        hit.FileAudioFactory = FromFile;
        HITVM.DISABLE_SOUND = !Enabled;
        for (int index = 0; index < volumes.Length; index++) hit.SetMasterVolume((FSO.HIT.Model.HITVolumeGroup)index, volumes[index]);
    }

    public void Enable(bool value)
    {
        Reset();
        Enabled = value;
        Configure();
    }

    public void Reset()
    {
        foreach (var voice in voices.Values.ToArray()) voice.Dispose();
        voices.Clear();
        output(new { type = "audio", command = "reset" });
        Configure();
    }

    public void Tick(VM vm)
    {
        if (!Enabled) return;
        foreach (var entity in vm.SoundEntities.ToArray())
        {
            if (entity.Dead)
            {
                foreach (var entry in entity.SoundThreads) entry.Sound.RemoveOwner(entity.ObjectID);
                entity.SoundThreads.Clear();
            }
            entity.SoundThreads.RemoveAll(entry => entry.Sound.Dead);
            if (entity.SoundThreads.Count == 0) { vm.SoundEntities.Remove(entity); continue; }
            foreach (var entry in entity.SoundThreads)
            {
                entry.Sound.NativePan = entry.Pan;
                entry.Sound.NativeZoom = entry.Zoom;
                entry.Sound.SetVolume(1, 0, entity.ObjectID);
                if (entry.Sound is HITThread thread) entity.SubmitHITVars(thread);
            }
        }
        HITVM.Get().Tick();
    }

    /// <summary>Advances HIT playback when no lot is loaded, such as on the loading screen and neighborhood maps.</summary>
    public void Tick()
    {
        if (Enabled) HITVM.Get().Tick();
    }

    public object State() => new { enabled = Enabled, volumes = Enum.GetValues<FSO.HIT.Model.HITVolumeGroup>().ToDictionary(group => group.ToString(), group => volumes[(int)group]), voices = voices.Count, trace = trace.Select(entry => new { entry.Name, entry.PC, operation = HITInterpreter.Instructions[entry.Opcode].Method.Name, entry.Registers }).ToArray(), sounds = HITVM.Get().ActiveSounds.Select(sound => new { sound.Name, sound.Dead, owner = sound.LastMainOwner, pc = (sound as HITThread)?.PC, simple = (sound as HITThread)?.SimpleMode, lastNote = (sound as HITThread)?.LastNote, wait = (sound as HITThread)?.WaitRemain }).ToArray() };

    public void SetVolume(string group, float volume)
    {
        if (!Enum.TryParse<FSO.HIT.Model.HITVolumeGroup>(group, out var kind) || !Enum.IsDefined(kind) || !float.IsFinite(volume) || volume < 0 || volume > 1) throw new ArgumentException("Invalid audio group volume");
        var previous = volumes[(int)kind];
        volumes[(int)kind] = volume;
        try { SaveVolumes(); }
        catch { volumes[(int)kind] = previous; throw; }
        HITVM.Get().SetMasterVolume(kind, volume);
    }

    public void End(long id)
    {
        if (voices.TryGetValue(id, out var voice)) voice.Stop();
    }

    public bool Play(string name, VMEntity? entity = null, int? externalOwnerID = null)
    {
        if (!Enabled || name.Length > 256 || (entity != null && externalOwnerID.HasValue) ||
            (externalOwnerID.HasValue && externalOwnerID.Value != NeighborhoodOwnerID))
            throw new ArgumentException("Audio is disabled or event request is invalid");
        var sound = HITVM.Get().PlaySoundEvent(name);
        if (sound == null) return false;
        if (entity != null && !sound.AlreadyOwns(entity.ObjectID))
        {
            sound.AddOwner(entity.ObjectID);
            entity.SoundThreads.Add(new FSO.SimAntics.Model.Sound.VMSoundEntry { Name = name, Sound = sound, Pan = true, Zoom = true });
            entity.Thread.Context.VM.SoundEntities.Add(entity);
            if (sound is HITThread thread) entity.SubmitHITVars(thread);
        }
        else if (externalOwnerID is { } ownerID && !sound.AlreadyOwns(ownerID)) sound.AddOwner(ownerID);
        return true;
    }

    public void RemoveOwner(int ownerID)
    {
        foreach (var sound in HITVM.Get().ActiveSounds.ToArray())
            if (sound.AlreadyOwns(ownerID)) sound.RemoveOwner(ownerID);
    }

    private HITAudioClip? ReadClip(string key, Func<HITAudioClip?> read)
    {
        if (failedResources.Contains(key)) return null;
        try { return read(); }
        catch (Exception error) when (error is IOException or ArgumentException or IndexOutOfRangeException or OverflowException or NotSupportedException)
        {
            failedResources.Add(key);
            output(new { type = "audioError", resource = key, error = error.Message });
            return null;
        }
    }

    private HITAudioClip? FromPatch(Patch patch)
    {
        if (patch?.Filename == null) return null;
        if (clips.TryGetValue(patch.Filename, out var cached)) return cached;
        return ReadClip(patch.Filename, () =>
        {
            var source = ((TS1Audio)FSO.Content.Content.Get().Audio).GetAudioFrom(patch.Filename);
            return source == null ? null : Store(patch.Filename, source.Data, source.Filetype == 2 ? "VOX" : source.Filetype == 3 ? "MUSIC" : "FX");
        });
    }

    private HITAudioClip? FromFile(string file)
    {
        if (clips.TryGetValue(file, out var cached)) return cached;
        return ReadClip(file, () =>
        {
            var info = new FileInfo(file);
            if (!info.Exists || info.Length > 64 * 1024 * 1024) return null;
            var codec = new FSO.Content.Codecs.SFXCodec();
            using var stream = File.OpenRead(file);
            var source = (FSO.Content.Codecs.DecodedSFX)codec.GenDecode(stream);
            return Store(file, source.Data, Path.GetExtension(file).Equals(".mp3", StringComparison.OrdinalIgnoreCase) ? "MUSIC" : "FX");
        });
    }

    private HITAudioClip Store(string key, byte[] bytes, string group)
    {
        if (bytes.Length > 64 * 1024 * 1024) throw new InvalidDataException("Audio resource exceeds size limit");
        var wave = bytes.Length >= 12 && bytes.AsSpan(0, 4).SequenceEqual("RIFF"u8) && bytes.AsSpan(8, 4).SequenceEqual("WAVE"u8);
        var duration = wave ? WaveDuration(bytes) : MP3Duration(bytes);
        if (!float.IsFinite(duration) || duration <= 0 || duration > 3600) throw new InvalidDataException("Invalid audio duration");
        var file = Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant() + (wave ? ".wav" : ".mp3");
        var path = Path.Combine(directory, file);
        if (!File.Exists(path)) File.WriteAllBytes(path, bytes);
        var clip = new HITAudioClip(group, duration, () =>
        {
            if (voices.Count >= 256) return null!;
            var voice = new Voice(this, ++sequence, file, duration, group);
            voices.Add(voice.ID, voice);
            return voice;
        });
        clips[key] = clip;
        return clip;
    }

    public static float WaveDuration(byte[] bytes)
    {
        uint rate = 0, length = 0;
        for (int offset = 12; offset + 8 <= bytes.Length;)
        {
            var size = BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(offset + 4));
            if (size > bytes.Length - offset - 8) throw new InvalidDataException("Truncated WAV chunk");
            if (bytes.AsSpan(offset, 4).SequenceEqual("fmt "u8) && size >= 16)
                rate = BinaryPrimitives.ReadUInt32LittleEndian(bytes.AsSpan(offset + 16));
            if (bytes.AsSpan(offset, 4).SequenceEqual("data"u8)) length = size;
            offset = checked(offset + 8 + (int)size + (int)(size & 1));
        }
        if (rate == 0 || length == 0) throw new InvalidDataException("WAV has no format or sample data");
        return (float)length / rate;
    }

    public static float MP3Duration(byte[] bytes)
    {
        int offset = 0, frames = 0;
        double duration = 0;
        if (bytes.Length >= 10 && bytes.AsSpan(0, 3).SequenceEqual("ID3"u8))
            offset = 10 + ((bytes[6] & 127) << 21) + ((bytes[7] & 127) << 14) + ((bytes[8] & 127) << 7) + (bytes[9] & 127);
        int[] rates = [44100, 48000, 32000];
        int[] mpeg1 = [0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320];
        int[] mpeg2 = [0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160];
        while (offset + 4 <= bytes.Length)
        {
            var header = BinaryPrimitives.ReadUInt32BigEndian(bytes.AsSpan(offset));
            var version = (int)(header >> 19 & 3);
            var layer = header >> 17 & 3;
            var bitrate = (int)(header >> 12 & 15);
            var sampleRate = (int)(header >> 10 & 3);
            if ((header & 0xFFE00000) != 0xFFE00000 || version == 1 || layer != 1 || bitrate is 0 or 15 || sampleRate == 3) { offset++; continue; }
            var rate = rates[sampleRate] / (version == 3 ? 1 : version == 2 ? 2 : 4);
            var length = (version == 3 ? 144 : 72) * (version == 3 ? mpeg1 : mpeg2)[bitrate] * 1000 / rate + (int)(header >> 9 & 1);
            if (length > bytes.Length - offset) break;
            duration += (version == 3 ? 1152.0 : 576.0) / rate;
            frames++;
            offset += length;
        }
        if (frames == 0) throw new InvalidDataException("MP3 has no supported frames");
        return (float)duration;
    }

    public void Dispose()
    {
        Reset();
        Enabled = false;
        HITVM.DISABLE_SOUND = true;
        HITVM.Get().NativeAudioEnabled = false;
    }

    private sealed class Voice(NativeAudio owner, long id, string file, float duration, string group) : IHITVoice
    {
        public long ID => id;
        private readonly Stopwatch elapsed = new();
        private SoundState state = SoundState.Stopped;
        private float volume = 1, pan;
        private bool loop;
        public bool IsDisposed { get; private set; }
        public FSO.HIT.Model.HITVolumeGroup Group { get => Enum.Parse<FSO.HIT.Model.HITVolumeGroup>(group); set => group = value.ToString(); }
        public int SourceID { get; set; }
        public bool Spatial { get; set; }
        public bool Zoom { get; set; }
        public float Volume { get => volume; set { value = Math.Clamp(value, 0, 1); if (volume != value) { volume = value; Send("update"); } } }
        public float Pan { get => pan; set { value = Math.Clamp(value, -1, 1); if (pan != value) { pan = value; Send("update"); } } }
        public bool IsLooped { get => loop; set { if (loop != value) { loop = value; Send("update"); } } }
        public SoundState State
        {
            get { if (state == SoundState.Playing && !loop && elapsed.Elapsed.TotalSeconds >= duration) Stop(); return state; }
        }
        private void Send(string command) => owner.output(new { type = "audio", command, voice = id, file = "audio/" + file, duration, group, volume, pan, loop, ownerID = SourceID, spatial = Spatial, zoom = Zoom });
        public void Play() { if (IsDisposed) return; elapsed.Restart(); state = SoundState.Playing; Send("play"); }
        public void Stop() { if (state == SoundState.Stopped) return; elapsed.Reset(); state = SoundState.Stopped; Send("stop"); }
        public void Pause() { if (state != SoundState.Playing) return; elapsed.Stop(); state = SoundState.Paused; Send("pause"); }
        public void Resume() { if (state != SoundState.Paused) return; elapsed.Start(); state = SoundState.Playing; Send("resume"); }
        public void Dispose() { if (IsDisposed) return; Stop(); IsDisposed = true; owner.voices.Remove(id); }
        public void Apply3D(AudioListener listener, AudioEmitter emitter) { }
    }
}
