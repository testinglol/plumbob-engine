import Foundation
import XCTest
@testable import SimsCore

final class ContentMountTests: XCTestCase {
    func testPackMountUsesIndependentFilesAndPreservesBaseCasing() throws {
        let manager = FileManager.default
        let temporary = manager.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        let base = temporary.appendingPathComponent("base")
        let pack = temporary.appendingPathComponent("pack")
        try manager.createDirectory(at: base.appendingPathComponent("UIGraphics"), withIntermediateDirectories: true)
        try manager.createDirectory(at: base.appendingPathComponent("GameData/Floors"), withIntermediateDirectories: true)
        try manager.createDirectory(at: pack.appendingPathComponent("files/gamedata/floors"), withIntermediateDirectories: true)
        defer { try? manager.removeItem(at: temporary) }
        var archive = Data("FAR!byAZ".utf8)
        for value: UInt32 in [1, 16, 0] { archive += withUnsafeBytes(of: value.littleEndian) { Data($0) } }
        try archive.write(to: base.appendingPathComponent("UIGraphics/UIGraphics.far"))
        let original = base.appendingPathComponent("GameData/Floors/original.flr")
        try Data("base".utf8).write(to: original)
        let replacement = pack.appendingPathComponent("files/gamedata/floors/original.flr")
        try Data("pack".utf8).write(to: replacement)
        let manifest: [String: Any] = ["schemaVersion": 1, "id": "local.test", "name": "Test", "version": "1.0", "baseGameVersion": "1.90", "dependencies": [], "overrides": ["GameData/Floors/original.flr"]]
        try JSONSerialization.data(withJSONObject: manifest).write(to: pack.appendingPathComponent("pack.json"))
        let content = try GameContent(root: base, packDirectories: [pack])
        let mount = temporary.appendingPathComponent("mount")
        try content.materialize(at: mount)
        let report = try content.packs.report()
        let metadata = try XCTUnwrap(JSONSerialization.jsonObject(with: Data(contentsOf: mount.appendingPathComponent(".native-pack-stack.json"))) as? [String: Any])
        XCTAssertEqual(metadata["fingerprint"] as? String, report.fingerprint)
        XCTAssertEqual(metadata["packs"] as? [String], report.packs)
        XCTAssertEqual(report.resources.first?.owner, "local.test")
        XCTAssertEqual(report.resources.first?.declaredOverride, true)
        let mounted = mount.appendingPathComponent("GameData/Floors/original.flr")
        XCTAssertEqual(try Data(contentsOf: mounted), Data("pack".utf8))
        try Data("changed".utf8).write(to: mounted)
        XCTAssertEqual(try Data(contentsOf: original), Data("base".utf8))
        XCTAssertEqual(try Data(contentsOf: replacement), Data("pack".utf8))
        let mountedArchive = mount.appendingPathComponent("UIGraphics/UIGraphics.far")
        try Data().write(to: mountedArchive)
        XCTAssertEqual(try Data(contentsOf: base.appendingPathComponent("UIGraphics/UIGraphics.far")), archive)
        XCTAssertThrowsError(try content.materialize(at: mount))
        XCTAssertThrowsError(try content.materialize(at: base.appendingPathComponent("mount")))
    }
}
