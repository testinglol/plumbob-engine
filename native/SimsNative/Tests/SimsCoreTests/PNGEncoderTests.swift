import Foundation
import XCTest
@testable import SimsCore

final class PNGEncoderTests: XCTestCase {
    func testEncodedPNGDecodesToTheSamePixels() throws {
        // 200×90 RGBA rows are over 64 KiB in total, so the output spans several stored deflate blocks.
        let width = 200, height = 90
        let rgba = Data((0..<(width * height * 4)).map { (index: Int) -> UInt8 in UInt8(truncatingIfNeeded: index * 7 + index / 13) })
        let png = try PNGEncoder.encode(rgba: rgba, width: width, height: height)
        XCTAssertEqual(try PNGImage(data: png, width: width, height: height).rgba, rgba)
        XCTAssertThrowsError(try PNGEncoder.encode(rgba: rgba, width: width, height: height + 1))
    }
}
