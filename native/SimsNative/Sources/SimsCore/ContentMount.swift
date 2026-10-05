import Foundation
#if canImport(Darwin)
import Darwin
#endif

public extension GameContent {
    func materialize(at destination: URL) throws {
        let manager = FileManager.default
        guard !manager.fileExists(atPath: destination.path) else {
            throw ContentError.invalid("Content mount already exists: \(destination.path)")
        }
        let base = root.resolvingSymlinksInPath().standardizedFileURL
        let target = destination.resolvingSymlinksInPath().standardizedFileURL
        guard !target.path.hasPrefix(base.path + "/"), target != base else {
            throw ContentError.invalid("Content mounts must be outside the base game")
        }
        try manager.createDirectory(at: target.deletingLastPathComponent(), withIntermediateDirectories: true)
        let staging = target.deletingLastPathComponent().appendingPathComponent(".mount-" + UUID().uuidString)
        try manager.createDirectory(at: staging, withIntermediateDirectories: false)
        defer { if manager.fileExists(atPath: staging.path) { try? manager.removeItem(at: staging) } }
        guard let entries = manager.enumerator(at: base, includingPropertiesForKeys: [.isDirectoryKey, .isRegularFileKey, .isSymbolicLinkKey], options: [.skipsHiddenFiles]) else {
            throw ContentError.invalid("Cannot enumerate base game")
        }
        var casing: [String: String] = [:]
        func copy(_ source: URL, _ output: URL) throws {
            try manager.createDirectory(at: output.deletingLastPathComponent(), withIntermediateDirectories: true)
            #if canImport(Darwin)
            // Clone on APFS so a mount costs no extra disk.
            if copyfile(source.path, output.path, nil, copyfile_flags_t(COPYFILE_DATA | COPYFILE_CLONE)) != 0 {
                throw ContentError.invalid("Cannot copy content resource: \(source.lastPathComponent), errno \(errno)")
            }
            #else
            do { try manager.copyItem(at: source, to: output) } catch {
                throw ContentError.invalid("Cannot copy content resource: \(source.lastPathComponent), \(error.localizedDescription)")
            }
            #endif
        }
        for case let file as URL in entries {
            let properties = try file.resourceValues(forKeys: [.isDirectoryKey, .isRegularFileKey, .isSymbolicLinkKey])
            guard properties.isSymbolicLink != true else { throw ContentError.invalid("Base game contains a symbolic link: \(file.path)") }
            let resolved = file.resolvingSymlinksInPath().standardizedFileURL
            guard resolved.path.hasPrefix(base.path + "/") else { throw ContentError.invalid("Base resource escapes game directory") }
            let relative = String(resolved.path.dropFirst(base.path.count + 1))
            let key = try resourceKey(relative)
            guard casing[key] == nil else { throw ContentError.invalid("Base game has duplicate normalized paths: \(relative)") }
            casing[key] = relative
            let output = staging.appendingPathComponent(relative)
            if properties.isDirectory == true {
                try manager.createDirectory(at: output, withIntermediateDirectories: true)
            } else if properties.isRegularFile == true {
                try copy(file, output)
            }
        }
        for (key, source) in packs.assets.sorted(by: { $0.key < $1.key }) {
            let components = key.split(separator: "/").map(String.init)
            var relative = ""
            var prefix = ""
            for component in components {
                prefix = prefix.isEmpty ? component : prefix + "/" + component
                relative = casing[prefix] ?? (relative.isEmpty ? component : relative + "/" + component)
            }
            let output = staging.appendingPathComponent(relative)
            if manager.fileExists(atPath: output.path) { try manager.removeItem(at: output) }
            try copy(source, output)
        }
        let report = try packs.report()
        // Plugins run from an immutable copy in the session mount; the simulation re-hashes it against the trust store.
        for (plugin, pack) in zip(report.plugins ?? [], packs.ordered.filter { $0.pluginAssembly != nil }) {
            guard let assembly = pack.pluginAssembly, pack.manifest.id == plugin.packID else { throw ContentError.invalid("Plugin report does not match its pack") }
            let folder = staging.appendingPathComponent(plugin.assembly).deletingLastPathComponent()
            for file in try pluginPayload(in: assembly.deletingLastPathComponent()) {
                try copy(file, folder.appendingPathComponent(file.lastPathComponent))
            }
            guard try pluginDigest(in: folder) == plugin.sha256 else { throw ContentError.invalid("Plugin \(plugin.packID) changed while its content mount was prepared") }
        }
        let plugins: [[String: Any]] = (report.plugins ?? []).map {
            ["packId": $0.packID, "version": $0.version, "assembly": $0.assembly, "sha256": $0.sha256,
             "entryType": $0.entryType, "apiVersion": $0.apiVersion, "stateVersion": $0.stateVersion]
        }
        let panels: [[String: Any]] = (report.panels ?? []).map { ["packId": $0.packID, "id": $0.id, "path": $0.path, "sha256": $0.sha256] }
        let details: [[String: Any]] = (report.packDetails ?? []).map { ["id": $0.id, "version": $0.version, "migratesFrom": $0.migratesFrom] }
        // The simulation checks these objects' animation references once the engine has loaded them.
        let objects: [[String: Any]] = report.objects.map { ["guid": $0.guid, "owner": $0.owner] }
        let metadata: [String: Any] = ["schemaVersion": report.schemaVersion, "baseGameVersion": report.baseGameVersion, "packs": report.packs, "fingerprint": report.fingerprint,
                                       "plugins": plugins, "panels": panels, "packDetails": details, "objects": objects]
        try JSONSerialization.data(withJSONObject: metadata, options: [.prettyPrinted, .sortedKeys]).write(to: staging.appendingPathComponent(".native-pack-stack.json"))
        try manager.moveItem(at: staging, to: target)
    }
}
