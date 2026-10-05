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
    private var log: FileHandle?
    public var event: (([String: Any]) -> Void)?
    /// When set, animation events reach it already decoded, off the main thread, instead of through `event`; they are
    /// the bulk of the stream while a lot runs.
    public var animation: ((SceneAnimation) -> Void)?
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
        // The host streams several megabytes a second while a lot runs, in small pipe reads; lines are split and parsed on
        // the reading queue, and the main actor only receives whole messages.
        let reader = MessageReader(session: session, decodesAnimation: animation != nil)
        output.fileHandleForReading.readabilityHandler = { [weak self] handle in
            let messages = reader.receive(handle.availableData)
            guard !messages.isEmpty else { return }
            Task { @MainActor [weak self] in self?.deliver(messages) }
        }
        let discardsContent = discardsContentOnExit
        process.terminationHandler = { [weak self] child in
            let status = child.terminationStatus
            if discardsContent { SimulationBridge.discard(mount) }
            Task { @MainActor [weak self] in
                if status != 0 { self?.failed?("Simulation exited with status \(status)") }
                self?.output.fileHandleForReading.readabilityHandler = nil
            }
        }
        try process.run()
    }

    private nonisolated static let discardLock = NSLock()

    /// Deletes a session's content mount, reporting a failure on standard error rather than leaving gigabytes silently.
    /// The termination handler and `waitForExit` can both get here at once; Foundation on Linux gives up when the other
    /// removal deletes a file first, so removals take turns.
    nonisolated static func discard(_ mount: URL) {
        discardLock.lock()
        defer { discardLock.unlock() }
        guard FileManager.default.fileExists(atPath: mount.path) else { return }
        do { try FileManager.default.removeItem(at: mount) }
        catch { FileHandle.standardError.write(Data("Cannot remove content mount \(mount.path): \(error)\n".utf8)) }
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

    /// For a client about to exit: waits up to `timeout` seconds for the host to finish after `stop` (its autosave
    /// included), then discards the content mount if asked, since the termination handler may not get to run.
    @discardableResult
    public func waitForExit(timeout: TimeInterval) -> Bool {
        let deadline = Date().addingTimeInterval(timeout)
        while process.isRunning && Date() < deadline { Thread.sleep(forTimeInterval: 0.05) }
        guard !process.isRunning else { return false }
        if discardsContentOnExit { SimulationBridge.discard(session.appendingPathComponent("content")) }
        return true
    }

    private func deliver(_ messages: [MessageReader.Message]) {
        for message in messages {
            switch message {
            case .event(let box): event?(box.value)
            case .animation(let frame): animation?(frame.value)
            case .failure(let error):
                failed?(error)
                if error == MessageReader.sizeLimitError { stop() }
            }
        }
    }
}

/// Splits the host's output into JSON lines and parses them, off the main thread. Calls to `receive` are serialized by
/// the pipe's readability handler.
final class MessageReader: @unchecked Sendable {
    final class Box<Value>: @unchecked Sendable {
        let value: Value
        init(_ value: Value) { self.value = value }
    }
    enum Message: Sendable {
        case event(Box<[String: Any]>)
        case animation(Box<SceneAnimation>)
        case failure(String)
    }
    static let sizeLimitError = "Simulation message exceeds the protocol size limit"
    private static let animationPrefix = Array(#"{"type":"animation","#.utf8)
    private let root: String
    private let decodesAnimation: Bool
    private let decoder = JSONDecoder()
    private struct AnimationEvent: Decodable { let frame: SceneAnimation }
    /// The start of a line whose end has not arrived yet.
    private var partial: [UInt8] = []
    private var overflowed = false

    init(session: URL, decodesAnimation: Bool) {
        root = session.resolvingSymlinksInPath().standardizedFileURL.path
        self.decodesAnimation = decodesAnimation
    }

    func receive(_ data: Data) -> [Message] {
        guard !data.isEmpty, !overflowed else { return [] }
        var messages: [Message] = []
        data.withUnsafeBytes { (chunk: UnsafeRawBufferPointer) in
            let bytes = chunk.bindMemory(to: UInt8.self)
            var start = 0
            while let newline = bytes[start...].firstIndex(of: 10) {
                if partial.isEmpty {
                    messages.append(parse(UnsafeBufferPointer(rebasing: bytes[start..<newline])))
                } else {
                    partial.append(contentsOf: bytes[start..<newline])
                    messages.append(partial.withUnsafeBufferPointer { parse($0) })
                    partial.removeAll(keepingCapacity: partial.capacity <= 1 << 20)
                }
                start = newline + 1
            }
            partial.append(contentsOf: bytes[start...])
        }
        if partial.count > 16 * 1024 * 1024 {
            overflowed = true
            partial = []
            messages.append(.failure(Self.sizeLimitError))
        }
        return messages
    }

    private func parse(_ line: UnsafeBufferPointer<UInt8>) -> Message {
        do {
            if decodesAnimation, line.starts(with: Self.animationPrefix) {
                return .animation(Box(try decoder.decode(AnimationEvent.self, from: Data(buffer: line)).frame))
            }
            guard let message = try JSONSerialization.jsonObject(with: Data(buffer: line)) as? [String: Any] else {
                throw ContentError.invalid("Invalid simulation event")
            }
            if let scene = message["scene"] as? String {
                let url = URL(fileURLWithPath: scene).resolvingSymlinksInPath().standardizedFileURL
                guard url.path.hasPrefix(root + "/") else { throw ContentError.invalid("Simulation scene escapes session") }
            }
            return .event(Box(message))
        } catch { return .failure(String(describing: error)) }
    }
}
