import Foundation
import XCTest
@testable import SimsCore

final class CutawaySceneTests: XCTestCase {
    func scene(mode: String, cut: Int) throws -> LotScene { try Self.scene(mode: mode, cut: cut) }

    static func scene(mode: String, cut: Int) throws -> LotScene {
        let terrain = (0..<6).map { _ in ["x": 0, "y": 0, "r": 0, "g": 100, "b": 0] }
        let document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 4, "height": 4,
            "lotWidth": 1, "lotHeight": 1, "wallMode": mode, "terrainVertices": terrain,
            "textures": [["file": "wall.rgba", "width": 1, "height": 1]],
            "sprites": [["texture": 0, "x": 0, "y": 0, "width": 1, "height": 1, "flip": false, "objectID": 0, "layer": 1,
                "wall": ["x": 0, "y": 0, "level": 1, "direction": 0, "cut": cut]]], "limitations": []]
        return try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
    }

    func testWallCutModesAndShapeBounds() throws {
        for mode in ["up", "down", "cutaway"] {
            for cut in 0...3 { try scene(mode: mode, cut: cut).validate() }
        }
        XCTAssertThrowsError(try scene(mode: "unknown", cut: 0).validate())
        XCTAssertThrowsError(try scene(mode: "cutaway", cut: -1).validate())
        XCTAssertThrowsError(try scene(mode: "cutaway", cut: 4).validate())
    }

    func testAnimationPreservesStaticCutawayWalls() throws {
        let scene = try scene(mode: "cutaway", cut: 2)
        let frame = SceneAnimation(schemaVersion: 1, baseRevision: 1, sequence: 1, updates: 0,
            textureStart: 1, textures: [], sprites: [], meshes: [])
        let updated = try frame.applying(to: scene, revision: 1, after: 0)
        XCTAssertEqual(updated.wallMode, "cutaway")
        XCTAssertEqual(updated.sprites.first?.wall?.cut, 2)
    }
}

final class AnimationValidationTests: XCTestCase {
    private func frame(spriteX: Double) throws -> SceneAnimation {
        let document: [String: Any] = ["schemaVersion": 1, "baseRevision": 1, "sequence": 1, "updates": 0, "textureStart": 1,
            "textures": [], "meshes": [],
            "sprites": [["texture": 0, "x": spriteX, "y": 0, "width": 1, "height": 1, "flip": false, "objectID": 5, "layer": 1]]]
        return try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: document))
    }

    /// Frames skip re-validating the snapshot they extend, but their own sprites are still checked.
    func testAnimatedSpritesAreValidatedAgainstTheScene() throws {
        let scene = try CutawaySceneTests.scene(mode: "up", cut: 0)
        XCTAssertEqual(try frame(spriteX: 1).applying(to: scene, revision: 1, after: 0).sprites.count, 2)
        XCTAssertThrowsError(try frame(spriteX: 10).applying(to: scene, revision: 1, after: 0))
    }
}
