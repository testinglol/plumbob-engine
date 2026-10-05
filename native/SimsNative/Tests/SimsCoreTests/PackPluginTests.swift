import Foundation
import XCTest
@testable import SimsCore

final class PackPluginTests: XCTestCase {
    private func workspace() throws -> (root: URL, base: URL) {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        let base = root.appendingPathComponent("base")
        try FileManager.default.createDirectory(at: base.appendingPathComponent("UIGraphics"), withIntermediateDirectories: true)
        var archive = Data("FAR!byAZ".utf8)
        for value: UInt32 in [1, 16, 0] { archive += withUnsafeBytes(of: value.littleEndian) { Data($0) } }
        try archive.write(to: base.appendingPathComponent("UIGraphics/UIGraphics.far"))
        return (root, base)
    }

    private func pack(in root: URL, id: String = "local.plug", version: String = "1.0.0", plugin: [String: Any]? = nil, panels: [String]? = nil,
                      migration: [String]? = nil, dll: Data = Data("MZ-plugin".utf8)) throws -> URL {
        let directory = root.appendingPathComponent("packs/" + id)
        try FileManager.default.createDirectory(at: directory.appendingPathComponent("files"), withIntermediateDirectories: true)
        var manifest: [String: Any] = ["schemaVersion": 1, "id": id, "name": id, "version": version, "baseGameVersion": "1.90", "dependencies": [], "overrides": []]
        if let plugin {
            manifest["plugin"] = plugin
            try FileManager.default.createDirectory(at: directory.appendingPathComponent("plugin"), withIntermediateDirectories: true)
            try dll.write(to: directory.appendingPathComponent("plugin/Plug.dll"))
        }
        if let panels { manifest["panels"] = panels }
        if let migration { manifest["saveMigration"] = ["from": migration] }
        try JSONSerialization.data(withJSONObject: manifest).write(to: directory.appendingPathComponent("pack.json"))
        return directory
    }

    private let goodPlugin: [String: Any] = ["assembly": "plugin/Plug.dll", "entryType": "Local.Plug.Entry", "apiVersion": 1, "stateVersion": 1]

    func testPluginIsReportedHashedFingerprintedAndCopiedIntoMounts() throws {
        let (root, base) = try workspace()
        defer { try? FileManager.default.removeItem(at: root) }
        let directory = try pack(in: root, plugin: goodPlugin, migration: ["0.9.0"])
        let content = try GameContent(root: base, packDirectories: [directory])
        let report = try content.packs.report()
        let plugin = try XCTUnwrap(report.plugins?.first)
        XCTAssertEqual(plugin.packID, "local.plug")
        XCTAssertEqual(plugin.assembly, ".native-plugins/local.plug/Plug.dll")
        XCTAssertEqual(report.packDetails?.first?.migratesFrom, ["0.9.0"])
        let mount = root.appendingPathComponent("mount")
        try content.materialize(at: mount)
        XCTAssertEqual(try Data(contentsOf: mount.appendingPathComponent(plugin.assembly)), Data("MZ-plugin".utf8))
        let metadata = try XCTUnwrap(JSONSerialization.jsonObject(with: Data(contentsOf: mount.appendingPathComponent(".native-pack-stack.json"))) as? [String: Any])
        XCTAssertEqual((metadata["plugins"] as? [[String: Any]])?.first?["sha256"] as? String, plugin.sha256)
        XCTAssertEqual(try pluginDigest(in: mount.appendingPathComponent(".native-plugins/local.plug")), plugin.sha256)

        // Changing the assembly changes both its digest and the save fingerprint.
        try Data("MZ-changed".utf8).write(to: directory.appendingPathComponent("plugin/Plug.dll"))
        let changed = try GameContent(root: base, packDirectories: [directory]).packs.report()
        XCTAssertNotEqual(changed.plugins?.first?.sha256, plugin.sha256)
        XCTAssertNotEqual(changed.fingerprint, report.fingerprint)
    }

    func testPacksWithoutPluginsKeepAPluginFreeReport() throws {
        let (root, base) = try workspace()
        defer { try? FileManager.default.removeItem(at: root) }
        let report = try GameContent(root: base, packDirectories: [try pack(in: root)]).packs.report()
        XCTAssertNil(report.plugins)
        XCTAssertNil(report.panels)
    }

    func testRejectsUnsupportedApiVersionBadEntryTypeAndEscapingPaths() throws {
        let (root, base) = try workspace()
        defer { try? FileManager.default.removeItem(at: root) }
        func load(_ plugin: [String: Any]) throws {
            let directory = try pack(in: root, id: "local.bad" + UUID().uuidString.prefix(6).lowercased(), plugin: plugin)
            _ = try GameContent(root: base, packDirectories: [directory])
        }
        var plugin = goodPlugin
        plugin["apiVersion"] = 3
        XCTAssertThrowsError(try load(plugin))
        plugin = goodPlugin; plugin["stateVersion"] = 0
        XCTAssertThrowsError(try load(plugin))
        plugin = goodPlugin; plugin["entryType"] = "Local..Entry"
        XCTAssertThrowsError(try load(plugin))
        plugin = goodPlugin; plugin["entryType"] = "1Bad.Entry"
        XCTAssertThrowsError(try load(plugin))
        plugin = goodPlugin; plugin["assembly"] = "plugin/../pack.json"
        XCTAssertThrowsError(try load(plugin))
        plugin = goodPlugin; plugin["assembly"] = "files/Plug.dll"
        XCTAssertThrowsError(try load(plugin))
        plugin = goodPlugin; plugin["assembly"] = "plugin/Missing.dll"
        XCTAssertThrowsError(try load(plugin))
        plugin = goodPlugin; plugin["assembly"] = "plugin/Plug.txt"
        XCTAssertThrowsError(try load(plugin))
        XCTAssertNoThrow(try load(goodPlugin))
    }

    func testSaveMigrationListMustNotNameTheCurrentVersion() throws {
        let (root, base) = try workspace()
        defer { try? FileManager.default.removeItem(at: root) }
        XCTAssertThrowsError(try GameContent(root: base, packDirectories: [try pack(in: root, version: "2.0.0", migration: ["2.0.0"])]))
        XCTAssertThrowsError(try GameContent(root: base, packDirectories: [try pack(in: root, id: "local.empty", migration: [])]))
    }

    func testPanelsAreValidatedWithThePackAndMustBeUnique() throws {
        let (root, base) = try workspace()
        defer { try? FileManager.default.removeItem(at: root) }
        let directory = try pack(in: root, panels: ["panels/a.json"])
        try FileManager.default.createDirectory(at: directory.appendingPathComponent("panels"), withIntermediateDirectories: true)
        let panel = #"{"schemaVersion":1,"id":"a","title":"A","frame":{"x":100,"y":100,"width":300,"height":220},"elements":[]}"#
        try Data(panel.utf8).write(to: directory.appendingPathComponent("panels/a.json"))
        let content = try GameContent(root: base, packDirectories: [directory])
        XCTAssertEqual(try content.packs.report().panels?.first?.id, "a")
        XCTAssertNotNil(content.packs.panelDescriptions()["local.plug"]?["a"])
        try Data("{".utf8).write(to: directory.appendingPathComponent("panels/a.json"))
        XCTAssertThrowsError(try GameContent(root: base, packDirectories: [directory]))
    }

    func testTrustIsPerExactDigestAndCanBeRevoked() throws {
        let root = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        defer { try? FileManager.default.removeItem(at: root) }
        let plugin = PackPluginReport(packID: "local.plug", version: "1.0.0", assembly: ".native-plugins/local.plug/Plug.dll", sha256: "aa", entryType: "A.B", apiVersion: 1, stateVersion: 1)
        var store = try PluginTrustStore(dataRoot: root)
        XCTAssertFalse(store.isTrusted(plugin))
        try store.trust(plugin)
        XCTAssertTrue(try PluginTrustStore(dataRoot: root).isTrusted(plugin))
        let changed = PackPluginReport(packID: "local.plug", version: "1.0.0", assembly: plugin.assembly, sha256: "bb", entryType: "A.B", apiVersion: 1, stateVersion: 1)
        XCTAssertFalse(store.isTrusted(changed))
        try store.trust(changed)
        XCTAssertFalse(store.isTrusted(plugin), "Trusting a new digest replaces the earlier trust for the pack")
        XCTAssertEqual(store.entries.count, 1)
        XCTAssertTrue(try store.revoke(packID: "local.plug"))
        XCTAssertFalse(try store.revoke(packID: "local.plug"))
        XCTAssertFalse(try PluginTrustStore(dataRoot: root).isTrusted(changed))
    }
}
