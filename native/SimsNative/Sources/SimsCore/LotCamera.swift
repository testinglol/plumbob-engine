import Foundation

public enum LotCamera: Int, CaseIterable, Codable, Sendable {
    case topLeft = 0
    case topRight = 1
    case bottomRight = 2
    case bottomLeft = 3

    public func cameraPoint(_ point: SIMD2<Float>, lotSize: SIMD2<Float>) -> SIMD2<Float> {
        switch self {
        case .topLeft: point
        case .topRight: SIMD2(lotSize.y - point.y, point.x)
        case .bottomRight: lotSize - point
        case .bottomLeft: SIMD2(point.y, lotSize.x - point.x)
        }
    }

    public func lotPoint(_ point: SIMD2<Float>, lotSize: SIMD2<Float>) -> SIMD2<Float> {
        switch self {
        case .topLeft: point
        case .topRight: SIMD2(point.y, lotSize.y - point.x)
        case .bottomRight: lotSize - point
        case .bottomLeft: SIMD2(lotSize.x - point.y, point.x)
        }
    }

    public func projectedPoint(_ point: SIMD2<Float>, lotSize: SIMD2<Float>, altitude: Float = 0) -> SIMD2<Float> {
        let camera = cameraPoint(point, lotSize: lotSize)
        return SIMD2((camera.x - camera.y) * 32 + 34, (camera.x + camera.y) * 16 + 158 - altitude)
    }

    public func sourceTile(_ tile: SIMD2<Int>, lotSize: SIMD2<Int>) -> SIMD2<Int> {
        switch self {
        case .topLeft: tile
        case .topRight: SIMD2(tile.y, lotSize.y - 1 - tile.x)
        case .bottomRight: SIMD2(lotSize.x - 1 - tile.x, lotSize.y - 1 - tile.y)
        case .bottomLeft: SIMD2(lotSize.x - 1 - tile.y, tile.x)
        }
    }
}
