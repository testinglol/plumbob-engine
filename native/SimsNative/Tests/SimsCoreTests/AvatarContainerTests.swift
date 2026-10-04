import Foundation
import XCTest
@testable import SimsCore

final class AvatarContainerTests: XCTestCase {
    enum Atom {
        case text(String), integer(Int32), short(Int16), float(Float)
    }

    func fixture(appearance: String = "Hat", animation: String = "Wave", skeleton: String = "Human") -> [Atom] {
        [.integer(1), .text(skeleton), .short(1), .text("ROOT"), .text("NULL"),
         .integer(1), .integer(1), .text("key"), .text("value"),
         .float(0), .float(0), .float(0), .float(0), .float(0), .float(0), .float(1),
         .integer(1), .integer(1), .integer(1), .float(0), .float(0),
         .integer(1), .text(appearance), .integer(0), .integer(0), .integer(1), .text("HEAD"), .text("hat-mesh"), .integer(0), .integer(0),
         .integer(1), .text(animation), .text("wave-curves"), .float(1000), .float(0), .integer(0), .integer(30), .integer(30),
         .integer(1), .text("ROOT"), .integer(30), .float(1000), .integer(1), .integer(1), .integer(0), .integer(0),
         .integer(1), .integer(1), .text("property"), .text("value"), .integer(1), .integer(1), .integer(0),
         .integer(1), .text("dress"), .text("hat")]
    }

    func encoded(_ atoms: [Atom], text: Bool) -> Data {
        var data = text ? Data("// fixture\nversion 300\n".utf8) : Data()
        for atom in atoms {
            if text {
                let value: String
                switch atom {
                case .text(let item): value = item
                case .integer(let item): value = String(item)
                case .short(let item): value = String(item)
                case .float(let item): value = String(item)
                }
                data += Data((value + "\n").utf8)
            } else {
                switch atom {
                case .text(let item): data += Data([UInt8(item.utf8.count)]) + Data(item.utf8)
                case .integer(let item): var value = item.littleEndian; data += withUnsafeBytes(of: &value) { Data($0) }
                case .short(let item): var value = item.littleEndian; data += withUnsafeBytes(of: &value) { Data($0) }
                case .float(let item): var value = item.bitPattern.littleEndian; data += withUnsafeBytes(of: &value) { Data($0) }
                }
            }
        }
        return data
    }

    func temporary() throws -> URL {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: root, withIntermediateDirectories: true)
        return root
    }

    func pack(_ root: URL, id: String, path: String, data: Data, overrides: [String] = [], dependencies: [[String: String]] = []) throws -> ContentPack {
        let directory = root.appendingPathComponent(id)
        let file = directory.appendingPathComponent("files/" + path)
        try FileManager.default.createDirectory(at: file.deletingLastPathComponent(), withIntermediateDirectories: true)
        try data.write(to: file)
        let manifest: [String: Any] = ["schemaVersion": 1, "id": id, "name": id, "version": "1", "baseGameVersion": "1.90", "dependencies": dependencies, "overrides": overrides]
        try JSONSerialization.data(withJSONObject: manifest).write(to: directory.appendingPathComponent("pack.json"))
        return try ContentPack(directory: directory)
    }

    func testTextAndBinaryWalkSkeletonsBindingsAndAnimationProperties() throws {
        for text in [false, true] {
            let path = text ? "fixture.cmx" : "fixture.bcf"
            let definitions = try AvatarContainer.read(encoded(fixture(), text: text), path: path, owner: "test")
            XCTAssertEqual(definitions.map { $0.kind + ":" + $0.name }, ["skeleton:human", "appearance:hat", "animation:wave"])
            if text {
                let original = String(data: encoded(fixture(), text: true), encoding: .utf8)!
                let grouped = original.replacingOccurrences(of: "0.0\n0.0\n0.0\n", with: "0.0 0.0 0.0\n")
                XCTAssertEqual(try AvatarContainer.read(Data(grouped.utf8), path: path, owner: "test"), definitions)
                XCTAssertEqual(try AvatarContainer.read(Data(("\u{FEFF}" + original).utf8), path: path, owner: "test"), definitions)
            }
        }
    }

    func testRejectsTruncationMalformedCountsAndDuplicateInternalNames() throws {
        let binary = encoded(fixture(), text: false)
        for length in 0..<binary.count { XCTAssertThrowsError(try AvatarContainer.read(Data(binary.prefix(length)), path: "a.bcf", owner: "test")) }
        XCTAssertThrowsError(try AvatarContainer.read(encoded([.integer(-1)], text: false), path: "a.bcf", owner: "test"))
        XCTAssertThrowsError(try AvatarContainer.read(Data("version 200\n0\n0\n0\n".utf8), path: "a.cmx", owner: "test"))
        XCTAssertThrowsError(try AvatarContainer.read(encoded(fixture(appearance: ""), text: true), path: "a.cmx", owner: "test"))
        let duplicated: [Atom] = [.integer(0), .integer(2), .text("HAT"), .integer(0), .integer(0), .integer(0), .text("hat"), .integer(0), .integer(0), .integer(0), .integer(0)]
        XCTAssertThrowsError(try AvatarContainer.read(encoded(duplicated, text: true), path: "a.cmx", owner: "test"))
        XCTAssertEqual(try AvatarContainer.read(encoded(duplicated, text: false), path: "a.bcf", owner: "base", allowDuplicates: true).count, 2)
    }

    func testPackSymbolsRejectAliasesAndAllowExplicitContainerReplacement() throws {
        let root = try temporary()
        defer { try? FileManager.default.removeItem(at: root) }
        let first = try pack(root, id: "first", path: "GameData/Skins/first.cmx", data: encoded(fixture(), text: true))
        let collision = try pack(root, id: "collision", path: "Downloads/other.bcf", data: encoded(fixture(appearance: "HAT", animation: "other", skeleton: "other"), text: false))
        XCTAssertThrowsError(try PackStack(packs: [first, collision]))
        let alias = try pack(root, id: "alias", path: "Downloads/first.cmx", data: encoded([.integer(0), .integer(0), .integer(0)], text: true))
        XCTAssertThrowsError(try PackStack(packs: [first, alias]))
        let replacement = try pack(root, id: "replacement", path: "GameData/Skins/first.cmx", data: encoded(fixture(appearance: "new"), text: true), overrides: ["GameData/Skins/first.cmx"], dependencies: [["id": "first", "version": "*"]])
        let stack = try PackStack(packs: [replacement, first])
        XCTAssertTrue(stack.avatarResources.allSatisfy { $0.owner == "replacement" })
        XCTAssertEqual(try stack.report().avatarResources?.count, 3)
    }

    func testEngineFoldersAndExcludedFilenamesAreValidated() throws {
        let root = try temporary()
        defer { try? FileManager.default.removeItem(at: root) }
        for (index, path) in ["GameData/Skins/test.bcf", "ExpansionShared/SkinsBuy/test.cfp", "Downloads/myglobals.cmx"].enumerated() {
            let item = try pack(root, id: "invalid\(index)", path: path, data: encoded([.integer(0), .integer(0), .integer(0)], text: path.hasSuffix(".cmx")))
            XCTAssertThrowsError(try PackStack(packs: [item]))
        }
        let valid = try pack(root, id: "valid", path: "Downloads/test.bcf", data: encoded(fixture(), text: false))
        XCTAssertEqual(try PackStack(packs: [valid]).avatarResources.count, 3)
    }

    func testBaseArchiveSymbolsRequireSameContainerReplacement() throws {
        let root = try temporary()
        defer { try? FileManager.default.removeItem(at: root) }
        let base = root.appendingPathComponent("game")
        try FileManager.default.createDirectory(at: base.appendingPathComponent("UIGraphics"), withIntermediateDirectories: true)
        try FileManager.default.createDirectory(at: base.appendingPathComponent("GameData/Skins"), withIntermediateDirectories: true)
        let archive = ContentTests().archive("original.cmx", payload: encoded(fixture(), text: true))
        try ContentTests().archive("placeholder.bmp", payload: Data()).write(to: base.appendingPathComponent("UIGraphics/UIGraphics.far"))
        try archive.write(to: base.appendingPathComponent("GameData/Skins/skins.far"))
        let collision = try pack(root, id: "collision", path: "GameData/Skins/custom.cmx", data: encoded(fixture(), text: true))
        XCTAssertThrowsError(try GameContent(root: base, packDirectories: [collision.directory]))
        let loose = try pack(root, id: "loose", path: "GameData/Skins/original.cmx", data: encoded(fixture(), text: true), overrides: ["GameData/Skins/original.cmx"])
        XCTAssertEqual(try GameContent(root: base, packDirectories: [loose.directory]).packs.avatarResources.count, 3)
        let replacement = try pack(root, id: "archive", path: "GameData/Skins/skins.far", data: archive, overrides: ["GameData/Skins/skins.far"])
        XCTAssertEqual(try GameContent(root: base, packDirectories: [replacement.directory]).packs.avatarResources.count, 3)
        let looseData = encoded(fixture(appearance: "different", animation: "different", skeleton: "different"), text: true)
        try looseData.write(to: base.appendingPathComponent("GameData/Skins/base-loose.cmx"))
        let alias = try pack(root, id: "loose-alias", path: "Downloads/base-loose.cmx", data: looseData, overrides: ["Downloads/base-loose.cmx"])
        XCTAssertThrowsError(try GameContent(root: base, packDirectories: [alias.directory])) { error in
            XCTAssertTrue(String(describing: error).contains("loose base path"))
        }
    }
}
