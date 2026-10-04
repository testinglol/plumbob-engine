import Foundation
import XCTest
@testable import SimsCore

final class LotSceneTests: XCTestCase {
    func testJunctionMetadataRequiresStaticArchitectureAndDepth() throws {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: root) }
        try Data([255, 255, 255, 255]).write(to: root.appendingPathComponent("pixel.rgba"))
        try Data([254]).write(to: root.appendingPathComponent("pixel.depth8"))
        let url = root.appendingPathComponent("scene.json")
        var junction: [String: Any] = ["x": 1, "y": 1, "level": 1, "flags": 3, "frame": 2, "down": false]
        var sprite: [String: Any] = ["texture": 0, "x": 0, "y": 0, "width": 1, "height": 1, "flip": false,
            "objectID": 0, "layer": 1, "level": 1, "depthTexture": 1, "depthNear": 0.4, "depthFar": 0.5]
        func save() throws {
            sprite["junction"] = junction
            let document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 32, "height": 16,
                "lotWidth": 4, "lotHeight": 4, "terrainVertices": Array(repeating: ["x": 0, "y": 0, "r": 0, "g": 0, "b": 0], count: 96),
                "limitations": [], "sprites": [sprite], "textures": [
                    ["file": "pixel.rgba", "width": 1, "height": 1],
                    ["file": "pixel.depth8", "width": 1, "height": 1, "encoding": "depth8"]]]
            try JSONSerialization.data(withJSONObject: document).write(to: url)
        }
        try save()
        XCTAssertEqual(try LotScene.load(url: url).scene.sprites.first?.junction?.frame, 2)
        junction["frame"] = 46
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        junction["frame"] = 2
        junction["x"] = 4
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        junction["x"] = 1
        sprite["objectID"] = 7
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        sprite["objectID"] = 0
        sprite.removeValue(forKey: "depthTexture")
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        sprite["depthTexture"] = 1
        sprite["architectureDepth"] = ["x": 1, "y": 1, "level": 1, "configuration": 4]
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        sprite.removeValue(forKey: "junction")
        func saveWall() throws {
            let document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 32, "height": 16,
                "lotWidth": 4, "lotHeight": 4, "terrainVertices": Array(repeating: ["x": 0, "y": 0, "r": 0, "g": 0, "b": 0], count: 96),
                "limitations": [], "sprites": [sprite], "textures": [
                    ["file": "pixel.rgba", "width": 1, "height": 1],
                    ["file": "pixel.depth8", "width": 1, "height": 1, "encoding": "depth8"]]]
            try JSONSerialization.data(withJSONObject: document).write(to: url)
        }
        try saveWall()
        let scene = try LotScene.load(url: url).scene
        XCTAssertEqual(scene.sprites.first?.architectureDepth?.configuration, 4)
        let animation = try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject:
            ["schemaVersion": 1, "baseRevision": 1, "sequence": 1, "updates": 1, "textureStart": 2, "textures": [], "sprites": [], "meshes": []]))
        XCTAssertEqual(try animation.applying(to: scene, revision: 1, after: 0).sprites.first?.architectureDepth, scene.sprites.first?.architectureDepth)
        sprite["architectureDepth"] = ["x": 1, "y": 1, "level": 1, "configuration": 8]
        try saveWall()
        XCTAssertThrowsError(try LotScene.load(url: url))
        sprite["architectureDepth"] = ["x": 1, "y": 1, "level": 1, "configuration": 4]
        sprite["wall"] = ["x": 2, "y": 1, "level": 1, "direction": 0]
        try saveWall()
        XCTAssertThrowsError(try LotScene.load(url: url))
    }

    func testAvatarMeshesValidateDepthTexturesAndTriangleBounds() throws {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: root) }
        try Data([255, 0, 0, 255]).write(to: root.appendingPathComponent("pixel.rgba"))
        let url = root.appendingPathComponent("scene.json")
        let vertex: [String: Float] = ["x": 0, "y": 0, "z": 0.5, "u": 0, "v": 0, "nx": 0, "ny": 1, "nz": 0]
        var mesh: [String: Any] = ["texture": 0, "objectID": 3, "depth": 1, "vertices": [vertex, vertex, vertex]]
        var document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 32, "height": 16,
            "limitations": [], "textures": [["file": "pixel.rgba", "width": 1, "height": 1]], "sprites": []]
        func save() throws {
            document["meshes"] = [mesh]
            try JSONSerialization.data(withJSONObject: document).write(to: url)
        }
        try save()
        XCTAssertEqual(try LotScene.load(url: url).scene.meshes?.first?.objectID, 3)
        mesh["texture"] = 1
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        mesh["texture"] = 0
        var escaping = vertex
        escaping["z"] = 1.1
        mesh["vertices"] = [vertex, vertex, escaping]
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        mesh["vertices"] = [vertex, vertex]
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
    }

    func testTerrainGeometryRejectsIncompleteTrianglesAndEscapingVertices() throws {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: root) }
        let url = root.appendingPathComponent("scene.json")
        var document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 32, "height": 16,
            "limitations": [], "textures": [], "sprites": [], "terrainVertices": [
                ["x": 16, "y": 0, "r": 80, "g": 116, "b": 59],
                ["x": 32, "y": 8, "r": 80, "g": 116, "b": 59],
                ["x": 0, "y": 8, "r": 80, "g": 116, "b": 59]]]
        func save() throws { try JSONSerialization.data(withJSONObject: document).write(to: url) }
        try save()
        XCTAssertEqual(try LotScene.load(url: url).scene.terrainVertices?.count, 3)
        var vertices = document["terrainVertices"] as! [[String: Int]]
        vertices[0]["x"] = -1
        document["terrainVertices"] = vertices
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        vertices[0]["x"] = 16
        vertices.removeLast()
        document["terrainVertices"] = vertices
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
    }

    func testScenePixelsAndBoundsAreValidated() throws {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: root) }
        let pixels = Data([255, 0, 0, 255])
        let texture = root.appendingPathComponent("pixel.rgba")
        try pixels.write(to: texture)
        var document: [String: Any] = [
            "schemaVersion": 1, "house": 1, "width": 1, "height": 1, "limitations": [],
            "textures": [["file": "pixel.rgba", "width": 1, "height": 1]],
            "sprites": [["texture": 0, "x": 0, "y": 0, "width": 1, "height": 1, "flip": false]]
        ]
        let url = root.appendingPathComponent("scene.json")
        func save() throws { try JSONSerialization.data(withJSONObject: document).write(to: url) }
        try save()
        XCTAssertEqual(try LotScene.load(url: url).pixels, [pixels])
        try Data([255]).write(to: texture)
        XCTAssertThrowsError(try LotScene.load(url: url))
        try pixels.write(to: texture)
        document["sprites"] = [["texture": 1, "x": 0, "y": 0, "width": 1, "height": 1, "flip": false]]
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        document["textures"] = [["file": "../pixel.rgba", "width": 1, "height": 1]]
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
    }
}
