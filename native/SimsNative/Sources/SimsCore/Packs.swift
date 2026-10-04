import Foundation

private func skinIdentity(_ name: String) -> String? {
    let ext = name.split(separator: ".").last.map(String.init) ?? ""
    let stem = String(name.dropLast(ext.count + 1))
    switch ext {
    case "bmp", "tga": return "texture:" + stem
    case "skn", "bmf": return "mesh:" + stem
    case "cmx", "bcf", "cfp": return name
    default: return nil
    }
}

private func skinName(_ key: String) -> String? {
    guard key.hasPrefix("gamedata/skins/") || key.hasPrefix("expansionshared/skinsbuy/") else { return nil }
    return key.split(separator: "/").last.flatMap { skinIdentity(String($0)) }
}

public struct PackManifest: Codable, Sendable {
    public struct Dependency: Codable, Sendable {
        public let id: String
        public let version: String
    }

    public let schemaVersion: Int
    public let id: String
    public let name: String
    public let version: String
    public let baseGameVersion: String
    public let dependencies: [Dependency]
    public let overrides: [String]
    public var objectGUIDs: [String: UInt32]? = nil
    /// Code-bearing gameplay plugin; loaded only after an explicit local trust action.
    public var plugin: PluginDeclaration? = nil
    /// Pack-relative declarative panel descriptions under `panels/`.
    public var panels: [String]? = nil
    /// Earlier pack versions whose native saves this version accepts.
    public var saveMigration: SaveMigration? = nil
}

public struct ContentPack: Sendable {
    public let directory: URL
    let manifestData: Data
    public let manifest: PackManifest
    public let assets: [String: URL]
    public let pluginAssembly: URL?
    public let panelFiles: [(path: String, url: URL, description: PanelDescription)]

    public init(directory: URL) throws {
        self.directory = directory.resolvingSymlinksInPath().standardizedFileURL
        manifestData = try Data(contentsOf: directory.appendingPathComponent("pack.json"))
        manifest = try JSONDecoder().decode(PackManifest.self, from: manifestData)
        guard manifest.schemaVersion == 1 && manifest.baseGameVersion == "1.90",
              !manifest.id.isEmpty && manifest.id.allSatisfy({ $0.isASCII && ($0.isLetter || $0.isNumber || $0 == "-" || $0 == ".") }),
              !manifest.version.isEmpty && !manifest.name.isEmpty else {
            throw ContentError.invalid("Unsupported pack manifest in \(directory.lastPathComponent)")
        }
        let files = directory.appendingPathComponent("files", isDirectory: true).standardizedFileURL.resolvingSymlinksInPath()
        let packRoot = directory.standardizedFileURL.resolvingSymlinksInPath().path + "/"
        guard files.path.hasPrefix(packRoot) else {
            throw ContentError.invalid("Pack files directory escapes its pack")
        }
        guard FileManager.default.fileExists(atPath: files.path) else {
            throw ContentError.invalid("Pack \(manifest.id) has no files directory")
        }
        let canonicalRoot = files.resolvingSymlinksInPath().path + "/"
        guard let enumerator = FileManager.default.enumerator(at: files, includingPropertiesForKeys: [.isRegularFileKey], options: [.skipsHiddenFiles]) else {
            throw ContentError.invalid("Cannot enumerate pack \(manifest.id)")
        }
        let extensions: Set<String> = ["iff", "far", "flr", "wll", "bmp", "png", "tga", "jpg", "jpeg", "skn", "cmx", "bcf", "cfp", "hit", "hot", "hsm", "wav", "mp3", "xa", "fnt", "pal", "rt", "txt", "bmf", "bco"]
        let roots: Set<String> = ["gamedata", "uigraphics", "downloads", "sounddata", "music", "expansionshared"]
        var assets: [String: URL] = [:]
        for case let file as URL in enumerator {
            let resolvedFile = file.resolvingSymlinksInPath()
            guard resolvedFile.path.hasPrefix(canonicalRoot) else {
                throw ContentError.invalid("Pack resource escapes its directory: \(file.lastPathComponent)")
            }
            let values = try file.resourceValues(forKeys: [.isRegularFileKey])
            guard values.isRegularFile == true else { continue }
            let relative = String(resolvedFile.path.dropFirst(canonicalRoot.count))
            let key = try resourceKey(relative)
            guard let root = key.split(separator: "/").first, roots.contains(String(root)),
                  extensions.contains(file.pathExtension.lowercased()) else {
                throw ContentError.invalid("Unsupported pack asset: \(relative)")
            }
            guard assets[key] == nil else { throw ContentError.invalid("Pack has duplicate resource: \(relative)") }
            assets[key] = file
        }
        for path in manifest.overrides {
            guard assets[try resourceKey(path)] != nil else {
                throw ContentError.invalid("Pack override does not name a supplied resource: \(path)")
            }
        }
        self.assets = assets
        let validatedRoot = self.directory
        let packID = manifest.id
        pluginAssembly = try manifest.plugin.map { try Self.validatedPlugin($0, packID: packID, root: validatedRoot) }
        panelFiles = try Self.validatedPanels(manifest.panels ?? [], packID: packID, root: validatedRoot)
        if let migration = manifest.saveMigration {
            guard !migration.from.isEmpty, migration.from.count <= 64,
                  migration.from.allSatisfy({ !$0.isEmpty && $0.count <= 32 && $0 != manifest.version }) else {
                throw ContentError.invalid("Pack \(manifest.id) has an invalid saveMigration list")
            }
        }
    }
}

public struct PackStack: Sendable {
    public let ordered: [ContentPack]
    public let assets: [String: URL]
    public let objects: [PackObjectDefinition]
    public let avatarResources: [PackAvatarResource]
    let avatarContainers: [String: String]
    public let reservations: [ObjectGUIDReservation]
    let objectResources: [String: String]

    public init(packs: [ContentPack]) throws {
        var byID: [String: ContentPack] = [:]
        for pack in packs {
            guard byID[pack.manifest.id] == nil else { throw ContentError.invalid("Duplicate pack ID: \(pack.manifest.id)") }
            byID[pack.manifest.id] = pack
        }
        var pending = Set(byID.keys)
        var complete = Set<String>()
        var ordered: [ContentPack] = []
        while !pending.isEmpty {
            var progress = false
            for id in pending.sorted() {
                let pack = byID[id]!
                for dependency in pack.manifest.dependencies {
                    guard let required = byID[dependency.id],
                          dependency.version == "*" || required.manifest.version == dependency.version else {
                        throw ContentError.invalid("Pack \(id) requires \(dependency.id) version \(dependency.version)")
                    }
                }
                if pack.manifest.dependencies.allSatisfy({ complete.contains($0.id) }) {
                    ordered.append(pack)
                    pending.remove(id)
                    complete.insert(id)
                    progress = true
                }
            }
            guard progress else { throw ContentError.invalid("Pack dependencies contain a cycle") }
        }
        var resources: [String: URL] = [:]
        var owners: [String: String] = [:]
        var skinPaths: [String: String] = [:]
        for pack in ordered {
            let declared = try Set(pack.manifest.overrides.map(resourceKey))
            for (key, file) in pack.assets {
                if let name = skinName(key) {
                    guard skinPaths[name] == nil || skinPaths[name] == key else {
                        throw ContentError.invalid("Skin \(name) has conflicting paths; use \(skinPaths[name]!) in every pack")
                    }
                    skinPaths[name] = key
                }
                guard resources[key] == nil || declared.contains(key) else {
                    throw ContentError.invalid("Conflicting pack resource \(key); declare it in overrides")
                }
                resources[key] = file
                owners[key] = pack.manifest.id
            }
        }
        let avatar = try Self.avatarResources(assets: resources, owners: owners)
        self.avatarResources = avatar.definitions
        self.avatarContainers = avatar.containers
        self.objects = try Self.objectDefinitions(assets: resources, owners: owners)
        self.reservations = try ObjectGUIDAllocator.reservations(packs: ordered, objects: self.objects)
        self.objectResources = try Self.objectResourceIndex(assets: resources)
        self.ordered = ordered
        self.assets = resources
    }
}

public struct GameContent: Sendable {
    public let root: URL
    public let language: InstalledGameLanguage
    public let ui: FARArchive
    public let packs: PackStack

    public init(root: URL, packDirectories: [URL] = []) throws {
        let base = root.resolvingSymlinksInPath().standardizedFileURL
        self.root = base
        language = InstalledGameLanguage.detect(in: base)
        ui = try FARArchive(url: base.appendingPathComponent("UIGraphics/UIGraphics.far"))
        packs = try PackStack(packs: packDirectories.map { try ContentPack(directory: $0) })
        _ = try packs.validateBaseObjects(at: base)
        try packs.validateBaseAvatarResources(at: base)
        var archivedSkins: [String: Set<String>] = [:]
        var looseSkins: [String: Set<String>] = [:]
        if packs.assets.keys.contains(where: { skinName($0) != nil }) {
            guard let files = FileManager.default.enumerator(at: base, includingPropertiesForKeys: [.isRegularFileKey], options: [.skipsHiddenFiles]) else {
                throw ContentError.invalid("Cannot enumerate base skin resources")
            }
            for case let file as URL in files {
                guard try file.resourceValues(forKeys: [.isRegularFileKey]).isRegularFile == true else { continue }
                let resolved = file.resolvingSymlinksInPath().standardizedFileURL
                guard resolved.path.hasPrefix(base.path + "/") else { throw ContentError.invalid("Base skin resource escapes game directory") }
                let relative = try resourceKey(String(resolved.path.dropFirst(base.path.count + 1)))
                if let name = skinName(relative) { looseSkins[name, default: []].insert(relative) }
                if file.pathExtension.lowercased() == "far" {
                    let archive = try FARArchive(url: file)
                    for entry in archive.entries.keys {
                        if let filename = entry.split(separator: "/").last.map(String.init), let identity = skinIdentity(filename) {
                            archivedSkins[identity, default: []].insert(filename)
                        }
                    }
                }
            }
        }
        for pack in packs.ordered {
            let declared = try Set(pack.manifest.overrides.map(resourceKey))
            for key in pack.assets.keys {
                let uiKey = String(key.dropFirst("uigraphics/".count))
                let name = skinName(key)
                if let name, let originals = archivedSkins[name], let filename = key.split(separator: "/").last.map(String.init), !originals.contains(filename) {
                    throw ContentError.invalid("Keep the original skin extension when replacing \(name): \(originals.sorted().joined(separator: ", "))")
                }
                if let name, let paths = looseSkins[name], paths.contains(where: { $0 != key }) {
                    throw ContentError.invalid("Skin \(name) conflicts with another base skin path: \(paths.sorted().joined(separator: ", "))")
                }
                let existsInArchive = (key.hasPrefix("uigraphics/") && ui.entries[uiKey] != nil) || (name.map { archivedSkins[$0] != nil } ?? false)
                let existsOnDisk = try diskURL(key) != nil
                guard !existsInArchive && !existsOnDisk || declared.contains(key) else {
                    throw ContentError.invalid("Pack \(pack.manifest.id) replaces a base resource without declaring an override: \(key)")
                }
            }
        }
    }

    private func diskURL(_ path: String) throws -> URL? {
        var current = root
        for part in path.split(separator: "/") {
            let candidates = try FileManager.default.contentsOfDirectory(at: current, includingPropertiesForKeys: nil)
            guard let next = candidates.first(where: { $0.lastPathComponent.lowercased() == part }) else { return nil }
            current = next
        }
        return current
    }

    public func read(_ path: String) throws -> Data {
        let key = try resourceKey(path)
        if let overlay = packs.assets[key] { return try Data(contentsOf: overlay) }
        if let loose = try diskURL(key) { return try Data(contentsOf: loose) }
        if key.hasPrefix("uigraphics/") { return try ui.read(String(key.dropFirst("uigraphics/".count))) }
        throw ContentError.missing("Missing game resource: \(path)")
    }
}
