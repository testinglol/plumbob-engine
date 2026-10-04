import Foundation

extension PackStack {
    static func avatarContainerName(_ path: String) -> String? {
        let parts = path.components(separatedBy: "::")
        guard let name = parts.last?.split(separator: "/").last.map(String.init),
              name.hasSuffix(".cmx") || name.hasSuffix(".bcf") || name.hasSuffix(".cfp") else { return nil }
        if parts.count == 2 { return name }
        if name.hasSuffix(".cmx"), path.hasPrefix("gamedata/skins/") || path.hasPrefix("expansionshared/skinsbuy/") { return name }
        return path.hasPrefix("downloads/") ? name : nil
    }

    static func avatarResources(assets: [String: URL], owners: [String: String]) throws -> (definitions: [PackAvatarResource], containers: [String: String]) {
        var definitions: [PackAvatarResource] = []
        var containers: [String: String] = [:]
        var symbols: [String: PackAvatarResource] = [:]
        func collect(_ data: Data, path: String, owner: String) throws {
            guard path.hasSuffix(".cmx") || path.hasSuffix(".bcf") || path.hasSuffix(".cfp") else { return }
            guard let name = avatarContainerName(path), !name.contains("globals") else {
                throw ContentError.invalid("Avatar container \(path) is outside the engine lookup. Put CMX under GameData/Skins, ExpansionShared/SkinsBuy or Downloads; put loose BCF/CFP under Downloads; avoid filenames containing globals")
            }
            if let previous = containers[name] {
                throw ContentError.invalid("Avatar container filename \(name) conflicts: \(previous) and \(path). Use a unique filename or override the same resource path")
            }
            containers[name] = path
            guard !name.hasSuffix(".cfp") else { return }
            for definition in try AvatarContainer.read(data, path: path, owner: owner) {
                let symbol = definition.kind + ":" + definition.name
                if let previous = symbols[symbol] {
                    throw ContentError.invalid("Avatar \(symbol) conflicts: \(previous.owner):\(previous.path) and \(owner):\(path). Use a unique internal name or replace the same resource container")
                }
                symbols[symbol] = definition
                definitions.append(definition)
            }
        }
        for (path, source) in assets.sorted(by: { $0.key < $1.key }) {
            if path.hasSuffix(".far") {
                let archive = try FARArchive(url: source)
                for entry in archive.entries.keys.sorted() where entry.hasSuffix(".cmx") || entry.hasSuffix(".bcf") || entry.hasSuffix(".cfp") {
                    try collect(archive.read(entry), path: path + "::" + entry, owner: owners[path]!)
                }
            } else if path.hasSuffix(".cmx") || path.hasSuffix(".bcf") || path.hasSuffix(".cfp") {
                try collect(Data(contentsOf: source), path: path, owner: owners[path]!)
            }
        }
        return (definitions.sorted { ($0.kind, $0.name) < ($1.kind, $1.name) }, containers)
    }

    func validateBaseAvatarResources(at base: URL) throws {
        guard !avatarContainers.isEmpty else { return }
        let symbols = Dictionary(uniqueKeysWithValues: avatarResources.map { ($0.kind + ":" + $0.name, $0) })
        var declarations: [String: Set<String>] = [:]
        for pack in ordered { declarations[pack.manifest.id] = try Set(pack.manifest.overrides.map(resourceKey)) }
        let owners = Dictionary(ordered.flatMap { pack in pack.assets.keys.map { ($0, pack.manifest.id) } }, uniquingKeysWith: { _, last in last })
        func check(_ data: Data, path: String) throws {
            guard let name = Self.avatarContainerName(path), !name.contains("globals") else { return }
            if let replacement = avatarContainers[name] {
                let parts = replacement.components(separatedBy: "::")
                if parts.count == 1, declarations[owners[replacement]!]!.contains(replacement) {
                    guard path.contains("::") || replacement == path else {
                        throw ContentError.invalid("Avatar container filename \(name) conflicts with loose base path \(path). Replace the original loose path instead of \(replacement)")
                    }
                    return
                }
                throw ContentError.invalid("Avatar container filename \(name) conflicts: base:\(path) and \(replacement). Declare an explicit loose replacement with the same filename or replace the original FAR container")
            }
            guard !name.hasSuffix(".cfp"), !symbols.isEmpty else { return }
            for original in try AvatarContainer.read(data, path: path, owner: "base", allowDuplicates: true) {
                let symbol = original.kind + ":" + original.name
                if let replacement = symbols[symbol] {
                    throw ContentError.invalid("Avatar \(symbol) conflicts: base:\(path) and \(replacement.owner):\(replacement.path). Use a unique internal name or explicitly replace the original resource container")
                }
            }
        }
        guard let files = FileManager.default.enumerator(at: base, includingPropertiesForKeys: [.isRegularFileKey], options: [.skipsHiddenFiles]) else {
            throw ContentError.invalid("Cannot enumerate base avatar resources")
        }
        for case let file as URL in files {
            guard try file.resourceValues(forKeys: [.isRegularFileKey]).isRegularFile == true else { continue }
            let resolved = file.resolvingSymlinksInPath().standardizedFileURL
            guard resolved.path.hasPrefix(base.path + "/") else { throw ContentError.invalid("Base avatar resource escapes game directory") }
            let path = try resourceKey(String(resolved.path.dropFirst(base.path.count + 1)))
            guard assets[path] == nil else { continue }
            if path.hasSuffix(".far") {
                let archive = try FARArchive(url: file)
                for entry in archive.entries.keys.sorted() where entry.hasSuffix(".cmx") || entry.hasSuffix(".bcf") || entry.hasSuffix(".cfp") {
                    try check(archive.read(entry), path: path + "::" + entry)
                }
            } else if Self.avatarContainerName(path) != nil { try check(Data(contentsOf: file), path: path) }
        }
    }
}
