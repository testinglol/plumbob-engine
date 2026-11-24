using System.Text.Json;
using SimsNative.Plugins;

namespace Local.Lighting;

public sealed class LightingPlugin : ISimsPlugin
{
    private const string PanelId = "lighting-settings";

    private IPluginContext _context = null!;
    private string? _publishedPanelSignature;
    private string? _publishedClientSignature;

    public void Initialize(IPluginContext context)
    {
        _context = context;
        PublishPanel();
    }

    public byte[] SaveState() => [];

    public void LoadState(int savedStateVersion, byte[] data)
    {
        _publishedPanelSignature = null;
        _publishedClientSignature = null;
    }

    public void OnWorldLoaded() => SyncState();

    public void OnTick(long update) => SyncState();

    private bool Flag(string key, bool fallback = true) =>
        _context.NeighborhoodValues.TryGetValue(key, out var val)
            ? !string.Equals(val, "off", StringComparison.OrdinalIgnoreCase)
            : fallback;

    private void Toggle(string key) =>
        _context.NeighborhoodValues[key] = Flag(key) ? "off" : "on";

    public void OnPanelAction(string panelId, string action)
    {
        if (panelId != PanelId) return;
        switch (action)
        {
            case "toggle-enabled": Toggle("enabled"); break;
            case "toggle-shadows": Toggle("shadows"); break;
            case "toggle-ao": Toggle("ao"); break;
            case "toggle-cycle": Toggle("cycle"); break;
            case "toggle-hd-lots": Toggle("hdLots"); break;
            default: return;
        }

        _publishedPanelSignature = null;
        _publishedClientSignature = null;
        SyncState();
    }

    private void SyncState()
    {
        PublishPanel();
        PublishClientState();
    }

    private void PublishPanel()
    {
        var enabled = Flag("enabled");
        var shadows = Flag("shadows");
        var ao = Flag("ao");
        var cycle = Flag("cycle");
        var hdLots = Flag("hdLots");
        var sig = $"{enabled}|{shadows}|{ao}|{cycle}|{hdLots}";
        if (_publishedPanelSignature == sig) return;
        _publishedPanelSignature = sig;
        _context.SetPanelValue(PanelId, "enabled", enabled ? "on" : "off");
        _context.SetPanelValue(PanelId, "shadows", shadows ? "on" : "off");
        _context.SetPanelValue(PanelId, "ao", ao ? "on" : "off");
        _context.SetPanelValue(PanelId, "cycle", cycle ? "on" : "off");
        _context.SetPanelValue(PanelId, "hdLots", hdLots ? "on" : "off");
    }

    private void PublishClientState()
    {
        int house = 0;
        int minutes = 720;
        try
        {
            var sim = _context.Simulation;
            house = sim.House;
            minutes = sim.Hours * 60 + sim.Minutes;
        }
        catch
        {
        }

        bool enabled = Flag("enabled");
        bool shadows = Flag("shadows");
        bool ao = Flag("ao");
        bool cycle = Flag("cycle");
        string sig = $"{house}|{minutes}|{enabled}|{shadows}|{ao}|{cycle}";
        if (string.Equals(_publishedClientSignature, sig, StringComparison.Ordinal))
            return;
        _publishedClientSignature = sig;

        byte[] payload = JsonSerializer.SerializeToUtf8Bytes(new
        {
            house,
            minutes,
            enabled,
            shadows,
            ao,
            cycle,
        });
        _context.PublishClientState(payload);
    }
}
