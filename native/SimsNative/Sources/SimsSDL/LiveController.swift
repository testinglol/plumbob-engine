import Foundation
import SimsClient
import SimsCore

/// Plays a lot through the simulation host with the original UI: the macOS client's live-mode game logic (its app
/// delegate's event handling, clicks, hover, keys and the buy and build tools) on SDL input. Points are in canvas pixels.
@MainActor
final class LiveController {
    let bridge: SimulationBridge
    let renderer: LotRenderer
    let ui: LiveUI
    let options: Options
    private var strings: OriginalUIStrings { ui.strings }

    private struct MenuRequest { let id: String; let object: Int; let caller: Int; let anchor: CGPoint }
    private struct PlacementKey: Equatable {
        let target: BuySelection.Target
        let tile: GroundTile
        let direction: Int
        let revision: Int64
        let level: Int
    }

    private var selectedSim = 0
    private var simIDs: [Int] = []
    private var pendingMenu: MenuRequest?
    private var pendingCatalog: String?
    private var pendingBuildCatalog: String?
    private var pendingPlacement: (id: String, key: PlacementKey)?
    private var desiredPlacement: PlacementKey?
    private var checkedPlacement: PlacementKey?
    private var editableObjects: [EditableLotObject] = []
    private var pendingResponseSounds: [String: (success: String, failure: String?)] = [:]
    private var pendingSaveRequests: Set<String> = []
    private var lastPieHighlight: Int?
    private var lastCutawayTile: String?
    private var localDialogToken: String?
    private var localDialogResponse: ((UInt8) -> Void)?
    private var answeredDialogs: Set<String> = []
    /// The last pointer position over the window, for placement previews refreshed by host state.
    private(set) var pointer: CGPoint?
    private var canvas = CGSize(width: 1, height: 1)
    private var wallStroke: (start: LotVertex, style: UInt16, pattern: UInt16, rectangle: Bool, deleting: Bool)?
    private var wallBrush: WallBrushSelection?
    private var floorStroke: (start: GroundTile, pattern: UInt16, selection: UInt16?, deleting: Bool)?
    private var floorBrush: FloorBrushSelection?
    private var terrainStrokeMode: TerrainBrushMode?
    private var terrainStrokeStartPoint: CGPoint?
    private var terrainGesture = TerrainBrushGesture()
    /// A left press that started a build stroke; its drags and release go to the stroke instead of panning the view.
    private(set) var primaryGesture = false
    var quitRequested = false

    init(options: Options, house: Int, renderer: LotRenderer) throws {
        let workspace = options.workspace ?? defaultWorkspace()
        let game = options.game ?? workspace.appendingPathComponent("runtime/game", isDirectory: true)
        let content = try GameContent(root: game)
        self.options = options
        self.renderer = renderer
        bridge = SimulationBridge(workspace: workspace, dataRoot: options.dataRoot, profileID: options.profile, neighborhood: options.neighborhood)
        ui = try LiveUI(content: content)
        renderer.liveMode = true
        bridge.event = { [weak self] event in self?.simulationEvent(event) }
        bridge.failed = { [weak bridge] error in
            log("\(error) (log: \(bridge?.session.path ?? "")/simulation.log)")
        }
        try bridge.start(content: content, house: house)
        log("live session \(bridge.session.path)")
    }

    // MARK: Requests

    private func send(_ operation: String, _ parameters: [String: Any] = [:]) -> String? {
        do { return try bridge.send(operation, parameters) }
        catch { log("\(operation): \(error)"); return nil }
    }

    func playUISound(_ name: String) { _ = send("audioEvent", ["name": name]) }

    private func playUISoundOnResponse(_ id: String?, success: String, failure: String? = "ui_error") {
        guard let id else { return }
        pendingResponseSounds[id] = (success, failure)
    }

    @discardableResult
    private func sendWithBuildSound(_ operation: String, _ parameters: [String: Any]) -> String? {
        let id = send(operation, parameters)
        playUISoundOnResponse(id, success: "ui_bld_dragtool_place")
        return id
    }

    func sendSpeed(_ value: Int) {
        if value > 0, ui.buyMode || ui.buildMode { return }
        guard send("speed", ["value": value]) != nil else { return }
        if let sound = Self.speedTransitionSound(from: renderer.speed, to: value) { playUISound(sound) }
    }

    /// Original HIT events for speed-control transitions (`ui_speed_1to2`, `ui_speed_pto3`, …); P is pause.
    static func speedTransitionSound(from current: Int, to requested: Int) -> String? {
        func code(_ speed: Int) -> String? { speed == 0 ? "p" : (1...3).contains(speed) ? String(speed) : nil }
        guard current != requested, let from = code(current), let to = code(requested) else { return nil }
        return "ui_speed_\(from)to\(to)"
    }

    private var scale: CGFloat { CGFloat(renderer.uiScale) }
    private var logicalCanvas: CGSize { CGSize(width: canvas.width / scale, height: canvas.height / scale) }
    private func local(_ point: CGPoint) -> CGPoint { CGPoint(x: point.x / scale, y: point.y / scale) }
    private func simd(_ point: CGPoint) -> SIMD2<Float> { SIMD2(Float(point.x), Float(point.y)) }
    private var simdCanvas: SIMD2<Float> { SIMD2(Float(canvas.width), Float(canvas.height)) }

    // MARK: Modes

    func dismissMenu() {
        wallStroke = nil
        wallBrush = nil
        floorStroke = nil
        floorBrush = nil
        terrainStrokeMode = nil
        terrainStrokeStartPoint = nil
        terrainGesture = TerrainBrushGesture()
        pendingMenu = nil
        ui.pieMenu = nil
        ui.buy.cancelSelection()
        ui.build.cancelSelection()
        desiredPlacement = nil
        checkedPlacement = nil
        try? renderer.updatePlacement(nil)
    }

    func browseBuyCatalog() {
        guard ui.gameDialog == nil else { return }
        dismissMenu()
        ui.buildMode = false
        pendingBuildCatalog = nil
        ui.buyMode.toggle()
        editingViewChanged()
        playUISound(ui.buyMode ? "bkground_buy1" : "bkground_live")
        pendingCatalog = nil
        if ui.buyMode {
            sendSpeed(0)
            ui.buy.clear(category: 0)
            requestCatalog(category: 0, offset: 0)
        }
    }

    func browseBuildCatalog() {
        guard ui.gameDialog == nil else { return }
        dismissMenu()
        ui.buyMode = false
        pendingCatalog = nil
        ui.buildMode.toggle()
        editingViewChanged()
        playUISound(ui.buildMode ? "bkground_build" : "bkground_live")
        pendingBuildCatalog = nil
        if ui.buildMode {
            sendSpeed(0)
            ui.build.changeKind(.floor)
            requestBuildCatalog(offset: 0)
        }
    }

    private func editingViewChanged() { _ = send("view", ["editing": ui.buyMode || ui.buildMode]) }

    private func requestBuildCatalog(offset: Int) {
        let count = OriginalBuildLayout.capacity(canvas: logicalCanvas)
        if let category = ui.build.objectTool?.category {
            pendingBuildCatalog = send("catalogPage", ["category": category, "offset": offset, "count": count])
        } else {
            pendingBuildCatalog = send("buildCatalogPage", ["kind": ui.build.kind.rawValue, "offset": offset, "count": count])
        }
    }

    private func requestCatalog(category: Int, offset: Int) {
        pendingCatalog = send("catalogPage", ["category": category, "offset": offset, "count": OriginalBuyLayout.capacity(canvas: logicalCanvas)])
    }

    func selectStory(_ level: Int) {
        guard ui.gameDialog == nil, (1...renderer.storyCount).contains(level), level != renderer.viewLevel || renderer.roofsVisible else { return }
        dismissMenu()
        ui.buy.selection.cancel()
        try? renderer.updateFloorBrush(nil)
        _ = send("level", ["value": level])
    }

    func nextSim() {
        dismissMenu()
        guard !simIDs.isEmpty else { return }
        let current = simIDs.firstIndex(of: selectedSim) ?? -1
        _ = send("selectSim", ["objectID": simIDs[(current + 1) % simIDs.count]])
    }

    func toggleWalls() { dismissMenu(); _ = send("walls", ["up": !ui.wallsUp]) }

    func rotateCamera(_ delta: Int) {
        let next = (renderer.cameraOrientation.rawValue + delta + 4) % 4
        _ = send("cameraOrientation", ["value": next])
    }

    func enterOptionsMode() {
        guard ui.gameDialog == nil else { return }
        dismissMenu()
        if ui.buyMode { browseBuyCatalog() } else if ui.buildMode { browseBuildCatalog() }
        ui.optionsPanel.select(.none)
        ui.optionsMode = true
        playUISound("ui_click")
    }

    func leaveOptionsMode() {
        guard ui.optionsMode else { return }
        ui.optionsMode = false
        ui.optionsPanel.select(.none)
    }

    private func chooseOption(_ button: OriginalOptionsPanelOverlay.Button) {
        playUISound("ui_click")
        switch button {
        case .save: saveGame()
        case .sound:
            presentLocalFeedback(title: strings.soundOptionsTitle(), message: "Sound options are not available in this client yet.")
        case .neighborhood:
            presentLocalFeedback(title: strings.saveMenuTitle(), message: "The neighborhood is not available in this client yet.")
        case .quit:
            presentLocalConfirmation(title: strings.quitTitle(), message: strings.quitMessage(), yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
                guard code == 0, let self else { return }
                self.presentLocalConfirmation(title: self.strings.quitTitle(), message: self.strings.saveBeforeQuitMessage(),
                                              yes: self.strings.yesButton(), no: self.strings.noButton()) { [weak self] save in
                    if save == 0 { _ = self?.send("save", ["slot": "manual"]) }
                    self?.quitRequested = true
                }
            }
        case .play, .graphics:
            let target: OriginalOptionsPanelOverlay.Page = button == .play ? .play : .graphics
            ui.optionsPanel.select(ui.optionsPanel.page != target ? target : .none)
        }
    }

    private var playOptionsURL: URL {
        (options.dataRoot ?? (options.workspace ?? defaultWorkspace()).appendingPathComponent("runtime/data")).appendingPathComponent("Settings/options.json")
    }

    func loadPlayOptions() {
        guard let data = try? Data(contentsOf: playOptionsURL),
              let options = try? JSONDecoder().decode(OriginalOptionsPanelOverlay.PlayOptions.self, from: data) else { return }
        ui.optionsPanel.playOptions = options
        renderer.lightingEnabled = options.lighting && self.options.lighting
    }

    private func togglePlayOption(_ option: OriginalOptionsPanelOverlay.PlayOption) {
        let updated = option.toggled(ui.optionsPanel.playOptions)
        ui.optionsPanel.playOptions = updated
        do {
            try FileManager.default.createDirectory(at: playOptionsURL.deletingLastPathComponent(), withIntermediateDirectories: true)
            try JSONEncoder().encode(updated).write(to: playOptionsURL, options: .atomic)
        } catch { log("Play options: \(error)") }
        playUISound("ui_click")
        applyPlayOptions()
        renderer.lightingEnabled = updated.lighting
    }

    func applyPlayOptions() { _ = send("freeWill", ["enabled": ui.optionsPanel.playOptions.freeWill]) }

    func saveGame() {
        guard ui.gameDialog == nil else { return }
        dismissMenu()
        presentLocalConfirmation(title: strings.saveHouseTitle(), message: strings.saveConfirmationMessage(),
                                 yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
            guard code == 0, let self, let id = self.send("save", ["slot": "manual"]) else { return }
            self.pendingSaveRequests.insert(id)
        }
    }

    // MARK: Local dialogs

    private func presentLocalFeedback(title: String, message: String) {
        guard ui.gameDialog == nil else { return }
        let token = "native-storage-" + UUID().uuidString
        do {
            ui.gameDialog = try OriginalDialogOverlay(dialog: .localFeedback(token: token, title: title, message: message, ok: strings.okButton()),
                                                      font: ui.font, device: UIDevice(), content: ui.content)
            localDialogToken = token
            localDialogResponse = nil
        } catch { log("Dialog: \(error)") }
    }

    private func presentLocalConfirmation(title: String, message: String, yes: String, no: String, cancel: String? = nil, response: @escaping (UInt8) -> Void) {
        guard ui.gameDialog == nil else { return }
        let token = "native-storage-" + UUID().uuidString
        do {
            let dialog = GameDialog.localPrompt(token: token, title: title, message: message, kind: cancel == nil ? 1 : 2, yes: yes, no: no, cancel: cancel)
            ui.gameDialog = try OriginalDialogOverlay(dialog: dialog, font: ui.font, device: UIDevice(), content: ui.content)
            localDialogToken = token
            localDialogResponse = response
        } catch { log("Dialog: \(error)") }
    }

    private func respondDialog(_ dialog: OriginalDialogOverlay, code: UInt8, responseText: String? = nil) {
        if localDialogToken == dialog.dialog.token {
            let response = localDialogResponse
            localDialogToken = nil
            localDialogResponse = nil
            ui.gameDialog = nil
            response?(code)
            return
        }
        guard !dialog.submitting else { return }
        if send("dialogResponse", ["token": dialog.dialog.token, "code": Int(code), "text": responseText ?? dialog.text]) != nil {
            dialog.submitting = true
        }
    }

    // MARK: Pointer

    /// A left press. Returns whether it began a build stroke (whose drags and release follow); otherwise it was a click.
    func press(_ point: CGPoint, canvas: CGSize, shift: Bool, alt: Bool) {
        self.canvas = canvas
        if shift, fillRoom(point, removing: alt) { primaryGesture = false; return }
        primaryGesture = startTerrainStroke(point) || startWallStroke(point, rectangle: shift, deleting: alt)
            || removeWallpaper(point, removing: alt) || startFloorStroke(point, deleting: alt)
        if !primaryGesture { click(point) }
    }

    func drag(_ point: CGPoint) {
        pointer = point
        updateTerrainStroke(point)
        updateBuildPreview(point)
    }

    func release(_ point: CGPoint) {
        guard primaryGesture else { return }
        primaryGesture = false
        finishTerrainStroke(point)
        finishWallStroke(point)
        finishFloorStroke(point)
    }

    private func click(_ point: CGPoint) {
        if let dialog = ui.gameDialog, localDialogToken == dialog.dialog.token {
            do {
                try dialog.prepare(canvas: canvas, scale: scale)
                if let code = dialog.choice(point, scale: scale) { respondDialog(dialog, code: code) }
            } catch { log("Dialog: \(error)") }
            return
        }
        do {
            if let dialog = ui.gameDialog {
                try dialog.prepare(canvas: canvas, scale: scale)
                if dialog.dialog.kind == 10 {
                    switch dialog.phoneBookAction(point, scale: scale) {
                    case .some(.changedSelection), nil: break
                    case .some(.call(let neighborId)): respondDialog(dialog, code: 1, responseText: String(neighborId))
                    case .some(.cancel): respondDialog(dialog, code: 0, responseText: "-1")
                    }
                } else if let code = dialog.choice(point, scale: scale) {
                    respondDialog(dialog, code: code)
                }
                return
            }
            if let control = OriginalUniversalControl.hit(point: point, canvas: canvas, scale: scale) {
                if control.action != .options { playUISound("ui_click") }
                switch control.action {
                case .live:
                    leaveOptionsMode()
                    if ui.buyMode { browseBuyCatalog() } else if ui.buildMode { browseBuildCatalog() }
                case .buy: leaveOptionsMode(); if !ui.buyMode { browseBuyCatalog() }
                case .build: leaveOptionsMode(); if !ui.buildMode { browseBuildCatalog() }
                case .zoomIn, .zoomOut:
                    dismissMenu()
                    renderer.setZoom(renderer.zoom.stepped(control.action == .zoomIn ? 1 : -1))
                case .wallsUp, .wallsDown, .wallsCutaway:
                    dismissMenu()
                    _ = send("walls", ["mode": control.action == .wallsUp ? "up" : control.action == .wallsCutaway ? "cutaway" : "down"])
                case .roofs:
                    dismissMenu()
                    _ = send("roofs", ["visible": !renderer.roofsVisible])
                case .story1: selectStory(1)
                case .story2: selectStory(2)
                case .cameraLeft: rotateCamera(-1)
                case .cameraRight: rotateCamera(1)
                case .options: ui.optionsMode ? leaveOptionsMode() : enterOptionsMode()
                }
                return
            }
            if let speed = OriginalSpeedControl.hit(point: point, canvas: canvas, scale: scale) {
                dismissMenu()
                sendSpeed(speed == 0 && renderer.speed == 0 ? 1 : speed)
                return
            }
            let local = local(point)
            if ui.optionsMode, let button = ui.optionsPanel.button(at: local, canvas: logicalCanvas) {
                if ui.optionsPanel.isEnabled(button) { chooseOption(button) }
                return
            }
            if ui.optionsMode, let option = ui.optionsPanel.option(at: local, canvas: logicalCanvas) {
                if option.isImplemented { togglePlayOption(option) }
                return
            }
            if ui.buildMode {
                if let action = ui.build.action(at: local, canvas: logicalCanvas) {
                    switch action {
                    case .page(let offset): requestBuildCatalog(offset: offset)
                    case .kind(let kind):
                        dismissMenu()
                        _ = send("roofs", ["visible": kind == .roof])
                        ui.build.changeKind(kind)
                        requestBuildCatalog(offset: 0)
                    case .select(let id):
                        ui.buy.cancelSelection()
                        ui.build.choose(id)
                        if ui.build.kind == .roof { _ = send("roof", ["style": id, "pitch": ui.roofPitch]) }
                    case .objectTool(let tool):
                        dismissMenu()
                        ui.build.changeObjectTool(tool)
                        ui.buy.clear(category: tool.category ?? 0)
                        pendingBuildCatalog = nil
                        if tool.category != nil { requestBuildCatalog(offset: 0) }
                    case .selectObject(let guid): ui.chooseCatalogObject(guid)
                    case .terrain:
                        dismissMenu()
                        ui.buy.cancelSelection()
                        ui.build.changeTerrainMode(.raise)
                    case .terrainMode(let mode):
                        dismissMenu()
                        ui.build.changeTerrainMode(mode)
                    case .history(let action):
                        dismissMenu()
                        if action == .undo ? ui.gameplay.state?.canUndo == true : ui.gameplay.state?.canRedo == true { _ = send(action.rawValue) }
                    }
                } else if ui.objectEditing, renderer.speed == 0 {
                    editObject(at: point)
                } else if renderer.speed == 0, ui.build.kind == .wall, let item = ui.build.selectedItem, let wall = renderer.wall(at: simd(point), canvas: simdCanvas) {
                    sendWithBuildSound("architecture", ["command": "PATTERN_DOT", "x": wall.x, "y": wall.y, "level": wall.level,
                                                        "x2": wall.direction, "y2": wall.direction, "pattern": item.id, "style": 0])
                } else if renderer.speed == 0, ui.build.kind == .floor || ui.build.kind == .water, let item = ui.build.selectedItem,
                          let hit = renderer.floorHit(at: simd(point), canvas: simdCanvas) {
                    sendWithBuildSound("architecture", ["command": "FLOOR_RECT", "x": hit.tile.x, "y": hit.tile.y, "level": renderer.viewLevel,
                                                        "x2": 0, "y2": 0, "pattern": item.id, "style": hit.style])
                }
                updatePlacement(point)
                return
            }
            if ui.buyMode {
                if let action = ui.buy.action(at: local, canvas: logicalCanvas) {
                    switch action {
                    case .category(let category):
                        ui.buy.clear(category: category)
                        requestCatalog(category: category, offset: 0)
                    case .page(let offset): requestCatalog(category: ui.buy.category, offset: offset)
                    case .select(let guid): ui.buy.choose(guid, budget: ui.gameplay.state?.budget)
                    }
                } else if renderer.speed == 0 {
                    editObject(at: point)
                }
                updatePlacement(point)
                return
            }
            if let sim = ui.gameplay.selection(at: local, canvas: logicalCanvas) {
                dismissMenu()
                _ = send("selectSim", ["objectID": sim])
                return
            }
            if let token = ui.gameplay.cancellation(at: local, canvas: logicalCanvas) {
                dismissMenu()
                _ = send("cancelAction", ["objectID": selectedSim, "token": token])
                playUISound("ui_queue_delete")
                return
            }
            if try ui.gameplay.pageInterests(at: local, canvas: logicalCanvas) { dismissMenu(); return }
            if try ui.gameplay.relationshipControl(at: local, canvas: logicalCanvas) { dismissMenu(); return }
            if let panel = ui.gameplay.subpanel(at: local, canvas: logicalCanvas) {
                dismissMenu()
                try ui.gameplay.choose(panel)
                return
            }
            if ui.gameplay.containsPanel(local, canvas: logicalCanvas) { dismissMenu(); return }
            if let menu = ui.pieMenu {
                menu.prepare(canvas: canvas, scale: scale)
                let result = try menu.choose(point, scale: scale)
                if let action = result.action, menu.selectedSim == selectedSim, renderer.containsObject(menu.objectID) {
                    let interaction = send("interact", ["objectID": menu.objectID, "interaction": Int(action.interaction), "param0": Int(action.param0), "global": action.global])
                    playUISound("ui_piemenu_select")
                    playUISoundOnResponse(interaction, success: "ui_queued", failure: nil)
                }
                if !result.keepOpen { dismissMenu() }
                return
            }
            dismissMenu()
            guard let target = renderer.object(at: simd(point), canvas: simdCanvas), selectedSim != 0,
                  let id = send("menu", ["objectID": target]) else { return }
            pendingMenu = MenuRequest(id: id, object: target, caller: selectedSim, anchor: local)
        } catch {
            dismissMenu()
            log("Interaction menu: \(error)")
        }
    }

    func hover(_ point: CGPoint, canvas: CGSize) {
        self.canvas = canvas
        pointer = point
        if let dialog = ui.gameDialog { dialog.hover(point, scale: scale); return }
        updatePlacement(point)
        updateCutaway(point)
        if ui.optionsMode { ui.optionsPanel.hover(local(point), canvas: logicalCanvas) }
        ui.pieMenu?.hover(point, scale: scale)
        if let highlighted = ui.pieMenu?.highlighted, highlighted != lastPieHighlight { playUISound("ui_piemenu_highlight") }
        lastPieHighlight = ui.pieMenu?.highlighted
        let local = local(point)
        ui.gameplay.hoveredAction = (0..<128).first { OriginalGameplayLayout.action($0).contains(local) }
    }

    /// The pointer left the window.
    func leave() { pointer = nil }

    /// Pans the lot by a drag in canvas pixels.
    func pan(_ delta: SIMD2<Float>) {
        guard ui.gameDialog == nil else { return }
        dismissMenu()
        renderer.pan += delta
    }

    /// A mouse wheel turn: zooms a whole level per notch, or scrolls an open dialog.
    func wheel(_ notches: Float) {
        dismissMenu()
        if let dialog = ui.gameDialog {
            if dialog.dialog.kind == 10 { dialog.scrollPhoneBook(-notches * 20, point: pointer ?? .zero, scale: scale) }
            else { dialog.scrollMessage(-notches * 20) }
            return
        }
        let steps = notches > 0 ? 1 : notches < 0 ? -1 : 0
        renderer.setZoom(renderer.zoom.stepped(steps))
    }

    /// Edge scrolling, once a frame: pans while the pointer rests on a window edge, as the original game does.
    func tick(canvas: CGSize) {
        self.canvas = canvas
        guard ui.optionsPanel.playOptions.edgeScrolling, ui.gameDialog == nil, let pointer else { return }
        let margin = 4 * scale, speed = Float(14 * scale)
        var delta = SIMD2<Float>(repeating: 0)
        if pointer.x < margin { delta.x = speed } else if pointer.x > canvas.width - margin { delta.x = -speed }
        if pointer.y < margin { delta.y = speed } else if pointer.y > canvas.height - margin { delta.y = -speed }
        if delta != .zero { renderer.pan += delta }
    }

    private func updateCutaway(_ point: CGPoint) {
        guard ui.wallMode == "cutaway", ui.gameDialog == nil, ui.pieMenu == nil,
              let tile = renderer.groundTile(at: simd(point), canvas: simdCanvas) else { lastCutawayTile = nil; return }
        let key = "\(renderer.viewLevel):\(tile.x):\(tile.y)"
        guard lastCutawayTile != key else { return }
        if send("cutaway", ["x": tile.x, "y": tile.y]) != nil { lastCutawayTile = key }
    }

    // MARK: Keys

    enum Key { case escape, enter, backspace, left, right, up, down, pageUp, pageDown, delete, tab, character(String) }

    /// A key press; returns false for keys the live game does not use (the window handles those).
    func key(_ key: Key) -> Bool {
        if dialogKey(key) { return true }
        switch key {
        case .escape: dismissMenu()
        case .character("p"), .character(" "): sendSpeed(renderer.speed == 0 ? 1 : 0)
        case .character("1"): sendSpeed(1)
        case .character("2"): sendSpeed(3)
        case .character("3"): sendSpeed(10)
        case .tab: nextSim()
        case .character("w"): toggleWalls()
        case .pageUp: selectStory(renderer.viewLevel + 1)
        case .pageDown: selectStory(renderer.viewLevel - 1)
        case .character("b"): browseBuyCatalog()
        case .character("f"): browseBuildCatalog()
        case .character("r"):
            guard ui.objectEditing, ui.gameDialog == nil else { break }
            ui.buy.rotate()
            playUISound("ui_object_rotate")
            if let pointer { updatePlacement(pointer) }
        case .character("["): rotateCamera(-1)
        case .character("]"): rotateCamera(1)
        case .character("s"): saveGame()
        case .delete, .backspace: sellHeldObject()
        default: return false
        }
        return true
    }

    private func dialogKey(_ key: Key) -> Bool {
        guard let dialog = ui.gameDialog else { return false }
        if localDialogToken == dialog.dialog.token {
            if case .enter = key, let first = dialog.dialog.buttons.first(where: { $0.code == 0 }) { respondDialog(dialog, code: first.code) }
            else if case .escape = key, let dismiss = dialog.dialog.buttons.first(where: { $0.code == 2 }) ?? dialog.dialog.buttons.first(where: { $0.code == 1 }) {
                respondDialog(dialog, code: dismiss.code)
            }
            return true
        }
        do {
            if dialog.dialog.kind == 10 {
                switch key {
                case .enter: if let neighbor = dialog.selectedPhoneBookContact() { respondDialog(dialog, code: 1, responseText: String(neighbor)) }
                case .escape: respondDialog(dialog, code: 0, responseText: "-1")
                case .up: dialog.movePhoneBookSelection(-1)
                case .down: dialog.movePhoneBookSelection(1)
                case .left: dialog.movePhoneBookFamily(-1)
                case .right: dialog.movePhoneBookFamily(1)
                default: break
                }
                return true
            }
            switch key {
            case .enter: if let first = dialog.dialog.buttons.first { respondDialog(dialog, code: first.code) }
            case .escape: if let cancel = dialog.dialog.buttons.first(where: { $0.code == 2 }) { respondDialog(dialog, code: cancel.code) }
            case .backspace where dialog.dialog.kind == 3 && !dialog.submitting: try dialog.updateText(String(dialog.text.dropLast()))
            default: break
            }
        } catch { log("Game dialog: \(error)") }
        return true
    }

    /// Typed text, for the name-entry dialog.
    func text(_ text: String) {
        guard let dialog = ui.gameDialog, dialog.dialog.kind == 3, !dialog.submitting, localDialogToken != dialog.dialog.token else { return }
        do { try dialog.updateText(dialog.text + text) } catch { log("Game dialog: \(error)") }
    }

    var acceptsText: Bool { ui.gameDialog?.dialog.kind == 3 && localDialogToken != ui.gameDialog?.dialog.token }

    // MARK: Buy and build editing

    private func editObject(at point: CGPoint) {
        guard ui.objectEditing, renderer.speed == 0, ui.gameDialog == nil else { return }
        if let target = ui.buy.selection.target, let tile = renderer.groundTile(at: simd(point), canvas: simdCanvas) {
            switch target {
            case .catalog(let guid):
                if let price = ui.selectedCatalogPrice, price <= (ui.gameplay.state?.budget ?? 0) {
                    let request = send("buyObject", ["guid": guid, "x": tile.placementX, "y": tile.placementY, "level": renderer.viewLevel, "direction": ui.buy.direction])
                    playUISoundOnResponse(request, success: "ui_buy_place")
                } else {
                    playUISound("ui_error")
                }
            case .placed(let object):
                if object.movable {
                    let request = send("moveObject", ["objectID": object.id, "x": tile.placementX, "y": tile.placementY, "level": renderer.viewLevel, "direction": ui.buy.direction])
                    playUISoundOnResponse(request, success: "ui_object_move_place")
                    ui.buy.cancelSelection()
                }
            }
        } else if ui.buy.selection.target == nil, let id = renderer.object(at: simd(point), canvas: simdCanvas),
                  let object = editableObjects.first(where: { $0.id == id && $0.level == renderer.viewLevel }) {
            ui.buy.selection.chooseObject(object)
        }
    }

    private func sellHeldObject() {
        guard ui.objectEditing, renderer.speed == 0, ui.gameDialog == nil,
              case .placed(let object) = ui.buy.selection.target, object.sellable else { return }
        let request = send("sellObject", ["objectID": object.id])
        playUISoundOnResponse(request, success: "ui_object_moneyback")
        ui.buy.cancelSelection()
        desiredPlacement = nil
        try? renderer.updatePlacement(nil)
    }

    private func overPanelControls(_ point: CGPoint) -> Bool {
        OriginalUniversalControl.hit(point: point, canvas: canvas, scale: scale) != nil
            || OriginalSpeedControl.hit(point: point, canvas: canvas, scale: scale) != nil
            || ui.build.action(at: local(point), canvas: logicalCanvas) != nil
    }

    private func floorHit(_ point: CGPoint) -> FloorTileHit? {
        overPanelControls(point) ? nil : renderer.floorHit(at: simd(point), canvas: simdCanvas)
    }

    private var buildToolsReady: Bool { ui.buildMode && ui.build.objectTool == nil && renderer.speed == 0 && ui.gameDialog == nil }

    private func fillRoom(_ point: CGPoint, removing: Bool) -> Bool {
        guard buildToolsReady, removing || ui.build.selectedItem != nil, !overPanelControls(point),
              let fill = BuildRoomFill(kind: ui.build.kind, pattern: ui.build.selectedItem?.id ?? 0,
                                       tile: renderer.groundTile(at: simd(point), canvas: simdCanvas), wall: renderer.wall(at: simd(point), canvas: simdCanvas),
                                       removing: removing, selectedLevel: renderer.viewLevel) else { return false }
        floorStroke = nil
        floorBrush = nil
        try? renderer.updateFloorBrush(nil)
        sendWithBuildSound("architecture", ["command": fill.command, "x": fill.x, "y": fill.y, "level": fill.level, "x2": 0, "y2": 0, "pattern": fill.pattern, "style": 0])
        return true
    }

    private func updateBuildPreview(_ point: CGPoint) {
        if ui.objectEditing { updatePlacement(point); return }
        if ui.build.terrainMode != nil { return }
        if ui.build.kind == .wallStyle { updateWallPreview(point) } else { updateFloorPreview(point) }
    }

    private func terrainTile(_ point: CGPoint) -> GroundTile? {
        guard buildToolsReady, ui.build.terrainMode != nil, !overPanelControls(point) else { return nil }
        return renderer.groundTile(at: simd(point), canvas: simdCanvas)
    }

    private func startTerrainStroke(_ point: CGPoint) -> Bool {
        guard let mode = ui.build.terrainMode, let tile = terrainTile(point) else { return false }
        terrainStrokeMode = mode
        terrainStrokeStartPoint = point
        terrainGesture = TerrainBrushGesture()
        terrainGesture.begin(at: tile)
        return true
    }

    private func updateTerrainStroke(_ point: CGPoint) {
        guard terrainStrokeMode != nil, let tile = terrainTile(point) else { return }
        terrainGesture.move(to: tile)
    }

    private func finishTerrainStroke(_ point: CGPoint) {
        guard let mode = terrainStrokeMode else { return }
        terrainStrokeMode = nil
        let startPoint = terrainStrokeStartPoint
        terrainStrokeStartPoint = nil
        guard let scene = renderer.scene, let tile = terrainTile(point), let viewport = renderer.sceneViewport(canvas: simdCanvas) else {
            terrainGesture = TerrainBrushGesture()
            return
        }
        terrainGesture.move(to: tile)
        do {
            let heightDelta: Int16? = mode == .raise || mode == .lower
                ? try TerrainHeightDrag.delta(startY: Double(startPoint?.y ?? point.y), endY: Double(point.y), viewportScale: Double(viewport.scale), mode: mode)
                : nil
            let requests = try terrainGesture.finishStroke(mode: mode, level: renderer.viewLevel, scene: scene, heightDelta: heightDelta)
            guard !requests.isEmpty else { return }
            sendWithBuildSound("architectureBatch", ["commands": requests.map { $0.payload }])
        } catch {
            terrainGesture = TerrainBrushGesture()
            log("Terrain editing: \(error)")
        }
    }

    private func startWallStroke(_ point: CGPoint, rectangle: Bool, deleting: Bool) -> Bool {
        guard buildToolsReady, ui.build.kind == .wallStyle, let item = ui.build.selectedItem, let pattern = item.pattern,
              floorHit(point) != nil, let vertex = renderer.lotVertex(at: simd(point), canvas: simdCanvas) else { return false }
        wallStroke = (vertex, item.id, pattern, rectangle, deleting)
        return true
    }

    private func wallLine(_ point: CGPoint) -> WallBrushSelection? {
        guard buildToolsReady, ui.build.kind == .wallStyle, let stroke = wallStroke, ui.build.selectedItem?.id == stroke.style,
              floorHit(point) != nil, let vertex = renderer.lotVertex(at: simd(point), canvas: simdCanvas) else { return nil }
        return WallBrushSelection(start: stroke.start, end: vertex, rectangle: stroke.rectangle, deleting: stroke.deleting)
    }

    private func updateWallPreview(_ point: CGPoint) {
        guard let line = wallLine(point) else {
            if wallBrush != nil { wallBrush = nil; try? renderer.updateWallBrush(nil) }
            return
        }
        guard line != wallBrush else { return }
        do { try renderer.updateWallBrush(line); wallBrush = line } catch { log("Wall brush: \(error)") }
    }

    private func finishWallStroke(_ point: CGPoint) {
        guard let stroke = wallStroke else { return }
        let line = wallLine(point)
        wallStroke = nil
        wallBrush = nil
        try? renderer.updateWallBrush(nil)
        guard let line else { return }
        let arguments = line.arguments
        sendWithBuildSound("architecture", ["command": line.command, "x": arguments.x, "y": arguments.y, "level": renderer.viewLevel,
                                            "x2": arguments.x2, "y2": arguments.y2, "pattern": stroke.pattern, "style": stroke.style])
    }

    private func removeWallpaper(_ point: CGPoint, removing: Bool) -> Bool {
        guard removing, buildToolsReady, ui.build.kind == .wall, !overPanelControls(point),
              let wall = renderer.wall(at: simd(point), canvas: simdCanvas) else { return false }
        sendWithBuildSound("architecture", ["command": "PATTERN_DOT", "x": wall.x, "y": wall.y, "level": wall.level,
                                            "x2": wall.direction, "y2": wall.direction, "pattern": 0, "style": 0])
        return true
    }

    private var floorToolReady: Bool {
        buildToolsReady && ui.build.selectedObjectGUID == nil && (ui.build.kind == .floor || ui.build.kind == .water)
    }

    private func startFloorStroke(_ point: CGPoint, deleting: Bool) -> Bool {
        guard floorToolReady, let pattern = deleting ? UInt16(0) : ui.build.selectedItem?.id, let tile = floorHit(point)?.tile else { return false }
        floorStroke = (tile, pattern, ui.build.selectedItem?.id, deleting)
        floorBrush = nil
        updateFloorPreview(point)
        return true
    }

    private func floorSelection(_ point: CGPoint) -> (rectangle: FloorBrushRectangle, selection: FloorBrushSelection)? {
        guard floorToolReady, ui.build.selectedItem != nil || floorStroke?.deleting == true, let hit = floorHit(point),
              let rectangle = FloorBrushRectangle(start: floorStroke?.start ?? hit.tile, end: hit.tile),
              let selection = FloorBrushSelection(rectangle: rectangle, half: hit.half, water: ui.build.kind == .water && floorStroke?.deleting != true) else { return nil }
        return (rectangle, selection)
    }

    private func updateFloorPreview(_ point: CGPoint) {
        guard let selection = floorSelection(point)?.selection else {
            if floorBrush != nil { floorBrush = nil; try? renderer.updateFloorBrush(nil) }
            return
        }
        guard selection != floorBrush else { return }
        do { try renderer.updateFloorBrush(selection, deleting: floorStroke?.deleting == true); floorBrush = selection }
        catch { log("Floor brush: \(error)") }
    }

    private func finishFloorStroke(_ point: CGPoint) {
        guard let stroke = floorStroke else { return }
        let selected = floorSelection(point)
        floorStroke = nil
        floorBrush = nil
        try? renderer.updateFloorBrush(nil)
        guard ui.build.selectedItem?.id == stroke.selection, let (rectangle, selection) = selected else { return }
        sendWithBuildSound("architecture", ["command": "FLOOR_RECT", "x": rectangle.x, "y": rectangle.y, "level": renderer.viewLevel,
                                            "x2": rectangle.width, "y2": rectangle.height, "pattern": stroke.pattern, "style": selection.style])
        updateFloorPreview(point)
    }

    private func updatePlacement(_ point: CGPoint) {
        if ui.buildMode && !ui.objectEditing { updateBuildPreview(point); return }
        guard ui.objectEditing, renderer.speed == 0, ui.gameDialog == nil,
              let target = ui.buy.selection.target, let tile = renderer.groundTile(at: simd(point), canvas: simdCanvas) else {
            if desiredPlacement != nil { try? renderer.updatePlacement(nil) }
            desiredPlacement = nil
            checkedPlacement = nil
            return
        }
        let unavailable: Bool
        switch target {
        case .placed(let object): unavailable = !object.movable
        case .catalog: unavailable = (ui.selectedCatalogPrice ?? Int.max) > (ui.gameplay.state?.budget ?? 0)
        }
        if unavailable {
            desiredPlacement = nil
            checkedPlacement = nil
            try? renderer.updatePlacement(nil)
            return
        }
        let key = PlacementKey(target: target, tile: tile, direction: ui.buy.direction, revision: renderer.sceneRevisionNumber, level: renderer.viewLevel)
        if desiredPlacement != key { try? renderer.updatePlacement(nil) }
        desiredPlacement = key
        requestPlacement()
    }

    private func requestPlacement() {
        guard pendingPlacement == nil, let key = desiredPlacement, key != checkedPlacement else { return }
        var parameters: [String: Any] = ["x": key.tile.placementX, "y": key.tile.placementY, "level": key.level, "direction": key.direction]
        switch key.target {
        case .catalog(let guid): parameters["guid"] = guid
        case .placed(let object): parameters["objectID"] = object.id
        }
        if let id = send("previewObject", parameters) { pendingPlacement = (id, key) }
    }

    /// Updates the renderer's per-frame flags from the modes.
    func prepareFrame() {
        renderer.showsPlacement = ui.buyMode || ui.buildMode
        renderer.showsGhost = ui.objectEditing
    }

    // MARK: Host events

    private func simulationEvent(_ event: [String: Any]) {
        do {
            let type = event["type"] as? String
            let id = event["id"] as? String
            let ok = event["ok"] as? Bool == true
            if type == "response", let id, pendingSaveRequests.remove(id) != nil, !ok {
                if let reason = event["error"] as? String { log("Save: \(reason)") }
                presentLocalFeedback(title: strings.saveHouseTitle(), message: strings.saveFailedMessage())
            }
            if type == "lotChanged" {
                dismissMenu()
                ui.gameDialog = nil
                ui.buyMode = false
                ui.buildMode = false
                renderer.pan = .zero
                pendingCatalog = nil
                pendingBuildCatalog = nil
                pendingPlacement = nil
                editableObjects = []
            }
            if type == "response", let pending = pendingPlacement, id == pending.id {
                pendingPlacement = nil
                checkedPlacement = pending.key
                if desiredPlacement == pending.key, ui.objectEditing, ok, let result = event["result"] as? [String: Any] {
                    try renderer.updatePlacement(JSONDecoder().decode(PlacementPreview.self, from: JSONSerialization.data(withJSONObject: result)))
                }
                requestPlacement()
            }
            if type == "response", let id, id == pendingBuildCatalog {
                pendingBuildCatalog = nil
                if ok, ui.buildMode, let result = event["result"] as? [String: Any], let root = renderer.sceneRoot {
                    let data = try JSONSerialization.data(withJSONObject: result)
                    if let category = ui.build.objectTool?.category {
                        let page = try JSONDecoder().decode(BuyCatalogPage.self, from: data)
                        if page.category == category {
                            try ui.build.updateObjects(page, root: root)
                            try ui.buy.update(page, root: root, buildObjects: true)
                        }
                    } else {
                        let page = try JSONDecoder().decode(BuildCatalogPage.self, from: data)
                        try ui.build.update(page, root: root)
                        if page.kind == .roof { ui.build.choose(ui.roofStyle) }
                        if page.kind == .water && ui.build.selectedObjectGUID == nil { ui.buy.cancelSelection() }
                    }
                }
            }
            if type == "response", let id, id == pendingCatalog {
                pendingCatalog = nil
                if ok, ui.buyMode, let result = event["result"] as? [String: Any], let root = renderer.sceneRoot {
                    try ui.buy.update(JSONDecoder().decode(BuyCatalogPage.self, from: JSONSerialization.data(withJSONObject: result)), root: root)
                }
            }
            if type == "response", let pending = pendingMenu, id == pending.id {
                pendingMenu = nil
                if ok, selectedSim == pending.caller, renderer.containsObject(pending.object), let result = event["result"] as? [[String: Any]] {
                    let entries = try JSONDecoder().decode([SimInteraction].self, from: JSONSerialization.data(withJSONObject: result))
                    if !entries.isEmpty {
                        playUISound("ui_piemenu_appear")
                        ui.pieMenu = try OriginalPieOverlay(entries: entries, objectID: pending.object, selectedSim: pending.caller,
                                                            anchor: pending.anchor, font: ui.font, device: UIDevice())
                    }
                }
            }
            if type == "hello" {
                _ = send("audio", ["enabled": false])
                _ = send("stream", ["enabled": true])
                applyPlayOptions()
                if let speed = options.speed { _ = send("speed", ["value": speed]) }
            }
            if type == "response", let id, let sounds = pendingResponseSounds.removeValue(forKey: id) {
                if ok { playUISound(sounds.success) } else if let failure = sounds.failure { playUISound(failure) }
            }
            // The host refuses speed changes while a blocking dialog is open, so the requested speed follows each answer.
            if type == "response", event["operation"] as? String == "dialogResponse", ok, let speed = options.speed, !ui.buyMode, !ui.buildMode {
                _ = send("speed", ["value": speed])
            }
            if let scene = event["scene"] as? String {
                let revision = (event["revision"] as? NSNumber)?.int64Value ?? 0
                try renderer.loadScene(URL(fileURLWithPath: scene), revision: revision)
                if let pointer { updatePlacement(pointer) }
                if revision > 0 { _ = send("sceneAck", ["revision": revision]) }
            }
            if type == "animation", let frame = event["frame"] as? [String: Any] { renderer.queueAnimation(frame) }
            if let state = event["state"] as? [String: Any] ?? event["result"] as? [String: Any], let speed = state["speed"] as? Int {
                try applyState(state, speed: speed)
            }
            if type == "error" { log("host error \(event)") }
            // UI sounds fail quietly while the host plays no audio.
            if event["ok"] as? Bool == false, event["operation"] as? String != "audioEvent" {
                ui.gameDialog?.submitting = false
                log("\(event["operation"] ?? "request") failed: \(event["error"] ?? "")")
            }
        } catch { log("\(error)") }
    }

    private func applyState(_ state: [String: Any], speed: Int) throws {
        if let values = state["dialogs"] as? [[String: Any]] {
            let pending = try JSONDecoder().decode([GameDialog].self, from: JSONSerialization.data(withJSONObject: values))
            if let first = pending.first {
                if ui.gameDialog?.dialog.token != first.token, localDialogToken == nil {
                    dismissMenu()
                    ui.gameDialog = try OriginalDialogOverlay(dialog: first, font: ui.font, device: UIDevice(), content: ui.content)
                    let choices = first.buttons.map(\.label).joined(separator: ", ")
                    log("dialog \"\(first.title)\": \(first.message) [\(choices)]")
                }
                if options.answerDialogs, !answeredDialogs.contains(first.token), let dialog = ui.gameDialog, dialog.dialog.token == first.token {
                    answeredDialogs.insert(first.token)
                    respondDialog(dialog, code: first.kind == 10 ? 0 : first.buttons.first?.code ?? 0, responseText: first.kind == 10 ? "-1" : nil)
                }
            } else if localDialogToken == nil {
                ui.gameDialog = nil
            }
        }
        if let objects = state["objects"] as? [[String: Any]] {
            editableObjects = try JSONDecoder().decode([EditableLotObject].self, from: JSONSerialization.data(withJSONObject: objects))
            ui.buy.selection.reconcile(objects: editableObjects)
        }
        renderer.speed = speed
        ui.roofPitch = (state["roofPitch"] as? NSNumber)?.floatValue ?? 0.66
        if let style = (state["roofStyle"] as? NSNumber)?.uint16Value {
            ui.roofStyle = style
            if ui.build.kind == .roof { ui.build.choose(style) }
        }
        if let root = renderer.sceneRoot { try ui.update(state: state, root: root) }
        if let pointer { updatePlacement(pointer) }
        selectedSim = state["selectedSim"] as? Int ?? 0
        if let menu = ui.pieMenu, menu.selectedSim != selectedSim || !renderer.containsObject(menu.objectID) { dismissMenu() }
        let sims = state["sims"] as? [[String: Any]] ?? []
        simIDs = sims.filter { $0["household"] as? Bool == true }.compactMap { $0["id"] as? Int }
    }
}

func log(_ message: String) {
    FileHandle.standardError.write(Data("SimsSDL: \(message)\n".utf8))
}
