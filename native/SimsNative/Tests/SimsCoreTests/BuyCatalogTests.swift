import Foundation
import XCTest
@testable import SimsCore

final class BuyCatalogTests: XCTestCase {
    /// An instance for borrowing fixture helpers from other test classes; Linux XCTest has no argument-free init.
    static func fixture() -> BuyCatalogTests {
        #if canImport(ObjectiveC)
        return BuyCatalogTests()
        #else
        return BuyCatalogTests(name: "fixture", testClosure: { _ in })
        #endif
    }

    func decode(_ items: [[String: Any]], category: Int = 2, offset: Int = 0, total: Int = 2) throws -> BuyCatalogPage {
        let data = try JSONSerialization.data(withJSONObject: ["schemaVersion": 1, "category": category, "offset": offset, "total": total, "items": items])
        return try JSONDecoder().decode(BuyCatalogPage.self, from: data)
    }

    func testValidatesCatalogPagesBeforeCreatingControlsOrLoadingIcons() throws {
        let icon: [String: Any] = ["file": "ui-" + String(repeating: "a", count: 64) + ".bmp", "columns": 2, "rows": 1]
        let first: [String: Any] = ["guid": 1, "name": "Flamingo", "description": "Garden decoration", "price": 12, "category": 2, "icon": icon]
        let second: [String: Any] = ["guid": 2, "name": "Custom object", "description": "", "price": 37, "category": 2]
        let page = try decode([first, second])
        try page.validate()
        XCTAssertEqual(page.items[0].icon?.columns, 2)
        XCTAssertEqual(page.items[1].guid, 2)
        try decode([], offset: 10, total: 2).validate()
        for items in [[second, first], [first, first], Array(repeating: first, count: 65)] {
            XCTAssertThrowsError(try decode(items, total: 65).validate())
        }
        for (key, value) in [("price", -1 as Any), ("category", 3 as Any), ("guid", 0 as Any),
                             ("name", String(repeating: "x", count: 513) as Any),
                             ("description", String(repeating: "x", count: 4097) as Any),
                             ("icon", ["file": "../outside.bmp", "columns": 2, "rows": 1] as Any)] {
            var malformed = first
            malformed[key] = value
            XCTAssertThrowsError(try decode([malformed]).validate())
        }
        XCTAssertThrowsError(try decode([first], total: 0).validate())
        XCTAssertThrowsError(try decode([], category: 8).validate())
        XCTAssertThrowsError(try decode([], offset: -1).validate())
        XCTAssertThrowsError(try decode([], total: 2).validate())
    }

    func testResizingCatalogDoesNotSkipHiddenItems() throws {
        let items = (1...30).map { ["guid": $0, "name": "Object", "description": "", "price": $0, "category": 2] as [String: Any] }
        let page = try decode(items, total: 50)
        try page.validate()
        let small = CGSize(width: 800, height: 480)
        let large = CGSize(width: 1200, height: 900)
        XCTAssertEqual(OriginalBuyLayout.capacity(canvas: small), 14)
        XCTAssertEqual(OriginalBuyLayout.capacity(canvas: large), 30)
        XCTAssertEqual(page.nextOffset(visibleCapacity: OriginalBuyLayout.capacity(canvas: small)), 14)
        XCTAssertEqual(page.nextOffset(visibleCapacity: OriginalBuyLayout.capacity(canvas: large)), 30)
        XCTAssertNil(page.nextOffset(visibleCapacity: 0))
        for canvas in [small, large, CGSize(width: 4096, height: 1800)] {
            let capacity = OriginalBuyLayout.capacity(canvas: canvas)
            XCTAssertLessThanOrEqual(capacity, 64)
            for index in 0..<capacity {
                let rect = OriginalBuyLayout.thumbnail(index, canvas: canvas)
                XCTAssertGreaterThanOrEqual(rect.minX, 421)
                XCTAssertLessThanOrEqual(rect.maxX, canvas.width - 24)
                XCTAssertGreaterThanOrEqual(rect.minY, canvas.height - 100)
                XCTAssertLessThanOrEqual(rect.maxY, canvas.height - 5)
            }
        }
    }
}
