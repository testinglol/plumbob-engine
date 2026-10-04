import AppKit
import MetalKit
import SimsCore

final class GameActionButton: NSAccessibilityElement {
    let pressed: @MainActor @Sendable () -> Void

    init(pressed: @escaping @MainActor @Sendable () -> Void) {
        self.pressed = pressed
        super.init()
    }

    override func accessibilityPerformPress() -> Bool {
        let action = pressed
        if Thread.isMainThread {
            MainActor.assumeIsolated { action() }
        } else {
            Task { @MainActor in action() }
        }
        return true
    }
}

@MainActor
final class GameMetalView: MTKView {
    var roomFillRequested: ((CGPoint, Bool) -> Bool)?
    private var roomFillGesture = false
    var primaryPressed: ((CGPoint, Bool, Bool) -> Bool)?
    var primaryDragged: ((CGPoint) -> Void)?
    var primaryReleased: ((CGPoint) -> Void)?
    private var primaryGesture = false
    var clicked: ((CGPoint) -> Void)?
    var hovered: ((CGPoint) -> Void)?
    var menuDismissed: (() -> Void)?
    var menuAccessibility: (() -> [(label: String, rect: CGRect)])?
    var gameplayAccessibility: (() -> [(label: String, rect: CGRect)])?
    var dialogKey: ((String) -> Bool)?
    var speedChanged: ((Int) -> Void)?
    var pauseToggled: (() -> Void)?
    var simSelected: (() -> Void)?
    var wallsToggled: (() -> Void)?
    var storyChanged: ((Int) -> Void)?
    var buildModeToggled: (() -> Void)?
    var buyBrowserToggled: (() -> Void)?
    var heldObjectSold: (() -> Void)?
    var heldObjectRotated: (() -> Void)?
    var cameraMoved: ((SIMD2<Float>) -> Void)?
    var cameraRotated: ((Int) -> Void)?
    var zoomChanged: ((Float) -> Void)?

    override var acceptsFirstResponder: Bool { true }

    override func updateTrackingAreas() {
        super.updateTrackingAreas()
        for area in trackingAreas { removeTrackingArea(area) }
        addTrackingArea(NSTrackingArea(rect: .zero, options: [.mouseMoved, .mouseEnteredAndExited, .activeInKeyWindow, .inVisibleRect], owner: self))
    }

    override func mouseMoved(with event: NSEvent) {
        let point = convert(event.locationInWindow, from: nil)
        hovered?(CGPoint(x: point.x * drawableSize.width / bounds.width, y: (bounds.height - point.y) * drawableSize.height / bounds.height))
    }

    override func mouseExited(with event: NSEvent) { hovered?(CGPoint(x: -1, y: -1)) }
    override func rightMouseDown(with event: NSEvent) { primaryGesture = false; roomFillGesture = false; menuDismissed?() }

    private struct ActionBounds: Equatable {
        let label: String
        let rect: CGRect
    }
    private var actionBounds: [ActionBounds] = []
    private var actionButtons: [GameActionButton] = []
    var dialogIsVisible: (() -> Bool)?

    override func accessibilityChildren() -> [Any]? { actionButtons }

    func refreshAccessibilityButtons() {
        let menu = menuAccessibility?() ?? []
        var items = menu.map { ActionBounds(label: $0.label, rect: $0.rect) }
        if dialogIsVisible?() != true {
            items += (gameplayAccessibility?() ?? []).map { ActionBounds(label: $0.label, rect: $0.rect) }
            items += OriginalUniversalControl.all.filter(\.enabled).map { ActionBounds(label: $0.label, rect: $0.rect(canvas: bounds.size)) }
            items += OriginalSpeedControl.all.map { control in
                ActionBounds(label: control.speed == 0 ? "Pause / Resume" : "Speed \(control.speed)",
                             rect: CGRect(x: control.position.x, y: bounds.height - OriginalSpeedControl.panelHeight + control.position.y, width: control.size.width, height: control.size.height))
            }
        }
        guard items != actionBounds else { return }
        actionBounds = items
        actionButtons = items.map { item in
            let button = GameActionButton { [weak self] in
                guard let self else { return }
                self.clicked?(CGPoint(x: item.rect.midX * self.drawableSize.width / self.bounds.width,
                                      y: item.rect.midY * self.drawableSize.height / self.bounds.height))
                self.window?.makeFirstResponder(self)
            }
            button.setAccessibilityRole(.button)
            button.setAccessibilityParent(self)
            button.setAccessibilityEnabled(true)
            button.setAccessibilityFrameInParentSpace(CGRect(x: item.rect.minX, y: bounds.height - item.rect.maxY, width: item.rect.width, height: item.rect.height))
            button.setAccessibilityLabel(item.label)
            return button
        }
        NSAccessibility.post(element: self, notification: .layoutChanged)
    }

    override func mouseDown(with event: NSEvent) {
        window?.makeFirstResponder(self)
        let point = convert(event.locationInWindow, from: nil)
        let location = CGPoint(x: point.x * drawableSize.width / bounds.width, y: (bounds.height - point.y) * drawableSize.height / bounds.height)
        roomFillGesture = event.modifierFlags.contains(.shift) && roomFillRequested?(location, event.modifierFlags.contains(.option)) == true
        if roomFillGesture { primaryGesture = false; return }
        primaryGesture = primaryPressed?(location, event.modifierFlags.contains(.shift), event.modifierFlags.contains(.option)) == true
        if !primaryGesture { clicked?(location) }
    }

    override func mouseUp(with event: NSEvent) {
        if roomFillGesture { roomFillGesture = false; return }
        guard primaryGesture else { return }
        primaryGesture = false
        let point = convert(event.locationInWindow, from: nil)
        primaryReleased?(CGPoint(x: point.x * drawableSize.width / bounds.width, y: (bounds.height - point.y) * drawableSize.height / bounds.height))
    }

    override func mouseDragged(with event: NSEvent) {
        if roomFillGesture { return }
        if primaryGesture {
            let point = convert(event.locationInWindow, from: nil)
            primaryDragged?(CGPoint(x: point.x * drawableSize.width / bounds.width, y: (bounds.height - point.y) * drawableSize.height / bounds.height))
            return
        }
        menuDismissed?()
        cameraMoved?(SIMD2(Float(event.deltaX * drawableSize.width / bounds.width), Float(event.deltaY * drawableSize.height / bounds.height)))
    }

    override func scrollWheel(with event: NSEvent) {
        menuDismissed?()
        zoomChanged?(Float(exp(-event.scrollingDeltaY * 0.02)))
    }

    override func keyDown(with event: NSEvent) {
        if let key = event.characters, dialogKey?(key) == true { return }
        switch event.charactersIgnoringModifiers {
        case "\u{1b}": menuDismissed?()
        case "p", " ": pauseToggled?()
        case "1": speedChanged?(1)
        case "2": speedChanged?(3)
        case "3": speedChanged?(10)
        case "\t": simSelected?()
        case "w": wallsToggled?()
        case "\u{f72c}": storyChanged?(1)
        case "\u{f72d}": storyChanged?(-1)
        case "b": buyBrowserToggled?()
        case "\u{f706}": buildModeToggled?()
        case "r": heldObjectRotated?()
        case "[": cameraRotated?(-1)
        case "]": cameraRotated?(1)
        case "\u{7f}", "\u{f728}": heldObjectSold?()
        default: super.keyDown(with: event)
        }
    }
}
