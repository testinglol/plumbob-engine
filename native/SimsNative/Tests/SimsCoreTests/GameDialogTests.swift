import Foundation
import XCTest
@testable import SimsCore

final class GameDialogTests: XCTestCase {
    func testOriginalChoicesAndCustomLabelsPreserveResponseCodes() throws {
        func dialog(_ kind: Int, yes: String? = nil) throws -> GameDialog {
            var object: [String: Any] = ["token": "1", "blocking": true, "caller": 58, "icon": 58, "kind": kind, "title": "Help System", "message": "Activate help?"]
            if let yes { object["yes"] = yes }
            return try JSONDecoder().decode(GameDialog.self, from: JSONSerialization.data(withJSONObject: object))
        }
        XCTAssertEqual(try dialog(0).buttons.map(\.code), [0])
        XCTAssertEqual(try dialog(1).buttons.map(\.label), ["Yes", "No"])
        XCTAssertEqual(try dialog(2, yes: "Accept").buttons.map(\.label), ["Accept", "No", "Cancel"])
        XCTAssertEqual(try dialog(2).buttons.map(\.code), [0, 1, 2])
        XCTAssertEqual(try dialog(3).buttons.map(\.code), [0])
        XCTAssertEqual(try dialog(10).buttons.map(\.code), [1, 0])
        XCTAssertEqual(try dialog(10).buttons.map(\.label), ["Call", "Cancel"])
        // Pickers without a native screen must still be dismissable with their original cancel/acknowledge codes.
        XCTAssertEqual(try dialog(6).buttons.map(\.code), [0])
        XCTAssertEqual(try dialog(9).buttons.map(\.label), ["Cancel"])
        XCTAssertEqual(try dialog(12).buttons.map(\.code), [0])
        XCTAssertEqual(try dialog(15).buttons.map(\.label), ["OK"])
        XCTAssertEqual(try dialog(5).buttons, [])
        XCTAssertNoThrow(try dialog(1).validate())
        XCTAssertThrowsError(try dialog(1, yes: String(repeating: "A", count: 513)).validate())
    }
}
