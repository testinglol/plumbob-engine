import Foundation

public struct HouseholdCreationRequest: Codable, Equatable {
    public struct Member: Codable, Equatable {
        public let name: String
        public let bio: String
        public let code: String
        public let skin: String
        public let personality: [Int]
        public let headChoice: String?
        public let bodyChoice: String?

        public init(name: String, bio: String = "", code: String, skin: String, personality: [Int], headChoice: String? = nil, bodyChoice: String? = nil) {
            self.name = name
            self.bio = bio
            self.code = code
            self.skin = skin
            self.personality = personality
            self.headChoice = headChoice
            self.bodyChoice = bodyChoice
        }

        public func validate() throws {
            guard !name.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty, name.utf16.count <= 32,
                  !name.unicodeScalars.contains(where: CharacterSet.controlCharacters.contains),
                  bio.utf16.count <= 512, !bio.unicodeScalars.contains(where: CharacterSet.controlCharacters.contains),
                  code.utf16.count == 5, let gender = code.first, gender == "m" || gender == "f",
                  let age = code.dropFirst().first, age == "a" || age == "c",
                  code.dropFirst(2).allSatisfy({ $0 >= "a" && $0 <= "z" }),
                  ["lgt", "med", "drk"].contains(skin),
                  headChoice.map({ !$0.isEmpty && $0.utf8.count <= 128 && !$0.unicodeScalars.contains(where: CharacterSet.controlCharacters.contains) }) ?? true,
                  bodyChoice.map({ !$0.isEmpty && $0.utf8.count <= 128 && !$0.unicodeScalars.contains(where: CharacterSet.controlCharacters.contains) }) ?? true,
                  personality.count == 5, personality.allSatisfy({ (0...1000).contains($0) && $0.isMultiple(of: 100) }),
                  personality.reduce(0, +) == 2500 else {
                throw ContentError.invalid("Invalid household member data")
            }
        }
    }

    public let familyName: String
    public let members: [Member]

    public init(familyName: String, members: [Member]) {
        self.familyName = familyName
        self.members = members
    }

    public func validate() throws {
        guard !familyName.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty,
              familyName.utf16.count <= 32,
              !familyName.unicodeScalars.contains(where: CharacterSet.controlCharacters.contains),
              (1...8).contains(members.count) else {
            throw ContentError.invalid("Invalid household name or member count")
        }
        for member in members { try member.validate() }
        guard members.contains(where: { $0.code.dropFirst().first == "a" }) else {
            throw ContentError.invalid("A household must contain at least one adult Sim")
        }
    }
}

public struct HouseholdAppearanceCatalog: Codable, Equatable {
    public struct Choice: Codable, Equatable {
        public let id: String
        public let texture: String
        public let bodyType: String

        private enum CodingKeys: String, CodingKey { case id, texture, bodyType }

        public init(id: String, texture: String, bodyType: String = "") {
            self.id = id
            self.texture = texture
            self.bodyType = bodyType
        }

        public init(from decoder: Decoder) throws {
            let values = try decoder.container(keyedBy: CodingKeys.self)
            id = try values.decode(String.self, forKey: .id)
            texture = try values.decode(String.self, forKey: .texture)
            bodyType = try values.decodeIfPresent(String.self, forKey: .bodyType) ?? ""
        }
    }

    public let gender: String
    public let age: String
    public let skin: String
    public let heads: [Choice]
    public let bodies: [Choice]
}
