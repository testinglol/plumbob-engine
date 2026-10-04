import CSDL3
import Foundation
import SimsCore

/// SimsSDL: the cross-platform front end on SDL3 and SDL_GPU. For now it shows an exported lot scene.
///
///     SimsSDL --scene <dir/scene.json> [--png out.png] [--width 1280] [--height 960] [--zoom near|medium|far]
///             [--scale 2] [--no-lighting]
///
/// With --png it renders one frame offscreen and writes it out; otherwise it opens a window where the mouse wheel
/// zooms, the arrow keys or a right drag pan, and a left click prints the object and wall under the cursor.
struct Options {
    var scene: URL?
    var png: URL?
    var width = 1280
    var height = 960
    var zoom: LotZoom = .near
    var scale: Float = 2
    var lighting = true

    init(_ arguments: [String]) throws {
        var iterator = arguments.dropFirst().makeIterator()
        func value(_ name: String) throws -> String {
            guard let value = iterator.next() else { throw ContentError.invalid("\(name) needs a value") }
            return value
        }
        while let argument = iterator.next() {
            switch argument {
            case "--scene": scene = URL(fileURLWithPath: try value(argument))
            case "--png": png = URL(fileURLWithPath: try value(argument))
            case "--width": width = Int(try value(argument)) ?? width
            case "--height": height = Int(try value(argument)) ?? height
            case "--scale": scale = Float(try value(argument)) ?? scale
            case "--no-lighting": lighting = false
            case "--zoom":
                switch try value(argument) {
                case "far": zoom = .far
                case "medium": zoom = .medium
                default: zoom = .near
                }
            default: throw ContentError.invalid("Unknown argument \(argument)")
            }
        }
    }
}

final class RenderTargets {
    let color: GPUTexture
    let depth: GPUTexture
    init(gpu: GPUContext, width: Int, height: Int) throws {
        color = try gpu.makeTexture(width: width, height: height, format: GPUContext.colorFormat,
                                    usage: SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER)
        depth = try gpu.makeTexture(width: width, height: height, format: GPUContext.depthFormat, usage: SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET)
    }
}

func renderPNG(_ options: Options, renderer: LotRenderer, to url: URL) throws {
    let targets = try RenderTargets(gpu: renderer.gpu, width: options.width, height: options.height)
    guard let command = SDL_AcquireGPUCommandBuffer(renderer.gpu.device) else { throw SDLError("SDL_AcquireGPUCommandBuffer") }
    try renderer.encode(command: command, color: targets.color, depth: targets.depth)
    guard SDL_SubmitGPUCommandBuffer(command) else { throw SDLError("SDL_SubmitGPUCommandBuffer") }
    let pixels = try renderer.gpu.readPixels(targets.color)
    try PNGEncoder.encode(rgba: pixels, width: options.width, height: options.height).write(to: url)
}

func runWindow(_ options: Options, renderer: LotRenderer) throws {
    guard let window = SDL_CreateWindow("The Sims", Int32(options.width), Int32(options.height), CSDL_WINDOW_RESIZABLE | CSDL_WINDOW_HIGH_PIXEL_DENSITY) else {
        throw SDLError("SDL_CreateWindow")
    }
    defer { SDL_DestroyWindow(window) }
    let device = renderer.gpu.device
    guard SDL_ClaimWindowForGPUDevice(device, window) else { throw SDLError("SDL_ClaimWindowForGPUDevice") }
    defer { SDL_ReleaseWindowFromGPUDevice(device, window) }
    // The offscreen target holds sRGB-encoded colour; an sRGB swapchain keeps the blit from re-encoding it.
    if SDL_WindowSupportsGPUSwapchainComposition(device, window, SDL_GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR) {
        _ = SDL_SetGPUSwapchainParameters(device, window, SDL_GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR, SDL_GPU_PRESENTMODE_VSYNC)
    }
    var targets: RenderTargets?
    var dragging = false
    var running = true
    while running {
        var event = SDL_Event()
        while SDL_PollEvent(&event) {
            let density = SDL_GetWindowPixelDensity(window)
            switch SDL_EventType(event.type) {
            case SDL_EVENT_QUIT:
                running = false
            case SDL_EVENT_MOUSE_WHEEL:
                let levels = LotZoom.allCases.sorted { $0.rawValue < $1.rawValue }
                guard let current = levels.firstIndex(of: renderer.zoom) else { break }
                let next = min(levels.count - 1, max(0, current + (event.wheel.y > 0 ? 1 : event.wheel.y < 0 ? -1 : 0)))
                renderer.setZoom(levels[next])
            case SDL_EVENT_KEY_DOWN:
                let step: Float = 64
                switch event.key.key {
                case SDLK_LEFT: renderer.pan.x += step
                case SDLK_RIGHT: renderer.pan.x -= step
                case SDLK_UP: renderer.pan.y += step
                case SDLK_DOWN: renderer.pan.y -= step
                case SDLK_ESCAPE: running = false
                default: break
                }
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if event.button.button == UInt8(SDL_BUTTON_RIGHT) { dragging = true }
                if event.button.button == UInt8(SDL_BUTTON_LEFT), let targets {
                    let point = SIMD2(event.button.x, event.button.y) * density
                    let canvas = SIMD2(Float(targets.color.width), Float(targets.color.height))
                    let object = renderer.object(at: point, canvas: canvas)
                    let wall = renderer.wall(at: point, canvas: canvas)
                    print("click \(point): object \(object.map(String.init) ?? "none"), wall \(wall.map { "\($0)" } ?? "none")")
                }
            case SDL_EVENT_MOUSE_BUTTON_UP:
                if event.button.button == UInt8(SDL_BUTTON_RIGHT) { dragging = false }
            case SDL_EVENT_MOUSE_MOTION:
                if dragging { renderer.pan += SIMD2(event.motion.xrel, event.motion.yrel) * density }
            default: break
            }
        }
        // The simulation bridge posts its events to the main actor; let them run between frames.
        RunLoop.main.run(until: Date())
        guard let command = SDL_AcquireGPUCommandBuffer(device) else { throw SDLError("SDL_AcquireGPUCommandBuffer") }
        var swapchain: OpaquePointer?
        var width: UInt32 = 0
        var height: UInt32 = 0
        guard SDL_WaitAndAcquireGPUSwapchainTexture(command, window, &swapchain, &width, &height) else { throw SDLError("SDL_WaitAndAcquireGPUSwapchainTexture") }
        guard let swapchain, width > 0, height > 0 else {
            _ = SDL_SubmitGPUCommandBuffer(command)
            continue
        }
        if targets?.color.width != Int(width) || targets?.color.height != Int(height) {
            targets = try RenderTargets(gpu: renderer.gpu, width: Int(width), height: Int(height))
        }
        guard let targets else { continue }
        try renderer.encode(command: command, color: targets.color, depth: targets.depth)
        var blit = SDL_GPUBlitInfo()
        blit.source.texture = targets.color.handle
        blit.source.w = width
        blit.source.h = height
        blit.destination.texture = swapchain
        blit.destination.w = width
        blit.destination.h = height
        blit.load_op = SDL_GPU_LOADOP_DONT_CARE
        blit.filter = SDL_GPU_FILTER_NEAREST
        SDL_BlitGPUTexture(command, &blit)
        guard SDL_SubmitGPUCommandBuffer(command) else { throw SDLError("SDL_SubmitGPUCommandBuffer") }
    }
}

do {
    let options = try Options(CommandLine.arguments)
    guard SDL_Init(SDL_INIT_VIDEO) else { throw SDLError("SDL_Init") }
    defer { SDL_Quit() }
    let gpu = try GPUContext()
    let renderer = LotRenderer(gpu: gpu)
    renderer.uiScale = options.scale
    renderer.zoom = options.zoom
    renderer.lightingEnabled = options.lighting
    if let scene = options.scene { try renderer.loadScene(scene) }
    if let png = options.png {
        try renderPNG(options, renderer: renderer, to: png)
    } else {
        try runWindow(options, renderer: renderer)
    }
} catch {
    FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8))
    exit(1)
}
