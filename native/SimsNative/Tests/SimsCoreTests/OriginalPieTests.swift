import Foundation
import XCTest
@testable import SimsCore

final class OriginalPieTests: XCTestCase {
    func testOriginalSpokesOverflowAndViewportEdges() {
        for count in 1...12 {
            let sizes = (0..<count).map { CGSize(width: 40 + $0 * 4, height: 25) }
            let layout = OriginalPieLayout(anchor: CGPoint(x: 300, y: 200), sizes: sizes, viewport: CGSize(width: 800, height: 500))
            for (index, rect) in layout.rectangles.enumerated() {
                XCTAssertEqual(layout.hit(CGPoint(x: rect.midX, y: rect.midY)), index)
            }
            let edge = OriginalPieLayout(anchor: .zero, sizes: sizes, viewport: CGSize(width: 800, height: 500))
            XCTAssertTrue(edge.rectangles.allSatisfy { $0.minX >= 0 && $0.minY >= 0 && $0.maxX <= 800 && $0.maxY <= 500 })
            XCTAssertNil(layout.hit(layout.center))
        }
    }

    func testMenuCategoriesPreserveOriginalCommands() throws {
        let json = """
        [{"name":"Call/Services/Maid","interaction":17,"param0":8,"global":false},
         {"name":"Call/Services/Gardener","interaction":17,"param0":9,"global":false},
         {"name":"View","interaction":2,"param0":-1,"global":true}]
        """
        let entries = try JSONDecoder().decode([SimInteraction].self, from: Data(json.utf8))
        let roots = try OriginalPieNode.build(entries)
        XCTAssertEqual(roots.map(\.label), ["Call", "View"])
        XCTAssertEqual(roots[0].children[0].children.map(\.label), ["Maid", "Gardener"])
        XCTAssertEqual(roots[0].children[0].children[1].action, entries[1])
        XCTAssertEqual(roots[1].action, entries[2])
        let bad = json.replacingOccurrences(of: "Call/Services/Maid", with: "Call//Maid")
        XCTAssertThrowsError(try OriginalPieNode.build(JSONDecoder().decode([SimInteraction].self, from: Data(bad.utf8))))
    }

    func testPluginEntriesJoinTheMenuAndNameTheirPlugin() throws {
        let json = """
        [{"name":"Talk","interaction":3,"param0":0,"global":false},
         {"name":"Allowance/Pay Now","interaction":0,"param0":0,"global":false,"plugin":"local.example-allowance","entry":"pay-now"}]
        """
        let entries = try JSONDecoder().decode([SimInteraction].self, from: Data(json.utf8))
        let roots = try OriginalPieNode.build(entries)
        XCTAssertEqual(roots.map(\.label), ["Talk", "Allowance"])
        XCTAssertEqual(roots[1].children[0].action, entries[1])
        let original = entries[0].interactParameters(objectID: 40)
        XCTAssertNil(original["plugin"])
        XCTAssertEqual(original["interaction"] as? Int, 3)
        let plugin = entries[1].interactParameters(objectID: 41)
        XCTAssertEqual(plugin["plugin"] as? String, "local.example-allowance")
        XCTAssertEqual(plugin["entry"] as? String, "pay-now")
        XCTAssertEqual(plugin["objectID"] as? Int, 41)
    }
}
