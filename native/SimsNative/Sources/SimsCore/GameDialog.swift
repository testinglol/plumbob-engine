import Foundation

public struct GameDialog: Codable, Equatable {
    public let token: String
    public let blocking: Bool
    public let caller: Int
    public let icon: Int
    public let kind: UInt8
    public let title: String
    public let message: String
    public let yes: String?
    public let no: String?
    public let cancel: String?
    public let phoneBook: [PhoneBookFamily]?

    public struct PhoneBookFamily: Codable, Equatable {
        public let familyId: Int
        public let name: String
        public let contacts: [PhoneBookContact]
    }

    public struct PhoneBookContact: Codable, Equatable {
        public let neighborId: Int
        public let name: String
    }

    public static func localFeedback(token: String, title: String, message: String, ok: String = "OK") -> GameDialog {
        localPrompt(token: token, title: title, message: message, kind: 0, yes: ok, no: nil, cancel: nil)
    }

    public static func localPrompt(token: String, title: String, message: String, kind: UInt8,
                                   yes: String?, no: String?, cancel: String?) -> GameDialog {
        GameDialog(token: token, blocking: true, caller: 0, icon: 0, kind: kind,
                   title: title, message: message, yes: yes, no: no, cancel: cancel, phoneBook: nil)
    }

    public struct Button: Equatable {
        public let label: String
        public let code: UInt8
    }

    public var buttons: [Button] {
        switch kind {
        case 0, 3, 4: return [Button(label: yes ?? "OK", code: 0)]
        case 1: return [Button(label: yes ?? "Yes", code: 0), Button(label: no ?? "No", code: 1)]
        case 2: return [Button(label: yes ?? "Yes", code: 0), Button(label: no ?? "No", code: 1), Button(label: cancel ?? "Cancel", code: 2)]
        case 10: return [Button(label: yes ?? "Call", code: 1), Button(label: no ?? "Cancel", code: 0)]
        // Wardrobe (6) and pet choice (9) pickers are not reconstructed. Response code 0 is the original cancel result for
        // both (the engine returns false without a selection), so these dialogs offer only Cancel instead of stalling the lot.
        case 6, 9: return [Button(label: cancel ?? no ?? "Cancel", code: 0)]
        // Spellbook (12), Transform Me (14) and Cookbook (15) also have no picker yet; the engine treats code 0 as acknowledged.
        case 12, 14, 15: return [Button(label: yes ?? "OK", code: 0)]
        default: return []
        }
    }

    public func validate() throws {
        guard !token.isEmpty, token.utf16.count <= 64, title.utf16.count <= 512,
              message.utf16.count <= 8192, buttons.allSatisfy({ $0.label.utf16.count <= 512 }),
              !title.contains("\0"), !message.contains("\0") else { throw ContentError.invalid("Invalid game dialog") }
        if kind == 10 {
            guard let phoneBook, phoneBook.count <= 64 else { throw ContentError.invalid("Invalid phone-book dialog") }
            var neighborIDs = Set<Int>()
            for family in phoneBook {
                guard (1...32767).contains(family.familyId), family.name.utf16.count <= 512,
                      !family.name.contains("\0"), family.contacts.count <= 512 else {
                    throw ContentError.invalid("Invalid phone-book family")
                }
                for contact in family.contacts {
                    guard (1...32767).contains(contact.neighborId), contact.name.utf16.count <= 512,
                          !contact.name.contains("\0"), neighborIDs.insert(contact.neighborId).inserted else {
                        throw ContentError.invalid("Invalid phone-book contact")
                    }
                }
            }
        } else if phoneBook != nil {
            throw ContentError.invalid("Unexpected phone-book dialog data")
        }
    }
}
