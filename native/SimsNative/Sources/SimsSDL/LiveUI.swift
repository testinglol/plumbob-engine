import Foundation
import SimsCore

/// The original control panel over a live lot, as the macOS renderer composes it: the panel background, the gameplay
/// (or buy, build or options) panel, the universal controls and the speed controls.
@MainActor
final class LiveUI {
    let content: GameContent
    let font: SimsBitmapFont
    let gameplay: OriginalGameplayOverlay
    let buy: OriginalBuyOverlay
    let build: OriginalBuildOverlay
    let optionsPanel: OriginalOptionsPanelOverlay
    let strings: OriginalUIStrings
    let soundOptions: OriginalSoundOptionsOverlay
    private let panel: UITexture
    private var universalTextures: [UITexture] = []
    private var speedTextures: [UITexture] = []

    var buyMode = false
    var buildMode = false
    var optionsMode = false
    var wallsUp = false
    var wallMode = "down"
    var roofsVisible = false
    var viewLevel = 1
    var pieMenu: OriginalPieOverlay?
    var gameDialog: OriginalDialogOverlay?
    var roofPitch: Float = 0.66
    var roofStyle: UInt16 = 16

    var objectEditing: Bool { buyMode || buildMode && (build.objectTool != nil || build.selectedObjectGUID != nil) }
    var selectedCatalogPrice: Int? {
        if buildMode, let guid = build.selectedObjectGUID { return build.page?.items.first { $0.guid == guid }?.price }
        return buy.selectedItem?.price
    }
    func chooseCatalogObject(_ guid: UInt32) {
        if buildMode && build.objectTool == nil && build.kind == .water {
            build.chooseObject(guid, budget: gameplay.state?.budget)
            if build.selectedObjectGUID == guid { buy.selection.chooseCatalog(guid) }
        } else { buy.choose(guid, budget: gameplay.state?.budget) }
    }

    init(content: GameContent) throws {
        self.content = content
        let device = UIDevice()
        func texture(_ path: String, transparent: Bool = false) throws -> UITexture {
            let bitmap = try SimsBitmap(data: content.read(path))
            return UITexture(width: bitmap.width, height: bitmap.height,
                             pixels: try SpritePixels.premultipliedSRGB(bitmap.rgba, removeMagenta: transparent))
        }
        panel = try texture("UIGraphics/cpanel/Backgrounds/PanelBack.bmp")
        font = try SimsBitmapFont(data: content.read("UIGraphics/Fonts/variablesans_10.ffn"))
        let strings = try OriginalUIStrings(content: content)
        self.strings = strings
        gameplay = try OriginalGameplayOverlay(content: content, font: font, device: device, strings: strings)
        buy = try OriginalBuyOverlay(content: content, font: font, device: device)
        build = try OriginalBuildOverlay(content: content, device: device)
        optionsPanel = try OriginalOptionsPanelOverlay(content: content, device: device, strings: strings, font: font)
        soundOptions = try OriginalSoundOptionsOverlay(content: content, font: font, device: device, strings: strings)
        for control in OriginalUniversalControl.all { universalTextures.append(try texture("UIGraphics/cpanel/Buttons/" + control.asset, transparent: true)) }
        for control in OriginalSpeedControl.all { speedTextures.append(try texture(control.asset, transparent: true)) }
    }

    /// Applies a host state report (the `state` or `result` of an event) to the panels.
    func update(state: [String: Any], root: URL) throws {
        wallsUp = state["wallsUp"] as? Bool ?? false
        wallMode = state["wallMode"] as? String ?? (wallsUp ? "up" : "down")
        let panelState = try JSONDecoder().decode(GameplayPanelState.self, from: JSONSerialization.data(withJSONObject: state))
        try gameplay.update(panelState, root: root)
        try buy.updateStatus(panelState)
    }

    /// The panel's draw list for a canvas in pixels.
    func draws(canvas: SIMD2<Float>, scale: Float, speed: Int) throws -> [UIDraw] {
        var draws: [UIDraw] = []
        func rect(_ rect: CGRect) -> SIMD4<Float> {
            SIMD4(Float(rect.minX) * scale, Float(rect.minY) * scale, Float(rect.width) * scale, Float(rect.height) * scale)
        }
        let top = canvas.y - 150 * scale
        draws.append(UIDraw(texture: panel, rect: SIMD4(0, top + 50 * scale, canvas.x, 100 * scale)))
        let logical = CGSize(width: CGFloat(canvas.x / scale), height: CGFloat(canvas.y / scale))
        try gameplay.prepare(canvas: logical)
        let parts = buildMode
            ? build.parts(canvas: logical, budget: gameplay.state?.budget, selectedObject: buy.selected,
                          canUndo: gameplay.state?.canUndo, canRedo: gameplay.state?.canRedo) + buy.statusParts(canvas: logical)
            : buyMode ? buy.parts(canvas: logical, budget: gameplay.state?.budget)
            : optionsMode ? optionsPanel.parts(canvas: logical) : gameplay.parts(canvas: logical)
        for part in parts { draws.append(UIDraw(texture: part.image.texture, rect: rect(part.rect), uv: part.uv)) }
        for item in soundOptions.drawItems(canvas: logical) { draws.append(UIDraw(texture: item.image.texture, rect: rect(item.rect), uv: item.uv)) }
        for (index, control) in OriginalUniversalControl.all.enumerated() {
            let selected: Bool
            switch control.action {
            case .live: selected = !buyMode && !buildMode
            case .buy: selected = buyMode
            case .build: selected = buildMode
            case .wallsUp: selected = wallsUp
            case .wallsCutaway: selected = wallMode == "cutaway"
            case .wallsDown: selected = wallMode == "down"
            case .story1: selected = !roofsVisible && viewLevel == 1
            case .story2: selected = !roofsVisible && viewLevel == 2
            case .roofs: selected = roofsVisible
            case .options: selected = optionsMode
            default: selected = false
            }
            let frame: Float = !control.enabled ? 3 : selected ? 2 : 0
            draws.append(UIDraw(texture: universalTextures[index], rect: rect(control.rect(canvas: logical)), uv: SIMD4(frame / 4, 0, 0.25, 1)))
        }
        for (index, control) in OriginalSpeedControl.all.enumerated() {
            let state: Float = buyMode || buildMode ? 3 : control.speed == speed ? 2 : 0
            let bounds = SIMD4(Float(control.position.x) * scale, canvas.y - Float(OriginalSpeedControl.panelHeight) * scale + Float(control.position.y) * scale,
                               Float(control.size.width) * scale, Float(control.size.height) * scale)
            draws.append(UIDraw(texture: speedTextures[index], rect: bounds,
                                uv: SIMD4(state / Float(control.columns), 0, 1 / Float(control.columns), 1 / Float(control.rows))))
        }
        if let pieMenu {
            pieMenu.prepare(canvas: CGSize(width: CGFloat(canvas.x), height: CGFloat(canvas.y)), scale: CGFloat(scale))
            for (index, label) in pieMenu.labels.enumerated() {
                guard let bounds = pieMenu.layout?.rectangles[index] else { continue }
                draws.append(UIDraw(texture: label.background, rect: rect(bounds)))
                draws.append(UIDraw(texture: label.states[pieMenu.highlighted == index ? 1 : 0], rect: rect(bounds)))
            }
        }
        if let gameDialog { try drawDialog(gameDialog, canvas: canvas, scale: scale, into: &draws) }
        return draws
    }

    private func drawDialog(_ dialog: OriginalDialogOverlay, canvas: SIMD2<Float>, scale: Float, into draws: inout [UIDraw]) throws {
        try dialog.prepare(canvas: CGSize(width: CGFloat(canvas.x), height: CGFloat(canvas.y)), scale: CGFloat(scale))
        func part(_ texture: UITexture, _ rect: CGRect, uv: SIMD4<Float> = SIMD4(0, 0, 1, 1)) {
            draws.append(UIDraw(texture: texture, rect: SIMD4(Float(rect.minX) * scale, Float(rect.minY) * scale,
                                                              Float(rect.width) * scale, Float(rect.height) * scale), uv: uv))
        }
        func centred(_ image: OriginalDialogOverlay.Image, x: CGFloat, y: CGFloat) {
            part(image.texture, CGRect(x: x - image.size.width / 2, y: y, width: image.size.width, height: image.size.height))
        }
        let frame = dialog.rect
        if let background = dialog.phoneBookBackground {
            part(background.texture, frame)
            centred(dialog.title, x: frame.midX, y: frame.minY + 16)
            part(dialog.bodyTexture, dialog.phoneBookFamilyRect)
            part(dialog.bodyTexture, dialog.phoneBookContactRect)
            for row in dialog.phoneBookFamilyRows + dialog.phoneBookContactRows {
                if row.selected { part(dialog.buttonTexture, row.rect, uv: SIMD4(0.5, 0, 0.25, 1)) }
                part(row.image.texture, CGRect(x: row.rect.minX + 7, y: row.rect.midY - row.image.size.height / 2,
                                               width: row.image.size.width, height: row.image.size.height))
            }
        } else {
            let xs = [frame.minX, frame.minX + 10, frame.maxX - 10, frame.maxX]
            let ys = [frame.minY, frame.minY + 10, frame.maxY - 10, frame.maxY]
            for row in 0..<3 {
                for column in 0..<3 {
                    part(dialog.frameTexture, CGRect(x: xs[column], y: ys[row], width: xs[column + 1] - xs[column], height: ys[row + 1] - ys[row]),
                         uv: SIMD4(Float(column) / 3, Float(row) / 3, 1 / 3, 1 / 3))
                }
            }
            centred(dialog.title, x: frame.midX, y: frame.minY + 14)
            for line in dialog.visibleLines { part(line.image.texture, line.rect) }
            if let input = dialog.input {
                part(dialog.bodyTexture, dialog.inputRect)
                part(input.texture, CGRect(x: dialog.inputRect.minX + 4, y: dialog.inputRect.minY + 2, width: input.size.width, height: input.size.height))
            }
        }
        for index in dialog.labels.indices {
            let bounds = dialog.buttonRects[index]
            let disabledCall = dialog.dialog.kind == 10 && index == 0 && dialog.selectedPhoneBookContact() == nil
            part(dialog.buttonTexture, bounds, uv: SIMD4(dialog.submitting || disabledCall ? 0.75 : dialog.hovered == index ? 0.25 : 0, 0, 0.25, 1))
            centred(dialog.labels[index], x: bounds.midX, y: bounds.midY - dialog.labels[index].size.height / 2)
        }
    }
}
