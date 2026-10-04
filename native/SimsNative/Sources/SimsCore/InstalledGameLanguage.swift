import Foundation

public struct InstalledGameLanguage: Equatable, Sendable {
    public let code: Int
    public let name: String
    public let windowsLanguageID: UInt16?

    public static let englishUS = InstalledGameLanguage(code: 1, name: "English (US)", windowsLanguageID: nil)

    public static func detect(in gameRoot: URL) -> InstalledGameLanguage {
        guard let data = try? Data(contentsOf: gameRoot.appendingPathComponent("Sims.exe")),
              let language = parse(executable: data) else { return .englishUS }
        return language
    }

    static func parse(executable data: Data) -> InstalledGameLanguage? {
        guard let languageIDs = PEVersionLanguages(data: data)?.resourceLanguageIDs else { return nil }
        let supported: [(UInt16, Int, String)] = [
            (0x0409, 1, "English (US)"), (0x0809, 2, "English (UK)"),
            (0x040c, 3, "French"), (0x080c, 3, "French"), (0x100c, 3, "French"),
            (0x0407, 4, "German"), (0x0807, 4, "German"), (0x0c07, 4, "German"),
            (0x0410, 5, "Italian"), (0x0810, 5, "Italian"),
            (0x040a, 6, "Spanish"), (0x0c0a, 6, "Spanish"),
            (0x0413, 7, "Dutch"), (0x0813, 7, "Dutch"),
            (0x0406, 8, "Danish"), (0x041d, 9, "Swedish"), (0x0414, 10, "Norwegian"),
            (0x040b, 11, "Finnish"), (0x040d, 12, "Hebrew"), (0x0419, 13, "Russian"),
            (0x0816, 14, "Portuguese"), (0x0416, 14, "Portuguese"),
            (0x0411, 15, "Japanese"), (0x0415, 16, "Polish"),
            (0x0804, 17, "Simplified Chinese"), (0x1004, 17, "Simplified Chinese"),
            (0x0404, 18, "Traditional Chinese"), (0x0c04, 18, "Traditional Chinese"), (0x1404, 18, "Traditional Chinese"),
            (0x041e, 19, "Thai"), (0x0412, 20, "Korean")
        ]
        for (windowsID, code, name) in supported where languageIDs.contains(windowsID) {
            return InstalledGameLanguage(code: code, name: name, windowsLanguageID: windowsID)
        }
        return nil
    }
}

private struct PEVersionLanguages {
    private struct Section {
        let virtualAddress: UInt32
        let virtualSize: UInt32
        let rawOffset: UInt32
        let rawSize: UInt32
    }

    private let data: Data
    private let sections: [Section]
    let resourceLanguageIDs: Set<UInt16>

    init?(data: Data) {
        self.data = data
        guard data.count >= 0x40,
              data[0] == 0x4d, data[1] == 0x5a,
              let peOffsetValue = Self.u32(data, at: 0x3c),
              let peOffset = Int(exactly: peOffsetValue),
              Self.matches(data, at: peOffset, bytes: [0x50, 0x45, 0, 0]),
              let sectionCount = Self.u16(data, at: peOffset + 6),
              let optionalSize = Self.u16(data, at: peOffset + 20),
              let optionalStart = Self.add(peOffset, 24),
              let magic = Self.u16(data, at: optionalStart) else { return nil }
        let directoriesOffset: Int
        let directoryCountOffset: Int
        if magic == 0x10b {
            directoriesOffset = optionalStart + 96
            directoryCountOffset = optionalStart + 92
        } else if magic == 0x20b {
            directoriesOffset = optionalStart + 112
            directoryCountOffset = optionalStart + 108
        } else {
            return nil
        }
        guard let directoryCount = Self.u32(data, at: directoryCountOffset), directoryCount > 2,
              directoriesOffset + 24 <= optionalStart + Int(optionalSize),
              let resourceRVA = Self.u32(data, at: directoriesOffset + 16), resourceRVA != 0,
              let sectionTable = Self.add(optionalStart, Int(optionalSize)) else { return nil }
        var parsedSections: [Section] = []
        for index in 0..<Int(sectionCount) {
            guard let header = Self.add(sectionTable, index * 40),
                  let virtualSize = Self.u32(data, at: header + 8),
                  let virtualAddress = Self.u32(data, at: header + 12),
                  let rawSize = Self.u32(data, at: header + 16),
                  let rawOffset = Self.u32(data, at: header + 20) else { return nil }
            parsedSections.append(Section(virtualAddress: virtualAddress, virtualSize: virtualSize, rawOffset: rawOffset, rawSize: rawSize))
        }
        sections = parsedSections
        guard let rootOffset = Self.rvaToOffset(resourceRVA, sections: parsedSections, dataCount: data.count) else { return nil }
        resourceLanguageIDs = Self.versionLanguages(data: data, rootOffset: rootOffset, sections: parsedSections)
    }

    private static func versionLanguages(data: Data, rootOffset: Int, sections: [Section]) -> Set<UInt16> {
        guard let types = directoryEntries(data, at: rootOffset),
              let version = types.first(where: { !$0.named && $0.id == 16 && $0.directory }) else { return [] }
        let versionDirectory = rootOffset + version.offset
        guard let resources = directoryEntries(data, at: versionDirectory) else { return [] }
        var languageIDs = Set<UInt16>()
        for resource in resources where resource.directory {
            guard let languages = directoryEntries(data, at: rootOffset + resource.offset) else { continue }
            for language in languages where !language.named && !language.directory {
                let entry = rootOffset + language.offset
                guard let resourceDataRVA = u32(data, at: entry),
                      let resourceDataSize = u32(data, at: entry + 4), resourceDataSize >= 6,
                      rvaToOffset(resourceDataRVA, sections: sections, dataCount: data.count) != nil else { continue }
                languageIDs.insert(language.id)
            }
        }
        return languageIDs
    }

    private struct DirectoryEntry {
        let id: UInt16
        let named: Bool
        let directory: Bool
        let offset: Int
    }

    private static func directoryEntries(_ data: Data, at offset: Int) -> [DirectoryEntry]? {
        guard let namedCount = u16(data, at: offset + 12),
              let idCount = u16(data, at: offset + 14) else { return nil }
        let count = Int(namedCount) + Int(idCount)
        guard count <= 4096, let entriesStart = add(offset, 16),
              let end = add(entriesStart, count * 8), end <= data.count else { return nil }
        var result: [DirectoryEntry] = []
        for index in 0..<count {
            let entry = entriesStart + index * 8
            guard let name = u32(data, at: entry), let target = u32(data, at: entry + 4) else { return nil }
            let named = name & 0x8000_0000 != 0
            let directory = target & 0x8000_0000 != 0
            let rawID = UInt16(truncatingIfNeeded: name)
            let child = Int(target & 0x7fff_ffff)
            result.append(DirectoryEntry(id: rawID, named: named, directory: directory, offset: child))
        }
        return result
    }

    private func rvaToOffset(_ rva: UInt32) -> Int? {
        Self.rvaToOffset(rva, sections: sections, dataCount: data.count)
    }

    private static func rvaToOffset(_ rva: UInt32, sections: [Section], dataCount: Int) -> Int? {
        for section in sections {
            let extent = max(section.virtualSize, section.rawSize)
            guard rva >= section.virtualAddress, rva - section.virtualAddress < extent else { continue }
            let delta = rva - section.virtualAddress
            guard delta < section.rawSize,
                  let raw = add(Int(section.rawOffset), Int(delta)), raw < dataCount else { return nil }
            return raw
        }
        return nil
    }

    private static func matches(_ data: Data, at offset: Int, bytes: [UInt8]) -> Bool {
        guard offset >= 0, let end = add(offset, bytes.count), end <= data.count else { return false }
        return bytes.indices.allSatisfy { data[offset + $0] == bytes[$0] }
    }

    private static func u16(_ data: Data, at offset: Int) -> UInt16? {
        guard offset >= 0, let end = add(offset, 2), end <= data.count else { return nil }
        return UInt16(data[offset]) | UInt16(data[offset + 1]) << 8
    }

    private static func u32(_ data: Data, at offset: Int) -> UInt32? {
        guard offset >= 0, let end = add(offset, 4), end <= data.count else { return nil }
        return UInt32(data[offset]) | UInt32(data[offset + 1]) << 8 | UInt32(data[offset + 2]) << 16 | UInt32(data[offset + 3]) << 24
    }

    private static func add(_ left: Int, _ right: Int) -> Int? {
        let (value, overflow) = left.addingReportingOverflow(right)
        return overflow ? nil : value
    }
}
