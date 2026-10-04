import AppKit
import MetalKit
import SimsCore

@MainActor
final class OriginalBuildOverlay {
    typealias Image = OriginalGameplayOverlay.Image
    typealias Part = OriginalGameplayOverlay.Part
    enum Action { case page(Int), select(UInt16), kind(BuildCatalogPage.Kind), objectTool(OriginalBuildObjectTool), selectObject(UInt32), terrain, terrainMode(TerrainBrushMode), history(ConstructionHistoryAction) }
    private let device: MTLDevice
    private let universal: Image
    private let patch: Image
    private let buttons: [Image]
    private let frame: Image
    private let unknown: Image
    private let previous: Image
    private let next: Image
    private let terrainModeIcons: [Image]
    private let historyIcons: [Image]
    private var icons: [Image?] = []
    private(set) var objectTool: OriginalBuildObjectTool?
    private(set) var objectPage: BuyCatalogPage?
    private(set) var kind: BuildCatalogPage.Kind = .floor
    private(set) var page: BuildCatalogPage?
    private(set) var selected: UInt16?
    private(set) var selectedObjectGUID: UInt32?
    private(set) var terrainMode: TerrainBrushMode?
    var selectedItem: BuildCatalogPage.Item? { page?.items.first { $0.id == selected } }

    init(content: GameContent, device: MTLDevice) throws {
        self.device = device
        func bitmap(_ path: String) throws -> Image {
            let pixels = try SimsBitmap(data: content.read("UIGraphics/cpanel/" + path))
            return try OriginalGameplayOverlay.image(device: device, width: pixels.width, height: pixels.height, pixels: pixels.rgba, magenta: true)
        }
        let pixels = try SimsTarga(data: content.read("UIGraphics/cpanel/Backgrounds/UniversalBack.tga"))
        universal = try OriginalGameplayOverlay.image(device: device, width: pixels.width, height: pixels.height, pixels: pixels.rgba)
        patch = try bitmap("Backgrounds/BuildPatch.bmp")
        buttons = try OriginalBuildLayout.assets.map { try bitmap("Buttons/ToolBtn" + $0 + ".bmp") }
        frame = try bitmap("Catalog/ThumbTemplate.bmp")
        unknown = try bitmap("CatalogUnknown.bmp")
        previous = try bitmap("Buttons/ScrollLeft.bmp")
        next = try bitmap("Buttons/ScrollRight.bmp")
        terrainModeIcons = try ["Build/TerrainDownIcon.BMP", "Build/TerrainLevelIcon.BMP", "Build/TerrainUpIcon.BMP", "HDBuild/TerrainGrassIcon.BMP"].map { try bitmap($0) }
        historyIcons = try ["Buttons/Undo.bmp", "Buttons/Redo.bmp"].map { try bitmap($0) }
    }
    func clear() { page = nil; objectPage = nil; icons = []; selected = nil; selectedObjectGUID = nil }
    func changeKind(_ kind: BuildCatalogPage.Kind) { clear(); objectTool = nil; terrainMode = nil; self.kind = kind }
    func changeTerrainMode(_ mode: TerrainBrushMode) { clear(); objectTool = nil; terrainMode = mode }
    func changeObjectTool(_ tool: OriginalBuildObjectTool) { clear(); terrainMode = nil; objectTool = tool }
    func cancelSelection() { selected = nil; selectedObjectGUID = nil }
    func choose(_ id: UInt16) { if page?.items.contains(where: { $0.id == id && $0.guid == nil }) == true { selected = id; selectedObjectGUID = nil } }
    func chooseObject(_ guid: UInt32, budget: Int?) {
        guard let item = page?.items.first(where: { $0.guid == guid }), item.price <= (budget ?? 0) else { return }
        selected = nil
        selectedObjectGUID = guid
    }
    func update(_ page: BuildCatalogPage, root: URL) throws {
        try page.validate()
        kind = page.kind
        objectTool = nil
        terrainMode = nil
        objectPage = nil
        let root = root.resolvingSymlinksInPath().standardizedFileURL
        let icons = try page.items.map { item -> Image? in
            guard let icon = item.icon else { return nil }
            let file = root.appendingPathComponent(icon.file).resolvingSymlinksInPath().standardizedFileURL
            guard file.deletingLastPathComponent() == root, (try file.resourceValues(forKeys: [.fileSizeKey]).fileSize ?? Int.max) <= 4 * 1024 * 1024 else { throw ContentError.invalid("Build thumbnail escapes scene directory or exceeds size limit") }
            let bitmap = try SimsBitmap(data: Data(contentsOf: file))
            guard bitmap.width <= 512, bitmap.height <= 512, bitmap.width.isMultiple(of: icon.columns), bitmap.height.isMultiple(of: icon.rows), item.guid != nil || (icon.columns == (page.kind == .wallStyle ? 2 : 1) && icon.rows == 1) else { throw ContentError.invalid("Invalid build thumbnail dimensions") }
            return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: true)
        }
        self.page = page
        self.icons = icons
        if !page.items.contains(where: { $0.id == selected && $0.guid == nil }) { selected = nil }
        if !page.items.contains(where: { $0.guid == selectedObjectGUID && $0.guid != nil }) { selectedObjectGUID = nil }
    }
    func updateObjects(_ page: BuyCatalogPage, root: URL) throws {
        try page.validate(buildObjects: true)
        guard let tool = OriginalBuildObjectTool.catalogTool(category: page.category) else { throw ContentError.invalid("Unknown build object category") }
        let root = root.resolvingSymlinksInPath().standardizedFileURL
        let images = try page.items.map { item -> Image? in
            guard let icon = item.icon else { return nil }
            let file = root.appendingPathComponent(icon.file).resolvingSymlinksInPath().standardizedFileURL
            guard file.deletingLastPathComponent() == root, (try file.resourceValues(forKeys: [.fileSizeKey]).fileSize ?? Int.max) <= 4 * 1024 * 1024 else { throw ContentError.invalid("Build object thumbnail escapes scene directory or exceeds size limit") }
            let bitmap = try SimsBitmap(data: Data(contentsOf: file))
            guard bitmap.width <= 512, bitmap.height <= 512, bitmap.width.isMultiple(of: icon.columns), bitmap.height.isMultiple(of: icon.rows) else { throw ContentError.invalid("Invalid build object thumbnail dimensions") }
            return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: true)
        }
        clear()
        objectTool = tool
        objectPage = page
        icons = images
    }
    private func toolControls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        [("Terrain", tool(0, canvas: canvas)), ("Water", tool(1, canvas: canvas)), ("Floor patterns", tool(7, canvas: canvas)), ("Wallpaper patterns", tool(3, canvas: canvas)), ("Walls and fences", tool(2, canvas: canvas))] + OriginalBuildObjectTool.allCases.map { ($0.label, tool($0.buttonIndex, canvas: canvas)) }
    }
    private func arrow(_ forward: Bool, canvas: CGSize) -> CGRect {
        let image = forward ? next : previous
        return OriginalBuildLayout.arrow(forward: forward, size: CGSize(width: image.size.width / 4, height: image.size.height), canvas: canvas)
    }
    private func tool(_ index: Int, canvas: CGSize) -> CGRect {
        CGRect(origin: OriginalBuildLayout.positions[index], size: CGSize(width: buttons[index].size.width / 4, height: buttons[index].size.height)).offsetBy(dx: 0, dy: canvas.height - 100)
    }
    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        var result = toolControls(canvas: canvas)
        result.append(("Undo construction", OriginalBuildLayout.historyControl(0, canvas: canvas, imageSize: historyIcons[0].size)))
        result.append(("Redo construction", OriginalBuildLayout.historyControl(1, canvas: canvas, imageSize: historyIcons[1].size)))
        let capacity = OriginalBuildLayout.capacity(canvas: canvas)
        if terrainMode != nil {
            result += TerrainBrushMode.allCases.enumerated().map { ($0.element.label, OriginalBuildLayout.thumbnail($0.offset, canvas: canvas)) }
        } else if let objectPage {
            result += objectPage.items.prefix(capacity).enumerated().map { ($0.element.name + " — §" + String($0.element.price), OriginalBuildLayout.thumbnail($0.offset, canvas: canvas)) }
            if objectPage.offset > 0 { result.append(("Previous build catalog page", arrow(false, canvas: canvas))) }
            if objectPage.nextOffset(visibleCapacity: capacity) != nil { result.append(("Next build catalog page", arrow(true, canvas: canvas))) }
        } else if let page {
            result += page.items.prefix(capacity).enumerated().map { ($0.element.name + " — §" + String($0.element.price), OriginalBuildLayout.thumbnail($0.offset, canvas: canvas)) }
            if page.offset > 0 { result.append(("Previous build catalog page", arrow(false, canvas: canvas))) }
            if page.nextOffset(visibleCapacity: capacity) != nil { result.append(("Next build catalog page", arrow(true, canvas: canvas))) }
        }
        return result
    }
    func action(at point: CGPoint, canvas: CGSize) -> Action? {
        for objectTool in OriginalBuildObjectTool.allCases where tool(objectTool.buttonIndex, canvas: canvas).contains(point) { return .objectTool(objectTool) }
        if tool(0, canvas: canvas).contains(point) { return .terrain }
        if tool(10, canvas: canvas).contains(point) { return .kind(.roof) }
        if tool(1, canvas: canvas).contains(point) { return .kind(.water) }
        if tool(2, canvas: canvas).contains(point) { return .kind(.wallStyle) }
        if tool(7, canvas: canvas).contains(point) { return .kind(.floor) }
        if tool(3, canvas: canvas).contains(point) { return .kind(.wall) }
        if OriginalBuildLayout.historyControl(0, canvas: canvas, imageSize: historyIcons[0].size).contains(point) { return .history(.undo) }
        if OriginalBuildLayout.historyControl(1, canvas: canvas, imageSize: historyIcons[1].size).contains(point) { return .history(.redo) }
        let capacity = OriginalBuildLayout.capacity(canvas: canvas)
        if terrainMode != nil {
            if let index = TerrainBrushMode.allCases.indices.first(where: { OriginalBuildLayout.thumbnail($0, canvas: canvas).contains(point) }) {
                return .terrainMode(TerrainBrushMode.allCases[index])
            }
        } else if let objectPage {
            if objectPage.offset > 0, arrow(false, canvas: canvas).contains(point) { return .page(max(0, objectPage.offset - capacity)) }
            if let offset = objectPage.nextOffset(visibleCapacity: capacity), arrow(true, canvas: canvas).contains(point) { return .page(offset) }
            if let index = objectPage.items.prefix(capacity).indices.first(where: { OriginalBuildLayout.thumbnail($0, canvas: canvas).contains(point) }) { return .selectObject(objectPage.items[index].guid) }
        } else if let page {
            if page.offset > 0, arrow(false, canvas: canvas).contains(point) { return .page(max(0, page.offset - capacity)) }
            if let offset = page.nextOffset(visibleCapacity: capacity), arrow(true, canvas: canvas).contains(point) { return .page(offset) }
            if let index = page.items.prefix(capacity).indices.first(where: { OriginalBuildLayout.thumbnail($0, canvas: canvas).contains(point) }) {
                let item = page.items[index]
                return item.guid.map(Action.selectObject) ?? .select(item.id)
            }
        }
        return nil
    }
    func parts(canvas: CGSize, budget: Int? = nil, selectedObject: UInt32? = nil, canUndo: Bool? = nil, canRedo: Bool? = nil) -> [Part] {
        let top = canvas.height - 183
        var result = [Part(image: universal, rect: CGRect(x: 0, y: top, width: universal.size.width, height: universal.size.height)), Part(image: patch, rect: CGRect(x: 113, y: top + 51, width: patch.size.width, height: patch.size.height))]
        let selectedTool = terrainMode != nil ? 0 : objectTool?.buttonIndex ?? (kind == .floor ? 7 : kind == .wall ? 3 : kind == .water ? 1 : kind == .roof ? 10 : 2)
        let enabledTools = Set([0, 7, 3, 2, 1, 10] + OriginalBuildObjectTool.allCases.map(\.buttonIndex))
        for (index, image) in buttons.enumerated() {
            result.append(Part(image: image, rect: tool(index, canvas: canvas), uv: SIMD4(index == selectedTool ? 0.5 : enabledTools.contains(index) ? 0 : 0.75, 0, 0.25, 1)))
        }
        for index in historyIcons.indices {
            let enabled = index == 0 ? canUndo == true : canRedo == true
            result.append(Part(image: historyIcons[index], rect: OriginalBuildLayout.historyControl(index, canvas: canvas, imageSize: historyIcons[index].size), uv: SIMD4(Float(OriginalBuildLayout.historyFrameIndex(enabled: enabled)) * 0.25, 0, 0.25, 1)))
        }
        if let objectPage {
            for (index, item) in objectPage.items.prefix(OriginalBuildLayout.capacity(canvas: canvas)).enumerated() {
                let rect = OriginalBuildLayout.thumbnail(index, canvas: canvas)
                let state: Float = item.price > (budget ?? 0) ? 2 : item.guid == selectedObject ? 1 : 0
                result.append(Part(image: frame, rect: rect, uv: SIMD4(state / 4, 0, 0.25, 1)))
                let image = icons[index] ?? unknown
                let columns = icons[index] == nil ? 2 : item.icon?.columns ?? 1
                let rows = icons[index] == nil ? 1 : item.icon?.rows ?? 1
                let size = CGSize(width: image.size.width / CGFloat(columns), height: image.size.height / CGFloat(rows))
                let scale = min(1, min(43 / size.width, 43 / size.height))
                result.append(Part(image: image, rect: CGRect(x: rect.midX - size.width * scale / 2, y: rect.midY - size.height * scale / 2, width: size.width * scale, height: size.height * scale), uv: SIMD4(0, 0, 1 / Float(columns), 1 / Float(rows))))
            }
            for forward in [false, true] {
                let enabled = forward ? objectPage.nextOffset(visibleCapacity: OriginalBuildLayout.capacity(canvas: canvas)) != nil : objectPage.offset > 0
                result.append(Part(image: forward ? next : previous, rect: arrow(forward, canvas: canvas), uv: SIMD4(enabled ? 0 : 0.75, 0, 0.25, 1)))
            }
        }
        if terrainMode != nil {
            for (index, mode) in TerrainBrushMode.allCases.enumerated() {
                let rect = OriginalBuildLayout.thumbnail(index, canvas: canvas)
                result.append(Part(image: frame, rect: rect, uv: SIMD4(mode == terrainMode ? 0.5 : 0, 0, 0.25, 1)))
                let icon = terrainModeIcons[index]
                let frameSize = CGSize(width: icon.size.width / 4, height: icon.size.height)
                let scale = min(1, min(39 / frameSize.width, 39 / frameSize.height))
                result.append(Part(image: icon, rect: CGRect(x: rect.midX - frameSize.width * scale / 2, y: rect.midY - frameSize.height * scale / 2, width: frameSize.width * scale, height: frameSize.height * scale), uv: SIMD4(0, 0, 0.25, 1)))
            }
        }
        if let page {
            for (index, item) in page.items.prefix(OriginalBuildLayout.capacity(canvas: canvas)).enumerated() {
                let rect = OriginalBuildLayout.thumbnail(index, canvas: canvas)
                let chosen = item.guid.map { $0 == selectedObject } ?? (item.id == selected)
                let state: Float = item.guid != nil && item.price > (budget ?? 0) ? 2 : chosen ? 1 : 0
                result.append(Part(image: frame, rect: rect, uv: SIMD4(state / 4, 0, 0.25, 1)))
                let image = icons[index] ?? unknown
                let columns = icons[index] == nil ? 2 : item.icon?.columns ?? 1
                let rows = icons[index] == nil ? 1 : item.icon?.rows ?? 1
                let size = CGSize(width: image.size.width / CGFloat(columns), height: image.size.height / CGFloat(rows))
                let scale = min(1, min(43 / size.width, 43 / size.height))
                result.append(Part(image: image, rect: CGRect(x: rect.midX - size.width * scale / 2, y: rect.midY - size.height * scale / 2, width: size.width * scale, height: size.height * scale), uv: SIMD4(0, 0, 1 / Float(columns), 1 / Float(rows))))
            }
            for forward in [false, true] {
                let enabled = forward ? page.nextOffset(visibleCapacity: OriginalBuildLayout.capacity(canvas: canvas)) != nil : page.offset > 0
                result.append(Part(image: forward ? next : previous, rect: arrow(forward, canvas: canvas), uv: SIMD4(enabled ? 0 : 0.75, 0, 0.25, 1)))
            }
        }
        return result
    }
}
