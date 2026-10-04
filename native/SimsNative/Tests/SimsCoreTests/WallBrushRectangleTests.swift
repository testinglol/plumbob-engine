import XCTest
@testable import SimsCore

final class WallBrushRectangleTests: XCTestCase {
    func testRoomPerimeterAndReverseDrags() throws {
        let area = try XCTUnwrap(WallBrushRectangle(start: LotVertex(x: 3, y: 5), end: LotVertex(x: 6, y: 7)))
        for (start, end) in [(LotVertex(x: 6, y: 7), LotVertex(x: 3, y: 5)), (LotVertex(x: 6, y: 5), LotVertex(x: 3, y: 7))] {
            XCTAssertEqual(WallBrushRectangle(start: start, end: end), area)
        }
        XCTAssertEqual(area.segmentCount, 10)
        XCTAssertEqual(area.lines.map(\.direction), [0, 2, 0, 2])
        XCTAssertEqual(area.lines.map(\.length), [3, 2, 3, 2])
        XCTAssertEqual(area.lines.map(\.start), [LotVertex(x: 3, y: 5), LotVertex(x: 3, y: 5), LotVertex(x: 3, y: 7), LotVertex(x: 6, y: 5)])
        XCTAssertNil(WallBrushRectangle(start: LotVertex(x: 0, y: 0), end: LotVertex(x: 0, y: 5)))
        XCTAssertNil(WallBrushRectangle(start: LotVertex(x: 0, y: 0), end: LotVertex(x: Int.max, y: 5)))
    }

    func testGestureModesRouteToCanonicalCommands() throws {
        let start = LotVertex(x: 6, y: 7), end = LotVertex(x: 3, y: 5)
        let rectangle = try XCTUnwrap(WallBrushSelection(start: start, end: end, rectangle: true, deleting: false))
        XCTAssertEqual(rectangle.command, "WALL_RECT")
        XCTAssertEqual(rectangle.arguments.x, 3)
        XCTAssertEqual(rectangle.arguments.y, 5)
        XCTAssertEqual(rectangle.arguments.x2, 3)
        XCTAssertEqual(rectangle.arguments.y2, 2)
        let deletion = try XCTUnwrap(WallBrushSelection(start: start, end: end, rectangle: true, deleting: true))
        XCTAssertEqual(deletion.command, "WALL_DELETE")
        XCTAssertTrue(deletion.deleting)
        XCTAssertEqual(deletion.arguments.x, 6)
        XCTAssertEqual(deletion.arguments.y, 7)
        XCTAssertEqual(deletion.arguments.x2, 3)
        XCTAssertEqual(deletion.arguments.y2, 5)
        XCTAssertEqual(WallBrushSelection(start: start, end: end, rectangle: false, deleting: false)?.command, "WALL_LINE")
    }
}
