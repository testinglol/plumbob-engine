import Foundation
import SimsCore

/// The wardrobe (STR# 220) and pet-adoption (STR# 221) carousel: Previous/Next, a 3D preview of the selected entry,
/// Buy and Cancel. The simulation owns the data: the dialog result is the index of an entry in the engine's valid-outfit
/// list, with response code 1 for a purchase and 0 for cancel. The frame uses the generic dialog art; the original's own
/// layout for this screen was not recovered, so positions are chosen to fit the original labels.
@MainActor
final class OriginalOutfitPickerOverlay {
    typealias Image = OriginalGameplayOverlay.Image

    struct DrawItem {
        let image: Image
        let rect: CGRect
        let uv: SIMD4<Float>
    }

    enum Action: Equatable {
        case previous, next, buy(Int), cancel
    }

    private enum Control: Int, CaseIterable { case previous, next, buy, cancel }

    let token: String
    let pet: Bool
    let names: [String]
    private let font: SimsBitmapFont
    private let device: UIDevice
    private let frame: Image
    private let button: Image
    private let title: Image
    private let labels: [Control: Image]
    private let labelStrings: [Control: String]
    private var nameImages: [Int: Image] = [:]
    private(set) var index = 0
    private(set) var hovered: Int?

    init(token: String, pet: Bool, names: [String], content: GameContent, font: SimsBitmapFont, device: UIDevice, strings: OriginalUIStrings) throws {
        precondition(!names.isEmpty)
        self.token = token
        self.pet = pet
        self.names = names
        self.font = font
        self.device = device
        func upload(_ path: String, magenta: Bool = false) throws -> Image {
            let bitmap = try SimsBitmap(data: content.read(path))
            return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: magenta)
        }
        frame = try upload("UIGraphics/Shared/Dlg/GenDlg.bmp")
        button = try upload("UIGraphics/Shared/Sys/WinBtn.bmp", magenta: true)
        title = try OriginalGameplayOverlay.text(strings.outfitText(pet: pet, 4, fallback: pet ? "Please Select Your Pet" : "Please Select Outfit"), font: font, device: device)
        var labelStrings: [Control: String] = [:]
        labelStrings[.next] = strings.outfitText(pet: pet, 0, fallback: pet ? "Next Pet" : "Next Outfit")
        labelStrings[.previous] = strings.outfitText(pet: pet, 1, fallback: pet ? "Previous Pet" : "Previous Outfit")
        labelStrings[.buy] = strings.outfitText(pet: pet, 2, fallback: pet ? "Buy Pet" : "Buy Outfit")
        labelStrings[.cancel] = strings.outfitText(pet: pet, 3, fallback: "Cancel")
        self.labelStrings = labelStrings
        var labels: [Control: Image] = [:]
        for (control, value) in labelStrings { labels[control] = try OriginalGameplayOverlay.text(value, font: font, device: device) }
        self.labels = labels
    }

    func move(_ delta: Int) {
        index = ((index + delta) % names.count + names.count) % names.count
    }

    private func panel(canvas: CGSize) -> CGRect {
        CGRect(x: (canvas.width - 440) / 2, y: (canvas.height - 380) / 2, width: 440, height: 380)
    }

    /// The area the 3D preview is drawn into, in logical points.
    func previewRect(canvas: CGSize) -> CGRect {
        let area = panel(canvas: canvas)
        return CGRect(x: area.midX - 100, y: area.minY + 46, width: 200, height: 220)
    }

    private func rect(_ control: Control, canvas: CGSize) -> CGRect {
        let area = panel(canvas: canvas)
        switch control {
        case .previous: return CGRect(x: area.minX + 28, y: area.minY + 292, width: 170, height: 33)
        case .next: return CGRect(x: area.maxX - 198, y: area.minY + 292, width: 170, height: 33)
        case .buy: return CGRect(x: area.minX + 28, y: area.maxY - 52, width: 170, height: 33)
        case .cancel: return CGRect(x: area.maxX - 198, y: area.maxY - 52, width: 170, height: 33)
        }
    }

    func hover(_ point: CGPoint, canvas: CGSize) {
        hovered = Control.allCases.first { rect($0, canvas: canvas).contains(point) }?.rawValue
    }

    func click(_ point: CGPoint, canvas: CGSize) -> Action? {
        guard let control = Control.allCases.first(where: { rect($0, canvas: canvas).contains(point) }) else { return nil }
        switch control {
        case .previous: return .previous
        case .next: return .next
        case .buy: return .buy(index)
        case .cancel: return .cancel
        }
    }

    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        Control.allCases.map { ((labelStrings[$0] ?? "") + ($0 == .buy ? ": " + names[index] : ""), rect($0, canvas: canvas)) }
    }

    private func nameImage() -> Image? {
        if let cached = nameImages[index] { return cached }
        guard let image = try? OriginalGameplayOverlay.text("\(names[index])  (\(index + 1)/\(names.count))", font: font, device: device) else { return nil }
        nameImages = [index: image]
        return image
    }

    func drawItems(canvas: CGSize) -> [DrawItem] {
        let area = panel(canvas: canvas)
        let whole = SIMD4<Float>(0, 0, 1, 1)
        let xs = [area.minX, area.minX + 10, area.maxX - 10, area.maxX]
        let ys = [area.minY, area.minY + 10, area.maxY - 10, area.maxY]
        var items: [DrawItem] = []
        for row in 0..<3 {
            for column in 0..<3 {
                items.append(DrawItem(image: frame, rect: CGRect(x: xs[column], y: ys[row], width: xs[column + 1] - xs[column], height: ys[row + 1] - ys[row]),
                                      uv: SIMD4(Float(column) / 3, Float(row) / 3, 1 / 3, 1 / 3)))
            }
        }
        items.append(DrawItem(image: title, rect: CGRect(x: area.midX - title.size.width / 2, y: area.minY + 14, width: title.size.width, height: title.size.height), uv: whole))
        if let name = nameImage() {
            items.append(DrawItem(image: name, rect: CGRect(x: area.midX - name.size.width / 2, y: area.minY + 270, width: name.size.width, height: name.size.height), uv: whole))
        }
        for control in Control.allCases {
            let area = rect(control, canvas: canvas)
            items.append(DrawItem(image: button, rect: area, uv: SIMD4(hovered == control.rawValue ? 0.25 : 0, 0, 0.25, 1)))
            if let label = labels[control] {
                items.append(DrawItem(image: label, rect: CGRect(x: area.midX - label.size.width / 2, y: area.midY - label.size.height / 2,
                                                                 width: label.size.width, height: label.size.height), uv: whole))
            }
        }
        return items
    }
}
