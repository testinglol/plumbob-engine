import AppKit
import MetalKit
import SimsCore

/// Draws one pack-declared `PanelDescription` with original-game primitives: the GenDlg frame, LBoxTile body,
/// WinBtn button sheet, original slider art for meters and the original bitmap font. Element coordinates come from the
/// description's 800×600 logical frame and are centered in the logical canvas like other original screens.
@MainActor
final class OriginalPluginPanelOverlay {
    typealias Image = OriginalGameplayOverlay.Image

    struct DrawItem {
        let image: Image
        let rect: CGRect
        let uv: SIMD4<Float>
    }

    let packID: String
    let description: PanelDescription
    private let font: SimsBitmapFont
    private let device: MTLDevice
    private let frame: Image
    private let body: Image
    private let button: Image
    private let meter: Image
    private let title: Image
    private let closeLabel: String
    private let close: Image
    private var images: [String: Image] = [:]
    private var textCache: [String: [Image]] = [:]
    private(set) var values: [String: String] = [:]
    private(set) var hovered: String?

    init(packID: String, description: PanelDescription, content: GameContent, font: SimsBitmapFont, device: MTLDevice, closeLabel: String) throws {
        try description.validate()
        self.packID = packID
        self.description = description
        self.font = font
        self.device = device
        self.closeLabel = closeLabel
        func upload(_ path: String, transparent: Bool = false) throws -> Image {
            let bitmap = try SimsBitmap(data: content.read(path))
            return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: transparent)
        }
        frame = try upload("UIGraphics/Shared/Dlg/GenDlg.bmp")
        body = try upload("UIGraphics/Shared/Dlg/LBoxTile.bmp")
        button = try upload("UIGraphics/Shared/Sys/WinBtn.bmp", transparent: true)
        meter = try upload("UIGraphics/cpanel/Buttons/optslideroff.bmp", transparent: true)
        title = try OriginalGameplayOverlay.text(description.title, font: font, device: device)
        close = try OriginalGameplayOverlay.text(closeLabel, font: font, device: device)
        for element in description.elements where element.kind == .image {
            guard let resource = element.resource else { continue }
            let data = try content.read(resource)
            let decoded: (width: Int, height: Int, rgba: Data) = resource.lowercased().hasSuffix(".tga")
                ? try { let image = try SimsTarga(data: data); return (image.width, image.height, image.rgba) }()
                : try { let image = try SimsBitmap(data: data); return (image.width, image.height, image.rgba) }()
            images[element.id] = try OriginalGameplayOverlay.image(device: device, width: decoded.width, height: decoded.height,
                                                                   pixels: decoded.rgba, magenta: true)
        }
    }

    /// Replaces the plugin-supplied binding values. Unknown bindings are kept but never drawn.
    func update(values: [String: String]) {
        guard values != self.values else { return }
        self.values = values
    }

    private func origin(canvas: CGSize) -> CGPoint {
        // The description is authored in 800×600 logical coordinates; center that space in wider canvases.
        let left = (canvas.width - CGFloat(PanelDescription.logicalWidth)) / 2
        let top = (canvas.height - CGFloat(PanelDescription.logicalHeight)) / 2
        return CGPoint(x: max(0, left) + CGFloat(description.frame.x), y: max(0, top) + CGFloat(description.frame.y))
    }

    func panelRect(canvas: CGSize) -> CGRect {
        let point = origin(canvas: canvas)
        return CGRect(x: point.x, y: point.y, width: CGFloat(description.frame.width), height: CGFloat(description.frame.height))
    }

    private func rect(_ element: PanelDescription.Element, canvas: CGSize) -> CGRect {
        let point = origin(canvas: canvas)
        return element.frame.cgRect.offsetBy(dx: point.x, dy: point.y)
    }

    private func closeRect(canvas: CGSize) -> CGRect {
        let panel = panelRect(canvas: canvas)
        return CGRect(x: panel.midX - 50, y: panel.maxY - 38, width: 100, height: 28)
    }

    private func lines(_ text: String, width: Int) -> [Image] {
        let key = String(width) + "\u{0}" + text
        if let cached = textCache[key] { return cached }
        let wrapped = text.split(separator: "\n", omittingEmptySubsequences: false).flatMap { line in
            (try? font.wrappedLines(String(line), width: max(8, width))) ?? [String(line)]
        }
        let rendered = wrapped.compactMap { try? OriginalGameplayOverlay.text($0, font: font, device: device) }
        if textCache.count > 256 { textCache.removeAll() }
        textCache[key] = rendered
        return rendered
    }

    enum Hit: Equatable {
        case action(String)
        case close
        case inside
    }

    func hit(_ point: CGPoint, canvas: CGSize, scale: CGFloat) -> Hit? {
        let logical = CGSize(width: canvas.width / scale, height: canvas.height / scale)
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        if closeRect(canvas: logical).contains(local) { return .close }
        if let element = description.elements.first(where: { $0.kind == .button && rect($0, canvas: logical).contains(local) }), let action = element.action {
            return .action(action)
        }
        return panelRect(canvas: logical).contains(local) ? .inside : nil
    }

    func hover(_ point: CGPoint, canvas: CGSize, scale: CGFloat) {
        let logical = CGSize(width: canvas.width / scale, height: canvas.height / scale)
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        hovered = closeRect(canvas: logical).contains(local) ? "close" :
            description.elements.first(where: { $0.kind == .button && rect($0, canvas: logical).contains(local) })?.id
    }

    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        var result = description.elements.compactMap { element -> (label: String, rect: CGRect)? in
            let text = element.accessibilityLabel ?? description.displayText(for: element, values: values)
            switch element.kind {
            case .button: return (text, rect(element, canvas: canvas))
            case .meter:
                let fraction = description.meterFraction(for: element, values: values).map { String(Int(($0 * 100).rounded())) + "%" } ?? ""
                return ((element.accessibilityLabel ?? element.id) + " " + fraction, rect(element, canvas: canvas))
            case .label, .list, .image:
                return text.isEmpty ? nil : (text, rect(element, canvas: canvas))
            }
        }
        result.append((closeLabel, closeRect(canvas: canvas)))
        return result
    }

    func drawItems(canvas: CGSize) -> [DrawItem] {
        let panel = panelRect(canvas: canvas)
        var items: [DrawItem] = []
        if description.framed ?? true {
            let xs = [panel.minX, panel.minX + 10, panel.maxX - 10, panel.maxX]
            let ys = [panel.minY, panel.minY + 10, panel.maxY - 10, panel.maxY]
            for row in 0..<3 {
                for column in 0..<3 {
                    items.append(DrawItem(image: frame, rect: CGRect(x: xs[column], y: ys[row], width: xs[column + 1] - xs[column], height: ys[row + 1] - ys[row]),
                                          uv: SIMD4(Float(column) / 3, Float(row) / 3, 1 / 3, 1 / 3)))
                }
            }
            items.append(DrawItem(image: title, rect: CGRect(x: panel.midX - title.size.width / 2, y: panel.minY + 12,
                                                             width: title.size.width, height: title.size.height), uv: SIMD4(0, 0, 1, 1)))
        }
        let whole = SIMD4<Float>(0, 0, 1, 1)
        for element in description.elements {
            let area = rect(element, canvas: canvas)
            switch element.kind {
            case .label:
                for (index, line) in lines(description.displayText(for: element, values: values), width: Int(area.width)).enumerated() {
                    let y = area.minY + CGFloat(index * font.lineHeight)
                    guard y + line.size.height <= area.maxY + 3 else { break }
                    items.append(DrawItem(image: line, rect: CGRect(x: area.minX, y: y, width: min(line.size.width, area.width), height: line.size.height),
                                          uv: SIMD4(0, 0, Float(min(1, area.width / line.size.width)), 1)))
                }
            case .list:
                items.append(DrawItem(image: body, rect: area, uv: whole))
                for (index, line) in lines(description.displayText(for: element, values: values), width: Int(area.width) - 8).enumerated() {
                    let y = area.minY + 2 + CGFloat(index * font.lineHeight)
                    guard y + line.size.height <= area.maxY else { break }
                    items.append(DrawItem(image: line, rect: CGRect(x: area.minX + 4, y: y, width: min(line.size.width, area.width - 8), height: line.size.height),
                                          uv: SIMD4(0, 0, Float(min(1, (area.width - 8) / line.size.width)), 1)))
                }
            case .button:
                items.append(DrawItem(image: button, rect: area, uv: SIMD4(hovered == element.id ? 0.25 : 0, 0, 0.25, 1)))
                if let label = lines(description.displayText(for: element, values: values), width: Int.max / 4).first {
                    items.append(DrawItem(image: label, rect: CGRect(x: area.midX - label.size.width / 2, y: area.midY - label.size.height / 2,
                                                                     width: label.size.width, height: label.size.height), uv: whole))
                }
            case .meter:
                let segment = min(area.width / 4, area.height * 2)
                items.append(DrawItem(image: meter, rect: CGRect(x: area.minX, y: area.minY, width: segment, height: area.height), uv: SIMD4(0, 0, 0.25, 1)))
                items.append(DrawItem(image: meter, rect: CGRect(x: area.minX + segment, y: area.minY, width: area.width - segment * 2, height: area.height),
                                      uv: SIMD4(0.25, 0, 0.25, 1)))
                items.append(DrawItem(image: meter, rect: CGRect(x: area.maxX - segment, y: area.minY, width: segment, height: area.height), uv: SIMD4(0.5, 0, 0.25, 1)))
                if let fraction = description.meterFraction(for: element, values: values) {
                    items.append(DrawItem(image: meter, rect: CGRect(x: area.minX + (area.width - segment) * CGFloat(fraction), y: area.minY,
                                                                     width: segment, height: area.height), uv: SIMD4(0.75, 0, 0.25, 1)))
                }
            case .image:
                if let image = images[element.id] { items.append(DrawItem(image: image, rect: area, uv: whole)) }
            }
        }
        let closeArea = closeRect(canvas: canvas)
        items.append(DrawItem(image: button, rect: closeArea, uv: SIMD4(hovered == "close" ? 0.25 : 0, 0, 0.25, 1)))
        items.append(DrawItem(image: close, rect: CGRect(x: closeArea.midX - close.size.width / 2, y: closeArea.midY - close.size.height / 2,
                                                         width: close.size.width, height: close.size.height), uv: whole))
        return items
    }
}
