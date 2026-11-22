using System.Text.Json;
using SimsEngine.Simulation;
using SimsEngine.Tests.E2E;
using SimsSDL.Core;
using SimsSDL.UI;
using Xunit;

namespace SimsEngine.Tests;

[Collection("Neighborhoods")]
public sealed class HouseholdDeathSelectionTests
{
    private static GameplayPanelState ParseAndValidatePanelState(JsonElement state)
    {
        var panelState = JsonSerializer.Deserialize<GameplayPanelState>(state.GetRawText(), PackContentPaths.JsonReadOptions)!;
        panelState.Validate();
        return panelState;
    }

    private static void DismissBlockingDialogs(ServerSession session, JsonElement state)
    {
        if (!state.TryGetProperty("dialogs", out var dialogs) || dialogs.ValueKind != JsonValueKind.Array)
            return;
        foreach (var dlg in dialogs.EnumerateArray())
        {
            if (dlg.TryGetProperty("blocking", out var blocking) && blocking.GetBoolean() &&
                dlg.TryGetProperty("token", out var token))
            {
                var resp = session.HandleJson("dialogResponse", new { token = token.GetString(), code = (byte)0 });
                Assert.True(resp.GetProperty("ok").GetBoolean(), resp.ToString());
            }
        }
    }

    [Fact]
    public void SelectedHouseholdSimDies_SwitchesSelectionToSurvivingMemberAndValidatesGameplayPanel()
    {
        if (!E2EHarness.TryLocateGameDir(out var gameDir) || !E2EHarness.HasHouses(gameDir, 5))
            return;

        using var profile = E2EHarness.CreateIsolatedProfile(gameDir, copyCharacters: true, neighborhood: 1, copyDownloads: false, 5);
        using var session = E2EHarness.StartServer(profile, house: 5);

        var initialPanel = ParseAndValidatePanelState(session.State());
        Assert.Equal(3, initialPanel.Household.Count);
        var originalSelectedId = initialPanel.SelectedSim;
        Assert.NotEqual(0, originalSelectedId);

        Assert.True(session.HandleJson("freeWill", new { enabled = false }).GetProperty("ok").GetBoolean());
        Assert.True(session.HandleJson("setMotive", new { objectID = originalSelectedId, motive = "Hunger", value = -100f }).GetProperty("ok").GetBoolean());

        GameplayPanelState? afterDeath = null;
        for (var i = 0; i < 60; i++)
        {
            session.Step(100);
            var rawState = session.State();
            DismissBlockingDialogs(session, rawState);
            var panel = ParseAndValidatePanelState(rawState);
            if (panel.Household.Count == 2)
            {
                afterDeath = panel;
                break;
            }
        }

        Assert.NotNull(afterDeath);
        Assert.NotEqual(0, afterDeath!.SelectedSim);
        Assert.NotEqual(originalSelectedId, afterDeath.SelectedSim);
        Assert.NotNull(afterDeath.Selected);
        Assert.DoesNotContain(afterDeath.Household, s => s.Id == originalSelectedId);
        Assert.Equal((short)afterDeath.SelectedSim, session.World![SimulationGlobal.SelectedPersonID]);
    }

    [Fact]
    public void AllHouseholdSimsDie_ClearsSelectionEvenWhenNpcsPresent_AndRejectsNpcSelectSim()
    {
        if (!E2EHarness.TryLocateGameDir(out var gameDir) || !E2EHarness.HasHouses(gameDir, 5))
            return;

        using var profile = E2EHarness.CreateIsolatedProfile(gameDir, copyCharacters: true, neighborhood: 1, copyDownloads: false, 5);
        using var session = E2EHarness.StartServer(profile, house: 5);

        var initialPanel = ParseAndValidatePanelState(session.State());
        var householdIds = initialPanel.Household.Select(s => s.Id).ToArray();
        Assert.Equal(3, householdIds.Length);

        Assert.True(session.HandleJson("freeWill", new { enabled = false }).GetProperty("ok").GetBoolean());
        foreach (var id in householdIds)
        {
            Assert.True(session.HandleJson("setMotive", new { objectID = id, motive = "Hunger", value = -100f }).GetProperty("ok").GetBoolean());
        }

        GameplayPanelState? allDeadPanel = null;
        for (var i = 0; i < 80; i++)
        {
            session.Step(100);
            var rawState = session.State();
            DismissBlockingDialogs(session, rawState);
            var panel = ParseAndValidatePanelState(rawState);
            if (panel.Household.Count == 0)
            {
                allDeadPanel = panel;
                break;
            }
        }

        Assert.NotNull(allDeadPanel);
        Assert.Equal(0, allDeadPanel!.SelectedSim);
        Assert.Null(allDeadPanel.Selected);
        Assert.Empty(allDeadPanel.Household);
        Assert.Equal((short)0, session.World![SimulationGlobal.SelectedPersonID]);

        // Advance a bit further so Grim Reaper finishes leaving while any NPC (such as Tragic Clown) remains on the lot.
        for (var i = 0; i < 5; i++)
        {
            session.Step(100);
            var rawState = session.State();
            DismissBlockingDialogs(session, rawState);
            allDeadPanel = ParseAndValidatePanelState(rawState);
        }

        Assert.Equal(0, allDeadPanel.SelectedSim);
        Assert.Null(allDeadPanel.Selected);
        Assert.Empty(allDeadPanel.Household);
        Assert.Equal((short)0, session.World[SimulationGlobal.SelectedPersonID]);
        Assert.NotEmpty(allDeadPanel.Sims);

        foreach (var npc in allDeadPanel.Sims)
        {
            Assert.False(npc.Household);
            var selectNpcResp = session.HandleJson("selectSim", new { objectID = npc.Id });
            Assert.False(selectNpcResp.GetProperty("ok").GetBoolean());
        }
    }

    [Fact]
    public void GameplayPanelWithNoHouseholdSims_ValidatesAndDisablesNeedsSubpanel()
    {
        var npcOnlyState = new GameplayPanelState(
            selectedSim: 0,
            hours: 11,
            minutes: 4,
            sims:
            [
                new GameplayPanelState.Sim(
                    id: 21,
                    name: "Sunny",
                    household: false,
                    mood: -22,
                    motives: new Dictionary<string, int> { ["Hunger"] = -20 },
                    actions: [])
            ],
            house: new GameplayPanelState.HousePanel
            {
                SquareFeet = 400,
                Bedrooms = 1,
                Bathrooms = 1,
                LotSize = 0,
                SizeScore = 10,
                FurnishingsScore = 10,
                YardScore = 10,
                UpkeepScore = 10,
                LayoutScore = 10,
            });

        npcOnlyState.Validate();
        Assert.Empty(npcOnlyState.Household);
        Assert.Null(npcOnlyState.Selected);
        Assert.False(OriginalGameplayOverlay.Supports(OriginalGameplayOverlay.Subpanel.Needs, npcOnlyState));
        Assert.True(OriginalGameplayOverlay.Supports(OriginalGameplayOverlay.Subpanel.House, npcOnlyState));
    }
}
