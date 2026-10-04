import Foundation
import XCTest
@testable import SimsCore

final class AudioEventTests: XCTestCase {
    private func event(_ fields: [String: Any]) throws -> AudioEvent {
        try JSONDecoder().decode(AudioEvent.self, from: JSONSerialization.data(withJSONObject: fields))
    }
    func testAudioCommandsRejectInvalidResourcesAndPlaybackParameters() throws {
        let fields: [String: Any] = ["command": "play", "voice": 1, "file": "audio/original.wav", "duration": 1.2,
                                   "group": "FX", "volume": 0.8, "pan": -0.5, "loop": false, "ownerID": 7, "spatial": true, "zoom": true]
        try event(fields).validate()
        for replacement in [["file": "audio/../../original.wav"], ["file": "other/original.wav"], ["file": "audio/original.iff"],
                            ["duration": 0], ["duration": 3601], ["voice": 0], ["volume": 1.1], ["pan": -1.1], ["group": "unknown"], ["ownerID": 32768]] {
            XCTAssertThrowsError(try event(fields.merging(replacement) { _, value in value }).validate())
        }
    }
    func testPlaybackControlCommandsDoNotRequireRepeatedResourceMetadata() throws {
        for command in ["pause", "resume", "stop"] {
            try event(["command": command, "voice": 7]).validate()
            XCTAssertThrowsError(try event(["command": command, "voice": -1]).validate())
        }
        try event(["command": "reset"]).validate()
        XCTAssertThrowsError(try event(["command": "delete", "voice": 7]))
    }
}
