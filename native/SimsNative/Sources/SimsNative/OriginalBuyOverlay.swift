import AppKit
import MetalKit
import SimsCore

@MainActor
final class OriginalBuyOverlay {
    typealias Image = OriginalGameplayOverlay.Image
    typealias Part = OriginalGameplayOverlay.Part
    enum Action { case category(Int), page(Int), select(UInt32) }
    let device: MTLDevice
    let font: SimsBitmapFont
    private let universal: Image
    private let patch: Image
    private let buttons: [Image]
    private let frame: Image
    private let unknown: Image
    private let previous: Image
    private let next: Image
    private var icons: [Image?] = []
    private var footer: [Part] = []
    private var statusKey = ""
    private(set) var page: BuyCatalogPage?
    private(set) var category = 0
    var selection = BuySelection()
    var selected: UInt32? {
        guard case .catalog(let guid) = selection.target else { return nil }
        return guid
    }
    var direction: Int { selection.direction }
    var selectedItem: BuyCatalogPage.Item? { page?.items.first { $0.guid == selected } }

    func choose(_ guid: UInt32, budget: Int?) {
        guard let item = page?.items.first(where: { $0.guid == guid }), item.price <= (budget ?? 0) else { return }
        selection.chooseCatalog(guid)
    }
    func cancelSelection() { selection.cancel() }
    func rotate() { selection.rotate() }

    init(content: GameContent, font: SimsBitmapFont, device: MTLDevice) throws {
        self.device = device
        self.font = font
        func bitmap(_ path: String) throws -> Image {
            let pixels = try SimsBitmap(data: content.read("UIGraphics/cpanel/" + path))
            return try OriginalGameplayOverlay.image(device: device, width: pixels.width, height: pixels.height, pixels: pixels.rgba, magenta: true)
        }
        let pixels = try SimsTarga(data: content.read("UIGraphics/cpanel/Backgrounds/UniversalBack.tga"))
        universal = try OriginalGameplayOverlay.image(device: device, width: pixels.width, height: pixels.height, pixels: pixels.rgba)
        patch = try bitmap("Backgrounds/BuyPatch.bmp")
        buttons = try OriginalBuyLayout.categories.map { try bitmap("Catalog/BuyF" + $0 + ".bmp") }
        frame = try bitmap("Catalog/ThumbTemplate.bmp")
        unknown = try bitmap("CatalogUnknown.bmp")
        previous = try bitmap("Buttons/ScrollLeftBuy.bmp")
        next = try bitmap("Buttons/ScrollRight.bmp")
    }

    func clear(category: Int) {
        self.category = category
        page = nil
        icons = []
        selection.cancel()
    }

    func update(_ page: BuyCatalogPage, root: URL, buildObjects: Bool = false) throws {
        try page.validate(buildObjects: buildObjects)
        let root = root.resolvingSymlinksInPath().standardizedFileURL
        let icons = try page.items.map { item -> Image? in
            guard let icon = item.icon else { return nil }
            let file = root.appendingPathComponent(icon.file).resolvingSymlinksInPath().standardizedFileURL
            guard file.deletingLastPathComponent() == root, (try file.resourceValues(forKeys: [.fileSizeKey]).fileSize ?? Int.max) <= 4 * 1024 * 1024 else {
                throw ContentError.invalid("Catalog thumbnail escapes scene directory or exceeds size limit")
            }
            let bitmap = try SimsBitmap(data: Data(contentsOf: file))
            guard bitmap.width <= 512, bitmap.height <= 512, bitmap.width.isMultiple(of: icon.columns), bitmap.height.isMultiple(of: icon.rows) else {
                throw ContentError.invalid("Invalid catalog thumbnail dimensions")
            }
            return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: true)
        }
        self.page = page
        self.category = page.category
        self.icons = icons
        if selected != nil, !page.items.contains(where: { $0.guid == selected }) { selection.cancel() }
    }

    func updateStatus(_ state: GameplayPanelState) throws {
        let hour = state.hours % 12 == 0 ? 12 : state.hours % 12
        let clock = String(format: "%d:%02d %@", hour, state.minutes, state.hours < 12 ? "AM" : "PM")
        let money = state.budget.map { "§" + String($0) } ?? ""
        let key = clock + money
        guard key != statusKey else { return }
        var parts: [Part] = []
        for (value, x, y) in [(clock, CGFloat(123), CGFloat(85)), (money, CGFloat(178), CGFloat(125))] where !value.isEmpty {
            let image = try OriginalGameplayOverlay.text(value, font: font, device: device)
            parts.append(Part(image: image, rect: CGRect(x: x - image.size.width / (y == 85 ? 2 : 1), y: y, width: image.size.width, height: image.size.height)))
        }
        footer = parts
        statusKey = key
    }

    func statusParts(canvas: CGSize) -> [Part] { footer.map { Part(image: $0.image, rect: $0.rect.offsetBy(dx: 0, dy: canvas.height - 150), uv: $0.uv) } }

    private func categoryRect(_ index: Int, canvas: CGSize) -> CGRect {
        CGRect(origin: OriginalBuyLayout.positions[index], size: CGSize(width: buttons[index].size.width / 4, height: buttons[index].size.height)).offsetBy(dx: 0, dy: canvas.height - 150)
    }
    private func arrowRect(_ forward: Bool, canvas: CGSize) -> CGRect {
        let image = forward ? next : previous
        return CGRect(x: forward ? canvas.width - 24 : 404, y: canvas.height - 100 + 25, width: image.size.width / 4, height: image.size.height)
    }
    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        var controls = OriginalBuyLayout.categories.enumerated().map { ("Buy: " + $0.element, categoryRect($0.offset, canvas: canvas)) }
        if let page {
            controls += page.items.prefix(OriginalBuyLayout.capacity(canvas: canvas)).enumerated().map { index, item in
                (item.name + " — §" + String(item.price), OriginalBuyLayout.thumbnail(index, canvas: canvas))
            }
            if page.offset > 0 { controls.append(("Previous catalog page", arrowRect(false, canvas: canvas))) }
            if page.nextOffset(visibleCapacity: OriginalBuyLayout.capacity(canvas: canvas)) != nil { controls.append(("Next catalog page", arrowRect(true, canvas: canvas))) }
        }
        return controls
    }
    func action(at point: CGPoint, canvas: CGSize) -> Action? {
        if let index = (0..<8).first(where: { categoryRect($0, canvas: canvas).contains(point) }) { return .category(index) }
        guard let page else { return nil }
        if page.offset > 0, arrowRect(false, canvas: canvas).contains(point) { return .page(max(0, page.offset - OriginalBuyLayout.capacity(canvas: canvas))) }
        if let offset = page.nextOffset(visibleCapacity: OriginalBuyLayout.capacity(canvas: canvas)), arrowRect(true, canvas: canvas).contains(point) { return .page(offset) }
        if let index = page.items.prefix(OriginalBuyLayout.capacity(canvas: canvas)).indices.first(where: { OriginalBuyLayout.thumbnail($0, canvas: canvas).contains(point) }) {
            return .select(page.items[index].guid)
        }
        return nil
    }
    func parts(canvas: CGSize, budget: Int?) -> [Part] {
        let top = canvas.height - 150
        var parts = [Part(image: universal, rect: CGRect(x: 0, y: top - 33, width: universal.size.width, height: universal.size.height)),
                     Part(image: patch, rect: CGRect(x: 64, y: top - 33 + 35, width: patch.size.width, height: patch.size.height))]
        parts += footer.map { Part(image: $0.image, rect: $0.rect.offsetBy(dx: 0, dy: top), uv: $0.uv) }
        parts += buttons.enumerated().map { index, image in
            Part(image: image, rect: categoryRect(index, canvas: canvas), uv: SIMD4(index == category ? 0.5 : 0, 0, 0.25, 1))
        }
        if let page {
            for (index, item) in page.items.prefix(OriginalBuyLayout.capacity(canvas: canvas)).enumerated() {
                let rect = OriginalBuyLayout.thumbnail(index, canvas: canvas)
                let state: Float = item.price > (budget ?? 0) ? 2 : item.guid == selected ? 1 : 0
                parts.append(Part(image: frame, rect: rect, uv: SIMD4(state / 4, 0, 0.25, 1)))
                let image = icons[index] ?? unknown
                let columns = icons[index] == nil ? 2 : item.icon?.columns ?? 1
                let rows = icons[index] == nil ? 1 : item.icon?.rows ?? 1
                let size = CGSize(width: image.size.width / CGFloat(columns), height: image.size.height / CGFloat(rows))
                let scale = min(1, min(43 / size.width, 43 / size.height))
                let iconRect = CGRect(x: rect.midX - size.width * scale / 2, y: rect.midY - size.height * scale / 2, width: size.width * scale, height: size.height * scale)
                parts.append(Part(image: image, rect: iconRect, uv: SIMD4(0, 0, 1 / Float(columns), 1 / Float(rows))))
            }
            for forward in [false, true] {
                let enabled = forward ? page.nextOffset(visibleCapacity: OriginalBuyLayout.capacity(canvas: canvas)) != nil : page.offset > 0
                parts.append(Part(image: forward ? next : previous, rect: arrowRect(forward, canvas: canvas), uv: SIMD4(enabled ? 0 : 0.75, 0, 0.25, 1)))
            }
        }
        return parts
    }
}
