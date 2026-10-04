import Foundation
import CryptoKit
import Darwin

public struct ObjectGUIDReservation: Codable, Sendable {
    public let owner: String
    public let name: String
    public let guid: UInt32
}

public enum ObjectGUIDAllocator {
    public static func validate(name: String) throws {
        guard !name.isEmpty, name.utf8.count <= 128, name == name.lowercased(),
              name.allSatisfy({ $0.isASCII && ($0.isLetter || $0.isNumber || "._-".contains($0)) }) else {
            throw ContentError.invalid("Object identity must use 1..128 lowercase ASCII letters, digits, dots, underscores or hyphens")
        }
    }

    public static func propose(packID: String, name: String, used: Set<UInt32>) throws -> UInt32 {
        try validate(name: name)
        guard !packID.isEmpty else { throw ContentError.invalid("Object allocation requires a pack ID") }
        for attempt in 0..<4096 {
            let hash = SHA256.hash(data: Data(["sims-native-object-v1", packID, name, String(attempt)].joined(separator: "\0").utf8))
            let prefix = hash.prefix(4).reduce(UInt32(0)) { ($0 << 8) | UInt32($1) }
            let candidate = 0xE0000000 | (prefix & 0x0FFFFFFF)
            if !used.contains(candidate) { return candidate }
        }
        throw ContentError.invalid("Object GUID allocation exhausted collision retries")
    }

    static func reservations(packs: [ContentPack], objects: [PackObjectDefinition]) throws -> [ObjectGUIDReservation] {
        var result: [ObjectGUIDReservation] = []
        var owners: [UInt32: ObjectGUIDReservation] = [:]
        let definitions = Dictionary(uniqueKeysWithValues: objects.map { ($0.guid, $0) })
        for pack in packs {
            let entries = pack.manifest.objectGUIDs ?? [:]
            guard entries.count <= 10000 else { throw ContentError.invalid("Pack object reservation limit exceeded") }
            for (name, guid) in entries.sorted(by: { $0.key < $1.key }) {
                try validate(name: name)
                guard guid != 0 else { throw ContentError.invalid("Reserved object GUID cannot be zero") }
                let reservation = ObjectGUIDReservation(owner: pack.manifest.id, name: name, guid: guid)
                if let previous = owners[guid] {
                    throw ContentError.invalid("Reserved object GUID \(String(format: "0x%08X", guid)) conflicts: \(previous.owner):\(previous.name) and \(reservation.owner):\(name)")
                }
                if let definition = definitions[guid], definition.owner != pack.manifest.id {
                    let container = definition.path.components(separatedBy: "::")[0]
                    let replacement = packs.first { $0.manifest.id == definition.owner }
                    let overrides = try Set((replacement?.manifest.overrides ?? []).map(resourceKey))
                    guard pack.assets[container] != nil && overrides.contains(container) else {
                        throw ContentError.invalid("Reserved object GUID belongs to \(definition.owner):\(definition.path)")
                    }
                }
                owners[guid] = reservation
                result.append(reservation)
            }
        }
        return result
    }
}

public extension GameContent {
    func reserveObjectGUID(packID: String, name: String) throws -> ObjectGUIDReservation {
        let reservation = try allocateObjectGUID(packID: packID, name: name)
        guard let pack = packs.ordered.first(where: { $0.manifest.id == packID }) else { throw ContentError.invalid("Missing reservation pack") }
        let path = pack.directory.appendingPathComponent("pack.json")
        guard path.resolvingSymlinksInPath().path.hasPrefix(pack.directory.path + "/") else { throw ContentError.invalid("Reservation manifest escapes its pack") }
        let handle = try FileHandle(forReadingFrom: path)
        defer { try? handle.close() }
        guard flock(handle.fileDescriptor, LOCK_EX) == 0 else { throw ContentError.invalid("Cannot lock object reservation manifest") }
        defer { _ = flock(handle.fileDescriptor, LOCK_UN) }
        guard try Data(contentsOf: path) == pack.manifestData else { throw ContentError.invalid("Pack manifest changed during allocation; reload before reserving an object GUID") }
        if pack.manifest.objectGUIDs?[name] == reservation.guid { return reservation }
        guard var document = try JSONSerialization.jsonObject(with: pack.manifestData) as? [String: Any] else { throw ContentError.invalid("Invalid pack manifest document") }
        var identities = pack.manifest.objectGUIDs ?? [:]
        guard identities.count < 10000 else { throw ContentError.invalid("Pack object reservation limit exceeded") }
        identities[name] = reservation.guid
        document["objectGUIDs"] = identities
        try JSONSerialization.data(withJSONObject: document, options: [.prettyPrinted, .sortedKeys]).write(to: path, options: .atomic)
        return reservation
    }

    func allocateObjectGUID(packID: String, name: String) throws -> ObjectGUIDReservation {
        try ObjectGUIDAllocator.validate(name: name)
        guard packs.ordered.contains(where: { $0.manifest.id == packID }) else { throw ContentError.invalid("Enable the target pack before allocating object GUIDs: \(packID)") }
        if let existing = packs.reservations.first(where: { $0.owner == packID && $0.name == name }) { return existing }
        let originals = try packs.validateBaseObjects(at: root, collectAll: true)
        let used = originals.union(packs.objects.map(\.guid)).union(packs.reservations.map(\.guid))
        return ObjectGUIDReservation(owner: packID, name: name, guid: try ObjectGUIDAllocator.propose(packID: packID, name: name, used: used))
    }
}
