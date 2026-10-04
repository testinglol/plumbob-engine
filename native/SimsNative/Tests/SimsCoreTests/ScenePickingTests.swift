import Foundation
import XCTest
@testable import SimsCore

final class ScenePickingTests: XCTestCase {
    func testWallpaperTargetsVisibleOpaqueWallSurface() throws {
        let wall: [String: Any] = ["x": 0, "y": 0, "level": 1, "direction": 1]
        let surface: [String: Any] = ["texture": 0, "objectID": 0, "x": 0, "y": 0, "width": 4, "height": 1,
                                    "flip": false, "layer": 1, "depth": 0, "wall": wall]
        let object: [String: Any] = ["texture": 1, "objectID": 42, "x": 0, "y": 0, "width": 1, "height": 1,
                                   "flip": false, "layer": 1, "depth": 1]
        let vertices = (0..<6).map { _ in ["x": 0, "y": 0, "r": 0, "g": 0, "b": 0] }
        var document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 4, "height": 1, "lotWidth": 1, "lotHeight": 1,
            "terrainVertices": vertices, "textures": [["file": "wall.rgba", "width": 4, "height": 1], ["file": "object.rgba", "width": 1, "height": 1]],
            "sprites": [surface, object], "limitations": []]
        let scene = try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
        try scene.validate()
        let picker = ScenePicker(scene: scene, pixels: [Data([255,0,0,255, 255,0,0,255, 255,0,0,0, 255,0,0,255]), Data([0,255,0,255])])
        XCTAssertEqual(picker.wall(at: SIMD2(1.5, 0.5))?.direction, 1)
        XCTAssertNil(picker.object(at: SIMD2(1.5, 0.5)))
        XCTAssertNil(picker.wall(at: SIMD2(2.5, 0.5)))
        XCTAssertNil(picker.wall(at: SIMD2(0.5, 0.5)))
        XCTAssertEqual(picker.object(at: SIMD2(0.5, 0.5)), 42)
        XCTAssertNil(picker.wall(at: SIMD2(.nan, 0)))
        var invalid = surface
        invalid["wall"] = ["x": 1, "y": 0, "level": 1, "direction": 1]
        document["sprites"] = [invalid]
        let outside = try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
        XCTAssertThrowsError(try outside.validate())
    }

    func testDepthPickingAndViewportTransform() throws {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: root) }
        try Data([255,0,0,255, 255,0,0,255, 255,0,0,255, 255,0,0,0]).write(to: root.appendingPathComponent("color.rgba"))
        try Data([0,0,255,255]).write(to: root.appendingPathComponent("blue.rgba"))
        try Data([0,254,255,0]).write(to: root.appendingPathComponent("depth.depth8"))
        func vertex(_ x: Int, _ y: Int) -> [String: Any] {
            ["x":x, "y":y, "z":0.5, "u":0, "v":0, "nx":0, "ny":1, "nz":0]
        }
        let textures: [[String: Any]] = [["file":"color.rgba", "width":4, "height":1],
            ["file":"blue.rgba", "width":1, "height":1], ["file":"depth.depth8", "width":4, "height":1, "encoding":"depth8"]]
        let mesh: [String: Any] = ["texture":1, "objectID":43, "depth":1,
            "vertices":[vertex(4,4),vertex(60,4),vertex(4,60),vertex(4,60),vertex(60,4),vertex(60,60)]]
        let url = root.appendingPathComponent("scene.json")
        for flip in [false,true] {
            for order in [0,2] {
                let sprite: [String: Any] = ["texture":0, "objectID":42, "x":4, "y":4, "width":56, "height":56,
                    "flip":flip, "layer":1, "depth":order, "depthTexture":2, "depthNear":0.3, "depthFar":0.7]
                var document: [String: Any] = ["schemaVersion":1, "house":1, "width":64, "height":64,
                    "textures":textures, "sprites":[sprite], "meshes":[mesh], "limitations":[]]
                try JSONSerialization.data(withJSONObject: document).write(to: url)
                let loaded = try LotScene.load(url: url)
                let picker = ScenePicker(scene: loaded.scene, pixels: loaded.pixels)
                for (index,x) in [11,25,39,53].enumerated() {
                    let point = SIMD2<Float>(Float(x),32)
                    XCTAssertEqual(picker.object(at: point), index == (flip ? 3 : 0) ? 42 : 43)
                    for resolution: Float in [1,2] {
                        let viewport = SceneViewport(scene: loaded.scene, canvas: SIMD2(800,600)*resolution,
                            panelHeight:150*resolution, zoom:.near, uiScale:resolution, pan:SIMD2(17,-5)*resolution)
                        let restored = try XCTUnwrap(viewport.scenePoint(point*viewport.scale+viewport.origin))
                        XCTAssertEqual(restored.x, point.x, accuracy:0.0001)
                        XCTAssertEqual(restored.y, point.y, accuracy:0.0001)
                        XCTAssertEqual(picker.object(at: restored), picker.object(at: point))
                        XCTAssertNil(viewport.scenePoint(SIMD2(100,599)*resolution))
                    }
                }
                XCTAssertNil(picker.object(at: SIMD2(0,0)))
                XCTAssertNil(picker.object(at: SIMD2(.nan,32)))
                var wall = sprite
                wall["texture"] = 1
                wall["objectID"] = 0
                wall["depth"] = 3
                for key in ["depthTexture","depthNear","depthFar"] { wall[key] = nil }
                document["sprites"] = [sprite,wall]
                try JSONSerialization.data(withJSONObject: document).write(to: url)
                let blocked = try LotScene.load(url: url)
                XCTAssertNil(ScenePicker(scene: blocked.scene, pixels: blocked.pixels).object(at: SIMD2(11,32)))
            }
        }
    }
}
