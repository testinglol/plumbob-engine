import CSDL3
import Foundation
import SimsClient
import SimsCore

/// Plays a lot through the simulation host with the original UI: the macOS client's live-mode game logic (its app
/// delegate's event handling, clicks, hover, keys and the buy and build tools) on SDL input. Points are in canvas pixels.
@MainActor
final class LiveController {
    /// The lot's simulation host; nil on the base neighborhood screen.
    private(set) var bridge: SimulationBridge?
    let content: GameContent
    let workspace: URL
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
    private var pendingLoadRequests: Set<String> = []
    private var pendingAudioState: String?
    private var pendingAudioVolumes: [String: OriginalSoundOptionsOverlay.VolumeChange] = [:]
    private var latestAudioVolumeRequest: [String: String] = [:]
    private var soundGesture = false
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
    private var audio: SDLAudioPlayer?
    private var lastAudioPan = SIMD2<Float>(repeating: 0)
    private var lastAudioZoom = LotZoom.medium

    // Neighborhood, Select a Family, Create a Family and wardrobe state, as the macOS app delegate keeps it.
    private var currentNeighborhood: Int
    private var neighborhoodHouseSelected: ((Int) -> Void)?
    private var rezoneMode = false
    private var evictMode = false
    private var neighborhoodBeforeHouseholdCreation: OriginalNeighborhoodOverlay?
    private var pendingHouseholdCreation: Int?
    private var pendingHouseholdCreationRequest: String?
    private var pendingHouseholdAppearanceRequest: String?
    private var pendingHouseholdPreviewRequest: String?
    private var pendingFamilyMoveIn: (house: Int, family: Int, request: String?)?
    private struct NeighborhoodRequest { let id: String; let dialog: GameDialog; let mode: Int }
    private var pendingNeighborhood: NeighborhoodRequest?
    private var pendingNeighborhoodResponse: String?
    private var activeNeighborhoodDialog: GameDialog?
    private var failedNeighborhoodTokens: Set<String> = []
    private var pendingOutfitChoices: (id: String, dialog: GameDialog)?
    private var pendingOutfitPreview: String?
    private var loadingNeighborhood = false
    // The audio-only host that plays the neighborhood maps' music and ambience while no lot is loaded.
    private var frontendAudio: SimulationBridge?
    private var frontendAudioPlayer: SDLAudioPlayer?
    private var frontendAudioReady = false
    private var pendingFrontendAudio: [(operation: String, parameters: [String: Any])] = []
    private var frontendMusic: String?
    /// The last values each plugin reported for its panels, by pack and panel ID.
    private var pluginPanelValues: [String: [String: [String: String]]] = [:]

    /// Opens `house` live, or the base neighborhood screen when `house` is nil.
    init(options: Options, house: Int?, renderer: LotRenderer) throws {
        let workspace = options.workspace ?? defaultWorkspace()
        let game = options.game ?? workspace.appendingPathComponent("runtime/game", isDirectory: true)
        content = try PackTool.loadContent(game: game, packs: options.packs)
        self.workspace = workspace
        self.options = options
        self.renderer = renderer
        currentNeighborhood = options.neighborhood
        ui = try LiveUI(content: content)
        if !options.answerDialogs { reviewPluginTrust() }
        if let house { try startSimulation(house: house) } else { loadBaseNeighborhood() }
    }

    /// Starts the simulation host on a lot, with its own audio player.
    private func startSimulation(house: Int) throws {
        stopFrontendAudio()
        let bridge = SimulationBridge(workspace: workspace, dataRoot: options.dataRoot, profileID: options.profile, neighborhood: currentNeighborhood)
        bridge.discardsContentOnExit = true
        self.bridge = bridge
        renderer.liveMode = true
        renderer.drawsLot = true
        bridge.event = { [weak self, weak bridge] event in
            guard let self, let bridge, self.bridge === bridge else { return }
            EventProfiler.measure(event["type"] as? String ?? "response") { self.simulationEvent(event) }
        }
        bridge.animation = { [weak self, weak bridge] frame in
            guard let self, let bridge, self.bridge === bridge else { return }
            self.renderer.queueAnimation(frame)
        }
        bridge.failed = { [weak bridge] error in
            log("\(error) (log: \(bridge?.session.path ?? "")/simulation.log)")
        }
        audio?.close()
        audio = nil
        if options.audio {
            do {
                let audio = try SDLAudioPlayer(session: bridge.session)
                audio.ended = { [weak self] voice in _ = self?.send("audioEnded", ["voice": voice]) }
                audio.spatial = { [weak self] owner, panned, zoom in self?.spatialMix(owner: owner, panned: panned, zoom: zoom) ?? (0, 1) }
                self.audio = audio
            } catch { log("audio disabled: \(error)") }
        }
        try bridge.start(content: content, house: house)
        log("live session \(bridge.session.path)")
    }

    // MARK: Requests

    private func send(_ operation: String, _ parameters: [String: Any] = [:]) -> String? {
        guard let bridge else { return nil }
        do { return try bridge.send(operation, parameters) }
        catch { log("\(operation): \(error)"); return nil }
    }

    func playUISound(_ name: String) {
        guard bridge != nil else { sendFrontendAudio("audioEvent", ["name": name]); return }
        if audio != nil { _ = send("audioEvent", ["name": name]) }
    }

    /// The pan and gain of a sound from an object, from where the object sits in the view, as the macOS client mixes it.
    private func spatialMix(owner: Int, panned: Bool, zoom: Bool) -> (pan: Float, gain: Float) {
        guard let scene = renderer.scene, let viewport = renderer.sceneViewport(canvas: simdCanvas) else { return (0, 1) }
        let source = scene.sprites.first { $0.objectID == owner }.map { SIMD2($0.x + $0.width / 2, $0.y + $0.height / 2) }
            ?? scene.meshes?.first { $0.objectID == owner }?.vertices.first.map { SIMD2($0.x, $0.y) }
        guard let source else { return (0, 0) }
        let point = source * viewport.scale + viewport.origin
        let delta = (point - viewport.size / 2) / max(1, viewport.size.x)
        let pan = min(1, max(-1, delta.x * 2))
        let gain = (panned ? max(0, 1 - (delta.x * delta.x + delta.y * delta.y).squareRoot()) : 1) * (zoom ? renderer.zoom.soundGain : 1)
        return (pan, gain)
    }

    /// Once a frame: finished voices go back to the host and positional sounds follow the view.
    func updateAudio() {
        frontendAudioPlayer?.poll()
        guard let audio else { return }
        audio.poll()
        if renderer.pan != lastAudioPan || renderer.zoom != lastAudioZoom {
            lastAudioPan = renderer.pan
            lastAudioZoom = renderer.zoom
            audio.updateSpatial()
        }
    }

    /// Shuts down on quit or a termination signal: the lot host autosaves and both hosts exit before the client does.
    func stop() {
        audio?.close()
        audio = nil
        let hosts = [bridge, frontendAudio].compactMap { $0 }
        bridge?.stop()
        stopFrontendAudio()
        for host in hosts where !host.waitForExit(timeout: 10) { log("the simulation host did not exit in time") }
    }

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
        if ui.soundOptions.isEmbedded { ui.soundOptions.dismiss() }
    }

    private func sendAudioVolume(_ change: OriginalSoundOptionsOverlay.VolumeChange) {
        guard let id = send("audioVolume", ["group": change.group, "volume": change.volume]) else {
            ui.soundOptions.restore(change)
            return
        }
        pendingAudioVolumes[id] = change
        latestAudioVolumeRequest[change.group] = id
    }

    private func chooseOption(_ button: OriginalOptionsPanelOverlay.Button) {
        playUISound("ui_click")
        switch button {
        case .save: saveGame()
        case .sound:
            if ui.soundOptions.isEmbedded {
                ui.soundOptions.dismiss()
                ui.optionsPanel.select(.none)
            } else {
                ui.soundOptions.showEmbedded(rows: OriginalOptionsPanelOverlay.soundRows(strings: strings))
                ui.optionsPanel.select(.sound)
                pendingAudioState = send("audioState")
            }
        case .neighborhood:
            // Original flow: offer to save, then return to the neighborhood (UIText STR# 153 entries 3 and 4).
            presentLocalConfirmation(title: strings.saveMenuTitle(), message: strings.saveConfirmationMessage(),
                                     yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
                self?.returnToNeighborhood(saving: code == 0)
            }
        case .quit:
            presentLocalConfirmation(title: strings.quitTitle(), message: strings.quitMessage(), yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
                guard code == 0, let self else { return }
                self.presentLocalConfirmation(title: self.strings.quitTitle(), message: self.strings.saveBeforeQuitMessage(),
                                              yes: self.strings.yesButton(), no: self.strings.noButton()) { [weak self] save in
                    if save == 0 { _ = self?.send("save", ["slot": "manual", "lot": true]) }
                    self?.quitRequested = true
                }
            }
        case .play, .graphics:
            let target: OriginalOptionsPanelOverlay.Page = button == .play ? .play : .graphics
            if ui.soundOptions.isEmbedded { ui.soundOptions.dismiss() }
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
            guard code == 0, let self, let id = self.send("save", ["slot": "manual", "lot": true]) else { return }
            self.pendingSaveRequests.insert(id)
        }
    }

    func loadGame() {
        guard ui.gameDialog == nil else { return }
        dismissMenu()
        presentLocalConfirmation(title: strings.loadHouseTitle(), message: strings.loadConfirmationMessage(),
                                 yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
            guard code == 0 else { return }
            self?.sendLoad(removingPacks: false)
        }
    }

    private func sendLoad(removingPacks: Bool) {
        var parameters: [String: Any] = ["slot": "manual"]
        if removingPacks { parameters["removePacks"] = true }
        guard let id = send("load", parameters) else {
            presentLocalFeedback(title: strings.loadHouseTitle(), message: strings.loadFailedMessage())
            return
        }
        pendingLoadRequests.insert(id)
    }

    /// A save that needs uninstalled packs loads only once the player agrees to lose that content; the host backs the
    /// slot up first, so reinstalling the packs and restoring the backup brings it back.
    private func confirmPackRemoval(_ packs: [String]) {
        let names = packs.map { $0.split(separator: "@").first.map(String.init) ?? $0 }.joined(separator: ", ")
        presentLocalConfirmation(title: strings.loadHouseTitle(),
                                 message: "This house uses custom content that is not installed: \(names). Load it anyway? "
                                     + "Objects from that content will be removed and refunded. A backup of the save is kept.",
                                 yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
            guard code == 0 else { return }
            self?.sendLoad(removingPacks: true)
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
        if ui.gameDialog == nil, ui.outfitPicker == nil, ui.soundOptions.isVisible, !ui.soundOptions.isEmbedded || ui.soundOptions.contains(point, canvas: canvas, scale: scale) {
            if let change = ui.soundOptions.pointerDown(point, canvas: canvas, scale: scale) { sendAudioVolume(change) }
            primaryGesture = true
            soundGesture = true
            return
        }
        if shift, fillRoom(point, removing: alt) { primaryGesture = false; return }
        primaryGesture = startTerrainStroke(point) || startWallStroke(point, rectangle: shift, deleting: alt)
            || removeWallpaper(point, removing: alt) || startFloorStroke(point, deleting: alt)
        if !primaryGesture { click(point) }
    }

    func drag(_ point: CGPoint) {
        pointer = point
        if soundGesture {
            if let change = ui.soundOptions.pointerDragged(point, canvas: canvas, scale: scale) { sendAudioVolume(change) }
            return
        }
        updateTerrainStroke(point)
        updateBuildPreview(point)
    }

    func release(_ point: CGPoint) {
        guard primaryGesture else { return }
        primaryGesture = false
        if soundGesture {
            soundGesture = false
            let wasVisible = ui.soundOptions.isVisible
            if let change = ui.soundOptions.pointerUp(point, canvas: canvas, scale: scale) { sendAudioVolume(change) }
            if wasVisible && !ui.soundOptions.isVisible { playUISound("ui_click") }
            return
        }
        finishTerrainStroke(point)
        finishWallStroke(point)
        finishFloorStroke(point)
    }

    private func click(_ point: CGPoint) {
        if let picker = ui.outfitPicker {
            if let action = picker.click(local(point), canvas: logicalCanvas) { handleOutfitPicker(action, picker: picker) }
            return
        }
        if let panel = ui.pluginPanel, ui.gameDialog == nil, !ui.soundOptions.isVisible {
            // Plugin panels are modal like the original option panels; clicks never fall through to the lot.
            switch panel.hit(point, canvas: canvas, scale: CGFloat(scale)) {
            case .close?:
                ui.pluginPanel = nil
                playUISound("ui_click")
            case .action(let action)?:
                playUISound("ui_click")
                _ = send("pluginAction", ["packId": panel.packID, "panelId": panel.description.id, "action": action])
            case .inside?, nil:
                break
            }
            return
        }
        if let dialog = ui.gameDialog, localDialogToken == dialog.dialog.token {
            do {
                try dialog.prepare(canvas: canvas, scale: scale)
                if let code = dialog.choice(point, scale: scale) { respondDialog(dialog, code: code) }
            } catch { log("Dialog: \(error)") }
            return
        }
        // A host dialog (the help prompt, a travel answer) sits above the full-screen screens and takes the click first.
        if ui.gameDialog == nil, clickNeighborhoodScreens(point) { return }
        guard bridge != nil else { return }
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
                    let interaction = send("interact", action.interactParameters(objectID: menu.objectID))
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
        if let picker = ui.outfitPicker { picker.hover(local(point), canvas: logicalCanvas); return }
        if let panel = ui.pluginPanel, !ui.soundOptions.isVisible { panel.hover(point, canvas: canvas, scale: CGFloat(scale)); return }
        if let neighborhood = ui.neighborhood {
            if let picker = ui.familyPicker { picker.hover(point, canvas: canvas) }
            else {
                neighborhood.updateHover(point, canvas: canvas)
                neighborhood.updateBannerHover(point, canvas: canvas)
            }
            return
        }
        if ui.householdCreation != nil { return }
        updatePlacement(point)
        updateCutaway(point)
        if ui.optionsMode { ui.optionsPanel.hover(local(point), canvas: logicalCanvas) }
        ui.soundOptions.hover(point, canvas: canvas, scale: scale)
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
        guard ui.gameDialog == nil, ui.showsLot else { return }
        dismissMenu()
        renderer.pan += delta
    }

    /// A mouse wheel turn: zooms a whole level per notch, or scrolls an open dialog.
    func wheel(_ notches: Float) {
        if ui.gameDialog == nil, let picker = ui.familyPicker {
            picker.scroll(by: notches > 0 ? -1 : notches < 0 ? 1 : 0)
            return
        }
        guard ui.showsLot else { return }
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
        guard ui.optionsPanel.playOptions.edgeScrolling, ui.gameDialog == nil, ui.showsLot, ui.outfitPicker == nil, ui.pluginPanel == nil,
              let pointer else { return }
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
        if let screen = screenKey(key) { return screen }
        if ui.pluginPanel != nil, !ui.soundOptions.isVisible {
            switch key {
            case .escape, .enter: ui.pluginPanel = nil; playUISound("ui_click")
            case .character("e"): openNextPluginPanel()
            default: break
            }
            return true
        }
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
        case .character("l"): loadGame()
        case .character("e"): openNextPluginPanel()
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
        if ui.gameDialog == nil, let creation = ui.householdCreation {
            for character in text { _ = creation.key(String(character)) { [weak self] in self?.confirmCancelHouseholdCreation() } }
            return
        }
        guard let dialog = ui.gameDialog, dialog.dialog.kind == 3, !dialog.submitting, localDialogToken != dialog.dialog.token else { return }
        do { try dialog.updateText(dialog.text + text) } catch { log("Game dialog: \(error)") }
    }

    var acceptsText: Bool { ui.householdCreation != nil || ui.gameDialog?.dialog.kind == 3 && localDialogToken != ui.gameDialog?.dialog.token }

    // MARK: Pack plugins

    /// Asks once per launch, in a system message box outside the original-game UI, before any untrusted plugin may run.
    /// "Keep Disabled" is the default; trust applies only to the exact files that were reviewed.
    private func reviewPluginTrust() {
        let dataRoot = options.dataRoot ?? workspace
        for (plugin, name) in PackTool.untrustedPlugins(content: content, dataRoot: dataRoot) {
            let title = "Allow “\(name)” to run code?"
            let message = "The pack \(plugin.packID) \(plugin.version) includes a gameplay plugin that runs with your user account's permissions. "
                + "Only allow packs from authors you trust.\n\nFiles digest: \(plugin.sha256)"
            let allowed = title.withCString { title in
                message.withCString { message in
                    "Keep Disabled".withCString { keep in
                        "Allow".withCString { allow in
                            var buttons = [SDL_MessageBoxButtonData(flags: SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT | SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, buttonID: 0, text: keep),
                                           SDL_MessageBoxButtonData(flags: 0, buttonID: 1, text: allow)]
                            return buttons.withUnsafeMutableBufferPointer { buttons in
                                var data = SDL_MessageBoxData(flags: SDL_MESSAGEBOX_WARNING, window: nil, title: title, message: message,
                                                              numbuttons: Int32(buttons.count), buttons: buttons.baseAddress, colorScheme: nil)
                                var choice: Int32 = 0
                                return SDL_ShowMessageBox(&data, &choice) && choice == 1
                            }
                        }
                    }
                }
            }
            guard allowed else { log("plugin \(plugin.packID) left disabled"); continue }
            do { try PackTool.trust(plugin, dataRoot: dataRoot) } catch { log("Plugin trust: \(error)") }
        }
    }

    /// Every pack-declared panel, in pack then panel ID order; the macOS client lists them in its Simulation menu.
    private var pluginPanels: [(packID: String, description: PanelDescription)] {
        content.packs.panelDescriptions().sorted { $0.key < $1.key }.flatMap { pack in
            pack.value.sorted { $0.key < $1.key }.map { (pack.key, $0.value) }
        }
    }

    /// Opens the panel after the open one (the first when none is open); past the last panel it closes.
    func openNextPluginPanel() {
        guard bridge != nil, ui.showsLot, ui.gameDialog == nil, ui.outfitPicker == nil else { return }
        let panels = pluginPanels
        guard !panels.isEmpty else { return log("no pack declares a plugin panel") }
        let current = ui.pluginPanel.flatMap { open in panels.firstIndex { $0.packID == open.packID && $0.description.id == open.description.id } }
        let next = current.map { $0 + 1 } ?? 0
        dismissMenu()
        ui.soundOptions.dismiss()
        playUISound("ui_click")
        guard next < panels.count else { ui.pluginPanel = nil; return }
        openPluginPanel(packID: panels[next].packID, description: panels[next].description)
    }

    /// Opens one declared panel, from the E key or when a plugin answers a menu choice with it.
    private func openPluginPanel(packID: String, description: PanelDescription) {
        do {
            let panel = try OriginalPluginPanelOverlay(packID: packID, description: description, content: content, font: ui.font,
                                                       device: ui.device, closeLabel: strings.okButton())
            panel.update(values: pluginPanelValues[packID]?[description.id] ?? [:])
            ui.pluginPanel = panel
            _ = send("pluginPanels")
        } catch { log("Plugin panel: \(error)") }
    }

    private func applyPluginPanelValues(_ panels: [[String: Any]]) {
        var updated: [String: [String: [String: String]]] = [:]
        for panel in panels {
            guard let packID = panel["packId"] as? String, let panelID = panel["panelId"] as? String,
                  let values = panel["values"] as? [String: String] else { continue }
            updated[packID, default: [:]][panelID] = values
        }
        pluginPanelValues = updated
        if let panel = ui.pluginPanel { panel.update(values: updated[panel.packID]?[panel.description.id] ?? [:]) }
    }

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
        renderer.drawsLot = ui.showsLot
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
            if type == "response", let id, pendingLoadRequests.remove(id) != nil, !ok {
                if let reason = event["error"] as? String { log("Load: \(reason)") }
                if let missing = event["missingPacks"] as? [String], !missing.isEmpty {
                    confirmPackRemoval(missing)
                } else {
                    presentLocalFeedback(title: strings.loadHouseTitle(), message: strings.loadFailedMessage())
                }
            }
            if type == "response", let id { try neighborhoodResponse(id: id, ok: ok, event: event) }
            if type == "pluginPanels", let panels = event["panels"] as? [[String: Any]] { applyPluginPanelValues(panels) }
            if type == "response", let result = event["result"] as? [String: Any],
               let panels = result["panels"] as? [[String: Any]], panels.allSatisfy({ $0["values"] != nil }) {
                applyPluginPanelValues(panels)
            }
            if type == "pluginPanelShow", let packID = event["packId"] as? String, let panelID = event["panelId"] as? String,
               ui.showsLot, ui.gameDialog == nil, ui.outfitPicker == nil,
               let description = pluginPanels.first(where: { $0.packID == packID && $0.description.id == panelID })?.description {
                dismissMenu()
                ui.soundOptions.dismiss()
                openPluginPanel(packID: packID, description: description)
            }
            if type == "plugin", let packID = event["packId"] as? String, let state = event["state"] as? String {
                log("Plugin \(packID): \(state)\(event["reason"].map { " — \($0)" } ?? "")")
                if state == "failed", ui.pluginPanel?.packID == packID { ui.pluginPanel = nil }
            }
            if type == "saveMigrated" {
                let removed = event["removedObjects"] as? [[String: Any]] ?? []
                log("Save migrated: \((event["upgraded"] as? [String] ?? []).joined(separator: ", ")); removed \((event["removed"] as? [String] ?? []).joined(separator: ", ")); "
                    + "\(removed.count) objects; backup \(event["backup"] ?? "none")")
                if !(event["removed"] as? [String] ?? []).isEmpty {
                    let refund = (event["refund"] as? NSNumber)?.intValue ?? 0
                    presentLocalFeedback(title: strings.loadHouseTitle(),
                                         message: "Removed \(removed.count) object\(removed.count == 1 ? "" : "s") from content that is no longer installed"
                                             + (refund > 0 ? " and refunded \(refund) Simoleons" : "") + ". A backup of the save was kept.")
                }
            }
            if type == "lotChanged" {
                dismissMenu()
                ui.pluginPanel = nil
                ui.soundOptions.dismiss()
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
            if type == "response", let id, id == pendingAudioState {
                pendingAudioState = nil
                if ok, let result = event["result"] as? [String: Any], let volumes = result["volumes"] as? [String: Any] {
                    ui.soundOptions.updateVolumes(volumes)
                }
            }
            if type == "response", let id, let change = pendingAudioVolumes.removeValue(forKey: id) {
                if latestAudioVolumeRequest[change.group] == id {
                    latestAudioVolumeRequest[change.group] = nil
                    if !ok { ui.soundOptions.restore(change) }
                }
            }
            if type == "hello" {
                _ = send("audio", ["enabled": audio != nil])
                _ = send("stream", ["enabled": true])
                applyPlayOptions()
                // An empty lot waits paused for its new family, as the original does; the speed follows the move-in.
                if let speed = options.speed, pendingHouseholdCreation == nil { _ = send("speed", ["value": speed]) }
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
                renderer.loadSceneInBackground(URL(fileURLWithPath: scene), revision: revision) { [weak self] error in
                    guard let self else { return }
                    if let error { return log("scene \(revision): \(error)") }
                    if let pointer { updatePlacement(pointer) }
                    if revision > 0 { _ = send("sceneAck", ["revision": revision]) }
                }
            }
            if let state = event["state"] as? [String: Any] ?? event["result"] as? [String: Any], let speed = state["speed"] as? Int {
                try applyState(state, speed: speed)
            }
            if type == "audio", let audio {
                do { try audio.receive(JSONDecoder().decode(AudioEvent.self, from: JSONSerialization.data(withJSONObject: event))) }
                catch { log("audio: \(error)") }
            }
            if type == "audioError" { log("audio: \(event["error"] ?? "unknown sound error")") }
            if type == "error" { log("host error \(event)") }
            // UI sounds fail quietly while the host plays no audio.
            if event["ok"] as? Bool == false, event["operation"] as? String != "audioEvent" {
                ui.gameDialog?.submitting = false
                log("\(event["operation"] ?? "request") failed: \(event["error"] ?? "")")
            }
        } catch { log("\(error)") }
    }

    private func applyState(_ state: [String: Any], speed: Int) throws {
        try applyHouseholdState(state)
        if let values = state["dialogs"] as? [[String: Any]] {
            let pending = try JSONDecoder().decode([GameDialog].self, from: JSONSerialization.data(withJSONObject: values))
            if let travel = pending.first(where: { OriginalNeighborhoodOverlay.mode(forDialogKind: $0.kind) != nil }),
               let mode = OriginalNeighborhoodOverlay.mode(forDialogKind: travel.kind) {
                if localDialogToken == nil { ui.gameDialog = nil }
                if activeNeighborhoodDialog?.token != travel.token, pendingNeighborhood?.dialog.token != travel.token,
                   !failedNeighborhoodTokens.contains(travel.token) {
                    loadTravelNeighborhood(travel, mode: mode)
                }
            } else if let first = pending.first, first.kind == 6 || first.kind == 9 {
                // Wardrobe and pet choice are carousels owned by the picker overlay, not generic dialogs.
                if localDialogToken == nil { ui.gameDialog = nil }
                if ui.outfitPicker?.token != first.token && pendingOutfitChoices?.dialog.token != first.token { openOutfitPicker(first) }
            } else if ui.householdCreation != nil {
                // The host cannot answer its prompts (the help-system question) before a family exists; they wait for the lot.
                if localDialogToken == nil { ui.gameDialog = nil }
            } else if let first = pending.first {
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
            } else {
                if localDialogToken == nil { ui.gameDialog = nil }
                if ui.outfitPicker != nil { closeOutfitPicker() }
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

// MARK: - Neighborhood, Select a Family, Create a Family and wardrobe (ported from the macOS app delegate)

extension LiveController {
    private var neighborhoodSettingURL: URL {
        (options.dataRoot ?? workspace).appendingPathComponent("runtime/native-profiles/\(options.profile)/Settings/current-neighborhood.txt")
    }

    private func storeNeighborhood(_ number: Int) {
        let url = neighborhoodSettingURL
        do {
            try FileManager.default.createDirectory(at: url.deletingLastPathComponent(), withIntermediateDirectories: true)
            try Data(String(number).utf8).write(to: url, options: .atomic)
        } catch { log("Neighborhood setting: \(error)") }
    }

    /// Exports and shows the base neighborhood map, with its music on the frontend audio host.
    func loadBaseNeighborhood() {
        guard !loadingNeighborhood else { return }
        loadingNeighborhood = true
        renderer.liveMode = false
        renderer.drawsLot = false
        let content = content
        Task { [weak self] in
            guard let self else { return }
            defer { self.loadingNeighborhood = false }
            do {
                let exported = try await NeighborhoodExport.create(content: content, workspace: self.workspace, dataRoot: self.options.dataRoot, mode: 1,
                                                                    profileID: self.options.profile, neighborhood: self.currentNeighborhood, discardsContent: true)
                guard self.bridge == nil else { return }
                self.ui.neighborhood = try OriginalNeighborhoodOverlay(content: content, device: self.ui.device, manifestURL: exported.manifest,
                                                                        session: exported.session, font: self.ui.font)
                self.neighborhoodHouseSelected = { [weak self] house in self?.selectNeighborhoodHouse(house) }
                log("neighborhood \(self.currentNeighborhood) (\(exported.session.path))")
                self.startFrontendAudio()
                if let neighborhood = self.ui.neighborhood { self.startNeighborhoodAudio(neighborhood) }
            } catch {
                log("Neighborhood: \(error)")
                self.showNeighborhoodError(error)
            }
        }
    }

    /// Leaves the lot for the base neighborhood screen, optionally saving the manual slot first.
    func returnToNeighborhood(saving: Bool) {
        leaveOptionsMode()
        if saving { _ = send("save", ["slot": "manual", "lot": true]) }
        dismissMenu()
        audio?.close()
        audio = nil
        bridge?.stop(save: false)
        bridge = nil
        simIDs = []
        ui.gameDialog = nil
        localDialogToken = nil
        localDialogResponse = nil
        ui.buyMode = false
        ui.buildMode = false
        ui.soundOptions.dismiss()
        ui.pluginPanel = nil
        closeOutfitPicker()
        activeNeighborhoodDialog = nil
        pendingNeighborhood = nil
        pendingNeighborhoodResponse = nil
        renderer.pan = .zero
        loadBaseNeighborhood()
    }

    private func showNeighborhoodError(_ error: Error) {
        presentLocalFeedback(title: strings.moveInErrorTitle(), message: String(describing: error))
    }

    /// Base-neighborhood lot selection: occupied lots open their household; vacant residential lots open Select a Family.
    private func selectNeighborhoodHouse(_ house: Int) {
        guard let neighborhood = ui.neighborhood, ui.familyPicker == nil else { return }
        playUISound("ui_nhood_click")
        if rezoneMode {
            rezoneMode = false
            neighborhood.setRezoneMode(false)
            beginRezone(house)
            return
        }
        if evictMode {
            evictMode = false
            neighborhood.setEvictMode(false)
            confirmEvict(house, neighborhood: neighborhood)
            return
        }
        if neighborhood.isVacantResidential(at: house) {
            openFamilyPicker(house: house, families: neighborhood.families)
            return
        }
        openNeighborhoodHouse(house, createHousehold: false)
    }

    /// Original rezone flow: evict the family, bulldoze the house, then choose Residential or Community (STR# 131, 250, 251).
    private func beginRezone(_ house: Int) {
        guard let neighborhood = ui.neighborhood, neighborhood.hasLot(house) else { return }
        let yes = strings.yesButton(), no = strings.noButton()
        if let family = neighborhood.occupant(at: house) {
            let message = OriginalUIStrings.format(strings.rezoneEvictMessage(), [family.name, OriginalUIStrings.simoleons(family.netWorth)])
            presentLocalConfirmation(title: strings.rezoneEvictTitle(), message: message, yes: yes, no: no) { [weak self] code in
                guard code == 0 else { return }
                self?.reloadNeighborhood(edit: "evict:\(house)") { self?.beginRezone(house) }
            }
        } else if !neighborhood.isBulldozed(at: house) {
            presentLocalConfirmation(title: strings.rezoneBulldozeTitle(), message: strings.rezoneBulldozeMessage(), yes: yes, no: no) { [weak self] code in
                guard code == 0 else { return }
                self?.playUISound("ui_nhood_bdoze_demolish")
                self?.reloadNeighborhood(edit: "bulldoze:\(house)") { self?.beginRezone(house) }
            }
        } else {
            let current = strings.zoningType(neighborhood.zoningIndex(at: house))
            let message = OriginalUIStrings.format(strings.rezoneMessage(), [current])
            // Yes chooses Residential, No chooses Community; Cancel leaves the zoning unchanged.
            presentLocalConfirmation(title: strings.rezoneTitle(), message: message, yes: strings.zoningType(0), no: strings.zoningType(1),
                                     cancel: strings.cancelButton()) { [weak self] code in
                guard code == 0 || code == 1, Int(code) != neighborhood.zoningIndex(at: house) else { return }
                self?.reloadNeighborhood(edit: "rezone:\(house):\(code)")
            }
        }
    }

    private func confirmEvict(_ house: Int, neighborhood: OriginalNeighborhoodOverlay) {
        guard let family = neighborhood.occupant(at: house) else {
            if neighborhood.isVacantResidential(at: house) {
                // A vacant lot's house can be bulldozed back to the empty-lot template (STR# 131 entries 0 and 1).
                presentLocalConfirmation(title: strings.bulldozeTitle(), message: strings.bulldozeMessage(), yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
                    guard code == 0 else { return }
                    self?.playUISound("ui_nhood_bdoze_demolish")
                    self?.reloadNeighborhood(edit: "bulldoze:\(house)")
                }
                return
            }
            playUISound("ui_nhood_error")
            presentLocalFeedback(title: strings.nothingToBulldozeTitle(), message: strings.nothingToBulldozeMessage())
            return
        }
        let message = OriginalUIStrings.format(strings.evictMessage(), [family.name, OriginalUIStrings.simoleons(family.netWorth)])
        presentLocalConfirmation(title: strings.evictTitle(), message: message, yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
            guard code == 0 else { return }
            self?.reloadNeighborhood(edit: "evict:\(house)")
        }
    }

    private func chooseBannerAction(_ action: OriginalNeighborhoodOverlay.BannerAction) {
        playUISound("ui_nhood_click")
        switch action {
        case .returnHome:
            // On a travel map the return button answers the travel dialog with "stay home".
            if activeNeighborhoodDialog != nil { respondToNeighborhood(-1) } else { reloadNeighborhood(edit: nil, mode: 1) }
        case .downtown, .vacation, .studioTown, .magicTown:
            if let mode = action.mapMode { reloadNeighborhood(edit: nil, mode: mode) }
        case .rezone:
            rezoneMode.toggle()
            if rezoneMode { evictMode = false; ui.neighborhood?.setEvictMode(false) }
            ui.neighborhood?.setRezoneMode(rezoneMode)
        case .bulldoze:
            evictMode.toggle()
            if evictMode { rezoneMode = false; ui.neighborhood?.setRezoneMode(false) }
            ui.neighborhood?.setEvictMode(evictMode)
        case .quit:
            presentLocalConfirmation(title: strings.quitTitle(), message: strings.quitMessage(), yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
                if code == 0 { self?.quitRequested = true }
            }
        case .importFamily:
            playUISound("ui_nhood_error")
            presentLocalFeedback(title: strings.sorryTitle(), message: "Importing original saves is available in the macOS client.")
        case .previous, .next:
            switchNeighborhood(forward: action == .next)
        default:
            break
        }
    }

    /// Previous/Next: open the adjacent installed neighborhood and remember it for the profile.
    private func switchNeighborhood(forward: Bool) {
        guard let neighborhood = ui.neighborhood, neighborhood.mode == 1,
              let target = OriginalNeighborhoodOverlay.neighborhood(after: currentNeighborhood, in: neighborhood.neighborhoods, forward: forward),
              target != currentNeighborhood else { playUISound("ui_nhood_error"); return }
        let previous = currentNeighborhood
        currentNeighborhood = target
        rezoneMode = false
        reloadNeighborhood(edit: nil, mode: 1, completion: { [weak self] in self?.storeNeighborhood(target) },
                           failure: { [weak self] in self?.currentNeighborhood = previous })
    }

    /// Rebuilds the base neighborhood map, optionally applying an evict/delete edit in the host process first.
    private func reloadNeighborhood(edit: String?, mode: Int = 1, completion: (() -> Void)? = nil, failure: (() -> Void)? = nil) {
        guard !loadingNeighborhood else { return }
        evictMode = false
        loadingNeighborhood = true
        let content = content
        Task { [weak self] in
            guard let self else { return }
            defer { self.loadingNeighborhood = false }
            do {
                let exported = try await NeighborhoodExport.create(content: content, workspace: self.workspace, dataRoot: self.options.dataRoot, mode: mode,
                                                                    profileID: self.options.profile, edit: edit, neighborhood: self.currentNeighborhood, discardsContent: true)
                let previousMode = self.ui.neighborhood?.mode
                self.ui.neighborhood = try OriginalNeighborhoodOverlay(content: content, device: self.ui.device, manifestURL: exported.manifest,
                                                                        session: exported.session, font: self.ui.font)
                self.neighborhoodHouseSelected = { [weak self] house in self?.selectNeighborhoodHouse(house) }
                if let neighborhood = self.ui.neighborhood, neighborhood.mode != previousMode {
                    self.stopNeighborhoodAmbientAudio()
                    self.startNeighborhoodAudio(neighborhood)
                }
                completion?()
            } catch {
                failure?()
                self.playUISound("ui_nhood_error")
                self.presentLocalFeedback(title: self.strings.moveInErrorTitle(), message: self.strings.evictFailedMessage())
                log("Neighborhood edit: \(error)")
            }
        }
    }

    // MARK: Select a Family

    private func openFamilyPicker(house: Int, families: [OriginalFamilyPickerOverlay.Family]) {
        do {
            ui.familyPicker = try OriginalFamilyPickerOverlay(house: house, families: families, content: content, font: ui.font, device: ui.device, strings: strings)
        } catch {
            showNeighborhoodError(error)
            return
        }
        if bridge == nil { playFrontendMusic("bkground_family") }
    }

    /// Closes Select a Family; returning to the map restores its music as the original does.
    private func closeFamilyPicker(returnsToMap: Bool = true) {
        ui.familyPicker = nil
        if returnsToMap, bridge == nil, let music = ui.neighborhood?.music, !music.isEmpty { playFrontendMusic(music) }
    }

    private func handleFamilyPicker(_ action: OriginalFamilyPickerOverlay.Action, picker: OriginalFamilyPickerOverlay) {
        guard let neighborhood = ui.neighborhood else { return }
        playUISound("ui_click")
        switch action {
        case .cancel:
            closeFamilyPicker()
        case .createFamily:
            guard neighborhood.canCreateHousehold(at: picker.house) else {
                playUISound("ui_nhood_error")
                presentLocalFeedback(title: strings.sorryTitle(), message: strings.cannotAffordMessage())
                return
            }
            closeFamilyPicker(returnsToMap: false)
            openNeighborhoodHouse(picker.house, createHousehold: true)
        case .delete(let family):
            let message = OriginalUIStrings.format(strings.pickFamily(7, fallback: "Are you sure you want to delete the \"%s\" family?"), [family.name])
            presentLocalConfirmation(title: strings.pickFamily(6, fallback: "Delete Family?"), message: message,
                                     yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
                guard code == 0, let self else { return }
                let house = picker.house
                self.closeFamilyPicker(returnsToMap: false)
                self.reloadNeighborhood(edit: "delete:\(family.id)") { [weak self] in
                    guard let self, let neighborhood = self.ui.neighborhood else { return }
                    self.openFamilyPicker(house: house, families: neighborhood.families)
                }
            }
        case .moveIn(let family):
            let price = neighborhood.price(at: picker.house) ?? Int.max
            guard family.budget >= price else {
                playUISound("ui_nhood_error")
                presentLocalFeedback(title: strings.sorryTitle(), message: strings.cannotAffordMessage())
                return
            }
            presentLocalConfirmation(title: strings.purchaseHouseTitle(), message: strings.purchaseHouseMessage(),
                                     yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
                guard code == 0, let self else { return }
                self.closeFamilyPicker(returnsToMap: false)
                self.pendingFamilyMoveIn = (picker.house, family.id, nil)
                self.openNeighborhoodHouse(picker.house, createHousehold: false, retainNeighborhood: true)
            }
        }
    }

    // MARK: Create a Family

    private func openNeighborhoodHouse(_ house: Int, createHousehold: Bool, retainNeighborhood: Bool = false) {
        neighborhoodBeforeHouseholdCreation = createHousehold || retainNeighborhood ? ui.neighborhood : nil
        ui.neighborhood = nil
        ui.familyPicker = nil
        ui.householdCreation = nil
        neighborhoodHouseSelected = nil
        rezoneMode = false
        evictMode = false
        pendingHouseholdCreation = createHousehold ? house : nil
        do { try startSimulation(house: house) }
        catch {
            log("Open lot \(house): \(error)")
            bridge = nil
            pendingFamilyMoveIn = nil
            restoreNeighborhoodAfterHouseholdCreation()
            showNeighborhoodError(error)
        }
    }

    private func confirmCancelHouseholdCreation() {
        guard ui.householdCreation != nil else { return }
        presentLocalConfirmation(title: strings.familyCancelConfirmationTitle(), message: strings.familyCancelConfirmationMessage(),
                                 yes: strings.yesButton(), no: strings.noButton()) { [weak self] code in
            guard code == 0 else { return }
            self?.cancelHouseholdCreation()
        }
    }

    private func cancelHouseholdCreation() {
        audio?.close()
        audio = nil
        bridge?.stop(save: false)
        bridge = nil
        simIDs = []
        dismissMenu()
        ui.gameDialog = nil
        restoreNeighborhoodAfterHouseholdCreation()
    }

    /// Puts back the neighborhood map that was showing before a lot was opened for a new or moving family.
    private func restoreNeighborhoodAfterHouseholdCreation() {
        ui.householdCreation = nil
        renderer.liveMode = false
        renderer.drawsLot = false
        renderer.clearAppearancePreview()
        pendingHouseholdCreation = nil
        pendingHouseholdCreationRequest = nil
        pendingHouseholdAppearanceRequest = nil
        pendingHouseholdPreviewRequest = nil
        guard let previous = neighborhoodBeforeHouseholdCreation else { loadBaseNeighborhood(); return }
        neighborhoodBeforeHouseholdCreation = nil
        ui.neighborhood = previous
        neighborhoodHouseSelected = { [weak self] house in self?.selectNeighborhoodHouse(house) }
        startFrontendAudio()
        startNeighborhoodAudio(previous)
    }

    private func requestHouseholdAppearancePreview(_ gender: String, _ age: String, _ skin: String, _ head: String, _ body: String,
                                                   creation: OriginalHouseholdCreationOverlay) {
        pendingHouseholdPreviewRequest = nil
        renderer.clearAppearancePreview()
        guard let bridge else { creation.previewFailed("The simulation is not connected."); return }
        do {
            pendingHouseholdPreviewRequest = try bridge.send("appearancePreview", ["gender": gender, "age": age, "skin": skin, "headChoice": head, "bodyChoice": body])
        } catch {
            creation.previewFailed("The Sim preview could not be loaded: \(error.localizedDescription)")
        }
    }

    private func clickHouseholdCreation(_ creation: OriginalHouseholdCreationOverlay, point: CGPoint) {
        creation.click(point, canvas: canvas, submit: { [weak self, weak creation] request in
            guard let self, creation != nil else { return }
            self.presentLocalConfirmation(title: self.strings.familyDoneConfirmationTitle(), message: self.strings.familyDoneConfirmationMessage(),
                                          yes: self.strings.yesButton(), no: self.strings.noButton()) { [weak self, weak creation] code in
                guard code == 0, let self, let creation else { return }
                creation.beginSubmission()
                guard let bridge = self.bridge else { creation.failed(self.strings.moveInErrorMessage()); return }
                do {
                    _ = try bridge.send("speed", ["value": 0])
                    let members: [[String: Any]] = request.members.map { member in
                        var fields: [String: Any] = ["name": member.name, "bio": member.bio, "code": member.code, "skin": member.skin, "personality": member.personality]
                        if let headChoice = member.headChoice { fields["headChoice"] = headChoice }
                        if let bodyChoice = member.bodyChoice { fields["bodyChoice"] = bodyChoice }
                        return fields
                    }
                    self.pendingHouseholdCreationRequest = try bridge.send("createHousehold", ["familyName": request.familyName, "members": members])
                } catch {
                    creation.failed(String(describing: error))
                }
            }
        }, cancel: { [weak self] in self?.confirmCancelHouseholdCreation() }, delete: { [weak self, weak creation] index in
            guard let self, creation != nil else { return }
            self.presentLocalConfirmation(title: self.strings.familyDeleteConfirmationTitle(), message: self.strings.familyDeleteConfirmationMessage(),
                                          yes: self.strings.yesButton(), no: self.strings.noButton()) { [weak creation] code in
                if code == 0 { creation?.deleteMember(at: index) }
            }
        }, appearanceCatalog: { [weak self, weak creation] gender, age, skin in
            guard let self, let creation else { return }
            guard let bridge = self.bridge else { creation.failed("The simulation is not connected."); return }
            self.pendingHouseholdPreviewRequest = nil
            self.renderer.clearAppearancePreview()
            do { self.pendingHouseholdAppearanceRequest = try bridge.send("appearanceCatalog", ["gender": gender, "age": age, "skin": skin]) }
            catch { creation.failed("Appearance choices could not be loaded: \(error.localizedDescription)") }
        }, previewAppearance: { [weak self, weak creation] gender, age, skin, head, body in
            guard let creation else { return }
            self?.requestHouseholdAppearancePreview(gender, age, skin, head, body, creation: creation)
        })
    }

    /// Opens Create a Family once the empty lot is running, and moves a chosen family in.
    func applyHouseholdState(_ state: [String: Any]) throws {
        let house = state["house"] as? Int
        let emptyLot = (state["sims"] as? [[String: Any]]).map { !$0.contains { $0["household"] as? Bool == true } } ?? false
        if let lot = pendingHouseholdCreation, house == lot, emptyLot, ui.householdCreation == nil {
            let creation = try OriginalHouseholdCreationOverlay(content: content, device: ui.device)
            creation.playSound = { [weak self] name in self?.playUISound(name) }
            ui.householdCreation = creation
            dismissMenu()
            log("create a family on lot \(lot)")
        }
        if let moveIn = pendingFamilyMoveIn, moveIn.request == nil, house == moveIn.house, emptyLot, let bridge {
            pendingFamilyMoveIn?.request = try bridge.send("moveInFamily", ["family": moveIn.family])
        }
    }

    // MARK: Travel maps

    private func respondToNeighborhood(_ house: Int) {
        guard let dialog = activeNeighborhoodDialog, let bridge, pendingNeighborhoodResponse == nil,
              let response = NeighborhoodTravel.response(forDestination: house) else { return }
        do {
            playUISound("ui_nhood_click")
            stopNeighborhoodAmbientAudio()
            pendingNeighborhoodResponse = try bridge.send("dialogResponse", ["token": dialog.token, "code": Int(response.code), "text": response.text])
            _ = send("audioEvent", ["name": "bkground_fade"])
            neighborhoodHouseSelected = nil
        } catch { log("Neighborhood selection: \(error)") }
    }

    private func startNeighborhoodAudio(_ neighborhood: OriginalNeighborhoodOverlay) {
        guard bridge != nil else {
            if let music = neighborhood.music, !music.isEmpty { playFrontendMusic(music) }
            if let ambient = neighborhood.ambientSound, !ambient.isEmpty { sendFrontendAudio("audioEvent", ["name": ambient, "ownerID": -25]) }
            return
        }
        guard audio != nil else { return }
        if let music = neighborhood.music, !music.isEmpty { _ = send("audioEvent", ["name": music]) }
        if let ambient = neighborhood.ambientSound, !ambient.isEmpty { _ = send("audioEvent", ["name": ambient, "ownerID": -25]) }
    }

    private func stopNeighborhoodAmbientAudio() {
        guard bridge != nil else { sendFrontendAudio("audioStopOwner", ["ownerID": -25]); return }
        if audio != nil { _ = send("audioStopOwner", ["ownerID": -25]) }
    }

    func loadTravelNeighborhood(_ dialog: GameDialog, mode: Int) {
        guard let bridge else { return }
        do {
            let id = try bridge.send("neighborhood", ["mode": mode])
            pendingNeighborhood = NeighborhoodRequest(id: id, dialog: dialog, mode: mode)
            dismissMenu()
            ui.gameDialog = nil
            ui.neighborhood = nil
            neighborhoodHouseSelected = nil
        } catch {
            failedNeighborhoodTokens.insert(dialog.token)
            activeNeighborhoodDialog = dialog
            log("Neighborhood selection: \(error)")
            showNeighborhoodError(error)
        }
    }

    // MARK: Wardrobe

    func openOutfitPicker(_ dialog: GameDialog) {
        dismissMenu()
        ui.soundOptions.dismiss()
        if let id = send("outfitChoices") { pendingOutfitChoices = (id, dialog) }
    }

    private func finishOpeningOutfitPicker(_ event: [String: Any], dialog: GameDialog) {
        let result = event["result"] as? [String: Any]
        let names = (result?["choices"] as? [[String: Any]])?.compactMap { $0["name"] as? String } ?? []
        guard event["ok"] as? Bool == true, !names.isEmpty else {
            // Nothing to choose from: answer with the original cancel result so the Sim is not left waiting.
            if let reason = event["error"] as? String { log("Outfit choices: \(reason)") }
            _ = send("dialogResponse", ["token": dialog.token, "code": 0, "text": "-1"])
            return
        }
        do {
            ui.outfitPicker = try OriginalOutfitPickerOverlay(token: dialog.token, pet: result?["pet"] as? Bool ?? false, names: names,
                                                              content: content, font: ui.font, device: ui.device, strings: strings)
            playUISound("ui_piemenu_appear")
            requestOutfitPreview()
            if options.answerDialogs, let picker = ui.outfitPicker { handleOutfitPicker(.cancel, picker: picker) }
        } catch {
            log("Outfit picker: \(error)")
            _ = send("dialogResponse", ["token": dialog.token, "code": 0, "text": "-1"])
        }
    }

    private func requestOutfitPreview() {
        guard let picker = ui.outfitPicker else { return }
        pendingOutfitPreview = send("outfitPreview", ["index": picker.index])
    }

    /// Loads the appearance preview the host wrote into its session directory and hands it to the renderer.
    private func loadAppearancePreview(_ event: [String: Any]) throws {
        guard event["ok"] as? Bool == true, let result = event["result"] as? [String: Any], result["file"] as? String == "cas-preview/preview.json",
              let bridge else { throw ContentError.invalid(event["error"] as? String ?? "The preview response is invalid") }
        let session = bridge.session.resolvingSymlinksInPath().standardizedFileURL
        let url = session.appendingPathComponent("cas-preview/preview.json").resolvingSymlinksInPath().standardizedFileURL
        guard url.path.hasPrefix(session.path + "/") else { throw ContentError.invalid("The preview file escaped its session directory") }
        let loaded = try HouseholdAppearancePreview.load(from: url)
        try renderer.updateAppearancePreview(loaded.preview, pixels: loaded.pixels)
    }

    func handleOutfitPicker(_ action: OriginalOutfitPickerOverlay.Action, picker: OriginalOutfitPickerOverlay) {
        switch action {
        case .previous, .next:
            picker.move(action == .next ? 1 : -1)
            playUISound("ui_click")
            requestOutfitPreview()
        case .buy(let index):
            playUISound("ui_buy_place")
            _ = send("dialogResponse", ["token": picker.token, "code": 1, "text": String(index)])
            closeOutfitPicker()
        case .cancel:
            playUISound("ui_click")
            _ = send("dialogResponse", ["token": picker.token, "code": 0, "text": "-1"])
            closeOutfitPicker()
        }
    }

    func closeOutfitPicker() {
        ui.outfitPicker = nil
        pendingOutfitPreview = nil
        renderer.clearAppearancePreview()
    }

    // MARK: Frontend audio

    /// Starts the audio-only host used by the neighborhood maps while no lot is loaded.
    private func startFrontendAudio() {
        guard options.audio, frontendAudio == nil, bridge == nil else { return }
        let host = SimulationBridge(workspace: workspace, dataRoot: options.dataRoot, profileID: options.profile, neighborhood: currentNeighborhood)
        host.discardsContentOnExit = true
        let player: SDLAudioPlayer
        do { player = try SDLAudioPlayer(session: host.session) }
        catch { log("Neighborhood audio: \(error)"); return }
        player.ended = { [weak host] voice in _ = try? host?.send("audioEnded", ["voice": voice]) }
        host.event = { [weak self, weak host, weak player] event in
            guard let self, let host, self.frontendAudio === host else { return }
            switch event["type"] as? String {
            case "hello":
                _ = try? host.send("audio", ["enabled": true])
                self.frontendAudioReady = true
                let queued = self.pendingFrontendAudio
                self.pendingFrontendAudio.removeAll()
                for request in queued { _ = try? host.send(request.operation, request.parameters) }
            case "audio":
                do { try player?.receive(JSONDecoder().decode(AudioEvent.self, from: JSONSerialization.data(withJSONObject: event))) }
                catch { log("Neighborhood audio: \(error)") }
            case "audioError":
                log("Neighborhood audio: \(event["error"] ?? "unknown sound error")")
            default: break
            }
        }
        host.failed = { error in log("Neighborhood audio: \(error)") }
        frontendAudio = host
        frontendAudioPlayer = player
        frontendAudioReady = false
        do { try host.startFrontendAudio(content: content) }
        catch {
            log("Neighborhood audio: \(error)")
            stopFrontendAudio()
        }
    }

    /// Starts a music event on the frontend host unless it is already the current track.
    private func playFrontendMusic(_ name: String) {
        guard frontendAudio != nil, frontendMusic != name else { return }
        frontendMusic = name
        sendFrontendAudio("audioEvent", ["name": name])
    }

    /// Sends an audio request to the neighborhood audio host, holding it until the host has started.
    func sendFrontendAudio(_ operation: String, _ parameters: [String: Any]) {
        guard let frontendAudio else { return }
        if frontendAudioReady { _ = try? frontendAudio.send(operation, parameters) }
        else if pendingFrontendAudio.count < 32 { pendingFrontendAudio.append((operation: operation, parameters: parameters)) }
    }

    func stopFrontendAudio() {
        frontendAudio?.stop(save: false)
        frontendAudioPlayer?.close()
        frontendAudio = nil
        frontendAudioPlayer = nil
        frontendAudioReady = false
        pendingFrontendAudio.removeAll()
        frontendMusic = nil
    }

    // MARK: Input on the full-screen screens

    /// Clicks on the family picker, the neighborhood map and Create a Family; returns whether one of them took it.
    func clickNeighborhoodScreens(_ point: CGPoint) -> Bool {
        if ui.neighborhood != nil, let picker = ui.familyPicker {
            if let action = picker.click(point, canvas: canvas) { handleFamilyPicker(action, picker: picker) }
            return true
        }
        if let neighborhood = ui.neighborhood {
            if let action = neighborhood.bannerAction(at: point, canvas: canvas) {
                if neighborhood.isEnabled(action) { chooseBannerAction(action) } else { playUISound("ui_nhood_error") }
                return true
            }
            if let house = neighborhood.house(at: point, canvas: canvas) { neighborhoodHouseSelected?(house) }
            return true
        }
        if let creation = ui.householdCreation {
            clickHouseholdCreation(creation, point: point)
            return true
        }
        return bridge == nil
    }

    /// Keys for the full-screen screens; nil when none is showing.
    func screenKey(_ key: Key) -> Bool? {
        if let picker = ui.outfitPicker {
            switch key {
            case .left: handleOutfitPicker(.previous, picker: picker)
            case .right: handleOutfitPicker(.next, picker: picker)
            case .enter: handleOutfitPicker(.buy(picker.index), picker: picker)
            case .escape: handleOutfitPicker(.cancel, picker: picker)
            default: break
            }
            return true
        }
        if let creation = ui.householdCreation {
            let code: String
            switch key {
            case .escape: code = "\u{1b}"
            case .enter: code = "\r"
            case .backspace: code = "\u{7f}"
            case .delete: code = "\u{f728}"
            case .left: code = "\u{f702}"
            case .right: code = "\u{f703}"
            case .up: code = "\u{f700}"
            case .down: code = "\u{f701}"
            case .tab: code = "\t"
            case .pageUp: code = "\u{f72c}"
            case .pageDown: code = "\u{f72d}"
            case .character: return true  // Typed text arrives through text(_:).
            }
            _ = creation.key(code) { [weak self] in self?.confirmCancelHouseholdCreation() }
            return true
        }
        if let picker = ui.familyPicker {
            switch key {
            case .up: picker.moveSelection(-1)
            case .down: picker.moveSelection(1)
            case .escape: handleFamilyPicker(.cancel, picker: picker)
            default: break
            }
            return true
        }
        if activeNeighborhoodDialog != nil {
            if case .escape = key { respondToNeighborhood(-1) }
            return true
        }
        if ui.neighborhood != nil || bridge == nil {
            if case .escape = key, rezoneMode || evictMode {
                rezoneMode = false
                evictMode = false
                ui.neighborhood?.setRezoneMode(false)
                ui.neighborhood?.setEvictMode(false)
            }
            return true
        }
        return nil
    }

    // MARK: Host responses

    func neighborhoodResponse(id: String, ok: Bool, event: [String: Any]) throws {
        if pendingHouseholdAppearanceRequest == id {
            pendingHouseholdAppearanceRequest = nil
            if ok, let result = event["result"] as? [String: Any],
               let catalog = try? JSONDecoder().decode(HouseholdAppearanceCatalog.self, from: JSONSerialization.data(withJSONObject: result)) {
                ui.householdCreation?.setAppearanceCatalog(catalog)
                if let creation = ui.householdCreation, let selection = creation.appearancePreviewSelection() {
                    requestHouseholdAppearancePreview(selection.gender, selection.age, selection.skin, selection.headChoice, selection.bodyChoice, creation: creation)
                }
            } else {
                ui.householdCreation?.failed(event["error"] as? String ?? "Appearance choices could not be loaded.")
            }
        }
        if pendingHouseholdPreviewRequest == id {
            pendingHouseholdPreviewRequest = nil
            do { try loadAppearancePreview(event) }
            catch { ui.householdCreation?.previewFailed("The Sim preview could not be loaded: \(error.localizedDescription)") }
        }
        if pendingHouseholdCreationRequest == id {
            pendingHouseholdCreationRequest = nil
            if ok {
                ui.householdCreation = nil
                renderer.clearAppearancePreview()
                pendingHouseholdPreviewRequest = nil
                pendingHouseholdCreation = nil
                neighborhoodBeforeHouseholdCreation = nil
                log("household moved in")
                if let speed = options.speed { _ = send("speed", ["value": speed]) }
            } else {
                if let reason = event["error"] as? String { log("Household creation: \(reason)") }
                ui.householdCreation?.failed(strings.moveInErrorMessage())
            }
        }
        if let pending = pendingNeighborhood, pending.id == id {
            pendingNeighborhood = nil
            activeNeighborhoodDialog = pending.dialog
            do {
                guard ok, let bridge else { throw ContentError.invalid(event["error"] as? String ?? "The neighborhood could not be loaded.") }
                let neighborhood = try OriginalNeighborhoodOverlay(content: content, device: ui.device, manifestURL: bridge.session.appendingPathComponent("neighborhood.json"),
                                                                   session: bridge.session, font: ui.font)
                guard neighborhood.mode == pending.mode else { throw ContentError.invalid("Neighborhood export returned the wrong mode") }
                if localDialogToken == nil { ui.gameDialog = nil }
                ui.neighborhood = neighborhood
                startNeighborhoodAudio(neighborhood)
                neighborhoodHouseSelected = { [weak self] house in self?.respondToNeighborhood(house) }
            } catch {
                failedNeighborhoodTokens.insert(pending.dialog.token)
                ui.neighborhood = nil
                neighborhoodHouseSelected = nil
                showNeighborhoodError(error)
            }
        }
        if pendingNeighborhoodResponse == id {
            pendingNeighborhoodResponse = nil
            if ok {
                activeNeighborhoodDialog = nil
                ui.neighborhood = nil
                neighborhoodHouseSelected = nil
            } else {
                showNeighborhoodError(ContentError.invalid(event["error"] as? String ?? "The travel selection was rejected."))
                if let neighborhood = ui.neighborhood { startNeighborhoodAudio(neighborhood) }
                neighborhoodHouseSelected = { [weak self] house in self?.respondToNeighborhood(house) }
            }
        }
        if let pending = pendingOutfitChoices, pending.id == id {
            pendingOutfitChoices = nil
            finishOpeningOutfitPicker(event, dialog: pending.dialog)
        } else if pendingOutfitPreview == id {
            pendingOutfitPreview = nil
            if ui.outfitPicker != nil {
                do { try loadAppearancePreview(event) }
                catch { renderer.clearAppearancePreview(); log("Outfit preview: \(error)") }
            }
        }
        if let moveIn = pendingFamilyMoveIn, moveIn.request == id {
            pendingFamilyMoveIn = nil
            if ok {
                neighborhoodBeforeHouseholdCreation = nil
                log("family moved in")
            } else {
                if let reason = event["error"] as? String { log("Move in: \(reason)") }
                cancelHouseholdCreation()
                presentLocalFeedback(title: strings.moveInErrorTitle(), message: strings.moveInErrorMessage())
            }
        }
    }
}

func log(_ message: String) {
    FileHandle.standardError.write(Data("SimsSDL: \(message)\n".utf8))
}
