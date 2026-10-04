import Foundation
import XCTest
@testable import SimsCore

final class GroundTilePickerTests: XCTestCase {
    func document(sloped: Bool = false) -> [String: Any] {
        func corner(_ x: Int, _ y: Int) -> [String: Any] {
            ["x": 64 + (x - y) * 32, "y": 32 + (x + y) * 16 - (sloped ? x * 4 + y * 2 : 0), "r": 0, "g": 100, "b": 0]
        }
        var vertices: [[String: Any]] = []
        for y in 0..<2 {
            for x in 0..<2 {
                let top = corner(x, y), right = corner(x + 1, y), bottom = corner(x + 1, y + 1), left = corner(x, y + 1)
                vertices += [top, right, bottom, bottom, left, top]
            }
        }
        return ["schemaVersion": 1, "house": 5, "width": 128, "height": 128, "lotWidth": 2, "lotHeight": 2,
                "terrainVertices": vertices, "textures": [], "sprites": [], "limitations": []]
    }
    func scene(_ document: [String: Any]) throws -> LotScene {
        try JSONDecoder().decode(LotScene.self, from: JSONSerialization.data(withJSONObject: document))
    }

    func testGroundPlacementTracksTerrainZoomPanAndRetinaScale() throws {
        for sloped in [false, true] {
            let scene = try scene(document(sloped: sloped))
            try scene.validate()
            let picker = try XCTUnwrap(GroundTilePicker(scene: scene))
            let vertices = try XCTUnwrap(scene.terrainVertices)
            for y in 0..<2 {
                for x in 0..<2 {
                    let start = (y * 2 + x) * 6
                    let corners = [vertices[start], vertices[start + 1], vertices[start + 2], vertices[start + 4]]
                    let center = corners.reduce(SIMD2<Float>.zero) { $0 + SIMD2($1.x, $1.y) } / 4
                    for scale: Float in [1, 2] {
                        for zoom in LotZoom.allCases {
                            let viewport = SceneViewport(scene: scene, canvas: SIMD2(800, 600) * scale, panelHeight: 150 * scale,
                                                         zoom: zoom, uiScale: scale, pan: SIMD2(17, -5) * scale)
                            let point = center * viewport.scale + viewport.origin
                            let restored = try XCTUnwrap(viewport.scenePoint(point))
                            let tile = try XCTUnwrap(picker.tile(at: restored))
                            XCTAssertEqual(tile.x, x)
                            XCTAssertEqual(tile.y, y)
                            XCTAssertEqual(tile.placementX, x * 16 + 8)
                            XCTAssertEqual(tile.placementY, y * 16 + 8)
                            XCTAssertNil(viewport.scenePoint(SIMD2(50, 500) * scale))
                        }
                    }
                }
            }
            XCTAssertNil(picker.tile(at: SIMD2(.nan, 0)))
            XCTAssertNil(picker.tile(at: SIMD2(-100, -100)))
        }
        let picker = try XCTUnwrap(GroundTilePicker(scene: scene(document())))
        let boundary = try XCTUnwrap(picker.tile(at: SIMD2(64, 64)))
        XCTAssertEqual(boundary.x, 1)
        XCTAssertEqual(boundary.y, 1)
    }

    func testRejectsIncompleteTerrainMetadataAndPreservesItAcrossAnimation() throws {
        var malformed = document()
        malformed["lotWidth"] = 3
        XCTAssertThrowsError(try scene(malformed).validate())
        XCTAssertNil(GroundTilePicker(scene: try scene(malformed)))
        malformed = document()
        malformed["lotHeight"] = nil
        XCTAssertThrowsError(try scene(malformed).validate())
        malformed["lotWidth"] = nil
        try scene(malformed).validate()
        XCTAssertNil(GroundTilePicker(scene: try scene(malformed)))
        let original = try scene(document())
        let frame: [String: Any] = ["schemaVersion": 1, "baseRevision": 1, "sequence": 1, "updates": 0,
                                    "textureStart": 0, "textures": [], "sprites": [], "meshes": []]
        let animation = try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: frame))
        let updated = try animation.applying(to: original, revision: 1, after: 0)
        XCTAssertEqual(updated.lotWidth, 2)
        XCTAssertEqual(updated.lotHeight, 2)
        XCTAssertNotNil(GroundTilePicker(scene: updated))
    }

    func testZoomLevelsMatchTheOriginalViewAndKeepPixelsWhole() throws {
        XCTAssertEqual(LotZoom.allCases.map(\.factor), [0.5, 1, 2])
        XCTAssertEqual(LotZoom.allCases.map(\.soundGain), [1 / 3, 1 / 2, 1])
        XCTAssertEqual(LotZoom.medium.stepped(1), .near)
        XCTAssertEqual(LotZoom.near.stepped(1), .near)
        XCTAssertEqual(LotZoom.near.stepped(-5), .far)
        let scene = try scene(document())
        for uiScale: Float in [1, 2] {
            for zoom in LotZoom.allCases {
                let viewport = SceneViewport(scene: scene, canvas: SIMD2(801, 601), panelHeight: 150, zoom: zoom,
                                             uiScale: uiScale, pan: SIMD2(17.3, -5.6))
                XCTAssertEqual(viewport.scale, uiScale * zoom.factor)
                XCTAssertEqual(viewport.origin, viewport.origin.rounded(.toNearestOrEven))
            }
        }
        let limit = SIMD2(scene.width, scene.height)
        XCTAssertEqual(SceneViewport.clampedPan(SIMD2(1e6, -1e6), scene: scene, scale: 2), SIMD2(limit.x, -limit.y))
        XCTAssertEqual(SceneViewport.rescaledPan(SIMD2(10, -4), from: 1, to: 2), SIMD2(20, -8))
        let medium = SceneViewport(scene: scene, canvas: SIMD2(800, 600), panelHeight: 150, zoom: .medium, uiScale: 1, pan: SIMD2(10, -4))
        let near = SceneViewport(scene: scene, canvas: SIMD2(800, 600), panelHeight: 150, zoom: .near, uiScale: 1,
                                 pan: SceneViewport.rescaledPan(SIMD2(10, -4), from: medium.scale, to: 2))
        let centre = medium.size / 2
        let a = try XCTUnwrap(medium.scenePoint(centre)), b = try XCTUnwrap(near.scenePoint(centre))
        XCTAssertEqual(a.x, b.x, accuracy: 1)
        XCTAssertEqual(a.y, b.y, accuracy: 1)
    }
}
