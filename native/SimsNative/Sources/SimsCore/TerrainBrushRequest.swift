import Foundation

public enum TerrainBrushMode: String, CaseIterable, Equatable {
    case lower
    case level
    case raise
    case grass

    public var label: String {
        switch self {
        case .lower: return "Lower terrain"
        case .level: return "Level terrain"
        case .raise: return "Raise terrain"
        case .grass: return "Grass"
        }
    }
}

public struct ArchitectureCommandRequest: Encodable, Equatable {
    public let command: String
    public let x: Int
    public let y: Int
    public let level: Int
    public let x2: Int
    public let y2: Int
    public let pattern: UInt16
    public let style: UInt16

    public enum CodingKeys: String, CodingKey { case command, x, y, level, x2, y2, pattern, style }

    public var payload: [String: Any] {
        ["command": command, "x": x, "y": y, "level": level, "x2": x2, "y2": y2, "pattern": pattern, "style": style]
    }
}

public enum ConstructionHistoryAction: String, Equatable { case undo, redo }

public enum TerrainHeightDrag {
    public static let sceneUnitsPerHeightLevel = 0.75

    public static func delta(startY: Double, endY: Double, viewportScale: Double,
                             mode: TerrainBrushMode) throws -> Int16 {
        guard startY.isFinite, endY.isFinite, viewportScale.isFinite, viewportScale > 0 else {
            throw ContentError.invalid("Terrain height drag requires finite screen positions and viewport scale")
        }
        let heightLevels = ((startY - endY) / (viewportScale * sceneUnitsPerHeightLevel)).rounded()
        guard heightLevels.isFinite else { throw ContentError.invalid("Terrain height drag is outside the supported range") }
        let direction: Double
        switch mode {
        case .raise: direction = 1
        case .lower: direction = -1
        case .level, .grass: throw ContentError.invalid("Height delta is only valid for raise or lower gestures")
        }
        return Int16(min(Double(Int16.max), max(Double(Int16.min), heightLevels * direction)))
    }
}

public struct TerrainBrushGesture {
    public private(set) var start: GroundTile?
    public private(set) var end: GroundTile?
    public private(set) var samples: [GroundTile] = []
    private var visited = Set<GroundTile>()

    public init() {}

    public mutating func begin(at tile: GroundTile) {
        start = tile
        end = tile
        samples = [tile]
        visited = [tile]
    }

    public mutating func move(to tile: GroundTile) {
        guard start != nil else { return }
        end = tile
        guard let previous = samples.last, previous != tile else { return }
        for point in Self.rasterize(from: previous, to: tile).dropFirst() where visited.insert(point).inserted {
            samples.append(point)
        }
    }

    public mutating func cancel() {
        start = nil
        end = nil
        samples = []
        visited = []
    }

    public mutating func finish(mode: TerrainBrushMode, level: Int, scene: LotScene,
                                heightDelta: Int16? = nil, grassStep: Int16 = 32,
                                smooth: Bool = false) throws -> ArchitectureCommandRequest {
        guard let start else { throw ContentError.invalid("Terrain gesture has no start tile") }
        let end = self.end
        self.start = nil
        self.end = nil
        return try TerrainBrushRequest.make(mode: mode, start: start, end: end, level: level,
                                            scene: scene, heightDelta: heightDelta,
                                            grassStep: grassStep, smooth: smooth)
    }

    public mutating func finishStroke(mode: TerrainBrushMode, level: Int, scene: LotScene,
                                      heightDelta: Int16? = nil, grassStep: Int16 = 32,
                                      smooth: Bool = false) throws -> [ArchitectureCommandRequest] {
        guard let start else { throw ContentError.invalid("Terrain gesture has no start tile") }
        let end = self.end
        let samples = self.samples
        self.start = nil
        self.end = nil
        self.samples = []
        self.visited = []
        return try TerrainBrushRequest.makeStroke(mode: mode, start: start, end: end, samples: samples,
                                                  level: level, scene: scene, heightDelta: heightDelta,
                                                  grassStep: grassStep, smooth: smooth)
    }

    private static func rasterize(from start: GroundTile, to end: GroundTile) -> [GroundTile] {
        var x = start.x
        var y = start.y
        let dx = abs(end.x - start.x)
        let sx = start.x < end.x ? 1 : -1
        let dy = -abs(end.y - start.y)
        let sy = start.y < end.y ? 1 : -1
        var error = dx + dy
        var result = [start]
        while x != end.x || y != end.y {
            let twice = 2 * error
            if twice >= dy { error += dy; x += sx }
            if twice <= dx { error += dx; y += sy }
            result.append(GroundTile(x: x, y: y))
        }
        return result
    }
}

public enum TerrainBrushRequest {
    public static func makeStroke(mode: TerrainBrushMode, start: GroundTile, end: GroundTile?, samples: [GroundTile],
                                   level: Int, scene: LotScene, heightDelta: Int16? = nil,
                                   grassStep: Int16 = 32, smooth: Bool = false) throws -> [ArchitectureCommandRequest] {
        switch mode {
        case .level:
            return [try make(mode: mode, start: start, end: end, level: level, scene: scene,
                             heightDelta: heightDelta, grassStep: grassStep, smooth: smooth)]
        case .raise, .lower:
            guard let heightDelta else { throw ContentError.invalid("Terrain raise or lower requires a vertical drag delta") }
            return [try make(mode: mode, start: start, end: nil, level: level, scene: scene,
                             heightDelta: heightDelta, grassStep: grassStep, smooth: smooth)]
        case .grass:
            let points = samples.isEmpty ? [start] : samples
            guard let width = scene.lotWidth, let height = scene.lotHeight, points.count <= width * height else {
                throw ContentError.invalid("Terrain stroke exceeds the lot tile count")
            }
            return try points.map { try make(mode: mode, start: $0, end: nil, level: level, scene: scene,
                                             heightDelta: heightDelta, grassStep: grassStep, smooth: smooth) }
        }
    }

    public static func make(mode: TerrainBrushMode, start: GroundTile, end: GroundTile?, level: Int,
                            scene: LotScene, heightDelta: Int16? = nil, grassStep: Int16 = 32,
                            smooth: Bool = false) throws -> ArchitectureCommandRequest {
        guard let width = scene.lotWidth, let height = scene.lotHeight,
              width > 0, height > 0, (1...(scene.stories ?? 5)).contains(level),
              (0..<width).contains(start.x), (0..<height).contains(start.y),
              let heights = scene.terrainHeights, heights.count == width * height else {
            throw ContentError.invalid("Terrain edit requires a valid lot height grid and start tile")
        }
        let startIndex = start.y * width + start.x
        let currentHeight = heights[startIndex]
        let encodedPattern: UInt16 = smooth ? 1 : 0
        switch mode {
        case .raise, .lower:
            guard let heightDelta else { throw ContentError.invalid("Terrain raise or lower requires a vertical drag delta") }
            let target = min(64, max(0, Int32(currentHeight) + Int32(heightDelta)))
            return ArchitectureCommandRequest(command: "TERRAIN_RAISE", x: start.x, y: start.y, level: level,
                x2: 0, y2: 0, pattern: encodedPattern, style: UInt16(bitPattern: Int16(target)))
        case .level:
            guard let end, (0..<width).contains(end.x), (0..<height).contains(end.y) else {
                throw ContentError.invalid("Terrain flatten requires an end tile inside the lot")
            }
            let left = min(start.x, end.x), top = min(start.y, end.y)
            let right = max(start.x, end.x), bottom = max(start.y, end.y)
            return ArchitectureCommandRequest(command: "TERRAIN_FLATTEN", x: left, y: top, level: level,
                x2: right - left, y2: bottom - top, pattern: encodedPattern,
                style: UInt16(bitPattern: currentHeight))
        case .grass:
            let delta = grassStep
            return ArchitectureCommandRequest(command: "GRASS_DOT", x: start.x, y: start.y, level: level,
                x2: 0, y2: 0, pattern: UInt16(bitPattern: delta), style: 0)
        }
    }
}
