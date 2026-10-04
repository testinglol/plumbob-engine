import AppKit
import AVFoundation
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

    /// The original streams `Music/Modes/Load/loadloop.wav` from the install folder, looped, at the music volume
    /// (`0x004fb49a`); it is a plain file rather than a HIT event, so it can start before any host runs.
    @MainActor
    static func music(gameRoot: URL, profile: URL) -> AVAudioPlayer? {
        guard let url = resolve(["Music", "Modes", "Load", "loadloop.wav"], in: gameRoot),
              let player = try? AVAudioPlayer(contentsOf: url) else { return nil }
        player.numberOfLoops = -1
        player.volume = musicVolume(profile: profile)
        return player.prepareToPlay() ? player : nil
    }

    /// The saved music master volume (HIT group 1) from the profile's `Settings/audio.json`, or full volume.
    static func musicVolume(profile: URL) -> Float {
        guard let data = try? Data(contentsOf: profile.appendingPathComponent("Settings/audio.json")),
              let root = try? JSONSerialization.jsonObject(with: data) as? [String: Any],
              root["schemaVersion"] as? Int == 1, let volumes = root["volumes"] as? [NSNumber], volumes.count == 4 else { return 1 }
        let value = volumes[1].floatValue
        return value.isFinite ? min(1, max(0, value)) : 1
    }

    /// Finds a file below the game folder without depending on the case of each path component.
    private static func resolve(_ components: [String], in root: URL) -> URL? {
        var current = root
        for component in components {
            guard let entries = try? FileManager.default.contentsOfDirectory(at: current, includingPropertiesForKeys: nil),
                  let next = entries.first(where: { $0.lastPathComponent.lowercased() == component.lowercased() }) else { return nil }
            current = next
        }
        return current
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
