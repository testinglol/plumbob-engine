import Foundation
import XCTest
@testable import SimsCore

final class SpritePixelsTests: XCTestCase {
    func testPremultipliesInLinearLightAndRemovesColorKey() throws {
        let pixels = Data([255, 0, 0, 128, 255, 0, 255, 255, 20, 40, 80, 0, 30, 40, 50, 255])
        let result = try SpritePixels.premultipliedSRGB(pixels, removeMagenta: true)
        XCTAssertEqual(Array(result), [188, 0, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 30, 40, 50, 255])
        XCTAssertThrowsError(try SpritePixels.premultipliedSRGB(Data([0])))
    }

    func testRemovesOriginalNeighborhoodRLEMagentaPaletteVariants() throws {
        let pixels = Data([254, 2, 254, 255, 248, 0, 248, 255, 247, 0, 247, 255])
        let result = try SpritePixels.premultipliedSRGB(pixels, removeMagenta: true)
        XCTAssertEqual(Array(result), [0, 0, 0, 0, 0, 0, 0, 0, 247, 0, 247, 255])
    }
}
