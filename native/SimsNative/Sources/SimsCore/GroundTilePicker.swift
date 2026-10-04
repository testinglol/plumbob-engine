import Foundation

public struct GroundTile: Equatable, Hashable {
    public let x: Int
    public let y: Int
    public var placementX: Int { x * 16 + 8 }
    public var placementY: Int { y * 16 + 8 }
}

public struct FloorTileHit: Equatable {
    public let tile: GroundTile
    public let half: Int
    public var style: UInt16 { half == 1 ? 1 : half == 4 ? 2 : 0 }
}

public struct GroundTilePicker {
    private let width: Int
    private let vertices: [LotScene.TerrainVertex]
    private let diagonals: [UInt8]

    public init?(scene: LotScene) {
        guard let width = scene.lotWidth, let height = scene.lotHeight,
              (1...128).contains(width), (1...128).contains(height),
              let vertices = scene.constructionVertices, vertices.count == width * height * 6 else { return nil }
        let diagonals = scene.floorDiagonals ?? Array(repeating: 0, count: width * height)
        guard diagonals.count == width * height, diagonals.allSatisfy({ [0, 16, 32].contains($0) }) else { return nil }
        self.width = width
        self.vertices = vertices
        self.diagonals = diagonals
    }

    public func tile(at point: SIMD2<Float>) -> GroundTile? { hit(at: point)?.tile }

    public func hit(at point: SIMD2<Float>) -> FloorTileHit? {
        guard point.x.isFinite, point.y.isFinite else { return nil }
        func coordinates(_ a: LotScene.TerrainVertex, _ b: LotScene.TerrainVertex, _ c: LotScene.TerrainVertex) -> SIMD2<Float>? {
            let ab = SIMD2(b.x - a.x, b.y - a.y), ac = SIMD2(c.x - a.x, c.y - a.y), ap = point - SIMD2(a.x, a.y)
            let determinant = ab.x * ac.y - ab.y * ac.x
            guard determinant.isFinite, abs(determinant) > 0.000001 else { return nil }
            let u = (ap.x * ac.y - ap.y * ac.x) / determinant
            let v = (ab.x * ap.y - ab.y * ap.x) / determinant
            guard u >= -0.00001, v >= -0.00001, u + v <= 1.00001 else { return nil }
            return SIMD2(u, v)
        }
        for index in (0..<(vertices.count / 6)).reversed() {
            let start = index * 6
            let local: SIMD2<Float>
            if let weights = coordinates(vertices[start], vertices[start + 1], vertices[start + 2]) {
                local = SIMD2(weights.x + weights.y, weights.y)
            } else if let weights = coordinates(vertices[start + 3], vertices[start + 4], vertices[start + 5]) {
                local = SIMD2(1 - weights.x - weights.y, 1 - weights.y)
            } else { continue }
            let half = diagonals[index] == 32 ? (local.x >= local.y ? 1 : 2) : diagonals[index] == 16 ? (local.x + local.y <= 1 ? 3 : 4) : 0
            return FloorTileHit(tile: GroundTile(x: index % width, y: index / width), half: half)
        }
        return nil
    }
}
