// swift-tools-version: 6.0
import PackageDescription
import Foundation

// SimsCore, SimsClient (the simulation host bridge shared by both front ends) and their tests build everywhere.
// The SDL3 front end needs SDL3 (found through pkg-config); it always builds off macOS, and on macOS with SIMS_SDL=1 so
// the AppKit/Metal front end keeps building without SDL3 installed until SimsSDL replaces it.
var products: [Product] = []
var targets: [Target] = [
    .target(name: "SimsCore"),
    .target(name: "SimsClient", dependencies: ["SimsCore"]),
    .testTarget(name: "SimsCoreTests", dependencies: ["SimsCore"]),
    .testTarget(name: "SimsClientTests", dependencies: ["SimsClient", "SimsCore"])
]
#if os(macOS)
let buildsSDL = ProcessInfo.processInfo.environment["SIMS_SDL"] == "1"
#else
let buildsSDL = true
#endif
if buildsSDL {
    products.append(.executable(name: "SimsSDL", targets: ["SimsSDL"]))
    targets += [
        .systemLibrary(name: "CSDL3", pkgConfig: "sdl3", providers: [.brew(["sdl3"]), .apt(["libsdl3-dev"])]),
        .target(name: "CDrMP3"),
        .executableTarget(name: "SimsSDL", dependencies: ["SimsCore", "SimsClient", "CSDL3", "CDrMP3"], resources: [.copy("Shaders")])
    ]
}
#if os(macOS)
products.append(.executable(name: "SimsNative", targets: ["SimsNative"]))
targets.append(.executableTarget(name: "SimsNative", dependencies: ["SimsCore", "SimsClient"]))
#endif

let package = Package(
    name: "SimsNative",
    platforms: [.macOS(.v14)],
    products: products,
    targets: targets
)
