import Foundation
import XCTest
@testable import SimsCore

final class DiagonalFloorPickingTests: XCTestCase {
    /// An instance for borrowing fixture helpers from other test classes; Linux XCTest has no argument-free init.
    static func fixture() -> DiagonalFloorPickingTests {
        #if canImport(ObjectiveC)
        return DiagonalFloorPickingTests()
        #else
        return DiagonalFloorPickingTests(name: "fixture", testClosure: { _ in })
        #endif
    }

    func scene(diagonal: Int) throws -> LotScene {
        let vertices = [(32, 0), (64, 16), (32, 32), (32, 32), (0, 16), (32, 0)].map { ["x": $0.0, "y": $0.1, "r": 0, "g": 0, "b": 0] }
        let document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 64, "height": 32, "lotWidth": 1, "lotHeight": 1,
            "floorDiagonals": [diagonal], "terrainVertices": vertices, "textures": [], "sprites": [], "limitations": []]
        return try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
    }
    func testBothOrientationsRouteEachCursorHalfToTheEngineSide() throws {
        for (diagonal, samples) in [(32, [(SIMD2<Float>(48, 16), 1, 1), (SIMD2<Float>(16, 16), 2, 0)]),
                                  (16, [(SIMD2<Float>(32, 8), 3, 0), (SIMD2<Float>(32, 24), 4, 2)])] {
            let scene = try scene(diagonal: diagonal)
            try scene.validate()
            let picker = try XCTUnwrap(GroundTilePicker(scene: scene))
            for (point, half, style) in samples {
                let hit = try XCTUnwrap(picker.hit(at: point))
                XCTAssertEqual(hit.tile, GroundTile(x: 0, y: 0))
                XCTAssertEqual(hit.half, half)
                XCTAssertEqual(hit.style, UInt16(style))
                let area = try XCTUnwrap(FloorBrushRectangle(start: hit.tile, end: hit.tile))
                let brush = try XCTUnwrap(FloorBrushSelection(rectangle: area, half: hit.half))
                XCTAssertEqual(brush.style, hit.style)
                XCTAssertEqual(try brush.geometry(scene: scene).count, 3)
            }
        }
    }
    func testSlopedPickingAndRectangleSkipDiagonalCells() throws {
        let points = [(32, 10), (64, 23), (32, 45), (32, 45), (0, 28), (32, 10)]
        let vertices = points.map { ["x": $0.0, "y": $0.1, "r": 0, "g": 0, "b": 0] }
        var document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 128, "height": 64, "lotWidth": 1, "lotHeight": 1,
            "floorDiagonals": [32], "terrainVertices": vertices, "textures": [], "sprites": [], "limitations": []]
        let sloped = try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
        let picker = try XCTUnwrap(GroundTilePicker(scene: sloped))
        XCTAssertEqual(picker.hit(at: SIMD2(128.0 / 3, 26))?.half, 1)
        XCTAssertEqual(picker.hit(at: SIMD2(64.0 / 3, 83.0 / 3))?.half, 2)
        document["lotWidth"] = 2
        document["floorDiagonals"] = [32, 0]
        document["terrainVertices"] = vertices + points.map { ["x": $0.0 + 64, "y": $0.1, "r": 0, "g": 0, "b": 0] }
        let twoTiles = try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
        let area = try XCTUnwrap(FloorBrushRectangle(startX: 0, startY: 0, endX: 1, endY: 0))
        let geometry = try area.geometry(scene: twoTiles)
        XCTAssertEqual(geometry.count, 6)
        XCTAssertEqual(geometry.map(\.x), points.map { Float($0.0 + 64) })
    }

    func testAnimationPreservesBlankDiagonalPickingGrid() throws {
        let scene = try scene(diagonal: 32)
        let document: [String: Any] = ["schemaVersion": 1, "baseRevision": 2, "sequence": 1, "updates": 0, "textureStart": 0, "textures": [], "sprites": [], "meshes": []]
        let frame = try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: document))
        let updated = try frame.applying(to: scene, revision: 2, after: 0)
        XCTAssertEqual(updated.floorDiagonals, [32])
        XCTAssertEqual(GroundTilePicker(scene: updated)?.hit(at: SIMD2(48, 16))?.half, 1)
    }

    func testBrushRejectsMismatchedHalfAndInvalidDiagonalGrid() throws {
        let scene = try scene(diagonal: 32)
        let area = try XCTUnwrap(FloorBrushRectangle(startX: 0, startY: 0, endX: 0, endY: 0))
        XCTAssertThrowsError(try area.geometry(scene: scene, half: 3))
        let invalid = try self.scene(diagonal: 48)
        XCTAssertThrowsError(try invalid.validate())
        XCTAssertNil(GroundTilePicker(scene: invalid))
        XCTAssertThrowsError(try area.geometry(scene: invalid, half: 1))
        XCTAssertEqual(try area.geometry(scene: self.scene(diagonal: 0)).count, 6)
    }
}
