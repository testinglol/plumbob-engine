import Foundation

/// Writes 8-bit RGBA PNGs with uncompressed (stored) deflate blocks: no zlib dependency, and the files are only
/// screenshots and render checks, so size does not matter.
public enum PNGEncoder {
    public static func encode(rgba: Data, width: Int, height: Int) throws -> Data {
        guard width > 0, height > 0, rgba.count == width * height * 4 else { throw ContentError.invalid("PNG pixel data does not match its size") }
        var raw = [UInt8]()
        raw.reserveCapacity((width * 4 + 1) * height)
        rgba.withUnsafeBytes { pixels in
            for row in 0..<height {
                raw.append(0)
                raw += pixels[(row * width * 4)..<((row + 1) * width * 4)]
            }
        }
        var zlib: [UInt8] = [0x78, 0x01]
        var offset = 0
        repeat {
            let length = min(65535, raw.count - offset)
            let final: UInt8 = offset + length == raw.count ? 1 : 0
            zlib += [final, UInt8(length & 0xFF), UInt8(length >> 8), UInt8(~length & 0xFF), UInt8((~length >> 8) & 0xFF)]
            zlib += raw[offset..<(offset + length)]
            offset += length
        } while offset < raw.count
        var a: UInt32 = 1, b: UInt32 = 0
        for byte in raw {
            a = (a + UInt32(byte)) % 65521
            b = (b + a) % 65521
        }
        zlib += bigEndian(b << 16 | a)
        var output: [UInt8] = [0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A]
        chunk("IHDR", bigEndian(UInt32(width)) + bigEndian(UInt32(height)) + [8, 6, 0, 0, 0], into: &output)
        chunk("IDAT", zlib, into: &output)
        chunk("IEND", [], into: &output)
        return Data(output)
    }

    private static func bigEndian(_ value: UInt32) -> [UInt8] {
        [UInt8(value >> 24), UInt8((value >> 16) & 0xFF), UInt8((value >> 8) & 0xFF), UInt8(value & 0xFF)]
    }

    private static let crcTable: [UInt32] = (0..<256).map { index in
        var value = UInt32(index)
        for _ in 0..<8 { value = value & 1 == 1 ? 0xEDB88320 ^ (value >> 1) : value >> 1 }
        return value
    }

    private static func chunk(_ type: String, _ data: [UInt8], into output: inout [UInt8]) {
        let body = Array(type.utf8) + data
        var crc: UInt32 = 0xFFFFFFFF
        for byte in body { crc = crcTable[Int((crc ^ UInt32(byte)) & 0xFF)] ^ (crc >> 8) }
        output += bigEndian(UInt32(data.count)) + body + bigEndian(~crc)
    }
}
