import Foundation
import XCTest
@testable import SimsCore

final class SpriteDepthTests: XCTestCase {
    func testDepthTexturesAreBoundedAndMustMatchColorDimensions() throws {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: root) }
        try Data(repeating: 255, count: 16).write(to: root.appendingPathComponent("color.rgba"))
        let depth = Data([0, 127, 254, 255])
        let depthURL = root.appendingPathComponent("pixels.depth8")
        try depth.write(to: depthURL)
        let url = root.appendingPathComponent("scene.json")
        var sprite: [String: Any] = ["texture": 0, "x": 0, "y": 0, "width": 32, "height": 16, "flip": true,
                                   "depthTexture": 1, "depthNear": 0.3, "depthFar": 0.7]
        var textures: [[String: Any]] = [
            ["file": "color.rgba", "width": 4, "height": 1, "encoding": "rgba"],
            ["file": "pixels.depth8", "width": 4, "height": 1, "encoding": "depth8"]]
        func save() throws {
            let document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 32, "height": 16,
                                          "textures": textures, "sprites": [sprite], "limitations": []]
            try JSONSerialization.data(withJSONObject: document).write(to: url)
        }
        try save()
        let loaded = try LotScene.load(url: url)
        XCTAssertEqual(loaded.pixels[1], depth)
        XCTAssertEqual(loaded.scene.sprites[0].depthTexture, 1)
        try Data([0, 127, 254]).write(to: depthURL)
        XCTAssertThrowsError(try LotScene.load(url: url))
        try depth.write(to: depthURL)
        textures[1]["width"] = 2
        textures[1]["height"] = 2
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        textures[1]["width"] = 4
        textures[1]["height"] = 1
        sprite["depthTexture"] = 2
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        sprite["depthTexture"] = 0
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        sprite["depthTexture"] = 1
        for pair in [(0.8, 0.7), (-0.1, 0.7), (0.3, 1.1)] {
            sprite["depthNear"] = pair.0
            sprite["depthFar"] = pair.1
            try save()
            XCTAssertThrowsError(try LotScene.load(url: url))
        }
        sprite["depthNear"] = 0.3
        sprite["depthFar"] = nil
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        sprite["depthFar"] = 0.7
        sprite["depthTexture"] = nil
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
        sprite["depthNear"] = nil
        sprite["depthFar"] = nil
        try save()
        XCTAssertNil(try LotScene.load(url: url).scene.sprites[0].depthTexture)
        sprite["texture"] = 1
        try save()
        XCTAssertThrowsError(try LotScene.load(url: url))
    }
}
