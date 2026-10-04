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
    private var sceneRoot: URL?
    private var sceneRevision: Int64 = 0
    private var animationSequence: Int64 = 0
    private var sceneTextures: [GPUTexture] = []
    private var cachedTextures: [String: GPUTexture] = [:]
    private var terrainBuffer: GPUBuffer?
    private var meshBuffers: [GPUBuffer?] = []
    private var drawItems: [SceneDrawItem] = []
    private var picker: ScenePicker?
    var liveMode = false
    /// The live game speed the host last reported: 0 paused, 1, 3 or 10.
    var speed = 0
    var uiScale: Float = 2
    var zoom: LotZoom = .near
    var pan = SIMD2<Float>(repeating: 0)
    var lightingEnabled = true

    init(gpu: GPUContext) { self.gpu = gpu }

    private func activeLighting(_ scene: LotScene) -> SceneLighting? { lightingEnabled ? scene.lighting : nil }

    private func pixels(for image: LotScene.Texture, _ data: Data) throws -> (width: Int, height: Int, depth8: Bool, pixels: Data) {
        let depth8 = image.encoding == "depth8"
        return (image.width, image.height, depth8, depth8 ? data : try SpritePixels.premultipliedSRGB(data))
    }

    func loadScene(_ url: URL, revision: Int64 = 0) throws {
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
        terrainBuffer = try makeTerrain(loaded.scene)
        meshBuffers = try makeMeshes(loaded.scene.meshes ?? [])
        drawItems = SceneDrawItem.ordered(in: loaded.scene)
        picker = ScenePicker(scene: loaded.scene, pixels: loaded.pixels)
        sceneTextures = resolved
        cachedTextures = Dictionary(zip(keys, resolved), uniquingKeysWith: { $1 })
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

    func object(at point: SIMD2<Float>, canvas: SIMD2<Float>) -> Int? {
        guard let location = viewport(canvas: canvas)?.scenePoint(point) else { return nil }
        return picker?.object(at: location)
    }

    func wall(at point: SIMD2<Float>, canvas: SIMD2<Float>) -> LotScene.WallSide? {
        guard let location = viewport(canvas: canvas)?.scenePoint(point) else { return nil }
        return picker?.wall(at: location)
    }

    /// Clears the targets and draws the lot into them, as the Metal view's lot pass does.
    func encode(command: OpaquePointer, color: GPUTexture, depth: GPUTexture) throws {
        var colorTarget = SDL_GPUColorTargetInfo()
        colorTarget.texture = color.handle
        colorTarget.clear_color = SDL_FColor(r: 0, g: 0, b: LotRenderer.originalUIBlue, a: 1)
        colorTarget.load_op = SDL_GPU_LOADOP_CLEAR
        colorTarget.store_op = SDL_GPU_STOREOP_STORE
        var depthTarget = SDL_GPUDepthStencilTargetInfo()
        depthTarget.texture = depth.handle
        depthTarget.clear_depth = 1
        depthTarget.load_op = SDL_GPU_LOADOP_CLEAR
        depthTarget.store_op = SDL_GPU_STOREOP_DONT_CARE
        depthTarget.stencil_load_op = SDL_GPU_LOADOP_DONT_CARE
        depthTarget.stencil_store_op = SDL_GPU_STOREOP_DONT_CARE
        guard let pass = SDL_BeginGPURenderPass(command, &colorTarget, 1, &depthTarget) else { throw SDLError("SDL_BeginGPURenderPass") }
        defer { SDL_EndGPURenderPass(pass) }
        let canvas = SIMD2(Float(color.width), Float(color.height))
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
    }
}
