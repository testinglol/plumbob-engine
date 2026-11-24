using SimsNative.Plugins;

namespace Local.Seasons;

// Self-Sim Seasons UI panels and real Frost Fortress snowball-fight coordination (no dialog-only stub interactions).
public sealed partial class SeasonsPlugin
{
    private const float Rest = 3;
    private const string SnowballId = "snowball";
    private sealed record PendingSnowballFight(short FirstSim, short SecondSim, short FortTile, string StartLabel, float StartedAt);
    private readonly List<PendingSnowballFight> pendingSnowballFights = [];
    private short pendingSnowballHouse = -1;
    private readonly Dictionary<(short Sim, string Activity), float> lastDone = [];

    private float Now(IPluginSimulation lot) => Day * 24 + lot.Hours + lot.Minutes / 60f;

    private bool Outdoors(IPluginSimulation lot, short simId, PluginObject target) =>
        Seasonal(lot.House) && lot.House is not (>= 40 and <= 42) && target.Outside &&
        lot.HouseholdSims.Any(sim => sim.ObjectId == simId) && lot.Objects.Any(item => item.ObjectId == simId && item.Outside);

    private static short? Partner(IPluginSimulation lot, short simId, PluginObject target) =>
        target.ObjectId != simId && lot.HouseholdSims.Any(sim => sim.ObjectId == target.ObjectId) ? target.ObjectId : null;

    private bool Resting(short simId, string id, float now) => lastDone.TryGetValue((simId, id), out var at) && now - at < Rest && now >= at;

    private static IEnumerable<PluginObject> FortParts(IPluginSimulation lot) =>
        lot.Objects.Where(item => SnowObjectGuids.Contains(item.Guid) && !SnowmanObjectGuids.Contains(item.Guid));

    private static bool HasFortFight(IPluginSimulation lot, short simId) => FortParts(lot)
        .Any(fort => lot.GetInteractions(simId, fort.ObjectId).Any(interaction => interaction.Id == 0));

    private bool CanQueueSnowballFight(IPluginSimulation lot, short simId, PluginObject target, float now)
    {
        if (!Outdoors(lot, simId, target) || Partner(lot, simId, target) is not { } partner) return false;
        var day = (int)MathF.Floor(now / 24);
        var hour = now - day * 24;
        var (mode, amount, _) = Ground(day, hour);
        if (mode != 2 || (amount < 0.2f && Precipitation(now) <= 0.05f)) return false;
        if (Resting(simId, SnowballId, now) || Resting(partner, SnowballId, now)) return false;
        if (pendingSnowballFights.Any(fight =>
                fight.FirstSim == simId && fight.SecondSim == partner || fight.FirstSim == partner && fight.SecondSim == simId))
            return false;
        try { return HasFortFight(lot, simId); }
        catch (NotSupportedException) { return false; }
    }

    private bool QueueSnowballFight(IPluginSimulation lot, short simId, short partnerId, float now)
    {
        // Fort interactions manage routing, animation, and motive updates; the plugin initiates the lead
        // participant and joins the partner when the pie menu transitions from Start to Join.
        foreach (var fort in FortParts(lot))
        {
            var start = lot.GetInteractions(simId, fort.ObjectId).FirstOrDefault(interaction => interaction.Id == 0);
            if (start is null || !lot.TryQueueInteraction(simId, fort.ObjectId, start.Id, start.Param0, start.Global)) continue;
            pendingSnowballHouse = lot.House;
            pendingSnowballFights.Add(new PendingSnowballFight(simId, partnerId, fort.ObjectId, start.Name, now));
            return true;
        }
        return false;
    }

    private void AdvanceSnowballFights(long update)
    {
        if (pendingSnowballFights.Count == 0) return;
        var lot = context.Simulation;
        if (lot.Paused || update % 6 != 0) return;
        if (pendingSnowballHouse != lot.House)
        {
            pendingSnowballFights.Clear();
            pendingSnowballHouse = lot.House;
        }
        var now = Now(lot);
        foreach (var fight in pendingSnowballFights.ToArray())
        {
            if (!new[] { fight.FirstSim, fight.SecondSim }.All(id => lot.HouseholdSims.Any(sim => sim.ObjectId == id)) ||
                !lot.Objects.Any(item => item.ObjectId == fight.FortTile))
            { pendingSnowballFights.Remove(fight); continue; }
            if (now - fight.StartedAt > 1) { pendingSnowballFights.Remove(fight); continue; }
            var join = lot.GetInteractions(fight.SecondSim, fight.FortTile)
                .FirstOrDefault(interaction => interaction.Id == 0 && !string.Equals(interaction.Name, fight.StartLabel, StringComparison.Ordinal));
            if (join is not null && lot.TryQueueInteraction(fight.SecondSim, fight.FortTile, join.Id, join.Param0, join.Global))
            {
                lastDone[(fight.FirstSim, SnowballId)] = now;
                lastDone[(fight.SecondSim, SnowballId)] = now;
                pendingSnowballFights.Remove(fight);
            }
        }
    }

    private readonly HashSet<short> manualWinterCoat = [];

    public IEnumerable<PluginMenuEntry> GetMenuEntries(short simId, PluginObject target)
    {
        var lot = context.Simulation;
        if (Seasonal(lot.House) && simId == target.ObjectId && lot.HouseholdSims.Any(sim => sim.ObjectId == simId))
        {
            var coatLabel = manualWinterCoat.Contains(simId) ? "Seasons/Auto Outerwear" : "Seasons/Wear Winter Coat";
            return [new("forecast", "Seasons/Forecast"), new("settings", "Seasons/Season Length"), new("toggle-coat", coatLabel)];
        }
        if (CanQueueSnowballFight(lot, simId, target, Now(lot)))
            return [new(SnowballId, "Snowball Fight")];
        return [];
    }

    public void OnMenuEntry(short simId, PluginObject target, string entryId)
    {
        var lot = context.Simulation;
        if (entryId == "toggle-coat" && Seasonal(lot.House) && simId == target.ObjectId)
        {
            if (manualWinterCoat.Add(simId))
                context.SetSimSuitOverride(simId, 17);
            else
            {
                manualWinterCoat.Remove(simId);
                context.SetSimSuitOverride(simId, null);
            }
            return;
        }
        if (entryId is "forecast" or "settings" && GetMenuEntries(simId, target).Any(entry => entry.Id == entryId))
        {
            PublishForecast(Day, lot.Hours + lot.Minutes / 60f, true, Ground(Day, lot.Hours + lot.Minutes / 60f).Mode == 2);
            PublishSeasonLength();
            context.ShowPanel(entryId == "forecast" ? "forecast" : "season-settings", simId);
            return;
        }
        var now = Now(lot);
        if (entryId == SnowballId && CanQueueSnowballFight(lot, simId, target, now))
        {
            QueueSnowballFight(lot, simId, target.ObjectId, now);
        }
    }
}
