import Foundation

public struct SimInteraction: Decodable, Equatable {
    public let name: String?
    public let interaction: UInt8
    public let param0: Int16
    public let global: Bool
}

public struct OriginalPieNode {
    public let label: String
    public let action: SimInteraction?
    public var children: [OriginalPieNode]

    public static func build(_ entries: [SimInteraction]) throws -> [OriginalPieNode] {
        guard entries.count <= 512 else { throw ContentError.invalid("Interaction menu exceeds size limit") }
        var roots: [OriginalPieNode] = []
        func insert(_ labels: ArraySlice<String>, action: SimInteraction, nodes: inout [OriginalPieNode]) {
            guard let label = labels.first else { return }
            if labels.count == 1 {
                nodes.append(OriginalPieNode(label: label, action: action, children: []))
            } else {
                let index: Int
                if let existing = nodes.firstIndex(where: { $0.label == label && $0.action == nil }) { index = existing }
                else { index = nodes.count; nodes.append(OriginalPieNode(label: label, action: nil, children: [])) }
                insert(labels.dropFirst(), action: action, nodes: &nodes[index].children)
            }
        }
        for entry in entries {
            guard let name = entry.name, !name.isEmpty else { continue }
            let labels = name.split(separator: "/", omittingEmptySubsequences: false).map(String.init)
            guard name.utf16.count <= 512, labels.count <= 16,
                  labels.allSatisfy({ !$0.isEmpty && !$0.unicodeScalars.contains(where: { $0.value < 32 }) }) else {
                throw ContentError.invalid("Invalid interaction menu label")
            }
            insert(labels[...], action: entry, nodes: &roots)
        }
        return roots
    }
}

public struct OriginalPieLayout {
    public let center: CGPoint
    public let rectangles: [CGRect]

    public init(anchor: CGPoint, sizes: [CGSize], viewport: CGSize) {
        let spokes = sizes.count <= 2 ? 2 : sizes.count <= 4 ? 4 : 8
        var rectangles: [CGRect] = []
        for (index, size) in sizes.enumerated() {
            let position: CGPoint
            if index >= spokes {
                let previous = rectangles[index == spokes ? 0 : index == spokes + 1 ? spokes / 2 : index - 2]
                position = CGPoint(x: -size.width / 2, y: index.isMultiple(of: 2) ? previous.minY - size.height : previous.maxY)
            } else {
                switch index * 8 / spokes {
                case 0: position = CGPoint(x: -size.width / 2, y: -40 - size.height)
                case 1: position = CGPoint(x: 20, y: -20 - size.height)
                case 2: position = CGPoint(x: 40, y: -size.height / 2)
                case 3: position = CGPoint(x: 20, y: 20)
                case 4: position = CGPoint(x: -size.width / 2, y: 40)
                case 5: position = CGPoint(x: -20 - size.width, y: 20)
                case 6: position = CGPoint(x: -40 - size.width, y: -size.height / 2)
                default: position = CGPoint(x: -20 - size.width, y: -20 - size.height)
                }
            }
            rectangles.append(CGRect(origin: position, size: size))
        }
        let bounds = rectangles.reduce(CGRect(x: -20, y: -20, width: 40, height: 40)) { $0.union($1) }.insetBy(dx: -4, dy: -4)
        func clamped(_ requested: CGFloat, minimum: CGFloat, maximum: CGFloat) -> CGFloat {
            maximum >= minimum ? min(maximum, max(minimum, requested)) : (minimum + maximum) / 2
        }
        let center = CGPoint(x: clamped(anchor.x, minimum: -bounds.minX, maximum: viewport.width - bounds.maxX),
                         y: clamped(anchor.y, minimum: -bounds.minY, maximum: viewport.height - bounds.maxY))
        self.center = center
        self.rectangles = rectangles.map { $0.offsetBy(dx: center.x, dy: center.y) }
    }

    public func hit(_ point: CGPoint) -> Int? {
        if let index = rectangles.firstIndex(where: { $0.contains(point) }) { return index }
        let x = point.x - center.x, y = point.y - center.y
        let radius = hypot(x, y)
        guard radius > 20, radius < 120, !rectangles.isEmpty else { return nil }
        let spokes = rectangles.count <= 2 ? 2 : rectangles.count <= 4 ? 4 : 8
        let angle = atan2(x, -y)
        let turn = angle / (2 * .pi)
        let index = Int(floor((turn < 0 ? turn + 1 : turn) * CGFloat(spokes) + 0.5)) % spokes
        return index < rectangles.count ? index : nil
    }
}
