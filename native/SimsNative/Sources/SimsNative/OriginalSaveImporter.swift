import Foundation
import SimsCore

enum OriginalSaveImporter {
    static func run(gameRoot: URL, workspace: URL, dataRoot: URL? = nil, sourceDirectory: URL, profileID: String) async throws -> String {
        try await Task.detached(priority: .userInitiated) {
            try importSynchronously(gameRoot: gameRoot, workspace: workspace, dataRoot: dataRoot, sourceDirectory: sourceDirectory, profileID: profileID)
        }.value
    }

    static func importSynchronously(gameRoot: URL, workspace: URL, dataRoot: URL? = nil, sourceDirectory: URL, profileID: String) throws -> String {
        let storageRoot = dataRoot ?? workspace
        let manager = FileManager.default
        let launch = try SimulationHost.resolve(workspace: workspace, purpose: "importing an original save")
        let process = Process()
        let output = Pipe()
        process.executableURL = launch.executable
        process.arguments = launch.leadingArguments + ["--import-original-user-data", gameRoot.path, workspace.path, sourceDirectory.path, profileID,
                             "--data-root", storageRoot.path]
        process.environment = ProcessInfo.processInfo.environment.merging(["DOTNET_CLI_HOME": storageRoot.appendingPathComponent("runtime/dotnet").path], uniquingKeysWith: { _, replacement in replacement })
        process.standardOutput = output
        process.standardError = output
        try process.run()
        let data = output.fileHandleForReading.readDataToEndOfFile()
        process.waitUntilExit()
        guard process.terminationStatus == 0 else {
            throw ContentError.invalid(String(data: data, encoding: .utf8)?.trimmingCharacters(in: .whitespacesAndNewlines) ?? "Original save import failed")
        }
        guard let result = String(data: data, encoding: .utf8)?.trimmingCharacters(in: .whitespacesAndNewlines), !result.isEmpty else {
            throw ContentError.invalid("Original save import returned no result")
        }
        return result
    }
}
