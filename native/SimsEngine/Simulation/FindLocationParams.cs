namespace SimsEngine.Simulation;

public sealed class FindLocationParams
{
    public bool UseCenter { get; set; } = true;
    public int CenterX { get; set; }
    public int CenterY { get; set; }
    public int Height { get; set; }
    public short Direction { get; set; } = -1;
    public byte ContinueFlag { get; set; } = 1;
    public byte FlagB { get; set; }
    public byte FlagC { get; set; }
    public bool RandomizeCenter { get; set; }
    public bool HasTarget { get; set; }
}
