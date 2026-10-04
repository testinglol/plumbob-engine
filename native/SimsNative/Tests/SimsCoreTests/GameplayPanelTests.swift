import XCTest
@testable import SimsCore

final class GameplayPanelTests: XCTestCase {
    private func state(selected: Int = 12, file: String? = nil, tokens: [String] = ["1"], personality: [String: Int]? = nil, personType: Int = 0, skills: [String: Int]? = nil, career: [String: Any]? = nil, interests: [Int]? = nil, relationships: [[String: Any]]? = nil) throws -> GameplayPanelState {
        let actions = tokens.map { ["name": "Sit", "token": $0, "active": false, "visible": true, "cancellable": true, "cancelRequested": false] as [String: Any] }
        var sim: [String: Any] = ["id": 12, "name": "Mortimer", "household": true, "mood": 25, "motives": ["Hunger": 100, "Energy": -100], "actions": actions]
        if let file { sim["portrait"] = ["file": file, "columns": 3, "rows": 1] }
        if let personality { sim["personality"] = personality; sim["personType"] = personType; sim["zodiac"] = 4 }
        if let skills { sim["skills"] = skills; sim["personType"] = personType }
        if let career { sim["career"] = career }
        if let interests { sim["interests"] = interests; sim["personType"] = personType }
        if let relationships { sim["relationships"] = relationships }
        let npc: [String: Any] = ["id": 13, "name": "Visitor", "household": false, "mood": 0, "motives": [:], "actions": []]
        let data = try JSONSerialization.data(withJSONObject: ["selectedSim": selected, "hours": 6, "minutes": 7, "budget": 1000, "sims": [sim, npc]])
        return try JSONDecoder().decode(GameplayPanelState.self, from: data)
    }

    func testHouseholdSelectionRejectsAnNPC() throws {
        let valid = try state()
        try valid.validate()
        XCTAssertEqual(valid.household.map(\.id), [12])
        XCTAssertEqual(valid.selected?.name, "Mortimer")
        XCTAssertThrowsError(try state(selected: 13).validate())
    }

    func testResourceReferencesAndActionIdentitiesAreBounded() throws {
        try state(file: "ui-" + String(repeating: "a", count: 64) + ".bmp").validate()
        XCTAssertThrowsError(try state(file: "../portrait.bmp").validate())
        XCTAssertThrowsError(try state(file: "ui-" + String(repeating: "z", count: 64) + ".bmp").validate())
        XCTAssertThrowsError(try state(tokens: ["1", "1"]).validate())
    }

    func testMotiveExtremesMatchOriginalBarRange() {
        XCTAssertEqual(OriginalGameplayLayout.barWidth(-32768), 0)
        XCTAssertEqual(OriginalGameplayLayout.barWidth(0), 30)
        XCTAssertEqual(OriginalGameplayLayout.barWidth(32767), 60)
        XCTAssertEqual(OriginalGameplayLayout.barColors(100).green, SIMD3(0, 202, 57))
        XCTAssertEqual(OriginalGameplayLayout.barColors(-100).red, SIMD3(209, 0, 0))
    }

    func testPersonalityDataRequiresAllFiveTraitsAndPreservesRawValues() throws {
        let traits = ["Neat": 299, "Outgoing": 600, "Active": 400, "Playful": 200, "Nice": 500]
        let panel = try state(personality: traits)
        try panel.validate()
        XCTAssertTrue(panel.selected?.hasHumanPersonality == true)
        XCTAssertEqual(panel.selected?.personality?["Neat"], 299)
        XCTAssertEqual(OriginalGameplayLayout.personalityWidth(299), 8)
        XCTAssertEqual(OriginalGameplayLayout.personalityWidth(-100), 0)
        XCTAssertEqual(OriginalGameplayLayout.personalityWidth(32767), 40)
        XCTAssertFalse(try state().selected?.hasHumanPersonality == true)
        XCTAssertFalse(try state(personality: traits, personType: 2).selected?.hasHumanPersonality == true)
        XCTAssertThrowsError(try state(personality: ["Neat": 500]).validate())
        XCTAssertThrowsError(try state(personality: traits.merging(["Nice": 32768]) { _, new in new }).validate())
    }

    func testUnsetZodiacUsesOriginalProfilesAndStoredSignsTakePrecedence() {
        let aries = ["Outgoing": 800, "Nice": 300, "Playful": 300, "Neat": 500, "Active": 600]
        let libra = ["Outgoing": 800, "Nice": 700, "Playful": 600, "Neat": 200, "Active": 200]
        XCTAssertEqual(OriginalGameplayLayout.zodiac(personality: aries, stored: 0), 1)
        XCTAssertEqual(OriginalGameplayLayout.zodiac(personality: libra, stored: 0), 7)
        XCTAssertEqual(OriginalGameplayLayout.zodiac(personality: aries, stored: 12), 12)
        XCTAssertEqual(OriginalGameplayLayout.zodiac(personality: aries, stored: -1), 1)
        XCTAssertEqual(OriginalGameplayLayout.zodiac(personality: aries, stored: 13), 12)
    }

    func testCareerPreservesRawSkillsAndRejectsIncompleteOrUnboundedData() throws {
        let skills = Dictionary(uniqueKeysWithValues: OriginalGameplayLayout.skills.map { ($0, 299) })
        let career: [String: Any] = ["type": 9, "level": 0, "performance": -30, "age": 27, "atWorkSchool": 0, "title": "Test Subject", "salary": 155, "startHour": 9, "endHour": 15]
        let panel = try state(skills: skills, career: career)
        try panel.validate()
        XCTAssertTrue(panel.selected?.hasHumanCareer == true)
        XCTAssertEqual(panel.selected?.skills?["Cooking"], 299)
        XCTAssertFalse(try state(personType: 2, skills: skills, career: career).selected?.hasHumanCareer == true)
        XCTAssertThrowsError(try state(skills: ["Cooking": 100], career: career).validate())
        XCTAssertThrowsError(try state(skills: skills.merging(["Body": 32768]) { _, value in value }, career: career).validate())
        XCTAssertThrowsError(try state(skills: skills, career: career.merging(["startHour": 25]) { _, value in value }).validate())
        XCTAssertThrowsError(try state(skills: skills, career: career.merging(["nextLevelRequirements": [100]]) { _, value in value }).validate())
    }

    func testCareerMarkersUseNextLevelAndDisappearWhenRequirementsAreMet() throws {
        let skills = Dictionary(uniqueKeysWithValues: OriginalGameplayLayout.skills.map { ($0, 299) })
        let data: [String: Any] = ["type": 9, "level": 0, "performance": 0, "age": 27, "atWorkSchool": 0, "title": "Test Subject", "familyFriends": 2, "currentLevelRequirements": Array(repeating: 0, count: 10), "nextLevelRequirements": [3, 300, 400, 200, 0, 0, 1000, 0, 0, 0]]
        let career = try XCTUnwrap(state(skills: skills, career: data).selected?.career)
        try career.validate()
        XCTAssertEqual(OriginalGameplayLayout.requiredSkillWidth(0, value: 299, career: career), 12)
        XCTAssertNil(OriginalGameplayLayout.requiredSkillWidth(0, value: 300, career: career))
        XCTAssertEqual(OriginalGameplayLayout.requiredSkillWidth(1, value: 0, career: career), 16)
        XCTAssertNil(OriginalGameplayLayout.requiredSkillWidth(2, value: 299, career: career))
        XCTAssertNil(OriginalGameplayLayout.requiredSkillWidth(6, value: 0, career: career))
        XCTAssertEqual(career.friendsNeeded, 3)
        let enough = try XCTUnwrap(state(skills: skills, career: data.merging(["familyFriends": 3]) { _, value in value }).selected?.career)
        XCTAssertNil(enough.friendsNeeded)
    }

    func testSchoolAndUnemploymentHaveDistinctDisplayStates() throws {
        let skills = Dictionary(uniqueKeysWithValues: OriginalGameplayLayout.skills.map { ($0, 0) })
        let data: [String: Any] = ["type": 0, "level": 4, "performance": 0, "age": 9, "atWorkSchool": 0]
        let school = try XCTUnwrap(state(skills: skills, career: data).selected?.career)
        XCTAssertTrue(school.isSchool)
        XCTAssertTrue(school.hasJob)
        let adult = try XCTUnwrap(state(skills: skills, career: data.merging(["age": 27]) { _, value in value }).selected?.career)
        XCTAssertFalse(adult.isSchool)
        XCTAssertFalse(adult.hasJob)
        XCTAssertFalse(try state().selected?.hasHumanCareer == true)
    }

    func testOffLotRelationshipsUseNeighborIdentitiesAndPreserveExtensionValues() throws {
        let relationship: [String: Any] = ["neighborID": 300, "guid": UInt32.max, "name": "Off lot", "household": false, "values": [37, 12, -24, 32767, -32768]]
        let panel = try state(relationships: [relationship])
        try panel.validate()
        let decoded = try XCTUnwrap(panel.selected?.relationships?.first)
        XCTAssertEqual(decoded.neighborID, 300)
        XCTAssertEqual(decoded.daily, 37)
        XCTAssertEqual(decoded.lifetime, -24)
        XCTAssertEqual(decoded.values, [37, 12, -24, 32767, -32768])
        XCTAssertThrowsError(try state(relationships: [relationship, relationship]).validate())
        XCTAssertThrowsError(try state(relationships: [relationship.merging(["values": [32768]]) { _, value in value }]).validate())
        let empty = try state(relationships: [relationship.merging(["values": []]) { _, value in value }])
        try empty.validate()
        XCTAssertEqual(empty.selected?.relationships?.first?.daily, 0)
        XCTAssertEqual(empty.selected?.relationships?.first?.lifetime, 0)
    }

    func testInterestTopicsFollowOriginalAgeBoundaryAndKeepRawValues() throws {
        let child = OriginalGameplayLayout.interestIndices(age: 17).map { OriginalGameplayLayout.interests[$0] }
        XCTAssertEqual(child, ["Toys", "Aliens", "Pets", "School", "Weather", "Sports", "Music", "Outdoors"])
        let adult = OriginalGameplayLayout.interestIndices(age: 18).map { OriginalGameplayLayout.interests[$0] }
        XCTAssertEqual(adult.count, 15)
        XCTAssertTrue(adult.contains("Romance"))
        XCTAssertFalse(adult.contains("School"))
        XCTAssertEqual(OriginalGameplayLayout.interestIndices(age: 0), OriginalGameplayLayout.interestIndices(age: 18))
        let career: [String: Any] = ["type": 0, "level": 0, "performance": 0, "age": 27, "atWorkSchool": 0]
        let raw = Array(repeating: 299, count: 19)
        let valid = try state(career: career, interests: raw)
        try valid.validate()
        XCTAssertEqual(valid.selected?.interests, raw)
        XCTAssertTrue(valid.selected?.hasHumanInterests == true)
        XCTAssertThrowsError(try state(career: career, interests: Array(raw.prefix(18))).validate())
        XCTAssertThrowsError(try state(career: career, interests: Array(repeating: 32768, count: 19)).validate())
        XCTAssertFalse(try state(personType: 2, career: career, interests: raw).selected?.hasHumanInterests == true)
    }

    func testOriginalRelationshipFlagsRequireMutualFriendshipAndKeepRomanceSeparate() throws {
        func relationship(_ id: Int, _ daily: Int, _ reverse: Int, _ flags: [Int], household: Bool = false, famous: Bool = false) throws -> GameplayPanelState.Relationship {
            let entry: [String: Any] = ["neighborID": id, "guid": id, "name": "Neighbor", "household": household, "famous": famous,
                                        "reverseDaily": reverse, "values": [daily, flags[0], -24, flags[1]]]
            return try XCTUnwrap(state(relationships: [entry]).selected?.relationships?.first)
        }
        let oneWay = try relationship(300, 100, 24, [0, 0])
        let mutual = try relationship(301, 25, 25, [1, 0], household: true)
        let love = try relationship(302, -100, 100, [0, 1], famous: true)
        XCTAssertFalse(oneWay.friend)
        XCTAssertTrue(mutual.friend)
        XCTAssertTrue(mutual.crush)
        XCTAssertFalse(mutual.love)
        XCTAssertTrue(love.love)
        let values = [love, mutual, oneWay]
        XCTAssertEqual(OriginalGameplayLayout.relationships(values, filter: .all).map(\.neighborID), [300, 301, 302])
        XCTAssertEqual(OriginalGameplayLayout.relationships(values, filter: .family).map(\.neighborID), [301])
        XCTAssertEqual(OriginalGameplayLayout.relationships(values, filter: .friends).map(\.neighborID), [301])
        XCTAssertEqual(OriginalGameplayLayout.relationships(values, filter: .famous).map(\.neighborID), [302])
        XCTAssertEqual([-32768, -100, 0, 100, 32767].map(OriginalGameplayLayout.relationshipWidth), [0, 0, 20, 40, 40])
        XCTAssertEqual([-100, -60, -20, 20, 60, 100].map(OriginalGameplayLayout.relationshipExpression), [0, 1, 2, 3, 4, 4])
    }

    func testPanelCapacityTracksWidthAndKeepsTheVisibleItemWhenResizing() {
        let standard = OriginalGameplayLayout.PanelGrid(width: 800)
        let originalWide = OriginalGameplayLayout.PanelGrid(width: 1024)
        let modernWide = OriginalGameplayLayout.PanelGrid(width: 1200)
        XCTAssertEqual([standard, originalWide, modernWide].map(\.relationshipCapacity), [5, 10, 14])
        XCTAssertEqual([standard, originalWide, modernWide].map(\.interestColumns), [2, 3, 5])
        for grid in [standard, originalWide, modernWide] {
            XCTAssertLessThanOrEqual(grid.interest(grid.interestCapacity - 1).maxX, grid.interestArrow(true).minX)
            XCTAssertLessThanOrEqual(OriginalGameplayLayout.relationship(grid.relationshipCapacity - 1).maxX, grid.relationshipArrow(true).minX)
        }
        XCTAssertEqual(standard.interest(3).minX - standard.interest(0).minX, 128)
        XCTAssertEqual(standard.interest(2).minY - standard.interest(0).minY, 54)
        XCTAssertEqual(originalWide.resizedPage(2, oldCapacity: 5, newCapacity: 10, items: 21), 1)
        XCTAssertEqual(standard.resizedPage(1, oldCapacity: 10, newCapacity: 5, items: 21), 2)
        XCTAssertEqual(standard.resizedPage(10, oldCapacity: 5, newCapacity: 5, items: 0), 0)
        XCTAssertEqual(OriginalGameplayLayout.PanelGrid(width: .nan), standard)
    }
}
