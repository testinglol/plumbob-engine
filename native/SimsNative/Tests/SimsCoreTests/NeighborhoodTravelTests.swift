import XCTest
@testable import SimsCore

final class NeighborhoodTravelTests: XCTestCase {
    func testOriginalTravelDialogModes() {
        XCTAssertEqual(NeighborhoodTravel.mode(forDialogKind: 5), 2)
        XCTAssertEqual(NeighborhoodTravel.mode(forDialogKind: 7), 3)
        XCTAssertEqual(NeighborhoodTravel.mode(forDialogKind: 8), 4)
        XCTAssertEqual(NeighborhoodTravel.mode(forDialogKind: 11), 5)
        XCTAssertEqual(NeighborhoodTravel.mode(forDialogKind: 13), 7)
        XCTAssertNil(NeighborhoodTravel.mode(forDialogKind: 6))
        XCTAssertNil(NeighborhoodTravel.mode(forDialogKind: 10))
    }

    func testHouseAndReturnHomeResponsesMatchOriginalDialog() {
        XCTAssertEqual(NeighborhoodTravel.response(forDestination: 21), .init(code: 1, text: "21"))
        XCTAssertEqual(NeighborhoodTravel.response(forDestination: -1), .init(code: 0, text: "-1"))
        XCTAssertNil(NeighborhoodTravel.response(forDestination: 0))
        XCTAssertNil(NeighborhoodTravel.response(forDestination: 101))
    }
}
