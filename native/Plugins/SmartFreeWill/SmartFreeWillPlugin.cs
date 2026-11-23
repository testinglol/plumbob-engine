using System.Text.Json;
using SimsNative.Plugins;

namespace Local.SmartFreeWill;

public sealed class SmartFreeWillPlugin : ISimsPlugin, IPluginAutonomyDirector
{
    private const string PanelId = "smart-free-will";

    private sealed record Configuration(
        string Style = "drama",
        bool ThoughtBubbles = true,
        bool SparksAndTurfWars = true);

    private IPluginContext context = null!;
    private Configuration defaults = new();
    private readonly HouseholdBlackboard blackboard = new();
    private readonly BalloonDirector balloons = new();
    private readonly SimMindPlanner planner;
    private string? lastPublishedSignature;

    public SmartFreeWillPlugin()
    {
        planner = new SimMindPlanner(blackboard, balloons);
    }

    public void Initialize(IPluginContext context)
    {
        this.context = context ?? throw new ArgumentNullException(nameof(context));
        try
        {
            var raw = context.ReadPluginData("smart-free-will.json");
            var parsed = JsonSerializer.Deserialize<Configuration>(raw, new JsonSerializerOptions
            {
                PropertyNameCaseInsensitive = true,
            });
            if (parsed is not null)
                defaults = parsed;
        }
        catch
        {
            defaults = new Configuration();
        }
        PublishPanel(null);
    }

    public byte[]? SaveState() => blackboard.SerializeState();

    public void LoadState(int savedStateVersion, byte[] data)
    {
        lastPublishedSignature = null;
        blackboard.RestoreState(data);
        balloons.Reset();
    }

    private SmartSettings CurrentSettings => new(
        Style: ReadStyle(),
        ThoughtBubbles: ReadFlag("thoughtBubbles", defaults.ThoughtBubbles),
        SparksAndTurfWars: ReadFlag("sparks", defaults.SparksAndTurfWars));

    private SmartStyle ReadStyle()
    {
        if (context.NeighborhoodValues.TryGetValue("style", out var raw))
            return ParseStyle(raw, ParseStyle(defaults.Style, SmartStyle.Drama));
        if (context.NeighborhoodValues.TryGetValue("enabled", out var legacyEnabled) &&
            string.Equals(legacyEnabled, "off", StringComparison.OrdinalIgnoreCase))
        {
            return SmartStyle.Classic;
        }
        return ParseStyle(defaults.Style, SmartStyle.Drama);
    }

    private void WriteStyle(SmartStyle style)
    {
        context.NeighborhoodValues["style"] = style switch
        {
            SmartStyle.Classic => "classic",
            SmartStyle.Mastermind => "mastermind",
            _ => "drama",
        };
        if (style == SmartStyle.Classic)
        {
            blackboard.Reset();
            balloons.Reset();
        }
    }

    private static SmartStyle ParseStyle(string? raw, SmartStyle fallback) =>
        raw?.Trim().ToLowerInvariant() switch
        {
            "classic" or "vanilla" or "off" or "0" => SmartStyle.Classic,
            "mastermind" or "competent" or "career" => SmartStyle.Mastermind,
            "drama" or "sitcom" or "uncut" or "on" or "smart" or "1" => SmartStyle.Drama,
            _ => fallback,
        };

    private bool ReadFlag(string key, bool fallback)
    {
        if (context.NeighborhoodValues.TryGetValue(key, out var raw))
            return !string.Equals(raw, "off", StringComparison.OrdinalIgnoreCase);
        return fallback;
    }

    private void WriteFlag(string key, bool enabled)
    {
        context.NeighborhoodValues[key] = enabled ? "on" : "off";
        if (key == "thoughtBubbles" && !enabled)
            balloons.Reset();
    }

    public bool DirectsAutonomy(short simId, bool household)
    {
        if (!household)
            return false;
        if (!CurrentSettings.Enabled)
            return false;
        try
        {
            return context.Simulation.FreeWill;
        }
        catch
        {
            return false;
        }
    }

    public int? SelectAutonomyCandidate(PluginAutonomyContext autonomyContext, IReadOnlyList<PluginAutonomyCandidate> candidates)
    {
        var settings = CurrentSettings;
        if (!settings.Enabled || !autonomyContext.Household)
            return null;
        var lot = context.Simulation;
        if (!lot.FreeWill)
            return null;
        var selected = planner.SelectBestCandidate(lot, settings, autonomyContext, candidates);
        PublishPanel(lot);
        return selected;
    }

    public void OnPlayerCancelledAction(short simId, short targetObjectId, int interactionId)
    {
        try
        {
            var objects = context.Simulation.Objects;
            var leadId = objects.FirstOrDefault(o => o.ObjectId == targetObjectId)?.LeadObjectId ?? targetObjectId;
            blackboard.RecordPlayerCancellation(simId, leadId, interactionId);
        }
        catch
        {
            blackboard.RecordPlayerCancellation(simId, targetObjectId, interactionId);
        }
    }

    public void OnTick(long update)
    {
        var lot = context.Simulation;
        var settings = CurrentSettings;
        planner.UpdateTick(update);
        if (settings.Enabled)
            planner.AdvanceProactiveDirector(lot, settings, update);
        if (update % 30 == 0)
            PublishPanel(lot);
    }

    public IEnumerable<PluginMenuEntry> GetMenuEntries(short simId, PluginObject target)
    {
        if (simId != target.ObjectId)
            return [];
        var lot = context.Simulation;
        if (!lot.HouseholdSims.Any(s => s.ObjectId == simId))
            return [];
        var settings = CurrentSettings;
        var quickSwitchLabel = settings.Enabled
            ? "Smart Free Will/Use Classic Free Will"
            : "Smart Free Will/Use Sitcom Drama";
        var alternateLabel = settings.Style == SmartStyle.Mastermind
            ? "Smart Free Will/Switch to Sitcom Drama"
            : "Smart Free Will/Switch to Mastermind";
        return
        [
            new PluginMenuEntry("options", "Smart Free Will/Options..."),
            new PluginMenuEntry("switch-alt", alternateLabel),
            new PluginMenuEntry("toggle-classic", quickSwitchLabel),
        ];
    }

    public void OnMenuEntry(short simId, PluginObject target, string entryId)
    {
        var lot = context.Simulation;
        if (simId != target.ObjectId || !lot.HouseholdSims.Any(s => s.ObjectId == simId))
            return;

        switch (entryId)
        {
            case "toggle-classic":
                WriteStyle(CurrentSettings.Enabled ? SmartStyle.Classic : SmartStyle.Drama);
                lastPublishedSignature = null;
                PublishPanel(lot);
                return;

            case "switch-alt":
                WriteStyle(CurrentSettings.Style == SmartStyle.Mastermind ? SmartStyle.Drama : SmartStyle.Mastermind);
                lastPublishedSignature = null;
                PublishPanel(lot);
                return;

            case "options":
                lastPublishedSignature = null;
                PublishPanel(lot);
                context.ShowPanel(PanelId, simId);
                return;
        }
    }

    public void OnPanelAction(string panelId, string action)
    {
        if (panelId != PanelId)
            return;

        var settings = CurrentSettings;
        switch (action)
        {
            case "cycle-style":
                var nextStyle = settings.Style switch
                {
                    SmartStyle.Drama => SmartStyle.Mastermind,
                    SmartStyle.Mastermind => SmartStyle.Classic,
                    _ => SmartStyle.Drama,
                };
                WriteStyle(nextStyle);
                break;

            case "toggle-bubbles":
                WriteFlag("thoughtBubbles", !settings.ThoughtBubbles);
                break;

            case "toggle-sparks":
                WriteFlag("sparks", !settings.SparksAndTurfWars);
                break;

            default:
                return;
        }

        lastPublishedSignature = null;
        try { PublishPanel(context.Simulation); }
        catch { PublishPanel(null); }
    }

    public string? OnCheat(string command, string[] args)
    {
        if (!string.Equals(command, "smart_freewill", StringComparison.OrdinalIgnoreCase))
            return null;

        var sub = args.Length > 0 ? args[0].ToLowerInvariant() : "status";
        switch (sub)
        {
            case "on":
            case "smart":
            case "drama":
            case "sitcom":
            case "1":
                WriteStyle(SmartStyle.Drama);
                break;
            case "mastermind":
            case "competent":
            case "2":
                WriteStyle(SmartStyle.Mastermind);
                break;
            case "off":
            case "classic":
            case "vanilla":
            case "0":
                WriteStyle(SmartStyle.Classic);
                break;
            case "bubbles":
                WriteFlag("thoughtBubbles", !CurrentSettings.ThoughtBubbles);
                break;
            case "status":
                break;
            default:
                throw new ArgumentException("Usage: smart_freewill [drama|mastermind|classic|bubbles|status]");
        }

        lastPublishedSignature = null;
        var settings = CurrentSettings;
        try { PublishPanel(context.Simulation); } catch { PublishPanel(null); }
        return settings.Style switch
        {
            SmartStyle.Drama => $"Sitcom Drama Free Will is active (Thought Bubbles: {(settings.ThoughtBubbles ? "On" : "Off")}, Sparks & Turf Wars: {(settings.SparksAndTurfWars ? "On" : "Off")})",
            SmartStyle.Mastermind => $"Mastermind Free Will is active (Thought Bubbles: {(settings.ThoughtBubbles ? "On" : "Off")}, Career & Teamwork: {(settings.SparksAndTurfWars ? "On" : "Off")})",
            _ => "Classic vanilla Free Will is active",
        };
    }

    private void PublishPanel(IPluginSimulation? lot)
    {
        var settings = CurrentSettings;
        var freeWillGlobal = true;
        if (lot is not null)
        {
            try { freeWillGlobal = lot.FreeWill; }
            catch { freeWillGlobal = true; }
        }

        var styleName = settings.Style switch
        {
            SmartStyle.Drama => "Sitcom Drama",
            SmartStyle.Mastermind => "Mastermind",
            _ => "Classic Free Will",
        };

        var modeText = !freeWillGlobal
            ? "Free Will is turned off in Play Options"
            : settings.Style switch
            {
                SmartStyle.Drama => "Obsessions, crushes & chaos",
                SmartStyle.Mastermind => "Smart routines, skills & teamwork",
                _ => "Original untouched autonomy",
            };

        var styleBtn = $"Mode: {styleName}";
        var bubblesBtn = $"Thought Bubbles: {(settings.ThoughtBubbles ? "On" : "Off")}";
        var sparksBtn = settings.IsMastermind
            ? $"Career & Teamwork: {(settings.SparksAndTurfWars ? "On" : "Off")}"
            : $"Crushes & Turf Wars: {(settings.SparksAndTurfWars ? "On" : "Off")}";

        var sig = $"{modeText}|{styleBtn}|{bubblesBtn}|{sparksBtn}";
        if (lastPublishedSignature == sig)
            return;
        lastPublishedSignature = sig;

        context.SetPanelValue(PanelId, "mode", modeText);
        context.SetPanelValue(PanelId, "style-btn", styleBtn);
        context.SetPanelValue(PanelId, "bubbles-btn", bubblesBtn);
        context.SetPanelValue(PanelId, "sparks-btn", sparksBtn);
    }
}
