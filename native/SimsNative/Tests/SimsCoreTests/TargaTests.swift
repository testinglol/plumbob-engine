import Foundation
import XCTest
@testable import SimsCore

final class TargaTests: XCTestCase {
    func testTrueColorRunsPreserveAlphaAndOrientation() throws {
        var header = Data(repeating: 0, count: 18)
        header[2] = 10
        header[12] = 2
        header[14] = 2
        header[16] = 32
        header[17] = 0x38
        let data = header + Data([1, 0, 0, 255, 255, 0, 255, 0, 128, 0x81, 255, 0, 0, 255])
        let image = try SimsTarga(data: data)
        XCTAssertEqual(image.rgba, Data([0, 255, 0, 128, 255, 0, 0, 255, 0, 0, 255, 255, 0, 0, 255, 255]))
        for length in 0..<data.count { XCTAssertThrowsError(try SimsTarga(data: Data(data.prefix(length)))) }
        XCTAssertThrowsError(try SimsTarga(data: header + Data([0x84, 0, 0, 0, 255])))
    }

    func testPaletteRunsRespectNonzeroPaletteIndex() throws {
        var header = Data(repeating: 0, count: 18)
        header[1] = 1
        header[2] = 9
        header[3] = 5
        header[5] = 2
        header[7] = 24
        header[12] = 2
        header[14] = 1
        header[16] = 8
        header[17] = 0x20
        let palette = Data([0, 0, 255, 0, 255, 0])
        XCTAssertEqual(try SimsTarga(data: header + palette + Data([0x81, 6])).rgba, Data([0, 255, 0, 255, 0, 255, 0, 255]))
        XCTAssertThrowsError(try SimsTarga(data: header + palette + Data([0x81, 7])))
    }

    func testGrayscaleAndDimensions() throws {
        var header = Data(repeating: 0, count: 18)
        header[2] = 3
        header[12] = 1
        header[14] = 1
        header[16] = 16
        XCTAssertEqual(try SimsTarga(data: header + Data([60, 128])).rgba, Data([60, 60, 60, 128]))
        header[14] = 0
        XCTAssertThrowsError(try SimsTarga(data: header + Data([60, 128])))
    }
}
