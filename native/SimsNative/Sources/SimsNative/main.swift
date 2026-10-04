import AppKit
import AVFoundation
import MetalKit
import SimsCore

let originalUIBlue = pow((82.0 / 255.0 + 0.055) / 1.055, 2.4)

@MainActor
final class OriginalUIRenderer: NSObject, MTKViewDelegate {
    struct Quad {
        var rect: SIMD4<Float>
        var canvas: SIMD2<Float>
        var padding = SIMD2<Float>(repeating: 0)
        var uvRect = SIMD4<Float>(0, 0, 1, 1)
        var depthInterval = SIMD4<Float>(repeating: 0)
        var tint = SIMD4<Float>(repeating: 1)
    }

    struct TerrainVertex {
        var position: SIMD2<Float>
        var padding = SIMD2<Float>(repeating: 0)
        var color: SIMD4<Float>
    }
    struct AvatarVertex {
        var position: SIMD4<Float>
        var uv: SIMD2<Float>
        var padding = SIMD2<Float>(repeating: 0)
        var normal: SIMD4<Float>
    }

    let device: MTLDevice
    let content: GameContent
    let queue: MTLCommandQueue
    let pipeline: MTLRenderPipelineState
    let spriteDepthPipeline: MTLRenderPipelineState
    let terrainPipeline: MTLRenderPipelineState
    let placementPipeline: MTLRenderPipelineState
    let ghostPipeline: MTLRenderPipelineState
    let surfacePipeline: MTLRenderPipelineState
    let avatarPipeline: MTLRenderPipelineState
    let flatDepth: MTLDepthStencilState
    let meshDepth: MTLDepthStencilState
    let sampler: MTLSamplerState
    let roofSampler: MTLSamplerState
    /// Nearest sampling for art drawn at a whole number of screen pixels per texel, so zoomed sprites stay sharp.
    let pixelSampler: MTLSamplerState
    let background: MTLTexture
    let panel: MTLTexture
    let pieFont: SimsBitmapFont
    let gameplay: OriginalGameplayOverlay
    let buy: OriginalBuyOverlay
    let build: OriginalBuildOverlay
    let soundOptions: OriginalSoundOptionsOverlay
    var editingViewChanged: ((Bool) -> Void)?
    var buyMode = false { didSet { editingViewChanged?(buyMode || buildMode) } }
    var buildMode = false { didSet { editingViewChanged?(buyMode || buildMode) } }
    var objectEditing: Bool { buyMode || buildMode && (build.objectTool != nil || build.selectedObjectGUID != nil) }
    var selectedCatalogPrice: Int? {
        if buildMode, let guid = build.selectedObjectGUID { return build.page?.items.first { $0.guid == guid }?.price }
        return buy.selectedItem?.price
    }
    func chooseCatalogObject(_ guid: UInt32) {
        if buildMode && build.objectTool == nil && build.kind == .water {
            build.chooseObject(guid, budget: gameplay.state?.budget)
            if build.selectedObjectGUID == guid { buy.selection.chooseCatalog(guid) }
        } else { buy.choose(guid, budget: gameplay.state?.budget) }
    }
    let contentSize: CGSize
    var scene: LotScene?
    var neighborhood: OriginalNeighborhoodOverlay?
    var neighborhoodHouseSelected: ((Int) -> Void)?
    var householdCreation: OriginalHouseholdCreationOverlay?
    private(set) var cameraOrientation: LotCamera = .topLeft
    var cameraOrientationRequested: ((LotCamera) -> Void)?
    var sceneTextures: [MTLTexture] = []
    private var scenePixels: [Data] = []
    private var sceneRoot: URL?
    private var sceneRevision: Int64 = 0
    private var animationSequence: Int64 = 0
    private var terrainBuffer: MTLBuffer?
    private var terrainVertexCount = 0
    private var meshBuffers: [MTLBuffer] = []
    private var drawItems: [SceneDrawItem] = []
    private var picker: ScenePicker?
    private var groundPicker: GroundTilePicker?
    private var placementBuffer: MTLBuffer?
    private var placementVertexCount = 0
    private var placementGhost: PlacementPreview.Ghost?
    private var ghostTextures: [MTLTexture] = []
    private var ghostCache: [String: MTLTexture] = [:]
    private var householdPreviewTextures: [MTLTexture] = []
    private var householdPreviewBuffers: [MTLBuffer] = []
    private var householdPreviewVertexCounts: [Int] = []
    var currentSceneRevision: Int64 { sceneRevision }
    var liveMode = false
    var uiScale: Float = 2
    var speed = 0
    var viewLevel: Int { scene?.selectedLevel ?? 1 }
    var roofsVisible: Bool { scene?.roofsVisible ?? false }
    var roofStyle: UInt16 = 16
    var roofPitch: Float = 0.66
    var storyCount: Int { scene?.stories ?? 2 }
    var wallsUp = false
    var wallMode = "down"
    var zoom: LotZoom = .near
    /// Wheel travel not yet turned into a zoom step.
    var zoomTravel: Float = 0
    var pan = SIMD2<Float>(repeating: 0)
    var speedTextures: [MTLTexture] = []
    private var universalTextures: [MTLTexture] = []
    var pieMenu: OriginalPieOverlay?
    var gameDialog: OriginalDialogOverlay?
    var pluginPanel: OriginalPluginPanelOverlay?
    var familyPicker: OriginalFamilyPickerOverlay?
    var outfitPicker: OriginalOutfitPickerOverlay?
    let optionsPanel: OriginalOptionsPanelOverlay
    var optionsMode = false
    var lightingEnabled = true
    private func activeLighting(_ scene: LotScene) -> SceneLighting? { lightingEnabled ? scene.lighting : nil }
    private var cachedTextures: [String: MTLTexture] = [:]

    init(content: GameContent, device: MTLDevice, sceneURL: URL? = nil) throws {
        self.device = device
        self.content = content
        guard let queue = device.makeCommandQueue() else { throw ContentError.invalid("Cannot create a Metal command queue") }
        self.queue = queue
        let shader = """
        #include <metal_stdlib>
        using namespace metal;
        struct Quad { float4 rect; float2 canvas; float2 padding; float4 uvRect; float4 depthInterval; float4 tint; };
        struct Vertex { float4 position [[position]]; float2 uv; };
        vertex Vertex spriteVertex(uint id [[vertex_id]], constant Quad &quad [[buffer(0)]]) {
            const float2 corners[6] = {float2(0,0),float2(1,0),float2(0,1),float2(0,1),float2(1,0),float2(1,1)};
            float2 uv = corners[id];
            float2 pixel = quad.rect.xy + uv * quad.rect.zw;
            Vertex result;
            result.position = float4(pixel.x / quad.canvas.x * 2 - 1, 1 - pixel.y / quad.canvas.y * 2, 0, 1);
            result.uv = quad.uvRect.xy + float2(quad.padding.x > 0 ? 1 - uv.x : uv.x, uv.y) * quad.uvRect.zw;
            return result;
        }
        fragment float4 spriteFragment(Vertex input [[stage_in]], constant Quad &quad [[buffer(0)]], texture2d<float> image [[texture(0)]], sampler sampling [[sampler(0)]]) {
            return image.sample(sampling, input.uv) * quad.tint;
        }
        fragment float4 ghostFragment(Vertex input [[stage_in]], constant Quad &quad [[buffer(0)]], texture2d<float> image [[texture(0)]], sampler sampling [[sampler(0)]]) {
            return image.sample(sampling, input.uv) * quad.padding.y;
        }
        struct DepthPixel { float4 color [[color(0)]]; float depth [[depth(any)]]; };
        fragment DepthPixel spriteDepthFragment(Vertex input [[stage_in]], constant Quad &quad [[buffer(0)]],
                texture2d<float> image [[texture(0)]], texture2d<float> depths [[texture(1)]], sampler sampling [[sampler(0)]]) {
            float4 color = image.sample(sampling, input.uv);
            if (color.a < 0.25) discard_fragment();
            uint2 dimensions = uint2(depths.get_width(), depths.get_height());
            uint2 coordinate = min(uint2(clamp(input.uv, 0.0, 1.0) * float2(dimensions)), dimensions - 1);
            float depth = depths.read(coordinate).r;
            if (depth >= 1.0) discard_fragment();
            DepthPixel result;
            result.color = color * quad.tint;
            result.depth = mix(quad.depthInterval.x, quad.depthInterval.y, depth * (255.0 / 254.0));
            return result;
        }
        struct TerrainInput { float2 position; float2 padding; float4 color; };
        struct TerrainOutput { float4 position [[position]]; float4 color; float2 coordinate; };
        vertex TerrainOutput terrainVertex(uint id [[vertex_id]], device const TerrainInput *vertices [[buffer(3)]], constant Quad &transform [[buffer(1)]]) {
            float2 coordinate = vertices[id].position;
            float2 pixel = transform.rect.xy + coordinate * transform.rect.zw;
            TerrainOutput result;
            result.position = float4(pixel.x / transform.canvas.x * 2 - 1, 1 - pixel.y / transform.canvas.y * 2, 0, 1);
            result.coordinate = coordinate;
            result.color = vertices[id].color * transform.tint;
            return result;
        }
        fragment float4 terrainFragment(TerrainOutput input [[stage_in]]) {
            float detail = fract(sin(dot(floor(input.coordinate), float2(12.9898, 78.233))) * 43758.5453);
            return float4(input.color.rgb * (0.90 + detail * 0.20), 1);
        }
        fragment float4 placementFragment(TerrainOutput input [[stage_in]]) {
            return input.color;
        }
        struct AvatarInput { float4 position; float2 uv; float2 padding; float4 normal; };
        struct AvatarOutput { float4 position [[position]]; float2 uv; float3 normal; };
        vertex AvatarOutput avatarVertex(uint id [[vertex_id]], device const AvatarInput *vertices [[buffer(2)]], constant Quad &transform [[buffer(1)]]) {
            AvatarInput input = vertices[id];
            float2 pixel = transform.rect.xy + input.position.xy * transform.rect.zw;
            AvatarOutput result;
            result.position = float4(pixel.x / transform.canvas.x * 2 - 1, 1 - pixel.y / transform.canvas.y * 2, input.position.z, 1);
            result.uv = input.uv;
            result.normal = input.normal.xyz;
            return result;
        }
        fragment float4 surfaceFragment(AvatarOutput input [[stage_in]], constant Quad &transform [[buffer(1)]], texture2d<float> image [[texture(0)]], sampler sampling [[sampler(0)]]) {
            float4 color = image.sample(sampling, input.uv);
            if (color.a < 0.01) discard_fragment();
            return color * transform.tint;
        }
        fragment float4 avatarFragment(AvatarOutput input [[stage_in]], constant Quad &transform [[buffer(1)]], texture2d<float> image [[texture(0)]], sampler sampling [[sampler(0)]]) {
            float4 color = image.sample(sampling, input.uv);
            if (color.a < 0.01) discard_fragment();
            float light = 0.65 + 0.35 * max(0.0, dot(normalize(input.normal), normalize(float3(-0.4, 1, -0.6))));
            return float4(color.rgb * light * transform.tint.rgb, color.a);
        }
        """
        let library = try device.makeLibrary(source: shader, options: nil)
        let descriptor = MTLRenderPipelineDescriptor()
        descriptor.vertexFunction = library.makeFunction(name: "spriteVertex")
        descriptor.fragmentFunction = library.makeFunction(name: "spriteFragment")
        descriptor.colorAttachments[0].pixelFormat = .bgra8Unorm_srgb
        descriptor.depthAttachmentPixelFormat = .depth32Float
        descriptor.colorAttachments[0].isBlendingEnabled = true
        descriptor.colorAttachments[0].sourceRGBBlendFactor = .one
        descriptor.colorAttachments[0].destinationRGBBlendFactor = .oneMinusSourceAlpha
        descriptor.colorAttachments[0].sourceAlphaBlendFactor = .one
        descriptor.colorAttachments[0].destinationAlphaBlendFactor = .oneMinusSourceAlpha
        pipeline = try device.makeRenderPipelineState(descriptor: descriptor)
        descriptor.fragmentFunction = library.makeFunction(name: "ghostFragment")
        ghostPipeline = try device.makeRenderPipelineState(descriptor: descriptor)
        descriptor.fragmentFunction = library.makeFunction(name: "spriteDepthFragment")
        spriteDepthPipeline = try device.makeRenderPipelineState(descriptor: descriptor)
        let terrainDescriptor = MTLRenderPipelineDescriptor()
        terrainDescriptor.vertexFunction = library.makeFunction(name: "terrainVertex")
        terrainDescriptor.fragmentFunction = library.makeFunction(name: "terrainFragment")
        terrainDescriptor.colorAttachments[0].pixelFormat = .bgra8Unorm_srgb
        terrainDescriptor.depthAttachmentPixelFormat = .depth32Float
        terrainPipeline = try device.makeRenderPipelineState(descriptor: terrainDescriptor)
        terrainDescriptor.fragmentFunction = library.makeFunction(name: "placementFragment")
        terrainDescriptor.colorAttachments[0].isBlendingEnabled = true
        terrainDescriptor.colorAttachments[0].sourceRGBBlendFactor = .one
        terrainDescriptor.colorAttachments[0].destinationRGBBlendFactor = .oneMinusSourceAlpha
        terrainDescriptor.colorAttachments[0].sourceAlphaBlendFactor = .one
        terrainDescriptor.colorAttachments[0].destinationAlphaBlendFactor = .oneMinusSourceAlpha
        placementPipeline = try device.makeRenderPipelineState(descriptor: terrainDescriptor)
        descriptor.vertexFunction = library.makeFunction(name: "avatarVertex")
        descriptor.fragmentFunction = library.makeFunction(name: "avatarFragment")
        avatarPipeline = try device.makeRenderPipelineState(descriptor: descriptor)
        descriptor.fragmentFunction = library.makeFunction(name: "surfaceFragment")
        surfacePipeline = try device.makeRenderPipelineState(descriptor: descriptor)
        let flat = MTLDepthStencilDescriptor()
        flat.depthCompareFunction = .always
        flat.isDepthWriteEnabled = false
        let mesh = MTLDepthStencilDescriptor()
        mesh.depthCompareFunction = .lessEqual
        mesh.isDepthWriteEnabled = true
        guard let flatDepth = device.makeDepthStencilState(descriptor: flat), let meshDepth = device.makeDepthStencilState(descriptor: mesh) else {
            throw ContentError.invalid("Cannot create mesh depth states")
        }
        self.flatDepth = flatDepth
        self.meshDepth = meshDepth
        let sampling = MTLSamplerDescriptor()
        sampling.minFilter = .linear
        sampling.magFilter = .linear
        sampling.sAddressMode = .clampToEdge
        sampling.tAddressMode = .clampToEdge
        guard let sampler = device.makeSamplerState(descriptor: sampling) else {
            throw ContentError.invalid("Cannot create a Metal sampler")
        }
        self.sampler = sampler
        sampling.sAddressMode = .repeat
        sampling.tAddressMode = .repeat
        guard let roofSampler = device.makeSamplerState(descriptor: sampling) else { throw ContentError.invalid("Cannot create roof sampler") }
        self.roofSampler = roofSampler
        sampling.sAddressMode = .clampToEdge
        sampling.tAddressMode = .clampToEdge
        sampling.minFilter = .nearest
        sampling.magFilter = .nearest
        guard let pixelSampler = device.makeSamplerState(descriptor: sampling) else { throw ContentError.invalid("Cannot create pixel sampler") }
        self.pixelSampler = pixelSampler
        let backgroundData = try content.read("UIGraphics/Community/NScreen_unleashed.bmp")
        let panelData = try content.read("UIGraphics/cpanel/Backgrounds/PanelBack.bmp")
        func texture(_ data: Data, transparent: Bool = false) throws -> MTLTexture {
            let bitmap = try SimsBitmap(data: data)
            let textureDescriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: .rgba8Unorm_srgb, width: bitmap.width, height: bitmap.height, mipmapped: false)
            textureDescriptor.storageMode = .shared
            textureDescriptor.usage = .shaderRead
            guard let texture = device.makeTexture(descriptor: textureDescriptor) else { throw ContentError.invalid("Cannot allocate original UI texture") }
            let rgba = try SpritePixels.premultipliedSRGB(bitmap.rgba, removeMagenta: transparent)
            rgba.withUnsafeBytes { pixels in
                texture.replace(region: MTLRegionMake2D(0, 0, bitmap.width, bitmap.height), mipmapLevel: 0, withBytes: pixels.baseAddress!, bytesPerRow: bitmap.width * 4)
            }
            return texture
        }
        background = try texture(backgroundData)
        panel = try texture(panelData)
        pieFont = try SimsBitmapFont(data: content.read("UIGraphics/Fonts/variablesans_10.ffn"))
        gameplay = try OriginalGameplayOverlay(content: content, font: pieFont, device: device,
                                               strings: OriginalUIStrings(content: content))
        buy = try OriginalBuyOverlay(content: content, font: pieFont, device: device)
        build = try OriginalBuildOverlay(content: content, device: device)
        soundOptions = try OriginalSoundOptionsOverlay(content: content, font: pieFont, device: device,
                                                       strings: OriginalUIStrings(content: content))
        optionsPanel = try OriginalOptionsPanelOverlay(content: content, device: device, strings: OriginalUIStrings(content: content), font: pieFont)
        for control in OriginalUniversalControl.all { universalTextures.append(try texture(content.read("UIGraphics/cpanel/Buttons/" + control.asset), transparent: true)) }
        for control in OriginalSpeedControl.all { speedTextures.append(try texture(content.read(control.asset), transparent: true)) }
        contentSize = CGSize(width: background.width, height: background.height)
        scene = nil
        super.init()
        if let sceneURL { try loadScene(sceneURL) }
    }

    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) {}

    func updateGameplay(_ state: GameplayPanelState) throws {
        guard let sceneRoot else { return }
        try gameplay.update(state, root: sceneRoot)
        try buy.updateStatus(state)
    }

    func updateWallBrush(_ line: WallBrushSelection?) throws {
        placementBuffer = nil
        placementVertexCount = 0
        placementGhost = nil
        ghostTextures = []
        guard let line, let scene else { return }
        let color: SIMD4<Float> = line.deleting ? SIMD4(0.35, 0.12, 0.02, 0.4) : SIMD4(0.06, 0.12, 0.32, 0.4)
        let vertices = try line.geometry(scene: scene).map { TerrainVertex(position: SIMD2($0.x, $0.y), color: color) }
        placementBuffer = vertices.withUnsafeBytes { device.makeBuffer(bytes: $0.baseAddress!, length: $0.count, options: .storageModeShared) }
        guard placementBuffer != nil else { throw ContentError.invalid("Cannot allocate wall brush") }
        placementVertexCount = vertices.count
    }
    func updateFloorBrush(_ rectangle: FloorBrushSelection?, deleting: Bool = false) throws {
        placementBuffer = nil
        placementVertexCount = 0
        placementGhost = nil
        ghostTextures = []
        guard let rectangle, let scene else { return }
        let color: SIMD4<Float> = deleting ? SIMD4(0.35, 0.12, 0.02, 0.4) : SIMD4(0.06, 0.12, 0.32, 0.4)
        let vertices = try rectangle.geometry(scene: scene).map { TerrainVertex(position: SIMD2($0.x, $0.y), color: color) }
        guard !vertices.isEmpty else { return }
        placementBuffer = vertices.withUnsafeBytes { device.makeBuffer(bytes: $0.baseAddress!, length: $0.count, options: .storageModeShared) }
        guard placementBuffer != nil else { throw ContentError.invalid("Cannot allocate floor brush") }
        placementVertexCount = vertices.count
    }
    func updatePlacement(_ preview: PlacementPreview?) throws {
        placementBuffer = nil
        placementVertexCount = 0
        placementGhost = nil
        ghostTextures = []
        guard let preview, let scene else { return }
        let color: SIMD4<Float> = preview.valid ? SIMD4(0.04, 0.35, 0.04, 0.4) : SIMD4(0.4, 0.02, 0.02, 0.4)
        let vertices = try preview.geometry(scene: scene).map { TerrainVertex(position: SIMD2($0.x, $0.y), color: color) }
        if !vertices.isEmpty {
            placementBuffer = vertices.withUnsafeBytes { device.makeBuffer(bytes: $0.baseAddress!, length: $0.count, options: .storageModeShared) }
            guard placementBuffer != nil else { throw ContentError.invalid("Cannot allocate placement preview") }
            placementVertexCount = vertices.count
        }
        if let ghost = preview.ghost, let sceneRoot {
            let pixels = try LotScene.readPixels(textures: ghost.scene.textures, root: sceneRoot.resolvingSymlinksInPath().standardizedFileURL)
            var cache: [String: MTLTexture] = [:]
            for (index, image) in ghost.scene.textures.enumerated() {
                let key = sceneRoot.appendingPathComponent(image.file).path
                let format: MTLPixelFormat = image.encoding == "depth8" ? .r8Unorm : .rgba8Unorm_srgb
                let texture: MTLTexture
                if let cached = ghostCache[key], cached.width == image.width, cached.height == image.height, cached.pixelFormat == format {
                    texture = cached
                } else {
                    let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: format, width: image.width, height: image.height, mipmapped: false)
                    descriptor.storageMode = .shared
                    descriptor.usage = .shaderRead
                    guard let allocated = device.makeTexture(descriptor: descriptor) else { throw ContentError.invalid("Cannot allocate object ghost") }
                    let bytes = image.encoding == "depth8" ? pixels[index] : try SpritePixels.premultipliedSRGB(pixels[index])
                    bytes.withUnsafeBytes { allocated.replace(region: MTLRegionMake2D(0, 0, image.width, image.height), mipmapLevel: 0, withBytes: $0.baseAddress!, bytesPerRow: image.width * (image.encoding == "depth8" ? 1 : 4)) }
                    texture = allocated
                }
                ghostTextures.append(texture)
                cache[key] = texture
            }
            ghostCache = cache
            placementGhost = ghost
        }
    }

    func updateBuildCatalog(_ page: BuildCatalogPage) throws {
        guard let sceneRoot else { throw ContentError.invalid("Build catalog requires a loaded scene") }
        try build.update(page, root: sceneRoot)
        if page.kind == .roof { build.choose(roofStyle) }
        if page.kind == .water && build.selectedObjectGUID == nil { buy.cancelSelection() }
    }
    func updateBuildObjects(_ page: BuyCatalogPage) throws {
        guard let sceneRoot else { throw ContentError.invalid("Build object catalog requires a loaded scene") }
        try build.updateObjects(page, root: sceneRoot)
        try buy.update(page, root: sceneRoot, buildObjects: true)
    }
    func updateCatalog(_ page: BuyCatalogPage) throws {
        guard let sceneRoot else { throw ContentError.invalid("Buy catalog requires a loaded scene") }
        try buy.update(page, root: sceneRoot)
    }

    private func draw(texture: MTLTexture, rect: SIMD4<Float>, canvas: SIMD2<Float>, flip: Bool = false, opacity: Float = 1, uvRect: SIMD4<Float> = SIMD4(0, 0, 1, 1), depthTexture: MTLTexture? = nil, depthInterval: SIMD2<Float> = .zero, tint: SIMD4<Float> = SIMD4(repeating: 1), encoder: MTLRenderCommandEncoder) {
        var quad = Quad(rect: rect, canvas: canvas)
        quad.padding.x = flip ? 1 : 0
        quad.padding.y = opacity
        quad.uvRect = uvRect
        quad.depthInterval = SIMD4(depthInterval.x, depthInterval.y, 0, 0)
        quad.tint = tint
        encoder.setVertexBytes(&quad, length: MemoryLayout<Quad>.stride, index: 0)
        encoder.setFragmentBytes(&quad, length: MemoryLayout<Quad>.stride, index: 0)
        encoder.setFragmentTexture(texture, index: 0)
        if let depthTexture {
            encoder.setFragmentBytes(&quad, length: MemoryLayout<Quad>.stride, index: 0)
            encoder.setFragmentTexture(depthTexture, index: 1)
        }
        encoder.drawPrimitives(type: .triangle, vertexStart: 0, vertexCount: 6)
    }

    private func drawDialog(_ dialog: OriginalDialogOverlay, canvas: SIMD2<Float>, size: CGSize, encoder: MTLRenderCommandEncoder) {
        do {
            let factor = CGFloat(uiScale)
            try dialog.prepare(canvas: size, scale: factor)
            func drawPart(_ texture: MTLTexture, _ rect: CGRect, uv: SIMD4<Float> = SIMD4(0, 0, 1, 1)) {
                draw(texture: texture,
                     rect: SIMD4(Float(rect.minX * factor), Float(rect.minY * factor), Float(rect.width * factor), Float(rect.height * factor)),
                     canvas: canvas, uvRect: uv, encoder: encoder)
            }
            let frame = dialog.rect
            if let background = dialog.phoneBookBackground {
                drawPart(background.texture, frame)
                drawPart(dialog.title.texture, CGRect(x: frame.midX - dialog.title.size.width / 2, y: frame.minY + 16, width: dialog.title.size.width, height: dialog.title.size.height))
                drawPart(dialog.bodyTexture, dialog.phoneBookFamilyRect)
                drawPart(dialog.bodyTexture, dialog.phoneBookContactRect)
                for row in dialog.phoneBookFamilyRows {
                    if row.selected { drawPart(dialog.buttonTexture, row.rect, uv: SIMD4(0.5, 0, 0.25, 1)) }
                    drawPart(row.image.texture, CGRect(x: row.rect.minX + 7, y: row.rect.midY - row.image.size.height / 2, width: row.image.size.width, height: row.image.size.height))
                }
                for row in dialog.phoneBookContactRows {
                    if row.selected { drawPart(dialog.buttonTexture, row.rect, uv: SIMD4(0.5, 0, 0.25, 1)) }
                    drawPart(row.image.texture, CGRect(x: row.rect.minX + 7, y: row.rect.midY - row.image.size.height / 2, width: row.image.size.width, height: row.image.size.height))
                }
            } else {
                let xs = [frame.minX, frame.minX + 10, frame.maxX - 10, frame.maxX]
                let ys = [frame.minY, frame.minY + 10, frame.maxY - 10, frame.maxY]
                for row in 0..<3 {
                    for column in 0..<3 {
                        drawPart(dialog.frameTexture, CGRect(x: xs[column], y: ys[row], width: xs[column + 1] - xs[column], height: ys[row + 1] - ys[row]),
                                 uv: SIMD4(Float(column) / 3, Float(row) / 3, 1 / 3, 1 / 3))
                    }
                }
                drawPart(dialog.title.texture, CGRect(x: frame.midX - dialog.title.size.width / 2, y: frame.minY + 14, width: dialog.title.size.width, height: dialog.title.size.height))
                for line in dialog.visibleLines { drawPart(line.image.texture, line.rect) }
                if let input = dialog.input {
                    drawPart(dialog.bodyTexture, dialog.inputRect)
                    drawPart(input.texture, CGRect(x: dialog.inputRect.minX + 4, y: dialog.inputRect.minY + 2, width: input.size.width, height: input.size.height))
                }
            }
            for index in dialog.labels.indices {
                let rect = dialog.buttonRects[index]
                let disabledCall = dialog.dialog.kind == 10 && index == 0 && dialog.selectedPhoneBookContact() == nil
                drawPart(dialog.buttonTexture, rect, uv: SIMD4(dialog.submitting || disabledCall ? 0.75 : dialog.hovered == index ? 0.25 : 0, 0, 0.25, 1))
                let label = dialog.labels[index]
                drawPart(label.texture, CGRect(x: rect.midX - label.size.width / 2, y: rect.midY - label.size.height / 2, width: label.size.width, height: label.size.height))
            }
        } catch { fputs("Game dialog: \(error)\n", stderr) }
    }

    private func drawPluginPanel(canvas: SIMD2<Float>, size: CGSize, encoder: MTLRenderCommandEncoder) {
        guard let pluginPanel, gameDialog == nil, !soundOptions.isVisible else { return }
        let factor = CGFloat(uiScale)
        for item in pluginPanel.drawItems(canvas: CGSize(width: size.width / factor, height: size.height / factor)) {
            draw(texture: item.image.texture,
                 rect: SIMD4(Float(item.rect.minX * factor), Float(item.rect.minY * factor), Float(item.rect.width * factor), Float(item.rect.height * factor)),
                 canvas: canvas, uvRect: item.uv, encoder: encoder)
        }
    }

    private func drawSoundOptions(canvas: SIMD2<Float>, size: CGSize, encoder: MTLRenderCommandEncoder) {
        drawOutfitPicker(canvas: canvas, size: size, encoder: encoder)
        drawPluginPanel(canvas: canvas, size: size, encoder: encoder)
        guard soundOptions.isVisible else { return }
        let factor = CGFloat(uiScale)
        for item in soundOptions.drawItems(canvas: CGSize(width: size.width / factor, height: size.height / factor)) {
            draw(texture: item.image.texture,
                 rect: SIMD4(Float(item.rect.minX * factor), Float(item.rect.minY * factor), Float(item.rect.width * factor), Float(item.rect.height * factor)),
                 canvas: canvas, uvRect: item.uv, encoder: encoder)
        }
    }

    func encode(pass: MTLRenderPassDescriptor, size: CGSize, command: MTLCommandBuffer) throws {
        guard let encoder = command.makeRenderCommandEncoder(descriptor: pass) else {
            throw ContentError.invalid("Cannot create a Metal render encoder")
        }
        encoder.setRenderPipelineState(pipeline)
        encoder.setDepthStencilState(flatDepth)
        encoder.setFragmentSamplerState(sampler, index: 0)
        let canvas = SIMD2(Float(size.width), Float(size.height))
        if let householdCreation {
            encoder.setDepthStencilState(flatDepth)
            for (index, item) in householdCreation.drawItems(canvas: size).enumerated() {
                draw(texture: item.image.texture,
                     rect: SIMD4(Float(item.rect.minX), Float(item.rect.minY), Float(item.rect.width), Float(item.rect.height)),
                     canvas: canvas, uvRect: item.uv, encoder: encoder)
                if index == 0 { drawHouseholdAppearancePreview(householdCreation, canvas: canvas, encoder: encoder) }
            }
            if let dialog = gameDialog { drawDialog(dialog, canvas: canvas, size: size, encoder: encoder) }
            drawSoundOptions(canvas: canvas, size: size, encoder: encoder)
            encoder.endEncoding()
            return
        }
        if let neighborhood {
            encoder.setDepthStencilState(flatDepth)
            if let familyPicker {
                for item in familyPicker.drawItems(canvas: size) {
                    draw(texture: item.image.texture,
                         rect: SIMD4(Float(item.rect.minX), Float(item.rect.minY), Float(item.rect.width), Float(item.rect.height)),
                         canvas: canvas, uvRect: item.uv, encoder: encoder)
                }
            } else {
                for item in neighborhood.drawItems(canvas: size) {
                    draw(texture: item.image.texture,
                         rect: SIMD4(Float(item.rect.minX), Float(item.rect.minY), Float(item.rect.width), Float(item.rect.height)),
                         canvas: canvas, opacity: item.opacity, uvRect: item.uv, encoder: encoder)
                }
            }
            if let dialog = gameDialog { drawDialog(dialog, canvas: canvas, size: size, encoder: encoder) }
            drawSoundOptions(canvas: canvas, size: size, encoder: encoder)
            encoder.endEncoding()
            return
        }
        if let scene {
            let viewport = SceneViewport(scene: scene, canvas: canvas, panelHeight: liveMode ? 150 * uiScale : 0, zoom: zoom, uiScale: uiScale, pan: pan)
            let scale = viewport.scale
            let origin = viewport.origin
            // Each zoom level draws its own art at a whole number of screen pixels per texel when the UI scale is whole.
            let artSampler = uiScale == uiScale.rounded() ? pixelSampler : sampler
            let zoom = self.zoom
            func artRect(_ sprite: LotScene.Sprite) -> (texture: Int, depthTexture: Int?, rect: SIMD4<Float>) {
                guard let image = sprite.image(for: zoom) else {
                    return (sprite.texture, sprite.depthTexture, SIMD4(sprite.x, sprite.y, sprite.width, sprite.height))
                }
                return (image.texture, image.depthTexture, SIMD4(sprite.x + image.x, sprite.y + image.y, image.width, image.height))
            }
            encoder.setScissorRect(MTLScissorRect(x: 0, y: 0, width: Int(canvas.x), height: Int(viewport.size.y)))
            if let terrainBuffer, terrainVertexCount > 0 {
                encoder.setRenderPipelineState(terrainPipeline)
                encoder.setVertexBuffer(terrainBuffer, offset: 0, index: 3)
                var transform = Quad(rect: SIMD4(origin.x, origin.y, scale, scale), canvas: canvas)
                transform.tint = activeLighting(scene)?.outside.multiplier ?? SIMD4(repeating: 1)
                encoder.setVertexBytes(&transform, length: MemoryLayout<Quad>.stride, index: 1)
                encoder.drawPrimitives(type: .triangle, vertexStart: 0, vertexCount: terrainVertexCount)
                encoder.setRenderPipelineState(pipeline)
            }
            for item in drawItems {
                switch item {
                case .sprite(let index):
                    encoder.setFragmentSamplerState(artSampler, index: 0)
                    let sprite = scene.sprites[index]
                    let art = artRect(sprite)
                    let depth = art.depthTexture.map { sceneTextures[$0] }
                    encoder.setRenderPipelineState(depth == nil ? pipeline : spriteDepthPipeline)
                    encoder.setDepthStencilState(depth == nil ? flatDepth : meshDepth)
                    draw(texture: sceneTextures[art.texture], rect: SIMD4(origin.x + art.rect.x * scale, origin.y + art.rect.y * scale, art.rect.z * scale, art.rect.w * scale), canvas: canvas, flip: sprite.flip,
                         depthTexture: depth, depthInterval: SIMD2(sprite.depthNear ?? 0, sprite.depthFar ?? 0), tint: activeLighting(scene)?.multiplier(room: sprite.room) ?? SIMD4(repeating: 1), encoder: encoder)
                case .mesh(let index):
                    guard let mesh = scene.meshes?[index] else { continue }
                    encoder.setFragmentSamplerState(mesh.roof != nil ? roofSampler : mesh.floor != nil ? artSampler : sampler, index: 0)
                    encoder.setRenderPipelineState(mesh.unlit == true ? surfacePipeline : avatarPipeline)
                    encoder.setDepthStencilState(mesh.unlit == true && mesh.floor?.water == nil && (mesh.level ?? 1) == 1 ? flatDepth : meshDepth)
                    encoder.setVertexBuffer(meshBuffers[index], offset: 0, index: 2)
                    var transform = Quad(rect: SIMD4(origin.x, origin.y, scale, scale), canvas: canvas)
                    transform.tint = activeLighting(scene)?.multiplier(room: mesh.room) ?? SIMD4(repeating: 1)
                    encoder.setVertexBytes(&transform, length: MemoryLayout<Quad>.stride, index: 1)
                    encoder.setFragmentBytes(&transform, length: MemoryLayout<Quad>.stride, index: 1)
                    encoder.setFragmentTexture(sceneTextures[mesh.texture(for: zoom)], index: 0)
                    encoder.drawPrimitives(type: .triangle, vertexStart: 0, vertexCount: mesh.vertices.count)
                }
            }
            encoder.setFragmentSamplerState(sampler, index: 0)
            if buyMode || buildMode, let placementBuffer, placementVertexCount > 0 {
                encoder.setRenderPipelineState(placementPipeline)
                encoder.setDepthStencilState(flatDepth)
                encoder.setVertexBuffer(placementBuffer, offset: 0, index: 3)
                var transform = Quad(rect: SIMD4(origin.x, origin.y, scale, scale), canvas: canvas)
                encoder.setVertexBytes(&transform, length: MemoryLayout<Quad>.stride, index: 1)
                encoder.drawPrimitives(type: .triangle, vertexStart: 0, vertexCount: placementVertexCount)
            }
            if objectEditing, let ghost = placementGhost {
                encoder.setRenderPipelineState(ghostPipeline)
                encoder.setDepthStencilState(flatDepth)
                encoder.setFragmentSamplerState(artSampler, index: 0)
                for sprite in ghost.scene.sprites {
                    let art = artRect(sprite)
                    draw(texture: ghostTextures[art.texture], rect: SIMD4(origin.x + (ghost.x + art.rect.x) * scale, origin.y + (ghost.y + art.rect.y) * scale, art.rect.z * scale, art.rect.w * scale),
                         canvas: canvas, flip: sprite.flip, opacity: 0.6, encoder: encoder)
                }
            }
            if liveMode {
                encoder.setRenderPipelineState(pipeline)
                encoder.setDepthStencilState(flatDepth)
                encoder.setScissorRect(MTLScissorRect(x: 0, y: 0, width: Int(canvas.x), height: Int(canvas.y)))
                let top = canvas.y - 150 * uiScale
                draw(texture: panel, rect: SIMD4(0, top + 50 * uiScale, canvas.x, 100 * uiScale), canvas: canvas, encoder: encoder)
                let logicalCanvas = CGSize(width: size.width / CGFloat(uiScale), height: size.height / CGFloat(uiScale))
                try gameplay.prepare(canvas: logicalCanvas)
                let parts = buildMode ? build.parts(canvas: logicalCanvas, budget: gameplay.state?.budget, selectedObject: buy.selected,
                                                    canUndo: gameplay.state?.canUndo, canRedo: gameplay.state?.canRedo) + buy.statusParts(canvas: logicalCanvas) : buyMode ? buy.parts(canvas: logicalCanvas, budget: gameplay.state?.budget) : optionsMode ? optionsPanel.parts(canvas: logicalCanvas) : gameplay.parts(canvas: logicalCanvas)
                for part in parts {
                    let rect = part.rect
                    draw(texture: part.image.texture, rect: SIMD4(Float(rect.minX) * uiScale, Float(rect.minY) * uiScale, Float(rect.width) * uiScale, Float(rect.height) * uiScale), canvas: canvas, uvRect: part.uv, encoder: encoder)
                }
                for (index, control) in OriginalUniversalControl.all.enumerated() {
                    let selected: Bool
                    switch control.action {
                    case .live: selected = !buyMode && !buildMode
                    case .buy: selected = buyMode
                    case .build: selected = buildMode
                    case .wallsUp: selected = wallsUp
                    case .wallsCutaway: selected = wallMode == "cutaway"
                    case .wallsDown: selected = wallMode == "down"
                    case .story1: selected = !roofsVisible && viewLevel == 1
                    case .story2: selected = !roofsVisible && viewLevel == 2
                    case .roofs: selected = roofsVisible
                    case .options: selected = optionsMode
                    default: selected = false
                    }
                    let frame: Float = !control.enabled ? 3 : selected ? 2 : 0
                    let rect = control.rect(canvas: logicalCanvas)
                    draw(texture: universalTextures[index], rect: SIMD4(Float(rect.minX) * uiScale, Float(rect.minY) * uiScale, Float(rect.width) * uiScale, Float(rect.height) * uiScale),
                         canvas: canvas, uvRect: SIMD4(frame / 4, 0, 0.25, 1), encoder: encoder)
                }

                for (index, control) in OriginalSpeedControl.all.enumerated() {
                    let active = control.speed == speed
                    let state: Float = buyMode || buildMode ? 3 : active ? 2 : 0
                    let rect = SIMD4(Float(control.position.x) * uiScale, canvas.y - Float(OriginalSpeedControl.panelHeight) * uiScale + Float(control.position.y) * uiScale, Float(control.size.width) * uiScale, Float(control.size.height) * uiScale)
                    draw(texture: speedTextures[index], rect: rect, canvas: canvas, uvRect: SIMD4(state / Float(control.columns), 0, 1 / Float(control.columns), 1 / Float(control.rows)), encoder: encoder)
                }
                if let pieMenu {
                    pieMenu.prepare(canvas: size, scale: CGFloat(uiScale))
                    for (index, label) in pieMenu.labels.enumerated() {
                        guard let bounds = pieMenu.layout?.rectangles[index] else { continue }
                        let rect = SIMD4(Float(bounds.minX) * uiScale, Float(bounds.minY) * uiScale,
                                         Float(bounds.width) * uiScale, Float(bounds.height) * uiScale)
                        draw(texture: label.background, rect: rect, canvas: canvas, encoder: encoder)
                        draw(texture: label.states[pieMenu.highlighted == index ? 1 : 0], rect: rect, canvas: canvas, encoder: encoder)
                    }
                }
                if let dialog = gameDialog {
                    drawDialog(dialog, canvas: canvas, size: size, encoder: encoder)
                }
                drawSoundOptions(canvas: canvas, size: size, encoder: encoder)
            }
            encoder.endEncoding()
            return
        }
        let scale = min(Float(size.width) / Float(background.width), Float(size.height) / Float(background.height))
        let width = Float(background.width) * scale
        let height = Float(background.height) * scale
        let x = (Float(size.width) - width) / 2
        let y = (Float(size.height) - height) / 2
        draw(texture: background, rect: SIMD4(x, y, width, height), canvas: canvas, encoder: encoder)
        encoder.endEncoding()
    }

    func loadScene(_ url: URL, revision: Int64 = 0) throws {
        let loaded = try LotScene.load(url: url)
        var textures: [MTLTexture] = []
        var nextCache: [String: MTLTexture] = [:]
        for (index, image) in loaded.scene.textures.enumerated() {
            let key = url.deletingLastPathComponent().appendingPathComponent(image.file).path
            let pixelFormat: MTLPixelFormat = image.encoding == "depth8" ? .r8Unorm : .rgba8Unorm_srgb
            let texture: MTLTexture
            if let cached = cachedTextures[key], cached.width == image.width && cached.height == image.height, cached.pixelFormat == pixelFormat {
                texture = cached
            } else {
                let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: pixelFormat, width: image.width, height: image.height, mipmapped: false)
                descriptor.storageMode = .shared
                descriptor.usage = .shaderRead
                guard let allocated = device.makeTexture(descriptor: descriptor) else { throw ContentError.invalid("Cannot allocate live sprite") }
                let pixels = image.encoding == "depth8" ? loaded.pixels[index] : try SpritePixels.premultipliedSRGB(loaded.pixels[index])
                pixels.withUnsafeBytes { bytes in
                    allocated.replace(region: MTLRegionMake2D(0, 0, image.width, image.height), mipmapLevel: 0, withBytes: bytes.baseAddress!, bytesPerRow: image.width * (image.encoding == "depth8" ? 1 : 4))
                }
                texture = allocated
            }
            textures.append(texture)
            nextCache[key] = texture
        }
        let terrain = try makeTerrain(loaded.scene)
        let meshes = try makeMeshes(loaded.scene.meshes ?? [])
        scene = loaded.scene
        cameraOrientation = loaded.scene.camera
        wallMode = loaded.scene.wallMode ?? wallMode
        if loaded.scene.wallMode != nil { wallsUp = wallMode == "up" }
        scenePixels = loaded.pixels
        sceneRoot = url.deletingLastPathComponent()
        sceneRevision = revision
        animationSequence = 0
        terrainBuffer = terrain.buffer
        terrainVertexCount = terrain.count
        meshBuffers = meshes
        drawItems = SceneDrawItem.ordered(in: loaded.scene)
        picker = ScenePicker(scene: loaded.scene, pixels: loaded.pixels)
        groundPicker = GroundTilePicker(scene: loaded.scene)
        sceneTextures = textures
        cachedTextures = nextCache
    }

    func requestCameraRotation(_ delta: Int) {
        let next = (cameraOrientation.rawValue + delta + 4) % 4
        guard let orientation = LotCamera(rawValue: next) else { return }
        cameraOrientationRequested?(orientation)
    }

    func applyAnimation(_ frame: SceneAnimation) throws {
        guard let scene, let sceneRoot else { throw ContentError.invalid("Animation requires a scene snapshot") }
        let updated = try frame.applying(to: scene, revision: sceneRevision, after: animationSequence)
        let appended = try LotScene.readPixels(textures: frame.textures, root: sceneRoot.resolvingSymlinksInPath().standardizedFileURL)
        let staticBuffers = zip(scene.meshes ?? [], meshBuffers).filter { $0.0.objectID == 0 }.map { $0.1 }
        let meshes = staticBuffers + (try makeMeshes(Array((updated.meshes ?? []).dropFirst(staticBuffers.count))))
        var textures = sceneTextures
        for (index, image) in frame.textures.enumerated() {
            let format: MTLPixelFormat = image.encoding == "depth8" ? .r8Unorm : .rgba8Unorm_srgb
            let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: format, width: image.width, height: image.height, mipmapped: false)
            descriptor.storageMode = .shared
            descriptor.usage = .shaderRead
            guard let texture = device.makeTexture(descriptor: descriptor) else { throw ContentError.invalid("Cannot allocate animated sprite") }
            let pixels = image.encoding == "depth8" ? appended[index] : try SpritePixels.premultipliedSRGB(appended[index])
            pixels.withUnsafeBytes { bytes in
                texture.replace(region: MTLRegionMake2D(0, 0, image.width, image.height), mipmapLevel: 0,
                                withBytes: bytes.baseAddress!, bytesPerRow: image.width * (image.encoding == "depth8" ? 1 : 4))
            }
            textures.append(texture)
            cachedTextures[sceneRoot.appendingPathComponent(image.file).path] = texture
        }
        scenePixels += appended
        self.scene = updated
        sceneTextures = textures
        meshBuffers = meshes
        drawItems = SceneDrawItem.ordered(in: updated)
        picker = ScenePicker(scene: updated, pixels: scenePixels)
        animationSequence = frame.sequence
    }

    private func makeMeshes(_ meshes: [LotScene.Mesh]) throws -> [MTLBuffer] {
        try meshes.map { mesh -> MTLBuffer in
            let vertices = mesh.vertices.map { vertex in
                AvatarVertex(position: SIMD4(vertex.x, vertex.y, vertex.z, 1), uv: SIMD2(vertex.u, vertex.v), normal: SIMD4(vertex.nx, vertex.ny, vertex.nz, 0))
            }
            guard let buffer = vertices.withUnsafeBytes({ bytes in
                device.makeBuffer(bytes: bytes.baseAddress!, length: bytes.count, options: .storageModeShared)
            }) else { throw ContentError.invalid("Cannot allocate Sim mesh") }
            return buffer
        }
    }

    func updateHouseholdAppearancePreview(_ preview: HouseholdAppearancePreview, pixels: [Data]) throws {
        try preview.validate()
        guard pixels.count == preview.textures.count else { throw ContentError.invalid("Household preview texture data does not match its manifest") }
        var textures: [MTLTexture] = []
        for (index, metadata) in preview.textures.enumerated() {
            let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: .rgba8Unorm_srgb, width: metadata.width, height: metadata.height, mipmapped: false)
            descriptor.storageMode = .shared
            descriptor.usage = .shaderRead
            guard let texture = device.makeTexture(descriptor: descriptor) else { throw ContentError.invalid("Cannot allocate household preview texture") }
            let bytes = try SpritePixels.premultipliedSRGB(pixels[index])
            bytes.withUnsafeBytes { texture.replace(region: MTLRegionMake2D(0, 0, metadata.width, metadata.height), mipmapLevel: 0, withBytes: $0.baseAddress!, bytesPerRow: metadata.width * 4) }
            textures.append(texture)
        }
        let buffers = try makeMeshes(preview.meshes)
        householdPreviewTextures = preview.meshes.map { textures[$0.texture] }
        householdPreviewBuffers = buffers
        householdPreviewVertexCounts = preview.meshes.map { $0.vertices.count }
    }

    func clearHouseholdAppearancePreview() {
        householdPreviewTextures = []
        householdPreviewBuffers = []
        householdPreviewVertexCounts = []
    }

    var hasHouseholdAppearancePreview: Bool { !householdPreviewBuffers.isEmpty }

    private func drawHouseholdAppearancePreview(_ overlay: OriginalHouseholdCreationOverlay, canvas: SIMD2<Float>, encoder: MTLRenderCommandEncoder) {
        guard let bounds = overlay.appearancePreviewRect(canvas: CGSize(width: CGFloat(canvas.x), height: CGFloat(canvas.y))) else { return }
        drawAppearancePreview(bounds: bounds, canvas: canvas, encoder: encoder)
    }

    private func drawOutfitPicker(canvas: SIMD2<Float>, size: CGSize, encoder: MTLRenderCommandEncoder) {
        guard let outfitPicker else { return }
        let factor = CGFloat(uiScale)
        let logical = CGSize(width: size.width / factor, height: size.height / factor)
        for item in outfitPicker.drawItems(canvas: logical) {
            draw(texture: item.image.texture,
                 rect: SIMD4(Float(item.rect.minX * factor), Float(item.rect.minY * factor), Float(item.rect.width * factor), Float(item.rect.height * factor)),
                 canvas: canvas, uvRect: item.uv, encoder: encoder)
        }
        let area = outfitPicker.previewRect(canvas: logical)
        drawAppearancePreview(bounds: CGRect(x: area.minX * factor, y: area.minY * factor, width: area.width * factor, height: area.height * factor), canvas: canvas, encoder: encoder)
    }

    private func drawAppearancePreview(bounds: CGRect, canvas: SIMD2<Float>, encoder: MTLRenderCommandEncoder) {
        guard householdPreviewTextures.count == householdPreviewBuffers.count,
              householdPreviewBuffers.count == householdPreviewVertexCounts.count,
              !householdPreviewBuffers.isEmpty, bounds.width > 0, bounds.height > 0 else { return }
        encoder.setScissorRect(MTLScissorRect(x: max(0, Int(bounds.minX)), y: max(0, Int(bounds.minY)), width: max(0, Int(bounds.width)), height: max(0, Int(bounds.height))))
        encoder.setRenderPipelineState(avatarPipeline)
        encoder.setDepthStencilState(meshDepth)
        encoder.setFragmentSamplerState(sampler, index: 0)
        for index in householdPreviewBuffers.indices {
            encoder.setVertexBuffer(householdPreviewBuffers[index], offset: 0, index: 2)
            var transform = Quad(rect: SIMD4(Float(bounds.minX), Float(bounds.minY), Float(bounds.width), Float(bounds.height)), canvas: canvas)
            encoder.setVertexBytes(&transform, length: MemoryLayout<Quad>.stride, index: 1)
            encoder.setFragmentBytes(&transform, length: MemoryLayout<Quad>.stride, index: 1)
            encoder.setFragmentTexture(householdPreviewTextures[index], index: 0)
            encoder.drawPrimitives(type: .triangle, vertexStart: 0, vertexCount: householdPreviewVertexCounts[index])
        }
        encoder.setScissorRect(MTLScissorRect(x: 0, y: 0, width: Int(canvas.x), height: Int(canvas.y)))
        encoder.setRenderPipelineState(pipeline)
        encoder.setDepthStencilState(flatDepth)
    }

    /// Moves to another zoom level, keeping the scene point at the view centre where it was.
    func setZoom(_ level: LotZoom) {
        guard level != zoom else { return }
        pan = SceneViewport.rescaledPan(pan, from: zoom.factor, to: level.factor)
        zoom = level
    }

    func object(at point: CGPoint, canvas: CGSize) -> Int? {
        guard let scene else { return nil }
        let viewport = SceneViewport(scene: scene, canvas: SIMD2(Float(canvas.width), Float(canvas.height)),
                                     panelHeight: liveMode ? 150 * uiScale : 0, zoom: zoom, uiScale: uiScale, pan: pan)
        guard let location = viewport.scenePoint(SIMD2(Float(point.x), Float(point.y))) else { return nil }
        return picker?.object(at: location)
    }

    func wall(at point: CGPoint, canvas: CGSize) -> LotScene.WallSide? {
        guard let scene else { return nil }
        let viewport = SceneViewport(scene: scene, canvas: SIMD2(Float(canvas.width), Float(canvas.height)),
                                     panelHeight: liveMode ? 150 * uiScale : 0, zoom: zoom, uiScale: uiScale, pan: pan)
        guard let location = viewport.scenePoint(SIMD2(Float(point.x), Float(point.y))) else { return nil }
        return picker?.wall(at: location)
    }

    func lotVertex(at point: CGPoint, canvas: CGSize) -> LotVertex? {
        guard let scene, let picker = LotVertexPicker(scene: scene) else { return nil }
        let viewport = SceneViewport(scene: scene, canvas: SIMD2(Float(canvas.width), Float(canvas.height)),
                                     panelHeight: liveMode ? 150 * uiScale : 0, zoom: zoom, uiScale: uiScale, pan: pan)
        guard let location = viewport.scenePoint(SIMD2(Float(point.x), Float(point.y))) else { return nil }
        return picker.vertex(at: location)
    }

    func groundTile(at point: CGPoint, canvas: CGSize) -> GroundTile? { floorHit(at: point, canvas: canvas)?.tile }

    func floorHit(at point: CGPoint, canvas: CGSize) -> FloorTileHit? {
        guard let scene else { return nil }
        let viewport = SceneViewport(scene: scene, canvas: SIMD2(Float(canvas.width), Float(canvas.height)),
                                     panelHeight: liveMode ? 150 * uiScale : 0, zoom: zoom, uiScale: uiScale, pan: pan)
        guard let location = viewport.scenePoint(SIMD2(Float(point.x), Float(point.y))) else { return nil }
        return groundPicker?.hit(at: location)
    }

    func containsObject(_ id: Int) -> Bool {
        scene?.sprites.contains { $0.objectID == id } == true || scene?.meshes?.contains { $0.objectID == id } == true
    }

    private func makeTerrain(_ scene: LotScene) throws -> (buffer: MTLBuffer?, count: Int) {
        let vertices = (scene.terrainVertices ?? []).map { vertex in
            func linear(_ component: UInt8) -> Float {
                let value = Float(component) / 255
                return value <= 0.04045 ? value / 12.92 : pow((value + 0.055) / 1.055, 2.4)
            }
            return TerrainVertex(position: SIMD2(vertex.x, vertex.y), color: SIMD4(linear(vertex.r), linear(vertex.g), linear(vertex.b), 1))
        }
        if vertices.isEmpty {
            return (nil, 0)
        }
        guard let buffer = vertices.withUnsafeBytes({ bytes in
            device.makeBuffer(bytes: bytes.baseAddress!, length: bytes.count, options: .storageModeShared)
        }) else { throw ContentError.invalid("Cannot allocate terrain geometry") }
        return (buffer, vertices.count)
    }

    func draw(in view: MTKView) {
        uiScale = Float(view.window?.backingScaleFactor ?? 1)
        (view as? GameMetalView)?.refreshAccessibilityButtons()
        guard let pass = view.currentRenderPassDescriptor,
              let drawable = view.currentDrawable,
              let command = queue.makeCommandBuffer() else { return }
        pass.colorAttachments[0].loadAction = .clear
        pass.colorAttachments[0].storeAction = .store
        pass.depthAttachment.loadAction = .clear
        pass.depthAttachment.storeAction = .dontCare
        pass.depthAttachment.clearDepth = 1
        do {
            try encode(pass: pass, size: view.drawableSize, command: command)
            command.present(drawable)
            command.commit()
        } catch {
            fputs("\(error)\n", stderr)
        }
    }

    func renderPNG(width: Int, height: Int, destination: URL) throws {
        guard width > 0, height > 0, width <= 16384, height <= 16384 else {
            throw ContentError.invalid("Render size must be between 1 and 16384")
        }
        let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: .bgra8Unorm_srgb, width: width, height: height, mipmapped: false)
        descriptor.usage = [.renderTarget, .shaderRead]
        descriptor.storageMode = .shared
        guard let target = device.makeTexture(descriptor: descriptor), let command = queue.makeCommandBuffer() else {
            throw ContentError.invalid("Cannot allocate render target")
        }
        let pass = MTLRenderPassDescriptor()
        pass.colorAttachments[0].texture = target
        pass.colorAttachments[0].loadAction = .clear
        pass.colorAttachments[0].storeAction = .store
        pass.colorAttachments[0].clearColor = MTLClearColor(red: 0, green: 0, blue: originalUIBlue, alpha: 1)
        let depthDescriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: .depth32Float, width: width, height: height, mipmapped: false)
        depthDescriptor.storageMode = .private
        depthDescriptor.usage = .renderTarget
        guard let depth = device.makeTexture(descriptor: depthDescriptor) else { throw ContentError.invalid("Cannot allocate mesh depth target") }
        pass.depthAttachment.texture = depth
        pass.depthAttachment.loadAction = .clear
        pass.depthAttachment.storeAction = .dontCare
        pass.depthAttachment.clearDepth = 1
        try encode(pass: pass, size: CGSize(width: width, height: height), command: command)
        command.commit()
        command.waitUntilCompleted()
        if let error = command.error { throw error }
        try saveTexture(target, destination: destination)
    }

    private func saveTexture(_ target: MTLTexture, destination: URL) throws {
        let width = target.width, height = target.height
        let pixels = UnsafeMutableRawPointer.allocate(byteCount: width * height * 4, alignment: 64)
        defer { pixels.deallocate() }
        target.getBytes(pixels, bytesPerRow: width * 4, from: MTLRegionMake2D(0, 0, width, height), mipmapLevel: 0)
        guard let image = NSBitmapImageRep(bitmapDataPlanes: nil, pixelsWide: width, pixelsHigh: height, bitsPerSample: 8, samplesPerPixel: 4, hasAlpha: true, isPlanar: false, colorSpaceName: .deviceRGB, bytesPerRow: width * 4, bitsPerPixel: 32),
              let output = image.bitmapData else { throw ContentError.invalid("Cannot allocate PNG output") }
        let input = pixels.assumingMemoryBound(to: UInt8.self)
        for offset in stride(from: 0, to: width * height * 4, by: 4) {
            output[offset] = input[offset + 2]
            output[offset + 1] = input[offset + 1]
            output[offset + 2] = input[offset]
            output[offset + 3] = input[offset + 3]
        }
        guard let png = image.representation(using: .png, properties: [:]) else { throw ContentError.invalid("PNG encoding failed") }
        try png.write(to: destination)
    }
}

@MainActor
private final class StorageMenuFeedback {
    var values: [String: String] = [:]
}

@MainActor
final class AppDelegate: NSObject, NSApplicationDelegate {
    let loadContent: @Sendable () throws -> GameContent
    let sceneURL: URL?
    let workspace: URL
    let dataRoot: URL
    let liveHouse: Int?
    let showsNeighborhood: Bool
    let gameRoot: URL?
    private var loadingScreen: NSView?
    private var loadingMusic: AVAudioPlayer?
    /// Audio-only host for screens shown before a lot is loaded; replaced by the simulation's own audio in a lot.
    private var frontendAudio: SimulationBridge?
    private var frontendAudioPlayer: NativeAudioController?
    private var frontendAudioReady = false
    private var pendingFrontendAudio: [(operation: String, parameters: [String: Any])] = []
    /// The music event most recently started on the frontend host, so screens do not restart the same track.
    private var frontendMusic: String?
    private(set) var activeProfileID = "player"
    /// The profile's current numbered neighborhood, remembered like the original's SIMS_CURRENT_NEIGHBORHOOD_NUM.
    private(set) var currentNeighborhood = 1
    private var currentContent: GameContent?
    private var gameStrings: OriginalUIStrings?
    var window: NSWindow?
    var renderer: OriginalUIRenderer?
    var bridge: SimulationBridge?
    var audio: NativeAudioController?
    var simIDs: [Int] = []
    var simulationLanguageCode: Int?
    var selectedSim = 0
    private struct MenuRequest {
        let id: String
        let object: Int
        let caller: Int
        let anchor: CGPoint
    }
    private var pendingMenu: MenuRequest?
    private struct NeighborhoodRequest {
        let id: String
        let dialog: GameDialog
        let mode: Int
    }
    private var pendingNeighborhood: NeighborhoodRequest?
    private var pendingNeighborhoodResponse: String?
    private var activeNeighborhoodDialog: GameDialog?
    private var failedNeighborhoodTokens = Set<String>()
    private var pendingHouseholdCreation: Int?
    private var pendingFamilyMoveIn: (house: Int, family: Int, request: String?)?
    private var evictMode = false
    private var rezoneMode = false
    private var pendingOutfitChoices: (id: String, dialog: GameDialog)?
    private var pendingOutfitPreview: String?
    private var edgeScrollTimer: Timer?
    private var pausedByDeactivation: Int?
    private var activationObservers: [NSObjectProtocol] = []
    private var pendingHouseholdCreationRequest: String?
    private var pendingHouseholdAppearanceRequest: String?
    private var pendingHouseholdPreviewRequest: String?
    private var neighborhoodBeforeHouseholdCreation: OriginalNeighborhoodOverlay?
    private var neighborhoodSelectionBeforeHouseholdCreation: ((Int) -> Void)?
    private var pendingSaveRequests = Set<String>()
    private var pendingLoadRequests = Set<String>()
    private var localDialogToken: String?
    private var localDialogResponse: ((UInt8) -> Void)?
    var storageFeedbackHandler: ((String, String) -> Void)?
    private var pluginPanelValues: [String: [String: [String: String]]] = [:]
    private var pendingResponseSounds: [String: (success: String, failure: String?)] = [:]
    private var lastPieHighlight: Int?
    private var pendingCatalog: String?
    private var pendingBuildCatalog: String?
    private var pendingAudioState: String?
    private var pendingAudioVolumes: [String: OriginalSoundOptionsOverlay.VolumeChange] = [:]
    private var latestAudioVolumeRequest: [String: String] = [:]
    private var floorStroke: (start: GroundTile, pattern: UInt16, selection: UInt16?, deleting: Bool)?
    private var terrainGesture = TerrainBrushGesture()
    private var terrainStrokeMode: TerrainBrushMode?
    private var terrainStrokeStartPoint: CGPoint?
    private var wallStroke: (start: LotVertex, style: UInt16, pattern: UInt16, rectangle: Bool, deleting: Bool)?
    private var wallBrush: WallBrushSelection?
    private var floorBrush: FloorBrushSelection?
    private var editableObjects: [EditableLotObject] = []
    private struct PlacementKey: Equatable {
        let target: BuySelection.Target
        let tile: GroundTile
        let direction: Int
        let revision: Int64
        let level: Int
    }
    private var pointer: CGPoint?
    private var lastCutawayTile: String?
    private var desiredPlacement: PlacementKey?
    private var checkedPlacement: PlacementKey?
    private var pendingPlacement: (id: String, key: PlacementKey)?

    init(loadContent: @escaping @Sendable () throws -> GameContent, sceneURL: URL?, workspace: URL, dataRoot: URL? = nil, liveHouse: Int?, showsNeighborhood: Bool,
         gameRoot: URL? = nil) {
        self.loadContent = loadContent
        self.gameRoot = gameRoot
        self.sceneURL = sceneURL
        self.workspace = workspace
        self.dataRoot = dataRoot ?? workspace
        self.liveHouse = liveHouse
        self.showsNeighborhood = showsNeighborhood
        let selectionURL = self.dataRoot.appendingPathComponent("runtime/native-profiles/active-profile.txt")
        if let selected = try? String(contentsOf: selectionURL, encoding: .utf8) {
            let value = selected.trimmingCharacters(in: .whitespacesAndNewlines)
            if Self.isValidProfileID(value) { activeProfileID = value }
        }
        currentNeighborhood = Self.storedNeighborhood(dataRoot: self.dataRoot, profileID: activeProfileID)
    }

    private static func neighborhoodSettingURL(dataRoot: URL, profileID: String) -> URL {
        dataRoot.appendingPathComponent("runtime/native-profiles/\(profileID)/Settings/current-neighborhood.txt")
    }

    private static func storedNeighborhood(dataRoot: URL, profileID: String) -> Int {
        guard let text = try? String(contentsOf: neighborhoodSettingURL(dataRoot: dataRoot, profileID: profileID), encoding: .utf8),
              let number = Int(text.trimmingCharacters(in: .whitespacesAndNewlines)), (1...99).contains(number) else { return 1 }
        // A remembered neighborhood that is no longer in the profile falls back to the first one.
        let folder = number == 1 ? "UserData" : "UserData\(number)"
        let neighborhoodFile = dataRoot.appendingPathComponent("runtime/native-profiles/\(profileID)/\(folder)/Neighborhood.iff")
        return FileManager.default.fileExists(atPath: neighborhoodFile.path) ? number : 1
    }

    private func storeNeighborhood(_ number: Int) {
        let url = Self.neighborhoodSettingURL(dataRoot: dataRoot, profileID: activeProfileID)
        do {
            try FileManager.default.createDirectory(at: url.deletingLastPathComponent(), withIntermediateDirectories: true)
            try Data(String(number).utf8).write(to: url, options: .atomic)
        } catch { fputs("Neighborhood setting: \(error)\n", stderr) }
    }

    func applicationDidFinishLaunching(_ notification: Notification) {
        let window = NSWindow(contentRect: NSRect(x: 0, y: 0, width: 1200, height: 900), styleMask: [.titled, .closable, .miniaturizable, .resizable], backing: .buffered, defer: false)
        window.title = "The Sims"
        let frame = window.contentView?.bounds ?? NSRect(x: 0, y: 0, width: 1200, height: 900)
        let loading = OriginalLoadingScreen.view(image: gameRoot.flatMap(OriginalLoadingScreen.image(gameRoot:)), frame: frame)
        window.contentView?.addSubview(loading)
        loadingScreen = loading
        if let gameRoot {
            let profile = dataRoot.appendingPathComponent("runtime/native-profiles/" + activeProfileID, isDirectory: true)
            loadingMusic = OriginalLoadingScreen.music(gameRoot: gameRoot, profile: profile)
            loadingMusic?.play()
        }
        window.center()
        window.makeKeyAndOrderFront(nil)
        self.window = window
        NSApp.activate(ignoringOtherApps: true)
        let loader = loadContent
        Task {
            do {
                let content = try await Task.detached(priority: .userInitiated, operation: loader).value
                openGame(content: content)
            } catch {
                showLaunchError(error)
            }
        }
    }

    private func openGame(content: GameContent) {
        do {
            currentContent = content
            gameStrings = OriginalUIStrings(content: content)
            refreshLocalizedStorageMenuTitles()
            reviewPluginTrust(content: content)
            refreshPluginPanelMenu(content: content)
            guard let device = MTLCreateSystemDefaultDevice() else { throw ContentError.invalid("Metal is unavailable") }
            let renderer = try OriginalUIRenderer(content: content, device: device, sceneURL: sceneURL)
            let view = GameMetalView(frame: NSRect(x: 0, y: 0, width: 1200, height: 900), device: device)
            view.colorPixelFormat = .bgra8Unorm_srgb
            view.depthStencilPixelFormat = .depth32Float
            view.clearColor = MTLClearColor(red: 0, green: 0, blue: originalUIBlue, alpha: 1)
            view.preferredFramesPerSecond = 60
            view.delegate = renderer
            view.setAccessibilityElement(true)
            view.setAccessibilityRole(.group)
            view.setAccessibilityLabel("The Sims game view")
            let window = self.window ?? NSWindow(contentRect: view.frame, styleMask: [.titled, .closable, .miniaturizable, .resizable], backing: .buffered, defer: false)
            window.title = showsNeighborhood ? "The Sims — Neighborhood" : renderer.scene.map { "The Sims — native lot \($0.house) snapshot" } ?? "The Sims — native renderer preview"
            window.contentView = view
            if showsNeighborhood, let loading = loadingScreen {
                loading.removeFromSuperview()
                loading.frame = view.bounds
                view.addSubview(loading)
            } else {
                dismissLoadingScreen()
            }
            window.collectionBehavior = [.fullScreenPrimary]
            window.minSize = NSSize(width: liveHouse == nil && !showsNeighborhood ? 640 : 800, height: 480)
            window.center()
            window.makeKeyAndOrderFront(nil)
            self.window = window
            self.renderer = renderer
            renderer.liveMode = liveHouse != nil
            loadPlayOptions()
            startEdgeScrolling()
            observeActivation()
            view.roomFillRequested = { [weak self, weak view] point, removing in
                guard let self, let view else { return false }
                return self.fillRoom(point, canvas: view.drawableSize, removing: removing)
            }
            view.primaryPressed = { [weak self, weak view] point, rectangle, deleting in
                guard let self, let view else { return false }
                if let renderer = self.renderer, renderer.soundOptions.isVisible && (!renderer.soundOptions.isEmbedded || renderer.soundOptions.contains(point, canvas: view.drawableSize, scale: CGFloat(renderer.uiScale))) {
                    let change = renderer.soundOptions.pointerDown(point, canvas: view.drawableSize, scale: CGFloat(renderer.uiScale))
                    self.sendAudioVolume(change)
                    return true
                }
                return self.startTerrainStroke(point, canvas: view.drawableSize) || self.startWallStroke(point, canvas: view.drawableSize, rectangle: rectangle, deleting: deleting) || self.removeWallpaper(point, canvas: view.drawableSize, removing: deleting) || self.startFloorStroke(point, canvas: view.drawableSize, deleting: deleting)
            }
            view.primaryDragged = { [weak self, weak view] point in
                guard let self, let view else { return }
                if let renderer = self.renderer, renderer.soundOptions.isVisible && (!renderer.soundOptions.isEmbedded || renderer.soundOptions.isDragging) {
                    self.sendAudioVolume(renderer.soundOptions.pointerDragged(point, canvas: view.drawableSize, scale: CGFloat(renderer.uiScale)))
                    view.setNeedsDisplay(view.bounds)
                    view.draw()
                    return
                }
                self.updateTerrainStroke(point, canvas: view.drawableSize)
                self.updateBuildPreview(point, canvas: view.drawableSize)
            }
            view.primaryReleased = { [weak self, weak view] point in
                guard let self, let view else { return }
                if let renderer = self.renderer, renderer.soundOptions.isVisible && (!renderer.soundOptions.isEmbedded || renderer.soundOptions.isDragging) {
                    let wasVisible = renderer.soundOptions.isVisible
                    self.sendAudioVolume(renderer.soundOptions.pointerUp(point, canvas: view.drawableSize, scale: CGFloat(renderer.uiScale)))
                    if wasVisible && !renderer.soundOptions.isVisible { _ = try? self.bridge?.send("audioEvent", ["name": "ui_click"]) }
                    view.setNeedsDisplay(view.bounds)
                    view.refreshAccessibilityButtons()
                    view.draw()
                    return
                }
                self.finishTerrainStroke(point, canvas: view.drawableSize)
                self.finishWallStroke(point, canvas: view.drawableSize)
                self.finishFloorStroke(point, canvas: view.drawableSize)
            }
            view.clicked = { [weak self, weak view] point in
                guard let self, let view else { return }
                self.clickGame(point, canvas: view.drawableSize)
            }
            view.hovered = { [weak self, weak renderer, weak view] point in
                self?.pointer = point
                if let renderer, let view, renderer.soundOptions.isVisible && (!renderer.soundOptions.isEmbedded || renderer.soundOptions.contains(point, canvas: view.drawableSize, scale: CGFloat(renderer.uiScale))) {
                    renderer.soundOptions.hover(point, canvas: view.drawableSize, scale: CGFloat(renderer.uiScale))
                    view.setNeedsDisplay(view.bounds)
                    view.draw()
                    return
                }
                if let renderer, let picker = renderer.outfitPicker, let view {
                    let scale = CGFloat(renderer.uiScale)
                    picker.hover(CGPoint(x: point.x / scale, y: point.y / scale), canvas: CGSize(width: view.drawableSize.width / scale, height: view.drawableSize.height / scale))
                    view.setNeedsDisplay(view.bounds)
                    return
                }
                if let renderer, renderer.gameDialog == nil, let panel = renderer.pluginPanel, let view {
                    panel.hover(point, canvas: view.drawableSize, scale: CGFloat(renderer.uiScale))
                    view.setNeedsDisplay(view.bounds)
                    return
                }
                if let renderer, let dialog = renderer.gameDialog {
                    dialog.hover(point, scale: CGFloat(renderer.uiScale))
                    return
                }
                if renderer?.householdCreation != nil { return }
                if let renderer, renderer.neighborhood != nil, let picker = renderer.familyPicker, let view {
                    picker.hover(point, canvas: view.drawableSize)
                    view.setNeedsDisplay(view.bounds)
                    return
                }
                if let renderer, let neighborhood = renderer.neighborhood, let view {
                    let previous = neighborhood.hoveredHouse
                    neighborhood.updateHover(point, canvas: view.drawableSize)
                    neighborhood.updateBannerHover(point, canvas: view.drawableSize)
                    view.toolTip = neighborhood.bannerTooltip(at: point, canvas: view.drawableSize)
                    if let house = neighborhood.hoveredHouse, house != previous { self?.playUISound("ui_nhood_rollover") }
                    view.setNeedsDisplay(view.bounds)
                    return
                }
                if let view { self?.updatePlacement(point, canvas: view.drawableSize) }
                if let view { self?.updateCutaway(point, canvas: view.drawableSize) }
                guard let renderer else { return }
                if let dialog = renderer.gameDialog { dialog.hover(point, scale: CGFloat(renderer.uiScale)); return }
                if renderer.optionsMode, let view {
                    renderer.optionsPanel.hover(CGPoint(x: point.x / CGFloat(renderer.uiScale), y: point.y / CGFloat(renderer.uiScale)),
                                                canvas: CGSize(width: view.drawableSize.width / CGFloat(renderer.uiScale), height: view.drawableSize.height / CGFloat(renderer.uiScale)))
                }
                renderer.pieMenu?.hover(point, scale: CGFloat(renderer.uiScale))
                if let highlighted = renderer.pieMenu?.highlighted, highlighted != self?.lastPieHighlight { self?.playUISound("ui_piemenu_highlight") }
                self?.lastPieHighlight = renderer.pieMenu?.highlighted
                let local = CGPoint(x: point.x / CGFloat(renderer.uiScale), y: point.y / CGFloat(renderer.uiScale))
                renderer.gameplay.hoveredAction = (0..<128).first { OriginalGameplayLayout.action($0).contains(local) }
                if let view {
                    if renderer.buildMode {
                        view.toolTip = renderer.build.controls(canvas: view.bounds.size).first { $0.rect.contains(local) }?.label
                        if let action = renderer.build.action(at: local, canvas: view.bounds.size), case .select(let id) = action, let item = renderer.build.page?.items.first(where: { $0.id == id }) { view.toolTip = item.name + " — §" + String(item.price) + "\n" + item.description }
                        if let action = renderer.build.action(at: local, canvas: view.bounds.size), case .selectObject(let guid) = action, let item = renderer.build.objectPage?.items.first(where: { $0.guid == guid }) { view.toolTip = item.name + " — §" + String(item.price) + "\n" + item.description }
                        if let action = renderer.build.action(at: local, canvas: view.bounds.size), case .selectObject(let guid) = action, let item = renderer.build.page?.items.first(where: { $0.guid == guid }) { view.toolTip = item.name + " — §" + String(item.price) + "\n" + item.description }
                    } else if renderer.buyMode {
                        view.toolTip = renderer.buy.controls(canvas: view.bounds.size).first { $0.rect.contains(local) }?.label
                        if let action = renderer.buy.action(at: local, canvas: view.bounds.size), case .select(let guid) = action, let item = renderer.buy.page?.items.first(where: { $0.guid == guid }) {
                            view.toolTip = item.name + " — §" + String(item.price) + "\n" + item.description
                        }
                    } else if renderer.optionsMode {
                        view.toolTip = renderer.optionsPanel.playOptions.quickTips ? renderer.optionsPanel.aboutText(at: local, canvas: view.bounds.size) : nil
                    } else { view.toolTip = renderer.gameplay.controls(canvas: view.bounds.size).first { $0.rect.contains(local) }?.label }
                    if let control = OriginalUniversalControl.hit(point: local, canvas: view.bounds.size, scale: 1), control.enabled { view.toolTip = control.label }
                    if !renderer.optionsPanel.playOptions.quickTips && !renderer.optionsMode { view.toolTip = nil }
                }
            }
            view.dialogKey = { [weak self] key in self?.dialogKey(key) ?? false }
            view.dialogIsVisible = { [weak renderer] in renderer?.gameDialog != nil || (renderer?.soundOptions.isVisible == true && renderer?.soundOptions.isEmbedded == false) || renderer?.pluginPanel != nil || renderer?.outfitPicker != nil }
            view.menuDismissed = { [weak self] in self?.dismissMenu() }
            view.menuAccessibility = { [weak renderer, weak view] in
                guard let renderer, let view else { return [] }
                if let picker = renderer.outfitPicker { return picker.controls(canvas: view.bounds.size) }
                if renderer.soundOptions.isVisible && !renderer.soundOptions.isEmbedded { return renderer.soundOptions.controls(canvas: view.bounds.size) }
                if renderer.gameDialog == nil, let panel = renderer.pluginPanel { return panel.controls(canvas: view.bounds.size) }
                if let dialog = renderer.gameDialog {
                    try? dialog.prepare(canvas: view.drawableSize, scale: CGFloat(renderer.uiScale))
                    if dialog.dialog.kind == 10 { return dialog.phoneBookAccessibilityControls }
                    return dialog.dialog.buttons.enumerated().map { ($0.element.label, dialog.buttonRects[$0.offset]) }
                }
                if let creation = renderer.householdCreation { return creation.controls(canvas: view.bounds.size) }
                if renderer.neighborhood != nil, let picker = renderer.familyPicker { return picker.controls(canvas: view.bounds.size) }
                if let neighborhood = renderer.neighborhood { return neighborhood.bannerControls(canvas: view.bounds.size) + neighborhood.controls(canvas: view.bounds.size) }
                guard let menu = renderer.pieMenu else { return [] }
                menu.prepare(canvas: view.drawableSize, scale: CGFloat(renderer.uiScale))
                return menu.nodes.enumerated().compactMap { index, node in
                    guard let rect = menu.layout?.rectangles[index] else { return nil }
                    return (node.label, rect)
                }
            }
            view.speedChanged = { [weak self] speed in self?.sendSpeed(speed) }
            view.gameplayAccessibility = { [weak renderer, weak view] in
                guard let renderer, let view else { return [] }
                if renderer.gameDialog != nil || renderer.outfitPicker != nil || (renderer.soundOptions.isVisible && !renderer.soundOptions.isEmbedded) { return [] }
                if let creation = renderer.householdCreation { return creation.controls(canvas: view.bounds.size) }
                if renderer.optionsMode && !renderer.buildMode && !renderer.buyMode {
                    return renderer.optionsPanel.controls(canvas: view.bounds.size) + (renderer.soundOptions.isEmbedded ? renderer.soundOptions.controls(canvas: view.bounds.size) : [])
                }
                return renderer.buildMode ? renderer.build.controls(canvas: view.bounds.size) : renderer.buyMode ? renderer.buy.controls(canvas: view.bounds.size) : renderer.gameplay.controls(canvas: view.bounds.size)
            }
            view.pauseToggled = { [weak self] in self?.togglePause(nil) }
            view.simSelected = { [weak self] in self?.nextSim(nil) }
            view.storyChanged = { [weak self] delta in self?.selectStory((self?.renderer?.viewLevel ?? 1) + delta) }
            view.wallsToggled = { [weak self] in self?.toggleWalls(nil) }
            view.buildModeToggled = { [weak self] in self?.browseBuildCatalog(nil) }
            view.buyBrowserToggled = { [weak self] in self?.browseBuyCatalog(nil) }
            view.heldObjectSold = { [weak self] in self?.sellHeldObject() }
            view.heldObjectRotated = { [weak self, weak renderer, weak view] in
                guard let renderer, renderer.objectEditing, renderer.gameDialog == nil else { return }
                renderer.buy.rotate()
                self?.playUISound("ui_object_rotate")
                if let point = self?.pointer, let view { self?.updatePlacement(point, canvas: view.drawableSize) }
            }
            view.cameraMoved = { [weak self, weak renderer] delta in
                guard renderer?.gameDialog == nil else { return }
                self?.dismissMenu()
                renderer?.pan += delta
            }
            view.cameraRotated = { [weak renderer] delta in renderer?.requestCameraRotation(delta) }
            view.zoomChanged = { [weak self, weak renderer] multiplier in
                self?.dismissMenu()
                guard let renderer else { return }
                if renderer.soundOptions.isVisible && !renderer.soundOptions.isEmbedded { return }
                if let dialog = renderer.gameDialog {
                    let amount = -log(multiplier) * 20
                    if dialog.dialog.kind == 10 {
                        dialog.scrollPhoneBook(amount, point: self?.pointer ?? .zero, scale: CGFloat(renderer.uiScale))
                        if let view = self?.window?.contentView as? GameMetalView { view.refreshAccessibilityButtons(); view.draw() }
                    } else { dialog.scrollMessage(amount) }
                    return
                }
                // The original zooms in whole levels; a wheel notch or a long trackpad swipe moves one level.
                renderer.zoomTravel += log(multiplier)
                let steps = Int(renderer.zoomTravel / 0.35)
                guard steps != 0 else { return }
                renderer.zoomTravel = 0
                renderer.setZoom(renderer.zoom.stepped(steps))
            }
            window.makeFirstResponder(view)
            NSApp.activate(ignoringOtherApps: true)
            if showsNeighborhood {
                window.title = "The Sims — loading neighborhood"
                startFrontendAudio(content: content)
                Task { [weak self, weak renderer, weak view] in
                    do {
                        guard let self else { return }
                        let exported = try await NeighborhoodExport.create(content: content, workspace: self.workspace, dataRoot: self.dataRoot, mode: 1, profileID: self.activeProfileID,
                                                                            neighborhood: self.currentNeighborhood)
                        guard let renderer, let view else { return }
                        renderer.neighborhood = try OriginalNeighborhoodOverlay(content: content, device: renderer.device,
                                                                                 manifestURL: exported.manifest, session: exported.session, font: renderer.pieFont)
                renderer.neighborhoodHouseSelected = { [weak self] house in self?.selectNeighborhoodHouse(house, content: content) }
                        window.title = "The Sims — Neighborhood"
                        self.dismissLoadingScreen()
                        if let neighborhood = renderer.neighborhood { self.startNeighborhoodAudio(neighborhood) }
                        view.setAccessibilityHelp("Select a house in the neighborhood")
                        view.setNeedsDisplay(view.bounds)
                        view.draw()
                    } catch { self?.showLaunchError(error) }
                }
            }
            if let liveHouse {
                try startSimulation(house: liveHouse, content: content, renderer: renderer, view: view)
            }
        } catch { showLaunchError(error) }
    }

    private func dismissLoadingScreen() {
        loadingScreen?.removeFromSuperview()
        loadingScreen = nil
        loadingMusic?.stop()
        loadingMusic = nil
    }

    private func showLaunchError(_ error: Error) {
        dismissLoadingScreen()
        let alert = NSAlert()
        alert.messageText = "Cannot open native renderer"
        alert.informativeText = String(describing: error)
        alert.runModal()
        NSApp.terminate(nil)
    }

    /// Base-neighborhood lot selection: occupied lots open their household; vacant residential lots open the
    /// original Select a Family screen.
    private func selectNeighborhoodHouse(_ house: Int, content: GameContent) {
        guard let renderer, let neighborhood = renderer.neighborhood, renderer.familyPicker == nil else { return }
        playUISound("ui_nhood_click")
        if rezoneMode {
            rezoneMode = false
            renderer.neighborhood?.setRezoneMode(false)
            beginRezone(house)
            return
        }
        if evictMode {
            evictMode = false
            renderer.neighborhood?.setEvictMode(false)
            confirmEvict(house, neighborhood: neighborhood)
            return
        }
        if neighborhood.isVacantResidential(at: house) {
            openFamilyPicker(house: house, families: neighborhood.families, content: content)
            return
        }
        openNeighborhoodHouse(house, createHousehold: false, content: content)
    }

    private func openOutfitPicker(_ dialog: GameDialog) {
        guard let bridge else { return }
        dismissMenu()
        renderer?.soundOptions.dismiss()
        if let id = try? bridge.send("outfitChoices") { pendingOutfitChoices = (id, dialog) }
    }

    private func finishOpeningOutfitPicker(_ event: [String: Any], dialog: GameDialog) {
        guard let renderer, let bridge else { return }
        let result = event["result"] as? [String: Any]
        let names = (result?["choices"] as? [[String: Any]])?.compactMap { $0["name"] as? String } ?? []
        guard event["ok"] as? Bool == true, !names.isEmpty, let strings = gameStrings else {
            // Nothing to choose from: answer with the original cancel result so the Sim is not left waiting.
            if let reason = event["error"] as? String { fputs("Outfit choices: \(reason)\n", stderr) }
            _ = try? bridge.send("dialogResponse", ["token": dialog.token, "code": 0, "text": "-1"])
            return
        }
        do {
            renderer.outfitPicker = try OriginalOutfitPickerOverlay(token: dialog.token, pet: result?["pet"] as? Bool ?? false, names: names,
                                                                     content: renderer.content, font: renderer.pieFont, device: renderer.device, strings: strings)
            playUISound("ui_piemenu_appear")
            requestOutfitPreview()
        } catch {
            fputs("Outfit picker: \(error)\n", stderr)
            _ = try? bridge.send("dialogResponse", ["token": dialog.token, "code": 0, "text": "-1"])
        }
        refreshGameView()
    }

    private func requestOutfitPreview() {
        guard let picker = renderer?.outfitPicker, let bridge else { return }
        pendingOutfitPreview = try? bridge.send("outfitPreview", ["index": picker.index])
    }

    private func finishOutfitPreview(_ event: [String: Any]) {
        guard let renderer, let bridge, renderer.outfitPicker != nil else { return }
        do {
            guard event["ok"] as? Bool == true, let result = event["result"] as? [String: Any], result["file"] as? String == "cas-preview/preview.json" else {
                throw ContentError.invalid(event["error"] as? String ?? "The outfit preview response is invalid")
            }
            let session = bridge.session.resolvingSymlinksInPath().standardizedFileURL
            let url = session.appendingPathComponent("cas-preview/preview.json").resolvingSymlinksInPath().standardizedFileURL
            guard url.path.hasPrefix(session.path + "/") else { throw ContentError.invalid("The outfit preview file escaped its session directory") }
            let loaded = try HouseholdAppearancePreview.load(from: url)
            try renderer.updateHouseholdAppearancePreview(loaded.preview, pixels: loaded.pixels)
        } catch {
            renderer.clearHouseholdAppearancePreview()
            fputs("Outfit preview: \(error)\n", stderr)
        }
        refreshGameView()
    }

    private func handleOutfitPicker(_ action: OriginalOutfitPickerOverlay.Action, picker: OriginalOutfitPickerOverlay) {
        guard let bridge else { return }
        switch action {
        case .previous, .next:
            picker.move(action == .next ? 1 : -1)
            playUISound("ui_click")
            requestOutfitPreview()
        case .buy(let index):
            playUISound("ui_buy_place")
            _ = try? bridge.send("dialogResponse", ["token": picker.token, "code": 1, "text": String(index)])
            closeOutfitPicker()
        case .cancel:
            playUISound("ui_click")
            _ = try? bridge.send("dialogResponse", ["token": picker.token, "code": 0, "text": "-1"])
            closeOutfitPicker()
        }
        refreshGameView()
    }

    private func closeOutfitPicker() {
        renderer?.outfitPicker = nil
        renderer?.clearHouseholdAppearancePreview()
        pendingOutfitPreview = nil
    }

    /// Original rezone flow: evict the family, bulldoze the house, then choose Residential or Community (STR# 131, 250, 251).
    private func beginRezone(_ house: Int) {
        guard let neighborhood = renderer?.neighborhood, neighborhood.hasLot(house), let strings = gameStrings else { return }
        let yes = strings.yesButton(), no = strings.noButton()
        if let family = neighborhood.occupant(at: house) {
            let message = OriginalUIStrings.format(strings.rezoneEvictMessage(), [family.name, OriginalUIStrings.simoleons(family.netWorth)])
            presentLocalConfirmation(title: strings.rezoneEvictTitle(), message: message, yes: yes, no: no) { [weak self] code in
                guard code == 0 else { return }
                self?.reloadNeighborhood(edit: "evict:\(house)") { self?.beginRezone(house) }
            }
        } else if !neighborhood.isBulldozed(at: house) {
            presentLocalConfirmation(title: strings.rezoneBulldozeTitle(), message: strings.rezoneBulldozeMessage(), yes: yes, no: no) { [weak self] code in
                guard code == 0 else { return }
                self?.playUISound("ui_nhood_bdoze_demolish")
                self?.reloadNeighborhood(edit: "bulldoze:\(house)") { self?.beginRezone(house) }
            }
        } else {
            let current = strings.zoningType(neighborhood.zoningIndex(at: house))
            let message = OriginalUIStrings.format(strings.rezoneMessage(), [current])
            // Yes chooses Residential, No chooses Community; Cancel leaves the zoning unchanged.
            presentLocalPrompt(title: strings.rezoneTitle(), message: message, yes: strings.zoningType(0), no: strings.zoningType(1), cancel: strings.cancelButton()) { [weak self] code in
                guard code == 0 || code == 1 else { return }
                if Int(code) == neighborhood.zoningIndex(at: house) { return }
                self?.reloadNeighborhood(edit: "rezone:\(house):\(code)")
            }
        }
    }

    private func confirmEvict(_ house: Int, neighborhood: OriginalNeighborhoodOverlay) {
        guard let family = neighborhood.occupant(at: house) else {
            if neighborhood.isVacantResidential(at: house) {
                // A vacant lot's house can be bulldozed back to the empty-lot template (STR# 131 entries 0 and 1).
                presentLocalConfirmation(title: gameStrings?.bulldozeTitle() ?? "Bulldoze House?", message: gameStrings?.bulldozeMessage() ?? "Do you want to bulldoze this house?",
                                         yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
                    guard code == 0 else { return }
                    self?.playUISound("ui_nhood_bdoze_demolish")
                    self?.reloadNeighborhood(edit: "bulldoze:\(house)")
                }
                return
            }
            playUISound("ui_nhood_error")
            presentStorageFeedback(.neighborhood, title: gameStrings?.nothingToBulldozeTitle() ?? "Nothing to Bulldoze",
                                   message: gameStrings?.nothingToBulldozeMessage() ?? "There is nothing here to bulldoze.")
            return
        }
        let message = OriginalUIStrings.format(gameStrings?.evictMessage() ?? "The %s family has net worth of %s.  Do you want to evict them?",
                                               [family.name, OriginalUIStrings.simoleons(family.netWorth)])
        presentLocalConfirmation(title: gameStrings?.evictTitle() ?? "Evict Family?", message: message,
                                 yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
            guard code == 0 else { return }
            self?.reloadNeighborhood(edit: "evict:\(house)")
        }
    }

    private func chooseBannerAction(_ action: OriginalNeighborhoodOverlay.BannerAction) {
        playUISound("ui_nhood_click")
        switch action {
        case .returnHome:
            reloadNeighborhood(edit: nil, mode: 1)
        case .downtown, .vacation, .studioTown, .magicTown:
            if let mode = action.mapMode { reloadNeighborhood(edit: nil, mode: mode) }
        case .rezone:
            rezoneMode.toggle()
            if rezoneMode { evictMode = false; renderer?.neighborhood?.setEvictMode(false) }
            renderer?.neighborhood?.setRezoneMode(rezoneMode)
        case .bulldoze:
            evictMode.toggle()
            if evictMode { rezoneMode = false; renderer?.neighborhood?.setRezoneMode(false) }
            renderer?.neighborhood?.setEvictMode(evictMode)
        case .quit:
            presentLocalConfirmation(title: gameStrings?.quitTitle() ?? "Quit?", message: gameStrings?.quitMessage() ?? "Are you sure you want to quit?",
                                     yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { code in
                if code == 0 { NSApp.terminate(nil) }
            }
        case .importFamily:
            importOriginalSave(nil)
        case .previous, .next:
            switchNeighborhood(forward: action == .next)
        default:
            break
        }
    }

    /// Previous/Next: open the adjacent installed neighborhood and remember it for the profile.
    private func switchNeighborhood(forward: Bool) {
        guard let neighborhood = renderer?.neighborhood, neighborhood.mode == 1,
              let target = OriginalNeighborhoodOverlay.neighborhood(after: currentNeighborhood, in: neighborhood.neighborhoods, forward: forward),
              target != currentNeighborhood else { playUISound("ui_nhood_error"); return }
        let previous = currentNeighborhood
        currentNeighborhood = target
        rezoneMode = false
        reloadNeighborhood(edit: nil, mode: 1, completion: { [weak self] in self?.storeNeighborhood(target) },
                           failure: { [weak self] in self?.currentNeighborhood = previous })
    }

    /// Rebuilds the base neighborhood map, optionally applying an evict/delete edit in the host process first.
    private func reloadNeighborhood(edit: String?, mode: Int = 1, completion: (() -> Void)? = nil, failure: (() -> Void)? = nil) {
        guard let content = currentContent else { return }
        evictMode = false
        Task { [weak self] in
            guard let self else { return }
            do {
                let exported = try await NeighborhoodExport.create(content: content, workspace: self.workspace, dataRoot: self.dataRoot, mode: mode,
                                                                    profileID: self.activeProfileID, edit: edit, neighborhood: self.currentNeighborhood)
                guard let renderer = self.renderer, let view = self.window?.contentView as? GameMetalView else { return }
                let previousMode = renderer.neighborhood?.mode
                renderer.neighborhood = try OriginalNeighborhoodOverlay(content: content, device: renderer.device, manifestURL: exported.manifest,
                                                                         session: exported.session, font: renderer.pieFont)
                renderer.neighborhoodHouseSelected = { [weak self] house in self?.selectNeighborhoodHouse(house, content: content) }
                if let neighborhood = renderer.neighborhood, neighborhood.mode != previousMode {
                    self.stopNeighborhoodAmbientAudio()
                    self.startNeighborhoodAudio(neighborhood)
                }
                view.refreshAccessibilityButtons()
                view.setNeedsDisplay(view.bounds)
                completion?()
            } catch {
                failure?()
                self.playUISound("ui_nhood_error")
                self.presentStorageFeedback(.neighborhood, title: self.gameStrings?.moveInErrorTitle() ?? "Error!", message: self.gameStrings?.evictFailedMessage() ?? "Could not evict!")
                fputs("Neighborhood edit: \(error)\n", stderr)
            }
        }
    }

    private func openFamilyPicker(house: Int, families: [OriginalFamilyPickerOverlay.Family], content: GameContent) {
        guard let renderer, let strings = gameStrings else { return }
        do {
            renderer.familyPicker = try OriginalFamilyPickerOverlay(house: house, families: families, content: content,
                                                                    font: renderer.pieFont, device: renderer.device, strings: strings)
        } catch {
            showNeighborhoodError(error)
            return
        }
        if bridge == nil { playFrontendMusic("bkground_family") }
        if let view = window?.contentView as? GameMetalView {
            view.setAccessibilityHelp(strings.pickFamily(8, fallback: "SELECT A FAMILY"))
            view.setNeedsDisplay(view.bounds)
            view.refreshAccessibilityButtons()
            view.draw()
        }
    }

    /// Closes Select a Family; returning to the map restores its music as the original does (`0x005591ff` case 0).
    private func closeFamilyPicker(returnsToMap: Bool = true) {
        renderer?.familyPicker = nil
        if returnsToMap, bridge == nil, let music = renderer?.neighborhood?.music, !music.isEmpty { playFrontendMusic(music) }
        if let view = window?.contentView as? GameMetalView {
            view.setAccessibilityHelp("Select a house in the neighborhood")
            view.setNeedsDisplay(view.bounds)
            view.refreshAccessibilityButtons()
            view.draw()
        }
    }

    private func handleFamilyPicker(_ action: OriginalFamilyPickerOverlay.Action, picker: OriginalFamilyPickerOverlay) {
        guard let renderer, let neighborhood = renderer.neighborhood, let content = currentContent else { return }
        playUISound("ui_click")
        switch action {
        case .cancel:
            closeFamilyPicker()
        case .createFamily:
            guard neighborhood.canCreateHousehold(at: picker.house) else {
                playUISound("ui_nhood_error")
                presentStorageFeedback(.neighborhood, title: gameStrings?.sorryTitle() ?? "Sorry", message: gameStrings?.cannotAffordMessage() ?? "You can't afford it.")
                return
            }
            closeFamilyPicker(returnsToMap: false)
            openNeighborhoodHouse(picker.house, createHousehold: true, content: content)
        case .delete(let family):
            let message = OriginalUIStrings.format(gameStrings?.pickFamily(7, fallback: "Are you sure you want to delete the \"%s\" family?") ?? "", [family.name])
            presentLocalConfirmation(title: gameStrings?.pickFamily(6, fallback: "Delete Family?") ?? "Delete Family?", message: message,
                                     yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
                guard code == 0, let self else { return }
                let house = picker.house
                self.closeFamilyPicker(returnsToMap: false)
                self.reloadNeighborhood(edit: "delete:\(family.id)") { [weak self] in
                    guard let self, let content = self.currentContent, let neighborhood = self.renderer?.neighborhood else { return }
                    self.openFamilyPicker(house: house, families: neighborhood.families, content: content)
                }
            }
        case .moveIn(let family):
            let price = neighborhood.price(at: picker.house) ?? Int.max
            guard family.budget >= price else {
                playUISound("ui_nhood_error")
                presentStorageFeedback(.neighborhood, title: gameStrings?.sorryTitle() ?? "Sorry", message: gameStrings?.cannotAffordMessage() ?? "You can't afford it.")
                return
            }
            presentLocalConfirmation(title: gameStrings?.purchaseHouseTitle() ?? "Purchase House?",
                                     message: gameStrings?.purchaseHouseMessage() ?? "Are you sure you want to buy this house?",
                                     yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
                guard code == 0, let self else { return }
                self.closeFamilyPicker(returnsToMap: false)
                self.pendingFamilyMoveIn = (picker.house, family.id, nil)
                self.openNeighborhoodHouse(picker.house, createHousehold: false, retainNeighborhood: true, content: content)
            }
        }
    }

    private func openNeighborhoodHouse(_ house: Int, createHousehold: Bool, retainNeighborhood: Bool = false, content: GameContent, audioEnabled: Bool = true) {
        guard let renderer, let view = window?.contentView as? GameMetalView else { return }
        let keepsNeighborhood = createHousehold || retainNeighborhood
        neighborhoodBeforeHouseholdCreation = keepsNeighborhood ? renderer.neighborhood : nil
        neighborhoodSelectionBeforeHouseholdCreation = keepsNeighborhood ? renderer.neighborhoodHouseSelected : nil
        renderer.neighborhood = nil
        renderer.neighborhoodHouseSelected = nil
        renderer.householdCreation = nil
        renderer.liveMode = true
        pendingHouseholdCreation = createHousehold ? house : nil
        do { try startSimulation(house: house, content: content, renderer: renderer, view: view, audioEnabled: audioEnabled) }
        catch { showLaunchError(error) }
    }

    private func confirmCancelHouseholdCreation() {
        guard renderer?.householdCreation != nil else { return }
        presentLocalConfirmation(title: gameStrings?.familyCancelConfirmationTitle() ?? "Cancel?",
                                 message: gameStrings?.familyCancelConfirmationMessage() ?? "Are you sure you want to cancel and lose this family?",
                                 yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
            guard code == 0 else { return }
            self?.cancelHouseholdCreation()
        }
    }

    private func cancelHouseholdCreation() {
        guard let renderer, let view = window?.contentView as? GameMetalView else { return }
        bridge?.stop(save: false)
        bridge = nil
        renderer.householdCreation = nil
        renderer.liveMode = false
        renderer.neighborhood = neighborhoodBeforeHouseholdCreation
        renderer.neighborhoodHouseSelected = neighborhoodSelectionBeforeHouseholdCreation
        neighborhoodBeforeHouseholdCreation = nil
        neighborhoodSelectionBeforeHouseholdCreation = nil
        pendingHouseholdCreation = nil
        pendingHouseholdCreationRequest = nil
        pendingHouseholdAppearanceRequest = nil
        pendingHouseholdPreviewRequest = nil
        renderer.clearHouseholdAppearancePreview()
        window?.title = "The Sims — Neighborhood"
        view.setAccessibilityHelp("Select a house in the neighborhood")
        view.refreshAccessibilityButtons()
        view.setNeedsDisplay(view.bounds)
        view.draw()
    }

    private func requestHouseholdAppearancePreview(_ gender: String, _ age: String, _ skin: String, _ head: String, _ body: String, creation: OriginalHouseholdCreationOverlay) {
        pendingHouseholdPreviewRequest = nil
        renderer?.clearHouseholdAppearancePreview()
        guard let bridge else {
            creation.previewFailed("The simulation is not connected.")
            return
        }
        do {
            pendingHouseholdPreviewRequest = try bridge.send("appearancePreview", [
                "gender": gender, "age": age, "skin": skin, "headChoice": head, "bodyChoice": body
            ])
        } catch {
            creation.previewFailed("The Sim preview could not be loaded: \(error.localizedDescription)")
        }
    }

    private func respondToNeighborhood(_ house: Int) {
        guard let dialog = activeNeighborhoodDialog, let bridge, let renderer, pendingNeighborhoodResponse == nil else { return }
        guard let response = NeighborhoodTravel.response(forDestination: house) else { return }
        do {
            playUISound("ui_nhood_click")
            stopNeighborhoodAmbientAudio()
            pendingNeighborhoodResponse = try bridge.send("dialogResponse", ["token": dialog.token, "code": Int(response.code), "text": response.text])
            _ = try? bridge.send("audioEvent", ["name": "bkground_fade"])
            window?.title = "The Sims — traveling"
            renderer.neighborhoodHouseSelected = nil
            if let view = window?.contentView as? GameMetalView {
                view.setAccessibilityHelp("Travel selection submitted")
                view.setNeedsDisplay(view.bounds)
                view.draw()
            }
        } catch { fputs("Neighborhood selection: \(error)\n", stderr) }
    }

    private func startNeighborhoodAudio(_ neighborhood: OriginalNeighborhoodOverlay) {
        guard bridge != nil else {
            if let music = neighborhood.music, !music.isEmpty { playFrontendMusic(music) }
            if let ambientSound = neighborhood.ambientSound, !ambientSound.isEmpty {
                sendFrontendAudio("audioEvent", ["name": ambientSound, "ownerID": -25])
            }
            return
        }
        guard audio != nil, let bridge else { return }
        if let music = neighborhood.music, !music.isEmpty {
            _ = try? bridge.send("audioEvent", ["name": music])
        }
        if let ambientSound = neighborhood.ambientSound, !ambientSound.isEmpty {
            _ = try? bridge.send("audioEvent", ["name": ambientSound, "ownerID": -25])
        }
    }

    private func stopNeighborhoodAmbientAudio() {
        guard bridge != nil else { sendFrontendAudio("audioStopOwner", ["ownerID": -25]); return }
        guard audio != nil else { return }
        _ = try? bridge?.send("audioStopOwner", ["ownerID": -25])
    }

    private func loadTravelNeighborhood(_ dialog: GameDialog, mode: Int) {
        guard let bridge, let renderer, let view = window?.contentView as? GameMetalView else { return }
        do {
            let id = try bridge.send("neighborhood", ["mode": mode])
            pendingNeighborhood = NeighborhoodRequest(id: id, dialog: dialog, mode: mode)
            renderer.gameDialog = nil
            renderer.neighborhood = nil
            renderer.neighborhoodHouseSelected = nil
            window?.title = "The Sims — loading neighborhood"
            view.setAccessibilityHelp("Loading neighborhood selection")
        } catch {
            failedNeighborhoodTokens.insert(dialog.token)
            activeNeighborhoodDialog = dialog
            if let neighborhood = renderer.neighborhood { startNeighborhoodAudio(neighborhood) }
            fputs("Neighborhood selection: \(error)\n", stderr)
            showNeighborhoodError(error)
        }
    }

    private func showNeighborhoodError(_ error: Error) {
        presentStorageFeedback(.neighborhood, title: gameStrings?.moveInErrorTitle() ?? "Error!", message: String(describing: error))
    }

    @objc func importOriginalSave(_ sender: Any?) {
        guard let renderer, renderer.neighborhood != nil, let content = currentContent else {
            showNeighborhoodError(ContentError.invalid("Import an original save from the neighborhood screen."))
            return
        }
        let panel = NSOpenPanel()
        panel.canChooseFiles = false
        panel.canChooseDirectories = true
        panel.allowsMultipleSelection = false
        panel.prompt = "Import"
        panel.message = "Choose the original Sims installation folder or its UserData folder. Sibling UserData neighborhoods will also be imported into a separate profile; source files will be preserved."
        guard panel.runModal() == .OK, let source = panel.url else { return }
        Task { [weak self] in
            guard let self else { return }
            do {
                let profileID = try await self.importOriginalSaveFromFolder(source, content: content)
                self.presentStorageFeedback(.imported, title: self.gameStrings?.importFamilyTitle() ?? "Import Family",
                                            message: "The save is active as profile ‘\(profileID)’. The original files were left unchanged.")
            } catch { self.showNeighborhoodError(error) }
        }
    }

    private func importOriginalSaveFromFolder(_ source: URL, content: GameContent) async throws -> String {
        let profileID = Self.availableProfileID(for: source, dataRoot: dataRoot)
        _ = try await OriginalSaveImporter.run(gameRoot: content.root, workspace: workspace, dataRoot: dataRoot, sourceDirectory: source, profileID: profileID)
        try selectProfile(profileID)
        let exported = try await NeighborhoodExport.create(content: content, workspace: workspace, dataRoot: dataRoot, mode: 1, profileID: profileID,
                                                            neighborhood: currentNeighborhood)
        try finishOriginalSaveImport(content: content, session: exported.session, manifest: exported.manifest)
        return profileID
    }

    private func importOriginalSaveFromFolderSynchronously(_ source: URL, content: GameContent) throws -> String {
        let profileID = Self.availableProfileID(for: source, dataRoot: dataRoot)
        _ = try OriginalSaveImporter.importSynchronously(gameRoot: content.root, workspace: workspace, dataRoot: dataRoot, sourceDirectory: source, profileID: profileID)
        try selectProfile(profileID)
        let exported = try NeighborhoodExport.createSynchronously(content: content, workspace: workspace, dataRoot: dataRoot, mode: 1, profileID: profileID,
                                                                   neighborhood: currentNeighborhood)
        try finishOriginalSaveImport(content: content, session: exported.session, manifest: exported.manifest)
        return profileID
    }

    private func finishOriginalSaveImport(content: GameContent, session: URL, manifest: URL) throws {
        guard let renderer else { throw ContentError.invalid("The native renderer is unavailable after importing the save") }
        guard let view = window?.contentView as? GameMetalView else { throw ContentError.invalid("The neighborhood view is unavailable after importing the save") }
        renderer.neighborhood = try OriginalNeighborhoodOverlay(content: content, device: renderer.device, manifestURL: manifest, session: session, font: renderer.pieFont)
        renderer.neighborhoodHouseSelected = { [weak self] house in self?.selectNeighborhoodHouse(house, content: content) }
        window?.title = "The Sims — Neighborhood"
        view.setNeedsDisplay(view.bounds)
    }

    private func selectProfile(_ profileID: String) throws {
        guard Self.isValidProfileID(profileID) else { throw ContentError.invalid("Invalid native profile ID") }
        let selectionURL = dataRoot.appendingPathComponent("runtime/native-profiles/active-profile.txt")
        try FileManager.default.createDirectory(at: selectionURL.deletingLastPathComponent(), withIntermediateDirectories: true)
        try Data(profileID.utf8).write(to: selectionURL, options: .atomic)
        activeProfileID = profileID
        currentNeighborhood = Self.storedNeighborhood(dataRoot: dataRoot, profileID: profileID)
    }

    private static func isValidProfileID(_ value: String) -> Bool {
        !value.isEmpty && value.utf8.count <= 64 && value.utf8.allSatisfy { ($0 >= 48 && $0 <= 57) || ($0 >= 65 && $0 <= 90) || ($0 >= 97 && $0 <= 122) || $0 == 45 || $0 == 95 }
    }

    private static func availableProfileID(for source: URL, dataRoot: URL) -> String {
        let transliterated = (source.lastPathComponent.applyingTransform(.toLatin, reverse: false) ?? source.lastPathComponent)
            .applyingTransform(.stripDiacritics, reverse: false) ?? source.lastPathComponent
        let baseName = transliterated.lowercased().components(separatedBy: CharacterSet(charactersIn: "abcdefghijklmnopqrstuvwxyz0123456789").inverted).filter { !$0.isEmpty }.joined(separator: "-")
        let prefix = String(("import-" + (baseName.isEmpty ? "save" : baseName)).prefix(56)).trimmingCharacters(in: CharacterSet(charactersIn: "-_"))
        let profiles = dataRoot.appendingPathComponent("runtime/native-profiles", isDirectory: true)
        var candidate = prefix
        var suffix = 2
        while FileManager.default.fileExists(atPath: profiles.appendingPathComponent(candidate).path) {
            let ending = "-\(suffix)"
            candidate = String(prefix.prefix(64 - ending.utf8.count)) + ending
            suffix += 1
        }
        return candidate
    }

    private func startSimulation(house: Int, content: GameContent, renderer: OriginalUIRenderer, view: GameMetalView, audioEnabled: Bool = true) throws {
        stopFrontendAudio()
        window?.title = "The Sims — starting native simulation"
        let bridge = SimulationBridge(workspace: workspace, dataRoot: dataRoot, profileID: activeProfileID, neighborhood: currentNeighborhood)
        bridge.event = { [weak self] event in self?.simulationEvent(event) }
        bridge.failed = { [weak self] error in
            self?.window?.title = "The Sims — simulation error"
            fputs("\(error)\n", stderr)
        }
        self.bridge = bridge
        renderer.cameraOrientationRequested = { [weak bridge] orientation in
            _ = try? bridge?.send("cameraOrientation", ["value": orientation.rawValue])
        }
        renderer.editingViewChanged = { [weak bridge] editing in _ = try? bridge?.send("view", ["editing": editing]) }
        if audioEnabled {
            let audio = NativeAudioController(session: bridge.session)
            audio.ended = { [weak bridge] voice in _ = try? bridge?.send("audioEnded", ["voice": voice]) }
            audio.spatial = { [weak self] owner, panned, zoom in
                guard let self, let renderer = self.renderer, let scene = renderer.scene, let view = self.window?.contentView as? MTKView else { return (0, 1) }
                let source = scene.sprites.first { $0.objectID == owner }.map { SIMD2($0.x + $0.width / 2, $0.y + $0.height / 2) } ?? scene.meshes?.first { $0.objectID == owner }?.vertices.first.map { SIMD2($0.x, $0.y) }
                guard let source else { return (0, 0) }
                let viewport = SceneViewport(scene: scene, canvas: SIMD2(Float(view.drawableSize.width), Float(view.drawableSize.height)), panelHeight: 150 * renderer.uiScale, zoom: renderer.zoom, uiScale: renderer.uiScale, pan: renderer.pan)
                let point = source * viewport.scale + viewport.origin
                let delta = (point - viewport.size / 2) / max(1, viewport.size.x)
                let pan = min(1, max(-1, delta.x * 2))
                let gain = (panned ? max(0, 1 - sqrt(delta.x * delta.x + delta.y * delta.y)) : 1) * (zoom ? renderer.zoom.soundGain : 1)
                return (pan, gain)
            }
            self.audio = audio
        } else {
            self.audio = nil
        }
        try bridge.start(content: content, house: house)
        applyPlayOptions()
        view.setNeedsDisplay(view.bounds)
    }

    func applicationShouldTerminateAfterLastWindowClosed(_ sender: NSApplication) -> Bool { true }

    func applicationWillTerminate(_ notification: Notification) { audio?.stop(); bridge?.stop() }

    func sendSpeed(_ value: Int) {
        if value > 0, renderer?.buyMode == true || renderer?.buildMode == true { return }
        do {
            try bridge?.send("speed", ["value": value])
            if let current = renderer?.speed, let sound = Self.speedTransitionSound(from: current, to: value) { playUISound(sound) }
        }
        catch { fputs("\(error)\n", stderr) }
    }

    /// Original HIT events for speed-control transitions (`ui_speed_1to2`, `ui_speed_pto3`, …); P is pause.
    static func speedTransitionSound(from current: Int, to requested: Int) -> String? {
        func code(_ speed: Int) -> String? { speed == 0 ? "p" : (1...3).contains(speed) ? String(speed) : nil }
        guard current != requested, let from = code(current), let to = code(requested) else { return nil }
        return "ui_speed_\(from)to\(to)"
    }

    /// Sends a build-mode edit and plays the original drag-tool placement sound once the simulation accepts it.
    @discardableResult
    func sendWithBuildSound(_ operation: String, _ parameters: [String: Any]) throws -> String? {
        let id = try bridge?.send(operation, parameters)
        playUISoundOnResponse(id, success: "ui_bld_dragtool_place")
        return id
    }

    /// Plays an original UI sound event through the simulation's HIT player when audio is enabled.
    func playUISound(_ name: String) {
        guard bridge != nil else { sendFrontendAudio("audioEvent", ["name": name]); return }
        guard audio != nil else { return }
        _ = try? bridge?.send("audioEvent", ["name": name])
    }

    /// Starts the audio-only host used by the neighborhood maps while no lot is loaded.
    private func startFrontendAudio(content: GameContent) {
        guard frontendAudio == nil, bridge == nil, gameRoot != nil else { return }
        let host = SimulationBridge(workspace: workspace, dataRoot: dataRoot, profileID: activeProfileID, neighborhood: currentNeighborhood)
        let player = NativeAudioController(session: host.session)
        player.ended = { [weak host] voice in _ = try? host?.send("audioEnded", ["voice": voice]) }
        host.event = { [weak self, weak host, weak player] event in
            guard let self, let host, self.frontendAudio === host else { return }
            switch event["type"] as? String {
            case "hello":
                _ = try? host.send("audio", ["enabled": true])
                self.frontendAudioReady = true
                let queued = self.pendingFrontendAudio
                self.pendingFrontendAudio.removeAll()
                for request in queued { _ = try? host.send(request.operation, request.parameters) }
            case "audio":
                do { try player?.receive(JSONDecoder().decode(AudioEvent.self, from: JSONSerialization.data(withJSONObject: event))) }
                catch { fputs("Neighborhood audio: \(error)\n", stderr) }
            case "audioError":
                fputs("Neighborhood audio: \(event["error"] ?? "Unknown sound error")\n", stderr)
            default: break
            }
        }
        host.failed = { error in fputs("Neighborhood audio: \(error)\n", stderr) }
        frontendAudio = host
        frontendAudioPlayer = player
        frontendAudioReady = false
        do { try host.startFrontendAudio(content: content) }
        catch {
            fputs("Neighborhood audio: \(error)\n", stderr)
            frontendAudio = nil
            frontendAudioPlayer = nil
        }
    }

    /// Starts a music event on the frontend host unless it is already the current track.
    private func playFrontendMusic(_ name: String) {
        guard frontendAudio != nil, frontendMusic != name else { return }
        frontendMusic = name
        sendFrontendAudio("audioEvent", ["name": name])
    }

    /// Sends an audio request to the neighborhood audio host, holding it until the host has started.
    private func sendFrontendAudio(_ operation: String, _ parameters: [String: Any]) {
        guard let frontendAudio else { return }
        if frontendAudioReady { _ = try? frontendAudio.send(operation, parameters) }
        else if pendingFrontendAudio.count < 32 { pendingFrontendAudio.append((operation: operation, parameters: parameters)) }
    }

    private func stopFrontendAudio() {
        frontendAudio?.stop(save: false)
        frontendAudioPlayer?.stop()
        frontendAudio = nil
        frontendAudioPlayer = nil
        frontendAudioReady = false
        pendingFrontendAudio.removeAll()
        frontendMusic = nil
    }

    /// Plays `success` or `failure` when the response to request `id` arrives.
    private func playUISoundOnResponse(_ id: String?, success: String, failure: String? = "ui_error") {
        guard let id else { return }
        pendingResponseSounds[id] = (success, failure)
    }

    private func updateCutaway(_ point: CGPoint, canvas: CGSize) {
        guard let renderer, renderer.wallMode == "cutaway", renderer.gameDialog == nil, renderer.pieMenu == nil,
              let tile = renderer.groundTile(at: point, canvas: canvas) else { lastCutawayTile = nil; return }
        let key = "\(renderer.viewLevel):\(tile.x):\(tile.y)"
        guard lastCutawayTile != key else { return }
        do { try bridge?.send("cutaway", ["x": tile.x, "y": tile.y]); lastCutawayTile = key }
        catch { fputs("\(error)\n", stderr) }
    }

    private func dismissMenu() {
        wallStroke = nil
        wallBrush = nil
        floorStroke = nil
        terrainStrokeMode = nil
        terrainStrokeStartPoint = nil
        terrainGesture = TerrainBrushGesture()
        floorBrush = nil
        pendingMenu = nil
        renderer?.pieMenu = nil
        renderer?.buy.cancelSelection()
        renderer?.build.cancelSelection()
        desiredPlacement = nil
        checkedPlacement = nil
        try? renderer?.updatePlacement(nil)
        if let view = window?.contentView { NSAccessibility.post(element: view, notification: .layoutChanged) }
    }

    private func clickGame(_ point: CGPoint, canvas: CGSize, householdCreationRequestObserved: ((HouseholdCreationRequest) -> Void)? = nil) {
        if let renderer, let picker = renderer.outfitPicker {
            let scale = CGFloat(renderer.uiScale)
            let logical = CGSize(width: canvas.width / scale, height: canvas.height / scale)
            if let action = picker.click(CGPoint(x: point.x / scale, y: point.y / scale), canvas: logical) { handleOutfitPicker(action, picker: picker) }
            return
        }
        if let renderer, let panel = renderer.pluginPanel, renderer.gameDialog == nil, !renderer.soundOptions.isVisible {
            // Plugin panels are modal like the original option panels; clicks never fall through to the lot.
            switch panel.hit(point, canvas: canvas, scale: CGFloat(renderer.uiScale)) {
            case .close?:
                renderer.pluginPanel = nil
                _ = try? bridge?.send("audioEvent", ["name": "ui_click"])
            case .action(let action)?:
                _ = try? bridge?.send("audioEvent", ["name": "ui_click"])
                do { _ = try bridge?.send("pluginAction", ["packId": panel.packID, "panelId": panel.description.id, "action": action]) }
                catch { fputs("Plugin panel action: \(error)\n", stderr) }
            case .inside?, nil:
                break
            }
            if let view = window?.contentView as? GameMetalView {
                view.setNeedsDisplay(view.bounds)
                view.refreshAccessibilityButtons()
                view.draw()
            }
            return
        }
        if let renderer, renderer.soundOptions.isVisible,
           !renderer.soundOptions.isEmbedded || renderer.soundOptions.contains(point, canvas: canvas, scale: CGFloat(renderer.uiScale)) {
            let wasVisible = renderer.soundOptions.isVisible
            sendAudioVolume(renderer.soundOptions.click(point, canvas: canvas, scale: CGFloat(renderer.uiScale)))
            if wasVisible && !renderer.soundOptions.isVisible { _ = try? bridge?.send("audioEvent", ["name": "ui_click"]) }
            if let view = window?.contentView as? GameMetalView {
                view.setNeedsDisplay(view.bounds)
                view.refreshAccessibilityButtons()
                view.draw()
            }
            return
        }
        if let renderer, let dialog = renderer.gameDialog, localDialogToken == dialog.dialog.token {
            do {
                try dialog.prepare(canvas: canvas, scale: CGFloat(renderer.uiScale))
                if let code = dialog.choice(point, scale: CGFloat(renderer.uiScale)) {
                    try respondDialog(dialog, code: code)
                }
            } catch { fputs("Local dialog: \(error)\n", stderr) }
            return
        }
        if let renderer, renderer.neighborhood != nil, let picker = renderer.familyPicker {
            if let action = picker.click(point, canvas: canvas) { handleFamilyPicker(action, picker: picker) }
            if let view = window?.contentView as? GameMetalView { view.setNeedsDisplay(view.bounds); view.refreshAccessibilityButtons() }
            return
        }
        if let renderer, let neighborhood = renderer.neighborhood {
            if let action = neighborhood.bannerAction(at: point, canvas: canvas) {
                if neighborhood.isEnabled(action) { chooseBannerAction(action) } else { playUISound("ui_nhood_error") }
                return
            }
            if let house = neighborhood.house(at: point, canvas: canvas) { renderer.neighborhoodHouseSelected?(house) }
            return
        }
        if let renderer, let creation = renderer.householdCreation {
            creation.click(point, canvas: canvas, submit: { [weak self, weak creation] request in
                guard let self, let creation else { return }
                self.presentLocalConfirmation(title: self.gameStrings?.familyDoneConfirmationTitle() ?? "Finished?",
                                              message: self.gameStrings?.familyDoneConfirmationMessage() ?? "Are you sure you are finished? You cannot return to the Create A Family screen to edit this family again.",
                                              yes: self.gameStrings?.yesButton() ?? "Yes",
                                              no: self.gameStrings?.noButton() ?? "No") { [weak self, weak creation] code in
                    guard code == 0, let self, let creation else { return }
                    creation.beginSubmission()
                    householdCreationRequestObserved?(request)
                    guard let bridge = self.bridge else {
                        creation.failed(self.gameStrings?.moveInErrorMessage() ?? "Could not move in!")
                        return
                    }
                    do {
                        _ = try bridge.send("speed", ["value": 0])
                        let members: [[String: Any]] = request.members.map { member in
                            var fields: [String: Any] = ["name": member.name, "bio": member.bio, "code": member.code, "skin": member.skin, "personality": member.personality]
                            if let headChoice = member.headChoice { fields["headChoice"] = headChoice }
                            if let bodyChoice = member.bodyChoice { fields["bodyChoice"] = bodyChoice }
                            return fields
                        }
                        self.pendingHouseholdCreationRequest = try bridge.send("createHousehold", ["familyName": request.familyName, "members": members])
                    } catch {
                        creation.failed(String(describing: error))
                    }
                    if let view = self.window?.contentView as? GameMetalView {
                        view.setNeedsDisplay(view.bounds)
                        view.refreshAccessibilityButtons()
                        view.draw()
                    }
                }
            }, cancel: { [weak self] in self?.confirmCancelHouseholdCreation() }, delete: { [weak self, weak creation] index in
                guard let self, let creation else { return }
                self.presentLocalConfirmation(title: self.gameStrings?.familyDeleteConfirmationTitle() ?? "Delete Sim?",
                                              message: self.gameStrings?.familyDeleteConfirmationMessage() ?? "Are you sure you would like to delete this Sim?",
                                              yes: self.gameStrings?.yesButton() ?? "Yes",
                                              no: self.gameStrings?.noButton() ?? "No") { [weak self, weak creation] code in
                    guard code == 0, let self, let creation else { return }
                    creation.deleteMember(at: index)
                    if let view = self.window?.contentView as? GameMetalView {
                        view.setNeedsDisplay(view.bounds)
                        view.refreshAccessibilityButtons()
                        view.draw()
                    }
                }
            }, appearanceCatalog: { [weak self] gender, age, skin in
                guard let self, let bridge = self.bridge else {
                    creation.failed("The simulation is not connected.")
                    return
                }
                self.pendingHouseholdPreviewRequest = nil
                self.renderer?.clearHouseholdAppearancePreview()
                do {
                    self.pendingHouseholdAppearanceRequest = try bridge.send("appearanceCatalog", ["gender": gender, "age": age, "skin": skin])
                } catch {
                    creation.failed("Appearance choices could not be loaded: \(error.localizedDescription)")
                }
            }, previewAppearance: { [weak self] gender, age, skin, head, body in
                self?.requestHouseholdAppearancePreview(gender, age, skin, head, body, creation: creation)
            })
            if let view = window?.contentView as? GameMetalView {
                view.setNeedsDisplay(view.bounds)
                view.refreshAccessibilityButtons()
                view.draw()
            }
            return
        }
        guard let renderer else { return }
        if let dialog = renderer.gameDialog, localDialogToken == dialog.dialog.token {
            do {
                try dialog.prepare(canvas: canvas, scale: CGFloat(renderer.uiScale))
                if let code = dialog.choice(point, scale: CGFloat(renderer.uiScale)) {
                    try respondDialog(dialog, code: code)
                }
            } catch { fputs("Storage dialog: \(error)\n", stderr) }
            return
        }
        guard let bridge else { return }
        do {
            if let dialog = renderer.gameDialog {
                try dialog.prepare(canvas: canvas, scale: CGFloat(renderer.uiScale))
                if dialog.dialog.kind == 10 {
                    switch dialog.phoneBookAction(point, scale: CGFloat(renderer.uiScale)) {
                    case .some(.changedSelection):
                        if let view = window?.contentView as? GameMetalView { view.refreshAccessibilityButtons(); view.draw() }
                    case .some(.call(let neighborId)): try respondDialog(dialog, code: 1, responseText: String(neighborId))
                    case .some(.cancel): try respondDialog(dialog, code: 0, responseText: "-1")
                    case nil: break
                    }
                } else if let code = dialog.choice(point, scale: CGFloat(renderer.uiScale)) {
                    try respondDialog(dialog, code: code)
                }
                return
            }
            if let control = OriginalUniversalControl.hit(point: point, canvas: canvas, scale: CGFloat(renderer.uiScale)) {
                if control.action != .options { _ = try? bridge.send("audioEvent", ["name": "ui_click"]) }
                switch control.action {
                case .live:
                    leaveOptionsMode()
                    if renderer.buyMode { browseBuyCatalog(nil) }
                    else if renderer.buildMode { browseBuildCatalog(nil) }
                case .buy: leaveOptionsMode(); if !renderer.buyMode { browseBuyCatalog(nil) }
                case .zoomIn, .zoomOut:
                    dismissMenu()
                    renderer.setZoom(renderer.zoom.stepped(control.action == .zoomIn ? 1 : -1))
                case .wallsUp, .wallsDown, .wallsCutaway:
                    dismissMenu()
                    try bridge.send("walls", ["mode": control.action == .wallsUp ? "up" : control.action == .wallsCutaway ? "cutaway" : "down"])
                case .roofs:
                    dismissMenu()
                    try bridge.send("roofs", ["visible": !renderer.roofsVisible])
                case .story1: selectStory(1)
                case .story2: selectStory(2)
                case .cameraLeft: renderer.requestCameraRotation(-1)
                case .cameraRight: renderer.requestCameraRotation(1)
                case .build: leaveOptionsMode(); if !renderer.buildMode { browseBuildCatalog(nil) }
                case .options: renderer.optionsMode ? leaveOptionsMode() : enterOptionsMode()
                }
                return
            }
            if let speed = OriginalSpeedControl.hit(point: point, canvas: canvas, scale: CGFloat(renderer.uiScale)) {
                dismissMenu()
                sendSpeed(speed == 0 && renderer.speed == 0 ? 1 : speed)
                return
            }
            let scale = CGFloat(renderer.uiScale)
            let local = CGPoint(x: point.x / scale, y: point.y / scale)
            let logicalCanvas = CGSize(width: canvas.width / scale, height: canvas.height / scale)
            if renderer.optionsMode, let button = renderer.optionsPanel.button(at: local, canvas: logicalCanvas) {
                if renderer.optionsPanel.isEnabled(button) { chooseOption(button) }
                return
            }
            if renderer.optionsMode, let option = renderer.optionsPanel.option(at: local, canvas: logicalCanvas) {
                if option.isImplemented { togglePlayOption(option) }
                return
            }
            if renderer.buildMode {
                if let action = renderer.build.action(at: local, canvas: logicalCanvas) {
                    switch action {
                    case .page(let offset): try requestBuildCatalog(offset: offset)
                    case .kind(let kind):
                        dismissMenu()
                        try bridge.send("roofs", ["visible": kind == .roof])
                        renderer.build.changeKind(kind)
                        try requestBuildCatalog(offset: 0)
                    case .select(let id):
                        renderer.buy.cancelSelection()
                        renderer.build.choose(id)
                        if renderer.build.kind == .roof { try bridge.send("roof", ["style": id, "pitch": renderer.roofPitch]) }
                    case .objectTool(let tool):
                        dismissMenu()
                        renderer.build.changeObjectTool(tool)
                        renderer.buy.clear(category: tool.category ?? 0)
                        pendingBuildCatalog = nil
                        if tool.category != nil { try requestBuildCatalog(offset: 0) }
                    case .selectObject(let guid): renderer.chooseCatalogObject(guid)
                    case .terrain:
                        dismissMenu()
                        renderer.buy.cancelSelection()
                        renderer.build.changeTerrainMode(.raise)
                    case .terrainMode(let mode):
                        dismissMenu()
                        renderer.build.changeTerrainMode(mode)
                    case .history(let action):
                        dismissMenu()
                        if action == .undo ? renderer.gameplay.state?.canUndo == true : renderer.gameplay.state?.canRedo == true {
                            try bridge.send(action.rawValue, [:])
                        }
                    }
                } else if renderer.objectEditing, renderer.speed == 0 {
                    try editObject(at: point, canvas: canvas)
                } else if renderer.speed == 0, renderer.build.kind == .wall, let item = renderer.build.selectedItem, let wall = renderer.wall(at: point, canvas: canvas) {
                    try sendWithBuildSound("architecture", ["command": "PATTERN_DOT", "x": wall.x, "y": wall.y, "level": wall.level,
                                                     "x2": wall.direction, "y2": wall.direction, "pattern": item.id, "style": 0])
                } else if renderer.speed == 0, (renderer.build.kind == .floor || renderer.build.kind == .water), let item = renderer.build.selectedItem, let hit = renderer.floorHit(at: point, canvas: canvas) {
                    try sendWithBuildSound("architecture", ["command": "FLOOR_RECT", "x": hit.tile.x, "y": hit.tile.y, "level": renderer.viewLevel, "x2": 0, "y2": 0, "pattern": item.id, "style": hit.style])
                }
                updatePlacement(point, canvas: canvas)
                return
            }
            if renderer.buyMode {
                if let action = renderer.buy.action(at: local, canvas: logicalCanvas) {
                    switch action {
                    case .category(let category):
                        renderer.buy.clear(category: category)
                        try requestCatalog(category: category, offset: 0)
                    case .page(let offset): try requestCatalog(category: renderer.buy.category, offset: offset)
                    case .select(let guid): renderer.buy.choose(guid, budget: renderer.gameplay.state?.budget)
                    }
                } else if renderer.speed == 0 {
                    try editObject(at: point, canvas: canvas)
                }
                updatePlacement(point, canvas: canvas)
                return
            }
            if let sim = renderer.gameplay.selection(at: local, canvas: logicalCanvas) {
                dismissMenu()
                try bridge.send("selectSim", ["objectID": sim])
                return
            }
            if let token = renderer.gameplay.cancellation(at: local, canvas: logicalCanvas) {
                dismissMenu()
                try bridge.send("cancelAction", ["objectID": selectedSim, "token": token])
                _ = try? bridge.send("audioEvent", ["name": "ui_queue_delete"])
                return
            }
            if try renderer.gameplay.pageInterests(at: local, canvas: logicalCanvas) { dismissMenu(); return }
            if try renderer.gameplay.relationshipControl(at: local, canvas: logicalCanvas) { dismissMenu(); return }
            if let panel = renderer.gameplay.subpanel(at: local, canvas: logicalCanvas) {
                dismissMenu()
                try renderer.gameplay.choose(panel)
                if let view = window?.contentView as? MTKView {
                    view.setNeedsDisplay(view.bounds)
                    NSAccessibility.post(element: view, notification: .layoutChanged)
                    view.draw()
                }
                return
            }
            if renderer.gameplay.containsPanel(local, canvas: logicalCanvas) { dismissMenu(); return }
            if let menu = renderer.pieMenu {
                menu.prepare(canvas: canvas, scale: CGFloat(renderer.uiScale))
                let result = try menu.choose(point, scale: CGFloat(renderer.uiScale))
                if let action = result.action, menu.selectedSim == selectedSim, renderer.containsObject(menu.objectID) {
                    let interaction = try bridge.send("interact", ["objectID": menu.objectID, "interaction": Int(action.interaction), "param0": Int(action.param0), "global": action.global])
                    playUISound("ui_piemenu_select")
                    playUISoundOnResponse(interaction, success: "ui_queued", failure: nil)
                }
                if !result.keepOpen { dismissMenu() }
                else if let view = window?.contentView { NSAccessibility.post(element: view, notification: .layoutChanged) }
                return
            }
            dismissMenu()
            guard let target = renderer.object(at: point, canvas: canvas), selectedSim != 0 else { return }
            let id = try bridge.send("menu", ["objectID": target])
            pendingMenu = MenuRequest(id: id, object: target, caller: selectedSim,
                                      anchor: CGPoint(x: point.x / CGFloat(renderer.uiScale), y: point.y / CGFloat(renderer.uiScale)))
        } catch {
            dismissMenu()
            fputs("Interaction menu: \(error)\n", stderr)
        }
    }

    private func respondDialog(_ dialog: OriginalDialogOverlay, code: UInt8, responseText: String? = nil) throws {
        if localDialogToken == dialog.dialog.token {
            let response = localDialogResponse
            localDialogToken = nil
            localDialogResponse = nil
            renderer?.gameDialog = nil
            if let view = window?.contentView as? GameMetalView {
                view.setNeedsDisplay(view.bounds)
                view.refreshAccessibilityButtons()
                view.draw()
            }
            response?(code)
            return
        }
        guard !dialog.submitting else { return }
        guard let bridge else { return }
        try bridge.send("dialogResponse", ["token": dialog.dialog.token, "code": Int(code), "text": responseText ?? dialog.text])
        dialog.submitting = true
    }

    private func dialogKey(_ key: String) -> Bool {
        if let picker = renderer?.outfitPicker {
            switch key {
            case "\u{1b}": handleOutfitPicker(.cancel, picker: picker)
            case "\r", "\n": handleOutfitPicker(.buy(picker.index), picker: picker)
            case String(UnicodeScalar(NSLeftArrowFunctionKey)!): handleOutfitPicker(.previous, picker: picker)
            case String(UnicodeScalar(NSRightArrowFunctionKey)!): handleOutfitPicker(.next, picker: picker)
            default: break
            }
            return true
        }
        if let soundOptions = renderer?.soundOptions, soundOptions.isVisible {
            if key == "\u{1b}" {
                soundOptions.dismiss()
                _ = try? bridge?.send("audioEvent", ["name": "ui_click"])
                if let view = window?.contentView as? GameMetalView {
                    view.setNeedsDisplay(view.bounds)
                    view.refreshAccessibilityButtons()
                    view.draw()
                }
            }
            return true
        }
        if let dialog = renderer?.gameDialog, localDialogToken == dialog.dialog.token {
            do {
                if key == "\r" || key == "\n", let first = dialog.dialog.buttons.first(where: { $0.code == 0 }) {
                    try respondDialog(dialog, code: first.code)
                } else if key == "\u{1b}", let dismiss = dialog.dialog.buttons.first(where: { $0.code == 2 }) ?? dialog.dialog.buttons.first(where: { $0.code == 1 }) {
                    // Escape cancels a three-choice prompt; two-choice prompts treat it as No.
                    try respondDialog(dialog, code: dismiss.code)
                }
                if let view = window?.contentView as? GameMetalView {
                    view.refreshAccessibilityButtons()
                    view.draw()
                }
            } catch { fputs("Local dialog: \(error)\n", stderr) }
            return true
        }
        if let creation = renderer?.householdCreation {
            let handled = creation.key(key) { [weak self] in self?.confirmCancelHouseholdCreation() }
            if let view = window?.contentView as? GameMetalView {
                view.setNeedsDisplay(view.bounds)
                view.refreshAccessibilityButtons()
                view.draw()
            }
            return handled
        }
        if activeNeighborhoodDialog != nil {
            if key == "\u{1b}" { respondToNeighborhood(-1) }
            return true
        }
        guard let dialog = renderer?.gameDialog else { return false }
        do {
            if dialog.dialog.kind == 10 {
                switch key {
                case "\r", "\n":
                    if let neighbor = dialog.selectedPhoneBookContact() { try respondDialog(dialog, code: 1, responseText: String(neighbor)) }
                case "\u{1b}": try respondDialog(dialog, code: 0, responseText: "-1")
                case "\u{f700}": dialog.movePhoneBookSelection(-1)
                case "\u{f701}": dialog.movePhoneBookSelection(1)
                case "\u{f702}": dialog.movePhoneBookFamily(-1)
                case "\u{f703}": dialog.movePhoneBookFamily(1)
                default: break
                }
                if let view = window?.contentView as? GameMetalView { view.refreshAccessibilityButtons(); view.draw() }
                return true
            }
            if key == "\r" || key == "\n" {
                if let first = dialog.dialog.buttons.first { try respondDialog(dialog, code: first.code) }
            } else if key == "\u{1b}" {
                if let cancel = dialog.dialog.buttons.first(where: { $0.code == 2 }) { try respondDialog(dialog, code: cancel.code) }
                else if localDialogToken == dialog.dialog.token,
                        let no = dialog.dialog.buttons.first(where: { $0.code == 1 }) { try respondDialog(dialog, code: no.code) }
            } else if dialog.dialog.kind == 3 && !dialog.submitting {
                if key == "\u{7f}" { try dialog.updateText(String(dialog.text.dropLast())) }
                else { try dialog.updateText(dialog.text + key) }
            }
        } catch { fputs("Game dialog: \(error)\n", stderr) }
        return true
    }

    private func editObject(at point: CGPoint, canvas: CGSize) throws {
        guard let renderer, renderer.objectEditing, renderer.speed == 0, renderer.gameDialog == nil else { return }
        if let target = renderer.buy.selection.target, let tile = renderer.groundTile(at: point, canvas: canvas) {
            switch target {
            case .catalog(let guid):
                if let price = renderer.selectedCatalogPrice, price <= (renderer.gameplay.state?.budget ?? 0) {
                    let request = try bridge?.send("buyObject", ["guid": guid, "x": tile.placementX, "y": tile.placementY, "level": renderer.viewLevel, "direction": renderer.buy.direction])
                    playUISoundOnResponse(request, success: "ui_buy_place")
                } else {
                    playUISound("ui_error")
                }
            case .placed(let object):
                if object.movable {
                    let request = try bridge?.send("moveObject", ["objectID": object.id, "x": tile.placementX, "y": tile.placementY, "level": renderer.viewLevel, "direction": renderer.buy.direction])
                    playUISoundOnResponse(request, success: "ui_object_move_place")
                    renderer.buy.cancelSelection()
                }
            }
        } else if renderer.buy.selection.target == nil, let id = renderer.object(at: point, canvas: canvas), let object = editableObjects.first(where: { $0.id == id && $0.level == renderer.viewLevel }) {
            renderer.buy.selection.chooseObject(object)
        }
    }
    @objc func togglePause(_ sender: Any?) { sendSpeed(renderer?.speed == 0 ? 1 : 0) }
    @objc func normalSpeed(_ sender: Any?) { sendSpeed(1) }
    @objc func fastSpeed(_ sender: Any?) { sendSpeed(3) }
    @objc func fastestSpeed(_ sender: Any?) { sendSpeed(10) }
    private func selectStory(_ level: Int) {
        guard let renderer, renderer.gameDialog == nil, (1...renderer.storyCount).contains(level), (level != renderer.viewLevel || renderer.roofsVisible) else { return }
        dismissMenu()
        renderer.buy.selection.cancel()
        floorStroke = nil
        wallStroke = nil
        floorBrush = nil
        wallBrush = nil
        desiredPlacement = nil
        checkedPlacement = nil
        try? renderer.updatePlacement(nil)
        try? renderer.updateFloorBrush(nil)
        try? renderer.updateWallBrush(nil)
        _ = try? bridge?.send("level", ["value": level])
    }
    @objc func storyUp(_ sender: Any?) { selectStory((renderer?.viewLevel ?? 1) + 1) }
    @objc func storyDown(_ sender: Any?) { selectStory((renderer?.viewLevel ?? 1) - 1) }
    @objc func toggleWalls(_ sender: Any?) { dismissMenu(); _ = try? bridge?.send("walls", ["up": !(renderer?.wallsUp ?? false)]) }
    @objc func browseBuyCatalog(_ sender: Any?) {
        guard let renderer, renderer.gameDialog == nil else { return }
        dismissMenu()
        renderer.buildMode = false
        pendingBuildCatalog = nil
        renderer.buyMode.toggle()
        _ = try? bridge?.send("audioEvent", ["name": renderer.buyMode ? "bkground_buy1" : "bkground_live"])
        pendingCatalog = nil
        if renderer.buyMode {
            sendSpeed(0)
            renderer.buy.clear(category: 0)
            do { try requestCatalog(category: 0, offset: 0) }
            catch { fputs("Buy catalog: \(error)\n", stderr) }
        }
    }
    @objc func browseBuildCatalog(_ sender: Any?) {
        guard let renderer, renderer.gameDialog == nil else { return }
        dismissMenu()
        renderer.buyMode = false
        pendingCatalog = nil
        renderer.buildMode.toggle()
        _ = try? bridge?.send("audioEvent", ["name": renderer.buildMode ? "bkground_build" : "bkground_live"])
        pendingBuildCatalog = nil
        if renderer.buildMode {
            sendSpeed(0)
            renderer.build.changeKind(.floor)
            do { try requestBuildCatalog(offset: 0) }
            catch { fputs("Build catalog: \(error)\n", stderr) }
        }
    }
    private func requestBuildCatalog(offset: Int) throws {
        guard let view = window?.contentView else { return }
        let count = OriginalBuildLayout.capacity(canvas: view.bounds.size)
        if let category = renderer?.build.objectTool?.category {
            pendingBuildCatalog = try bridge?.send("catalogPage", ["category": category, "offset": offset, "count": count])
        } else {
            pendingBuildCatalog = try bridge?.send("buildCatalogPage", ["kind": renderer?.build.kind.rawValue ?? "floor", "offset": offset, "count": count])
        }
    }
    private func requestCatalog(category: Int, offset: Int) throws {
        guard let view = window?.contentView else { return }
        let count = OriginalBuyLayout.capacity(canvas: view.bounds.size)
        pendingCatalog = try bridge?.send("catalogPage", ["category": category, "offset": offset, "count": count])
    }
    private func floorTile(at point: CGPoint, canvas: CGSize) -> GroundTile? { floorHit(point, canvas: canvas)?.tile }
    private func floorHit(_ point: CGPoint, canvas: CGSize) -> FloorTileHit? {
        guard let renderer else { return nil }
        let scale = CGFloat(renderer.uiScale)
        guard OriginalUniversalControl.hit(point: point, canvas: canvas, scale: scale) == nil,
              OriginalSpeedControl.hit(point: point, canvas: canvas, scale: scale) == nil,
              renderer.build.action(at: CGPoint(x: point.x / scale, y: point.y / scale),
                                    canvas: CGSize(width: canvas.width / scale, height: canvas.height / scale)) == nil else { return nil }
        return renderer.floorHit(at: point, canvas: canvas)
    }
    private func fillRoom(_ point: CGPoint, canvas: CGSize, removing: Bool) -> Bool {
        guard let renderer, renderer.buildMode, renderer.build.objectTool == nil, renderer.speed == 0, renderer.gameDialog == nil,
              removing || renderer.build.selectedItem != nil else { return false }
        let scale = CGFloat(renderer.uiScale)
        guard OriginalUniversalControl.hit(point: point, canvas: canvas, scale: scale) == nil,
              OriginalSpeedControl.hit(point: point, canvas: canvas, scale: scale) == nil,
              renderer.build.action(at: CGPoint(x: point.x / scale, y: point.y / scale),
                                    canvas: CGSize(width: canvas.width / scale, height: canvas.height / scale)) == nil,
              let fill = BuildRoomFill(kind: renderer.build.kind, pattern: renderer.build.selectedItem?.id ?? 0,
                                       tile: renderer.groundTile(at: point, canvas: canvas), wall: renderer.wall(at: point, canvas: canvas), removing: removing, selectedLevel: renderer.viewLevel) else { return false }
        floorStroke = nil
        floorBrush = nil
        try? renderer.updateFloorBrush(nil)
        do {
            try sendWithBuildSound("architecture", ["command": fill.command, "x": fill.x, "y": fill.y, "level": fill.level,
                                              "x2": 0, "y2": 0, "pattern": fill.pattern, "style": 0])
        } catch { fputs("Room fill: \(error)\n", stderr) }
        return true
    }
    private func updateBuildPreview(_ point: CGPoint, canvas: CGSize) {
        if renderer?.objectEditing == true { updatePlacement(point, canvas: canvas); return }
        if renderer?.build.terrainMode != nil { return }
        if renderer?.build.kind == .wallStyle { updateWallPreview(point, canvas: canvas) }
        else { updateFloorPreview(point, canvas: canvas) }
    }
    private func terrainTile(_ point: CGPoint, canvas: CGSize) -> GroundTile? {
        guard let renderer, renderer.buildMode, renderer.build.terrainMode != nil,
              renderer.build.objectTool == nil, renderer.speed == 0, renderer.gameDialog == nil,
              OriginalUniversalControl.hit(point: point, canvas: canvas, scale: CGFloat(renderer.uiScale)) == nil,
              OriginalSpeedControl.hit(point: point, canvas: canvas, scale: CGFloat(renderer.uiScale)) == nil else { return nil }
        let scale = CGFloat(renderer.uiScale)
        let logical = CGPoint(x: point.x / scale, y: point.y / scale)
        let logicalCanvas = CGSize(width: canvas.width / scale, height: canvas.height / scale)
        guard renderer.build.action(at: logical, canvas: logicalCanvas) == nil else { return nil }
        return renderer.groundTile(at: point, canvas: canvas)
    }
    private func startTerrainStroke(_ point: CGPoint, canvas: CGSize) -> Bool {
        guard let renderer, let mode = renderer.build.terrainMode,
              let tile = terrainTile(point, canvas: canvas) else { return false }
        terrainStrokeMode = mode
        terrainStrokeStartPoint = point
        terrainGesture = TerrainBrushGesture()
        terrainGesture.begin(at: tile)
        return true
    }
    private func updateTerrainStroke(_ point: CGPoint, canvas: CGSize) {
        guard terrainStrokeMode != nil, let tile = terrainTile(point, canvas: canvas) else { return }
        terrainGesture.move(to: tile)
    }
    private func finishTerrainStroke(_ point: CGPoint, canvas: CGSize) {
        guard let mode = terrainStrokeMode else { return }
        terrainStrokeMode = nil
        let startPoint = terrainStrokeStartPoint
        terrainStrokeStartPoint = nil
        guard let renderer, let scene = renderer.scene, let tile = terrainTile(point, canvas: canvas) else {
            terrainGesture = TerrainBrushGesture()
            return
        }
        terrainGesture.move(to: tile)
        do {
            let viewport = SceneViewport(scene: scene, canvas: SIMD2(Float(canvas.width), Float(canvas.height)),
                                         panelHeight: renderer.liveMode ? Float(150 * renderer.uiScale) : 0,
                                         zoom: renderer.zoom, uiScale: renderer.uiScale, pan: renderer.pan)
            let heightDelta: Int16?
            if mode == .raise || mode == .lower {
                heightDelta = try TerrainHeightDrag.delta(startY: Double(startPoint?.y ?? point.y), endY: Double(point.y),
                                                          viewportScale: Double(viewport.scale), mode: mode)
            } else { heightDelta = nil }
            let requests = try terrainGesture.finishStroke(mode: mode, level: renderer.viewLevel, scene: scene, heightDelta: heightDelta)
            guard !requests.isEmpty else { return }
            try sendWithBuildSound("architectureBatch", ["commands": requests.map(\.payload)])
        } catch {
            terrainGesture = TerrainBrushGesture()
            fputs("Terrain editing: \(error)\n", stderr)
        }
    }
    private func startWallStroke(_ point: CGPoint, canvas: CGSize, rectangle: Bool, deleting: Bool) -> Bool {
        guard let renderer, renderer.buildMode, renderer.build.objectTool == nil, renderer.build.kind == .wallStyle, renderer.speed == 0, renderer.gameDialog == nil,
              let item = renderer.build.selectedItem, let pattern = item.pattern,
              floorTile(at: point, canvas: canvas) != nil, let vertex = renderer.lotVertex(at: point, canvas: canvas) else { return false }
        wallStroke = (vertex, item.id, pattern, rectangle, deleting)
        return true
    }
    private func updateWallPreview(_ point: CGPoint, canvas: CGSize) {
        pointer = point
        guard let renderer, renderer.buildMode, renderer.build.objectTool == nil, renderer.speed == 0, renderer.gameDialog == nil, let stroke = wallStroke,
              renderer.build.selectedItem?.id == stroke.style, floorTile(at: point, canvas: canvas) != nil,
              let vertex = renderer.lotVertex(at: point, canvas: canvas), let line = WallBrushSelection(start: stroke.start, end: vertex, rectangle: stroke.rectangle, deleting: stroke.deleting) else {
            wallBrush = nil
            try? self.renderer?.updateWallBrush(nil)
            return
        }
        guard line != wallBrush else { return }
        do { try renderer.updateWallBrush(line); wallBrush = line }
        catch { fputs("Wall brush: \(error)\n", stderr) }
    }
    private func finishWallStroke(_ point: CGPoint, canvas: CGSize) {
        guard let stroke = wallStroke else { return }
        wallStroke = nil
        wallBrush = nil
        try? renderer?.updateWallBrush(nil)
        guard let renderer, renderer.buildMode, renderer.build.objectTool == nil, renderer.build.kind == .wallStyle, renderer.speed == 0, renderer.gameDialog == nil,
              renderer.build.selectedItem?.id == stroke.style, floorTile(at: point, canvas: canvas) != nil,
              let vertex = renderer.lotVertex(at: point, canvas: canvas), let line = WallBrushSelection(start: stroke.start, end: vertex, rectangle: stroke.rectangle, deleting: stroke.deleting) else { return }
        do {
            let arguments = line.arguments
            try sendWithBuildSound("architecture", ["command": line.command, "x": arguments.x, "y": arguments.y, "level": renderer.viewLevel,
                                              "x2": arguments.x2, "y2": arguments.y2, "pattern": stroke.pattern, "style": stroke.style])
        } catch { fputs("Wall building: \(error)\n", stderr) }
    }
    private func removeWallpaper(_ point: CGPoint, canvas: CGSize, removing: Bool) -> Bool {
        guard removing, let renderer, renderer.buildMode, renderer.build.objectTool == nil, renderer.build.kind == .wall, renderer.speed == 0, renderer.gameDialog == nil else { return false }
        let scale = CGFloat(renderer.uiScale)
        guard OriginalUniversalControl.hit(point: point, canvas: canvas, scale: scale) == nil,
              OriginalSpeedControl.hit(point: point, canvas: canvas, scale: scale) == nil,
              renderer.build.action(at: CGPoint(x: point.x / scale, y: point.y / scale),
                                    canvas: CGSize(width: canvas.width / scale, height: canvas.height / scale)) == nil,
              let wall = renderer.wall(at: point, canvas: canvas) else { return false }
        do {
            try sendWithBuildSound("architecture", ["command": "PATTERN_DOT", "x": wall.x, "y": wall.y, "level": wall.level,
                                              "x2": wall.direction, "y2": wall.direction, "pattern": 0, "style": 0])
        } catch { fputs("Wallpaper removal: \(error)\n", stderr) }
        return true
    }
    private func startFloorStroke(_ point: CGPoint, canvas: CGSize, deleting: Bool) -> Bool {
        guard let renderer, renderer.buildMode, renderer.build.objectTool == nil, renderer.build.selectedObjectGUID == nil, (renderer.build.kind == .floor || renderer.build.kind == .water), renderer.speed == 0, renderer.gameDialog == nil,
              let pattern = deleting ? UInt16(0) : renderer.build.selectedItem?.id, let tile = floorTile(at: point, canvas: canvas) else { return false }
        floorStroke = (tile, pattern, renderer.build.selectedItem?.id, deleting)
        floorBrush = nil
        updateFloorPreview(point, canvas: canvas)
        return true
    }
    private func updateFloorPreview(_ point: CGPoint, canvas: CGSize) {
        pointer = point
        guard let renderer, renderer.buildMode, renderer.build.objectTool == nil, renderer.build.selectedObjectGUID == nil, (renderer.build.kind == .floor || renderer.build.kind == .water), renderer.speed == 0, renderer.gameDialog == nil, (renderer.build.selectedItem != nil || floorStroke?.deleting == true),
              let hit = floorHit(point, canvas: canvas),
              let rectangle = FloorBrushRectangle(start: floorStroke?.start ?? hit.tile, end: hit.tile),
              let selection = FloorBrushSelection(rectangle: rectangle, half: hit.half, water: renderer.build.kind == .water && floorStroke?.deleting != true) else {
            floorBrush = nil
            try? self.renderer?.updateFloorBrush(nil)
            return
        }
        guard selection != floorBrush else { return }
        do {
            try renderer.updateFloorBrush(selection, deleting: floorStroke?.deleting == true)
            floorBrush = selection
        } catch { fputs("Floor brush: \(error)\n", stderr) }
    }
    private func finishFloorStroke(_ point: CGPoint, canvas: CGSize) {
        guard let stroke = floorStroke else { return }
        floorStroke = nil
        floorBrush = nil
        try? renderer?.updateFloorBrush(nil)
        guard let renderer, renderer.buildMode, renderer.build.objectTool == nil, renderer.build.selectedObjectGUID == nil, (renderer.build.kind == .floor || renderer.build.kind == .water), renderer.speed == 0, renderer.gameDialog == nil,
              renderer.build.selectedItem?.id == stroke.selection, let hit = floorHit(point, canvas: canvas),
              let rectangle = FloorBrushRectangle(start: stroke.start, end: hit.tile),
              let selection = FloorBrushSelection(rectangle: rectangle, half: hit.half, water: renderer.build.kind == .water && !stroke.deleting) else { return }
        do {
            try sendWithBuildSound("architecture", ["command": "FLOOR_RECT", "x": rectangle.x, "y": rectangle.y, "level": renderer.viewLevel,
                                              "x2": rectangle.width, "y2": rectangle.height, "pattern": stroke.pattern, "style": selection.style])
            updateFloorPreview(point, canvas: canvas)
        } catch { fputs("Floor painting: \(error)\n", stderr) }
    }

    private func updatePlacement(_ point: CGPoint, canvas: CGSize) {
        if renderer?.buildMode == true && renderer?.objectEditing == false { updateBuildPreview(point, canvas: canvas); return }
        guard let renderer, renderer.objectEditing, renderer.speed == 0, renderer.gameDialog == nil,
              let target = renderer.buy.selection.target, let tile = renderer.groundTile(at: point, canvas: canvas) else {
            desiredPlacement = nil
            checkedPlacement = nil
            try? self.renderer?.updatePlacement(nil)
            return
        }
        let unavailable: Bool
        switch target {
        case .placed(let object): unavailable = !object.movable
        case .catalog: unavailable = (renderer.selectedCatalogPrice ?? Int.max) > (renderer.gameplay.state?.budget ?? 0)
        }
        if unavailable {
            desiredPlacement = nil
            checkedPlacement = nil
            try? renderer.updatePlacement(nil)
            return
        }
        let key = PlacementKey(target: target, tile: tile, direction: renderer.buy.direction, revision: renderer.currentSceneRevision, level: renderer.viewLevel)
        if desiredPlacement != key { try? renderer.updatePlacement(nil) }
        desiredPlacement = key
        requestPlacement()
    }
    private func requestPlacement() {
        guard pendingPlacement == nil, let key = desiredPlacement, key != checkedPlacement else { return }
        var parameters: [String: Any] = ["x": key.tile.placementX, "y": key.tile.placementY, "level": key.level, "direction": key.direction]
        switch key.target {
        case .catalog(let guid): parameters["guid"] = guid
        case .placed(let object): parameters["objectID"] = object.id
        }
        do {
            if let id = try bridge?.send("previewObject", parameters) { pendingPlacement = (id, key) }
        } catch { fputs("Placement preview: \(error)\n", stderr) }
    }
    private func sellHeldObject() {
        guard let renderer, renderer.objectEditing, renderer.speed == 0, renderer.gameDialog == nil,
              case .placed(let object) = renderer.buy.selection.target, object.sellable else { return }
        do {
            let request = try bridge?.send("sellObject", ["objectID": object.id])
            playUISoundOnResponse(request, success: "ui_object_moneyback")
            renderer.buy.cancelSelection()
            desiredPlacement = nil
            try renderer.updatePlacement(nil)
        } catch { fputs("Sell object: \(error)\n", stderr) }
    }
    @objc func saveGame(_ sender: Any?) {
        guard renderer?.gameDialog == nil else { return }
        dismissMenu()
        guard bridge != nil else {
            presentStorageFeedback(.saveFailed, title: gameStrings?.saveHouseTitle() ?? "Save House", message: gameStrings?.saveFailedMessage() ?? "An error was encountered saving the house.")
            return
        }
        presentLocalConfirmation(title: gameStrings?.saveHouseTitle() ?? "Save House",
                                  message: gameStrings?.saveConfirmationMessage() ?? "Do you want to save the game?",
                                  yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
            guard code == 0 else { return }
            self?.sendSaveRequest()
        }
    }
    private func sendSaveRequest() {
        guard let bridge else {
            presentStorageFeedback(.saveFailed, title: gameStrings?.saveHouseTitle() ?? "Save House", message: gameStrings?.saveFailedMessage() ?? "An error was encountered saving the house.")
            return
        }
        do {
            pendingSaveRequests.insert(try bridge.send("save", ["slot": "manual"]))
        } catch {
            fputs("Save request: \(error)\n", stderr)
            presentStorageFeedback(.saveFailed, title: gameStrings?.saveHouseTitle() ?? "Save House", message: gameStrings?.saveFailedMessage() ?? "An error was encountered saving the house.")
        }
    }
    @objc func loadGame(_ sender: Any?) {
        guard renderer?.gameDialog == nil else { return }
        dismissMenu()
        guard bridge != nil else {
            presentStorageFeedback(.loadFailed, title: gameStrings?.loadHouseTitle() ?? "Load House", message: gameStrings?.loadFailedMessage() ?? "The house could not be loaded.")
            return
        }
        presentLocalConfirmation(title: gameStrings?.loadHouseTitle() ?? "Load House",
                                  message: gameStrings?.loadConfirmationMessage() ?? "Are you sure?",
                                  yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
            guard code == 0 else { return }
            self?.sendLoadRequest()
        }
    }
    private func sendLoadRequest() {
        guard let bridge else {
            presentStorageFeedback(.loadFailed, title: gameStrings?.loadHouseTitle() ?? "Load House", message: gameStrings?.loadFailedMessage() ?? "The house could not be loaded.")
            return
        }
        do {
            pendingLoadRequests.insert(try bridge.send("load", ["slot": "manual"]))
        } catch {
            fputs("Load request: \(error)\n", stderr)
            presentStorageFeedback(.loadFailed, title: gameStrings?.loadHouseTitle() ?? "Load House", message: gameStrings?.loadFailedMessage() ?? "The house could not be loaded.")
        }
    }
    @objc func nextSim(_ sender: Any?) {
        dismissMenu()
        guard !simIDs.isEmpty else { return }
        let current = simIDs.firstIndex(of: selectedSim) ?? -1
        _ = try? bridge?.send("selectSim", ["objectID": simIDs[(current + 1) % simIDs.count]])
    }

    /// Enters the original control-panel Options mode (Save, Neighborhood, Quit, Graphics, Sound, Play).
    func enterOptionsMode() {
        guard let renderer, renderer.gameDialog == nil else { return }
        dismissMenu()
        if renderer.buyMode { browseBuyCatalog(nil) } else if renderer.buildMode { browseBuildCatalog(nil) }
        renderer.soundOptions.dismiss()
        renderer.optionsPanel.select(.none)
        renderer.optionsMode = true
        playUISound("ui_click")
        refreshGameView()
    }

    func leaveOptionsMode() {
        guard let renderer, renderer.optionsMode else { return }
        renderer.optionsMode = false
        renderer.optionsPanel.select(.none)
        if renderer.soundOptions.isEmbedded { renderer.soundOptions.dismiss() }
        refreshGameView()
    }

    private func refreshGameView() {
        if let view = window?.contentView as? GameMetalView {
            view.setNeedsDisplay(view.bounds)
            view.refreshAccessibilityButtons()
            view.draw()
        }
    }

    private func chooseOption(_ button: OriginalOptionsPanelOverlay.Button) {
        guard let renderer else { return }
        playUISound("ui_click")
        switch button {
        case .save:
            saveGame(nil)
        case .sound:
            if renderer.soundOptions.isEmbedded {
                renderer.soundOptions.dismiss()
                renderer.optionsPanel.select(.none)
            } else {
                renderer.soundOptions.showEmbedded(rows: OriginalOptionsPanelOverlay.soundRows(strings: gameStrings ?? OriginalUIStrings(content: renderer.content)))
                renderer.optionsPanel.select(.sound)
                requestAudioState()
            }
        case .neighborhood:
            // Original flow: offer to save, then return to the neighborhood (UIText STR# 153 entries 3 and 4).
            presentLocalConfirmation(title: gameStrings?.saveMenuTitle() ?? "Save", message: gameStrings?.saveConfirmationMessage() ?? "Do you want to save the game?",
                                     yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
                self?.returnToNeighborhood(saving: code == 0)
            }
        case .quit:
            presentLocalConfirmation(title: gameStrings?.quitTitle() ?? "Quit?", message: gameStrings?.quitMessage() ?? "Are you sure you want to quit?",
                                     yes: gameStrings?.yesButton() ?? "Yes", no: gameStrings?.noButton() ?? "No") { [weak self] code in
                guard code == 0 else { return }
                self?.presentLocalConfirmation(title: self?.gameStrings?.quitTitle() ?? "Quit?",
                                               message: self?.gameStrings?.saveBeforeQuitMessage() ?? "Do you want to save before quitting?",
                                               yes: self?.gameStrings?.yesButton() ?? "Yes", no: self?.gameStrings?.noButton() ?? "No") { [weak self] save in
                    if save == 0 { _ = try? self?.bridge?.send("save", ["slot": "manual"]) }
                    self?.bridge?.stop(save: false)
                    NSApp.terminate(nil)
                }
            }
        case .play, .graphics:
            let target: OriginalOptionsPanelOverlay.Page = button == .play ? .play : .graphics
            let opening = renderer.optionsPanel.page != target
            if renderer.soundOptions.isEmbedded { renderer.soundOptions.dismiss() }
            renderer.optionsPanel.select(opening ? target : .none)
        }
        refreshGameView()
    }

    private var playOptionsURL: URL { dataRoot.appendingPathComponent("Settings/options.json") }

    func loadPlayOptions() {
        guard let data = try? Data(contentsOf: playOptionsURL),
              let options = try? JSONDecoder().decode(OriginalOptionsPanelOverlay.PlayOptions.self, from: data) else { return }
        renderer?.optionsPanel.playOptions = options
        renderer?.lightingEnabled = options.lighting
    }

    private func savePlayOptions(_ options: OriginalOptionsPanelOverlay.PlayOptions) {
        do {
            try FileManager.default.createDirectory(at: playOptionsURL.deletingLastPathComponent(), withIntermediateDirectories: true)
            try JSONEncoder().encode(options).write(to: playOptionsURL, options: .atomic)
        } catch { fputs("Play options: \(error)\n", stderr) }
    }

    /// Applies options that need simulation or client behavior; called after toggles and when a lot starts.
    func applyPlayOptions() {
        guard let options = renderer?.optionsPanel.playOptions else { return }
        _ = try? bridge?.send("freeWill", ["enabled": options.freeWill])
    }

    private func togglePlayOption(_ option: OriginalOptionsPanelOverlay.PlayOption) {
        guard let renderer else { return }
        let updated = option.toggled(renderer.optionsPanel.playOptions)
        renderer.optionsPanel.playOptions = updated
        savePlayOptions(updated)
        playUISound("ui_click")
        applyPlayOptions()
        renderer.lightingEnabled = updated.lighting
        if !updated.quickTips { (window?.contentView as? GameMetalView)?.toolTip = nil }
        refreshGameView()
    }

    /// Sim In Background: unless enabled, the simulation pauses while the app is inactive and resumes at its earlier speed.
    func observeActivation() {
        guard activationObservers.isEmpty else { return }
        let center = NotificationCenter.default
        activationObservers = [
            center.addObserver(forName: NSApplication.didResignActiveNotification, object: nil, queue: .main) { [weak self] _ in
                MainActor.assumeIsolated {
                    guard let self, let renderer = self.renderer, renderer.liveMode, renderer.speed > 0,
                          !renderer.optionsPanel.playOptions.simInBackground, let bridge = self.bridge else { return }
                    self.pausedByDeactivation = renderer.speed
                    _ = try? bridge.send("speed", ["value": 0])
                }
            },
            center.addObserver(forName: NSApplication.didBecomeActiveNotification, object: nil, queue: .main) { [weak self] _ in
                MainActor.assumeIsolated {
                    guard let self, let speed = self.pausedByDeactivation else { return }
                    self.pausedByDeactivation = nil
                    // Do not override a pause the player chose after returning, or build/buy mode, which stays paused.
                    guard self.renderer?.speed == 0, self.renderer?.buyMode == false, self.renderer?.buildMode == false else { return }
                    _ = try? self.bridge?.send("speed", ["value": speed])
                }
            }
        ]
    }

    /// Edge scrolling: pans the lot while the pointer rests on a window edge, as the original game does.
    func startEdgeScrolling() {
        edgeScrollTimer?.invalidate()
        edgeScrollTimer = Timer.scheduledTimer(withTimeInterval: 1.0 / 60, repeats: true) { [weak self] _ in
            MainActor.assumeIsolated { self?.edgeScrollTick() }
        }
    }

    private func edgeScrollTick() {
        guard let renderer, renderer.liveMode, renderer.optionsPanel.playOptions.edgeScrolling, renderer.gameDialog == nil,
              renderer.pluginPanel == nil, !renderer.soundOptions.isVisible || renderer.soundOptions.isEmbedded,
              let window, window.isKeyWindow, let view = window.contentView as? GameMetalView else { return }
        let mouse = window.mouseLocationOutsideOfEventStream
        let bounds = view.bounds
        guard bounds.contains(mouse) else { return }
        // Keep the control panel (bottom 150 points, flipped coordinates aside) free of edge scrolling.
        let margin: CGFloat = 4, speed: CGFloat = 14
        var delta = SIMD2<Float>(repeating: 0)
        if mouse.x < margin { delta.x = Float(speed) } else if mouse.x > bounds.width - margin { delta.x = -Float(speed) }
        if mouse.y > bounds.height - margin { delta.y = Float(speed) } else if mouse.y < margin { delta.y = -Float(speed) }
        guard delta != SIMD2<Float>(repeating: 0) else { return }
        renderer.pan += delta
        view.setNeedsDisplay(bounds)
    }

    /// Leaves the lot for the base neighborhood screen, optionally saving the manual slot first.
    private func returnToNeighborhood(saving: Bool) {
        guard let renderer, let content = currentContent, let view = window?.contentView as? GameMetalView else { return }
        leaveOptionsMode()
        if saving { _ = try? bridge?.send("save", ["slot": "manual"]) }
        audio?.stop()
        bridge?.stop(save: false)
        bridge = nil
        simIDs = []
        renderer.liveMode = false
        renderer.pieMenu = nil
        window?.title = "The Sims — loading neighborhood"
        Task { [weak self, weak renderer, weak view] in
            guard let self else { return }
            do {
                let exported = try await NeighborhoodExport.create(content: content, workspace: self.workspace, dataRoot: self.dataRoot, mode: 1, profileID: self.activeProfileID,
                                                                    neighborhood: self.currentNeighborhood)
                guard let renderer, let view else { return }
                renderer.neighborhood = try OriginalNeighborhoodOverlay(content: content, device: renderer.device, manifestURL: exported.manifest,
                                                                         session: exported.session, font: renderer.pieFont)
                renderer.neighborhoodHouseSelected = { [weak self] house in self?.selectNeighborhoodHouse(house, content: content) }
                self.window?.title = "The Sims — Neighborhood"
                self.startFrontendAudio(content: content)
                if let neighborhood = renderer.neighborhood { self.startNeighborhoodAudio(neighborhood) }
                view.setAccessibilityHelp("Select a house in the neighborhood")
                view.refreshAccessibilityButtons()
                view.setNeedsDisplay(view.bounds)
            } catch { self.showNeighborhoodError(error) }
        }
    }

    @objc func openSoundOptions(_ sender: Any?) {
        guard let renderer, renderer.gameDialog == nil else { return }
        // On a lot, the original sound sliders live in the control panel's Options mode.
        if renderer.liveMode, renderer.neighborhood == nil, renderer.householdCreation == nil {
            if !renderer.optionsMode { enterOptionsMode() }
            if !renderer.soundOptions.isEmbedded { chooseOption(.sound) }
            return
        }
        dismissMenu()
        if renderer.buyMode || renderer.buildMode {
            renderer.buyMode = false
            renderer.buildMode = false
            renderer.buy.cancelSelection()
            pendingCatalog = nil
            pendingBuildCatalog = nil
            pendingPlacement = nil
            desiredPlacement = nil
            checkedPlacement = nil
            try? renderer.updatePlacement(nil)
            try? renderer.updateFloorBrush(nil)
            try? renderer.updateWallBrush(nil)
            _ = try? bridge?.send("audioEvent", ["name": "bkground_live"])
        }
        renderer.soundOptions.show()
        _ = try? bridge?.send("audioEvent", ["name": "ui_click"])
        requestAudioState()
        if let view = window?.contentView as? GameMetalView {
            view.setNeedsDisplay(view.bounds)
            view.refreshAccessibilityButtons()
            view.draw()
        }
    }

    private func requestAudioState() {
        guard let bridge else { return }
        do { pendingAudioState = try bridge.send("audioState") }
        catch { fputs("Audio settings: \(error)\n", stderr) }
    }

    func soundOptionsMenuTitle() -> String {
        (gameStrings?.soundOptionsTitle() ?? "Sound Options") + "…"
    }

    private func sendAudioVolume(_ change: OriginalSoundOptionsOverlay.VolumeChange?) {
        guard let change, let bridge else { return }
        do {
            let id = try bridge.send("audioVolume", ["group": change.group, "volume": change.volume])
            pendingAudioVolumes[id] = change
            latestAudioVolumeRequest[change.group] = id
        }
        catch { fputs("Audio settings: \(error)\n", stderr) }
    }

    private func simulationEvent(_ event: [String: Any]) {
        do {
            if event["type"] as? String == "response", let id = event["id"] as? String, pendingAudioState == id {
                pendingAudioState = nil
                if event["ok"] as? Bool == true,
                   let result = event["result"] as? [String: Any],
                   let volumes = result["volumes"] as? [String: Any] {
                    renderer?.soundOptions.updateVolumes(volumes)
                    if let view = window?.contentView as? GameMetalView {
                        view.setNeedsDisplay(view.bounds)
                        view.draw()
                    }
                }
            }
            if event["type"] as? String == "response", let id = event["id"] as? String,
               let change = pendingAudioVolumes.removeValue(forKey: id), latestAudioVolumeRequest[change.group] == id {
                latestAudioVolumeRequest.removeValue(forKey: change.group)
                if event["ok"] as? Bool != true {
                    renderer?.soundOptions.restore(change)
                    if let view = window?.contentView as? GameMetalView {
                        view.setNeedsDisplay(view.bounds)
                        view.draw()
                    }
                }
            }
            if event["type"] as? String == "response",
               let id = event["id"] as? String,
               pendingSaveRequests.remove(id) != nil {
                if event["ok"] as? Bool == true {
                    let result = event["result"] as? [String: Any]
                    let path = result?["path"] as? String
                    let slot = result?["slot"] as? String ?? "manual"
                    let destination = path.map { "Saved to \($0)." } ?? "Saved the \(slot) slot."
                    presentStorageFeedback(.saved, title: gameStrings?.saveHouseTitle() ?? "Save House", message: destination)
                } else {
                    if let reason = event["error"] as? String { fputs("Save: \(reason)\n", stderr) }
                    presentStorageFeedback(.saveFailed, title: gameStrings?.saveHouseTitle() ?? "Save House", message: gameStrings?.saveFailedMessage() ?? "An error was encountered saving the house.")
                }
            }
            if event["type"] as? String == "response",
               let id = event["id"] as? String,
               pendingLoadRequests.remove(id) != nil {
                if event["ok"] as? Bool == true {
                    presentStorageFeedback(.loaded, title: gameStrings?.loadHouseTitle() ?? "Load House", message: "Loaded the manual save slot.")
                } else {
                    if let reason = event["error"] as? String { fputs("Load: \(reason)\n", stderr) }
                    presentStorageFeedback(.loadFailed, title: gameStrings?.loadHouseTitle() ?? "Load House", message: gameStrings?.loadFailedMessage() ?? "The house could not be loaded.")
                }
            }
            if event["type"] as? String == "response",
               let id = event["id"] as? String,
               pendingHouseholdAppearanceRequest == id {
                pendingHouseholdAppearanceRequest = nil
                if event["ok"] as? Bool == true,
                   let result = event["result"] as? [String: Any],
                   let data = try? JSONSerialization.data(withJSONObject: result),
                   let catalog = try? JSONDecoder().decode(HouseholdAppearanceCatalog.self, from: data) {
                    renderer?.householdCreation?.setAppearanceCatalog(catalog)
                    if let creation = renderer?.householdCreation,
                       let selection = creation.appearancePreviewSelection() {
                        requestHouseholdAppearancePreview(selection.gender, selection.age, selection.skin,
                                                          selection.headChoice, selection.bodyChoice, creation: creation)
                    }
                } else {
                    renderer?.householdCreation?.failed(event["error"] as? String ?? "Appearance choices could not be loaded.")
                }
                if let view = window?.contentView as? GameMetalView {
                    view.setNeedsDisplay(view.bounds)
                    view.refreshAccessibilityButtons()
                    view.draw()
                }
            }
            if event["type"] as? String == "response",
               let id = event["id"] as? String,
               pendingHouseholdPreviewRequest == id {
                pendingHouseholdPreviewRequest = nil
                do {
                    guard event["ok"] as? Bool == true,
                          let result = event["result"] as? [String: Any],
                          let file = result["file"] as? String,
                          file == "cas-preview/preview.json",
                          let bridge, let renderer else {
                        throw ContentError.invalid(event["error"] as? String ?? "The Sim preview response is invalid")
                    }
                    let session = bridge.session.resolvingSymlinksInPath().standardizedFileURL
                    let previewURL = session.appendingPathComponent(file).resolvingSymlinksInPath().standardizedFileURL
                    guard previewURL.path.hasPrefix(session.path + "/") else {
                        throw ContentError.invalid("The Sim preview file escaped its session directory")
                    }
                    let loaded = try HouseholdAppearancePreview.load(from: previewURL)
                    try renderer.updateHouseholdAppearancePreview(loaded.preview, pixels: loaded.pixels)
                } catch {
                    renderer?.householdCreation?.previewFailed("The Sim preview could not be loaded: \(error.localizedDescription)")
                }
                if let view = window?.contentView as? GameMetalView {
                    view.setNeedsDisplay(view.bounds)
                    view.draw()
                }
            }
            if event["type"] as? String == "response",
               let id = event["id"] as? String,
               pendingHouseholdCreationRequest == id {
                pendingHouseholdCreationRequest = nil
                if event["ok"] as? Bool == true {
                    renderer?.householdCreation = nil
                    renderer?.clearHouseholdAppearancePreview()
                    pendingHouseholdPreviewRequest = nil
                    pendingHouseholdCreation = nil
                    neighborhoodBeforeHouseholdCreation = nil
                    neighborhoodSelectionBeforeHouseholdCreation = nil
                    window?.title = "The Sims — household moved in"
                } else {
                    if let reason = event["error"] as? String { fputs("Household creation: \(reason)\n", stderr) }
                    renderer?.householdCreation?.failed(gameStrings?.moveInErrorMessage() ?? "Could not move in!")
                }
                if let view = window?.contentView as? GameMetalView {
                    view.setNeedsDisplay(view.bounds)
                    view.refreshAccessibilityButtons()
                    view.draw()
                }
            }
            if event["type"] as? String == "response",
               let pending = pendingNeighborhood,
               event["id"] as? String == pending.id {
                pendingNeighborhood = nil
                if event["ok"] as? Bool == true, let bridge, let renderer,
                   let view = window?.contentView as? GameMetalView {
                    do {
                        let manifestURL = bridge.session.appendingPathComponent("neighborhood.json")
                        let neighborhood = try OriginalNeighborhoodOverlay(content: renderer.content, device: renderer.device,
                                                                            manifestURL: manifestURL, session: bridge.session, font: renderer.pieFont)
                        guard neighborhood.mode == pending.mode else { throw ContentError.invalid("Neighborhood export returned the wrong mode") }
                        renderer.gameDialog = nil
                        renderer.neighborhood = neighborhood
                        startNeighborhoodAudio(neighborhood)
                        renderer.neighborhoodHouseSelected = { [weak self] house in self?.respondToNeighborhood(house) }
                        activeNeighborhoodDialog = pending.dialog
                        window?.title = "The Sims — Neighborhood"
                        view.setAccessibilityHelp("Select a house in the neighborhood or press Escape to return home")
                        NSAccessibility.post(element: view, notification: .layoutChanged)
                        view.setNeedsDisplay(view.bounds)
                        view.draw()
                    } catch {
                        failedNeighborhoodTokens.insert(pending.dialog.token)
                        activeNeighborhoodDialog = pending.dialog
                        renderer.gameDialog = nil
                        renderer.neighborhood = nil
                        renderer.neighborhoodHouseSelected = nil
                        showNeighborhoodError(error)
                    }
                } else {
                    let reason = event["error"] as? String ?? "The neighborhood could not be loaded."
                    failedNeighborhoodTokens.insert(pending.dialog.token)
                    activeNeighborhoodDialog = pending.dialog
                    renderer?.neighborhood = nil
                    renderer?.neighborhoodHouseSelected = nil
                    showNeighborhoodError(ContentError.invalid(reason))
                }
            }
            if event["type"] as? String == "response",
               let id = event["id"] as? String,
               pendingNeighborhoodResponse == id {
                pendingNeighborhoodResponse = nil
                if event["ok"] as? Bool == true {
                    activeNeighborhoodDialog = nil
                    renderer?.neighborhood = nil
                    renderer?.neighborhoodHouseSelected = nil
                } else {
                    showNeighborhoodError(ContentError.invalid(event["error"] as? String ?? "The travel selection was rejected."))
                    if let neighborhood = renderer?.neighborhood { startNeighborhoodAudio(neighborhood) }
                    renderer?.neighborhoodHouseSelected = { [weak self] house in self?.respondToNeighborhood(house) }
                }
            }
            if event["type"] as? String == "lotChanged" {
                dismissMenu()
                renderer?.soundOptions.dismiss()
                renderer?.gameDialog = nil
                renderer?.buy.cancelSelection()
                renderer?.buyMode = false
                renderer?.buildMode = false
                renderer?.pan = .zero
                pendingCatalog = nil
                pendingBuildCatalog = nil
                pendingPlacement = nil
                desiredPlacement = nil
                checkedPlacement = nil
                editableObjects = []
                try renderer?.updatePlacement(nil)
            }
            if event["type"] as? String == "response", let pending = pendingPlacement, event["id"] as? String == pending.id {
                pendingPlacement = nil
                checkedPlacement = pending.key
                if desiredPlacement == pending.key, renderer?.objectEditing == true, event["ok"] as? Bool == true,
                   let result = event["result"] as? [String: Any] {
                    let preview = try JSONDecoder().decode(PlacementPreview.self, from: JSONSerialization.data(withJSONObject: result))
                    try renderer?.updatePlacement(preview)
                }
                requestPlacement()
            }
            if event["type"] as? String == "response", event["id"] as? String == pendingBuildCatalog, pendingBuildCatalog != nil {
                pendingBuildCatalog = nil
                if event["ok"] as? Bool == true, renderer?.buildMode == true, let result = event["result"] as? [String: Any] {
                    if let category = renderer?.build.objectTool?.category {
                        let page = try JSONDecoder().decode(BuyCatalogPage.self, from: JSONSerialization.data(withJSONObject: result))
                        guard page.category == category else { return }
                        try renderer?.updateBuildObjects(page)
                    } else {
                        let page = try JSONDecoder().decode(BuildCatalogPage.self, from: JSONSerialization.data(withJSONObject: result))
                        try renderer?.updateBuildCatalog(page)
                    }
                }
            }
            if event["type"] as? String == "response", event["id"] as? String == pendingCatalog, pendingCatalog != nil {
                pendingCatalog = nil
                if event["ok"] as? Bool == true, renderer?.buyMode == true, let result = event["result"] as? [String: Any] {
                    let page = try JSONDecoder().decode(BuyCatalogPage.self, from: JSONSerialization.data(withJSONObject: result))
                    try renderer?.updateCatalog(page)
                }
            }
            if event["type"] as? String == "response", let pending = pendingMenu, event["id"] as? String == pending.id {
                pendingMenu = nil
                if event["ok"] as? Bool == true, selectedSim == pending.caller, let renderer,
                   renderer.containsObject(pending.object), let result = event["result"] as? [[String: Any]] {
                    let entries = try JSONDecoder().decode([SimInteraction].self, from: JSONSerialization.data(withJSONObject: result))
                    if !entries.isEmpty {
                        _ = try? bridge?.send("audioEvent", ["name": "ui_piemenu_appear"])
                        renderer.pieMenu = try OriginalPieOverlay(entries: entries, objectID: pending.object, selectedSim: pending.caller,
                                                                 anchor: pending.anchor, font: renderer.pieFont, device: renderer.device)
                        if let view = window?.contentView { NSAccessibility.post(element: view, notification: .layoutChanged) }
                    }
                }
            }
            if event["type"] as? String == "hello" {
                simulationLanguageCode = event["languageCode"] as? Int
                _ = try bridge?.send("audio", ["enabled": audio != nil])
                _ = try bridge?.send("stream", ["enabled": true])
                requestAudioState()
            }
            if event["type"] as? String == "audioError" { fputs("Audio: \(event["error"] ?? "Unknown sound error")\n", stderr) }
            if event["type"] as? String == "response", let id = event["id"] as? String {
                if let pending = pendingOutfitChoices, pending.id == id {
                    pendingOutfitChoices = nil
                    finishOpeningOutfitPicker(event, dialog: pending.dialog)
                } else if pendingOutfitPreview == id {
                    pendingOutfitPreview = nil
                    finishOutfitPreview(event)
                }
            }
            if event["type"] as? String == "response", let id = event["id"] as? String, let moveIn = pendingFamilyMoveIn, moveIn.request == id {
                pendingFamilyMoveIn = nil
                if event["ok"] as? Bool == true {
                    neighborhoodBeforeHouseholdCreation = nil
                    neighborhoodSelectionBeforeHouseholdCreation = nil
                    window?.title = "The Sims — household moved in"
                } else {
                    if let reason = event["error"] as? String { fputs("Move in: \(reason)\n", stderr) }
                    cancelHouseholdCreation()
                    presentStorageFeedback(.neighborhood, title: gameStrings?.moveInErrorTitle() ?? "Error!", message: gameStrings?.moveInErrorMessage() ?? "Could not move in!")
                }
            }
            if event["type"] as? String == "response", let id = event["id"] as? String, let sounds = pendingResponseSounds.removeValue(forKey: id) {
                if event["ok"] as? Bool == true { playUISound(sounds.success) } else if let failure = sounds.failure { playUISound(failure) }
            }
            if event["type"] as? String == "pluginPanels", let panels = event["panels"] as? [[String: Any]] { applyPluginPanelValues(panels) }
            if event["type"] as? String == "response", let result = event["result"] as? [String: Any],
               let panels = result["panels"] as? [[String: Any]], panels.allSatisfy({ $0["values"] != nil }) {
                applyPluginPanelValues(panels)
            }
            if event["type"] as? String == "plugin", let packID = event["packId"] as? String, let state = event["state"] as? String {
                fputs("Plugin \(packID): \(state)\(event["reason"].map { " — \($0)" } ?? "")\n", stderr)
                if state == "failed", renderer?.pluginPanel?.packID == packID { renderer?.pluginPanel = nil }
            }
            if event["type"] as? String == "saveMigrated" {
                let upgraded = (event["upgraded"] as? [String] ?? []).joined(separator: ", ")
                fputs("Save migrated: \(upgraded); backup \(event["backup"] ?? "none")\n", stderr)
                if let view = window?.contentView {
                    NSAccessibility.post(element: view, notification: .announcementRequested,
                                         userInfo: [.announcement: "The save was upgraded for newer packs. A backup was kept."])
                }
            }
            if event["type"] as? String == "audio" {
                try audio?.receive(JSONDecoder().decode(AudioEvent.self, from: JSONSerialization.data(withJSONObject: event)))
            }
            if let scene = event["scene"] as? String {
                let revision = (event["revision"] as? NSNumber)?.int64Value ?? 0
                try renderer?.loadScene(URL(fileURLWithPath: scene), revision: revision)
                audio?.updateSpatial()
                if let pointer, let view = window?.contentView as? MTKView { updatePlacement(pointer, canvas: view.drawableSize) }
                if revision > 0 { _ = try bridge?.send("sceneAck", ["revision": revision]) }
            }
            if event["type"] as? String == "animation", let frame = event["frame"] as? [String: Any] {
                let animation = try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: frame))
                try renderer?.applyAnimation(animation)
                audio?.updateSpatial()
            }
            let state = event["state"] as? [String: Any] ?? event["result"] as? [String: Any]
            if let state, let speed = state["speed"] as? Int {
                if let lot = pendingHouseholdCreation,
                   (state["house"] as? Int) == lot,
                   let sims = state["sims"] as? [[String: Any]],
                   !sims.contains(where: { $0["household"] as? Bool == true }),
                   renderer?.householdCreation == nil,
                   let renderer {
                    renderer.householdCreation = try OriginalHouseholdCreationOverlay(content: renderer.content, device: renderer.device)
                    renderer.householdCreation?.playSound = { [weak self] name in self?.playUISound(name) }
                    window?.title = "The Sims — create your family"
                    window?.contentView?.setAccessibilityHelp("Create a family and one or more Sims, then choose Move In")
                    if let view = window?.contentView as? GameMetalView { view.refreshAccessibilityButtons() }
                }
                if let moveIn = pendingFamilyMoveIn, moveIn.request == nil,
                   (state["house"] as? Int) == moveIn.house,
                   let sims = state["sims"] as? [[String: Any]],
                   !sims.contains(where: { $0["household"] as? Bool == true }),
                   let bridge {
                    pendingFamilyMoveIn?.request = try bridge.send("moveInFamily", ["family": moveIn.family])
                }
                if let values = state["dialogs"] as? [[String: Any]], let renderer {
                    let pending = try JSONDecoder().decode([GameDialog].self, from: JSONSerialization.data(withJSONObject: values))
                    if let travelDialog = pending.first(where: { OriginalNeighborhoodOverlay.mode(forDialogKind: $0.kind) != nil }),
                       let mode = OriginalNeighborhoodOverlay.mode(forDialogKind: travelDialog.kind) {
                        renderer.gameDialog = nil
                        if activeNeighborhoodDialog?.token != travelDialog.token,
                           pendingNeighborhood?.dialog.token != travelDialog.token,
                           !failedNeighborhoodTokens.contains(travelDialog.token) {
                            loadTravelNeighborhood(travelDialog, mode: mode)
                        }
                    } else if let first = pending.first, first.kind == 6 || first.kind == 9 {
                        // Wardrobe and pet choice are carousels owned by the picker overlay, not generic dialogs.
                        renderer.gameDialog = nil
                        if renderer.outfitPicker?.token != first.token && pendingOutfitChoices?.dialog.token != first.token { openOutfitPicker(first) }
                    } else if let first = pending.first {
                        dismissMenu()
                        renderer.soundOptions.dismiss()
                        if renderer.gameDialog?.dialog.token != first.token {
                            renderer.gameDialog = try OriginalDialogOverlay(dialog: first, font: renderer.pieFont, device: renderer.device, content: renderer.content)
                            if let view = window?.contentView { NSAccessibility.post(element: view, notification: .layoutChanged) }
                        }
                    } else {
                        renderer.gameDialog = nil
                        if renderer.outfitPicker != nil { renderer.outfitPicker = nil; renderer.clearHouseholdAppearancePreview() }
                    }
                }
                if let objects = state["objects"] as? [[String: Any]] {
                    editableObjects = try JSONDecoder().decode([EditableLotObject].self, from: JSONSerialization.data(withJSONObject: objects))
                    renderer?.buy.selection.reconcile(objects: editableObjects)
                }
                renderer?.speed = speed
                if let pointer, let view = window?.contentView as? MTKView { updatePlacement(pointer, canvas: view.drawableSize) }
                renderer?.wallsUp = state["wallsUp"] as? Bool ?? false
                renderer?.wallMode = state["wallMode"] as? String ?? ((renderer?.wallsUp ?? false) ? "up" : "down")
                renderer?.roofPitch = (state["roofPitch"] as? NSNumber)?.floatValue ?? 0.66
                if let style = (state["roofStyle"] as? NSNumber)?.uint16Value {
                    renderer?.roofStyle = style
                    if renderer?.build.kind == .roof { renderer?.build.choose(style) }
                }
                let panelState = try JSONDecoder().decode(GameplayPanelState.self, from: JSONSerialization.data(withJSONObject: state))
                try renderer?.updateGameplay(panelState)
                selectedSim = state["selectedSim"] as? Int ?? 0
                if let menu = renderer?.pieMenu, menu.selectedSim != selectedSim || renderer?.containsObject(menu.objectID) != true { dismissMenu() }
                let sims = state["sims"] as? [[String: Any]] ?? []
                simIDs = sims.filter { $0["household"] as? Bool == true }.compactMap { $0["id"] as? Int }
                let name = sims.first { $0["id"] as? Int == selectedSim }?["name"] as? String ?? ""
                let actions = sims.first { $0["id"] as? Int == selectedSim }?["actions"] as? [[String: Any]] ?? []
                window?.contentView?.setAccessibilityHelp("Selected Sim: \(name). Actions: \(actions.compactMap { $0["name"] as? String }.joined(separator: ", "))")
                if let dialog = renderer?.gameDialog {
                    window?.contentView?.setAccessibilityHelp("\(dialog.dialog.title). \(dialog.dialog.message). \(dialog.dialog.buttons.map(\.label).joined(separator: ", "))")
                }
                let hour = state["hours"] as? Int ?? 0
                let minute = state["minutes"] as? Int ?? 0
                if renderer?.householdCreation == nil {
                    window?.title = String(format: "The Sims — native lot %d · %@ · %02d:%02d%@", state["house"] as? Int ?? liveHouse ?? 0, name, hour, minute, speed == 0 ? " · paused" : speed == -2 ? " · awaiting response" : "")
                } else {
                    window?.contentView?.setAccessibilityHelp("Create a family and one or more Sims, then choose Move In")
                }
                if let view = window?.contentView as? MTKView {
                    view.setNeedsDisplay(view.bounds)
                    view.draw()
                }
            }
            if event["ok"] as? Bool == false { renderer?.gameDialog?.submitting = false; fputs("Simulation: \(event["error"] ?? "Unknown error")\n", stderr) }
        } catch { fputs("\(error)\n", stderr) }
    }

    /// Successful saves and loads are silent, as in the original game; the outcome is still announced to accessibility clients.
    private func presentStorageFeedback(_ kind: StorageFeedbackKind, title: String, message: String) {
        if let storageFeedbackHandler {
            storageFeedbackHandler(kind.rawValue, message)
            return
        }
        if !kind.showsDialog {
            if let view = window?.contentView { NSAccessibility.post(element: view, notification: .announcementRequested, userInfo: [.announcement: title]) }
            return
        }
        if let renderer, renderer.gameDialog == nil, let view = window?.contentView as? GameMetalView {
            let token = "native-storage-" + UUID().uuidString
            do {
                let dialog = GameDialog.localFeedback(token: token, title: title, message: message,
                                                      ok: gameStrings?.okButton() ?? "OK")
                renderer.soundOptions.dismiss()
                renderer.gameDialog = try OriginalDialogOverlay(dialog: dialog, font: renderer.pieFont,
                                                                device: renderer.device, content: renderer.content)
                localDialogToken = token
                localDialogResponse = nil
                view.setAccessibilityHelp("\(title). \(message). \(gameStrings?.okButton() ?? "OK")")
                view.setNeedsDisplay(view.bounds)
                view.refreshAccessibilityButtons()
                view.draw()
                return
            } catch { fputs("Storage dialog: \(error)\n", stderr) }
        }
        let alert = NSAlert()
        alert.alertStyle = kind.isFailure ? .warning : .informational
        alert.messageText = title
        alert.informativeText = message
        if let window {
            alert.beginSheetModal(for: window)
        } else {
            alert.runModal()
        }
    }

    /// A three-choice local prompt: response 0 is the first button, 1 the second and 2 Cancel.
    private func presentLocalPrompt(title: String, message: String, yes: String, no: String, cancel: String,
                                    response: @escaping (UInt8) -> Void) {
        presentLocalConfirmation(title: title, message: message, yes: yes, no: no, cancel: cancel, response: response)
    }

    private func presentLocalConfirmation(title: String, message: String, yes: String, no: String, cancel: String? = nil,
                                           response: @escaping (UInt8) -> Void) {
        guard let renderer, renderer.gameDialog == nil, let view = window?.contentView as? GameMetalView else {
            presentStorageFeedback(.dialogFailed, title: title, message: "The original-style dialog could not be displayed.")
            return
        }
        let token = "native-storage-" + UUID().uuidString
        do {
            let dialog = GameDialog.localPrompt(token: token, title: title, message: message,
                                                kind: cancel == nil ? 1 : 2, yes: yes, no: no, cancel: cancel)
            renderer.soundOptions.dismiss()
            renderer.gameDialog = try OriginalDialogOverlay(dialog: dialog, font: renderer.pieFont,
                                                            device: renderer.device, content: renderer.content)
            localDialogToken = token
            localDialogResponse = response
            view.setAccessibilityHelp("\(title). \(message). \(yes), \(no)" + (cancel.map { ", \($0)" } ?? ""))
            view.setNeedsDisplay(view.bounds)
            view.refreshAccessibilityButtons()
            view.draw()
        } catch {
            presentStorageFeedback(.dialogFailed, title: title, message: error.localizedDescription)
        }
    }

    private func confirmLocalConfirmation() throws {
        guard let dialog = renderer?.gameDialog, localDialogToken == dialog.dialog.token,
              let confirm = dialog.dialog.buttons.first(where: { $0.code == 0 }) else {
            throw ContentError.invalid("The original-style confirmation dialog did not open")
        }
        try respondDialog(dialog, code: confirm.code)
    }

    func storageMenuSaveTitle() -> String { gameStrings?.saveMenuTitle() ?? "Save" }
    func storageMenuLoadTitle() -> String { gameStrings?.loadMenuTitle() ?? "Load" }

    /// Lists every pack-declared panel at the end of the Simulation menu.
    private func refreshPluginPanelMenu(content: GameContent) {
        guard let simulation = NSApp.mainMenu?.items.first(where: { $0.submenu?.items.contains { $0.action == #selector(AppDelegate.saveGame(_:)) } == true })?.submenu else { return }
        for item in simulation.items where item.action == #selector(AppDelegate.openPluginPanel(_:)) || item.tag == Self.pluginMenuSeparatorTag {
            simulation.removeItem(item)
        }
        let panels = content.packs.panelDescriptions().sorted { $0.key < $1.key }
        guard !panels.isEmpty else { return }
        let separator = NSMenuItem.separator()
        separator.tag = Self.pluginMenuSeparatorTag
        simulation.addItem(separator)
        for (packID, descriptions) in panels {
            for (panelID, description) in descriptions.sorted(by: { $0.key < $1.key }) {
                let item = simulation.addItem(withTitle: description.title + "…", action: #selector(AppDelegate.openPluginPanel(_:)), keyEquivalent: "")
                item.target = self
                item.representedObject = [packID, panelID]
            }
        }
    }

    private static let pluginMenuSeparatorTag = 0x5049

    @objc func openPluginPanel(_ sender: Any?) {
        guard let renderer, renderer.gameDialog == nil, let content = currentContent,
              let identifiers = (sender as? NSMenuItem)?.representedObject as? [String], identifiers.count == 2,
              let description = content.packs.panelDescriptions()[identifiers[0]]?[identifiers[1]] else { return }
        dismissMenu()
        renderer.soundOptions.dismiss()
        do {
            let panel = try OriginalPluginPanelOverlay(packID: identifiers[0], description: description, content: content,
                                                       font: renderer.pieFont, device: renderer.device, closeLabel: gameStrings?.okButton() ?? "OK")
            panel.update(values: pluginPanelValues[identifiers[0]]?[identifiers[1]] ?? [:])
            renderer.pluginPanel = panel
            _ = try? bridge?.send("pluginPanels")
        } catch {
            fputs("Plugin panel: \(error)\n", stderr)
            return
        }
        if let view = window?.contentView as? GameMetalView {
            view.setAccessibilityHelp(description.title)
            view.setNeedsDisplay(view.bounds)
            view.refreshAccessibilityButtons()
            view.draw()
        }
    }

    private func applyPluginPanelValues(_ panels: [[String: Any]]) {
        var updated: [String: [String: [String: String]]] = [:]
        for panel in panels {
            guard let packID = panel["packId"] as? String, let panelID = panel["panelId"] as? String,
                  let values = panel["values"] as? [String: String] else { continue }
            updated[packID, default: [:]][panelID] = values
        }
        pluginPanelValues = updated
        if let panel = renderer?.pluginPanel {
            panel.update(values: updated[panel.packID]?[panel.description.id] ?? [:])
            if let view = window?.contentView as? GameMetalView {
                view.setNeedsDisplay(view.bounds)
                view.refreshAccessibilityButtons()
            }
        }
    }

    /// Asks once per launch, outside the original-game UI, before any untrusted plugin may run.
    /// "Keep Disabled" is the default; trust applies only to the exact files that were reviewed.
    private func reviewPluginTrust(content: GameContent) {
        guard storageFeedbackHandler == nil, let plugins = try? content.packs.pluginReports(), !plugins.isEmpty,
              var store = try? PluginTrustStore(dataRoot: dataRoot) else { return }
        for plugin in plugins where !store.isTrusted(plugin) {
            let name = content.packs.ordered.first { $0.manifest.id == plugin.packID }?.manifest.name ?? plugin.packID
            let alert = NSAlert()
            alert.alertStyle = .warning
            alert.messageText = "Allow “\(name)” to run code?"
            alert.informativeText = "The pack \(plugin.packID) \(plugin.version) includes a gameplay plugin that runs with your user account's permissions. Only allow packs from authors you trust.\n\nFiles digest: \(plugin.sha256)"
            alert.addButton(withTitle: "Keep Disabled")
            alert.addButton(withTitle: "Allow")
            if alert.runModal() == .alertSecondButtonReturn {
                do { try store.trust(plugin) } catch { fputs("Plugin trust: \(error)\n", stderr) }
            }
        }
    }

    private func refreshLocalizedStorageMenuTitles() {
        guard let menu = NSApp.mainMenu else { return }
        for parent in menu.items {
            guard let submenu = parent.submenu else { continue }
            for item in submenu.items {
                if item.action == #selector(AppDelegate.saveGame(_:)) { item.title = storageMenuSaveTitle() }
                else if item.action == #selector(AppDelegate.loadGame(_:)) { item.title = storageMenuLoadTitle() }
                else if item.action == #selector(AppDelegate.openSoundOptions(_:)) { item.title = soundOptionsMenuTitle() }
            }
        }
    }

    func checkStorageMenuFlow(content: GameContent, house: Int) throws -> [String: Any] {
        currentContent = content
        gameStrings = OriginalUIStrings(content: content)
        guard let device = MTLCreateSystemDefaultDevice() else { throw ContentError.invalid("Metal is unavailable") }
        let renderer = try OriginalUIRenderer(content: content, device: device, sceneURL: nil)
        let view = GameMetalView(frame: NSRect(x: 0, y: 0, width: 800, height: 600), device: device)
        view.drawableSize = CGSize(width: 800, height: 600)
        let window = NSWindow(contentRect: NSRect(x: 0, y: 0, width: 800, height: 600), styleMask: .borderless, backing: .buffered, defer: false)
        window.contentView = view
        self.window = window
        self.renderer = renderer
        let feedback = StorageMenuFeedback()
        storageFeedbackHandler = { title, message in feedback.values[title] = message }
        let bridge = SimulationBridge(workspace: workspace, dataRoot: dataRoot)
        bridge.event = { [weak self] event in
            if event["type"] as? String == "hello" { feedback.values["Simulation ready"] = "ready" }
            self?.simulationEvent(event)
        }
        bridge.failed = { error in feedback.values["Simulation failed"] = error }
        self.bridge = bridge
        defer {
            storageFeedbackHandler = nil
            if bridge.process.isRunning {
                bridge.stop(save: false)
                bridge.process.waitUntilExit()
            }
            if self.bridge === bridge { self.bridge = nil }
        }
        try bridge.start(content: content, house: house)
        guard waitForStorageFeedback("Simulation ready", feedback: feedback) else {
            throw ContentError.invalid(feedback.values["Simulation failed"] ?? "The simulation did not become ready")
        }
        let menu = simulationMenu(target: self)
        guard let saveIndex = menu.items.firstIndex(where: { $0.action == #selector(AppDelegate.saveGame(_:)) }),
              let loadIndex = menu.items.firstIndex(where: { $0.action == #selector(AppDelegate.loadGame(_:)) }),
              menu.items[saveIndex].isEnabled, menu.items[loadIndex].isEnabled,
              menu.items[saveIndex].action == #selector(AppDelegate.saveGame(_:)),
              menu.items[loadIndex].action == #selector(AppDelegate.loadGame(_:)) else {
            throw ContentError.invalid("The Simulation menu does not expose enabled Save and Load actions")
        }
        let saveItem = menu.items[saveIndex]
        guard let saveAction = saveItem.action,
              NSApp.sendAction(saveAction, to: saveItem.target, from: saveItem) else {
            throw ContentError.invalid("AppKit did not dispatch the Save menu action")
        }
        try confirmLocalConfirmation()
        guard waitForStorageFeedback("Game saved", feedback: feedback) else {
            throw ContentError.invalid(feedback.values["Save failed"] ?? feedback.values["Simulation failed"] ?? "The Save menu action did not receive a response")
        }
        let savePath = dataRoot.appendingPathComponent("runtime/native-profiles/\(activeProfileID)/Saves/manual.json")
        guard FileManager.default.fileExists(atPath: savePath.path) else {
            throw ContentError.invalid("The Save menu action returned without creating the manual profile slot")
        }
        let loadItem = menu.items[loadIndex]
        guard let loadAction = loadItem.action,
              NSApp.sendAction(loadAction, to: loadItem.target, from: loadItem) else {
            throw ContentError.invalid("AppKit did not dispatch the Load menu action")
        }
        try confirmLocalConfirmation()
        guard waitForStorageFeedback("Game loaded", feedback: feedback) else {
            throw ContentError.invalid(feedback.values["Load failed"] ?? feedback.values["Simulation failed"] ?? "The Load menu action did not receive a response")
        }
        bridge.stop(save: false)
        bridge.process.waitUntilExit()
        return ["result": "passed", "saveMenuAction": true, "saveFeedback": feedback.values["Game saved"] ?? "",
                "manualProfileSlot": savePath.path, "loadMenuAction": true, "loadFeedback": feedback.values["Game loaded"] ?? ""]
    }

    func checkNewGameInputFlow(content: GameContent) throws -> [String: Any] {
        currentContent = content
        gameStrings = OriginalUIStrings(content: content)
        guard let device = MTLCreateSystemDefaultDevice() else { throw ContentError.invalid("Metal is unavailable") }
        let renderer = try OriginalUIRenderer(content: content, device: device, sceneURL: nil)
        let view = GameMetalView(frame: NSRect(x: 0, y: 0, width: 800, height: 600), device: device)
        view.drawableSize = CGSize(width: 800, height: 600)
        let window = NSWindow(contentRect: NSRect(x: 0, y: 0, width: 800, height: 600), styleMask: .borderless, backing: .buffered, defer: false)
        window.contentView = view
        self.window = window
        self.renderer = renderer
        var submittedRequest: HouseholdCreationRequest?
        var headPreviewWasRendered = false
        var outfitPreviewWasRendered = false
        view.clicked = { [weak self, weak view] point in
            guard let self, let view else { return }
            self.clickGame(point, canvas: view.drawableSize, householdCreationRequestObserved: { submittedRequest = $0 })
        }
        view.menuAccessibility = { [weak renderer, weak view] in
            guard let renderer, let view else { return [] }
            return renderer.householdCreation?.controls(canvas: view.bounds.size) ?? renderer.familyPicker?.controls(canvas: view.bounds.size)
                ?? renderer.neighborhood?.controls(canvas: view.bounds.size) ?? []
        }
        view.gameplayAccessibility = { [] }
        view.dialogKey = { [weak renderer] key in renderer?.householdCreation?.key(key) ?? false }
        defer {
            storageFeedbackHandler = nil
            if let bridge = self.bridge, bridge.process.isRunning {
                bridge.stop(save: false)
                bridge.process.waitUntilExit()
            }
            self.bridge = nil
            self.audio?.stop()
            self.audio = nil
            self.pendingHouseholdCreation = nil
            self.pendingHouseholdCreationRequest = nil
            self.pendingHouseholdAppearanceRequest = nil
            self.pendingHouseholdPreviewRequest = nil
            self.simulationLanguageCode = nil
            self.window?.close()
            self.window = nil
            self.renderer = nil
        }

        func waitUntil(_ description: String, _ predicate: () -> Bool) throws {
            let deadline = Date(timeIntervalSinceNow: 45)
            while !predicate() && Date() < deadline {
                RunLoop.current.run(until: Date(timeIntervalSinceNow: 0.02))
            }
            guard predicate() else { throw ContentError.invalid("Timed out waiting for \(description)") }
        }

        func currentControls() -> [(label: String, rect: CGRect)] {
            renderer.householdCreation?.controls(canvas: view.bounds.size) ?? renderer.familyPicker?.controls(canvas: view.bounds.size)
                ?? renderer.neighborhood?.controls(canvas: view.bounds.size) ?? []
        }

        func pressControl(_ predicate: (String) -> Bool) throws {
            let controls = currentControls()
            guard let index = controls.firstIndex(where: { predicate($0.label) }) else {
                throw ContentError.invalid("Native input could not find a matching screen control")
            }
            view.refreshAccessibilityButtons()
            guard let children = view.accessibilityChildren(), index < children.count,
                  let button = children[index] as? GameActionButton,
                  button.accessibilityPerformPress() else {
                throw ContentError.invalid("AppKit did not dispatch the screen control")
            }
        }

        func type(_ value: String) throws {
            guard let event = NSEvent.keyEvent(with: .keyDown, location: .zero, modifierFlags: [],
                                               timestamp: ProcessInfo.processInfo.systemUptime, windowNumber: window.windowNumber,
                                               context: nil, characters: value, charactersIgnoringModifiers: value,
                                               isARepeat: false, keyCode: 0) else {
                throw ContentError.invalid("Could not create a scripted keyboard event")
            }
            view.keyDown(with: event)
        }

        let exported = try NeighborhoodExport.createSynchronously(content: content, workspace: workspace, dataRoot: dataRoot, mode: 1)
        var neighborhood = try OriginalNeighborhoodOverlay(content: content, device: device, manifestURL: exported.manifest, session: exported.session)
        renderer.neighborhood = neighborhood
        var selectedHouse: Int?
        renderer.neighborhoodHouseSelected = { [weak self, weak renderer] lot in
            selectedHouse = lot
            guard let self, let neighborhood = renderer?.neighborhood else { return }
            let canCreate = neighborhood.canCreateHousehold(at: lot)
            if neighborhood.isVacantResidential(at: lot) && !canCreate { return }
            self.openNeighborhoodHouse(lot, createHousehold: canCreate, content: content, audioEnabled: false)
        }
        let importedHouse = 5
        let importedControls = neighborhood.controls(canvas: view.bounds.size)
        for control in importedControls {
            guard let expectedHouse = Int(control.label.split(separator: " ").last ?? ""),
                  neighborhood.house(at: CGPoint(x: control.rect.midX, y: control.rect.midY), canvas: view.bounds.size) == expectedHouse else {
                throw ContentError.invalid("A neighborhood house control resolves to another lot at its center: \(control.label)")
            }
        }
        let importedControl = importedControls.first(where: { $0.label == "Open house \(importedHouse)" })
        let importedHit = importedControl.flatMap {
            neighborhood.house(at: CGPoint(x: $0.rect.midX, y: $0.rect.midY), canvas: view.bounds.size)
        }
        guard let importedControl, importedHit == importedHouse, !neighborhood.canCreateHousehold(at: importedHouse) else {
            let label = importedControl?.label ?? "is missing"
            throw ContentError.invalid("Occupied lot \(importedHouse) control \(label) resolves to hit target \(String(describing: importedHit)); creation=\(neighborhood.canCreateHousehold(at: importedHouse))")
        }
        try pressControl { $0 == importedControl.label }
        try waitUntil("the imported household on its selected lot") { !self.simIDs.isEmpty }
        let importedHouseholdSims = simIDs.count
        guard simulationLanguageCode == content.language.code, pendingHouseholdCreation == nil,
              renderer.householdCreation == nil, bridge != nil else {
            throw ContentError.invalid("Selecting the installed household did not start its lot with the detected language")
        }
        if let bridge = self.bridge {
            bridge.event = nil
            bridge.stop(save: false)
            bridge.process.waitUntilExit()
        }
        self.bridge = nil
        simIDs = []
        selectedHouse = nil
        renderer.liveMode = false
        renderer.neighborhood = neighborhood
        renderer.neighborhoodHouseSelected = { [weak self, weak renderer] lot in
            selectedHouse = lot
            guard let self, let neighborhood = renderer?.neighborhood else { return }
            let canCreate = neighborhood.canCreateHousehold(at: lot)
            if neighborhood.isVacantResidential(at: lot) && !canCreate { return }
            self.openNeighborhoodHouse(lot, createHousehold: canCreate, content: content, audioEnabled: false)
        }
        let sourceNeighborhood = try Data(contentsOf: content.root.appendingPathComponent("UserData/Neighborhood.iff"))
        let importedProfileID = try importOriginalSaveFromFolderSynchronously(content.root.appendingPathComponent("UserData", isDirectory: true), content: content)
        let relaunchedDelegate = AppDelegate(loadContent: { content }, sceneURL: nil, workspace: workspace, dataRoot: dataRoot, liveHouse: nil, showsNeighborhood: true,
                                              gameRoot: gameRoot)
        guard importedProfileID == activeProfileID,
              relaunchedDelegate.activeProfileID == importedProfileID,
              try String(contentsOf: dataRoot.appendingPathComponent("runtime/native-profiles/active-profile.txt"), encoding: .utf8) == importedProfileID,
              try Data(contentsOf: content.root.appendingPathComponent("UserData/Neighborhood.iff")) == sourceNeighborhood,
              let importedNeighborhood = renderer.neighborhood else {
            throw ContentError.invalid("Original save import did not activate a separate profile while preserving the installed source")
        }
        neighborhood = importedNeighborhood
        renderer.neighborhoodHouseSelected = { [weak self, weak renderer] lot in
            selectedHouse = lot
            guard let self, let neighborhood = renderer?.neighborhood else { return }
            let canCreate = neighborhood.canCreateHousehold(at: lot)
            if neighborhood.isVacantResidential(at: lot) && !canCreate { return }
            self.openNeighborhoodHouse(lot, createHousehold: canCreate, content: content, audioEnabled: false)
        }
        let neighborhoodControls = neighborhood.controls(canvas: view.bounds.size)
        guard let createIndex = neighborhoodControls.firstIndex(where: { $0.label.hasPrefix("Create a household on vacant lot") }),
              let selectedLabelHouse = Int(neighborhoodControls[createIndex].label.split(separator: " ").last ?? ""),
              let selectedCenterHouse = neighborhood.house(at: CGPoint(x: neighborhoodControls[createIndex].rect.midX,
                                                                        y: neighborhoodControls[createIndex].rect.midY), canvas: view.bounds.size),
              neighborhood.canCreateHousehold(at: selectedCenterHouse) else {
            throw ContentError.invalid("No affordable vacant home has a usable native neighborhood hit target")
        }
        guard selectedCenterHouse == selectedLabelHouse else {
            throw ContentError.invalid("Neighborhood accessibility hit target does not match its vacant-lot label")
        }
        // The original Select a Family screen: Create/Cancel are enabled, Move In needs a family, Cancel restores the map.
        openFamilyPicker(house: selectedCenterHouse, families: neighborhood.families, content: content)
        guard let picker = renderer.familyPicker else { throw ContentError.invalid("The Select a Family screen did not open for a vacant lot") }
        let pickerLabels = picker.controls(canvas: view.bounds.size).map(\.label)
        let createLabel = gameStrings?.pickFamily(2, fallback: "Create New Family") ?? "Create New Family"
        let cancelLabel = gameStrings?.pickFamily(5, fallback: "Cancel") ?? "Cancel"
        let moveInLabel = gameStrings?.pickFamily(3, fallback: "Move In Family") ?? "Move In Family"
        guard pickerLabels.contains(createLabel), pickerLabels.contains(cancelLabel),
              pickerLabels.contains(moveInLabel) == !neighborhood.families.isEmpty else {
            throw ContentError.invalid("The Select a Family screen does not expose its original controls: \(pickerLabels)")
        }
        try pressControl { $0 == cancelLabel }
        guard renderer.familyPicker == nil, renderer.neighborhood != nil else {
            throw ContentError.invalid("Cancel did not close the Select a Family screen")
        }
        let familyPickerFamilies = neighborhood.families.count
        try pressControl { $0 == neighborhoodControls[createIndex].label }
        guard selectedHouse == selectedCenterHouse, pendingHouseholdCreation == selectedCenterHouse else {
            throw ContentError.invalid("The native neighborhood control did not enter its selected vacant lot")
        }
        try waitUntil("the family screen") { renderer.householdCreation != nil }
        guard let creation = renderer.householdCreation else { throw ContentError.invalid("The native family screen did not open") }
        guard simulationLanguageCode == content.language.code else {
            throw ContentError.invalid("The simulation did not use the installed game's detected language")
        }

        try pressControl { $0 == creation.controlLabel("addSim") }
        try waitUntil("the installed appearance catalog") { creation.appearancePreviewSelection() != nil }
        try pressControl { $0 == creation.controlLabel("female") }
        try waitUntil("the female appearance catalog") { creation.appearancePreviewSelection()?.gender == "f" }
        guard let initialAppearance = creation.appearancePreviewSelection() else { throw ContentError.invalid("The female appearance catalog has no valid choices") }
        try pressControl { $0 == creation.controlLabel("nextHead") }
        try waitUntil("the selected head preview") {
            headPreviewWasRendered = renderer.hasHouseholdAppearancePreview
            return headPreviewWasRendered
        }
        guard let selectedHead = creation.appearancePreviewSelection(), selectedHead.headChoice != initialAppearance.headChoice else {
            throw ContentError.invalid("The Create-a-Sim head control did not change the selected original resource")
        }
        try pressControl { $0 == creation.controlLabel("nextBody") }
        try waitUntil("the selected outfit preview") {
            outfitPreviewWasRendered = renderer.hasHouseholdAppearancePreview
            return outfitPreviewWasRendered
        }
        guard let selectedAppearance = creation.appearancePreviewSelection(), selectedAppearance.bodyChoice != initialAppearance.bodyChoice else {
            throw ContentError.invalid("The Create-a-Sim outfit control did not change the selected original resource")
        }
        try pressControl { $0 == creation.controlLabel("simName") }
        try type("Ada")
        try pressControl { $0 == creation.controlLabel("biography") }
        try type("Architect")
        guard let personalityRect = currentControls().first(where: { $0.label == creation.controlLabel("personality") })?.rect else {
            throw ContentError.invalid("Create-a-Sim personality control is unavailable")
        }
        view.clicked?(CGPoint(x: personalityRect.minX + 20, y: personalityRect.minY + 24))
        try pressControl { $0 == creation.controlLabel("simDone") }

        try pressControl { $0 == creation.controlLabel("addSim") }
        try waitUntil("the child appearance catalog") { creation.appearancePreviewSelection() != nil }
        try pressControl { $0 == creation.controlLabel("child") }
        try waitUntil("the child-specific appearance catalog") { creation.appearancePreviewSelection()?.age == "child" }
        try pressControl { $0 == creation.controlLabel("simName") }
        try type("Milo")
        try pressControl { $0 == creation.controlLabel("simDone") }
        try pressControl { $0 == creation.controlLabel("familyName") }
        try type("Palm")
        let feedback = StorageMenuFeedback()
        storageFeedbackHandler = { title, message in feedback.values[title] = message }
        try pressControl { $0 == creation.controlLabel("familyDone") }
        try confirmLocalConfirmation()
        guard let submittedRequest else { throw ContentError.invalid("The native family screen did not submit a household request") }
        try submittedRequest.validate()
        guard submittedRequest.familyName == "Palm", submittedRequest.members.count == 2,
              submittedRequest.members[0].name == "Ada", submittedRequest.members[0].bio == "Architect",
              submittedRequest.members[0].code.first == "f", submittedRequest.members[0].code.dropFirst().first == "a",
              submittedRequest.members[0].headChoice == selectedAppearance.headChoice,
              submittedRequest.members[0].bodyChoice == selectedAppearance.bodyChoice,
              submittedRequest.members[0].personality == [600, 400, 500, 500, 500],
              submittedRequest.members[1].name == "Milo", submittedRequest.members[1].code.dropFirst().first == "c" else {
            throw ContentError.invalid("Native family and Create-a-Sim input did not preserve the entered household data")
        }
        try waitUntil("the simulation's household creation response") { renderer.householdCreation == nil }
        guard bridge != nil else { throw ContentError.invalid("The lot simulation stopped before the new household could be saved") }
        let menu = simulationMenu(target: self)
        guard let saveItem = menu.items.first(where: { $0.action == #selector(AppDelegate.saveGame(_:)) }), let saveAction = saveItem.action,
              NSApp.sendAction(saveAction, to: saveItem.target, from: saveItem) else {
            throw ContentError.invalid(feedback.values["Save failed"] ?? "The new household did not save through the Simulation menu")
        }
        try confirmLocalConfirmation()
        guard waitForStorageFeedback("Game saved", feedback: feedback) else {
            throw ContentError.invalid(feedback.values["Save failed"] ?? "The new household did not save through the Simulation menu")
        }
        let savePath = dataRoot.appendingPathComponent("runtime/native-profiles/\(activeProfileID)/Saves/manual.json")
        guard FileManager.default.fileExists(atPath: savePath.path),
              let loadItem = menu.items.first(where: { $0.action == #selector(AppDelegate.loadGame(_:)) }), let loadAction = loadItem.action,
              NSApp.sendAction(loadAction, to: loadItem.target, from: loadItem) else {
            throw ContentError.invalid(feedback.values["Load failed"] ?? "The saved household did not reload through the Simulation menu")
        }
        try confirmLocalConfirmation()
        guard waitForStorageFeedback("Game loaded", feedback: feedback) else {
            throw ContentError.invalid(feedback.values["Load failed"] ?? "The saved household did not reload through the Simulation menu")
        }
        try waitUntil("the restored household state") { self.simIDs.count == 2 }
        if let bridge = self.bridge, bridge.process.isRunning {
            bridge.stop(save: false)
            bridge.process.waitUntilExit()
        }
        let encoded = try JSONEncoder().encode(submittedRequest)
        let request = try JSONSerialization.jsonObject(with: encoded)
        return ["result": "passed", "languageCode": content.language.code, "importedHouseholdSelection": true,
                "importedHouseholdSims": importedHouseholdSims, "selectedVacantHouse": selectedHouse ?? 0, "householdRequest": request,
                "appearancePreviewUpdated": headPreviewWasRendered && outfitPreviewWasRendered, "saveMenuAction": true,
                "loadMenuAction": true, "restoredHouseholdSims": simIDs.count, "manualProfileSlot": savePath.path,
                "originalSaveImport": true, "activeProfileID": importedProfileID, "profileSelectionSurvivesRelaunch": true,
                "sourcePreserved": true, "familyPickerVerified": true, "familyPickerFamilies": familyPickerFamilies]
    }

    private func waitForStorageFeedback(_ title: String, feedback: StorageMenuFeedback) -> Bool {
        let deadline = Date(timeIntervalSinceNow: 45)
        let failure = title == "Game saved" ? "Save failed" : title == "Game loaded" ? "Load failed" : "Simulation failed"
        while feedback.values[title] == nil && feedback.values[failure] == nil && feedback.values["Simulation failed"] == nil && Date() < deadline {
            RunLoop.current.run(until: Date(timeIntervalSinceNow: 0.02))
        }
        return feedback.values[title] != nil
    }
}

/// Stable identifiers for native storage feedback; scripted flows key on the raw values while players see localized original text.
enum StorageFeedbackKind: String {
    case saved = "Game saved"
    case saveFailed = "Save failed"
    case loaded = "Game loaded"
    case loadFailed = "Load failed"
    case neighborhood = "Cannot open neighborhood"
    case imported = "Original save imported"
    case dialogFailed = "Storage dialog failed"

    var showsDialog: Bool { self != .saved && self != .loaded }
    var isFailure: Bool { self != .saved && self != .loaded && self != .imported }
}

func argument(_ name: String) -> String? {
    let args = CommandLine.arguments
    guard let index = args.firstIndex(of: name), index + 1 < args.count else { return nil }
    return args[index + 1]
}

@MainActor
func simulationMenu(target: AppDelegate) -> NSMenu {
    let menu = NSMenu(title: "Simulation")
    let items: [(String, Selector, String)] = [
        ("Build Mode", #selector(AppDelegate.browseBuildCatalog(_:)), ""),
        ("Browse Buy Catalog", #selector(AppDelegate.browseBuyCatalog(_:)), "b"),
        ("Pause / Resume", #selector(AppDelegate.togglePause(_:)), "p"),
        ("Normal Speed", #selector(AppDelegate.normalSpeed(_:)), "1"),
        ("Fast Speed", #selector(AppDelegate.fastSpeed(_:)), "2"),
        ("Fastest Speed", #selector(AppDelegate.fastestSpeed(_:)), "3"),
        ("Next Sim", #selector(AppDelegate.nextSim(_:)), ""),
        ("Story Up", #selector(AppDelegate.storyUp(_:)), ""),
        ("Story Down", #selector(AppDelegate.storyDown(_:)), ""),
        ("Walls Up / Down", #selector(AppDelegate.toggleWalls(_:)), "w"),
        (target.storageMenuSaveTitle(), #selector(AppDelegate.saveGame(_:)), "s"),
        (target.storageMenuLoadTitle(), #selector(AppDelegate.loadGame(_:)), "l"),
        (target.soundOptionsMenuTitle(), #selector(AppDelegate.openSoundOptions(_:)), "")
    ]
    for (title, action, key) in items {
        let item = menu.addItem(withTitle: title, action: action, keyEquivalent: key)
        item.target = target
    }
    return menu
}

@MainActor
func run() throws {
    let interactive = !["--mount", "--inspect", "--render", "--household-screen", "--household-preview", "--outfit-picker", "--check-storage-menu", "--check-new-game-ui", "--pack-report", "--inspect-audio", "--allocate-object-guid", "--reserve-object-guid", "--list-plugins", "--trust-plugin", "--revoke-plugin"].contains(where: CommandLine.arguments.contains)
    let app = interactive ? NSApplication.shared : nil
    app?.setActivationPolicy(.regular)
    if let file = argument("--inspect-audio") {
        let result = try NativeAudioController.inspect(URL(fileURLWithPath: file))
        FileHandle.standardOutput.write(try JSONSerialization.data(withJSONObject: result, options: [.sortedKeys]))
        FileHandle.standardOutput.write(Data([10]))
        return
    }
    // A release bundle carries its runtime files (FreeSO content, self-contained simulation host) in Contents/Resources/workspace.
    let bundledWorkspace = Bundle.main.resourceURL?.appendingPathComponent("workspace", isDirectory: true)
    let usesBundledWorkspace = argument("--workspace") == nil && Bundle.main.bundleURL.pathExtension == "app" &&
        bundledWorkspace.map { FileManager.default.fileExists(atPath: $0.appendingPathComponent("native/SimsSimulation/bin/Release/net9.0").path) } == true
    let workspace = argument("--workspace").map { URL(fileURLWithPath: $0) } ?? (usesBundledWorkspace ? bundledWorkspace! : Bundle.main.bundleURL.deletingLastPathComponent())
    let dataRoot: URL
    let usesApplicationSupport = argument("--data-root") == nil && argument("--workspace") == nil && interactive && Bundle.main.bundleURL.pathExtension == "app"
    if let configuredDataRoot = argument("--data-root") {
        dataRoot = URL(fileURLWithPath: configuredDataRoot, isDirectory: true)
    } else if usesApplicationSupport {
        dataRoot = try FileManager.default.url(for: .applicationSupportDirectory, in: .userDomainMask, appropriateFor: nil, create: true)
            .appendingPathComponent("Sims Native", isDirectory: true)
    } else {
        dataRoot = workspace
    }
    if usesApplicationSupport && !UserDefaults.standard.bool(forKey: "local.sims.native.profileMigrationV1") {
        let manager = FileManager.default
        let oldProfiles = workspace.appendingPathComponent("runtime/native-profiles", isDirectory: true)
        let newProfiles = dataRoot.appendingPathComponent("runtime/native-profiles", isDirectory: true)
        var isDirectory: ObjCBool = false
        if manager.fileExists(atPath: oldProfiles.path, isDirectory: &isDirectory), isDirectory.boolValue,
           !manager.fileExists(atPath: newProfiles.path) {
            let stagingProfiles = newProfiles.deletingLastPathComponent()
                .appendingPathComponent("native-profiles.migrating-" + UUID().uuidString, isDirectory: true)
            try manager.createDirectory(at: stagingProfiles.deletingLastPathComponent(), withIntermediateDirectories: true)
            do {
                try manager.copyItem(at: oldProfiles, to: stagingProfiles)
                try manager.moveItem(at: stagingProfiles, to: newProfiles)
            } catch {
                try? manager.removeItem(at: stagingProfiles)
                if !manager.fileExists(atPath: newProfiles.path) { throw error }
            }
        }
        UserDefaults.standard.set(true, forKey: "local.sims.native.profileMigrationV1")
    }
    let defaultGame = workspace.appendingPathComponent("runtime/game").path
    let gamePathPreference = "local.sims.native.gameInstallPath"
    let fileManager = FileManager.default
    let isAppBundle = Bundle.main.bundleURL.pathExtension == "app"
    func hasCompleteCollectionNeighborhoods(_ gameRoot: URL) -> Bool {
        // Installs keep the neighbourhood lot positions in either folder.
        ["TemplateUserData/LotLocations.iff", "GameData/LotLocations.iff"].contains {
            fileManager.isReadableFile(atPath: gameRoot.appendingPathComponent($0).path)
        }
    }
    let path: String
    if let suppliedPath = argument("--game") {
        path = suppliedPath
    } else {
        let savedPath = UserDefaults.standard.string(forKey: gamePathPreference)
        // Without a saved choice, try the folder most people extract the game to before asking.
        let downloadsGame = fileManager.homeDirectoryForCurrentUser.appendingPathComponent("Downloads/The Sims 1", isDirectory: true).path
        let candidates = [savedPath, isAppBundle ? nil : defaultGame, downloadsGame].compactMap { $0 }
        if let foundPath = candidates.first(where: {
            let gameRoot = URL(fileURLWithPath: $0, isDirectory: true)
            return fileManager.isReadableFile(atPath: gameRoot.appendingPathComponent("UIGraphics/UIGraphics.far").path) &&
                (!isAppBundle || hasCompleteCollectionNeighborhoods(gameRoot))
        }) {
            path = foundPath
        } else if interactive {
            app?.activate(ignoringOtherApps: true)
            var selectedPath: String?
            while selectedPath == nil {
                let panel = NSOpenPanel()
                panel.canChooseFiles = false
                panel.canChooseDirectories = true
                panel.allowsMultipleSelection = false
                panel.prompt = "Use Game Folder"
                panel.directoryURL = fileManager.homeDirectoryForCurrentUser.appendingPathComponent("Downloads", isDirectory: true)
                panel.message = "Choose the installed PC Complete Collection folder containing UIGraphics/UIGraphics.far and LotLocations.iff (in TemplateUserData or GameData). Game files stay in their original location."
                guard panel.runModal() == .OK, let selected = panel.url else { return }
                let archive = selected.appendingPathComponent("UIGraphics/UIGraphics.far")
                if fileManager.isReadableFile(atPath: archive.path) && hasCompleteCollectionNeighborhoods(selected) {
                    let normalized = selected.resolvingSymlinksInPath().standardizedFileURL.path
                    selectedPath = normalized
                    UserDefaults.standard.set(normalized, forKey: gamePathPreference)
                } else {
                    let alert = NSAlert()
                    alert.messageText = "This folder does not contain Sims game data"
                    alert.informativeText = "Choose the Complete Collection folder that contains UIGraphics/UIGraphics.far and LotLocations.iff (in TemplateUserData or GameData)."
                    alert.alertStyle = .warning
                    alert.addButton(withTitle: "Choose Again")
                    alert.runModal()
                }
            }
            guard let chosenPath = selectedPath else { throw ContentError.invalid("No Sims game folder was selected") }
            path = chosenPath
        } else {
            throw ContentError.invalid("Pass --game with the extracted Sims directory")
        }
    }
    // Packs are user-owned content: beside the app's data for a release bundle, in the workspace for developer runs.
    let defaultPacks = (usesBundledWorkspace ? dataRoot : workspace).appendingPathComponent("packs").path
    let packPath = argument("--packs") ?? (Bundle.main.bundleURL.pathExtension == "app" ? defaultPacks : nil)
    let packs = packPath.map { URL(fileURLWithPath: $0, isDirectory: true) }
    let loadContent: @Sendable () throws -> GameContent = {
        // A missing packs folder (first launch of a release bundle) simply means no custom packs.
        var directories: [URL] = []
        if let folder = packs, FileManager.default.fileExists(atPath: folder.path) {
            directories = try FileManager.default.contentsOfDirectory(at: folder, includingPropertiesForKeys: nil).filter {
                FileManager.default.fileExists(atPath: $0.appendingPathComponent("pack.json").path)
            }
        }
        return try GameContent(root: URL(fileURLWithPath: path, isDirectory: true), packDirectories: directories)
    }
    let sceneURL = argument("--scene").map { URL(fileURLWithPath: $0) }
    if !interactive {
        let content = try loadContent()
        if CommandLine.arguments.contains("--check-new-game-ui") {
            let application = NSApplication.shared
            application.setActivationPolicy(.prohibited)
            let fileManager = FileManager.default
            let testWorkspace = fileManager.temporaryDirectory.appendingPathComponent("sims-native-new-game-check-" + UUID().uuidString, isDirectory: true)
            try fileManager.createDirectory(at: testWorkspace.appendingPathComponent("runtime", isDirectory: true), withIntermediateDirectories: true)
            try fileManager.createSymbolicLink(at: testWorkspace.appendingPathComponent("engine", isDirectory: true), withDestinationURL: workspace.appendingPathComponent("engine", isDirectory: true))
            try fileManager.createSymbolicLink(at: testWorkspace.appendingPathComponent("native", isDirectory: true), withDestinationURL: workspace.appendingPathComponent("native", isDirectory: true))
            try fileManager.createSymbolicLink(at: testWorkspace.appendingPathComponent("runtime/dotnet", isDirectory: true), withDestinationURL: workspace.appendingPathComponent("runtime/dotnet", isDirectory: true))
            defer { try? fileManager.removeItem(at: testWorkspace) }
            let delegate = AppDelegate(loadContent: loadContent, sceneURL: nil, workspace: testWorkspace, liveHouse: nil, showsNeighborhood: false)
            let report = try delegate.checkNewGameInputFlow(content: content)
            FileHandle.standardOutput.write(try JSONSerialization.data(withJSONObject: report, options: [.sortedKeys]))
            FileHandle.standardOutput.write(Data([10]))
            return
        }
        if CommandLine.arguments.contains("--check-storage-menu") {
            _ = NSApplication.shared
            let fileManager = FileManager.default
            let testWorkspace = fileManager.temporaryDirectory.appendingPathComponent("sims-native-storage-check-" + UUID().uuidString, isDirectory: true)
            try fileManager.createDirectory(at: testWorkspace.appendingPathComponent("runtime", isDirectory: true), withIntermediateDirectories: true)
            try fileManager.createSymbolicLink(at: testWorkspace.appendingPathComponent("engine", isDirectory: true), withDestinationURL: workspace.appendingPathComponent("engine", isDirectory: true))
            try fileManager.createSymbolicLink(at: testWorkspace.appendingPathComponent("native", isDirectory: true), withDestinationURL: workspace.appendingPathComponent("native", isDirectory: true))
            try fileManager.createSymbolicLink(at: testWorkspace.appendingPathComponent("runtime/dotnet", isDirectory: true), withDestinationURL: workspace.appendingPathComponent("runtime/dotnet", isDirectory: true))
            defer { try? fileManager.removeItem(at: testWorkspace) }
            let delegate = AppDelegate(loadContent: loadContent, sceneURL: nil, workspace: testWorkspace, liveHouse: nil, showsNeighborhood: false)
            let house = Int(argument("--house") ?? "5") ?? 5
            let report = try delegate.checkStorageMenuFlow(content: content, house: house)
            FileHandle.standardOutput.write(try JSONSerialization.data(withJSONObject: report, options: [.sortedKeys]))
            FileHandle.standardOutput.write(Data([10]))
            return
        }
        if let name = argument("--allocate-object-guid") ?? argument("--reserve-object-guid") {
            guard let packID = argument("--pack-id") else { throw ContentError.invalid("Object allocation requires --pack-id") }
            let reservation = try CommandLine.arguments.contains("--reserve-object-guid") ? content.reserveObjectGUID(packID: packID, name: name) : content.allocateObjectGUID(packID: packID, name: name)
            FileHandle.standardOutput.write(try JSONEncoder().encode(reservation))
            FileHandle.standardOutput.write(Data([10]))
            return
        }
        if CommandLine.arguments.contains("--list-plugins") || argument("--trust-plugin") != nil || argument("--revoke-plugin") != nil {
            var store = try PluginTrustStore(dataRoot: dataRoot)
            let plugins = try content.packs.pluginReports()
            if let packID = argument("--trust-plugin") {
                guard let plugin = plugins.first(where: { $0.packID == packID }) else {
                    throw ContentError.invalid("No enabled pack named \(packID) declares a plugin")
                }
                try store.trust(plugin)
            }
            if let packID = argument("--revoke-plugin") {
                guard try store.revoke(packID: packID) else { throw ContentError.invalid("Plugin \(packID) was not trusted") }
            }
            let listing: [[String: Any]] = plugins.map {
                ["packID": $0.packID, "version": $0.version, "sha256": $0.sha256, "entryType": $0.entryType,
                 "apiVersion": $0.apiVersion, "stateVersion": $0.stateVersion, "trusted": store.isTrusted($0)]
            }
            let result: [String: Any] = ["trustStore": store.url.path, "plugins": listing]
            FileHandle.standardOutput.write(try JSONSerialization.data(withJSONObject: result, options: [.prettyPrinted, .sortedKeys]))
            FileHandle.standardOutput.write(Data([10]))
            return
        }
        if CommandLine.arguments.contains("--pack-report") {
            let encoder = JSONEncoder()
            encoder.outputFormatting = [.prettyPrinted, .sortedKeys]
            let data = try encoder.encode(content.packs.report())
            FileHandle.standardOutput.write(data)
            FileHandle.standardOutput.write(Data([10]))
            return
        }
        if let mount = argument("--mount") {
            try content.materialize(at: URL(fileURLWithPath: mount, isDirectory: true))
            print("Prepared simulation content mount: \(mount)")
            return
        }
        if CommandLine.arguments.contains("--inspect") {
            print("Original UI archive: \(content.ui.entries.count) resources")
            print("Enabled packs: \(content.packs.ordered.map { $0.manifest.id }.joined(separator: ", "))")
            let languageID = content.language.windowsLanguageID.map { String(format: "0x%04X", $0) } ?? "fallback"
            print("Installed language: \(content.language.name) (STR code \(content.language.code), PE LANGID \(languageID))")
            return
        }
        if let output = argument("--render") {
            guard let device = MTLCreateSystemDefaultDevice() else { throw ContentError.invalid("Metal is unavailable") }
            let renderer = try OriginalUIRenderer(content: content, device: device, sceneURL: sceneURL)
            renderer.liveMode = CommandLine.arguments.contains("--controls")
            if let screen = argument("--household-screen") {
                guard screen == "family" || screen == "sim" else { throw ContentError.invalid("Household screen must be family or sim") }
                let creation = try OriginalHouseholdCreationOverlay(content: content, device: device)
                if screen == "sim" { creation.showSimPreview() }
                if let catalogPath = argument("--household-appearance-catalog") {
                    let data = try Data(contentsOf: URL(fileURLWithPath: catalogPath))
                    creation.setAppearanceCatalog(try JSONDecoder().decode(HouseholdAppearanceCatalog.self, from: data))
                }
                renderer.householdCreation = creation
                if let previewPath = argument("--household-preview") {
                    let loaded = try HouseholdAppearancePreview.load(from: URL(fileURLWithPath: previewPath))
                    try renderer.updateHouseholdAppearancePreview(loaded.preview, pixels: loaded.pixels)
                }
            }
            if let pickerDirectory = argument("--outfit-picker") {
                // Offscreen check of the wardrobe/pet carousel: names come from the host's choices.json, the preview from its last export.
                let directory = URL(fileURLWithPath: pickerDirectory, isDirectory: true)
                let names = try JSONDecoder().decode([String].self, from: Data(contentsOf: directory.appendingPathComponent("choices.json")))
                let picker = try OriginalOutfitPickerOverlay(token: "preview", pet: CommandLine.arguments.contains("--pet"), names: names, content: content,
                                                             font: renderer.pieFont, device: device, strings: OriginalUIStrings(content: content))
                picker.move(names.count - 1)
                renderer.outfitPicker = picker
                let loaded = try HouseholdAppearancePreview.load(from: directory.appendingPathComponent("cas-preview/preview.json"))
                try renderer.updateHouseholdAppearancePreview(loaded.preview, pixels: loaded.pixels)
            }
            if let manifestPath = argument("--neighborhood-manifest") {
                let session = URL(fileURLWithPath: argument("--neighborhood-session") ?? URL(fileURLWithPath: manifestPath).deletingLastPathComponent().path, isDirectory: true)
                renderer.neighborhood = try OriginalNeighborhoodOverlay(content: content, device: device,
                                                                         manifestURL: URL(fileURLWithPath: manifestPath), session: session, font: renderer.pieFont)
            }
            if let value = argument("--ui-scale") {
                guard let scale = Float(value), scale.isFinite, (1...4).contains(scale) else { throw ContentError.invalid("UI scale must be between 1 and 4") }
                renderer.uiScale = scale
            }
            if let path = argument("--panel-state") {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                guard data.count <= 4 * 1024 * 1024 else { throw ContentError.invalid("Gameplay fixture exceeds size limit") }
                renderer.liveMode = true
                if let state = try JSONSerialization.jsonObject(with: data) as? [String: Any] {
                    renderer.roofStyle = (state["roofStyle"] as? NSNumber)?.uint16Value ?? 16
                    renderer.roofPitch = (state["roofPitch"] as? NSNumber)?.floatValue ?? 0.66
                }
                try renderer.updateGameplay(JSONDecoder().decode(GameplayPanelState.self, from: data))
            }
            if let panel = argument("--subpanel") {
                guard let mode = OriginalGameplayOverlay.Subpanel(rawValue: panel) else { throw ContentError.invalid("Unknown gameplay subpanel") }
                try renderer.gameplay.choose(mode)
            }
            try renderer.gameplay.prepare(canvas: CGSize(width: CGFloat(Int(argument("--width") ?? "1600") ?? 1600) / CGFloat(renderer.uiScale), height: CGFloat(Int(argument("--height") ?? "1200") ?? 1200) / CGFloat(renderer.uiScale)))
            if let value = argument("--interest-page") {
                guard let page = Int(value) else { throw ContentError.invalid("Invalid interest page") }
                try renderer.gameplay.chooseInterestPage(page)
            }
            if let value = argument("--relationship-filter") {
                guard let filter = OriginalGameplayLayout.RelationshipFilter(rawValue: value) else { throw ContentError.invalid("Invalid relationship filter") }
                try renderer.gameplay.chooseRelationshipFilter(filter)
            }
            if let value = argument("--relationship-page") {
                guard let page = Int(value) else { throw ContentError.invalid("Invalid relationship page") }
                try renderer.gameplay.chooseRelationshipPage(page)
            }
            if let path = argument("--buy-catalog") {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                guard data.count <= 4 * 1024 * 1024 else { throw ContentError.invalid("Catalog fixture exceeds size limit") }
                let page = try JSONDecoder().decode(BuyCatalogPage.self, from: data)
                try renderer.updateCatalog(page)
                renderer.liveMode = true
                renderer.buyMode = true
            }
            if let path = argument("--build-catalog") {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                guard data.count <= 4 * 1024 * 1024 else { throw ContentError.invalid("Build fixture exceeds size limit") }
                try renderer.updateBuildCatalog(JSONDecoder().decode(BuildCatalogPage.self, from: data))
                renderer.liveMode = true
                renderer.buyMode = false
                renderer.buildMode = true
            }
            if let path = argument("--build-objects") {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                guard data.count <= 4 * 1024 * 1024 else { throw ContentError.invalid("Build object fixture exceeds size limit") }
                try renderer.updateBuildObjects(JSONDecoder().decode(BuyCatalogPage.self, from: data))
                renderer.liveMode = true
                renderer.buyMode = false
                renderer.buildMode = true
            }
            if let value = argument("--catalog-guid") {
                guard renderer.buyMode || renderer.buildMode && (renderer.build.objectTool != nil || renderer.build.kind == .water), let guid = UInt32(value) else { throw ContentError.invalid("Catalog selection requires an object catalog and a valid GUID") }
                renderer.chooseCatalogObject(guid)
            }
            if argument("--build-object-tool") == "hand" {
                guard renderer.buildMode else { throw ContentError.invalid("Hand tool requires build mode") }
                renderer.build.changeObjectTool(.hand)
                renderer.buy.cancelSelection()
            }
            if let value = argument("--floor-brush") {
                let coordinates = value.split(separator: ",").compactMap { Int($0) }
                guard renderer.buildMode, coordinates.count == 4,
                      let rectangle = FloorBrushRectangle(startX: coordinates[0], startY: coordinates[1], endX: coordinates[2], endY: coordinates[3]) else {
                    throw ContentError.invalid("Floor brush requires a build catalog and four valid tile coordinates")
                }
                guard let selection = FloorBrushSelection(rectangle: rectangle, half: Int(argument("--floor-half") ?? "0") ?? -1, water: renderer.build.kind == .water && !CommandLine.arguments.contains("--floor-delete")) else { throw ContentError.invalid("Invalid floor brush half") }
                try renderer.updateFloorBrush(selection, deleting: CommandLine.arguments.contains("--floor-delete"))
            }
            if let value = argument("--wall-brush") {
                let coordinates = value.split(separator: ",").compactMap { Int($0) }
                guard renderer.buildMode, coordinates.count == 4,
                      let line = WallBrushSelection(start: LotVertex(x: coordinates[0], y: coordinates[1]), end: LotVertex(x: coordinates[2], y: coordinates[3]),
                                                    rectangle: CommandLine.arguments.contains("--wall-rectangle"), deleting: CommandLine.arguments.contains("--wall-delete")) else {
                    throw ContentError.invalid("Wall brush requires a build catalog and four valid vertex coordinates")
                }
                try renderer.updateWallBrush(line)
            }
            if let path = argument("--placement-preview") {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                guard data.count <= 64 * 1024 else { throw ContentError.invalid("Placement fixture exceeds size limit") }
                try renderer.updatePlacement(JSONDecoder().decode(PlacementPreview.self, from: data))
            }
            if let path = argument("--reload-panel-state") {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                guard data.count <= 4 * 1024 * 1024 else { throw ContentError.invalid("Gameplay fixture exceeds size limit") }
                if let state = try JSONSerialization.jsonObject(with: data) as? [String: Any] {
                    renderer.roofStyle = (state["roofStyle"] as? NSNumber)?.uint16Value ?? 16
                    renderer.roofPitch = (state["roofPitch"] as? NSNumber)?.floatValue ?? 0.66
                }
                try renderer.updateGameplay(JSONDecoder().decode(GameplayPanelState.self, from: data))
            }
            if let menu = argument("--pie-menu") {
                let fixture = try PieMenuPreview.load(URL(fileURLWithPath: menu))
                renderer.liveMode = true
                renderer.pieMenu = try OriginalPieOverlay(entries: fixture.entries, objectID: fixture.objectID, selectedSim: fixture.selectedSim,
                                                         anchor: CGPoint(x: fixture.x, y: fixture.y), font: renderer.pieFont, device: device)
            }
            if let path = argument("--dialog") {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                guard data.count <= 65536 else { throw ContentError.invalid("Dialog fixture exceeds size limit") }
                let dialog = try JSONDecoder().decode(GameDialog.self, from: data)
                renderer.liveMode = true
                renderer.gameDialog = try OriginalDialogOverlay(dialog: dialog, font: renderer.pieFont, device: renderer.device, content: content)
            }
            if let reload = argument("--reload-scene") { try renderer.loadScene(URL(fileURLWithPath: reload)) }
            if let animationPath = argument("--animation") {
                let data = try Data(contentsOf: URL(fileURLWithPath: animationPath))
                guard data.count <= 16 * 1024 * 1024 else { throw ContentError.invalid("Animation fixture exceeds 16 MiB") }
                let animation = try JSONDecoder().decode(SceneAnimation.self, from: data)
                guard let sceneURL else { throw ContentError.invalid("Animation fixture requires --scene") }
                try renderer.loadScene(sceneURL, revision: animation.baseRevision)
                try renderer.applyAnimation(animation)
            }
            if let streamPath = argument("--animation-stream") {
                let data = try Data(contentsOf: URL(fileURLWithPath: streamPath))
                guard data.count <= 128 * 1024 * 1024 else { throw ContentError.invalid("Animation replay exceeds 128 MiB") }
                let lines = data.split(separator: 10)
                guard !lines.isEmpty, lines.count <= 300, let sceneURL else { throw ContentError.invalid("Animation replay requires a scene and 1..300 frames") }
                for (index, line) in lines.enumerated() {
                    guard line.count <= 16 * 1024 * 1024 else { throw ContentError.invalid("Animation frame exceeds 16 MiB") }
                    let frame = try JSONDecoder().decode(SceneAnimation.self, from: Data(line))
                    if index == 0 { try renderer.loadScene(sceneURL, revision: frame.baseRevision) }
                    try renderer.applyAnimation(frame)
                }
            }
            try renderer.renderPNG(width: Int(argument("--width") ?? "1600") ?? 1600, height: Int(argument("--height") ?? "1200") ?? 1200, destination: URL(fileURLWithPath: output))
            print("Metal render saved to \(output)")
            return
        }
        return
    }
    guard let app else { throw ContentError.invalid("Interactive application is unavailable") }
    let live = CommandLine.arguments.contains("--live") || (Bundle.main.bundleURL.pathExtension == "app" && sceneURL == nil)
    let requestedHouse = argument("--house").flatMap(Int.init)
    let showsNeighborhood = live && requestedHouse == nil
    let liveHouse = live ? requestedHouse : nil
    let delegate = AppDelegate(loadContent: loadContent, sceneURL: sceneURL, workspace: workspace, dataRoot: dataRoot,
                               liveHouse: liveHouse, showsNeighborhood: showsNeighborhood,
                               gameRoot: URL(fileURLWithPath: path, isDirectory: true))
    app.delegate = delegate
    let menu = NSMenu()
    let appItem = NSMenuItem()
    menu.addItem(appItem)
    let appMenu = NSMenu()
    appMenu.addItem(withTitle: "Quit", action: #selector(NSApplication.terminate(_:)), keyEquivalent: "q")
    appItem.submenu = appMenu
    let fileItem = NSMenuItem()
    menu.addItem(fileItem)
    let fileMenu = NSMenu(title: "File")
    let importSaveItem = fileMenu.addItem(withTitle: "Import Original Save…", action: #selector(AppDelegate.importOriginalSave(_:)), keyEquivalent: "")
    importSaveItem.target = delegate
    fileItem.submenu = fileMenu
    let viewItem = NSMenuItem()
    menu.addItem(viewItem)
    let viewMenu = NSMenu(title: "View")
    viewMenu.addItem(withTitle: "Toggle Full Screen", action: #selector(NSWindow.toggleFullScreen(_:)), keyEquivalent: "f")
    viewItem.submenu = viewMenu
    app.mainMenu = menu
    if liveHouse != nil || showsNeighborhood {
        let simulationItem = NSMenuItem()
        menu.addItem(simulationItem)
        simulationItem.submenu = simulationMenu(target: delegate)
    }
    withExtendedLifetime(delegate) { app.run() }
}

do {
    try run()
} catch {
    fputs("\(error)\n", stderr)
    exit(1)
}
