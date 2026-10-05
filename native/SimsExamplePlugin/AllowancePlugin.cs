using System.Buffers.Binary;
using SimsNative.Plugins;

namespace Local.ExampleAllowance;

/// <summary>
/// Example gameplay system: a daily allowance. At 08:00 each game day it pays the household §50 per child,
/// shows the running total in its panel, and lets the player pause or resume payments from the panel.
/// State version 2 added the paused flag; version 1 saves stored only the running total.
/// It also shows what plugin API version 2 can do: "Chore" sends an adult to a chore the lot offers, through the same
/// pie menu the player uses, and "Coffee" tops up that adult's energy.
/// </summary>
public sealed class AllowancePlugin : ISimsPlugin
{
    private const int AllowancePerChild = 50;
    private const int Energy = 5;
    private static readonly string[] Chores = ["Water", "Bring In", "Clean", "Repair", "Feed Fish", "Empty"];
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
        // Funds change with every purchase and bill; only changed panel values reach the client.
        context.SetPanelValue("allowance", "funds", simulation.HouseholdFunds.ToString());
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
        var simulation = context.Simulation;
        var adult = simulation.HouseholdSims.FirstOrDefault(sim => !sim.Child);
        if (action == "chore") context.SetPanelValue("allowance", "chore", adult == null ? "Nobody to do chores" : Chore(simulation, adult));
        if (action == "coffee" && adult != null)
            context.SetPanelValue("allowance", "chore", $"{adult.Name} has energy {simulation.ChangeMotive(adult.ObjectId, Energy, 20)}");
        Publish();
    }

    private static string Chore(IPluginSimulation simulation, PluginSim adult)
    {
        foreach (var item in simulation.Objects.Where(item => item.ObjectId == item.LeadObjectId && item.ObjectId != adult.ObjectId))
            foreach (var interaction in simulation.GetInteractions(adult.ObjectId, item.ObjectId))
                if (Chores.Contains(interaction.Name) &&
                    simulation.TryQueueInteraction(adult.ObjectId, item.ObjectId, interaction.Id, interaction.Param0, interaction.Global))
                    return $"{adult.Name}: {interaction.Name} {item.Name}";
        return "No chores on this lot";
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
        context.SetPanelValue("allowance", "objects", context.Simulation.Objects.Count + " objects on this lot");
    }
}
