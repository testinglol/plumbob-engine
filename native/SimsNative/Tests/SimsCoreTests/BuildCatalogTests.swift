import Foundation
import XCTest
@testable import SimsCore

final class BuildCatalogTests: XCTestCase {
    func testPatternPagesRejectInvalidIdentifiersOrderingAndKinds() throws {
        func page(_ items: [[String: Any]], kind: String = "floor", total: Int = 2) throws -> BuildCatalogPage {
            let data = try JSONSerialization.data(withJSONObject: ["schemaVersion": 1, "kind": kind, "offset": 0, "total": total, "items": items])
            return try JSONDecoder().decode(BuildCatalogPage.self, from: data)
        }
        let first: [String: Any] = ["id": 1, "name": "Original pattern", "description": "", "price": 2, "file": "global"]
        let second = first.merging(["id": 256, "price": 3, "file": "custom.flr"]) { _, next in next }
        let valid = try page([first, second], total: 30)
        try valid.validate()
        XCTAssertEqual(valid.nextOffset(visibleCapacity: 1), 1)
        XCTAssertEqual(valid.nextOffset(visibleCapacity: 40), 2)
        for invalid in [[first, first], [second, first], [first.merging(["id": 65535]) { _, next in next }], [first.merging(["price": -1]) { _, next in next }]] {
            XCTAssertThrowsError(try page(invalid).validate())
        }
        XCTAssertThrowsError(try page([first], kind: "unknown"))
        try page([first.merging(["id": 0, "price": 0]) { _, next in next }], kind: "roof", total: 1).validate()
        try page([first], kind: "wall", total: 1).validate()
        XCTAssertThrowsError(try page([first], kind: "wallStyle", total: 1).validate())
        try page([first.merging(["pattern": 0]) { _, next in next }], kind: "wallStyle", total: 1).validate()
        XCTAssertThrowsError(try page([first.merging(["pattern": 65534]) { _, next in next }], kind: "wallStyle", total: 1).validate())
    }
}
