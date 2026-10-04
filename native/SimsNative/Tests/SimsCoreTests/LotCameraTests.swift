import XCTest
@testable import SimsCore

final class LotCameraTests: XCTestCase {
    func testLotCameraTransformsRoundTripOnNonSquareLots() {
        let lotSize = SIMD2<Float>(7, 5)
        let points = [SIMD2<Float>(0, 0), SIMD2<Float>(7, 5), SIMD2<Float>(2.25, 3.75)]

        for camera in LotCamera.allCases {
            for point in points {
                XCTAssertEqual(camera.lotPoint(camera.cameraPoint(point, lotSize: lotSize), lotSize: lotSize), point)
            }
        }
    }

    func testQuarterTurnsPlaceLotCornersAtExpectedScreenCorners() {
        let lotSize = SIMD2<Float>(7, 5)
        let corners = [SIMD2<Float>(0, 0), SIMD2<Float>(7, 0), SIMD2<Float>(7, 5), SIMD2<Float>(0, 5)]
        let expected = [
            [SIMD2<Float>(0, 0), SIMD2<Float>(7, 0), SIMD2<Float>(7, 5), SIMD2<Float>(0, 5)],
            [SIMD2<Float>(5, 0), SIMD2<Float>(5, 7), SIMD2<Float>(0, 7), SIMD2<Float>(0, 0)],
            [SIMD2<Float>(7, 5), SIMD2<Float>(0, 5), SIMD2<Float>(0, 0), SIMD2<Float>(7, 0)],
            [SIMD2<Float>(0, 7), SIMD2<Float>(0, 0), SIMD2<Float>(5, 0), SIMD2<Float>(5, 7)]
        ]

        for camera in LotCamera.allCases {
            for index in corners.indices {
                XCTAssertEqual(camera.cameraPoint(corners[index], lotSize: lotSize), expected[camera.rawValue][index])
            }
        }
    }

    func testRotatedTileCoordinatesMapBackToSourceTiles() {
        let lotSize = SIMD2<Float>(7, 5)
        let integerSize = SIMD2<Int>(7, 5)

        for camera in LotCamera.allCases {
            for y in 0..<5 {
                for x in 0..<7 {
                    let center = SIMD2<Float>(Float(x) + 0.5, Float(y) + 0.5)
                    let cameraCenter = camera.cameraPoint(center, lotSize: lotSize)
                    let cameraTile = SIMD2<Int>(Int(cameraCenter.x), Int(cameraCenter.y))
                    XCTAssertEqual(camera.sourceTile(cameraTile, lotSize: integerSize), SIMD2(x, y))
                }
            }
        }
    }

    func testCameraProjectionKeepsAltitudeIndependentOfOrientation() {
        let lotSize = SIMD2<Float>(8, 6)
        let point = SIMD2<Float>(3, 2)
        let ground = LotCamera.topRight.projectedPoint(point, lotSize: lotSize)
        let elevated = LotCamera.topRight.projectedPoint(point, lotSize: lotSize, altitude: 40)

        XCTAssertEqual(elevated.x, ground.x)
        XCTAssertEqual(elevated.y, ground.y - 40)
    }
}
