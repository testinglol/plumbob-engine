import Foundation

public struct BuyCatalogPage: Decodable {
    public struct Item: Decodable {
        public let guid: UInt32
        public let name: String
        public let description: String
        public let price: Int
        public let category: Int
        public let icon: GameplayPanelState.Image?
    }

    public let schemaVersion: Int
    public let category: Int
    public let offset: Int
    public let total: Int
    public let items: [Item]

    public func nextOffset(visibleCapacity: Int) -> Int? {
        let count = min(items.count, max(0, visibleCapacity))
        guard count > 0, offset + count < total else { return nil }
        return offset + count
    }

    public func validate(buildObjects: Bool = false) throws {
        guard schemaVersion == 1, (buildObjects ? (8...12) : (0...7)).contains(category), (0...1_000_000).contains(offset),
              (0...1_000_000).contains(total), items.count <= 64,
              items.count <= max(0, total - offset), !items.isEmpty || offset >= total,
              Set(items.map(\.guid)).count == items.count else {
            throw ContentError.invalid("Invalid buy catalog page")
        }
        var previous: Item?
        for item in items {
            guard item.guid != 0, item.category == category, (0...Int(Int32.max)).contains(item.price),
                  item.name.utf16.count <= 512, item.description.utf16.count <= 4096 else {
                throw ContentError.invalid("Invalid buy catalog item")
            }
            if let previous, item.price < previous.price || item.price == previous.price && item.guid <= previous.guid {
                throw ContentError.invalid("Buy catalog items are out of order")
            }
            try item.icon?.validate()
            previous = item
        }
    }
}
