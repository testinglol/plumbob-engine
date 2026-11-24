using SimsNative.Plugins;

namespace Local.Seasons;

public sealed partial class SeasonsPlugin
{
    // Includes all constituent subtiles because object interactions may be registered directly on child
    // parts rather than the lead tile.
    private static readonly HashSet<uint> SnowObjectGuids =
    [
        0xE9F3DA2Au,
        0xE73F9109u,
        0xE8D5D791u,
        0xE111CE38u,
        0xE66E2F18u,
        0xE83125F2u,
        0xE175421Bu,
        0xEC168A6Cu,
        0xEA36068Bu,
        0xEEDF056Au,
        0xED09E219u,
        0xE36D6C86u,
        0xE36E2106u,
        0xEECF2919u,
        0xE756E535u,
        0xEE080655u,
        0xE171ABB8u,
        0xEBB0E120u,
        0xEEFEFED0u,
        0xEFC4EC91u,
        0xEC45CF27u,
        0xE5F1FE38u,
        0xE16CE641u,
        0xE670241Fu,
        0xEE1A8C57u,
        0xE988E872u,
        0xE5FF8B98u,
        0xE36F6DB1u,
        0xE41D36A0u,
        0xE0212234u,
        0xE6742D79u,
        0xEB076365u,
    ];

    private static readonly HashSet<uint> SnowmanObjectGuids =
    [
        // Original Vacation expansion Snowman.iff GUIDs (loaded from the player's own game files).
        0x6F2311FCu, 0x4CAD2E37u, 0xAA71621Fu, 0x9AEB65FFu, 0x86503633u,
        0xD60214A0u, 0xC13D15B4u, 0x30D1375Fu, 0x201E6C73u,
        // Legacy custom snowman GUIDs for existing saves.
        0xE9F3DA2Au, 0xE73F9109u, 0xE8D5D791u, 0xE111CE38u, 0xE66E2F18u,
        0xE83125F2u, 0xE175421Bu, 0xEC168A6Cu, 0xEA36068Bu, 0xEEDF056Au
    ];

    private static readonly HashSet<uint> TsoSprinklerGuids =
    [
        0xE0484538, 0xE80F654B, 0xEC517A4E,
        0xEAAC793B, 0xE302BFB9, 0xEDBD82D5, 0xE1A98ACF, 0xEAF19698
    ];

    private const uint HalfPipeGuidStart = 0xE6400000u;
    private const uint HalfPipeGuidEnd = 0xE6400023u;

    private static bool IsHalfPipe(uint guid) => guid is >= HalfPipeGuidStart and <= HalfPipeGuidEnd;

    private static bool IsSnowObject(uint guid) => SnowObjectGuids.Contains(guid) || SnowmanObjectGuids.Contains(guid) || IsHalfPipe(guid);

    private static bool IsSnowActivity(uint guid, int interaction, bool global = false) =>
        !global && IsSnowObject(guid) &&
        (SnowmanObjectGuids.Contains(guid) ? interaction is 6 or 9 : IsHalfPipe(guid) || interaction == 0);

    public bool AllowInteraction(short simId, PluginObject target, PluginInteraction interaction)
    {
        if (interaction.Global) return true;
        // Snow Day: cancel School Bus boarding for children during heavy winter blizzards.
        var lot = context.Simulation;
        if (IsSnowDay(lot.House, Day, (lot.Hours * 60 + lot.Minutes) / 60f)
            && lot.HouseholdSims.Any(s => s.ObjectId == simId && s.Child)
            && target.Name.Contains("School Bus", StringComparison.OrdinalIgnoreCase))
        {
            return false;
        }
        if (IsSnowActivity(target.Guid, interaction.Id)) return SnowActivityAvailable(target.Guid);
        if (!TsoSprinklerGuids.Contains(target.Guid)) return true;
        var restricted = interaction.Id is 1 or 2;
        return !restricted || SprinklerWeatherAvailable();
    }

    private bool SprinklerWeatherAvailable()
    {
        var lot = context.Simulation;
        if (!Seasonal(lot.House)) return true;
        var hour = (lot.Hours * 60 + lot.Minutes) / 60f;
        var ground = Ground(Day, hour);
        return ground.Mode != 2 && ground.Wetness < 0.2f &&
            Precipitation(Day * 24 + hour) <= 0.02f &&
            Temperature(Day * 24 + hour, true) > 38;
    }

    private int? snowAttributesAt;
    private short snowAttributesHouse;

    private void UpdateSnowmanWeather()
    {
        var lot = context.Simulation;
        if (lot.Paused) return;
        var minute = lot.Hours * 60 + lot.Minutes;
        if (snowAttributesAt == minute && snowAttributesHouse == lot.House) return;
        snowAttributesAt = minute;
        snowAttributesHouse = lot.House;
        var hour = minute / 60f;
        var ground = Ground(Day, hour);
        var frozen = lot.House is >= 40 and <= 42 || Seasonal(lot.House) &&
            ground.Mode == 2 && ground.Amount >= 0.1f && Temperature(Day * 24 + hour, true) <= 34;
        var value = frozen ? (short)1 : (short)0;
        // The snowman thaw routine monitors subpart A, requiring updates to both the subpart and the lead
        // tile.
        foreach (var obj in lot.Objects.Where(obj => SnowmanObjectGuids.Contains(obj.Guid) && (obj.ObjectId == obj.LeadObjectId || obj.Guid == 0xE73F9109u)))
        {
            try
            {
                if (context.GetObjectAttribute(obj.ObjectId, 11) != value)
                    context.SetObjectAttribute(obj.ObjectId, 11, value);
            }
            catch (ArgumentOutOfRangeException)
            {
                // Original Vacation Snowman.iff does not expose custom thaw attribute 11.
            }
        }
    }

    private bool SnowActivityAvailable(uint guid)
    {
        var lot = context.Simulation;
        if (!IsSnowObject(guid) || !Seasonal(lot.House)) return true;
        var ground = Ground(Day, (lot.Hours * 60 + lot.Minutes) / 60f);
        return ground.Mode == 2 && ground.Amount >= 0.1f;
    }
}
