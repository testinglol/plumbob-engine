import Foundation
import SimsCore

/// The pack commands every front end offers: loading the enabled pack collection and the report, plugin trust and object
/// GUID commands of `docs/PACKS.md`. They read content without creating a mount or starting the simulation.
public enum PackTool {
    public enum Command: Equatable, Sendable {
        case report
        case listPlugins
        case trustPlugin(String)
        case revokePlugin(String)
        case allocateObjectGUID(packID: String, name: String)
        case reserveObjectGUID(packID: String, name: String)
    }

    /// The game content with every child of `packs` that holds a `pack.json`. A missing folder means no custom packs.
    public static func loadContent(game: URL, packs: URL?) throws -> GameContent {
        var directories: [URL] = []
        if let packs, FileManager.default.fileExists(atPath: packs.path) {
            directories = try FileManager.default.contentsOfDirectory(at: packs, includingPropertiesForKeys: nil).filter {
                FileManager.default.fileExists(atPath: $0.appendingPathComponent("pack.json").path)
            }
        }
        return try GameContent(root: game, packDirectories: directories)
    }

    /// Runs `command` and returns its JSON output.
    public static func run(_ command: Command, content: GameContent, dataRoot: URL) throws -> Data {
        switch command {
        case .report:
            let encoder = JSONEncoder()
            encoder.outputFormatting = [.prettyPrinted, .sortedKeys]
            return try encoder.encode(content.packs.report())
        case .allocateObjectGUID(let packID, let name):
            return try JSONEncoder().encode(content.allocateObjectGUID(packID: packID, name: name))
        case .reserveObjectGUID(let packID, let name):
            return try JSONEncoder().encode(content.reserveObjectGUID(packID: packID, name: name))
        case .listPlugins, .trustPlugin, .revokePlugin:
            var store = try PluginTrustStore(dataRoot: dataRoot)
            let plugins = try content.packs.pluginReports()
            if case .trustPlugin(let packID) = command {
                guard let plugin = plugins.first(where: { $0.packID == packID }) else {
                    throw ContentError.invalid("No enabled pack named \(packID) declares a plugin")
                }
                try store.trust(plugin)
            }
            if case .revokePlugin(let packID) = command {
                guard try store.revoke(packID: packID) else { throw ContentError.invalid("Plugin \(packID) was not trusted") }
            }
            let listing: [[String: Any]] = plugins.map {
                ["packID": $0.packID, "version": $0.version, "sha256": $0.sha256, "entryType": $0.entryType,
                 "apiVersion": $0.apiVersion, "stateVersion": $0.stateVersion, "trusted": store.isTrusted($0)]
            }
            let result: [String: Any] = ["trustStore": store.url.path, "plugins": listing]
            return try JSONSerialization.data(withJSONObject: result, options: [.prettyPrinted, .sortedKeys])
        }
    }

    /// The enabled plugins the player has not trusted yet, with their pack names, for a launch-time review.
    public static func untrustedPlugins(content: GameContent, dataRoot: URL) -> [(plugin: PackPluginReport, name: String)] {
        guard let plugins = try? content.packs.pluginReports(), !plugins.isEmpty,
              let store = try? PluginTrustStore(dataRoot: dataRoot) else { return [] }
        return plugins.filter { !store.isTrusted($0) }.map { plugin in
            (plugin, content.packs.ordered.first { $0.manifest.id == plugin.packID }?.manifest.name ?? plugin.packID)
        }
    }

    /// Records trust for exactly the reviewed plugin files.
    public static func trust(_ plugin: PackPluginReport, dataRoot: URL) throws {
        var store = try PluginTrustStore(dataRoot: dataRoot)
        try store.trust(plugin)
    }
}
