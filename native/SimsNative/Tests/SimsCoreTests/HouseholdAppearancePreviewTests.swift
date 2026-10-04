import Foundation
import XCTest
@testable import SimsCore

final class HouseholdAppearancePreviewTests: XCTestCase {
    private func previewJSON(file: String = "textures/preview.bmp", vertexZ: Float = 0.5) throws -> Data {
        let vertices: [[String: Float]] = (0..<3).map { index in
            ["x": Float(index == 1 ? 1 : 0), "y": Float(index == 2 ? 1 : 0), "z": vertexZ,
             "u": 0, "v": 0, "nx": 0, "ny": 1, "nz": 0]
        }
        let object: [String: Any] = [
            "schemaVersion": 1,
            "width": 1,
            "height": 1,
            "textures": [["file": file, "width": 1, "height": 1, "encoding": "bmp"]],
            "meshes": [["texture": 0, "objectID": 0, "depth": 0.5, "vertices": vertices, "layer": 1]]
        ]
        return try JSONSerialization.data(withJSONObject: object)
    }

    func testAcceptsBoundedOriginalAvatarPreviewManifest() throws {
        let preview = try JSONDecoder().decode(HouseholdAppearancePreview.self, from: previewJSON())
        XCTAssertNoThrow(try preview.validate())
    }

    func testRejectsPreviewTextureTraversalAndInvalidDepth() throws {
        let pathTraversal = try JSONDecoder().decode(HouseholdAppearancePreview.self, from: previewJSON(file: "../preview.bmp"))
        XCTAssertThrowsError(try pathTraversal.validate())

        let invalidDepth = try JSONDecoder().decode(HouseholdAppearancePreview.self, from: previewJSON(vertexZ: 1.1))
        XCTAssertThrowsError(try invalidDepth.validate())
    }
}
