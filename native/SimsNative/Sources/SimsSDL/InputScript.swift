import Foundation

/// Scripted input for `--script <file>`: drives a live window with the same press, release and key calls a player's
/// input reaches, so UI flows can be run and checked with screenshots without a person at the window. One command per
/// line; `#` starts a comment.
///
///     wait <frames>                 do nothing for this many frames
///     waitfor <condition> [frames]  wait until lot, menu, panel, dialog, nodialog, neighborhood, picker or creation
///                                   holds (default 1800 frames)
///     key <name>                    escape, enter, tab, backspace, space, home, end, f1-f4, or one character
///     click <x> <y>                 a left click at window pixels
///     clicksim <n>                  a left click on the n-th household Sim (Tab order, from 0)
///     choose <label>                a left click on the open pie menu's entry with this label (spaces allowed)
///     control <text>                a left click on the frontmost screen's first control whose label contains the text
///                                   (case-insensitive)
///     controls                      log the frontmost screen's control labels
///     type <text>                   typed text, as a keyboard's text input delivers it
///     shot <file.png>               write the next frame to a PNG
///     quit                          end the run (exit status 0)
///
/// A condition that times out, a Sim that is not on screen or a missing pie entry ends the run with exit status 2.
@MainActor
final class InputScript {
    enum Action { case none, shot(URL) }

    private var lines: [(number: Int, words: [String])]
    private var index = 0
    private var waitFrames = 0
    private var condition: (name: String, deadline: Int)?
    private var frame = 0
    private(set) var failed: String?

    init(_ url: URL) throws {
        let text = try String(contentsOf: url, encoding: .utf8)
        lines = text.split(separator: "\n", omittingEmptySubsequences: false).enumerated().compactMap { offset, line in
            let words = line.split(separator: "#", maxSplits: 1, omittingEmptySubsequences: false).first?
                .split(separator: " ", omittingEmptySubsequences: true).map(String.init) ?? []
            return words.isEmpty ? nil : (offset + 1, words)
        }
    }

    /// Runs the commands due this frame, after the controller's tick. Returns what the main loop must do for it.
    func step(_ live: LiveController) -> Action {
        frame += 1
        if waitFrames > 0 { waitFrames -= 1; return .none }
        if let pending = condition {
            if holds(pending.name, live) { condition = nil }
            else if frame >= pending.deadline { fail("waitfor \(pending.name) timed out", live); return .none }
            else { return .none }
        }
        while index < lines.count, !live.quitRequested {
            let (number, words) = lines[index]
            index += 1
            let argument = words.dropFirst().joined(separator: " ")
            log("script \(number): \(words.joined(separator: " "))")
            switch words[0] {
            case "wait":
                waitFrames = Int(argument) ?? 1
                return .none
            case "waitfor":
                let frames = words.count > 2 ? Int(words[2]) ?? 1800 : 1800
                guard ["lot", "menu", "panel", "dialog", "nodialog", "neighborhood", "picker", "creation"].contains(words.count > 1 ? words[1] : "") else {
                    fail("line \(number): unknown condition", live); return .none
                }
                condition = (words[1], frame + frames)
                return .none
            case "key":
                let key: LiveController.Key
                switch argument {
                case "escape": key = .escape
                case "enter": key = .enter
                case "tab": key = .tab
                case "backspace": key = .backspace
                case "space": key = .character(" ")
                case "home": key = .home
                case "end": key = .end
                case "f1", "f2", "f3", "f4": key = .function(Int(argument.dropFirst())!)
                default: key = .character(argument.lowercased())
                }
                _ = live.key(key)
                return .none
            case "click":
                guard words.count == 3, let x = Double(words[1]), let y = Double(words[2]) else { fail("line \(number): click needs x y", live); return .none }
                click(CGPoint(x: x, y: y), live)
                return .none
            case "clicksim":
                guard let n = Int(argument), live.scriptSimIDs.indices.contains(n) else { fail("line \(number): no Sim \(argument)", live); return .none }
                guard let point = live.scriptPoint(onObject: live.scriptSimIDs[n]) else { fail("line \(number): Sim \(argument) is not on screen", live); return .none }
                log("script: Sim \(n) at \(Int(point.x)),\(Int(point.y))")
                click(point, live)
                return .none
            case "choose":
                guard let point = live.scriptPoint(onMenuEntry: argument) else { fail("line \(number): no pie entry \(argument)", live); return .none }
                click(point, live)
                return .none
            case "control":
                let needle = argument.lowercased()
                guard !needle.isEmpty, let control = live.scriptControls.first(where: { $0.label.lowercased().contains(needle) }) else {
                    fail("line \(number): no control \(argument)", live); return .none
                }
                click(CGPoint(x: control.rect.midX, y: control.rect.midY), live)
                return .none
            case "controls":
                for control in live.scriptControls { log("control: \(control.label) at \(Int(control.rect.midX)),\(Int(control.rect.midY))") }
            case "type":
                live.text(argument)
                return .none
            case "shot":
                return .shot(URL(fileURLWithPath: argument))
            case "quit":
                live.quitRequested = true
                return .none
            default:
                fail("line \(number): unknown command \(words[0])", live)
                return .none
            }
        }
        return .none
    }

    private func click(_ point: CGPoint, _ live: LiveController) {
        live.hover(point, canvas: live.scriptCanvas)
        live.press(point, canvas: live.scriptCanvas, shift: false, alt: false)
        live.release(point)
    }

    private func holds(_ name: String, _ live: LiveController) -> Bool {
        switch name {
        case "lot": return live.ui.showsLot && !live.scriptSimIDs.isEmpty
        case "menu": return live.ui.pieMenu != nil
        case "panel": return live.ui.pluginPanel != nil
        case "dialog": return live.ui.gameDialog != nil
        case "neighborhood", "picker", "creation": return live.ui.gameDialog == nil && live.scriptScreen == name
        default: return live.ui.gameDialog == nil
        }
    }

    private func fail(_ message: String, _ live: LiveController) {
        failed = message
        log("script failed: \(message)")
        live.quitRequested = true
    }
}
