namespace SimsSimulation;

public sealed class DirectPackOverlay
{
    public required string PackStackJson { get; init; }
    public required IReadOnlyDictionary<string, string> PluginFolders { get; init; }
    public required IReadOnlyDictionary<string, string> ResourcePaths { get; init; }
    public IReadOnlyList<string> DisabledDownloadFolders { get; init; } = [];
}
