import CSDL3
import Foundation
import SimsClient
import SimsCore

/// SimsSDL: the cross-platform front end on SDL3 and SDL_GPU. It plays the game through the simulation host from the
/// original neighborhood screen, opens one lot directly with --house, or shows an exported lot scene.
///
///     SimsSDL --scene <dir/scene.json> [--png out.png] [--width 1280] [--height 960] [--zoom near|medium|far]
///             [--scale 2] [--no-lighting]
///     SimsSDL [--house <1-100>] [--game <game dir>] [--workspace <repo>] [--data-root <dir>] [--profile player]
///             [--neighborhood 1] [--speed 0|1|3|10] [--answer-dialogs] [--no-audio] [--packs <dir>]
///     SimsSDL [--packs <dir>] --pack-report | --list-plugins | --trust-plugin <pack> | --revoke-plugin <pack>
///             | --allocate-object-guid <name> --pack-id <pack> | --reserve-object-guid <name> --pack-id <pack> | --mount <dir>
///
/// With --png it renders one frame offscreen and writes it out; otherwise it opens a window where the mouse wheel
/// zooms, the arrow keys or a right drag pan, and a left click prints the object and wall under the cursor. A live lot
/// plays with the original control panel, pie menus, dialogs and buy and build tools and the macOS client's keys
/// (P or space pause, 1-3 speeds, Tab next Sim, W walls, B buy, F build, R rotate, [ ] camera, S save, E pack panels);
/// --answer-dialogs answers each game dialog with its first choice.
struct Options {
    var scene: URL?
    var png: URL?
    var width = 1280
    var height = 960
    var zoom: LotZoom = .near
    /// Screen pixels per original pixel: 2 for --png by default, the window's pixel density in a window.
    var scale: Float?
    var lighting = true
    var audio = true
    var house: Int?
    var game: URL?
    var workspace: URL?
    var dataRoot: URL?
    var profile = "player"
    var neighborhood = 1
    /// The game speed to set once the lot is ready; the host loads a lot paused.
    var speed: Int?
    /// Answers every game dialog with its first choice, for unattended runs.
    var answerDialogs = false
    /// The custom pack collection (`docs/PACKS.md`); each child holding a `pack.json` is enabled.
    var packs: URL?
    /// A pack command to run instead of the game.
    var packCommand: PackTool.Command?

    init(_ arguments: [String]) throws {
        var iterator = arguments.dropFirst().makeIterator()
        var guidName: (name: String, reserve: Bool)?
        var packID: String?
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
            case "--no-audio": audio = false
            case "--house": house = Int(try value(argument))
            case "--game": game = URL(fileURLWithPath: try value(argument), isDirectory: true)
            case "--workspace": workspace = URL(fileURLWithPath: try value(argument), isDirectory: true)
            case "--data-root": dataRoot = URL(fileURLWithPath: try value(argument), isDirectory: true)
            case "--profile": profile = try value(argument)
            case "--neighborhood": neighborhood = Int(try value(argument)) ?? neighborhood
            case "--speed": speed = Int(try value(argument))
            case "--answer-dialogs": answerDialogs = true
            case "--packs": packs = URL(fileURLWithPath: try value(argument), isDirectory: true)
            case "--pack-report": packCommand = .report
            case "--list-plugins": packCommand = .listPlugins
            case "--mount": packCommand = .mount(try value(argument))
            case "--trust-plugin": packCommand = .trustPlugin(try value(argument))
            case "--revoke-plugin": packCommand = .revokePlugin(try value(argument))
            case "--allocate-object-guid": guidName = (try value(argument), false)
            case "--reserve-object-guid": guidName = (try value(argument), true)
            case "--pack-id": packID = try value(argument)
            case "--zoom":
                switch try value(argument) {
                case "far": zoom = .far
                case "medium": zoom = .medium
                default: zoom = .near
                }
            default: throw ContentError.invalid("Unknown argument \(argument)")
            }
        }
        if let guidName {
            guard let packID else { throw ContentError.invalid("Object allocation requires --pack-id") }
            packCommand = guidName.reserve ? .reserveObjectGUID(packID: packID, name: guidName.name) : .allocateObjectGUID(packID: packID, name: guidName.name)
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

@MainActor
func runWindow(_ options: Options, renderer: LotRenderer, live: LiveController? = nil) throws {
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
    var framesInFlight: [OpaquePointer?] = []
    defer {
        if !framesInFlight.isEmpty { _ = SDL_WaitForGPUFences(device, true, &framesInFlight, UInt32(framesInFlight.count)) }
        for fence in framesInFlight { SDL_ReleaseGPUFence(device, fence) }
    }
    var dragging = false
    var leftDown = false
    var debugFrame = 0
    var running = true
    var profiler = FrameProfiler()
    if live != nil { _ = SDL_StartTextInput(window) }
    func canvasSize() -> CGSize { CGSize(width: CGFloat(targets?.color.width ?? 1), height: CGFloat(targets?.color.height ?? 1)) }
    func liveKey(_ key: SDL_Keycode) -> LiveController.Key? {
        switch key {
        case SDLK_ESCAPE: return .escape
        case SDLK_RETURN, SDLK_KP_ENTER: return .enter
        case SDLK_BACKSPACE: return .backspace
        case SDLK_DELETE: return .delete
        case SDLK_TAB: return .tab
        case SDLK_LEFT: return .left
        case SDLK_RIGHT: return .right
        case SDLK_UP: return .up
        case SDLK_DOWN: return .down
        case SDLK_PAGEUP: return .pageUp
        case SDLK_PAGEDOWN: return .pageDown
        case SDLK_SPACE: return .character(" ")
        default:
            guard key >= 0x21, key < 0x7f, let scalar = Unicode.Scalar(key) else { return nil }
            return .character(String(Character(scalar)).lowercased())
        }
    }
    while running && live?.quitRequested != true {
        profiler.begin()
        var event = SDL_Event()
        while SDL_PollEvent(&event) {
            let density = SDL_GetWindowPixelDensity(window)
            switch SDL_EventType(event.type) {
            case SDL_EVENT_QUIT:
                running = false
            case SDL_EVENT_MOUSE_WHEEL:
                if let live { live.wheel(event.wheel.y); break }
                let levels = LotZoom.allCases.sorted { $0.rawValue < $1.rawValue }
                guard let current = levels.firstIndex(of: renderer.zoom) else { break }
                let next = min(levels.count - 1, max(0, current + (event.wheel.y > 0 ? 1 : event.wheel.y < 0 ? -1 : 0)))
                renderer.setZoom(levels[next])
            case SDL_EVENT_KEY_DOWN:
                if let live {
                    if let key = liveKey(event.key.key), live.key(key) { break }
                    // Arrow keys the game did not take scroll the view.
                    let step: Float = 64
                    switch event.key.key {
                    case SDLK_LEFT: live.pan(SIMD2(step, 0))
                    case SDLK_RIGHT: live.pan(SIMD2(-step, 0))
                    case SDLK_UP: live.pan(SIMD2(0, step))
                    case SDLK_DOWN: live.pan(SIMD2(0, -step))
                    default: break
                    }
                    break
                }
                let step: Float = 64
                switch event.key.key {
                case SDLK_LEFT: renderer.pan.x += step
                case SDLK_RIGHT: renderer.pan.x -= step
                case SDLK_UP: renderer.pan.y += step
                case SDLK_DOWN: renderer.pan.y -= step
                case SDLK_ESCAPE: running = false
                default: break
                }
            case SDL_EVENT_TEXT_INPUT:
                if let live, let text = event.text.text { live.text(String(cString: text)) }
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                let point = SIMD2(event.button.x, event.button.y) * density
                if event.button.button == UInt8(SDL_BUTTON_RIGHT) { dragging = true }
                if event.button.button == UInt8(SDL_BUTTON_LEFT) {
                    if let live {
                        let mods = SDL_GetModState()
                        leftDown = true
                        live.press(CGPoint(x: CGFloat(point.x), y: CGFloat(point.y)), canvas: canvasSize(),
                                   shift: mods & SDL_Keymod(SDL_KMOD_SHIFT) != 0, alt: mods & SDL_Keymod(SDL_KMOD_ALT) != 0)
                    } else if let targets {
                        let canvas = SIMD2(Float(targets.color.width), Float(targets.color.height))
                        let object = renderer.object(at: point, canvas: canvas)
                        let wall = renderer.wall(at: point, canvas: canvas)
                        print("click \(point): object \(object.map(String.init) ?? "none"), wall \(wall.map { "\($0)" } ?? "none")")
                    }
                }
            case SDL_EVENT_MOUSE_BUTTON_UP:
                if event.button.button == UInt8(SDL_BUTTON_RIGHT) { dragging = false }
                if event.button.button == UInt8(SDL_BUTTON_LEFT) {
                    leftDown = false
                    let point = SIMD2(event.button.x, event.button.y) * density
                    live?.release(CGPoint(x: CGFloat(point.x), y: CGFloat(point.y)))
                }
            case SDL_EVENT_MOUSE_MOTION:
                let point = SIMD2(event.motion.x, event.motion.y) * density
                let delta = SIMD2(event.motion.xrel, event.motion.yrel) * density
                let location = CGPoint(x: CGFloat(point.x), y: CGFloat(point.y))
                if let live {
                    if leftDown && live.primaryGesture { live.drag(location) }
                    else if dragging { live.pan(delta) }
                    else { live.hover(location, canvas: canvasSize()) }
                } else if dragging { renderer.pan += delta }
            case SDL_EVENT_WINDOW_MOUSE_LEAVE:
                live?.leave()
            default: break
            }
        }
        if options.scale == nil { renderer.uiScale = SDL_GetWindowPixelDensity(window) }
        // The simulation bridge posts its events to the main actor; let them run between frames.
        profiler.mark("events")
        RunLoop.main.run(until: Date())
        profiler.mark("host")
        guard let command = SDL_AcquireGPUCommandBuffer(device) else { throw SDLError("SDL_AcquireGPUCommandBuffer") }
        do { try renderer.applyPendingAnimation(into: command) }
        catch { FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8)) }
        profiler.mark("animation")
        var swapchain: OpaquePointer?
        var width: UInt32 = 0
        var height: UInt32 = 0
        guard SDL_WaitAndAcquireGPUSwapchainTexture(command, window, &swapchain, &width, &height) else { throw SDLError("SDL_WaitAndAcquireGPUSwapchainTexture") }
        profiler.mark("swapchain")
        guard let swapchain, width > 0, height > 0 else {
            _ = SDL_SubmitGPUCommandBuffer(command)
            continue
        }
        if targets?.color.width != Int(width) || targets?.color.height != Int(height) {
            targets = try RenderTargets(gpu: renderer.gpu, width: Int(width), height: Int(height))
        }
        guard let targets else { continue }
        if let live {
            debugFrame += 1
            if debugFrame % 120 == 0, ProcessInfo.processInfo.environment["SIMS_DEBUG"] != nil {
                log("frame \(debugFrame): pan \(renderer.pan) zoom \(renderer.zoom) scene \(renderer.sceneRoot?.path ?? "none")")
            }
            live.tick(canvas: CGSize(width: CGFloat(width), height: CGFloat(height)))
            live.prepareFrame()
            live.updateAudio()
            profiler.mark("tick")
            live.ui.roofsVisible = renderer.roofsVisible
            live.ui.viewLevel = renderer.viewLevel
            do {
                renderer.overlay = try live.ui.draws(canvas: SIMD2(Float(width), Float(height)), scale: renderer.uiScale, speed: renderer.speed)
                renderer.previewPlacement = live.ui.previewPlacement
                try renderer.gpu.batchingUploads(into: command) { try renderer.uploadOverlay() }
            } catch { FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8)) }
            profiler.mark("ui")
        }
        try renderer.encode(command: command, color: targets.color, depth: targets.depth)
        profiler.mark("encode")
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
        guard let fence = SDL_SubmitGPUCommandBufferAndAcquireFence(command) else { throw SDLError("SDL_SubmitGPUCommandBufferAndAcquireFence") }
        // Keep at most two frames queued. SDL's Vulkan backend gives every command buffer in flight its own descriptor-set
        // cache, sized for a whole frame of draws and never freed, so an unbounded queue (a slow GPU or software
        // rasteriser) grows descriptor memory until the driver fails.
        framesInFlight.append(fence)
        if framesInFlight.count > 2 {
            var oldest: OpaquePointer? = framesInFlight.removeFirst()
            _ = SDL_WaitForGPUFences(device, true, &oldest, 1)
            SDL_ReleaseGPUFence(device, oldest)
        }
        profiler.mark("gpu wait")
        profiler.endFrame()
    }
}

do {
    let options = try Options(CommandLine.arguments)
    if let command = options.packCommand {
        let workspace = options.workspace ?? defaultWorkspace()
        let content = try PackTool.loadContent(game: options.game ?? workspace.appendingPathComponent("runtime/game", isDirectory: true), packs: options.packs)
        FileHandle.standardOutput.write(try PackTool.run(command, content: content, dataRoot: options.dataRoot ?? workspace))
        FileHandle.standardOutput.write(Data([10]))
        exit(0)
    }
    guard SDL_Init(SDL_INIT_VIDEO) else { throw SDLError("SDL_Init") }
    defer { SDL_Quit() }
    let gpu = try GPUContext()
    let renderer = LotRenderer(gpu: gpu)
    renderer.uiScale = options.scale ?? 2
    renderer.zoom = options.zoom
    renderer.lightingEnabled = options.lighting
    if let scene = options.scene { try renderer.loadScene(scene) }
    if options.house != nil || (options.scene == nil && options.png == nil) {
        let live = try MainActor.assumeIsolated { try LiveController(options: options, house: options.house, renderer: renderer) }
        defer { MainActor.assumeIsolated { live.stop() } }
        try MainActor.assumeIsolated {
            live.loadPlayOptions()
            try runWindow(options, renderer: renderer, live: live)
        }
    } else if let png = options.png {
        try renderPNG(options, renderer: renderer, to: png)
    } else {
        try MainActor.assumeIsolated { try runWindow(options, renderer: renderer) }
    }
} catch {
    FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8))
    exit(1)
}
