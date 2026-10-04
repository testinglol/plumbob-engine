import Foundation
import CoreGraphics
import ImageIO

public struct PNGImage {
    public let width: Int
    public let height: Int
    public let rgba: Data

    public init(data: Data, width: Int, height: Int) throws {
        guard (1...4096).contains(width), (1...4096).contains(height), data.count <= 64 * 1024 * 1024,
              data.starts(with: [137, 80, 78, 71, 13, 10, 26, 10]),
              let source = CGImageSourceCreateWithData(data as CFData, nil), CGImageSourceGetCount(source) == 1,
              let properties = CGImageSourceCopyPropertiesAtIndex(source, 0, nil) as? [CFString: Any],
              (properties[kCGImagePropertyPixelWidth] as? NSNumber)?.intValue == width,
              (properties[kCGImagePropertyPixelHeight] as? NSNumber)?.intValue == height,
              let image = CGImageSourceCreateImageAtIndex(source, 0, nil) else { throw ContentError.invalid("PNG dimensions or format differ from scene metadata") }
        var pixels = Data(count: width * height * 4)
        try pixels.withUnsafeMutableBytes { buffer in
            guard let context = CGContext(data: buffer.baseAddress, width: width, height: height, bitsPerComponent: 8,
                                          bytesPerRow: width * 4, space: CGColorSpaceCreateDeviceRGB(),
                                          bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue | CGBitmapInfo.byteOrder32Big.rawValue) else { throw ContentError.invalid("Cannot decode PNG pixels") }
            context.setBlendMode(.copy)
            context.draw(image, in: CGRect(x: 0, y: 0, width: width, height: height))
            let bytes = buffer.bindMemory(to: UInt8.self)
            for offset in stride(from: 0, to: bytes.count, by: 4) {
                let alpha = Int(bytes[offset + 3])
                if alpha > 0 && alpha < 255 {
                    for channel in 0..<3 { bytes[offset + channel] = UInt8(min(255, (Int(bytes[offset + channel]) * 255 + alpha / 2) / alpha)) }
                }
            }
        }
        self.width = width
        self.height = height
        rgba = pixels
    }
}
