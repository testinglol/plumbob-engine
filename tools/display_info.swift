import AppKit

let screens = NSScreen.screens
let values = screens.map { screen -> [String: Any] in
    let identifier = screen.deviceDescription[NSDeviceDescriptionKey("NSScreenNumber")] as? UInt32 ?? 0
    return [
        "name": screen.localizedName,
        "width": Int(screen.frame.width),
        "height": Int(screen.frame.height),
        "availableWidth": Int(screen.visibleFrame.width),
        "availableHeight": Int(screen.visibleFrame.height),
        "scale": screen.backingScaleFactor,
        "pixelWidth": Int(CGDisplayPixelsWide(identifier)),
        "pixelHeight": Int(CGDisplayPixelsHigh(identifier))
    ]
}
let data = try JSONSerialization.data(withJSONObject: values, options: [.prettyPrinted, .sortedKeys])
print(String(data: data, encoding: .utf8)!)
