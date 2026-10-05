import Foundation
import SimsCore

public enum NeighborhoodExport {
    public static func create(content: GameContent, workspace: URL, dataRoot: URL? = nil, mode: Int, profileID: String = "player", edit: String? = nil,
                       neighborhood: Int = 1, discardsContent: Bool = false) async throws -> (session: URL, manifest: URL) {
        try await Task.detached(priority: .userInitiated) {
            try createSynchronously(content: content, workspace: workspace, dataRoot: dataRoot, mode: mode, profileID: profileID, edit: edit,
                                    neighborhood: neighborhood, discardsContent: discardsContent)
        }.value
    }

    public static func createSynchronously(content: GameContent, workspace: URL, dataRoot: URL? = nil, mode: Int, profileID: String = "player", edit: String? = nil,
                                    neighborhood: Int = 1, discardsContent: Bool = false) throws -> (session: URL, manifest: URL) {
        guard (1...7).contains(mode) else { throw ContentError.invalid("Neighborhood mode must be 1..7") }
        guard (1...99).contains(neighborhood) else { throw ContentError.invalid("Neighborhood number must be 1..99") }
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
                             "--language", String(content.language.code), "--profile-id", profileID, "--data-root", storageRoot.path,
                             "--neighborhood", String(neighborhood)]
            + (edit.map { ["--edit", $0] } ?? [])
        process.environment = ProcessInfo.processInfo.environment.merging(["DOTNET_CLI_HOME": storageRoot.appendingPathComponent("runtime/dotnet").path], uniquingKeysWith: { _, replacement in replacement })
        process.standardOutput = FileHandle.nullDevice
        process.standardError = output
        try process.run()
        process.waitUntilExit()
        // The export only reads the mount; its images and manifest live beside it in the session.
        if discardsContent { try? FileManager.default.removeItem(at: mount) }
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
