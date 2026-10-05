import AppKit
import MetalKit
import SimsCore

/// The original Select a Family screen (Res_Nbhd `kPickFamilyBkg` 5041 and controls 5103–5106) shown when a vacant
/// residential lot is chosen. Positions are measured from the 800×600 `Nbhd/PickBkg.bmp` art: the list well spans
/// 20–740 × 70–508, the § and smiley column icons sit at x≈598 and x≈675, and the three bottom slots fit the 92-, 92-
/// and 164-pixel button frames. The Cancel button has no drawn slot; its position is not yet confirmed against the
/// executable.
@MainActor
final class OriginalFamilyPickerOverlay {
    typealias Image = OriginalGameplayOverlay.Image

    struct Family: Decodable, Equatable {
        let id: Int
        let name: String
        let budget: Int
        let netWorth: Int
        let friends: Int
        let members: [String]
    }

    struct DrawItem {
        let image: Image
        let rect: CGRect
        let uv: SIMD4<Float>
    }

    enum Action: Equatable {
        case createFamily
        case moveIn(Family)
        case delete(Family)
        case cancel
    }

    enum Control: Int, CaseIterable {
        case add, delete, moveIn, cancel
    }

    static let rowOrigin = CGPoint(x: 35, y: 85)
    static let rowSize = CGSize(width: 690, height: 68)
    static let rowPitch: CGFloat = 70
    static let rowsPerPage = 6
    static let controlRects: [Control: CGRect] = [
        .add: CGRect(x: 322, y: 530, width: 92, height: 62),
        .delete: CGRect(x: 414, y: 530, width: 92, height: 62),
        .moveIn: CGRect(x: 506, y: 530, width: 164, height: 62),
        .cancel: CGRect(x: 669, y: 537, width: 124, height: 49)
    ]

    let house: Int
    let families: [Family]
    private let background: Image
    private let row: Image
    private let buttons: [Control: (image: Image, frames: Int)]
    private let title: Image
    private let emptyHint: [Image]
    private let rowText: [(name: Image, netWorth: Image, friends: Image)]
    private let labels: [Control: String]
    private(set) var selected: Int?
    private(set) var hoveredRow: Int?
    private(set) var hoveredControl: Control?
    private var scroll = 0

    init(house: Int, families: [Family], content: GameContent, font: SimsBitmapFont, device: MTLDevice, strings: OriginalUIStrings) throws {
        self.house = house
        self.families = families
        func upload(_ path: String) throws -> Image {
            let bitmap = try SimsBitmap(data: content.read(path))
            return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: true)
        }
        func text(_ value: String) throws -> Image { try OriginalGameplayOverlay.text(value, font: font, device: device) }
        background = try upload("UIGraphics/Nbhd/PickBkg.bmp")
        row = try upload("UIGraphics/Nbhd/FamilyPickItemBkg.bmp")
        buttons = [
            .add: (try upload("UIGraphics/Nbhd/PAFAddFamily.bmp"), 4),
            .delete: (try upload("UIGraphics/Nbhd/PAFDeleteFamily.bmp"), 4),
            .moveIn: (try upload("UIGraphics/Nbhd/PAFMoveIn.bmp"), 4),
            .cancel: (try upload("UIGraphics/Nbhd/PAFCancel.bmp"), 6)
        ]
        title = try text(strings.pickFamily(8, fallback: "SELECT A FAMILY"))
        emptyHint = try (try font.wrappedLines(strings.pickFamily(14, fallback: "You can create a new family by clicking on the Create a Family button at the bottom of the screen"), width: 600)).map(text)
        rowText = try families.map { family in
            (try text(family.name), try text(OriginalUIStrings.simoleons(family.netWorth)), try text(String(family.friends)))
        }
        labels = [
            .add: strings.pickFamily(2, fallback: "Create New Family"),
            .delete: strings.pickFamily(4, fallback: "Delete Family"),
            .moveIn: strings.pickFamily(3, fallback: "Move In Family"),
            .cancel: strings.pickFamily(5, fallback: "Cancel")
        ]
        selected = families.isEmpty ? nil : 0
    }

    var selectedFamily: Family? { selected.flatMap { families.indices.contains($0) ? families[$0] : nil } }

    func isEnabled(_ control: Control) -> Bool {
        switch control {
        case .add, .cancel: true
        case .moveIn, .delete: selectedFamily != nil
        }
    }

    private func transform(canvas: CGSize) -> (left: CGFloat, factor: CGFloat) {
        let factor = canvas.height / 600
        return ((canvas.width - 800 * factor) / 2, factor)
    }

    private func logical(_ point: CGPoint, canvas: CGSize) -> CGPoint {
        let (left, factor) = transform(canvas: canvas)
        return CGPoint(x: (point.x - left) / factor, y: point.y / factor)
    }

    private func rowRect(_ visibleIndex: Int) -> CGRect {
        CGRect(x: Self.rowOrigin.x, y: Self.rowOrigin.y + CGFloat(visibleIndex) * Self.rowPitch, width: Self.rowSize.width, height: Self.rowSize.height)
    }

    private var visibleRows: Range<Int> { scroll..<min(families.count, scroll + Self.rowsPerPage) }

    func hover(_ point: CGPoint, canvas: CGSize) {
        let local = logical(point, canvas: canvas)
        hoveredControl = Control.allCases.first { Self.controlRects[$0]!.contains(local) && isEnabled($0) }
        hoveredRow = visibleRows.first { rowRect($0 - scroll).contains(local) }
    }

    func click(_ point: CGPoint, canvas: CGSize) -> Action? {
        let local = logical(point, canvas: canvas)
        if let index = visibleRows.first(where: { rowRect($0 - scroll).contains(local) }) {
            selected = index
            return nil
        }
        guard let control = Control.allCases.first(where: { Self.controlRects[$0]!.contains(local) }), isEnabled(control) else { return nil }
        switch control {
        case .add: return .createFamily
        case .moveIn: return selectedFamily.map { .moveIn($0) }
        case .cancel: return .cancel
        case .delete: return selectedFamily.map { .delete($0) }
        }
    }

    func scroll(by delta: Int) {
        scroll = min(max(0, scroll + delta), max(0, families.count - Self.rowsPerPage))
    }

    func moveSelection(_ delta: Int) {
        guard !families.isEmpty else { return }
        let next = min(max(0, (selected ?? 0) + delta), families.count - 1)
        selected = next
        if next < scroll { scroll = next } else if next >= scroll + Self.rowsPerPage { scroll = next - Self.rowsPerPage + 1 }
    }

    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        let (left, factor) = transform(canvas: canvas)
        func screen(_ rect: CGRect) -> CGRect {
            CGRect(x: left + rect.minX * factor, y: rect.minY * factor, width: rect.width * factor, height: rect.height * factor)
        }
        let rows = visibleRows.map { index -> (label: String, rect: CGRect) in
            let family = families[index]
            let members = family.members.filter { !$0.isEmpty }.joined(separator: ", ")
            return ("\(family.name). \(OriginalUIStrings.simoleons(family.netWorth)). \(family.friends). \(members)", screen(rowRect(index - scroll)))
        }
        let controls: [(label: String, rect: CGRect)] = Control.allCases.filter(isEnabled).map { (labels[$0] ?? "", screen(Self.controlRects[$0]!)) }
        return rows + controls
    }

    func drawItems(canvas: CGSize) -> [DrawItem] {
        let (left, factor) = transform(canvas: canvas)
        func screen(_ rect: CGRect) -> CGRect {
            CGRect(x: left + rect.minX * factor, y: rect.minY * factor, width: rect.width * factor, height: rect.height * factor)
        }
        let whole = SIMD4<Float>(0, 0, 1, 1)
        var items = [DrawItem(image: background, rect: screen(CGRect(x: 0, y: 0, width: 800, height: 600)), uv: whole)]
        items.append(DrawItem(image: title, rect: screen(CGRect(x: 40, y: 42, width: title.size.width, height: title.size.height)), uv: whole))
        if families.isEmpty {
            for (index, line) in emptyHint.enumerated() {
                items.append(DrawItem(image: line, rect: screen(CGRect(x: 400 - line.size.width / 2, y: 260 + CGFloat(index) * line.size.height,
                                                                       width: line.size.width, height: line.size.height)), uv: whole))
            }
        }
        for index in visibleRows {
            let rect = rowRect(index - scroll)
            // FamilyPickItemBkg stacks normal, highlighted and selected frames vertically.
            let frame: Float = selected == index ? 2 : hoveredRow == index ? 1 : 0
            items.append(DrawItem(image: row, rect: screen(rect), uv: SIMD4(0, frame / 3, 1, 1 / 3)))
            let text = rowText[index]
            items.append(DrawItem(image: text.name, rect: screen(CGRect(x: rect.minX + 24, y: rect.midY - text.name.size.height / 2,
                                                                         width: text.name.size.width, height: text.name.size.height)), uv: whole))
            items.append(DrawItem(image: text.netWorth, rect: screen(CGRect(x: 598 - text.netWorth.size.width / 2, y: rect.midY - text.netWorth.size.height / 2,
                                                                             width: text.netWorth.size.width, height: text.netWorth.size.height)), uv: whole))
            items.append(DrawItem(image: text.friends, rect: screen(CGRect(x: 675 - text.friends.size.width / 2, y: rect.midY - text.friends.size.height / 2,
                                                                            width: text.friends.size.width, height: text.friends.size.height)), uv: whole))
        }
        for control in Control.allCases {
            guard let sheet = buttons[control], let rect = Self.controlRects[control] else { continue }
            let (image, frames) = sheet
            // Button sheets: normal, highlighted, pressed, disabled (Cancel adds two more frames that are not used here).
            let frame = !isEnabled(control) ? 3 : hoveredControl == control ? 1 : 0
            items.append(DrawItem(image: image, rect: screen(rect), uv: SIMD4(Float(frame) / Float(frames), 0, 1 / Float(frames), 1)))
        }
        return items
    }
}
