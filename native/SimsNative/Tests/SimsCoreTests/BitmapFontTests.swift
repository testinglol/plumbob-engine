import Foundation
import XCTest
@testable import SimsCore

final class BitmapFontTests: XCTestCase {
    func testPackedCoverageAndOriginalGlyphMetrics() throws {
        var bytes = Data(repeating: 0, count: 98)
        bytes.replaceSubrange(0..<4, with: Data("FNTF".utf8))
        func put(_ value: Int, _ offset: Int, _ count: Int) {
            for index in 0..<count { bytes[offset + index] = UInt8(truncatingIfNeeded: value >> (index * 8)) }
        }
        put(98, 4, 4)
        put(101, 8, 2)
        put(3, 10, 2)
        put(9, 12, 4)
        put(32, 20, 4)
        put(66, 28, 4)
        for (index, code) in [32, 65, 160].enumerated() {
            let offset = 32 + index * 11
            put(code, offset, 2)
            put(code == 65 ? 2 : 1, offset + 2, 1)
            put(code == 65 ? 2 : 1, offset + 3, 1)
            put(0, offset + 4, 2)
            put(0, offset + 6, 2)
            put(code == 65 ? 7 : -1, offset + 8, 1)
            put(code == 65 ? 1 : -1, offset + 9, 1)
            put(code == 65 ? 1 : -1, offset + 10, 1)
        }
        put(122, 66, 4)
        put(8, 70, 2)
        put(4, 72, 2)
        bytes[82] = 0x1f
        let font = try SimsBitmapFont(data: bytes)
        XCTAssertEqual(font.coverage.prefix(2), Data([17, 255]))
        XCTAssertEqual(font.lineHeight, 4)
        XCTAssertEqual(font.spaceAdvance, 1)
        XCTAssertEqual(font.glyphs[65]?.offsetX, 1)
        XCTAssertEqual(font.glyphs[65]?.offsetY, 2)
        XCTAssertEqual(font.advance(for: 65), 3)
        XCTAssertEqual(font.textWidth("A A"), 7)
        XCTAssertEqual(try font.wrappedLines("AA A\r\n\r\nAAAA", width: 6), ["AA", "A", "", "AA", "AA"])
        XCTAssertThrowsError(try font.wrappedLines("A", width: 0))
        XCTAssertThrowsError(try font.wrappedLines(String(repeating: "A", count: 8193), width: 100))
        let image = try font.rasterize("A", color: SIMD3(185, 185, 208))
        XCTAssertEqual(image.width, 9)
        XCTAssertEqual(image.height, 10)
        XCTAssertEqual(image.rgba[(5 * 9 + 4) * 4 + 3], 17)
        XCTAssertEqual(image.rgba[(5 * 9 + 5) * 4 + 3], 255)
        for badOffset in [4, 8, 20, 28, 70] {
            var bad = bytes
            bad[badOffset] = 0
            XCTAssertThrowsError(try SimsBitmapFont(data: bad))
        }
        XCTAssertThrowsError(try SimsBitmapFont(data: bytes.dropLast()))
        XCTAssertThrowsError(try font.rasterize(String(repeating: "A", count: 513), color: SIMD3(255,255,255)))
    }
}
