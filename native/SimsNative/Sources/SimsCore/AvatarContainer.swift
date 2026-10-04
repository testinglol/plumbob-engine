import Foundation

public struct PackAvatarResource: Codable, Sendable, Equatable {
    public let kind: String
    public let name: String
    public let path: String
    public let owner: String
}

struct AvatarContainer {
    private struct Reader {
        var binary: BinaryReader?
        var lines: [String] = []
        var line = 0
        var numbers: [Substring] = []
        var number = 0
        var operations = 0

        init(data: Data, text: Bool) throws {
            guard data.count <= 64 * 1024 * 1024 else { throw ContentError.invalid("Avatar container exceeds size limit") }
            if text {
                guard let content = String(data: data, encoding: .utf8) else { throw ContentError.invalid("CMX is not UTF-8 text") }
                lines = content.trimmingPrefix("\u{FEFF}").replacingOccurrences(of: "\r\n", with: "\n").components(separatedBy: "\n")
                guard let version = lines.firstIndex(where: { $0.hasPrefix("version ") }), lines[version] == "version 300" else {
                    throw ContentError.invalid("Unsupported CMX version")
                }
                line = version + 1
            } else { binary = BinaryReader(data: data) }
        }

        mutating func consume() throws {
            operations += 1
            guard operations <= 4_000_000 else { throw ContentError.invalid("Avatar container complexity limit exceeded") }
        }

        mutating func token() throws -> Substring {
            if number == numbers.count {
                guard line < lines.count else { throw ContentError.invalid("Truncated CMX") }
                numbers = lines[line].trimmingCharacters(in: .whitespaces).split(separator: " ", omittingEmptySubsequences: false)
                line += 1
                number = 0
            }
            guard number < numbers.count else { throw ContentError.invalid("Missing CMX numeric value") }
            defer { number += 1 }
            return numbers[number]
        }

        mutating func integer(short: Bool = false) throws -> Int {
            try consume()
            let value: Int
            if binary != nil {
                if short {
                    let bytes = try binary!.bytes(2)
                    value = Int(Int16(bitPattern: UInt16(bytes[0]) | UInt16(bytes[1]) << 8))
                } else { value = Int(Int32(bitPattern: try binary!.uint32())) }
            } else {
                let token = try token()
                guard let parsed = Int(token), short ? Int16(exactly: parsed) != nil : Int32(exactly: parsed) != nil else {
                    throw ContentError.invalid("Invalid CMX integer")
                }
                value = parsed
            }
            return value
        }

        mutating func count(short: Bool = false, limit: Int = 100_000) throws -> Int {
            let value = try integer(short: short)
            guard (0...limit).contains(value) else { throw ContentError.invalid("Invalid avatar container count") }
            return value
        }

        mutating func floats(_ count: Int) throws {
            for _ in 0..<count {
                try consume()
                let value: Float
                if binary != nil { value = Float(bitPattern: try binary!.uint32()) }
                else {
                    guard let parsed = Float(try token()) else { throw ContentError.invalid("Invalid CMX float") }
                    value = parsed
                }
                guard value.isFinite else { throw ContentError.invalid("Non-finite avatar value") }
            }
        }

        mutating func string() throws -> String {
            try consume()
            let value: String
            if binary != nil {
                let count = Int(try binary!.bytes(1)[0])
                guard let parsed = String(data: try binary!.bytes(count), encoding: .ascii) else { throw ContentError.invalid("Invalid BCF string") }
                value = parsed
            } else {
                guard number == numbers.count, line < lines.count else { throw ContentError.invalid("Invalid CMX string position") }
                value = lines[line]
                line += 1
            }
            guard value.utf8.count <= 4096, !value.contains("\0") else { throw ContentError.invalid("Invalid avatar string") }
            return value
        }

        mutating func properties(grouped: Bool) throws {
            let groups = grouped ? try count() : 1
            for _ in 0..<groups {
                for _ in 0..<(try count()) { _ = try string(); _ = try string() }
            }
        }

        func finish() throws {
            if let binary {
                guard binary.data.dropFirst(binary.offset).allSatisfy({ $0 == 0 }) else { throw ContentError.invalid("Trailing BCF content") }
            } else {
                guard number == numbers.count, lines.dropFirst(line).allSatisfy({ $0.trimmingCharacters(in: .whitespaces).isEmpty }) else {
                    throw ContentError.invalid("Trailing CMX content")
                }
            }
        }
    }

    static func read(_ data: Data, path: String, owner: String, allowDuplicates: Bool = false) throws -> [PackAvatarResource] {
        var reader = try Reader(data: data, text: path.hasSuffix(".cmx"))
        var resources: [PackAvatarResource] = []
        var identities = Set<String>()
        func insert(_ kind: String, _ name: String) throws {
            guard !name.isEmpty else { throw ContentError.invalid("Empty avatar resource name in \(path)") }
            let normalized = name.lowercased()
            guard identities.insert(kind + ":" + normalized).inserted || allowDuplicates else {
                throw ContentError.invalid("Duplicate avatar \(kind) \(normalized) in \(path)")
            }
            resources.append(PackAvatarResource(kind: kind, name: normalized, path: path, owner: owner))
        }
        for _ in 0..<(try reader.count()) {
            try insert("skeleton", reader.string())
            let count = try reader.count(short: true, limit: 32767)
            var bones = 0
            while bones < count {
                let name = try reader.string()
                _ = try reader.string()
                if name.isEmpty { continue }
                try reader.properties(grouped: true)
                try reader.floats(7)
                for _ in 0..<3 { _ = try reader.integer() }
                try reader.floats(2)
                bones += 1
            }
        }
        for _ in 0..<(try reader.count()) {
            try insert("appearance", reader.string())
            _ = try reader.integer(); _ = try reader.integer()
            for _ in 0..<(try reader.count()) {
                _ = try reader.string(); _ = try reader.string()
                _ = try reader.integer(); _ = try reader.integer()
            }
        }
        for _ in 0..<(try reader.count()) {
            try insert("animation", reader.string())
            _ = try reader.string()
            try reader.floats(2)
            _ = try reader.integer()
            _ = try reader.count(limit: 10_000_000); _ = try reader.count(limit: 10_000_000)
            for _ in 0..<(try reader.count()) {
                _ = try reader.string()
                _ = try reader.count(limit: 10_000_000)
                try reader.floats(1)
                for _ in 0..<4 { _ = try reader.integer() }
                for _ in 0..<(try reader.count()) { try reader.properties(grouped: false) }
                for _ in 0..<(try reader.count()) {
                    for _ in 0..<(try reader.count()) { _ = try reader.integer(); try reader.properties(grouped: false) }
                }
            }
        }
        try reader.finish()
        return resources
    }
}
