import Foundation
import XCTest
@testable import SimsCore

final class TerrainBrushRequestTests: XCTestCase {
    func testHeightDragUsesSceneProjectionScale() throws {
        XCTAssertEqual(try TerrainHeightDrag.delta(startY: 100, endY: 91, viewportScale: 4, mode: .raise), 3)
        XCTAssertEqual(try TerrainHeightDrag.delta(startY: 100, endY: 91, viewportScale: 4, mode: .lower), -3)
        XCTAssertEqual(try TerrainHeightDrag.delta(startY: 91, endY: 100, viewportScale: 4, mode: .raise), -3)
        XCTAssertEqual(try TerrainHeightDrag.delta(startY: 100, endY: 100, viewportScale: 4, mode: .raise), 0)
        XCTAssertEqual(try TerrainHeightDrag.delta(startY: 200, endY: 182, viewportScale: 8, mode: .raise), 3)
        XCTAssertThrowsError(try TerrainHeightDrag.delta(startY: 0, endY: 10, viewportScale: 0, mode: .raise))
    }

    func testBrushModesProduceCanonicalArchitectureCommands() throws {
        let scene = try makeScene(heights: [0, 10, 20, 30, 40, 50, 60, 70])
        let start = GroundTile(x: 1, y: 0)
        let raised = try TerrainBrushRequest.make(mode: .raise, start: start, end: nil, level: 1, scene: scene, heightDelta: 10)
        XCTAssertEqual(raised, ArchitectureCommandRequest(command: "TERRAIN_RAISE", x: 1, y: 0, level: 1, x2: 0, y2: 0, pattern: 0, style: 20))
        let flattened = try TerrainBrushRequest.make(mode: .level, start: GroundTile(x: 3, y: 1), end: GroundTile(x: 0, y: 0), level: 1, scene: scene, smooth: true)
        XCTAssertEqual(flattened, ArchitectureCommandRequest(command: "TERRAIN_FLATTEN", x: 0, y: 0, level: 1, x2: 3, y2: 1, pattern: 1, style: 70))
        let grass = try TerrainBrushRequest.make(mode: .grass, start: start, end: nil, level: 1, scene: scene)
        XCTAssertEqual(grass, ArchitectureCommandRequest(command: "GRASS_DOT", x: 1, y: 0, level: 1, x2: 0, y2: 0, pattern: 32, style: 0))
        let encoded = try JSONEncoder().encode(raised)
        let object = try XCTUnwrap(JSONSerialization.jsonObject(with: encoded) as? [String: Any])
        XCTAssertEqual(object["command"] as? String, "TERRAIN_RAISE")
        XCTAssertEqual(object["style"] as? Int, 20)
        XCTAssertEqual(raised.payload["command"] as? String, "TERRAIN_RAISE")
        XCTAssertEqual(raised.payload["pattern"] as? UInt16, 0)
    }

    func testBrushRejectsMissingOrOutOfRangeHeightGrid() throws {
        let scene = try makeScene(heights: [0, 0, 0, 0, 0, 0, 0, 0])
        XCTAssertThrowsError(try TerrainBrushRequest.make(mode: .level, start: GroundTile(x: 0, y: 0), end: nil, level: 1, scene: scene))
        XCTAssertThrowsError(try TerrainBrushRequest.make(mode: .raise, start: GroundTile(x: 4, y: 0), end: nil, level: 1, scene: scene, heightDelta: 10))
        let clamped = try TerrainBrushRequest.make(mode: .raise, start: GroundTile(x: 0, y: 0), end: nil, level: 1, scene: scene, heightDelta: .max)
        XCTAssertEqual(clamped.style, 64)
        let lowered = try TerrainBrushRequest.make(mode: .lower, start: GroundTile(x: 1, y: 0), end: nil, level: 1, scene: scene, heightDelta: .min)
        XCTAssertEqual(lowered.style, 0)
        let missingGrid = try makeScene(heights: nil)
        XCTAssertThrowsError(try TerrainBrushRequest.make(mode: .raise, start: GroundTile(x: 0, y: 0), end: nil, level: 1, scene: missingGrid, heightDelta: 10))
    }

    func testGestureBuildsRectangleAndResetsAfterFinish() throws {
        let scene = try makeScene(heights: [0, 10, 20, 30, 40, 50, 60, 70])
        var gesture = TerrainBrushGesture()
        XCTAssertThrowsError(try gesture.finish(mode: .level, level: 1, scene: scene))
        gesture.begin(at: GroundTile(x: 1, y: 1))
        gesture.cancel()
        XCTAssertThrowsError(try gesture.finishStroke(mode: .grass, level: 1, scene: scene))
        gesture.begin(at: GroundTile(x: 3, y: 1))
        gesture.move(to: GroundTile(x: 2, y: 1))
        gesture.move(to: GroundTile(x: 0, y: 0))
        let request = try gesture.finishStroke(mode: .level, level: 1, scene: scene)[0]
        XCTAssertEqual(request.command, "TERRAIN_FLATTEN")
        XCTAssertEqual([request.x, request.y, request.x2, request.y2], [0, 0, 3, 1])
        XCTAssertEqual(request.style, 70)
        XCTAssertThrowsError(try gesture.finish(mode: .level, level: 1, scene: scene))
    }

    func testStrokeRetainsEveryDistinctSample() throws {
        let scene = try makeScene(heights: [0, 10, 20, 30, 40, 50, 60, 70])
        var gesture = TerrainBrushGesture()
        gesture.begin(at: GroundTile(x: 0, y: 0))
        gesture.move(to: GroundTile(x: 3, y: 1))
        gesture.move(to: GroundTile(x: 3, y: 1))
        let requests = try gesture.finishStroke(mode: .grass, level: 1, scene: scene)
        XCTAssertEqual(requests.map(\.x), [0, 1, 2, 3])
        XCTAssertEqual(requests.map(\.y), [0, 0, 1, 1])
    }

    private func makeScene(heights: [Int16]?) throws -> LotScene {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: root) }
        let url = root.appendingPathComponent("scene.json")
        var document: [String: Any] = ["schemaVersion": 1, "house": 1, "width": 32, "height": 16,
            "lotWidth": 4, "lotHeight": 2, "stories": 1,
            "terrainVertices": (0..<48).map { _ in ["x": 0, "y": 0, "r": 0, "g": 0, "b": 0] },
            "limitations": [], "textures": [], "sprites": []]
        if let heights { document["terrainHeights"] = heights }
        try JSONSerialization.data(withJSONObject: document).write(to: url)
        return try LotScene.load(url: url).scene
    }
}
