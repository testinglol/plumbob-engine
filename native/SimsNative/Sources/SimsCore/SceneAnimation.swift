import Foundation

public struct SceneAnimation: Decodable {
    public struct Mesh: Decodable {
        public let texture: Int
        public let objectID: Int
        public var room: Int? = nil
        public var level: Int? = nil
        public let depth: Float
        public let vertices: Data

        func unpack() throws -> LotScene.Mesh {
            guard !vertices.isEmpty, vertices.count.isMultiple(of: 96), vertices.count <= 32_000_000 else {
                throw ContentError.invalid("Invalid packed animation triangle count")
            }
            let unpacked = vertices.withUnsafeBytes { bytes -> [LotScene.MeshVertex] in
                func value(_ offset: Int) -> Float {
                    Float(bitPattern: UInt32(littleEndian: bytes.loadUnaligned(fromByteOffset: offset, as: UInt32.self)))
                }
                return stride(from: 0, to: bytes.count, by: 32).map { offset in
                    LotScene.MeshVertex(x: value(offset), y: value(offset + 4), z: value(offset + 8),
                                        u: value(offset + 12), v: value(offset + 16), nx: value(offset + 20),
                                        ny: value(offset + 24), nz: value(offset + 28))
                }
            }
            return LotScene.Mesh(room: room, level: level, texture: texture, objectID: objectID, depth: depth, vertices: unpacked)
        }
    }

    public let schemaVersion: Int
    public var lighting: SceneLighting? = nil
    public let baseRevision: Int64
    public let sequence: Int64
    public let updates: Int64
    public let textureStart: Int
    public let textures: [LotScene.Texture]
    public var sprites: [LotScene.Sprite]
    public var meshes: [Mesh]

    public func applying(to scene: LotScene, revision: Int64, after sequence: Int64) throws -> LotScene {
        guard schemaVersion == 1, baseRevision == revision, self.sequence > sequence, updates >= 0,
              textureStart == scene.textures.count, textures.count + textureStart <= 10000,
              sprites.count <= 100000, meshes.count <= 10000,
              sprites.allSatisfy({ ($0.objectID ?? 0) > 0 }), meshes.allSatisfy({ $0.objectID > 0 }) else {
            throw ContentError.invalid("Animation does not match the current scene")
        }
        var vertexBytes = 0
        for mesh in meshes {
            vertexBytes += mesh.vertices.count
            guard vertexBytes <= 32_000_000 else { throw ContentError.invalid("Animation vertex memory limit exceeded") }
        }
        let retainedSprites = scene.sprites.filter { ($0.objectID ?? 0) == 0 }
        let updatedSprites = retainedSprites + sprites
        let retainedMeshes = (scene.meshes ?? []).filter { $0.objectID == 0 }
        let unpackedMeshes: [LotScene.Mesh] = try meshes.map { try $0.unpack() }
        let updatedMeshes = retainedMeshes + unpackedMeshes
        let updatedTextures = scene.textures + textures
        let result = LotScene(schemaVersion: scene.schemaVersion,
                              lighting: lighting ?? scene.lighting,
                              wallMode: scene.wallMode,
                              cameraOrientation: scene.cameraOrientation,
                              house: scene.house,
                              width: scene.width,
                              height: scene.height,
                              lotWidth: scene.lotWidth,
                              lotHeight: scene.lotHeight,
                              floorDiagonals: scene.floorDiagonals,
                              roofsVisible: scene.roofsVisible,
                              viewLevel: scene.viewLevel,
                              stories: scene.stories,
                              placementVertices: scene.placementVertices,
                              textures: updatedTextures,
                              sprites: updatedSprites,
                              terrainVertices: scene.terrainVertices,
                              terrainHeights: scene.terrainHeights,
                              meshes: updatedMeshes,
                              limitations: scene.limitations)
        // The snapshot was validated when it loaded; its static sprites, meshes and textures are kept as they were.
        try result.validate(trusting: .init(textures: scene.textures.count, sprites: retainedSprites.count, meshes: retainedMeshes.count, architecture: true))
        return result
    }
}
