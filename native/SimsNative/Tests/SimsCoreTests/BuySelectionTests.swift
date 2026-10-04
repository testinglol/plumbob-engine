import XCTest
@testable import SimsCore

final class BuySelectionTests: XCTestCase {
    private func object(id: Int = 42, guid: UInt32 = 123, level: Int = 1, direction: Int = 4, movable: Bool = true, sellable: Bool = true) throws -> EditableLotObject {
        let data = try JSONSerialization.data(withJSONObject: ["id": id, "guid": guid, "level": level, "direction": direction, "movable": movable, "sellable": sellable])
        return try JSONDecoder().decode(EditableLotObject.self, from: data)
    }

    func testCatalogAndPlacedSelectionKeepIndependentDirectionAndPermissions() throws {
        var selection = BuySelection()
        selection.chooseCatalog(123)
        XCTAssertEqual(selection.target, .catalog(123))
        for expected in [4, 16, 64, 1] {
            selection.rotate()
            XCTAssertEqual(selection.direction, expected)
        }
        let placed = try object()
        selection.chooseObject(placed)
        XCTAssertEqual(selection.target, .placed(placed))
        XCTAssertEqual(selection.direction, 4)
        selection.rotate()
        XCTAssertEqual(selection.direction, 16)
        selection.reconcile(objects: [placed])
        XCTAssertEqual(selection.direction, 16)
        let sellOnly = try object(movable: false)
        selection.reconcile(objects: [sellOnly])
        selection.rotate()
        XCTAssertEqual(selection.direction, 16)
        XCTAssertEqual(selection.target, .placed(sellOnly))
        selection.chooseCatalog(456)
        XCTAssertEqual(selection.direction, 1)
        selection.cancel()
        XCTAssertNil(selection.target)
        selection.rotate()
        XCTAssertEqual(selection.direction, 1)
    }

    func testUpperStoryObjectsUseTheSameSelectionAndRotationPath() throws {
        var selection = BuySelection()
        let upper = try object(level: 2)
        selection.chooseObject(upper)
        XCTAssertEqual(selection.target, .placed(upper))
        selection.rotate()
        XCTAssertEqual(selection.direction, 16)
        selection.reconcile(objects: [upper])
        XCTAssertEqual(selection.target, .placed(upper))
        selection.reconcile(objects: [try object(level: 1)])
        XCTAssertNil(selection.target)
    }

    func testUnavailableObjectsAndReusedIdentifiersCannotRemainSelected() throws {
        var selection = BuySelection()
        for invalid in [try object(id: 0), try object(guid: 0), try object(level: 6), try object(direction: 2), try object(movable: false, sellable: false)] {
            selection.chooseObject(invalid)
            XCTAssertNil(selection.target)
        }
        let placed = try object()
        for remaining in [[], [try object(guid: 999)], [try object(level: 2)], [try object(movable: false, sellable: false)]] {
            selection.chooseObject(placed)
            selection.reconcile(objects: remaining)
            XCTAssertNil(selection.target)
        }
    }
}
