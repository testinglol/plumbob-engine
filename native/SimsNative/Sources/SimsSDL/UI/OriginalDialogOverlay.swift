import Foundation
import SimsCore

@MainActor
final class OriginalDialogOverlay {
    struct Image {
        let texture: UITexture
        let size: CGSize
    }
    let dialog: GameDialog
    let font: SimsBitmapFont
    let device: UIDevice
    let frameTexture: UITexture
    let buttonTexture: UITexture
    let bodyTexture: UITexture
    let phoneBookBackground: Image?
    let title: Image
    let labels: [Image]
    private let phoneBookFamilyLabels: [Image]
    private let phoneBookContactLabels: [[Image]]
    private(set) var message: [Image] = []
    private(set) var rect = CGRect.zero
    private(set) var bodyRect = CGRect.zero
    private(set) var buttonRects: [CGRect] = []
    private(set) var input: Image?
    private(set) var text = ""
    private(set) var hovered: Int?
    private var wrappedWidth = 0
    private var scroll = 0
    private var familyScroll = 0
    private var contactScroll = 0
    private var selectedFamily = 0
    private var selectedContact: Int?
    private(set) var phoneBookFamilyRows: [(image: Image, rect: CGRect, selected: Bool)] = []
    private(set) var phoneBookContactRows: [(image: Image, rect: CGRect, selected: Bool)] = []
    private(set) var phoneBookFamilyRect = CGRect.zero
    private(set) var phoneBookContactRect = CGRect.zero
    var submitting = false

    enum PhoneBookAction {
        case changedSelection
        case call(Int)
        case cancel
    }

    init(dialog: GameDialog, font: SimsBitmapFont, device: UIDevice, content: GameContent) throws {
        try dialog.validate()
        self.dialog = dialog
        self.font = font
        self.device = device
        func upload(_ bitmap: SimsBitmap, transparent: Bool) throws -> UITexture {
            try Self.texture(device: device, width: bitmap.width, height: bitmap.height,
                             pixels: SpritePixels.premultipliedSRGB(bitmap.rgba, removeMagenta: transparent))
        }
        frameTexture = try upload(SimsBitmap(data: content.read("UIGraphics/Shared/Dlg/GenDlg.bmp")), transparent: false)
        buttonTexture = try upload(SimsBitmap(data: content.read("UIGraphics/Shared/Sys/WinBtn.bmp")), transparent: true)
        bodyTexture = try upload(SimsBitmap(data: content.read("UIGraphics/Shared/Dlg/LBoxTile.bmp")), transparent: false)
        if dialog.kind == 10 {
            let bitmap = try SimsBitmap(data: content.read("UIGraphics/cpanel/Backgrounds/phonebookbkg.bmp"))
            phoneBookBackground = Image(texture: try Self.texture(device: device, width: bitmap.width, height: bitmap.height,
                                                                   pixels: SpritePixels.premultipliedSRGB(bitmap.rgba, removeMagenta: true)),
                                        size: CGSize(width: bitmap.width, height: bitmap.height))
            phoneBookFamilyLabels = try (dialog.phoneBook ?? []).map { try Self.label($0.name, font: font, device: device, color: SIMD3(24, 24, 24)) }
            phoneBookContactLabels = try (dialog.phoneBook ?? []).map { family in
                try family.contacts.map { try Self.label($0.name, font: font, device: device, color: SIMD3(24, 24, 24)) }
            }
        } else {
            phoneBookBackground = nil
            phoneBookFamilyLabels = []
            phoneBookContactLabels = []
        }
        title = try Self.label(dialog.title, font: font, device: device)
        labels = try dialog.buttons.map { try Self.label($0.label, font: font, device: device) }
        if dialog.kind == 3 { try updateText("") }
    }

    private static func texture(device: UIDevice, width: Int, height: Int, pixels: Data) throws -> UITexture {
        let descriptor = UITextureDescriptor.texture2DDescriptor(pixelFormat: .rgba8Unorm_srgb, width: width, height: height, mipmapped: false)
        descriptor.storageMode = .shared
        descriptor.usage = .shaderRead
        guard let texture = device.makeTexture(descriptor: descriptor) else { throw ContentError.invalid("Cannot allocate game dialog texture") }
        pixels.withUnsafeBytes { texture.replace(region: MTLRegionMake2D(0, 0, width, height), mipmapLevel: 0, withBytes: $0.baseAddress!, bytesPerRow: width * 4) }
        return texture
    }

    private static func label(_ value: String, font: SimsBitmapFont, device: UIDevice, color: SIMD3<UInt8> = SIMD3(255, 255, 255)) throws -> Image {
        let image = try font.rasterize(value, color: color)
        return Image(texture: try texture(device: device, width: image.width, height: image.height,
                                         pixels: SpritePixels.premultipliedSRGB(image.rgba)), size: CGSize(width: image.width, height: image.height))
    }

    func prepare(canvas: CGSize, scale: CGFloat) throws {
        let viewport = CGSize(width: canvas.width / scale, height: canvas.height / scale)
        if dialog.kind == 10 {
            preparePhoneBook(viewport: viewport)
            return
        }
        let width = min(440, max(200, viewport.width - 32))
        let wrap = Int(width - 48)
        if wrappedWidth != wrap {
            let lines = try font.wrappedLines(dialog.message, width: wrap)
            message = try lines.map { try Self.label($0, font: font, device: device) }
            wrappedWidth = wrap
        }
        let textHeight = CGFloat(max(1, message.count) * font.lineHeight)
        let height = min(max(140, textHeight + 120 + (dialog.kind == 3 ? 32 : 0)), viewport.height - 32)
        rect = CGRect(x: (viewport.width - width) / 2, y: (viewport.height - height) / 2, width: width, height: height)
        bodyRect = CGRect(x: rect.minX + 24, y: rect.minY + 44, width: width - 48, height: max(1, height - 106 - (dialog.kind == 3 ? 32 : 0)))
        let buttonWidth = min(100, (width - 48 - CGFloat(max(0, labels.count - 1)) * 12) / CGFloat(max(1, labels.count)))
        let total = buttonWidth * CGFloat(labels.count) + CGFloat(max(0, labels.count - 1)) * 12
        buttonRects = labels.indices.map { CGRect(x: rect.midX - total / 2 + CGFloat($0) * (buttonWidth + 12), y: rect.maxY - 49, width: buttonWidth, height: 33) }
        scroll = min(scroll, max(0, message.count - Int(bodyRect.height) / font.lineHeight))
    }

    private func preparePhoneBook(viewport: CGSize) {
        let width = min(600, max(360, viewport.width - 32))
        let height = min(452, max(280, viewport.height - 32))
        rect = CGRect(x: (viewport.width - width) / 2, y: (viewport.height - height) / 2, width: width, height: height)
        bodyRect = CGRect(x: rect.minX + 24, y: rect.minY + 62, width: rect.width - 48, height: max(80, rect.height - 132))
        let listGap: CGFloat = 18
        let listWidth = (bodyRect.width - listGap) / 2
        phoneBookFamilyRect = CGRect(x: bodyRect.minX, y: bodyRect.minY, width: listWidth, height: bodyRect.height)
        phoneBookContactRect = CGRect(x: phoneBookFamilyRect.maxX + listGap, y: bodyRect.minY, width: listWidth, height: bodyRect.height)
        let rowHeight: CGFloat = 24
        let visibleCount = max(1, Int(bodyRect.height / rowHeight))
        let families = dialog.phoneBook ?? []
        if families.isEmpty { selectedFamily = 0; selectedContact = nil }
        else { selectedFamily = min(max(0, selectedFamily), families.count - 1) }
        let contacts = families.indices.contains(selectedFamily) ? families[selectedFamily].contacts : []
        if contacts.isEmpty { selectedContact = nil }
        else if let selectedContact { self.selectedContact = min(max(0, selectedContact), contacts.count - 1) }
        familyScroll = min(familyScroll, max(0, families.count - visibleCount))
        contactScroll = min(contactScroll, max(0, contacts.count - visibleCount))
        phoneBookFamilyRows = families.indices.dropFirst(familyScroll).prefix(visibleCount).map { index in
            let row = index - familyScroll
            return (phoneBookFamilyLabels[index], CGRect(x: phoneBookFamilyRect.minX + 4, y: phoneBookFamilyRect.minY + CGFloat(row) * rowHeight + 2,
                                                          width: phoneBookFamilyRect.width - 8, height: rowHeight - 2), index == selectedFamily)
        }
        phoneBookContactRows = contacts.indices.dropFirst(contactScroll).prefix(visibleCount).map { index in
            let row = index - contactScroll
            return (phoneBookContactLabels[selectedFamily][index], CGRect(x: phoneBookContactRect.minX + 4, y: phoneBookContactRect.minY + CGFloat(row) * rowHeight + 2,
                                                                          width: phoneBookContactRect.width - 8, height: rowHeight - 2), index == selectedContact)
        }
        let buttonWidth: CGFloat = 112
        let buttonHeight: CGFloat = 34
        let gap: CGFloat = 18
        let total = buttonWidth * CGFloat(labels.count) + gap * CGFloat(max(0, labels.count - 1))
        buttonRects = labels.indices.map { index in
            CGRect(x: rect.midX - total / 2 + CGFloat(index) * (buttonWidth + gap), y: rect.maxY - 49, width: buttonWidth, height: buttonHeight)
        }
    }

    var visibleLines: [(image: Image, rect: CGRect)] {
        let count = max(1, Int(bodyRect.height) / font.lineHeight)
        return message.dropFirst(scroll).prefix(count).enumerated().map { index, image in
            (image, CGRect(x: bodyRect.minX, y: bodyRect.minY + CGFloat(index * font.lineHeight), width: image.size.width, height: image.size.height))
        }
    }

    var inputRect: CGRect { CGRect(x: rect.minX + 24, y: rect.maxY - 83, width: rect.width - 48, height: 28) }
    func hover(_ point: CGPoint, scale: CGFloat) { hovered = buttonRects.firstIndex { $0.contains(CGPoint(x: point.x / scale, y: point.y / scale)) } }
    func choice(_ point: CGPoint, scale: CGFloat) -> UInt8? {
        guard !submitting, let index = buttonRects.firstIndex(where: { $0.contains(CGPoint(x: point.x / scale, y: point.y / scale)) }) else { return nil }
        return dialog.buttons[index].code
    }
    func phoneBookAction(_ point: CGPoint, scale: CGFloat) -> PhoneBookAction? {
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        if let row = phoneBookFamilyRows.firstIndex(where: { $0.rect.contains(local) }) {
            let index = familyScroll + row
            guard index != selectedFamily else { return nil }
            selectedFamily = index
            selectedContact = nil
            contactScroll = 0
            return .changedSelection
        }
        if let row = phoneBookContactRows.firstIndex(where: { $0.rect.contains(local) }) {
            let index = contactScroll + row
            guard let family = phoneBookFamily(at: selectedFamily), family.contacts.indices.contains(index) else { return nil }
            selectedContact = index
            return .changedSelection
        }
        if let button = buttonRects.firstIndex(where: { $0.contains(local) }) {
            if dialog.buttons[button].code == 0 { return .cancel }
            if let selectedContact, let family = phoneBookFamily(at: selectedFamily), family.contacts.indices.contains(selectedContact) {
                return .call(family.contacts[selectedContact].neighborId)
            }
        }
        return nil
    }

    func movePhoneBookSelection(_ delta: Int) {
        guard let family = phoneBookFamily(at: selectedFamily), !family.contacts.isEmpty else { return }
        selectedContact = min(max(0, (selectedContact ?? 0) + delta), family.contacts.count - 1)
        let visibleCount = max(1, Int(phoneBookContactRect.height / 24))
        if let selectedContact {
            if selectedContact < contactScroll { contactScroll = selectedContact }
            else if selectedContact >= contactScroll + visibleCount { contactScroll = selectedContact - visibleCount + 1 }
        }
    }

    func movePhoneBookFamily(_ delta: Int) {
        guard let families = dialog.phoneBook, !families.isEmpty else { return }
        selectedFamily = min(max(0, selectedFamily + delta), families.count - 1)
        selectedContact = nil
        contactScroll = 0
        if selectedFamily < familyScroll { familyScroll = selectedFamily }
        else if selectedFamily >= familyScroll + max(1, Int(phoneBookFamilyRect.height / 24)) {
            familyScroll = selectedFamily - max(1, Int(phoneBookFamilyRect.height / 24)) + 1
        }
    }

    func selectedPhoneBookContact() -> Int? {
        guard let family = phoneBookFamily(at: selectedFamily), let selectedContact, family.contacts.indices.contains(selectedContact) else { return nil }
        return family.contacts[selectedContact].neighborId
    }

    func scrollPhoneBook(_ delta: Float, point: CGPoint, scale: CGFloat) {
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        let amount = max(1, abs(Int(delta.rounded())))
        if phoneBookFamilyRect.contains(local) {
            let count = dialog.phoneBook?.count ?? 0
            familyScroll = min(max(0, familyScroll + (delta > 0 ? -amount : amount)), max(0, count - max(1, Int(phoneBookFamilyRect.height / 24))))
        } else {
            let count = phoneBookFamily(at: selectedFamily)?.contacts.count ?? 0
            contactScroll = min(max(0, contactScroll + (delta > 0 ? -amount : amount)), max(0, count - max(1, Int(phoneBookContactRect.height / 24))))
        }
    }

    var phoneBookAccessibilityControls: [(label: String, rect: CGRect)] {
        guard dialog.kind == 10 else { return [] }
        let families = (dialog.phoneBook ?? []).dropFirst(familyScroll).prefix(phoneBookFamilyRows.count)
        let contacts = (phoneBookFamily(at: selectedFamily)?.contacts ?? []).dropFirst(contactScroll).prefix(phoneBookContactRows.count)
        let familyControls = zip(families, phoneBookFamilyRows).map { ($0.0.name, $0.1.rect) }
        let contactControls = zip(contacts, phoneBookContactRows).map { ($0.0.name, $0.1.rect) }
        let buttonControls = dialog.buttons.enumerated().map { ($0.element.label, buttonRects[$0.offset]) }
        return familyControls + contactControls + buttonControls
    }

    private func phoneBookFamily(at index: Int) -> GameDialog.PhoneBookFamily? {
        guard let phoneBook = dialog.phoneBook, phoneBook.indices.contains(index) else { return nil }
        return phoneBook[index]
    }

    func scrollMessage(_ delta: Float) { scroll = min(max(0, scroll + Int(delta.rounded())), max(0, message.count - max(1, Int(bodyRect.height) / font.lineHeight))) }

    func updateText(_ value: String) throws {
        guard value.utf16.count <= 32, !value.contains(where: { $0.isNewline || $0.asciiValue == 0 }) else { return }
        text = value
        input = try Self.label(value + "|", font: font, device: device, color: SIMD3(0, 0, 0))
    }
}
