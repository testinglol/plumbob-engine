import Foundation
import CDrMP3
import CSDL3
import SimsCore

/// The host's voices, mixed on SDL's audio thread: decoded stereo float samples at the device rate, each with its gains,
/// loop flag and position. Everything the audio thread reads is guarded by the lock.
private final class AudioMixer: @unchecked Sendable {
    struct Voice {
        let samples: [Float]
        var frame = 0
        var left: Float = 1
        var right: Float = 1
        var loop = false
        var paused = false
    }

    private let lock = NSLock()
    private var voices: [Int64: Voice] = [:]
    private var ended: [Int64] = []
    private var scratch: [Float] = []

    func set(_ id: Int64, _ voice: Voice?) { lock.withLock { voices[id] = voice } }
    func update(_ id: Int64, _ change: (inout Voice) -> Void) { lock.withLock { if voices[id] != nil { change(&voices[id]!) } } }
    func clear() { lock.withLock { voices.removeAll(); ended.removeAll() } }
    var count: Int { lock.withLock { voices.count } }

    /// Voices that played to their end since the last call.
    func takeEnded() -> [Int64] { lock.withLock { defer { ended.removeAll() }; return ended } }

    /// Fills `frames` stereo frames; runs on the audio thread.
    func mix(frames: Int) -> [Float] {
        lock.lock()
        defer { lock.unlock() }
        if scratch.count != frames * 2 { scratch = [Float](repeating: 0, count: frames * 2) }
        else { for index in scratch.indices { scratch[index] = 0 } }
        for (id, var voice) in voices where !voice.paused {
            let total = voice.samples.count / 2
            guard total > 0 else { continue }
            voice.samples.withUnsafeBufferPointer { source in
                var written = 0
                while written < frames {
                    if voice.frame >= total {
                        guard voice.loop else { break }
                        voice.frame = 0
                    }
                    let run = min(frames - written, total - voice.frame)
                    for offset in 0..<run {
                        let input = (voice.frame + offset) * 2, output = (written + offset) * 2
                        scratch[output] += source[input] * voice.left
                        scratch[output + 1] += source[input + 1] * voice.right
                    }
                    voice.frame += run
                    written += run
                }
            }
            if voice.frame >= total && !voice.loop {
                voices[id] = nil
                ended.append(id)
            } else {
                voices[id] = voice
            }
        }
        for index in scratch.indices { scratch[index] = min(1, max(-1, scratch[index])) }
        return scratch
    }
}

/// SDL's stream callback, on the audio thread: tops the stream up with freshly mixed frames.
private func mixAudio(_ userdata: UnsafeMutableRawPointer?, _ stream: OpaquePointer?, _ additional: Int32, _ total: Int32) {
    guard let userdata, additional > 0 else { return }
    let mixer = Unmanaged<AudioMixer>.fromOpaque(userdata).takeUnretainedValue()
    let samples = mixer.mix(frames: Int(additional) / 8)
    samples.withUnsafeBytes { _ = SDL_PutAudioStreamData(stream, $0.baseAddress, Int32($0.count)) }
}

/// Plays the simulation host's audio events through SDL, as NativeAudioController does through AVFoundation on macOS:
/// the host picks, routes and scales each sound and the client decodes, pans and mixes it.
@MainActor
final class SDLAudioPlayer {
    private static let rate: Int32 = 44_100
    private let root: URL
    private let mixer = AudioMixer()
    private var stream: OpaquePointer?
    private var events: [Int64: AudioEvent] = [:]
    private var cache: [String: [Float]] = [:]
    private var cacheOrder: [String] = []
    var ended: ((Int64) -> Void)?
    var spatial: ((Int, Bool, Bool) -> (pan: Float, gain: Float))?

    init(session: URL) throws {
        root = session.resolvingSymlinksInPath().standardizedFileURL
        guard SDL_InitSubSystem(SDL_INIT_AUDIO) else { throw SDLError("SDL_InitSubSystem(audio)") }
        var spec = SDL_AudioSpec(format: SDL_AUDIO_F32, channels: 2, freq: Self.rate)
        let context = Unmanaged.passUnretained(mixer).toOpaque()
        guard let stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, mixAudio, context) else {
            SDL_QuitSubSystem(SDL_INIT_AUDIO)
            throw SDLError("SDL_OpenAudioDeviceStream")
        }
        self.stream = stream
        _ = SDL_ResumeAudioStreamDevice(stream)
    }

    func close() {
        if let stream { SDL_DestroyAudioStream(stream) }
        stream = nil
        mixer.clear()
        SDL_QuitSubSystem(SDL_INIT_AUDIO)
    }

    func receive(_ event: AudioEvent) throws {
        try event.validate()
        if event.command == .reset { stop(); return }
        guard let id = event.voice else { return }
        switch event.command {
        case .play:
            guard let file = event.file else { return }
            let url = root.appendingPathComponent(file).resolvingSymlinksInPath().standardizedFileURL
            guard url.path.hasPrefix(root.appendingPathComponent("audio").path + "/"),
                  (try url.resourceValues(forKeys: [.fileSizeKey]).fileSize ?? Int.max) <= 64 * 1024 * 1024,
                  mixer.count < 256 else { throw ContentError.invalid("Audio resource escapes session or exceeds size limit") }
            let samples = try decode(url)
            guard !samples.isEmpty, samples.count / 2 <= Int(Self.rate) * 3600 else { throw ContentError.invalid("Invalid decoded audio duration") }
            events[id] = event
            var voice = AudioMixer.Voice(samples: samples)
            configure(&voice, event)
            mixer.set(id, voice)
        case .update:
            guard events[id] != nil else { return }
            events[id] = event
            mixer.update(id) { configure(&$0, event) }
        case .pause: mixer.update(id) { $0.paused = true }
        case .resume: mixer.update(id) { $0.paused = false }
        case .stop:
            mixer.set(id, nil)
            events.removeValue(forKey: id)
        case .reset: break
        }
    }

    private func configure(_ voice: inout AudioMixer.Voice, _ event: AudioEvent) {
        let position = (event.spatial == true || event.zoom == true) && (event.ownerID ?? -1) > 0
            ? spatial?(event.ownerID!, event.spatial ?? false, event.zoom ?? false) : nil
        let volume = (event.volume ?? 1) * (position?.gain ?? 1)
        let pan = event.spatial == true ? position?.pan ?? event.pan ?? 0 : event.pan ?? 0
        voice.left = volume * (pan > 0 ? 1 - pan : 1)
        voice.right = volume * (pan < 0 ? 1 + pan : 1)
        voice.loop = event.loop == true
    }

    /// Re-applies positions after the view moves, and reports voices that finished.
    func updateSpatial() {
        for (id, event) in events where event.spatial == true || event.zoom == true {
            mixer.update(id) { configure(&$0, event) }
        }
    }

    func poll() {
        for id in mixer.takeEnded() {
            events.removeValue(forKey: id)
            ended?(id)
        }
    }

    func stop() {
        mixer.clear()
        events.removeAll()
    }

    /// Decodes a WAV or MP3 file to interleaved stereo floats at the mixer rate; recent files stay cached.
    private func decode(_ url: URL) throws -> [Float] {
        if let cached = cache[url.path] { return cached }
        let data = try Data(contentsOf: url)
        var source = SDL_AudioSpec()
        var samples: [Float]
        if url.pathExtension.lowercased() == "mp3" {
            var config = drmp3_config()
            var frames: drmp3_uint64 = 0
            guard let decoded = data.withUnsafeBytes({ drmp3_open_memory_and_read_pcm_frames_f32($0.baseAddress, $0.count, &config, &frames, nil) }) else {
                throw ContentError.invalid("Cannot decode \(url.lastPathComponent)")
            }
            defer { drmp3_free(decoded, nil) }
            source = SDL_AudioSpec(format: SDL_AUDIO_F32, channels: Int32(config.channels), freq: Int32(config.sampleRate))
            samples = try convert(UnsafeRawPointer(decoded), bytes: Int(frames) * Int(config.channels) * 4, from: &source)
        } else {
            var buffer: UnsafeMutablePointer<UInt8>?
            var length: UInt32 = 0
            let loaded = data.withUnsafeBytes { bytes -> Bool in
                guard let io = SDL_IOFromConstMem(bytes.baseAddress, bytes.count) else { return false }
                return SDL_LoadWAV_IO(io, true, &source, &buffer, &length)
            }
            guard loaded, let buffer else { throw ContentError.invalid("Cannot decode \(url.lastPathComponent): \(String(cString: SDL_GetError()))") }
            defer { SDL_free(buffer) }
            samples = try convert(UnsafeRawPointer(buffer), bytes: Int(length), from: &source)
        }
        cache[url.path] = samples
        cacheOrder.append(url.path)
        if cacheOrder.count > 96 { cache[cacheOrder.removeFirst()] = nil }
        return samples
    }

    private func convert(_ input: UnsafeRawPointer, bytes: Int, from source: inout SDL_AudioSpec) throws -> [Float] {
        var target = SDL_AudioSpec(format: SDL_AUDIO_F32, channels: 2, freq: Self.rate)
        var output: UnsafeMutablePointer<UInt8>?
        var length: Int32 = 0
        guard bytes > 0, SDL_ConvertAudioSamples(&source, input.assumingMemoryBound(to: UInt8.self), Int32(bytes), &target, &output, &length),
              let output else { throw ContentError.invalid("Cannot convert audio: \(String(cString: SDL_GetError()))") }
        defer { SDL_free(output) }
        return Array(UnsafeBufferPointer(start: UnsafeRawPointer(output).assumingMemoryBound(to: Float.self), count: Int(length) / 4))
    }
}
