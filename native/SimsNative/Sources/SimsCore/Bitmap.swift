import Foundation

public struct SimsBitmap {
    public let width: Int
    public let height: Int
    public let rgba: Data

    public init(data: Data) throws {
        func unsigned(_ offset: Int, _ count: Int = 4) throws -> UInt32 {
            guard offset >= 0 && offset + count <= data.count else { throw ContentError.invalid("Truncated BMP header") }
            return (0..<count).reduce(UInt32(0)) { $0 | UInt32(data[offset + $1]) << ($1 * 8) }
        }
        guard data.count >= 54 && data.prefix(2) == Data("BM".utf8), try unsigned(14) >= 40 else {
            throw ContentError.invalid("Unsupported BMP header")
        }
        let pixelOffset = Int(try unsigned(10))
        let width = Int(Int32(bitPattern: try unsigned(18)))
        let signedHeight = Int(Int32(bitPattern: try unsigned(22)))
        let height = abs(signedHeight)
        let bits = Int(try unsigned(28, 2))
        let compression = try unsigned(30)
        guard width > 0 && height > 0 && width <= 16384 && height <= 16384 && width * height <= 64_000_000,
              try unsigned(26, 2) == 1, pixelOffset >= 54 && pixelOffset <= data.count,
              (bits == 8 && (compression == 0 || compression == 1)) || ((bits == 24 || bits == 32) && compression == 0) else {
            throw ContentError.invalid("Unsupported BMP dimensions or encoding")
        }
        var rgba = Data(repeating: 0, count: width * height * 4)
        var palette: [SIMD4<UInt8>] = []
        if bits == 8 {
            let paletteOffset = 14 + Int(try unsigned(14))
            let specified = Int(try unsigned(46))
            let colors = specified == 0 ? 256 : specified
            guard colors > 0 && colors <= 256 && paletteOffset + colors * 4 <= pixelOffset else {
                throw ContentError.invalid("Invalid BMP palette")
            }
            for index in 0..<colors {
                let offset = paletteOffset + index * 4
                palette.append(SIMD4(data[offset + 2], data[offset + 1], data[offset], 255))
            }
        }
        func setPixel(_ x: Int, _ y: Int, _ color: SIMD4<UInt8>) throws {
            guard x >= 0 && x < width && y >= 0 && y < height else { throw ContentError.invalid("BMP run exceeds image bounds") }
            let row = signedHeight > 0 ? height - 1 - y : y
            let offset = (row * width + x) * 4
            for channel in 0..<4 { rgba[offset + channel] = color[channel] }
        }
        func indexedPixel(_ x: Int, _ y: Int, _ index: UInt8) throws {
            guard Int(index) < palette.count else { throw ContentError.invalid("BMP references a missing palette color") }
            try setPixel(x, y, palette[Int(index)])
        }
        if compression == 1 {
            var offset = pixelOffset
            var x = 0
            var y = 0
            var ended = false
            for row in 0..<height {
                for column in 0..<width { try indexedPixel(column, row, 0) }
            }
            func next() throws -> UInt8 {
                guard offset < data.count else { throw ContentError.invalid("Truncated BMP RLE stream") }
                defer { offset += 1 }
                return data[offset]
            }
            while !ended {
                let count = Int(try next())
                let value = try next()
                if count > 0 {
                    for _ in 0..<count { try indexedPixel(x, y, value); x += 1 }
                } else {
                    switch value {
                    case 0: x = 0; y += 1
                    case 1: ended = true
                    case 2:
                        x += Int(try next()); y += Int(try next())
                        guard x <= width && y < height else { throw ContentError.invalid("BMP delta exceeds image bounds") }
                    default:
                        for _ in 0..<Int(value) { try indexedPixel(x, y, next()); x += 1 }
                        if value % 2 != 0 { _ = try next() }
                    }
                }
            }
        } else {
            let stride = ((width * bits + 31) / 32) * 4
            guard stride * height <= data.count - pixelOffset else { throw ContentError.invalid("Truncated BMP pixel data") }
            for y in 0..<height {
                for x in 0..<width {
                    let offset = pixelOffset + y * stride + x * (bits / 8)
                    if bits == 8 {
                        try indexedPixel(x, y, data[offset])
                    } else {
                        try setPixel(x, y, SIMD4(data[offset + 2], data[offset + 1], data[offset], 255))
                    }
                }
            }
        }
        self.width = width
        self.height = height
        self.rgba = rgba
    }
}
