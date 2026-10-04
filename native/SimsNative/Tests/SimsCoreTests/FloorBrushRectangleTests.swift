import Foundation
import XCTest
@testable import SimsCore

final class FloorBrushRectangleTests: XCTestCase {
    func testInclusiveRectangleInEveryDragDirection() throws {
        let expected = try XCTUnwrap(FloorBrushRectangle(startX: 1, startY: 2, endX: 4, endY: 6))
        for (x, y, endX, endY) in [(1, 2, 4, 6), (4, 6, 1, 2), (4, 2, 1, 6), (1, 6, 4, 2)] {
            XCTAssertEqual(FloorBrushRectangle(startX: x, startY: y, endX: endX, endY: endY), expected)
        }
        XCTAssertEqual(expected.x, 1)
        XCTAssertEqual(expected.y, 2)
        XCTAssertEqual(expected.width, 3)
        XCTAssertEqual(expected.height, 4)
        XCTAssertEqual(expected.tileCount, 20)
        XCTAssertEqual(FloorBrushRectangle(startX: 3, startY: 3, endX: 3, endY: 3)?.tileCount, 1)
        XCTAssertEqual(FloorBrushRectangle(startX: 0, startY: 0, endX: 127, endY: 127)?.tileCount, 16384)
        XCTAssertNil(FloorBrushRectangle(startX: -1, startY: 0, endX: 0, endY: 0))
        XCTAssertNil(FloorBrushRectangle(startX: 0, startY: 0, endX: Int.max, endY: 0))
    }

    func testGeometryPreservesTerrainAndRejectsOutOfBounds() throws {
        let vertices = (0..<54).map { ["x": $0, "y": $0 * 2, "r": 10, "g": 20, "b": 30] }
        let data = try JSONSerialization.data(withJSONObject: ["schemaVersion": 1, "house": 5, "width": 32, "height": 32, "lotWidth": 3, "lotHeight": 3, "terrainVertices": vertices, "textures": [], "sprites": [], "limitations": []])
        let scene = try JSONDecoder().decode(LotScene.self, from: data)
        let rectangle = try XCTUnwrap(FloorBrushRectangle(startX: 2, startY: 2, endX: 1, endY: 1))
        let geometry = try rectangle.geometry(scene: scene)
        let indices = Array(24..<36) + Array(42..<54)
        XCTAssertEqual(geometry.count, 24)
        XCTAssertEqual(geometry.map(\.x), indices.map(Float.init))
        XCTAssertEqual(geometry.map(\.y), indices.map { Float($0 * 2) })
        let outside = try XCTUnwrap(FloorBrushRectangle(startX: 0, startY: 0, endX: 3, endY: 2))
        XCTAssertThrowsError(try outside.geometry(scene: scene))
    }
}
