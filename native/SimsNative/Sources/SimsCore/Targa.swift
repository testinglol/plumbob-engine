import Foundation

public struct SimsTarga {
    public let width: Int
    public let height: Int
    public let rgba: Data

    public init(data: Data) throws {
        guard data.count >= 18 else { throw ContentError.invalid("Truncated TGA header") }
        func word(_ offset: Int) -> Int { Int(data[offset]) | Int(data[offset + 1]) << 8 }
        let kind = Int(data[2])
        let base = kind >= 9 ? kind - 8 : kind
        let width = word(12)
        let height = word(14)
        let bits = Int(data[16])
        let descriptor = data[17]
        let paletteStart = word(3)
        let paletteCount = word(5)
        let paletteBits = Int(data[7])
        guard [1, 2, 3, 9, 10, 11].contains(kind), width > 0, height > 0,
              width <= 4096, height <= 4096, descriptor & 0xc0 == 0,
              (base == 1 && data[1] == 1 && [8, 16].contains(bits) && paletteCount > 0 && paletteStart + paletteCount <= 65536 && [16, 24, 32].contains(paletteBits)) ||
              (base == 2 && data[1] == 0 && [16, 24, 32].contains(bits)) ||
              (base == 3 && data[1] == 0 && [8, 16].contains(bits)) else {
            throw ContentError.invalid("Unsupported TGA dimensions or encoding")
        }
        var offset = 18 + Int(data[0])
        func next() throws -> UInt8 {
            guard offset < data.count else { throw ContentError.invalid("Truncated TGA pixel data") }
            defer { offset += 1 }
            return data[offset]
        }
        func color(_ depth: Int, alpha: Bool) throws -> SIMD4<UInt8> {
            if depth == 16 {
                let value = UInt16(try next()) | UInt16(try next()) << 8
                func expand(_ value: UInt16) -> UInt8 { UInt8((value & 31) * 255 / 31) }
                return SIMD4(expand(value >> 10), expand(value >> 5), expand(value), alpha && value & 0x8000 == 0 ? 0 : 255)
            }
            let blue = try next()
            let green = try next()
            let red = try next()
            let opacity: UInt8 = depth == 32 ? try next() : 255
            return SIMD4(red, green, blue, alpha ? opacity : 255)
        }
        var palette: [SIMD4<UInt8>] = []
        if base == 1 {
            for _ in 0..<paletteCount { palette.append(try color(paletteBits, alpha: paletteBits == 32 || descriptor & 15 > 0)) }
        }
        func pixel() throws -> SIMD4<UInt8> {
            if base == 1 {
                var index = Int(try next())
                if bits == 16 { index |= Int(try next()) << 8 }
                guard index >= paletteStart, index < paletteStart + paletteCount else { throw ContentError.invalid("TGA references a missing palette color") }
                return palette[index - paletteStart]
            }
            if base == 3 {
                let value = try next()
                let alpha: UInt8 = bits == 16 ? try next() : 255
                return SIMD4(value, value, value, alpha)
            }
            return try color(bits, alpha: descriptor & 15 > 0)
        }
        var output = Data(repeating: 0, count: width * height * 4)
        var position = 0
        func append(_ value: SIMD4<UInt8>) throws {
            guard position < width * height else { throw ContentError.invalid("TGA run exceeds image bounds") }
            let row = position / width
            let column = position % width
            let x = descriptor & 0x10 == 0 ? column : width - 1 - column
            let y = descriptor & 0x20 != 0 ? row : height - 1 - row
            let target = (y * width + x) * 4
            for channel in 0..<4 { output[target + channel] = value[channel] }
            position += 1
        }
        while position < width * height {
            if kind >= 9 {
                let packet = try next()
                let count = Int(packet & 0x7f) + 1
                guard count <= width * height - position else { throw ContentError.invalid("TGA run exceeds image bounds") }
                if packet & 0x80 != 0 {
                    let value = try pixel()
                    for _ in 0..<count { try append(value) }
                } else {
                    for _ in 0..<count { try append(pixel()) }
                }
            } else { try append(pixel()) }
        }
        self.width = width
        self.height = height
        rgba = output
    }
}
