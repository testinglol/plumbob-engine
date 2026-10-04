import Foundation

public struct LotVertex: Equatable {
    public let x: Int
    public let y: Int
    public init(x: Int, y: Int) { self.x = x; self.y = y }
}

public struct WallBrushLine: Equatable {
    public let start: LotVertex
    public let end: LotVertex
    public let length: Int
    public let direction: Int
    private static let steps = [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]

    public init?(start: LotVertex, end: LotVertex) {
        guard [start.x, start.y, end.x, end.y].allSatisfy({ (0...128).contains($0) }) else { return nil }
        let dx = end.x - start.x, dy = end.y - start.y
        guard dx != 0 || dy != 0 else { return nil }
        direction = (Int((atan2(Double(dy), Double(dx)) / (.pi / 4)).rounded()) + 8) % 8
        length = max(abs(dx), abs(dy))
        let step = Self.steps[direction]
        self.start = start
        self.end = LotVertex(x: start.x + step.0 * length, y: start.y + step.1 * length)
        guard (0...128).contains(self.end.x), (0...128).contains(self.end.y) else { return nil }
    }

    public static func point(_ vertex: LotVertex, scene: LotScene) -> SIMD2<Float>? {
        guard let width = scene.lotWidth, let height = scene.lotHeight, (1...128).contains(width), (1...128).contains(height),
              (0...width).contains(vertex.x), (0...height).contains(vertex.y), let vertices = scene.constructionVertices,
              vertices.count == width * height * 6 else { return nil }
        let x = min(vertex.x, width - 1), y = min(vertex.y, height - 1)
        let corner = vertex.x == x ? (vertex.y == y ? 0 : 4) : (vertex.y == y ? 1 : 2)
        let value = vertices[(y * width + x) * 6 + corner]
        return SIMD2(value.x, value.y)
    }

    public func geometry(scene: LotScene) throws -> [LotScene.TerrainVertex] {
        let step = Self.steps[direction]
        var result: [LotScene.TerrainVertex] = []
        for offset in 0..<length {
            let a = LotVertex(x: start.x + step.0 * offset, y: start.y + step.1 * offset)
            let b = LotVertex(x: a.x + step.0, y: a.y + step.1)
            guard let first = Self.point(a, scene: scene), let last = Self.point(b, scene: scene) else { throw ContentError.invalid("Wall brush exceeds terrain grid") }
            let points = [first, last, last - SIMD2(0, 112), last - SIMD2(0, 112), first - SIMD2(0, 112), first]
            result += points.map { LotScene.TerrainVertex(x: $0.x, y: $0.y, r: 0, g: 0, b: 0) }
        }
        return result
    }
}

public struct LotVertexPicker {
    private let scene: LotScene
    private let tiles: GroundTilePicker
    public init?(scene: LotScene) {
        guard let tiles = GroundTilePicker(scene: scene) else { return nil }
        self.scene = scene
        self.tiles = tiles
    }
    public func vertex(at point: SIMD2<Float>) -> LotVertex? {
        guard let tile = tiles.tile(at: point) else { return nil }
        let candidates = [LotVertex(x: tile.x, y: tile.y), LotVertex(x: tile.x + 1, y: tile.y), LotVertex(x: tile.x + 1, y: tile.y + 1), LotVertex(x: tile.x, y: tile.y + 1)]
        return candidates.min { a, b in
            guard let first = WallBrushLine.point(a, scene: scene), let last = WallBrushLine.point(b, scene: scene) else { return false }
            let da = first - point, db = last - point
            return da.x * da.x + da.y * da.y < db.x * db.x + db.y * db.y
        }
    }
}
