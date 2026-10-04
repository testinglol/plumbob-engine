using System.Buffers.Binary;
using SimsNative.Plugins;

namespace Local.ExampleAllowance;

/// <summary>
/// Example gameplay system: a daily allowance. At 08:00 each game day it pays the household §50 per child,
/// shows the running total in its panel, and lets the player pause or resume payments from the panel.
/// State version 2 added the paused flag; version 1 saves stored only the running total.
/// </summary>
public sealed class AllowancePlugin : ISimsPlugin
{
    private const int AllowancePerChild = 50;
    private IPluginContext context = null!;
    private int totalPaid;
    private bool paused;
    private bool paidThisMorning;

    public void Initialize(IPluginContext context)
    {
        this.context = context;
        Publish();
    }

    public void OnTick(long update)
    {
        var simulation = context.Simulation;
        if (simulation.Hours != 8) { paidThisMorning = false; return; }
        if (simulation.Paused || paused || paidThisMorning) return;
        paidThisMorning = true;
        var children = simulation.HouseholdSims.Count(sim => sim.Child);
        if (children > 0 && simulation.TryPay(children * AllowancePerChild))
        {
            totalPaid += children * AllowancePerChild;
            context.Values["lastPaidHouse"] = simulation.House.ToString();
        }
        Publish();
    }

    public void OnPanelAction(string panelId, string action)
    {
        if (panelId != "allowance") return;
        paused = action switch { "pause" => true, "resume" => false, _ => paused };
        Publish();
    }

    public byte[]? SaveState()
    {
        var data = new byte[5];
        BinaryPrimitives.WriteInt32LittleEndian(data, totalPaid);
        data[4] = paused ? (byte)1 : (byte)0;
        return data;
    }

    public void LoadState(int savedStateVersion, byte[] data)
    {
        totalPaid = data.Length >= 4 ? BinaryPrimitives.ReadInt32LittleEndian(data) : 0;
        // Version 1 had no paused flag; payments resume by default after migration.
        paused = savedStateVersion >= 2 && data.Length >= 5 && data[4] != 0;
        Publish();
    }

    private void Publish()
    {
        context.SetPanelValue("allowance", "total", "§" + totalPaid);
        context.SetPanelValue("allowance", "status", paused ? "Payments paused" : "Paid each morning at 8:00");
        context.SetPanelValue("allowance", "funds", context.Simulation.HouseholdFunds.ToString());
    }
}
