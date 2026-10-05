import CSDL3
import Foundation
import SimsCore

/// The lot pass of the Metal renderer on SDL_GPU: terrain, the depth-ordered sprites and meshes, lit by the scene's
/// lighting. It keeps the same scene state (textures, mesh buffers, draw order, picker) and the same viewport maths.
final class LotRenderer {
    /// The original UI's blue (82/255) in linear light, the colour the Metal view clears to.
    static let originalUIBlue = Float(pow((82.0 / 255 + 0.055) / 1.055, 2.4))

    let gpu: GPUContext
    private(set) var scene: LotScene?
    private var scenePixels: [Data] = []
    private(set) var sceneRoot: URL?
    private var sceneRevision: Int64 = 0
    private var animationSequence: Int64 = 0
    private var sceneTextures: [GPUTexture] = []
    private var cachedTextures: [String: GPUTexture] = [:]
    private var terrainBuffer: GPUBuffer?
    private var meshBuffers: [GPUBuffer?] = []
    private var drawItems: [SceneDrawItem] = []
    private var picker: ScenePicker?
    private var groundPicker: GroundTilePicker?
    /// The buy and build previews: a coloured footprint or brush over the ground and the held object's ghost. They are
    /// built on the CPU when they change and uploaded with the next frame's uploads.
    private var placementVertices: [TerrainVertex] = []
    private var placementBuffer: GPUBuffer?
    private var placementDirty = false
    private var placementGhost: PlacementPreview.Ghost?
    private var ghostPixels: [(width: Int, height: Int, depth8: Bool, pixels: Data)] = []
    private var ghostTextures: [GPUTexture] = []
    /// Whether the footprint and the ghost are drawn this frame (buy or build mode, and holding an object).
    var showsPlacement = false
    var showsGhost = false
    var liveMode = false
    /// The live game speed the host last reported: 0 paused, 1, 3 or 10.
    var speed = 0
    var uiScale: Float = 2
    var zoom: LotZoom = .near
    var pan = SIMD2<Float>(repeating: 0)
    var lightingEnabled = true
    /// The original UI drawn over the lot this frame, in order, in canvas pixels.
    var overlay: [UIDraw] = []
    /// Whether the lot is drawn under the overlay; the neighborhood and Create a Family screens show only UI.
    var drawsLot = true
    /// Where the Create a Family or wardrobe Sim preview goes: after overlay item `index`, inside `rect` (canvas pixels).
    var previewPlacement: (index: Int, rect: SIMD4<Float>)?
    private var previewTextures: [GPUTexture] = []
    private var previewBuffers: [GPUBuffer?] = []
    private var previewVertexCounts: [Int] = []
    private var uiTextures: [ObjectIdentifier: (source: UITexture, version: Int, texture: GPUTexture)] = [:]

    init(gpu: GPUContext) { self.gpu = gpu }

    /// Uploads the overlay's new and changed UI textures and drops the ones it no longer draws. Uploads go into the
    /// current batch, so call it inside `gpu.batchingUploads` ahead of `encode`.
    func uploadOverlay() throws {
        if placementDirty {
            placementDirty = false
            placementBuffer = try gpu.makeStorageBuffer(placementVertices)
            ghostTextures = try gpu.uploadTextures(ghostPixels)
            ghostPixels = []
        }
        var next: [ObjectIdentifier: (source: UITexture, version: Int, texture: GPUTexture)] = [:]
        var uploads: [UITexture] = []
        for item in overlay {
            let key = ObjectIdentifier(item.texture)
            guard next[key] == nil else { continue }
            if let cached = uiTextures[key], cached.version == item.texture.version {
                next[key] = cached
            } else if !uploads.contains(where: { $0 === item.texture }) {
                uploads.append(item.texture)
            }
        }
        let textures = try gpu.uploadTextures(uploads.map { (width: $0.width, height: $0.height, depth8: false, pixels: $0.pixels) })
        for (source, texture) in zip(uploads, textures) { next[ObjectIdentifier(source)] = (source, source.version, texture) }
        uiTextures = next
    }

    private func activeLighting(_ scene: LotScene) -> SceneLighting? { lightingEnabled ? scene.lighting : nil }

    private func pixels(for image: LotScene.Texture, _ data: Data) throws -> (width: Int, height: Int, depth8: Bool, pixels: Data) {
        let depth8 = image.encoding == "depth8"
        return (image.width, image.height, depth8, depth8 ? data : try SpritePixels.premultipliedSRGB(data))
    }

    func loadScene(_ url: URL, revision: Int64 = 0) throws {
        try gpu.batchingUploads { try load(url, revision: revision) }
    }

    private func load(_ url: URL, revision: Int64) throws {
        let loaded = try LotScene.load(url: url)
        var textures: [GPUTexture?] = []
        var uploads: [(index: Int, image: (width: Int, height: Int, depth8: Bool, pixels: Data))] = []
        var keys: [String] = []
        for (index, image) in loaded.scene.textures.enumerated() {
            let key = url.deletingLastPathComponent().appendingPathComponent(image.file).path
            keys.append(key)
            let format = image.encoding == "depth8" ? SDL_GPU_TEXTUREFORMAT_R8_UNORM : GPUContext.colorFormat
            if let cached = cachedTextures[key], cached.width == image.width, cached.height == image.height, cached.format == format {
                textures.append(cached)
            } else {
                textures.append(nil)
                uploads.append((index, try pixels(for: image, loaded.pixels[index])))
            }
        }
        for (upload, texture) in zip(uploads, try gpu.uploadTextures(uploads.map(\.image))) { textures[upload.index] = texture }
        let resolved = textures.map { $0! }
        scene = loaded.scene
        scenePixels = loaded.pixels
        sceneRoot = url.deletingLastPathComponent()
        sceneRevision = revision
        animationSequence = 0
        pendingFrames = []
        terrainBuffer = try makeTerrain(loaded.scene)
        meshBuffers = try makeMeshes(loaded.scene.meshes ?? [])
        drawItems = SceneDrawItem.ordered(in: loaded.scene)
        picker = ScenePicker(scene: loaded.scene, pixels: loaded.pixels)
        groundPicker = GroundTilePicker(scene: loaded.scene)
        sceneTextures = resolved
        cachedTextures = Dictionary(zip(keys, resolved), uniquingKeysWith: { $1 })
    }

    /// Animation frames the host sent since the last drawn frame, as received.
    private var pendingFrames: [[String: Any]] = []

    func queueAnimation(_ frame: [String: Any]) { pendingFrames.append(frame) }

    /// Applies the queued animation frames before a draw. Each frame replaces every animated sprite and mesh, so only the
    /// newest is decoded whole; older ones still add the textures they introduce, which later frames index into.
    func applyPendingAnimation(into command: OpaquePointer? = nil) throws {
        let frames = pendingFrames
        pendingFrames = []
        guard !frames.isEmpty else { return }
        try gpu.batchingUploads(into: command) { try applyAnimations(frames) }
    }

    private func applyAnimations(_ frames: [[String: Any]]) throws {
        for (index, frame) in frames.enumerated() {
            var frame = frame
            if index < frames.count - 1 {
                guard let textures = frame["textures"] as? [Any], !textures.isEmpty else { continue }
                frame["sprites"] = []
                frame["meshes"] = []
            }
            try applyAnimation(JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: frame)))
        }
    }

    func applyAnimation(_ frame: SceneAnimation) throws {
        guard let scene, let sceneRoot else { throw ContentError.invalid("Animation requires a scene snapshot") }
        let updated = try frame.applying(to: scene, revision: sceneRevision, after: animationSequence)
        let appended = try LotScene.readPixels(textures: frame.textures, root: sceneRoot.resolvingSymlinksInPath().standardizedFileURL)
        let staticBuffers = zip(scene.meshes ?? [], meshBuffers).filter { $0.0.objectID == 0 }.map { $0.1 }
        let meshes = staticBuffers + (try makeMeshes(Array((updated.meshes ?? []).dropFirst(staticBuffers.count))))
        let uploaded = try gpu.uploadTextures(zip(frame.textures, appended).map { try pixels(for: $0.0, $0.1) })
        for (image, texture) in zip(frame.textures, uploaded) { cachedTextures[sceneRoot.appendingPathComponent(image.file).path] = texture }
        scenePixels += appended
        self.scene = updated
        sceneTextures += uploaded
        meshBuffers = meshes
        drawItems = SceneDrawItem.ordered(in: updated)
        picker = ScenePicker(scene: updated, pixels: scenePixels)
        animationSequence = frame.sequence
    }

    private func makeMeshes(_ meshes: [LotScene.Mesh]) throws -> [GPUBuffer?] {
        try meshes.map { mesh in
            try gpu.makeStorageBuffer(mesh.vertices.map { vertex in
                AvatarVertex(position: SIMD4(vertex.x, vertex.y, vertex.z, 1), uv: SIMD2(vertex.u, vertex.v), normal: SIMD4(vertex.nx, vertex.ny, vertex.nz, 0))
            })
        }
    }

    private func makeTerrain(_ scene: LotScene) throws -> GPUBuffer? {
        func linear(_ component: UInt8) -> Float {
            let value = Float(component) / 255
            return value <= 0.04045 ? value / 12.92 : pow((value + 0.055) / 1.055, 2.4)
        }
        return try gpu.makeStorageBuffer((scene.terrainVertices ?? []).map { vertex in
            TerrainVertex(position: SIMD2(vertex.x, vertex.y), color: SIMD4(linear(vertex.r), linear(vertex.g), linear(vertex.b), 1))
        })
    }

    /// Moves to another zoom level, keeping the scene point at the view centre where it was.
    func setZoom(_ level: LotZoom) {
        guard level != zoom else { return }
        pan = SceneViewport.rescaledPan(pan, from: zoom.factor, to: level.factor)
        zoom = level
    }

    private func viewport(canvas: SIMD2<Float>) -> SceneViewport? {
        guard let scene else { return nil }
        return SceneViewport(scene: scene, canvas: canvas, panelHeight: liveMode ? 150 * uiScale : 0, zoom: zoom, uiScale: uiScale, pan: pan)
    }

    var sceneRevisionNumber: Int64 { sceneRevision }
    var viewLevel: Int { scene?.selectedLevel ?? 1 }
    var roofsVisible: Bool { scene?.roofsVisible ?? false }
    var storyCount: Int { scene?.stories ?? 2 }
    var cameraOrientation: LotCamera { scene?.camera ?? .topLeft }

    func containsObject(_ id: Int) -> Bool {
        scene?.sprites.contains { $0.objectID == id } == true || scene?.meshes?.contains { $0.objectID == id } == true
    }

    func floorHit(at point: SIMD2<Float>, canvas: SIMD2<Float>) -> FloorTileHit? {
        guard let location = viewport(canvas: canvas)?.scenePoint(point) else { return nil }
        return groundPicker?.hit(at: location)
    }

    func groundTile(at point: SIMD2<Float>, canvas: SIMD2<Float>) -> GroundTile? { floorHit(at: point, canvas: canvas)?.tile }

    func lotVertex(at point: SIMD2<Float>, canvas: SIMD2<Float>) -> LotVertex? {
        guard let scene, let picker = LotVertexPicker(scene: scene), let location = viewport(canvas: canvas)?.scenePoint(point) else { return nil }
        return picker.vertex(at: location)
    }

    /// The viewport's scale and origin, for placing screen-space feedback over scene points.
    func sceneViewport(canvas: SIMD2<Float>) -> SceneViewport? { viewport(canvas: canvas) }

    private func setPlacement(_ vertices: [TerrainVertex], ghost: PlacementPreview.Ghost? = nil, pixels: [(width: Int, height: Int, depth8: Bool, pixels: Data)] = []) {
        placementVertices = vertices
        placementGhost = ghost
        ghostPixels = pixels
        ghostTextures = []
        placementBuffer = nil
        placementDirty = true
    }

    func updateWallBrush(_ line: WallBrushSelection?) throws {
        guard let line, let scene else { setPlacement([]); return }
        let color: SIMD4<Float> = line.deleting ? SIMD4(0.35, 0.12, 0.02, 0.4) : SIMD4(0.06, 0.12, 0.32, 0.4)
        setPlacement(try line.geometry(scene: scene).map { TerrainVertex(position: SIMD2($0.x, $0.y), color: color) })
    }

    func updateFloorBrush(_ rectangle: FloorBrushSelection?, deleting: Bool = false) throws {
        guard let rectangle, let scene else { setPlacement([]); return }
        let color: SIMD4<Float> = deleting ? SIMD4(0.35, 0.12, 0.02, 0.4) : SIMD4(0.06, 0.12, 0.32, 0.4)
        setPlacement(try rectangle.geometry(scene: scene).map { TerrainVertex(position: SIMD2($0.x, $0.y), color: color) })
    }

    func updatePlacement(_ preview: PlacementPreview?) throws {
        guard let preview, let scene, let sceneRoot else { setPlacement([]); return }
        let color: SIMD4<Float> = preview.valid ? SIMD4(0.04, 0.35, 0.04, 0.4) : SIMD4(0.4, 0.02, 0.02, 0.4)
        let vertices = try preview.geometry(scene: scene).map { TerrainVertex(position: SIMD2($0.x, $0.y), color: color) }
        guard let ghost = preview.ghost else { setPlacement(vertices); return }
        let data = try LotScene.readPixels(textures: ghost.scene.textures, root: sceneRoot.resolvingSymlinksInPath().standardizedFileURL)
        setPlacement(vertices, ghost: ghost, pixels: try zip(ghost.scene.textures, data).map { try pixels(for: $0.0, $0.1) })
    }

    func object(at point: SIMD2<Float>, canvas: SIMD2<Float>) -> Int? {
        guard let location = viewport(canvas: canvas)?.scenePoint(point) else { return nil }
        return picker?.object(at: location)
    }

    func wall(at point: SIMD2<Float>, canvas: SIMD2<Float>) -> LotScene.WallSide? {
        guard let location = viewport(canvas: canvas)?.scenePoint(point) else { return nil }
        return picker?.wall(at: location)
    }

    /// Shows a Sim preview (from `HouseholdAppearancePreview`) at `previewPlacement`, as the macOS renderer does.
    func updateAppearancePreview(_ preview: HouseholdAppearancePreview, pixels: [Data]) throws {
        try preview.validate()
        guard pixels.count == preview.textures.count else { throw ContentError.invalid("Household preview texture data does not match its manifest") }
        let textures = try gpu.uploadTextures(zip(preview.textures, pixels).map { metadata, data in
            (width: metadata.width, height: metadata.height, depth8: false, pixels: try SpritePixels.premultipliedSRGB(data))
        })
        previewBuffers = try makeMeshes(preview.meshes)
        previewTextures = preview.meshes.map { textures[$0.texture] }
        previewVertexCounts = preview.meshes.map { $0.vertices.count }
    }

    func clearAppearancePreview() {
        previewTextures = []
        previewBuffers = []
        previewVertexCounts = []
    }

    /// Clears the targets and draws the lot into them, as the Metal view's lot pass does, then the overlay. A Sim
    /// preview splits the overlay: a second pass keeps the colour, clears the depth and draws the preview's meshes.
    func encode(command: OpaquePointer, color: GPUTexture, depth: GPUTexture) throws {
        let canvas = SIMD2(Float(color.width), Float(color.height))
        let previewing = previewPlacement != nil && !previewBuffers.isEmpty
        let split = previewing ? min(overlay.count, max(0, previewPlacement!.index + 1)) : overlay.count
        var pass = try beginPass(command: command, color: color, depth: depth, clearColor: true)
        if drawsLot { try encodeLot(pass: pass, command: command, canvas: canvas) }
        try encodeOverlay(overlay[0..<split], pass: pass, command: command, canvas: canvas)
        if previewing, let placement = previewPlacement {
            SDL_EndGPURenderPass(pass)
            pass = try beginPass(command: command, color: color, depth: depth, clearColor: false)
            try encodePreview(rect: placement.rect, pass: pass, command: command, canvas: canvas)
            try encodeOverlay(overlay[split...], pass: pass, command: command, canvas: canvas)
        }
        SDL_EndGPURenderPass(pass)
    }

    private func beginPass(command: OpaquePointer, color: GPUTexture, depth: GPUTexture, clearColor: Bool) throws -> OpaquePointer {
        var colorTarget = SDL_GPUColorTargetInfo()
        colorTarget.texture = color.handle
        colorTarget.clear_color = SDL_FColor(r: 0, g: 0, b: LotRenderer.originalUIBlue, a: 1)
        colorTarget.load_op = clearColor ? SDL_GPU_LOADOP_CLEAR : SDL_GPU_LOADOP_LOAD
        colorTarget.store_op = SDL_GPU_STOREOP_STORE
        var depthTarget = SDL_GPUDepthStencilTargetInfo()
        depthTarget.texture = depth.handle
        depthTarget.clear_depth = 1
        depthTarget.load_op = SDL_GPU_LOADOP_CLEAR
        depthTarget.store_op = SDL_GPU_STOREOP_DONT_CARE
        depthTarget.stencil_load_op = SDL_GPU_LOADOP_DONT_CARE
        depthTarget.stencil_store_op = SDL_GPU_STOREOP_DONT_CARE
        guard let pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget) else { throw SDLError("SDL_BeginGPURenderPass") }
        return pass
    }

    private func encodePreview(rect: SIMD4<Float>, pass: OpaquePointer, command: OpaquePointer, canvas: SIMD2<Float>) throws {
        guard rect.z > 0, rect.w > 0 else { return }
        var scissor = SDL_Rect(x: Int32(max(0, rect.x)), y: Int32(max(0, rect.y)), w: Int32(rect.z), h: Int32(rect.w))
        SDL_SetGPUScissor(pass, &scissor)
        SDL_BindGPUGraphicsPipeline(pass, try gpu.pipeline(.avatar, depth: .mesh))
        for index in previewBuffers.indices {
            guard let buffer = previewBuffers[index] else { continue }
            var binding = SDL_GPUTextureSamplerBinding(texture: previewTextures[index].handle, sampler: gpu.sampler)
            SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1)
            var handle: OpaquePointer? = buffer.handle
            SDL_BindGPUVertexStorageBuffers(pass, 0, &handle, 1)
            var transform = Quad(rect: rect, canvas: canvas)
            SDL_PushGPUVertexUniformData(command, 0, &transform, UInt32(MemoryLayout<Quad>.stride))
            SDL_DrawGPUPrimitives(pass, UInt32(previewVertexCounts[index]), 1, 0, 0)
        }
    }

    private func encodeOverlay(_ items: ArraySlice<UIDraw>, pass: OpaquePointer, command: OpaquePointer, canvas: SIMD2<Float>) throws {
        guard !items.isEmpty else { return }
        var scissor = SDL_Rect(x: 0, y: 0, w: Int32(canvas.x), h: Int32(canvas.y))
        SDL_SetGPUScissor(pass, &scissor)
        SDL_BindGPUGraphicsPipeline(pass, try gpu.pipeline(.sprite, depth: .flat))
        for item in items {
            guard let texture = uiTextures[ObjectIdentifier(item.texture)]?.texture else { continue }
            var binding = SDL_GPUTextureSamplerBinding(texture: texture.handle, sampler: gpu.sampler)
            SDL_BindGPUFragmentSamplers(pass, 0, &binding, 1)
            var quad = Quad(rect: item.rect, canvas: canvas, opacity: item.opacity)
            quad.uvRect = item.uv
            quad.tint = SIMD4(repeating: item.opacity)
            SDL_PushGPUVertexUniformData(command, 0, &quad, UInt32(MemoryLayout<Quad>.stride))
            SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0)
        }
    }

    private func encodeLot(pass: OpaquePointer, command: OpaquePointer, canvas: SIMD2<Float>) throws {
        guard let scene, let viewport = viewport(canvas: canvas) else { return }
        let scale = viewport.scale
        let origin = viewport.origin
        // Each zoom level draws its own art at a whole number of screen pixels per texel when the UI scale is whole.
        let artSampler = uiScale == uiScale.rounded() ? gpu.pixelSampler! : gpu.sampler!
        let zoom = self.zoom
        let lighting = activeLighting(scene)
        var scissor = SDL_Rect(x: 0, y: 0, w: Int32(canvas.x), h: Int32(viewport.size.y))
        SDL_SetGPUScissor(pass, &scissor)

        func bind(_ program: GPUContext.Program, _ depth: GPUContext.DepthMode) throws {
            SDL_BindGPUGraphicsPipeline(pass, try gpu.pipeline(program, depth: depth))
        }
        func bindTextures(_ textures: [GPUTexture], sampler: OpaquePointer) {
            var bindings = textures.map { SDL_GPUTextureSamplerBinding(texture: $0.handle, sampler: sampler) }
            SDL_BindGPUFragmentSamplers(pass, 0, &bindings, UInt32(bindings.count))
        }
        func bindVertices(_ buffer: GPUBuffer) {
            var handle: OpaquePointer? = buffer.handle
            SDL_BindGPUVertexStorageBuffers(pass, 0, &handle, 1)
        }
        func push(_ quad: Quad) {
            var quad = quad
            SDL_PushGPUVertexUniformData(command, 0, &quad, UInt32(MemoryLayout<Quad>.stride))
        }

        if let terrainBuffer {
            try bind(.terrain, .flat)
            bindVertices(terrainBuffer)
            var transform = Quad(rect: SIMD4(origin.x, origin.y, scale, scale), canvas: canvas)
            transform.tint = lighting?.outside.multiplier ?? SIMD4(repeating: 1)
            push(transform)
            SDL_DrawGPUPrimitives(pass, UInt32(terrainBuffer.count), 1, 0, 0)
        }
        for item in drawItems {
            switch item {
            case .sprite(let index):
                let sprite = scene.sprites[index]
                var texture = sprite.texture
                var depthTexture = sprite.depthTexture
                var rect = SIMD4(sprite.x, sprite.y, sprite.width, sprite.height)
                if let image = sprite.image(for: zoom) {
                    texture = image.texture
                    depthTexture = image.depthTexture
                    rect = SIMD4(sprite.x + image.x, sprite.y + image.y, image.width, image.height)
                }
                if let depthTexture {
                    try bind(.spriteDepth, .mesh)
                    bindTextures([sceneTextures[texture], sceneTextures[depthTexture]], sampler: artSampler)
                } else {
                    try bind(.sprite, .flat)
                    bindTextures([sceneTextures[texture]], sampler: artSampler)
                }
                var quad = Quad(rect: SIMD4(origin.x + rect.x * scale, origin.y + rect.y * scale, rect.z * scale, rect.w * scale), canvas: canvas, flip: sprite.flip)
                quad.depthInterval = SIMD4(sprite.depthNear ?? 0, sprite.depthFar ?? 0, 0, 0)
                quad.tint = lighting?.multiplier(room: sprite.room) ?? SIMD4(repeating: 1)
                push(quad)
                SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0)
            case .mesh(let index):
                guard let mesh = scene.meshes?[index], let buffer = meshBuffers[index] else { continue }
                let unlit = mesh.unlit == true
                try bind(unlit ? .surface : .avatar, unlit && mesh.floor?.water == nil && (mesh.level ?? 1) == 1 ? .flat : .mesh)
                bindTextures([sceneTextures[mesh.texture(for: zoom)]], sampler: mesh.roof != nil ? gpu.roofSampler : mesh.floor != nil ? artSampler : gpu.sampler)
                bindVertices(buffer)
                var transform = Quad(rect: SIMD4(origin.x, origin.y, scale, scale), canvas: canvas)
                transform.tint = lighting?.multiplier(room: mesh.room) ?? SIMD4(repeating: 1)
                push(transform)
                SDL_DrawGPUPrimitives(pass, UInt32(mesh.vertices.count), 1, 0, 0)
            }
        }
        if showsPlacement, let placementBuffer {
            try bind(.placement, .flat)
            bindVertices(placementBuffer)
            push(Quad(rect: SIMD4(origin.x, origin.y, scale, scale), canvas: canvas))
            SDL_DrawGPUPrimitives(pass, UInt32(placementBuffer.count), 1, 0, 0)
        }
        if showsGhost, let ghost = placementGhost, ghostTextures.count == ghost.scene.textures.count {
            try bind(.ghost, .flat)
            for sprite in ghost.scene.sprites {
                var texture = sprite.texture
                var rect = SIMD4(sprite.x, sprite.y, sprite.width, sprite.height)
                if let image = sprite.image(for: zoom) {
                    texture = image.texture
                    rect = SIMD4(sprite.x + image.x, sprite.y + image.y, image.width, image.height)
                }
                bindTextures([ghostTextures[texture]], sampler: artSampler)
                push(Quad(rect: SIMD4(origin.x + (ghost.x + rect.x) * scale, origin.y + (ghost.y + rect.y) * scale, rect.z * scale, rect.w * scale),
                          canvas: canvas, flip: sprite.flip, opacity: 0.6))
                SDL_DrawGPUPrimitives(pass, 6, 1, 0, 0)
            }
        }
    }
}

/// One original-UI image drawn over the lot: a rectangle in canvas pixels and the part of the texture it shows.
struct UIDraw {
    var texture: UITexture
    var rect: SIMD4<Float>
    var uv = SIMD4<Float>(0, 0, 1, 1)
    var opacity: Float = 1
}
