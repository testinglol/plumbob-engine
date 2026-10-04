import Foundation

public struct AudioEvent: Decodable {
    public enum Command: String, Decodable { case play, update, pause, resume, stop, reset }
    public let command: Command
    public let voice: Int64?
    public let file: String?
    public let duration: Float?
    public let group: String?
    public let volume: Float?
    public let pan: Float?
    public let loop: Bool?
    public let ownerID: Int?
    public let spatial: Bool?
    public let zoom: Bool?

    public func validate() throws {
        if command == .reset { return }
        guard let voice, voice > 0 else { throw ContentError.invalid("Invalid audio voice") }
        if command == .play || command == .update {
            guard let file, let duration, let group, let volume, let pan, loop != nil,
                  duration.isFinite, duration > 0, duration <= 3600,
                  volume.isFinite, (0...1).contains(volume), pan.isFinite, (-1...1).contains(pan),
                  ["FX", "VOX", "MUSIC", "AMBIENCE"].contains(group), (ownerID ?? -1) >= -1, (ownerID ?? -1) <= 32767 else {
                throw ContentError.invalid("Invalid audio playback parameters")
            }
            let key = try resourceKey(file)
            guard key.hasPrefix("audio/"), ["wav", "mp3"].contains((key as NSString).pathExtension), key.utf8.count <= 256 else {
                throw ContentError.invalid("Invalid audio resource path")
            }
        }
    }
}
