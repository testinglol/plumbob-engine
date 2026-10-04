import Foundation
#if canImport(CoreGraphics)
import CoreGraphics
#endif

public struct OriginalSpeedControl: Sendable {
    public static let panelHeight: CGFloat = 183
    public let asset: String
    public let position: CGPoint
    public let size: CGSize
    public let columns: Int
    public let rows: Int
    public let speed: Int

    public static let all: [OriginalSpeedControl] = [
        .init(asset: "UIGraphics/cpanel/Buttons/pause.bmp", position: CGPoint(x: 85, y: 135), size: CGSize(width: 15, height: 15), columns: 4, rows: 2, speed: 0),
        .init(asset: "UIGraphics/cpanel/Buttons/Speed1.bmp", position: CGPoint(x: 105, y: 135), size: CGSize(width: 11, height: 15), columns: 4, rows: 1, speed: 1),
        .init(asset: "UIGraphics/cpanel/Buttons/Speed2.bmp", position: CGPoint(x: 120, y: 135), size: CGSize(width: 20, height: 15), columns: 4, rows: 1, speed: 3),
        .init(asset: "UIGraphics/cpanel/Buttons/Speed3.bmp", position: CGPoint(x: 141, y: 135), size: CGSize(width: 32, height: 15), columns: 4, rows: 1, speed: 10)
    ]

    public static func hit(point: CGPoint, canvas: CGSize, scale: CGFloat) -> Int? {
        guard scale > 0 else { return nil }
        let local = CGPoint(x: point.x / scale, y: (point.y - canvas.height + panelHeight * scale) / scale)
        return all.first { CGRect(origin: $0.position, size: $0.size).contains(local) }?.speed
    }
}

public struct OriginalUniversalControl: Sendable {
    public enum Action: String, Sendable { case live, buy, build, options, zoomIn, zoomOut, wallsUp, wallsCutaway, wallsDown, story1, story2, roofs, cameraLeft, cameraRight }
    public let action: Action
    public let asset: String
    public let label: String
    public let position: CGPoint
    public let size: CGSize
    public var enabled: Bool { true }
    public static let all: [OriginalUniversalControl] = [
        .init(action: .live, asset: "People.bmp", label: "Live mode", position: CGPoint(x: 10, y: 6), size: CGSize(width: 50, height: 50)),
        .init(action: .buy, asset: "Objects.bmp", label: "Buy mode", position: CGPoint(x: 69, y: 20), size: CGSize(width: 45, height: 47)),
        .init(action: .build, asset: "Arch.bmp", label: "Build mode", position: CGPoint(x: 117, y: 45), size: CGSize(width: 39, height: 39)),
        .init(action: .options, asset: "Options.bmp", label: "Options", position: CGPoint(x: 193, y: 125), size: CGSize(width: 23, height: 23)),
        .init(action: .zoomIn, asset: "ZoomIn.bmp", label: "Zoom in", position: CGPoint(x: 26, y: 105), size: CGSize(width: 27, height: 27)),
        .init(action: .zoomOut, asset: "ZoomOut.bmp", label: "Zoom out", position: CGPoint(x: 26, y: 149), size: CGSize(width: 27, height: 27)),
        .init(action: .wallsUp, asset: "NoCut.bmp", label: "Walls up", position: CGPoint(x: 56, y: 80), size: CGSize(width: 21, height: 21)),
        .init(action: .wallsCutaway, asset: "Dynacut.bmp", label: "Wall cutaway", position: CGPoint(x: 80, y: 85), size: CGSize(width: 21, height: 21)),
        .init(action: .wallsDown, asset: "NoWall.bmp", label: "Walls down", position: CGPoint(x: 103, y: 95), size: CGSize(width: 22, height: 15)),
        .init(action: .roofs, asset: "LevRoof.bmp", label: "Roof view", position: CGPoint(x: 32, y: 78), size: CGSize(width: 22, height: 19)),
        .init(action: .story1, asset: "Lev1.BMP", label: "Ground floor", position: CGPoint(x: 5, y: 92), size: CGSize(width: 21, height: 11)),
        .init(action: .story2, asset: "Lev2.BMP", label: "Second floor", position: CGPoint(x: 5, y: 77), size: CGSize(width: 22, height: 15)),
        .init(action: .cameraLeft, asset: "RotLeft.bmp", label: "Rotate view counterclockwise", position: CGPoint(x: 43, y: 127), size: CGSize(width: 27, height: 27)),
        .init(action: .cameraRight, asset: "RotRight.bmp", label: "Rotate view clockwise", position: CGPoint(x: 9, y: 127), size: CGSize(width: 27, height: 27))
    ]
    public func rect(canvas: CGSize) -> CGRect {
        CGRect(origin: position, size: size).offsetBy(dx: 0, dy: canvas.height - OriginalSpeedControl.panelHeight)
    }
    public static func hit(point: CGPoint, canvas: CGSize, scale: CGFloat) -> OriginalUniversalControl? {
        guard scale.isFinite, scale > 0 else { return nil }
        let local = CGPoint(x: point.x / scale, y: point.y / scale)
        let canvas = CGSize(width: canvas.width / scale, height: canvas.height / scale)
        return all.reversed().first { $0.rect(canvas: canvas).contains(local) }
    }
}
