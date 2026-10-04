import Foundation
import SimsCore

@MainActor
final class OriginalSoundOptionsOverlay {
    typealias Image = OriginalGameplayOverlay.Image

    struct DrawItem {
        let image: Image
        let rect: CGRect
        let uv: SIMD4<Float>
    }

    struct VolumeChange {
        let group: String
        let volume: Float
        let previousVolume: Float
    }

    private struct Slider {
        let group: String
        let label: String
        let labelImage: Image
        let off: Image
        let on: Image
    }

    private let frame: Image
    private let body: Image
    private let button: Image
    private let sliders: [Slider]
    private let buttonLabel: Image
    private let title: Image
    private let valueLabels: [Image]
    private let closeLabel: String
    private var values: [String: Float] = ["FX": 1, "MUSIC": 1, "VOX": 1, "AMBIENCE": 1]
    private var draggingGroup: String?
    private(set) var isVisible = false
    private(set) var hoveredClose = false
    /// When set, the sliders are drawn inside the control panel's Options mode like the original game
    /// (rows from STR# 145 entries 42/43, relative to the sub-panel origin) instead of in a centered dialog.
    private(set) var embeddedRows: (origin: CGPoint, size: CGSize)?
    var isEmbedded: Bool { embeddedRows != nil }
    var isDragging: Bool { draggingGroup != nil }

    init(content: GameContent, font: SimsBitmapFont, device: UIDevice, strings: OriginalUIStrings) throws {
        func upload(_ path: String, transparent: Bool = false) throws -> Image {
            let bitmap = try SimsBitmap(data: content.read(path))
            return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height,
                                                    pixels: bitmap.rgba, magenta: transparent)
        }
        func text(_ value: String) throws -> Image {
            let raster = try font.rasterize(value, color: SIMD3(255, 255, 255))
            return try OriginalGameplayOverlay.image(device: device, width: raster.width, height: raster.height,
                                                    pixels: raster.rgba)
        }
        frame = try upload("UIGraphics/Shared/Dlg/GenDlg.bmp")
        body = try upload("UIGraphics/Shared/Dlg/LBoxTile.bmp")
        button = try upload("UIGraphics/Shared/Sys/WinBtn.bmp", transparent: true)
        let rows: [(String, String)] = [
            ("FX", strings.soundEffectVolume()),
            ("MUSIC", strings.soundMusicVolume()),
            ("VOX", strings.soundVoiceVolume())
        ]
        let sliderOff = try upload("UIGraphics/cpanel/Buttons/optslideroff.bmp", transparent: true)
        let sliderOn = try upload("UIGraphics/cpanel/Buttons/optslideron.bmp", transparent: true)
        sliders = try rows.map { row in
            Slider(group: row.0, label: row.1,
                   labelImage: try text(row.1),
                   off: sliderOff,
                   on: sliderOn)
        }
        title = try text(strings.soundOptionsTitle())
        closeLabel = strings.okButton()
        buttonLabel = try text(closeLabel)
        valueLabels = try (0...10).map { try text(String($0) + "/10") }
    }

    func show() { isVisible = true }

    /// Shows the sliders inside the control panel; `origin` is relative to the sub-panel origin.
    func showEmbedded(rows: (origin: CGPoint, size: CGSize)) {
        embeddedRows = (CGPoint(x: OriginalOptionsPanelOverlay.subpanelOrigin.x + rows.origin.x, y: OriginalOptionsPanelOverlay.subpanelOrigin.y + rows.origin.y), rows.size)
        isVisible = true
    }

    func dismiss() {
        isVisible = false
        embeddedRows = nil
        draggingGroup = nil
        hoveredClose = false
    }

    func updateVolumes(_ raw: [String: Any]) {
        for group in Array(values.keys) {
            if let volume = (raw[group] as? NSNumber)?.floatValue, volume.isFinite {
                values[group] = min(1, max(0, volume))
            }
        }
    }

    func restore(_ change: VolumeChange) {
        guard values[change.group] == change.volume else { return }
        values[change.group] = change.previousVolume
    }

    func pointerDown(_ point: CGPoint, canvas: CGSize, scale: CGFloat) -> VolumeChange? {
        guard isVisible else { return nil }
        draggingGroup = group(at: point, canvas: canvas, scale: scale)
        return updatePointer(point, canvas: canvas, scale: scale)
    }

    func pointerDragged(_ point: CGPoint, canvas: CGSize, scale: CGFloat) -> VolumeChange? {
        guard isVisible else { return nil }
        return updatePointer(point, canvas: canvas, scale: scale)
    }

    func pointerUp(_ point: CGPoint, canvas: CGSize, scale: CGFloat) -> VolumeChange? {
        guard isVisible else { return nil }
        let change = updatePointer(point, canvas: canvas, scale: scale)
        draggingGroup = nil
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        if !isEmbedded, closeRect(canvas: CGSize(width: canvas.width / scale, height: canvas.height / scale)).contains(local) { dismiss() }
        return change
    }

    func click(_ point: CGPoint, canvas: CGSize, scale: CGFloat) -> VolumeChange? {
        guard isVisible else { return nil }
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        let logicalCanvas = CGSize(width: canvas.width / scale, height: canvas.height / scale)
        if !isEmbedded, closeRect(canvas: logicalCanvas).contains(local) {
            dismiss()
            return nil
        }
        if let group = group(at: point, canvas: canvas, scale: scale) {
            draggingGroup = group
            defer { draggingGroup = nil }
            return updatePointer(point, canvas: canvas, scale: scale)
        }
        return nil
    }

    func hover(_ point: CGPoint, canvas: CGSize, scale: CGFloat) {
        guard isVisible else { return }
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        hoveredClose = closeRect(canvas: CGSize(width: canvas.width / scale, height: canvas.height / scale)).contains(local)
    }

    func contains(_ point: CGPoint, canvas: CGSize, scale: CGFloat) -> Bool {
        guard isVisible else { return false }
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        let logical = CGSize(width: canvas.width / scale, height: canvas.height / scale)
        if isEmbedded {
            return sliders.indices.contains { trackRect(index: $0, panel: panelRect(canvas: logical)).insetBy(dx: -110, dy: -10).contains(local) }
        }
        return panelRect(canvas: logical).contains(local)
    }

    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        guard isVisible else { return [] }
        let panel = panelRect(canvas: canvas)
        let sliderControls = sliders.enumerated().flatMap { entry in
            let (index, slider) = entry
            let track = trackRect(index: index, panel: panel)
            let thumbWidth = track.width * 0.25
            let valueWidth = track.width - thumbWidth
            return (0...10).map { step in
                (slider.label + " volume " + String(step) + " of 10",
                 CGRect(x: track.minX + CGFloat(step) * valueWidth / 10 - 10, y: track.minY - 8, width: 20, height: 30))
            }
        }
        return isEmbedded ? sliderControls : sliderControls + [(closeLabel, closeRect(canvas: canvas))]
    }

    func drawItems(canvas: CGSize) -> [DrawItem] {
        guard isVisible else { return [] }
        let panel = panelRect(canvas: canvas)
        let xs = [panel.minX, panel.minX + 10, panel.maxX - 10, panel.maxX]
        let ys = [panel.minY, panel.minY + 10, panel.maxY - 10, panel.maxY]
        var items: [DrawItem] = []
        for row in 0..<3 where !isEmbedded {
            for column in 0..<3 {
                items.append(DrawItem(image: frame,
                                      rect: CGRect(x: xs[column], y: ys[row], width: xs[column + 1] - xs[column], height: ys[row + 1] - ys[row]),
                                      uv: SIMD4(Float(column) / 3, Float(row) / 3, 1 / 3, 1 / 3)))
            }
        }
        let contentRect = panel.insetBy(dx: 12, dy: 12)
        if !isEmbedded { items.append(DrawItem(image: body, rect: contentRect, uv: SIMD4(0, 0, 1, 1)))
        items.append(DrawItem(image: title,
                              rect: CGRect(x: panel.midX - title.size.width / 2, y: panel.minY + 22,
                                           width: title.size.width, height: title.size.height),
                              uv: SIMD4(0, 0, 1, 1))) }
        for (index, slider) in sliders.enumerated() {
            let track = trackRect(index: index, panel: panel)
            let y = track.midY
            items.append(DrawItem(image: slider.labelImage,
                                  rect: CGRect(x: isEmbedded ? track.minX - 8 - slider.labelImage.size.width : panel.minX + 28, y: y - slider.labelImage.size.height / 2,
                                               width: slider.labelImage.size.width, height: slider.labelImage.size.height),
                                  uv: SIMD4(0, 0, 1, 1)))
            let value = values[slider.group] ?? 1
            let texture = draggingGroup == slider.group ? slider.on : slider.off
            let segment = track.width * 0.25
            items.append(DrawItem(image: texture,
                                  rect: CGRect(x: track.minX, y: track.minY, width: segment, height: track.height),
                                  uv: SIMD4(0, 0, 0.25, 1)))
            items.append(DrawItem(image: texture,
                                  rect: CGRect(x: track.minX + segment, y: track.minY, width: track.width - segment * 2, height: track.height),
                                  uv: SIMD4(0.25, 0, 0.25, 1)))
            items.append(DrawItem(image: texture,
                                  rect: CGRect(x: track.maxX - segment, y: track.minY, width: segment, height: track.height),
                                  uv: SIMD4(0.5, 0, 0.25, 1)))
            items.append(DrawItem(image: texture,
                                  rect: CGRect(x: track.minX + (track.width - segment) * CGFloat(value), y: track.minY,
                                               width: segment, height: track.height),
                                  uv: SIMD4(0.75, 0, 0.25, 1)))
            let valueImage = valueLabels[min(10, max(0, Int((value * 10).rounded())))]
            items.append(DrawItem(image: valueImage,
                                  rect: CGRect(x: track.maxX + 10, y: track.midY - valueImage.size.height / 2,
                                               width: valueImage.size.width, height: valueImage.size.height),
                                  uv: SIMD4(0, 0, 1, 1)))
        }
        if isEmbedded { return items }
        let close = closeRect(canvas: canvas)
        items.append(DrawItem(image: button, rect: close,
                              uv: SIMD4(hoveredClose ? 0.25 : 0, 0, 0.25, 1)))
        items.append(DrawItem(image: buttonLabel, rect: CGRect(x: close.midX - buttonLabel.size.width / 2,
                                                               y: close.midY - buttonLabel.size.height / 2,
                                                               width: buttonLabel.size.width, height: buttonLabel.size.height),
                              uv: SIMD4(0, 0, 1, 1)))
        return items
    }

    private func updatePointer(_ point: CGPoint, canvas: CGSize, scale: CGFloat) -> VolumeChange? {
        guard let group = draggingGroup else { return nil }
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        guard let index = sliders.firstIndex(where: { $0.group == group }) else { return nil }
        let track = trackRect(index: index, panel: panelRect(canvas: CGSize(width: canvas.width / scale, height: canvas.height / scale)))
        let valueWidth = track.width * 0.75
        let volume = Float(min(10, max(0, Int(((local.x - track.minX) / valueWidth * 10).rounded())))) / 10
        let previousVolume = values[group] ?? 1
        guard abs(previousVolume - volume) > 0.0001 else { return nil }
        values[group] = volume
        return VolumeChange(group: group, volume: volume, previousVolume: previousVolume)
    }

    private func group(at point: CGPoint, canvas: CGSize, scale: CGFloat) -> String? {
        let logical = CGSize(width: canvas.width / scale, height: canvas.height / scale)
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        let panel = panelRect(canvas: logical)
        return sliders.indices.first(where: { trackRect(index: $0, panel: panel).insetBy(dx: 0, dy: -12).contains(local) }).map { sliders[$0].group }
    }

    private func panelRect(canvas: CGSize) -> CGRect {
        if let embeddedRows {
            // Embedded rows are measured from the top of the 150-pixel live control panel.
            let top = canvas.height - 150
            return CGRect(x: embeddedRows.origin.x, y: top + embeddedRows.origin.y, width: embeddedRows.size.width + 120, height: embeddedRows.size.height * CGFloat(sliders.count))
        }
        return CGRect(x: (canvas.width - 440) / 2, y: (canvas.height - 330) / 2, width: 440, height: 330)
    }

    private func trackRect(index: Int, panel: CGRect) -> CGRect {
        if let embeddedRows {
            let row = embeddedRows.size.height
            return CGRect(x: panel.minX, y: panel.minY + CGFloat(index) * row + (row - 14) / 2, width: embeddedRows.size.width, height: 14)
        }
        return CGRect(x: panel.minX + 138, y: panel.minY + 92 + CGFloat(index) * 47 - 7, width: 220, height: 14)
    }

    private func closeRect(canvas: CGSize) -> CGRect {
        let panel = panelRect(canvas: canvas)
        return CGRect(x: panel.midX - 50, y: panel.maxY - 48, width: 100, height: 28)
    }
}
