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
        gameplay = try OriginalGameplayOverlay(content: content, font: font, device: device, strings: strings)
        buy = try OriginalBuyOverlay(content: content, font: font, device: device)
        build = try OriginalBuildOverlay(content: content, device: device)
        optionsPanel = try OriginalOptionsPanelOverlay(content: content, device: device, strings: strings, font: font)
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
        return draws
    }
}
