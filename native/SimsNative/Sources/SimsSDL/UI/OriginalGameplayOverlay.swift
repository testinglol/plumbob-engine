import Foundation
import SimsCore

@MainActor
final class OriginalGameplayOverlay {
    enum Subpanel: String {
        case needs, relationships, personality, career, interests
        var buttonIndex: Int {
            switch self { case .needs: 0; case .relationships: 1; case .personality: 4; case .career: 2; case .interests: 5 }
        }
        var label: String {
            switch self { case .needs: "Needs"; case .relationships: "Relationships"; case .personality: "Personality"; case .career: "Career"; case .interests: "Interests" }
        }
    }
    struct Image {
        let texture: UITexture
        let size: CGSize
    }
    struct Part {
        let image: Image
        let rect: CGRect
        var uv = SIMD4<Float>(0, 0, 1, 1)
    }
    let device: UIDevice
    let font: SimsBitmapFont
    private let strings: OriginalUIStrings
    private let patch: Image
    private let universal: Image
    private let gadget: Image
    private let people: Image
    private let unknown: Image
    private let iconFrame: Image
    private let cancel: Image
    private let greenBars: Image
    private let redBars: Image
    private let buttons: [Image]
    private let labels: [Image]
    private let traitLabels: [Image]
    private let personalityBackground: Image
    private let personalityBars: Image
    private let careerFont: SimsBitmapFont
    private let skillLabels: [Image]
    private let skillBars: Image
    private let skillBarsOff: Image
    private let skillHighlight: Image
    private let interestIcons: [Image]
    private let interestBars: Image
    private let interestBackground: Image
    private let interestArrows: [Image]
    private let relationshipUnknown: Image
    private let relationshipIcons: [Image]
    private let relationshipFilters: [Image]
    private(set) var relationshipPage = 0
    private(set) var relationshipFilter = OriginalGameplayLayout.RelationshipFilter.all
    private(set) var interestPage = 0
    private var grid = OriginalGameplayLayout.PanelGrid(width: 800)
    private var resources: [String: Image] = [:]
    private var body: [Part] = []
    private var queued: [(GameplayPanelState.Action, Image?)] = []
    private(set) var state: GameplayPanelState?
    private(set) var subpanel = Subpanel.needs
    private var resourceRoot: URL?
    var hoveredAction: Int?
    private let buttonPositions = [CGPoint(x: 422, y: 81), CGPoint(x: 489, y: 54), CGPoint(x: 489, y: 85), CGPoint(x: 489, y: 116), CGPoint(x: 457, y: 85), CGPoint(x: 457, y: 54)]

    init(content: GameContent, font: SimsBitmapFont, device: UIDevice, strings: OriginalUIStrings) throws {
        self.device = device
        self.font = font
        self.strings = strings
        func bitmap(_ asset: String) throws -> Image {
            let image = try SimsBitmap(data: content.read("UIGraphics/cpanel/" + asset))
            return try Self.image(device: device, width: image.width, height: image.height, pixels: image.rgba, magenta: true)
        }
        patch = try bitmap("Backgrounds/LivePatch.bmp")
        let base = try SimsTarga(data: content.read("UIGraphics/cpanel/Backgrounds/UniversalBack.tga"))
        universal = try Self.image(device: device, width: base.width, height: base.height, pixels: base.rgba)
        gadget = try bitmap("Backgrounds/LiveGadget.bmp")
        people = try bitmap("People/PeopleTemplate.bmp")
        unknown = try bitmap("Buttons/UnknownFace.bmp")
        iconFrame = try bitmap("Buttons/IconFrame.bmp")
        let cancelBitmap = try SimsBitmap(data: content.read("UIGraphics/Other/QueueCancel.bmp"))
        cancel = try Self.image(device: device, width: cancelBitmap.width, height: cancelBitmap.height, pixels: cancelBitmap.rgba, magenta: true)
        greenBars = try bitmap("Greenbars.bmp")
        redBars = try bitmap("Redbars.bmp")
        buttons = try ["Mood", "Relationship", "Job", "House", "Personality", "Interest"].map { try bitmap("Buttons/" + $0 + ".bmp") }
        labels = try OriginalGameplayLayout.motives.map { try Self.text($0, font: font, device: device) }
        traitLabels = try OriginalGameplayLayout.traits.map { try Self.text($0, font: font, device: device) }
        personalityBackground = try bitmap("Backgrounds/PersBkg.bmp")
        personalityBars = try bitmap("HouseSubBars.bmp")
        let careerFont = try SimsBitmapFont(data: content.read("UIGraphics/Fonts/variablesans_07.ffn"))
        self.careerFont = careerFont
        skillLabels = try OriginalGameplayLayout.skills.map { try Self.text(strings.careerSkill($0), font: careerFont, device: device) }
        skillBars = try bitmap("JobSubBars.bmp")
        skillBarsOff = try bitmap("Backgrounds/JobSubBarsOff.bmp")
        skillHighlight = try bitmap("SkillsHilite.bmp")
        interestIcons = try OriginalGameplayLayout.interests.map { try bitmap("Buttons/Interest" + $0 + ".bmp") }
        interestBars = try bitmap("InterestBars.bmp")
        interestBackground = try bitmap("Backgrounds/InterestBarsBackground.bmp")
        interestArrows = try ["ScrollLeft", "ScrollRight"].map { try bitmap("Buttons/" + $0 + ".bmp") }
        relationshipUnknown = try bitmap("People/UnknownRel.bmp")
        relationshipIcons = try ["Smiley", "Heart", "HeartDeep"].map { try bitmap("Buttons/" + $0 + ".bmp") }
        relationshipFilters = try ["RelFamilySort", "RelFriendSort", "RelStarSort", "RelAllSort"].map { try bitmap("Buttons/" + $0 + ".bmp") }
    }

    static func image(device: UIDevice, width: Int, height: Int, pixels: Data, magenta: Bool = false) throws -> Image {
        let descriptor = UITextureDescriptor.texture2DDescriptor(pixelFormat: .rgba8Unorm_srgb, width: width, height: height, mipmapped: false)
        descriptor.storageMode = .shared
        descriptor.usage = .shaderRead
        guard let texture = device.makeTexture(descriptor: descriptor) else { throw ContentError.invalid("Cannot allocate gameplay panel texture") }
        let rgba = try SpritePixels.premultipliedSRGB(pixels, removeMagenta: magenta)
        rgba.withUnsafeBytes { texture.replace(region: MTLRegionMake2D(0, 0, width, height), mipmapLevel: 0, withBytes: $0.baseAddress!, bytesPerRow: width * 4) }
        return Image(texture: texture, size: CGSize(width: width, height: height))
    }
    static func text(_ value: String, font: SimsBitmapFont, device: UIDevice) throws -> Image {
        // The rasterizer pads labels by 3 pixels on every side; the panel positions text by its glyph cell, as the original does.
        let image = try font.rasterize(value, color: SIMD3(255, 255, 255)), pad = 3
        let width = max(1, image.width - 2 * pad), height = image.height - 2 * pad
        var pixels = Data(capacity: width * height * 4)
        for y in pad..<(pad + height) { pixels.append(image.rgba[((y * image.width + pad) * 4)..<((y * image.width + pad + width) * 4)]) }
        return try Self.image(device: device, width: width, height: height, pixels: pixels)
    }

    func update(_ next: GameplayPanelState, root: URL) throws {
        try next.validate()
        if !supports(subpanel, state: next) { subpanel = .needs }
        let root = root.resolvingSymlinksInPath().standardizedFileURL
        var used: Set<String> = []
        func resource(_ reference: GameplayPanelState.Image?) throws -> Image? {
            guard let reference else { return nil }
            try reference.validate()
            used.insert(reference.file)
            if let cached = resources[reference.file] { return cached }
            let path = root.appendingPathComponent(reference.file).resolvingSymlinksInPath().standardizedFileURL
            guard path.deletingLastPathComponent() == root,
                  (try path.resourceValues(forKeys: [.fileSizeKey]).fileSize ?? Int.max) <= 4 * 1024 * 1024 else { throw ContentError.invalid("Gameplay image escapes resource directory or exceeds size limit") }
            let bitmap = try SimsBitmap(data: Data(contentsOf: path))
            guard bitmap.width <= 512, bitmap.height <= 512,
                  bitmap.width.isMultiple(of: reference.columns), bitmap.height.isMultiple(of: reference.rows) else { throw ContentError.invalid("Invalid gameplay image dimensions") }
            let image = try Self.image(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: true)
            resources[reference.file] = image
            return image
        }
        var parts = [Part(image: universal, rect: CGRect(x: 0, y: -33, width: 220, height: 183)),
                     Part(image: patch, rect: CGRect(x: 7, y: -3, width: patch.size.width, height: patch.size.height)),
                     Part(image: gadget, rect: CGRect(x: 413, y: 50, width: 108, height: 100))]
        for index in buttons.indices {
            let image = buttons[index]
            let enabled = [Subpanel.needs, .relationships, .personality, .career, .interests].contains { $0.buttonIndex == index && supports($0, state: next) }
            let column: Float = !enabled ? 0.75 : index == subpanel.buttonIndex ? 0.5 : 0
            parts.append(Part(image: image, rect: buttonRect(index), uv: SIMD4(column, 0, 0.25, 1)))
        }
        for (index, sim) in next.household.enumerated() {
            let rect = OriginalGameplayLayout.portrait(index)
            parts.append(Part(image: people, rect: rect, uv: SIMD4(sim.id == next.selectedSim ? 0.5 : 0, 0, 0.25, 1)))
            if let image = try resource(sim.portrait), let reference = sim.portrait {
                let size = CGSize(width: image.size.width / CGFloat(reference.columns), height: image.size.height / CGFloat(reference.rows))
                let expression = reference.columns >= 3 ? (sim.mood > 30 ? 1 : sim.mood < -30 ? 2 : 0) : 0
                parts.append(Part(image: image, rect: CGRect(x: rect.midX - size.width / 2, y: rect.midY - size.height / 2, width: size.width, height: size.height), uv: SIMD4(Float(expression) / Float(reference.columns), 0, 1 / Float(reference.columns), 1 / Float(reference.rows))))
            } else { parts.append(Part(image: unknown, rect: rect, uv: SIMD4(0, 0, 0.25, 1 / 3))) }
        }
        if let selected = next.selected {
            let mood = min(5, max(-5, Int(Float(selected.mood + 100) * Float(0.05472636967897415) - 5)))
            if mood > 0 {
                let height = CGFloat(mood * 5)
                parts.append(Part(image: greenBars, rect: CGRect(x: 425, y: 53 + 25 - height, width: 27, height: height), uv: SIMD4(0, Float(25 - height) / 25, 1, Float(height) / 25)))
            } else if mood < 0 {
                let height = CGFloat(-mood * 5)
                parts.append(Part(image: redBars, rect: CGRect(x: 425, y: 123, width: 27, height: height), uv: SIMD4(0, 0, 1, Float(height) / 25)))
            } else {
                parts.append(Part(image: greenBars, rect: CGRect(x: 425, y: 76, width: 27, height: 2), uv: SIMD4(0, 23 / 25, 1, 2 / 25)))
                parts.append(Part(image: redBars, rect: CGRect(x: 425, y: 123, width: 27, height: 2), uv: SIMD4(0, 0, 1, 2 / 25)))
            }
            if subpanel == .needs { for index in labels.indices {
                let label = labels[index]
                let rect = OriginalGameplayLayout.need(index)
                parts.append(Part(image: label, rect: CGRect(x: rect.midX - label.size.width / 2, y: rect.minY + CGFloat(10 - font.lineHeight) / 2, width: label.size.width, height: label.size.height)))
                let value = selected.motives[OriginalGameplayLayout.motives[index]] ?? 0
                let colors = OriginalGameplayLayout.barColors(value)
                let width = OriginalGameplayLayout.barWidth(value)
                var pixels = Data(repeating: 255, count: 60 * 5 * 4)
                for y in 0..<5 { for x in 0..<60 {
                    let color = x < width ? colors.green : colors.red
                    for channel in 0..<3 { pixels[(y * 60 + x) * 4 + channel] = (60 - width > 1 && x == width - 1) ? 0 : color[channel] }
                } }
                let bar = try Self.image(device: device, width: 60, height: 5, pixels: pixels)
                parts.append(Part(image: bar, rect: CGRect(x: rect.minX + 20, y: rect.minY + 12, width: 60, height: 5)))
            } } else if subpanel == .relationships, let values = selected.relationships {
                let relationships = OriginalGameplayLayout.relationships(values, filter: relationshipFilter)
                relationshipPage = min(relationshipPage, grid.pageCount(items: relationships.count, capacity: grid.relationshipCapacity) - 1)
                for (index, filter) in OriginalGameplayLayout.RelationshipFilter.allCases.enumerated() {
                    parts.append(Part(image: relationshipFilters[index], rect: OriginalGameplayLayout.relationshipFilter(index), uv: SIMD4(filter == relationshipFilter ? 0.5 : 0, 0, 0.25, 1)))
                }
                for (index, relationship) in relationships.dropFirst(relationshipPage * grid.relationshipCapacity).prefix(grid.relationshipCapacity).enumerated() {
                    let rect = OriginalGameplayLayout.relationship(index)
                    let image = try resource(relationship.portrait) ?? relationshipUnknown
                    let columns = relationship.portrait?.columns ?? 5
                    let size = CGSize(width: image.size.width / CGFloat(columns), height: image.size.height)
                    let expression = min(columns - 1, OriginalGameplayLayout.relationshipExpression(relationship.lifetime))
                    parts.append(Part(image: image, rect: CGRect(x: rect.midX - size.width / 2, y: rect.minY, width: size.width, height: size.height), uv: SIMD4(Float(expression) / Float(columns), 0, 1 / Float(columns), 1)))
                    let daily = try Self.text(String(min(100, max(-100, relationship.daily))), font: careerFont, device: device)
                    parts.append(Part(image: daily, rect: CGRect(x: rect.minX, y: rect.minY + size.height - 2, width: daily.size.width, height: daily.size.height)))
                    let barY = rect.minY + size.height - 2 + CGFloat(careerFont.lineHeight)
                    let colors = OriginalGameplayLayout.barColors(relationship.lifetime)
                    for (value, y, height) in [(relationship.lifetime, barY, 2), (relationship.daily, barY + 4, 4)] {
                        let width = OriginalGameplayLayout.relationshipWidth(value)
                        var pixels = Data(repeating: 255, count: 40 * height * 4)
                        for row in 0..<height { for column in 0..<40 {
                            let color = column < width ? colors.green : colors.red
                            for channel in 0..<3 { pixels[(row * 40 + column) * 4 + channel] = (40 - width > 1 && column == width - 1) ? 0 : color[channel] }
                        } }
                        let bar = try Self.image(device: device, width: 40, height: height, pixels: pixels)
                        parts.append(Part(image: bar, rect: CGRect(x: rect.minX + 2, y: y, width: 40, height: CGFloat(height))))
                    }
                    let lifetime = try Self.text(String(min(100, max(-100, relationship.lifetime))), font: careerFont, device: device)
                    let valueY = barY + 10
                    parts.append(Part(image: lifetime, rect: CGRect(x: rect.minX + 2, y: valueY, width: lifetime.size.width, height: lifetime.size.height)))
                    let iconY = valueY - 2 + CGFloat(careerFont.lineHeight)
                    if relationship.friend { parts.append(Part(image: relationshipIcons[0], rect: CGRect(x: rect.minX + 2, y: iconY, width: 9, height: 9))) }
                    if relationship.love || relationship.crush { parts.append(Part(image: relationshipIcons[relationship.love ? 2 : 1], rect: CGRect(x: rect.minX + 14, y: iconY, width: 9, height: 9))) }
                }
                for direction in 0...1 {
                    let available = direction == 0 ? relationshipPage > 0 : (relationshipPage + 1) * grid.relationshipCapacity < relationships.count
                    if available { parts.append(Part(image: interestArrows[direction], rect: grid.relationshipArrow(direction == 1), uv: SIMD4(0, 0, 0.25, 1))) }
                }
            } else if subpanel == .personality, let traits = selected.personality {
                let labelWidth = OriginalGameplayLayout.traits.map(font.textWidth).max() ?? 0
                for index in traitLabels.indices {
                    let label = traitLabels[index]
                    let rect = OriginalGameplayLayout.personality(index, labelWidth: labelWidth)
                    let barX = rect.minX + CGFloat(labelWidth + 6)
                    let barY = rect.minY + CGFloat(max(0, (font.lineHeight - 14) / 2))
                    parts.append(Part(image: label, rect: CGRect(x: rect.minX + CGFloat(labelWidth + 3) - label.size.width, y: rect.minY + CGFloat(max(0, (14 - font.lineHeight) / 2)), width: label.size.width, height: label.size.height)))
                    parts.append(Part(image: personalityBackground, rect: CGRect(x: barX, y: barY, width: 40, height: 14)))
                    let width = CGFloat(OriginalGameplayLayout.personalityWidth(traits[OriginalGameplayLayout.traits[index]] ?? 0))
                    if width > 0 {
                        parts.append(Part(image: personalityBars, rect: CGRect(x: barX, y: barY - 1, width: width, height: 16), uv: SIMD4(0, 0, Float(width / 40), 1)))
                    }
                }
                if let stored = selected.zodiac {
                    let zodiac = OriginalGameplayLayout.zodiac(personality: traits, stored: stored)
                    let sign = try Self.text(OriginalGameplayLayout.signs[zodiac - 1], font: font, device: device)
                    parts.append(Part(image: sign, rect: CGRect(x: 525, y: 145 - sign.size.height, width: sign.size.width, height: sign.size.height)))
                }
            } else if subpanel == .interests, let values = selected.interests, let career = selected.career {
                let indices = OriginalGameplayLayout.interestIndices(age: career.age)
                interestPage = min(interestPage, grid.pageCount(items: indices.count, capacity: grid.interestCapacity) - 1)
                let title = try Self.text(strings.interestsTitle(), font: careerFont, device: device)
                parts.append(Part(image: title, rect: CGRect(x: 525, y: 50, width: title.size.width, height: title.size.height)))
                for (slot, index) in indices.dropFirst(interestPage * grid.interestCapacity).prefix(grid.interestCapacity).enumerated() {
                    let rect = grid.interest(slot)
                    let icon = interestIcons[index]
                    parts.append(Part(image: icon, rect: CGRect(origin: rect.origin, size: icon.size)))
                    let bar = CGRect(x: rect.minX + icon.size.width + 5, y: rect.minY + 5, width: 40, height: 16)
                    parts.append(Part(image: interestBackground, rect: bar))
                    let width = CGFloat(OriginalGameplayLayout.personalityWidth(values[index]))
                    if width > 0 { parts.append(Part(image: interestBars, rect: CGRect(x: bar.minX, y: bar.minY, width: width, height: bar.height), uv: SIMD4(0, 0, Float(width / 40), 1))) }
                }
                for direction in 0...1 {
                    let available = direction == 0 ? interestPage > 0 : (interestPage + 1) * grid.interestCapacity < indices.count
                    if available { parts.append(Part(image: interestArrows[direction], rect: grid.interestArrow(direction == 1), uv: SIMD4(0, 0, 0.25, 1))) }
                }
            } else if subpanel == .career, let skills = selected.skills, let career = selected.career {
                for index in skillLabels.indices {
                    let label = skillLabels[index]
                    let bounds = OriginalGameplayLayout.skillLabel(index)
                    parts.append(Part(image: label, rect: CGRect(origin: bounds.origin, size: label.size)))
                    let bar = OriginalGameplayLayout.skillBar(index)
                    parts.append(Part(image: skillBarsOff, rect: bar))
                    let value = skills[OriginalGameplayLayout.skills[index]] ?? 0
                    let width = CGFloat(OriginalGameplayLayout.personalityWidth(value))
                    if width > 0 {
                        parts.append(Part(image: skillBars, rect: CGRect(x: bar.minX, y: bar.minY, width: width, height: bar.height), uv: SIMD4(0, 0, Float(width / 40), 1)))
                    }
                    if let required = OriginalGameplayLayout.requiredSkillWidth(index, value: value, career: career) {
                        parts.append(Part(image: skillHighlight, rect: CGRect(x: bar.minX + CGFloat(required) - 1, y: bar.minY, width: skillHighlight.size.width, height: bar.height)))
                    }
                }
                let title: String
                if !career.hasJob { title = strings.careerUnemployed() }
                else if let name = career.title, !name.isEmpty { title = name }
                else { title = career.isSchool ? strings.careerSchool() : "" }
                let lines = try careerFont.wrappedLines(title, width: 89)
                for (index, line) in lines.prefix(max(1, 31 / careerFont.lineHeight)).enumerated() {
                    let image = try Self.text(line, font: careerFont, device: device)
                    parts.append(Part(image: image, rect: CGRect(x: 523, y: CGFloat(54 + index * careerFont.lineHeight), width: image.size.width, height: image.size.height)))
                }
                let salary = career.hasJob ? "§" + String(career.salary ?? 0) : strings.careerUnavailable()
                let rating = career.hasJob ? career.performanceLabel ?? strings.careerUnavailable() : strings.careerUnavailable()
                for (text, y) in [(strings.careerJobLabel(), 85), (salary, 95), (rating, 115)] {
                    let image = try Self.text(text, font: careerFont, device: device)
                    let width = min(95, image.size.width)
                    parts.append(Part(image: image, rect: CGRect(x: 523, y: CGFloat(y), width: width, height: image.size.height), uv: SIMD4(0, 0, Float(width / image.size.width), 1)))
                }
                if let required = career.friendsNeeded {
                    let image = try Self.text("Need " + String(required), font: careerFont, device: device)
                    parts.append(Part(image: image, rect: CGRect(x: 523, y: 135, width: image.size.width, height: image.size.height)))
                }
            }
        }
        let hour = next.hours % 12 == 0 ? 12 : next.hours % 12
        let clock = try Self.text(String(format: "%d:%02d %@", hour, next.minutes, next.hours < 12 ? "AM" : "PM"), font: font, device: device)
        parts.append(Part(image: clock, rect: CGRect(x: 123 - clock.size.width / 2, y: 85, width: clock.size.width, height: clock.size.height)))
        if let budget = next.budget {
            let money = try Self.text("§" + String(budget), font: font, device: device)
            parts.append(Part(image: money, rect: CGRect(x: 178 - money.size.width, y: 125, width: money.size.width, height: money.size.height)))
        }
        let actions = try (next.selected?.actions.filter(\.visible) ?? []).map { ($0, try resource($0.icon)) }
        body = parts
        queued = actions
        state = next
        resourceRoot = root
        resources = resources.filter { used.contains($0.key) }
    }

    private func buttonRect(_ index: Int) -> CGRect {
        CGRect(origin: buttonPositions[index], size: CGSize(width: buttons[index].size.width / 4, height: buttons[index].size.height))
    }
    func choose(_ panel: Subpanel) throws {
        guard let state, let resourceRoot, supports(panel, state: state) else { return }
        let previous = subpanel
        subpanel = panel
        do { try update(state, root: resourceRoot) }
        catch { subpanel = previous; throw error }
    }
    func subpanel(at point: CGPoint, canvas: CGSize) -> Subpanel? {
        [Subpanel.needs, .relationships, .personality, .career, .interests].first {
            supports($0, state: state) && buttonRect($0.buttonIndex).offsetBy(dx: 0, dy: canvas.height - 150).contains(point)
        }
    }

    private func supports(_ panel: Subpanel, state: GameplayPanelState?) -> Bool {
        switch panel {
        case .needs: true
        case .relationships: state?.selected?.relationships != nil
        case .personality: state?.selected?.hasHumanPersonality == true
        case .career: state?.selected?.hasHumanCareer == true
        case .interests: state?.selected?.hasHumanInterests == true
        }
    }

    func chooseInterestPage(_ page: Int) throws {
        guard subpanel == .interests, let state, let root = resourceRoot, let age = state.selected?.career?.age,
              page >= 0, page < grid.pageCount(items: OriginalGameplayLayout.interestIndices(age: age).count, capacity: grid.interestCapacity) else { throw ContentError.invalid("Invalid interest page") }
        interestPage = page
        try update(state, root: root)
    }

    func chooseRelationshipFilter(_ filter: OriginalGameplayLayout.RelationshipFilter) throws {
        guard subpanel == .relationships, let state, let root = resourceRoot else { throw ContentError.invalid("Relationships panel is unavailable") }
        relationshipFilter = filter
        relationshipPage = 0
        try update(state, root: root)
    }

    func chooseRelationshipPage(_ page: Int) throws {
        guard subpanel == .relationships, let state, let root = resourceRoot, let values = state.selected?.relationships,
              page >= 0, page < grid.pageCount(items: OriginalGameplayLayout.relationships(values, filter: relationshipFilter).count, capacity: grid.relationshipCapacity) else { throw ContentError.invalid("Invalid relationship page") }
        relationshipPage = page
        try update(state, root: root)
    }

    func relationshipControl(at point: CGPoint, canvas: CGSize) throws -> Bool {
        try prepare(canvas: canvas)
        guard subpanel == .relationships, let values = state?.selected?.relationships else { return false }
        for (index, filter) in OriginalGameplayLayout.RelationshipFilter.allCases.enumerated() where OriginalGameplayLayout.relationshipFilter(index).offsetBy(dx: 0, dy: canvas.height - 150).contains(point) {
            try chooseRelationshipFilter(filter)
            return true
        }
        for next in [false, true] where grid.relationshipArrow(next).offsetBy(dx: 0, dy: canvas.height - 150).contains(point) {
            let page = relationshipPage + (next ? 1 : -1)
            if page >= 0 && page * grid.relationshipCapacity < OriginalGameplayLayout.relationships(values, filter: relationshipFilter).count { try chooseRelationshipPage(page) }
            return true
        }
        return false
    }

    func pageInterests(at point: CGPoint, canvas: CGSize) throws -> Bool {
        try prepare(canvas: canvas)
        guard subpanel == .interests, let age = state?.selected?.career?.age else { return false }
        for next in [false, true] where grid.interestArrow(next).offsetBy(dx: 0, dy: canvas.height - 150).contains(point) {
            let page = interestPage + (next ? 1 : -1)
            guard page >= 0, page * grid.interestCapacity < OriginalGameplayLayout.interestIndices(age: age).count else { return true }
            try chooseInterestPage(page)
            return true
        }
        return false
    }

    func prepare(canvas: CGSize) throws {
        let next = OriginalGameplayLayout.PanelGrid(width: canvas.width)
        guard next != grid else { return }
        let previous = grid
        let previousRelationshipPage = relationshipPage
        let previousInterestPage = interestPage
        grid = next
        guard let state, let root = resourceRoot else { return }
        let relationships = OriginalGameplayLayout.relationships(state.selected?.relationships ?? [], filter: relationshipFilter)
        relationshipPage = next.resizedPage(relationshipPage, oldCapacity: previous.relationshipCapacity, newCapacity: next.relationshipCapacity, items: relationships.count)
        let interests = state.selected?.career.map { OriginalGameplayLayout.interestIndices(age: $0.age).count } ?? 0
        interestPage = next.resizedPage(interestPage, oldCapacity: previous.interestCapacity, newCapacity: next.interestCapacity, items: interests)
        do { try update(state, root: root) }
        catch {
            grid = previous
            relationshipPage = previousRelationshipPage
            interestPage = previousInterestPage
            throw error
        }
    }

    func parts(canvas: CGSize) -> [Part] {
        let top = canvas.height - 150
        var parts = body.map { Part(image: $0.image, rect: $0.rect.offsetBy(dx: 0, dy: top), uv: $0.uv) }
        for (index, item) in queued.prefix(max(0, Int((canvas.width - 20) / 48))).enumerated() {
            let rect = OriginalGameplayLayout.action(index)
            parts.append(Part(image: iconFrame, rect: rect, uv: SIMD4(item.0.active ? 0.5 : 0, 0, 0.5, 1)))
            if let image = item.1, let reference = item.0.icon {
                let width = image.size.width / CGFloat(reference.columns), height = image.size.height / CGFloat(reference.rows)
                let scale = min(1, min(39 / width, 39 / height))
                parts.append(Part(image: image, rect: CGRect(x: rect.midX - width * scale / 2, y: rect.midY - height * scale / 2, width: width * scale, height: height * scale), uv: SIMD4(0, 0, 1 / Float(reference.columns), 1 / Float(reference.rows))))
            }
            if item.0.cancelRequested || item.0.cancellable && hoveredAction == index {
                parts.append(Part(image: cancel, rect: rect))
            }
        }
        return parts
    }

    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        let top = canvas.height - 150
        var controls = (state?.household ?? []).enumerated().map { ("Select " + $0.element.name, OriginalGameplayLayout.portrait($0.offset).offsetBy(dx: 0, dy: top)) }
        controls += queued.prefix(max(0, Int((canvas.width - 20) / 48))).enumerated().filter { $0.element.0.cancellable }.map { ("Cancel " + ($0.element.0.name ?? "action"), OriginalGameplayLayout.action($0.offset)) }
        controls += [Subpanel.needs, .relationships, .personality, .career, .interests].filter { supports($0, state: state) }.map { ("Show " + $0.label, buttonRect($0.buttonIndex).offsetBy(dx: 0, dy: top)) }
        if subpanel == .relationships {
            controls += OriginalGameplayLayout.RelationshipFilter.allCases.enumerated().map { ("Show " + $0.element.rawValue + " relationships", OriginalGameplayLayout.relationshipFilter($0.offset).offsetBy(dx: 0, dy: top)) }
            let relationships = OriginalGameplayLayout.relationships(state?.selected?.relationships ?? [], filter: relationshipFilter)
            controls += relationships.dropFirst(relationshipPage * grid.relationshipCapacity).prefix(grid.relationshipCapacity).enumerated().map { ($0.element.name, OriginalGameplayLayout.relationship($0.offset).offsetBy(dx: 0, dy: top)) }
            if relationshipPage > 0 { controls.append(("Previous relationships page", grid.relationshipArrow(false).offsetBy(dx: 0, dy: top))) }
            if (relationshipPage + 1) * grid.relationshipCapacity < relationships.count { controls.append(("Next relationships page", grid.relationshipArrow(true).offsetBy(dx: 0, dy: top))) }
        } else if subpanel == .interests, let age = state?.selected?.career?.age {
            let indices = OriginalGameplayLayout.interestIndices(age: age)
            controls += indices.dropFirst(interestPage * grid.interestCapacity).prefix(grid.interestCapacity).enumerated().map { (OriginalGameplayLayout.interests[$0.element], grid.interest($0.offset).offsetBy(dx: 0, dy: top)) }
            if interestPage > 0 { controls.append(("Previous interests page", grid.interestArrow(false).offsetBy(dx: 0, dy: top))) }
            if (interestPage + 1) * grid.interestCapacity < indices.count { controls.append(("Next interests page", grid.interestArrow(true).offsetBy(dx: 0, dy: top))) }
        }
        return controls
    }

    func selection(at point: CGPoint, canvas: CGSize) -> Int? {
        (state?.household ?? []).enumerated().first { OriginalGameplayLayout.portrait($0.offset).offsetBy(dx: 0, dy: canvas.height - 150).contains(point) }?.element.id
    }
    func cancellation(at point: CGPoint, canvas: CGSize) -> String? {
        queued.prefix(max(0, Int((canvas.width - 20) / 48))).enumerated().first { $0.element.0.cancellable && OriginalGameplayLayout.action($0.offset).contains(point) }?.element.0.token
    }
    func containsPanel(_ point: CGPoint, canvas: CGSize) -> Bool {
        point.y >= canvas.height - 100 || CGRect(x: 0, y: canvas.height - 183, width: 220, height: 183).contains(point) || CGRect(x: 220, y: canvas.height - 150, width: 193, height: 150).contains(point)
    }
}
