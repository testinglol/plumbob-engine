import Foundation
import XCTest
@testable import SimsCore

final class SceneLightingTests: XCTestCase {
    func table(_ rooms: [[String: Any]]) throws -> SceneLighting {
        try JSONDecoder().decode(SceneLighting.self, from: JSONSerialization.data(withJSONObject:
            ["outside": ["r": 255, "g": 200, "b": 100], "rooms": rooms]))
    }

    func testLightingValidationAndLinearMaterialMultipliers() throws {
        let room: [String: Any] = ["id": 0, "outside": false, "ambient": 20, "daylight": 30, "r": 100, "g": 150, "b": 200]
        let valid = try table([room])
        try valid.validate()
        XCTAssertEqual(valid.multiplier(room: 0), SIMD4(100 / Float(255), 150 / Float(255), 200 / Float(255), 1))
        XCTAssertEqual(valid.multiplier(room: nil), SIMD4(repeating: 1))
        XCTAssertEqual(valid.multiplier(room: 65535), SIMD4(repeating: 1))
        XCTAssertThrowsError(try valid.validate(room: 1))
        for (key, value) in [("id", 1), ("ambient", -1), ("daylight", 101)] {
            var invalid = room
            invalid[key] = value
            XCTAssertThrowsError(try table([invalid]).validate())
        }
        XCTAssertThrowsError(try table([]).validate())
        var invalid = room
        invalid["r"] = 256
        XCTAssertThrowsError(try table([invalid]))
    }

    func testAnimationUpdatesLightingAndPreservesStaticRoomIdentity() throws {
        let room: [String: Any] = ["id": 0, "outside": false, "ambient": 20, "daylight": 0, "r": 100, "g": 100, "b": 100]
        let lighting = try table([room])
        let sprite = LotScene.Sprite(texture: 0, x: 0, y: 0, width: 1, height: 1, flip: false,
            objectID: 0, layer: 0, depth: 0, depthTexture: nil, depthNear: nil, depthFar: nil, room: 0)
        let scene = LotScene(schemaVersion: 1, lighting: lighting, house: 1, width: 4, height: 4, lotWidth: nil, lotHeight: nil,
            textures: [.init(file: "pixel.rgba", width: 1, height: 1, encoding: nil)], sprites: [sprite], terrainVertices: nil, terrainHeights: nil, meshes: nil, limitations: [])
        let brighter = try table([room.merging(["r": 200, "g": 200, "b": 200]) { _, new in new }])
        let frame = SceneAnimation(schemaVersion: 1, lighting: brighter, baseRevision: 1, sequence: 1, updates: 0,
            textureStart: 1, textures: [], sprites: [], meshes: [])
        let updated = try frame.applying(to: scene, revision: 1, after: 0)
        XCTAssertEqual(updated.sprites.first?.room, 0)
        XCTAssertEqual(updated.lighting?.rooms.first?.r, 200)
        let legacy = SceneAnimation(schemaVersion: 1, baseRevision: 1, sequence: 2, updates: 0, textureStart: 1, textures: [], sprites: [], meshes: [])
        XCTAssertEqual(try legacy.applying(to: updated, revision: 1, after: 1).lighting?.rooms.first?.r, 200)
    }
}
