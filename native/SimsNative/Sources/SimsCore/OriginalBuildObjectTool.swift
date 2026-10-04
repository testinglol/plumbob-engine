import Foundation

public enum OriginalBuildObjectTool: String, CaseIterable {
    case door, window, stairs, plants, fireplace, hand

    public var category: Int? {
        switch self {
        case .door: return 8
        case .window: return 9
        case .stairs: return 10
        case .plants: return 11
        case .fireplace: return 12
        case .hand: return nil
        }
    }
    public var buttonIndex: Int {
        switch self {
        case .door: return 8
        case .window: return 9
        case .stairs: return 4
        case .plants: return 6
        case .fireplace: return 5
        case .hand: return 11
        }
    }
    public var label: String {
        switch self {
        case .door: return "Doors"
        case .window: return "Windows"
        case .stairs: return "Stairs"
        case .plants: return "Trees and plants"
        case .fireplace: return "Fireplaces"
        case .hand: return "Move objects"
        }
    }
    public static func catalogTool(category: Int) -> Self? {
        allCases.first { $0.category == category }
    }
}
