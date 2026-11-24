using System.Numerics;

namespace SimsNative.Plugins;

/// <summary>Versions of the gameplay plugin contract that the native simulation host accepts.</summary>
public static class PluginApi
{
    /// <summary>The contract version implemented by this assembly.</summary>
    public const int Version = 6;

    /// <summary>
    /// Contract versions the host can load. A plugin declares exactly one in its pack manifest. Version 2 added lot
    /// objects, pie menus, queued interactions and motive changes; version 4 adds reciprocal social roles, recipient
    /// response and per-role lifecycle status; version 5 adds Buy Mode catalog browser and filtering hooks; version 6
    /// adds rich Sim/object profiles, relationship queries, safe autonomous queuing/cancellation, and full-lot autonomy directors.
    /// Older plugins keep the version-specific throwing defaults.
    /// </summary>
    public static readonly IReadOnlyList<int> SupportedVersions = [1, 2, 3, 4, 5, 6];
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

    /// <summary>Called whenever a lot world is attached and ready, before its first frame is rendered.</summary>
    void OnWorldLoaded() { }

    /// <summary>Called after every simulation update that advanced game time.</summary>
    void OnTick(long update) { }

    /// <summary>Called when the player activates a button declared in one of this pack's panel descriptions.</summary>
    void OnPanelAction(string panelId, string action) { }

    /// <summary>
    /// Handles a console cheat command. Return a non-null message if handled (empty string is valid for silent success),
    /// or null if this plugin does not handle the command. Throw <see cref="ArgumentException"/> for invalid usage.
    /// </summary>
    string? OnCheat(string command, string[] args) => null;

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

    /// <summary>
    /// API version 3: restricts an interaction that passed the original object's tests.
    /// Called for player menus and again before queuing, including queues requested
    /// through the plugin SDK. Return false to withhold it. This cannot create an
    /// interaction or override the original tests; already queued actions are unchanged.
    /// </summary>
    bool AllowInteraction(short simId, PluginObject target, PluginInteraction interaction) => true;

    /// <summary>
    /// API version 4: extra pie menu entries when clicking terrain/ground while a household Sim is selected.
    /// Return at most 8 entries. A "/" in a name opens a submenu.
    /// </summary>
    IEnumerable<PluginMenuEntry> GetGroundMenuEntries(short simId, PluginGroundPoint point) => [];

    /// <summary>
    /// API version 4: the player chose one of this plugin's ground pie menu entries.
    /// </summary>
    void OnGroundMenuEntry(short simId, PluginGroundPoint point, string entryId) { }

    /// <summary>
    /// Intercepts a SimAntics global subroutine call (256..4095). Return true or false to override the global BHAV result,
    /// or null to allow normal global subroutine execution.
    /// </summary>
    bool? OnSimAnticsGlobalCall(ushort subroutineId, PluginObject caller, short stackObjectId) => null;

    /// <summary>Called when this pack's client plugin sends a command to the simulation thread.</summary>
    void OnClientCommand(string command, string? payload) { }

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
    /// <summary>Reads a saved attribute (0..255) on a lot object.</summary>
    short GetObjectAttribute(short objectId, int index) => throw new NotSupportedException("Object attributes need API3");
    /// <summary>Writes a saved attribute (0..255) on a lot object.</summary>
    void SetObjectAttribute(short objectId, int index, short value) => throw new NotSupportedException("Object attributes need API3");
    /// <summary>Selects an OBJD graphic offset on a lot object.</summary>
    void SetObjectGraphic(short objectId, short graphic) => throw new NotSupportedException("Object graphics need API3");

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

    /// <summary>
    /// API version 2: like <see cref="ShowPanel(string)"/>, but the clients draw the panel beside a Sim or object on the lot
    /// (the menu's Sim or target, or any object in <see cref="IPluginSimulation.Objects"/>), follow it as the view moves, and
    /// close the panel when the object leaves the lot. The panel keeps its size; its frame's position is ignored.
    /// </summary>
    void ShowPanel(string panelId, short anchorObjectId) => throw new NotSupportedException("ShowPanel needs plugin API version 2");

    /// <summary>API3: neighborhood-scoped key/value storage persisted with the save.</summary>
    IDictionary<string, string> NeighborhoodValues => throw new NotSupportedException("Neighborhood state needs API 3");
    /// <summary>API3: version of neighborhood-scoped plugin state stored in the active save.</summary>
    int NeighborhoodStateVersion => throw new NotSupportedException("Neighborhood state needs API 3");
    /// <summary>API3: reads a legacy sidecar file from the neighborhood directory if present.</summary>
    byte[]? ReadLegacyNeighborhoodData(string filename) => throw new NotSupportedException("Legacy import needs API 3");
    /// <summary>API3: reads a read-only data file bundled inside the pack.</summary>
    byte[] ReadPluginData(string filename) => throw new NotSupportedException("Plugin data needs API 3");
    /// <summary>API3: reads a pack-owned RGBA image resource.</summary>
    PluginImage ReadImageResource(string resource) => throw new NotSupportedException("Image resources need API 3");
    /// <summary>API3: plays a pack-owned WAV resource at an object, optionally looping it under a pack-local cue key.</summary>
    void PlaySoundResource(string resource, short ownerObjectId, string cue, bool loop = false) => throw new NotSupportedException("Pack sound resources need API 3");
    /// <summary>API3: stops a loop started with the same cue on the same object.</summary>
    void StopSoundResource(short ownerObjectId, string cue) => throw new NotSupportedException("Pack sound resources need API 3");

    /// <summary>API4: attempts to place a pack-owned object near the specified tile, returning its lead ObjectId or null if obstructed.</summary>
    short? TryPlaceOwnedObject(uint guid, int tileX, int tileY, int level = 1, short direction = 0, short? clearForSimId = null) =>
        throw new NotSupportedException("Pack object placement needs API 4");

    /// <summary>API4: removes a pack-owned object previously placed on the lot if idle.</summary>
    bool TryRemoveOwnedObject(short objectId) =>
        throw new NotSupportedException("Pack object removal needs API 4");

    /// <summary>Resolves a body mesh/texture suit specification for a Sim from a classic suit category prefix and body-string slot.</summary>
    string? ResolveSimSuit(short simId, char categoryPrefix, int bodyStringIndex) =>
        throw new NotSupportedException("Sim suit resolution needs API 4");

    /// <summary>Sets or clears a transient Sim body appearance override, optionally playing the classic clothes-change spin.</summary>
    void SetSimAppearanceOverride(short simId, string? bodySuitSpec, bool animateSpin = true) =>
        throw new NotSupportedException("Sim appearance overrides need API 4");

    /// <summary>Publishes an opaque state snapshot to this pack's client plugin (<see cref="ISimsClientPlugin.OnServerState"/>).</summary>
    void PublishClientState(byte[] data) { }

    /// <summary>Shared numeric blackboard synced across active simulation and client plugins.</summary>
    IDictionary<string, float> SharedBlackboard => new Dictionary<string, float>();

    /// <summary>Writes a diagnostic line to the simulation log.</summary>
    void Log(string message);
}

/// <summary>A household Sim visible to plugins.</summary>
public sealed record PluginSim(short ObjectId, short NeighborId, string Name, bool Child)
{
    /// <summary>The Sim's currently playing clip name when the host can report it.</summary>
    public string? Animation { get; init; }
    /// <summary>True while the Sim is wearing transient outdoor clothing (such as winter outerwear).</summary>
    public bool WearingOutdoorSuit { get; init; }
}

/// <summary>World tile descriptor passed to plugin ground pie-menu hooks.</summary>
public sealed record PluginGroundPoint(int TileX, int TileY, int Level, bool BareTerrain, bool Outside, bool Sheltered);

/// <summary>
/// An object on the lot (API version 2). <paramref name="X"/> and <paramref name="Y"/> are tile coordinates; a
/// multi-tile object's parts share <paramref name="LeadObjectId"/>.
/// </summary>
public sealed record PluginObject(short ObjectId, uint Guid, string Name, int X, int Y, int Level, short LeadObjectId)
{
    /// <summary>
    /// True when the object stands in an outdoor room, one open to the lot edge, rather than in a room enclosed by walls.
    /// Hosts before this member always report false.
    /// </summary>
    public bool Outside { get; init; }
    /// <summary>True beneath a solid upper floor or generated roof, regardless of camera visibility. Older hosts report false.</summary>
    public bool Sheltered { get; init; }
    /// <summary>API version 6: room identifier on the lot (-5 when unplaced or unassigned).</summary>
    public short RoomId { get; init; } = -5;
    /// <summary>API version 6: number of Sims actively using this object.</summary>
    public short UseCount { get; init; }
    /// <summary>API version 6: current dirtiness counter on this object.</summary>
    public short DirtyLevel { get; init; }
    /// <summary>API version 6: current repair/broken state (nonzero when broken or clogged).</summary>
    public short RepairState { get; init; }
    /// <summary>API version 6: runtime object category code from ObjectData.Category.</summary>
    public short Category { get; init; }
    /// <summary>API version 6: catalog purchase price in Simoleons.</summary>
    public int Price { get; init; }
    /// <summary>API version 6: Buy Mode function category bitmask (OBJD FunctionFlags low byte).</summary>
    public int FunctionFlags { get; init; }
    /// <summary>API version 6: Buy Mode function subsort bitmask (OBJD FunctionSubsort).</summary>
    public int FunctionSubsort { get; init; }
    /// <summary>API version 6: Buy Mode room sort bitmask (OBJD RoomSort).</summary>
    public int RoomSort { get; init; }
    /// <summary>API version 6: OBJD skill/study training bitmask (bit0 Cooking, bit1 Mechanical, bit2 Logic, bit3 Body, bit4 Creativity, bit5 Charisma, bit6 Study).</summary>
    public int SkillFlags { get; init; }
    /// <summary>API version 6: catalog Hunger rating (OBJD field 82).</summary>
    public short RatingHunger { get; init; }
    /// <summary>API version 6: catalog Comfort rating (OBJD field 83).</summary>
    public short RatingComfort { get; init; }
    /// <summary>API version 6: catalog Hygiene rating (OBJD field 84).</summary>
    public short RatingHygiene { get; init; }
    /// <summary>API version 6: catalog Bladder rating (OBJD field 85).</summary>
    public short RatingBladder { get; init; }
    /// <summary>API version 6: catalog Energy rating (OBJD field 86).</summary>
    public short RatingEnergy { get; init; }
    /// <summary>API version 6: catalog Fun rating (OBJD field 87).</summary>
    public short RatingFun { get; init; }
    /// <summary>API version 6: catalog Room rating (OBJD field 88).</summary>
    public short RatingRoom { get; init; }
    /// <summary>API version 6: functional food preparation score (ObjectData.PrepValue).</summary>
    public short PrepValue { get; init; }
    /// <summary>API version 6: functional cooking appliance score (ObjectData.CookValue).</summary>
    public short CookValue { get; init; }
    /// <summary>API version 6: functional surface score (ObjectData.SurfaceValue).</summary>
    public short SurfaceValue { get; init; }
    /// <summary>API version 6: functional trash disposal score (ObjectData.DisposeValue).</summary>
    public short DisposeValue { get; init; }
    /// <summary>API version 6: functional dishwashing score (ObjectData.WashDishValue).</summary>
    public short WashDishValue { get; init; }
    /// <summary>API version 6: functional dining surface score (ObjectData.EatingSurfaceValue).</summary>
    public short EatingSurfaceValue { get; init; }
    /// <summary>API version 6: functional serving surface score (ObjectData.ServingSurfaceValue).</summary>
    public short ServingSurfaceValue { get; init; }
    /// <summary>API version 6: functional gardening value (ObjectData.GardeningValue).</summary>
    public short GardeningValue { get; init; }
    /// <summary>API version 6: functional handwashing sink value (ObjectData.WashHandsValue).</summary>
    public short WashHandsValue { get; init; }
    /// <summary>API version 6: primary runtime object state attribute (Attributes[0], e.g. stereo/television power or station state).</summary>
    public short PrimaryAttribute { get; init; }
    /// <summary>Number of runtime attribute slots on this object.</summary>
    public int AttributeCount { get; init; }
    /// <summary>True when this object is a Sim or pet actor rather than a furnishing/architectural object.</summary>
    public bool IsPerson { get; init; }
}

/// <summary>A pie menu entry a Sim is offered on an object (API version 2), as the player would see it.</summary>
public sealed record PluginInteraction(int Id, string Name, short Param0, bool Global)
{
    /// <summary>API version 6: language-invariant US English interaction label when available.</summary>
    public string? EnglishName { get; init; }
    /// <summary>API version 6: TTAB autonomy threshold (0..100; 100 means player-only in classic autonomy).</summary>
    public int AutonomyThreshold { get; init; }
    /// <summary>API version 6: true when TTAB AutoFirst flag (0x100) is set.</summary>
    public bool AutoFirst { get; init; }
    /// <summary>API version 6: true when another Sim can join this interaction.</summary>
    public bool Joinable { get; init; }
    /// <summary>API version 6: personality-adjusted motive advertisements across indices 0..15.</summary>
    public float[] MotiveDeltas { get; init; } = [];
}

/// <summary>One participant's named role in a reciprocal Sim-to-Sim social interaction.</summary>
public sealed record PluginPairedSocialRole(short SimId, short PartnerId, string Role, PluginInteraction Interaction);

/// <summary>Lifecycle state for the two queued role actions. Finished means the source action trees ended; it does not assert their semantic success.</summary>
public enum PluginPairedSocialActionState
{
    /// <summary>Action has been enqueued and has not started running yet.</summary>
    Queued,
    /// <summary>Action tree is currently executing.</summary>
    Running,
    /// <summary>Action tree exited cleanly.</summary>
    Finished,
    /// <summary>Action was cancelled before finishing.</summary>
    Cancelled,
    /// <summary>One of the participating Sims left the lot or became unavailable.</summary>
    ParticipantMissing,
}

/// <summary>Response recorded by the recipient's interaction-result chooser for the partner role.</summary>
public enum PluginSocialResponse
{
    /// <summary>No response chooser prompt has been issued.</summary>
    NotRequested,
    /// <summary>Waiting for the recipient's acceptance or rejection response.</summary>
    Awaiting,
    /// <summary>Recipient accepted the social interaction.</summary>
    Accepted,
    /// <summary>Recipient rejected the social interaction.</summary>
    Rejected,
    /// <summary>Recipient did not respond within the timeout window.</summary>
    TimedOut,
}

/// <summary>Current state of both participants in a queued paired social action.</summary>
public sealed record PluginPairedSocialActionStatus(long Id, PluginPairedSocialActionState State,
    short FirstSimId, string FirstRole, PluginPairedSocialActionState FirstState,
    short SecondSimId, string SecondRole, PluginPairedSocialActionState SecondState, PluginSocialResponse Response);

/// <summary>
/// A pie menu entry contributed by a plugin (API version 2). <paramref name="Id"/> is 1 to 64 letters, digits, '.', '-'
/// or '_' and is unique among the plugin's entries for one menu; <paramref name="Name"/> is 1 to 64 printable characters.
/// </summary>
public sealed record PluginMenuEntry(string Id, string Name);

/// <summary>A candidate of an autonomous choice (API version 2): which Sim, on which object, which pie menu entry.</summary>
public sealed record PluginAutonomyChoice(short SimId, bool Household, short ObjectId, uint ObjectGuid, int InteractionId, string Interaction)
{
    /// <summary>Whether the interaction belongs to the global table rather than the object's private table.</summary>
    public bool Global { get; init; }
}

/// <summary>Constrained simulation access. Writes go through the same validation the original game applies.</summary>
public interface IPluginSimulation
{
    /// <summary>The house number of the loaded lot.</summary>
    short House { get; }

    /// <summary>Game clock hour, 0 through 23.</summary>
    int Hours { get; }

    /// <summary>Game clock minute, 0 through 59.</summary>
    int Minutes { get; }

    /// <summary>Game calendar month, 1 through 12 (or 0 when unavailable).</summary>
    int Month => 0;

    /// <summary>Game calendar day of month, 1 through 30 (or 0 when unavailable).</summary>
    int DayOfMonth => 0;

    /// <summary>Sub-tile positions and shelter flags for all persons and pets currently on the lot.</summary>
    IReadOnlyList<PluginActor> Actors => [];

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

    /// <summary>Returns the interaction labels defined in an object's interaction table without running per-Sim guard tests.</summary>
    IReadOnlyList<string> GetDefinedInteractions(short objectId) => [];

    /// <summary>
    /// API version 2: queues an interaction for a household Sim exactly as if the player picked it from the pie menu.
    /// Fails without a change while a blocking dialog is open or when the Sim is not offered that entry.
    /// </summary>
    bool TryQueueInteraction(short simId, short objectId, int interactionId, short param0 = 0, bool global = false) =>
        throw new NotSupportedException("Queuing interactions needs plugin API version 2");

    /// <summary>API version 2: the names of the actions in a household Sim's queue, the running one first.</summary>
    IReadOnlyList<string> GetQueuedActions(short simId) => throw new NotSupportedException("Action queues need plugin API version 2");

    /// <summary>
    /// API version 4: atomically queues both reciprocal participant roles of one Sim-to-Sim social action. Each role's
    /// interaction must currently be offered on the other participant. The participant whose action tree runs is the
    /// role's SimId; the stack object is its PartnerId. The returned handle reports each action tree's lifecycle.
    /// </summary>
    bool TryQueuePairedSocialAction(PluginPairedSocialRole first, PluginPairedSocialRole second, out long actionId)
    { actionId = 0; throw new NotSupportedException("Paired social actions need plugin API version 4"); }

    /// <summary>API version 4: reads lifecycle status for a pair queued by this simulation. Finished describes execution termination, not source-specific acceptance.</summary>
    PluginPairedSocialActionStatus? GetPairedSocialActionStatus(long actionId) => throw new NotSupportedException("Paired social actions need plugin API version 4");

    /// <summary>
    /// API version 2: changes one of a household Sim's needs, by the original motive index of <see cref="GetMotive"/>
    /// (energy 5, comfort 6, hunger 7, hygiene 8, bladder 9, social 14, fun 15), by up to 100 either way. The result is clamped to -100 through 100. Returns the new value.
    /// </summary>
    short ChangeMotive(short simId, int motive, int delta) => throw new NotSupportedException("Motive changes need plugin API version 2");

    /// <summary>API version 6: true when Free Will is enabled in Play Options on the active lot.</summary>
    bool FreeWill => throw new NotSupportedException("FreeWill state needs plugin API version 6");

    /// <summary>API version 6: true when the active lot is an away destination (Downtown, Vacation, Old Town, Studio Town, Magic Town).</summary>
    bool AwayLot => throw new NotSupportedException("AwayLot state needs plugin API version 6");

    /// <summary>API version 6: detailed read-only profiles for all persons and pets currently on the lot.</summary>
    IReadOnlyList<PluginSimProfile> AllSims => throw new NotSupportedException("Sim profiles need plugin API version 6");

    /// <summary>API version 6: read-only pairwise relationships known by a Sim on the lot.</summary>
    IReadOnlyList<PluginSimRelationship> GetRelationships(short simId) =>
        throw new NotSupportedException("Relationships need plugin API version 6");

    /// <summary>
    /// API version 6: queues an offered interaction for a household Sim at autonomous priority (priority 2),
    /// so any player command immediately preempts it. Fails when Free Will is off, while a blocking dialog is open,
    /// or when the Sim already has a player-ordered action active or queued.
    /// </summary>
    bool TryQueueAutonomousInteraction(short simId, short objectId, int interactionId, short param0 = 0) =>
        throw new NotSupportedException("Autonomous queuing needs plugin API version 6");

    /// <summary>
    /// API version 6: requests a graceful exit from a household Sim's currently running action if and only if
    /// that action is autonomous (priority &lt;= 2), interruptible, and no player-ordered action is queued.
    /// </summary>
    bool TryCancelAutonomousAction(short simId) =>
        throw new NotSupportedException("Autonomous cancellation needs plugin API version 6");

    /// <summary>
    /// API version 6: displays a native overhead thought, scream, or speech balloon on a Sim using either a lot object/Sim
    /// thumbnail (<paramref name="targetObjectId"/>) or a global sprite resource (<paramref name="spriteId"/>), with an
    /// optional red crossed-out overlay (<paramref name="crossedOut"/>). Never overwrites active skill progress meters or
    /// priority-2 interaction balloons.
    /// </summary>
    bool TryShowSimBalloon(
        short simId,
        PluginBalloonStyle style,
        short? targetObjectId = null,
        int? spriteId = null,
        bool crossedOut = false,
        int durationTicks = 90) =>
        throw new NotSupportedException("Sim balloons need plugin API version 6");
}


/// <summary>Sub-tile actor position and shelter state on the active lot.</summary>
public sealed record PluginActor(int Id, float X, float Y, int Level, bool Pet, bool Child, bool Swimming)
{
    public bool Outside { get; init; }
    public bool Sheltered { get; init; }
    public bool WearingOutdoorSuit { get; init; }
}

/// <summary>Raw top-down RGBA8888 pixel buffer returned to/from plugin resources.</summary>
public sealed record PluginImage(int Width, int Height, byte[] Rgba);

/// <summary>API version 5: read-only catalog object descriptor supplied to <see cref="IPluginBuyCatalogProvider"/>.</summary>
public sealed record PluginCatalogObject(
    uint Guid,
    string Name,
    string SourcePath,
    int Price,
    int CategoryMask,
    int RoomMask,
    bool IsCustomContent);

/// <summary>API version 5: one named folder/collection of catalog object GUIDs exposed inside a plugin Buy Mode view.</summary>
public sealed record PluginBuyCollection(
    string Id,
    string Label,
    string? Tooltip,
    uint[] Guids);

/// <summary>API version 5: custom Buy Mode browser tab and optional standard-catalog declutter filter returned by a plugin.</summary>
public sealed record PluginBuyCatalogView(
    string TabId,
    string TabLabel,
    string? Hotkey,
    bool HideMatchedFromStandardCatalog,
    PluginBuyCollection[] Collections);

/// <summary>API version 5: optional plugin hook providing custom Buy Mode catalog collections (such as a CC folder browser)
/// and optional filtering of matched items out of standard Buy Mode categories.</summary>
public interface IPluginBuyCatalogProvider
{
    /// <summary>Returns a custom Buy Mode view over the currently loaded catalog objects, or null to provide none.</summary>
    PluginBuyCatalogView? GetBuyCatalogView(IReadOnlyList<PluginCatalogObject> objects);
}

public sealed record PluginObjectSpriteMember(
    short ObjectId,
    short LeadObjectId,
    uint Guid,
    string Name,
    bool IsBuildFoliage,
    bool Outside,
    bool Sheltered,
    Vector3 Origin,
    int Direction,
    short Graphic);

public sealed record PluginObjectSpritePart(
    int MemberIndex,
    int SpriteIndex,
    int NearX,
    int NearY,
    int NearW,
    int NearH,
    bool Flip,
    float DepthNear,
    float DepthFar,
    byte[] NearRgba,
    byte[]? NearDepth,
    int MedW,
    int MedH,
    int FarW,
    int FarH,
    bool HasNear,
    bool HasFar);

public sealed record PluginObjectSpriteOverride(
    byte[] MediumRgba,
    byte[]? MediumDepth,
    byte[]? NearRgba,
    byte[]? NearDepth,
    byte[]? FarRgba,
    byte[]? FarDepth);

public interface IPluginObjectSpriteModifier
{
    int SpriteVariant { get; }
    bool SelectsObject(PluginObjectSpriteMember candidate);
    IReadOnlyList<PluginObjectSpriteOverride?>? TransformObjectGroup(
        int cameraOrientation,
        IReadOnlyList<PluginObjectSpriteMember> members,
        IReadOnlyList<PluginObjectSpritePart> parts);
}

/// <summary>API version 6: active or queued interaction record on a Sim.</summary>
public sealed record PluginQueuedAction(
    int Sequence,
    short TargetObjectId,
    uint TargetGuid,
    int InteractionId,
    short Param0,
    string Name,
    string? EnglishName,
    short Priority,
    bool Autonomous);

/// <summary>API version 6: career or school schedule, performance, and next-promotion requirements for a Sim.</summary>
public sealed record PluginSimCareer(
    short JobType,
    short JobLevel,
    short JobPerformance,
    bool IsSchool,
    int? StartHour,
    int? EndHour,
    int? Salary,
    int FriendsRequired,
    int FamilyFriends,
    short[] SkillRequirements);

/// <summary>API version 6: native overhead balloon frame style from Sprites.iff.</summary>
public enum PluginBalloonStyle
{
    /// <summary>No balloon background; displays the inner headline sprite by itself.</summary>
    None = 0,
    /// <summary>Cloud thought balloon (Sprites.iff 100).</summary>
    Thought = 1,
    /// <summary>Spiky exclamation/panic balloon (Sprites.iff 101).</summary>
    Scream = 2,
    /// <summary>Conversation speech balloon (Sprites.iff 102).</summary>
    Speech = 3,
}

/// <summary>API version 6: detailed read-only snapshot of a person or pet on the lot.</summary>
public sealed record PluginSimProfile(
    short ObjectId,
    short NeighborId,
    uint Guid,
    string Name,
    bool Household,
    bool Visitor,
    bool Npc,
    bool Child,
    bool Dog,
    bool Cat,
    bool Greeted,
    int X,
    int Y,
    int Level,
    short RoomId,
    bool Outside,
    bool Sheltered,
    bool Sitting,
    bool Asleep,
    bool AtWorkOrSchool,
    short Priority,
    bool NonInterruptible,
    short RouteResult,
    short Neat,
    short Outgoing,
    short Active,
    short Playful,
    short Nice,
    short Cooking,
    short Mechanical,
    short Charisma,
    short Body,
    short Logic,
    short Creativity,
    short Cleaning,
    short[] Motives,
    PluginSimCareer? Career,
    PluginQueuedAction? CurrentAction,
    IReadOnlyList<PluginQueuedAction> ActionQueue)
{
    /// <summary>API version 6: Sim gender flag (0 male, 1 female).</summary>
    public short Gender { get; init; }
    /// <summary>API version 6: romantic preference toward female Sims (PersonData 75).</summary>
    public short FemalePreference { get; init; }
    /// <summary>API version 6: romantic preference toward male Sims (PersonData 76).</summary>
    public short MalePreference { get; init; }
    /// <summary>API version 6: Romance interest score (PersonData 55).</summary>
    public short RomanceInterest { get; init; }
    /// <summary>API version 6: Parties interest score (PersonData 16).</summary>
    public short PartyInterest { get; init; }
    /// <summary>API version 6: Music interest score (PersonData 52).</summary>
    public short MusicInterest { get; init; }
    /// <summary>API version 6: Technology interest score (PersonData 54).</summary>
    public short TechInterest { get; init; }
}

/// <summary>API version 6: pairwise relationship record from one Sim toward another Sim.</summary>
public sealed record PluginSimRelationship(
    short TargetNeighborId,
    short? TargetObjectId,
    string TargetName,
    bool Household,
    int Daily,
    int ReverseDaily,
    int Lifetime,
    bool MutualFriend,
    bool Crush,
    bool Love);

/// <summary>API version 6: context of a single autonomous decision pass for a Sim.</summary>
public sealed record PluginAutonomyContext(
    short SimId,
    bool Household,
    short House,
    bool AwayLot,
    int Hours,
    int Minutes,
    float BaselineScore,
    float VanillaThreshold,
    uint RandomSeed);

/// <summary>API version 6: one guard-validated interaction candidate considered during a full-lot autonomy pass.</summary>
public sealed record PluginAutonomyCandidate(
    short ObjectId,
    uint ObjectGuid,
    string ObjectName,
    int ActionId,
    string InteractionName,
    string? EnglishName,
    float Distance,
    float VanillaScore,
    float AdjustedScore,
    bool AutoFirst,
    bool JoinInteraction,
    bool BlockedByPlugin,
    float[] MotiveDeltas);

/// <summary>
/// API version 6: optional plugin hook that upgrades autonomous decision-making with full-lot candidate visibility
/// and custom candidate selection while preserving classic vanilla free will whenever inactive.
/// </summary>
public interface IPluginAutonomyDirector
{
    /// <summary>
    /// Returns true when this plugin wants full-lot candidate scanning and <see cref="SelectAutonomyCandidate"/>
    /// selection for the specified Sim. Returning false preserves 100% original vanilla autonomy for that Sim.
    /// </summary>
    bool DirectsAutonomy(short simId, bool household) => false;

    /// <summary>
    /// Selects the index in <paramref name="candidates"/> to execute, -1 to decline all candidates,
    /// or null to fall back to the original autonomy selection rule.
    /// </summary>
    int? SelectAutonomyCandidate(PluginAutonomyContext context, IReadOnlyList<PluginAutonomyCandidate> candidates) => null;

    /// <summary>Called when the player explicitly cancels an active or queued action on a Sim.</summary>
    void OnPlayerCancelledAction(short simId, short targetObjectId, int interactionId) { }
}

/// <summary>Anchor origin for 2D HUD widgets drawn by client plugins.</summary>
public enum PluginHudAnchor
{
    /// <summary>Anchored relative to the Live Mode bottom control panel (e.g. clock accessory slot at 149, 88).</summary>
    ControlPanel = 0,
    /// <summary>Anchored relative to the top-left corner of the logical viewport.</summary>
    ScreenTopLeft = 1,
    /// <summary>Anchored relative to the top-right corner of the logical viewport.</summary>
    ScreenTopRight = 2,
    /// <summary>Anchored relative to the top-center of the logical viewport.</summary>
    ScreenTopCenter = 3,
}

/// <summary>Logical UI rectangle in 1x classic viewport pixels.</summary>
public readonly record struct PluginUiRect(double X, double Y, double Width, double Height);

/// <summary>Neighborhood UI texture descriptor supplied to <see cref="ISimsClientPlugin.TransformNeighborhoodTexture"/>.</summary>
public sealed record PluginNeighborhoodTexture(
    string Role,
    string Resource,
    int Width,
    int Height,
    int MapMode,
    float X = 0f,
    float Y = 0f,
    float Scale = 1f);

/// <summary>2D UI and HUD drawing services exposed to <see cref="ISimsClientPlugin.BuildHud"/>.</summary>
public interface IPluginUiContext
{
    /// <summary>True when a lot is currently shown in Live Mode.</summary>
    bool InLiveMode { get; }

    /// <summary>True when the Live Mode control panel is minimized.</summary>
    bool ControlPanelMinimized { get; }

    /// <summary>Registers or updates a reusable RGBA8888 image under a pack-local key.</summary>
    void RegisterImage(string imageKey, int pixelWidth, int pixelHeight, ReadOnlySpan<byte> rgba, double logicalWidth = 0, double logicalHeight = 0);

    /// <summary>Draws a registered image widget onto the HUD with optional hover tooltip and click hit-testing.</summary>
    void DrawWidget(
        string widgetId,
        string imageKey,
        PluginHudAnchor anchor,
        PluginUiRect rect,
        string? tooltip = null,
        float opacity = 1f);

    /// <summary>Displays a transient top-center toast notification banner using the classic UI font.</summary>
    void ShowToastBanner(string text, double durationSeconds = 4.5);
}

/// <summary>Host services provided to a client-side plugin running in the SDL UI/render process.</summary>
public interface IClientPluginContext
{
    /// <summary>The owning pack identifier.</summary>
    string PackId { get; }

    /// <summary>The owning pack version.</summary>
    string PackVersion { get; }

    /// <summary>Reads a read-only data file from the pack's plugin folder.</summary>
    byte[] ReadPluginData(string filename);

    /// <summary>Reads a sealed pack asset from the pack's files tree.</summary>
    byte[] ReadResourceBytes(string resource);

    /// <summary>Shared numeric blackboard synced across active simulation and client plugins.</summary>
    IReadOnlyDictionary<string, float> Blackboard { get; }

    /// <summary>Publishes a numeric value to the shared client blackboard.</summary>
    void SetBlackboardValue(string key, float value);

    /// <summary>Sends an asynchronous command to this pack's simulation plugin (<see cref="ISimsPlugin.OnClientCommand"/>).</summary>
    void SendServerCommand(string command, string? payload = null);

    /// <summary>Writes a diagnostic message to the client log.</summary>
    void Log(string message);
}

public enum PluginRenderStage
{
    PreLighting = 0,
    Lighting = 1,
    Atmosphere = 2,
    PostProcess = 3,
}

public enum PluginTextureFormat
{
    ColorSrgb8 = 0,
    Float16Rgba = 1,
    MaskR8 = 2,
    Depth32Float = 3,
}

public enum PluginBlendMode
{
    Opaque = 0,
    AlphaPremultiplied = 1,
    DoubleModulate = 2,
}

public enum SceneBufferKind
{
    SceneColor = 0,
    SceneDepth = 1,
    GroundDepth = 2,
    LotHeightMap = 3,
    LotFootHeightMap = 4,
    WorldShadowDepth = 5,
    WorldShadowBackDepth = 6,
    IndoorArchitectureMask = 7,
    OverheadMap = 8,
    VoxelMap = 9,
    AvatarMask = 10,
    DepthSpriteColor = 11,
    EmptyTransparent = 12,
    EmptyFloat16 = 13,
    EmptyIndoorMask = 14,
}

public readonly record struct PluginTextureHandle(int Id, int Width, int Height);

public readonly record struct PluginPointLight(float X, float Y, float Toward, float SignedIntensity);

public sealed record PluginLotRenderState(
    int House,
    long SceneRevision,
    int CameraOrientation,
    int ViewLevel,
    bool RoofsVisible,
    int LotWidth,
    int LotHeight,
    Vector2 ViewportOrigin,
    float ViewportScale,
    Vector2 CanvasSize,
    Vector4? LotHeightFrame,
    float IndoorBaseAltitude,
    Vector4? WorldShadowViewport,
    int Speed,
    double DeltaSeconds,
    int DebugViewMode,
    bool ShadowsEnabled,
    Vector3? SunDirectionOverride,
    float? TimeOverrideSeconds,
    IReadOnlyList<PluginPointLight> Lights);

public interface IPluginRenderContext
{
    PluginRenderStage Stage { get; }
    PluginLotRenderState Scene { get; }

    PluginTextureHandle AcquireSceneBuffer(SceneBufferKind kind);

    PluginTextureHandle GetOrCreateTarget(string key, int width, int height, PluginTextureFormat format, out bool wasCreated);

    PluginTextureHandle UploadTexture(string key, int width, int height, ReadOnlySpan<byte> rgba);

    void ShareTexture(string globalKey, PluginTextureHandle texture);

    bool TryGetSharedTexture(string globalKey, out PluginTextureHandle texture);

    void CopyTexture(PluginTextureHandle source, PluginTextureHandle destination);

    void StampDepthSprites(PluginTextureHandle depthTarget, float alphaCutoff);

    void DrawFullscreenPass(
        string fragmentShaderResource,
        PluginTextureHandle target,
        PluginBlendMode blendMode,
        bool loadTarget,
        ReadOnlySpan<PluginTextureHandle> sampledTextures,
        ReadOnlySpan<byte> uniformBytes,
        PluginTextureHandle? secondaryTarget = null,
        uint linearSamplerMask = 0);
}

public interface IPluginAudioContext
{
    bool Paused { get; }
    void SetEnvironmentMuffle(float gain, float cutoffHz);
    void SetAmbientLoop(string cue, string packResource, float gain);
}

/// <summary>Entry point for client-side UI, HUD, audio, and GPU rendering extensions declared via <c>plugin.clientEntryType</c>.</summary>
public interface ISimsClientPlugin : IDisposable
{
    /// <summary>Called once after the client plugin is constructed on the main client thread.</summary>
    void Initialize(IClientPluginContext context);

    /// <summary>Called whenever the pack's simulation plugin publishes an updated state snapshot via <see cref="IPluginContext.PublishClientState"/>.</summary>
    void OnServerState(ReadOnlySpan<byte> data) { }

    /// <summary>Builds 2D HUD widgets for the current frame.</summary>
    void BuildHud(IPluginUiContext ui) { }

    /// <summary>Called when the player clicks a HUD widget drawn by <see cref="BuildHud"/>. Return true if handled.</summary>
    bool OnHudClick(string widgetId) => false;

    /// <summary>Allows in-place RGBA8888 transformation of neighborhood backdrops (including 4K extended maps) and lot thumbnails.</summary>
    void TransformNeighborhoodTexture(PluginNeighborhoodTexture texture, Span<byte> rgba) { }

    /// <summary>True when this plugin replaces vanilla per-room flat vertex tinting with its own lighting pass.</summary>
    bool SuppressVanillaRoomLighting => false;

    /// <summary>Optional pack shader resource path (without extension) overriding terrain fragment shading.</summary>
    string? TerrainFragmentShader => null;

    /// <summary>Ordered GPU render stages this plugin participates in when a lot is drawn.</summary>
    IReadOnlyList<PluginRenderStage> RenderStages => [];

    /// <summary>Records GPU passes for <see cref="IPluginRenderContext.Stage"/>.</summary>
    void Render(IPluginRenderContext render) { }

    /// <summary>Updates lot-wide environmental audio muffle and looping ambient beds.</summary>
    void UpdateAudio(IPluginAudioContext audio) { }

    void IDisposable.Dispose() { }
}
