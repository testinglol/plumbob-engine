import Foundation

/// A self-contained PNG decoder (all colour types, bit depths and Adam7 interlacing) that yields straight-alpha RGBA rows
/// top-down, so scene textures decode identically on every platform.
public struct PNGImage {
    public let width: Int
    public let height: Int
    public let rgba: Data

    public init(data: Data, width: Int, height: Int) throws {
        guard (1...4096).contains(width), (1...4096).contains(height), data.count <= 64 * 1024 * 1024,
              data.starts(with: [137, 80, 78, 71, 13, 10, 26, 10]) else { throw Self.invalid }
        let bytes = [UInt8](data)
        var offset = 8
        var header: (width: Int, height: Int, depth: Int, colour: Int, interlace: Int)?
        var palette: [UInt8] = []
        var transparency: [UInt8] = []
        var compressed: [UInt8] = []
        var ended = false
        while offset + 12 <= bytes.count {
            let length = Int(Self.word(bytes, offset))
            let type = String(decoding: bytes[offset + 4..<offset + 8], as: UTF8.self)
            guard length <= bytes.count - offset - 12 else { throw Self.invalid }
            let body = Array(bytes[offset + 8..<offset + 8 + length])
            offset += 12 + length
            switch type {
            case "IHDR":
                guard header == nil, length == 13, body[10] == 0, body[11] == 0, body[12] <= 1 else { throw Self.invalid }
                header = (Int(Self.word(body, 0)), Int(Self.word(body, 4)), Int(body[8]), Int(body[9]), Int(body[12]))
            case "PLTE": palette = body
            case "tRNS": transparency = body
            case "IDAT": compressed += body
            case "IEND": ended = true
            default: break
            }
            if ended { break }
        }
        guard ended, let header, header.width == width, header.height == height,
              let channels = [0: 1, 2: 3, 3: 1, 4: 2, 6: 4][header.colour],
              (header.colour == 0 ? [1, 2, 4, 8, 16] : header.colour == 3 ? [1, 2, 4, 8] : [8, 16]).contains(header.depth),
              header.colour != 3 || (!palette.isEmpty && palette.count % 3 == 0) else { throw Self.invalid }
        let raw = try Inflate.zlib(compressed)

        let depth = header.depth
        let bitsPerPixel = channels * depth
        let filterStride = max(1, bitsPerPixel / 8)
        var pixels = [UInt8](repeating: 0, count: width * height * 4)
        var cursor = 0

        func sample(_ row: [UInt8], _ index: Int) -> Int {
            switch depth {
            case 16: return Int(row[index * 2]) // high byte keeps 8-bit precision
            case 8: return Int(row[index])
            default:
                let bit = index * depth
                return Int(row[bit / 8] >> UInt8(8 - depth - bit % 8)) & ((1 << depth) - 1)
            }
        }
        func raw16(_ row: [UInt8], _ index: Int) -> Int { depth == 16 ? Int(row[index * 2]) << 8 | Int(row[index * 2 + 1]) : sample(row, index) }
        let scale = depth < 8 ? 255 / ((1 << depth) - 1) : 1

        func pass(x0: Int, y0: Int, dx: Int, dy: Int) throws {
            let columns = (width - x0 + dx - 1) / dx
            let rows = (height - y0 + dy - 1) / dy
            guard columns > 0, rows > 0 else { return }
            let rowBytes = (columns * bitsPerPixel + 7) / 8
            var previous = [UInt8](repeating: 0, count: rowBytes)
            for y in 0..<rows {
                guard cursor + 1 + rowBytes <= raw.count else { throw Self.invalid }
                let filter = raw[cursor]
                var row = Array(raw[cursor + 1..<cursor + 1 + rowBytes])
                cursor += 1 + rowBytes
                for i in 0..<rowBytes {
                    let a = i >= filterStride ? Int(row[i - filterStride]) : 0
                    let b = Int(previous[i])
                    let c = i >= filterStride ? Int(previous[i - filterStride]) : 0
                    let add: Int
                    switch filter {
                    case 0: add = 0
                    case 1: add = a
                    case 2: add = b
                    case 3: add = (a + b) / 2
                    case 4:
                        let p = a + b - c, pa = abs(p - a), pb = abs(p - b), pc = abs(p - c)
                        add = pa <= pb && pa <= pc ? a : pb <= pc ? b : c
                    default: throw Self.invalid
                    }
                    row[i] = UInt8(truncatingIfNeeded: Int(row[i]) + add)
                }
                previous = row
                for x in 0..<columns {
                    let out = ((y0 + y * dy) * width + x0 + x * dx) * 4
                    var (r, g, b, alpha) = (0, 0, 0, 255)
                    switch header.colour {
                    case 0:
                        let grey = sample(row, x) * scale
                        (r, g, b) = (grey, grey, grey)
                        if transparency.count >= 2, raw16(row, x) == Int(transparency[0]) << 8 | Int(transparency[1]) { alpha = 0 }
                    case 2:
                        (r, g, b) = (sample(row, x * 3), sample(row, x * 3 + 1), sample(row, x * 3 + 2))
                        if transparency.count >= 6, (0..<3).allSatisfy({ raw16(row, x * 3 + $0) == Int(transparency[$0 * 2]) << 8 | Int(transparency[$0 * 2 + 1]) }) { alpha = 0 }
                    case 3:
                        let index = sample(row, x)
                        guard index * 3 + 2 < palette.count else { throw Self.invalid }
                        (r, g, b) = (Int(palette[index * 3]), Int(palette[index * 3 + 1]), Int(palette[index * 3 + 2]))
                        if index < transparency.count { alpha = Int(transparency[index]) }
                    case 4:
                        let grey = sample(row, x * 2)
                        (r, g, b, alpha) = (grey, grey, grey, sample(row, x * 2 + 1))
                    default:
                        (r, g, b, alpha) = (sample(row, x * 4), sample(row, x * 4 + 1), sample(row, x * 4 + 2), sample(row, x * 4 + 3))
                    }
                    pixels[out] = UInt8(r); pixels[out + 1] = UInt8(g); pixels[out + 2] = UInt8(b); pixels[out + 3] = UInt8(alpha)
                }
            }
        }

        if header.interlace == 1 {
            for (x0, y0, dx, dy) in [(0, 0, 8, 8), (4, 0, 8, 8), (0, 4, 4, 8), (2, 0, 4, 4), (0, 2, 2, 4), (1, 0, 2, 2), (0, 1, 1, 2)] {
                try pass(x0: x0, y0: y0, dx: dx, dy: dy)
            }
        } else {
            try pass(x0: 0, y0: 0, dx: 1, dy: 1)
        }
        self.width = width
        self.height = height
        rgba = Data(pixels)
    }

    private static let invalid = ContentError.invalid("PNG dimensions or format differ from scene metadata")

    private static func word(_ bytes: [UInt8], _ offset: Int) -> UInt32 {
        UInt32(bytes[offset]) << 24 | UInt32(bytes[offset + 1]) << 16 | UInt32(bytes[offset + 2]) << 8 | UInt32(bytes[offset + 3])
    }
}

/// RFC 1950/1951 decompression for PNG image data.
enum Inflate {
    private struct Bits {
        let bytes: [UInt8]
        var position = 0
        var buffer = 0
        var count = 0

        mutating func read(_ n: Int) throws -> Int {
            while count < n {
                guard position < bytes.count else { throw ContentError.invalid("Truncated deflate stream") }
                buffer |= Int(bytes[position]) << count
                position += 1
                count += 8
            }
            let value = buffer & ((1 << n) - 1)
            buffer >>= n
            count -= n
            return value
        }

        mutating func alignToByte() { buffer = 0; count = 0 }
    }

    /// Canonical Huffman table: counts per length and symbols in code order.
    private struct Huffman {
        var counts = [Int](repeating: 0, count: 16)
        var symbols: [Int] = []

        init(_ lengths: [Int]) throws {
            for length in lengths { counts[length] += 1 }
            counts[0] = 0
            var offsets = [Int](repeating: 0, count: 16)
            for length in 1..<16 { offsets[length] = offsets[length - 1] + counts[length - 1] }
            symbols = [Int](repeating: 0, count: lengths.count)
            for (symbol, length) in lengths.enumerated() where length > 0 {
                symbols[offsets[length]] = symbol
                offsets[length] += 1
            }
        }

        func decode(_ bits: inout Bits) throws -> Int {
            var code = 0, first = 0, index = 0
            for length in 1..<16 {
                code |= try bits.read(1)
                let count = counts[length]
                if code - first < count { return symbols[index + code - first] }
                index += count
                first = (first + count) << 1
                code <<= 1
            }
            throw ContentError.invalid("Invalid Huffman code")
        }
    }

    private static let lengthBase = [3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31, 35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258]
    private static let lengthExtra = [0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0]
    private static let distanceBase = [1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193, 257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577]
    private static let distanceExtra = [0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13]
    private static let codeLengthOrder = [16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15]

    static func zlib(_ input: [UInt8]) throws -> [UInt8] {
        guard input.count >= 6, input[0] & 0x0F == 8, (Int(input[0]) << 8 | Int(input[1])) % 31 == 0, input[1] & 0x20 == 0 else {
            throw ContentError.invalid("Invalid zlib header")
        }
        var bits = Bits(bytes: input, position: 2)
        var output: [UInt8] = []
        var final = 0
        repeat {
            final = try bits.read(1)
            switch try bits.read(2) {
            case 0:
                bits.alignToByte()
                let position = bits.position
                guard position + 4 <= input.count else { throw ContentError.invalid("Truncated stored block") }
                let length = Int(input[position]) | Int(input[position + 1]) << 8
                let complement = Int(input[position + 2]) | Int(input[position + 3]) << 8
                guard length == ~complement & 0xFFFF, position + 4 + length <= input.count else { throw ContentError.invalid("Invalid stored block") }
                output += input[position + 4..<position + 4 + length]
                bits.position = position + 4 + length
            case 1:
                let literal = try Huffman((0..<288).map { $0 < 144 ? 8 : $0 < 256 ? 9 : $0 < 280 ? 7 : 8 })
                let distance = try Huffman([Int](repeating: 5, count: 30))
                try block(&bits, &output, literal, distance)
            case 2:
                let literalCount = try bits.read(5) + 257
                let distanceCount = try bits.read(5) + 1
                let codeCount = try bits.read(4) + 4
                var codeLengths = [Int](repeating: 0, count: 19)
                for i in 0..<codeCount { codeLengths[codeLengthOrder[i]] = try bits.read(3) }
                let codeTable = try Huffman(codeLengths)
                var lengths: [Int] = []
                while lengths.count < literalCount + distanceCount {
                    let symbol = try codeTable.decode(&bits)
                    switch symbol {
                    case 0..<16: lengths.append(symbol)
                    case 16:
                        guard let last = lengths.last else { throw ContentError.invalid("Invalid code length repeat") }
                        lengths += [Int](repeating: last, count: try bits.read(2) + 3)
                    case 17: lengths += [Int](repeating: 0, count: try bits.read(3) + 3)
                    default: lengths += [Int](repeating: 0, count: try bits.read(7) + 11)
                    }
                }
                guard lengths.count == literalCount + distanceCount else { throw ContentError.invalid("Invalid code lengths") }
                try block(&bits, &output, Huffman(Array(lengths[..<literalCount])), Huffman(Array(lengths[literalCount...])))
            default:
                throw ContentError.invalid("Invalid deflate block type")
            }
        } while final == 0
        return output
    }

    private static func block(_ bits: inout Bits, _ output: inout [UInt8], _ literal: Huffman, _ distance: Huffman) throws {
        while true {
            let symbol = try literal.decode(&bits)
            if symbol < 256 { output.append(UInt8(symbol)); continue }
            if symbol == 256 { return }
            let index = symbol - 257
            guard index < lengthBase.count else { throw ContentError.invalid("Invalid length symbol") }
            let length = lengthBase[index] + (try bits.read(lengthExtra[index]))
            let distanceSymbol = try distance.decode(&bits)
            guard distanceSymbol < distanceBase.count else { throw ContentError.invalid("Invalid distance symbol") }
            let back = distanceBase[distanceSymbol] + (try bits.read(distanceExtra[distanceSymbol]))
            guard back <= output.count else { throw ContentError.invalid("Distance before start of output") }
            let start = output.count - back
            output.reserveCapacity(output.count + length)
            for i in 0..<length { output.append(output[start + i]) }
        }
    }
}
