import Foundation

public struct EditableLotObject: Decodable, Equatable {
    public let id: Int
    public let guid: UInt32
    public let level: Int
    public let direction: Int
    public let movable: Bool
    public let sellable: Bool
}

public struct BuySelection {
    public enum Target: Equatable {
        case catalog(UInt32)
        case placed(EditableLotObject)
    }
    public private(set) var target: Target?
    public private(set) var direction = 1
    public init() {}

    public mutating func chooseCatalog(_ guid: UInt32) {
        guard guid != 0 else { return }
        target = .catalog(guid)
        direction = 1
    }
    public mutating func chooseObject(_ object: EditableLotObject) {
        guard object.id > 0, object.guid != 0, (1...5).contains(object.level),
              [1, 4, 16, 64].contains(object.direction), object.movable || object.sellable else { return }
        target = .placed(object)
        direction = object.direction
    }
    public mutating func rotate() {
        guard let target else { return }
        if case .placed(let object) = target, !object.movable { return }
        direction = direction == 64 ? 1 : direction * 4
    }
    public mutating func cancel() { target = nil }
    public mutating func reconcile(objects: [EditableLotObject]) {
        guard case .placed(let held) = target else { return }
        guard let current = objects.first(where: { $0.id == held.id && $0.guid == held.guid }),
              (1...5).contains(current.level), current.level == held.level, current.movable || current.sellable else { cancel(); return }
        target = .placed(current)
    }
}
