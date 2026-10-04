import Foundation
import XCTest
@testable import SimsCore

final class PNGImageTests: XCTestCase {
    func testPNGPreservesRowOrderAndStraightAlphaForMetalTextures() throws {
        let data = try XCTUnwrap(Data(base64Encoded: "iVBORw0KGgoAAAANSUhEUgAAAAIAAAACCAYAAABytg0kAAAAGElEQVR4nGP4z8Dwn+E/QwMDA8N/EGAAAEPTCHlKSuRGAAAAAElFTkSuQmCC"))
        let image = try PNGImage(data: data, width: 2, height: 2)
        XCTAssertEqual(Array(image.rgba.prefix(12)), [255, 0, 0, 255, 0, 255, 0, 128, 0, 0, 255, 255])
        XCTAssertEqual(image.rgba[15], 0)
        XCTAssertThrowsError(try PNGImage(data: data, width: 1, height: 2))
        XCTAssertThrowsError(try PNGImage(data: data, width: 4097, height: 2))
        XCTAssertThrowsError(try PNGImage(data: Data(data.prefix(20)), width: 2, height: 2))
    }
}
