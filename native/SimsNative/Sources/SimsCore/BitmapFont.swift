import Foundation

public struct SimsBitmapFont {
    public struct Glyph {
        public let width: Int
        public let height: Int
        public let x: Int
        public let y: Int
        public let offsetX: Int
        public let offsetY: Int
        public let advance: Int
    }

    public let width: Int
    public let height: Int
    public let coverage: Data
    public let glyphs: [UInt16: Glyph]
    public let lineHeight: Int
    public let spaceAdvance: Int

    public init(data: Data) throws {
        func value(_ offset: Int, _ count: Int) throws -> Int {
            guard offset >= 0, count > 0, offset <= data.count - count else { throw ContentError.invalid("Truncated FFN font") }
            return (0..<count).reduce(0) { $0 | Int(data[offset + $1]) << ($1 * 8) }
        }
        guard data.count >= 32, data.count <= 16 * 1024 * 1024, data.prefix(4) == Data("FNTF".utf8),
              try value(4, 4) == data.count, try value(8, 2) == 101 else { throw ContentError.invalid("Unsupported FFN font header") }
        let count = try value(10, 2)
        let table = try value(20, 4)
        let atlas = try value(28, 4)
        guard count > 0, count <= 256, table >= 32, table <= data.count - count * 11,
              atlas >= table + count * 11, atlas <= data.count - 16,
              try value(atlas, 4) == 0x7a else { throw ContentError.invalid("Unsupported FFN glyph table or atlas") }
        let width = try value(atlas + 4, 2), height = try value(atlas + 6, 2)
        guard width > 0, height > 0, width <= 4096, height <= 4096,
              width.isMultiple(of: 2), width * height / 2 == data.count - atlas - 16 else {
            throw ContentError.invalid("Invalid FFN atlas dimensions")
        }
        var records: [UInt16: Glyph] = [:]
        for index in 0..<count {
            let offset = table + index * 11
            let code = UInt16(try value(offset, 2))
            let w = try value(offset + 2, 1), h = try value(offset + 3, 1)
            let x = try value(offset + 4, 2), y = try value(offset + 6, 2)
            let dx = Int(Int8(bitPattern: data[offset + 9]))
            let dy = Int(Int8(bitPattern: data[offset + 10]))
            guard records[code] == nil, w > 0, h > 0, x + w <= width, y + h <= height else {
                throw ContentError.invalid("Invalid FFN glyph rectangle")
            }
            records[code] = Glyph(width: w, height: h, x: x, y: y, offsetX: dx, offsetY: dy, advance: w + dx)
        }
        let measured = records.filter { $0.key != 160 }.map(\.value)
        guard !measured.isEmpty else { throw ContentError.invalid("FFN font has no measurable glyphs") }
        let minimumY = min(0, measured.map(\.offsetY).min() ?? 0)
        lineHeight = (measured.map { $0.height + $0.offsetY }.max() ?? 0) - minimumY
        spaceAdvance = Int(floor(0.5 * Double(measured.reduce(0) { $0 + $1.width }) / Double(measured.count) + 0.5))
        glyphs = records.mapValues { Glyph(width: $0.width, height: $0.height, x: $0.x, y: $0.y,
                                           offsetX: $0.offsetX, offsetY: $0.offsetY - minimumY, advance: $0.advance) }
        var pixels = Data(repeating: 0, count: width * height)
        for index in pixels.indices {
            let packed = data[atlas + 16 + index / 2]
            pixels[index] = (index.isMultiple(of: 2) ? packed >> 4 : packed & 15) * 17
        }
        self.width = width
        self.height = height
        coverage = pixels
    }

    public func advance(for character: UInt16) -> Int {
        if character == 32 { return spaceAdvance }
        return glyphs[character]?.advance ?? glyphs[63]?.advance ?? spaceAdvance
    }

    public func textWidth(_ text: String) -> Int {
        text.utf16.reduce(0) { $0 + advance(for: $1) }
    }

    public func wrappedLines(_ text: String, width: Int) throws -> [String] {
        guard width > 0, text.utf16.count <= 8192 else { throw ContentError.invalid("Invalid bitmap font paragraph") }
        let normalized = text.replacingOccurrences(of: "\r\n", with: "\n").replacingOccurrences(of: "\r", with: "\n")
        var lines: [String] = []
        for paragraph in normalized.split(separator: "\n", omittingEmptySubsequences: false) {
            var line = ""
            for word in paragraph.split(whereSeparator: { $0 == " " || $0 == "\t" }) {
                let candidate = line.isEmpty ? String(word) : line + " " + word
                if textWidth(candidate) <= width && candidate.utf16.count <= 512 { line = candidate; continue }
                if !line.isEmpty { lines.append(line); line = "" }
                for character in word {
                    let candidate = line + String(character)
                    if !line.isEmpty && (textWidth(candidate) > width || candidate.utf16.count > 512) {
                        lines.append(line)
                        line = ""
                    }
                    line.append(character)
                }
            }
            lines.append(line)
        }
        guard lines.count <= 512 else { throw ContentError.invalid("Bitmap font paragraph has too many lines") }
        return lines
    }

    public func rasterize(_ text: String, color: SIMD3<UInt8>) throws -> (width: Int, height: Int, rgba: Data) {
        guard text.utf16.count <= 512, !text.contains("\n"), !text.contains("\r") else { throw ContentError.invalid("Invalid bitmap font label") }
        let width = max(1, textWidth(text) + 6), height = lineHeight + 6
        guard width <= 8192, height > 0, height <= 1024 else { throw ContentError.invalid("Bitmap font label exceeds size limits") }
        var output = Data(repeating: 0, count: width * height * 4)
        var cursor = 3
        for character in text.utf16 {
            defer { cursor += advance(for: character) }
            guard character != 32, let glyph = glyphs[character] ?? glyphs[63] else { continue }
            for y in 0..<glyph.height {
                for x in 0..<glyph.width {
                    let targetX = cursor + glyph.offsetX + x, targetY = 3 + glyph.offsetY + y
                    guard targetX >= 0, targetY >= 0, targetX < width, targetY < height else { continue }
                    let offset = (targetY * width + targetX) * 4
                    output[offset] = color.x
                    output[offset + 1] = color.y
                    output[offset + 2] = color.z
                    output[offset + 3] = coverage[(glyph.y + y) * self.width + glyph.x + x]
                }
            }
        }
        return (width, height, output)
    }
}
