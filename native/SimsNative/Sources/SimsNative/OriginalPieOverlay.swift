import AppKit
import MetalKit
import SimsCore

struct PieMenuPreview: Decodable {
    let entries: [SimInteraction]
    let objectID: Int
    let selectedSim: Int
    let x: Double
    let y: Double

    static func load(_ url: URL) throws -> PieMenuPreview {
        let attributes = try FileManager.default.attributesOfItem(atPath: url.path)
        guard (attributes[.size] as? NSNumber)?.intValue ?? Int.max <= 1024 * 1024 else { throw ContentError.invalid("Pie menu fixture exceeds size limit") }
        let fixture = try JSONDecoder().decode(Self.self, from: Data(contentsOf: url))
        guard fixture.x.isFinite, fixture.y.isFinite else { throw ContentError.invalid("Invalid pie menu position") }
        return fixture
    }
}

@MainActor
final class OriginalPieOverlay {
    struct Label {
        let background: MTLTexture
        let states: [MTLTexture]
        let size: CGSize
    }
    let objectID: Int
    let selectedSim: Int
    let roots: [OriginalPieNode]
    let font: SimsBitmapFont
    let device: MTLDevice
    let anchor: CGPoint
    private var path: [Int] = []
    private(set) var nodes: [OriginalPieNode] = []
    private(set) var labels: [Label] = []
    var highlighted: Int?
    private(set) var layout: OriginalPieLayout?

    init(entries: [SimInteraction], objectID: Int, selectedSim: Int, anchor: CGPoint, font: SimsBitmapFont, device: MTLDevice) throws {
        roots = try OriginalPieNode.build(entries)
        guard !roots.isEmpty else { throw ContentError.missing("Interaction menu has no available labels") }
        self.objectID = objectID
        self.selectedSim = selectedSim
        self.anchor = anchor
        self.font = font
        self.device = device
        try rebuild()
    }

    private func texture(width: Int, height: Int, pixels: Data) throws -> MTLTexture {
        let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: .rgba8Unorm_srgb, width: width, height: height, mipmapped: false)
        descriptor.storageMode = .shared
        descriptor.usage = .shaderRead
        guard let texture = device.makeTexture(descriptor: descriptor) else { throw ContentError.invalid("Cannot allocate pie menu texture") }
        let encoded = try SpritePixels.premultipliedSRGB(pixels)
        encoded.withUnsafeBytes { bytes in
            texture.replace(region: MTLRegionMake2D(0, 0, width, height), mipmapLevel: 0, withBytes: bytes.baseAddress!, bytesPerRow: width * 4)
        }
        return texture
    }

    private func rebuild() throws {
        var current = roots
        for index in path { current = current[index].children }
        var budget = 64 * 1024 * 1024
        let next = try current.map { node -> Label in
            let width = max(1, font.textWidth(node.label) + 6), height = font.lineHeight + 6
            budget -= width * height * 16
            guard budget >= 0 else { throw ContentError.invalid("Pie menu texture memory limit exceeded") }
            var background = Data(repeating: 0, count: width * height * 4)
            for y in 0..<height {
                let edge = min(y, height - 1 - y)
                let margin = edge == 0 ? 5 : edge == 1 ? 3 : edge == 2 ? 2 : edge < 5 ? 1 : 0
                for x in 0..<width where x >= margin && x < width - margin {
                    let offset = (y * width + x) * 4
                    background[offset] = 118
                    background[offset + 1] = 118
                    background[offset + 2] = 118
                    background[offset + 3] = 255
                }
            }
            let states = try [SIMD3<UInt8>(185, 185, 208), SIMD3(0, 255, 255), SIMD3(255, 255, 255)].map { color in
                let image = try font.rasterize(node.label, color: color)
                return try texture(width: image.width, height: image.height, pixels: image.rgba)
            }
            return Label(background: try texture(width: width, height: height, pixels: background), states: states,
                         size: CGSize(width: width, height: height))
        }
        nodes = current
        labels = next
        highlighted = nil
        layout = nil
    }

    func prepare(canvas: CGSize, scale: CGFloat) {
        layout = OriginalPieLayout(anchor: anchor, sizes: labels.map(\.size),
                                   viewport: CGSize(width: canvas.width / scale, height: max(1, canvas.height / scale - 150)))
    }

    func hover(_ point: CGPoint, scale: CGFloat) { highlighted = layout?.hit(CGPoint(x: point.x / scale, y: point.y / scale)) }

    func choose(_ point: CGPoint, scale: CGFloat) throws -> (action: SimInteraction?, keepOpen: Bool) {
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        if let center = layout?.center, hypot(local.x - center.x, local.y - center.y) < 20, !path.isEmpty {
            path.removeLast()
            try rebuild()
            return (nil, true)
        }
        guard let index = layout?.hit(local), nodes.indices.contains(index) else { return (nil, false) }
        if let action = nodes[index].action { return (action, false) }
        path.append(index)
        do { try rebuild() }
        catch { path.removeLast(); throw error }
        return (nil, true)
    }
}
