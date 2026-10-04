import Foundation
import XCTest
@testable import SimsCore

final class ZoomSceneTests: XCTestCase {
    private func document(near: [String: Any]?, nearTexture: Int? = 3) -> [String: Any] {
        let floor: [[String: Any]] = [(0, 0), (10, 0), (0, 10), (10, 0), (10, 10), (0, 10)].map { ["x": $0.0, "y": $0.1, "z": 0.4, "u": 0, "v": 0, "nx": 0, "ny": 1, "nz": 0] }
        var sprite: [String: Any] = ["texture": 0, "x": 0, "y": 0, "width": 10, "height": 20, "flip": false, "objectID": 7, "layer": 1, "depth": 1,
                                     "depthTexture": 1, "depthNear": 0.2, "depthFar": 0.3]
        if let near { sprite["near"] = near }
        var mesh: [String: Any] = ["texture": 0, "objectID": 0, "layer": 0, "unlit": true, "depth": 0, "vertices": floor,
                                   "floor": ["x": 0, "y": 0, "pattern": 1, "half": 0]]
        if let nearTexture { mesh["nearTexture"] = nearTexture }
        return ["schemaVersion": 1, "house": 5, "width": 40, "height": 40, "lotWidth": 1, "lotHeight": 1,
                "terrainVertices": floor.map { ["x": $0["x"]!, "y": $0["y"]!, "r": 0, "g": 100, "b": 0] },
                "textures": [["file": "a.rgba", "width": 10, "height": 20, "encoding": "rgba"], ["file": "a.depth8", "width": 10, "height": 20, "encoding": "depth8"],
                             ["file": "b.depth8", "width": 22, "height": 40, "encoding": "depth8"], ["file": "b.rgba", "width": 22, "height": 40, "encoding": "rgba"]],
                "sprites": [sprite], "meshes": [mesh], "limitations": []]
    }
    private func scene(_ document: [String: Any]) throws -> LotScene {
        try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
    }

    func testZoomedArtDecodesAndIsChosenPerZoom() throws {
        let scene = try scene(document(near: ["texture": 3, "x": -0.5, "y": 0, "width": 11, "height": 20, "depthTexture": 2]))
        try scene.validate()
        XCTAssertEqual(scene.sprites[0].image(for: .near)?.texture, 3)
        XCTAssertEqual(scene.sprites[0].image(for: .near)?.x, -0.5)
        XCTAssertNil(scene.sprites[0].image(for: .medium))
        XCTAssertNil(scene.sprites[0].image(for: .far))
        XCTAssertEqual(scene.meshes?[0].texture(for: .near), 3)
        XCTAssertEqual(scene.meshes?[0].texture(for: .far), 0)
    }

    func testZoomedArtRejectsMismatchedDepthAndBadTextures() throws {
        // Depth presence must match the medium sprite, and depth must be a depth8 of the zoomed colour's size.
        XCTAssertThrowsError(try scene(document(near: ["texture": 3, "x": 0, "y": 0, "width": 11, "height": 20])).validate())
        XCTAssertThrowsError(try scene(document(near: ["texture": 3, "x": 0, "y": 0, "width": 11, "height": 20, "depthTexture": 1])).validate())
        XCTAssertThrowsError(try scene(document(near: ["texture": 2, "x": 0, "y": 0, "width": 11, "height": 20, "depthTexture": 2])).validate())
        XCTAssertThrowsError(try scene(document(near: ["texture": 3, "x": 0, "y": 0, "width": 0, "height": 20, "depthTexture": 2])).validate())
        XCTAssertThrowsError(try scene(document(near: nil, nearTexture: 2)).validate())
        XCTAssertThrowsError(try scene(document(near: nil, nearTexture: 9)).validate())
    }
}
