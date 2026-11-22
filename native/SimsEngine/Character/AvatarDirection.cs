namespace SimsEngine.Character;

using System.Numerics;

public static class AvatarDirection
{
    public static float Angle(short direction) => Angle((float)direction);

    public static float RootDirection(float? animatorDirection, short objectDirection, float displacementDirection,
        float? inheritedRootDirection = null)
    {
        if (inheritedRootDirection is { } inherited && float.IsFinite(inherited)) return inherited;
        var direction = animatorDirection is { } animator && float.IsFinite(animator) ? animator : objectDirection;
        return direction + displacementDirection;
    }

    public static float Angle(float direction)
    {
        var wrapped = Wrap(direction);
        return wrapped * (MathF.PI / 4);
    }

    // Lot-space Y-axis rotation: rotating local +Z by (dir + 6) * pi/4 maps 0->(0,-1), 2->(+1,0), 4->(0,+1), 6->(-1,0).
    public static float LotFacingAngle(float direction) => Angle(direction + 6f);

    public static float Approach(float current, float target, float maximumStep)
        => Approach(current, target, maximumStep, out _);

    public static float Approach(float current, float target, float maximumStep, out bool clamped)
    {
        var delta = target - current;
        while (delta >= 4f) delta -= 8f;
        while (delta < -4f) delta += 8f;
        clamped = MathF.Abs(delta) > maximumStep;
        return Wrap(current + Math.Clamp(delta, -maximumStep, maximumStep));
    }

    // Lot-space octants: direction 0 = -Y, 2 = +X.
    public static float Toward(float deltaX, float deltaY)
    {
        var direction = MathF.Atan2(deltaY, deltaX) * (4f / MathF.PI) + 2f;
        return Wrap(direction);
    }

    public static short ToObjectDirection(float direction)
    {
        if (!float.IsFinite(direction)) return 0;
        var value = (int)MathF.Floor(direction + 0.5f);
        return (short)((value % 8 + 8) % 8);
    }

    public static float Wrap(float direction) => direction - MathF.Floor(direction / 8f) * 8f;

    public static float ShortestDelta(float from, float to)
    {
        var delta = to - from;
        while (delta >= 4f) delta -= 8f;
        while (delta < -4f) delta += 8f;
        return delta;
    }
}
