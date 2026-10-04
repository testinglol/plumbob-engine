import Foundation

public enum SpritePixels {
    public static func premultipliedSRGB(_ pixels: Data, removeMagenta: Bool = false) throws -> Data {
        guard pixels.count % 4 == 0 else { throw ContentError.invalid("RGBA pixel data is not aligned") }
        let linear = (0..<256).map { value -> Double in
            let encoded = Double(value) / 255
            return encoded <= 0.04045 ? encoded / 12.92 : pow((encoded + 0.055) / 1.055, 2.4)
        }
        var output = pixels
        for offset in stride(from: 0, to: output.count, by: 4) {
            if removeMagenta && output[offset] >= 248 && output[offset + 1] <= 8 && output[offset + 2] >= 248 { output[offset + 3] = 0 }
            let alpha = output[offset + 3]
            if alpha == 255 { continue }
            for channel in 0..<3 {
                let value = linear[Int(output[offset + channel])] * Double(alpha) / 255
                let encoded = value <= 0.0031308 ? value * 12.92 : 1.055 * pow(value, 1 / 2.4) - 0.055
                output[offset + channel] = UInt8(min(255, max(0, (encoded * 255).rounded())))
            }
        }
        return output
    }
}
