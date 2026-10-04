import Foundation

/// A CPU-side UI image: premultiplied sRGB RGBA pixels that the SDL renderer uploads on first draw.
///
/// The original-UI overlays were written against Metal. This file gives them the small part of the Metal API they use
/// (a device that makes textures, a texture descriptor and `replace(region:...)`), so the overlay sources stay close to
/// the macOS client's and changes port across by copying.
final class UITexture {
    let width: Int
    let height: Int
    private(set) var pixels: Data
    /// Bumped on every pixel change so the renderer knows to upload again.
    private(set) var version = 0

    init(width: Int, height: Int, pixels: Data? = nil) {
        self.width = width
        self.height = height
        self.pixels = pixels ?? Data(count: width * height * 4)
    }

    func replace(region: UIRegion, mipmapLevel: Int, withBytes bytes: UnsafeRawPointer, bytesPerRow: Int) {
        pixels.withUnsafeMutableBytes { destination in
            for row in 0..<region.height {
                let target = ((region.y + row) * width + region.x) * 4
                guard target + region.width * 4 <= destination.count else { return }
                (destination.baseAddress! + target).copyMemory(from: bytes + row * bytesPerRow, byteCount: region.width * 4)
            }
        }
        version += 1
    }
}

struct UIRegion {
    var x: Int, y: Int, width: Int, height: Int
}

func MTLRegionMake2D(_ x: Int, _ y: Int, _ width: Int, _ height: Int) -> UIRegion {
    UIRegion(x: x, y: y, width: width, height: height)
}

final class UITextureDescriptor {
    enum PixelFormat { case rgba8Unorm_srgb }
    enum StorageMode { case shared }
    struct Usage: OptionSet {
        let rawValue: Int
        static let shaderRead = Usage(rawValue: 1)
    }
    let width: Int
    let height: Int
    var storageMode = StorageMode.shared
    var usage = Usage.shaderRead

    private init(width: Int, height: Int) {
        self.width = width
        self.height = height
    }

    static func texture2DDescriptor(pixelFormat: PixelFormat, width: Int, height: Int, mipmapped: Bool) -> UITextureDescriptor {
        UITextureDescriptor(width: width, height: height)
    }
}

/// Stands in for `MTLDevice` in the overlays; textures live in CPU memory until drawn.
struct UIDevice {
    func makeTexture(descriptor: UITextureDescriptor) -> UITexture? {
        guard descriptor.width > 0, descriptor.height > 0 else { return nil }
        return UITexture(width: descriptor.width, height: descriptor.height)
    }
}
