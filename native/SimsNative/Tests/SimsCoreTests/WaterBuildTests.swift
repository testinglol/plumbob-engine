import Foundation
import XCTest
@testable import SimsCore

final class WaterBuildTests: XCTestCase {
    func testWaterCatalogSeparatesReservedPatternsFromOrdinaryFloors() throws {
        let items: [[String: Any]] = [
            ["id": 65534, "name": "Pond", "description": "", "price": 30, "file": "global"],
            ["id": 65535, "name": "Pool", "description": "", "price": 75, "file": "global"]
        ]
        func page(_ kind: String, _ entries: [[String: Any]]) throws -> BuildCatalogPage {
            let data = try JSONSerialization.data(withJSONObject: ["schemaVersion": 1, "kind": kind, "offset": 0, "total": entries.count, "items": entries])
            return try JSONDecoder().decode(BuildCatalogPage.self, from: data)
        }
        try page("water", items).validate()
        XCTAssertThrowsError(try page("floor", items).validate())
        XCTAssertThrowsError(try page("water", [["id": 1, "name": "Carpet", "description": "", "price": 2, "file": "global"]]).validate())
        XCTAssertNil(BuildRoomFill(kind: .water, pattern: 65535, tile: nil, wall: nil))
    }

    func testPoolAccessoriesKeepFullGUIDsAndCannotBecomeFloorCommands() throws {
        let floor: [String: Any] = ["id": 65535, "name": "Pool", "description": "", "price": 75, "file": "global"]
        let ladder: [String: Any] = ["id": 0, "guid": 0xF1A00001, "name": "Ladder", "description": "", "price": 75, "file": "objects/ladder"]
        let board: [String: Any] = ["id": 0, "guid": 0xF1A00002, "name": "Board", "description": "", "price": 75, "file": "objects/board"]
        func page(_ items: [[String: Any]], kind: String = "water") throws -> BuildCatalogPage {
            let data = try JSONSerialization.data(withJSONObject: ["schemaVersion": 1, "kind": kind, "offset": 0, "total": items.count, "items": items])
            return try JSONDecoder().decode(BuildCatalogPage.self, from: data)
        }
        let valid = try page([floor, ladder, board])
        try valid.validate()
        XCTAssertEqual(valid.items.map(\.target), [.pattern(65535), .object(0xF1A00001), .object(0xF1A00002)])
        XCTAssertThrowsError(try page([ladder, floor]).validate())
        XCTAssertThrowsError(try page([ladder, ladder]).validate())
        XCTAssertThrowsError(try page([ladder], kind: "floor").validate())
        XCTAssertThrowsError(try page([ladder.merging(["id": 65535]) { _, next in next }]).validate())
        XCTAssertThrowsError(try page([ladder.merging(["guid": 0]) { _, next in next }]).validate())
    }

    func testWaterBrushUsesWholeTilesAndDoesNotPaintSingleDiagonalHalves() throws {
        let scene = try DiagonalFloorPickingTests().scene(diagonal: 32)
        let area = try XCTUnwrap(FloorBrushRectangle(startX: 0, startY: 0, endX: 0, endY: 0))
        let water = try XCTUnwrap(FloorBrushSelection(rectangle: area, half: 1, water: true))
        XCTAssertEqual(water.style, 0)
        XCTAssertTrue(try water.geometry(scene: scene).isEmpty)
        let removal = try XCTUnwrap(FloorBrushSelection(rectangle: area, half: 1))
        XCTAssertEqual(try removal.geometry(scene: scene).count, 3)
        let normal = try DiagonalFloorPickingTests().scene(diagonal: 0)
        XCTAssertEqual(try water.geometry(scene: normal).count, 6)
    }

    func testWaterTopologyUsesOriginalEdgeAndInnerCornerSprites() throws {
        try LotScene.WaterSurface(adjacency: 0, sprite: 0x410, corners: []).validate(pattern: 65535)
        try LotScene.WaterSurface(adjacency: 255, sprite: 0x41F, corners: []).validate(pattern: 65535)
        try LotScene.WaterSurface(adjacency: 65, sprite: 0x413, corners: [0x434]).validate(pattern: 65535)
        try LotScene.WaterSurface(adjacency: 65, sprite: 0x803, corners: []).validate(pattern: 65534)
        XCTAssertThrowsError(try LotScene.WaterSurface(adjacency: 65, sprite: 0x413, corners: []).validate(pattern: 65535))
        XCTAssertThrowsError(try LotScene.WaterSurface(adjacency: 255, sprite: 0x410, corners: []).validate(pattern: 65535))
        XCTAssertThrowsError(try LotScene.WaterSurface(adjacency: 256, sprite: 0x41F, corners: []).validate(pattern: 65535))
        XCTAssertThrowsError(try LotScene.WaterSurface(adjacency: 65, sprite: 0x803, corners: [0x434]).validate(pattern: 65534))
    }
}
