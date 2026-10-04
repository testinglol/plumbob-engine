import Foundation

public struct PackObjectDefinition: Codable, Sendable {
    public let guid: UInt32
    public let chunkID: UInt16
    public let path: String
    public let owner: String
}

extension PackStack {
    static func objectResourceName(_ path: String) -> String? {
        let parts = path.components(separatedBy: "::")
        guard parts.count == 2 || path.hasPrefix("downloads/"),
              let name = parts.last?.split(separator: "/").last.map(String.init),
              name.hasSuffix(".iff"), !name.contains("globals") else { return nil }
        return name
    }

    static func objectResourceIndex(assets: [String: URL]) throws -> [String: String] {
        var resources: [String: String] = [:]
        func insert(_ path: String) throws {
            guard let name = objectResourceName(path) else { return }
            if let previous = resources[name] {
                throw ContentError.invalid("Object resource name \(name) conflicts: \(previous) and \(path). Use a unique filename or an explicit override at the same resource path")
            }
            resources[name] = path
        }
        for (path, source) in assets.sorted(by: { $0.key < $1.key }) {
            if path.hasSuffix(".far") {
                for entry in try FARArchive(url: source).entries.keys.sorted() { try insert(path + "::" + entry) }
            } else { try insert(path) }
        }
        return resources
    }

    static func objectDefinitions(assets: [String: URL], owners: [String: String]) throws -> [PackObjectDefinition] {
        var definitions: [PackObjectDefinition] = []
        var identities: [UInt32: PackObjectDefinition] = [:]
        func collect(_ data: Data, path: String, owner: String) throws {
            for definition in try readObjects(data, path: path, owner: owner) {
                guard objectResourceName(path) != nil else {
                    throw ContentError.invalid("Object definition \(path) is outside the engine's object lookup. Put loose object IFF files under Downloads or inside a FAR archive, and avoid filenames containing globals")
                }
                if let previous = identities[definition.guid] {
                    let guid = String(format: "0x%08X", definition.guid)
                    throw ContentError.invalid("Object GUID \(guid) conflicts: \(previous.owner):\(previous.path)#\(previous.chunkID) and \(owner):\(path)#\(definition.chunkID). Give new objects unique GUIDs; replace existing objects at the same resource path with an explicit override")
                }
                identities[definition.guid] = definition
                definitions.append(definition)
            }
        }
        for (path, source) in assets.sorted(by: { $0.key < $1.key }) {
            let owner = owners[path]!
            if path.hasSuffix(".iff") {
                try collect(Data(contentsOf: source, options: .mappedIfSafe), path: path, owner: owner)
            } else if path.hasSuffix(".far") {
                let archive = try FARArchive(url: source)
                for entry in archive.entries.keys.sorted() where entry.hasSuffix(".iff") {
                    try collect(archive.read(entry), path: path + "::" + entry, owner: owner)
                }
            }
        }
        return definitions.sorted { $0.guid < $1.guid }
    }

    func validateBaseObjects(at base: URL, collectAll: Bool = false) throws -> Set<UInt32> {
        guard collectAll || !objectResources.isEmpty || !reservations.isEmpty else { return [] }
        let custom = Dictionary(uniqueKeysWithValues: objects.map { ($0.guid, $0) })
        let reserved = Dictionary(uniqueKeysWithValues: reservations.map { ($0.guid, $0) })
        var identities: Set<UInt32> = []
        guard let files = FileManager.default.enumerator(at: base, includingPropertiesForKeys: [.isRegularFileKey], options: [.skipsHiddenFiles]) else {
            throw ContentError.invalid("Cannot enumerate base object resources")
        }
        func check(_ data: Data, path: String, validate: Bool) throws {
            for original in try Self.readObjects(data, path: path, owner: "base", allowZero: true) {
                identities.insert(original.guid)
                guard validate else { continue }
                if let replacement = custom[original.guid] {
                    throw ContentError.invalid("Object GUID \(String(format: "0x%08X", original.guid)) conflicts: base:\(original.path)#\(original.chunkID) and \(replacement.owner):\(replacement.path)#\(replacement.chunkID). Declare an override at the original resource path or assign a unique GUID")
                }
                if let reservation = reserved[original.guid] {
                    throw ContentError.invalid("Reserved object GUID \(String(format: "0x%08X", original.guid)) conflicts: base:\(original.path) and \(reservation.owner):\(reservation.name)")
                }
            }
            if validate, let name = Self.objectResourceName(path), let replacement = objectResources[name] {
                throw ContentError.invalid("Object resource name \(name) conflicts: base:\(path) and \(replacement). Use a unique filename or declare an override at the original resource path")
            }
        }
        for case let file as URL in files {
            guard try file.resourceValues(forKeys: [.isRegularFileKey]).isRegularFile == true else { continue }
            let resolved = file.resolvingSymlinksInPath().standardizedFileURL
            guard resolved.path.hasPrefix(base.path + "/") else { throw ContentError.invalid("Base object resource escapes game directory") }
            let path = try resourceKey(String(resolved.path.dropFirst(base.path.count + 1)))
            guard collectAll || assets[path] == nil else { continue }
            if path.hasSuffix(".far") {
                let archive = try FARArchive(url: resolved)
                for entry in archive.entries.keys.sorted() where entry.hasSuffix(".iff") && !entry.split(separator: "/").last!.contains("globals") {
                    try check(archive.read(entry), path: path + "::" + entry, validate: assets[path] == nil)
                }
            } else if path.hasPrefix("downloads/") && path.hasSuffix(".iff") && !file.lastPathComponent.lowercased().contains("globals") {
                try check(Data(contentsOf: resolved, options: .mappedIfSafe), path: path, validate: assets[path] == nil)
            }
        }
        return identities
    }

    private static func readObjects(_ data: Data, path: String, owner: String, allowZero: Bool = false) throws -> [PackObjectDefinition] {
        guard data.count >= 64,
              let header = String(data: data.prefix(60), encoding: .ascii)?.replacingOccurrences(of: "\0", with: ""),
              ["IFF FILE 2.5:TYPE FOLLOWED BY SIZE JAMIE DOORNBOS & MAXIS 1", "IFF FILE 2.0:TYPE FOLLOWED BY SIZE JAMIE DOORNBOS & MAXIS 1"].contains(header) else {
            throw ContentError.invalid("Invalid pack IFF header: \(path)")
        }
        func integer(_ offset: Int, bytes: Int, bigEndian: Bool) -> UInt32 {
            (0..<bytes).reduce(UInt32(0)) { value, index in
                value | UInt32(data[offset + index]) << ((bigEndian ? bytes - index - 1 : index) * 8)
            }
        }
        var offset = 64
        var result: [PackObjectDefinition] = []
        while offset < data.count {
            guard data.count - offset >= 76 else { throw ContentError.invalid("Truncated pack IFF chunk: \(path)") }
            let size = Int(integer(offset + 4, bytes: 4, bigEndian: true))
            guard size >= 76 && size <= data.count - offset else { throw ContentError.invalid("Invalid pack IFF chunk size: \(path)") }
            if data.subdata(in: offset..<(offset + 4)) == Data("OBJD".utf8) {
                guard size >= 80 else { throw ContentError.invalid("Truncated object definition: \(path)") }
                let payload = offset + 76
                let version = integer(payload, bytes: 4, bigEndian: false)
                let sizes: [UInt32: Int] = [136: 160, 138: 190, 139: 192, 140: 194, 141: 194, 142: 210]
                guard let minimum = sizes[version], size - 76 >= minimum else {
                    throw ContentError.invalid("Unsupported or truncated OBJD version \(version): \(path)")
                }
                let guid = integer(payload + 28, bytes: 4, bigEndian: false)
                if guid == 0 && allowZero { offset += size; continue }
                guard guid != 0 else { throw ContentError.invalid("Pack object GUID cannot be zero: \(path)") }
                result.append(PackObjectDefinition(guid: guid, chunkID: UInt16(integer(offset + 8, bytes: 2, bigEndian: true)), path: path, owner: owner))
            }
            offset += size
        }
        return result
    }
}
