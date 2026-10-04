import Foundation
import XCTest
@testable import SimsCore

final class ObjectGUIDAllocatorTests: XCTestCase {
    func reserve(_ pack: ContentPack, names: [String: UInt32]) throws -> ContentPack {
        let path = pack.directory.appendingPathComponent("pack.json")
        var document = try XCTUnwrap(JSONSerialization.jsonObject(with: Data(contentsOf: path)) as? [String: Any])
        document["objectGUIDs"] = names
        try JSONSerialization.data(withJSONObject: document).write(to: path)
        return try ContentPack(directory: pack.directory)
    }

    func testDeterministicAllocationAvoidsUsedGUIDsAndRejectsUnstableNames() throws {
        let first = try ObjectGUIDAllocator.propose(packID: "local.expansion", name: "furniture.chair", used: [])
        XCTAssertEqual(first & 0xF0000000, 0xE0000000)
        XCTAssertEqual(try ObjectGUIDAllocator.propose(packID: "local.expansion", name: "furniture.chair", used: []), first)
        let next = try ObjectGUIDAllocator.propose(packID: "local.expansion", name: "furniture.chair", used: [first])
        XCTAssertNotEqual(next, first)
        XCTAssertNotEqual(try ObjectGUIDAllocator.propose(packID: "other.expansion", name: "furniture.chair", used: []), first)
        for invalid in ["", "Chair", "bad/name", "bad:name", String(repeating: "a", count: 129)] {
            XCTAssertThrowsError(try ObjectGUIDAllocator.propose(packID: "local.expansion", name: invalid, used: []))
        }
    }

    func testReservationsRejectConflictsAndChangeSaveFingerprint() throws {
        let helper = PackObjectTests()
        let root = try helper.temporary()
        let first = try helper.pack(root, id: "first", path: "Downloads/first.iff", data: helper.object(42))
        let baseline = try PackStack(packs: [first]).report().fingerprint
        let reserved = try reserve(first, names: ["first": 42, "future": 43])
        let report = try PackStack(packs: [reserved]).report()
        XCTAssertEqual(report.reservations?.count, 2)
        XCTAssertNotEqual(report.fingerprint, baseline)
        let other = try helper.pack(root, id: "other", path: "Downloads/other.iff", data: helper.object(44))
        let collision = try reserve(other, names: ["future": 43])
        XCTAssertThrowsError(try PackStack(packs: [reserved, collision]))
        let foreign = try reserve(other, names: ["foreign": 42])
        XCTAssertThrowsError(try PackStack(packs: [reserved, foreign]))
        let duplicate = try reserve(first, names: ["one": 42, "two": 42])
        XCTAssertThrowsError(try PackStack(packs: [duplicate]))
    }

    func testInheritedReservationAllowsExplicitObjectReplacement() throws {
        let helper = PackObjectTests()
        let root = try helper.temporary()
        let path = "Downloads/object.iff"
        let original = try reserve(helper.pack(root, id: "original", path: path, data: helper.object(42)), names: ["object": 42])
        let replacement = try helper.pack(root, id: "replacement", path: path, data: helper.object(42), overrides: [path], dependencies: [["id": "original", "version": "*"]])
        let stack = try PackStack(packs: [original, replacement])
        XCTAssertEqual(stack.reservations.first?.owner, "original")
        XCTAssertEqual(stack.objects.first?.owner, "replacement")
    }

    func testPersistentReservationsCheckBaseAndDetectManifestChanges() throws {
        let helper = PackObjectTests()
        let root = try helper.temporary()
        let base = root.appendingPathComponent("game")
        let ui = base.appendingPathComponent("UIGraphics/UIGraphics.far")
        try FileManager.default.createDirectory(at: ui.deletingLastPathComponent(), withIntermediateDirectories: true)
        try ContentTests().archive("pixel.bmp", payload: Data()).write(to: ui)
        let pack = try helper.pack(root, id: "author", path: "Downloads/object.iff", data: helper.object(42))
        let content = try GameContent(root: base, packDirectories: [pack.directory])
        let identity = try content.reserveObjectGUID(packID: "author", name: "new-object")
        XCTAssertThrowsError(try content.reserveObjectGUID(packID: "author", name: "another"))
        let reloaded = try GameContent(root: base, packDirectories: [pack.directory])
        XCTAssertEqual(try reloaded.allocateObjectGUID(packID: "author", name: "new-object").guid, identity.guid)
        XCTAssertEqual(try reloaded.reserveObjectGUID(packID: "author", name: "new-object").guid, identity.guid)
        let archive = base.appendingPathComponent("Objects.far")
        try ContentTests().archive("original.iff", payload: helper.object(identity.guid)).write(to: archive)
        XCTAssertThrowsError(try GameContent(root: base, packDirectories: [pack.directory]))
    }
}
