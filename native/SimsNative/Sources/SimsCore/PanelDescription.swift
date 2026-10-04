import Foundation

/// A versioned, declarative panel contributed by a pack. Packs describe layout and bindings only; the Swift client
/// draws every element with original-game primitives (dialog frame, bitmap font, button sheets) inside the 800×600
/// logical interface. Plugins supply values for `binding` names and receive `action` names from buttons.
public struct PanelDescription: Codable, Sendable, Equatable {
    public static let supportedSchemaVersions: ClosedRange<Int> = 1...1
    public static let logicalWidth = 800
    public static let logicalHeight = 600
    public static let maximumElements = 64
    public static let titleHeight = 36
    public static let closeBandHeight = 44

    public struct Rect: Codable, Sendable, Equatable {
        public let x: Int
        public let y: Int
        public let width: Int
        public let height: Int

        public init(x: Int, y: Int, width: Int, height: Int) {
            self.x = x; self.y = y; self.width = width; self.height = height
        }

        public var cgRect: CGRect { CGRect(x: x, y: y, width: width, height: height) }

        func contains(_ other: Rect) -> Bool {
            other.x >= x && other.y >= y && other.x + other.width <= x + width && other.y + other.height <= y + height
        }
    }

    public enum Kind: String, Codable, Sendable {
        /// Static or bound text in the original bitmap font.
        case label
        /// An original-art button that sends `action` to the owning plugin.
        case button
        /// A horizontal bar like the original needs meters; `binding` supplies a number between `minimum` and `maximum`.
        case meter
        /// An image read from the original or pack-provided `UIGraphics` resources.
        case image
        /// Bound text split into rows by newline characters.
        case list
    }

    public struct Element: Codable, Sendable, Equatable {
        public let id: String
        public let kind: Kind
        public let frame: Rect
        public var text: String? = nil
        public var binding: String? = nil
        public var action: String? = nil
        public var resource: String? = nil
        public var minimum: Double? = nil
        public var maximum: Double? = nil
        public var accessibilityLabel: String? = nil
    }

    public let schemaVersion: Int
    public let id: String
    public let title: String
    public let frame: Rect
    /// Draws the original dialog frame behind the panel when true or omitted.
    public var framed: Bool? = nil
    public let elements: [Element]

    public func validate() throws {
        guard Self.supportedSchemaVersions.contains(schemaVersion) else {
            throw ContentError.invalid("Panel \(id) uses unsupported schema version \(schemaVersion)")
        }
        guard Self.isIdentifier(id) else { throw ContentError.invalid("Panel ID \(id) must be 1–64 lowercase letters, digits, dots, underscores or hyphens") }
        guard !title.isEmpty, title.count <= 128 else { throw ContentError.invalid("Panel \(id) title must be 1–128 characters") }
        let screen = Rect(x: 0, y: 0, width: Self.logicalWidth, height: Self.logicalHeight)
        guard frame.width >= 32, frame.height >= 32, screen.contains(frame) else {
            throw ContentError.invalid("Panel \(id) frame must fit the 800×600 logical interface")
        }
        guard elements.count <= Self.maximumElements else { throw ContentError.invalid("Panel \(id) has more than \(Self.maximumElements) elements") }
        // The renderer reserves the title band and the bottom band for the original title text and close button.
        guard frame.width >= 140, frame.height >= Self.titleHeight + Self.closeBandHeight + 8 else {
            throw ContentError.invalid("Panel \(id) must be at least 140×\(Self.titleHeight + Self.closeBandHeight + 8)")
        }
        let local = Rect(x: 0, y: Self.titleHeight, width: frame.width, height: frame.height - Self.titleHeight - Self.closeBandHeight)
        var ids = Set<String>()
        for element in elements {
            let name = "Panel \(id) element \(element.id)"
            guard Self.isIdentifier(element.id), ids.insert(element.id).inserted else {
                throw ContentError.invalid("\(name) needs a unique identifier")
            }
            guard element.frame.width > 0, element.frame.height > 0, local.contains(element.frame) else {
                throw ContentError.invalid("\(name) must lie inside the panel content area; element frames are relative to the panel, below its \(Self.titleHeight)-point title band and above its \(Self.closeBandHeight)-point close band")
            }
            if let text = element.text, text.count > 256 { throw ContentError.invalid("\(name) text exceeds 256 characters") }
            if let label = element.accessibilityLabel, label.count > 256 { throw ContentError.invalid("\(name) accessibility label exceeds 256 characters") }
            if let binding = element.binding, !Self.isIdentifier(binding) { throw ContentError.invalid("\(name) has an invalid binding") }
            switch element.kind {
            case .label, .list:
                guard element.text != nil || element.binding != nil else { throw ContentError.invalid("\(name) needs text or a binding") }
                guard element.action == nil, element.resource == nil else { throw ContentError.invalid("\(name) cannot have an action or resource") }
            case .button:
                guard let action = element.action, Self.isIdentifier(action) else { throw ContentError.invalid("\(name) needs a valid action") }
                guard element.text != nil || element.binding != nil else { throw ContentError.invalid("\(name) needs text or a binding") }
            case .meter:
                guard element.binding != nil else { throw ContentError.invalid("\(name) needs a binding") }
                let minimum = element.minimum ?? 0, maximum = element.maximum ?? 100
                guard minimum.isFinite, maximum.isFinite, minimum < maximum else { throw ContentError.invalid("\(name) needs minimum below maximum") }
            case .image:
                guard let resource = element.resource else { throw ContentError.invalid("\(name) needs a UIGraphics resource") }
                let key = try resourceKey(resource)
                guard key.hasPrefix("uigraphics/"), ["bmp", "tga"].contains(key.split(separator: ".").last.map(String.init) ?? "") else {
                    throw ContentError.invalid("\(name) resource must be a BMP or TGA under UIGraphics")
                }
            }
        }
    }

    /// Text shown for an element given the plugin's current binding values.
    public func displayText(for element: Element, values: [String: String]) -> String {
        if let binding = element.binding, let value = values[binding] { return value }
        return element.text ?? ""
    }

    /// Fill fraction for a meter element, clamped to 0...1; nil when the bound value is missing or not numeric.
    public func meterFraction(for element: Element, values: [String: String]) -> Double? {
        guard element.kind == .meter, let binding = element.binding, let raw = values[binding], let value = Double(raw), value.isFinite else { return nil }
        let minimum = element.minimum ?? 0, maximum = element.maximum ?? 100
        return min(1, max(0, (value - minimum) / (maximum - minimum)))
    }

    static func isIdentifier(_ value: String) -> Bool {
        (1...64).contains(value.count) && value.allSatisfy { $0.isASCII && ($0.isLowercase || $0.isNumber || $0 == "." || $0 == "_" || $0 == "-") }
    }
}
