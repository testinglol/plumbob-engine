import Foundation

public enum ContentError: Error, CustomStringConvertible {
    case invalid(String)
    case missing(String)

    public var description: String {
        switch self {
        case .invalid(let message), .missing(let message): return message
        }
    }
}

public func resourceKey(_ path: String) throws -> String {
    let normalized = path.replacingOccurrences(of: "\\", with: "/")
    let parts = normalized.split(separator: "/", omittingEmptySubsequences: false)
    guard !parts.isEmpty,
          parts.allSatisfy({ !$0.isEmpty && $0 != "." && $0 != ".." && !$0.contains(":") && !$0.contains("\0") }) else {
        throw ContentError.invalid("Unsafe resource path: \(path)")
    }
    return parts.joined(separator: "/").lowercased()
}

public struct FARArchive: Sendable {
    public struct Entry: Sendable {
        public let name: String
        public let offset: Int
        public let size: Int
    }

    private let data: Data
    public let entries: [String: Entry]

    public init(url: URL) throws {
        try self.init(data: Data(contentsOf: url, options: .mappedIfSafe))
    }

    public init(data: Data) throws {
        var reader = BinaryReader(data: data)
        guard try reader.bytes(8) == Data("FAR!byAZ".utf8), try reader.uint32() == 1 else {
            throw ContentError.invalid("Expected a Sims FAR version 1 archive")
        }
        let manifest = Int(try reader.uint32())
        guard manifest >= 16 && manifest <= data.count - 4 else {
            throw ContentError.invalid("FAR manifest is outside the file")
        }
        reader.offset = manifest
        let count = Int(try reader.uint32())
        guard count <= (data.count - reader.offset) / 17 else {
            throw ContentError.invalid("FAR entry count exceeds the manifest size")
        }
        var result: [String: Entry] = [:]
        for _ in 0..<count {
            let size = Int(try reader.uint32())
            let storedSize = Int(try reader.uint32())
            let offset = Int(try reader.uint32())
            let length = Int(try reader.uint32())
            guard length > 0 && length <= 4096 else {
                throw ContentError.invalid("Invalid FAR filename length")
            }
            let nameData = try reader.bytes(length)
            guard let name = String(data: nameData, encoding: .ascii),
                  size == storedSize, offset >= 16, offset <= manifest, size <= manifest - offset else {
                throw ContentError.invalid("Unsupported or corrupt FAR entry")
            }
            let key = try resourceKey(name)
            guard result[key] == nil else {
                throw ContentError.invalid("Duplicate FAR entry: \(name)")
            }
            result[key] = Entry(name: name, offset: offset, size: size)
        }
        self.data = data
        self.entries = result
    }

    public func read(_ path: String) throws -> Data {
        let key = try resourceKey(path)
        guard let entry = entries[key] else { throw ContentError.missing("Missing archive resource: \(path)") }
        return data.subdata(in: entry.offset..<(entry.offset + entry.size))
    }
}

struct BinaryReader {
    let data: Data
    var offset = 0

    mutating func bytes(_ count: Int) throws -> Data {
        guard count >= 0 && offset >= 0 && offset <= data.count && count <= data.count - offset else {
            throw ContentError.invalid("Unexpected end of resource")
        }
        let result = data.subdata(in: offset..<(offset + count))
        offset += count
        return result
    }

    mutating func uint32() throws -> UInt32 {
        let bytes = try bytes(4)
        return bytes.enumerated().reduce(UInt32(0)) { $0 | UInt32($1.element) << ($1.offset * 8) }
    }
}
