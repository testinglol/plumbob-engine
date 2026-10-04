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
///             [--neighborhood 1] [--speed 0|1|3|10] [--answer-dialogs]
///
/// With --png it renders one frame offscreen and writes it out; otherwise it opens a window where the mouse wheel
/// zooms, the arrow keys or a right drag pan, and a left click prints the object and wall under the cursor. In a live
/// lot P pauses or resumes and 1, 2 and 3 pick normal, fast and fastest speed, as in the macOS client. Game dialogs are
/// printed; Y or Enter, N and C answer yes, no and cancel, and --answer-dialogs answers each with yes or OK.
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
    /// Answers every game dialog with its first choice, for unattended runs.
    var answerDialogs = false

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
            case "--answer-dialogs": answerDialogs = true
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
                renderer.queueAnimation(frame)
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
            // The host refuses speed changes while a blocking dialog is open, so the requested speed follows each answer.
            if event["type"] as? String == "response", event["operation"] as? String == "dialogResponse", event["ok"] as? Bool == true,
               let speed = options.speed {
                try bridge?.send("speed", ["value": speed])
            }
            for key in ["state", "result"] {
                guard let state = event[key] as? [String: Any], let dialogs = state["dialogs"] as? [[String: Any]] else { continue }
                let known = Set(renderer.dialogs.compactMap { $0["token"] as? String })
                renderer.dialogs = dialogs
                for dialog in dialogs where !known.contains(dialog["token"] as? String ?? "") {
                    let choices = LiveDialog.choices(dialog).map { "\($0.key) \($0.label)" }.joined(separator: ", ")
                    FileHandle.standardError.write(Data("SimsSDL: dialog \"\(dialog["title"] ?? "")\": \(dialog["message"] ?? "") [\(choices)]\n".utf8))
                    if options.answerDialogs, let token = dialog["token"] as? String {
                        try bridge?.send("dialogResponse", LiveDialog.response(dialog, token: token, code: 0))
                    }
                }
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

/// The host's game dialogs until the original dialog UI is ported: which choices a dialog kind offers and the
/// response that picks one, as the macOS client sends them.
enum LiveDialog {
    static func choices(_ dialog: [String: Any]) -> [(code: Int, key: String, label: String)] {
        func label(_ field: String, _ fallback: String) -> String { (dialog[field] as? String).flatMap { $0.isEmpty ? nil : $0 } ?? fallback }
        switch dialog["kind"] as? Int ?? 0 {
        case 1, 10: return [(0, "Y", label("yes", "Yes")), (1, "N", label("no", "No"))]
        case 2: return [(0, "Y", label("yes", "Yes")), (1, "N", label("no", "No")), (2, "C", label("cancel", "Cancel"))]
        default: return [(0, "Y", label("yes", "OK"))]
        }
    }

    static func response(_ dialog: [String: Any], token: String, code: Int) -> [String: Any] {
        // The phone book takes the chosen neighbour in its text; -1 hangs up.
        let text = dialog["kind"] as? Int == 10 ? "-1" : ""
        return ["token": token, "code": dialog["kind"] as? Int == 10 ? 0 : code, "text": text]
    }
}

@MainActor
func runWindow(_ options: Options, renderer: LotRenderer, bridge: SimulationBridge? = nil) throws {
    func sendSpeed(_ value: Int) {
        do { try bridge?.send("speed", ["value": value]) }
        catch { FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8)) }
    }
    /// Answers the oldest open dialog with a choice it offers: 0 yes or OK, 1 no, 2 cancel.
    func answerDialog(_ code: Int) {
        guard let dialog = renderer.dialogs.first, let token = dialog["token"] as? String,
              LiveDialog.choices(dialog).contains(where: { $0.code == code }) else { return }
        do { try bridge?.send("dialogResponse", LiveDialog.response(dialog, token: token, code: code)) }
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
    var framesInFlight: [OpaquePointer?] = []
    defer {
        if !framesInFlight.isEmpty { _ = SDL_WaitForGPUFences(device, true, &framesInFlight, UInt32(framesInFlight.count)) }
        for fence in framesInFlight { SDL_ReleaseGPUFence(device, fence) }
    }
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
                case SDLK_Y, SDLK_RETURN: answerDialog(0)
                case SDLK_N: answerDialog(1)
                case SDLK_C: answerDialog(2)
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
        do { try renderer.applyPendingAnimation(into: command) }
        catch { FileHandle.standardError.write(Data("SimsSDL: \(error)\n".utf8)) }
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
