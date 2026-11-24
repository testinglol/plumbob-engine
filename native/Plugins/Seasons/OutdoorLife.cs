using SimsNative.Plugins;

namespace Local.Seasons;

// Ground pie-menu Snowman placement (queuing real Sims 1 Snowman Kit Build).
public sealed partial class SeasonsPlugin
{
    private enum QueueOutcome { Queued, NotAvailable, Unsupported }

    private QueueOutcome TryQueueOwnedObjectInteraction(IPluginSimulation lot, short simId, short objectId, params string[] nameParts)
    {
        IReadOnlyList<PluginInteraction> interactions;
        try
        {
            interactions = lot.GetInteractions(simId, objectId);
        }
        catch (NotSupportedException)
        {
            return QueueOutcome.Unsupported;
        }
        PluginInteraction? match = nameParts.Length == 0
            ? interactions.FirstOrDefault(item => item.Id == 0) ?? interactions.FirstOrDefault()
            : nameParts
                .Select(part => interactions.FirstOrDefault(item => item.Name.Contains(part, StringComparison.OrdinalIgnoreCase)))
                .FirstOrDefault(item => item != null);
        if (match == null) return QueueOutcome.NotAvailable;
        return lot.TryQueueInteraction(simId, objectId, match.Id, match.Param0, match.Global)
            ? QueueOutcome.Queued
            : QueueOutcome.NotAvailable;
    }

    public IEnumerable<PluginMenuEntry> GetGroundMenuEntries(short simId, PluginGroundPoint point)
    {
        var lot = context.Simulation;
        if (!Seasonal(lot.House) || lot.House is >= 40 and <= 42) yield break;
        if (point.Level != 1 || !point.Outside) yield break;

        var hour = (lot.Hours * 60 + lot.Minutes) / 60f;
        var ground = Ground(Day, hour);
        if (ground.Mode == 2 && ground.Amount >= 0.2f)
        {
            yield return new("ground-snowman", "Build Snowman Here");
        }
    }

    public void OnGroundMenuEntry(short simId, PluginGroundPoint point, string entryId)
    {
        var lot = context.Simulation;
        if (!Seasonal(lot.House) || lot.House is >= 40 and <= 42) return;
        if (entryId == "ground-snowman")
        {
            // Uses the player's own Vacation expansion Snowman.iff directly (no bundled IFF assets).
            var placed = context.TryPlaceOwnedObject(0x6F2311FCu, point.TileX, point.TileY, point.Level, clearForSimId: simId);
            if (placed == null) return;

            var outcome = TryQueueOwnedObjectInteraction(lot, simId, placed.Value, "Build");
            if (outcome != QueueOutcome.Queued)
            {
                try { context.TryRemoveOwnedObject(placed.Value); }
                catch (NotSupportedException) { }
            }
            return;
        }
    }
}
