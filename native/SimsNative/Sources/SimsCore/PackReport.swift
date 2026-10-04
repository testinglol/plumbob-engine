import Foundation

public struct PackReport: Codable, Sendable {
    public struct Resource: Codable, Sendable {
        public let path: String
        public let owner: String
        public let providers: [String]
        public let declaredOverride: Bool
        public let bytes: Int
        public let sha256: String
    }

    public let schemaVersion: Int
    public let baseGameVersion: String
    public let packs: [String]
    public let fingerprint: String
    public let resources: [Resource]
    public let objects: [PackObjectDefinition]
    public var avatarResources: [PackAvatarResource]? = nil
    public var reservations: [ObjectGUIDReservation]? = nil
    public var plugins: [PackPluginReport]? = nil
    public var panels: [PackPanelReport]? = nil
    public var packDetails: [PackDetailReport]? = nil
}

public extension PackStack {
    func report() throws -> PackReport {
        var providers: [String: [String]] = [:]
        var overrides: [String: Set<String>] = [:]
        for pack in ordered {
            overrides[pack.manifest.id] = try Set(pack.manifest.overrides.map(resourceKey))
            for path in pack.assets.keys {
                providers[path, default: []].append(pack.manifest.id)
            }
        }
        let resources = try assets.sorted(by: { $0.key < $1.key }).map { path, source in
            let data = try Data(contentsOf: source)
            let owners = providers[path]!
            let owner = owners.last!
            return PackReport.Resource(
                path: path, owner: owner, providers: owners,
                declaredOverride: overrides[owner]!.contains(path), bytes: data.count,
                sha256: SHA256Digest.hex(data)
            )
        }
        let packIDs = ordered.map { $0.manifest.id + "@" + $0.manifest.version }
        let fingerprints = resources.map { $0.path + ":" + $0.sha256 }
        let reserved = reservations.map { "object-guid:" + $0.owner + ":" + $0.name + ":" + String($0.guid) }
        let plugins = try pluginReports()
        let panels = try panelReports()
        // Packs without plugins or panels keep their earlier fingerprint calculation.
        let code = plugins.map { "plugin:" + $0.packID + ":" + $0.sha256 + ":" + String($0.stateVersion) } +
            panels.map { "panel:" + $0.packID + ":" + $0.id + ":" + $0.sha256 }
        let fingerprint = SHA256Digest.hex(Data((packIDs + fingerprints + reserved + code).joined(separator: "\n").utf8))
        return PackReport(schemaVersion: 1, baseGameVersion: "1.90", packs: packIDs,
                          fingerprint: fingerprint, resources: resources, objects: objects, avatarResources: avatarResources, reservations: reservations,
                          plugins: plugins.isEmpty ? nil : plugins, panels: panels.isEmpty ? nil : panels, packDetails: packDetails())
    }
}
