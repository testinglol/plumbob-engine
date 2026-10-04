import Foundation
import XCTest
@testable import SimsCore

final class PlacementPreviewTests: XCTestCase {
    func testFootprintUsesExactSlopedTerrainAndRejectsUnboundedPayloads() throws {
        let vertices = (0..<12).map { ["x": $0, "y": $0 + 1, "r": 10, "g": 20, "b": 30] }
        let sceneData = try JSONSerialization.data(withJSONObject: ["schemaVersion": 1, "house": 5, "width": 32, "height": 32, "lotWidth": 2, "lotHeight": 1, "terrainVertices": vertices, "textures": [], "sprites": [], "limitations": []])
        let scene = try JSONDecoder().decode(LotScene.self, from: sceneData)
        func preview(tiles: [[String: Int]], schema: Int = 1) throws -> PlacementPreview {
            let data = try JSONSerialization.data(withJSONObject: ["schemaVersion": schema, "valid": false, "status": "IntersectsObjects", "tiles": tiles])
            return try JSONDecoder().decode(PlacementPreview.self, from: data)
        }
        let result = try preview(tiles: [["x": 1, "y": 0, "level": 1], ["x": -1, "y": 0, "level": 1]])
        let geometry = try result.geometry(scene: scene)
        XCTAssertEqual(geometry.count, 6)
        XCTAssertEqual(geometry.map(\.x), Array(6..<12).map(Float.init))
        XCTAssertEqual(geometry.map(\.y), Array(7..<13).map(Float.init))
        for bad in [try preview(tiles: []), try preview(tiles: [["x": 256, "y": 0, "level": 1]]), try preview(tiles: [["x": 0, "y": 0, "level": 0]]), try preview(tiles: [["x": 0, "y": 0, "level": 1]], schema: 2)] {
            XCTAssertThrowsError(try bad.geometry(scene: scene))
        }
    }
}
