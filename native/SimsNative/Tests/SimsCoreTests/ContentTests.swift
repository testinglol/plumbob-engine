import Foundation
import XCTest
@testable import SimsCore

final class ContentTests: XCTestCase {
    /// An instance for borrowing fixture helpers from other test classes; Linux XCTest has no argument-free init.
    static func fixture() -> ContentTests {
        #if canImport(ObjectiveC)
        return ContentTests()
        #else
        return ContentTests(name: "fixture", testClosure: { _ in })
        #endif
    }

    func integer(_ value: UInt32) -> Data {
        withUnsafeBytes(of: value.littleEndian) { Data($0) }
    }

    func archive(_ name: String, payload: Data) -> Data {
        var data = Data("FAR!byAZ".utf8) + integer(1) + integer(UInt32(16 + payload.count))
        data += payload
        data += integer(1) + integer(UInt32(payload.count)) + integer(UInt32(payload.count)) + integer(16)
        data += integer(UInt32(name.utf8.count)) + Data(name.utf8)
        return data
    }

    func testReadsOriginalPathSyntaxCaseInsensitively() throws {
        let payload = Data([1, 2, 3, 4])
        let file = try FARArchive(data: archive("Nbhd\\NScreen.BMP", payload: payload))
        XCTAssertEqual(try file.read("nbhd/nscreen.bmp"), payload)
    }

    func testDecodesPaletteRLEAndRejectsOverrun() throws {
        var header = Data(repeating: 0, count: 54)
        header.replaceSubrange(0..<2, with: Data("BM".utf8))
        for (offset, value) in [(10, 62), (14, 40), (18, 2), (22, 2), (30, 1), (46, 2)] {
            header.replaceSubrange(offset..<(offset + 4), with: integer(UInt32(value)))
        }
        header[26] = 1
        header[28] = 8
        let palette = Data([0, 0, 0, 0, 0, 0, 255, 0])
        let encoded = header + palette + Data([2, 1, 0, 0, 2, 0, 0, 1])
        let bitmap = try SimsBitmap(data: encoded)
        XCTAssertEqual(bitmap.width, 2)
        XCTAssertEqual(bitmap.height, 2)
        XCTAssertEqual(Array(bitmap.rgba.prefix(8)), [0, 0, 0, 255, 0, 0, 0, 255])
        XCTAssertEqual(Array(bitmap.rgba.suffix(8)), [255, 0, 0, 255, 255, 0, 0, 255])
        XCTAssertThrowsError(try SimsBitmap(data: header + palette + Data([3, 1, 0, 1])))
        XCTAssertThrowsError(try SimsBitmap(data: header + palette + Data([2, 4, 0, 1])))
    }

    func testRejectsTruncationAndTraversal() {
        let valid = archive("asset.bmp", payload: Data([4, 5]))
        for length in 0..<valid.count {
            XCTAssertThrowsError(try FARArchive(data: Data(valid.prefix(length))))
        }
        for path in ["../outside.bmp", "/absolute.bmp", "C:\\file.bmp", "a//b", "a/./b"] {
            XCTAssertThrowsError(try resourceKey(path))
        }
    }

    func makePack(_ root: URL, id: String, dependencies: [[String: String]] = [], overrides: [String] = [], payload: String = "content", asset: String = "UIGraphics/shared.bmp") throws -> ContentPack {
        let directory = root.appendingPathComponent(id)
        let resource = directory.appendingPathComponent("files/" + asset)
        try FileManager.default.createDirectory(at: resource.deletingLastPathComponent(), withIntermediateDirectories: true)
        try Data(payload.utf8).write(to: resource)
        let manifest: [String: Any] = ["schemaVersion": 1, "id": id, "name": id, "version": "1.0.0", "baseGameVersion": "1.90", "dependencies": dependencies, "overrides": overrides]
        try JSONSerialization.data(withJSONObject: manifest).write(to: directory.appendingPathComponent("pack.json"))
        return try ContentPack(directory: directory)
    }

    func temporary() throws -> URL {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        addTeardownBlock { try FileManager.default.removeItem(at: root) }
        return root
    }

    func testDependenciesAndExplicitOverrides() throws {
        let root = try temporary()
        let first = try makePack(root, id: "z-base")
        let second = try makePack(root, id: "a-addition", dependencies: [["id": "z-base", "version": "1.0.0"]], overrides: ["UIGraphics/shared.bmp"], payload: "replacement")
        let stack = try PackStack(packs: [second, first])
        XCTAssertEqual(stack.ordered.map { $0.manifest.id }, ["z-base", "a-addition"])
        XCTAssertEqual(try Data(contentsOf: XCTUnwrap(stack.assets["uigraphics/shared.bmp"])), Data("replacement".utf8))
        XCTAssertEqual(try Data(contentsOf: XCTUnwrap(first.assets["uigraphics/shared.bmp"])), Data("content".utf8))
    }

    func testRejectsConflictsMissingDependenciesAndCycles() throws {
        let root = try temporary()
        let first = try makePack(root, id: "first")
        let second = try makePack(root, id: "second")
        XCTAssertThrowsError(try PackStack(packs: [first, second]))
        let missing = try makePack(root, id: "missing", dependencies: [["id": "unknown", "version": "*"]])
        XCTAssertThrowsError(try PackStack(packs: [missing]))
        let a = try makePack(root, id: "cycle-a", dependencies: [["id": "cycle-b", "version": "*"]])
        let b = try makePack(root, id: "cycle-b", dependencies: [["id": "cycle-a", "version": "*"]])
        XCTAssertThrowsError(try PackStack(packs: [a, b]))
    }

    func testReportTracksWinningResourcesAndSaveCompatibility() throws {
        let root = try temporary()
        let first = try makePack(root, id: "z-base")
        let second = try makePack(root, id: "a-addition", dependencies: [["id": "z-base", "version": "*"]], overrides: ["UIGraphics/shared.bmp"], payload: "replacement")
        let stack = try PackStack(packs: [second, first])
        let report = try stack.report()
        XCTAssertEqual(report.packs, ["z-base@1.0.0", "a-addition@1.0.0"])
        XCTAssertEqual(report.resources.count, 1)
        let resource = try XCTUnwrap(report.resources.first)
        XCTAssertEqual(resource.path, "uigraphics/shared.bmp")
        XCTAssertEqual(resource.owner, "a-addition")
        XCTAssertEqual(resource.providers, ["z-base", "a-addition"])
        XCTAssertTrue(resource.declaredOverride)
        XCTAssertEqual(resource.bytes, 11)
        XCTAssertEqual(resource.sha256, "95713e9cbdd1dfcb2d4080c2537f418d43ca0da25f0d7d6631f4f7c97b89dc47")
        XCTAssertEqual(try PackStack(packs: [first, second]).report().fingerprint, report.fingerprint)
        try Data("unused change".utf8).write(to: XCTUnwrap(first.assets[resource.path]))
        XCTAssertEqual(try stack.report().fingerprint, report.fingerprint)
        try Data("winning change".utf8).write(to: XCTUnwrap(second.assets[resource.path]))
        XCTAssertNotEqual(try stack.report().fingerprint, report.fingerprint)
        let decoded = try JSONDecoder().decode(PackReport.self, from: JSONEncoder().encode(report))
        XCTAssertEqual(decoded.resources.first?.providers, resource.providers)
        XCTAssertEqual(decoded.fingerprint, report.fingerprint)
    }

    func testRejectsExecutableAssetsAndEscapingSymlinks() throws {
        let root = try temporary()
        _ = try makePack(root, id: "bad")
        let directory = root.appendingPathComponent("bad")
        let executable = directory.appendingPathComponent("files/Downloads/evil.exe")
        try FileManager.default.createDirectory(at: executable.deletingLastPathComponent(), withIntermediateDirectories: true)
        try Data([0]).write(to: executable)
        XCTAssertThrowsError(try ContentPack(directory: directory))
        try FileManager.default.removeItem(at: executable)
        let outside = root.appendingPathComponent("outside.bmp")
        try Data([1]).write(to: outside)
        try FileManager.default.createSymbolicLink(at: executable.deletingLastPathComponent().appendingPathComponent("escape.bmp"), withDestinationURL: outside)
        XCTAssertThrowsError(try ContentPack(directory: directory))
    }

    func testArchivedSkinsRequireDeclaredOverrides() throws {
        let root = try temporary()
        let game = root.appendingPathComponent("game")
        let ui = game.appendingPathComponent("UIGraphics/UIGraphics.far")
        let skins = game.appendingPathComponent("GameData/Skins/Skins.far")
        for file in [ui, skins] { try FileManager.default.createDirectory(at: file.deletingLastPathComponent(), withIntermediateDirectories: true) }
        try archive("shared.bmp", payload: Data([1])).write(to: ui)
        try archive("B004MAFitlgt_rat.BMP", payload: Data([2])).write(to: skins)
        _ = try makePack(root, id: "undeclared", asset: "GameData/Skins/B004MAFitlgt_rat.bmp")
        XCTAssertThrowsError(try GameContent(root: game, packDirectories: [root.appendingPathComponent("undeclared")]))
        _ = try makePack(root, id: "declared", overrides: ["GameData/Skins/B004MAFitlgt_rat.bmp"], asset: "GameData/Skins/B004MAFitlgt_rat.bmp")
        let content = try GameContent(root: game, packDirectories: [root.appendingPathComponent("declared")])
        XCTAssertEqual(try content.read("GameData/Skins/B004MAFitlgt_rat.bmp"), Data("content".utf8))
        _ = try makePack(root, id: "wrong-format", overrides: ["GameData/Skins/B004MAFitlgt_rat.tga"], asset: "GameData/Skins/B004MAFitlgt_rat.tga")
        XCTAssertThrowsError(try GameContent(root: game, packDirectories: [root.appendingPathComponent("wrong-format")]))
        let alias = game.appendingPathComponent("ExpansionShared/SkinsBuy/B004MAFitlgt_rat.bmp")
        try FileManager.default.createDirectory(at: alias.deletingLastPathComponent(), withIntermediateDirectories: true)
        try Data([3]).write(to: alias)
        XCTAssertThrowsError(try GameContent(root: game, packDirectories: [root.appendingPathComponent("declared")]))
    }

    func testSkinAliasesCannotBypassPackConflicts() throws {
        let root = try temporary()
        let first = try makePack(root, id: "first", asset: "GameData/Skins/example.bmp")
        let second = try makePack(root, id: "second", overrides: ["ExpansionShared/SkinsBuy/example.bmp"], asset: "ExpansionShared/SkinsBuy/example.bmp")
        XCTAssertThrowsError(try PackStack(packs: [first, second]))
        let alternate = try makePack(root, id: "alternate", asset: "GameData/Skins/example.tga")
        XCTAssertThrowsError(try PackStack(packs: [first, alternate]))
    }
}
