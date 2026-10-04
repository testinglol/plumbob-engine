import Foundation

/// The `plugin` object of a pack manifest.
public struct PluginDeclaration: Codable, Sendable, Equatable {
    /// Pack-relative path of the .NET assembly, under `plugin/`.
    public let assembly: String
    /// Full name of the type implementing `SimsNative.Plugins.ISimsPlugin`.
    public let entryType: String
    /// Plugin contract version; see `PluginDeclaration.supportedAPIVersions`.
    public let apiVersion: Int
    /// Version of the plugin's own save state, starting at 1. Raise it when `SaveState` output changes shape.
    public let stateVersion: Int

    public static let supportedAPIVersions: ClosedRange<Int> = 1...1
}

/// The `saveMigration` object of a pack manifest.
public struct SaveMigration: Codable, Sendable, Equatable {
    public let from: [String]
}

extension ContentPack {
    static func validatedPlugin(_ plugin: PluginDeclaration, packID: String, root: URL) throws -> URL {
        guard PluginDeclaration.supportedAPIVersions.contains(plugin.apiVersion) else {
            throw ContentError.invalid("Pack \(packID) requires unsupported plugin API version \(plugin.apiVersion)")
        }
        guard plugin.stateVersion >= 1 && plugin.stateVersion <= 1_000_000 else {
            throw ContentError.invalid("Pack \(packID) plugin stateVersion must be a positive integer")
        }
        let entryParts = plugin.entryType.split(separator: ".", omittingEmptySubsequences: false)
        guard plugin.entryType.count <= 256, !entryParts.isEmpty,
              entryParts.allSatisfy({ part in
                  guard let first = part.first, first.isLetter || first == "_" else { return false }
                  return part.allSatisfy { $0.isASCII && ($0.isLetter || $0.isNumber || $0 == "_" || $0 == "+") }
              }) else {
            throw ContentError.invalid("Pack \(packID) has an invalid plugin entryType")
        }
        let url = try containedFile(plugin.assembly, folder: "plugin", extensions: ["dll"], packID: packID, root: root)
        return url
    }

    static func validatedPanels(_ paths: [String], packID: String, root: URL) throws -> [(path: String, url: URL, description: PanelDescription)] {
        guard paths.count <= 32 else { throw ContentError.invalid("Pack \(packID) declares more than 32 panels") }
        var seenPaths = Set<String>()
        var seenIDs = Set<String>()
        return try paths.map { path in
            let url = try containedFile(path, folder: "panels", extensions: ["json"], packID: packID, root: root)
            guard seenPaths.insert(url.path.lowercased()).inserted else { throw ContentError.invalid("Pack \(packID) lists panel \(path) twice") }
            let data = try Data(contentsOf: url)
            guard data.count <= 262_144 else { throw ContentError.invalid("Panel \(path) in pack \(packID) exceeds 256 KiB") }
            let description: PanelDescription
            do { description = try JSONDecoder().decode(PanelDescription.self, from: data) }
            catch { throw ContentError.invalid("Panel \(path) in pack \(packID) is not a valid panel description: \(error)") }
            try description.validate()
            guard seenIDs.insert(description.id).inserted else { throw ContentError.invalid("Pack \(packID) has two panels with ID \(description.id)") }
            return (path, url, description)
        }
    }

    /// Resolves a pack-relative path that must stay inside `folder` and must not be a symbolic link.
    private static func containedFile(_ path: String, folder: String, extensions: Set<String>, packID: String, root: URL) throws -> URL {
        let normalized = path.replacingOccurrences(of: "\\", with: "/")
        let components = normalized.split(separator: "/", omittingEmptySubsequences: false).map(String.init)
        guard !normalized.hasPrefix("/"), components.count >= 2, components.first?.lowercased() == folder,
              !components.contains(where: { $0.isEmpty || $0 == "." || $0 == ".." }) else {
            throw ContentError.invalid("Pack \(packID) path must be inside \(folder)/: \(path)")
        }
        let candidate = components.reduce(root) { $0.appendingPathComponent($1) }
        guard extensions.contains(candidate.pathExtension.lowercased()) else {
            throw ContentError.invalid("Pack \(packID) file has an unsupported extension: \(path)")
        }
        let values = try? candidate.resourceValues(forKeys: [.isRegularFileKey, .isSymbolicLinkKey])
        guard values?.isRegularFile == true, values?.isSymbolicLink != true else {
            throw ContentError.invalid("Pack \(packID) is missing \(path)")
        }
        let resolved = candidate.resolvingSymlinksInPath().standardizedFileURL
        guard resolved.path.hasPrefix(root.path + "/") else {
            throw ContentError.invalid("Pack \(packID) file escapes its directory: \(path)")
        }
        return resolved
    }
}

/// Report entry for a code-bearing plugin.
public struct PackPluginReport: Codable, Sendable, Equatable {
    public let packID: String
    public let version: String
    /// Mount-relative path of the copied assembly.
    public let assembly: String
    /// `pluginDigest` of the assembly's folder.
    public let sha256: String
    public let entryType: String
    public let apiVersion: Int
    public let stateVersion: Int
}

/// Report entry for a declarative panel.
public struct PackPanelReport: Codable, Sendable, Equatable {
    public let packID: String
    public let id: String
    public let path: String
    public let sha256: String
}

/// Report entry describing a pack's save-migration sources.
public struct PackDetailReport: Codable, Sendable, Equatable {
    public let id: String
    public let version: String
    public let migratesFrom: [String]
}

func sha256Hex(_ data: Data) -> String {
    SHA256Digest.hex(data)
}

/// Files of a plugin folder that are copied into the mount and covered by trust: regular `.dll` and `.json` files
/// directly inside the folder, sorted by lowercase name.
public func pluginPayload(in folder: URL) throws -> [URL] {
    try FileManager.default.contentsOfDirectory(at: folder, includingPropertiesForKeys: [.isRegularFileKey, .isSymbolicLinkKey])
        .filter { file in
            guard ["dll", "json"].contains(file.pathExtension.lowercased()) else { return false }
            let values = try file.resourceValues(forKeys: [.isRegularFileKey, .isSymbolicLinkKey])
            return values.isRegularFile == true && values.isSymbolicLink != true
        }
        .sorted { $0.lastPathComponent.lowercased() < $1.lastPathComponent.lowercased() }
}

/// Trust digest of a plugin folder: SHA-256 of `name:sha256` lines (lowercase names, one per payload file, each ending in a newline).
/// The simulation host computes the same digest over the mounted copy.
public func pluginDigest(in folder: URL) throws -> String {
    var lines = ""
    for file in try pluginPayload(in: folder) {
        lines += file.lastPathComponent.lowercased() + ":" + sha256Hex(try Data(contentsOf: file)) + "\n"
    }
    return sha256Hex(Data(lines.utf8))
}

public extension PackStack {
    /// Where `materialize` copies plugin assemblies inside a content mount.
    static let mountedPluginFolder = ".native-plugins"

    func pluginReports() throws -> [PackPluginReport] {
        try ordered.compactMap { pack in
            guard let plugin = pack.manifest.plugin, let assembly = pack.pluginAssembly else { return nil }
            return PackPluginReport(packID: pack.manifest.id, version: pack.manifest.version,
                                    assembly: Self.mountedPluginFolder + "/" + pack.manifest.id + "/" + assembly.lastPathComponent,
                                    sha256: try pluginDigest(in: assembly.deletingLastPathComponent()), entryType: plugin.entryType,
                                    apiVersion: plugin.apiVersion, stateVersion: plugin.stateVersion)
        }
    }

    func panelReports() throws -> [PackPanelReport] {
        try ordered.flatMap { pack in
            try pack.panelFiles.map { panel in
                PackPanelReport(packID: pack.manifest.id, id: panel.description.id, path: panel.path,
                                sha256: sha256Hex(try Data(contentsOf: panel.url)))
            }
        }
    }

    func packDetails() -> [PackDetailReport] {
        ordered.map { PackDetailReport(id: $0.manifest.id, version: $0.manifest.version, migratesFrom: $0.manifest.saveMigration?.from ?? []) }
    }

    /// Panel descriptions keyed by pack ID and panel ID, for the Swift renderer.
    func panelDescriptions() -> [String: [String: PanelDescription]] {
        var result: [String: [String: PanelDescription]] = [:]
        for pack in ordered {
            for panel in pack.panelFiles { result[pack.manifest.id, default: [:]][panel.description.id] = panel.description }
        }
        return result
    }
}

/// The local, per-user record of plugin assemblies the player explicitly trusted.
/// Trust names a pack ID, version and assembly SHA-256; any change to the assembly needs a new trust action.
public struct PluginTrustStore: Sendable {
    public struct Entry: Codable, Sendable, Equatable {
        public let packId: String
        public let version: String
        public let sha256: String
        public let trustedAt: String
    }

    private struct File: Codable {
        let schemaVersion: Int
        let plugins: [Entry]
    }

    public let url: URL
    public private(set) var entries: [Entry]

    public static func url(dataRoot: URL) -> URL {
        dataRoot.appendingPathComponent("Settings/plugin-trust.json")
    }

    public init(dataRoot: URL) throws {
        url = Self.url(dataRoot: dataRoot)
        guard FileManager.default.fileExists(atPath: url.path) else { entries = []; return }
        let file = try JSONDecoder().decode(File.self, from: Data(contentsOf: url))
        guard file.schemaVersion == 1 else { throw ContentError.invalid("Unsupported plugin trust store version \(file.schemaVersion)") }
        entries = file.plugins
    }

    public func isTrusted(_ plugin: PackPluginReport) -> Bool {
        entries.contains { $0.packId == plugin.packID && $0.version == plugin.version && $0.sha256 == plugin.sha256 }
    }

    /// Records trust for exactly this assembly, replacing any earlier trust for the same pack.
    public mutating func trust(_ plugin: PackPluginReport, now: Date = Date()) throws {
        entries.removeAll { $0.packId == plugin.packID }
        entries.append(Entry(packId: plugin.packID, version: plugin.version, sha256: plugin.sha256,
                             trustedAt: ISO8601DateFormatter().string(from: now)))
        try save()
    }

    /// Removes trust for a pack. Returns false when it was not trusted.
    @discardableResult
    public mutating func revoke(packID: String) throws -> Bool {
        let before = entries.count
        entries.removeAll { $0.packId == packID }
        guard entries.count != before else { return false }
        try save()
        return true
    }

    private func save() throws {
        try FileManager.default.createDirectory(at: url.deletingLastPathComponent(), withIntermediateDirectories: true)
        let encoder = JSONEncoder()
        encoder.outputFormatting = [.prettyPrinted, .sortedKeys]
        let data = try encoder.encode(File(schemaVersion: 1, plugins: entries.sorted { $0.packId < $1.packId }))
        try data.write(to: url, options: .atomic)
    }
}
