import Foundation
import SimsCore

@MainActor
final class OriginalHouseholdCreationOverlay {
    typealias Image = OriginalGameplayOverlay.Image

    struct DrawItem {
        let image: Image
        let rect: CGRect
        var uv = SIMD4<Float>(0, 0, 1, 1)
    }

    private struct Draft: Equatable {
        var name = ""
        var bio = ""
        var female = false
        var child = false
        var skin = "med"
        var bodyType = "fit"
        var headChoice: String?
        var bodyChoice: String?
        var personality = [500, 500, 500, 500, 500]

        var code: String { (female ? "f" : "m") + (child ? "c" : "a") + bodyType }

        func member() -> HouseholdCreationRequest.Member {
            HouseholdCreationRequest.Member(name: name, bio: bio, code: code, skin: skin, personality: personality,
                                            headChoice: headChoice, bodyChoice: bodyChoice)
        }
    }

    private enum Page { case family, sim }
    private enum Field { case family, sim, bio }

    private struct ButtonSheet {
        let image: Image
        let columns: Int
    }

    private let device: UIDevice
    private let font: SimsBitmapFont
    private let familyBackground: Image
    private let simBackground: Image
    private let strings: OriginalUIStrings
    private var buttonSheets: [String: ButtonSheet] = [:]
    private var textImages: [String: Image] = [:]
    private var page = Page.family
    private var field = Field.family
    private var familyName = ""
    private var members: [Draft] = []
    private var draft = Draft()
    private var appearanceCatalog: HouseholdAppearanceCatalog?
    private var editingMember: Int?
    private var selectedMember = 0
    private var caretOffset = 0
    private var error = ""
    private(set) var submitting = false

    func beginSubmission() { submitting = true }

    init(content: GameContent, device: UIDevice) throws {
        self.device = device
        strings = OriginalUIStrings(content: content)
        font = try SimsBitmapFont(data: content.read("UIGraphics/Fonts/variablesans_10.ffn"))
        let family = try SimsBitmap(data: content.read("UIGraphics/Nbhd/DsgnFamBkg.bmp"))
        let sim = try SimsBitmap(data: content.read("UIGraphics/Nbhd/CreateACharBack.bmp"))
        guard family.width == 800, family.height == 600, sim.width == 800, sim.height == 600 else {
            throw ContentError.invalid("Original family creation backgrounds are not 800×600")
        }
        familyBackground = try Self.upload(device: device, bitmap: family)
        simBackground = try Self.upload(device: device, bitmap: sim)
        let assets: [(String, String, Int)] = [
            ("add", "AddPersonBtn.bmp", 4), ("delete", "DeletePersonBtn.bmp", 4), ("edit", "EditPersonBtn.bmp", 4),
            ("familyDone", "DesignFamDone.bmp", 6), ("familyCancel", "DesignFamCancel.bmp", 6),
            ("adult", "DesignCharAdultBtn.bmp", 4), ("child", "DesignCharChildBtn.bmp", 4),
            ("skinsLeft", "DesignCharSkinsLeftBtn.bmp", 4), ("skinsRight", "DesignCharSkinsRightBtn.bmp", 4),
            ("simDone", "DesignCharDoneBtn.bmp", 6), ("simCancel", "DesignCharCancelBtn.bmp", 6),
            ("female", "DesignCharFemaleBtn.bmp", 4), ("male", "DesignCharMaleBtn.bmp", 4),
            ("dark", "DesignCharDarkBtn.bmp", 4), ("medium", "DesignCharMediumBtn.bmp", 4), ("light", "DesignCharLightBtn.bmp", 4)
        ]
        for (name, file, columns) in assets {
            let bitmap = try SimsBitmap(data: content.read("UIGraphics/Nbhd/" + file))
            guard bitmap.width.isMultiple(of: columns) else { throw ContentError.invalid("Original household button sheet has invalid frame dimensions: \(file)") }
            let image = try Self.upload(device: device, bitmap: bitmap, magenta: true)
            buttonSheets[name] = ButtonSheet(image: image, columns: columns)
        }
    }

    private static func upload(device: UIDevice, bitmap: SimsBitmap, magenta: Bool = false) throws -> Image {
        try upload(device: device, width: bitmap.width, height: bitmap.height, pixels: bitmap.rgba, magenta: magenta)
    }

    private static func upload(device: UIDevice, width: Int, height: Int, pixels: Data, magenta: Bool = false) throws -> Image {
        let descriptor = UITextureDescriptor.texture2DDescriptor(pixelFormat: .rgba8Unorm_srgb, width: width, height: height, mipmapped: false)
        descriptor.storageMode = .shared
        descriptor.usage = .shaderRead
        guard let texture = device.makeTexture(descriptor: descriptor) else { throw ContentError.invalid("Cannot allocate original household screen texture") }
        let converted = try SpritePixels.premultipliedSRGB(pixels, removeMagenta: magenta)
        converted.withUnsafeBytes { texture.replace(region: MTLRegionMake2D(0, 0, width, height), mipmapLevel: 0, withBytes: $0.baseAddress!, bytesPerRow: width * 4) }
        return Image(texture: texture, size: CGSize(width: width, height: height))
    }

    private func button(_ name: String, frame: Int, x: CGFloat, y: CGFloat, factor: CGFloat) -> DrawItem? {
        guard let sheet = buttonSheets[name], frame >= 0, frame < sheet.columns else { return nil }
        let frameWidth = sheet.image.size.width / CGFloat(sheet.columns)
        return DrawItem(image: sheet.image, rect: CGRect(x: x * factor, y: y * factor, width: frameWidth * factor, height: sheet.image.size.height * factor),
                        uv: SIMD4<Float>(Float(frame) / Float(sheet.columns), 0, 1 / Float(sheet.columns), 1))
    }

    private func label(_ value: String, color: SIMD3<UInt8> = SIMD3(255, 255, 255)) -> Image? {
        let key = "\(color.x)-\(color.y)-\(color.z):\(value)"
        if let image = textImages[key] { return image }
        guard let raster = try? font.rasterize(value, color: color),
              let image = try? Self.upload(device: device, width: raster.width, height: raster.height, pixels: raster.rgba) else { return nil }
        textImages[key] = image
        return image
    }

    func drawItems(canvas: CGSize) -> [DrawItem] {
        let factor = canvas.height / 600
        let left = (canvas.width - 800 * factor) / 2
        let background = page == .family ? familyBackground : simBackground
        var items = [DrawItem(image: background, rect: CGRect(x: left, y: 0, width: 800 * factor, height: 600 * factor))]
        func add(_ value: String, x: CGFloat, y: CGFloat, color: SIMD3<UInt8> = SIMD3(255, 255, 255)) {
            guard let image = label(value, color: color) else { return }
            items.append(DrawItem(image: image, rect: CGRect(x: left + x * factor, y: y * factor, width: image.size.width * factor, height: image.size.height * factor)))
        }
        let amber = SIMD3<UInt8>(255, 218, 116)
        if page == .family {
            if let item = button("add", frame: members.count < 8 ? 0 : 3, x: left / factor + 594, y: 103, factor: factor) { items.append(item) }
            if let item = button("edit", frame: members.indices.contains(selectedMember) ? 0 : 3, x: left / factor + 594, y: 207, factor: factor) { items.append(item) }
            if let item = button("delete", frame: members.indices.contains(selectedMember) ? 0 : 3, x: left / factor + 594, y: 310, factor: factor) { items.append(item) }
            if let item = button("familyCancel", frame: 0, x: left / factor + 492, y: 472, factor: factor) { items.append(item) }
            if let item = button("familyDone", frame: 0, x: left / factor + 625, y: 472, factor: factor) { items.append(item) }
            let familyText = familyName.isEmpty ? strings.family(12, fallback: "Enter Last Name:") : familyName
            let displayedFamilyName = field == .family && !familyName.isEmpty ? withCaret(familyText) : familyText
            add(displayedFamilyName, x: 280, y: 56, color: amber)
            for index in members.indices {
                let member = members[index]
                let selected = index == selectedMember
                let age = member.child ? strings.sim(1, fallback: "Child") : strings.sim(0, fallback: "Adult")
                add("\(selected ? ">" : " ") \(member.name) · \(age)", x: 96, y: 152 + CGFloat(index) * 32, color: selected ? amber : SIMD3(230, 230, 230))
            }
            if !error.isEmpty { add(error, x: 92, y: 462, color: SIMD3(255, 150, 132)) }
        } else {
            if let item = button("male", frame: draft.female ? 0 : 1, x: left / factor + 400, y: 102, factor: factor) { items.append(item) }
            if let item = button("female", frame: draft.female ? 1 : 0, x: left / factor + 498, y: 97, factor: factor) { items.append(item) }
            if let item = button("adult", frame: draft.child ? 0 : 1, x: left / factor + 396, y: 185, factor: factor) { items.append(item) }
            if let item = button("child", frame: draft.child ? 1 : 0, x: left / factor + 498, y: 184, factor: factor) { items.append(item) }
            let skinButtons = [("light", "lgt", CGFloat(396)), ("medium", "med", CGFloat(452)), ("dark", "drk", CGFloat(499))]
            for (name, skin, x) in skinButtons {
                if let item = button(name, frame: draft.skin == skin ? 1 : 0, x: left / factor + x, y: 242, factor: factor) { items.append(item) }
            }
            if let catalog = appearanceCatalog {
                if catalog.heads.contains(where: { $0.id == draft.headChoice }) {
                    if let item = button("skinsLeft", frame: 0, x: left / factor + 570, y: 300, factor: factor) { items.append(item) }
                    if let item = button("skinsRight", frame: 1, x: left / factor + 720, y: 300, factor: factor) { items.append(item) }
                }
                if catalog.bodies.contains(where: { $0.id == draft.bodyChoice }) {
                    if let item = button("skinsLeft", frame: 0, x: left / factor + 570, y: 348, factor: factor) { items.append(item) }
                    if let item = button("skinsRight", frame: 1, x: left / factor + 720, y: 348, factor: factor) { items.append(item) }
                }
            }
            if let item = button("simCancel", frame: 0, x: left / factor + 492, y: 536, factor: factor) { items.append(item) }
            if let item = button("simDone", frame: 0, x: left / factor + 640, y: 536, factor: factor) { items.append(item) }
            let simText = draft.name.isEmpty ? strings.sim(26, fallback: "Enter First Name:") : draft.name
            let displayedSimName = field == .sim && !draft.name.isEmpty ? withCaret(simText) : simText
            add(displayedSimName, x: 280, y: 56, color: amber)
            let traitKeys = ["Neat", "Outgoing", "Active", "Playful", "Nice"]
            let traits = (17...21).map { strings.sim($0, fallback: traitKeys[$0 - 17]) }
            for index in traits.indices {
                let points = draft.personality[index] / 100
                add(traits[index], x: 93, y: 132 + CGFloat(index) * 32)
                add(String(points), x: 250, y: 132 + CGFloat(index) * 32, color: amber)
            }
            let personality = Dictionary(uniqueKeysWithValues: zip(traitKeys, draft.personality))
            let zodiac = OriginalGameplayLayout.zodiac(personality: personality, stored: 0)
            add("\(strings.sim(27, fallback: "Astrological Sign")):  \(strings.sign(zodiac - 1, fallback: OriginalGameplayLayout.signs[zodiac - 1]))", x: 93, y: 292, color: amber)
            let biographyLabel = draft.name.isEmpty ? strings.sim(24, fallback: "BIO") : strings.sim(25, fallback: "Bio for %s").replacingOccurrences(of: "%s", with: draft.name)
            add(field == .bio ? withCaret(biographyLabel) : biographyLabel, x: 30, y: 435, color: amber)
            add(field == .bio ? withCaret(draft.bio) : draft.bio, x: 31, y: 466)
            if !error.isEmpty { add(error, x: 30, y: 510, color: SIMD3(255, 150, 132)) }
        }
        return items
    }

    func controls(canvas: CGSize) -> [(label: String, rect: CGRect)] {
        let factor = canvas.height / 600
        let left = (canvas.width - 800 * factor) / 2
        func rect(_ value: CGRect) -> CGRect { CGRect(x: left + value.minX * factor, y: value.minY * factor, width: value.width * factor, height: value.height * factor) }
        if page == .family {
            var items = [(strings.control("familyName"), rect(CGRect(x: 260, y: 44, width: 282, height: 40))),
                         (strings.control("addSim"), rect(CGRect(x: 594, y: 103, width: 139, height: 103))),
                         (strings.control("editSim"), rect(CGRect(x: 594, y: 207, width: 137, height: 99))),
                         (strings.control("deleteSim"), rect(CGRect(x: 594, y: 310, width: 149, height: 99))),
                         (strings.control("familyCancel"), rect(CGRect(x: 492, y: 472, width: 149, height: 52))),
                         (strings.control("familyDone"), rect(CGRect(x: 625, y: 472, width: 110, height: 52)))]
            items += members.enumerated().map { index, member in
                let age = member.child ? strings.sim(1, fallback: "Child") : strings.sim(0, fallback: "Adult")
                let selected = index == selectedMember ? "✓ " : ""
                return ("\(selected)\(member.name) · \(age)", rect(CGRect(x: 76, y: 140 + CGFloat(index) * 32, width: 508, height: 32)))
            }
            return items
        }
        return [(strings.control("simName"), rect(CGRect(x: 260, y: 44, width: 282, height: 40))),
                (strings.control("male"), rect(CGRect(x: 400, y: 102, width: 98, height: 80))),
                (strings.control("female"), rect(CGRect(x: 498, y: 97, width: 57, height: 86))),
                (strings.control("adult"), rect(CGRect(x: 396, y: 185, width: 57, height: 57))),
                (strings.control("child"), rect(CGRect(x: 498, y: 184, width: 92, height: 58))),
                (strings.control("light"), rect(CGRect(x: 396, y: 242, width: 55, height: 71))),
                (strings.control("medium"), rect(CGRect(x: 452, y: 242, width: 46, height: 71))),
                (strings.control("dark"), rect(CGRect(x: 499, y: 242, width: 57, height: 71))),
                (strings.control("previousHead"), rect(CGRect(x: 570, y: 300, width: 44, height: 44))),
                (strings.control("nextHead"), rect(CGRect(x: 720, y: 300, width: 44, height: 44))),
                (strings.control("previousBody"), rect(CGRect(x: 570, y: 348, width: 44, height: 44))),
                (strings.control("nextBody"), rect(CGRect(x: 720, y: 348, width: 44, height: 44))),
                (strings.control("personality"), rect(CGRect(x: 80, y: 124, width: 225, height: 175))),
                (controlLabel("biography"), rect(CGRect(x: 24, y: 424, width: 752, height: 96))),
                (strings.control("simDone"), rect(CGRect(x: 640, y: 536, width: 105, height: 40))),
                (strings.control("simCancel"), rect(CGRect(x: 492, y: 536, width: 137, height: 40)))]
    }

    func controlLabel(_ key: String) -> String {
        if key == "biography" {
            return draft.name.isEmpty ? strings.sim(24, fallback: "BIO") : strings.sim(25, fallback: "Bio for %s").replacingOccurrences(of: "%s", with: draft.name)
        }
        return strings.control(key)
    }

    func appearancePreviewRect(canvas: CGSize) -> CGRect? {
        guard page == .sim else { return nil }
        let factor = canvas.height / 600
        let left = (canvas.width - 800 * factor) / 2
        return CGRect(x: left + 565 * factor, y: 108 * factor, width: 205 * factor, height: 190 * factor)
    }

    func appearancePreviewSelection() -> (gender: String, age: String, skin: String, headChoice: String, bodyChoice: String)? {
        guard appearanceCatalog != nil, let headChoice = draft.headChoice, let bodyChoice = draft.bodyChoice else { return nil }
        return (draft.female ? "f" : "m", draft.child ? "child" : "adult", draft.skin, headChoice, bodyChoice)
    }

    /// Receives original UI sound event names for control feedback.
    var playSound: ((String) -> Void)?

    func click(_ point: CGPoint, canvas: CGSize, submit: (HouseholdCreationRequest) -> Void, cancel: () -> Void = {}, delete: ((Int) -> Void)? = nil, appearanceCatalog requestAppearance: ((String, String, String) -> Void)? = nil, previewAppearance requestPreview: ((String, String, String, String, String) -> Void)? = nil) {
        guard !submitting else { return }
        let factor = canvas.height / 600
        let left = (canvas.width - 800 * factor) / 2
        let logical = CGPoint(x: (point.x - left) / factor, y: point.y / factor)
        error = ""
        if page == .family {
            if CGRect(x: 260, y: 44, width: 282, height: 40).contains(logical) { field = .family; caretOffset = familyName.count; return }
            if CGRect(x: 76, y: 140, width: 508, height: 250).contains(logical), !members.isEmpty {
                selectedMember = min(members.count - 1, max(0, Int((logical.y - 140) / 32)))
                return
            }
            if CGRect(x: 594, y: 103, width: 139, height: 103).contains(logical), members.count < 8 {
                page = .sim
                draft = Draft()
                editingMember = nil
                field = .sim
                caretOffset = 0
                resetAppearance(requestAppearance)
                return
            }
            if CGRect(x: 594, y: 207, width: 137, height: 99).contains(logical), members.indices.contains(selectedMember) {
                page = .sim
                draft = members[selectedMember]
                editingMember = selectedMember
                field = .sim
                caretOffset = draft.name.count
                requestCurrentAppearance(requestAppearance)
                return
            }
            if CGRect(x: 594, y: 310, width: 149, height: 99).contains(logical), members.indices.contains(selectedMember) {
                delete?(selectedMember)
                return
            }
            if CGRect(x: 492, y: 472, width: 149, height: 52).contains(logical) { cancel(); return }
            if CGRect(x: 625, y: 472, width: 110, height: 52).contains(logical) {
                do {
                    let request = HouseholdCreationRequest(familyName: familyName, members: members.map { $0.member() })
                    try request.validate()
                    submit(request)
                } catch { self.error = String(describing: error) }
                return
            }
        } else {
            if CGRect(x: 260, y: 44, width: 282, height: 40).contains(logical) { field = .sim; caretOffset = draft.name.count; return }
            if CGRect(x: 24, y: 424, width: 752, height: 96).contains(logical) { field = .bio; caretOffset = draft.bio.count; return }
            if CGRect(x: 396, y: 242, width: 55, height: 71).contains(logical) { if draft.skin != "lgt" { draft.skin = "lgt"; resetAppearance(requestAppearance) }; return }
            if CGRect(x: 452, y: 242, width: 46, height: 71).contains(logical) { if draft.skin != "med" { draft.skin = "med"; resetAppearance(requestAppearance) }; return }
            if CGRect(x: 499, y: 242, width: 57, height: 71).contains(logical) { if draft.skin != "drk" { draft.skin = "drk"; resetAppearance(requestAppearance) }; return }
            if CGRect(x: 396, y: 185, width: 57, height: 57).contains(logical) { if draft.child { draft.child = false; resetAppearance(requestAppearance) }; return }
            if CGRect(x: 498, y: 184, width: 92, height: 58).contains(logical) { if !draft.child { draft.child = true; resetAppearance(requestAppearance) }; return }
            if CGRect(x: 400, y: 102, width: 98, height: 80).contains(logical) { if draft.female { draft.female = false; resetAppearance(requestAppearance) }; return }
            if CGRect(x: 498, y: 97, width: 57, height: 86).contains(logical) { if !draft.female { draft.female = true; resetAppearance(requestAppearance) }; return }
            if CGRect(x: 570, y: 300, width: 44, height: 44).contains(logical) { cycleHead(-1); playSound?("ui_cac_cyclehead"); requestPreviewForCurrentSelection(requestPreview); return }
            if CGRect(x: 720, y: 300, width: 44, height: 44).contains(logical) { cycleHead(1); playSound?("ui_cac_cyclehead"); requestPreviewForCurrentSelection(requestPreview); return }
            if CGRect(x: 570, y: 348, width: 44, height: 44).contains(logical) { cycleBody(-1); playSound?("ui_cac_cycleparts"); requestPreviewForCurrentSelection(requestPreview); return }
            if CGRect(x: 720, y: 348, width: 44, height: 44).contains(logical) { cycleBody(1); playSound?("ui_cac_cycleparts"); requestPreviewForCurrentSelection(requestPreview); return }
            if CGRect(x: 80, y: 124, width: 225, height: 175).contains(logical) {
                let index = min(4, max(0, Int((logical.y - 124) / 32)))
                let selected = logical.x < 220 ? min(1000, draft.personality[index] + 100) : min(1000, max(0, Int(((logical.x - 220) / 75 * 10).rounded()) * 100))
                var difference = selected - draft.personality[index]
                if difference > 0 {
                    for offset in 1..<5 {
                        let other = (index + offset) % 5
                        let transfer = min(difference, draft.personality[other])
                        draft.personality[other] -= transfer
                        difference -= transfer
                    }
                } else if difference < 0 {
                    difference = -difference
                    for offset in 1..<5 {
                        let other = (index + offset) % 5
                        let transfer = min(difference, 1000 - draft.personality[other])
                        draft.personality[other] += transfer
                        difference -= transfer
                    }
                    difference = -difference
                }
                draft.personality[index] = selected - difference
                playSound?("ui_cac_personpts")
                return
            }
            if CGRect(x: 492, y: 536, width: 137, height: 40).contains(logical) { page = .family; field = .family; caretOffset = familyName.count; return }
            if CGRect(x: 640, y: 536, width: 105, height: 40).contains(logical) {
                do {
                    try draft.member().validate()
                    if let editingMember { members[editingMember] = draft; selectedMember = editingMember }
                    else { members.append(draft); selectedMember = members.count - 1 }
                    page = .family
                    field = .family
                    caretOffset = familyName.count
                } catch { self.error = String(describing: error) }
            }
        }
    }

    func deleteMember(at index: Int) {
        guard !submitting, members.indices.contains(index) else { return }
        members.remove(at: index)
        selectedMember = max(0, min(index, members.count - 1))
    }

    func key(_ key: String, cancel: () -> Void = {}) -> Bool {
        if key == "\u{1b}" {
            if page == .sim { page = .family; field = .family; caretOffset = familyName.count }
            else { cancel() }
            return true
        }
        if key == "\r" || key == "\n" {
            if page == .sim {
                click(CGPoint(x: 690, y: 556), canvas: CGSize(width: 800, height: 600), submit: { _ in })
            } else {
                click(CGPoint(x: 680, y: 498), canvas: CGSize(width: 800, height: 600), submit: { _ in })
            }
            return true
        }
        if key == "\u{f702}" {
            caretOffset = max(0, caretOffset - 1)
            return true
        }
        if key == "\u{f703}" {
            caretOffset = min(currentFieldText.count, caretOffset + 1)
            return true
        }
        if key == "\u{f729}" {
            caretOffset = 0
            return true
        }
        if key == "\u{f72b}" {
            caretOffset = currentFieldText.count
            return true
        }
        editCurrentField(with: key)
        return true
    }

    private var currentFieldText: String {
        switch field {
        case .family: familyName
        case .sim: draft.name
        case .bio: draft.bio
        }
    }

    private func setCurrentFieldText(_ value: String) {
        switch field {
        case .family: familyName = value
        case .sim: draft.name = value
        case .bio: draft.bio = value
        }
    }

    private func editCurrentField(with key: String) {
        var value = currentFieldText
        let maximum = field == .bio ? 512 : 32
        let boundedOffset = min(max(0, caretOffset), value.count)
        let caret = value.index(value.startIndex, offsetBy: boundedOffset)
        if key == "\u{7f}" || key == "\u{8}" {
            guard caret > value.startIndex else { return }
            let previous = value.index(before: caret)
            value.removeSubrange(previous..<caret)
            caretOffset = boundedOffset - 1
        } else if key == "\u{f728}" {
            guard caret < value.endIndex else { return }
            let next = value.index(after: caret)
            value.removeSubrange(caret..<next)
            caretOffset = boundedOffset
        } else {
            guard !key.isEmpty,
                  !key.unicodeScalars.contains(where: CharacterSet.controlCharacters.contains),
                  value.utf16.count + key.utf16.count <= maximum else { return }
            value.insert(contentsOf: key, at: caret)
            caretOffset = boundedOffset + key.count
        }
        setCurrentFieldText(value)
    }

    private func withCaret(_ value: String) -> String {
        let offset = min(max(0, caretOffset), value.count)
        let position = value.index(value.startIndex, offsetBy: offset)
        return String(value[..<position]) + "|" + String(value[position...])
    }

    func failed(_ message: String) {
        submitting = false
        error = String(message.prefix(100))
    }

    func previewFailed(_ message: String) {
        error = String(message.prefix(100))
    }

    func setAppearanceCatalog(_ catalog: HouseholdAppearanceCatalog) {
        guard catalog.gender == (draft.female ? "f" : "m"),
              catalog.age == (draft.child ? "child" : "adult"), catalog.skin == draft.skin else { return }
        appearanceCatalog = catalog
        if !catalog.heads.contains(where: { $0.id == draft.headChoice }) { draft.headChoice = catalog.heads.first?.id }
        if let body = catalog.bodies.first(where: { $0.id == draft.bodyChoice }) ?? catalog.bodies.first {
            draft.bodyChoice = body.id
            draft.bodyType = body.bodyType
        }
    }

    private func resetAppearance(_ requestAppearance: ((String, String, String) -> Void)?) {
        appearanceCatalog = nil
        draft.headChoice = nil
        draft.bodyChoice = nil
        draft.bodyType = "fit"
        requestCurrentAppearance(requestAppearance)
    }

    private func requestCurrentAppearance(_ requestAppearance: ((String, String, String) -> Void)?) {
        requestAppearance?(draft.female ? "f" : "m", draft.child ? "child" : "adult", draft.skin)
    }

    private func requestPreviewForCurrentSelection(_ requestPreview: ((String, String, String, String, String) -> Void)?) {
        guard let selection = appearancePreviewSelection() else { return }
        requestPreview?(selection.gender, selection.age, selection.skin, selection.headChoice, selection.bodyChoice)
    }

    private func cycleHead(_ offset: Int) {
        guard let choices = appearanceCatalog?.heads, !choices.isEmpty else { return }
        let current = choices.firstIndex(where: { $0.id == draft.headChoice }) ?? 0
        draft.headChoice = choices[(current + offset + choices.count) % choices.count].id
    }

    private func cycleBody(_ offset: Int) {
        guard let choices = appearanceCatalog?.bodies, !choices.isEmpty else { return }
        let current = choices.firstIndex(where: { $0.id == draft.bodyChoice }) ?? 0
        let choice = choices[(current + offset + choices.count) % choices.count]
        draft.bodyChoice = choice.id
        draft.bodyType = choice.bodyType
    }

    func showSimPreview() {
        page = .sim
        field = .sim
        draft = Draft()
    }
}
