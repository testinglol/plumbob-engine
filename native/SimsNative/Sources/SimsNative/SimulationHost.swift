import Foundation
import SimsCore

/// Locates the .NET simulation host. A release bundle ships a self-contained publish in the workspace
/// (`native/SimsSimulation/bin/Release/net9.0`, recognized by `libhostfxr.dylib` next to the `SimsSimulation` executable),
/// so players need no .NET install. Developer builds use the system `dotnet` with `SimsSimulation.dll`.
enum SimulationHost {
    struct Launch {
        let executable: URL
        /// Arguments that come before the host's own arguments.
        let leadingArguments: [String]
    }

    static func resolve(workspace: URL, purpose: String) throws -> Launch {
        let manager = FileManager.default
        let directory = workspace.appendingPathComponent("native/SimsSimulation/bin/Release/net9.0", isDirectory: true)
        let bundled = directory.appendingPathComponent("SimsSimulation")
        if manager.isExecutableFile(atPath: bundled.path), manager.fileExists(atPath: directory.appendingPathComponent("libhostfxr.dylib").path) {
            return Launch(executable: bundled, leadingArguments: [])
        }
        let candidates = [ProcessInfo.processInfo.environment["DOTNET_HOST_PATH"], "/opt/homebrew/bin/dotnet", "/usr/local/share/dotnet/dotnet"].compactMap { $0 }
        guard let host = candidates.first(where: { manager.isExecutableFile(atPath: $0) }) else {
            throw ContentError.missing("The native \(purpose) requires .NET 9")
        }
        let module = directory.appendingPathComponent("SimsSimulation.dll")
        guard manager.fileExists(atPath: module.path) else { throw ContentError.missing("Build SimsSimulation before \(purpose)") }
        return Launch(executable: URL(fileURLWithPath: host), leadingArguments: [module.path])
    }
}
