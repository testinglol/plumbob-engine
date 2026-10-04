import Foundation

public struct HouseholdAppearancePreview: Decodable {
    public let schemaVersion: Int
    public let width: Float
    public let height: Float
    public let textures: [LotScene.Texture]
    public let meshes: [LotScene.Mesh]

    public func validate() throws {
        guard schemaVersion == 1, width == 1, height == 1,
              (1...32).contains(textures.count), (1...32).contains(meshes.count) else {
            throw ContentError.invalid("Invalid household appearance preview header")
        }
        var textureBudget = 128 * 1024 * 1024
        for texture in textures {
            let components = texture.file.split(separator: "/", omittingEmptySubsequences: false)
            guard !texture.file.hasPrefix("/"), !texture.file.contains("\\"),
                  !texture.file.unicodeScalars.contains(where: CharacterSet.controlCharacters.contains),
                  texture.file.utf16.count <= 1024, !components.isEmpty,
                  components.allSatisfy({ !$0.isEmpty && $0 != "." && $0 != ".." }),
                  texture.width > 0, texture.height > 0, texture.width <= 4096, texture.height <= 4096,
                  ["bmp", "tga"].contains(texture.encoding ?? "") else {
                throw ContentError.invalid("Invalid household preview texture")
            }
            textureBudget -= texture.width * texture.height * 4
            guard textureBudget >= 0 else { throw ContentError.invalid("Household preview textures exceed the memory limit") }
        }
        var vertexCount = 0
        for mesh in meshes {
            vertexCount += mesh.vertices.count
            guard textures.indices.contains(mesh.texture), mesh.objectID == 0, mesh.depth.isFinite,
                  mesh.layer == 1, mesh.roof == nil, mesh.floor == nil, mesh.unlit != true,
                  !mesh.vertices.isEmpty, mesh.vertices.count.isMultiple(of: 3), vertexCount <= 250_000 else {
                throw ContentError.invalid("Invalid household preview mesh")
            }
            for vertex in mesh.vertices {
                guard [vertex.x, vertex.y, vertex.z, vertex.u, vertex.v, vertex.nx, vertex.ny, vertex.nz].allSatisfy(\.isFinite),
                      (0...1).contains(vertex.x), (0...1).contains(vertex.y), (0...1).contains(vertex.z),
                      abs(vertex.u) <= 16, abs(vertex.v) <= 16,
                      abs(vertex.nx) <= 1.01, abs(vertex.ny) <= 1.01, abs(vertex.nz) <= 1.01 else {
                    throw ContentError.invalid("Invalid household preview vertex")
                }
            }
        }
    }

    public static func load(from url: URL) throws -> (preview: HouseholdAppearancePreview, pixels: [Data]) {
        let attributes = try FileManager.default.attributesOfItem(atPath: url.path)
        guard (attributes[.size] as? NSNumber)?.intValue ?? Int.max <= 16 * 1024 * 1024 else {
            throw ContentError.invalid("Household appearance preview exceeds 16 MiB")
        }
        let preview = try JSONDecoder().decode(HouseholdAppearancePreview.self, from: Data(contentsOf: url))
        try preview.validate()
        let root = url.deletingLastPathComponent().resolvingSymlinksInPath().standardizedFileURL
        return (preview, try LotScene.readPixels(textures: preview.textures, root: root))
    }
}
