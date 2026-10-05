import Foundation

/// Where a frame's time goes. With SIMS_PROFILE set, the main loop marks each phase, and every 120 frames the frame rate,
/// the average milliseconds per phase and the resident memory are logged.
@MainActor
struct FrameProfiler {
    let enabled = ProcessInfo.processInfo.environment["SIMS_PROFILE"] != nil
    private var totals: [String: UInt64] = [:]
    private var order: [String] = []
    private var last: UInt64 = 0
    private var windowStart: UInt64 = 0
    private var frames = 0

    mutating func begin() {
        guard enabled else { return }
        last = DispatchTime.now().uptimeNanoseconds
        if windowStart == 0 { windowStart = last }
    }

    mutating func mark(_ phase: String) {
        guard enabled else { return }
        let now = DispatchTime.now().uptimeNanoseconds
        if totals[phase] == nil { order.append(phase) }
        totals[phase, default: 0] += now - last
        last = now
    }

    mutating func endFrame() {
        guard enabled else { return }
        frames += 1
        guard frames == 120 else { return }
        let elapsed = Double(DispatchTime.now().uptimeNanoseconds - windowStart) / 1e9
        let phases = order.map { String(format: "%@ %.2f", $0, Double(totals[$0] ?? 0) / 1e6 / Double(frames)) }.joined(separator: ", ")
        EventProfiler.flush()
        log(String(format: "profile: %.1f fps, ms/frame: %@, rss %d MB", Double(frames) / elapsed, phases, Self.residentMegabytes()))
        totals.removeAll()
        order.removeAll()
        frames = 0
        windowStart = DispatchTime.now().uptimeNanoseconds
    }

    private static func residentMegabytes() -> Int {
        guard let statm = try? String(contentsOfFile: "/proc/self/statm", encoding: .utf8),
              let pages = statm.split(separator: " ").dropFirst().first.flatMap({ Int($0) }) else { return 0 }
        return pages * Int(sysconf(Int32(_SC_PAGESIZE))) / 1_048_576
    }
}

/// With SIMS_PROFILE set, the host events handled and the time spent per event type, logged every 120 frames with the frame profile.
/// Used from the main thread only.
enum EventProfiler {
    static let enabled = ProcessInfo.processInfo.environment["SIMS_PROFILE"] != nil
    nonisolated(unsafe) private static var totals: [String: (count: Int, nanoseconds: UInt64)] = [:]

    static func measure<T>(_ type: String, _ body: () throws -> T) rethrows -> T {
        guard enabled else { return try body() }
        let start = DispatchTime.now().uptimeNanoseconds
        defer {
            let entry = totals[type, default: (0, 0)]
            totals[type] = (entry.count + 1, entry.nanoseconds + DispatchTime.now().uptimeNanoseconds - start)
        }
        return try body()
    }

    static func flush() {
        guard enabled, !totals.isEmpty else { return }
        let summary = totals.sorted { $0.value.nanoseconds > $1.value.nanoseconds }
            .map { String(format: "%@ %d/%.0fms", $0.key, $0.value.count, Double($0.value.nanoseconds) / 1e6) }.joined(separator: ", ")
        log("events: \(summary)")
        totals.removeAll()
    }
}
