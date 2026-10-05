import Foundation
import XCTest
import SimsCore
@testable import SimsClient

final class MessageReaderTests: XCTestCase {
    let session = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent("reader-session")

    private func events(_ messages: [MessageReader.Message]) -> [[String: Any]] {
        messages.compactMap { if case .event(let box) = $0 { box.value } else { nil } }
    }

    func testLinesSplitAcrossReadsAreJoined() {
        let reader = MessageReader(session: session, decodesAnimation: false)
        let stream = Data(#"{"type":"state","n":1}"#.utf8) + Data([10]) + Data(#"{"type":"audio","n":2}"#.utf8) + Data([10])
        var received: [[String: Any]] = []
        // One byte at a time, as small pipe reads can deliver it.
        for byte in stream { received += events(reader.receive(Data([byte]))) }
        XCTAssertEqual(received.map { $0["type"] as? String }, ["state", "audio"])
        XCTAssertEqual(received.map { $0["n"] as? Int }, [1, 2])
        XCTAssertEqual(events(reader.receive(stream + stream)).count, 4)
    }

    func testAnimationLinesAreDecodedWhenAsked() throws {
        let frame = #"{"type":"animation","frame":{"schemaVersion":1,"baseRevision":3,"sequence":7,"updates":9,"textureStart":0,"textures":[],"sprites":[],"meshes":[]}}"#
        let line = Data(frame.utf8) + Data([10])
        guard case .animation(let decoded)? = MessageReader(session: session, decodesAnimation: true).receive(line).first else {
            return XCTFail("expected a decoded animation frame")
        }
        XCTAssertEqual(decoded.value.baseRevision, 3)
        XCTAssertEqual(decoded.value.sequence, 7)
        XCTAssertEqual(events(MessageReader(session: session, decodesAnimation: false).receive(line)).first?["type"] as? String, "animation")
    }

    func testScenesOutsideTheSessionAndMalformedLinesFail() {
        let reader = MessageReader(session: session, decodesAnimation: false)
        let messages = reader.receive(Data("{\"scene\":\"/etc/passwd\"}\nnot json\n{\"ok\":true}\n".utf8))
        XCTAssertEqual(messages.count, 3)
        guard case .failure = messages[0], case .failure = messages[1], case .event = messages[2] else { return XCTFail("unexpected messages") }
    }

    func testOversizedLineStopsTheReader() {
        let reader = MessageReader(session: session, decodesAnimation: false)
        let messages = reader.receive(Data(repeating: 65, count: 16 * 1024 * 1024 + 1))
        guard case .failure(let error)? = messages.last else { return XCTFail("expected a size failure") }
        XCTAssertEqual(error, MessageReader.sizeLimitError)
        XCTAssertTrue(reader.receive(Data("{}\n".utf8)).isEmpty)
    }
}
