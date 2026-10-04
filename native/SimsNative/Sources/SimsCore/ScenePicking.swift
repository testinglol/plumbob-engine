import Foundation

public enum SceneDrawItem: Equatable {
    case sprite(Int)
    case mesh(Int)

    public static func ordered(in scene: LotScene) -> [SceneDrawItem] {
        var entries: [(level: Int, layer: Int, depth: Float, ordinal: Int, item: SceneDrawItem)] = scene.sprites.enumerated().map {
            ($0.element.level ?? 1, $0.element.layer ?? 0, $0.element.depth ?? Float($0.offset), $0.offset, .sprite($0.offset))
        }
        entries += (scene.meshes ?? []).enumerated().map { ($0.element.level ?? 1, $0.element.layer ?? 1, $0.element.depth, scene.sprites.count + $0.offset, .mesh($0.offset)) }
        return entries.sorted {
            if $0.level != $1.level { return $0.level < $1.level }
            if $0.layer != $1.layer { return $0.layer < $1.layer }
            if $0.depth != $1.depth { return $0.depth < $1.depth }
            return $0.ordinal < $1.ordinal
        }.map(\.item)
    }
}

/// The three zoom levels of the original lot view, numbered like FreeSO's WorldZoom. Scene units are medium-zoom
/// pixels, so near draws every scene unit as two screen pixels and far as half of one; the art for each level is drawn
/// at its own resolution, which keeps sprites sharp instead of magnifying the medium art.
public enum LotZoom: Int, CaseIterable, Sendable {
    case far = 1
    case medium = 2
    case near = 3

    /// Screen pixels per scene unit at a UI scale of 1.
    public var factor: Float {
        switch self {
        case .far: 0.5
        case .medium: 1
        case .near: 2
        }
    }

    /// VMEntity.TickSounds divides the volume of zoom-aware sounds by 4 - zoom: near 1, medium 1/2, far 1/3.
    public var soundGain: Float { 1 / Float(4 - rawValue) }

    /// One step closer (positive) or farther (negative), stopping at near and far.
    public func stepped(_ steps: Int) -> LotZoom {
        LotZoom(rawValue: min(LotZoom.near.rawValue, max(LotZoom.far.rawValue, rawValue + steps)))!
    }
}

public struct SceneViewport {
    public let size: SIMD2<Float>
    public let scale: Float
    public let origin: SIMD2<Float>

    /// Lays the scene out at an exact zoom factor with a whole-pixel origin, so at near and medium every texel lands on
    /// whole screen pixels and nearest sampling stays crisp. `pan` moves the scene centre away from the view centre.
    public init(scene: LotScene, canvas: SIMD2<Float>, panelHeight: Float, zoom: LotZoom, uiScale: Float, pan: SIMD2<Float>) {
        size = SIMD2(canvas.x, max(1, canvas.y - panelHeight))
        scale = max(uiScale, 0.01) * zoom.factor
        let clamped = SceneViewport.clampedPan(pan, scene: scene, scale: scale)
        origin = ((size - SIMD2(scene.width, scene.height) * scale) / 2 + clamped).rounded(.toNearestOrEven)
    }

    /// Keeps the view centre inside the lot.
    public static func clampedPan(_ pan: SIMD2<Float>, scene: LotScene, scale: Float) -> SIMD2<Float> {
        let limit = SIMD2(scene.width, scene.height) * scale / 2
        return pan.clamped(lowerBound: -limit, upperBound: limit)
    }

    /// The pan that keeps the same scene point at the view centre after the scale changes.
    public static func rescaledPan(_ pan: SIMD2<Float>, from oldScale: Float, to newScale: Float) -> SIMD2<Float> {
        guard oldScale > 0, newScale > 0 else { return pan }
        return pan * (newScale / oldScale)
    }

    public func scenePoint(_ point: SIMD2<Float>) -> SIMD2<Float>? {
        guard point.x.isFinite, point.y.isFinite, point.x >= 0, point.y >= 0,
              point.x < size.x, point.y < size.y, scale.isFinite, scale > 0 else { return nil }
        return (point - origin) / scale
    }
}

public struct ScenePicker {
    private let scene: LotScene
    private let pixels: [Data]
    private let items: [SceneDrawItem]

    public init(scene: LotScene, pixels: [Data]) {
        self.scene = scene
        self.pixels = pixels
        items = SceneDrawItem.ordered(in: scene)
    }

    public var camera: LotCamera { scene.camera }

    private func alpha(texture: Int, uv: SIMD2<Float>, repeating: Bool = false) -> Float {
        let info = scene.textures[texture]
        let data = pixels[texture]
        let coordinates = repeating ? SIMD2(uv.x - floor(uv.x), uv.y - floor(uv.y)) : SIMD2(max(0, min(1, uv.x)), max(0, min(1, uv.y)))
        let p = SIMD2(coordinates.x * Float(info.width) - 0.5, coordinates.y * Float(info.height) - 0.5)
        let x = Int(floor(p.x)), y = Int(floor(p.y))
        let fraction = p - SIMD2(Float(x), Float(y))
        func sample(_ x: Int, _ y: Int) -> Float {
            let column = repeating ? (x % info.width + info.width) % info.width : max(0, min(info.width - 1, x))
            let row = repeating ? (y % info.height + info.height) % info.height : max(0, min(info.height - 1, y))
            let index = (row * info.width + column) * 4 + 3
            return Float(data[index]) / 255
        }
        let top = sample(x, y) * (1 - fraction.x) + sample(x + 1, y) * fraction.x
        let bottom = sample(x, y + 1) * (1 - fraction.x) + sample(x + 1, y + 1) * fraction.x
        return top * (1 - fraction.y) + bottom * fraction.y
    }

    private enum Hit { case object(Int), wall(LotScene.WallSide) }

    public func object(at point: SIMD2<Float>) -> Int? {
        if case .object(let id) = hit(at: point) { return id }
        return nil
    }

    public func wall(at point: SIMD2<Float>) -> LotScene.WallSide? {
        if case .wall(let wall) = hit(at: point) { return wall }
        return nil
    }

    private func hit(at point: SIMD2<Float>) -> Hit? {
        guard point.x.isFinite, point.y.isFinite, point.x >= 0, point.y >= 0,
              point.x < scene.width, point.y < scene.height else { return nil }
        var storedDepth: Float = 1
        var visibleHit: Hit?
        for item in items {
            switch item {
            case .sprite(let index):
                let sprite = scene.sprites[index]
                var uv = (point - SIMD2(sprite.x, sprite.y)) / SIMD2(sprite.width, sprite.height)
                guard uv.x >= 0, uv.y >= 0, uv.x < 1, uv.y < 1 else { continue }
                if sprite.flip { uv.x = 1 - uv.x }
                let opacity = alpha(texture: sprite.texture, uv: uv)
                if let texture = sprite.depthTexture, let near = sprite.depthNear, let far = sprite.depthFar {
                    guard opacity >= 0.25 else { continue }
                    let info = scene.textures[texture]
                    let x = min(info.width - 1, Int(uv.x * Float(info.width)))
                    let y = min(info.height - 1, Int(uv.y * Float(info.height)))
                    let raw = pixels[texture][y * info.width + x]
                    guard raw != 255 else { continue }
                    let depth = near + (far - near) * Float(raw) / 254
                    guard depth <= storedDepth else { continue }
                    storedDepth = depth
                } else if opacity < 0.01 { continue }
                let id = sprite.objectID ?? 0
                visibleHit = sprite.wall.map { .wall($0) } ?? (id == 0 ? nil : .object(id))
            case .mesh(let index):
                guard let mesh = scene.meshes?[index] else { continue }
                for offset in stride(from: 0, to: mesh.vertices.count, by: 3) {
                    let a = mesh.vertices[offset], b = mesh.vertices[offset + 1], c = mesh.vertices[offset + 2]
                    let ab = SIMD2(b.x - a.x, b.y - a.y), ac = SIMD2(c.x - a.x, c.y - a.y)
                    let relative = point - SIMD2(a.x, a.y)
                    let determinant = ab.x * ac.y - ab.y * ac.x
                    guard abs(determinant) > 0.000001 else { continue }
                    let weightB = (relative.x * ac.y - relative.y * ac.x) / determinant
                    let weightC = (ab.x * relative.y - ab.y * relative.x) / determinant
                    let weightA = 1 - weightB - weightC
                    guard min(weightA, weightB, weightC) >= 0 else { continue }
                    let depth = a.z * weightA + b.z * weightB + c.z * weightC
                    let usesDepth = mesh.unlit != true || mesh.floor?.water != nil || (mesh.level ?? 1) > 1
                    guard !usesDepth || depth <= storedDepth else { continue }
                    let uv = SIMD2(a.u, a.v) * weightA + SIMD2(b.u, b.v) * weightB + SIMD2(c.u, c.v) * weightC
                    guard alpha(texture: mesh.texture, uv: uv, repeating: mesh.roof != nil) >= 0.01 else { continue }
                    if usesDepth { storedDepth = depth }
                    visibleHit = mesh.objectID == 0 ? nil : .object(mesh.objectID)
                }
            }
        }
        return visibleHit
    }
}
