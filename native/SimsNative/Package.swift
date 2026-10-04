// swift-tools-version: 6.0
import PackageDescription

// SimsCore and its tests build everywhere. The AppKit/Metal front end is macOS-only until the SDL3 front end replaces it.
var products: [Product] = []
var targets: [Target] = [
    .target(name: "SimsCore"),
    .testTarget(name: "SimsCoreTests", dependencies: ["SimsCore"])
]
#if os(macOS)
products.append(.executable(name: "SimsNative", targets: ["SimsNative"]))
targets.append(.executableTarget(name: "SimsNative", dependencies: ["SimsCore"]))
#endif

let package = Package(
    name: "SimsNative",
    platforms: [.macOS(.v14)],
    products: products,
    targets: targets
)
