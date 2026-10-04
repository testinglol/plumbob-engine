import XCTest
@testable import SimsCore

final class BuildRoomFillTests: XCTestCase {
    func testRemovalUsesZeroWithoutRequiringCatalogSelection() throws {
        let tile = GroundTile(x: 8, y: 9)
        for kind in [BuildCatalogPage.Kind.floor, .wall] {
            let fill = try XCTUnwrap(BuildRoomFill(kind: kind, pattern: 0, tile: tile, wall: nil, removing: true))
            XCTAssertEqual(fill.pattern, 0)
            XCTAssertEqual(fill.command, kind == .floor ? "FLOOR_FILL" : "PATTERN_FILL")
        }
        XCTAssertEqual(BuildRoomFill(kind: .floor, pattern: 256, tile: tile, wall: nil, removing: true)?.pattern, 0)
        XCTAssertNil(BuildRoomFill(kind: .wallStyle, pattern: 0, tile: tile, wall: nil, removing: true))
    }

    func testFloorAndWallpaperUseTheirOwnRoomSeeds() throws {
        let tile = GroundTile(x: 8, y: 9)
        let wall = LotScene.WallSide(x: 4, y: 5, level: 1, direction: 0)
        let floor = try XCTUnwrap(BuildRoomFill(kind: .floor, pattern: 256, tile: tile, wall: wall))
        XCTAssertEqual(floor.command, "FLOOR_FILL")
        XCTAssertEqual(floor.x, 8)
        XCTAssertEqual(floor.y, 9)
        XCTAssertEqual(floor.pattern, 256)
        let wallpaper = try XCTUnwrap(BuildRoomFill(kind: .wall, pattern: 256, tile: tile, wall: wall))
        XCTAssertEqual(wallpaper.command, "PATTERN_FILL")
        XCTAssertEqual(wallpaper.x, 4)
        XCTAssertEqual(wallpaper.y, 5)
        XCTAssertEqual(BuildRoomFill(kind: .wall, pattern: 1, tile: tile, wall: nil)?.x, 8)
        XCTAssertNil(BuildRoomFill(kind: .wallStyle, pattern: 1, tile: tile, wall: wall))
        XCTAssertNil(BuildRoomFill(kind: .floor, pattern: 1, tile: nil, wall: wall))
        XCTAssertNil(BuildRoomFill(kind: .wall, pattern: 0, tile: tile, wall: wall))
        XCTAssertNil(BuildRoomFill(kind: .floor, pattern: 65534, tile: tile, wall: nil))
        XCTAssertNil(BuildRoomFill(kind: .wall, pattern: 1, tile: nil, wall: LotScene.WallSide(x: 128, y: 0, level: 1, direction: 0)))
        XCTAssertEqual(BuildRoomFill(kind: .wall, pattern: 1, tile: nil, wall: LotScene.WallSide(x: 0, y: 0, level: 2, direction: 0))?.level, 2)
        XCTAssertEqual(BuildRoomFill(kind: .floor, pattern: 1, tile: tile, wall: nil, selectedLevel: 2)?.level, 2)
        XCTAssertNil(BuildRoomFill(kind: .floor, pattern: 1, tile: tile, wall: nil, selectedLevel: 6))
    }
}
