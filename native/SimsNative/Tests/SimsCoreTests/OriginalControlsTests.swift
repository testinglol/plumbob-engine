import Foundation
import XCTest
@testable import SimsCore

final class OriginalControlsTests: XCTestCase {
    func testUniversalControlsUseOriginalCoordinatesWithoutInterceptingSpeedButtons() {
        for scale: CGFloat in [1, 2, 3] {
            let logical = CGSize(width: 800, height: 600)
            let canvas = CGSize(width: logical.width * scale, height: logical.height * scale)
            for control in OriginalUniversalControl.all {
                let rect = control.rect(canvas: logical)
                let point = CGPoint(x: rect.midX * scale, y: rect.midY * scale)
                XCTAssertEqual(OriginalUniversalControl.hit(point: point, canvas: canvas, scale: scale)?.action, control.action)
            }
            for control in OriginalSpeedControl.all {
                let point = CGPoint(x: (control.position.x + control.size.width / 2) * scale,
                                    y: (logical.height - 183 + control.position.y + control.size.height / 2) * scale)
                XCTAssertNil(OriginalUniversalControl.hit(point: point, canvas: canvas, scale: scale))
            }
        }
        XCTAssertEqual(OriginalUniversalControl.all.first { $0.action == .live }?.position, CGPoint(x: 10, y: 6))
        XCTAssertEqual(OriginalUniversalControl.all.first { $0.action == .buy }?.position, CGPoint(x: 69, y: 20))
        XCTAssertTrue(OriginalUniversalControl.all.first { $0.action == .build }!.enabled)
        XCTAssertNil(OriginalUniversalControl.hit(point: .zero, canvas: CGSize(width: 800, height: 600), scale: 0))
    }
    func testSpeedHitTestingUsesTheSameCoordinatesAtRetinaScale() {
        for scale in [CGFloat(1), CGFloat(2), CGFloat(3)] {
            let canvas = CGSize(width: 1200 * scale, height: 900 * scale)
            for control in OriginalSpeedControl.all {
                let point = CGPoint(x: (control.position.x + control.size.width / 2) * scale,
                                    y: canvas.height - 183 * scale + (control.position.y + control.size.height / 2) * scale)
                XCTAssertEqual(OriginalSpeedControl.hit(point: point, canvas: canvas, scale: scale), control.speed)
            }
            XCTAssertNil(OriginalSpeedControl.hit(point: CGPoint(x: 0, y: 0), canvas: canvas, scale: scale))
        }
    }

    func testBuildHistoryControlsKeepOriginalPanelPositionAcrossBackingSizes() {
        let sourceImageSize = CGSize(width: 120, height: 24)
        let at800x600 = OriginalBuildLayout.historyControl(0, canvas: CGSize(width: 400, height: 300), imageSize: sourceImageSize)
        let redoAt800x600 = OriginalBuildLayout.historyControl(1, canvas: CGSize(width: 400, height: 300), imageSize: sourceImageSize)
        XCTAssertEqual(at800x600, CGRect(x: 231, y: 132, width: 30, height: 24))
        XCTAssertEqual(redoAt800x600, CGRect(x: 231, y: 170, width: 30, height: 24))
        XCTAssertEqual(CGRect(x: at800x600.minX * 2, y: at800x600.minY * 2,
                              width: at800x600.width * 2, height: at800x600.height * 2),
                       CGRect(x: 462, y: 264, width: 60, height: 48))

        let at1600x1200 = OriginalBuildLayout.historyControl(0, canvas: CGSize(width: 800, height: 600), imageSize: sourceImageSize)
        XCTAssertEqual(at1600x1200, CGRect(x: 231, y: 432, width: 30, height: 24))
        XCTAssertEqual(CGRect(x: at1600x1200.minX * 2, y: at1600x1200.minY * 2,
                              width: at1600x1200.width * 2, height: at1600x1200.height * 2),
                       CGRect(x: 462, y: 864, width: 60, height: 48))
        XCTAssertTrue(at800x600.contains(CGPoint(x: 240, y: 143)))
        XCTAssertTrue(redoAt800x600.contains(CGPoint(x: 240, y: 181)))
        XCTAssertFalse(at800x600.contains(CGPoint(x: 262, y: 143)))
        XCTAssertEqual(OriginalBuildLayout.historyControl(2, canvas: CGSize(width: 400, height: 300), imageSize: sourceImageSize), .zero)
    }

    func testBuildHistoryControlsUseOriginalEnabledAndDisabledFrames() {
        XCTAssertEqual(OriginalBuildLayout.historyFrameIndex(enabled: true), 0)
        XCTAssertEqual(OriginalBuildLayout.historyFrameIndex(enabled: false), 3)
    }
    func testBuildCatalogThumbnailsStayClearOfPageArrows() {
        let arrowSize = CGSize(width: 9, height: 49)
        for width: CGFloat in [800, 1024, 1600, 4096] {
            let canvas = CGSize(width: width, height: 600)
            let previous = OriginalBuildLayout.arrow(forward: false, size: arrowSize, canvas: canvas)
            let next = OriginalBuildLayout.arrow(forward: true, size: arrowSize, canvas: canvas)
            XCTAssertLessThanOrEqual(next.maxX, width)
            for index in 0..<OriginalBuildLayout.capacity(canvas: canvas) {
                let rect = OriginalBuildLayout.thumbnail(index, canvas: canvas)
                XCTAssertGreaterThanOrEqual(rect.minX, 558)
                XCTAssertLessThanOrEqual(rect.maxY, canvas.height - 5)
                XCTAssertFalse(rect.intersects(previous), "\(width) \(index)")
                XCTAssertFalse(rect.intersects(next), "\(width) \(index)")
            }
        }
        XCTAssertEqual(OriginalBuildLayout.columns(canvas: CGSize(width: 800, height: 600)), 5)
        XCTAssertEqual(OriginalBuildLayout.columns(canvas: CGSize(width: CGFloat.infinity, height: 600)), 1)
    }
}
