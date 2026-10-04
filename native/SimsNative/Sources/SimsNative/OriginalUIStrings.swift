import Foundation
import SimsCore

struct OriginalUIStrings {
    private let tables: [UInt16: [String]]

    init(content: GameContent) {
        if let data = try? content.read("GameData/UIText.iff"),
           let resource = OriginalStringResource(data: data, languageCode: content.language.code) {
            tables = resource.tables
        } else {
            tables = [:]
        }
    }

    func family(_ index: Int, fallback: String) -> String {
        value(table: 129, index: index, fallback: fallback)
    }

    func familyCancelConfirmationTitle() -> String {
        family(7, fallback: "Cancel?")
    }

    func familyCancelConfirmationMessage() -> String {
        family(8, fallback: "Are you sure you want to cancel and lose this family?")
    }

    func familyDoneConfirmationTitle() -> String {
        family(13, fallback: "Finished?")
    }

    func familyDoneConfirmationMessage() -> String {
        family(14, fallback: "Are you sure you are finished? You cannot return to the Create A Family screen to edit this family again.")
    }

    func familyDeleteConfirmationTitle() -> String {
        family(5, fallback: "Delete Sim?")
    }

    func familyDeleteConfirmationMessage() -> String {
        family(6, fallback: "Are you sure you would like to delete this Sim?")
    }

    func sim(_ index: Int, fallback: String) -> String {
        value(table: 130, index: index, fallback: fallback)
    }

    func sign(_ index: Int, fallback: String) -> String {
        value(table: 164, index: index, fallback: fallback)
    }

    func saveHouseTitle() -> String {
        value(table: 153, index: 15, fallback: "Save House")
    }

    func saveConfirmationMessage() -> String {
        value(table: 153, index: 4, fallback: "Do you want to save the game?")
    }

    func loadHouseTitle() -> String {
        value(table: 153, index: 19, fallback: "Load House")
    }

    func loadConfirmationMessage() -> String {
        value(table: 131, index: 8, fallback: "Are you sure?")
    }

    func quitTitle() -> String { value(table: 153, index: 1, fallback: "Quit?") }

    func quitMessage() -> String { value(table: 153, index: 2, fallback: "Are you sure you want to quit?") }

    func saveBeforeQuitMessage() -> String { value(table: 153, index: 6, fallback: "Do you want to save before quitting?") }

    func saveFailedMessage() -> String {
        value(table: 153, index: 14, fallback: "An error was encountered saving the house.")
    }

    func loadFailedMessage() -> String {
        value(table: 153, index: 18, fallback: "The house could not be loaded.")
    }

    func pickFamily(_ index: Int, fallback: String) -> String { value(table: 128, index: index, fallback: fallback) }

    func purchaseHouseTitle() -> String { value(table: 132, index: 0, fallback: "Purchase House?") }

    func purchaseHouseMessage() -> String { value(table: 132, index: 1, fallback: "Are you sure you want to buy this house?") }

    /// STR# 225: "Please Purchase The Sims Hot Date / Vacation / … to be able to visit …".
    func missingPackTip(_ index: Int, fallback: String) -> String { value(table: 225, index: index, fallback: fallback) }

    /// STR# 169 entry 0, the Return button tooltip on the expansion maps.
    func returnTip(fallback: String) -> String { value(table: 169, index: 0, fallback: fallback) }

    func neighborhoodButtonTip(_ index: Int, fallback: String) -> String { value(table: 151, index: index, fallback: fallback) }

    func bulldozeTitle() -> String { value(table: 131, index: 0, fallback: "Bulldoze House?") }

    func bulldozeMessage() -> String { value(table: 131, index: 1, fallback: "Do you want to bulldoze this house?") }

    /// STR# 250 and 251: the rezone question and zoning type names (0 Residential, 1 Community).
    func rezoneTitle() -> String { value(table: 250, index: 0, fallback: "Rezone House?") }
    func rezoneMessage() -> String { value(table: 250, index: 1, fallback: "This lot is currently zoned as a %s lot. Please choose what type of lot you want this to be:") }
    func zoningType(_ index: Int) -> String { value(table: 251, index: index, fallback: index == 0 ? "Residential" : "Community") }

    /// STR# 131 entries 6–9: confirmations before a lot can be rezoned.
    func rezoneEvictTitle() -> String { value(table: 131, index: 6, fallback: "Are You Sure?") }
    func rezoneEvictMessage() -> String {
        value(table: 131, index: 7, fallback: "The %s family has net worth of %s. You cannot rezone this lot until the family that is living there is evicted. Proceed with the eviction?")
    }
    func rezoneBulldozeTitle() -> String { value(table: 131, index: 8, fallback: "Are you sure?") }
    func rezoneBulldozeMessage() -> String { value(table: 131, index: 9, fallback: "You cannot rezone this lot until it has been bulldozed. Proceed with the bulldoze?") }

    func evictTitle() -> String { value(table: 131, index: 2, fallback: "Evict Family?") }

    func evictMessage() -> String { value(table: 131, index: 3, fallback: "The %s family has net worth of %s.  Do you want to evict them?") }

    func evictFailedMessage() -> String { value(table: 131, index: 11, fallback: "Could not evict!") }

    func nothingToBulldozeTitle() -> String { value(table: 131, index: 4, fallback: "Nothing to Bulldoze") }

    func nothingToBulldozeMessage() -> String { value(table: 131, index: 5, fallback: "There is nothing here to bulldoze.") }

    /// Wardrobe (STR# 220) and pet adoption (STR# 221) carousel text: 0 next, 1 previous, 2 buy, 3 cancel, 4 title.
    func outfitText(pet: Bool, _ index: Int, fallback: String) -> String { value(table: pet ? 221 : 220, index: index, fallback: fallback) }

    func sorryTitle() -> String { value(table: 132, index: 2, fallback: "Sorry") }

    func cannotAffordMessage() -> String { value(table: 132, index: 3, fallback: "You can't afford it.") }

    func moveInErrorTitle() -> String { value(table: 132, index: 18, fallback: "Error!") }

    func moveInErrorMessage() -> String { value(table: 132, index: 19, fallback: "Could not move in!") }

    func communityLotTitle() -> String { value(table: 132, index: 12, fallback: "Community Lot") }

    func communityLotMessage() -> String { value(table: 132, index: 13, fallback: "You cannot move a family into a community lot.") }

    func houseOccupiedTitle() -> String { value(table: 132, index: 14, fallback: "House Occupied") }

    func houseOccupiedMessage() -> String { value(table: 132, index: 15, fallback: "This house is occupied by another family.") }

    func importFamilyTitle() -> String { value(table: 143, index: 8, fallback: "Import Family") }

    func corruptedFileTitle() -> String { value(table: 154, index: 21, fallback: "Corrupted File") }

    func corruptedFileMessage(_ path: String) -> String {
        value(table: 154, index: 22, fallback: "The following file is corrupted: %s").replacingOccurrences(of: "%s", with: path)
    }

    /// Neighborhood lot rollover templates from STR# 134 (NghRollover), with `%s`/`%d` placeholders.
    func neighborhoodRollover(_ index: Int, fallback: String) -> String { value(table: 134, index: index, fallback: fallback) }

    /// Fills `%s` and `%d` placeholders in order, the way the original printf-style templates are used.
    static func format(_ template: String, _ arguments: [String]) -> String {
        var result = ""
        var remaining = arguments[...]
        var index = template.startIndex
        while index < template.endIndex {
            let character = template[index]
            let next = template.index(after: index)
            if character == "%", next < template.endIndex, template[next] == "s" || template[next] == "d" {
                result += remaining.popFirst() ?? ""
                index = template.index(after: next)
            } else {
                result.append(character)
                index = next
            }
        }
        return result
    }

    /// Simoleon amounts as the original UI writes them, e.g. `§20,000`.
    static func simoleons(_ amount: Int) -> String {
        let formatter = NumberFormatter()
        formatter.numberStyle = .decimal
        formatter.groupingSeparator = ","
        formatter.usesGroupingSeparator = true
        return "§" + (formatter.string(from: NSNumber(value: amount)) ?? String(amount))
    }

    func fatalErrorTitle() -> String { value(table: 153, index: 21, fallback: "Fatal Error") }

    func yesButton() -> String {
        value(table: 152, index: 2, fallback: "Yes")
    }

    func cancelButton() -> String {
        value(table: 152, index: 1, fallback: "Cancel")
    }

    func noButton() -> String {
        value(table: 152, index: 3, fallback: "No")
    }

    func okButton() -> String {
        value(table: 152, index: 0, fallback: "OK")
    }

    func saveMenuTitle() -> String {
        value(table: 145, index: 3, fallback: "Save")
    }

    func loadMenuTitle() -> String {
        value(table: 153, index: 19, fallback: "Load")
    }

    func optionString(_ index: Int, fallback: String) -> String { value(table: 145, index: index, fallback: fallback) }

    /// Parses the original "(x;y)" layout strings stored in UIText tables.
    static func point(_ value: String) -> CGPoint? {
        let trimmed = value.trimmingCharacters(in: .whitespaces)
        guard trimmed.hasPrefix("("), trimmed.hasSuffix(")") else { return nil }
        let parts = trimmed.dropFirst().dropLast().split(separator: ";").map { Int($0.trimmingCharacters(in: .whitespaces)) }
        guard parts.count == 2, let x = parts[0], let y = parts[1] else { return nil }
        return CGPoint(x: x, y: y)
    }

    func soundOptionsTitle() -> String { value(table: 145, index: 9, fallback: "Sound Options") }

    func soundEffectVolume() -> String { value(table: 145, index: 45, fallback: "Sound Effects") }

    func soundMusicVolume() -> String { value(table: 145, index: 47, fallback: "Music") }

    func soundVoiceVolume() -> String { value(table: 145, index: 50, fallback: "Vox") }

    func careerSkill(_ name: String) -> String {
        guard let entry = ["Cooking": 7, "Mechanical": 8, "Logic": 9, "Body": 10, "Creativity": 11, "Charisma": 12][name] else { return name }
        let localized = value(table: 160, index: entry, fallback: "+ " + name)
        return String(localized.drop(while: { $0 == "+" || $0.isWhitespace }))
    }

    func careerUnemployed() -> String { value(table: 158, index: 0, fallback: "Unemployed") }

    func careerUnavailable() -> String { value(table: 158, index: 12, fallback: "N/A") }

    func careerSchool() -> String { value(table: 154, index: 16, fallback: "School") }

    func careerJobLabel() -> String { value(table: 166, index: 44, fallback: "Job") }

    func interestsTitle() -> String { value(table: 166, index: 42, fallback: "Interests") }

    func control(_ key: String) -> String {
        return switch key {
        case "familyName": family(12, fallback: "Family name")
        case "addSim": family(0, fallback: "Add Sim")
        case "editSim": family(2, fallback: "Edit selected Sim")
        case "deleteSim": family(1, fallback: "Remove selected Sim")
        case "familyCancel": family(4, fallback: "Cancel family")
        case "familyDone": family(3, fallback: "Done")
        case "simName": sim(26, fallback: "Sim name")
        case "male": sim(3, fallback: "Male")
        case "female": sim(2, fallback: "Female")
        case "adult": sim(0, fallback: "Adult")
        case "child": sim(1, fallback: "Child")
        case "light": sim(6, fallback: "Light skin")
        case "medium": sim(5, fallback: "Medium skin")
        case "dark": sim(4, fallback: "Dark skin")
        case "previousHead": sim(9, fallback: "Previous head")
        case "nextHead": sim(10, fallback: "Next head")
        case "previousBody": sim(7, fallback: "Previous outfit")
        case "nextBody": sim(8, fallback: "Next outfit")
        case "personality": sim(16, fallback: "Personality traits")
        case "biography": sim(24, fallback: "Biography")
        case "simCancel": sim(12, fallback: "Cancel")
        case "simDone": sim(11, fallback: "Done")
        default: key
        }
    }

    private func value(table: UInt16, index: Int, fallback: String) -> String {
        guard let strings = tables[table], strings.indices.contains(index), !strings[index].isEmpty else { return fallback }
        return strings[index]
    }
}

private struct OriginalStringResource {
    let tables: [UInt16: [String]]

    init?(data: Data, languageCode: Int) {
        guard data.count >= 64,
              let header = String(data: data.prefix(60).prefix { $0 != 0 }, encoding: .ascii),
              header.hasPrefix("IFF FILE 2.") else { return nil }
        var position = 64
        var parsed: [UInt16: [[String]]] = [:]
        while position + 76 <= data.count {
            guard let chunkSizeValue = Self.u32BE(data, position + 4),
                  let chunkSize = Int(exactly: chunkSizeValue), chunkSize >= 76,
                  position <= data.count - chunkSize else { return nil }
            let chunkType = String(data: data[position..<(position + 4)], encoding: .ascii)
            let chunkID = Self.u16BE(data, position + 8)
            if chunkType == "STR#", let chunkID, [128, 129, 130, 131, 132, 134, 151, 169, 220, 221, 225, 250, 251, 143, 145, 152, 153, 154, 158, 160, 164, 166].contains(chunkID) {
                let start = position + 76
                let end = position + chunkSize
                guard let languageSets = Self.readStringChunk(data, start: start, end: end) else { return nil }
                parsed[chunkID] = languageSets
            }
            position += chunkSize
        }

        let selectedLanguage = UInt8(clamping: languageCode)
        let languageIndex = (1...20).contains(Int(selectedLanguage)) ? Int(selectedLanguage) - 1 : 0
        var selected: [UInt16: [String]] = [:]
        for (chunkID, languageSets) in parsed {
            let strings = languageSets.indices.contains(languageIndex) ? languageSets[languageIndex] : []
            selected[chunkID] = strings.isEmpty ? (languageSets.first ?? []) : strings
        }
        tables = selected
    }

    private static func readStringChunk(_ data: Data, start: Int, end: Int) -> [[String]]? {
        guard start + 2 <= end, let formatBits = u16LE(data, start) else { return nil }
        let format = Int16(bitPattern: formatBits)
        var position = start + 2
        if position == end { return Array(repeating: [], count: 20) }
        guard position + 2 <= end, let count = u16LE(data, position) else { return nil }
        position += 2
        var languages = Array(repeating: [String](), count: 20)
        switch format {
        case 0:
            for _ in 0..<Int(count) {
                guard let value = readPascalString(data, position: &position, end: end, utf8: false) else { return nil }
                languages[0].append(value)
            }
        case -1:
            for _ in 0..<Int(count) {
                guard let value = readCString(data, position: &position, end: end, utf8: true) else { return nil }
                languages[0].append(value)
            }
        case -2:
            for _ in 0..<Int(count) {
                guard let value = readCString(data, position: &position, end: end, utf8: false),
                      readCString(data, position: &position, end: end, utf8: false) != nil else { return nil }
                languages[0].append(value)
            }
        case -3:
            var languageSets = Array(repeating: [String](), count: 20)
            for _ in 0..<Int(count) {
                guard position < end else { return nil }
                var language = Int(data[position])
                position += 1
                if language == 0 { language = 1 }
                guard let value = readCString(data, position: &position, end: end, utf8: false),
                      readCString(data, position: &position, end: end, utf8: false) != nil else { return nil }
                if (1...20).contains(language) { languageSets[language - 1].append(value) }
            }
            return languageSets
        default:
            return nil
        }
        return languages
    }

    private static func readPascalString(_ data: Data, position: inout Int, end: Int, utf8: Bool) -> String? {
        guard position < end else { return nil }
        let length = Int(data[position])
        position += 1
        guard position <= end - length else { return nil }
        let bytes = data[position..<(position + length)]
        position += length
        return String(data: bytes, encoding: utf8 ? .utf8 : .isoLatin1)
    }

    private static func readCString(_ data: Data, position: inout Int, end: Int, utf8: Bool) -> String? {
        guard position <= end else { return nil }
        let start = position
        while position < end, data[position] != 0 { position += 1 }
        guard position < end else { return nil }
        let bytes = data[start..<position]
        position += 1
        return String(data: bytes, encoding: utf8 ? .utf8 : .isoLatin1)
    }

    private static func u16LE(_ data: Data, _ offset: Int) -> UInt16? {
        guard offset >= 0, offset + 2 <= data.count else { return nil }
        return UInt16(data[offset]) | UInt16(data[offset + 1]) << 8
    }

    private static func u16BE(_ data: Data, _ offset: Int) -> UInt16? {
        guard offset >= 0, offset + 2 <= data.count else { return nil }
        return UInt16(data[offset]) << 8 | UInt16(data[offset + 1])
    }

    private static func u32BE(_ data: Data, _ offset: Int) -> UInt32? {
        guard offset >= 0, offset + 4 <= data.count else { return nil }
        return UInt32(data[offset]) << 24 | UInt32(data[offset + 1]) << 16 | UInt32(data[offset + 2]) << 8 | UInt32(data[offset + 3])
    }
}
