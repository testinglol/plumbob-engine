// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "SimsNative",
    platforms: [.macOS(.v14)],
    products: [.executable(name: "SimsNative", targets: ["SimsNative"])],
    targets: [
        .target(name: "SimsCore"),
        .executableTarget(name: "SimsNative", dependencies: ["SimsCore"]),
        .testTarget(name: "SimsCoreTests", dependencies: ["SimsCore"])
    ]
)
