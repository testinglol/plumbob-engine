import Foundation
import AVFoundation
import SimsCore

@MainActor
final class NativeAudioController: NSObject, AVAudioPlayerDelegate {
    private let root: URL
    private var players: [Int64: AVAudioPlayer] = [:]
    private var events: [Int64: AudioEvent] = [:]
    var ended: ((Int64) -> Void)?
    var spatial: ((Int, Bool, Bool) -> (pan: Float, gain: Float))?

    init(session: URL) {
        root = session.resolvingSymlinksInPath().standardizedFileURL
        super.init()
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
                  players.count < 256 else { throw ContentError.invalid("Audio resource escapes session or exceeds size limit") }
            let player = try AVAudioPlayer(contentsOf: url)
            guard player.duration.isFinite, player.duration > 0, player.duration <= 3600 else { throw ContentError.invalid("Invalid decoded audio duration") }
            players[id]?.stop()
            players[id] = player
            events[id] = event
            player.delegate = self
            configure(player, event)
            guard player.prepareToPlay(), player.play() else { finish(player); return }
        case .update:
            if let player = players[id] { events[id] = event; configure(player, event) }
        case .pause: players[id]?.pause()
        case .resume:
            if let player = players[id], !player.play() { finish(player) }
        case .stop:
            players.removeValue(forKey: id)?.stop()
            events.removeValue(forKey: id)
        case .reset: break
        }
    }

    private func configure(_ player: AVAudioPlayer, _ event: AudioEvent) {
        let position = (event.spatial == true || event.zoom == true) && (event.ownerID ?? -1) > 0 ? spatial?(event.ownerID!, event.spatial ?? false, event.zoom ?? false) : nil
        player.volume = (event.volume ?? 1) * (position?.gain ?? 1)
        player.pan = event.spatial == true ? position?.pan ?? event.pan ?? 0 : event.pan ?? 0
        player.numberOfLoops = event.loop == true ? -1 : 0
    }

    func updateSpatial() {
        for (id, player) in players { if let event = events[id] { configure(player, event) } }
    }

    func stop() {
        players.values.forEach { $0.stop() }
        players.removeAll()
        events.removeAll()
    }

    static func inspect(_ url: URL) throws -> [String: Any] {
        let file = try AVAudioFile(forReading: url, commonFormat: .pcmFormatFloat32, interleaved: false)
        let format = file.processingFormat
        guard format.channelCount > 0, format.channelCount <= 8, format.sampleRate.isFinite, format.sampleRate > 0,
              let buffer = AVAudioPCMBuffer(pcmFormat: format, frameCapacity: 4096) else { throw ContentError.invalid("Invalid native audio format") }
        var frames: Int64 = 0
        var peak: Float = 0
        while file.framePosition < file.length {
            try file.read(into: buffer)
            guard buffer.frameLength > 0, let channels = buffer.floatChannelData else { break }
            frames += Int64(buffer.frameLength)
            for channel in 0..<Int(format.channelCount) {
                for sample in 0..<Int(buffer.frameLength) {
                    let value = channels[channel][sample]
                    guard value.isFinite else { throw ContentError.invalid("Decoded audio has nonfinite samples") }
                    peak = max(peak, abs(value))
                }
            }
        }
        guard frames > 0 else { throw ContentError.invalid("Native audio decoder produced no samples") }
        return ["file": url.path, "channels": format.channelCount, "sampleRate": format.sampleRate, "frames": frames,
                "duration": Double(frames) / format.sampleRate, "peak": peak]
    }

    private func finish(_ player: AVAudioPlayer) { finish(ObjectIdentifier(player)) }

    private func finish(_ identity: ObjectIdentifier) {
        guard let id = players.first(where: { ObjectIdentifier($0.value) == identity })?.key else { return }
        players.removeValue(forKey: id)
        events.removeValue(forKey: id)
        ended?(id)
    }

    nonisolated func audioPlayerDidFinishPlaying(_ player: AVAudioPlayer, successfully flag: Bool) {
        let identity = ObjectIdentifier(player)
        Task { @MainActor [weak self] in self?.finish(identity) }
    }

    nonisolated func audioPlayerDecodeErrorDidOccur(_ player: AVAudioPlayer, error: Error?) {
        let identity = ObjectIdentifier(player)
        Task { @MainActor [weak self] in self?.finish(identity) }
    }
}
