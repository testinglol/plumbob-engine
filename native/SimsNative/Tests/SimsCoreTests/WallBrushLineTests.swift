import Foundation
import XCTest
@testable import SimsCore

final class WallBrushLineTests: XCTestCase {
    func testEightDirectionsAndSnappedEndpoints() throws {
        for (direction, delta) in [(3, 0), (3, 3), (0, 3), (-3, 3), (-3, 0), (-3, -3), (0, -3), (3, -3)].enumerated() {
            let line = try XCTUnwrap(WallBrushLine(start: LotVertex(x: 20, y: 20), end: LotVertex(x: 20 + delta.0, y: 20 + delta.1)))
            XCTAssertEqual(line.direction, direction)
            XCTAssertEqual(line.length, 3)
            XCTAssertEqual(line.end, LotVertex(x: 20 + delta.0, y: 20 + delta.1))
        }
        XCTAssertEqual(WallBrushLine(start: LotVertex(x: 20, y: 20), end: LotVertex(x: 25, y: 21))?.end, LotVertex(x: 25, y: 20))
        XCTAssertNil(WallBrushLine(start: LotVertex(x: 20, y: 20), end: LotVertex(x: 20, y: 20)))
        XCTAssertNil(WallBrushLine(start: LotVertex(x: -1, y: 20), end: LotVertex(x: 20, y: 20)))
        XCTAssertNil(WallBrushLine(start: LotVertex(x: 127, y: 127), end: LotVertex(x: 128, y: 125)))
    }

    func testVertexPickingAndWallPlaneFollowSlopedTerrain() throws {
        let vertices = [(10, 140), (42, 150), (10, 166), (10, 166), (-22, 150), (10, 140)]
            .map { ["x": $0.0 + 22, "y": $0.1, "r": 0, "g": 0, "b": 0] }
        let document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 64, "height": 200, "lotWidth": 1, "lotHeight": 1,
                                     "terrainVertices": vertices, "textures": [], "sprites": [], "limitations": []]
        let scene = try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
        let picker = try XCTUnwrap(LotVertexPicker(scene: scene))
        XCTAssertEqual(picker.vertex(at: SIMD2(32, 141)), LotVertex(x: 0, y: 0))
        XCTAssertEqual(picker.vertex(at: SIMD2(63, 150)), LotVertex(x: 1, y: 0))
        XCTAssertNil(picker.vertex(at: SIMD2(.nan, 150)))
        let line = try XCTUnwrap(WallBrushLine(start: LotVertex(x: 0, y: 0), end: LotVertex(x: 1, y: 0)))
        let geometry = try line.geometry(scene: scene)
        XCTAssertEqual(geometry.map(\.x), [32, 64, 64, 64, 32, 32])
        XCTAssertEqual(geometry.map(\.y), [140, 150, 38, 38, 28, 140])
        let outside = try XCTUnwrap(WallBrushLine(start: LotVertex(x: 0, y: 0), end: LotVertex(x: 2, y: 0)))
        XCTAssertThrowsError(try outside.geometry(scene: scene))
    }
}
