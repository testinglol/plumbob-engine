import Foundation
import XCTest
@testable import SimsCore

final class HouseholdCreationTests: XCTestCase {
    private func member(code: String = "mafit", skin: String = "lgt", personality: [Int] = [500, 500, 500, 500, 500]) -> HouseholdCreationRequest.Member {
        HouseholdCreationRequest.Member(name: "Alex", code: code, skin: skin, personality: personality)
    }

    func testValidRequestEncodesSimulationProtocolFields() throws {
        let selected = HouseholdCreationRequest.Member(name: "Alex", code: "mafat", skin: "lgt", personality: [500, 500, 500, 500, 500], headChoice: "hula01", bodyChoice: "bafa01")
        let request = HouseholdCreationRequest(familyName: "New House", members: [selected, member(code: "mcfit", skin: "med")])
        try request.validate()
        let data = try JSONEncoder().encode(request)
        let object = try XCTUnwrap(JSONSerialization.jsonObject(with: data) as? [String: Any])
        XCTAssertEqual(object["familyName"] as? String, "New House")
        XCTAssertEqual((object["members"] as? [[String: Any]])?.count, 2)
        XCTAssertEqual((object["members"] as? [[String: Any]])?.first?["headChoice"] as? String, "hula01")
        XCTAssertEqual((object["members"] as? [[String: Any]])?.first?["bodyChoice"] as? String, "bafa01")
    }

    func testDecodesInstalledAppearanceCatalog() throws {
        let data = Data("""
        {"gender":"m","age":"adult","skin":"lgt","heads":[{"id":"hula01","texture":"hula01lgt"}],"bodies":[{"id":"bafa01_fit","texture":"bafa01lgt","bodyType":"fat"}]}
        """.utf8)
        let catalog = try JSONDecoder().decode(HouseholdAppearanceCatalog.self, from: data)
        XCTAssertEqual(catalog.gender, "m")
        XCTAssertEqual(catalog.heads.first?.id, "hula01")
        XCTAssertEqual(catalog.bodies.first?.bodyType, "fat")
    }

    func testRequiresAdultAndTwentyFiveDistributedPersonalityPoints() {
        XCTAssertThrowsError(try HouseholdCreationRequest(familyName: "Kids", members: [member(code: "mcfit")]).validate())
        XCTAssertThrowsError(try member(personality: [600, 500, 500, 500, 500]).validate())
        XCTAssertThrowsError(try member(personality: [500, 500, 500, 500, 400]).validate())
    }

    func testRejectsInvalidAppearanceAndText() {
        XCTAssertThrowsError(try member(code: "m?fit").validate())
        XCTAssertThrowsError(try member(skin: "tan").validate())
        XCTAssertThrowsError(try HouseholdCreationRequest.Member(name: "Alex", code: "mafit", skin: "lgt", personality: [500, 500, 500, 500, 500], headChoice: "bad\nid").validate())
        XCTAssertThrowsError(try HouseholdCreationRequest(familyName: "\n", members: [member()]).validate())
    }
}
