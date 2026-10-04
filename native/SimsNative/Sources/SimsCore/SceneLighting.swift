import Foundation

public struct SceneLighting: Decodable {
    public struct RGB: Decodable {
        public let r: UInt8
        public let g: UInt8
        public let b: UInt8
        public var multiplier: SIMD4<Float> { SIMD4(Float(r) / 255, Float(g) / 255, Float(b) / 255, 1) }
    }
    public struct Room: Decodable {
        public let id: Int
        public let outside: Bool
        public let ambient: Int
        public let daylight: Int
        public let r: UInt8
        public let g: UInt8
        public let b: UInt8
        public var multiplier: SIMD4<Float> { SIMD4(Float(r) / 255, Float(g) / 255, Float(b) / 255, 1) }
    }
    public let outside: RGB
    public let rooms: [Room]

    public func validate() throws {
        guard !rooms.isEmpty, rooms.count <= 65535,
              rooms.enumerated().allSatisfy({ $0.offset == $0.element.id && (0...100).contains($0.element.ambient) && (0...100).contains($0.element.daylight) }) else {
            throw ContentError.invalid("Invalid room lighting table")
        }
    }

    public func multiplier(room: Int?) -> SIMD4<Float> {
        guard let room else { return SIMD4(repeating: 1) }
        if room == 65535 { return SIMD4(repeating: 1) }
        guard rooms.indices.contains(room) else { return SIMD4(repeating: 1) }
        return rooms[room].multiplier
    }

    func validate(room: Int?) throws {
        if let room, room != 65535 && !rooms.indices.contains(room) { throw ContentError.invalid("Material references missing room lighting") }
    }
}
