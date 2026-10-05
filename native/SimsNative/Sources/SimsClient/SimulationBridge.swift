import Foundation
import SimsCore

@MainActor
public final class SimulationBridge {
    public let workspace: URL
    public let dataRoot: URL
    public let session: URL
    public let process = Process()
    let input = Pipe()
    let output = Pipe()
    private var buffer = Data()
    /// How much of `buffer` is known to hold no newline, so each chunk scans only the new bytes.
    private var scanned = 0
    private var log: FileHandle?
    public var event: (([String: Any]) -> Void)?
    public var failed: ((String) -> Void)?
    private var sequence = 0
    /// Deletes the session's copy of the game once the host exits. Where the mount is not a clone it costs gigabytes per lot.
    public var discardsContentOnExit = false

    public init(workspace: URL, dataRoot: URL? = nil, profileID: String = "player", neighborhood: Int = 1) {
        self.workspace = workspace
        self.dataRoot = dataRoot ?? workspace
        self.profileID = profileID
        self.neighborhood = neighborhood
        session = self.dataRoot.appendingPathComponent("runtime/native-sessions/" + UUID().uuidString)
    }

    public let profileID: String
    /// The numbered neighborhood (`UserData` is 1) whose lots and saves the host uses.
    public let neighborhood: Int

    public func start(content: GameContent, house: Int) throws {
        guard house > 0 && house <= 100 else { throw ContentError.invalid("House must be 1..100") }
        try launch(content: content, purpose: "starting live gameplay", mode: ["--serve", session.path, String(house)])
    }

    /// Starts an audio-only host for the loading screen and neighborhood maps, before any lot is loaded.
    public func startFrontendAudio(content: GameContent) throws {
        try launch(content: content, purpose: "playing neighborhood audio", mode: ["--serve-audio", session.path])
    }

    private func launch(content: GameContent, purpose: String, mode: [String]) throws {
        let manager = FileManager.default
        try manager.createDirectory(at: session, withIntermediateDirectories: true)
        let mount = session.appendingPathComponent("content")
        try content.materialize(at: mount)
        let launch = try SimulationHost.resolve(workspace: workspace, purpose: purpose)
        let logURL = session.appendingPathComponent("simulation.log")
        manager.createFile(atPath: logURL.path, contents: nil)
        log = try FileHandle(forWritingTo: logURL)
        process.executableURL = launch.executable
        process.arguments = launch.leadingArguments + [mount.path, workspace.path] + mode +
                            ["--language", String(content.language.code), "--profile-id", profileID, "--data-root", dataRoot.path,
                             "--neighborhood", String(neighborhood)]
        process.environment = ProcessInfo.processInfo.environment.merging(["DOTNET_CLI_HOME": dataRoot.appendingPathComponent("runtime/dotnet").path], uniquingKeysWith: { _, replacement in replacement })
        process.standardInput = input
        process.standardOutput = output
        process.standardError = log
        output.fileHandleForReading.readabilityHandler = { [weak self] handle in
            let data = handle.availableData
            Task { @MainActor [weak self] in self?.receive(data) }
        }
        let discardsContent = discardsContentOnExit
        process.terminationHandler = { [weak self] child in
            let status = child.terminationStatus
            if discardsContent { try? FileManager.default.removeItem(at: mount) }
            Task { @MainActor [weak self] in
                if status != 0 { self?.failed?("Simulation exited with status \(status)") }
                self?.output.fileHandleForReading.readabilityHandler = nil
            }
        }
        try process.run()
    }

    @discardableResult
    public func send(_ operation: String, _ parameters: [String: Any] = [:]) throws -> String {
        guard process.isRunning else { throw ContentError.invalid("Simulation is not running") }
        sequence += 1
        var message = parameters
        message["op"] = operation
        message["id"] = String(sequence)
        var data = try JSONSerialization.data(withJSONObject: message)
        data.append(10)
        try input.fileHandleForWriting.write(contentsOf: data)
        return String(sequence)
    }

    public func stop(save: Bool = true) {
        if process.isRunning {
            if save { _ = try? send("save", ["slot": "autosave"]) }
            _ = try? send("quit")
        }
        try? input.fileHandleForWriting.close()
        output.fileHandleForReading.readabilityHandler = nil
    }

    private func receive(_ data: Data) {
        guard !data.isEmpty else { return }
        buffer.append(data)
        guard buffer.count <= 16 * 1024 * 1024 else {
            failed?("Simulation message exceeds the protocol size limit")
            stop()
            return
        }
        while let newline = buffer[(buffer.startIndex + scanned)...].firstIndex(of: 10) {
            let line = buffer[buffer.startIndex..<newline]
            buffer = buffer[(newline + 1)...]
            scanned = 0
            do {
                guard let message = try JSONSerialization.jsonObject(with: line) as? [String: Any] else { throw ContentError.invalid("Invalid simulation event") }
                if let scene = message["scene"] as? String {
                    let url = URL(fileURLWithPath: scene).resolvingSymlinksInPath().standardizedFileURL
                    let root = session.resolvingSymlinksInPath().standardizedFileURL
                    guard url.path.hasPrefix(root.path + "/") else { throw ContentError.invalid("Simulation scene escapes session") }
                }
                event?(message)
            } catch { failed?(String(describing: error)) }
        }
        scanned = buffer.count
    }
}
