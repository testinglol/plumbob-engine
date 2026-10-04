import Foundation

public struct LotScene: Decodable {
    public struct Texture: Decodable {
        public let file: String
        public let width: Int
        public let height: Int
        public let encoding: String?
    }

    public struct WallSide: Decodable, Equatable {
        public var cut: Int? = nil
        public let x: Int
        public let y: Int
        public let level: Int
        public let direction: Int
    }

    public struct WallDepth: Decodable, Equatable {
        public let x: Int
        public let y: Int
        public let level: Int
        public let configuration: Int
    }

    public struct WallJunction: Decodable, Equatable {
        public let x: Int
        public let y: Int
        public let level: Int
        public let flags: Int
        public let frame: Int
        public let down: Bool
    }

    public struct Sprite: Decodable {
        public let texture: Int
        public let x: Float
        public let y: Float
        public let width: Float
        public let height: Float
        public let flip: Bool
        public let objectID: Int?
        public let layer: Int?
        public let depth: Float?
        public let depthTexture: Int?
        public let depthNear: Float?
        public let depthFar: Float?
        public var wall: WallSide? = nil
        public var junction: WallJunction? = nil
        public var architectureDepth: WallDepth? = nil
        public var room: Int? = nil
        public var level: Int? = nil
    }

    public struct MeshVertex: Decodable {
        public let x: Float
        public let y: Float
        public let z: Float
        public let u: Float
        public let v: Float
        public let nx: Float
        public let ny: Float
        public let nz: Float
    }

    public struct WaterSurface: Decodable {
        public let adjacency: Int
        public let sprite: UInt16
        public let corners: [UInt16]
        public func validate(pattern: UInt16) throws {
            guard (0...255).contains(adjacency), pattern >= 65534 else { throw ContentError.invalid("Invalid water surface topology") }
            let variant = (adjacency & 1 != 0 ? 1 : 0) | (adjacency & 64 != 0 ? 2 : 0) | (adjacency & 16 != 0 ? 4 : 0) | (adjacency & 4 != 0 ? 8 : 0)
            let pairs = [65, 80, 20, 5]
            let diagonal = [128, 32, 8, 2]
            let expected = pattern == 65535 ? (0..<4).filter { adjacency & pairs[$0] == pairs[$0] && adjacency & diagonal[$0] == 0 }.map { UInt16(0x434 + $0) } : []
            guard sprite == UInt16((pattern == 65535 ? 0x410 : 0x800) + variant), corners == expected else { throw ContentError.invalid("Water surface sprites do not match adjacent tiles") }
        }
    }

    public struct FloorSurface: Decodable {
        public let x: Int
        public let y: Int
        public let pattern: UInt16
        public let half: Int
        public var water: WaterSurface? = nil
        public var level: Int? = nil
    }

    public struct RoofSurface: Decodable {
        public var part: String? = nil
        public let style: UInt32
        public let pitch: Float
        public let file: String
    }

    public struct Mesh: Decodable {
        public var room: Int? = nil
        public var roof: RoofSurface? = nil
        public var floor: FloorSurface? = nil
        public var level: Int? = nil
        public var layer: Int? = nil
        public var unlit: Bool? = nil
        public let texture: Int
        public let objectID: Int
        public let depth: Float
        public let vertices: [MeshVertex]
    }

    public struct TerrainVertex: Decodable {
        public let x: Float
        public let y: Float
        public let r: UInt8
        public let g: UInt8
        public let b: UInt8
    }

    public let schemaVersion: Int
    public var lighting: SceneLighting? = nil
    public var wallMode: String? = nil
    public var cameraOrientation: Int? = nil
    public let house: Int
    public let width: Float
    public let height: Float
    public let lotWidth: Int?
    public let lotHeight: Int?
    public var floorDiagonals: [UInt8]? = nil
    public var roofsVisible: Bool? = nil
    public var viewLevel: Int? = nil
    public var stories: Int? = nil
    public var placementVertices: [TerrainVertex]? = nil
    public var selectedLevel: Int { viewLevel ?? 1 }
    public var camera: LotCamera { LotCamera(rawValue: cameraOrientation ?? 0) ?? .topLeft }
    public var constructionVertices: [TerrainVertex]? { placementVertices ?? terrainVertices }
    public let textures: [Texture]
    public let sprites: [Sprite]
    public let terrainVertices: [TerrainVertex]?
    public let terrainHeights: [Int16]?
    public let meshes: [Mesh]?
    public let limitations: [String]

    public static func load(url: URL) throws -> (scene: LotScene, pixels: [Data]) {
        let attributes = try FileManager.default.attributesOfItem(atPath: url.path)
        guard (attributes[.size] as? NSNumber)?.intValue ?? Int.max <= 64 * 1024 * 1024 else {
            throw ContentError.invalid("Lot scene file exceeds 64 MiB")
        }
        let scene = try JSONDecoder().decode(LotScene.self, from: Data(contentsOf: url))
        let root = url.deletingLastPathComponent().resolvingSymlinksInPath().standardizedFileURL
        try scene.validate()
        let pixels = try readPixels(textures: scene.textures, root: root)
        return (scene, pixels)
    }

    public static func readPixels(textures: [Texture], root: URL) throws -> [Data] {
        var budget = 512 * 1024 * 1024
        return try textures.map { texture in
            guard texture.width > 0, texture.height > 0, texture.width <= 4096, texture.height <= 4096 else {
                throw ContentError.invalid("Invalid lot texture dimensions")
            }
            _ = try resourceKey(texture.file)
            let expectedSize = texture.width * texture.height * (texture.encoding == "depth8" ? 1 : 4)
            budget -= expectedSize
            guard budget >= 0 else { throw ContentError.invalid("Lot texture memory limit exceeded") }
            let file = root.appendingPathComponent(texture.file).resolvingSymlinksInPath().standardizedFileURL
            guard file.path.hasPrefix(root.path + "/") else { throw ContentError.invalid("Lot texture escapes scene directory") }
            let data = try Data(contentsOf: file, options: .mappedIfSafe)
            switch texture.encoding ?? "rgba" {
            case "rgba", "depth8":
                guard data.count == expectedSize else { throw ContentError.invalid("Truncated lot texture: \(texture.file)") }
                return data
            case "png":
                return try PNGImage(data: data, width: texture.width, height: texture.height).rgba
            case "bmp":
                let image = try SimsBitmap(data: data)
                guard image.width == texture.width, image.height == texture.height else { throw ContentError.invalid("BMP dimensions differ from scene metadata") }
                return image.rgba
            case "tga":
                let image = try SimsTarga(data: data)
                guard image.width == texture.width, image.height == texture.height else { throw ContentError.invalid("TGA dimensions differ from scene metadata") }
                return image.rgba
            default: throw ContentError.invalid("Unsupported lot texture encoding")
            }
        }
    }

    public func validate() throws {
        guard cameraOrientation == nil || (0...3).contains(cameraOrientation!) else { throw ContentError.invalid("Invalid lot camera orientation") }
        guard wallMode == nil || ["up", "down", "cutaway"].contains(wallMode!) else { throw ContentError.invalid("Invalid wall mode") }
        try lighting?.validate()
        for room in sprites.map(\.room) + (meshes ?? []).map(\.room) {
            if let room, !(0...65535).contains(room) { throw ContentError.invalid("Invalid material room ID") }
            try lighting?.validate(room: room)
        }
        guard (1...5).contains(selectedLevel), stories == nil || (1...5).contains(stories!), selectedLevel <= (stories ?? 5) else { throw ContentError.invalid("Invalid selected story") }
        if let placementVertices {
            guard let lotWidth, let lotHeight, placementVertices.count == lotWidth * lotHeight * 6 else { throw ContentError.invalid("Invalid construction grid") }
            for vertex in placementVertices {
                guard vertex.x.isFinite, vertex.y.isFinite, vertex.x >= 0, vertex.y >= 0, vertex.x <= width + 1, vertex.y <= height + 1 else { throw ContentError.invalid("Invalid construction vertex bounds") }
            }
        }
        if lotWidth != nil || lotHeight != nil {
            guard let lotWidth, let lotHeight, (1...128).contains(lotWidth), (1...128).contains(lotHeight),
                  terrainVertices?.count == lotWidth * lotHeight * 6 else { throw ContentError.invalid("Invalid lot terrain grid") }
        }
        if let floorDiagonals {
            guard let lotWidth, let lotHeight, floorDiagonals.count == lotWidth * lotHeight,
                  floorDiagonals.allSatisfy({ [0, 16, 32].contains($0) }) else { throw ContentError.invalid("Invalid diagonal floor grid") }
        }
        var textureBytes = 0
        for texture in textures {
            guard texture.width > 0, texture.height > 0, texture.width <= 4096, texture.height <= 4096,
                  ["rgba", "bmp", "tga", "png", "depth8"].contains(texture.encoding ?? "rgba") else {
                throw ContentError.invalid("Invalid lot texture metadata")
            }
            _ = try resourceKey(texture.file)
            textureBytes += texture.width * texture.height * (texture.encoding == "depth8" ? 1 : 4)
            guard textureBytes <= 512 * 1024 * 1024 else { throw ContentError.invalid("Lot texture memory limit exceeded") }
        }
        guard self.schemaVersion == 1, self.width.isFinite, self.height.isFinite,
              self.width > 0, self.height > 0, self.width <= 65536, self.height <= 65536,
              self.textures.count <= 10000, self.sprites.count <= 100000 else {
            throw ContentError.invalid("Invalid lot scene size or version")
        }
        for sprite in self.sprites {
            guard (1...(stories ?? 5)).contains(sprite.level ?? 1), viewLevel == nil || (sprite.level ?? 1) <= selectedLevel else { throw ContentError.invalid("Sprite exceeds visible story") }
            guard self.textures.indices.contains(sprite.texture), sprite.x.isFinite, sprite.y.isFinite,
                  sprite.width.isFinite, sprite.height.isFinite, sprite.width > 0, sprite.height > 0,
                  sprite.x >= 0, sprite.y >= 0, sprite.x + sprite.width <= self.width + 1,
                  sprite.y + sprite.height <= self.height + 1 else { throw ContentError.invalid("Invalid lot sprite bounds") }
            if let wall = sprite.wall {
                guard (0...3).contains(wall.cut ?? 0) else { throw ContentError.invalid("Invalid wall cut shape") }
                guard let lotWidth, let lotHeight, (0..<lotWidth).contains(wall.x), (0..<lotHeight).contains(wall.y),
                      (1...(stories ?? 5)).contains(wall.level), wall.level == (sprite.level ?? 1), (0...3).contains(wall.direction), (sprite.objectID ?? 0) == 0, sprite.layer == 1 else {
                    throw ContentError.invalid("Invalid wall picking metadata")
                }
            }
            if let architecture = sprite.architectureDepth {
                guard let lotWidth, let lotHeight, (0..<lotWidth).contains(architecture.x), (0..<lotHeight).contains(architecture.y),
                      architecture.level == (sprite.level ?? 1), (4...7).contains(architecture.configuration),
                      sprite.junction == nil, (sprite.objectID ?? 0) == 0, sprite.layer == 1, sprite.depthTexture != nil,
                      sprite.wall == nil || (sprite.wall!.x == architecture.x && sprite.wall!.y == architecture.y) else {
                    throw ContentError.invalid("Invalid wall depth metadata")
                }
            }
            if let junction = sprite.junction {
                guard let lotWidth, let lotHeight, (0..<lotWidth).contains(junction.x), (0..<lotHeight).contains(junction.y),
                      junction.level == (sprite.level ?? 1), (1...255).contains(junction.flags), (0...45).contains(junction.frame),
                      sprite.wall == nil, (sprite.objectID ?? 0) == 0, sprite.layer == 1, sprite.depthTexture != nil else {
                    throw ContentError.invalid("Invalid wall junction metadata")
                }
            }
            if let depth = sprite.depth, !depth.isFinite { throw ContentError.invalid("Invalid sprite draw depth") }
            let color = self.textures[sprite.texture]
            guard color.encoding != "depth8" else { throw ContentError.invalid("Sprite color references a depth texture") }
            if let depth = sprite.depthTexture {
                guard self.textures.indices.contains(depth), let near = sprite.depthNear, let far = sprite.depthFar,
                      near.isFinite, far.isFinite, near >= 0, far <= 1, near <= far,
                      self.textures[depth].encoding == "depth8",
                      self.textures[depth].width == color.width, self.textures[depth].height == color.height else {
                    throw ContentError.invalid("Invalid sprite depth texture or interval")
                }
            } else if sprite.depthNear != nil || sprite.depthFar != nil {
                throw ContentError.invalid("Sprite depth interval has no texture")
            }
        }
        if let vertices = self.terrainVertices {
            guard vertices.count <= 300000, vertices.count.isMultiple(of: 3) else {
                throw ContentError.invalid("Invalid terrain triangle count")
            }
            for vertex in vertices {
                guard vertex.x.isFinite, vertex.y.isFinite, vertex.x >= 0, vertex.y >= 0,
                      vertex.x <= self.width + 1, vertex.y <= self.height + 1 else {
                    throw ContentError.invalid("Invalid terrain vertex bounds")
                }
            }
        }
        if let heights = self.terrainHeights {
            guard let lotWidth, let lotHeight, heights.count == lotWidth * lotHeight else { throw ContentError.invalid("Invalid terrain height grid") }
        }
        var meshVertexCount = 0
        for mesh in self.meshes ?? [] {
            guard (1...(stories ?? 5)).contains(mesh.level ?? 1), viewLevel == nil || (mesh.level ?? 1) <= selectedLevel else { throw ContentError.invalid("Mesh exceeds visible story") }
            guard mesh.layer == nil || (0...2).contains(mesh.layer!), mesh.unlit != true || (mesh.layer == 0 && mesh.objectID == 0) else { throw ContentError.invalid("Invalid static mesh material or layer") }
            guard (mesh.layer == 2) == (mesh.roof != nil) else { throw ContentError.invalid("Roof layer has no material") }
            if let roof = mesh.roof {
                guard mesh.objectID == 0, mesh.floor == nil, mesh.unlit == false, ["surface", "edge"].contains(roof.part ?? "surface"), roof.pitch.isFinite, (0...1.25).contains(roof.pitch), roof.file.utf16.count <= 1024 else { throw ContentError.invalid("Invalid roof material") }
            }
            if let floor = mesh.floor {
                if floor.pattern >= 65534 {
                    guard let water = floor.water else { throw ContentError.invalid("Water surface has no topology") }
                    try water.validate(pattern: floor.pattern)
                } else if floor.water != nil { throw ContentError.invalid("Ordinary floor contains water metadata") }
                guard (floor.level ?? 1) == (mesh.level ?? 1), let lotWidth, let lotHeight, (0..<lotWidth).contains(floor.x), (0..<lotHeight).contains(floor.y),
                      floor.pattern > 0, (0...4).contains(floor.half), mesh.unlit == true,
                      mesh.vertices.count == (floor.half == 0 ? 6 : 3) else { throw ContentError.invalid("Invalid floor surface metadata") }
            }
            meshVertexCount += mesh.vertices.count
            guard meshVertexCount <= 1_000_000, !mesh.vertices.isEmpty, mesh.vertices.count.isMultiple(of: 3),
                  self.textures.indices.contains(mesh.texture), mesh.depth.isFinite,
                  self.textures[mesh.texture].encoding != "depth8" else {
                throw ContentError.invalid("Invalid avatar mesh size or texture")
            }
            for vertex in mesh.vertices {
                guard [vertex.x, vertex.y, vertex.z, vertex.u, vertex.v, vertex.nx, vertex.ny, vertex.nz].allSatisfy(\.isFinite),
                      vertex.x >= 0, vertex.y >= 0, vertex.x <= self.width + 1, vertex.y <= self.height + 1,
                      vertex.z >= 0, vertex.z <= 1, abs(vertex.u) <= (mesh.roof == nil ? 16 : 4096), abs(vertex.v) <= (mesh.roof == nil ? 16 : 4096),
                      abs(vertex.nx) <= 1.01, abs(vertex.ny) <= 1.01, abs(vertex.nz) <= 1.01 else {
                    throw ContentError.invalid("Invalid avatar mesh vertex")
                }
            }
        }
    }
}
