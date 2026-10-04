import Foundation

public struct FloorBrushRectangle: Equatable {
    public let x: Int
    public let y: Int
    public let width: Int
    public let height: Int
    public var tileCount: Int { (width + 1) * (height + 1) }

    public init?(start: GroundTile, end: GroundTile) {
        self.init(startX: start.x, startY: start.y, endX: end.x, endY: end.y)
    }

    public init?(startX: Int, startY: Int, endX: Int, endY: Int) {
        guard [startX, startY, endX, endY].allSatisfy({ (0...127).contains($0) }) else { return nil }
        x = min(startX, endX)
        y = min(startY, endY)
        width = abs(endX - startX)
        height = abs(endY - startY)
    }
    public func geometry(scene: LotScene, half: Int = 0, water: Bool = false) throws -> [LotScene.TerrainVertex] {
        guard let columns = scene.lotWidth, let rows = scene.lotHeight,
              (1...128).contains(columns), (1...128).contains(rows),
              x + width < columns, y + height < rows, let vertices = scene.constructionVertices,
              vertices.count == columns * rows * 6 else { throw ContentError.invalid("Floor brush exceeds the terrain grid") }
        if let diagonals = scene.floorDiagonals {
            guard diagonals.count == columns * rows, diagonals.allSatisfy({ [0, 16, 32].contains($0) }) else { throw ContentError.invalid("Invalid diagonal floor grid") }
        }
        guard (0...4).contains(half) else { throw ContentError.invalid("Invalid floor brush half") }
        var result: [LotScene.TerrainVertex] = []
        result.reserveCapacity(tileCount * 6)
        for row in y...(y + height) {
            for column in x...(x + width) {
                let start = (row * columns + column) * 6
                let diagonal = scene.floorDiagonals?[row * columns + column] ?? 0
                if diagonal != 0 && (water ? tileCount == 1 : tileCount > 1) { continue }
                let corners: [Int]
                if tileCount == 1 && diagonal != 0 && !water {
                    guard (diagonal == 32 && [1, 2].contains(half)) || (diagonal == 16 && [3, 4].contains(half)) else { throw ContentError.invalid("Floor brush half does not match diagonal") }
                    corners = half == 1 ? [0, 1, 2] : half == 2 ? [3, 4, 5] : half == 3 ? [0, 1, 4] : [1, 2, 4]
                } else { corners = [0, 1, 2, 3, 4, 5] }
                result += corners.map { vertices[start + $0] }
            }
        }
        return result
    }
}

public struct FloorBrushSelection: Equatable {
    public let rectangle: FloorBrushRectangle
    public let half: Int
    public let water: Bool
    public var style: UInt16 { half == 1 ? 1 : half == 4 ? 2 : 0 }
    public init?(rectangle: FloorBrushRectangle, half: Int, water: Bool = false) {
        guard (0...4).contains(half) else { return nil }
        self.rectangle = rectangle
        self.water = water
        self.half = rectangle.tileCount == 1 && !water ? half : 0
    }
    public func geometry(scene: LotScene) throws -> [LotScene.TerrainVertex] {
        try rectangle.geometry(scene: scene, half: half, water: water)
    }
}
