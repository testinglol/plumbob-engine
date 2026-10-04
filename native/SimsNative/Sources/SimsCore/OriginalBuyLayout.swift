import Foundation
import CoreGraphics

public enum OriginalBuyLayout {
    public static let categories = ["Seating", "Surfaces", "Decorative", "Electronics", "Appliances", "Plumbing", "Lighting", "Misc"]
    public static let positions = [CGPoint(x: 242, y: 58), CGPoint(x: 279, y: 66), CGPoint(x: 322, y: 51), CGPoint(x: 369, y: 54), CGPoint(x: 241, y: 111), CGPoint(x: 285, y: 109), CGPoint(x: 322, y: 105), CGPoint(x: 364, y: 114)]

    public static func columns(canvas: CGSize) -> Int {
        guard canvas.width.isFinite else { return 1 }
        return max(1, Int(min(32, max(0, canvas.width - 445) / 48)))
    }
    public static func capacity(canvas: CGSize) -> Int { columns(canvas: canvas) * 2 }
    public static func thumbnail(_ index: Int, canvas: CGSize) -> CGRect {
        let columns = columns(canvas: canvas)
        return CGRect(x: CGFloat(421 + index % columns * 48), y: canvas.height - 100 + CGFloat(index / columns * 50), width: 45, height: 45)
    }
}
