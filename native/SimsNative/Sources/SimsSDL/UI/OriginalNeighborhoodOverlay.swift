import Foundation
import SimsCore

@MainActor
final class OriginalNeighborhoodOverlay {
    typealias Image = OriginalGameplayOverlay.Image

    struct Manifest: Decodable {
        struct AnimationLayer: Decodable {
            let positionX: Float
            let positionY: Float
            let frameResources: [String]
        }

        struct Entry: Decodable {
            let house: Int
            let x: Float
            let y: Float
            let closedImagePath: String
            let openImagePath: String
            let closedImageWidth: Int
            let closedImageHeight: Int
            let openImageWidth: Int
            let openImageHeight: Int
            let thumbWidth: Int
            let thumbHeight: Int
            let xOff: Int
            let baseYOff: Int
            let addYOff: Int
            let occupied: Bool
            let residential: Bool
            let availableForCreation: Bool
            let price: Int?
            let community: Bool?
            let houseName: String?
            let houseDescription: String?
            let street: Int?
            let familyName: String?
            let familyNetWorth: Int?
            let familyFriends: Int?
            let bulldozed: Bool?
        }

        let schemaVersion: Int
        let mode: Int
        let backgroundResource: String
        let canvasWidth: Int
        let canvasHeight: Int
        let scale: Float
        let pulsate: Bool
        let frameDuration: Int
        let music: String?
        let ambientSound: String?
        let animationLayers: [AnimationLayer]
        let entries: [Entry]
        let families: [OriginalFamilyPickerOverlay.Family]?
        /// The numbered neighborhood (`UserData` is 1) and every neighborhood installed in the profile.
        let neighborhood: Int?
        let neighborhoods: [Int]?
    }

    /// The neighborhood after `current` in the installed list, wrapping at either end like the original
    /// Previous/Next buttons (`0x0042a368` previous, `0x0042a3ca` next).
    static func neighborhood(after current: Int, in installed: [Int], forward: Bool) -> Int? {
        let sorted = Array(Set(installed)).sorted()
        guard sorted.count > 1 else { return nil }
        guard let index = sorted.firstIndex(of: current) else { return sorted.first }
        return sorted[(index + (forward ? 1 : sorted.count - 1)) % sorted.count]
    }

    static func mode(forDialogKind kind: UInt8) -> Int? {
        NeighborhoodTravel.mode(forDialogKind: kind)
    }

    struct DrawItem {
        let image: Image
        let rect: CGRect
        var opacity: Float = 1
        var uv = SIMD4<Float>(0, 0, 1, 1)
    }

    /// Top banner buttons (NghUI/banner_neighborhood.bmp, Res_Nbhd 5200–5307). X positions are the immediates stored by
    /// the executable at 0x55e5c2 into its position table at VA 0x6f5aa8; every banner button has Y 0 and Credits sits at
    /// (195,540). Each sheet holds normal, highlighted, pressed and disabled frames side by side.
    enum BannerAction: Int, CaseIterable {
        case selectFamily, bulldoze, quit, internet, credits, previous, next, importFamily, downtown, vacation, rezone, studioTown, magicTown
        /// Returns from an expansion map to the base neighborhood: button 5210, X 5 in the executable's position table.
        case returnHome

        var resource: String {
            switch self {
            case .selectFamily: "UIGraphics/NghUI/MoveIn.bmp"
            case .bulldoze: "UIGraphics/NghUI/Bulldoze.bmp"
            case .quit: "UIGraphics/NghUI/Exit.bmp"
            case .internet: "UIGraphics/NghUI/InetBtn.bmp"
            case .credits: "UIGraphics/Nbhd/CreditBtn.BMP"
            case .previous: "UIGraphics/NghUI/Previous.bmp"
            case .next: "UIGraphics/NghUI/Next.bmp"
            case .importFamily: "UIGraphics/NghUI/Import.bmp"
            case .downtown: "UIGraphics/NghUI/Downtown.bmp"
            case .vacation: "UIGraphics/NghUI/Vacation.bmp"
            case .rezone: "UIGraphics/NghUI/Rezone.bmp"
            case .studioTown: "UIGraphics/NghUI/Studiotown.bmp"
            case .magicTown: "UIGraphics/NghUI/Magicland.bmp"
            case .returnHome: "UIGraphics/NghUI/Return.bmp"
            }
        }

        var position: CGPoint {
            switch self {
            case .selectFamily: CGPoint(x: 200, y: 0)
            case .bulldoze: CGPoint(x: 300, y: 0)
            case .quit: CGPoint(x: 600, y: 0)
            case .internet: CGPoint(x: 762, y: 0)
            case .credits: CGPoint(x: 195, y: 540)
            case .previous: CGPoint(x: 106, y: 0)
            case .next: CGPoint(x: 141, y: 0)
            case .importFamily: CGPoint(x: 250, y: 0)
            case .downtown: CGPoint(x: 400, y: 0)
            case .vacation: CGPoint(x: 450, y: 0)
            case .rezone: CGPoint(x: 350, y: 0)
            case .studioTown: CGPoint(x: 500, y: 0)
            case .magicTown: CGPoint(x: 550, y: 0)
            case .returnHome: CGPoint(x: 5, y: 0)
            }
        }

        /// STR# 151 (`NghbBtnTips`) tooltip index.
        var tooltipIndex: Int {
            switch self {
            case .selectFamily: 0
            case .bulldoze: 1
            case .quit: 2
            case .internet: 3
            case .previous: 4
            case .next: 5
            case .importFamily: 6
            case .downtown: 7
            case .credits: 8
            case .vacation: 9
            case .rezone: 10
            case .studioTown: 11
            case .magicTown: 12
            case .returnHome: 0
            }
        }

        var fallbackTooltip: String {
            if self == .returnHome { return "Return to Neighborhood View" }
            return ["Select or Create Family", "Evict or Bulldoze", "Quit", "View Web Pages", "Switch To Previous Neighborhood", "Switch To Next Neighborhood",
                    "Import Family", "Switch to Downtown View", "Credits", "Switch to Vacation Island View", "Evict or Rezone",
                    "Switch to Studio Town View", "Switch to Magic Town View"][tooltipIndex]
        }

        /// The expansion map a travel button opens (UserData lot-location modes), if it is one.
        var mapMode: Int? {
            switch self {
            case .downtown: 2
            case .vacation: 3
            case .studioTown: 5
            case .magicTown: 7
            default: nil
            }
        }

        /// The expansion folder whose presence enables a travel button (Hot Date, Vacation, Superstar, Makin' Magic).
        var requiredPackFolder: String? {
            switch self {
            case .downtown: "ExpansionPack3"
            case .vacation: "ExpansionPack4"
            case .studioTown: "ExpansionPack6"
            case .magicTown: "ExpansionPack7"
            case .rezone: "ExpansionPack5"
            default: nil
            }
        }

        /// STR# 225 "please purchase" tooltip index shown when the pack is missing.
        var missingPackTooltipIndex: Int? {
            switch self {
            case .downtown: 0
            case .vacation: 1
            case .studioTown: 3
            case .magicTown: 4
            case .rezone: 2
            default: nil
            }
        }

        var isTravelButton: Bool { mapMode != nil }
    }

    private struct House {
        let entry: Manifest.Entry
        let closed: Image
        let open: Image
        let hitRect: CGRect
    }

    private struct Animation {
        let position: CGPoint
        let frames: [Image]
    }

    let background: Image
    let mode: Int
    let neighborhood: Int
    let neighborhoods: [Int]
    private let device: UIDevice
    let music: String?
    let ambientSound: String?
    private let houses: [House]
    private let entries: [Manifest.Entry]
    /// Unhoused families offered by the Select a Family screen (base neighborhood only).
    let families: [OriginalFamilyPickerOverlay.Family]
    private(set) var hoveredHouse: Int?
    private let canvasWidth: Int
    private let canvasHeight: Int
    private let houseScale: Float
    private let pulsate: Bool
    private let frameDuration: TimeInterval
    private let animations: [Animation]
    private let startedAt = ProcessInfo.processInfo.systemUptime
    private let strings: OriginalUIStrings
    private let font: SimsBitmapFont?
    private let rolloverBackground: Image?
    private let banner: Image?
    private let bannerButtons: [BannerAction: Image]
    private let bannerTooltips: [BannerAction: String]
    private let installedBannerActions: Set<BannerAction>
    private(set) var hoveredBanner: BannerAction?
    private var rolloverCache: (house: Int, lines: [Image])?

    init(content: GameContent, device: UIDevice, manifestURL: URL, session: URL, font: SimsBitmapFont? = nil) throws {
        strings = OriginalUIStrings(content: content)
        self.font = font
        self.device = device
        rolloverBackground = font == nil ? nil : try {
            // The original lot rollover is the soft-edged navy tiler, drawn translucent like HotSpotPopupBkgAlpha.bmp.
            let tiler = try SimsTarga(data: content.read("UIGraphics/Nbhd/HotSpotPopupTiler.tga"))
            return try OriginalGameplayOverlay.image(device: device, width: tiler.width, height: tiler.height, pixels: tiler.rgba)
        }()
        let manifestData = try Data(contentsOf: manifestURL)
        guard manifestData.count <= 4 * 1024 * 1024 else { throw ContentError.invalid("Neighborhood manifest exceeds 4 MiB") }
        let manifest = try JSONDecoder().decode(Manifest.self, from: manifestData)
        func bannerImage(_ path: String) throws -> Image {
            let bitmap = try SimsBitmap(data: content.read(path))
            return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: true)
        }
        // The base map has the full banner; expansion maps show the Downtown-style banner with a Return button.
        let baseMap = manifest.mode == 1
        banner = try bannerImage(baseMap ? "UIGraphics/NghUI/banner_neighborhood.bmp" : "UIGraphics/NghUI/banner_downtown.bmp")
        let uiStrings = OriginalUIStrings(content: content)
        let actions: [BannerAction] = baseMap ? BannerAction.allCases.filter { $0 != .returnHome } : [.returnHome]
        var sheets: [BannerAction: Image] = [:]
        var tips: [BannerAction: String] = [:]
        var installed = Set<BannerAction>()
        for action in actions {
            sheets[action] = try bannerImage(action.resource)
            let present = action.requiredPackFolder.map { FileManager.default.fileExists(atPath: content.root.appendingPathComponent($0).path) } ?? true
            if present { installed.insert(action) }
            if !present, let index = action.missingPackTooltipIndex {
                tips[action] = uiStrings.missingPackTip(index, fallback: "Please purchase the expansion pack to use this")
            } else {
                tips[action] = action == .returnHome ? uiStrings.returnTip(fallback: action.fallbackTooltip)
                    : uiStrings.neighborhoodButtonTip(action.tooltipIndex, fallback: action.fallbackTooltip)
            }
        }
        bannerButtons = sheets
        bannerTooltips = tips
        installedBannerActions = installed
        guard manifest.schemaVersion == 2, manifest.mode > 0, manifest.canvasWidth == 800, manifest.canvasHeight == 600,
              manifest.scale.isFinite, manifest.scale > 0, manifest.scale <= 4, manifest.entries.count <= 256,
              manifest.frameDuration > 0, manifest.frameDuration <= 600, manifest.animationLayers.count <= 16,
              Set(manifest.entries.map(\.house)).count == manifest.entries.count else {
            throw ContentError.invalid("Invalid neighborhood manifest")
        }
        let root = session.resolvingSymlinksInPath().standardizedFileURL
        let backgroundData = try content.read(manifest.backgroundResource)
        let backgroundBitmap = try SimsBitmap(data: backgroundData)
        guard backgroundBitmap.width == manifest.canvasWidth, backgroundBitmap.height == manifest.canvasHeight else {
            throw ContentError.invalid("Neighborhood background dimensions differ from its manifest")
        }
        background = try OriginalGameplayOverlay.image(device: device, width: backgroundBitmap.width, height: backgroundBitmap.height, pixels: backgroundBitmap.rgba)
        mode = manifest.mode
        neighborhood = manifest.neighborhood ?? 1
        neighborhoods = (manifest.neighborhoods ?? [neighborhood]).filter { (1...99).contains($0) }
        entries = manifest.entries
        families = manifest.families ?? []
        canvasWidth = manifest.canvasWidth
        canvasHeight = manifest.canvasHeight
        houseScale = manifest.scale
        pulsate = manifest.pulsate
        frameDuration = Double(manifest.frameDuration) / 60
        music = manifest.music
        ambientSound = manifest.ambientSound
        animations = try manifest.animationLayers.map { layer in
            guard layer.positionX.isFinite, layer.positionY.isFinite, !layer.frameResources.isEmpty, layer.frameResources.count <= 32 else {
                throw ContentError.invalid("Invalid neighborhood animation layer")
            }
            let frames = try layer.frameResources.map { path -> Image in
                let bitmap = try SimsBitmap(data: content.read(path))
                guard bitmap.width <= 4096, bitmap.height <= 4096 else { throw ContentError.invalid("Neighborhood animation frame exceeds 4096 pixels") }
                return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: true)
            }
            return Animation(position: CGPoint(x: CGFloat(layer.positionX), y: CGFloat(layer.positionY)), frames: frames)
        }
        houses = try manifest.entries.map { entry in
            guard (0...100).contains(entry.house), entry.x.isFinite, entry.y.isFinite,
                  entry.closedImageWidth > 0, entry.closedImageHeight > 0, entry.openImageWidth > 0, entry.openImageHeight > 0,
                  entry.closedImageWidth <= 2048, entry.closedImageHeight <= 2048,
                  entry.openImageWidth <= 2048, entry.openImageHeight <= 2048 else {
                throw ContentError.invalid("Invalid neighborhood house entry")
            }
            @MainActor func readImage(_ path: String, width: Int, height: Int) throws -> Image {
                let candidate = path.hasPrefix("/") ? URL(fileURLWithPath: path) : root.appendingPathComponent(path)
                let file = candidate.resolvingSymlinksInPath().standardizedFileURL
                let attributes = try FileManager.default.attributesOfItem(atPath: file.path)
                guard file.path.hasPrefix(root.path + "/"), (attributes[.size] as? NSNumber)?.intValue ?? Int.max <= 4 * 1024 * 1024 else {
                    throw ContentError.invalid("Neighborhood house image escapes its session or exceeds 4 MiB")
                }
                let bitmap = try SimsBitmap(data: Data(contentsOf: file))
                guard bitmap.width == width, bitmap.height == height else {
                    throw ContentError.invalid("Neighborhood house image dimensions differ from its manifest")
                }
                return try OriginalGameplayOverlay.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: true)
            }
            let closed = try readImage(entry.closedImagePath, width: entry.closedImageWidth, height: entry.closedImageHeight)
            let open = try readImage(entry.openImagePath, width: entry.openImageWidth, height: entry.openImageHeight)
            let width = CGFloat(entry.closedImageWidth) / CGFloat(manifest.scale)
            let height = CGFloat(entry.closedImageHeight) / CGFloat(manifest.scale)
            let hitRect = CGRect(x: CGFloat(entry.x) - width / 2, y: CGFloat(entry.y) - height / 2, width: width, height: height)
            return House(entry: entry, closed: closed, open: open, hitRect: hitRect)
        }
    }

    func updateHover(_ point: CGPoint, canvas: CGSize) {
        let factor = canvas.height / CGFloat(canvasHeight)
        let left = (canvas.width - CGFloat(canvasWidth) * factor) / 2
        let logical = CGPoint(x: (point.x - left) / factor, y: point.y / factor)
        hoveredHouse = houses
            .filter { $0.hitRect.contains(logical) }
            .min { left, right in
                let leftX = logical.x - left.hitRect.midX
                let leftY = logical.y - left.hitRect.midY
                let rightX = logical.x - right.hitRect.midX
                let rightY = logical.y - right.hitRect.midY
                return leftX * leftX + leftY * leftY < rightX * rightX + rightY * rightY
            }?.entry.house
    }

    func house(at point: CGPoint, canvas: CGSize) -> Int? {
        updateHover(point, canvas: canvas)
        return hoveredHouse
    }

    func canCreateHousehold(at house: Int) -> Bool {
        mode == 1 && entries.first(where: { $0.house == house })?.availableForCreation == true
    }

    /// The family living on a lot, shaped like a picker row, for eviction prompts.
    func occupant(at house: Int) -> OriginalFamilyPickerOverlay.Family? {
        guard let entry = entries.first(where: { $0.house == house }), entry.occupied, entry.residential else { return nil }
        return OriginalFamilyPickerOverlay.Family(id: 0, name: entry.familyName ?? "", budget: 0, netWorth: entry.familyNetWorth ?? 0,
                                                  friends: entry.familyFriends ?? 0, members: [])
    }

    /// While active, the Bulldoze/Evict banner button is drawn pressed and the next lot click proposes an eviction.
    private(set) var evictMode = false
    func setEvictMode(_ value: Bool) { evictMode = value }

    /// While active, the Rezone banner button is drawn pressed and the next lot click starts a rezoning.
    private(set) var rezoneMode = false
    func setRezoneMode(_ value: Bool) { rezoneMode = value }

    /// Whether a lot's house is already the empty-lot template, which the original game requires before rezoning.
    func isBulldozed(at house: Int) -> Bool { entries.first(where: { $0.house == house })?.bulldozed == true }

    func hasLot(_ house: Int) -> Bool { entries.contains { $0.house == house } }

    /// The lot's current zoning as the original STR# 251 names it: 0 Residential, 1 Community.
    func zoningIndex(at house: Int) -> Int { entries.first(where: { $0.house == house })?.residential == true ? 0 : 1 }

    func price(at house: Int) -> Int? { entries.first(where: { $0.house == house })?.price }

    func isVacantResidential(at house: Int) -> Bool {
        mode == 1 && entries.first(where: { $0.house == house }).map { $0.residential && !$0.occupied } == true
    }

    /// Funds a newly created family starts with (original `money_for_new_family` tuning).
    static let newFamilyFunds = 20_000

    /// The original rollover text for a lot, built from STR# 134 templates as the neighborhood screen shows it
    /// when no family is being moved in.
    func rolloverText(for house: Int) -> String? {
        guard let entry = entries.first(where: { $0.house == house }) else { return nil }
        if entry.occupied {
            return OriginalUIStrings.format(strings.neighborhoodRollover(0, fallback: "The %s Family\r\nNet Worth: %s\r\nFriends: %d"),
                                            [entry.familyName ?? "", OriginalUIStrings.simoleons(entry.familyNetWorth ?? 0), String(entry.familyFriends ?? 0)])
        }
        let address = OriginalUIStrings.format(streetTemplate(entry), [String(entry.house)])
        let name = entry.houseName ?? strings.neighborhoodRollover(22, fallback: "No Name")
        if entry.community == true {
            return OriginalUIStrings.format(strings.neighborhoodRollover(17, fallback: "%s\r\n%s\r\nThis is a community lot."), [address, name])
        }
        guard entry.residential else {
            return OriginalUIStrings.format(strings.neighborhoodRollover(18, fallback: "%s\r\n%s\r\nYou cannot move in here. It is not a residential lot. "), [address, name])
        }
        let cost = OriginalUIStrings.simoleons(entry.price ?? 0)
        return OriginalUIStrings.format(strings.neighborhoodRollover(1, fallback: "%s\r\n%s\r\nCost: %s\r\nPick or create a family and move them in to play."),
                                        [address, name, cost])
    }

    /// Street templates in STR# 134 by StreetNames.iff lot assignment. The assignment-to-template order is inferred
    /// from the order of the street templates in the table and still needs confirmation against the executable.
    private func streetTemplate(_ entry: Manifest.Entry) -> String {
        let indices = [1: 7, 2: 13, 3: 14, 4: 15, 5: 16, 6: 24, 7: 25, 8: 27]
        let modeDefault = [1: 7, 2: 14, 3: 16, 4: 13, 5: 25, 7: 27][mode] ?? 7
        return strings.neighborhoodRollover(entry.street.flatMap { indices[$0] } ?? modeDefault, fallback: "%s Sim Lane")
    }

    private func rolloverLines(for house: Int) -> [Image] {
        if let rolloverCache, rolloverCache.house == house { return rolloverCache.lines }
        guard let font, let text = rolloverText(for: house) else { return [] }
        let lines = text.replacingOccurrences(of: "\r\n", with: "\n").split(separator: "\n", omittingEmptySubsequences: false).flatMap { line in
            (try? font.wrappedLines(String(line), width: 300)) ?? [String(line)]
        }
        let images = lines.compactMap { line -> Image? in
            guard let raster = try? font.rasterize(line, color: SIMD3(255, 255, 255)) else { return nil }
            return try? OriginalGameplayOverlay.image(device: device, width: raster.width, height: raster.height, pixels: raster.rgba)
        }
        rolloverCache = (house, images)
        return images
    }

    /// Whether a banner button works: Quit, Import, Evict/Bulldoze and Return always do; travel buttons need their expansion installed.
    func isEnabled(_ action: BannerAction) -> Bool {
        switch action {
        case .quit, .importFamily, .bulldoze, .returnHome: true
        case .previous, .next: mode == 1 && Set(neighborhoods).count > 1
        case .downtown, .vacation, .studioTown, .magicTown, .rezone: installedBannerActions.contains(action)
        default: false
        }
    }

    private func bannerRect(_ action: BannerAction, canvas: CGSize) -> CGRect {
        let factor = canvas.height / CGFloat(canvasHeight)
        let left = (canvas.width - CGFloat(canvasWidth) * factor) / 2
        guard let sheet = bannerButtons[action] else { return .zero }
        return CGRect(x: left + action.position.x * factor, y: action.position.y * factor,
                      width: sheet.size.width / 4 * factor, height: sheet.size.height * factor)
    }

    func bannerAction(at point: CGPoint, canvas: CGSize) -> BannerAction? {
        BannerAction.allCases.first { bannerButtons[$0] != nil && bannerRect($0, canvas: canvas).contains(point) }
    }

    func updateBannerHover(_ point: CGPoint, canvas: CGSize) {
        hoveredBanner = bannerAction(at: point, canvas: canvas).flatMap { isEnabled($0) ? $0 : nil }
    }

    func bannerTooltip(at point: CGPoint, canvas: CGSize) -> String? {
        bannerAction(at: point, canvas: canvas).flatMap { bannerTooltips[$0] }
    }

    func bannerControls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        BannerAction.allCases.filter { bannerButtons[$0] != nil && isEnabled($0) }.map { (bannerTooltips[$0] ?? $0.fallbackTooltip, bannerRect($0, canvas: canvas)) }
    }

    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        let factor = canvas.height / CGFloat(canvasHeight)
        let left = (canvas.width - CGFloat(canvasWidth) * factor) / 2
        return houses.map { house in
            let rect = CGRect(x: left + house.hitRect.minX * factor, y: house.hitRect.minY * factor,
                              width: house.hitRect.width * factor, height: house.hitRect.height * factor)
            // Scripted checks key on these labels; the original rollover text is available from `rolloverText(for:)`.
            let label = canCreateHousehold(at: house.entry.house) ? "Create a household on vacant lot \(house.entry.house)" : "Open house \(house.entry.house)"
            return (label, rect)
        }
    }

    func drawItems(canvas: CGSize, time: TimeInterval = ProcessInfo.processInfo.systemUptime) -> [DrawItem] {
        let factor = canvas.height / CGFloat(canvasHeight)
        let left = (canvas.width - CGFloat(canvasWidth) * factor) / 2
        let backgroundRect = CGRect(x: left, y: 0, width: CGFloat(canvasWidth) * factor, height: CGFloat(canvasHeight) * factor)
        var items = [DrawItem(image: background, rect: backgroundRect)]
        if let banner {
            items.append(DrawItem(image: banner, rect: CGRect(x: backgroundRect.minX, y: 0, width: banner.size.width * factor, height: banner.size.height * factor)))
        }
        for house in houses {
            let entry = house.entry
            let scale = factor / CGFloat(houseScale)
            let x = left + CGFloat(entry.x) * factor + (CGFloat(entry.xOff) / 2 - CGFloat(entry.closedImageWidth) / 2) * scale
            let y = CGFloat(entry.y) * factor + (CGFloat(entry.baseYOff) / 2 - CGFloat(entry.closedImageHeight) / 2) * scale
            items.append(DrawItem(image: house.closed, rect: CGRect(x: x, y: y, width: CGFloat(entry.closedImageWidth) * scale, height: CGFloat(entry.closedImageHeight) * scale)))
            if hoveredHouse == entry.house {
                let openY = y - CGFloat(entry.addYOff) * scale
                items.append(DrawItem(image: house.open, rect: CGRect(x: x, y: openY, width: CGFloat(entry.openImageWidth) * scale, height: CGFloat(entry.openImageHeight) * scale)))
            }
        }
        for animation in animations {
            let count = animation.frames.count
            let totalFrames = pulsate ? count * 2 - 2 : count
            let cycleFrames = max(1, totalFrames)
            let phase = max(0, time - startedAt) / frameDuration
            let frame = Int(phase) % cycleFrames
            let progress = Float(phase - floor(phase))
            func frameIndex(_ index: Int) -> Int {
                if index < count { return index }
                return max(0, totalFrames - index)
            }
            let current = frameIndex(frame)
            let next = frameIndex((frame + 1) % cycleFrames)
            let currentImage = animation.frames[current]
            items.append(DrawItem(image: currentImage,
                                  rect: CGRect(x: left + animation.position.x * factor, y: animation.position.y * factor,
                                               width: currentImage.size.width * factor, height: currentImage.size.height * factor)))
            if progress > 0 {
                let nextImage = animation.frames[next]
                items.append(DrawItem(image: nextImage,
                                      rect: CGRect(x: left + animation.position.x * factor, y: animation.position.y * factor,
                                                   width: nextImage.size.width * factor, height: nextImage.size.height * factor), opacity: progress))
            }
        }
        for action in BannerAction.allCases {
            guard let sheet = bannerButtons[action] else { continue }
            let frame: Float = !isEnabled(action) ? 3 : (action == .bulldoze && evictMode) || (action == .rezone && rezoneMode) ? 2 : hoveredBanner == action ? 1 : 0
            items.append(DrawItem(image: sheet, rect: bannerRect(action, canvas: canvas), uv: SIMD4(frame / 4, 0, 0.25, 1)))
        }
        items.append(contentsOf: rolloverItems(canvas: canvas, left: left, factor: factor))
        return items
    }

    /// Draws a tiler image with its `sourceEdge`-pixel corners and edges kept at `edge` points and its centre stretched.
    static func nineSlice(_ image: Image, rect: CGRect, edge requested: CGFloat, sourceEdge: CGFloat, opacity: Float = 1) -> [DrawItem] {
        let edge = min(requested, rect.width / 2, rect.height / 2)
        let u = Float(min(1.0 / 3, sourceEdge / max(1, image.size.width)))
        let v = Float(min(1.0 / 3, sourceEdge / max(1, image.size.height)))
        let xs = [rect.minX, rect.minX + edge, rect.maxX - edge, rect.maxX]
        let ys = [rect.minY, rect.minY + edge, rect.maxY - edge, rect.maxY]
        let us: [Float] = [0, u, 1 - u, 1]
        let vs: [Float] = [0, v, 1 - v, 1]
        var items: [DrawItem] = []
        for row in 0..<3 {
            for column in 0..<3 where xs[column + 1] > xs[column] && ys[row + 1] > ys[row] {
                items.append(DrawItem(image: image, rect: CGRect(x: xs[column], y: ys[row], width: xs[column + 1] - xs[column], height: ys[row + 1] - ys[row]),
                                      opacity: opacity, uv: SIMD4(us[column], vs[row], us[column + 1] - us[column], vs[row + 1] - vs[row])))
            }
        }
        return items
    }

    private func rolloverItems(canvas: CGSize, left: CGFloat, factor: CGFloat) -> [DrawItem] {
        guard let hoveredHouse, let background = rolloverBackground, let house = houses.first(where: { $0.entry.house == hoveredHouse }) else { return [] }
        let lines = rolloverLines(for: hoveredHouse)
        guard !lines.isEmpty, let font else { return [] }
        let lineHeight = CGFloat(font.lineHeight) * factor
        let width = (lines.map(\.size.width).max() ?? 0) * factor + 16 * factor
        let height = CGFloat(lines.count) * lineHeight + 12 * factor
        let anchor = CGPoint(x: left + house.hitRect.midX * factor, y: house.hitRect.maxY * factor + 6 * factor)
        let mapRight = left + CGFloat(canvasWidth) * factor
        let x = min(max(left + 4 * factor, anchor.x - width / 2), mapRight - width - 4 * factor)
        let y = anchor.y + height > canvas.height - 4 * factor ? house.hitRect.minY * factor - height - 6 * factor : anchor.y
        var items = Self.nineSlice(background, rect: CGRect(x: x, y: y, width: width, height: height), edge: 14 * factor, sourceEdge: 20, opacity: 176 / 255)
        for (index, line) in lines.enumerated() {
            items.append(DrawItem(image: line, rect: CGRect(x: x + 8 * factor, y: y + 6 * factor + CGFloat(index) * lineHeight,
                                                            width: line.size.width * factor, height: line.size.height * factor)))
        }
        return items
    }
}
