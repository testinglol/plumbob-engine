import Foundation
import XCTest
@testable import SimsCore

final class BuildObjectTests: XCTestCase {
    func testOriginalToolsUseCanonicalObjectCategoriesAndButtonPositions() {
        let tools: [(OriginalBuildObjectTool, Int, Int)] = [(.door, 8, 8), (.window, 9, 9), (.stairs, 10, 4), (.plants, 11, 6), (.fireplace, 12, 5)]
        for (tool, category, button) in tools {
            XCTAssertEqual(tool.category, category)
            XCTAssertEqual(tool.buttonIndex, button)
            XCTAssertEqual(OriginalBuildObjectTool.catalogTool(category: category), tool)
        }
        XCTAssertNil(OriginalBuildObjectTool.hand.category)
        XCTAssertEqual(OriginalBuildObjectTool.hand.buttonIndex, 11)
        XCTAssertNil(OriginalBuildObjectTool.catalogTool(category: 7))
        XCTAssertNil(OriginalBuildObjectTool.catalogTool(category: 13))
    }

    func testBuildPagesCannotCrossBuyAndPatternCatalogBoundaries() throws {
        for category in 8...12 {
            let item: [String: Any] = ["guid": 0xF1A00001, "name": "Build object", "description": "", "price": 50, "category": category]
            let page = try BuyCatalogTests().decode([item], category: category, total: 1)
            try page.validate(buildObjects: true)
            XCTAssertThrowsError(try page.validate())
        }
        let buy = try BuyCatalogTests().decode([], category: 2, total: 0)
        XCTAssertThrowsError(try buy.validate(buildObjects: true))
        let invalid = try BuyCatalogTests().decode([], category: 13, total: 0)
        XCTAssertThrowsError(try invalid.validate(buildObjects: true))
    }
}
