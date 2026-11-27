namespace SimsSimulation;

internal static class SceneDepth
{
    private const float HalfStep = 1f / 97.97959f;

    public static float Project(float x, float y, float height) =>
        Math.Clamp(0.62f - (x + y + height * 0.81649658f) * 0.003f, 0.001f, 0.999f);

    public static (float Near, float Far) Sprite(float x, float y, float height) =>
        (Project(x + 0.5f + 200.5f * HalfStep, y + 0.5f + 200.5f * HalfStep, height),
         Project(x + 0.5f - 53.5f * HalfStep, y + 0.5f - 53.5f * HalfStep, height));
}
