import Foundation
import SimsCore

enum NeighborhoodExport {
    static func create(content: GameContent, workspace: URL, dataRoot: URL? = nil, mode: Int, profileID: String = "player", edit: String? = nil) async throws -> (session: URL, manifest: URL) {
        try await Task.detached(priority: .userInitiated) {
            try createSynchronously(content: content, workspace: workspace, dataRoot: dataRoot, mode: mode, profileID: profileID, edit: edit)
        }.value
    }

    static func createSynchronously(content: GameContent, workspace: URL, dataRoot: URL? = nil, mode: Int, profileID: String = "player", edit: String? = nil) throws -> (session: URL, manifest: URL) {
        guard (1...7).contains(mode) else { throw ContentError.invalid("Neighborhood mode must be 1..7") }
        let storageRoot = dataRoot ?? workspace
        let session = storageRoot.appendingPathComponent("runtime/native-sessions/neighborhood-" + UUID().uuidString, isDirectory: true)
        try FileManager.default.createDirectory(at: session, withIntermediateDirectories: true)
        let mount = session.appendingPathComponent("content", isDirectory: true)
        try content.materialize(at: mount)
        let launch = try SimulationHost.resolve(workspace: workspace, purpose: "opening the neighborhood")
        let log = session.appendingPathComponent("neighborhood-export.log")
        guard FileManager.default.createFile(atPath: log.path, contents: nil), let output = try? FileHandle(forWritingTo: log) else {
            throw ContentError.invalid("Cannot create neighborhood export log")
        }
        let process = Process()
        process.executableURL = launch.executable
        process.arguments = launch.leadingArguments + [mount.path, workspace.path, "--export-neighborhood", session.path, String(mode),
                             "--language", String(content.language.code), "--profile-id", profileID, "--data-root", storageRoot.path]
            + (edit.map { ["--edit", $0] } ?? [])
        process.environment = ProcessInfo.processInfo.environment.merging(["DOTNET_CLI_HOME": storageRoot.appendingPathComponent("runtime/dotnet").path], uniquingKeysWith: { _, replacement in replacement })
        process.standardOutput = FileHandle.nullDevice
        process.standardError = output
        try process.run()
        process.waitUntilExit()
        try output.close()
        guard process.terminationStatus == 0 else {
            let detail = (try? String(contentsOf: log, encoding: .utf8)) ?? ""
            throw ContentError.invalid("Neighborhood export failed (\(process.terminationStatus)): \(detail)")
        }
        let manifest = session.appendingPathComponent("neighborhood.json")
        guard FileManager.default.fileExists(atPath: manifest.path) else { throw ContentError.missing("Neighborhood export did not write its manifest") }
        return (session, manifest)
    }
}
