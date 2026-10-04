import Foundation
#if canImport(CoreGraphics)
import CoreGraphics
#endif

public enum OriginalBuyLayout {
    public static let categories = ["Seating", "Surfaces", "Decorative", "Electronics", "Appliances", "Plumbing", "Lighting", "Misc"]
    public static let positions = [CGPoint(x: 242, y: 58), CGPoint(x: 279, y: 66), CGPoint(x: 322, y: 51), CGPoint(x: 369, y: 54), CGPoint(x: 241, y: 111), CGPoint(x: 285, y: 109), CGPoint(x: 322, y: 105), CGPoint(x: 364, y: 114)]

    /// Engine catalog category for each button. Buttons follow the original function-sort table at `0x005072f5`
    /// (flags 1, 2, 0x20, 8, 4, 0x10, 0x80, 0x40); the engine category is log2 of the function flag.
    public static let engineCategories = [0, 1, 5, 3, 2, 4, 7, 6]

    /// `0x005072f5` lays 45×45 thumbnails out in 45-pixel steps from x `0x19f` minus the panel offset, y 5, to
    /// (panel width - 12, 95). The buy panel sits at (220, 50) in the control panel, so the grid starts at
    /// absolute x 415 and is two rows tall.
    public static func columns(canvas: CGSize) -> Int {
        guard canvas.width.isFinite else { return 1 }
        return max(1, Int(min(32, max(0, canvas.width - 427) / 45)))
    }
    public static func capacity(canvas: CGSize) -> Int { columns(canvas: canvas) * 2 }
    public static func thumbnail(_ index: Int, canvas: CGSize) -> CGRect {
        let columns = columns(canvas: canvas)
        return CGRect(x: CGFloat(415 + index % columns * 45), y: canvas.height - 95 + CGFloat(index / columns * 45), width: 45, height: 45)
    }
    /// Scroll arrows are centered in the gutters between the outer scroll rect (x `0x18b` = 395 to the panel edge) and the grid.
    public static func arrow(forward: Bool, size: CGSize, canvas: CGSize) -> CGRect {
        let x = forward ? canvas.width - 12 + (12 - size.width) / 2 : 395 + (20 - size.width) / 2
        return CGRect(x: x, y: canvas.height - 50 - size.height / 2, width: size.width, height: size.height)
    }
}
