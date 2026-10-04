import Foundation

public struct PlacementPreview: Decodable {
    public struct Tile: Decodable {
        public let x: Int
        public let y: Int
        public let level: Int
    }
    public struct Ghost: Decodable {
        public let x: Float
        public let y: Float
        public let scene: LotScene

        public func validate() throws {
            guard x.isFinite, y.isFinite, abs(x) <= 65536, abs(y) <= 65536,
                  scene.sprites.count <= 2048, scene.textures.count <= 4096,
                  scene.meshes == nil, scene.terrainVertices == nil else {
                throw ContentError.invalid("Invalid placement ghost")
            }
            try scene.validate()
        }
    }
    public let ghost: Ghost?
    public let schemaVersion: Int
    public let valid: Bool
    public let status: String
    public let tiles: [Tile]

    public func geometry(scene: LotScene) throws -> [LotScene.TerrainVertex] {
        guard schemaVersion == 1, status.count <= 128, !tiles.isEmpty, tiles.count <= 128,
              let width = scene.lotWidth, let height = scene.lotHeight,
              let terrain = scene.constructionVertices, terrain.count == width * height * 6 else {
            throw ContentError.invalid("Invalid placement preview")
        }
        try ghost?.validate()
        var result: [LotScene.TerrainVertex] = []
        for tile in tiles {
            guard (-128...255).contains(tile.x), (-128...255).contains(tile.y), (1...5).contains(tile.level) else {
                throw ContentError.invalid("Placement footprint exceeds limits")
            }
            if tile.level == scene.selectedLevel, (0..<width).contains(tile.x), (0..<height).contains(tile.y) {
                let start = (tile.y * width + tile.x) * 6
                result += terrain[start..<(start + 6)]
            }
        }
        return result
    }
}
