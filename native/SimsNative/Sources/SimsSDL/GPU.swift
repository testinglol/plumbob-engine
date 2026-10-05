import CSDL3
import Foundation
import SimsCore

struct SDLError: Error, CustomStringConvertible {
    let description: String
    init(_ context: String) { description = "\(context): \(String(cString: SDL_GetError()))" }
}

/// Mirrors the Metal Quad and the std140 block in Shaders/sdl/quad.glsl: rect, canvas size + (flip, opacity), uv rect,
/// depth interval and tint.
struct Quad {
    var rect: SIMD4<Float>
    var canvasPadding: SIMD4<Float>
    var uvRect = SIMD4<Float>(0, 0, 1, 1)
    var depthInterval = SIMD4<Float>(repeating: 0)
    var tint = SIMD4<Float>(repeating: 1)

    init(rect: SIMD4<Float>, canvas: SIMD2<Float>, flip: Bool = false, opacity: Float = 1) {
        self.rect = rect
        canvasPadding = SIMD4(canvas.x, canvas.y, flip ? 1 : 0, opacity)
    }
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

/// Owns the SDL GPU device. Every texture and buffer holds it, so the device outlives whatever was made on it, whatever
/// order the objects holding them are released in.
final class GPUDevice {
    let handle: OpaquePointer
    init(_ handle: OpaquePointer) { self.handle = handle }
    deinit { SDL_DestroyGPUDevice(handle) }
}

final class GPUTexture {
    let handle: OpaquePointer
    let width: Int
    let height: Int
    let format: SDL_GPUTextureFormat
    private let device: GPUDevice
    init(handle: OpaquePointer, width: Int, height: Int, format: SDL_GPUTextureFormat, device: GPUDevice) {
        self.handle = handle
        self.width = width
        self.height = height
        self.format = format
        self.device = device
    }
    deinit { SDL_ReleaseGPUTexture(device.handle, handle) }
}

final class GPUBuffer {
    let handle: OpaquePointer
    let count: Int
    private let device: GPUDevice
    init(handle: OpaquePointer, count: Int, device: GPUDevice) {
        self.handle = handle
        self.count = count
        self.device = device
    }
    deinit { SDL_ReleaseGPUBuffer(device.handle, handle) }
}

/// The SDL_GPU equivalents of the Metal renderer's pipeline states, depth states and samplers. SDL_GPU folds the depth
/// state into the pipeline, so each shader pair is built once per depth mode it is drawn with.
final class GPUContext {
    enum DepthMode { case flat, mesh }
    enum Program: Hashable {
        case sprite, ghost, spriteDepth, terrain, placement, surface, avatar
    }

    static let colorFormat = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB
    static let depthFormat = SDL_GPU_TEXTUREFORMAT_D32_FLOAT

    private let owner: GPUDevice
    var device: OpaquePointer { owner.handle }
    private(set) var sampler: OpaquePointer!
    private(set) var roofSampler: OpaquePointer!
    /// Nearest sampling for art drawn at a whole number of screen pixels per texel, so zoomed sprites stay sharp.
    private(set) var pixelSampler: OpaquePointer!
    private var shaders: [String: OpaquePointer] = [:]
    private var pipelines: [String: OpaquePointer] = [:]

    init() throws {
        guard let device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, false, nil) else { throw SDLError("SDL_CreateGPUDevice") }
        owner = GPUDevice(device)
        sampler = try makeSampler(filter: SDL_GPU_FILTER_LINEAR, address: SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE)
        roofSampler = try makeSampler(filter: SDL_GPU_FILTER_LINEAR, address: SDL_GPU_SAMPLERADDRESSMODE_REPEAT)
        pixelSampler = try makeSampler(filter: SDL_GPU_FILTER_NEAREST, address: SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE)
    }

    deinit {
        for pipeline in pipelines.values { SDL_ReleaseGPUGraphicsPipeline(device, pipeline) }
        for shader in shaders.values { SDL_ReleaseGPUShader(device, shader) }
        for sampler in [sampler, roofSampler, pixelSampler] { if let sampler { SDL_ReleaseGPUSampler(device, sampler) } }
    }

    private func makeSampler(filter: SDL_GPUFilter, address: SDL_GPUSamplerAddressMode) throws -> OpaquePointer {
        var info = SDL_GPUSamplerCreateInfo()
        info.min_filter = filter
        info.mag_filter = filter
        info.mipmap_mode = SDL_GPU_SAMPLERMIPMAPMODE_NEAREST
        info.address_mode_u = address
        info.address_mode_v = address
        info.address_mode_w = address
        guard let sampler = SDL_CreateGPUSampler(device, &info) else { throw SDLError("SDL_CreateGPUSampler") }
        return sampler
    }

    private static var shaderDirectory: URL? {
        if let override = ProcessInfo.processInfo.environment["SIMS_SDL_SHADERS"] { return URL(fileURLWithPath: override) }
        return Bundle.module.url(forResource: "Shaders", withExtension: nil)
    }

    private func shader(_ name: String, stage: SDL_GPUShaderStage, samplers: UInt32 = 0, storageBuffers: UInt32 = 0, uniforms: UInt32 = 0) throws -> OpaquePointer {
        if let cached = shaders[name] { return cached }
        guard let url = GPUContext.shaderDirectory?.appendingPathComponent(name + ".spv") else { throw ContentError.invalid("SDL shaders are missing") }
        let code = try Data(contentsOf: url)
        let created: OpaquePointer? = code.withUnsafeBytes { bytes in
            "main".withCString { entry in
                var info = SDL_GPUShaderCreateInfo()
                info.code_size = bytes.count
                info.code = bytes.baseAddress!.assumingMemoryBound(to: UInt8.self)
                info.entrypoint = entry
                info.format = SDL_GPU_SHADERFORMAT_SPIRV
                info.stage = stage
                info.num_samplers = samplers
                info.num_storage_buffers = storageBuffers
                info.num_uniform_buffers = uniforms
                return SDL_CreateGPUShader(device, &info)
            }
        }
        guard let created else { throw SDLError("SDL_CreateGPUShader \(name)") }
        shaders[name] = created
        return created
    }

    func pipeline(_ program: Program, depth: DepthMode) throws -> OpaquePointer {
        let key = "\(program)-\(depth)"
        if let cached = pipelines[key] { return cached }
        let vertex: OpaquePointer
        let fragment: OpaquePointer
        var blended = true
        switch program {
        case .sprite, .ghost, .spriteDepth:
            vertex = try shader("sprite.vert", stage: SDL_GPU_SHADERSTAGE_VERTEX, uniforms: 1)
            let name = program == .sprite ? "sprite.frag" : program == .ghost ? "ghost.frag" : "spriteDepth.frag"
            fragment = try shader(name, stage: SDL_GPU_SHADERSTAGE_FRAGMENT, samplers: program == .spriteDepth ? 2 : 1)
        case .terrain, .placement:
            vertex = try shader("terrain.vert", stage: SDL_GPU_SHADERSTAGE_VERTEX, storageBuffers: 1, uniforms: 1)
            fragment = try shader(program == .terrain ? "terrain.frag" : "placement.frag", stage: SDL_GPU_SHADERSTAGE_FRAGMENT)
            blended = program == .placement
        case .surface, .avatar:
            vertex = try shader("avatar.vert", stage: SDL_GPU_SHADERSTAGE_VERTEX, storageBuffers: 1, uniforms: 1)
            fragment = try shader(program == .surface ? "surface.frag" : "avatar.frag", stage: SDL_GPU_SHADERSTAGE_FRAGMENT, samplers: 1)
        }
        var color = SDL_GPUColorTargetDescription()
        color.format = GPUContext.colorFormat
        color.blend_state.enable_blend = blended
        color.blend_state.src_color_blendfactor = SDL_GPU_BLENDFACTOR_ONE
        color.blend_state.dst_color_blendfactor = SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA
        color.blend_state.color_blend_op = SDL_GPU_BLENDOP_ADD
        color.blend_state.src_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ONE
        color.blend_state.dst_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA
        color.blend_state.alpha_blend_op = SDL_GPU_BLENDOP_ADD
        let created: OpaquePointer? = withUnsafePointer(to: &color) { colorPointer in
            var info = SDL_GPUGraphicsPipelineCreateInfo()
            info.vertex_shader = vertex
            info.fragment_shader = fragment
            info.primitive_type = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST
            info.rasterizer_state.fill_mode = SDL_GPU_FILLMODE_FILL
            info.rasterizer_state.cull_mode = SDL_GPU_CULLMODE_NONE
            info.depth_stencil_state.enable_depth_test = true
            info.depth_stencil_state.enable_depth_write = depth == .mesh
            info.depth_stencil_state.compare_op = depth == .mesh ? SDL_GPU_COMPAREOP_LESS_OR_EQUAL : SDL_GPU_COMPAREOP_ALWAYS
            info.target_info.color_target_descriptions = colorPointer
            info.target_info.num_color_targets = 1
            info.target_info.depth_stencil_format = GPUContext.depthFormat
            info.target_info.has_depth_stencil_target = true
            return SDL_CreateGPUGraphicsPipeline(device, &info)
        }
        guard let created else { throw SDLError("SDL_CreateGPUGraphicsPipeline \(key)") }
        pipelines[key] = created
        return created
    }

    func makeTexture(width: Int, height: Int, format: SDL_GPUTextureFormat, usage: SDL_GPUTextureUsageFlags) throws -> GPUTexture {
        var info = SDL_GPUTextureCreateInfo()
        info.type = SDL_GPU_TEXTURETYPE_2D
        info.format = format
        info.usage = usage
        info.width = UInt32(max(1, width))
        info.height = UInt32(max(1, height))
        info.layer_count_or_depth = 1
        info.num_levels = 1
        info.sample_count = SDL_GPU_SAMPLECOUNT_1
        guard let texture = SDL_CreateGPUTexture(device, &info) else { throw SDLError("SDL_CreateGPUTexture") }
        return GPUTexture(handle: texture, width: width, height: height, format: format, device: owner)
    }

    /// Creates sampled textures from tightly packed pixels (4 bytes per pixel for colour, 1 for depth8) in one copy pass.
    func uploadTextures(_ images: [(width: Int, height: Int, depth8: Bool, pixels: Data)]) throws -> [GPUTexture] {
        guard !images.isEmpty else { return [] }
        let textures = try images.map {
            try makeTexture(width: $0.width, height: $0.height, format: $0.depth8 ? SDL_GPU_TEXTUREFORMAT_R8_UNORM : GPUContext.colorFormat,
                            usage: SDL_GPU_TEXTUREUSAGE_SAMPLER)
        }
        try upload(images.map(\.pixels)) { copy, transfer, offsets in
            for (index, image) in images.enumerated() {
                var source = SDL_GPUTextureTransferInfo(transfer_buffer: transfer, offset: offsets[index], pixels_per_row: UInt32(image.width), rows_per_layer: UInt32(image.height))
                var region = SDL_GPUTextureRegion()
                region.texture = textures[index].handle
                region.w = UInt32(image.width)
                region.h = UInt32(image.height)
                region.d = 1
                SDL_UploadToGPUTexture(copy, &source, &region, false)
            }
        }
        return textures
    }

    func makeStorageBuffer<Element>(_ elements: [Element]) throws -> GPUBuffer? {
        guard !elements.isEmpty else { return nil }
        let data = elements.withUnsafeBytes { Data($0) }
        var info = SDL_GPUBufferCreateInfo()
        info.usage = SDL_GPU_BUFFERUSAGE_GRAPHICS_STORAGE_READ
        info.size = UInt32(data.count)
        guard let buffer = SDL_CreateGPUBuffer(device, &info) else { throw SDLError("SDL_CreateGPUBuffer") }
        let result = GPUBuffer(handle: buffer, count: elements.count, device: owner)
        try upload([data]) { copy, transfer, _ in
            var source = SDL_GPUTransferBufferLocation(transfer_buffer: transfer, offset: 0)
            var region = SDL_GPUBufferRegion(buffer: buffer, offset: 0, size: UInt32(data.count))
            SDL_UploadToGPUBuffer(copy, &source, &region, false)
        }
        return result
    }

    private func upload(_ chunks: [Data], encode: (OpaquePointer, OpaquePointer, [UInt32]) -> Void) throws {
        var offsets: [UInt32] = []
        var total = 0
        for chunk in chunks {
            offsets.append(UInt32(total))
            total += (chunk.count + 3) & ~3
        }
        var info = SDL_GPUTransferBufferCreateInfo()
        info.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD
        info.size = UInt32(max(4, total))
        guard let transfer = SDL_CreateGPUTransferBuffer(device, &info) else { throw SDLError("SDL_CreateGPUTransferBuffer") }
        defer { SDL_ReleaseGPUTransferBuffer(device, transfer) }
        guard let mapped = SDL_MapGPUTransferBuffer(device, transfer, false) else { throw SDLError("SDL_MapGPUTransferBuffer") }
        for (index, chunk) in chunks.enumerated() {
            chunk.withUnsafeBytes { bytes in
                if let base = bytes.baseAddress { (mapped + Int(offsets[index])).copyMemory(from: base, byteCount: bytes.count) }
            }
        }
        SDL_UnmapGPUTransferBuffer(device, transfer)
        if let batchCopy {
            encode(batchCopy, transfer, offsets)
            return
        }
        guard let command = SDL_AcquireGPUCommandBuffer(device) else { throw SDLError("SDL_AcquireGPUCommandBuffer") }
        guard let copy = SDL_BeginGPUCopyPass(command) else { throw SDLError("SDL_BeginGPUCopyPass") }
        encode(copy, transfer, offsets)
        SDL_EndGPUCopyPass(copy)
        guard SDL_SubmitGPUCommandBuffer(command) else { throw SDLError("SDL_SubmitGPUCommandBuffer") }
    }

    private var batchCopy: OpaquePointer?

    /// Records every upload made in `body` into one copy pass and command buffer. Each command buffer in flight holds its
    /// own descriptor-set cache in SDL's Vulkan backend, which grows to the most sets one frame binds, so a command buffer
    /// per upload multiplies descriptor memory (on lavapipe, one mapping per set, until the process runs out of mappings).
    /// With `command`, the copy pass goes into that command buffer (ahead of its other passes) and the caller submits it.
    func batchingUploads<Result>(into command: OpaquePointer? = nil, _ body: () throws -> Result) throws -> Result {
        guard batchCopy == nil else { return try body() }
        let owned = command == nil
        guard let command = command ?? SDL_AcquireGPUCommandBuffer(device) else { throw SDLError("SDL_AcquireGPUCommandBuffer") }
        guard let copy = SDL_BeginGPUCopyPass(command) else {
            if owned { _ = SDL_SubmitGPUCommandBuffer(command) }
            throw SDLError("SDL_BeginGPUCopyPass")
        }
        batchCopy = copy
        defer {
            batchCopy = nil
            SDL_EndGPUCopyPass(copy)
            if owned { _ = SDL_SubmitGPUCommandBuffer(command) }
        }
        return try body()
    }

    /// Reads a colour target back as tightly packed RGBA bytes (the sRGB-encoded values the target stores).
    func readPixels(_ texture: GPUTexture) throws -> Data {
        let size = texture.width * texture.height * 4
        var info = SDL_GPUTransferBufferCreateInfo()
        info.usage = SDL_GPU_TRANSFERBUFFERUSAGE_DOWNLOAD
        info.size = UInt32(size)
        guard let transfer = SDL_CreateGPUTransferBuffer(device, &info) else { throw SDLError("SDL_CreateGPUTransferBuffer") }
        defer { SDL_ReleaseGPUTransferBuffer(device, transfer) }
        guard let command = SDL_AcquireGPUCommandBuffer(device), let copy = SDL_BeginGPUCopyPass(command) else { throw SDLError("readback") }
        var region = SDL_GPUTextureRegion()
        region.texture = texture.handle
        region.w = UInt32(texture.width)
        region.h = UInt32(texture.height)
        region.d = 1
        var destination = SDL_GPUTextureTransferInfo(transfer_buffer: transfer, offset: 0, pixels_per_row: UInt32(texture.width), rows_per_layer: UInt32(texture.height))
        SDL_DownloadFromGPUTexture(copy, &region, &destination)
        SDL_EndGPUCopyPass(copy)
        guard let fence = SDL_SubmitGPUCommandBufferAndAcquireFence(command) else { throw SDLError("SDL_SubmitGPUCommandBufferAndAcquireFence") }
        var fences: [OpaquePointer?] = [fence]
        _ = SDL_WaitForGPUFences(device, true, &fences, 1)
        SDL_ReleaseGPUFence(device, fence)
        guard let mapped = SDL_MapGPUTransferBuffer(device, transfer, false) else { throw SDLError("SDL_MapGPUTransferBuffer") }
        let data = Data(bytes: mapped, count: size)
        SDL_UnmapGPUTransferBuffer(device, transfer)
        return data
    }
}
