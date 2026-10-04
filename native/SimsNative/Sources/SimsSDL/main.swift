import CSDL3
import Foundation
import SimsClient
import SimsCore

/// SimsSDL: the cross-platform front end on SDL3 and SDL_GPU. For now it shows an exported lot scene, or plays a lot
/// live through the simulation host.
///
///     SimsSDL --scene <dir/scene.json> [--png out.png] [--width 1280] [--height 960] [--zoom near|medium|far]
///             [--scale 2] [--no-lighting]
///     SimsSDL --house <1-100> [--game <game dir>] [--workspace <repo>] [--data-root <dir>] [--profile player]
///             [--neighborhood 1] [--speed 0|1|3|10]
///
/// With --png it renders one frame offscreen and writes it out; otherwise it opens a window where the mouse wheel
/// zooms, the arrow keys or a right drag pan, and a left click prints the object and wall under the cursor. In a live
/// lot P pauses or resumes and 1, 2 and 3 pick normal, fast and fastest speed, as in the macOS client.
struct Options {
    var scene: URL?
    var png: URL?
    var width = 1280
    var height = 960
    var zoom: LotZoom = .near
    /// Screen pixels per original pixel: 2 for --png by default, the window's pixel density in a window.
    var scale: Float?
    var lighting = true
    var house: Int?
    var game: URL?
    var workspace: URL?
    var dataRoot: URL?
    var profile = "player"
    var neighborhood = 1
    /// The game speed to set once the lot is ready; the host loads a lot paused.
    var speed: Int?

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
            case "--scale": scale = Float(try value(argument))
            case "--no-lighting": lighting = false
            case "--house": house = Int(try value(argument))
            case "--game": game = URL(fileURLWithPath: try value(argument), isDirectory: true)
            case "--workspace": workspace = URL(fileURLWithPath: try value(argument), isDirectory: true)
            case "--data-root": dataRoot = URL(fileURLWithPath: try value(argument), isDirectory: true)
            case "--profile": profile = try value(argument)
            case "--neighborhood": neighborhood = Int(try value(argument)) ?? neighborhood
            case "--speed": speed = Int(try value(argument))
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

/// The repository checkout: the nearest directory above the executable (or the current directory) holding
/// `native/SimsSimulation`, where the simulation host is built.
func defaultWorkspace() -> URL {
    let manager = FileManager.default
    let starts = [URL(fileURLWithPath: CommandLine.arguments[0]).resolvingSymlinksInPath().deletingLastPathComponent(),
                  URL(fileURLWithPath: manager.currentDirectoryPath, isDirectory: true)]
    for start in starts {
        var directory = start.standardizedFileURL
        while directory.path != "/" {
            if manager.fileExists(atPath: directory.appendingPathComponent("native/SimsSimulation").path) { return directory }
            directory.deleteLastPathComponent()
        }
    }
    return starts[1]
}

/// Plays a lot through the simulation host: each scene snapshot replaces the renderer's scene (and is acknowledged so
/// the host starts streaming animation against it), and animation frames update it in place.
@MainActor
func startLive(_ options: Options, house: Int, renderer: LotRenderer) throws -> SimulationBridge {
    let workspace = options.workspace ?? defaultWorkspace()
    let game = options.game ?? workspace.appendingPathComponent("runtime/game", isDirectory: true)
    let content = try GameContent(root: game)
    let bridge = SimulationBridge(workspace: workspace, dataRoot: options.dataRoot, profileID: options.profile, neighborhood: options.neighborhood)
    renderer.liveMode = true
    bridge.event = { [weak bridge] event in
        do {
            if let scene = event["scene"] as? String {
                let revision = (event["revision"] as? NSNumber)?.int64Value ?? 0
                try renderer.loadScene(URL(fileURLWithPath: scene), revision: revision)
                if revision > 0 { try bridge?.send("sceneAck", ["revision": revision]) }
            }
            if event["type"] as? String == "animation", let frame = event["frame"] as? [String: Any] {
                let animation = try JSONDecoder().decode(SceneAnimation.self, from: JSONSerialization.data(withJSONObject: frame))
                try renderer.applyAnimation(animation)
            }
            for key in ["state", "result"] {
                if let state = event[key] as? [String: Any], let speed = state["speed"] as? Int { renderer.speed = speed }
            }
            if event["type"] as? String == "hello" {
                try bridge?.send("audio", ["enabled": false])
                try bridge?.send("stream", ["enabled": true])
                if let speed = options.speed { try bridge?.send("speed", ["value": speed]) }
            }
            if event["type"] as? String == "response", event["ok"] as? Bool == false {
                FileHandle.standardError.write(Data("SimsSDL: \(event["operation"] ?? "request") failed: \(event["error"] ?? "")\n".utf8))
            }
            if let state = event["state"] as? [String: Any], let dialogs = state["dialogs"] as? [Any], !dialogs.isEmpty {
                FileHandle.standardError.write(Data("SimsSDL: dialogs \(dialogs)\n".utf8))
            }
            if event["type"] as? String == "response", event["ok"] as? Bool == false {
                FileHandle.standardError.write(Data("SimsSDL: \(event["operation"] ?? "request") failed: \(event["error"] ?? "")\n".utf8))
            }
            if let state = event["state"] as? [String: Any], let dialogs = state["dialogs"] as? [Any], !dialogs.isEmpty {
                FileHandle.standardError.write(Data("SimsSDL: dialogs \(dialogs)\n".utf8))
            }
            if event["type"] as? String == "error" { FileHandle.standardError.write(Data("SimsSDL: host error \(event)\n".utf8)) }
        } catch {
            FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8))
        }
    }
    bridge.failed = { error in FileHandle.standardError.write(Data("SimsSDL: \(error) (log: \(bridge.session.path)/simulation.log)\n".utf8)) }
    try bridge.start(content: content, house: house)
    FileHandle.standardError.write(Data("SimsSDL: live session \(bridge.session.path)\n".utf8))
    return bridge
}

@MainActor
func runWindow(_ options: Options, renderer: LotRenderer, bridge: SimulationBridge? = nil) throws {
    func sendSpeed(_ value: Int) {
        do { try bridge?.send("speed", ["value": value]) }
        catch { FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8)) }
    }
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
                case SDLK_P: sendSpeed(renderer.speed == 0 ? 1 : 0)
                case SDLK_1: sendSpeed(1)
                case SDLK_2: sendSpeed(3)
                case SDLK_3: sendSpeed(10)
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
        if options.scale == nil { renderer.uiScale = SDL_GetWindowPixelDensity(window) }
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
    renderer.uiScale = options.scale ?? 2
    renderer.zoom = options.zoom
    renderer.lightingEnabled = options.lighting
    if let scene = options.scene { try renderer.loadScene(scene) }
    if let house = options.house {
        let bridge = try MainActor.assumeIsolated { try startLive(options, house: house, renderer: renderer) }
        defer { MainActor.assumeIsolated { bridge.stop() } }
        try MainActor.assumeIsolated { try runWindow(options, renderer: renderer, bridge: bridge) }
    } else if let png = options.png {
        try renderPNG(options, renderer: renderer, to: png)
    } else {
        try MainActor.assumeIsolated { try runWindow(options, renderer: renderer) }
    }
} catch {
    FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8))
    exit(1)
}
