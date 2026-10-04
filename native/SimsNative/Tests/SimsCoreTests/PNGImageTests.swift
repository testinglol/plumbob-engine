import Foundation
import XCTest
@testable import SimsCore

final class PNGImageTests: XCTestCase {
    func testPNGPreservesRowOrderAndStraightAlphaForMetalTextures() throws {
        let data = try XCTUnwrap(Data(base64Encoded: "iVBORw0KGgoAAAANSUhEUgAAAAIAAAACCAYAAABytg0kAAAAGElEQVR4nGP4z8Dwn+E/QwMDA8N/EGAAAEPTCHlKSuRGAAAAAElFTkSuQmCC"))
        let image = try PNGImage(data: data, width: 2, height: 2)
        XCTAssertEqual(Array(image.rgba.prefix(12)), [255, 0, 0, 255, 0, 255, 0, 128, 0, 0, 255, 255])
        XCTAssertEqual(image.rgba[15], 0)
        XCTAssertThrowsError(try PNGImage(data: data, width: 1, height: 2))
        XCTAssertThrowsError(try PNGImage(data: data, width: 4097, height: 2))
        XCTAssertThrowsError(try PNGImage(data: Data(data.prefix(20)), width: 2, height: 2))
    }

    /// 13×11 images in every colour type, filter type and both interlace modes; expected pixels were cross-checked
    /// against an independent decoder when the fixtures were made. 16-bit samples keep their high byte.
    func testDecodesEveryColourTypeFilterAndInterlace() throws {
        let cases: [(String, String, String)] = [
        ("palette4BitTransparency", "iVBORw0KGgoAAAANSUhEUgAAAA0AAAALBAMAAABWnBpSAAAAMFBMVEWlTcoYJTC7HW0TLN7WI3su2R4/ch/LGXEXRJTWSTydXDRgvjEgHmn+2qDu6LmZf1xpd12KAAAACnRSTlN8KZn9r+WTJTzWAa+SjgAAAGNJREFUeNoBWACn/wBaT9Eqq/4gASjKJ9DiQ6ICK/9QXgHkoAPDlmJM9GYHBFspHZR718UAQezMw/wWIAFu5U6PE21wAv71GsP8P9ADXNYpKGw6LgQASLPScMhwAG+wCPhr67ClWycdzQNz5wAAAABJRU5ErkJggg==", "81d952f8d9ca354435c8b1e2e7d0dbcae4f85c8a544babbd62718942cd84f027"),
        ("grey2Bit", "iVBORw0KGgoAAAANSUhEUgAAAA0AAAALAgAAAADLaUAcAAAAQklEQVR42gE3AMj/ABHZzgABN0GERAIaZlTAA019MAsEui3aAADCwWDAAQ5h+NkCwRixAAMyQ2A2BFS1jdEA6BChgPQcE19nRGimAAAAAElFTkSuQmCC", "4944cab3613fc1ef77bd360c64f6eb359f327c24ad9581f3c27a1dc2bf0ea7a1"),
        ("greyAlpha8BitInterlaced", "iVBORw0KGgoAAAANSUhEUgAAAA0AAAALCAQAAAF5vP98AAABP0lEQVR42gE0Acv+AELYhSoBUQF6PACOHa3VAbDAGQcALoeZm0yRKw8ATP0liYc+AcwVg7KMgAIDhVo5uToA5DbJna9lsRskghwrfJYBJ/U+Mh10dIQ8UGB+qnkC0SSMrRbnhHsL5tgRboAAhM+nLV3ZCC1xIugFAd39kXjZWvs4mkznPQJQTFuWMFxk9m7DReUDffOdmOOcgwhZRW1qBGjPte9dN64kvllajQBBV6+Qhc/3yVImcOcAiUIWejhShhlcZ5+caZTkW4qxCYASBwlh830BF+tHZSuUeKK5IuvVbCFeGO5KTsN/MGRz8ZwC/lla5TcDGIPDUuKE2IXAa5WBe8ROduiFfcEDlQlH2Ltz0W031uMIfOceXxvAINQ3JWZIzC8EiI081ISlHIsJMhQ8uXOCHiOIFFpdo6lwfYbFvYVYMGChqgAAAABJRU5ErkJggg==", "1e46e3cc153fca9fb5f9e868681455cad44b6408cda8bae7be189fa11145d016"),
        ("rgb8BitKey", "iVBORw0KGgoAAAANSUhEUgAAAA0AAAALCAIAAAAr0JA2AAAABnRSTlMAyAAKABSgjvUgAAAAcklEQVR42nWRyxHAIAhEN34uni3GgizLgigrRiIBnDgMPFR2QEGlwhpZz3A9Cd7VgD8OHNwBFrdtkyPl0vfVrgSGqpmcRE8DKfm9ebQMlX5zzKBlnKr0HTi4MemoichlrAnEM7TlZT+5h9BgU9u1+xWBGzNdL42OqCfoAAAAAElFTkSuQmCC", "ed99021b01582861ce03f233c9c1b7a084d696350782cd393d963e57788046ce"),
        ("rgba8BitInterlaced", "iVBORw0KGgoAAAANSUhEUgAAAA0AAAALCAYAAAHTtTf3AAACXUlEQVR42gFSAq39AJ/Bv6nPFMARASnnWXPaJoYEALae3SyijZgBAW8rB1bZ4wi/AL1XSrKhG8YsP0x+Yrzk4FsAKI8ps+RipbpjIK25ATfE+2W7mXSw1YwtwgII54u1tQVYk5BhdDYAib6ChX14TpCAfXYz83blvxlhYyYDNrNvFmiCEwFlXc5SIt1KZjdNqAQk7ppcHpwXNBgyiSidWDxCAi6+NGB2d22ZlrFpP+tV0sCGyuZ2mmRVcs7bCvUA4lY3Adc/asIZ8mS+8g/Sfu0gH4OLqxaGAWXgfl/7x6NrjWsTOCeEQzuqxW5IVWHJwwIsctnDOpn1LWVfm2K4uk16V7jAt4rDK38DRn6VRVPCFiOuZQGTDP3oMD6TNEx/XURBBKfetr36qhFBO5m+KONKiVEjj9g2Iis3rwD7MPtekW12/zWntjAMvmmbd+tAEaVW7eAAIQx3NvPuxYDc/EP+XQSbTXino+u5KGXIUX7QIRH2plLaNSSHK2ox1//kWHdE1et4PpaWjwFoBafRVln4VqqyXtC4wDbTL14gATujPtJLSQ4Z/7tqBJDzxq6fFoFwN1B/4rElc00v9YkmAqP8Ux26hks0irw5KyHnqfHftMFJuFkPi0anpldNY1qJl8uFCR7VMXlrXhqPl6Iof19b8+UDbdMdzfPgMQKXROgTpNJ0xwBEbda2OFDmZJpsks/GnjPsAozNueL5kBFcwRCstbdityJ0awTUQojT26XMCqMvGEiCA/GoxMZtLiefdJokethv61+rC58Jh5SNUy8cTM7e4bI81Z9URiHUmMoYqGSQJ/0AAAAASUVORK5CYII=", "ae0a4d30c9cfc0258ff22c5d96a0a808f16c968f8b0d3176fadd61e2ab2220da"),
        ("rgba16Bit", "iVBORw0KGgoAAAANSUhEUgAAAA0AAAALEAYAAAD0ItsiAAAEjklEQVR42gGDBHz7AOyNedNiFYjzml9PJk/dfsKnM7J/UmR48Kf5YOiEcjQfVEY0CWQPxLpNSkvwmq2YRd6ujDJkczfzNrePxWmzxtTthhFfBnXMTN+AceWXqe0yC1JIm4OxzzYC03wM3CzXoXUGdQtc7j+ZAehl3XSgQ4UFSrb5X9zYR9keAKo0XMQrTJn0ign5tmaQvuf7YfZvnRKPgQ4WuZx1whziU8YyqMQzl4YCpkFL1X7UhkeX34bhsa4rr5H221W6S3C+4rlOTs4NgLCmnjt6WGP+Cq241K55Ap9dWnzSpRZem/CaQkyUILwccdQ2alQsHHnY5iWiH+0pDdfOKSimnOgKnt3ONQEGcDaSWknPiadpdk2OnQ7Oh7v6487iyG+7EYr3miwTb+0SA5AyOBr2ObVat18Gh8JBEoo5MVwuj7cbA+F8e4tHj+bI0aD0k7u2WJ5XEem9GqRJvMxUjxkqWtmTeUjtqmXgYy6dxY5pGfssxhb+ybxuriQZsmVZjHbQhDqR+8SIO7nezwvTl9i397AWoE5H0U9E5ZhNhnWfXD/ZfvMmoA71ybQUBIVUmhp34sUuoObhu3ZY3KGP/5wyw5jtEm7HRZkBziwD4ae9HrBfoEDfGidqvYk1C8HMOqq46bVCOcBxNlIj8+2u4fpBo1pQ6z7v2plyJ92h0R3HeiiE2jZoieq/8bwF07ytG1y27jQLACp/bMwUNepvWQkz5VzTEu7X2DOCBt+83EcDnmKEGJqlXpvX9BGIow8KcNyBG/b+2xQpPNnXls8u5Jciagc8xjdPgvNt0yg0Pyp18cNsr020B/PanwJyBMY+Sy0gb70+IUII8dUJGo0HAXwK5sxf9BmrP0lkV8w0fWtEs6GuV+qE4BFYGgWd7u2UGG3CToBDmHUsMjLcf1gC8Gg056DS7rRMjgBbIMl0/sCLzrl0DIKU1LZCtr/QNKiAlMoADnI8vhB/9TFrdxNzfChT5TH5+ycxAhUDGhBFq20CzueOLiVff5GUs100yTFyP++erMAMjfGom6ifetiQ/3PJe9F+0KPI1sY7JCzVkpYl4rZ6EGcUJD/24JCu39oNNNwatuXXM9MnECiygo1xbGUZwPOnzki+QFCCPPBIhU9JA3ZF7dnXigyd/m0tP3TpXdZw1AXjlMPbW3Q8/fpnkd/J/V7IPGbqraoHxJbIxPgQg9pOtgxximZz1mRWGZjNqHuHxdYCGytOEn7AQ9QIgCj6/9harsI/Tfjf6/K8JPrAMSVSNw3ojmHNBGAOIfLvPDUY2dQOAoOouxcBJNLKVKtO2enxBQRsEg2T5DdSnday/Lc9sHMLFeTwZ18AhHQfdfheDgdSzVUwZrl3XMTvrY8KMrYRrvoiI5SSQn1kUlBxLsAmRQ2XjjpKQdL4lno2fGLRAFxI5xpKF+DATH2IZdYm0tV+Vk+2DQOKzpfVq0RV6YV2+2U37qLZ6ZH3ATp0ToYdG2wc9HWSjT0Gg/1nOrqC3TaF5nozee4x9MfBlC/UzlMLHW6WSEnoCDTiXK6LR8Di0QD8kqJfI7heZxxAdxhARIEAAAAASUVORK5CYII=", "c9444577dffed00042d9b5fe04937228bab993c7374f8255f762518cc08412ec"),
        ]
        for (name, encoded, expected) in cases {
            let data = try XCTUnwrap(Data(base64Encoded: encoded), name)
            let image = try PNGImage(data: data, width: 13, height: 11)
            XCTAssertEqual(image.rgba.count, 13 * 11 * 4, name)
            XCTAssertEqual(SHA256Digest.hex(image.rgba), expected, name)
        }
    }
}
