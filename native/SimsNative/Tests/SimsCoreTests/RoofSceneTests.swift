import Foundation
import XCTest
@testable import SimsCore

final class RoofSceneTests: XCTestCase {
    private func document(uv: Float = 2.25) -> [String: Any] {
        let vertices = [(0, 0), (30, 0), (0, 30)].map { ["x": Float($0.0), "y": Float($0.1), "z": 0.4, "u": uv, "v": 0.5, "nx": 0, "ny": 1, "nz": 0] }
        return ["schemaVersion": 1, "house": 5, "width": 40, "height": 40, "viewLevel": 2, "stories": 5, "roofsVisible": true,
                "textures": [["file": "roof.rgba", "width": 2, "height": 1, "encoding": "rgba"]],
                "sprites": [["texture": 0, "x": 0, "y": 0, "width": 30, "height": 30, "flip": false, "objectID": 7, "level": 1, "layer": 1, "depth": 100]],
                "meshes": [["texture": 0, "objectID": 0, "level": 2, "layer": 2, "unlit": false, "depth": 0, "vertices": vertices,
                            "roof": ["style": 0, "pitch": 0.66, "file": "roof.bmp"]]], "limitations": []]
    }
    private func scene(_ document: [String: Any]) throws -> LotScene {
        try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
    }
    func testRepeatingRoofAlphaAndDepthOcclusionMatchPicking() throws {
        let transparent = try scene(document())
        try transparent.validate()
        let pixels = Data([255, 255, 255, 0, 255, 255, 255, 255])
        XCTAssertEqual(ScenePicker(scene: transparent, pixels: [pixels]).object(at: SIMD2(8, 8)), 7)
        let opaque = try scene(document(uv: 2.75))
        try opaque.validate()
        XCTAssertNil(ScenePicker(scene: opaque, pixels: [pixels]).object(at: SIMD2(8, 8)))
        XCTAssertEqual(SceneDrawItem.ordered(in: opaque), [.sprite(0), .mesh(0)])
    }
    func testRoofMetadataCannotMasqueradeAsFloorOrDynamicGeometry() throws {
        for field in ["layer", "objectID", "unlit", "floor", "roof"] {
            var doc = document()
            var meshes = doc["meshes"] as! [[String: Any]]
            switch field {
            case "layer": meshes[0][field] = 1
            case "objectID": meshes[0][field] = 7
            case "unlit": meshes[0][field] = true
            case "floor": meshes[0][field] = ["x": 0, "y": 0, "pattern": 1, "half": 0]
            default: meshes[0][field] = ["style": 0, "pitch": 1.26, "file": "roof.bmp"]
            }
            doc["meshes"] = meshes
            XCTAssertThrowsError(try scene(doc).validate())
        }
    }
    func testAnimationRetainsRoofGeometryAndVisibility() throws {
        let base = try scene(document())
        let doc: [String: Any] = ["schemaVersion": 1, "baseRevision": 4, "sequence": 1, "updates": 3, "textureStart": 1,
                                 "textures": [], "sprites": [], "meshes": []]
        let frame = try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: doc))
        let updated = try frame.applying(to: base, revision: 4, after: 0)
        XCTAssertEqual(updated.roofsVisible, true)
        XCTAssertEqual(updated.meshes?.first?.roof?.style, 0)
        XCTAssertEqual(updated.meshes?.first?.vertices.count, 3)
    }
}
