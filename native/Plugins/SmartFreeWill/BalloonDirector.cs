using SimsNative.Plugins;

namespace Local.SmartFreeWill;

internal sealed record BalloonBeat(
    PluginBalloonStyle Style,
    short? TargetObjectId = null,
    int? SpriteId = null,
    bool CrossedOut = false,
    int DurationTicks = 72);

internal sealed class BalloonDirector
{
    public const int SpriteHunger = 200;
    public const int SpriteBladder = 201;
    public const int SpriteHygiene = 203;
    public const int SpriteEnergy = 204;
    public const int SpriteComfort = 205;
    public const int SpriteFun = 206;
    public const int SpriteSocial = 210;
    public const int SpriteRomance = 300;
    public const int SpriteFriends = 301;
    public const int SpriteMusic = 419;
    public const int SpriteParties = 443;
    public const int SpriteHate = 500;
    public const int SpriteStress = 501;
    public const int SpriteSurprise = 502;
    public const int SpriteIdea = 503;
    public const int SpriteLove = 504;
    public const int SpriteHurt = 506;
    public const int SpriteSmell = 507;
    public const int SpriteCheerUp = 604;
    public const int SpriteBrag = 607;
    public const int SpriteSlap = 608;
    public const int SpriteTease = 610;
    public const int SpriteCrush = 633;

    private sealed record QueuedFollowUp(long FireAtTick, BalloonBeat Beat);

    private readonly Dictionary<short, QueuedFollowUp> followUps = [];
    private readonly Dictionary<short, long> lastBalloonTickBySim = [];
    private readonly Dictionary<short, int> lastHubrisMinuteBySim = [];

    public void Reset()
    {
        followUps.Clear();
        lastBalloonTickBySim.Clear();
        lastHubrisMinuteBySim.Clear();
    }

    public void AdvanceTicks(IPluginSimulation lot, bool enabled, long tick)
    {
        if (!enabled || lot.Paused || followUps.Count == 0)
            return;

        foreach (var (simId, pending) in followUps.ToArray())
        {
            if (tick < pending.FireAtTick)
                continue;
            followUps.Remove(simId);
            EmitNow(lot, simId, pending.Beat, tick, ignoreCooldown: true);
        }
    }

    public void EmitSingle(IPluginSimulation lot, bool enabled, short simId, BalloonBeat beat, long tick, int minGapTicks = 70)
    {
        if (!enabled)
            return;
        if (!CanEmit(simId, tick, minGapTicks))
            return;
        followUps.Remove(simId);
        EmitNow(lot, simId, beat, tick, ignoreCooldown: true);
    }

    public void EmitSequence(IPluginSimulation lot, bool enabled, short simId, BalloonBeat first, BalloonBeat second, long tick, int minGapTicks = 70)
    {
        if (!enabled)
            return;
        if (!CanEmit(simId, tick, minGapTicks))
            return;
        if (EmitNow(lot, simId, first, tick, ignoreCooldown: true))
            followUps[simId] = new QueuedFollowUp(tick + Math.Max(30, first.DurationTicks + 4), second);
    }

    public void TryEmitHoldItHubris(
        IPluginSimulation lot,
        bool enabled,
        short simId,
        short? nearestToiletId,
        int nowMinutes,
        long tick)
    {
        if (!enabled)
            return;
        if (lastHubrisMinuteBySim.TryGetValue(simId, out var prevMin) && nowMinutes - prevMin < 14)
            return;
        lastHubrisMinuteBySim[simId] = nowMinutes;
        var beat = nearestToiletId.HasValue
            ? new BalloonBeat(PluginBalloonStyle.Thought, TargetObjectId: nearestToiletId.Value, CrossedOut: true, DurationTicks: 68)
            : new BalloonBeat(PluginBalloonStyle.Thought, SpriteId: SpriteBladder, CrossedOut: true, DurationTicks: 68);
        EmitSingle(lot, enabled, simId, beat, tick, minGapTicks: 45);
    }

    public static int CareerSpriteForJobType(short jobType) => jobType switch
    {
        1 => 457,
        2 => 458,
        3 => 459,
        4 => 460,
        5 => 461,
        6 => 462,
        7 => 463,
        8 => 465,
        9 => 466,
        10 => 464,
        11 => 467,
        12 => 468,
        13 => 469,
        14 => 470,
        15 => 471,
        _ => SpriteIdea,
    };

    private bool CanEmit(short simId, long tick, int minGapTicks) =>
        !lastBalloonTickBySim.TryGetValue(simId, out var prev) || tick - prev >= minGapTicks;

    private bool EmitNow(IPluginSimulation lot, short simId, BalloonBeat beat, long tick, bool ignoreCooldown)
    {
        if (!ignoreCooldown && !CanEmit(simId, tick, 60))
            return false;
        try
        {
            var shown = lot.TryShowSimBalloon(
                simId,
                beat.Style,
                beat.TargetObjectId,
                beat.SpriteId,
                beat.CrossedOut,
                beat.DurationTicks);
            if (shown)
                lastBalloonTickBySim[simId] = tick;
            return shown;
        }
        catch
        {
            return false;
        }
    }
}
