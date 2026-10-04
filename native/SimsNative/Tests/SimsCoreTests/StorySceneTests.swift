import Foundation
import XCTest
@testable import SimsCore

final class StorySceneTests: XCTestCase {
    private func document() -> [String: Any] {
        let ground: [[String: Any]] = [(10, 20), (20, 25), (10, 30), (10, 30), (0, 25), (10, 20)].map { ["x": $0.0, "y": $0.1, "r": 0, "g": 100, "b": 0] }
        let upper = ground.map { vertex -> [String: Any] in var result = vertex; result["y"] = (vertex["y"] as! Int) - 10; return result }
        let floor = upper.map { ["x": $0["x"]!, "y": $0["y"]!, "z": 0.4, "u": 0, "v": 0, "nx": 0, "ny": 1, "nz": 0] }
        return ["schemaVersion": 1, "house": 5, "width": 40, "height": 40, "lotWidth": 1, "lotHeight": 1,
                "viewLevel": 2, "stories": 5, "terrainVertices": ground, "placementVertices": upper, "floorDiagonals": [0],
                "textures": [["file": "floor.rgba", "width": 1, "height": 1, "encoding": "rgba"]],
                "sprites": [["texture": 0, "x": 0, "y": 0, "width": 30, "height": 30, "flip": false, "objectID": 7, "level": 1, "layer": 1, "depth": 100]],
                "meshes": [["texture": 0, "objectID": 0, "level": 2, "layer": 0, "unlit": true, "depth": 0, "vertices": floor,
                            "floor": ["x": 0, "y": 0, "pattern": 1, "half": 0, "level": 2]]], "limitations": []]
    }
    private func scene(_ document: [String: Any]) throws -> LotScene {
        try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
    }
    func testUpperFloorOccludesLowerObjectsAndPickingUsesSelectedPlane() throws {
        let scene = try scene(document())
        try scene.validate()
        XCTAssertEqual(SceneDrawItem.ordered(in: scene), [.sprite(0), .mesh(0)])
        let picker = try XCTUnwrap(GroundTilePicker(scene: scene))
        XCTAssertEqual(picker.tile(at: SIMD2(10, 15)), GroundTile(x: 0, y: 0))
        XCTAssertNil(picker.tile(at: SIMD2(10, 25)))
        let brush = try XCTUnwrap(FloorBrushRectangle(start: GroundTile(x: 0, y: 0), end: GroundTile(x: 0, y: 0)))
        XCTAssertEqual(try brush.geometry(scene: scene).map(\.y), scene.placementVertices?.map(\.y))
        let objects = ScenePicker(scene: scene, pixels: [Data([255, 255, 255, 255])])
        XCTAssertNil(objects.object(at: SIMD2(10, 15)))
        XCTAssertEqual(objects.object(at: SIMD2(10, 25)), 7)
    }
    func testStoryMetadataRejectsHiddenGeometryAndInvalidConstructionBounds() throws {
        var doc = document()
        doc["viewLevel"] = 1
        XCTAssertThrowsError(try scene(doc).validate())
        doc = document()
        doc["stories"] = 1
        XCTAssertThrowsError(try scene(doc).validate())
        doc = document()
        var vertices = doc["placementVertices"] as! [[String: Any]]
        vertices[0]["y"] = -1
        doc["placementVertices"] = vertices
        XCTAssertThrowsError(try scene(doc).validate())
        doc = document()
        var meshes = doc["meshes"] as! [[String: Any]]
        meshes[0]["level"] = 1
        doc["meshes"] = meshes
        XCTAssertThrowsError(try scene(doc).validate())
    }
    func testAnimationPreservesStoryAndConstructionPlane() throws {
        let base = try scene(document())
        var bytes = Data()
        for value: Float in [8, 14, 0.3, 0, 0, 0, 1, 0, 12, 14, 0.3, 0, 0, 0, 1, 0, 10, 18, 0.3, 0, 0, 0, 1, 0] {
            var bits = value.bitPattern.littleEndian
            withUnsafeBytes(of: &bits) { bytes.append(contentsOf: $0) }
        }
        let doc: [String: Any] = ["schemaVersion": 1, "baseRevision": 4, "sequence": 1, "updates": 3, "textureStart": 1,
                                 "textures": [], "sprites": [], "meshes": [["texture": 0, "objectID": 9, "level": 2, "depth": 0, "vertices": bytes.base64EncodedString()]]]
        let frame = try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: doc))
        let updated = try frame.applying(to: base, revision: 4, after: 0)
        XCTAssertEqual(updated.viewLevel, 2)
        XCTAssertEqual(updated.stories, 5)
        XCTAssertEqual(updated.placementVertices?.map(\.y), base.placementVertices?.map(\.y))
        XCTAssertEqual(updated.meshes?.last?.level, 2)
        XCTAssertEqual(ScenePicker(scene: updated, pixels: [Data([255, 255, 255, 255])]).object(at: SIMD2(10, 15)), 9)
    }
}
