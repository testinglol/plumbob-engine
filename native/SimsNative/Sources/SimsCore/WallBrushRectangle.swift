import Foundation

public struct WallBrushRectangle: Equatable {
    public let x: Int
    public let y: Int
    public let width: Int
    public let height: Int
    public var segmentCount: Int { 2 * (width + height) }

    public init?(start: LotVertex, end: LotVertex) {
        guard [start.x, start.y, end.x, end.y].allSatisfy({ (0...128).contains($0) }), start.x != end.x, start.y != end.y else { return nil }
        x = min(start.x, end.x)
        y = min(start.y, end.y)
        width = abs(end.x - start.x)
        height = abs(end.y - start.y)
    }

    public var lines: [WallBrushLine] {
        [(LotVertex(x: x, y: y), LotVertex(x: x + width, y: y)),
         (LotVertex(x: x, y: y), LotVertex(x: x, y: y + height)),
         (LotVertex(x: x, y: y + height), LotVertex(x: x + width, y: y + height)),
         (LotVertex(x: x + width, y: y), LotVertex(x: x + width, y: y + height))].compactMap { WallBrushLine(start: $0.0, end: $0.1) }
    }
    public func geometry(scene: LotScene) throws -> [LotScene.TerrainVertex] {
        try lines.flatMap { try $0.geometry(scene: scene) }
    }
}

public enum WallBrushSelection: Equatable {
    case line(WallBrushLine, deleting: Bool)
    case rectangle(WallBrushRectangle)

    public init?(start: LotVertex, end: LotVertex, rectangle: Bool, deleting: Bool) {
        if rectangle && !deleting {
            guard let area = WallBrushRectangle(start: start, end: end) else { return nil }
            self = .rectangle(area)
        } else {
            guard let line = WallBrushLine(start: start, end: end) else { return nil }
            self = .line(line, deleting: deleting)
        }
    }
    public var deleting: Bool {
        if case .line(_, let deleting) = self { return deleting }
        return false
    }
    public var command: String {
        switch self {
        case .line(_, let deleting): return deleting ? "WALL_DELETE" : "WALL_LINE"
        case .rectangle: return "WALL_RECT"
        }
    }
    public var arguments: (x: Int, y: Int, x2: Int, y2: Int) {
        switch self {
        case .line(let line, _): return (line.start.x, line.start.y, line.length, line.direction)
        case .rectangle(let area): return (area.x, area.y, area.width, area.height)
        }
    }
    public func geometry(scene: LotScene) throws -> [LotScene.TerrainVertex] {
        switch self {
        case .line(let line, _): return try line.geometry(scene: scene)
        case .rectangle(let area): return try area.geometry(scene: scene)
        }
    }
}
