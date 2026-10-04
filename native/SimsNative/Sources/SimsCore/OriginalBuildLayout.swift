import Foundation
#if canImport(CoreGraphics)
import CoreGraphics
#endif

public enum OriginalBuildLayout {
    public static let assets = ["Terrain", "Water", "Wall", "Wallpaper", "Stairs", "Fireplace", "Tree", "Floor", "Door", "Window", "Roof", "Hand"]
    public static let positions: [CGPoint] = [CGPoint(x: 278, y: 4), CGPoint(x: 325, y: 6), CGPoint(x: 364, y: 4), CGPoint(x: 408, y: 3), CGPoint(x: 450, y: 4), CGPoint(x: 502, y: 8), CGPoint(x: 279, y: 57), CGPoint(x: 317, y: 64), CGPoint(x: 367, y: 55), CGPoint(x: 409, y: 55), CGPoint(x: 449, y: 55), CGPoint(x: 502, y: 55)]
    public static let historyPositions: [CGPoint] = [CGPoint(x: 231, y: 15), CGPoint(x: 231, y: 53)]
    public static func historyFrameIndex(enabled: Bool) -> Int { enabled ? 0 : 3 }
    /// Grid origin and 45-pixel step follow 0x00500572 (grid from panel x 0x152, outer scroll rect from 0x13e).
    /// The original grid runs to panelW - 4 with no recovered arrow slot on the right, so columns stop at
    /// W - 14 to keep the next-page arrow from covering the last thumbnail column.
    public static func columns(canvas: CGSize) -> Int {
        guard canvas.width.isFinite else { return 1 }
        return max(1, min(32, Int(max(0, canvas.width - 572) / 45)))
    }
    public static func capacity(canvas: CGSize) -> Int { columns(canvas: canvas) * 2 }
    public static func historyControl(_ index: Int, canvas: CGSize, imageSize: CGSize) -> CGRect {
        guard historyPositions.indices.contains(index), imageSize.width > 0, imageSize.height > 0 else { return .zero }
        return CGRect(origin: historyPositions[index], size: CGSize(width: imageSize.width / 4, height: imageSize.height))
            .offsetBy(dx: 0, dy: canvas.height - 183)
    }
    /// Page arrows sit in the left gutter (546) and right of the last column (W - 14); `size` is one frame.
    public static func arrow(forward: Bool, size: CGSize, canvas: CGSize) -> CGRect {
        CGRect(x: forward ? canvas.width - 14 : 546, y: canvas.height - 74, width: size.width, height: size.height)
    }
    public static func thumbnail(_ index: Int, canvas: CGSize) -> CGRect {
        CGRect(x: 558 + index % columns(canvas: canvas) * 45, y: Int(canvas.height) - 95 + index / columns(canvas: canvas) * 45, width: 45, height: 45)
    }
}
