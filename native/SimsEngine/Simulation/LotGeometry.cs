namespace SimsEngine.Simulation;

public static class LotGeometry
{
    public const int LotDimension = 0x40;
    public const int MaxSupportedStories = 16;

    public static int NormalizeOrientation(int orientation) => orientation & 3;

    public static ObjectPosition TransformSearchCenter(ObjectPosition position, int orientation)
    {
        orientation = NormalizeOrientation(orientation);
        return orientation switch
        {
            0 => position,
            1 => position with { X = 0x3ff - position.Y, Y = position.X },
            2 => position with { X = 0x3ff - position.X, Y = 0x3ff - position.Y },
            _ => position with { X = position.Y, Y = 0x3ff - position.X },
        };
    }

    public static bool TryTransformTile(sbyte x, sbyte y, int orientation, out sbyte transformedX, out sbyte transformedY)
    {
        transformedX = x;
        transformedY = y;
        if (orientation is < 1 or > 3 || x is < 0 or >= 64 || y is < 0 or >= 64) return false;

        (var tx, var ty) = orientation switch
        {
            1 => (63 - y, (int)x),
            2 => (63 - x, 63 - y),
            3 => ((int)y, 63 - x),
            _ => throw new InvalidOperationException("Validated lot orientation must be between 1 and 3."),
        };
        transformedX = (sbyte)tx;
        transformedY = (sbyte)ty;
        return true;
    }

    public static LotCoordinateBounds TransformLotBounds(int dimension, int orientation)
    {
        if (dimension is < 1 or > 64) throw new ArgumentOutOfRangeException(nameof(dimension), "Lot dimension must fit the 64 × 64 transform table.");
        orientation = NormalizeOrientation(orientation);
        var edge = (sbyte)(dimension - 1);
        Span<(sbyte X, sbyte Y)> corners = [(0, 0), (edge, 0), (0, edge), (edge, edge)];
        var minX = int.MaxValue;
        var maxX = int.MinValue;
        var minY = int.MaxValue;
        var maxY = int.MinValue;
        foreach (var corner in corners)
        {
            var x = corner.X;
            var y = corner.Y;
            if (orientation != 0 && !TryTransformTile(x, y, orientation, out x, out y))
                throw new InvalidOperationException("A validated lot corner must be covered by the transform table.");
            minX = Math.Min(minX, x);
            maxX = Math.Max(maxX, x);
            minY = Math.Min(minY, y);
            maxY = Math.Max(maxY, y);
        }
        return new LotCoordinateBounds(minX, maxX, minY, maxY);
    }

    public static (int X, int Y) FootprintOffset(short direction) => (direction & 7) switch
    {
        0 => (0, -16),
        1 => (16, -16),
        2 => (16, 0),
        3 => (16, 16),
        4 => (0, 16),
        5 => (-16, 16),
        6 => (-16, 0),
        7 => (-16, -16),
        _ => throw new InvalidOperationException("A three-bit direction must be between 0 and 7."),
    };

    public static ObjectPosition SlotPosition(ObjectPosition anchor, short direction, float slotX, float slotY)
    {
        var angle = (direction & 7) * (MathF.PI / 4f);
        var sin = MathF.Sin(angle);
        var cos = MathF.Cos(angle);
        var x = MathF.Round(cos * slotX - sin * slotY, MidpointRounding.AwayFromZero);
        var y = MathF.Round(sin * slotX + cos * slotY, MidpointRounding.AwayFromZero);
        return anchor with { X = checked(anchor.X + (int)x), Y = checked(anchor.Y + (int)y) };
    }
}
