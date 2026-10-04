import Foundation
import XCTest
@testable import SimsCore

final class PackObjectTests: XCTestCase {
    func object(_ guid: UInt32, chunkID: UInt16 = 1) -> Data {
        var header = Data("IFF FILE 2.5:TYPE FOLLOWED BY SIZE\0 JAMIE DOORNBOS & MAXIS 1".utf8)
        header += Data(repeating: 0, count: 64 - header.count)
        var chunk = Data(repeating: 0, count: 266)
        chunk.replaceSubrange(0..<4, with: Data("OBJD".utf8))
        withUnsafeBytes(of: UInt32(266).bigEndian) { chunk.replaceSubrange(4..<8, with: $0) }
        withUnsafeBytes(of: chunkID.bigEndian) { chunk.replaceSubrange(8..<10, with: $0) }
        withUnsafeBytes(of: UInt32(138).littleEndian) { chunk.replaceSubrange(76..<80, with: $0) }
        withUnsafeBytes(of: guid.littleEndian) { chunk.replaceSubrange(104..<108, with: $0) }
        return header + chunk
    }

    func pack(_ root: URL, id: String, path: String, data: Data, overrides: [String] = [], dependencies: [[String: String]] = []) throws -> ContentPack {
        let directory = root.appendingPathComponent(id)
        let asset = directory.appendingPathComponent("files/" + path)
        try FileManager.default.createDirectory(at: asset.deletingLastPathComponent(), withIntermediateDirectories: true)
        try data.write(to: asset)
        let manifest: [String: Any] = ["schemaVersion": 1, "id": id, "name": id, "version": "1", "baseGameVersion": "1.90", "dependencies": dependencies, "overrides": overrides]
        try JSONSerialization.data(withJSONObject: manifest).write(to: directory.appendingPathComponent("pack.json"))
        return try ContentPack(directory: directory)
    }

    func temporary() throws -> URL {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        addTeardownBlock { try FileManager.default.removeItem(at: root) }
        return root
    }

    func testRejectsDuplicateGUIDAcrossDifferentPathsAndSameIFF() throws {
        let root = try temporary()
        let first = try pack(root, id: "first", path: "Downloads/one.iff", data: object(0xF1A00001))
        let second = try pack(root, id: "second", path: "Downloads/two.iff", data: object(0xF1A00001))
        XCTAssertThrowsError(try PackStack(packs: [second, first])) { error in
            XCTAssertTrue(String(describing: error).contains("0xF1A00001"))
            XCTAssertTrue(String(describing: error).contains("downloads/one.iff"))
            XCTAssertTrue(String(describing: error).contains("downloads/two.iff"))
        }
        let duplicate = object(42) + object(42, chunkID: 2).dropFirst(64)
        let third = try pack(root, id: "third", path: "Downloads/duplicate.iff", data: duplicate)
        XCTAssertThrowsError(try PackStack(packs: [third]))
    }

    func testExplicitResourceOverrideUsesOnlyWinningDefinitions() throws {
        let root = try temporary()
        let path = "Downloads/object.iff"
        let first = try pack(root, id: "z-base", path: path, data: object(42))
        let replacement = try pack(root, id: "a-replacement", path: path, data: object(43), overrides: [path], dependencies: [["id": "z-base", "version": "*"]])
        let other = try pack(root, id: "other", path: "Downloads/other.iff", data: object(42))
        let stack = try PackStack(packs: [other, replacement, first])
        XCTAssertEqual(stack.objects.map { $0.guid }, [42, 43])
        XCTAssertEqual(stack.objects.last?.owner, "a-replacement")
        let report = try JSONDecoder().decode(PackReport.self, from: JSONEncoder().encode(stack.report()))
        XCTAssertEqual(report.objects.map { $0.guid }, [42, 43])
    }

    func testArchivedDefinitionsCannotHideCollisionWithLooseIFF() throws {
        let root = try temporary()
        let data = ContentTests().archive("nested/object.iff", payload: object(42))
        let archived = try pack(root, id: "archive", path: "Downloads/objects.far", data: data)
        let loose = try pack(root, id: "loose", path: "Downloads/object.iff", data: object(42))
        XCTAssertThrowsError(try PackStack(packs: [archived, loose]))
        let stack = try PackStack(packs: [archived])
        XCTAssertEqual(stack.objects.first?.path, "downloads/objects.far::nested/object.iff")
    }

    func testBaseArchiveAndDownloadGUIDCollisionsRequireResourceReplacement() throws {
        let root = try temporary()
        let base = root.appendingPathComponent("game")
        let archivePath = "GameData/Objects/Objects.far"
        let archiveURL = base.appendingPathComponent(archivePath)
        try FileManager.default.createDirectory(at: archiveURL.deletingLastPathComponent(), withIntermediateDirectories: true)
        let original = ContentTests().archive("original.iff", payload: object(42))
        try original.write(to: archiveURL)
        let collision = try pack(root, id: "collision", path: "Downloads/new.iff", data: object(42))
        XCTAssertThrowsError(try PackStack(packs: [collision]).validateBaseObjects(at: base)) { error in
            XCTAssertTrue(String(describing: error).contains("base:gamedata/objects/objects.far::original.iff"))
        }
        let replacement = try pack(root, id: "replacement", path: archivePath, data: original, overrides: [archivePath])
        XCTAssertNoThrow(try PackStack(packs: [replacement]).validateBaseObjects(at: base))
        let unique = try pack(root, id: "unique", path: "Downloads/unique.iff", data: object(43))
        XCTAssertNoThrow(try PackStack(packs: [unique]).validateBaseObjects(at: base))
        let download = base.appendingPathComponent("Downloads/base.iff")
        try FileManager.default.createDirectory(at: download.deletingLastPathComponent(), withIntermediateDirectories: true)
        try object(43).write(to: download)
        XCTAssertThrowsError(try PackStack(packs: [unique]).validateBaseObjects(at: base))
    }

    func testRejectsMalformedObjectResourcesAndAllowsIFFWithoutObjects() throws {
        let root = try temporary()
        var truncated = object(42)
        truncated.removeLast()
        let bad = try pack(root, id: "bad", path: "Downloads/bad.iff", data: truncated)
        XCTAssertThrowsError(try PackStack(packs: [bad]))
        let zero = try pack(root, id: "zero", path: "Downloads/zero.iff", data: object(0))
        XCTAssertThrowsError(try PackStack(packs: [zero]))
        var invalid = object(42)
        invalid[140] = 255
        let version = try pack(root, id: "version", path: "Downloads/version.iff", data: invalid)
        XCTAssertThrowsError(try PackStack(packs: [version]))
        let empty = try pack(root, id: "empty", path: "UIGraphics/panel.iff", data: object(42).prefix(64))
        XCTAssertTrue(try PackStack(packs: [empty]).objects.isEmpty)
    }

    func testObjectLookupRejectsFilenameAliasesEvenWithDifferentGUIDs() throws {
        let root = try temporary()
        let first = try pack(root, id: "first", path: "Downloads/first/chair.iff", data: object(42))
        let second = try pack(root, id: "second", path: "Downloads/second/CHAIR.IFF", data: object(43))
        XCTAssertThrowsError(try PackStack(packs: [first, second])) { error in
            XCTAssertTrue(String(describing: error).contains("Object resource name chair.iff conflicts"))
        }
        let archived = try pack(root, id: "archive", path: "GameData/Objects/custom.far", data: ContentTests().archive("nested/chair.iff", payload: object(44)))
        XCTAssertThrowsError(try PackStack(packs: [first, archived]))
        let empty = try pack(root, id: "empty", path: "Downloads/empty/chair.iff", data: object(42).prefix(64))
        XCTAssertThrowsError(try PackStack(packs: [first, empty]))
        let ignored = try pack(root, id: "ignored", path: "GameData/Objects/new.iff", data: object(45))
        XCTAssertThrowsError(try PackStack(packs: [ignored]))
        let globals = try pack(root, id: "globals", path: "Downloads/custom-globals.iff", data: object(46))
        XCTAssertThrowsError(try PackStack(packs: [globals]))
    }

    func testBaseResourceNameCollisionDoesNotRequireMatchingGUID() throws {
        let root = try temporary()
        let base = root.appendingPathComponent("game")
        let url = base.appendingPathComponent("GameData/Objects/base.far")
        try FileManager.default.createDirectory(at: url.deletingLastPathComponent(), withIntermediateDirectories: true)
        try ContentTests().archive("nested/chair.iff", payload: object(42)).write(to: url)
        let replacement = try pack(root, id: "replacement", path: "Downloads/new/chair.iff", data: object(43))
        XCTAssertThrowsError(try PackStack(packs: [replacement]).validateBaseObjects(at: base)) { error in
            XCTAssertTrue(String(describing: error).contains("Object resource name chair.iff conflicts: base:"))
        }
        let empty = try pack(root, id: "empty", path: "Downloads/chair.iff", data: object(42).prefix(64))
        XCTAssertThrowsError(try PackStack(packs: [empty]).validateBaseObjects(at: base))
    }
}
