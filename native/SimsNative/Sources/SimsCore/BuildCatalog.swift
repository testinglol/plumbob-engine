import Foundation

public struct BuildCatalogPage: Decodable {
    public enum Kind: String, Decodable { case floor, wall, wallStyle, water, roof }
    public enum Target: Hashable {
        case pattern(UInt16), object(UInt32)
    }
    public struct Item: Decodable {
        public let id: UInt16
        public let name: String
        public let description: String
        public let price: Int
        public let file: String
        public var pattern: UInt16? = nil
        public var guid: UInt32? = nil
        public var target: Target { guid.map(Target.object) ?? .pattern(id) }
        public var sortKey: UInt64 { guid.map { UInt64($0) + 65536 } ?? UInt64(id) }
        public let icon: GameplayPanelState.Image?
    }
    public let schemaVersion: Int
    public let kind: Kind
    public let offset: Int
    public let total: Int
    public let items: [Item]

    public func nextOffset(visibleCapacity: Int) -> Int? {
        let count = min(items.count, max(0, visibleCapacity))
        return count > 0 && offset + count < total ? offset + count : nil
    }
    public func validate() throws {
        guard schemaVersion == 1, (0...1_000_000).contains(offset), (0...1_000_000).contains(total),
              items.count <= 64, items.count <= max(0, total - offset), !items.isEmpty || offset >= total,
              Set(items.map(\.target)).count == items.count else { throw ContentError.invalid("Invalid build catalog page") }
        var previous: Item?
        for item in items {
            if kind == .wallStyle, item.pattern == nil || item.pattern! >= 65534 { throw ContentError.invalid("Wall style has no valid pattern") }
            let validIdentity = item.guid.map { kind == .water && item.id == 0 && $0 != 0 } ?? (kind == .water ? (65534...65535) : kind == .roof ? (0...65533) : (1...65533)).contains(item.id)
            guard validIdentity, (0...Int(Int32.max)).contains(item.price),
                  item.name.utf16.count <= 512, item.description.utf16.count <= 4096, item.file.utf16.count <= 1024 else {
                throw ContentError.invalid("Invalid build catalog pattern")
            }
            if let previous, item.price < previous.price || item.price == previous.price && item.sortKey <= previous.sortKey {
                throw ContentError.invalid("Build catalog patterns are out of order")
            }
            try item.icon?.validate()
            previous = item
        }
    }
}
