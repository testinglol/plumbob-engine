using System.Numerics;

namespace SimsSimulation;

internal static class AvatarCoordinates
{
    internal static Vector3 RootTranslation(float lotX, float lotY, float altitude) =>
        new(lotY, altitude, lotX);

    internal static float ElevationSample(float rootFtile) => MathF.Truncate(rootFtile + 0.5f) / 16f;

    internal static Vector3 ToLot(Vector3 sourceWorld) =>
        new(sourceWorld.Z, sourceWorld.X, sourceWorld.Y);
}
