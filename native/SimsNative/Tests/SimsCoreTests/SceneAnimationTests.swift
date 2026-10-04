import Foundation
import XCTest
@testable import SimsCore

final class SceneAnimationTests: XCTestCase {
    func testStaticFloorMaterialRejectsInvalidLayerAndAvatarIdentity() throws {
        let vertices = (0..<3).map { _ in ["x": 1, "y": 1, "z": 1, "u": 0, "v": 0, "nx": 0, "ny": 1, "nz": 0] }
        func scene(layer: Int, object: Int) throws -> LotScene {
            let document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 4, "height": 4,
                "textures": [["file": "floor.rgba", "width": 1, "height": 1]], "sprites": [],
                "meshes": [["texture": 0, "objectID": object, "layer": layer, "unlit": true, "depth": 0, "vertices": vertices]], "limitations": []]
            return try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
        }
        try scene(layer: 0, object: 0).validate()
        XCTAssertThrowsError(try scene(layer: 1, object: 0).validate())
        XCTAssertThrowsError(try scene(layer: 0, object: 42).validate())
        XCTAssertThrowsError(try scene(layer: -1, object: 0).validate())
    }

    func testAnimationReplacesDynamicGeometryAndPreservesTerrain() throws {
        let staticSprite = LotScene.Sprite(texture: 0, x: 0, y: 0, width: 1, height: 1, flip: false,
                                           objectID: 0, layer: 0, depth: 0, depthTexture: nil, depthNear: nil, depthFar: nil)
        let oldSprite = LotScene.Sprite(texture: 0, x: 2, y: 2, width: 1, height: 1, flip: false,
                                        objectID: 2, layer: 1, depth: 2, depthTexture: nil, depthNear: nil, depthFar: nil)
        let terrain = [LotScene.TerrainVertex(x: 0, y: 0, r: 0, g: 100, b: 0),
                       LotScene.TerrainVertex(x: 10, y: 0, r: 0, g: 100, b: 0),
                       LotScene.TerrainVertex(x: 0, y: 10, r: 0, g: 100, b: 0)]
        let floor = LotScene.Mesh(layer: 0, unlit: true, texture: 0, objectID: 0, depth: 0,
                                  vertices: terrain.map { LotScene.MeshVertex(x: $0.x, y: $0.y, z: 1, u: 0, v: 0, nx: 0, ny: 1, nz: 0) })
        let scene = LotScene(schemaVersion: 1, house: 5, width: 10, height: 10,
                             lotWidth: nil, lotHeight: nil,
                             textures: [.init(file: "skin.rgba", width: 1, height: 1, encoding: "rgba")],
                             sprites: [staticSprite, oldSprite], terrainVertices: terrain, terrainHeights: nil, meshes: [floor], limitations: [])
        var packed = Data()
        for coordinate: Float in [3, 4, 0.5, 0, 0, 0, 1, 0, 4, 4, 0.5, 1, 0, 0, 1, 0, 3, 5, 0.5, 0, 1, 0, 1, 0] {
            var bits = coordinate.bitPattern.littleEndian
            withUnsafeBytes(of: &bits) { packed.append(contentsOf: $0) }
        }
        var document: [String: Any] = ["schemaVersion": 1, "baseRevision": 7, "sequence": 2, "updates": 12,
            "textureStart": 1, "textures": [["file": "new.rgba", "width": 1, "height": 1, "encoding": "rgba"]],
            "sprites": [["texture": 1, "x": 5, "y": 5, "width": 1, "height": 1, "flip": false, "objectID": 4]],
            "meshes": [["texture": 0, "objectID": 3, "depth": 3, "vertices": packed.base64EncodedString()]]]
        func frame() throws -> SceneAnimation {
            try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: document))
        }
        let animation = try frame()
        let updated = try animation.applying(to: scene, revision: 7, after: 1)
        XCTAssertEqual(updated.textures.count, 2)
        XCTAssertEqual(updated.sprites.compactMap(\.objectID), [0, 4])
        XCTAssertEqual(updated.terrainVertices?.count, 3)
        XCTAssertEqual(updated.floorDiagonals, scene.floorDiagonals)
        XCTAssertEqual(updated.meshes?.count, 2)
        XCTAssertEqual(updated.meshes?.first?.objectID, 0)
        XCTAssertEqual(updated.meshes?.first?.layer, 0)
        XCTAssertEqual(updated.meshes?.first?.unlit, true)
        XCTAssertEqual(updated.meshes?.first?.vertices.map(\.x), terrain.map(\.x))
        XCTAssertEqual(updated.meshes?.last?.vertices.first?.x, 3)
        XCTAssertEqual(updated.meshes?.last?.vertices.last?.y, 5)
        XCTAssertThrowsError(try animation.applying(to: scene, revision: 8, after: 1))
        XCTAssertThrowsError(try animation.applying(to: scene, revision: 7, after: 2))
        document["textureStart"] = 0
        XCTAssertThrowsError(try frame().applying(to: scene, revision: 7, after: 1))
        document["textureStart"] = 1
        document["meshes"] = [["texture": 0, "objectID": 3, "depth": 3, "vertices": Data(packed.dropLast()).base64EncodedString()]]
        XCTAssertThrowsError(try frame().applying(to: scene, revision: 7, after: 1))
        var nan = Float.nan.bitPattern.littleEndian
        withUnsafeBytes(of: &nan) { packed.replaceSubrange(0..<4, with: $0) }
        document["meshes"] = [["texture": 0, "objectID": 3, "depth": 3, "vertices": packed.base64EncodedString()]]
        XCTAssertThrowsError(try frame().applying(to: scene, revision: 7, after: 1))
        document["meshes"] = []
        document["sprites"] = [["texture": 1, "x": 5, "y": 5, "width": 1, "height": 1, "flip": false, "objectID": 0]]
        XCTAssertThrowsError(try frame().applying(to: scene, revision: 7, after: 1))
    }
}
