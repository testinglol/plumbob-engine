namespace SimsNative.Plugins;

/// <summary>Versions of the gameplay plugin contract that the native simulation host accepts.</summary>
public static class PluginApi
{
    /// <summary>The contract version implemented by this assembly.</summary>
    public const int Version = 2;

    /// <summary>
    /// Contract versions the host can load. A plugin declares exactly one in its pack manifest. Version 2 added lot
    /// objects, pie menus, queued interactions and motive changes; a version 1 plugin sees those members throw.
    /// </summary>
    public static readonly IReadOnlyList<int> SupportedVersions = [1, 2];
}

/// <summary>
/// Entry point of a code-bearing gameplay pack. The host constructs the type named by the manifest's
/// <c>plugin.entryType</c> with a public parameterless constructor, only after the player trusted that exact assembly.
/// All calls arrive on the simulation thread between VM updates.
/// </summary>
public interface ISimsPlugin
{
    /// <summary>Called once after the plugin is constructed and before the first tick.</summary>
    void Initialize(IPluginContext context);

    /// <summary>Called after every simulation update that advanced game time.</summary>
    void OnTick(long update) { }

    /// <summary>Called when the player activates a button declared in one of this pack's panel descriptions.</summary>
    void OnPanelAction(string panelId, string action) { }

    /// <summary>
    /// API version 2: rescores one candidate of a Sim's autonomous choice. The host calls it only on plugins that
    /// implement it, after the original scoring and before the Sim picks among its four best candidates. Return the
    /// score to use; 0 rules the candidate out. Keep it fast and deterministic: it runs for every candidate.
    /// </summary>
    float ScoreAutonomy(PluginAutonomyChoice choice, float score) => score;

    /// <summary>
    /// API version 2: extra pie menu entries for a household Sim on an object (another Sim included). Called each time
    /// the player opens a menu; return at most 8 entries. A "/" in a name opens a submenu, as in the original menus.
    /// </summary>
    IEnumerable<PluginMenuEntry> GetMenuEntries(short simId, PluginObject target) => [];

    /// <summary>
    /// API version 2: the player chose one of this plugin's entries. The host checks first that the plugin still offers
    /// it for that Sim and object. Nothing is queued for the Sim; queue interactions or change needs from here.
    /// </summary>
    void OnMenuEntry(short simId, PluginObject target, string entryId) { }

    /// <summary>Returns opaque plugin state to store under the pack's namespace in a native save, or null for none.</summary>
    byte[]? SaveState() => null;

    /// <summary>
    /// Restores state written by <see cref="SaveState"/>. <paramref name="savedStateVersion"/> is the manifest
    /// <c>plugin.stateVersion</c> at save time and is never newer than the running plugin's version; migrate older data here.
    /// </summary>
    void LoadState(int savedStateVersion, byte[] data) { }
}

/// <summary>Services the host gives one plugin. Every call is validated by the host; plugins cannot reach the VM directly.</summary>
public interface IPluginContext
{
    /// <summary>The contract version the host is serving for this plugin.</summary>
    int ApiVersion { get; }

    /// <summary>The owning pack ID; also the namespace of this plugin's save data.</summary>
    string PackId { get; }

    /// <summary>The pack version from its manifest.</summary>
    string PackVersion { get; }

    /// <summary>The manifest's <c>plugin.stateVersion</c>.</summary>
    int StateVersion { get; }

    /// <summary>Read-mostly access to the running lot.</summary>
    IPluginSimulation Simulation { get; }

    /// <summary>
    /// Small string values persisted automatically under this pack's namespace in native saves.
    /// Limited to 256 keys of at most 64 characters and values of at most 4096 characters.
    /// </summary>
    IDictionary<string, string> Values { get; }

    /// <summary>Sets a value bound by an element of one of this pack's declared panels.</summary>
    void SetPanelValue(string panelId, string binding, string value);

    /// <summary>
    /// API version 2: opens one of this pack's declared panels for the player. Only allowed from
    /// <see cref="ISimsPlugin.OnMenuEntry"/>, so a panel opens only when the player asked for it; set its values first.
    /// </summary>
    void ShowPanel(string panelId) => throw new NotSupportedException("ShowPanel needs plugin API version 2");

    /// <summary>Writes a diagnostic line to the simulation log.</summary>
    void Log(string message);
}

/// <summary>A household Sim visible to plugins.</summary>
public sealed record PluginSim(short ObjectId, short NeighborId, string Name, bool Child);

/// <summary>
/// An object on the lot (API version 2). <paramref name="X"/> and <paramref name="Y"/> are tile coordinates; a
/// multi-tile object's parts share <paramref name="LeadObjectId"/>.
/// </summary>
public sealed record PluginObject(short ObjectId, uint Guid, string Name, int X, int Y, int Level, short LeadObjectId);

/// <summary>A pie menu entry a Sim is offered on an object (API version 2), as the player would see it.</summary>
public sealed record PluginInteraction(int Id, string Name, short Param0, bool Global);

/// <summary>
/// A pie menu entry contributed by a plugin (API version 2). <paramref name="Id"/> is 1 to 64 letters, digits, '.', '-'
/// or '_' and is unique among the plugin's entries for one menu; <paramref name="Name"/> is 1 to 64 printable characters.
/// </summary>
public sealed record PluginMenuEntry(string Id, string Name);

/// <summary>A candidate of an autonomous choice (API version 2): which Sim, on which object, which pie menu entry.</summary>
public sealed record PluginAutonomyChoice(short SimId, bool Household, short ObjectId, uint ObjectGuid, int InteractionId, string Interaction);

/// <summary>Constrained simulation access. Writes go through the same validation the original game applies.</summary>
public interface IPluginSimulation
{
    /// <summary>The house number of the loaded lot.</summary>
    short House { get; }

    /// <summary>Game clock hour, 0 through 23.</summary>
    int Hours { get; }

    /// <summary>Game clock minute, 0 through 59.</summary>
    int Minutes { get; }

    /// <summary>True while the simulation is paused or a blocking dialog is open.</summary>
    bool Paused { get; }

    /// <summary>The active household's funds, or 0 when no household is active.</summary>
    int HouseholdFunds { get; }

    /// <summary>The active household's Sims on this lot.</summary>
    IReadOnlyList<PluginSim> HouseholdSims { get; }

    /// <summary>Reads one of a Sim's motives by its original motive index (0–15).</summary>
    short GetMotive(short objectId, int motive);

    /// <summary>Removes funds from the active household. Fails without a change when the amount is not positive or exceeds the funds.</summary>
    bool TryCharge(int amount);

    /// <summary>Adds funds to the active household. Amounts above 100,000 per call are rejected.</summary>
    bool TryPay(int amount);

    /// <summary>API version 2: every object on the lot, Sims included.</summary>
    IReadOnlyList<PluginObject> Objects => throw new NotSupportedException("Lot objects need plugin API version 2");

    /// <summary>API version 2: the pie menu a household Sim is offered on an object right now.</summary>
    IReadOnlyList<PluginInteraction> GetInteractions(short simId, short objectId) =>
        throw new NotSupportedException("Pie menus need plugin API version 2");

    /// <summary>
    /// API version 2: queues an interaction for a household Sim exactly as if the player picked it from the pie menu.
    /// Fails without a change while a blocking dialog is open or when the Sim is not offered that entry.
    /// </summary>
    bool TryQueueInteraction(short simId, short objectId, int interactionId, short param0 = 0, bool global = false) =>
        throw new NotSupportedException("Queuing interactions needs plugin API version 2");

    /// <summary>API version 2: the names of the actions in a household Sim's queue, the running one first.</summary>
    IReadOnlyList<string> GetQueuedActions(short simId) => throw new NotSupportedException("Action queues need plugin API version 2");

    /// <summary>
    /// API version 2: changes one of a household Sim's needs, by the original motive index of <see cref="GetMotive"/>
    /// (energy 5, comfort 6, hunger 7, hygiene 8, bladder 9, social 14, fun 15), by up to 100 either way. The result is clamped to -100 through 100. Returns the new value.
    /// </summary>
    short ChangeMotive(short simId, int motive, int delta) => throw new NotSupportedException("Motive changes need plugin API version 2");
}
