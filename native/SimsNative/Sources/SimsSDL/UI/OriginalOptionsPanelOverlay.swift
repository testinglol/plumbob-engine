import Foundation
import SimsCore

/// The original control-panel Options mode. Button offsets come from UIText STR# 145 (`optionstrs`), which stores
/// "(x;y)" positions before each button's tooltip: Neighborhood (88;6), Save (29;6), Quit (159;6), Graphics (29;58),
/// Sound (89;58) and Play (151;58). The executable creates the buttons from the ID table at 0x66c364 in that order
/// (FUN_00514110). Offsets are relative to the sub-panel origin, which sits right of the 220-pixel universal panel on
/// top of `PanelBack.bmp`.
@MainActor
final class OriginalOptionsPanelOverlay {
    typealias Part = OriginalGameplayOverlay.Part
    typealias Image = OriginalGameplayOverlay.Image

    enum Button: Int, CaseIterable {
        case neighborhood, save, quit, graphics, sound, play

        var asset: String {
            switch self {
            case .neighborhood: "UIGraphics/cpanel/Buttons/OptNbhd.bmp"
            case .save: "UIGraphics/cpanel/Buttons/OptSave.BMP"
            case .quit: "UIGraphics/cpanel/Buttons/OptExit.bmp"
            case .graphics: "UIGraphics/cpanel/Buttons/optgraphics.bmp"
            case .sound: "UIGraphics/cpanel/Buttons/optsound.bmp"
            case .play: "UIGraphics/cpanel/Buttons/optplay.bmp"
            }
        }

        /// STR# 145 index of the "(x;y)" position; the tooltip follows at the next index.
        var stringIndex: Int { [0, 2, 4, 6, 8, 10][rawValue] }
        var fallbackPosition: CGPoint { [CGPoint(x: 88, y: 6), CGPoint(x: 29, y: 6), CGPoint(x: 159, y: 6), CGPoint(x: 29, y: 58), CGPoint(x: 89, y: 58), CGPoint(x: 151, y: 58)][rawValue] }
        var fallbackLabel: String { ["Neighborhood", "Save", "Quit", "Graphics Options", "Sound Options", "Play Options"][rawValue] }
    }

    enum Page { case none, graphics, sound, play }

    /// Persisted Play Options (UIText STR# 145 entries 54–67 and 72–74). Only options the native client honors are enabled.
    struct PlayOptions: Codable, Equatable {
        var autoCenter = true
        var freeWill = true
        var edgeScrolling = true
        var quickTips = true
        var lighting = true
        var simInBackground = false
    }

    enum PlayOption: Int, CaseIterable {
        // Play page, column B (STR# 145 entries 54/55): original order of the option text blocks.
        case autoCenter, freeWill, edgeScrolling, simInBackground
        // Play page, column A (entry 53 origin): the second group of text blocks after Reset Tutorial.
        case quickTips, autoSnapshot, livePIP, exportHTML
        // Graphics page (entries 12/13).
        case antiAlias, shadows, lighting, interfaceEffects

        var page: Page { rawValue < 8 ? .play : .graphics }
        var row: Int { rawValue % 4 }
        var isColumnA: Bool { (4..<8).contains(rawValue) }

        /// STR# 145 index of the label; the "About" title and text follow at +1 and +2.
        var stringIndex: Int { [56, 59, 62, 65, 72, 75, 78, 81, 14, 17, 20, 23][rawValue] }
        var fallbackLabel: String {
            ["Auto-Centering", "Free Will", "Edge Scrolling", "Sim In Background", "Quick Tips", "Auto Snapshot", "Live PIP", "Export HTML",
             "Anti-alias", "Shadows", "Lighting", "Interface Effects"][rawValue]
        }
        /// Options without a native effect stay disabled: no auto-centering events, snapshots, picture-in-picture windows,
        /// HTML export, shadows, anti-aliasing or interface effects exist yet.
        var isImplemented: Bool { [.freeWill, .edgeScrolling, .simInBackground, .quickTips, .lighting].contains(self) }

        func value(_ options: PlayOptions) -> Bool {
            switch self {
            case .autoCenter: options.autoCenter
            case .freeWill: options.freeWill
            case .edgeScrolling: options.edgeScrolling
            case .quickTips: options.quickTips
            case .lighting: options.lighting
            case .simInBackground: options.simInBackground
            case .antiAlias, .shadows, .interfaceEffects: true
            case .autoSnapshot, .livePIP, .exportHTML: false
            }
        }

        func toggled(_ options: PlayOptions) -> PlayOptions {
            var copy = options
            switch self {
            case .lighting: copy.lighting.toggle()
            case .freeWill: copy.freeWill.toggle()
            case .edgeScrolling: copy.edgeScrolling.toggle()
            case .quickTips: copy.quickTips.toggle()
            case .simInBackground: copy.simInBackground.toggle()
            case .autoCenter, .antiAlias, .shadows, .interfaceEffects, .autoSnapshot, .livePIP, .exportHTML: break
            }
            return copy
        }
    }

    /// STR# 145 entries 54/55: first checkbox row and row size, relative to the sub-panel origin.
    private var playRows = (origin: CGPoint(x: 275, y: 9), size: CGSize(width: 200, height: 20))
    private var columnAOrigin = CGPoint(x: 130, y: 0)
    private let checkbox: Image
    private var playLabels: [PlayOption: Image] = [:]
    private var playAbout: [PlayOption: String] = [:]
    var playOptions = PlayOptions()
    private(set) var hoveredOption: PlayOption?

    static let subpanelOrigin = CGPoint(x: 220, y: 50)
    /// STR# 145 entries 42/43: the first sound slider row and its row size.
    static func soundRows(strings: OriginalUIStrings) -> (origin: CGPoint, size: CGSize) {
        (OriginalUIStrings.point(strings.optionString(42, fallback: "(305;13)")) ?? CGPoint(x: 305, y: 13),
         OriginalUIStrings.point(strings.optionString(43, fallback: "(200;28)")).map { CGSize(width: $0.x, height: $0.y) } ?? CGSize(width: 200, height: 28))
    }

    private let universal: Image
    private let patch: Image
    private let buttons: [Button: Image]
    private let positions: [Button: CGPoint]
    let labels: [Button: String]
    private(set) var page = Page.none
    private(set) var hovered: Button?

    init(content: GameContent, device: UIDevice, strings: OriginalUIStrings, font: SimsBitmapFont) throws {
        func bitmap(_ path: String) throws -> Image {
            let image = try SimsBitmap(data: content.read(path))
            return try OriginalGameplayOverlay.image(device: device, width: image.width, height: image.height, pixels: image.rgba, magenta: true)
        }
        let base = try SimsTarga(data: content.read("UIGraphics/cpanel/Backgrounds/UniversalBack.tga"))
        universal = try OriginalGameplayOverlay.image(device: device, width: base.width, height: base.height, pixels: base.rgba)
        patch = try bitmap("UIGraphics/cpanel/Backgrounds/OptionsPatch.bmp")
        var buttons: [Button: Image] = [:]
        var positions: [Button: CGPoint] = [:]
        var labels: [Button: String] = [:]
        for button in Button.allCases {
            buttons[button] = try bitmap(button.asset)
            positions[button] = OriginalUIStrings.point(strings.optionString(button.stringIndex, fallback: "")) ?? button.fallbackPosition
            labels[button] = strings.optionString(button.stringIndex + 1, fallback: button.fallbackLabel)
        }
        checkbox = try bitmap("UIGraphics/cpanel/Buttons/optcheckbox.bmp")
        if let origin = OriginalUIStrings.point(strings.optionString(54, fallback: "")) { playRows.origin = origin }
        if let origin = OriginalUIStrings.point(strings.optionString(53, fallback: "")) { columnAOrigin = origin }
        if let size = OriginalUIStrings.point(strings.optionString(55, fallback: "")) { playRows.size = CGSize(width: size.x, height: size.y) }
        for option in PlayOption.allCases {
            playLabels[option] = try OriginalGameplayOverlay.text(strings.optionString(option.stringIndex, fallback: option.fallbackLabel), font: font, device: device)
            playAbout[option] = strings.optionString(option.stringIndex + 2, fallback: "")
        }
        self.buttons = buttons
        self.positions = positions
        self.labels = labels
    }

    func isEnabled(_ button: Button) -> Bool { true }

    func select(_ page: Page) { self.page = page }

    private func rect(_ button: Button, top: CGFloat) -> CGRect {
        guard let image = buttons[button], let position = positions[button] else { return .zero }
        // Option button sheets hold normal, highlighted, pressed and disabled frames side by side.
        return CGRect(x: Self.subpanelOrigin.x + position.x, y: top + Self.subpanelOrigin.y + position.y,
                      width: image.size.width / 4, height: image.size.height)
    }

    func button(at point: CGPoint, canvas: CGSize) -> Button? {
        let top = canvas.height - 150
        return Button.allCases.first { rect($0, top: top).contains(point) }
    }

    func hover(_ point: CGPoint, canvas: CGSize) {
        hovered = button(at: point, canvas: canvas).flatMap { isEnabled($0) ? $0 : nil }
        hoveredOption = option(at: point, canvas: canvas)
    }

    private func optionRect(_ option: PlayOption, top: CGFloat) -> CGRect {
        let origin = option.isColumnA ? columnAOrigin : playRows.origin
        return CGRect(x: Self.subpanelOrigin.x + origin.x, y: top + Self.subpanelOrigin.y + origin.y + CGFloat(option.row) * playRows.size.height,
                      width: playRows.size.width, height: playRows.size.height)
    }

    func option(at point: CGPoint, canvas: CGSize) -> PlayOption? {
        guard page == .play || page == .graphics else { return nil }
        let top = canvas.height - 150
        return PlayOption.allCases.first { $0.page == page && optionRect($0, top: top).contains(point) }
    }

    /// The original "About" help text for the hovered Play option.
    func aboutText(at point: CGPoint, canvas: CGSize) -> String? {
        option(at: point, canvas: canvas).flatMap { playAbout[$0] }.flatMap { $0.isEmpty ? nil : $0 }
    }

    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        let top = canvas.height - 150
        let buttonControls: [(label: String, rect: CGRect)] = Button.allCases.filter(isEnabled).map { (labels[$0] ?? $0.fallbackLabel, rect($0, top: top)) }
        guard page == .play || page == .graphics else { return buttonControls }
        let optionControls: [(label: String, rect: CGRect)] = PlayOption.allCases.filter { $0.page == page && $0.isImplemented }.map {
            (labelText($0) + ($0.value(playOptions) ? ", on" : ", off"), optionRect($0, top: top))
        }
        return buttonControls + optionControls
    }

    private func labelText(_ option: PlayOption) -> String { option.fallbackLabel }

    func parts(canvas: CGSize) -> [Part] {
        let top = canvas.height - 150
        var parts = [Part(image: universal, rect: CGRect(x: 0, y: top - 33, width: universal.size.width, height: universal.size.height))]
        // Centered behind the universal Options button (193,125 in the 183-pixel universal panel); placement inferred.
        parts.append(Part(image: patch, rect: CGRect(x: 186, y: top - 33 + 86, width: patch.size.width, height: patch.size.height)))
        for button in Button.allCases {
            guard let image = buttons[button] else { continue }
            let selected = (button == .sound && page == .sound) || (button == .graphics && page == .graphics) || (button == .play && page == .play)
            let frame: Float = !isEnabled(button) ? 3 : selected ? 2 : hovered == button ? 1 : 0
            parts.append(Part(image: image, rect: rect(button, top: top), uv: SIMD4(frame / 4, 0, 0.25, 1)))
        }
        if page == .play || page == .graphics {
            for option in PlayOption.allCases where option.page == page {
                let area = optionRect(option, top: top)
                // Checkbox sheet: [off, on] × [normal, hover, disabled], 20 pixels wide each.
                let pair: Float = !option.isImplemented ? 2 : hoveredOption == option ? 1 : 0
                let frame = pair * 2 + (option.value(playOptions) ? 1 : 0)
                parts.append(Part(image: checkbox, rect: CGRect(x: area.minX, y: area.minY, width: checkbox.size.width / 6, height: checkbox.size.height),
                                  uv: SIMD4(frame / 6, 0, 1 / 6, 1)))
                if let label = playLabels[option] {
                    parts.append(Part(image: label, rect: CGRect(x: area.minX + checkbox.size.width / 6 + 6, y: area.midY - label.size.height / 2,
                                                                 width: label.size.width, height: label.size.height)))
                }
            }
        }
        return parts
    }
}
