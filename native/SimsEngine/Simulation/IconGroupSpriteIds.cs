namespace SimsEngine.Simulation;

internal static class IconGroupSpriteIds
{
    private static readonly short[] DefaultGroupZero =
    [
        200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213,
        400, 401, 402, 403, 0,
    ];

    private static readonly short[] BaseSprites = [-1, 100, 400, 200, 300, 500, 600, -1, 700, 800, 900];

    public static short GetSpriteId(int group, int icon)
    {
        if ((uint)group >= BaseSprites.Length) return 0;
        var baseSprite = BaseSprites[group];
        if (baseSprite == -1)
            return group == 0 && (uint)icon < DefaultGroupZero.Length ? DefaultGroupZero[icon] : (short)0;
        return unchecked((short)(baseSprite + icon));
    }

    public static short GetBalloonSpriteId(int type) =>
        type is >= 0 and < 3 ? unchecked((short)(BaseSprites[1] + type)) : (short)0;
}
