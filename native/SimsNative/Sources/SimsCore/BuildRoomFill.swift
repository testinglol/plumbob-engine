import Foundation

public struct BuildRoomFill: Equatable {
    public let command: String
    public let x: Int
    public let y: Int
    public let level: Int
    public let pattern: UInt16

    public init?(kind: BuildCatalogPage.Kind, pattern: UInt16, tile: GroundTile?, wall: LotScene.WallSide?, removing: Bool = false, selectedLevel: Int = 1) {
        guard kind == .floor || kind == .wall, (removing || pattern > 0), pattern < 65534 else { return nil }
        if kind == .wall, let wall {
            x = wall.x
            y = wall.y
            level = wall.level
        } else if let tile {
            x = tile.x
            y = tile.y
            level = selectedLevel
        } else { return nil }
        guard (0...127).contains(x), (0...127).contains(y), (1...5).contains(level) else { return nil }
        self.pattern = removing ? 0 : pattern
        command = kind == .floor ? "FLOOR_FILL" : "PATTERN_FILL"
    }
}
