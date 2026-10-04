import Foundation
import XCTest
@testable import SimsCore

final class PanelDescriptionTests: XCTestCase {
    func panel(_ elements: String, frame: String = #"{"x":100,"y":100,"width":300,"height":220}"#, extra: String = "") throws -> PanelDescription {
        let json = #"{"schemaVersion":1,"id":"status","title":"Status","frame":\#(frame),"elements":[\#(elements)]\#(extra)}"#
        return try JSONDecoder().decode(PanelDescription.self, from: Data(json.utf8))
    }

    func testValidPanelWithEveryElementKindPasses() throws {
        let description = try panel("""
        {"id":"title","kind":"label","frame":{"x":10,"y":40,"width":200,"height":20},"text":"Hello"},
        {"id":"meter","kind":"meter","frame":{"x":10,"y":70,"width":200,"height":14},"binding":"funds","minimum":0,"maximum":100},
        {"id":"go","kind":"button","frame":{"x":10,"y":100,"width":100,"height":30},"text":"Go","action":"go"},
        {"id":"rows","kind":"list","frame":{"x":10,"y":132,"width":200,"height":40},"binding":"rows"},
        {"id":"art","kind":"image","frame":{"x":220,"y":40,"width":40,"height":40},"resource":"UIGraphics/cpanel/Buttons/optslideroff.bmp"}
        """)
        XCTAssertNoThrow(try description.validate())
    }

    func testElementsMustStayInsideTheContentArea() throws {
        // The first 36 points belong to the title band and the last 44 to the close band.
        XCTAssertThrowsError(try panel(#"{"id":"a","kind":"label","frame":{"x":0,"y":0,"width":50,"height":20},"text":"x"}"#).validate())
        XCTAssertThrowsError(try panel(#"{"id":"a","kind":"label","frame":{"x":0,"y":190,"width":50,"height":20},"text":"x"}"#).validate())
        XCTAssertThrowsError(try panel(#"{"id":"a","kind":"label","frame":{"x":280,"y":40,"width":50,"height":20},"text":"x"}"#).validate())
        XCTAssertNoThrow(try panel(#"{"id":"a","kind":"label","frame":{"x":0,"y":36,"width":300,"height":140},"text":"x"}"#).validate())
    }

    func testPanelMustFitTheLogicalInterface() throws {
        XCTAssertThrowsError(try panel("", frame: #"{"x":600,"y":100,"width":300,"height":220}"#).validate())
        XCTAssertThrowsError(try panel("", frame: #"{"x":100,"y":100,"width":100,"height":220}"#).validate())
    }

    func testRejectsBadIdentifiersDuplicatesAndMissingFields() throws {
        let label = #"{"id":"a","kind":"label","frame":{"x":0,"y":40,"width":50,"height":20},"text":"x"}"#
        XCTAssertThrowsError(try panel(label + "," + label).validate())
        XCTAssertThrowsError(try panel(#"{"id":"Upper","kind":"label","frame":{"x":0,"y":40,"width":50,"height":20},"text":"x"}"#).validate())
        XCTAssertThrowsError(try panel(#"{"id":"a","kind":"button","frame":{"x":0,"y":40,"width":50,"height":20},"text":"x"}"#).validate())
        XCTAssertThrowsError(try panel(#"{"id":"a","kind":"label","frame":{"x":0,"y":40,"width":50,"height":20}}"#).validate())
        XCTAssertThrowsError(try panel(#"{"id":"a","kind":"meter","frame":{"x":0,"y":40,"width":50,"height":10},"binding":"b","minimum":5,"maximum":5}"#).validate())
        XCTAssertThrowsError(try panel(#"{"id":"a","kind":"image","frame":{"x":0,"y":40,"width":50,"height":20},"resource":"GameData/Objects/x.bmp"}"#).validate())
        XCTAssertThrowsError(try panel(#"{"id":"a","kind":"image","frame":{"x":0,"y":40,"width":50,"height":20},"resource":"UIGraphics/../x.bmp"}"#).validate())
    }

    func testRejectsUnsupportedSchemaVersionAndTooManyElements() throws {
        let json = #"{"schemaVersion":2,"id":"status","title":"Status","frame":{"x":100,"y":100,"width":300,"height":220},"elements":[]}"#
        XCTAssertThrowsError(try JSONDecoder().decode(PanelDescription.self, from: Data(json.utf8)).validate())
        let many = (0..<65).map { #"{"id":"e\#($0)","kind":"label","frame":{"x":0,"y":40,"width":10,"height":10},"text":"x"}"# }.joined(separator: ",")
        XCTAssertThrowsError(try panel(many).validate())
    }

    func testBindingsAndMeterFractionsClamp() throws {
        let description = try panel(#"{"id":"m","kind":"meter","frame":{"x":0,"y":40,"width":100,"height":10},"binding":"funds","minimum":0,"maximum":200},{"id":"l","kind":"label","frame":{"x":0,"y":60,"width":100,"height":10},"text":"fallback","binding":"name"}"#)
        let meter = description.elements[0], label = description.elements[1]
        XCTAssertEqual(description.meterFraction(for: meter, values: ["funds": "50"]), 0.25)
        XCTAssertEqual(description.meterFraction(for: meter, values: ["funds": "9999"]), 1)
        XCTAssertEqual(description.meterFraction(for: meter, values: ["funds": "-5"]), 0)
        XCTAssertNil(description.meterFraction(for: meter, values: ["funds": "abc"]))
        XCTAssertNil(description.meterFraction(for: meter, values: [:]))
        XCTAssertEqual(description.displayText(for: label, values: ["name": "Ada"]), "Ada")
        XCTAssertEqual(description.displayText(for: label, values: [:]), "fallback")
    }
}
