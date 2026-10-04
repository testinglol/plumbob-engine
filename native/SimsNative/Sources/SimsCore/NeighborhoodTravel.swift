import Foundation

public struct NeighborhoodTravel {
    public struct Response: Equatable {
        public let code: UInt8
        public let text: String
    }

    public static func mode(forDialogKind kind: UInt8) -> Int? {
        switch kind {
        case 5: 2
        case 7: 3
        case 8: 4
        case 11: 5
        case 13: 7
        default: nil
        }
    }

    public static func response(forDestination destination: Int) -> Response? {
        guard destination == -1 || (1...100).contains(destination) else { return nil }
        return Response(code: destination > 0 ? 1 : 0, text: String(destination))
    }
}
