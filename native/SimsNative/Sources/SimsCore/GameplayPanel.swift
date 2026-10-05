import Foundation
#if canImport(CoreGraphics)
import CoreGraphics
#endif

public struct GameplayPanelState: Decodable {
    public struct Career: Decodable {
        public let type: Int
        public let level: Int
        public let performance: Int
        public let age: Int
        public let atWorkSchool: Int
        public let school: Bool?
        public let track: String?
        public let title: String?
        public let salary: Int?
        public let startHour: Int?
        public let endHour: Int?
        public let currentLevelRequirements: [Int]?
        public let nextLevelRequirements: [Int]?
        public let performanceLabel: String?
        public let familyFriends: Int?

        public var isSchool: Bool { school ?? (age < 18) }
        public var hasJob: Bool { isSchool || type != 0 && title?.isEmpty == false }
        public var friendsNeeded: Int? {
            guard let required = nextLevelRequirements?.first, required > (familyFriends ?? 0) else { return nil }
            return required
        }
        public func validate() throws {
            guard [type, level, performance, age, atWorkSchool].allSatisfy({ (-32768...32767).contains($0) }),
                  [track, title, performanceLabel].compactMap({ $0 }).allSatisfy({ $0.utf16.count <= 512 }),
                  [salary, familyFriends].compactMap({ $0 }).allSatisfy({ (0...Int(Int32.max)).contains($0) }),
                  [startHour, endHour].compactMap({ $0 }).allSatisfy({ (0...24).contains($0) }) else { throw ContentError.invalid("Invalid career data") }
            for requirements in [currentLevelRequirements, nextLevelRequirements].compactMap({ $0 }) {
                guard requirements.count == 10, requirements.allSatisfy({ (Int(Int32.min)...Int(Int32.max)).contains($0) }) else { throw ContentError.invalid("Invalid career requirements") }
            }
        }
    }
    public struct Image: Decodable {
        public let file: String
        public let columns: Int
        public let rows: Int

        public func validate() throws {
            guard file.hasPrefix("ui-"), file.hasSuffix(".bmp"), file.count == 71,
                  file.dropFirst(3).dropLast(4).allSatisfy({ $0.isHexDigit && !$0.isUppercase }),
                  (1...5).contains(columns), (1...4).contains(rows) else { throw ContentError.invalid("Invalid gameplay image") }
        }
    }
    public struct Relationship: Decodable {
        public let neighborID: Int
        public let guid: UInt32
        public let name: String
        public let values: [Int]
        public let household: Bool
        public let portrait: Image?
        public let reverseDaily: Int?
        public let famous: Bool?
        /// Mutual friendship as the simulation decides it, with the friendship_threshold loaded from the game's constants.
        public let mutualFriend: Bool?
        public var daily: Int { values.first ?? 0 }
        public var lifetime: Int { values.count > 2 ? values[2] : 0 }
        public var friend: Bool { mutualFriend ?? (daily >= 50 && (reverseDaily ?? 0) >= 50) }
        public var crush: Bool { values.count > 1 && values[1] != 0 }
        public var love: Bool { values.count > 3 && values[3] != 0 }

        public func validate() throws {
            guard (1...32767).contains(neighborID), name.utf16.count <= 512, values.count <= 1024,
                  values.allSatisfy({ (-32768...32767).contains($0) }),
                  reverseDaily == nil || (-32768...32767).contains(reverseDaily!) else { throw ContentError.invalid("Invalid relationship data") }
            try portrait?.validate()
        }
    }
    public struct Action: Decodable {
        public let name: String?
        public let token: String
        public let active: Bool
        public let visible: Bool
        public let cancellable: Bool
        public let cancelRequested: Bool
        public let icon: Image?
    }
    public struct Sim: Decodable {
        public let id: Int
        public let name: String
        public let household: Bool
        public let portrait: Image?
        public let pieHead: Image?
        public let mood: Int
        public let motives: [String: Int]
        public let actions: [Action]
        public let personality: [String: Int]?
        public let personType: Int?
        public let zodiac: Int?
        public let skills: [String: Int]?
        public let career: Career?
        public let interests: [Int]?
        public let relationships: [Relationship]?
        public var hasHumanInterests: Bool {
            interests?.count == OriginalGameplayLayout.interests.count && (0...1).contains(personType ?? -1) && career != nil
        }
        public var hasHumanCareer: Bool {
            guard let skills, let career, let personType else { return false }
            return (0...1).contains(personType) && Set(skills.keys) == Set(OriginalGameplayLayout.skills) && career.age >= 0
        }
        public var hasHumanPersonality: Bool {
            guard let personality, let personType else { return false }
            return (0...1).contains(personType) && Set(personality.keys) == Set(OriginalGameplayLayout.traits)
        }
    }
    public let selectedSim: Int
    public let hours: Int
    public let minutes: Int
    public let budget: Int?
    public let sims: [Sim]
    public let canUndo: Bool?
    public let canRedo: Bool?
    public var household: [Sim] { sims.filter(\.household) }
    public var selected: Sim? { household.first { $0.id == selectedSim } }

    public func validate() throws {
        guard sims.count <= 128, household.count <= 8, Set(sims.map(\.id)).count == sims.count,
              (0..<24).contains(hours), (0..<60).contains(minutes),
              selectedSim == 0 || selected != nil else { throw ContentError.invalid("Invalid gameplay panel state") }
        for sim in sims {
            guard (1...32767).contains(sim.id), sim.name.utf16.count <= 512, sim.actions.count <= 128,
                  Set(sim.actions.map(\.token)).count == sim.actions.count,
                  sim.motives.count <= 16, sim.motives.values.allSatisfy({ (-32768...32767).contains($0) }) else { throw ContentError.invalid("Invalid Sim panel state") }
            try sim.portrait?.validate()
            try sim.pieHead?.validate()
            try sim.career?.validate()
            if let relationships = sim.relationships {
                guard relationships.count <= 32767,
                      Set(relationships.map(\.neighborID)).count == relationships.count else { throw ContentError.invalid("Invalid relationship identities") }
                for relationship in relationships { try relationship.validate() }
            }
            if let interests = sim.interests {
                guard interests.count == OriginalGameplayLayout.interests.count,
                      interests.allSatisfy({ (-32768...32767).contains($0) }) else { throw ContentError.invalid("Invalid interest data") }
            }
            if let skills = sim.skills {
                guard Set(skills.keys) == Set(OriginalGameplayLayout.skills),
                      skills.values.allSatisfy({ (-32768...32767).contains($0) }) else { throw ContentError.invalid("Invalid skill data") }
            }
            if let personality = sim.personality {
                guard Set(personality.keys) == Set(OriginalGameplayLayout.traits),
                      personality.values.allSatisfy({ (-32768...32767).contains($0) }) else { throw ContentError.invalid("Invalid personality data") }
            }
            guard [sim.personType, sim.zodiac].compactMap({ $0 }).allSatisfy({ (-32768...32767).contains($0) }) else { throw ContentError.invalid("Invalid Sim type or zodiac") }
            for action in sim.actions {
                guard !action.token.isEmpty, action.token.utf16.count <= 64,
                      (action.name?.utf16.count ?? 0) <= 512 else { throw ContentError.invalid("Invalid queued action") }
                try action.icon?.validate()
            }
        }
    }
}

public enum OriginalGameplayLayout {
    public struct PanelGrid: Equatable {
        public let width: CGFloat
        public let relationshipCapacity: Int
        public let interestColumns: Int
        public var interestCapacity: Int { interestColumns * 3 }
        public init(width: CGFloat) {
            self.width = width.isFinite ? max(800, min(16384, width.rounded(.down))) : 800
            relationshipCapacity = max(1, Int((self.width - 566) / 45))
            interestColumns = max(1, Int((self.width - 544) / 128))
        }
        public func interest(_ index: Int) -> CGRect {
            CGRect(x: 533 + index / 3 * 128, y: 68 + index % 3 * 27, width: 125, height: 25)
        }
        public func relationshipArrow(_ next: Bool) -> CGRect {
            CGRect(x: next ? width - 11 : 544, y: 82, width: 9, height: 49)
        }
        public func interestArrow(_ next: Bool) -> CGRect {
            CGRect(x: next ? width - 11 : 522, y: 83, width: 9, height: 49)
        }
        public func pageCount(items: Int, capacity: Int) -> Int { max(1, (max(0, items) + capacity - 1) / capacity) }
        public func resizedPage(_ page: Int, oldCapacity: Int, newCapacity: Int, items: Int) -> Int {
            min(max(0, page) * oldCapacity / newCapacity, pageCount(items: items, capacity: newCapacity) - 1)
        }
    }
    public enum RelationshipFilter: String, CaseIterable {
        case family, friends, famous, all
    }
    public static func relationships(_ values: [GameplayPanelState.Relationship], filter: RelationshipFilter) -> [GameplayPanelState.Relationship] {
        values.filter { value in
            guard !value.values.isEmpty else { return false }
            switch filter {
            case .family: return value.household
            case .friends: return value.friend
            case .famous: return value.famous == true
            case .all: return true
            }
        }.sorted { $0.daily == $1.daily ? $0.neighborID < $1.neighborID : $0.daily > $1.daily }
    }
    public static func relationship(_ index: Int) -> CGRect { CGRect(x: 555 + index * 45, y: 68, width: 45, height: 90) }
    public static func relationshipFilter(_ index: Int) -> CGRect { CGRect(x: index == 0 ? 523 : 522, y: 64 + index * 21, width: 20, height: 20) }
    public static func relationshipWidth(_ value: Int) -> Int { (min(100, max(-100, value)) + 100) / 5 }
    public static func relationshipExpression(_ value: Int) -> Int { min(4, max(0, (value + 100) / 40)) }
    public static let interests = ["Travel", "Violence", "Politics", "The60s", "Weather", "Sports", "Music", "Outdoors", "Toys", "Aliens", "Pets", "School", "Exercise", "Food", "Parties", "Style", "Charisma", "Health", "Romance"]
    public static func interestIndices(age: Int) -> [Int] { age > 0 && age < 18 ? [8, 9, 10, 11, 4, 5, 6, 7] : Array(0..<8) + Array(12..<19) }
    public static let skills = ["Cooking", "Mechanical", "Charisma", "Body", "Logic", "Creativity"]
    public static func skillBar(_ index: Int) -> CGRect { CGRect(x: 677, y: 57 + index * 15, width: 40, height: 11) }
    public static func skillLabel(_ index: Int) -> CGRect { CGRect(x: 613, y: 56 + index * 15, width: 62, height: 16) }
    public static func requiredSkillWidth(_ index: Int, value: Int, career: GameplayPanelState.Career) -> Int? {
        guard let requirements = career.nextLevelRequirements, requirements.count == 10,
              skills.indices.contains(index), requirements[index + 1] > value else { return nil }
        return personalityWidth(requirements[index + 1])
    }
    public static let traits = ["Neat", "Outgoing", "Active", "Playful", "Nice"]
    public static let signs = ["Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"]
    private static let zodiacTraitOrder = ["Outgoing", "Nice", "Playful", "Neat", "Active"]
    private static let zodiacProfiles: [[Float]] = [
        [8, 3, 3, 5, 6], [5, 4, 8, 5, 3], [7, 3, 3, 4, 8], [3, 6, 4, 6, 6],
        [10, 3, 4, 4, 4], [2, 5, 3, 9, 6], [8, 7, 6, 2, 2], [5, 3, 3, 6, 8],
        [3, 4, 7, 2, 9], [4, 5, 8, 7, 1], [4, 6, 7, 4, 4], [3, 7, 3, 5, 7]
    ]
    public static func zodiac(personality: [String: Int], stored: Int) -> Int {
        if stored != 0 { return min(12, max(1, stored)) }
        let values = zodiacTraitOrder.map { Float(personality[$0] ?? 0) * Float(0.009999999776482582) }
        var nearest = 1
        var distance = Float(1e38)
        for (index, profile) in zodiacProfiles.enumerated() {
            let squared = zip(values, profile).reduce(Float(0)) { sum, pair in
                let delta = pair.0 - pair.1
                return sum + delta * delta
            }
            if squared < distance { nearest = index + 1; distance = squared }
        }
        return nearest
    }
    public static func personalityWidth(_ value: Int) -> Int { min(10, max(0, value / 100)) * 4 }
    public static func personality(_ index: Int, labelWidth: Int) -> CGRect {
        CGRect(x: 520 + 202 - (labelWidth + 49), y: 58 + index * 18, width: labelWidth + 49, height: 14)
    }
    public static let motives = ["Hunger", "Energy", "Comfort", "Fun", "Hygiene", "Social", "Bladder", "Room"]
    public static func portrait(_ index: Int) -> CGRect {
        CGRect(x: 229 + (index % 4) * 45, y: 55 + (index / 4) * 45, width: 45, height: 45)
    }
    public static func need(_ index: Int) -> CGRect {
        CGRect(x: 520 + (index % 2) * 100, y: 71 + (index / 2) * 19, width: 100, height: 20)
    }
    public static func action(_ index: Int) -> CGRect { CGRect(x: 10 + index * 48, y: 10, width: 45, height: 45) }
    public static func barWidth(_ value: Int) -> Int { Int(Double(min(100, max(-100, value)) + 100) * 0.3) }
    public static func barColors(_ value: Int) -> (green: SIMD3<UInt8>, red: SIMD3<UInt8>) {
        let factor = min(1, max(0, Double(value + 50) * 0.01))
        let gray = SIMD3<Double>(64, 93, 95)
        func mix(_ target: SIMD3<Double>, _ weight: Double) -> SIMD3<UInt8> {
            let result = gray + (target - gray) * weight
            return SIMD3(UInt8(result.x), UInt8(result.y), UInt8(result.z))
        }
        return (mix(SIMD3(0, 202, 57), factor), mix(SIMD3(209, 0, 0), 1 - factor))
    }
}
