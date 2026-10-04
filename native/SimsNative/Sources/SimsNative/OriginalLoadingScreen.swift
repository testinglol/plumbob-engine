import AppKit
import SimsCore

/// The original startup screen: the installed `UIGraphics/Other/setup.bmp` artwork, letterboxed at its own aspect
/// ratio over black, shown while game content and the first neighborhood load.
enum OriginalLoadingScreen {
    static let resource = "Other/setup.bmp"

    /// Reads the setup artwork straight from the installed UIGraphics archive, before the full content stack loads.
    /// Returns nil when the archive or bitmap is missing so startup can continue with a plain screen.
    static func image(gameRoot: URL) -> CGImage? {
        guard let archive = try? FARArchive(url: gameRoot.appendingPathComponent("UIGraphics/UIGraphics.far")),
              let data = try? archive.read(resource) else { return nil }
        return image(bitmapData: data)
    }

    static func image(bitmapData: Data) -> CGImage? {
        guard let bitmap = try? SimsBitmap(data: bitmapData),
              let provider = CGDataProvider(data: bitmap.rgba as CFData),
              let space = CGColorSpace(name: CGColorSpace.sRGB) else { return nil }
        return CGImage(width: bitmap.width, height: bitmap.height, bitsPerComponent: 8, bitsPerPixel: 32,
                       bytesPerRow: bitmap.width * 4, space: space,
                       bitmapInfo: CGBitmapInfo(rawValue: CGImageAlphaInfo.noneSkipLast.rawValue),
                       provider: provider, decode: nil, shouldInterpolate: true, intent: .defaultIntent)
    }

    /// A black view that scales the artwork proportionally to fill the window.
    @MainActor
    static func view(image: CGImage?, frame: NSRect) -> NSView {
        let container = NSView(frame: frame)
        container.wantsLayer = true
        container.layer?.backgroundColor = NSColor.black.cgColor
        container.autoresizingMask = [.width, .height]
        container.setAccessibilityElement(true)
        container.setAccessibilityRole(.image)
        container.setAccessibilityLabel("The Sims is loading")
        if let image {
            let imageView = NSImageView(frame: container.bounds)
            imageView.image = NSImage(cgImage: image, size: NSSize(width: image.width, height: image.height))
            imageView.imageScaling = .scaleProportionallyUpOrDown
            imageView.imageAlignment = .alignCenter
            imageView.autoresizingMask = [.width, .height]
            imageView.setAccessibilityElement(false)
            container.addSubview(imageView)
        }
        return container
    }
}
