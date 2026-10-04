import Foundation
import XCTest
@testable import SimsCore

final class InstalledGameLanguageTests: XCTestCase {
    func testDetectsLanguageFromPEVersionResourceDirectory() throws {
        let english = try InstalledGameLanguage.parse(executable: peExecutable(languageID: 0x0409))
        XCTAssertEqual(english?.code, 1)
        XCTAssertEqual(english?.name, "English (US)")
        XCTAssertEqual(english?.windowsLanguageID, 0x0409)

        let italian = try InstalledGameLanguage.parse(executable: peExecutable(languageID: 0x0410))
        XCTAssertEqual(italian?.code, 5)
        XCTAssertEqual(italian?.name, "Italian")
    }

    func testDetectsInstalledExecutableAndFallsBackForUnknownOrMalformedFiles() throws {
        let directory = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString, isDirectory: true)
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: directory) }

        try peExecutable(languageID: 0x040c).write(to: directory.appendingPathComponent("Sims.exe"))
        XCTAssertEqual(InstalledGameLanguage.detect(in: directory).code, 3)

        try Data([0x4d, 0x5a]).write(to: directory.appendingPathComponent("Sims.exe"))
        XCTAssertEqual(InstalledGameLanguage.detect(in: directory), .englishUS)
        let unsupported = try peExecutable(languageID: 0x041b)
        XCTAssertNil(InstalledGameLanguage.parse(executable: unsupported))
    }

    private func peExecutable(languageID: UInt16) throws -> Data {
        var bytes = [UInt8](repeating: 0, count: 0x400)
        put16(0x5a4d, at: 0, in: &bytes)
        put32(0x80, at: 0x3c, in: &bytes)
        bytes.replaceSubrange(0x80..<0x84, with: [0x50, 0x45, 0, 0])
        put16(1, at: 0x86, in: &bytes)
        put16(224, at: 0x94, in: &bytes)

        let optional = 0x98
        put16(0x10b, at: optional, in: &bytes)
        put32(16, at: optional + 92, in: &bytes)
        put32(0x1000, at: optional + 96 + 16, in: &bytes)
        put32(0x100, at: optional + 96 + 20, in: &bytes)

        let section = 0x178
        put32(0x100, at: section + 8, in: &bytes)
        put32(0x1000, at: section + 12, in: &bytes)
        put32(0x200, at: section + 16, in: &bytes)
        put32(0x200, at: section + 20, in: &bytes)

        let root = 0x200
        put16(1, at: root + 14, in: &bytes)
        put32(16, at: root + 16, in: &bytes)
        put32(0x8000_0018, at: root + 20, in: &bytes)

        let versionType = root + 0x18
        put16(1, at: versionType + 14, in: &bytes)
        put32(1, at: versionType + 16, in: &bytes)
        put32(0x8000_0030, at: versionType + 20, in: &bytes)

        let versionName = root + 0x30
        put16(1, at: versionName + 14, in: &bytes)
        put32(UInt32(languageID), at: versionName + 16, in: &bytes)
        put32(0x48, at: versionName + 20, in: &bytes)

        let dataEntry = root + 0x48
        put32(0x1060, at: dataEntry, in: &bytes)
        put32(0x20, at: dataEntry + 4, in: &bytes)
        bytes[0x260] = 0x20
        return Data(bytes)
    }

    private func put16(_ value: UInt16, at offset: Int, in bytes: inout [UInt8]) {
        bytes[offset] = UInt8(truncatingIfNeeded: value)
        bytes[offset + 1] = UInt8(truncatingIfNeeded: value >> 8)
    }

    private func put32(_ value: UInt32, at offset: Int, in bytes: inout [UInt8]) {
        bytes[offset] = UInt8(truncatingIfNeeded: value)
        bytes[offset + 1] = UInt8(truncatingIfNeeded: value >> 8)
        bytes[offset + 2] = UInt8(truncatingIfNeeded: value >> 16)
        bytes[offset + 3] = UInt8(truncatingIfNeeded: value >> 24)
    }
}
